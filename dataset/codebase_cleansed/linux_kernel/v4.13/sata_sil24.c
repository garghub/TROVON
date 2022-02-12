static int sil24_tag(int tag)
{
if (unlikely(ata_tag_internal(tag)))
return 0;
return tag;
}
static unsigned long sil24_port_offset(struct ata_port *ap)
{
return ap->port_no * PORT_REGS_SIZE;
}
static void __iomem *sil24_port_base(struct ata_port *ap)
{
return ap->host->iomap[SIL24_PORT_BAR] + sil24_port_offset(ap);
}
static void sil24_dev_config(struct ata_device *dev)
{
void __iomem *port = sil24_port_base(dev->link->ap);
if (dev->cdb_len == 16)
writel(PORT_CS_CDB16, port + PORT_CTRL_STAT);
else
writel(PORT_CS_CDB16, port + PORT_CTRL_CLR);
}
static void sil24_read_tf(struct ata_port *ap, int tag, struct ata_taskfile *tf)
{
void __iomem *port = sil24_port_base(ap);
struct sil24_prb __iomem *prb;
u8 fis[6 * 4];
prb = port + PORT_LRAM + sil24_tag(tag) * PORT_LRAM_SLOT_SZ;
memcpy_fromio(fis, prb->fis, sizeof(fis));
ata_tf_from_fis(fis, tf);
}
static int sil24_scr_read(struct ata_link *link, unsigned sc_reg, u32 *val)
{
void __iomem *scr_addr = sil24_port_base(link->ap) + PORT_SCONTROL;
if (sc_reg < ARRAY_SIZE(sil24_scr_map)) {
*val = readl(scr_addr + sil24_scr_map[sc_reg] * 4);
return 0;
}
return -EINVAL;
}
static int sil24_scr_write(struct ata_link *link, unsigned sc_reg, u32 val)
{
void __iomem *scr_addr = sil24_port_base(link->ap) + PORT_SCONTROL;
if (sc_reg < ARRAY_SIZE(sil24_scr_map)) {
writel(val, scr_addr + sil24_scr_map[sc_reg] * 4);
return 0;
}
return -EINVAL;
}
static void sil24_config_port(struct ata_port *ap)
{
void __iomem *port = sil24_port_base(ap);
if (ap->flags & SIL24_FLAG_PCIX_IRQ_WOC)
writel(PORT_CS_IRQ_WOC, port + PORT_CTRL_STAT);
else
writel(PORT_CS_IRQ_WOC, port + PORT_CTRL_CLR);
writew(0x8000, port + PORT_DECODE_ERR_THRESH);
writew(0x8000, port + PORT_CRC_ERR_THRESH);
writew(0x8000, port + PORT_HSHK_ERR_THRESH);
writew(0x0000, port + PORT_DECODE_ERR_CNT);
writew(0x0000, port + PORT_CRC_ERR_CNT);
writew(0x0000, port + PORT_HSHK_ERR_CNT);
writel(PORT_CS_32BIT_ACTV, port + PORT_CTRL_CLR);
writel(PORT_CS_PMP_EN | PORT_CS_PMP_RESUME, port + PORT_CTRL_CLR);
}
static void sil24_config_pmp(struct ata_port *ap, int attached)
{
void __iomem *port = sil24_port_base(ap);
if (attached)
writel(PORT_CS_PMP_EN, port + PORT_CTRL_STAT);
else
writel(PORT_CS_PMP_EN, port + PORT_CTRL_CLR);
}
static void sil24_clear_pmp(struct ata_port *ap)
{
void __iomem *port = sil24_port_base(ap);
int i;
writel(PORT_CS_PMP_RESUME, port + PORT_CTRL_CLR);
for (i = 0; i < SATA_PMP_MAX_PORTS; i++) {
void __iomem *pmp_base = port + PORT_PMP + i * PORT_PMP_SIZE;
writel(0, pmp_base + PORT_PMP_STATUS);
writel(0, pmp_base + PORT_PMP_QACTIVE);
}
}
static int sil24_init_port(struct ata_port *ap)
{
void __iomem *port = sil24_port_base(ap);
struct sil24_port_priv *pp = ap->private_data;
u32 tmp;
if (sata_pmp_attached(ap))
sil24_clear_pmp(ap);
writel(PORT_CS_INIT, port + PORT_CTRL_STAT);
ata_wait_register(ap, port + PORT_CTRL_STAT,
PORT_CS_INIT, PORT_CS_INIT, 10, 100);
tmp = ata_wait_register(ap, port + PORT_CTRL_STAT,
PORT_CS_RDY, 0, 10, 100);
if ((tmp & (PORT_CS_INIT | PORT_CS_RDY)) != PORT_CS_RDY) {
pp->do_port_rst = 1;
ap->link.eh_context.i.action |= ATA_EH_RESET;
return -EIO;
}
return 0;
}
static int sil24_exec_polled_cmd(struct ata_port *ap, int pmp,
const struct ata_taskfile *tf,
int is_cmd, u32 ctrl,
unsigned long timeout_msec)
{
void __iomem *port = sil24_port_base(ap);
struct sil24_port_priv *pp = ap->private_data;
struct sil24_prb *prb = &pp->cmd_block[0].ata.prb;
dma_addr_t paddr = pp->cmd_block_dma;
u32 irq_enabled, irq_mask, irq_stat;
int rc;
prb->ctrl = cpu_to_le16(ctrl);
ata_tf_to_fis(tf, pmp, is_cmd, prb->fis);
irq_enabled = readl(port + PORT_IRQ_ENABLE_SET);
writel(PORT_IRQ_COMPLETE | PORT_IRQ_ERROR, port + PORT_IRQ_ENABLE_CLR);
wmb();
writel((u32)paddr, port + PORT_CMD_ACTIVATE);
writel((u64)paddr >> 32, port + PORT_CMD_ACTIVATE + 4);
irq_mask = (PORT_IRQ_COMPLETE | PORT_IRQ_ERROR) << PORT_IRQ_RAW_SHIFT;
irq_stat = ata_wait_register(ap, port + PORT_IRQ_STAT, irq_mask, 0x0,
10, timeout_msec);
writel(irq_mask, port + PORT_IRQ_STAT);
irq_stat >>= PORT_IRQ_RAW_SHIFT;
if (irq_stat & PORT_IRQ_COMPLETE)
rc = 0;
else {
sil24_init_port(ap);
if (irq_stat & PORT_IRQ_ERROR)
rc = -EIO;
else
rc = -EBUSY;
}
writel(irq_enabled, port + PORT_IRQ_ENABLE_SET);
return rc;
}
static int sil24_softreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
int pmp = sata_srst_pmp(link);
unsigned long timeout_msec = 0;
struct ata_taskfile tf;
const char *reason;
int rc;
DPRINTK("ENTER\n");
if (sil24_init_port(ap)) {
reason = "port not ready";
goto err;
}
if (time_after(deadline, jiffies))
timeout_msec = jiffies_to_msecs(deadline - jiffies);
ata_tf_init(link->device, &tf);
rc = sil24_exec_polled_cmd(ap, pmp, &tf, 0, PRB_CTRL_SRST,
timeout_msec);
if (rc == -EBUSY) {
reason = "timeout";
goto err;
} else if (rc) {
reason = "SRST command error";
goto err;
}
sil24_read_tf(ap, 0, &tf);
*class = ata_dev_classify(&tf);
DPRINTK("EXIT, class=%u\n", *class);
return 0;
err:
ata_link_err(link, "softreset failed (%s)\n", reason);
return -EIO;
}
static int sil24_hardreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
struct ata_port *ap = link->ap;
void __iomem *port = sil24_port_base(ap);
struct sil24_port_priv *pp = ap->private_data;
int did_port_rst = 0;
const char *reason;
int tout_msec, rc;
u32 tmp;
retry:
if (pp->do_port_rst) {
ata_port_warn(ap,
"controller in dubious state, performing PORT_RST\n");
writel(PORT_CS_PORT_RST, port + PORT_CTRL_STAT);
ata_msleep(ap, 10);
writel(PORT_CS_PORT_RST, port + PORT_CTRL_CLR);
ata_wait_register(ap, port + PORT_CTRL_STAT, PORT_CS_RDY, 0,
10, 5000);
sil24_config_port(ap);
sil24_config_pmp(ap, ap->nr_pmp_links);
pp->do_port_rst = 0;
did_port_rst = 1;
}
sata_set_spd(link);
tout_msec = 100;
if (ata_link_online(link))
tout_msec = 5000;
writel(PORT_CS_DEV_RST, port + PORT_CTRL_STAT);
tmp = ata_wait_register(ap, port + PORT_CTRL_STAT,
PORT_CS_DEV_RST, PORT_CS_DEV_RST, 10,
tout_msec);
rc = sata_link_debounce(link, sata_deb_timing_long, deadline);
if (rc) {
reason = "PHY debouncing failed";
goto err;
}
if (tmp & PORT_CS_DEV_RST) {
if (ata_link_offline(link))
return 0;
reason = "link not ready";
goto err;
}
return -EAGAIN;
err:
if (!did_port_rst) {
pp->do_port_rst = 1;
goto retry;
}
ata_link_err(link, "hardreset failed (%s)\n", reason);
return -EIO;
}
static inline void sil24_fill_sg(struct ata_queued_cmd *qc,
struct sil24_sge *sge)
{
struct scatterlist *sg;
struct sil24_sge *last_sge = NULL;
unsigned int si;
for_each_sg(qc->sg, sg, qc->n_elem, si) {
sge->addr = cpu_to_le64(sg_dma_address(sg));
sge->cnt = cpu_to_le32(sg_dma_len(sg));
sge->flags = 0;
last_sge = sge;
sge++;
}
last_sge->flags = cpu_to_le32(SGE_TRM);
}
static int sil24_qc_defer(struct ata_queued_cmd *qc)
{
struct ata_link *link = qc->dev->link;
struct ata_port *ap = link->ap;
u8 prot = qc->tf.protocol;
int is_excl = (ata_is_atapi(prot) ||
(qc->flags & ATA_QCFLAG_RESULT_TF));
if (unlikely(ap->excl_link)) {
if (link == ap->excl_link) {
if (ap->nr_active_links)
return ATA_DEFER_PORT;
qc->flags |= ATA_QCFLAG_CLEAR_EXCL;
} else
return ATA_DEFER_PORT;
} else if (unlikely(is_excl)) {
ap->excl_link = link;
if (ap->nr_active_links)
return ATA_DEFER_PORT;
qc->flags |= ATA_QCFLAG_CLEAR_EXCL;
}
return ata_std_qc_defer(qc);
}
static void sil24_qc_prep(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct sil24_port_priv *pp = ap->private_data;
union sil24_cmd_block *cb;
struct sil24_prb *prb;
struct sil24_sge *sge;
u16 ctrl = 0;
cb = &pp->cmd_block[sil24_tag(qc->tag)];
if (!ata_is_atapi(qc->tf.protocol)) {
prb = &cb->ata.prb;
sge = cb->ata.sge;
if (ata_is_data(qc->tf.protocol)) {
u16 prot = 0;
ctrl = PRB_CTRL_PROTOCOL;
if (ata_is_ncq(qc->tf.protocol))
prot |= PRB_PROT_NCQ;
if (qc->tf.flags & ATA_TFLAG_WRITE)
prot |= PRB_PROT_WRITE;
else
prot |= PRB_PROT_READ;
prb->prot = cpu_to_le16(prot);
}
} else {
prb = &cb->atapi.prb;
sge = cb->atapi.sge;
memset(cb->atapi.cdb, 0, sizeof(cb->atapi.cdb));
memcpy(cb->atapi.cdb, qc->cdb, qc->dev->cdb_len);
if (ata_is_data(qc->tf.protocol)) {
if (qc->tf.flags & ATA_TFLAG_WRITE)
ctrl = PRB_CTRL_PACKET_WRITE;
else
ctrl = PRB_CTRL_PACKET_READ;
}
}
prb->ctrl = cpu_to_le16(ctrl);
ata_tf_to_fis(&qc->tf, qc->dev->link->pmp, 1, prb->fis);
if (qc->flags & ATA_QCFLAG_DMAMAP)
sil24_fill_sg(qc, sge);
}
static unsigned int sil24_qc_issue(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
struct sil24_port_priv *pp = ap->private_data;
void __iomem *port = sil24_port_base(ap);
unsigned int tag = sil24_tag(qc->tag);
dma_addr_t paddr;
void __iomem *activate;
paddr = pp->cmd_block_dma + tag * sizeof(*pp->cmd_block);
activate = port + PORT_CMD_ACTIVATE + tag * 8;
wmb();
writel((u32)paddr, activate);
writel((u64)paddr >> 32, activate + 4);
return 0;
}
static bool sil24_qc_fill_rtf(struct ata_queued_cmd *qc)
{
sil24_read_tf(qc->ap, qc->tag, &qc->result_tf);
return true;
}
static void sil24_pmp_attach(struct ata_port *ap)
{
u32 *gscr = ap->link.device->gscr;
sil24_config_pmp(ap, 1);
sil24_init_port(ap);
if (sata_pmp_gscr_vendor(gscr) == 0x11ab &&
sata_pmp_gscr_devid(gscr) == 0x4140) {
ata_port_info(ap,
"disabling NCQ support due to sil24-mv4140 quirk\n");
ap->flags &= ~ATA_FLAG_NCQ;
}
}
static void sil24_pmp_detach(struct ata_port *ap)
{
sil24_init_port(ap);
sil24_config_pmp(ap, 0);
ap->flags |= ATA_FLAG_NCQ;
}
static int sil24_pmp_hardreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
int rc;
rc = sil24_init_port(link->ap);
if (rc) {
ata_link_err(link, "hardreset failed (port not ready)\n");
return rc;
}
return sata_std_hardreset(link, class, deadline);
}
static void sil24_freeze(struct ata_port *ap)
{
void __iomem *port = sil24_port_base(ap);
writel(0xffff, port + PORT_IRQ_ENABLE_CLR);
}
static void sil24_thaw(struct ata_port *ap)
{
void __iomem *port = sil24_port_base(ap);
u32 tmp;
tmp = readl(port + PORT_IRQ_STAT);
writel(tmp, port + PORT_IRQ_STAT);
writel(DEF_PORT_IRQ, port + PORT_IRQ_ENABLE_SET);
}
static void sil24_error_intr(struct ata_port *ap)
{
void __iomem *port = sil24_port_base(ap);
struct sil24_port_priv *pp = ap->private_data;
struct ata_queued_cmd *qc = NULL;
struct ata_link *link;
struct ata_eh_info *ehi;
int abort = 0, freeze = 0;
u32 irq_stat;
irq_stat = readl(port + PORT_IRQ_STAT);
writel(irq_stat, port + PORT_IRQ_STAT);
link = &ap->link;
ehi = &link->eh_info;
ata_ehi_clear_desc(ehi);
ata_ehi_push_desc(ehi, "irq_stat 0x%08x", irq_stat);
if (irq_stat & PORT_IRQ_SDB_NOTIFY) {
ata_ehi_push_desc(ehi, "SDB notify");
sata_async_notification(ap);
}
if (irq_stat & (PORT_IRQ_PHYRDY_CHG | PORT_IRQ_DEV_XCHG)) {
ata_ehi_hotplugged(ehi);
ata_ehi_push_desc(ehi, "%s",
irq_stat & PORT_IRQ_PHYRDY_CHG ?
"PHY RDY changed" : "device exchanged");
freeze = 1;
}
if (irq_stat & PORT_IRQ_UNK_FIS) {
ehi->err_mask |= AC_ERR_HSM;
ehi->action |= ATA_EH_RESET;
ata_ehi_push_desc(ehi, "unknown FIS");
freeze = 1;
}
if (irq_stat & PORT_IRQ_ERROR) {
const struct sil24_cerr_info *ci = NULL;
unsigned int err_mask = 0, action = 0;
u32 context, cerr;
int pmp;
abort = 1;
if (ap->nr_active_links >= 3) {
ehi->err_mask |= AC_ERR_OTHER;
ehi->action |= ATA_EH_RESET;
ata_ehi_push_desc(ehi, "PMP DMA CS errata");
pp->do_port_rst = 1;
freeze = 1;
}
if (sata_pmp_attached(ap)) {
context = readl(port + PORT_CONTEXT);
pmp = (context >> 5) & 0xf;
if (pmp < ap->nr_pmp_links) {
link = &ap->pmp_link[pmp];
ehi = &link->eh_info;
qc = ata_qc_from_tag(ap, link->active_tag);
ata_ehi_clear_desc(ehi);
ata_ehi_push_desc(ehi, "irq_stat 0x%08x",
irq_stat);
} else {
err_mask |= AC_ERR_HSM;
action |= ATA_EH_RESET;
freeze = 1;
}
} else
qc = ata_qc_from_tag(ap, link->active_tag);
cerr = readl(port + PORT_CMD_ERR);
if (cerr < ARRAY_SIZE(sil24_cerr_db))
ci = &sil24_cerr_db[cerr];
if (ci && ci->desc) {
err_mask |= ci->err_mask;
action |= ci->action;
if (action & ATA_EH_RESET)
freeze = 1;
ata_ehi_push_desc(ehi, "%s", ci->desc);
} else {
err_mask |= AC_ERR_OTHER;
action |= ATA_EH_RESET;
freeze = 1;
ata_ehi_push_desc(ehi, "unknown command error %d",
cerr);
}
if (qc)
qc->err_mask |= err_mask;
else
ehi->err_mask |= err_mask;
ehi->action |= action;
if (sata_pmp_attached(ap))
writel(PORT_CS_PMP_RESUME, port + PORT_CTRL_STAT);
}
if (freeze)
ata_port_freeze(ap);
else if (abort) {
if (qc)
ata_link_abort(qc->dev->link);
else
ata_port_abort(ap);
}
}
static inline void sil24_host_intr(struct ata_port *ap)
{
void __iomem *port = sil24_port_base(ap);
u32 slot_stat, qc_active;
int rc;
if (ap->flags & SIL24_FLAG_PCIX_IRQ_WOC)
writel(PORT_IRQ_COMPLETE, port + PORT_IRQ_STAT);
slot_stat = readl(port + PORT_SLOT_STAT);
if (unlikely(slot_stat & HOST_SSTAT_ATTN)) {
sil24_error_intr(ap);
return;
}
qc_active = slot_stat & ~HOST_SSTAT_ATTN;
rc = ata_qc_complete_multiple(ap, qc_active);
if (rc > 0)
return;
if (rc < 0) {
struct ata_eh_info *ehi = &ap->link.eh_info;
ehi->err_mask |= AC_ERR_HSM;
ehi->action |= ATA_EH_RESET;
ata_port_freeze(ap);
return;
}
if (!(ap->flags & SIL24_FLAG_PCIX_IRQ_WOC) && ata_ratelimit())
ata_port_info(ap,
"spurious interrupt (slot_stat 0x%x active_tag %d sactive 0x%x)\n",
slot_stat, ap->link.active_tag, ap->link.sactive);
}
static irqreturn_t sil24_interrupt(int irq, void *dev_instance)
{
struct ata_host *host = dev_instance;
void __iomem *host_base = host->iomap[SIL24_HOST_BAR];
unsigned handled = 0;
u32 status;
int i;
status = readl(host_base + HOST_IRQ_STAT);
if (status == 0xffffffff) {
dev_err(host->dev, "IRQ status == 0xffffffff, "
"PCI fault or device removal?\n");
goto out;
}
if (!(status & IRQ_STAT_4PORTS))
goto out;
spin_lock(&host->lock);
for (i = 0; i < host->n_ports; i++)
if (status & (1 << i)) {
sil24_host_intr(host->ports[i]);
handled++;
}
spin_unlock(&host->lock);
out:
return IRQ_RETVAL(handled);
}
static void sil24_error_handler(struct ata_port *ap)
{
struct sil24_port_priv *pp = ap->private_data;
if (sil24_init_port(ap))
ata_eh_freeze_port(ap);
sata_pmp_error_handler(ap);
pp->do_port_rst = 0;
}
static void sil24_post_internal_cmd(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
if ((qc->flags & ATA_QCFLAG_FAILED) && sil24_init_port(ap))
ata_eh_freeze_port(ap);
}
static int sil24_port_start(struct ata_port *ap)
{
struct device *dev = ap->host->dev;
struct sil24_port_priv *pp;
union sil24_cmd_block *cb;
size_t cb_size = sizeof(*cb) * SIL24_MAX_CMDS;
dma_addr_t cb_dma;
pp = devm_kzalloc(dev, sizeof(*pp), GFP_KERNEL);
if (!pp)
return -ENOMEM;
cb = dmam_alloc_coherent(dev, cb_size, &cb_dma, GFP_KERNEL);
if (!cb)
return -ENOMEM;
memset(cb, 0, cb_size);
pp->cmd_block = cb;
pp->cmd_block_dma = cb_dma;
ap->private_data = pp;
ata_port_pbar_desc(ap, SIL24_HOST_BAR, -1, "host");
ata_port_pbar_desc(ap, SIL24_PORT_BAR, sil24_port_offset(ap), "port");
return 0;
}
static void sil24_init_controller(struct ata_host *host)
{
void __iomem *host_base = host->iomap[SIL24_HOST_BAR];
u32 tmp;
int i;
writel(0, host_base + HOST_FLASH_CMD);
writel(0, host_base + HOST_CTRL);
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
void __iomem *port = sil24_port_base(ap);
writel(0x20c, port + PORT_PHY_CFG);
tmp = readl(port + PORT_CTRL_STAT);
if (tmp & PORT_CS_PORT_RST) {
writel(PORT_CS_PORT_RST, port + PORT_CTRL_CLR);
tmp = ata_wait_register(NULL, port + PORT_CTRL_STAT,
PORT_CS_PORT_RST,
PORT_CS_PORT_RST, 10, 100);
if (tmp & PORT_CS_PORT_RST)
dev_err(host->dev,
"failed to clear port RST\n");
}
sil24_config_port(ap);
}
writel(IRQ_STAT_4PORTS, host_base + HOST_CTRL);
}
static int sil24_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
extern int __MARKER__sil24_cmd_block_is_sized_wrongly;
struct ata_port_info pi = sil24_port_info[ent->driver_data];
const struct ata_port_info *ppi[] = { &pi, NULL };
void __iomem * const *iomap;
struct ata_host *host;
int rc;
u32 tmp;
if (sizeof(union sil24_cmd_block) != PAGE_SIZE)
__MARKER__sil24_cmd_block_is_sized_wrongly = 1;
ata_print_version_once(&pdev->dev, DRV_VERSION);
rc = pcim_enable_device(pdev);
if (rc)
return rc;
rc = pcim_iomap_regions(pdev,
(1 << SIL24_HOST_BAR) | (1 << SIL24_PORT_BAR),
DRV_NAME);
if (rc)
return rc;
iomap = pcim_iomap_table(pdev);
if (pi.flags & SIL24_FLAG_PCIX_IRQ_WOC) {
tmp = readl(iomap[SIL24_HOST_BAR] + HOST_CTRL);
if (tmp & (HOST_CTRL_TRDY | HOST_CTRL_STOP | HOST_CTRL_DEVSEL))
dev_info(&pdev->dev,
"Applying completion IRQ loss on PCI-X errata fix\n");
else
pi.flags &= ~SIL24_FLAG_PCIX_IRQ_WOC;
}
host = ata_host_alloc_pinfo(&pdev->dev, ppi,
SIL24_FLAG2NPORTS(ppi[0]->flags));
if (!host)
return -ENOMEM;
host->iomap = iomap;
if (!dma_set_mask(&pdev->dev, DMA_BIT_MASK(64))) {
rc = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(64));
if (rc) {
rc = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev,
"64-bit DMA enable failed\n");
return rc;
}
}
} else {
rc = dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev, "32-bit DMA enable failed\n");
return rc;
}
rc = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev,
"32-bit consistent DMA enable failed\n");
return rc;
}
}
pcie_set_readrq(pdev, 4096);
sil24_init_controller(host);
if (sata_sil24_msi && !pci_enable_msi(pdev)) {
dev_info(&pdev->dev, "Using MSI\n");
pci_intx(pdev, 0);
}
pci_set_master(pdev);
return ata_host_activate(host, pdev->irq, sil24_interrupt, IRQF_SHARED,
&sil24_sht);
}
static int sil24_pci_device_resume(struct pci_dev *pdev)
{
struct ata_host *host = pci_get_drvdata(pdev);
void __iomem *host_base = host->iomap[SIL24_HOST_BAR];
int rc;
rc = ata_pci_device_do_resume(pdev);
if (rc)
return rc;
if (pdev->dev.power.power_state.event == PM_EVENT_SUSPEND)
writel(HOST_CTRL_GLOBAL_RST, host_base + HOST_CTRL);
sil24_init_controller(host);
ata_host_resume(host);
return 0;
}
static int sil24_port_resume(struct ata_port *ap)
{
sil24_config_pmp(ap, ap->nr_pmp_links);
return 0;
}
