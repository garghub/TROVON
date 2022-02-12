int hda_display_power(struct hda_intel *hda, bool enable)
{
struct i915_audio_component *acomp = &hda->audio_component;
if (!acomp->ops)
return -ENODEV;
dev_dbg(&hda->chip.pci->dev, "display power %s\n",
enable ? "enable" : "disable");
if (enable)
acomp->ops->get_power(acomp->dev);
else
acomp->ops->put_power(acomp->dev);
return 0;
}
void haswell_set_bclk(struct hda_intel *hda)
{
int cdclk_freq;
unsigned int bclk_m, bclk_n;
struct i915_audio_component *acomp = &hda->audio_component;
if (!acomp->ops)
return;
cdclk_freq = acomp->ops->get_cdclk_freq(acomp->dev);
switch (cdclk_freq) {
case 337500:
bclk_m = 16;
bclk_n = 225;
break;
case 450000:
default:
bclk_m = 4;
bclk_n = 75;
break;
case 540000:
bclk_m = 4;
bclk_n = 90;
break;
case 675000:
bclk_m = 8;
bclk_n = 225;
break;
}
azx_writew(&hda->chip, EM4, bclk_m);
azx_writew(&hda->chip, EM5, bclk_n);
}
static int hda_component_master_bind(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip = card->private_data;
struct hda_intel *hda = container_of(chip, struct hda_intel, chip);
struct i915_audio_component *acomp = &hda->audio_component;
int ret;
ret = component_bind_all(dev, acomp);
if (ret < 0)
return ret;
if (WARN_ON(!(acomp->dev && acomp->ops && acomp->ops->get_power &&
acomp->ops->put_power && acomp->ops->get_cdclk_freq))) {
ret = -EINVAL;
goto out_unbind;
}
if (!try_module_get(acomp->ops->owner)) {
ret = -ENODEV;
goto out_unbind;
}
return 0;
out_unbind:
component_unbind_all(dev, acomp);
return ret;
}
static void hda_component_master_unbind(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct azx *chip = card->private_data;
struct hda_intel *hda = container_of(chip, struct hda_intel, chip);
struct i915_audio_component *acomp = &hda->audio_component;
module_put(acomp->ops->owner);
component_unbind_all(dev, acomp);
WARN_ON(acomp->ops || acomp->dev);
}
static int hda_component_master_match(struct device *dev, void *data)
{
return !strcmp(dev->driver->name, "i915");
}
int hda_i915_init(struct hda_intel *hda)
{
struct component_match *match = NULL;
struct device *dev = &hda->chip.pci->dev;
struct i915_audio_component *acomp = &hda->audio_component;
int ret;
component_match_add(dev, &match, hda_component_master_match, hda);
ret = component_master_add_with_match(dev, &hda_component_master_ops,
match);
if (ret < 0)
goto out_err;
request_module("i915");
if (!acomp->ops) {
ret = -ENODEV;
goto out_master_del;
}
dev_dbg(dev, "bound to i915 component master\n");
return 0;
out_master_del:
component_master_del(dev, &hda_component_master_ops);
out_err:
dev_err(dev, "failed to add i915 component master (%d)\n", ret);
return ret;
}
int hda_i915_exit(struct hda_intel *hda)
{
struct device *dev = &hda->chip.pci->dev;
component_master_del(dev, &hda_component_master_ops);
return 0;
}
