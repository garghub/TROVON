struct s3c_cpufreq_config *s3c_cpufreq_getconfig(void)
{
return &cpu_cur;
}
struct s3c_iotimings *s3c_cpufreq_getiotimings(void)
{
return &s3c24xx_iotiming;
}
static void s3c_cpufreq_getcur(struct s3c_cpufreq_config *cfg)
{
unsigned long fclk, pclk, hclk, armclk;
cfg->freq.fclk = fclk = clk_get_rate(clk_fclk);
cfg->freq.hclk = hclk = clk_get_rate(clk_hclk);
cfg->freq.pclk = pclk = clk_get_rate(clk_pclk);
cfg->freq.armclk = armclk = clk_get_rate(clk_arm);
cfg->pll.driver_data = __raw_readl(S3C2410_MPLLCON);
cfg->pll.frequency = fclk;
cfg->freq.hclk_tns = 1000000000 / (cfg->freq.hclk / 10);
cfg->divs.h_divisor = fclk / hclk;
cfg->divs.p_divisor = fclk / pclk;
}
static inline void s3c_cpufreq_calc(struct s3c_cpufreq_config *cfg)
{
unsigned long pll = cfg->pll.frequency;
cfg->freq.fclk = pll;
cfg->freq.hclk = pll / cfg->divs.h_divisor;
cfg->freq.pclk = pll / cfg->divs.p_divisor;
cfg->freq.hclk_tns = 1000000000 / (cfg->freq.hclk / 10);
}
static inline int closer(unsigned int target, unsigned int n, unsigned int c)
{
int diff_cur = abs(target - c);
int diff_new = abs(target - n);
return (diff_new < diff_cur);
}
static void s3c_cpufreq_show(const char *pfx,
struct s3c_cpufreq_config *cfg)
{
s3c_freq_dbg("%s: Fvco=%u, F=%lu, A=%lu, H=%lu (%u), P=%lu (%u)\n",
pfx, cfg->pll.frequency, cfg->freq.fclk, cfg->freq.armclk,
cfg->freq.hclk, cfg->divs.h_divisor,
cfg->freq.pclk, cfg->divs.p_divisor);
}
static void s3c_cpufreq_setio(struct s3c_cpufreq_config *cfg)
{
if (cfg->info->set_iotiming)
(cfg->info->set_iotiming)(cfg, &s3c24xx_iotiming);
}
static int s3c_cpufreq_calcio(struct s3c_cpufreq_config *cfg)
{
if (cfg->info->calc_iotiming)
return (cfg->info->calc_iotiming)(cfg, &s3c24xx_iotiming);
return 0;
}
static void s3c_cpufreq_setrefresh(struct s3c_cpufreq_config *cfg)
{
(cfg->info->set_refresh)(cfg);
}
static void s3c_cpufreq_setdivs(struct s3c_cpufreq_config *cfg)
{
(cfg->info->set_divs)(cfg);
}
static int s3c_cpufreq_calcdivs(struct s3c_cpufreq_config *cfg)
{
return (cfg->info->calc_divs)(cfg);
}
static void s3c_cpufreq_setfvco(struct s3c_cpufreq_config *cfg)
{
(cfg->info->set_fvco)(cfg);
}
static inline void s3c_cpufreq_resume_clocks(void)
{
cpu_cur.info->resume_clocks();
}
static inline void s3c_cpufreq_updateclk(struct clk *clk,
unsigned int freq)
{
clk_set_rate(clk, freq);
}
static int s3c_cpufreq_settarget(struct cpufreq_policy *policy,
unsigned int target_freq,
struct cpufreq_frequency_table *pll)
{
struct s3c_cpufreq_freqs freqs;
struct s3c_cpufreq_config cpu_new;
unsigned long flags;
cpu_new = cpu_cur;
s3c_cpufreq_show("cur", &cpu_cur);
cpu_new.pll = pll ? *pll : cpu_cur.pll;
if (pll)
freqs.pll_changing = 1;
cpu_new.freq.armclk = target_freq;
cpu_new.freq.fclk = cpu_new.pll.frequency;
if (s3c_cpufreq_calcdivs(&cpu_new) < 0) {
printk(KERN_ERR "no divisors for %d\n", target_freq);
goto err_notpossible;
}
s3c_freq_dbg("%s: got divs\n", __func__);
s3c_cpufreq_calc(&cpu_new);
s3c_freq_dbg("%s: calculated frequencies for new\n", __func__);
if (cpu_new.freq.hclk != cpu_cur.freq.hclk) {
if (s3c_cpufreq_calcio(&cpu_new) < 0) {
printk(KERN_ERR "%s: no IO timings\n", __func__);
goto err_notpossible;
}
}
s3c_cpufreq_show("new", &cpu_new);
freqs.old = cpu_cur.freq;
freqs.new = cpu_new.freq;
freqs.freqs.old = cpu_cur.freq.armclk / 1000;
freqs.freqs.new = cpu_new.freq.armclk / 1000;
s3c_cpufreq_updateclk(_clk_mpll, cpu_new.pll.frequency);
s3c_cpufreq_updateclk(clk_fclk, cpu_new.freq.fclk);
s3c_cpufreq_updateclk(clk_hclk, cpu_new.freq.hclk);
s3c_cpufreq_updateclk(clk_pclk, cpu_new.freq.pclk);
cpufreq_notify_transition(policy, &freqs.freqs, CPUFREQ_PRECHANGE);
local_irq_save(flags);
if (cpu_new.freq.hclk < cpu_cur.freq.hclk) {
s3c_cpufreq_setrefresh(&cpu_new);
s3c_cpufreq_setio(&cpu_new);
}
if (cpu_new.freq.fclk == cpu_cur.freq.fclk) {
s3c_cpufreq_setdivs(&cpu_new);
} else {
if (cpu_new.freq.fclk < cpu_cur.freq.fclk) {
s3c_cpufreq_setfvco(&cpu_new);
s3c_cpufreq_setdivs(&cpu_new);
} else {
s3c_cpufreq_setdivs(&cpu_new);
s3c_cpufreq_setfvco(&cpu_new);
}
}
if (cpu_new.freq.hclk > cpu_cur.freq.hclk) {
s3c_cpufreq_setrefresh(&cpu_new);
s3c_cpufreq_setio(&cpu_new);
}
cpu_cur = cpu_new;
local_irq_restore(flags);
cpufreq_notify_transition(policy, &freqs.freqs, CPUFREQ_POSTCHANGE);
s3c_freq_dbg("%s: finished\n", __func__);
return 0;
err_notpossible:
printk(KERN_ERR "no compatible settings for %d\n", target_freq);
return -EINVAL;
}
static int s3c_cpufreq_target(struct cpufreq_policy *policy,
unsigned int target_freq,
unsigned int relation)
{
struct cpufreq_frequency_table *pll;
unsigned int index;
if (target_freq == last_target)
return 0;
last_target = target_freq;
s3c_freq_dbg("%s: policy %p, target %u, relation %u\n",
__func__, policy, target_freq, relation);
if (ftab) {
if (cpufreq_frequency_table_target(policy, ftab,
target_freq, relation,
&index)) {
s3c_freq_dbg("%s: table failed\n", __func__);
return -EINVAL;
}
s3c_freq_dbg("%s: adjust %d to entry %d (%u)\n", __func__,
target_freq, index, ftab[index].frequency);
target_freq = ftab[index].frequency;
}
target_freq *= 1000;
if (!pll_reg || cpu_cur.lock_pll) {
pll = NULL;
} else {
struct cpufreq_policy tmp_policy;
int ret;
tmp_policy.min = policy->min * 1000;
tmp_policy.max = policy->max * 1000;
tmp_policy.cpu = policy->cpu;
ret = cpufreq_frequency_table_target(&tmp_policy, pll_reg,
target_freq, relation,
&index);
if (ret < 0) {
printk(KERN_ERR "%s: no PLL available\n", __func__);
goto err_notpossible;
}
pll = pll_reg + index;
s3c_freq_dbg("%s: target %u => %u\n",
__func__, target_freq, pll->frequency);
target_freq = pll->frequency;
}
return s3c_cpufreq_settarget(policy, target_freq, pll);
err_notpossible:
printk(KERN_ERR "no compatible settings for %d\n", target_freq);
return -EINVAL;
}
struct clk *s3c_cpufreq_clk_get(struct device *dev, const char *name)
{
struct clk *clk;
clk = clk_get(dev, name);
if (IS_ERR(clk))
printk(KERN_ERR "cpufreq: failed to get clock '%s'\n", name);
return clk;
}
static int s3c_cpufreq_init(struct cpufreq_policy *policy)
{
policy->clk = clk_arm;
return cpufreq_generic_init(policy, ftab, cpu_cur.info->latency);
}
static int __init s3c_cpufreq_initclks(void)
{
_clk_mpll = s3c_cpufreq_clk_get(NULL, "mpll");
_clk_xtal = s3c_cpufreq_clk_get(NULL, "xtal");
clk_fclk = s3c_cpufreq_clk_get(NULL, "fclk");
clk_hclk = s3c_cpufreq_clk_get(NULL, "hclk");
clk_pclk = s3c_cpufreq_clk_get(NULL, "pclk");
clk_arm = s3c_cpufreq_clk_get(NULL, "armclk");
if (IS_ERR(clk_fclk) || IS_ERR(clk_hclk) || IS_ERR(clk_pclk) ||
IS_ERR(_clk_mpll) || IS_ERR(clk_arm) || IS_ERR(_clk_xtal)) {
printk(KERN_ERR "%s: could not get clock(s)\n", __func__);
return -ENOENT;
}
printk(KERN_INFO "%s: clocks f=%lu,h=%lu,p=%lu,a=%lu\n", __func__,
clk_get_rate(clk_fclk) / 1000,
clk_get_rate(clk_hclk) / 1000,
clk_get_rate(clk_pclk) / 1000,
clk_get_rate(clk_arm) / 1000);
return 0;
}
static int s3c_cpufreq_suspend(struct cpufreq_policy *policy)
{
suspend_pll.frequency = clk_get_rate(_clk_mpll);
suspend_pll.driver_data = __raw_readl(S3C2410_MPLLCON);
suspend_freq = clk_get_rate(clk_arm);
return 0;
}
static int s3c_cpufreq_resume(struct cpufreq_policy *policy)
{
int ret;
s3c_freq_dbg("%s: resuming with policy %p\n", __func__, policy);
last_target = ~0;
s3c_cpufreq_resume_clocks();
ret = s3c_cpufreq_settarget(NULL, suspend_freq, &suspend_pll);
if (ret) {
printk(KERN_ERR "%s: failed to reset pll/freq\n", __func__);
return ret;
}
return 0;
}
int __init s3c_cpufreq_register(struct s3c_cpufreq_info *info)
{
if (!info || !info->name) {
printk(KERN_ERR "%s: failed to pass valid information\n",
__func__);
return -EINVAL;
}
printk(KERN_INFO "S3C24XX CPU Frequency driver, %s cpu support\n",
info->name);
BUG_ON(info->set_refresh == NULL);
BUG_ON(info->set_divs == NULL);
BUG_ON(info->calc_divs == NULL);
cpu_cur.info = info;
return 0;
}
int __init s3c_cpufreq_setboard(struct s3c_cpufreq_board *board)
{
struct s3c_cpufreq_board *ours;
if (!board) {
printk(KERN_INFO "%s: no board data\n", __func__);
return -EINVAL;
}
ours = kzalloc(sizeof(*ours), GFP_KERNEL);
if (ours == NULL) {
printk(KERN_ERR "%s: no memory\n", __func__);
return -ENOMEM;
}
*ours = *board;
cpu_cur.board = ours;
return 0;
}
static int __init s3c_cpufreq_auto_io(void)
{
int ret;
if (!cpu_cur.info->get_iotiming) {
printk(KERN_ERR "%s: get_iotiming undefined\n", __func__);
return -ENOENT;
}
printk(KERN_INFO "%s: working out IO settings\n", __func__);
ret = (cpu_cur.info->get_iotiming)(&cpu_cur, &s3c24xx_iotiming);
if (ret)
printk(KERN_ERR "%s: failed to get timings\n", __func__);
return ret;
}
static void s3c_cpufreq_freq_min(struct s3c_freq *dst,
struct s3c_freq *a, struct s3c_freq *b)
{
dst->fclk = do_min(a->fclk, b->fclk);
dst->hclk = do_min(a->hclk, b->hclk);
dst->pclk = do_min(a->pclk, b->pclk);
dst->armclk = do_min(a->armclk, b->armclk);
}
static inline u32 calc_locktime(u32 freq, u32 time_us)
{
u32 result;
result = freq * time_us;
result = DIV_ROUND_UP(result, 1000 * 1000);
return result;
}
static void s3c_cpufreq_update_loctkime(void)
{
unsigned int bits = cpu_cur.info->locktime_bits;
u32 rate = (u32)clk_get_rate(_clk_xtal);
u32 val;
if (bits == 0) {
WARN_ON(1);
return;
}
val = calc_locktime(rate, cpu_cur.info->locktime_u) << bits;
val |= calc_locktime(rate, cpu_cur.info->locktime_m);
printk(KERN_INFO "%s: new locktime is 0x%08x\n", __func__, val);
__raw_writel(val, S3C2410_LOCKTIME);
}
static int s3c_cpufreq_build_freq(void)
{
int size, ret;
if (!cpu_cur.info->calc_freqtable)
return -EINVAL;
kfree(ftab);
ftab = NULL;
size = cpu_cur.info->calc_freqtable(&cpu_cur, NULL, 0);
size++;
ftab = kmalloc(sizeof(*ftab) * size, GFP_KERNEL);
if (!ftab) {
printk(KERN_ERR "%s: no memory for tables\n", __func__);
return -ENOMEM;
}
ftab_size = size;
ret = cpu_cur.info->calc_freqtable(&cpu_cur, ftab, size);
s3c_cpufreq_addfreq(ftab, ret, size, CPUFREQ_TABLE_END);
return 0;
}
static int __init s3c_cpufreq_initcall(void)
{
int ret = 0;
if (cpu_cur.info && cpu_cur.board) {
ret = s3c_cpufreq_initclks();
if (ret)
goto out;
s3c_cpufreq_getcur(&cpu_cur);
s3c_cpufreq_show("cur", &cpu_cur);
if (cpu_cur.board->auto_io) {
ret = s3c_cpufreq_auto_io();
if (ret) {
printk(KERN_ERR "%s: failed to get io timing\n",
__func__);
goto out;
}
}
if (cpu_cur.board->need_io && !cpu_cur.info->set_iotiming) {
printk(KERN_ERR "%s: no IO support registered\n",
__func__);
ret = -EINVAL;
goto out;
}
if (!cpu_cur.info->need_pll)
cpu_cur.lock_pll = 1;
s3c_cpufreq_update_loctkime();
s3c_cpufreq_freq_min(&cpu_cur.max, &cpu_cur.board->max,
&cpu_cur.info->max);
if (cpu_cur.info->calc_freqtable)
s3c_cpufreq_build_freq();
ret = cpufreq_register_driver(&s3c24xx_driver);
}
out:
return ret;
}
int __init s3c_plltab_register(struct cpufreq_frequency_table *plls,
unsigned int plls_no)
{
struct cpufreq_frequency_table *vals;
unsigned int size;
size = sizeof(*vals) * (plls_no + 1);
vals = kmalloc(size, GFP_KERNEL);
if (vals) {
memcpy(vals, plls, size);
pll_reg = vals;
vals += plls_no;
vals->frequency = CPUFREQ_TABLE_END;
printk(KERN_INFO "cpufreq: %d PLL entries\n", plls_no);
} else
printk(KERN_ERR "cpufreq: no memory for PLL tables\n");
return vals ? 0 : -ENOMEM;
}
