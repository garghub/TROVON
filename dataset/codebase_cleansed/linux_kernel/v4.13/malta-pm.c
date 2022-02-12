int mips_pm_suspend(unsigned state)
{
int spec_devid;
u16 sts;
if (!pm_pci_bus || !pm_io_offset)
return -ENODEV;
while (1) {
sts = inw(pm_io_offset + PIIX4_FUNC3IO_PMSTS);
if (!(sts & PIIX4_FUNC3IO_PMSTS_PWRBTN_STS))
break;
outw(sts, pm_io_offset + PIIX4_FUNC3IO_PMSTS);
}
outw(state | PIIX4_FUNC3IO_PMCNTRL_SUS_EN,
pm_io_offset + PIIX4_FUNC3IO_PMCNTRL);
mdelay(10);
spec_devid = PCI_DEVID(0, PCI_DEVFN(0x1f, 0x7));
pci_bus_write_config_dword(pm_pci_bus, spec_devid, 0,
PIIX4_SUSPEND_MAGIC);
mdelay(1000);
return 0;
}
static int __init malta_pm_setup(void)
{
struct pci_dev *dev;
int res, io_region = PCI_BRIDGE_RESOURCES;
pm_pci_bus = pci_find_next_bus(NULL);
if (!pm_pci_bus) {
pr_warn("malta-pm: failed to find reference to PCI bus\n");
return -ENODEV;
}
dev = pci_get_subsys(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82371AB_3, PCI_ANY_ID,
PCI_ANY_ID, NULL);
if (!dev) {
pr_warn("malta-pm: failed to find PIIX4 PM\n");
return -ENODEV;
}
res = pci_request_region(dev, io_region, "PIIX4 PM IO registers");
if (res) {
pr_warn("malta-pm: failed to request PM IO registers (%d)\n",
res);
pci_dev_put(dev);
return -ENODEV;
}
pm_io_offset = pci_resource_start(dev, io_region);
pci_dev_put(dev);
return 0;
}
