static void it821x_program(struct ata_port *ap, struct ata_device *adev, u16 timing)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct it821x_dev *itdev = ap->private_data;
int channel = ap->port_no;
u8 conf;
if (itdev->clock_mode == ATA_66)
conf = timing >> 8;
else
conf = timing & 0xFF;
pci_write_config_byte(pdev, 0x54 + 4 * channel, conf);
}
static void it821x_program_udma(struct ata_port *ap, struct ata_device *adev, u16 timing)
{
struct it821x_dev *itdev = ap->private_data;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int channel = ap->port_no;
int unit = adev->devno;
u8 conf;
if (itdev->clock_mode == ATA_66)
conf = timing >> 8;
else
conf = timing & 0xFF;
if (itdev->timing10 == 0)
pci_write_config_byte(pdev, 0x56 + 4 * channel + unit, conf);
else {
pci_write_config_byte(pdev, 0x56 + 4 * channel, conf);
pci_write_config_byte(pdev, 0x56 + 4 * channel + 1, conf);
}
}
static void it821x_clock_strategy(struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct it821x_dev *itdev = ap->private_data;
u8 unit = adev->devno;
struct ata_device *pair = ata_dev_pair(adev);
int clock, altclock;
u8 v;
int sel = 0;
if (itdev->want[0][0] > itdev->want[1][0]) {
clock = itdev->want[0][1];
altclock = itdev->want[1][1];
} else {
clock = itdev->want[1][1];
altclock = itdev->want[0][1];
}
if (clock == ATA_ANY)
clock = altclock;
if (clock == ATA_ANY)
return;
if (clock == itdev->clock_mode)
return;
if (clock == ATA_66)
itdev->clock_mode = ATA_66;
else {
itdev->clock_mode = ATA_50;
sel = 1;
}
pci_read_config_byte(pdev, 0x50, &v);
v &= ~(1 << (1 + ap->port_no));
v |= sel << (1 + ap->port_no);
pci_write_config_byte(pdev, 0x50, v);
if (pair && itdev->udma[1-unit] != UDMA_OFF) {
it821x_program_udma(ap, pair, itdev->udma[1-unit]);
it821x_program(ap, pair, itdev->pio[1-unit]);
}
if (itdev->udma[unit] != UDMA_OFF) {
it821x_program_udma(ap, adev, itdev->udma[unit]);
it821x_program(ap, adev, itdev->pio[unit]);
}
}
static void it821x_passthru_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
static const u16 pio[] = { 0xAA88, 0xA382, 0xA181, 0x3332, 0x3121 };
static const u8 pio_want[] = { ATA_66, ATA_66, ATA_66, ATA_66, ATA_ANY };
struct it821x_dev *itdev = ap->private_data;
int unit = adev->devno;
int mode_wanted = adev->pio_mode - XFER_PIO_0;
itdev->want[unit][1] = pio_want[mode_wanted];
itdev->want[unit][0] = 1;
itdev->pio[unit] = pio[mode_wanted];
it821x_clock_strategy(ap, adev);
it821x_program(ap, adev, itdev->pio[unit]);
}
static void it821x_passthru_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
static const u16 dma[] = { 0x8866, 0x3222, 0x3121 };
static const u8 mwdma_want[] = { ATA_ANY, ATA_66, ATA_ANY };
static const u16 udma[] = { 0x4433, 0x4231, 0x3121, 0x2121, 0x1111, 0x2211, 0x1111 };
static const u8 udma_want[] = { ATA_ANY, ATA_50, ATA_ANY, ATA_66, ATA_66, ATA_50, ATA_66 };
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct it821x_dev *itdev = ap->private_data;
int channel = ap->port_no;
int unit = adev->devno;
u8 conf;
if (adev->dma_mode >= XFER_UDMA_0) {
int mode_wanted = adev->dma_mode - XFER_UDMA_0;
itdev->want[unit][1] = udma_want[mode_wanted];
itdev->want[unit][0] = 3;
itdev->mwdma[unit] = MWDMA_OFF;
itdev->udma[unit] = udma[mode_wanted];
if (mode_wanted >= 5)
itdev->udma[unit] |= 0x8080;
pci_read_config_byte(pdev, 0x50, &conf);
if (itdev->timing10)
conf &= channel ? 0x9F: 0xE7;
else
conf &= ~ (1 << (3 + 2 * channel + unit));
pci_write_config_byte(pdev, 0x50, conf);
it821x_clock_strategy(ap, adev);
it821x_program_udma(ap, adev, itdev->udma[unit]);
} else {
int mode_wanted = adev->dma_mode - XFER_MW_DMA_0;
itdev->want[unit][1] = mwdma_want[mode_wanted];
itdev->want[unit][0] = 2;
itdev->mwdma[unit] = dma[mode_wanted];
itdev->udma[unit] = UDMA_OFF;
pci_read_config_byte(pdev, 0x50, &conf);
if (itdev->timing10)
conf |= channel ? 0x60: 0x18;
else
conf |= 1 << (3 + 2 * channel + unit);
pci_write_config_byte(pdev, 0x50, conf);
it821x_clock_strategy(ap, adev);
}
}
static void it821x_passthru_bmdma_start(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ata_device *adev = qc->dev;
struct it821x_dev *itdev = ap->private_data;
int unit = adev->devno;
if (itdev->mwdma[unit] != MWDMA_OFF)
it821x_program(ap, adev, itdev->mwdma[unit]);
else if (itdev->udma[unit] != UDMA_OFF && itdev->timing10)
it821x_program_udma(ap, adev, itdev->udma[unit]);
ata_bmdma_start(qc);
}
static void it821x_passthru_bmdma_stop(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ata_device *adev = qc->dev;
struct it821x_dev *itdev = ap->private_data;
int unit = adev->devno;
ata_bmdma_stop(qc);
if (itdev->mwdma[unit] != MWDMA_OFF)
it821x_program(ap, adev, itdev->pio[unit]);
}
static void it821x_passthru_dev_select(struct ata_port *ap,
unsigned int device)
{
struct it821x_dev *itdev = ap->private_data;
if (itdev && device != itdev->last_device) {
struct ata_device *adev = &ap->link.device[device];
it821x_program(ap, adev, itdev->pio[adev->devno]);
itdev->last_device = device;
}
ata_sff_dev_select(ap, device);
}
static unsigned int it821x_smart_qc_issue(struct ata_queued_cmd *qc)
{
switch(qc->tf.command)
{
case ATA_CMD_READ:
case ATA_CMD_READ_EXT:
case ATA_CMD_WRITE:
case ATA_CMD_WRITE_EXT:
case ATA_CMD_PIO_READ:
case ATA_CMD_PIO_READ_EXT:
case ATA_CMD_PIO_WRITE:
case ATA_CMD_PIO_WRITE_EXT:
case ATA_CMD_READ_MULTI:
case ATA_CMD_READ_MULTI_EXT:
case ATA_CMD_WRITE_MULTI:
case ATA_CMD_WRITE_MULTI_EXT:
case ATA_CMD_ID_ATA:
case ATA_CMD_INIT_DEV_PARAMS:
case 0xFC:
case ATA_CMD_SET_FEATURES:
return ata_bmdma_qc_issue(qc);
}
printk(KERN_DEBUG "it821x: can't process command 0x%02X\n", qc->tf.command);
return AC_ERR_DEV;
}
static unsigned int it821x_passthru_qc_issue(struct ata_queued_cmd *qc)
{
it821x_passthru_dev_select(qc->ap, qc->dev->devno);
return ata_bmdma_qc_issue(qc);
}
static int it821x_smart_set_mode(struct ata_link *link, struct ata_device **unused)
{
struct ata_device *dev;
ata_for_each_dev(dev, link, ENABLED) {
dev->pio_mode = XFER_PIO_0;
dev->dma_mode = XFER_MW_DMA_0;
if (ata_id_has_dma(dev->id)) {
ata_dev_info(dev, "configured for DMA\n");
dev->xfer_mode = XFER_MW_DMA_0;
dev->xfer_shift = ATA_SHIFT_MWDMA;
dev->flags &= ~ATA_DFLAG_PIO;
} else {
ata_dev_info(dev, "configured for PIO\n");
dev->xfer_mode = XFER_PIO_0;
dev->xfer_shift = ATA_SHIFT_PIO;
dev->flags |= ATA_DFLAG_PIO;
}
}
return 0;
}
static void it821x_dev_config(struct ata_device *adev)
{
unsigned char model_num[ATA_ID_PROD_LEN + 1];
ata_id_c_string(adev->id, model_num, ATA_ID_PROD, sizeof(model_num));
if (adev->max_sectors > 255)
adev->max_sectors = 255;
if (strstr(model_num, "Integrated Technology Express")) {
ata_dev_info(adev, "%sRAID%d volume",
adev->id[147] ? "Bootable " : "",
adev->id[129]);
if (adev->id[129] != 1)
pr_cont("(%dK stripe)", adev->id[146]);
pr_cont("\n");
}
adev->horkage &= ~ATA_HORKAGE_DIAGNOSTIC;
adev->horkage |= ATA_HORKAGE_BROKEN_HPA;
}
static unsigned int it821x_read_id(struct ata_device *adev,
struct ata_taskfile *tf, u16 *id)
{
unsigned int err_mask;
unsigned char model_num[ATA_ID_PROD_LEN + 1];
err_mask = ata_do_dev_read_id(adev, tf, id);
if (err_mask)
return err_mask;
ata_id_c_string(id, model_num, ATA_ID_PROD, sizeof(model_num));
id[83] &= ~(1 << 12);
id[83] &= ~(1 << 13);
id[84] &= ~(1 << 6);
id[85] &= ~(1 << 10);
id[76] = 0;
if (strstr(model_num, "Integrated Technology Express")) {
id[49] |= 0x0300;
id[83] &= 0x7FFF;
id[83] |= 0x4400;
id[86] |= 0x0400;
id[ATA_ID_MAJOR_VER] |= 0x1F;
memset(&id[ATA_ID_SERNO], 0x20, ATA_ID_SERNO_LEN);
}
return err_mask;
}
static int it821x_check_atapi_dma(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct it821x_dev *itdev = ap->private_data;
if (ata_qc_raw_nbytes(qc) < 2048)
return -EOPNOTSUPP;
if (itdev->smart)
return -EOPNOTSUPP;
if (itdev->timing10)
return -EOPNOTSUPP;
return 0;
}
static void it821x_display_disk(int n, u8 *buf)
{
unsigned char id[41];
int mode = 0;
char *mtype = "";
char mbuf[8];
char *cbl = "(40 wire cable)";
static const char *types[5] = {
"RAID0", "RAID1", "RAID 0+1", "JBOD", "DISK"
};
if (buf[52] > 4)
return;
ata_id_c_string((u16 *)buf, id, 0, 41);
if (buf[51]) {
mode = ffs(buf[51]);
mtype = "UDMA";
} else if (buf[49]) {
mode = ffs(buf[49]);
mtype = "MWDMA";
}
if (buf[76])
cbl = "";
if (mode)
snprintf(mbuf, 8, "%5s%d", mtype, mode - 1);
else
strcpy(mbuf, "PIO");
if (buf[52] == 4)
printk(KERN_INFO "%d: %-6s %-8s %s %s\n",
n, mbuf, types[buf[52]], id, cbl);
else
printk(KERN_INFO "%d: %-6s %-8s Volume: %1d %s %s\n",
n, mbuf, types[buf[52]], buf[53], id, cbl);
if (buf[125] < 100)
printk(KERN_INFO "%d: Rebuilding: %d%%\n", n, buf[125]);
}
static u8 *it821x_firmware_command(struct ata_port *ap, u8 cmd, int len)
{
u8 status;
int n = 0;
u16 *buf = kmalloc(len, GFP_KERNEL);
if (buf == NULL) {
printk(KERN_ERR "it821x_firmware_command: Out of memory\n");
return NULL;
}
ap->ctl |= ATA_NIEN;
iowrite8(ap->ctl, ap->ioaddr.ctl_addr);
ata_wait_idle(ap);
iowrite8(ATA_DEVICE_OBS, ap->ioaddr.device_addr);
iowrite8(cmd, ap->ioaddr.command_addr);
udelay(1);
while(n++ < 10) {
status = ioread8(ap->ioaddr.status_addr);
if (status & ATA_ERR) {
kfree(buf);
printk(KERN_ERR "it821x_firmware_command: rejected\n");
return NULL;
}
if (status & ATA_DRQ) {
ioread16_rep(ap->ioaddr.data_addr, buf, len/2);
return (u8 *)buf;
}
mdelay(1);
}
kfree(buf);
printk(KERN_ERR "it821x_firmware_command: timeout\n");
return NULL;
}
static void it821x_probe_firmware(struct ata_port *ap)
{
u8 *buf;
int i;
buf = it821x_firmware_command(ap, 0xFA, 512);
if (buf != NULL) {
printk(KERN_INFO "pata_it821x: Firmware %02X/%02X/%02X%02X\n",
buf[505],
buf[506],
buf[507],
buf[508]);
for (i = 0; i < 4; i++)
it821x_display_disk(i, buf + 128 * i);
kfree(buf);
}
}
static int it821x_port_start(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct it821x_dev *itdev;
u8 conf;
int ret = ata_bmdma_port_start(ap);
if (ret < 0)
return ret;
itdev = devm_kzalloc(&pdev->dev, sizeof(struct it821x_dev), GFP_KERNEL);
if (itdev == NULL)
return -ENOMEM;
ap->private_data = itdev;
pci_read_config_byte(pdev, 0x50, &conf);
if (conf & 1) {
itdev->smart = 1;
if (ap->port_no == 0)
it821x_probe_firmware(ap);
}
if (conf & (1 << (1 + ap->port_no)))
itdev->clock_mode = ATA_50;
else
itdev->clock_mode = ATA_66;
itdev->want[0][1] = ATA_ANY;
itdev->want[1][1] = ATA_ANY;
itdev->last_device = -1;
if (pdev->revision == 0x10) {
itdev->timing10 = 1;
if (!itdev->smart)
printk(KERN_WARNING DRV_NAME": Revision 0x10, workarounds activated.\n");
}
return 0;
}
static int it821x_rdc_cable(struct ata_port *ap)
{
u16 r40;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
pci_read_config_word(pdev, 0x40, &r40);
if (r40 & (1 << (2 + ap->port_no)))
return ATA_CBL_PATA40;
return ATA_CBL_PATA80;
}
static void it821x_disable_raid(struct pci_dev *pdev)
{
if (pdev->vendor != PCI_VENDOR_ID_ITE ||
pdev->device != PCI_DEVICE_ID_ITE_8212)
return;
pci_write_config_byte(pdev, 0x5E, 0x01);
pci_write_config_byte(pdev, 0x50, 0x00);
pci_write_config_word(pdev, PCI_COMMAND,
PCI_COMMAND_PARITY | PCI_COMMAND_IO |
PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER);
pci_write_config_word(pdev, 0x40, 0xA0F3);
pci_write_config_dword(pdev,0x4C, 0x02040204);
pci_write_config_byte(pdev, 0x42, 0x36);
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 0x20);
}
static int it821x_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
u8 conf;
static const struct ata_port_info info_smart = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &it821x_smart_port_ops
};
static const struct ata_port_info info_passthru = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &it821x_passthru_port_ops
};
static const struct ata_port_info info_rdc = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.udma_mask = ATA_UDMA6,
.port_ops = &it821x_rdc_port_ops
};
static const struct ata_port_info info_rdc_11 = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.mwdma_mask = ATA_MWDMA2,
.port_ops = &it821x_rdc_port_ops
};
const struct ata_port_info *ppi[] = { NULL, NULL };
static char *mode[2] = { "pass through", "smart" };
int rc;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
if (pdev->vendor == PCI_VENDOR_ID_RDC) {
if (pdev->revision == 0x11)
ppi[0] = &info_rdc_11;
else
ppi[0] = &info_rdc;
} else {
if (it8212_noraid) {
printk(KERN_INFO DRV_NAME ": forcing bypass mode.\n");
it821x_disable_raid(pdev);
}
pci_read_config_byte(pdev, 0x50, &conf);
conf &= 1;
printk(KERN_INFO DRV_NAME": controller in %s mode.\n",
mode[conf]);
if (conf == 0)
ppi[0] = &info_passthru;
else
ppi[0] = &info_smart;
}
return ata_pci_bmdma_init_one(pdev, ppi, &it821x_sht, NULL, 0);
}
static int it821x_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
if (it8212_noraid)
it821x_disable_raid(pdev);
ata_host_resume(host);
return rc;
}
static int __init it821x_init(void)
{
return pci_register_driver(&it821x_pci_driver);
}
static void __exit it821x_exit(void)
{
pci_unregister_driver(&it821x_pci_driver);
}
