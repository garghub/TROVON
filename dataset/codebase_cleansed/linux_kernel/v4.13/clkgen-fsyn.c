static int quadfs_pll_enable(struct clk_hw *hw)
{
struct st_clk_quadfs_pll *pll = to_quadfs_pll(hw);
unsigned long flags = 0, timeout = jiffies + msecs_to_jiffies(10);
if (pll->lock)
spin_lock_irqsave(pll->lock, flags);
if (pll->data->reset_present)
CLKGEN_WRITE(pll, nreset, 1);
if (pll->data->bwfilter_present)
CLKGEN_WRITE(pll, ref_bw, PLL_BW_GOODREF);
CLKGEN_WRITE(pll, ndiv, pll->ndiv);
CLKGEN_WRITE(pll, npda, !pll->data->powerup_polarity);
if (pll->lock)
spin_unlock_irqrestore(pll->lock, flags);
if (pll->data->lockstatus_present)
while (!CLKGEN_READ(pll, lock_status)) {
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
cpu_relax();
}
return 0;
}
static void quadfs_pll_disable(struct clk_hw *hw)
{
struct st_clk_quadfs_pll *pll = to_quadfs_pll(hw);
unsigned long flags = 0;
if (pll->lock)
spin_lock_irqsave(pll->lock, flags);
CLKGEN_WRITE(pll, npda, pll->data->powerup_polarity);
if (pll->data->reset_present)
CLKGEN_WRITE(pll, nreset, 0);
if (pll->lock)
spin_unlock_irqrestore(pll->lock, flags);
}
static int quadfs_pll_is_enabled(struct clk_hw *hw)
{
struct st_clk_quadfs_pll *pll = to_quadfs_pll(hw);
u32 npda = CLKGEN_READ(pll, npda);
return pll->data->powerup_polarity ? !npda : !!npda;
}
static int clk_fs660c32_vco_get_rate(unsigned long input, struct stm_fs *fs,
unsigned long *rate)
{
unsigned long nd = fs->ndiv + 16;
*rate = input * nd;
return 0;
}
static unsigned long quadfs_pll_fs660c32_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct st_clk_quadfs_pll *pll = to_quadfs_pll(hw);
unsigned long rate = 0;
struct stm_fs params;
params.ndiv = CLKGEN_READ(pll, ndiv);
if (clk_fs660c32_vco_get_rate(parent_rate, &params, &rate))
pr_err("%s:%s error calculating rate\n",
clk_hw_get_name(hw), __func__);
pll->ndiv = params.ndiv;
return rate;
}
static int clk_fs660c32_vco_get_params(unsigned long input,
unsigned long output, struct stm_fs *fs)
{
unsigned long pdiv = 1, n;
if (output < 384000000 || output > 660000000)
return -EINVAL;
if (input > 40000000)
return -EINVAL;
input /= 1000;
output /= 1000;
n = output * pdiv / input;
if (n < 16)
n = 16;
fs->ndiv = n - 16;
return 0;
}
static long quadfs_pll_fs660c32_round_rate(struct clk_hw *hw,
unsigned long rate,
unsigned long *prate)
{
struct stm_fs params;
if (clk_fs660c32_vco_get_params(*prate, rate, &params))
return rate;
clk_fs660c32_vco_get_rate(*prate, &params, &rate);
pr_debug("%s: %s new rate %ld [ndiv=%u]\n",
__func__, clk_hw_get_name(hw),
rate, (unsigned int)params.ndiv);
return rate;
}
static int quadfs_pll_fs660c32_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct st_clk_quadfs_pll *pll = to_quadfs_pll(hw);
struct stm_fs params;
long hwrate = 0;
unsigned long flags = 0;
int ret;
if (!rate || !parent_rate)
return -EINVAL;
ret = clk_fs660c32_vco_get_params(parent_rate, rate, &params);
if (ret)
return ret;
clk_fs660c32_vco_get_rate(parent_rate, &params, &hwrate);
pr_debug("%s: %s new rate %ld [ndiv=0x%x]\n",
__func__, clk_hw_get_name(hw),
hwrate, (unsigned int)params.ndiv);
if (!hwrate)
return -EINVAL;
pll->ndiv = params.ndiv;
if (pll->lock)
spin_lock_irqsave(pll->lock, flags);
CLKGEN_WRITE(pll, ndiv, pll->ndiv);
if (pll->lock)
spin_unlock_irqrestore(pll->lock, flags);
return 0;
}
static struct clk * __init st_clk_register_quadfs_pll(
const char *name, const char *parent_name,
struct clkgen_quadfs_data *quadfs, void __iomem *reg,
spinlock_t *lock)
{
struct st_clk_quadfs_pll *pll;
struct clk *clk;
struct clk_init_data init;
if (WARN_ON(!name || !parent_name))
return ERR_PTR(-EINVAL);
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = quadfs->pll_ops;
init.flags = CLK_IS_BASIC | CLK_GET_RATE_NOCACHE;
init.parent_names = &parent_name;
init.num_parents = 1;
pll->data = quadfs;
pll->regs_base = reg;
pll->lock = lock;
pll->hw.init = &init;
clk = clk_register(NULL, &pll->hw);
if (IS_ERR(clk))
kfree(pll);
return clk;
}
static void quadfs_fsynth_program_enable(struct st_clk_quadfs_fsynth *fs)
{
CLKGEN_WRITE(fs, en[fs->chan], 1);
CLKGEN_WRITE(fs, en[fs->chan], 0);
}
static void quadfs_fsynth_program_rate(struct st_clk_quadfs_fsynth *fs)
{
unsigned long flags = 0;
CLKGEN_WRITE(fs, en[fs->chan], 0);
CLKGEN_WRITE(fs, mdiv[fs->chan], fs->md);
CLKGEN_WRITE(fs, pe[fs->chan], fs->pe);
CLKGEN_WRITE(fs, sdiv[fs->chan], fs->sdiv);
if (fs->lock)
spin_lock_irqsave(fs->lock, flags);
if (fs->data->nsdiv_present)
CLKGEN_WRITE(fs, nsdiv[fs->chan], fs->nsdiv);
if (fs->lock)
spin_unlock_irqrestore(fs->lock, flags);
}
static int quadfs_fsynth_enable(struct clk_hw *hw)
{
struct st_clk_quadfs_fsynth *fs = to_quadfs_fsynth(hw);
unsigned long flags = 0;
pr_debug("%s: %s\n", __func__, clk_hw_get_name(hw));
quadfs_fsynth_program_rate(fs);
if (fs->lock)
spin_lock_irqsave(fs->lock, flags);
CLKGEN_WRITE(fs, nsb[fs->chan], !fs->data->standby_polarity);
if (fs->data->nrst_present)
CLKGEN_WRITE(fs, nrst[fs->chan], 0);
if (fs->lock)
spin_unlock_irqrestore(fs->lock, flags);
quadfs_fsynth_program_enable(fs);
return 0;
}
static void quadfs_fsynth_disable(struct clk_hw *hw)
{
struct st_clk_quadfs_fsynth *fs = to_quadfs_fsynth(hw);
unsigned long flags = 0;
pr_debug("%s: %s\n", __func__, clk_hw_get_name(hw));
if (fs->lock)
spin_lock_irqsave(fs->lock, flags);
CLKGEN_WRITE(fs, nsb[fs->chan], fs->data->standby_polarity);
if (fs->lock)
spin_unlock_irqrestore(fs->lock, flags);
}
static int quadfs_fsynth_is_enabled(struct clk_hw *hw)
{
struct st_clk_quadfs_fsynth *fs = to_quadfs_fsynth(hw);
u32 nsb = CLKGEN_READ(fs, nsb[fs->chan]);
pr_debug("%s: %s enable bit = 0x%x\n",
__func__, clk_hw_get_name(hw), nsb);
return fs->data->standby_polarity ? !nsb : !!nsb;
}
static int clk_fs660c32_dig_get_rate(unsigned long input,
const struct stm_fs *fs, unsigned long *rate)
{
unsigned long s = (1 << fs->sdiv);
unsigned long ns;
uint64_t res;
ns = (fs->nsdiv == 1) ? 1 : 3;
res = (P20 * (32 + fs->mdiv) + 32 * fs->pe) * s * ns;
*rate = (unsigned long)div64_u64(input * P20 * 32, res);
return 0;
}
static int clk_fs660c32_get_pe(int m, int si, unsigned long *deviation,
signed long input, unsigned long output, uint64_t *p,
struct stm_fs *fs)
{
unsigned long new_freq, new_deviation;
struct stm_fs fs_tmp;
uint64_t val;
val = (uint64_t)output << si;
*p = (uint64_t)input * P20 - (32LL + (uint64_t)m) * val * (P20 / 32LL);
*p = div64_u64(*p, val);
if (*p > 32767LL)
return 1;
fs_tmp.mdiv = (unsigned long) m;
fs_tmp.pe = (unsigned long)*p;
fs_tmp.sdiv = si;
fs_tmp.nsdiv = 1;
clk_fs660c32_dig_get_rate(input, &fs_tmp, &new_freq);
new_deviation = abs(output - new_freq);
if (new_deviation < *deviation) {
fs->mdiv = m;
fs->pe = (unsigned long)*p;
fs->sdiv = si;
fs->nsdiv = 1;
*deviation = new_deviation;
}
return 0;
}
static int clk_fs660c32_dig_get_params(unsigned long input,
unsigned long output, struct stm_fs *fs)
{
int si;
int m;
unsigned long new_freq, new_deviation;
unsigned long deviation = ~0;
uint64_t p, p1, p2;
int r1, r2;
struct stm_fs fs_tmp;
for (si = 0; (si <= 8) && deviation; si++) {
r1 = clk_fs660c32_get_pe(0, si, &deviation,
input, output, &p1, fs);
r2 = clk_fs660c32_get_pe(31, si, &deviation,
input, output, &p2, fs);
if (r1 && r2 && (p1 > p2))
continue;
for (m = 1; (m < 31) && deviation; m++)
clk_fs660c32_get_pe(m, si, &deviation,
input, output, &p, fs);
}
if (deviation == ~0)
return -1;
if (deviation) {
fs_tmp.mdiv = fs->mdiv;
fs_tmp.sdiv = fs->sdiv;
fs_tmp.nsdiv = fs->nsdiv;
if (fs->pe > 2)
p2 = fs->pe - 2;
else
p2 = 0;
for (; p2 < 32768ll && (p2 <= (fs->pe + 2)); p2++) {
fs_tmp.pe = (unsigned long)p2;
clk_fs660c32_dig_get_rate(input, &fs_tmp, &new_freq);
new_deviation = abs(output - new_freq);
if (new_deviation < deviation) {
fs->pe = (unsigned long)p2;
deviation = new_deviation;
}
}
}
return 0;
}
static int quadfs_fsynt_get_hw_value_for_recalc(struct st_clk_quadfs_fsynth *fs,
struct stm_fs *params)
{
params->mdiv = CLKGEN_READ(fs, mdiv[fs->chan]);
params->pe = CLKGEN_READ(fs, pe[fs->chan]);
params->sdiv = CLKGEN_READ(fs, sdiv[fs->chan]);
if (fs->data->nsdiv_present)
params->nsdiv = CLKGEN_READ(fs, nsdiv[fs->chan]);
else
params->nsdiv = 1;
if (!params->mdiv && !params->pe && !params->sdiv)
return 1;
fs->md = params->mdiv;
fs->pe = params->pe;
fs->sdiv = params->sdiv;
fs->nsdiv = params->nsdiv;
return 0;
}
static long quadfs_find_best_rate(struct clk_hw *hw, unsigned long drate,
unsigned long prate, struct stm_fs *params)
{
struct st_clk_quadfs_fsynth *fs = to_quadfs_fsynth(hw);
int (*clk_fs_get_rate)(unsigned long ,
const struct stm_fs *, unsigned long *);
int (*clk_fs_get_params)(unsigned long, unsigned long, struct stm_fs *);
unsigned long rate = 0;
clk_fs_get_rate = fs->data->get_rate;
clk_fs_get_params = fs->data->get_params;
if (!clk_fs_get_params(prate, drate, params))
clk_fs_get_rate(prate, params, &rate);
return rate;
}
static unsigned long quadfs_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct st_clk_quadfs_fsynth *fs = to_quadfs_fsynth(hw);
unsigned long rate = 0;
struct stm_fs params;
int (*clk_fs_get_rate)(unsigned long ,
const struct stm_fs *, unsigned long *);
clk_fs_get_rate = fs->data->get_rate;
if (quadfs_fsynt_get_hw_value_for_recalc(fs, &params))
return 0;
if (clk_fs_get_rate(parent_rate, &params, &rate)) {
pr_err("%s:%s error calculating rate\n",
clk_hw_get_name(hw), __func__);
}
pr_debug("%s:%s rate %lu\n", clk_hw_get_name(hw), __func__, rate);
return rate;
}
static long quadfs_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct stm_fs params;
rate = quadfs_find_best_rate(hw, rate, *prate, &params);
pr_debug("%s: %s new rate %ld [sdiv=0x%x,md=0x%x,pe=0x%x,nsdiv3=%u]\n",
__func__, clk_hw_get_name(hw),
rate, (unsigned int)params.sdiv, (unsigned int)params.mdiv,
(unsigned int)params.pe, (unsigned int)params.nsdiv);
return rate;
}
static void quadfs_program_and_enable(struct st_clk_quadfs_fsynth *fs,
struct stm_fs *params)
{
fs->md = params->mdiv;
fs->pe = params->pe;
fs->sdiv = params->sdiv;
fs->nsdiv = params->nsdiv;
quadfs_fsynth_program_rate(fs);
quadfs_fsynth_program_enable(fs);
}
static int quadfs_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct st_clk_quadfs_fsynth *fs = to_quadfs_fsynth(hw);
struct stm_fs params;
long hwrate;
int uninitialized_var(i);
if (!rate || !parent_rate)
return -EINVAL;
memset(&params, 0, sizeof(struct stm_fs));
hwrate = quadfs_find_best_rate(hw, rate, parent_rate, &params);
if (!hwrate)
return -EINVAL;
quadfs_program_and_enable(fs, &params);
return 0;
}
static struct clk * __init st_clk_register_quadfs_fsynth(
const char *name, const char *parent_name,
struct clkgen_quadfs_data *quadfs, void __iomem *reg, u32 chan,
unsigned long flags, spinlock_t *lock)
{
struct st_clk_quadfs_fsynth *fs;
struct clk *clk;
struct clk_init_data init;
if (WARN_ON(!name || !parent_name))
return ERR_PTR(-EINVAL);
fs = kzalloc(sizeof(*fs), GFP_KERNEL);
if (!fs)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &st_quadfs_ops;
init.flags = flags | CLK_GET_RATE_NOCACHE | CLK_IS_BASIC;
init.parent_names = &parent_name;
init.num_parents = 1;
fs->data = quadfs;
fs->regs_base = reg;
fs->chan = chan;
fs->lock = lock;
fs->hw.init = &init;
clk = clk_register(NULL, &fs->hw);
if (IS_ERR(clk))
kfree(fs);
return clk;
}
static void __init st_of_create_quadfs_fsynths(
struct device_node *np, const char *pll_name,
struct clkgen_quadfs_data *quadfs, void __iomem *reg,
spinlock_t *lock)
{
struct clk_onecell_data *clk_data;
int fschan;
clk_data = kzalloc(sizeof(*clk_data), GFP_KERNEL);
if (!clk_data)
return;
clk_data->clk_num = QUADFS_MAX_CHAN;
clk_data->clks = kzalloc(QUADFS_MAX_CHAN * sizeof(struct clk *),
GFP_KERNEL);
if (!clk_data->clks) {
kfree(clk_data);
return;
}
for (fschan = 0; fschan < QUADFS_MAX_CHAN; fschan++) {
struct clk *clk;
const char *clk_name;
unsigned long flags = 0;
if (of_property_read_string_index(np, "clock-output-names",
fschan, &clk_name)) {
break;
}
if (*clk_name == '\0')
continue;
of_clk_detect_critical(np, fschan, &flags);
clk = st_clk_register_quadfs_fsynth(clk_name, pll_name,
quadfs, reg, fschan,
flags, lock);
if (!IS_ERR(clk)) {
clk_data->clks[fschan] = clk;
pr_debug("%s: parent %s rate %u\n",
__clk_get_name(clk),
__clk_get_name(clk_get_parent(clk)),
(unsigned int)clk_get_rate(clk));
}
}
of_clk_add_provider(np, of_clk_src_onecell_get, clk_data);
}
static void __init st_of_quadfs_setup(struct device_node *np,
struct clkgen_quadfs_data *data)
{
struct clk *clk;
const char *pll_name, *clk_parent_name;
void __iomem *reg;
spinlock_t *lock;
reg = of_iomap(np, 0);
if (!reg)
return;
clk_parent_name = of_clk_get_parent_name(np, 0);
if (!clk_parent_name)
return;
pll_name = kasprintf(GFP_KERNEL, "%s.pll", np->name);
if (!pll_name)
return;
lock = kzalloc(sizeof(*lock), GFP_KERNEL);
if (!lock)
goto err_exit;
spin_lock_init(lock);
clk = st_clk_register_quadfs_pll(pll_name, clk_parent_name, data,
reg, lock);
if (IS_ERR(clk))
goto err_exit;
else
pr_debug("%s: parent %s rate %u\n",
__clk_get_name(clk),
__clk_get_name(clk_get_parent(clk)),
(unsigned int)clk_get_rate(clk));
st_of_create_quadfs_fsynths(np, pll_name, data, reg, lock);
err_exit:
kfree(pll_name);
}
static void __init st_of_quadfs660C_setup(struct device_node *np)
{
st_of_quadfs_setup(np, (struct clkgen_quadfs_data *) &st_fs660c32_C);
}
static void __init st_of_quadfs660D_setup(struct device_node *np)
{
st_of_quadfs_setup(np, (struct clkgen_quadfs_data *) &st_fs660c32_D);
}
