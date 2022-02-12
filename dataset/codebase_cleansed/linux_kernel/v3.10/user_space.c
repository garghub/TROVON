static int notify_user_space(struct thermal_zone_device *tz, int trip)
{
mutex_lock(&tz->lock);
kobject_uevent(&tz->device.kobj, KOBJ_CHANGE);
mutex_unlock(&tz->lock);
return 0;
}
int thermal_gov_user_space_register(void)
{
return thermal_register_governor(&thermal_gov_user_space);
}
void thermal_gov_user_space_unregister(void)
{
thermal_unregister_governor(&thermal_gov_user_space);
}
