static void pcmcia_hw_setup(int slot, int enable)
{
if (enable)
clrbits32(&bcsr[1], BCSR1_PCCEN);
else
setbits32(&bcsr[1], BCSR1_PCCEN);
}
static int pcmcia_set_voltage(int slot, int vcc, int vpp)
{
u32 reg = 0;
switch (vcc) {
case 0:
break;
case 33:
reg |= BCSR1_PCCVCC0;
break;
case 50:
reg |= BCSR1_PCCVCC1;
break;
default:
return 1;
}
switch (vpp) {
case 0:
break;
case 33:
case 50:
if (vcc == vpp)
reg |= BCSR1_PCCVPP1;
else
return 1;
break;
case 120:
if ((vcc == 33) || (vcc == 50))
reg |= BCSR1_PCCVPP0;
else
return 1;
default:
return 1;
}
clrbits32(&bcsr[1], 0x00610000);
setbits32(&bcsr[1], reg);
return 0;
}
static void __init init_ioports(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(mpc885ads_pins); i++) {
struct cpm_pin *pin = &mpc885ads_pins[i];
cpm1_set_pin(pin->port, pin->pin, pin->flags);
}
cpm1_clk_setup(CPM_CLK_SMC1, CPM_BRG1, CPM_CLK_RTX);
cpm1_clk_setup(CPM_CLK_SMC2, CPM_BRG2, CPM_CLK_RTX);
cpm1_clk_setup(CPM_CLK_SCC3, CPM_CLK5, CPM_CLK_TX);
cpm1_clk_setup(CPM_CLK_SCC3, CPM_CLK6, CPM_CLK_RX);
clrbits32(&mpc8xx_immr->im_cpm.cp_cptr, 0x00000180);
}
static void __init mpc885ads_setup_arch(void)
{
struct device_node *np;
cpm_reset();
init_ioports();
np = of_find_compatible_node(NULL, NULL, "fsl,mpc885ads-bcsr");
if (!np) {
printk(KERN_CRIT "Could not find fsl,mpc885ads-bcsr node\n");
return;
}
bcsr = of_iomap(np, 0);
bcsr5 = of_iomap(np, 1);
of_node_put(np);
if (!bcsr || !bcsr5) {
printk(KERN_CRIT "Could not remap BCSR\n");
return;
}
clrbits32(&bcsr[1], BCSR1_RS232EN_1);
#ifdef CONFIG_MPC8xx_SECOND_ETH_FEC2
setbits32(&bcsr[1], BCSR1_RS232EN_2);
#else
clrbits32(&bcsr[1], BCSR1_RS232EN_2);
#endif
clrbits32(bcsr5, BCSR5_MII1_EN);
setbits32(bcsr5, BCSR5_MII1_RST);
udelay(1000);
clrbits32(bcsr5, BCSR5_MII1_RST);
#ifdef CONFIG_MPC8xx_SECOND_ETH_FEC2
clrbits32(bcsr5, BCSR5_MII2_EN);
setbits32(bcsr5, BCSR5_MII2_RST);
udelay(1000);
clrbits32(bcsr5, BCSR5_MII2_RST);
#else
setbits32(bcsr5, BCSR5_MII2_EN);
#endif
#ifdef CONFIG_MPC8xx_SECOND_ETH_SCC3
clrbits32(&bcsr[4], BCSR4_ETH10_RST);
udelay(1000);
setbits32(&bcsr[4], BCSR4_ETH10_RST);
setbits32(&bcsr[1], BCSR1_ETHEN);
np = of_find_node_by_path("/soc@ff000000/cpm@9c0/serial@a80");
#else
np = of_find_node_by_path("/soc@ff000000/cpm@9c0/ethernet@a40");
#endif
if (np) {
of_detach_node(np);
of_node_put(np);
}
#ifdef CONFIG_PCMCIA_M8XX
m8xx_pcmcia_ops.hw_ctrl = pcmcia_hw_setup;
m8xx_pcmcia_ops.voltage_set = pcmcia_set_voltage;
#endif
}
static int __init mpc885ads_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,mpc885ads");
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
