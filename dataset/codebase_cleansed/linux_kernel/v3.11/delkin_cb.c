static int delkin_cb_init_chipset(struct pci_dev *dev)
{
unsigned long base = pci_resource_start(dev, 0);
int i;
outb(0x02, base + 0x1e);
inb(base + 0x17);
for (i = 0; i < sizeof(setup); ++i) {
if (setup[i])
outb(setup[i], base + i);
}
return 0;
}
static int delkin_cb_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct ide_host *host;
unsigned long base;
int rc;
struct ide_hw hw, *hws[] = { &hw };
rc = pci_enable_device(dev);
if (rc) {
printk(KERN_ERR "delkin_cb: pci_enable_device failed (%d)\n", rc);
return rc;
}
rc = pci_request_regions(dev, "delkin_cb");
if (rc) {
printk(KERN_ERR "delkin_cb: pci_request_regions failed (%d)\n", rc);
pci_disable_device(dev);
return rc;
}
base = pci_resource_start(dev, 0);
delkin_cb_init_chipset(dev);
memset(&hw, 0, sizeof(hw));
ide_std_init_ports(&hw, base + 0x10, base + 0x1e);
hw.irq = dev->irq;
hw.dev = &dev->dev;
rc = ide_host_add(&delkin_cb_port_info, hws, 1, &host);
if (rc)
goto out_disable;
pci_set_drvdata(dev, host);
return 0;
out_disable:
pci_release_regions(dev);
pci_disable_device(dev);
return rc;
}
static void
delkin_cb_remove (struct pci_dev *dev)
{
struct ide_host *host = pci_get_drvdata(dev);
ide_host_remove(host);
pci_release_regions(dev);
pci_disable_device(dev);
}
static int delkin_cb_suspend(struct pci_dev *dev, pm_message_t state)
{
pci_save_state(dev);
pci_disable_device(dev);
pci_set_power_state(dev, pci_choose_state(dev, state));
return 0;
}
static int delkin_cb_resume(struct pci_dev *dev)
{
struct ide_host *host = pci_get_drvdata(dev);
int rc;
pci_set_power_state(dev, PCI_D0);
rc = pci_enable_device(dev);
if (rc)
return rc;
pci_restore_state(dev);
pci_set_master(dev);
if (host->init_chipset)
host->init_chipset(dev);
return 0;
}
