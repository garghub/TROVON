static void thermal_zone_trip_update(struct thermal_zone_device *tz, int trip)
{
int trip_temp, trip_hyst;
struct thermal_instance *instance;
tz->ops->get_trip_temp(tz, trip, &trip_temp);
if (!tz->ops->get_trip_hyst) {
pr_warn_once("Undefined get_trip_hyst for thermal zone %s - "
"running with default hysteresis zero\n", tz->type);
trip_hyst = 0;
} else
tz->ops->get_trip_hyst(tz, trip, &trip_hyst);
dev_dbg(&tz->device, "Trip%d[temp=%d]:temp=%d:hyst=%d\n",
trip, trip_temp, tz->temperature,
trip_hyst);
mutex_lock(&tz->lock);
list_for_each_entry(instance, &tz->thermal_instances, tz_node) {
if (instance->trip != trip)
continue;
if (instance->target == THERMAL_NO_TARGET)
instance->target = 0;
if (instance->target != 0 && instance->target != 1) {
pr_warn("Thermal instance %s controlled by bang-bang has unexpected state: %ld\n",
instance->name, instance->target);
instance->target = 1;
}
if (instance->target == 0 && tz->temperature >= trip_temp)
instance->target = 1;
else if (instance->target == 1 &&
tz->temperature <= trip_temp - trip_hyst)
instance->target = 0;
dev_dbg(&instance->cdev->device, "target=%d\n",
(int)instance->target);
mutex_lock(&instance->cdev->lock);
instance->cdev->updated = false;
mutex_unlock(&instance->cdev->lock);
}
mutex_unlock(&tz->lock);
}
static int bang_bang_control(struct thermal_zone_device *tz, int trip)
{
struct thermal_instance *instance;
thermal_zone_trip_update(tz, trip);
mutex_lock(&tz->lock);
list_for_each_entry(instance, &tz->thermal_instances, tz_node)
thermal_cdev_update(instance->cdev);
mutex_unlock(&tz->lock);
return 0;
}
int thermal_gov_bang_bang_register(void)
{
return thermal_register_governor(&thermal_gov_bang_bang);
}
void thermal_gov_bang_bang_unregister(void)
{
thermal_unregister_governor(&thermal_gov_bang_bang);
}
