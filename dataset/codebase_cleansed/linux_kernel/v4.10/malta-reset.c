static void mips_machine_power_off(void)
{
mips_pm_suspend(PIIX4_FUNC3IO_PMCNTRL_SUS_TYP_SOFF);
pr_info("Failed to power down, resetting\n");
machine_restart(NULL);
}
static int __init mips_reboot_setup(void)
{
pm_power_off = mips_machine_power_off;
return 0;
}
