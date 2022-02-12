static int db8500_thermal_match_cdev(struct thermal_cooling_device *cdev,
struct db8500_trip_point *trip_point)
{
int i;
if (!strlen(cdev->type))
return -EINVAL;
for (i = 0; i < COOLING_DEV_MAX; i++) {
if (!strcmp(trip_point->cdev_name[i], cdev->type))
return 0;
}
return -ENODEV;
}
static int db8500_cdev_bind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
struct db8500_thermal_zone *pzone = thermal->devdata;
struct db8500_thsens_platform_data *ptrips = pzone->trip_tab;
unsigned long max_state, upper, lower;
int i, ret = -EINVAL;
cdev->ops->get_max_state(cdev, &max_state);
for (i = 0; i < ptrips->num_trips; i++) {
if (db8500_thermal_match_cdev(cdev, &ptrips->trip_points[i]))
continue;
upper = lower = i > max_state ? max_state : i;
ret = thermal_zone_bind_cooling_device(thermal, i, cdev,
upper, lower, THERMAL_WEIGHT_DEFAULT);
dev_info(&cdev->device, "%s bind to %d: %d-%s\n", cdev->type,
i, ret, ret ? "fail" : "succeed");
}
return ret;
}
static int db8500_cdev_unbind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
struct db8500_thermal_zone *pzone = thermal->devdata;
struct db8500_thsens_platform_data *ptrips = pzone->trip_tab;
int i, ret = -EINVAL;
for (i = 0; i < ptrips->num_trips; i++) {
if (db8500_thermal_match_cdev(cdev, &ptrips->trip_points[i]))
continue;
ret = thermal_zone_unbind_cooling_device(thermal, i, cdev);
dev_info(&cdev->device, "%s unbind from %d: %s\n", cdev->type,
i, ret ? "fail" : "succeed");
}
return ret;
}
static int db8500_sys_get_temp(struct thermal_zone_device *thermal,
unsigned long *temp)
{
struct db8500_thermal_zone *pzone = thermal->devdata;
*temp = pzone->cur_temp_pseudo;
return 0;
}
static int db8500_sys_get_trend(struct thermal_zone_device *thermal,
int trip, enum thermal_trend *trend)
{
struct db8500_thermal_zone *pzone = thermal->devdata;
*trend = pzone->trend;
return 0;
}
static int db8500_sys_get_mode(struct thermal_zone_device *thermal,
enum thermal_device_mode *mode)
{
struct db8500_thermal_zone *pzone = thermal->devdata;
mutex_lock(&pzone->th_lock);
*mode = pzone->mode;
mutex_unlock(&pzone->th_lock);
return 0;
}
static int db8500_sys_set_mode(struct thermal_zone_device *thermal,
enum thermal_device_mode mode)
{
struct db8500_thermal_zone *pzone = thermal->devdata;
mutex_lock(&pzone->th_lock);
pzone->mode = mode;
if (mode == THERMAL_DEVICE_ENABLED)
schedule_work(&pzone->therm_work);
mutex_unlock(&pzone->th_lock);
return 0;
}
static int db8500_sys_get_trip_type(struct thermal_zone_device *thermal,
int trip, enum thermal_trip_type *type)
{
struct db8500_thermal_zone *pzone = thermal->devdata;
struct db8500_thsens_platform_data *ptrips = pzone->trip_tab;
if (trip >= ptrips->num_trips)
return -EINVAL;
*type = ptrips->trip_points[trip].type;
return 0;
}
static int db8500_sys_get_trip_temp(struct thermal_zone_device *thermal,
int trip, unsigned long *temp)
{
struct db8500_thermal_zone *pzone = thermal->devdata;
struct db8500_thsens_platform_data *ptrips = pzone->trip_tab;
if (trip >= ptrips->num_trips)
return -EINVAL;
*temp = ptrips->trip_points[trip].temp;
return 0;
}
static int db8500_sys_get_crit_temp(struct thermal_zone_device *thermal,
unsigned long *temp)
{
struct db8500_thermal_zone *pzone = thermal->devdata;
struct db8500_thsens_platform_data *ptrips = pzone->trip_tab;
int i;
for (i = ptrips->num_trips - 1; i > 0; i--) {
if (ptrips->trip_points[i].type == THERMAL_TRIP_CRITICAL) {
*temp = ptrips->trip_points[i].temp;
return 0;
}
}
return -EINVAL;
}
static void db8500_thermal_update_config(struct db8500_thermal_zone *pzone,
unsigned int idx, enum thermal_trend trend,
unsigned long next_low, unsigned long next_high)
{
prcmu_stop_temp_sense();
pzone->cur_index = idx;
pzone->cur_temp_pseudo = (next_low + next_high)/2;
pzone->trend = trend;
prcmu_config_hotmon((u8)(next_low/1000), (u8)(next_high/1000));
prcmu_start_temp_sense(PRCMU_DEFAULT_MEASURE_TIME);
}
static irqreturn_t prcmu_low_irq_handler(int irq, void *irq_data)
{
struct db8500_thermal_zone *pzone = irq_data;
struct db8500_thsens_platform_data *ptrips = pzone->trip_tab;
unsigned int idx = pzone->cur_index;
unsigned long next_low, next_high;
if (unlikely(idx == 0))
return IRQ_HANDLED;
if (idx == 1) {
next_high = ptrips->trip_points[0].temp;
next_low = PRCMU_DEFAULT_LOW_TEMP;
} else {
next_high = ptrips->trip_points[idx-1].temp;
next_low = ptrips->trip_points[idx-2].temp;
}
idx -= 1;
db8500_thermal_update_config(pzone, idx, THERMAL_TREND_DROPPING,
next_low, next_high);
dev_dbg(&pzone->therm_dev->device,
"PRCMU set max %ld, min %ld\n", next_high, next_low);
schedule_work(&pzone->therm_work);
return IRQ_HANDLED;
}
static irqreturn_t prcmu_high_irq_handler(int irq, void *irq_data)
{
struct db8500_thermal_zone *pzone = irq_data;
struct db8500_thsens_platform_data *ptrips = pzone->trip_tab;
unsigned int idx = pzone->cur_index;
unsigned long next_low, next_high;
if (idx < ptrips->num_trips - 1) {
next_high = ptrips->trip_points[idx+1].temp;
next_low = ptrips->trip_points[idx].temp;
idx += 1;
db8500_thermal_update_config(pzone, idx, THERMAL_TREND_RAISING,
next_low, next_high);
dev_dbg(&pzone->therm_dev->device,
"PRCMU set max %ld, min %ld\n", next_high, next_low);
} else if (idx == ptrips->num_trips - 1)
pzone->cur_temp_pseudo = ptrips->trip_points[idx].temp + 1;
schedule_work(&pzone->therm_work);
return IRQ_HANDLED;
}
static void db8500_thermal_work(struct work_struct *work)
{
enum thermal_device_mode cur_mode;
struct db8500_thermal_zone *pzone;
pzone = container_of(work, struct db8500_thermal_zone, therm_work);
mutex_lock(&pzone->th_lock);
cur_mode = pzone->mode;
mutex_unlock(&pzone->th_lock);
if (cur_mode == THERMAL_DEVICE_DISABLED)
return;
thermal_zone_device_update(pzone->therm_dev);
dev_dbg(&pzone->therm_dev->device, "thermal work finished.\n");
}
static struct db8500_thsens_platform_data*
db8500_thermal_parse_dt(struct platform_device *pdev)
{
struct db8500_thsens_platform_data *ptrips;
struct device_node *np = pdev->dev.of_node;
char prop_name[32];
const char *tmp_str;
u32 tmp_data;
int i, j;
ptrips = devm_kzalloc(&pdev->dev, sizeof(*ptrips), GFP_KERNEL);
if (!ptrips)
return NULL;
if (of_property_read_u32(np, "num-trips", &tmp_data))
goto err_parse_dt;
if (tmp_data > THERMAL_MAX_TRIPS)
goto err_parse_dt;
ptrips->num_trips = tmp_data;
for (i = 0; i < ptrips->num_trips; i++) {
sprintf(prop_name, "trip%d-temp", i);
if (of_property_read_u32(np, prop_name, &tmp_data))
goto err_parse_dt;
ptrips->trip_points[i].temp = tmp_data;
sprintf(prop_name, "trip%d-type", i);
if (of_property_read_string(np, prop_name, &tmp_str))
goto err_parse_dt;
if (!strcmp(tmp_str, "active"))
ptrips->trip_points[i].type = THERMAL_TRIP_ACTIVE;
else if (!strcmp(tmp_str, "passive"))
ptrips->trip_points[i].type = THERMAL_TRIP_PASSIVE;
else if (!strcmp(tmp_str, "hot"))
ptrips->trip_points[i].type = THERMAL_TRIP_HOT;
else if (!strcmp(tmp_str, "critical"))
ptrips->trip_points[i].type = THERMAL_TRIP_CRITICAL;
else
goto err_parse_dt;
sprintf(prop_name, "trip%d-cdev-num", i);
if (of_property_read_u32(np, prop_name, &tmp_data))
goto err_parse_dt;
if (tmp_data > COOLING_DEV_MAX)
goto err_parse_dt;
for (j = 0; j < tmp_data; j++) {
sprintf(prop_name, "trip%d-cdev-name%d", i, j);
if (of_property_read_string(np, prop_name, &tmp_str))
goto err_parse_dt;
if (strlen(tmp_str) >= THERMAL_NAME_LENGTH)
goto err_parse_dt;
strcpy(ptrips->trip_points[i].cdev_name[j], tmp_str);
}
}
return ptrips;
err_parse_dt:
dev_err(&pdev->dev, "Parsing device tree data error.\n");
return NULL;
}
static inline struct db8500_thsens_platform_data*
db8500_thermal_parse_dt(struct platform_device *pdev)
{
return NULL;
}
static int db8500_thermal_probe(struct platform_device *pdev)
{
struct db8500_thermal_zone *pzone = NULL;
struct db8500_thsens_platform_data *ptrips = NULL;
struct device_node *np = pdev->dev.of_node;
int low_irq, high_irq, ret = 0;
unsigned long dft_low, dft_high;
if (np)
ptrips = db8500_thermal_parse_dt(pdev);
else
ptrips = dev_get_platdata(&pdev->dev);
if (!ptrips)
return -EINVAL;
pzone = devm_kzalloc(&pdev->dev, sizeof(*pzone), GFP_KERNEL);
if (!pzone)
return -ENOMEM;
mutex_init(&pzone->th_lock);
mutex_lock(&pzone->th_lock);
pzone->mode = THERMAL_DEVICE_DISABLED;
pzone->trip_tab = ptrips;
INIT_WORK(&pzone->therm_work, db8500_thermal_work);
low_irq = platform_get_irq_byname(pdev, "IRQ_HOTMON_LOW");
if (low_irq < 0) {
dev_err(&pdev->dev, "Get IRQ_HOTMON_LOW failed.\n");
ret = low_irq;
goto out_unlock;
}
ret = devm_request_threaded_irq(&pdev->dev, low_irq, NULL,
prcmu_low_irq_handler, IRQF_NO_SUSPEND | IRQF_ONESHOT,
"dbx500_temp_low", pzone);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to allocate temp low irq.\n");
goto out_unlock;
}
high_irq = platform_get_irq_byname(pdev, "IRQ_HOTMON_HIGH");
if (high_irq < 0) {
dev_err(&pdev->dev, "Get IRQ_HOTMON_HIGH failed.\n");
ret = high_irq;
goto out_unlock;
}
ret = devm_request_threaded_irq(&pdev->dev, high_irq, NULL,
prcmu_high_irq_handler, IRQF_NO_SUSPEND | IRQF_ONESHOT,
"dbx500_temp_high", pzone);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to allocate temp high irq.\n");
goto out_unlock;
}
pzone->therm_dev = thermal_zone_device_register("db8500_thermal_zone",
ptrips->num_trips, 0, pzone, &thdev_ops, NULL, 0, 0);
if (IS_ERR(pzone->therm_dev)) {
dev_err(&pdev->dev, "Register thermal zone device failed.\n");
ret = PTR_ERR(pzone->therm_dev);
goto out_unlock;
}
dev_info(&pdev->dev, "Thermal zone device registered.\n");
dft_low = PRCMU_DEFAULT_LOW_TEMP;
dft_high = ptrips->trip_points[0].temp;
db8500_thermal_update_config(pzone, 0, THERMAL_TREND_STABLE,
dft_low, dft_high);
platform_set_drvdata(pdev, pzone);
pzone->mode = THERMAL_DEVICE_ENABLED;
out_unlock:
mutex_unlock(&pzone->th_lock);
return ret;
}
static int db8500_thermal_remove(struct platform_device *pdev)
{
struct db8500_thermal_zone *pzone = platform_get_drvdata(pdev);
thermal_zone_device_unregister(pzone->therm_dev);
cancel_work_sync(&pzone->therm_work);
mutex_destroy(&pzone->th_lock);
return 0;
}
static int db8500_thermal_suspend(struct platform_device *pdev,
pm_message_t state)
{
struct db8500_thermal_zone *pzone = platform_get_drvdata(pdev);
flush_work(&pzone->therm_work);
prcmu_stop_temp_sense();
return 0;
}
static int db8500_thermal_resume(struct platform_device *pdev)
{
struct db8500_thermal_zone *pzone = platform_get_drvdata(pdev);
struct db8500_thsens_platform_data *ptrips = pzone->trip_tab;
unsigned long dft_low, dft_high;
dft_low = PRCMU_DEFAULT_LOW_TEMP;
dft_high = ptrips->trip_points[0].temp;
db8500_thermal_update_config(pzone, 0, THERMAL_TREND_STABLE,
dft_low, dft_high);
return 0;
}
