static void imx_set_alarm_temp(struct imx_thermal_data *data,
signed long alarm_temp)
{
struct regmap *map = data->tempmon;
int alarm_value;
data->alarm_temp = alarm_temp;
alarm_value = (data->c2 - alarm_temp) / data->c1;
regmap_write(map, TEMPSENSE0 + REG_CLR, TEMPSENSE0_ALARM_VALUE_MASK);
regmap_write(map, TEMPSENSE0 + REG_SET, alarm_value <<
TEMPSENSE0_ALARM_VALUE_SHIFT);
}
static int imx_get_temp(struct thermal_zone_device *tz, unsigned long *temp)
{
struct imx_thermal_data *data = tz->devdata;
struct regmap *map = data->tempmon;
unsigned int n_meas;
bool wait;
u32 val;
if (data->mode == THERMAL_DEVICE_ENABLED) {
regmap_read(map, TEMPSENSE0, &val);
wait = !(val & TEMPSENSE0_FINISHED);
} else {
regmap_write(map, TEMPSENSE0 + REG_CLR, TEMPSENSE0_POWER_DOWN);
regmap_write(map, TEMPSENSE0 + REG_SET, TEMPSENSE0_MEASURE_TEMP);
wait = true;
}
if (wait)
usleep_range(20, 50);
regmap_read(map, TEMPSENSE0, &val);
if (data->mode != THERMAL_DEVICE_ENABLED) {
regmap_write(map, TEMPSENSE0 + REG_CLR, TEMPSENSE0_MEASURE_TEMP);
regmap_write(map, TEMPSENSE0 + REG_SET, TEMPSENSE0_POWER_DOWN);
}
if ((val & TEMPSENSE0_FINISHED) == 0) {
dev_dbg(&tz->device, "temp measurement never finished\n");
return -EAGAIN;
}
n_meas = (val & TEMPSENSE0_TEMP_CNT_MASK) >> TEMPSENSE0_TEMP_CNT_SHIFT;
*temp = data->c2 - n_meas * data->c1;
if (data->alarm_temp == data->temp_passive && *temp >= data->temp_passive)
imx_set_alarm_temp(data, data->temp_critical);
if (data->alarm_temp == data->temp_critical && *temp < data->temp_passive) {
imx_set_alarm_temp(data, data->temp_passive);
dev_dbg(&tz->device, "thermal alarm off: T < %lu\n",
data->alarm_temp / 1000);
}
if (*temp != data->last_temp) {
dev_dbg(&tz->device, "millicelsius: %ld\n", *temp);
data->last_temp = *temp;
}
if (!data->irq_enabled && *temp < data->alarm_temp) {
data->irq_enabled = true;
enable_irq(data->irq);
}
return 0;
}
static int imx_get_mode(struct thermal_zone_device *tz,
enum thermal_device_mode *mode)
{
struct imx_thermal_data *data = tz->devdata;
*mode = data->mode;
return 0;
}
static int imx_set_mode(struct thermal_zone_device *tz,
enum thermal_device_mode mode)
{
struct imx_thermal_data *data = tz->devdata;
struct regmap *map = data->tempmon;
if (mode == THERMAL_DEVICE_ENABLED) {
tz->polling_delay = IMX_POLLING_DELAY;
tz->passive_delay = IMX_PASSIVE_DELAY;
regmap_write(map, TEMPSENSE0 + REG_CLR, TEMPSENSE0_POWER_DOWN);
regmap_write(map, TEMPSENSE0 + REG_SET, TEMPSENSE0_MEASURE_TEMP);
if (!data->irq_enabled) {
data->irq_enabled = true;
enable_irq(data->irq);
}
} else {
regmap_write(map, TEMPSENSE0 + REG_CLR, TEMPSENSE0_MEASURE_TEMP);
regmap_write(map, TEMPSENSE0 + REG_SET, TEMPSENSE0_POWER_DOWN);
tz->polling_delay = 0;
tz->passive_delay = 0;
if (data->irq_enabled) {
disable_irq(data->irq);
data->irq_enabled = false;
}
}
data->mode = mode;
thermal_zone_device_update(tz);
return 0;
}
static int imx_get_trip_type(struct thermal_zone_device *tz, int trip,
enum thermal_trip_type *type)
{
*type = (trip == IMX_TRIP_PASSIVE) ? THERMAL_TRIP_PASSIVE :
THERMAL_TRIP_CRITICAL;
return 0;
}
static int imx_get_crit_temp(struct thermal_zone_device *tz,
unsigned long *temp)
{
struct imx_thermal_data *data = tz->devdata;
*temp = data->temp_critical;
return 0;
}
static int imx_get_trip_temp(struct thermal_zone_device *tz, int trip,
unsigned long *temp)
{
struct imx_thermal_data *data = tz->devdata;
*temp = (trip == IMX_TRIP_PASSIVE) ? data->temp_passive :
data->temp_critical;
return 0;
}
static int imx_set_trip_temp(struct thermal_zone_device *tz, int trip,
unsigned long temp)
{
struct imx_thermal_data *data = tz->devdata;
if (trip == IMX_TRIP_CRITICAL)
return -EPERM;
if (temp > IMX_TEMP_PASSIVE)
return -EINVAL;
data->temp_passive = temp;
imx_set_alarm_temp(data, temp);
return 0;
}
static int imx_bind(struct thermal_zone_device *tz,
struct thermal_cooling_device *cdev)
{
int ret;
ret = thermal_zone_bind_cooling_device(tz, IMX_TRIP_PASSIVE, cdev,
THERMAL_NO_LIMIT,
THERMAL_NO_LIMIT);
if (ret) {
dev_err(&tz->device,
"binding zone %s with cdev %s failed:%d\n",
tz->type, cdev->type, ret);
return ret;
}
return 0;
}
static int imx_unbind(struct thermal_zone_device *tz,
struct thermal_cooling_device *cdev)
{
int ret;
ret = thermal_zone_unbind_cooling_device(tz, IMX_TRIP_PASSIVE, cdev);
if (ret) {
dev_err(&tz->device,
"unbinding zone %s with cdev %s failed:%d\n",
tz->type, cdev->type, ret);
return ret;
}
return 0;
}
static int imx_get_sensor_data(struct platform_device *pdev)
{
struct imx_thermal_data *data = platform_get_drvdata(pdev);
struct regmap *map;
int t1, t2, n1, n2;
int ret;
u32 val;
u64 temp64;
map = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"fsl,tempmon-data");
if (IS_ERR(map)) {
ret = PTR_ERR(map);
dev_err(&pdev->dev, "failed to get sensor regmap: %d\n", ret);
return ret;
}
ret = regmap_read(map, OCOTP_ANA1, &val);
if (ret) {
dev_err(&pdev->dev, "failed to read sensor data: %d\n", ret);
return ret;
}
if (val == 0 || val == ~0) {
dev_err(&pdev->dev, "invalid sensor calibration data\n");
return -EINVAL;
}
n1 = val >> 20;
n2 = (val & 0xfff00) >> 8;
t2 = val & 0xff;
t1 = 25;
temp64 = FACTOR0;
temp64 *= 1000;
do_div(temp64, FACTOR1 * n1 - FACTOR2);
data->c1 = temp64;
data->c2 = n1 * data->c1 + 1000 * t1;
data->temp_passive = 1000 * (t2 - 20);
data->temp_critical = 1000 * (t2 - 5);
return 0;
}
static irqreturn_t imx_thermal_alarm_irq(int irq, void *dev)
{
struct imx_thermal_data *data = dev;
disable_irq_nosync(irq);
data->irq_enabled = false;
return IRQ_WAKE_THREAD;
}
static irqreturn_t imx_thermal_alarm_irq_thread(int irq, void *dev)
{
struct imx_thermal_data *data = dev;
dev_dbg(&data->tz->device, "THERMAL ALARM: T > %lu\n",
data->alarm_temp / 1000);
thermal_zone_device_update(data->tz);
return IRQ_HANDLED;
}
static int imx_thermal_probe(struct platform_device *pdev)
{
struct imx_thermal_data *data;
struct cpumask clip_cpus;
struct regmap *map;
int measure_freq;
int ret;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
map = syscon_regmap_lookup_by_phandle(pdev->dev.of_node, "fsl,tempmon");
if (IS_ERR(map)) {
ret = PTR_ERR(map);
dev_err(&pdev->dev, "failed to get tempmon regmap: %d\n", ret);
return ret;
}
data->tempmon = map;
data->irq = platform_get_irq(pdev, 0);
if (data->irq < 0)
return data->irq;
ret = devm_request_threaded_irq(&pdev->dev, data->irq,
imx_thermal_alarm_irq, imx_thermal_alarm_irq_thread,
0, "imx_thermal", data);
if (ret < 0) {
dev_err(&pdev->dev, "failed to request alarm irq: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, data);
ret = imx_get_sensor_data(pdev);
if (ret) {
dev_err(&pdev->dev, "failed to get sensor data\n");
return ret;
}
regmap_write(map, TEMPSENSE0 + REG_CLR, TEMPSENSE0_POWER_DOWN);
regmap_write(map, TEMPSENSE0 + REG_CLR, TEMPSENSE0_MEASURE_TEMP);
regmap_write(map, TEMPSENSE1 + REG_CLR, TEMPSENSE1_MEASURE_FREQ);
regmap_write(map, MISC0 + REG_SET, MISC0_REFTOP_SELBIASOFF);
regmap_write(map, TEMPSENSE0 + REG_SET, TEMPSENSE0_POWER_DOWN);
cpumask_set_cpu(0, &clip_cpus);
data->cdev = cpufreq_cooling_register(&clip_cpus);
if (IS_ERR(data->cdev)) {
ret = PTR_ERR(data->cdev);
dev_err(&pdev->dev,
"failed to register cpufreq cooling device: %d\n", ret);
return ret;
}
data->tz = thermal_zone_device_register("imx_thermal_zone",
IMX_TRIP_NUM,
BIT(IMX_TRIP_PASSIVE), data,
&imx_tz_ops, NULL,
IMX_PASSIVE_DELAY,
IMX_POLLING_DELAY);
if (IS_ERR(data->tz)) {
ret = PTR_ERR(data->tz);
dev_err(&pdev->dev,
"failed to register thermal zone device %d\n", ret);
cpufreq_cooling_unregister(data->cdev);
return ret;
}
data->thermal_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(data->thermal_clk)) {
dev_warn(&pdev->dev, "failed to get thermal clk!\n");
} else {
ret = clk_prepare_enable(data->thermal_clk);
if (ret)
dev_warn(&pdev->dev, "failed to enable thermal clk: %d\n", ret);
}
regmap_write(map, TEMPSENSE1 + REG_CLR, TEMPSENSE1_MEASURE_FREQ);
measure_freq = DIV_ROUND_UP(32768, 10);
regmap_write(map, TEMPSENSE1 + REG_SET, measure_freq);
imx_set_alarm_temp(data, data->temp_passive);
regmap_write(map, TEMPSENSE0 + REG_CLR, TEMPSENSE0_POWER_DOWN);
regmap_write(map, TEMPSENSE0 + REG_SET, TEMPSENSE0_MEASURE_TEMP);
data->irq_enabled = true;
data->mode = THERMAL_DEVICE_ENABLED;
return 0;
}
static int imx_thermal_remove(struct platform_device *pdev)
{
struct imx_thermal_data *data = platform_get_drvdata(pdev);
struct regmap *map = data->tempmon;
regmap_write(map, TEMPSENSE0 + REG_SET, TEMPSENSE0_POWER_DOWN);
if (!IS_ERR(data->thermal_clk))
clk_disable_unprepare(data->thermal_clk);
thermal_zone_device_unregister(data->tz);
cpufreq_cooling_unregister(data->cdev);
return 0;
}
static int imx_thermal_suspend(struct device *dev)
{
struct imx_thermal_data *data = dev_get_drvdata(dev);
struct regmap *map = data->tempmon;
regmap_write(map, TEMPSENSE0 + REG_CLR, TEMPSENSE0_MEASURE_TEMP);
regmap_write(map, TEMPSENSE0 + REG_SET, TEMPSENSE0_POWER_DOWN);
data->mode = THERMAL_DEVICE_DISABLED;
return 0;
}
static int imx_thermal_resume(struct device *dev)
{
struct imx_thermal_data *data = dev_get_drvdata(dev);
struct regmap *map = data->tempmon;
regmap_write(map, TEMPSENSE0 + REG_CLR, TEMPSENSE0_POWER_DOWN);
regmap_write(map, TEMPSENSE0 + REG_SET, TEMPSENSE0_MEASURE_TEMP);
data->mode = THERMAL_DEVICE_ENABLED;
return 0;
}
