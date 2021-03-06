static void hanwang_parse_packet(struct hanwang *hanwang)
{
unsigned char *data = hanwang->data;
struct input_dev *input_dev = hanwang->dev;
struct usb_device *dev = hanwang->usbdev;
enum hanwang_tablet_type type = hanwang->features->type;
int i;
u16 x, y, p;
switch (data[0]) {
case 0x02:
switch (data[1]) {
case 0x80:
hanwang->current_id = 0;
input_report_key(input_dev, hanwang->current_tool, 0);
break;
case 0xc2:
switch (data[3] & 0xf0) {
case 0x20:
case 0x30:
hanwang->current_id = STYLUS_DEVICE_ID;
hanwang->current_tool = BTN_TOOL_PEN;
input_report_key(input_dev, BTN_TOOL_PEN, 1);
break;
case 0xa0:
case 0xb0:
hanwang->current_id = ERASER_DEVICE_ID;
hanwang->current_tool = BTN_TOOL_RUBBER;
input_report_key(input_dev, BTN_TOOL_RUBBER, 1);
break;
default:
hanwang->current_id = 0;
dev_dbg(&dev->dev,
"unknown tablet tool %02x ", data[0]);
break;
}
break;
default:
x = (data[2] << 8) | data[3];
y = (data[4] << 8) | data[5];
switch (type) {
case HANWANG_ART_MASTER_III:
p = (data[6] << 3) |
((data[7] & 0xc0) >> 5) |
(data[1] & 0x01);
break;
case HANWANG_ART_MASTER_HD:
p = (data[7] >> 6) | (data[6] << 2);
break;
default:
p = 0;
break;
}
input_report_abs(input_dev, ABS_X,
le16_to_cpup((__le16 *)&x));
input_report_abs(input_dev, ABS_Y,
le16_to_cpup((__le16 *)&y));
input_report_abs(input_dev, ABS_PRESSURE,
le16_to_cpup((__le16 *)&p));
input_report_abs(input_dev, ABS_TILT_X, data[7] & 0x3f);
input_report_abs(input_dev, ABS_TILT_Y, data[8] & 0x7f);
input_report_key(input_dev, BTN_STYLUS, data[1] & 0x02);
input_report_key(input_dev, BTN_STYLUS2, data[1] & 0x04);
break;
}
input_report_abs(input_dev, ABS_MISC, hanwang->current_id);
input_event(input_dev, EV_MSC, MSC_SERIAL,
hanwang->features->pid);
break;
case 0x0c:
hanwang->current_id = PAD_DEVICE_ID;
switch (type) {
case HANWANG_ART_MASTER_III:
input_report_key(input_dev, BTN_TOOL_FINGER, data[1] ||
data[2] || data[3]);
input_report_abs(input_dev, ABS_WHEEL, data[1]);
input_report_key(input_dev, BTN_0, data[2]);
for (i = 0; i < 8; i++)
input_report_key(input_dev,
BTN_1 + i, data[3] & (1 << i));
break;
case HANWANG_ART_MASTER_HD:
input_report_key(input_dev, BTN_TOOL_FINGER, data[1] ||
data[2] || data[3] || data[4] ||
data[5] || data[6]);
input_report_abs(input_dev, ABS_RX,
((data[1] & 0x1f) << 8) | data[2]);
input_report_abs(input_dev, ABS_RY,
((data[3] & 0x1f) << 8) | data[4]);
input_report_key(input_dev, BTN_0, data[5] & 0x01);
for (i = 0; i < 4; i++) {
input_report_key(input_dev,
BTN_1 + i, data[5] & (1 << i));
input_report_key(input_dev,
BTN_5 + i, data[6] & (1 << i));
}
break;
}
input_report_abs(input_dev, ABS_MISC, hanwang->current_id);
input_event(input_dev, EV_MSC, MSC_SERIAL, 0xffffffff);
break;
default:
dev_dbg(&dev->dev, "error packet %02x ", data[0]);
break;
}
input_sync(input_dev);
}
static void hanwang_irq(struct urb *urb)
{
struct hanwang *hanwang = urb->context;
struct usb_device *dev = hanwang->usbdev;
int retval;
switch (urb->status) {
case 0:
;
hanwang_parse_packet(hanwang);
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_err(&dev->dev, "%s - urb shutting down with status: %d",
__func__, urb->status);
return;
default:
dev_err(&dev->dev, "%s - nonzero urb status received: %d",
__func__, urb->status);
break;
}
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&dev->dev, "%s - usb_submit_urb failed with result %d",
__func__, retval);
}
static int hanwang_open(struct input_dev *dev)
{
struct hanwang *hanwang = input_get_drvdata(dev);
hanwang->irq->dev = hanwang->usbdev;
if (usb_submit_urb(hanwang->irq, GFP_KERNEL))
return -EIO;
return 0;
}
static void hanwang_close(struct input_dev *dev)
{
struct hanwang *hanwang = input_get_drvdata(dev);
usb_kill_urb(hanwang->irq);
}
static bool get_features(struct usb_device *dev, struct hanwang *hanwang)
{
int i;
for (i = 0; i < ARRAY_SIZE(features_array); i++) {
if (le16_to_cpu(dev->descriptor.idProduct) ==
features_array[i].pid) {
hanwang->features = &features_array[i];
return true;
}
}
return false;
}
static int hanwang_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct usb_device *dev = interface_to_usbdev(intf);
struct usb_endpoint_descriptor *endpoint;
struct hanwang *hanwang;
struct input_dev *input_dev;
int error;
int i;
hanwang = kzalloc(sizeof(struct hanwang), GFP_KERNEL);
input_dev = input_allocate_device();
if (!hanwang || !input_dev) {
error = -ENOMEM;
goto fail1;
}
if (!get_features(dev, hanwang)) {
error = -ENXIO;
goto fail1;
}
hanwang->data = usb_alloc_coherent(dev, hanwang->features->pkg_len,
GFP_KERNEL, &hanwang->data_dma);
if (!hanwang->data) {
error = -ENOMEM;
goto fail1;
}
hanwang->irq = usb_alloc_urb(0, GFP_KERNEL);
if (!hanwang->irq) {
error = -ENOMEM;
goto fail2;
}
hanwang->usbdev = dev;
hanwang->dev = input_dev;
usb_make_path(dev, hanwang->phys, sizeof(hanwang->phys));
strlcat(hanwang->phys, "/input0", sizeof(hanwang->phys));
strlcpy(hanwang->name, hanwang->features->name, sizeof(hanwang->name));
input_dev->name = hanwang->name;
input_dev->phys = hanwang->phys;
usb_to_input_id(dev, &input_dev->id);
input_dev->dev.parent = &intf->dev;
input_set_drvdata(input_dev, hanwang);
input_dev->open = hanwang_open;
input_dev->close = hanwang_close;
for (i = 0; i < ARRAY_SIZE(hw_eventtypes); ++i)
__set_bit(hw_eventtypes[i], input_dev->evbit);
for (i = 0; i < ARRAY_SIZE(hw_absevents); ++i)
__set_bit(hw_absevents[i], input_dev->absbit);
for (i = 0; i < ARRAY_SIZE(hw_btnevents); ++i)
__set_bit(hw_btnevents[i], input_dev->keybit);
for (i = 0; i < ARRAY_SIZE(hw_mscevents); ++i)
__set_bit(hw_mscevents[i], input_dev->mscbit);
input_set_abs_params(input_dev, ABS_X,
0, hanwang->features->max_x, 4, 0);
input_set_abs_params(input_dev, ABS_Y,
0, hanwang->features->max_y, 4, 0);
input_set_abs_params(input_dev, ABS_TILT_X,
0, hanwang->features->max_tilt_x, 0, 0);
input_set_abs_params(input_dev, ABS_TILT_Y,
0, hanwang->features->max_tilt_y, 0, 0);
input_set_abs_params(input_dev, ABS_PRESSURE,
0, hanwang->features->max_pressure, 0, 0);
endpoint = &intf->cur_altsetting->endpoint[0].desc;
usb_fill_int_urb(hanwang->irq, dev,
usb_rcvintpipe(dev, endpoint->bEndpointAddress),
hanwang->data, hanwang->features->pkg_len,
hanwang_irq, hanwang, endpoint->bInterval);
hanwang->irq->transfer_dma = hanwang->data_dma;
hanwang->irq->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
error = input_register_device(hanwang->dev);
if (error)
goto fail3;
usb_set_intfdata(intf, hanwang);
return 0;
fail3: usb_free_urb(hanwang->irq);
fail2: usb_free_coherent(dev, hanwang->features->pkg_len,
hanwang->data, hanwang->data_dma);
fail1: input_free_device(input_dev);
kfree(hanwang);
return error;
}
static void hanwang_disconnect(struct usb_interface *intf)
{
struct hanwang *hanwang = usb_get_intfdata(intf);
input_unregister_device(hanwang->dev);
usb_free_urb(hanwang->irq);
usb_free_coherent(interface_to_usbdev(intf),
hanwang->features->pkg_len, hanwang->data,
hanwang->data_dma);
kfree(hanwang);
usb_set_intfdata(intf, NULL);
}
static int __init hanwang_init(void)
{
return usb_register(&hanwang_driver);
}
static void __exit hanwang_exit(void)
{
usb_deregister(&hanwang_driver);
}
