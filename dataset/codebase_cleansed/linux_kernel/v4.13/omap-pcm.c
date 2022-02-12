static void omap_pcm_limit_supported_formats(void)
{
int i;
for (i = 0; i <= SNDRV_PCM_FORMAT_LAST; i++) {
switch (snd_pcm_format_physical_width(i)) {
case 8:
case 16:
case 32:
omap_pcm_hardware.formats |= (1LL << i);
break;
default:
break;
}
}
}
static int omap_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct omap_pcm_dma_data *dma_data;
struct dma_slave_config config;
struct dma_chan *chan;
int err = 0;
memset(&config, 0x00, sizeof(config));
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (!dma_data)
return 0;
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
runtime->dma_bytes = params_buffer_bytes(params);
chan = snd_dmaengine_pcm_get_chan(substream);
if (!chan)
return -EINVAL;
err = snd_hwparams_to_dma_slave_config(substream, params, &config);
if (err)
return err;
snd_dmaengine_pcm_set_config_from_dai_data(substream,
snd_soc_dai_get_dma_data(rtd->cpu_dai, substream),
&config);
return dmaengine_slave_config(chan, &config);
}
static int omap_pcm_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_set_runtime_buffer(substream, NULL);
return 0;
}
static snd_pcm_uframes_t omap_pcm_pointer(struct snd_pcm_substream *substream)
{
snd_pcm_uframes_t offset;
if (pcm_omap1510())
offset = snd_dmaengine_pcm_pointer_no_residue(substream);
else
offset = snd_dmaengine_pcm_pointer(substream);
return offset;
}
static int omap_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_dmaengine_dai_dma_data *dma_data;
int ret;
snd_soc_set_runtime_hwparams(substream, &omap_pcm_hardware);
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (rtd->cpu_dai->dev->of_node) {
struct dma_chan *chan;
chan = dma_request_slave_channel(rtd->cpu_dai->dev,
dma_data->filter_data);
ret = snd_dmaengine_pcm_open(substream, chan);
} else {
ret = snd_dmaengine_pcm_open_request_chan(substream,
omap_dma_filter_fn,
dma_data->filter_data);
}
return ret;
}
static int omap_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return dma_mmap_wc(substream->pcm->card->dev, vma, runtime->dma_area,
runtime->dma_addr, runtime->dma_bytes);
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
buf->area = dma_alloc_wc(pcm->card->dev, size, &buf->addr, GFP_KERNEL);
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
dma_free_wc(pcm->card->dev, buf->bytes, buf->area, buf->addr);
buf->area = NULL;
}
}
static int omap_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
int ret;
ret = dma_coerce_mask_and_coherent(card->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {
ret = omap_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
goto out;
}
if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
ret = omap_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
goto out;
}
out:
if (ret)
omap_pcm_free_dma_buffers(pcm);
return ret;
}
int omap_pcm_platform_register(struct device *dev)
{
omap_pcm_limit_supported_formats();
return devm_snd_soc_register_platform(dev, &omap_soc_platform);
}
