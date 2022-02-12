static int __init i2o_config_init(void)
{
printk(KERN_INFO OSM_DESCRIPTION " v" OSM_VERSION "\n");
if (i2o_driver_register(&i2o_config_driver)) {
osm_err("handler register failed.\n");
return -EBUSY;
}
#ifdef CONFIG_I2O_CONFIG_OLD_IOCTL
if (i2o_config_old_init()) {
osm_err("old config handler initialization failed\n");
i2o_driver_unregister(&i2o_config_driver);
return -EBUSY;
}
#endif
return 0;
}
static void i2o_config_exit(void)
{
#ifdef CONFIG_I2O_CONFIG_OLD_IOCTL
i2o_config_old_exit();
#endif
i2o_driver_unregister(&i2o_config_driver);
}
