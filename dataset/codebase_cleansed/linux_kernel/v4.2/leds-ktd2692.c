static struct ktd2692_context *fled_cdev_to_led(
struct led_classdev_flash *fled_cdev)
{
return container_of(fled_cdev, struct ktd2692_context, fled_cdev);
}
static void ktd2692_expresswire_start(struct ktd2692_context *led)
{
gpiod_direction_output(led->ctrl_gpio, KTD2692_HIGH);
udelay(KTD2692_TIME_DATA_START_TIME_US);
}
static void ktd2692_expresswire_reset(struct ktd2692_context *led)
{
gpiod_direction_output(led->ctrl_gpio, KTD2692_LOW);
udelay(KTD2692_TIME_RESET_US);
}
static void ktd2692_expresswire_end(struct ktd2692_context *led)
{
gpiod_direction_output(led->ctrl_gpio, KTD2692_LOW);
udelay(KTD2692_TIME_LOW_END_OF_DATA_US);
gpiod_direction_output(led->ctrl_gpio, KTD2692_HIGH);
udelay(KTD2692_TIME_HIGH_END_OF_DATA_US);
}
static void ktd2692_expresswire_set_bit(struct ktd2692_context *led, bool bit)
{
if (bit) {
gpiod_direction_output(led->ctrl_gpio, KTD2692_LOW);
udelay(KTD2692_TIME_SHORT_BITSET_US);
gpiod_direction_output(led->ctrl_gpio, KTD2692_HIGH);
udelay(KTD2692_TIME_LONG_BITSET_US);
} else {
gpiod_direction_output(led->ctrl_gpio, KTD2692_LOW);
udelay(KTD2692_TIME_LONG_BITSET_US);
gpiod_direction_output(led->ctrl_gpio, KTD2692_HIGH);
udelay(KTD2692_TIME_SHORT_BITSET_US);
}
}
static void ktd2692_expresswire_write(struct ktd2692_context *led, u8 value)
{
int i;
ktd2692_expresswire_start(led);
for (i = 7; i >= 0; i--)
ktd2692_expresswire_set_bit(led, value & BIT(i));
ktd2692_expresswire_end(led);
}
static void ktd2692_brightness_set(struct ktd2692_context *led,
enum led_brightness brightness)
{
mutex_lock(&led->lock);
if (brightness == LED_OFF) {
led->mode = KTD2692_MODE_DISABLE;
gpiod_direction_output(led->aux_gpio, KTD2692_LOW);
} else {
ktd2692_expresswire_write(led, brightness |
KTD2692_REG_MOVIE_CURRENT_BASE);
led->mode = KTD2692_MODE_MOVIE;
}
ktd2692_expresswire_write(led, led->mode | KTD2692_REG_MODE_BASE);
mutex_unlock(&led->lock);
}
static void ktd2692_brightness_set_work(struct work_struct *work)
{
struct ktd2692_context *led =
container_of(work, struct ktd2692_context, work_brightness_set);
ktd2692_brightness_set(led, led->torch_brightness);
}
static void ktd2692_led_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
struct ktd2692_context *led = fled_cdev_to_led(fled_cdev);
led->torch_brightness = brightness;
schedule_work(&led->work_brightness_set);
}
static int ktd2692_led_brightness_set_sync(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct led_classdev_flash *fled_cdev = lcdev_to_flcdev(led_cdev);
struct ktd2692_context *led = fled_cdev_to_led(fled_cdev);
ktd2692_brightness_set(led, brightness);
return 0;
}
static int ktd2692_led_flash_strobe_set(struct led_classdev_flash *fled_cdev,
bool state)
{
struct ktd2692_context *led = fled_cdev_to_led(fled_cdev);
struct led_flash_setting *timeout = &fled_cdev->timeout;
u32 flash_tm_reg;
mutex_lock(&led->lock);
if (state) {
flash_tm_reg = GET_TIMEOUT_OFFSET(timeout->val, timeout->step);
ktd2692_expresswire_write(led, flash_tm_reg
| KTD2692_REG_FLASH_TIMEOUT_BASE);
led->mode = KTD2692_MODE_FLASH;
gpiod_direction_output(led->aux_gpio, KTD2692_HIGH);
} else {
led->mode = KTD2692_MODE_DISABLE;
gpiod_direction_output(led->aux_gpio, KTD2692_LOW);
}
ktd2692_expresswire_write(led, led->mode | KTD2692_REG_MODE_BASE);
fled_cdev->led_cdev.brightness = LED_OFF;
led->mode = KTD2692_MODE_DISABLE;
mutex_unlock(&led->lock);
return 0;
}
static int ktd2692_led_flash_timeout_set(struct led_classdev_flash *fled_cdev,
u32 timeout)
{
return 0;
}
static void ktd2692_init_movie_current_max(struct ktd2692_led_config_data *cfg)
{
u32 offset, step;
u32 movie_current_microamp;
offset = KTD2692_MOVIE_MODE_CURRENT_LEVELS;
step = KTD2692_MM_TO_FL_RATIO(cfg->flash_max_microamp)
/ KTD2692_MOVIE_MODE_CURRENT_LEVELS;
do {
movie_current_microamp = step * offset;
offset--;
} while ((movie_current_microamp > cfg->movie_max_microamp) &&
(offset > 0));
cfg->max_brightness = offset;
}
static void ktd2692_init_flash_timeout(struct led_classdev_flash *fled_cdev,
struct ktd2692_led_config_data *cfg)
{
struct led_flash_setting *setting;
setting = &fled_cdev->timeout;
setting->min = KTD2692_FLASH_MODE_TIMEOUT_DISABLE;
setting->max = cfg->flash_max_timeout;
setting->step = cfg->flash_max_timeout
/ (KTD2692_FLASH_MODE_TIMEOUT_LEVELS - 1);
setting->val = cfg->flash_max_timeout;
}
static void ktd2692_setup(struct ktd2692_context *led)
{
led->mode = KTD2692_MODE_DISABLE;
ktd2692_expresswire_reset(led);
gpiod_direction_output(led->aux_gpio, KTD2692_LOW);
ktd2692_expresswire_write(led, (KTD2962_MM_MIN_CURR_THRESHOLD_SCALE - 1)
| KTD2692_REG_MM_MIN_CURR_THRESHOLD_BASE);
ktd2692_expresswire_write(led, KTD2692_FLASH_MODE_CURR_PERCENT(45)
| KTD2692_REG_FLASH_CURRENT_BASE);
}
static int ktd2692_parse_dt(struct ktd2692_context *led, struct device *dev,
struct ktd2692_led_config_data *cfg)
{
struct device_node *np = dev->of_node;
struct device_node *child_node;
int ret;
if (!dev->of_node)
return -ENXIO;
led->ctrl_gpio = devm_gpiod_get(dev, "ctrl", GPIOD_ASIS);
if (IS_ERR(led->ctrl_gpio)) {
ret = PTR_ERR(led->ctrl_gpio);
dev_err(dev, "cannot get ctrl-gpios %d\n", ret);
return ret;
}
led->aux_gpio = devm_gpiod_get(dev, "aux", GPIOD_ASIS);
if (IS_ERR(led->aux_gpio)) {
ret = PTR_ERR(led->aux_gpio);
dev_err(dev, "cannot get aux-gpios %d\n", ret);
return ret;
}
led->regulator = devm_regulator_get(dev, "vin");
if (IS_ERR(led->regulator))
led->regulator = NULL;
if (led->regulator) {
ret = regulator_enable(led->regulator);
if (ret)
dev_err(dev, "Failed to enable supply: %d\n", ret);
}
child_node = of_get_next_available_child(np, NULL);
if (!child_node) {
dev_err(dev, "No DT child node found for connected LED.\n");
return -EINVAL;
}
led->fled_cdev.led_cdev.name =
of_get_property(child_node, "label", NULL) ? : child_node->name;
ret = of_property_read_u32(child_node, "led-max-microamp",
&cfg->movie_max_microamp);
if (ret) {
dev_err(dev, "failed to parse led-max-microamp\n");
return ret;
}
ret = of_property_read_u32(child_node, "flash-max-microamp",
&cfg->flash_max_microamp);
if (ret) {
dev_err(dev, "failed to parse flash-max-microamp\n");
return ret;
}
ret = of_property_read_u32(child_node, "flash-max-timeout-us",
&cfg->flash_max_timeout);
if (ret)
dev_err(dev, "failed to parse flash-max-timeout-us\n");
of_node_put(child_node);
return ret;
}
static int ktd2692_probe(struct platform_device *pdev)
{
struct ktd2692_context *led;
struct led_classdev *led_cdev;
struct led_classdev_flash *fled_cdev;
struct ktd2692_led_config_data led_cfg;
int ret;
led = devm_kzalloc(&pdev->dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
fled_cdev = &led->fled_cdev;
led_cdev = &fled_cdev->led_cdev;
ret = ktd2692_parse_dt(led, &pdev->dev, &led_cfg);
if (ret)
return ret;
ktd2692_init_flash_timeout(fled_cdev, &led_cfg);
ktd2692_init_movie_current_max(&led_cfg);
fled_cdev->ops = &flash_ops;
led_cdev->max_brightness = led_cfg.max_brightness;
led_cdev->brightness_set = ktd2692_led_brightness_set;
led_cdev->brightness_set_sync = ktd2692_led_brightness_set_sync;
led_cdev->flags |= LED_CORE_SUSPENDRESUME | LED_DEV_CAP_FLASH;
mutex_init(&led->lock);
INIT_WORK(&led->work_brightness_set, ktd2692_brightness_set_work);
platform_set_drvdata(pdev, led);
ret = led_classdev_flash_register(&pdev->dev, fled_cdev);
if (ret) {
dev_err(&pdev->dev, "can't register LED %s\n", led_cdev->name);
mutex_destroy(&led->lock);
return ret;
}
ktd2692_setup(led);
return 0;
}
static int ktd2692_remove(struct platform_device *pdev)
{
struct ktd2692_context *led = platform_get_drvdata(pdev);
int ret;
led_classdev_flash_unregister(&led->fled_cdev);
cancel_work_sync(&led->work_brightness_set);
if (led->regulator) {
ret = regulator_disable(led->regulator);
if (ret)
dev_err(&pdev->dev,
"Failed to disable supply: %d\n", ret);
}
mutex_destroy(&led->lock);
return 0;
}
