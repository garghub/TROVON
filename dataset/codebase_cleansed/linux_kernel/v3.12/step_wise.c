static unsigned long get_target_state(struct thermal_instance *instance,
enum thermal_trend trend, bool throttle)
{
struct thermal_cooling_device *cdev = instance->cdev;
unsigned long cur_state;
unsigned long next_target;
cdev->ops->get_cur_state(cdev, &cur_state);
next_target = instance->target;
switch (trend) {
case THERMAL_TREND_RAISING:
if (throttle) {
next_target = cur_state < instance->upper ?
(cur_state + 1) : instance->upper;
if (next_target < instance->lower)
next_target = instance->lower;
}
break;
case THERMAL_TREND_RAISE_FULL:
if (throttle)
next_target = instance->upper;
break;
case THERMAL_TREND_DROPPING:
if (cur_state == instance->lower) {
if (!throttle)
next_target = THERMAL_NO_TARGET;
} else {
next_target = cur_state - 1;
if (next_target > instance->upper)
next_target = instance->upper;
}
break;
case THERMAL_TREND_DROP_FULL:
if (cur_state == instance->lower) {
if (!throttle)
next_target = THERMAL_NO_TARGET;
} else
next_target = instance->lower;
break;
default:
break;
}
return next_target;
}
static void update_passive_instance(struct thermal_zone_device *tz,
enum thermal_trip_type type, int value)
{
if (type == THERMAL_TRIP_PASSIVE || type == THERMAL_TRIPS_NONE)
tz->passive += value;
}
static void thermal_zone_trip_update(struct thermal_zone_device *tz, int trip)
{
long trip_temp;
enum thermal_trip_type trip_type;
enum thermal_trend trend;
struct thermal_instance *instance;
bool throttle = false;
int old_target;
if (trip == THERMAL_TRIPS_NONE) {
trip_temp = tz->forced_passive;
trip_type = THERMAL_TRIPS_NONE;
} else {
tz->ops->get_trip_temp(tz, trip, &trip_temp);
tz->ops->get_trip_type(tz, trip, &trip_type);
}
trend = get_tz_trend(tz, trip);
if (tz->temperature >= trip_temp)
throttle = true;
mutex_lock(&tz->lock);
list_for_each_entry(instance, &tz->thermal_instances, tz_node) {
if (instance->trip != trip)
continue;
old_target = instance->target;
instance->target = get_target_state(instance, trend, throttle);
if (old_target == instance->target)
continue;
if (old_target == THERMAL_NO_TARGET &&
instance->target != THERMAL_NO_TARGET)
update_passive_instance(tz, trip_type, 1);
else if (old_target != THERMAL_NO_TARGET &&
instance->target == THERMAL_NO_TARGET)
update_passive_instance(tz, trip_type, -1);
instance->cdev->updated = false;
}
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
int thermal_gov_step_wise_register(void)
{
return thermal_register_governor(&thermal_gov_step_wise);
}
void thermal_gov_step_wise_unregister(void)
{
thermal_unregister_governor(&thermal_gov_step_wise);
}
