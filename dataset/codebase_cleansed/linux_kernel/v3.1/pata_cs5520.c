static void cs5520_set_timings(struct ata_port *ap, struct ata_device *adev, int pio)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int slave = adev->devno;
pio -= XFER_PIO_0;
pci_write_config_byte(pdev, 0x62 + ap->port_no,
(cs5520_pio_clocks[pio].recovery << 4) |
(cs5520_pio_clocks[pio].assert));
pci_write_config_byte(pdev, 0x64 + 4*ap->port_no + slave,
(cs5520_pio_clocks[pio].recovery << 4) |
(cs5520_pio_clocks[pio].assert));
pci_write_config_byte(pdev, 0x66 + 4*ap->port_no + slave,
(cs5520_pio_clocks[pio].recovery << 4) |
(cs5520_pio_clocks[pio].assert));
}
static void cs5520_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
cs5520_set_timings(ap, adev, adev->pio_mode);
}
static int __devinit cs5520_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
static const unsigned int cmd_port[] = { 0x1F0, 0x170 };
static const unsigned int ctl_port[] = { 0x3F6, 0x376 };
struct ata_port_info pi = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.port_ops = &cs5520_port_ops,
};
const struct ata_port_info *ppi[2];
u8 pcicfg;
void __iomem *iomap[5];
struct ata_host *host;
struct ata_ioports *ioaddr;
int i, rc;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
pci_read_config_byte(pdev, 0x60, &pcicfg);
if ((pcicfg & 3) == 0)
return -ENODEV;
ppi[0] = ppi[1] = &ata_dummy_port_info;
if (pcicfg & 1)
ppi[0] = &pi;
if (pcicfg & 2)
ppi[1] = &pi;
if ((pcicfg & 0x40) == 0) {
dev_warn(&pdev->dev, "DMA mode disabled. Enabling.\n");
pci_write_config_byte(pdev, 0x60, pcicfg | 0x40);
}
pi.mwdma_mask = id->driver_data;
host = ata_host_alloc_pinfo(&pdev->dev, ppi, 2);
if (!host)
return -ENOMEM;
if (pci_enable_device_io(pdev)) {
printk(KERN_ERR DRV_NAME ": unable to configure BAR2.\n");
return -ENODEV;
}
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
printk(KERN_ERR DRV_NAME ": unable to configure DMA mask.\n");
return -ENODEV;
}
if (pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32))) {
printk(KERN_ERR DRV_NAME ": unable to configure consistent DMA mask.\n");
return -ENODEV;
}
iomap[0] = devm_ioport_map(&pdev->dev, cmd_port[0], 8);
iomap[1] = devm_ioport_map(&pdev->dev, ctl_port[0], 1);
iomap[2] = devm_ioport_map(&pdev->dev, cmd_port[1], 8);
iomap[3] = devm_ioport_map(&pdev->dev, ctl_port[1], 1);
iomap[4] = pcim_iomap(pdev, 2, 0);
if (!iomap[0] || !iomap[1] || !iomap[2] || !iomap[3] || !iomap[4])
return -ENOMEM;
ioaddr = &host->ports[0]->ioaddr;
ioaddr->cmd_addr = iomap[0];
ioaddr->ctl_addr = iomap[1];
ioaddr->altstatus_addr = iomap[1];
ioaddr->bmdma_addr = iomap[4];
ata_sff_std_ports(ioaddr);
ata_port_desc(host->ports[0],
"cmd 0x%x ctl 0x%x", cmd_port[0], ctl_port[0]);
ata_port_pbar_desc(host->ports[0], 4, 0, "bmdma");
ioaddr = &host->ports[1]->ioaddr;
ioaddr->cmd_addr = iomap[2];
ioaddr->ctl_addr = iomap[3];
ioaddr->altstatus_addr = iomap[3];
ioaddr->bmdma_addr = iomap[4] + 8;
ata_sff_std_ports(ioaddr);
ata_port_desc(host->ports[1],
"cmd 0x%x ctl 0x%x", cmd_port[1], ctl_port[1]);
ata_port_pbar_desc(host->ports[1], 4, 8, "bmdma");
pci_set_master(pdev);
rc = ata_host_start(host);
if (rc)
return rc;
for (i = 0; i < 2; i++) {
static const int irq[] = { 14, 15 };
struct ata_port *ap = host->ports[i];
if (ata_port_is_dummy(ap))
continue;
rc = devm_request_irq(&pdev->dev, irq[ap->port_no],
ata_bmdma_interrupt, 0, DRV_NAME, host);
if (rc)
return rc;
ata_port_desc(ap, "irq %d", irq[i]);
}
return ata_host_register(host, &cs5520_sht);
}
static int cs5520_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
u8 pcicfg;
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
pci_read_config_byte(pdev, 0x60, &pcicfg);
if ((pcicfg & 0x40) == 0)
pci_write_config_byte(pdev, 0x60, pcicfg | 0x40);
ata_host_resume(host);
return 0;
}
static int cs5520_pci_device_suspend(struct pci_dev *pdev, pm_message_t mesg)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
int rc = 0;
rc = ata_host_suspend(host, mesg);
if (rc)
return rc;
pci_save_state(pdev);
return 0;
}
static int __init cs5520_init(void)
{
return pci_register_driver(&cs5520_pci_driver);
}
static void __exit cs5520_exit(void)
{
pci_unregister_driver(&cs5520_pci_driver);
}
