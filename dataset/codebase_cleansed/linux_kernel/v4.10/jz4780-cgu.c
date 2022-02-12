static u8 jz4780_otg_phy_get_parent(struct clk_hw *hw)
{
return 0;
}
static int jz4780_otg_phy_set_parent(struct clk_hw *hw, u8 idx)
{
unsigned long flags;
u32 usbpcr1;
if (idx > 0)
return -EINVAL;
spin_lock_irqsave(&cgu->lock, flags);
usbpcr1 = readl(cgu->base + CGU_REG_USBPCR1);
usbpcr1 &= ~USBPCR1_REFCLKSEL_MASK;
usbpcr1 |= USBPCR1_REFCLKSEL_CORE;
writel(usbpcr1, cgu->base + CGU_REG_USBPCR1);
spin_unlock_irqrestore(&cgu->lock, flags);
return 0;
}
static unsigned long jz4780_otg_phy_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
u32 usbpcr1;
unsigned refclk_div;
usbpcr1 = readl(cgu->base + CGU_REG_USBPCR1);
refclk_div = usbpcr1 & USBPCR1_REFCLKDIV_MASK;
switch (refclk_div) {
case USBPCR1_REFCLKDIV_12:
return 12000000;
case USBPCR1_REFCLKDIV_24:
return 24000000;
case USBPCR1_REFCLKDIV_48:
return 48000000;
case USBPCR1_REFCLKDIV_19_2:
return 19200000;
}
BUG();
return parent_rate;
}
static long jz4780_otg_phy_round_rate(struct clk_hw *hw, unsigned long req_rate,
unsigned long *parent_rate)
{
if (req_rate < 15600000)
return 12000000;
if (req_rate < 21600000)
return 19200000;
if (req_rate < 36000000)
return 24000000;
return 48000000;
}
static int jz4780_otg_phy_set_rate(struct clk_hw *hw, unsigned long req_rate,
unsigned long parent_rate)
{
unsigned long flags;
u32 usbpcr1, div_bits;
switch (req_rate) {
case 12000000:
div_bits = USBPCR1_REFCLKDIV_12;
break;
case 19200000:
div_bits = USBPCR1_REFCLKDIV_19_2;
break;
case 24000000:
div_bits = USBPCR1_REFCLKDIV_24;
break;
case 48000000:
div_bits = USBPCR1_REFCLKDIV_48;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&cgu->lock, flags);
usbpcr1 = readl(cgu->base + CGU_REG_USBPCR1);
usbpcr1 &= ~USBPCR1_REFCLKDIV_MASK;
usbpcr1 |= div_bits;
writel(usbpcr1, cgu->base + CGU_REG_USBPCR1);
spin_unlock_irqrestore(&cgu->lock, flags);
return 0;
}
static void __init jz4780_cgu_init(struct device_node *np)
{
int retval;
cgu = ingenic_cgu_new(jz4780_cgu_clocks,
ARRAY_SIZE(jz4780_cgu_clocks), np);
if (!cgu) {
pr_err("%s: failed to initialise CGU\n", __func__);
return;
}
retval = ingenic_cgu_register_clocks(cgu);
if (retval) {
pr_err("%s: failed to register CGU Clocks\n", __func__);
return;
}
}
