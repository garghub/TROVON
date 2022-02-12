static int init_div_table(void)
{
struct cpufreq_frequency_table *pos, *freq_tbl = dvfs_info->freq_table;
unsigned int tmp, clk_div, ema_div, freq, volt_id;
struct dev_pm_opp *opp;
rcu_read_lock();
cpufreq_for_each_entry(pos, freq_tbl) {
opp = dev_pm_opp_find_freq_exact(dvfs_info->dev,
pos->frequency * 1000, true);
if (IS_ERR(opp)) {
rcu_read_unlock();
dev_err(dvfs_info->dev,
"failed to find valid OPP for %u KHZ\n",
pos->frequency);
return PTR_ERR(opp);
}
freq = pos->frequency / 1000;
clk_div = ((freq / CPU_DIV_FREQ_MAX) & P0_7_CPUCLKDEV_MASK)
<< P0_7_CPUCLKDEV_SHIFT;
clk_div |= ((freq / CPU_ATB_FREQ_MAX) & P0_7_ATBCLKDEV_MASK)
<< P0_7_ATBCLKDEV_SHIFT;
clk_div |= ((freq / CPU_DBG_FREQ_MAX) & P0_7_CSCLKDEV_MASK)
<< P0_7_CSCLKDEV_SHIFT;
volt_id = dev_pm_opp_get_voltage(opp);
volt_id = (MAX_VOLTAGE - volt_id) / VOLTAGE_STEP;
if (volt_id < PMIC_HIGH_VOLT) {
ema_div = (CPUEMA_HIGH << P0_7_CPUEMA_SHIFT) |
(L2EMA_HIGH << P0_7_L2EMA_SHIFT);
} else if (volt_id > PMIC_LOW_VOLT) {
ema_div = (CPUEMA_LOW << P0_7_CPUEMA_SHIFT) |
(L2EMA_LOW << P0_7_L2EMA_SHIFT);
} else {
ema_div = (CPUEMA_MID << P0_7_CPUEMA_SHIFT) |
(L2EMA_MID << P0_7_L2EMA_SHIFT);
}
tmp = (clk_div | ema_div | (volt_id << P0_7_VDD_SHIFT)
| ((freq / FREQ_UNIT) << P0_7_FREQ_SHIFT));
__raw_writel(tmp, dvfs_info->base + XMU_PMU_P0_7 + 4 *
(pos - freq_tbl));
}
rcu_read_unlock();
return 0;
}
static void exynos_enable_dvfs(unsigned int cur_frequency)
{
unsigned int tmp, cpu;
struct cpufreq_frequency_table *freq_table = dvfs_info->freq_table;
struct cpufreq_frequency_table *pos;
__raw_writel(0, dvfs_info->base + XMU_DVFS_CTRL);
tmp = __raw_readl(dvfs_info->base + XMU_PMUEVTEN);
tmp |= (1 << PSTATE_CHANGED_EVTEN_SHIFT);
__raw_writel(tmp, dvfs_info->base + XMU_PMUEVTEN);
tmp = __raw_readl(dvfs_info->base + XMU_PMUIRQEN);
tmp |= (1 << PSTATE_CHANGED_IRQEN_SHIFT);
__raw_writel(tmp, dvfs_info->base + XMU_PMUIRQEN);
cpufreq_for_each_entry(pos, freq_table)
if (pos->frequency == cur_frequency)
break;
if (pos->frequency == CPUFREQ_TABLE_END) {
dev_crit(dvfs_info->dev, "Boot up frequency not supported\n");
pos = freq_table;
cur_frequency = pos->frequency;
}
dev_info(dvfs_info->dev, "Setting dvfs initial frequency = %uKHZ",
cur_frequency);
for (cpu = 0; cpu < CONFIG_NR_CPUS; cpu++) {
tmp = __raw_readl(dvfs_info->base + XMU_C0_3_PSTATE + cpu * 4);
tmp &= ~(P_VALUE_MASK << C0_3_PSTATE_NEW_SHIFT);
tmp |= ((pos - freq_table) << C0_3_PSTATE_NEW_SHIFT);
__raw_writel(tmp, dvfs_info->base + XMU_C0_3_PSTATE + cpu * 4);
}
__raw_writel(1 << XMU_DVFS_CTRL_EN_SHIFT,
dvfs_info->base + XMU_DVFS_CTRL);
}
static int exynos_target(struct cpufreq_policy *policy, unsigned int index)
{
unsigned int tmp;
int i;
struct cpufreq_frequency_table *freq_table = dvfs_info->freq_table;
mutex_lock(&cpufreq_lock);
freqs.old = policy->cur;
freqs.new = freq_table[index].frequency;
cpufreq_freq_transition_begin(policy, &freqs);
for_each_cpu(i, policy->cpus) {
tmp = __raw_readl(dvfs_info->base + XMU_C0_3_PSTATE + i * 4);
tmp &= ~(P_VALUE_MASK << C0_3_PSTATE_NEW_SHIFT);
tmp |= (index << C0_3_PSTATE_NEW_SHIFT);
__raw_writel(tmp, dvfs_info->base + XMU_C0_3_PSTATE + i * 4);
}
mutex_unlock(&cpufreq_lock);
return 0;
}
static void exynos_cpufreq_work(struct work_struct *work)
{
unsigned int cur_pstate, index;
struct cpufreq_policy *policy = cpufreq_cpu_get(0);
struct cpufreq_frequency_table *freq_table = dvfs_info->freq_table;
if (unlikely(dvfs_info->dvfs_enabled == false))
goto skip_work;
mutex_lock(&cpufreq_lock);
freqs.old = policy->cur;
cur_pstate = __raw_readl(dvfs_info->base + XMU_P_STATUS);
if (cur_pstate >> C0_3_PSTATE_VALID_SHIFT & 0x1)
index = (cur_pstate >> C0_3_PSTATE_CURR_SHIFT) & P_VALUE_MASK;
else
index = (cur_pstate >> C0_3_PSTATE_NEW_SHIFT) & P_VALUE_MASK;
if (likely(index < dvfs_info->freq_count)) {
freqs.new = freq_table[index].frequency;
} else {
dev_crit(dvfs_info->dev, "New frequency out of range\n");
freqs.new = freqs.old;
}
cpufreq_freq_transition_end(policy, &freqs, 0);
cpufreq_cpu_put(policy);
mutex_unlock(&cpufreq_lock);
skip_work:
enable_irq(dvfs_info->irq);
}
static irqreturn_t exynos_cpufreq_irq(int irq, void *id)
{
unsigned int tmp;
tmp = __raw_readl(dvfs_info->base + XMU_PMUIRQ);
if (tmp >> PSTATE_CHANGED_SHIFT & 0x1) {
__raw_writel(tmp, dvfs_info->base + XMU_PMUIRQ);
disable_irq_nosync(irq);
schedule_work(&dvfs_info->irq_work);
}
return IRQ_HANDLED;
}
static void exynos_sort_descend_freq_table(void)
{
struct cpufreq_frequency_table *freq_tbl = dvfs_info->freq_table;
int i = 0, index;
unsigned int tmp_freq;
for (i = 0; i < dvfs_info->freq_count / 2; i++) {
index = dvfs_info->freq_count - i - 1;
tmp_freq = freq_tbl[i].frequency;
freq_tbl[i].frequency = freq_tbl[index].frequency;
freq_tbl[index].frequency = tmp_freq;
}
}
static int exynos_cpufreq_cpu_init(struct cpufreq_policy *policy)
{
policy->clk = dvfs_info->cpu_clk;
return cpufreq_generic_init(policy, dvfs_info->freq_table,
dvfs_info->latency);
}
static int exynos_cpufreq_probe(struct platform_device *pdev)
{
int ret = -EINVAL;
struct device_node *np;
struct resource res;
unsigned int cur_frequency;
np = pdev->dev.of_node;
if (!np)
return -ENODEV;
dvfs_info = devm_kzalloc(&pdev->dev, sizeof(*dvfs_info), GFP_KERNEL);
if (!dvfs_info) {
ret = -ENOMEM;
goto err_put_node;
}
dvfs_info->dev = &pdev->dev;
ret = of_address_to_resource(np, 0, &res);
if (ret)
goto err_put_node;
dvfs_info->base = devm_ioremap_resource(dvfs_info->dev, &res);
if (IS_ERR(dvfs_info->base)) {
ret = PTR_ERR(dvfs_info->base);
goto err_put_node;
}
dvfs_info->irq = irq_of_parse_and_map(np, 0);
if (!dvfs_info->irq) {
dev_err(dvfs_info->dev, "No cpufreq irq found\n");
ret = -ENODEV;
goto err_put_node;
}
ret = of_init_opp_table(dvfs_info->dev);
if (ret) {
dev_err(dvfs_info->dev, "failed to init OPP table: %d\n", ret);
goto err_put_node;
}
ret = dev_pm_opp_init_cpufreq_table(dvfs_info->dev,
&dvfs_info->freq_table);
if (ret) {
dev_err(dvfs_info->dev,
"failed to init cpufreq table: %d\n", ret);
goto err_put_node;
}
dvfs_info->freq_count = dev_pm_opp_get_opp_count(dvfs_info->dev);
exynos_sort_descend_freq_table();
if (of_property_read_u32(np, "clock-latency", &dvfs_info->latency))
dvfs_info->latency = DEF_TRANS_LATENCY;
dvfs_info->cpu_clk = devm_clk_get(dvfs_info->dev, "armclk");
if (IS_ERR(dvfs_info->cpu_clk)) {
dev_err(dvfs_info->dev, "Failed to get cpu clock\n");
ret = PTR_ERR(dvfs_info->cpu_clk);
goto err_free_table;
}
cur_frequency = clk_get_rate(dvfs_info->cpu_clk);
if (!cur_frequency) {
dev_err(dvfs_info->dev, "Failed to get clock rate\n");
ret = -EINVAL;
goto err_free_table;
}
cur_frequency /= 1000;
INIT_WORK(&dvfs_info->irq_work, exynos_cpufreq_work);
ret = devm_request_irq(dvfs_info->dev, dvfs_info->irq,
exynos_cpufreq_irq, IRQF_TRIGGER_NONE,
CPUFREQ_NAME, dvfs_info);
if (ret) {
dev_err(dvfs_info->dev, "Failed to register IRQ\n");
goto err_free_table;
}
ret = init_div_table();
if (ret) {
dev_err(dvfs_info->dev, "Failed to initialise div table\n");
goto err_free_table;
}
exynos_enable_dvfs(cur_frequency);
ret = cpufreq_register_driver(&exynos_driver);
if (ret) {
dev_err(dvfs_info->dev,
"%s: failed to register cpufreq driver\n", __func__);
goto err_free_table;
}
of_node_put(np);
dvfs_info->dvfs_enabled = true;
return 0;
err_free_table:
dev_pm_opp_free_cpufreq_table(dvfs_info->dev, &dvfs_info->freq_table);
err_put_node:
of_node_put(np);
dev_err(&pdev->dev, "%s: failed initialization\n", __func__);
return ret;
}
static int exynos_cpufreq_remove(struct platform_device *pdev)
{
cpufreq_unregister_driver(&exynos_driver);
dev_pm_opp_free_cpufreq_table(dvfs_info->dev, &dvfs_info->freq_table);
return 0;
}
