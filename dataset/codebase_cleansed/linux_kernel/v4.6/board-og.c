static int og_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
if (machine_is_im4004() && (slot == 8))
return KS8695_IRQ_EXTERN1;
return KS8695_IRQ_EXTERN0;
}
static void __init og_register_pci(void)
{
ks8695_gpio_interrupt(KS8695_GPIO_0, IRQ_TYPE_LEVEL_LOW);
if (machine_is_im4004())
ks8695_gpio_interrupt(KS8695_GPIO_1, IRQ_TYPE_LEVEL_LOW);
if (IS_ENABLED(CONFIG_PCI))
ks8695_init_pci(&og_pci);
}
static void __init og_pci_bus_reset(void)
{
unsigned int rstline = 1;
if (machine_is_im4004())
rstline = 2;
else if (machine_is_im42xx())
rstline = 0;
gpio_request(rstline, "PCI reset");
gpio_direction_output(rstline, 0);
gpio_set_value(rstline, 1);
gpio_set_value(rstline, 0);
mdelay(100);
gpio_set_value(rstline, 1);
mdelay(100);
}
static void __init og_init(void)
{
ks8695_register_gpios();
if (machine_is_cm4002()) {
ks8695_gpio_interrupt(KS8695_GPIO_1, IRQ_TYPE_LEVEL_HIGH);
iotable_init(og_io_desc, ARRAY_SIZE(og_io_desc));
platform_add_devices(og_devices, ARRAY_SIZE(og_devices));
} else {
og_pci_bus_reset();
og_register_pci();
}
ks8695_add_device_lan();
ks8695_add_device_wan();
}
