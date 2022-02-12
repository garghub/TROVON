static void mxs_dma_reset_chan(struct mxs_dma_chan *mxs_chan)
{
struct mxs_dma_engine *mxs_dma = mxs_chan->mxs_dma;
int chan_id = mxs_chan->chan.chan_id;
if (dma_is_apbh() && apbh_is_old())
writel(1 << (chan_id + BP_APBH_CTRL0_RESET_CHANNEL),
mxs_dma->base + HW_APBHX_CTRL0 + MXS_SET_ADDR);
else
writel(1 << (chan_id + BP_APBHX_CHANNEL_CTRL_RESET_CHANNEL),
mxs_dma->base + HW_APBHX_CHANNEL_CTRL + MXS_SET_ADDR);
}
static void mxs_dma_enable_chan(struct mxs_dma_chan *mxs_chan)
{
struct mxs_dma_engine *mxs_dma = mxs_chan->mxs_dma;
int chan_id = mxs_chan->chan.chan_id;
writel(mxs_chan->ccw_phys,
mxs_dma->base + HW_APBHX_CHn_NXTCMDAR(chan_id));
if (dma_is_apbh()) {
if (apbh_is_old())
writel(1 << (chan_id + BP_APBH_CTRL0_CLKGATE_CHANNEL),
mxs_dma->base + HW_APBHX_CTRL0 + MXS_CLR_ADDR);
else
writel(1 << chan_id,
mxs_dma->base + HW_APBHX_CTRL0 + MXS_CLR_ADDR);
}
writel(1, mxs_dma->base + HW_APBHX_CHn_SEMA(chan_id));
}
static void mxs_dma_disable_chan(struct mxs_dma_chan *mxs_chan)
{
struct mxs_dma_engine *mxs_dma = mxs_chan->mxs_dma;
int chan_id = mxs_chan->chan.chan_id;
if (dma_is_apbh()) {
if (apbh_is_old())
writel(1 << (chan_id + BP_APBH_CTRL0_CLKGATE_CHANNEL),
mxs_dma->base + HW_APBHX_CTRL0 + MXS_SET_ADDR);
else
writel(1 << chan_id,
mxs_dma->base + HW_APBHX_CTRL0 + MXS_SET_ADDR);
}
mxs_chan->status = DMA_SUCCESS;
}
static void mxs_dma_pause_chan(struct mxs_dma_chan *mxs_chan)
{
struct mxs_dma_engine *mxs_dma = mxs_chan->mxs_dma;
int chan_id = mxs_chan->chan.chan_id;
if (dma_is_apbh() && apbh_is_old())
writel(1 << chan_id,
mxs_dma->base + HW_APBHX_CTRL0 + MXS_SET_ADDR);
else
writel(1 << chan_id,
mxs_dma->base + HW_APBHX_CHANNEL_CTRL + MXS_SET_ADDR);
mxs_chan->status = DMA_PAUSED;
}
static void mxs_dma_resume_chan(struct mxs_dma_chan *mxs_chan)
{
struct mxs_dma_engine *mxs_dma = mxs_chan->mxs_dma;
int chan_id = mxs_chan->chan.chan_id;
if (dma_is_apbh() && apbh_is_old())
writel(1 << chan_id,
mxs_dma->base + HW_APBHX_CTRL0 + MXS_CLR_ADDR);
else
writel(1 << chan_id,
mxs_dma->base + HW_APBHX_CHANNEL_CTRL + MXS_CLR_ADDR);
mxs_chan->status = DMA_IN_PROGRESS;
}
static dma_cookie_t mxs_dma_assign_cookie(struct mxs_dma_chan *mxs_chan)
{
dma_cookie_t cookie = mxs_chan->chan.cookie;
if (++cookie < 0)
cookie = 1;
mxs_chan->chan.cookie = cookie;
mxs_chan->desc.cookie = cookie;
return cookie;
}
static struct mxs_dma_chan *to_mxs_dma_chan(struct dma_chan *chan)
{
return container_of(chan, struct mxs_dma_chan, chan);
}
static dma_cookie_t mxs_dma_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct mxs_dma_chan *mxs_chan = to_mxs_dma_chan(tx->chan);
mxs_dma_enable_chan(mxs_chan);
return mxs_dma_assign_cookie(mxs_chan);
}
static void mxs_dma_tasklet(unsigned long data)
{
struct mxs_dma_chan *mxs_chan = (struct mxs_dma_chan *) data;
if (mxs_chan->desc.callback)
mxs_chan->desc.callback(mxs_chan->desc.callback_param);
}
static irqreturn_t mxs_dma_int_handler(int irq, void *dev_id)
{
struct mxs_dma_engine *mxs_dma = dev_id;
u32 stat1, stat2;
stat1 = readl(mxs_dma->base + HW_APBHX_CTRL1);
stat1 &= MXS_DMA_CHANNELS_MASK;
writel(stat1, mxs_dma->base + HW_APBHX_CTRL1 + MXS_CLR_ADDR);
stat2 = readl(mxs_dma->base + HW_APBHX_CTRL2);
writel(stat2, mxs_dma->base + HW_APBHX_CTRL2 + MXS_CLR_ADDR);
stat2 = ((stat2 >> MXS_DMA_CHANNELS) & stat2) |
(~(stat2 >> MXS_DMA_CHANNELS) & stat2 & ~stat1);
stat1 = (stat2 << MXS_DMA_CHANNELS) | stat1;
while (stat1) {
int channel = fls(stat1) - 1;
struct mxs_dma_chan *mxs_chan =
&mxs_dma->mxs_chans[channel % MXS_DMA_CHANNELS];
if (channel >= MXS_DMA_CHANNELS) {
dev_dbg(mxs_dma->dma_device.dev,
"%s: error in channel %d\n", __func__,
channel - MXS_DMA_CHANNELS);
mxs_chan->status = DMA_ERROR;
mxs_dma_reset_chan(mxs_chan);
} else {
if (mxs_chan->flags & MXS_DMA_SG_LOOP)
mxs_chan->status = DMA_IN_PROGRESS;
else
mxs_chan->status = DMA_SUCCESS;
}
stat1 &= ~(1 << channel);
if (mxs_chan->status == DMA_SUCCESS)
mxs_chan->last_completed = mxs_chan->desc.cookie;
tasklet_schedule(&mxs_chan->tasklet);
}
return IRQ_HANDLED;
}
static int mxs_dma_alloc_chan_resources(struct dma_chan *chan)
{
struct mxs_dma_chan *mxs_chan = to_mxs_dma_chan(chan);
struct mxs_dma_data *data = chan->private;
struct mxs_dma_engine *mxs_dma = mxs_chan->mxs_dma;
int ret;
if (!data)
return -EINVAL;
mxs_chan->chan_irq = data->chan_irq;
mxs_chan->ccw = dma_alloc_coherent(mxs_dma->dma_device.dev, PAGE_SIZE,
&mxs_chan->ccw_phys, GFP_KERNEL);
if (!mxs_chan->ccw) {
ret = -ENOMEM;
goto err_alloc;
}
memset(mxs_chan->ccw, 0, PAGE_SIZE);
ret = request_irq(mxs_chan->chan_irq, mxs_dma_int_handler,
0, "mxs-dma", mxs_dma);
if (ret)
goto err_irq;
ret = clk_enable(mxs_dma->clk);
if (ret)
goto err_clk;
mxs_dma_reset_chan(mxs_chan);
dma_async_tx_descriptor_init(&mxs_chan->desc, chan);
mxs_chan->desc.tx_submit = mxs_dma_tx_submit;
async_tx_ack(&mxs_chan->desc);
return 0;
err_clk:
free_irq(mxs_chan->chan_irq, mxs_dma);
err_irq:
dma_free_coherent(mxs_dma->dma_device.dev, PAGE_SIZE,
mxs_chan->ccw, mxs_chan->ccw_phys);
err_alloc:
return ret;
}
static void mxs_dma_free_chan_resources(struct dma_chan *chan)
{
struct mxs_dma_chan *mxs_chan = to_mxs_dma_chan(chan);
struct mxs_dma_engine *mxs_dma = mxs_chan->mxs_dma;
mxs_dma_disable_chan(mxs_chan);
free_irq(mxs_chan->chan_irq, mxs_dma);
dma_free_coherent(mxs_dma->dma_device.dev, PAGE_SIZE,
mxs_chan->ccw, mxs_chan->ccw_phys);
clk_disable(mxs_dma->clk);
}
static struct dma_async_tx_descriptor *mxs_dma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_data_direction direction,
unsigned long append)
{
struct mxs_dma_chan *mxs_chan = to_mxs_dma_chan(chan);
struct mxs_dma_engine *mxs_dma = mxs_chan->mxs_dma;
struct mxs_dma_ccw *ccw;
struct scatterlist *sg;
int i, j;
u32 *pio;
static int idx;
if (mxs_chan->status == DMA_IN_PROGRESS && !append)
return NULL;
if (sg_len + (append ? idx : 0) > NUM_CCW) {
dev_err(mxs_dma->dma_device.dev,
"maximum number of sg exceeded: %d > %d\n",
sg_len, NUM_CCW);
goto err_out;
}
mxs_chan->status = DMA_IN_PROGRESS;
mxs_chan->flags = 0;
if (append) {
BUG_ON(idx < 1);
ccw = &mxs_chan->ccw[idx - 1];
ccw->next = mxs_chan->ccw_phys + sizeof(*ccw) * idx;
ccw->bits |= CCW_CHAIN;
ccw->bits &= ~CCW_IRQ;
ccw->bits &= ~CCW_DEC_SEM;
ccw->bits &= ~CCW_WAIT4END;
} else {
idx = 0;
}
if (direction == DMA_NONE) {
ccw = &mxs_chan->ccw[idx++];
pio = (u32 *) sgl;
for (j = 0; j < sg_len;)
ccw->pio_words[j++] = *pio++;
ccw->bits = 0;
ccw->bits |= CCW_IRQ;
ccw->bits |= CCW_DEC_SEM;
ccw->bits |= CCW_WAIT4END;
ccw->bits |= CCW_HALT_ON_TERM;
ccw->bits |= CCW_TERM_FLUSH;
ccw->bits |= BF_CCW(sg_len, PIO_NUM);
ccw->bits |= BF_CCW(MXS_DMA_CMD_NO_XFER, COMMAND);
} else {
for_each_sg(sgl, sg, sg_len, i) {
if (sg->length > MAX_XFER_BYTES) {
dev_err(mxs_dma->dma_device.dev, "maximum bytes for sg entry exceeded: %d > %d\n",
sg->length, MAX_XFER_BYTES);
goto err_out;
}
ccw = &mxs_chan->ccw[idx++];
ccw->next = mxs_chan->ccw_phys + sizeof(*ccw) * idx;
ccw->bufaddr = sg->dma_address;
ccw->xfer_bytes = sg->length;
ccw->bits = 0;
ccw->bits |= CCW_CHAIN;
ccw->bits |= CCW_HALT_ON_TERM;
ccw->bits |= CCW_TERM_FLUSH;
ccw->bits |= BF_CCW(direction == DMA_FROM_DEVICE ?
MXS_DMA_CMD_WRITE : MXS_DMA_CMD_READ,
COMMAND);
if (i + 1 == sg_len) {
ccw->bits &= ~CCW_CHAIN;
ccw->bits |= CCW_IRQ;
ccw->bits |= CCW_DEC_SEM;
ccw->bits |= CCW_WAIT4END;
}
}
}
return &mxs_chan->desc;
err_out:
mxs_chan->status = DMA_ERROR;
return NULL;
}
static struct dma_async_tx_descriptor *mxs_dma_prep_dma_cyclic(
struct dma_chan *chan, dma_addr_t dma_addr, size_t buf_len,
size_t period_len, enum dma_data_direction direction)
{
struct mxs_dma_chan *mxs_chan = to_mxs_dma_chan(chan);
struct mxs_dma_engine *mxs_dma = mxs_chan->mxs_dma;
int num_periods = buf_len / period_len;
int i = 0, buf = 0;
if (mxs_chan->status == DMA_IN_PROGRESS)
return NULL;
mxs_chan->status = DMA_IN_PROGRESS;
mxs_chan->flags |= MXS_DMA_SG_LOOP;
if (num_periods > NUM_CCW) {
dev_err(mxs_dma->dma_device.dev,
"maximum number of sg exceeded: %d > %d\n",
num_periods, NUM_CCW);
goto err_out;
}
if (period_len > MAX_XFER_BYTES) {
dev_err(mxs_dma->dma_device.dev,
"maximum period size exceeded: %d > %d\n",
period_len, MAX_XFER_BYTES);
goto err_out;
}
while (buf < buf_len) {
struct mxs_dma_ccw *ccw = &mxs_chan->ccw[i];
if (i + 1 == num_periods)
ccw->next = mxs_chan->ccw_phys;
else
ccw->next = mxs_chan->ccw_phys + sizeof(*ccw) * (i + 1);
ccw->bufaddr = dma_addr;
ccw->xfer_bytes = period_len;
ccw->bits = 0;
ccw->bits |= CCW_CHAIN;
ccw->bits |= CCW_IRQ;
ccw->bits |= CCW_HALT_ON_TERM;
ccw->bits |= CCW_TERM_FLUSH;
ccw->bits |= BF_CCW(direction == DMA_FROM_DEVICE ?
MXS_DMA_CMD_WRITE : MXS_DMA_CMD_READ, COMMAND);
dma_addr += period_len;
buf += period_len;
i++;
}
return &mxs_chan->desc;
err_out:
mxs_chan->status = DMA_ERROR;
return NULL;
}
static int mxs_dma_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
struct mxs_dma_chan *mxs_chan = to_mxs_dma_chan(chan);
int ret = 0;
switch (cmd) {
case DMA_TERMINATE_ALL:
mxs_dma_disable_chan(mxs_chan);
break;
case DMA_PAUSE:
mxs_dma_pause_chan(mxs_chan);
break;
case DMA_RESUME:
mxs_dma_resume_chan(mxs_chan);
break;
default:
ret = -ENOSYS;
}
return ret;
}
static enum dma_status mxs_dma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie, struct dma_tx_state *txstate)
{
struct mxs_dma_chan *mxs_chan = to_mxs_dma_chan(chan);
dma_cookie_t last_used;
last_used = chan->cookie;
dma_set_tx_state(txstate, mxs_chan->last_completed, last_used, 0);
return mxs_chan->status;
}
static void mxs_dma_issue_pending(struct dma_chan *chan)
{
}
static int __init mxs_dma_init(struct mxs_dma_engine *mxs_dma)
{
int ret;
ret = clk_enable(mxs_dma->clk);
if (ret)
goto err_out;
ret = mxs_reset_block(mxs_dma->base);
if (ret)
goto err_out;
mxs_dma->version = readl(mxs_dma->base +
((mxs_dma->dev_id == MXS_DMA_APBX) ?
HW_APBX_VERSION : HW_APBH_VERSION)) >>
BP_APBHX_VERSION_MAJOR;
if (dma_is_apbh()) {
writel(BM_APBH_CTRL0_APB_BURST_EN,
mxs_dma->base + HW_APBHX_CTRL0 + MXS_SET_ADDR);
writel(BM_APBH_CTRL0_APB_BURST8_EN,
mxs_dma->base + HW_APBHX_CTRL0 + MXS_SET_ADDR);
}
writel(MXS_DMA_CHANNELS_MASK << MXS_DMA_CHANNELS,
mxs_dma->base + HW_APBHX_CTRL1 + MXS_SET_ADDR);
clk_disable(mxs_dma->clk);
return 0;
err_out:
return ret;
}
static int __init mxs_dma_probe(struct platform_device *pdev)
{
const struct platform_device_id *id_entry =
platform_get_device_id(pdev);
struct mxs_dma_engine *mxs_dma;
struct resource *iores;
int ret, i;
mxs_dma = kzalloc(sizeof(*mxs_dma), GFP_KERNEL);
if (!mxs_dma)
return -ENOMEM;
mxs_dma->dev_id = id_entry->driver_data;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!request_mem_region(iores->start, resource_size(iores),
pdev->name)) {
ret = -EBUSY;
goto err_request_region;
}
mxs_dma->base = ioremap(iores->start, resource_size(iores));
if (!mxs_dma->base) {
ret = -ENOMEM;
goto err_ioremap;
}
mxs_dma->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(mxs_dma->clk)) {
ret = PTR_ERR(mxs_dma->clk);
goto err_clk;
}
dma_cap_set(DMA_SLAVE, mxs_dma->dma_device.cap_mask);
dma_cap_set(DMA_CYCLIC, mxs_dma->dma_device.cap_mask);
INIT_LIST_HEAD(&mxs_dma->dma_device.channels);
for (i = 0; i < MXS_DMA_CHANNELS; i++) {
struct mxs_dma_chan *mxs_chan = &mxs_dma->mxs_chans[i];
mxs_chan->mxs_dma = mxs_dma;
mxs_chan->chan.device = &mxs_dma->dma_device;
tasklet_init(&mxs_chan->tasklet, mxs_dma_tasklet,
(unsigned long) mxs_chan);
list_add_tail(&mxs_chan->chan.device_node,
&mxs_dma->dma_device.channels);
}
ret = mxs_dma_init(mxs_dma);
if (ret)
goto err_init;
mxs_dma->dma_device.dev = &pdev->dev;
mxs_dma->dma_device.dev->dma_parms = &mxs_dma->dma_parms;
dma_set_max_seg_size(mxs_dma->dma_device.dev, MAX_XFER_BYTES);
mxs_dma->dma_device.device_alloc_chan_resources = mxs_dma_alloc_chan_resources;
mxs_dma->dma_device.device_free_chan_resources = mxs_dma_free_chan_resources;
mxs_dma->dma_device.device_tx_status = mxs_dma_tx_status;
mxs_dma->dma_device.device_prep_slave_sg = mxs_dma_prep_slave_sg;
mxs_dma->dma_device.device_prep_dma_cyclic = mxs_dma_prep_dma_cyclic;
mxs_dma->dma_device.device_control = mxs_dma_control;
mxs_dma->dma_device.device_issue_pending = mxs_dma_issue_pending;
ret = dma_async_device_register(&mxs_dma->dma_device);
if (ret) {
dev_err(mxs_dma->dma_device.dev, "unable to register\n");
goto err_init;
}
dev_info(mxs_dma->dma_device.dev, "initialized\n");
return 0;
err_init:
clk_put(mxs_dma->clk);
err_clk:
iounmap(mxs_dma->base);
err_ioremap:
release_mem_region(iores->start, resource_size(iores));
err_request_region:
kfree(mxs_dma);
return ret;
}
static int __init mxs_dma_module_init(void)
{
return platform_driver_probe(&mxs_dma_driver, mxs_dma_probe);
}
