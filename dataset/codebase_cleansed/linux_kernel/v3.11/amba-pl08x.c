static inline struct pl08x_dma_chan *to_pl08x_chan(struct dma_chan *chan)
{
return container_of(chan, struct pl08x_dma_chan, vc.chan);
}
static inline struct pl08x_txd *to_pl08x_txd(struct dma_async_tx_descriptor *tx)
{
return container_of(tx, struct pl08x_txd, vd.tx);
}
static int pl08x_request_mux(struct pl08x_dma_chan *plchan)
{
const struct pl08x_platform_data *pd = plchan->host->pd;
int ret;
if (plchan->mux_use++ == 0 && pd->get_xfer_signal) {
ret = pd->get_xfer_signal(plchan->cd);
if (ret < 0) {
plchan->mux_use = 0;
return ret;
}
plchan->signal = ret;
}
return 0;
}
static void pl08x_release_mux(struct pl08x_dma_chan *plchan)
{
const struct pl08x_platform_data *pd = plchan->host->pd;
if (plchan->signal >= 0) {
WARN_ON(plchan->mux_use == 0);
if (--plchan->mux_use == 0 && pd->put_xfer_signal) {
pd->put_xfer_signal(plchan->cd, plchan->signal);
plchan->signal = -1;
}
}
}
static int pl08x_phy_channel_busy(struct pl08x_phy_chan *ch)
{
unsigned int val;
val = readl(ch->base + PL080_CH_CONFIG);
return val & PL080_CONFIG_ACTIVE;
}
static void pl08x_start_next_txd(struct pl08x_dma_chan *plchan)
{
struct pl08x_driver_data *pl08x = plchan->host;
struct pl08x_phy_chan *phychan = plchan->phychan;
struct virt_dma_desc *vd = vchan_next_desc(&plchan->vc);
struct pl08x_txd *txd = to_pl08x_txd(&vd->tx);
struct pl08x_lli *lli;
u32 val;
list_del(&txd->vd.node);
plchan->at = txd;
while (pl08x_phy_channel_busy(phychan))
cpu_relax();
lli = &txd->llis_va[0];
dev_vdbg(&pl08x->adev->dev,
"WRITE channel %d: csrc=0x%08x, cdst=0x%08x, "
"clli=0x%08x, cctl=0x%08x, ccfg=0x%08x\n",
phychan->id, lli->src, lli->dst, lli->lli, lli->cctl,
txd->ccfg);
writel(lli->src, phychan->base + PL080_CH_SRC_ADDR);
writel(lli->dst, phychan->base + PL080_CH_DST_ADDR);
writel(lli->lli, phychan->base + PL080_CH_LLI);
writel(lli->cctl, phychan->base + PL080_CH_CONTROL);
writel(txd->ccfg, phychan->base + PL080_CH_CONFIG);
while (readl(pl08x->base + PL080_EN_CHAN) & (1 << phychan->id))
cpu_relax();
val = readl(phychan->base + PL080_CH_CONFIG);
while ((val & PL080_CONFIG_ACTIVE) || (val & PL080_CONFIG_ENABLE))
val = readl(phychan->base + PL080_CH_CONFIG);
writel(val | PL080_CONFIG_ENABLE, phychan->base + PL080_CH_CONFIG);
}
static void pl08x_pause_phy_chan(struct pl08x_phy_chan *ch)
{
u32 val;
int timeout;
val = readl(ch->base + PL080_CH_CONFIG);
val |= PL080_CONFIG_HALT;
writel(val, ch->base + PL080_CH_CONFIG);
for (timeout = 1000; timeout; timeout--) {
if (!pl08x_phy_channel_busy(ch))
break;
udelay(1);
}
if (pl08x_phy_channel_busy(ch))
pr_err("pl08x: channel%u timeout waiting for pause\n", ch->id);
}
static void pl08x_resume_phy_chan(struct pl08x_phy_chan *ch)
{
u32 val;
val = readl(ch->base + PL080_CH_CONFIG);
val &= ~PL080_CONFIG_HALT;
writel(val, ch->base + PL080_CH_CONFIG);
}
static void pl08x_terminate_phy_chan(struct pl08x_driver_data *pl08x,
struct pl08x_phy_chan *ch)
{
u32 val = readl(ch->base + PL080_CH_CONFIG);
val &= ~(PL080_CONFIG_ENABLE | PL080_CONFIG_ERR_IRQ_MASK |
PL080_CONFIG_TC_IRQ_MASK);
writel(val, ch->base + PL080_CH_CONFIG);
writel(1 << ch->id, pl08x->base + PL080_ERR_CLEAR);
writel(1 << ch->id, pl08x->base + PL080_TC_CLEAR);
}
static inline u32 get_bytes_in_cctl(u32 cctl)
{
u32 bytes = cctl & PL080_CONTROL_TRANSFER_SIZE_MASK;
switch (cctl >> PL080_CONTROL_SWIDTH_SHIFT) {
case PL080_WIDTH_8BIT:
break;
case PL080_WIDTH_16BIT:
bytes *= 2;
break;
case PL080_WIDTH_32BIT:
bytes *= 4;
break;
}
return bytes;
}
static u32 pl08x_getbytes_chan(struct pl08x_dma_chan *plchan)
{
struct pl08x_phy_chan *ch;
struct pl08x_txd *txd;
size_t bytes = 0;
ch = plchan->phychan;
txd = plchan->at;
if (ch && txd) {
u32 clli = readl(ch->base + PL080_CH_LLI) & ~PL080_LLI_LM_AHB2;
bytes = get_bytes_in_cctl(readl(ch->base + PL080_CH_CONTROL));
if (clli) {
struct pl08x_lli *llis_va = txd->llis_va;
dma_addr_t llis_bus = txd->llis_bus;
int index;
BUG_ON(clli < llis_bus || clli >= llis_bus +
sizeof(struct pl08x_lli) * MAX_NUM_TSFR_LLIS);
index = (clli - llis_bus) / sizeof(struct pl08x_lli);
for (; index < MAX_NUM_TSFR_LLIS; index++) {
bytes += get_bytes_in_cctl(llis_va[index].cctl);
if (!llis_va[index].lli)
break;
}
}
}
return bytes;
}
static struct pl08x_phy_chan *
pl08x_get_phy_channel(struct pl08x_driver_data *pl08x,
struct pl08x_dma_chan *virt_chan)
{
struct pl08x_phy_chan *ch = NULL;
unsigned long flags;
int i;
for (i = 0; i < pl08x->vd->channels; i++) {
ch = &pl08x->phy_chans[i];
spin_lock_irqsave(&ch->lock, flags);
if (!ch->locked && !ch->serving) {
ch->serving = virt_chan;
spin_unlock_irqrestore(&ch->lock, flags);
break;
}
spin_unlock_irqrestore(&ch->lock, flags);
}
if (i == pl08x->vd->channels) {
return NULL;
}
return ch;
}
static inline void pl08x_put_phy_channel(struct pl08x_driver_data *pl08x,
struct pl08x_phy_chan *ch)
{
ch->serving = NULL;
}
static void pl08x_phy_alloc_and_start(struct pl08x_dma_chan *plchan)
{
struct pl08x_driver_data *pl08x = plchan->host;
struct pl08x_phy_chan *ch;
ch = pl08x_get_phy_channel(pl08x, plchan);
if (!ch) {
dev_dbg(&pl08x->adev->dev, "no physical channel available for xfer on %s\n", plchan->name);
plchan->state = PL08X_CHAN_WAITING;
return;
}
dev_dbg(&pl08x->adev->dev, "allocated physical channel %d for xfer on %s\n",
ch->id, plchan->name);
plchan->phychan = ch;
plchan->state = PL08X_CHAN_RUNNING;
pl08x_start_next_txd(plchan);
}
static void pl08x_phy_reassign_start(struct pl08x_phy_chan *ch,
struct pl08x_dma_chan *plchan)
{
struct pl08x_driver_data *pl08x = plchan->host;
dev_dbg(&pl08x->adev->dev, "reassigned physical channel %d for xfer on %s\n",
ch->id, plchan->name);
ch->serving = plchan;
plchan->phychan = ch;
plchan->state = PL08X_CHAN_RUNNING;
pl08x_start_next_txd(plchan);
}
static void pl08x_phy_free(struct pl08x_dma_chan *plchan)
{
struct pl08x_driver_data *pl08x = plchan->host;
struct pl08x_dma_chan *p, *next;
retry:
next = NULL;
list_for_each_entry(p, &pl08x->memcpy.channels, vc.chan.device_node)
if (p->state == PL08X_CHAN_WAITING) {
next = p;
break;
}
if (!next) {
list_for_each_entry(p, &pl08x->slave.channels, vc.chan.device_node)
if (p->state == PL08X_CHAN_WAITING) {
next = p;
break;
}
}
pl08x_terminate_phy_chan(pl08x, plchan->phychan);
if (next) {
bool success;
spin_lock(&next->vc.lock);
success = next->state == PL08X_CHAN_WAITING;
if (success)
pl08x_phy_reassign_start(plchan->phychan, next);
spin_unlock(&next->vc.lock);
if (!success)
goto retry;
} else {
pl08x_put_phy_channel(pl08x, plchan->phychan);
}
plchan->phychan = NULL;
plchan->state = PL08X_CHAN_IDLE;
}
static inline unsigned int pl08x_get_bytes_for_cctl(unsigned int coded)
{
switch (coded) {
case PL080_WIDTH_8BIT:
return 1;
case PL080_WIDTH_16BIT:
return 2;
case PL080_WIDTH_32BIT:
return 4;
default:
break;
}
BUG();
return 0;
}
static inline u32 pl08x_cctl_bits(u32 cctl, u8 srcwidth, u8 dstwidth,
size_t tsize)
{
u32 retbits = cctl;
retbits &= ~PL080_CONTROL_DWIDTH_MASK;
retbits &= ~PL080_CONTROL_SWIDTH_MASK;
retbits &= ~PL080_CONTROL_TRANSFER_SIZE_MASK;
switch (srcwidth) {
case 1:
retbits |= PL080_WIDTH_8BIT << PL080_CONTROL_SWIDTH_SHIFT;
break;
case 2:
retbits |= PL080_WIDTH_16BIT << PL080_CONTROL_SWIDTH_SHIFT;
break;
case 4:
retbits |= PL080_WIDTH_32BIT << PL080_CONTROL_SWIDTH_SHIFT;
break;
default:
BUG();
break;
}
switch (dstwidth) {
case 1:
retbits |= PL080_WIDTH_8BIT << PL080_CONTROL_DWIDTH_SHIFT;
break;
case 2:
retbits |= PL080_WIDTH_16BIT << PL080_CONTROL_DWIDTH_SHIFT;
break;
case 4:
retbits |= PL080_WIDTH_32BIT << PL080_CONTROL_DWIDTH_SHIFT;
break;
default:
BUG();
break;
}
retbits |= tsize << PL080_CONTROL_TRANSFER_SIZE_SHIFT;
return retbits;
}
static void pl08x_choose_master_bus(struct pl08x_lli_build_data *bd,
struct pl08x_bus_data **mbus, struct pl08x_bus_data **sbus, u32 cctl)
{
if (!(cctl & PL080_CONTROL_DST_INCR)) {
*mbus = &bd->dstbus;
*sbus = &bd->srcbus;
} else if (!(cctl & PL080_CONTROL_SRC_INCR)) {
*mbus = &bd->srcbus;
*sbus = &bd->dstbus;
} else {
if (bd->dstbus.buswidth >= bd->srcbus.buswidth) {
*mbus = &bd->dstbus;
*sbus = &bd->srcbus;
} else {
*mbus = &bd->srcbus;
*sbus = &bd->dstbus;
}
}
}
static void pl08x_fill_lli_for_desc(struct pl08x_lli_build_data *bd,
int num_llis, int len, u32 cctl)
{
struct pl08x_lli *llis_va = bd->txd->llis_va;
dma_addr_t llis_bus = bd->txd->llis_bus;
BUG_ON(num_llis >= MAX_NUM_TSFR_LLIS);
llis_va[num_llis].cctl = cctl;
llis_va[num_llis].src = bd->srcbus.addr;
llis_va[num_llis].dst = bd->dstbus.addr;
llis_va[num_llis].lli = llis_bus + (num_llis + 1) *
sizeof(struct pl08x_lli);
llis_va[num_llis].lli |= bd->lli_bus;
if (cctl & PL080_CONTROL_SRC_INCR)
bd->srcbus.addr += len;
if (cctl & PL080_CONTROL_DST_INCR)
bd->dstbus.addr += len;
BUG_ON(bd->remainder < len);
bd->remainder -= len;
}
static inline void prep_byte_width_lli(struct pl08x_lli_build_data *bd,
u32 *cctl, u32 len, int num_llis, size_t *total_bytes)
{
*cctl = pl08x_cctl_bits(*cctl, 1, 1, len);
pl08x_fill_lli_for_desc(bd, num_llis, len, *cctl);
(*total_bytes) += len;
}
static int pl08x_fill_llis_for_desc(struct pl08x_driver_data *pl08x,
struct pl08x_txd *txd)
{
struct pl08x_bus_data *mbus, *sbus;
struct pl08x_lli_build_data bd;
int num_llis = 0;
u32 cctl, early_bytes = 0;
size_t max_bytes_per_lli, total_bytes;
struct pl08x_lli *llis_va;
struct pl08x_sg *dsg;
txd->llis_va = dma_pool_alloc(pl08x->pool, GFP_NOWAIT, &txd->llis_bus);
if (!txd->llis_va) {
dev_err(&pl08x->adev->dev, "%s no memory for llis\n", __func__);
return 0;
}
bd.txd = txd;
bd.lli_bus = (pl08x->lli_buses & PL08X_AHB2) ? PL080_LLI_LM_AHB2 : 0;
cctl = txd->cctl;
bd.srcbus.maxwidth =
pl08x_get_bytes_for_cctl((cctl & PL080_CONTROL_SWIDTH_MASK) >>
PL080_CONTROL_SWIDTH_SHIFT);
bd.dstbus.maxwidth =
pl08x_get_bytes_for_cctl((cctl & PL080_CONTROL_DWIDTH_MASK) >>
PL080_CONTROL_DWIDTH_SHIFT);
list_for_each_entry(dsg, &txd->dsg_list, node) {
total_bytes = 0;
cctl = txd->cctl;
bd.srcbus.addr = dsg->src_addr;
bd.dstbus.addr = dsg->dst_addr;
bd.remainder = dsg->len;
bd.srcbus.buswidth = bd.srcbus.maxwidth;
bd.dstbus.buswidth = bd.dstbus.maxwidth;
pl08x_choose_master_bus(&bd, &mbus, &sbus, cctl);
dev_vdbg(&pl08x->adev->dev, "src=0x%08x%s/%u dst=0x%08x%s/%u len=%zu\n",
bd.srcbus.addr, cctl & PL080_CONTROL_SRC_INCR ? "+" : "",
bd.srcbus.buswidth,
bd.dstbus.addr, cctl & PL080_CONTROL_DST_INCR ? "+" : "",
bd.dstbus.buswidth,
bd.remainder);
dev_vdbg(&pl08x->adev->dev, "mbus=%s sbus=%s\n",
mbus == &bd.srcbus ? "src" : "dst",
sbus == &bd.srcbus ? "src" : "dst");
if (!bd.remainder) {
u32 fc = (txd->ccfg & PL080_CONFIG_FLOW_CONTROL_MASK) >>
PL080_CONFIG_FLOW_CONTROL_SHIFT;
if (!((fc >= PL080_FLOW_SRC2DST_DST) &&
(fc <= PL080_FLOW_SRC2DST_SRC))) {
dev_err(&pl08x->adev->dev, "%s sg len can't be zero",
__func__);
return 0;
}
if ((bd.srcbus.addr % bd.srcbus.buswidth) ||
(bd.dstbus.addr % bd.dstbus.buswidth)) {
dev_err(&pl08x->adev->dev,
"%s src & dst address must be aligned to src"
" & dst width if peripheral is flow controller",
__func__);
return 0;
}
cctl = pl08x_cctl_bits(cctl, bd.srcbus.buswidth,
bd.dstbus.buswidth, 0);
pl08x_fill_lli_for_desc(&bd, num_llis++, 0, cctl);
break;
}
if (bd.remainder < mbus->buswidth)
early_bytes = bd.remainder;
else if ((mbus->addr) % (mbus->buswidth)) {
early_bytes = mbus->buswidth - (mbus->addr) %
(mbus->buswidth);
if ((bd.remainder - early_bytes) < mbus->buswidth)
early_bytes = bd.remainder;
}
if (early_bytes) {
dev_vdbg(&pl08x->adev->dev,
"%s byte width LLIs (remain 0x%08x)\n",
__func__, bd.remainder);
prep_byte_width_lli(&bd, &cctl, early_bytes, num_llis++,
&total_bytes);
}
if (bd.remainder) {
if (sbus->addr % sbus->buswidth) {
dev_dbg(&pl08x->adev->dev,
"%s set down bus width to one byte\n",
__func__);
sbus->buswidth = 1;
}
max_bytes_per_lli = bd.srcbus.buswidth *
PL080_CONTROL_TRANSFER_SIZE_MASK;
dev_vdbg(&pl08x->adev->dev,
"%s max bytes per lli = %zu\n",
__func__, max_bytes_per_lli);
while (bd.remainder > (mbus->buswidth - 1)) {
size_t lli_len, tsize, width;
lli_len = min(bd.remainder, max_bytes_per_lli);
width = max(mbus->buswidth, sbus->buswidth);
lli_len = (lli_len / width) * width;
tsize = lli_len / bd.srcbus.buswidth;
dev_vdbg(&pl08x->adev->dev,
"%s fill lli with single lli chunk of "
"size 0x%08zx (remainder 0x%08zx)\n",
__func__, lli_len, bd.remainder);
cctl = pl08x_cctl_bits(cctl, bd.srcbus.buswidth,
bd.dstbus.buswidth, tsize);
pl08x_fill_lli_for_desc(&bd, num_llis++,
lli_len, cctl);
total_bytes += lli_len;
}
if (bd.remainder) {
dev_vdbg(&pl08x->adev->dev,
"%s align with boundary, send odd bytes (remain %zu)\n",
__func__, bd.remainder);
prep_byte_width_lli(&bd, &cctl, bd.remainder,
num_llis++, &total_bytes);
}
}
if (total_bytes != dsg->len) {
dev_err(&pl08x->adev->dev,
"%s size of encoded lli:s don't match total txd, transferred 0x%08zx from size 0x%08zx\n",
__func__, total_bytes, dsg->len);
return 0;
}
if (num_llis >= MAX_NUM_TSFR_LLIS) {
dev_err(&pl08x->adev->dev,
"%s need to increase MAX_NUM_TSFR_LLIS from 0x%08x\n",
__func__, (u32) MAX_NUM_TSFR_LLIS);
return 0;
}
}
llis_va = txd->llis_va;
llis_va[num_llis - 1].lli = 0;
llis_va[num_llis - 1].cctl |= PL080_CONTROL_TC_IRQ_EN;
#ifdef VERBOSE_DEBUG
{
int i;
dev_vdbg(&pl08x->adev->dev,
"%-3s %-9s %-10s %-10s %-10s %s\n",
"lli", "", "csrc", "cdst", "clli", "cctl");
for (i = 0; i < num_llis; i++) {
dev_vdbg(&pl08x->adev->dev,
"%3d @%p: 0x%08x 0x%08x 0x%08x 0x%08x\n",
i, &llis_va[i], llis_va[i].src,
llis_va[i].dst, llis_va[i].lli, llis_va[i].cctl
);
}
}
#endif
return num_llis;
}
static void pl08x_free_txd(struct pl08x_driver_data *pl08x,
struct pl08x_txd *txd)
{
struct pl08x_sg *dsg, *_dsg;
if (txd->llis_va)
dma_pool_free(pl08x->pool, txd->llis_va, txd->llis_bus);
list_for_each_entry_safe(dsg, _dsg, &txd->dsg_list, node) {
list_del(&dsg->node);
kfree(dsg);
}
kfree(txd);
}
static void pl08x_unmap_buffers(struct pl08x_txd *txd)
{
struct device *dev = txd->vd.tx.chan->device->dev;
struct pl08x_sg *dsg;
if (!(txd->vd.tx.flags & DMA_COMPL_SKIP_SRC_UNMAP)) {
if (txd->vd.tx.flags & DMA_COMPL_SRC_UNMAP_SINGLE)
list_for_each_entry(dsg, &txd->dsg_list, node)
dma_unmap_single(dev, dsg->src_addr, dsg->len,
DMA_TO_DEVICE);
else {
list_for_each_entry(dsg, &txd->dsg_list, node)
dma_unmap_page(dev, dsg->src_addr, dsg->len,
DMA_TO_DEVICE);
}
}
if (!(txd->vd.tx.flags & DMA_COMPL_SKIP_DEST_UNMAP)) {
if (txd->vd.tx.flags & DMA_COMPL_DEST_UNMAP_SINGLE)
list_for_each_entry(dsg, &txd->dsg_list, node)
dma_unmap_single(dev, dsg->dst_addr, dsg->len,
DMA_FROM_DEVICE);
else
list_for_each_entry(dsg, &txd->dsg_list, node)
dma_unmap_page(dev, dsg->dst_addr, dsg->len,
DMA_FROM_DEVICE);
}
}
static void pl08x_desc_free(struct virt_dma_desc *vd)
{
struct pl08x_txd *txd = to_pl08x_txd(&vd->tx);
struct pl08x_dma_chan *plchan = to_pl08x_chan(vd->tx.chan);
if (!plchan->slave)
pl08x_unmap_buffers(txd);
if (!txd->done)
pl08x_release_mux(plchan);
pl08x_free_txd(plchan->host, txd);
}
static void pl08x_free_txd_list(struct pl08x_driver_data *pl08x,
struct pl08x_dma_chan *plchan)
{
LIST_HEAD(head);
vchan_get_all_descriptors(&plchan->vc, &head);
vchan_dma_desc_free_list(&plchan->vc, &head);
}
static int pl08x_alloc_chan_resources(struct dma_chan *chan)
{
return 0;
}
static void pl08x_free_chan_resources(struct dma_chan *chan)
{
vchan_free_chan_resources(to_virt_chan(chan));
}
static struct dma_async_tx_descriptor *pl08x_prep_dma_interrupt(
struct dma_chan *chan, unsigned long flags)
{
struct dma_async_tx_descriptor *retval = NULL;
return retval;
}
static enum dma_status pl08x_dma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie, struct dma_tx_state *txstate)
{
struct pl08x_dma_chan *plchan = to_pl08x_chan(chan);
struct virt_dma_desc *vd;
unsigned long flags;
enum dma_status ret;
size_t bytes = 0;
ret = dma_cookie_status(chan, cookie, txstate);
if (ret == DMA_SUCCESS)
return ret;
if (!txstate) {
if (plchan->state == PL08X_CHAN_PAUSED)
ret = DMA_PAUSED;
return ret;
}
spin_lock_irqsave(&plchan->vc.lock, flags);
ret = dma_cookie_status(chan, cookie, txstate);
if (ret != DMA_SUCCESS) {
vd = vchan_find_desc(&plchan->vc, cookie);
if (vd) {
struct pl08x_txd *txd = to_pl08x_txd(&vd->tx);
struct pl08x_sg *dsg;
list_for_each_entry(dsg, &txd->dsg_list, node)
bytes += dsg->len;
} else {
bytes = pl08x_getbytes_chan(plchan);
}
}
spin_unlock_irqrestore(&plchan->vc.lock, flags);
dma_set_residue(txstate, bytes);
if (plchan->state == PL08X_CHAN_PAUSED && ret == DMA_IN_PROGRESS)
ret = DMA_PAUSED;
return ret;
}
static u32 pl08x_select_bus(u8 src, u8 dst)
{
u32 cctl = 0;
if (!(dst & PL08X_AHB1) || ((dst & PL08X_AHB2) && (src & PL08X_AHB1)))
cctl |= PL080_CONTROL_DST_AHB2;
if (!(src & PL08X_AHB1) || ((src & PL08X_AHB2) && !(dst & PL08X_AHB2)))
cctl |= PL080_CONTROL_SRC_AHB2;
return cctl;
}
static u32 pl08x_cctl(u32 cctl)
{
cctl &= ~(PL080_CONTROL_SRC_AHB2 | PL080_CONTROL_DST_AHB2 |
PL080_CONTROL_SRC_INCR | PL080_CONTROL_DST_INCR |
PL080_CONTROL_PROT_MASK);
return cctl | PL080_CONTROL_PROT_SYS;
}
static u32 pl08x_width(enum dma_slave_buswidth width)
{
switch (width) {
case DMA_SLAVE_BUSWIDTH_1_BYTE:
return PL080_WIDTH_8BIT;
case DMA_SLAVE_BUSWIDTH_2_BYTES:
return PL080_WIDTH_16BIT;
case DMA_SLAVE_BUSWIDTH_4_BYTES:
return PL080_WIDTH_32BIT;
default:
return ~0;
}
}
static u32 pl08x_burst(u32 maxburst)
{
int i;
for (i = 0; i < ARRAY_SIZE(burst_sizes); i++)
if (burst_sizes[i].burstwords <= maxburst)
break;
return burst_sizes[i].reg;
}
static u32 pl08x_get_cctl(struct pl08x_dma_chan *plchan,
enum dma_slave_buswidth addr_width, u32 maxburst)
{
u32 width, burst, cctl = 0;
width = pl08x_width(addr_width);
if (width == ~0)
return ~0;
cctl |= width << PL080_CONTROL_SWIDTH_SHIFT;
cctl |= width << PL080_CONTROL_DWIDTH_SHIFT;
if (plchan->cd->single)
maxburst = 1;
burst = pl08x_burst(maxburst);
cctl |= burst << PL080_CONTROL_SB_SIZE_SHIFT;
cctl |= burst << PL080_CONTROL_DB_SIZE_SHIFT;
return pl08x_cctl(cctl);
}
static int dma_set_runtime_config(struct dma_chan *chan,
struct dma_slave_config *config)
{
struct pl08x_dma_chan *plchan = to_pl08x_chan(chan);
if (!plchan->slave)
return -EINVAL;
if (config->src_addr_width == DMA_SLAVE_BUSWIDTH_8_BYTES ||
config->dst_addr_width == DMA_SLAVE_BUSWIDTH_8_BYTES)
return -EINVAL;
plchan->cfg = *config;
return 0;
}
static void pl08x_issue_pending(struct dma_chan *chan)
{
struct pl08x_dma_chan *plchan = to_pl08x_chan(chan);
unsigned long flags;
spin_lock_irqsave(&plchan->vc.lock, flags);
if (vchan_issue_pending(&plchan->vc)) {
if (!plchan->phychan && plchan->state != PL08X_CHAN_WAITING)
pl08x_phy_alloc_and_start(plchan);
}
spin_unlock_irqrestore(&plchan->vc.lock, flags);
}
static struct pl08x_txd *pl08x_get_txd(struct pl08x_dma_chan *plchan)
{
struct pl08x_txd *txd = kzalloc(sizeof(*txd), GFP_NOWAIT);
if (txd) {
INIT_LIST_HEAD(&txd->dsg_list);
txd->ccfg = PL080_CONFIG_ERR_IRQ_MASK |
PL080_CONFIG_TC_IRQ_MASK;
}
return txd;
}
static struct dma_async_tx_descriptor *pl08x_prep_dma_memcpy(
struct dma_chan *chan, dma_addr_t dest, dma_addr_t src,
size_t len, unsigned long flags)
{
struct pl08x_dma_chan *plchan = to_pl08x_chan(chan);
struct pl08x_driver_data *pl08x = plchan->host;
struct pl08x_txd *txd;
struct pl08x_sg *dsg;
int ret;
txd = pl08x_get_txd(plchan);
if (!txd) {
dev_err(&pl08x->adev->dev,
"%s no memory for descriptor\n", __func__);
return NULL;
}
dsg = kzalloc(sizeof(struct pl08x_sg), GFP_NOWAIT);
if (!dsg) {
pl08x_free_txd(pl08x, txd);
dev_err(&pl08x->adev->dev, "%s no memory for pl080 sg\n",
__func__);
return NULL;
}
list_add_tail(&dsg->node, &txd->dsg_list);
dsg->src_addr = src;
dsg->dst_addr = dest;
dsg->len = len;
txd->ccfg |= PL080_FLOW_MEM2MEM << PL080_CONFIG_FLOW_CONTROL_SHIFT;
txd->cctl = pl08x->pd->memcpy_channel.cctl_memcpy &
~(PL080_CONTROL_DST_AHB2 | PL080_CONTROL_SRC_AHB2);
txd->cctl |= PL080_CONTROL_SRC_INCR | PL080_CONTROL_DST_INCR;
if (pl08x->vd->dualmaster)
txd->cctl |= pl08x_select_bus(pl08x->mem_buses,
pl08x->mem_buses);
ret = pl08x_fill_llis_for_desc(plchan->host, txd);
if (!ret) {
pl08x_free_txd(pl08x, txd);
return NULL;
}
return vchan_tx_prep(&plchan->vc, &txd->vd, flags);
}
static struct dma_async_tx_descriptor *pl08x_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long flags, void *context)
{
struct pl08x_dma_chan *plchan = to_pl08x_chan(chan);
struct pl08x_driver_data *pl08x = plchan->host;
struct pl08x_txd *txd;
struct pl08x_sg *dsg;
struct scatterlist *sg;
enum dma_slave_buswidth addr_width;
dma_addr_t slave_addr;
int ret, tmp;
u8 src_buses, dst_buses;
u32 maxburst, cctl;
dev_dbg(&pl08x->adev->dev, "%s prepare transaction of %d bytes from %s\n",
__func__, sg_dma_len(sgl), plchan->name);
txd = pl08x_get_txd(plchan);
if (!txd) {
dev_err(&pl08x->adev->dev, "%s no txd\n", __func__);
return NULL;
}
if (direction == DMA_MEM_TO_DEV) {
cctl = PL080_CONTROL_SRC_INCR;
slave_addr = plchan->cfg.dst_addr;
addr_width = plchan->cfg.dst_addr_width;
maxburst = plchan->cfg.dst_maxburst;
src_buses = pl08x->mem_buses;
dst_buses = plchan->cd->periph_buses;
} else if (direction == DMA_DEV_TO_MEM) {
cctl = PL080_CONTROL_DST_INCR;
slave_addr = plchan->cfg.src_addr;
addr_width = plchan->cfg.src_addr_width;
maxburst = plchan->cfg.src_maxburst;
src_buses = plchan->cd->periph_buses;
dst_buses = pl08x->mem_buses;
} else {
pl08x_free_txd(pl08x, txd);
dev_err(&pl08x->adev->dev,
"%s direction unsupported\n", __func__);
return NULL;
}
cctl |= pl08x_get_cctl(plchan, addr_width, maxburst);
if (cctl == ~0) {
pl08x_free_txd(pl08x, txd);
dev_err(&pl08x->adev->dev,
"DMA slave configuration botched?\n");
return NULL;
}
txd->cctl = cctl | pl08x_select_bus(src_buses, dst_buses);
if (plchan->cfg.device_fc)
tmp = (direction == DMA_MEM_TO_DEV) ? PL080_FLOW_MEM2PER_PER :
PL080_FLOW_PER2MEM_PER;
else
tmp = (direction == DMA_MEM_TO_DEV) ? PL080_FLOW_MEM2PER :
PL080_FLOW_PER2MEM;
txd->ccfg |= tmp << PL080_CONFIG_FLOW_CONTROL_SHIFT;
ret = pl08x_request_mux(plchan);
if (ret < 0) {
pl08x_free_txd(pl08x, txd);
dev_dbg(&pl08x->adev->dev,
"unable to mux for transfer on %s due to platform restrictions\n",
plchan->name);
return NULL;
}
dev_dbg(&pl08x->adev->dev, "allocated DMA request signal %d for xfer on %s\n",
plchan->signal, plchan->name);
if (direction == DMA_MEM_TO_DEV)
txd->ccfg |= plchan->signal << PL080_CONFIG_DST_SEL_SHIFT;
else
txd->ccfg |= plchan->signal << PL080_CONFIG_SRC_SEL_SHIFT;
for_each_sg(sgl, sg, sg_len, tmp) {
dsg = kzalloc(sizeof(struct pl08x_sg), GFP_NOWAIT);
if (!dsg) {
pl08x_release_mux(plchan);
pl08x_free_txd(pl08x, txd);
dev_err(&pl08x->adev->dev, "%s no mem for pl080 sg\n",
__func__);
return NULL;
}
list_add_tail(&dsg->node, &txd->dsg_list);
dsg->len = sg_dma_len(sg);
if (direction == DMA_MEM_TO_DEV) {
dsg->src_addr = sg_dma_address(sg);
dsg->dst_addr = slave_addr;
} else {
dsg->src_addr = slave_addr;
dsg->dst_addr = sg_dma_address(sg);
}
}
ret = pl08x_fill_llis_for_desc(plchan->host, txd);
if (!ret) {
pl08x_release_mux(plchan);
pl08x_free_txd(pl08x, txd);
return NULL;
}
return vchan_tx_prep(&plchan->vc, &txd->vd, flags);
}
static int pl08x_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
struct pl08x_dma_chan *plchan = to_pl08x_chan(chan);
struct pl08x_driver_data *pl08x = plchan->host;
unsigned long flags;
int ret = 0;
if (cmd == DMA_SLAVE_CONFIG) {
return dma_set_runtime_config(chan,
(struct dma_slave_config *)arg);
}
spin_lock_irqsave(&plchan->vc.lock, flags);
if (!plchan->phychan && !plchan->at) {
spin_unlock_irqrestore(&plchan->vc.lock, flags);
return 0;
}
switch (cmd) {
case DMA_TERMINATE_ALL:
plchan->state = PL08X_CHAN_IDLE;
if (plchan->phychan) {
pl08x_phy_free(plchan);
}
if (plchan->at) {
pl08x_desc_free(&plchan->at->vd);
plchan->at = NULL;
}
pl08x_free_txd_list(pl08x, plchan);
break;
case DMA_PAUSE:
pl08x_pause_phy_chan(plchan->phychan);
plchan->state = PL08X_CHAN_PAUSED;
break;
case DMA_RESUME:
pl08x_resume_phy_chan(plchan->phychan);
plchan->state = PL08X_CHAN_RUNNING;
break;
default:
ret = -ENXIO;
break;
}
spin_unlock_irqrestore(&plchan->vc.lock, flags);
return ret;
}
bool pl08x_filter_id(struct dma_chan *chan, void *chan_id)
{
struct pl08x_dma_chan *plchan;
char *name = chan_id;
if (chan->device->dev->driver != &pl08x_amba_driver.drv)
return false;
plchan = to_pl08x_chan(chan);
if (!strcmp(plchan->name, name))
return true;
return false;
}
static void pl08x_ensure_on(struct pl08x_driver_data *pl08x)
{
if (pl08x->vd->nomadik)
return;
writel(PL080_CONFIG_ENABLE, pl08x->base + PL080_CONFIG);
}
static irqreturn_t pl08x_irq(int irq, void *dev)
{
struct pl08x_driver_data *pl08x = dev;
u32 mask = 0, err, tc, i;
err = readl(pl08x->base + PL080_ERR_STATUS);
if (err) {
dev_err(&pl08x->adev->dev, "%s error interrupt, register value 0x%08x\n",
__func__, err);
writel(err, pl08x->base + PL080_ERR_CLEAR);
}
tc = readl(pl08x->base + PL080_TC_STATUS);
if (tc)
writel(tc, pl08x->base + PL080_TC_CLEAR);
if (!err && !tc)
return IRQ_NONE;
for (i = 0; i < pl08x->vd->channels; i++) {
if (((1 << i) & err) || ((1 << i) & tc)) {
struct pl08x_phy_chan *phychan = &pl08x->phy_chans[i];
struct pl08x_dma_chan *plchan = phychan->serving;
struct pl08x_txd *tx;
if (!plchan) {
dev_err(&pl08x->adev->dev,
"%s Error TC interrupt on unused channel: 0x%08x\n",
__func__, i);
continue;
}
spin_lock(&plchan->vc.lock);
tx = plchan->at;
if (tx) {
plchan->at = NULL;
pl08x_release_mux(plchan);
tx->done = true;
vchan_cookie_complete(&tx->vd);
if (vchan_next_desc(&plchan->vc))
pl08x_start_next_txd(plchan);
else
pl08x_phy_free(plchan);
}
spin_unlock(&plchan->vc.lock);
mask |= (1 << i);
}
}
return mask ? IRQ_HANDLED : IRQ_NONE;
}
static void pl08x_dma_slave_init(struct pl08x_dma_chan *chan)
{
chan->slave = true;
chan->name = chan->cd->bus_id;
chan->cfg.src_addr = chan->cd->addr;
chan->cfg.dst_addr = chan->cd->addr;
}
static int pl08x_dma_init_virtual_channels(struct pl08x_driver_data *pl08x,
struct dma_device *dmadev, unsigned int channels, bool slave)
{
struct pl08x_dma_chan *chan;
int i;
INIT_LIST_HEAD(&dmadev->channels);
for (i = 0; i < channels; i++) {
chan = kzalloc(sizeof(*chan), GFP_KERNEL);
if (!chan) {
dev_err(&pl08x->adev->dev,
"%s no memory for channel\n", __func__);
return -ENOMEM;
}
chan->host = pl08x;
chan->state = PL08X_CHAN_IDLE;
chan->signal = -1;
if (slave) {
chan->cd = &pl08x->pd->slave_channels[i];
pl08x_dma_slave_init(chan);
} else {
chan->cd = &pl08x->pd->memcpy_channel;
chan->name = kasprintf(GFP_KERNEL, "memcpy%d", i);
if (!chan->name) {
kfree(chan);
return -ENOMEM;
}
}
dev_dbg(&pl08x->adev->dev,
"initialize virtual channel \"%s\"\n",
chan->name);
chan->vc.desc_free = pl08x_desc_free;
vchan_init(&chan->vc, dmadev);
}
dev_info(&pl08x->adev->dev, "initialized %d virtual %s channels\n",
i, slave ? "slave" : "memcpy");
return i;
}
static void pl08x_free_virtual_channels(struct dma_device *dmadev)
{
struct pl08x_dma_chan *chan = NULL;
struct pl08x_dma_chan *next;
list_for_each_entry_safe(chan,
next, &dmadev->channels, vc.chan.device_node) {
list_del(&chan->vc.chan.device_node);
kfree(chan);
}
}
static const char *pl08x_state_str(enum pl08x_dma_chan_state state)
{
switch (state) {
case PL08X_CHAN_IDLE:
return "idle";
case PL08X_CHAN_RUNNING:
return "running";
case PL08X_CHAN_PAUSED:
return "paused";
case PL08X_CHAN_WAITING:
return "waiting";
default:
break;
}
return "UNKNOWN STATE";
}
static int pl08x_debugfs_show(struct seq_file *s, void *data)
{
struct pl08x_driver_data *pl08x = s->private;
struct pl08x_dma_chan *chan;
struct pl08x_phy_chan *ch;
unsigned long flags;
int i;
seq_printf(s, "PL08x physical channels:\n");
seq_printf(s, "CHANNEL:\tUSER:\n");
seq_printf(s, "--------\t-----\n");
for (i = 0; i < pl08x->vd->channels; i++) {
struct pl08x_dma_chan *virt_chan;
ch = &pl08x->phy_chans[i];
spin_lock_irqsave(&ch->lock, flags);
virt_chan = ch->serving;
seq_printf(s, "%d\t\t%s%s\n",
ch->id,
virt_chan ? virt_chan->name : "(none)",
ch->locked ? " LOCKED" : "");
spin_unlock_irqrestore(&ch->lock, flags);
}
seq_printf(s, "\nPL08x virtual memcpy channels:\n");
seq_printf(s, "CHANNEL:\tSTATE:\n");
seq_printf(s, "--------\t------\n");
list_for_each_entry(chan, &pl08x->memcpy.channels, vc.chan.device_node) {
seq_printf(s, "%s\t\t%s\n", chan->name,
pl08x_state_str(chan->state));
}
seq_printf(s, "\nPL08x virtual slave channels:\n");
seq_printf(s, "CHANNEL:\tSTATE:\n");
seq_printf(s, "--------\t------\n");
list_for_each_entry(chan, &pl08x->slave.channels, vc.chan.device_node) {
seq_printf(s, "%s\t\t%s\n", chan->name,
pl08x_state_str(chan->state));
}
return 0;
}
static int pl08x_debugfs_open(struct inode *inode, struct file *file)
{
return single_open(file, pl08x_debugfs_show, inode->i_private);
}
static void init_pl08x_debugfs(struct pl08x_driver_data *pl08x)
{
(void) debugfs_create_file(dev_name(&pl08x->adev->dev),
S_IFREG | S_IRUGO, NULL, pl08x,
&pl08x_debugfs_operations);
}
static inline void init_pl08x_debugfs(struct pl08x_driver_data *pl08x)
{
}
static int pl08x_probe(struct amba_device *adev, const struct amba_id *id)
{
struct pl08x_driver_data *pl08x;
const struct vendor_data *vd = id->data;
int ret = 0;
int i;
ret = amba_request_regions(adev, NULL);
if (ret)
return ret;
pl08x = kzalloc(sizeof(*pl08x), GFP_KERNEL);
if (!pl08x) {
ret = -ENOMEM;
goto out_no_pl08x;
}
dma_cap_set(DMA_MEMCPY, pl08x->memcpy.cap_mask);
pl08x->memcpy.dev = &adev->dev;
pl08x->memcpy.device_alloc_chan_resources = pl08x_alloc_chan_resources;
pl08x->memcpy.device_free_chan_resources = pl08x_free_chan_resources;
pl08x->memcpy.device_prep_dma_memcpy = pl08x_prep_dma_memcpy;
pl08x->memcpy.device_prep_dma_interrupt = pl08x_prep_dma_interrupt;
pl08x->memcpy.device_tx_status = pl08x_dma_tx_status;
pl08x->memcpy.device_issue_pending = pl08x_issue_pending;
pl08x->memcpy.device_control = pl08x_control;
dma_cap_set(DMA_SLAVE, pl08x->slave.cap_mask);
pl08x->slave.dev = &adev->dev;
pl08x->slave.device_alloc_chan_resources = pl08x_alloc_chan_resources;
pl08x->slave.device_free_chan_resources = pl08x_free_chan_resources;
pl08x->slave.device_prep_dma_interrupt = pl08x_prep_dma_interrupt;
pl08x->slave.device_tx_status = pl08x_dma_tx_status;
pl08x->slave.device_issue_pending = pl08x_issue_pending;
pl08x->slave.device_prep_slave_sg = pl08x_prep_slave_sg;
pl08x->slave.device_control = pl08x_control;
pl08x->pd = dev_get_platdata(&adev->dev);
if (!pl08x->pd) {
dev_err(&adev->dev, "no platform data supplied\n");
ret = -EINVAL;
goto out_no_platdata;
}
pl08x->adev = adev;
pl08x->vd = vd;
pl08x->lli_buses = PL08X_AHB1;
pl08x->mem_buses = PL08X_AHB1;
if (pl08x->vd->dualmaster) {
pl08x->lli_buses = pl08x->pd->lli_buses;
pl08x->mem_buses = pl08x->pd->mem_buses;
}
pl08x->pool = dma_pool_create(DRIVER_NAME, &pl08x->adev->dev,
PL08X_LLI_TSFR_SIZE, PL08X_ALIGN, 0);
if (!pl08x->pool) {
ret = -ENOMEM;
goto out_no_lli_pool;
}
pl08x->base = ioremap(adev->res.start, resource_size(&adev->res));
if (!pl08x->base) {
ret = -ENOMEM;
goto out_no_ioremap;
}
pl08x_ensure_on(pl08x);
writel(0x000000FF, pl08x->base + PL080_ERR_CLEAR);
writel(0x000000FF, pl08x->base + PL080_TC_CLEAR);
ret = request_irq(adev->irq[0], pl08x_irq, IRQF_DISABLED,
DRIVER_NAME, pl08x);
if (ret) {
dev_err(&adev->dev, "%s failed to request interrupt %d\n",
__func__, adev->irq[0]);
goto out_no_irq;
}
pl08x->phy_chans = kzalloc((vd->channels * sizeof(*pl08x->phy_chans)),
GFP_KERNEL);
if (!pl08x->phy_chans) {
dev_err(&adev->dev, "%s failed to allocate "
"physical channel holders\n",
__func__);
ret = -ENOMEM;
goto out_no_phychans;
}
for (i = 0; i < vd->channels; i++) {
struct pl08x_phy_chan *ch = &pl08x->phy_chans[i];
ch->id = i;
ch->base = pl08x->base + PL080_Cx_BASE(i);
spin_lock_init(&ch->lock);
if (vd->nomadik) {
u32 val;
val = readl(ch->base + PL080_CH_CONFIG);
if (val & (PL080N_CONFIG_ITPROT | PL080N_CONFIG_SECPROT)) {
dev_info(&adev->dev, "physical channel %d reserved for secure access only\n", i);
ch->locked = true;
}
}
dev_dbg(&adev->dev, "physical channel %d is %s\n",
i, pl08x_phy_channel_busy(ch) ? "BUSY" : "FREE");
}
ret = pl08x_dma_init_virtual_channels(pl08x, &pl08x->memcpy,
pl08x->vd->channels, false);
if (ret <= 0) {
dev_warn(&pl08x->adev->dev,
"%s failed to enumerate memcpy channels - %d\n",
__func__, ret);
goto out_no_memcpy;
}
pl08x->memcpy.chancnt = ret;
ret = pl08x_dma_init_virtual_channels(pl08x, &pl08x->slave,
pl08x->pd->num_slave_channels, true);
if (ret <= 0) {
dev_warn(&pl08x->adev->dev,
"%s failed to enumerate slave channels - %d\n",
__func__, ret);
goto out_no_slave;
}
pl08x->slave.chancnt = ret;
ret = dma_async_device_register(&pl08x->memcpy);
if (ret) {
dev_warn(&pl08x->adev->dev,
"%s failed to register memcpy as an async device - %d\n",
__func__, ret);
goto out_no_memcpy_reg;
}
ret = dma_async_device_register(&pl08x->slave);
if (ret) {
dev_warn(&pl08x->adev->dev,
"%s failed to register slave as an async device - %d\n",
__func__, ret);
goto out_no_slave_reg;
}
amba_set_drvdata(adev, pl08x);
init_pl08x_debugfs(pl08x);
dev_info(&pl08x->adev->dev, "DMA: PL%03x rev%u at 0x%08llx irq %d\n",
amba_part(adev), amba_rev(adev),
(unsigned long long)adev->res.start, adev->irq[0]);
return 0;
out_no_slave_reg:
dma_async_device_unregister(&pl08x->memcpy);
out_no_memcpy_reg:
pl08x_free_virtual_channels(&pl08x->slave);
out_no_slave:
pl08x_free_virtual_channels(&pl08x->memcpy);
out_no_memcpy:
kfree(pl08x->phy_chans);
out_no_phychans:
free_irq(adev->irq[0], pl08x);
out_no_irq:
iounmap(pl08x->base);
out_no_ioremap:
dma_pool_destroy(pl08x->pool);
out_no_lli_pool:
out_no_platdata:
kfree(pl08x);
out_no_pl08x:
amba_release_regions(adev);
return ret;
}
static int __init pl08x_init(void)
{
int retval;
retval = amba_driver_register(&pl08x_amba_driver);
if (retval)
printk(KERN_WARNING DRIVER_NAME
"failed to register as an AMBA device (%d)\n",
retval);
return retval;
}
