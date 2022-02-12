static void emc_ccfifo_writel(struct tegra_emc *emc, u32 value,
unsigned long offset)
{
writel(value, emc->regs + EMC_CCFIFO_DATA);
writel(offset, emc->regs + EMC_CCFIFO_ADDR);
}
static void emc_seq_update_timing(struct tegra_emc *emc)
{
unsigned int i;
u32 value;
writel(1, emc->regs + EMC_TIMING_CONTROL);
for (i = 0; i < EMC_STATUS_UPDATE_TIMEOUT; ++i) {
value = readl(emc->regs + EMC_STATUS);
if ((value & EMC_STATUS_TIMING_UPDATE_STALLED) == 0)
return;
udelay(1);
}
dev_err(emc->dev, "timing update timed out\n");
}
static void emc_seq_disable_auto_cal(struct tegra_emc *emc)
{
unsigned int i;
u32 value;
writel(0, emc->regs + EMC_AUTO_CAL_INTERVAL);
for (i = 0; i < EMC_STATUS_UPDATE_TIMEOUT; ++i) {
value = readl(emc->regs + EMC_AUTO_CAL_STATUS);
if ((value & EMC_AUTO_CAL_STATUS_ACTIVE) == 0)
return;
udelay(1);
}
dev_err(emc->dev, "auto cal disable timed out\n");
}
static void emc_seq_wait_clkchange(struct tegra_emc *emc)
{
unsigned int i;
u32 value;
for (i = 0; i < EMC_STATUS_UPDATE_TIMEOUT; ++i) {
value = readl(emc->regs + EMC_INTSTATUS);
if (value & EMC_INTSTATUS_CLKCHANGE_COMPLETE)
return;
udelay(1);
}
dev_err(emc->dev, "clock change timed out\n");
}
static struct emc_timing *tegra_emc_find_timing(struct tegra_emc *emc,
unsigned long rate)
{
struct emc_timing *timing = NULL;
unsigned int i;
for (i = 0; i < emc->num_timings; i++) {
if (emc->timings[i].rate == rate) {
timing = &emc->timings[i];
break;
}
}
if (!timing) {
dev_err(emc->dev, "no timing for rate %lu\n", rate);
return NULL;
}
return timing;
}
int tegra_emc_prepare_timing_change(struct tegra_emc *emc,
unsigned long rate)
{
struct emc_timing *timing = tegra_emc_find_timing(emc, rate);
struct emc_timing *last = &emc->last_timing;
enum emc_dll_change dll_change;
unsigned int pre_wait = 0;
u32 val, val2, mask;
bool update = false;
unsigned int i;
if (!timing)
return -ENOENT;
if ((last->emc_mode_1 & 0x1) == (timing->emc_mode_1 & 0x1))
dll_change = DLL_CHANGE_NONE;
else if (timing->emc_mode_1 & 0x1)
dll_change = DLL_CHANGE_ON;
else
dll_change = DLL_CHANGE_OFF;
writel(EMC_INTSTATUS_CLKCHANGE_COMPLETE, emc->regs + EMC_INTSTATUS);
val = readl(emc->regs + EMC_CFG);
if (val & EMC_CFG_PWR_MASK) {
val &= ~EMC_CFG_POWER_FEATURES_MASK;
writel(val, emc->regs + EMC_CFG);
pre_wait = 5;
}
if (emc->dram_type == DRAM_TYPE_DDR3)
mask = EMC_SEL_DPD_CTRL_DDR3_MASK;
else
mask = EMC_SEL_DPD_CTRL_MASK;
val = readl(emc->regs + EMC_SEL_DPD_CTRL);
if (val & mask) {
val &= ~mask;
writel(val, emc->regs + EMC_SEL_DPD_CTRL);
}
val = readl(emc->regs + EMC_BGBIAS_CTL0);
val2 = last->emc_bgbias_ctl0;
if (!(timing->emc_bgbias_ctl0 &
EMC_BGBIAS_CTL0_BIAS0_DSC_E_PWRD_IBIAS_RX) &&
(val & EMC_BGBIAS_CTL0_BIAS0_DSC_E_PWRD_IBIAS_RX)) {
val2 &= ~EMC_BGBIAS_CTL0_BIAS0_DSC_E_PWRD_IBIAS_RX;
update = true;
}
if ((val & EMC_BGBIAS_CTL0_BIAS0_DSC_E_PWRD) ||
(val & EMC_BGBIAS_CTL0_BIAS0_DSC_E_PWRD_IBIAS_VTTGEN)) {
update = true;
}
if (update) {
writel(val2, emc->regs + EMC_BGBIAS_CTL0);
if (pre_wait < 5)
pre_wait = 5;
}
update = false;
val = readl(emc->regs + EMC_XM2DQSPADCTRL2);
if (timing->emc_xm2dqspadctrl2 & EMC_XM2DQSPADCTRL2_VREF_ENABLE &&
!(val & EMC_XM2DQSPADCTRL2_VREF_ENABLE)) {
val |= EMC_XM2DQSPADCTRL2_VREF_ENABLE;
update = true;
}
if (timing->emc_xm2dqspadctrl2 & EMC_XM2DQSPADCTRL2_RX_FT_REC_ENABLE &&
!(val & EMC_XM2DQSPADCTRL2_RX_FT_REC_ENABLE)) {
val |= EMC_XM2DQSPADCTRL2_RX_FT_REC_ENABLE;
update = true;
}
if (update) {
writel(val, emc->regs + EMC_XM2DQSPADCTRL2);
if (pre_wait < 30)
pre_wait = 30;
}
if (pre_wait) {
emc_seq_update_timing(emc);
udelay(pre_wait);
}
if (last->emc_ctt_term_ctrl != timing->emc_ctt_term_ctrl) {
emc_seq_disable_auto_cal(emc);
writel(timing->emc_ctt_term_ctrl,
emc->regs + EMC_CTT_TERM_CTRL);
emc_seq_update_timing(emc);
}
for (i = 0; i < ARRAY_SIZE(timing->emc_burst_data); ++i)
writel(timing->emc_burst_data[i],
emc->regs + emc_burst_regs[i]);
writel(timing->emc_xm2dqspadctrl2, emc->regs + EMC_XM2DQSPADCTRL2);
writel(timing->emc_zcal_interval, emc->regs + EMC_ZCAL_INTERVAL);
tegra_mc_write_emem_configuration(emc->mc, timing->rate);
val = timing->emc_cfg & ~EMC_CFG_POWER_FEATURES_MASK;
emc_ccfifo_writel(emc, val, EMC_CFG);
if (timing->emc_auto_cal_config2 != last->emc_auto_cal_config2)
emc_ccfifo_writel(emc, timing->emc_auto_cal_config2,
EMC_AUTO_CAL_CONFIG2);
if (timing->emc_auto_cal_config3 != last->emc_auto_cal_config3)
emc_ccfifo_writel(emc, timing->emc_auto_cal_config3,
EMC_AUTO_CAL_CONFIG3);
if (timing->emc_auto_cal_config != last->emc_auto_cal_config) {
val = timing->emc_auto_cal_config;
val &= EMC_AUTO_CAL_CONFIG_AUTO_CAL_START;
emc_ccfifo_writel(emc, val, EMC_AUTO_CAL_CONFIG);
}
if (emc->dram_type == DRAM_TYPE_DDR3 &&
dll_change == DLL_CHANGE_ON) {
u32 cnt = 512;
if (timing->emc_zcal_interval != 0 &&
last->emc_zcal_interval == 0)
cnt -= emc->dram_num * 256;
val = (timing->emc_mrs_wait_cnt
& EMC_MRS_WAIT_CNT_SHORT_WAIT_MASK)
>> EMC_MRS_WAIT_CNT_SHORT_WAIT_SHIFT;
if (cnt < val)
cnt = val;
val = timing->emc_mrs_wait_cnt
& ~EMC_MRS_WAIT_CNT_LONG_WAIT_MASK;
val |= (cnt << EMC_MRS_WAIT_CNT_LONG_WAIT_SHIFT)
& EMC_MRS_WAIT_CNT_LONG_WAIT_MASK;
writel(val, emc->regs + EMC_MRS_WAIT_CNT);
}
val = timing->emc_cfg_2;
val &= ~EMC_CFG_2_DIS_STP_OB_CLK_DURING_NON_WR;
emc_ccfifo_writel(emc, val, EMC_CFG_2);
if (emc->dram_type == DRAM_TYPE_DDR3 && dll_change == DLL_CHANGE_OFF)
emc_ccfifo_writel(emc, timing->emc_mode_1, EMC_EMRS);
emc_ccfifo_writel(emc, EMC_REFCTRL_DEV_SEL(emc->dram_num),
EMC_REFCTRL);
if (emc->dram_type == DRAM_TYPE_DDR3)
emc_ccfifo_writel(emc, EMC_DRAM_DEV_SEL(emc->dram_num) |
EMC_SELF_REF_CMD_ENABLED,
EMC_SELF_REF);
emc_ccfifo_writel(emc, 1, EMC_STALL_THEN_EXE_AFTER_CLKCHANGE);
if (emc->dram_type == DRAM_TYPE_DDR3)
emc_ccfifo_writel(emc, EMC_DRAM_DEV_SEL(emc->dram_num),
EMC_SELF_REF);
emc_ccfifo_writel(emc, EMC_REFCTRL_DEV_SEL(emc->dram_num) |
EMC_REFCTRL_ENABLE,
EMC_REFCTRL);
if (emc->dram_type == DRAM_TYPE_DDR3) {
if (timing->emc_mode_1 != last->emc_mode_1)
emc_ccfifo_writel(emc, timing->emc_mode_1, EMC_EMRS);
if (timing->emc_mode_2 != last->emc_mode_2)
emc_ccfifo_writel(emc, timing->emc_mode_2, EMC_EMRS2);
if ((timing->emc_mode_reset != last->emc_mode_reset) ||
dll_change == DLL_CHANGE_ON) {
val = timing->emc_mode_reset;
if (dll_change == DLL_CHANGE_ON) {
val |= EMC_MODE_SET_DLL_RESET;
val |= EMC_MODE_SET_LONG_CNT;
} else {
val &= ~EMC_MODE_SET_DLL_RESET;
}
emc_ccfifo_writel(emc, val, EMC_MRS);
}
} else {
if (timing->emc_mode_2 != last->emc_mode_2)
emc_ccfifo_writel(emc, timing->emc_mode_2, EMC_MRW2);
if (timing->emc_mode_1 != last->emc_mode_1)
emc_ccfifo_writel(emc, timing->emc_mode_1, EMC_MRW);
if (timing->emc_mode_4 != last->emc_mode_4)
emc_ccfifo_writel(emc, timing->emc_mode_4, EMC_MRW4);
}
if (timing->emc_zcal_interval != 0 && last->emc_zcal_interval == 0) {
emc_ccfifo_writel(emc, EMC_ZQ_CAL_LONG_CMD_DEV0, EMC_ZQ_CAL);
if (emc->dram_num > 1)
emc_ccfifo_writel(emc, EMC_ZQ_CAL_LONG_CMD_DEV1,
EMC_ZQ_CAL);
}
emc_ccfifo_writel(emc, 0, EMC_CCFIFO_STATUS);
if (timing->emc_cfg_2 & EMC_CFG_2_DIS_STP_OB_CLK_DURING_NON_WR)
emc_ccfifo_writel(emc, timing->emc_cfg_2, EMC_CFG_2);
emc_seq_disable_auto_cal(emc);
readl(emc->regs + EMC_INTSTATUS);
return 0;
}
void tegra_emc_complete_timing_change(struct tegra_emc *emc,
unsigned long rate)
{
struct emc_timing *timing = tegra_emc_find_timing(emc, rate);
struct emc_timing *last = &emc->last_timing;
u32 val;
if (!timing)
return;
emc_seq_wait_clkchange(emc);
if (timing->emc_ctt_term_ctrl != last->emc_ctt_term_ctrl)
writel(timing->emc_auto_cal_interval,
emc->regs + EMC_AUTO_CAL_INTERVAL);
if (timing->emc_cfg & EMC_CFG_PWR_MASK)
writel(timing->emc_cfg, emc->regs + EMC_CFG);
writel(timing->emc_zcal_cnt_long, emc->regs + EMC_ZCAL_WAIT_CNT);
if (emc->dram_type == DRAM_TYPE_LPDDR3 &&
timing->emc_bgbias_ctl0 &
EMC_BGBIAS_CTL0_BIAS0_DSC_E_PWRD_IBIAS_RX) {
val = timing->emc_bgbias_ctl0;
val |= EMC_BGBIAS_CTL0_BIAS0_DSC_E_PWRD_IBIAS_VTTGEN;
val |= EMC_BGBIAS_CTL0_BIAS0_DSC_E_PWRD;
writel(val, emc->regs + EMC_BGBIAS_CTL0);
} else {
if (emc->dram_type == DRAM_TYPE_DDR3 &&
readl(emc->regs + EMC_BGBIAS_CTL0) !=
timing->emc_bgbias_ctl0) {
writel(timing->emc_bgbias_ctl0,
emc->regs + EMC_BGBIAS_CTL0);
}
writel(timing->emc_auto_cal_interval,
emc->regs + EMC_AUTO_CAL_INTERVAL);
}
udelay(2);
writel(timing->emc_sel_dpd_ctrl, emc->regs + EMC_SEL_DPD_CTRL);
emc_seq_update_timing(emc);
emc->last_timing = *timing;
}
static void emc_read_current_timing(struct tegra_emc *emc,
struct emc_timing *timing)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(emc_burst_regs); ++i)
timing->emc_burst_data[i] =
readl(emc->regs + emc_burst_regs[i]);
timing->emc_cfg = readl(emc->regs + EMC_CFG);
timing->emc_auto_cal_interval = 0;
timing->emc_zcal_cnt_long = 0;
timing->emc_mode_1 = 0;
timing->emc_mode_2 = 0;
timing->emc_mode_4 = 0;
timing->emc_mode_reset = 0;
}
static int emc_init(struct tegra_emc *emc)
{
emc->dram_type = readl(emc->regs + EMC_FBIO_CFG5);
emc->dram_type &= EMC_FBIO_CFG5_DRAM_TYPE_MASK;
emc->dram_type >>= EMC_FBIO_CFG5_DRAM_TYPE_SHIFT;
emc->dram_num = tegra_mc_get_emem_device_count(emc->mc);
emc_read_current_timing(emc, &emc->last_timing);
return 0;
}
static int load_one_timing_from_dt(struct tegra_emc *emc,
struct emc_timing *timing,
struct device_node *node)
{
u32 value;
int err;
err = of_property_read_u32(node, "clock-frequency", &value);
if (err) {
dev_err(emc->dev, "timing %s: failed to read rate: %d\n",
node->name, err);
return err;
}
timing->rate = value;
err = of_property_read_u32_array(node, "nvidia,emc-configuration",
timing->emc_burst_data,
ARRAY_SIZE(timing->emc_burst_data));
if (err) {
dev_err(emc->dev,
"timing %s: failed to read emc burst data: %d\n",
node->name, err);
return err;
}
#define EMC_READ_PROP(prop, dtprop) { \
err = of_property_read_u32(node, dtprop, &timing->prop); \
if (err) { \
dev_err(emc->dev, "timing %s: failed to read " #prop ": %d\n", \
node->name, err); \
return err; \
} \
}
EMC_READ_PROP(emc_auto_cal_config, "nvidia,emc-auto-cal-config")
EMC_READ_PROP(emc_auto_cal_config2, "nvidia,emc-auto-cal-config2")
EMC_READ_PROP(emc_auto_cal_config3, "nvidia,emc-auto-cal-config3")
EMC_READ_PROP(emc_auto_cal_interval, "nvidia,emc-auto-cal-interval")
EMC_READ_PROP(emc_bgbias_ctl0, "nvidia,emc-bgbias-ctl0")
EMC_READ_PROP(emc_cfg, "nvidia,emc-cfg")
EMC_READ_PROP(emc_cfg_2, "nvidia,emc-cfg-2")
EMC_READ_PROP(emc_ctt_term_ctrl, "nvidia,emc-ctt-term-ctrl")
EMC_READ_PROP(emc_mode_1, "nvidia,emc-mode-1")
EMC_READ_PROP(emc_mode_2, "nvidia,emc-mode-2")
EMC_READ_PROP(emc_mode_4, "nvidia,emc-mode-4")
EMC_READ_PROP(emc_mode_reset, "nvidia,emc-mode-reset")
EMC_READ_PROP(emc_mrs_wait_cnt, "nvidia,emc-mrs-wait-cnt")
EMC_READ_PROP(emc_sel_dpd_ctrl, "nvidia,emc-sel-dpd-ctrl")
EMC_READ_PROP(emc_xm2dqspadctrl2, "nvidia,emc-xm2dqspadctrl2")
EMC_READ_PROP(emc_zcal_cnt_long, "nvidia,emc-zcal-cnt-long")
EMC_READ_PROP(emc_zcal_interval, "nvidia,emc-zcal-interval")
#undef EMC_READ_PROP
return 0;
}
static int cmp_timings(const void *_a, const void *_b)
{
const struct emc_timing *a = _a;
const struct emc_timing *b = _b;
if (a->rate < b->rate)
return -1;
else if (a->rate == b->rate)
return 0;
else
return 1;
}
static int tegra_emc_load_timings_from_dt(struct tegra_emc *emc,
struct device_node *node)
{
int child_count = of_get_child_count(node);
struct device_node *child;
struct emc_timing *timing;
unsigned int i = 0;
int err;
emc->timings = devm_kcalloc(emc->dev, child_count, sizeof(*timing),
GFP_KERNEL);
if (!emc->timings)
return -ENOMEM;
emc->num_timings = child_count;
for_each_child_of_node(node, child) {
timing = &emc->timings[i++];
err = load_one_timing_from_dt(emc, timing, child);
if (err) {
of_node_put(child);
return err;
}
}
sort(emc->timings, emc->num_timings, sizeof(*timing), cmp_timings,
NULL);
return 0;
}
static struct device_node *
tegra_emc_find_node_by_ram_code(struct device_node *node, u32 ram_code)
{
struct device_node *np;
int err;
for_each_child_of_node(node, np) {
u32 value;
err = of_property_read_u32(np, "nvidia,ram-code", &value);
if (err || (value != ram_code))
continue;
return np;
}
return NULL;
}
static int emc_debug_rate_get(void *data, u64 *rate)
{
struct clk *c = data;
*rate = clk_get_rate(c);
return 0;
}
static int emc_debug_rate_set(void *data, u64 rate)
{
struct clk *c = data;
return clk_set_rate(c, rate);
}
static int emc_debug_supported_rates_show(struct seq_file *s, void *data)
{
struct tegra_emc *emc = s->private;
const char *prefix = "";
unsigned int i;
for (i = 0; i < emc->num_timings; i++) {
struct emc_timing *timing = &emc->timings[i];
seq_printf(s, "%s%lu", prefix, timing->rate);
prefix = " ";
}
seq_puts(s, "\n");
return 0;
}
static int emc_debug_supported_rates_open(struct inode *inode,
struct file *file)
{
return single_open(file, emc_debug_supported_rates_show,
inode->i_private);
}
static void emc_debugfs_init(struct device *dev, struct tegra_emc *emc)
{
struct dentry *root, *file;
struct clk *clk;
root = debugfs_create_dir("emc", NULL);
if (!root) {
dev_err(dev, "failed to create debugfs directory\n");
return;
}
clk = clk_get_sys("tegra-clk-debug", "emc");
if (IS_ERR(clk)) {
dev_err(dev, "failed to get debug clock: %ld\n", PTR_ERR(clk));
return;
}
file = debugfs_create_file("rate", S_IRUGO | S_IWUSR, root, clk,
&emc_debug_rate_fops);
if (!file)
dev_err(dev, "failed to create debugfs entry\n");
file = debugfs_create_file("supported_rates", S_IRUGO, root, emc,
&emc_debug_supported_rates_fops);
if (!file)
dev_err(dev, "failed to create debugfs entry\n");
}
static int tegra_emc_probe(struct platform_device *pdev)
{
struct platform_device *mc;
struct device_node *np;
struct tegra_emc *emc;
struct resource *res;
u32 ram_code;
int err;
emc = devm_kzalloc(&pdev->dev, sizeof(*emc), GFP_KERNEL);
if (!emc)
return -ENOMEM;
emc->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
emc->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(emc->regs))
return PTR_ERR(emc->regs);
np = of_parse_phandle(pdev->dev.of_node, "nvidia,memory-controller", 0);
if (!np) {
dev_err(&pdev->dev, "could not get memory controller\n");
return -ENOENT;
}
mc = of_find_device_by_node(np);
if (!mc)
return -ENOENT;
of_node_put(np);
emc->mc = platform_get_drvdata(mc);
if (!emc->mc)
return -EPROBE_DEFER;
ram_code = tegra_read_ram_code();
np = tegra_emc_find_node_by_ram_code(pdev->dev.of_node, ram_code);
if (!np) {
dev_err(&pdev->dev,
"no memory timings for RAM code %u found in DT\n",
ram_code);
return -ENOENT;
}
err = tegra_emc_load_timings_from_dt(emc, np);
of_node_put(np);
if (err)
return err;
if (emc->num_timings == 0) {
dev_err(&pdev->dev,
"no memory timings for RAM code %u registered\n",
ram_code);
return -ENOENT;
}
err = emc_init(emc);
if (err) {
dev_err(&pdev->dev, "EMC initialization failed: %d\n", err);
return err;
}
platform_set_drvdata(pdev, emc);
if (IS_ENABLED(CONFIG_DEBUG_FS))
emc_debugfs_init(&pdev->dev, emc);
return 0;
}
static int tegra_emc_init(void)
{
return platform_driver_register(&tegra_emc_driver);
}
