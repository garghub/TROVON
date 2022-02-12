static inline struct si4713_usb_device *to_si4713_dev(struct v4l2_device *v4l2_dev)
{
return container_of(v4l2_dev, struct si4713_usb_device, v4l2_dev);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct si4713_usb_device *radio = video_drvdata(file);
strlcpy(v->driver, "radio-usb-si4713", sizeof(v->driver));
strlcpy(v->card, "Si4713 FM Transmitter", sizeof(v->card));
usb_make_path(radio->usbdev, v->bus_info, sizeof(v->bus_info));
v->device_caps = V4L2_CAP_MODULATOR | V4L2_CAP_RDS_OUTPUT;
v->capabilities = v->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_g_modulator(struct file *file, void *priv,
struct v4l2_modulator *vm)
{
struct si4713_usb_device *radio = video_drvdata(file);
return v4l2_subdev_call(radio->v4l2_subdev, tuner, g_modulator, vm);
}
static int vidioc_s_modulator(struct file *file, void *priv,
const struct v4l2_modulator *vm)
{
struct si4713_usb_device *radio = video_drvdata(file);
return v4l2_subdev_call(radio->v4l2_subdev, tuner, s_modulator, vm);
}
static int vidioc_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *vf)
{
struct si4713_usb_device *radio = video_drvdata(file);
return v4l2_subdev_call(radio->v4l2_subdev, tuner, s_frequency, vf);
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *vf)
{
struct si4713_usb_device *radio = video_drvdata(file);
return v4l2_subdev_call(radio->v4l2_subdev, tuner, g_frequency, vf);
}
static void usb_si4713_video_device_release(struct v4l2_device *v4l2_dev)
{
struct si4713_usb_device *radio = to_si4713_dev(v4l2_dev);
struct i2c_adapter *adapter = &radio->i2c_adapter;
i2c_del_adapter(adapter);
v4l2_device_unregister(&radio->v4l2_dev);
kfree(radio->buffer);
kfree(radio);
}
static int si4713_send_startup_command(struct si4713_usb_device *radio)
{
unsigned long until_jiffies = jiffies + usecs_to_jiffies(USB_RESP_TIMEOUT) + 1;
u8 *buffer = radio->buffer;
int retval;
retval = usb_control_msg(radio->usbdev, usb_sndctrlpipe(radio->usbdev, 0),
0x09, 0x21, 0x033f, 0, radio->buffer,
BUFFER_LENGTH, USB_TIMEOUT);
if (retval < 0)
return retval;
for (;;) {
retval = usb_control_msg(radio->usbdev, usb_rcvctrlpipe(radio->usbdev, 0),
0x01, 0xa1, 0x033f, 0, radio->buffer,
BUFFER_LENGTH, USB_TIMEOUT);
if (retval < 0)
return retval;
if (!radio->buffer[1]) {
switch (buffer[1]) {
case 0x32:
if (radio->buffer[2] == 0)
return 0;
break;
case 0x14:
case 0x12:
if (radio->buffer[2] & SI4713_CTS)
return 0;
break;
case 0x06:
if ((radio->buffer[2] & SI4713_CTS) && radio->buffer[9] == 0x08)
return 0;
break;
default:
return 0;
}
}
if (time_is_before_jiffies(until_jiffies))
return -EIO;
msleep(3);
}
return retval;
}
static int si4713_start_seq(struct si4713_usb_device *radio)
{
int retval = 0;
int i;
radio->buffer[0] = 0x3f;
for (i = 0; i < ARRAY_SIZE(start_seq); i++) {
int len = start_seq[i].len;
const u8 *payload = start_seq[i].payload;
memcpy(radio->buffer + 1, payload, len);
memset(radio->buffer + len + 1, 0, BUFFER_LENGTH - 1 - len);
retval = si4713_send_startup_command(radio);
}
return retval;
}
static int send_command(struct si4713_usb_device *radio, u8 *payload, char *data, int len)
{
int retval;
radio->buffer[0] = 0x3f;
radio->buffer[1] = 0x06;
memcpy(radio->buffer + 2, payload, 3);
memcpy(radio->buffer + 5, data, len);
memset(radio->buffer + 5 + len, 0, BUFFER_LENGTH - 5 - len);
retval = usb_control_msg(radio->usbdev, usb_sndctrlpipe(radio->usbdev, 0),
0x09, 0x21, 0x033f, 0, radio->buffer,
BUFFER_LENGTH, USB_TIMEOUT);
return retval < 0 ? retval : 0;
}
static int si4713_i2c_read(struct si4713_usb_device *radio, char *data, int len)
{
unsigned long until_jiffies = jiffies + usecs_to_jiffies(USB_RESP_TIMEOUT) + 1;
int retval;
for (;;) {
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
0x01, 0xa1, 0x033f, 0, radio->buffer,
BUFFER_LENGTH, USB_TIMEOUT);
if (retval < 0)
return retval;
if (radio->buffer[1] == 0 && (radio->buffer[2] & SI4713_CTS)) {
memcpy(data, radio->buffer + 2, len);
return 0;
}
if (time_is_before_jiffies(until_jiffies)) {
data[0] = 0;
return 0;
}
msleep(3);
}
}
static int si4713_i2c_write(struct si4713_usb_device *radio, char *data, int len)
{
int retval = -EINVAL;
int i;
if (len > BUFFER_LENGTH - 5)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(command_table); i++) {
if (data[0] == command_table[i].command_id)
retval = send_command(radio, command_table[i].payload,
data, len);
}
return retval < 0 ? retval : 0;
}
static int si4713_transfer(struct i2c_adapter *i2c_adapter,
struct i2c_msg *msgs, int num)
{
struct si4713_usb_device *radio = i2c_get_adapdata(i2c_adapter);
int retval = -EINVAL;
int i;
if (num <= 0)
return 0;
for (i = 0; i < num; i++) {
if (msgs[i].flags & I2C_M_RD)
retval = si4713_i2c_read(radio, msgs[i].buf, msgs[i].len);
else
retval = si4713_i2c_write(radio, msgs[i].buf, msgs[i].len);
if (retval)
break;
}
return retval ? retval : num;
}
static u32 si4713_functionality(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int si4713_register_i2c_adapter(struct si4713_usb_device *radio)
{
radio->i2c_adapter = si4713_i2c_adapter_template;
radio->i2c_adapter.dev.parent = &radio->usbdev->dev;
i2c_set_adapdata(&radio->i2c_adapter, radio);
return i2c_add_adapter(&radio->i2c_adapter);
}
static int usb_si4713_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct si4713_usb_device *radio;
struct i2c_adapter *adapter;
struct v4l2_subdev *sd;
int retval = -ENOMEM;
dev_info(&intf->dev, "Si4713 development board discovered: (%04X:%04X)\n",
id->idVendor, id->idProduct);
radio = kzalloc(sizeof(struct si4713_usb_device), GFP_KERNEL);
if (radio)
radio->buffer = kmalloc(BUFFER_LENGTH, GFP_KERNEL);
if (!radio || !radio->buffer) {
dev_err(&intf->dev, "kmalloc for si4713_usb_device failed\n");
kfree(radio);
return -ENOMEM;
}
mutex_init(&radio->lock);
radio->usbdev = interface_to_usbdev(intf);
radio->intf = intf;
usb_set_intfdata(intf, &radio->v4l2_dev);
retval = si4713_start_seq(radio);
if (retval < 0)
goto err_v4l2;
retval = v4l2_device_register(&intf->dev, &radio->v4l2_dev);
if (retval < 0) {
dev_err(&intf->dev, "couldn't register v4l2_device\n");
goto err_v4l2;
}
retval = si4713_register_i2c_adapter(radio);
if (retval < 0) {
dev_err(&intf->dev, "could not register i2c device\n");
goto err_i2cdev;
}
adapter = &radio->i2c_adapter;
sd = v4l2_i2c_new_subdev_board(&radio->v4l2_dev, adapter,
&si4713_board_info, NULL);
radio->v4l2_subdev = sd;
if (!sd) {
dev_err(&intf->dev, "cannot get v4l2 subdevice\n");
retval = -ENODEV;
goto del_adapter;
}
radio->vdev.ctrl_handler = sd->ctrl_handler;
radio->v4l2_dev.release = usb_si4713_video_device_release;
strlcpy(radio->vdev.name, radio->v4l2_dev.name,
sizeof(radio->vdev.name));
radio->vdev.v4l2_dev = &radio->v4l2_dev;
radio->vdev.fops = &usb_si4713_fops;
radio->vdev.ioctl_ops = &usb_si4713_ioctl_ops;
radio->vdev.lock = &radio->lock;
radio->vdev.release = video_device_release_empty;
radio->vdev.vfl_dir = VFL_DIR_TX;
video_set_drvdata(&radio->vdev, radio);
retval = video_register_device(&radio->vdev, VFL_TYPE_RADIO, -1);
if (retval < 0) {
dev_err(&intf->dev, "could not register video device\n");
goto del_adapter;
}
dev_info(&intf->dev, "V4L2 device registered as %s\n",
video_device_node_name(&radio->vdev));
return 0;
del_adapter:
i2c_del_adapter(adapter);
err_i2cdev:
v4l2_device_unregister(&radio->v4l2_dev);
err_v4l2:
kfree(radio->buffer);
kfree(radio);
return retval;
}
static void usb_si4713_disconnect(struct usb_interface *intf)
{
struct si4713_usb_device *radio = to_si4713_dev(usb_get_intfdata(intf));
dev_info(&intf->dev, "Si4713 development board now disconnected\n");
mutex_lock(&radio->lock);
usb_set_intfdata(intf, NULL);
video_unregister_device(&radio->vdev);
v4l2_device_disconnect(&radio->v4l2_dev);
mutex_unlock(&radio->lock);
v4l2_device_put(&radio->v4l2_dev);
}
