static void malformed_message(struct xilly_endpoint *endpoint, u32 *buf)
{
int opcode;
int msg_channel, msg_bufno, msg_data, msg_dir;
opcode = (buf[0] >> 24) & 0xff;
msg_dir = buf[0] & 1;
msg_channel = (buf[0] >> 1) & 0x7ff;
msg_bufno = (buf[0] >> 12) & 0x3ff;
msg_data = buf[1] & 0xfffffff;
dev_warn(endpoint->dev,
"Malformed message (skipping): opcode=%d, channel=%03x, dir=%d, bufno=%03x, data=%07x\n",
opcode, msg_channel, msg_dir, msg_bufno, msg_data);
}
irqreturn_t xillybus_isr(int irq, void *data)
{
struct xilly_endpoint *ep = data;
u32 *buf;
unsigned int buf_size;
int i;
int opcode;
unsigned int msg_channel, msg_bufno, msg_data, msg_dir;
struct xilly_channel *channel;
smp_rmb();
buf = ep->msgbuf_addr;
buf_size = ep->msg_buf_size/sizeof(u32);
ep->ephw->hw_sync_sgl_for_cpu(ep,
ep->msgbuf_dma_addr,
ep->msg_buf_size,
DMA_FROM_DEVICE);
for (i = 0; i < buf_size; i += 2)
if (((buf[i+1] >> 28) & 0xf) != ep->msg_counter) {
malformed_message(ep, &buf[i]);
dev_warn(ep->dev,
"Sending a NACK on counter %x (instead of %x) on entry %d\n",
((buf[i+1] >> 28) & 0xf),
ep->msg_counter,
i/2);
if (++ep->failed_messages > 10) {
dev_err(ep->dev,
"Lost sync with interrupt messages. Stopping.\n");
} else {
ep->ephw->hw_sync_sgl_for_device(
ep,
ep->msgbuf_dma_addr,
ep->msg_buf_size,
DMA_FROM_DEVICE);
iowrite32(0x01,
ep->registers + fpga_msg_ctrl_reg);
}
return IRQ_HANDLED;
} else if (buf[i] & (1 << 22))
break;
if (i >= buf_size) {
dev_err(ep->dev, "Bad interrupt message. Stopping.\n");
return IRQ_HANDLED;
}
buf_size = i;
for (i = 0; i <= buf_size; i += 2) {
opcode = (buf[i] >> 24) & 0xff;
msg_dir = buf[i] & 1;
msg_channel = (buf[i] >> 1) & 0x7ff;
msg_bufno = (buf[i] >> 12) & 0x3ff;
msg_data = buf[i+1] & 0xfffffff;
switch (opcode) {
case XILLYMSG_OPCODE_RELEASEBUF:
if ((msg_channel > ep->num_channels) ||
(msg_channel == 0)) {
malformed_message(ep, &buf[i]);
break;
}
channel = ep->channels[msg_channel];
if (msg_dir) {
if (msg_bufno >= channel->num_wr_buffers) {
malformed_message(ep, &buf[i]);
break;
}
spin_lock(&channel->wr_spinlock);
channel->wr_buffers[msg_bufno]->end_offset =
msg_data;
channel->wr_fpga_buf_idx = msg_bufno;
channel->wr_empty = 0;
channel->wr_sleepy = 0;
spin_unlock(&channel->wr_spinlock);
wake_up_interruptible(&channel->wr_wait);
} else {
if (msg_bufno >= channel->num_rd_buffers) {
malformed_message(ep, &buf[i]);
break;
}
spin_lock(&channel->rd_spinlock);
channel->rd_fpga_buf_idx = msg_bufno;
channel->rd_full = 0;
spin_unlock(&channel->rd_spinlock);
wake_up_interruptible(&channel->rd_wait);
if (!channel->rd_synchronous)
queue_delayed_work(
xillybus_wq,
&channel->rd_workitem,
XILLY_RX_TIMEOUT);
}
break;
case XILLYMSG_OPCODE_NONEMPTY:
if ((msg_channel > ep->num_channels) ||
(msg_channel == 0) || (!msg_dir) ||
!ep->channels[msg_channel]->wr_supports_nonempty) {
malformed_message(ep, &buf[i]);
break;
}
channel = ep->channels[msg_channel];
if (msg_bufno >= channel->num_wr_buffers) {
malformed_message(ep, &buf[i]);
break;
}
spin_lock(&channel->wr_spinlock);
if (msg_bufno == channel->wr_host_buf_idx)
channel->wr_ready = 1;
spin_unlock(&channel->wr_spinlock);
wake_up_interruptible(&channel->wr_ready_wait);
break;
case XILLYMSG_OPCODE_QUIESCEACK:
ep->idtlen = msg_data;
wake_up_interruptible(&ep->ep_wait);
break;
case XILLYMSG_OPCODE_FIFOEOF:
if ((msg_channel > ep->num_channels) ||
(msg_channel == 0) || (!msg_dir) ||
!ep->channels[msg_channel]->num_wr_buffers) {
malformed_message(ep, &buf[i]);
break;
}
channel = ep->channels[msg_channel];
spin_lock(&channel->wr_spinlock);
channel->wr_eof = msg_bufno;
channel->wr_sleepy = 0;
channel->wr_hangup = channel->wr_empty &&
(channel->wr_host_buf_idx == msg_bufno);
spin_unlock(&channel->wr_spinlock);
wake_up_interruptible(&channel->wr_wait);
break;
case XILLYMSG_OPCODE_FATAL_ERROR:
ep->fatal_error = 1;
wake_up_interruptible(&ep->ep_wait);
dev_err(ep->dev,
"FPGA reported a fatal error. This means that the low-level communication with the device has failed. This hardware problem is most likely unrelated to Xillybus (neither kernel module nor FPGA core), but reports are still welcome. All I/O is aborted.\n");
break;
default:
malformed_message(ep, &buf[i]);
break;
}
}
ep->ephw->hw_sync_sgl_for_device(ep,
ep->msgbuf_dma_addr,
ep->msg_buf_size,
DMA_FROM_DEVICE);
ep->msg_counter = (ep->msg_counter + 1) & 0xf;
ep->failed_messages = 0;
iowrite32(0x03, ep->registers + fpga_msg_ctrl_reg);
return IRQ_HANDLED;
}
static int xilly_get_dma_buffers(struct xilly_endpoint *ep,
struct xilly_alloc_state *s,
struct xilly_buffer **buffers,
int bufnum, int bytebufsize)
{
int i, rc;
dma_addr_t dma_addr;
struct device *dev = ep->dev;
struct xilly_buffer *this_buffer = NULL;
if (buffers) {
this_buffer = devm_kzalloc(
dev, bufnum * sizeof(struct xilly_buffer),
GFP_KERNEL);
if (!this_buffer)
return -ENOMEM;
}
for (i = 0; i < bufnum; i++) {
if ((s->left_of_salami < bytebufsize) &&
(s->left_of_salami > 0)) {
dev_err(ep->dev,
"Corrupt buffer allocation in IDT. Aborting.\n");
return -ENODEV;
}
if (s->left_of_salami == 0) {
int allocorder, allocsize;
allocsize = PAGE_SIZE;
allocorder = 0;
while (bytebufsize > allocsize) {
allocsize *= 2;
allocorder++;
}
s->salami = (void *) devm_get_free_pages(
dev,
GFP_KERNEL | __GFP_DMA32 | __GFP_ZERO,
allocorder);
if (!s->salami)
return -ENOMEM;
s->left_of_salami = allocsize;
}
rc = ep->ephw->map_single(ep, s->salami,
bytebufsize, s->direction,
&dma_addr);
if (rc)
return rc;
iowrite32((u32) (dma_addr & 0xffffffff),
ep->registers + fpga_dma_bufaddr_lowaddr_reg);
iowrite32(((u32) ((((u64) dma_addr) >> 32) & 0xffffffff)),
ep->registers + fpga_dma_bufaddr_highaddr_reg);
mmiowb();
if (buffers) {
this_buffer->addr = s->salami;
this_buffer->dma_addr = dma_addr;
buffers[i] = this_buffer++;
iowrite32(s->regdirection | s->nbuffer++,
ep->registers + fpga_dma_bufno_reg);
} else {
ep->msgbuf_addr = s->salami;
ep->msgbuf_dma_addr = dma_addr;
ep->msg_buf_size = bytebufsize;
iowrite32(s->regdirection,
ep->registers + fpga_dma_bufno_reg);
}
s->left_of_salami -= bytebufsize;
s->salami += bytebufsize;
}
return 0;
}
static int xilly_setupchannels(struct xilly_endpoint *ep,
unsigned char *chandesc,
int entries
)
{
struct device *dev = ep->dev;
int i, entry, rc;
struct xilly_channel *channel;
int channelnum, bufnum, bufsize, format, is_writebuf;
int bytebufsize;
int synchronous, allowpartial, exclusive_open, seekable;
int supports_nonempty;
int msg_buf_done = 0;
struct xilly_alloc_state rd_alloc = {
.salami = NULL,
.left_of_salami = 0,
.nbuffer = 1,
.direction = DMA_TO_DEVICE,
.regdirection = 0,
};
struct xilly_alloc_state wr_alloc = {
.salami = NULL,
.left_of_salami = 0,
.nbuffer = 1,
.direction = DMA_FROM_DEVICE,
.regdirection = 0x80000000,
};
channel = devm_kzalloc(dev, ep->num_channels *
sizeof(struct xilly_channel), GFP_KERNEL);
if (!channel)
goto memfail;
ep->channels = devm_kzalloc(dev, (ep->num_channels + 1) *
sizeof(struct xilly_channel *),
GFP_KERNEL);
if (!ep->channels)
goto memfail;
ep->channels[0] = NULL;
for (i = 1; i <= ep->num_channels; i++) {
channel->wr_buffers = NULL;
channel->rd_buffers = NULL;
channel->num_wr_buffers = 0;
channel->num_rd_buffers = 0;
channel->wr_fpga_buf_idx = -1;
channel->wr_host_buf_idx = 0;
channel->wr_host_buf_pos = 0;
channel->wr_empty = 1;
channel->wr_ready = 0;
channel->wr_sleepy = 1;
channel->rd_fpga_buf_idx = 0;
channel->rd_host_buf_idx = 0;
channel->rd_host_buf_pos = 0;
channel->rd_full = 0;
channel->wr_ref_count = 0;
channel->rd_ref_count = 0;
spin_lock_init(&channel->wr_spinlock);
spin_lock_init(&channel->rd_spinlock);
mutex_init(&channel->wr_mutex);
mutex_init(&channel->rd_mutex);
init_waitqueue_head(&channel->rd_wait);
init_waitqueue_head(&channel->wr_wait);
init_waitqueue_head(&channel->wr_ready_wait);
INIT_DELAYED_WORK(&channel->rd_workitem, xillybus_autoflush);
channel->endpoint = ep;
channel->chan_num = i;
channel->log2_element_size = 0;
ep->channels[i] = channel++;
}
for (entry = 0; entry < entries; entry++, chandesc += 4) {
struct xilly_buffer **buffers = NULL;
is_writebuf = chandesc[0] & 0x01;
channelnum = (chandesc[0] >> 1) | ((chandesc[1] & 0x0f) << 7);
format = (chandesc[1] >> 4) & 0x03;
allowpartial = (chandesc[1] >> 6) & 0x01;
synchronous = (chandesc[1] >> 7) & 0x01;
bufsize = 1 << (chandesc[2] & 0x1f);
bufnum = 1 << (chandesc[3] & 0x0f);
exclusive_open = (chandesc[2] >> 7) & 0x01;
seekable = (chandesc[2] >> 6) & 0x01;
supports_nonempty = (chandesc[2] >> 5) & 0x01;
if ((channelnum > ep->num_channels) ||
((channelnum == 0) && !is_writebuf)) {
dev_err(ep->dev,
"IDT requests channel out of range. Aborting.\n");
return -ENODEV;
}
channel = ep->channels[channelnum];
if (!is_writebuf || channelnum > 0) {
channel->log2_element_size = ((format > 2) ?
2 : format);
bytebufsize = channel->rd_buf_size = bufsize *
(1 << channel->log2_element_size);
buffers = devm_kzalloc(dev,
bufnum * sizeof(struct xilly_buffer *),
GFP_KERNEL);
if (!buffers)
goto memfail;
} else {
bytebufsize = bufsize << 2;
}
if (!is_writebuf) {
channel->num_rd_buffers = bufnum;
channel->rd_allow_partial = allowpartial;
channel->rd_synchronous = synchronous;
channel->rd_exclusive_open = exclusive_open;
channel->seekable = seekable;
channel->rd_buffers = buffers;
rc = xilly_get_dma_buffers(ep, &rd_alloc, buffers,
bufnum, bytebufsize);
} else if (channelnum > 0) {
channel->num_wr_buffers = bufnum;
channel->seekable = seekable;
channel->wr_supports_nonempty = supports_nonempty;
channel->wr_allow_partial = allowpartial;
channel->wr_synchronous = synchronous;
channel->wr_exclusive_open = exclusive_open;
channel->wr_buffers = buffers;
rc = xilly_get_dma_buffers(ep, &wr_alloc, buffers,
bufnum, bytebufsize);
} else {
rc = xilly_get_dma_buffers(ep, &wr_alloc, NULL,
bufnum, bytebufsize);
msg_buf_done++;
}
if (rc)
goto memfail;
}
if (!msg_buf_done) {
dev_err(ep->dev,
"Corrupt IDT: No message buffer. Aborting.\n");
return -ENODEV;
}
return 0;
memfail:
dev_err(ep->dev,
"Failed to assign DMA buffer memory. Aborting.\n");
return -ENOMEM;
}
static void xilly_scan_idt(struct xilly_endpoint *endpoint,
struct xilly_idt_handle *idt_handle)
{
int count = 0;
unsigned char *idt = endpoint->channels[1]->wr_buffers[0]->addr;
unsigned char *end_of_idt = idt + endpoint->idtlen - 4;
unsigned char *scan;
int len;
scan = idt;
idt_handle->idt = idt;
scan++;
while ((scan <= end_of_idt) && *scan) {
while ((scan <= end_of_idt) && *scan++)
;
count++;
}
scan++;
if (scan > end_of_idt) {
dev_err(endpoint->dev,
"IDT device name list overflow. Aborting.\n");
idt_handle->chandesc = NULL;
return;
}
idt_handle->chandesc = scan;
len = endpoint->idtlen - (3 + ((int) (scan - idt)));
if (len & 0x03) {
idt_handle->chandesc = NULL;
dev_err(endpoint->dev,
"Corrupt IDT device name list. Aborting.\n");
}
idt_handle->entries = len >> 2;
endpoint->num_channels = count;
}
static int xilly_obtain_idt(struct xilly_endpoint *endpoint)
{
int rc = 0;
struct xilly_channel *channel;
unsigned char *version;
channel = endpoint->channels[1];
channel->wr_sleepy = 1;
wmb();
iowrite32(1 |
(3 << 24),
endpoint->registers + fpga_buf_ctrl_reg);
mmiowb();
wait_event_interruptible_timeout(channel->wr_wait,
(!channel->wr_sleepy),
XILLY_TIMEOUT);
if (channel->wr_sleepy) {
dev_err(endpoint->dev, "Failed to obtain IDT. Aborting.\n");
if (endpoint->fatal_error)
return -EIO;
rc = -ENODEV;
return rc;
}
endpoint->ephw->hw_sync_sgl_for_cpu(
channel->endpoint,
channel->wr_buffers[0]->dma_addr,
channel->wr_buf_size,
DMA_FROM_DEVICE);
if (channel->wr_buffers[0]->end_offset != endpoint->idtlen) {
dev_err(endpoint->dev,
"IDT length mismatch (%d != %d). Aborting.\n",
channel->wr_buffers[0]->end_offset, endpoint->idtlen);
rc = -ENODEV;
return rc;
}
if (crc32_le(~0, channel->wr_buffers[0]->addr,
endpoint->idtlen+1) != 0) {
dev_err(endpoint->dev, "IDT failed CRC check. Aborting.\n");
rc = -ENODEV;
return rc;
}
version = channel->wr_buffers[0]->addr;
if (*version > 0x82) {
dev_err(endpoint->dev,
"No support for IDT version 0x%02x. Maybe the xillybus driver needs an upgarde. Aborting.\n",
(int) *version);
rc = -ENODEV;
return rc;
}
return 0;
}
static ssize_t xillybus_read(struct file *filp, char __user *userbuf,
size_t count, loff_t *f_pos)
{
ssize_t rc;
unsigned long flags;
int bytes_done = 0;
int no_time_left = 0;
long deadline, left_to_sleep;
struct xilly_channel *channel = filp->private_data;
int empty, reached_eof, exhausted, ready;
int howmany = 0, bufpos = 0, bufidx = 0, bufferdone = 0;
int waiting_bufidx;
if (channel->endpoint->fatal_error)
return -EIO;
deadline = jiffies + 1 + XILLY_RX_TIMEOUT;
rc = mutex_lock_interruptible(&channel->wr_mutex);
if (rc)
return rc;
rc = 0;
while (1) {
int bytes_to_do = count - bytes_done;
spin_lock_irqsave(&channel->wr_spinlock, flags);
empty = channel->wr_empty;
ready = !empty || channel->wr_ready;
if (!empty) {
bufidx = channel->wr_host_buf_idx;
bufpos = channel->wr_host_buf_pos;
howmany = ((channel->wr_buffers[bufidx]->end_offset
+ 1) << channel->log2_element_size)
- bufpos;
if (howmany > bytes_to_do) {
bufferdone = 0;
howmany = bytes_to_do;
channel->wr_host_buf_pos += howmany;
} else {
bufferdone = 1;
channel->wr_host_buf_pos = 0;
if (bufidx == channel->wr_fpga_buf_idx) {
channel->wr_empty = 1;
channel->wr_sleepy = 1;
channel->wr_ready = 0;
}
if (bufidx >= (channel->num_wr_buffers - 1))
channel->wr_host_buf_idx = 0;
else
channel->wr_host_buf_idx++;
}
}
reached_eof = channel->wr_empty &&
(channel->wr_host_buf_idx == channel->wr_eof);
channel->wr_hangup = reached_eof;
exhausted = channel->wr_empty;
waiting_bufidx = channel->wr_host_buf_idx;
spin_unlock_irqrestore(&channel->wr_spinlock, flags);
if (!empty) {
if (bufpos == 0)
channel->endpoint->ephw->hw_sync_sgl_for_cpu(
channel->endpoint,
channel->wr_buffers[bufidx]->dma_addr,
channel->wr_buf_size,
DMA_FROM_DEVICE);
if (copy_to_user(
userbuf,
channel->wr_buffers[bufidx]->addr
+ bufpos, howmany))
rc = -EFAULT;
userbuf += howmany;
bytes_done += howmany;
if (bufferdone) {
channel->endpoint->ephw->
hw_sync_sgl_for_device
(
channel->endpoint,
channel->wr_buffers[bufidx]->
dma_addr,
channel->wr_buf_size,
DMA_FROM_DEVICE);
iowrite32(1 | (channel->chan_num << 1)
| (bufidx << 12),
channel->endpoint->registers +
fpga_buf_ctrl_reg);
mmiowb();
}
if (rc) {
mutex_unlock(&channel->wr_mutex);
return rc;
}
}
if ((bytes_done >= count) || reached_eof)
break;
if (!exhausted)
continue;
if ((bytes_done > 0) &&
(no_time_left ||
(channel->wr_synchronous && channel->wr_allow_partial)))
break;
if (!no_time_left && (filp->f_flags & O_NONBLOCK)) {
if (bytes_done > 0)
break;
if (ready)
goto desperate;
bytes_done = -EAGAIN;
break;
}
if (!no_time_left || (bytes_done > 0)) {
int offsetlimit = ((count - bytes_done) - 1) >>
channel->log2_element_size;
int buf_elements = channel->wr_buf_size >>
channel->log2_element_size;
if (channel->wr_synchronous) {
if (channel->wr_allow_partial &&
(offsetlimit >= buf_elements))
offsetlimit = buf_elements - 1;
if (!channel->wr_allow_partial &&
(offsetlimit >=
(buf_elements * channel->num_wr_buffers)))
offsetlimit = buf_elements *
channel->num_wr_buffers - 1;
}
if (channel->wr_synchronous ||
(offsetlimit < (buf_elements - 1))) {
mutex_lock(&channel->endpoint->register_mutex);
iowrite32(offsetlimit,
channel->endpoint->registers +
fpga_buf_offset_reg);
mmiowb();
iowrite32(1 | (channel->chan_num << 1) |
(2 << 24) |
(waiting_bufidx << 12),
channel->endpoint->registers +
fpga_buf_ctrl_reg);
mmiowb();
mutex_unlock(&channel->endpoint->
register_mutex);
}
}
if (!channel->wr_allow_partial ||
(no_time_left && (bytes_done == 0))) {
do {
mutex_unlock(&channel->wr_mutex);
if (wait_event_interruptible(
channel->wr_wait,
(!channel->wr_sleepy)))
goto interrupted;
if (mutex_lock_interruptible(
&channel->wr_mutex))
goto interrupted;
} while (channel->wr_sleepy);
continue;
interrupted:
if (channel->endpoint->fatal_error)
return -EIO;
if (bytes_done)
return bytes_done;
if (filp->f_flags & O_NONBLOCK)
return -EAGAIN;
return -EINTR;
}
left_to_sleep = deadline - ((long) jiffies);
if (left_to_sleep > 0) {
left_to_sleep =
wait_event_interruptible_timeout(
channel->wr_wait,
(!channel->wr_sleepy),
left_to_sleep);
if (!channel->wr_sleepy)
continue;
if (left_to_sleep < 0) {
mutex_unlock(&channel->wr_mutex);
if (channel->endpoint->fatal_error)
return -EIO;
if (bytes_done)
return bytes_done;
return -EINTR;
}
}
desperate:
no_time_left = 1;
if (bytes_done == 0) {
iowrite32(1 | (channel->chan_num << 1) |
(3 << 24) |
(waiting_bufidx << 12),
channel->endpoint->registers +
fpga_buf_ctrl_reg);
mmiowb();
}
}
mutex_unlock(&channel->wr_mutex);
if (channel->endpoint->fatal_error)
return -EIO;
return bytes_done;
}
static int xillybus_myflush(struct xilly_channel *channel, long timeout)
{
int rc = 0;
unsigned long flags;
int end_offset_plus1;
int bufidx, bufidx_minus1;
int i;
int empty;
int new_rd_host_buf_pos;
if (channel->endpoint->fatal_error)
return -EIO;
rc = mutex_lock_interruptible(&channel->rd_mutex);
if (rc)
return rc;
if (!channel->rd_ref_count)
goto done;
bufidx = channel->rd_host_buf_idx;
bufidx_minus1 = (bufidx == 0) ? channel->num_rd_buffers - 1 : bufidx-1;
end_offset_plus1 = channel->rd_host_buf_pos >>
channel->log2_element_size;
new_rd_host_buf_pos = channel->rd_host_buf_pos -
(end_offset_plus1 << channel->log2_element_size);
if (end_offset_plus1) {
unsigned char *tail = channel->rd_buffers[bufidx]->addr +
(end_offset_plus1 << channel->log2_element_size);
for (i = 0; i < new_rd_host_buf_pos; i++)
channel->rd_leftovers[i] = *tail++;
spin_lock_irqsave(&channel->rd_spinlock, flags);
if ((timeout < 0) &&
(channel->rd_full ||
(bufidx_minus1 != channel->rd_fpga_buf_idx))) {
spin_unlock_irqrestore(&channel->rd_spinlock, flags);
goto done;
}
channel->rd_leftovers[3] = (new_rd_host_buf_pos != 0);
if (bufidx == channel->rd_fpga_buf_idx)
channel->rd_full = 1;
spin_unlock_irqrestore(&channel->rd_spinlock, flags);
if (bufidx >= (channel->num_rd_buffers - 1))
channel->rd_host_buf_idx = 0;
else
channel->rd_host_buf_idx++;
channel->endpoint->ephw->hw_sync_sgl_for_device(
channel->endpoint,
channel->rd_buffers[bufidx]->dma_addr,
channel->rd_buf_size,
DMA_TO_DEVICE);
mutex_lock(&channel->endpoint->register_mutex);
iowrite32(end_offset_plus1 - 1,
channel->endpoint->registers + fpga_buf_offset_reg);
mmiowb();
iowrite32((channel->chan_num << 1) |
(2 << 24) |
(bufidx << 12),
channel->endpoint->registers + fpga_buf_ctrl_reg);
mmiowb();
mutex_unlock(&channel->endpoint->register_mutex);
} else if (bufidx == 0)
bufidx = channel->num_rd_buffers - 1;
else
bufidx--;
channel->rd_host_buf_pos = new_rd_host_buf_pos;
if (timeout < 0)
goto done;
rc = 0;
while (1) {
spin_lock_irqsave(&channel->rd_spinlock, flags);
if (bufidx != channel->rd_fpga_buf_idx)
channel->rd_full = 1;
empty = !channel->rd_full;
spin_unlock_irqrestore(&channel->rd_spinlock, flags);
if (empty)
break;
if (timeout == 0)
wait_event_interruptible(channel->rd_wait,
(!channel->rd_full));
else if (wait_event_interruptible_timeout(
channel->rd_wait,
(!channel->rd_full),
timeout) == 0) {
dev_warn(channel->endpoint->dev,
"Timed out while flushing. Output data may be lost.\n");
rc = -ETIMEDOUT;
break;
}
if (channel->rd_full) {
rc = -EINTR;
break;
}
}
done:
mutex_unlock(&channel->rd_mutex);
if (channel->endpoint->fatal_error)
return -EIO;
return rc;
}
static int xillybus_flush(struct file *filp, fl_owner_t id)
{
if (!(filp->f_mode & FMODE_WRITE))
return 0;
return xillybus_myflush(filp->private_data, HZ);
}
static void xillybus_autoflush(struct work_struct *work)
{
struct delayed_work *workitem = container_of(
work, struct delayed_work, work);
struct xilly_channel *channel = container_of(
workitem, struct xilly_channel, rd_workitem);
int rc;
rc = xillybus_myflush(channel, -1);
if (rc == -EINTR)
dev_warn(channel->endpoint->dev,
"Autoflush failed because work queue thread got a signal.\n");
else if (rc)
dev_err(channel->endpoint->dev,
"Autoflush failed under weird circumstances.\n");
}
static ssize_t xillybus_write(struct file *filp, const char __user *userbuf,
size_t count, loff_t *f_pos)
{
ssize_t rc;
unsigned long flags;
int bytes_done = 0;
struct xilly_channel *channel = filp->private_data;
int full, exhausted;
int howmany = 0, bufpos = 0, bufidx = 0, bufferdone = 0;
int end_offset_plus1 = 0;
if (channel->endpoint->fatal_error)
return -EIO;
rc = mutex_lock_interruptible(&channel->rd_mutex);
if (rc)
return rc;
rc = 0;
while (1) {
int bytes_to_do = count - bytes_done;
spin_lock_irqsave(&channel->rd_spinlock, flags);
full = channel->rd_full;
if (!full) {
bufidx = channel->rd_host_buf_idx;
bufpos = channel->rd_host_buf_pos;
howmany = channel->rd_buf_size - bufpos;
if ((howmany > bytes_to_do) &&
(count ||
((bufpos >> channel->log2_element_size) == 0))) {
bufferdone = 0;
howmany = bytes_to_do;
channel->rd_host_buf_pos += howmany;
} else {
bufferdone = 1;
if (count) {
end_offset_plus1 =
channel->rd_buf_size >>
channel->log2_element_size;
channel->rd_host_buf_pos = 0;
} else {
unsigned char *tail;
int i;
end_offset_plus1 = bufpos >>
channel->log2_element_size;
channel->rd_host_buf_pos -=
end_offset_plus1 <<
channel->log2_element_size;
tail = channel->
rd_buffers[bufidx]->addr +
(end_offset_plus1 <<
channel->log2_element_size);
for (i = 0;
i < channel->rd_host_buf_pos;
i++)
channel->rd_leftovers[i] =
*tail++;
}
if (bufidx == channel->rd_fpga_buf_idx)
channel->rd_full = 1;
if (bufidx >= (channel->num_rd_buffers - 1))
channel->rd_host_buf_idx = 0;
else
channel->rd_host_buf_idx++;
}
}
exhausted = channel->rd_full;
spin_unlock_irqrestore(&channel->rd_spinlock, flags);
if (!full) {
unsigned char *head =
channel->rd_buffers[bufidx]->addr;
int i;
if ((bufpos == 0) ||
(channel->rd_leftovers[3] != 0)) {
channel->endpoint->ephw->hw_sync_sgl_for_cpu(
channel->endpoint,
channel->rd_buffers[bufidx]->dma_addr,
channel->rd_buf_size,
DMA_TO_DEVICE);
for (i = 0; i < bufpos; i++)
*head++ = channel->rd_leftovers[i];
channel->rd_leftovers[3] = 0;
}
if (copy_from_user(
channel->rd_buffers[bufidx]->addr + bufpos,
userbuf, howmany))
rc = -EFAULT;
userbuf += howmany;
bytes_done += howmany;
if (bufferdone) {
channel->endpoint->ephw->
hw_sync_sgl_for_device(
channel->endpoint,
channel->rd_buffers[bufidx]->
dma_addr,
channel->rd_buf_size,
DMA_TO_DEVICE);
mutex_lock(&channel->endpoint->register_mutex);
iowrite32(end_offset_plus1 - 1,
channel->endpoint->registers +
fpga_buf_offset_reg);
mmiowb();
iowrite32((channel->chan_num << 1) |
(2 << 24) |
(bufidx << 12),
channel->endpoint->registers +
fpga_buf_ctrl_reg);
mmiowb();
mutex_unlock(&channel->endpoint->
register_mutex);
channel->rd_leftovers[3] =
(channel->rd_host_buf_pos != 0);
}
if (rc) {
mutex_unlock(&channel->rd_mutex);
if (channel->endpoint->fatal_error)
return -EIO;
if (!channel->rd_synchronous)
queue_delayed_work(
xillybus_wq,
&channel->rd_workitem,
XILLY_RX_TIMEOUT);
return rc;
}
}
if (bytes_done >= count)
break;
if (!exhausted)
continue;
if ((bytes_done > 0) && channel->rd_allow_partial)
break;
if (filp->f_flags & O_NONBLOCK) {
bytes_done = -EAGAIN;
break;
}
wait_event_interruptible(channel->rd_wait,
(!channel->rd_full));
if (channel->rd_full) {
mutex_unlock(&channel->rd_mutex);
if (channel->endpoint->fatal_error)
return -EIO;
if (bytes_done)
return bytes_done;
return -EINTR;
}
}
mutex_unlock(&channel->rd_mutex);
if (!channel->rd_synchronous)
queue_delayed_work(xillybus_wq,
&channel->rd_workitem,
XILLY_RX_TIMEOUT);
if ((channel->rd_synchronous) && (bytes_done > 0)) {
rc = xillybus_myflush(filp->private_data, 0);
if (rc && (rc != -EINTR))
return rc;
}
if (channel->endpoint->fatal_error)
return -EIO;
return bytes_done;
}
static int xillybus_open(struct inode *inode, struct file *filp)
{
int rc = 0;
unsigned long flags;
int minor = iminor(inode);
int major = imajor(inode);
struct xilly_endpoint *ep_iter, *endpoint = NULL;
struct xilly_channel *channel;
mutex_lock(&ep_list_lock);
list_for_each_entry(ep_iter, &list_of_endpoints, ep_list) {
if ((ep_iter->major == major) &&
(minor >= ep_iter->lowest_minor) &&
(minor < (ep_iter->lowest_minor +
ep_iter->num_channels))) {
endpoint = ep_iter;
break;
}
}
mutex_unlock(&ep_list_lock);
if (!endpoint) {
pr_err("xillybus: open() failed to find a device for major=%d and minor=%d\n",
major, minor);
return -ENODEV;
}
if (endpoint->fatal_error)
return -EIO;
channel = endpoint->channels[1 + minor - endpoint->lowest_minor];
filp->private_data = channel;
if ((filp->f_mode & FMODE_READ) && (!channel->num_wr_buffers))
return -ENODEV;
if ((filp->f_mode & FMODE_WRITE) && (!channel->num_rd_buffers))
return -ENODEV;
if ((filp->f_mode & FMODE_READ) && (filp->f_flags & O_NONBLOCK) &&
(channel->wr_synchronous || !channel->wr_allow_partial ||
!channel->wr_supports_nonempty)) {
dev_err(endpoint->dev,
"open() failed: O_NONBLOCK not allowed for read on this device\n");
return -ENODEV;
}
if ((filp->f_mode & FMODE_WRITE) && (filp->f_flags & O_NONBLOCK) &&
(channel->rd_synchronous || !channel->rd_allow_partial)) {
dev_err(endpoint->dev,
"open() failed: O_NONBLOCK not allowed for write on this device\n");
return -ENODEV;
}
if (filp->f_mode & FMODE_READ) {
rc = mutex_lock_interruptible(&channel->wr_mutex);
if (rc)
return rc;
}
if (filp->f_mode & FMODE_WRITE) {
rc = mutex_lock_interruptible(&channel->rd_mutex);
if (rc)
goto unlock_wr;
}
if ((filp->f_mode & FMODE_READ) &&
(channel->wr_ref_count != 0) &&
(channel->wr_exclusive_open)) {
rc = -EBUSY;
goto unlock;
}
if ((filp->f_mode & FMODE_WRITE) &&
(channel->rd_ref_count != 0) &&
(channel->rd_exclusive_open)) {
rc = -EBUSY;
goto unlock;
}
if (filp->f_mode & FMODE_READ) {
if (channel->wr_ref_count == 0) {
spin_lock_irqsave(&channel->wr_spinlock, flags);
channel->wr_host_buf_idx = 0;
channel->wr_host_buf_pos = 0;
channel->wr_fpga_buf_idx = -1;
channel->wr_empty = 1;
channel->wr_ready = 0;
channel->wr_sleepy = 1;
channel->wr_eof = -1;
channel->wr_hangup = 0;
spin_unlock_irqrestore(&channel->wr_spinlock, flags);
iowrite32(1 | (channel->chan_num << 1) |
(4 << 24) |
((channel->wr_synchronous & 1) << 23),
channel->endpoint->registers +
fpga_buf_ctrl_reg);
mmiowb();
}
channel->wr_ref_count++;
}
if (filp->f_mode & FMODE_WRITE) {
if (channel->rd_ref_count == 0) {
spin_lock_irqsave(&channel->rd_spinlock, flags);
channel->rd_host_buf_idx = 0;
channel->rd_host_buf_pos = 0;
channel->rd_leftovers[3] = 0;
channel->rd_fpga_buf_idx = channel->num_rd_buffers - 1;
channel->rd_full = 0;
spin_unlock_irqrestore(&channel->rd_spinlock, flags);
iowrite32((channel->chan_num << 1) |
(4 << 24),
channel->endpoint->registers +
fpga_buf_ctrl_reg);
mmiowb();
}
channel->rd_ref_count++;
}
unlock:
if (filp->f_mode & FMODE_WRITE)
mutex_unlock(&channel->rd_mutex);
unlock_wr:
if (filp->f_mode & FMODE_READ)
mutex_unlock(&channel->wr_mutex);
if (!rc && (!channel->seekable))
return nonseekable_open(inode, filp);
return rc;
}
static int xillybus_release(struct inode *inode, struct file *filp)
{
int rc;
unsigned long flags;
struct xilly_channel *channel = filp->private_data;
int buf_idx;
int eof;
if (channel->endpoint->fatal_error)
return -EIO;
if (filp->f_mode & FMODE_WRITE) {
rc = mutex_lock_interruptible(&channel->rd_mutex);
if (rc) {
dev_warn(channel->endpoint->dev,
"Failed to close file. Hardware left in messy state.\n");
return rc;
}
channel->rd_ref_count--;
if (channel->rd_ref_count == 0) {
iowrite32((channel->chan_num << 1) |
(5 << 24),
channel->endpoint->registers +
fpga_buf_ctrl_reg);
mmiowb();
}
mutex_unlock(&channel->rd_mutex);
}
if (filp->f_mode & FMODE_READ) {
rc = mutex_lock_interruptible(&channel->wr_mutex);
if (rc) {
dev_warn(channel->endpoint->dev,
"Failed to close file. Hardware left in messy state.\n");
return rc;
}
channel->wr_ref_count--;
if (channel->wr_ref_count == 0) {
iowrite32(1 | (channel->chan_num << 1) |
(5 << 24),
channel->endpoint->registers +
fpga_buf_ctrl_reg);
mmiowb();
while (1) {
spin_lock_irqsave(&channel->wr_spinlock,
flags);
buf_idx = channel->wr_fpga_buf_idx;
eof = channel->wr_eof;
channel->wr_sleepy = 1;
spin_unlock_irqrestore(&channel->wr_spinlock,
flags);
buf_idx++;
if (buf_idx == channel->num_wr_buffers)
buf_idx = 0;
if (buf_idx == eof)
break;
if (wait_event_interruptible(
channel->wr_wait,
(!channel->wr_sleepy)))
msleep(100);
if (channel->wr_sleepy) {
mutex_unlock(&channel->wr_mutex);
dev_warn(channel->endpoint->dev,
"Hardware failed to respond to close command, therefore left in messy state.\n");
return -EINTR;
}
}
}
mutex_unlock(&channel->wr_mutex);
}
return 0;
}
static loff_t xillybus_llseek(struct file *filp, loff_t offset, int whence)
{
struct xilly_channel *channel = filp->private_data;
loff_t pos = filp->f_pos;
int rc = 0;
if (channel->endpoint->fatal_error)
return -EIO;
mutex_lock(&channel->wr_mutex);
mutex_lock(&channel->rd_mutex);
switch (whence) {
case 0:
pos = offset;
break;
case 1:
pos += offset;
break;
case 2:
pos = offset;
break;
default:
rc = -EINVAL;
goto end;
}
if (pos & ((1 << channel->log2_element_size) - 1)) {
rc = -EINVAL;
goto end;
}
mutex_lock(&channel->endpoint->register_mutex);
iowrite32(pos >> channel->log2_element_size,
channel->endpoint->registers + fpga_buf_offset_reg);
mmiowb();
iowrite32((channel->chan_num << 1) |
(6 << 24),
channel->endpoint->registers + fpga_buf_ctrl_reg);
mmiowb();
mutex_unlock(&channel->endpoint->register_mutex);
end:
mutex_unlock(&channel->rd_mutex);
mutex_unlock(&channel->wr_mutex);
if (rc)
return rc;
filp->f_pos = pos;
channel->rd_leftovers[3] = 0;
return pos;
}
static unsigned int xillybus_poll(struct file *filp, poll_table *wait)
{
struct xilly_channel *channel = filp->private_data;
unsigned int mask = 0;
unsigned long flags;
poll_wait(filp, &channel->endpoint->ep_wait, wait);
if (!channel->wr_synchronous && channel->wr_supports_nonempty) {
poll_wait(filp, &channel->wr_wait, wait);
poll_wait(filp, &channel->wr_ready_wait, wait);
spin_lock_irqsave(&channel->wr_spinlock, flags);
if (!channel->wr_empty || channel->wr_ready)
mask |= POLLIN | POLLRDNORM;
if (channel->wr_hangup)
mask |= POLLIN | POLLRDNORM;
spin_unlock_irqrestore(&channel->wr_spinlock, flags);
}
if (channel->rd_allow_partial) {
poll_wait(filp, &channel->rd_wait, wait);
spin_lock_irqsave(&channel->rd_spinlock, flags);
if (!channel->rd_full)
mask |= POLLOUT | POLLWRNORM;
spin_unlock_irqrestore(&channel->rd_spinlock, flags);
}
if (channel->endpoint->fatal_error)
mask |= POLLERR;
return mask;
}
static int xillybus_init_chrdev(struct xilly_endpoint *endpoint,
const unsigned char *idt)
{
int rc;
dev_t dev;
int devnum, i, minor, major;
char devname[48];
struct device *device;
rc = alloc_chrdev_region(&dev, 0,
endpoint->num_channels,
xillyname);
if (rc) {
dev_warn(endpoint->dev, "Failed to obtain major/minors");
goto error1;
}
endpoint->major = major = MAJOR(dev);
endpoint->lowest_minor = minor = MINOR(dev);
cdev_init(&endpoint->cdev, &xillybus_fops);
endpoint->cdev.owner = endpoint->ephw->owner;
rc = cdev_add(&endpoint->cdev, MKDEV(major, minor),
endpoint->num_channels);
if (rc) {
dev_warn(endpoint->dev, "Failed to add cdev. Aborting.\n");
goto error2;
}
idt++;
for (i = minor, devnum = 0;
devnum < endpoint->num_channels;
devnum++, i++) {
snprintf(devname, sizeof(devname)-1, "xillybus_%s", idt);
devname[sizeof(devname)-1] = 0;
while (*idt++)
;
device = device_create(xillybus_class,
NULL,
MKDEV(major, i),
NULL,
"%s", devname);
if (IS_ERR(device)) {
dev_warn(endpoint->dev,
"Failed to create %s device. Aborting.\n",
devname);
goto error3;
}
}
dev_info(endpoint->dev, "Created %d device files.\n",
endpoint->num_channels);
return 0;
error3:
devnum--; i--;
for (; devnum >= 0; devnum--, i--)
device_destroy(xillybus_class, MKDEV(major, i));
cdev_del(&endpoint->cdev);
error2:
unregister_chrdev_region(MKDEV(major, minor), endpoint->num_channels);
error1:
return rc;
}
static void xillybus_cleanup_chrdev(struct xilly_endpoint *endpoint)
{
int minor;
for (minor = endpoint->lowest_minor;
minor < (endpoint->lowest_minor + endpoint->num_channels);
minor++)
device_destroy(xillybus_class, MKDEV(endpoint->major, minor));
cdev_del(&endpoint->cdev);
unregister_chrdev_region(MKDEV(endpoint->major,
endpoint->lowest_minor),
endpoint->num_channels);
dev_info(endpoint->dev, "Removed %d device files.\n",
endpoint->num_channels);
}
struct xilly_endpoint *xillybus_init_endpoint(struct pci_dev *pdev,
struct device *dev,
struct xilly_endpoint_hardware
*ephw)
{
struct xilly_endpoint *endpoint;
endpoint = devm_kzalloc(dev, sizeof(*endpoint), GFP_KERNEL);
if (!endpoint)
return NULL;
endpoint->pdev = pdev;
endpoint->dev = dev;
endpoint->ephw = ephw;
endpoint->msg_counter = 0x0b;
endpoint->failed_messages = 0;
endpoint->fatal_error = 0;
init_waitqueue_head(&endpoint->ep_wait);
mutex_init(&endpoint->register_mutex);
return endpoint;
}
static int xilly_quiesce(struct xilly_endpoint *endpoint)
{
endpoint->idtlen = -1;
wmb();
iowrite32((u32) (endpoint->dma_using_dac & 0x0001),
endpoint->registers + fpga_dma_control_reg);
mmiowb();
wait_event_interruptible_timeout(endpoint->ep_wait,
(endpoint->idtlen >= 0),
XILLY_TIMEOUT);
if (endpoint->idtlen < 0) {
dev_err(endpoint->dev,
"Failed to quiesce the device on exit.\n");
return -ENODEV;
}
return 0;
}
int xillybus_endpoint_discovery(struct xilly_endpoint *endpoint)
{
int rc = 0;
void *bootstrap_resources;
int idtbuffersize = (1 << PAGE_SHIFT);
struct device *dev = endpoint->dev;
unsigned char bogus_idt[8] = { 1, 224, (PAGE_SHIFT)-2, 0,
3, 192, PAGE_SHIFT, 0 };
struct xilly_idt_handle idt_handle;
iowrite32(1, endpoint->registers + fpga_endian_reg);
mmiowb();
bootstrap_resources = devres_open_group(dev, NULL, GFP_KERNEL);
if (!bootstrap_resources)
return -ENOMEM;
endpoint->num_channels = 0;
rc = xilly_setupchannels(endpoint, bogus_idt, 1);
if (rc)
return rc;
iowrite32(0x04, endpoint->registers + fpga_msg_ctrl_reg);
mmiowb();
endpoint->idtlen = -1;
smp_wmb();
iowrite32((u32) (endpoint->dma_using_dac & 0x0001),
endpoint->registers + fpga_dma_control_reg);
mmiowb();
wait_event_interruptible_timeout(endpoint->ep_wait,
(endpoint->idtlen >= 0),
XILLY_TIMEOUT);
if (endpoint->idtlen < 0) {
dev_err(endpoint->dev, "No response from FPGA. Aborting.\n");
return -ENODEV;
}
iowrite32((u32) (0x0002 | (endpoint->dma_using_dac & 0x0001)),
endpoint->registers + fpga_dma_control_reg);
mmiowb();
while (endpoint->idtlen >= idtbuffersize) {
idtbuffersize *= 2;
bogus_idt[6]++;
}
endpoint->num_channels = 1;
rc = xilly_setupchannels(endpoint, bogus_idt, 2);
if (rc)
goto failed_idt;
smp_wmb();
rc = xilly_obtain_idt(endpoint);
if (rc)
goto failed_idt;
xilly_scan_idt(endpoint, &idt_handle);
if (!idt_handle.chandesc) {
rc = -ENODEV;
goto failed_idt;
}
devres_close_group(dev, bootstrap_resources);
rc = xilly_setupchannels(endpoint,
idt_handle.chandesc,
idt_handle.entries);
if (rc)
goto failed_idt;
smp_wmb();
mutex_lock(&ep_list_lock);
list_add_tail(&endpoint->ep_list, &list_of_endpoints);
mutex_unlock(&ep_list_lock);
rc = xillybus_init_chrdev(endpoint, idt_handle.idt);
if (rc)
goto failed_chrdevs;
devres_release_group(dev, bootstrap_resources);
return 0;
failed_chrdevs:
mutex_lock(&ep_list_lock);
list_del(&endpoint->ep_list);
mutex_unlock(&ep_list_lock);
failed_idt:
xilly_quiesce(endpoint);
flush_workqueue(xillybus_wq);
return rc;
}
void xillybus_endpoint_remove(struct xilly_endpoint *endpoint)
{
xillybus_cleanup_chrdev(endpoint);
mutex_lock(&ep_list_lock);
list_del(&endpoint->ep_list);
mutex_unlock(&ep_list_lock);
xilly_quiesce(endpoint);
flush_workqueue(xillybus_wq);
}
static int __init xillybus_init(void)
{
int rc = 0;
mutex_init(&ep_list_lock);
xillybus_class = class_create(THIS_MODULE, xillyname);
if (IS_ERR(xillybus_class)) {
rc = PTR_ERR(xillybus_class);
pr_warn("Failed to register class xillybus\n");
return rc;
}
xillybus_wq = alloc_workqueue(xillyname, 0, 0);
if (!xillybus_wq) {
class_destroy(xillybus_class);
rc = -ENOMEM;
}
return rc;
}
static void __exit xillybus_exit(void)
{
destroy_workqueue(xillybus_wq);
class_destroy(xillybus_class);
}
