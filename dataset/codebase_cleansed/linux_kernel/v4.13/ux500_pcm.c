static struct dma_chan *ux500_pcm_request_chan(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_substream *substream)
{
struct snd_soc_dai *dai = rtd->cpu_dai;
u16 per_data_width, mem_data_width;
struct stedma40_chan_cfg *dma_cfg;
struct ux500_msp_dma_params *dma_params;
dma_params = snd_soc_dai_get_dma_data(dai, substream);
dma_cfg = dma_params->dma_cfg;
mem_data_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
switch (dma_params->data_size) {
case 32:
per_data_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
break;
case 16:
per_data_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
break;
case 8:
per_data_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
break;
default:
per_data_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
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
static int ux500_pcm_prepare_slave_config(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct dma_slave_config *slave_config)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct msp_i2s_platform_data *pdata = rtd->cpu_dai->dev->platform_data;
struct snd_dmaengine_dai_dma_data *snd_dma_params;
struct ux500_msp_dma_params *ste_dma_params;
dma_addr_t dma_addr;
int ret;
if (pdata) {
ste_dma_params =
snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
dma_addr = ste_dma_params->tx_rx_addr;
} else {
snd_dma_params =
snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
dma_addr = snd_dma_params->addr;
}
ret = snd_hwparams_to_dma_slave_config(substream, params, slave_config);
if (ret)
return ret;
slave_config->dst_maxburst = 4;
slave_config->src_maxburst = 4;
slave_config->src_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
slave_config->dst_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
slave_config->dst_addr = dma_addr;
else
slave_config->src_addr = dma_addr;
return 0;
}
int ux500_pcm_register_platform(struct platform_device *pdev)
{
const struct snd_dmaengine_pcm_config *pcm_config;
struct device_node *np = pdev->dev.of_node;
int ret;
if (np)
pcm_config = &ux500_dmaengine_of_pcm_config;
else
pcm_config = &ux500_dmaengine_pcm_config;
ret = snd_dmaengine_pcm_register(&pdev->dev, pcm_config,
SND_DMAENGINE_PCM_FLAG_COMPAT);
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
