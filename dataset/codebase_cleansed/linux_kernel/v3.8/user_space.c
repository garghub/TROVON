static int notify_user_space(struct thermal_zone_device *tz, int trip)
{
mutex_lock(&tz->lock);
kobject_uevent(&tz->device.kobj, KOBJ_CHANGE);
mutex_unlock(&tz->lock);
return 0;
}
static int __init thermal_gov_user_space_init(void)
{
return thermal_register_governor(&thermal_gov_user_space);
}
static void __exit thermal_gov_user_space_exit(void)
{
thermal_unregister_governor(&thermal_gov_user_space);
}
