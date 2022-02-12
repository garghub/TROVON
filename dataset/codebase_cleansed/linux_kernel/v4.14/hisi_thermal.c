static inline int _step_to_temp(int step)
{
return (HISI_TEMP_BASE * 1000 + (step * 200000 / 255));
}
static inline long _temp_to_step(long temp)
{
return ((temp - HISI_TEMP_BASE * 1000) * 255) / 200000;
}
static long hisi_thermal_get_sensor_temp(struct hisi_thermal_data *data,
struct hisi_thermal_sensor *sensor)
{
long val;
mutex_lock(&data->thermal_lock);
writel(0x0, data->regs + TEMP0_INT_EN);
writel(0x1, data->regs + TEMP0_INT_CLR);
writel(0x0, data->regs + TEMP0_EN);
writel((sensor->id << 12), data->regs + TEMP0_CFG);
writel(0x1, data->regs + TEMP0_EN);
usleep_range(3000, 5000);
val = readl(data->regs + TEMP0_VALUE);
val = _step_to_temp(val);
mutex_unlock(&data->thermal_lock);
return val;
}
static void hisi_thermal_enable_bind_irq_sensor
(struct hisi_thermal_data *data)
{
struct hisi_thermal_sensor *sensor;
mutex_lock(&data->thermal_lock);
sensor = &data->sensors[data->irq_bind_sensor];
writel(0x0, data->regs + TEMP0_CFG);
writel(0x0, data->regs + TEMP0_RST_MSK);
writel(0x0, data->regs + TEMP0_EN);
writel((sensor->id << 12), data->regs + TEMP0_CFG);
writel(_temp_to_step(sensor->thres_temp) | 0x0FFFFFF00,
data->regs + TEMP0_TH);
writel(_temp_to_step(HISI_TEMP_RESET), data->regs + TEMP0_RST_TH);
writel(0x1, data->regs + TEMP0_RST_MSK);
writel(0x1, data->regs + TEMP0_EN);
writel(0x0, data->regs + TEMP0_INT_CLR);
writel(0x1, data->regs + TEMP0_INT_EN);
usleep_range(3000, 5000);
mutex_unlock(&data->thermal_lock);
}
static void hisi_thermal_disable_sensor(struct hisi_thermal_data *data)
{
mutex_lock(&data->thermal_lock);
writel(0x0, data->regs + TEMP0_INT_EN);
writel(0x0, data->regs + TEMP0_RST_MSK);
writel(0x0, data->regs + TEMP0_EN);
mutex_unlock(&data->thermal_lock);
}
static int hisi_thermal_get_temp(void *_sensor, int *temp)
{
struct hisi_thermal_sensor *sensor = _sensor;
struct hisi_thermal_data *data = sensor->thermal;
int sensor_id = -1, i;
long max_temp = 0;
*temp = hisi_thermal_get_sensor_temp(data, sensor);
sensor->sensor_temp = *temp;
for (i = 0; i < HISI_MAX_SENSORS; i++) {
if (!data->sensors[i].tzd)
continue;
if (data->sensors[i].sensor_temp >= max_temp) {
max_temp = data->sensors[i].sensor_temp;
sensor_id = i;
}
}
if (sensor_id == -1)
return 0;
mutex_lock(&data->thermal_lock);
data->irq_bind_sensor = sensor_id;
mutex_unlock(&data->thermal_lock);
dev_dbg(&data->pdev->dev, "id=%d, irq=%d, temp=%d, thres=%d\n",
sensor->id, data->irq_enabled, *temp, sensor->thres_temp);
if (data->irq_enabled) {
hisi_thermal_enable_bind_irq_sensor(data);
return 0;
}
if (max_temp < sensor->thres_temp) {
data->irq_enabled = true;
hisi_thermal_enable_bind_irq_sensor(data);
enable_irq(data->irq);
}
return 0;
}
static irqreturn_t hisi_thermal_alarm_irq(int irq, void *dev)
{
struct hisi_thermal_data *data = dev;
disable_irq_nosync(irq);
data->irq_enabled = false;
return IRQ_WAKE_THREAD;
}
static irqreturn_t hisi_thermal_alarm_irq_thread(int irq, void *dev)
{
struct hisi_thermal_data *data = dev;
struct hisi_thermal_sensor *sensor;
int i;
mutex_lock(&data->thermal_lock);
sensor = &data->sensors[data->irq_bind_sensor];
dev_crit(&data->pdev->dev, "THERMAL ALARM: T > %d\n",
sensor->thres_temp / 1000);
mutex_unlock(&data->thermal_lock);
for (i = 0; i < HISI_MAX_SENSORS; i++) {
if (!data->sensors[i].tzd)
continue;
thermal_zone_device_update(data->sensors[i].tzd,
THERMAL_EVENT_UNSPECIFIED);
}
return IRQ_HANDLED;
}
static int hisi_thermal_register_sensor(struct platform_device *pdev,
struct hisi_thermal_data *data,
struct hisi_thermal_sensor *sensor,
int index)
{
int ret, i;
const struct thermal_trip *trip;
sensor->id = index;
sensor->thermal = data;
sensor->tzd = devm_thermal_zone_of_sensor_register(&pdev->dev,
sensor->id, sensor, &hisi_of_thermal_ops);
if (IS_ERR(sensor->tzd)) {
ret = PTR_ERR(sensor->tzd);
sensor->tzd = NULL;
dev_err(&pdev->dev, "failed to register sensor id %d: %d\n",
sensor->id, ret);
return ret;
}
trip = of_thermal_get_trip_points(sensor->tzd);
for (i = 0; i < of_thermal_get_ntrips(sensor->tzd); i++) {
if (trip[i].type == THERMAL_TRIP_PASSIVE) {
sensor->thres_temp = trip[i].temperature;
break;
}
}
return 0;
}
static void hisi_thermal_toggle_sensor(struct hisi_thermal_sensor *sensor,
bool on)
{
struct thermal_zone_device *tzd = sensor->tzd;
tzd->ops->set_mode(tzd,
on ? THERMAL_DEVICE_ENABLED : THERMAL_DEVICE_DISABLED);
}
static int hisi_thermal_probe(struct platform_device *pdev)
{
struct hisi_thermal_data *data;
struct resource *res;
int i;
int ret;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
mutex_init(&data->thermal_lock);
data->pdev = pdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->regs)) {
dev_err(&pdev->dev, "failed to get io address\n");
return PTR_ERR(data->regs);
}
data->irq = platform_get_irq(pdev, 0);
if (data->irq < 0)
return data->irq;
ret = devm_request_threaded_irq(&pdev->dev, data->irq,
hisi_thermal_alarm_irq,
hisi_thermal_alarm_irq_thread,
0, "hisi_thermal", data);
if (ret < 0) {
dev_err(&pdev->dev, "failed to request alarm irq: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, data);
data->clk = devm_clk_get(&pdev->dev, "thermal_clk");
if (IS_ERR(data->clk)) {
ret = PTR_ERR(data->clk);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev,
"failed to get thermal clk: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(data->clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable thermal clk: %d\n", ret);
return ret;
}
hisi_thermal_enable_bind_irq_sensor(data);
irq_get_irqchip_state(data->irq, IRQCHIP_STATE_MASKED,
&data->irq_enabled);
for (i = 0; i < HISI_MAX_SENSORS; ++i) {
ret = hisi_thermal_register_sensor(pdev, data,
&data->sensors[i], i);
if (ret)
dev_err(&pdev->dev,
"failed to register thermal sensor: %d\n", ret);
else
hisi_thermal_toggle_sensor(&data->sensors[i], true);
}
return 0;
}
static int hisi_thermal_remove(struct platform_device *pdev)
{
struct hisi_thermal_data *data = platform_get_drvdata(pdev);
int i;
for (i = 0; i < HISI_MAX_SENSORS; i++) {
struct hisi_thermal_sensor *sensor = &data->sensors[i];
if (!sensor->tzd)
continue;
hisi_thermal_toggle_sensor(sensor, false);
}
hisi_thermal_disable_sensor(data);
clk_disable_unprepare(data->clk);
return 0;
}
static int hisi_thermal_suspend(struct device *dev)
{
struct hisi_thermal_data *data = dev_get_drvdata(dev);
hisi_thermal_disable_sensor(data);
data->irq_enabled = false;
clk_disable_unprepare(data->clk);
return 0;
}
static int hisi_thermal_resume(struct device *dev)
{
struct hisi_thermal_data *data = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(data->clk);
if (ret)
return ret;
data->irq_enabled = true;
hisi_thermal_enable_bind_irq_sensor(data);
return 0;
}
