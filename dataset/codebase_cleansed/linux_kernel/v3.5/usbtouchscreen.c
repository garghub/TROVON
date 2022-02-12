static int e2i_init(struct usbtouch_usb *usbtouch)
{
int ret;
struct usb_device *udev = interface_to_usbdev(usbtouch->interface);
ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
0x01, 0x02, 0x0000, 0x0081,
NULL, 0, USB_CTRL_SET_TIMEOUT);
dev_dbg(&usbtouch->interface->dev,
"%s - usb_control_msg - E2I_RESET - bytes|err: %d\n",
__func__, ret);
return ret;
}
static int e2i_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
int tmp = (pkt[0] << 8) | pkt[1];
dev->x = (pkt[2] << 8) | pkt[3];
dev->y = (pkt[4] << 8) | pkt[5];
tmp = tmp - 0xA000;
dev->touch = (tmp > 0);
dev->press = (tmp > 0 ? tmp : 0);
return 1;
}
static int egalax_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
if ((pkt[0] & EGALAX_PKT_TYPE_MASK) != EGALAX_PKT_TYPE_REPT)
return 0;
dev->x = ((pkt[3] & 0x0F) << 7) | (pkt[4] & 0x7F);
dev->y = ((pkt[1] & 0x0F) << 7) | (pkt[2] & 0x7F);
dev->touch = pkt[0] & 0x01;
return 1;
}
static int egalax_get_pkt_len(unsigned char *buf, int len)
{
switch (buf[0] & EGALAX_PKT_TYPE_MASK) {
case EGALAX_PKT_TYPE_REPT:
return 5;
case EGALAX_PKT_TYPE_DIAG:
if (len < 2)
return -1;
return buf[1] + 2;
}
return 0;
}
static int etouch_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
if ((pkt[0] & ETOUCH_PKT_TYPE_MASK) != ETOUCH_PKT_TYPE_REPT &&
(pkt[0] & ETOUCH_PKT_TYPE_MASK) != ETOUCH_PKT_TYPE_REPT2)
return 0;
dev->x = ((pkt[1] & 0x1F) << 7) | (pkt[2] & 0x7F);
dev->y = ((pkt[3] & 0x1F) << 7) | (pkt[4] & 0x7F);
dev->touch = pkt[0] & 0x01;
return 1;
}
static int etouch_get_pkt_len(unsigned char *buf, int len)
{
switch (buf[0] & ETOUCH_PKT_TYPE_MASK) {
case ETOUCH_PKT_TYPE_REPT:
case ETOUCH_PKT_TYPE_REPT2:
return 5;
case ETOUCH_PKT_TYPE_DIAG:
if (len < 2)
return -1;
return buf[1] + 2;
}
return 0;
}
static int panjit_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
dev->x = ((pkt[2] & 0x0F) << 8) | pkt[1];
dev->y = ((pkt[4] & 0x0F) << 8) | pkt[3];
dev->touch = pkt[0] & 0x01;
return 1;
}
static int mtouch_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
if (hwcalib_xy) {
dev->x = (pkt[4] << 8) | pkt[3];
dev->y = 0xffff - ((pkt[6] << 8) | pkt[5]);
} else {
dev->x = (pkt[8] << 8) | pkt[7];
dev->y = (pkt[10] << 8) | pkt[9];
}
dev->touch = (pkt[2] & 0x40) ? 1 : 0;
return 1;
}
static int mtouch_init(struct usbtouch_usb *usbtouch)
{
int ret, i;
struct usb_device *udev = interface_to_usbdev(usbtouch->interface);
ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
MTOUCHUSB_RESET,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
1, 0, NULL, 0, USB_CTRL_SET_TIMEOUT);
dev_dbg(&usbtouch->interface->dev,
"%s - usb_control_msg - MTOUCHUSB_RESET - bytes|err: %d\n",
__func__, ret);
if (ret < 0)
return ret;
msleep(150);
for (i = 0; i < 3; i++) {
ret = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
MTOUCHUSB_ASYNC_REPORT,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
1, 1, NULL, 0, USB_CTRL_SET_TIMEOUT);
dev_dbg(&usbtouch->interface->dev,
"%s - usb_control_msg - MTOUCHUSB_ASYNC_REPORT - bytes|err: %d\n",
__func__, ret);
if (ret >= 0)
break;
if (ret != -EPIPE)
return ret;
}
if (hwcalib_xy) {
input_set_abs_params(usbtouch->input, ABS_X, 0, 0xffff, 0, 0);
input_set_abs_params(usbtouch->input, ABS_Y, 0, 0xffff, 0, 0);
}
return 0;
}
static int itm_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
int touch;
dev->press = ((pkt[2] & 0x01) << 7) | (pkt[5] & 0x7F);
touch = ~pkt[7] & 0x20;
if (!touch) {
if (dev->touch) {
dev->touch = 0;
return 1;
}
return 0;
}
dev->x = ((pkt[0] & 0x1F) << 7) | (pkt[3] & 0x7F);
dev->y = ((pkt[1] & 0x1F) << 7) | (pkt[4] & 0x7F);
dev->touch = touch;
return 1;
}
static int eturbo_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
unsigned int shift;
if (!(pkt[0] & 0x80))
return 0;
shift = (6 - (pkt[0] & 0x03));
dev->x = ((pkt[3] << 7) | pkt[4]) >> shift;
dev->y = ((pkt[1] << 7) | pkt[2]) >> shift;
dev->touch = (pkt[0] & 0x10) ? 1 : 0;
return 1;
}
static int eturbo_get_pkt_len(unsigned char *buf, int len)
{
if (buf[0] & 0x80)
return 5;
if (buf[0] == 0x01)
return 3;
return 0;
}
static int gunze_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
if (!(pkt[0] & 0x80) || ((pkt[1] | pkt[2] | pkt[3]) & 0x80))
return 0;
dev->x = ((pkt[0] & 0x1F) << 7) | (pkt[2] & 0x7F);
dev->y = ((pkt[1] & 0x1F) << 7) | (pkt[3] & 0x7F);
dev->touch = pkt[0] & 0x20;
return 1;
}
static int dmc_tsc10_init(struct usbtouch_usb *usbtouch)
{
struct usb_device *dev = interface_to_usbdev(usbtouch->interface);
int ret = -ENOMEM;
unsigned char *buf;
buf = kmalloc(2, GFP_NOIO);
if (!buf)
goto err_nobuf;
buf[0] = buf[1] = 0xFF;
ret = usb_control_msg(dev, usb_rcvctrlpipe (dev, 0),
TSC10_CMD_RESET,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, 0, buf, 2, USB_CTRL_SET_TIMEOUT);
if (ret < 0)
goto err_out;
if (buf[0] != 0x06) {
ret = -ENODEV;
goto err_out;
}
buf[0] = buf[1] = 0xFF;
ret = usb_control_msg(dev, usb_rcvctrlpipe (dev, 0),
TSC10_CMD_RATE,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
TSC10_RATE_150, 0, buf, 2, USB_CTRL_SET_TIMEOUT);
if (ret < 0)
goto err_out;
if ((buf[0] != 0x06) && (buf[0] != 0x15 || buf[1] != 0x01)) {
ret = -ENODEV;
goto err_out;
}
ret = usb_control_msg(dev, usb_rcvctrlpipe (dev, 0),
TSC10_CMD_DATA1,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, 0, NULL, 0, USB_CTRL_SET_TIMEOUT);
err_out:
kfree(buf);
err_nobuf:
return ret;
}
static int dmc_tsc10_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
dev->x = ((pkt[2] & 0x03) << 8) | pkt[1];
dev->y = ((pkt[4] & 0x03) << 8) | pkt[3];
dev->touch = pkt[0] & 0x01;
return 1;
}
static int irtouch_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
dev->x = (pkt[3] << 8) | pkt[2];
dev->y = (pkt[5] << 8) | pkt[4];
dev->touch = (pkt[1] & 0x03) ? 1 : 0;
return 1;
}
static int tc45usb_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
dev->x = ((pkt[2] & 0x0F) << 8) | pkt[1];
dev->y = ((pkt[4] & 0x0F) << 8) | pkt[3];
dev->touch = pkt[0] & 0x01;
return 1;
}
static int idealtek_get_pkt_len(unsigned char *buf, int len)
{
if (buf[0] & 0x80)
return 5;
if (buf[0] == 0x01)
return len;
return 0;
}
static int idealtek_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
switch (pkt[0] & 0x98) {
case 0x88:
dev->x = (pkt[1] << 5) | (pkt[2] >> 2);
dev->y = (pkt[3] << 5) | (pkt[4] >> 2);
dev->touch = (pkt[0] & 0x40) ? 1 : 0;
return 1;
case 0x98:
dev->x = (pkt[2] << 5) | (pkt[1] >> 2);
dev->y = (pkt[4] << 5) | (pkt[3] >> 2);
dev->touch = (pkt[0] & 0x40) ? 1 : 0;
return 1;
default:
return 0;
}
}
static int general_touch_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
dev->x = (pkt[2] << 8) | pkt[1];
dev->y = (pkt[4] << 8) | pkt[3];
dev->press = pkt[5] & 0xff;
dev->touch = pkt[0] & 0x01;
return 1;
}
static int gotop_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
dev->x = ((pkt[1] & 0x38) << 4) | pkt[2];
dev->y = ((pkt[1] & 0x07) << 7) | pkt[3];
dev->touch = pkt[0] & 0x01;
return 1;
}
static int jastec_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
dev->x = ((pkt[0] & 0x3f) << 6) | (pkt[2] & 0x3f);
dev->y = ((pkt[1] & 0x3f) << 6) | (pkt[3] & 0x3f);
dev->touch = (pkt[0] & 0x40) >> 6;
return 1;
}
static int zytronic_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
struct usb_interface *intf = dev->interface;
switch (pkt[0]) {
case 0x3A:
dev_dbg(&intf->dev, "%s: Command response %d\n", __func__, pkt[1]);
break;
case 0xC0:
dev->x = (pkt[1] & 0x7f) | ((pkt[2] & 0x07) << 7);
dev->y = (pkt[3] & 0x7f) | ((pkt[4] & 0x07) << 7);
dev->touch = 1;
dev_dbg(&intf->dev, "%s: down %d,%d\n", __func__, dev->x, dev->y);
return 1;
case 0x80:
dev->x = (pkt[1] & 0x7f) | ((pkt[2] & 0x07) << 7);
dev->y = (pkt[3] & 0x7f) | ((pkt[4] & 0x07) << 7);
dev->touch = 0;
dev_dbg(&intf->dev, "%s: up %d,%d\n", __func__, dev->x, dev->y);
return 1;
default:
dev_dbg(&intf->dev, "%s: Unknown return %d\n", __func__, pkt[0]);
break;
}
return 0;
}
static void nexio_ack_complete(struct urb *urb)
{
}
static int nexio_alloc(struct usbtouch_usb *usbtouch)
{
struct nexio_priv *priv;
int ret = -ENOMEM;
usbtouch->priv = kmalloc(sizeof(struct nexio_priv), GFP_KERNEL);
if (!usbtouch->priv)
goto out_buf;
priv = usbtouch->priv;
priv->ack_buf = kmemdup(nexio_ack_pkt, sizeof(nexio_ack_pkt),
GFP_KERNEL);
if (!priv->ack_buf)
goto err_priv;
priv->ack = usb_alloc_urb(0, GFP_KERNEL);
if (!priv->ack) {
dev_dbg(&usbtouch->interface->dev,
"%s - usb_alloc_urb failed: usbtouch->ack\n", __func__);
goto err_ack_buf;
}
return 0;
err_ack_buf:
kfree(priv->ack_buf);
err_priv:
kfree(priv);
out_buf:
return ret;
}
static int nexio_init(struct usbtouch_usb *usbtouch)
{
struct usb_device *dev = interface_to_usbdev(usbtouch->interface);
struct usb_host_interface *interface = usbtouch->interface->cur_altsetting;
struct nexio_priv *priv = usbtouch->priv;
int ret = -ENOMEM;
int actual_len, i;
unsigned char *buf;
char *firmware_ver = NULL, *device_name = NULL;
int input_ep = 0, output_ep = 0;
for (i = 0; i < interface->desc.bNumEndpoints; i++) {
if (!input_ep &&
usb_endpoint_dir_in(&interface->endpoint[i].desc))
input_ep = interface->endpoint[i].desc.bEndpointAddress;
if (!output_ep &&
usb_endpoint_dir_out(&interface->endpoint[i].desc))
output_ep = interface->endpoint[i].desc.bEndpointAddress;
}
if (!input_ep || !output_ep)
return -ENXIO;
buf = kmalloc(NEXIO_BUFSIZE, GFP_NOIO);
if (!buf)
goto out_buf;
for (i = 0; i < 2; i++) {
ret = usb_bulk_msg(dev, usb_rcvbulkpipe(dev, input_ep),
buf, NEXIO_BUFSIZE, &actual_len,
NEXIO_TIMEOUT);
if (ret < 0)
goto out_buf;
}
memcpy(buf, nexio_init_pkt, sizeof(nexio_init_pkt));
ret = usb_bulk_msg(dev, usb_sndbulkpipe(dev, output_ep),
buf, sizeof(nexio_init_pkt), &actual_len,
NEXIO_TIMEOUT);
if (ret < 0)
goto out_buf;
for (i = 0; i < 3; i++) {
memset(buf, 0, NEXIO_BUFSIZE);
ret = usb_bulk_msg(dev, usb_rcvbulkpipe(dev, input_ep),
buf, NEXIO_BUFSIZE, &actual_len,
NEXIO_TIMEOUT);
if (ret < 0 || actual_len < 1 || buf[1] != actual_len)
continue;
switch (buf[0]) {
case 0x83:
if (!firmware_ver)
firmware_ver = kstrdup(&buf[2], GFP_NOIO);
break;
case 0x84:
if (!device_name)
device_name = kstrdup(&buf[2], GFP_NOIO);
break;
}
}
printk(KERN_INFO "Nexio device: %s, firmware version: %s\n",
device_name, firmware_ver);
kfree(firmware_ver);
kfree(device_name);
usb_fill_bulk_urb(priv->ack, dev, usb_sndbulkpipe(dev, output_ep),
priv->ack_buf, sizeof(nexio_ack_pkt),
nexio_ack_complete, usbtouch);
ret = 0;
out_buf:
kfree(buf);
return ret;
}
static void nexio_exit(struct usbtouch_usb *usbtouch)
{
struct nexio_priv *priv = usbtouch->priv;
usb_kill_urb(priv->ack);
usb_free_urb(priv->ack);
kfree(priv->ack_buf);
kfree(priv);
}
static int nexio_read_data(struct usbtouch_usb *usbtouch, unsigned char *pkt)
{
struct nexio_touch_packet *packet = (void *) pkt;
struct nexio_priv *priv = usbtouch->priv;
unsigned int data_len = be16_to_cpu(packet->data_len);
unsigned int x_len = be16_to_cpu(packet->x_len);
unsigned int y_len = be16_to_cpu(packet->y_len);
int x, y, begin_x, begin_y, end_x, end_y, w, h, ret;
if ((pkt[0] & 0xe0) != 0xe0)
return 0;
if (data_len > 0xff)
data_len -= 0x100;
if (x_len > 0xff)
x_len -= 0x80;
ret = usb_submit_urb(priv->ack, GFP_ATOMIC);
if (!usbtouch->type->max_xc) {
usbtouch->type->max_xc = 2 * x_len;
input_set_abs_params(usbtouch->input, ABS_X,
0, usbtouch->type->max_xc, 0, 0);
usbtouch->type->max_yc = 2 * y_len;
input_set_abs_params(usbtouch->input, ABS_Y,
0, usbtouch->type->max_yc, 0, 0);
}
begin_x = end_x = begin_y = end_y = -1;
for (x = 0; x < x_len; x++) {
if (begin_x == -1 && packet->data[x] > NEXIO_THRESHOLD) {
begin_x = x;
continue;
}
if (end_x == -1 && begin_x != -1 && packet->data[x] < NEXIO_THRESHOLD) {
end_x = x - 1;
for (y = x_len; y < data_len; y++) {
if (begin_y == -1 && packet->data[y] > NEXIO_THRESHOLD) {
begin_y = y - x_len;
continue;
}
if (end_y == -1 &&
begin_y != -1 && packet->data[y] < NEXIO_THRESHOLD) {
end_y = y - 1 - x_len;
w = end_x - begin_x;
h = end_y - begin_y;
#if 0
input_report_abs(usbtouch->input,
ABS_MT_TOUCH_MAJOR, max(w,h));
input_report_abs(usbtouch->input,
ABS_MT_TOUCH_MINOR, min(x,h));
input_report_abs(usbtouch->input,
ABS_MT_POSITION_X, 2*begin_x+w);
input_report_abs(usbtouch->input,
ABS_MT_POSITION_Y, 2*begin_y+h);
input_report_abs(usbtouch->input,
ABS_MT_ORIENTATION, w > h);
input_mt_sync(usbtouch->input);
#endif
usbtouch->x = 2 * begin_x + w;
usbtouch->y = 2 * begin_y + h;
usbtouch->touch = packet->flags & 0x01;
begin_y = end_y = -1;
return 1;
}
}
begin_x = end_x = -1;
}
}
return 0;
}
static int elo_read_data(struct usbtouch_usb *dev, unsigned char *pkt)
{
dev->x = (pkt[3] << 8) | pkt[2];
dev->y = (pkt[5] << 8) | pkt[4];
dev->touch = pkt[6] > 0;
dev->press = pkt[6];
return 1;
}
static void usbtouch_process_pkt(struct usbtouch_usb *usbtouch,
unsigned char *pkt, int len)
{
struct usbtouch_device_info *type = usbtouch->type;
if (!type->read_data(usbtouch, pkt))
return;
input_report_key(usbtouch->input, BTN_TOUCH, usbtouch->touch);
if (swap_xy) {
input_report_abs(usbtouch->input, ABS_X, usbtouch->y);
input_report_abs(usbtouch->input, ABS_Y, usbtouch->x);
} else {
input_report_abs(usbtouch->input, ABS_X, usbtouch->x);
input_report_abs(usbtouch->input, ABS_Y, usbtouch->y);
}
if (type->max_press)
input_report_abs(usbtouch->input, ABS_PRESSURE, usbtouch->press);
input_sync(usbtouch->input);
}
static void usbtouch_process_multi(struct usbtouch_usb *usbtouch,
unsigned char *pkt, int len)
{
unsigned char *buffer;
int pkt_len, pos, buf_len, tmp;
if (unlikely(usbtouch->buf_len)) {
pkt_len = usbtouch->type->get_pkt_len(
usbtouch->buffer, usbtouch->buf_len);
if (unlikely(!pkt_len))
goto out_flush_buf;
if (unlikely(pkt_len < 0)) {
int append = -pkt_len;
if (unlikely(append > len))
append = len;
if (usbtouch->buf_len + append >= usbtouch->type->rept_size)
goto out_flush_buf;
memcpy(usbtouch->buffer + usbtouch->buf_len, pkt, append);
usbtouch->buf_len += append;
pkt_len = usbtouch->type->get_pkt_len(
usbtouch->buffer, usbtouch->buf_len);
if (pkt_len < 0)
return;
}
tmp = pkt_len - usbtouch->buf_len;
if (usbtouch->buf_len + tmp >= usbtouch->type->rept_size)
goto out_flush_buf;
memcpy(usbtouch->buffer + usbtouch->buf_len, pkt, tmp);
usbtouch_process_pkt(usbtouch, usbtouch->buffer, pkt_len);
buffer = pkt + tmp;
buf_len = len - tmp;
} else {
buffer = pkt;
buf_len = len;
}
pos = 0;
while (pos < buf_len) {
pkt_len = usbtouch->type->get_pkt_len(buffer + pos,
buf_len - pos);
if (unlikely(!pkt_len)) {
pos++;
continue;
}
if (likely((pkt_len > 0) && (pkt_len <= buf_len - pos))) {
usbtouch_process_pkt(usbtouch, buffer + pos, pkt_len);
} else {
memcpy(usbtouch->buffer, buffer + pos, buf_len - pos);
usbtouch->buf_len = buf_len - pos;
return;
}
pos += pkt_len;
}
out_flush_buf:
usbtouch->buf_len = 0;
return;
}
static void usbtouch_irq(struct urb *urb)
{
struct usbtouch_usb *usbtouch = urb->context;
struct device *dev = &usbtouch->interface->dev;
int retval;
switch (urb->status) {
case 0:
break;
case -ETIME:
dev_dbg(dev,
"%s - urb timed out - was the device unplugged?\n",
__func__);
return;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
case -EPIPE:
dev_dbg(dev, "%s - urb shutting down with status: %d\n",
__func__, urb->status);
return;
default:
dev_dbg(dev, "%s - nonzero urb status received: %d\n",
__func__, urb->status);
goto exit;
}
usbtouch->type->process_pkt(usbtouch, usbtouch->data, urb->actual_length);
exit:
usb_mark_last_busy(interface_to_usbdev(usbtouch->interface));
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(dev, "%s - usb_submit_urb failed with result: %d\n",
__func__, retval);
}
static int usbtouch_open(struct input_dev *input)
{
struct usbtouch_usb *usbtouch = input_get_drvdata(input);
int r;
usbtouch->irq->dev = interface_to_usbdev(usbtouch->interface);
r = usb_autopm_get_interface(usbtouch->interface) ? -EIO : 0;
if (r < 0)
goto out;
if (!usbtouch->type->irq_always) {
if (usb_submit_urb(usbtouch->irq, GFP_KERNEL)) {
r = -EIO;
goto out_put;
}
}
usbtouch->interface->needs_remote_wakeup = 1;
out_put:
usb_autopm_put_interface(usbtouch->interface);
out:
return r;
}
static void usbtouch_close(struct input_dev *input)
{
struct usbtouch_usb *usbtouch = input_get_drvdata(input);
int r;
if (!usbtouch->type->irq_always)
usb_kill_urb(usbtouch->irq);
r = usb_autopm_get_interface(usbtouch->interface);
usbtouch->interface->needs_remote_wakeup = 0;
if (!r)
usb_autopm_put_interface(usbtouch->interface);
}
static int usbtouch_suspend
(struct usb_interface *intf, pm_message_t message)
{
struct usbtouch_usb *usbtouch = usb_get_intfdata(intf);
usb_kill_urb(usbtouch->irq);
return 0;
}
static int usbtouch_resume(struct usb_interface *intf)
{
struct usbtouch_usb *usbtouch = usb_get_intfdata(intf);
struct input_dev *input = usbtouch->input;
int result = 0;
mutex_lock(&input->mutex);
if (input->users || usbtouch->type->irq_always)
result = usb_submit_urb(usbtouch->irq, GFP_NOIO);
mutex_unlock(&input->mutex);
return result;
}
static int usbtouch_reset_resume(struct usb_interface *intf)
{
struct usbtouch_usb *usbtouch = usb_get_intfdata(intf);
struct input_dev *input = usbtouch->input;
int err = 0;
if (usbtouch->type->init) {
err = usbtouch->type->init(usbtouch);
if (err) {
dev_dbg(&intf->dev,
"%s - type->init() failed, err: %d\n",
__func__, err);
return err;
}
}
mutex_lock(&input->mutex);
if (input->users)
err = usb_submit_urb(usbtouch->irq, GFP_NOIO);
mutex_unlock(&input->mutex);
return err;
}
static void usbtouch_free_buffers(struct usb_device *udev,
struct usbtouch_usb *usbtouch)
{
usb_free_coherent(udev, usbtouch->type->rept_size,
usbtouch->data, usbtouch->data_dma);
kfree(usbtouch->buffer);
}
static struct usb_endpoint_descriptor *
usbtouch_get_input_endpoint(struct usb_host_interface *interface)
{
int i;
for (i = 0; i < interface->desc.bNumEndpoints; i++)
if (usb_endpoint_dir_in(&interface->endpoint[i].desc))
return &interface->endpoint[i].desc;
return NULL;
}
static int usbtouch_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usbtouch_usb *usbtouch;
struct input_dev *input_dev;
struct usb_endpoint_descriptor *endpoint;
struct usb_device *udev = interface_to_usbdev(intf);
struct usbtouch_device_info *type;
int err = -ENOMEM;
if (id->driver_info == DEVTYPE_IGNORE)
return -ENODEV;
endpoint = usbtouch_get_input_endpoint(intf->cur_altsetting);
if (!endpoint)
return -ENXIO;
usbtouch = kzalloc(sizeof(struct usbtouch_usb), GFP_KERNEL);
input_dev = input_allocate_device();
if (!usbtouch || !input_dev)
goto out_free;
type = &usbtouch_dev_info[id->driver_info];
usbtouch->type = type;
if (!type->process_pkt)
type->process_pkt = usbtouch_process_pkt;
usbtouch->data = usb_alloc_coherent(udev, type->rept_size,
GFP_KERNEL, &usbtouch->data_dma);
if (!usbtouch->data)
goto out_free;
if (type->get_pkt_len) {
usbtouch->buffer = kmalloc(type->rept_size, GFP_KERNEL);
if (!usbtouch->buffer)
goto out_free_buffers;
}
usbtouch->irq = usb_alloc_urb(0, GFP_KERNEL);
if (!usbtouch->irq) {
dev_dbg(&intf->dev,
"%s - usb_alloc_urb failed: usbtouch->irq\n", __func__);
goto out_free_buffers;
}
usbtouch->interface = intf;
usbtouch->input = input_dev;
if (udev->manufacturer)
strlcpy(usbtouch->name, udev->manufacturer, sizeof(usbtouch->name));
if (udev->product) {
if (udev->manufacturer)
strlcat(usbtouch->name, " ", sizeof(usbtouch->name));
strlcat(usbtouch->name, udev->product, sizeof(usbtouch->name));
}
if (!strlen(usbtouch->name))
snprintf(usbtouch->name, sizeof(usbtouch->name),
"USB Touchscreen %04x:%04x",
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct));
usb_make_path(udev, usbtouch->phys, sizeof(usbtouch->phys));
strlcat(usbtouch->phys, "/input0", sizeof(usbtouch->phys));
input_dev->name = usbtouch->name;
input_dev->phys = usbtouch->phys;
usb_to_input_id(udev, &input_dev->id);
input_dev->dev.parent = &intf->dev;
input_set_drvdata(input_dev, usbtouch);
input_dev->open = usbtouch_open;
input_dev->close = usbtouch_close;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X, type->min_xc, type->max_xc, 0, 0);
input_set_abs_params(input_dev, ABS_Y, type->min_yc, type->max_yc, 0, 0);
if (type->max_press)
input_set_abs_params(input_dev, ABS_PRESSURE, type->min_press,
type->max_press, 0, 0);
if (usb_endpoint_type(endpoint) == USB_ENDPOINT_XFER_INT)
usb_fill_int_urb(usbtouch->irq, udev,
usb_rcvintpipe(udev, endpoint->bEndpointAddress),
usbtouch->data, type->rept_size,
usbtouch_irq, usbtouch, endpoint->bInterval);
else
usb_fill_bulk_urb(usbtouch->irq, udev,
usb_rcvbulkpipe(udev, endpoint->bEndpointAddress),
usbtouch->data, type->rept_size,
usbtouch_irq, usbtouch);
usbtouch->irq->dev = udev;
usbtouch->irq->transfer_dma = usbtouch->data_dma;
usbtouch->irq->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
if (type->alloc) {
err = type->alloc(usbtouch);
if (err) {
dev_dbg(&intf->dev,
"%s - type->alloc() failed, err: %d\n",
__func__, err);
goto out_free_urb;
}
}
if (type->init) {
err = type->init(usbtouch);
if (err) {
dev_dbg(&intf->dev,
"%s - type->init() failed, err: %d\n",
__func__, err);
goto out_do_exit;
}
}
err = input_register_device(usbtouch->input);
if (err) {
dev_dbg(&intf->dev,
"%s - input_register_device failed, err: %d\n",
__func__, err);
goto out_do_exit;
}
usb_set_intfdata(intf, usbtouch);
if (usbtouch->type->irq_always) {
usb_autopm_get_interface(intf);
err = usb_submit_urb(usbtouch->irq, GFP_KERNEL);
if (err) {
usb_autopm_put_interface(intf);
dev_err(&intf->dev,
"%s - usb_submit_urb failed with result: %d\n",
__func__, err);
goto out_unregister_input;
}
}
return 0;
out_unregister_input:
input_unregister_device(input_dev);
input_dev = NULL;
out_do_exit:
if (type->exit)
type->exit(usbtouch);
out_free_urb:
usb_free_urb(usbtouch->irq);
out_free_buffers:
usbtouch_free_buffers(udev, usbtouch);
out_free:
input_free_device(input_dev);
kfree(usbtouch);
return err;
}
static void usbtouch_disconnect(struct usb_interface *intf)
{
struct usbtouch_usb *usbtouch = usb_get_intfdata(intf);
if (!usbtouch)
return;
dev_dbg(&intf->dev,
"%s - usbtouch is initialized, cleaning up\n", __func__);
usb_set_intfdata(intf, NULL);
input_unregister_device(usbtouch->input);
usb_free_urb(usbtouch->irq);
if (usbtouch->type->exit)
usbtouch->type->exit(usbtouch);
usbtouch_free_buffers(interface_to_usbdev(intf), usbtouch);
kfree(usbtouch);
}
