static void xpad_process_packet(struct usb_xpad *xpad, u16 cmd, unsigned char *data)
{
struct input_dev *dev = xpad->dev;
if (!(xpad->mapping & MAP_STICKS_TO_NULL)) {
input_report_abs(dev, ABS_X,
(__s16) le16_to_cpup((__le16 *)(data + 12)));
input_report_abs(dev, ABS_Y,
~(__s16) le16_to_cpup((__le16 *)(data + 14)));
input_report_abs(dev, ABS_RX,
(__s16) le16_to_cpup((__le16 *)(data + 16)));
input_report_abs(dev, ABS_RY,
~(__s16) le16_to_cpup((__le16 *)(data + 18)));
}
if (xpad->mapping & MAP_TRIGGERS_TO_BUTTONS) {
input_report_key(dev, BTN_TL2, data[10]);
input_report_key(dev, BTN_TR2, data[11]);
} else {
input_report_abs(dev, ABS_Z, data[10]);
input_report_abs(dev, ABS_RZ, data[11]);
}
if (xpad->mapping & MAP_DPAD_TO_BUTTONS) {
input_report_key(dev, BTN_TRIGGER_HAPPY1, data[2] & 0x04);
input_report_key(dev, BTN_TRIGGER_HAPPY2, data[2] & 0x08);
input_report_key(dev, BTN_TRIGGER_HAPPY3, data[2] & 0x01);
input_report_key(dev, BTN_TRIGGER_HAPPY4, data[2] & 0x02);
} else {
input_report_abs(dev, ABS_HAT0X,
!!(data[2] & 0x08) - !!(data[2] & 0x04));
input_report_abs(dev, ABS_HAT0Y,
!!(data[2] & 0x02) - !!(data[2] & 0x01));
}
input_report_key(dev, BTN_START, data[2] & 0x10);
input_report_key(dev, BTN_SELECT, data[2] & 0x20);
input_report_key(dev, BTN_THUMBL, data[2] & 0x40);
input_report_key(dev, BTN_THUMBR, data[2] & 0x80);
input_report_key(dev, BTN_A, data[4]);
input_report_key(dev, BTN_B, data[5]);
input_report_key(dev, BTN_X, data[6]);
input_report_key(dev, BTN_Y, data[7]);
input_report_key(dev, BTN_C, data[8]);
input_report_key(dev, BTN_Z, data[9]);
input_sync(dev);
}
static void xpad360_process_packet(struct usb_xpad *xpad,
u16 cmd, unsigned char *data)
{
struct input_dev *dev = xpad->dev;
if (xpad->mapping & MAP_DPAD_TO_BUTTONS) {
input_report_key(dev, BTN_TRIGGER_HAPPY1, data[2] & 0x04);
input_report_key(dev, BTN_TRIGGER_HAPPY2, data[2] & 0x08);
input_report_key(dev, BTN_TRIGGER_HAPPY3, data[2] & 0x01);
input_report_key(dev, BTN_TRIGGER_HAPPY4, data[2] & 0x02);
} else {
input_report_abs(dev, ABS_HAT0X,
!!(data[2] & 0x08) - !!(data[2] & 0x04));
input_report_abs(dev, ABS_HAT0Y,
!!(data[2] & 0x02) - !!(data[2] & 0x01));
}
input_report_key(dev, BTN_START, data[2] & 0x10);
input_report_key(dev, BTN_SELECT, data[2] & 0x20);
input_report_key(dev, BTN_THUMBL, data[2] & 0x40);
input_report_key(dev, BTN_THUMBR, data[2] & 0x80);
input_report_key(dev, BTN_A, data[3] & 0x10);
input_report_key(dev, BTN_B, data[3] & 0x20);
input_report_key(dev, BTN_X, data[3] & 0x40);
input_report_key(dev, BTN_Y, data[3] & 0x80);
input_report_key(dev, BTN_TL, data[3] & 0x01);
input_report_key(dev, BTN_TR, data[3] & 0x02);
input_report_key(dev, BTN_MODE, data[3] & 0x04);
if (!(xpad->mapping & MAP_STICKS_TO_NULL)) {
input_report_abs(dev, ABS_X,
(__s16) le16_to_cpup((__le16 *)(data + 6)));
input_report_abs(dev, ABS_Y,
~(__s16) le16_to_cpup((__le16 *)(data + 8)));
input_report_abs(dev, ABS_RX,
(__s16) le16_to_cpup((__le16 *)(data + 10)));
input_report_abs(dev, ABS_RY,
~(__s16) le16_to_cpup((__le16 *)(data + 12)));
}
if (xpad->mapping & MAP_TRIGGERS_TO_BUTTONS) {
input_report_key(dev, BTN_TL2, data[4]);
input_report_key(dev, BTN_TR2, data[5]);
} else {
input_report_abs(dev, ABS_Z, data[4]);
input_report_abs(dev, ABS_RZ, data[5]);
}
input_sync(dev);
}
static void xpad360w_process_packet(struct usb_xpad *xpad, u16 cmd, unsigned char *data)
{
if (data[0] & 0x08) {
if (data[1] & 0x80) {
xpad->pad_present = 1;
usb_submit_urb(xpad->bulk_out, GFP_ATOMIC);
xpad_identify_controller(xpad);
} else
xpad->pad_present = 0;
}
if (!(data[1] & 0x1))
return;
xpad360_process_packet(xpad, cmd, &data[4]);
}
static void xpadone_process_buttons(struct usb_xpad *xpad,
struct input_dev *dev,
unsigned char *data)
{
input_report_key(dev, BTN_START, data[4] & 0x04);
input_report_key(dev, BTN_SELECT, data[4] & 0x08);
input_report_key(dev, BTN_A, data[4] & 0x10);
input_report_key(dev, BTN_B, data[4] & 0x20);
input_report_key(dev, BTN_X, data[4] & 0x40);
input_report_key(dev, BTN_Y, data[4] & 0x80);
if (xpad->mapping & MAP_DPAD_TO_BUTTONS) {
input_report_key(dev, BTN_TRIGGER_HAPPY1, data[5] & 0x04);
input_report_key(dev, BTN_TRIGGER_HAPPY2, data[5] & 0x08);
input_report_key(dev, BTN_TRIGGER_HAPPY3, data[5] & 0x01);
input_report_key(dev, BTN_TRIGGER_HAPPY4, data[5] & 0x02);
} else {
input_report_abs(dev, ABS_HAT0X,
!!(data[5] & 0x08) - !!(data[5] & 0x04));
input_report_abs(dev, ABS_HAT0Y,
!!(data[5] & 0x02) - !!(data[5] & 0x01));
}
input_report_key(dev, BTN_TL, data[5] & 0x10);
input_report_key(dev, BTN_TR, data[5] & 0x20);
input_report_key(dev, BTN_THUMBL, data[5] & 0x40);
input_report_key(dev, BTN_THUMBR, data[5] & 0x80);
if (!(xpad->mapping & MAP_STICKS_TO_NULL)) {
input_report_abs(dev, ABS_X,
(__s16) le16_to_cpup((__le16 *)(data + 10)));
input_report_abs(dev, ABS_Y,
~(__s16) le16_to_cpup((__le16 *)(data + 12)));
input_report_abs(dev, ABS_RX,
(__s16) le16_to_cpup((__le16 *)(data + 14)));
input_report_abs(dev, ABS_RY,
~(__s16) le16_to_cpup((__le16 *)(data + 16)));
}
if (xpad->mapping & MAP_TRIGGERS_TO_BUTTONS) {
input_report_key(dev, BTN_TL2,
(__u16) le16_to_cpup((__le16 *)(data + 6)));
input_report_key(dev, BTN_TR2,
(__u16) le16_to_cpup((__le16 *)(data + 8)));
} else {
input_report_abs(dev, ABS_Z,
(__u16) le16_to_cpup((__le16 *)(data + 6)));
input_report_abs(dev, ABS_RZ,
(__u16) le16_to_cpup((__le16 *)(data + 8)));
}
input_sync(dev);
}
static void xpadone_process_packet(struct usb_xpad *xpad,
u16 cmd, unsigned char *data)
{
struct input_dev *dev = xpad->dev;
switch (data[0]) {
case 0x20:
xpadone_process_buttons(xpad, dev, data);
break;
case 0x07:
input_report_key(dev, BTN_MODE, data[4] & 0x01);
input_sync(dev);
break;
}
}
static void xpad_irq_in(struct urb *urb)
{
struct usb_xpad *xpad = urb->context;
struct device *dev = &xpad->intf->dev;
int retval, status;
status = urb->status;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(dev, "%s - urb shutting down with status: %d\n",
__func__, status);
return;
default:
dev_dbg(dev, "%s - nonzero urb status received: %d\n",
__func__, status);
goto exit;
}
switch (xpad->xtype) {
case XTYPE_XBOX360:
xpad360_process_packet(xpad, 0, xpad->idata);
break;
case XTYPE_XBOX360W:
xpad360w_process_packet(xpad, 0, xpad->idata);
break;
case XTYPE_XBOXONE:
xpadone_process_packet(xpad, 0, xpad->idata);
break;
default:
xpad_process_packet(xpad, 0, xpad->idata);
}
exit:
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(dev, "%s - usb_submit_urb failed with result %d\n",
__func__, retval);
}
static void xpad_bulk_out(struct urb *urb)
{
struct usb_xpad *xpad = urb->context;
struct device *dev = &xpad->intf->dev;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(dev, "%s - urb shutting down with status: %d\n",
__func__, urb->status);
break;
default:
dev_dbg(dev, "%s - nonzero urb status received: %d\n",
__func__, urb->status);
}
}
static void xpad_irq_out(struct urb *urb)
{
struct usb_xpad *xpad = urb->context;
struct device *dev = &xpad->intf->dev;
int retval, status;
status = urb->status;
switch (status) {
case 0:
return;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(dev, "%s - urb shutting down with status: %d\n",
__func__, status);
return;
default:
dev_dbg(dev, "%s - nonzero urb status received: %d\n",
__func__, status);
goto exit;
}
exit:
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(dev, "%s - usb_submit_urb failed with result %d\n",
__func__, retval);
}
static int xpad_init_output(struct usb_interface *intf, struct usb_xpad *xpad)
{
struct usb_endpoint_descriptor *ep_irq_out;
int ep_irq_out_idx;
int error;
if (xpad->xtype == XTYPE_UNKNOWN)
return 0;
xpad->odata = usb_alloc_coherent(xpad->udev, XPAD_PKT_LEN,
GFP_KERNEL, &xpad->odata_dma);
if (!xpad->odata) {
error = -ENOMEM;
goto fail1;
}
mutex_init(&xpad->odata_mutex);
xpad->irq_out = usb_alloc_urb(0, GFP_KERNEL);
if (!xpad->irq_out) {
error = -ENOMEM;
goto fail2;
}
ep_irq_out_idx = xpad->xtype == XTYPE_XBOXONE ? 0 : 1;
ep_irq_out = &intf->cur_altsetting->endpoint[ep_irq_out_idx].desc;
usb_fill_int_urb(xpad->irq_out, xpad->udev,
usb_sndintpipe(xpad->udev, ep_irq_out->bEndpointAddress),
xpad->odata, XPAD_PKT_LEN,
xpad_irq_out, xpad, ep_irq_out->bInterval);
xpad->irq_out->transfer_dma = xpad->odata_dma;
xpad->irq_out->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
return 0;
fail2: usb_free_coherent(xpad->udev, XPAD_PKT_LEN, xpad->odata, xpad->odata_dma);
fail1: return error;
}
static void xpad_stop_output(struct usb_xpad *xpad)
{
if (xpad->xtype != XTYPE_UNKNOWN)
usb_kill_urb(xpad->irq_out);
}
static void xpad_deinit_output(struct usb_xpad *xpad)
{
if (xpad->xtype != XTYPE_UNKNOWN) {
usb_free_urb(xpad->irq_out);
usb_free_coherent(xpad->udev, XPAD_PKT_LEN,
xpad->odata, xpad->odata_dma);
}
}
static int xpad_play_effect(struct input_dev *dev, void *data, struct ff_effect *effect)
{
struct usb_xpad *xpad = input_get_drvdata(dev);
if (effect->type == FF_RUMBLE) {
__u16 strong = effect->u.rumble.strong_magnitude;
__u16 weak = effect->u.rumble.weak_magnitude;
switch (xpad->xtype) {
case XTYPE_XBOX:
xpad->odata[0] = 0x00;
xpad->odata[1] = 0x06;
xpad->odata[2] = 0x00;
xpad->odata[3] = strong / 256;
xpad->odata[4] = 0x00;
xpad->odata[5] = weak / 256;
xpad->irq_out->transfer_buffer_length = 6;
return usb_submit_urb(xpad->irq_out, GFP_ATOMIC);
case XTYPE_XBOX360:
xpad->odata[0] = 0x00;
xpad->odata[1] = 0x08;
xpad->odata[2] = 0x00;
xpad->odata[3] = strong / 256;
xpad->odata[4] = weak / 256;
xpad->odata[5] = 0x00;
xpad->odata[6] = 0x00;
xpad->odata[7] = 0x00;
xpad->irq_out->transfer_buffer_length = 8;
return usb_submit_urb(xpad->irq_out, GFP_ATOMIC);
case XTYPE_XBOX360W:
xpad->odata[0] = 0x00;
xpad->odata[1] = 0x01;
xpad->odata[2] = 0x0F;
xpad->odata[3] = 0xC0;
xpad->odata[4] = 0x00;
xpad->odata[5] = strong / 256;
xpad->odata[6] = weak / 256;
xpad->odata[7] = 0x00;
xpad->odata[8] = 0x00;
xpad->odata[9] = 0x00;
xpad->odata[10] = 0x00;
xpad->odata[11] = 0x00;
xpad->irq_out->transfer_buffer_length = 12;
return usb_submit_urb(xpad->irq_out, GFP_ATOMIC);
case XTYPE_XBOXONE:
xpad->odata[0] = 0x09;
xpad->odata[1] = 0x08;
xpad->odata[2] = 0x00;
xpad->odata[3] = 0x08;
xpad->odata[4] = 0x00;
xpad->odata[5] = 0x03;
xpad->odata[6] = 0x00;
xpad->odata[7] = 0x00;
xpad->odata[8] = strong / 256;
xpad->odata[9] = weak / 256;
xpad->odata[10] = 0x80;
xpad->odata[11] = 0x00;
xpad->irq_out->transfer_buffer_length = 12;
return usb_submit_urb(xpad->irq_out, GFP_ATOMIC);
default:
dev_dbg(&xpad->dev->dev,
"%s - rumble command sent to unsupported xpad type: %d\n",
__func__, xpad->xtype);
return -1;
}
}
return 0;
}
static int xpad_init_ff(struct usb_xpad *xpad)
{
if (xpad->xtype == XTYPE_UNKNOWN)
return 0;
input_set_capability(xpad->dev, EV_FF, FF_RUMBLE);
return input_ff_create_memless(xpad->dev, NULL, xpad_play_effect);
}
static int xpad_init_ff(struct usb_xpad *xpad) { return 0; }
static void xpad_send_led_command(struct usb_xpad *xpad, int command)
{
command %= 16;
mutex_lock(&xpad->odata_mutex);
switch (xpad->xtype) {
case XTYPE_XBOX360:
xpad->odata[0] = 0x01;
xpad->odata[1] = 0x03;
xpad->odata[2] = command;
xpad->irq_out->transfer_buffer_length = 3;
break;
case XTYPE_XBOX360W:
xpad->odata[0] = 0x00;
xpad->odata[1] = 0x00;
xpad->odata[2] = 0x08;
xpad->odata[3] = 0x40 + command;
xpad->odata[4] = 0x00;
xpad->odata[5] = 0x00;
xpad->odata[6] = 0x00;
xpad->odata[7] = 0x00;
xpad->odata[8] = 0x00;
xpad->odata[9] = 0x00;
xpad->odata[10] = 0x00;
xpad->odata[11] = 0x00;
xpad->irq_out->transfer_buffer_length = 12;
break;
}
usb_submit_urb(xpad->irq_out, GFP_KERNEL);
mutex_unlock(&xpad->odata_mutex);
}
static void xpad_identify_controller(struct usb_xpad *xpad)
{
xpad_send_led_command(xpad, (xpad->led_no % 4) + 2);
}
static void xpad_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct xpad_led *xpad_led = container_of(led_cdev,
struct xpad_led, led_cdev);
xpad_send_led_command(xpad_led->xpad, value);
}
static int xpad_led_probe(struct usb_xpad *xpad)
{
static atomic_t led_seq = ATOMIC_INIT(-1);
struct xpad_led *led;
struct led_classdev *led_cdev;
int error;
if (xpad->xtype != XTYPE_XBOX360 && xpad->xtype != XTYPE_XBOX360W)
return 0;
xpad->led = led = kzalloc(sizeof(struct xpad_led), GFP_KERNEL);
if (!led)
return -ENOMEM;
xpad->led_no = atomic_inc_return(&led_seq);
snprintf(led->name, sizeof(led->name), "xpad%lu", xpad->led_no);
led->xpad = xpad;
led_cdev = &led->led_cdev;
led_cdev->name = led->name;
led_cdev->brightness_set = xpad_led_set;
error = led_classdev_register(&xpad->udev->dev, led_cdev);
if (error) {
kfree(led);
xpad->led = NULL;
return error;
}
xpad_identify_controller(xpad);
return 0;
}
static void xpad_led_disconnect(struct usb_xpad *xpad)
{
struct xpad_led *xpad_led = xpad->led;
if (xpad_led) {
led_classdev_unregister(&xpad_led->led_cdev);
kfree(xpad_led);
}
}
static int xpad_led_probe(struct usb_xpad *xpad) { return 0; }
static void xpad_led_disconnect(struct usb_xpad *xpad) { }
static void xpad_identify_controller(struct usb_xpad *xpad) { }
static int xpad_open(struct input_dev *dev)
{
struct usb_xpad *xpad = input_get_drvdata(dev);
if (xpad->xtype == XTYPE_XBOX360W)
return 0;
xpad->irq_in->dev = xpad->udev;
if (usb_submit_urb(xpad->irq_in, GFP_KERNEL))
return -EIO;
if (xpad->xtype == XTYPE_XBOXONE) {
xpad->odata[0] = 0x05;
xpad->odata[1] = 0x20;
xpad->irq_out->transfer_buffer_length = 2;
return usb_submit_urb(xpad->irq_out, GFP_KERNEL);
}
return 0;
}
static void xpad_close(struct input_dev *dev)
{
struct usb_xpad *xpad = input_get_drvdata(dev);
if (xpad->xtype != XTYPE_XBOX360W)
usb_kill_urb(xpad->irq_in);
xpad_stop_output(xpad);
}
static void xpad_set_up_abs(struct input_dev *input_dev, signed short abs)
{
struct usb_xpad *xpad = input_get_drvdata(input_dev);
set_bit(abs, input_dev->absbit);
switch (abs) {
case ABS_X:
case ABS_Y:
case ABS_RX:
case ABS_RY:
input_set_abs_params(input_dev, abs, -32768, 32767, 16, 128);
break;
case ABS_Z:
case ABS_RZ:
if (xpad->xtype == XTYPE_XBOXONE)
input_set_abs_params(input_dev, abs, 0, 1023, 0, 0);
else
input_set_abs_params(input_dev, abs, 0, 255, 0, 0);
break;
case ABS_HAT0X:
case ABS_HAT0Y:
input_set_abs_params(input_dev, abs, -1, 1, 0, 0);
break;
}
}
static int xpad_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct usb_xpad *xpad;
struct input_dev *input_dev;
struct usb_endpoint_descriptor *ep_irq_in;
int ep_irq_in_idx;
int i, error;
for (i = 0; xpad_device[i].idVendor; i++) {
if ((le16_to_cpu(udev->descriptor.idVendor) == xpad_device[i].idVendor) &&
(le16_to_cpu(udev->descriptor.idProduct) == xpad_device[i].idProduct))
break;
}
if (xpad_device[i].xtype == XTYPE_XBOXONE &&
intf->cur_altsetting->desc.bInterfaceNumber != 0) {
return -ENODEV;
}
xpad = kzalloc(sizeof(struct usb_xpad), GFP_KERNEL);
input_dev = input_allocate_device();
if (!xpad || !input_dev) {
error = -ENOMEM;
goto fail1;
}
xpad->idata = usb_alloc_coherent(udev, XPAD_PKT_LEN,
GFP_KERNEL, &xpad->idata_dma);
if (!xpad->idata) {
error = -ENOMEM;
goto fail1;
}
xpad->irq_in = usb_alloc_urb(0, GFP_KERNEL);
if (!xpad->irq_in) {
error = -ENOMEM;
goto fail2;
}
xpad->udev = udev;
xpad->intf = intf;
xpad->mapping = xpad_device[i].mapping;
xpad->xtype = xpad_device[i].xtype;
if (xpad->xtype == XTYPE_UNKNOWN) {
if (intf->cur_altsetting->desc.bInterfaceClass == USB_CLASS_VENDOR_SPEC) {
if (intf->cur_altsetting->desc.bInterfaceProtocol == 129)
xpad->xtype = XTYPE_XBOX360W;
else
xpad->xtype = XTYPE_XBOX360;
} else
xpad->xtype = XTYPE_XBOX;
if (dpad_to_buttons)
xpad->mapping |= MAP_DPAD_TO_BUTTONS;
if (triggers_to_buttons)
xpad->mapping |= MAP_TRIGGERS_TO_BUTTONS;
if (sticks_to_null)
xpad->mapping |= MAP_STICKS_TO_NULL;
}
xpad->dev = input_dev;
usb_make_path(udev, xpad->phys, sizeof(xpad->phys));
strlcat(xpad->phys, "/input0", sizeof(xpad->phys));
input_dev->name = xpad_device[i].name;
input_dev->phys = xpad->phys;
usb_to_input_id(udev, &input_dev->id);
input_dev->dev.parent = &intf->dev;
input_set_drvdata(input_dev, xpad);
input_dev->open = xpad_open;
input_dev->close = xpad_close;
input_dev->evbit[0] = BIT_MASK(EV_KEY);
if (!(xpad->mapping & MAP_STICKS_TO_NULL)) {
input_dev->evbit[0] |= BIT_MASK(EV_ABS);
for (i = 0; xpad_abs[i] >= 0; i++)
xpad_set_up_abs(input_dev, xpad_abs[i]);
}
for (i = 0; xpad_common_btn[i] >= 0; i++)
__set_bit(xpad_common_btn[i], input_dev->keybit);
if (xpad->xtype == XTYPE_XBOX360 || xpad->xtype == XTYPE_XBOX360W ||
xpad->xtype == XTYPE_XBOXONE) {
for (i = 0; xpad360_btn[i] >= 0; i++)
__set_bit(xpad360_btn[i], input_dev->keybit);
} else {
for (i = 0; xpad_btn[i] >= 0; i++)
__set_bit(xpad_btn[i], input_dev->keybit);
}
if (xpad->mapping & MAP_DPAD_TO_BUTTONS) {
for (i = 0; xpad_btn_pad[i] >= 0; i++)
__set_bit(xpad_btn_pad[i], input_dev->keybit);
} else {
for (i = 0; xpad_abs_pad[i] >= 0; i++)
xpad_set_up_abs(input_dev, xpad_abs_pad[i]);
}
if (xpad->mapping & MAP_TRIGGERS_TO_BUTTONS) {
for (i = 0; xpad_btn_triggers[i] >= 0; i++)
__set_bit(xpad_btn_triggers[i], input_dev->keybit);
} else {
for (i = 0; xpad_abs_triggers[i] >= 0; i++)
xpad_set_up_abs(input_dev, xpad_abs_triggers[i]);
}
error = xpad_init_output(intf, xpad);
if (error)
goto fail3;
error = xpad_init_ff(xpad);
if (error)
goto fail4;
error = xpad_led_probe(xpad);
if (error)
goto fail5;
ep_irq_in_idx = xpad->xtype == XTYPE_XBOXONE ? 1 : 0;
ep_irq_in = &intf->cur_altsetting->endpoint[ep_irq_in_idx].desc;
usb_fill_int_urb(xpad->irq_in, udev,
usb_rcvintpipe(udev, ep_irq_in->bEndpointAddress),
xpad->idata, XPAD_PKT_LEN, xpad_irq_in,
xpad, ep_irq_in->bInterval);
xpad->irq_in->transfer_dma = xpad->idata_dma;
xpad->irq_in->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
error = input_register_device(xpad->dev);
if (error)
goto fail6;
usb_set_intfdata(intf, xpad);
if (xpad->xtype == XTYPE_XBOX360W) {
xpad->bulk_out = usb_alloc_urb(0, GFP_KERNEL);
if (!xpad->bulk_out) {
error = -ENOMEM;
goto fail7;
}
xpad->bdata = kzalloc(XPAD_PKT_LEN, GFP_KERNEL);
if (!xpad->bdata) {
error = -ENOMEM;
goto fail8;
}
xpad->bdata[2] = 0x08;
switch (intf->cur_altsetting->desc.bInterfaceNumber) {
case 0:
xpad->bdata[3] = 0x42;
break;
case 2:
xpad->bdata[3] = 0x43;
break;
case 4:
xpad->bdata[3] = 0x44;
break;
case 6:
xpad->bdata[3] = 0x45;
}
ep_irq_in = &intf->cur_altsetting->endpoint[1].desc;
if (usb_endpoint_is_bulk_out(ep_irq_in)) {
usb_fill_bulk_urb(xpad->bulk_out, udev,
usb_sndbulkpipe(udev,
ep_irq_in->bEndpointAddress),
xpad->bdata, XPAD_PKT_LEN,
xpad_bulk_out, xpad);
} else {
usb_fill_int_urb(xpad->bulk_out, udev,
usb_sndintpipe(udev,
ep_irq_in->bEndpointAddress),
xpad->bdata, XPAD_PKT_LEN,
xpad_bulk_out, xpad, 0);
}
xpad->irq_in->dev = xpad->udev;
error = usb_submit_urb(xpad->irq_in, GFP_KERNEL);
if (error)
goto fail9;
}
return 0;
fail9: kfree(xpad->bdata);
fail8: usb_free_urb(xpad->bulk_out);
fail7: input_unregister_device(input_dev);
input_dev = NULL;
fail6: xpad_led_disconnect(xpad);
fail5: if (input_dev)
input_ff_destroy(input_dev);
fail4: xpad_deinit_output(xpad);
fail3: usb_free_urb(xpad->irq_in);
fail2: usb_free_coherent(udev, XPAD_PKT_LEN, xpad->idata, xpad->idata_dma);
fail1: input_free_device(input_dev);
kfree(xpad);
return error;
}
static void xpad_disconnect(struct usb_interface *intf)
{
struct usb_xpad *xpad = usb_get_intfdata (intf);
xpad_led_disconnect(xpad);
input_unregister_device(xpad->dev);
xpad_deinit_output(xpad);
if (xpad->xtype == XTYPE_XBOX360W) {
usb_kill_urb(xpad->bulk_out);
usb_free_urb(xpad->bulk_out);
usb_kill_urb(xpad->irq_in);
}
usb_free_urb(xpad->irq_in);
usb_free_coherent(xpad->udev, XPAD_PKT_LEN,
xpad->idata, xpad->idata_dma);
kfree(xpad->bdata);
kfree(xpad);
usb_set_intfdata(intf, NULL);
}
