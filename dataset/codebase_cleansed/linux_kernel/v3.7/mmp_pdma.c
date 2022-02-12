static void set_desc(struct mmp_pdma_phy *phy, dma_addr_t addr)
{
u32 reg = (phy->idx << 4) + DDADR;
writel(addr, phy->base + reg);
}
static void enable_chan(struct mmp_pdma_phy *phy)
{
u32 reg;
if (!phy->vchan)
return;
reg = phy->vchan->drcmr;
reg = (((reg) < 64) ? 0x0100 : 0x1100) + (((reg) & 0x3f) << 2);
writel(DRCMR_MAPVLD | phy->idx, phy->base + reg);
reg = (phy->idx << 2) + DCSR;
writel(readl(phy->base + reg) | DCSR_RUN,
phy->base + reg);
}
static void disable_chan(struct mmp_pdma_phy *phy)
{
u32 reg;
if (phy) {
reg = (phy->idx << 2) + DCSR;
writel(readl(phy->base + reg) & ~DCSR_RUN,
phy->base + reg);
}
}
static int clear_chan_irq(struct mmp_pdma_phy *phy)
{
u32 dcsr;
u32 dint = readl(phy->base + DINT);
u32 reg = (phy->idx << 2) + DCSR;
if (dint & BIT(phy->idx)) {
dcsr = readl(phy->base + reg);
writel(dcsr, phy->base + reg);
if ((dcsr & DCSR_BUSERR) && (phy->vchan))
dev_warn(phy->vchan->dev, "DCSR_BUSERR\n");
return 0;
}
return -EAGAIN;
}
static irqreturn_t mmp_pdma_chan_handler(int irq, void *dev_id)
{
struct mmp_pdma_phy *phy = dev_id;
if (clear_chan_irq(phy) == 0) {
tasklet_schedule(&phy->vchan->tasklet);
return IRQ_HANDLED;
} else
return IRQ_NONE;
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
dint &= (dint - 1);
phy = &pdev->phy[i];
ret = mmp_pdma_chan_handler(irq, phy);
if (ret == IRQ_HANDLED)
irq_num++;
}
if (irq_num)
return IRQ_HANDLED;
else
return IRQ_NONE;
}
static struct mmp_pdma_phy *lookup_phy(struct mmp_pdma_chan *pchan)
{
int prio, i;
struct mmp_pdma_device *pdev = to_mmp_pdma_dev(pchan->chan.device);
struct mmp_pdma_phy *phy;
for (prio = 0; prio <= (((pdev->dma_channels - 1) & 0xf) >> 2); prio++) {
for (i = 0; i < pdev->dma_channels; i++) {
if (prio != ((i & 0xf) >> 2))
continue;
phy = &pdev->phy[i];
if (!phy->vchan) {
phy->vchan = pchan;
return phy;
}
}
}
return NULL;
}
static void append_pending_queue(struct mmp_pdma_chan *chan,
struct mmp_pdma_desc_sw *desc)
{
struct mmp_pdma_desc_sw *tail =
to_mmp_pdma_desc(chan->chain_pending.prev);
if (list_empty(&chan->chain_pending))
goto out_splice;
tail->desc.ddadr = desc->async_tx.phys;
tail->desc.dcmd &= ~DCMD_ENDIRQEN;
out_splice:
list_splice_tail_init(&desc->tx_list, &chan->chain_pending);
}
static void start_pending_queue(struct mmp_pdma_chan *chan)
{
struct mmp_pdma_desc_sw *desc;
if (!chan->idle) {
dev_dbg(chan->dev, "DMA controller still busy\n");
return;
}
if (list_empty(&chan->chain_pending)) {
if (chan->phy) {
chan->phy->vchan = NULL;
chan->phy = NULL;
}
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
append_pending_queue(chan, desc);
spin_unlock_irqrestore(&chan->desc_lock, flags);
return cookie;
}
struct mmp_pdma_desc_sw *mmp_pdma_alloc_descriptor(struct mmp_pdma_chan *chan)
{
struct mmp_pdma_desc_sw *desc;
dma_addr_t pdesc;
desc = dma_pool_alloc(chan->desc_pool, GFP_ATOMIC, &pdesc);
if (!desc) {
dev_err(chan->dev, "out of memory for link descriptor\n");
return NULL;
}
memset(desc, 0, sizeof(*desc));
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
chan->desc_pool =
dma_pool_create(dev_name(&dchan->dev->device), chan->dev,
sizeof(struct mmp_pdma_desc_sw),
__alignof__(struct mmp_pdma_desc_sw), 0);
if (!chan->desc_pool) {
dev_err(chan->dev, "unable to allocate descriptor pool\n");
return -ENOMEM;
}
if (chan->phy) {
chan->phy->vchan = NULL;
chan->phy = NULL;
}
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
if (chan->phy) {
chan->phy->vchan = NULL;
chan->phy = NULL;
}
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
for_each_sg(sgl, sg, sg_len, i) {
addr = sg_dma_address(sg);
avail = sg_dma_len(sgl);
do {
len = min_t(size_t, avail, PDMA_MAX_DESC_BYTES);
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
return &first->async_tx;
fail:
if (first)
mmp_pdma_free_desc_list(chan, &first->tx_list);
return NULL;
}
static int mmp_pdma_control(struct dma_chan *dchan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
struct mmp_pdma_chan *chan = to_mmp_pdma_chan(dchan);
struct dma_slave_config *cfg = (void *)arg;
unsigned long flags;
int ret = 0;
u32 maxburst = 0, addr = 0;
enum dma_slave_buswidth width = DMA_SLAVE_BUSWIDTH_UNDEFINED;
if (!dchan)
return -EINVAL;
switch (cmd) {
case DMA_TERMINATE_ALL:
disable_chan(chan->phy);
if (chan->phy) {
chan->phy->vchan = NULL;
chan->phy = NULL;
}
spin_lock_irqsave(&chan->desc_lock, flags);
mmp_pdma_free_desc_list(chan, &chan->chain_pending);
mmp_pdma_free_desc_list(chan, &chan->chain_running);
spin_unlock_irqrestore(&chan->desc_lock, flags);
chan->idle = true;
break;
case DMA_SLAVE_CONFIG:
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
if (cfg) {
chan->dir = cfg->direction;
chan->drcmr = cfg->slave_id;
}
chan->dev_addr = addr;
break;
default:
return -ENOSYS;
}
return ret;
}
static enum dma_status mmp_pdma_tx_status(struct dma_chan *dchan,
dma_cookie_t cookie, struct dma_tx_state *txstate)
{
struct mmp_pdma_chan *chan = to_mmp_pdma_chan(dchan);
enum dma_status ret;
unsigned long flags;
spin_lock_irqsave(&chan->desc_lock, flags);
ret = dma_cookie_status(dchan, cookie, txstate);
spin_unlock_irqrestore(&chan->desc_lock, flags);
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
spin_lock_irqsave(&chan->desc_lock, flags);
if (!list_empty(&chan->chain_running)) {
dma_cookie_t cookie;
desc = to_mmp_pdma_desc(chan->chain_running.prev);
cookie = desc->async_tx.cookie;
dma_cookie_complete(&desc->async_tx);
dev_dbg(chan->dev, "completed_cookie=%d\n", cookie);
}
list_splice_tail_init(&chan->chain_running, &chain_cleanup);
chan->idle = true;
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
static int __devexit mmp_pdma_remove(struct platform_device *op)
{
struct mmp_pdma_device *pdev = platform_get_drvdata(op);
dma_async_device_unregister(&pdev->device);
return 0;
}
static int __devinit mmp_pdma_chan_init(struct mmp_pdma_device *pdev,
int idx, int irq)
{
struct mmp_pdma_phy *phy = &pdev->phy[idx];
struct mmp_pdma_chan *chan;
int ret;
chan = devm_kzalloc(pdev->dev,
sizeof(struct mmp_pdma_chan), GFP_KERNEL);
if (chan == NULL)
return -ENOMEM;
phy->idx = idx;
phy->base = pdev->base;
if (irq) {
ret = devm_request_irq(pdev->dev, irq,
mmp_pdma_chan_handler, IRQF_DISABLED, "pdma", phy);
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
list_add_tail(&chan->chan.device_node,
&pdev->device.channels);
return 0;
}
static int __devinit mmp_pdma_probe(struct platform_device *op)
{
struct mmp_pdma_device *pdev;
const struct of_device_id *of_id;
struct mmp_dma_platdata *pdata = dev_get_platdata(&op->dev);
struct resource *iores;
int i, ret, irq = 0;
int dma_channels = 0, irq_num = 0;
pdev = devm_kzalloc(&op->dev, sizeof(*pdev), GFP_KERNEL);
if (!pdev)
return -ENOMEM;
pdev->dev = &op->dev;
iores = platform_get_resource(op, IORESOURCE_MEM, 0);
if (!iores)
return -EINVAL;
pdev->base = devm_request_and_ioremap(pdev->dev, iores);
if (!pdev->base)
return -EADDRNOTAVAIL;
of_id = of_match_device(mmp_pdma_dt_ids, pdev->dev);
if (of_id)
of_property_read_u32(pdev->dev->of_node,
"#dma-channels", &dma_channels);
else if (pdata && pdata->dma_channels)
dma_channels = pdata->dma_channels;
else
dma_channels = 32;
pdev->dma_channels = dma_channels;
for (i = 0; i < dma_channels; i++) {
if (platform_get_irq(op, i) > 0)
irq_num++;
}
pdev->phy = devm_kzalloc(pdev->dev,
dma_channels * sizeof(struct mmp_pdma_chan), GFP_KERNEL);
if (pdev->phy == NULL)
return -ENOMEM;
INIT_LIST_HEAD(&pdev->device.channels);
if (irq_num != dma_channels) {
irq = platform_get_irq(op, 0);
ret = devm_request_irq(pdev->dev, irq,
mmp_pdma_int_handler, IRQF_DISABLED, "pdma", pdev);
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
dma_cap_set(DMA_SLAVE, pdev->device.cap_mask);
pdev->device.dev = &op->dev;
pdev->device.device_alloc_chan_resources = mmp_pdma_alloc_chan_resources;
pdev->device.device_free_chan_resources = mmp_pdma_free_chan_resources;
pdev->device.device_tx_status = mmp_pdma_tx_status;
pdev->device.device_prep_dma_memcpy = mmp_pdma_prep_memcpy;
pdev->device.device_prep_slave_sg = mmp_pdma_prep_slave_sg;
pdev->device.device_issue_pending = mmp_pdma_issue_pending;
pdev->device.device_control = mmp_pdma_control;
pdev->device.copy_align = PDMA_ALIGNMENT;
if (pdev->dev->coherent_dma_mask)
dma_set_mask(pdev->dev, pdev->dev->coherent_dma_mask);
else
dma_set_mask(pdev->dev, DMA_BIT_MASK(64));
ret = dma_async_device_register(&pdev->device);
if (ret) {
dev_err(pdev->device.dev, "unable to register\n");
return ret;
}
dev_info(pdev->device.dev, "initialized\n");
return 0;
}
