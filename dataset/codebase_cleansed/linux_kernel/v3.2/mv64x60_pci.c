static ssize_t mv64x60_hs_reg_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
struct pci_dev *phb;
u32 v;
if (off > 0)
return 0;
if (count < MV64X60_VAL_LEN_MAX)
return -EINVAL;
phb = pci_get_bus_and_slot(0, PCI_DEVFN(0, 0));
if (!phb)
return -ENODEV;
pci_read_config_dword(phb, MV64X60_PCICFG_CPCI_HOTSWAP, &v);
pci_dev_put(phb);
return sprintf(buf, "0x%08x\n", v);
}
static ssize_t mv64x60_hs_reg_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
struct pci_dev *phb;
u32 v;
if (off > 0)
return 0;
if (count <= 0)
return -EINVAL;
if (sscanf(buf, "%i", &v) != 1)
return -EINVAL;
phb = pci_get_bus_and_slot(0, PCI_DEVFN(0, 0));
if (!phb)
return -ENODEV;
pci_write_config_dword(phb, MV64X60_PCICFG_CPCI_HOTSWAP, v);
pci_dev_put(phb);
return count;
}
static int __init mv64x60_sysfs_init(void)
{
struct device_node *np;
struct platform_device *pdev;
const unsigned int *prop;
np = of_find_compatible_node(NULL, NULL, "marvell,mv64360");
if (!np)
return 0;
prop = of_get_property(np, "hs_reg_valid", NULL);
of_node_put(np);
pdev = platform_device_register_simple("marvell,mv64360", 0, NULL, 0);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
return sysfs_create_bin_file(&pdev->dev.kobj, &mv64x60_hs_reg_attr);
}
static void __init mv64x60_pci_fixup_early(struct pci_dev *dev)
{
dev->hdr_type = PCI_HEADER_TYPE_INVALID;
}
static int __init mv64x60_add_bridge(struct device_node *dev)
{
int len;
struct pci_controller *hose;
struct resource rsrc;
const int *bus_range;
int primary;
memset(&rsrc, 0, sizeof(rsrc));
if (of_address_to_resource(dev, 0, &rsrc)) {
printk(KERN_ERR "No PCI reg property in device tree\n");
return -ENODEV;
}
bus_range = of_get_property(dev, "bus-range", &len);
if (bus_range == NULL || len < 2 * sizeof(int))
printk(KERN_WARNING "Can't get bus-range for %s, assume"
" bus 0\n", dev->full_name);
hose = pcibios_alloc_controller(dev);
if (!hose)
return -ENOMEM;
hose->first_busno = bus_range ? bus_range[0] : 0;
hose->last_busno = bus_range ? bus_range[1] : 0xff;
setup_indirect_pci(hose, rsrc.start, rsrc.start + 4, 0);
hose->self_busno = hose->first_busno;
printk(KERN_INFO "Found MV64x60 PCI host bridge at 0x%016llx. "
"Firmware bus number: %d->%d\n",
(unsigned long long)rsrc.start, hose->first_busno,
hose->last_busno);
primary = (hose->first_busno == 0);
pci_process_bridge_OF_ranges(hose, dev, primary);
return 0;
}
void __init mv64x60_pci_init(void)
{
struct device_node *np;
for_each_compatible_node(np, "pci", "marvell,mv64360-pci")
mv64x60_add_bridge(np);
}
