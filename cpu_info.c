#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <unistd.h>
#include <stdbool.h>

int get_cpu_usage() {
    unsigned long u1, n1, s1, i1, u2, n2, s2, i2;
    FILE* f = fopen("/proc/stat", "r");
    if (f == NULL) {
        perror("Failed to open /proc/stat");
        return -1;
    }
    fscanf(f, "cpu %lu %lu %lu %lu", &u1, &n1, &s1, &i1);
    fclose(f);
    sleep(1);
    f = fopen("/proc/stat", "r");
    if (f == NULL) {
        perror("Failed to open /proc/stat");
        return -1;
    }
    fscanf(f, "cpu %lu %lu %lu %lu", &u2, &n2, &s2, &i2);
    fclose(f);
    unsigned long total1 = u1 + n1 + s1 + i1, total2 = u2 + n2 + s2 + i2;
    return 100 * ((total2 - total1) - (i2 - i1)) / (total2 - total1);
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1) {
        fprintf(stderr, "TTF_Init Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "CPU Usage", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        200, 
        100, 
        SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
    if (window == NULL) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 24);
    if (font == NULL) {
        fprintf(stderr, "TTF_OpenFont Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Color color = {255, 255, 255};
    bool running = true;
    char cpu_str[10];
    
    while (running) {
        // Get CPU usage
        int usage = get_cpu_usage();
        if (usage < 0) {
            fprintf(stderr, "Error getting CPU usage\n");
            running = false;
            break;
        }
        snprintf(cpu_str, sizeof(cpu_str), "%d%%", usage);

        // Create texture for the new value
        SDL_Surface* txtSurface = TTF_RenderText_Solid(font, cpu_str, color);
        SDL_Texture* txtTexture = SDL_CreateTextureFromSurface(renderer, txtSurface);
        SDL_Rect txtRect = {70, 30, txtSurface->w, txtSurface->h};
        
        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Render
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, txtTexture, NULL, &txtRect);
        SDL_RenderPresent(renderer);

        // Clean up temporary resources
        SDL_DestroyTexture(txtTexture);
        SDL_FreeSurface(txtSurface);
        
        // Small delay to prevent CPU from maxing out
        SDL_Delay(100);
    }

    // Clean up
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
