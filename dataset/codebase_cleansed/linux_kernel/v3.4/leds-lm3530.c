static int lm3530_get_mode_from_str(const char *str)
{
int i;
for (i = 0; i < ARRAY_SIZE(mode_map); i++)
if (sysfs_streq(str, mode_map[i].mode))
return mode_map[i].mode_val;
return -1;
}
static int lm3530_init_registers(struct lm3530_data *drvdata)
{
int ret = 0;
int i;
u8 gen_config;
u8 als_config = 0;
u8 brt_ramp;
u8 als_imp_sel = 0;
u8 brightness;
u8 reg_val[LM3530_REG_MAX];
u8 zones[LM3530_ALS_ZB_MAX];
u32 als_vmin, als_vmax, als_vstep;
struct lm3530_platform_data *pdata = drvdata->pdata;
struct i2c_client *client = drvdata->client;
struct lm3530_pwm_data *pwm = &pdata->pwm_data;
gen_config = (pdata->brt_ramp_law << LM3530_RAMP_LAW_SHIFT) |
((pdata->max_current & 7) << LM3530_MAX_CURR_SHIFT);
switch (drvdata->mode) {
case LM3530_BL_MODE_MANUAL:
case LM3530_BL_MODE_ALS:
gen_config |= LM3530_ENABLE_I2C;
break;
case LM3530_BL_MODE_PWM:
gen_config |= LM3530_ENABLE_PWM | LM3530_ENABLE_PWM_SIMPLE |
(pdata->pwm_pol_hi << LM3530_PWM_POL_SHIFT);
break;
}
if (drvdata->mode == LM3530_BL_MODE_ALS) {
if (pdata->als_vmax == 0) {
pdata->als_vmin = 0;
pdata->als_vmax = LM3530_ALS_WINDOW_mV;
}
als_vmin = pdata->als_vmin;
als_vmax = pdata->als_vmax;
if ((als_vmax - als_vmin) > LM3530_ALS_WINDOW_mV)
pdata->als_vmax = als_vmax =
als_vmin + LM3530_ALS_WINDOW_mV;
als_vstep = (als_vmax - als_vmin) / (LM3530_ALS_ZB_MAX + 1);
for (i = 0; i < LM3530_ALS_ZB_MAX; i++)
zones[i] = (((als_vmin + LM3530_ALS_OFFSET_mV) +
als_vstep + (i * als_vstep)) * LED_FULL)
/ 1000;
als_config =
(pdata->als_avrg_time << LM3530_ALS_AVG_TIME_SHIFT) |
(LM3530_ENABLE_ALS) |
(pdata->als_input_mode << LM3530_ALS_SEL_SHIFT);
als_imp_sel =
(pdata->als1_resistor_sel << LM3530_ALS1_IMP_SHIFT) |
(pdata->als2_resistor_sel << LM3530_ALS2_IMP_SHIFT);
}
brt_ramp = (pdata->brt_ramp_fall << LM3530_BRT_RAMP_FALL_SHIFT) |
(pdata->brt_ramp_rise << LM3530_BRT_RAMP_RISE_SHIFT);
if (drvdata->brightness)
brightness = drvdata->brightness;
else
brightness = drvdata->brightness = pdata->brt_val;
if (brightness > drvdata->led_dev.max_brightness)
brightness = drvdata->led_dev.max_brightness;
reg_val[0] = gen_config;
reg_val[1] = als_config;
reg_val[2] = brt_ramp;
reg_val[3] = als_imp_sel;
reg_val[4] = brightness;
reg_val[5] = zones[0];
reg_val[6] = zones[1];
reg_val[7] = zones[2];
reg_val[8] = zones[3];
reg_val[9] = LM3530_DEF_ZT_0;
reg_val[10] = LM3530_DEF_ZT_1;
reg_val[11] = LM3530_DEF_ZT_2;
reg_val[12] = LM3530_DEF_ZT_3;
reg_val[13] = LM3530_DEF_ZT_4;
if (!drvdata->enable) {
ret = regulator_enable(drvdata->regulator);
if (ret) {
dev_err(&drvdata->client->dev,
"Enable regulator failed\n");
return ret;
}
drvdata->enable = true;
}
for (i = 0; i < LM3530_REG_MAX; i++) {
if (lm3530_reg[i] == LM3530_BRT_CTRL_REG &&
drvdata->mode == LM3530_BL_MODE_PWM) {
if (pwm->pwm_set_intensity)
pwm->pwm_set_intensity(reg_val[i],
drvdata->led_dev.max_brightness);
continue;
}
ret = i2c_smbus_write_byte_data(client,
lm3530_reg[i], reg_val[i]);
if (ret)
break;
}
return ret;
}
static void lm3530_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brt_val)
{
int err;
struct lm3530_data *drvdata =
container_of(led_cdev, struct lm3530_data, led_dev);
struct lm3530_platform_data *pdata = drvdata->pdata;
struct lm3530_pwm_data *pwm = &pdata->pwm_data;
u8 max_brightness = led_cdev->max_brightness;
switch (drvdata->mode) {
case LM3530_BL_MODE_MANUAL:
if (!drvdata->enable) {
err = lm3530_init_registers(drvdata);
if (err) {
dev_err(&drvdata->client->dev,
"Register Init failed: %d\n", err);
break;
}
}
err = i2c_smbus_write_byte_data(drvdata->client,
LM3530_BRT_CTRL_REG, brt_val);
if (err)
dev_err(&drvdata->client->dev,
"Unable to set brightness: %d\n", err);
else
drvdata->brightness = brt_val;
if (brt_val == 0) {
err = regulator_disable(drvdata->regulator);
if (err)
dev_err(&drvdata->client->dev,
"Disable regulator failed\n");
drvdata->enable = false;
}
break;
case LM3530_BL_MODE_ALS:
break;
case LM3530_BL_MODE_PWM:
if (pwm->pwm_set_intensity)
pwm->pwm_set_intensity(brt_val, max_brightness);
break;
default:
break;
}
}
static ssize_t lm3530_mode_get(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3530_data *drvdata;
int i, len = 0;
drvdata = container_of(led_cdev, struct lm3530_data, led_dev);
for (i = 0; i < ARRAY_SIZE(mode_map); i++)
if (drvdata->mode == mode_map[i].mode_val)
len += sprintf(buf + len, "[%s] ", mode_map[i].mode);
else
len += sprintf(buf + len, "%s ", mode_map[i].mode);
len += sprintf(buf + len, "\n");
return len;
}
static ssize_t lm3530_mode_set(struct device *dev, struct device_attribute
*attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3530_data *drvdata;
struct lm3530_pwm_data *pwm;
u8 max_brightness;
int mode, err;
drvdata = container_of(led_cdev, struct lm3530_data, led_dev);
pwm = &drvdata->pdata->pwm_data;
max_brightness = led_cdev->max_brightness;
mode = lm3530_get_mode_from_str(buf);
if (mode < 0) {
dev_err(dev, "Invalid mode\n");
return -EINVAL;
}
drvdata->mode = mode;
if (mode != LM3530_BL_MODE_PWM && pwm->pwm_set_intensity)
pwm->pwm_set_intensity(0, max_brightness);
err = lm3530_init_registers(drvdata);
if (err) {
dev_err(dev, "Setting %s Mode failed :%d\n", buf, err);
return err;
}
return sizeof(drvdata->mode);
}
static int __devinit lm3530_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lm3530_platform_data *pdata = client->dev.platform_data;
struct lm3530_data *drvdata;
int err = 0;
if (pdata == NULL) {
dev_err(&client->dev, "platform data required\n");
err = -ENODEV;
goto err_out;
}
if (pdata->mode > LM3530_BL_MODE_PWM) {
dev_err(&client->dev, "Illegal Mode request\n");
err = -EINVAL;
goto err_out;
}
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "I2C_FUNC_I2C not supported\n");
err = -EIO;
goto err_out;
}
drvdata = kzalloc(sizeof(struct lm3530_data), GFP_KERNEL);
if (drvdata == NULL) {
err = -ENOMEM;
goto err_out;
}
drvdata->mode = pdata->mode;
drvdata->client = client;
drvdata->pdata = pdata;
drvdata->brightness = LED_OFF;
drvdata->enable = false;
drvdata->led_dev.name = LM3530_LED_DEV;
drvdata->led_dev.brightness_set = lm3530_brightness_set;
drvdata->led_dev.max_brightness = MAX_BRIGHTNESS;
i2c_set_clientdata(client, drvdata);
drvdata->regulator = regulator_get(&client->dev, "vin");
if (IS_ERR(drvdata->regulator)) {
dev_err(&client->dev, "regulator get failed\n");
err = PTR_ERR(drvdata->regulator);
drvdata->regulator = NULL;
goto err_regulator_get;
}
if (drvdata->pdata->brt_val) {
err = lm3530_init_registers(drvdata);
if (err < 0) {
dev_err(&client->dev,
"Register Init failed: %d\n", err);
err = -ENODEV;
goto err_reg_init;
}
}
err = led_classdev_register(&client->dev, &drvdata->led_dev);
if (err < 0) {
dev_err(&client->dev, "Register led class failed: %d\n", err);
err = -ENODEV;
goto err_class_register;
}
err = device_create_file(drvdata->led_dev.dev, &dev_attr_mode);
if (err < 0) {
dev_err(&client->dev, "File device creation failed: %d\n", err);
err = -ENODEV;
goto err_create_file;
}
return 0;
err_create_file:
led_classdev_unregister(&drvdata->led_dev);
err_class_register:
err_reg_init:
regulator_put(drvdata->regulator);
err_regulator_get:
kfree(drvdata);
err_out:
return err;
}
static int __devexit lm3530_remove(struct i2c_client *client)
{
struct lm3530_data *drvdata = i2c_get_clientdata(client);
device_remove_file(drvdata->led_dev.dev, &dev_attr_mode);
if (drvdata->enable)
regulator_disable(drvdata->regulator);
regulator_put(drvdata->regulator);
led_classdev_unregister(&drvdata->led_dev);
kfree(drvdata);
return 0;
}
