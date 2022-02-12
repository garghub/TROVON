static int get_trip_level(struct thermal_zone_device *tz)
{
int count = 0;
int trip_temp;
enum thermal_trip_type trip_type;
if (tz->trips == 0 || !tz->ops->get_trip_temp)
return 0;
for (count = 0; count < tz->trips; count++) {
tz->ops->get_trip_temp(tz, count, &trip_temp);
if (tz->temperature < trip_temp)
break;
}
if (count > 0) {
tz->ops->get_trip_type(tz, count - 1, &trip_type);
trace_thermal_zone_trip(tz, count - 1, trip_type);
}
return count;
}
static long get_target_state(struct thermal_zone_device *tz,
struct thermal_cooling_device *cdev, int percentage, int level)
{
unsigned long max_state;
cdev->ops->get_max_state(cdev, &max_state);
return (long)(percentage * level * max_state) / (100 * tz->trips);
}
static int fair_share_throttle(struct thermal_zone_device *tz, int trip)
{
struct thermal_instance *instance;
int total_weight = 0;
int total_instance = 0;
int cur_trip_level = get_trip_level(tz);
list_for_each_entry(instance, &tz->thermal_instances, tz_node) {
if (instance->trip != trip)
continue;
total_weight += instance->weight;
total_instance++;
}
list_for_each_entry(instance, &tz->thermal_instances, tz_node) {
int percentage;
struct thermal_cooling_device *cdev = instance->cdev;
if (instance->trip != trip)
continue;
if (!total_weight)
percentage = 100 / total_instance;
else
percentage = (instance->weight * 100) / total_weight;
instance->target = get_target_state(tz, cdev, percentage,
cur_trip_level);
instance->cdev->updated = false;
thermal_cdev_update(cdev);
}
return 0;
}
int thermal_gov_fair_share_register(void)
{
return thermal_register_governor(&thermal_gov_fair_share);
}
void thermal_gov_fair_share_unregister(void)
{
thermal_unregister_governor(&thermal_gov_fair_share);
}
