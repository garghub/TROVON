void
ia64_ssc_connect_irq (long intr, long irq)
{
ia64_ssc(intr, irq, 0, 0, SSC_CONNECT_INTERRUPT);
}
void
ia64_ctl_trace (long on)
{
ia64_ssc(on, 0, 0, 0, SSC_CTL_TRACE);
}
void __init
hpsim_setup (char **cmdline_p)
{
ROOT_DEV = Root_SDA1;
simcons_register();
}
