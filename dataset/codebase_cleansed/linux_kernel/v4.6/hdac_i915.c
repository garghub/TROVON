int snd_hdac_set_codec_wakeup(struct hdac_bus *bus, bool enable)
{
struct i915_audio_component *acomp = bus->audio_component;
if (!acomp || !acomp->ops)
return -ENODEV;
if (!acomp->ops->codec_wake_override) {
dev_warn(bus->dev,
"Invalid codec wake callback\n");
return 0;
}
dev_dbg(bus->dev, "%s codec wakeup\n",
enable ? "enable" : "disable");
acomp->ops->codec_wake_override(acomp->dev, enable);
return 0;
}
int snd_hdac_display_power(struct hdac_bus *bus, bool enable)
{
struct i915_audio_component *acomp = bus->audio_component;
if (!acomp || !acomp->ops)
return -ENODEV;
dev_dbg(bus->dev, "display power %s\n",
enable ? "enable" : "disable");
if (enable) {
if (!bus->i915_power_refcount++) {
acomp->ops->get_power(acomp->dev);
snd_hdac_set_codec_wakeup(bus, true);
snd_hdac_set_codec_wakeup(bus, false);
}
} else {
WARN_ON(!bus->i915_power_refcount);
if (!--bus->i915_power_refcount)
acomp->ops->put_power(acomp->dev);
}
return 0;
}
void snd_hdac_i915_set_bclk(struct hdac_bus *bus)
{
struct i915_audio_component *acomp = bus->audio_component;
struct pci_dev *pci = to_pci_dev(bus->dev);
int cdclk_freq;
unsigned int bclk_m, bclk_n;
if (!acomp || !acomp->ops || !acomp->ops->get_cdclk_freq)
return;
if (!CONTROLLER_IN_GPU(pci))
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
snd_hdac_chip_writew(bus, HSW_EM4, bclk_m);
snd_hdac_chip_writew(bus, HSW_EM5, bclk_n);
}
static int pin2port(hda_nid_t pin_nid)
{
if (WARN_ON(pin_nid < 5 || pin_nid > 7))
return -1;
return pin_nid - 4;
}
int snd_hdac_sync_audio_rate(struct hdac_bus *bus, hda_nid_t nid, int rate)
{
struct i915_audio_component *acomp = bus->audio_component;
int port;
if (!acomp || !acomp->ops || !acomp->ops->sync_audio_rate)
return -ENODEV;
port = pin2port(nid);
if (port < 0)
return -EINVAL;
return acomp->ops->sync_audio_rate(acomp->dev, port, rate);
}
int snd_hdac_acomp_get_eld(struct hdac_bus *bus, hda_nid_t nid,
bool *audio_enabled, char *buffer, int max_bytes)
{
struct i915_audio_component *acomp = bus->audio_component;
int port;
if (!acomp || !acomp->ops || !acomp->ops->get_eld)
return -ENODEV;
port = pin2port(nid);
if (port < 0)
return -EINVAL;
return acomp->ops->get_eld(acomp->dev, port, audio_enabled,
buffer, max_bytes);
}
static int hdac_component_master_bind(struct device *dev)
{
struct i915_audio_component *acomp = hdac_acomp;
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
static void hdac_component_master_unbind(struct device *dev)
{
struct i915_audio_component *acomp = hdac_acomp;
module_put(acomp->ops->owner);
component_unbind_all(dev, acomp);
WARN_ON(acomp->ops || acomp->dev);
}
static int hdac_component_master_match(struct device *dev, void *data)
{
return !strcmp(dev->driver->name, "i915");
}
int snd_hdac_i915_register_notifier(const struct i915_audio_component_audio_ops *aops)
{
if (WARN_ON(!hdac_acomp))
return -ENODEV;
hdac_acomp->audio_ops = aops;
return 0;
}
static bool i915_gfx_present(void)
{
static struct pci_device_id ids[] = {
{ PCI_DEVICE(PCI_VENDOR_ID_INTEL, PCI_ANY_ID),
.class = PCI_BASE_CLASS_DISPLAY << 16,
.class_mask = 0xff << 16 },
{}
};
return pci_dev_present(ids);
}
int snd_hdac_i915_init(struct hdac_bus *bus)
{
struct component_match *match = NULL;
struct device *dev = bus->dev;
struct i915_audio_component *acomp;
int ret;
if (!i915_gfx_present())
return -ENODEV;
acomp = kzalloc(sizeof(*acomp), GFP_KERNEL);
if (!acomp)
return -ENOMEM;
bus->audio_component = acomp;
hdac_acomp = acomp;
component_match_add(dev, &match, hdac_component_master_match, bus);
ret = component_master_add_with_match(dev, &hdac_component_master_ops,
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
component_master_del(dev, &hdac_component_master_ops);
out_err:
kfree(acomp);
bus->audio_component = NULL;
dev_info(dev, "failed to add i915 component master (%d)\n", ret);
return ret;
}
int snd_hdac_i915_exit(struct hdac_bus *bus)
{
struct device *dev = bus->dev;
struct i915_audio_component *acomp = bus->audio_component;
if (!acomp)
return 0;
WARN_ON(bus->i915_power_refcount);
if (bus->i915_power_refcount > 0 && acomp->ops)
acomp->ops->put_power(acomp->dev);
component_master_del(dev, &hdac_component_master_ops);
kfree(acomp);
bus->audio_component = NULL;
return 0;
}
