static inline void emc_writel(u32 val, unsigned long addr)
{
writel(val, emc + addr);
}
static inline u32 emc_readl(unsigned long addr)
{
return readl(emc + addr);
}
long tegra_emc_round_rate(unsigned long rate)
{
int i;
int best = -1;
unsigned long distance = ULONG_MAX;
if (!tegra_emc_table)
return -EINVAL;
if (!emc_enable)
return -EINVAL;
pr_debug("%s: %lu\n", __func__, rate);
rate = rate / 2 / 1000;
for (i = 0; i < tegra_emc_table_size; i++) {
if (tegra_emc_table[i].rate >= rate &&
(tegra_emc_table[i].rate - rate) < distance) {
distance = tegra_emc_table[i].rate - rate;
best = i;
}
}
if (best < 0)
return -EINVAL;
pr_debug("%s: using %lu\n", __func__, tegra_emc_table[best].rate);
return tegra_emc_table[best].rate * 2 * 1000;
}
int tegra_emc_set_rate(unsigned long rate)
{
int i;
int j;
if (!tegra_emc_table)
return -EINVAL;
rate = rate / 2 / 1000;
for (i = 0; i < tegra_emc_table_size; i++)
if (tegra_emc_table[i].rate == rate)
break;
if (i >= tegra_emc_table_size)
return -EINVAL;
pr_debug("%s: setting to %lu\n", __func__, rate);
for (j = 0; j < TEGRA_EMC_NUM_REGS; j++)
emc_writel(tegra_emc_table[i].regs[j], emc_reg_addr[j]);
emc_readl(tegra_emc_table[i].regs[TEGRA_EMC_NUM_REGS - 1]);
return 0;
}
void tegra_init_emc(const struct tegra_emc_table *table, int table_size)
{
tegra_emc_table = table;
tegra_emc_table_size = table_size;
}
