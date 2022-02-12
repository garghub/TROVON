static int opti_pre_reset(struct ata_link *link, unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
static const struct pci_bits opti_enable_bits[] = {
{ 0x45, 1, 0x80, 0x00 },
{ 0x40, 1, 0x08, 0x00 }
};
if (!pci_test_config_bits(pdev, &opti_enable_bits[ap->port_no]))
return -ENOENT;
return ata_sff_prereset(link, deadline);
}
static void opti_write_reg(struct ata_port *ap, u8 val, int reg)
{
void __iomem *regio = ap->ioaddr.cmd_addr;
ioread16(regio + 1);
ioread16(regio + 1);
iowrite8(3, regio + 2);
iowrite8(val, regio + reg);
iowrite8(0x83, regio + 2);
}
static void opti_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct ata_device *pair = ata_dev_pair(adev);
int clock;
int pio = adev->pio_mode - XFER_PIO_0;
void __iomem *regio = ap->ioaddr.cmd_addr;
u8 addr;
static const u8 addr_timing[2][5] = {
{ 0x30, 0x20, 0x20, 0x10, 0x10 },
{ 0x20, 0x20, 0x10, 0x10, 0x10 }
};
static const u8 data_rec_timing[2][5] = {
{ 0x6B, 0x56, 0x42, 0x32, 0x31 },
{ 0x58, 0x44, 0x32, 0x22, 0x21 }
};
iowrite8(0xff, regio + 5);
clock = ioread16(regio + 5) & 1;
addr = addr_timing[clock][pio];
if (pair) {
u8 pair_addr = addr_timing[clock][pair->pio_mode - XFER_PIO_0];
if (pair_addr > addr)
addr = pair_addr;
}
opti_write_reg(ap, adev->devno, MISC_REG);
opti_write_reg(ap, data_rec_timing[clock][pio], READ_REG);
opti_write_reg(ap, data_rec_timing[clock][pio], WRITE_REG);
opti_write_reg(ap, addr, MISC_REG);
opti_write_reg(ap, 0x85, CNTRL_REG);
}
static int opti_init_one(struct pci_dev *dev, const struct pci_device_id *id)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.port_ops = &opti_port_ops
};
const struct ata_port_info *ppi[] = { &info, NULL };
ata_print_version_once(&dev->dev, DRV_VERSION);
return ata_pci_sff_init_one(dev, ppi, &opti_sht, NULL, 0);
}
