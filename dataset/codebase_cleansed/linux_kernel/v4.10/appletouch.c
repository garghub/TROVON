static int atp_geyser_init(struct atp *dev)
{
struct usb_device *udev = dev->udev;
char *data;
int size;
int i;
int ret;
data = kmalloc(8, GFP_KERNEL);
if (!data) {
dev_err(&dev->intf->dev, "Out of memory\n");
return -ENOMEM;
}
size = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
ATP_GEYSER_MODE_READ_REQUEST_ID,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
ATP_GEYSER_MODE_REQUEST_VALUE,
ATP_GEYSER_MODE_REQUEST_INDEX, data, 8, 5000);
if (size != 8) {
dprintk("atp_geyser_init: read error\n");
for (i = 0; i < 8; i++)
dprintk("appletouch[%d]: %d\n", i, data[i]);
dev_err(&dev->intf->dev, "Failed to read mode from device.\n");
ret = -EIO;
goto out_free;
}
data[0] = ATP_GEYSER_MODE_VENDOR_VALUE;
size = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
ATP_GEYSER_MODE_WRITE_REQUEST_ID,
USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
ATP_GEYSER_MODE_REQUEST_VALUE,
ATP_GEYSER_MODE_REQUEST_INDEX, data, 8, 5000);
if (size != 8) {
dprintk("atp_geyser_init: write error\n");
for (i = 0; i < 8; i++)
dprintk("appletouch[%d]: %d\n", i, data[i]);
dev_err(&dev->intf->dev, "Failed to request geyser raw mode\n");
ret = -EIO;
goto out_free;
}
ret = 0;
out_free:
kfree(data);
return ret;
}
static void atp_reinit(struct work_struct *work)
{
struct atp *dev = container_of(work, struct atp, work);
int retval;
dprintk("appletouch: putting appletouch to sleep (reinit)\n");
atp_geyser_init(dev);
retval = usb_submit_urb(dev->urb, GFP_ATOMIC);
if (retval)
dev_err(&dev->intf->dev,
"atp_reinit: usb_submit_urb failed with error %d\n",
retval);
}
static int atp_calculate_abs(struct atp *dev, int offset, int nb_sensors,
int fact, int *z, int *fingers)
{
int i, pass;
int *xy_sensors = dev->xy_acc + offset;
int pcum = 0, psum = 0;
int is_increasing = 0;
*fingers = 0;
for (i = 0; i < nb_sensors; i++) {
if (xy_sensors[i] < threshold) {
if (is_increasing)
is_increasing = 0;
} else if (i < 1 ||
(!is_increasing && xy_sensors[i - 1] < xy_sensors[i])) {
(*fingers)++;
is_increasing = 1;
} else if (i > 0 && (xy_sensors[i - 1] - xy_sensors[i] > threshold)) {
is_increasing = 0;
}
}
if (*fingers < 1)
return 0;
memset(dev->smooth, 0, 4 * sizeof(dev->smooth[0]));
for (i = 0; i < nb_sensors; i++)
dev->smooth[i + 4] = xy_sensors[i] << ATP_SCALE;
memset(&dev->smooth[nb_sensors + 4], 0, 4 * sizeof(dev->smooth[0]));
for (pass = 0; pass < 4; pass++) {
dev->smooth_tmp[0] = (dev->smooth[0] + dev->smooth[1]) / 2;
for (i = 1; i < nb_sensors + 7; i++)
dev->smooth_tmp[i] = (dev->smooth[i - 1] +
dev->smooth[i] * 2 +
dev->smooth[i + 1]) / 4;
dev->smooth_tmp[i] = (dev->smooth[i - 1] + dev->smooth[i]) / 2;
memcpy(dev->smooth, dev->smooth_tmp, sizeof(dev->smooth));
}
for (i = 0; i < nb_sensors + 8; i++) {
if ((dev->smooth[i] >> ATP_SCALE) > 0) {
pcum += dev->smooth[i] * i;
psum += dev->smooth[i];
}
}
if (psum > 0) {
*z = psum >> ATP_SCALE;
return pcum * fact / psum;
}
return 0;
}
static inline void atp_report_fingers(struct input_dev *input, int fingers)
{
input_report_key(input, BTN_TOOL_FINGER, fingers == 1);
input_report_key(input, BTN_TOOL_DOUBLETAP, fingers == 2);
input_report_key(input, BTN_TOOL_TRIPLETAP, fingers > 2);
}
static int atp_status_check(struct urb *urb)
{
struct atp *dev = urb->context;
struct usb_interface *intf = dev->intf;
switch (urb->status) {
case 0:
break;
case -EOVERFLOW:
if (!dev->overflow_warned) {
dev_warn(&intf->dev,
"appletouch: OVERFLOW with data length %d, actual length is %d\n",
dev->info->datalen, dev->urb->actual_length);
dev->overflow_warned = true;
}
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(&intf->dev,
"atp_complete: urb shutting down with status: %d\n",
urb->status);
return ATP_URB_STATUS_ERROR_FATAL;
default:
dev_dbg(&intf->dev,
"atp_complete: nonzero urb status received: %d\n",
urb->status);
return ATP_URB_STATUS_ERROR;
}
if (dev->urb->actual_length != dev->info->datalen) {
dprintk("appletouch: incomplete data package"
" (first byte: %d, length: %d).\n",
dev->data[0], dev->urb->actual_length);
return ATP_URB_STATUS_ERROR;
}
return ATP_URB_STATUS_SUCCESS;
}
static void atp_detect_size(struct atp *dev)
{
int i;
for (i = dev->info->xsensors; i < ATP_XSENSORS; i++) {
if (dev->xy_cur[i]) {
dev_info(&dev->intf->dev,
"appletouch: 17\" model detected.\n");
input_set_abs_params(dev->input, ABS_X, 0,
(dev->info->xsensors_17 - 1) *
dev->info->xfact - 1,
dev->info->fuzz, 0);
break;
}
}
}
static void atp_complete_geyser_1_2(struct urb *urb)
{
int x, y, x_z, y_z, x_f, y_f;
int retval, i, j;
int key, fingers;
struct atp *dev = urb->context;
int status = atp_status_check(urb);
if (status == ATP_URB_STATUS_ERROR_FATAL)
return;
else if (status == ATP_URB_STATUS_ERROR)
goto exit;
if (dev->info == &geyser2_info) {
memset(dev->xy_cur, 0, sizeof(dev->xy_cur));
for (i = 0, j = 19; i < 20; i += 2, j += 3) {
dev->xy_cur[i] = dev->data[j];
dev->xy_cur[i + 1] = dev->data[j + 1];
}
for (i = 0, j = 1; i < 9; i += 2, j += 3) {
dev->xy_cur[ATP_XSENSORS + i] = dev->data[j];
dev->xy_cur[ATP_XSENSORS + i + 1] = dev->data[j + 1];
}
} else {
for (i = 0; i < 8; i++) {
dev->xy_cur[i + 0] = dev->data[5 * i + 2];
dev->xy_cur[i + 8] = dev->data[5 * i + 4];
dev->xy_cur[i + 16] = dev->data[5 * i + 42];
if (i < 2)
dev->xy_cur[i + 24] = dev->data[5 * i + 44];
dev->xy_cur[ATP_XSENSORS + i] = dev->data[5 * i + 1];
dev->xy_cur[ATP_XSENSORS + i + 8] = dev->data[5 * i + 3];
}
}
dbg_dump("sample", dev->xy_cur);
if (!dev->valid) {
dev->valid = true;
dev->x_old = dev->y_old = -1;
memcpy(dev->xy_old, dev->xy_cur, sizeof(dev->xy_old));
if (unlikely(!dev->size_detect_done)) {
atp_detect_size(dev);
dev->size_detect_done = 1;
goto exit;
}
}
for (i = 0; i < ATP_XSENSORS + ATP_YSENSORS; i++) {
signed char change = dev->xy_old[i] - dev->xy_cur[i];
dev->xy_acc[i] -= change;
if (dev->xy_acc[i] < 0)
dev->xy_acc[i] = 0;
}
memcpy(dev->xy_old, dev->xy_cur, sizeof(dev->xy_old));
dbg_dump("accumulator", dev->xy_acc);
x = atp_calculate_abs(dev, 0, ATP_XSENSORS,
dev->info->xfact, &x_z, &x_f);
y = atp_calculate_abs(dev, ATP_XSENSORS, ATP_YSENSORS,
dev->info->yfact, &y_z, &y_f);
key = dev->data[dev->info->datalen - 1] & ATP_STATUS_BUTTON;
fingers = max(x_f, y_f);
if (x && y && fingers == dev->fingers_old) {
if (dev->x_old != -1) {
x = (dev->x_old * 7 + x) >> 3;
y = (dev->y_old * 7 + y) >> 3;
dev->x_old = x;
dev->y_old = y;
if (debug > 1)
printk(KERN_DEBUG "appletouch: "
"X: %3d Y: %3d Xz: %3d Yz: %3d\n",
x, y, x_z, y_z);
input_report_key(dev->input, BTN_TOUCH, 1);
input_report_abs(dev->input, ABS_X, x);
input_report_abs(dev->input, ABS_Y, y);
input_report_abs(dev->input, ABS_PRESSURE,
min(ATP_PRESSURE, x_z + y_z));
atp_report_fingers(dev->input, fingers);
}
dev->x_old = x;
dev->y_old = y;
} else if (!x && !y) {
dev->x_old = dev->y_old = -1;
dev->fingers_old = 0;
input_report_key(dev->input, BTN_TOUCH, 0);
input_report_abs(dev->input, ABS_PRESSURE, 0);
atp_report_fingers(dev->input, 0);
memset(dev->xy_acc, 0, sizeof(dev->xy_acc));
}
if (fingers != dev->fingers_old)
dev->x_old = dev->y_old = -1;
dev->fingers_old = fingers;
input_report_key(dev->input, BTN_LEFT, key);
input_sync(dev->input);
exit:
retval = usb_submit_urb(dev->urb, GFP_ATOMIC);
if (retval)
dev_err(&dev->intf->dev,
"atp_complete: usb_submit_urb failed with result %d\n",
retval);
}
static void atp_complete_geyser_3_4(struct urb *urb)
{
int x, y, x_z, y_z, x_f, y_f;
int retval, i, j;
int key, fingers;
struct atp *dev = urb->context;
int status = atp_status_check(urb);
if (status == ATP_URB_STATUS_ERROR_FATAL)
return;
else if (status == ATP_URB_STATUS_ERROR)
goto exit;
for (i = 0, j = 19; i < 20; i += 2, j += 3) {
dev->xy_cur[i] = dev->data[j + 1];
dev->xy_cur[i + 1] = dev->data[j + 2];
}
for (i = 0, j = 1; i < 9; i += 2, j += 3) {
dev->xy_cur[ATP_XSENSORS + i] = dev->data[j + 1];
dev->xy_cur[ATP_XSENSORS + i + 1] = dev->data[j + 2];
}
dbg_dump("sample", dev->xy_cur);
if (dev->data[dev->info->datalen - 1] & ATP_STATUS_BASE_UPDATE) {
dprintk("appletouch: updated base values\n");
memcpy(dev->xy_old, dev->xy_cur, sizeof(dev->xy_old));
goto exit;
}
for (i = 0; i < ATP_XSENSORS + ATP_YSENSORS; i++) {
dev->xy_acc[i] = dev->xy_cur[i] - dev->xy_old[i];
if (dev->xy_acc[i] > 127)
dev->xy_acc[i] -= 256;
if (dev->xy_acc[i] < -127)
dev->xy_acc[i] += 256;
if (dev->xy_acc[i] < 0)
dev->xy_acc[i] = 0;
}
dbg_dump("accumulator", dev->xy_acc);
x = atp_calculate_abs(dev, 0, ATP_XSENSORS,
dev->info->xfact, &x_z, &x_f);
y = atp_calculate_abs(dev, ATP_XSENSORS, ATP_YSENSORS,
dev->info->yfact, &y_z, &y_f);
key = dev->data[dev->info->datalen - 1] & ATP_STATUS_BUTTON;
fingers = max(x_f, y_f);
if (x && y && fingers == dev->fingers_old) {
if (dev->x_old != -1) {
x = (dev->x_old * 7 + x) >> 3;
y = (dev->y_old * 7 + y) >> 3;
dev->x_old = x;
dev->y_old = y;
if (debug > 1)
printk(KERN_DEBUG "appletouch: X: %3d Y: %3d "
"Xz: %3d Yz: %3d\n",
x, y, x_z, y_z);
input_report_key(dev->input, BTN_TOUCH, 1);
input_report_abs(dev->input, ABS_X, x);
input_report_abs(dev->input, ABS_Y, y);
input_report_abs(dev->input, ABS_PRESSURE,
min(ATP_PRESSURE, x_z + y_z));
atp_report_fingers(dev->input, fingers);
}
dev->x_old = x;
dev->y_old = y;
} else if (!x && !y) {
dev->x_old = dev->y_old = -1;
dev->fingers_old = 0;
input_report_key(dev->input, BTN_TOUCH, 0);
input_report_abs(dev->input, ABS_PRESSURE, 0);
atp_report_fingers(dev->input, 0);
memset(dev->xy_acc, 0, sizeof(dev->xy_acc));
}
if (fingers != dev->fingers_old)
dev->x_old = dev->y_old = -1;
dev->fingers_old = fingers;
input_report_key(dev->input, BTN_LEFT, key);
input_sync(dev->input);
if (!x && !y && !key) {
dev->idlecount++;
if (dev->idlecount == 10) {
dev->x_old = dev->y_old = -1;
dev->idlecount = 0;
schedule_work(&dev->work);
return;
}
} else
dev->idlecount = 0;
exit:
retval = usb_submit_urb(dev->urb, GFP_ATOMIC);
if (retval)
dev_err(&dev->intf->dev,
"atp_complete: usb_submit_urb failed with result %d\n",
retval);
}
static int atp_open(struct input_dev *input)
{
struct atp *dev = input_get_drvdata(input);
if (usb_submit_urb(dev->urb, GFP_ATOMIC))
return -EIO;
dev->open = 1;
return 0;
}
static void atp_close(struct input_dev *input)
{
struct atp *dev = input_get_drvdata(input);
usb_kill_urb(dev->urb);
cancel_work_sync(&dev->work);
dev->open = 0;
}
static int atp_handle_geyser(struct atp *dev)
{
if (dev->info != &fountain_info) {
if (atp_geyser_init(dev))
return -EIO;
dev_info(&dev->intf->dev, "Geyser mode initialized.\n");
}
return 0;
}
static int atp_probe(struct usb_interface *iface,
const struct usb_device_id *id)
{
struct atp *dev;
struct input_dev *input_dev;
struct usb_device *udev = interface_to_usbdev(iface);
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int int_in_endpointAddr = 0;
int i, error = -ENOMEM;
const struct atp_info *info = (const struct atp_info *)id->driver_info;
iface_desc = iface->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {
endpoint = &iface_desc->endpoint[i].desc;
if (!int_in_endpointAddr && usb_endpoint_is_int_in(endpoint)) {
int_in_endpointAddr = endpoint->bEndpointAddress;
break;
}
}
if (!int_in_endpointAddr) {
dev_err(&iface->dev, "Could not find int-in endpoint\n");
return -EIO;
}
dev = kzalloc(sizeof(struct atp), GFP_KERNEL);
input_dev = input_allocate_device();
if (!dev || !input_dev) {
dev_err(&iface->dev, "Out of memory\n");
goto err_free_devs;
}
dev->udev = udev;
dev->intf = iface;
dev->input = input_dev;
dev->info = info;
dev->overflow_warned = false;
dev->urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->urb)
goto err_free_devs;
dev->data = usb_alloc_coherent(dev->udev, dev->info->datalen, GFP_KERNEL,
&dev->urb->transfer_dma);
if (!dev->data)
goto err_free_urb;
usb_fill_int_urb(dev->urb, udev,
usb_rcvintpipe(udev, int_in_endpointAddr),
dev->data, dev->info->datalen,
dev->info->callback, dev, 1);
error = atp_handle_geyser(dev);
if (error)
goto err_free_buffer;
usb_make_path(udev, dev->phys, sizeof(dev->phys));
strlcat(dev->phys, "/input0", sizeof(dev->phys));
input_dev->name = "appletouch";
input_dev->phys = dev->phys;
usb_to_input_id(dev->udev, &input_dev->id);
input_dev->dev.parent = &iface->dev;
input_set_drvdata(input_dev, dev);
input_dev->open = atp_open;
input_dev->close = atp_close;
set_bit(EV_ABS, input_dev->evbit);
input_set_abs_params(input_dev, ABS_X, 0,
(dev->info->xsensors - 1) * dev->info->xfact - 1,
dev->info->fuzz, 0);
input_set_abs_params(input_dev, ABS_Y, 0,
(dev->info->ysensors - 1) * dev->info->yfact - 1,
dev->info->fuzz, 0);
input_set_abs_params(input_dev, ABS_PRESSURE, 0, ATP_PRESSURE, 0, 0);
set_bit(EV_KEY, input_dev->evbit);
set_bit(BTN_TOUCH, input_dev->keybit);
set_bit(BTN_TOOL_FINGER, input_dev->keybit);
set_bit(BTN_TOOL_DOUBLETAP, input_dev->keybit);
set_bit(BTN_TOOL_TRIPLETAP, input_dev->keybit);
set_bit(BTN_LEFT, input_dev->keybit);
error = input_register_device(dev->input);
if (error)
goto err_free_buffer;
usb_set_intfdata(iface, dev);
INIT_WORK(&dev->work, atp_reinit);
return 0;
err_free_buffer:
usb_free_coherent(dev->udev, dev->info->datalen,
dev->data, dev->urb->transfer_dma);
err_free_urb:
usb_free_urb(dev->urb);
err_free_devs:
usb_set_intfdata(iface, NULL);
kfree(dev);
input_free_device(input_dev);
return error;
}
static void atp_disconnect(struct usb_interface *iface)
{
struct atp *dev = usb_get_intfdata(iface);
usb_set_intfdata(iface, NULL);
if (dev) {
usb_kill_urb(dev->urb);
input_unregister_device(dev->input);
usb_free_coherent(dev->udev, dev->info->datalen,
dev->data, dev->urb->transfer_dma);
usb_free_urb(dev->urb);
kfree(dev);
}
dev_info(&iface->dev, "input: appletouch disconnected\n");
}
static int atp_recover(struct atp *dev)
{
int error;
error = atp_handle_geyser(dev);
if (error)
return error;
if (dev->open && usb_submit_urb(dev->urb, GFP_ATOMIC))
return -EIO;
return 0;
}
static int atp_suspend(struct usb_interface *iface, pm_message_t message)
{
struct atp *dev = usb_get_intfdata(iface);
usb_kill_urb(dev->urb);
return 0;
}
static int atp_resume(struct usb_interface *iface)
{
struct atp *dev = usb_get_intfdata(iface);
if (dev->open && usb_submit_urb(dev->urb, GFP_ATOMIC))
return -EIO;
return 0;
}
static int atp_reset_resume(struct usb_interface *iface)
{
struct atp *dev = usb_get_intfdata(iface);
return atp_recover(dev);
}
