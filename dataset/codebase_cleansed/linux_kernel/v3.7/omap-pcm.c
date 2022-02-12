static int omap_pcm_get_dma_buswidth(int num_bits)
{
int buswidth;
switch (num_bits) {
case 16:
buswidth = DMA_SLAVE_BUSWIDTH_2_BYTES;
break;
case 32:
buswidth = DMA_SLAVE_BUSWIDTH_4_BYTES;
break;
default:
buswidth = -EINVAL;
break;
}
return buswidth;
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
if (dma_data->data_type) {
int buswidth = omap_pcm_get_dma_buswidth(dma_data->data_type);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
config.dst_addr_width = buswidth;
else
config.src_addr_width = buswidth;
}
config.src_addr = dma_data->port_addr;
config.dst_addr = dma_data->port_addr;
config.src_maxburst = dma_data->packet_size;
config.dst_maxburst = dma_data->packet_size;
return dmaengine_slave_config(chan, &config);
}
static int omap_pcm_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_set_runtime_buffer(substream, NULL);
return 0;
}
static int omap_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct omap_pcm_dma_data *dma_data;
int ret = 0;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (dma_data->set_threshold)
dma_data->set_threshold(substream);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
break;
default:
ret = -EINVAL;
}
if (ret == 0)
ret = snd_dmaengine_pcm_trigger(substream, cmd);
return ret;
}
static snd_pcm_uframes_t omap_pcm_pointer(struct snd_pcm_substream *substream)
{
snd_pcm_uframes_t offset;
if (cpu_is_omap1510())
offset = snd_dmaengine_pcm_pointer_no_residue(substream);
else
offset = snd_dmaengine_pcm_pointer(substream);
return offset;
}
static int omap_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct omap_pcm_dma_data *dma_data;
int ret;
snd_soc_set_runtime_hwparams(substream, &omap_pcm_hardware);
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
return ret;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
ret = snd_dmaengine_pcm_open(substream, omap_dma_filter_fn,
&dma_data->dma_req);
return ret;
}
static int omap_pcm_close(struct snd_pcm_substream *substream)
{
snd_dmaengine_pcm_close(substream);
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
struct snd_pcm *pcm = rtd->pcm;
int ret = 0;
if (!card->dev->dma_mask)
card->dev->dma_mask = &omap_pcm_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = DMA_BIT_MASK(64);
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
