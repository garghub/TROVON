static void __init init_ioports(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(ep88xc_pins); i++) {
struct cpm_pin *pin = &ep88xc_pins[i];
cpm1_set_pin(pin->port, pin->pin, pin->flags);
}
cpm1_clk_setup(CPM_CLK_SMC1, CPM_BRG1, CPM_CLK_RTX);
cpm1_clk_setup(CPM_CLK_SCC1, CPM_CLK2, CPM_CLK_TX);
cpm1_clk_setup(CPM_CLK_SCC1, CPM_CLK2, CPM_CLK_RX);
cpm1_clk_setup(CPM_CLK_SCC2, CPM_BRG2, CPM_CLK_TX);
cpm1_clk_setup(CPM_CLK_SCC2, CPM_BRG2, CPM_CLK_RX);
}
static void __init ep88xc_setup_arch(void)
{
struct device_node *np;
cpm_reset();
init_ioports();
np = of_find_compatible_node(NULL, NULL, "fsl,ep88xc-bcsr");
if (!np) {
printk(KERN_CRIT "Could not find fsl,ep88xc-bcsr node\n");
return;
}
ep88xc_bcsr = of_iomap(np, 0);
of_node_put(np);
if (!ep88xc_bcsr) {
printk(KERN_CRIT "Could not remap BCSR\n");
return;
}
setbits8(&ep88xc_bcsr[7], BCSR7_SCC2_ENABLE);
setbits8(&ep88xc_bcsr[8], BCSR8_PHY1_ENABLE | BCSR8_PHY1_POWER |
BCSR8_PHY2_ENABLE | BCSR8_PHY2_POWER);
}
static int __init ep88xc_probe(void)
{
return of_machine_is_compatible("fsl,ep88xc");
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
