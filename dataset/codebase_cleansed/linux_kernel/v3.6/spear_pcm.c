static int spear_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
return 0;
}
static int spear_pcm_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_set_runtime_buffer(substream, NULL);
return 0;
}
static int spear_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct spear_dma_data *dma_data = (struct spear_dma_data *)
snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
int ret;
ret = snd_soc_set_runtime_hwparams(substream, &spear_pcm_hardware);
if (ret)
return ret;
ret = snd_dmaengine_pcm_open(substream, dma_data->filter, dma_data);
if (ret)
return ret;
snd_dmaengine_pcm_set_data(substream, dma_data);
return 0;
}
static int spear_pcm_close(struct snd_pcm_substream *substream)
{
snd_dmaengine_pcm_close(substream);
return 0;
}
static int spear_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return dma_mmap_writecombine(substream->pcm->card->dev, vma,
runtime->dma_area, runtime->dma_addr,
runtime->dma_bytes);
}
static int
spear_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream,
size_t size)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_writecombine(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
if (!buf->area)
return -ENOMEM;
dev_info(buf->dev.dev,
" preallocate_dma_buffer: area=%p, addr=%p, size=%d\n",
(void *)buf->area, (void *)buf->addr, size);
buf->bytes = size;
return 0;
}
static void spear_pcm_free(struct snd_pcm *pcm)
{
struct snd_pcm_substream *substream;
struct snd_dma_buffer *buf;
int stream;
for (stream = 0; stream < 2; stream++) {
substream = pcm->streams[stream].substream;
if (!substream)
continue;
buf = &substream->dma_buffer;
if (!buf || !buf->area)
continue;
dma_free_writecombine(pcm->card->dev, buf->bytes,
buf->area, buf->addr);
buf->area = NULL;
}
}
static int spear_pcm_new(struct snd_card *card,
struct snd_soc_dai *dai, struct snd_pcm *pcm)
{
int ret;
if (!card->dev->dma_mask)
card->dev->dma_mask = &spear_pcm_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = DMA_BIT_MASK(32);
if (dai->driver->playback.channels_min) {
ret = spear_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK,
spear_pcm_hardware.buffer_bytes_max);
if (ret)
return ret;
}
if (dai->driver->capture.channels_min) {
ret = spear_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE,
spear_pcm_hardware.buffer_bytes_max);
if (ret)
return ret;
}
return 0;
}
static int __devinit spear_soc_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_platform(&pdev->dev, &spear_soc_platform);
}
static int __devexit spear_soc_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
