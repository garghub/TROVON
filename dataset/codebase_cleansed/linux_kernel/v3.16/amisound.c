void __init amiga_init_sound(void)
{
static struct resource beep_res = { .name = "Beep" };
snd_data = amiga_chip_alloc_res(sizeof(sine_data), &beep_res);
if (!snd_data) {
pr_crit("amiga init_sound: failed to allocate chipmem\n");
return;
}
memcpy (snd_data, sine_data, sizeof(sine_data));
clock_constant = (amiga_colorclock+DATA_SIZE/2)/DATA_SIZE;
#ifndef CONFIG_FB_AMIGA
amifb_video_off();
#endif
}
void amiga_mksound( unsigned int hz, unsigned int ticks )
{
unsigned long flags;
if (!snd_data)
return;
local_irq_save(flags);
del_timer( &sound_timer );
if (hz > 20 && hz < 32767) {
unsigned long period = (clock_constant / hz);
if (period < amiga_audio_min_period)
period = amiga_audio_min_period;
if (period > MAX_PERIOD)
period = MAX_PERIOD;
custom.aud[2].audlc = snd_data;
custom.aud[2].audlen = sizeof(sine_data)/2;
custom.aud[2].audper = (unsigned short)period;
custom.aud[2].audvol = 32;
if (ticks) {
sound_timer.expires = jiffies + ticks;
add_timer( &sound_timer );
}
custom.dmacon = DMAF_SETCLR | DMAF_AUD2;
} else
nosound( 0 );
local_irq_restore(flags);
}
static void nosound( unsigned long ignored )
{
custom.dmacon = DMAF_AUD2;
custom.aud[2].audper = amiga_audio_period;
}
