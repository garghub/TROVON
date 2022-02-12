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
static void xpad360_process_packet(struct usb_xpad *xpad, struct input_dev *dev,
u16 cmd, unsigned char *data)
{
if (data[0] != 0x00)
return;
if (xpad->mapping & MAP_DPAD_TO_BUTTONS) {
input_report_key(dev, BTN_TRIGGER_HAPPY1, data[2] & 0x04);
input_report_key(dev, BTN_TRIGGER_HAPPY2, data[2] & 0x08);
input_report_key(dev, BTN_TRIGGER_HAPPY3, data[2] & 0x01);
input_report_key(dev, BTN_TRIGGER_HAPPY4, data[2] & 0x02);
}
if (!(xpad->mapping & MAP_DPAD_TO_BUTTONS) ||
xpad->xtype == XTYPE_XBOX360W) {
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
static void xpad_presence_work(struct work_struct *work)
{
struct usb_xpad *xpad = container_of(work, struct usb_xpad, work);
int error;
if (xpad->pad_present) {
error = xpad_init_input(xpad);
if (error) {
dev_err(&xpad->dev->dev,
"unable to init device: %d\n", error);
} else {
rcu_assign_pointer(xpad->x360w_dev, xpad->dev);
}
} else {
RCU_INIT_POINTER(xpad->x360w_dev, NULL);
synchronize_rcu();
xpad_deinit_input(xpad);
}
}
static void xpad360w_process_packet(struct usb_xpad *xpad, u16 cmd, unsigned char *data)
{
struct input_dev *dev;
bool present;
if (data[0] & 0x08) {
present = (data[1] & 0x80) != 0;
if (xpad->pad_present != present) {
xpad->pad_present = present;
schedule_work(&xpad->work);
}
}
if (data[1] != 0x1)
return;
rcu_read_lock();
dev = rcu_dereference(xpad->x360w_dev);
if (dev)
xpad360_process_packet(xpad, dev, cmd, &data[4]);
rcu_read_unlock();
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
xpad360_process_packet(xpad, xpad->dev, 0, xpad->idata);
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
static bool xpad_prepare_next_out_packet(struct usb_xpad *xpad)
{
struct xpad_output_packet *pkt, *packet = NULL;
int i;
for (i = 0; i < XPAD_NUM_OUT_PACKETS; i++) {
if (++xpad->last_out_packet >= XPAD_NUM_OUT_PACKETS)
xpad->last_out_packet = 0;
pkt = &xpad->out_packets[xpad->last_out_packet];
if (pkt->pending) {
dev_dbg(&xpad->intf->dev,
"%s - found pending output packet %d\n",
__func__, xpad->last_out_packet);
packet = pkt;
break;
}
}
if (packet) {
memcpy(xpad->odata, packet->data, packet->len);
xpad->irq_out->transfer_buffer_length = packet->len;
packet->pending = false;
return true;
}
return false;
}
static int xpad_try_sending_next_out_packet(struct usb_xpad *xpad)
{
int error;
if (!xpad->irq_out_active && xpad_prepare_next_out_packet(xpad)) {
usb_anchor_urb(xpad->irq_out, &xpad->irq_out_anchor);
error = usb_submit_urb(xpad->irq_out, GFP_ATOMIC);
if (error) {
dev_err(&xpad->intf->dev,
"%s - usb_submit_urb failed with result %d\n",
__func__, error);
usb_unanchor_urb(xpad->irq_out);
return -EIO;
}
xpad->irq_out_active = true;
}
return 0;
}
static void xpad_irq_out(struct urb *urb)
{
struct usb_xpad *xpad = urb->context;
struct device *dev = &xpad->intf->dev;
int status = urb->status;
int error;
unsigned long flags;
spin_lock_irqsave(&xpad->odata_lock, flags);
switch (status) {
case 0:
xpad->irq_out_active = xpad_prepare_next_out_packet(xpad);
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(dev, "%s - urb shutting down with status: %d\n",
__func__, status);
xpad->irq_out_active = false;
break;
default:
dev_dbg(dev, "%s - nonzero urb status received: %d\n",
__func__, status);
break;
}
if (xpad->irq_out_active) {
usb_anchor_urb(urb, &xpad->irq_out_anchor);
error = usb_submit_urb(urb, GFP_ATOMIC);
if (error) {
dev_err(dev,
"%s - usb_submit_urb failed with result %d\n",
__func__, error);
usb_unanchor_urb(urb);
xpad->irq_out_active = false;
}
}
spin_unlock_irqrestore(&xpad->odata_lock, flags);
}
static int xpad_init_output(struct usb_interface *intf, struct usb_xpad *xpad)
{
struct usb_endpoint_descriptor *ep_irq_out;
int ep_irq_out_idx;
int error;
if (xpad->xtype == XTYPE_UNKNOWN)
return 0;
init_usb_anchor(&xpad->irq_out_anchor);
xpad->odata = usb_alloc_coherent(xpad->udev, XPAD_PKT_LEN,
GFP_KERNEL, &xpad->odata_dma);
if (!xpad->odata) {
error = -ENOMEM;
goto fail1;
}
spin_lock_init(&xpad->odata_lock);
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
if (xpad->xtype != XTYPE_UNKNOWN) {
if (!usb_wait_anchor_empty_timeout(&xpad->irq_out_anchor,
5000)) {
dev_warn(&xpad->intf->dev,
"timed out waiting for output URB to complete, killing\n");
usb_kill_anchored_urbs(&xpad->irq_out_anchor);
}
}
}
static void xpad_deinit_output(struct usb_xpad *xpad)
{
if (xpad->xtype != XTYPE_UNKNOWN) {
usb_free_urb(xpad->irq_out);
usb_free_coherent(xpad->udev, XPAD_PKT_LEN,
xpad->odata, xpad->odata_dma);
}
}
static int xpad_inquiry_pad_presence(struct usb_xpad *xpad)
{
struct xpad_output_packet *packet =
&xpad->out_packets[XPAD_OUT_CMD_IDX];
unsigned long flags;
int retval;
spin_lock_irqsave(&xpad->odata_lock, flags);
packet->data[0] = 0x08;
packet->data[1] = 0x00;
packet->data[2] = 0x0F;
packet->data[3] = 0xC0;
packet->data[4] = 0x00;
packet->data[5] = 0x00;
packet->data[6] = 0x00;
packet->data[7] = 0x00;
packet->data[8] = 0x00;
packet->data[9] = 0x00;
packet->data[10] = 0x00;
packet->data[11] = 0x00;
packet->len = 12;
packet->pending = true;
xpad->last_out_packet = -1;
retval = xpad_try_sending_next_out_packet(xpad);
spin_unlock_irqrestore(&xpad->odata_lock, flags);
return retval;
}
static int xpad_start_xbox_one(struct usb_xpad *xpad)
{
struct xpad_output_packet *packet =
&xpad->out_packets[XPAD_OUT_CMD_IDX];
unsigned long flags;
int retval;
spin_lock_irqsave(&xpad->odata_lock, flags);
packet->data[0] = 0x05;
packet->data[1] = 0x20;
packet->data[2] = xpad->odata_serial++;
packet->data[3] = 0x01;
packet->data[4] = 0x00;
packet->len = 5;
packet->pending = true;
xpad->last_out_packet = -1;
retval = xpad_try_sending_next_out_packet(xpad);
spin_unlock_irqrestore(&xpad->odata_lock, flags);
return retval;
}
static int xpad_play_effect(struct input_dev *dev, void *data, struct ff_effect *effect)
{
struct usb_xpad *xpad = input_get_drvdata(dev);
struct xpad_output_packet *packet = &xpad->out_packets[XPAD_OUT_FF_IDX];
__u16 strong;
__u16 weak;
int retval;
unsigned long flags;
if (effect->type != FF_RUMBLE)
return 0;
strong = effect->u.rumble.strong_magnitude;
weak = effect->u.rumble.weak_magnitude;
spin_lock_irqsave(&xpad->odata_lock, flags);
switch (xpad->xtype) {
case XTYPE_XBOX:
packet->data[0] = 0x00;
packet->data[1] = 0x06;
packet->data[2] = 0x00;
packet->data[3] = strong / 256;
packet->data[4] = 0x00;
packet->data[5] = weak / 256;
packet->len = 6;
packet->pending = true;
break;
case XTYPE_XBOX360:
packet->data[0] = 0x00;
packet->data[1] = 0x08;
packet->data[2] = 0x00;
packet->data[3] = strong / 256;
packet->data[4] = weak / 256;
packet->data[5] = 0x00;
packet->data[6] = 0x00;
packet->data[7] = 0x00;
packet->len = 8;
packet->pending = true;
break;
case XTYPE_XBOX360W:
packet->data[0] = 0x00;
packet->data[1] = 0x01;
packet->data[2] = 0x0F;
packet->data[3] = 0xC0;
packet->data[4] = 0x00;
packet->data[5] = strong / 256;
packet->data[6] = weak / 256;
packet->data[7] = 0x00;
packet->data[8] = 0x00;
packet->data[9] = 0x00;
packet->data[10] = 0x00;
packet->data[11] = 0x00;
packet->len = 12;
packet->pending = true;
break;
case XTYPE_XBOXONE:
packet->data[0] = 0x09;
packet->data[1] = 0x00;
packet->data[2] = xpad->odata_serial++;
packet->data[3] = 0x09;
packet->data[4] = 0x00;
packet->data[5] = 0x0F;
packet->data[6] = 0x00;
packet->data[7] = 0x00;
packet->data[8] = strong / 512;
packet->data[9] = weak / 512;
packet->data[10] = 0xFF;
packet->data[11] = 0x00;
packet->data[12] = 0x00;
packet->len = 13;
packet->pending = true;
break;
default:
dev_dbg(&xpad->dev->dev,
"%s - rumble command sent to unsupported xpad type: %d\n",
__func__, xpad->xtype);
retval = -EINVAL;
goto out;
}
retval = xpad_try_sending_next_out_packet(xpad);
out:
spin_unlock_irqrestore(&xpad->odata_lock, flags);
return retval;
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
struct xpad_output_packet *packet =
&xpad->out_packets[XPAD_OUT_LED_IDX];
unsigned long flags;
command %= 16;
spin_lock_irqsave(&xpad->odata_lock, flags);
switch (xpad->xtype) {
case XTYPE_XBOX360:
packet->data[0] = 0x01;
packet->data[1] = 0x03;
packet->data[2] = command;
packet->len = 3;
packet->pending = true;
break;
case XTYPE_XBOX360W:
packet->data[0] = 0x00;
packet->data[1] = 0x00;
packet->data[2] = 0x08;
packet->data[3] = 0x40 + command;
packet->data[4] = 0x00;
packet->data[5] = 0x00;
packet->data[6] = 0x00;
packet->data[7] = 0x00;
packet->data[8] = 0x00;
packet->data[9] = 0x00;
packet->data[10] = 0x00;
packet->data[11] = 0x00;
packet->len = 12;
packet->pending = true;
break;
}
xpad_try_sending_next_out_packet(xpad);
spin_unlock_irqrestore(&xpad->odata_lock, flags);
}
static void xpad_identify_controller(struct usb_xpad *xpad)
{
led_set_brightness(&xpad->led->led_cdev, (xpad->pad_nr % 4) + 2);
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
struct xpad_led *led;
struct led_classdev *led_cdev;
int error;
if (xpad->xtype != XTYPE_XBOX360 && xpad->xtype != XTYPE_XBOX360W)
return 0;
xpad->led = led = kzalloc(sizeof(struct xpad_led), GFP_KERNEL);
if (!led)
return -ENOMEM;
xpad->pad_nr = ida_simple_get(&xpad_pad_seq, 0, 0, GFP_KERNEL);
if (xpad->pad_nr < 0) {
error = xpad->pad_nr;
goto err_free_mem;
}
snprintf(led->name, sizeof(led->name), "xpad%d", xpad->pad_nr);
led->xpad = xpad;
led_cdev = &led->led_cdev;
led_cdev->name = led->name;
led_cdev->brightness_set = xpad_led_set;
error = led_classdev_register(&xpad->udev->dev, led_cdev);
if (error)
goto err_free_id;
xpad_identify_controller(xpad);
return 0;
err_free_id:
ida_simple_remove(&xpad_pad_seq, xpad->pad_nr);
err_free_mem:
kfree(led);
xpad->led = NULL;
return error;
}
static void xpad_led_disconnect(struct usb_xpad *xpad)
{
struct xpad_led *xpad_led = xpad->led;
if (xpad_led) {
led_classdev_unregister(&xpad_led->led_cdev);
ida_simple_remove(&xpad_pad_seq, xpad->pad_nr);
kfree(xpad_led);
}
}
static int xpad_led_probe(struct usb_xpad *xpad) { return 0; }
static void xpad_led_disconnect(struct usb_xpad *xpad) { }
static int xpad_start_input(struct usb_xpad *xpad)
{
int error;
if (usb_submit_urb(xpad->irq_in, GFP_KERNEL))
return -EIO;
if (xpad->xtype == XTYPE_XBOXONE) {
error = xpad_start_xbox_one(xpad);
if (error) {
usb_kill_urb(xpad->irq_in);
return error;
}
}
return 0;
}
static void xpad_stop_input(struct usb_xpad *xpad)
{
usb_kill_urb(xpad->irq_in);
}
static void xpad360w_poweroff_controller(struct usb_xpad *xpad)
{
unsigned long flags;
struct xpad_output_packet *packet =
&xpad->out_packets[XPAD_OUT_CMD_IDX];
spin_lock_irqsave(&xpad->odata_lock, flags);
packet->data[0] = 0x00;
packet->data[1] = 0x00;
packet->data[2] = 0x08;
packet->data[3] = 0xC0;
packet->data[4] = 0x00;
packet->data[5] = 0x00;
packet->data[6] = 0x00;
packet->data[7] = 0x00;
packet->data[8] = 0x00;
packet->data[9] = 0x00;
packet->data[10] = 0x00;
packet->data[11] = 0x00;
packet->len = 12;
packet->pending = true;
xpad->last_out_packet = -1;
xpad_try_sending_next_out_packet(xpad);
spin_unlock_irqrestore(&xpad->odata_lock, flags);
}
static int xpad360w_start_input(struct usb_xpad *xpad)
{
int error;
error = usb_submit_urb(xpad->irq_in, GFP_KERNEL);
if (error)
return -EIO;
error = xpad_inquiry_pad_presence(xpad);
if (error) {
usb_kill_urb(xpad->irq_in);
return error;
}
return 0;
}
static void xpad360w_stop_input(struct usb_xpad *xpad)
{
usb_kill_urb(xpad->irq_in);
flush_work(&xpad->work);
}
static int xpad_open(struct input_dev *dev)
{
struct usb_xpad *xpad = input_get_drvdata(dev);
return xpad_start_input(xpad);
}
static void xpad_close(struct input_dev *dev)
{
struct usb_xpad *xpad = input_get_drvdata(dev);
xpad_stop_input(xpad);
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
static void xpad_deinit_input(struct usb_xpad *xpad)
{
if (xpad->input_created) {
xpad->input_created = false;
xpad_led_disconnect(xpad);
input_unregister_device(xpad->dev);
}
}
static int xpad_init_input(struct usb_xpad *xpad)
{
struct input_dev *input_dev;
int i, error;
input_dev = input_allocate_device();
if (!input_dev)
return -ENOMEM;
xpad->dev = input_dev;
input_dev->name = xpad->name;
input_dev->phys = xpad->phys;
usb_to_input_id(xpad->udev, &input_dev->id);
input_dev->dev.parent = &xpad->intf->dev;
input_set_drvdata(input_dev, xpad);
if (xpad->xtype != XTYPE_XBOX360W) {
input_dev->open = xpad_open;
input_dev->close = xpad_close;
}
__set_bit(EV_KEY, input_dev->evbit);
if (!(xpad->mapping & MAP_STICKS_TO_NULL)) {
__set_bit(EV_ABS, input_dev->evbit);
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
}
if (!(xpad->mapping & MAP_DPAD_TO_BUTTONS) ||
xpad->xtype == XTYPE_XBOX360W) {
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
error = xpad_init_ff(xpad);
if (error)
goto err_free_input;
error = xpad_led_probe(xpad);
if (error)
goto err_destroy_ff;
error = input_register_device(xpad->dev);
if (error)
goto err_disconnect_led;
xpad->input_created = true;
return 0;
err_disconnect_led:
xpad_led_disconnect(xpad);
err_destroy_ff:
input_ff_destroy(input_dev);
err_free_input:
input_free_device(input_dev);
return error;
}
static int xpad_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct usb_xpad *xpad;
struct usb_endpoint_descriptor *ep_irq_in;
int ep_irq_in_idx;
int i, error;
if (intf->cur_altsetting->desc.bNumEndpoints != 2)
return -ENODEV;
for (i = 0; xpad_device[i].idVendor; i++) {
if ((le16_to_cpu(udev->descriptor.idVendor) == xpad_device[i].idVendor) &&
(le16_to_cpu(udev->descriptor.idProduct) == xpad_device[i].idProduct))
break;
}
xpad = kzalloc(sizeof(struct usb_xpad), GFP_KERNEL);
if (!xpad)
return -ENOMEM;
usb_make_path(udev, xpad->phys, sizeof(xpad->phys));
strlcat(xpad->phys, "/input0", sizeof(xpad->phys));
xpad->idata = usb_alloc_coherent(udev, XPAD_PKT_LEN,
GFP_KERNEL, &xpad->idata_dma);
if (!xpad->idata) {
error = -ENOMEM;
goto err_free_mem;
}
xpad->irq_in = usb_alloc_urb(0, GFP_KERNEL);
if (!xpad->irq_in) {
error = -ENOMEM;
goto err_free_idata;
}
xpad->udev = udev;
xpad->intf = intf;
xpad->mapping = xpad_device[i].mapping;
xpad->xtype = xpad_device[i].xtype;
xpad->name = xpad_device[i].name;
INIT_WORK(&xpad->work, xpad_presence_work);
if (xpad->xtype == XTYPE_UNKNOWN) {
if (intf->cur_altsetting->desc.bInterfaceClass == USB_CLASS_VENDOR_SPEC) {
if (intf->cur_altsetting->desc.bInterfaceProtocol == 129)
xpad->xtype = XTYPE_XBOX360W;
else if (intf->cur_altsetting->desc.bInterfaceProtocol == 208)
xpad->xtype = XTYPE_XBOXONE;
else
xpad->xtype = XTYPE_XBOX360;
} else {
xpad->xtype = XTYPE_XBOX;
}
if (dpad_to_buttons)
xpad->mapping |= MAP_DPAD_TO_BUTTONS;
if (triggers_to_buttons)
xpad->mapping |= MAP_TRIGGERS_TO_BUTTONS;
if (sticks_to_null)
xpad->mapping |= MAP_STICKS_TO_NULL;
}
if (xpad->xtype == XTYPE_XBOXONE &&
intf->cur_altsetting->desc.bInterfaceNumber != 0) {
error = -ENODEV;
goto err_free_in_urb;
}
error = xpad_init_output(intf, xpad);
if (error)
goto err_free_in_urb;
ep_irq_in_idx = xpad->xtype == XTYPE_XBOXONE ? 1 : 0;
ep_irq_in = &intf->cur_altsetting->endpoint[ep_irq_in_idx].desc;
usb_fill_int_urb(xpad->irq_in, udev,
usb_rcvintpipe(udev, ep_irq_in->bEndpointAddress),
xpad->idata, XPAD_PKT_LEN, xpad_irq_in,
xpad, ep_irq_in->bInterval);
xpad->irq_in->transfer_dma = xpad->idata_dma;
xpad->irq_in->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_set_intfdata(intf, xpad);
if (xpad->xtype == XTYPE_XBOX360W) {
error = xpad360w_start_input(xpad);
if (error)
goto err_deinit_output;
udev->quirks |= USB_QUIRK_RESET_RESUME;
} else {
error = xpad_init_input(xpad);
if (error)
goto err_deinit_output;
}
return 0;
err_deinit_output:
xpad_deinit_output(xpad);
err_free_in_urb:
usb_free_urb(xpad->irq_in);
err_free_idata:
usb_free_coherent(udev, XPAD_PKT_LEN, xpad->idata, xpad->idata_dma);
err_free_mem:
kfree(xpad);
return error;
}
static void xpad_disconnect(struct usb_interface *intf)
{
struct usb_xpad *xpad = usb_get_intfdata(intf);
if (xpad->xtype == XTYPE_XBOX360W)
xpad360w_stop_input(xpad);
xpad_deinit_input(xpad);
xpad_stop_output(xpad);
xpad_deinit_output(xpad);
usb_free_urb(xpad->irq_in);
usb_free_coherent(xpad->udev, XPAD_PKT_LEN,
xpad->idata, xpad->idata_dma);
kfree(xpad);
usb_set_intfdata(intf, NULL);
}
static int xpad_suspend(struct usb_interface *intf, pm_message_t message)
{
struct usb_xpad *xpad = usb_get_intfdata(intf);
struct input_dev *input = xpad->dev;
if (xpad->xtype == XTYPE_XBOX360W) {
xpad360w_stop_input(xpad);
if (auto_poweroff && xpad->pad_present)
xpad360w_poweroff_controller(xpad);
} else {
mutex_lock(&input->mutex);
if (input->users)
xpad_stop_input(xpad);
mutex_unlock(&input->mutex);
}
xpad_stop_output(xpad);
return 0;
}
static int xpad_resume(struct usb_interface *intf)
{
struct usb_xpad *xpad = usb_get_intfdata(intf);
struct input_dev *input = xpad->dev;
int retval = 0;
if (xpad->xtype == XTYPE_XBOX360W) {
retval = xpad360w_start_input(xpad);
} else {
mutex_lock(&input->mutex);
if (input->users)
retval = xpad_start_input(xpad);
mutex_unlock(&input->mutex);
}
return retval;
}
