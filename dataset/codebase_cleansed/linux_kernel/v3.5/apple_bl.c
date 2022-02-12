static void intel_chipset_set_brightness(int intensity)
{
outb(0x04 | (intensity << 4), 0xb3);
outb(0xbf, 0xb2);
}
static int intel_chipset_send_intensity(struct backlight_device *bd)
{
int intensity = bd->props.brightness;
if (debug)
pr_debug("setting brightness to %d\n", intensity);
intel_chipset_set_brightness(intensity);
return 0;
}
static int intel_chipset_get_intensity(struct backlight_device *bd)
{
int intensity;
outb(0x03, 0xb3);
outb(0xbf, 0xb2);
intensity = inb(0xb3) >> 4;
if (debug)
pr_debug("read brightness of %d\n", intensity);
return intensity;
}
static void nvidia_chipset_set_brightness(int intensity)
{
outb(0x04 | (intensity << 4), 0x52f);
outb(0xbf, 0x52e);
}
static int nvidia_chipset_send_intensity(struct backlight_device *bd)
{
int intensity = bd->props.brightness;
if (debug)
pr_debug("setting brightness to %d\n", intensity);
nvidia_chipset_set_brightness(intensity);
return 0;
}
static int nvidia_chipset_get_intensity(struct backlight_device *bd)
{
int intensity;
outb(0x03, 0x52f);
outb(0xbf, 0x52e);
intensity = inb(0x52f) >> 4;
if (debug)
pr_debug("read brightness of %d\n", intensity);
return intensity;
}
static int __devinit apple_bl_add(struct acpi_device *dev)
{
struct backlight_properties props;
struct pci_dev *host;
int intensity;
host = pci_get_bus_and_slot(0, 0);
if (!host) {
pr_err("unable to find PCI host\n");
return -ENODEV;
}
if (host->vendor == PCI_VENDOR_ID_INTEL)
hw_data = &intel_chipset_data;
else if (host->vendor == PCI_VENDOR_ID_NVIDIA)
hw_data = &nvidia_chipset_data;
pci_dev_put(host);
if (!hw_data) {
pr_err("unknown hardware\n");
return -ENODEV;
}
intensity = hw_data->backlight_ops.get_brightness(NULL);
if (!intensity) {
hw_data->set_brightness(1);
if (!hw_data->backlight_ops.get_brightness(NULL))
return -ENODEV;
hw_data->set_brightness(0);
}
if (!request_region(hw_data->iostart, hw_data->iolen,
"Apple backlight"))
return -ENXIO;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = 15;
apple_backlight_device = backlight_device_register("apple_backlight",
NULL, NULL, &hw_data->backlight_ops, &props);
if (IS_ERR(apple_backlight_device)) {
release_region(hw_data->iostart, hw_data->iolen);
return PTR_ERR(apple_backlight_device);
}
apple_backlight_device->props.brightness =
hw_data->backlight_ops.get_brightness(apple_backlight_device);
backlight_update_status(apple_backlight_device);
return 0;
}
static int __devexit apple_bl_remove(struct acpi_device *dev, int type)
{
backlight_device_unregister(apple_backlight_device);
release_region(hw_data->iostart, hw_data->iolen);
hw_data = NULL;
return 0;
}
int apple_bl_register(void)
{
if (atomic_xchg(&apple_bl_registered, 1) == 0)
return acpi_bus_register_driver(&apple_bl_driver);
return 0;
}
void apple_bl_unregister(void)
{
if (atomic_xchg(&apple_bl_registered, 0) == 1)
acpi_bus_unregister_driver(&apple_bl_driver);
}
static int __init apple_bl_init(void)
{
return apple_bl_register();
}
static void __exit apple_bl_exit(void)
{
apple_bl_unregister();
}
