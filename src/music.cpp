#include "music.h"
#include <cstdio>

GoSDL::Music::~Music ()
{
    Mix_FreeMusic(mSample);
}

void GoSDL::Music::setSample (std::string path)
{
    mSample = Mix_LoadMUS(path.c_str());

    if(!mSample) {
        printf("Mix_LoadMUS: %s\n", Mix_GetError());
    }
}

void GoSDL::Music::play (float vol)
{
    Mix_VolumeMusic(128 * vol);
    Mix_FadeInMusic(mSample, -1, 200);
}

void GoSDL::Music::stop()
{
    Mix_FadeOutMusic(200);
}

bool GoSDL::Music::isPlaying()
{
    return Mix_PlayingMusic();
}
