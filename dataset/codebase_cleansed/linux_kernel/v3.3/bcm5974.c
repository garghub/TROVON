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
static inline int int2scale(const struct bcm5974_param *p, int x)
{
return x * p->dim / (p->devmax - p->devmin);
}
static inline int int2bound(const struct bcm5974_param *p, int x)
{
int s = int2scale(p, x);
return clamp_val(s, 0, p->dim - 1);
}
static void setup_events_to_report(struct input_dev *input_dev,
const struct bcm5974_config *cfg)
{
__set_bit(EV_ABS, input_dev->evbit);
input_set_abs_params(input_dev, ABS_PRESSURE,
0, cfg->p.dim, cfg->p.fuzz, 0);
input_set_abs_params(input_dev, ABS_TOOL_WIDTH,
0, cfg->w.dim, cfg->w.fuzz, 0);
input_set_abs_params(input_dev, ABS_X,
0, cfg->x.dim, cfg->x.fuzz, 0);
input_set_abs_params(input_dev, ABS_Y,
0, cfg->y.dim, cfg->y.fuzz, 0);
input_set_abs_params(input_dev, ABS_MT_TOUCH_MAJOR,
cfg->w.devmin, cfg->w.devmax, 0, 0);
input_set_abs_params(input_dev, ABS_MT_TOUCH_MINOR,
cfg->w.devmin, cfg->w.devmax, 0, 0);
input_set_abs_params(input_dev, ABS_MT_WIDTH_MAJOR,
cfg->w.devmin, cfg->w.devmax, 0, 0);
input_set_abs_params(input_dev, ABS_MT_WIDTH_MINOR,
cfg->w.devmin, cfg->w.devmax, 0, 0);
input_set_abs_params(input_dev, ABS_MT_ORIENTATION,
-MAX_FINGER_ORIENTATION,
MAX_FINGER_ORIENTATION, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_X,
cfg->x.devmin, cfg->x.devmax, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y,
cfg->y.devmin, cfg->y.devmax, 0, 0);
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_TOUCH, input_dev->keybit);
__set_bit(BTN_TOOL_FINGER, input_dev->keybit);
__set_bit(BTN_TOOL_DOUBLETAP, input_dev->keybit);
__set_bit(BTN_TOOL_TRIPLETAP, input_dev->keybit);
__set_bit(BTN_TOOL_QUADTAP, input_dev->keybit);
__set_bit(BTN_LEFT, input_dev->keybit);
if (cfg->caps & HAS_INTEGRATED_BUTTON)
__set_bit(INPUT_PROP_BUTTONPAD, input_dev->propbit);
input_set_events_per_packet(input_dev, 60);
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
static void report_finger_data(struct input_dev *input,
const struct bcm5974_config *cfg,
const struct tp_finger *f)
{
input_report_abs(input, ABS_MT_TOUCH_MAJOR,
raw2int(f->force_major) << 1);
input_report_abs(input, ABS_MT_TOUCH_MINOR,
raw2int(f->force_minor) << 1);
input_report_abs(input, ABS_MT_WIDTH_MAJOR,
raw2int(f->size_major) << 1);
input_report_abs(input, ABS_MT_WIDTH_MINOR,
raw2int(f->size_minor) << 1);
input_report_abs(input, ABS_MT_ORIENTATION,
MAX_FINGER_ORIENTATION - raw2int(f->orientation));
input_report_abs(input, ABS_MT_POSITION_X, raw2int(f->abs_x));
input_report_abs(input, ABS_MT_POSITION_Y,
cfg->y.devmin + cfg->y.devmax - raw2int(f->abs_y));
input_mt_sync(input);
}
static int report_tp_state(struct bcm5974 *dev, int size)
{
const struct bcm5974_config *c = &dev->cfg;
const struct tp_finger *f;
struct input_dev *input = dev->input;
int raw_p, raw_w, raw_x, raw_y, raw_n, i;
int ptest, origin, ibt = 0, nmin = 0, nmax = 0;
int abs_p = 0, abs_w = 0, abs_x = 0, abs_y = 0;
if (size < c->tp_offset || (size - c->tp_offset) % SIZEOF_FINGER != 0)
return -EIO;
f = (const struct tp_finger *)(dev->tp_data + c->tp_offset);
raw_n = (size - c->tp_offset) / SIZEOF_FINGER;
if (raw_n) {
for (i = 0; i < raw_n; i++)
report_finger_data(input, c, &f[i]);
raw_p = raw2int(f->force_major);
raw_w = raw2int(f->size_major);
raw_x = raw2int(f->abs_x);
raw_y = raw2int(f->abs_y);
dprintk(9,
"bcm5974: "
"raw: p: %+05d w: %+05d x: %+05d y: %+05d n: %d\n",
raw_p, raw_w, raw_x, raw_y, raw_n);
ptest = int2bound(&c->p, raw_p);
origin = raw2int(f->origin);
if (ptest > PRESSURE_LOW && origin) {
abs_p = ptest;
abs_w = int2bound(&c->w, raw_w);
abs_x = int2bound(&c->x, raw_x - c->x.devmin);
abs_y = int2bound(&c->y, c->y.devmax - raw_y);
while (raw_n--) {
ptest = int2bound(&c->p,
raw2int(f->force_major));
if (ptest > PRESSURE_LOW)
nmax++;
if (ptest > PRESSURE_HIGH)
nmin++;
f++;
}
}
}
if (c->tp_type == TYPE2)
ibt = raw2int(dev->tp_data[BUTTON_TYPE2]);
if (dev->fingers < nmin)
dev->fingers = nmin;
if (dev->fingers > nmax)
dev->fingers = nmax;
input_report_key(input, BTN_TOUCH, dev->fingers > 0);
input_report_key(input, BTN_TOOL_FINGER, dev->fingers == 1);
input_report_key(input, BTN_TOOL_DOUBLETAP, dev->fingers == 2);
input_report_key(input, BTN_TOOL_TRIPLETAP, dev->fingers == 3);
input_report_key(input, BTN_TOOL_QUADTAP, dev->fingers > 3);
input_report_abs(input, ABS_PRESSURE, abs_p);
input_report_abs(input, ABS_TOOL_WIDTH, abs_w);
if (abs_p) {
input_report_abs(input, ABS_X, abs_x);
input_report_abs(input, ABS_Y, abs_y);
dprintk(8,
"bcm5974: abs: p: %+05d w: %+05d x: %+05d y: %+05d "
"nmin: %d nmax: %d n: %d ibt: %d\n", abs_p, abs_w,
abs_x, abs_y, nmin, nmax, dev->fingers, ibt);
}
if (c->tp_type == TYPE2)
input_report_key(input, BTN_LEFT, ibt);
input_sync(input);
return 0;
}
static int bcm5974_wellspring_mode(struct bcm5974 *dev, bool on)
{
char *data = kmalloc(8, GFP_KERNEL);
int retval = 0, size;
if (!data) {
err("bcm5974: out of memory");
retval = -ENOMEM;
goto out;
}
size = usb_control_msg(dev->udev, usb_rcvctrlpipe(dev->udev, 0),
BCM5974_WELLSPRING_MODE_READ_REQUEST_ID,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
BCM5974_WELLSPRING_MODE_REQUEST_VALUE,
BCM5974_WELLSPRING_MODE_REQUEST_INDEX, data, 8, 5000);
if (size != 8) {
err("bcm5974: could not read from device");
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
err("bcm5974: could not write to device");
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
int error;
switch (urb->status) {
case 0:
break;
case -EOVERFLOW:
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dbg("bcm5974: button urb shutting down: %d", urb->status);
return;
default:
dbg("bcm5974: button urb status: %d", urb->status);
goto exit;
}
if (report_bt_state(dev, dev->bt_urb->actual_length))
dprintk(1, "bcm5974: bad button package, length: %d\n",
dev->bt_urb->actual_length);
exit:
error = usb_submit_urb(dev->bt_urb, GFP_ATOMIC);
if (error)
err("bcm5974: button urb failed: %d", error);
}
static void bcm5974_irq_trackpad(struct urb *urb)
{
struct bcm5974 *dev = urb->context;
int error;
switch (urb->status) {
case 0:
break;
case -EOVERFLOW:
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dbg("bcm5974: trackpad urb shutting down: %d", urb->status);
return;
default:
dbg("bcm5974: trackpad urb status: %d", urb->status);
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
err("bcm5974: trackpad urb failed: %d", error);
}
static int bcm5974_start_traffic(struct bcm5974 *dev)
{
int error;
error = bcm5974_wellspring_mode(dev, true);
if (error) {
dprintk(1, "bcm5974: mode switch failed\n");
goto err_out;
}
error = usb_submit_urb(dev->bt_urb, GFP_KERNEL);
if (error)
goto err_reset_mode;
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
err("bcm5974: out of memory");
goto err_free_devs;
}
dev->udev = udev;
dev->intf = iface;
dev->input = input_dev;
dev->cfg = *cfg;
mutex_init(&dev->pm_mutex);
dev->bt_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->bt_urb)
goto err_free_devs;
dev->tp_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->tp_urb)
goto err_free_bt_urb;
dev->bt_data = usb_alloc_coherent(dev->udev,
dev->cfg.bt_datalen, GFP_KERNEL,
&dev->bt_urb->transfer_dma);
if (!dev->bt_data)
goto err_free_urb;
dev->tp_data = usb_alloc_coherent(dev->udev,
dev->cfg.tp_datalen, GFP_KERNEL,
&dev->tp_urb->transfer_dma);
if (!dev->tp_data)
goto err_free_bt_buffer;
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
usb_free_coherent(dev->udev, dev->cfg.bt_datalen,
dev->bt_data, dev->bt_urb->transfer_dma);
usb_free_urb(dev->tp_urb);
usb_free_urb(dev->bt_urb);
kfree(dev);
}
