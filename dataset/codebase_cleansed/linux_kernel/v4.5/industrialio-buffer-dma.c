static void iio_buffer_block_release(struct kref *kref)
{
struct iio_dma_buffer_block *block = container_of(kref,
struct iio_dma_buffer_block, kref);
WARN_ON(block->state != IIO_BLOCK_STATE_DEAD);
dma_free_coherent(block->queue->dev, PAGE_ALIGN(block->size),
block->vaddr, block->phys_addr);
iio_buffer_put(&block->queue->buffer);
kfree(block);
}
static void iio_buffer_block_get(struct iio_dma_buffer_block *block)
{
kref_get(&block->kref);
}
static void iio_buffer_block_put(struct iio_dma_buffer_block *block)
{
kref_put(&block->kref, iio_buffer_block_release);
}
static void iio_dma_buffer_cleanup_worker(struct work_struct *work)
{
struct iio_dma_buffer_block *block, *_block;
LIST_HEAD(block_list);
spin_lock_irq(&iio_dma_buffer_dead_blocks_lock);
list_splice_tail_init(&iio_dma_buffer_dead_blocks, &block_list);
spin_unlock_irq(&iio_dma_buffer_dead_blocks_lock);
list_for_each_entry_safe(block, _block, &block_list, head)
iio_buffer_block_release(&block->kref);
}
static void iio_buffer_block_release_atomic(struct kref *kref)
{
struct iio_dma_buffer_block *block;
unsigned long flags;
block = container_of(kref, struct iio_dma_buffer_block, kref);
spin_lock_irqsave(&iio_dma_buffer_dead_blocks_lock, flags);
list_add_tail(&block->head, &iio_dma_buffer_dead_blocks);
spin_unlock_irqrestore(&iio_dma_buffer_dead_blocks_lock, flags);
schedule_work(&iio_dma_buffer_cleanup_work);
}
static void iio_buffer_block_put_atomic(struct iio_dma_buffer_block *block)
{
kref_put(&block->kref, iio_buffer_block_release_atomic);
}
static struct iio_dma_buffer_queue *iio_buffer_to_queue(struct iio_buffer *buf)
{
return container_of(buf, struct iio_dma_buffer_queue, buffer);
}
static struct iio_dma_buffer_block *iio_dma_buffer_alloc_block(
struct iio_dma_buffer_queue *queue, size_t size)
{
struct iio_dma_buffer_block *block;
block = kzalloc(sizeof(*block), GFP_KERNEL);
if (!block)
return NULL;
block->vaddr = dma_alloc_coherent(queue->dev, PAGE_ALIGN(size),
&block->phys_addr, GFP_KERNEL);
if (!block->vaddr) {
kfree(block);
return NULL;
}
block->size = size;
block->state = IIO_BLOCK_STATE_DEQUEUED;
block->queue = queue;
INIT_LIST_HEAD(&block->head);
kref_init(&block->kref);
iio_buffer_get(&queue->buffer);
return block;
}
static void _iio_dma_buffer_block_done(struct iio_dma_buffer_block *block)
{
struct iio_dma_buffer_queue *queue = block->queue;
if (block->state != IIO_BLOCK_STATE_DEAD) {
block->state = IIO_BLOCK_STATE_DONE;
list_add_tail(&block->head, &queue->outgoing);
}
}
void iio_dma_buffer_block_done(struct iio_dma_buffer_block *block)
{
struct iio_dma_buffer_queue *queue = block->queue;
unsigned long flags;
spin_lock_irqsave(&queue->list_lock, flags);
_iio_dma_buffer_block_done(block);
spin_unlock_irqrestore(&queue->list_lock, flags);
iio_buffer_block_put_atomic(block);
wake_up_interruptible_poll(&queue->buffer.pollq, POLLIN | POLLRDNORM);
}
void iio_dma_buffer_block_list_abort(struct iio_dma_buffer_queue *queue,
struct list_head *list)
{
struct iio_dma_buffer_block *block, *_block;
unsigned long flags;
spin_lock_irqsave(&queue->list_lock, flags);
list_for_each_entry_safe(block, _block, list, head) {
list_del(&block->head);
block->bytes_used = 0;
_iio_dma_buffer_block_done(block);
iio_buffer_block_put_atomic(block);
}
spin_unlock_irqrestore(&queue->list_lock, flags);
wake_up_interruptible_poll(&queue->buffer.pollq, POLLIN | POLLRDNORM);
}
static bool iio_dma_block_reusable(struct iio_dma_buffer_block *block)
{
switch (block->state) {
case IIO_BLOCK_STATE_DEQUEUED:
case IIO_BLOCK_STATE_QUEUED:
case IIO_BLOCK_STATE_DONE:
return true;
default:
return false;
}
}
int iio_dma_buffer_request_update(struct iio_buffer *buffer)
{
struct iio_dma_buffer_queue *queue = iio_buffer_to_queue(buffer);
struct iio_dma_buffer_block *block;
bool try_reuse = false;
size_t size;
int ret = 0;
int i;
size = DIV_ROUND_UP(queue->buffer.bytes_per_datum *
queue->buffer.length, 2);
mutex_lock(&queue->lock);
if (PAGE_ALIGN(queue->fileio.block_size) == PAGE_ALIGN(size))
try_reuse = true;
queue->fileio.block_size = size;
queue->fileio.active_block = NULL;
spin_lock_irq(&queue->list_lock);
for (i = 0; i < 2; i++) {
block = queue->fileio.blocks[i];
if (block && (!iio_dma_block_reusable(block) || !try_reuse))
block->state = IIO_BLOCK_STATE_DEAD;
}
INIT_LIST_HEAD(&queue->outgoing);
spin_unlock_irq(&queue->list_lock);
INIT_LIST_HEAD(&queue->incoming);
for (i = 0; i < 2; i++) {
if (queue->fileio.blocks[i]) {
block = queue->fileio.blocks[i];
if (block->state == IIO_BLOCK_STATE_DEAD) {
iio_buffer_block_put(block);
block = NULL;
} else {
block->size = size;
}
} else {
block = NULL;
}
if (!block) {
block = iio_dma_buffer_alloc_block(queue, size);
if (!block) {
ret = -ENOMEM;
goto out_unlock;
}
queue->fileio.blocks[i] = block;
}
block->state = IIO_BLOCK_STATE_QUEUED;
list_add_tail(&block->head, &queue->incoming);
}
out_unlock:
mutex_unlock(&queue->lock);
return ret;
}
static void iio_dma_buffer_submit_block(struct iio_dma_buffer_queue *queue,
struct iio_dma_buffer_block *block)
{
int ret;
if (!queue->ops)
return;
block->state = IIO_BLOCK_STATE_ACTIVE;
iio_buffer_block_get(block);
ret = queue->ops->submit(queue, block);
if (ret) {
iio_buffer_block_put(block);
}
}
int iio_dma_buffer_enable(struct iio_buffer *buffer,
struct iio_dev *indio_dev)
{
struct iio_dma_buffer_queue *queue = iio_buffer_to_queue(buffer);
struct iio_dma_buffer_block *block, *_block;
mutex_lock(&queue->lock);
queue->active = true;
list_for_each_entry_safe(block, _block, &queue->incoming, head) {
list_del(&block->head);
iio_dma_buffer_submit_block(queue, block);
}
mutex_unlock(&queue->lock);
return 0;
}
int iio_dma_buffer_disable(struct iio_buffer *buffer,
struct iio_dev *indio_dev)
{
struct iio_dma_buffer_queue *queue = iio_buffer_to_queue(buffer);
mutex_lock(&queue->lock);
queue->active = false;
if (queue->ops && queue->ops->abort)
queue->ops->abort(queue);
mutex_unlock(&queue->lock);
return 0;
}
static void iio_dma_buffer_enqueue(struct iio_dma_buffer_queue *queue,
struct iio_dma_buffer_block *block)
{
if (block->state == IIO_BLOCK_STATE_DEAD) {
iio_buffer_block_put(block);
} else if (queue->active) {
iio_dma_buffer_submit_block(queue, block);
} else {
block->state = IIO_BLOCK_STATE_QUEUED;
list_add_tail(&block->head, &queue->incoming);
}
}
static struct iio_dma_buffer_block *iio_dma_buffer_dequeue(
struct iio_dma_buffer_queue *queue)
{
struct iio_dma_buffer_block *block;
spin_lock_irq(&queue->list_lock);
block = list_first_entry_or_null(&queue->outgoing, struct
iio_dma_buffer_block, head);
if (block != NULL) {
list_del(&block->head);
block->state = IIO_BLOCK_STATE_DEQUEUED;
}
spin_unlock_irq(&queue->list_lock);
return block;
}
int iio_dma_buffer_read(struct iio_buffer *buffer, size_t n,
char __user *user_buffer)
{
struct iio_dma_buffer_queue *queue = iio_buffer_to_queue(buffer);
struct iio_dma_buffer_block *block;
int ret;
if (n < buffer->bytes_per_datum)
return -EINVAL;
mutex_lock(&queue->lock);
if (!queue->fileio.active_block) {
block = iio_dma_buffer_dequeue(queue);
if (block == NULL) {
ret = 0;
goto out_unlock;
}
queue->fileio.pos = 0;
queue->fileio.active_block = block;
} else {
block = queue->fileio.active_block;
}
n = rounddown(n, buffer->bytes_per_datum);
if (n > block->bytes_used - queue->fileio.pos)
n = block->bytes_used - queue->fileio.pos;
if (copy_to_user(user_buffer, block->vaddr + queue->fileio.pos, n)) {
ret = -EFAULT;
goto out_unlock;
}
queue->fileio.pos += n;
if (queue->fileio.pos == block->bytes_used) {
queue->fileio.active_block = NULL;
iio_dma_buffer_enqueue(queue, block);
}
ret = n;
out_unlock:
mutex_unlock(&queue->lock);
return ret;
}
size_t iio_dma_buffer_data_available(struct iio_buffer *buf)
{
struct iio_dma_buffer_queue *queue = iio_buffer_to_queue(buf);
struct iio_dma_buffer_block *block;
size_t data_available = 0;
mutex_lock(&queue->lock);
if (queue->fileio.active_block)
data_available += queue->fileio.active_block->size;
spin_lock_irq(&queue->list_lock);
list_for_each_entry(block, &queue->outgoing, head)
data_available += block->size;
spin_unlock_irq(&queue->list_lock);
mutex_unlock(&queue->lock);
return data_available;
}
int iio_dma_buffer_set_bytes_per_datum(struct iio_buffer *buffer, size_t bpd)
{
buffer->bytes_per_datum = bpd;
return 0;
}
int iio_dma_buffer_set_length(struct iio_buffer *buffer, int length)
{
if (length < 2)
length = 2;
buffer->length = length;
buffer->watermark = length / 2;
return 0;
}
int iio_dma_buffer_init(struct iio_dma_buffer_queue *queue,
struct device *dev, const struct iio_dma_buffer_ops *ops)
{
iio_buffer_init(&queue->buffer);
queue->buffer.length = PAGE_SIZE;
queue->buffer.watermark = queue->buffer.length / 2;
queue->dev = dev;
queue->ops = ops;
INIT_LIST_HEAD(&queue->incoming);
INIT_LIST_HEAD(&queue->outgoing);
mutex_init(&queue->lock);
spin_lock_init(&queue->list_lock);
return 0;
}
void iio_dma_buffer_exit(struct iio_dma_buffer_queue *queue)
{
unsigned int i;
mutex_lock(&queue->lock);
spin_lock_irq(&queue->list_lock);
for (i = 0; i < ARRAY_SIZE(queue->fileio.blocks); i++) {
if (!queue->fileio.blocks[i])
continue;
queue->fileio.blocks[i]->state = IIO_BLOCK_STATE_DEAD;
}
INIT_LIST_HEAD(&queue->outgoing);
spin_unlock_irq(&queue->list_lock);
INIT_LIST_HEAD(&queue->incoming);
for (i = 0; i < ARRAY_SIZE(queue->fileio.blocks); i++) {
if (!queue->fileio.blocks[i])
continue;
iio_buffer_block_put(queue->fileio.blocks[i]);
queue->fileio.blocks[i] = NULL;
}
queue->fileio.active_block = NULL;
queue->ops = NULL;
mutex_unlock(&queue->lock);
}
void iio_dma_buffer_release(struct iio_dma_buffer_queue *queue)
{
mutex_destroy(&queue->lock);
}
