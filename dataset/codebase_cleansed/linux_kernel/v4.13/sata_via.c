static int svia_scr_read(struct ata_link *link, unsigned int sc_reg, u32 *val)
{
if (sc_reg > SCR_CONTROL)
return -EINVAL;
*val = ioread32(link->ap->ioaddr.scr_addr + (4 * sc_reg));
return 0;
}
static int svia_scr_write(struct ata_link *link, unsigned int sc_reg, u32 val)
{
if (sc_reg > SCR_CONTROL)
return -EINVAL;
iowrite32(val, link->ap->ioaddr.scr_addr + (4 * sc_reg));
return 0;
}
static int vt8251_scr_read(struct ata_link *link, unsigned int scr, u32 *val)
{
static const u8 ipm_tbl[] = { 1, 2, 6, 0 };
struct pci_dev *pdev = to_pci_dev(link->ap->host->dev);
int slot = 2 * link->ap->port_no + link->pmp;
u32 v = 0;
u8 raw;
switch (scr) {
case SCR_STATUS:
pci_read_config_byte(pdev, 0xA0 + slot, &raw);
v |= raw & 0x03;
if (raw & (1 << 4))
v |= 0x02 << 4;
else
v |= 0x01 << 4;
v |= ipm_tbl[(raw >> 2) & 0x3];
break;
case SCR_ERROR:
WARN_ON(pdev->device != 0x5287);
pci_read_config_dword(pdev, 0xB0 + slot * 4, &v);
break;
case SCR_CONTROL:
pci_read_config_byte(pdev, 0xA4 + slot, &raw);
v |= ((raw & 0x02) << 1) | (raw & 0x01);
v |= ((raw >> 2) & 0x03) << 8;
break;
default:
return -EINVAL;
}
*val = v;
return 0;
}
static int vt8251_scr_write(struct ata_link *link, unsigned int scr, u32 val)
{
struct pci_dev *pdev = to_pci_dev(link->ap->host->dev);
int slot = 2 * link->ap->port_no + link->pmp;
u32 v = 0;
switch (scr) {
case SCR_ERROR:
WARN_ON(pdev->device != 0x5287);
pci_write_config_dword(pdev, 0xB0 + slot * 4, val);
return 0;
case SCR_CONTROL:
v |= ((val & 0x4) >> 1) | (val & 0x1);
v |= ((val >> 8) & 0x3) << 2;
pci_write_config_byte(pdev, 0xA4 + slot, v);
return 0;
default:
return -EINVAL;
}
}
static void svia_tf_load(struct ata_port *ap, const struct ata_taskfile *tf)
{
struct ata_taskfile ttf;
if (tf->ctl != ap->last_ctl) {
ttf = *tf;
ttf.flags |= ATA_TFLAG_DEVICE;
tf = &ttf;
}
ata_sff_tf_load(ap, tf);
}
static void svia_noop_freeze(struct ata_port *ap)
{
ap->ops->sff_check_status(ap);
ata_bmdma_irq_clear(ap);
}
static int vt6420_prereset(struct ata_link *link, unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct ata_eh_context *ehc = &ap->link.eh_context;
unsigned long timeout = jiffies + (HZ * 5);
u32 sstatus, scontrol;
int online;
if (!(ap->pflags & ATA_PFLAG_LOADING))
goto skip_scr;
svia_scr_write(link, SCR_CONTROL, 0x300);
svia_scr_read(link, SCR_CONTROL, &scontrol);
do {
ata_msleep(link->ap, 200);
svia_scr_read(link, SCR_STATUS, &sstatus);
if ((sstatus & 0xf) != 1)
break;
} while (time_before(jiffies, timeout));
svia_scr_read(link, SCR_STATUS, &sstatus);
svia_scr_read(link, SCR_CONTROL, &scontrol);
online = (sstatus & 0xf) == 0x3;
ata_port_info(ap,
"SATA link %s 1.5 Gbps (SStatus %X SControl %X)\n",
online ? "up" : "down", sstatus, scontrol);
svia_scr_read(link, SCR_STATUS, &sstatus);
if (!online) {
ehc->i.action &= ~ATA_EH_RESET;
return 0;
}
skip_scr:
ata_sff_wait_ready(link, deadline);
return 0;
}
static void vt6420_bmdma_start(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
if ((qc->tf.command == ATA_CMD_PACKET) &&
(qc->scsicmd->sc_data_direction == DMA_TO_DEVICE)) {
ata_sff_pause(ap);
}
ata_bmdma_start(qc);
}
static int vt6421_pata_cable_detect(struct ata_port *ap)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u8 tmp;
pci_read_config_byte(pdev, PATA_UDMA_TIMING, &tmp);
if (tmp & 0x10)
return ATA_CBL_PATA40;
return ATA_CBL_PATA80;
}
static void vt6421_set_pio_mode(struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
static const u8 pio_bits[] = { 0xA8, 0x65, 0x65, 0x31, 0x20 };
pci_write_config_byte(pdev, PATA_PIO_TIMING - adev->devno,
pio_bits[adev->pio_mode - XFER_PIO_0]);
}
static void vt6421_set_dma_mode(struct ata_port *ap, struct ata_device *adev)
{
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
static const u8 udma_bits[] = { 0xEE, 0xE8, 0xE6, 0xE4, 0xE2, 0xE1, 0xE0, 0xE0 };
pci_write_config_byte(pdev, PATA_UDMA_TIMING - adev->devno,
udma_bits[adev->dma_mode - XFER_UDMA_0]);
}
static void __iomem *svia_scr_addr(void __iomem *addr, unsigned int port)
{
return addr + (port * 128);
}
static void __iomem *vt6421_scr_addr(void __iomem *addr, unsigned int port)
{
return addr + (port * 64);
}
static void vt6421_init_addrs(struct ata_port *ap)
{
void __iomem * const * iomap = ap->host->iomap;
void __iomem *reg_addr = iomap[ap->port_no];
void __iomem *bmdma_addr = iomap[4] + (ap->port_no * 8);
struct ata_ioports *ioaddr = &ap->ioaddr;
ioaddr->cmd_addr = reg_addr;
ioaddr->altstatus_addr =
ioaddr->ctl_addr = (void __iomem *)
((unsigned long)(reg_addr + 8) | ATA_PCI_CTL_OFS);
ioaddr->bmdma_addr = bmdma_addr;
ioaddr->scr_addr = vt6421_scr_addr(iomap[5], ap->port_no);
ata_sff_std_ports(ioaddr);
ata_port_pbar_desc(ap, ap->port_no, -1, "port");
ata_port_pbar_desc(ap, 4, ap->port_no * 8, "bmdma");
}
static int vt6420_prepare_host(struct pci_dev *pdev, struct ata_host **r_host)
{
const struct ata_port_info *ppi[] = { &vt6420_port_info, NULL };
struct ata_host *host;
int rc;
if (vt6420_hotplug) {
ppi[0]->port_ops->scr_read = svia_scr_read;
ppi[0]->port_ops->scr_write = svia_scr_write;
}
rc = ata_pci_bmdma_prepare_host(pdev, ppi, &host);
if (rc)
return rc;
*r_host = host;
rc = pcim_iomap_regions(pdev, 1 << 5, DRV_NAME);
if (rc) {
dev_err(&pdev->dev, "failed to iomap PCI BAR 5\n");
return rc;
}
host->ports[0]->ioaddr.scr_addr = svia_scr_addr(host->iomap[5], 0);
host->ports[1]->ioaddr.scr_addr = svia_scr_addr(host->iomap[5], 1);
return 0;
}
static int vt6421_prepare_host(struct pci_dev *pdev, struct ata_host **r_host)
{
const struct ata_port_info *ppi[] =
{ &vt6421_sport_info, &vt6421_sport_info, &vt6421_pport_info };
struct ata_host *host;
int i, rc;
*r_host = host = ata_host_alloc_pinfo(&pdev->dev, ppi, ARRAY_SIZE(ppi));
if (!host) {
dev_err(&pdev->dev, "failed to allocate host\n");
return -ENOMEM;
}
rc = pcim_iomap_regions(pdev, 0x3f, DRV_NAME);
if (rc) {
dev_err(&pdev->dev, "failed to request/iomap PCI BARs (errno=%d)\n",
rc);
return rc;
}
host->iomap = pcim_iomap_table(pdev);
for (i = 0; i < host->n_ports; i++)
vt6421_init_addrs(host->ports[i]);
rc = dma_set_mask(&pdev->dev, ATA_DMA_MASK);
if (rc)
return rc;
rc = dma_set_coherent_mask(&pdev->dev, ATA_DMA_MASK);
if (rc)
return rc;
return 0;
}
static int vt8251_prepare_host(struct pci_dev *pdev, struct ata_host **r_host)
{
const struct ata_port_info *ppi[] = { &vt8251_port_info, NULL };
struct ata_host *host;
int i, rc;
rc = ata_pci_bmdma_prepare_host(pdev, ppi, &host);
if (rc)
return rc;
*r_host = host;
rc = pcim_iomap_regions(pdev, 1 << 5, DRV_NAME);
if (rc) {
dev_err(&pdev->dev, "failed to iomap PCI BAR 5\n");
return rc;
}
for (i = 0; i < host->n_ports; i++)
ata_slave_link_init(host->ports[i]);
return 0;
}
static void svia_wd_fix(struct pci_dev *pdev)
{
u8 tmp8;
pci_read_config_byte(pdev, 0x52, &tmp8);
pci_write_config_byte(pdev, 0x52, tmp8 | BIT(2));
}
static irqreturn_t vt642x_interrupt(int irq, void *dev_instance)
{
struct ata_host *host = dev_instance;
irqreturn_t rc = ata_bmdma_interrupt(irq, dev_instance);
if (rc != IRQ_HANDLED) {
u32 serror;
unsigned long flags;
spin_lock_irqsave(&host->lock, flags);
svia_scr_read(&host->ports[0]->link, SCR_ERROR, &serror);
if (serror & SERR_PHYRDY_CHG) {
ata_ehi_hotplugged(&host->ports[0]->link.eh_info);
ata_port_freeze(host->ports[0]);
rc = IRQ_HANDLED;
}
svia_scr_read(&host->ports[1]->link, SCR_ERROR, &serror);
if (serror & SERR_PHYRDY_CHG) {
ata_ehi_hotplugged(&host->ports[1]->link.eh_info);
ata_port_freeze(host->ports[1]);
rc = IRQ_HANDLED;
}
spin_unlock_irqrestore(&host->lock, flags);
}
return rc;
}
static void vt6421_error_handler(struct ata_port *ap)
{
struct svia_priv *hpriv = ap->host->private_data;
struct pci_dev *pdev = to_pci_dev(ap->host->dev);
u32 serror;
if (!hpriv->wd_workaround) {
svia_scr_read(&ap->link, SCR_ERROR, &serror);
if (serror == 0x1000500) {
ata_port_warn(ap, "Incompatible drive: enabling workaround. This slows down transfer rate to ~60 MB/s");
svia_wd_fix(pdev);
hpriv->wd_workaround = true;
ap->link.eh_context.i.flags |= ATA_EHI_QUIET;
}
}
ata_sff_error_handler(ap);
}
static void svia_configure(struct pci_dev *pdev, int board_id,
struct svia_priv *hpriv)
{
u8 tmp8;
pci_read_config_byte(pdev, PCI_INTERRUPT_LINE, &tmp8);
dev_info(&pdev->dev, "routed to hard irq line %d\n",
(int) (tmp8 & 0xf0) == 0xf0 ? 0 : tmp8 & 0x0f);
pci_read_config_byte(pdev, SATA_CHAN_ENAB, &tmp8);
if ((tmp8 & ALL_PORTS) != ALL_PORTS) {
dev_dbg(&pdev->dev, "enabling SATA channels (0x%x)\n",
(int)tmp8);
tmp8 |= ALL_PORTS;
pci_write_config_byte(pdev, SATA_CHAN_ENAB, tmp8);
}
pci_read_config_byte(pdev, SATA_INT_GATE, &tmp8);
if ((tmp8 & ALL_PORTS) != ALL_PORTS) {
dev_dbg(&pdev->dev, "enabling SATA channel interrupts (0x%x)\n",
(int) tmp8);
tmp8 |= ALL_PORTS;
pci_write_config_byte(pdev, SATA_INT_GATE, tmp8);
}
pci_read_config_byte(pdev, SATA_NATIVE_MODE, &tmp8);
if ((tmp8 & NATIVE_MODE_ALL) != NATIVE_MODE_ALL) {
dev_dbg(&pdev->dev,
"enabling SATA channel native mode (0x%x)\n",
(int) tmp8);
tmp8 |= NATIVE_MODE_ALL;
pci_write_config_byte(pdev, SATA_NATIVE_MODE, tmp8);
}
if ((board_id == vt6420 && vt6420_hotplug) || board_id == vt6421) {
pci_read_config_byte(pdev, SVIA_MISC_3, &tmp8);
if ((tmp8 & SATA_HOTPLUG) != SATA_HOTPLUG) {
dev_dbg(&pdev->dev,
"enabling SATA hotplug (0x%x)\n",
(int) tmp8);
tmp8 |= SATA_HOTPLUG;
pci_write_config_byte(pdev, SVIA_MISC_3, tmp8);
}
}
if (board_id == vt6420) {
svia_wd_fix(pdev);
hpriv->wd_workaround = true;
}
}
static int svia_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
unsigned int i;
int rc;
struct ata_host *host = NULL;
int board_id = (int) ent->driver_data;
const unsigned *bar_sizes;
struct svia_priv *hpriv;
ata_print_version_once(&pdev->dev, DRV_VERSION);
rc = pcim_enable_device(pdev);
if (rc)
return rc;
if (board_id == vt6421)
bar_sizes = &vt6421_bar_sizes[0];
else
bar_sizes = &svia_bar_sizes[0];
for (i = 0; i < ARRAY_SIZE(svia_bar_sizes); i++)
if ((pci_resource_start(pdev, i) == 0) ||
(pci_resource_len(pdev, i) < bar_sizes[i])) {
dev_err(&pdev->dev,
"invalid PCI BAR %u (sz 0x%llx, val 0x%llx)\n",
i,
(unsigned long long)pci_resource_start(pdev, i),
(unsigned long long)pci_resource_len(pdev, i));
return -ENODEV;
}
switch (board_id) {
case vt6420:
rc = vt6420_prepare_host(pdev, &host);
break;
case vt6421:
rc = vt6421_prepare_host(pdev, &host);
break;
case vt8251:
rc = vt8251_prepare_host(pdev, &host);
break;
default:
rc = -EINVAL;
}
if (rc)
return rc;
hpriv = devm_kzalloc(&pdev->dev, sizeof(*hpriv), GFP_KERNEL);
if (!hpriv)
return -ENOMEM;
host->private_data = hpriv;
svia_configure(pdev, board_id, hpriv);
pci_set_master(pdev);
if ((board_id == vt6420 && vt6420_hotplug) || board_id == vt6421)
return ata_host_activate(host, pdev->irq, vt642x_interrupt,
IRQF_SHARED, &svia_sht);
else
return ata_host_activate(host, pdev->irq, ata_bmdma_interrupt,
IRQF_SHARED, &svia_sht);
}
static int svia_pci_device_resume(struct pci_dev *pdev)
{
struct ata_host *host = pci_get_drvdata(pdev);
struct svia_priv *hpriv = host->private_data;
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
if (hpriv->wd_workaround)
svia_wd_fix(pdev);
ata_host_resume(host);
return 0;
}
