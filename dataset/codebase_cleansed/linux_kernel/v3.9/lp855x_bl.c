static int lp855x_write_byte(struct lp855x *lp, u8 reg, u8 data)
{
return i2c_smbus_write_byte_data(lp->client, reg, data);
}
static int lp855x_update_bit(struct lp855x *lp, u8 reg, u8 mask, u8 data)
{
int ret;
u8 tmp;
ret = i2c_smbus_read_byte_data(lp->client, reg);
if (ret < 0) {
dev_err(lp->dev, "failed to read 0x%.2x\n", reg);
return ret;
}
tmp = (u8)ret;
tmp &= ~mask;
tmp |= data & mask;
return lp855x_write_byte(lp, reg, tmp);
}
static bool lp855x_is_valid_rom_area(struct lp855x *lp, u8 addr)
{
u8 start, end;
switch (lp->chip_id) {
case LP8550:
case LP8551:
case LP8552:
case LP8553:
start = LP855X_EEPROM_START;
end = LP855X_EEPROM_END;
break;
case LP8556:
start = LP8556_EPROM_START;
end = LP8556_EPROM_END;
break;
case LP8557:
start = LP8557_EPROM_START;
end = LP8557_EPROM_END;
break;
default:
return false;
}
return (addr >= start && addr <= end);
}
static int lp8557_bl_off(struct lp855x *lp)
{
return lp855x_update_bit(lp, LP8557_BL_CMD, LP8557_BL_MASK,
LP8557_BL_OFF);
}
static int lp8557_bl_on(struct lp855x *lp)
{
return lp855x_update_bit(lp, LP8557_BL_CMD, LP8557_BL_MASK,
LP8557_BL_ON);
}
static int lp855x_configure(struct lp855x *lp)
{
u8 val, addr;
int i, ret;
struct lp855x_platform_data *pd = lp->pdata;
switch (lp->chip_id) {
case LP8550 ... LP8556:
lp->cfg = &lp855x_dev_cfg;
break;
case LP8557:
lp->cfg = &lp8557_dev_cfg;
break;
default:
return -EINVAL;
}
if (lp->cfg->pre_init_device) {
ret = lp->cfg->pre_init_device(lp);
if (ret) {
dev_err(lp->dev, "pre init device err: %d\n", ret);
goto err;
}
}
val = pd->initial_brightness;
ret = lp855x_write_byte(lp, lp->cfg->reg_brightness, val);
if (ret)
goto err;
val = pd->device_control;
ret = lp855x_write_byte(lp, lp->cfg->reg_devicectrl, val);
if (ret)
goto err;
if (pd->load_new_rom_data && pd->size_program) {
for (i = 0; i < pd->size_program; i++) {
addr = pd->rom_data[i].addr;
val = pd->rom_data[i].val;
if (!lp855x_is_valid_rom_area(lp, addr))
continue;
ret = lp855x_write_byte(lp, addr, val);
if (ret)
goto err;
}
}
if (lp->cfg->post_init_device) {
ret = lp->cfg->post_init_device(lp);
if (ret) {
dev_err(lp->dev, "post init device err: %d\n", ret);
goto err;
}
}
return 0;
err:
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
lp855x_write_byte(lp, lp->cfg->reg_brightness, val);
}
return 0;
}
static int lp855x_bl_get_brightness(struct backlight_device *bl)
{
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
ret = lp855x_configure(lp);
if (ret) {
dev_err(lp->dev, "device config err: %d", ret);
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
