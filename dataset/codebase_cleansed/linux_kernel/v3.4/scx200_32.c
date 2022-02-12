static void __devinit scx200_init_shadow(void)
{
int bank;
for (bank = 0; bank < 2; ++bank)
scx200_gpio_shadow[bank] = inl(scx200_gpio_base + 0x10 * bank);
}
static int __devinit scx200_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
unsigned base;
if (pdev->device == PCI_DEVICE_ID_NS_SCx200_BRIDGE ||
pdev->device == PCI_DEVICE_ID_NS_SC1100_BRIDGE) {
base = pci_resource_start(pdev, 0);
pr_info("GPIO base 0x%x\n", base);
if (!request_region(base, SCx200_GPIO_SIZE,
"NatSemi SCx200 GPIO")) {
pr_err("can't allocate I/O for GPIOs\n");
return -EBUSY;
}
scx200_gpio_base = base;
scx200_init_shadow();
} else {
if (scx200_cb_probe(SCx200_CB_BASE_FIXED)) {
scx200_cb_base = SCx200_CB_BASE_FIXED;
} else {
pci_read_config_dword(pdev, SCx200_CBA_SCRATCH, &base);
if (scx200_cb_probe(base)) {
scx200_cb_base = base;
} else {
pr_warn("Configuration Block not found\n");
return -ENODEV;
}
}
pr_info("Configuration Block base 0x%x\n", scx200_cb_base);
}
return 0;
}
u32 scx200_gpio_configure(unsigned index, u32 mask, u32 bits)
{
u32 config, new_config;
mutex_lock(&scx200_gpio_config_lock);
outl(index, scx200_gpio_base + 0x20);
config = inl(scx200_gpio_base + 0x24);
new_config = (config & mask) | bits;
outl(new_config, scx200_gpio_base + 0x24);
mutex_unlock(&scx200_gpio_config_lock);
return config;
}
static int __init scx200_init(void)
{
pr_info("NatSemi SCx200 Driver\n");
return pci_register_driver(&scx200_pci_driver);
}
static void __exit scx200_cleanup(void)
{
pci_unregister_driver(&scx200_pci_driver);
release_region(scx200_gpio_base, SCx200_GPIO_SIZE);
}
