static bool filter(struct dma_chan *chan, void *param)
{
if (!imx_dma_is_general_purpose(chan))
return false;
chan->private = param;
return true;
}
static int snd_imx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct dma_chan *chan = snd_dmaengine_pcm_get_chan(substream);
struct imx_pcm_dma_params *dma_params;
struct dma_slave_config slave_config;
int ret;
dma_params = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
ret = snd_hwparams_to_dma_slave_config(substream, params, &slave_config);
if (ret)
return ret;
slave_config.device_fc = false;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
slave_config.dst_addr = dma_params->dma_addr;
slave_config.dst_maxburst = dma_params->burstsize;
} else {
slave_config.src_addr = dma_params->dma_addr;
slave_config.src_maxburst = dma_params->burstsize;
}
ret = dmaengine_slave_config(chan, &slave_config);
if (ret)
return ret;
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
return 0;
}
static int snd_imx_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct imx_pcm_dma_params *dma_params;
struct imx_dma_data *dma_data;
int ret;
snd_soc_set_runtime_hwparams(substream, &snd_imx_hardware);
dma_params = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
dma_data = kzalloc(sizeof(*dma_data), GFP_KERNEL);
dma_data->peripheral_type = IMX_DMATYPE_SSI;
dma_data->priority = DMA_PRIO_HIGH;
dma_data->dma_request = dma_params->dma;
ret = snd_dmaengine_pcm_open(substream, filter, dma_data);
if (ret) {
kfree(dma_data);
return 0;
}
snd_dmaengine_pcm_set_data(substream, dma_data);
return 0;
}
static int snd_imx_close(struct snd_pcm_substream *substream)
{
struct imx_dma_data *dma_data = snd_dmaengine_pcm_get_data(substream);
snd_dmaengine_pcm_close(substream);
kfree(dma_data);
return 0;
}
static int __devinit imx_soc_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_platform(&pdev->dev, &imx_soc_platform_mx2);
}
static int __devexit imx_soc_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
