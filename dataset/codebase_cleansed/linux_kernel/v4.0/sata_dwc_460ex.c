static const char *get_prot_descript(u8 protocol)
{
switch ((enum ata_tf_protocols)protocol) {
case ATA_PROT_NODATA:
return "ATA no data";
case ATA_PROT_PIO:
return "ATA PIO";
case ATA_PROT_DMA:
return "ATA DMA";
case ATA_PROT_NCQ:
return "ATA NCQ";
case ATAPI_PROT_NODATA:
return "ATAPI no data";
case ATAPI_PROT_PIO:
return "ATAPI PIO";
case ATAPI_PROT_DMA:
return "ATAPI DMA";
default:
return "unknown";
}
}
static const char *get_dma_dir_descript(int dma_dir)
{
switch ((enum dma_data_direction)dma_dir) {
case DMA_BIDIRECTIONAL:
return "bidirectional";
case DMA_TO_DEVICE:
return "to device";
case DMA_FROM_DEVICE:
return "from device";
default:
return "none";
}
}
static void sata_dwc_tf_dump(struct ata_taskfile *tf)
{
dev_vdbg(host_pvt.dwc_dev, "taskfile cmd: 0x%02x protocol: %s flags:"
"0x%lx device: %x\n", tf->command,
get_prot_descript(tf->protocol), tf->flags, tf->device);
dev_vdbg(host_pvt.dwc_dev, "feature: 0x%02x nsect: 0x%x lbal: 0x%x "
"lbam: 0x%x lbah: 0x%x\n", tf->feature, tf->nsect, tf->lbal,
tf->lbam, tf->lbah);
dev_vdbg(host_pvt.dwc_dev, "hob_feature: 0x%02x hob_nsect: 0x%x "
"hob_lbal: 0x%x hob_lbam: 0x%x hob_lbah: 0x%x\n",
tf->hob_feature, tf->hob_nsect, tf->hob_lbal, tf->hob_lbam,
tf->hob_lbah);
}
static int get_burst_length_encode(int datalength)
{
int items = datalength >> 2;
if (items >= 64)
return 5;
if (items >= 32)
return 4;
if (items >= 16)
return 3;
if (items >= 8)
return 2;
if (items >= 4)
return 1;
return 0;
}
static void clear_chan_interrupts(int c)
{
out_le32(&(host_pvt.sata_dma_regs->interrupt_clear.tfr.low),
DMA_CHANNEL(c));
out_le32(&(host_pvt.sata_dma_regs->interrupt_clear.block.low),
DMA_CHANNEL(c));
out_le32(&(host_pvt.sata_dma_regs->interrupt_clear.srctran.low),
DMA_CHANNEL(c));
out_le32(&(host_pvt.sata_dma_regs->interrupt_clear.dsttran.low),
DMA_CHANNEL(c));
out_le32(&(host_pvt.sata_dma_regs->interrupt_clear.error.low),
DMA_CHANNEL(c));
}
static int dma_request_channel(void)
{
if (!(in_le32(&(host_pvt.sata_dma_regs->dma_chan_en.low)) &
DMA_CHANNEL(host_pvt.dma_channel)))
return host_pvt.dma_channel;
dev_err(host_pvt.dwc_dev, "%s Channel %d is currently in use\n",
__func__, host_pvt.dma_channel);
return -1;
}
static irqreturn_t dma_dwc_interrupt(int irq, void *hsdev_instance)
{
int chan;
u32 tfr_reg, err_reg;
unsigned long flags;
struct sata_dwc_device *hsdev = hsdev_instance;
struct ata_host *host = (struct ata_host *)hsdev->host;
struct ata_port *ap;
struct sata_dwc_device_port *hsdevp;
u8 tag = 0;
unsigned int port = 0;
spin_lock_irqsave(&host->lock, flags);
ap = host->ports[port];
hsdevp = HSDEVP_FROM_AP(ap);
tag = ap->link.active_tag;
tfr_reg = in_le32(&(host_pvt.sata_dma_regs->interrupt_status.tfr\
.low));
err_reg = in_le32(&(host_pvt.sata_dma_regs->interrupt_status.error\
.low));
dev_dbg(ap->dev, "eot=0x%08x err=0x%08x pending=%d active port=%d\n",
tfr_reg, err_reg, hsdevp->dma_pending[tag], port);
chan = host_pvt.dma_channel;
if (chan >= 0) {
if (tfr_reg & DMA_CHANNEL(chan)) {
host_pvt.dma_interrupt_count++;
sata_dwc_clear_dmacr(hsdevp, tag);
if (hsdevp->dma_pending[tag] ==
SATA_DWC_DMA_PENDING_NONE) {
dev_err(ap->dev, "DMA not pending eot=0x%08x "
"err=0x%08x tag=0x%02x pending=%d\n",
tfr_reg, err_reg, tag,
hsdevp->dma_pending[tag]);
}
if ((host_pvt.dma_interrupt_count % 2) == 0)
sata_dwc_dma_xfer_complete(ap, 1);
out_le32(&(host_pvt.sata_dma_regs->interrupt_clear\
.tfr.low),
DMA_CHANNEL(chan));
}
if (err_reg & DMA_CHANNEL(chan)) {
dev_err(ap->dev, "error interrupt err_reg=0x%08x\n",
err_reg);
out_le32(&(host_pvt.sata_dma_regs->interrupt_clear\
.error.low),
DMA_CHANNEL(chan));
}
}
spin_unlock_irqrestore(&host->lock, flags);
return IRQ_HANDLED;
}
static int dma_request_interrupts(struct sata_dwc_device *hsdev, int irq)
{
int retval = 0;
int chan = host_pvt.dma_channel;
if (chan >= 0) {
out_le32(&(host_pvt.sata_dma_regs)->interrupt_mask.error.low,
DMA_ENABLE_CHAN(chan));
out_le32(&(host_pvt.sata_dma_regs)->interrupt_mask.tfr.low,
DMA_ENABLE_CHAN(chan));
}
retval = request_irq(irq, dma_dwc_interrupt, 0, "SATA DMA", hsdev);
if (retval) {
dev_err(host_pvt.dwc_dev, "%s: could not get IRQ %d\n",
__func__, irq);
return -ENODEV;
}
hsdev->irq_dma = irq;
return 0;
}
static int map_sg_to_lli(struct scatterlist *sg, int num_elems,
struct lli *lli, dma_addr_t dma_lli,
void __iomem *dmadr_addr, int dir)
{
int i, idx = 0;
int fis_len = 0;
dma_addr_t next_llp;
int bl;
int sms_val, dms_val;
sms_val = 0;
dms_val = 1 + host_pvt.dma_channel;
dev_dbg(host_pvt.dwc_dev,
"%s: sg=%p nelem=%d lli=%p dma_lli=0x%pad dmadr=0x%p\n",
__func__, sg, num_elems, lli, &dma_lli, dmadr_addr);
bl = get_burst_length_encode(AHB_DMA_BRST_DFLT);
for (i = 0; i < num_elems; i++, sg++) {
u32 addr, offset;
u32 sg_len, len;
addr = (u32) sg_dma_address(sg);
sg_len = sg_dma_len(sg);
dev_dbg(host_pvt.dwc_dev, "%s: elem=%d sg_addr=0x%x sg_len"
"=%d\n", __func__, i, addr, sg_len);
while (sg_len) {
if (idx >= SATA_DWC_DMAC_LLI_NUM) {
dev_err(host_pvt.dwc_dev, "LLI table overrun "
"(idx=%d)\n", idx);
break;
}
len = (sg_len > SATA_DWC_DMAC_CTRL_TSIZE_MAX) ?
SATA_DWC_DMAC_CTRL_TSIZE_MAX : sg_len;
offset = addr & 0xffff;
if ((offset + sg_len) > 0x10000)
len = 0x10000 - offset;
if (fis_len + len > 8192) {
dev_dbg(host_pvt.dwc_dev, "SPLITTING: fis_len="
"%d(0x%x) len=%d(0x%x)\n", fis_len,
fis_len, len, len);
len = 8192 - fis_len;
fis_len = 0;
} else {
fis_len += len;
}
if (fis_len == 8192)
fis_len = 0;
if (dir == DMA_FROM_DEVICE) {
lli[idx].dar = cpu_to_le32(addr);
lli[idx].sar = cpu_to_le32((u32)dmadr_addr);
lli[idx].ctl.low = cpu_to_le32(
DMA_CTL_TTFC(DMA_CTL_TTFC_P2M_DMAC) |
DMA_CTL_SMS(sms_val) |
DMA_CTL_DMS(dms_val) |
DMA_CTL_SRC_MSIZE(bl) |
DMA_CTL_DST_MSIZE(bl) |
DMA_CTL_SINC_NOCHANGE |
DMA_CTL_SRC_TRWID(2) |
DMA_CTL_DST_TRWID(2) |
DMA_CTL_INT_EN |
DMA_CTL_LLP_SRCEN |
DMA_CTL_LLP_DSTEN);
} else {
lli[idx].sar = cpu_to_le32(addr);
lli[idx].dar = cpu_to_le32((u32)dmadr_addr);
lli[idx].ctl.low = cpu_to_le32(
DMA_CTL_TTFC(DMA_CTL_TTFC_M2P_PER) |
DMA_CTL_SMS(dms_val) |
DMA_CTL_DMS(sms_val) |
DMA_CTL_SRC_MSIZE(bl) |
DMA_CTL_DST_MSIZE(bl) |
DMA_CTL_DINC_NOCHANGE |
DMA_CTL_SRC_TRWID(2) |
DMA_CTL_DST_TRWID(2) |
DMA_CTL_INT_EN |
DMA_CTL_LLP_SRCEN |
DMA_CTL_LLP_DSTEN);
}
dev_dbg(host_pvt.dwc_dev, "%s setting ctl.high len: "
"0x%08x val: 0x%08x\n", __func__,
len, DMA_CTL_BLK_TS(len / 4));
lli[idx].ctl.high = cpu_to_le32(DMA_CTL_BLK_TS\
(len / 4));
next_llp = (dma_lli + ((idx + 1) * sizeof(struct \
lli)));
next_llp = DMA_LLP_LMS(next_llp, DMA_LLP_AHBMASTER2);
lli[idx].llp = cpu_to_le32(next_llp);
idx++;
sg_len -= len;
addr += len;
}
}
if (idx) {
lli[idx-1].llp = 0x00000000;
lli[idx-1].ctl.low &= DMA_CTL_LLP_DISABLE_LE32;
dma_cache_sync(NULL, lli, (sizeof(struct lli) * idx),
DMA_BIDIRECTIONAL);
}
return idx;
}
static void dma_dwc_xfer_start(int dma_ch)
{
out_le32(&(host_pvt.sata_dma_regs->dma_chan_en.low),
in_le32(&(host_pvt.sata_dma_regs->dma_chan_en.low)) |
DMA_ENABLE_CHAN(dma_ch));
}
static int dma_dwc_xfer_setup(struct scatterlist *sg, int num_elems,
struct lli *lli, dma_addr_t dma_lli,
void __iomem *addr, int dir)
{
int dma_ch;
int num_lli;
dma_ch = dma_request_channel();
if (dma_ch == -1) {
dev_err(host_pvt.dwc_dev, "%s: dma channel unavailable\n",
__func__);
return -EAGAIN;
}
num_lli = map_sg_to_lli(sg, num_elems, lli, dma_lli, addr, dir);
dev_dbg(host_pvt.dwc_dev, "%s sg: 0x%p, count: %d lli: %p dma_lli:"
" 0x%0xlx addr: %p lli count: %d\n", __func__, sg, num_elems,
lli, (u32)dma_lli, addr, num_lli);
clear_chan_interrupts(dma_ch);
out_le32(&(host_pvt.sata_dma_regs->chan_regs[dma_ch].cfg.high),
DMA_CFG_HW_HS_SRC(dma_ch) | DMA_CFG_HW_HS_DEST(dma_ch) |
DMA_CFG_PROTCTL | DMA_CFG_FCMOD_REQ);
out_le32(&(host_pvt.sata_dma_regs->chan_regs[dma_ch].cfg.low),
DMA_CFG_HW_CH_PRIOR(dma_ch));
out_le32(&(host_pvt.sata_dma_regs->chan_regs[dma_ch].llp.low),
DMA_LLP_LMS(dma_lli, DMA_LLP_AHBMASTER2));
out_le32(&(host_pvt.sata_dma_regs->chan_regs[dma_ch].ctl.low),
DMA_CTL_LLP_SRCEN | DMA_CTL_LLP_DSTEN);
return dma_ch;
}
static void dma_dwc_exit(struct sata_dwc_device *hsdev)
{
dev_dbg(host_pvt.dwc_dev, "%s:\n", __func__);
if (host_pvt.sata_dma_regs) {
iounmap((void __iomem *)host_pvt.sata_dma_regs);
host_pvt.sata_dma_regs = NULL;
}
if (hsdev->irq_dma) {
free_irq(hsdev->irq_dma, hsdev);
hsdev->irq_dma = 0;
}
}
static int dma_dwc_init(struct sata_dwc_device *hsdev, int irq)
{
int err;
err = dma_request_interrupts(hsdev, irq);
if (err) {
dev_err(host_pvt.dwc_dev, "%s: dma_request_interrupts returns"
" %d\n", __func__, err);
return err;
}
out_le32(&(host_pvt.sata_dma_regs->dma_cfg.low), DMA_EN);
dev_notice(host_pvt.dwc_dev, "DMA initialized\n");
dev_dbg(host_pvt.dwc_dev, "SATA DMA registers=0x%p\n", host_pvt.\
sata_dma_regs);
return 0;
}
static int sata_dwc_scr_read(struct ata_link *link, unsigned int scr, u32 *val)
{
if (scr > SCR_NOTIFICATION) {
dev_err(link->ap->dev, "%s: Incorrect SCR offset 0x%02x\n",
__func__, scr);
return -EINVAL;
}
*val = in_le32(link->ap->ioaddr.scr_addr + (scr * 4));
dev_dbg(link->ap->dev, "%s: id=%d reg=%d val=val=0x%08x\n",
__func__, link->ap->print_id, scr, *val);
return 0;
}
static int sata_dwc_scr_write(struct ata_link *link, unsigned int scr, u32 val)
{
dev_dbg(link->ap->dev, "%s: id=%d reg=%d val=val=0x%08x\n",
__func__, link->ap->print_id, scr, val);
if (scr > SCR_NOTIFICATION) {
dev_err(link->ap->dev, "%s: Incorrect SCR offset 0x%02x\n",
__func__, scr);
return -EINVAL;
}
out_le32(link->ap->ioaddr.scr_addr + (scr * 4), val);
return 0;
}
static u32 core_scr_read(unsigned int scr)
{
return in_le32(host_pvt.scr_addr_sstatus + (scr * 4));
}
static void core_scr_write(unsigned int scr, u32 val)
{
out_le32(host_pvt.scr_addr_sstatus + (scr * 4), val);
}
static void clear_serror(void)
{
u32 val;
val = core_scr_read(SCR_ERROR);
core_scr_write(SCR_ERROR, val);
}
static void clear_interrupt_bit(struct sata_dwc_device *hsdev, u32 bit)
{
out_le32(&hsdev->sata_dwc_regs->intpr,
in_le32(&hsdev->sata_dwc_regs->intpr));
}
static u32 qcmd_tag_to_mask(u8 tag)
{
return 0x00000001 << (tag & 0x1f);
}
static void sata_dwc_error_intr(struct ata_port *ap,
struct sata_dwc_device *hsdev, uint intpr)
{
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
struct ata_eh_info *ehi = &ap->link.eh_info;
unsigned int err_mask = 0, action = 0;
struct ata_queued_cmd *qc;
u32 serror;
u8 status, tag;
u32 err_reg;
ata_ehi_clear_desc(ehi);
serror = core_scr_read(SCR_ERROR);
status = ap->ops->sff_check_status(ap);
err_reg = in_le32(&(host_pvt.sata_dma_regs->interrupt_status.error.\
low));
tag = ap->link.active_tag;
dev_err(ap->dev, "%s SCR_ERROR=0x%08x intpr=0x%08x status=0x%08x "
"dma_intp=%d pending=%d issued=%d dma_err_status=0x%08x\n",
__func__, serror, intpr, status, host_pvt.dma_interrupt_count,
hsdevp->dma_pending[tag], hsdevp->cmd_issued[tag], err_reg);
clear_serror();
clear_interrupt_bit(hsdev, SATA_DWC_INTPR_ERR);
err_mask |= AC_ERR_HOST_BUS;
action |= ATA_EH_RESET;
ehi->serror |= serror;
ehi->action |= action;
qc = ata_qc_from_tag(ap, tag);
if (qc)
qc->err_mask |= err_mask;
else
ehi->err_mask |= err_mask;
ata_port_abort(ap);
}
static irqreturn_t sata_dwc_isr(int irq, void *dev_instance)
{
struct ata_host *host = (struct ata_host *)dev_instance;
struct sata_dwc_device *hsdev = HSDEV_FROM_HOST(host);
struct ata_port *ap;
struct ata_queued_cmd *qc;
unsigned long flags;
u8 status, tag;
int handled, num_processed, port = 0;
uint intpr, sactive, sactive2, tag_mask;
struct sata_dwc_device_port *hsdevp;
host_pvt.sata_dwc_sactive_issued = 0;
spin_lock_irqsave(&host->lock, flags);
intpr = in_le32(&hsdev->sata_dwc_regs->intpr);
ap = host->ports[port];
hsdevp = HSDEVP_FROM_AP(ap);
dev_dbg(ap->dev, "%s intpr=0x%08x active_tag=%d\n", __func__, intpr,
ap->link.active_tag);
if (intpr & SATA_DWC_INTPR_ERR) {
sata_dwc_error_intr(ap, hsdev, intpr);
handled = 1;
goto DONE;
}
if (intpr & SATA_DWC_INTPR_NEWFP) {
clear_interrupt_bit(hsdev, SATA_DWC_INTPR_NEWFP);
tag = (u8)(in_le32(&hsdev->sata_dwc_regs->fptagr));
dev_dbg(ap->dev, "%s: NEWFP tag=%d\n", __func__, tag);
if (hsdevp->cmd_issued[tag] != SATA_DWC_CMD_ISSUED_PEND)
dev_warn(ap->dev, "CMD tag=%d not pending?\n", tag);
host_pvt.sata_dwc_sactive_issued |= qcmd_tag_to_mask(tag);
qc = ata_qc_from_tag(ap, tag);
qc->ap->link.active_tag = tag;
sata_dwc_bmdma_start_by_tag(qc, tag);
handled = 1;
goto DONE;
}
sactive = core_scr_read(SCR_ACTIVE);
tag_mask = (host_pvt.sata_dwc_sactive_issued | sactive) ^ sactive;
if (host_pvt.sata_dwc_sactive_issued == 0 && tag_mask == 0) {
if (ap->link.active_tag == ATA_TAG_POISON)
tag = 0;
else
tag = ap->link.active_tag;
qc = ata_qc_from_tag(ap, tag);
if (unlikely(!qc || (qc->tf.flags & ATA_TFLAG_POLLING))) {
dev_err(ap->dev, "%s interrupt with no active qc "
"qc=%p\n", __func__, qc);
ap->ops->sff_check_status(ap);
handled = 1;
goto DONE;
}
status = ap->ops->sff_check_status(ap);
qc->ap->link.active_tag = tag;
hsdevp->cmd_issued[tag] = SATA_DWC_CMD_ISSUED_NOT;
if (status & ATA_ERR) {
dev_dbg(ap->dev, "interrupt ATA_ERR (0x%x)\n", status);
sata_dwc_qc_complete(ap, qc, 1);
handled = 1;
goto DONE;
}
dev_dbg(ap->dev, "%s non-NCQ cmd interrupt, protocol: %s\n",
__func__, get_prot_descript(qc->tf.protocol));
DRVSTILLBUSY:
if (ata_is_dma(qc->tf.protocol)) {
host_pvt.dma_interrupt_count++;
if (hsdevp->dma_pending[tag] == \
SATA_DWC_DMA_PENDING_NONE) {
dev_err(ap->dev, "%s: DMA not pending "
"intpr=0x%08x status=0x%08x pending"
"=%d\n", __func__, intpr, status,
hsdevp->dma_pending[tag]);
}
if ((host_pvt.dma_interrupt_count % 2) == 0)
sata_dwc_dma_xfer_complete(ap, 1);
} else if (ata_is_pio(qc->tf.protocol)) {
ata_sff_hsm_move(ap, qc, status, 0);
handled = 1;
goto DONE;
} else {
if (unlikely(sata_dwc_qc_complete(ap, qc, 1)))
goto DRVSTILLBUSY;
}
handled = 1;
goto DONE;
}
sactive = core_scr_read(SCR_ACTIVE);
tag_mask = (host_pvt.sata_dwc_sactive_issued | sactive) ^ sactive;
if (sactive != 0 || (host_pvt.sata_dwc_sactive_issued) > 1 || \
tag_mask > 1) {
dev_dbg(ap->dev, "%s NCQ:sactive=0x%08x sactive_issued=0x%08x"
"tag_mask=0x%08x\n", __func__, sactive,
host_pvt.sata_dwc_sactive_issued, tag_mask);
}
if ((tag_mask | (host_pvt.sata_dwc_sactive_issued)) != \
(host_pvt.sata_dwc_sactive_issued)) {
dev_warn(ap->dev, "Bad tag mask? sactive=0x%08x "
"(host_pvt.sata_dwc_sactive_issued)=0x%08x tag_mask"
"=0x%08x\n", sactive, host_pvt.sata_dwc_sactive_issued,
tag_mask);
}
status = ap->ops->sff_check_status(ap);
dev_dbg(ap->dev, "%s ATA status register=0x%x\n", __func__, status);
tag = 0;
num_processed = 0;
while (tag_mask) {
num_processed++;
while (!(tag_mask & 0x00000001)) {
tag++;
tag_mask <<= 1;
}
tag_mask &= (~0x00000001);
qc = ata_qc_from_tag(ap, tag);
qc->ap->link.active_tag = tag;
hsdevp->cmd_issued[tag] = SATA_DWC_CMD_ISSUED_NOT;
if (status & ATA_ERR) {
dev_dbg(ap->dev, "%s ATA_ERR (0x%x)\n", __func__,
status);
sata_dwc_qc_complete(ap, qc, 1);
handled = 1;
goto DONE;
}
dev_dbg(ap->dev, "%s NCQ command, protocol: %s\n", __func__,
get_prot_descript(qc->tf.protocol));
if (ata_is_dma(qc->tf.protocol)) {
host_pvt.dma_interrupt_count++;
if (hsdevp->dma_pending[tag] == \
SATA_DWC_DMA_PENDING_NONE)
dev_warn(ap->dev, "%s: DMA not pending?\n",
__func__);
if ((host_pvt.dma_interrupt_count % 2) == 0)
sata_dwc_dma_xfer_complete(ap, 1);
} else {
if (unlikely(sata_dwc_qc_complete(ap, qc, 1)))
goto STILLBUSY;
}
continue;
STILLBUSY:
ap->stats.idle_irq++;
dev_warn(ap->dev, "STILL BUSY IRQ ata%d: irq trap\n",
ap->print_id);
}
sactive2 = core_scr_read(SCR_ACTIVE);
if (sactive2 != sactive) {
dev_dbg(ap->dev, "More completed - sactive=0x%x sactive2"
"=0x%x\n", sactive, sactive2);
}
handled = 1;
DONE:
spin_unlock_irqrestore(&host->lock, flags);
return IRQ_RETVAL(handled);
}
static void sata_dwc_clear_dmacr(struct sata_dwc_device_port *hsdevp, u8 tag)
{
struct sata_dwc_device *hsdev = HSDEV_FROM_HSDEVP(hsdevp);
if (hsdevp->dma_pending[tag] == SATA_DWC_DMA_PENDING_RX) {
out_le32(&(hsdev->sata_dwc_regs->dmacr),
SATA_DWC_DMACR_RX_CLEAR(
in_le32(&(hsdev->sata_dwc_regs->dmacr))));
} else if (hsdevp->dma_pending[tag] == SATA_DWC_DMA_PENDING_TX) {
out_le32(&(hsdev->sata_dwc_regs->dmacr),
SATA_DWC_DMACR_TX_CLEAR(
in_le32(&(hsdev->sata_dwc_regs->dmacr))));
} else {
dev_err(host_pvt.dwc_dev, "%s DMA protocol RX and"
"TX DMA not pending tag=0x%02x pending=%d"
" dmacr: 0x%08x\n", __func__, tag,
hsdevp->dma_pending[tag],
in_le32(&(hsdev->sata_dwc_regs->dmacr)));
out_le32(&(hsdev->sata_dwc_regs->dmacr),
SATA_DWC_DMACR_TXRXCH_CLEAR);
}
}
static void sata_dwc_dma_xfer_complete(struct ata_port *ap, u32 check_status)
{
struct ata_queued_cmd *qc;
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
struct sata_dwc_device *hsdev = HSDEV_FROM_AP(ap);
u8 tag = 0;
tag = ap->link.active_tag;
qc = ata_qc_from_tag(ap, tag);
if (!qc) {
dev_err(ap->dev, "failed to get qc");
return;
}
#ifdef DEBUG_NCQ
if (tag > 0) {
dev_info(ap->dev, "%s tag=%u cmd=0x%02x dma dir=%s proto=%s "
"dmacr=0x%08x\n", __func__, qc->tag, qc->tf.command,
get_dma_dir_descript(qc->dma_dir),
get_prot_descript(qc->tf.protocol),
in_le32(&(hsdev->sata_dwc_regs->dmacr)));
}
#endif
if (ata_is_dma(qc->tf.protocol)) {
if (hsdevp->dma_pending[tag] == SATA_DWC_DMA_PENDING_NONE) {
dev_err(ap->dev, "%s DMA protocol RX and TX DMA not "
"pending dmacr: 0x%08x\n", __func__,
in_le32(&(hsdev->sata_dwc_regs->dmacr)));
}
hsdevp->dma_pending[tag] = SATA_DWC_DMA_PENDING_NONE;
sata_dwc_qc_complete(ap, qc, check_status);
ap->link.active_tag = ATA_TAG_POISON;
} else {
sata_dwc_qc_complete(ap, qc, check_status);
}
}
static int sata_dwc_qc_complete(struct ata_port *ap, struct ata_queued_cmd *qc,
u32 check_status)
{
u8 status = 0;
u32 mask = 0x0;
u8 tag = qc->tag;
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
host_pvt.sata_dwc_sactive_queued = 0;
dev_dbg(ap->dev, "%s checkstatus? %x\n", __func__, check_status);
if (hsdevp->dma_pending[tag] == SATA_DWC_DMA_PENDING_TX)
dev_err(ap->dev, "TX DMA PENDING\n");
else if (hsdevp->dma_pending[tag] == SATA_DWC_DMA_PENDING_RX)
dev_err(ap->dev, "RX DMA PENDING\n");
dev_dbg(ap->dev, "QC complete cmd=0x%02x status=0x%02x ata%u:"
" protocol=%d\n", qc->tf.command, status, ap->print_id,
qc->tf.protocol);
mask = (~(qcmd_tag_to_mask(tag)));
host_pvt.sata_dwc_sactive_queued = (host_pvt.sata_dwc_sactive_queued) \
& mask;
host_pvt.sata_dwc_sactive_issued = (host_pvt.sata_dwc_sactive_issued) \
& mask;
ata_qc_complete(qc);
return 0;
}
static void sata_dwc_enable_interrupts(struct sata_dwc_device *hsdev)
{
out_le32(&hsdev->sata_dwc_regs->intmr,
SATA_DWC_INTMR_ERRM |
SATA_DWC_INTMR_NEWFPM |
SATA_DWC_INTMR_PMABRTM |
SATA_DWC_INTMR_DMATM);
out_le32(&hsdev->sata_dwc_regs->errmr, SATA_DWC_SERROR_ERR_BITS);
dev_dbg(host_pvt.dwc_dev, "%s: INTMR = 0x%08x, ERRMR = 0x%08x\n",
__func__, in_le32(&hsdev->sata_dwc_regs->intmr),
in_le32(&hsdev->sata_dwc_regs->errmr));
}
static void sata_dwc_setup_port(struct ata_ioports *port, unsigned long base)
{
port->cmd_addr = (void __iomem *)base + 0x00;
port->data_addr = (void __iomem *)base + 0x00;
port->error_addr = (void __iomem *)base + 0x04;
port->feature_addr = (void __iomem *)base + 0x04;
port->nsect_addr = (void __iomem *)base + 0x08;
port->lbal_addr = (void __iomem *)base + 0x0c;
port->lbam_addr = (void __iomem *)base + 0x10;
port->lbah_addr = (void __iomem *)base + 0x14;
port->device_addr = (void __iomem *)base + 0x18;
port->command_addr = (void __iomem *)base + 0x1c;
port->status_addr = (void __iomem *)base + 0x1c;
port->altstatus_addr = (void __iomem *)base + 0x20;
port->ctl_addr = (void __iomem *)base + 0x20;
}
static int sata_dwc_port_start(struct ata_port *ap)
{
int err = 0;
struct sata_dwc_device *hsdev;
struct sata_dwc_device_port *hsdevp = NULL;
struct device *pdev;
int i;
hsdev = HSDEV_FROM_AP(ap);
dev_dbg(ap->dev, "%s: port_no=%d\n", __func__, ap->port_no);
hsdev->host = ap->host;
pdev = ap->host->dev;
if (!pdev) {
dev_err(ap->dev, "%s: no ap->host->dev\n", __func__);
err = -ENODEV;
goto CLEANUP;
}
hsdevp = kzalloc(sizeof(*hsdevp), GFP_KERNEL);
if (!hsdevp) {
dev_err(ap->dev, "%s: kmalloc failed for hsdevp\n", __func__);
err = -ENOMEM;
goto CLEANUP;
}
hsdevp->hsdev = hsdev;
for (i = 0; i < SATA_DWC_QCMD_MAX; i++)
hsdevp->cmd_issued[i] = SATA_DWC_CMD_ISSUED_NOT;
ap->bmdma_prd = NULL;
ap->bmdma_prd_dma = 0;
for (i = 0; i < SATA_DWC_QCMD_MAX; i++) {
hsdevp->llit[i] = dma_alloc_coherent(pdev,
SATA_DWC_DMAC_LLI_TBL_SZ,
&(hsdevp->llit_dma[i]),
GFP_ATOMIC);
if (!hsdevp->llit[i]) {
dev_err(ap->dev, "%s: dma_alloc_coherent failed\n",
__func__);
err = -ENOMEM;
goto CLEANUP_ALLOC;
}
}
if (ap->port_no == 0) {
dev_dbg(ap->dev, "%s: clearing TXCHEN, RXCHEN in DMAC\n",
__func__);
out_le32(&hsdev->sata_dwc_regs->dmacr,
SATA_DWC_DMACR_TXRXCH_CLEAR);
dev_dbg(ap->dev, "%s: setting burst size in DBTSR\n",
__func__);
out_le32(&hsdev->sata_dwc_regs->dbtsr,
(SATA_DWC_DBTSR_MWR(AHB_DMA_BRST_DFLT) |
SATA_DWC_DBTSR_MRD(AHB_DMA_BRST_DFLT)));
}
clear_serror();
ap->private_data = hsdevp;
dev_dbg(ap->dev, "%s: done\n", __func__);
return 0;
CLEANUP_ALLOC:
kfree(hsdevp);
CLEANUP:
dev_dbg(ap->dev, "%s: fail. ap->id = %d\n", __func__, ap->print_id);
return err;
}
static void sata_dwc_port_stop(struct ata_port *ap)
{
int i;
struct sata_dwc_device *hsdev = HSDEV_FROM_AP(ap);
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
dev_dbg(ap->dev, "%s: ap->id = %d\n", __func__, ap->print_id);
if (hsdevp && hsdev) {
for (i = 0; i < SATA_DWC_QCMD_MAX; i++) {
dma_free_coherent(ap->host->dev,
SATA_DWC_DMAC_LLI_TBL_SZ,
hsdevp->llit[i], hsdevp->llit_dma[i]);
}
kfree(hsdevp);
}
ap->private_data = NULL;
}
static void sata_dwc_exec_command_by_tag(struct ata_port *ap,
struct ata_taskfile *tf,
u8 tag, u32 cmd_issued)
{
unsigned long flags;
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
dev_dbg(ap->dev, "%s cmd(0x%02x): %s tag=%d\n", __func__, tf->command,
ata_get_cmd_descript(tf->command), tag);
spin_lock_irqsave(&ap->host->lock, flags);
hsdevp->cmd_issued[tag] = cmd_issued;
spin_unlock_irqrestore(&ap->host->lock, flags);
clear_serror();
ata_sff_exec_command(ap, tf);
}
static void sata_dwc_bmdma_setup_by_tag(struct ata_queued_cmd *qc, u8 tag)
{
sata_dwc_exec_command_by_tag(qc->ap, &qc->tf, tag,
SATA_DWC_CMD_ISSUED_PEND);
}
static void sata_dwc_bmdma_setup(struct ata_queued_cmd *qc)
{
u8 tag = qc->tag;
if (ata_is_ncq(qc->tf.protocol)) {
dev_dbg(qc->ap->dev, "%s: ap->link.sactive=0x%08x tag=%d\n",
__func__, qc->ap->link.sactive, tag);
} else {
tag = 0;
}
sata_dwc_bmdma_setup_by_tag(qc, tag);
}
static void sata_dwc_bmdma_start_by_tag(struct ata_queued_cmd *qc, u8 tag)
{
int start_dma;
u32 reg, dma_chan;
struct sata_dwc_device *hsdev = HSDEV_FROM_QC(qc);
struct ata_port *ap = qc->ap;
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
int dir = qc->dma_dir;
dma_chan = hsdevp->dma_chan[tag];
if (hsdevp->cmd_issued[tag] != SATA_DWC_CMD_ISSUED_NOT) {
start_dma = 1;
if (dir == DMA_TO_DEVICE)
hsdevp->dma_pending[tag] = SATA_DWC_DMA_PENDING_TX;
else
hsdevp->dma_pending[tag] = SATA_DWC_DMA_PENDING_RX;
} else {
dev_err(ap->dev, "%s: Command not pending cmd_issued=%d "
"(tag=%d) DMA NOT started\n", __func__,
hsdevp->cmd_issued[tag], tag);
start_dma = 0;
}
dev_dbg(ap->dev, "%s qc=%p tag: %x cmd: 0x%02x dma_dir: %s "
"start_dma? %x\n", __func__, qc, tag, qc->tf.command,
get_dma_dir_descript(qc->dma_dir), start_dma);
sata_dwc_tf_dump(&(qc->tf));
if (start_dma) {
reg = core_scr_read(SCR_ERROR);
if (reg & SATA_DWC_SERROR_ERR_BITS) {
dev_err(ap->dev, "%s: ****** SError=0x%08x ******\n",
__func__, reg);
}
if (dir == DMA_TO_DEVICE)
out_le32(&hsdev->sata_dwc_regs->dmacr,
SATA_DWC_DMACR_TXCHEN);
else
out_le32(&hsdev->sata_dwc_regs->dmacr,
SATA_DWC_DMACR_RXCHEN);
dma_dwc_xfer_start(dma_chan);
}
}
static void sata_dwc_bmdma_start(struct ata_queued_cmd *qc)
{
u8 tag = qc->tag;
if (ata_is_ncq(qc->tf.protocol)) {
dev_dbg(qc->ap->dev, "%s: ap->link.sactive=0x%08x tag=%d\n",
__func__, qc->ap->link.sactive, tag);
} else {
tag = 0;
}
dev_dbg(qc->ap->dev, "%s\n", __func__);
sata_dwc_bmdma_start_by_tag(qc, tag);
}
static void sata_dwc_qc_prep_by_tag(struct ata_queued_cmd *qc, u8 tag)
{
struct scatterlist *sg = qc->sg;
struct ata_port *ap = qc->ap;
int dma_chan;
struct sata_dwc_device *hsdev = HSDEV_FROM_AP(ap);
struct sata_dwc_device_port *hsdevp = HSDEVP_FROM_AP(ap);
dev_dbg(ap->dev, "%s: port=%d dma dir=%s n_elem=%d\n",
__func__, ap->port_no, get_dma_dir_descript(qc->dma_dir),
qc->n_elem);
dma_chan = dma_dwc_xfer_setup(sg, qc->n_elem, hsdevp->llit[tag],
hsdevp->llit_dma[tag],
(void __iomem *)&hsdev->sata_dwc_regs->dmadr,
qc->dma_dir);
if (dma_chan < 0) {
dev_err(ap->dev, "%s: dma_dwc_xfer_setup returns err %d\n",
__func__, dma_chan);
return;
}
hsdevp->dma_chan[tag] = dma_chan;
}
static unsigned int sata_dwc_qc_issue(struct ata_queued_cmd *qc)
{
u32 sactive;
u8 tag = qc->tag;
struct ata_port *ap = qc->ap;
#ifdef DEBUG_NCQ
if (qc->tag > 0 || ap->link.sactive > 1)
dev_info(ap->dev, "%s ap id=%d cmd(0x%02x)=%s qc tag=%d "
"prot=%s ap active_tag=0x%08x ap sactive=0x%08x\n",
__func__, ap->print_id, qc->tf.command,
ata_get_cmd_descript(qc->tf.command),
qc->tag, get_prot_descript(qc->tf.protocol),
ap->link.active_tag, ap->link.sactive);
#endif
if (!ata_is_ncq(qc->tf.protocol))
tag = 0;
sata_dwc_qc_prep_by_tag(qc, tag);
if (ata_is_ncq(qc->tf.protocol)) {
sactive = core_scr_read(SCR_ACTIVE);
sactive |= (0x00000001 << tag);
core_scr_write(SCR_ACTIVE, sactive);
dev_dbg(qc->ap->dev, "%s: tag=%d ap->link.sactive = 0x%08x "
"sactive=0x%08x\n", __func__, tag, qc->ap->link.sactive,
sactive);
ap->ops->sff_tf_load(ap, &qc->tf);
sata_dwc_exec_command_by_tag(ap, &qc->tf, qc->tag,
SATA_DWC_CMD_ISSUED_PEND);
} else {
ata_sff_qc_issue(qc);
}
return 0;
}
static void sata_dwc_qc_prep(struct ata_queued_cmd *qc)
{
if ((qc->dma_dir == DMA_NONE) || (qc->tf.protocol == ATA_PROT_PIO))
return;
#ifdef DEBUG_NCQ
if (qc->tag > 0)
dev_info(qc->ap->dev, "%s: qc->tag=%d ap->active_tag=0x%08x\n",
__func__, qc->tag, qc->ap->link.active_tag);
return ;
#endif
}
static void sata_dwc_error_handler(struct ata_port *ap)
{
ata_sff_error_handler(ap);
}
static int sata_dwc_hardreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
struct sata_dwc_device *hsdev = HSDEV_FROM_AP(link->ap);
int ret;
ret = sata_sff_hardreset(link, class, deadline);
sata_dwc_enable_interrupts(hsdev);
out_le32(&hsdev->sata_dwc_regs->dmacr,
SATA_DWC_DMACR_TXRXCH_CLEAR);
out_le32(&hsdev->sata_dwc_regs->dbtsr,
SATA_DWC_DBTSR_MWR(AHB_DMA_BRST_DFLT) |
SATA_DWC_DBTSR_MRD(AHB_DMA_BRST_DFLT));
return ret;
}
static int sata_dwc_probe(struct platform_device *ofdev)
{
struct sata_dwc_device *hsdev;
u32 idr, versionr;
char *ver = (char *)&versionr;
u8 __iomem *base;
int err = 0;
int irq;
struct ata_host *host;
struct ata_port_info pi = sata_dwc_port_info[0];
const struct ata_port_info *ppi[] = { &pi, NULL };
struct device_node *np = ofdev->dev.of_node;
u32 dma_chan;
host = ata_host_alloc_pinfo(&ofdev->dev, ppi, SATA_DWC_MAX_PORTS);
hsdev = devm_kzalloc(&ofdev->dev, sizeof(*hsdev), GFP_KERNEL);
if (!host || !hsdev)
return -ENOMEM;
host->private_data = hsdev;
if (of_property_read_u32(np, "dma-channel", &dma_chan)) {
dev_warn(&ofdev->dev, "no dma-channel property set."
" Use channel 0\n");
dma_chan = 0;
}
host_pvt.dma_channel = dma_chan;
base = of_iomap(np, 0);
if (!base) {
dev_err(&ofdev->dev, "ioremap failed for SATA register"
" address\n");
return -ENODEV;
}
hsdev->reg_base = base;
dev_dbg(&ofdev->dev, "ioremap done for SATA register address\n");
hsdev->sata_dwc_regs = (void *__iomem)(base + SATA_DWC_REG_OFFSET);
host->ports[0]->ioaddr.cmd_addr = base;
host->ports[0]->ioaddr.scr_addr = base + SATA_DWC_SCR_OFFSET;
host_pvt.scr_addr_sstatus = base + SATA_DWC_SCR_OFFSET;
sata_dwc_setup_port(&host->ports[0]->ioaddr, (unsigned long)base);
idr = in_le32(&hsdev->sata_dwc_regs->idr);
versionr = in_le32(&hsdev->sata_dwc_regs->versionr);
dev_notice(&ofdev->dev, "id %d, controller version %c.%c%c\n",
idr, ver[0], ver[1], ver[2]);
irq = irq_of_parse_and_map(np, 1);
if (irq == NO_IRQ) {
dev_err(&ofdev->dev, "no SATA DMA irq\n");
err = -ENODEV;
goto error_iomap;
}
host_pvt.sata_dma_regs = (void *)of_iomap(np, 1);
if (!(host_pvt.sata_dma_regs)) {
dev_err(&ofdev->dev, "ioremap failed for AHBDMA register"
" address\n");
err = -ENODEV;
goto error_iomap;
}
host_pvt.dwc_dev = &ofdev->dev;
err = dma_dwc_init(hsdev, irq);
if (err)
goto error_dma_iomap;
sata_dwc_enable_interrupts(hsdev);
irq = irq_of_parse_and_map(np, 0);
if (irq == NO_IRQ) {
dev_err(&ofdev->dev, "no SATA DMA irq\n");
err = -ENODEV;
goto error_out;
}
err = ata_host_activate(host, irq, sata_dwc_isr, 0, &sata_dwc_sht);
if (err)
dev_err(&ofdev->dev, "failed to activate host");
dev_set_drvdata(&ofdev->dev, host);
return 0;
error_out:
dma_dwc_exit(hsdev);
error_dma_iomap:
iounmap((void __iomem *)host_pvt.sata_dma_regs);
error_iomap:
iounmap(base);
return err;
}
static int sata_dwc_remove(struct platform_device *ofdev)
{
struct device *dev = &ofdev->dev;
struct ata_host *host = dev_get_drvdata(dev);
struct sata_dwc_device *hsdev = host->private_data;
ata_host_detach(host);
dma_dwc_exit(hsdev);
iounmap((void __iomem *)host_pvt.sata_dma_regs);
iounmap(hsdev->reg_base);
dev_dbg(&ofdev->dev, "done\n");
return 0;
}
