static int lp855x_read_byte(struct lp855x *lp, u8 reg, u8 *data)
{
int ret;
ret = i2c_smbus_read_byte_data(lp->client, reg);
if (ret < 0) {
dev_err(lp->dev, "failed to read 0x%.2x\n", reg);
return ret;
}
*data = (u8)ret;
return 0;
}
static int lp855x_write_byte(struct lp855x *lp, u8 reg, u8 data)
{
return i2c_smbus_write_byte_data(lp->client, reg, data);
}
static bool lp855x_is_valid_rom_area(struct lp855x *lp, u8 addr)
{
u8 start, end;
switch (lp->chip_id) {
case LP8550:
case LP8551:
case LP8552:
case LP8553:
start = EEPROM_START;
end = EEPROM_END;
break;
case LP8556:
start = EPROM_START;
end = EPROM_END;
break;
default:
return false;
}
return (addr >= start && addr <= end);
}
static int lp855x_init_registers(struct lp855x *lp)
{
u8 val, addr;
int i, ret;
struct lp855x_platform_data *pd = lp->pdata;
val = pd->initial_brightness;
ret = lp855x_write_byte(lp, BRIGHTNESS_CTRL, val);
if (ret)
return ret;
val = pd->device_control;
ret = lp855x_write_byte(lp, DEVICE_CTRL, val);
if (ret)
return ret;
if (pd->load_new_rom_data && pd->size_program) {
for (i = 0; i < pd->size_program; i++) {
addr = pd->rom_data[i].addr;
val = pd->rom_data[i].val;
if (!lp855x_is_valid_rom_area(lp, addr))
continue;
ret = lp855x_write_byte(lp, addr, val);
if (ret)
return ret;
}
}
return ret;
}
static void lp855x_pwm_ctrl(struct lp855x *lp, int br, int max_br)
{
unsigned int period = lp->pdata->period_ns;
unsigned int duty = br * period / max_br;
struct pwm_device *pwm;
if (!lp->pwm) {
pwm = devm_pwm_get(lp->dev, lp->chipname);
if (IS_ERR(pwm))
return;
lp->pwm = pwm;
}
pwm_config(lp->pwm, duty, period);
if (duty)
pwm_enable(lp->pwm);
else
pwm_disable(lp->pwm);
}
static int lp855x_bl_update_status(struct backlight_device *bl)
{
struct lp855x *lp = bl_get_data(bl);
enum lp855x_brightness_ctrl_mode mode = lp->pdata->mode;
if (bl->props.state & BL_CORE_SUSPENDED)
bl->props.brightness = 0;
if (mode == PWM_BASED) {
int br = bl->props.brightness;
int max_br = bl->props.max_brightness;
lp855x_pwm_ctrl(lp, br, max_br);
} else if (mode == REGISTER_BASED) {
u8 val = bl->props.brightness;
lp855x_write_byte(lp, BRIGHTNESS_CTRL, val);
}
return 0;
}
static int lp855x_bl_get_brightness(struct backlight_device *bl)
{
struct lp855x *lp = bl_get_data(bl);
enum lp855x_brightness_ctrl_mode mode = lp->pdata->mode;
if (mode == REGISTER_BASED) {
u8 val = 0;
lp855x_read_byte(lp, BRIGHTNESS_CTRL, &val);
bl->props.brightness = val;
}
return bl->props.brightness;
}
static int lp855x_backlight_register(struct lp855x *lp)
{
struct backlight_device *bl;
struct backlight_properties props;
struct lp855x_platform_data *pdata = lp->pdata;
char *name = pdata->name ? : DEFAULT_BL_NAME;
props.type = BACKLIGHT_PLATFORM;
props.max_brightness = MAX_BRIGHTNESS;
if (pdata->initial_brightness > props.max_brightness)
pdata->initial_brightness = props.max_brightness;
props.brightness = pdata->initial_brightness;
bl = backlight_device_register(name, lp->dev, lp,
&lp855x_bl_ops, &props);
if (IS_ERR(bl))
return PTR_ERR(bl);
lp->bl = bl;
return 0;
}
static void lp855x_backlight_unregister(struct lp855x *lp)
{
if (lp->bl)
backlight_device_unregister(lp->bl);
}
static ssize_t lp855x_get_chip_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lp855x *lp = dev_get_drvdata(dev);
return scnprintf(buf, BUF_SIZE, "%s\n", lp->chipname);
}
static ssize_t lp855x_get_bl_ctl_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lp855x *lp = dev_get_drvdata(dev);
enum lp855x_brightness_ctrl_mode mode = lp->pdata->mode;
char *strmode = NULL;
if (mode == PWM_BASED)
strmode = "pwm based";
else if (mode == REGISTER_BASED)
strmode = "register based";
return scnprintf(buf, BUF_SIZE, "%s\n", strmode);
}
static int lp855x_probe(struct i2c_client *cl, const struct i2c_device_id *id)
{
struct lp855x *lp;
struct lp855x_platform_data *pdata = cl->dev.platform_data;
enum lp855x_brightness_ctrl_mode mode;
int ret;
if (!pdata) {
dev_err(&cl->dev, "no platform data supplied\n");
return -EINVAL;
}
if (!i2c_check_functionality(cl->adapter, I2C_FUNC_SMBUS_I2C_BLOCK))
return -EIO;
lp = devm_kzalloc(&cl->dev, sizeof(struct lp855x), GFP_KERNEL);
if (!lp)
return -ENOMEM;
mode = pdata->mode;
lp->client = cl;
lp->dev = &cl->dev;
lp->pdata = pdata;
lp->chipname = id->name;
lp->chip_id = id->driver_data;
i2c_set_clientdata(cl, lp);
ret = lp855x_init_registers(lp);
if (ret) {
dev_err(lp->dev, "i2c communication err: %d", ret);
if (mode == REGISTER_BASED)
goto err_dev;
}
ret = lp855x_backlight_register(lp);
if (ret) {
dev_err(lp->dev,
"failed to register backlight. err: %d\n", ret);
goto err_dev;
}
ret = sysfs_create_group(&lp->dev->kobj, &lp855x_attr_group);
if (ret) {
dev_err(lp->dev, "failed to register sysfs. err: %d\n", ret);
goto err_sysfs;
}
backlight_update_status(lp->bl);
return 0;
err_sysfs:
lp855x_backlight_unregister(lp);
err_dev:
return ret;
}
static int lp855x_remove(struct i2c_client *cl)
{
struct lp855x *lp = i2c_get_clientdata(cl);
lp->bl->props.brightness = 0;
backlight_update_status(lp->bl);
sysfs_remove_group(&lp->dev->kobj, &lp855x_attr_group);
lp855x_backlight_unregister(lp);
return 0;
}
