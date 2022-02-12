static struct msgdma_sw_desc *msgdma_get_descriptor(struct msgdma_device *mdev)
{
struct msgdma_sw_desc *desc;
unsigned long flags;
spin_lock_irqsave(&mdev->lock, flags);
desc = list_first_entry(&mdev->free_list, struct msgdma_sw_desc, node);
list_del(&desc->node);
spin_unlock_irqrestore(&mdev->lock, flags);
INIT_LIST_HEAD(&desc->tx_list);
return desc;
}
static void msgdma_free_descriptor(struct msgdma_device *mdev,
struct msgdma_sw_desc *desc)
{
struct msgdma_sw_desc *child, *next;
mdev->desc_free_cnt++;
list_add_tail(&desc->node, &mdev->free_list);
list_for_each_entry_safe(child, next, &desc->tx_list, node) {
mdev->desc_free_cnt++;
list_move_tail(&child->node, &mdev->free_list);
}
}
static void msgdma_free_desc_list(struct msgdma_device *mdev,
struct list_head *list)
{
struct msgdma_sw_desc *desc, *next;
list_for_each_entry_safe(desc, next, list, node)
msgdma_free_descriptor(mdev, desc);
}
static void msgdma_desc_config(struct msgdma_extended_desc *desc,
dma_addr_t dst, dma_addr_t src, size_t len,
u32 stride)
{
desc->read_addr_lo = lower_32_bits(src);
desc->write_addr_lo = lower_32_bits(dst);
desc->read_addr_hi = upper_32_bits(src);
desc->write_addr_hi = upper_32_bits(dst);
desc->len = len;
desc->stride = stride;
desc->burst_seq_num = 0;
desc->control = MSGDMA_DESC_CTL_TR_ERR_IRQ | MSGDMA_DESC_CTL_GO |
MSGDMA_DESC_CTL_END_ON_LEN;
}
static void msgdma_desc_config_eod(struct msgdma_extended_desc *desc)
{
desc->control |= MSGDMA_DESC_CTL_TR_COMP_IRQ;
}
static dma_cookie_t msgdma_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct msgdma_device *mdev = to_mdev(tx->chan);
struct msgdma_sw_desc *new;
dma_cookie_t cookie;
unsigned long flags;
new = tx_to_desc(tx);
spin_lock_irqsave(&mdev->lock, flags);
cookie = dma_cookie_assign(tx);
list_add_tail(&new->node, &mdev->pending_list);
spin_unlock_irqrestore(&mdev->lock, flags);
return cookie;
}
static struct dma_async_tx_descriptor *
msgdma_prep_memcpy(struct dma_chan *dchan, dma_addr_t dma_dst,
dma_addr_t dma_src, size_t len, ulong flags)
{
struct msgdma_device *mdev = to_mdev(dchan);
struct msgdma_sw_desc *new, *first = NULL;
struct msgdma_extended_desc *desc;
size_t copy;
u32 desc_cnt;
unsigned long irqflags;
desc_cnt = DIV_ROUND_UP(len, MSGDMA_MAX_TRANS_LEN);
spin_lock_irqsave(&mdev->lock, irqflags);
if (desc_cnt > mdev->desc_free_cnt) {
spin_unlock_irqrestore(&mdev->lock, irqflags);
dev_dbg(mdev->dev, "mdev %p descs are not available\n", mdev);
return NULL;
}
mdev->desc_free_cnt -= desc_cnt;
spin_unlock_irqrestore(&mdev->lock, irqflags);
do {
new = msgdma_get_descriptor(mdev);
copy = min_t(size_t, len, MSGDMA_MAX_TRANS_LEN);
desc = &new->hw_desc;
msgdma_desc_config(desc, dma_dst, dma_src, copy,
MSGDMA_DESC_STRIDE_RW);
len -= copy;
dma_src += copy;
dma_dst += copy;
if (!first)
first = new;
else
list_add_tail(&new->node, &first->tx_list);
} while (len);
msgdma_desc_config_eod(desc);
async_tx_ack(&first->async_tx);
first->async_tx.flags = flags;
return &first->async_tx;
}
static struct dma_async_tx_descriptor *
msgdma_prep_slave_sg(struct dma_chan *dchan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction dir,
unsigned long flags, void *context)
{
struct msgdma_device *mdev = to_mdev(dchan);
struct dma_slave_config *cfg = &mdev->slave_cfg;
struct msgdma_sw_desc *new, *first = NULL;
void *desc = NULL;
size_t len, avail;
dma_addr_t dma_dst, dma_src;
u32 desc_cnt = 0, i;
struct scatterlist *sg;
u32 stride;
unsigned long irqflags;
for_each_sg(sgl, sg, sg_len, i)
desc_cnt += DIV_ROUND_UP(sg_dma_len(sg), MSGDMA_MAX_TRANS_LEN);
spin_lock_irqsave(&mdev->lock, irqflags);
if (desc_cnt > mdev->desc_free_cnt) {
spin_unlock_irqrestore(&mdev->lock, irqflags);
dev_dbg(mdev->dev, "mdev %p descs are not available\n", mdev);
return NULL;
}
mdev->desc_free_cnt -= desc_cnt;
spin_unlock_irqrestore(&mdev->lock, irqflags);
avail = sg_dma_len(sgl);
while (true) {
new = msgdma_get_descriptor(mdev);
desc = &new->hw_desc;
len = min_t(size_t, avail, MSGDMA_MAX_TRANS_LEN);
if (dir == DMA_MEM_TO_DEV) {
dma_src = sg_dma_address(sgl) + sg_dma_len(sgl) - avail;
dma_dst = cfg->dst_addr;
stride = MSGDMA_DESC_STRIDE_RD;
} else {
dma_src = cfg->src_addr;
dma_dst = sg_dma_address(sgl) + sg_dma_len(sgl) - avail;
stride = MSGDMA_DESC_STRIDE_WR;
}
msgdma_desc_config(desc, dma_dst, dma_src, len, stride);
avail -= len;
if (!first)
first = new;
else
list_add_tail(&new->node, &first->tx_list);
if (avail == 0) {
if (sg_len == 0)
break;
sgl = sg_next(sgl);
if (sgl == NULL)
break;
sg_len--;
avail = sg_dma_len(sgl);
}
}
msgdma_desc_config_eod(desc);
first->async_tx.flags = flags;
return &first->async_tx;
}
static int msgdma_dma_config(struct dma_chan *dchan,
struct dma_slave_config *config)
{
struct msgdma_device *mdev = to_mdev(dchan);
memcpy(&mdev->slave_cfg, config, sizeof(*config));
return 0;
}
static void msgdma_reset(struct msgdma_device *mdev)
{
u32 val;
int ret;
iowrite32(MSGDMA_CSR_STAT_MASK, mdev->csr + MSGDMA_CSR_STATUS);
iowrite32(MSGDMA_CSR_CTL_RESET, mdev->csr + MSGDMA_CSR_CONTROL);
ret = readl_poll_timeout(mdev->csr + MSGDMA_CSR_STATUS, val,
(val & MSGDMA_CSR_STAT_RESETTING) == 0,
1, 10000);
if (ret)
dev_err(mdev->dev, "DMA channel did not reset\n");
iowrite32(MSGDMA_CSR_STAT_MASK, mdev->csr + MSGDMA_CSR_STATUS);
iowrite32(MSGDMA_CSR_CTL_STOP_ON_ERR | MSGDMA_CSR_CTL_STOP_ON_EARLY |
MSGDMA_CSR_CTL_GLOBAL_INTR, mdev->csr + MSGDMA_CSR_CONTROL);
mdev->idle = true;
}
static void msgdma_copy_one(struct msgdma_device *mdev,
struct msgdma_sw_desc *desc)
{
void __iomem *hw_desc = mdev->desc;
while (ioread32(mdev->csr + MSGDMA_CSR_STATUS) &
MSGDMA_CSR_STAT_DESC_BUF_FULL)
mdelay(1);
memcpy((void __force *)hw_desc, &desc->hw_desc,
sizeof(desc->hw_desc) - sizeof(u32));
mdev->idle = false;
wmb();
iowrite32(desc->hw_desc.control, hw_desc +
offsetof(struct msgdma_extended_desc, control));
wmb();
}
static void msgdma_copy_desc_to_fifo(struct msgdma_device *mdev,
struct msgdma_sw_desc *desc)
{
struct msgdma_sw_desc *sdesc, *next;
msgdma_copy_one(mdev, desc);
list_for_each_entry_safe(sdesc, next, &desc->tx_list, node)
msgdma_copy_one(mdev, sdesc);
}
static void msgdma_start_transfer(struct msgdma_device *mdev)
{
struct msgdma_sw_desc *desc;
if (!mdev->idle)
return;
desc = list_first_entry_or_null(&mdev->pending_list,
struct msgdma_sw_desc, node);
if (!desc)
return;
list_splice_tail_init(&mdev->pending_list, &mdev->active_list);
msgdma_copy_desc_to_fifo(mdev, desc);
}
static void msgdma_issue_pending(struct dma_chan *chan)
{
struct msgdma_device *mdev = to_mdev(chan);
unsigned long flags;
spin_lock_irqsave(&mdev->lock, flags);
msgdma_start_transfer(mdev);
spin_unlock_irqrestore(&mdev->lock, flags);
}
static void msgdma_chan_desc_cleanup(struct msgdma_device *mdev)
{
struct msgdma_sw_desc *desc, *next;
list_for_each_entry_safe(desc, next, &mdev->done_list, node) {
dma_async_tx_callback callback;
void *callback_param;
list_del(&desc->node);
callback = desc->async_tx.callback;
callback_param = desc->async_tx.callback_param;
if (callback) {
spin_unlock(&mdev->lock);
callback(callback_param);
spin_lock(&mdev->lock);
}
msgdma_free_descriptor(mdev, desc);
}
}
static void msgdma_complete_descriptor(struct msgdma_device *mdev)
{
struct msgdma_sw_desc *desc;
desc = list_first_entry_or_null(&mdev->active_list,
struct msgdma_sw_desc, node);
if (!desc)
return;
list_del(&desc->node);
dma_cookie_complete(&desc->async_tx);
list_add_tail(&desc->node, &mdev->done_list);
}
static void msgdma_free_descriptors(struct msgdma_device *mdev)
{
msgdma_free_desc_list(mdev, &mdev->active_list);
msgdma_free_desc_list(mdev, &mdev->pending_list);
msgdma_free_desc_list(mdev, &mdev->done_list);
}
static void msgdma_free_chan_resources(struct dma_chan *dchan)
{
struct msgdma_device *mdev = to_mdev(dchan);
unsigned long flags;
spin_lock_irqsave(&mdev->lock, flags);
msgdma_free_descriptors(mdev);
spin_unlock_irqrestore(&mdev->lock, flags);
kfree(mdev->sw_desq);
}
static int msgdma_alloc_chan_resources(struct dma_chan *dchan)
{
struct msgdma_device *mdev = to_mdev(dchan);
struct msgdma_sw_desc *desc;
int i;
mdev->sw_desq = kcalloc(MSGDMA_DESC_NUM, sizeof(*desc), GFP_NOWAIT);
if (!mdev->sw_desq)
return -ENOMEM;
mdev->idle = true;
mdev->desc_free_cnt = MSGDMA_DESC_NUM;
INIT_LIST_HEAD(&mdev->free_list);
for (i = 0; i < MSGDMA_DESC_NUM; i++) {
desc = mdev->sw_desq + i;
dma_async_tx_descriptor_init(&desc->async_tx, &mdev->dmachan);
desc->async_tx.tx_submit = msgdma_tx_submit;
list_add_tail(&desc->node, &mdev->free_list);
}
return MSGDMA_DESC_NUM;
}
static void msgdma_tasklet(unsigned long data)
{
struct msgdma_device *mdev = (struct msgdma_device *)data;
u32 count;
u32 __maybe_unused size;
u32 __maybe_unused status;
unsigned long flags;
spin_lock_irqsave(&mdev->lock, flags);
count = ioread32(mdev->csr + MSGDMA_CSR_RESP_FILL_LEVEL);
dev_dbg(mdev->dev, "%s (%d): response count=%d\n",
__func__, __LINE__, count);
while (count--) {
size = ioread32(mdev->resp + MSGDMA_RESP_BYTES_TRANSFERRED);
status = ioread32(mdev->resp + MSGDMA_RESP_STATUS);
msgdma_complete_descriptor(mdev);
msgdma_chan_desc_cleanup(mdev);
}
spin_unlock_irqrestore(&mdev->lock, flags);
}
static irqreturn_t msgdma_irq_handler(int irq, void *data)
{
struct msgdma_device *mdev = data;
u32 status;
status = ioread32(mdev->csr + MSGDMA_CSR_STATUS);
if ((status & MSGDMA_CSR_STAT_BUSY) == 0) {
spin_lock(&mdev->lock);
mdev->idle = true;
msgdma_start_transfer(mdev);
spin_unlock(&mdev->lock);
}
tasklet_schedule(&mdev->irq_tasklet);
iowrite32(MSGDMA_CSR_STAT_IRQ, mdev->csr + MSGDMA_CSR_STATUS);
return IRQ_HANDLED;
}
static void msgdma_dev_remove(struct msgdma_device *mdev)
{
if (!mdev)
return;
devm_free_irq(mdev->dev, mdev->irq, mdev);
tasklet_kill(&mdev->irq_tasklet);
list_del(&mdev->dmachan.device_node);
}
static int request_and_map(struct platform_device *pdev, const char *name,
struct resource **res, void __iomem **ptr)
{
struct resource *region;
struct device *device = &pdev->dev;
*res = platform_get_resource_byname(pdev, IORESOURCE_MEM, name);
if (*res == NULL) {
dev_err(device, "resource %s not defined\n", name);
return -ENODEV;
}
region = devm_request_mem_region(device, (*res)->start,
resource_size(*res), dev_name(device));
if (region == NULL) {
dev_err(device, "unable to request %s\n", name);
return -EBUSY;
}
*ptr = devm_ioremap_nocache(device, region->start,
resource_size(region));
if (*ptr == NULL) {
dev_err(device, "ioremap_nocache of %s failed!", name);
return -ENOMEM;
}
return 0;
}
static int msgdma_probe(struct platform_device *pdev)
{
struct msgdma_device *mdev;
struct dma_device *dma_dev;
struct resource *dma_res;
int ret;
mdev = devm_kzalloc(&pdev->dev, sizeof(*mdev), GFP_NOWAIT);
if (!mdev)
return -ENOMEM;
mdev->dev = &pdev->dev;
ret = request_and_map(pdev, "csr", &dma_res, &mdev->csr);
if (ret)
return ret;
ret = request_and_map(pdev, "desc", &dma_res, &mdev->desc);
if (ret)
return ret;
ret = request_and_map(pdev, "resp", &dma_res, &mdev->resp);
if (ret)
return ret;
platform_set_drvdata(pdev, mdev);
mdev->irq = platform_get_irq(pdev, 0);
if (mdev->irq < 0)
return -ENXIO;
ret = devm_request_irq(&pdev->dev, mdev->irq, msgdma_irq_handler,
0, dev_name(&pdev->dev), mdev);
if (ret)
return ret;
tasklet_init(&mdev->irq_tasklet, msgdma_tasklet, (unsigned long)mdev);
dma_cookie_init(&mdev->dmachan);
spin_lock_init(&mdev->lock);
INIT_LIST_HEAD(&mdev->active_list);
INIT_LIST_HEAD(&mdev->pending_list);
INIT_LIST_HEAD(&mdev->done_list);
INIT_LIST_HEAD(&mdev->free_list);
dma_dev = &mdev->dmadev;
dma_cap_zero(dma_dev->cap_mask);
dma_cap_set(DMA_MEMCPY, dma_dev->cap_mask);
dma_cap_set(DMA_SLAVE, dma_dev->cap_mask);
dma_dev->src_addr_widths = BIT(DMA_SLAVE_BUSWIDTH_4_BYTES);
dma_dev->dst_addr_widths = BIT(DMA_SLAVE_BUSWIDTH_4_BYTES);
dma_dev->directions = BIT(DMA_MEM_TO_DEV) | BIT(DMA_DEV_TO_MEM) |
BIT(DMA_MEM_TO_MEM);
dma_dev->residue_granularity = DMA_RESIDUE_GRANULARITY_DESCRIPTOR;
INIT_LIST_HEAD(&dma_dev->channels);
dma_dev->device_tx_status = dma_cookie_status;
dma_dev->device_issue_pending = msgdma_issue_pending;
dma_dev->dev = &pdev->dev;
dma_dev->copy_align = DMAENGINE_ALIGN_4_BYTES;
dma_dev->device_prep_dma_memcpy = msgdma_prep_memcpy;
dma_dev->device_prep_slave_sg = msgdma_prep_slave_sg;
dma_dev->device_config = msgdma_dma_config;
dma_dev->device_alloc_chan_resources = msgdma_alloc_chan_resources;
dma_dev->device_free_chan_resources = msgdma_free_chan_resources;
mdev->dmachan.device = dma_dev;
list_add_tail(&mdev->dmachan.device_node, &dma_dev->channels);
ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));
if (ret) {
dev_warn(&pdev->dev, "unable to set coherent mask to 64");
ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
goto fail;
}
msgdma_reset(mdev);
ret = dma_async_device_register(dma_dev);
if (ret)
goto fail;
dev_notice(&pdev->dev, "Altera mSGDMA driver probe success\n");
return 0;
fail:
msgdma_dev_remove(mdev);
return ret;
}
static int msgdma_remove(struct platform_device *pdev)
{
struct msgdma_device *mdev = platform_get_drvdata(pdev);
dma_async_device_unregister(&mdev->dmadev);
msgdma_dev_remove(mdev);
dev_notice(&pdev->dev, "Altera mSGDMA driver removed\n");
return 0;
}
