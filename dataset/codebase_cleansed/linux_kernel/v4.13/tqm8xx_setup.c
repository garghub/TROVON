static void __init init_pins(int n, struct cpm_pin *pin)
{
int i;
for (i = 0; i < n; i++) {
cpm1_set_pin(pin->port, pin->pin, pin->flags);
pin++;
}
}
static void __init init_ioports(void)
{
struct device_node *dnode;
struct property *prop;
int len;
init_pins(ARRAY_SIZE(tqm8xx_pins), &tqm8xx_pins[0]);
cpm1_clk_setup(CPM_CLK_SMC1, CPM_BRG1, CPM_CLK_RTX);
dnode = of_find_node_by_name(NULL, "aliases");
if (dnode == NULL)
return;
prop = of_find_property(dnode, "ethernet1", &len);
if (prop == NULL)
return;
init_pins(ARRAY_SIZE(tqm8xx_fec_pins), &tqm8xx_fec_pins[0]);
}
static void __init tqm8xx_setup_arch(void)
{
cpm_reset();
init_ioports();
}
static int __init tqm8xx_probe(void)
{
return of_machine_is_compatible("tqc,tqm8xx");
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
