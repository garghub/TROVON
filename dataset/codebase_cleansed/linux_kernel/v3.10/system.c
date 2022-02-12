void highbank_restart(char mode, const char *cmd)
{
if (mode == 'h')
highbank_set_pwr_hard_reset();
else
highbank_set_pwr_soft_reset();
while (1)
cpu_do_idle();
}
