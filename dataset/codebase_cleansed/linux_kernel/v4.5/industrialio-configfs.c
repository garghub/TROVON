static int __init iio_configfs_init(void)
{
config_group_init(&iio_configfs_subsys.su_group);
return configfs_register_subsystem(&iio_configfs_subsys);
}
static void __exit iio_configfs_exit(void)
{
configfs_unregister_subsystem(&iio_configfs_subsys);
}
