static int adma_check_atapi_dma(struct ata_queued_cmd *qc)
{
return 1;
}
static void adma_reset_engine(struct ata_port *ap)
{
void __iomem *chan = ADMA_PORT_REGS(ap);
writew(aPIOMD4 | aNIEN | aRSTADM, chan + ADMA_CONTROL);
udelay(2);
writew(aPIOMD4, chan + ADMA_CONTROL);
udelay(2);
}
static void adma_reinit_engine(struct ata_port *ap)
{
struct adma_port_priv *pp = ap->private_data;
void __iomem *chan = ADMA_PORT_REGS(ap);
writeb(ATA_NIEN, ap->ioaddr.ctl_addr);
ata_sff_check_status(ap);
adma_reset_engine(ap);
writew(0x100, chan + ADMA_FIFO_IN);
writel((u32)pp->pkt_dma, chan + ADMA_CPB_NEXT);
writew(0x100, chan + ADMA_FIFO_OUT);
writew(1, chan + ADMA_CPB_COUNT);
readb(chan + ADMA_STATUS);
}
static inline void adma_enter_reg_mode(struct ata_port *ap)
{
void __iomem *chan = ADMA_PORT_REGS(ap);
writew(aPIOMD4, chan + ADMA_CONTROL);
readb(chan + ADMA_STATUS);
}
static void adma_freeze(struct ata_port *ap)
{
void __iomem *chan = ADMA_PORT_REGS(ap);
writeb(ATA_NIEN, ap->ioaddr.ctl_addr);
ata_sff_check_status(ap);
writew(aPIOMD4 | aNIEN | aRSTADM, chan + ADMA_CONTROL);
udelay(2);
writew(aPIOMD4 | aNIEN, chan + ADMA_CONTROL);
udelay(2);
}
static void adma_thaw(struct ata_port *ap)
{
adma_reinit_engine(ap);
}
static int adma_prereset(struct ata_link *link, unsigned long deadline)
{
struct ata_port *ap = link->ap;
struct adma_port_priv *pp = ap->private_data;
if (pp->state != adma_state_idle)
pp->state = adma_state_mmio;
adma_reinit_engine(ap);
return ata_sff_prereset(link, deadline);
}
static int adma_fill_sg(struct ata_queued_cmd *qc)
{
struct scatterlist *sg;
struct ata_port *ap = qc->ap;
struct adma_port_priv *pp = ap->private_data;
u8 *buf = pp->pkt, *last_buf = NULL;
int i = (2 + buf[3]) * 8;
u8 pFLAGS = pORD | ((qc->tf.flags & ATA_TFLAG_WRITE) ? pDIRO : 0);
unsigned int si;
for_each_sg(qc->sg, sg, qc->n_elem, si) {
u32 addr;
u32 len;
addr = (u32)sg_dma_address(sg);
*(__le32 *)(buf + i) = cpu_to_le32(addr);
i += 4;
len = sg_dma_len(sg) >> 3;
*(__le32 *)(buf + i) = cpu_to_le32(len);
i += 4;
last_buf = &buf[i];
buf[i++] = pFLAGS;
buf[i++] = qc->dev->dma_mode & 0xf;
buf[i++] = 0;
buf[i++] = 0;
*(__le32 *)(buf + i) =
(pFLAGS & pEND) ? 0 : cpu_to_le32(pp->pkt_dma + i + 4);
i += 4;
VPRINTK("PRD[%u] = (0x%lX, 0x%X)\n", i/4,
(unsigned long)addr, len);
}
if (likely(last_buf))
*last_buf |= pEND;
return i;
}
static void adma_qc_prep(struct ata_queued_cmd *qc)
{
struct adma_port_priv *pp = qc->ap->private_data;
u8 *buf = pp->pkt;
u32 pkt_dma = (u32)pp->pkt_dma;
int i = 0;
VPRINTK("ENTER\n");
adma_enter_reg_mode(qc->ap);
if (qc->tf.protocol != ATA_PROT_DMA)
return;
buf[i++] = 0;
buf[i++] = 0;
buf[i++] = cVLD | cDAT | cIEN;
i++;
*(__le32 *)(buf+i) = cpu_to_le32(pkt_dma);
i += 4;
i += 4;
buf[i++] = 0;
buf[i++] = 0;
buf[i++] = 0;
buf[i++] = 0;
buf[i++] = qc->tf.device;
buf[i++] = ADMA_REGS_DEVICE;
if ((qc->tf.flags & ATA_TFLAG_LBA48)) {
buf[i++] = qc->tf.hob_nsect;
buf[i++] = ADMA_REGS_SECTOR_COUNT;
buf[i++] = qc->tf.hob_lbal;
buf[i++] = ADMA_REGS_LBA_LOW;
buf[i++] = qc->tf.hob_lbam;
buf[i++] = ADMA_REGS_LBA_MID;
buf[i++] = qc->tf.hob_lbah;
buf[i++] = ADMA_REGS_LBA_HIGH;
}
buf[i++] = qc->tf.nsect;
buf[i++] = ADMA_REGS_SECTOR_COUNT;
buf[i++] = qc->tf.lbal;
buf[i++] = ADMA_REGS_LBA_LOW;
buf[i++] = qc->tf.lbam;
buf[i++] = ADMA_REGS_LBA_MID;
buf[i++] = qc->tf.lbah;
buf[i++] = ADMA_REGS_LBA_HIGH;
buf[i++] = 0;
buf[i++] = ADMA_REGS_CONTROL;
buf[i++] = rIGN;
buf[i++] = 0;
buf[i++] = qc->tf.command;
buf[i++] = ADMA_REGS_COMMAND | rEND;
buf[3] = (i >> 3) - 2;
*(__le32 *)(buf+8) = cpu_to_le32(pkt_dma + i);
i = adma_fill_sg(qc);
wmb();
#if 0
{
int j, len = 0;
static char obuf[2048];
for (j = 0; j < i; ++j) {
len += sprintf(obuf+len, "%02x ", buf[j]);
if ((j & 7) == 7) {
printk("%s\n", obuf);
len = 0;
}
}
if (len)
printk("%s\n", obuf);
}
#endif
}
static inline void adma_packet_start(struct ata_queued_cmd *qc)
{
struct ata_port *ap = qc->ap;
void __iomem *chan = ADMA_PORT_REGS(ap);
VPRINTK("ENTER, ap %p\n", ap);
writew(aPIOMD4 | aGO, chan + ADMA_CONTROL);
}
static unsigned int adma_qc_issue(struct ata_queued_cmd *qc)
{
struct adma_port_priv *pp = qc->ap->private_data;
switch (qc->tf.protocol) {
case ATA_PROT_DMA:
pp->state = adma_state_pkt;
adma_packet_start(qc);
return 0;
case ATAPI_PROT_DMA:
BUG();
break;
default:
break;
}
pp->state = adma_state_mmio;
return ata_sff_qc_issue(qc);
}
static inline unsigned int adma_intr_pkt(struct ata_host *host)
{
unsigned int handled = 0, port_no;
for (port_no = 0; port_no < host->n_ports; ++port_no) {
struct ata_port *ap = host->ports[port_no];
struct adma_port_priv *pp;
struct ata_queued_cmd *qc;
void __iomem *chan = ADMA_PORT_REGS(ap);
u8 status = readb(chan + ADMA_STATUS);
if (status == 0)
continue;
handled = 1;
adma_enter_reg_mode(ap);
pp = ap->private_data;
if (!pp || pp->state != adma_state_pkt)
continue;
qc = ata_qc_from_tag(ap, ap->link.active_tag);
if (qc && (!(qc->tf.flags & ATA_TFLAG_POLLING))) {
if (status & aPERR)
qc->err_mask |= AC_ERR_HOST_BUS;
else if ((status & (aPSD | aUIRQ)))
qc->err_mask |= AC_ERR_OTHER;
if (pp->pkt[0] & cATERR)
qc->err_mask |= AC_ERR_DEV;
else if (pp->pkt[0] != cDONE)
qc->err_mask |= AC_ERR_OTHER;
if (!qc->err_mask)
ata_qc_complete(qc);
else {
struct ata_eh_info *ehi = &ap->link.eh_info;
ata_ehi_clear_desc(ehi);
ata_ehi_push_desc(ehi,
"ADMA-status 0x%02X", status);
ata_ehi_push_desc(ehi,
"pkt[0] 0x%02X", pp->pkt[0]);
if (qc->err_mask == AC_ERR_DEV)
ata_port_abort(ap);
else
ata_port_freeze(ap);
}
}
}
return handled;
}
static inline unsigned int adma_intr_mmio(struct ata_host *host)
{
unsigned int handled = 0, port_no;
for (port_no = 0; port_no < host->n_ports; ++port_no) {
struct ata_port *ap = host->ports[port_no];
struct adma_port_priv *pp = ap->private_data;
struct ata_queued_cmd *qc;
if (!pp || pp->state != adma_state_mmio)
continue;
qc = ata_qc_from_tag(ap, ap->link.active_tag);
if (qc && (!(qc->tf.flags & ATA_TFLAG_POLLING))) {
u8 status = ata_sff_check_status(ap);
if ((status & ATA_BUSY))
continue;
DPRINTK("ata%u: protocol %d (dev_stat 0x%X)\n",
ap->print_id, qc->tf.protocol, status);
pp->state = adma_state_idle;
qc->err_mask |= ac_err_mask(status);
if (!qc->err_mask)
ata_qc_complete(qc);
else {
struct ata_eh_info *ehi = &ap->link.eh_info;
ata_ehi_clear_desc(ehi);
ata_ehi_push_desc(ehi, "status 0x%02X", status);
if (qc->err_mask == AC_ERR_DEV)
ata_port_abort(ap);
else
ata_port_freeze(ap);
}
handled = 1;
}
}
return handled;
}
static irqreturn_t adma_intr(int irq, void *dev_instance)
{
struct ata_host *host = dev_instance;
unsigned int handled = 0;
VPRINTK("ENTER\n");
spin_lock(&host->lock);
handled = adma_intr_pkt(host) | adma_intr_mmio(host);
spin_unlock(&host->lock);
VPRINTK("EXIT\n");
return IRQ_RETVAL(handled);
}
static void adma_ata_setup_port(struct ata_ioports *port, void __iomem *base)
{
port->cmd_addr =
port->data_addr = base + 0x000;
port->error_addr =
port->feature_addr = base + 0x004;
port->nsect_addr = base + 0x008;
port->lbal_addr = base + 0x00c;
port->lbam_addr = base + 0x010;
port->lbah_addr = base + 0x014;
port->device_addr = base + 0x018;
port->status_addr =
port->command_addr = base + 0x01c;
port->altstatus_addr =
port->ctl_addr = base + 0x038;
}
static int adma_port_start(struct ata_port *ap)
{
struct device *dev = ap->host->dev;
struct adma_port_priv *pp;
adma_enter_reg_mode(ap);
pp = devm_kzalloc(dev, sizeof(*pp), GFP_KERNEL);
if (!pp)
return -ENOMEM;
pp->pkt = dmam_alloc_coherent(dev, ADMA_PKT_BYTES, &pp->pkt_dma,
GFP_KERNEL);
if (!pp->pkt)
return -ENOMEM;
if ((pp->pkt_dma & 7) != 0) {
printk(KERN_ERR "bad alignment for pp->pkt_dma: %08x\n",
(u32)pp->pkt_dma);
return -ENOMEM;
}
memset(pp->pkt, 0, ADMA_PKT_BYTES);
ap->private_data = pp;
adma_reinit_engine(ap);
return 0;
}
static void adma_port_stop(struct ata_port *ap)
{
adma_reset_engine(ap);
}
static void adma_host_init(struct ata_host *host, unsigned int chip_id)
{
unsigned int port_no;
writeb(7, host->iomap[ADMA_MMIO_BAR] + ADMA_MODE_LOCK);
for (port_no = 0; port_no < ADMA_PORTS; ++port_no)
adma_reset_engine(host->ports[port_no]);
}
static int adma_set_dma_masks(struct pci_dev *pdev, void __iomem *mmio_base)
{
int rc;
rc = dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev, "32-bit DMA enable failed\n");
return rc;
}
rc = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (rc) {
dev_err(&pdev->dev, "32-bit consistent DMA enable failed\n");
return rc;
}
return 0;
}
static int adma_ata_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
unsigned int board_idx = (unsigned int) ent->driver_data;
const struct ata_port_info *ppi[] = { &adma_port_info[board_idx], NULL };
struct ata_host *host;
void __iomem *mmio_base;
int rc, port_no;
ata_print_version_once(&pdev->dev, DRV_VERSION);
host = ata_host_alloc_pinfo(&pdev->dev, ppi, ADMA_PORTS);
if (!host)
return -ENOMEM;
rc = pcim_enable_device(pdev);
if (rc)
return rc;
if ((pci_resource_flags(pdev, 4) & IORESOURCE_MEM) == 0)
return -ENODEV;
rc = pcim_iomap_regions(pdev, 1 << ADMA_MMIO_BAR, DRV_NAME);
if (rc)
return rc;
host->iomap = pcim_iomap_table(pdev);
mmio_base = host->iomap[ADMA_MMIO_BAR];
rc = adma_set_dma_masks(pdev, mmio_base);
if (rc)
return rc;
for (port_no = 0; port_no < ADMA_PORTS; ++port_no) {
struct ata_port *ap = host->ports[port_no];
void __iomem *port_base = ADMA_ATA_REGS(mmio_base, port_no);
unsigned int offset = port_base - mmio_base;
adma_ata_setup_port(&ap->ioaddr, port_base);
ata_port_pbar_desc(ap, ADMA_MMIO_BAR, -1, "mmio");
ata_port_pbar_desc(ap, ADMA_MMIO_BAR, offset, "port");
}
adma_host_init(host, board_idx);
pci_set_master(pdev);
return ata_host_activate(host, pdev->irq, adma_intr, IRQF_SHARED,
&adma_ata_sht);
}
