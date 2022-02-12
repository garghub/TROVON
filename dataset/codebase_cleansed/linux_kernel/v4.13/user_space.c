static int notify_user_space(struct thermal_zone_device *tz, int trip)
{
char *thermal_prop[5];
int i;
mutex_lock(&tz->lock);
thermal_prop[0] = kasprintf(GFP_KERNEL, "NAME=%s", tz->type);
thermal_prop[1] = kasprintf(GFP_KERNEL, "TEMP=%d", tz->temperature);
thermal_prop[2] = kasprintf(GFP_KERNEL, "TRIP=%d", trip);
thermal_prop[3] = kasprintf(GFP_KERNEL, "EVENT=%d", tz->notify_event);
thermal_prop[4] = NULL;
kobject_uevent_env(&tz->device.kobj, KOBJ_CHANGE, thermal_prop);
for (i = 0; i < 4; ++i)
kfree(thermal_prop[i]);
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
