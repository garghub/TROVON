static struct dma_chan *ux500_pcm_request_chan(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_substream *substream)
{
struct snd_soc_dai *dai = rtd->cpu_dai;
struct device *dev = dai->dev;
u16 per_data_width, mem_data_width;
struct stedma40_chan_cfg *dma_cfg;
struct ux500_msp_dma_params *dma_params;
dev_dbg(dev, "%s: MSP %d (%s): Enter.\n", __func__, dai->id,
snd_pcm_stream_str(substream));
dma_params = snd_soc_dai_get_dma_data(dai, substream);
dma_cfg = dma_params->dma_cfg;
mem_data_width = STEDMA40_HALFWORD_WIDTH;
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
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
dma_cfg->src_info.data_width = mem_data_width;
dma_cfg->dst_info.data_width = per_data_width;
} else {
dma_cfg->src_info.data_width = per_data_width;
dma_cfg->dst_info.data_width = mem_data_width;
}
return snd_dmaengine_pcm_request_channel(stedma40_filter, dma_cfg);
}
int ux500_pcm_register_platform(struct platform_device *pdev)
{
int ret;
ret = snd_dmaengine_pcm_register(&pdev->dev,
&ux500_dmaengine_pcm_config,
SND_DMAENGINE_PCM_FLAG_NO_RESIDUE |
SND_DMAENGINE_PCM_FLAG_COMPAT |
SND_DMAENGINE_PCM_FLAG_NO_DT);
if (ret < 0) {
dev_err(&pdev->dev,
"%s: ERROR: Failed to register platform '%s' (%d)!\n",
__func__, pdev->name, ret);
return ret;
}
return 0;
}
int ux500_pcm_unregister_platform(struct platform_device *pdev)
{
snd_dmaengine_pcm_unregister(&pdev->dev);
return 0;
}
