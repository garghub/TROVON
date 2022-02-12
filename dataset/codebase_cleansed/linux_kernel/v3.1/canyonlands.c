static int __init ppc460ex_device_probe(void)
{
of_platform_bus_probe(NULL, ppc460ex_of_bus, NULL);
return 0;
}
static int __init ppc460ex_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "amcc,canyonlands")) {
pci_set_flags(PCI_REASSIGN_ALL_RSRC);
return 1;
}
return 0;
}
static int __init ppc460ex_canyonlands_fixup(void)
{
u8 __iomem *bcsr ;
void __iomem *vaddr;
struct device_node *np;
int ret = 0;
np = of_find_compatible_node(NULL, NULL, "amcc,ppc460ex-bcsr");
if (!np) {
printk(KERN_ERR "failed did not find amcc, ppc460ex bcsr node\n");
return -ENODEV;
}
bcsr = of_iomap(np, 0);
of_node_put(np);
if (!bcsr) {
printk(KERN_CRIT "Could not remap bcsr\n");
ret = -ENODEV;
goto err_bcsr;
}
np = of_find_compatible_node(NULL, NULL, "ibm,ppc4xx-gpio");
if (!np) {
printk(KERN_ERR "failed did not find ibm,ppc4xx-gpio node\n");
return -ENODEV;
}
vaddr = of_iomap(np, 0);
of_node_put(np);
if (!vaddr) {
printk(KERN_CRIT "Could not get gpio node address\n");
ret = -ENODEV;
goto err_gpio;
}
setbits8(&bcsr[7], BCSR_USB_EN);
msleep(100);
clrbits8(&bcsr[7], BCSR_USB_EN);
setbits32((vaddr + GPIO0_OSRH), 0x42000000);
setbits32((vaddr + GPIO0_TSRH), 0x42000000);
err_gpio:
iounmap(vaddr);
err_bcsr:
iounmap(bcsr);
return ret;
}
