static bool ep93xx_pcm_dma_filter(struct dma_chan *chan, void *filter_param)
{
struct ep93xx_dma_data *data = filter_param;
if (data->direction == ep93xx_dma_chan_direction(chan)) {
chan->private = data;
return true;
}
return false;
}
static int ep93xx_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
snd_soc_set_runtime_hwparams(substream, &ep93xx_pcm_hardware);
return snd_dmaengine_pcm_open_request_chan(substream,
ep93xx_pcm_dma_filter,
snd_soc_dai_get_dma_data(rtd->cpu_dai, substream));
}
static int ep93xx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
return 0;
}
static int ep93xx_pcm_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_set_runtime_buffer(substream, NULL);
return 0;
}
static int ep93xx_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return dma_mmap_writecombine(substream->pcm->card->dev, vma,
runtime->dma_area,
runtime->dma_addr,
runtime->dma_bytes);
}
static int ep93xx_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = ep93xx_pcm_hardware.buffer_bytes_max;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_writecombine(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
buf->bytes = size;
return (buf->area == NULL) ? -ENOMEM : 0;
}
static void ep93xx_pcm_free_dma_buffers(struct snd_pcm *pcm)
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
dma_free_writecombine(pcm->card->dev, buf->bytes, buf->area,
buf->addr);
buf->area = NULL;
}
}
static int ep93xx_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
int ret = 0;
if (!card->dev->dma_mask)
card->dev->dma_mask = &ep93xx_pcm_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = DMA_BIT_MASK(32);
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {
ret = ep93xx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
return ret;
}
if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
ret = ep93xx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
return ret;
}
return 0;
}
static int ep93xx_soc_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_platform(&pdev->dev, &ep93xx_soc_platform);
}
static int ep93xx_soc_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
