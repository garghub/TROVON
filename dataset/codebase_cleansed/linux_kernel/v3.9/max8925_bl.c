static int max8925_backlight_set(struct backlight_device *bl, int brightness)
{
struct max8925_backlight_data *data = bl_get_data(bl);
struct max8925_chip *chip = data->chip;
unsigned char value;
int ret;
if (brightness > MAX_BRIGHTNESS)
value = MAX_BRIGHTNESS;
else
value = brightness;
ret = max8925_reg_write(chip->i2c, data->reg_cntl, value);
if (ret < 0)
goto out;
if (!data->current_brightness && brightness)
ret = max8925_set_bits(chip->i2c, data->reg_mode_cntl, 1, 1);
else if (!brightness)
ret = max8925_set_bits(chip->i2c, data->reg_mode_cntl, 1, 0);
if (ret < 0)
goto out;
dev_dbg(chip->dev, "set brightness %d\n", value);
data->current_brightness = value;
return 0;
out:
dev_dbg(chip->dev, "set brightness %d failure with return value:%d\n",
value, ret);
return ret;
}
static int max8925_backlight_update_status(struct backlight_device *bl)
{
int brightness = bl->props.brightness;
if (bl->props.power != FB_BLANK_UNBLANK)
brightness = 0;
if (bl->props.fb_blank != FB_BLANK_UNBLANK)
brightness = 0;
if (bl->props.state & BL_CORE_SUSPENDED)
brightness = 0;
return max8925_backlight_set(bl, brightness);
}
static int max8925_backlight_get_brightness(struct backlight_device *bl)
{
struct max8925_backlight_data *data = bl_get_data(bl);
struct max8925_chip *chip = data->chip;
int ret;
ret = max8925_reg_read(chip->i2c, data->reg_cntl);
if (ret < 0)
return -EINVAL;
data->current_brightness = ret;
dev_dbg(chip->dev, "get brightness %d\n", data->current_brightness);
return ret;
}
static int max8925_backlight_dt_init(struct platform_device *pdev,
struct max8925_backlight_pdata *pdata)
{
struct device_node *nproot = pdev->dev.parent->of_node, *np;
int dual_string;
if (!nproot)
return -ENODEV;
np = of_find_node_by_name(nproot, "backlight");
if (!np) {
dev_err(&pdev->dev, "failed to find backlight node\n");
return -ENODEV;
}
of_property_read_u32(np, "maxim,max8925-dual-string", &dual_string);
pdata->dual_string = dual_string;
return 0;
}
static int max8925_backlight_probe(struct platform_device *pdev)
{
struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct max8925_backlight_pdata *pdata = pdev->dev.platform_data;
struct max8925_backlight_data *data;
struct backlight_device *bl;
struct backlight_properties props;
struct resource *res;
unsigned char value;
int ret = 0;
data = devm_kzalloc(&pdev->dev, sizeof(struct max8925_backlight_data),
GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_REG, 0);
if (!res) {
dev_err(&pdev->dev, "No REG resource for mode control!\n");
return -ENXIO;
}
data->reg_mode_cntl = res->start;
res = platform_get_resource(pdev, IORESOURCE_REG, 1);
if (!res) {
dev_err(&pdev->dev, "No REG resource for control!\n");
return -ENXIO;
}
data->reg_cntl = res->start;
data->chip = chip;
data->current_brightness = 0;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = MAX_BRIGHTNESS;
bl = backlight_device_register("max8925-backlight", &pdev->dev, data,
&max8925_backlight_ops, &props);
if (IS_ERR(bl)) {
dev_err(&pdev->dev, "failed to register backlight\n");
return PTR_ERR(bl);
}
bl->props.brightness = MAX_BRIGHTNESS;
platform_set_drvdata(pdev, bl);
value = 0;
if (pdev->dev.parent->of_node && !pdata) {
pdata = devm_kzalloc(&pdev->dev,
sizeof(struct max8925_backlight_pdata),
GFP_KERNEL);
max8925_backlight_dt_init(pdev, pdata);
}
if (pdata) {
if (pdata->lxw_scl)
value |= (1 << 7);
if (pdata->lxw_freq)
value |= (LWX_FREQ(pdata->lxw_freq) << 4);
if (pdata->dual_string)
value |= (1 << 1);
}
ret = max8925_set_bits(chip->i2c, data->reg_mode_cntl, 0xfe, value);
if (ret < 0)
goto out_brt;
backlight_update_status(bl);
return 0;
out_brt:
backlight_device_unregister(bl);
return ret;
}
static int max8925_backlight_remove(struct platform_device *pdev)
{
struct backlight_device *bl = platform_get_drvdata(pdev);
backlight_device_unregister(bl);
return 0;
}
