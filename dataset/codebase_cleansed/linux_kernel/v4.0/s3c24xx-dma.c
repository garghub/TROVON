static int s3c24xx_dma_phy_busy(struct s3c24xx_dma_phy *phy)
{
unsigned int val = readl(phy->base + S3C24XX_DSTAT);
return val & S3C24XX_DSTAT_STAT_BUSY;
}
static bool s3c24xx_dma_phy_valid(struct s3c24xx_dma_chan *s3cchan,
struct s3c24xx_dma_phy *phy)
{
struct s3c24xx_dma_engine *s3cdma = s3cchan->host;
const struct s3c24xx_dma_platdata *pdata = s3cdma->pdata;
struct s3c24xx_dma_channel *cdata = &pdata->channels[s3cchan->id];
int phyvalid;
if (!s3cchan->slave)
return true;
if (s3cdma->sdata->has_reqsel)
return true;
phyvalid = (cdata->chansel >> (phy->id * S3C24XX_CHANSEL_WIDTH));
return (phyvalid & S3C24XX_CHANSEL_VALID) ? true : false;
}
static
struct s3c24xx_dma_phy *s3c24xx_dma_get_phy(struct s3c24xx_dma_chan *s3cchan)
{
struct s3c24xx_dma_engine *s3cdma = s3cchan->host;
const struct s3c24xx_dma_platdata *pdata = s3cdma->pdata;
struct s3c24xx_dma_channel *cdata;
struct s3c24xx_dma_phy *phy = NULL;
unsigned long flags;
int i;
int ret;
if (s3cchan->slave)
cdata = &pdata->channels[s3cchan->id];
for (i = 0; i < s3cdma->pdata->num_phy_channels; i++) {
phy = &s3cdma->phy_chans[i];
if (!phy->valid)
continue;
if (!s3c24xx_dma_phy_valid(s3cchan, phy))
continue;
spin_lock_irqsave(&phy->lock, flags);
if (!phy->serving) {
phy->serving = s3cchan;
spin_unlock_irqrestore(&phy->lock, flags);
break;
}
spin_unlock_irqrestore(&phy->lock, flags);
}
if (i == s3cdma->pdata->num_phy_channels) {
dev_warn(&s3cdma->pdev->dev, "no phy channel available\n");
return NULL;
}
if (s3cdma->sdata->has_clocks) {
ret = clk_enable(phy->clk);
if (ret) {
dev_err(&s3cdma->pdev->dev, "could not enable clock for channel %d, err %d\n",
phy->id, ret);
phy->serving = NULL;
return NULL;
}
}
return phy;
}
static inline void s3c24xx_dma_put_phy(struct s3c24xx_dma_phy *phy)
{
struct s3c24xx_dma_engine *s3cdma = phy->host;
if (s3cdma->sdata->has_clocks)
clk_disable(phy->clk);
phy->serving = NULL;
}
static void s3c24xx_dma_terminate_phy(struct s3c24xx_dma_phy *phy)
{
writel(S3C24XX_DMASKTRIG_STOP, phy->base + S3C24XX_DMASKTRIG);
}
static inline
struct s3c24xx_dma_chan *to_s3c24xx_dma_chan(struct dma_chan *chan)
{
return container_of(chan, struct s3c24xx_dma_chan, vc.chan);
}
static u32 s3c24xx_dma_getbytes_chan(struct s3c24xx_dma_chan *s3cchan)
{
struct s3c24xx_dma_phy *phy = s3cchan->phy;
struct s3c24xx_txd *txd = s3cchan->at;
u32 tc = readl(phy->base + S3C24XX_DSTAT) & S3C24XX_DSTAT_CURRTC_MASK;
return tc * txd->width;
}
static int s3c24xx_dma_set_runtime_config(struct dma_chan *chan,
struct dma_slave_config *config)
{
struct s3c24xx_dma_chan *s3cchan = to_s3c24xx_dma_chan(chan);
unsigned long flags;
int ret = 0;
if (config->src_addr_width == DMA_SLAVE_BUSWIDTH_8_BYTES ||
config->dst_addr_width == DMA_SLAVE_BUSWIDTH_8_BYTES)
return -EINVAL;
spin_lock_irqsave(&s3cchan->vc.lock, flags);
if (!s3cchan->slave) {
ret = -EINVAL;
goto out;
}
s3cchan->cfg = *config;
out:
spin_unlock_irqrestore(&s3cchan->vc.lock, flags);
return ret;
}
static inline
struct s3c24xx_txd *to_s3c24xx_txd(struct dma_async_tx_descriptor *tx)
{
return container_of(tx, struct s3c24xx_txd, vd.tx);
}
static struct s3c24xx_txd *s3c24xx_dma_get_txd(void)
{
struct s3c24xx_txd *txd = kzalloc(sizeof(*txd), GFP_NOWAIT);
if (txd) {
INIT_LIST_HEAD(&txd->dsg_list);
txd->dcon = S3C24XX_DCON_INT | S3C24XX_DCON_NORELOAD;
}
return txd;
}
static void s3c24xx_dma_free_txd(struct s3c24xx_txd *txd)
{
struct s3c24xx_sg *dsg, *_dsg;
list_for_each_entry_safe(dsg, _dsg, &txd->dsg_list, node) {
list_del(&dsg->node);
kfree(dsg);
}
kfree(txd);
}
static void s3c24xx_dma_start_next_sg(struct s3c24xx_dma_chan *s3cchan,
struct s3c24xx_txd *txd)
{
struct s3c24xx_dma_engine *s3cdma = s3cchan->host;
struct s3c24xx_dma_phy *phy = s3cchan->phy;
const struct s3c24xx_dma_platdata *pdata = s3cdma->pdata;
struct s3c24xx_sg *dsg = list_entry(txd->at, struct s3c24xx_sg, node);
u32 dcon = txd->dcon;
u32 val;
switch (txd->width) {
case 1:
dcon |= S3C24XX_DCON_DSZ_BYTE | dsg->len;
break;
case 2:
dcon |= S3C24XX_DCON_DSZ_HALFWORD | (dsg->len / 2);
break;
case 4:
dcon |= S3C24XX_DCON_DSZ_WORD | (dsg->len / 4);
break;
}
if (s3cchan->slave) {
struct s3c24xx_dma_channel *cdata =
&pdata->channels[s3cchan->id];
if (s3cdma->sdata->has_reqsel) {
writel_relaxed((cdata->chansel << 1) |
S3C24XX_DMAREQSEL_HW,
phy->base + S3C24XX_DMAREQSEL);
} else {
int csel = cdata->chansel >> (phy->id *
S3C24XX_CHANSEL_WIDTH);
csel &= S3C24XX_CHANSEL_REQ_MASK;
dcon |= csel << S3C24XX_DCON_HWSRC_SHIFT;
dcon |= S3C24XX_DCON_HWTRIG;
}
} else {
if (s3cdma->sdata->has_reqsel)
writel_relaxed(0, phy->base + S3C24XX_DMAREQSEL);
}
writel_relaxed(dsg->src_addr, phy->base + S3C24XX_DISRC);
writel_relaxed(txd->disrcc, phy->base + S3C24XX_DISRCC);
writel_relaxed(dsg->dst_addr, phy->base + S3C24XX_DIDST);
writel_relaxed(txd->didstc, phy->base + S3C24XX_DIDSTC);
writel_relaxed(dcon, phy->base + S3C24XX_DCON);
val = readl_relaxed(phy->base + S3C24XX_DMASKTRIG);
val &= ~S3C24XX_DMASKTRIG_STOP;
val |= S3C24XX_DMASKTRIG_ON;
if (!s3cchan->slave)
val |= S3C24XX_DMASKTRIG_SWTRIG;
writel(val, phy->base + S3C24XX_DMASKTRIG);
}
static void s3c24xx_dma_start_next_txd(struct s3c24xx_dma_chan *s3cchan)
{
struct s3c24xx_dma_phy *phy = s3cchan->phy;
struct virt_dma_desc *vd = vchan_next_desc(&s3cchan->vc);
struct s3c24xx_txd *txd = to_s3c24xx_txd(&vd->tx);
list_del(&txd->vd.node);
s3cchan->at = txd;
while (s3c24xx_dma_phy_busy(phy))
cpu_relax();
txd->at = txd->dsg_list.next;
s3c24xx_dma_start_next_sg(s3cchan, txd);
}
static void s3c24xx_dma_free_txd_list(struct s3c24xx_dma_engine *s3cdma,
struct s3c24xx_dma_chan *s3cchan)
{
LIST_HEAD(head);
vchan_get_all_descriptors(&s3cchan->vc, &head);
vchan_dma_desc_free_list(&s3cchan->vc, &head);
}
static void s3c24xx_dma_phy_alloc_and_start(struct s3c24xx_dma_chan *s3cchan)
{
struct s3c24xx_dma_engine *s3cdma = s3cchan->host;
struct s3c24xx_dma_phy *phy;
phy = s3c24xx_dma_get_phy(s3cchan);
if (!phy) {
dev_dbg(&s3cdma->pdev->dev, "no physical channel available for xfer on %s\n",
s3cchan->name);
s3cchan->state = S3C24XX_DMA_CHAN_WAITING;
return;
}
dev_dbg(&s3cdma->pdev->dev, "allocated physical channel %d for xfer on %s\n",
phy->id, s3cchan->name);
s3cchan->phy = phy;
s3cchan->state = S3C24XX_DMA_CHAN_RUNNING;
s3c24xx_dma_start_next_txd(s3cchan);
}
static void s3c24xx_dma_phy_reassign_start(struct s3c24xx_dma_phy *phy,
struct s3c24xx_dma_chan *s3cchan)
{
struct s3c24xx_dma_engine *s3cdma = s3cchan->host;
dev_dbg(&s3cdma->pdev->dev, "reassigned physical channel %d for xfer on %s\n",
phy->id, s3cchan->name);
phy->serving = s3cchan;
s3cchan->phy = phy;
s3cchan->state = S3C24XX_DMA_CHAN_RUNNING;
s3c24xx_dma_start_next_txd(s3cchan);
}
static void s3c24xx_dma_phy_free(struct s3c24xx_dma_chan *s3cchan)
{
struct s3c24xx_dma_engine *s3cdma = s3cchan->host;
struct s3c24xx_dma_chan *p, *next;
retry:
next = NULL;
list_for_each_entry(p, &s3cdma->memcpy.channels, vc.chan.device_node)
if (p->state == S3C24XX_DMA_CHAN_WAITING) {
next = p;
break;
}
if (!next) {
list_for_each_entry(p, &s3cdma->slave.channels,
vc.chan.device_node)
if (p->state == S3C24XX_DMA_CHAN_WAITING &&
s3c24xx_dma_phy_valid(p, s3cchan->phy)) {
next = p;
break;
}
}
s3c24xx_dma_terminate_phy(s3cchan->phy);
if (next) {
bool success;
spin_lock(&next->vc.lock);
success = next->state == S3C24XX_DMA_CHAN_WAITING;
if (success)
s3c24xx_dma_phy_reassign_start(s3cchan->phy, next);
spin_unlock(&next->vc.lock);
if (!success)
goto retry;
} else {
s3c24xx_dma_put_phy(s3cchan->phy);
}
s3cchan->phy = NULL;
s3cchan->state = S3C24XX_DMA_CHAN_IDLE;
}
static void s3c24xx_dma_desc_free(struct virt_dma_desc *vd)
{
struct s3c24xx_txd *txd = to_s3c24xx_txd(&vd->tx);
struct s3c24xx_dma_chan *s3cchan = to_s3c24xx_dma_chan(vd->tx.chan);
if (!s3cchan->slave)
dma_descriptor_unmap(&vd->tx);
s3c24xx_dma_free_txd(txd);
}
static irqreturn_t s3c24xx_dma_irq(int irq, void *data)
{
struct s3c24xx_dma_phy *phy = data;
struct s3c24xx_dma_chan *s3cchan = phy->serving;
struct s3c24xx_txd *txd;
dev_dbg(&phy->host->pdev->dev, "interrupt on channel %d\n", phy->id);
if (unlikely(!s3cchan)) {
dev_err(&phy->host->pdev->dev, "interrupt on unused channel %d\n",
phy->id);
s3c24xx_dma_terminate_phy(phy);
return IRQ_HANDLED;
}
spin_lock(&s3cchan->vc.lock);
txd = s3cchan->at;
if (txd) {
if (!list_is_last(txd->at, &txd->dsg_list)) {
txd->at = txd->at->next;
if (txd->cyclic)
vchan_cyclic_callback(&txd->vd);
s3c24xx_dma_start_next_sg(s3cchan, txd);
} else if (!txd->cyclic) {
s3cchan->at = NULL;
vchan_cookie_complete(&txd->vd);
if (vchan_next_desc(&s3cchan->vc))
s3c24xx_dma_start_next_txd(s3cchan);
else
s3c24xx_dma_phy_free(s3cchan);
} else {
vchan_cyclic_callback(&txd->vd);
txd->at = txd->dsg_list.next;
s3c24xx_dma_start_next_sg(s3cchan, txd);
}
}
spin_unlock(&s3cchan->vc.lock);
return IRQ_HANDLED;
}
static int s3c24xx_dma_terminate_all(struct dma_chan *chan)
{
struct s3c24xx_dma_chan *s3cchan = to_s3c24xx_dma_chan(chan);
struct s3c24xx_dma_engine *s3cdma = s3cchan->host;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&s3cchan->vc.lock, flags);
if (!s3cchan->phy && !s3cchan->at) {
dev_err(&s3cdma->pdev->dev, "trying to terminate already stopped channel %d\n",
s3cchan->id);
ret = -EINVAL;
goto unlock;
}
s3cchan->state = S3C24XX_DMA_CHAN_IDLE;
if (s3cchan->phy)
s3c24xx_dma_phy_free(s3cchan);
if (s3cchan->at) {
s3c24xx_dma_desc_free(&s3cchan->at->vd);
s3cchan->at = NULL;
}
s3c24xx_dma_free_txd_list(s3cdma, s3cchan);
unlock:
spin_unlock_irqrestore(&s3cchan->vc.lock, flags);
return ret;
}
static int s3c24xx_dma_alloc_chan_resources(struct dma_chan *chan)
{
return 0;
}
static void s3c24xx_dma_free_chan_resources(struct dma_chan *chan)
{
vchan_free_chan_resources(to_virt_chan(chan));
}
static enum dma_status s3c24xx_dma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie, struct dma_tx_state *txstate)
{
struct s3c24xx_dma_chan *s3cchan = to_s3c24xx_dma_chan(chan);
struct s3c24xx_txd *txd;
struct s3c24xx_sg *dsg;
struct virt_dma_desc *vd;
unsigned long flags;
enum dma_status ret;
size_t bytes = 0;
spin_lock_irqsave(&s3cchan->vc.lock, flags);
ret = dma_cookie_status(chan, cookie, txstate);
if (ret == DMA_COMPLETE) {
spin_unlock_irqrestore(&s3cchan->vc.lock, flags);
return ret;
}
if (!txstate) {
spin_unlock_irqrestore(&s3cchan->vc.lock, flags);
return ret;
}
vd = vchan_find_desc(&s3cchan->vc, cookie);
if (vd) {
txd = to_s3c24xx_txd(&vd->tx);
list_for_each_entry(dsg, &txd->dsg_list, node)
bytes += dsg->len;
} else {
txd = s3cchan->at;
dsg = list_entry(txd->at, struct s3c24xx_sg, node);
list_for_each_entry_from(dsg, &txd->dsg_list, node)
bytes += dsg->len;
bytes += s3c24xx_dma_getbytes_chan(s3cchan);
}
spin_unlock_irqrestore(&s3cchan->vc.lock, flags);
dma_set_residue(txstate, bytes);
return ret;
}
static struct dma_async_tx_descriptor *s3c24xx_dma_prep_memcpy(
struct dma_chan *chan, dma_addr_t dest, dma_addr_t src,
size_t len, unsigned long flags)
{
struct s3c24xx_dma_chan *s3cchan = to_s3c24xx_dma_chan(chan);
struct s3c24xx_dma_engine *s3cdma = s3cchan->host;
struct s3c24xx_txd *txd;
struct s3c24xx_sg *dsg;
int src_mod, dest_mod;
dev_dbg(&s3cdma->pdev->dev, "prepare memcpy of %d bytes from %s\n",
len, s3cchan->name);
if ((len & S3C24XX_DCON_TC_MASK) != len) {
dev_err(&s3cdma->pdev->dev, "memcpy size %d to large\n", len);
return NULL;
}
txd = s3c24xx_dma_get_txd();
if (!txd)
return NULL;
dsg = kzalloc(sizeof(*dsg), GFP_NOWAIT);
if (!dsg) {
s3c24xx_dma_free_txd(txd);
return NULL;
}
list_add_tail(&dsg->node, &txd->dsg_list);
dsg->src_addr = src;
dsg->dst_addr = dest;
dsg->len = len;
src_mod = src % 4;
dest_mod = dest % 4;
switch (len % 4) {
case 0:
txd->width = (src_mod == 0 && dest_mod == 0) ? 4 : 1;
break;
case 2:
txd->width = ((src_mod == 2 || src_mod == 0) &&
(dest_mod == 2 || dest_mod == 0)) ? 2 : 1;
break;
default:
txd->width = 1;
break;
}
txd->disrcc = S3C24XX_DISRCC_LOC_AHB | S3C24XX_DISRCC_INC_INCREMENT;
txd->didstc = S3C24XX_DIDSTC_LOC_AHB | S3C24XX_DIDSTC_INC_INCREMENT;
txd->dcon |= S3C24XX_DCON_DEMAND | S3C24XX_DCON_SYNC_HCLK |
S3C24XX_DCON_SERV_WHOLE;
return vchan_tx_prep(&s3cchan->vc, &txd->vd, flags);
}
static struct dma_async_tx_descriptor *s3c24xx_dma_prep_dma_cyclic(
struct dma_chan *chan, dma_addr_t addr, size_t size, size_t period,
enum dma_transfer_direction direction, unsigned long flags)
{
struct s3c24xx_dma_chan *s3cchan = to_s3c24xx_dma_chan(chan);
struct s3c24xx_dma_engine *s3cdma = s3cchan->host;
const struct s3c24xx_dma_platdata *pdata = s3cdma->pdata;
struct s3c24xx_dma_channel *cdata = &pdata->channels[s3cchan->id];
struct s3c24xx_txd *txd;
struct s3c24xx_sg *dsg;
unsigned sg_len;
dma_addr_t slave_addr;
u32 hwcfg = 0;
int i;
dev_dbg(&s3cdma->pdev->dev,
"prepare cyclic transaction of %zu bytes with period %zu from %s\n",
size, period, s3cchan->name);
if (!is_slave_direction(direction)) {
dev_err(&s3cdma->pdev->dev,
"direction %d unsupported\n", direction);
return NULL;
}
txd = s3c24xx_dma_get_txd();
if (!txd)
return NULL;
txd->cyclic = 1;
if (cdata->handshake)
txd->dcon |= S3C24XX_DCON_HANDSHAKE;
switch (cdata->bus) {
case S3C24XX_DMA_APB:
txd->dcon |= S3C24XX_DCON_SYNC_PCLK;
hwcfg |= S3C24XX_DISRCC_LOC_APB;
break;
case S3C24XX_DMA_AHB:
txd->dcon |= S3C24XX_DCON_SYNC_HCLK;
hwcfg |= S3C24XX_DISRCC_LOC_AHB;
break;
}
hwcfg |= S3C24XX_DISRCC_INC_FIXED;
txd->dcon |= S3C24XX_DCON_SERV_SINGLE;
if (direction == DMA_MEM_TO_DEV) {
txd->disrcc = S3C24XX_DISRCC_LOC_AHB |
S3C24XX_DISRCC_INC_INCREMENT;
txd->didstc = hwcfg;
slave_addr = s3cchan->cfg.dst_addr;
txd->width = s3cchan->cfg.dst_addr_width;
} else {
txd->disrcc = hwcfg;
txd->didstc = S3C24XX_DIDSTC_LOC_AHB |
S3C24XX_DIDSTC_INC_INCREMENT;
slave_addr = s3cchan->cfg.src_addr;
txd->width = s3cchan->cfg.src_addr_width;
}
sg_len = size / period;
for (i = 0; i < sg_len; i++) {
dsg = kzalloc(sizeof(*dsg), GFP_NOWAIT);
if (!dsg) {
s3c24xx_dma_free_txd(txd);
return NULL;
}
list_add_tail(&dsg->node, &txd->dsg_list);
dsg->len = period;
if (i == sg_len - 1)
dsg->len = size - period * i;
if (direction == DMA_MEM_TO_DEV) {
dsg->src_addr = addr + period * i;
dsg->dst_addr = slave_addr;
} else {
dsg->src_addr = slave_addr;
dsg->dst_addr = addr + period * i;
}
}
return vchan_tx_prep(&s3cchan->vc, &txd->vd, flags);
}
static struct dma_async_tx_descriptor *s3c24xx_dma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long flags, void *context)
{
struct s3c24xx_dma_chan *s3cchan = to_s3c24xx_dma_chan(chan);
struct s3c24xx_dma_engine *s3cdma = s3cchan->host;
const struct s3c24xx_dma_platdata *pdata = s3cdma->pdata;
struct s3c24xx_dma_channel *cdata = &pdata->channels[s3cchan->id];
struct s3c24xx_txd *txd;
struct s3c24xx_sg *dsg;
struct scatterlist *sg;
dma_addr_t slave_addr;
u32 hwcfg = 0;
int tmp;
dev_dbg(&s3cdma->pdev->dev, "prepare transaction of %d bytes from %s\n",
sg_dma_len(sgl), s3cchan->name);
txd = s3c24xx_dma_get_txd();
if (!txd)
return NULL;
if (cdata->handshake)
txd->dcon |= S3C24XX_DCON_HANDSHAKE;
switch (cdata->bus) {
case S3C24XX_DMA_APB:
txd->dcon |= S3C24XX_DCON_SYNC_PCLK;
hwcfg |= S3C24XX_DISRCC_LOC_APB;
break;
case S3C24XX_DMA_AHB:
txd->dcon |= S3C24XX_DCON_SYNC_HCLK;
hwcfg |= S3C24XX_DISRCC_LOC_AHB;
break;
}
hwcfg |= S3C24XX_DISRCC_INC_FIXED;
txd->dcon |= S3C24XX_DCON_SERV_SINGLE;
if (direction == DMA_MEM_TO_DEV) {
txd->disrcc = S3C24XX_DISRCC_LOC_AHB |
S3C24XX_DISRCC_INC_INCREMENT;
txd->didstc = hwcfg;
slave_addr = s3cchan->cfg.dst_addr;
txd->width = s3cchan->cfg.dst_addr_width;
} else if (direction == DMA_DEV_TO_MEM) {
txd->disrcc = hwcfg;
txd->didstc = S3C24XX_DIDSTC_LOC_AHB |
S3C24XX_DIDSTC_INC_INCREMENT;
slave_addr = s3cchan->cfg.src_addr;
txd->width = s3cchan->cfg.src_addr_width;
} else {
s3c24xx_dma_free_txd(txd);
dev_err(&s3cdma->pdev->dev,
"direction %d unsupported\n", direction);
return NULL;
}
for_each_sg(sgl, sg, sg_len, tmp) {
dsg = kzalloc(sizeof(*dsg), GFP_NOWAIT);
if (!dsg) {
s3c24xx_dma_free_txd(txd);
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
return vchan_tx_prep(&s3cchan->vc, &txd->vd, flags);
}
static void s3c24xx_dma_issue_pending(struct dma_chan *chan)
{
struct s3c24xx_dma_chan *s3cchan = to_s3c24xx_dma_chan(chan);
unsigned long flags;
spin_lock_irqsave(&s3cchan->vc.lock, flags);
if (vchan_issue_pending(&s3cchan->vc)) {
if (!s3cchan->phy && s3cchan->state != S3C24XX_DMA_CHAN_WAITING)
s3c24xx_dma_phy_alloc_and_start(s3cchan);
}
spin_unlock_irqrestore(&s3cchan->vc.lock, flags);
}
static int s3c24xx_dma_init_virtual_channels(struct s3c24xx_dma_engine *s3cdma,
struct dma_device *dmadev, unsigned int channels, bool slave)
{
struct s3c24xx_dma_chan *chan;
int i;
INIT_LIST_HEAD(&dmadev->channels);
for (i = 0; i < channels; i++) {
chan = devm_kzalloc(dmadev->dev, sizeof(*chan), GFP_KERNEL);
if (!chan) {
dev_err(dmadev->dev,
"%s no memory for channel\n", __func__);
return -ENOMEM;
}
chan->id = i;
chan->host = s3cdma;
chan->state = S3C24XX_DMA_CHAN_IDLE;
if (slave) {
chan->slave = true;
chan->name = kasprintf(GFP_KERNEL, "slave%d", i);
if (!chan->name)
return -ENOMEM;
} else {
chan->name = kasprintf(GFP_KERNEL, "memcpy%d", i);
if (!chan->name)
return -ENOMEM;
}
dev_dbg(dmadev->dev,
"initialize virtual channel \"%s\"\n",
chan->name);
chan->vc.desc_free = s3c24xx_dma_desc_free;
vchan_init(&chan->vc, dmadev);
}
dev_info(dmadev->dev, "initialized %d virtual %s channels\n",
i, slave ? "slave" : "memcpy");
return i;
}
static void s3c24xx_dma_free_virtual_channels(struct dma_device *dmadev)
{
struct s3c24xx_dma_chan *chan = NULL;
struct s3c24xx_dma_chan *next;
list_for_each_entry_safe(chan,
next, &dmadev->channels, vc.chan.device_node)
list_del(&chan->vc.chan.device_node);
}
static struct soc_data *s3c24xx_dma_get_soc_data(struct platform_device *pdev)
{
return (struct soc_data *)
platform_get_device_id(pdev)->driver_data;
}
static int s3c24xx_dma_probe(struct platform_device *pdev)
{
const struct s3c24xx_dma_platdata *pdata = dev_get_platdata(&pdev->dev);
struct s3c24xx_dma_engine *s3cdma;
struct soc_data *sdata;
struct resource *res;
int ret;
int i;
if (!pdata) {
dev_err(&pdev->dev, "platform data missing\n");
return -ENODEV;
}
if (pdata->num_phy_channels > MAX_DMA_CHANNELS) {
dev_err(&pdev->dev, "to many dma channels %d, max %d\n",
pdata->num_phy_channels, MAX_DMA_CHANNELS);
return -EINVAL;
}
sdata = s3c24xx_dma_get_soc_data(pdev);
if (!sdata)
return -EINVAL;
s3cdma = devm_kzalloc(&pdev->dev, sizeof(*s3cdma), GFP_KERNEL);
if (!s3cdma)
return -ENOMEM;
s3cdma->pdev = pdev;
s3cdma->pdata = pdata;
s3cdma->sdata = sdata;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
s3cdma->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(s3cdma->base))
return PTR_ERR(s3cdma->base);
s3cdma->phy_chans = devm_kzalloc(&pdev->dev,
sizeof(struct s3c24xx_dma_phy) *
pdata->num_phy_channels,
GFP_KERNEL);
if (!s3cdma->phy_chans)
return -ENOMEM;
for (i = 0; i < pdata->num_phy_channels; i++) {
struct s3c24xx_dma_phy *phy = &s3cdma->phy_chans[i];
char clk_name[6];
phy->id = i;
phy->base = s3cdma->base + (i * sdata->stride);
phy->host = s3cdma;
phy->irq = platform_get_irq(pdev, i);
if (phy->irq < 0) {
dev_err(&pdev->dev, "failed to get irq %d, err %d\n",
i, phy->irq);
continue;
}
ret = devm_request_irq(&pdev->dev, phy->irq, s3c24xx_dma_irq,
0, pdev->name, phy);
if (ret) {
dev_err(&pdev->dev, "Unable to request irq for channel %d, error %d\n",
i, ret);
continue;
}
if (sdata->has_clocks) {
sprintf(clk_name, "dma.%d", i);
phy->clk = devm_clk_get(&pdev->dev, clk_name);
if (IS_ERR(phy->clk) && sdata->has_clocks) {
dev_err(&pdev->dev, "unable to aquire clock for channel %d, error %lu",
i, PTR_ERR(phy->clk));
continue;
}
ret = clk_prepare(phy->clk);
if (ret) {
dev_err(&pdev->dev, "clock for phy %d failed, error %d\n",
i, ret);
continue;
}
}
spin_lock_init(&phy->lock);
phy->valid = true;
dev_dbg(&pdev->dev, "physical channel %d is %s\n",
i, s3c24xx_dma_phy_busy(phy) ? "BUSY" : "FREE");
}
dma_cap_set(DMA_MEMCPY, s3cdma->memcpy.cap_mask);
dma_cap_set(DMA_PRIVATE, s3cdma->memcpy.cap_mask);
s3cdma->memcpy.dev = &pdev->dev;
s3cdma->memcpy.device_alloc_chan_resources =
s3c24xx_dma_alloc_chan_resources;
s3cdma->memcpy.device_free_chan_resources =
s3c24xx_dma_free_chan_resources;
s3cdma->memcpy.device_prep_dma_memcpy = s3c24xx_dma_prep_memcpy;
s3cdma->memcpy.device_tx_status = s3c24xx_dma_tx_status;
s3cdma->memcpy.device_issue_pending = s3c24xx_dma_issue_pending;
s3cdma->memcpy.device_config = s3c24xx_dma_set_runtime_config;
s3cdma->memcpy.device_terminate_all = s3c24xx_dma_terminate_all;
dma_cap_set(DMA_SLAVE, s3cdma->slave.cap_mask);
dma_cap_set(DMA_CYCLIC, s3cdma->slave.cap_mask);
dma_cap_set(DMA_PRIVATE, s3cdma->slave.cap_mask);
s3cdma->slave.dev = &pdev->dev;
s3cdma->slave.device_alloc_chan_resources =
s3c24xx_dma_alloc_chan_resources;
s3cdma->slave.device_free_chan_resources =
s3c24xx_dma_free_chan_resources;
s3cdma->slave.device_tx_status = s3c24xx_dma_tx_status;
s3cdma->slave.device_issue_pending = s3c24xx_dma_issue_pending;
s3cdma->slave.device_prep_slave_sg = s3c24xx_dma_prep_slave_sg;
s3cdma->slave.device_prep_dma_cyclic = s3c24xx_dma_prep_dma_cyclic;
s3cdma->slave.device_config = s3c24xx_dma_set_runtime_config;
s3cdma->slave.device_terminate_all = s3c24xx_dma_terminate_all;
ret = s3c24xx_dma_init_virtual_channels(s3cdma, &s3cdma->memcpy,
pdata->num_phy_channels, false);
if (ret <= 0) {
dev_warn(&pdev->dev,
"%s failed to enumerate memcpy channels - %d\n",
__func__, ret);
goto err_memcpy;
}
ret = s3c24xx_dma_init_virtual_channels(s3cdma, &s3cdma->slave,
pdata->num_channels, true);
if (ret <= 0) {
dev_warn(&pdev->dev,
"%s failed to enumerate slave channels - %d\n",
__func__, ret);
goto err_slave;
}
ret = dma_async_device_register(&s3cdma->memcpy);
if (ret) {
dev_warn(&pdev->dev,
"%s failed to register memcpy as an async device - %d\n",
__func__, ret);
goto err_memcpy_reg;
}
ret = dma_async_device_register(&s3cdma->slave);
if (ret) {
dev_warn(&pdev->dev,
"%s failed to register slave as an async device - %d\n",
__func__, ret);
goto err_slave_reg;
}
platform_set_drvdata(pdev, s3cdma);
dev_info(&pdev->dev, "Loaded dma driver with %d physical channels\n",
pdata->num_phy_channels);
return 0;
err_slave_reg:
dma_async_device_unregister(&s3cdma->memcpy);
err_memcpy_reg:
s3c24xx_dma_free_virtual_channels(&s3cdma->slave);
err_slave:
s3c24xx_dma_free_virtual_channels(&s3cdma->memcpy);
err_memcpy:
if (sdata->has_clocks)
for (i = 0; i < pdata->num_phy_channels; i++) {
struct s3c24xx_dma_phy *phy = &s3cdma->phy_chans[i];
if (phy->valid)
clk_unprepare(phy->clk);
}
return ret;
}
static int s3c24xx_dma_remove(struct platform_device *pdev)
{
const struct s3c24xx_dma_platdata *pdata = dev_get_platdata(&pdev->dev);
struct s3c24xx_dma_engine *s3cdma = platform_get_drvdata(pdev);
struct soc_data *sdata = s3c24xx_dma_get_soc_data(pdev);
int i;
dma_async_device_unregister(&s3cdma->slave);
dma_async_device_unregister(&s3cdma->memcpy);
s3c24xx_dma_free_virtual_channels(&s3cdma->slave);
s3c24xx_dma_free_virtual_channels(&s3cdma->memcpy);
if (sdata->has_clocks)
for (i = 0; i < pdata->num_phy_channels; i++) {
struct s3c24xx_dma_phy *phy = &s3cdma->phy_chans[i];
if (phy->valid)
clk_unprepare(phy->clk);
}
return 0;
}
bool s3c24xx_dma_filter(struct dma_chan *chan, void *param)
{
struct s3c24xx_dma_chan *s3cchan;
if (chan->device->dev->driver != &s3c24xx_dma_driver.driver)
return false;
s3cchan = to_s3c24xx_dma_chan(chan);
return s3cchan->id == (int)param;
}
