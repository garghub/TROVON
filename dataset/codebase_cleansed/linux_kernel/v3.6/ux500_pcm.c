static void ux500_pcm_dma_hw_free(struct device *dev,
struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_dma_buffer *buf = runtime->dma_buffer_p;
if (runtime->dma_area == NULL)
return;
if (buf != &substream->dma_buffer) {
dma_free_coherent(buf->dev.dev, buf->bytes, buf->area,
buf->addr);
kfree(runtime->dma_buffer_p);
}
snd_pcm_set_runtime_buffer(substream, NULL);
}
static int ux500_pcm_open(struct snd_pcm_substream *substream)
{
int stream_id = substream->pstr->stream;
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *dai = rtd->cpu_dai;
struct device *dev = dai->dev;
int ret;
struct ux500_msp_dma_params *dma_params;
u16 per_data_width, mem_data_width;
struct stedma40_chan_cfg *dma_cfg;
dev_dbg(dev, "%s: MSP %d (%s): Enter.\n", __func__, dai->id,
snd_pcm_stream_str(substream));
dev_dbg(dev, "%s: Set runtime hwparams.\n", __func__);
if (stream_id == SNDRV_PCM_STREAM_PLAYBACK)
snd_soc_set_runtime_hwparams(substream,
&ux500_pcm_hw_playback);
else
snd_soc_set_runtime_hwparams(substream,
&ux500_pcm_hw_capture);
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0) {
dev_err(dev, "%s: Error: snd_pcm_hw_constraints failed (%d)\n",
__func__, ret);
return ret;
}
dev_dbg(dev, "%s: Set hw-struct for %s.\n", __func__,
snd_pcm_stream_str(substream));
runtime->hw = (stream_id == SNDRV_PCM_STREAM_PLAYBACK) ?
ux500_pcm_hw_playback : ux500_pcm_hw_capture;
mem_data_width = STEDMA40_HALFWORD_WIDTH;
dma_params = snd_soc_dai_get_dma_data(dai, substream);
switch (dma_params->data_size) {
case 32:
per_data_width = STEDMA40_WORD_WIDTH;
break;
case 16:
per_data_width = STEDMA40_HALFWORD_WIDTH;
break;
case 8:
per_data_width = STEDMA40_BYTE_WIDTH;
break;
default:
per_data_width = STEDMA40_WORD_WIDTH;
dev_warn(rtd->platform->dev,
"%s: Unknown data-size (%d)! Assuming 32 bits.\n",
__func__, dma_params->data_size);
}
dma_cfg = dma_params->dma_cfg;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
dma_cfg->src_info.data_width = mem_data_width;
dma_cfg->dst_info.data_width = per_data_width;
} else {
dma_cfg->src_info.data_width = per_data_width;
dma_cfg->dst_info.data_width = mem_data_width;
}
ret = snd_dmaengine_pcm_open(substream, stedma40_filter, dma_cfg);
if (ret) {
dev_dbg(dai->dev,
"%s: ERROR: snd_dmaengine_pcm_open failed (%d)!\n",
__func__, ret);
return ret;
}
snd_dmaengine_pcm_set_data(substream, dma_cfg);
return 0;
}
static int ux500_pcm_close(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *dai = rtd->cpu_dai;
dev_dbg(dai->dev, "%s: Enter\n", __func__);
snd_dmaengine_pcm_close(substream);
return 0;
}
static int ux500_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_dma_buffer *buf = runtime->dma_buffer_p;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
int ret = 0;
int size;
dev_dbg(rtd->platform->dev, "%s: Enter\n", __func__);
size = params_buffer_bytes(hw_params);
if (buf) {
if (buf->bytes >= size)
goto out;
ux500_pcm_dma_hw_free(NULL, substream);
}
if (substream->dma_buffer.area != NULL &&
substream->dma_buffer.bytes >= size) {
buf = &substream->dma_buffer;
} else {
buf = kmalloc(sizeof(struct snd_dma_buffer), GFP_KERNEL);
if (!buf)
goto nomem;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = NULL;
buf->area = dma_alloc_coherent(NULL, size, &buf->addr,
GFP_KERNEL);
buf->bytes = size;
buf->private_data = NULL;
if (!buf->area)
goto free;
}
snd_pcm_set_runtime_buffer(substream, buf);
ret = 1;
out:
runtime->dma_bytes = size;
return ret;
free:
kfree(buf);
nomem:
return -ENOMEM;
}
static int ux500_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
dev_dbg(rtd->platform->dev, "%s: Enter\n", __func__);
ux500_pcm_dma_hw_free(NULL, substream);
return 0;
}
static int ux500_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
dev_dbg(rtd->platform->dev, "%s: Enter.\n", __func__);
return dma_mmap_coherent(NULL, vma, runtime->dma_area,
runtime->dma_addr, runtime->dma_bytes);
}
int ux500_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_pcm *pcm = rtd->pcm;
dev_dbg(rtd->platform->dev, "%s: Enter (id = '%s').\n", __func__,
pcm->id);
pcm->info_flags = 0;
return 0;
}
static int __devexit ux500_pcm_drv_probe(struct platform_device *pdev)
{
int ret;
ret = snd_soc_register_platform(&pdev->dev, &ux500_pcm_soc_drv);
if (ret < 0) {
dev_err(&pdev->dev,
"%s: ERROR: Failed to register platform '%s' (%d)!\n",
__func__, pdev->name, ret);
return ret;
}
return 0;
}
static int __devinit ux500_pcm_drv_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
