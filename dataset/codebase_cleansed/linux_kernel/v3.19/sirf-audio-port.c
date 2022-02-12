static int sirf_audio_port_dai_probe(struct snd_soc_dai *dai)
{
struct sirf_audio_port *port = snd_soc_dai_get_drvdata(dai);
snd_soc_dai_init_dma_data(dai, &port->playback_dma_data,
&port->capture_dma_data);
return 0;
}
static int sirf_audio_port_probe(struct platform_device *pdev)
{
int ret;
struct sirf_audio_port *port;
port = devm_kzalloc(&pdev->dev,
sizeof(struct sirf_audio_port), GFP_KERNEL);
if (!port)
return -ENOMEM;
ret = devm_snd_soc_register_component(&pdev->dev,
&sirf_audio_port_component, &sirf_audio_port_dai, 1);
if (ret)
return ret;
platform_set_drvdata(pdev, port);
return devm_snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
}
