static int ac97_bus_match(struct device *dev, struct device_driver *drv)
{
return 1;
}
static int ac97_bus_suspend(struct device *dev, pm_message_t state)
{
int ret = 0;
if (dev->driver && dev->driver->suspend)
ret = dev->driver->suspend(dev, state);
return ret;
}
static int ac97_bus_resume(struct device *dev)
{
int ret = 0;
if (dev->driver && dev->driver->resume)
ret = dev->driver->resume(dev);
return ret;
}
static int __init ac97_bus_init(void)
{
return bus_register(&ac97_bus_type);
}
static void __exit ac97_bus_exit(void)
{
bus_unregister(&ac97_bus_type);
}
