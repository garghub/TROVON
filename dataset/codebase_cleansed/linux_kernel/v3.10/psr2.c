static void psr2_spin(void)
{
hard_irq_disable();
for (;;)
continue;
}
static void psr2_restart(char *cmd)
{
psr2_spin();
}
static int __init psr2_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "ibm,wsp-chroma")) {
return 0;
}
if (!of_flat_dt_is_compatible(root, "ibm,psr2"))
return 0;
return 1;
}
