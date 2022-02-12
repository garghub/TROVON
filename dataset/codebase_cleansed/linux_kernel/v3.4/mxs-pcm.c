static bool filter(struct dma_chan *chan, void *param)
{
struct mxs_pcm_dma_data *pcm_dma_data = param;
struct mxs_pcm_dma_params *dma_params = pcm_dma_data->dma_params;
if (!mxs_dma_is_apbx(chan))
return false;
if (chan->chan_id != dma_params->chan_num)
return false;
chan->private = &pcm_dma_data->dma_data;
return true;
}
static int snd_mxs_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
return 0;
}
static int snd_mxs_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct mxs_pcm_dma_data *pcm_dma_data;
int ret;
pcm_dma_data = kzalloc(sizeof(*pcm_dma_data), GFP_KERNEL);
if (pcm_dma_data == NULL)
return -ENOMEM;
pcm_dma_data->dma_params = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
pcm_dma_data->dma_data.chan_irq = pcm_dma_data->dma_params->chan_irq;
ret = snd_dmaengine_pcm_open(substream, filter, pcm_dma_data);
if (ret) {
kfree(pcm_dma_data);
return ret;
}
snd_soc_set_runtime_hwparams(substream, &snd_mxs_hardware);
snd_dmaengine_pcm_set_data(substream, pcm_dma_data);
return 0;
}
static int snd_mxs_close(struct snd_pcm_substream *substream)
{
struct mxs_pcm_dma_data *pcm_dma_data = snd_dmaengine_pcm_get_data(substream);
snd_dmaengine_pcm_close(substream);
kfree(pcm_dma_data);
return 0;
}
static int snd_mxs_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return dma_mmap_writecombine(substream->pcm->card->dev, vma,
runtime->dma_area,
runtime->dma_addr,
runtime->dma_bytes);
}
static int mxs_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = snd_mxs_hardware.buffer_bytes_max;
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
static int mxs_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
int ret = 0;
if (!card->dev->dma_mask)
card->dev->dma_mask = &mxs_pcm_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = DMA_BIT_MASK(32);
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {
ret = mxs_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
goto out;
}
if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
ret = mxs_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
goto out;
}
out:
return ret;
}
static void mxs_pcm_free(struct snd_pcm *pcm)
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
static int __devinit mxs_soc_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_platform(&pdev->dev, &mxs_soc_platform);
}
static int __devexit mxs_soc_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
