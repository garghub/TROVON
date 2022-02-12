static int tegra_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct device *dev = rtd->platform->dev;
int ret;
snd_soc_set_runtime_hwparams(substream, &tegra_pcm_hardware);
ret = snd_dmaengine_pcm_open(substream, NULL, NULL);
if (ret) {
dev_err(dev, "dmaengine pcm open failed with err %d\n", ret);
return ret;
}
return 0;
}
static int tegra_pcm_close(struct snd_pcm_substream *substream)
{
snd_dmaengine_pcm_close(substream);
return 0;
}
static int tegra_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct device *dev = rtd->platform->dev;
struct dma_chan *chan = snd_dmaengine_pcm_get_chan(substream);
struct tegra_pcm_dma_params *dmap;
struct dma_slave_config slave_config;
int ret;
dmap = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
ret = snd_hwparams_to_dma_slave_config(substream, params,
&slave_config);
if (ret) {
dev_err(dev, "hw params config failed with err %d\n", ret);
return ret;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
slave_config.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
slave_config.dst_addr = dmap->addr;
slave_config.dst_maxburst = 4;
} else {
slave_config.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
slave_config.src_addr = dmap->addr;
slave_config.src_maxburst = 4;
}
slave_config.slave_id = dmap->req_sel;
ret = dmaengine_slave_config(chan, &slave_config);
if (ret < 0) {
dev_err(dev, "dma slave config failed with err %d\n", ret);
return ret;
}
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
return 0;
}
static int tegra_pcm_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_set_runtime_buffer(substream, NULL);
return 0;
}
static int tegra_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return dma_mmap_writecombine(substream->pcm->card->dev, vma,
runtime->dma_area,
runtime->dma_addr,
runtime->dma_bytes);
}
static int tegra_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = tegra_pcm_hardware.buffer_bytes_max;
buf->area = dma_alloc_writecombine(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
if (!buf->area)
return -ENOMEM;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->bytes = size;
return 0;
}
static void tegra_pcm_deallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_pcm_substream *substream;
struct snd_dma_buffer *buf;
substream = pcm->streams[stream].substream;
if (!substream)
return;
buf = &substream->dma_buffer;
if (!buf->area)
return;
dma_free_writecombine(pcm->card->dev, buf->bytes,
buf->area, buf->addr);
buf->area = NULL;
}
static int tegra_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
int ret = 0;
if (!card->dev->dma_mask)
card->dev->dma_mask = &tegra_dma_mask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = DMA_BIT_MASK(32);
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {
ret = tegra_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
goto err;
}
if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
ret = tegra_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
goto err_free_play;
}
return 0;
err_free_play:
tegra_pcm_deallocate_dma_buffer(pcm, SNDRV_PCM_STREAM_PLAYBACK);
err:
return ret;
}
static void tegra_pcm_free(struct snd_pcm *pcm)
{
tegra_pcm_deallocate_dma_buffer(pcm, SNDRV_PCM_STREAM_CAPTURE);
tegra_pcm_deallocate_dma_buffer(pcm, SNDRV_PCM_STREAM_PLAYBACK);
}
int tegra_pcm_platform_register(struct device *dev)
{
return snd_soc_register_platform(dev, &tegra_pcm_platform);
}
void tegra_pcm_platform_unregister(struct device *dev)
{
snd_soc_unregister_platform(dev);
}
