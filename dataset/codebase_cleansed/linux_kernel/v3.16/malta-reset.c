static void mips_machine_restart(char *command)
{
unsigned int __iomem *softres_reg =
ioremap(SOFTRES_REG, sizeof(unsigned int));
__raw_writel(GORESET, softres_reg);
}
static void mips_machine_halt(void)
{
while (true);
}
static void mips_machine_power_off(void)
{
mips_pm_suspend(PIIX4_FUNC3IO_PMCNTRL_SUS_TYP_SOFF);
pr_info("Failed to power down, resetting\n");
mips_machine_restart(NULL);
}
static int __init mips_reboot_setup(void)
{
_machine_restart = mips_machine_restart;
_machine_halt = mips_machine_halt;
pm_power_off = mips_machine_power_off;
return 0;
}
