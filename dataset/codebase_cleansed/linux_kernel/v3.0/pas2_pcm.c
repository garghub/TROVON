static int pcm_set_speed(int arg)
{
int foo, tmp;
unsigned long flags;
if (arg == 0)
return pcm_speed;
if (arg > 44100)
arg = 44100;
if (arg < 5000)
arg = 5000;
if (pcm_channels & 2)
{
foo = ((CLOCK_TICK_RATE / 2) + (arg / 2)) / arg;
arg = ((CLOCK_TICK_RATE / 2) + (foo / 2)) / foo;
}
else
{
foo = (CLOCK_TICK_RATE + (arg / 2)) / arg;
arg = (CLOCK_TICK_RATE + (foo / 2)) / foo;
}
pcm_speed = arg;
tmp = pas_read(0x0B8A);
#if !defined NO_AUTO_FILTER_SET
tmp &= 0xe0;
if (pcm_speed >= 2 * 17897)
tmp |= 0x01;
else if (pcm_speed >= 2 * 15909)
tmp |= 0x02;
else if (pcm_speed >= 2 * 11931)
tmp |= 0x09;
else if (pcm_speed >= 2 * 8948)
tmp |= 0x11;
else if (pcm_speed >= 2 * 5965)
tmp |= 0x19;
else if (pcm_speed >= 2 * 2982)
tmp |= 0x04;
pcm_filter = tmp;
#endif
spin_lock_irqsave(&pas_lock, flags);
pas_write(tmp & ~(0x40 | 0x80), 0x0B8A);
pas_write(0x00 | 0x30 | 0x04, 0x138B);
pas_write(foo & 0xff, 0x1388);
pas_write((foo >> 8) & 0xff, 0x1388);
pas_write(tmp, 0x0B8A);
spin_unlock_irqrestore(&pas_lock, flags);
return pcm_speed;
}
static int pcm_set_channels(int arg)
{
if ((arg != 1) && (arg != 2))
return pcm_channels;
if (arg != pcm_channels)
{
pas_write(pas_read(0xF8A) ^ 0x20, 0xF8A);
pcm_channels = arg;
pcm_set_speed(pcm_speed);
}
return pcm_channels;
}
static int pcm_set_bits(int arg)
{
if (arg == 0)
return pcm_bits;
if ((arg & pcm_bitsok) != arg)
return pcm_bits;
if (arg != pcm_bits)
{
pas_write(pas_read(0x8389) ^ 0x04, 0x8389);
pcm_bits = arg;
}
return pcm_bits;
}
static int pas_audio_ioctl(int dev, unsigned int cmd, void __user *arg)
{
int val, ret;
int __user *p = arg;
DEB(printk("pas2_pcm.c: static int pas_audio_ioctl(unsigned int cmd = %X, unsigned int arg = %X)\n", cmd, arg));
switch (cmd)
{
case SOUND_PCM_WRITE_RATE:
if (get_user(val, p))
return -EFAULT;
ret = pcm_set_speed(val);
break;
case SOUND_PCM_READ_RATE:
ret = pcm_speed;
break;
case SNDCTL_DSP_STEREO:
if (get_user(val, p))
return -EFAULT;
ret = pcm_set_channels(val + 1) - 1;
break;
case SOUND_PCM_WRITE_CHANNELS:
if (get_user(val, p))
return -EFAULT;
ret = pcm_set_channels(val);
break;
case SOUND_PCM_READ_CHANNELS:
ret = pcm_channels;
break;
case SNDCTL_DSP_SETFMT:
if (get_user(val, p))
return -EFAULT;
ret = pcm_set_bits(val);
break;
case SOUND_PCM_READ_BITS:
ret = pcm_bits;
break;
default:
return -EINVAL;
}
return put_user(ret, p);
}
static void pas_audio_reset(int dev)
{
DEB(printk("pas2_pcm.c: static void pas_audio_reset(void)\n"));
pas_write(pas_read(0xF8A) & ~0x40, 0xF8A);
}
static int pas_audio_open(int dev, int mode)
{
int err;
unsigned long flags;
DEB(printk("pas2_pcm.c: static int pas_audio_open(int mode = %X)\n", mode));
spin_lock_irqsave(&pas_lock, flags);
if (pcm_busy)
{
spin_unlock_irqrestore(&pas_lock, flags);
return -EBUSY;
}
pcm_busy = 1;
spin_unlock_irqrestore(&pas_lock, flags);
if ((err = pas_set_intr(PAS_PCM_INTRBITS)) < 0)
return err;
pcm_count = 0;
open_mode = mode;
return 0;
}
static void pas_audio_close(int dev)
{
unsigned long flags;
DEB(printk("pas2_pcm.c: static void pas_audio_close(void)\n"));
spin_lock_irqsave(&pas_lock, flags);
pas_audio_reset(dev);
pas_remove_intr(PAS_PCM_INTRBITS);
pcm_mode = PCM_NON;
pcm_busy = 0;
spin_unlock_irqrestore(&pas_lock, flags);
}
static void pas_audio_output_block(int dev, unsigned long buf, int count,
int intrflag)
{
unsigned long flags, cnt;
DEB(printk("pas2_pcm.c: static void pas_audio_output_block(char *buf = %P, int count = %X)\n", buf, count));
cnt = count;
if (audio_devs[dev]->dmap_out->dma > 3)
cnt >>= 1;
if (audio_devs[dev]->flags & DMA_AUTOMODE &&
intrflag &&
cnt == pcm_count)
return;
spin_lock_irqsave(&pas_lock, flags);
pas_write(pas_read(0xF8A) & ~0x40,
0xF8A);
if (audio_devs[dev]->dmap_out->dma > 3)
count >>= 1;
if (count != pcm_count)
{
pas_write(pas_read(0x0B8A) & ~0x80, 0x0B8A);
pas_write(0x40 | 0x30 | 0x04, 0x138B);
pas_write(count & 0xff, 0x1389);
pas_write((count >> 8) & 0xff, 0x1389);
pas_write(pas_read(0x0B8A) | 0x80, 0x0B8A);
pcm_count = count;
}
pas_write(pas_read(0x0B8A) | 0x80 | 0x40, 0x0B8A);
#ifdef NO_TRIGGER
pas_write(pas_read(0xF8A) | 0x40 | 0x10, 0xF8A);
#endif
pcm_mode = PCM_DAC;
spin_unlock_irqrestore(&pas_lock, flags);
}
static void pas_audio_start_input(int dev, unsigned long buf, int count,
int intrflag)
{
unsigned long flags;
int cnt;
DEB(printk("pas2_pcm.c: static void pas_audio_start_input(char *buf = %P, int count = %X)\n", buf, count));
cnt = count;
if (audio_devs[dev]->dmap_out->dma > 3)
cnt >>= 1;
if (audio_devs[pas_audiodev]->flags & DMA_AUTOMODE &&
intrflag &&
cnt == pcm_count)
return;
spin_lock_irqsave(&pas_lock, flags);
if (audio_devs[dev]->dmap_out->dma > 3)
count >>= 1;
if (count != pcm_count)
{
pas_write(pas_read(0x0B8A) & ~0x80, 0x0B8A);
pas_write(0x40 | 0x30 | 0x04, 0x138B);
pas_write(count & 0xff, 0x1389);
pas_write((count >> 8) & 0xff, 0x1389);
pas_write(pas_read(0x0B8A) | 0x80, 0x0B8A);
pcm_count = count;
}
pas_write(pas_read(0x0B8A) | 0x80 | 0x40, 0x0B8A);
#ifdef NO_TRIGGER
pas_write((pas_read(0xF8A) | 0x40) & ~0x10, 0xF8A);
#endif
pcm_mode = PCM_ADC;
spin_unlock_irqrestore(&pas_lock, flags);
}
static void pas_audio_trigger(int dev, int state)
{
unsigned long flags;
spin_lock_irqsave(&pas_lock, flags);
state &= open_mode;
if (state & PCM_ENABLE_OUTPUT)
pas_write(pas_read(0xF8A) | 0x40 | 0x10, 0xF8A);
else if (state & PCM_ENABLE_INPUT)
pas_write((pas_read(0xF8A) | 0x40) & ~0x10, 0xF8A);
else
pas_write(pas_read(0xF8A) & ~0x40, 0xF8A);
spin_unlock_irqrestore(&pas_lock, flags);
}
static int pas_audio_prepare_for_input(int dev, int bsize, int bcount)
{
pas_audio_reset(dev);
return 0;
}
static int pas_audio_prepare_for_output(int dev, int bsize, int bcount)
{
pas_audio_reset(dev);
return 0;
}
void __init pas_pcm_init(struct address_info *hw_config)
{
DEB(printk("pas2_pcm.c: long pas_pcm_init()\n"));
pcm_bitsok = 8;
if (pas_read(0xEF8B) & 0x08)
pcm_bitsok |= 16;
pcm_set_speed(DSP_DEFAULT_SPEED);
if ((pas_audiodev = sound_install_audiodrv(AUDIO_DRIVER_VERSION,
"Pro Audio Spectrum",
&pas_audio_driver,
sizeof(struct audio_driver),
DMA_AUTOMODE,
AFMT_U8 | AFMT_S16_LE,
NULL,
hw_config->dma,
hw_config->dma)) < 0)
printk(KERN_WARNING "PAS16: Too many PCM devices available\n");
}
void pas_pcm_interrupt(unsigned char status, int cause)
{
if (cause == 1)
{
if (!(audio_devs[pas_audiodev]->flags & DMA_AUTOMODE))
pas_write(pas_read(0xF8A) & ~0x40, 0xF8A);
switch (pcm_mode)
{
case PCM_DAC:
DMAbuf_outputintr(pas_audiodev, 1);
break;
case PCM_ADC:
DMAbuf_inputintr(pas_audiodev);
break;
default:
printk(KERN_WARNING "PAS: Unexpected PCM interrupt\n");
}
}
}
