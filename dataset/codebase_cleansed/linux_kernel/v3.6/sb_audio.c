int sb_audio_open(int dev, int mode)
{
sb_devc *devc = audio_devs[dev]->devc;
unsigned long flags;
if (devc == NULL)
{
printk(KERN_ERR "Sound Blaster: incomplete initialization.\n");
return -ENXIO;
}
if (devc->caps & SB_NO_RECORDING && mode & OPEN_READ)
{
if (mode == OPEN_READ)
return -EPERM;
}
spin_lock_irqsave(&devc->lock, flags);
if (devc->opened)
{
spin_unlock_irqrestore(&devc->lock, flags);
return -EBUSY;
}
if (devc->dma16 != -1 && devc->dma16 != devc->dma8 && !devc->duplex)
{
if (sound_open_dma(devc->dma16, "Sound Blaster 16 bit"))
{
spin_unlock_irqrestore(&devc->lock, flags);
return -EBUSY;
}
}
devc->opened = mode;
spin_unlock_irqrestore(&devc->lock, flags);
devc->irq_mode = IMODE_NONE;
devc->irq_mode_16 = IMODE_NONE;
devc->fullduplex = devc->duplex &&
((mode & OPEN_READ) && (mode & OPEN_WRITE));
sb_dsp_reset(devc);
if (devc->model == MDL_ESS) ess_mixer_reload (devc, SOUND_MIXER_RECLEV);
if (devc->submodel == SUBMDL_ALS007)
{
if (mode & OPEN_READ)
sb_setmixer(devc,ALS007_OUTPUT_CTRL2,
sb_getmixer(devc,ALS007_OUTPUT_CTRL2) & 0xf9);
else
sb_setmixer(devc,ALS007_OUTPUT_CTRL2,
sb_getmixer(devc,ALS007_OUTPUT_CTRL2) | 0x06);
}
return 0;
}
void sb_audio_close(int dev)
{
sb_devc *devc = audio_devs[dev]->devc;
if(devc->duplex
&& !devc->fullduplex
&& (devc->opened & OPEN_READ) && (devc->opened & OPEN_WRITE))
{
struct dma_buffparms *dmap_temp;
dmap_temp = audio_devs[dev]->dmap_out;
audio_devs[dev]->dmap_out = audio_devs[dev]->dmap_in;
audio_devs[dev]->dmap_in = dmap_temp;
}
audio_devs[dev]->dmap_out->dma = devc->dma8;
audio_devs[dev]->dmap_in->dma = ( devc->duplex ) ?
devc->dma16 : devc->dma8;
if (devc->dma16 != -1 && devc->dma16 != devc->dma8 && !devc->duplex)
sound_close_dma(devc->dma16);
if ((devc->submodel == SUBMDL_ALS007) && (devc->opened & OPEN_READ))
{
sb_setmixer(devc,ALS007_OUTPUT_CTRL2,
sb_getmixer(devc,ALS007_OUTPUT_CTRL2) | 0x06);
}
devc->opened = 0;
}
static void sb_set_output_parms(int dev, unsigned long buf, int nr_bytes,
int intrflag)
{
sb_devc *devc = audio_devs[dev]->devc;
if (!devc->fullduplex || devc->bits == AFMT_S16_LE)
{
devc->trg_buf = buf;
devc->trg_bytes = nr_bytes;
devc->trg_intrflag = intrflag;
devc->irq_mode = IMODE_OUTPUT;
}
else
{
devc->trg_buf_16 = buf;
devc->trg_bytes_16 = nr_bytes;
devc->trg_intrflag_16 = intrflag;
devc->irq_mode_16 = IMODE_OUTPUT;
}
}
static void sb_set_input_parms(int dev, unsigned long buf, int count, int intrflag)
{
sb_devc *devc = audio_devs[dev]->devc;
if (!devc->fullduplex || devc->bits != AFMT_S16_LE)
{
devc->trg_buf = buf;
devc->trg_bytes = count;
devc->trg_intrflag = intrflag;
devc->irq_mode = IMODE_INPUT;
}
else
{
devc->trg_buf_16 = buf;
devc->trg_bytes_16 = count;
devc->trg_intrflag_16 = intrflag;
devc->irq_mode_16 = IMODE_INPUT;
}
}
static void sb1_audio_output_block(int dev, unsigned long buf, int nr_bytes, int intrflag)
{
unsigned long flags;
int count = nr_bytes;
sb_devc *devc = audio_devs[dev]->devc;
if (audio_devs[dev]->dmap_out->dma > 3)
count >>= 1;
count--;
devc->irq_mode = IMODE_OUTPUT;
spin_lock_irqsave(&devc->lock, flags);
if (sb_dsp_command(devc, 0x14))
{
sb_dsp_command(devc, (unsigned char) (count & 0xff));
sb_dsp_command(devc, (unsigned char) ((count >> 8) & 0xff));
}
else
printk(KERN_WARNING "Sound Blaster: unable to start DAC.\n");
spin_unlock_irqrestore(&devc->lock, flags);
devc->intr_active = 1;
}
static void sb1_audio_start_input(int dev, unsigned long buf, int nr_bytes, int intrflag)
{
unsigned long flags;
int count = nr_bytes;
sb_devc *devc = audio_devs[dev]->devc;
if (audio_devs[dev]->dmap_out->dma > 3)
count >>= 1;
count--;
devc->irq_mode = IMODE_INPUT;
spin_lock_irqsave(&devc->lock, flags);
if (sb_dsp_command(devc, 0x24))
{
sb_dsp_command(devc, (unsigned char) (count & 0xff));
sb_dsp_command(devc, (unsigned char) ((count >> 8) & 0xff));
}
else
printk(KERN_ERR "Sound Blaster: unable to start ADC.\n");
spin_unlock_irqrestore(&devc->lock, flags);
devc->intr_active = 1;
}
static void sb1_audio_trigger(int dev, int bits)
{
sb_devc *devc = audio_devs[dev]->devc;
bits &= devc->irq_mode;
if (!bits)
sb_dsp_command(devc, 0xd0);
else
{
switch (devc->irq_mode)
{
case IMODE_INPUT:
sb1_audio_start_input(dev, devc->trg_buf, devc->trg_bytes,
devc->trg_intrflag);
break;
case IMODE_OUTPUT:
sb1_audio_output_block(dev, devc->trg_buf, devc->trg_bytes,
devc->trg_intrflag);
break;
}
}
devc->trigger_bits = bits;
}
static int sb1_audio_prepare_for_input(int dev, int bsize, int bcount)
{
sb_devc *devc = audio_devs[dev]->devc;
unsigned long flags;
spin_lock_irqsave(&devc->lock, flags);
if (sb_dsp_command(devc, 0x40))
sb_dsp_command(devc, devc->tconst);
sb_dsp_command(devc, DSP_CMD_SPKOFF);
spin_unlock_irqrestore(&devc->lock, flags);
devc->trigger_bits = 0;
return 0;
}
static int sb1_audio_prepare_for_output(int dev, int bsize, int bcount)
{
sb_devc *devc = audio_devs[dev]->devc;
unsigned long flags;
spin_lock_irqsave(&devc->lock, flags);
if (sb_dsp_command(devc, 0x40))
sb_dsp_command(devc, devc->tconst);
sb_dsp_command(devc, DSP_CMD_SPKON);
spin_unlock_irqrestore(&devc->lock, flags);
devc->trigger_bits = 0;
return 0;
}
static int sb1_audio_set_speed(int dev, int speed)
{
int max_speed = 23000;
sb_devc *devc = audio_devs[dev]->devc;
int tmp;
if (devc->opened & OPEN_READ)
max_speed = 13000;
if (speed > 0)
{
if (speed < 4000)
speed = 4000;
if (speed > max_speed)
speed = max_speed;
devc->tconst = (256 - ((1000000 + speed / 2) / speed)) & 0xff;
tmp = 256 - devc->tconst;
speed = (1000000 + tmp / 2) / tmp;
devc->speed = speed;
}
return devc->speed;
}
static short sb1_audio_set_channels(int dev, short channels)
{
sb_devc *devc = audio_devs[dev]->devc;
return devc->channels = 1;
}
static unsigned int sb1_audio_set_bits(int dev, unsigned int bits)
{
sb_devc *devc = audio_devs[dev]->devc;
return devc->bits = 8;
}
static void sb1_audio_halt_xfer(int dev)
{
unsigned long flags;
sb_devc *devc = audio_devs[dev]->devc;
spin_lock_irqsave(&devc->lock, flags);
sb_dsp_reset(devc);
spin_unlock_irqrestore(&devc->lock, flags);
}
static void sb20_audio_output_block(int dev, unsigned long buf, int nr_bytes,
int intrflag)
{
unsigned long flags;
int count = nr_bytes;
sb_devc *devc = audio_devs[dev]->devc;
unsigned char cmd;
if (audio_devs[dev]->dmap_out->dma > 3)
count >>= 1;
count--;
devc->irq_mode = IMODE_OUTPUT;
spin_lock_irqsave(&devc->lock, flags);
if (sb_dsp_command(devc, 0x48))
{
sb_dsp_command(devc, (unsigned char) (count & 0xff));
sb_dsp_command(devc, (unsigned char) ((count >> 8) & 0xff));
if (devc->speed * devc->channels <= 23000)
cmd = 0x1c;
else
cmd = 0x90;
if (!sb_dsp_command(devc, cmd))
printk(KERN_ERR "Sound Blaster: unable to start DAC.\n");
}
else
printk(KERN_ERR "Sound Blaster: unable to start DAC.\n");
spin_unlock_irqrestore(&devc->lock, flags);
devc->intr_active = 1;
}
static void sb20_audio_start_input(int dev, unsigned long buf, int nr_bytes, int intrflag)
{
unsigned long flags;
int count = nr_bytes;
sb_devc *devc = audio_devs[dev]->devc;
unsigned char cmd;
if (audio_devs[dev]->dmap_out->dma > 3)
count >>= 1;
count--;
devc->irq_mode = IMODE_INPUT;
spin_lock_irqsave(&devc->lock, flags);
if (sb_dsp_command(devc, 0x48))
{
sb_dsp_command(devc, (unsigned char) (count & 0xff));
sb_dsp_command(devc, (unsigned char) ((count >> 8) & 0xff));
if (devc->speed * devc->channels <= (devc->major == 3 ? 23000 : 13000))
cmd = 0x2c;
else
cmd = 0x98;
if (!sb_dsp_command(devc, cmd))
printk(KERN_ERR "Sound Blaster: unable to start ADC.\n");
}
else
printk(KERN_ERR "Sound Blaster: unable to start ADC.\n");
spin_unlock_irqrestore(&devc->lock, flags);
devc->intr_active = 1;
}
static void sb20_audio_trigger(int dev, int bits)
{
sb_devc *devc = audio_devs[dev]->devc;
bits &= devc->irq_mode;
if (!bits)
sb_dsp_command(devc, 0xd0);
else
{
switch (devc->irq_mode)
{
case IMODE_INPUT:
sb20_audio_start_input(dev, devc->trg_buf, devc->trg_bytes,
devc->trg_intrflag);
break;
case IMODE_OUTPUT:
sb20_audio_output_block(dev, devc->trg_buf, devc->trg_bytes,
devc->trg_intrflag);
break;
}
}
devc->trigger_bits = bits;
}
static int sb201_audio_set_speed(int dev, int speed)
{
sb_devc *devc = audio_devs[dev]->devc;
int tmp;
int s = speed * devc->channels;
if (speed > 0)
{
if (speed < 4000)
speed = 4000;
if (speed > 44100)
speed = 44100;
if (devc->opened & OPEN_READ && speed > 15000)
speed = 15000;
devc->tconst = (256 - ((1000000 + s / 2) / s)) & 0xff;
tmp = 256 - devc->tconst;
speed = ((1000000 + tmp / 2) / tmp) / devc->channels;
devc->speed = speed;
}
return devc->speed;
}
static int sbpro_audio_prepare_for_input(int dev, int bsize, int bcount)
{
sb_devc *devc = audio_devs[dev]->devc;
unsigned long flags;
unsigned char bits = 0;
if (devc->dma16 >= 0 && devc->dma16 != devc->dma8)
audio_devs[dev]->dmap_out->dma = audio_devs[dev]->dmap_in->dma =
devc->bits == 16 ? devc->dma16 : devc->dma8;
if (devc->model == MDL_JAZZ || devc->model == MDL_SMW)
if (devc->bits == AFMT_S16_LE)
bits = 0x04;
spin_lock_irqsave(&devc->lock, flags);
if (sb_dsp_command(devc, 0x40))
sb_dsp_command(devc, devc->tconst);
sb_dsp_command(devc, DSP_CMD_SPKOFF);
if (devc->channels == 1)
sb_dsp_command(devc, 0xa0 | bits);
else
sb_dsp_command(devc, 0xa8 | bits);
spin_unlock_irqrestore(&devc->lock, flags);
devc->trigger_bits = 0;
return 0;
}
static int sbpro_audio_prepare_for_output(int dev, int bsize, int bcount)
{
sb_devc *devc = audio_devs[dev]->devc;
unsigned long flags;
unsigned char tmp;
unsigned char bits = 0;
if (devc->dma16 >= 0 && devc->dma16 != devc->dma8)
audio_devs[dev]->dmap_out->dma = audio_devs[dev]->dmap_in->dma = devc->bits == 16 ? devc->dma16 : devc->dma8;
if (devc->model == MDL_SBPRO)
sb_mixer_set_stereo(devc, devc->channels == 2);
spin_lock_irqsave(&devc->lock, flags);
if (sb_dsp_command(devc, 0x40))
sb_dsp_command(devc, devc->tconst);
sb_dsp_command(devc, DSP_CMD_SPKON);
if (devc->model == MDL_JAZZ || devc->model == MDL_SMW)
{
if (devc->bits == AFMT_S16_LE)
bits = 0x04;
if (devc->channels == 1)
sb_dsp_command(devc, 0xa0 | bits);
else
sb_dsp_command(devc, 0xa8 | bits);
spin_unlock_irqrestore(&devc->lock, flags);
}
else
{
spin_unlock_irqrestore(&devc->lock, flags);
tmp = sb_getmixer(devc, 0x0e);
if (devc->channels == 1)
tmp &= ~0x02;
else
tmp |= 0x02;
sb_setmixer(devc, 0x0e, tmp);
}
devc->trigger_bits = 0;
return 0;
}
static int sbpro_audio_set_speed(int dev, int speed)
{
sb_devc *devc = audio_devs[dev]->devc;
if (speed > 0)
{
if (speed < 4000)
speed = 4000;
if (speed > 44100)
speed = 44100;
if (devc->channels > 1 && speed > 22050)
speed = 22050;
sb201_audio_set_speed(dev, speed);
}
return devc->speed;
}
static short sbpro_audio_set_channels(int dev, short channels)
{
sb_devc *devc = audio_devs[dev]->devc;
if (channels == 1 || channels == 2)
{
if (channels != devc->channels)
{
devc->channels = channels;
if (devc->model == MDL_SBPRO && devc->channels == 2)
sbpro_audio_set_speed(dev, devc->speed);
}
}
return devc->channels;
}
static int jazz16_audio_set_speed(int dev, int speed)
{
sb_devc *devc = audio_devs[dev]->devc;
if (speed > 0)
{
int tmp;
int s;
if (speed < 5000)
speed = 5000;
if (speed > 44100)
speed = 44100;
s = speed * devc->channels;
devc->tconst = (256 - ((1000000 + s / 2) / s)) & 0xff;
tmp = 256 - devc->tconst;
speed = ((1000000 + tmp / 2) / tmp) / devc->channels;
devc->speed = speed;
}
return devc->speed;
}
static int sb16_audio_set_speed(int dev, int speed)
{
sb_devc *devc = audio_devs[dev]->devc;
int max_speed = devc->submodel == SUBMDL_ALS100 ? 48000 : 44100;
if (speed > 0)
{
if (speed < 5000)
speed = 5000;
if (speed > max_speed)
speed = max_speed;
devc->speed = speed;
}
return devc->speed;
}
static unsigned int sb16_audio_set_bits(int dev, unsigned int bits)
{
sb_devc *devc = audio_devs[dev]->devc;
if (bits != 0)
{
if (bits == AFMT_U8 || bits == AFMT_S16_LE)
devc->bits = bits;
else
devc->bits = AFMT_U8;
}
return devc->bits;
}
static int sb16_audio_prepare_for_input(int dev, int bsize, int bcount)
{
sb_devc *devc = audio_devs[dev]->devc;
if (!devc->fullduplex)
{
audio_devs[dev]->dmap_out->dma =
audio_devs[dev]->dmap_in->dma =
devc->bits == AFMT_S16_LE ?
devc->dma16 : devc->dma8;
}
else if (devc->bits == AFMT_S16_LE)
{
audio_devs[dev]->dmap_out->dma = devc->dma8;
audio_devs[dev]->dmap_in->dma = devc->dma16;
}
else
{
audio_devs[dev]->dmap_out->dma = devc->dma16;
audio_devs[dev]->dmap_in->dma = devc->dma8;
}
devc->trigger_bits = 0;
return 0;
}
static int sb16_audio_prepare_for_output(int dev, int bsize, int bcount)
{
sb_devc *devc = audio_devs[dev]->devc;
if (!devc->fullduplex)
{
audio_devs[dev]->dmap_out->dma =
audio_devs[dev]->dmap_in->dma =
devc->bits == AFMT_S16_LE ?
devc->dma16 : devc->dma8;
}
else if (devc->bits == AFMT_S16_LE)
{
audio_devs[dev]->dmap_out->dma = devc->dma8;
audio_devs[dev]->dmap_in->dma = devc->dma16;
}
else
{
audio_devs[dev]->dmap_out->dma = devc->dma16;
audio_devs[dev]->dmap_in->dma = devc->dma8;
}
devc->trigger_bits = 0;
return 0;
}
static void sb16_audio_output_block(int dev, unsigned long buf, int count,
int intrflag)
{
unsigned long flags, cnt;
sb_devc *devc = audio_devs[dev]->devc;
unsigned long bits;
if (!devc->fullduplex || devc->bits == AFMT_S16_LE)
{
devc->irq_mode = IMODE_OUTPUT;
devc->intr_active = 1;
}
else
{
devc->irq_mode_16 = IMODE_OUTPUT;
devc->intr_active_16 = 1;
}
spin_lock_irqsave(&devc->lock, flags);
bits = devc->bits;
if (devc->fullduplex)
devc->bits = (devc->bits == AFMT_S16_LE) ?
AFMT_U8 : AFMT_S16_LE;
spin_unlock_irqrestore(&devc->lock, flags);
cnt = count;
if (devc->bits == AFMT_S16_LE)
cnt >>= 1;
cnt--;
spin_lock_irqsave(&devc->lock, flags);
sb_dsp_command(devc, 0x41);
sb_dsp_command(devc, (unsigned char) ((devc->speed >> 8) & 0xff));
sb_dsp_command(devc, (unsigned char) (devc->speed & 0xff));
sb_dsp_command(devc, (devc->bits == AFMT_S16_LE ? 0xb6 : 0xc6));
sb_dsp_command(devc, ((devc->channels == 2 ? 0x20 : 0) +
(devc->bits == AFMT_S16_LE ? 0x10 : 0)));
sb_dsp_command(devc, (unsigned char) (cnt & 0xff));
sb_dsp_command(devc, (unsigned char) (cnt >> 8));
devc->bits = bits;
spin_unlock_irqrestore(&devc->lock, flags);
}
static void sb16_audio_start_input(int dev, unsigned long buf, int count, int intrflag)
{
unsigned long flags, cnt;
sb_devc *devc = audio_devs[dev]->devc;
if (!devc->fullduplex || devc->bits != AFMT_S16_LE)
{
devc->irq_mode = IMODE_INPUT;
devc->intr_active = 1;
}
else
{
devc->irq_mode_16 = IMODE_INPUT;
devc->intr_active_16 = 1;
}
cnt = count;
if (devc->bits == AFMT_S16_LE)
cnt >>= 1;
cnt--;
spin_lock_irqsave(&devc->lock, flags);
sb_dsp_command(devc, 0x42);
sb_dsp_command(devc, (unsigned char) ((devc->speed >> 8) & 0xff));
sb_dsp_command(devc, (unsigned char) (devc->speed & 0xff));
sb_dsp_command(devc, (devc->bits == AFMT_S16_LE ? 0xbe : 0xce));
sb_dsp_command(devc, ((devc->channels == 2 ? 0x20 : 0) +
(devc->bits == AFMT_S16_LE ? 0x10 : 0)));
sb_dsp_command(devc, (unsigned char) (cnt & 0xff));
sb_dsp_command(devc, (unsigned char) (cnt >> 8));
spin_unlock_irqrestore(&devc->lock, flags);
}
static void sb16_audio_trigger(int dev, int bits)
{
sb_devc *devc = audio_devs[dev]->devc;
int bits_16 = bits & devc->irq_mode_16;
bits &= devc->irq_mode;
if (!bits && !bits_16)
sb_dsp_command(devc, 0xd0);
else
{
if (bits)
{
switch (devc->irq_mode)
{
case IMODE_INPUT:
sb16_audio_start_input(dev,
devc->trg_buf,
devc->trg_bytes,
devc->trg_intrflag);
break;
case IMODE_OUTPUT:
sb16_audio_output_block(dev,
devc->trg_buf,
devc->trg_bytes,
devc->trg_intrflag);
break;
}
}
if (bits_16)
{
switch (devc->irq_mode_16)
{
case IMODE_INPUT:
sb16_audio_start_input(dev,
devc->trg_buf_16,
devc->trg_bytes_16,
devc->trg_intrflag_16);
break;
case IMODE_OUTPUT:
sb16_audio_output_block(dev,
devc->trg_buf_16,
devc->trg_bytes_16,
devc->trg_intrflag_16);
break;
}
}
}
devc->trigger_bits = bits | bits_16;
}
static void
sb16_copy_from_user(int dev,
char *localbuf, int localoffs,
const char __user *userbuf, int useroffs,
int max_in, int max_out,
int *used, int *returned,
int len)
{
sb_devc *devc = audio_devs[dev]->devc;
int i, c, p, locallen;
unsigned char *buf8;
signed short *buf16;
if (!devc->fullduplex)
{
if (copy_from_user(localbuf + localoffs,
userbuf + useroffs, len))
return;
*used = len;
*returned = len;
}
else if (devc->bits == AFMT_S16_LE)
{
len = ( (max_in >> 1) > max_out) ? max_out : (max_in >> 1);
c = len;
p = 0;
buf8 = (unsigned char *)(localbuf + localoffs);
while (c)
{
locallen = (c >= LBUFCOPYSIZE ? LBUFCOPYSIZE : c);
if (copy_from_user(lbuf16,
userbuf + useroffs + (p << 1),
locallen << 1))
return;
for (i = 0; i < locallen; i++)
{
buf8[p+i] = ~((lbuf16[i] >> 8) & 0xff) ^ 0x80;
}
c -= locallen; p += locallen;
}
*used = max_in > ( max_out << 1) ? (max_out << 1) : max_in;
*returned = len;
}
else
{
len = max_in > (max_out >> 1) ? (max_out >> 1) : max_in;
c = len;
p = 0;
buf16 = (signed short *)(localbuf + localoffs);
while (c)
{
locallen = (c >= LBUFCOPYSIZE ? LBUFCOPYSIZE : c);
if (copy_from_user(lbuf8,
userbuf+useroffs + p,
locallen))
return;
for (i = 0; i < locallen; i++)
{
buf16[p+i] = (~lbuf8[i] ^ 0x80) << 8;
}
c -= locallen; p += locallen;
}
*used = len;
*returned = len << 1;
}
}
static void
sb16_audio_mmap(int dev)
{
sb_devc *devc = audio_devs[dev]->devc;
devc->fullduplex = 0;
}
void sb_audio_init(sb_devc * devc, char *name, struct module *owner)
{
int audio_flags = 0;
int format_mask = AFMT_U8;
struct audio_driver *driver = &sb1_audio_driver;
switch (devc->model)
{
case MDL_SB1:
DDB(printk("Will use standard SB1.x driver\n"));
audio_flags = DMA_HARDSTOP;
break;
case MDL_SB2:
DDB(printk("Will use SB2.0 driver\n"));
audio_flags = DMA_AUTOMODE;
driver = &sb20_audio_driver;
break;
case MDL_SB201:
DDB(printk("Will use SB2.01 (high speed) driver\n"));
audio_flags = DMA_AUTOMODE;
driver = &sb201_audio_driver;
break;
case MDL_JAZZ:
case MDL_SMW:
DDB(printk("Will use Jazz16 driver\n"));
audio_flags = DMA_AUTOMODE;
format_mask |= AFMT_S16_LE;
driver = &jazz16_audio_driver;
break;
case MDL_ESS:
DDB(printk("Will use ESS ES688/1688 driver\n"));
driver = ess_audio_init (devc, &audio_flags, &format_mask);
break;
case MDL_SB16:
DDB(printk("Will use SB16 driver\n"));
audio_flags = DMA_AUTOMODE;
format_mask |= AFMT_S16_LE;
if (devc->dma8 != devc->dma16 && devc->dma16 != -1)
{
audio_flags |= DMA_DUPLEX;
devc->duplex = 1;
}
driver = &sb16_audio_driver;
break;
default:
DDB(printk("Will use SB Pro driver\n"));
audio_flags = DMA_AUTOMODE;
driver = &sbpro_audio_driver;
}
if (owner)
driver->owner = owner;
if ((devc->dev = sound_install_audiodrv(AUDIO_DRIVER_VERSION,
name,driver, sizeof(struct audio_driver),
audio_flags, format_mask, devc,
devc->dma8,
devc->duplex ? devc->dma16 : devc->dma8)) < 0)
{
printk(KERN_ERR "Sound Blaster: unable to install audio.\n");
return;
}
audio_devs[devc->dev]->mixer_dev = devc->my_mixerdev;
audio_devs[devc->dev]->min_fragment = 5;
}
