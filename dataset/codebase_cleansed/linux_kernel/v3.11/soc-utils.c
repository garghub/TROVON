int snd_soc_calc_frame_size(int sample_size, int channels, int tdm_slots)
{
return sample_size * channels * tdm_slots;
}
int snd_soc_params_to_frame_size(struct snd_pcm_hw_params *params)
{
int sample_size;
sample_size = snd_pcm_format_width(params_format(params));
if (sample_size < 0)
return sample_size;
return snd_soc_calc_frame_size(sample_size, params_channels(params),
1);
}
int snd_soc_calc_bclk(int fs, int sample_size, int channels, int tdm_slots)
{
return fs * snd_soc_calc_frame_size(sample_size, channels, tdm_slots);
}
int snd_soc_params_to_bclk(struct snd_pcm_hw_params *params)
{
int ret;
ret = snd_soc_params_to_frame_size(params);
if (ret > 0)
return ret * params_rate(params);
else
return ret;
}
static int dummy_dma_open(struct snd_pcm_substream *substream)
{
snd_soc_set_runtime_hwparams(substream, &dummy_dma_hardware);
return 0;
}
static int snd_soc_dummy_probe(struct platform_device *pdev)
{
int ret;
ret = snd_soc_register_codec(&pdev->dev, &dummy_codec, &dummy_dai, 1);
if (ret < 0)
return ret;
ret = snd_soc_register_platform(&pdev->dev, &dummy_platform);
if (ret < 0) {
snd_soc_unregister_codec(&pdev->dev);
return ret;
}
return ret;
}
static int snd_soc_dummy_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
int __init snd_soc_util_init(void)
{
int ret;
soc_dummy_dev =
platform_device_register_simple("snd-soc-dummy", -1, NULL, 0);
if (IS_ERR(soc_dummy_dev))
return PTR_ERR(soc_dummy_dev);
ret = platform_driver_register(&soc_dummy_driver);
if (ret != 0)
platform_device_unregister(soc_dummy_dev);
return ret;
}
void __exit snd_soc_util_exit(void)
{
platform_device_unregister(soc_dummy_dev);
platform_driver_unregister(&soc_dummy_driver);
}
