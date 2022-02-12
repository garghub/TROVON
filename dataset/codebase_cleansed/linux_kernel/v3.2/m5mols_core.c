static u32 m5mols_swap_byte(u8 *data, u8 length)
{
if (length == 1)
return *data;
else if (length == 2)
return be16_to_cpu(*((u16 *)data));
else
return be32_to_cpu(*((u32 *)data));
}
static int m5mols_read(struct v4l2_subdev *sd, u32 size, u32 reg, u32 *val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 rbuf[M5MOLS_I2C_MAX_SIZE + 1];
u8 category = I2C_CATEGORY(reg);
u8 cmd = I2C_COMMAND(reg);
struct i2c_msg msg[2];
u8 wbuf[5];
int ret;
if (!client->adapter)
return -ENODEV;
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].len = 5;
msg[0].buf = wbuf;
wbuf[0] = 5;
wbuf[1] = M5MOLS_BYTE_READ;
wbuf[2] = category;
wbuf[3] = cmd;
wbuf[4] = size;
msg[1].addr = client->addr;
msg[1].flags = I2C_M_RD;
msg[1].len = size + 1;
msg[1].buf = rbuf;
usleep_range(200, 200);
ret = i2c_transfer(client->adapter, msg, 2);
if (ret < 0) {
v4l2_err(sd, "read failed: size:%d cat:%02x cmd:%02x. %d\n",
size, category, cmd, ret);
return ret;
}
*val = m5mols_swap_byte(&rbuf[1], size);
return 0;
}
int m5mols_read_u8(struct v4l2_subdev *sd, u32 reg, u8 *val)
{
u32 val_32;
int ret;
if (I2C_SIZE(reg) != 1) {
v4l2_err(sd, "Wrong data size\n");
return -EINVAL;
}
ret = m5mols_read(sd, I2C_SIZE(reg), reg, &val_32);
if (ret)
return ret;
*val = (u8)val_32;
return ret;
}
int m5mols_read_u16(struct v4l2_subdev *sd, u32 reg, u16 *val)
{
u32 val_32;
int ret;
if (I2C_SIZE(reg) != 2) {
v4l2_err(sd, "Wrong data size\n");
return -EINVAL;
}
ret = m5mols_read(sd, I2C_SIZE(reg), reg, &val_32);
if (ret)
return ret;
*val = (u16)val_32;
return ret;
}
int m5mols_read_u32(struct v4l2_subdev *sd, u32 reg, u32 *val)
{
if (I2C_SIZE(reg) != 4) {
v4l2_err(sd, "Wrong data size\n");
return -EINVAL;
}
return m5mols_read(sd, I2C_SIZE(reg), reg, val);
}
int m5mols_write(struct v4l2_subdev *sd, u32 reg, u32 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 wbuf[M5MOLS_I2C_MAX_SIZE + 4];
u8 category = I2C_CATEGORY(reg);
u8 cmd = I2C_COMMAND(reg);
u8 size = I2C_SIZE(reg);
u32 *buf = (u32 *)&wbuf[4];
struct i2c_msg msg[1];
int ret;
if (!client->adapter)
return -ENODEV;
if (size != 1 && size != 2 && size != 4) {
v4l2_err(sd, "Wrong data size\n");
return -EINVAL;
}
msg->addr = client->addr;
msg->flags = 0;
msg->len = (u16)size + 4;
msg->buf = wbuf;
wbuf[0] = size + 4;
wbuf[1] = M5MOLS_BYTE_WRITE;
wbuf[2] = category;
wbuf[3] = cmd;
*buf = m5mols_swap_byte((u8 *)&val, size);
usleep_range(200, 200);
ret = i2c_transfer(client->adapter, msg, 1);
if (ret < 0) {
v4l2_err(sd, "write failed: size:%d cat:%02x cmd:%02x. %d\n",
size, category, cmd, ret);
return ret;
}
return 0;
}
int m5mols_busy(struct v4l2_subdev *sd, u8 category, u8 cmd, u8 mask)
{
u8 busy;
int i;
int ret;
for (i = 0; i < M5MOLS_I2C_CHECK_RETRY; i++) {
ret = m5mols_read_u8(sd, I2C_REG(category, cmd, 1), &busy);
if (ret < 0)
return ret;
if ((busy & mask) == mask)
return 0;
}
return -EBUSY;
}
int m5mols_enable_interrupt(struct v4l2_subdev *sd, u8 reg)
{
struct m5mols_info *info = to_m5mols(sd);
u8 mask = is_available_af(info) ? REG_INT_AF : 0;
u8 dummy;
int ret;
ret = m5mols_read_u8(sd, SYSTEM_INT_FACTOR, &dummy);
if (!ret)
ret = m5mols_write(sd, SYSTEM_INT_ENABLE, reg & ~mask);
return ret;
}
static int m5mols_reg_mode(struct v4l2_subdev *sd, u8 mode)
{
int ret = m5mols_write(sd, SYSTEM_SYSMODE, mode);
return ret ? ret : m5mols_busy(sd, CAT_SYSTEM, CAT0_SYSMODE, mode);
}
int m5mols_mode(struct m5mols_info *info, u8 mode)
{
struct v4l2_subdev *sd = &info->sd;
int ret = -EINVAL;
u8 reg;
if (mode < REG_PARAMETER || mode > REG_CAPTURE)
return ret;
ret = m5mols_read_u8(sd, SYSTEM_SYSMODE, &reg);
if ((!ret && reg == mode) || ret)
return ret;
switch (reg) {
case REG_PARAMETER:
ret = m5mols_reg_mode(sd, REG_MONITOR);
if (!ret && mode == REG_MONITOR)
break;
if (!ret)
ret = m5mols_reg_mode(sd, REG_CAPTURE);
break;
case REG_MONITOR:
if (mode == REG_PARAMETER) {
ret = m5mols_reg_mode(sd, REG_PARAMETER);
break;
}
ret = m5mols_reg_mode(sd, REG_CAPTURE);
break;
case REG_CAPTURE:
ret = m5mols_reg_mode(sd, REG_MONITOR);
if (!ret && mode == REG_MONITOR)
break;
if (!ret)
ret = m5mols_reg_mode(sd, REG_PARAMETER);
break;
default:
v4l2_warn(sd, "Wrong mode: %d\n", mode);
}
if (!ret)
info->mode = mode;
return ret;
}
static int m5mols_get_version(struct v4l2_subdev *sd)
{
struct m5mols_info *info = to_m5mols(sd);
struct m5mols_version *ver = &info->ver;
u8 *str = ver->str;
int i;
int ret;
ret = m5mols_read_u8(sd, SYSTEM_VER_CUSTOMER, &ver->customer);
if (!ret)
ret = m5mols_read_u8(sd, SYSTEM_VER_PROJECT, &ver->project);
if (!ret)
ret = m5mols_read_u16(sd, SYSTEM_VER_FIRMWARE, &ver->fw);
if (!ret)
ret = m5mols_read_u16(sd, SYSTEM_VER_HARDWARE, &ver->hw);
if (!ret)
ret = m5mols_read_u16(sd, SYSTEM_VER_PARAMETER, &ver->param);
if (!ret)
ret = m5mols_read_u16(sd, SYSTEM_VER_AWB, &ver->awb);
if (!ret)
ret = m5mols_read_u8(sd, AF_VERSION, &ver->af);
if (ret)
return ret;
for (i = 0; i < VERSION_STRING_SIZE; i++) {
ret = m5mols_read_u8(sd, SYSTEM_VER_STRING, &str[i]);
if (ret)
return ret;
}
ver->fw = be16_to_cpu(ver->fw);
ver->hw = be16_to_cpu(ver->hw);
ver->param = be16_to_cpu(ver->param);
ver->awb = be16_to_cpu(ver->awb);
v4l2_info(sd, "Manufacturer\t[%s]\n",
is_manufacturer(info, REG_SAMSUNG_ELECTRO) ?
"Samsung Electro-Machanics" :
is_manufacturer(info, REG_SAMSUNG_OPTICS) ?
"Samsung Fiber-Optics" :
is_manufacturer(info, REG_SAMSUNG_TECHWIN) ?
"Samsung Techwin" : "None");
v4l2_info(sd, "Customer/Project\t[0x%02x/0x%02x]\n",
info->ver.customer, info->ver.project);
if (!is_available_af(info))
v4l2_info(sd, "No support Auto Focus on this firmware\n");
return ret;
}
static enum m5mols_restype __find_restype(enum v4l2_mbus_pixelcode code)
{
enum m5mols_restype type = M5MOLS_RESTYPE_MONITOR;
do {
if (code == m5mols_default_ffmt[type].code)
return type;
} while (type++ != SIZE_DEFAULT_FFMT);
return 0;
}
static int __find_resolution(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf,
enum m5mols_restype *type,
u32 *resolution)
{
const struct m5mols_resolution *fsize = &m5mols_reg_res[0];
const struct m5mols_resolution *match = NULL;
enum m5mols_restype stype = __find_restype(mf->code);
int i = ARRAY_SIZE(m5mols_reg_res);
unsigned int min_err = ~0;
while (i--) {
int err;
if (stype == fsize->type) {
err = abs(fsize->width - mf->width)
+ abs(fsize->height - mf->height);
if (err < min_err) {
min_err = err;
match = fsize;
}
}
fsize++;
}
if (match) {
mf->width = match->width;
mf->height = match->height;
*resolution = match->reg;
*type = stype;
return 0;
}
return -EINVAL;
}
static struct v4l2_mbus_framefmt *__find_format(struct m5mols_info *info,
struct v4l2_subdev_fh *fh,
enum v4l2_subdev_format_whence which,
enum m5mols_restype type)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return fh ? v4l2_subdev_get_try_format(fh, 0) : NULL;
return &info->ffmt[type];
}
static int m5mols_get_fmt(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct m5mols_info *info = to_m5mols(sd);
struct v4l2_mbus_framefmt *format;
format = __find_format(info, fh, fmt->which, info->res_type);
if (!format)
return -EINVAL;
fmt->format = *format;
return 0;
}
static int m5mols_set_fmt(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct m5mols_info *info = to_m5mols(sd);
struct v4l2_mbus_framefmt *format = &fmt->format;
struct v4l2_mbus_framefmt *sfmt;
enum m5mols_restype type;
u32 resolution = 0;
int ret;
ret = __find_resolution(sd, format, &type, &resolution);
if (ret < 0)
return ret;
sfmt = __find_format(info, fh, fmt->which, type);
if (!sfmt)
return 0;
format->code = m5mols_default_ffmt[type].code;
format->colorspace = V4L2_COLORSPACE_JPEG;
format->field = V4L2_FIELD_NONE;
if (fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE) {
*sfmt = *format;
info->resolution = resolution;
info->res_type = type;
}
return 0;
}
static int m5mols_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
if (!code || code->index >= SIZE_DEFAULT_FFMT)
return -EINVAL;
code->code = m5mols_default_ffmt[code->index].code;
return 0;
}
int m5mols_sync_controls(struct m5mols_info *info)
{
int ret = -EINVAL;
if (!is_ctrl_synced(info)) {
ret = m5mols_do_scenemode(info, REG_SCENE_NORMAL);
if (ret)
return ret;
v4l2_ctrl_handler_setup(&info->handle);
info->ctrl_sync = true;
}
return ret;
}
static int m5mols_start_monitor(struct m5mols_info *info)
{
struct v4l2_subdev *sd = &info->sd;
int ret;
ret = m5mols_mode(info, REG_PARAMETER);
if (!ret)
ret = m5mols_write(sd, PARM_MON_SIZE, info->resolution);
if (!ret)
ret = m5mols_write(sd, PARM_MON_FPS, REG_FPS_30);
if (!ret)
ret = m5mols_mode(info, REG_MONITOR);
if (!ret)
ret = m5mols_sync_controls(info);
return ret;
}
static int m5mols_s_stream(struct v4l2_subdev *sd, int enable)
{
struct m5mols_info *info = to_m5mols(sd);
u32 code = info->ffmt[info->res_type].code;
if (enable) {
int ret = -EINVAL;
if (is_code(code, M5MOLS_RESTYPE_MONITOR))
ret = m5mols_start_monitor(info);
if (is_code(code, M5MOLS_RESTYPE_CAPTURE))
ret = m5mols_start_capture(info);
return ret;
}
return m5mols_mode(info, REG_PARAMETER);
}
static int m5mols_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct m5mols_info *info = to_m5mols(sd);
int ret;
info->mode_save = info->mode;
ret = m5mols_mode(info, REG_PARAMETER);
if (!ret)
ret = m5mols_set_ctrl(ctrl);
if (!ret)
ret = m5mols_mode(info, info->mode_save);
return ret;
}
static int m5mols_sensor_power(struct m5mols_info *info, bool enable)
{
struct v4l2_subdev *sd = &info->sd;
struct i2c_client *client = v4l2_get_subdevdata(sd);
const struct m5mols_platform_data *pdata = info->pdata;
int ret;
if (enable) {
if (is_powered(info))
return 0;
if (info->set_power) {
ret = info->set_power(&client->dev, 1);
if (ret)
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(supplies), supplies);
if (ret) {
info->set_power(&client->dev, 0);
return ret;
}
gpio_set_value(pdata->gpio_reset, !pdata->reset_polarity);
usleep_range(1000, 1000);
info->power = true;
return ret;
}
if (!is_powered(info))
return 0;
ret = regulator_bulk_disable(ARRAY_SIZE(supplies), supplies);
if (ret)
return ret;
if (info->set_power)
info->set_power(&client->dev, 0);
gpio_set_value(pdata->gpio_reset, pdata->reset_polarity);
usleep_range(1000, 1000);
info->power = false;
return ret;
}
static int m5mols_sensor_armboot(struct v4l2_subdev *sd)
{
int ret;
ret = m5mols_write(sd, FLASH_CAM_START, REG_START_ARM_BOOT);
if (ret < 0)
return ret;
msleep(520);
ret = m5mols_get_version(sd);
if (!ret)
ret = m5mols_update_fw(sd, m5mols_sensor_power);
if (ret)
return ret;
v4l2_dbg(1, m5mols_debug, sd, "Success ARM Booting\n");
ret = m5mols_write(sd, PARM_INTERFACE, REG_INTERFACE_MIPI);
if (!ret)
ret = m5mols_enable_interrupt(sd, REG_INT_AF);
return ret;
}
static int m5mols_init_controls(struct m5mols_info *info)
{
struct v4l2_subdev *sd = &info->sd;
u16 max_exposure;
u16 step_zoom;
int ret;
ret = m5mols_read_u16(sd, AE_MAX_GAIN_MON, &max_exposure);
if (!ret)
step_zoom = is_manufacturer(info, REG_SAMSUNG_OPTICS) ? 31 : 1;
if (ret)
return ret;
v4l2_ctrl_handler_init(&info->handle, 6);
info->autowb = v4l2_ctrl_new_std(&info->handle,
&m5mols_ctrl_ops, V4L2_CID_AUTO_WHITE_BALANCE,
0, 1, 1, 0);
info->saturation = v4l2_ctrl_new_std(&info->handle,
&m5mols_ctrl_ops, V4L2_CID_SATURATION,
1, 5, 1, 3);
info->zoom = v4l2_ctrl_new_std(&info->handle,
&m5mols_ctrl_ops, V4L2_CID_ZOOM_ABSOLUTE,
1, 70, step_zoom, 1);
info->exposure = v4l2_ctrl_new_std(&info->handle,
&m5mols_ctrl_ops, V4L2_CID_EXPOSURE,
0, max_exposure, 1, (int)max_exposure/2);
info->colorfx = v4l2_ctrl_new_std_menu(&info->handle,
&m5mols_ctrl_ops, V4L2_CID_COLORFX,
4, (1 << V4L2_COLORFX_BW), V4L2_COLORFX_NONE);
info->autoexposure = v4l2_ctrl_new_std_menu(&info->handle,
&m5mols_ctrl_ops, V4L2_CID_EXPOSURE_AUTO,
1, 0, V4L2_EXPOSURE_MANUAL);
sd->ctrl_handler = &info->handle;
if (info->handle.error) {
v4l2_err(sd, "Failed to initialize controls: %d\n", ret);
v4l2_ctrl_handler_free(&info->handle);
return info->handle.error;
}
v4l2_ctrl_cluster(2, &info->autoexposure);
return 0;
}
static int m5mols_s_power(struct v4l2_subdev *sd, int on)
{
struct m5mols_info *info = to_m5mols(sd);
int ret;
if (on) {
ret = m5mols_sensor_power(info, true);
if (!ret)
ret = m5mols_sensor_armboot(sd);
if (!ret)
ret = m5mols_init_controls(info);
if (ret)
return ret;
info->ffmt[M5MOLS_RESTYPE_MONITOR] =
m5mols_default_ffmt[M5MOLS_RESTYPE_MONITOR];
info->ffmt[M5MOLS_RESTYPE_CAPTURE] =
m5mols_default_ffmt[M5MOLS_RESTYPE_CAPTURE];
return ret;
}
if (is_manufacturer(info, REG_SAMSUNG_TECHWIN)) {
ret = m5mols_mode(info, REG_MONITOR);
if (!ret)
ret = m5mols_write(sd, AF_EXECUTE, REG_AF_STOP);
if (!ret)
ret = m5mols_write(sd, AF_MODE, REG_AF_POWEROFF);
if (!ret)
ret = m5mols_busy(sd, CAT_SYSTEM, CAT0_STATUS,
REG_AF_IDLE);
if (!ret)
v4l2_info(sd, "Success soft-landing lens\n");
}
ret = m5mols_sensor_power(info, false);
if (!ret) {
v4l2_ctrl_handler_free(&info->handle);
info->ctrl_sync = false;
}
return ret;
}
static int m5mols_log_status(struct v4l2_subdev *sd)
{
struct m5mols_info *info = to_m5mols(sd);
v4l2_ctrl_handler_log_status(&info->handle, sd->name);
return 0;
}
static void m5mols_irq_work(struct work_struct *work)
{
struct m5mols_info *info =
container_of(work, struct m5mols_info, work_irq);
struct v4l2_subdev *sd = &info->sd;
u8 reg;
int ret;
if (!is_powered(info) ||
m5mols_read_u8(sd, SYSTEM_INT_FACTOR, &info->interrupt))
return;
switch (info->interrupt & REG_INT_MASK) {
case REG_INT_AF:
if (!is_available_af(info))
break;
ret = m5mols_read_u8(sd, AF_STATUS, &reg);
v4l2_dbg(2, m5mols_debug, sd, "AF %s\n",
reg == REG_AF_FAIL ? "Failed" :
reg == REG_AF_SUCCESS ? "Success" :
reg == REG_AF_IDLE ? "Idle" : "Busy");
break;
case REG_INT_CAPTURE:
if (!test_and_set_bit(ST_CAPT_IRQ, &info->flags))
wake_up_interruptible(&info->irq_waitq);
v4l2_dbg(2, m5mols_debug, sd, "CAPTURE\n");
break;
default:
v4l2_dbg(2, m5mols_debug, sd, "Undefined: %02x\n", reg);
break;
};
}
static irqreturn_t m5mols_irq_handler(int irq, void *data)
{
struct v4l2_subdev *sd = data;
struct m5mols_info *info = to_m5mols(sd);
schedule_work(&info->work_irq);
return IRQ_HANDLED;
}
static int __devinit m5mols_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct m5mols_platform_data *pdata = client->dev.platform_data;
struct m5mols_info *info;
struct v4l2_subdev *sd;
int ret;
if (pdata == NULL) {
dev_err(&client->dev, "No platform data\n");
return -EINVAL;
}
if (!gpio_is_valid(pdata->gpio_reset)) {
dev_err(&client->dev, "No valid RESET GPIO specified\n");
return -EINVAL;
}
if (!client->irq) {
dev_err(&client->dev, "Interrupt not assigned\n");
return -EINVAL;
}
info = kzalloc(sizeof(struct m5mols_info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->pdata = pdata;
info->set_power = pdata->set_power;
ret = gpio_request(pdata->gpio_reset, "M5MOLS_NRST");
if (ret) {
dev_err(&client->dev, "Failed to request gpio: %d\n", ret);
goto out_free;
}
gpio_direction_output(pdata->gpio_reset, pdata->reset_polarity);
ret = regulator_bulk_get(&client->dev, ARRAY_SIZE(supplies), supplies);
if (ret) {
dev_err(&client->dev, "Failed to get regulators: %d\n", ret);
goto out_gpio;
}
sd = &info->sd;
strlcpy(sd->name, MODULE_NAME, sizeof(sd->name));
v4l2_i2c_subdev_init(sd, client, &m5mols_ops);
info->pad.flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_init(&sd->entity, 1, &info->pad, 0);
if (ret < 0)
goto out_reg;
sd->entity.type = MEDIA_ENT_T_V4L2_SUBDEV_SENSOR;
init_waitqueue_head(&info->irq_waitq);
INIT_WORK(&info->work_irq, m5mols_irq_work);
ret = request_irq(client->irq, m5mols_irq_handler,
IRQF_TRIGGER_RISING, MODULE_NAME, sd);
if (ret) {
dev_err(&client->dev, "Interrupt request failed: %d\n", ret);
goto out_me;
}
info->res_type = M5MOLS_RESTYPE_MONITOR;
return 0;
out_me:
media_entity_cleanup(&sd->entity);
out_reg:
regulator_bulk_free(ARRAY_SIZE(supplies), supplies);
out_gpio:
gpio_free(pdata->gpio_reset);
out_free:
kfree(info);
return ret;
}
static int __devexit m5mols_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct m5mols_info *info = to_m5mols(sd);
v4l2_device_unregister_subdev(sd);
free_irq(client->irq, sd);
regulator_bulk_free(ARRAY_SIZE(supplies), supplies);
gpio_free(info->pdata->gpio_reset);
media_entity_cleanup(&sd->entity);
kfree(info);
return 0;
}
static int __init m5mols_mod_init(void)
{
return i2c_add_driver(&m5mols_i2c_driver);
}
static void __exit m5mols_mod_exit(void)
{
i2c_del_driver(&m5mols_i2c_driver);
}
