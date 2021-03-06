static struct port *find_port_by_vtermno(u32 vtermno)
{
struct port *port;
struct console *cons;
unsigned long flags;
spin_lock_irqsave(&pdrvdata_lock, flags);
list_for_each_entry(cons, &pdrvdata.consoles, list) {
if (cons->vtermno == vtermno) {
port = container_of(cons, struct port, cons);
goto out;
}
}
port = NULL;
out:
spin_unlock_irqrestore(&pdrvdata_lock, flags);
return port;
}
static struct port *find_port_by_devt_in_portdev(struct ports_device *portdev,
dev_t dev)
{
struct port *port;
unsigned long flags;
spin_lock_irqsave(&portdev->ports_lock, flags);
list_for_each_entry(port, &portdev->ports, list) {
if (port->cdev->dev == dev) {
kref_get(&port->kref);
goto out;
}
}
port = NULL;
out:
spin_unlock_irqrestore(&portdev->ports_lock, flags);
return port;
}
static struct port *find_port_by_devt(dev_t dev)
{
struct ports_device *portdev;
struct port *port;
unsigned long flags;
spin_lock_irqsave(&pdrvdata_lock, flags);
list_for_each_entry(portdev, &pdrvdata.portdevs, list) {
port = find_port_by_devt_in_portdev(portdev, dev);
if (port)
goto out;
}
port = NULL;
out:
spin_unlock_irqrestore(&pdrvdata_lock, flags);
return port;
}
static struct port *find_port_by_id(struct ports_device *portdev, u32 id)
{
struct port *port;
unsigned long flags;
spin_lock_irqsave(&portdev->ports_lock, flags);
list_for_each_entry(port, &portdev->ports, list)
if (port->id == id)
goto out;
port = NULL;
out:
spin_unlock_irqrestore(&portdev->ports_lock, flags);
return port;
}
static struct port *find_port_by_vq(struct ports_device *portdev,
struct virtqueue *vq)
{
struct port *port;
unsigned long flags;
spin_lock_irqsave(&portdev->ports_lock, flags);
list_for_each_entry(port, &portdev->ports, list)
if (port->in_vq == vq || port->out_vq == vq)
goto out;
port = NULL;
out:
spin_unlock_irqrestore(&portdev->ports_lock, flags);
return port;
}
static bool is_console_port(struct port *port)
{
if (port->cons.hvc)
return true;
return false;
}
static bool is_rproc_serial(const struct virtio_device *vdev)
{
return is_rproc_enabled && vdev->id.device == VIRTIO_ID_RPROC_SERIAL;
}
static inline bool use_multiport(struct ports_device *portdev)
{
if (!portdev->vdev)
return 0;
return portdev->vdev->features[0] & (1 << VIRTIO_CONSOLE_F_MULTIPORT);
}
static void free_buf(struct port_buffer *buf, bool can_sleep)
{
unsigned int i;
for (i = 0; i < buf->sgpages; i++) {
struct page *page = sg_page(&buf->sg[i]);
if (!page)
break;
put_page(page);
}
if (!buf->dev) {
kfree(buf->buf);
} else if (is_rproc_enabled) {
unsigned long flags;
if (!can_sleep) {
spin_lock_irqsave(&dma_bufs_lock, flags);
list_add_tail(&buf->list, &pending_free_dma_bufs);
spin_unlock_irqrestore(&dma_bufs_lock, flags);
return;
}
dma_free_coherent(buf->dev, buf->size, buf->buf, buf->dma);
put_device(buf->dev);
}
kfree(buf);
}
static void reclaim_dma_bufs(void)
{
unsigned long flags;
struct port_buffer *buf, *tmp;
LIST_HEAD(tmp_list);
if (list_empty(&pending_free_dma_bufs))
return;
spin_lock_irqsave(&dma_bufs_lock, flags);
list_cut_position(&tmp_list, &pending_free_dma_bufs,
pending_free_dma_bufs.prev);
spin_unlock_irqrestore(&dma_bufs_lock, flags);
list_for_each_entry_safe(buf, tmp, &tmp_list, list) {
list_del(&buf->list);
free_buf(buf, true);
}
}
static struct port_buffer *alloc_buf(struct virtqueue *vq, size_t buf_size,
int pages)
{
struct port_buffer *buf;
reclaim_dma_bufs();
buf = kmalloc(sizeof(*buf) + sizeof(struct scatterlist) * pages,
GFP_KERNEL);
if (!buf)
goto fail;
buf->sgpages = pages;
if (pages > 0) {
buf->dev = NULL;
buf->buf = NULL;
return buf;
}
if (is_rproc_serial(vq->vdev)) {
if (!vq->vdev->dev.parent || !vq->vdev->dev.parent->parent)
goto free_buf;
buf->dev = vq->vdev->dev.parent->parent;
get_device(buf->dev);
buf->buf = dma_alloc_coherent(buf->dev, buf_size, &buf->dma,
GFP_KERNEL);
} else {
buf->dev = NULL;
buf->buf = kmalloc(buf_size, GFP_KERNEL);
}
if (!buf->buf)
goto free_buf;
buf->len = 0;
buf->offset = 0;
buf->size = buf_size;
return buf;
free_buf:
kfree(buf);
fail:
return NULL;
}
static struct port_buffer *get_inbuf(struct port *port)
{
struct port_buffer *buf;
unsigned int len;
if (port->inbuf)
return port->inbuf;
buf = virtqueue_get_buf(port->in_vq, &len);
if (buf) {
buf->len = len;
buf->offset = 0;
port->stats.bytes_received += len;
}
return buf;
}
static int add_inbuf(struct virtqueue *vq, struct port_buffer *buf)
{
struct scatterlist sg[1];
int ret;
sg_init_one(sg, buf->buf, buf->size);
ret = virtqueue_add_inbuf(vq, sg, 1, buf, GFP_ATOMIC);
virtqueue_kick(vq);
if (!ret)
ret = vq->num_free;
return ret;
}
static void discard_port_data(struct port *port)
{
struct port_buffer *buf;
unsigned int err;
if (!port->portdev) {
return;
}
buf = get_inbuf(port);
err = 0;
while (buf) {
port->stats.bytes_discarded += buf->len - buf->offset;
if (add_inbuf(port->in_vq, buf) < 0) {
err++;
free_buf(buf, false);
}
port->inbuf = NULL;
buf = get_inbuf(port);
}
if (err)
dev_warn(port->dev, "Errors adding %d buffers back to vq\n",
err);
}
static bool port_has_data(struct port *port)
{
unsigned long flags;
bool ret;
ret = false;
spin_lock_irqsave(&port->inbuf_lock, flags);
port->inbuf = get_inbuf(port);
if (port->inbuf)
ret = true;
spin_unlock_irqrestore(&port->inbuf_lock, flags);
return ret;
}
static ssize_t __send_control_msg(struct ports_device *portdev, u32 port_id,
unsigned int event, unsigned int value)
{
struct scatterlist sg[1];
struct virtio_console_control cpkt;
struct virtqueue *vq;
unsigned int len;
if (!use_multiport(portdev))
return 0;
cpkt.id = port_id;
cpkt.event = event;
cpkt.value = value;
vq = portdev->c_ovq;
sg_init_one(sg, &cpkt, sizeof(cpkt));
spin_lock(&portdev->c_ovq_lock);
if (virtqueue_add_outbuf(vq, sg, 1, &cpkt, GFP_ATOMIC) == 0) {
virtqueue_kick(vq);
while (!virtqueue_get_buf(vq, &len)
&& !virtqueue_is_broken(vq))
cpu_relax();
}
spin_unlock(&portdev->c_ovq_lock);
return 0;
}
static ssize_t send_control_msg(struct port *port, unsigned int event,
unsigned int value)
{
if (port->portdev)
return __send_control_msg(port->portdev, port->id, event, value);
return 0;
}
static void reclaim_consumed_buffers(struct port *port)
{
struct port_buffer *buf;
unsigned int len;
if (!port->portdev) {
return;
}
while ((buf = virtqueue_get_buf(port->out_vq, &len))) {
free_buf(buf, false);
port->outvq_full = false;
}
}
static ssize_t __send_to_port(struct port *port, struct scatterlist *sg,
int nents, size_t in_count,
void *data, bool nonblock)
{
struct virtqueue *out_vq;
int err;
unsigned long flags;
unsigned int len;
out_vq = port->out_vq;
spin_lock_irqsave(&port->outvq_lock, flags);
reclaim_consumed_buffers(port);
err = virtqueue_add_outbuf(out_vq, sg, nents, data, GFP_ATOMIC);
virtqueue_kick(out_vq);
if (err) {
in_count = 0;
goto done;
}
if (out_vq->num_free == 0)
port->outvq_full = true;
if (nonblock)
goto done;
while (!virtqueue_get_buf(out_vq, &len)
&& !virtqueue_is_broken(out_vq))
cpu_relax();
done:
spin_unlock_irqrestore(&port->outvq_lock, flags);
port->stats.bytes_sent += in_count;
return in_count;
}
static ssize_t fill_readbuf(struct port *port, char *out_buf, size_t out_count,
bool to_user)
{
struct port_buffer *buf;
unsigned long flags;
if (!out_count || !port_has_data(port))
return 0;
buf = port->inbuf;
out_count = min(out_count, buf->len - buf->offset);
if (to_user) {
ssize_t ret;
ret = copy_to_user(out_buf, buf->buf + buf->offset, out_count);
if (ret)
return -EFAULT;
} else {
memcpy(out_buf, buf->buf + buf->offset, out_count);
}
buf->offset += out_count;
if (buf->offset == buf->len) {
spin_lock_irqsave(&port->inbuf_lock, flags);
port->inbuf = NULL;
if (add_inbuf(port->in_vq, buf) < 0)
dev_warn(port->dev, "failed add_buf\n");
spin_unlock_irqrestore(&port->inbuf_lock, flags);
}
return out_count;
}
static bool will_read_block(struct port *port)
{
if (!port->guest_connected) {
return false;
}
return !port_has_data(port) && port->host_connected;
}
static bool will_write_block(struct port *port)
{
bool ret;
if (!port->guest_connected) {
return false;
}
if (!port->host_connected)
return true;
spin_lock_irq(&port->outvq_lock);
reclaim_consumed_buffers(port);
ret = port->outvq_full;
spin_unlock_irq(&port->outvq_lock);
return ret;
}
static ssize_t port_fops_read(struct file *filp, char __user *ubuf,
size_t count, loff_t *offp)
{
struct port *port;
ssize_t ret;
port = filp->private_data;
if (!port->guest_connected)
return -ENODEV;
if (!port_has_data(port)) {
if (!port->host_connected)
return 0;
if (filp->f_flags & O_NONBLOCK)
return -EAGAIN;
ret = wait_event_freezable(port->waitqueue,
!will_read_block(port));
if (ret < 0)
return ret;
}
if (!port->guest_connected)
return -ENODEV;
if (!port_has_data(port) && !port->host_connected)
return 0;
return fill_readbuf(port, ubuf, count, true);
}
static int wait_port_writable(struct port *port, bool nonblock)
{
int ret;
if (will_write_block(port)) {
if (nonblock)
return -EAGAIN;
ret = wait_event_freezable(port->waitqueue,
!will_write_block(port));
if (ret < 0)
return ret;
}
if (!port->guest_connected)
return -ENODEV;
return 0;
}
static ssize_t port_fops_write(struct file *filp, const char __user *ubuf,
size_t count, loff_t *offp)
{
struct port *port;
struct port_buffer *buf;
ssize_t ret;
bool nonblock;
struct scatterlist sg[1];
if (!count)
return 0;
port = filp->private_data;
nonblock = filp->f_flags & O_NONBLOCK;
ret = wait_port_writable(port, nonblock);
if (ret < 0)
return ret;
count = min((size_t)(32 * 1024), count);
buf = alloc_buf(port->out_vq, count, 0);
if (!buf)
return -ENOMEM;
ret = copy_from_user(buf->buf, ubuf, count);
if (ret) {
ret = -EFAULT;
goto free_buf;
}
nonblock = true;
sg_init_one(sg, buf->buf, count);
ret = __send_to_port(port, sg, 1, count, buf, nonblock);
if (nonblock && ret > 0)
goto out;
free_buf:
free_buf(buf, true);
out:
return ret;
}
static int pipe_to_sg(struct pipe_inode_info *pipe, struct pipe_buffer *buf,
struct splice_desc *sd)
{
struct sg_list *sgl = sd->u.data;
unsigned int offset, len;
if (sgl->n == sgl->size)
return 0;
if (buf->ops->steal(pipe, buf) == 0) {
get_page(buf->page);
unlock_page(buf->page);
len = min(buf->len, sd->len);
sg_set_page(&(sgl->sg[sgl->n]), buf->page, len, buf->offset);
} else {
struct page *page = alloc_page(GFP_KERNEL);
char *src;
if (!page)
return -ENOMEM;
offset = sd->pos & ~PAGE_MASK;
len = sd->len;
if (len + offset > PAGE_SIZE)
len = PAGE_SIZE - offset;
src = kmap_atomic(buf->page);
memcpy(page_address(page) + offset, src + buf->offset, len);
kunmap_atomic(src);
sg_set_page(&(sgl->sg[sgl->n]), page, len, offset);
}
sgl->n++;
sgl->len += len;
return len;
}
static ssize_t port_fops_splice_write(struct pipe_inode_info *pipe,
struct file *filp, loff_t *ppos,
size_t len, unsigned int flags)
{
struct port *port = filp->private_data;
struct sg_list sgl;
ssize_t ret;
struct port_buffer *buf;
struct splice_desc sd = {
.total_len = len,
.flags = flags,
.pos = *ppos,
.u.data = &sgl,
};
if (is_rproc_serial(port->out_vq->vdev))
return -EINVAL;
pipe_lock(pipe);
if (!pipe->nrbufs) {
ret = 0;
goto error_out;
}
ret = wait_port_writable(port, filp->f_flags & O_NONBLOCK);
if (ret < 0)
goto error_out;
buf = alloc_buf(port->out_vq, 0, pipe->nrbufs);
if (!buf) {
ret = -ENOMEM;
goto error_out;
}
sgl.n = 0;
sgl.len = 0;
sgl.size = pipe->nrbufs;
sgl.sg = buf->sg;
sg_init_table(sgl.sg, sgl.size);
ret = __splice_from_pipe(pipe, &sd, pipe_to_sg);
pipe_unlock(pipe);
if (likely(ret > 0))
ret = __send_to_port(port, buf->sg, sgl.n, sgl.len, buf, true);
if (unlikely(ret <= 0))
free_buf(buf, true);
return ret;
error_out:
pipe_unlock(pipe);
return ret;
}
static unsigned int port_fops_poll(struct file *filp, poll_table *wait)
{
struct port *port;
unsigned int ret;
port = filp->private_data;
poll_wait(filp, &port->waitqueue, wait);
if (!port->guest_connected) {
return POLLHUP;
}
ret = 0;
if (!will_read_block(port))
ret |= POLLIN | POLLRDNORM;
if (!will_write_block(port))
ret |= POLLOUT;
if (!port->host_connected)
ret |= POLLHUP;
return ret;
}
static int port_fops_release(struct inode *inode, struct file *filp)
{
struct port *port;
port = filp->private_data;
send_control_msg(port, VIRTIO_CONSOLE_PORT_OPEN, 0);
spin_lock_irq(&port->inbuf_lock);
port->guest_connected = false;
discard_port_data(port);
spin_unlock_irq(&port->inbuf_lock);
spin_lock_irq(&port->outvq_lock);
reclaim_consumed_buffers(port);
spin_unlock_irq(&port->outvq_lock);
reclaim_dma_bufs();
kref_put(&port->kref, remove_port);
return 0;
}
static int port_fops_open(struct inode *inode, struct file *filp)
{
struct cdev *cdev = inode->i_cdev;
struct port *port;
int ret;
port = find_port_by_devt(cdev->dev);
if (!port) {
return -ENXIO;
}
filp->private_data = port;
if (is_console_port(port)) {
ret = -ENXIO;
goto out;
}
spin_lock_irq(&port->inbuf_lock);
if (port->guest_connected) {
spin_unlock_irq(&port->inbuf_lock);
ret = -EBUSY;
goto out;
}
port->guest_connected = true;
spin_unlock_irq(&port->inbuf_lock);
spin_lock_irq(&port->outvq_lock);
reclaim_consumed_buffers(port);
spin_unlock_irq(&port->outvq_lock);
nonseekable_open(inode, filp);
send_control_msg(filp->private_data, VIRTIO_CONSOLE_PORT_OPEN, 1);
return 0;
out:
kref_put(&port->kref, remove_port);
return ret;
}
static int port_fops_fasync(int fd, struct file *filp, int mode)
{
struct port *port;
port = filp->private_data;
return fasync_helper(fd, filp, mode, &port->async_queue);
}
static int put_chars(u32 vtermno, const char *buf, int count)
{
struct port *port;
struct scatterlist sg[1];
if (unlikely(early_put_chars))
return early_put_chars(vtermno, buf, count);
port = find_port_by_vtermno(vtermno);
if (!port)
return -EPIPE;
sg_init_one(sg, buf, count);
return __send_to_port(port, sg, 1, count, (void *)buf, false);
}
static int get_chars(u32 vtermno, char *buf, int count)
{
struct port *port;
if (unlikely(early_put_chars))
return 0;
port = find_port_by_vtermno(vtermno);
if (!port)
return -EPIPE;
BUG_ON(!port->in_vq);
return fill_readbuf(port, buf, count, false);
}
static void resize_console(struct port *port)
{
struct virtio_device *vdev;
if (!port || !is_console_port(port))
return;
vdev = port->portdev->vdev;
if (!is_rproc_serial(vdev) &&
virtio_has_feature(vdev, VIRTIO_CONSOLE_F_SIZE))
hvc_resize(port->cons.hvc, port->cons.ws);
}
static int notifier_add_vio(struct hvc_struct *hp, int data)
{
struct port *port;
port = find_port_by_vtermno(hp->vtermno);
if (!port)
return -EINVAL;
hp->irq_requested = 1;
resize_console(port);
return 0;
}
static void notifier_del_vio(struct hvc_struct *hp, int data)
{
hp->irq_requested = 0;
}
int __init virtio_cons_early_init(int (*put_chars)(u32, const char *, int))
{
early_put_chars = put_chars;
return hvc_instantiate(0, 0, &hv_ops);
}
static int init_port_console(struct port *port)
{
int ret;
port->cons.vtermno = pdrvdata.next_vtermno;
port->cons.hvc = hvc_alloc(port->cons.vtermno, 0, &hv_ops, PAGE_SIZE);
if (IS_ERR(port->cons.hvc)) {
ret = PTR_ERR(port->cons.hvc);
dev_err(port->dev,
"error %d allocating hvc for port\n", ret);
port->cons.hvc = NULL;
return ret;
}
spin_lock_irq(&pdrvdata_lock);
pdrvdata.next_vtermno++;
list_add_tail(&port->cons.list, &pdrvdata.consoles);
spin_unlock_irq(&pdrvdata_lock);
port->guest_connected = true;
if (early_put_chars)
early_put_chars = NULL;
send_control_msg(port, VIRTIO_CONSOLE_PORT_OPEN, 1);
return 0;
}
static ssize_t show_port_name(struct device *dev,
struct device_attribute *attr, char *buffer)
{
struct port *port;
port = dev_get_drvdata(dev);
return sprintf(buffer, "%s\n", port->name);
}
static ssize_t debugfs_read(struct file *filp, char __user *ubuf,
size_t count, loff_t *offp)
{
struct port *port;
char *buf;
ssize_t ret, out_offset, out_count;
out_count = 1024;
buf = kmalloc(out_count, GFP_KERNEL);
if (!buf)
return -ENOMEM;
port = filp->private_data;
out_offset = 0;
out_offset += snprintf(buf + out_offset, out_count,
"name: %s\n", port->name ? port->name : "");
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"guest_connected: %d\n", port->guest_connected);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"host_connected: %d\n", port->host_connected);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"outvq_full: %d\n", port->outvq_full);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"bytes_sent: %lu\n", port->stats.bytes_sent);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"bytes_received: %lu\n",
port->stats.bytes_received);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"bytes_discarded: %lu\n",
port->stats.bytes_discarded);
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"is_console: %s\n",
is_console_port(port) ? "yes" : "no");
out_offset += snprintf(buf + out_offset, out_count - out_offset,
"console_vtermno: %u\n", port->cons.vtermno);
ret = simple_read_from_buffer(ubuf, count, offp, buf, out_offset);
kfree(buf);
return ret;
}
static void set_console_size(struct port *port, u16 rows, u16 cols)
{
if (!port || !is_console_port(port))
return;
port->cons.ws.ws_row = rows;
port->cons.ws.ws_col = cols;
}
static unsigned int fill_queue(struct virtqueue *vq, spinlock_t *lock)
{
struct port_buffer *buf;
unsigned int nr_added_bufs;
int ret;
nr_added_bufs = 0;
do {
buf = alloc_buf(vq, PAGE_SIZE, 0);
if (!buf)
break;
spin_lock_irq(lock);
ret = add_inbuf(vq, buf);
if (ret < 0) {
spin_unlock_irq(lock);
free_buf(buf, true);
break;
}
nr_added_bufs++;
spin_unlock_irq(lock);
} while (ret > 0);
return nr_added_bufs;
}
static void send_sigio_to_port(struct port *port)
{
if (port->async_queue && port->guest_connected)
kill_fasync(&port->async_queue, SIGIO, POLL_OUT);
}
static int add_port(struct ports_device *portdev, u32 id)
{
char debugfs_name[16];
struct port *port;
struct port_buffer *buf;
dev_t devt;
unsigned int nr_added_bufs;
int err;
port = kmalloc(sizeof(*port), GFP_KERNEL);
if (!port) {
err = -ENOMEM;
goto fail;
}
kref_init(&port->kref);
port->portdev = portdev;
port->id = id;
port->name = NULL;
port->inbuf = NULL;
port->cons.hvc = NULL;
port->async_queue = NULL;
port->cons.ws.ws_row = port->cons.ws.ws_col = 0;
port->host_connected = port->guest_connected = false;
port->stats = (struct port_stats) { 0 };
port->outvq_full = false;
port->in_vq = portdev->in_vqs[port->id];
port->out_vq = portdev->out_vqs[port->id];
port->cdev = cdev_alloc();
if (!port->cdev) {
dev_err(&port->portdev->vdev->dev, "Error allocating cdev\n");
err = -ENOMEM;
goto free_port;
}
port->cdev->ops = &port_fops;
devt = MKDEV(portdev->chr_major, id);
err = cdev_add(port->cdev, devt, 1);
if (err < 0) {
dev_err(&port->portdev->vdev->dev,
"Error %d adding cdev for port %u\n", err, id);
goto free_cdev;
}
port->dev = device_create(pdrvdata.class, &port->portdev->vdev->dev,
devt, port, "vport%up%u",
port->portdev->vdev->index, id);
if (IS_ERR(port->dev)) {
err = PTR_ERR(port->dev);
dev_err(&port->portdev->vdev->dev,
"Error %d creating device for port %u\n",
err, id);
goto free_cdev;
}
spin_lock_init(&port->inbuf_lock);
spin_lock_init(&port->outvq_lock);
init_waitqueue_head(&port->waitqueue);
nr_added_bufs = fill_queue(port->in_vq, &port->inbuf_lock);
if (!nr_added_bufs) {
dev_err(port->dev, "Error allocating inbufs\n");
err = -ENOMEM;
goto free_device;
}
if (is_rproc_serial(port->portdev->vdev))
port->host_connected = true;
else if (!use_multiport(port->portdev)) {
err = init_port_console(port);
if (err)
goto free_inbufs;
}
spin_lock_irq(&portdev->ports_lock);
list_add_tail(&port->list, &port->portdev->ports);
spin_unlock_irq(&portdev->ports_lock);
send_control_msg(port, VIRTIO_CONSOLE_PORT_READY, 1);
if (pdrvdata.debugfs_dir) {
sprintf(debugfs_name, "vport%up%u",
port->portdev->vdev->index, id);
port->debugfs_file = debugfs_create_file(debugfs_name, 0444,
pdrvdata.debugfs_dir,
port,
&port_debugfs_ops);
}
return 0;
free_inbufs:
while ((buf = virtqueue_detach_unused_buf(port->in_vq)))
free_buf(buf, true);
free_device:
device_destroy(pdrvdata.class, port->dev->devt);
free_cdev:
cdev_del(port->cdev);
free_port:
kfree(port);
fail:
__send_control_msg(portdev, id, VIRTIO_CONSOLE_PORT_READY, 0);
return err;
}
static void remove_port(struct kref *kref)
{
struct port *port;
port = container_of(kref, struct port, kref);
kfree(port);
}
static void remove_port_data(struct port *port)
{
struct port_buffer *buf;
spin_lock_irq(&port->inbuf_lock);
discard_port_data(port);
while ((buf = virtqueue_detach_unused_buf(port->in_vq)))
free_buf(buf, true);
spin_unlock_irq(&port->inbuf_lock);
spin_lock_irq(&port->outvq_lock);
reclaim_consumed_buffers(port);
while ((buf = virtqueue_detach_unused_buf(port->out_vq)))
free_buf(buf, true);
spin_unlock_irq(&port->outvq_lock);
}
static void unplug_port(struct port *port)
{
spin_lock_irq(&port->portdev->ports_lock);
list_del(&port->list);
spin_unlock_irq(&port->portdev->ports_lock);
spin_lock_irq(&port->inbuf_lock);
if (port->guest_connected) {
send_sigio_to_port(port);
port->guest_connected = false;
port->host_connected = false;
wake_up_interruptible(&port->waitqueue);
}
spin_unlock_irq(&port->inbuf_lock);
if (is_console_port(port)) {
spin_lock_irq(&pdrvdata_lock);
list_del(&port->cons.list);
spin_unlock_irq(&pdrvdata_lock);
hvc_remove(port->cons.hvc);
}
remove_port_data(port);
port->portdev = NULL;
sysfs_remove_group(&port->dev->kobj, &port_attribute_group);
device_destroy(pdrvdata.class, port->dev->devt);
cdev_del(port->cdev);
debugfs_remove(port->debugfs_file);
kfree(port->name);
kref_put(&port->kref, remove_port);
}
static void handle_control_message(struct ports_device *portdev,
struct port_buffer *buf)
{
struct virtio_console_control *cpkt;
struct port *port;
size_t name_size;
int err;
cpkt = (struct virtio_console_control *)(buf->buf + buf->offset);
port = find_port_by_id(portdev, cpkt->id);
if (!port && cpkt->event != VIRTIO_CONSOLE_PORT_ADD) {
dev_dbg(&portdev->vdev->dev,
"Invalid index %u in control packet\n", cpkt->id);
return;
}
switch (cpkt->event) {
case VIRTIO_CONSOLE_PORT_ADD:
if (port) {
dev_dbg(&portdev->vdev->dev,
"Port %u already added\n", port->id);
send_control_msg(port, VIRTIO_CONSOLE_PORT_READY, 1);
break;
}
if (cpkt->id >= portdev->config.max_nr_ports) {
dev_warn(&portdev->vdev->dev,
"Request for adding port with out-of-bound id %u, max. supported id: %u\n",
cpkt->id, portdev->config.max_nr_ports - 1);
break;
}
add_port(portdev, cpkt->id);
break;
case VIRTIO_CONSOLE_PORT_REMOVE:
unplug_port(port);
break;
case VIRTIO_CONSOLE_CONSOLE_PORT:
if (!cpkt->value)
break;
if (is_console_port(port))
break;
init_port_console(port);
complete(&early_console_added);
break;
case VIRTIO_CONSOLE_RESIZE: {
struct {
__u16 rows;
__u16 cols;
} size;
if (!is_console_port(port))
break;
memcpy(&size, buf->buf + buf->offset + sizeof(*cpkt),
sizeof(size));
set_console_size(port, size.rows, size.cols);
port->cons.hvc->irq_requested = 1;
resize_console(port);
break;
}
case VIRTIO_CONSOLE_PORT_OPEN:
port->host_connected = cpkt->value;
wake_up_interruptible(&port->waitqueue);
spin_lock_irq(&port->outvq_lock);
reclaim_consumed_buffers(port);
spin_unlock_irq(&port->outvq_lock);
spin_lock_irq(&port->inbuf_lock);
send_sigio_to_port(port);
spin_unlock_irq(&port->inbuf_lock);
break;
case VIRTIO_CONSOLE_PORT_NAME:
if (port->name)
break;
name_size = buf->len - buf->offset - sizeof(*cpkt) + 1;
port->name = kmalloc(name_size, GFP_KERNEL);
if (!port->name) {
dev_err(port->dev,
"Not enough space to store port name\n");
break;
}
strncpy(port->name, buf->buf + buf->offset + sizeof(*cpkt),
name_size - 1);
port->name[name_size - 1] = 0;
err = sysfs_create_group(&port->dev->kobj,
&port_attribute_group);
if (err) {
dev_err(port->dev,
"Error %d creating sysfs device attributes\n",
err);
} else {
kobject_uevent(&port->dev->kobj, KOBJ_CHANGE);
}
break;
}
}
static void control_work_handler(struct work_struct *work)
{
struct ports_device *portdev;
struct virtqueue *vq;
struct port_buffer *buf;
unsigned int len;
portdev = container_of(work, struct ports_device, control_work);
vq = portdev->c_ivq;
spin_lock(&portdev->c_ivq_lock);
while ((buf = virtqueue_get_buf(vq, &len))) {
spin_unlock(&portdev->c_ivq_lock);
buf->len = len;
buf->offset = 0;
handle_control_message(portdev, buf);
spin_lock(&portdev->c_ivq_lock);
if (add_inbuf(portdev->c_ivq, buf) < 0) {
dev_warn(&portdev->vdev->dev,
"Error adding buffer to queue\n");
free_buf(buf, false);
}
}
spin_unlock(&portdev->c_ivq_lock);
}
static void out_intr(struct virtqueue *vq)
{
struct port *port;
port = find_port_by_vq(vq->vdev->priv, vq);
if (!port)
return;
wake_up_interruptible(&port->waitqueue);
}
static void in_intr(struct virtqueue *vq)
{
struct port *port;
unsigned long flags;
port = find_port_by_vq(vq->vdev->priv, vq);
if (!port)
return;
spin_lock_irqsave(&port->inbuf_lock, flags);
port->inbuf = get_inbuf(port);
if (!port->guest_connected && !is_rproc_serial(port->portdev->vdev))
discard_port_data(port);
send_sigio_to_port(port);
spin_unlock_irqrestore(&port->inbuf_lock, flags);
wake_up_interruptible(&port->waitqueue);
if (is_console_port(port) && hvc_poll(port->cons.hvc))
hvc_kick();
}
static void control_intr(struct virtqueue *vq)
{
struct ports_device *portdev;
portdev = vq->vdev->priv;
schedule_work(&portdev->control_work);
}
static void config_intr(struct virtio_device *vdev)
{
struct ports_device *portdev;
portdev = vdev->priv;
if (!use_multiport(portdev)) {
struct port *port;
u16 rows, cols;
virtio_cread(vdev, struct virtio_console_config, cols, &cols);
virtio_cread(vdev, struct virtio_console_config, rows, &rows);
port = find_port_by_id(portdev, 0);
set_console_size(port, rows, cols);
resize_console(port);
}
}
static int init_vqs(struct ports_device *portdev)
{
vq_callback_t **io_callbacks;
char **io_names;
struct virtqueue **vqs;
u32 i, j, nr_ports, nr_queues;
int err;
nr_ports = portdev->config.max_nr_ports;
nr_queues = use_multiport(portdev) ? (nr_ports + 1) * 2 : 2;
vqs = kmalloc(nr_queues * sizeof(struct virtqueue *), GFP_KERNEL);
io_callbacks = kmalloc(nr_queues * sizeof(vq_callback_t *), GFP_KERNEL);
io_names = kmalloc(nr_queues * sizeof(char *), GFP_KERNEL);
portdev->in_vqs = kmalloc(nr_ports * sizeof(struct virtqueue *),
GFP_KERNEL);
portdev->out_vqs = kmalloc(nr_ports * sizeof(struct virtqueue *),
GFP_KERNEL);
if (!vqs || !io_callbacks || !io_names || !portdev->in_vqs ||
!portdev->out_vqs) {
err = -ENOMEM;
goto free;
}
j = 0;
io_callbacks[j] = in_intr;
io_callbacks[j + 1] = out_intr;
io_names[j] = "input";
io_names[j + 1] = "output";
j += 2;
if (use_multiport(portdev)) {
io_callbacks[j] = control_intr;
io_callbacks[j + 1] = NULL;
io_names[j] = "control-i";
io_names[j + 1] = "control-o";
for (i = 1; i < nr_ports; i++) {
j += 2;
io_callbacks[j] = in_intr;
io_callbacks[j + 1] = out_intr;
io_names[j] = "input";
io_names[j + 1] = "output";
}
}
err = portdev->vdev->config->find_vqs(portdev->vdev, nr_queues, vqs,
io_callbacks,
(const char **)io_names);
if (err)
goto free;
j = 0;
portdev->in_vqs[0] = vqs[0];
portdev->out_vqs[0] = vqs[1];
j += 2;
if (use_multiport(portdev)) {
portdev->c_ivq = vqs[j];
portdev->c_ovq = vqs[j + 1];
for (i = 1; i < nr_ports; i++) {
j += 2;
portdev->in_vqs[i] = vqs[j];
portdev->out_vqs[i] = vqs[j + 1];
}
}
kfree(io_names);
kfree(io_callbacks);
kfree(vqs);
return 0;
free:
kfree(portdev->out_vqs);
kfree(portdev->in_vqs);
kfree(io_names);
kfree(io_callbacks);
kfree(vqs);
return err;
}
static void remove_vqs(struct ports_device *portdev)
{
portdev->vdev->config->del_vqs(portdev->vdev);
kfree(portdev->in_vqs);
kfree(portdev->out_vqs);
}
static void remove_controlq_data(struct ports_device *portdev)
{
struct port_buffer *buf;
unsigned int len;
if (!use_multiport(portdev))
return;
while ((buf = virtqueue_get_buf(portdev->c_ivq, &len)))
free_buf(buf, true);
while ((buf = virtqueue_detach_unused_buf(portdev->c_ivq)))
free_buf(buf, true);
}
static int virtcons_probe(struct virtio_device *vdev)
{
struct ports_device *portdev;
int err;
bool multiport;
bool early = early_put_chars != NULL;
barrier();
portdev = kmalloc(sizeof(*portdev), GFP_KERNEL);
if (!portdev) {
err = -ENOMEM;
goto fail;
}
portdev->vdev = vdev;
vdev->priv = portdev;
portdev->chr_major = register_chrdev(0, "virtio-portsdev",
&portdev_fops);
if (portdev->chr_major < 0) {
dev_err(&vdev->dev,
"Error %d registering chrdev for device %u\n",
portdev->chr_major, vdev->index);
err = portdev->chr_major;
goto free;
}
multiport = false;
portdev->config.max_nr_ports = 1;
if (!is_rproc_serial(vdev) &&
virtio_cread_feature(vdev, VIRTIO_CONSOLE_F_MULTIPORT,
struct virtio_console_config, max_nr_ports,
&portdev->config.max_nr_ports) == 0) {
multiport = true;
}
err = init_vqs(portdev);
if (err < 0) {
dev_err(&vdev->dev, "Error %d initializing vqs\n", err);
goto free_chrdev;
}
spin_lock_init(&portdev->ports_lock);
INIT_LIST_HEAD(&portdev->ports);
virtio_device_ready(portdev->vdev);
if (multiport) {
unsigned int nr_added_bufs;
spin_lock_init(&portdev->c_ivq_lock);
spin_lock_init(&portdev->c_ovq_lock);
INIT_WORK(&portdev->control_work, &control_work_handler);
nr_added_bufs = fill_queue(portdev->c_ivq,
&portdev->c_ivq_lock);
if (!nr_added_bufs) {
dev_err(&vdev->dev,
"Error allocating buffers for control queue\n");
err = -ENOMEM;
goto free_vqs;
}
} else {
add_port(portdev, 0);
}
spin_lock_irq(&pdrvdata_lock);
list_add_tail(&portdev->list, &pdrvdata.portdevs);
spin_unlock_irq(&pdrvdata_lock);
__send_control_msg(portdev, VIRTIO_CONSOLE_BAD_ID,
VIRTIO_CONSOLE_DEVICE_READY, 1);
if (multiport && early)
wait_for_completion(&early_console_added);
return 0;
free_vqs:
__send_control_msg(portdev, VIRTIO_CONSOLE_BAD_ID,
VIRTIO_CONSOLE_DEVICE_READY, 0);
remove_vqs(portdev);
free_chrdev:
unregister_chrdev(portdev->chr_major, "virtio-portsdev");
free:
kfree(portdev);
fail:
return err;
}
static void virtcons_remove(struct virtio_device *vdev)
{
struct ports_device *portdev;
struct port *port, *port2;
portdev = vdev->priv;
spin_lock_irq(&pdrvdata_lock);
list_del(&portdev->list);
spin_unlock_irq(&pdrvdata_lock);
vdev->config->reset(vdev);
if (use_multiport(portdev))
cancel_work_sync(&portdev->control_work);
list_for_each_entry_safe(port, port2, &portdev->ports, list)
unplug_port(port);
unregister_chrdev(portdev->chr_major, "virtio-portsdev");
remove_controlq_data(portdev);
remove_vqs(portdev);
kfree(portdev);
}
static int virtcons_freeze(struct virtio_device *vdev)
{
struct ports_device *portdev;
struct port *port;
portdev = vdev->priv;
vdev->config->reset(vdev);
virtqueue_disable_cb(portdev->c_ivq);
cancel_work_sync(&portdev->control_work);
virtqueue_disable_cb(portdev->c_ivq);
remove_controlq_data(portdev);
list_for_each_entry(port, &portdev->ports, list) {
virtqueue_disable_cb(port->in_vq);
virtqueue_disable_cb(port->out_vq);
port->host_connected = false;
remove_port_data(port);
}
remove_vqs(portdev);
return 0;
}
static int virtcons_restore(struct virtio_device *vdev)
{
struct ports_device *portdev;
struct port *port;
int ret;
portdev = vdev->priv;
ret = init_vqs(portdev);
if (ret)
return ret;
virtio_device_ready(portdev->vdev);
if (use_multiport(portdev))
fill_queue(portdev->c_ivq, &portdev->c_ivq_lock);
list_for_each_entry(port, &portdev->ports, list) {
port->in_vq = portdev->in_vqs[port->id];
port->out_vq = portdev->out_vqs[port->id];
fill_queue(port->in_vq, &port->inbuf_lock);
send_control_msg(port, VIRTIO_CONSOLE_PORT_READY, 1);
if (port->guest_connected)
send_control_msg(port, VIRTIO_CONSOLE_PORT_OPEN, 1);
}
return 0;
}
static int __init init(void)
{
int err;
pdrvdata.class = class_create(THIS_MODULE, "virtio-ports");
if (IS_ERR(pdrvdata.class)) {
err = PTR_ERR(pdrvdata.class);
pr_err("Error %d creating virtio-ports class\n", err);
return err;
}
pdrvdata.debugfs_dir = debugfs_create_dir("virtio-ports", NULL);
if (!pdrvdata.debugfs_dir)
pr_warning("Error creating debugfs dir for virtio-ports\n");
INIT_LIST_HEAD(&pdrvdata.consoles);
INIT_LIST_HEAD(&pdrvdata.portdevs);
err = register_virtio_driver(&virtio_console);
if (err < 0) {
pr_err("Error %d registering virtio driver\n", err);
goto free;
}
err = register_virtio_driver(&virtio_rproc_serial);
if (err < 0) {
pr_err("Error %d registering virtio rproc serial driver\n",
err);
goto unregister;
}
return 0;
unregister:
unregister_virtio_driver(&virtio_console);
free:
debugfs_remove_recursive(pdrvdata.debugfs_dir);
class_destroy(pdrvdata.class);
return err;
}
static void __exit fini(void)
{
reclaim_dma_bufs();
unregister_virtio_driver(&virtio_console);
unregister_virtio_driver(&virtio_rproc_serial);
class_destroy(pdrvdata.class);
debugfs_remove_recursive(pdrvdata.debugfs_dir);
}
