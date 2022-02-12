struct clk *clk_get(struct device *dev, const char *id)
{
return &cpu_clk;
}
static void propagate_rate(struct clk *clk)
{
struct clk *clkp;
list_for_each_entry(clkp, &clock_list, node) {
if (likely(clkp->parent != clk))
continue;
if (likely(clkp->ops && clkp->ops->recalc))
clkp->ops->recalc(clkp);
if (unlikely(clkp->flags & CLK_RATE_PROPAGATES))
propagate_rate(clkp);
}
}
int clk_enable(struct clk *clk)
{
return 0;
}
void clk_disable(struct clk *clk)
{
}
unsigned long clk_get_rate(struct clk *clk)
{
return (unsigned long)clk->rate;
}
void clk_put(struct clk *clk)
{
}
int clk_set_rate(struct clk *clk, unsigned long rate)
{
return clk_set_rate_ex(clk, rate, 0);
}
int clk_set_rate_ex(struct clk *clk, unsigned long rate, int algo_id)
{
int ret = 0;
int regval;
int i;
if (likely(clk->ops && clk->ops->set_rate)) {
unsigned long flags;
spin_lock_irqsave(&clock_lock, flags);
ret = clk->ops->set_rate(clk, rate, algo_id);
spin_unlock_irqrestore(&clock_lock, flags);
}
if (unlikely(clk->flags & CLK_RATE_PROPAGATES))
propagate_rate(clk);
for (i = 0; loongson2_clockmod_table[i].frequency != CPUFREQ_TABLE_END;
i++) {
if (loongson2_clockmod_table[i].frequency ==
CPUFREQ_ENTRY_INVALID)
continue;
if (rate == loongson2_clockmod_table[i].frequency)
break;
}
if (rate != loongson2_clockmod_table[i].frequency)
return -ENOTSUPP;
clk->rate = rate;
regval = LOONGSON_CHIPCFG0;
regval = (regval & ~0x7) | (loongson2_clockmod_table[i].index - 1);
LOONGSON_CHIPCFG0 = regval;
return ret;
}
long clk_round_rate(struct clk *clk, unsigned long rate)
{
if (likely(clk->ops && clk->ops->round_rate)) {
unsigned long flags, rounded;
spin_lock_irqsave(&clock_lock, flags);
rounded = clk->ops->round_rate(clk, rate);
spin_unlock_irqrestore(&clock_lock, flags);
return rounded;
}
return rate;
}
void loongson2_cpu_wait(void)
{
u32 cpu_freq;
unsigned long flags;
spin_lock_irqsave(&loongson2_wait_lock, flags);
cpu_freq = LOONGSON_CHIPCFG0;
LOONGSON_CHIPCFG0 &= ~0x7;
LOONGSON_CHIPCFG0 = cpu_freq;
spin_unlock_irqrestore(&loongson2_wait_lock, flags);
}
