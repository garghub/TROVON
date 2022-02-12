static unsigned long get_target_state(struct thermal_instance *instance,
enum thermal_trend trend)
{
struct thermal_cooling_device *cdev = instance->cdev;
unsigned long cur_state;
cdev->ops->get_cur_state(cdev, &cur_state);
if (trend == THERMAL_TREND_RAISING) {
cur_state = cur_state < instance->upper ?
(cur_state + 1) : instance->upper;
} else if (trend == THERMAL_TREND_DROPPING) {
cur_state = cur_state > instance->lower ?
(cur_state - 1) : instance->lower;
}
return cur_state;
}
static void update_passive_instance(struct thermal_zone_device *tz,
enum thermal_trip_type type, int value)
{
if (type == THERMAL_TRIP_PASSIVE || type == THERMAL_TRIPS_NONE)
tz->passive += value;
}
static void update_instance_for_throttle(struct thermal_zone_device *tz,
int trip, enum thermal_trip_type trip_type,
enum thermal_trend trend)
{
struct thermal_instance *instance;
list_for_each_entry(instance, &tz->thermal_instances, tz_node) {
if (instance->trip != trip)
continue;
instance->target = get_target_state(instance, trend);
if (instance->target == THERMAL_NO_TARGET)
update_passive_instance(tz, trip_type, 1);
instance->cdev->updated = false;
}
}
static void update_instance_for_dethrottle(struct thermal_zone_device *tz,
int trip, enum thermal_trip_type trip_type)
{
struct thermal_instance *instance;
struct thermal_cooling_device *cdev;
unsigned long cur_state;
list_for_each_entry(instance, &tz->thermal_instances, tz_node) {
if (instance->trip != trip ||
instance->target == THERMAL_NO_TARGET)
continue;
cdev = instance->cdev;
cdev->ops->get_cur_state(cdev, &cur_state);
instance->target = cur_state > instance->lower ?
(cur_state - 1) : THERMAL_NO_TARGET;
if (instance->target == THERMAL_NO_TARGET)
update_passive_instance(tz, trip_type, -1);
cdev->updated = false;
}
}
static void thermal_zone_trip_update(struct thermal_zone_device *tz, int trip)
{
long trip_temp;
enum thermal_trip_type trip_type;
enum thermal_trend trend;
if (trip == THERMAL_TRIPS_NONE) {
trip_temp = tz->forced_passive;
trip_type = THERMAL_TRIPS_NONE;
} else {
tz->ops->get_trip_temp(tz, trip, &trip_temp);
tz->ops->get_trip_type(tz, trip, &trip_type);
}
trend = get_tz_trend(tz, trip);
mutex_lock(&tz->lock);
if (tz->temperature >= trip_temp)
update_instance_for_throttle(tz, trip, trip_type, trend);
else
update_instance_for_dethrottle(tz, trip, trip_type);
mutex_unlock(&tz->lock);
}
static int step_wise_throttle(struct thermal_zone_device *tz, int trip)
{
struct thermal_instance *instance;
thermal_zone_trip_update(tz, trip);
if (tz->forced_passive)
thermal_zone_trip_update(tz, THERMAL_TRIPS_NONE);
mutex_lock(&tz->lock);
list_for_each_entry(instance, &tz->thermal_instances, tz_node)
thermal_cdev_update(instance->cdev);
mutex_unlock(&tz->lock);
return 0;
}
static int __init thermal_gov_step_wise_init(void)
{
return thermal_register_governor(&thermal_gov_step_wise);
}
static void __exit thermal_gov_step_wise_exit(void)
{
thermal_unregister_governor(&thermal_gov_step_wise);
}
