static void psr2_spin(void)
{
hard_irq_disable();
for (;;) ;
}
static void psr2_restart(char *cmd)
{
psr2_spin();
}
static int psr2_probe_devices(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "dallas,ds1500");
if (np != NULL) {
struct resource res;
if (of_address_to_resource(np, 0, &res) == 0)
platform_device_register_simple("ds1511", 0, &res, 1);
}
return 0;
}
static void __init psr2_setup_arch(void)
{
loops_per_jiffy = 50000000;
scom_init_wsp();
#ifdef CONFIG_SMP
a2_setup_smp();
#endif
#ifdef CONFIG_PCI
wsp_setup_pci();
#endif
}
static int __init psr2_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "ibm,psr2"))
return 0;
return 1;
}
static void __init psr2_init_irq(void)
{
wsp_init_irq();
opb_pic_init();
}
