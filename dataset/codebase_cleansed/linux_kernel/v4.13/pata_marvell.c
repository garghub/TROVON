static int marvell_pata_active(struct pci_dev *pdev)
{
int i;
u32 devices;
void __iomem *barp;
if (pdev->device != 0x6145)
return 1;
barp = pci_iomap(pdev, 5, 0x10);
if (barp == NULL)
return -ENOMEM;
printk("BAR5:");
for(i = 0; i <= 0x0F; i++)
printk("%02X:%02X ", i, ioread8(barp + i));
printk("\n");
devices = ioread32(barp + 0x0C);
pci_iounmap(pdev, barp);
if (devices & 0x10)
return 1;
return 0;
}
static int marvell_pre_reset(struct ata_link *link, unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
if (pdev->device == 0x6145 && ap->port_no == 0 &&
!marvell_pata_active(pdev))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static int marvell_cable_detect(struct ata_port *ap)
{
switch(ap->port_no)
{
case 0:
if (ioread8(ap->ioaddr.bmdma_addr + 1) & 1)
return ATA_CBL_PATA40;
return ATA_CBL_PATA80;
case 1:
return ATA_CBL_SATA;
}
BUG();
return 0;
}
static int marvell_init_one (struct pci_dev *pdev, const struct pci_device_id *id)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &marvell_ops,
};
static const struct ata_port_info info_sata = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &marvell_ops,
};
const struct ata_port_info *ppi[] = { &info, &info_sata };
if (pdev->device == 0x6101)
ppi[1] = &ata_dummy_port_info;
#if IS_ENABLED(CONFIG_SATA_AHCI)
if (!marvell_pata_active(pdev)) {
printk(KERN_INFO DRV_NAME ": PATA port not active, deferring to AHCI driver.\n");
return -ENODEV;
}
#endif
return ata_pci_bmdma_init_one(pdev, ppi, &marvell_sht, NULL, 0);
}
