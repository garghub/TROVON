static int at91_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
at91_standby();
return index;
}
static int at91_cpuidle_probe(struct platform_device *dev)
{
at91_standby = (void *)(dev->dev.platform_data);
return cpuidle_register(&at91_idle_driver, NULL);
}
