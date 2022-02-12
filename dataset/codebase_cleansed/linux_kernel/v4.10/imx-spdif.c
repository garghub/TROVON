static int imx_spdif_audio_probe(struct platform_device *pdev)
{
struct device_node *spdif_np, *np = pdev->dev.of_node;
struct imx_spdif_data *data;
int ret = 0;
spdif_np = of_parse_phandle(np, "spdif-controller", 0);
if (!spdif_np) {
dev_err(&pdev->dev, "failed to find spdif-controller\n");
ret = -EINVAL;
goto end;
}
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
ret = -ENOMEM;
goto end;
}
data->dai.name = "S/PDIF PCM";
data->dai.stream_name = "S/PDIF PCM";
data->dai.codec_dai_name = "snd-soc-dummy-dai";
data->dai.codec_name = "snd-soc-dummy";
data->dai.cpu_of_node = spdif_np;
data->dai.platform_of_node = spdif_np;
data->dai.playback_only = true;
data->dai.capture_only = true;
if (of_property_read_bool(np, "spdif-out"))
data->dai.capture_only = false;
if (of_property_read_bool(np, "spdif-in"))
data->dai.playback_only = false;
if (data->dai.playback_only && data->dai.capture_only) {
dev_err(&pdev->dev, "no enabled S/PDIF DAI link\n");
goto end;
}
data->card.dev = &pdev->dev;
data->card.dai_link = &data->dai;
data->card.num_links = 1;
data->card.owner = THIS_MODULE;
ret = snd_soc_of_parse_card_name(&data->card, "model");
if (ret)
goto end;
ret = devm_snd_soc_register_card(&pdev->dev, &data->card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed: %d\n", ret);
goto end;
}
end:
of_node_put(spdif_np);
return ret;
}
