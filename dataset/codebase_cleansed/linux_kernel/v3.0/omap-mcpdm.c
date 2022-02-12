static int omap_mcpdm_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
int err = 0;
if (!dai->active)
err = omap_mcpdm_request();
return err;
}
static void omap_mcpdm_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
if (!dai->active)
omap_mcpdm_free();
}
static int omap_mcpdm_dai_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct omap_mcpdm_data *mcpdm_priv = snd_soc_dai_get_drvdata(dai);
int stream = substream->stream;
int err = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (!mcpdm_priv->active++)
omap_mcpdm_start(stream);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (!--mcpdm_priv->active)
omap_mcpdm_stop(stream);
break;
default:
err = -EINVAL;
}
return err;
}
static int omap_mcpdm_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct omap_mcpdm_data *mcpdm_priv = snd_soc_dai_get_drvdata(dai);
struct omap_mcpdm_link *mcpdm_links = mcpdm_priv->links;
int stream = substream->stream;
int channels, err, link_mask = 0;
snd_soc_dai_set_dma_data(dai, substream,
&omap_mcpdm_dai_dma_params[stream]);
channels = params_channels(params);
switch (channels) {
case 4:
if (stream == SNDRV_PCM_STREAM_CAPTURE)
return -EINVAL;
link_mask |= 1 << 3;
case 3:
if (stream == SNDRV_PCM_STREAM_CAPTURE)
return -EINVAL;
link_mask |= 1 << 2;
case 2:
link_mask |= 1 << 1;
case 1:
link_mask |= 1 << 0;
break;
default:
return -EINVAL;
}
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
mcpdm_links[stream].channels = link_mask << 3;
err = omap_mcpdm_playback_open(&mcpdm_links[stream]);
} else {
mcpdm_links[stream].channels = link_mask << 0;
err = omap_mcpdm_capture_open(&mcpdm_links[stream]);
}
return err;
}
static int omap_mcpdm_dai_hw_free(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct omap_mcpdm_data *mcpdm_priv = snd_soc_dai_get_drvdata(dai);
struct omap_mcpdm_link *mcpdm_links = mcpdm_priv->links;
int stream = substream->stream;
int err;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
err = omap_mcpdm_playback_close(&mcpdm_links[stream]);
else
err = omap_mcpdm_capture_close(&mcpdm_links[stream]);
return err;
}
static int omap_mcpdm_dai_probe(struct snd_soc_dai *dai)
{
snd_soc_dai_set_drvdata(dai, &mcpdm_data);
return 0;
}
static __devinit int asoc_mcpdm_probe(struct platform_device *pdev)
{
int ret;
ret = omap_mcpdm_probe(pdev);
if (ret < 0)
return ret;
ret = snd_soc_register_dai(&pdev->dev, &omap_mcpdm_dai);
if (ret < 0)
omap_mcpdm_remove(pdev);
return ret;
}
static int __devexit asoc_mcpdm_remove(struct platform_device *pdev)
{
snd_soc_unregister_dai(&pdev->dev);
omap_mcpdm_remove(pdev);
return 0;
}
static int __init snd_omap_mcpdm_init(void)
{
return platform_driver_register(&asoc_mcpdm_driver);
}
static void __exit snd_omap_mcpdm_exit(void)
{
platform_driver_unregister(&asoc_mcpdm_driver);
}
