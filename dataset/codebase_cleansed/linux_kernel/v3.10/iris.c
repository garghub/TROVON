static void iris_power_off(void)
{
outb(IRIS_GIO_PULSE, IRIS_GIO_OUTPUT);
msleep(850);
outb(IRIS_GIO_REST, IRIS_GIO_OUTPUT);
}
static int iris_probe(struct platform_device *pdev)
{
unsigned char status = inb(IRIS_GIO_INPUT);
if (status == IRIS_GIO_NODEV) {
printk(KERN_ERR "This machine does not seem to be an Iris. "
"Power off handler not installed.\n");
return -ENODEV;
}
old_pm_power_off = pm_power_off;
pm_power_off = &iris_power_off;
printk(KERN_INFO "Iris power_off handler installed.\n");
return 0;
}
static int iris_remove(struct platform_device *pdev)
{
pm_power_off = old_pm_power_off;
printk(KERN_INFO "Iris power_off handler uninstalled.\n");
return 0;
}
static int iris_init(void)
{
int ret;
if (force != 1) {
printk(KERN_ERR "The force parameter has not been set to 1."
" The Iris poweroff handler will not be installed.\n");
return -ENODEV;
}
ret = platform_driver_register(&iris_driver);
if (ret < 0) {
printk(KERN_ERR "Failed to register iris platform driver: %d\n",
ret);
return ret;
}
iris_device = platform_device_register_simple("iris", (-1),
iris_resources, ARRAY_SIZE(iris_resources));
if (IS_ERR(iris_device)) {
printk(KERN_ERR "Failed to register iris platform device\n");
platform_driver_unregister(&iris_driver);
return PTR_ERR(iris_device);
}
return 0;
}
static void iris_exit(void)
{
platform_device_unregister(iris_device);
platform_driver_unregister(&iris_driver);
}
