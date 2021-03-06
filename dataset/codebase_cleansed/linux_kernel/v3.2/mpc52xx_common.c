void __init
mpc5200_setup_xlb_arbiter(void)
{
struct device_node *np;
struct mpc52xx_xlb __iomem *xlb;
np = of_find_matching_node(NULL, mpc52xx_xlb_ids);
xlb = of_iomap(np, 0);
of_node_put(np);
if (!xlb) {
printk(KERN_ERR __FILE__ ": "
"Error mapping XLB in mpc52xx_setup_cpu(). "
"Expect some abnormal behavior\n");
return;
}
out_be32(&xlb->master_pri_enable, 0xff);
out_be32(&xlb->master_priority, 0x11111111);
if ((mfspr(SPRN_SVR) & MPC5200_SVR_MASK) == MPC5200_SVR)
out_be32(&xlb->config, in_be32(&xlb->config) | MPC52xx_XLB_CFG_PLDIS);
iounmap(xlb);
}
void __init
mpc52xx_declare_of_platform_devices(void)
{
if (of_platform_bus_probe(NULL, mpc52xx_bus_ids, NULL))
printk(KERN_ERR __FILE__ ": "
"Error while probing of_platform bus\n");
}
void __init
mpc52xx_map_common_devices(void)
{
struct device_node *np;
for_each_matching_node(np, mpc52xx_gpt_ids) {
if (of_get_property(np, "fsl,has-wdt", NULL) ||
of_get_property(np, "has-wdt", NULL)) {
mpc52xx_wdt = of_iomap(np, 0);
of_node_put(np);
break;
}
}
np = of_find_matching_node(NULL, mpc52xx_cdm_ids);
mpc52xx_cdm = of_iomap(np, 0);
of_node_put(np);
np = of_find_matching_node(NULL, mpc52xx_gpio_simple);
simple_gpio = of_iomap(np, 0);
of_node_put(np);
np = of_find_matching_node(NULL, mpc52xx_gpio_wkup);
wkup_gpio = of_iomap(np, 0);
of_node_put(np);
}
int mpc52xx_set_psc_clkdiv(int psc_id, int clkdiv)
{
unsigned long flags;
u16 __iomem *reg;
u32 val;
u32 mask;
u32 mclken_div;
if (!mpc52xx_cdm)
return -ENODEV;
mclken_div = 0x8000 | (clkdiv & 0x1FF);
switch (psc_id) {
case 1: reg = &mpc52xx_cdm->mclken_div_psc1; mask = 0x20; break;
case 2: reg = &mpc52xx_cdm->mclken_div_psc2; mask = 0x40; break;
case 3: reg = &mpc52xx_cdm->mclken_div_psc3; mask = 0x80; break;
case 6: reg = &mpc52xx_cdm->mclken_div_psc6; mask = 0x10; break;
default:
return -ENODEV;
}
spin_lock_irqsave(&mpc52xx_lock, flags);
out_be16(reg, mclken_div);
val = in_be32(&mpc52xx_cdm->clk_enables);
out_be32(&mpc52xx_cdm->clk_enables, val | mask);
spin_unlock_irqrestore(&mpc52xx_lock, flags);
return 0;
}
unsigned int mpc52xx_get_xtal_freq(struct device_node *node)
{
u32 val;
unsigned int freq;
if (!mpc52xx_cdm)
return 0;
freq = mpc5xxx_get_bus_frequency(node);
if (!freq)
return 0;
if (in_8(&mpc52xx_cdm->ipb_clk_sel) & 0x1)
freq *= 2;
val = in_be32(&mpc52xx_cdm->rstcfg);
if (val & (1 << 5))
freq *= 8;
else
freq *= 4;
if (val & (1 << 6))
freq /= 12;
else
freq /= 16;
return freq;
}
void
mpc52xx_restart(char *cmd)
{
local_irq_disable();
if (mpc52xx_wdt) {
out_be32(&mpc52xx_wdt->mode, 0x00000000);
out_be32(&mpc52xx_wdt->count, 0x000000ff);
out_be32(&mpc52xx_wdt->mode, 0x00009004);
} else
printk(KERN_ERR __FILE__ ": "
"mpc52xx_restart: Can't access wdt. "
"Restart impossible, system halted.\n");
while (1);
}
int mpc5200_psc_ac97_gpio_reset(int psc_number)
{
unsigned long flags;
u32 gpio;
u32 mux;
int out;
int reset;
int sync;
if ((!simple_gpio) || (!wkup_gpio))
return -ENODEV;
switch (psc_number) {
case 0:
reset = PSC1_RESET;
sync = PSC1_SYNC;
out = PSC1_SDATA_OUT;
gpio = MPC52xx_GPIO_PSC1_MASK;
break;
case 1:
reset = PSC2_RESET;
sync = PSC2_SYNC;
out = PSC2_SDATA_OUT;
gpio = MPC52xx_GPIO_PSC2_MASK;
break;
default:
pr_err(__FILE__ ": Unable to determine PSC, no ac97 "
"cold-reset will be performed\n");
return -ENODEV;
}
spin_lock_irqsave(&gpio_lock, flags);
mux = in_be32(&simple_gpio->port_config);
out_be32(&simple_gpio->port_config, mux & (~gpio));
setbits8(&wkup_gpio->wkup_gpioe, reset);
setbits32(&simple_gpio->simple_gpioe, sync | out);
setbits8(&wkup_gpio->wkup_ddr, reset);
setbits32(&simple_gpio->simple_ddr, sync | out);
clrbits32(&simple_gpio->simple_dvo, sync | out);
clrbits8(&wkup_gpio->wkup_dvo, reset);
udelay(1);
setbits8(&wkup_gpio->wkup_dvo, reset);
__delay(7);
out_be32(&simple_gpio->port_config, mux);
spin_unlock_irqrestore(&gpio_lock, flags);
return 0;
}
