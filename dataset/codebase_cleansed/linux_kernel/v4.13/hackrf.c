static int hackrf_ctrl_msg(struct hackrf_dev *dev, u8 request, u16 value,
u16 index, u8 *data, u16 size)
{
int ret;
unsigned int pipe;
u8 requesttype;
switch (request) {
case CMD_SET_TRANSCEIVER_MODE:
case CMD_SET_FREQ:
case CMD_AMP_ENABLE:
case CMD_SAMPLE_RATE_SET:
case CMD_BASEBAND_FILTER_BANDWIDTH_SET:
pipe = usb_sndctrlpipe(dev->udev, 0);
requesttype = (USB_TYPE_VENDOR | USB_DIR_OUT);
break;
case CMD_BOARD_ID_READ:
case CMD_VERSION_STRING_READ:
case CMD_SET_LNA_GAIN:
case CMD_SET_VGA_GAIN:
case CMD_SET_TXVGA_GAIN:
pipe = usb_rcvctrlpipe(dev->udev, 0);
requesttype = (USB_TYPE_VENDOR | USB_DIR_IN);
break;
default:
dev_err(dev->dev, "Unknown command %02x\n", request);
ret = -EINVAL;
goto err;
}
if (!(requesttype & USB_DIR_IN))
memcpy(dev->buf, data, size);
ret = usb_control_msg(dev->udev, pipe, request, requesttype, value,
index, dev->buf, size, 1000);
hackrf_dbg_usb_control_msg(dev->dev, request, requesttype, value,
index, dev->buf, size);
if (ret < 0) {
dev_err(dev->dev, "usb_control_msg() failed %d request %02x\n",
ret, request);
goto err;
}
if (requesttype & USB_DIR_IN)
memcpy(data, dev->buf, size);
return 0;
err:
return ret;
}
static int hackrf_set_params(struct hackrf_dev *dev)
{
struct usb_interface *intf = dev->intf;
int ret, i;
u8 buf[8], u8tmp;
unsigned int uitmp, uitmp1, uitmp2;
const bool rx = test_bit(RX_ON, &dev->flags);
const bool tx = test_bit(TX_ON, &dev->flags);
static const struct {
u32 freq;
} bandwidth_lut[] = {
{ 1750000},
{ 2500000},
{ 3500000},
{ 5000000},
{ 5500000},
{ 6000000},
{ 7000000},
{ 8000000},
{ 9000000},
{10000000},
{12000000},
{14000000},
{15000000},
{20000000},
{24000000},
{28000000},
};
if (!rx && !tx) {
dev_dbg(&intf->dev, "device is sleeping\n");
return 0;
}
if (rx && test_and_clear_bit(RX_ADC_FREQUENCY, &dev->flags)) {
dev_dbg(&intf->dev, "RX ADC frequency=%u Hz\n", dev->f_adc);
uitmp1 = dev->f_adc;
uitmp2 = 1;
set_bit(TX_DAC_FREQUENCY, &dev->flags);
} else if (tx && test_and_clear_bit(TX_DAC_FREQUENCY, &dev->flags)) {
dev_dbg(&intf->dev, "TX DAC frequency=%u Hz\n", dev->f_dac);
uitmp1 = dev->f_dac;
uitmp2 = 1;
set_bit(RX_ADC_FREQUENCY, &dev->flags);
} else {
uitmp1 = uitmp2 = 0;
}
if (uitmp1 || uitmp2) {
buf[0] = (uitmp1 >> 0) & 0xff;
buf[1] = (uitmp1 >> 8) & 0xff;
buf[2] = (uitmp1 >> 16) & 0xff;
buf[3] = (uitmp1 >> 24) & 0xff;
buf[4] = (uitmp2 >> 0) & 0xff;
buf[5] = (uitmp2 >> 8) & 0xff;
buf[6] = (uitmp2 >> 16) & 0xff;
buf[7] = (uitmp2 >> 24) & 0xff;
ret = hackrf_ctrl_msg(dev, CMD_SAMPLE_RATE_SET, 0, 0, buf, 8);
if (ret)
goto err;
}
if (rx && test_and_clear_bit(RX_BANDWIDTH, &dev->flags)) {
if (dev->rx_bandwidth_auto->val == true)
uitmp = dev->f_adc;
else
uitmp = dev->rx_bandwidth->val;
for (i = 0; i < ARRAY_SIZE(bandwidth_lut); i++) {
if (uitmp <= bandwidth_lut[i].freq) {
uitmp = bandwidth_lut[i].freq;
break;
}
}
dev->rx_bandwidth->val = uitmp;
dev->rx_bandwidth->cur.val = uitmp;
dev_dbg(&intf->dev, "RX bandwidth selected=%u\n", uitmp);
set_bit(TX_BANDWIDTH, &dev->flags);
} else if (tx && test_and_clear_bit(TX_BANDWIDTH, &dev->flags)) {
if (dev->tx_bandwidth_auto->val == true)
uitmp = dev->f_dac;
else
uitmp = dev->tx_bandwidth->val;
for (i = 0; i < ARRAY_SIZE(bandwidth_lut); i++) {
if (uitmp <= bandwidth_lut[i].freq) {
uitmp = bandwidth_lut[i].freq;
break;
}
}
dev->tx_bandwidth->val = uitmp;
dev->tx_bandwidth->cur.val = uitmp;
dev_dbg(&intf->dev, "TX bandwidth selected=%u\n", uitmp);
set_bit(RX_BANDWIDTH, &dev->flags);
} else {
uitmp = 0;
}
if (uitmp) {
uitmp1 = uitmp2 = 0;
uitmp1 |= ((uitmp >> 0) & 0xff) << 0;
uitmp1 |= ((uitmp >> 8) & 0xff) << 8;
uitmp2 |= ((uitmp >> 16) & 0xff) << 0;
uitmp2 |= ((uitmp >> 24) & 0xff) << 8;
ret = hackrf_ctrl_msg(dev, CMD_BASEBAND_FILTER_BANDWIDTH_SET,
uitmp1, uitmp2, NULL, 0);
if (ret)
goto err;
}
if (rx && test_and_clear_bit(RX_RF_FREQUENCY, &dev->flags)) {
dev_dbg(&intf->dev, "RX RF frequency=%u Hz\n", dev->f_rx);
uitmp1 = dev->f_rx / 1000000;
uitmp2 = dev->f_rx % 1000000;
set_bit(TX_RF_FREQUENCY, &dev->flags);
} else if (tx && test_and_clear_bit(TX_RF_FREQUENCY, &dev->flags)) {
dev_dbg(&intf->dev, "TX RF frequency=%u Hz\n", dev->f_tx);
uitmp1 = dev->f_tx / 1000000;
uitmp2 = dev->f_tx % 1000000;
set_bit(RX_RF_FREQUENCY, &dev->flags);
} else {
uitmp1 = uitmp2 = 0;
}
if (uitmp1 || uitmp2) {
buf[0] = (uitmp1 >> 0) & 0xff;
buf[1] = (uitmp1 >> 8) & 0xff;
buf[2] = (uitmp1 >> 16) & 0xff;
buf[3] = (uitmp1 >> 24) & 0xff;
buf[4] = (uitmp2 >> 0) & 0xff;
buf[5] = (uitmp2 >> 8) & 0xff;
buf[6] = (uitmp2 >> 16) & 0xff;
buf[7] = (uitmp2 >> 24) & 0xff;
ret = hackrf_ctrl_msg(dev, CMD_SET_FREQ, 0, 0, buf, 8);
if (ret)
goto err;
}
if (rx && test_and_clear_bit(RX_RF_GAIN, &dev->flags)) {
dev_dbg(&intf->dev, "RX RF gain val=%d->%d\n",
dev->rx_rf_gain->cur.val, dev->rx_rf_gain->val);
u8tmp = (dev->rx_rf_gain->val) ? 1 : 0;
ret = hackrf_ctrl_msg(dev, CMD_AMP_ENABLE, u8tmp, 0, NULL, 0);
if (ret)
goto err;
set_bit(TX_RF_GAIN, &dev->flags);
}
if (tx && test_and_clear_bit(TX_RF_GAIN, &dev->flags)) {
dev_dbg(&intf->dev, "TX RF gain val=%d->%d\n",
dev->tx_rf_gain->cur.val, dev->tx_rf_gain->val);
u8tmp = (dev->tx_rf_gain->val) ? 1 : 0;
ret = hackrf_ctrl_msg(dev, CMD_AMP_ENABLE, u8tmp, 0, NULL, 0);
if (ret)
goto err;
set_bit(RX_RF_GAIN, &dev->flags);
}
if (rx && test_and_clear_bit(RX_LNA_GAIN, &dev->flags)) {
dev_dbg(dev->dev, "RX LNA gain val=%d->%d\n",
dev->rx_lna_gain->cur.val, dev->rx_lna_gain->val);
ret = hackrf_ctrl_msg(dev, CMD_SET_LNA_GAIN, 0,
dev->rx_lna_gain->val, &u8tmp, 1);
if (ret)
goto err;
}
if (rx && test_and_clear_bit(RX_IF_GAIN, &dev->flags)) {
dev_dbg(&intf->dev, "IF gain val=%d->%d\n",
dev->rx_if_gain->cur.val, dev->rx_if_gain->val);
ret = hackrf_ctrl_msg(dev, CMD_SET_VGA_GAIN, 0,
dev->rx_if_gain->val, &u8tmp, 1);
if (ret)
goto err;
}
if (tx && test_and_clear_bit(TX_LNA_GAIN, &dev->flags)) {
dev_dbg(&intf->dev, "TX LNA gain val=%d->%d\n",
dev->tx_lna_gain->cur.val, dev->tx_lna_gain->val);
ret = hackrf_ctrl_msg(dev, CMD_SET_TXVGA_GAIN, 0,
dev->tx_lna_gain->val, &u8tmp, 1);
if (ret)
goto err;
}
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static struct hackrf_buffer *hackrf_get_next_buffer(struct hackrf_dev *dev,
struct list_head *buffer_list)
{
unsigned long flags;
struct hackrf_buffer *buffer = NULL;
spin_lock_irqsave(&dev->buffer_list_lock, flags);
if (list_empty(buffer_list))
goto leave;
buffer = list_entry(buffer_list->next, struct hackrf_buffer, list);
list_del(&buffer->list);
leave:
spin_unlock_irqrestore(&dev->buffer_list_lock, flags);
return buffer;
}
static void hackrf_copy_stream(struct hackrf_dev *dev, void *dst, void *src,
unsigned int src_len)
{
memcpy(dst, src, src_len);
if (unlikely(time_is_before_jiffies(dev->jiffies_next))) {
#define MSECS 10000UL
unsigned int msecs = jiffies_to_msecs(jiffies -
dev->jiffies_next + msecs_to_jiffies(MSECS));
unsigned int samples = dev->sample - dev->sample_measured;
dev->jiffies_next = jiffies + msecs_to_jiffies(MSECS);
dev->sample_measured = dev->sample;
dev_dbg(dev->dev, "slen=%u samples=%u msecs=%u sample rate=%lu\n",
src_len, samples, msecs,
samples * 1000UL / msecs);
}
dev->sample += src_len / 2;
}
static void hackrf_urb_complete_in(struct urb *urb)
{
struct hackrf_dev *dev = urb->context;
struct usb_interface *intf = dev->intf;
struct hackrf_buffer *buffer;
unsigned int len;
dev_dbg_ratelimited(&intf->dev, "status=%d length=%u/%u\n", urb->status,
urb->actual_length, urb->transfer_buffer_length);
switch (urb->status) {
case 0:
case -ETIMEDOUT:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
dev_err_ratelimited(&intf->dev, "URB failed %d\n", urb->status);
goto exit_usb_submit_urb;
}
buffer = hackrf_get_next_buffer(dev, &dev->rx_buffer_list);
if (unlikely(buffer == NULL)) {
dev->vb_full++;
dev_notice_ratelimited(&intf->dev,
"buffer is full - %u packets dropped\n",
dev->vb_full);
goto exit_usb_submit_urb;
}
len = min_t(unsigned long, vb2_plane_size(&buffer->vb.vb2_buf, 0),
urb->actual_length);
hackrf_copy_stream(dev, vb2_plane_vaddr(&buffer->vb.vb2_buf, 0),
urb->transfer_buffer, len);
vb2_set_plane_payload(&buffer->vb.vb2_buf, 0, len);
buffer->vb.sequence = dev->sequence++;
buffer->vb.vb2_buf.timestamp = ktime_get_ns();
vb2_buffer_done(&buffer->vb.vb2_buf, VB2_BUF_STATE_DONE);
exit_usb_submit_urb:
usb_submit_urb(urb, GFP_ATOMIC);
}
static void hackrf_urb_complete_out(struct urb *urb)
{
struct hackrf_dev *dev = urb->context;
struct usb_interface *intf = dev->intf;
struct hackrf_buffer *buffer;
unsigned int len;
dev_dbg_ratelimited(&intf->dev, "status=%d length=%u/%u\n", urb->status,
urb->actual_length, urb->transfer_buffer_length);
switch (urb->status) {
case 0:
case -ETIMEDOUT:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
dev_err_ratelimited(&intf->dev, "URB failed %d\n", urb->status);
}
buffer = hackrf_get_next_buffer(dev, &dev->tx_buffer_list);
if (unlikely(buffer == NULL)) {
dev->vb_empty++;
dev_notice_ratelimited(&intf->dev,
"buffer is empty - %u packets dropped\n",
dev->vb_empty);
urb->actual_length = 0;
goto exit_usb_submit_urb;
}
len = min_t(unsigned long, urb->transfer_buffer_length,
vb2_get_plane_payload(&buffer->vb.vb2_buf, 0));
hackrf_copy_stream(dev, urb->transfer_buffer,
vb2_plane_vaddr(&buffer->vb.vb2_buf, 0), len);
urb->actual_length = len;
buffer->vb.sequence = dev->sequence++;
buffer->vb.vb2_buf.timestamp = ktime_get_ns();
vb2_buffer_done(&buffer->vb.vb2_buf, VB2_BUF_STATE_DONE);
exit_usb_submit_urb:
usb_submit_urb(urb, GFP_ATOMIC);
}
static int hackrf_kill_urbs(struct hackrf_dev *dev)
{
int i;
for (i = dev->urbs_submitted - 1; i >= 0; i--) {
dev_dbg(dev->dev, "kill urb=%d\n", i);
usb_kill_urb(dev->urb_list[i]);
}
dev->urbs_submitted = 0;
return 0;
}
static int hackrf_submit_urbs(struct hackrf_dev *dev)
{
int i, ret;
for (i = 0; i < dev->urbs_initialized; i++) {
dev_dbg(dev->dev, "submit urb=%d\n", i);
ret = usb_submit_urb(dev->urb_list[i], GFP_ATOMIC);
if (ret) {
dev_err(dev->dev, "Could not submit URB no. %d - get them all back\n",
i);
hackrf_kill_urbs(dev);
return ret;
}
dev->urbs_submitted++;
}
return 0;
}
static int hackrf_free_stream_bufs(struct hackrf_dev *dev)
{
if (dev->flags & USB_STATE_URB_BUF) {
while (dev->buf_num) {
dev->buf_num--;
dev_dbg(dev->dev, "free buf=%d\n", dev->buf_num);
usb_free_coherent(dev->udev, dev->buf_size,
dev->buf_list[dev->buf_num],
dev->dma_addr[dev->buf_num]);
}
}
dev->flags &= ~USB_STATE_URB_BUF;
return 0;
}
static int hackrf_alloc_stream_bufs(struct hackrf_dev *dev)
{
dev->buf_num = 0;
dev->buf_size = BULK_BUFFER_SIZE;
dev_dbg(dev->dev, "all in all I will use %u bytes for streaming\n",
MAX_BULK_BUFS * BULK_BUFFER_SIZE);
for (dev->buf_num = 0; dev->buf_num < MAX_BULK_BUFS; dev->buf_num++) {
dev->buf_list[dev->buf_num] = usb_alloc_coherent(dev->udev,
BULK_BUFFER_SIZE, GFP_ATOMIC,
&dev->dma_addr[dev->buf_num]);
if (!dev->buf_list[dev->buf_num]) {
dev_dbg(dev->dev, "alloc buf=%d failed\n",
dev->buf_num);
hackrf_free_stream_bufs(dev);
return -ENOMEM;
}
dev_dbg(dev->dev, "alloc buf=%d %p (dma %llu)\n", dev->buf_num,
dev->buf_list[dev->buf_num],
(long long)dev->dma_addr[dev->buf_num]);
dev->flags |= USB_STATE_URB_BUF;
}
return 0;
}
static int hackrf_free_urbs(struct hackrf_dev *dev)
{
int i;
hackrf_kill_urbs(dev);
for (i = dev->urbs_initialized - 1; i >= 0; i--) {
if (dev->urb_list[i]) {
dev_dbg(dev->dev, "free urb=%d\n", i);
usb_free_urb(dev->urb_list[i]);
}
}
dev->urbs_initialized = 0;
return 0;
}
static int hackrf_alloc_urbs(struct hackrf_dev *dev, bool rcv)
{
int i, j;
unsigned int pipe;
usb_complete_t complete;
if (rcv) {
pipe = usb_rcvbulkpipe(dev->udev, 0x81);
complete = &hackrf_urb_complete_in;
} else {
pipe = usb_sndbulkpipe(dev->udev, 0x02);
complete = &hackrf_urb_complete_out;
}
for (i = 0; i < MAX_BULK_BUFS; i++) {
dev_dbg(dev->dev, "alloc urb=%d\n", i);
dev->urb_list[i] = usb_alloc_urb(0, GFP_ATOMIC);
if (!dev->urb_list[i]) {
for (j = 0; j < i; j++)
usb_free_urb(dev->urb_list[j]);
return -ENOMEM;
}
usb_fill_bulk_urb(dev->urb_list[i],
dev->udev,
pipe,
dev->buf_list[i],
BULK_BUFFER_SIZE,
complete, dev);
dev->urb_list[i]->transfer_flags = URB_NO_TRANSFER_DMA_MAP;
dev->urb_list[i]->transfer_dma = dev->dma_addr[i];
dev->urbs_initialized++;
}
return 0;
}
static void hackrf_disconnect(struct usb_interface *intf)
{
struct v4l2_device *v = usb_get_intfdata(intf);
struct hackrf_dev *dev = container_of(v, struct hackrf_dev, v4l2_dev);
dev_dbg(dev->dev, "\n");
mutex_lock(&dev->vb_queue_lock);
mutex_lock(&dev->v4l2_lock);
dev->udev = NULL;
v4l2_device_disconnect(&dev->v4l2_dev);
video_unregister_device(&dev->tx_vdev);
video_unregister_device(&dev->rx_vdev);
mutex_unlock(&dev->v4l2_lock);
mutex_unlock(&dev->vb_queue_lock);
v4l2_device_put(&dev->v4l2_dev);
}
static void hackrf_return_all_buffers(struct vb2_queue *vq,
enum vb2_buffer_state state)
{
struct hackrf_dev *dev = vb2_get_drv_priv(vq);
struct usb_interface *intf = dev->intf;
struct hackrf_buffer *buffer, *node;
struct list_head *buffer_list;
unsigned long flags;
dev_dbg(&intf->dev, "\n");
if (vq->type == V4L2_BUF_TYPE_SDR_CAPTURE)
buffer_list = &dev->rx_buffer_list;
else
buffer_list = &dev->tx_buffer_list;
spin_lock_irqsave(&dev->buffer_list_lock, flags);
list_for_each_entry_safe(buffer, node, buffer_list, list) {
dev_dbg(&intf->dev, "list_for_each_entry_safe\n");
vb2_buffer_done(&buffer->vb.vb2_buf, state);
list_del(&buffer->list);
}
spin_unlock_irqrestore(&dev->buffer_list_lock, flags);
}
static int hackrf_queue_setup(struct vb2_queue *vq,
unsigned int *nbuffers,
unsigned int *nplanes, unsigned int sizes[], struct device *alloc_devs[])
{
struct hackrf_dev *dev = vb2_get_drv_priv(vq);
dev_dbg(dev->dev, "nbuffers=%d\n", *nbuffers);
if (vq->num_buffers + *nbuffers < 8)
*nbuffers = 8 - vq->num_buffers;
*nplanes = 1;
sizes[0] = PAGE_ALIGN(dev->buffersize);
dev_dbg(dev->dev, "nbuffers=%d sizes[0]=%d\n", *nbuffers, sizes[0]);
return 0;
}
static void hackrf_buf_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vb2_queue *vq = vb->vb2_queue;
struct hackrf_dev *dev = vb2_get_drv_priv(vq);
struct hackrf_buffer *buffer = container_of(vbuf, struct hackrf_buffer, vb);
struct list_head *buffer_list;
unsigned long flags;
dev_dbg_ratelimited(&dev->intf->dev, "\n");
if (vq->type == V4L2_BUF_TYPE_SDR_CAPTURE)
buffer_list = &dev->rx_buffer_list;
else
buffer_list = &dev->tx_buffer_list;
spin_lock_irqsave(&dev->buffer_list_lock, flags);
list_add_tail(&buffer->list, buffer_list);
spin_unlock_irqrestore(&dev->buffer_list_lock, flags);
}
static int hackrf_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct hackrf_dev *dev = vb2_get_drv_priv(vq);
struct usb_interface *intf = dev->intf;
int ret;
unsigned int mode;
dev_dbg(&intf->dev, "count=%i\n", count);
mutex_lock(&dev->v4l2_lock);
if (vq->type == V4L2_BUF_TYPE_SDR_CAPTURE) {
if (test_bit(TX_ON, &dev->flags)) {
ret = -EBUSY;
goto err_hackrf_return_all_buffers;
}
mode = 1;
set_bit(RX_ON, &dev->flags);
} else {
if (test_bit(RX_ON, &dev->flags)) {
ret = -EBUSY;
goto err_hackrf_return_all_buffers;
}
mode = 2;
set_bit(TX_ON, &dev->flags);
}
dev->sequence = 0;
ret = hackrf_alloc_stream_bufs(dev);
if (ret)
goto err;
ret = hackrf_alloc_urbs(dev, (mode == 1));
if (ret)
goto err;
ret = hackrf_submit_urbs(dev);
if (ret)
goto err;
ret = hackrf_set_params(dev);
if (ret)
goto err;
ret = hackrf_ctrl_msg(dev, CMD_SET_TRANSCEIVER_MODE, mode, 0, NULL, 0);
if (ret)
goto err;
mutex_unlock(&dev->v4l2_lock);
return 0;
err:
hackrf_kill_urbs(dev);
hackrf_free_urbs(dev);
hackrf_free_stream_bufs(dev);
clear_bit(RX_ON, &dev->flags);
clear_bit(TX_ON, &dev->flags);
err_hackrf_return_all_buffers:
hackrf_return_all_buffers(vq, VB2_BUF_STATE_QUEUED);
mutex_unlock(&dev->v4l2_lock);
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static void hackrf_stop_streaming(struct vb2_queue *vq)
{
struct hackrf_dev *dev = vb2_get_drv_priv(vq);
struct usb_interface *intf = dev->intf;
dev_dbg(&intf->dev, "\n");
mutex_lock(&dev->v4l2_lock);
hackrf_ctrl_msg(dev, CMD_SET_TRANSCEIVER_MODE, 0, 0, NULL, 0);
hackrf_kill_urbs(dev);
hackrf_free_urbs(dev);
hackrf_free_stream_bufs(dev);
hackrf_return_all_buffers(vq, VB2_BUF_STATE_ERROR);
if (vq->type == V4L2_BUF_TYPE_SDR_CAPTURE)
clear_bit(RX_ON, &dev->flags);
else
clear_bit(TX_ON, &dev->flags);
mutex_unlock(&dev->v4l2_lock);
}
static int hackrf_querycap(struct file *file, void *fh,
struct v4l2_capability *cap)
{
struct hackrf_dev *dev = video_drvdata(file);
struct usb_interface *intf = dev->intf;
struct video_device *vdev = video_devdata(file);
dev_dbg(&intf->dev, "\n");
if (vdev->vfl_dir == VFL_DIR_RX)
cap->device_caps = V4L2_CAP_SDR_CAPTURE | V4L2_CAP_TUNER |
V4L2_CAP_STREAMING | V4L2_CAP_READWRITE;
else
cap->device_caps = V4L2_CAP_SDR_OUTPUT | V4L2_CAP_MODULATOR |
V4L2_CAP_STREAMING | V4L2_CAP_READWRITE;
cap->capabilities = V4L2_CAP_SDR_CAPTURE | V4L2_CAP_TUNER |
V4L2_CAP_SDR_OUTPUT | V4L2_CAP_MODULATOR |
V4L2_CAP_STREAMING | V4L2_CAP_READWRITE |
V4L2_CAP_DEVICE_CAPS;
strlcpy(cap->driver, KBUILD_MODNAME, sizeof(cap->driver));
strlcpy(cap->card, dev->rx_vdev.name, sizeof(cap->card));
usb_make_path(dev->udev, cap->bus_info, sizeof(cap->bus_info));
return 0;
}
static int hackrf_s_fmt_sdr(struct file *file, void *priv,
struct v4l2_format *f)
{
struct hackrf_dev *dev = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
struct vb2_queue *q;
int i;
dev_dbg(dev->dev, "pixelformat fourcc %4.4s\n",
(char *)&f->fmt.sdr.pixelformat);
if (vdev->vfl_dir == VFL_DIR_RX)
q = &dev->rx_vb2_queue;
else
q = &dev->tx_vb2_queue;
if (vb2_is_busy(q))
return -EBUSY;
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
for (i = 0; i < NUM_FORMATS; i++) {
if (f->fmt.sdr.pixelformat == formats[i].pixelformat) {
dev->pixelformat = formats[i].pixelformat;
dev->buffersize = formats[i].buffersize;
f->fmt.sdr.buffersize = formats[i].buffersize;
return 0;
}
}
dev->pixelformat = formats[0].pixelformat;
dev->buffersize = formats[0].buffersize;
f->fmt.sdr.pixelformat = formats[0].pixelformat;
f->fmt.sdr.buffersize = formats[0].buffersize;
return 0;
}
static int hackrf_g_fmt_sdr(struct file *file, void *priv,
struct v4l2_format *f)
{
struct hackrf_dev *dev = video_drvdata(file);
dev_dbg(dev->dev, "pixelformat fourcc %4.4s\n",
(char *)&dev->pixelformat);
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
f->fmt.sdr.pixelformat = dev->pixelformat;
f->fmt.sdr.buffersize = dev->buffersize;
return 0;
}
static int hackrf_try_fmt_sdr(struct file *file, void *priv,
struct v4l2_format *f)
{
struct hackrf_dev *dev = video_drvdata(file);
int i;
dev_dbg(dev->dev, "pixelformat fourcc %4.4s\n",
(char *)&f->fmt.sdr.pixelformat);
memset(f->fmt.sdr.reserved, 0, sizeof(f->fmt.sdr.reserved));
for (i = 0; i < NUM_FORMATS; i++) {
if (formats[i].pixelformat == f->fmt.sdr.pixelformat) {
f->fmt.sdr.buffersize = formats[i].buffersize;
return 0;
}
}
f->fmt.sdr.pixelformat = formats[0].pixelformat;
f->fmt.sdr.buffersize = formats[0].buffersize;
return 0;
}
static int hackrf_enum_fmt_sdr(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct hackrf_dev *dev = video_drvdata(file);
dev_dbg(dev->dev, "index=%d\n", f->index);
if (f->index >= NUM_FORMATS)
return -EINVAL;
f->pixelformat = formats[f->index].pixelformat;
return 0;
}
static int hackrf_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *v)
{
struct hackrf_dev *dev = video_drvdata(file);
int ret;
dev_dbg(dev->dev, "index=%d\n", v->index);
if (v->index == 0)
ret = 0;
else if (v->index == 1)
ret = 0;
else
ret = -EINVAL;
return ret;
}
static int hackrf_g_tuner(struct file *file, void *priv, struct v4l2_tuner *v)
{
struct hackrf_dev *dev = video_drvdata(file);
int ret;
dev_dbg(dev->dev, "index=%d\n", v->index);
if (v->index == 0) {
strlcpy(v->name, "HackRF ADC", sizeof(v->name));
v->type = V4L2_TUNER_SDR;
v->capability = V4L2_TUNER_CAP_1HZ | V4L2_TUNER_CAP_FREQ_BANDS;
v->rangelow = bands_adc_dac[0].rangelow;
v->rangehigh = bands_adc_dac[0].rangehigh;
ret = 0;
} else if (v->index == 1) {
strlcpy(v->name, "HackRF RF", sizeof(v->name));
v->type = V4L2_TUNER_RF;
v->capability = V4L2_TUNER_CAP_1HZ | V4L2_TUNER_CAP_FREQ_BANDS;
v->rangelow = bands_rx_tx[0].rangelow;
v->rangehigh = bands_rx_tx[0].rangehigh;
ret = 0;
} else {
ret = -EINVAL;
}
return ret;
}
static int hackrf_s_modulator(struct file *file, void *fh,
const struct v4l2_modulator *a)
{
struct hackrf_dev *dev = video_drvdata(file);
dev_dbg(dev->dev, "index=%d\n", a->index);
return a->index > 1 ? -EINVAL : 0;
}
static int hackrf_g_modulator(struct file *file, void *fh,
struct v4l2_modulator *a)
{
struct hackrf_dev *dev = video_drvdata(file);
int ret;
dev_dbg(dev->dev, "index=%d\n", a->index);
if (a->index == 0) {
strlcpy(a->name, "HackRF DAC", sizeof(a->name));
a->type = V4L2_TUNER_SDR;
a->capability = V4L2_TUNER_CAP_1HZ | V4L2_TUNER_CAP_FREQ_BANDS;
a->rangelow = bands_adc_dac[0].rangelow;
a->rangehigh = bands_adc_dac[0].rangehigh;
ret = 0;
} else if (a->index == 1) {
strlcpy(a->name, "HackRF RF", sizeof(a->name));
a->type = V4L2_TUNER_RF;
a->capability = V4L2_TUNER_CAP_1HZ | V4L2_TUNER_CAP_FREQ_BANDS;
a->rangelow = bands_rx_tx[0].rangelow;
a->rangehigh = bands_rx_tx[0].rangehigh;
ret = 0;
} else {
ret = -EINVAL;
}
return ret;
}
static int hackrf_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct hackrf_dev *dev = video_drvdata(file);
struct usb_interface *intf = dev->intf;
struct video_device *vdev = video_devdata(file);
int ret;
unsigned int uitmp;
dev_dbg(&intf->dev, "tuner=%d type=%d frequency=%u\n",
f->tuner, f->type, f->frequency);
if (f->tuner == 0) {
uitmp = clamp(f->frequency, bands_adc_dac[0].rangelow,
bands_adc_dac[0].rangehigh);
if (vdev->vfl_dir == VFL_DIR_RX) {
dev->f_adc = uitmp;
set_bit(RX_ADC_FREQUENCY, &dev->flags);
} else {
dev->f_dac = uitmp;
set_bit(TX_DAC_FREQUENCY, &dev->flags);
}
} else if (f->tuner == 1) {
uitmp = clamp(f->frequency, bands_rx_tx[0].rangelow,
bands_rx_tx[0].rangehigh);
if (vdev->vfl_dir == VFL_DIR_RX) {
dev->f_rx = uitmp;
set_bit(RX_RF_FREQUENCY, &dev->flags);
} else {
dev->f_tx = uitmp;
set_bit(TX_RF_FREQUENCY, &dev->flags);
}
} else {
ret = -EINVAL;
goto err;
}
ret = hackrf_set_params(dev);
if (ret)
goto err;
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int hackrf_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct hackrf_dev *dev = video_drvdata(file);
struct usb_interface *intf = dev->intf;
struct video_device *vdev = video_devdata(file);
int ret;
dev_dbg(dev->dev, "tuner=%d type=%d\n", f->tuner, f->type);
if (f->tuner == 0) {
f->type = V4L2_TUNER_SDR;
if (vdev->vfl_dir == VFL_DIR_RX)
f->frequency = dev->f_adc;
else
f->frequency = dev->f_dac;
} else if (f->tuner == 1) {
f->type = V4L2_TUNER_RF;
if (vdev->vfl_dir == VFL_DIR_RX)
f->frequency = dev->f_rx;
else
f->frequency = dev->f_tx;
} else {
ret = -EINVAL;
goto err;
}
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int hackrf_enum_freq_bands(struct file *file, void *priv,
struct v4l2_frequency_band *band)
{
struct hackrf_dev *dev = video_drvdata(file);
int ret;
dev_dbg(dev->dev, "tuner=%d type=%d index=%d\n",
band->tuner, band->type, band->index);
if (band->tuner == 0) {
if (band->index >= ARRAY_SIZE(bands_adc_dac)) {
ret = -EINVAL;
} else {
*band = bands_adc_dac[band->index];
ret = 0;
}
} else if (band->tuner == 1) {
if (band->index >= ARRAY_SIZE(bands_rx_tx)) {
ret = -EINVAL;
} else {
*band = bands_rx_tx[band->index];
ret = 0;
}
} else {
ret = -EINVAL;
}
return ret;
}
static void hackrf_video_release(struct v4l2_device *v)
{
struct hackrf_dev *dev = container_of(v, struct hackrf_dev, v4l2_dev);
dev_dbg(dev->dev, "\n");
v4l2_ctrl_handler_free(&dev->rx_ctrl_handler);
v4l2_ctrl_handler_free(&dev->tx_ctrl_handler);
v4l2_device_unregister(&dev->v4l2_dev);
kfree(dev);
}
static int hackrf_s_ctrl_rx(struct v4l2_ctrl *ctrl)
{
struct hackrf_dev *dev = container_of(ctrl->handler,
struct hackrf_dev, rx_ctrl_handler);
struct usb_interface *intf = dev->intf;
int ret;
switch (ctrl->id) {
case V4L2_CID_RF_TUNER_BANDWIDTH_AUTO:
case V4L2_CID_RF_TUNER_BANDWIDTH:
set_bit(RX_BANDWIDTH, &dev->flags);
break;
case V4L2_CID_RF_TUNER_RF_GAIN:
set_bit(RX_RF_GAIN, &dev->flags);
break;
case V4L2_CID_RF_TUNER_LNA_GAIN:
set_bit(RX_LNA_GAIN, &dev->flags);
break;
case V4L2_CID_RF_TUNER_IF_GAIN:
set_bit(RX_IF_GAIN, &dev->flags);
break;
default:
dev_dbg(&intf->dev, "unknown ctrl: id=%d name=%s\n",
ctrl->id, ctrl->name);
ret = -EINVAL;
goto err;
}
ret = hackrf_set_params(dev);
if (ret)
goto err;
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int hackrf_s_ctrl_tx(struct v4l2_ctrl *ctrl)
{
struct hackrf_dev *dev = container_of(ctrl->handler,
struct hackrf_dev, tx_ctrl_handler);
struct usb_interface *intf = dev->intf;
int ret;
switch (ctrl->id) {
case V4L2_CID_RF_TUNER_BANDWIDTH_AUTO:
case V4L2_CID_RF_TUNER_BANDWIDTH:
set_bit(TX_BANDWIDTH, &dev->flags);
break;
case V4L2_CID_RF_TUNER_LNA_GAIN:
set_bit(TX_LNA_GAIN, &dev->flags);
break;
case V4L2_CID_RF_TUNER_RF_GAIN:
set_bit(TX_RF_GAIN, &dev->flags);
break;
default:
dev_dbg(&intf->dev, "unknown ctrl: id=%d name=%s\n",
ctrl->id, ctrl->name);
ret = -EINVAL;
goto err;
}
ret = hackrf_set_params(dev);
if (ret)
goto err;
return 0;
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
static int hackrf_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct hackrf_dev *dev;
int ret;
u8 u8tmp, buf[BUF_SIZE];
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
ret = -ENOMEM;
goto err;
}
mutex_init(&dev->v4l2_lock);
mutex_init(&dev->vb_queue_lock);
spin_lock_init(&dev->buffer_list_lock);
INIT_LIST_HEAD(&dev->rx_buffer_list);
INIT_LIST_HEAD(&dev->tx_buffer_list);
dev->intf = intf;
dev->dev = &intf->dev;
dev->udev = interface_to_usbdev(intf);
dev->pixelformat = formats[0].pixelformat;
dev->buffersize = formats[0].buffersize;
dev->f_adc = bands_adc_dac[0].rangelow;
dev->f_dac = bands_adc_dac[0].rangelow;
dev->f_rx = bands_rx_tx[0].rangelow;
dev->f_tx = bands_rx_tx[0].rangelow;
set_bit(RX_ADC_FREQUENCY, &dev->flags);
set_bit(TX_DAC_FREQUENCY, &dev->flags);
set_bit(RX_RF_FREQUENCY, &dev->flags);
set_bit(TX_RF_FREQUENCY, &dev->flags);
ret = hackrf_ctrl_msg(dev, CMD_BOARD_ID_READ, 0, 0, &u8tmp, 1);
if (ret == 0)
ret = hackrf_ctrl_msg(dev, CMD_VERSION_STRING_READ, 0, 0,
buf, BUF_SIZE);
if (ret) {
dev_err(dev->dev, "Could not detect board\n");
goto err_kfree;
}
buf[BUF_SIZE - 1] = '\0';
dev_info(dev->dev, "Board ID: %02x\n", u8tmp);
dev_info(dev->dev, "Firmware version: %s\n", buf);
dev->rx_vb2_queue.type = V4L2_BUF_TYPE_SDR_CAPTURE;
dev->rx_vb2_queue.io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF |
VB2_READ;
dev->rx_vb2_queue.ops = &hackrf_vb2_ops;
dev->rx_vb2_queue.mem_ops = &vb2_vmalloc_memops;
dev->rx_vb2_queue.drv_priv = dev;
dev->rx_vb2_queue.buf_struct_size = sizeof(struct hackrf_buffer);
dev->rx_vb2_queue.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
ret = vb2_queue_init(&dev->rx_vb2_queue);
if (ret) {
dev_err(dev->dev, "Could not initialize rx vb2 queue\n");
goto err_kfree;
}
dev->tx_vb2_queue.type = V4L2_BUF_TYPE_SDR_OUTPUT;
dev->tx_vb2_queue.io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF |
VB2_WRITE;
dev->tx_vb2_queue.ops = &hackrf_vb2_ops;
dev->tx_vb2_queue.mem_ops = &vb2_vmalloc_memops;
dev->tx_vb2_queue.drv_priv = dev;
dev->tx_vb2_queue.buf_struct_size = sizeof(struct hackrf_buffer);
dev->tx_vb2_queue.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
ret = vb2_queue_init(&dev->tx_vb2_queue);
if (ret) {
dev_err(dev->dev, "Could not initialize tx vb2 queue\n");
goto err_kfree;
}
v4l2_ctrl_handler_init(&dev->rx_ctrl_handler, 5);
dev->rx_bandwidth_auto = v4l2_ctrl_new_std(&dev->rx_ctrl_handler,
&hackrf_ctrl_ops_rx, V4L2_CID_RF_TUNER_BANDWIDTH_AUTO,
0, 1, 0, 1);
dev->rx_bandwidth = v4l2_ctrl_new_std(&dev->rx_ctrl_handler,
&hackrf_ctrl_ops_rx, V4L2_CID_RF_TUNER_BANDWIDTH,
1750000, 28000000, 50000, 1750000);
v4l2_ctrl_auto_cluster(2, &dev->rx_bandwidth_auto, 0, false);
dev->rx_rf_gain = v4l2_ctrl_new_std(&dev->rx_ctrl_handler,
&hackrf_ctrl_ops_rx, V4L2_CID_RF_TUNER_RF_GAIN, 0, 12, 12, 0);
dev->rx_lna_gain = v4l2_ctrl_new_std(&dev->rx_ctrl_handler,
&hackrf_ctrl_ops_rx, V4L2_CID_RF_TUNER_LNA_GAIN, 0, 40, 8, 0);
dev->rx_if_gain = v4l2_ctrl_new_std(&dev->rx_ctrl_handler,
&hackrf_ctrl_ops_rx, V4L2_CID_RF_TUNER_IF_GAIN, 0, 62, 2, 0);
if (dev->rx_ctrl_handler.error) {
ret = dev->rx_ctrl_handler.error;
dev_err(dev->dev, "Could not initialize controls\n");
goto err_v4l2_ctrl_handler_free_rx;
}
v4l2_ctrl_grab(dev->rx_rf_gain, !hackrf_enable_rf_gain_ctrl);
v4l2_ctrl_handler_setup(&dev->rx_ctrl_handler);
v4l2_ctrl_handler_init(&dev->tx_ctrl_handler, 4);
dev->tx_bandwidth_auto = v4l2_ctrl_new_std(&dev->tx_ctrl_handler,
&hackrf_ctrl_ops_tx, V4L2_CID_RF_TUNER_BANDWIDTH_AUTO,
0, 1, 0, 1);
dev->tx_bandwidth = v4l2_ctrl_new_std(&dev->tx_ctrl_handler,
&hackrf_ctrl_ops_tx, V4L2_CID_RF_TUNER_BANDWIDTH,
1750000, 28000000, 50000, 1750000);
v4l2_ctrl_auto_cluster(2, &dev->tx_bandwidth_auto, 0, false);
dev->tx_lna_gain = v4l2_ctrl_new_std(&dev->tx_ctrl_handler,
&hackrf_ctrl_ops_tx, V4L2_CID_RF_TUNER_LNA_GAIN, 0, 47, 1, 0);
dev->tx_rf_gain = v4l2_ctrl_new_std(&dev->tx_ctrl_handler,
&hackrf_ctrl_ops_tx, V4L2_CID_RF_TUNER_RF_GAIN, 0, 15, 15, 0);
if (dev->tx_ctrl_handler.error) {
ret = dev->tx_ctrl_handler.error;
dev_err(dev->dev, "Could not initialize controls\n");
goto err_v4l2_ctrl_handler_free_tx;
}
v4l2_ctrl_grab(dev->tx_rf_gain, !hackrf_enable_rf_gain_ctrl);
v4l2_ctrl_handler_setup(&dev->tx_ctrl_handler);
dev->v4l2_dev.release = hackrf_video_release;
ret = v4l2_device_register(&intf->dev, &dev->v4l2_dev);
if (ret) {
dev_err(dev->dev, "Failed to register v4l2-device (%d)\n", ret);
goto err_v4l2_ctrl_handler_free_tx;
}
dev->rx_vdev = hackrf_template;
dev->rx_vdev.queue = &dev->rx_vb2_queue;
dev->rx_vdev.queue->lock = &dev->vb_queue_lock;
dev->rx_vdev.v4l2_dev = &dev->v4l2_dev;
dev->rx_vdev.ctrl_handler = &dev->rx_ctrl_handler;
dev->rx_vdev.lock = &dev->v4l2_lock;
dev->rx_vdev.vfl_dir = VFL_DIR_RX;
video_set_drvdata(&dev->rx_vdev, dev);
ret = video_register_device(&dev->rx_vdev, VFL_TYPE_SDR, -1);
if (ret) {
dev_err(dev->dev,
"Failed to register as video device (%d)\n", ret);
goto err_v4l2_device_unregister;
}
dev_info(dev->dev, "Registered as %s\n",
video_device_node_name(&dev->rx_vdev));
dev->tx_vdev = hackrf_template;
dev->tx_vdev.queue = &dev->tx_vb2_queue;
dev->tx_vdev.queue->lock = &dev->vb_queue_lock;
dev->tx_vdev.v4l2_dev = &dev->v4l2_dev;
dev->tx_vdev.ctrl_handler = &dev->tx_ctrl_handler;
dev->tx_vdev.lock = &dev->v4l2_lock;
dev->tx_vdev.vfl_dir = VFL_DIR_TX;
video_set_drvdata(&dev->tx_vdev, dev);
ret = video_register_device(&dev->tx_vdev, VFL_TYPE_SDR, -1);
if (ret) {
dev_err(dev->dev,
"Failed to register as video device (%d)\n", ret);
goto err_video_unregister_device_rx;
}
dev_info(dev->dev, "Registered as %s\n",
video_device_node_name(&dev->tx_vdev));
dev_notice(dev->dev, "SDR API is still slightly experimental and functionality changes may follow\n");
return 0;
err_video_unregister_device_rx:
video_unregister_device(&dev->rx_vdev);
err_v4l2_device_unregister:
v4l2_device_unregister(&dev->v4l2_dev);
err_v4l2_ctrl_handler_free_tx:
v4l2_ctrl_handler_free(&dev->tx_ctrl_handler);
err_v4l2_ctrl_handler_free_rx:
v4l2_ctrl_handler_free(&dev->rx_ctrl_handler);
err_kfree:
kfree(dev);
err:
dev_dbg(&intf->dev, "failed=%d\n", ret);
return ret;
}
