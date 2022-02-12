static void __init init_ioports(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(mpc866ads_pins); i++) {
struct cpm_pin *pin = &mpc866ads_pins[i];
cpm1_set_pin(pin->port, pin->pin, pin->flags);
}
cpm1_clk_setup(CPM_CLK_SMC1, CPM_BRG1, CPM_CLK_RTX);
cpm1_clk_setup(CPM_CLK_SMC2, CPM_BRG2, CPM_CLK_RTX);
cpm1_clk_setup(CPM_CLK_SCC1, CPM_CLK1, CPM_CLK_TX);
cpm1_clk_setup(CPM_CLK_SCC1, CPM_CLK2, CPM_CLK_RX);
clrbits32(&mpc8xx_immr->im_cpm.cp_cptr, 0x00000180);
}
static void __init mpc86xads_setup_arch(void)
{
struct device_node *np;
u32 __iomem *bcsr_io;
cpm_reset();
init_ioports();
np = of_find_compatible_node(NULL, NULL, "fsl,mpc866ads-bcsr");
if (!np) {
printk(KERN_CRIT "Could not find fsl,mpc866ads-bcsr node\n");
return;
}
bcsr_io = of_iomap(np, 0);
of_node_put(np);
if (bcsr_io == NULL) {
printk(KERN_CRIT "Could not remap BCSR\n");
return;
}
clrbits32(bcsr_io, BCSR1_RS232EN_1 | BCSR1_RS232EN_2 | BCSR1_ETHEN);
iounmap(bcsr_io);
}
static int __init mpc86xads_probe(void)
{
return of_machine_is_compatible("fsl,mpc866ads");
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
