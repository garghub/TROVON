static inline u32 dfll_readl(struct tegra_dfll *td, u32 offs)
{
return __raw_readl(td->base + offs);
}
static inline void dfll_writel(struct tegra_dfll *td, u32 val, u32 offs)
{
WARN_ON(offs >= DFLL_I2C_CFG);
__raw_writel(val, td->base + offs);
}
static inline void dfll_wmb(struct tegra_dfll *td)
{
dfll_readl(td, DFLL_CTRL);
}
static inline u32 dfll_i2c_readl(struct tegra_dfll *td, u32 offs)
{
return __raw_readl(td->i2c_base + offs);
}
static inline void dfll_i2c_writel(struct tegra_dfll *td, u32 val, u32 offs)
{
__raw_writel(val, td->i2c_base + offs);
}
static inline void dfll_i2c_wmb(struct tegra_dfll *td)
{
dfll_i2c_readl(td, DFLL_I2C_CFG);
}
static bool dfll_is_running(struct tegra_dfll *td)
{
return td->mode >= DFLL_OPEN_LOOP;
}
int tegra_dfll_runtime_resume(struct device *dev)
{
struct tegra_dfll *td = dev_get_drvdata(dev);
int ret;
ret = clk_enable(td->ref_clk);
if (ret) {
dev_err(dev, "could not enable ref clock: %d\n", ret);
return ret;
}
ret = clk_enable(td->soc_clk);
if (ret) {
dev_err(dev, "could not enable register clock: %d\n", ret);
clk_disable(td->ref_clk);
return ret;
}
ret = clk_enable(td->i2c_clk);
if (ret) {
dev_err(dev, "could not enable i2c clock: %d\n", ret);
clk_disable(td->soc_clk);
clk_disable(td->ref_clk);
return ret;
}
return 0;
}
int tegra_dfll_runtime_suspend(struct device *dev)
{
struct tegra_dfll *td = dev_get_drvdata(dev);
clk_disable(td->ref_clk);
clk_disable(td->soc_clk);
clk_disable(td->i2c_clk);
return 0;
}
static void dfll_tune_low(struct tegra_dfll *td)
{
td->tune_range = DFLL_TUNE_LOW;
dfll_writel(td, td->soc->tune0_low, DFLL_TUNE0);
dfll_writel(td, td->soc->tune1, DFLL_TUNE1);
dfll_wmb(td);
if (td->soc->set_clock_trimmers_low)
td->soc->set_clock_trimmers_low();
}
static unsigned long dfll_scale_dvco_rate(int scale_bits,
unsigned long dvco_rate)
{
return (u64)dvco_rate * (scale_bits + 1) / DFLL_FREQ_REQ_SCALE_MAX;
}
static u64 dfll_calc_monitored_rate(u32 monitor_data,
unsigned long ref_rate)
{
return monitor_data * (ref_rate / REF_CLK_CYC_PER_DVCO_SAMPLE);
}
static u64 dfll_read_monitor_rate(struct tegra_dfll *td)
{
u32 v, s;
u64 pre_scaler_rate, post_scaler_rate;
if (!dfll_is_running(td))
return 0;
v = dfll_readl(td, DFLL_MONITOR_DATA);
v = (v & DFLL_MONITOR_DATA_VAL_MASK) >> DFLL_MONITOR_DATA_VAL_SHIFT;
pre_scaler_rate = dfll_calc_monitored_rate(v, td->ref_rate);
s = dfll_readl(td, DFLL_FREQ_REQ);
s = (s & DFLL_FREQ_REQ_SCALE_MASK) >> DFLL_FREQ_REQ_SCALE_SHIFT;
post_scaler_rate = dfll_scale_dvco_rate(s, pre_scaler_rate);
return post_scaler_rate;
}
static void dfll_set_mode(struct tegra_dfll *td,
enum dfll_ctrl_mode mode)
{
td->mode = mode;
dfll_writel(td, mode - 1, DFLL_CTRL);
dfll_wmb(td);
}
static int dfll_i2c_set_output_enabled(struct tegra_dfll *td, bool enable)
{
u32 val;
val = dfll_i2c_readl(td, DFLL_OUTPUT_CFG);
if (enable)
val |= DFLL_OUTPUT_CFG_I2C_ENABLE;
else
val &= ~DFLL_OUTPUT_CFG_I2C_ENABLE;
dfll_i2c_writel(td, val, DFLL_OUTPUT_CFG);
dfll_i2c_wmb(td);
return 0;
}
static void dfll_load_i2c_lut(struct tegra_dfll *td)
{
int i, lut_index;
u32 val;
for (i = 0; i < MAX_DFLL_VOLTAGES; i++) {
if (i < td->lut_min)
lut_index = td->lut_min;
else if (i > td->lut_max)
lut_index = td->lut_max;
else
lut_index = i;
val = regulator_list_hardware_vsel(td->vdd_reg,
td->i2c_lut[lut_index]);
__raw_writel(val, td->lut_base + i * 4);
}
dfll_i2c_wmb(td);
}
static void dfll_init_i2c_if(struct tegra_dfll *td)
{
u32 val;
if (td->i2c_slave_addr > 0x7f) {
val = td->i2c_slave_addr << DFLL_I2C_CFG_SLAVE_ADDR_SHIFT_10BIT;
val |= DFLL_I2C_CFG_SLAVE_ADDR_10;
} else {
val = td->i2c_slave_addr << DFLL_I2C_CFG_SLAVE_ADDR_SHIFT_7BIT;
}
val |= DFLL_I2C_CFG_SIZE_MASK;
val |= DFLL_I2C_CFG_ARB_ENABLE;
dfll_i2c_writel(td, val, DFLL_I2C_CFG);
dfll_i2c_writel(td, td->i2c_reg, DFLL_I2C_VDD_REG_ADDR);
val = DIV_ROUND_UP(td->i2c_clk_rate, td->i2c_fs_rate * 8);
BUG_ON(!val || (val > DFLL_I2C_CLK_DIVISOR_MASK));
val = (val - 1) << DFLL_I2C_CLK_DIVISOR_FS_SHIFT;
val |= 1 << DFLL_I2C_CLK_DIVISOR_HS_SHIFT;
__raw_writel(val, td->i2c_controller_base + DFLL_I2C_CLK_DIVISOR);
dfll_i2c_wmb(td);
}
static void dfll_init_out_if(struct tegra_dfll *td)
{
u32 val;
td->lut_min = 0;
td->lut_max = td->i2c_lut_size - 1;
td->lut_safe = td->lut_min + 1;
dfll_i2c_writel(td, 0, DFLL_OUTPUT_CFG);
val = (td->lut_safe << DFLL_OUTPUT_CFG_SAFE_SHIFT) |
(td->lut_max << DFLL_OUTPUT_CFG_MAX_SHIFT) |
(td->lut_min << DFLL_OUTPUT_CFG_MIN_SHIFT);
dfll_i2c_writel(td, val, DFLL_OUTPUT_CFG);
dfll_i2c_wmb(td);
dfll_writel(td, 0, DFLL_OUTPUT_FORCE);
dfll_i2c_writel(td, 0, DFLL_INTR_EN);
dfll_i2c_writel(td, DFLL_INTR_MAX_MASK | DFLL_INTR_MIN_MASK,
DFLL_INTR_STS);
dfll_load_i2c_lut(td);
dfll_init_i2c_if(td);
}
static int find_lut_index_for_rate(struct tegra_dfll *td, unsigned long rate)
{
struct dev_pm_opp *opp;
int i, uv;
rcu_read_lock();
opp = dev_pm_opp_find_freq_ceil(td->soc->dev, &rate);
if (IS_ERR(opp)) {
rcu_read_unlock();
return PTR_ERR(opp);
}
uv = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
for (i = 0; i < td->i2c_lut_size; i++) {
if (regulator_list_voltage(td->vdd_reg, td->i2c_lut[i]) == uv)
return i;
}
return -ENOENT;
}
static int dfll_calculate_rate_request(struct tegra_dfll *td,
struct dfll_rate_req *req,
unsigned long rate)
{
u32 val;
req->scale_bits = DFLL_FREQ_REQ_SCALE_MAX - 1;
if (rate < td->dvco_rate_min) {
int scale;
scale = DIV_ROUND_CLOSEST(rate / 1000 * DFLL_FREQ_REQ_SCALE_MAX,
td->dvco_rate_min / 1000);
if (!scale) {
dev_err(td->dev, "%s: Rate %lu is too low\n",
__func__, rate);
return -EINVAL;
}
req->scale_bits = scale - 1;
rate = td->dvco_rate_min;
}
val = DVCO_RATE_TO_MULT(rate, td->ref_rate);
if (val > FREQ_MAX) {
dev_err(td->dev, "%s: Rate %lu is above dfll range\n",
__func__, rate);
return -EINVAL;
}
req->mult_bits = val;
req->dvco_target_rate = MULT_TO_DVCO_RATE(req->mult_bits, td->ref_rate);
req->rate = dfll_scale_dvco_rate(req->scale_bits,
req->dvco_target_rate);
req->lut_index = find_lut_index_for_rate(td, req->dvco_target_rate);
if (req->lut_index < 0)
return req->lut_index;
return 0;
}
static void dfll_set_frequency_request(struct tegra_dfll *td,
struct dfll_rate_req *req)
{
u32 val = 0;
int force_val;
int coef = 128; ;
force_val = (req->lut_index - td->lut_safe) * coef / td->cg;
force_val = clamp(force_val, FORCE_MIN, FORCE_MAX);
val |= req->mult_bits << DFLL_FREQ_REQ_MULT_SHIFT;
val |= req->scale_bits << DFLL_FREQ_REQ_SCALE_SHIFT;
val |= ((u32)force_val << DFLL_FREQ_REQ_FORCE_SHIFT) &
DFLL_FREQ_REQ_FORCE_MASK;
val |= DFLL_FREQ_REQ_FREQ_VALID | DFLL_FREQ_REQ_FORCE_ENABLE;
dfll_writel(td, val, DFLL_FREQ_REQ);
dfll_wmb(td);
}
static int dfll_request_rate(struct tegra_dfll *td, unsigned long rate)
{
int ret;
struct dfll_rate_req req;
if (td->mode == DFLL_UNINITIALIZED) {
dev_err(td->dev, "%s: Cannot set DFLL rate in %s mode\n",
__func__, mode_name[td->mode]);
return -EPERM;
}
ret = dfll_calculate_rate_request(td, &req, rate);
if (ret)
return ret;
td->last_unrounded_rate = rate;
td->last_req = req;
if (td->mode == DFLL_CLOSED_LOOP)
dfll_set_frequency_request(td, &td->last_req);
return 0;
}
static int dfll_disable(struct tegra_dfll *td)
{
if (td->mode != DFLL_OPEN_LOOP) {
dev_err(td->dev, "cannot disable DFLL in %s mode\n",
mode_name[td->mode]);
return -EINVAL;
}
dfll_set_mode(td, DFLL_DISABLED);
pm_runtime_put_sync(td->dev);
return 0;
}
static int dfll_enable(struct tegra_dfll *td)
{
if (td->mode != DFLL_DISABLED) {
dev_err(td->dev, "cannot enable DFLL in %s mode\n",
mode_name[td->mode]);
return -EPERM;
}
pm_runtime_get_sync(td->dev);
dfll_set_mode(td, DFLL_OPEN_LOOP);
return 0;
}
static void dfll_set_open_loop_config(struct tegra_dfll *td)
{
u32 val;
if (td->tune_range != DFLL_TUNE_LOW)
dfll_tune_low(td);
val = dfll_readl(td, DFLL_FREQ_REQ);
val |= DFLL_FREQ_REQ_SCALE_MASK;
val &= ~DFLL_FREQ_REQ_FORCE_ENABLE;
dfll_writel(td, val, DFLL_FREQ_REQ);
dfll_wmb(td);
}
static int dfll_lock(struct tegra_dfll *td)
{
struct dfll_rate_req *req = &td->last_req;
switch (td->mode) {
case DFLL_CLOSED_LOOP:
return 0;
case DFLL_OPEN_LOOP:
if (req->rate == 0) {
dev_err(td->dev, "%s: Cannot lock DFLL at rate 0\n",
__func__);
return -EINVAL;
}
dfll_i2c_set_output_enabled(td, true);
dfll_set_mode(td, DFLL_CLOSED_LOOP);
dfll_set_frequency_request(td, req);
return 0;
default:
BUG_ON(td->mode > DFLL_CLOSED_LOOP);
dev_err(td->dev, "%s: Cannot lock DFLL in %s mode\n",
__func__, mode_name[td->mode]);
return -EPERM;
}
}
static int dfll_unlock(struct tegra_dfll *td)
{
switch (td->mode) {
case DFLL_CLOSED_LOOP:
dfll_set_open_loop_config(td);
dfll_set_mode(td, DFLL_OPEN_LOOP);
dfll_i2c_set_output_enabled(td, false);
return 0;
case DFLL_OPEN_LOOP:
return 0;
default:
BUG_ON(td->mode > DFLL_CLOSED_LOOP);
dev_err(td->dev, "%s: Cannot unlock DFLL in %s mode\n",
__func__, mode_name[td->mode]);
return -EPERM;
}
}
static int dfll_clk_is_enabled(struct clk_hw *hw)
{
struct tegra_dfll *td = clk_hw_to_dfll(hw);
return dfll_is_running(td);
}
static int dfll_clk_enable(struct clk_hw *hw)
{
struct tegra_dfll *td = clk_hw_to_dfll(hw);
int ret;
ret = dfll_enable(td);
if (ret)
return ret;
ret = dfll_lock(td);
if (ret)
dfll_disable(td);
return ret;
}
static void dfll_clk_disable(struct clk_hw *hw)
{
struct tegra_dfll *td = clk_hw_to_dfll(hw);
int ret;
ret = dfll_unlock(td);
if (!ret)
dfll_disable(td);
}
static unsigned long dfll_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct tegra_dfll *td = clk_hw_to_dfll(hw);
return td->last_unrounded_rate;
}
static long dfll_clk_round_rate(struct clk_hw *hw,
unsigned long rate,
unsigned long *parent_rate)
{
struct tegra_dfll *td = clk_hw_to_dfll(hw);
struct dfll_rate_req req;
int ret;
ret = dfll_calculate_rate_request(td, &req, rate);
if (ret)
return ret;
return rate;
}
static int dfll_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct tegra_dfll *td = clk_hw_to_dfll(hw);
return dfll_request_rate(td, rate);
}
static int dfll_register_clk(struct tegra_dfll *td)
{
int ret;
dfll_clk_init_data.name = td->output_clock_name;
td->dfll_clk_hw.init = &dfll_clk_init_data;
td->dfll_clk = clk_register(td->dev, &td->dfll_clk_hw);
if (IS_ERR(td->dfll_clk)) {
dev_err(td->dev, "DFLL clock registration error\n");
return -EINVAL;
}
ret = of_clk_add_provider(td->dev->of_node, of_clk_src_simple_get,
td->dfll_clk);
if (ret) {
dev_err(td->dev, "of_clk_add_provider() failed\n");
clk_unregister(td->dfll_clk);
return ret;
}
return 0;
}
static void dfll_unregister_clk(struct tegra_dfll *td)
{
of_clk_del_provider(td->dev->of_node);
clk_unregister(td->dfll_clk);
td->dfll_clk = NULL;
}
static int attr_enable_get(void *data, u64 *val)
{
struct tegra_dfll *td = data;
*val = dfll_is_running(td);
return 0;
}
static int attr_enable_set(void *data, u64 val)
{
struct tegra_dfll *td = data;
return val ? dfll_enable(td) : dfll_disable(td);
}
static int attr_lock_get(void *data, u64 *val)
{
struct tegra_dfll *td = data;
*val = (td->mode == DFLL_CLOSED_LOOP);
return 0;
}
static int attr_lock_set(void *data, u64 val)
{
struct tegra_dfll *td = data;
return val ? dfll_lock(td) : dfll_unlock(td);
}
static int attr_rate_get(void *data, u64 *val)
{
struct tegra_dfll *td = data;
*val = dfll_read_monitor_rate(td);
return 0;
}
static int attr_rate_set(void *data, u64 val)
{
struct tegra_dfll *td = data;
return dfll_request_rate(td, val);
}
static int attr_registers_show(struct seq_file *s, void *data)
{
u32 val, offs;
struct tegra_dfll *td = s->private;
seq_puts(s, "CONTROL REGISTERS:\n");
for (offs = 0; offs <= DFLL_MONITOR_DATA; offs += 4) {
if (offs == DFLL_OUTPUT_CFG)
val = dfll_i2c_readl(td, offs);
else
val = dfll_readl(td, offs);
seq_printf(s, "[0x%02x] = 0x%08x\n", offs, val);
}
seq_puts(s, "\nI2C and INTR REGISTERS:\n");
for (offs = DFLL_I2C_CFG; offs <= DFLL_I2C_STS; offs += 4)
seq_printf(s, "[0x%02x] = 0x%08x\n", offs,
dfll_i2c_readl(td, offs));
for (offs = DFLL_INTR_STS; offs <= DFLL_INTR_EN; offs += 4)
seq_printf(s, "[0x%02x] = 0x%08x\n", offs,
dfll_i2c_readl(td, offs));
seq_puts(s, "\nINTEGRATED I2C CONTROLLER REGISTERS:\n");
offs = DFLL_I2C_CLK_DIVISOR;
seq_printf(s, "[0x%02x] = 0x%08x\n", offs,
__raw_readl(td->i2c_controller_base + offs));
seq_puts(s, "\nLUT:\n");
for (offs = 0; offs < 4 * MAX_DFLL_VOLTAGES; offs += 4)
seq_printf(s, "[0x%02x] = 0x%08x\n", offs,
__raw_readl(td->lut_base + offs));
return 0;
}
static int attr_registers_open(struct inode *inode, struct file *file)
{
return single_open(file, attr_registers_show, inode->i_private);
}
static int dfll_debug_init(struct tegra_dfll *td)
{
int ret;
if (!td || (td->mode == DFLL_UNINITIALIZED))
return 0;
td->debugfs_dir = debugfs_create_dir("tegra_dfll_fcpu", NULL);
if (!td->debugfs_dir)
return -ENOMEM;
ret = -ENOMEM;
if (!debugfs_create_file("enable", S_IRUGO | S_IWUSR,
td->debugfs_dir, td, &enable_fops))
goto err_out;
if (!debugfs_create_file("lock", S_IRUGO,
td->debugfs_dir, td, &lock_fops))
goto err_out;
if (!debugfs_create_file("rate", S_IRUGO,
td->debugfs_dir, td, &rate_fops))
goto err_out;
if (!debugfs_create_file("registers", S_IRUGO,
td->debugfs_dir, td, &attr_registers_fops))
goto err_out;
return 0;
err_out:
debugfs_remove_recursive(td->debugfs_dir);
return ret;
}
static void dfll_set_default_params(struct tegra_dfll *td)
{
u32 val;
val = DIV_ROUND_UP(td->ref_rate, td->sample_rate * 32);
BUG_ON(val > DFLL_CONFIG_DIV_MASK);
dfll_writel(td, val, DFLL_CONFIG);
val = (td->force_mode << DFLL_PARAMS_FORCE_MODE_SHIFT) |
(td->cf << DFLL_PARAMS_CF_PARAM_SHIFT) |
(td->ci << DFLL_PARAMS_CI_PARAM_SHIFT) |
(td->cg << DFLL_PARAMS_CG_PARAM_SHIFT) |
(td->cg_scale ? DFLL_PARAMS_CG_SCALE : 0);
dfll_writel(td, val, DFLL_PARAMS);
dfll_tune_low(td);
dfll_writel(td, td->droop_ctrl, DFLL_DROOP_CTRL);
dfll_writel(td, DFLL_MONITOR_CTRL_FREQ, DFLL_MONITOR_CTRL);
}
static int dfll_init_clks(struct tegra_dfll *td)
{
td->ref_clk = devm_clk_get(td->dev, "ref");
if (IS_ERR(td->ref_clk)) {
dev_err(td->dev, "missing ref clock\n");
return PTR_ERR(td->ref_clk);
}
td->soc_clk = devm_clk_get(td->dev, "soc");
if (IS_ERR(td->soc_clk)) {
dev_err(td->dev, "missing soc clock\n");
return PTR_ERR(td->soc_clk);
}
td->i2c_clk = devm_clk_get(td->dev, "i2c");
if (IS_ERR(td->i2c_clk)) {
dev_err(td->dev, "missing i2c clock\n");
return PTR_ERR(td->i2c_clk);
}
td->i2c_clk_rate = clk_get_rate(td->i2c_clk);
return 0;
}
static int dfll_init(struct tegra_dfll *td)
{
int ret;
td->ref_rate = clk_get_rate(td->ref_clk);
if (td->ref_rate != REF_CLOCK_RATE) {
dev_err(td->dev, "unexpected ref clk rate %lu, expecting %lu",
td->ref_rate, REF_CLOCK_RATE);
return -EINVAL;
}
reset_control_deassert(td->dvco_rst);
ret = clk_prepare(td->ref_clk);
if (ret) {
dev_err(td->dev, "failed to prepare ref_clk\n");
return ret;
}
ret = clk_prepare(td->soc_clk);
if (ret) {
dev_err(td->dev, "failed to prepare soc_clk\n");
goto di_err1;
}
ret = clk_prepare(td->i2c_clk);
if (ret) {
dev_err(td->dev, "failed to prepare i2c_clk\n");
goto di_err2;
}
td->last_unrounded_rate = 0;
pm_runtime_enable(td->dev);
pm_runtime_get_sync(td->dev);
dfll_set_mode(td, DFLL_DISABLED);
dfll_set_default_params(td);
if (td->soc->init_clock_trimmers)
td->soc->init_clock_trimmers();
dfll_set_open_loop_config(td);
dfll_init_out_if(td);
pm_runtime_put_sync(td->dev);
return 0;
di_err2:
clk_unprepare(td->soc_clk);
di_err1:
clk_unprepare(td->ref_clk);
reset_control_assert(td->dvco_rst);
return ret;
}
static int find_vdd_map_entry_exact(struct tegra_dfll *td, int uV)
{
int i, n_voltages, reg_uV;
n_voltages = regulator_count_voltages(td->vdd_reg);
for (i = 0; i < n_voltages; i++) {
reg_uV = regulator_list_voltage(td->vdd_reg, i);
if (reg_uV < 0)
break;
if (uV == reg_uV)
return i;
}
dev_err(td->dev, "no voltage map entry for %d uV\n", uV);
return -EINVAL;
}
static int find_vdd_map_entry_min(struct tegra_dfll *td, int uV)
{
int i, n_voltages, reg_uV;
n_voltages = regulator_count_voltages(td->vdd_reg);
for (i = 0; i < n_voltages; i++) {
reg_uV = regulator_list_voltage(td->vdd_reg, i);
if (reg_uV < 0)
break;
if (uV <= reg_uV)
return i;
}
dev_err(td->dev, "no voltage map entry rounding to %d uV\n", uV);
return -EINVAL;
}
static int dfll_build_i2c_lut(struct tegra_dfll *td)
{
int ret = -EINVAL;
int j, v, v_max, v_opp;
int selector;
unsigned long rate;
struct dev_pm_opp *opp;
int lut;
rcu_read_lock();
rate = ULONG_MAX;
opp = dev_pm_opp_find_freq_floor(td->soc->dev, &rate);
if (IS_ERR(opp)) {
dev_err(td->dev, "couldn't get vmax opp, empty opp table?\n");
goto out;
}
v_max = dev_pm_opp_get_voltage(opp);
v = td->soc->min_millivolts * 1000;
lut = find_vdd_map_entry_exact(td, v);
if (lut < 0)
goto out;
td->i2c_lut[0] = lut;
for (j = 1, rate = 0; ; rate++) {
opp = dev_pm_opp_find_freq_ceil(td->soc->dev, &rate);
if (IS_ERR(opp))
break;
v_opp = dev_pm_opp_get_voltage(opp);
if (v_opp <= td->soc->min_millivolts * 1000)
td->dvco_rate_min = dev_pm_opp_get_freq(opp);
for (;;) {
v += max(1, (v_max - v) / (MAX_DFLL_VOLTAGES - j));
if (v >= v_opp)
break;
selector = find_vdd_map_entry_min(td, v);
if (selector < 0)
goto out;
if (selector != td->i2c_lut[j - 1])
td->i2c_lut[j++] = selector;
}
v = (j == MAX_DFLL_VOLTAGES - 1) ? v_max : v_opp;
selector = find_vdd_map_entry_exact(td, v);
if (selector < 0)
goto out;
if (selector != td->i2c_lut[j - 1])
td->i2c_lut[j++] = selector;
if (v >= v_max)
break;
}
td->i2c_lut_size = j;
if (!td->dvco_rate_min)
dev_err(td->dev, "no opp above DFLL minimum voltage %d mV\n",
td->soc->min_millivolts);
else
ret = 0;
out:
rcu_read_unlock();
return ret;
}
static bool read_dt_param(struct tegra_dfll *td, const char *param, u32 *dest)
{
int err = of_property_read_u32(td->dev->of_node, param, dest);
if (err < 0) {
dev_err(td->dev, "failed to read DT parameter %s: %d\n",
param, err);
return false;
}
return true;
}
static int dfll_fetch_i2c_params(struct tegra_dfll *td)
{
struct regmap *regmap;
struct device *i2c_dev;
struct i2c_client *i2c_client;
int vsel_reg, vsel_mask;
int ret;
if (!read_dt_param(td, "nvidia,i2c-fs-rate", &td->i2c_fs_rate))
return -EINVAL;
regmap = regulator_get_regmap(td->vdd_reg);
i2c_dev = regmap_get_device(regmap);
i2c_client = to_i2c_client(i2c_dev);
td->i2c_slave_addr = i2c_client->addr;
ret = regulator_get_hardware_vsel_register(td->vdd_reg,
&vsel_reg,
&vsel_mask);
if (ret < 0) {
dev_err(td->dev,
"regulator unsuitable for DFLL I2C operation\n");
return -EINVAL;
}
td->i2c_reg = vsel_reg;
ret = dfll_build_i2c_lut(td);
if (ret) {
dev_err(td->dev, "couldn't build I2C LUT\n");
return ret;
}
return 0;
}
static int dfll_fetch_common_params(struct tegra_dfll *td)
{
bool ok = true;
ok &= read_dt_param(td, "nvidia,droop-ctrl", &td->droop_ctrl);
ok &= read_dt_param(td, "nvidia,sample-rate", &td->sample_rate);
ok &= read_dt_param(td, "nvidia,force-mode", &td->force_mode);
ok &= read_dt_param(td, "nvidia,cf", &td->cf);
ok &= read_dt_param(td, "nvidia,ci", &td->ci);
ok &= read_dt_param(td, "nvidia,cg", &td->cg);
td->cg_scale = of_property_read_bool(td->dev->of_node,
"nvidia,cg-scale");
if (of_property_read_string(td->dev->of_node, "clock-output-names",
&td->output_clock_name)) {
dev_err(td->dev, "missing clock-output-names property\n");
ok = false;
}
return ok ? 0 : -EINVAL;
}
int tegra_dfll_register(struct platform_device *pdev,
struct tegra_dfll_soc_data *soc)
{
struct resource *mem;
struct tegra_dfll *td;
int ret;
if (!soc) {
dev_err(&pdev->dev, "no tegra_dfll_soc_data provided\n");
return -EINVAL;
}
td = devm_kzalloc(&pdev->dev, sizeof(*td), GFP_KERNEL);
if (!td)
return -ENOMEM;
td->dev = &pdev->dev;
platform_set_drvdata(pdev, td);
td->soc = soc;
td->vdd_reg = devm_regulator_get(td->dev, "vdd-cpu");
if (IS_ERR(td->vdd_reg)) {
dev_err(td->dev, "couldn't get vdd_cpu regulator\n");
return PTR_ERR(td->vdd_reg);
}
td->dvco_rst = devm_reset_control_get(td->dev, "dvco");
if (IS_ERR(td->dvco_rst)) {
dev_err(td->dev, "couldn't get dvco reset\n");
return PTR_ERR(td->dvco_rst);
}
ret = dfll_fetch_common_params(td);
if (ret) {
dev_err(td->dev, "couldn't parse device tree parameters\n");
return ret;
}
ret = dfll_fetch_i2c_params(td);
if (ret)
return ret;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(td->dev, "no control register resource\n");
return -ENODEV;
}
td->base = devm_ioremap(td->dev, mem->start, resource_size(mem));
if (!td->base) {
dev_err(td->dev, "couldn't ioremap DFLL control registers\n");
return -ENODEV;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!mem) {
dev_err(td->dev, "no i2c_base resource\n");
return -ENODEV;
}
td->i2c_base = devm_ioremap(td->dev, mem->start, resource_size(mem));
if (!td->i2c_base) {
dev_err(td->dev, "couldn't ioremap i2c_base resource\n");
return -ENODEV;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 2);
if (!mem) {
dev_err(td->dev, "no i2c_controller_base resource\n");
return -ENODEV;
}
td->i2c_controller_base = devm_ioremap(td->dev, mem->start,
resource_size(mem));
if (!td->i2c_controller_base) {
dev_err(td->dev,
"couldn't ioremap i2c_controller_base resource\n");
return -ENODEV;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 3);
if (!mem) {
dev_err(td->dev, "no lut_base resource\n");
return -ENODEV;
}
td->lut_base = devm_ioremap(td->dev, mem->start, resource_size(mem));
if (!td->lut_base) {
dev_err(td->dev,
"couldn't ioremap lut_base resource\n");
return -ENODEV;
}
ret = dfll_init_clks(td);
if (ret) {
dev_err(&pdev->dev, "DFLL clock init error\n");
return ret;
}
ret = dfll_init(td);
if (ret)
return ret;
ret = dfll_register_clk(td);
if (ret) {
dev_err(&pdev->dev, "DFLL clk registration failed\n");
return ret;
}
#ifdef CONFIG_DEBUG_FS
dfll_debug_init(td);
#endif
return 0;
}
int tegra_dfll_unregister(struct platform_device *pdev)
{
struct tegra_dfll *td = platform_get_drvdata(pdev);
if (td->mode != DFLL_DISABLED) {
dev_err(&pdev->dev,
"must disable DFLL before removing driver\n");
return -EBUSY;
}
debugfs_remove_recursive(td->debugfs_dir);
dfll_unregister_clk(td);
pm_runtime_disable(&pdev->dev);
clk_unprepare(td->ref_clk);
clk_unprepare(td->soc_clk);
clk_unprepare(td->i2c_clk);
reset_control_assert(td->dvco_rst);
return 0;
}
