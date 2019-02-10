#include "wolf3d.h"

static void	stop_sounds(ENGINE *wolf)
{
	Mix_HaltChannel(-1);
	if (BGMUSIC)
		Mix_FreeMusic(BGMUSIC);
	if (SHOTSOUND)
		Mix_FreeChunk(SHOTSOUND);
}

void		stop_engine(ENGINE *wolf)
{
	if (WALL)
	{
		free(WALL->pixels);
		free(WALL);
	}
	if (BLOCK)
	{
		while (MAP_H-- > 0)
			free(BLOCK[MAP_H]);
		free(BLOCK);
	}
	stop_sounds(wolf);
	SDL_DestroyWindow(WINDOW);
	SDL_Quit();
}