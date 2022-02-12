static void __iomem *inic_port_base(struct ata_port *ap)
{
struct inic_host_priv *hpriv = ap->host->private_data;
return hpriv->mmio_base + ap->port_no * PORT_SIZE;
}
static void inic_reset_port(void __iomem *port_base)
{
void __iomem *idma_ctl = port_base + PORT_IDMA_CTL;
readw(idma_ctl);
msleep(1);
writew(IDMA_CTL_RST_IDMA, idma_ctl);
readw(idma_ctl);
msleep(1);
writew(0, idma_ctl);
writeb(0xff, port_base + PORT_IRQ_STAT);
}
static int inic_scr_read(struct ata_link *link, unsigned sc_reg, u32 *val)
{
void __iomem *scr_addr = inic_port_base(link->ap) + PORT_SCR;
void __iomem *addr;
if (unlikely(sc_reg >= ARRAY_SIZE(scr_map)))
return -EINVAL;
addr = scr_addr + scr_map[sc_reg] * 4;
*val = readl(scr_addr + scr_map[sc_reg] * 4);
if (sc_reg == SCR_ERROR)
*val &= ~SERR_PHYRDY_CHG;
return 0;
}
static int inic_scr_write(struct ata_link *link, unsigned sc_reg, u32 val)
{
void __iomem *scr_addr = inic_port_base(link->ap) + PORT_SCR;
if (unlikely(sc_reg >= ARRAY_SIZE(scr_map)))
return -EINVAL;
writel(val, scr_addr + scr_map[sc_reg] * 4);
return 0;
}
static void inic_stop_idma(struct ata_port *ap)
{
void __iomem *port_base = inic_port_base(ap);
readb(port_base + PORT_RPQ_FIFO);
readb(port_base + PORT_RPQ_CNT);
writew(0, port_base + PORT_IDMA_CTL);
}
static void inic_host_err_intr(struct ata_port *ap, u8 irq_stat, u16 idma_stat)
{
struct ata_eh_info *ehi = &ap->link.eh_info;
struct inic_port_priv *pp = ap->private_data;
struct inic_cpb *cpb = &pp->pkt->cpb;
bool freeze = false;
ata_ehi_clear_desc(ehi);
ata_ehi_push_desc(ehi, "irq_stat=0x%x idma_stat=0x%x",
irq_stat, idma_stat);
inic_stop_idma(ap);
if (irq_stat & (PIRQ_OFFLINE | PIRQ_ONLINE)) {
ata_ehi_push_desc(ehi, "hotplug");
ata_ehi_hotplugged(ehi);
freeze = true;
}
if (idma_stat & IDMA_STAT_PERR) {
ata_ehi_push_desc(ehi, "PCI error");
freeze = true;
}
if (idma_stat & IDMA_STAT_CPBERR) {
ata_ehi_push_desc(ehi, "CPB error");
if (cpb->resp_flags & CPB_RESP_IGNORED) {
__ata_ehi_push_desc(ehi, " ignored");
ehi->err_mask |= AC_ERR_INVALID;
freeze = true;
}
if (cpb->resp_flags & CPB_RESP_ATA_ERR)
ehi->err_mask |= AC_ERR_DEV;
if (cpb->resp_flags & CPB_RESP_SPURIOUS) {
__ata_ehi_push_desc(ehi, " spurious-intr");
ehi->err_mask |= AC_ERR_HSM;
freeze = true;
}
if (cpb->resp_flags &
(CPB_RESP_UNDERFLOW | CPB_RESP_OVERFLOW)) {
__ata_ehi_push_desc(ehi, " data-over/underflow");
ehi->err_mask |= AC_ERR_HSM;
freeze = true;
}
}
if (freeze)
ata_port_freeze(ap);
else
ata_port_abort(ap);
}
static void inic_host_intr(struct ata_port *ap)
{
void __iomem *port_base = inic_port_base(ap);
struct ata_queued_cmd *qc = ata_qc_from_tag(ap, ap->link.active_tag);
u8 irq_stat;
u16 idma_stat;
irq_stat = readb(port_base + PORT_IRQ_STAT);
writeb(irq_stat, port_base + PORT_IRQ_STAT);
idma_stat = readw(port_base + PORT_IDMA_STAT);
if (unlikely((irq_stat & PIRQ_ERR) || (idma_stat & IDMA_STAT_ERR)))
inic_host_err_intr(ap, irq_stat, idma_stat);
if (unlikely(!qc))
goto spurious;
if (likely(idma_stat & IDMA_STAT_DONE)) {
inic_stop_idma(ap);
if (unlikely(readb(port_base + PORT_TF_COMMAND) &
(ATA_DF | ATA_ERR)))
qc->err_mask |= AC_ERR_DEV;
ata_qc_complete(qc);
return;
}
spurious:
ata_port_warn(ap, "unhandled interrupt: cmd=0x%x irq_stat=0x%x idma_stat=0x%x\n",
qc ? qc->tf.command : 0xff, irq_stat, idma_stat);
}
static irqreturn_t inic_interrupt(int irq, void *dev_instance)
{
struct ata_host *host = dev_instance;
struct inic_host_priv *hpriv = host->private_data;
u16 host_irq_stat;
int i, handled = 0;
host_irq_stat = readw(hpriv->mmio_base + HOST_IRQ_STAT);
if (unlikely(!(host_irq_stat & HIRQ_GLOBAL)))
goto out;
spin_lock(&host->lock);
for (i = 0; i < NR_PORTS; i++)
if (host_irq_stat & (HIRQ_PORT0 << i)) {
inic_host_intr(host->ports[i]);
handled++;
}
spin_unlock(&host->lock);
out:
return IRQ_RETVAL(handled);
}
static int inic_check_atapi_dma(struct ata_queued_cmd *qc)
{
if (atapi_cmd_type(qc->cdb[0]) == READ)
return 0;
return 1;
}
static void inic_fill_sg(struct inic_prd *prd, struct ata_queued_cmd *qc)
{
struct scatterlist *sg;
unsigned int si;
u8 flags = 0;
if (qc->tf.flags & ATA_TFLAG_WRITE)
flags |= PRD_WRITE;
if (ata_is_dma(qc->tf.protocol))
flags |= PRD_DMA;
for_each_sg(qc->sg, sg, qc->n_elem, si) {
prd->mad = cpu_to_le32(sg_dma_address(sg));
prd->len = cpu_to_le16(sg_dma_len(sg));
prd->flags = flags;
prd++;
}
WARN_ON(!si);
prd[-1].flags |= PRD_END;
}
static void inic_qc_prep(struct ata_queued_cmd *qc)
{
struct inic_port_priv *pp = qc->ap->private_data;
struct inic_pkt *pkt = pp->pkt;
struct inic_cpb *cpb = &pkt->cpb;
struct inic_prd *prd = pkt->prd;
bool is_atapi = ata_is_atapi(qc->tf.protocol);
bool is_data = ata_is_data(qc->tf.protocol);
unsigned int cdb_len = 0;
VPRINTK("ENTER\n");
if (is_atapi)
cdb_len = qc->dev->cdb_len;
memset(pkt, 0, sizeof(struct inic_pkt));
cpb->ctl_flags = CPB_CTL_VALID | CPB_CTL_IEN;
if (is_atapi || is_data)
cpb->ctl_flags |= CPB_CTL_DATA;
cpb->len = cpu_to_le32(qc->nbytes + cdb_len);
cpb->prd = cpu_to_le32(pp->pkt_dma + offsetof(struct inic_pkt, prd));
cpb->device = qc->tf.device;
cpb->feature = qc->tf.feature;
cpb->nsect = qc->tf.nsect;
cpb->lbal = qc->tf.lbal;
cpb->lbam = qc->tf.lbam;
cpb->lbah = qc->tf.lbah;
if (qc->tf.flags & ATA_TFLAG_LBA48) {
cpb->hob_feature = qc->tf.hob_feature;
cpb->hob_nsect = qc->tf.hob_nsect;
cpb->hob_lbal = qc->tf.hob_lbal;
cpb->hob_lbam = qc->tf.hob_lbam;
cpb->hob_lbah = qc->tf.hob_lbah;
}
cpb->command = qc->tf.command;
if (is_atapi) {
memcpy(pkt->cdb, qc->cdb, ATAPI_CDB_LEN);
prd->mad = cpu_to_le32(pp->pkt_dma +
offsetof(struct inic_pkt, cdb));
prd->len = cpu_to_le16(cdb_len);
prd->flags = PRD_CDB | PRD_WRITE;
if (!is_data)
prd->flags |= PRD_END;
prd++;
}
if (is_data)
inic_fill_sg(prd, qc);
pp->cpb_tbl[0] = pp->pkt_dma;
}
static unsigned int inic_qc_issue(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
void __iomem *port_base = inic_port_base(ap);
writew(HCTL_FTHD0 | HCTL_LEDEN, port_base + HOST_CTL);
writew(IDMA_CTL_GO, port_base + PORT_IDMA_CTL);
writeb(0, port_base + PORT_CPB_PTQFIFO);
return 0;
}
static void inic_tf_read(struct ata_port *ap, struct ata_taskfile *tf)
{
void __iomem *port_base = inic_port_base(ap);
tf->feature = readb(port_base + PORT_TF_FEATURE);
tf->nsect = readb(port_base + PORT_TF_NSECT);
tf->lbal = readb(port_base + PORT_TF_LBAL);
tf->lbam = readb(port_base + PORT_TF_LBAM);
tf->lbah = readb(port_base + PORT_TF_LBAH);
tf->device = readb(port_base + PORT_TF_DEVICE);
tf->command = readb(port_base + PORT_TF_COMMAND);
}
static bool inic_qc_fill_rtf(struct ata_queued_cmd *qc)
{
struct ata_taskfile *rtf = &qc->result_tf;
struct ata_taskfile tf;
inic_tf_read(qc->ap, &tf);
if (!(tf.command & ATA_ERR))
return false;
rtf->command = tf.command;
rtf->feature = tf.feature;
return true;
}
static void inic_freeze(struct ata_port *ap)
{
void __iomem *port_base = inic_port_base(ap);
writeb(PIRQ_MASK_FREEZE, port_base + PORT_IRQ_MASK);
writeb(0xff, port_base + PORT_IRQ_STAT);
}
static void inic_thaw(struct ata_port *ap)
{
void __iomem *port_base = inic_port_base(ap);
writeb(0xff, port_base + PORT_IRQ_STAT);
writeb(PIRQ_MASK_DEFAULT, port_base + PORT_IRQ_MASK);
}
static int inic_check_ready(struct ata_link *link)
{
void __iomem *port_base = inic_port_base(link->ap);
return ata_check_ready(readb(port_base + PORT_TF_COMMAND));
}
static int inic_hardreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
void __iomem *port_base = inic_port_base(ap);
void __iomem *idma_ctl = port_base + PORT_IDMA_CTL;
const unsigned long *timing = sata_ehc_deb_timing(&link->eh_context);
int rc;
inic_reset_port(port_base);
writew(IDMA_CTL_RST_ATA, idma_ctl);
readw(idma_ctl);
ata_msleep(ap, 1);
writew(0, idma_ctl);
rc = sata_link_resume(link, timing, deadline);
if (rc) {
ata_link_warn(link,
"failed to resume link after reset (errno=%d)\n",
rc);
return rc;
}
*class = ATA_DEV_NONE;
if (ata_link_online(link)) {
struct ata_taskfile tf;
rc = ata_wait_after_reset(link, deadline, inic_check_ready);
if (rc) {
ata_link_warn(link,
"device not ready after hardreset (errno=%d)\n",
rc);
return rc;
}
inic_tf_read(ap, &tf);
*class = ata_dev_classify(&tf);
}
return 0;
}
static void inic_error_handler(struct ata_port *ap)
{
void __iomem *port_base = inic_port_base(ap);
inic_reset_port(port_base);
ata_std_error_handler(ap);
}
static void inic_post_internal_cmd(struct ata_queued_cmd *qc)
{
if (qc->flags & ATA_QCFLAG_FAILED)
inic_reset_port(inic_port_base(qc->ap));
}
static void init_port(struct ata_port *ap)
{
void __iomem *port_base = inic_port_base(ap);
struct inic_port_priv *pp = ap->private_data;
memset(pp->pkt, 0, sizeof(struct inic_pkt));
memset(pp->cpb_tbl, 0, IDMA_CPB_TBL_SIZE);
writel(pp->cpb_tbl_dma, port_base + PORT_CPB_CPBLAR);
}
static int inic_port_resume(struct ata_port *ap)
{
init_port(ap);
return 0;
}
static int inic_port_start(struct ata_port *ap)
{
struct device *dev = ap->host->dev;
struct inic_port_priv *pp;
pp = devm_kzalloc(dev, sizeof(*pp), GFP_KERNEL);
if (!pp)
return -ENOMEM;
ap->private_data = pp;
pp->pkt = dmam_alloc_coherent(dev, sizeof(struct inic_pkt),
&pp->pkt_dma, GFP_KERNEL);
if (!pp->pkt)
return -ENOMEM;
pp->cpb_tbl = dmam_alloc_coherent(dev, IDMA_CPB_TBL_SIZE,
&pp->cpb_tbl_dma, GFP_KERNEL);
if (!pp->cpb_tbl)
return -ENOMEM;
init_port(ap);
return 0;
}
static int init_controller(void __iomem *mmio_base, u16 hctl)
{
int i;
u16 val;
hctl &= ~HCTL_KNOWN_BITS;
writew(hctl | HCTL_SOFTRST, mmio_base + HOST_CTL);
readw(mmio_base + HOST_CTL);
for (i = 0; i < 10; i++) {
msleep(1);
val = readw(mmio_base + HOST_CTL);
if (!(val & HCTL_SOFTRST))
break;
}
if (val & HCTL_SOFTRST)
return -EIO;
for (i = 0; i < NR_PORTS; i++) {
void __iomem *port_base = mmio_base + i * PORT_SIZE;
writeb(0xff, port_base + PORT_IRQ_MASK);
inic_reset_port(port_base);
}
writew(hctl & ~HCTL_IRQOFF, mmio_base + HOST_CTL);
val = readw(mmio_base + HOST_IRQ_MASK);
val &= ~(HIRQ_PORT0 | HIRQ_PORT1);
writew(val, mmio_base + HOST_IRQ_MASK);
return 0;
}
static int inic_pci_device_resume(struct pci_dev *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
struct inic_host_priv *hpriv = host->private_data;
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
if (pdev->dev.power.power_state.event == PM_EVENT_SUSPEND) {
rc = init_controller(hpriv->mmio_base, hpriv->cached_hctl);
if (rc)
return rc;
}
ata_host_resume(host);
return 0;
}
static int inic_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
const struct ata_port_info *ppi[] = { &inic_port_info, NULL };
struct ata_host *host;
struct inic_host_priv *hpriv;
void __iomem * const *iomap;
int mmio_bar;
int i, rc;
ata_print_version_once(&pdev->dev, DRV_VERSION);
host = ata_host_alloc_pinfo(&pdev->dev, ppi, NR_PORTS);
hpriv = devm_kzalloc(&pdev->dev, sizeof(*hpriv), GFP_KERNEL);
if (!host || !hpriv)
return -ENOMEM;
host->private_data = hpriv;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
if (pci_resource_flags(pdev, MMIO_BAR_PCI) & IORESOURCE_MEM)
mmio_bar = MMIO_BAR_PCI;
else
mmio_bar = MMIO_BAR_CARDBUS;
rc = pcim_iomap_regions(pdev, 1 << mmio_bar, DRV_NAME);
if (rc)
return rc;
host->iomap = iomap = pcim_iomap_table(pdev);
hpriv->mmio_base = iomap[mmio_bar];
hpriv->cached_hctl = readw(hpriv->mmio_base + HOST_CTL);
for (i = 0; i < NR_PORTS; i++) {
struct ata_port *ap = host->ports[i];
ata_port_pbar_desc(ap, mmio_bar, -1, "mmio");
ata_port_pbar_desc(ap, mmio_bar, i * PORT_SIZE, "port");
}
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev, "32-bit DMA enable failed\n");
return rc;
}
rc = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev, "32-bit consistent DMA enable failed\n");
return rc;
}
rc = pci_set_dma_max_seg_size(pdev, 65536 - 512);
if (rc) {
dev_err(&pdev->dev, "failed to set the maximum segment size\n");
return rc;
}
rc = init_controller(hpriv->mmio_base, hpriv->cached_hctl);
if (rc) {
dev_err(&pdev->dev, "failed to initialize controller\n");
return rc;
}
pci_set_master(pdev);
return ata_host_activate(host, pdev->irq, inic_interrupt, IRQF_SHARED,
&inic_sht);
}
