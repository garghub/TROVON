static inline struct bam_chan *to_bam_chan(struct dma_chan *common)
{
return container_of(common, struct bam_chan, vc.chan);
}
static inline void __iomem *bam_addr(struct bam_device *bdev, u32 pipe,
enum bam_reg reg)
{
const struct reg_offset_data r = bdev->layout[reg];
return bdev->regs + r.base_offset +
r.pipe_mult * pipe +
r.evnt_mult * pipe +
r.ee_mult * bdev->ee;
}
static void bam_reset_channel(struct bam_chan *bchan)
{
struct bam_device *bdev = bchan->bdev;
lockdep_assert_held(&bchan->vc.lock);
writel_relaxed(1, bam_addr(bdev, bchan->id, BAM_P_RST));
writel_relaxed(0, bam_addr(bdev, bchan->id, BAM_P_RST));
wmb();
bchan->initialized = 0;
}
static void bam_chan_init_hw(struct bam_chan *bchan,
enum dma_transfer_direction dir)
{
struct bam_device *bdev = bchan->bdev;
u32 val;
bam_reset_channel(bchan);
writel_relaxed(ALIGN(bchan->fifo_phys, sizeof(struct bam_desc_hw)),
bam_addr(bdev, bchan->id, BAM_P_DESC_FIFO_ADDR));
writel_relaxed(BAM_DESC_FIFO_SIZE,
bam_addr(bdev, bchan->id, BAM_P_FIFO_SIZES));
writel_relaxed(P_DEFAULT_IRQS_EN,
bam_addr(bdev, bchan->id, BAM_P_IRQ_EN));
val = readl_relaxed(bam_addr(bdev, 0, BAM_IRQ_SRCS_MSK_EE));
val |= BIT(bchan->id);
writel_relaxed(val, bam_addr(bdev, 0, BAM_IRQ_SRCS_MSK_EE));
wmb();
val = P_EN | P_SYS_MODE;
if (dir == DMA_DEV_TO_MEM)
val |= P_DIRECTION;
writel_relaxed(val, bam_addr(bdev, bchan->id, BAM_P_CTRL));
bchan->initialized = 1;
bchan->head = 0;
bchan->tail = 0;
}
static int bam_alloc_chan(struct dma_chan *chan)
{
struct bam_chan *bchan = to_bam_chan(chan);
struct bam_device *bdev = bchan->bdev;
if (bchan->fifo_virt)
return 0;
bchan->fifo_virt = dma_alloc_writecombine(bdev->dev, BAM_DESC_FIFO_SIZE,
&bchan->fifo_phys, GFP_KERNEL);
if (!bchan->fifo_virt) {
dev_err(bdev->dev, "Failed to allocate desc fifo\n");
return -ENOMEM;
}
return 0;
}
static void bam_free_chan(struct dma_chan *chan)
{
struct bam_chan *bchan = to_bam_chan(chan);
struct bam_device *bdev = bchan->bdev;
u32 val;
unsigned long flags;
vchan_free_chan_resources(to_virt_chan(chan));
if (bchan->curr_txd) {
dev_err(bchan->bdev->dev, "Cannot free busy channel\n");
return;
}
spin_lock_irqsave(&bchan->vc.lock, flags);
bam_reset_channel(bchan);
spin_unlock_irqrestore(&bchan->vc.lock, flags);
dma_free_writecombine(bdev->dev, BAM_DESC_FIFO_SIZE, bchan->fifo_virt,
bchan->fifo_phys);
bchan->fifo_virt = NULL;
val = readl_relaxed(bam_addr(bdev, 0, BAM_IRQ_SRCS_MSK_EE));
val &= ~BIT(bchan->id);
writel_relaxed(val, bam_addr(bdev, 0, BAM_IRQ_SRCS_MSK_EE));
writel_relaxed(0, bam_addr(bdev, bchan->id, BAM_P_IRQ_EN));
}
static int bam_slave_config(struct dma_chan *chan,
struct dma_slave_config *cfg)
{
struct bam_chan *bchan = to_bam_chan(chan);
unsigned long flag;
spin_lock_irqsave(&bchan->vc.lock, flag);
memcpy(&bchan->slave, cfg, sizeof(*cfg));
bchan->reconfigure = 1;
spin_unlock_irqrestore(&bchan->vc.lock, flag);
return 0;
}
static struct dma_async_tx_descriptor *bam_prep_slave_sg(struct dma_chan *chan,
struct scatterlist *sgl, unsigned int sg_len,
enum dma_transfer_direction direction, unsigned long flags,
void *context)
{
struct bam_chan *bchan = to_bam_chan(chan);
struct bam_device *bdev = bchan->bdev;
struct bam_async_desc *async_desc;
struct scatterlist *sg;
u32 i;
struct bam_desc_hw *desc;
unsigned int num_alloc = 0;
if (!is_slave_direction(direction)) {
dev_err(bdev->dev, "invalid dma direction\n");
return NULL;
}
for_each_sg(sgl, sg, sg_len, i)
num_alloc += DIV_ROUND_UP(sg_dma_len(sg), BAM_MAX_DATA_SIZE);
async_desc = kzalloc(sizeof(*async_desc) +
(num_alloc * sizeof(struct bam_desc_hw)), GFP_NOWAIT);
if (!async_desc)
goto err_out;
if (flags & DMA_PREP_FENCE)
async_desc->flags |= DESC_FLAG_NWD;
if (flags & DMA_PREP_INTERRUPT)
async_desc->flags |= DESC_FLAG_EOT;
else
async_desc->flags |= DESC_FLAG_INT;
async_desc->num_desc = num_alloc;
async_desc->curr_desc = async_desc->desc;
async_desc->dir = direction;
desc = async_desc->desc;
for_each_sg(sgl, sg, sg_len, i) {
unsigned int remainder = sg_dma_len(sg);
unsigned int curr_offset = 0;
do {
desc->addr = sg_dma_address(sg) + curr_offset;
if (remainder > BAM_MAX_DATA_SIZE) {
desc->size = BAM_MAX_DATA_SIZE;
remainder -= BAM_MAX_DATA_SIZE;
curr_offset += BAM_MAX_DATA_SIZE;
} else {
desc->size = remainder;
remainder = 0;
}
async_desc->length += desc->size;
desc++;
} while (remainder > 0);
}
return vchan_tx_prep(&bchan->vc, &async_desc->vd, flags);
err_out:
kfree(async_desc);
return NULL;
}
static int bam_dma_terminate_all(struct dma_chan *chan)
{
struct bam_chan *bchan = to_bam_chan(chan);
unsigned long flag;
LIST_HEAD(head);
spin_lock_irqsave(&bchan->vc.lock, flag);
if (bchan->curr_txd) {
list_add(&bchan->curr_txd->vd.node, &bchan->vc.desc_issued);
bchan->curr_txd = NULL;
}
vchan_get_all_descriptors(&bchan->vc, &head);
spin_unlock_irqrestore(&bchan->vc.lock, flag);
vchan_dma_desc_free_list(&bchan->vc, &head);
return 0;
}
static int bam_pause(struct dma_chan *chan)
{
struct bam_chan *bchan = to_bam_chan(chan);
struct bam_device *bdev = bchan->bdev;
unsigned long flag;
spin_lock_irqsave(&bchan->vc.lock, flag);
writel_relaxed(1, bam_addr(bdev, bchan->id, BAM_P_HALT));
bchan->paused = 1;
spin_unlock_irqrestore(&bchan->vc.lock, flag);
return 0;
}
static int bam_resume(struct dma_chan *chan)
{
struct bam_chan *bchan = to_bam_chan(chan);
struct bam_device *bdev = bchan->bdev;
unsigned long flag;
spin_lock_irqsave(&bchan->vc.lock, flag);
writel_relaxed(0, bam_addr(bdev, bchan->id, BAM_P_HALT));
bchan->paused = 0;
spin_unlock_irqrestore(&bchan->vc.lock, flag);
return 0;
}
static u32 process_channel_irqs(struct bam_device *bdev)
{
u32 i, srcs, pipe_stts;
unsigned long flags;
struct bam_async_desc *async_desc;
srcs = readl_relaxed(bam_addr(bdev, 0, BAM_IRQ_SRCS_EE));
if (!(srcs & P_IRQ))
return srcs;
for (i = 0; i < bdev->num_channels; i++) {
struct bam_chan *bchan = &bdev->channels[i];
if (!(srcs & BIT(i)))
continue;
pipe_stts = readl_relaxed(bam_addr(bdev, i, BAM_P_IRQ_STTS));
writel_relaxed(pipe_stts, bam_addr(bdev, i, BAM_P_IRQ_CLR));
spin_lock_irqsave(&bchan->vc.lock, flags);
async_desc = bchan->curr_txd;
if (async_desc) {
async_desc->num_desc -= async_desc->xfer_len;
async_desc->curr_desc += async_desc->xfer_len;
bchan->curr_txd = NULL;
bchan->head += async_desc->xfer_len;
bchan->head %= MAX_DESCRIPTORS;
if (!async_desc->num_desc)
vchan_cookie_complete(&async_desc->vd);
else
list_add(&async_desc->vd.node,
&bchan->vc.desc_issued);
}
spin_unlock_irqrestore(&bchan->vc.lock, flags);
}
return srcs;
}
static irqreturn_t bam_dma_irq(int irq, void *data)
{
struct bam_device *bdev = data;
u32 clr_mask = 0, srcs = 0;
srcs |= process_channel_irqs(bdev);
if (srcs & P_IRQ)
tasklet_schedule(&bdev->task);
if (srcs & BAM_IRQ)
clr_mask = readl_relaxed(bam_addr(bdev, 0, BAM_IRQ_STTS));
mb();
writel_relaxed(clr_mask, bam_addr(bdev, 0, BAM_IRQ_CLR));
return IRQ_HANDLED;
}
static enum dma_status bam_tx_status(struct dma_chan *chan, dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct bam_chan *bchan = to_bam_chan(chan);
struct virt_dma_desc *vd;
int ret;
size_t residue = 0;
unsigned int i;
unsigned long flags;
ret = dma_cookie_status(chan, cookie, txstate);
if (ret == DMA_COMPLETE)
return ret;
if (!txstate)
return bchan->paused ? DMA_PAUSED : ret;
spin_lock_irqsave(&bchan->vc.lock, flags);
vd = vchan_find_desc(&bchan->vc, cookie);
if (vd)
residue = container_of(vd, struct bam_async_desc, vd)->length;
else if (bchan->curr_txd && bchan->curr_txd->vd.tx.cookie == cookie)
for (i = 0; i < bchan->curr_txd->num_desc; i++)
residue += bchan->curr_txd->curr_desc[i].size;
spin_unlock_irqrestore(&bchan->vc.lock, flags);
dma_set_residue(txstate, residue);
if (ret == DMA_IN_PROGRESS && bchan->paused)
ret = DMA_PAUSED;
return ret;
}
static void bam_apply_new_config(struct bam_chan *bchan,
enum dma_transfer_direction dir)
{
struct bam_device *bdev = bchan->bdev;
u32 maxburst;
if (dir == DMA_DEV_TO_MEM)
maxburst = bchan->slave.src_maxburst;
else
maxburst = bchan->slave.dst_maxburst;
writel_relaxed(maxburst, bam_addr(bdev, 0, BAM_DESC_CNT_TRSHLD));
bchan->reconfigure = 0;
}
static void bam_start_dma(struct bam_chan *bchan)
{
struct virt_dma_desc *vd = vchan_next_desc(&bchan->vc);
struct bam_device *bdev = bchan->bdev;
struct bam_async_desc *async_desc;
struct bam_desc_hw *desc;
struct bam_desc_hw *fifo = PTR_ALIGN(bchan->fifo_virt,
sizeof(struct bam_desc_hw));
lockdep_assert_held(&bchan->vc.lock);
if (!vd)
return;
list_del(&vd->node);
async_desc = container_of(vd, struct bam_async_desc, vd);
bchan->curr_txd = async_desc;
if (!bchan->initialized)
bam_chan_init_hw(bchan, async_desc->dir);
if (bchan->reconfigure)
bam_apply_new_config(bchan, async_desc->dir);
desc = bchan->curr_txd->curr_desc;
if (async_desc->num_desc > MAX_DESCRIPTORS)
async_desc->xfer_len = MAX_DESCRIPTORS;
else
async_desc->xfer_len = async_desc->num_desc;
if (async_desc->num_desc == async_desc->xfer_len)
desc[async_desc->xfer_len - 1].flags = async_desc->flags;
else
desc[async_desc->xfer_len - 1].flags |= DESC_FLAG_INT;
if (bchan->tail + async_desc->xfer_len > MAX_DESCRIPTORS) {
u32 partial = MAX_DESCRIPTORS - bchan->tail;
memcpy(&fifo[bchan->tail], desc,
partial * sizeof(struct bam_desc_hw));
memcpy(fifo, &desc[partial], (async_desc->xfer_len - partial) *
sizeof(struct bam_desc_hw));
} else {
memcpy(&fifo[bchan->tail], desc,
async_desc->xfer_len * sizeof(struct bam_desc_hw));
}
bchan->tail += async_desc->xfer_len;
bchan->tail %= MAX_DESCRIPTORS;
wmb();
writel_relaxed(bchan->tail * sizeof(struct bam_desc_hw),
bam_addr(bdev, bchan->id, BAM_P_EVNT_REG));
}
static void dma_tasklet(unsigned long data)
{
struct bam_device *bdev = (struct bam_device *)data;
struct bam_chan *bchan;
unsigned long flags;
unsigned int i;
for (i = 0; i < bdev->num_channels; i++) {
bchan = &bdev->channels[i];
spin_lock_irqsave(&bchan->vc.lock, flags);
if (!list_empty(&bchan->vc.desc_issued) && !bchan->curr_txd)
bam_start_dma(bchan);
spin_unlock_irqrestore(&bchan->vc.lock, flags);
}
}
static void bam_issue_pending(struct dma_chan *chan)
{
struct bam_chan *bchan = to_bam_chan(chan);
unsigned long flags;
spin_lock_irqsave(&bchan->vc.lock, flags);
if (vchan_issue_pending(&bchan->vc) && !bchan->curr_txd)
bam_start_dma(bchan);
spin_unlock_irqrestore(&bchan->vc.lock, flags);
}
static void bam_dma_free_desc(struct virt_dma_desc *vd)
{
struct bam_async_desc *async_desc = container_of(vd,
struct bam_async_desc, vd);
kfree(async_desc);
}
static struct dma_chan *bam_dma_xlate(struct of_phandle_args *dma_spec,
struct of_dma *of)
{
struct bam_device *bdev = container_of(of->of_dma_data,
struct bam_device, common);
unsigned int request;
if (dma_spec->args_count != 1)
return NULL;
request = dma_spec->args[0];
if (request >= bdev->num_channels)
return NULL;
return dma_get_slave_channel(&(bdev->channels[request].vc.chan));
}
static int bam_init(struct bam_device *bdev)
{
u32 val;
val = readl_relaxed(bam_addr(bdev, 0, BAM_REVISION)) >> NUM_EES_SHIFT;
val &= NUM_EES_MASK;
if (bdev->ee >= val)
return -EINVAL;
val = readl_relaxed(bam_addr(bdev, 0, BAM_NUM_PIPES));
bdev->num_channels = val & BAM_NUM_PIPES_MASK;
val = readl_relaxed(bam_addr(bdev, 0, BAM_CTRL));
val |= BAM_SW_RST;
writel_relaxed(val, bam_addr(bdev, 0, BAM_CTRL));
val &= ~BAM_SW_RST;
writel_relaxed(val, bam_addr(bdev, 0, BAM_CTRL));
wmb();
val |= BAM_EN;
writel_relaxed(val, bam_addr(bdev, 0, BAM_CTRL));
writel_relaxed(DEFAULT_CNT_THRSHLD,
bam_addr(bdev, 0, BAM_DESC_CNT_TRSHLD));
writel_relaxed(BAM_CNFG_BITS_DEFAULT, bam_addr(bdev, 0, BAM_CNFG_BITS));
writel_relaxed(BAM_ERROR_EN | BAM_HRESP_ERR_EN,
bam_addr(bdev, 0, BAM_IRQ_EN));
writel_relaxed(BAM_IRQ_MSK, bam_addr(bdev, 0, BAM_IRQ_SRCS_MSK_EE));
return 0;
}
static void bam_channel_init(struct bam_device *bdev, struct bam_chan *bchan,
u32 index)
{
bchan->id = index;
bchan->bdev = bdev;
vchan_init(&bchan->vc, &bdev->common);
bchan->vc.desc_free = bam_dma_free_desc;
}
static int bam_dma_probe(struct platform_device *pdev)
{
struct bam_device *bdev;
const struct of_device_id *match;
struct resource *iores;
int ret, i;
bdev = devm_kzalloc(&pdev->dev, sizeof(*bdev), GFP_KERNEL);
if (!bdev)
return -ENOMEM;
bdev->dev = &pdev->dev;
match = of_match_node(bam_of_match, pdev->dev.of_node);
if (!match) {
dev_err(&pdev->dev, "Unsupported BAM module\n");
return -ENODEV;
}
bdev->layout = match->data;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
bdev->regs = devm_ioremap_resource(&pdev->dev, iores);
if (IS_ERR(bdev->regs))
return PTR_ERR(bdev->regs);
bdev->irq = platform_get_irq(pdev, 0);
if (bdev->irq < 0)
return bdev->irq;
ret = of_property_read_u32(pdev->dev.of_node, "qcom,ee", &bdev->ee);
if (ret) {
dev_err(bdev->dev, "Execution environment unspecified\n");
return ret;
}
bdev->bamclk = devm_clk_get(bdev->dev, "bam_clk");
if (IS_ERR(bdev->bamclk))
return PTR_ERR(bdev->bamclk);
ret = clk_prepare_enable(bdev->bamclk);
if (ret) {
dev_err(bdev->dev, "failed to prepare/enable clock\n");
return ret;
}
ret = bam_init(bdev);
if (ret)
goto err_disable_clk;
tasklet_init(&bdev->task, dma_tasklet, (unsigned long)bdev);
bdev->channels = devm_kcalloc(bdev->dev, bdev->num_channels,
sizeof(*bdev->channels), GFP_KERNEL);
if (!bdev->channels) {
ret = -ENOMEM;
goto err_tasklet_kill;
}
INIT_LIST_HEAD(&bdev->common.channels);
for (i = 0; i < bdev->num_channels; i++)
bam_channel_init(bdev, &bdev->channels[i], i);
ret = devm_request_irq(bdev->dev, bdev->irq, bam_dma_irq,
IRQF_TRIGGER_HIGH, "bam_dma", bdev);
if (ret)
goto err_bam_channel_exit;
bdev->common.dev = bdev->dev;
bdev->common.dev->dma_parms = &bdev->dma_parms;
ret = dma_set_max_seg_size(bdev->common.dev, BAM_MAX_DATA_SIZE);
if (ret) {
dev_err(bdev->dev, "cannot set maximum segment size\n");
goto err_bam_channel_exit;
}
platform_set_drvdata(pdev, bdev);
dma_cap_zero(bdev->common.cap_mask);
dma_cap_set(DMA_SLAVE, bdev->common.cap_mask);
bdev->common.directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
bdev->common.residue_granularity = DMA_RESIDUE_GRANULARITY_SEGMENT;
bdev->common.src_addr_widths = DMA_SLAVE_BUSWIDTH_4_BYTES;
bdev->common.dst_addr_widths = DMA_SLAVE_BUSWIDTH_4_BYTES;
bdev->common.device_alloc_chan_resources = bam_alloc_chan;
bdev->common.device_free_chan_resources = bam_free_chan;
bdev->common.device_prep_slave_sg = bam_prep_slave_sg;
bdev->common.device_config = bam_slave_config;
bdev->common.device_pause = bam_pause;
bdev->common.device_resume = bam_resume;
bdev->common.device_terminate_all = bam_dma_terminate_all;
bdev->common.device_issue_pending = bam_issue_pending;
bdev->common.device_tx_status = bam_tx_status;
bdev->common.dev = bdev->dev;
ret = dma_async_device_register(&bdev->common);
if (ret) {
dev_err(bdev->dev, "failed to register dma async device\n");
goto err_bam_channel_exit;
}
ret = of_dma_controller_register(pdev->dev.of_node, bam_dma_xlate,
&bdev->common);
if (ret)
goto err_unregister_dma;
return 0;
err_unregister_dma:
dma_async_device_unregister(&bdev->common);
err_bam_channel_exit:
for (i = 0; i < bdev->num_channels; i++)
tasklet_kill(&bdev->channels[i].vc.task);
err_tasklet_kill:
tasklet_kill(&bdev->task);
err_disable_clk:
clk_disable_unprepare(bdev->bamclk);
return ret;
}
static int bam_dma_remove(struct platform_device *pdev)
{
struct bam_device *bdev = platform_get_drvdata(pdev);
u32 i;
of_dma_controller_free(pdev->dev.of_node);
dma_async_device_unregister(&bdev->common);
writel_relaxed(0, bam_addr(bdev, 0, BAM_IRQ_SRCS_MSK_EE));
devm_free_irq(bdev->dev, bdev->irq, bdev);
for (i = 0; i < bdev->num_channels; i++) {
bam_dma_terminate_all(&bdev->channels[i].vc.chan);
tasklet_kill(&bdev->channels[i].vc.task);
dma_free_writecombine(bdev->dev, BAM_DESC_FIFO_SIZE,
bdev->channels[i].fifo_virt,
bdev->channels[i].fifo_phys);
}
tasklet_kill(&bdev->task);
clk_disable_unprepare(bdev->bamclk);
return 0;
}
