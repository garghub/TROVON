static void ti_thermal_work(struct work_struct *work)
{
struct ti_thermal_data *data = container_of(work,
struct ti_thermal_data, thermal_wq);
thermal_zone_device_update(data->ti_thermal, THERMAL_EVENT_UNSPECIFIED);
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
static inline int __ti_thermal_get_temp(void *devdata, int *temp)
{
struct thermal_zone_device *pcb_tz = NULL;
struct ti_thermal_data *data = devdata;
struct ti_bandgap *bgp;
const struct ti_temp_sensor *s;
int ret, tmp, slope, constant;
int pcb_temp;
if (!data)
return 0;
bgp = data->bgp;
s = &bgp->conf->sensors[data->sensor_id];
ret = ti_bandgap_read_temperature(bgp, data->sensor_id, &tmp);
if (ret)
return ret;
slope = thermal_zone_get_slope(data->ti_thermal);
constant = thermal_zone_get_offset(data->ti_thermal);
pcb_tz = data->pcb_tz;
if (!IS_ERR(pcb_tz)) {
ret = thermal_zone_get_temp(pcb_tz, &pcb_temp);
if (!ret) {
tmp -= pcb_temp;
slope = s->slope_pcb;
constant = s->constant_pcb;
} else {
dev_err(bgp->dev,
"Failed to read PCB state. Using defaults\n");
ret = 0;
}
}
*temp = ti_thermal_hotspot_temperature(tmp, slope, constant);
return ret;
}
static inline int ti_thermal_get_temp(struct thermal_zone_device *thermal,
int *temp)
{
struct ti_thermal_data *data = thermal->devdata;
return __ti_thermal_get_temp(data, temp);
}
static int __ti_thermal_get_trend(void *p, int trip, enum thermal_trend *trend)
{
struct ti_thermal_data *data = p;
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
data->pcb_tz = thermal_zone_get_zone_by_name("pcb");
INIT_WORK(&data->thermal_wq, ti_thermal_work);
return data;
}
int ti_thermal_expose_sensor(struct ti_bandgap *bgp, int id,
char *domain)
{
struct ti_thermal_data *data;
data = ti_bandgap_get_sensor_data(bgp, id);
if (!data || IS_ERR(data))
data = ti_thermal_build_data(bgp, id);
if (!data)
return -EINVAL;
data->ti_thermal = devm_thermal_zone_of_sensor_register(bgp->dev, id,
data, &ti_of_thermal_ops);
if (IS_ERR(data->ti_thermal)) {
dev_err(bgp->dev, "thermal zone device is NULL\n");
return PTR_ERR(data->ti_thermal);
}
ti_bandgap_set_sensor_data(bgp, id, data);
ti_bandgap_write_update_interval(bgp, data->sensor_id,
data->ti_thermal->polling_delay);
return 0;
}
int ti_thermal_remove_sensor(struct ti_bandgap *bgp, int id)
{
struct ti_thermal_data *data;
data = ti_bandgap_get_sensor_data(bgp, id);
if (data && data->ti_thermal) {
if (data->our_zone)
thermal_zone_device_unregister(data->ti_thermal);
}
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
struct device_node *np = bgp->dev->of_node;
if (of_find_property(np, "#thermal-sensor-cells", NULL))
return 0;
data = ti_bandgap_get_sensor_data(bgp, id);
if (!data || IS_ERR(data))
data = ti_thermal_build_data(bgp, id);
if (!data)
return -EINVAL;
data->policy = cpufreq_cpu_get(0);
if (!data->policy) {
pr_debug("%s: CPUFreq policy not found\n", __func__);
return -EPROBE_DEFER;
}
data->cool_dev = cpufreq_cooling_register(data->policy);
if (IS_ERR(data->cool_dev)) {
int ret = PTR_ERR(data->cool_dev);
dev_err(bgp->dev, "Failed to register cpu cooling device %d\n",
ret);
cpufreq_cpu_put(data->policy);
return ret;
}
ti_bandgap_set_sensor_data(bgp, id, data);
return 0;
}
int ti_thermal_unregister_cpu_cooling(struct ti_bandgap *bgp, int id)
{
struct ti_thermal_data *data;
data = ti_bandgap_get_sensor_data(bgp, id);
if (data) {
cpufreq_cooling_unregister(data->cool_dev);
cpufreq_cpu_put(data->policy);
}
return 0;
}
