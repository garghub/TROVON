static void sz_push(struct streamzap_ir *sz, struct ir_raw_event rawir)
{
dev_dbg(sz->dev, "Storing %s with duration %u us\n",
(rawir.pulse ? "pulse" : "space"), rawir.duration);
ir_raw_event_store_with_filter(sz->rdev, &rawir);
}
static void sz_push_full_pulse(struct streamzap_ir *sz,
unsigned char value)
{
DEFINE_IR_RAW_EVENT(rawir);
if (sz->idle) {
long deltv;
sz->signal_last = sz->signal_start;
do_gettimeofday(&sz->signal_start);
deltv = sz->signal_start.tv_sec - sz->signal_last.tv_sec;
rawir.pulse = false;
if (deltv > 15) {
rawir.duration = IR_MAX_DURATION;
} else {
rawir.duration = (int)(deltv * 1000000 +
sz->signal_start.tv_usec -
sz->signal_last.tv_usec);
rawir.duration -= sz->sum;
rawir.duration = US_TO_NS(rawir.duration);
rawir.duration &= IR_MAX_DURATION;
}
sz_push(sz, rawir);
sz->idle = false;
sz->sum = 0;
}
rawir.pulse = true;
rawir.duration = ((int) value) * SZ_RESOLUTION;
rawir.duration += SZ_RESOLUTION / 2;
sz->sum += rawir.duration;
rawir.duration = US_TO_NS(rawir.duration);
rawir.duration &= IR_MAX_DURATION;
sz_push(sz, rawir);
}
static void sz_push_half_pulse(struct streamzap_ir *sz,
unsigned char value)
{
sz_push_full_pulse(sz, (value & SZ_PULSE_MASK) >> 4);
}
static void sz_push_full_space(struct streamzap_ir *sz,
unsigned char value)
{
DEFINE_IR_RAW_EVENT(rawir);
rawir.pulse = false;
rawir.duration = ((int) value) * SZ_RESOLUTION;
rawir.duration += SZ_RESOLUTION / 2;
sz->sum += rawir.duration;
rawir.duration = US_TO_NS(rawir.duration);
sz_push(sz, rawir);
}
static void sz_push_half_space(struct streamzap_ir *sz,
unsigned long value)
{
sz_push_full_space(sz, value & SZ_SPACE_MASK);
}
static void streamzap_callback(struct urb *urb)
{
struct streamzap_ir *sz;
unsigned int i;
int len;
if (!urb)
return;
sz = urb->context;
len = urb->actual_length;
switch (urb->status) {
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_err(sz->dev, "urb terminated, status: %d\n", urb->status);
return;
default:
break;
}
dev_dbg(sz->dev, "%s: received urb, len %d\n", __func__, len);
for (i = 0; i < len; i++) {
dev_dbg(sz->dev, "sz->buf_in[%d]: %x\n",
i, (unsigned char)sz->buf_in[i]);
switch (sz->decoder_state) {
case PulseSpace:
if ((sz->buf_in[i] & SZ_PULSE_MASK) ==
SZ_PULSE_MASK) {
sz->decoder_state = FullPulse;
continue;
} else if ((sz->buf_in[i] & SZ_SPACE_MASK)
== SZ_SPACE_MASK) {
sz_push_half_pulse(sz, sz->buf_in[i]);
sz->decoder_state = FullSpace;
continue;
} else {
sz_push_half_pulse(sz, sz->buf_in[i]);
sz_push_half_space(sz, sz->buf_in[i]);
}
break;
case FullPulse:
sz_push_full_pulse(sz, sz->buf_in[i]);
sz->decoder_state = IgnorePulse;
break;
case FullSpace:
if (sz->buf_in[i] == SZ_TIMEOUT) {
DEFINE_IR_RAW_EVENT(rawir);
rawir.pulse = false;
rawir.duration = sz->rdev->timeout;
sz->idle = true;
if (sz->timeout_enabled)
sz_push(sz, rawir);
ir_raw_event_handle(sz->rdev);
ir_raw_event_reset(sz->rdev);
} else {
sz_push_full_space(sz, sz->buf_in[i]);
}
sz->decoder_state = PulseSpace;
break;
case IgnorePulse:
if ((sz->buf_in[i] & SZ_SPACE_MASK) ==
SZ_SPACE_MASK) {
sz->decoder_state = FullSpace;
continue;
}
sz_push_half_space(sz, sz->buf_in[i]);
sz->decoder_state = PulseSpace;
break;
}
}
ir_raw_event_handle(sz->rdev);
usb_submit_urb(urb, GFP_ATOMIC);
return;
}
static struct rc_dev *streamzap_init_rc_dev(struct streamzap_ir *sz)
{
struct rc_dev *rdev;
struct device *dev = sz->dev;
int ret;
rdev = rc_allocate_device();
if (!rdev) {
dev_err(dev, "remote dev allocation failed\n");
goto out;
}
snprintf(sz->name, sizeof(sz->name), "Streamzap PC Remote Infrared "
"Receiver (%04x:%04x)",
le16_to_cpu(sz->usbdev->descriptor.idVendor),
le16_to_cpu(sz->usbdev->descriptor.idProduct));
usb_make_path(sz->usbdev, sz->phys, sizeof(sz->phys));
strlcat(sz->phys, "/input0", sizeof(sz->phys));
rdev->input_name = sz->name;
rdev->input_phys = sz->phys;
usb_to_input_id(sz->usbdev, &rdev->input_id);
rdev->dev.parent = dev;
rdev->priv = sz;
rdev->driver_type = RC_DRIVER_IR_RAW;
rdev->allowed_protos = RC_TYPE_ALL;
rdev->driver_name = DRIVER_NAME;
rdev->map_name = RC_MAP_STREAMZAP;
ret = rc_register_device(rdev);
if (ret < 0) {
dev_err(dev, "remote input device register failed\n");
goto out;
}
return rdev;
out:
rc_free_device(rdev);
return NULL;
}
static int __devinit streamzap_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *usbdev = interface_to_usbdev(intf);
struct usb_host_interface *iface_host;
struct streamzap_ir *sz = NULL;
char buf[63], name[128] = "";
int retval = -ENOMEM;
int pipe, maxp;
sz = kzalloc(sizeof(struct streamzap_ir), GFP_KERNEL);
if (!sz)
return -ENOMEM;
sz->usbdev = usbdev;
sz->interface = intf;
iface_host = intf->cur_altsetting;
if (iface_host->desc.bNumEndpoints != 1) {
dev_err(&intf->dev, "%s: Unexpected desc.bNumEndpoints (%d)\n",
__func__, iface_host->desc.bNumEndpoints);
retval = -ENODEV;
goto free_sz;
}
sz->endpoint = &(iface_host->endpoint[0].desc);
if ((sz->endpoint->bEndpointAddress & USB_ENDPOINT_DIR_MASK)
!= USB_DIR_IN) {
dev_err(&intf->dev, "%s: endpoint doesn't match input device "
"02%02x\n", __func__, sz->endpoint->bEndpointAddress);
retval = -ENODEV;
goto free_sz;
}
if ((sz->endpoint->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK)
!= USB_ENDPOINT_XFER_INT) {
dev_err(&intf->dev, "%s: endpoint attributes don't match xfer "
"02%02x\n", __func__, sz->endpoint->bmAttributes);
retval = -ENODEV;
goto free_sz;
}
pipe = usb_rcvintpipe(usbdev, sz->endpoint->bEndpointAddress);
maxp = usb_maxpacket(usbdev, pipe, usb_pipeout(pipe));
if (maxp == 0) {
dev_err(&intf->dev, "%s: endpoint Max Packet Size is 0!?!\n",
__func__);
retval = -ENODEV;
goto free_sz;
}
sz->buf_in = usb_alloc_coherent(usbdev, maxp, GFP_ATOMIC, &sz->dma_in);
if (!sz->buf_in)
goto free_sz;
sz->urb_in = usb_alloc_urb(0, GFP_KERNEL);
if (!sz->urb_in)
goto free_buf_in;
sz->dev = &intf->dev;
sz->buf_in_len = maxp;
if (usbdev->descriptor.iManufacturer
&& usb_string(usbdev, usbdev->descriptor.iManufacturer,
buf, sizeof(buf)) > 0)
strlcpy(name, buf, sizeof(name));
if (usbdev->descriptor.iProduct
&& usb_string(usbdev, usbdev->descriptor.iProduct,
buf, sizeof(buf)) > 0)
snprintf(name + strlen(name), sizeof(name) - strlen(name),
" %s", buf);
sz->rdev = streamzap_init_rc_dev(sz);
if (!sz->rdev)
goto rc_dev_fail;
sz->idle = true;
sz->decoder_state = PulseSpace;
sz->timeout_enabled = true;
sz->rdev->timeout = ((US_TO_NS(SZ_TIMEOUT * SZ_RESOLUTION) &
IR_MAX_DURATION) | 0x03000000);
#if 0
sz->min_timeout = US_TO_NS(SZ_TIMEOUT * SZ_RESOLUTION);
sz->max_timeout = US_TO_NS(SZ_TIMEOUT * SZ_RESOLUTION);
#endif
do_gettimeofday(&sz->signal_start);
usb_fill_int_urb(sz->urb_in, usbdev, pipe, sz->buf_in,
maxp, (usb_complete_t)streamzap_callback,
sz, sz->endpoint->bInterval);
sz->urb_in->transfer_dma = sz->dma_in;
sz->urb_in->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_set_intfdata(intf, sz);
if (usb_submit_urb(sz->urb_in, GFP_ATOMIC))
dev_err(sz->dev, "urb submit failed\n");
dev_info(sz->dev, "Registered %s on usb%d:%d\n", name,
usbdev->bus->busnum, usbdev->devnum);
load_rc5_sz_decode();
return 0;
rc_dev_fail:
usb_free_urb(sz->urb_in);
free_buf_in:
usb_free_coherent(usbdev, maxp, sz->buf_in, sz->dma_in);
free_sz:
kfree(sz);
return retval;
}
static void streamzap_disconnect(struct usb_interface *interface)
{
struct streamzap_ir *sz = usb_get_intfdata(interface);
struct usb_device *usbdev = interface_to_usbdev(interface);
usb_set_intfdata(interface, NULL);
if (!sz)
return;
sz->usbdev = NULL;
rc_unregister_device(sz->rdev);
usb_kill_urb(sz->urb_in);
usb_free_urb(sz->urb_in);
usb_free_coherent(usbdev, sz->buf_in_len, sz->buf_in, sz->dma_in);
kfree(sz);
}
static int streamzap_suspend(struct usb_interface *intf, pm_message_t message)
{
struct streamzap_ir *sz = usb_get_intfdata(intf);
usb_kill_urb(sz->urb_in);
return 0;
}
static int streamzap_resume(struct usb_interface *intf)
{
struct streamzap_ir *sz = usb_get_intfdata(intf);
if (usb_submit_urb(sz->urb_in, GFP_ATOMIC)) {
dev_err(sz->dev, "Error sumbiting urb\n");
return -EIO;
}
return 0;
}
static int __init streamzap_init(void)
{
int ret;
ret = usb_register(&streamzap_driver);
if (ret < 0)
printk(KERN_ERR DRIVER_NAME ": usb register failed, "
"result = %d\n", ret);
return ret;
}
static void __exit streamzap_exit(void)
{
usb_deregister(&streamzap_driver);
}
