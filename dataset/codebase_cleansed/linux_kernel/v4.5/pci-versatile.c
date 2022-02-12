static int __init versatile_pci_slot_ignore(char *str)
{
int retval;
int slot;
while ((retval = get_option(&str, &slot))) {
if ((slot < 0) || (slot > 31))
pr_err("Illegal slot value: %d\n", slot);
else
pci_slot_ignore |= (1 << slot);
}
return 1;
}
static void __iomem *versatile_map_bus(struct pci_bus *bus,
unsigned int devfn, int offset)
{
unsigned int busnr = bus->number;
if (pci_slot_ignore & (1 << PCI_SLOT(devfn)))
return NULL;
return versatile_cfg_base[1] + ((busnr << 16) | (devfn << 8) | offset);
}
static int versatile_pci_parse_request_of_pci_ranges(struct device *dev,
struct list_head *res)
{
int err, mem = 1, res_valid = 0;
struct device_node *np = dev->of_node;
resource_size_t iobase;
struct resource_entry *win;
err = of_pci_get_host_bridge_resources(np, 0, 0xff, res, &iobase);
if (err)
return err;
resource_list_for_each_entry(win, res) {
struct resource *parent, *res = win->res;
switch (resource_type(res)) {
case IORESOURCE_IO:
parent = &ioport_resource;
err = pci_remap_iospace(res, iobase);
if (err) {
dev_warn(dev, "error %d: failed to map resource %pR\n",
err, res);
continue;
}
break;
case IORESOURCE_MEM:
parent = &iomem_resource;
res_valid |= !(res->flags & IORESOURCE_PREFETCH);
writel(res->start >> 28, PCI_IMAP(mem));
writel(PHYS_OFFSET >> 28, PCI_SMAP(mem));
mem++;
break;
case IORESOURCE_BUS:
default:
continue;
}
err = devm_request_resource(dev, parent, res);
if (err)
goto out_release_res;
}
if (!res_valid) {
dev_err(dev, "non-prefetchable memory resource required\n");
err = -EINVAL;
goto out_release_res;
}
return 0;
out_release_res:
pci_free_resource_list(res);
return err;
}
static int versatile_pci_probe(struct platform_device *pdev)
{
struct resource *res;
int ret, i, myslot = -1;
u32 val;
void __iomem *local_pci_cfg_base;
struct pci_bus *bus;
LIST_HEAD(pci_res);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
versatile_pci_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(versatile_pci_base))
return PTR_ERR(versatile_pci_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
versatile_cfg_base[0] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(versatile_cfg_base[0]))
return PTR_ERR(versatile_cfg_base[0]);
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
versatile_cfg_base[1] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(versatile_cfg_base[1]))
return PTR_ERR(versatile_cfg_base[1]);
ret = versatile_pci_parse_request_of_pci_ranges(&pdev->dev, &pci_res);
if (ret)
return ret;
for (i = 0; i < 32; i++) {
if ((readl(versatile_cfg_base[0] + (i << 11) + PCI_VENDOR_ID) == VP_PCI_DEVICE_ID) &&
(readl(versatile_cfg_base[0] + (i << 11) + PCI_CLASS_REVISION) == VP_PCI_CLASS_ID)) {
myslot = i;
break;
}
}
if (myslot == -1) {
dev_err(&pdev->dev, "Cannot find PCI core!\n");
return -EIO;
}
pci_slot_ignore |= (1 << myslot);
dev_info(&pdev->dev, "PCI core found (slot %d)\n", myslot);
writel(myslot, PCI_SELFID);
local_pci_cfg_base = versatile_cfg_base[1] + (myslot << 11);
val = readl(local_pci_cfg_base + PCI_COMMAND);
val |= PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER | PCI_COMMAND_INVALIDATE;
writel(val, local_pci_cfg_base + PCI_COMMAND);
writel(PHYS_OFFSET, local_pci_cfg_base + PCI_BASE_ADDRESS_0);
writel(PHYS_OFFSET, local_pci_cfg_base + PCI_BASE_ADDRESS_1);
writel(PHYS_OFFSET, local_pci_cfg_base + PCI_BASE_ADDRESS_2);
writel(0, versatile_cfg_base[0] + PCI_INTERRUPT_LINE);
pci_add_flags(PCI_ENABLE_PROC_DOMAINS);
pci_add_flags(PCI_REASSIGN_ALL_BUS | PCI_REASSIGN_ALL_RSRC);
bus = pci_scan_root_bus(&pdev->dev, 0, &pci_versatile_ops, NULL, &pci_res);
if (!bus)
return -ENOMEM;
pci_fixup_irqs(pci_common_swizzle, of_irq_parse_and_map_pci);
pci_assign_unassigned_bus_resources(bus);
pci_bus_add_devices(bus);
return 0;
}
