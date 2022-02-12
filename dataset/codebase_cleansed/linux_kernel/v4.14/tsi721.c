static int tsi721_lcread(struct rio_mport *mport, int index, u32 offset,
int len, u32 *data)
{
struct tsi721_device *priv = mport->priv;
if (len != sizeof(u32))
return -EINVAL;
*data = ioread32(priv->regs + offset);
return 0;
}
static int tsi721_lcwrite(struct rio_mport *mport, int index, u32 offset,
int len, u32 data)
{
struct tsi721_device *priv = mport->priv;
if (len != sizeof(u32))
return -EINVAL;
iowrite32(data, priv->regs + offset);
return 0;
}
static int tsi721_maint_dma(struct tsi721_device *priv, u32 sys_size,
u16 destid, u8 hopcount, u32 offset, int len,
u32 *data, int do_wr)
{
void __iomem *regs = priv->regs + TSI721_DMAC_BASE(priv->mdma.ch_id);
struct tsi721_dma_desc *bd_ptr;
u32 rd_count, swr_ptr, ch_stat;
unsigned long flags;
int i, err = 0;
u32 op = do_wr ? MAINT_WR : MAINT_RD;
if (offset > (RIO_MAINT_SPACE_SZ - len) || (len != sizeof(u32)))
return -EINVAL;
spin_lock_irqsave(&tsi721_maint_lock, flags);
bd_ptr = priv->mdma.bd_base;
rd_count = ioread32(regs + TSI721_DMAC_DRDCNT);
bd_ptr[0].type_id = cpu_to_le32((DTYPE2 << 29) | (op << 19) | destid);
bd_ptr[0].bcount = cpu_to_le32((sys_size << 26) | 0x04);
bd_ptr[0].raddr_lo = cpu_to_le32((hopcount << 24) | offset);
bd_ptr[0].raddr_hi = 0;
if (do_wr)
bd_ptr[0].data[0] = cpu_to_be32p(data);
else
bd_ptr[0].data[0] = 0xffffffff;
mb();
iowrite32(rd_count + 2, regs + TSI721_DMAC_DWRCNT);
ioread32(regs + TSI721_DMAC_DWRCNT);
i = 0;
while ((ch_stat = ioread32(regs + TSI721_DMAC_STS))
& TSI721_DMAC_STS_RUN) {
udelay(1);
if (++i >= 5000000) {
tsi_debug(MAINT, &priv->pdev->dev,
"DMA[%d] read timeout ch_status=%x",
priv->mdma.ch_id, ch_stat);
if (!do_wr)
*data = 0xffffffff;
err = -EIO;
goto err_out;
}
}
if (ch_stat & TSI721_DMAC_STS_ABORT) {
tsi_debug(MAINT, &priv->pdev->dev, "DMA ABORT ch_stat=%x",
ch_stat);
tsi_debug(MAINT, &priv->pdev->dev,
"OP=%d : destid=%x hc=%x off=%x",
do_wr ? MAINT_WR : MAINT_RD,
destid, hopcount, offset);
iowrite32(TSI721_DMAC_INT_ALL, regs + TSI721_DMAC_INT);
iowrite32(TSI721_DMAC_CTL_INIT, regs + TSI721_DMAC_CTL);
udelay(10);
iowrite32(0, regs + TSI721_DMAC_DWRCNT);
udelay(1);
if (!do_wr)
*data = 0xffffffff;
err = -EIO;
goto err_out;
}
if (!do_wr)
*data = be32_to_cpu(bd_ptr[0].data[0]);
swr_ptr = ioread32(regs + TSI721_DMAC_DSWP);
iowrite32(swr_ptr, regs + TSI721_DMAC_DSRP);
err_out:
spin_unlock_irqrestore(&tsi721_maint_lock, flags);
return err;
}
static int tsi721_cread_dma(struct rio_mport *mport, int index, u16 destid,
u8 hopcount, u32 offset, int len, u32 *data)
{
struct tsi721_device *priv = mport->priv;
return tsi721_maint_dma(priv, mport->sys_size, destid, hopcount,
offset, len, data, 0);
}
static int tsi721_cwrite_dma(struct rio_mport *mport, int index, u16 destid,
u8 hopcount, u32 offset, int len, u32 data)
{
struct tsi721_device *priv = mport->priv;
u32 temp = data;
return tsi721_maint_dma(priv, mport->sys_size, destid, hopcount,
offset, len, &temp, 1);
}
static int
tsi721_pw_handler(struct tsi721_device *priv)
{
u32 pw_stat;
u32 pw_buf[TSI721_RIO_PW_MSG_SIZE/sizeof(u32)];
pw_stat = ioread32(priv->regs + TSI721_RIO_PW_RX_STAT);
if (pw_stat & TSI721_RIO_PW_RX_STAT_PW_VAL) {
pw_buf[0] = ioread32(priv->regs + TSI721_RIO_PW_RX_CAPT(0));
pw_buf[1] = ioread32(priv->regs + TSI721_RIO_PW_RX_CAPT(1));
pw_buf[2] = ioread32(priv->regs + TSI721_RIO_PW_RX_CAPT(2));
pw_buf[3] = ioread32(priv->regs + TSI721_RIO_PW_RX_CAPT(3));
spin_lock(&priv->pw_fifo_lock);
if (kfifo_avail(&priv->pw_fifo) >= TSI721_RIO_PW_MSG_SIZE)
kfifo_in(&priv->pw_fifo, pw_buf,
TSI721_RIO_PW_MSG_SIZE);
else
priv->pw_discard_count++;
spin_unlock(&priv->pw_fifo_lock);
}
iowrite32(TSI721_RIO_PW_RX_STAT_PW_DISC | TSI721_RIO_PW_RX_STAT_PW_VAL,
priv->regs + TSI721_RIO_PW_RX_STAT);
schedule_work(&priv->pw_work);
return 0;
}
static void tsi721_pw_dpc(struct work_struct *work)
{
struct tsi721_device *priv = container_of(work, struct tsi721_device,
pw_work);
union rio_pw_msg pwmsg;
while (kfifo_out_spinlocked(&priv->pw_fifo, (unsigned char *)&pwmsg,
TSI721_RIO_PW_MSG_SIZE, &priv->pw_fifo_lock)) {
rio_inb_pwrite_handler(&priv->mport, &pwmsg);
}
}
static int tsi721_pw_enable(struct rio_mport *mport, int enable)
{
struct tsi721_device *priv = mport->priv;
u32 rval;
rval = ioread32(priv->regs + TSI721_RIO_EM_INT_ENABLE);
if (enable)
rval |= TSI721_RIO_EM_INT_ENABLE_PW_RX;
else
rval &= ~TSI721_RIO_EM_INT_ENABLE_PW_RX;
iowrite32(TSI721_RIO_PW_RX_STAT_PW_DISC | TSI721_RIO_PW_RX_STAT_PW_VAL,
priv->regs + TSI721_RIO_PW_RX_STAT);
iowrite32(rval, priv->regs + TSI721_RIO_EM_INT_ENABLE);
return 0;
}
static int tsi721_dsend(struct rio_mport *mport, int index,
u16 destid, u16 data)
{
struct tsi721_device *priv = mport->priv;
u32 offset;
offset = (((mport->sys_size) ? RIO_TT_CODE_16 : RIO_TT_CODE_8) << 18) |
(destid << 2);
tsi_debug(DBELL, &priv->pdev->dev,
"Send Doorbell 0x%04x to destID 0x%x", data, destid);
iowrite16be(data, priv->odb_base + offset);
return 0;
}
static int
tsi721_dbell_handler(struct tsi721_device *priv)
{
u32 regval;
regval = ioread32(priv->regs + TSI721_SR_CHINTE(IDB_QUEUE));
regval &= ~TSI721_SR_CHINT_IDBQRCV;
iowrite32(regval,
priv->regs + TSI721_SR_CHINTE(IDB_QUEUE));
schedule_work(&priv->idb_work);
return 0;
}
static void tsi721_db_dpc(struct work_struct *work)
{
struct tsi721_device *priv = container_of(work, struct tsi721_device,
idb_work);
struct rio_mport *mport;
struct rio_dbell *dbell;
int found = 0;
u32 wr_ptr, rd_ptr;
u64 *idb_entry;
u32 regval;
union {
u64 msg;
u8 bytes[8];
} idb;
mport = &priv->mport;
wr_ptr = ioread32(priv->regs + TSI721_IDQ_WP(IDB_QUEUE)) % IDB_QSIZE;
rd_ptr = ioread32(priv->regs + TSI721_IDQ_RP(IDB_QUEUE)) % IDB_QSIZE;
while (wr_ptr != rd_ptr) {
idb_entry = (u64 *)(priv->idb_base +
(TSI721_IDB_ENTRY_SIZE * rd_ptr));
rd_ptr++;
rd_ptr %= IDB_QSIZE;
idb.msg = *idb_entry;
*idb_entry = 0;
list_for_each_entry(dbell, &mport->dbells, node) {
if ((dbell->res->start <= DBELL_INF(idb.bytes)) &&
(dbell->res->end >= DBELL_INF(idb.bytes))) {
found = 1;
break;
}
}
if (found) {
dbell->dinb(mport, dbell->dev_id, DBELL_SID(idb.bytes),
DBELL_TID(idb.bytes), DBELL_INF(idb.bytes));
} else {
tsi_debug(DBELL, &priv->pdev->dev,
"spurious IDB sid %2.2x tid %2.2x info %4.4x",
DBELL_SID(idb.bytes), DBELL_TID(idb.bytes),
DBELL_INF(idb.bytes));
}
wr_ptr = ioread32(priv->regs +
TSI721_IDQ_WP(IDB_QUEUE)) % IDB_QSIZE;
}
iowrite32(rd_ptr & (IDB_QSIZE - 1),
priv->regs + TSI721_IDQ_RP(IDB_QUEUE));
regval = ioread32(priv->regs + TSI721_SR_CHINTE(IDB_QUEUE));
regval |= TSI721_SR_CHINT_IDBQRCV;
iowrite32(regval,
priv->regs + TSI721_SR_CHINTE(IDB_QUEUE));
wr_ptr = ioread32(priv->regs + TSI721_IDQ_WP(IDB_QUEUE)) % IDB_QSIZE;
if (wr_ptr != rd_ptr)
schedule_work(&priv->idb_work);
}
static irqreturn_t tsi721_irqhandler(int irq, void *ptr)
{
struct tsi721_device *priv = (struct tsi721_device *)ptr;
u32 dev_int;
u32 dev_ch_int;
u32 intval;
u32 ch_inte;
if (priv->flags & TSI721_USING_MSI)
iowrite32(0, priv->regs + TSI721_DEV_INTE);
dev_int = ioread32(priv->regs + TSI721_DEV_INT);
if (!dev_int)
return IRQ_NONE;
dev_ch_int = ioread32(priv->regs + TSI721_DEV_CHAN_INT);
if (dev_int & TSI721_DEV_INT_SR2PC_CH) {
if (dev_ch_int & TSI721_INT_SR2PC_CHAN(IDB_QUEUE)) {
intval = ioread32(priv->regs +
TSI721_SR_CHINT(IDB_QUEUE));
if (intval & TSI721_SR_CHINT_IDBQRCV)
tsi721_dbell_handler(priv);
else
tsi_info(&priv->pdev->dev,
"Unsupported SR_CH_INT %x", intval);
iowrite32(intval,
priv->regs + TSI721_SR_CHINT(IDB_QUEUE));
ioread32(priv->regs + TSI721_SR_CHINT(IDB_QUEUE));
}
}
if (dev_int & TSI721_DEV_INT_SMSG_CH) {
int ch;
if (dev_ch_int & TSI721_INT_IMSG_CHAN_M) {
ch_inte = ioread32(priv->regs + TSI721_DEV_CHAN_INTE);
ch_inte &= ~(dev_ch_int & TSI721_INT_IMSG_CHAN_M);
iowrite32(ch_inte, priv->regs + TSI721_DEV_CHAN_INTE);
for (ch = 4; ch < RIO_MAX_MBOX + 4; ch++) {
if (!(dev_ch_int & TSI721_INT_IMSG_CHAN(ch)))
continue;
tsi721_imsg_handler(priv, ch);
}
}
if (dev_ch_int & TSI721_INT_OMSG_CHAN_M) {
ch_inte = ioread32(priv->regs + TSI721_DEV_CHAN_INTE);
ch_inte &= ~(dev_ch_int & TSI721_INT_OMSG_CHAN_M);
iowrite32(ch_inte, priv->regs + TSI721_DEV_CHAN_INTE);
for (ch = 0; ch < RIO_MAX_MBOX; ch++) {
if (!(dev_ch_int & TSI721_INT_OMSG_CHAN(ch)))
continue;
tsi721_omsg_handler(priv, ch);
}
}
}
if (dev_int & TSI721_DEV_INT_SRIO) {
intval = ioread32(priv->regs + TSI721_RIO_EM_INT_STAT);
if (intval & TSI721_RIO_EM_INT_STAT_PW_RX)
tsi721_pw_handler(priv);
}
#ifdef CONFIG_RAPIDIO_DMA_ENGINE
if (dev_int & TSI721_DEV_INT_BDMA_CH) {
int ch;
if (dev_ch_int & TSI721_INT_BDMA_CHAN_M) {
tsi_debug(DMA, &priv->pdev->dev,
"IRQ from DMA channel 0x%08x", dev_ch_int);
for (ch = 0; ch < TSI721_DMA_MAXCH; ch++) {
if (!(dev_ch_int & TSI721_INT_BDMA_CHAN(ch)))
continue;
tsi721_bdma_handler(&priv->bdma[ch]);
}
}
}
#endif
if (priv->flags & TSI721_USING_MSI) {
dev_int = TSI721_DEV_INT_SR2PC_CH | TSI721_DEV_INT_SRIO |
TSI721_DEV_INT_SMSG_CH | TSI721_DEV_INT_BDMA_CH;
iowrite32(dev_int, priv->regs + TSI721_DEV_INTE);
}
return IRQ_HANDLED;
}
static void tsi721_interrupts_init(struct tsi721_device *priv)
{
u32 intr;
iowrite32(TSI721_SR_CHINT_ALL,
priv->regs + TSI721_SR_CHINT(IDB_QUEUE));
iowrite32(TSI721_SR_CHINT_IDBQRCV,
priv->regs + TSI721_SR_CHINTE(IDB_QUEUE));
iowrite32(TSI721_RIO_EM_DEV_INT_EN_INT,
priv->regs + TSI721_RIO_EM_DEV_INT_EN);
#ifdef CONFIG_RAPIDIO_DMA_ENGINE
intr = TSI721_INT_SR2PC_CHAN(IDB_QUEUE) |
(TSI721_INT_BDMA_CHAN_M &
~TSI721_INT_BDMA_CHAN(TSI721_DMACH_MAINT));
#else
intr = TSI721_INT_SR2PC_CHAN(IDB_QUEUE);
#endif
iowrite32(intr, priv->regs + TSI721_DEV_CHAN_INTE);
if (priv->flags & TSI721_USING_MSIX)
intr = TSI721_DEV_INT_SRIO;
else
intr = TSI721_DEV_INT_SR2PC_CH | TSI721_DEV_INT_SRIO |
TSI721_DEV_INT_SMSG_CH | TSI721_DEV_INT_BDMA_CH;
iowrite32(intr, priv->regs + TSI721_DEV_INTE);
ioread32(priv->regs + TSI721_DEV_INTE);
}
static irqreturn_t tsi721_omsg_msix(int irq, void *ptr)
{
struct tsi721_device *priv = (struct tsi721_device *)ptr;
int mbox;
mbox = (irq - priv->msix[TSI721_VECT_OMB0_DONE].vector) % RIO_MAX_MBOX;
tsi721_omsg_handler(priv, mbox);
return IRQ_HANDLED;
}
static irqreturn_t tsi721_imsg_msix(int irq, void *ptr)
{
struct tsi721_device *priv = (struct tsi721_device *)ptr;
int mbox;
mbox = (irq - priv->msix[TSI721_VECT_IMB0_RCV].vector) % RIO_MAX_MBOX;
tsi721_imsg_handler(priv, mbox + 4);
return IRQ_HANDLED;
}
static irqreturn_t tsi721_srio_msix(int irq, void *ptr)
{
struct tsi721_device *priv = (struct tsi721_device *)ptr;
u32 srio_int;
srio_int = ioread32(priv->regs + TSI721_RIO_EM_INT_STAT);
if (srio_int & TSI721_RIO_EM_INT_STAT_PW_RX)
tsi721_pw_handler(priv);
return IRQ_HANDLED;
}
static irqreturn_t tsi721_sr2pc_ch_msix(int irq, void *ptr)
{
struct tsi721_device *priv = (struct tsi721_device *)ptr;
u32 sr_ch_int;
sr_ch_int = ioread32(priv->regs + TSI721_SR_CHINT(IDB_QUEUE));
if (sr_ch_int & TSI721_SR_CHINT_IDBQRCV)
tsi721_dbell_handler(priv);
iowrite32(sr_ch_int, priv->regs + TSI721_SR_CHINT(IDB_QUEUE));
sr_ch_int = ioread32(priv->regs + TSI721_SR_CHINT(IDB_QUEUE));
return IRQ_HANDLED;
}
static int tsi721_request_msix(struct tsi721_device *priv)
{
int err = 0;
err = request_irq(priv->msix[TSI721_VECT_IDB].vector,
tsi721_sr2pc_ch_msix, 0,
priv->msix[TSI721_VECT_IDB].irq_name, (void *)priv);
if (err)
return err;
err = request_irq(priv->msix[TSI721_VECT_PWRX].vector,
tsi721_srio_msix, 0,
priv->msix[TSI721_VECT_PWRX].irq_name, (void *)priv);
if (err) {
free_irq(priv->msix[TSI721_VECT_IDB].vector, (void *)priv);
return err;
}
return 0;
}
static int tsi721_enable_msix(struct tsi721_device *priv)
{
struct msix_entry entries[TSI721_VECT_MAX];
int err;
int i;
entries[TSI721_VECT_IDB].entry = TSI721_MSIX_SR2PC_IDBQ_RCV(IDB_QUEUE);
entries[TSI721_VECT_PWRX].entry = TSI721_MSIX_SRIO_MAC_INT;
for (i = 0; i < RIO_MAX_MBOX; i++) {
entries[TSI721_VECT_IMB0_RCV + i].entry =
TSI721_MSIX_IMSG_DQ_RCV(i + 4);
entries[TSI721_VECT_IMB0_INT + i].entry =
TSI721_MSIX_IMSG_INT(i + 4);
entries[TSI721_VECT_OMB0_DONE + i].entry =
TSI721_MSIX_OMSG_DONE(i);
entries[TSI721_VECT_OMB0_INT + i].entry =
TSI721_MSIX_OMSG_INT(i);
}
#ifdef CONFIG_RAPIDIO_DMA_ENGINE
for (i = 0; i < TSI721_DMA_CHNUM; i++) {
entries[TSI721_VECT_DMA0_DONE + i].entry =
TSI721_MSIX_DMACH_DONE(i);
entries[TSI721_VECT_DMA0_INT + i].entry =
TSI721_MSIX_DMACH_INT(i);
}
#endif
err = pci_enable_msix_exact(priv->pdev, entries, ARRAY_SIZE(entries));
if (err) {
tsi_err(&priv->pdev->dev,
"Failed to enable MSI-X (err=%d)", err);
return err;
}
priv->msix[TSI721_VECT_IDB].vector = entries[TSI721_VECT_IDB].vector;
snprintf(priv->msix[TSI721_VECT_IDB].irq_name, IRQ_DEVICE_NAME_MAX,
DRV_NAME "-idb@pci:%s", pci_name(priv->pdev));
priv->msix[TSI721_VECT_PWRX].vector = entries[TSI721_VECT_PWRX].vector;
snprintf(priv->msix[TSI721_VECT_PWRX].irq_name, IRQ_DEVICE_NAME_MAX,
DRV_NAME "-pwrx@pci:%s", pci_name(priv->pdev));
for (i = 0; i < RIO_MAX_MBOX; i++) {
priv->msix[TSI721_VECT_IMB0_RCV + i].vector =
entries[TSI721_VECT_IMB0_RCV + i].vector;
snprintf(priv->msix[TSI721_VECT_IMB0_RCV + i].irq_name,
IRQ_DEVICE_NAME_MAX, DRV_NAME "-imbr%d@pci:%s",
i, pci_name(priv->pdev));
priv->msix[TSI721_VECT_IMB0_INT + i].vector =
entries[TSI721_VECT_IMB0_INT + i].vector;
snprintf(priv->msix[TSI721_VECT_IMB0_INT + i].irq_name,
IRQ_DEVICE_NAME_MAX, DRV_NAME "-imbi%d@pci:%s",
i, pci_name(priv->pdev));
priv->msix[TSI721_VECT_OMB0_DONE + i].vector =
entries[TSI721_VECT_OMB0_DONE + i].vector;
snprintf(priv->msix[TSI721_VECT_OMB0_DONE + i].irq_name,
IRQ_DEVICE_NAME_MAX, DRV_NAME "-ombd%d@pci:%s",
i, pci_name(priv->pdev));
priv->msix[TSI721_VECT_OMB0_INT + i].vector =
entries[TSI721_VECT_OMB0_INT + i].vector;
snprintf(priv->msix[TSI721_VECT_OMB0_INT + i].irq_name,
IRQ_DEVICE_NAME_MAX, DRV_NAME "-ombi%d@pci:%s",
i, pci_name(priv->pdev));
}
#ifdef CONFIG_RAPIDIO_DMA_ENGINE
for (i = 0; i < TSI721_DMA_CHNUM; i++) {
priv->msix[TSI721_VECT_DMA0_DONE + i].vector =
entries[TSI721_VECT_DMA0_DONE + i].vector;
snprintf(priv->msix[TSI721_VECT_DMA0_DONE + i].irq_name,
IRQ_DEVICE_NAME_MAX, DRV_NAME "-dmad%d@pci:%s",
i, pci_name(priv->pdev));
priv->msix[TSI721_VECT_DMA0_INT + i].vector =
entries[TSI721_VECT_DMA0_INT + i].vector;
snprintf(priv->msix[TSI721_VECT_DMA0_INT + i].irq_name,
IRQ_DEVICE_NAME_MAX, DRV_NAME "-dmai%d@pci:%s",
i, pci_name(priv->pdev));
}
#endif
return 0;
}
static int tsi721_request_irq(struct tsi721_device *priv)
{
int err;
#ifdef CONFIG_PCI_MSI
if (priv->flags & TSI721_USING_MSIX)
err = tsi721_request_msix(priv);
else
#endif
err = request_irq(priv->pdev->irq, tsi721_irqhandler,
(priv->flags & TSI721_USING_MSI) ? 0 : IRQF_SHARED,
DRV_NAME, (void *)priv);
if (err)
tsi_err(&priv->pdev->dev,
"Unable to allocate interrupt, err=%d", err);
return err;
}
static void tsi721_free_irq(struct tsi721_device *priv)
{
#ifdef CONFIG_PCI_MSI
if (priv->flags & TSI721_USING_MSIX) {
free_irq(priv->msix[TSI721_VECT_IDB].vector, (void *)priv);
free_irq(priv->msix[TSI721_VECT_PWRX].vector, (void *)priv);
} else
#endif
free_irq(priv->pdev->irq, (void *)priv);
}
static int
tsi721_obw_alloc(struct tsi721_device *priv, struct tsi721_obw_bar *pbar,
u32 size, int *win_id)
{
u64 win_base;
u64 bar_base;
u64 bar_end;
u32 align;
struct tsi721_ob_win *win;
struct tsi721_ob_win *new_win = NULL;
int new_win_idx = -1;
int i = 0;
bar_base = pbar->base;
bar_end = bar_base + pbar->size;
win_base = bar_base;
align = size/TSI721_PC2SR_ZONES;
while (i < TSI721_IBWIN_NUM) {
for (i = 0; i < TSI721_IBWIN_NUM; i++) {
if (!priv->ob_win[i].active) {
if (new_win == NULL) {
new_win = &priv->ob_win[i];
new_win_idx = i;
}
continue;
}
win = &priv->ob_win[i];
if (win->base >= bar_base && win->base < bar_end) {
if (win_base < (win->base + win->size) &&
(win_base + size) > win->base) {
win_base = win->base + win->size;
win_base = ALIGN(win_base, align);
break;
}
}
}
}
if (win_base + size > bar_end)
return -ENOMEM;
if (!new_win) {
tsi_err(&priv->pdev->dev, "OBW count tracking failed");
return -EIO;
}
new_win->active = true;
new_win->base = win_base;
new_win->size = size;
new_win->pbar = pbar;
priv->obwin_cnt--;
pbar->free -= size;
*win_id = new_win_idx;
return 0;
}
static int tsi721_map_outb_win(struct rio_mport *mport, u16 destid, u64 rstart,
u32 size, u32 flags, dma_addr_t *laddr)
{
struct tsi721_device *priv = mport->priv;
int i;
struct tsi721_obw_bar *pbar;
struct tsi721_ob_win *ob_win;
int obw = -1;
u32 rval;
u64 rio_addr;
u32 zsize;
int ret = -ENOMEM;
tsi_debug(OBW, &priv->pdev->dev,
"did=%d ra=0x%llx sz=0x%x", destid, rstart, size);
if (!is_power_of_2(size) || (size < 0x8000) || (rstart & (size - 1)))
return -EINVAL;
if (priv->obwin_cnt == 0)
return -EBUSY;
for (i = 0; i < 2; i++) {
if (priv->p2r_bar[i].free >= size) {
pbar = &priv->p2r_bar[i];
ret = tsi721_obw_alloc(priv, pbar, size, &obw);
if (!ret)
break;
}
}
if (ret)
return ret;
WARN_ON(obw == -1);
ob_win = &priv->ob_win[obw];
ob_win->destid = destid;
ob_win->rstart = rstart;
tsi_debug(OBW, &priv->pdev->dev,
"allocated OBW%d @%llx", obw, ob_win->base);
zsize = size/TSI721_PC2SR_ZONES;
rio_addr = rstart;
for (i = 0; i < TSI721_PC2SR_ZONES; i++) {
while (ioread32(priv->regs + TSI721_ZONE_SEL) &
TSI721_ZONE_SEL_GO) {
udelay(1);
}
rval = (u32)(rio_addr & TSI721_LUT_DATA0_ADD) |
TSI721_LUT_DATA0_NREAD | TSI721_LUT_DATA0_NWR;
iowrite32(rval, priv->regs + TSI721_LUT_DATA0);
rval = (u32)(rio_addr >> 32);
iowrite32(rval, priv->regs + TSI721_LUT_DATA1);
rval = destid;
iowrite32(rval, priv->regs + TSI721_LUT_DATA2);
rval = TSI721_ZONE_SEL_GO | (obw << 3) | i;
iowrite32(rval, priv->regs + TSI721_ZONE_SEL);
rio_addr += zsize;
}
iowrite32(TSI721_OBWIN_SIZE(size) << 8,
priv->regs + TSI721_OBWINSZ(obw));
iowrite32((u32)(ob_win->base >> 32), priv->regs + TSI721_OBWINUB(obw));
iowrite32((u32)(ob_win->base & TSI721_OBWINLB_BA) | TSI721_OBWINLB_WEN,
priv->regs + TSI721_OBWINLB(obw));
*laddr = ob_win->base;
return 0;
}
static void tsi721_unmap_outb_win(struct rio_mport *mport,
u16 destid, u64 rstart)
{
struct tsi721_device *priv = mport->priv;
struct tsi721_ob_win *ob_win;
int i;
tsi_debug(OBW, &priv->pdev->dev, "did=%d ra=0x%llx", destid, rstart);
for (i = 0; i < TSI721_OBWIN_NUM; i++) {
ob_win = &priv->ob_win[i];
if (ob_win->active &&
ob_win->destid == destid && ob_win->rstart == rstart) {
tsi_debug(OBW, &priv->pdev->dev,
"free OBW%d @%llx", i, ob_win->base);
ob_win->active = false;
iowrite32(0, priv->regs + TSI721_OBWINLB(i));
ob_win->pbar->free += ob_win->size;
priv->obwin_cnt++;
break;
}
}
}
static void tsi721_init_pc2sr_mapping(struct tsi721_device *priv)
{
int i, z;
u32 rval;
for (i = 0; i < TSI721_OBWIN_NUM; i++)
iowrite32(0, priv->regs + TSI721_OBWINLB(i));
iowrite32(0, priv->regs + TSI721_LUT_DATA0);
iowrite32(0, priv->regs + TSI721_LUT_DATA1);
iowrite32(0, priv->regs + TSI721_LUT_DATA2);
for (i = 0; i < TSI721_OBWIN_NUM; i++) {
for (z = 0; z < TSI721_PC2SR_ZONES; z++) {
while (ioread32(priv->regs + TSI721_ZONE_SEL) &
TSI721_ZONE_SEL_GO) {
udelay(1);
}
rval = TSI721_ZONE_SEL_GO | (i << 3) | z;
iowrite32(rval, priv->regs + TSI721_ZONE_SEL);
}
}
if (priv->p2r_bar[0].size == 0 && priv->p2r_bar[1].size == 0) {
priv->obwin_cnt = 0;
return;
}
priv->p2r_bar[0].free = priv->p2r_bar[0].size;
priv->p2r_bar[1].free = priv->p2r_bar[1].size;
for (i = 0; i < TSI721_OBWIN_NUM; i++)
priv->ob_win[i].active = false;
priv->obwin_cnt = TSI721_OBWIN_NUM;
}
static int tsi721_rio_map_inb_mem(struct rio_mport *mport, dma_addr_t lstart,
u64 rstart, u64 size, u32 flags)
{
struct tsi721_device *priv = mport->priv;
int i, avail = -1;
u32 regval;
struct tsi721_ib_win *ib_win;
bool direct = (lstart == rstart);
u64 ibw_size;
dma_addr_t loc_start;
u64 ibw_start;
struct tsi721_ib_win_mapping *map = NULL;
int ret = -EBUSY;
if (size > 0x400000000UL)
return -EINVAL;
if (direct) {
ibw_size = roundup_pow_of_two(size);
ibw_start = lstart & ~(ibw_size - 1);
tsi_debug(IBW, &priv->pdev->dev,
"Direct (RIO_0x%llx -> PCIe_%pad), size=0x%llx, ibw_start = 0x%llx",
rstart, &lstart, size, ibw_start);
while ((lstart + size) > (ibw_start + ibw_size)) {
ibw_size *= 2;
ibw_start = lstart & ~(ibw_size - 1);
if (ibw_size > 0x400000000UL)
return -EBUSY;
}
loc_start = ibw_start;
map = kzalloc(sizeof(struct tsi721_ib_win_mapping), GFP_ATOMIC);
if (map == NULL)
return -ENOMEM;
} else {
tsi_debug(IBW, &priv->pdev->dev,
"Translated (RIO_0x%llx -> PCIe_%pad), size=0x%llx",
rstart, &lstart, size);
if (!is_power_of_2(size) || size < 0x1000 ||
((u64)lstart & (size - 1)) || (rstart & (size - 1)))
return -EINVAL;
if (priv->ibwin_cnt == 0)
return -EBUSY;
ibw_start = rstart;
ibw_size = size;
loc_start = lstart;
}
for (i = 0; i < TSI721_IBWIN_NUM; i++) {
ib_win = &priv->ib_win[i];
if (!ib_win->active) {
if (avail == -1) {
avail = i;
ret = 0;
}
} else if (ibw_start < (ib_win->rstart + ib_win->size) &&
(ibw_start + ibw_size) > ib_win->rstart) {
if (!direct || ib_win->xlat) {
ret = -EFAULT;
break;
}
if (rstart >= ib_win->rstart &&
(rstart + size) <= (ib_win->rstart +
ib_win->size)) {
map->lstart = lstart;
list_add_tail(&map->node, &ib_win->mappings);
return 0;
}
ret = -EFAULT;
break;
}
}
if (ret)
goto out;
i = avail;
regval = ioread32(priv->regs + TSI721_IBWIN_LB(i));
if (WARN_ON(regval & TSI721_IBWIN_LB_WEN)) {
ret = -EIO;
goto out;
}
ib_win = &priv->ib_win[i];
ib_win->active = true;
ib_win->rstart = ibw_start;
ib_win->lstart = loc_start;
ib_win->size = ibw_size;
ib_win->xlat = (lstart != rstart);
INIT_LIST_HEAD(&ib_win->mappings);
if (direct) {
map->lstart = lstart;
list_add_tail(&map->node, &ib_win->mappings);
}
iowrite32(TSI721_IBWIN_SIZE(ibw_size) << 8,
priv->regs + TSI721_IBWIN_SZ(i));
iowrite32(((u64)loc_start >> 32), priv->regs + TSI721_IBWIN_TUA(i));
iowrite32(((u64)loc_start & TSI721_IBWIN_TLA_ADD),
priv->regs + TSI721_IBWIN_TLA(i));
iowrite32(ibw_start >> 32, priv->regs + TSI721_IBWIN_UB(i));
iowrite32((ibw_start & TSI721_IBWIN_LB_BA) | TSI721_IBWIN_LB_WEN,
priv->regs + TSI721_IBWIN_LB(i));
priv->ibwin_cnt--;
tsi_debug(IBW, &priv->pdev->dev,
"Configured IBWIN%d (RIO_0x%llx -> PCIe_%pad), size=0x%llx",
i, ibw_start, &loc_start, ibw_size);
return 0;
out:
kfree(map);
return ret;
}
static void tsi721_rio_unmap_inb_mem(struct rio_mport *mport,
dma_addr_t lstart)
{
struct tsi721_device *priv = mport->priv;
struct tsi721_ib_win *ib_win;
int i;
tsi_debug(IBW, &priv->pdev->dev,
"Unmap IBW mapped to PCIe_%pad", &lstart);
for (i = 0; i < TSI721_IBWIN_NUM; i++) {
ib_win = &priv->ib_win[i];
if (!ib_win->active ||
(ib_win->xlat && lstart != ib_win->lstart))
continue;
if (lstart >= ib_win->lstart &&
lstart < (ib_win->lstart + ib_win->size)) {
if (!ib_win->xlat) {
struct tsi721_ib_win_mapping *map;
int found = 0;
list_for_each_entry(map,
&ib_win->mappings, node) {
if (map->lstart == lstart) {
list_del(&map->node);
kfree(map);
found = 1;
break;
}
}
if (!found)
continue;
if (!list_empty(&ib_win->mappings))
break;
}
tsi_debug(IBW, &priv->pdev->dev, "Disable IBWIN_%d", i);
iowrite32(0, priv->regs + TSI721_IBWIN_LB(i));
ib_win->active = false;
priv->ibwin_cnt++;
break;
}
}
if (i == TSI721_IBWIN_NUM)
tsi_debug(IBW, &priv->pdev->dev,
"IB window mapped to %pad not found", &lstart);
}
static void tsi721_init_sr2pc_mapping(struct tsi721_device *priv)
{
int i;
for (i = 0; i < TSI721_IBWIN_NUM; i++)
iowrite32(0, priv->regs + TSI721_IBWIN_LB(i));
priv->ibwin_cnt = TSI721_IBWIN_NUM;
}
static void tsi721_close_sr2pc_mapping(struct tsi721_device *priv)
{
struct tsi721_ib_win *ib_win;
int i;
for (i = 0; i < TSI721_IBWIN_NUM; i++) {
ib_win = &priv->ib_win[i];
if (ib_win->active) {
iowrite32(0, priv->regs + TSI721_IBWIN_LB(i));
ib_win->active = false;
}
}
}
static int tsi721_port_write_init(struct tsi721_device *priv)
{
priv->pw_discard_count = 0;
INIT_WORK(&priv->pw_work, tsi721_pw_dpc);
spin_lock_init(&priv->pw_fifo_lock);
if (kfifo_alloc(&priv->pw_fifo,
TSI721_RIO_PW_MSG_SIZE * 32, GFP_KERNEL)) {
tsi_err(&priv->pdev->dev, "PW FIFO allocation failed");
return -ENOMEM;
}
iowrite32(TSI721_RIO_PW_CTL_PWC_REL, priv->regs + TSI721_RIO_PW_CTL);
return 0;
}
static void tsi721_port_write_free(struct tsi721_device *priv)
{
kfifo_free(&priv->pw_fifo);
}
static int tsi721_doorbell_init(struct tsi721_device *priv)
{
priv->db_discard_count = 0;
INIT_WORK(&priv->idb_work, tsi721_db_dpc);
priv->idb_base = dma_zalloc_coherent(&priv->pdev->dev,
IDB_QSIZE * TSI721_IDB_ENTRY_SIZE,
&priv->idb_dma, GFP_KERNEL);
if (!priv->idb_base)
return -ENOMEM;
tsi_debug(DBELL, &priv->pdev->dev,
"Allocated IDB buffer @ %p (phys = %pad)",
priv->idb_base, &priv->idb_dma);
iowrite32(TSI721_IDQ_SIZE_VAL(IDB_QSIZE),
priv->regs + TSI721_IDQ_SIZE(IDB_QUEUE));
iowrite32(((u64)priv->idb_dma >> 32),
priv->regs + TSI721_IDQ_BASEU(IDB_QUEUE));
iowrite32(((u64)priv->idb_dma & TSI721_IDQ_BASEL_ADDR),
priv->regs + TSI721_IDQ_BASEL(IDB_QUEUE));
iowrite32(0, priv->regs + TSI721_IDQ_MASK(IDB_QUEUE));
iowrite32(TSI721_IDQ_INIT, priv->regs + TSI721_IDQ_CTL(IDB_QUEUE));
iowrite32(0, priv->regs + TSI721_IDQ_RP(IDB_QUEUE));
return 0;
}
static void tsi721_doorbell_free(struct tsi721_device *priv)
{
if (priv->idb_base == NULL)
return;
dma_free_coherent(&priv->pdev->dev, IDB_QSIZE * TSI721_IDB_ENTRY_SIZE,
priv->idb_base, priv->idb_dma);
priv->idb_base = NULL;
}
static int tsi721_bdma_maint_init(struct tsi721_device *priv)
{
struct tsi721_dma_desc *bd_ptr;
u64 *sts_ptr;
dma_addr_t bd_phys, sts_phys;
int sts_size;
int bd_num = 2;
void __iomem *regs;
tsi_debug(MAINT, &priv->pdev->dev,
"Init BDMA_%d Maintenance requests", TSI721_DMACH_MAINT);
priv->mdma.ch_id = TSI721_DMACH_MAINT;
regs = priv->regs + TSI721_DMAC_BASE(TSI721_DMACH_MAINT);
bd_ptr = dma_zalloc_coherent(&priv->pdev->dev,
bd_num * sizeof(struct tsi721_dma_desc),
&bd_phys, GFP_KERNEL);
if (!bd_ptr)
return -ENOMEM;
priv->mdma.bd_num = bd_num;
priv->mdma.bd_phys = bd_phys;
priv->mdma.bd_base = bd_ptr;
tsi_debug(MAINT, &priv->pdev->dev, "DMA descriptors @ %p (phys = %pad)",
bd_ptr, &bd_phys);
sts_size = (bd_num >= TSI721_DMA_MINSTSSZ) ?
bd_num : TSI721_DMA_MINSTSSZ;
sts_size = roundup_pow_of_two(sts_size);
sts_ptr = dma_zalloc_coherent(&priv->pdev->dev,
sts_size * sizeof(struct tsi721_dma_sts),
&sts_phys, GFP_KERNEL);
if (!sts_ptr) {
dma_free_coherent(&priv->pdev->dev,
bd_num * sizeof(struct tsi721_dma_desc),
bd_ptr, bd_phys);
priv->mdma.bd_base = NULL;
return -ENOMEM;
}
priv->mdma.sts_phys = sts_phys;
priv->mdma.sts_base = sts_ptr;
priv->mdma.sts_size = sts_size;
tsi_debug(MAINT, &priv->pdev->dev,
"desc status FIFO @ %p (phys = %pad) size=0x%x",
sts_ptr, &sts_phys, sts_size);
bd_ptr[bd_num - 1].type_id = cpu_to_le32(DTYPE3 << 29);
bd_ptr[bd_num - 1].next_lo = cpu_to_le32((u64)bd_phys &
TSI721_DMAC_DPTRL_MASK);
bd_ptr[bd_num - 1].next_hi = cpu_to_le32((u64)bd_phys >> 32);
iowrite32(((u64)bd_phys >> 32), regs + TSI721_DMAC_DPTRH);
iowrite32(((u64)bd_phys & TSI721_DMAC_DPTRL_MASK),
regs + TSI721_DMAC_DPTRL);
iowrite32(((u64)sts_phys >> 32), regs + TSI721_DMAC_DSBH);
iowrite32(((u64)sts_phys & TSI721_DMAC_DSBL_MASK),
regs + TSI721_DMAC_DSBL);
iowrite32(TSI721_DMAC_DSSZ_SIZE(sts_size),
regs + TSI721_DMAC_DSSZ);
iowrite32(TSI721_DMAC_INT_ALL, regs + TSI721_DMAC_INT);
ioread32(regs + TSI721_DMAC_INT);
iowrite32(TSI721_DMAC_CTL_INIT, regs + TSI721_DMAC_CTL);
ioread32(regs + TSI721_DMAC_CTL);
udelay(10);
return 0;
}
static int tsi721_bdma_maint_free(struct tsi721_device *priv)
{
u32 ch_stat;
struct tsi721_bdma_maint *mdma = &priv->mdma;
void __iomem *regs = priv->regs + TSI721_DMAC_BASE(mdma->ch_id);
if (mdma->bd_base == NULL)
return 0;
ch_stat = ioread32(regs + TSI721_DMAC_STS);
if (ch_stat & TSI721_DMAC_STS_RUN)
return -EFAULT;
iowrite32(TSI721_DMAC_CTL_INIT, regs + TSI721_DMAC_CTL);
dma_free_coherent(&priv->pdev->dev,
mdma->bd_num * sizeof(struct tsi721_dma_desc),
mdma->bd_base, mdma->bd_phys);
mdma->bd_base = NULL;
dma_free_coherent(&priv->pdev->dev,
mdma->sts_size * sizeof(struct tsi721_dma_sts),
mdma->sts_base, mdma->sts_phys);
mdma->sts_base = NULL;
return 0;
}
static void
tsi721_imsg_interrupt_enable(struct tsi721_device *priv, int ch,
u32 inte_mask)
{
u32 rval;
if (!inte_mask)
return;
iowrite32(inte_mask, priv->regs + TSI721_IBDMAC_INT(ch));
rval = ioread32(priv->regs + TSI721_IBDMAC_INTE(ch));
iowrite32(rval | inte_mask, priv->regs + TSI721_IBDMAC_INTE(ch));
if (priv->flags & TSI721_USING_MSIX)
return;
rval = ioread32(priv->regs + TSI721_DEV_CHAN_INTE);
iowrite32(rval | TSI721_INT_IMSG_CHAN(ch),
priv->regs + TSI721_DEV_CHAN_INTE);
}
static void
tsi721_imsg_interrupt_disable(struct tsi721_device *priv, int ch,
u32 inte_mask)
{
u32 rval;
if (!inte_mask)
return;
iowrite32(inte_mask, priv->regs + TSI721_IBDMAC_INT(ch));
rval = ioread32(priv->regs + TSI721_IBDMAC_INTE(ch));
rval &= ~inte_mask;
iowrite32(rval, priv->regs + TSI721_IBDMAC_INTE(ch));
if (priv->flags & TSI721_USING_MSIX)
return;
rval = ioread32(priv->regs + TSI721_DEV_CHAN_INTE);
rval &= ~TSI721_INT_IMSG_CHAN(ch);
iowrite32(rval, priv->regs + TSI721_DEV_CHAN_INTE);
}
static void
tsi721_omsg_interrupt_enable(struct tsi721_device *priv, int ch,
u32 inte_mask)
{
u32 rval;
if (!inte_mask)
return;
iowrite32(inte_mask, priv->regs + TSI721_OBDMAC_INT(ch));
rval = ioread32(priv->regs + TSI721_OBDMAC_INTE(ch));
iowrite32(rval | inte_mask, priv->regs + TSI721_OBDMAC_INTE(ch));
if (priv->flags & TSI721_USING_MSIX)
return;
rval = ioread32(priv->regs + TSI721_DEV_CHAN_INTE);
iowrite32(rval | TSI721_INT_OMSG_CHAN(ch),
priv->regs + TSI721_DEV_CHAN_INTE);
}
static void
tsi721_omsg_interrupt_disable(struct tsi721_device *priv, int ch,
u32 inte_mask)
{
u32 rval;
if (!inte_mask)
return;
iowrite32(inte_mask, priv->regs + TSI721_OBDMAC_INT(ch));
rval = ioread32(priv->regs + TSI721_OBDMAC_INTE(ch));
rval &= ~inte_mask;
iowrite32(rval, priv->regs + TSI721_OBDMAC_INTE(ch));
if (priv->flags & TSI721_USING_MSIX)
return;
rval = ioread32(priv->regs + TSI721_DEV_CHAN_INTE);
rval &= ~TSI721_INT_OMSG_CHAN(ch);
iowrite32(rval, priv->regs + TSI721_DEV_CHAN_INTE);
}
static int
tsi721_add_outb_message(struct rio_mport *mport, struct rio_dev *rdev, int mbox,
void *buffer, size_t len)
{
struct tsi721_device *priv = mport->priv;
struct tsi721_omsg_desc *desc;
u32 tx_slot;
unsigned long flags;
if (!priv->omsg_init[mbox] ||
len > TSI721_MSG_MAX_SIZE || len < 8)
return -EINVAL;
spin_lock_irqsave(&priv->omsg_ring[mbox].lock, flags);
tx_slot = priv->omsg_ring[mbox].tx_slot;
memcpy(priv->omsg_ring[mbox].omq_base[tx_slot], buffer, len);
if (len & 0x7)
len += 8;
desc = priv->omsg_ring[mbox].omd_base;
desc[tx_slot].type_id = cpu_to_le32((DTYPE4 << 29) | rdev->destid);
#ifdef TSI721_OMSG_DESC_INT
if (tx_slot % 4 == 0)
desc[tx_slot].type_id |= cpu_to_le32(TSI721_OMD_IOF);
#endif
desc[tx_slot].msg_info =
cpu_to_le32((mport->sys_size << 26) | (mbox << 22) |
(0xe << 12) | (len & 0xff8));
desc[tx_slot].bufptr_lo =
cpu_to_le32((u64)priv->omsg_ring[mbox].omq_phys[tx_slot] &
0xffffffff);
desc[tx_slot].bufptr_hi =
cpu_to_le32((u64)priv->omsg_ring[mbox].omq_phys[tx_slot] >> 32);
priv->omsg_ring[mbox].wr_count++;
if (++priv->omsg_ring[mbox].tx_slot == priv->omsg_ring[mbox].size) {
priv->omsg_ring[mbox].tx_slot = 0;
priv->omsg_ring[mbox].wr_count++;
}
mb();
iowrite32(priv->omsg_ring[mbox].wr_count,
priv->regs + TSI721_OBDMAC_DWRCNT(mbox));
ioread32(priv->regs + TSI721_OBDMAC_DWRCNT(mbox));
spin_unlock_irqrestore(&priv->omsg_ring[mbox].lock, flags);
return 0;
}
static void tsi721_omsg_handler(struct tsi721_device *priv, int ch)
{
u32 omsg_int;
struct rio_mport *mport = &priv->mport;
void *dev_id = NULL;
u32 tx_slot = 0xffffffff;
int do_callback = 0;
spin_lock(&priv->omsg_ring[ch].lock);
omsg_int = ioread32(priv->regs + TSI721_OBDMAC_INT(ch));
if (omsg_int & TSI721_OBDMAC_INT_ST_FULL)
tsi_info(&priv->pdev->dev,
"OB MBOX%d: Status FIFO is full", ch);
if (omsg_int & (TSI721_OBDMAC_INT_DONE | TSI721_OBDMAC_INT_IOF_DONE)) {
u32 srd_ptr;
u64 *sts_ptr, last_ptr = 0, prev_ptr = 0;
int i, j;
srd_ptr = priv->omsg_ring[ch].sts_rdptr;
sts_ptr = priv->omsg_ring[ch].sts_base;
j = srd_ptr * 8;
while (sts_ptr[j]) {
for (i = 0; i < 8 && sts_ptr[j]; i++, j++) {
prev_ptr = last_ptr;
last_ptr = le64_to_cpu(sts_ptr[j]);
sts_ptr[j] = 0;
}
++srd_ptr;
srd_ptr %= priv->omsg_ring[ch].sts_size;
j = srd_ptr * 8;
}
if (last_ptr == 0)
goto no_sts_update;
priv->omsg_ring[ch].sts_rdptr = srd_ptr;
iowrite32(srd_ptr, priv->regs + TSI721_OBDMAC_DSRP(ch));
if (!mport->outb_msg[ch].mcback)
goto no_sts_update;
tx_slot = (last_ptr - (u64)priv->omsg_ring[ch].omd_phys)/
sizeof(struct tsi721_omsg_desc);
if (tx_slot == priv->omsg_ring[ch].size) {
if (prev_ptr)
tx_slot = (prev_ptr -
(u64)priv->omsg_ring[ch].omd_phys)/
sizeof(struct tsi721_omsg_desc);
else
goto no_sts_update;
}
if (tx_slot >= priv->omsg_ring[ch].size)
tsi_debug(OMSG, &priv->pdev->dev,
"OB_MSG tx_slot=%x > size=%x",
tx_slot, priv->omsg_ring[ch].size);
WARN_ON(tx_slot >= priv->omsg_ring[ch].size);
++tx_slot;
if (tx_slot == priv->omsg_ring[ch].size)
tx_slot = 0;
dev_id = priv->omsg_ring[ch].dev_id;
do_callback = 1;
}
no_sts_update:
if (omsg_int & TSI721_OBDMAC_INT_ERROR) {
tsi_debug(OMSG, &priv->pdev->dev, "OB MSG ABORT ch_stat=%x",
ioread32(priv->regs + TSI721_OBDMAC_STS(ch)));
iowrite32(TSI721_OBDMAC_INT_ERROR,
priv->regs + TSI721_OBDMAC_INT(ch));
iowrite32(TSI721_OBDMAC_CTL_RETRY_THR | TSI721_OBDMAC_CTL_INIT,
priv->regs + TSI721_OBDMAC_CTL(ch));
ioread32(priv->regs + TSI721_OBDMAC_CTL(ch));
dev_id = priv->omsg_ring[ch].dev_id;
tx_slot = priv->omsg_ring[ch].tx_slot;
do_callback = 1;
iowrite32(priv->omsg_ring[ch].tx_slot,
priv->regs + TSI721_OBDMAC_DRDCNT(ch));
ioread32(priv->regs + TSI721_OBDMAC_DRDCNT(ch));
priv->omsg_ring[ch].wr_count = priv->omsg_ring[ch].tx_slot;
priv->omsg_ring[ch].sts_rdptr = 0;
}
iowrite32(omsg_int, priv->regs + TSI721_OBDMAC_INT(ch));
if (!(priv->flags & TSI721_USING_MSIX)) {
u32 ch_inte;
ch_inte = ioread32(priv->regs + TSI721_DEV_CHAN_INTE);
ch_inte |= TSI721_INT_OMSG_CHAN(ch);
iowrite32(ch_inte, priv->regs + TSI721_DEV_CHAN_INTE);
}
spin_unlock(&priv->omsg_ring[ch].lock);
if (mport->outb_msg[ch].mcback && do_callback)
mport->outb_msg[ch].mcback(mport, dev_id, ch, tx_slot);
}
static int tsi721_open_outb_mbox(struct rio_mport *mport, void *dev_id,
int mbox, int entries)
{
struct tsi721_device *priv = mport->priv;
struct tsi721_omsg_desc *bd_ptr;
int i, rc = 0;
if ((entries < TSI721_OMSGD_MIN_RING_SIZE) ||
(entries > (TSI721_OMSGD_RING_SIZE)) ||
(!is_power_of_2(entries)) || mbox >= RIO_MAX_MBOX) {
rc = -EINVAL;
goto out;
}
if ((mbox_sel & (1 << mbox)) == 0) {
rc = -ENODEV;
goto out;
}
priv->omsg_ring[mbox].dev_id = dev_id;
priv->omsg_ring[mbox].size = entries;
priv->omsg_ring[mbox].sts_rdptr = 0;
spin_lock_init(&priv->omsg_ring[mbox].lock);
for (i = 0; i < entries; i++) {
priv->omsg_ring[mbox].omq_base[i] =
dma_alloc_coherent(
&priv->pdev->dev, TSI721_MSG_BUFFER_SIZE,
&priv->omsg_ring[mbox].omq_phys[i],
GFP_KERNEL);
if (priv->omsg_ring[mbox].omq_base[i] == NULL) {
tsi_debug(OMSG, &priv->pdev->dev,
"ENOMEM for OB_MSG_%d data buffer", mbox);
rc = -ENOMEM;
goto out_buf;
}
}
priv->omsg_ring[mbox].omd_base = dma_alloc_coherent(
&priv->pdev->dev,
(entries + 1) * sizeof(struct tsi721_omsg_desc),
&priv->omsg_ring[mbox].omd_phys, GFP_KERNEL);
if (priv->omsg_ring[mbox].omd_base == NULL) {
tsi_debug(OMSG, &priv->pdev->dev,
"ENOMEM for OB_MSG_%d descriptor memory", mbox);
rc = -ENOMEM;
goto out_buf;
}
priv->omsg_ring[mbox].tx_slot = 0;
priv->omsg_ring[mbox].sts_size = roundup_pow_of_two(entries + 1);
priv->omsg_ring[mbox].sts_base = dma_zalloc_coherent(&priv->pdev->dev,
priv->omsg_ring[mbox].sts_size *
sizeof(struct tsi721_dma_sts),
&priv->omsg_ring[mbox].sts_phys, GFP_KERNEL);
if (priv->omsg_ring[mbox].sts_base == NULL) {
tsi_debug(OMSG, &priv->pdev->dev,
"ENOMEM for OB_MSG_%d status FIFO", mbox);
rc = -ENOMEM;
goto out_desc;
}
iowrite32(((u64)priv->omsg_ring[mbox].omd_phys >> 32),
priv->regs + TSI721_OBDMAC_DPTRH(mbox));
iowrite32(((u64)priv->omsg_ring[mbox].omd_phys &
TSI721_OBDMAC_DPTRL_MASK),
priv->regs + TSI721_OBDMAC_DPTRL(mbox));
iowrite32(((u64)priv->omsg_ring[mbox].sts_phys >> 32),
priv->regs + TSI721_OBDMAC_DSBH(mbox));
iowrite32(((u64)priv->omsg_ring[mbox].sts_phys &
TSI721_OBDMAC_DSBL_MASK),
priv->regs + TSI721_OBDMAC_DSBL(mbox));
iowrite32(TSI721_DMAC_DSSZ_SIZE(priv->omsg_ring[mbox].sts_size),
priv->regs + (u32)TSI721_OBDMAC_DSSZ(mbox));
#ifdef CONFIG_PCI_MSI
if (priv->flags & TSI721_USING_MSIX) {
int idx = TSI721_VECT_OMB0_DONE + mbox;
rc = request_irq(priv->msix[idx].vector, tsi721_omsg_msix, 0,
priv->msix[idx].irq_name, (void *)priv);
if (rc) {
tsi_debug(OMSG, &priv->pdev->dev,
"Unable to get MSI-X IRQ for OBOX%d-DONE",
mbox);
goto out_stat;
}
idx = TSI721_VECT_OMB0_INT + mbox;
rc = request_irq(priv->msix[idx].vector, tsi721_omsg_msix, 0,
priv->msix[idx].irq_name, (void *)priv);
if (rc) {
tsi_debug(OMSG, &priv->pdev->dev,
"Unable to get MSI-X IRQ for MBOX%d-INT", mbox);
idx = TSI721_VECT_OMB0_DONE + mbox;
free_irq(priv->msix[idx].vector, (void *)priv);
goto out_stat;
}
}
#endif
tsi721_omsg_interrupt_enable(priv, mbox, TSI721_OBDMAC_INT_ALL);
bd_ptr = priv->omsg_ring[mbox].omd_base;
bd_ptr[entries].type_id = cpu_to_le32(DTYPE5 << 29);
bd_ptr[entries].msg_info = 0;
bd_ptr[entries].next_lo =
cpu_to_le32((u64)priv->omsg_ring[mbox].omd_phys &
TSI721_OBDMAC_DPTRL_MASK);
bd_ptr[entries].next_hi =
cpu_to_le32((u64)priv->omsg_ring[mbox].omd_phys >> 32);
priv->omsg_ring[mbox].wr_count = 0;
mb();
iowrite32(TSI721_OBDMAC_CTL_RETRY_THR | TSI721_OBDMAC_CTL_INIT,
priv->regs + TSI721_OBDMAC_CTL(mbox));
ioread32(priv->regs + TSI721_OBDMAC_DWRCNT(mbox));
udelay(10);
priv->omsg_init[mbox] = 1;
return 0;
#ifdef CONFIG_PCI_MSI
out_stat:
dma_free_coherent(&priv->pdev->dev,
priv->omsg_ring[mbox].sts_size * sizeof(struct tsi721_dma_sts),
priv->omsg_ring[mbox].sts_base,
priv->omsg_ring[mbox].sts_phys);
priv->omsg_ring[mbox].sts_base = NULL;
#endif
out_desc:
dma_free_coherent(&priv->pdev->dev,
(entries + 1) * sizeof(struct tsi721_omsg_desc),
priv->omsg_ring[mbox].omd_base,
priv->omsg_ring[mbox].omd_phys);
priv->omsg_ring[mbox].omd_base = NULL;
out_buf:
for (i = 0; i < priv->omsg_ring[mbox].size; i++) {
if (priv->omsg_ring[mbox].omq_base[i]) {
dma_free_coherent(&priv->pdev->dev,
TSI721_MSG_BUFFER_SIZE,
priv->omsg_ring[mbox].omq_base[i],
priv->omsg_ring[mbox].omq_phys[i]);
priv->omsg_ring[mbox].omq_base[i] = NULL;
}
}
out:
return rc;
}
static void tsi721_close_outb_mbox(struct rio_mport *mport, int mbox)
{
struct tsi721_device *priv = mport->priv;
u32 i;
if (!priv->omsg_init[mbox])
return;
priv->omsg_init[mbox] = 0;
tsi721_omsg_interrupt_disable(priv, mbox, TSI721_OBDMAC_INT_ALL);
#ifdef CONFIG_PCI_MSI
if (priv->flags & TSI721_USING_MSIX) {
free_irq(priv->msix[TSI721_VECT_OMB0_DONE + mbox].vector,
(void *)priv);
free_irq(priv->msix[TSI721_VECT_OMB0_INT + mbox].vector,
(void *)priv);
}
#endif
dma_free_coherent(&priv->pdev->dev,
priv->omsg_ring[mbox].sts_size * sizeof(struct tsi721_dma_sts),
priv->omsg_ring[mbox].sts_base,
priv->omsg_ring[mbox].sts_phys);
priv->omsg_ring[mbox].sts_base = NULL;
dma_free_coherent(&priv->pdev->dev,
(priv->omsg_ring[mbox].size + 1) *
sizeof(struct tsi721_omsg_desc),
priv->omsg_ring[mbox].omd_base,
priv->omsg_ring[mbox].omd_phys);
priv->omsg_ring[mbox].omd_base = NULL;
for (i = 0; i < priv->omsg_ring[mbox].size; i++) {
if (priv->omsg_ring[mbox].omq_base[i]) {
dma_free_coherent(&priv->pdev->dev,
TSI721_MSG_BUFFER_SIZE,
priv->omsg_ring[mbox].omq_base[i],
priv->omsg_ring[mbox].omq_phys[i]);
priv->omsg_ring[mbox].omq_base[i] = NULL;
}
}
}
static void tsi721_imsg_handler(struct tsi721_device *priv, int ch)
{
u32 mbox = ch - 4;
u32 imsg_int;
struct rio_mport *mport = &priv->mport;
spin_lock(&priv->imsg_ring[mbox].lock);
imsg_int = ioread32(priv->regs + TSI721_IBDMAC_INT(ch));
if (imsg_int & TSI721_IBDMAC_INT_SRTO)
tsi_info(&priv->pdev->dev, "IB MBOX%d SRIO timeout", mbox);
if (imsg_int & TSI721_IBDMAC_INT_PC_ERROR)
tsi_info(&priv->pdev->dev, "IB MBOX%d PCIe error", mbox);
if (imsg_int & TSI721_IBDMAC_INT_FQ_LOW)
tsi_info(&priv->pdev->dev, "IB MBOX%d IB free queue low", mbox);
iowrite32(imsg_int, priv->regs + TSI721_IBDMAC_INT(ch));
if (imsg_int & TSI721_IBDMAC_INT_DQ_RCV &&
mport->inb_msg[mbox].mcback)
mport->inb_msg[mbox].mcback(mport,
priv->imsg_ring[mbox].dev_id, mbox, -1);
if (!(priv->flags & TSI721_USING_MSIX)) {
u32 ch_inte;
ch_inte = ioread32(priv->regs + TSI721_DEV_CHAN_INTE);
ch_inte |= TSI721_INT_IMSG_CHAN(ch);
iowrite32(ch_inte, priv->regs + TSI721_DEV_CHAN_INTE);
}
spin_unlock(&priv->imsg_ring[mbox].lock);
}
static int tsi721_open_inb_mbox(struct rio_mport *mport, void *dev_id,
int mbox, int entries)
{
struct tsi721_device *priv = mport->priv;
int ch = mbox + 4;
int i;
u64 *free_ptr;
int rc = 0;
if ((entries < TSI721_IMSGD_MIN_RING_SIZE) ||
(entries > TSI721_IMSGD_RING_SIZE) ||
(!is_power_of_2(entries)) || mbox >= RIO_MAX_MBOX) {
rc = -EINVAL;
goto out;
}
if ((mbox_sel & (1 << mbox)) == 0) {
rc = -ENODEV;
goto out;
}
priv->imsg_ring[mbox].dev_id = dev_id;
priv->imsg_ring[mbox].size = entries;
priv->imsg_ring[mbox].rx_slot = 0;
priv->imsg_ring[mbox].desc_rdptr = 0;
priv->imsg_ring[mbox].fq_wrptr = 0;
for (i = 0; i < priv->imsg_ring[mbox].size; i++)
priv->imsg_ring[mbox].imq_base[i] = NULL;
spin_lock_init(&priv->imsg_ring[mbox].lock);
priv->imsg_ring[mbox].buf_base =
dma_alloc_coherent(&priv->pdev->dev,
entries * TSI721_MSG_BUFFER_SIZE,
&priv->imsg_ring[mbox].buf_phys,
GFP_KERNEL);
if (priv->imsg_ring[mbox].buf_base == NULL) {
tsi_err(&priv->pdev->dev,
"Failed to allocate buffers for IB MBOX%d", mbox);
rc = -ENOMEM;
goto out;
}
priv->imsg_ring[mbox].imfq_base =
dma_alloc_coherent(&priv->pdev->dev,
entries * 8,
&priv->imsg_ring[mbox].imfq_phys,
GFP_KERNEL);
if (priv->imsg_ring[mbox].imfq_base == NULL) {
tsi_err(&priv->pdev->dev,
"Failed to allocate free queue for IB MBOX%d", mbox);
rc = -ENOMEM;
goto out_buf;
}
priv->imsg_ring[mbox].imd_base =
dma_alloc_coherent(&priv->pdev->dev,
entries * sizeof(struct tsi721_imsg_desc),
&priv->imsg_ring[mbox].imd_phys, GFP_KERNEL);
if (priv->imsg_ring[mbox].imd_base == NULL) {
tsi_err(&priv->pdev->dev,
"Failed to allocate descriptor memory for IB MBOX%d",
mbox);
rc = -ENOMEM;
goto out_dma;
}
free_ptr = priv->imsg_ring[mbox].imfq_base;
for (i = 0; i < entries; i++)
free_ptr[i] = cpu_to_le64(
(u64)(priv->imsg_ring[mbox].buf_phys) +
i * 0x1000);
mb();
if (!(priv->flags & TSI721_IMSGID_SET)) {
iowrite32((u32)priv->mport.host_deviceid,
priv->regs + TSI721_IB_DEVID);
priv->flags |= TSI721_IMSGID_SET;
}
iowrite32(((u64)priv->imsg_ring[mbox].imfq_phys >> 32),
priv->regs + TSI721_IBDMAC_FQBH(ch));
iowrite32(((u64)priv->imsg_ring[mbox].imfq_phys &
TSI721_IBDMAC_FQBL_MASK),
priv->regs+TSI721_IBDMAC_FQBL(ch));
iowrite32(TSI721_DMAC_DSSZ_SIZE(entries),
priv->regs + TSI721_IBDMAC_FQSZ(ch));
iowrite32(((u64)priv->imsg_ring[mbox].imd_phys >> 32),
priv->regs + TSI721_IBDMAC_DQBH(ch));
iowrite32(((u32)priv->imsg_ring[mbox].imd_phys &
(u32)TSI721_IBDMAC_DQBL_MASK),
priv->regs+TSI721_IBDMAC_DQBL(ch));
iowrite32(TSI721_DMAC_DSSZ_SIZE(entries),
priv->regs + TSI721_IBDMAC_DQSZ(ch));
#ifdef CONFIG_PCI_MSI
if (priv->flags & TSI721_USING_MSIX) {
int idx = TSI721_VECT_IMB0_RCV + mbox;
rc = request_irq(priv->msix[idx].vector, tsi721_imsg_msix, 0,
priv->msix[idx].irq_name, (void *)priv);
if (rc) {
tsi_debug(IMSG, &priv->pdev->dev,
"Unable to get MSI-X IRQ for IBOX%d-DONE",
mbox);
goto out_desc;
}
idx = TSI721_VECT_IMB0_INT + mbox;
rc = request_irq(priv->msix[idx].vector, tsi721_imsg_msix, 0,
priv->msix[idx].irq_name, (void *)priv);
if (rc) {
tsi_debug(IMSG, &priv->pdev->dev,
"Unable to get MSI-X IRQ for IBOX%d-INT", mbox);
free_irq(
priv->msix[TSI721_VECT_IMB0_RCV + mbox].vector,
(void *)priv);
goto out_desc;
}
}
#endif
tsi721_imsg_interrupt_enable(priv, ch, TSI721_IBDMAC_INT_ALL);
iowrite32(TSI721_IBDMAC_CTL_INIT, priv->regs + TSI721_IBDMAC_CTL(ch));
ioread32(priv->regs + TSI721_IBDMAC_CTL(ch));
udelay(10);
priv->imsg_ring[mbox].fq_wrptr = entries - 1;
iowrite32(entries - 1, priv->regs + TSI721_IBDMAC_FQWP(ch));
priv->imsg_init[mbox] = 1;
return 0;
#ifdef CONFIG_PCI_MSI
out_desc:
dma_free_coherent(&priv->pdev->dev,
priv->imsg_ring[mbox].size * sizeof(struct tsi721_imsg_desc),
priv->imsg_ring[mbox].imd_base,
priv->imsg_ring[mbox].imd_phys);
priv->imsg_ring[mbox].imd_base = NULL;
#endif
out_dma:
dma_free_coherent(&priv->pdev->dev,
priv->imsg_ring[mbox].size * 8,
priv->imsg_ring[mbox].imfq_base,
priv->imsg_ring[mbox].imfq_phys);
priv->imsg_ring[mbox].imfq_base = NULL;
out_buf:
dma_free_coherent(&priv->pdev->dev,
priv->imsg_ring[mbox].size * TSI721_MSG_BUFFER_SIZE,
priv->imsg_ring[mbox].buf_base,
priv->imsg_ring[mbox].buf_phys);
priv->imsg_ring[mbox].buf_base = NULL;
out:
return rc;
}
static void tsi721_close_inb_mbox(struct rio_mport *mport, int mbox)
{
struct tsi721_device *priv = mport->priv;
u32 rx_slot;
int ch = mbox + 4;
if (!priv->imsg_init[mbox])
return;
priv->imsg_init[mbox] = 0;
tsi721_imsg_interrupt_disable(priv, ch, TSI721_OBDMAC_INT_MASK);
#ifdef CONFIG_PCI_MSI
if (priv->flags & TSI721_USING_MSIX) {
free_irq(priv->msix[TSI721_VECT_IMB0_RCV + mbox].vector,
(void *)priv);
free_irq(priv->msix[TSI721_VECT_IMB0_INT + mbox].vector,
(void *)priv);
}
#endif
for (rx_slot = 0; rx_slot < priv->imsg_ring[mbox].size; rx_slot++)
priv->imsg_ring[mbox].imq_base[rx_slot] = NULL;
dma_free_coherent(&priv->pdev->dev,
priv->imsg_ring[mbox].size * TSI721_MSG_BUFFER_SIZE,
priv->imsg_ring[mbox].buf_base,
priv->imsg_ring[mbox].buf_phys);
priv->imsg_ring[mbox].buf_base = NULL;
dma_free_coherent(&priv->pdev->dev,
priv->imsg_ring[mbox].size * 8,
priv->imsg_ring[mbox].imfq_base,
priv->imsg_ring[mbox].imfq_phys);
priv->imsg_ring[mbox].imfq_base = NULL;
dma_free_coherent(&priv->pdev->dev,
priv->imsg_ring[mbox].size * sizeof(struct tsi721_imsg_desc),
priv->imsg_ring[mbox].imd_base,
priv->imsg_ring[mbox].imd_phys);
priv->imsg_ring[mbox].imd_base = NULL;
}
static int tsi721_add_inb_buffer(struct rio_mport *mport, int mbox, void *buf)
{
struct tsi721_device *priv = mport->priv;
u32 rx_slot;
int rc = 0;
rx_slot = priv->imsg_ring[mbox].rx_slot;
if (priv->imsg_ring[mbox].imq_base[rx_slot]) {
tsi_err(&priv->pdev->dev,
"Error adding inbound buffer %d, buffer exists",
rx_slot);
rc = -EINVAL;
goto out;
}
priv->imsg_ring[mbox].imq_base[rx_slot] = buf;
if (++priv->imsg_ring[mbox].rx_slot == priv->imsg_ring[mbox].size)
priv->imsg_ring[mbox].rx_slot = 0;
out:
return rc;
}
static void *tsi721_get_inb_message(struct rio_mport *mport, int mbox)
{
struct tsi721_device *priv = mport->priv;
struct tsi721_imsg_desc *desc;
u32 rx_slot;
void *rx_virt = NULL;
u64 rx_phys;
void *buf = NULL;
u64 *free_ptr;
int ch = mbox + 4;
int msg_size;
if (!priv->imsg_init[mbox])
return NULL;
desc = priv->imsg_ring[mbox].imd_base;
desc += priv->imsg_ring[mbox].desc_rdptr;
if (!(le32_to_cpu(desc->msg_info) & TSI721_IMD_HO))
goto out;
rx_slot = priv->imsg_ring[mbox].rx_slot;
while (priv->imsg_ring[mbox].imq_base[rx_slot] == NULL) {
if (++rx_slot == priv->imsg_ring[mbox].size)
rx_slot = 0;
}
rx_phys = ((u64)le32_to_cpu(desc->bufptr_hi) << 32) |
le32_to_cpu(desc->bufptr_lo);
rx_virt = priv->imsg_ring[mbox].buf_base +
(rx_phys - (u64)priv->imsg_ring[mbox].buf_phys);
buf = priv->imsg_ring[mbox].imq_base[rx_slot];
msg_size = le32_to_cpu(desc->msg_info) & TSI721_IMD_BCOUNT;
if (msg_size == 0)
msg_size = RIO_MAX_MSG_SIZE;
memcpy(buf, rx_virt, msg_size);
priv->imsg_ring[mbox].imq_base[rx_slot] = NULL;
desc->msg_info &= cpu_to_le32(~TSI721_IMD_HO);
if (++priv->imsg_ring[mbox].desc_rdptr == priv->imsg_ring[mbox].size)
priv->imsg_ring[mbox].desc_rdptr = 0;
iowrite32(priv->imsg_ring[mbox].desc_rdptr,
priv->regs + TSI721_IBDMAC_DQRP(ch));
free_ptr = priv->imsg_ring[mbox].imfq_base;
free_ptr[priv->imsg_ring[mbox].fq_wrptr] = cpu_to_le64(rx_phys);
if (++priv->imsg_ring[mbox].fq_wrptr == priv->imsg_ring[mbox].size)
priv->imsg_ring[mbox].fq_wrptr = 0;
iowrite32(priv->imsg_ring[mbox].fq_wrptr,
priv->regs + TSI721_IBDMAC_FQWP(ch));
out:
return buf;
}
static int tsi721_messages_init(struct tsi721_device *priv)
{
int ch;
iowrite32(0, priv->regs + TSI721_SMSG_ECC_LOG);
iowrite32(0, priv->regs + TSI721_RETRY_GEN_CNT);
iowrite32(0, priv->regs + TSI721_RETRY_RX_CNT);
iowrite32(TSI721_RQRPTO_VAL, priv->regs + TSI721_RQRPTO);
for (ch = 0; ch < TSI721_IMSG_CHNUM; ch++) {
iowrite32(TSI721_IBDMAC_INT_MASK,
priv->regs + TSI721_IBDMAC_INT(ch));
iowrite32(0, priv->regs + TSI721_IBDMAC_STS(ch));
iowrite32(TSI721_SMSG_ECC_COR_LOG_MASK,
priv->regs + TSI721_SMSG_ECC_COR_LOG(ch));
iowrite32(TSI721_SMSG_ECC_NCOR_MASK,
priv->regs + TSI721_SMSG_ECC_NCOR(ch));
}
return 0;
}
static int tsi721_query_mport(struct rio_mport *mport,
struct rio_mport_attr *attr)
{
struct tsi721_device *priv = mport->priv;
u32 rval;
rval = ioread32(priv->regs + 0x100 + RIO_PORT_N_ERR_STS_CSR(0, 0));
if (rval & RIO_PORT_N_ERR_STS_PORT_OK) {
rval = ioread32(priv->regs + 0x100 + RIO_PORT_N_CTL2_CSR(0, 0));
attr->link_speed = (rval & RIO_PORT_N_CTL2_SEL_BAUD) >> 28;
rval = ioread32(priv->regs + 0x100 + RIO_PORT_N_CTL_CSR(0, 0));
attr->link_width = (rval & RIO_PORT_N_CTL_IPW) >> 27;
} else
attr->link_speed = RIO_LINK_DOWN;
#ifdef CONFIG_RAPIDIO_DMA_ENGINE
attr->flags = RIO_MPORT_DMA | RIO_MPORT_DMA_SG;
attr->dma_max_sge = 0;
attr->dma_max_size = TSI721_BDMA_MAX_BCOUNT;
attr->dma_align = 0;
#else
attr->flags = 0;
#endif
return 0;
}
static void tsi721_disable_ints(struct tsi721_device *priv)
{
int ch;
iowrite32(0, priv->regs + TSI721_DEV_INTE);
iowrite32(0, priv->regs + TSI721_DEV_CHAN_INTE);
for (ch = 0; ch < TSI721_IMSG_CHNUM; ch++)
iowrite32(0, priv->regs + TSI721_IBDMAC_INTE(ch));
for (ch = 0; ch < TSI721_OMSG_CHNUM; ch++)
iowrite32(0, priv->regs + TSI721_OBDMAC_INTE(ch));
iowrite32(0, priv->regs + TSI721_SMSG_INTE);
for (ch = 0; ch < TSI721_DMA_MAXCH; ch++)
iowrite32(0,
priv->regs + TSI721_DMAC_BASE(ch) + TSI721_DMAC_INTE);
iowrite32(0, priv->regs + TSI721_BDMA_INTE);
for (ch = 0; ch < TSI721_SRIO_MAXCH; ch++)
iowrite32(0, priv->regs + TSI721_SR_CHINTE(ch));
iowrite32(0, priv->regs + TSI721_SR2PC_GEN_INTE);
iowrite32(0, priv->regs + TSI721_PC2SR_INTE);
iowrite32(0, priv->regs + TSI721_I2C_INT_ENABLE);
iowrite32(0, priv->regs + TSI721_RIO_EM_INT_ENABLE);
iowrite32(0, priv->regs + TSI721_RIO_EM_DEV_INT_EN);
}
static void tsi721_mport_release(struct device *dev)
{
struct rio_mport *mport = to_rio_mport(dev);
tsi_debug(EXIT, dev, "%s id=%d", mport->name, mport->id);
}
static int tsi721_setup_mport(struct tsi721_device *priv)
{
struct pci_dev *pdev = priv->pdev;
int err = 0;
struct rio_mport *mport = &priv->mport;
err = rio_mport_initialize(mport);
if (err)
return err;
mport->ops = &tsi721_rio_ops;
mport->index = 0;
mport->sys_size = 0;
mport->priv = (void *)priv;
mport->phys_efptr = 0x100;
mport->phys_rmap = 1;
mport->dev.parent = &pdev->dev;
mport->dev.release = tsi721_mport_release;
INIT_LIST_HEAD(&mport->dbells);
rio_init_dbell_res(&mport->riores[RIO_DOORBELL_RESOURCE], 0, 0xffff);
rio_init_mbox_res(&mport->riores[RIO_INB_MBOX_RESOURCE], 0, 3);
rio_init_mbox_res(&mport->riores[RIO_OUTB_MBOX_RESOURCE], 0, 3);
snprintf(mport->name, RIO_MAX_MPORT_NAME, "%s(%s)",
dev_driver_string(&pdev->dev), dev_name(&pdev->dev));
#ifdef CONFIG_PCI_MSI
if (!tsi721_enable_msix(priv))
priv->flags |= TSI721_USING_MSIX;
else if (!pci_enable_msi(pdev))
priv->flags |= TSI721_USING_MSI;
else
tsi_debug(MPORT, &pdev->dev,
"MSI/MSI-X is not available. Using legacy INTx.");
#endif
err = tsi721_request_irq(priv);
if (err) {
tsi_err(&pdev->dev, "Unable to get PCI IRQ %02X (err=0x%x)",
pdev->irq, err);
return err;
}
#ifdef CONFIG_RAPIDIO_DMA_ENGINE
err = tsi721_register_dma(priv);
if (err)
goto err_exit;
#endif
iowrite32(ioread32(priv->regs + TSI721_DEVCTL) |
TSI721_DEVCTL_SRBOOT_CMPL,
priv->regs + TSI721_DEVCTL);
if (mport->host_deviceid >= 0)
iowrite32(RIO_PORT_GEN_HOST | RIO_PORT_GEN_MASTER |
RIO_PORT_GEN_DISCOVERED,
priv->regs + (0x100 + RIO_PORT_GEN_CTL_CSR));
else
iowrite32(0, priv->regs + (0x100 + RIO_PORT_GEN_CTL_CSR));
err = rio_register_mport(mport);
if (err) {
tsi721_unregister_dma(priv);
goto err_exit;
}
return 0;
err_exit:
tsi721_free_irq(priv);
return err;
}
static int tsi721_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct tsi721_device *priv;
int err;
priv = kzalloc(sizeof(struct tsi721_device), GFP_KERNEL);
if (!priv) {
err = -ENOMEM;
goto err_exit;
}
err = pci_enable_device(pdev);
if (err) {
tsi_err(&pdev->dev, "Failed to enable PCI device");
goto err_clean;
}
priv->pdev = pdev;
#ifdef DEBUG
{
int i;
for (i = 0; i <= PCI_STD_RESOURCE_END; i++) {
tsi_debug(INIT, &pdev->dev, "res%d %pR",
i, &pdev->resource[i]);
}
}
#endif
if (!(pci_resource_flags(pdev, BAR_0) & IORESOURCE_MEM) ||
pci_resource_flags(pdev, BAR_0) & IORESOURCE_MEM_64 ||
pci_resource_len(pdev, BAR_0) < TSI721_REG_SPACE_SIZE) {
tsi_err(&pdev->dev, "Missing or misconfigured CSR BAR0");
err = -ENODEV;
goto err_disable_pdev;
}
if (!(pci_resource_flags(pdev, BAR_1) & IORESOURCE_MEM) ||
pci_resource_flags(pdev, BAR_1) & IORESOURCE_MEM_64 ||
pci_resource_len(pdev, BAR_1) < TSI721_DB_WIN_SIZE) {
tsi_err(&pdev->dev, "Missing or misconfigured Doorbell BAR1");
err = -ENODEV;
goto err_disable_pdev;
}
priv->p2r_bar[0].size = priv->p2r_bar[1].size = 0;
if (pci_resource_flags(pdev, BAR_2) & IORESOURCE_MEM_64) {
if (pci_resource_flags(pdev, BAR_2) & IORESOURCE_PREFETCH)
tsi_debug(INIT, &pdev->dev,
"Prefetchable OBW BAR2 will not be used");
else {
priv->p2r_bar[0].base = pci_resource_start(pdev, BAR_2);
priv->p2r_bar[0].size = pci_resource_len(pdev, BAR_2);
}
}
if (pci_resource_flags(pdev, BAR_4) & IORESOURCE_MEM_64) {
if (pci_resource_flags(pdev, BAR_4) & IORESOURCE_PREFETCH)
tsi_debug(INIT, &pdev->dev,
"Prefetchable OBW BAR4 will not be used");
else {
priv->p2r_bar[1].base = pci_resource_start(pdev, BAR_4);
priv->p2r_bar[1].size = pci_resource_len(pdev, BAR_4);
}
}
err = pci_request_regions(pdev, DRV_NAME);
if (err) {
tsi_err(&pdev->dev, "Unable to obtain PCI resources");
goto err_disable_pdev;
}
pci_set_master(pdev);
priv->regs = pci_ioremap_bar(pdev, BAR_0);
if (!priv->regs) {
tsi_err(&pdev->dev, "Unable to map device registers space");
err = -ENOMEM;
goto err_free_res;
}
priv->odb_base = pci_ioremap_bar(pdev, BAR_1);
if (!priv->odb_base) {
tsi_err(&pdev->dev, "Unable to map outbound doorbells space");
err = -ENOMEM;
goto err_unmap_bars;
}
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
tsi_err(&pdev->dev, "Unable to set DMA mask");
goto err_unmap_bars;
}
if (pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32)))
tsi_info(&pdev->dev, "Unable to set consistent DMA mask");
} else {
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (err)
tsi_info(&pdev->dev, "Unable to set consistent DMA mask");
}
BUG_ON(!pci_is_pcie(pdev));
pcie_capability_clear_and_set_word(pdev, PCI_EXP_DEVCTL,
PCI_EXP_DEVCTL_RELAX_EN | PCI_EXP_DEVCTL_NOSNOOP_EN, 0);
if (pcie_mrrs >= 0) {
if (pcie_mrrs <= 5)
pcie_capability_clear_and_set_word(pdev, PCI_EXP_DEVCTL,
PCI_EXP_DEVCTL_READRQ, pcie_mrrs << 12);
else
tsi_info(&pdev->dev,
"Invalid MRRS override value %d", pcie_mrrs);
}
pcie_capability_clear_and_set_word(pdev, PCI_EXP_DEVCTL2, 0xf, 0x2);
pci_write_config_dword(pdev, TSI721_PCIECFG_EPCTL, 0x01);
pci_write_config_dword(pdev, TSI721_PCIECFG_MSIXTBL,
TSI721_MSIXTBL_OFFSET);
pci_write_config_dword(pdev, TSI721_PCIECFG_MSIXPBA,
TSI721_MSIXPBA_OFFSET);
pci_write_config_dword(pdev, TSI721_PCIECFG_EPCTL, 0);
tsi721_disable_ints(priv);
tsi721_init_pc2sr_mapping(priv);
tsi721_init_sr2pc_mapping(priv);
if (tsi721_bdma_maint_init(priv)) {
tsi_err(&pdev->dev, "BDMA initialization failed");
err = -ENOMEM;
goto err_unmap_bars;
}
err = tsi721_doorbell_init(priv);
if (err)
goto err_free_bdma;
tsi721_port_write_init(priv);
err = tsi721_messages_init(priv);
if (err)
goto err_free_consistent;
err = tsi721_setup_mport(priv);
if (err)
goto err_free_consistent;
pci_set_drvdata(pdev, priv);
tsi721_interrupts_init(priv);
return 0;
err_free_consistent:
tsi721_port_write_free(priv);
tsi721_doorbell_free(priv);
err_free_bdma:
tsi721_bdma_maint_free(priv);
err_unmap_bars:
if (priv->regs)
iounmap(priv->regs);
if (priv->odb_base)
iounmap(priv->odb_base);
err_free_res:
pci_release_regions(pdev);
pci_clear_master(pdev);
err_disable_pdev:
pci_disable_device(pdev);
err_clean:
kfree(priv);
err_exit:
return err;
}
static void tsi721_remove(struct pci_dev *pdev)
{
struct tsi721_device *priv = pci_get_drvdata(pdev);
tsi_debug(EXIT, &pdev->dev, "enter");
tsi721_disable_ints(priv);
tsi721_free_irq(priv);
flush_scheduled_work();
rio_unregister_mport(&priv->mport);
tsi721_unregister_dma(priv);
tsi721_bdma_maint_free(priv);
tsi721_doorbell_free(priv);
tsi721_port_write_free(priv);
tsi721_close_sr2pc_mapping(priv);
if (priv->regs)
iounmap(priv->regs);
if (priv->odb_base)
iounmap(priv->odb_base);
#ifdef CONFIG_PCI_MSI
if (priv->flags & TSI721_USING_MSIX)
pci_disable_msix(priv->pdev);
else if (priv->flags & TSI721_USING_MSI)
pci_disable_msi(priv->pdev);
#endif
pci_release_regions(pdev);
pci_clear_master(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
kfree(priv);
tsi_debug(EXIT, &pdev->dev, "exit");
}
static void tsi721_shutdown(struct pci_dev *pdev)
{
struct tsi721_device *priv = pci_get_drvdata(pdev);
tsi_debug(EXIT, &pdev->dev, "enter");
tsi721_disable_ints(priv);
tsi721_dma_stop_all(priv);
pci_clear_master(pdev);
pci_disable_device(pdev);
}
