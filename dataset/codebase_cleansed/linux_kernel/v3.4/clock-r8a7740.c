static unsigned long div_recalc(struct clk *clk)
{
return clk->parent->rate / (int)(clk->priv);
}
static unsigned long pllc01_recalc(struct clk *clk)
{
unsigned long mult = 1;
if (__raw_readl(PLLC01CR) & (1 << 14))
mult = ((__raw_readl(clk->enable_reg) >> 24) & 0x7f) + 1;
return clk->parent->rate * mult;
}
static void div4_kick(struct clk *clk)
{
unsigned long value;
value = __raw_readl(FRQCRB);
value |= (1 << 31);
__raw_writel(value, FRQCRB);
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
ret = sh_clk_mstp32_register(mstp_clks, MSTP_NR);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
panic("failed to setup r8a7740 clocks\n");
}
