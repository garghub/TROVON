int __pxa2xx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct dma_chan *chan = snd_dmaengine_pcm_get_chan(substream);
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_dmaengine_dai_dma_data *dma_params;
struct dma_slave_config config;
int ret;
dma_params = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (!dma_params)
return 0;
ret = snd_hwparams_to_dma_slave_config(substream, params, &config);
if (ret)
return ret;
snd_dmaengine_pcm_set_config_from_dai_data(substream,
snd_soc_dai_get_dma_data(rtd->cpu_dai, substream),
&config);
ret = dmaengine_slave_config(chan, &config);
if (ret)
return ret;
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
return 0;
}
int __pxa2xx_pcm_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_set_runtime_buffer(substream, NULL);
return 0;
}
int pxa2xx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
return snd_dmaengine_pcm_trigger(substream, cmd);
}
snd_pcm_uframes_t
pxa2xx_pcm_pointer(struct snd_pcm_substream *substream)
{
return snd_dmaengine_pcm_pointer(substream);
}
int __pxa2xx_pcm_prepare(struct snd_pcm_substream *substream)
{
return 0;
}
int __pxa2xx_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_dmaengine_dai_dma_data *dma_params;
int ret;
runtime->hw = pxa2xx_pcm_hardware;
dma_params = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (!dma_params)
return 0;
ret = snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_BYTES, 32);
if (ret)
return ret;
ret = snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_BUFFER_BYTES, 32);
if (ret)
return ret;
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
return ret;
return snd_dmaengine_pcm_open_request_chan(substream,
pxad_filter_fn,
dma_params->filter_data);
}
int __pxa2xx_pcm_close(struct snd_pcm_substream *substream)
{
return snd_dmaengine_pcm_close_release_chan(substream);
}
int pxa2xx_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return dma_mmap_writecombine(substream->pcm->card->dev, vma,
runtime->dma_area,
runtime->dma_addr,
runtime->dma_bytes);
}
int pxa2xx_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = pxa2xx_pcm_hardware.buffer_bytes_max;
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
void pxa2xx_pcm_free_dma_buffers(struct snd_pcm *pcm)
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
