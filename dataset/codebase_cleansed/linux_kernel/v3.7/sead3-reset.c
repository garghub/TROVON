static void mips_machine_restart(char *command)
{
unsigned int __iomem *softres_reg =
ioremap(SOFTRES_REG, sizeof(unsigned int));
__raw_writel(GORESET, softres_reg);
}
static void mips_machine_halt(void)
{
unsigned int __iomem *softres_reg =
ioremap(SOFTRES_REG, sizeof(unsigned int));
__raw_writel(GORESET, softres_reg);
}
static int __init mips_reboot_setup(void)
{
_machine_restart = mips_machine_restart;
_machine_halt = mips_machine_halt;
pm_power_off = mips_machine_halt;
return 0;
}
