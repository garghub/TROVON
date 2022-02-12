static inline int lm3533_bl_get_ctrlbank_id(struct lm3533_bl *bl)
{
return bl->id;
}
static int lm3533_bl_update_status(struct backlight_device *bd)
{
struct lm3533_bl *bl = bl_get_data(bd);
int brightness = bd->props.brightness;
if (bd->props.power != FB_BLANK_UNBLANK)
brightness = 0;
if (bd->props.fb_blank != FB_BLANK_UNBLANK)
brightness = 0;
return lm3533_ctrlbank_set_brightness(&bl->cb, (u8)brightness);
}
static int lm3533_bl_get_brightness(struct backlight_device *bd)
{
struct lm3533_bl *bl = bl_get_data(bd);
u8 val;
int ret;
ret = lm3533_ctrlbank_get_brightness(&bl->cb, &val);
if (ret)
return ret;
return val;
}
static ssize_t show_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm3533_bl *bl = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%d\n", bl->id);
}
static ssize_t show_als_channel(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm3533_bl *bl = dev_get_drvdata(dev);
unsigned channel = lm3533_bl_get_ctrlbank_id(bl);
return scnprintf(buf, PAGE_SIZE, "%u\n", channel);
}
static ssize_t show_als_en(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm3533_bl *bl = dev_get_drvdata(dev);
int ctrlbank = lm3533_bl_get_ctrlbank_id(bl);
u8 val;
u8 mask;
bool enable;
int ret;
ret = lm3533_read(bl->lm3533, LM3533_REG_CTRLBANK_AB_BCONF, &val);
if (ret)
return ret;
mask = 1 << (2 * ctrlbank);
enable = val & mask;
return scnprintf(buf, PAGE_SIZE, "%d\n", enable);
}
static ssize_t store_als_en(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct lm3533_bl *bl = dev_get_drvdata(dev);
int ctrlbank = lm3533_bl_get_ctrlbank_id(bl);
int enable;
u8 val;
u8 mask;
int ret;
if (kstrtoint(buf, 0, &enable))
return -EINVAL;
mask = 1 << (2 * ctrlbank);
if (enable)
val = mask;
else
val = 0;
ret = lm3533_update(bl->lm3533, LM3533_REG_CTRLBANK_AB_BCONF, val,
mask);
if (ret)
return ret;
return len;
}
static ssize_t show_linear(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm3533_bl *bl = dev_get_drvdata(dev);
u8 val;
u8 mask;
int linear;
int ret;
ret = lm3533_read(bl->lm3533, LM3533_REG_CTRLBANK_AB_BCONF, &val);
if (ret)
return ret;
mask = 1 << (2 * lm3533_bl_get_ctrlbank_id(bl) + 1);
if (val & mask)
linear = 1;
else
linear = 0;
return scnprintf(buf, PAGE_SIZE, "%x\n", linear);
}
static ssize_t store_linear(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct lm3533_bl *bl = dev_get_drvdata(dev);
unsigned long linear;
u8 mask;
u8 val;
int ret;
if (kstrtoul(buf, 0, &linear))
return -EINVAL;
mask = 1 << (2 * lm3533_bl_get_ctrlbank_id(bl) + 1);
if (linear)
val = mask;
else
val = 0;
ret = lm3533_update(bl->lm3533, LM3533_REG_CTRLBANK_AB_BCONF, val,
mask);
if (ret)
return ret;
return len;
}
static ssize_t show_pwm(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct lm3533_bl *bl = dev_get_drvdata(dev);
u8 val;
int ret;
ret = lm3533_ctrlbank_get_pwm(&bl->cb, &val);
if (ret)
return ret;
return scnprintf(buf, PAGE_SIZE, "%u\n", val);
}
static ssize_t store_pwm(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct lm3533_bl *bl = dev_get_drvdata(dev);
u8 val;
int ret;
if (kstrtou8(buf, 0, &val))
return -EINVAL;
ret = lm3533_ctrlbank_set_pwm(&bl->cb, val);
if (ret)
return ret;
return len;
}
static umode_t lm3533_bl_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct lm3533_bl *bl = dev_get_drvdata(dev);
umode_t mode = attr->mode;
if (attr == &dev_attr_als_channel.attr ||
attr == &dev_attr_als_en.attr) {
if (!bl->lm3533->have_als)
mode = 0;
}
return mode;
}
static int lm3533_bl_setup(struct lm3533_bl *bl,
struct lm3533_bl_platform_data *pdata)
{
int ret;
ret = lm3533_ctrlbank_set_max_current(&bl->cb, pdata->max_current);
if (ret)
return ret;
return lm3533_ctrlbank_set_pwm(&bl->cb, pdata->pwm);
}
static int lm3533_bl_probe(struct platform_device *pdev)
{
struct lm3533 *lm3533;
struct lm3533_bl_platform_data *pdata;
struct lm3533_bl *bl;
struct backlight_device *bd;
struct backlight_properties props;
int ret;
dev_dbg(&pdev->dev, "%s\n", __func__);
lm3533 = dev_get_drvdata(pdev->dev.parent);
if (!lm3533)
return -EINVAL;
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "no platform data\n");
return -EINVAL;
}
if (pdev->id < 0 || pdev->id >= LM3533_HVCTRLBANK_COUNT) {
dev_err(&pdev->dev, "illegal backlight id %d\n", pdev->id);
return -EINVAL;
}
bl = devm_kzalloc(&pdev->dev, sizeof(*bl), GFP_KERNEL);
if (!bl) {
dev_err(&pdev->dev,
"failed to allocate memory for backlight\n");
return -ENOMEM;
}
bl->lm3533 = lm3533;
bl->id = pdev->id;
bl->cb.lm3533 = lm3533;
bl->cb.id = lm3533_bl_get_ctrlbank_id(bl);
bl->cb.dev = NULL;
memset(&props, 0, sizeof(props));
props.type = BACKLIGHT_RAW;
props.max_brightness = LM3533_BL_MAX_BRIGHTNESS;
props.brightness = pdata->default_brightness;
bd = backlight_device_register(pdata->name, pdev->dev.parent, bl,
&lm3533_bl_ops, &props);
if (IS_ERR(bd)) {
dev_err(&pdev->dev, "failed to register backlight device\n");
return PTR_ERR(bd);
}
bl->bd = bd;
bl->cb.dev = &bl->bd->dev;
platform_set_drvdata(pdev, bl);
ret = sysfs_create_group(&bd->dev.kobj, &lm3533_bl_attribute_group);
if (ret < 0) {
dev_err(&pdev->dev, "failed to create sysfs attributes\n");
goto err_unregister;
}
backlight_update_status(bd);
ret = lm3533_bl_setup(bl, pdata);
if (ret)
goto err_sysfs_remove;
ret = lm3533_ctrlbank_enable(&bl->cb);
if (ret)
goto err_sysfs_remove;
return 0;
err_sysfs_remove:
sysfs_remove_group(&bd->dev.kobj, &lm3533_bl_attribute_group);
err_unregister:
backlight_device_unregister(bd);
return ret;
}
static int lm3533_bl_remove(struct platform_device *pdev)
{
struct lm3533_bl *bl = platform_get_drvdata(pdev);
struct backlight_device *bd = bl->bd;
dev_dbg(&bd->dev, "%s\n", __func__);
bd->props.power = FB_BLANK_POWERDOWN;
bd->props.brightness = 0;
lm3533_ctrlbank_disable(&bl->cb);
sysfs_remove_group(&bd->dev.kobj, &lm3533_bl_attribute_group);
backlight_device_unregister(bd);
return 0;
}
static int lm3533_bl_suspend(struct platform_device *pdev, pm_message_t state)
{
struct lm3533_bl *bl = platform_get_drvdata(pdev);
dev_dbg(&pdev->dev, "%s\n", __func__);
return lm3533_ctrlbank_disable(&bl->cb);
}
static int lm3533_bl_resume(struct platform_device *pdev)
{
struct lm3533_bl *bl = platform_get_drvdata(pdev);
dev_dbg(&pdev->dev, "%s\n", __func__);
return lm3533_ctrlbank_enable(&bl->cb);
}
static void lm3533_bl_shutdown(struct platform_device *pdev)
{
struct lm3533_bl *bl = platform_get_drvdata(pdev);
dev_dbg(&pdev->dev, "%s\n", __func__);
lm3533_ctrlbank_disable(&bl->cb);
}
