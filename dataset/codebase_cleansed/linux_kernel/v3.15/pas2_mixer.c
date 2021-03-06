void
mix_write(unsigned char data, int ioaddr)
{
if (pas_model == 4)
{
outw(data | (data << 8), (ioaddr + pas_translate_code) - 1);
outb((0x80), 0);
} else
pas_write(data, ioaddr);
}
static int
mixer_output(int right_vol, int left_vol, int div, int bits,
int mixer)
{
int left = left_vol * div / 100;
int right = right_vol * div / 100;
if (bits & 0x10)
{
left |= mixer;
right |= mixer;
}
if (bits == 0x03 || bits == 0x04)
{
mix_write(0x80 | bits, 0x078B);
mix_write(left, 0x078B);
right_vol = left_vol;
} else
{
mix_write(0x80 | 0x20 | bits, 0x078B);
mix_write(left, 0x078B);
mix_write(0x80 | 0x40 | bits, 0x078B);
mix_write(right, 0x078B);
}
return (left_vol | (right_vol << 8));
}
static void
set_mode(int new_mode)
{
mix_write(0x80 | 0x05, 0x078B);
mix_write(new_mode, 0x078B);
mode_control = new_mode;
}
static int
pas_mixer_set(int whichDev, unsigned int level)
{
int left, right, devmask, changed, i, mixer = 0;
left = level & 0x7f;
right = (level & 0x7f00) >> 8;
if (whichDev < SOUND_MIXER_NRDEVICES) {
if ((1 << whichDev) & rec_devices)
mixer = 0x20;
else
mixer = 0x00;
}
switch (whichDev)
{
case SOUND_MIXER_VOLUME:
levels[whichDev] = mixer_output(right, left, 63, 0x01, 0);
break;
case SOUND_MIXER_BASS:
levels[whichDev] = mixer_output(right, left, 12, 0x03, 0);
break;
case SOUND_MIXER_TREBLE:
levels[whichDev] = mixer_output(right, left, 12, 0x04, 0);
break;
case SOUND_MIXER_SYNTH:
levels[whichDev] = mixer_output(right, left, 31, 0x10 | 0x00, mixer);
break;
case SOUND_MIXER_PCM:
levels[whichDev] = mixer_output(right, left, 31, 0x10 | 0x05, mixer);
break;
case SOUND_MIXER_ALTPCM:
levels[whichDev] = mixer_output(right, left, 31, 0x10 | 0x07, mixer);
break;
case SOUND_MIXER_SPEAKER:
levels[whichDev] = mixer_output(right, left, 31, 0x10 | 0x06, mixer);
break;
case SOUND_MIXER_LINE:
levels[whichDev] = mixer_output(right, left, 31, 0x10 | 0x02, mixer);
break;
case SOUND_MIXER_CD:
levels[whichDev] = mixer_output(right, left, 31, 0x10 | 0x03, mixer);
break;
case SOUND_MIXER_MIC:
levels[whichDev] = mixer_output(right, left, 31, 0x10 | 0x04, mixer);
break;
case SOUND_MIXER_IMIX:
levels[whichDev] = mixer_output(right, left, 31, 0x10 | 0x01,
0x00);
break;
case SOUND_MIXER_RECLEV:
levels[whichDev] = mixer_output(right, left, 15, 0x02, 0);
break;
case SOUND_MIXER_RECSRC:
devmask = level & POSSIBLE_RECORDING_DEVICES;
changed = devmask ^ rec_devices;
rec_devices = devmask;
for (i = 0; i < SOUND_MIXER_NRDEVICES; i++)
if (changed & (1 << i))
{
pas_mixer_set(i, levels[i]);
}
return rec_devices;
break;
default:
return -EINVAL;
}
return (levels[whichDev]);
}
static void
pas_mixer_reset(void)
{
int foo;
for (foo = 0; foo < SOUND_MIXER_NRDEVICES; foo++)
pas_mixer_set(foo, levels[foo]);
set_mode(0x04 | 0x01);
}
static int pas_mixer_ioctl(int dev, unsigned int cmd, void __user *arg)
{
int level,v ;
int __user *p = (int __user *)arg;
if (cmd == SOUND_MIXER_PRIVATE1) {
if (get_user(level, p))
return -EFAULT;
if (level == -1)
level = (mode_control & 0x04);
else {
mode_control &= ~0x04;
if (level)
mode_control |= 0x04;
set_mode(mode_control);
}
level = !!level;
return put_user(level, p);
}
if (cmd == SOUND_MIXER_PRIVATE2) {
if (get_user(level, p))
return -EFAULT;
if (level == -1) {
if (!(mode_control & 0x03))
level = 0;
else
level = ((mode_control & 0x03) + 1) * 20;
} else {
int i = 0;
level &= 0x7f;
if (level)
i = (level / 20) - 1;
mode_control &= ~0x03;
mode_control |= i & 0x03;
set_mode(mode_control);
if (i)
i = (i + 1) * 20;
level = i;
}
return put_user(level, p);
}
if (cmd == SOUND_MIXER_PRIVATE3) {
if (get_user(level, p))
return -EFAULT;
if (level == -1)
level = !(pas_read(0x0B8A) & 0x20);
else {
if (level)
pas_write(pas_read(0x0B8A) & (~0x20), 0x0B8A);
else
pas_write(pas_read(0x0B8A) | 0x20, 0x0B8A);
level = !(pas_read(0x0B8A) & 0x20);
}
return put_user(level, p);
}
if (((cmd >> 8) & 0xff) == 'M') {
if (get_user(v, p))
return -EFAULT;
if (_SIOC_DIR(cmd) & _SIOC_WRITE) {
v = pas_mixer_set(cmd & 0xff, v);
} else {
switch (cmd & 0xff) {
case SOUND_MIXER_RECSRC:
v = rec_devices;
break;
case SOUND_MIXER_STEREODEVS:
v = SUPPORTED_MIXER_DEVICES & ~(SOUND_MASK_BASS | SOUND_MASK_TREBLE);
break;
case SOUND_MIXER_DEVMASK:
v = SUPPORTED_MIXER_DEVICES;
break;
case SOUND_MIXER_RECMASK:
v = POSSIBLE_RECORDING_DEVICES & SUPPORTED_MIXER_DEVICES;
break;
case SOUND_MIXER_CAPS:
v = 0;
break;
default:
v = levels[cmd & 0xff];
break;
}
}
return put_user(v, p);
}
return -EINVAL;
}
int __init
pas_init_mixer(void)
{
int d;
levels = load_mixer_volumes("PAS16_1", default_levels, 1);
pas_mixer_reset();
if ((d = sound_alloc_mixerdev()) != -1)
{
audio_devs[pas_audiodev]->mixer_dev = d;
mixer_devs[d] = &pas_mixer_operations;
}
return 1;
}
