static void omap_thermal_work(struct work_struct *work)
{
struct omap_thermal_data *data = container_of(work,
struct omap_thermal_data, thermal_wq);
thermal_zone_device_update(data->omap_thermal);
dev_dbg(&data->omap_thermal->device, "updated thermal zone %s\n",
data->omap_thermal->type);
}
static inline int omap_thermal_hotspot_temperature(int t, int s, int c)
{
int delta = t * s / 1000 + c;
if (delta < 0)
delta = 0;
return t + delta;
}
static inline int omap_thermal_get_temp(struct thermal_zone_device *thermal,
unsigned long *temp)
{
struct omap_thermal_data *data = thermal->devdata;
struct omap_bandgap *bg_ptr;
struct omap_temp_sensor *s;
int ret, tmp, pcb_temp, slope, constant;
if (!data)
return 0;
bg_ptr = data->bg_ptr;
s = &bg_ptr->conf->sensors[data->sensor_id];
ret = omap_bandgap_read_temperature(bg_ptr, data->sensor_id, &tmp);
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
*temp = omap_thermal_hotspot_temperature(tmp, slope, constant);
return ret;
}
static int omap_thermal_bind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
struct omap_thermal_data *data = thermal->devdata;
int max, id;
if (IS_ERR_OR_NULL(data))
return -ENODEV;
if (data->cool_dev != cdev)
return 0;
id = data->sensor_id;
max = data->bg_ptr->conf->sensors[id].cooling_data.freq_clip_count;
return thermal_zone_bind_cooling_device(thermal, 0, cdev,
THERMAL_NO_LIMIT,
THERMAL_NO_LIMIT);
}
static int omap_thermal_unbind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
struct omap_thermal_data *data = thermal->devdata;
if (IS_ERR_OR_NULL(data))
return -ENODEV;
if (data->cool_dev != cdev)
return 0;
return thermal_zone_unbind_cooling_device(thermal, 0, cdev);
}
static int omap_thermal_get_mode(struct thermal_zone_device *thermal,
enum thermal_device_mode *mode)
{
struct omap_thermal_data *data = thermal->devdata;
if (data)
*mode = data->mode;
return 0;
}
static int omap_thermal_set_mode(struct thermal_zone_device *thermal,
enum thermal_device_mode mode)
{
struct omap_thermal_data *data = thermal->devdata;
if (!data->omap_thermal) {
dev_notice(&thermal->device, "thermal zone not registered\n");
return 0;
}
mutex_lock(&data->omap_thermal->lock);
if (mode == THERMAL_DEVICE_ENABLED)
data->omap_thermal->polling_delay = FAST_TEMP_MONITORING_RATE;
else
data->omap_thermal->polling_delay = 0;
mutex_unlock(&data->omap_thermal->lock);
data->mode = mode;
thermal_zone_device_update(data->omap_thermal);
dev_dbg(&thermal->device, "thermal polling set for duration=%d msec\n",
data->omap_thermal->polling_delay);
return 0;
}
static int omap_thermal_get_trip_type(struct thermal_zone_device *thermal,
int trip, enum thermal_trip_type *type)
{
if (!omap_thermal_is_valid_trip(trip))
return -EINVAL;
if (trip + 1 == OMAP_TRIP_NUMBER)
*type = THERMAL_TRIP_CRITICAL;
else
*type = THERMAL_TRIP_PASSIVE;
return 0;
}
static int omap_thermal_get_trip_temp(struct thermal_zone_device *thermal,
int trip, unsigned long *temp)
{
if (!omap_thermal_is_valid_trip(trip))
return -EINVAL;
*temp = omap_thermal_get_trip_value(trip);
return 0;
}
static int omap_thermal_get_crit_temp(struct thermal_zone_device *thermal,
unsigned long *temp)
{
return omap_thermal_get_trip_temp(thermal, OMAP_TRIP_NUMBER - 1, temp);
}
static struct omap_thermal_data
*omap_thermal_build_data(struct omap_bandgap *bg_ptr, int id)
{
struct omap_thermal_data *data;
data = devm_kzalloc(bg_ptr->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
dev_err(bg_ptr->dev, "kzalloc fail\n");
return NULL;
}
data->sensor_id = id;
data->bg_ptr = bg_ptr;
data->mode = THERMAL_DEVICE_ENABLED;
INIT_WORK(&data->thermal_wq, omap_thermal_work);
return data;
}
int omap_thermal_expose_sensor(struct omap_bandgap *bg_ptr, int id,
char *domain)
{
struct omap_thermal_pdata pdata;
data = omap_bandgap_get_sensor_data(bg_ptr, id);
if (!data)
data = omap_thermal_build_pdata(bg_ptr, id);
if (!data)
return -EINVAL;
data->omap_thermal = thermal_zone_device_register(domain,
OMAP_TRIP_NUMBER, 0, data, &omap_thermal_ops,
FAST_TEMP_MONITORING_RATE,
FAST_TEMP_MONITORING_RATE);
if (IS_ERR_OR_NULL(data->omap_thermal)) {
dev_err(bg_ptr->dev, "thermal zone device is NULL\n");
return PTR_ERR(data->omap_thermal);
}
data->omap_thermal->polling_delay = FAST_TEMP_MONITORING_RATE;
omap_bandgap_set_sensor_data(bg_ptr, id, data);
return 0;
}
int omap_thermal_remove_sensor(struct omap_bandgap *bg_ptr, int id)
{
struct omap_thermal_data *data;
data = omap_bandgap_get_sensor_data(bg_ptr, id);
thermal_zone_device_unregister(data->omap_thermal);
return 0;
}
int omap_thermal_report_sensor_temperature(struct omap_bandgap *bg_ptr, int id)
{
struct omap_thermal_data *data;
data = omap_bandgap_get_sensor_data(bg_ptr, id);
schedule_work(&data->thermal_wq);
return 0;
}
static int omap_thermal_build_cpufreq_clip(struct omap_bandgap *bg_ptr,
struct freq_clip_table **tab_ptr,
int *tab_size)
{
struct cpufreq_frequency_table *freq_table;
struct freq_clip_table *tab;
int i, count = 0;
freq_table = cpufreq_frequency_get_table(0);
if (IS_ERR_OR_NULL(freq_table)) {
dev_err(bg_ptr->dev,
"%s: failed to get cpufreq table (%p)\n",
__func__, freq_table);
return -EINVAL;
}
for (i = 0; freq_table[i].frequency != CPUFREQ_TABLE_END; i++) {
unsigned int freq = freq_table[i].frequency;
if (freq == CPUFREQ_ENTRY_INVALID)
continue;
count++;
}
tab = devm_kzalloc(bg_ptr->dev, sizeof(*tab) * count, GFP_KERNEL);
if (!tab) {
dev_err(bg_ptr->dev,
"%s: no memory available\n", __func__);
return -ENOMEM;
}
for (i = 0; freq_table[i].frequency != CPUFREQ_TABLE_END; i++) {
unsigned int freq = freq_table[i].frequency;
if (freq == CPUFREQ_ENTRY_INVALID)
continue;
tab[count - i - 1].freq_clip_max = freq;
tab[count - i - 1].temp_level = OMAP_TRIP_HOT;
tab[count - i - 1].mask_val = cpumask_of(0);
}
*tab_ptr = tab;
*tab_size = count;
return 0;
}
int omap_thermal_register_cpu_cooling(struct omap_bandgap *bg_ptr, int id)
{
struct omap_thermal_data *data;
struct freq_clip_table *tab_ptr;
int tab_size, ret;
data = omap_bandgap_get_sensor_data(bg_ptr, id);
if (!data)
data = omap_thermal_build_pdata(bg_ptr, id);
if (!data)
return -EINVAL;
ret = omap_thermal_build_cpufreq_clip(bg_ptr, &tab_ptr, &tab_size);
if (ret < 0) {
dev_err(bg_ptr->dev,
"%s: failed to build cpufreq clip table\n", __func__);
return ret;
}
data->cool_dev = cpufreq_cooling_register(tab_ptr, tab_size);
if (IS_ERR_OR_NULL(data->cool_dev)) {
dev_err(bg_ptr->dev,
"Failed to register cpufreq cooling device\n");
return PTR_ERR(data->cool_dev);
}
bg_ptr->conf->sensors[id].cooling_data.freq_clip_count = tab_size;
omap_bandgap_set_sensor_data(bg_ptr, id, data);
return 0;
}
int omap_thermal_unregister_cpu_cooling(struct omap_bandgap *bg_ptr, int id)
{
struct omap_thermal_data *data;
data = omap_bandgap_get_sensor_data(bg_ptr, id);
cpufreq_cooling_unregister(data->cool_dev);
return 0;
}
