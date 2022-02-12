static inline int wled_a(int port)
{
int ret;
ret = ((port - PM8606_BACKLIGHT1) << 1) + 2;
return ret;
}
static inline int wled_b(int port)
{
int ret;
ret = ((port - PM8606_BACKLIGHT1) << 1) + 3;
return ret;
}
static inline int wled_idc(int port)
{
int ret;
switch (port) {
case PM8606_BACKLIGHT1:
case PM8606_BACKLIGHT2:
ret = ((port - PM8606_BACKLIGHT1) << 1) + 3;
break;
case PM8606_BACKLIGHT3:
default:
ret = ((port - PM8606_BACKLIGHT2) << 1) + 3;
break;
}
return ret;
}
static int pm860x_backlight_set(struct backlight_device *bl, int brightness)
{
struct pm860x_backlight_data *data = bl_get_data(bl);
struct pm860x_chip *chip = data->chip;
unsigned char value;
int ret;
if (brightness > MAX_BRIGHTNESS)
value = MAX_BRIGHTNESS;
else
value = brightness;
ret = pm860x_reg_write(data->i2c, wled_a(data->port), value);
if (ret < 0)
goto out;
if ((data->current_brightness == 0) && brightness) {
if (data->iset) {
ret = pm860x_set_bits(data->i2c, wled_idc(data->port),
CURRENT_BITMASK, data->iset);
if (ret < 0)
goto out;
}
if (data->pwm) {
ret = pm860x_set_bits(data->i2c, PM8606_PWM,
PM8606_PWM_FREQ_MASK, data->pwm);
if (ret < 0)
goto out;
}
if (brightness == MAX_BRIGHTNESS) {
ret = pm860x_set_bits(data->i2c, wled_b(data->port),
PM8606_WLED_ON, PM8606_WLED_ON);
}
} else {
if (brightness == MAX_BRIGHTNESS) {
ret = pm860x_set_bits(data->i2c, wled_b(data->port),
PM8606_WLED_ON, PM8606_WLED_ON);
} else {
ret = pm860x_set_bits(data->i2c, wled_b(data->port),
PM8606_WLED_ON, 0);
}
}
if (ret < 0)
goto out;
dev_dbg(chip->dev, "set brightness %d\n", value);
data->current_brightness = value;
return 0;
out:
dev_dbg(chip->dev, "set brightness %d failure with return "
"value:%d\n", value, ret);
return ret;
}
static int pm860x_backlight_update_status(struct backlight_device *bl)
{
int brightness = bl->props.brightness;
if (bl->props.power != FB_BLANK_UNBLANK)
brightness = 0;
if (bl->props.fb_blank != FB_BLANK_UNBLANK)
brightness = 0;
if (bl->props.state & BL_CORE_SUSPENDED)
brightness = 0;
return pm860x_backlight_set(bl, brightness);
}
static int pm860x_backlight_get_brightness(struct backlight_device *bl)
{
struct pm860x_backlight_data *data = bl_get_data(bl);
struct pm860x_chip *chip = data->chip;
int ret;
ret = pm860x_reg_read(data->i2c, wled_a(data->port));
if (ret < 0)
goto out;
data->current_brightness = ret;
dev_dbg(chip->dev, "get brightness %d\n", data->current_brightness);
return data->current_brightness;
out:
return -EINVAL;
}
static int pm860x_backlight_probe(struct platform_device *pdev)
{
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct pm860x_backlight_pdata *pdata = NULL;
struct pm860x_backlight_data *data;
struct backlight_device *bl;
struct resource *res;
struct backlight_properties props;
unsigned char value;
char name[MFD_NAME_SIZE];
int ret;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (res == NULL) {
dev_err(&pdev->dev, "No I/O resource!\n");
return -EINVAL;
}
pdata = pdev->dev.platform_data;
if (pdata == NULL) {
dev_err(&pdev->dev, "platform data isn't assigned to "
"backlight\n");
return -EINVAL;
}
data = kzalloc(sizeof(struct pm860x_backlight_data), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
strncpy(name, res->name, MFD_NAME_SIZE);
data->chip = chip;
data->i2c = (chip->id == CHIP_PM8606) ? chip->client \
: chip->companion;
data->current_brightness = MAX_BRIGHTNESS;
data->pwm = pdata->pwm;
data->iset = pdata->iset;
data->port = pdata->flags;
if (data->port < 0) {
dev_err(&pdev->dev, "wrong platform data is assigned");
kfree(data);
return -EINVAL;
}
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = MAX_BRIGHTNESS;
bl = backlight_device_register(name, &pdev->dev, data,
&pm860x_backlight_ops, &props);
if (IS_ERR(bl)) {
dev_err(&pdev->dev, "failed to register backlight\n");
kfree(data);
return PTR_ERR(bl);
}
bl->props.brightness = MAX_BRIGHTNESS;
platform_set_drvdata(pdev, bl);
ret = pm860x_reg_read(data->i2c, PM8606_VSYS);
if (ret < 0)
goto out;
if ((ret & PM8606_VSYS_EN) == 0) {
value = ret | PM8606_VSYS_EN;
ret = pm860x_reg_write(data->i2c, PM8606_VSYS, value);
if (ret < 0)
goto out;
}
ret = pm860x_reg_read(data->i2c, PM8606_MISC);
if (ret < 0)
goto out;
if ((ret & PM8606_MISC_OSC_EN) == 0) {
value = ret | PM8606_MISC_OSC_EN;
ret = pm860x_reg_write(data->i2c, PM8606_MISC, value);
if (ret < 0)
goto out;
}
ret = pm860x_backlight_get_brightness(bl);
if (ret < 0)
goto out;
backlight_update_status(bl);
return 0;
out:
backlight_device_unregister(bl);
kfree(data);
return ret;
}
static int pm860x_backlight_remove(struct platform_device *pdev)
{
struct backlight_device *bl = platform_get_drvdata(pdev);
struct pm860x_backlight_data *data = bl_get_data(bl);
backlight_device_unregister(bl);
kfree(data);
return 0;
}
