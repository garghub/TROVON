static int ns87410_pre_reset(struct ata_link *link, unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
static const struct pci_bits ns87410_enable_bits[] = {
{ 0x43, 1, 0x08, 0x08 },
{ 0x47, 1, 0x08, 0x08 }
};
if (!pci_test_config_bits(pdev, &ns87410_enable_bits[ap->port_no]))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static void ns87410_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int port = 0x40 + 4 * ap->port_no;
u8 idetcr, idefr;
struct ata_timing at;
static const u8 activebits[15] = {
0, 1, 2, 3, 4,
5, 5, 6, 6, 6,
6, 7, 7, 7, 7
};
static const u8 recoverbits[12] = {
0, 1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 7
};
pci_read_config_byte(pdev, port + 3, &idefr);
if (ata_pio_need_iordy(adev))
idefr |= 0x04;
else
idefr &= ~0x04;
if (ata_timing_compute(adev, adev->pio_mode, &at, 30303, 1) < 0) {
dev_err(&pdev->dev, "unknown mode %d\n", adev->pio_mode);
return;
}
at.active = clamp_val(at.active, 2, 16) - 2;
at.setup = clamp_val(at.setup, 1, 4) - 1;
at.recover = clamp_val(at.recover, 1, 12) - 1;
idetcr = (at.setup << 6) | (recoverbits[at.recover] << 3) | activebits[at.active];
pci_write_config_byte(pdev, port, idetcr);
pci_write_config_byte(pdev, port + 3, idefr);
ap->private_data = adev;
}
static unsigned int ns87410_qc_issue(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ata_device *adev = qc->dev;
if (adev->pio_mode && adev != ap->private_data)
ns87410_set_piomode(ap, adev);
return ata_sff_qc_issue(qc);
}
static int ns87410_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO3,
.port_ops = &ns87410_port_ops
};
const struct ata_port_info *ppi[] = { &info, NULL };
return ata_pci_sff_init_one(dev, ppi, &ns87410_sht, NULL, 0);
}
static int __init ns87410_init(void)
{
return pci_register_driver(&ns87410_pci_driver);
}
static void __exit ns87410_exit(void)
{
pci_unregister_driver(&ns87410_pci_driver);
}
