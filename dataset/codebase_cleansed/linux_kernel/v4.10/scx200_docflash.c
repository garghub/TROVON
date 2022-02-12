static int __init init_scx200_docflash(void)
{
unsigned u;
unsigned base;
unsigned ctrl;
unsigned pmr;
struct pci_dev *bridge;
printk(KERN_DEBUG NAME ": NatSemi SCx200 DOCCS Flash Driver\n");
if ((bridge = pci_get_device(PCI_VENDOR_ID_NS,
PCI_DEVICE_ID_NS_SCx200_BRIDGE,
NULL)) == NULL)
return -ENODEV;
if (!scx200_cb_present()) {
pci_dev_put(bridge);
return -ENODEV;
}
if (probe) {
pci_read_config_dword(bridge, SCx200_DOCCS_BASE, &base);
pci_read_config_dword(bridge, SCx200_DOCCS_CTRL, &ctrl);
pci_dev_put(bridge);
pmr = inl(scx200_cb_base + SCx200_PMR);
if (base == 0
|| (ctrl & 0x07000000) != 0x07000000
|| (ctrl & 0x0007ffff) == 0)
return -ENODEV;
size = ((ctrl&0x1fff)<<13) + (1<<13);
for (u = size; u > 1; u >>= 1)
;
if (u != 1)
return -ENODEV;
if (pmr & (1<<6))
width = 16;
else
width = 8;
docmem.start = base;
docmem.end = base + size;
if (request_resource(&iomem_resource, &docmem)) {
printk(KERN_ERR NAME ": unable to allocate memory for flash mapping\n");
return -ENOMEM;
}
} else {
pci_dev_put(bridge);
for (u = size; u > 1; u >>= 1)
;
if (u != 1) {
printk(KERN_ERR NAME ": invalid size for flash mapping\n");
return -EINVAL;
}
if (width != 8 && width != 16) {
printk(KERN_ERR NAME ": invalid bus width for flash mapping\n");
return -EINVAL;
}
if (allocate_resource(&iomem_resource, &docmem,
size,
0xc0000000, 0xffffffff,
size, NULL, NULL)) {
printk(KERN_ERR NAME ": unable to allocate memory for flash mapping\n");
return -ENOMEM;
}
ctrl = 0x07000000 | ((size-1) >> 13);
printk(KERN_INFO "DOCCS BASE=0x%08lx, CTRL=0x%08lx\n", (long)docmem.start, (long)ctrl);
pci_write_config_dword(bridge, SCx200_DOCCS_BASE, docmem.start);
pci_write_config_dword(bridge, SCx200_DOCCS_CTRL, ctrl);
pmr = inl(scx200_cb_base + SCx200_PMR);
if (width == 8) {
pmr &= ~(1<<6);
} else {
pmr |= (1<<6);
}
outl(pmr, scx200_cb_base + SCx200_PMR);
}
printk(KERN_INFO NAME ": DOCCS mapped at %pR, width %d\n",
&docmem, width);
scx200_docflash_map.size = size;
if (width == 8)
scx200_docflash_map.bankwidth = 1;
else
scx200_docflash_map.bankwidth = 2;
simple_map_init(&scx200_docflash_map);
scx200_docflash_map.phys = docmem.start;
scx200_docflash_map.virt = ioremap(docmem.start, scx200_docflash_map.size);
if (!scx200_docflash_map.virt) {
printk(KERN_ERR NAME ": failed to ioremap the flash\n");
release_resource(&docmem);
return -EIO;
}
mymtd = do_map_probe(flashtype, &scx200_docflash_map);
if (!mymtd) {
printk(KERN_ERR NAME ": unable to detect flash\n");
iounmap(scx200_docflash_map.virt);
release_resource(&docmem);
return -ENXIO;
}
if (size < mymtd->size)
printk(KERN_WARNING NAME ": warning, flash mapping is smaller than flash size\n");
mymtd->owner = THIS_MODULE;
partition_info[3].offset = mymtd->size-partition_info[3].size;
partition_info[2].size = partition_info[3].offset-partition_info[2].offset;
mtd_device_register(mymtd, partition_info, NUM_PARTITIONS);
return 0;
}
static void __exit cleanup_scx200_docflash(void)
{
if (mymtd) {
mtd_device_unregister(mymtd);
map_destroy(mymtd);
}
if (scx200_docflash_map.virt) {
iounmap(scx200_docflash_map.virt);
release_resource(&docmem);
}
}
