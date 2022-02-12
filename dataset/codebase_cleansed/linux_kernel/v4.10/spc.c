static inline bool cluster_is_a15(u32 cluster)
{
return cluster == info->a15_clusid;
}
void ve_spc_global_wakeup_irq(bool set)
{
u32 reg;
reg = readl_relaxed(info->baseaddr + WAKE_INT_MASK);
if (set)
reg |= GBL_WAKEUP_INT_MSK;
else
reg &= ~GBL_WAKEUP_INT_MSK;
writel_relaxed(reg, info->baseaddr + WAKE_INT_MASK);
}
void ve_spc_cpu_wakeup_irq(u32 cluster, u32 cpu, bool set)
{
u32 mask, reg;
if (cluster >= MAX_CLUSTERS)
return;
mask = 1 << cpu;
if (!cluster_is_a15(cluster))
mask <<= 4;
reg = readl_relaxed(info->baseaddr + WAKE_INT_MASK);
if (set)
reg |= mask;
else
reg &= ~mask;
writel_relaxed(reg, info->baseaddr + WAKE_INT_MASK);
}
void ve_spc_set_resume_addr(u32 cluster, u32 cpu, u32 addr)
{
void __iomem *baseaddr;
if (cluster >= MAX_CLUSTERS)
return;
if (cluster_is_a15(cluster))
baseaddr = info->baseaddr + A15_BX_ADDR0 + (cpu << 2);
else
baseaddr = info->baseaddr + A7_BX_ADDR0 + (cpu << 2);
writel_relaxed(addr, baseaddr);
}
void ve_spc_powerdown(u32 cluster, bool enable)
{
u32 pwdrn_reg;
if (cluster >= MAX_CLUSTERS)
return;
pwdrn_reg = cluster_is_a15(cluster) ? A15_PWRDN_EN : A7_PWRDN_EN;
writel_relaxed(enable, info->baseaddr + pwdrn_reg);
}
static u32 standbywfi_cpu_mask(u32 cpu, u32 cluster)
{
return cluster_is_a15(cluster) ?
STANDBYWFI_STAT_A15_CPU_MASK(cpu)
: STANDBYWFI_STAT_A7_CPU_MASK(cpu);
}
int ve_spc_cpu_in_wfi(u32 cpu, u32 cluster)
{
int ret;
u32 mask = standbywfi_cpu_mask(cpu, cluster);
if (cluster >= MAX_CLUSTERS)
return 1;
ret = readl_relaxed(info->baseaddr + STANDBYWFI_STAT);
pr_debug("%s: PCFGREG[0x%X] = 0x%08X, mask = 0x%X\n",
__func__, STANDBYWFI_STAT, ret, mask);
return ret & mask;
}
static int ve_spc_get_performance(int cluster, u32 *freq)
{
struct ve_spc_opp *opps = info->opps[cluster];
u32 perf_cfg_reg = 0;
u32 perf;
perf_cfg_reg = cluster_is_a15(cluster) ? PERF_LVL_A15 : PERF_LVL_A7;
perf = readl_relaxed(info->baseaddr + perf_cfg_reg);
if (perf >= info->num_opps[cluster])
return -EINVAL;
opps += perf;
*freq = opps->freq;
return 0;
}
static int ve_spc_round_performance(int cluster, u32 freq)
{
int idx, max_opp = info->num_opps[cluster];
struct ve_spc_opp *opps = info->opps[cluster];
u32 fmin = 0, fmax = ~0, ftmp;
freq /= 1000;
for (idx = 0; idx < max_opp; idx++, opps++) {
ftmp = opps->freq;
if (ftmp >= freq) {
if (ftmp <= fmax)
fmax = ftmp;
} else {
if (ftmp >= fmin)
fmin = ftmp;
}
}
if (fmax != ~0)
return fmax * 1000;
else
return fmin * 1000;
}
static int ve_spc_find_performance_index(int cluster, u32 freq)
{
int idx, max_opp = info->num_opps[cluster];
struct ve_spc_opp *opps = info->opps[cluster];
for (idx = 0; idx < max_opp; idx++, opps++)
if (opps->freq == freq)
break;
return (idx == max_opp) ? -EINVAL : idx;
}
static int ve_spc_waitforcompletion(int req_type)
{
int ret = wait_for_completion_interruptible_timeout(
&info->done, usecs_to_jiffies(TIMEOUT_US));
if (ret == 0)
ret = -ETIMEDOUT;
else if (ret > 0)
ret = info->cur_rsp_stat & STAT_COMPLETE(req_type) ? 0 : -EIO;
return ret;
}
static int ve_spc_set_performance(int cluster, u32 freq)
{
u32 perf_cfg_reg;
int ret, perf, req_type;
if (cluster_is_a15(cluster)) {
req_type = CA15_DVFS;
perf_cfg_reg = PERF_LVL_A15;
} else {
req_type = CA7_DVFS;
perf_cfg_reg = PERF_LVL_A7;
}
perf = ve_spc_find_performance_index(cluster, freq);
if (perf < 0)
return perf;
if (down_timeout(&info->sem, usecs_to_jiffies(TIMEOUT_US)))
return -ETIME;
init_completion(&info->done);
info->cur_rsp_mask = RESPONSE_MASK(req_type);
writel(perf, info->baseaddr + perf_cfg_reg);
ret = ve_spc_waitforcompletion(req_type);
info->cur_rsp_mask = 0;
up(&info->sem);
return ret;
}
static int ve_spc_read_sys_cfg(int func, int offset, uint32_t *data)
{
int ret;
if (down_timeout(&info->sem, usecs_to_jiffies(TIMEOUT_US)))
return -ETIME;
init_completion(&info->done);
info->cur_rsp_mask = RESPONSE_MASK(SPC_SYS_CFG);
writel(SYSCFG_START | func | offset >> 2, info->baseaddr + COMMS);
ret = ve_spc_waitforcompletion(SPC_SYS_CFG);
if (ret == 0)
*data = readl(info->baseaddr + SYSCFG_RDATA);
info->cur_rsp_mask = 0;
up(&info->sem);
return ret;
}
static irqreturn_t ve_spc_irq_handler(int irq, void *data)
{
struct ve_spc_drvdata *drv_data = data;
uint32_t status = readl_relaxed(drv_data->baseaddr + PWC_STATUS);
if (info->cur_rsp_mask & status) {
info->cur_rsp_stat = status;
complete(&drv_data->done);
}
return IRQ_HANDLED;
}
static int ve_spc_populate_opps(uint32_t cluster)
{
uint32_t data = 0, off, ret, idx;
struct ve_spc_opp *opps;
opps = kzalloc(sizeof(*opps) * MAX_OPPS, GFP_KERNEL);
if (!opps)
return -ENOMEM;
info->opps[cluster] = opps;
off = cluster_is_a15(cluster) ? A15_PERFVAL_BASE : A7_PERFVAL_BASE;
for (idx = 0; idx < MAX_OPPS; idx++, off += 4, opps++) {
ret = ve_spc_read_sys_cfg(SYSCFG_SCC, off, &data);
if (!ret) {
opps->freq = (data & FREQ_MASK) * MULT_FACTOR;
opps->u_volt = (data >> VOLT_SHIFT) * 1000;
} else {
break;
}
}
info->num_opps[cluster] = idx;
return ret;
}
static int ve_init_opp_table(struct device *cpu_dev)
{
int cluster;
int idx, ret = 0, max_opp;
struct ve_spc_opp *opps;
cluster = topology_physical_package_id(cpu_dev->id);
cluster = cluster < 0 ? 0 : cluster;
max_opp = info->num_opps[cluster];
opps = info->opps[cluster];
for (idx = 0; idx < max_opp; idx++, opps++) {
ret = dev_pm_opp_add(cpu_dev, opps->freq * 1000, opps->u_volt);
if (ret) {
dev_warn(cpu_dev, "failed to add opp %lu %lu\n",
opps->freq, opps->u_volt);
return ret;
}
}
return ret;
}
int __init ve_spc_init(void __iomem *baseaddr, u32 a15_clusid, int irq)
{
int ret;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
pr_err(SPCLOG "unable to allocate mem\n");
return -ENOMEM;
}
info->baseaddr = baseaddr;
info->a15_clusid = a15_clusid;
if (irq <= 0) {
pr_err(SPCLOG "Invalid IRQ %d\n", irq);
kfree(info);
return -EINVAL;
}
init_completion(&info->done);
readl_relaxed(info->baseaddr + PWC_STATUS);
ret = request_irq(irq, ve_spc_irq_handler, IRQF_TRIGGER_HIGH
| IRQF_ONESHOT, "vexpress-spc", info);
if (ret) {
pr_err(SPCLOG "IRQ %d request failed\n", irq);
kfree(info);
return -ENODEV;
}
sema_init(&info->sem, 1);
sync_cache_w(info);
sync_cache_w(&info);
return 0;
}
static unsigned long spc_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_spc *spc = to_clk_spc(hw);
u32 freq;
if (ve_spc_get_performance(spc->cluster, &freq))
return -EIO;
return freq * 1000;
}
static long spc_round_rate(struct clk_hw *hw, unsigned long drate,
unsigned long *parent_rate)
{
struct clk_spc *spc = to_clk_spc(hw);
return ve_spc_round_performance(spc->cluster, drate);
}
static int spc_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_spc *spc = to_clk_spc(hw);
return ve_spc_set_performance(spc->cluster, rate / 1000);
}
static struct clk *ve_spc_clk_register(struct device *cpu_dev)
{
struct clk_init_data init;
struct clk_spc *spc;
spc = kzalloc(sizeof(*spc), GFP_KERNEL);
if (!spc) {
pr_err("could not allocate spc clk\n");
return ERR_PTR(-ENOMEM);
}
spc->hw.init = &init;
spc->cluster = topology_physical_package_id(cpu_dev->id);
spc->cluster = spc->cluster < 0 ? 0 : spc->cluster;
init.name = dev_name(cpu_dev);
init.ops = &clk_spc_ops;
init.flags = CLK_GET_RATE_NOCACHE;
init.num_parents = 0;
return devm_clk_register(cpu_dev, &spc->hw);
}
static int __init ve_spc_clk_init(void)
{
int cpu;
struct clk *clk;
if (!info)
return 0;
if (ve_spc_populate_opps(0) || ve_spc_populate_opps(1)) {
pr_err("failed to build OPP table\n");
return -ENODEV;
}
for_each_possible_cpu(cpu) {
struct device *cpu_dev = get_cpu_device(cpu);
if (!cpu_dev) {
pr_warn("failed to get cpu%d device\n", cpu);
continue;
}
clk = ve_spc_clk_register(cpu_dev);
if (IS_ERR(clk)) {
pr_warn("failed to register cpu%d clock\n", cpu);
continue;
}
if (clk_register_clkdev(clk, NULL, dev_name(cpu_dev))) {
pr_warn("failed to register cpu%d clock lookup\n", cpu);
continue;
}
if (ve_init_opp_table(cpu_dev))
pr_warn("failed to initialise cpu%d opp table\n", cpu);
}
platform_device_register_simple("vexpress-spc-cpufreq", -1, NULL, 0);
return 0;
}
