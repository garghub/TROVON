static void __iomem *qs_mmio_base(struct ata_host *host)
{
return host->iomap[QS_MMIO_BAR];
}
static int qs_check_atapi_dma(struct ata_queued_cmd *qc)
{
return 1;
}
static inline void qs_enter_reg_mode(struct ata_port *ap)
{
u8 __iomem *chan = qs_mmio_base(ap->host) + (ap->port_no * 0x4000);
struct qs_port_priv *pp = ap->private_data;
pp->state = qs_state_mmio;
writeb(QS_CTR0_REG, chan + QS_CCT_CTR0);
readb(chan + QS_CCT_CTR0);
}
static inline void qs_reset_channel_logic(struct ata_port *ap)
{
u8 __iomem *chan = qs_mmio_base(ap->host) + (ap->port_no * 0x4000);
writeb(QS_CTR1_RCHN, chan + QS_CCT_CTR1);
readb(chan + QS_CCT_CTR0);
qs_enter_reg_mode(ap);
}
static void qs_freeze(struct ata_port *ap)
{
u8 __iomem *mmio_base = qs_mmio_base(ap->host);
writeb(0, mmio_base + QS_HCT_CTRL);
qs_enter_reg_mode(ap);
}
static void qs_thaw(struct ata_port *ap)
{
u8 __iomem *mmio_base = qs_mmio_base(ap->host);
qs_enter_reg_mode(ap);
writeb(1, mmio_base + QS_HCT_CTRL);
}
static int qs_prereset(struct ata_link *link, unsigned long deadline)
{
struct ata_port *ap = link->ap;
qs_reset_channel_logic(ap);
return ata_sff_prereset(link, deadline);
}
static int qs_scr_read(struct ata_link *link, unsigned int sc_reg, u32 *val)
{
if (sc_reg > SCR_CONTROL)
return -EINVAL;
*val = readl(link->ap->ioaddr.scr_addr + (sc_reg * 8));
return 0;
}
static void qs_error_handler(struct ata_port *ap)
{
qs_enter_reg_mode(ap);
ata_sff_error_handler(ap);
}
static int qs_scr_write(struct ata_link *link, unsigned int sc_reg, u32 val)
{
if (sc_reg > SCR_CONTROL)
return -EINVAL;
writel(val, link->ap->ioaddr.scr_addr + (sc_reg * 8));
return 0;
}
static unsigned int qs_fill_sg(struct ata_queued_cmd *qc)
{
struct scatterlist *sg;
struct ata_port *ap = qc->ap;
struct qs_port_priv *pp = ap->private_data;
u8 *prd = pp->pkt + QS_CPB_BYTES;
unsigned int si;
for_each_sg(qc->sg, sg, qc->n_elem, si) {
u64 addr;
u32 len;
addr = sg_dma_address(sg);
*(__le64 *)prd = cpu_to_le64(addr);
prd += sizeof(u64);
len = sg_dma_len(sg);
*(__le32 *)prd = cpu_to_le32(len);
prd += sizeof(u64);
VPRINTK("PRD[%u] = (0x%llX, 0x%X)\n", si,
(unsigned long long)addr, len);
}
return si;
}
static void qs_qc_prep(struct ata_queued_cmd *qc)
{
struct qs_port_priv *pp = qc->ap->private_data;
u8 dflags = QS_DF_PORD, *buf = pp->pkt;
u8 hflags = QS_HF_DAT | QS_HF_IEN | QS_HF_VLD;
u64 addr;
unsigned int nelem;
VPRINTK("ENTER\n");
qs_enter_reg_mode(qc->ap);
if (qc->tf.protocol != ATA_PROT_DMA)
return;
nelem = qs_fill_sg(qc);
if ((qc->tf.flags & ATA_TFLAG_WRITE))
hflags |= QS_HF_DIRO;
if ((qc->tf.flags & ATA_TFLAG_LBA48))
dflags |= QS_DF_ELBA;
buf[ 0] = QS_HCB_HDR;
buf[ 1] = hflags;
*(__le32 *)(&buf[ 4]) = cpu_to_le32(qc->nbytes);
*(__le32 *)(&buf[ 8]) = cpu_to_le32(nelem);
addr = ((u64)pp->pkt_dma) + QS_CPB_BYTES;
*(__le64 *)(&buf[16]) = cpu_to_le64(addr);
buf[24] = QS_DCB_HDR;
buf[28] = dflags;
ata_tf_to_fis(&qc->tf, 0, 1, &buf[32]);
}
static inline void qs_packet_start(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
u8 __iomem *chan = qs_mmio_base(ap->host) + (ap->port_no * 0x4000);
VPRINTK("ENTER, ap %p\n", ap);
writeb(QS_CTR0_CLER, chan + QS_CCT_CTR0);
wmb();
writel(QS_CCF_RUN_PKT, chan + QS_CCT_CFF);
readl(chan + QS_CCT_CFF);
}
static unsigned int qs_qc_issue(struct ata_queued_cmd *qc)
{
struct qs_port_priv *pp = qc->ap->private_data;
switch (qc->tf.protocol) {
case ATA_PROT_DMA:
pp->state = qs_state_pkt;
qs_packet_start(qc);
return 0;
case ATAPI_PROT_DMA:
BUG();
break;
default:
break;
}
pp->state = qs_state_mmio;
return ata_sff_qc_issue(qc);
}
static void qs_do_or_die(struct ata_queued_cmd *qc, u8 status)
{
qc->err_mask |= ac_err_mask(status);
if (!qc->err_mask) {
ata_qc_complete(qc);
} else {
struct ata_port *ap = qc->ap;
struct ata_eh_info *ehi = &ap->link.eh_info;
ata_ehi_clear_desc(ehi);
ata_ehi_push_desc(ehi, "status 0x%02X", status);
if (qc->err_mask == AC_ERR_DEV)
ata_port_abort(ap);
else
ata_port_freeze(ap);
}
}
static inline unsigned int qs_intr_pkt(struct ata_host *host)
{
unsigned int handled = 0;
u8 sFFE;
u8 __iomem *mmio_base = qs_mmio_base(host);
do {
u32 sff0 = readl(mmio_base + QS_HST_SFF);
u32 sff1 = readl(mmio_base + QS_HST_SFF + 4);
u8 sEVLD = (sff1 >> 30) & 0x01;
sFFE = sff1 >> 31;
if (sEVLD) {
u8 sDST = sff0 >> 16;
u8 sHST = sff1 & 0x3f;
unsigned int port_no = (sff1 >> 8) & 0x03;
struct ata_port *ap = host->ports[port_no];
struct qs_port_priv *pp = ap->private_data;
struct ata_queued_cmd *qc;
DPRINTK("SFF=%08x%08x: sCHAN=%u sHST=%d sDST=%02x\n",
sff1, sff0, port_no, sHST, sDST);
handled = 1;
if (!pp || pp->state != qs_state_pkt)
continue;
qc = ata_qc_from_tag(ap, ap->link.active_tag);
if (qc && (!(qc->tf.flags & ATA_TFLAG_POLLING))) {
switch (sHST) {
case 0:
case 3:
qs_enter_reg_mode(qc->ap);
qs_do_or_die(qc, sDST);
break;
default:
break;
}
}
}
} while (!sFFE);
return handled;
}
static inline unsigned int qs_intr_mmio(struct ata_host *host)
{
unsigned int handled = 0, port_no;
for (port_no = 0; port_no < host->n_ports; ++port_no) {
struct ata_port *ap = host->ports[port_no];
struct qs_port_priv *pp = ap->private_data;
struct ata_queued_cmd *qc;
qc = ata_qc_from_tag(ap, ap->link.active_tag);
if (!qc) {
ata_sff_check_status(ap);
handled = 1;
continue;
}
if (!pp || pp->state != qs_state_mmio)
continue;
if (!(qc->tf.flags & ATA_TFLAG_POLLING))
handled |= ata_sff_port_intr(ap, qc);
}
return handled;
}
static irqreturn_t qs_intr(int irq, void *dev_instance)
{
struct ata_host *host = dev_instance;
unsigned int handled = 0;
unsigned long flags;
VPRINTK("ENTER\n");
spin_lock_irqsave(&host->lock, flags);
handled = qs_intr_pkt(host) | qs_intr_mmio(host);
spin_unlock_irqrestore(&host->lock, flags);
VPRINTK("EXIT\n");
return IRQ_RETVAL(handled);
}
static void qs_ata_setup_port(struct ata_ioports *port, void __iomem *base)
{
port->cmd_addr =
port->data_addr = base + 0x400;
port->error_addr =
port->feature_addr = base + 0x408;
port->nsect_addr = base + 0x410;
port->lbal_addr = base + 0x418;
port->lbam_addr = base + 0x420;
port->lbah_addr = base + 0x428;
port->device_addr = base + 0x430;
port->status_addr =
port->command_addr = base + 0x438;
port->altstatus_addr =
port->ctl_addr = base + 0x440;
port->scr_addr = base + 0xc00;
}
static int qs_port_start(struct ata_port *ap)
{
struct device *dev = ap->host->dev;
struct qs_port_priv *pp;
void __iomem *mmio_base = qs_mmio_base(ap->host);
void __iomem *chan = mmio_base + (ap->port_no * 0x4000);
u64 addr;
pp = devm_kzalloc(dev, sizeof(*pp), GFP_KERNEL);
if (!pp)
return -ENOMEM;
pp->pkt = dmam_alloc_coherent(dev, QS_PKT_BYTES, &pp->pkt_dma,
GFP_KERNEL);
if (!pp->pkt)
return -ENOMEM;
memset(pp->pkt, 0, QS_PKT_BYTES);
ap->private_data = pp;
qs_enter_reg_mode(ap);
addr = (u64)pp->pkt_dma;
writel((u32) addr, chan + QS_CCF_CPBA);
writel((u32)(addr >> 32), chan + QS_CCF_CPBA + 4);
return 0;
}
static void qs_host_stop(struct ata_host *host)
{
void __iomem *mmio_base = qs_mmio_base(host);
writeb(0, mmio_base + QS_HCT_CTRL);
writeb(QS_CNFG3_GSRST, mmio_base + QS_HCF_CNFG3);
}
static void qs_host_init(struct ata_host *host, unsigned int chip_id)
{
void __iomem *mmio_base = host->iomap[QS_MMIO_BAR];
unsigned int port_no;
writeb(0, mmio_base + QS_HCT_CTRL);
writeb(QS_CNFG3_GSRST, mmio_base + QS_HCF_CNFG3);
for (port_no = 0; port_no < host->n_ports; ++port_no) {
u8 __iomem *chan = mmio_base + (port_no * 0x4000);
writeb(QS_CTR1_RDEV|QS_CTR1_RCHN, chan + QS_CCT_CTR1);
writeb(QS_CTR0_REG, chan + QS_CCT_CTR0);
readb(chan + QS_CCT_CTR0);
}
writeb(QS_SERD3_PHY_ENA, mmio_base + QS_HVS_SERD3);
for (port_no = 0; port_no < host->n_ports; ++port_no) {
u8 __iomem *chan = mmio_base + (port_no * 0x4000);
writew(32, chan + QS_CFC_HUFT);
writew(32, chan + QS_CFC_HDFT);
writew(10, chan + QS_CFC_DUFT);
writew( 8, chan + QS_CFC_DDFT);
writeb(QS_CPB_ORDER, chan + QS_CCF_CSEP);
}
writeb(1, mmio_base + QS_HCT_CTRL);
}
static int qs_set_dma_masks(struct pci_dev *pdev, void __iomem *mmio_base)
{
u32 bus_info = readl(mmio_base + QS_HID_HPHY);
int rc, have_64bit_bus = (bus_info & QS_HPHY_64BIT);
if (have_64bit_bus &&
!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (rc) {
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc) {
dev_printk(KERN_ERR, &pdev->dev,
"64-bit DMA enable failed\n");
return rc;
}
}
} else {
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc) {
dev_printk(KERN_ERR, &pdev->dev,
"32-bit DMA enable failed\n");
return rc;
}
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc) {
dev_printk(KERN_ERR, &pdev->dev,
"32-bit consistent DMA enable failed\n");
return rc;
}
}
return 0;
}
static int qs_ata_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
static int printed_version;
unsigned int board_idx = (unsigned int) ent->driver_data;
const struct ata_port_info *ppi[] = { &qs_port_info[board_idx], NULL };
struct ata_host *host;
int rc, port_no;
if (!printed_version++)
dev_printk(KERN_DEBUG, &pdev->dev, "version " DRV_VERSION "\n");
host = ata_host_alloc_pinfo(&pdev->dev, ppi, QS_PORTS);
if (!host)
return -ENOMEM;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
if ((pci_resource_flags(pdev, QS_MMIO_BAR) & IORESOURCE_MEM) == 0)
return -ENODEV;
rc = pcim_iomap_regions(pdev, 1 << QS_MMIO_BAR, DRV_NAME);
if (rc)
return rc;
host->iomap = pcim_iomap_table(pdev);
rc = qs_set_dma_masks(pdev, host->iomap[QS_MMIO_BAR]);
if (rc)
return rc;
for (port_no = 0; port_no < host->n_ports; ++port_no) {
struct ata_port *ap = host->ports[port_no];
unsigned int offset = port_no * 0x4000;
void __iomem *chan = host->iomap[QS_MMIO_BAR] + offset;
qs_ata_setup_port(&ap->ioaddr, chan);
ata_port_pbar_desc(ap, QS_MMIO_BAR, -1, "mmio");
ata_port_pbar_desc(ap, QS_MMIO_BAR, offset, "port");
}
qs_host_init(host, board_idx);
pci_set_master(pdev);
return ata_host_activate(host, pdev->irq, qs_intr, IRQF_SHARED,
&qs_ata_sht);
}
static int __init qs_ata_init(void)
{
return pci_register_driver(&qs_ata_pci_driver);
}
static void __exit qs_ata_exit(void)
{
pci_unregister_driver(&qs_ata_pci_driver);
}
