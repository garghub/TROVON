int ishtp_cl_alloc_rx_ring(struct ishtp_cl *cl)
{
size_t len = cl->device->fw_client->props.max_msg_length;
int j;
struct ishtp_cl_rb *rb;
int ret = 0;
unsigned long flags;
for (j = 0; j < cl->rx_ring_size; ++j) {
rb = ishtp_io_rb_init(cl);
if (!rb) {
ret = -ENOMEM;
goto out;
}
ret = ishtp_io_rb_alloc_buf(rb, len);
if (ret)
goto out;
spin_lock_irqsave(&cl->free_list_spinlock, flags);
list_add_tail(&rb->list, &cl->free_rb_list.list);
spin_unlock_irqrestore(&cl->free_list_spinlock, flags);
}
return 0;
out:
dev_err(&cl->device->dev, "error in allocating Rx buffers\n");
ishtp_cl_free_rx_ring(cl);
return ret;
}
int ishtp_cl_alloc_tx_ring(struct ishtp_cl *cl)
{
size_t len = cl->device->fw_client->props.max_msg_length;
int j;
unsigned long flags;
for (j = 0; j < cl->tx_ring_size; ++j) {
struct ishtp_cl_tx_ring *tx_buf;
tx_buf = kzalloc(sizeof(struct ishtp_cl_tx_ring), GFP_KERNEL);
if (!tx_buf)
goto out;
tx_buf->send_buf.data = kmalloc(len, GFP_KERNEL);
if (!tx_buf->send_buf.data) {
kfree(tx_buf);
goto out;
}
spin_lock_irqsave(&cl->tx_free_list_spinlock, flags);
list_add_tail(&tx_buf->list, &cl->tx_free_list.list);
spin_unlock_irqrestore(&cl->tx_free_list_spinlock, flags);
}
return 0;
out:
dev_err(&cl->device->dev, "error in allocating Tx pool\n");
ishtp_cl_free_rx_ring(cl);
return -ENOMEM;
}
void ishtp_cl_free_rx_ring(struct ishtp_cl *cl)
{
struct ishtp_cl_rb *rb;
unsigned long flags;
spin_lock_irqsave(&cl->free_list_spinlock, flags);
while (!list_empty(&cl->free_rb_list.list)) {
rb = list_entry(cl->free_rb_list.list.next, struct ishtp_cl_rb,
list);
list_del(&rb->list);
kfree(rb->buffer.data);
kfree(rb);
}
spin_unlock_irqrestore(&cl->free_list_spinlock, flags);
spin_lock_irqsave(&cl->in_process_spinlock, flags);
while (!list_empty(&cl->in_process_list.list)) {
rb = list_entry(cl->in_process_list.list.next,
struct ishtp_cl_rb, list);
list_del(&rb->list);
kfree(rb->buffer.data);
kfree(rb);
}
spin_unlock_irqrestore(&cl->in_process_spinlock, flags);
}
void ishtp_cl_free_tx_ring(struct ishtp_cl *cl)
{
struct ishtp_cl_tx_ring *tx_buf;
unsigned long flags;
spin_lock_irqsave(&cl->tx_free_list_spinlock, flags);
while (!list_empty(&cl->tx_free_list.list)) {
tx_buf = list_entry(cl->tx_free_list.list.next,
struct ishtp_cl_tx_ring, list);
list_del(&tx_buf->list);
kfree(tx_buf->send_buf.data);
kfree(tx_buf);
}
spin_unlock_irqrestore(&cl->tx_free_list_spinlock, flags);
spin_lock_irqsave(&cl->tx_list_spinlock, flags);
while (!list_empty(&cl->tx_list.list)) {
tx_buf = list_entry(cl->tx_list.list.next,
struct ishtp_cl_tx_ring, list);
list_del(&tx_buf->list);
kfree(tx_buf->send_buf.data);
kfree(tx_buf);
}
spin_unlock_irqrestore(&cl->tx_list_spinlock, flags);
}
void ishtp_io_rb_free(struct ishtp_cl_rb *rb)
{
if (rb == NULL)
return;
kfree(rb->buffer.data);
kfree(rb);
}
struct ishtp_cl_rb *ishtp_io_rb_init(struct ishtp_cl *cl)
{
struct ishtp_cl_rb *rb;
rb = kzalloc(sizeof(struct ishtp_cl_rb), GFP_KERNEL);
if (!rb)
return NULL;
INIT_LIST_HEAD(&rb->list);
rb->cl = cl;
rb->buf_idx = 0;
return rb;
}
int ishtp_io_rb_alloc_buf(struct ishtp_cl_rb *rb, size_t length)
{
if (!rb)
return -EINVAL;
if (length == 0)
return 0;
rb->buffer.data = kmalloc(length, GFP_KERNEL);
if (!rb->buffer.data)
return -ENOMEM;
rb->buffer.size = length;
return 0;
}
int ishtp_cl_io_rb_recycle(struct ishtp_cl_rb *rb)
{
struct ishtp_cl *cl;
int rets = 0;
unsigned long flags;
if (!rb || !rb->cl)
return -EFAULT;
cl = rb->cl;
spin_lock_irqsave(&cl->free_list_spinlock, flags);
list_add_tail(&rb->list, &cl->free_rb_list.list);
spin_unlock_irqrestore(&cl->free_list_spinlock, flags);
if (!cl->out_flow_ctrl_creds)
rets = ishtp_cl_read_start(cl);
return rets;
}
