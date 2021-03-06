static void cmd640_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct cmd640_reg *timing = ap->private_data;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct ata_timing t;
const unsigned long T = 1000000 / 33;
const u8 setup_data[] = { 0x40, 0x40, 0x40, 0x80, 0x00 };
u8 reg;
int arttim = ARTIM0 + 2 * adev->devno;
struct ata_device *pair = ata_dev_pair(adev);
if (ata_timing_compute(adev, adev->pio_mode, &t, T, 0) < 0) {
printk(KERN_ERR DRV_NAME ": mode computation failed.\n");
return;
}
if (ap->port_no && pair) {
struct ata_timing p;
ata_timing_compute(pair, pair->pio_mode, &p, T, 1);
ata_timing_merge(&p, &t, &t, ATA_TIMING_SETUP);
}
if (t.recover > 16) {
t.active += t.recover - 16;
t.recover = 16;
}
if (t.active > 16)
t.active = 16;
if (t.recover > 1)
t.recover--;
else
t.recover = 15;
if (t.setup > 4)
t.setup = 0xC0;
else
t.setup = setup_data[t.setup];
if (ap->port_no == 0) {
t.active &= 0x0F;
pci_read_config_byte(pdev, arttim, &reg);
reg &= 0x3F;
reg |= t.setup;
pci_write_config_byte(pdev, arttim, reg);
pci_write_config_byte(pdev, arttim + 1, (t.active << 4) | t.recover);
} else {
pci_read_config_byte(pdev, ARTIM23, &reg);
reg &= 0x3F;
reg |= t.setup;
pci_write_config_byte(pdev, ARTIM23, reg);
timing->reg58[adev->devno] = (t.active << 4) | t.recover;
}
}
static unsigned int cmd640_qc_issue(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct ata_device *adev = qc->dev;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct cmd640_reg *timing = ap->private_data;
if (ap->port_no != 0 && adev->devno != timing->last) {
pci_write_config_byte(pdev, DRWTIM23, timing->reg58[adev->devno]);
timing->last = adev->devno;
}
return ata_sff_qc_issue(qc);
}
static int cmd640_port_start(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct cmd640_reg *timing;
timing = devm_kzalloc(&pdev->dev, sizeof(struct cmd640_reg), GFP_KERNEL);
if (timing == NULL)
return -ENOMEM;
timing->last = -1;
ap->private_data = timing;
return 0;
}
static bool cmd640_sff_irq_check(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
int irq_reg = ap->port_no ? ARTIM23 : CFR;
u8 irq_stat, irq_mask = ap->port_no ? 0x10 : 0x04;
pci_read_config_byte(pdev, irq_reg, &irq_stat);
return irq_stat & irq_mask;
}
static void cmd640_hardware_init(struct pci_dev *pdev)
{
u8 ctrl;
pci_write_config_byte(pdev, 0x5B, 0x00);
pci_write_config_byte(pdev, CMDTIM, 0);
pci_write_config_byte(pdev, BRST, 0x40);
pci_read_config_byte(pdev, CNTRL, &ctrl);
pci_write_config_byte(pdev, CNTRL, ctrl | 0xC0);
pci_read_config_byte(pdev, ARTIM23, &ctrl);
ctrl |= 0x0C;
pci_write_config_byte(pdev, ARTIM23, ctrl);
}
static int cmd640_init_one(struct pci_dev *pdev, const struct pci_device_id *id)
{
static const struct ata_port_info info = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.port_ops = &cmd640_port_ops
};
const struct ata_port_info *ppi[] = { &info, NULL };
int rc;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
cmd640_hardware_init(pdev);
return ata_pci_sff_init_one(pdev, ppi, &cmd640_sht, NULL, 0);
}
static int cmd640_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
cmd640_hardware_init(pdev);
ata_host_resume(host);
return 0;
}
static int __init cmd640_init(void)
{
return pci_register_driver(&cmd640_pci_driver);
}
static void __exit cmd640_exit(void)
{
pci_unregister_driver(&cmd640_pci_driver);
}
