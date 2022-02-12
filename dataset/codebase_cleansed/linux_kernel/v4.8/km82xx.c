static void __init km82xx_pic_init(void)
{
struct device_node *np = of_find_compatible_node(NULL, NULL,
"fsl,pq2-pic");
if (!np) {
pr_err("PIC init: can not find cpm-pic node\n");
return;
}
cpm2_pic_init(np);
of_node_put(np);
}
static void __init init_ioports(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(km82xx_pins); i++) {
const struct cpm_pin *pin = &km82xx_pins[i];
cpm2_set_pin(pin->port, pin->pin, pin->flags);
}
cpm2_smc_clk_setup(CPM_CLK_SMC2, CPM_BRG8);
cpm2_smc_clk_setup(CPM_CLK_SMC1, CPM_BRG7);
cpm2_clk_setup(CPM_CLK_SCC1, CPM_CLK11, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_SCC1, CPM_CLK11, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_SCC3, CPM_CLK5, CPM_CLK_RTX);
cpm2_clk_setup(CPM_CLK_SCC4, CPM_CLK7, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_SCC4, CPM_CLK8, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_FCC1, CPM_CLK10, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_FCC1, CPM_CLK9, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_FCC2, CPM_CLK13, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_FCC2, CPM_CLK14, CPM_CLK_TX);
setbits32(&cpm2_immr->im_ioport.iop_pdata, 1 << (31 - 10));
clrbits32(&cpm2_immr->im_ioport.iop_pdata, 1 << (31 - 11));
}
static void __init km82xx_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("km82xx_setup_arch()", 0);
cpm2_reset();
clrbits32(&cpm2_immr->im_siu_conf.siu_82xx.sc_bcr, MPC82XX_BCR_PLDP);
init_ioports();
if (ppc_md.progress)
ppc_md.progress("km82xx_setup_arch(), finish", 0);
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
static int __init km82xx_probe(void)
{
return of_machine_is_compatible("keymile,km82xx");
}
