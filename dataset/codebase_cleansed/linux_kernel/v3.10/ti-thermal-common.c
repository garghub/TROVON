static void ti_thermal_work(struct work_struct *work)
{
struct ti_thermal_data *data = container_of(work,
struct ti_thermal_data, thermal_wq);
thermal_zone_device_update(data->ti_thermal);
dev_dbg(&data->ti_thermal->device, "updated thermal zone %s\n",
data->ti_thermal->type);
}
static inline int ti_thermal_hotspot_temperature(int t, int s, int c)
{
int delta = t * s / 1000 + c;
if (delta < 0)
delta = 0;
return t + delta;
}
static inline int ti_thermal_get_temp(struct thermal_zone_device *thermal,
unsigned long *temp)
{
struct ti_thermal_data *data = thermal->devdata;
struct ti_bandgap *bgp;
const struct ti_temp_sensor *s;
int ret, tmp, pcb_temp, slope, constant;
if (!data)
return 0;
bgp = data->bgp;
s = &bgp->conf->sensors[data->sensor_id];
ret = ti_bandgap_read_temperature(bgp, data->sensor_id, &tmp);
if (ret)
return ret;
pcb_temp = 0;
if (pcb_temp) {
tmp -= pcb_temp;
slope = s->slope_pcb;
constant = s->constant_pcb;
} else {
slope = s->slope;
constant = s->constant;
}
*temp = ti_thermal_hotspot_temperature(tmp, slope, constant);
return ret;
}
static int ti_thermal_bind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
struct ti_thermal_data *data = thermal->devdata;
int id;
if (IS_ERR_OR_NULL(data))
return -ENODEV;
if (data->cool_dev != cdev)
return 0;
id = data->sensor_id;
return thermal_zone_bind_cooling_device(thermal, 0, cdev,
THERMAL_NO_LIMIT,
THERMAL_NO_LIMIT);
}
static int ti_thermal_unbind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
struct ti_thermal_data *data = thermal->devdata;
if (IS_ERR_OR_NULL(data))
return -ENODEV;
if (data->cool_dev != cdev)
return 0;
return thermal_zone_unbind_cooling_device(thermal, 0, cdev);
}
static int ti_thermal_get_mode(struct thermal_zone_device *thermal,
enum thermal_device_mode *mode)
{
struct ti_thermal_data *data = thermal->devdata;
if (data)
*mode = data->mode;
return 0;
}
static int ti_thermal_set_mode(struct thermal_zone_device *thermal,
enum thermal_device_mode mode)
{
struct ti_thermal_data *data = thermal->devdata;
if (!data->ti_thermal) {
dev_notice(&thermal->device, "thermal zone not registered\n");
return 0;
}
mutex_lock(&data->ti_thermal->lock);
if (mode == THERMAL_DEVICE_ENABLED)
data->ti_thermal->polling_delay = FAST_TEMP_MONITORING_RATE;
else
data->ti_thermal->polling_delay = 0;
mutex_unlock(&data->ti_thermal->lock);
data->mode = mode;
thermal_zone_device_update(data->ti_thermal);
dev_dbg(&thermal->device, "thermal polling set for duration=%d msec\n",
data->ti_thermal->polling_delay);
return 0;
}
static int ti_thermal_get_trip_type(struct thermal_zone_device *thermal,
int trip, enum thermal_trip_type *type)
{
if (!ti_thermal_is_valid_trip(trip))
return -EINVAL;
if (trip + 1 == OMAP_TRIP_NUMBER)
*type = THERMAL_TRIP_CRITICAL;
else
*type = THERMAL_TRIP_PASSIVE;
return 0;
}
static int ti_thermal_get_trip_temp(struct thermal_zone_device *thermal,
int trip, unsigned long *temp)
{
if (!ti_thermal_is_valid_trip(trip))
return -EINVAL;
*temp = ti_thermal_get_trip_value(trip);
return 0;
}
static int ti_thermal_get_trend(struct thermal_zone_device *thermal,
int trip, enum thermal_trend *trend)
{
struct ti_thermal_data *data = thermal->devdata;
struct ti_bandgap *bgp;
int id, tr, ret = 0;
bgp = data->bgp;
id = data->sensor_id;
ret = ti_bandgap_get_trend(bgp, id, &tr);
if (ret)
return ret;
if (tr > 0)
*trend = THERMAL_TREND_RAISING;
else if (tr < 0)
*trend = THERMAL_TREND_DROPPING;
else
*trend = THERMAL_TREND_STABLE;
return 0;
}
static int ti_thermal_get_crit_temp(struct thermal_zone_device *thermal,
unsigned long *temp)
{
return ti_thermal_get_trip_temp(thermal, OMAP_TRIP_NUMBER - 1, temp);
}
static struct ti_thermal_data
*ti_thermal_build_data(struct ti_bandgap *bgp, int id)
{
struct ti_thermal_data *data;
data = devm_kzalloc(bgp->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
dev_err(bgp->dev, "kzalloc fail\n");
return NULL;
}
data->sensor_id = id;
data->bgp = bgp;
data->mode = THERMAL_DEVICE_ENABLED;
INIT_WORK(&data->thermal_wq, ti_thermal_work);
return data;
}
int ti_thermal_expose_sensor(struct ti_bandgap *bgp, int id,
char *domain)
{
struct ti_thermal_data *data;
data = ti_bandgap_get_sensor_data(bgp, id);
if (IS_ERR_OR_NULL(data))
data = ti_thermal_build_data(bgp, id);
if (!data)
return -EINVAL;
data->ti_thermal = thermal_zone_device_register(domain,
OMAP_TRIP_NUMBER, 0, data, &ti_thermal_ops,
NULL, FAST_TEMP_MONITORING_RATE,
FAST_TEMP_MONITORING_RATE);
if (IS_ERR_OR_NULL(data->ti_thermal)) {
dev_err(bgp->dev, "thermal zone device is NULL\n");
return PTR_ERR(data->ti_thermal);
}
data->ti_thermal->polling_delay = FAST_TEMP_MONITORING_RATE;
ti_bandgap_set_sensor_data(bgp, id, data);
return 0;
}
int ti_thermal_remove_sensor(struct ti_bandgap *bgp, int id)
{
struct ti_thermal_data *data;
data = ti_bandgap_get_sensor_data(bgp, id);
thermal_zone_device_unregister(data->ti_thermal);
return 0;
}
int ti_thermal_report_sensor_temperature(struct ti_bandgap *bgp, int id)
{
struct ti_thermal_data *data;
data = ti_bandgap_get_sensor_data(bgp, id);
schedule_work(&data->thermal_wq);
return 0;
}
int ti_thermal_register_cpu_cooling(struct ti_bandgap *bgp, int id)
{
struct ti_thermal_data *data;
data = ti_bandgap_get_sensor_data(bgp, id);
if (IS_ERR_OR_NULL(data))
data = ti_thermal_build_data(bgp, id);
if (!data)
return -EINVAL;
if (!cpufreq_get_current_driver()) {
dev_dbg(bgp->dev, "no cpufreq driver yet\n");
return -EPROBE_DEFER;
}
data->cool_dev = cpufreq_cooling_register(cpu_present_mask);
if (IS_ERR_OR_NULL(data->cool_dev)) {
dev_err(bgp->dev,
"Failed to register cpufreq cooling device\n");
return PTR_ERR(data->cool_dev);
}
ti_bandgap_set_sensor_data(bgp, id, data);
return 0;
}
int ti_thermal_unregister_cpu_cooling(struct ti_bandgap *bgp, int id)
{
struct ti_thermal_data *data;
data = ti_bandgap_get_sensor_data(bgp, id);
cpufreq_cooling_unregister(data->cool_dev);
return 0;
}
