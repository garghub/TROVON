static const struct bcm5974_config *bcm5974_get_config(struct usb_device *udev)
{
u16 id = le16_to_cpu(udev->descriptor.idProduct);
const struct bcm5974_config *cfg;
for (cfg = bcm5974_config_table; cfg->ansi; ++cfg)
if (cfg->ansi == id || cfg->iso == id || cfg->jis == id)
return cfg;
return bcm5974_config_table;
}
static inline int raw2int(__le16 x)
{
return (signed short)le16_to_cpu(x);
}
static void set_abs(struct input_dev *input, unsigned int code,
const struct bcm5974_param *p)
{
int fuzz = p->snratio ? (p->max - p->min) / p->snratio : 0;
input_set_abs_params(input, code, p->min, p->max, fuzz, 0);
}
static void setup_events_to_report(struct input_dev *input_dev,
const struct bcm5974_config *cfg)
{
__set_bit(EV_ABS, input_dev->evbit);
input_set_abs_params(input_dev, ABS_PRESSURE, 0, 256, 5, 0);
input_set_abs_params(input_dev, ABS_TOOL_WIDTH, 0, 16, 0, 0);
set_abs(input_dev, ABS_MT_TOUCH_MAJOR, &cfg->w);
set_abs(input_dev, ABS_MT_TOUCH_MINOR, &cfg->w);
set_abs(input_dev, ABS_MT_WIDTH_MAJOR, &cfg->w);
set_abs(input_dev, ABS_MT_WIDTH_MINOR, &cfg->w);
set_abs(input_dev, ABS_MT_ORIENTATION, &cfg->o);
set_abs(input_dev, ABS_MT_POSITION_X, &cfg->x);
set_abs(input_dev, ABS_MT_POSITION_Y, &cfg->y);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_LEFT, input_dev->keybit);
if (cfg->caps & HAS_INTEGRATED_BUTTON)
__set_bit(INPUT_PROP_BUTTONPAD, input_dev->propbit);
input_mt_init_slots(input_dev, MAX_FINGERS,
INPUT_MT_POINTER | INPUT_MT_DROP_UNUSED | INPUT_MT_TRACK);
}
static int report_bt_state(struct bcm5974 *dev, int size)
{
if (size != sizeof(struct bt_data))
return -EIO;
dprintk(7,
"bcm5974: button data: %x %x %x %x\n",
dev->bt_data->unknown1, dev->bt_data->button,
dev->bt_data->rel_x, dev->bt_data->rel_y);
input_report_key(dev->input, BTN_LEFT, dev->bt_data->button);
input_sync(dev->input);
return 0;
}
static void report_finger_data(struct input_dev *input, int slot,
const struct input_mt_pos *pos,
const struct tp_finger *f)
{
input_mt_slot(input, slot);
input_mt_report_slot_state(input, MT_TOOL_FINGER, true);
input_report_abs(input, ABS_MT_TOUCH_MAJOR,
raw2int(f->touch_major) << 1);
input_report_abs(input, ABS_MT_TOUCH_MINOR,
raw2int(f->touch_minor) << 1);
input_report_abs(input, ABS_MT_WIDTH_MAJOR,
raw2int(f->tool_major) << 1);
input_report_abs(input, ABS_MT_WIDTH_MINOR,
raw2int(f->tool_minor) << 1);
input_report_abs(input, ABS_MT_ORIENTATION,
MAX_FINGER_ORIENTATION - raw2int(f->orientation));
input_report_abs(input, ABS_MT_POSITION_X, pos->x);
input_report_abs(input, ABS_MT_POSITION_Y, pos->y);
}
static void report_synaptics_data(struct input_dev *input,
const struct bcm5974_config *cfg,
const struct tp_finger *f, int raw_n)
{
int abs_p = 0, abs_w = 0;
if (raw_n) {
int p = raw2int(f->touch_major);
int w = raw2int(f->tool_major);
if (p > 0 && raw2int(f->origin)) {
abs_p = clamp_val(256 * p / cfg->p.max, 0, 255);
abs_w = clamp_val(16 * w / cfg->w.max, 0, 15);
}
}
input_report_abs(input, ABS_PRESSURE, abs_p);
input_report_abs(input, ABS_TOOL_WIDTH, abs_w);
}
static int report_tp_state(struct bcm5974 *dev, int size)
{
const struct bcm5974_config *c = &dev->cfg;
const struct tp_finger *f;
struct input_dev *input = dev->input;
int raw_n, i, n = 0;
if (size < c->tp_offset || (size - c->tp_offset) % SIZEOF_FINGER != 0)
return -EIO;
f = (const struct tp_finger *)(dev->tp_data + c->tp_offset);
raw_n = (size - c->tp_offset) / SIZEOF_FINGER;
for (i = 0; i < raw_n; i++) {
if (raw2int(f[i].touch_major) == 0)
continue;
dev->pos[n].x = raw2int(f[i].abs_x);
dev->pos[n].y = c->y.min + c->y.max - raw2int(f[i].abs_y);
dev->index[n++] = &f[i];
}
input_mt_assign_slots(input, dev->slots, dev->pos, n);
for (i = 0; i < n; i++)
report_finger_data(input, dev->slots[i],
&dev->pos[i], dev->index[i]);
input_mt_sync_frame(input);
report_synaptics_data(input, c, f, raw_n);
if (c->tp_type == TYPE2) {
int ibt = raw2int(dev->tp_data[BUTTON_TYPE2]);
input_report_key(input, BTN_LEFT, ibt);
}
input_sync(input);
return 0;
}
static int bcm5974_wellspring_mode(struct bcm5974 *dev, bool on)
{
char *data = kmalloc(8, GFP_KERNEL);
int retval = 0, size;
if (!data) {
dev_err(&dev->intf->dev, "out of memory\n");
retval = -ENOMEM;
goto out;
}
size = usb_control_msg(dev->udev, usb_rcvctrlpipe(dev->udev, 0),
BCM5974_WELLSPRING_MODE_READ_REQUEST_ID,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
BCM5974_WELLSPRING_MODE_REQUEST_VALUE,
BCM5974_WELLSPRING_MODE_REQUEST_INDEX, data, 8, 5000);
if (size != 8) {
dev_err(&dev->intf->dev, "could not read from device\n");
retval = -EIO;
goto out;
}
data[0] = on ?
BCM5974_WELLSPRING_MODE_VENDOR_VALUE :
BCM5974_WELLSPRING_MODE_NORMAL_VALUE;
size = usb_control_msg(dev->udev, usb_sndctrlpipe(dev->udev, 0),
BCM5974_WELLSPRING_MODE_WRITE_REQUEST_ID,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
BCM5974_WELLSPRING_MODE_REQUEST_VALUE,
BCM5974_WELLSPRING_MODE_REQUEST_INDEX, data, 8, 5000);
if (size != 8) {
dev_err(&dev->intf->dev, "could not write to device\n");
retval = -EIO;
goto out;
}
dprintk(2, "bcm5974: switched to %s mode.\n",
on ? "wellspring" : "normal");
out:
kfree(data);
return retval;
}
static void bcm5974_irq_button(struct urb *urb)
{
struct bcm5974 *dev = urb->context;
struct usb_interface *intf = dev->intf;
int error;
switch (urb->status) {
case 0:
break;
case -EOVERFLOW:
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(&intf->dev, "button urb shutting down: %d\n",
urb->status);
return;
default:
dev_dbg(&intf->dev, "button urb status: %d\n", urb->status);
goto exit;
}
if (report_bt_state(dev, dev->bt_urb->actual_length))
dprintk(1, "bcm5974: bad button package, length: %d\n",
dev->bt_urb->actual_length);
exit:
error = usb_submit_urb(dev->bt_urb, GFP_ATOMIC);
if (error)
dev_err(&intf->dev, "button urb failed: %d\n", error);
}
static void bcm5974_irq_trackpad(struct urb *urb)
{
struct bcm5974 *dev = urb->context;
struct usb_interface *intf = dev->intf;
int error;
switch (urb->status) {
case 0:
break;
case -EOVERFLOW:
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(&intf->dev, "trackpad urb shutting down: %d\n",
urb->status);
return;
default:
dev_dbg(&intf->dev, "trackpad urb status: %d\n", urb->status);
goto exit;
}
if (dev->tp_urb->actual_length == 2)
goto exit;
if (report_tp_state(dev, dev->tp_urb->actual_length))
dprintk(1, "bcm5974: bad trackpad package, length: %d\n",
dev->tp_urb->actual_length);
exit:
error = usb_submit_urb(dev->tp_urb, GFP_ATOMIC);
if (error)
dev_err(&intf->dev, "trackpad urb failed: %d\n", error);
}
static int bcm5974_start_traffic(struct bcm5974 *dev)
{
int error;
error = bcm5974_wellspring_mode(dev, true);
if (error) {
dprintk(1, "bcm5974: mode switch failed\n");
goto err_out;
}
if (dev->bt_urb) {
error = usb_submit_urb(dev->bt_urb, GFP_KERNEL);
if (error)
goto err_reset_mode;
}
error = usb_submit_urb(dev->tp_urb, GFP_KERNEL);
if (error)
goto err_kill_bt;
return 0;
err_kill_bt:
usb_kill_urb(dev->bt_urb);
err_reset_mode:
bcm5974_wellspring_mode(dev, false);
err_out:
return error;
}
static void bcm5974_pause_traffic(struct bcm5974 *dev)
{
usb_kill_urb(dev->tp_urb);
usb_kill_urb(dev->bt_urb);
bcm5974_wellspring_mode(dev, false);
}
static int bcm5974_open(struct input_dev *input)
{
struct bcm5974 *dev = input_get_drvdata(input);
int error;
error = usb_autopm_get_interface(dev->intf);
if (error)
return error;
mutex_lock(&dev->pm_mutex);
error = bcm5974_start_traffic(dev);
if (!error)
dev->opened = 1;
mutex_unlock(&dev->pm_mutex);
if (error)
usb_autopm_put_interface(dev->intf);
return error;
}
static void bcm5974_close(struct input_dev *input)
{
struct bcm5974 *dev = input_get_drvdata(input);
mutex_lock(&dev->pm_mutex);
bcm5974_pause_traffic(dev);
dev->opened = 0;
mutex_unlock(&dev->pm_mutex);
usb_autopm_put_interface(dev->intf);
}
static int bcm5974_suspend(struct usb_interface *iface, pm_message_t message)
{
struct bcm5974 *dev = usb_get_intfdata(iface);
mutex_lock(&dev->pm_mutex);
if (dev->opened)
bcm5974_pause_traffic(dev);
mutex_unlock(&dev->pm_mutex);
return 0;
}
static int bcm5974_resume(struct usb_interface *iface)
{
struct bcm5974 *dev = usb_get_intfdata(iface);
int error = 0;
mutex_lock(&dev->pm_mutex);
if (dev->opened)
error = bcm5974_start_traffic(dev);
mutex_unlock(&dev->pm_mutex);
return error;
}
static int bcm5974_probe(struct usb_interface *iface,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(iface);
const struct bcm5974_config *cfg;
struct bcm5974 *dev;
struct input_dev *input_dev;
int error = -ENOMEM;
cfg = bcm5974_get_config(udev);
dev = kzalloc(sizeof(struct bcm5974), GFP_KERNEL);
input_dev = input_allocate_device();
if (!dev || !input_dev) {
dev_err(&iface->dev, "out of memory\n");
goto err_free_devs;
}
dev->udev = udev;
dev->intf = iface;
dev->input = input_dev;
dev->cfg = *cfg;
mutex_init(&dev->pm_mutex);
if (cfg->tp_type == TYPE1) {
dev->bt_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->bt_urb)
goto err_free_devs;
}
dev->tp_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->tp_urb)
goto err_free_bt_urb;
if (dev->bt_urb) {
dev->bt_data = usb_alloc_coherent(dev->udev,
dev->cfg.bt_datalen, GFP_KERNEL,
&dev->bt_urb->transfer_dma);
if (!dev->bt_data)
goto err_free_urb;
}
dev->tp_data = usb_alloc_coherent(dev->udev,
dev->cfg.tp_datalen, GFP_KERNEL,
&dev->tp_urb->transfer_dma);
if (!dev->tp_data)
goto err_free_bt_buffer;
if (dev->bt_urb)
usb_fill_int_urb(dev->bt_urb, udev,
usb_rcvintpipe(udev, cfg->bt_ep),
dev->bt_data, dev->cfg.bt_datalen,
bcm5974_irq_button, dev, 1);
usb_fill_int_urb(dev->tp_urb, udev,
usb_rcvintpipe(udev, cfg->tp_ep),
dev->tp_data, dev->cfg.tp_datalen,
bcm5974_irq_trackpad, dev, 1);
usb_make_path(udev, dev->phys, sizeof(dev->phys));
strlcat(dev->phys, "/input0", sizeof(dev->phys));
input_dev->name = "bcm5974";
input_dev->phys = dev->phys;
usb_to_input_id(dev->udev, &input_dev->id);
input_dev->id.version = cfg->caps;
input_dev->dev.parent = &iface->dev;
input_set_drvdata(input_dev, dev);
input_dev->open = bcm5974_open;
input_dev->close = bcm5974_close;
setup_events_to_report(input_dev, cfg);
error = input_register_device(dev->input);
if (error)
goto err_free_buffer;
usb_set_intfdata(iface, dev);
return 0;
err_free_buffer:
usb_free_coherent(dev->udev, dev->cfg.tp_datalen,
dev->tp_data, dev->tp_urb->transfer_dma);
err_free_bt_buffer:
if (dev->bt_urb)
usb_free_coherent(dev->udev, dev->cfg.bt_datalen,
dev->bt_data, dev->bt_urb->transfer_dma);
err_free_urb:
usb_free_urb(dev->tp_urb);
err_free_bt_urb:
usb_free_urb(dev->bt_urb);
err_free_devs:
usb_set_intfdata(iface, NULL);
input_free_device(input_dev);
kfree(dev);
return error;
}
static void bcm5974_disconnect(struct usb_interface *iface)
{
struct bcm5974 *dev = usb_get_intfdata(iface);
usb_set_intfdata(iface, NULL);
input_unregister_device(dev->input);
usb_free_coherent(dev->udev, dev->cfg.tp_datalen,
dev->tp_data, dev->tp_urb->transfer_dma);
if (dev->bt_urb)
usb_free_coherent(dev->udev, dev->cfg.bt_datalen,
dev->bt_data, dev->bt_urb->transfer_dma);
usb_free_urb(dev->tp_urb);
usb_free_urb(dev->bt_urb);
kfree(dev);
}
