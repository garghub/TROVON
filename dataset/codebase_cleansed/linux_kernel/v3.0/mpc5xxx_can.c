static u32 __devinit mpc52xx_can_get_clock(struct platform_device *ofdev,
const char *clock_name,
int *mscan_clksrc)
{
unsigned int pvr;
struct mpc52xx_cdm __iomem *cdm;
struct device_node *np_cdm;
unsigned int freq;
u32 val;
pvr = mfspr(SPRN_PVR);
if (clock_name && strcmp(clock_name, "ip") == 0)
*mscan_clksrc = MSCAN_CLKSRC_BUS;
else
*mscan_clksrc = MSCAN_CLKSRC_XTAL;
freq = mpc5xxx_get_bus_frequency(ofdev->dev.of_node);
if (!freq)
return 0;
if (*mscan_clksrc == MSCAN_CLKSRC_BUS || pvr == 0x80822011)
return freq;
np_cdm = of_find_matching_node(NULL, mpc52xx_cdm_ids);
if (!np_cdm) {
dev_err(&ofdev->dev, "can't get clock node!\n");
return 0;
}
cdm = of_iomap(np_cdm, 0);
if (in_8(&cdm->ipb_clk_sel) & 0x1)
freq *= 2;
val = in_be32(&cdm->rstcfg);
freq *= (val & (1 << 5)) ? 8 : 4;
freq /= (val & (1 << 6)) ? 12 : 16;
of_node_put(np_cdm);
iounmap(cdm);
return freq;
}
static u32 __devinit mpc52xx_can_get_clock(struct platform_device *ofdev,
const char *clock_name,
int *mscan_clksrc)
{
return 0;
}
static u32 __devinit mpc512x_can_get_clock(struct platform_device *ofdev,
const char *clock_name,
int *mscan_clksrc)
{
struct mpc512x_clockctl __iomem *clockctl;
struct device_node *np_clock;
struct clk *sys_clk, *ref_clk;
int plen, clockidx, clocksrc = -1;
u32 sys_freq, val, clockdiv = 1, freq = 0;
const u32 *pval;
np_clock = of_find_matching_node(NULL, mpc512x_clock_ids);
if (!np_clock) {
dev_err(&ofdev->dev, "couldn't find clock node\n");
return 0;
}
clockctl = of_iomap(np_clock, 0);
if (!clockctl) {
dev_err(&ofdev->dev, "couldn't map clock registers\n");
goto exit_put;
}
pval = of_get_property(ofdev->dev.of_node, "reg", &plen);
BUG_ON(!pval || plen < sizeof(*pval));
clockidx = (*pval & 0x80) ? 1 : 0;
if (*pval & 0x2000)
clockidx += 2;
if (clock_name && !strcmp(clock_name, "ip")) {
*mscan_clksrc = MSCAN_CLKSRC_IPS;
freq = mpc5xxx_get_bus_frequency(ofdev->dev.of_node);
} else {
*mscan_clksrc = MSCAN_CLKSRC_BUS;
pval = of_get_property(ofdev->dev.of_node,
"fsl,mscan-clock-divider", &plen);
if (pval && plen == sizeof(*pval))
clockdiv = *pval;
if (!clockdiv)
clockdiv = 1;
if (!clock_name || !strcmp(clock_name, "sys")) {
sys_clk = clk_get(&ofdev->dev, "sys_clk");
if (!sys_clk) {
dev_err(&ofdev->dev, "couldn't get sys_clk\n");
goto exit_unmap;
}
sys_freq = 1000000 *
((clk_get_rate(sys_clk) + 499999) / 1000000);
if (!clock_name) {
if ((sys_freq % 16000000) == 0) {
clocksrc = 0;
clockdiv = sys_freq / 16000000;
freq = sys_freq / clockdiv;
}
} else {
clocksrc = 0;
freq = sys_freq / clockdiv;
}
}
if (clocksrc < 0) {
ref_clk = clk_get(&ofdev->dev, "ref_clk");
if (!ref_clk) {
dev_err(&ofdev->dev, "couldn't get ref_clk\n");
goto exit_unmap;
}
clocksrc = 1;
freq = clk_get_rate(ref_clk) / clockdiv;
}
}
out_be32(&clockctl->mccr[clockidx], 0x0);
if (clocksrc >= 0) {
val = (clocksrc << 14) | ((clockdiv - 1) << 17);
out_be32(&clockctl->mccr[clockidx], val);
out_be32(&clockctl->mccr[clockidx], val | 0x10000);
}
val = in_be32(&clockctl->sccr[1]);
if (!(val & (1 << 25)))
out_be32(&clockctl->sccr[1], val | (1 << 25));
dev_dbg(&ofdev->dev, "using '%s' with frequency divider %d\n",
*mscan_clksrc == MSCAN_CLKSRC_IPS ? "ips_clk" :
clocksrc == 1 ? "ref_clk" : "sys_clk", clockdiv);
exit_unmap:
iounmap(clockctl);
exit_put:
of_node_put(np_clock);
return freq;
}
static u32 __devinit mpc512x_can_get_clock(struct platform_device *ofdev,
const char *clock_name,
int *mscan_clksrc)
{
return 0;
}
static int __devinit mpc5xxx_can_probe(struct platform_device *ofdev)
{
const struct of_device_id *match;
struct mpc5xxx_can_data *data;
struct device_node *np = ofdev->dev.of_node;
struct net_device *dev;
struct mscan_priv *priv;
void __iomem *base;
const char *clock_name = NULL;
int irq, mscan_clksrc = 0;
int err = -ENOMEM;
match = of_match_device(mpc5xxx_can_table, &ofdev->dev);
if (!match)
return -EINVAL;
data = match->data;
base = of_iomap(np, 0);
if (!base) {
dev_err(&ofdev->dev, "couldn't ioremap\n");
return err;
}
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
dev_err(&ofdev->dev, "no irq found\n");
err = -ENODEV;
goto exit_unmap_mem;
}
dev = alloc_mscandev();
if (!dev)
goto exit_dispose_irq;
priv = netdev_priv(dev);
priv->reg_base = base;
dev->irq = irq;
clock_name = of_get_property(np, "fsl,mscan-clock-source", NULL);
BUG_ON(!data);
priv->type = data->type;
priv->can.clock.freq = data->get_clock(ofdev, clock_name,
&mscan_clksrc);
if (!priv->can.clock.freq) {
dev_err(&ofdev->dev, "couldn't get MSCAN clock properties\n");
goto exit_free_mscan;
}
SET_NETDEV_DEV(dev, &ofdev->dev);
err = register_mscandev(dev, mscan_clksrc);
if (err) {
dev_err(&ofdev->dev, "registering %s failed (err=%d)\n",
DRV_NAME, err);
goto exit_free_mscan;
}
dev_set_drvdata(&ofdev->dev, dev);
dev_info(&ofdev->dev, "MSCAN at 0x%p, irq %d, clock %d Hz\n",
priv->reg_base, dev->irq, priv->can.clock.freq);
return 0;
exit_free_mscan:
free_candev(dev);
exit_dispose_irq:
irq_dispose_mapping(irq);
exit_unmap_mem:
iounmap(base);
return err;
}
static int __devexit mpc5xxx_can_remove(struct platform_device *ofdev)
{
struct net_device *dev = dev_get_drvdata(&ofdev->dev);
struct mscan_priv *priv = netdev_priv(dev);
dev_set_drvdata(&ofdev->dev, NULL);
unregister_mscandev(dev);
iounmap(priv->reg_base);
irq_dispose_mapping(dev->irq);
free_candev(dev);
return 0;
}
static int mpc5xxx_can_suspend(struct platform_device *ofdev, pm_message_t state)
{
struct net_device *dev = dev_get_drvdata(&ofdev->dev);
struct mscan_priv *priv = netdev_priv(dev);
struct mscan_regs *regs = (struct mscan_regs *)priv->reg_base;
_memcpy_fromio(&saved_regs, regs, sizeof(*regs));
return 0;
}
static int mpc5xxx_can_resume(struct platform_device *ofdev)
{
struct net_device *dev = dev_get_drvdata(&ofdev->dev);
struct mscan_priv *priv = netdev_priv(dev);
struct mscan_regs *regs = (struct mscan_regs *)priv->reg_base;
regs->canctl0 |= MSCAN_INITRQ;
while (!(regs->canctl1 & MSCAN_INITAK))
udelay(10);
regs->canctl1 = saved_regs.canctl1;
regs->canbtr0 = saved_regs.canbtr0;
regs->canbtr1 = saved_regs.canbtr1;
regs->canidac = saved_regs.canidac;
_memcpy_toio(&regs->canidar1_0, (void *)&saved_regs.canidar1_0,
sizeof(*regs) - offsetof(struct mscan_regs, canidar1_0));
regs->canctl0 &= ~MSCAN_INITRQ;
regs->cantbsel = saved_regs.cantbsel;
regs->canrier = saved_regs.canrier;
regs->cantier = saved_regs.cantier;
regs->canctl0 = saved_regs.canctl0;
return 0;
}
static int __init mpc5xxx_can_init(void)
{
return platform_driver_register(&mpc5xxx_can_driver);
}
static void __exit mpc5xxx_can_exit(void)
{
platform_driver_unregister(&mpc5xxx_can_driver);
}
