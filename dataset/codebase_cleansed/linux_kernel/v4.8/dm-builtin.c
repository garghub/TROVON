void dm_kobject_release(struct kobject *kobj)
{
complete(dm_get_completion_from_kobject(kobj));
}
