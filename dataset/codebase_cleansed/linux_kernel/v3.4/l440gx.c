static void l440gx_set_vpp(struct map_info *map, int vpp)
{
unsigned long flags;
spin_lock_irqsave(&l440gx_vpp_lock, flags);
if (vpp) {
if (++l440gx_vpp_refcnt == 1)
outl(inl(VPP_PORT) | 1, VPP_PORT);
} else {
if (--l440gx_vpp_refcnt == 0)
outl(inl(VPP_PORT) & ~1, VPP_PORT);
}
spin_unlock_irqrestore(&l440gx_vpp_lock, flags);
}
static int __init init_l440gx(void)
{
struct pci_dev *dev, *pm_dev;
struct resource *pm_iobase;
__u16 word;
dev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82371AB_0, NULL);
pm_dev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82371AB_3, NULL);
pci_dev_put(dev);
if (!dev || !pm_dev) {
printk(KERN_NOTICE "L440GX flash mapping: failed to find PIIX4 ISA bridge, cannot continue\n");
pci_dev_put(pm_dev);
return -ENODEV;
}
l440gx_map.virt = ioremap_nocache(WINDOW_ADDR, WINDOW_SIZE);
if (!l440gx_map.virt) {
printk(KERN_WARNING "Failed to ioremap L440GX flash region\n");
pci_dev_put(pm_dev);
return -ENOMEM;
}
simple_map_init(&l440gx_map);
printk(KERN_NOTICE "window_addr = 0x%08lx\n", (unsigned long)l440gx_map.virt);
pm_iobase = &pm_dev->resource[PIIXE_IOBASE_RESOURCE];
if (!(pm_iobase->flags & IORESOURCE_IO)) {
pm_iobase->name = "pm iobase";
pm_iobase->start = 0;
pm_iobase->end = 63;
pm_iobase->flags = IORESOURCE_IO;
pci_read_config_dword(pm_dev, 0x40, &iobase);
iobase &= ~1;
pm_iobase->start += iobase & ~1;
pm_iobase->end += iobase & ~1;
pci_dev_put(pm_dev);
if (pci_assign_resource(pm_dev, PIIXE_IOBASE_RESOURCE) != 0) {
pci_dev_put(dev);
pci_dev_put(pm_dev);
printk(KERN_WARNING "Could not allocate pm iobase resource\n");
iounmap(l440gx_map.virt);
return -ENXIO;
}
}
iobase = pm_iobase->start;
pci_write_config_dword(pm_dev, 0x40, iobase | 1);
pci_read_config_word(dev, 0x4e, &word);
word |= 0x4;
pci_write_config_word(dev, 0x4e, word);
l440gx_set_vpp(&l440gx_map, 1);
outb(inb(TRIBUF_PORT) & ~1, TRIBUF_PORT);
printk(KERN_NOTICE "Enabled WE line to L440GX BIOS flash chip.\n");
mymtd = do_map_probe("jedec_probe", &l440gx_map);
if (!mymtd) {
printk(KERN_NOTICE "JEDEC probe on BIOS chip failed. Using ROM\n");
mymtd = do_map_probe("map_rom", &l440gx_map);
}
if (mymtd) {
mymtd->owner = THIS_MODULE;
mtd_device_register(mymtd, NULL, 0);
return 0;
}
iounmap(l440gx_map.virt);
return -ENXIO;
}
static void __exit cleanup_l440gx(void)
{
mtd_device_unregister(mymtd);
map_destroy(mymtd);
iounmap(l440gx_map.virt);
}
