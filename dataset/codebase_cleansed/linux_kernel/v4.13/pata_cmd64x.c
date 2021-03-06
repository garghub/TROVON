static int cmd648_cable_detect(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u8 r;
pci_read_config_byte(pdev, BMIDECSR, &r);
if (r & (1 << ap->port_no))
return ATA_CBL_PATA80;
return ATA_CBL_PATA40;
}
static void cmd64x_set_timing(struct ata_port *ap, struct ata_device *adev, u8 mode)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct ata_timing t;
const unsigned long T = 1000000 / 33;
const u8 setup_data[] = { 0x40, 0x40, 0x40, 0x80, 0x00 };
u8 reg;
const u8 arttim_port[2][2] = {
{ ARTTIM0, ARTTIM1 },
{ ARTTIM23, ARTTIM23 }
};
const u8 drwtim_port[2][2] = {
{ DRWTIM0, DRWTIM1 },
{ DRWTIM2, DRWTIM3 }
};
int arttim = arttim_port[ap->port_no][adev->devno];
int drwtim = drwtim_port[ap->port_no][adev->devno];
if (ata_timing_compute(adev, mode, &t, T, 0) < 0) {
printk(KERN_ERR DRV_NAME ": mode computation failed.\n");
return;
}
if (ap->port_no) {
struct ata_device *pair = ata_dev_pair(adev);
if (pair) {
struct ata_timing tp;
ata_timing_compute(pair, pair->pio_mode, &tp, T, 0);
ata_timing_merge(&t, &tp, &t, ATA_TIMING_SETUP);
}
}
printk(KERN_DEBUG DRV_NAME ": active %d recovery %d setup %d.\n",
t.active, t.recover, t.setup);
if (t.recover > 16) {
t.active += t.recover - 16;
t.recover = 16;
}
if (t.active > 16)
t.active = 16;
if (t.recover == 16)
t.recover = 0;
else if (t.recover > 1)
t.recover--;
else
t.recover = 15;
if (t.setup > 4)
t.setup = 0xC0;
else
t.setup = setup_data[t.setup];
t.active &= 0x0F;
pci_read_config_byte(pdev, arttim, &reg);
reg &= 0x3F;
reg |= t.setup;
pci_write_config_byte(pdev, arttim, reg);
pci_write_config_byte(pdev, drwtim, (t.active << 4) | t.recover);
}
static void cmd64x_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
cmd64x_set_timing(ap, adev, adev->pio_mode);
}
static void cmd64x_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
static const u8 udma_data[] = {
0x30, 0x20, 0x10, 0x20, 0x10, 0x00
};
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u8 regU, regD;
int pciU = UDIDETCR0 + 8 * ap->port_no;
int pciD = BMIDESR0 + 8 * ap->port_no;
int shift = 2 * adev->devno;
pci_read_config_byte(pdev, pciD, &regD);
pci_read_config_byte(pdev, pciU, &regU);
regD &= ~(0x20 << adev->devno);
regU &= ~(0x30 << shift);
regU &= ~(0x05 << adev->devno);
if (adev->dma_mode >= XFER_UDMA_0) {
regU |= udma_data[adev->dma_mode - XFER_UDMA_0] << shift;
regU |= 1 << adev->devno;
if (adev->dma_mode > XFER_UDMA_2)
regU |= 4 << adev->devno;
} else {
regU &= ~ (1 << adev->devno);
cmd64x_set_timing(ap, adev, adev->dma_mode);
}
regD |= 0x20 << adev->devno;
pci_write_config_byte(pdev, pciU, regU);
pci_write_config_byte(pdev, pciD, regD);
}
static bool cmd64x_sff_irq_check(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int irq_mask = ap->port_no ? ARTTIM23_INTR_CH1 : CFR_INTR_CH0;
int irq_reg = ap->port_no ? ARTTIM23 : CFR;
u8 irq_stat;
pci_read_config_byte(pdev, irq_reg, &irq_stat);
return irq_stat & irq_mask;
}
static void cmd64x_sff_irq_clear(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int irq_reg = ap->port_no ? ARTTIM23 : CFR;
u8 irq_stat;
ata_bmdma_irq_clear(ap);
pci_read_config_byte(pdev, irq_reg, &irq_stat);
}
static bool cmd648_sff_irq_check(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
unsigned long base = pci_resource_start(pdev, 4);
int irq_mask = ap->port_no ? MRDMODE_INTR_CH1 : MRDMODE_INTR_CH0;
u8 mrdmode = inb(base + 1);
return mrdmode & irq_mask;
}
static void cmd648_sff_irq_clear(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
unsigned long base = pci_resource_start(pdev, 4);
int irq_mask = ap->port_no ? MRDMODE_INTR_CH1 : MRDMODE_INTR_CH0;
u8 mrdmode;
ata_bmdma_irq_clear(ap);
mrdmode = inb(base + 1);
mrdmode &= ~(MRDMODE_INTR_CH0 | MRDMODE_INTR_CH1);
outb(mrdmode | irq_mask, base + 1);
}
static void cmd646r1_bmdma_stop(struct ata_queued_cmd *qc)
{
ata_bmdma_stop(qc);
}
static void cmd64x_fixup(struct pci_dev *pdev)
{
u8 mrdmode;
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 64);
pci_read_config_byte(pdev, MRDMODE, &mrdmode);
mrdmode &= ~0x30;
mrdmode |= 0x02;
pci_write_config_byte(pdev, MRDMODE, mrdmode);
#ifdef CONFIG_PPC
pci_write_config_byte(pdev, UDIDETCR0, 0xF0);
#endif
}
static int cmd64x_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
static const struct ata_port_info cmd_info[7] = {
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &cmd64x_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &cmd64x_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &cmd646r3_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA2,
.port_ops = &cmd646r3_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &cmd646r1_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA4,
.port_ops = &cmd648_port_ops
},
{
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA5,
.port_ops = &cmd648_port_ops
}
};
const struct ata_port_info *ppi[] = {
&cmd_info[id->driver_data],
&cmd_info[id->driver_data],
NULL
};
u8 reg;
int rc;
struct pci_dev *bridge = pdev->bus->self;
int port_ok = !(bridge && bridge->vendor ==
PCI_VENDOR_ID_MOBILITY_ELECTRONICS);
int cntrl_ch0_ok = (id->driver_data != 0);
rc = pcim_enable_device(pdev);
if (rc)
return rc;
if (id->driver_data == 0)
ata_pci_bmdma_clear_simplex(pdev);
if (pdev->device == PCI_DEVICE_ID_CMD_646)
switch (pdev->revision) {
default:
ppi[0] = &cmd_info[3];
ppi[1] = &cmd_info[3];
break;
case 3:
case 4:
ppi[0] = &cmd_info[2];
ppi[1] = &cmd_info[2];
break;
case 1:
ppi[0] = &cmd_info[4];
ppi[1] = &cmd_info[4];
case 2:
case 0:
cntrl_ch0_ok = 0;
break;
}
cmd64x_fixup(pdev);
pci_read_config_byte(pdev, CNTRL, &reg);
if (!port_ok)
dev_notice(&pdev->dev, "Mobility Bridge detected, ignoring CNTRL port enable/disable\n");
if (port_ok && cntrl_ch0_ok && !(reg & CNTRL_CH0)) {
dev_notice(&pdev->dev, "Primary port is disabled\n");
ppi[0] = &ata_dummy_port_info;
}
if (port_ok && !(reg & CNTRL_CH1)) {
dev_notice(&pdev->dev, "Secondary port is disabled\n");
ppi[1] = &ata_dummy_port_info;
}
return ata_pci_bmdma_init_one(pdev, ppi, &cmd64x_sht, NULL, 0);
}
static int cmd64x_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = pci_get_drvdata(pdev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
cmd64x_fixup(pdev);
ata_host_resume(host);
return 0;
}
