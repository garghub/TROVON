static int get_trip_level(struct thermal_zone_device *tz)
{
int count = 0;
unsigned long trip_temp;
if (tz->trips == 0 || !tz->ops->get_trip_temp)
return 0;
for (count = 0; count < tz->trips; count++) {
tz->ops->get_trip_temp(tz, count, &trip_temp);
if (tz->temperature < trip_temp)
break;
}
return count;
}
static long get_target_state(struct thermal_zone_device *tz,
struct thermal_cooling_device *cdev, int weight, int level)
{
unsigned long max_state;
cdev->ops->get_max_state(cdev, &max_state);
return (long)(weight * level * max_state) / (100 * tz->trips);
}
static int fair_share_throttle(struct thermal_zone_device *tz, int trip)
{
const struct thermal_zone_params *tzp;
struct thermal_cooling_device *cdev;
struct thermal_instance *instance;
int i;
int cur_trip_level = get_trip_level(tz);
if (!tz->tzp || !tz->tzp->tbp)
return -EINVAL;
tzp = tz->tzp;
for (i = 0; i < tzp->num_tbps; i++) {
if (!tzp->tbp[i].cdev)
continue;
cdev = tzp->tbp[i].cdev;
instance = get_thermal_instance(tz, cdev, trip);
if (!instance)
continue;
instance->target = get_target_state(tz, cdev,
tzp->tbp[i].weight, cur_trip_level);
instance->cdev->updated = false;
thermal_cdev_update(cdev);
}
return 0;
}
static int __init thermal_gov_fair_share_init(void)
{
return thermal_register_governor(&thermal_gov_fair_share);
}
static void __exit thermal_gov_fair_share_exit(void)
{
thermal_unregister_governor(&thermal_gov_fair_share);
}
