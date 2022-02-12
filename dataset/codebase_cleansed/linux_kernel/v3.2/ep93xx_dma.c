static inline struct device *chan2dev(struct ep93xx_dma_chan *edmac)
{
return &edmac->chan.dev->device;
}
static struct ep93xx_dma_chan *to_ep93xx_dma_chan(struct dma_chan *chan)
{
return container_of(chan, struct ep93xx_dma_chan, chan);
}
static void ep93xx_dma_set_active(struct ep93xx_dma_chan *edmac,
struct ep93xx_dma_desc *desc)
{
BUG_ON(!list_empty(&edmac->active));
list_add_tail(&desc->node, &edmac->active);
while (!list_empty(&desc->tx_list)) {
struct ep93xx_dma_desc *d = list_first_entry(&desc->tx_list,
struct ep93xx_dma_desc, node);
d->txd.callback = desc->txd.callback;
d->txd.callback_param = desc->txd.callback_param;
list_move_tail(&d->node, &edmac->active);
}
}
static struct ep93xx_dma_desc *
ep93xx_dma_get_active(struct ep93xx_dma_chan *edmac)
{
return list_first_entry(&edmac->active, struct ep93xx_dma_desc, node);
}
static bool ep93xx_dma_advance_active(struct ep93xx_dma_chan *edmac)
{
list_rotate_left(&edmac->active);
if (test_bit(EP93XX_DMA_IS_CYCLIC, &edmac->flags))
return true;
return !ep93xx_dma_get_active(edmac)->txd.cookie;
}
static void m2p_set_control(struct ep93xx_dma_chan *edmac, u32 control)
{
writel(control, edmac->regs + M2P_CONTROL);
readl(edmac->regs + M2P_CONTROL);
}
static int m2p_hw_setup(struct ep93xx_dma_chan *edmac)
{
struct ep93xx_dma_data *data = edmac->chan.private;
u32 control;
writel(data->port & 0xf, edmac->regs + M2P_PPALLOC);
control = M2P_CONTROL_CH_ERROR_INT | M2P_CONTROL_ICE
| M2P_CONTROL_ENABLE;
m2p_set_control(edmac, control);
return 0;
}
static inline u32 m2p_channel_state(struct ep93xx_dma_chan *edmac)
{
return (readl(edmac->regs + M2P_STATUS) >> 4) & 0x3;
}
static void m2p_hw_shutdown(struct ep93xx_dma_chan *edmac)
{
u32 control;
control = readl(edmac->regs + M2P_CONTROL);
control &= ~(M2P_CONTROL_STALLINT | M2P_CONTROL_NFBINT);
m2p_set_control(edmac, control);
while (m2p_channel_state(edmac) >= M2P_STATE_ON)
cpu_relax();
m2p_set_control(edmac, 0);
while (m2p_channel_state(edmac) == M2P_STATE_STALL)
cpu_relax();
}
static void m2p_fill_desc(struct ep93xx_dma_chan *edmac)
{
struct ep93xx_dma_desc *desc = ep93xx_dma_get_active(edmac);
u32 bus_addr;
if (ep93xx_dma_chan_direction(&edmac->chan) == DMA_TO_DEVICE)
bus_addr = desc->src_addr;
else
bus_addr = desc->dst_addr;
if (edmac->buffer == 0) {
writel(desc->size, edmac->regs + M2P_MAXCNT0);
writel(bus_addr, edmac->regs + M2P_BASE0);
} else {
writel(desc->size, edmac->regs + M2P_MAXCNT1);
writel(bus_addr, edmac->regs + M2P_BASE1);
}
edmac->buffer ^= 1;
}
static void m2p_hw_submit(struct ep93xx_dma_chan *edmac)
{
u32 control = readl(edmac->regs + M2P_CONTROL);
m2p_fill_desc(edmac);
control |= M2P_CONTROL_STALLINT;
if (ep93xx_dma_advance_active(edmac)) {
m2p_fill_desc(edmac);
control |= M2P_CONTROL_NFBINT;
}
m2p_set_control(edmac, control);
}
static int m2p_hw_interrupt(struct ep93xx_dma_chan *edmac)
{
u32 irq_status = readl(edmac->regs + M2P_INTERRUPT);
u32 control;
if (irq_status & M2P_INTERRUPT_ERROR) {
struct ep93xx_dma_desc *desc = ep93xx_dma_get_active(edmac);
writel(1, edmac->regs + M2P_INTERRUPT);
dev_err(chan2dev(edmac),
"DMA transfer failed! Details:\n"
"\tcookie : %d\n"
"\tsrc_addr : 0x%08x\n"
"\tdst_addr : 0x%08x\n"
"\tsize : %zu\n",
desc->txd.cookie, desc->src_addr, desc->dst_addr,
desc->size);
}
switch (irq_status & (M2P_INTERRUPT_STALL | M2P_INTERRUPT_NFB)) {
case M2P_INTERRUPT_STALL:
control = readl(edmac->regs + M2P_CONTROL);
control &= ~(M2P_CONTROL_STALLINT | M2P_CONTROL_NFBINT);
m2p_set_control(edmac, control);
return INTERRUPT_DONE;
case M2P_INTERRUPT_NFB:
if (ep93xx_dma_advance_active(edmac))
m2p_fill_desc(edmac);
return INTERRUPT_NEXT_BUFFER;
}
return INTERRUPT_UNKNOWN;
}
static int m2m_hw_setup(struct ep93xx_dma_chan *edmac)
{
const struct ep93xx_dma_data *data = edmac->chan.private;
u32 control = 0;
if (!data) {
writel(control, edmac->regs + M2M_CONTROL);
return 0;
}
switch (data->port) {
case EP93XX_DMA_SSP:
control = (5 << M2M_CONTROL_PWSC_SHIFT);
control |= M2M_CONTROL_NO_HDSK;
if (data->direction == DMA_TO_DEVICE) {
control |= M2M_CONTROL_DAH;
control |= M2M_CONTROL_TM_TX;
control |= M2M_CONTROL_RSS_SSPTX;
} else {
control |= M2M_CONTROL_SAH;
control |= M2M_CONTROL_TM_RX;
control |= M2M_CONTROL_RSS_SSPRX;
}
break;
case EP93XX_DMA_IDE:
control |= M2M_CONTROL_NO_HDSK;
control |= M2M_CONTROL_RSS_IDE;
control |= M2M_CONTROL_PW_16;
if (data->direction == DMA_TO_DEVICE) {
control = (3 << M2M_CONTROL_PWSC_SHIFT);
control |= M2M_CONTROL_DAH;
control |= M2M_CONTROL_TM_TX;
} else {
control = (2 << M2M_CONTROL_PWSC_SHIFT);
control |= M2M_CONTROL_SAH;
control |= M2M_CONTROL_TM_RX;
}
break;
default:
return -EINVAL;
}
writel(control, edmac->regs + M2M_CONTROL);
return 0;
}
static void m2m_hw_shutdown(struct ep93xx_dma_chan *edmac)
{
writel(0, edmac->regs + M2M_CONTROL);
}
static void m2m_fill_desc(struct ep93xx_dma_chan *edmac)
{
struct ep93xx_dma_desc *desc = ep93xx_dma_get_active(edmac);
if (edmac->buffer == 0) {
writel(desc->src_addr, edmac->regs + M2M_SAR_BASE0);
writel(desc->dst_addr, edmac->regs + M2M_DAR_BASE0);
writel(desc->size, edmac->regs + M2M_BCR0);
} else {
writel(desc->src_addr, edmac->regs + M2M_SAR_BASE1);
writel(desc->dst_addr, edmac->regs + M2M_DAR_BASE1);
writel(desc->size, edmac->regs + M2M_BCR1);
}
edmac->buffer ^= 1;
}
static void m2m_hw_submit(struct ep93xx_dma_chan *edmac)
{
struct ep93xx_dma_data *data = edmac->chan.private;
u32 control = readl(edmac->regs + M2M_CONTROL);
control &= ~M2M_CONTROL_PW_MASK;
control |= edmac->runtime_ctrl;
m2m_fill_desc(edmac);
control |= M2M_CONTROL_DONEINT;
control |= M2M_CONTROL_ENABLE;
writel(control, edmac->regs + M2M_CONTROL);
if (!data) {
control |= M2M_CONTROL_START;
writel(control, edmac->regs + M2M_CONTROL);
}
}
static int m2m_hw_interrupt(struct ep93xx_dma_chan *edmac)
{
u32 control;
if (!(readl(edmac->regs + M2M_INTERRUPT) & M2M_INTERRUPT_DONEINT))
return INTERRUPT_UNKNOWN;
writel(0, edmac->regs + M2M_INTERRUPT);
control = readl(edmac->regs + M2M_CONTROL);
control &= ~(M2M_CONTROL_DONEINT | M2M_CONTROL_ENABLE);
writel(control, edmac->regs + M2M_CONTROL);
if (ep93xx_dma_advance_active(edmac)) {
edmac->edma->hw_submit(edmac);
return INTERRUPT_NEXT_BUFFER;
}
return INTERRUPT_DONE;
}
static struct ep93xx_dma_desc *
ep93xx_dma_desc_get(struct ep93xx_dma_chan *edmac)
{
struct ep93xx_dma_desc *desc, *_desc;
struct ep93xx_dma_desc *ret = NULL;
unsigned long flags;
spin_lock_irqsave(&edmac->lock, flags);
list_for_each_entry_safe(desc, _desc, &edmac->free_list, node) {
if (async_tx_test_ack(&desc->txd)) {
list_del_init(&desc->node);
desc->src_addr = 0;
desc->dst_addr = 0;
desc->size = 0;
desc->complete = false;
desc->txd.cookie = 0;
desc->txd.callback = NULL;
desc->txd.callback_param = NULL;
ret = desc;
break;
}
}
spin_unlock_irqrestore(&edmac->lock, flags);
return ret;
}
static void ep93xx_dma_desc_put(struct ep93xx_dma_chan *edmac,
struct ep93xx_dma_desc *desc)
{
if (desc) {
unsigned long flags;
spin_lock_irqsave(&edmac->lock, flags);
list_splice_init(&desc->tx_list, &edmac->free_list);
list_add(&desc->node, &edmac->free_list);
spin_unlock_irqrestore(&edmac->lock, flags);
}
}
static void ep93xx_dma_advance_work(struct ep93xx_dma_chan *edmac)
{
struct ep93xx_dma_desc *new;
unsigned long flags;
spin_lock_irqsave(&edmac->lock, flags);
if (!list_empty(&edmac->active) || list_empty(&edmac->queue)) {
spin_unlock_irqrestore(&edmac->lock, flags);
return;
}
new = list_first_entry(&edmac->queue, struct ep93xx_dma_desc, node);
list_del_init(&new->node);
ep93xx_dma_set_active(edmac, new);
edmac->edma->hw_submit(edmac);
spin_unlock_irqrestore(&edmac->lock, flags);
}
static void ep93xx_dma_unmap_buffers(struct ep93xx_dma_desc *desc)
{
struct device *dev = desc->txd.chan->device->dev;
if (!(desc->txd.flags & DMA_COMPL_SKIP_SRC_UNMAP)) {
if (desc->txd.flags & DMA_COMPL_SRC_UNMAP_SINGLE)
dma_unmap_single(dev, desc->src_addr, desc->size,
DMA_TO_DEVICE);
else
dma_unmap_page(dev, desc->src_addr, desc->size,
DMA_TO_DEVICE);
}
if (!(desc->txd.flags & DMA_COMPL_SKIP_DEST_UNMAP)) {
if (desc->txd.flags & DMA_COMPL_DEST_UNMAP_SINGLE)
dma_unmap_single(dev, desc->dst_addr, desc->size,
DMA_FROM_DEVICE);
else
dma_unmap_page(dev, desc->dst_addr, desc->size,
DMA_FROM_DEVICE);
}
}
static void ep93xx_dma_tasklet(unsigned long data)
{
struct ep93xx_dma_chan *edmac = (struct ep93xx_dma_chan *)data;
struct ep93xx_dma_desc *desc, *d;
dma_async_tx_callback callback;
void *callback_param;
LIST_HEAD(list);
spin_lock_irq(&edmac->lock);
desc = ep93xx_dma_get_active(edmac);
if (desc->complete) {
edmac->last_completed = desc->txd.cookie;
list_splice_init(&edmac->active, &list);
}
spin_unlock_irq(&edmac->lock);
ep93xx_dma_advance_work(edmac);
callback = desc->txd.callback;
callback_param = desc->txd.callback_param;
list_for_each_entry_safe(desc, d, &list, node) {
if (!edmac->chan.private)
ep93xx_dma_unmap_buffers(desc);
ep93xx_dma_desc_put(edmac, desc);
}
if (callback)
callback(callback_param);
}
static irqreturn_t ep93xx_dma_interrupt(int irq, void *dev_id)
{
struct ep93xx_dma_chan *edmac = dev_id;
irqreturn_t ret = IRQ_HANDLED;
spin_lock(&edmac->lock);
switch (edmac->edma->hw_interrupt(edmac)) {
case INTERRUPT_DONE:
ep93xx_dma_get_active(edmac)->complete = true;
tasklet_schedule(&edmac->tasklet);
break;
case INTERRUPT_NEXT_BUFFER:
if (test_bit(EP93XX_DMA_IS_CYCLIC, &edmac->flags))
tasklet_schedule(&edmac->tasklet);
break;
default:
dev_warn(chan2dev(edmac), "unknown interrupt!\n");
ret = IRQ_NONE;
break;
}
spin_unlock(&edmac->lock);
return ret;
}
static dma_cookie_t ep93xx_dma_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct ep93xx_dma_chan *edmac = to_ep93xx_dma_chan(tx->chan);
struct ep93xx_dma_desc *desc;
dma_cookie_t cookie;
unsigned long flags;
spin_lock_irqsave(&edmac->lock, flags);
cookie = edmac->chan.cookie;
if (++cookie < 0)
cookie = 1;
desc = container_of(tx, struct ep93xx_dma_desc, txd);
edmac->chan.cookie = cookie;
desc->txd.cookie = cookie;
if (list_empty(&edmac->active)) {
ep93xx_dma_set_active(edmac, desc);
edmac->edma->hw_submit(edmac);
} else {
list_add_tail(&desc->node, &edmac->queue);
}
spin_unlock_irqrestore(&edmac->lock, flags);
return cookie;
}
static int ep93xx_dma_alloc_chan_resources(struct dma_chan *chan)
{
struct ep93xx_dma_chan *edmac = to_ep93xx_dma_chan(chan);
struct ep93xx_dma_data *data = chan->private;
const char *name = dma_chan_name(chan);
int ret, i;
if (!edmac->edma->m2m) {
if (!data)
return -EINVAL;
if (data->port < EP93XX_DMA_I2S1 ||
data->port > EP93XX_DMA_IRDA)
return -EINVAL;
if (data->direction != ep93xx_dma_chan_direction(chan))
return -EINVAL;
} else {
if (data) {
switch (data->port) {
case EP93XX_DMA_SSP:
case EP93XX_DMA_IDE:
if (data->direction != DMA_TO_DEVICE &&
data->direction != DMA_FROM_DEVICE)
return -EINVAL;
break;
default:
return -EINVAL;
}
}
}
if (data && data->name)
name = data->name;
ret = clk_enable(edmac->clk);
if (ret)
return ret;
ret = request_irq(edmac->irq, ep93xx_dma_interrupt, 0, name, edmac);
if (ret)
goto fail_clk_disable;
spin_lock_irq(&edmac->lock);
edmac->last_completed = 1;
edmac->chan.cookie = 1;
ret = edmac->edma->hw_setup(edmac);
spin_unlock_irq(&edmac->lock);
if (ret)
goto fail_free_irq;
for (i = 0; i < DMA_MAX_CHAN_DESCRIPTORS; i++) {
struct ep93xx_dma_desc *desc;
desc = kzalloc(sizeof(*desc), GFP_KERNEL);
if (!desc) {
dev_warn(chan2dev(edmac), "not enough descriptors\n");
break;
}
INIT_LIST_HEAD(&desc->tx_list);
dma_async_tx_descriptor_init(&desc->txd, chan);
desc->txd.flags = DMA_CTRL_ACK;
desc->txd.tx_submit = ep93xx_dma_tx_submit;
ep93xx_dma_desc_put(edmac, desc);
}
return i;
fail_free_irq:
free_irq(edmac->irq, edmac);
fail_clk_disable:
clk_disable(edmac->clk);
return ret;
}
static void ep93xx_dma_free_chan_resources(struct dma_chan *chan)
{
struct ep93xx_dma_chan *edmac = to_ep93xx_dma_chan(chan);
struct ep93xx_dma_desc *desc, *d;
unsigned long flags;
LIST_HEAD(list);
BUG_ON(!list_empty(&edmac->active));
BUG_ON(!list_empty(&edmac->queue));
spin_lock_irqsave(&edmac->lock, flags);
edmac->edma->hw_shutdown(edmac);
edmac->runtime_addr = 0;
edmac->runtime_ctrl = 0;
edmac->buffer = 0;
list_splice_init(&edmac->free_list, &list);
spin_unlock_irqrestore(&edmac->lock, flags);
list_for_each_entry_safe(desc, d, &list, node)
kfree(desc);
clk_disable(edmac->clk);
free_irq(edmac->irq, edmac);
}
static struct dma_async_tx_descriptor *
ep93xx_dma_prep_dma_memcpy(struct dma_chan *chan, dma_addr_t dest,
dma_addr_t src, size_t len, unsigned long flags)
{
struct ep93xx_dma_chan *edmac = to_ep93xx_dma_chan(chan);
struct ep93xx_dma_desc *desc, *first;
size_t bytes, offset;
first = NULL;
for (offset = 0; offset < len; offset += bytes) {
desc = ep93xx_dma_desc_get(edmac);
if (!desc) {
dev_warn(chan2dev(edmac), "couln't get descriptor\n");
goto fail;
}
bytes = min_t(size_t, len - offset, DMA_MAX_CHAN_BYTES);
desc->src_addr = src + offset;
desc->dst_addr = dest + offset;
desc->size = bytes;
if (!first)
first = desc;
else
list_add_tail(&desc->node, &first->tx_list);
}
first->txd.cookie = -EBUSY;
first->txd.flags = flags;
return &first->txd;
fail:
ep93xx_dma_desc_put(edmac, first);
return NULL;
}
static struct dma_async_tx_descriptor *
ep93xx_dma_prep_slave_sg(struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_data_direction dir,
unsigned long flags)
{
struct ep93xx_dma_chan *edmac = to_ep93xx_dma_chan(chan);
struct ep93xx_dma_desc *desc, *first;
struct scatterlist *sg;
int i;
if (!edmac->edma->m2m && dir != ep93xx_dma_chan_direction(chan)) {
dev_warn(chan2dev(edmac),
"channel was configured with different direction\n");
return NULL;
}
if (test_bit(EP93XX_DMA_IS_CYCLIC, &edmac->flags)) {
dev_warn(chan2dev(edmac),
"channel is already used for cyclic transfers\n");
return NULL;
}
first = NULL;
for_each_sg(sgl, sg, sg_len, i) {
size_t sg_len = sg_dma_len(sg);
if (sg_len > DMA_MAX_CHAN_BYTES) {
dev_warn(chan2dev(edmac), "too big transfer size %d\n",
sg_len);
goto fail;
}
desc = ep93xx_dma_desc_get(edmac);
if (!desc) {
dev_warn(chan2dev(edmac), "couln't get descriptor\n");
goto fail;
}
if (dir == DMA_TO_DEVICE) {
desc->src_addr = sg_dma_address(sg);
desc->dst_addr = edmac->runtime_addr;
} else {
desc->src_addr = edmac->runtime_addr;
desc->dst_addr = sg_dma_address(sg);
}
desc->size = sg_len;
if (!first)
first = desc;
else
list_add_tail(&desc->node, &first->tx_list);
}
first->txd.cookie = -EBUSY;
first->txd.flags = flags;
return &first->txd;
fail:
ep93xx_dma_desc_put(edmac, first);
return NULL;
}
static struct dma_async_tx_descriptor *
ep93xx_dma_prep_dma_cyclic(struct dma_chan *chan, dma_addr_t dma_addr,
size_t buf_len, size_t period_len,
enum dma_data_direction dir)
{
struct ep93xx_dma_chan *edmac = to_ep93xx_dma_chan(chan);
struct ep93xx_dma_desc *desc, *first;
size_t offset = 0;
if (!edmac->edma->m2m && dir != ep93xx_dma_chan_direction(chan)) {
dev_warn(chan2dev(edmac),
"channel was configured with different direction\n");
return NULL;
}
if (test_and_set_bit(EP93XX_DMA_IS_CYCLIC, &edmac->flags)) {
dev_warn(chan2dev(edmac),
"channel is already used for cyclic transfers\n");
return NULL;
}
if (period_len > DMA_MAX_CHAN_BYTES) {
dev_warn(chan2dev(edmac), "too big period length %d\n",
period_len);
return NULL;
}
first = NULL;
for (offset = 0; offset < buf_len; offset += period_len) {
desc = ep93xx_dma_desc_get(edmac);
if (!desc) {
dev_warn(chan2dev(edmac), "couln't get descriptor\n");
goto fail;
}
if (dir == DMA_TO_DEVICE) {
desc->src_addr = dma_addr + offset;
desc->dst_addr = edmac->runtime_addr;
} else {
desc->src_addr = edmac->runtime_addr;
desc->dst_addr = dma_addr + offset;
}
desc->size = period_len;
if (!first)
first = desc;
else
list_add_tail(&desc->node, &first->tx_list);
}
first->txd.cookie = -EBUSY;
return &first->txd;
fail:
ep93xx_dma_desc_put(edmac, first);
return NULL;
}
static int ep93xx_dma_terminate_all(struct ep93xx_dma_chan *edmac)
{
struct ep93xx_dma_desc *desc, *_d;
unsigned long flags;
LIST_HEAD(list);
spin_lock_irqsave(&edmac->lock, flags);
edmac->edma->hw_shutdown(edmac);
clear_bit(EP93XX_DMA_IS_CYCLIC, &edmac->flags);
list_splice_init(&edmac->active, &list);
list_splice_init(&edmac->queue, &list);
edmac->edma->hw_setup(edmac);
spin_unlock_irqrestore(&edmac->lock, flags);
list_for_each_entry_safe(desc, _d, &list, node)
ep93xx_dma_desc_put(edmac, desc);
return 0;
}
static int ep93xx_dma_slave_config(struct ep93xx_dma_chan *edmac,
struct dma_slave_config *config)
{
enum dma_slave_buswidth width;
unsigned long flags;
u32 addr, ctrl;
if (!edmac->edma->m2m)
return -EINVAL;
switch (config->direction) {
case DMA_FROM_DEVICE:
width = config->src_addr_width;
addr = config->src_addr;
break;
case DMA_TO_DEVICE:
width = config->dst_addr_width;
addr = config->dst_addr;
break;
default:
return -EINVAL;
}
switch (width) {
case DMA_SLAVE_BUSWIDTH_1_BYTE:
ctrl = 0;
break;
case DMA_SLAVE_BUSWIDTH_2_BYTES:
ctrl = M2M_CONTROL_PW_16;
break;
case DMA_SLAVE_BUSWIDTH_4_BYTES:
ctrl = M2M_CONTROL_PW_32;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&edmac->lock, flags);
edmac->runtime_addr = addr;
edmac->runtime_ctrl = ctrl;
spin_unlock_irqrestore(&edmac->lock, flags);
return 0;
}
static int ep93xx_dma_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
struct ep93xx_dma_chan *edmac = to_ep93xx_dma_chan(chan);
struct dma_slave_config *config;
switch (cmd) {
case DMA_TERMINATE_ALL:
return ep93xx_dma_terminate_all(edmac);
case DMA_SLAVE_CONFIG:
config = (struct dma_slave_config *)arg;
return ep93xx_dma_slave_config(edmac, config);
default:
break;
}
return -ENOSYS;
}
static enum dma_status ep93xx_dma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *state)
{
struct ep93xx_dma_chan *edmac = to_ep93xx_dma_chan(chan);
dma_cookie_t last_used, last_completed;
enum dma_status ret;
unsigned long flags;
spin_lock_irqsave(&edmac->lock, flags);
last_used = chan->cookie;
last_completed = edmac->last_completed;
spin_unlock_irqrestore(&edmac->lock, flags);
ret = dma_async_is_complete(cookie, last_completed, last_used);
dma_set_tx_state(state, last_completed, last_used, 0);
return ret;
}
static void ep93xx_dma_issue_pending(struct dma_chan *chan)
{
ep93xx_dma_advance_work(to_ep93xx_dma_chan(chan));
}
static int __init ep93xx_dma_probe(struct platform_device *pdev)
{
struct ep93xx_dma_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct ep93xx_dma_engine *edma;
struct dma_device *dma_dev;
size_t edma_size;
int ret, i;
edma_size = pdata->num_channels * sizeof(struct ep93xx_dma_chan);
edma = kzalloc(sizeof(*edma) + edma_size, GFP_KERNEL);
if (!edma)
return -ENOMEM;
dma_dev = &edma->dma_dev;
edma->m2m = platform_get_device_id(pdev)->driver_data;
edma->num_channels = pdata->num_channels;
INIT_LIST_HEAD(&dma_dev->channels);
for (i = 0; i < pdata->num_channels; i++) {
const struct ep93xx_dma_chan_data *cdata = &pdata->channels[i];
struct ep93xx_dma_chan *edmac = &edma->channels[i];
edmac->chan.device = dma_dev;
edmac->regs = cdata->base;
edmac->irq = cdata->irq;
edmac->edma = edma;
edmac->clk = clk_get(NULL, cdata->name);
if (IS_ERR(edmac->clk)) {
dev_warn(&pdev->dev, "failed to get clock for %s\n",
cdata->name);
continue;
}
spin_lock_init(&edmac->lock);
INIT_LIST_HEAD(&edmac->active);
INIT_LIST_HEAD(&edmac->queue);
INIT_LIST_HEAD(&edmac->free_list);
tasklet_init(&edmac->tasklet, ep93xx_dma_tasklet,
(unsigned long)edmac);
list_add_tail(&edmac->chan.device_node,
&dma_dev->channels);
}
dma_cap_zero(dma_dev->cap_mask);
dma_cap_set(DMA_SLAVE, dma_dev->cap_mask);
dma_cap_set(DMA_CYCLIC, dma_dev->cap_mask);
dma_dev->dev = &pdev->dev;
dma_dev->device_alloc_chan_resources = ep93xx_dma_alloc_chan_resources;
dma_dev->device_free_chan_resources = ep93xx_dma_free_chan_resources;
dma_dev->device_prep_slave_sg = ep93xx_dma_prep_slave_sg;
dma_dev->device_prep_dma_cyclic = ep93xx_dma_prep_dma_cyclic;
dma_dev->device_control = ep93xx_dma_control;
dma_dev->device_issue_pending = ep93xx_dma_issue_pending;
dma_dev->device_tx_status = ep93xx_dma_tx_status;
dma_set_max_seg_size(dma_dev->dev, DMA_MAX_CHAN_BYTES);
if (edma->m2m) {
dma_cap_set(DMA_MEMCPY, dma_dev->cap_mask);
dma_dev->device_prep_dma_memcpy = ep93xx_dma_prep_dma_memcpy;
edma->hw_setup = m2m_hw_setup;
edma->hw_shutdown = m2m_hw_shutdown;
edma->hw_submit = m2m_hw_submit;
edma->hw_interrupt = m2m_hw_interrupt;
} else {
dma_cap_set(DMA_PRIVATE, dma_dev->cap_mask);
edma->hw_setup = m2p_hw_setup;
edma->hw_shutdown = m2p_hw_shutdown;
edma->hw_submit = m2p_hw_submit;
edma->hw_interrupt = m2p_hw_interrupt;
}
ret = dma_async_device_register(dma_dev);
if (unlikely(ret)) {
for (i = 0; i < edma->num_channels; i++) {
struct ep93xx_dma_chan *edmac = &edma->channels[i];
if (!IS_ERR_OR_NULL(edmac->clk))
clk_put(edmac->clk);
}
kfree(edma);
} else {
dev_info(dma_dev->dev, "EP93xx M2%s DMA ready\n",
edma->m2m ? "M" : "P");
}
return ret;
}
static int __init ep93xx_dma_module_init(void)
{
return platform_driver_probe(&ep93xx_dma_driver, ep93xx_dma_probe);
}
