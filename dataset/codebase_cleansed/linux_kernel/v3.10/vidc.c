static void
vidc_mixer_set(int mdev, unsigned int level)
{
unsigned int lev_l = level & 0x007f;
unsigned int lev_r = (level & 0x7f00) >> 8;
unsigned int mlev_l, mlev_r;
if (lev_l > 100)
lev_l = 100;
if (lev_r > 100)
lev_r = 100;
#define SCALE(lev,master) ((lev) * (master) * 65536 / 10000)
mlev_l = vidc_level_l[SOUND_MIXER_VOLUME];
mlev_r = vidc_level_r[SOUND_MIXER_VOLUME];
switch (mdev) {
case SOUND_MIXER_VOLUME:
case SOUND_MIXER_PCM:
vidc_level_l[mdev] = lev_l;
vidc_level_r[mdev] = lev_r;
vidc_audio_volume_l = SCALE(lev_l, mlev_l);
vidc_audio_volume_r = SCALE(lev_r, mlev_r);
break;
}
#undef SCALE
}
static int vidc_mixer_ioctl(int dev, unsigned int cmd, void __user *arg)
{
unsigned int val;
unsigned int mdev;
if (_SIOC_TYPE(cmd) != 'M')
return -EINVAL;
mdev = _SIOC_NR(cmd);
if (_SIOC_DIR(cmd) & _SIOC_WRITE) {
if (get_user(val, (unsigned int __user *)arg))
return -EFAULT;
if (mdev < SOUND_MIXER_NRDEVICES)
vidc_mixer_set(mdev, val);
else
return -EINVAL;
}
switch (mdev) {
case SOUND_MIXER_RECSRC:
val = 0;
break;
case SOUND_MIXER_DEVMASK:
val = SOUND_MASK_VOLUME | SOUND_MASK_PCM | SOUND_MASK_SYNTH;
break;
case SOUND_MIXER_STEREODEVS:
val = SOUND_MASK_VOLUME | SOUND_MASK_PCM | SOUND_MASK_SYNTH;
break;
case SOUND_MIXER_RECMASK:
val = 0;
break;
case SOUND_MIXER_CAPS:
val = 0;
break;
default:
if (mdev < SOUND_MIXER_NRDEVICES)
val = vidc_level_l[mdev] | vidc_level_r[mdev] << 8;
else
return -EINVAL;
}
return put_user(val, (unsigned int __user *)arg) ? -EFAULT : 0;
}
static unsigned int vidc_audio_set_format(int dev, unsigned int fmt)
{
switch (fmt) {
default:
fmt = AFMT_S16_LE;
case AFMT_U8:
case AFMT_S8:
case AFMT_S16_LE:
vidc_audio_format = fmt;
vidc_update_filler(vidc_audio_format, vidc_audio_channels);
case AFMT_QUERY:
break;
}
return vidc_audio_format;
}
static int vidc_audio_set_speed(int dev, int rate)
{
if (rate) {
unsigned int hwctrl, hwrate, hwrate_ext, rate_int, rate_ext;
unsigned int diff_int, diff_ext;
unsigned int newsize, new2size;
hwctrl = 0x00000003;
hwrate = (((VIDC_SOUND_CLOCK * 2) / rate) + 1) >> 1;
if (hwrate < 3)
hwrate = 3;
if (hwrate > 255)
hwrate = 255;
hwrate_ext = (((VIDC_SOUND_CLOCK_EXT * 2) / rate) + 1) >> 1;
if (hwrate_ext < 3)
hwrate_ext = 3;
if (hwrate_ext > 255)
hwrate_ext = 255;
rate_int = VIDC_SOUND_CLOCK / hwrate;
rate_ext = VIDC_SOUND_CLOCK_EXT / hwrate_ext;
diff_int = my_abs(rate_ext-rate);
diff_ext = my_abs(rate_int-rate);
if (diff_ext < diff_int) {
hwrate=hwrate_ext;
hwctrl=0x00000002;
if (diff_ext > (rate/256))
rate=rate_ext;
} else {
hwctrl=0x00000003;
if (diff_int > (rate/256))
rate=rate_int;
}
vidc_writel(0xb0000000 | (hwrate - 2));
vidc_writel(0xb1000000 | hwctrl);
newsize = (10000 / hwrate) & ~3;
if (newsize < 208)
newsize = 208;
if (newsize > 4096)
newsize = 4096;
for (new2size = 128; new2size < newsize; new2size <<= 1);
if (new2size - newsize > newsize - (new2size >> 1))
new2size >>= 1;
if (new2size > 4096) {
printk(KERN_ERR "VIDC: error: dma buffer (%d) %d > 4K\n",
newsize, new2size);
new2size = 4096;
}
dma_bufsize = new2size;
vidc_audio_rate = rate;
}
return vidc_audio_rate;
}
static short vidc_audio_set_channels(int dev, short channels)
{
switch (channels) {
default:
channels = 2;
case 1:
case 2:
vidc_audio_channels = channels;
vidc_update_filler(vidc_audio_format, vidc_audio_channels);
case 0:
break;
}
return vidc_audio_channels;
}
static int vidc_audio_open(int dev, int mode)
{
if (mode == OPEN_READ)
return -EPERM;
if (vidc_busy)
return -EBUSY;
vidc_busy = 1;
return 0;
}
static void vidc_audio_close(int dev)
{
vidc_busy = 0;
}
static void
vidc_audio_output_block(int dev, unsigned long buf, int total_count, int one)
{
struct dma_buffparms *dmap = audio_devs[dev]->dmap_out;
unsigned long flags;
local_irq_save(flags);
dma_start = buf - (unsigned long)dmap->raw_buf_phys + (unsigned long)dmap->raw_buf;
dma_count = total_count;
local_irq_restore(flags);
}
static void
vidc_audio_start_input(int dev, unsigned long buf, int count, int intrflag)
{
}
static int vidc_audio_prepare_for_input(int dev, int bsize, int bcount)
{
return -EINVAL;
}
static irqreturn_t vidc_audio_dma_interrupt(void)
{
DMAbuf_outputintr(vidc_adev, 1);
return IRQ_HANDLED;
}
static int vidc_audio_prepare_for_output(int dev, int bsize, int bcount)
{
struct audio_operations *adev = audio_devs[dev];
dma_interrupt = NULL;
adev->dmap_out->flags |= DMA_NODMA;
return 0;
}
static void vidc_audio_reset(int dev)
{
dma_interrupt = NULL;
}
static int vidc_audio_local_qlen(int dev)
{
return 0;
}
static void vidc_audio_trigger(int dev, int enable_bits)
{
struct audio_operations *adev = audio_devs[dev];
if (enable_bits & PCM_ENABLE_OUTPUT) {
if (!(adev->dmap_out->flags & DMA_ACTIVE)) {
unsigned long flags;
local_irq_save(flags);
adev->dmap_out->flags |= DMA_ACTIVE;
dma_interrupt = vidc_audio_dma_interrupt;
vidc_sound_dma_irq(0, NULL);
iomd_writeb(DMA_CR_E | 0x10, IOMD_SD0CR);
local_irq_restore(flags);
}
}
}
void vidc_update_filler(int format, int channels)
{
#define TYPE(fmt,ch) (((fmt)<<2) | ((ch)&3))
switch (TYPE(format, channels)) {
default:
case TYPE(AFMT_U8, 1):
vidc_filler = vidc_fill_1x8_u;
break;
case TYPE(AFMT_U8, 2):
vidc_filler = vidc_fill_2x8_u;
break;
case TYPE(AFMT_S8, 1):
vidc_filler = vidc_fill_1x8_s;
break;
case TYPE(AFMT_S8, 2):
vidc_filler = vidc_fill_2x8_s;
break;
case TYPE(AFMT_S16_LE, 1):
vidc_filler = vidc_fill_1x16_s;
break;
case TYPE(AFMT_S16_LE, 2):
vidc_filler = vidc_fill_2x16_s;
break;
}
}
static void __init attach_vidc(struct address_info *hw_config)
{
char name[32];
int i, adev;
sprintf(name, "VIDC %d-bit sound", hw_config->card_subtype);
conf_printf(name, hw_config);
memset(dma_buf, 0, sizeof(dma_buf));
adev = sound_install_audiodrv(AUDIO_DRIVER_VERSION, name,
&vidc_audio_driver, sizeof(vidc_audio_driver),
DMA_AUTOMODE, AFMT_U8 | AFMT_S8 | AFMT_S16_LE,
NULL, hw_config->dma, hw_config->dma2);
if (adev < 0)
goto audio_failed;
audio_devs[adev]->min_fragment = 10;
audio_devs[adev]->mixer_dev = num_mixers;
audio_devs[adev]->mixer_dev =
sound_install_mixer(MIXER_DRIVER_VERSION,
name, &vidc_mixer_operations,
sizeof(vidc_mixer_operations), NULL);
if (audio_devs[adev]->mixer_dev < 0)
goto mixer_failed;
for (i = 0; i < 2; i++) {
dma_buf[i] = get_zeroed_page(GFP_KERNEL);
if (!dma_buf[i]) {
printk(KERN_ERR "%s: can't allocate required buffers\n",
name);
goto mem_failed;
}
dma_pbuf[i] = virt_to_phys((void *)dma_buf[i]);
}
if (sound_alloc_dma(hw_config->dma, hw_config->name)) {
printk(KERN_ERR "%s: DMA %d is in use\n", name, hw_config->dma);
goto dma_failed;
}
if (request_irq(hw_config->irq, vidc_sound_dma_irq, 0,
hw_config->name, &dma_start)) {
printk(KERN_ERR "%s: IRQ %d is in use\n", name, hw_config->irq);
goto irq_failed;
}
vidc_adev = adev;
vidc_mixer_set(SOUND_MIXER_VOLUME, (85 | 85 << 8));
return;
irq_failed:
sound_free_dma(hw_config->dma);
dma_failed:
mem_failed:
for (i = 0; i < 2; i++)
free_page(dma_buf[i]);
sound_unload_mixerdev(audio_devs[adev]->mixer_dev);
mixer_failed:
sound_unload_audiodev(adev);
audio_failed:
return;
}
static int __init probe_vidc(struct address_info *hw_config)
{
hw_config->irq = IRQ_DMAS0;
hw_config->dma = DMA_VIRTUAL_SOUND;
hw_config->dma2 = -1;
hw_config->card_subtype = 16;
hw_config->name = "VIDC20";
return 1;
}
static void __exit unload_vidc(struct address_info *hw_config)
{
int i, adev = vidc_adev;
vidc_adev = -1;
free_irq(hw_config->irq, &dma_start);
sound_free_dma(hw_config->dma);
if (adev >= 0) {
sound_unload_mixerdev(audio_devs[adev]->mixer_dev);
sound_unload_audiodev(adev);
for (i = 0; i < 2; i++)
free_page(dma_buf[i]);
}
}
static int __init init_vidc(void)
{
if (probe_vidc(&cfg) == 0)
return -ENODEV;
attach_vidc(&cfg);
return 0;
}
static void __exit cleanup_vidc(void)
{
unload_vidc(&cfg);
}
