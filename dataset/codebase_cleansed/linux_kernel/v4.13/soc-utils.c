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
int snd_soc_component_enable_pin(struct snd_soc_component *component,
const char *pin)
{
struct snd_soc_dapm_context *dapm =
snd_soc_component_get_dapm(component);
char *full_name;
int ret;
if (!component->name_prefix)
return snd_soc_dapm_enable_pin(dapm, pin);
full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
if (!full_name)
return -ENOMEM;
ret = snd_soc_dapm_enable_pin(dapm, full_name);
kfree(full_name);
return ret;
}
int snd_soc_component_enable_pin_unlocked(struct snd_soc_component *component,
const char *pin)
{
struct snd_soc_dapm_context *dapm =
snd_soc_component_get_dapm(component);
char *full_name;
int ret;
if (!component->name_prefix)
return snd_soc_dapm_enable_pin_unlocked(dapm, pin);
full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
if (!full_name)
return -ENOMEM;
ret = snd_soc_dapm_enable_pin_unlocked(dapm, full_name);
kfree(full_name);
return ret;
}
int snd_soc_component_disable_pin(struct snd_soc_component *component,
const char *pin)
{
struct snd_soc_dapm_context *dapm =
snd_soc_component_get_dapm(component);
char *full_name;
int ret;
if (!component->name_prefix)
return snd_soc_dapm_disable_pin(dapm, pin);
full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
if (!full_name)
return -ENOMEM;
ret = snd_soc_dapm_disable_pin(dapm, full_name);
kfree(full_name);
return ret;
}
int snd_soc_component_disable_pin_unlocked(struct snd_soc_component *component,
const char *pin)
{
struct snd_soc_dapm_context *dapm =
snd_soc_component_get_dapm(component);
char *full_name;
int ret;
if (!component->name_prefix)
return snd_soc_dapm_disable_pin_unlocked(dapm, pin);
full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
if (!full_name)
return -ENOMEM;
ret = snd_soc_dapm_disable_pin_unlocked(dapm, full_name);
kfree(full_name);
return ret;
}
int snd_soc_component_nc_pin(struct snd_soc_component *component,
const char *pin)
{
struct snd_soc_dapm_context *dapm =
snd_soc_component_get_dapm(component);
char *full_name;
int ret;
if (!component->name_prefix)
return snd_soc_dapm_nc_pin(dapm, pin);
full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
if (!full_name)
return -ENOMEM;
ret = snd_soc_dapm_nc_pin(dapm, full_name);
kfree(full_name);
return ret;
}
int snd_soc_component_nc_pin_unlocked(struct snd_soc_component *component,
const char *pin)
{
struct snd_soc_dapm_context *dapm =
snd_soc_component_get_dapm(component);
char *full_name;
int ret;
if (!component->name_prefix)
return snd_soc_dapm_nc_pin_unlocked(dapm, pin);
full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
if (!full_name)
return -ENOMEM;
ret = snd_soc_dapm_nc_pin_unlocked(dapm, full_name);
kfree(full_name);
return ret;
}
int snd_soc_component_get_pin_status(struct snd_soc_component *component,
const char *pin)
{
struct snd_soc_dapm_context *dapm =
snd_soc_component_get_dapm(component);
char *full_name;
int ret;
if (!component->name_prefix)
return snd_soc_dapm_get_pin_status(dapm, pin);
full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
if (!full_name)
return -ENOMEM;
ret = snd_soc_dapm_get_pin_status(dapm, full_name);
kfree(full_name);
return ret;
}
int snd_soc_component_force_enable_pin(struct snd_soc_component *component,
const char *pin)
{
struct snd_soc_dapm_context *dapm =
snd_soc_component_get_dapm(component);
char *full_name;
int ret;
if (!component->name_prefix)
return snd_soc_dapm_force_enable_pin(dapm, pin);
full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
if (!full_name)
return -ENOMEM;
ret = snd_soc_dapm_force_enable_pin(dapm, full_name);
kfree(full_name);
return ret;
}
int snd_soc_component_force_enable_pin_unlocked(
struct snd_soc_component *component,
const char *pin)
{
struct snd_soc_dapm_context *dapm =
snd_soc_component_get_dapm(component);
char *full_name;
int ret;
if (!component->name_prefix)
return snd_soc_dapm_force_enable_pin_unlocked(dapm, pin);
full_name = kasprintf(GFP_KERNEL, "%s %s", component->name_prefix, pin);
if (!full_name)
return -ENOMEM;
ret = snd_soc_dapm_force_enable_pin_unlocked(dapm, full_name);
kfree(full_name);
return ret;
}
static int dummy_dma_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
if (!rtd->dai_link->no_pcm)
snd_soc_set_runtime_hwparams(substream, &dummy_dma_hardware);
return 0;
}
int snd_soc_dai_is_dummy(struct snd_soc_dai *dai)
{
if (dai->driver == &dummy_dai)
return 1;
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
