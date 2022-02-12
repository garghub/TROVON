static inline struct lm3533_led *to_lm3533_led(struct led_classdev *cdev)
{
return container_of(cdev, struct lm3533_led, cdev);
}
static inline int lm3533_led_get_ctrlbank_id(struct lm3533_led *led)
{
return led->id + 2;
}
static inline u8 lm3533_led_get_lv_reg(struct lm3533_led *led, u8 base)
{
return base + led->id;
}
static inline u8 lm3533_led_get_pattern(struct lm3533_led *led)
{
return led->id;
}
static inline u8 lm3533_led_get_pattern_reg(struct lm3533_led *led,
u8 base)
{
return base + lm3533_led_get_pattern(led) * LM3533_REG_PATTERN_STEP;
}
static int lm3533_led_pattern_enable(struct lm3533_led *led, int enable)
{
u8 mask;
u8 val;
int pattern;
int state;
int ret = 0;
dev_dbg(led->cdev.dev, "%s - %d\n", __func__, enable);
mutex_lock(&led->mutex);
state = test_bit(LM3533_LED_FLAG_PATTERN_ENABLE, &led->flags);
if ((enable && state) || (!enable && !state))
goto out;
pattern = lm3533_led_get_pattern(led);
mask = 1 << (2 * pattern);
if (enable)
val = mask;
else
val = 0;
ret = lm3533_update(led->lm3533, LM3533_REG_PATTERN_ENABLE, val, mask);
if (ret) {
dev_err(led->cdev.dev, "failed to enable pattern %d (%d)\n",
pattern, enable);
goto out;
}
__change_bit(LM3533_LED_FLAG_PATTERN_ENABLE, &led->flags);
out:
mutex_unlock(&led->mutex);
return ret;
}
static void lm3533_led_work(struct work_struct *work)
{
struct lm3533_led *led = container_of(work, struct lm3533_led, work);
dev_dbg(led->cdev.dev, "%s - %u\n", __func__, led->new_brightness);
if (led->new_brightness == 0)
lm3533_led_pattern_enable(led, 0);
lm3533_ctrlbank_set_brightness(&led->cb, led->new_brightness);
}
static void lm3533_led_set(struct led_classdev *cdev,
enum led_brightness value)
{
struct lm3533_led *led = to_lm3533_led(cdev);
dev_dbg(led->cdev.dev, "%s - %d\n", __func__, value);
led->new_brightness = value;
schedule_work(&led->work);
}
static enum led_brightness lm3533_led_get(struct led_classdev *cdev)
{
struct lm3533_led *led = to_lm3533_led(cdev);
u8 val;
int ret;
ret = lm3533_ctrlbank_get_brightness(&led->cb, &val);
if (ret)
return ret;
dev_dbg(led->cdev.dev, "%s - %u\n", __func__, val);
return val;
}
static u8 time_to_val(unsigned *t, unsigned t_min, unsigned t_step,
u8 v_min, u8 v_max)
{
unsigned val;
val = (*t + t_step / 2 - t_min) / t_step + v_min;
*t = t_step * (val - v_min) + t_min;
return (u8)val;
}
static u8 lm3533_led_get_hw_delay(unsigned *delay)
{
unsigned t;
u8 val;
t = *delay * 1000;
if (t >= (LM3533_LED_DELAY2_TMAX + LM3533_LED_DELAY3_TMIN) / 2) {
t = clamp(t, LM3533_LED_DELAY3_TMIN, LM3533_LED_DELAY3_TMAX);
val = time_to_val(&t, LM3533_LED_DELAY3_TMIN,
LM3533_LED_DELAY3_TSTEP,
LM3533_LED_DELAY3_VMIN,
LM3533_LED_DELAY3_VMAX);
} else if (t >= (LM3533_LED_DELAY1_TMAX + LM3533_LED_DELAY2_TMIN) / 2) {
t = clamp(t, LM3533_LED_DELAY2_TMIN, LM3533_LED_DELAY2_TMAX);
val = time_to_val(&t, LM3533_LED_DELAY2_TMIN,
LM3533_LED_DELAY2_TSTEP,
LM3533_LED_DELAY2_VMIN,
LM3533_LED_DELAY2_VMAX);
} else {
t = clamp(t, LM3533_LED_DELAY1_TMIN, LM3533_LED_DELAY1_TMAX);
val = time_to_val(&t, LM3533_LED_DELAY1_TMIN,
LM3533_LED_DELAY1_TSTEP,
LM3533_LED_DELAY1_VMIN,
LM3533_LED_DELAY1_VMAX);
}
*delay = (t + 500) / 1000;
return val;
}
static u8 lm3533_led_delay_set(struct lm3533_led *led, u8 base,
unsigned long *delay)
{
unsigned t;
u8 val;
u8 reg;
int ret;
t = (unsigned)*delay;
if (base != LM3533_REG_PATTERN_LOW_TIME_BASE)
t = min(t, LM3533_LED_DELAY2_TMAX / 1000);
val = lm3533_led_get_hw_delay(&t);
dev_dbg(led->cdev.dev, "%s - %lu: %u (0x%02x)\n", __func__,
*delay, t, val);
reg = lm3533_led_get_pattern_reg(led, base);
ret = lm3533_write(led->lm3533, reg, val);
if (ret)
dev_err(led->cdev.dev, "failed to set delay (%02x)\n", reg);
*delay = t;
return ret;
}
static int lm3533_led_delay_on_set(struct lm3533_led *led, unsigned long *t)
{
return lm3533_led_delay_set(led, LM3533_REG_PATTERN_HIGH_TIME_BASE, t);
}
static int lm3533_led_delay_off_set(struct lm3533_led *led, unsigned long *t)
{
return lm3533_led_delay_set(led, LM3533_REG_PATTERN_LOW_TIME_BASE, t);
}
static int lm3533_led_blink_set(struct led_classdev *cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
struct lm3533_led *led = to_lm3533_led(cdev);
int ret;
dev_dbg(led->cdev.dev, "%s - on = %lu, off = %lu\n", __func__,
*delay_on, *delay_off);
if (*delay_on > LM3533_LED_DELAY_ON_MAX ||
*delay_off > LM3533_LED_DELAY_OFF_MAX)
return -EINVAL;
if (*delay_on == 0 && *delay_off == 0) {
*delay_on = 500;
*delay_off = 500;
}
ret = lm3533_led_delay_on_set(led, delay_on);
if (ret)
return ret;
ret = lm3533_led_delay_off_set(led, delay_off);
if (ret)
return ret;
return lm3533_led_pattern_enable(led, 1);
}
static ssize_t show_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
return scnprintf(buf, PAGE_SIZE, "%d\n", led->id);
}
static ssize_t show_risefalltime(struct device *dev,
struct device_attribute *attr,
char *buf, u8 base)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
ssize_t ret;
u8 reg;
u8 val;
reg = lm3533_led_get_pattern_reg(led, base);
ret = lm3533_read(led->lm3533, reg, &val);
if (ret)
return ret;
return scnprintf(buf, PAGE_SIZE, "%x\n", val);
}
static ssize_t show_risetime(struct device *dev,
struct device_attribute *attr, char *buf)
{
return show_risefalltime(dev, attr, buf,
LM3533_REG_PATTERN_RISETIME_BASE);
}
static ssize_t show_falltime(struct device *dev,
struct device_attribute *attr, char *buf)
{
return show_risefalltime(dev, attr, buf,
LM3533_REG_PATTERN_FALLTIME_BASE);
}
static ssize_t store_risefalltime(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len, u8 base)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
u8 val;
u8 reg;
int ret;
if (kstrtou8(buf, 0, &val) || val > LM3533_RISEFALLTIME_MAX)
return -EINVAL;
reg = lm3533_led_get_pattern_reg(led, base);
ret = lm3533_write(led->lm3533, reg, val);
if (ret)
return ret;
return len;
}
static ssize_t store_risetime(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_risefalltime(dev, attr, buf, len,
LM3533_REG_PATTERN_RISETIME_BASE);
}
static ssize_t store_falltime(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
return store_risefalltime(dev, attr, buf, len,
LM3533_REG_PATTERN_FALLTIME_BASE);
}
static ssize_t show_als_channel(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
unsigned channel;
u8 reg;
u8 val;
int ret;
reg = lm3533_led_get_lv_reg(led, LM3533_REG_CTRLBANK_BCONF_BASE);
ret = lm3533_read(led->lm3533, reg, &val);
if (ret)
return ret;
channel = (val & LM3533_REG_CTRLBANK_BCONF_ALS_CHANNEL_MASK) + 1;
return scnprintf(buf, PAGE_SIZE, "%u\n", channel);
}
static ssize_t store_als_channel(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
unsigned channel;
u8 reg;
u8 val;
u8 mask;
int ret;
if (kstrtouint(buf, 0, &channel))
return -EINVAL;
if (channel < LM3533_ALS_CHANNEL_LV_MIN ||
channel > LM3533_ALS_CHANNEL_LV_MAX)
return -EINVAL;
reg = lm3533_led_get_lv_reg(led, LM3533_REG_CTRLBANK_BCONF_BASE);
mask = LM3533_REG_CTRLBANK_BCONF_ALS_CHANNEL_MASK;
val = channel - 1;
ret = lm3533_update(led->lm3533, reg, val, mask);
if (ret)
return ret;
return len;
}
static ssize_t show_als_en(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
bool enable;
u8 reg;
u8 val;
int ret;
reg = lm3533_led_get_lv_reg(led, LM3533_REG_CTRLBANK_BCONF_BASE);
ret = lm3533_read(led->lm3533, reg, &val);
if (ret)
return ret;
enable = val & LM3533_REG_CTRLBANK_BCONF_ALS_EN_MASK;
return scnprintf(buf, PAGE_SIZE, "%d\n", enable);
}
static ssize_t store_als_en(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
unsigned enable;
u8 reg;
u8 mask;
u8 val;
int ret;
if (kstrtouint(buf, 0, &enable))
return -EINVAL;
reg = lm3533_led_get_lv_reg(led, LM3533_REG_CTRLBANK_BCONF_BASE);
mask = LM3533_REG_CTRLBANK_BCONF_ALS_EN_MASK;
if (enable)
val = mask;
else
val = 0;
ret = lm3533_update(led->lm3533, reg, val, mask);
if (ret)
return ret;
return len;
}
static ssize_t show_linear(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
u8 reg;
u8 val;
int linear;
int ret;
reg = lm3533_led_get_lv_reg(led, LM3533_REG_CTRLBANK_BCONF_BASE);
ret = lm3533_read(led->lm3533, reg, &val);
if (ret)
return ret;
if (val & LM3533_REG_CTRLBANK_BCONF_MAPPING_MASK)
linear = 1;
else
linear = 0;
return scnprintf(buf, PAGE_SIZE, "%x\n", linear);
}
static ssize_t store_linear(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
unsigned long linear;
u8 reg;
u8 mask;
u8 val;
int ret;
if (kstrtoul(buf, 0, &linear))
return -EINVAL;
reg = lm3533_led_get_lv_reg(led, LM3533_REG_CTRLBANK_BCONF_BASE);
mask = LM3533_REG_CTRLBANK_BCONF_MAPPING_MASK;
if (linear)
val = mask;
else
val = 0;
ret = lm3533_update(led->lm3533, reg, val, mask);
if (ret)
return ret;
return len;
}
static ssize_t show_pwm(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
u8 val;
int ret;
ret = lm3533_ctrlbank_get_pwm(&led->cb, &val);
if (ret)
return ret;
return scnprintf(buf, PAGE_SIZE, "%u\n", val);
}
static ssize_t store_pwm(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
u8 val;
int ret;
if (kstrtou8(buf, 0, &val))
return -EINVAL;
ret = lm3533_ctrlbank_set_pwm(&led->cb, val);
if (ret)
return ret;
return len;
}
static umode_t lm3533_led_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3533_led *led = to_lm3533_led(led_cdev);
umode_t mode = attr->mode;
if (attr == &dev_attr_als_channel.attr ||
attr == &dev_attr_als_en.attr) {
if (!led->lm3533->have_als)
mode = 0;
}
return mode;
}
static int lm3533_led_setup(struct lm3533_led *led,
struct lm3533_led_platform_data *pdata)
{
int ret;
ret = lm3533_ctrlbank_set_max_current(&led->cb, pdata->max_current);
if (ret)
return ret;
return lm3533_ctrlbank_set_pwm(&led->cb, pdata->pwm);
}
static int lm3533_led_probe(struct platform_device *pdev)
{
struct lm3533 *lm3533;
struct lm3533_led_platform_data *pdata;
struct lm3533_led *led;
int ret;
dev_dbg(&pdev->dev, "%s\n", __func__);
lm3533 = dev_get_drvdata(pdev->dev.parent);
if (!lm3533)
return -EINVAL;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "no platform data\n");
return -EINVAL;
}
if (pdev->id < 0 || pdev->id >= LM3533_LVCTRLBANK_COUNT) {
dev_err(&pdev->dev, "illegal LED id %d\n", pdev->id);
return -EINVAL;
}
led = devm_kzalloc(&pdev->dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
led->lm3533 = lm3533;
led->cdev.name = pdata->name;
led->cdev.default_trigger = pdata->default_trigger;
led->cdev.brightness_set = lm3533_led_set;
led->cdev.brightness_get = lm3533_led_get;
led->cdev.blink_set = lm3533_led_blink_set;
led->cdev.brightness = LED_OFF;
led->cdev.groups = lm3533_led_attribute_groups,
led->id = pdev->id;
mutex_init(&led->mutex);
INIT_WORK(&led->work, lm3533_led_work);
led->cb.lm3533 = lm3533;
led->cb.id = lm3533_led_get_ctrlbank_id(led);
led->cb.dev = lm3533->dev;
platform_set_drvdata(pdev, led);
ret = led_classdev_register(pdev->dev.parent, &led->cdev);
if (ret) {
dev_err(&pdev->dev, "failed to register LED %d\n", pdev->id);
return ret;
}
led->cb.dev = led->cdev.dev;
ret = lm3533_led_setup(led, pdata);
if (ret)
goto err_unregister;
ret = lm3533_ctrlbank_enable(&led->cb);
if (ret)
goto err_unregister;
return 0;
err_unregister:
led_classdev_unregister(&led->cdev);
flush_work(&led->work);
return ret;
}
static int lm3533_led_remove(struct platform_device *pdev)
{
struct lm3533_led *led = platform_get_drvdata(pdev);
dev_dbg(&pdev->dev, "%s\n", __func__);
lm3533_ctrlbank_disable(&led->cb);
led_classdev_unregister(&led->cdev);
flush_work(&led->work);
return 0;
}
static void lm3533_led_shutdown(struct platform_device *pdev)
{
struct lm3533_led *led = platform_get_drvdata(pdev);
dev_dbg(&pdev->dev, "%s\n", __func__);
lm3533_ctrlbank_disable(&led->cb);
lm3533_led_set(&led->cdev, LED_OFF);
flush_work(&led->work);
}
