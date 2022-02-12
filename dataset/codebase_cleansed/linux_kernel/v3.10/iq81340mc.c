static int __init
iq81340mc_pcix_map_irq(const struct pci_dev *dev, u8 idsel, u8 pin)
{
switch (idsel) {
case 1:
switch (pin) {
case 1: return ATUX_INTB;
case 2: return ATUX_INTC;
case 3: return ATUX_INTD;
case 4: return ATUX_INTA;
default: return -1;
}
case 2:
switch (pin) {
case 1: return ATUX_INTC;
case 2: return ATUX_INTD;
case 3: return ATUX_INTC;
case 4: return ATUX_INTD;
default: return -1;
}
default: return -1;
}
}
static int __init iq81340mc_pci_init(void)
{
iop13xx_atu_select(&iq81340mc_pci);
pci_common_init(&iq81340mc_pci);
iop13xx_map_pci_memory();
return 0;
}
static void __init iq81340mc_init(void)
{
iop13xx_platform_init();
iq81340mc_pci_init();
iop13xx_add_tpmi_devices();
}
static void __init iq81340mc_timer_init(void)
{
unsigned long bus_freq = iop13xx_core_freq() / iop13xx_xsi_bus_ratio();
printk(KERN_DEBUG "%s: bus frequency: %lu\n", __func__, bus_freq);
iop_init_time(bus_freq);
}
