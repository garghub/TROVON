static int of_thermal_get_temp(struct thermal_zone_device *tz,
unsigned long *temp)
{
struct __thermal_zone *data = tz->devdata;
if (!data->get_temp)
return -EINVAL;
return data->get_temp(data->sensor_data, temp);
}
static int of_thermal_get_trend(struct thermal_zone_device *tz, int trip,
enum thermal_trend *trend)
{
struct __thermal_zone *data = tz->devdata;
long dev_trend;
int r;
if (!data->get_trend)
return -EINVAL;
r = data->get_trend(data->sensor_data, &dev_trend);
if (r)
return r;
if (dev_trend > 0)
*trend = THERMAL_TREND_RAISING;
else if (dev_trend < 0)
*trend = THERMAL_TREND_DROPPING;
else
*trend = THERMAL_TREND_STABLE;
return 0;
}
static int of_thermal_bind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
struct __thermal_zone *data = thermal->devdata;
int i;
if (!data || IS_ERR(data))
return -ENODEV;
for (i = 0; i < data->num_tbps; i++) {
struct __thermal_bind_params *tbp = data->tbps + i;
if (tbp->cooling_device == cdev->np) {
int ret;
ret = thermal_zone_bind_cooling_device(thermal,
tbp->trip_id, cdev,
tbp->min,
tbp->max);
if (ret)
return ret;
}
}
return 0;
}
static int of_thermal_unbind(struct thermal_zone_device *thermal,
struct thermal_cooling_device *cdev)
{
struct __thermal_zone *data = thermal->devdata;
int i;
if (!data || IS_ERR(data))
return -ENODEV;
for (i = 0; i < data->num_tbps; i++) {
struct __thermal_bind_params *tbp = data->tbps + i;
if (tbp->cooling_device == cdev->np) {
int ret;
ret = thermal_zone_unbind_cooling_device(thermal,
tbp->trip_id, cdev);
if (ret)
return ret;
}
}
return 0;
}
static int of_thermal_get_mode(struct thermal_zone_device *tz,
enum thermal_device_mode *mode)
{
struct __thermal_zone *data = tz->devdata;
*mode = data->mode;
return 0;
}
static int of_thermal_set_mode(struct thermal_zone_device *tz,
enum thermal_device_mode mode)
{
struct __thermal_zone *data = tz->devdata;
mutex_lock(&tz->lock);
if (mode == THERMAL_DEVICE_ENABLED)
tz->polling_delay = data->polling_delay;
else
tz->polling_delay = 0;
mutex_unlock(&tz->lock);
data->mode = mode;
thermal_zone_device_update(tz);
return 0;
}
static int of_thermal_get_trip_type(struct thermal_zone_device *tz, int trip,
enum thermal_trip_type *type)
{
struct __thermal_zone *data = tz->devdata;
if (trip >= data->ntrips || trip < 0)
return -EDOM;
*type = data->trips[trip].type;
return 0;
}
static int of_thermal_get_trip_temp(struct thermal_zone_device *tz, int trip,
unsigned long *temp)
{
struct __thermal_zone *data = tz->devdata;
if (trip >= data->ntrips || trip < 0)
return -EDOM;
*temp = data->trips[trip].temperature;
return 0;
}
static int of_thermal_set_trip_temp(struct thermal_zone_device *tz, int trip,
unsigned long temp)
{
struct __thermal_zone *data = tz->devdata;
if (trip >= data->ntrips || trip < 0)
return -EDOM;
data->trips[trip].temperature = temp;
return 0;
}
static int of_thermal_get_trip_hyst(struct thermal_zone_device *tz, int trip,
unsigned long *hyst)
{
struct __thermal_zone *data = tz->devdata;
if (trip >= data->ntrips || trip < 0)
return -EDOM;
*hyst = data->trips[trip].hysteresis;
return 0;
}
static int of_thermal_set_trip_hyst(struct thermal_zone_device *tz, int trip,
unsigned long hyst)
{
struct __thermal_zone *data = tz->devdata;
if (trip >= data->ntrips || trip < 0)
return -EDOM;
data->trips[trip].hysteresis = hyst;
return 0;
}
static int of_thermal_get_crit_temp(struct thermal_zone_device *tz,
unsigned long *temp)
{
struct __thermal_zone *data = tz->devdata;
int i;
for (i = 0; i < data->ntrips; i++)
if (data->trips[i].type == THERMAL_TRIP_CRITICAL) {
*temp = data->trips[i].temperature;
return 0;
}
return -EINVAL;
}
static struct thermal_zone_device *
thermal_zone_of_add_sensor(struct device_node *zone,
struct device_node *sensor, void *data,
int (*get_temp)(void *, long *),
int (*get_trend)(void *, long *))
{
struct thermal_zone_device *tzd;
struct __thermal_zone *tz;
tzd = thermal_zone_get_zone_by_name(zone->name);
if (IS_ERR(tzd))
return ERR_PTR(-EPROBE_DEFER);
tz = tzd->devdata;
mutex_lock(&tzd->lock);
tz->get_temp = get_temp;
tz->get_trend = get_trend;
tz->sensor_data = data;
tzd->ops->get_temp = of_thermal_get_temp;
tzd->ops->get_trend = of_thermal_get_trend;
mutex_unlock(&tzd->lock);
return tzd;
}
struct thermal_zone_device *
thermal_zone_of_sensor_register(struct device *dev, int sensor_id,
void *data, int (*get_temp)(void *, long *),
int (*get_trend)(void *, long *))
{
struct device_node *np, *child, *sensor_np;
np = of_find_node_by_name(NULL, "thermal-zones");
if (!np)
return ERR_PTR(-ENODEV);
if (!dev || !dev->of_node)
return ERR_PTR(-EINVAL);
sensor_np = dev->of_node;
for_each_child_of_node(np, child) {
struct of_phandle_args sensor_specs;
int ret, id;
ret = of_parse_phandle_with_args(child, "thermal-sensors",
"#thermal-sensor-cells",
0, &sensor_specs);
if (ret)
continue;
if (sensor_specs.args_count >= 1) {
id = sensor_specs.args[0];
WARN(sensor_specs.args_count > 1,
"%s: too many cells in sensor specifier %d\n",
sensor_specs.np->name, sensor_specs.args_count);
} else {
id = 0;
}
if (sensor_specs.np == sensor_np && id == sensor_id) {
of_node_put(np);
return thermal_zone_of_add_sensor(child, sensor_np,
data,
get_temp,
get_trend);
}
}
of_node_put(np);
return ERR_PTR(-ENODEV);
}
void thermal_zone_of_sensor_unregister(struct device *dev,
struct thermal_zone_device *tzd)
{
struct __thermal_zone *tz;
if (!dev || !tzd || !tzd->devdata)
return;
tz = tzd->devdata;
if (!tz)
return;
mutex_lock(&tzd->lock);
tzd->ops->get_temp = NULL;
tzd->ops->get_trend = NULL;
tz->get_temp = NULL;
tz->get_trend = NULL;
tz->sensor_data = NULL;
mutex_unlock(&tzd->lock);
}
static int thermal_of_populate_bind_params(struct device_node *np,
struct __thermal_bind_params *__tbp,
struct __thermal_trip *trips,
int ntrips)
{
struct of_phandle_args cooling_spec;
struct device_node *trip;
int ret, i;
u32 prop;
__tbp->usage = 0;
ret = of_property_read_u32(np, "contribution", &prop);
if (ret == 0)
__tbp->usage = prop;
trip = of_parse_phandle(np, "trip", 0);
if (!trip) {
pr_err("missing trip property\n");
return -ENODEV;
}
for (i = 0; i < ntrips; i++)
if (trip == trips[i].np) {
__tbp->trip_id = i;
break;
}
if (i == ntrips) {
ret = -ENODEV;
goto end;
}
ret = of_parse_phandle_with_args(np, "cooling-device", "#cooling-cells",
0, &cooling_spec);
if (ret < 0) {
pr_err("missing cooling_device property\n");
goto end;
}
__tbp->cooling_device = cooling_spec.np;
if (cooling_spec.args_count >= 2) {
__tbp->min = cooling_spec.args[0];
__tbp->max = cooling_spec.args[1];
} else {
pr_err("wrong reference to cooling device, missing limits\n");
}
end:
of_node_put(trip);
return ret;
}
static int thermal_of_get_trip_type(struct device_node *np,
enum thermal_trip_type *type)
{
const char *t;
int err, i;
err = of_property_read_string(np, "type", &t);
if (err < 0)
return err;
for (i = 0; i < ARRAY_SIZE(trip_types); i++)
if (!strcasecmp(t, trip_types[i])) {
*type = i;
return 0;
}
return -ENODEV;
}
static int thermal_of_populate_trip(struct device_node *np,
struct __thermal_trip *trip)
{
int prop;
int ret;
ret = of_property_read_u32(np, "temperature", &prop);
if (ret < 0) {
pr_err("missing temperature property\n");
return ret;
}
trip->temperature = prop;
ret = of_property_read_u32(np, "hysteresis", &prop);
if (ret < 0) {
pr_err("missing hysteresis property\n");
return ret;
}
trip->hysteresis = prop;
ret = thermal_of_get_trip_type(np, &trip->type);
if (ret < 0) {
pr_err("wrong trip type property\n");
return ret;
}
trip->np = np;
return 0;
}
static struct __thermal_zone *
thermal_of_build_thermal_zone(struct device_node *np)
{
struct device_node *child = NULL, *gchild;
struct __thermal_zone *tz;
int ret, i;
u32 prop;
if (!np) {
pr_err("no thermal zone np\n");
return ERR_PTR(-EINVAL);
}
tz = kzalloc(sizeof(*tz), GFP_KERNEL);
if (!tz)
return ERR_PTR(-ENOMEM);
ret = of_property_read_u32(np, "polling-delay-passive", &prop);
if (ret < 0) {
pr_err("missing polling-delay-passive property\n");
goto free_tz;
}
tz->passive_delay = prop;
ret = of_property_read_u32(np, "polling-delay", &prop);
if (ret < 0) {
pr_err("missing polling-delay property\n");
goto free_tz;
}
tz->polling_delay = prop;
child = of_get_child_by_name(np, "trips");
if (!child)
goto finish;
tz->ntrips = of_get_child_count(child);
if (tz->ntrips == 0)
goto finish;
tz->trips = kzalloc(tz->ntrips * sizeof(*tz->trips), GFP_KERNEL);
if (!tz->trips) {
ret = -ENOMEM;
goto free_tz;
}
i = 0;
for_each_child_of_node(child, gchild) {
ret = thermal_of_populate_trip(gchild, &tz->trips[i++]);
if (ret)
goto free_trips;
}
of_node_put(child);
child = of_get_child_by_name(np, "cooling-maps");
if (!child)
goto finish;
tz->num_tbps = of_get_child_count(child);
if (tz->num_tbps == 0)
goto finish;
tz->tbps = kzalloc(tz->num_tbps * sizeof(*tz->tbps), GFP_KERNEL);
if (!tz->tbps) {
ret = -ENOMEM;
goto free_trips;
}
i = 0;
for_each_child_of_node(child, gchild)
ret = thermal_of_populate_bind_params(gchild, &tz->tbps[i++],
tz->trips, tz->ntrips);
if (ret)
goto free_tbps;
finish:
of_node_put(child);
tz->mode = THERMAL_DEVICE_DISABLED;
return tz;
free_tbps:
kfree(tz->tbps);
free_trips:
kfree(tz->trips);
free_tz:
kfree(tz);
of_node_put(child);
return ERR_PTR(ret);
}
static inline void of_thermal_free_zone(struct __thermal_zone *tz)
{
kfree(tz->tbps);
kfree(tz->trips);
kfree(tz);
}
int __init of_parse_thermal_zones(void)
{
struct device_node *np, *child;
struct __thermal_zone *tz;
struct thermal_zone_device_ops *ops;
np = of_find_node_by_name(NULL, "thermal-zones");
if (!np) {
pr_debug("unable to find thermal zones\n");
return 0;
}
for_each_child_of_node(np, child) {
struct thermal_zone_device *zone;
struct thermal_zone_params *tzp;
tz = thermal_of_build_thermal_zone(child);
if (IS_ERR(tz)) {
pr_err("failed to build thermal zone %s: %ld\n",
child->name,
PTR_ERR(tz));
continue;
}
ops = kmemdup(&of_thermal_ops, sizeof(*ops), GFP_KERNEL);
if (!ops)
goto exit_free;
tzp = kzalloc(sizeof(*tzp), GFP_KERNEL);
if (!tzp) {
kfree(ops);
goto exit_free;
}
tzp->no_hwmon = true;
zone = thermal_zone_device_register(child->name, tz->ntrips,
0, tz,
ops, tzp,
tz->passive_delay,
tz->polling_delay);
if (IS_ERR(zone)) {
pr_err("Failed to build %s zone %ld\n", child->name,
PTR_ERR(zone));
kfree(tzp);
kfree(ops);
of_thermal_free_zone(tz);
}
}
return 0;
exit_free:
of_thermal_free_zone(tz);
of_thermal_destroy_zones();
return -ENOMEM;
}
void of_thermal_destroy_zones(void)
{
struct device_node *np, *child;
np = of_find_node_by_name(NULL, "thermal-zones");
if (!np) {
pr_err("unable to find thermal zones\n");
return;
}
for_each_child_of_node(np, child) {
struct thermal_zone_device *zone;
zone = thermal_zone_get_zone_by_name(child->name);
if (IS_ERR(zone))
continue;
thermal_zone_device_unregister(zone);
kfree(zone->tzp);
kfree(zone->ops);
of_thermal_free_zone(zone->devdata);
}
}
