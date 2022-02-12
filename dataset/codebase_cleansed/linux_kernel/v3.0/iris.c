static void iris_power_off(void)
{
outb(IRIS_GIO_PULSE, IRIS_GIO_OUTPUT);
msleep(850);
outb(IRIS_GIO_REST, IRIS_GIO_OUTPUT);
}
static int iris_init(void)
{
unsigned char status;
if (force != 1) {
printk(KERN_ERR "The force parameter has not been set to 1 so the Iris poweroff handler will not be installed.\n");
return -ENODEV;
}
status = inb(IRIS_GIO_INPUT);
if (status == IRIS_GIO_NODEV) {
printk(KERN_ERR "This machine does not seem to be an Iris. Power_off handler not installed.\n");
return -ENODEV;
}
old_pm_power_off = pm_power_off;
pm_power_off = &iris_power_off;
printk(KERN_INFO "Iris power_off handler installed.\n");
return 0;
}
static void iris_exit(void)
{
pm_power_off = old_pm_power_off;
printk(KERN_INFO "Iris power_off handler uninstalled.\n");
}
