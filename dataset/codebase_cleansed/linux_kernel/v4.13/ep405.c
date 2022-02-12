static int __init ep405_device_probe(void)
{
of_platform_bus_probe(NULL, ep405_of_bus, NULL);
return 0;
}
static void __init ep405_init_bcsr(void)
{
const u8 *irq_routing;
int i;
bcsr_node = of_find_compatible_node(NULL, NULL, "ep405-bcsr");
if (bcsr_node == NULL) {
printk(KERN_ERR "EP405 BCSR not found !\n");
return;
}
bcsr_regs = of_iomap(bcsr_node, 0);
if (bcsr_regs == NULL) {
printk(KERN_ERR "EP405 BCSR failed to map !\n");
return;
}
irq_routing = of_get_property(bcsr_node, "irq-routing", NULL);
if (irq_routing == NULL)
return;
for (i = 0; i < 16; i++) {
u8 irq = irq_routing[i];
out_8(bcsr_regs + BCSR_XIRQ_SELECT, i);
out_8(bcsr_regs + BCSR_XIRQ_ROUTING, irq);
}
in_8(bcsr_regs + BCSR_XIRQ_SELECT);
mb();
out_8(bcsr_regs + BCSR_GPIO_IRQ_PAR_CTRL, 0xfe);
}
static void __init ep405_setup_arch(void)
{
ep405_init_bcsr();
pci_set_flags(PCI_REASSIGN_ALL_RSRC);
}
static int __init ep405_probe(void)
{
if (!of_machine_is_compatible("ep405"))
return 0;
return 1;
}
