static int triflex_prereset(struct ata_link *link, unsigned long deadline)
{
static const struct pci_bits triflex_enable_bits[] = {
{ 0x80, 1, 0x01, 0x01 },
{ 0x80, 1, 0x02, 0x02 }
};
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
if (!pci_test_config_bits(pdev, &triflex_enable_bits[ap->port_no]))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static void triflex_load_timing(struct ata_port *ap, struct ata_device *adev, int speed)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u32 timing = 0;
u32 triflex_timing, old_triflex_timing;
int channel_offset = ap->port_no ? 0x74: 0x70;
unsigned int is_slave = (adev->devno != 0);
pci_read_config_dword(pdev, channel_offset, &old_triflex_timing);
triflex_timing = old_triflex_timing;
switch(speed)
{
case XFER_MW_DMA_2:
timing = 0x0103;break;
case XFER_MW_DMA_1:
timing = 0x0203;break;
case XFER_MW_DMA_0:
timing = 0x0808;break;
case XFER_SW_DMA_2:
case XFER_SW_DMA_1:
case XFER_SW_DMA_0:
timing = 0x0F0F;break;
case XFER_PIO_4:
timing = 0x0202;break;
case XFER_PIO_3:
timing = 0x0204;break;
case XFER_PIO_2:
timing = 0x0404;break;
case XFER_PIO_1:
timing = 0x0508;break;
case XFER_PIO_0:
timing = 0x0808;break;
default:
BUG();
}
triflex_timing &= ~ (0xFFFF << (16 * is_slave));
triflex_timing |= (timing << (16 * is_slave));
if (triflex_timing != old_triflex_timing)
pci_write_config_dword(pdev, channel_offset, triflex_timing);
}
static void triflex_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
triflex_load_timing(ap, adev, adev->pio_mode);
}
static void triflex_bmdma_start(struct ata_queued_cmd *qc)
{
triflex_load_timing(qc->ap, qc->dev, qc->dev->dma_mode);
ata_bmdma_start(qc);
}
static void triflex_bmdma_stop(struct ata_queued_cmd *qc)
{
ata_bmdma_stop(qc);
triflex_load_timing(qc->ap, qc->dev, qc->dev->pio_mode);
}
static int triflex_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &triflex_port_ops
};
const struct ata_port_info *ppi[] = { &info, NULL };
static int printed_version;
if (!printed_version++)
dev_printk(KERN_DEBUG, &dev->dev, "version " DRV_VERSION "\n");
return ata_pci_bmdma_init_one(dev, ppi, &triflex_sht, NULL, 0);
}
static int triflex_ata_pci_device_suspend(struct pci_dev *pdev, pm_message_t mesg)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
int rc = 0;
rc = ata_host_suspend(host, mesg);
if (rc)
return rc;
pci_save_state(pdev);
return 0;
}
static int __init triflex_init(void)
{
return pci_register_driver(&triflex_pci_driver);
}
static void __exit triflex_exit(void)
{
pci_unregister_driver(&triflex_pci_driver);
}
