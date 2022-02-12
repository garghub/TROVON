static int hidma_is_chan_enabled(int state)
{
switch (state) {
case HIDMA_CH_ENABLED:
case HIDMA_CH_RUNNING:
return true;
default:
return false;
}
}
void hidma_ll_free(struct hidma_lldev *lldev, u32 tre_ch)
{
struct hidma_tre *tre;
if (tre_ch >= lldev->nr_tres) {
dev_err(lldev->dev, "invalid TRE number in free:%d", tre_ch);
return;
}
tre = &lldev->trepool[tre_ch];
if (atomic_read(&tre->allocated) != true) {
dev_err(lldev->dev, "trying to free an unused TRE:%d", tre_ch);
return;
}
atomic_set(&tre->allocated, 0);
}
int hidma_ll_request(struct hidma_lldev *lldev, u32 sig, const char *dev_name,
void (*callback)(void *data), void *data, u32 *tre_ch)
{
unsigned int i;
struct hidma_tre *tre;
u32 *tre_local;
if (!tre_ch || !lldev)
return -EINVAL;
for (i = 0; i < lldev->nr_tres - 1; i++) {
if (atomic_add_unless(&lldev->trepool[i].allocated, 1, 1))
break;
}
if (i == (lldev->nr_tres - 1))
return -ENOMEM;
tre = &lldev->trepool[i];
tre->dma_sig = sig;
tre->dev_name = dev_name;
tre->callback = callback;
tre->data = data;
tre->idx = i;
tre->status = 0;
tre->queued = 0;
tre->err_code = 0;
tre->err_info = 0;
tre->lldev = lldev;
tre_local = &tre->tre_local[0];
tre_local[HIDMA_TRE_CFG_IDX] = HIDMA_TRE_MEMCPY;
tre_local[HIDMA_TRE_CFG_IDX] |= (lldev->chidx & 0xFF) << 8;
tre_local[HIDMA_TRE_CFG_IDX] |= BIT(16);
*tre_ch = i;
if (callback)
callback(data);
return 0;
}
static void hidma_ll_tre_complete(unsigned long arg)
{
struct hidma_lldev *lldev = (struct hidma_lldev *)arg;
struct hidma_tre *tre;
while (kfifo_out(&lldev->handoff_fifo, &tre, 1)) {
if (tre->callback)
tre->callback(tre->data);
}
}
static int hidma_post_completed(struct hidma_lldev *lldev, int tre_iterator,
u8 err_info, u8 err_code)
{
struct hidma_tre *tre;
unsigned long flags;
spin_lock_irqsave(&lldev->lock, flags);
tre = lldev->pending_tre_list[tre_iterator / HIDMA_TRE_SIZE];
if (!tre) {
spin_unlock_irqrestore(&lldev->lock, flags);
dev_warn(lldev->dev, "tre_index [%d] and tre out of sync\n",
tre_iterator / HIDMA_TRE_SIZE);
return -EINVAL;
}
lldev->pending_tre_list[tre->tre_index] = NULL;
lldev->pending_tre_count--;
if (lldev->pending_tre_count < 0) {
dev_warn(lldev->dev, "tre count mismatch on completion");
lldev->pending_tre_count = 0;
}
spin_unlock_irqrestore(&lldev->lock, flags);
tre->err_info = err_info;
tre->err_code = err_code;
tre->queued = 0;
kfifo_put(&lldev->handoff_fifo, tre);
tasklet_schedule(&lldev->task);
return 0;
}
static int hidma_handle_tre_completion(struct hidma_lldev *lldev)
{
u32 evre_ring_size = lldev->evre_ring_size;
u32 tre_ring_size = lldev->tre_ring_size;
u32 err_info, err_code, evre_write_off;
u32 tre_iterator, evre_iterator;
u32 num_completed = 0;
evre_write_off = readl_relaxed(lldev->evca + HIDMA_EVCA_WRITE_PTR_REG);
tre_iterator = lldev->tre_processed_off;
evre_iterator = lldev->evre_processed_off;
if ((evre_write_off > evre_ring_size) ||
(evre_write_off % HIDMA_EVRE_SIZE)) {
dev_err(lldev->dev, "HW reports invalid EVRE write offset\n");
return 0;
}
while ((evre_iterator != evre_write_off)) {
u32 *current_evre = lldev->evre_ring + evre_iterator;
u32 cfg;
cfg = current_evre[HIDMA_EVRE_CFG_IDX];
err_info = cfg >> HIDMA_EVRE_ERRINFO_BIT_POS;
err_info &= HIDMA_EVRE_ERRINFO_MASK;
err_code =
(cfg >> HIDMA_EVRE_CODE_BIT_POS) & HIDMA_EVRE_CODE_MASK;
if (hidma_post_completed(lldev, tre_iterator, err_info,
err_code))
break;
HIDMA_INCREMENT_ITERATOR(tre_iterator, HIDMA_TRE_SIZE,
tre_ring_size);
HIDMA_INCREMENT_ITERATOR(evre_iterator, HIDMA_EVRE_SIZE,
evre_ring_size);
evre_write_off =
readl_relaxed(lldev->evca + HIDMA_EVCA_WRITE_PTR_REG);
num_completed++;
}
if (num_completed) {
u32 evre_read_off = (lldev->evre_processed_off +
HIDMA_EVRE_SIZE * num_completed);
u32 tre_read_off = (lldev->tre_processed_off +
HIDMA_TRE_SIZE * num_completed);
evre_read_off = evre_read_off % evre_ring_size;
tre_read_off = tre_read_off % tre_ring_size;
writel(evre_read_off, lldev->evca + HIDMA_EVCA_DOORBELL_REG);
lldev->tre_processed_off = tre_read_off;
lldev->evre_processed_off = evre_read_off;
}
return num_completed;
}
void hidma_cleanup_pending_tre(struct hidma_lldev *lldev, u8 err_info,
u8 err_code)
{
u32 tre_iterator;
u32 tre_ring_size = lldev->tre_ring_size;
int num_completed = 0;
u32 tre_read_off;
tre_iterator = lldev->tre_processed_off;
while (lldev->pending_tre_count) {
if (hidma_post_completed(lldev, tre_iterator, err_info,
err_code))
break;
HIDMA_INCREMENT_ITERATOR(tre_iterator, HIDMA_TRE_SIZE,
tre_ring_size);
num_completed++;
}
tre_read_off = (lldev->tre_processed_off +
HIDMA_TRE_SIZE * num_completed);
tre_read_off = tre_read_off % tre_ring_size;
lldev->tre_processed_off = tre_read_off;
}
static int hidma_ll_reset(struct hidma_lldev *lldev)
{
u32 val;
int ret;
val = readl(lldev->trca + HIDMA_TRCA_CTRLSTS_REG);
val &= ~(HIDMA_CH_CONTROL_MASK << 16);
val |= HIDMA_CH_RESET << 16;
writel(val, lldev->trca + HIDMA_TRCA_CTRLSTS_REG);
ret = readl_poll_timeout(lldev->trca + HIDMA_TRCA_CTRLSTS_REG, val,
HIDMA_CH_STATE(val) == HIDMA_CH_DISABLED,
1000, 10000);
if (ret) {
dev_err(lldev->dev, "transfer channel did not reset\n");
return ret;
}
val = readl(lldev->evca + HIDMA_EVCA_CTRLSTS_REG);
val &= ~(HIDMA_CH_CONTROL_MASK << 16);
val |= HIDMA_CH_RESET << 16;
writel(val, lldev->evca + HIDMA_EVCA_CTRLSTS_REG);
ret = readl_poll_timeout(lldev->evca + HIDMA_EVCA_CTRLSTS_REG, val,
HIDMA_CH_STATE(val) == HIDMA_CH_DISABLED,
1000, 10000);
if (ret)
return ret;
lldev->trch_state = HIDMA_CH_DISABLED;
lldev->evch_state = HIDMA_CH_DISABLED;
return 0;
}
irqreturn_t hidma_ll_inthandler(int chirq, void *arg)
{
struct hidma_lldev *lldev = arg;
u32 status;
u32 enable;
u32 cause;
status = readl_relaxed(lldev->evca + HIDMA_EVCA_IRQ_STAT_REG);
enable = readl_relaxed(lldev->evca + HIDMA_EVCA_IRQ_EN_REG);
cause = status & enable;
while (cause) {
if (cause & HIDMA_ERR_INT_MASK) {
dev_err(lldev->dev, "error 0x%x, disabling...\n",
cause);
writel(cause, lldev->evca + HIDMA_EVCA_IRQ_CLR_REG);
hidma_ll_disable(lldev);
hidma_cleanup_pending_tre(lldev, 0xFF,
HIDMA_EVRE_STATUS_ERROR);
goto out;
}
hidma_handle_tre_completion(lldev);
writel_relaxed(cause, lldev->evca + HIDMA_EVCA_IRQ_CLR_REG);
status = readl_relaxed(lldev->evca + HIDMA_EVCA_IRQ_STAT_REG);
enable = readl_relaxed(lldev->evca + HIDMA_EVCA_IRQ_EN_REG);
cause = status & enable;
}
out:
return IRQ_HANDLED;
}
int hidma_ll_enable(struct hidma_lldev *lldev)
{
u32 val;
int ret;
val = readl(lldev->evca + HIDMA_EVCA_CTRLSTS_REG);
val &= ~(HIDMA_CH_CONTROL_MASK << 16);
val |= HIDMA_CH_ENABLE << 16;
writel(val, lldev->evca + HIDMA_EVCA_CTRLSTS_REG);
ret = readl_poll_timeout(lldev->evca + HIDMA_EVCA_CTRLSTS_REG, val,
hidma_is_chan_enabled(HIDMA_CH_STATE(val)),
1000, 10000);
if (ret) {
dev_err(lldev->dev, "event channel did not get enabled\n");
return ret;
}
val = readl(lldev->trca + HIDMA_TRCA_CTRLSTS_REG);
val &= ~(HIDMA_CH_CONTROL_MASK << 16);
val |= HIDMA_CH_ENABLE << 16;
writel(val, lldev->trca + HIDMA_TRCA_CTRLSTS_REG);
ret = readl_poll_timeout(lldev->trca + HIDMA_TRCA_CTRLSTS_REG, val,
hidma_is_chan_enabled(HIDMA_CH_STATE(val)),
1000, 10000);
if (ret) {
dev_err(lldev->dev, "transfer channel did not get enabled\n");
return ret;
}
lldev->trch_state = HIDMA_CH_ENABLED;
lldev->evch_state = HIDMA_CH_ENABLED;
return 0;
}
void hidma_ll_start(struct hidma_lldev *lldev)
{
unsigned long irqflags;
spin_lock_irqsave(&lldev->lock, irqflags);
writel(lldev->tre_write_offset, lldev->trca + HIDMA_TRCA_DOORBELL_REG);
spin_unlock_irqrestore(&lldev->lock, irqflags);
}
bool hidma_ll_isenabled(struct hidma_lldev *lldev)
{
u32 val;
val = readl(lldev->trca + HIDMA_TRCA_CTRLSTS_REG);
lldev->trch_state = HIDMA_CH_STATE(val);
val = readl(lldev->evca + HIDMA_EVCA_CTRLSTS_REG);
lldev->evch_state = HIDMA_CH_STATE(val);
if (hidma_is_chan_enabled(lldev->trch_state) &&
hidma_is_chan_enabled(lldev->evch_state))
return true;
return false;
}
void hidma_ll_queue_request(struct hidma_lldev *lldev, u32 tre_ch)
{
struct hidma_tre *tre;
unsigned long flags;
tre = &lldev->trepool[tre_ch];
spin_lock_irqsave(&lldev->lock, flags);
tre->tre_index = lldev->tre_write_offset / HIDMA_TRE_SIZE;
lldev->pending_tre_list[tre->tre_index] = tre;
memcpy(lldev->tre_ring + lldev->tre_write_offset,
&tre->tre_local[0], HIDMA_TRE_SIZE);
tre->err_code = 0;
tre->err_info = 0;
tre->queued = 1;
lldev->pending_tre_count++;
lldev->tre_write_offset = (lldev->tre_write_offset + HIDMA_TRE_SIZE)
% lldev->tre_ring_size;
spin_unlock_irqrestore(&lldev->lock, flags);
}
int hidma_ll_disable(struct hidma_lldev *lldev)
{
u32 val;
int ret;
val = readl(lldev->evca + HIDMA_EVCA_CTRLSTS_REG);
lldev->evch_state = HIDMA_CH_STATE(val);
val = readl(lldev->trca + HIDMA_TRCA_CTRLSTS_REG);
lldev->trch_state = HIDMA_CH_STATE(val);
if ((lldev->trch_state == HIDMA_CH_SUSPENDED) ||
(lldev->evch_state == HIDMA_CH_SUSPENDED))
return 0;
if ((lldev->trch_state == HIDMA_CH_STOPPED) ||
(lldev->evch_state == HIDMA_CH_STOPPED))
return 0;
val = readl(lldev->trca + HIDMA_TRCA_CTRLSTS_REG);
val &= ~(HIDMA_CH_CONTROL_MASK << 16);
val |= HIDMA_CH_SUSPEND << 16;
writel(val, lldev->trca + HIDMA_TRCA_CTRLSTS_REG);
ret = readl_poll_timeout(lldev->trca + HIDMA_TRCA_CTRLSTS_REG, val,
HIDMA_CH_STATE(val) == HIDMA_CH_SUSPENDED,
1000, 10000);
if (ret)
return ret;
val = readl(lldev->evca + HIDMA_EVCA_CTRLSTS_REG);
val &= ~(HIDMA_CH_CONTROL_MASK << 16);
val |= HIDMA_CH_SUSPEND << 16;
writel(val, lldev->evca + HIDMA_EVCA_CTRLSTS_REG);
ret = readl_poll_timeout(lldev->evca + HIDMA_EVCA_CTRLSTS_REG, val,
HIDMA_CH_STATE(val) == HIDMA_CH_SUSPENDED,
1000, 10000);
if (ret)
return ret;
lldev->trch_state = HIDMA_CH_SUSPENDED;
lldev->evch_state = HIDMA_CH_SUSPENDED;
return 0;
}
void hidma_ll_set_transfer_params(struct hidma_lldev *lldev, u32 tre_ch,
dma_addr_t src, dma_addr_t dest, u32 len,
u32 flags)
{
struct hidma_tre *tre;
u32 *tre_local;
if (tre_ch >= lldev->nr_tres) {
dev_err(lldev->dev, "invalid TRE number in transfer params:%d",
tre_ch);
return;
}
tre = &lldev->trepool[tre_ch];
if (atomic_read(&tre->allocated) != true) {
dev_err(lldev->dev, "trying to set params on an unused TRE:%d",
tre_ch);
return;
}
tre_local = &tre->tre_local[0];
tre_local[HIDMA_TRE_LEN_IDX] = len;
tre_local[HIDMA_TRE_SRC_LOW_IDX] = lower_32_bits(src);
tre_local[HIDMA_TRE_SRC_HI_IDX] = upper_32_bits(src);
tre_local[HIDMA_TRE_DEST_LOW_IDX] = lower_32_bits(dest);
tre_local[HIDMA_TRE_DEST_HI_IDX] = upper_32_bits(dest);
tre->int_flags = flags;
}
int hidma_ll_setup(struct hidma_lldev *lldev)
{
int rc;
u64 addr;
u32 val;
u32 nr_tres = lldev->nr_tres;
lldev->pending_tre_count = 0;
lldev->tre_processed_off = 0;
lldev->evre_processed_off = 0;
lldev->tre_write_offset = 0;
writel(0, lldev->evca + HIDMA_EVCA_IRQ_EN_REG);
val = readl(lldev->evca + HIDMA_EVCA_IRQ_STAT_REG);
writel(val, lldev->evca + HIDMA_EVCA_IRQ_CLR_REG);
rc = hidma_ll_reset(lldev);
if (rc)
return rc;
val = readl(lldev->evca + HIDMA_EVCA_IRQ_STAT_REG);
writel(val, lldev->evca + HIDMA_EVCA_IRQ_CLR_REG);
writel(0, lldev->evca + HIDMA_EVCA_IRQ_EN_REG);
addr = lldev->tre_dma;
writel(lower_32_bits(addr), lldev->trca + HIDMA_TRCA_RING_LOW_REG);
writel(upper_32_bits(addr), lldev->trca + HIDMA_TRCA_RING_HIGH_REG);
writel(lldev->tre_ring_size, lldev->trca + HIDMA_TRCA_RING_LEN_REG);
addr = lldev->evre_dma;
writel(lower_32_bits(addr), lldev->evca + HIDMA_EVCA_RING_LOW_REG);
writel(upper_32_bits(addr), lldev->evca + HIDMA_EVCA_RING_HIGH_REG);
writel(HIDMA_EVRE_SIZE * nr_tres,
lldev->evca + HIDMA_EVCA_RING_LEN_REG);
val = readl(lldev->evca + HIDMA_EVCA_INTCTRL_REG);
val &= ~0xF;
val |= 0x1;
writel(val, lldev->evca + HIDMA_EVCA_INTCTRL_REG);
writel(ENABLE_IRQS, lldev->evca + HIDMA_EVCA_IRQ_CLR_REG);
writel(ENABLE_IRQS, lldev->evca + HIDMA_EVCA_IRQ_EN_REG);
return hidma_ll_enable(lldev);
}
struct hidma_lldev *hidma_ll_init(struct device *dev, u32 nr_tres,
void __iomem *trca, void __iomem *evca,
u8 chidx)
{
u32 required_bytes;
struct hidma_lldev *lldev;
int rc;
size_t sz;
if (!trca || !evca || !dev || !nr_tres)
return NULL;
if (nr_tres < 4)
return NULL;
nr_tres += 1;
lldev = devm_kzalloc(dev, sizeof(struct hidma_lldev), GFP_KERNEL);
if (!lldev)
return NULL;
lldev->evca = evca;
lldev->trca = trca;
lldev->dev = dev;
sz = sizeof(struct hidma_tre);
lldev->trepool = devm_kcalloc(lldev->dev, nr_tres, sz, GFP_KERNEL);
if (!lldev->trepool)
return NULL;
required_bytes = sizeof(lldev->pending_tre_list[0]);
lldev->pending_tre_list = devm_kcalloc(dev, nr_tres, required_bytes,
GFP_KERNEL);
if (!lldev->pending_tre_list)
return NULL;
sz = (HIDMA_TRE_SIZE + 1) * nr_tres;
lldev->tre_ring = dmam_alloc_coherent(dev, sz, &lldev->tre_dma,
GFP_KERNEL);
if (!lldev->tre_ring)
return NULL;
memset(lldev->tre_ring, 0, (HIDMA_TRE_SIZE + 1) * nr_tres);
lldev->tre_ring_size = HIDMA_TRE_SIZE * nr_tres;
lldev->nr_tres = nr_tres;
if (!IS_ALIGNED(lldev->tre_dma, HIDMA_TRE_SIZE)) {
u8 tre_ring_shift;
tre_ring_shift = lldev->tre_dma % HIDMA_TRE_SIZE;
tre_ring_shift = HIDMA_TRE_SIZE - tre_ring_shift;
lldev->tre_dma += tre_ring_shift;
lldev->tre_ring += tre_ring_shift;
}
sz = (HIDMA_EVRE_SIZE + 1) * nr_tres;
lldev->evre_ring = dmam_alloc_coherent(dev, sz, &lldev->evre_dma,
GFP_KERNEL);
if (!lldev->evre_ring)
return NULL;
memset(lldev->evre_ring, 0, (HIDMA_EVRE_SIZE + 1) * nr_tres);
lldev->evre_ring_size = HIDMA_EVRE_SIZE * nr_tres;
if (!IS_ALIGNED(lldev->evre_dma, HIDMA_EVRE_SIZE)) {
u8 evre_ring_shift;
evre_ring_shift = lldev->evre_dma % HIDMA_EVRE_SIZE;
evre_ring_shift = HIDMA_EVRE_SIZE - evre_ring_shift;
lldev->evre_dma += evre_ring_shift;
lldev->evre_ring += evre_ring_shift;
}
lldev->nr_tres = nr_tres;
lldev->chidx = chidx;
sz = nr_tres * sizeof(struct hidma_tre *);
rc = kfifo_alloc(&lldev->handoff_fifo, sz, GFP_KERNEL);
if (rc)
return NULL;
rc = hidma_ll_setup(lldev);
if (rc)
return NULL;
spin_lock_init(&lldev->lock);
tasklet_init(&lldev->task, hidma_ll_tre_complete, (unsigned long)lldev);
lldev->initialized = 1;
writel(ENABLE_IRQS, lldev->evca + HIDMA_EVCA_IRQ_EN_REG);
return lldev;
}
int hidma_ll_uninit(struct hidma_lldev *lldev)
{
u32 required_bytes;
int rc = 0;
u32 val;
if (!lldev)
return -ENODEV;
if (!lldev->initialized)
return 0;
lldev->initialized = 0;
required_bytes = sizeof(struct hidma_tre) * lldev->nr_tres;
tasklet_kill(&lldev->task);
memset(lldev->trepool, 0, required_bytes);
lldev->trepool = NULL;
lldev->pending_tre_count = 0;
lldev->tre_write_offset = 0;
rc = hidma_ll_reset(lldev);
val = readl(lldev->evca + HIDMA_EVCA_IRQ_STAT_REG);
writel(val, lldev->evca + HIDMA_EVCA_IRQ_CLR_REG);
writel(0, lldev->evca + HIDMA_EVCA_IRQ_EN_REG);
return rc;
}
enum dma_status hidma_ll_status(struct hidma_lldev *lldev, u32 tre_ch)
{
enum dma_status ret = DMA_ERROR;
struct hidma_tre *tre;
unsigned long flags;
u8 err_code;
spin_lock_irqsave(&lldev->lock, flags);
tre = &lldev->trepool[tre_ch];
err_code = tre->err_code;
if (err_code & HIDMA_EVRE_STATUS_COMPLETE)
ret = DMA_COMPLETE;
else if (err_code & HIDMA_EVRE_STATUS_ERROR)
ret = DMA_ERROR;
else
ret = DMA_IN_PROGRESS;
spin_unlock_irqrestore(&lldev->lock, flags);
return ret;
}
