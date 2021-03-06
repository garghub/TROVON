static void coh901318_list_print(struct coh901318_chan *cohc,
struct coh901318_lli *lli)
{
struct coh901318_lli *l = lli;
int i = 0;
while (l) {
dev_vdbg(COHC_2_DEV(cohc), "i %d, lli %p, ctrl 0x%x, src 0x%x"
", dst 0x%x, link 0x%x virt_link_addr 0x%p\n",
i, l, l->control, l->src_addr, l->dst_addr,
l->link_addr, l->virt_link_addr);
i++;
l = l->virt_link_addr;
}
}
static int coh901318_debugfs_read(struct file *file, char __user *buf,
size_t count, loff_t *f_pos)
{
u64 started_channels = debugfs_dma_base->pm.started_channels;
int pool_count = debugfs_dma_base->pool.debugfs_pool_counter;
int i;
int ret = 0;
char *dev_buf;
char *tmp;
int dev_size;
dev_buf = kmalloc(4*1024, GFP_KERNEL);
if (dev_buf == NULL)
goto err_kmalloc;
tmp = dev_buf;
tmp += sprintf(tmp, "DMA -- enabled dma channels\n");
for (i = 0; i < U300_DMA_CHANNELS; i++)
if (started_channels & (1 << i))
tmp += sprintf(tmp, "channel %d\n", i);
tmp += sprintf(tmp, "Pool alloc nbr %d\n", pool_count);
dev_size = tmp - dev_buf;
if (*f_pos > dev_size)
goto out;
if (count > dev_size - *f_pos)
count = dev_size - *f_pos;
if (copy_to_user(buf, dev_buf + *f_pos, count))
ret = -EINVAL;
ret = count;
*f_pos += count;
out:
kfree(dev_buf);
return ret;
err_kmalloc:
return 0;
}
static int __init init_coh901318_debugfs(void)
{
dma_dentry = debugfs_create_dir("dma", NULL);
(void) debugfs_create_file("status",
S_IFREG | S_IRUGO,
dma_dentry, NULL,
&coh901318_debugfs_status_operations);
return 0;
}
static void __exit exit_coh901318_debugfs(void)
{
debugfs_remove_recursive(dma_dentry);
}
static inline struct coh901318_chan *to_coh901318_chan(struct dma_chan *chan)
{
return container_of(chan, struct coh901318_chan, chan);
}
static inline const struct coh901318_params *
cohc_chan_param(struct coh901318_chan *cohc)
{
return &chan_config[cohc->id].param;
}
static inline const struct coh_dma_channel *
cohc_chan_conf(struct coh901318_chan *cohc)
{
return &chan_config[cohc->id];
}
static void enable_powersave(struct coh901318_chan *cohc)
{
unsigned long flags;
struct powersave *pm = &cohc->base->pm;
spin_lock_irqsave(&pm->lock, flags);
pm->started_channels &= ~(1ULL << cohc->id);
spin_unlock_irqrestore(&pm->lock, flags);
}
static void disable_powersave(struct coh901318_chan *cohc)
{
unsigned long flags;
struct powersave *pm = &cohc->base->pm;
spin_lock_irqsave(&pm->lock, flags);
pm->started_channels |= (1ULL << cohc->id);
spin_unlock_irqrestore(&pm->lock, flags);
}
static inline int coh901318_set_ctrl(struct coh901318_chan *cohc, u32 control)
{
int channel = cohc->id;
void __iomem *virtbase = cohc->base->virtbase;
writel(control,
virtbase + COH901318_CX_CTRL +
COH901318_CX_CTRL_SPACING * channel);
return 0;
}
static inline int coh901318_set_conf(struct coh901318_chan *cohc, u32 conf)
{
int channel = cohc->id;
void __iomem *virtbase = cohc->base->virtbase;
writel(conf,
virtbase + COH901318_CX_CFG +
COH901318_CX_CFG_SPACING*channel);
return 0;
}
static int coh901318_start(struct coh901318_chan *cohc)
{
u32 val;
int channel = cohc->id;
void __iomem *virtbase = cohc->base->virtbase;
disable_powersave(cohc);
val = readl(virtbase + COH901318_CX_CFG +
COH901318_CX_CFG_SPACING * channel);
val |= COH901318_CX_CFG_CH_ENABLE;
writel(val, virtbase + COH901318_CX_CFG +
COH901318_CX_CFG_SPACING * channel);
return 0;
}
static int coh901318_prep_linked_list(struct coh901318_chan *cohc,
struct coh901318_lli *lli)
{
int channel = cohc->id;
void __iomem *virtbase = cohc->base->virtbase;
BUG_ON(readl(virtbase + COH901318_CX_STAT +
COH901318_CX_STAT_SPACING*channel) &
COH901318_CX_STAT_ACTIVE);
writel(lli->src_addr,
virtbase + COH901318_CX_SRC_ADDR +
COH901318_CX_SRC_ADDR_SPACING * channel);
writel(lli->dst_addr, virtbase +
COH901318_CX_DST_ADDR +
COH901318_CX_DST_ADDR_SPACING * channel);
writel(lli->link_addr, virtbase + COH901318_CX_LNK_ADDR +
COH901318_CX_LNK_ADDR_SPACING * channel);
writel(lli->control, virtbase + COH901318_CX_CTRL +
COH901318_CX_CTRL_SPACING * channel);
return 0;
}
static struct coh901318_desc *
coh901318_desc_get(struct coh901318_chan *cohc)
{
struct coh901318_desc *desc;
if (list_empty(&cohc->free)) {
desc = kzalloc(sizeof(struct coh901318_desc), GFP_NOWAIT);
if (desc == NULL)
goto out;
INIT_LIST_HEAD(&desc->node);
dma_async_tx_descriptor_init(&desc->desc, &cohc->chan);
} else {
desc = list_first_entry(&cohc->free,
struct coh901318_desc,
node);
list_del(&desc->node);
desc->sg = NULL;
desc->sg_len = 0;
desc->desc.callback = NULL;
desc->desc.callback_param = NULL;
}
out:
return desc;
}
static void
coh901318_desc_free(struct coh901318_chan *cohc, struct coh901318_desc *cohd)
{
list_add_tail(&cohd->node, &cohc->free);
}
static void
coh901318_desc_submit(struct coh901318_chan *cohc, struct coh901318_desc *desc)
{
list_add_tail(&desc->node, &cohc->active);
}
static struct coh901318_desc *
coh901318_first_active_get(struct coh901318_chan *cohc)
{
struct coh901318_desc *d;
if (list_empty(&cohc->active))
return NULL;
d = list_first_entry(&cohc->active,
struct coh901318_desc,
node);
return d;
}
static void
coh901318_desc_remove(struct coh901318_desc *cohd)
{
list_del(&cohd->node);
}
static void
coh901318_desc_queue(struct coh901318_chan *cohc, struct coh901318_desc *desc)
{
list_add_tail(&desc->node, &cohc->queue);
}
static struct coh901318_desc *
coh901318_first_queued(struct coh901318_chan *cohc)
{
struct coh901318_desc *d;
if (list_empty(&cohc->queue))
return NULL;
d = list_first_entry(&cohc->queue,
struct coh901318_desc,
node);
return d;
}
static inline u32 coh901318_get_bytes_in_lli(struct coh901318_lli *in_lli)
{
struct coh901318_lli *lli = in_lli;
u32 bytes = 0;
while (lli) {
bytes += lli->control & COH901318_CX_CTRL_TC_VALUE_MASK;
lli = lli->virt_link_addr;
}
return bytes;
}
static u32 coh901318_get_bytes_left(struct dma_chan *chan)
{
struct coh901318_chan *cohc = to_coh901318_chan(chan);
struct coh901318_desc *cohd;
struct list_head *pos;
unsigned long flags;
u32 left = 0;
int i = 0;
spin_lock_irqsave(&cohc->lock, flags);
list_for_each(pos, &cohc->active) {
cohd = list_entry(pos, struct coh901318_desc, node);
if (i == 0) {
struct coh901318_lli *lli;
dma_addr_t ladd;
left = readl(cohc->base->virtbase +
COH901318_CX_CTRL +
COH901318_CX_CTRL_SPACING * cohc->id) &
COH901318_CX_CTRL_TC_VALUE_MASK;
ladd = readl(cohc->base->virtbase +
COH901318_CX_LNK_ADDR +
COH901318_CX_LNK_ADDR_SPACING *
cohc->id) &
~COH901318_CX_LNK_LINK_IMMEDIATE;
if (!ladd)
continue;
lli = cohd->lli;
while (lli && lli->link_addr != ladd)
lli = lli->virt_link_addr;
if (lli)
lli = lli->virt_link_addr;
left += coh901318_get_bytes_in_lli(lli);
} else {
left += coh901318_get_bytes_in_lli(cohd->lli);
}
i++;
}
list_for_each(pos, &cohc->queue) {
cohd = list_entry(pos, struct coh901318_desc, node);
left += coh901318_get_bytes_in_lli(cohd->lli);
}
spin_unlock_irqrestore(&cohc->lock, flags);
return left;
}
static void coh901318_pause(struct dma_chan *chan)
{
u32 val;
unsigned long flags;
struct coh901318_chan *cohc = to_coh901318_chan(chan);
int channel = cohc->id;
void __iomem *virtbase = cohc->base->virtbase;
spin_lock_irqsave(&cohc->lock, flags);
val = readl(virtbase + COH901318_CX_CFG +
COH901318_CX_CFG_SPACING * channel);
if ((val & COH901318_CX_CTRL_TC_ENABLE) == 0 &&
(val & COH901318_CX_CFG_CH_ENABLE))
cohc->stopped = 1;
val &= ~COH901318_CX_CFG_CH_ENABLE;
writel(val, virtbase + COH901318_CX_CFG +
COH901318_CX_CFG_SPACING * channel);
writel(val, virtbase + COH901318_CX_CFG +
COH901318_CX_CFG_SPACING * channel);
while (readl(virtbase + COH901318_CX_STAT+COH901318_CX_STAT_SPACING *
channel) & COH901318_CX_STAT_ACTIVE)
cpu_relax();
if ((readl(virtbase + COH901318_CX_CTRL+COH901318_CX_CTRL_SPACING *
channel) & COH901318_CX_CTRL_TC_VALUE_MASK) > 0)
cohc->stopped = 1;
enable_powersave(cohc);
spin_unlock_irqrestore(&cohc->lock, flags);
}
static void coh901318_resume(struct dma_chan *chan)
{
u32 val;
unsigned long flags;
struct coh901318_chan *cohc = to_coh901318_chan(chan);
int channel = cohc->id;
spin_lock_irqsave(&cohc->lock, flags);
disable_powersave(cohc);
if (cohc->stopped) {
val = readl(cohc->base->virtbase + COH901318_CX_CFG +
COH901318_CX_CFG_SPACING * channel);
val |= COH901318_CX_CFG_CH_ENABLE;
writel(val, cohc->base->virtbase + COH901318_CX_CFG +
COH901318_CX_CFG_SPACING*channel);
cohc->stopped = 0;
}
spin_unlock_irqrestore(&cohc->lock, flags);
}
bool coh901318_filter_id(struct dma_chan *chan, void *chan_id)
{
unsigned int ch_nr = (unsigned int) chan_id;
if (ch_nr == to_coh901318_chan(chan)->id)
return true;
return false;
}
static bool coh901318_filter_base_and_id(struct dma_chan *chan, void *data)
{
struct coh901318_filter_args *args = data;
if (&args->base->dma_slave == chan->device &&
args->ch_nr == to_coh901318_chan(chan)->id)
return true;
return false;
}
static struct dma_chan *coh901318_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct coh901318_filter_args args = {
.base = ofdma->of_dma_data,
.ch_nr = dma_spec->args[0],
};
dma_cap_mask_t cap;
dma_cap_zero(cap);
dma_cap_set(DMA_SLAVE, cap);
return dma_request_channel(cap, coh901318_filter_base_and_id, &args);
}
static int coh901318_config(struct coh901318_chan *cohc,
struct coh901318_params *param)
{
unsigned long flags;
const struct coh901318_params *p;
int channel = cohc->id;
void __iomem *virtbase = cohc->base->virtbase;
spin_lock_irqsave(&cohc->lock, flags);
if (param)
p = param;
else
p = cohc_chan_param(cohc);
if (channel < 32) {
writel(1 << channel, virtbase + COH901318_BE_INT_CLEAR1);
writel(1 << channel, virtbase + COH901318_TC_INT_CLEAR1);
} else {
writel(1 << (channel - 32), virtbase +
COH901318_BE_INT_CLEAR2);
writel(1 << (channel - 32), virtbase +
COH901318_TC_INT_CLEAR2);
}
coh901318_set_conf(cohc, p->config);
coh901318_set_ctrl(cohc, p->ctrl_lli_last);
spin_unlock_irqrestore(&cohc->lock, flags);
return 0;
}
static struct coh901318_desc *coh901318_queue_start(struct coh901318_chan *cohc)
{
struct coh901318_desc *cohd;
cohd = coh901318_first_queued(cohc);
if (cohd != NULL) {
coh901318_desc_remove(cohd);
cohc->busy = 1;
coh901318_desc_submit(cohc, cohd);
coh901318_set_conf(cohc, cohd->head_config);
coh901318_set_ctrl(cohc, cohd->head_ctrl);
coh901318_prep_linked_list(cohc, cohd->lli);
coh901318_start(cohc);
}
return cohd;
}
static void dma_tasklet(unsigned long data)
{
struct coh901318_chan *cohc = (struct coh901318_chan *) data;
struct coh901318_desc *cohd_fin;
unsigned long flags;
dma_async_tx_callback callback;
void *callback_param;
dev_vdbg(COHC_2_DEV(cohc), "[%s] chan_id %d"
" nbr_active_done %ld\n", __func__,
cohc->id, cohc->nbr_active_done);
spin_lock_irqsave(&cohc->lock, flags);
cohd_fin = coh901318_first_active_get(cohc);
if (cohd_fin == NULL)
goto err;
callback = cohd_fin->desc.callback;
callback_param = cohd_fin->desc.callback_param;
dma_cookie_complete(&cohd_fin->desc);
coh901318_lli_free(&cohc->base->pool, &cohd_fin->lli);
coh901318_desc_remove(cohd_fin);
coh901318_desc_free(cohc, cohd_fin);
spin_unlock_irqrestore(&cohc->lock, flags);
if (callback)
callback(callback_param);
spin_lock_irqsave(&cohc->lock, flags);
cohc->nbr_active_done--;
if (cohc->nbr_active_done) {
dev_dbg(COHC_2_DEV(cohc), "scheduling tasklet again, new IRQs "
"came in while we were scheduling this tasklet\n");
if (cohc_chan_conf(cohc)->priority_high)
tasklet_hi_schedule(&cohc->tasklet);
else
tasklet_schedule(&cohc->tasklet);
}
spin_unlock_irqrestore(&cohc->lock, flags);
return;
err:
spin_unlock_irqrestore(&cohc->lock, flags);
dev_err(COHC_2_DEV(cohc), "[%s] No active dma desc\n", __func__);
}
static void dma_tc_handle(struct coh901318_chan *cohc)
{
if (!cohc->allocated) {
dev_err(COHC_2_DEV(cohc), "spurious interrupt from "
"unallocated channel\n");
return;
}
spin_lock(&cohc->lock);
BUG_ON(list_empty(&cohc->active));
cohc->nbr_active_done++;
if (coh901318_queue_start(cohc) == NULL)
cohc->busy = 0;
spin_unlock(&cohc->lock);
if (cohc_chan_conf(cohc)->priority_high)
tasklet_hi_schedule(&cohc->tasklet);
else
tasklet_schedule(&cohc->tasklet);
}
static irqreturn_t dma_irq_handler(int irq, void *dev_id)
{
u32 status1;
u32 status2;
int i;
int ch;
struct coh901318_base *base = dev_id;
struct coh901318_chan *cohc;
void __iomem *virtbase = base->virtbase;
status1 = readl(virtbase + COH901318_INT_STATUS1);
status2 = readl(virtbase + COH901318_INT_STATUS2);
if (unlikely(status1 == 0 && status2 == 0)) {
dev_warn(base->dev, "spurious DMA IRQ from no channel!\n");
return IRQ_HANDLED;
}
while (status1) {
i = ffs(status1) - 1;
ch = i;
cohc = &base->chans[ch];
spin_lock(&cohc->lock);
status1 &= ~(1 << i);
if (test_bit(i, virtbase + COH901318_BE_INT_STATUS1)) {
dev_crit(COHC_2_DEV(cohc),
"DMA bus error on channel %d!\n", ch);
BUG_ON(1);
__set_bit(i, virtbase + COH901318_BE_INT_CLEAR1);
} else {
if (unlikely(!test_bit(i, virtbase +
COH901318_TC_INT_STATUS1))) {
dev_warn(COHC_2_DEV(cohc),
"ignoring interrupt not caused by terminal count on channel %d\n", ch);
BUG_ON(1);
__set_bit(i, virtbase + COH901318_TC_INT_CLEAR1);
} else {
if (!(readl(virtbase + COH901318_CX_STAT +
COH901318_CX_STAT_SPACING*ch) &
COH901318_CX_STAT_ENABLED)) {
enable_powersave(cohc);
}
__set_bit(i, virtbase + COH901318_TC_INT_CLEAR1);
dma_tc_handle(cohc);
}
}
spin_unlock(&cohc->lock);
}
while (status2) {
i = ffs(status2) - 1;
ch = i + 32;
cohc = &base->chans[ch];
spin_lock(&cohc->lock);
status2 &= ~(1 << i);
if (test_bit(i, virtbase + COH901318_BE_INT_STATUS2)) {
dev_crit(COHC_2_DEV(cohc),
"DMA bus error on channel %d!\n", ch);
BUG_ON(1);
__set_bit(i, virtbase + COH901318_BE_INT_CLEAR2);
} else {
if (unlikely(!test_bit(i, virtbase +
COH901318_TC_INT_STATUS2))) {
dev_warn(COHC_2_DEV(cohc),
"ignoring interrupt not caused by terminal count on channel %d\n", ch);
__set_bit(i, virtbase + COH901318_TC_INT_CLEAR2);
BUG_ON(1);
} else {
if (!(readl(virtbase + COH901318_CX_STAT +
COH901318_CX_STAT_SPACING*ch) &
COH901318_CX_STAT_ENABLED)) {
enable_powersave(cohc);
}
__set_bit(i, virtbase + COH901318_TC_INT_CLEAR2);
dma_tc_handle(cohc);
}
}
spin_unlock(&cohc->lock);
}
return IRQ_HANDLED;
}
static int coh901318_alloc_chan_resources(struct dma_chan *chan)
{
struct coh901318_chan *cohc = to_coh901318_chan(chan);
unsigned long flags;
dev_vdbg(COHC_2_DEV(cohc), "[%s] DMA channel %d\n",
__func__, cohc->id);
if (chan->client_count > 1)
return -EBUSY;
spin_lock_irqsave(&cohc->lock, flags);
coh901318_config(cohc, NULL);
cohc->allocated = 1;
dma_cookie_init(chan);
spin_unlock_irqrestore(&cohc->lock, flags);
return 1;
}
static void
coh901318_free_chan_resources(struct dma_chan *chan)
{
struct coh901318_chan *cohc = to_coh901318_chan(chan);
int channel = cohc->id;
unsigned long flags;
spin_lock_irqsave(&cohc->lock, flags);
writel(0x00000000U, cohc->base->virtbase + COH901318_CX_CFG +
COH901318_CX_CFG_SPACING*channel);
writel(0x00000000U, cohc->base->virtbase + COH901318_CX_CTRL +
COH901318_CX_CTRL_SPACING*channel);
cohc->allocated = 0;
spin_unlock_irqrestore(&cohc->lock, flags);
chan->device->device_control(chan, DMA_TERMINATE_ALL, 0);
}
static dma_cookie_t
coh901318_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct coh901318_desc *cohd = container_of(tx, struct coh901318_desc,
desc);
struct coh901318_chan *cohc = to_coh901318_chan(tx->chan);
unsigned long flags;
dma_cookie_t cookie;
spin_lock_irqsave(&cohc->lock, flags);
cookie = dma_cookie_assign(tx);
coh901318_desc_queue(cohc, cohd);
spin_unlock_irqrestore(&cohc->lock, flags);
return cookie;
}
static struct dma_async_tx_descriptor *
coh901318_prep_memcpy(struct dma_chan *chan, dma_addr_t dest, dma_addr_t src,
size_t size, unsigned long flags)
{
struct coh901318_lli *lli;
struct coh901318_desc *cohd;
unsigned long flg;
struct coh901318_chan *cohc = to_coh901318_chan(chan);
int lli_len;
u32 ctrl_last = cohc_chan_param(cohc)->ctrl_lli_last;
int ret;
spin_lock_irqsave(&cohc->lock, flg);
dev_vdbg(COHC_2_DEV(cohc),
"[%s] channel %d src 0x%x dest 0x%x size %d\n",
__func__, cohc->id, src, dest, size);
if (flags & DMA_PREP_INTERRUPT)
ctrl_last |= COH901318_CX_CTRL_TC_IRQ_ENABLE;
lli_len = size >> MAX_DMA_PACKET_SIZE_SHIFT;
if ((lli_len << MAX_DMA_PACKET_SIZE_SHIFT) < size)
lli_len++;
lli = coh901318_lli_alloc(&cohc->base->pool, lli_len);
if (lli == NULL)
goto err;
ret = coh901318_lli_fill_memcpy(
&cohc->base->pool, lli, src, size, dest,
cohc_chan_param(cohc)->ctrl_lli_chained,
ctrl_last);
if (ret)
goto err;
COH_DBG(coh901318_list_print(cohc, lli));
cohd = coh901318_desc_get(cohc);
cohd->lli = lli;
cohd->flags = flags;
cohd->desc.tx_submit = coh901318_tx_submit;
spin_unlock_irqrestore(&cohc->lock, flg);
return &cohd->desc;
err:
spin_unlock_irqrestore(&cohc->lock, flg);
return NULL;
}
static struct dma_async_tx_descriptor *
coh901318_prep_slave_sg(struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long flags, void *context)
{
struct coh901318_chan *cohc = to_coh901318_chan(chan);
struct coh901318_lli *lli;
struct coh901318_desc *cohd;
const struct coh901318_params *params;
struct scatterlist *sg;
int len = 0;
int size;
int i;
u32 ctrl_chained = cohc_chan_param(cohc)->ctrl_lli_chained;
u32 ctrl = cohc_chan_param(cohc)->ctrl_lli;
u32 ctrl_last = cohc_chan_param(cohc)->ctrl_lli_last;
u32 config;
unsigned long flg;
int ret;
if (!sgl)
goto out;
if (sg_dma_len(sgl) == 0)
goto out;
spin_lock_irqsave(&cohc->lock, flg);
dev_vdbg(COHC_2_DEV(cohc), "[%s] sg_len %d dir %d\n",
__func__, sg_len, direction);
if (flags & DMA_PREP_INTERRUPT)
ctrl_last |= COH901318_CX_CTRL_TC_IRQ_ENABLE;
params = cohc_chan_param(cohc);
config = params->config;
ctrl_chained |= cohc->ctrl;
ctrl_last |= cohc->ctrl;
ctrl |= cohc->ctrl;
if (direction == DMA_MEM_TO_DEV) {
u32 tx_flags = COH901318_CX_CTRL_PRDD_SOURCE |
COH901318_CX_CTRL_SRC_ADDR_INC_ENABLE;
config |= COH901318_CX_CFG_RM_MEMORY_TO_PRIMARY;
ctrl_chained |= tx_flags;
ctrl_last |= tx_flags;
ctrl |= tx_flags;
} else if (direction == DMA_DEV_TO_MEM) {
u32 rx_flags = COH901318_CX_CTRL_PRDD_DEST |
COH901318_CX_CTRL_DST_ADDR_INC_ENABLE;
config |= COH901318_CX_CFG_RM_PRIMARY_TO_MEMORY;
ctrl_chained |= rx_flags;
ctrl_last |= rx_flags;
ctrl |= rx_flags;
} else
goto err_direction;
for_each_sg(sgl, sg, sg_len, i) {
unsigned int factor;
size = sg_dma_len(sg);
if (size <= MAX_DMA_PACKET_SIZE) {
len++;
continue;
}
factor = size >> MAX_DMA_PACKET_SIZE_SHIFT;
if ((factor << MAX_DMA_PACKET_SIZE_SHIFT) < size)
factor++;
len += factor;
}
pr_debug("Allocate %d lli:s for this transfer\n", len);
lli = coh901318_lli_alloc(&cohc->base->pool, len);
if (lli == NULL)
goto err_dma_alloc;
ret = coh901318_lli_fill_sg(&cohc->base->pool, lli, sgl, sg_len,
cohc->addr,
ctrl_chained,
ctrl,
ctrl_last,
direction, COH901318_CX_CTRL_TC_IRQ_ENABLE);
if (ret)
goto err_lli_fill;
COH_DBG(coh901318_list_print(cohc, lli));
cohd = coh901318_desc_get(cohc);
cohd->head_config = config;
cohd->head_ctrl = lli->control;
cohd->dir = direction;
cohd->flags = flags;
cohd->desc.tx_submit = coh901318_tx_submit;
cohd->lli = lli;
spin_unlock_irqrestore(&cohc->lock, flg);
return &cohd->desc;
err_lli_fill:
err_dma_alloc:
err_direction:
spin_unlock_irqrestore(&cohc->lock, flg);
out:
return NULL;
}
static enum dma_status
coh901318_tx_status(struct dma_chan *chan, dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct coh901318_chan *cohc = to_coh901318_chan(chan);
enum dma_status ret;
ret = dma_cookie_status(chan, cookie, txstate);
if (ret == DMA_SUCCESS)
return ret;
dma_set_residue(txstate, coh901318_get_bytes_left(chan));
if (ret == DMA_IN_PROGRESS && cohc->stopped)
ret = DMA_PAUSED;
return ret;
}
static void
coh901318_issue_pending(struct dma_chan *chan)
{
struct coh901318_chan *cohc = to_coh901318_chan(chan);
unsigned long flags;
spin_lock_irqsave(&cohc->lock, flags);
if (!cohc->busy)
coh901318_queue_start(cohc);
spin_unlock_irqrestore(&cohc->lock, flags);
}
static void coh901318_dma_set_runtimeconfig(struct dma_chan *chan,
struct dma_slave_config *config)
{
struct coh901318_chan *cohc = to_coh901318_chan(chan);
dma_addr_t addr;
enum dma_slave_buswidth addr_width;
u32 maxburst;
u32 ctrl = 0;
int i = 0;
if (config->direction == DMA_DEV_TO_MEM) {
addr = config->src_addr;
addr_width = config->src_addr_width;
maxburst = config->src_maxburst;
} else if (config->direction == DMA_MEM_TO_DEV) {
addr = config->dst_addr;
addr_width = config->dst_addr_width;
maxburst = config->dst_maxburst;
} else {
dev_err(COHC_2_DEV(cohc), "illegal channel mode\n");
return;
}
dev_dbg(COHC_2_DEV(cohc), "configure channel for %d byte transfers\n",
addr_width);
switch (addr_width) {
case DMA_SLAVE_BUSWIDTH_1_BYTE:
ctrl |=
COH901318_CX_CTRL_SRC_BUS_SIZE_8_BITS |
COH901318_CX_CTRL_DST_BUS_SIZE_8_BITS;
while (i < ARRAY_SIZE(burst_sizes)) {
if (burst_sizes[i].burst_8bit <= maxburst)
break;
i++;
}
break;
case DMA_SLAVE_BUSWIDTH_2_BYTES:
ctrl |=
COH901318_CX_CTRL_SRC_BUS_SIZE_16_BITS |
COH901318_CX_CTRL_DST_BUS_SIZE_16_BITS;
while (i < ARRAY_SIZE(burst_sizes)) {
if (burst_sizes[i].burst_16bit <= maxburst)
break;
i++;
}
break;
case DMA_SLAVE_BUSWIDTH_4_BYTES:
ctrl |=
COH901318_CX_CTRL_SRC_BUS_SIZE_32_BITS |
COH901318_CX_CTRL_DST_BUS_SIZE_32_BITS;
while (i < ARRAY_SIZE(burst_sizes)) {
if (burst_sizes[i].burst_32bit <= maxburst)
break;
i++;
}
break;
default:
dev_err(COHC_2_DEV(cohc),
"bad runtimeconfig: alien address width\n");
return;
}
ctrl |= burst_sizes[i].reg;
dev_dbg(COHC_2_DEV(cohc),
"selected burst size %d bytes for address width %d bytes, maxburst %d\n",
burst_sizes[i].burst_8bit, addr_width, maxburst);
cohc->addr = addr;
cohc->ctrl = ctrl;
}
static int
coh901318_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
unsigned long flags;
struct coh901318_chan *cohc = to_coh901318_chan(chan);
struct coh901318_desc *cohd;
void __iomem *virtbase = cohc->base->virtbase;
if (cmd == DMA_SLAVE_CONFIG) {
struct dma_slave_config *config =
(struct dma_slave_config *) arg;
coh901318_dma_set_runtimeconfig(chan, config);
return 0;
}
if (cmd == DMA_PAUSE) {
coh901318_pause(chan);
return 0;
}
if (cmd == DMA_RESUME) {
coh901318_resume(chan);
return 0;
}
if (cmd != DMA_TERMINATE_ALL)
return -ENXIO;
coh901318_pause(chan);
spin_lock_irqsave(&cohc->lock, flags);
if (cohc->id < 32) {
writel(1 << cohc->id, virtbase + COH901318_BE_INT_CLEAR1);
writel(1 << cohc->id, virtbase + COH901318_TC_INT_CLEAR1);
} else {
writel(1 << (cohc->id - 32), virtbase +
COH901318_BE_INT_CLEAR2);
writel(1 << (cohc->id - 32), virtbase +
COH901318_TC_INT_CLEAR2);
}
enable_powersave(cohc);
while ((cohd = coh901318_first_active_get(cohc))) {
coh901318_lli_free(&cohc->base->pool, &cohd->lli);
coh901318_desc_remove(cohd);
coh901318_desc_free(cohc, cohd);
}
while ((cohd = coh901318_first_queued(cohc))) {
coh901318_lli_free(&cohc->base->pool, &cohd->lli);
coh901318_desc_remove(cohd);
coh901318_desc_free(cohc, cohd);
}
cohc->nbr_active_done = 0;
cohc->busy = 0;
spin_unlock_irqrestore(&cohc->lock, flags);
return 0;
}
void coh901318_base_init(struct dma_device *dma, const int *pick_chans,
struct coh901318_base *base)
{
int chans_i;
int i = 0;
struct coh901318_chan *cohc;
INIT_LIST_HEAD(&dma->channels);
for (chans_i = 0; pick_chans[chans_i] != -1; chans_i += 2) {
for (i = pick_chans[chans_i]; i <= pick_chans[chans_i+1]; i++) {
cohc = &base->chans[i];
cohc->base = base;
cohc->chan.device = dma;
cohc->id = i;
spin_lock_init(&cohc->lock);
cohc->nbr_active_done = 0;
cohc->busy = 0;
INIT_LIST_HEAD(&cohc->free);
INIT_LIST_HEAD(&cohc->active);
INIT_LIST_HEAD(&cohc->queue);
tasklet_init(&cohc->tasklet, dma_tasklet,
(unsigned long) cohc);
list_add_tail(&cohc->chan.device_node,
&dma->channels);
}
}
}
static int __init coh901318_probe(struct platform_device *pdev)
{
int err = 0;
struct coh901318_base *base;
int irq;
struct resource *io;
io = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!io)
return -ENODEV;
if (devm_request_mem_region(&pdev->dev,
io->start,
resource_size(io),
pdev->dev.driver->name) == NULL)
return -ENOMEM;
base = devm_kzalloc(&pdev->dev,
ALIGN(sizeof(struct coh901318_base), 4) +
U300_DMA_CHANNELS *
sizeof(struct coh901318_chan),
GFP_KERNEL);
if (!base)
return -ENOMEM;
base->chans = ((void *)base) + ALIGN(sizeof(struct coh901318_base), 4);
base->virtbase = devm_ioremap(&pdev->dev, io->start, resource_size(io));
if (!base->virtbase)
return -ENOMEM;
base->dev = &pdev->dev;
spin_lock_init(&base->pm.lock);
base->pm.started_channels = 0;
COH901318_DEBUGFS_ASSIGN(debugfs_dma_base, base);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
err = devm_request_irq(&pdev->dev, irq, dma_irq_handler, IRQF_DISABLED,
"coh901318", base);
if (err)
return err;
err = coh901318_pool_create(&base->pool, &pdev->dev,
sizeof(struct coh901318_lli),
32);
if (err)
return err;
coh901318_base_init(&base->dma_slave, dma_slave_channels,
base);
dma_cap_zero(base->dma_slave.cap_mask);
dma_cap_set(DMA_SLAVE, base->dma_slave.cap_mask);
base->dma_slave.device_alloc_chan_resources = coh901318_alloc_chan_resources;
base->dma_slave.device_free_chan_resources = coh901318_free_chan_resources;
base->dma_slave.device_prep_slave_sg = coh901318_prep_slave_sg;
base->dma_slave.device_tx_status = coh901318_tx_status;
base->dma_slave.device_issue_pending = coh901318_issue_pending;
base->dma_slave.device_control = coh901318_control;
base->dma_slave.dev = &pdev->dev;
err = dma_async_device_register(&base->dma_slave);
if (err)
goto err_register_slave;
coh901318_base_init(&base->dma_memcpy, dma_memcpy_channels,
base);
dma_cap_zero(base->dma_memcpy.cap_mask);
dma_cap_set(DMA_MEMCPY, base->dma_memcpy.cap_mask);
base->dma_memcpy.device_alloc_chan_resources = coh901318_alloc_chan_resources;
base->dma_memcpy.device_free_chan_resources = coh901318_free_chan_resources;
base->dma_memcpy.device_prep_dma_memcpy = coh901318_prep_memcpy;
base->dma_memcpy.device_tx_status = coh901318_tx_status;
base->dma_memcpy.device_issue_pending = coh901318_issue_pending;
base->dma_memcpy.device_control = coh901318_control;
base->dma_memcpy.dev = &pdev->dev;
base->dma_memcpy.copy_align = 2;
err = dma_async_device_register(&base->dma_memcpy);
if (err)
goto err_register_memcpy;
err = of_dma_controller_register(pdev->dev.of_node, coh901318_xlate,
base);
if (err)
goto err_register_of_dma;
platform_set_drvdata(pdev, base);
dev_info(&pdev->dev, "Initialized COH901318 DMA on virtual base 0x%08x\n",
(u32) base->virtbase);
return err;
err_register_of_dma:
dma_async_device_unregister(&base->dma_memcpy);
err_register_memcpy:
dma_async_device_unregister(&base->dma_slave);
err_register_slave:
coh901318_pool_destroy(&base->pool);
return err;
}
static int coh901318_remove(struct platform_device *pdev)
{
struct coh901318_base *base = platform_get_drvdata(pdev);
of_dma_controller_free(pdev->dev.of_node);
dma_async_device_unregister(&base->dma_memcpy);
dma_async_device_unregister(&base->dma_slave);
coh901318_pool_destroy(&base->pool);
return 0;
}
int __init coh901318_init(void)
{
return platform_driver_probe(&coh901318_driver, coh901318_probe);
}
void __exit coh901318_exit(void)
{
platform_driver_unregister(&coh901318_driver);
}
