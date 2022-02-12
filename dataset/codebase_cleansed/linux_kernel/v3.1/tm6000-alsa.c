static int _tm6000_start_audio_dma(struct snd_tm6000_card *chip)
{
struct tm6000_core *core = chip->core;
dprintk(1, "Starting audio DMA\n");
tm6000_set_reg_mask(core, TM6010_REQ07_RCC_ACTIVE_VIDEO_IF, 0x40, 0x40);
tm6000_set_audio_bitrate(core, 48000);
return 0;
}
static int _tm6000_stop_audio_dma(struct snd_tm6000_card *chip)
{
struct tm6000_core *core = chip->core;
dprintk(1, "Stopping audio DMA\n");
tm6000_set_reg_mask(core, TM6010_REQ07_RCC_ACTIVE_VIDEO_IF, 0x00, 0x40);
return 0;
}
static void dsp_buffer_free(struct snd_pcm_substream *substream)
{
struct snd_tm6000_card *chip = snd_pcm_substream_chip(substream);
dprintk(2, "Freeing buffer\n");
vfree(substream->runtime->dma_area);
substream->runtime->dma_area = NULL;
substream->runtime->dma_bytes = 0;
}
static int dsp_buffer_alloc(struct snd_pcm_substream *substream, int size)
{
struct snd_tm6000_card *chip = snd_pcm_substream_chip(substream);
dprintk(2, "Allocating buffer\n");
if (substream->runtime->dma_area) {
if (substream->runtime->dma_bytes > size)
return 0;
dsp_buffer_free(substream);
}
substream->runtime->dma_area = vmalloc(size);
if (!substream->runtime->dma_area)
return -ENOMEM;
substream->runtime->dma_bytes = size;
return 0;
}
static int snd_tm6000_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_tm6000_card *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
err = snd_pcm_hw_constraint_pow2(runtime, 0,
SNDRV_PCM_HW_PARAM_PERIODS);
if (err < 0)
goto _error;
chip->substream = substream;
runtime->hw = snd_tm6000_digital_hw;
return 0;
_error:
dprintk(1, "Error opening PCM!\n");
return err;
}
static int snd_tm6000_close(struct snd_pcm_substream *substream)
{
struct snd_tm6000_card *chip = snd_pcm_substream_chip(substream);
struct tm6000_core *core = chip->core;
if (atomic_read(&core->stream_started) > 0) {
atomic_set(&core->stream_started, 0);
schedule_work(&core->wq_trigger);
}
return 0;
}
static int tm6000_fillbuf(struct tm6000_core *core, char *buf, int size)
{
struct snd_tm6000_card *chip = core->adev;
struct snd_pcm_substream *substream = chip->substream;
struct snd_pcm_runtime *runtime;
int period_elapsed = 0;
unsigned int stride, buf_pos;
int length;
if (atomic_read(&core->stream_started) == 0)
return 0;
if (!size || !substream) {
dprintk(1, "substream was NULL\n");
return -EINVAL;
}
runtime = substream->runtime;
if (!runtime || !runtime->dma_area) {
dprintk(1, "runtime was NULL\n");
return -EINVAL;
}
buf_pos = chip->buf_pos;
stride = runtime->frame_bits >> 3;
if (stride == 0) {
dprintk(1, "stride is zero\n");
return -EINVAL;
}
length = size / stride;
if (length == 0) {
dprintk(1, "%s: length was zero\n", __func__);
return -EINVAL;
}
dprintk(1, "Copying %d bytes at %p[%d] - buf size=%d x %d\n", size,
runtime->dma_area, buf_pos,
(unsigned int)runtime->buffer_size, stride);
if (buf_pos + length >= runtime->buffer_size) {
unsigned int cnt = runtime->buffer_size - buf_pos;
memcpy(runtime->dma_area + buf_pos * stride, buf, cnt * stride);
memcpy(runtime->dma_area, buf + cnt * stride,
length * stride - cnt * stride);
} else
memcpy(runtime->dma_area + buf_pos * stride, buf,
length * stride);
snd_pcm_stream_lock(substream);
chip->buf_pos += length;
if (chip->buf_pos >= runtime->buffer_size)
chip->buf_pos -= runtime->buffer_size;
chip->period_pos += length;
if (chip->period_pos >= runtime->period_size) {
chip->period_pos -= runtime->period_size;
period_elapsed = 1;
}
snd_pcm_stream_unlock(substream);
if (period_elapsed)
snd_pcm_period_elapsed(substream);
return 0;
}
static int snd_tm6000_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
int size, rc;
size = params_period_bytes(hw_params) * params_periods(hw_params);
rc = dsp_buffer_alloc(substream, size);
if (rc < 0)
return rc;
return 0;
}
static int snd_tm6000_hw_free(struct snd_pcm_substream *substream)
{
struct snd_tm6000_card *chip = snd_pcm_substream_chip(substream);
struct tm6000_core *core = chip->core;
if (atomic_read(&core->stream_started) > 0) {
atomic_set(&core->stream_started, 0);
schedule_work(&core->wq_trigger);
}
return 0;
}
static int snd_tm6000_prepare(struct snd_pcm_substream *substream)
{
struct snd_tm6000_card *chip = snd_pcm_substream_chip(substream);
chip->buf_pos = 0;
chip->period_pos = 0;
return 0;
}
static void audio_trigger(struct work_struct *work)
{
struct tm6000_core *core = container_of(work, struct tm6000_core,
wq_trigger);
struct snd_tm6000_card *chip = core->adev;
if (atomic_read(&core->stream_started)) {
dprintk(1, "starting capture");
_tm6000_start_audio_dma(chip);
} else {
dprintk(1, "stopping capture");
_tm6000_stop_audio_dma(chip);
}
}
static int snd_tm6000_card_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_tm6000_card *chip = snd_pcm_substream_chip(substream);
struct tm6000_core *core = chip->core;
int err = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
atomic_set(&core->stream_started, 1);
break;
case SNDRV_PCM_TRIGGER_STOP:
atomic_set(&core->stream_started, 0);
break;
default:
err = -EINVAL;
break;
}
schedule_work(&core->wq_trigger);
return err;
}
static snd_pcm_uframes_t snd_tm6000_pointer(struct snd_pcm_substream *substream)
{
struct snd_tm6000_card *chip = snd_pcm_substream_chip(substream);
return chip->buf_pos;
}
int tm6000_audio_init(struct tm6000_core *dev)
{
struct snd_card *card;
struct snd_tm6000_card *chip;
int rc;
static int devnr;
char component[14];
struct snd_pcm *pcm;
if (!dev)
return 0;
if (devnr >= SNDRV_CARDS)
return -ENODEV;
if (!enable[devnr])
return -ENOENT;
rc = snd_card_create(index[devnr], "tm6000", THIS_MODULE, 0, &card);
if (rc < 0) {
snd_printk(KERN_ERR "cannot create card instance %d\n", devnr);
return rc;
}
strcpy(card->driver, "tm6000-alsa");
strcpy(card->shortname, "TM5600/60x0");
sprintf(card->longname, "TM5600/60x0 Audio at bus %d device %d",
dev->udev->bus->busnum, dev->udev->devnum);
sprintf(component, "USB%04x:%04x",
le16_to_cpu(dev->udev->descriptor.idVendor),
le16_to_cpu(dev->udev->descriptor.idProduct));
snd_component_add(card, component);
snd_card_set_dev(card, &dev->udev->dev);
chip = kzalloc(sizeof(struct snd_tm6000_card), GFP_KERNEL);
if (!chip) {
rc = -ENOMEM;
goto error;
}
chip->core = dev;
chip->card = card;
dev->adev = chip;
spin_lock_init(&chip->reg_lock);
rc = snd_pcm_new(card, "TM6000 Audio", 0, 0, 1, &pcm);
if (rc < 0)
goto error_chip;
pcm->info_flags = 0;
pcm->private_data = chip;
strcpy(pcm->name, "Trident TM5600/60x0");
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_tm6000_pcm_ops);
INIT_WORK(&dev->wq_trigger, audio_trigger);
rc = snd_card_register(card);
if (rc < 0)
goto error_chip;
dprintk(1, "Registered audio driver for %s\n", card->longname);
return 0;
error_chip:
kfree(chip);
dev->adev = NULL;
error:
snd_card_free(card);
return rc;
}
static int tm6000_audio_fini(struct tm6000_core *dev)
{
struct snd_tm6000_card *chip = dev->adev;
if (!dev)
return 0;
if (!chip)
return 0;
if (!chip->card)
return 0;
snd_card_free(chip->card);
chip->card = NULL;
kfree(chip);
dev->adev = NULL;
return 0;
}
static int __init tm6000_alsa_register(void)
{
return tm6000_register_extension(&audio_ops);
}
static void __exit tm6000_alsa_unregister(void)
{
tm6000_unregister_extension(&audio_ops);
}
