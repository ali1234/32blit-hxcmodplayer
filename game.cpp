/*
 * HxCModPlayer example (c) 2021 Alistair Buxton <a.j.buxton@gmail.com>
 *
 * License: Same as HxCModPlayer license.
 *
 * See https://github.com/jfdelnero/HxCModPlayer for more information.
 */

#include "32blit.hpp"

extern "C" {
#include "hxcmod.h"
}

#include "assets.hpp"


void fill_buffer(blit::AudioChannel &);
modcontext modctx;


void init() {
    blit::channels[0].waveforms = blit::Waveform::WAVE;
    blit::channels[0].wave_buffer_callback = &fill_buffer;
    hxcmod_init(&modctx);
    hxcmod_setcfg(&modctx, 22050, 0, 1);
    hxcmod_load(&modctx, (char *)song, song_length);
    blit::channels[0].trigger_attack();
}


void fill_buffer(blit::AudioChannel &channel) {
    hxcmod_fillbuffer(&modctx, blit::channels[0].wave_buffer, 64, nullptr);
}


void render(uint32_t time_ms) {
    char message[80];
    blit::screen.pen = blit::Pen(200, 20, 20);
    blit::screen.clear();
    sprintf(message, "11th Hour by TDK\nhttps://modarchive.org/\nmodule.php?67104");
    blit::screen.pen = blit::Pen(0, 0, 0, 127);
    blit::screen.text(message, blit::minimal_font, blit::Point(8, 8));
    blit::screen.pen = blit::Pen(255, 255, 255);
    blit::screen.text(message, blit::minimal_font, blit::Point(7, 7));
}


void update(uint32_t time_ms) {

}

