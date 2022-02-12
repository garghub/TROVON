static unsigned long pllc01_recalc(struct clk *clk)
{
unsigned long mult = 1;
if (__raw_readl(PLLC01CR) & (1 << 14))
mult = ((__raw_readl(clk->enable_reg) >> 24) & 0x7f) + 1;
return clk->parent->rate * mult;
}
static int usb24s_enable(struct clk *clk)
{
__raw_writel(__raw_readl(USBCKCR) & ~(1 << 8), USBCKCR);
return 0;
}
static void usb24s_disable(struct clk *clk)
{
__raw_writel(__raw_readl(USBCKCR) | (1 << 8), USBCKCR);
}
static int usb24s_set_parent(struct clk *clk, struct clk *parent)
{
int i, ret;
u32 val;
if (!clk->parent_table || !clk->parent_num)
return -EINVAL;
for (i = 0; i < clk->parent_num; i++)
if (clk->parent_table[i] == parent)
break;
if (i == clk->parent_num)
return -ENODEV;
ret = clk_reparent(clk, parent);
if (ret < 0)
return ret;
val = __raw_readl(USBCKCR);
val &= ~(1 << 7);
val |= i << 7;
__raw_writel(val, USBCKCR);
return 0;
}
static unsigned long usb24_recalc(struct clk *clk)
{
return clk->parent->rate /
((__raw_readl(USBCKCR) & (1 << 6)) ? 1 : 2);
}
static int usb24_set_rate(struct clk *clk, unsigned long rate)
{
u32 val;
val = __raw_readl(USBCKCR);
val &= ~(1 << 6);
val |= (rate > (clk->parent->rate / 4) * 3) << 6;
__raw_writel(val, USBCKCR);
return 0;
}
static void div4_kick(struct clk *clk)
{
unsigned long value;
value = __raw_readl(FRQCRB);
value |= (1 << 31);
__raw_writel(value, FRQCRB);
}
static unsigned long hdmi12_recalc(struct clk *clk)
{
u32 val = __raw_readl(HDMICKCR);
int shift = (int)clk->priv;
val >>= shift;
val &= 0x3;
return clk->parent->rate / (1 << val);
}
static int hdmi12_set_rate(struct clk *clk, unsigned long rate)
{
u32 val, mask;
int i, shift;
for (i = 0; i < 3; i++)
if (rate == clk->parent->rate / (1 << i))
goto find;
return -ENODEV;
find:
shift = (int)clk->priv;
val = __raw_readl(HDMICKCR);
mask = ~(0x3 << shift);
val = (val & mask) | i << shift;
__raw_writel(val, HDMICKCR);
return 0;
}
void __init r8a7740_clock_init(u8 md_ck)
{
int k, ret = 0;
if (md_ck & MD_CK1)
system_clk.parent = &extal1_div2_clk;
else
system_clk.parent = &extal1_clk;
switch (md_ck & (MD_CK2 | MD_CK1)) {
case MD_CK2 | MD_CK1:
r_clk.parent = &extal1_div2048_clk;
break;
case MD_CK2:
r_clk.parent = &extal1_div1024_clk;
break;
case MD_CK1:
default:
r_clk.parent = &extalr_clk;
break;
}
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret)
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
ret = sh_clk_div6_register(div6_clks, DIV6_NR);
if (!ret)
ret = sh_clk_div6_reparent_register(div6_reparent_clks,
DIV6_REPARENT_NR);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
for (k = 0; !ret && (k < ARRAY_SIZE(late_main_clks)); k++)
ret = clk_register(late_main_clks[k]);
if (!ret)
ret = sh_clk_fsidiv_register(fsidivs, FSIDIV_REPARENT_NR);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
panic("failed to setup r8a7740 clocks\n");
}
