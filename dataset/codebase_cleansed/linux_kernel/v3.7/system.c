void highbank_restart(char mode, const char *cmd)
{
if (mode == 'h')
hignbank_set_pwr_hard_reset();
else
hignbank_set_pwr_soft_reset();
scu_power_mode(scu_base_addr, SCU_PM_POWEROFF);
while (1)
cpu_do_idle();
}
