static int unregister_from_lirc(struct igorplug *ir)
{
struct lirc_driver *d;
int devnum;
if (!ir) {
dev_err(&ir->usbdev->dev,
"%s: called with NULL device struct!\n", __func__);
return -EINVAL;
}
devnum = ir->devnum;
d = ir->d;
if (!d) {
dev_err(&ir->usbdev->dev,
"%s: called with NULL lirc driver struct!\n", __func__);
return -EINVAL;
}
dprintk(DRIVER_NAME "[%d]: calling lirc_unregister_driver\n", devnum);
lirc_unregister_driver(d->minor);
return devnum;
}
static int set_use_inc(void *data)
{
struct igorplug *ir = data;
if (!ir) {
printk(DRIVER_NAME "[?]: set_use_inc called with no context\n");
return -EIO;
}
dprintk(DRIVER_NAME "[%d]: set use inc\n", ir->devnum);
if (!ir->usbdev)
return -ENODEV;
return 0;
}
static void set_use_dec(void *data)
{
struct igorplug *ir = data;
if (!ir) {
printk(DRIVER_NAME "[?]: set_use_dec called with no context\n");
return;
}
dprintk(DRIVER_NAME "[%d]: set use dec\n", ir->devnum);
}
static void send_fragment(struct igorplug *ir, struct lirc_buffer *buf,
int i, int max)
{
int code;
while (i < max) {
code = (unsigned int)ir->buf_in[i] * 85 +
(unsigned int)ir->buf_in[i] / 3;
ir->last_time.tv_usec += code;
if (ir->in_space)
code |= PULSE_BIT;
lirc_buffer_write(buf, (unsigned char *)&code);
ir->in_space ^= 1;
++i;
}
}
static int igorplugusb_remote_poll(void *data, struct lirc_buffer *buf)
{
int ret;
struct igorplug *ir = (struct igorplug *)data;
if (!ir || !ir->usbdev)
return -ENODEV;
memset(ir->buf_in, 0, ir->len_in);
ret = usb_control_msg(ir->usbdev, usb_rcvctrlpipe(ir->usbdev, 0),
GET_INFRACODE, USB_TYPE_VENDOR | USB_DIR_IN,
0, 0,
ir->buf_in, ir->len_in,
HZ * USB_CTRL_GET_TIMEOUT);
if (ret > 0) {
int code, timediff;
struct timeval now;
if (ret < DEVICE_HEADERLEN)
return -ENODATA;
dprintk(DRIVER_NAME ": Got %d bytes. Header: %*ph\n",
ret, 3, ir->buf_in);
do_gettimeofday(&now);
timediff = now.tv_sec - ir->last_time.tv_sec;
if (timediff + 1 > PULSE_MASK / 1000000)
timediff = PULSE_MASK;
else {
timediff *= 1000000;
timediff += now.tv_usec - ir->last_time.tv_usec;
}
ir->last_time.tv_sec = now.tv_sec;
ir->last_time.tv_usec = now.tv_usec;
code = timediff;
lirc_buffer_write(buf, (unsigned char *)&code);
ir->in_space = 1;
if (ir->buf_in[2] == 0)
send_fragment(ir, buf, DEVICE_HEADERLEN, ret);
else {
dev_warn(&ir->usbdev->dev,
"[%d]: Device buffer overrun.\n", ir->devnum);
ir->buf_in[2] %= ret - DEVICE_HEADERLEN;
send_fragment(ir, buf, DEVICE_HEADERLEN +
ir->buf_in[2] - (ir->buf_in[2] & 1), ret);
send_fragment(ir, buf, DEVICE_HEADERLEN,
DEVICE_HEADERLEN + ir->buf_in[2]);
}
ret = usb_control_msg(
ir->usbdev, usb_rcvctrlpipe(ir->usbdev, 0),
SET_INFRABUFFER_EMPTY, USB_TYPE_VENDOR|USB_DIR_IN,
0, 0,
ir->buf_in, ir->len_in,
HZ * USB_CTRL_GET_TIMEOUT);
if (ret < 0)
printk(DRIVER_NAME "[%d]: SET_INFRABUFFER_EMPTY: error %d\n",
ir->devnum, ret);
return 0;
} else if (ret < 0)
printk(DRIVER_NAME "[%d]: GET_INFRACODE: error %d\n",
ir->devnum, ret);
return -ENODATA;
}
static int igorplugusb_remote_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *dev;
struct usb_host_interface *idesc = NULL;
struct usb_endpoint_descriptor *ep;
struct igorplug *ir = NULL;
struct lirc_driver *driver = NULL;
int devnum, pipe, maxp;
char buf[63], name[128] = "";
int ret;
dprintk(DRIVER_NAME ": usb probe called.\n");
dev = interface_to_usbdev(intf);
idesc = intf->cur_altsetting;
if (idesc->desc.bNumEndpoints != 1)
return -ENODEV;
ep = &idesc->endpoint->desc;
if (((ep->bEndpointAddress & USB_ENDPOINT_DIR_MASK)
!= USB_DIR_IN)
|| (ep->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK)
!= USB_ENDPOINT_XFER_CONTROL)
return -ENODEV;
pipe = usb_rcvctrlpipe(dev, ep->bEndpointAddress);
devnum = dev->devnum;
maxp = usb_maxpacket(dev, pipe, usb_pipeout(pipe));
dprintk(DRIVER_NAME "[%d]: bytes_in_key=%zu maxp=%d\n",
devnum, CODE_LENGTH, maxp);
ir = devm_kzalloc(&intf->dev, sizeof(*ir), GFP_KERNEL);
if (!ir)
return -ENOMEM;
driver = devm_kzalloc(&intf->dev, sizeof(*driver), GFP_KERNEL);
if (!driver)
return -ENOMEM;
ir->buf_in = usb_alloc_coherent(dev, DEVICE_BUFLEN + DEVICE_HEADERLEN,
GFP_ATOMIC, &ir->dma_in);
if (!ir->buf_in)
return -ENOMEM;
strcpy(driver->name, DRIVER_NAME " ");
driver->minor = -1;
driver->code_length = CODE_LENGTH * 8;
driver->features = LIRC_CAN_REC_MODE2;
driver->data = ir;
driver->chunk_size = CODE_LENGTH;
driver->buffer_size = DEVICE_BUFLEN + ADDITIONAL_LIRC_BYTES;
driver->set_use_inc = &set_use_inc;
driver->set_use_dec = &set_use_dec;
driver->sample_rate = sample_rate;
driver->add_to_buf = &igorplugusb_remote_poll;
driver->dev = &intf->dev;
driver->owner = THIS_MODULE;
ret = lirc_register_driver(driver);
if (ret < 0) {
usb_free_coherent(dev, DEVICE_BUFLEN + DEVICE_HEADERLEN,
ir->buf_in, ir->dma_in);
return ret;
}
driver->minor = ret;
ir->d = driver;
ir->devnum = devnum;
ir->usbdev = dev;
ir->len_in = DEVICE_BUFLEN + DEVICE_HEADERLEN;
ir->in_space = 1;
do_gettimeofday(&ir->last_time);
if (dev->descriptor.iManufacturer
&& usb_string(dev, dev->descriptor.iManufacturer,
buf, sizeof(buf)) > 0)
strlcpy(name, buf, sizeof(name));
if (dev->descriptor.iProduct
&& usb_string(dev, dev->descriptor.iProduct, buf, sizeof(buf)) > 0)
snprintf(name + strlen(name), sizeof(name) - strlen(name),
" %s", buf);
printk(DRIVER_NAME "[%d]: %s on usb%d:%d\n", devnum, name,
dev->bus->busnum, devnum);
ret = usb_control_msg(ir->usbdev, usb_rcvctrlpipe(ir->usbdev, 0),
SET_INFRABUFFER_EMPTY, USB_TYPE_VENDOR|USB_DIR_IN,
0, 0,
ir->buf_in, ir->len_in,
HZ * USB_CTRL_GET_TIMEOUT);
if (ret < 0)
printk(DRIVER_NAME "[%d]: SET_INFRABUFFER_EMPTY: error %d\n",
devnum, ret);
usb_set_intfdata(intf, ir);
return 0;
}
static void igorplugusb_remote_disconnect(struct usb_interface *intf)
{
struct usb_device *usbdev = interface_to_usbdev(intf);
struct igorplug *ir = usb_get_intfdata(intf);
struct device *dev = &intf->dev;
int devnum;
usb_set_intfdata(intf, NULL);
if (!ir || !ir->d)
return;
ir->usbdev = NULL;
usb_free_coherent(usbdev, ir->len_in, ir->buf_in, ir->dma_in);
devnum = unregister_from_lirc(ir);
dev_info(dev, DRIVER_NAME "[%d]: %s done\n", devnum, __func__);
}
