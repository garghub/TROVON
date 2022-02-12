static const char *get_medion_keymap(struct usb_interface *interface)
{
struct usb_device *udev = interface_to_usbdev(interface);
if (udev->manufacturer && udev->product) {
if (udev->actconfig->desc.bmAttributes & USB_CONFIG_ATT_WAKEUP) {
if (!strcmp(udev->manufacturer, "X10 Wireless Technology Inc")
&& !strcmp(udev->product, "USB Receiver"))
return RC_MAP_MEDION_X10_DIGITAINER;
if (!strcmp(udev->manufacturer, "X10 WTI")
&& !strcmp(udev->product, "RF receiver"))
return RC_MAP_MEDION_X10_OR2X;
} else {
if (!strcmp(udev->manufacturer, "X10 Wireless Technology Inc")
&& !strcmp(udev->product, "USB Receiver"))
return RC_MAP_MEDION_X10;
}
}
dev_info(&interface->dev,
"Unknown Medion X10 receiver, using default ati_remote Medion keymap\n");
return RC_MAP_MEDION_X10;
}
static void ati_remote_dump(struct device *dev, unsigned char *data,
unsigned int len)
{
if (len == 1) {
if (data[0] != (unsigned char)0xff && data[0] != 0x00)
dev_warn(dev, "Weird byte 0x%02x\n", data[0]);
} else if (len == 4)
dev_warn(dev, "Weird key %*ph\n", 4, data);
else
dev_warn(dev, "Weird data, len=%d %*ph ...\n", len, 6, data);
}
static int ati_remote_open(struct ati_remote *ati_remote)
{
int err = 0;
mutex_lock(&ati_remote->open_mutex);
if (ati_remote->users++ != 0)
goto out;
ati_remote->irq_urb->dev = ati_remote->udev;
if (usb_submit_urb(ati_remote->irq_urb, GFP_KERNEL)) {
dev_err(&ati_remote->interface->dev,
"%s: usb_submit_urb failed!\n", __func__);
err = -EIO;
}
out: mutex_unlock(&ati_remote->open_mutex);
return err;
}
static void ati_remote_close(struct ati_remote *ati_remote)
{
mutex_lock(&ati_remote->open_mutex);
if (--ati_remote->users == 0)
usb_kill_urb(ati_remote->irq_urb);
mutex_unlock(&ati_remote->open_mutex);
}
static int ati_remote_input_open(struct input_dev *inputdev)
{
struct ati_remote *ati_remote = input_get_drvdata(inputdev);
return ati_remote_open(ati_remote);
}
static void ati_remote_input_close(struct input_dev *inputdev)
{
struct ati_remote *ati_remote = input_get_drvdata(inputdev);
ati_remote_close(ati_remote);
}
static int ati_remote_rc_open(struct rc_dev *rdev)
{
struct ati_remote *ati_remote = rdev->priv;
return ati_remote_open(ati_remote);
}
static void ati_remote_rc_close(struct rc_dev *rdev)
{
struct ati_remote *ati_remote = rdev->priv;
ati_remote_close(ati_remote);
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
static int ati_remote_sendpacket(struct ati_remote *ati_remote, u16 cmd,
unsigned char *data)
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
int index = -1;
int acc;
int remote_num;
unsigned char scancode;
u32 wheel_keycode = KEY_RESERVED;
int i;
if ( (urb->actual_length != 4) || (data[0] != 0x14) ||
((data[3] & 0x0f) != 0x00) ) {
ati_remote_dump(&urb->dev->dev, data, urb->actual_length);
return;
}
if (data[1] != ((data[2] + data[3] + 0xd5) & 0xff)) {
dbginfo(&ati_remote->interface->dev,
"wrong checksum in input: %*ph\n", 4, data);
return;
}
remote_num = (data[3] >> 4) & 0x0f;
if (channel_mask & (1 << (remote_num + 1))) {
dbginfo(&ati_remote->interface->dev,
"Masked input from channel 0x%02x: data %02x,%02x, "
"mask= 0x%02lx\n",
remote_num, data[1], data[2], channel_mask);
return;
}
scancode = data[2] & 0x7f;
dbginfo(&ati_remote->interface->dev,
"channel 0x%02x; key data %02x, scancode %02x\n",
remote_num, data[2], scancode);
if (scancode >= 0x70) {
wheel_keycode = rc_g_keycode_from_table(ati_remote->rdev,
scancode & 0x78);
if (wheel_keycode == KEY_RESERVED) {
for (i = 0; ati_remote_tbl[i].kind != KIND_END; i++) {
if (scancode == ati_remote_tbl[i].data) {
index = i;
break;
}
}
}
}
if (index >= 0 && ati_remote_tbl[index].kind == KIND_LITERAL) {
input_event(dev, ati_remote_tbl[index].type,
ati_remote_tbl[index].code,
ati_remote_tbl[index].value);
input_sync(dev);
ati_remote->old_jiffies = jiffies;
return;
}
if (index < 0 || ati_remote_tbl[index].kind == KIND_FILTERED) {
unsigned long now = jiffies;
if (ati_remote->old_data == data[2] &&
time_before(now, ati_remote->old_jiffies +
msecs_to_jiffies(repeat_filter))) {
ati_remote->repeat_count++;
} else {
ati_remote->repeat_count = 0;
ati_remote->first_jiffies = now;
}
ati_remote->old_data = data[2];
ati_remote->old_jiffies = now;
if (ati_remote->repeat_count > 0 &&
(ati_remote->repeat_count < 5 ||
time_before(now, ati_remote->first_jiffies +
msecs_to_jiffies(repeat_delay))))
return;
if (index < 0) {
int count = 1;
if (wheel_keycode != KEY_RESERVED) {
count = (scancode & 0x07) + 1;
scancode &= 0x78;
}
while (count--) {
rc_keydown_notimeout(ati_remote->rdev, scancode,
data[2]);
rc_keyup(ati_remote->rdev);
}
return;
}
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
dev_dbg(&ati_remote->interface->dev,
"ati_remote kind=%d\n",
ati_remote_tbl[index].kind);
}
input_sync(dev);
ati_remote->old_jiffies = jiffies;
ati_remote->old_data = data[2];
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
dev_dbg(&ati_remote->interface->dev,
"%s: urb error status, unlink?\n",
__func__);
return;
default:
dev_dbg(&ati_remote->interface->dev,
"%s: Nonzero urb status %d\n",
__func__, urb->status);
}
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&ati_remote->interface->dev,
"%s: usb_submit_urb()=%d\n",
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
idev->open = ati_remote_input_open;
idev->close = ati_remote_input_close;
idev->name = ati_remote->mouse_name;
idev->phys = ati_remote->mouse_phys;
usb_to_input_id(ati_remote->udev, &idev->id);
idev->dev.parent = &ati_remote->interface->dev;
}
static void ati_remote_rc_init(struct ati_remote *ati_remote)
{
struct rc_dev *rdev = ati_remote->rdev;
rdev->priv = ati_remote;
rdev->driver_type = RC_DRIVER_SCANCODE;
rdev->allowed_protos = RC_TYPE_OTHER;
rdev->driver_name = "ati_remote";
rdev->open = ati_remote_rc_open;
rdev->close = ati_remote_rc_close;
rdev->input_name = ati_remote->rc_name;
rdev->input_phys = ati_remote->rc_phys;
usb_to_input_id(ati_remote->udev, &rdev->input_id);
rdev->dev.parent = &ati_remote->interface->dev;
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
static int ati_remote_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(interface);
struct usb_host_interface *iface_host = interface->cur_altsetting;
struct usb_endpoint_descriptor *endpoint_in, *endpoint_out;
struct ati_receiver_type *type = (struct ati_receiver_type *)id->driver_info;
struct ati_remote *ati_remote;
struct input_dev *input_dev;
struct rc_dev *rc_dev;
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
rc_dev = rc_allocate_device();
if (!ati_remote || !rc_dev)
goto fail1;
if (ati_remote_alloc_buffers(udev, ati_remote))
goto fail2;
ati_remote->endpoint_in = endpoint_in;
ati_remote->endpoint_out = endpoint_out;
ati_remote->udev = udev;
ati_remote->rdev = rc_dev;
ati_remote->interface = interface;
usb_make_path(udev, ati_remote->rc_phys, sizeof(ati_remote->rc_phys));
strlcpy(ati_remote->mouse_phys, ati_remote->rc_phys,
sizeof(ati_remote->mouse_phys));
strlcat(ati_remote->rc_phys, "/input0", sizeof(ati_remote->rc_phys));
strlcat(ati_remote->mouse_phys, "/input1", sizeof(ati_remote->mouse_phys));
if (udev->manufacturer)
strlcpy(ati_remote->rc_name, udev->manufacturer,
sizeof(ati_remote->rc_name));
if (udev->product)
snprintf(ati_remote->rc_name, sizeof(ati_remote->rc_name),
"%s %s", ati_remote->rc_name, udev->product);
if (!strlen(ati_remote->rc_name))
snprintf(ati_remote->rc_name, sizeof(ati_remote->rc_name),
DRIVER_DESC "(%04x,%04x)",
le16_to_cpu(ati_remote->udev->descriptor.idVendor),
le16_to_cpu(ati_remote->udev->descriptor.idProduct));
snprintf(ati_remote->mouse_name, sizeof(ati_remote->mouse_name),
"%s mouse", ati_remote->rc_name);
rc_dev->map_name = RC_MAP_ATI_X10;
if (type) {
if (type->default_keymap)
rc_dev->map_name = type->default_keymap;
else if (type->get_default_keymap)
rc_dev->map_name = type->get_default_keymap(interface);
}
ati_remote_rc_init(ati_remote);
mutex_init(&ati_remote->open_mutex);
err = ati_remote_initialize(ati_remote);
if (err)
goto fail3;
err = rc_register_device(ati_remote->rdev);
if (err)
goto fail3;
ati_remote->rdev->input_dev->rep[REP_DELAY] = repeat_delay;
if (mouse) {
input_dev = input_allocate_device();
if (!input_dev) {
err = -ENOMEM;
goto fail4;
}
ati_remote->idev = input_dev;
ati_remote_input_init(ati_remote);
err = input_register_device(input_dev);
if (err)
goto fail5;
}
usb_set_intfdata(interface, ati_remote);
return 0;
fail5: input_free_device(input_dev);
fail4: rc_unregister_device(rc_dev);
rc_dev = NULL;
fail3: usb_kill_urb(ati_remote->irq_urb);
usb_kill_urb(ati_remote->out_urb);
fail2: ati_remote_free_buffers(ati_remote);
fail1: rc_free_device(rc_dev);
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
if (ati_remote->idev)
input_unregister_device(ati_remote->idev);
rc_unregister_device(ati_remote->rdev);
ati_remote_free_buffers(ati_remote);
kfree(ati_remote);
}
