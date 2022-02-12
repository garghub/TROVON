static int sh_clk_mstp32_enable(struct clk *clk)
{
__raw_writel(__raw_readl(clk->enable_reg) & ~(1 << clk->enable_bit),
clk->enable_reg);
return 0;
}
static void sh_clk_mstp32_disable(struct clk *clk)
{
__raw_writel(__raw_readl(clk->enable_reg) | (1 << clk->enable_bit),
clk->enable_reg);
}
int __init sh_clk_mstp32_register(struct clk *clks, int nr)
{
struct clk *clkp;
int ret = 0;
int k;
for (k = 0; !ret && (k < nr); k++) {
clkp = clks + k;
clkp->ops = &sh_clk_mstp32_clk_ops;
ret |= clk_register(clkp);
}
return ret;
}
static long sh_clk_div_round_rate(struct clk *clk, unsigned long rate)
{
return clk_rate_table_round(clk, clk->freq_table, rate);
}
static unsigned long sh_clk_div6_recalc(struct clk *clk)
{
struct clk_div_mult_table *table = &sh_clk_div6_table;
unsigned int idx;
clk_rate_table_build(clk, clk->freq_table, table->nr_divisors,
table, NULL);
idx = __raw_readl(clk->enable_reg) & 0x003f;
return clk->freq_table[idx].frequency;
}
static int sh_clk_div6_set_parent(struct clk *clk, struct clk *parent)
{
struct clk_div_mult_table *table = &sh_clk_div6_table;
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
value = __raw_readl(clk->enable_reg) &
~(((1 << clk->src_width) - 1) << clk->src_shift);
__raw_writel(value | (i << clk->src_shift), clk->enable_reg);
clk_rate_table_build(clk, clk->freq_table, table->nr_divisors,
table, NULL);
return 0;
}
static int sh_clk_div6_set_rate(struct clk *clk, unsigned long rate)
{
unsigned long value;
int idx;
idx = clk_rate_table_find(clk, clk->freq_table, rate);
if (idx < 0)
return idx;
value = __raw_readl(clk->enable_reg);
value &= ~0x3f;
value |= idx;
__raw_writel(value, clk->enable_reg);
return 0;
}
static int sh_clk_div6_enable(struct clk *clk)
{
unsigned long value;
int ret;
ret = sh_clk_div6_set_rate(clk, clk->rate);
if (ret == 0) {
value = __raw_readl(clk->enable_reg);
value &= ~0x100;
__raw_writel(value, clk->enable_reg);
}
return ret;
}
static void sh_clk_div6_disable(struct clk *clk)
{
unsigned long value;
value = __raw_readl(clk->enable_reg);
value |= 0x100;
value |= 0x3f;
__raw_writel(value, clk->enable_reg);
}
static int __init sh_clk_div6_register_ops(struct clk *clks, int nr,
struct clk_ops *ops)
{
struct clk *clkp;
void *freq_table;
int nr_divs = sh_clk_div6_table.nr_divisors;
int freq_table_size = sizeof(struct cpufreq_frequency_table);
int ret = 0;
int k;
freq_table_size *= (nr_divs + 1);
freq_table = kzalloc(freq_table_size * nr, GFP_KERNEL);
if (!freq_table) {
pr_err("sh_clk_div6_register: unable to alloc memory\n");
return -ENOMEM;
}
for (k = 0; !ret && (k < nr); k++) {
clkp = clks + k;
clkp->ops = ops;
clkp->freq_table = freq_table + (k * freq_table_size);
clkp->freq_table[nr_divs].frequency = CPUFREQ_TABLE_END;
ret = clk_register(clkp);
}
return ret;
}
int __init sh_clk_div6_register(struct clk *clks, int nr)
{
return sh_clk_div6_register_ops(clks, nr, &sh_clk_div6_clk_ops);
}
int __init sh_clk_div6_reparent_register(struct clk *clks, int nr)
{
return sh_clk_div6_register_ops(clks, nr,
&sh_clk_div6_reparent_clk_ops);
}
static unsigned long sh_clk_div4_recalc(struct clk *clk)
{
struct clk_div4_table *d4t = clk->priv;
struct clk_div_mult_table *table = d4t->div_mult_table;
unsigned int idx;
clk_rate_table_build(clk, clk->freq_table, table->nr_divisors,
table, &clk->arch_flags);
idx = (__raw_readl(clk->enable_reg) >> clk->enable_bit) & 0x000f;
return clk->freq_table[idx].frequency;
}
static int sh_clk_div4_set_parent(struct clk *clk, struct clk *parent)
{
struct clk_div4_table *d4t = clk->priv;
struct clk_div_mult_table *table = d4t->div_mult_table;
u32 value;
int ret;
if (parent->flags & CLK_ENABLE_ON_INIT)
value = __raw_readl(clk->enable_reg) & ~(1 << 7);
else
value = __raw_readl(clk->enable_reg) | (1 << 7);
ret = clk_reparent(clk, parent);
if (ret < 0)
return ret;
__raw_writel(value, clk->enable_reg);
clk_rate_table_build(clk, clk->freq_table, table->nr_divisors,
table, &clk->arch_flags);
return 0;
}
static int sh_clk_div4_set_rate(struct clk *clk, unsigned long rate)
{
struct clk_div4_table *d4t = clk->priv;
unsigned long value;
int idx = clk_rate_table_find(clk, clk->freq_table, rate);
if (idx < 0)
return idx;
value = __raw_readl(clk->enable_reg);
value &= ~(0xf << clk->enable_bit);
value |= (idx << clk->enable_bit);
__raw_writel(value, clk->enable_reg);
if (d4t->kick)
d4t->kick(clk);
return 0;
}
static int sh_clk_div4_enable(struct clk *clk)
{
__raw_writel(__raw_readl(clk->enable_reg) & ~(1 << 8), clk->enable_reg);
return 0;
}
static void sh_clk_div4_disable(struct clk *clk)
{
__raw_writel(__raw_readl(clk->enable_reg) | (1 << 8), clk->enable_reg);
}
static int __init sh_clk_div4_register_ops(struct clk *clks, int nr,
struct clk_div4_table *table, struct clk_ops *ops)
{
struct clk *clkp;
void *freq_table;
int nr_divs = table->div_mult_table->nr_divisors;
int freq_table_size = sizeof(struct cpufreq_frequency_table);
int ret = 0;
int k;
freq_table_size *= (nr_divs + 1);
freq_table = kzalloc(freq_table_size * nr, GFP_KERNEL);
if (!freq_table) {
pr_err("sh_clk_div4_register: unable to alloc memory\n");
return -ENOMEM;
}
for (k = 0; !ret && (k < nr); k++) {
clkp = clks + k;
clkp->ops = ops;
clkp->priv = table;
clkp->freq_table = freq_table + (k * freq_table_size);
clkp->freq_table[nr_divs].frequency = CPUFREQ_TABLE_END;
ret = clk_register(clkp);
}
return ret;
}
int __init sh_clk_div4_register(struct clk *clks, int nr,
struct clk_div4_table *table)
{
return sh_clk_div4_register_ops(clks, nr, table, &sh_clk_div4_clk_ops);
}
int __init sh_clk_div4_enable_register(struct clk *clks, int nr,
struct clk_div4_table *table)
{
return sh_clk_div4_register_ops(clks, nr, table,
&sh_clk_div4_enable_clk_ops);
}
int __init sh_clk_div4_reparent_register(struct clk *clks, int nr,
struct clk_div4_table *table)
{
return sh_clk_div4_register_ops(clks, nr, table,
&sh_clk_div4_reparent_clk_ops);
}
