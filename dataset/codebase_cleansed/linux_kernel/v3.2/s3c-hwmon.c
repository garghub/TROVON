static int s3c_hwmon_read_ch(struct device *dev,
struct s3c_hwmon *hwmon, int channel)
{
int ret;
ret = mutex_lock_interruptible(&hwmon->lock);
if (ret < 0)
return ret;
dev_dbg(dev, "reading channel %d\n", channel);
ret = s3c_adc_read(hwmon->client, channel);
mutex_unlock(&hwmon->lock);
return ret;
}
static ssize_t s3c_hwmon_show_raw(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct s3c_hwmon *adc = platform_get_drvdata(to_platform_device(dev));
struct sensor_device_attribute *sa = to_sensor_dev_attr(attr);
int ret;
ret = s3c_hwmon_read_ch(dev, adc, sa->index);
return (ret < 0) ? ret : snprintf(buf, PAGE_SIZE, "%d\n", ret);
}
static inline int s3c_hwmon_add_raw(struct device *dev)
{
return sysfs_create_group(&dev->kobj, &s3c_hwmon_attrgroup);
}
static inline void s3c_hwmon_remove_raw(struct device *dev)
{
sysfs_remove_group(&dev->kobj, &s3c_hwmon_attrgroup);
}
static inline int s3c_hwmon_add_raw(struct device *dev) { return 0; }
static inline void s3c_hwmon_remove_raw(struct device *dev) { }
static ssize_t s3c_hwmon_ch_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sen_attr = to_sensor_dev_attr(attr);
struct s3c_hwmon *hwmon = platform_get_drvdata(to_platform_device(dev));
struct s3c_hwmon_pdata *pdata = dev->platform_data;
struct s3c_hwmon_chcfg *cfg;
int ret;
cfg = pdata->in[sen_attr->index];
ret = s3c_hwmon_read_ch(dev, hwmon, sen_attr->index);
if (ret < 0)
return ret;
ret *= cfg->mult;
ret = DIV_ROUND_CLOSEST(ret, cfg->div);
return snprintf(buf, PAGE_SIZE, "%d\n", ret);
}
static ssize_t s3c_hwmon_label_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sen_attr = to_sensor_dev_attr(attr);
struct s3c_hwmon_pdata *pdata = dev->platform_data;
struct s3c_hwmon_chcfg *cfg;
cfg = pdata->in[sen_attr->index];
return snprintf(buf, PAGE_SIZE, "%s\n", cfg->name);
}
static int s3c_hwmon_create_attr(struct device *dev,
struct s3c_hwmon_chcfg *cfg,
struct s3c_hwmon_attr *attrs,
int channel)
{
struct sensor_device_attribute *attr;
int ret;
snprintf(attrs->in_name, sizeof(attrs->in_name), "in%d_input", channel);
attr = &attrs->in;
attr->index = channel;
sysfs_attr_init(&attr->dev_attr.attr);
attr->dev_attr.attr.name = attrs->in_name;
attr->dev_attr.attr.mode = S_IRUGO;
attr->dev_attr.show = s3c_hwmon_ch_show;
ret = device_create_file(dev, &attr->dev_attr);
if (ret < 0) {
dev_err(dev, "failed to create input attribute\n");
return ret;
}
if (cfg->name) {
snprintf(attrs->label_name, sizeof(attrs->label_name),
"in%d_label", channel);
attr = &attrs->label;
attr->index = channel;
sysfs_attr_init(&attr->dev_attr.attr);
attr->dev_attr.attr.name = attrs->label_name;
attr->dev_attr.attr.mode = S_IRUGO;
attr->dev_attr.show = s3c_hwmon_label_show;
ret = device_create_file(dev, &attr->dev_attr);
if (ret < 0) {
device_remove_file(dev, &attrs->in.dev_attr);
dev_err(dev, "failed to create label attribute\n");
}
}
return ret;
}
static void s3c_hwmon_remove_attr(struct device *dev,
struct s3c_hwmon_attr *attrs)
{
device_remove_file(dev, &attrs->in.dev_attr);
device_remove_file(dev, &attrs->label.dev_attr);
}
static int __devinit s3c_hwmon_probe(struct platform_device *dev)
{
struct s3c_hwmon_pdata *pdata = dev->dev.platform_data;
struct s3c_hwmon *hwmon;
int ret = 0;
int i;
if (!pdata) {
dev_err(&dev->dev, "no platform data supplied\n");
return -EINVAL;
}
hwmon = kzalloc(sizeof(struct s3c_hwmon), GFP_KERNEL);
if (hwmon == NULL) {
dev_err(&dev->dev, "no memory\n");
return -ENOMEM;
}
platform_set_drvdata(dev, hwmon);
mutex_init(&hwmon->lock);
hwmon->client = s3c_adc_register(dev, NULL, NULL, 0);
if (IS_ERR(hwmon->client)) {
dev_err(&dev->dev, "cannot register adc\n");
ret = PTR_ERR(hwmon->client);
goto err_mem;
}
ret = s3c_hwmon_add_raw(&dev->dev);
if (ret)
goto err_registered;
hwmon->hwmon_dev = hwmon_device_register(&dev->dev);
if (IS_ERR(hwmon->hwmon_dev)) {
dev_err(&dev->dev, "error registering with hwmon\n");
ret = PTR_ERR(hwmon->hwmon_dev);
goto err_raw_attribute;
}
for (i = 0; i < ARRAY_SIZE(pdata->in); i++) {
struct s3c_hwmon_chcfg *cfg = pdata->in[i];
if (!cfg)
continue;
if (cfg->mult >= 0x10000)
dev_warn(&dev->dev,
"channel %d multiplier too large\n",
i);
if (cfg->div == 0) {
dev_err(&dev->dev, "channel %d divider zero\n", i);
continue;
}
ret = s3c_hwmon_create_attr(&dev->dev, pdata->in[i],
&hwmon->attrs[i], i);
if (ret) {
dev_err(&dev->dev,
"error creating channel %d\n", i);
for (i--; i >= 0; i--)
s3c_hwmon_remove_attr(&dev->dev,
&hwmon->attrs[i]);
goto err_hwmon_register;
}
}
return 0;
err_hwmon_register:
hwmon_device_unregister(hwmon->hwmon_dev);
err_raw_attribute:
s3c_hwmon_remove_raw(&dev->dev);
err_registered:
s3c_adc_release(hwmon->client);
err_mem:
kfree(hwmon);
return ret;
}
static int __devexit s3c_hwmon_remove(struct platform_device *dev)
{
struct s3c_hwmon *hwmon = platform_get_drvdata(dev);
int i;
s3c_hwmon_remove_raw(&dev->dev);
for (i = 0; i < ARRAY_SIZE(hwmon->attrs); i++)
s3c_hwmon_remove_attr(&dev->dev, &hwmon->attrs[i]);
hwmon_device_unregister(hwmon->hwmon_dev);
s3c_adc_release(hwmon->client);
return 0;
}
