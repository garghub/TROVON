static int exynos_get_mode(struct thermal_zone_device *thermal,
enum thermal_device_mode *mode)
{
if (th_zone)
*mode = th_zone->mode;
return 0;
}
static int exynos_set_mode(struct thermal_zone_device *thermal,
enum thermal_device_mode mode)
{
if (!th_zone->therm_dev) {
pr_notice("thermal zone not registered\n");
return 0;
}
mutex_lock(&th_zone->therm_dev->lock);
if (mode == THERMAL_DEVICE_ENABLED &&
!th_zone->sensor_conf->trip_data.trigger_falling)
th_zone->therm_dev->polling_delay = IDLE_INTERVAL;
else
th_zone->therm_dev->polling_delay = 0;
mutex_unlock(&th_zone->therm_dev->lock);
th_zone->mode = mode;
thermal_zone_device_update(th_zone->therm_dev);
pr_info("thermal polling set for duration=%d msec\n",
th_zone->therm_dev->polling_delay);
return 0;
}
static int exynos_get_trip_type(struct thermal_zone_device *thermal, int trip,
enum thermal_trip_type *type)
{
switch (GET_ZONE(trip)) {
case MONITOR_ZONE:
case WARN_ZONE:
*type = THERMAL_TRIP_ACTIVE;
break;
case PANIC_ZONE:
*type = THERMAL_TRIP_CRITICAL;
break;
default:
return -EINVAL;
}
return 0;
}
static int exynos_get_trip_temp(struct thermal_zone_device *thermal, int trip,
unsigned long *temp)
{
if (trip < GET_TRIP(MONITOR_ZONE) || trip > GET_TRIP(PANIC_ZONE))
return -EINVAL;
*temp = th_zone->sensor_conf->trip_data.trip_val[trip];
*temp = *temp * MCELSIUS;
return 0;
}
static int exynos_get_crit_temp(struct thermal_zone_device *thermal,
unsigned long *temp)
{
int ret;
ret = exynos_get_trip_temp(thermal, GET_TRIP(PANIC_ZONE), temp);
return ret;
}
static int exynos_bind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
int ret = 0, i, tab_size, level;
struct freq_clip_table *tab_ptr, *clip_data;
struct thermal_sensor_conf *data = th_zone->sensor_conf;
tab_ptr = (struct freq_clip_table *)data->cooling_data.freq_data;
tab_size = data->cooling_data.freq_clip_count;
if (tab_ptr == NULL || tab_size == 0)
return -EINVAL;
for (i = 0; i < th_zone->cool_dev_size; i++)
if (cdev == th_zone->cool_dev[i])
break;
if (i == th_zone->cool_dev_size)
return 0;
for (i = 0; i < tab_size; i++) {
clip_data = (struct freq_clip_table *)&(tab_ptr[i]);
level = cpufreq_cooling_get_level(0, clip_data->freq_clip_max);
if (level == THERMAL_CSTATE_INVALID)
return 0;
switch (GET_ZONE(i)) {
case MONITOR_ZONE:
case WARN_ZONE:
if (thermal_zone_bind_cooling_device(thermal, i, cdev,
level, 0)) {
pr_err("error binding cdev inst %d\n", i);
ret = -EINVAL;
}
th_zone->bind = true;
break;
default:
ret = -EINVAL;
}
}
return ret;
}
static int exynos_unbind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
int ret = 0, i, tab_size;
struct thermal_sensor_conf *data = th_zone->sensor_conf;
if (th_zone->bind == false)
return 0;
tab_size = data->cooling_data.freq_clip_count;
if (tab_size == 0)
return -EINVAL;
for (i = 0; i < th_zone->cool_dev_size; i++)
if (cdev == th_zone->cool_dev[i])
break;
if (i == th_zone->cool_dev_size)
return 0;
for (i = 0; i < tab_size; i++) {
switch (GET_ZONE(i)) {
case MONITOR_ZONE:
case WARN_ZONE:
if (thermal_zone_unbind_cooling_device(thermal, i,
cdev)) {
pr_err("error unbinding cdev inst=%d\n", i);
ret = -EINVAL;
}
th_zone->bind = false;
break;
default:
ret = -EINVAL;
}
}
return ret;
}
static int exynos_get_temp(struct thermal_zone_device *thermal,
unsigned long *temp)
{
void *data;
if (!th_zone->sensor_conf) {
pr_info("Temperature sensor not initialised\n");
return -EINVAL;
}
data = th_zone->sensor_conf->private_data;
*temp = th_zone->sensor_conf->read_temperature(data);
*temp = *temp * MCELSIUS;
return 0;
}
static int exynos_set_emul_temp(struct thermal_zone_device *thermal,
unsigned long temp)
{
void *data;
int ret = -EINVAL;
if (!th_zone->sensor_conf) {
pr_info("Temperature sensor not initialised\n");
return -EINVAL;
}
data = th_zone->sensor_conf->private_data;
if (th_zone->sensor_conf->write_emul_temp)
ret = th_zone->sensor_conf->write_emul_temp(data, temp);
return ret;
}
static int exynos_get_trend(struct thermal_zone_device *thermal,
int trip, enum thermal_trend *trend)
{
int ret;
unsigned long trip_temp;
ret = exynos_get_trip_temp(thermal, trip, &trip_temp);
if (ret < 0)
return ret;
if (thermal->temperature >= trip_temp)
*trend = THERMAL_TREND_RAISE_FULL;
else
*trend = THERMAL_TREND_DROP_FULL;
return 0;
}
static void exynos_report_trigger(void)
{
unsigned int i;
char data[10];
char *envp[] = { data, NULL };
if (!th_zone || !th_zone->therm_dev)
return;
if (th_zone->bind == false) {
for (i = 0; i < th_zone->cool_dev_size; i++) {
if (!th_zone->cool_dev[i])
continue;
exynos_bind(th_zone->therm_dev,
th_zone->cool_dev[i]);
}
}
thermal_zone_device_update(th_zone->therm_dev);
mutex_lock(&th_zone->therm_dev->lock);
for (i = 0; i < th_zone->sensor_conf->trip_data.trip_count; i++) {
if (th_zone->therm_dev->last_temperature <
th_zone->sensor_conf->trip_data.trip_val[i] * MCELSIUS)
break;
}
if (th_zone->mode == THERMAL_DEVICE_ENABLED &&
!th_zone->sensor_conf->trip_data.trigger_falling) {
if (i > 0)
th_zone->therm_dev->polling_delay = ACTIVE_INTERVAL;
else
th_zone->therm_dev->polling_delay = IDLE_INTERVAL;
}
snprintf(data, sizeof(data), "%u", i);
kobject_uevent_env(&th_zone->therm_dev->device.kobj, KOBJ_CHANGE, envp);
mutex_unlock(&th_zone->therm_dev->lock);
}
static int exynos_register_thermal(struct thermal_sensor_conf *sensor_conf)
{
int ret;
struct cpumask mask_val;
if (!sensor_conf || !sensor_conf->read_temperature) {
pr_err("Temperature sensor not initialised\n");
return -EINVAL;
}
th_zone = kzalloc(sizeof(struct exynos_thermal_zone), GFP_KERNEL);
if (!th_zone)
return -ENOMEM;
th_zone->sensor_conf = sensor_conf;
cpumask_set_cpu(0, &mask_val);
th_zone->cool_dev[0] = cpufreq_cooling_register(&mask_val);
if (IS_ERR(th_zone->cool_dev[0])) {
pr_err("Failed to register cpufreq cooling device\n");
ret = -EINVAL;
goto err_unregister;
}
th_zone->cool_dev_size++;
th_zone->therm_dev = thermal_zone_device_register(sensor_conf->name,
EXYNOS_ZONE_COUNT, 0, NULL, &exynos_dev_ops, NULL, 0,
sensor_conf->trip_data.trigger_falling ?
0 : IDLE_INTERVAL);
if (IS_ERR(th_zone->therm_dev)) {
pr_err("Failed to register thermal zone device\n");
ret = PTR_ERR(th_zone->therm_dev);
goto err_unregister;
}
th_zone->mode = THERMAL_DEVICE_ENABLED;
pr_info("Exynos: Kernel Thermal management registered\n");
return 0;
err_unregister:
exynos_unregister_thermal();
return ret;
}
static void exynos_unregister_thermal(void)
{
int i;
if (!th_zone)
return;
if (th_zone->therm_dev)
thermal_zone_device_unregister(th_zone->therm_dev);
for (i = 0; i < th_zone->cool_dev_size; i++) {
if (th_zone->cool_dev[i])
cpufreq_cooling_unregister(th_zone->cool_dev[i]);
}
kfree(th_zone);
pr_info("Exynos: Kernel Thermal management unregistered\n");
}
static int temp_to_code(struct exynos_tmu_data *data, u8 temp)
{
struct exynos_tmu_platform_data *pdata = data->pdata;
int temp_code;
if (data->soc == SOC_ARCH_EXYNOS4210)
if (temp < 25 || temp > 125) {
temp_code = -EINVAL;
goto out;
}
switch (pdata->cal_type) {
case TYPE_TWO_POINT_TRIMMING:
temp_code = (temp - 25) *
(data->temp_error2 - data->temp_error1) /
(85 - 25) + data->temp_error1;
break;
case TYPE_ONE_POINT_TRIMMING:
temp_code = temp + data->temp_error1 - 25;
break;
default:
temp_code = temp + EXYNOS_TMU_DEF_CODE_TO_TEMP_OFFSET;
break;
}
out:
return temp_code;
}
static int code_to_temp(struct exynos_tmu_data *data, u8 temp_code)
{
struct exynos_tmu_platform_data *pdata = data->pdata;
int temp;
if (data->soc == SOC_ARCH_EXYNOS4210)
if (temp_code < 75 || temp_code > 175) {
temp = -ENODATA;
goto out;
}
switch (pdata->cal_type) {
case TYPE_TWO_POINT_TRIMMING:
temp = (temp_code - data->temp_error1) * (85 - 25) /
(data->temp_error2 - data->temp_error1) + 25;
break;
case TYPE_ONE_POINT_TRIMMING:
temp = temp_code - data->temp_error1 + 25;
break;
default:
temp = temp_code - EXYNOS_TMU_DEF_CODE_TO_TEMP_OFFSET;
break;
}
out:
return temp;
}
static int exynos_tmu_initialize(struct platform_device *pdev)
{
struct exynos_tmu_data *data = platform_get_drvdata(pdev);
struct exynos_tmu_platform_data *pdata = data->pdata;
unsigned int status, trim_info;
unsigned int rising_threshold = 0, falling_threshold = 0;
int ret = 0, threshold_code, i, trigger_levs = 0;
mutex_lock(&data->lock);
clk_enable(data->clk);
status = readb(data->base + EXYNOS_TMU_REG_STATUS);
if (!status) {
ret = -EBUSY;
goto out;
}
if (data->soc == SOC_ARCH_EXYNOS) {
__raw_writel(EXYNOS_TRIMINFO_RELOAD,
data->base + EXYNOS_TMU_TRIMINFO_CON);
}
trim_info = readl(data->base + EXYNOS_TMU_REG_TRIMINFO);
data->temp_error1 = trim_info & EXYNOS_TMU_TRIM_TEMP_MASK;
data->temp_error2 = ((trim_info >> 8) & EXYNOS_TMU_TRIM_TEMP_MASK);
if ((EFUSE_MIN_VALUE > data->temp_error1) ||
(data->temp_error1 > EFUSE_MAX_VALUE) ||
(data->temp_error2 != 0))
data->temp_error1 = pdata->efuse_value;
for (i = 0; i < MAX_THRESHOLD_LEVS; i++)
if (pdata->trigger_levels[i])
trigger_levs++;
if (data->soc == SOC_ARCH_EXYNOS4210) {
threshold_code = temp_to_code(data, pdata->threshold);
if (threshold_code < 0) {
ret = threshold_code;
goto out;
}
writeb(threshold_code,
data->base + EXYNOS4210_TMU_REG_THRESHOLD_TEMP);
for (i = 0; i < trigger_levs; i++)
writeb(pdata->trigger_levels[i],
data->base + EXYNOS4210_TMU_REG_TRIG_LEVEL0 + i * 4);
writel(EXYNOS4210_TMU_INTCLEAR_VAL,
data->base + EXYNOS_TMU_REG_INTCLEAR);
} else if (data->soc == SOC_ARCH_EXYNOS) {
for (i = 0; i < trigger_levs; i++) {
threshold_code = temp_to_code(data,
pdata->trigger_levels[i]);
if (threshold_code < 0) {
ret = threshold_code;
goto out;
}
rising_threshold |= threshold_code << 8 * i;
if (pdata->threshold_falling) {
threshold_code = temp_to_code(data,
pdata->trigger_levels[i] -
pdata->threshold_falling);
if (threshold_code > 0)
falling_threshold |=
threshold_code << 8 * i;
}
}
writel(rising_threshold,
data->base + EXYNOS_THD_TEMP_RISE);
writel(falling_threshold,
data->base + EXYNOS_THD_TEMP_FALL);
writel(EXYNOS_TMU_CLEAR_RISE_INT | EXYNOS_TMU_CLEAR_FALL_INT,
data->base + EXYNOS_TMU_REG_INTCLEAR);
}
out:
clk_disable(data->clk);
mutex_unlock(&data->lock);
return ret;
}
static void exynos_tmu_control(struct platform_device *pdev, bool on)
{
struct exynos_tmu_data *data = platform_get_drvdata(pdev);
struct exynos_tmu_platform_data *pdata = data->pdata;
unsigned int con, interrupt_en;
mutex_lock(&data->lock);
clk_enable(data->clk);
con = pdata->reference_voltage << EXYNOS_TMU_REF_VOLTAGE_SHIFT |
pdata->gain << EXYNOS_TMU_GAIN_SHIFT;
if (data->soc == SOC_ARCH_EXYNOS) {
con |= pdata->noise_cancel_mode << EXYNOS_TMU_TRIP_MODE_SHIFT;
con |= (EXYNOS_MUX_ADDR_VALUE << EXYNOS_MUX_ADDR_SHIFT);
}
if (on) {
con |= EXYNOS_TMU_CORE_ON;
interrupt_en = pdata->trigger_level3_en << 12 |
pdata->trigger_level2_en << 8 |
pdata->trigger_level1_en << 4 |
pdata->trigger_level0_en;
if (pdata->threshold_falling)
interrupt_en |= interrupt_en << 16;
} else {
con |= EXYNOS_TMU_CORE_OFF;
interrupt_en = 0;
}
writel(interrupt_en, data->base + EXYNOS_TMU_REG_INTEN);
writel(con, data->base + EXYNOS_TMU_REG_CONTROL);
clk_disable(data->clk);
mutex_unlock(&data->lock);
}
static int exynos_tmu_read(struct exynos_tmu_data *data)
{
u8 temp_code;
int temp;
mutex_lock(&data->lock);
clk_enable(data->clk);
temp_code = readb(data->base + EXYNOS_TMU_REG_CURRENT_TEMP);
temp = code_to_temp(data, temp_code);
clk_disable(data->clk);
mutex_unlock(&data->lock);
return temp;
}
static int exynos_tmu_set_emulation(void *drv_data, unsigned long temp)
{
struct exynos_tmu_data *data = drv_data;
unsigned int reg;
int ret = -EINVAL;
if (data->soc == SOC_ARCH_EXYNOS4210)
goto out;
if (temp && temp < MCELSIUS)
goto out;
mutex_lock(&data->lock);
clk_enable(data->clk);
reg = readl(data->base + EXYNOS_EMUL_CON);
if (temp) {
temp /= MCELSIUS;
reg = (EXYNOS_EMUL_TIME << EXYNOS_EMUL_TIME_SHIFT) |
(temp_to_code(data, temp)
<< EXYNOS_EMUL_DATA_SHIFT) | EXYNOS_EMUL_ENABLE;
} else {
reg &= ~EXYNOS_EMUL_ENABLE;
}
writel(reg, data->base + EXYNOS_EMUL_CON);
clk_disable(data->clk);
mutex_unlock(&data->lock);
return 0;
out:
return ret;
}
static int exynos_tmu_set_emulation(void *drv_data, unsigned long temp)
{ return -EINVAL; }
static void exynos_tmu_work(struct work_struct *work)
{
struct exynos_tmu_data *data = container_of(work,
struct exynos_tmu_data, irq_work);
exynos_report_trigger();
mutex_lock(&data->lock);
clk_enable(data->clk);
if (data->soc == SOC_ARCH_EXYNOS)
writel(EXYNOS_TMU_CLEAR_RISE_INT |
EXYNOS_TMU_CLEAR_FALL_INT,
data->base + EXYNOS_TMU_REG_INTCLEAR);
else
writel(EXYNOS4210_TMU_INTCLEAR_VAL,
data->base + EXYNOS_TMU_REG_INTCLEAR);
clk_disable(data->clk);
mutex_unlock(&data->lock);
enable_irq(data->irq);
}
static irqreturn_t exynos_tmu_irq(int irq, void *id)
{
struct exynos_tmu_data *data = id;
disable_irq_nosync(irq);
schedule_work(&data->irq_work);
return IRQ_HANDLED;
}
static inline struct exynos_tmu_platform_data *exynos_get_driver_data(
struct platform_device *pdev)
{
#ifdef CONFIG_OF
if (pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_node(exynos_tmu_match, pdev->dev.of_node);
if (!match)
return NULL;
return (struct exynos_tmu_platform_data *) match->data;
}
#endif
return (struct exynos_tmu_platform_data *)
platform_get_device_id(pdev)->driver_data;
}
static int exynos_tmu_probe(struct platform_device *pdev)
{
struct exynos_tmu_data *data;
struct exynos_tmu_platform_data *pdata = pdev->dev.platform_data;
int ret, i;
if (!pdata)
pdata = exynos_get_driver_data(pdev);
if (!pdata) {
dev_err(&pdev->dev, "No platform init data supplied.\n");
return -ENODEV;
}
data = devm_kzalloc(&pdev->dev, sizeof(struct exynos_tmu_data),
GFP_KERNEL);
if (!data) {
dev_err(&pdev->dev, "Failed to allocate driver structure\n");
return -ENOMEM;
}
data->irq = platform_get_irq(pdev, 0);
if (data->irq < 0) {
dev_err(&pdev->dev, "Failed to get platform irq\n");
return data->irq;
}
INIT_WORK(&data->irq_work, exynos_tmu_work);
data->mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->base = devm_ioremap_resource(&pdev->dev, data->mem);
if (IS_ERR(data->base))
return PTR_ERR(data->base);
ret = devm_request_irq(&pdev->dev, data->irq, exynos_tmu_irq,
IRQF_TRIGGER_RISING, "exynos-tmu", data);
if (ret) {
dev_err(&pdev->dev, "Failed to request irq: %d\n", data->irq);
return ret;
}
data->clk = devm_clk_get(&pdev->dev, "tmu_apbif");
if (IS_ERR(data->clk)) {
dev_err(&pdev->dev, "Failed to get clock\n");
return PTR_ERR(data->clk);
}
ret = clk_prepare(data->clk);
if (ret)
return ret;
if (pdata->type == SOC_ARCH_EXYNOS ||
pdata->type == SOC_ARCH_EXYNOS4210)
data->soc = pdata->type;
else {
ret = -EINVAL;
dev_err(&pdev->dev, "Platform not supported\n");
goto err_clk;
}
data->pdata = pdata;
platform_set_drvdata(pdev, data);
mutex_init(&data->lock);
ret = exynos_tmu_initialize(pdev);
if (ret) {
dev_err(&pdev->dev, "Failed to initialize TMU\n");
goto err_clk;
}
exynos_tmu_control(pdev, true);
(&exynos_sensor_conf)->private_data = data;
exynos_sensor_conf.trip_data.trip_count = pdata->trigger_level0_en +
pdata->trigger_level1_en + pdata->trigger_level2_en +
pdata->trigger_level3_en;
for (i = 0; i < exynos_sensor_conf.trip_data.trip_count; i++)
exynos_sensor_conf.trip_data.trip_val[i] =
pdata->threshold + pdata->trigger_levels[i];
exynos_sensor_conf.trip_data.trigger_falling = pdata->threshold_falling;
exynos_sensor_conf.cooling_data.freq_clip_count =
pdata->freq_tab_count;
for (i = 0; i < pdata->freq_tab_count; i++) {
exynos_sensor_conf.cooling_data.freq_data[i].freq_clip_max =
pdata->freq_tab[i].freq_clip_max;
exynos_sensor_conf.cooling_data.freq_data[i].temp_level =
pdata->freq_tab[i].temp_level;
}
ret = exynos_register_thermal(&exynos_sensor_conf);
if (ret) {
dev_err(&pdev->dev, "Failed to register thermal interface\n");
goto err_clk;
}
return 0;
err_clk:
clk_unprepare(data->clk);
return ret;
}
static int exynos_tmu_remove(struct platform_device *pdev)
{
struct exynos_tmu_data *data = platform_get_drvdata(pdev);
exynos_tmu_control(pdev, false);
exynos_unregister_thermal();
clk_unprepare(data->clk);
return 0;
}
static int exynos_tmu_suspend(struct device *dev)
{
exynos_tmu_control(to_platform_device(dev), false);
return 0;
}
static int exynos_tmu_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
exynos_tmu_initialize(pdev);
exynos_tmu_control(pdev, true);
return 0;
}
