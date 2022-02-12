static s32 nsa320_hwmon_update(struct device *dev)
{
u32 mcu_data;
u32 mask;
struct nsa320_hwmon *hwmon = dev_get_drvdata(dev);
mutex_lock(&hwmon->update_lock);
mcu_data = hwmon->mcu_data;
if (time_after(jiffies, hwmon->last_updated + HZ) || mcu_data == 0) {
gpiod_set_value(hwmon->act, 1);
msleep(100);
mcu_data = 0;
for (mask = BIT(31); mask; mask >>= 1) {
gpiod_set_value(hwmon->clk, 0);
usleep_range(100, 200);
gpiod_set_value(hwmon->clk, 1);
usleep_range(100, 200);
if (gpiod_get_value(hwmon->data))
mcu_data |= mask;
}
gpiod_set_value(hwmon->act, 0);
dev_dbg(dev, "Read raw MCU data %08x\n", mcu_data);
if ((mcu_data >> 24) != MAGIC_NUMBER) {
dev_dbg(dev, "Read invalid MCU data %08x\n", mcu_data);
mcu_data = -EIO;
} else {
hwmon->mcu_data = mcu_data;
hwmon->last_updated = jiffies;
}
}
mutex_unlock(&hwmon->update_lock);
return mcu_data;
}
static ssize_t show_label(struct device *dev,
struct device_attribute *attr, char *buf)
{
int channel = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%s\n", nsa320_input_names[channel]);
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
s32 mcu_data = nsa320_hwmon_update(dev);
if (mcu_data < 0)
return mcu_data;
return sprintf(buf, "%d\n", (mcu_data & 0xffff) * 100);
}
static ssize_t show_fan(struct device *dev, struct device_attribute *attr,
char *buf)
{
s32 mcu_data = nsa320_hwmon_update(dev);
if (mcu_data < 0)
return mcu_data;
return sprintf(buf, "%d\n", ((mcu_data & 0xff0000) >> 16) * 100);
}
static int nsa320_hwmon_probe(struct platform_device *pdev)
{
struct nsa320_hwmon *hwmon;
struct device *classdev;
hwmon = devm_kzalloc(&pdev->dev, sizeof(*hwmon), GFP_KERNEL);
if (!hwmon)
return -ENOMEM;
hwmon->act = devm_gpiod_get(&pdev->dev, "act", GPIOD_OUT_LOW);
if (IS_ERR(hwmon->act))
return PTR_ERR(hwmon->act);
hwmon->clk = devm_gpiod_get(&pdev->dev, "clk", GPIOD_OUT_HIGH);
if (IS_ERR(hwmon->clk))
return PTR_ERR(hwmon->clk);
hwmon->data = devm_gpiod_get(&pdev->dev, "data", GPIOD_IN);
if (IS_ERR(hwmon->data))
return PTR_ERR(hwmon->data);
mutex_init(&hwmon->update_lock);
classdev = devm_hwmon_device_register_with_groups(&pdev->dev,
"nsa320", hwmon, nsa320_groups);
return PTR_ERR_OR_ZERO(classdev);
}
