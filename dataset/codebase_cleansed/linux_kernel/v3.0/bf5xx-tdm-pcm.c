static void bf5xx_dma_irq(void *data)
{
struct snd_pcm_substream *pcm = data;
snd_pcm_period_elapsed(pcm);
}
static int bf5xx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
size_t size = bf5xx_pcm_hardware.buffer_bytes_max;
snd_pcm_lib_malloc_pages(substream, size * 4);
return 0;
}
static int bf5xx_pcm_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_lib_free_pages(substream);
return 0;
}
static int bf5xx_pcm_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct sport_device *sport = runtime->private_data;
int fragsize_bytes = frames_to_bytes(runtime, runtime->period_size);
fragsize_bytes /= runtime->channels;
fragsize_bytes *= 8;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
sport_set_tx_callback(sport, bf5xx_dma_irq, substream);
sport_config_tx_dma(sport, runtime->dma_area,
runtime->periods, fragsize_bytes);
} else {
sport_set_rx_callback(sport, bf5xx_dma_irq, substream);
sport_config_rx_dma(sport, runtime->dma_area,
runtime->periods, fragsize_bytes);
}
return 0;
}
static int bf5xx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct sport_device *sport = runtime->private_data;
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
sport_tx_start(sport);
else
sport_rx_start(sport);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
sport_tx_stop(sport);
else
sport_rx_stop(sport);
break;
default:
ret = -EINVAL;
}
return ret;
}
static snd_pcm_uframes_t bf5xx_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct sport_device *sport = runtime->private_data;
unsigned int diff;
snd_pcm_uframes_t frames;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
diff = sport_curr_offset_tx(sport);
frames = diff / (8*4);
} else {
diff = sport_curr_offset_rx(sport);
frames = diff / (8*4);
}
return frames;
}
static int bf5xx_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(cpu_dai);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_dma_buffer *buf = &substream->dma_buffer;
int ret = 0;
snd_soc_set_runtime_hwparams(substream, &bf5xx_pcm_hardware);
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
goto out;
if (sport_handle != NULL) {
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
sport_handle->tx_buf = buf->area;
else
sport_handle->rx_buf = buf->area;
runtime->private_data = sport_handle;
} else {
pr_err("sport_handle is NULL\n");
ret = -ENODEV;
}
out:
return ret;
}
static int bf5xx_pcm_copy(struct snd_pcm_substream *substream, int channel,
snd_pcm_uframes_t pos, void *buf, snd_pcm_uframes_t count)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct sport_device *sport = runtime->private_data;
struct bf5xx_tdm_port *tdm_port = sport->private_data;
unsigned int *src;
unsigned int *dst;
int i;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
src = buf;
dst = (unsigned int *)substream->runtime->dma_area;
dst += pos * 8;
while (count--) {
for (i = 0; i < substream->runtime->channels; i++)
*(dst + tdm_port->tx_map[i]) = *src++;
dst += 8;
}
} else {
src = (unsigned int *)substream->runtime->dma_area;
dst = buf;
src += pos * 8;
while (count--) {
for (i = 0; i < substream->runtime->channels; i++)
*dst++ = *(src + tdm_port->rx_map[i]);
src += 8;
}
}
return 0;
}
static int bf5xx_pcm_silence(struct snd_pcm_substream *substream,
int channel, snd_pcm_uframes_t pos, snd_pcm_uframes_t count)
{
unsigned char *buf = substream->runtime->dma_area;
buf += pos * 8 * 4;
memset(buf, '\0', count * 8 * 4);
return 0;
}
static int bf5xx_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = bf5xx_pcm_hardware.buffer_bytes_max;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_coherent(pcm->card->dev, size * 4,
&buf->addr, GFP_KERNEL);
if (!buf->area) {
pr_err("Failed to allocate dma memory - Please increase uncached DMA memory region\n");
return -ENOMEM;
}
buf->bytes = size;
return 0;
}
static void bf5xx_pcm_free_dma_buffers(struct snd_pcm *pcm)
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
dma_free_coherent(NULL, buf->bytes, buf->area, 0);
buf->area = NULL;
}
}
static int bf5xx_pcm_tdm_new(struct snd_card *card, struct snd_soc_dai *dai,
struct snd_pcm *pcm)
{
int ret = 0;
if (!card->dev->dma_mask)
card->dev->dma_mask = &bf5xx_pcm_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = DMA_BIT_MASK(32);
if (dai->driver->playback.channels_min) {
ret = bf5xx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
goto out;
}
if (dai->driver->capture.channels_min) {
ret = bf5xx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
goto out;
}
out:
return ret;
}
static int __devinit bf5xx_soc_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_platform(&pdev->dev, &bf5xx_tdm_soc_platform);
}
static int __devexit bf5xx_soc_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
static int __init snd_bfin_tdm_init(void)
{
return platform_driver_register(&bfin_tdm_driver);
}
static void __exit snd_bfin_tdm_exit(void)
{
platform_driver_unregister(&bfin_tdm_driver);
}
