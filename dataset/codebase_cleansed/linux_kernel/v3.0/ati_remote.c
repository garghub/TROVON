static void ati_remote_dump(struct device *dev, unsigned char *data,
unsigned int len)
{
if ((len == 1) && (data[0] != (unsigned char)0xff) && (data[0] != 0x00))
dev_warn(dev, "Weird byte 0x%02x\n", data[0]);
else if (len == 4)
dev_warn(dev, "Weird key %02x %02x %02x %02x\n",
data[0], data[1], data[2], data[3]);
else
dev_warn(dev, "Weird data, len=%d %02x %02x %02x %02x %02x %02x ...\n",
len, data[0], data[1], data[2], data[3], data[4], data[5]);
}
static int ati_remote_open(struct input_dev *inputdev)
{
struct ati_remote *ati_remote = input_get_drvdata(inputdev);
ati_remote->irq_urb->dev = ati_remote->udev;
if (usb_submit_urb(ati_remote->irq_urb, GFP_KERNEL)) {
dev_err(&ati_remote->interface->dev,
"%s: usb_submit_urb failed!\n", __func__);
return -EIO;
}
return 0;
}
static void ati_remote_close(struct input_dev *inputdev)
{
struct ati_remote *ati_remote = input_get_drvdata(inputdev);
usb_kill_urb(ati_remote->irq_urb);
}
static void ati_remote_irq_out(struct urb *urb)
{
struct ati_remote *ati_remote = urb->context;
if (urb->status) {
dev_dbg(&ati_remote->interface->dev, "%s: status %d\n",
__func__, urb->status);
return;
}
ati_remote->send_flags |= SEND_FLAG_COMPLETE;
wmb();
wake_up(&ati_remote->wait);
}
static int ati_remote_sendpacket(struct ati_remote *ati_remote, u16 cmd, unsigned char *data)
{
int retval = 0;
memcpy(ati_remote->out_urb->transfer_buffer + 1, data, LO(cmd));
((char *) ati_remote->out_urb->transfer_buffer)[0] = HI(cmd);
ati_remote->out_urb->transfer_buffer_length = LO(cmd) + 1;
ati_remote->out_urb->dev = ati_remote->udev;
ati_remote->send_flags = SEND_FLAG_IN_PROGRESS;
retval = usb_submit_urb(ati_remote->out_urb, GFP_ATOMIC);
if (retval) {
dev_dbg(&ati_remote->interface->dev,
"sendpacket: usb_submit_urb failed: %d\n", retval);
return retval;
}
wait_event_timeout(ati_remote->wait,
((ati_remote->out_urb->status != -EINPROGRESS) ||
(ati_remote->send_flags & SEND_FLAG_COMPLETE)),
HZ);
usb_kill_urb(ati_remote->out_urb);
return retval;
}
static int ati_remote_event_lookup(int rem, unsigned char d1, unsigned char d2)
{
int i;
for (i = 0; ati_remote_tbl[i].kind != KIND_END; i++) {
if ((((ati_remote_tbl[i].data1 & 0x0f) == (d1 & 0x0f))) &&
((((ati_remote_tbl[i].data1 >> 4) -
(d1 >> 4) + rem) & 0x0f) == 0x0f) &&
(ati_remote_tbl[i].data2 == d2))
return i;
}
return -1;
}
static int ati_remote_compute_accel(struct ati_remote *ati_remote)
{
static const char accel[] = { 1, 2, 4, 6, 9, 13, 20 };
unsigned long now = jiffies;
int acc;
if (time_after(now, ati_remote->old_jiffies + msecs_to_jiffies(250))) {
acc = 1;
ati_remote->acc_jiffies = now;
}
else if (time_before(now, ati_remote->acc_jiffies + msecs_to_jiffies(125)))
acc = accel[0];
else if (time_before(now, ati_remote->acc_jiffies + msecs_to_jiffies(250)))
acc = accel[1];
else if (time_before(now, ati_remote->acc_jiffies + msecs_to_jiffies(500)))
acc = accel[2];
else if (time_before(now, ati_remote->acc_jiffies + msecs_to_jiffies(1000)))
acc = accel[3];
else if (time_before(now, ati_remote->acc_jiffies + msecs_to_jiffies(1500)))
acc = accel[4];
else if (time_before(now, ati_remote->acc_jiffies + msecs_to_jiffies(2000)))
acc = accel[5];
else
acc = accel[6];
return acc;
}
static void ati_remote_input_report(struct urb *urb)
{
struct ati_remote *ati_remote = urb->context;
unsigned char *data= ati_remote->inbuf;
struct input_dev *dev = ati_remote->idev;
int index, acc;
int remote_num;
if ( (urb->actual_length != 4) || (data[0] != 0x14) ||
((data[3] & 0x0f) != 0x00) ) {
ati_remote_dump(&urb->dev->dev, data, urb->actual_length);
return;
}
remote_num = (data[3] >> 4) & 0x0f;
if (channel_mask & (1 << (remote_num + 1))) {
dbginfo(&ati_remote->interface->dev,
"Masked input from channel 0x%02x: data %02x,%02x, mask= 0x%02lx\n",
remote_num, data[1], data[2], channel_mask);
return;
}
index = ati_remote_event_lookup(remote_num, data[1], data[2]);
if (index < 0) {
dev_warn(&ati_remote->interface->dev,
"Unknown input from channel 0x%02x: data %02x,%02x\n",
remote_num, data[1], data[2]);
return;
}
dbginfo(&ati_remote->interface->dev,
"channel 0x%02x; data %02x,%02x; index %d; keycode %d\n",
remote_num, data[1], data[2], index, ati_remote_tbl[index].code);
if (ati_remote_tbl[index].kind == KIND_LITERAL) {
input_event(dev, ati_remote_tbl[index].type,
ati_remote_tbl[index].code,
ati_remote_tbl[index].value);
input_sync(dev);
ati_remote->old_jiffies = jiffies;
return;
}
if (ati_remote_tbl[index].kind == KIND_FILTERED) {
unsigned long now = jiffies;
if (ati_remote->old_data[0] == data[1] &&
ati_remote->old_data[1] == data[2] &&
time_before(now, ati_remote->old_jiffies +
msecs_to_jiffies(repeat_filter))) {
ati_remote->repeat_count++;
} else {
ati_remote->repeat_count = 0;
ati_remote->first_jiffies = now;
}
ati_remote->old_data[0] = data[1];
ati_remote->old_data[1] = data[2];
ati_remote->old_jiffies = now;
if (ati_remote->repeat_count > 0 &&
(ati_remote->repeat_count < 5 ||
time_before(now, ati_remote->first_jiffies +
msecs_to_jiffies(repeat_delay))))
return;
input_event(dev, ati_remote_tbl[index].type,
ati_remote_tbl[index].code, 1);
input_sync(dev);
input_event(dev, ati_remote_tbl[index].type,
ati_remote_tbl[index].code, 0);
input_sync(dev);
} else {
acc = ati_remote_compute_accel(ati_remote);
switch (ati_remote_tbl[index].kind) {
case KIND_ACCEL:
input_event(dev, ati_remote_tbl[index].type,
ati_remote_tbl[index].code,
ati_remote_tbl[index].value * acc);
break;
case KIND_LU:
input_report_rel(dev, REL_X, -acc);
input_report_rel(dev, REL_Y, -acc);
break;
case KIND_RU:
input_report_rel(dev, REL_X, acc);
input_report_rel(dev, REL_Y, -acc);
break;
case KIND_LD:
input_report_rel(dev, REL_X, -acc);
input_report_rel(dev, REL_Y, acc);
break;
case KIND_RD:
input_report_rel(dev, REL_X, acc);
input_report_rel(dev, REL_Y, acc);
break;
default:
dev_dbg(&ati_remote->interface->dev, "ati_remote kind=%d\n",
ati_remote_tbl[index].kind);
}
input_sync(dev);
ati_remote->old_jiffies = jiffies;
ati_remote->old_data[0] = data[1];
ati_remote->old_data[1] = data[2];
}
}
static void ati_remote_irq_in(struct urb *urb)
{
struct ati_remote *ati_remote = urb->context;
int retval;
switch (urb->status) {
case 0:
ati_remote_input_report(urb);
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(&ati_remote->interface->dev, "%s: urb error status, unlink? \n",
__func__);
return;
default:
dev_dbg(&ati_remote->interface->dev, "%s: Nonzero urb status %d\n",
__func__, urb->status);
}
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&ati_remote->interface->dev, "%s: usb_submit_urb()=%d\n",
__func__, retval);
}
static int ati_remote_alloc_buffers(struct usb_device *udev,
struct ati_remote *ati_remote)
{
ati_remote->inbuf = usb_alloc_coherent(udev, DATA_BUFSIZE, GFP_ATOMIC,
&ati_remote->inbuf_dma);
if (!ati_remote->inbuf)
return -1;
ati_remote->outbuf = usb_alloc_coherent(udev, DATA_BUFSIZE, GFP_ATOMIC,
&ati_remote->outbuf_dma);
if (!ati_remote->outbuf)
return -1;
ati_remote->irq_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!ati_remote->irq_urb)
return -1;
ati_remote->out_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!ati_remote->out_urb)
return -1;
return 0;
}
static void ati_remote_free_buffers(struct ati_remote *ati_remote)
{
usb_free_urb(ati_remote->irq_urb);
usb_free_urb(ati_remote->out_urb);
usb_free_coherent(ati_remote->udev, DATA_BUFSIZE,
ati_remote->inbuf, ati_remote->inbuf_dma);
usb_free_coherent(ati_remote->udev, DATA_BUFSIZE,
ati_remote->outbuf, ati_remote->outbuf_dma);
}
static void ati_remote_input_init(struct ati_remote *ati_remote)
{
struct input_dev *idev = ati_remote->idev;
int i;
idev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REL);
idev->keybit[BIT_WORD(BTN_MOUSE)] = BIT_MASK(BTN_LEFT) |
BIT_MASK(BTN_RIGHT) | BIT_MASK(BTN_SIDE) | BIT_MASK(BTN_EXTRA);
idev->relbit[0] = BIT_MASK(REL_X) | BIT_MASK(REL_Y);
for (i = 0; ati_remote_tbl[i].kind != KIND_END; i++)
if (ati_remote_tbl[i].type == EV_KEY)
set_bit(ati_remote_tbl[i].code, idev->keybit);
input_set_drvdata(idev, ati_remote);
idev->open = ati_remote_open;
idev->close = ati_remote_close;
idev->name = ati_remote->name;
idev->phys = ati_remote->phys;
usb_to_input_id(ati_remote->udev, &idev->id);
idev->dev.parent = &ati_remote->udev->dev;
}
static int ati_remote_initialize(struct ati_remote *ati_remote)
{
struct usb_device *udev = ati_remote->udev;
int pipe, maxp;
init_waitqueue_head(&ati_remote->wait);
pipe = usb_rcvintpipe(udev, ati_remote->endpoint_in->bEndpointAddress);
maxp = usb_maxpacket(udev, pipe, usb_pipeout(pipe));
maxp = (maxp > DATA_BUFSIZE) ? DATA_BUFSIZE : maxp;
usb_fill_int_urb(ati_remote->irq_urb, udev, pipe, ati_remote->inbuf,
maxp, ati_remote_irq_in, ati_remote,
ati_remote->endpoint_in->bInterval);
ati_remote->irq_urb->transfer_dma = ati_remote->inbuf_dma;
ati_remote->irq_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
pipe = usb_sndintpipe(udev, ati_remote->endpoint_out->bEndpointAddress);
maxp = usb_maxpacket(udev, pipe, usb_pipeout(pipe));
maxp = (maxp > DATA_BUFSIZE) ? DATA_BUFSIZE : maxp;
usb_fill_int_urb(ati_remote->out_urb, udev, pipe, ati_remote->outbuf,
maxp, ati_remote_irq_out, ati_remote,
ati_remote->endpoint_out->bInterval);
ati_remote->out_urb->transfer_dma = ati_remote->outbuf_dma;
ati_remote->out_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
if ((ati_remote_sendpacket(ati_remote, 0x8004, init1)) ||
(ati_remote_sendpacket(ati_remote, 0x8007, init2))) {
dev_err(&ati_remote->interface->dev,
"Initializing ati_remote hardware failed.\n");
return -EIO;
}
return 0;
}
static int ati_remote_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(interface);
struct usb_host_interface *iface_host = interface->cur_altsetting;
struct usb_endpoint_descriptor *endpoint_in, *endpoint_out;
struct ati_remote *ati_remote;
struct input_dev *input_dev;
int err = -ENOMEM;
if (iface_host->desc.bNumEndpoints != 2) {
err("%s: Unexpected desc.bNumEndpoints\n", __func__);
return -ENODEV;
}
endpoint_in = &iface_host->endpoint[0].desc;
endpoint_out = &iface_host->endpoint[1].desc;
if (!usb_endpoint_is_int_in(endpoint_in)) {
err("%s: Unexpected endpoint_in\n", __func__);
return -ENODEV;
}
if (le16_to_cpu(endpoint_in->wMaxPacketSize) == 0) {
err("%s: endpoint_in message size==0? \n", __func__);
return -ENODEV;
}
ati_remote = kzalloc(sizeof (struct ati_remote), GFP_KERNEL);
input_dev = input_allocate_device();
if (!ati_remote || !input_dev)
goto fail1;
if (ati_remote_alloc_buffers(udev, ati_remote))
goto fail2;
ati_remote->endpoint_in = endpoint_in;
ati_remote->endpoint_out = endpoint_out;
ati_remote->udev = udev;
ati_remote->idev = input_dev;
ati_remote->interface = interface;
usb_make_path(udev, ati_remote->phys, sizeof(ati_remote->phys));
strlcat(ati_remote->phys, "/input0", sizeof(ati_remote->phys));
if (udev->manufacturer)
strlcpy(ati_remote->name, udev->manufacturer, sizeof(ati_remote->name));
if (udev->product)
snprintf(ati_remote->name, sizeof(ati_remote->name),
"%s %s", ati_remote->name, udev->product);
if (!strlen(ati_remote->name))
snprintf(ati_remote->name, sizeof(ati_remote->name),
DRIVER_DESC "(%04x,%04x)",
le16_to_cpu(ati_remote->udev->descriptor.idVendor),
le16_to_cpu(ati_remote->udev->descriptor.idProduct));
ati_remote_input_init(ati_remote);
err = ati_remote_initialize(ati_remote);
if (err)
goto fail3;
err = input_register_device(ati_remote->idev);
if (err)
goto fail3;
usb_set_intfdata(interface, ati_remote);
return 0;
fail3: usb_kill_urb(ati_remote->irq_urb);
usb_kill_urb(ati_remote->out_urb);
fail2: ati_remote_free_buffers(ati_remote);
fail1: input_free_device(input_dev);
kfree(ati_remote);
return err;
}
static void ati_remote_disconnect(struct usb_interface *interface)
{
struct ati_remote *ati_remote;
ati_remote = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
if (!ati_remote) {
dev_warn(&interface->dev, "%s - null device?\n", __func__);
return;
}
usb_kill_urb(ati_remote->irq_urb);
usb_kill_urb(ati_remote->out_urb);
input_unregister_device(ati_remote->idev);
ati_remote_free_buffers(ati_remote);
kfree(ati_remote);
}
static int __init ati_remote_init(void)
{
int result;
result = usb_register(&ati_remote_driver);
if (result)
printk(KERN_ERR KBUILD_MODNAME
": usb_register error #%d\n", result);
else
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
return result;
}
static void __exit ati_remote_exit(void)
{
usb_deregister(&ati_remote_driver);
}
