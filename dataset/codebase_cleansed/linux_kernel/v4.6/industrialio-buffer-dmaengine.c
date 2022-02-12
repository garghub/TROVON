static struct dmaengine_buffer *iio_buffer_to_dmaengine_buffer(
struct iio_buffer *buffer)
{
return container_of(buffer, struct dmaengine_buffer, queue.buffer);
}
static void iio_dmaengine_buffer_block_done(void *data)
{
struct iio_dma_buffer_block *block = data;
unsigned long flags;
spin_lock_irqsave(&block->queue->list_lock, flags);
list_del(&block->head);
spin_unlock_irqrestore(&block->queue->list_lock, flags);
iio_dma_buffer_block_done(block);
}
static int iio_dmaengine_buffer_submit_block(struct iio_dma_buffer_queue *queue,
struct iio_dma_buffer_block *block)
{
struct dmaengine_buffer *dmaengine_buffer =
iio_buffer_to_dmaengine_buffer(&queue->buffer);
struct dma_async_tx_descriptor *desc;
dma_cookie_t cookie;
block->bytes_used = min(block->size, dmaengine_buffer->max_size);
block->bytes_used = rounddown(block->bytes_used,
dmaengine_buffer->align);
desc = dmaengine_prep_slave_single(dmaengine_buffer->chan,
block->phys_addr, block->bytes_used, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT);
if (!desc)
return -ENOMEM;
desc->callback = iio_dmaengine_buffer_block_done;
desc->callback_param = block;
cookie = dmaengine_submit(desc);
if (dma_submit_error(cookie))
return dma_submit_error(cookie);
spin_lock_irq(&dmaengine_buffer->queue.list_lock);
list_add_tail(&block->head, &dmaengine_buffer->active);
spin_unlock_irq(&dmaengine_buffer->queue.list_lock);
dma_async_issue_pending(dmaengine_buffer->chan);
return 0;
}
static void iio_dmaengine_buffer_abort(struct iio_dma_buffer_queue *queue)
{
struct dmaengine_buffer *dmaengine_buffer =
iio_buffer_to_dmaengine_buffer(&queue->buffer);
dmaengine_terminate_sync(dmaengine_buffer->chan);
iio_dma_buffer_block_list_abort(queue, &dmaengine_buffer->active);
}
static void iio_dmaengine_buffer_release(struct iio_buffer *buf)
{
struct dmaengine_buffer *dmaengine_buffer =
iio_buffer_to_dmaengine_buffer(buf);
iio_dma_buffer_release(&dmaengine_buffer->queue);
kfree(dmaengine_buffer);
}
struct iio_buffer *iio_dmaengine_buffer_alloc(struct device *dev,
const char *channel)
{
struct dmaengine_buffer *dmaengine_buffer;
unsigned int width, src_width, dest_width;
struct dma_slave_caps caps;
struct dma_chan *chan;
int ret;
dmaengine_buffer = kzalloc(sizeof(*dmaengine_buffer), GFP_KERNEL);
if (!dmaengine_buffer)
return ERR_PTR(-ENOMEM);
chan = dma_request_slave_channel_reason(dev, channel);
if (IS_ERR(chan)) {
ret = PTR_ERR(chan);
goto err_free;
}
ret = dma_get_slave_caps(chan, &caps);
if (ret < 0)
goto err_free;
if (caps.src_addr_widths)
src_width = __ffs(caps.src_addr_widths);
else
src_width = 1;
if (caps.dst_addr_widths)
dest_width = __ffs(caps.dst_addr_widths);
else
dest_width = 1;
width = max(src_width, dest_width);
INIT_LIST_HEAD(&dmaengine_buffer->active);
dmaengine_buffer->chan = chan;
dmaengine_buffer->align = width;
dmaengine_buffer->max_size = dma_get_max_seg_size(chan->device->dev);
iio_dma_buffer_init(&dmaengine_buffer->queue, chan->device->dev,
&iio_dmaengine_default_ops);
dmaengine_buffer->queue.buffer.access = &iio_dmaengine_buffer_ops;
return &dmaengine_buffer->queue.buffer;
err_free:
kfree(dmaengine_buffer);
return ERR_PTR(ret);
}
void iio_dmaengine_buffer_free(struct iio_buffer *buffer)
{
struct dmaengine_buffer *dmaengine_buffer =
iio_buffer_to_dmaengine_buffer(buffer);
iio_dma_buffer_exit(&dmaengine_buffer->queue);
dma_release_channel(dmaengine_buffer->chan);
iio_buffer_put(buffer);
}
