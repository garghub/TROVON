static inline struct s2250 *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct s2250, sd);
}
static int go7007_usb_vendor_request(struct go7007 *go, u16 request,
u16 value, u16 index, void *transfer_buffer, int length, int in)
{
struct go7007_usb *usb = go->hpi_context;
int timeout = 5000;
if (in) {
return usb_control_msg(usb->usbdev,
usb_rcvctrlpipe(usb->usbdev, 0), request,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
value, index, transfer_buffer, length, timeout);
} else {
return usb_control_msg(usb->usbdev,
usb_sndctrlpipe(usb->usbdev, 0), request,
USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, transfer_buffer, length, timeout);
}
}
static int write_reg(struct i2c_client *client, u8 reg, u8 value)
{
struct go7007 *go = i2c_get_adapdata(client->adapter);
struct go7007_usb *usb;
int rc;
int dev_addr = client->addr << 1;
u8 *buf;
if (go == NULL)
return -ENODEV;
if (go->status == STATUS_SHUTDOWN)
return -EBUSY;
buf = kzalloc(16, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
usb = go->hpi_context;
if (mutex_lock_interruptible(&usb->i2c_lock) != 0) {
dev_info(&client->dev, "i2c lock failed\n");
kfree(buf);
return -EINTR;
}
rc = go7007_usb_vendor_request(go, 0x55, dev_addr,
(reg<<8 | value),
buf,
16, 1);
mutex_unlock(&usb->i2c_lock);
kfree(buf);
return rc;
}
static int write_reg_fp(struct i2c_client *client, u16 addr, u16 val)
{
struct go7007 *go = i2c_get_adapdata(client->adapter);
struct go7007_usb *usb;
int rc;
u8 *buf;
struct s2250 *dec = i2c_get_clientdata(client);
if (go == NULL)
return -ENODEV;
if (go->status == STATUS_SHUTDOWN)
return -EBUSY;
buf = kzalloc(16, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
memset(buf, 0xcd, 6);
usb = go->hpi_context;
if (mutex_lock_interruptible(&usb->i2c_lock) != 0) {
dev_info(&client->dev, "i2c lock failed\n");
kfree(buf);
return -EINTR;
}
rc = go7007_usb_vendor_request(go, 0x57, addr, val, buf, 16, 1);
mutex_unlock(&usb->i2c_lock);
if (rc < 0) {
kfree(buf);
return rc;
}
if (buf[0] == 0) {
unsigned int subaddr, val_read;
subaddr = (buf[4] << 8) + buf[5];
val_read = (buf[2] << 8) + buf[3];
kfree(buf);
if (val_read != val) {
dev_info(&client->dev, "invalid fp write %x %x\n",
val_read, val);
return -EFAULT;
}
if (subaddr != addr) {
dev_info(&client->dev, "invalid fp write addr %x %x\n",
subaddr, addr);
return -EFAULT;
}
} else {
kfree(buf);
return -EFAULT;
}
if (addr == 0x12b)
dec->reg12b_val = val;
return 0;
}
static int read_reg_fp(struct i2c_client *client, u16 addr, u16 *val)
{
struct go7007 *go = i2c_get_adapdata(client->adapter);
struct go7007_usb *usb;
int rc;
u8 *buf;
if (go == NULL)
return -ENODEV;
if (go->status == STATUS_SHUTDOWN)
return -EBUSY;
buf = kzalloc(16, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
memset(buf, 0xcd, 6);
usb = go->hpi_context;
if (mutex_lock_interruptible(&usb->i2c_lock) != 0) {
dev_info(&client->dev, "i2c lock failed\n");
kfree(buf);
return -EINTR;
}
rc = go7007_usb_vendor_request(go, 0x58, addr, 0, buf, 16, 1);
mutex_unlock(&usb->i2c_lock);
if (rc < 0) {
kfree(buf);
return rc;
}
*val = (buf[0] << 8) | buf[1];
kfree(buf);
return 0;
}
static int write_regs(struct i2c_client *client, u8 *regs)
{
int i;
for (i = 0; !((regs[i] == 0x00) && (regs[i+1] == 0x00)); i += 2) {
if (write_reg(client, regs[i], regs[i+1]) < 0) {
dev_info(&client->dev, "failed\n");
return -1;
}
}
return 0;
}
static int write_regs_fp(struct i2c_client *client, u16 *regs)
{
int i;
for (i = 0; !((regs[i] == 0x00) && (regs[i+1] == 0x00)); i += 2) {
if (write_reg_fp(client, regs[i], regs[i+1]) < 0) {
dev_info(&client->dev, "failed fp\n");
return -1;
}
}
return 0;
}
static int s2250_s_video_routing(struct v4l2_subdev *sd, u32 input, u32 output,
u32 config)
{
struct s2250 *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
int vidsys;
vidsys = (state->std == V4L2_STD_NTSC) ? 0x01 : 0x00;
if (input == 0) {
write_reg_fp(client, 0x20, 0x020 | vidsys);
write_reg_fp(client, 0x21, 0x662);
write_reg_fp(client, 0x140, 0x060);
} else if (input == 1) {
write_reg_fp(client, 0x20, 0x040 | vidsys);
write_reg_fp(client, 0x21, 0x666);
write_reg_fp(client, 0x140, 0x060);
} else {
return -EINVAL;
}
state->input = input;
return 0;
}
static int s2250_s_std(struct v4l2_subdev *sd, v4l2_std_id norm)
{
struct s2250 *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
u16 vidsource;
vidsource = (state->input == 1) ? 0x040 : 0x020;
if (norm & V4L2_STD_625_50) {
write_regs_fp(client, vid_regs_fp);
write_regs_fp(client, vid_regs_fp_pal);
write_reg_fp(client, 0x20, vidsource);
} else {
write_regs_fp(client, vid_regs_fp);
write_reg_fp(client, 0x20, vidsource | 1);
}
state->std = norm;
return 0;
}
static int s2250_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct s2250 *state = container_of(ctrl->handler, struct s2250, hdl);
struct i2c_client *client = v4l2_get_subdevdata(&state->sd);
u16 oldvalue;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
read_reg_fp(client, VPX322_ADDR_BRIGHTNESS0, &oldvalue);
write_reg_fp(client, VPX322_ADDR_BRIGHTNESS0,
ctrl->val | (oldvalue & ~0xff));
read_reg_fp(client, VPX322_ADDR_BRIGHTNESS1, &oldvalue);
write_reg_fp(client, VPX322_ADDR_BRIGHTNESS1,
ctrl->val | (oldvalue & ~0xff));
write_reg_fp(client, 0x140, 0x60);
break;
case V4L2_CID_CONTRAST:
read_reg_fp(client, VPX322_ADDR_CONTRAST0, &oldvalue);
write_reg_fp(client, VPX322_ADDR_CONTRAST0,
ctrl->val | (oldvalue & ~0x3f));
read_reg_fp(client, VPX322_ADDR_CONTRAST1, &oldvalue);
write_reg_fp(client, VPX322_ADDR_CONTRAST1,
ctrl->val | (oldvalue & ~0x3f));
write_reg_fp(client, 0x140, 0x60);
break;
case V4L2_CID_SATURATION:
write_reg_fp(client, VPX322_ADDR_SAT, ctrl->val);
break;
case V4L2_CID_HUE:
write_reg_fp(client, VPX322_ADDR_HUE, ctrl->val);
break;
default:
return -EINVAL;
}
return 0;
}
static int s2250_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct v4l2_mbus_framefmt *fmt = &format->format;
struct s2250 *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (format->pad)
return -EINVAL;
if (format->which == V4L2_SUBDEV_FORMAT_TRY)
return 0;
if (fmt->height < 640) {
write_reg_fp(client, 0x12b, state->reg12b_val | 0x400);
write_reg_fp(client, 0x140, 0x060);
} else {
write_reg_fp(client, 0x12b, state->reg12b_val & ~0x400);
write_reg_fp(client, 0x140, 0x060);
}
return 0;
}
static int s2250_s_audio_routing(struct v4l2_subdev *sd, u32 input, u32 output,
u32 config)
{
struct s2250 *state = to_state(sd);
switch (input) {
case 0:
write_reg(state->audio, 0x08, 0x02);
break;
case 1:
write_reg(state->audio, 0x08, 0x04);
break;
case 2:
write_reg(state->audio, 0x08, 0x05);
break;
default:
return -EINVAL;
}
state->audio_input = input;
return 0;
}
static int s2250_log_status(struct v4l2_subdev *sd)
{
struct s2250 *state = to_state(sd);
v4l2_info(sd, "Standard: %s\n", state->std == V4L2_STD_NTSC ? "NTSC" :
state->std == V4L2_STD_PAL ? "PAL" :
state->std == V4L2_STD_SECAM ? "SECAM" :
"unknown");
v4l2_info(sd, "Input: %s\n", state->input == 0 ? "Composite" :
state->input == 1 ? "S-video" :
"error");
v4l2_info(sd, "Audio input: %s\n", state->audio_input == 0 ? "Line In" :
state->audio_input == 1 ? "Mic" :
state->audio_input == 2 ? "Mic Boost" :
"error");
return v4l2_ctrl_subdev_log_status(sd);
}
static int s2250_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_client *audio;
struct i2c_adapter *adapter = client->adapter;
struct s2250 *state;
struct v4l2_subdev *sd;
u8 *data;
struct go7007 *go = i2c_get_adapdata(adapter);
struct go7007_usb *usb = go->hpi_context;
audio = i2c_new_dummy(adapter, TLV320_ADDRESS >> 1);
if (audio == NULL)
return -ENOMEM;
state = kzalloc(sizeof(struct s2250), GFP_KERNEL);
if (state == NULL) {
i2c_unregister_device(audio);
return -ENOMEM;
}
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &s2250_ops);
v4l2_info(sd, "initializing %s at address 0x%x on %s\n",
"Sensoray 2250/2251", client->addr, client->adapter->name);
v4l2_ctrl_handler_init(&state->hdl, 4);
v4l2_ctrl_new_std(&state->hdl, &s2250_ctrl_ops,
V4L2_CID_BRIGHTNESS, -128, 127, 1, 0);
v4l2_ctrl_new_std(&state->hdl, &s2250_ctrl_ops,
V4L2_CID_CONTRAST, 0, 0x3f, 1, 0x32);
v4l2_ctrl_new_std(&state->hdl, &s2250_ctrl_ops,
V4L2_CID_SATURATION, 0, 4094, 1, 2070);
v4l2_ctrl_new_std(&state->hdl, &s2250_ctrl_ops,
V4L2_CID_HUE, -512, 511, 1, 0);
sd->ctrl_handler = &state->hdl;
if (state->hdl.error) {
int err = state->hdl.error;
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return err;
}
state->std = V4L2_STD_NTSC;
state->brightness = 50;
state->contrast = 50;
state->saturation = 50;
state->hue = 0;
state->audio = audio;
if (write_regs(audio, aud_regs) < 0) {
dev_err(&client->dev, "error initializing audio\n");
goto fail;
}
if (write_regs(client, vid_regs) < 0) {
dev_err(&client->dev, "error initializing decoder\n");
goto fail;
}
if (write_regs_fp(client, vid_regs_fp) < 0) {
dev_err(&client->dev, "error initializing decoder\n");
goto fail;
}
write_reg_fp(client, 0x20, 0x020 | 1);
write_reg_fp(client, 0x21, 0x662);
write_reg_fp(client, 0x140, 0x060);
state->audio_input = 0;
write_reg(client, 0x08, 0x02);
if (mutex_lock_interruptible(&usb->i2c_lock) == 0) {
data = kzalloc(16, GFP_KERNEL);
if (data != NULL) {
int rc = go7007_usb_vendor_request(go, 0x41, 0, 0,
data, 16, 1);
if (rc > 0) {
u8 mask;
data[0] = 0;
mask = 1<<5;
data[0] &= ~mask;
data[1] |= mask;
go7007_usb_vendor_request(go, 0x40, 0,
(data[1]<<8)
+ data[1],
data, 16, 0);
}
kfree(data);
}
mutex_unlock(&usb->i2c_lock);
}
v4l2_info(sd, "initialized successfully\n");
return 0;
fail:
i2c_unregister_device(audio);
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return -EIO;
}
static int s2250_remove(struct i2c_client *client)
{
struct s2250 *state = to_state(i2c_get_clientdata(client));
v4l2_device_unregister_subdev(&state->sd);
v4l2_ctrl_handler_free(&state->hdl);
kfree(state);
return 0;
}
