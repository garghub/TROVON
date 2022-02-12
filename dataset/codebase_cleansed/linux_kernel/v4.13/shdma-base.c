static void shdma_chan_xfer_ld_queue(struct shdma_chan *schan)
{
struct shdma_dev *sdev = to_shdma_dev(schan->dma_chan.device);
const struct shdma_ops *ops = sdev->ops;
struct shdma_desc *sdesc;
if (ops->channel_busy(schan))
return;
list_for_each_entry(sdesc, &schan->ld_queue, node)
if (sdesc->mark == DESC_SUBMITTED) {
ops->start_xfer(schan, sdesc);
break;
}
}
static dma_cookie_t shdma_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct shdma_desc *chunk, *c, *desc =
container_of(tx, struct shdma_desc, async_tx);
struct shdma_chan *schan = to_shdma_chan(tx->chan);
dma_async_tx_callback callback = tx->callback;
dma_cookie_t cookie;
bool power_up;
spin_lock_irq(&schan->chan_lock);
power_up = list_empty(&schan->ld_queue);
cookie = dma_cookie_assign(tx);
list_for_each_entry_safe(chunk, c, desc->node.prev, node) {
if (chunk != desc && (chunk->mark == DESC_IDLE ||
chunk->async_tx.cookie > 0 ||
chunk->async_tx.cookie == -EBUSY ||
&chunk->node == &schan->ld_free))
break;
chunk->mark = DESC_SUBMITTED;
if (chunk->chunks == 1) {
chunk->async_tx.callback = callback;
chunk->async_tx.callback_param = tx->callback_param;
} else {
chunk->async_tx.callback = NULL;
}
chunk->cookie = cookie;
list_move_tail(&chunk->node, &schan->ld_queue);
dev_dbg(schan->dev, "submit #%d@%p on %d\n",
tx->cookie, &chunk->async_tx, schan->id);
}
if (power_up) {
int ret;
schan->pm_state = SHDMA_PM_BUSY;
ret = pm_runtime_get(schan->dev);
spin_unlock_irq(&schan->chan_lock);
if (ret < 0)
dev_err(schan->dev, "%s(): GET = %d\n", __func__, ret);
pm_runtime_barrier(schan->dev);
spin_lock_irq(&schan->chan_lock);
if (schan->pm_state != SHDMA_PM_ESTABLISHED) {
struct shdma_dev *sdev =
to_shdma_dev(schan->dma_chan.device);
const struct shdma_ops *ops = sdev->ops;
dev_dbg(schan->dev, "Bring up channel %d\n",
schan->id);
ops->setup_xfer(schan, schan->slave_id);
if (schan->pm_state == SHDMA_PM_PENDING)
shdma_chan_xfer_ld_queue(schan);
schan->pm_state = SHDMA_PM_ESTABLISHED;
}
} else {
schan->pm_state = SHDMA_PM_PENDING;
}
spin_unlock_irq(&schan->chan_lock);
return cookie;
}
static struct shdma_desc *shdma_get_desc(struct shdma_chan *schan)
{
struct shdma_desc *sdesc;
list_for_each_entry(sdesc, &schan->ld_free, node)
if (sdesc->mark != DESC_PREPARED) {
BUG_ON(sdesc->mark != DESC_IDLE);
list_del(&sdesc->node);
return sdesc;
}
return NULL;
}
static int shdma_setup_slave(struct shdma_chan *schan, dma_addr_t slave_addr)
{
struct shdma_dev *sdev = to_shdma_dev(schan->dma_chan.device);
const struct shdma_ops *ops = sdev->ops;
int ret, match;
if (schan->dev->of_node) {
match = schan->hw_req;
ret = ops->set_slave(schan, match, slave_addr, true);
if (ret < 0)
return ret;
} else {
match = schan->real_slave_id;
}
if (schan->real_slave_id < 0 || schan->real_slave_id >= slave_num)
return -EINVAL;
if (test_and_set_bit(schan->real_slave_id, shdma_slave_used))
return -EBUSY;
ret = ops->set_slave(schan, match, slave_addr, false);
if (ret < 0) {
clear_bit(schan->real_slave_id, shdma_slave_used);
return ret;
}
schan->slave_id = schan->real_slave_id;
return 0;
}
static int shdma_alloc_chan_resources(struct dma_chan *chan)
{
struct shdma_chan *schan = to_shdma_chan(chan);
struct shdma_dev *sdev = to_shdma_dev(schan->dma_chan.device);
const struct shdma_ops *ops = sdev->ops;
struct shdma_desc *desc;
struct shdma_slave *slave = chan->private;
int ret, i;
if (slave) {
schan->real_slave_id = slave->slave_id;
ret = shdma_setup_slave(schan, 0);
if (ret < 0)
goto esetslave;
} else {
schan->slave_id = -EINVAL;
}
schan->desc = kcalloc(NR_DESCS_PER_CHANNEL,
sdev->desc_size, GFP_KERNEL);
if (!schan->desc) {
ret = -ENOMEM;
goto edescalloc;
}
schan->desc_num = NR_DESCS_PER_CHANNEL;
for (i = 0; i < NR_DESCS_PER_CHANNEL; i++) {
desc = ops->embedded_desc(schan->desc, i);
dma_async_tx_descriptor_init(&desc->async_tx,
&schan->dma_chan);
desc->async_tx.tx_submit = shdma_tx_submit;
desc->mark = DESC_IDLE;
list_add(&desc->node, &schan->ld_free);
}
return NR_DESCS_PER_CHANNEL;
edescalloc:
if (slave)
esetslave:
clear_bit(slave->slave_id, shdma_slave_used);
chan->private = NULL;
return ret;
}
bool shdma_chan_filter(struct dma_chan *chan, void *arg)
{
struct shdma_chan *schan;
struct shdma_dev *sdev;
int slave_id = (long)arg;
int ret;
if (chan->device->device_alloc_chan_resources !=
shdma_alloc_chan_resources)
return false;
schan = to_shdma_chan(chan);
sdev = to_shdma_dev(chan->device);
if (schan->dev->of_node) {
ret = sdev->ops->set_slave(schan, slave_id, 0, true);
if (ret < 0)
return false;
schan->real_slave_id = schan->slave_id;
return true;
}
if (slave_id < 0) {
dev_warn(sdev->dma_dev.dev, "invalid slave ID passed to dma_request_slave\n");
return true;
}
if (slave_id >= slave_num)
return false;
ret = sdev->ops->set_slave(schan, slave_id, 0, true);
if (ret < 0)
return false;
schan->real_slave_id = slave_id;
return true;
}
static dma_async_tx_callback __ld_cleanup(struct shdma_chan *schan, bool all)
{
struct shdma_desc *desc, *_desc;
bool head_acked = false;
dma_cookie_t cookie = 0;
dma_async_tx_callback callback = NULL;
struct dmaengine_desc_callback cb;
unsigned long flags;
LIST_HEAD(cyclic_list);
memset(&cb, 0, sizeof(cb));
spin_lock_irqsave(&schan->chan_lock, flags);
list_for_each_entry_safe(desc, _desc, &schan->ld_queue, node) {
struct dma_async_tx_descriptor *tx = &desc->async_tx;
BUG_ON(tx->cookie > 0 && tx->cookie != desc->cookie);
BUG_ON(desc->mark != DESC_SUBMITTED &&
desc->mark != DESC_COMPLETED &&
desc->mark != DESC_WAITING);
if (!all && desc->mark == DESC_SUBMITTED &&
desc->cookie != cookie)
break;
if (tx->cookie > 0)
cookie = tx->cookie;
if (desc->mark == DESC_COMPLETED && desc->chunks == 1) {
if (schan->dma_chan.completed_cookie != desc->cookie - 1)
dev_dbg(schan->dev,
"Completing cookie %d, expected %d\n",
desc->cookie,
schan->dma_chan.completed_cookie + 1);
schan->dma_chan.completed_cookie = desc->cookie;
}
if (desc->mark == DESC_COMPLETED && tx->callback) {
desc->mark = DESC_WAITING;
dmaengine_desc_get_callback(tx, &cb);
callback = tx->callback;
dev_dbg(schan->dev, "descriptor #%d@%p on %d callback\n",
tx->cookie, tx, schan->id);
BUG_ON(desc->chunks != 1);
break;
}
if (tx->cookie > 0 || tx->cookie == -EBUSY) {
if (desc->mark == DESC_COMPLETED) {
BUG_ON(tx->cookie < 0);
desc->mark = DESC_WAITING;
}
head_acked = async_tx_test_ack(tx);
} else {
switch (desc->mark) {
case DESC_COMPLETED:
desc->mark = DESC_WAITING;
case DESC_WAITING:
if (head_acked)
async_tx_ack(&desc->async_tx);
}
}
dev_dbg(schan->dev, "descriptor %p #%d completed.\n",
tx, tx->cookie);
if (((desc->mark == DESC_COMPLETED ||
desc->mark == DESC_WAITING) &&
async_tx_test_ack(&desc->async_tx)) || all) {
if (all || !desc->cyclic) {
desc->mark = DESC_IDLE;
list_move(&desc->node, &schan->ld_free);
} else {
desc->mark = DESC_SUBMITTED;
list_move_tail(&desc->node, &cyclic_list);
}
if (list_empty(&schan->ld_queue)) {
dev_dbg(schan->dev, "Bring down channel %d\n", schan->id);
pm_runtime_put(schan->dev);
schan->pm_state = SHDMA_PM_ESTABLISHED;
} else if (schan->pm_state == SHDMA_PM_PENDING) {
shdma_chan_xfer_ld_queue(schan);
}
}
}
if (all && !callback)
schan->dma_chan.completed_cookie = schan->dma_chan.cookie;
list_splice_tail(&cyclic_list, &schan->ld_queue);
spin_unlock_irqrestore(&schan->chan_lock, flags);
dmaengine_desc_callback_invoke(&cb, NULL);
return callback;
}
static void shdma_chan_ld_cleanup(struct shdma_chan *schan, bool all)
{
while (__ld_cleanup(schan, all))
;
}
static void shdma_free_chan_resources(struct dma_chan *chan)
{
struct shdma_chan *schan = to_shdma_chan(chan);
struct shdma_dev *sdev = to_shdma_dev(chan->device);
const struct shdma_ops *ops = sdev->ops;
LIST_HEAD(list);
spin_lock_irq(&schan->chan_lock);
ops->halt_channel(schan);
spin_unlock_irq(&schan->chan_lock);
if (!list_empty(&schan->ld_queue))
shdma_chan_ld_cleanup(schan, true);
if (schan->slave_id >= 0) {
clear_bit(schan->slave_id, shdma_slave_used);
chan->private = NULL;
}
schan->real_slave_id = 0;
spin_lock_irq(&schan->chan_lock);
list_splice_init(&schan->ld_free, &list);
schan->desc_num = 0;
spin_unlock_irq(&schan->chan_lock);
kfree(schan->desc);
}
static struct shdma_desc *shdma_add_desc(struct shdma_chan *schan,
unsigned long flags, dma_addr_t *dst, dma_addr_t *src, size_t *len,
struct shdma_desc **first, enum dma_transfer_direction direction)
{
struct shdma_dev *sdev = to_shdma_dev(schan->dma_chan.device);
const struct shdma_ops *ops = sdev->ops;
struct shdma_desc *new;
size_t copy_size = *len;
if (!copy_size)
return NULL;
new = shdma_get_desc(schan);
if (!new) {
dev_err(schan->dev, "No free link descriptor available\n");
return NULL;
}
ops->desc_setup(schan, new, *src, *dst, &copy_size);
if (!*first) {
new->async_tx.cookie = -EBUSY;
*first = new;
} else {
new->async_tx.cookie = -EINVAL;
}
dev_dbg(schan->dev,
"chaining (%zu/%zu)@%pad -> %pad with %p, cookie %d\n",
copy_size, *len, src, dst, &new->async_tx,
new->async_tx.cookie);
new->mark = DESC_PREPARED;
new->async_tx.flags = flags;
new->direction = direction;
new->partial = 0;
*len -= copy_size;
if (direction == DMA_MEM_TO_MEM || direction == DMA_MEM_TO_DEV)
*src += copy_size;
if (direction == DMA_MEM_TO_MEM || direction == DMA_DEV_TO_MEM)
*dst += copy_size;
return new;
}
static struct dma_async_tx_descriptor *shdma_prep_sg(struct shdma_chan *schan,
struct scatterlist *sgl, unsigned int sg_len, dma_addr_t *addr,
enum dma_transfer_direction direction, unsigned long flags, bool cyclic)
{
struct scatterlist *sg;
struct shdma_desc *first = NULL, *new = NULL ;
LIST_HEAD(tx_list);
int chunks = 0;
unsigned long irq_flags;
int i;
for_each_sg(sgl, sg, sg_len, i)
chunks += DIV_ROUND_UP(sg_dma_len(sg), schan->max_xfer_len);
spin_lock_irqsave(&schan->chan_lock, irq_flags);
for_each_sg(sgl, sg, sg_len, i) {
dma_addr_t sg_addr = sg_dma_address(sg);
size_t len = sg_dma_len(sg);
if (!len)
goto err_get_desc;
do {
dev_dbg(schan->dev, "Add SG #%d@%p[%zu], dma %pad\n",
i, sg, len, &sg_addr);
if (direction == DMA_DEV_TO_MEM)
new = shdma_add_desc(schan, flags,
&sg_addr, addr, &len, &first,
direction);
else
new = shdma_add_desc(schan, flags,
addr, &sg_addr, &len, &first,
direction);
if (!new)
goto err_get_desc;
new->cyclic = cyclic;
if (cyclic)
new->chunks = 1;
else
new->chunks = chunks--;
list_add_tail(&new->node, &tx_list);
} while (len);
}
if (new != first)
new->async_tx.cookie = -ENOSPC;
list_splice_tail(&tx_list, &schan->ld_free);
spin_unlock_irqrestore(&schan->chan_lock, irq_flags);
return &first->async_tx;
err_get_desc:
list_for_each_entry(new, &tx_list, node)
new->mark = DESC_IDLE;
list_splice(&tx_list, &schan->ld_free);
spin_unlock_irqrestore(&schan->chan_lock, irq_flags);
return NULL;
}
static struct dma_async_tx_descriptor *shdma_prep_memcpy(
struct dma_chan *chan, dma_addr_t dma_dest, dma_addr_t dma_src,
size_t len, unsigned long flags)
{
struct shdma_chan *schan = to_shdma_chan(chan);
struct scatterlist sg;
if (!chan || !len)
return NULL;
BUG_ON(!schan->desc_num);
sg_init_table(&sg, 1);
sg_set_page(&sg, pfn_to_page(PFN_DOWN(dma_src)), len,
offset_in_page(dma_src));
sg_dma_address(&sg) = dma_src;
sg_dma_len(&sg) = len;
return shdma_prep_sg(schan, &sg, 1, &dma_dest, DMA_MEM_TO_MEM,
flags, false);
}
static struct dma_async_tx_descriptor *shdma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl, unsigned int sg_len,
enum dma_transfer_direction direction, unsigned long flags, void *context)
{
struct shdma_chan *schan = to_shdma_chan(chan);
struct shdma_dev *sdev = to_shdma_dev(schan->dma_chan.device);
const struct shdma_ops *ops = sdev->ops;
int slave_id = schan->slave_id;
dma_addr_t slave_addr;
if (!chan)
return NULL;
BUG_ON(!schan->desc_num);
if (slave_id < 0 || !sg_len) {
dev_warn(schan->dev, "%s: bad parameter: len=%d, id=%d\n",
__func__, sg_len, slave_id);
return NULL;
}
slave_addr = ops->slave_addr(schan);
return shdma_prep_sg(schan, sgl, sg_len, &slave_addr,
direction, flags, false);
}
static struct dma_async_tx_descriptor *shdma_prep_dma_cyclic(
struct dma_chan *chan, dma_addr_t buf_addr, size_t buf_len,
size_t period_len, enum dma_transfer_direction direction,
unsigned long flags)
{
struct shdma_chan *schan = to_shdma_chan(chan);
struct shdma_dev *sdev = to_shdma_dev(schan->dma_chan.device);
struct dma_async_tx_descriptor *desc;
const struct shdma_ops *ops = sdev->ops;
unsigned int sg_len = buf_len / period_len;
int slave_id = schan->slave_id;
dma_addr_t slave_addr;
struct scatterlist *sgl;
int i;
if (!chan)
return NULL;
BUG_ON(!schan->desc_num);
if (sg_len > SHDMA_MAX_SG_LEN) {
dev_err(schan->dev, "sg length %d exceds limit %d",
sg_len, SHDMA_MAX_SG_LEN);
return NULL;
}
if (slave_id < 0 || (buf_len < period_len)) {
dev_warn(schan->dev,
"%s: bad parameter: buf_len=%zu, period_len=%zu, id=%d\n",
__func__, buf_len, period_len, slave_id);
return NULL;
}
slave_addr = ops->slave_addr(schan);
sgl = kcalloc(sg_len, sizeof(*sgl), GFP_KERNEL);
if (!sgl)
return NULL;
sg_init_table(sgl, sg_len);
for (i = 0; i < sg_len; i++) {
dma_addr_t src = buf_addr + (period_len * i);
sg_set_page(&sgl[i], pfn_to_page(PFN_DOWN(src)), period_len,
offset_in_page(src));
sg_dma_address(&sgl[i]) = src;
sg_dma_len(&sgl[i]) = period_len;
}
desc = shdma_prep_sg(schan, sgl, sg_len, &slave_addr,
direction, flags, true);
kfree(sgl);
return desc;
}
static int shdma_terminate_all(struct dma_chan *chan)
{
struct shdma_chan *schan = to_shdma_chan(chan);
struct shdma_dev *sdev = to_shdma_dev(chan->device);
const struct shdma_ops *ops = sdev->ops;
unsigned long flags;
spin_lock_irqsave(&schan->chan_lock, flags);
ops->halt_channel(schan);
if (ops->get_partial && !list_empty(&schan->ld_queue)) {
struct shdma_desc *desc = list_first_entry(&schan->ld_queue,
struct shdma_desc, node);
desc->partial = ops->get_partial(schan, desc);
}
spin_unlock_irqrestore(&schan->chan_lock, flags);
shdma_chan_ld_cleanup(schan, true);
return 0;
}
static int shdma_config(struct dma_chan *chan,
struct dma_slave_config *config)
{
struct shdma_chan *schan = to_shdma_chan(chan);
if (!config)
return -EINVAL;
if (WARN_ON_ONCE(config->slave_id &&
config->slave_id != schan->real_slave_id))
schan->real_slave_id = config->slave_id;
return shdma_setup_slave(schan,
config->direction == DMA_DEV_TO_MEM ?
config->src_addr : config->dst_addr);
}
static void shdma_issue_pending(struct dma_chan *chan)
{
struct shdma_chan *schan = to_shdma_chan(chan);
spin_lock_irq(&schan->chan_lock);
if (schan->pm_state == SHDMA_PM_ESTABLISHED)
shdma_chan_xfer_ld_queue(schan);
else
schan->pm_state = SHDMA_PM_PENDING;
spin_unlock_irq(&schan->chan_lock);
}
static enum dma_status shdma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct shdma_chan *schan = to_shdma_chan(chan);
enum dma_status status;
unsigned long flags;
shdma_chan_ld_cleanup(schan, false);
spin_lock_irqsave(&schan->chan_lock, flags);
status = dma_cookie_status(chan, cookie, txstate);
if (status != DMA_COMPLETE) {
struct shdma_desc *sdesc;
status = DMA_ERROR;
list_for_each_entry(sdesc, &schan->ld_queue, node)
if (sdesc->cookie == cookie) {
status = DMA_IN_PROGRESS;
break;
}
}
spin_unlock_irqrestore(&schan->chan_lock, flags);
return status;
}
bool shdma_reset(struct shdma_dev *sdev)
{
const struct shdma_ops *ops = sdev->ops;
struct shdma_chan *schan;
unsigned int handled = 0;
int i;
shdma_for_each_chan(schan, sdev, i) {
struct shdma_desc *sdesc;
LIST_HEAD(dl);
if (!schan)
continue;
spin_lock(&schan->chan_lock);
ops->halt_channel(schan);
list_splice_init(&schan->ld_queue, &dl);
if (!list_empty(&dl)) {
dev_dbg(schan->dev, "Bring down channel %d\n", schan->id);
pm_runtime_put(schan->dev);
}
schan->pm_state = SHDMA_PM_ESTABLISHED;
spin_unlock(&schan->chan_lock);
list_for_each_entry(sdesc, &dl, node) {
struct dma_async_tx_descriptor *tx = &sdesc->async_tx;
sdesc->mark = DESC_IDLE;
dmaengine_desc_get_callback_invoke(tx, NULL);
}
spin_lock(&schan->chan_lock);
list_splice(&dl, &schan->ld_free);
spin_unlock(&schan->chan_lock);
handled++;
}
return !!handled;
}
static irqreturn_t chan_irq(int irq, void *dev)
{
struct shdma_chan *schan = dev;
const struct shdma_ops *ops =
to_shdma_dev(schan->dma_chan.device)->ops;
irqreturn_t ret;
spin_lock(&schan->chan_lock);
ret = ops->chan_irq(schan, irq) ? IRQ_WAKE_THREAD : IRQ_NONE;
spin_unlock(&schan->chan_lock);
return ret;
}
static irqreturn_t chan_irqt(int irq, void *dev)
{
struct shdma_chan *schan = dev;
const struct shdma_ops *ops =
to_shdma_dev(schan->dma_chan.device)->ops;
struct shdma_desc *sdesc;
spin_lock_irq(&schan->chan_lock);
list_for_each_entry(sdesc, &schan->ld_queue, node) {
if (sdesc->mark == DESC_SUBMITTED &&
ops->desc_completed(schan, sdesc)) {
dev_dbg(schan->dev, "done #%d@%p\n",
sdesc->async_tx.cookie, &sdesc->async_tx);
sdesc->mark = DESC_COMPLETED;
break;
}
}
shdma_chan_xfer_ld_queue(schan);
spin_unlock_irq(&schan->chan_lock);
shdma_chan_ld_cleanup(schan, false);
return IRQ_HANDLED;
}
int shdma_request_irq(struct shdma_chan *schan, int irq,
unsigned long flags, const char *name)
{
int ret = devm_request_threaded_irq(schan->dev, irq, chan_irq,
chan_irqt, flags, name, schan);
schan->irq = ret < 0 ? ret : irq;
return ret;
}
void shdma_chan_probe(struct shdma_dev *sdev,
struct shdma_chan *schan, int id)
{
schan->pm_state = SHDMA_PM_ESTABLISHED;
schan->dma_chan.device = &sdev->dma_dev;
dma_cookie_init(&schan->dma_chan);
schan->dev = sdev->dma_dev.dev;
schan->id = id;
if (!schan->max_xfer_len)
schan->max_xfer_len = PAGE_SIZE;
spin_lock_init(&schan->chan_lock);
INIT_LIST_HEAD(&schan->ld_queue);
INIT_LIST_HEAD(&schan->ld_free);
list_add_tail(&schan->dma_chan.device_node,
&sdev->dma_dev.channels);
sdev->schan[id] = schan;
}
void shdma_chan_remove(struct shdma_chan *schan)
{
list_del(&schan->dma_chan.device_node);
}
int shdma_init(struct device *dev, struct shdma_dev *sdev,
int chan_num)
{
struct dma_device *dma_dev = &sdev->dma_dev;
if (!sdev->ops ||
!sdev->desc_size ||
!sdev->ops->embedded_desc ||
!sdev->ops->start_xfer ||
!sdev->ops->setup_xfer ||
!sdev->ops->set_slave ||
!sdev->ops->desc_setup ||
!sdev->ops->slave_addr ||
!sdev->ops->channel_busy ||
!sdev->ops->halt_channel ||
!sdev->ops->desc_completed)
return -EINVAL;
sdev->schan = kcalloc(chan_num, sizeof(*sdev->schan), GFP_KERNEL);
if (!sdev->schan)
return -ENOMEM;
INIT_LIST_HEAD(&dma_dev->channels);
dma_dev->device_alloc_chan_resources
= shdma_alloc_chan_resources;
dma_dev->device_free_chan_resources = shdma_free_chan_resources;
dma_dev->device_prep_dma_memcpy = shdma_prep_memcpy;
dma_dev->device_tx_status = shdma_tx_status;
dma_dev->device_issue_pending = shdma_issue_pending;
dma_dev->device_prep_slave_sg = shdma_prep_slave_sg;
dma_dev->device_prep_dma_cyclic = shdma_prep_dma_cyclic;
dma_dev->device_config = shdma_config;
dma_dev->device_terminate_all = shdma_terminate_all;
dma_dev->dev = dev;
return 0;
}
void shdma_cleanup(struct shdma_dev *sdev)
{
kfree(sdev->schan);
}
static int __init shdma_enter(void)
{
shdma_slave_used = kzalloc(DIV_ROUND_UP(slave_num, BITS_PER_LONG) *
sizeof(long), GFP_KERNEL);
if (!shdma_slave_used)
return -ENOMEM;
return 0;
}
static void __exit shdma_exit(void)
{
kfree(shdma_slave_used);
}
