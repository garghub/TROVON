static inline struct pl08x_dma_chan *to_pl08x_chan(struct dma_chan *chan)
{
return container_of(chan, struct pl08x_dma_chan, chan);
}
static inline struct pl08x_txd *to_pl08x_txd(struct dma_async_tx_descriptor *tx)
{
return container_of(tx, struct pl08x_txd, tx);
}
static int pl08x_phy_channel_busy(struct pl08x_phy_chan *ch)
{
unsigned int val;
val = readl(ch->base + PL080_CH_CONFIG);
return val & PL080_CONFIG_ACTIVE;
}
static void pl08x_start_txd(struct pl08x_dma_chan *plchan,
struct pl08x_txd *txd)
{
struct pl08x_driver_data *pl08x = plchan->host;
struct pl08x_phy_chan *phychan = plchan->phychan;
struct pl08x_lli *lli = &txd->llis_va[0];
u32 val;
plchan->at = txd;
while (pl08x_phy_channel_busy(phychan))
cpu_relax();
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
unsigned long flags;
size_t bytes = 0;
spin_lock_irqsave(&plchan->lock, flags);
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
if (!list_empty(&plchan->pend_list)) {
struct pl08x_txd *txdi;
list_for_each_entry(txdi, &plchan->pend_list, node) {
struct pl08x_sg *dsg;
list_for_each_entry(dsg, &txd->dsg_list, node)
bytes += dsg->len;
}
}
spin_unlock_irqrestore(&plchan->lock, flags);
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
if (!ch->serving) {
ch->serving = virt_chan;
ch->signal = -1;
spin_unlock_irqrestore(&ch->lock, flags);
break;
}
spin_unlock_irqrestore(&ch->lock, flags);
}
if (i == pl08x->vd->channels) {
return NULL;
}
pm_runtime_get_sync(&pl08x->adev->dev);
return ch;
}
static inline void pl08x_put_phy_channel(struct pl08x_driver_data *pl08x,
struct pl08x_phy_chan *ch)
{
unsigned long flags;
spin_lock_irqsave(&ch->lock, flags);
pl08x_terminate_phy_chan(pl08x, ch);
pm_runtime_put(&pl08x->adev->dev);
ch->serving = NULL;
spin_unlock_irqrestore(&ch->lock, flags);
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
pl08x->pool_ctr++;
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
pl08x->pool_ctr--;
list_for_each_entry_safe(dsg, _dsg, &txd->dsg_list, node) {
list_del(&dsg->node);
kfree(dsg);
}
kfree(txd);
}
static void pl08x_free_txd_list(struct pl08x_driver_data *pl08x,
struct pl08x_dma_chan *plchan)
{
struct pl08x_txd *txdi = NULL;
struct pl08x_txd *next;
if (!list_empty(&plchan->pend_list)) {
list_for_each_entry_safe(txdi,
next, &plchan->pend_list, node) {
list_del(&txdi->node);
pl08x_free_txd(pl08x, txdi);
}
}
}
static int pl08x_alloc_chan_resources(struct dma_chan *chan)
{
return 0;
}
static void pl08x_free_chan_resources(struct dma_chan *chan)
{
}
static int prep_phy_channel(struct pl08x_dma_chan *plchan,
struct pl08x_txd *txd)
{
struct pl08x_driver_data *pl08x = plchan->host;
struct pl08x_phy_chan *ch;
int ret;
if (plchan->phychan) {
ch = plchan->phychan;
goto got_channel;
}
ch = pl08x_get_phy_channel(pl08x, plchan);
if (!ch) {
dev_dbg(&pl08x->adev->dev, "no physical channel available for xfer on %s\n", plchan->name);
return -EBUSY;
}
if (plchan->slave && pl08x->pd->get_signal) {
ret = pl08x->pd->get_signal(plchan);
if (ret < 0) {
dev_dbg(&pl08x->adev->dev,
"unable to use physical channel %d for transfer on %s due to platform restrictions\n",
ch->id, plchan->name);
pl08x_put_phy_channel(pl08x, ch);
return -EBUSY;
}
ch->signal = ret;
}
plchan->phychan = ch;
dev_dbg(&pl08x->adev->dev, "allocated physical channel %d and signal %d for xfer on %s\n",
ch->id,
ch->signal,
plchan->name);
got_channel:
if (txd->direction == DMA_MEM_TO_DEV)
txd->ccfg |= ch->signal << PL080_CONFIG_DST_SEL_SHIFT;
else if (txd->direction == DMA_DEV_TO_MEM)
txd->ccfg |= ch->signal << PL080_CONFIG_SRC_SEL_SHIFT;
plchan->phychan_hold++;
return 0;
}
static void release_phy_channel(struct pl08x_dma_chan *plchan)
{
struct pl08x_driver_data *pl08x = plchan->host;
if ((plchan->phychan->signal >= 0) && pl08x->pd->put_signal) {
pl08x->pd->put_signal(plchan);
plchan->phychan->signal = -1;
}
pl08x_put_phy_channel(pl08x, plchan->phychan);
plchan->phychan = NULL;
}
static dma_cookie_t pl08x_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct pl08x_dma_chan *plchan = to_pl08x_chan(tx->chan);
struct pl08x_txd *txd = to_pl08x_txd(tx);
unsigned long flags;
dma_cookie_t cookie;
spin_lock_irqsave(&plchan->lock, flags);
cookie = dma_cookie_assign(tx);
list_add_tail(&txd->node, &plchan->pend_list);
if (!plchan->slave && !plchan->phychan) {
plchan->state = PL08X_CHAN_WAITING;
plchan->waiting = txd;
} else {
plchan->phychan_hold--;
}
spin_unlock_irqrestore(&plchan->lock, flags);
return cookie;
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
enum dma_status ret;
ret = dma_cookie_status(chan, cookie, txstate);
if (ret == DMA_SUCCESS)
return ret;
dma_set_residue(txstate, pl08x_getbytes_chan(plchan));
if (plchan->state == PL08X_CHAN_PAUSED)
return DMA_PAUSED;
return DMA_IN_PROGRESS;
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
static int dma_set_runtime_config(struct dma_chan *chan,
struct dma_slave_config *config)
{
struct pl08x_dma_chan *plchan = to_pl08x_chan(chan);
struct pl08x_driver_data *pl08x = plchan->host;
enum dma_slave_buswidth addr_width;
u32 width, burst, maxburst;
u32 cctl = 0;
if (!plchan->slave)
return -EINVAL;
plchan->runtime_direction = config->direction;
if (config->direction == DMA_MEM_TO_DEV) {
addr_width = config->dst_addr_width;
maxburst = config->dst_maxburst;
} else if (config->direction == DMA_DEV_TO_MEM) {
addr_width = config->src_addr_width;
maxburst = config->src_maxburst;
} else {
dev_err(&pl08x->adev->dev,
"bad runtime_config: alien transfer direction\n");
return -EINVAL;
}
width = pl08x_width(addr_width);
if (width == ~0) {
dev_err(&pl08x->adev->dev,
"bad runtime_config: alien address width\n");
return -EINVAL;
}
cctl |= width << PL080_CONTROL_SWIDTH_SHIFT;
cctl |= width << PL080_CONTROL_DWIDTH_SHIFT;
if (plchan->cd->single)
maxburst = 1;
burst = pl08x_burst(maxburst);
cctl |= burst << PL080_CONTROL_SB_SIZE_SHIFT;
cctl |= burst << PL080_CONTROL_DB_SIZE_SHIFT;
plchan->device_fc = config->device_fc;
if (plchan->runtime_direction == DMA_DEV_TO_MEM) {
plchan->src_addr = config->src_addr;
plchan->src_cctl = pl08x_cctl(cctl) | PL080_CONTROL_DST_INCR |
pl08x_select_bus(plchan->cd->periph_buses,
pl08x->mem_buses);
} else {
plchan->dst_addr = config->dst_addr;
plchan->dst_cctl = pl08x_cctl(cctl) | PL080_CONTROL_SRC_INCR |
pl08x_select_bus(pl08x->mem_buses,
plchan->cd->periph_buses);
}
dev_dbg(&pl08x->adev->dev,
"configured channel %s (%s) for %s, data width %d, "
"maxburst %d words, LE, CCTL=0x%08x\n",
dma_chan_name(chan), plchan->name,
(config->direction == DMA_DEV_TO_MEM) ? "RX" : "TX",
addr_width,
maxburst,
cctl);
return 0;
}
static void pl08x_issue_pending(struct dma_chan *chan)
{
struct pl08x_dma_chan *plchan = to_pl08x_chan(chan);
unsigned long flags;
spin_lock_irqsave(&plchan->lock, flags);
if (plchan->at || plchan->state == PL08X_CHAN_WAITING) {
spin_unlock_irqrestore(&plchan->lock, flags);
return;
}
if (!list_empty(&plchan->pend_list)) {
struct pl08x_txd *next;
next = list_first_entry(&plchan->pend_list,
struct pl08x_txd,
node);
list_del(&next->node);
plchan->state = PL08X_CHAN_RUNNING;
pl08x_start_txd(plchan, next);
}
spin_unlock_irqrestore(&plchan->lock, flags);
}
static int pl08x_prep_channel_resources(struct pl08x_dma_chan *plchan,
struct pl08x_txd *txd)
{
struct pl08x_driver_data *pl08x = plchan->host;
unsigned long flags;
int num_llis, ret;
num_llis = pl08x_fill_llis_for_desc(pl08x, txd);
if (!num_llis) {
spin_lock_irqsave(&plchan->lock, flags);
pl08x_free_txd(pl08x, txd);
spin_unlock_irqrestore(&plchan->lock, flags);
return -EINVAL;
}
spin_lock_irqsave(&plchan->lock, flags);
ret = prep_phy_channel(plchan, txd);
if (ret) {
if (plchan->slave) {
pl08x_free_txd_list(pl08x, plchan);
pl08x_free_txd(pl08x, txd);
spin_unlock_irqrestore(&plchan->lock, flags);
return -EBUSY;
}
} else
if (plchan->state == PL08X_CHAN_IDLE)
plchan->state = PL08X_CHAN_PAUSED;
spin_unlock_irqrestore(&plchan->lock, flags);
return 0;
}
static struct pl08x_txd *pl08x_get_txd(struct pl08x_dma_chan *plchan,
unsigned long flags)
{
struct pl08x_txd *txd = kzalloc(sizeof(*txd), GFP_NOWAIT);
if (txd) {
dma_async_tx_descriptor_init(&txd->tx, &plchan->chan);
txd->tx.flags = flags;
txd->tx.tx_submit = pl08x_tx_submit;
INIT_LIST_HEAD(&txd->node);
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
txd = pl08x_get_txd(plchan, flags);
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
txd->direction = DMA_NONE;
dsg->src_addr = src;
dsg->dst_addr = dest;
dsg->len = len;
txd->ccfg |= PL080_FLOW_MEM2MEM << PL080_CONFIG_FLOW_CONTROL_SHIFT;
txd->cctl = pl08x->pd->memcpy_channel.cctl &
~(PL080_CONTROL_DST_AHB2 | PL080_CONTROL_SRC_AHB2);
txd->cctl |= PL080_CONTROL_SRC_INCR | PL080_CONTROL_DST_INCR;
if (pl08x->vd->dualmaster)
txd->cctl |= pl08x_select_bus(pl08x->mem_buses,
pl08x->mem_buses);
ret = pl08x_prep_channel_resources(plchan, txd);
if (ret)
return NULL;
return &txd->tx;
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
dma_addr_t slave_addr;
int ret, tmp;
dev_dbg(&pl08x->adev->dev, "%s prepare transaction of %d bytes from %s\n",
__func__, sgl->length, plchan->name);
txd = pl08x_get_txd(plchan, flags);
if (!txd) {
dev_err(&pl08x->adev->dev, "%s no txd\n", __func__);
return NULL;
}
if (direction != plchan->runtime_direction)
dev_err(&pl08x->adev->dev, "%s DMA setup does not match "
"the direction configured for the PrimeCell\n",
__func__);
txd->direction = direction;
if (direction == DMA_MEM_TO_DEV) {
txd->cctl = plchan->dst_cctl;
slave_addr = plchan->dst_addr;
} else if (direction == DMA_DEV_TO_MEM) {
txd->cctl = plchan->src_cctl;
slave_addr = plchan->src_addr;
} else {
pl08x_free_txd(pl08x, txd);
dev_err(&pl08x->adev->dev,
"%s direction unsupported\n", __func__);
return NULL;
}
if (plchan->device_fc)
tmp = (direction == DMA_MEM_TO_DEV) ? PL080_FLOW_MEM2PER_PER :
PL080_FLOW_PER2MEM_PER;
else
tmp = (direction == DMA_MEM_TO_DEV) ? PL080_FLOW_MEM2PER :
PL080_FLOW_PER2MEM;
txd->ccfg |= tmp << PL080_CONFIG_FLOW_CONTROL_SHIFT;
for_each_sg(sgl, sg, sg_len, tmp) {
dsg = kzalloc(sizeof(struct pl08x_sg), GFP_NOWAIT);
if (!dsg) {
pl08x_free_txd(pl08x, txd);
dev_err(&pl08x->adev->dev, "%s no mem for pl080 sg\n",
__func__);
return NULL;
}
list_add_tail(&dsg->node, &txd->dsg_list);
dsg->len = sg_dma_len(sg);
if (direction == DMA_MEM_TO_DEV) {
dsg->src_addr = sg_phys(sg);
dsg->dst_addr = slave_addr;
} else {
dsg->src_addr = slave_addr;
dsg->dst_addr = sg_phys(sg);
}
}
ret = pl08x_prep_channel_resources(plchan, txd);
if (ret)
return NULL;
return &txd->tx;
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
spin_lock_irqsave(&plchan->lock, flags);
if (!plchan->phychan && !plchan->at) {
spin_unlock_irqrestore(&plchan->lock, flags);
return 0;
}
switch (cmd) {
case DMA_TERMINATE_ALL:
plchan->state = PL08X_CHAN_IDLE;
if (plchan->phychan) {
pl08x_terminate_phy_chan(pl08x, plchan->phychan);
release_phy_channel(plchan);
plchan->phychan_hold = 0;
}
if (plchan->at) {
pl08x_free_txd(pl08x, plchan->at);
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
spin_unlock_irqrestore(&plchan->lock, flags);
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
writel(PL080_CONFIG_ENABLE, pl08x->base + PL080_CONFIG);
}
static void pl08x_unmap_buffers(struct pl08x_txd *txd)
{
struct device *dev = txd->tx.chan->device->dev;
struct pl08x_sg *dsg;
if (!(txd->tx.flags & DMA_COMPL_SKIP_SRC_UNMAP)) {
if (txd->tx.flags & DMA_COMPL_SRC_UNMAP_SINGLE)
list_for_each_entry(dsg, &txd->dsg_list, node)
dma_unmap_single(dev, dsg->src_addr, dsg->len,
DMA_TO_DEVICE);
else {
list_for_each_entry(dsg, &txd->dsg_list, node)
dma_unmap_page(dev, dsg->src_addr, dsg->len,
DMA_TO_DEVICE);
}
}
if (!(txd->tx.flags & DMA_COMPL_SKIP_DEST_UNMAP)) {
if (txd->tx.flags & DMA_COMPL_DEST_UNMAP_SINGLE)
list_for_each_entry(dsg, &txd->dsg_list, node)
dma_unmap_single(dev, dsg->dst_addr, dsg->len,
DMA_FROM_DEVICE);
else
list_for_each_entry(dsg, &txd->dsg_list, node)
dma_unmap_page(dev, dsg->dst_addr, dsg->len,
DMA_FROM_DEVICE);
}
}
static void pl08x_tasklet(unsigned long data)
{
struct pl08x_dma_chan *plchan = (struct pl08x_dma_chan *) data;
struct pl08x_driver_data *pl08x = plchan->host;
struct pl08x_txd *txd;
unsigned long flags;
spin_lock_irqsave(&plchan->lock, flags);
txd = plchan->at;
plchan->at = NULL;
if (txd) {
dma_cookie_complete(&txd->tx);
}
if (!list_empty(&plchan->pend_list)) {
struct pl08x_txd *next;
next = list_first_entry(&plchan->pend_list,
struct pl08x_txd,
node);
list_del(&next->node);
pl08x_start_txd(plchan, next);
} else if (plchan->phychan_hold) {
} else {
struct pl08x_dma_chan *waiting = NULL;
release_phy_channel(plchan);
plchan->state = PL08X_CHAN_IDLE;
list_for_each_entry(waiting, &pl08x->memcpy.channels,
chan.device_node) {
if (waiting->state == PL08X_CHAN_WAITING &&
waiting->waiting != NULL) {
int ret;
ret = prep_phy_channel(waiting,
waiting->waiting);
BUG_ON(ret);
waiting->phychan_hold--;
waiting->state = PL08X_CHAN_RUNNING;
waiting->waiting = NULL;
pl08x_issue_pending(&waiting->chan);
break;
}
}
}
spin_unlock_irqrestore(&plchan->lock, flags);
if (txd) {
dma_async_tx_callback callback = txd->tx.callback;
void *callback_param = txd->tx.callback_param;
if (!plchan->slave)
pl08x_unmap_buffers(txd);
spin_lock_irqsave(&plchan->lock, flags);
pl08x_free_txd(pl08x, txd);
spin_unlock_irqrestore(&plchan->lock, flags);
if (callback)
callback(callback_param);
}
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
tc = readl(pl08x->base + PL080_INT_STATUS);
if (tc)
writel(tc, pl08x->base + PL080_TC_CLEAR);
if (!err && !tc)
return IRQ_NONE;
for (i = 0; i < pl08x->vd->channels; i++) {
if (((1 << i) & err) || ((1 << i) & tc)) {
struct pl08x_phy_chan *phychan = &pl08x->phy_chans[i];
struct pl08x_dma_chan *plchan = phychan->serving;
if (!plchan) {
dev_err(&pl08x->adev->dev,
"%s Error TC interrupt on unused channel: 0x%08x\n",
__func__, i);
continue;
}
tasklet_schedule(&plchan->tasklet);
mask |= (1 << i);
}
}
return mask ? IRQ_HANDLED : IRQ_NONE;
}
static void pl08x_dma_slave_init(struct pl08x_dma_chan *chan)
{
u32 cctl = pl08x_cctl(chan->cd->cctl);
chan->slave = true;
chan->name = chan->cd->bus_id;
chan->src_addr = chan->cd->addr;
chan->dst_addr = chan->cd->addr;
chan->src_cctl = cctl | PL080_CONTROL_DST_INCR |
pl08x_select_bus(chan->cd->periph_buses, chan->host->mem_buses);
chan->dst_cctl = cctl | PL080_CONTROL_SRC_INCR |
pl08x_select_bus(chan->host->mem_buses, chan->cd->periph_buses);
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
if (chan->cd->circular_buffer) {
dev_err(&pl08x->adev->dev,
"channel %s: circular buffers not supported\n",
chan->name);
kfree(chan);
continue;
}
dev_dbg(&pl08x->adev->dev,
"initialize virtual channel \"%s\"\n",
chan->name);
chan->chan.device = dmadev;
dma_cookie_init(&chan->chan);
spin_lock_init(&chan->lock);
INIT_LIST_HEAD(&chan->pend_list);
tasklet_init(&chan->tasklet, pl08x_tasklet,
(unsigned long) chan);
list_add_tail(&chan->chan.device_node, &dmadev->channels);
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
next, &dmadev->channels, chan.device_node) {
list_del(&chan->chan.device_node);
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
seq_printf(s, "%d\t\t%s\n",
ch->id, virt_chan ? virt_chan->name : "(none)");
spin_unlock_irqrestore(&ch->lock, flags);
}
seq_printf(s, "\nPL08x virtual memcpy channels:\n");
seq_printf(s, "CHANNEL:\tSTATE:\n");
seq_printf(s, "--------\t------\n");
list_for_each_entry(chan, &pl08x->memcpy.channels, chan.device_node) {
seq_printf(s, "%s\t\t%s\n", chan->name,
pl08x_state_str(chan->state));
}
seq_printf(s, "\nPL08x virtual slave channels:\n");
seq_printf(s, "CHANNEL:\tSTATE:\n");
seq_printf(s, "--------\t------\n");
list_for_each_entry(chan, &pl08x->slave.channels, chan.device_node) {
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
pm_runtime_set_active(&adev->dev);
pm_runtime_enable(&adev->dev);
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
spin_lock_init(&pl08x->lock);
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
pl08x->phy_chans = kmalloc((vd->channels * sizeof(*pl08x->phy_chans)),
GFP_KERNEL);
if (!pl08x->phy_chans) {
dev_err(&adev->dev, "%s failed to allocate "
"physical channel holders\n",
__func__);
goto out_no_phychans;
}
for (i = 0; i < vd->channels; i++) {
struct pl08x_phy_chan *ch = &pl08x->phy_chans[i];
ch->id = i;
ch->base = pl08x->base + PL080_Cx_BASE(i);
spin_lock_init(&ch->lock);
ch->serving = NULL;
ch->signal = -1;
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
pm_runtime_put(&adev->dev);
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
pm_runtime_put(&adev->dev);
pm_runtime_disable(&adev->dev);
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
