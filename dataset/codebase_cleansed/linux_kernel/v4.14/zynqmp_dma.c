static inline void zynqmp_dma_writeq(struct zynqmp_dma_chan *chan, u32 reg,
u64 value)
{
lo_hi_writeq(value, chan->regs + reg);
}
static void zynqmp_dma_update_desc_to_ctrlr(struct zynqmp_dma_chan *chan,
struct zynqmp_dma_desc_sw *desc)
{
dma_addr_t addr;
addr = desc->src_p;
zynqmp_dma_writeq(chan, ZYNQMP_DMA_SRC_START_LSB, addr);
addr = desc->dst_p;
zynqmp_dma_writeq(chan, ZYNQMP_DMA_DST_START_LSB, addr);
}
static void zynqmp_dma_desc_config_eod(struct zynqmp_dma_chan *chan,
void *desc)
{
struct zynqmp_dma_desc_ll *hw = (struct zynqmp_dma_desc_ll *)desc;
hw->ctrl |= ZYNQMP_DMA_DESC_CTRL_STOP;
hw++;
hw->ctrl |= ZYNQMP_DMA_DESC_CTRL_COMP_INT | ZYNQMP_DMA_DESC_CTRL_STOP;
}
static void zynqmp_dma_config_sg_ll_desc(struct zynqmp_dma_chan *chan,
struct zynqmp_dma_desc_ll *sdesc,
dma_addr_t src, dma_addr_t dst, size_t len,
struct zynqmp_dma_desc_ll *prev)
{
struct zynqmp_dma_desc_ll *ddesc = sdesc + 1;
sdesc->size = ddesc->size = len;
sdesc->addr = src;
ddesc->addr = dst;
sdesc->ctrl = ddesc->ctrl = ZYNQMP_DMA_DESC_CTRL_SIZE_256;
if (chan->is_dmacoherent) {
sdesc->ctrl |= ZYNQMP_DMA_DESC_CTRL_COHRNT;
ddesc->ctrl |= ZYNQMP_DMA_DESC_CTRL_COHRNT;
}
if (prev) {
dma_addr_t addr = chan->desc_pool_p +
((uintptr_t)sdesc - (uintptr_t)chan->desc_pool_v);
ddesc = prev + 1;
prev->nxtdscraddr = addr;
ddesc->nxtdscraddr = addr + ZYNQMP_DMA_DESC_SIZE(chan);
}
}
static void zynqmp_dma_init(struct zynqmp_dma_chan *chan)
{
u32 val;
writel(ZYNQMP_DMA_IDS_DEFAULT_MASK, chan->regs + ZYNQMP_DMA_IDS);
val = readl(chan->regs + ZYNQMP_DMA_ISR);
writel(val, chan->regs + ZYNQMP_DMA_ISR);
if (chan->is_dmacoherent) {
val = ZYNQMP_DMA_AXCOHRNT;
val = (val & ~ZYNQMP_DMA_AXCACHE) |
(ZYNQMP_DMA_AXCACHE_VAL << ZYNQMP_DMA_AXCACHE_OFST);
writel(val, chan->regs + ZYNQMP_DMA_DSCR_ATTR);
}
val = readl(chan->regs + ZYNQMP_DMA_DATA_ATTR);
if (chan->is_dmacoherent) {
val = (val & ~ZYNQMP_DMA_ARCACHE) |
(ZYNQMP_DMA_AXCACHE_VAL << ZYNQMP_DMA_ARCACHE_OFST);
val = (val & ~ZYNQMP_DMA_AWCACHE) |
(ZYNQMP_DMA_AXCACHE_VAL << ZYNQMP_DMA_AWCACHE_OFST);
}
writel(val, chan->regs + ZYNQMP_DMA_DATA_ATTR);
val = readl(chan->regs + ZYNQMP_DMA_IRQ_SRC_ACCT);
val = readl(chan->regs + ZYNQMP_DMA_IRQ_DST_ACCT);
chan->idle = true;
}
static dma_cookie_t zynqmp_dma_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct zynqmp_dma_chan *chan = to_chan(tx->chan);
struct zynqmp_dma_desc_sw *desc, *new;
dma_cookie_t cookie;
new = tx_to_desc(tx);
spin_lock_bh(&chan->lock);
cookie = dma_cookie_assign(tx);
if (!list_empty(&chan->pending_list)) {
desc = list_last_entry(&chan->pending_list,
struct zynqmp_dma_desc_sw, node);
if (!list_empty(&desc->tx_list))
desc = list_last_entry(&desc->tx_list,
struct zynqmp_dma_desc_sw, node);
desc->src_v->nxtdscraddr = new->src_p;
desc->src_v->ctrl &= ~ZYNQMP_DMA_DESC_CTRL_STOP;
desc->dst_v->nxtdscraddr = new->dst_p;
desc->dst_v->ctrl &= ~ZYNQMP_DMA_DESC_CTRL_STOP;
}
list_add_tail(&new->node, &chan->pending_list);
spin_unlock_bh(&chan->lock);
return cookie;
}
static struct zynqmp_dma_desc_sw *
zynqmp_dma_get_descriptor(struct zynqmp_dma_chan *chan)
{
struct zynqmp_dma_desc_sw *desc;
spin_lock_bh(&chan->lock);
desc = list_first_entry(&chan->free_list,
struct zynqmp_dma_desc_sw, node);
list_del(&desc->node);
spin_unlock_bh(&chan->lock);
INIT_LIST_HEAD(&desc->tx_list);
memset((void *)desc->src_v, 0, ZYNQMP_DMA_DESC_SIZE(chan));
memset((void *)desc->dst_v, 0, ZYNQMP_DMA_DESC_SIZE(chan));
return desc;
}
static void zynqmp_dma_free_descriptor(struct zynqmp_dma_chan *chan,
struct zynqmp_dma_desc_sw *sdesc)
{
struct zynqmp_dma_desc_sw *child, *next;
chan->desc_free_cnt++;
list_add_tail(&sdesc->node, &chan->free_list);
list_for_each_entry_safe(child, next, &sdesc->tx_list, node) {
chan->desc_free_cnt++;
list_move_tail(&child->node, &chan->free_list);
}
}
static void zynqmp_dma_free_desc_list(struct zynqmp_dma_chan *chan,
struct list_head *list)
{
struct zynqmp_dma_desc_sw *desc, *next;
list_for_each_entry_safe(desc, next, list, node)
zynqmp_dma_free_descriptor(chan, desc);
}
static int zynqmp_dma_alloc_chan_resources(struct dma_chan *dchan)
{
struct zynqmp_dma_chan *chan = to_chan(dchan);
struct zynqmp_dma_desc_sw *desc;
int i;
chan->sw_desc_pool = kzalloc(sizeof(*desc) * ZYNQMP_DMA_NUM_DESCS,
GFP_KERNEL);
if (!chan->sw_desc_pool)
return -ENOMEM;
chan->idle = true;
chan->desc_free_cnt = ZYNQMP_DMA_NUM_DESCS;
INIT_LIST_HEAD(&chan->free_list);
for (i = 0; i < ZYNQMP_DMA_NUM_DESCS; i++) {
desc = chan->sw_desc_pool + i;
dma_async_tx_descriptor_init(&desc->async_tx, &chan->common);
desc->async_tx.tx_submit = zynqmp_dma_tx_submit;
list_add_tail(&desc->node, &chan->free_list);
}
chan->desc_pool_v = dma_zalloc_coherent(chan->dev,
(2 * chan->desc_size * ZYNQMP_DMA_NUM_DESCS),
&chan->desc_pool_p, GFP_KERNEL);
if (!chan->desc_pool_v)
return -ENOMEM;
for (i = 0; i < ZYNQMP_DMA_NUM_DESCS; i++) {
desc = chan->sw_desc_pool + i;
desc->src_v = (struct zynqmp_dma_desc_ll *) (chan->desc_pool_v +
(i * ZYNQMP_DMA_DESC_SIZE(chan) * 2));
desc->dst_v = (struct zynqmp_dma_desc_ll *) (desc->src_v + 1);
desc->src_p = chan->desc_pool_p +
(i * ZYNQMP_DMA_DESC_SIZE(chan) * 2);
desc->dst_p = desc->src_p + ZYNQMP_DMA_DESC_SIZE(chan);
}
return ZYNQMP_DMA_NUM_DESCS;
}
static void zynqmp_dma_start(struct zynqmp_dma_chan *chan)
{
writel(ZYNQMP_DMA_INT_EN_DEFAULT_MASK, chan->regs + ZYNQMP_DMA_IER);
chan->idle = false;
writel(ZYNQMP_DMA_ENABLE, chan->regs + ZYNQMP_DMA_CTRL2);
}
static void zynqmp_dma_handle_ovfl_int(struct zynqmp_dma_chan *chan, u32 status)
{
u32 val;
if (status & ZYNQMP_DMA_IRQ_DST_ACCT_ERR)
val = readl(chan->regs + ZYNQMP_DMA_IRQ_DST_ACCT);
if (status & ZYNQMP_DMA_IRQ_SRC_ACCT_ERR)
val = readl(chan->regs + ZYNQMP_DMA_IRQ_SRC_ACCT);
}
static void zynqmp_dma_config(struct zynqmp_dma_chan *chan)
{
u32 val;
val = readl(chan->regs + ZYNQMP_DMA_CTRL0);
val |= ZYNQMP_DMA_POINT_TYPE_SG;
writel(val, chan->regs + ZYNQMP_DMA_CTRL0);
val = readl(chan->regs + ZYNQMP_DMA_DATA_ATTR);
val = (val & ~ZYNQMP_DMA_ARLEN) |
(chan->src_burst_len << ZYNQMP_DMA_ARLEN_OFST);
val = (val & ~ZYNQMP_DMA_AWLEN) |
(chan->dst_burst_len << ZYNQMP_DMA_AWLEN_OFST);
writel(val, chan->regs + ZYNQMP_DMA_DATA_ATTR);
}
static int zynqmp_dma_device_config(struct dma_chan *dchan,
struct dma_slave_config *config)
{
struct zynqmp_dma_chan *chan = to_chan(dchan);
chan->src_burst_len = config->src_maxburst;
chan->dst_burst_len = config->dst_maxburst;
return 0;
}
static void zynqmp_dma_start_transfer(struct zynqmp_dma_chan *chan)
{
struct zynqmp_dma_desc_sw *desc;
if (!chan->idle)
return;
zynqmp_dma_config(chan);
desc = list_first_entry_or_null(&chan->pending_list,
struct zynqmp_dma_desc_sw, node);
if (!desc)
return;
list_splice_tail_init(&chan->pending_list, &chan->active_list);
zynqmp_dma_update_desc_to_ctrlr(chan, desc);
zynqmp_dma_start(chan);
}
static void zynqmp_dma_chan_desc_cleanup(struct zynqmp_dma_chan *chan)
{
struct zynqmp_dma_desc_sw *desc, *next;
list_for_each_entry_safe(desc, next, &chan->done_list, node) {
dma_async_tx_callback callback;
void *callback_param;
list_del(&desc->node);
callback = desc->async_tx.callback;
callback_param = desc->async_tx.callback_param;
if (callback) {
spin_unlock(&chan->lock);
callback(callback_param);
spin_lock(&chan->lock);
}
zynqmp_dma_free_descriptor(chan, desc);
}
}
static void zynqmp_dma_complete_descriptor(struct zynqmp_dma_chan *chan)
{
struct zynqmp_dma_desc_sw *desc;
desc = list_first_entry_or_null(&chan->active_list,
struct zynqmp_dma_desc_sw, node);
if (!desc)
return;
list_del(&desc->node);
dma_cookie_complete(&desc->async_tx);
list_add_tail(&desc->node, &chan->done_list);
}
static void zynqmp_dma_issue_pending(struct dma_chan *dchan)
{
struct zynqmp_dma_chan *chan = to_chan(dchan);
spin_lock_bh(&chan->lock);
zynqmp_dma_start_transfer(chan);
spin_unlock_bh(&chan->lock);
}
static void zynqmp_dma_free_descriptors(struct zynqmp_dma_chan *chan)
{
zynqmp_dma_free_desc_list(chan, &chan->active_list);
zynqmp_dma_free_desc_list(chan, &chan->pending_list);
zynqmp_dma_free_desc_list(chan, &chan->done_list);
}
static void zynqmp_dma_free_chan_resources(struct dma_chan *dchan)
{
struct zynqmp_dma_chan *chan = to_chan(dchan);
spin_lock_bh(&chan->lock);
zynqmp_dma_free_descriptors(chan);
spin_unlock_bh(&chan->lock);
dma_free_coherent(chan->dev,
(2 * ZYNQMP_DMA_DESC_SIZE(chan) * ZYNQMP_DMA_NUM_DESCS),
chan->desc_pool_v, chan->desc_pool_p);
kfree(chan->sw_desc_pool);
}
static void zynqmp_dma_reset(struct zynqmp_dma_chan *chan)
{
writel(ZYNQMP_DMA_IDS_DEFAULT_MASK, chan->regs + ZYNQMP_DMA_IDS);
zynqmp_dma_complete_descriptor(chan);
zynqmp_dma_chan_desc_cleanup(chan);
zynqmp_dma_free_descriptors(chan);
zynqmp_dma_init(chan);
}
static irqreturn_t zynqmp_dma_irq_handler(int irq, void *data)
{
struct zynqmp_dma_chan *chan = (struct zynqmp_dma_chan *)data;
u32 isr, imr, status;
irqreturn_t ret = IRQ_NONE;
isr = readl(chan->regs + ZYNQMP_DMA_ISR);
imr = readl(chan->regs + ZYNQMP_DMA_IMR);
status = isr & ~imr;
writel(isr, chan->regs + ZYNQMP_DMA_ISR);
if (status & ZYNQMP_DMA_INT_DONE) {
tasklet_schedule(&chan->tasklet);
ret = IRQ_HANDLED;
}
if (status & ZYNQMP_DMA_DONE)
chan->idle = true;
if (status & ZYNQMP_DMA_INT_ERR) {
chan->err = true;
tasklet_schedule(&chan->tasklet);
dev_err(chan->dev, "Channel %p has errors\n", chan);
ret = IRQ_HANDLED;
}
if (status & ZYNQMP_DMA_INT_OVRFL) {
zynqmp_dma_handle_ovfl_int(chan, status);
dev_info(chan->dev, "Channel %p overflow interrupt\n", chan);
ret = IRQ_HANDLED;
}
return ret;
}
static void zynqmp_dma_do_tasklet(unsigned long data)
{
struct zynqmp_dma_chan *chan = (struct zynqmp_dma_chan *)data;
u32 count;
spin_lock(&chan->lock);
if (chan->err) {
zynqmp_dma_reset(chan);
chan->err = false;
goto unlock;
}
count = readl(chan->regs + ZYNQMP_DMA_IRQ_DST_ACCT);
while (count) {
zynqmp_dma_complete_descriptor(chan);
zynqmp_dma_chan_desc_cleanup(chan);
count--;
}
if (chan->idle)
zynqmp_dma_start_transfer(chan);
unlock:
spin_unlock(&chan->lock);
}
static int zynqmp_dma_device_terminate_all(struct dma_chan *dchan)
{
struct zynqmp_dma_chan *chan = to_chan(dchan);
spin_lock_bh(&chan->lock);
writel(ZYNQMP_DMA_IDS_DEFAULT_MASK, chan->regs + ZYNQMP_DMA_IDS);
zynqmp_dma_free_descriptors(chan);
spin_unlock_bh(&chan->lock);
return 0;
}
static struct dma_async_tx_descriptor *zynqmp_dma_prep_memcpy(
struct dma_chan *dchan, dma_addr_t dma_dst,
dma_addr_t dma_src, size_t len, ulong flags)
{
struct zynqmp_dma_chan *chan;
struct zynqmp_dma_desc_sw *new, *first = NULL;
void *desc = NULL, *prev = NULL;
size_t copy;
u32 desc_cnt;
chan = to_chan(dchan);
desc_cnt = DIV_ROUND_UP(len, ZYNQMP_DMA_MAX_TRANS_LEN);
spin_lock_bh(&chan->lock);
if (desc_cnt > chan->desc_free_cnt) {
spin_unlock_bh(&chan->lock);
dev_dbg(chan->dev, "chan %p descs are not available\n", chan);
return NULL;
}
chan->desc_free_cnt = chan->desc_free_cnt - desc_cnt;
spin_unlock_bh(&chan->lock);
do {
new = zynqmp_dma_get_descriptor(chan);
copy = min_t(size_t, len, ZYNQMP_DMA_MAX_TRANS_LEN);
desc = (struct zynqmp_dma_desc_ll *)new->src_v;
zynqmp_dma_config_sg_ll_desc(chan, desc, dma_src,
dma_dst, copy, prev);
prev = desc;
len -= copy;
dma_src += copy;
dma_dst += copy;
if (!first)
first = new;
else
list_add_tail(&new->node, &first->tx_list);
} while (len);
zynqmp_dma_desc_config_eod(chan, desc);
async_tx_ack(&first->async_tx);
first->async_tx.flags = flags;
return &first->async_tx;
}
static void zynqmp_dma_chan_remove(struct zynqmp_dma_chan *chan)
{
if (!chan)
return;
devm_free_irq(chan->zdev->dev, chan->irq, chan);
tasklet_kill(&chan->tasklet);
list_del(&chan->common.device_node);
clk_disable_unprepare(chan->clk_apb);
clk_disable_unprepare(chan->clk_main);
}
static int zynqmp_dma_chan_probe(struct zynqmp_dma_device *zdev,
struct platform_device *pdev)
{
struct zynqmp_dma_chan *chan;
struct resource *res;
struct device_node *node = pdev->dev.of_node;
int err;
chan = devm_kzalloc(zdev->dev, sizeof(*chan), GFP_KERNEL);
if (!chan)
return -ENOMEM;
chan->dev = zdev->dev;
chan->zdev = zdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
chan->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(chan->regs))
return PTR_ERR(chan->regs);
chan->bus_width = ZYNQMP_DMA_BUS_WIDTH_64;
chan->dst_burst_len = ZYNQMP_DMA_AWLEN_RST_VAL;
chan->src_burst_len = ZYNQMP_DMA_ARLEN_RST_VAL;
err = of_property_read_u32(node, "xlnx,bus-width", &chan->bus_width);
if (err < 0) {
dev_err(&pdev->dev, "missing xlnx,bus-width property\n");
return err;
}
if (chan->bus_width != ZYNQMP_DMA_BUS_WIDTH_64 &&
chan->bus_width != ZYNQMP_DMA_BUS_WIDTH_128) {
dev_err(zdev->dev, "invalid bus-width value");
return -EINVAL;
}
chan->is_dmacoherent = of_property_read_bool(node, "dma-coherent");
zdev->chan = chan;
tasklet_init(&chan->tasklet, zynqmp_dma_do_tasklet, (ulong)chan);
spin_lock_init(&chan->lock);
INIT_LIST_HEAD(&chan->active_list);
INIT_LIST_HEAD(&chan->pending_list);
INIT_LIST_HEAD(&chan->done_list);
INIT_LIST_HEAD(&chan->free_list);
dma_cookie_init(&chan->common);
chan->common.device = &zdev->common;
list_add_tail(&chan->common.device_node, &zdev->common.channels);
zynqmp_dma_init(chan);
chan->irq = platform_get_irq(pdev, 0);
if (chan->irq < 0)
return -ENXIO;
err = devm_request_irq(&pdev->dev, chan->irq, zynqmp_dma_irq_handler, 0,
"zynqmp-dma", chan);
if (err)
return err;
chan->clk_main = devm_clk_get(&pdev->dev, "clk_main");
if (IS_ERR(chan->clk_main)) {
dev_err(&pdev->dev, "main clock not found.\n");
return PTR_ERR(chan->clk_main);
}
chan->clk_apb = devm_clk_get(&pdev->dev, "clk_apb");
if (IS_ERR(chan->clk_apb)) {
dev_err(&pdev->dev, "apb clock not found.\n");
return PTR_ERR(chan->clk_apb);
}
err = clk_prepare_enable(chan->clk_main);
if (err) {
dev_err(&pdev->dev, "Unable to enable main clock.\n");
return err;
}
err = clk_prepare_enable(chan->clk_apb);
if (err) {
clk_disable_unprepare(chan->clk_main);
dev_err(&pdev->dev, "Unable to enable apb clock.\n");
return err;
}
chan->desc_size = sizeof(struct zynqmp_dma_desc_ll);
chan->idle = true;
return 0;
}
static struct dma_chan *of_zynqmp_dma_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct zynqmp_dma_device *zdev = ofdma->of_dma_data;
return dma_get_slave_channel(&zdev->chan->common);
}
static int zynqmp_dma_probe(struct platform_device *pdev)
{
struct zynqmp_dma_device *zdev;
struct dma_device *p;
int ret;
zdev = devm_kzalloc(&pdev->dev, sizeof(*zdev), GFP_KERNEL);
if (!zdev)
return -ENOMEM;
zdev->dev = &pdev->dev;
INIT_LIST_HEAD(&zdev->common.channels);
dma_set_mask(&pdev->dev, DMA_BIT_MASK(44));
dma_cap_set(DMA_MEMCPY, zdev->common.cap_mask);
p = &zdev->common;
p->device_prep_dma_memcpy = zynqmp_dma_prep_memcpy;
p->device_terminate_all = zynqmp_dma_device_terminate_all;
p->device_issue_pending = zynqmp_dma_issue_pending;
p->device_alloc_chan_resources = zynqmp_dma_alloc_chan_resources;
p->device_free_chan_resources = zynqmp_dma_free_chan_resources;
p->device_tx_status = dma_cookie_status;
p->device_config = zynqmp_dma_device_config;
p->dev = &pdev->dev;
platform_set_drvdata(pdev, zdev);
ret = zynqmp_dma_chan_probe(zdev, pdev);
if (ret) {
dev_err(&pdev->dev, "Probing channel failed\n");
goto free_chan_resources;
}
p->dst_addr_widths = BIT(zdev->chan->bus_width / 8);
p->src_addr_widths = BIT(zdev->chan->bus_width / 8);
dma_async_device_register(&zdev->common);
ret = of_dma_controller_register(pdev->dev.of_node,
of_zynqmp_dma_xlate, zdev);
if (ret) {
dev_err(&pdev->dev, "Unable to register DMA to DT\n");
dma_async_device_unregister(&zdev->common);
goto free_chan_resources;
}
dev_info(&pdev->dev, "ZynqMP DMA driver Probe success\n");
return 0;
free_chan_resources:
zynqmp_dma_chan_remove(zdev->chan);
return ret;
}
static int zynqmp_dma_remove(struct platform_device *pdev)
{
struct zynqmp_dma_device *zdev = platform_get_drvdata(pdev);
of_dma_controller_free(pdev->dev.of_node);
dma_async_device_unregister(&zdev->common);
zynqmp_dma_chan_remove(zdev->chan);
return 0;
}
