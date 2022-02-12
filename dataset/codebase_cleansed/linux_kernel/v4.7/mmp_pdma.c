static void set_desc(struct mmp_pdma_phy *phy, dma_addr_t addr)
{
u32 reg = (phy->idx << 4) + DDADR;
writel(addr, phy->base + reg);
}
static void enable_chan(struct mmp_pdma_phy *phy)
{
u32 reg, dalgn;
if (!phy->vchan)
return;
reg = DRCMR(phy->vchan->drcmr);
writel(DRCMR_MAPVLD | phy->idx, phy->base + reg);
dalgn = readl(phy->base + DALGN);
if (phy->vchan->byte_align)
dalgn |= 1 << phy->idx;
else
dalgn &= ~(1 << phy->idx);
writel(dalgn, phy->base + DALGN);
reg = (phy->idx << 2) + DCSR;
writel(readl(phy->base + reg) | DCSR_RUN, phy->base + reg);
}
static void disable_chan(struct mmp_pdma_phy *phy)
{
u32 reg;
if (!phy)
return;
reg = (phy->idx << 2) + DCSR;
writel(readl(phy->base + reg) & ~DCSR_RUN, phy->base + reg);
}
static int clear_chan_irq(struct mmp_pdma_phy *phy)
{
u32 dcsr;
u32 dint = readl(phy->base + DINT);
u32 reg = (phy->idx << 2) + DCSR;
if (!(dint & BIT(phy->idx)))
return -EAGAIN;
dcsr = readl(phy->base + reg);
writel(dcsr, phy->base + reg);
if ((dcsr & DCSR_BUSERR) && (phy->vchan))
dev_warn(phy->vchan->dev, "DCSR_BUSERR\n");
return 0;
}
static irqreturn_t mmp_pdma_chan_handler(int irq, void *dev_id)
{
struct mmp_pdma_phy *phy = dev_id;
if (clear_chan_irq(phy) != 0)
return IRQ_NONE;
tasklet_schedule(&phy->vchan->tasklet);
return IRQ_HANDLED;
}
static irqreturn_t mmp_pdma_int_handler(int irq, void *dev_id)
{
struct mmp_pdma_device *pdev = dev_id;
struct mmp_pdma_phy *phy;
u32 dint = readl(pdev->base + DINT);
int i, ret;
int irq_num = 0;
while (dint) {
i = __ffs(dint);
if (i >= pdev->dma_channels)
break;
dint &= (dint - 1);
phy = &pdev->phy[i];
ret = mmp_pdma_chan_handler(irq, phy);
if (ret == IRQ_HANDLED)
irq_num++;
}
if (irq_num)
return IRQ_HANDLED;
return IRQ_NONE;
}
static struct mmp_pdma_phy *lookup_phy(struct mmp_pdma_chan *pchan)
{
int prio, i;
struct mmp_pdma_device *pdev = to_mmp_pdma_dev(pchan->chan.device);
struct mmp_pdma_phy *phy, *found = NULL;
unsigned long flags;
spin_lock_irqsave(&pdev->phy_lock, flags);
for (prio = 0; prio <= ((pdev->dma_channels - 1) & 0xf) >> 2; prio++) {
for (i = 0; i < pdev->dma_channels; i++) {
if (prio != (i & 0xf) >> 2)
continue;
phy = &pdev->phy[i];
if (!phy->vchan) {
phy->vchan = pchan;
found = phy;
goto out_unlock;
}
}
}
out_unlock:
spin_unlock_irqrestore(&pdev->phy_lock, flags);
return found;
}
static void mmp_pdma_free_phy(struct mmp_pdma_chan *pchan)
{
struct mmp_pdma_device *pdev = to_mmp_pdma_dev(pchan->chan.device);
unsigned long flags;
u32 reg;
if (!pchan->phy)
return;
reg = DRCMR(pchan->drcmr);
writel(0, pchan->phy->base + reg);
spin_lock_irqsave(&pdev->phy_lock, flags);
pchan->phy->vchan = NULL;
pchan->phy = NULL;
spin_unlock_irqrestore(&pdev->phy_lock, flags);
}
static void start_pending_queue(struct mmp_pdma_chan *chan)
{
struct mmp_pdma_desc_sw *desc;
if (!chan->idle) {
dev_dbg(chan->dev, "DMA controller still busy\n");
return;
}
if (list_empty(&chan->chain_pending)) {
mmp_pdma_free_phy(chan);
dev_dbg(chan->dev, "no pending list\n");
return;
}
if (!chan->phy) {
chan->phy = lookup_phy(chan);
if (!chan->phy) {
dev_dbg(chan->dev, "no free dma channel\n");
return;
}
}
desc = list_first_entry(&chan->chain_pending,
struct mmp_pdma_desc_sw, node);
list_splice_tail_init(&chan->chain_pending, &chan->chain_running);
set_desc(chan->phy, desc->async_tx.phys);
enable_chan(chan->phy);
chan->idle = false;
}
static dma_cookie_t mmp_pdma_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct mmp_pdma_chan *chan = to_mmp_pdma_chan(tx->chan);
struct mmp_pdma_desc_sw *desc = tx_to_mmp_pdma_desc(tx);
struct mmp_pdma_desc_sw *child;
unsigned long flags;
dma_cookie_t cookie = -EBUSY;
spin_lock_irqsave(&chan->desc_lock, flags);
list_for_each_entry(child, &desc->tx_list, node) {
cookie = dma_cookie_assign(&child->async_tx);
}
list_splice_tail_init(&desc->tx_list, &chan->chain_pending);
spin_unlock_irqrestore(&chan->desc_lock, flags);
return cookie;
}
static struct mmp_pdma_desc_sw *
mmp_pdma_alloc_descriptor(struct mmp_pdma_chan *chan)
{
struct mmp_pdma_desc_sw *desc;
dma_addr_t pdesc;
desc = dma_pool_zalloc(chan->desc_pool, GFP_ATOMIC, &pdesc);
if (!desc) {
dev_err(chan->dev, "out of memory for link descriptor\n");
return NULL;
}
INIT_LIST_HEAD(&desc->tx_list);
dma_async_tx_descriptor_init(&desc->async_tx, &chan->chan);
desc->async_tx.tx_submit = mmp_pdma_tx_submit;
desc->async_tx.phys = pdesc;
return desc;
}
static int mmp_pdma_alloc_chan_resources(struct dma_chan *dchan)
{
struct mmp_pdma_chan *chan = to_mmp_pdma_chan(dchan);
if (chan->desc_pool)
return 1;
chan->desc_pool = dma_pool_create(dev_name(&dchan->dev->device),
chan->dev,
sizeof(struct mmp_pdma_desc_sw),
__alignof__(struct mmp_pdma_desc_sw),
0);
if (!chan->desc_pool) {
dev_err(chan->dev, "unable to allocate descriptor pool\n");
return -ENOMEM;
}
mmp_pdma_free_phy(chan);
chan->idle = true;
chan->dev_addr = 0;
return 1;
}
static void mmp_pdma_free_desc_list(struct mmp_pdma_chan *chan,
struct list_head *list)
{
struct mmp_pdma_desc_sw *desc, *_desc;
list_for_each_entry_safe(desc, _desc, list, node) {
list_del(&desc->node);
dma_pool_free(chan->desc_pool, desc, desc->async_tx.phys);
}
}
static void mmp_pdma_free_chan_resources(struct dma_chan *dchan)
{
struct mmp_pdma_chan *chan = to_mmp_pdma_chan(dchan);
unsigned long flags;
spin_lock_irqsave(&chan->desc_lock, flags);
mmp_pdma_free_desc_list(chan, &chan->chain_pending);
mmp_pdma_free_desc_list(chan, &chan->chain_running);
spin_unlock_irqrestore(&chan->desc_lock, flags);
dma_pool_destroy(chan->desc_pool);
chan->desc_pool = NULL;
chan->idle = true;
chan->dev_addr = 0;
mmp_pdma_free_phy(chan);
return;
}
static struct dma_async_tx_descriptor *
mmp_pdma_prep_memcpy(struct dma_chan *dchan,
dma_addr_t dma_dst, dma_addr_t dma_src,
size_t len, unsigned long flags)
{
struct mmp_pdma_chan *chan;
struct mmp_pdma_desc_sw *first = NULL, *prev = NULL, *new;
size_t copy = 0;
if (!dchan)
return NULL;
if (!len)
return NULL;
chan = to_mmp_pdma_chan(dchan);
chan->byte_align = false;
if (!chan->dir) {
chan->dir = DMA_MEM_TO_MEM;
chan->dcmd = DCMD_INCTRGADDR | DCMD_INCSRCADDR;
chan->dcmd |= DCMD_BURST32;
}
do {
new = mmp_pdma_alloc_descriptor(chan);
if (!new) {
dev_err(chan->dev, "no memory for desc\n");
goto fail;
}
copy = min_t(size_t, len, PDMA_MAX_DESC_BYTES);
if (dma_src & 0x7 || dma_dst & 0x7)
chan->byte_align = true;
new->desc.dcmd = chan->dcmd | (DCMD_LENGTH & copy);
new->desc.dsadr = dma_src;
new->desc.dtadr = dma_dst;
if (!first)
first = new;
else
prev->desc.ddadr = new->async_tx.phys;
new->async_tx.cookie = 0;
async_tx_ack(&new->async_tx);
prev = new;
len -= copy;
if (chan->dir == DMA_MEM_TO_DEV) {
dma_src += copy;
} else if (chan->dir == DMA_DEV_TO_MEM) {
dma_dst += copy;
} else if (chan->dir == DMA_MEM_TO_MEM) {
dma_src += copy;
dma_dst += copy;
}
list_add_tail(&new->node, &first->tx_list);
} while (len);
first->async_tx.flags = flags;
first->async_tx.cookie = -EBUSY;
new->desc.ddadr = DDADR_STOP;
new->desc.dcmd |= DCMD_ENDIRQEN;
chan->cyclic_first = NULL;
return &first->async_tx;
fail:
if (first)
mmp_pdma_free_desc_list(chan, &first->tx_list);
return NULL;
}
static struct dma_async_tx_descriptor *
mmp_pdma_prep_slave_sg(struct dma_chan *dchan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction dir,
unsigned long flags, void *context)
{
struct mmp_pdma_chan *chan = to_mmp_pdma_chan(dchan);
struct mmp_pdma_desc_sw *first = NULL, *prev = NULL, *new = NULL;
size_t len, avail;
struct scatterlist *sg;
dma_addr_t addr;
int i;
if ((sgl == NULL) || (sg_len == 0))
return NULL;
chan->byte_align = false;
for_each_sg(sgl, sg, sg_len, i) {
addr = sg_dma_address(sg);
avail = sg_dma_len(sgl);
do {
len = min_t(size_t, avail, PDMA_MAX_DESC_BYTES);
if (addr & 0x7)
chan->byte_align = true;
new = mmp_pdma_alloc_descriptor(chan);
if (!new) {
dev_err(chan->dev, "no memory for desc\n");
goto fail;
}
new->desc.dcmd = chan->dcmd | (DCMD_LENGTH & len);
if (dir == DMA_MEM_TO_DEV) {
new->desc.dsadr = addr;
new->desc.dtadr = chan->dev_addr;
} else {
new->desc.dsadr = chan->dev_addr;
new->desc.dtadr = addr;
}
if (!first)
first = new;
else
prev->desc.ddadr = new->async_tx.phys;
new->async_tx.cookie = 0;
async_tx_ack(&new->async_tx);
prev = new;
list_add_tail(&new->node, &first->tx_list);
addr += len;
avail -= len;
} while (avail);
}
first->async_tx.cookie = -EBUSY;
first->async_tx.flags = flags;
new->desc.ddadr = DDADR_STOP;
new->desc.dcmd |= DCMD_ENDIRQEN;
chan->dir = dir;
chan->cyclic_first = NULL;
return &first->async_tx;
fail:
if (first)
mmp_pdma_free_desc_list(chan, &first->tx_list);
return NULL;
}
static struct dma_async_tx_descriptor *
mmp_pdma_prep_dma_cyclic(struct dma_chan *dchan,
dma_addr_t buf_addr, size_t len, size_t period_len,
enum dma_transfer_direction direction,
unsigned long flags)
{
struct mmp_pdma_chan *chan;
struct mmp_pdma_desc_sw *first = NULL, *prev = NULL, *new;
dma_addr_t dma_src, dma_dst;
if (!dchan || !len || !period_len)
return NULL;
if (len % period_len != 0)
return NULL;
if (period_len > PDMA_MAX_DESC_BYTES)
return NULL;
chan = to_mmp_pdma_chan(dchan);
switch (direction) {
case DMA_MEM_TO_DEV:
dma_src = buf_addr;
dma_dst = chan->dev_addr;
break;
case DMA_DEV_TO_MEM:
dma_dst = buf_addr;
dma_src = chan->dev_addr;
break;
default:
dev_err(chan->dev, "Unsupported direction for cyclic DMA\n");
return NULL;
}
chan->dir = direction;
do {
new = mmp_pdma_alloc_descriptor(chan);
if (!new) {
dev_err(chan->dev, "no memory for desc\n");
goto fail;
}
new->desc.dcmd = (chan->dcmd | DCMD_ENDIRQEN |
(DCMD_LENGTH & period_len));
new->desc.dsadr = dma_src;
new->desc.dtadr = dma_dst;
if (!first)
first = new;
else
prev->desc.ddadr = new->async_tx.phys;
new->async_tx.cookie = 0;
async_tx_ack(&new->async_tx);
prev = new;
len -= period_len;
if (chan->dir == DMA_MEM_TO_DEV)
dma_src += period_len;
else
dma_dst += period_len;
list_add_tail(&new->node, &first->tx_list);
} while (len);
first->async_tx.flags = flags;
first->async_tx.cookie = -EBUSY;
new->desc.ddadr = first->async_tx.phys;
chan->cyclic_first = first;
return &first->async_tx;
fail:
if (first)
mmp_pdma_free_desc_list(chan, &first->tx_list);
return NULL;
}
static int mmp_pdma_config(struct dma_chan *dchan,
struct dma_slave_config *cfg)
{
struct mmp_pdma_chan *chan = to_mmp_pdma_chan(dchan);
u32 maxburst = 0, addr = 0;
enum dma_slave_buswidth width = DMA_SLAVE_BUSWIDTH_UNDEFINED;
if (!dchan)
return -EINVAL;
if (cfg->direction == DMA_DEV_TO_MEM) {
chan->dcmd = DCMD_INCTRGADDR | DCMD_FLOWSRC;
maxburst = cfg->src_maxburst;
width = cfg->src_addr_width;
addr = cfg->src_addr;
} else if (cfg->direction == DMA_MEM_TO_DEV) {
chan->dcmd = DCMD_INCSRCADDR | DCMD_FLOWTRG;
maxburst = cfg->dst_maxburst;
width = cfg->dst_addr_width;
addr = cfg->dst_addr;
}
if (width == DMA_SLAVE_BUSWIDTH_1_BYTE)
chan->dcmd |= DCMD_WIDTH1;
else if (width == DMA_SLAVE_BUSWIDTH_2_BYTES)
chan->dcmd |= DCMD_WIDTH2;
else if (width == DMA_SLAVE_BUSWIDTH_4_BYTES)
chan->dcmd |= DCMD_WIDTH4;
if (maxburst == 8)
chan->dcmd |= DCMD_BURST8;
else if (maxburst == 16)
chan->dcmd |= DCMD_BURST16;
else if (maxburst == 32)
chan->dcmd |= DCMD_BURST32;
chan->dir = cfg->direction;
chan->dev_addr = addr;
if (cfg->slave_id)
chan->drcmr = cfg->slave_id;
return 0;
}
static int mmp_pdma_terminate_all(struct dma_chan *dchan)
{
struct mmp_pdma_chan *chan = to_mmp_pdma_chan(dchan);
unsigned long flags;
if (!dchan)
return -EINVAL;
disable_chan(chan->phy);
mmp_pdma_free_phy(chan);
spin_lock_irqsave(&chan->desc_lock, flags);
mmp_pdma_free_desc_list(chan, &chan->chain_pending);
mmp_pdma_free_desc_list(chan, &chan->chain_running);
spin_unlock_irqrestore(&chan->desc_lock, flags);
chan->idle = true;
return 0;
}
static unsigned int mmp_pdma_residue(struct mmp_pdma_chan *chan,
dma_cookie_t cookie)
{
struct mmp_pdma_desc_sw *sw;
u32 curr, residue = 0;
bool passed = false;
bool cyclic = chan->cyclic_first != NULL;
if (!chan->phy)
return 0;
if (chan->dir == DMA_DEV_TO_MEM)
curr = readl(chan->phy->base + DTADR(chan->phy->idx));
else
curr = readl(chan->phy->base + DSADR(chan->phy->idx));
list_for_each_entry(sw, &chan->chain_running, node) {
u32 start, end, len;
if (chan->dir == DMA_DEV_TO_MEM)
start = sw->desc.dtadr;
else
start = sw->desc.dsadr;
len = sw->desc.dcmd & DCMD_LENGTH;
end = start + len;
if (passed) {
residue += len;
} else if (curr >= start && curr <= end) {
residue += end - curr;
passed = true;
}
if (cyclic || !(sw->desc.dcmd & DCMD_ENDIRQEN))
continue;
if (sw->async_tx.cookie == cookie) {
return residue;
} else {
residue = 0;
passed = false;
}
}
return residue;
}
static enum dma_status mmp_pdma_tx_status(struct dma_chan *dchan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct mmp_pdma_chan *chan = to_mmp_pdma_chan(dchan);
enum dma_status ret;
ret = dma_cookie_status(dchan, cookie, txstate);
if (likely(ret != DMA_ERROR))
dma_set_residue(txstate, mmp_pdma_residue(chan, cookie));
return ret;
}
static void mmp_pdma_issue_pending(struct dma_chan *dchan)
{
struct mmp_pdma_chan *chan = to_mmp_pdma_chan(dchan);
unsigned long flags;
spin_lock_irqsave(&chan->desc_lock, flags);
start_pending_queue(chan);
spin_unlock_irqrestore(&chan->desc_lock, flags);
}
static void dma_do_tasklet(unsigned long data)
{
struct mmp_pdma_chan *chan = (struct mmp_pdma_chan *)data;
struct mmp_pdma_desc_sw *desc, *_desc;
LIST_HEAD(chain_cleanup);
unsigned long flags;
if (chan->cyclic_first) {
dma_async_tx_callback cb = NULL;
void *cb_data = NULL;
spin_lock_irqsave(&chan->desc_lock, flags);
desc = chan->cyclic_first;
cb = desc->async_tx.callback;
cb_data = desc->async_tx.callback_param;
spin_unlock_irqrestore(&chan->desc_lock, flags);
if (cb)
cb(cb_data);
return;
}
spin_lock_irqsave(&chan->desc_lock, flags);
list_for_each_entry_safe(desc, _desc, &chan->chain_running, node) {
list_move(&desc->node, &chain_cleanup);
if (desc->desc.dcmd & DCMD_ENDIRQEN) {
dma_cookie_t cookie = desc->async_tx.cookie;
dma_cookie_complete(&desc->async_tx);
dev_dbg(chan->dev, "completed_cookie=%d\n", cookie);
break;
}
}
chan->idle = list_empty(&chan->chain_running);
start_pending_queue(chan);
spin_unlock_irqrestore(&chan->desc_lock, flags);
list_for_each_entry_safe(desc, _desc, &chain_cleanup, node) {
struct dma_async_tx_descriptor *txd = &desc->async_tx;
list_del(&desc->node);
if (txd->callback)
txd->callback(txd->callback_param);
dma_pool_free(chan->desc_pool, desc, txd->phys);
}
}
static int mmp_pdma_remove(struct platform_device *op)
{
struct mmp_pdma_device *pdev = platform_get_drvdata(op);
dma_async_device_unregister(&pdev->device);
return 0;
}
static int mmp_pdma_chan_init(struct mmp_pdma_device *pdev, int idx, int irq)
{
struct mmp_pdma_phy *phy = &pdev->phy[idx];
struct mmp_pdma_chan *chan;
int ret;
chan = devm_kzalloc(pdev->dev, sizeof(*chan), GFP_KERNEL);
if (chan == NULL)
return -ENOMEM;
phy->idx = idx;
phy->base = pdev->base;
if (irq) {
ret = devm_request_irq(pdev->dev, irq, mmp_pdma_chan_handler,
IRQF_SHARED, "pdma", phy);
if (ret) {
dev_err(pdev->dev, "channel request irq fail!\n");
return ret;
}
}
spin_lock_init(&chan->desc_lock);
chan->dev = pdev->dev;
chan->chan.device = &pdev->device;
tasklet_init(&chan->tasklet, dma_do_tasklet, (unsigned long)chan);
INIT_LIST_HEAD(&chan->chain_pending);
INIT_LIST_HEAD(&chan->chain_running);
list_add_tail(&chan->chan.device_node, &pdev->device.channels);
return 0;
}
static struct dma_chan *mmp_pdma_dma_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct mmp_pdma_device *d = ofdma->of_dma_data;
struct dma_chan *chan;
chan = dma_get_any_slave_channel(&d->device);
if (!chan)
return NULL;
to_mmp_pdma_chan(chan)->drcmr = dma_spec->args[0];
return chan;
}
static int mmp_pdma_probe(struct platform_device *op)
{
struct mmp_pdma_device *pdev;
const struct of_device_id *of_id;
struct mmp_dma_platdata *pdata = dev_get_platdata(&op->dev);
struct resource *iores;
int i, ret, irq = 0;
int dma_channels = 0, irq_num = 0;
const enum dma_slave_buswidth widths =
DMA_SLAVE_BUSWIDTH_1_BYTE | DMA_SLAVE_BUSWIDTH_2_BYTES |
DMA_SLAVE_BUSWIDTH_4_BYTES;
pdev = devm_kzalloc(&op->dev, sizeof(*pdev), GFP_KERNEL);
if (!pdev)
return -ENOMEM;
pdev->dev = &op->dev;
spin_lock_init(&pdev->phy_lock);
iores = platform_get_resource(op, IORESOURCE_MEM, 0);
pdev->base = devm_ioremap_resource(pdev->dev, iores);
if (IS_ERR(pdev->base))
return PTR_ERR(pdev->base);
of_id = of_match_device(mmp_pdma_dt_ids, pdev->dev);
if (of_id)
of_property_read_u32(pdev->dev->of_node, "#dma-channels",
&dma_channels);
else if (pdata && pdata->dma_channels)
dma_channels = pdata->dma_channels;
else
dma_channels = 32;
pdev->dma_channels = dma_channels;
for (i = 0; i < dma_channels; i++) {
if (platform_get_irq(op, i) > 0)
irq_num++;
}
pdev->phy = devm_kcalloc(pdev->dev, dma_channels, sizeof(*pdev->phy),
GFP_KERNEL);
if (pdev->phy == NULL)
return -ENOMEM;
INIT_LIST_HEAD(&pdev->device.channels);
if (irq_num != dma_channels) {
irq = platform_get_irq(op, 0);
ret = devm_request_irq(pdev->dev, irq, mmp_pdma_int_handler,
IRQF_SHARED, "pdma", pdev);
if (ret)
return ret;
}
for (i = 0; i < dma_channels; i++) {
irq = (irq_num != dma_channels) ? 0 : platform_get_irq(op, i);
ret = mmp_pdma_chan_init(pdev, i, irq);
if (ret)
return ret;
}
dma_cap_set(DMA_SLAVE, pdev->device.cap_mask);
dma_cap_set(DMA_MEMCPY, pdev->device.cap_mask);
dma_cap_set(DMA_CYCLIC, pdev->device.cap_mask);
dma_cap_set(DMA_PRIVATE, pdev->device.cap_mask);
pdev->device.dev = &op->dev;
pdev->device.device_alloc_chan_resources = mmp_pdma_alloc_chan_resources;
pdev->device.device_free_chan_resources = mmp_pdma_free_chan_resources;
pdev->device.device_tx_status = mmp_pdma_tx_status;
pdev->device.device_prep_dma_memcpy = mmp_pdma_prep_memcpy;
pdev->device.device_prep_slave_sg = mmp_pdma_prep_slave_sg;
pdev->device.device_prep_dma_cyclic = mmp_pdma_prep_dma_cyclic;
pdev->device.device_issue_pending = mmp_pdma_issue_pending;
pdev->device.device_config = mmp_pdma_config;
pdev->device.device_terminate_all = mmp_pdma_terminate_all;
pdev->device.copy_align = DMAENGINE_ALIGN_8_BYTES;
pdev->device.src_addr_widths = widths;
pdev->device.dst_addr_widths = widths;
pdev->device.directions = BIT(DMA_MEM_TO_DEV) | BIT(DMA_DEV_TO_MEM);
pdev->device.residue_granularity = DMA_RESIDUE_GRANULARITY_DESCRIPTOR;
if (pdev->dev->coherent_dma_mask)
dma_set_mask(pdev->dev, pdev->dev->coherent_dma_mask);
else
dma_set_mask(pdev->dev, DMA_BIT_MASK(64));
ret = dma_async_device_register(&pdev->device);
if (ret) {
dev_err(pdev->device.dev, "unable to register\n");
return ret;
}
if (op->dev.of_node) {
ret = of_dma_controller_register(op->dev.of_node,
mmp_pdma_dma_xlate, pdev);
if (ret < 0) {
dev_err(&op->dev, "of_dma_controller_register failed\n");
return ret;
}
}
platform_set_drvdata(op, pdev);
dev_info(pdev->device.dev, "initialized %d channels\n", dma_channels);
return 0;
}
bool mmp_pdma_filter_fn(struct dma_chan *chan, void *param)
{
struct mmp_pdma_chan *c = to_mmp_pdma_chan(chan);
if (chan->device->dev->driver != &mmp_pdma_driver.driver)
return false;
c->drcmr = *(unsigned int *)param;
return true;
}
