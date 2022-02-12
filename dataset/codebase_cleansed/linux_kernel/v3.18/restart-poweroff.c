static void restart_poweroff_do_poweroff(void)
{
reboot_mode = REBOOT_HARD;
machine_restart(NULL);
}
static int restart_poweroff_probe(struct platform_device *pdev)
{
if (pm_power_off != NULL) {
dev_err(&pdev->dev,
"pm_power_off function already registered");
return -EBUSY;
}
pm_power_off = &restart_poweroff_do_poweroff;
return 0;
}
static int restart_poweroff_remove(struct platform_device *pdev)
{
if (pm_power_off == &restart_poweroff_do_poweroff)
pm_power_off = NULL;
return 0;
}
