static void pwm_backlight_power_on(struct pwm_bl_data *pb, int brightness)
{
int err;
if (pb->enabled)
return;
err = regulator_enable(pb->power_supply);
if (err < 0)
dev_err(pb->dev, "failed to enable power supply\n");
if (pb->enable_gpio)
gpiod_set_value_cansleep(pb->enable_gpio, 1);
pwm_enable(pb->pwm);
pb->enabled = true;
}
static void pwm_backlight_power_off(struct pwm_bl_data *pb)
{
if (!pb->enabled)
return;
pwm_config(pb->pwm, 0, pb->period);
pwm_disable(pb->pwm);
if (pb->enable_gpio)
gpiod_set_value_cansleep(pb->enable_gpio, 0);
regulator_disable(pb->power_supply);
pb->enabled = false;
}
static int compute_duty_cycle(struct pwm_bl_data *pb, int brightness)
{
unsigned int lth = pb->lth_brightness;
int duty_cycle;
if (pb->levels)
duty_cycle = pb->levels[brightness];
else
duty_cycle = brightness;
return (duty_cycle * (pb->period - lth) / pb->scale) + lth;
}
static int pwm_backlight_update_status(struct backlight_device *bl)
{
struct pwm_bl_data *pb = bl_get_data(bl);
int brightness = bl->props.brightness;
int duty_cycle;
if (bl->props.power != FB_BLANK_UNBLANK ||
bl->props.fb_blank != FB_BLANK_UNBLANK ||
bl->props.state & BL_CORE_FBBLANK)
brightness = 0;
if (pb->notify)
brightness = pb->notify(pb->dev, brightness);
if (brightness > 0) {
duty_cycle = compute_duty_cycle(pb, brightness);
pwm_config(pb->pwm, duty_cycle, pb->period);
pwm_backlight_power_on(pb, brightness);
} else
pwm_backlight_power_off(pb);
if (pb->notify_after)
pb->notify_after(pb->dev, brightness);
return 0;
}
static int pwm_backlight_check_fb(struct backlight_device *bl,
struct fb_info *info)
{
struct pwm_bl_data *pb = bl_get_data(bl);
return !pb->check_fb || pb->check_fb(pb->dev, info);
}
static int pwm_backlight_parse_dt(struct device *dev,
struct platform_pwm_backlight_data *data)
{
struct device_node *node = dev->of_node;
struct property *prop;
int length;
u32 value;
int ret;
if (!node)
return -ENODEV;
memset(data, 0, sizeof(*data));
prop = of_find_property(node, "brightness-levels", &length);
if (!prop)
return -EINVAL;
data->max_brightness = length / sizeof(u32);
if (data->max_brightness > 0) {
size_t size = sizeof(*data->levels) * data->max_brightness;
data->levels = devm_kzalloc(dev, size, GFP_KERNEL);
if (!data->levels)
return -ENOMEM;
ret = of_property_read_u32_array(node, "brightness-levels",
data->levels,
data->max_brightness);
if (ret < 0)
return ret;
ret = of_property_read_u32(node, "default-brightness-level",
&value);
if (ret < 0)
return ret;
data->dft_brightness = value;
data->max_brightness--;
}
data->enable_gpio = -EINVAL;
return 0;
}
static int pwm_backlight_parse_dt(struct device *dev,
struct platform_pwm_backlight_data *data)
{
return -ENODEV;
}
static int pwm_backlight_probe(struct platform_device *pdev)
{
struct platform_pwm_backlight_data *data = dev_get_platdata(&pdev->dev);
struct platform_pwm_backlight_data defdata;
struct backlight_properties props;
struct backlight_device *bl;
struct device_node *node = pdev->dev.of_node;
struct pwm_bl_data *pb;
int initial_blank = FB_BLANK_UNBLANK;
struct pwm_args pargs;
int ret;
if (!data) {
ret = pwm_backlight_parse_dt(&pdev->dev, &defdata);
if (ret < 0) {
dev_err(&pdev->dev, "failed to find platform data\n");
return ret;
}
data = &defdata;
}
if (data->init) {
ret = data->init(&pdev->dev);
if (ret < 0)
return ret;
}
pb = devm_kzalloc(&pdev->dev, sizeof(*pb), GFP_KERNEL);
if (!pb) {
ret = -ENOMEM;
goto err_alloc;
}
if (data->levels) {
unsigned int i;
for (i = 0; i <= data->max_brightness; i++)
if (data->levels[i] > pb->scale)
pb->scale = data->levels[i];
pb->levels = data->levels;
} else
pb->scale = data->max_brightness;
pb->notify = data->notify;
pb->notify_after = data->notify_after;
pb->check_fb = data->check_fb;
pb->exit = data->exit;
pb->dev = &pdev->dev;
pb->enabled = false;
pb->enable_gpio = devm_gpiod_get_optional(&pdev->dev, "enable",
GPIOD_ASIS);
if (IS_ERR(pb->enable_gpio)) {
ret = PTR_ERR(pb->enable_gpio);
goto err_alloc;
}
if (!pb->enable_gpio && gpio_is_valid(data->enable_gpio)) {
ret = devm_gpio_request_one(&pdev->dev, data->enable_gpio,
GPIOF_OUT_INIT_HIGH, "enable");
if (ret < 0) {
dev_err(&pdev->dev, "failed to request GPIO#%d: %d\n",
data->enable_gpio, ret);
goto err_alloc;
}
pb->enable_gpio = gpio_to_desc(data->enable_gpio);
}
if (pb->enable_gpio) {
if (node && node->phandle &&
gpiod_get_direction(pb->enable_gpio) == GPIOF_DIR_OUT &&
gpiod_get_value(pb->enable_gpio) == 0)
initial_blank = FB_BLANK_POWERDOWN;
else
gpiod_direction_output(pb->enable_gpio, 1);
}
pb->power_supply = devm_regulator_get(&pdev->dev, "power");
if (IS_ERR(pb->power_supply)) {
ret = PTR_ERR(pb->power_supply);
goto err_alloc;
}
if (node && node->phandle && !regulator_is_enabled(pb->power_supply))
initial_blank = FB_BLANK_POWERDOWN;
pb->pwm = devm_pwm_get(&pdev->dev, NULL);
if (IS_ERR(pb->pwm) && PTR_ERR(pb->pwm) != -EPROBE_DEFER && !node) {
dev_err(&pdev->dev, "unable to request PWM, trying legacy API\n");
pb->legacy = true;
pb->pwm = pwm_request(data->pwm_id, "pwm-backlight");
}
if (IS_ERR(pb->pwm)) {
ret = PTR_ERR(pb->pwm);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "unable to request PWM\n");
goto err_alloc;
}
dev_dbg(&pdev->dev, "got pwm for backlight\n");
pwm_apply_args(pb->pwm);
pwm_get_args(pb->pwm, &pargs);
pb->period = pargs.period;
if (!pb->period && (data->pwm_period_ns > 0))
pb->period = data->pwm_period_ns;
pb->lth_brightness = data->lth_brightness * (pb->period / pb->scale);
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = data->max_brightness;
bl = backlight_device_register(dev_name(&pdev->dev), &pdev->dev, pb,
&pwm_backlight_ops, &props);
if (IS_ERR(bl)) {
dev_err(&pdev->dev, "failed to register backlight\n");
ret = PTR_ERR(bl);
if (pb->legacy)
pwm_free(pb->pwm);
goto err_alloc;
}
if (data->dft_brightness > data->max_brightness) {
dev_warn(&pdev->dev,
"invalid default brightness level: %u, using %u\n",
data->dft_brightness, data->max_brightness);
data->dft_brightness = data->max_brightness;
}
bl->props.brightness = data->dft_brightness;
bl->props.power = initial_blank;
backlight_update_status(bl);
platform_set_drvdata(pdev, bl);
return 0;
err_alloc:
if (data->exit)
data->exit(&pdev->dev);
return ret;
}
static int pwm_backlight_remove(struct platform_device *pdev)
{
struct backlight_device *bl = platform_get_drvdata(pdev);
struct pwm_bl_data *pb = bl_get_data(bl);
backlight_device_unregister(bl);
pwm_backlight_power_off(pb);
if (pb->exit)
pb->exit(&pdev->dev);
if (pb->legacy)
pwm_free(pb->pwm);
return 0;
}
static void pwm_backlight_shutdown(struct platform_device *pdev)
{
struct backlight_device *bl = platform_get_drvdata(pdev);
struct pwm_bl_data *pb = bl_get_data(bl);
pwm_backlight_power_off(pb);
}
static int pwm_backlight_suspend(struct device *dev)
{
struct backlight_device *bl = dev_get_drvdata(dev);
struct pwm_bl_data *pb = bl_get_data(bl);
if (pb->notify)
pb->notify(pb->dev, 0);
pwm_backlight_power_off(pb);
if (pb->notify_after)
pb->notify_after(pb->dev, 0);
return 0;
}
static int pwm_backlight_resume(struct device *dev)
{
struct backlight_device *bl = dev_get_drvdata(dev);
backlight_update_status(bl);
return 0;
}
