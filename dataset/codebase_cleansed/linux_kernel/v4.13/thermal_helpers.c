int get_tz_trend(struct thermal_zone_device *tz, int trip)
{
enum thermal_trend trend;
if (tz->emul_temperature || !tz->ops->get_trend ||
tz->ops->get_trend(tz, trip, &trend)) {
if (tz->temperature > tz->last_temperature)
trend = THERMAL_TREND_RAISING;
else if (tz->temperature < tz->last_temperature)
trend = THERMAL_TREND_DROPPING;
else
trend = THERMAL_TREND_STABLE;
}
return trend;
}
struct thermal_instance *
get_thermal_instance(struct thermal_zone_device *tz,
struct thermal_cooling_device *cdev, int trip)
{
struct thermal_instance *pos = NULL;
struct thermal_instance *target_instance = NULL;
mutex_lock(&tz->lock);
mutex_lock(&cdev->lock);
list_for_each_entry(pos, &tz->thermal_instances, tz_node) {
if (pos->tz == tz && pos->trip == trip && pos->cdev == cdev) {
target_instance = pos;
break;
}
}
mutex_unlock(&cdev->lock);
mutex_unlock(&tz->lock);
return target_instance;
}
int thermal_zone_get_temp(struct thermal_zone_device *tz, int *temp)
{
int ret = -EINVAL;
int count;
int crit_temp = INT_MAX;
enum thermal_trip_type type;
if (!tz || IS_ERR(tz) || !tz->ops->get_temp)
goto exit;
mutex_lock(&tz->lock);
ret = tz->ops->get_temp(tz, temp);
if (IS_ENABLED(CONFIG_THERMAL_EMULATION) && tz->emul_temperature) {
for (count = 0; count < tz->trips; count++) {
ret = tz->ops->get_trip_type(tz, count, &type);
if (!ret && type == THERMAL_TRIP_CRITICAL) {
ret = tz->ops->get_trip_temp(tz, count,
&crit_temp);
break;
}
}
if (!ret && *temp < crit_temp)
*temp = tz->emul_temperature;
}
mutex_unlock(&tz->lock);
exit:
return ret;
}
void thermal_zone_set_trips(struct thermal_zone_device *tz)
{
int low = -INT_MAX;
int high = INT_MAX;
int trip_temp, hysteresis;
int i, ret;
mutex_lock(&tz->lock);
if (!tz->ops->set_trips || !tz->ops->get_trip_hyst)
goto exit;
for (i = 0; i < tz->trips; i++) {
int trip_low;
tz->ops->get_trip_temp(tz, i, &trip_temp);
tz->ops->get_trip_hyst(tz, i, &hysteresis);
trip_low = trip_temp - hysteresis;
if (trip_low < tz->temperature && trip_low > low)
low = trip_low;
if (trip_temp > tz->temperature && trip_temp < high)
high = trip_temp;
}
if (tz->prev_low_trip == low && tz->prev_high_trip == high)
goto exit;
tz->prev_low_trip = low;
tz->prev_high_trip = high;
dev_dbg(&tz->device,
"new temperature boundaries: %d < x < %d\n", low, high);
ret = tz->ops->set_trips(tz, low, high);
if (ret)
dev_err(&tz->device, "Failed to set trips: %d\n", ret);
exit:
mutex_unlock(&tz->lock);
}
void thermal_cdev_update(struct thermal_cooling_device *cdev)
{
struct thermal_instance *instance;
unsigned long target = 0;
mutex_lock(&cdev->lock);
if (cdev->updated) {
mutex_unlock(&cdev->lock);
return;
}
list_for_each_entry(instance, &cdev->thermal_instances, cdev_node) {
dev_dbg(&cdev->device, "zone%d->target=%lu\n",
instance->tz->id, instance->target);
if (instance->target == THERMAL_NO_TARGET)
continue;
if (instance->target > target)
target = instance->target;
}
cdev->ops->set_cur_state(cdev, target);
cdev->updated = true;
mutex_unlock(&cdev->lock);
trace_cdev_update(cdev, target);
dev_dbg(&cdev->device, "set to state %lu\n", target);
}
int thermal_zone_get_slope(struct thermal_zone_device *tz)
{
if (tz && tz->tzp)
return tz->tzp->slope;
return 1;
}
int thermal_zone_get_offset(struct thermal_zone_device *tz)
{
if (tz && tz->tzp)
return tz->tzp->offset;
return 0;
}
