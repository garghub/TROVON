static unsigned long pllc01_recalc(struct clk *clk)
{
unsigned long mult = 1;
if (__raw_readl(PLLC01CR) & (1 << 14))
mult = (((__raw_readl(clk->enable_reg) >> 24) & 0x3f) + 1) * 2;
return clk->parent->rate * mult;
}
static void pllc2_table_rebuild(struct clk *clk)
{
int i;
for (i = 0; i < ARRAY_SIZE(pllc2_freq_table) - 2; i++) {
pllc2_freq_table[i].frequency = clk->parent->rate * (i + 20) * 2;
pllc2_freq_table[i].driver_data = i;
}
pllc2_freq_table[i].frequency = clk->parent->rate;
pllc2_freq_table[i].driver_data = i;
pllc2_freq_table[++i].frequency = CPUFREQ_TABLE_END;
pllc2_freq_table[i].driver_data = i;
}
static unsigned long pllc2_recalc(struct clk *clk)
{
unsigned long mult = 1;
pllc2_table_rebuild(clk);
if (__raw_readl(PLLC2CR) & (1 << 31))
mult = (((__raw_readl(PLLC2CR) >> 24) & 0x3f) + 1) * 2;
return clk->parent->rate * mult;
}
static long pllc2_round_rate(struct clk *clk, unsigned long rate)
{
return clk_rate_table_round(clk, clk->freq_table, rate);
}
static int pllc2_enable(struct clk *clk)
{
int i;
__raw_writel(__raw_readl(PLLC2CR) | 0x80000000, PLLC2CR);
for (i = 0; i < 100; i++)
if (__raw_readl(PLLC2CR) & 0x80000000) {
clk->rate = pllc2_recalc(clk);
return 0;
}
pr_err("%s(): timeout!\n", __func__);
return -ETIMEDOUT;
}
static void pllc2_disable(struct clk *clk)
{
__raw_writel(__raw_readl(PLLC2CR) & ~0x80000000, PLLC2CR);
}
static int pllc2_set_rate(struct clk *clk, unsigned long rate)
{
unsigned long value;
int idx;
idx = clk_rate_table_find(clk, clk->freq_table, rate);
if (idx < 0)
return idx;
if (rate == clk->parent->rate)
return -EINVAL;
value = __raw_readl(PLLC2CR) & ~(0x3f << 24);
__raw_writel(value | ((idx + 19) << 24), PLLC2CR);
clk->rate = clk->freq_table[idx].frequency;
return 0;
}
static int pllc2_set_parent(struct clk *clk, struct clk *parent)
{
u32 value;
int ret, i;
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
value = __raw_readl(PLLC2CR) & ~(3 << 6);
__raw_writel(value | (i << 6), PLLC2CR);
pllc2_table_rebuild(clk);
return 0;
}
static void div4_kick(struct clk *clk)
{
unsigned long value;
value = __raw_readl(FRQCRB);
value |= (1 << 31);
__raw_writel(value, FRQCRB);
}
void __init sh7372_clock_init(void)
{
int k, ret = 0;
__raw_writel(0xe4ef8087, RMSTPCR0);
__raw_writel(0xffffffff, RMSTPCR1);
__raw_writel(0x37c7f7ff, RMSTPCR2);
__raw_writel(0xffffffff, RMSTPCR3);
__raw_writel(0xffe0fffd, RMSTPCR4);
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret)
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
ret = sh_clk_div6_register(div6_clks, DIV6_NR);
if (!ret)
ret = sh_clk_div6_reparent_register(div6_reparent_clks, DIV6_REPARENT_NR);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
if (!ret)
ret = sh_clk_fsidiv_register(fsidivs, FSIDIV_REPARENT_NR);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
panic("failed to setup sh7372 clocks\n");
}
