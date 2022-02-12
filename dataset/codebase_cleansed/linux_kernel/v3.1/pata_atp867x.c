static void atp867x_set_dmamode(struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct atp867x_priv *dp = ap->private_data;
u8 speed = adev->dma_mode;
u8 b;
u8 mode = speed - XFER_UDMA_0 + 1;
if (dp->pci66mhz && mode > ATP867X_IO_DMAMODE_UDMA_0 &&
(pdev->device == PCI_DEVICE_ID_ARTOP_ATP867B ||
mode < ATP867X_IO_DMAMODE_UDMA_5))
mode--;
b = ioread8(dp->dma_mode);
if (adev->devno & 1) {
b = (b & ~ATP867X_IO_DMAMODE_SLAVE_MASK) |
(mode << ATP867X_IO_DMAMODE_SLAVE_SHIFT);
} else {
b = (b & ~ATP867X_IO_DMAMODE_MSTR_MASK) |
(mode << ATP867X_IO_DMAMODE_MSTR_SHIFT);
}
iowrite8(b, dp->dma_mode);
}
static int atp867x_get_active_clocks_shifted(struct ata_port *ap,
unsigned int clk)
{
struct atp867x_priv *dp = ap->private_data;
unsigned char clocks = clk;
if (dp->pci66mhz)
clocks++;
switch (clocks) {
case 0:
clocks = 1;
break;
case 1 ... 6:
break;
default:
printk(KERN_WARNING "ATP867X: active %dclk is invalid. "
"Using 12clk.\n", clk);
case 9 ... 12:
clocks = 7;
break;
case 7:
case 8:
clocks = 0;
goto active_clock_shift_done;
}
active_clock_shift_done:
return clocks << ATP867X_IO_PIOSPD_ACTIVE_SHIFT;
}
static int atp867x_get_recover_clocks_shifted(unsigned int clk)
{
unsigned char clocks = clk;
switch (clocks) {
case 0:
clocks = 1;
break;
case 1 ... 11:
break;
case 13:
case 14:
--clocks;
break;
case 15:
break;
default:
printk(KERN_WARNING "ATP867X: recover %dclk is invalid. "
"Using default 12clk.\n", clk);
case 12:
clocks = 0;
break;
}
return clocks << ATP867X_IO_PIOSPD_RECOVER_SHIFT;
}
static void atp867x_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
struct ata_device *peer = ata_dev_pair(adev);
struct atp867x_priv *dp = ap->private_data;
u8 speed = adev->pio_mode;
struct ata_timing t, p;
int T, UT;
u8 b;
T = 1000000000 / 33333;
UT = T / 4;
ata_timing_compute(adev, speed, &t, T, UT);
if (peer && peer->pio_mode) {
ata_timing_compute(peer, peer->pio_mode, &p, T, UT);
ata_timing_merge(&p, &t, &t, ATA_TIMING_8BIT);
}
b = ioread8(dp->dma_mode);
if (adev->devno & 1)
b = (b & ~ATP867X_IO_DMAMODE_SLAVE_MASK);
else
b = (b & ~ATP867X_IO_DMAMODE_MSTR_MASK);
iowrite8(b, dp->dma_mode);
b = atp867x_get_active_clocks_shifted(ap, t.active) |
atp867x_get_recover_clocks_shifted(t.recover);
if (adev->devno & 1)
iowrite8(b, dp->slave_piospd);
else
iowrite8(b, dp->mstr_piospd);
b = atp867x_get_active_clocks_shifted(ap, t.act8b) |
atp867x_get_recover_clocks_shifted(t.rec8b);
iowrite8(b, dp->eightb_piospd);
}
static int atp867x_cable_override(struct pci_dev *pdev)
{
if (pdev->subsystem_vendor == PCI_VENDOR_ID_ARTOP &&
(pdev->subsystem_device == PCI_DEVICE_ID_ARTOP_ATP867A ||
pdev->subsystem_device == PCI_DEVICE_ID_ARTOP_ATP867B)) {
return 1;
}
return 0;
}
static int atp867x_cable_detect(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
if (atp867x_cable_override(pdev))
return ATA_CBL_PATA40_SHORT;
return ATA_CBL_PATA_UNK;
}
static void atp867x_check_res(struct pci_dev *pdev)
{
int i;
unsigned long start, len;
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
start = pci_resource_start(pdev, i);
len = pci_resource_len(pdev, i);
printk(KERN_DEBUG "ATP867X: resource start:len=%lx:%lx\n",
start, len);
}
}
static void atp867x_check_ports(struct ata_port *ap, int port)
{
struct ata_ioports *ioaddr = &ap->ioaddr;
struct atp867x_priv *dp = ap->private_data;
printk(KERN_DEBUG "ATP867X: port[%d] addresses\n"
" cmd_addr =0x%llx, 0x%llx\n"
" ctl_addr =0x%llx, 0x%llx\n"
" bmdma_addr =0x%llx, 0x%llx\n"
" data_addr =0x%llx\n"
" error_addr =0x%llx\n"
" feature_addr =0x%llx\n"
" nsect_addr =0x%llx\n"
" lbal_addr =0x%llx\n"
" lbam_addr =0x%llx\n"
" lbah_addr =0x%llx\n"
" device_addr =0x%llx\n"
" status_addr =0x%llx\n"
" command_addr =0x%llx\n"
" dp->dma_mode =0x%llx\n"
" dp->mstr_piospd =0x%llx\n"
" dp->slave_piospd =0x%llx\n"
" dp->eightb_piospd =0x%llx\n"
" dp->pci66mhz =0x%lx\n",
port,
(unsigned long long)ioaddr->cmd_addr,
(unsigned long long)ATP867X_IO_PORTBASE(ap, port),
(unsigned long long)ioaddr->ctl_addr,
(unsigned long long)ATP867X_IO_ALTSTATUS(ap, port),
(unsigned long long)ioaddr->bmdma_addr,
(unsigned long long)ATP867X_IO_DMABASE(ap, port),
(unsigned long long)ioaddr->data_addr,
(unsigned long long)ioaddr->error_addr,
(unsigned long long)ioaddr->feature_addr,
(unsigned long long)ioaddr->nsect_addr,
(unsigned long long)ioaddr->lbal_addr,
(unsigned long long)ioaddr->lbam_addr,
(unsigned long long)ioaddr->lbah_addr,
(unsigned long long)ioaddr->device_addr,
(unsigned long long)ioaddr->status_addr,
(unsigned long long)ioaddr->command_addr,
(unsigned long long)dp->dma_mode,
(unsigned long long)dp->mstr_piospd,
(unsigned long long)dp->slave_piospd,
(unsigned long long)dp->eightb_piospd,
(unsigned long)dp->pci66mhz);
}
static int atp867x_set_priv(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
struct atp867x_priv *dp;
int port = ap->port_no;
dp = ap->private_data =
devm_kzalloc(&pdev->dev, sizeof(*dp), GFP_KERNEL);
if (dp == NULL)
return -ENOMEM;
dp->dma_mode = ATP867X_IO_DMAMODE(ap, port);
dp->mstr_piospd = ATP867X_IO_MSTRPIOSPD(ap, port);
dp->slave_piospd = ATP867X_IO_SLAVPIOSPD(ap, port);
dp->eightb_piospd = ATP867X_IO_8BPIOSPD(ap, port);
dp->pci66mhz =
ioread8(ATP867X_SYS_INFO(ap)) & ATP867X_IO_SYS_INFO_66MHZ;
return 0;
}
static void atp867x_fixup(struct ata_host *host)
{
struct pci_dev *pdev = to_pci_dev(host->dev);
struct ata_port *ap = host->ports[0];
int i;
u8 v;
pci_read_config_byte(pdev, PCI_LATENCY_TIMER, &v);
if (v < 0x80) {
v = 0x80;
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, v);
printk(KERN_DEBUG "ATP867X: set latency timer of device %s"
" to %d\n", pci_name(pdev), v);
}
for (i = 0; i < ATP867X_NUM_PORTS; i++)
iowrite16(ATP867X_IO_PORTSPD_VAL, ATP867X_IO_PORTSPD(ap, i));
for (i = 0; i < ATP867X_NUM_PORTS; i++)
iowrite16(ATP867X_PREREAD_VAL, ATP867X_IO_PREREAD(ap, i));
v = ioread8(ATP867X_IOBASE(ap) + 0x28);
v &= 0xcf;
v |= 0xc0;
iowrite8(v, ATP867X_IOBASE(ap) + 0x28);
v = ioread8(ATP867X_SYS_INFO(ap));
v &= ATP867X_IO_SYS_MASK_RESERVED;
if (pdev->device == PCI_DEVICE_ID_ARTOP_ATP867B)
v |= ATP867X_IO_SYS_INFO_SLOW_UDMA5;
iowrite8(v, ATP867X_SYS_INFO(ap));
}
static int atp867x_ata_pci_sff_init_host(struct ata_host *host)
{
struct device *gdev = host->dev;
struct pci_dev *pdev = to_pci_dev(gdev);
unsigned int mask = 0;
int i, rc;
rc = pcim_iomap_regions(pdev, 1 << ATP867X_BAR_IOBASE, DRV_NAME);
if (rc == -EBUSY)
pcim_pin_device(pdev);
if (rc)
return rc;
host->iomap = pcim_iomap_table(pdev);
#ifdef ATP867X_DEBUG
atp867x_check_res(pdev);
for (i = 0; i < PCI_ROM_RESOURCE; i++)
printk(KERN_DEBUG "ATP867X: iomap[%d]=0x%llx\n", i,
(unsigned long long)(host->iomap[i]));
#endif
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
struct ata_ioports *ioaddr = &ap->ioaddr;
ioaddr->cmd_addr = ATP867X_IO_PORTBASE(ap, i);
ioaddr->ctl_addr = ioaddr->altstatus_addr
= ATP867X_IO_ALTSTATUS(ap, i);
ioaddr->bmdma_addr = ATP867X_IO_DMABASE(ap, i);
ata_sff_std_ports(ioaddr);
rc = atp867x_set_priv(ap);
if (rc)
return rc;
#ifdef ATP867X_DEBUG
atp867x_check_ports(ap, i);
#endif
ata_port_desc(ap, "cmd 0x%lx ctl 0x%lx",
(unsigned long)ioaddr->cmd_addr,
(unsigned long)ioaddr->ctl_addr);
ata_port_desc(ap, "bmdma 0x%lx",
(unsigned long)ioaddr->bmdma_addr);
mask |= 1 << i;
}
if (!mask) {
dev_err(gdev, "no available native port\n");
return -ENODEV;
}
atp867x_fixup(host);
rc = pci_set_dma_mask(pdev, ATA_DMA_MASK);
if (rc)
return rc;
rc = pci_set_consistent_dma_mask(pdev, ATA_DMA_MASK);
return rc;
}
static int atp867x_init_one(struct pci_dev *pdev,
const struct pci_device_id *id)
{
static const struct ata_port_info info_867x = {
.flags = ATA_FLAG_SLAVE_POSS,
.pio_mask = ATA_PIO4,
.udma_mask = ATA_UDMA6,
.port_ops = &atp867x_ops,
};
struct ata_host *host;
const struct ata_port_info *ppi[] = { &info_867x, NULL };
int rc;
ata_print_version_once(&pdev->dev, DRV_VERSION);
rc = pcim_enable_device(pdev);
if (rc)
return rc;
printk(KERN_INFO "ATP867X: ATP867 ATA UDMA133 controller (rev %02X)",
pdev->device);
host = ata_host_alloc_pinfo(&pdev->dev, ppi, ATP867X_NUM_PORTS);
if (!host) {
dev_err(&pdev->dev, "failed to allocate ATA host\n");
rc = -ENOMEM;
goto err_out;
}
rc = atp867x_ata_pci_sff_init_host(host);
if (rc) {
dev_err(&pdev->dev, "failed to init host\n");
goto err_out;
}
pci_set_master(pdev);
rc = ata_host_activate(host, pdev->irq, ata_bmdma_interrupt,
IRQF_SHARED, &atp867x_sht);
if (rc)
dev_err(&pdev->dev, "failed to activate host\n");
err_out:
return rc;
}
static int atp867x_reinit_one(struct pci_dev *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
atp867x_fixup(host);
ata_host_resume(host);
return 0;
}
static int __init atp867x_init(void)
{
return pci_register_driver(&atp867x_driver);
}
static void __exit atp867x_exit(void)
{
pci_unregister_driver(&atp867x_driver);
}
