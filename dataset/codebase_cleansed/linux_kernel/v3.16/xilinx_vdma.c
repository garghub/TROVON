static inline u32 vdma_read(struct xilinx_vdma_chan *chan, u32 reg)
{
return ioread32(chan->xdev->regs + reg);
}
static inline void vdma_write(struct xilinx_vdma_chan *chan, u32 reg, u32 value)
{
iowrite32(value, chan->xdev->regs + reg);
}
static inline void vdma_desc_write(struct xilinx_vdma_chan *chan, u32 reg,
u32 value)
{
vdma_write(chan, chan->desc_offset + reg, value);
}
static inline u32 vdma_ctrl_read(struct xilinx_vdma_chan *chan, u32 reg)
{
return vdma_read(chan, chan->ctrl_offset + reg);
}
static inline void vdma_ctrl_write(struct xilinx_vdma_chan *chan, u32 reg,
u32 value)
{
vdma_write(chan, chan->ctrl_offset + reg, value);
}
static inline void vdma_ctrl_clr(struct xilinx_vdma_chan *chan, u32 reg,
u32 clr)
{
vdma_ctrl_write(chan, reg, vdma_ctrl_read(chan, reg) & ~clr);
}
static inline void vdma_ctrl_set(struct xilinx_vdma_chan *chan, u32 reg,
u32 set)
{
vdma_ctrl_write(chan, reg, vdma_ctrl_read(chan, reg) | set);
}
static struct xilinx_vdma_tx_segment *
xilinx_vdma_alloc_tx_segment(struct xilinx_vdma_chan *chan)
{
struct xilinx_vdma_tx_segment *segment;
dma_addr_t phys;
segment = dma_pool_alloc(chan->desc_pool, GFP_ATOMIC, &phys);
if (!segment)
return NULL;
memset(segment, 0, sizeof(*segment));
segment->phys = phys;
return segment;
}
static void xilinx_vdma_free_tx_segment(struct xilinx_vdma_chan *chan,
struct xilinx_vdma_tx_segment *segment)
{
dma_pool_free(chan->desc_pool, segment, segment->phys);
}
static struct xilinx_vdma_tx_descriptor *
xilinx_vdma_alloc_tx_descriptor(struct xilinx_vdma_chan *chan)
{
struct xilinx_vdma_tx_descriptor *desc;
unsigned long flags;
if (chan->allocated_desc)
return chan->allocated_desc;
desc = kzalloc(sizeof(*desc), GFP_KERNEL);
if (!desc)
return NULL;
spin_lock_irqsave(&chan->lock, flags);
chan->allocated_desc = desc;
spin_unlock_irqrestore(&chan->lock, flags);
INIT_LIST_HEAD(&desc->segments);
return desc;
}
static void
xilinx_vdma_free_tx_descriptor(struct xilinx_vdma_chan *chan,
struct xilinx_vdma_tx_descriptor *desc)
{
struct xilinx_vdma_tx_segment *segment, *next;
if (!desc)
return;
list_for_each_entry_safe(segment, next, &desc->segments, node) {
list_del(&segment->node);
xilinx_vdma_free_tx_segment(chan, segment);
}
kfree(desc);
}
static void xilinx_vdma_free_desc_list(struct xilinx_vdma_chan *chan,
struct list_head *list)
{
struct xilinx_vdma_tx_descriptor *desc, *next;
list_for_each_entry_safe(desc, next, list, node) {
list_del(&desc->node);
xilinx_vdma_free_tx_descriptor(chan, desc);
}
}
static void xilinx_vdma_free_descriptors(struct xilinx_vdma_chan *chan)
{
unsigned long flags;
spin_lock_irqsave(&chan->lock, flags);
xilinx_vdma_free_desc_list(chan, &chan->pending_list);
xilinx_vdma_free_desc_list(chan, &chan->done_list);
xilinx_vdma_free_tx_descriptor(chan, chan->active_desc);
chan->active_desc = NULL;
spin_unlock_irqrestore(&chan->lock, flags);
}
static void xilinx_vdma_free_chan_resources(struct dma_chan *dchan)
{
struct xilinx_vdma_chan *chan = to_xilinx_chan(dchan);
dev_dbg(chan->dev, "Free all channel resources.\n");
xilinx_vdma_free_descriptors(chan);
dma_pool_destroy(chan->desc_pool);
chan->desc_pool = NULL;
}
static void xilinx_vdma_chan_desc_cleanup(struct xilinx_vdma_chan *chan)
{
struct xilinx_vdma_tx_descriptor *desc, *next;
unsigned long flags;
spin_lock_irqsave(&chan->lock, flags);
list_for_each_entry_safe(desc, next, &chan->done_list, node) {
dma_async_tx_callback callback;
void *callback_param;
list_del(&desc->node);
callback = desc->async_tx.callback;
callback_param = desc->async_tx.callback_param;
if (callback) {
spin_unlock_irqrestore(&chan->lock, flags);
callback(callback_param);
spin_lock_irqsave(&chan->lock, flags);
}
dma_run_dependencies(&desc->async_tx);
xilinx_vdma_free_tx_descriptor(chan, desc);
}
spin_unlock_irqrestore(&chan->lock, flags);
}
static void xilinx_vdma_do_tasklet(unsigned long data)
{
struct xilinx_vdma_chan *chan = (struct xilinx_vdma_chan *)data;
xilinx_vdma_chan_desc_cleanup(chan);
}
static int xilinx_vdma_alloc_chan_resources(struct dma_chan *dchan)
{
struct xilinx_vdma_chan *chan = to_xilinx_chan(dchan);
if (chan->desc_pool)
return 0;
chan->desc_pool = dma_pool_create("xilinx_vdma_desc_pool",
chan->dev,
sizeof(struct xilinx_vdma_tx_segment),
__alignof__(struct xilinx_vdma_tx_segment), 0);
if (!chan->desc_pool) {
dev_err(chan->dev,
"unable to allocate channel %d descriptor pool\n",
chan->id);
return -ENOMEM;
}
dma_cookie_init(dchan);
return 0;
}
static enum dma_status xilinx_vdma_tx_status(struct dma_chan *dchan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
return dma_cookie_status(dchan, cookie, txstate);
}
static bool xilinx_vdma_is_running(struct xilinx_vdma_chan *chan)
{
return !(vdma_ctrl_read(chan, XILINX_VDMA_REG_DMASR) &
XILINX_VDMA_DMASR_HALTED) &&
(vdma_ctrl_read(chan, XILINX_VDMA_REG_DMACR) &
XILINX_VDMA_DMACR_RUNSTOP);
}
static bool xilinx_vdma_is_idle(struct xilinx_vdma_chan *chan)
{
return vdma_ctrl_read(chan, XILINX_VDMA_REG_DMASR) &
XILINX_VDMA_DMASR_IDLE;
}
static void xilinx_vdma_halt(struct xilinx_vdma_chan *chan)
{
int loop = XILINX_VDMA_LOOP_COUNT;
vdma_ctrl_clr(chan, XILINX_VDMA_REG_DMACR, XILINX_VDMA_DMACR_RUNSTOP);
do {
if (vdma_ctrl_read(chan, XILINX_VDMA_REG_DMASR) &
XILINX_VDMA_DMASR_HALTED)
break;
} while (loop--);
if (!loop) {
dev_err(chan->dev, "Cannot stop channel %p: %x\n",
chan, vdma_ctrl_read(chan, XILINX_VDMA_REG_DMASR));
chan->err = true;
}
return;
}
static void xilinx_vdma_start(struct xilinx_vdma_chan *chan)
{
int loop = XILINX_VDMA_LOOP_COUNT;
vdma_ctrl_set(chan, XILINX_VDMA_REG_DMACR, XILINX_VDMA_DMACR_RUNSTOP);
do {
if (!(vdma_ctrl_read(chan, XILINX_VDMA_REG_DMASR) &
XILINX_VDMA_DMASR_HALTED))
break;
} while (loop--);
if (!loop) {
dev_err(chan->dev, "Cannot start channel %p: %x\n",
chan, vdma_ctrl_read(chan, XILINX_VDMA_REG_DMASR));
chan->err = true;
}
return;
}
static void xilinx_vdma_start_transfer(struct xilinx_vdma_chan *chan)
{
struct xilinx_vdma_config *config = &chan->config;
struct xilinx_vdma_tx_descriptor *desc;
unsigned long flags;
u32 reg;
struct xilinx_vdma_tx_segment *head, *tail = NULL;
if (chan->err)
return;
spin_lock_irqsave(&chan->lock, flags);
if (chan->active_desc)
goto out_unlock;
if (list_empty(&chan->pending_list))
goto out_unlock;
desc = list_first_entry(&chan->pending_list,
struct xilinx_vdma_tx_descriptor, node);
if (chan->has_sg && xilinx_vdma_is_running(chan) &&
!xilinx_vdma_is_idle(chan)) {
dev_dbg(chan->dev, "DMA controller still busy\n");
goto out_unlock;
}
if (chan->has_sg) {
head = list_first_entry(&desc->segments,
struct xilinx_vdma_tx_segment, node);
tail = list_entry(desc->segments.prev,
struct xilinx_vdma_tx_segment, node);
vdma_ctrl_write(chan, XILINX_VDMA_REG_CURDESC, head->phys);
}
reg = vdma_ctrl_read(chan, XILINX_VDMA_REG_DMACR);
if (config->frm_cnt_en)
reg |= XILINX_VDMA_DMACR_FRAMECNT_EN;
else
reg &= ~XILINX_VDMA_DMACR_FRAMECNT_EN;
if (chan->has_sg || !config->park)
reg |= XILINX_VDMA_DMACR_CIRC_EN;
if (config->park)
reg &= ~XILINX_VDMA_DMACR_CIRC_EN;
vdma_ctrl_write(chan, XILINX_VDMA_REG_DMACR, reg);
if (config->park && (config->park_frm >= 0) &&
(config->park_frm < chan->num_frms)) {
if (chan->direction == DMA_MEM_TO_DEV)
vdma_write(chan, XILINX_VDMA_REG_PARK_PTR,
config->park_frm <<
XILINX_VDMA_PARK_PTR_RD_REF_SHIFT);
else
vdma_write(chan, XILINX_VDMA_REG_PARK_PTR,
config->park_frm <<
XILINX_VDMA_PARK_PTR_WR_REF_SHIFT);
}
xilinx_vdma_start(chan);
if (chan->err)
goto out_unlock;
if (chan->has_sg) {
vdma_ctrl_write(chan, XILINX_VDMA_REG_TAILDESC, tail->phys);
} else {
struct xilinx_vdma_tx_segment *segment, *last = NULL;
int i = 0;
list_for_each_entry(segment, &desc->segments, node) {
vdma_desc_write(chan,
XILINX_VDMA_REG_START_ADDRESS(i++),
segment->hw.buf_addr);
last = segment;
}
if (!last)
goto out_unlock;
vdma_desc_write(chan, XILINX_VDMA_REG_HSIZE, last->hw.hsize);
vdma_desc_write(chan, XILINX_VDMA_REG_FRMDLY_STRIDE,
last->hw.stride);
vdma_desc_write(chan, XILINX_VDMA_REG_VSIZE, last->hw.vsize);
}
list_del(&desc->node);
chan->active_desc = desc;
out_unlock:
spin_unlock_irqrestore(&chan->lock, flags);
}
static void xilinx_vdma_issue_pending(struct dma_chan *dchan)
{
struct xilinx_vdma_chan *chan = to_xilinx_chan(dchan);
xilinx_vdma_start_transfer(chan);
}
static void xilinx_vdma_complete_descriptor(struct xilinx_vdma_chan *chan)
{
struct xilinx_vdma_tx_descriptor *desc;
unsigned long flags;
spin_lock_irqsave(&chan->lock, flags);
desc = chan->active_desc;
if (!desc) {
dev_dbg(chan->dev, "no running descriptors\n");
goto out_unlock;
}
dma_cookie_complete(&desc->async_tx);
list_add_tail(&desc->node, &chan->done_list);
chan->active_desc = NULL;
out_unlock:
spin_unlock_irqrestore(&chan->lock, flags);
}
static int xilinx_vdma_reset(struct xilinx_vdma_chan *chan)
{
int loop = XILINX_VDMA_LOOP_COUNT;
u32 tmp;
vdma_ctrl_set(chan, XILINX_VDMA_REG_DMACR, XILINX_VDMA_DMACR_RESET);
tmp = vdma_ctrl_read(chan, XILINX_VDMA_REG_DMACR) &
XILINX_VDMA_DMACR_RESET;
do {
tmp = vdma_ctrl_read(chan, XILINX_VDMA_REG_DMACR) &
XILINX_VDMA_DMACR_RESET;
} while (loop-- && tmp);
if (!loop) {
dev_err(chan->dev, "reset timeout, cr %x, sr %x\n",
vdma_ctrl_read(chan, XILINX_VDMA_REG_DMACR),
vdma_ctrl_read(chan, XILINX_VDMA_REG_DMASR));
return -ETIMEDOUT;
}
chan->err = false;
return 0;
}
static int xilinx_vdma_chan_reset(struct xilinx_vdma_chan *chan)
{
int err;
err = xilinx_vdma_reset(chan);
if (err)
return err;
vdma_ctrl_set(chan, XILINX_VDMA_REG_DMACR,
XILINX_VDMA_DMAXR_ALL_IRQ_MASK);
return 0;
}
static irqreturn_t xilinx_vdma_irq_handler(int irq, void *data)
{
struct xilinx_vdma_chan *chan = data;
u32 status;
status = vdma_ctrl_read(chan, XILINX_VDMA_REG_DMASR);
if (!(status & XILINX_VDMA_DMAXR_ALL_IRQ_MASK))
return IRQ_NONE;
vdma_ctrl_write(chan, XILINX_VDMA_REG_DMASR,
status & XILINX_VDMA_DMAXR_ALL_IRQ_MASK);
if (status & XILINX_VDMA_DMASR_ERR_IRQ) {
u32 errors = status & XILINX_VDMA_DMASR_ALL_ERR_MASK;
vdma_ctrl_write(chan, XILINX_VDMA_REG_DMASR,
errors & XILINX_VDMA_DMASR_ERR_RECOVER_MASK);
if (!chan->flush_on_fsync ||
(errors & ~XILINX_VDMA_DMASR_ERR_RECOVER_MASK)) {
dev_err(chan->dev,
"Channel %p has errors %x, cdr %x tdr %x\n",
chan, errors,
vdma_ctrl_read(chan, XILINX_VDMA_REG_CURDESC),
vdma_ctrl_read(chan, XILINX_VDMA_REG_TAILDESC));
chan->err = true;
}
}
if (status & XILINX_VDMA_DMASR_DLY_CNT_IRQ) {
dev_dbg(chan->dev, "Inter-packet latency too long\n");
}
if (status & XILINX_VDMA_DMASR_FRM_CNT_IRQ) {
xilinx_vdma_complete_descriptor(chan);
xilinx_vdma_start_transfer(chan);
}
tasklet_schedule(&chan->tasklet);
return IRQ_HANDLED;
}
static dma_cookie_t xilinx_vdma_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct xilinx_vdma_tx_descriptor *desc = to_vdma_tx_descriptor(tx);
struct xilinx_vdma_chan *chan = to_xilinx_chan(tx->chan);
dma_cookie_t cookie;
unsigned long flags;
int err;
if (chan->err) {
err = xilinx_vdma_chan_reset(chan);
if (err < 0)
return err;
}
spin_lock_irqsave(&chan->lock, flags);
cookie = dma_cookie_assign(tx);
list_add_tail(&desc->node, &chan->pending_list);
chan->allocated_desc = NULL;
spin_unlock_irqrestore(&chan->lock, flags);
return cookie;
}
static struct dma_async_tx_descriptor *
xilinx_vdma_dma_prep_interleaved(struct dma_chan *dchan,
struct dma_interleaved_template *xt,
unsigned long flags)
{
struct xilinx_vdma_chan *chan = to_xilinx_chan(dchan);
struct xilinx_vdma_tx_descriptor *desc;
struct xilinx_vdma_tx_segment *segment, *prev = NULL;
struct xilinx_vdma_desc_hw *hw;
if (!is_slave_direction(xt->dir))
return NULL;
if (!xt->numf || !xt->sgl[0].size)
return NULL;
desc = xilinx_vdma_alloc_tx_descriptor(chan);
if (!desc)
return NULL;
dma_async_tx_descriptor_init(&desc->async_tx, &chan->common);
desc->async_tx.tx_submit = xilinx_vdma_tx_submit;
async_tx_ack(&desc->async_tx);
segment = xilinx_vdma_alloc_tx_segment(chan);
if (!segment)
goto error;
hw = &segment->hw;
hw->vsize = xt->numf;
hw->hsize = xt->sgl[0].size;
hw->stride = xt->sgl[0].icg <<
XILINX_VDMA_FRMDLY_STRIDE_STRIDE_SHIFT;
hw->stride |= chan->config.frm_dly <<
XILINX_VDMA_FRMDLY_STRIDE_FRMDLY_SHIFT;
if (xt->dir != DMA_MEM_TO_DEV)
hw->buf_addr = xt->dst_start;
else
hw->buf_addr = xt->src_start;
prev = list_last_entry(&desc->segments,
struct xilinx_vdma_tx_segment, node);
prev->hw.next_desc = segment->phys;
list_add_tail(&segment->node, &desc->segments);
prev = segment;
segment = list_first_entry(&desc->segments,
struct xilinx_vdma_tx_segment, node);
prev->hw.next_desc = segment->phys;
return &desc->async_tx;
error:
xilinx_vdma_free_tx_descriptor(chan, desc);
return NULL;
}
static void xilinx_vdma_terminate_all(struct xilinx_vdma_chan *chan)
{
xilinx_vdma_halt(chan);
xilinx_vdma_free_descriptors(chan);
}
int xilinx_vdma_channel_set_config(struct dma_chan *dchan,
struct xilinx_vdma_config *cfg)
{
struct xilinx_vdma_chan *chan = to_xilinx_chan(dchan);
u32 dmacr;
if (cfg->reset)
return xilinx_vdma_chan_reset(chan);
dmacr = vdma_ctrl_read(chan, XILINX_VDMA_REG_DMACR);
chan->config.frm_dly = cfg->frm_dly;
chan->config.park = cfg->park;
chan->config.gen_lock = cfg->gen_lock;
chan->config.master = cfg->master;
if (cfg->gen_lock && chan->genlock) {
dmacr |= XILINX_VDMA_DMACR_GENLOCK_EN;
dmacr |= cfg->master << XILINX_VDMA_DMACR_MASTER_SHIFT;
}
chan->config.frm_cnt_en = cfg->frm_cnt_en;
if (cfg->park)
chan->config.park_frm = cfg->park_frm;
else
chan->config.park_frm = -1;
chan->config.coalesc = cfg->coalesc;
chan->config.delay = cfg->delay;
if (cfg->coalesc <= XILINX_VDMA_DMACR_FRAME_COUNT_MAX) {
dmacr |= cfg->coalesc << XILINX_VDMA_DMACR_FRAME_COUNT_SHIFT;
chan->config.coalesc = cfg->coalesc;
}
if (cfg->delay <= XILINX_VDMA_DMACR_DELAY_MAX) {
dmacr |= cfg->delay << XILINX_VDMA_DMACR_DELAY_SHIFT;
chan->config.delay = cfg->delay;
}
dmacr &= ~XILINX_VDMA_DMACR_FSYNCSRC_MASK;
dmacr |= cfg->ext_fsync << XILINX_VDMA_DMACR_FSYNCSRC_SHIFT;
vdma_ctrl_write(chan, XILINX_VDMA_REG_DMACR, dmacr);
return 0;
}
static int xilinx_vdma_device_control(struct dma_chan *dchan,
enum dma_ctrl_cmd cmd, unsigned long arg)
{
struct xilinx_vdma_chan *chan = to_xilinx_chan(dchan);
if (cmd != DMA_TERMINATE_ALL)
return -ENXIO;
xilinx_vdma_terminate_all(chan);
return 0;
}
static void xilinx_vdma_chan_remove(struct xilinx_vdma_chan *chan)
{
vdma_ctrl_clr(chan, XILINX_VDMA_REG_DMACR,
XILINX_VDMA_DMAXR_ALL_IRQ_MASK);
if (chan->irq > 0)
free_irq(chan->irq, chan);
tasklet_kill(&chan->tasklet);
list_del(&chan->common.device_node);
}
static int xilinx_vdma_chan_probe(struct xilinx_vdma_device *xdev,
struct device_node *node)
{
struct xilinx_vdma_chan *chan;
bool has_dre = false;
u32 value, width;
int err;
chan = devm_kzalloc(xdev->dev, sizeof(*chan), GFP_KERNEL);
if (!chan)
return -ENOMEM;
chan->dev = xdev->dev;
chan->xdev = xdev;
chan->has_sg = xdev->has_sg;
spin_lock_init(&chan->lock);
INIT_LIST_HEAD(&chan->pending_list);
INIT_LIST_HEAD(&chan->done_list);
has_dre = of_property_read_bool(node, "xlnx,include-dre");
chan->genlock = of_property_read_bool(node, "xlnx,genlock-mode");
err = of_property_read_u32(node, "xlnx,datawidth", &value);
if (err) {
dev_err(xdev->dev, "missing xlnx,datawidth property\n");
return err;
}
width = value >> 3;
if (width > 8)
has_dre = false;
if (!has_dre)
xdev->common.copy_align = fls(width - 1);
if (of_device_is_compatible(node, "xlnx,axi-vdma-mm2s-channel")) {
chan->direction = DMA_MEM_TO_DEV;
chan->id = 0;
chan->ctrl_offset = XILINX_VDMA_MM2S_CTRL_OFFSET;
chan->desc_offset = XILINX_VDMA_MM2S_DESC_OFFSET;
if (xdev->flush_on_fsync == XILINX_VDMA_FLUSH_BOTH ||
xdev->flush_on_fsync == XILINX_VDMA_FLUSH_MM2S)
chan->flush_on_fsync = true;
} else if (of_device_is_compatible(node,
"xlnx,axi-vdma-s2mm-channel")) {
chan->direction = DMA_DEV_TO_MEM;
chan->id = 1;
chan->ctrl_offset = XILINX_VDMA_S2MM_CTRL_OFFSET;
chan->desc_offset = XILINX_VDMA_S2MM_DESC_OFFSET;
if (xdev->flush_on_fsync == XILINX_VDMA_FLUSH_BOTH ||
xdev->flush_on_fsync == XILINX_VDMA_FLUSH_S2MM)
chan->flush_on_fsync = true;
} else {
dev_err(xdev->dev, "Invalid channel compatible node\n");
return -EINVAL;
}
chan->irq = irq_of_parse_and_map(node, 0);
err = request_irq(chan->irq, xilinx_vdma_irq_handler, IRQF_SHARED,
"xilinx-vdma-controller", chan);
if (err) {
dev_err(xdev->dev, "unable to request IRQ %d\n", chan->irq);
return err;
}
tasklet_init(&chan->tasklet, xilinx_vdma_do_tasklet,
(unsigned long)chan);
chan->common.device = &xdev->common;
list_add_tail(&chan->common.device_node, &xdev->common.channels);
xdev->chan[chan->id] = chan;
err = xilinx_vdma_chan_reset(chan);
if (err < 0) {
dev_err(xdev->dev, "Reset channel failed\n");
return err;
}
return 0;
}
static struct dma_chan *of_dma_xilinx_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct xilinx_vdma_device *xdev = ofdma->of_dma_data;
int chan_id = dma_spec->args[0];
if (chan_id >= XILINX_VDMA_MAX_CHANS_PER_DEVICE)
return NULL;
return dma_get_slave_channel(&xdev->chan[chan_id]->common);
}
static int xilinx_vdma_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct xilinx_vdma_device *xdev;
struct device_node *child;
struct resource *io;
u32 num_frames;
int i, err;
xdev = devm_kzalloc(&pdev->dev, sizeof(*xdev), GFP_KERNEL);
if (!xdev)
return -ENOMEM;
xdev->dev = &pdev->dev;
io = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xdev->regs = devm_ioremap_resource(&pdev->dev, io);
if (IS_ERR(xdev->regs))
return PTR_ERR(xdev->regs);
xdev->has_sg = of_property_read_bool(node, "xlnx,include-sg");
err = of_property_read_u32(node, "xlnx,num-fstores", &num_frames);
if (err < 0) {
dev_err(xdev->dev, "missing xlnx,num-fstores property\n");
return err;
}
err = of_property_read_u32(node, "xlnx,flush-fsync",
&xdev->flush_on_fsync);
if (err < 0)
dev_warn(xdev->dev, "missing xlnx,flush-fsync property\n");
xdev->common.dev = &pdev->dev;
INIT_LIST_HEAD(&xdev->common.channels);
dma_cap_set(DMA_SLAVE, xdev->common.cap_mask);
dma_cap_set(DMA_PRIVATE, xdev->common.cap_mask);
xdev->common.device_alloc_chan_resources =
xilinx_vdma_alloc_chan_resources;
xdev->common.device_free_chan_resources =
xilinx_vdma_free_chan_resources;
xdev->common.device_prep_interleaved_dma =
xilinx_vdma_dma_prep_interleaved;
xdev->common.device_control = xilinx_vdma_device_control;
xdev->common.device_tx_status = xilinx_vdma_tx_status;
xdev->common.device_issue_pending = xilinx_vdma_issue_pending;
platform_set_drvdata(pdev, xdev);
for_each_child_of_node(node, child) {
err = xilinx_vdma_chan_probe(xdev, child);
if (err < 0)
goto error;
}
for (i = 0; i < XILINX_VDMA_MAX_CHANS_PER_DEVICE; i++)
if (xdev->chan[i])
xdev->chan[i]->num_frms = num_frames;
dma_async_device_register(&xdev->common);
err = of_dma_controller_register(node, of_dma_xilinx_xlate,
xdev);
if (err < 0) {
dev_err(&pdev->dev, "Unable to register DMA to DT\n");
dma_async_device_unregister(&xdev->common);
goto error;
}
dev_info(&pdev->dev, "Xilinx AXI VDMA Engine Driver Probed!!\n");
return 0;
error:
for (i = 0; i < XILINX_VDMA_MAX_CHANS_PER_DEVICE; i++)
if (xdev->chan[i])
xilinx_vdma_chan_remove(xdev->chan[i]);
return err;
}
static int xilinx_vdma_remove(struct platform_device *pdev)
{
struct xilinx_vdma_device *xdev = platform_get_drvdata(pdev);
int i;
of_dma_controller_free(pdev->dev.of_node);
dma_async_device_unregister(&xdev->common);
for (i = 0; i < XILINX_VDMA_MAX_CHANS_PER_DEVICE; i++)
if (xdev->chan[i])
xilinx_vdma_chan_remove(xdev->chan[i]);
return 0;
}
