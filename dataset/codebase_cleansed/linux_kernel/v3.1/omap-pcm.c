static void omap_pcm_dma_irq(int ch, u16 stat, void *data)
{
struct snd_pcm_substream *substream = data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct omap_runtime_data *prtd = runtime->private_data;
unsigned long flags;
if ((cpu_is_omap1510())) {
spin_lock_irqsave(&prtd->lock, flags);
if ((stat == OMAP_DMA_LAST_IRQ) &&
(prtd->period_index == runtime->periods - 1)) {
spin_unlock_irqrestore(&prtd->lock, flags);
return;
}
if (prtd->period_index >= 0) {
if (stat & OMAP_DMA_BLOCK_IRQ) {
prtd->period_index = 0;
} else if (stat & OMAP_DMA_LAST_IRQ) {
prtd->period_index = runtime->periods - 1;
} else if (++prtd->period_index >= runtime->periods) {
prtd->period_index = 0;
}
}
spin_unlock_irqrestore(&prtd->lock, flags);
}
snd_pcm_period_elapsed(substream);
}
static int omap_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct omap_runtime_data *prtd = runtime->private_data;
struct omap_pcm_dma_data *dma_data;
int err = 0;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (!dma_data)
return 0;
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
runtime->dma_bytes = params_buffer_bytes(params);
if (prtd->dma_data)
return 0;
prtd->dma_data = dma_data;
err = omap_request_dma(dma_data->dma_req, dma_data->name,
omap_pcm_dma_irq, substream, &prtd->dma_ch);
if (!err) {
omap_dma_link_lch(prtd->dma_ch, prtd->dma_ch);
}
return err;
}
static int omap_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct omap_runtime_data *prtd = runtime->private_data;
if (prtd->dma_data == NULL)
return 0;
omap_dma_unlink_lch(prtd->dma_ch, prtd->dma_ch);
omap_free_dma(prtd->dma_ch);
prtd->dma_data = NULL;
snd_pcm_set_runtime_buffer(substream, NULL);
return 0;
}
static int omap_pcm_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct omap_runtime_data *prtd = runtime->private_data;
struct omap_pcm_dma_data *dma_data = prtd->dma_data;
struct omap_dma_channel_params dma_params;
int bytes;
if (!prtd->dma_data)
return 0;
memset(&dma_params, 0, sizeof(dma_params));
dma_params.data_type = dma_data->data_type;
dma_params.trigger = dma_data->dma_req;
dma_params.sync_mode = dma_data->sync_mode;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
dma_params.src_amode = OMAP_DMA_AMODE_POST_INC;
dma_params.dst_amode = OMAP_DMA_AMODE_CONSTANT;
dma_params.src_or_dst_synch = OMAP_DMA_DST_SYNC;
dma_params.src_start = runtime->dma_addr;
dma_params.dst_start = dma_data->port_addr;
dma_params.dst_port = OMAP_DMA_PORT_MPUI;
dma_params.dst_fi = dma_data->packet_size;
} else {
dma_params.src_amode = OMAP_DMA_AMODE_CONSTANT;
dma_params.dst_amode = OMAP_DMA_AMODE_POST_INC;
dma_params.src_or_dst_synch = OMAP_DMA_SRC_SYNC;
dma_params.src_start = dma_data->port_addr;
dma_params.dst_start = runtime->dma_addr;
dma_params.src_port = OMAP_DMA_PORT_MPUI;
dma_params.src_fi = dma_data->packet_size;
}
bytes = snd_pcm_lib_period_bytes(substream);
dma_params.elem_count = bytes >> dma_data->data_type;
dma_params.frame_count = runtime->periods;
omap_set_dma_params(prtd->dma_ch, &dma_params);
if ((cpu_is_omap1510()))
omap_enable_dma_irq(prtd->dma_ch, OMAP_DMA_FRAME_IRQ |
OMAP_DMA_LAST_IRQ | OMAP_DMA_BLOCK_IRQ);
else if (!substream->runtime->no_period_wakeup)
omap_enable_dma_irq(prtd->dma_ch, OMAP_DMA_FRAME_IRQ);
if (!(cpu_class_is_omap1())) {
omap_set_dma_src_burst_mode(prtd->dma_ch,
OMAP_DMA_DATA_BURST_16);
omap_set_dma_dest_burst_mode(prtd->dma_ch,
OMAP_DMA_DATA_BURST_16);
}
return 0;
}
static int omap_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct omap_runtime_data *prtd = runtime->private_data;
struct omap_pcm_dma_data *dma_data = prtd->dma_data;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&prtd->lock, flags);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
prtd->period_index = 0;
if (dma_data->set_threshold)
dma_data->set_threshold(substream);
omap_start_dma(prtd->dma_ch);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
prtd->period_index = -1;
omap_stop_dma(prtd->dma_ch);
break;
default:
ret = -EINVAL;
}
spin_unlock_irqrestore(&prtd->lock, flags);
return ret;
}
static snd_pcm_uframes_t omap_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct omap_runtime_data *prtd = runtime->private_data;
dma_addr_t ptr;
snd_pcm_uframes_t offset;
if (cpu_is_omap1510()) {
offset = prtd->period_index * runtime->period_size;
} else if (substream->stream == SNDRV_PCM_STREAM_CAPTURE) {
ptr = omap_get_dma_dst_pos(prtd->dma_ch);
offset = bytes_to_frames(runtime, ptr - runtime->dma_addr);
} else {
ptr = omap_get_dma_src_pos(prtd->dma_ch);
offset = bytes_to_frames(runtime, ptr - runtime->dma_addr);
}
if (offset >= runtime->buffer_size)
offset = 0;
return offset;
}
static int omap_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct omap_runtime_data *prtd;
int ret;
snd_soc_set_runtime_hwparams(substream, &omap_pcm_hardware);
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
goto out;
prtd = kzalloc(sizeof(*prtd), GFP_KERNEL);
if (prtd == NULL) {
ret = -ENOMEM;
goto out;
}
spin_lock_init(&prtd->lock);
runtime->private_data = prtd;
out:
return ret;
}
static int omap_pcm_close(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
kfree(runtime->private_data);
return 0;
}
static int omap_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return dma_mmap_writecombine(substream->pcm->card->dev, vma,
runtime->dma_area,
runtime->dma_addr,
runtime->dma_bytes);
}
static int omap_pcm_preallocate_dma_buffer(struct snd_pcm *pcm,
int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = omap_pcm_hardware.buffer_bytes_max;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_writecombine(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
if (!buf->area)
return -ENOMEM;
buf->bytes = size;
return 0;
}
static void omap_pcm_free_dma_buffers(struct snd_pcm *pcm)
{
struct snd_pcm_substream *substream;
struct snd_dma_buffer *buf;
int stream;
for (stream = 0; stream < 2; stream++) {
substream = pcm->streams[stream].substream;
if (!substream)
continue;
buf = &substream->dma_buffer;
if (!buf->area)
continue;
dma_free_writecombine(pcm->card->dev, buf->bytes,
buf->area, buf->addr);
buf->area = NULL;
}
}
static int omap_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_soc_dai *dai = rtd->cpu_dai;
struct snd_pcm *pcm = rtd->pcm;
int ret = 0;
if (!card->dev->dma_mask)
card->dev->dma_mask = &omap_pcm_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = DMA_BIT_MASK(64);
if (dai->driver->playback.channels_min) {
ret = omap_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
goto out;
}
if (dai->driver->capture.channels_min) {
ret = omap_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
goto out;
}
out:
return ret;
}
static __devinit int omap_pcm_probe(struct platform_device *pdev)
{
return snd_soc_register_platform(&pdev->dev,
&omap_soc_platform);
}
static int __devexit omap_pcm_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
static int __init snd_omap_pcm_init(void)
{
return platform_driver_register(&omap_pcm_driver);
}
static void __exit snd_omap_pcm_exit(void)
{
platform_driver_unregister(&omap_pcm_driver);
}
