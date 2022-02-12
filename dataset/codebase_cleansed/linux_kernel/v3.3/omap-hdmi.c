static int omap_hdmi_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int err;
err = snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_BYTES, 128);
if (err < 0)
return err;
return 0;
}
static int omap_hdmi_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
int err = 0;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
omap_hdmi_dai_dma_params.packet_size = 16;
break;
case SNDRV_PCM_FORMAT_S24_LE:
omap_hdmi_dai_dma_params.packet_size = 32;
break;
default:
err = -EINVAL;
}
omap_hdmi_dai_dma_params.data_type = OMAP_DMA_DATA_TYPE_S32;
snd_soc_dai_set_dma_data(dai, substream,
&omap_hdmi_dai_dma_params);
return err;
}
static __devinit int omap_hdmi_probe(struct platform_device *pdev)
{
int ret;
struct resource *hdmi_rsrc;
hdmi_rsrc = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!hdmi_rsrc) {
dev_err(&pdev->dev, "Cannot obtain IORESOURCE_MEM HDMI\n");
return -EINVAL;
}
omap_hdmi_dai_dma_params.port_addr = hdmi_rsrc->start
+ OMAP_HDMI_AUDIO_DMA_PORT;
hdmi_rsrc = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!hdmi_rsrc) {
dev_err(&pdev->dev, "Cannot obtain IORESOURCE_DMA HDMI\n");
return -EINVAL;
}
omap_hdmi_dai_dma_params.dma_req = hdmi_rsrc->start;
ret = snd_soc_register_dai(&pdev->dev, &omap_hdmi_dai);
return ret;
}
static int __devexit omap_hdmi_remove(struct platform_device *pdev)
{
snd_soc_unregister_dai(&pdev->dev);
return 0;
}
