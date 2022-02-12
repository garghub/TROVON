static void hpt3x3_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u32 r1, r2;
int dn = 2 * ap->port_no + adev->devno;
pci_read_config_dword(pdev, 0x44, &r1);
pci_read_config_dword(pdev, 0x48, &r2);
r1 &= ~(7 << (3 * dn));
r1 |= (adev->pio_mode - XFER_PIO_0) << (3 * dn);
r2 &= ~(0x11 << dn);
pci_write_config_dword(pdev, 0x44, r1);
pci_write_config_dword(pdev, 0x48, r2);
}
static void hpt3x3_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u32 r1, r2;
int dn = 2 * ap->port_no + adev->devno;
int mode_num = adev->dma_mode & 0x0F;
pci_read_config_dword(pdev, 0x44, &r1);
pci_read_config_dword(pdev, 0x48, &r2);
r1 &= ~(7 << (3 * dn));
r1 |= (mode_num << (3 * dn));
r2 &= ~(0x11 << dn);
if (adev->dma_mode >= XFER_UDMA_0)
r2 |= (0x01 << dn);
else
r2 |= (0x10 << dn);
pci_write_config_dword(pdev, 0x44, r1);
pci_write_config_dword(pdev, 0x48, r2);
}
static void hpt3x3_freeze(struct ata_port *ap)
{
void __iomem *mmio = ap->ioaddr.bmdma_addr;
iowrite8(ioread8(mmio + ATA_DMA_CMD) & ~ ATA_DMA_START,
mmio + ATA_DMA_CMD);
ata_sff_dma_pause(ap);
ata_sff_freeze(ap);
}
static void hpt3x3_bmdma_setup(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
u8 r = ioread8(ap->ioaddr.bmdma_addr + ATA_DMA_STATUS);
r |= ATA_DMA_INTR | ATA_DMA_ERR;
iowrite8(r, ap->ioaddr.bmdma_addr + ATA_DMA_STATUS);
return ata_bmdma_setup(qc);
}
static int hpt3x3_atapi_dma(struct ata_queued_cmd *qc)
{
return 1;
}
static void hpt3x3_init_chipset(struct pci_dev *dev)
{
u16 cmd;
pci_write_config_word(dev, 0x80, 0x00);
pci_read_config_word(dev, PCI_COMMAND, &cmd);
if (cmd & PCI_COMMAND_MEMORY)
pci_write_config_byte(dev, PCI_LATENCY_TIMER, 0xF0);
else
pci_write_config_byte(dev, PCI_LATENCY_TIMER, 0x20);
}
static int hpt3x3_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
static int printed_version;
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
#if defined(CONFIG_PATA_HPT3X3_DMA)
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA2,
#endif
.port_ops = &hpt3x3_port_ops
};
static const u8 offset_cmd[2] = { 0x20, 0x28 };
static const u8 offset_ctl[2] = { 0x36, 0x3E };
const struct ata_port_info *ppi[] = { &info, NULL };
struct ata_host *host;
int i, rc;
void __iomem *base;
hpt3x3_init_chipset(pdev);
if (!printed_version++)
dev_printk(KERN_DEBUG, &pdev->dev, "version " DRV_VERSION "\n");
host = ata_host_alloc_pinfo(&pdev->dev, ppi, 2);
if (!host)
return -ENOMEM;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
rc = pcim_iomap_regions(pdev, 1 << 4, DRV_NAME);
if (rc == -EBUSY)
pcim_pin_device(pdev);
if (rc)
return rc;
host->iomap = pcim_iomap_table(pdev);
rc = pci_set_dma_mask(pdev, ATA_DMA_MASK);
if (rc)
return rc;
rc = pci_set_consistent_dma_mask(pdev, ATA_DMA_MASK);
if (rc)
return rc;
base = host->iomap[4];
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
struct ata_ioports *ioaddr = &ap->ioaddr;
ioaddr->cmd_addr = base + offset_cmd[i];
ioaddr->altstatus_addr =
ioaddr->ctl_addr = base + offset_ctl[i];
ioaddr->scr_addr = NULL;
ata_sff_std_ports(ioaddr);
ioaddr->bmdma_addr = base + 8 * i;
ata_port_pbar_desc(ap, 4, -1, "ioport");
ata_port_pbar_desc(ap, 4, offset_cmd[i], "cmd");
}
pci_set_master(pdev);
return ata_host_activate(host, pdev->irq, ata_bmdma_interrupt,
IRQF_SHARED, &hpt3x3_sht);
}
static int hpt3x3_reinit_one(struct pci_dev *dev)
{
struct ata_host *host = dev_get_drvdata(&dev->dev);
int rc;
rc = ata_pci_device_do_resume(dev);
if (rc)
return rc;
hpt3x3_init_chipset(dev);
ata_host_resume(host);
return 0;
}
static int __init hpt3x3_init(void)
{
return pci_register_driver(&hpt3x3_pci_driver);
}
static void __exit hpt3x3_exit(void)
{
pci_unregister_driver(&hpt3x3_pci_driver);
}
