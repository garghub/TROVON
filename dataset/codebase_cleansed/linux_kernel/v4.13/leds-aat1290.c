static struct aat1290_led *fled_cdev_to_led(
struct led_classdev_flash *fled_cdev)
{
return container_of(fled_cdev, struct aat1290_led, fled_cdev);
}
static struct led_classdev_flash *led_cdev_to_fled_cdev(
struct led_classdev *led_cdev)
{
return container_of(led_cdev, struct led_classdev_flash, led_cdev);
}
static void aat1290_as2cwire_write(struct aat1290_led *led, int addr, int value)
{
int i;
gpiod_direction_output(led->gpio_fl_en, 0);
gpiod_direction_output(led->gpio_en_set, 0);
udelay(AAT1290_FLEN_OFF_DELAY_TIME_US);
for (i = 0; i < addr; ++i) {
udelay(AAT1290_EN_SET_TICK_TIME_US);
gpiod_direction_output(led->gpio_en_set, 0);
udelay(AAT1290_EN_SET_TICK_TIME_US);
gpiod_direction_output(led->gpio_en_set, 1);
}
usleep_range(AAT1290_LATCH_TIME_MIN_US, AAT1290_LATCH_TIME_MAX_US);
for (i = 0; i < value; ++i) {
udelay(AAT1290_EN_SET_TICK_TIME_US);
gpiod_direction_output(led->gpio_en_set, 0);
udelay(AAT1290_EN_SET_TICK_TIME_US);
gpiod_direction_output(led->gpio_en_set, 1);
}
usleep_range(AAT1290_LATCH_TIME_MIN_US, AAT1290_LATCH_TIME_MAX_US);
}
static void aat1290_set_flash_safety_timer(struct aat1290_led *led,
unsigned int micro_sec)
{
struct led_classdev_flash *fled_cdev = &led->fled_cdev;
struct led_flash_setting *flash_tm = &fled_cdev->timeout;
int flash_tm_reg = AAT1290_FLASH_TM_NUM_LEVELS -
(micro_sec / flash_tm->step) + 1;
aat1290_as2cwire_write(led, AAT1290_FLASH_SAFETY_TIMER_ADDR,
flash_tm_reg);
}
static int aat1290_led_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct led_classdev_flash *fled_cdev = led_cdev_to_fled_cdev(led_cdev);
struct aat1290_led *led = fled_cdev_to_led(fled_cdev);
mutex_lock(&led->lock);
if (brightness == 0) {
gpiod_direction_output(led->gpio_fl_en, 0);
gpiod_direction_output(led->gpio_en_set, 0);
led->movie_mode = false;
} else {
if (!led->movie_mode) {
aat1290_as2cwire_write(led,
AAT1290_MM_CURRENT_RATIO_ADDR,
AAT1290_MM_TO_FL_1_92);
led->movie_mode = true;
}
aat1290_as2cwire_write(led, AAT1290_MOVIE_MODE_CURRENT_ADDR,
AAT1290_MAX_MM_CURR_PERCENT_0 - brightness);
aat1290_as2cwire_write(led, AAT1290_MOVIE_MODE_CONFIG_ADDR,
AAT1290_MOVIE_MODE_ON);
}
mutex_unlock(&led->lock);
return 0;
}
static int aat1290_led_flash_strobe_set(struct led_classdev_flash *fled_cdev,
bool state)
{
struct aat1290_led *led = fled_cdev_to_led(fled_cdev);
struct led_classdev *led_cdev = &fled_cdev->led_cdev;
struct led_flash_setting *timeout = &fled_cdev->timeout;
mutex_lock(&led->lock);
if (state) {
aat1290_set_flash_safety_timer(led, timeout->val);
gpiod_direction_output(led->gpio_fl_en, 1);
} else {
gpiod_direction_output(led->gpio_fl_en, 0);
gpiod_direction_output(led->gpio_en_set, 0);
}
led_cdev->brightness = 0;
led->movie_mode = false;
mutex_unlock(&led->lock);
return 0;
}
static int aat1290_led_flash_timeout_set(struct led_classdev_flash *fled_cdev,
u32 timeout)
{
return 0;
}
static int aat1290_led_parse_dt(struct aat1290_led *led,
struct aat1290_led_config_data *cfg,
struct device_node **sub_node)
{
struct led_classdev *led_cdev = &led->fled_cdev.led_cdev;
struct device *dev = &led->pdev->dev;
struct device_node *child_node;
#if IS_ENABLED(CONFIG_V4L2_FLASH_LED_CLASS)
struct pinctrl *pinctrl;
#endif
int ret = 0;
led->gpio_fl_en = devm_gpiod_get(dev, "flen", GPIOD_ASIS);
if (IS_ERR(led->gpio_fl_en)) {
ret = PTR_ERR(led->gpio_fl_en);
dev_err(dev, "Unable to claim gpio \"flen\".\n");
return ret;
}
led->gpio_en_set = devm_gpiod_get(dev, "enset", GPIOD_ASIS);
if (IS_ERR(led->gpio_en_set)) {
ret = PTR_ERR(led->gpio_en_set);
dev_err(dev, "Unable to claim gpio \"enset\".\n");
return ret;
}
#if IS_ENABLED(CONFIG_V4L2_FLASH_LED_CLASS)
pinctrl = devm_pinctrl_get_select_default(&led->pdev->dev);
if (IS_ERR(pinctrl)) {
cfg->has_external_strobe = false;
dev_info(dev,
"No support for external strobe detected.\n");
} else {
cfg->has_external_strobe = true;
}
#endif
child_node = of_get_next_available_child(dev->of_node, NULL);
if (!child_node) {
dev_err(dev, "No DT child node found for connected LED.\n");
return -EINVAL;
}
led_cdev->name = of_get_property(child_node, "label", NULL) ? :
child_node->name;
ret = of_property_read_u32(child_node, "led-max-microamp",
&cfg->max_mm_current);
if (ret < 0)
dev_warn(dev,
"led-max-microamp DT property missing\n");
ret = of_property_read_u32(child_node, "flash-max-microamp",
&cfg->max_flash_current);
if (ret < 0) {
dev_err(dev,
"flash-max-microamp DT property missing\n");
goto err_parse_dt;
}
ret = of_property_read_u32(child_node, "flash-max-timeout-us",
&cfg->max_flash_tm);
if (ret < 0) {
dev_err(dev,
"flash-max-timeout-us DT property missing\n");
goto err_parse_dt;
}
*sub_node = child_node;
err_parse_dt:
of_node_put(child_node);
return ret;
}
static void aat1290_led_validate_mm_current(struct aat1290_led *led,
struct aat1290_led_config_data *cfg)
{
int i, b = 0, e = AAT1290_MM_CURRENT_SCALE_SIZE;
while (e - b > 1) {
i = b + (e - b) / 2;
if (cfg->max_mm_current < led->mm_current_scale[i])
e = i;
else
b = i;
}
cfg->max_mm_current = led->mm_current_scale[b];
cfg->max_brightness = b + 1;
}
static int init_mm_current_scale(struct aat1290_led *led,
struct aat1290_led_config_data *cfg)
{
int max_mm_current_percent[] = { 20, 22, 25, 28, 32, 36, 40, 45, 50, 56,
63, 71, 79, 89, 100 };
int i, max_mm_current =
AAT1290_MAX_MM_CURRENT(cfg->max_flash_current);
led->mm_current_scale = devm_kzalloc(&led->pdev->dev,
sizeof(max_mm_current_percent),
GFP_KERNEL);
if (!led->mm_current_scale)
return -ENOMEM;
for (i = 0; i < AAT1290_MM_CURRENT_SCALE_SIZE; ++i)
led->mm_current_scale[i] = max_mm_current *
max_mm_current_percent[i] / 100;
return 0;
}
static int aat1290_led_get_configuration(struct aat1290_led *led,
struct aat1290_led_config_data *cfg,
struct device_node **sub_node)
{
int ret;
ret = aat1290_led_parse_dt(led, cfg, sub_node);
if (ret < 0)
return ret;
ret = init_mm_current_scale(led, cfg);
if (ret < 0)
return ret;
aat1290_led_validate_mm_current(led, cfg);
#if IS_ENABLED(CONFIG_V4L2_FLASH_LED_CLASS)
#else
devm_kfree(&led->pdev->dev, led->mm_current_scale);
#endif
return 0;
}
static void aat1290_init_flash_timeout(struct aat1290_led *led,
struct aat1290_led_config_data *cfg)
{
struct led_classdev_flash *fled_cdev = &led->fled_cdev;
struct led_flash_setting *setting;
setting = &fled_cdev->timeout;
setting->min = cfg->max_flash_tm / AAT1290_FLASH_TM_NUM_LEVELS;
setting->max = cfg->max_flash_tm;
setting->step = setting->min;
setting->val = setting->max;
}
static enum led_brightness aat1290_intensity_to_brightness(
struct v4l2_flash *v4l2_flash,
s32 intensity)
{
struct led_classdev_flash *fled_cdev = v4l2_flash->fled_cdev;
struct aat1290_led *led = fled_cdev_to_led(fled_cdev);
int i;
for (i = AAT1290_MM_CURRENT_SCALE_SIZE - 1; i >= 0; --i)
if (intensity >= led->mm_current_scale[i])
return i + 1;
return 1;
}
static s32 aat1290_brightness_to_intensity(struct v4l2_flash *v4l2_flash,
enum led_brightness brightness)
{
struct led_classdev_flash *fled_cdev = v4l2_flash->fled_cdev;
struct aat1290_led *led = fled_cdev_to_led(fled_cdev);
return led->mm_current_scale[brightness - 1];
}
static int aat1290_led_external_strobe_set(struct v4l2_flash *v4l2_flash,
bool enable)
{
struct aat1290_led *led = fled_cdev_to_led(v4l2_flash->fled_cdev);
struct led_classdev_flash *fled_cdev = v4l2_flash->fled_cdev;
struct led_classdev *led_cdev = &fled_cdev->led_cdev;
struct pinctrl *pinctrl;
gpiod_direction_output(led->gpio_fl_en, 0);
gpiod_direction_output(led->gpio_en_set, 0);
led->movie_mode = false;
led_cdev->brightness = 0;
pinctrl = devm_pinctrl_get_select(&led->pdev->dev,
enable ? "isp" : "host");
if (IS_ERR(pinctrl)) {
dev_warn(&led->pdev->dev, "Unable to switch strobe source.\n");
return PTR_ERR(pinctrl);
}
return 0;
}
static void aat1290_init_v4l2_flash_config(struct aat1290_led *led,
struct aat1290_led_config_data *led_cfg,
struct v4l2_flash_config *v4l2_sd_cfg)
{
struct led_classdev *led_cdev = &led->fled_cdev.led_cdev;
struct led_flash_setting *s;
strlcpy(v4l2_sd_cfg->dev_name, led_cdev->name,
sizeof(v4l2_sd_cfg->dev_name));
s = &v4l2_sd_cfg->torch_intensity;
s->min = led->mm_current_scale[0];
s->max = led_cfg->max_mm_current;
s->step = 1;
s->val = s->max;
v4l2_sd_cfg->has_external_strobe = led_cfg->has_external_strobe;
}
static inline void aat1290_init_v4l2_flash_config(struct aat1290_led *led,
struct aat1290_led_config_data *led_cfg,
struct v4l2_flash_config *v4l2_sd_cfg)
{
}
static int aat1290_led_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *sub_node = NULL;
struct aat1290_led *led;
struct led_classdev *led_cdev;
struct led_classdev_flash *fled_cdev;
struct aat1290_led_config_data led_cfg = {};
struct v4l2_flash_config v4l2_sd_cfg = {};
int ret;
led = devm_kzalloc(dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
led->pdev = pdev;
platform_set_drvdata(pdev, led);
fled_cdev = &led->fled_cdev;
fled_cdev->ops = &flash_ops;
led_cdev = &fled_cdev->led_cdev;
ret = aat1290_led_get_configuration(led, &led_cfg, &sub_node);
if (ret < 0)
return ret;
mutex_init(&led->lock);
led_cdev->brightness_set_blocking = aat1290_led_brightness_set;
led_cdev->max_brightness = led_cfg.max_brightness;
led_cdev->flags |= LED_DEV_CAP_FLASH;
aat1290_init_flash_timeout(led, &led_cfg);
ret = led_classdev_flash_register(&pdev->dev, fled_cdev);
if (ret < 0)
goto err_flash_register;
aat1290_init_v4l2_flash_config(led, &led_cfg, &v4l2_sd_cfg);
led->v4l2_flash = v4l2_flash_init(dev, of_fwnode_handle(sub_node),
fled_cdev, NULL, &v4l2_flash_ops,
&v4l2_sd_cfg);
if (IS_ERR(led->v4l2_flash)) {
ret = PTR_ERR(led->v4l2_flash);
goto error_v4l2_flash_init;
}
return 0;
error_v4l2_flash_init:
led_classdev_flash_unregister(fled_cdev);
err_flash_register:
mutex_destroy(&led->lock);
return ret;
}
static int aat1290_led_remove(struct platform_device *pdev)
{
struct aat1290_led *led = platform_get_drvdata(pdev);
v4l2_flash_release(led->v4l2_flash);
led_classdev_flash_unregister(&led->fled_cdev);
mutex_destroy(&led->lock);
return 0;
}
