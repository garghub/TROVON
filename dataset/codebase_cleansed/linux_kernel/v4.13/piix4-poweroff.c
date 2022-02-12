static void piix4_poweroff(void)
{
int spec_devid;
u16 sts;
while (1) {
sts = inw(io_offset + PIIX4_FUNC3IO_PMSTS);
if (!(sts & PIIX4_FUNC3IO_PMSTS_PWRBTN_STS))
break;
outw(sts, io_offset + PIIX4_FUNC3IO_PMSTS);
}
outw(PIIX4_FUNC3IO_PMCNTRL_SUS_TYP_SOFF | PIIX4_FUNC3IO_PMCNTRL_SUS_EN,
io_offset + PIIX4_FUNC3IO_PMCNTRL);
mdelay(10);
spec_devid = PCI_DEVID(0, PCI_DEVFN(0x1f, 0x7));
pci_bus_write_config_dword(pm_dev->bus, spec_devid, 0,
PIIX4_SUSPEND_MAGIC);
mdelay(1000);
pr_emerg("Unable to poweroff system\n");
}
static int piix4_poweroff_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
int res;
if (pm_dev)
return -EINVAL;
res = pci_request_region(dev, piix4_pm_io_region,
"PIIX4 PM IO registers");
if (res) {
dev_err(&dev->dev, "failed to request PM IO registers: %d\n",
res);
return res;
}
pm_dev = dev;
io_offset = pci_resource_start(dev, piix4_pm_io_region);
pm_power_off = piix4_poweroff;
return 0;
}
static void piix4_poweroff_remove(struct pci_dev *dev)
{
if (pm_power_off == piix4_poweroff)
pm_power_off = NULL;
pci_release_region(dev, piix4_pm_io_region);
pm_dev = NULL;
}
