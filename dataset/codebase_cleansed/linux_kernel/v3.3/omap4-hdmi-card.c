static int omap4_hdmi_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
int i;
struct omap_overlay_manager *mgr = NULL;
struct device *dev = substream->pcm->card->dev;
for (i = 0; i < omap_dss_get_num_overlay_managers(); i++) {
mgr = omap_dss_get_overlay_manager(i);
if (mgr && mgr->device
&& mgr->device->type == OMAP_DISPLAY_TYPE_HDMI)
break;
}
if (i == omap_dss_get_num_overlay_managers()) {
dev_err(dev, "HDMI display device not found!\n");
return -ENODEV;
}
if (mgr->device->state != OMAP_DSS_DISPLAY_ACTIVE) {
dev_err(dev, "HDMI display is not active!\n");
return -EIO;
}
return 0;
}
static __devinit int omap4_hdmi_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snd_soc_omap4_hdmi;
int ret;
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
card->dev = NULL;
return ret;
}
return 0;
}
static int __devexit omap4_hdmi_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
snd_soc_unregister_card(card);
card->dev = NULL;
return 0;
}
