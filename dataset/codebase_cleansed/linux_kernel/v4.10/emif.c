static void do_emif_regdump_show(struct seq_file *s, struct emif_data *emif,
struct emif_regs *regs)
{
u32 type = emif->plat_data->device_info->type;
u32 ip_rev = emif->plat_data->ip_rev;
seq_printf(s, "EMIF register cache dump for %dMHz\n",
regs->freq/1000000);
seq_printf(s, "ref_ctrl_shdw\t: 0x%08x\n", regs->ref_ctrl_shdw);
seq_printf(s, "sdram_tim1_shdw\t: 0x%08x\n", regs->sdram_tim1_shdw);
seq_printf(s, "sdram_tim2_shdw\t: 0x%08x\n", regs->sdram_tim2_shdw);
seq_printf(s, "sdram_tim3_shdw\t: 0x%08x\n", regs->sdram_tim3_shdw);
if (ip_rev == EMIF_4D) {
seq_printf(s, "read_idle_ctrl_shdw_normal\t: 0x%08x\n",
regs->read_idle_ctrl_shdw_normal);
seq_printf(s, "read_idle_ctrl_shdw_volt_ramp\t: 0x%08x\n",
regs->read_idle_ctrl_shdw_volt_ramp);
} else if (ip_rev == EMIF_4D5) {
seq_printf(s, "dll_calib_ctrl_shdw_normal\t: 0x%08x\n",
regs->dll_calib_ctrl_shdw_normal);
seq_printf(s, "dll_calib_ctrl_shdw_volt_ramp\t: 0x%08x\n",
regs->dll_calib_ctrl_shdw_volt_ramp);
}
if (type == DDR_TYPE_LPDDR2_S2 || type == DDR_TYPE_LPDDR2_S4) {
seq_printf(s, "ref_ctrl_shdw_derated\t: 0x%08x\n",
regs->ref_ctrl_shdw_derated);
seq_printf(s, "sdram_tim1_shdw_derated\t: 0x%08x\n",
regs->sdram_tim1_shdw_derated);
seq_printf(s, "sdram_tim3_shdw_derated\t: 0x%08x\n",
regs->sdram_tim3_shdw_derated);
}
}
static int emif_regdump_show(struct seq_file *s, void *unused)
{
struct emif_data *emif = s->private;
struct emif_regs **regs_cache;
int i;
if (emif->duplicate)
regs_cache = emif1->regs_cache;
else
regs_cache = emif->regs_cache;
for (i = 0; i < EMIF_MAX_NUM_FREQUENCIES && regs_cache[i]; i++) {
do_emif_regdump_show(s, emif, regs_cache[i]);
seq_printf(s, "\n");
}
return 0;
}
static int emif_regdump_open(struct inode *inode, struct file *file)
{
return single_open(file, emif_regdump_show, inode->i_private);
}
static int emif_mr4_show(struct seq_file *s, void *unused)
{
struct emif_data *emif = s->private;
seq_printf(s, "MR4=%d\n", emif->temperature_level);
return 0;
}
static int emif_mr4_open(struct inode *inode, struct file *file)
{
return single_open(file, emif_mr4_show, inode->i_private);
}
static int __init_or_module emif_debugfs_init(struct emif_data *emif)
{
struct dentry *dentry;
int ret;
dentry = debugfs_create_dir(dev_name(emif->dev), NULL);
if (!dentry) {
ret = -ENOMEM;
goto err0;
}
emif->debugfs_root = dentry;
dentry = debugfs_create_file("regcache_dump", S_IRUGO,
emif->debugfs_root, emif, &emif_regdump_fops);
if (!dentry) {
ret = -ENOMEM;
goto err1;
}
dentry = debugfs_create_file("mr4", S_IRUGO,
emif->debugfs_root, emif, &emif_mr4_fops);
if (!dentry) {
ret = -ENOMEM;
goto err1;
}
return 0;
err1:
debugfs_remove_recursive(emif->debugfs_root);
err0:
return ret;
}
static void __exit emif_debugfs_exit(struct emif_data *emif)
{
debugfs_remove_recursive(emif->debugfs_root);
emif->debugfs_root = NULL;
}
static inline int __init_or_module emif_debugfs_init(struct emif_data *emif)
{
return 0;
}
static inline void __exit emif_debugfs_exit(struct emif_data *emif)
{
}
static void set_ddr_clk_period(u32 freq)
{
t_ck = (u32)DIV_ROUND_UP_ULL(1000000000000ull, freq);
}
static u32 get_emif_bus_width(struct emif_data *emif)
{
u32 width;
void __iomem *base = emif->base;
width = (readl(base + EMIF_SDRAM_CONFIG) & NARROW_MODE_MASK)
>> NARROW_MODE_SHIFT;
width = width == 0 ? 32 : 16;
return width;
}
static u32 get_cl(struct emif_data *emif)
{
u32 cl;
void __iomem *base = emif->base;
cl = (readl(base + EMIF_SDRAM_CONFIG) & CL_MASK) >> CL_SHIFT;
return cl;
}
static void set_lpmode(struct emif_data *emif, u8 lpmode)
{
u32 temp;
void __iomem *base = emif->base;
if ((emif->plat_data->ip_rev == EMIF_4D) &&
(EMIF_LP_MODE_PWR_DN == lpmode)) {
WARN_ONCE(1,
"REG_LP_MODE = LP_MODE_PWR_DN(4) is prohibited by"
"erratum i743 switch to LP_MODE_SELF_REFRESH(2)\n");
lpmode = EMIF_LP_MODE_SELF_REFRESH;
}
temp = readl(base + EMIF_POWER_MANAGEMENT_CONTROL);
temp &= ~LP_MODE_MASK;
temp |= (lpmode << LP_MODE_SHIFT);
writel(temp, base + EMIF_POWER_MANAGEMENT_CONTROL);
}
static void do_freq_update(void)
{
struct emif_data *emif;
list_for_each_entry(emif, &device_list, node) {
if (emif->lpmode == EMIF_LP_MODE_SELF_REFRESH)
set_lpmode(emif, EMIF_LP_MODE_DISABLE);
}
list_for_each_entry(emif, &device_list, node) {
if (emif->lpmode == EMIF_LP_MODE_SELF_REFRESH)
set_lpmode(emif, EMIF_LP_MODE_SELF_REFRESH);
}
}
static const struct lpddr2_addressing *get_addressing_table(
const struct ddr_device_info *device_info)
{
u32 index, type, density;
type = device_info->type;
density = device_info->density;
switch (type) {
case DDR_TYPE_LPDDR2_S4:
index = density - 1;
break;
case DDR_TYPE_LPDDR2_S2:
switch (density) {
case DDR_DENSITY_1Gb:
case DDR_DENSITY_2Gb:
index = density + 3;
break;
default:
index = density - 1;
}
break;
default:
return NULL;
}
return &lpddr2_jedec_addressing_table[index];
}
static const struct lpddr2_timings *get_timings_table(struct emif_data *emif,
u32 freq)
{
u32 i, min, max, freq_nearest;
const struct lpddr2_timings *timings = NULL;
const struct lpddr2_timings *timings_arr = emif->plat_data->timings;
struct device *dev = emif->dev;
freq_nearest = 1000000000;
for (i = 0; i < emif->plat_data->timings_arr_size; i++) {
max = timings_arr[i].max_freq;
min = timings_arr[i].min_freq;
if ((freq >= min) && (freq <= max) && (max < freq_nearest)) {
freq_nearest = max;
timings = &timings_arr[i];
}
}
if (!timings)
dev_err(dev, "%s: couldn't find timings for - %dHz\n",
__func__, freq);
dev_dbg(dev, "%s: timings table: freq %d, speed bin freq %d\n",
__func__, freq, freq_nearest);
return timings;
}
static u32 get_sdram_ref_ctrl_shdw(u32 freq,
const struct lpddr2_addressing *addressing)
{
u32 ref_ctrl_shdw = 0, val = 0, freq_khz, t_refi;
freq_khz = freq / 1000;
t_refi = addressing->tREFI_ns / 100;
val = t_refi * freq_khz / 10000;
ref_ctrl_shdw |= val << REFRESH_RATE_SHIFT;
return ref_ctrl_shdw;
}
static u32 get_sdram_tim_1_shdw(const struct lpddr2_timings *timings,
const struct lpddr2_min_tck *min_tck,
const struct lpddr2_addressing *addressing)
{
u32 tim1 = 0, val = 0;
val = max(min_tck->tWTR, DIV_ROUND_UP(timings->tWTR, t_ck)) - 1;
tim1 |= val << T_WTR_SHIFT;
if (addressing->num_banks == B8)
val = DIV_ROUND_UP(timings->tFAW, t_ck*4);
else
val = max(min_tck->tRRD, DIV_ROUND_UP(timings->tRRD, t_ck));
tim1 |= (val - 1) << T_RRD_SHIFT;
val = DIV_ROUND_UP(timings->tRAS_min + timings->tRPab, t_ck) - 1;
tim1 |= val << T_RC_SHIFT;
val = max(min_tck->tRASmin, DIV_ROUND_UP(timings->tRAS_min, t_ck));
tim1 |= (val - 1) << T_RAS_SHIFT;
val = max(min_tck->tWR, DIV_ROUND_UP(timings->tWR, t_ck)) - 1;
tim1 |= val << T_WR_SHIFT;
val = max(min_tck->tRCD, DIV_ROUND_UP(timings->tRCD, t_ck)) - 1;
tim1 |= val << T_RCD_SHIFT;
val = max(min_tck->tRPab, DIV_ROUND_UP(timings->tRPab, t_ck)) - 1;
tim1 |= val << T_RP_SHIFT;
return tim1;
}
static u32 get_sdram_tim_1_shdw_derated(const struct lpddr2_timings *timings,
const struct lpddr2_min_tck *min_tck,
const struct lpddr2_addressing *addressing)
{
u32 tim1 = 0, val = 0;
val = max(min_tck->tWTR, DIV_ROUND_UP(timings->tWTR, t_ck)) - 1;
tim1 = val << T_WTR_SHIFT;
if (addressing->num_banks == B8) {
val = DIV_ROUND_UP(timings->tFAW + 7500, 4 * t_ck) - 1;
} else {
val = DIV_ROUND_UP(timings->tRRD + 1875, t_ck);
val = max(min_tck->tRRD, val) - 1;
}
tim1 |= val << T_RRD_SHIFT;
val = DIV_ROUND_UP(timings->tRAS_min + timings->tRPab + 1875, t_ck);
tim1 |= (val - 1) << T_RC_SHIFT;
val = DIV_ROUND_UP(timings->tRAS_min + 1875, t_ck);
val = max(min_tck->tRASmin, val) - 1;
tim1 |= val << T_RAS_SHIFT;
val = max(min_tck->tWR, DIV_ROUND_UP(timings->tWR, t_ck)) - 1;
tim1 |= val << T_WR_SHIFT;
val = max(min_tck->tRCD, DIV_ROUND_UP(timings->tRCD + 1875, t_ck));
tim1 |= (val - 1) << T_RCD_SHIFT;
val = max(min_tck->tRPab, DIV_ROUND_UP(timings->tRPab + 1875, t_ck));
tim1 |= (val - 1) << T_RP_SHIFT;
return tim1;
}
static u32 get_sdram_tim_2_shdw(const struct lpddr2_timings *timings,
const struct lpddr2_min_tck *min_tck,
const struct lpddr2_addressing *addressing,
u32 type)
{
u32 tim2 = 0, val = 0;
val = min_tck->tCKE - 1;
tim2 |= val << T_CKE_SHIFT;
val = max(min_tck->tRTP, DIV_ROUND_UP(timings->tRTP, t_ck)) - 1;
tim2 |= val << T_RTP_SHIFT;
val = DIV_ROUND_UP(addressing->tRFCab_ps + 10000, t_ck) - 1;
tim2 |= val << T_XSNR_SHIFT;
tim2 |= val << T_XSRD_SHIFT;
val = max(min_tck->tXP, DIV_ROUND_UP(timings->tXP, t_ck)) - 1;
tim2 |= val << T_XP_SHIFT;
return tim2;
}
static u32 get_sdram_tim_3_shdw(const struct lpddr2_timings *timings,
const struct lpddr2_min_tck *min_tck,
const struct lpddr2_addressing *addressing,
u32 type, u32 ip_rev, u32 derated)
{
u32 tim3 = 0, val = 0, t_dqsck;
val = timings->tRAS_max_ns / addressing->tREFI_ns - 1;
val = val > 0xF ? 0xF : val;
tim3 |= val << T_RAS_MAX_SHIFT;
val = DIV_ROUND_UP(addressing->tRFCab_ps, t_ck) - 1;
tim3 |= val << T_RFC_SHIFT;
t_dqsck = (derated == EMIF_DERATED_TIMINGS) ?
timings->tDQSCK_max_derated : timings->tDQSCK_max;
if (ip_rev == EMIF_4D5)
val = DIV_ROUND_UP(t_dqsck + 1000, t_ck) - 1;
else
val = DIV_ROUND_UP(t_dqsck, t_ck) - 1;
tim3 |= val << T_TDQSCKMAX_SHIFT;
val = DIV_ROUND_UP(timings->tZQCS, t_ck) - 1;
tim3 |= val << ZQ_ZQCS_SHIFT;
val = DIV_ROUND_UP(timings->tCKESR, t_ck);
val = max(min_tck->tCKESR, val) - 1;
tim3 |= val << T_CKESR_SHIFT;
if (ip_rev == EMIF_4D5) {
tim3 |= (EMIF_T_CSTA - 1) << T_CSTA_SHIFT;
val = DIV_ROUND_UP(EMIF_T_PDLL_UL, 128) - 1;
tim3 |= val << T_PDLL_UL_SHIFT;
}
return tim3;
}
static u32 get_zq_config_reg(const struct lpddr2_addressing *addressing,
bool cs1_used, bool cal_resistors_per_cs)
{
u32 zq = 0, val = 0;
val = EMIF_ZQCS_INTERVAL_US * 1000 / addressing->tREFI_ns;
zq |= val << ZQ_REFINTERVAL_SHIFT;
val = DIV_ROUND_UP(T_ZQCL_DEFAULT_NS, T_ZQCS_DEFAULT_NS) - 1;
zq |= val << ZQ_ZQCL_MULT_SHIFT;
val = DIV_ROUND_UP(T_ZQINIT_DEFAULT_NS, T_ZQCL_DEFAULT_NS) - 1;
zq |= val << ZQ_ZQINIT_MULT_SHIFT;
zq |= ZQ_SFEXITEN_ENABLE << ZQ_SFEXITEN_SHIFT;
if (cal_resistors_per_cs)
zq |= ZQ_DUALCALEN_ENABLE << ZQ_DUALCALEN_SHIFT;
else
zq |= ZQ_DUALCALEN_DISABLE << ZQ_DUALCALEN_SHIFT;
zq |= ZQ_CS0EN_MASK;
val = cs1_used ? 1 : 0;
zq |= val << ZQ_CS1EN_SHIFT;
return zq;
}
static u32 get_temp_alert_config(const struct lpddr2_addressing *addressing,
const struct emif_custom_configs *custom_configs, bool cs1_used,
u32 sdram_io_width, u32 emif_bus_width)
{
u32 alert = 0, interval, devcnt;
if (custom_configs && (custom_configs->mask &
EMIF_CUSTOM_CONFIG_TEMP_ALERT_POLL_INTERVAL))
interval = custom_configs->temp_alert_poll_interval_ms;
else
interval = TEMP_ALERT_POLL_INTERVAL_DEFAULT_MS;
interval *= 1000000;
interval /= addressing->tREFI_ns;
alert |= (interval << TA_REFINTERVAL_SHIFT);
emif_bus_width = __fls(emif_bus_width) - 1;
devcnt = emif_bus_width - sdram_io_width;
alert |= devcnt << TA_DEVCNT_SHIFT;
alert |= (sdram_io_width - 2) << TA_DEVWDT_SHIFT;
alert |= 1 << TA_SFEXITEN_SHIFT;
alert |= 1 << TA_CS0EN_SHIFT;
alert |= (cs1_used ? 1 : 0) << TA_CS1EN_SHIFT;
return alert;
}
static u32 get_read_idle_ctrl_shdw(u8 volt_ramp)
{
u32 idle = 0, val = 0;
if (volt_ramp)
val = READ_IDLE_INTERVAL_DVFS / t_ck / 64 - 1;
else
val = 0x1FF;
idle |= val << DLL_CALIB_INTERVAL_SHIFT;
idle |= EMIF_READ_IDLE_LEN_VAL << ACK_WAIT_SHIFT;
return idle;
}
static u32 get_dll_calib_ctrl_shdw(u8 volt_ramp)
{
u32 calib = 0, val = 0;
if (volt_ramp == DDR_VOLTAGE_RAMPING)
val = DLL_CALIB_INTERVAL_DVFS / t_ck / 16 - 1;
else
val = 0;
calib |= val << DLL_CALIB_INTERVAL_SHIFT;
calib |= DLL_CALIB_ACK_WAIT_VAL << ACK_WAIT_SHIFT;
return calib;
}
static u32 get_ddr_phy_ctrl_1_attilaphy_4d(const struct lpddr2_timings *timings,
u32 freq, u8 RL)
{
u32 phy = EMIF_DDR_PHY_CTRL_1_BASE_VAL_ATTILAPHY, val = 0;
val = RL + DIV_ROUND_UP(timings->tDQSCK_max, t_ck) - 1;
phy |= val << READ_LATENCY_SHIFT_4D;
if (freq <= 100000000)
val = EMIF_DLL_SLAVE_DLY_CTRL_100_MHZ_AND_LESS_ATTILAPHY;
else if (freq <= 200000000)
val = EMIF_DLL_SLAVE_DLY_CTRL_200_MHZ_ATTILAPHY;
else
val = EMIF_DLL_SLAVE_DLY_CTRL_400_MHZ_ATTILAPHY;
phy |= val << DLL_SLAVE_DLY_CTRL_SHIFT_4D;
return phy;
}
static u32 get_phy_ctrl_1_intelliphy_4d5(u32 freq, u8 cl)
{
u32 phy = EMIF_DDR_PHY_CTRL_1_BASE_VAL_INTELLIPHY, half_delay;
if (freq >= 265000000 && freq < 267000000)
half_delay = 0;
else
half_delay = 1;
phy |= half_delay << DLL_HALF_DELAY_SHIFT_4D5;
phy |= ((cl + DIV_ROUND_UP(EMIF_PHY_TOTAL_READ_LATENCY_INTELLIPHY_PS,
t_ck) - 1) << READ_LATENCY_SHIFT_4D5);
return phy;
}
static u32 get_ext_phy_ctrl_2_intelliphy_4d5(void)
{
u32 fifo_we_slave_ratio;
fifo_we_slave_ratio = DIV_ROUND_CLOSEST(
EMIF_INTELLI_PHY_DQS_GATE_OPENING_DELAY_PS * 256 , t_ck);
return fifo_we_slave_ratio | fifo_we_slave_ratio << 11 |
fifo_we_slave_ratio << 22;
}
static u32 get_ext_phy_ctrl_3_intelliphy_4d5(void)
{
u32 fifo_we_slave_ratio;
fifo_we_slave_ratio = DIV_ROUND_CLOSEST(
EMIF_INTELLI_PHY_DQS_GATE_OPENING_DELAY_PS * 256 , t_ck);
return fifo_we_slave_ratio >> 10 | fifo_we_slave_ratio << 1 |
fifo_we_slave_ratio << 12 | fifo_we_slave_ratio << 23;
}
static u32 get_ext_phy_ctrl_4_intelliphy_4d5(void)
{
u32 fifo_we_slave_ratio;
fifo_we_slave_ratio = DIV_ROUND_CLOSEST(
EMIF_INTELLI_PHY_DQS_GATE_OPENING_DELAY_PS * 256 , t_ck);
return fifo_we_slave_ratio >> 9 | fifo_we_slave_ratio << 2 |
fifo_we_slave_ratio << 13;
}
static u32 get_pwr_mgmt_ctrl(u32 freq, struct emif_data *emif, u32 ip_rev)
{
u32 pwr_mgmt_ctrl = 0, timeout;
u32 lpmode = EMIF_LP_MODE_SELF_REFRESH;
u32 timeout_perf = EMIF_LP_MODE_TIMEOUT_PERFORMANCE;
u32 timeout_pwr = EMIF_LP_MODE_TIMEOUT_POWER;
u32 freq_threshold = EMIF_LP_MODE_FREQ_THRESHOLD;
u32 mask;
u8 shift;
struct emif_custom_configs *cust_cfgs = emif->plat_data->custom_configs;
if (cust_cfgs && (cust_cfgs->mask & EMIF_CUSTOM_CONFIG_LPMODE)) {
lpmode = cust_cfgs->lpmode;
timeout_perf = cust_cfgs->lpmode_timeout_performance;
timeout_pwr = cust_cfgs->lpmode_timeout_power;
freq_threshold = cust_cfgs->lpmode_freq_threshold;
}
timeout = freq >= freq_threshold ? timeout_perf : timeout_pwr;
if (timeout < 16) {
timeout = 0;
} else {
if (timeout & (timeout - 1))
timeout <<= 1;
timeout = __fls(timeout) - 3;
}
switch (lpmode) {
case EMIF_LP_MODE_CLOCK_STOP:
shift = CS_TIM_SHIFT;
mask = CS_TIM_MASK;
break;
case EMIF_LP_MODE_SELF_REFRESH:
if (timeout < 6)
timeout = 6;
shift = SR_TIM_SHIFT;
mask = SR_TIM_MASK;
break;
case EMIF_LP_MODE_PWR_DN:
shift = PD_TIM_SHIFT;
mask = PD_TIM_MASK;
break;
case EMIF_LP_MODE_DISABLE:
default:
mask = 0;
shift = 0;
break;
}
if (lpmode != EMIF_LP_MODE_DISABLE && timeout > mask >> shift) {
pr_err("TIMEOUT Overflow - lpmode=%d perf=%d pwr=%d freq=%d\n",
lpmode,
timeout_perf,
timeout_pwr,
freq_threshold);
WARN(1, "timeout=0x%02x greater than 0x%02x. Using max\n",
timeout, mask >> shift);
timeout = mask >> shift;
}
pwr_mgmt_ctrl = (timeout << shift) & mask;
pwr_mgmt_ctrl |= (SR_TIM_MASK | CS_TIM_MASK | PD_TIM_MASK) &
~mask;
if (ip_rev == EMIF_4D5)
pwr_mgmt_ctrl &= ~CS_TIM_MASK;
pwr_mgmt_ctrl |= lpmode << LP_MODE_SHIFT;
return pwr_mgmt_ctrl;
}
static void get_temperature_level(struct emif_data *emif)
{
u32 temp, temperature_level;
void __iomem *base;
base = emif->base;
writel(DDR_MR4, base + EMIF_LPDDR2_MODE_REG_CONFIG);
temperature_level = readl(base + EMIF_LPDDR2_MODE_REG_DATA);
temperature_level = (temperature_level & MR4_SDRAM_REF_RATE_MASK) >>
MR4_SDRAM_REF_RATE_SHIFT;
if (emif->plat_data->device_info->cs1_used) {
writel(DDR_MR4 | CS_MASK, base + EMIF_LPDDR2_MODE_REG_CONFIG);
temp = readl(base + EMIF_LPDDR2_MODE_REG_DATA);
temp = (temp & MR4_SDRAM_REF_RATE_MASK)
>> MR4_SDRAM_REF_RATE_SHIFT;
temperature_level = max(temp, temperature_level);
}
if (unlikely(temperature_level < SDRAM_TEMP_NOMINAL))
temperature_level = SDRAM_TEMP_NOMINAL;
if (likely(temperature_level != SDRAM_TEMP_RESERVED_4))
emif->temperature_level = temperature_level;
}
static void setup_registers(struct emif_data *emif, struct emif_regs *regs)
{
void __iomem *base = emif->base;
writel(regs->sdram_tim2_shdw, base + EMIF_SDRAM_TIMING_2_SHDW);
writel(regs->phy_ctrl_1_shdw, base + EMIF_DDR_PHY_CTRL_1_SHDW);
writel(regs->pwr_mgmt_ctrl_shdw,
base + EMIF_POWER_MANAGEMENT_CTRL_SHDW);
if (emif->plat_data->ip_rev != EMIF_4D5)
return;
writel(regs->ext_phy_ctrl_2_shdw, base + EMIF_EXT_PHY_CTRL_2_SHDW);
writel(regs->ext_phy_ctrl_3_shdw, base + EMIF_EXT_PHY_CTRL_3_SHDW);
writel(regs->ext_phy_ctrl_4_shdw, base + EMIF_EXT_PHY_CTRL_4_SHDW);
}
static void setup_volt_sensitive_regs(struct emif_data *emif,
struct emif_regs *regs, u32 volt_state)
{
u32 calib_ctrl;
void __iomem *base = emif->base;
if (volt_state == DDR_VOLTAGE_RAMPING)
calib_ctrl = regs->dll_calib_ctrl_shdw_volt_ramp;
else
calib_ctrl = regs->dll_calib_ctrl_shdw_normal;
writel(calib_ctrl, base + EMIF_DLL_CALIB_CTRL_SHDW);
}
static void setup_temperature_sensitive_regs(struct emif_data *emif,
struct emif_regs *regs)
{
u32 tim1, tim3, ref_ctrl, type;
void __iomem *base = emif->base;
u32 temperature;
type = emif->plat_data->device_info->type;
tim1 = regs->sdram_tim1_shdw;
tim3 = regs->sdram_tim3_shdw;
ref_ctrl = regs->ref_ctrl_shdw;
if (type != DDR_TYPE_LPDDR2_S2 && type != DDR_TYPE_LPDDR2_S4)
goto out;
temperature = emif->temperature_level;
if (temperature == SDRAM_TEMP_HIGH_DERATE_REFRESH) {
ref_ctrl = regs->ref_ctrl_shdw_derated;
} else if (temperature == SDRAM_TEMP_HIGH_DERATE_REFRESH_AND_TIMINGS) {
tim1 = regs->sdram_tim1_shdw_derated;
tim3 = regs->sdram_tim3_shdw_derated;
ref_ctrl = regs->ref_ctrl_shdw_derated;
}
out:
writel(tim1, base + EMIF_SDRAM_TIMING_1_SHDW);
writel(tim3, base + EMIF_SDRAM_TIMING_3_SHDW);
writel(ref_ctrl, base + EMIF_SDRAM_REFRESH_CTRL_SHDW);
}
static irqreturn_t handle_temp_alert(void __iomem *base, struct emif_data *emif)
{
u32 old_temp_level;
irqreturn_t ret = IRQ_HANDLED;
struct emif_custom_configs *custom_configs;
spin_lock_irqsave(&emif_lock, irq_state);
old_temp_level = emif->temperature_level;
get_temperature_level(emif);
if (unlikely(emif->temperature_level == old_temp_level)) {
goto out;
} else if (!emif->curr_regs) {
dev_err(emif->dev, "temperature alert before registers are calculated, not de-rating timings\n");
goto out;
}
custom_configs = emif->plat_data->custom_configs;
if (custom_configs && !(custom_configs->mask &
EMIF_CUSTOM_CONFIG_EXTENDED_TEMP_PART)) {
if (emif->temperature_level >= SDRAM_TEMP_HIGH_DERATE_REFRESH) {
dev_err(emif->dev,
"%s:NOT Extended temperature capable memory."
"Converting MR4=0x%02x as shutdown event\n",
__func__, emif->temperature_level);
emif->temperature_level = SDRAM_TEMP_VERY_HIGH_SHUTDOWN;
ret = IRQ_WAKE_THREAD;
goto out;
}
}
if (emif->temperature_level < old_temp_level ||
emif->temperature_level == SDRAM_TEMP_VERY_HIGH_SHUTDOWN) {
ret = IRQ_WAKE_THREAD;
} else {
setup_temperature_sensitive_regs(emif, emif->curr_regs);
do_freq_update();
}
out:
spin_unlock_irqrestore(&emif_lock, irq_state);
return ret;
}
static irqreturn_t emif_interrupt_handler(int irq, void *dev_id)
{
u32 interrupts;
struct emif_data *emif = dev_id;
void __iomem *base = emif->base;
struct device *dev = emif->dev;
irqreturn_t ret = IRQ_HANDLED;
interrupts = readl(base + EMIF_SYSTEM_OCP_INTERRUPT_STATUS);
writel(interrupts, base + EMIF_SYSTEM_OCP_INTERRUPT_STATUS);
if (interrupts & TA_SYS_MASK)
ret = handle_temp_alert(base, emif);
if (interrupts & ERR_SYS_MASK)
dev_err(dev, "Access error from SYS port - %x\n", interrupts);
if (emif->plat_data->hw_caps & EMIF_HW_CAPS_LL_INTERFACE) {
interrupts = readl(base + EMIF_LL_OCP_INTERRUPT_STATUS);
writel(interrupts, base + EMIF_LL_OCP_INTERRUPT_STATUS);
if (interrupts & ERR_LL_MASK)
dev_err(dev, "Access error from LL port - %x\n",
interrupts);
}
return ret;
}
static irqreturn_t emif_threaded_isr(int irq, void *dev_id)
{
struct emif_data *emif = dev_id;
if (emif->temperature_level == SDRAM_TEMP_VERY_HIGH_SHUTDOWN) {
dev_emerg(emif->dev, "SDRAM temperature exceeds operating limit.. Needs shut down!!!\n");
if (pm_power_off) {
kernel_power_off();
} else {
WARN(1, "FIXME: NO pm_power_off!!! trying restart\n");
kernel_restart("SDRAM Over-temp Emergency restart");
}
return IRQ_HANDLED;
}
spin_lock_irqsave(&emif_lock, irq_state);
if (emif->curr_regs) {
setup_temperature_sensitive_regs(emif, emif->curr_regs);
do_freq_update();
} else {
dev_err(emif->dev, "temperature alert before registers are calculated, not de-rating timings\n");
}
spin_unlock_irqrestore(&emif_lock, irq_state);
return IRQ_HANDLED;
}
static void clear_all_interrupts(struct emif_data *emif)
{
void __iomem *base = emif->base;
writel(readl(base + EMIF_SYSTEM_OCP_INTERRUPT_STATUS),
base + EMIF_SYSTEM_OCP_INTERRUPT_STATUS);
if (emif->plat_data->hw_caps & EMIF_HW_CAPS_LL_INTERFACE)
writel(readl(base + EMIF_LL_OCP_INTERRUPT_STATUS),
base + EMIF_LL_OCP_INTERRUPT_STATUS);
}
static void disable_and_clear_all_interrupts(struct emif_data *emif)
{
void __iomem *base = emif->base;
writel(readl(base + EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_SET),
base + EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_CLEAR);
if (emif->plat_data->hw_caps & EMIF_HW_CAPS_LL_INTERFACE)
writel(readl(base + EMIF_LL_OCP_INTERRUPT_ENABLE_SET),
base + EMIF_LL_OCP_INTERRUPT_ENABLE_CLEAR);
clear_all_interrupts(emif);
}
static int __init_or_module setup_interrupts(struct emif_data *emif, u32 irq)
{
u32 interrupts, type;
void __iomem *base = emif->base;
type = emif->plat_data->device_info->type;
clear_all_interrupts(emif);
interrupts = EN_ERR_SYS_MASK;
if (type == DDR_TYPE_LPDDR2_S2 || type == DDR_TYPE_LPDDR2_S4)
interrupts |= EN_TA_SYS_MASK;
writel(interrupts, base + EMIF_SYSTEM_OCP_INTERRUPT_ENABLE_SET);
if (emif->plat_data->hw_caps & EMIF_HW_CAPS_LL_INTERFACE) {
interrupts = EN_ERR_LL_MASK;
writel(interrupts, base + EMIF_LL_OCP_INTERRUPT_ENABLE_SET);
}
return devm_request_threaded_irq(emif->dev, irq,
emif_interrupt_handler,
emif_threaded_isr,
0, dev_name(emif->dev),
emif);
}
static void __init_or_module emif_onetime_settings(struct emif_data *emif)
{
u32 pwr_mgmt_ctrl, zq, temp_alert_cfg;
void __iomem *base = emif->base;
const struct lpddr2_addressing *addressing;
const struct ddr_device_info *device_info;
device_info = emif->plat_data->device_info;
addressing = get_addressing_table(device_info);
pwr_mgmt_ctrl = get_pwr_mgmt_ctrl(1000000000, emif,
emif->plat_data->ip_rev);
emif->lpmode = (pwr_mgmt_ctrl & LP_MODE_MASK) >> LP_MODE_SHIFT;
writel(pwr_mgmt_ctrl, base + EMIF_POWER_MANAGEMENT_CONTROL);
zq = get_zq_config_reg(addressing, device_info->cs1_used,
device_info->cal_resistors_per_cs);
writel(zq, base + EMIF_SDRAM_OUTPUT_IMPEDANCE_CALIBRATION_CONFIG);
get_temperature_level(emif);
if (emif->temperature_level == SDRAM_TEMP_VERY_HIGH_SHUTDOWN)
dev_emerg(emif->dev, "SDRAM temperature exceeds operating limit.. Needs shut down!!!\n");
temp_alert_cfg = get_temp_alert_config(addressing,
emif->plat_data->custom_configs, device_info->cs1_used,
device_info->io_width, get_emif_bus_width(emif));
writel(temp_alert_cfg, base + EMIF_TEMPERATURE_ALERT_CONFIG);
if (emif->plat_data->phy_type != EMIF_PHY_TYPE_INTELLIPHY)
return;
writel(EMIF_EXT_PHY_CTRL_1_VAL, base + EMIF_EXT_PHY_CTRL_1_SHDW);
writel(EMIF_EXT_PHY_CTRL_5_VAL, base + EMIF_EXT_PHY_CTRL_5_SHDW);
writel(EMIF_EXT_PHY_CTRL_6_VAL, base + EMIF_EXT_PHY_CTRL_6_SHDW);
writel(EMIF_EXT_PHY_CTRL_7_VAL, base + EMIF_EXT_PHY_CTRL_7_SHDW);
writel(EMIF_EXT_PHY_CTRL_8_VAL, base + EMIF_EXT_PHY_CTRL_8_SHDW);
writel(EMIF_EXT_PHY_CTRL_9_VAL, base + EMIF_EXT_PHY_CTRL_9_SHDW);
writel(EMIF_EXT_PHY_CTRL_10_VAL, base + EMIF_EXT_PHY_CTRL_10_SHDW);
writel(EMIF_EXT_PHY_CTRL_11_VAL, base + EMIF_EXT_PHY_CTRL_11_SHDW);
writel(EMIF_EXT_PHY_CTRL_12_VAL, base + EMIF_EXT_PHY_CTRL_12_SHDW);
writel(EMIF_EXT_PHY_CTRL_13_VAL, base + EMIF_EXT_PHY_CTRL_13_SHDW);
writel(EMIF_EXT_PHY_CTRL_14_VAL, base + EMIF_EXT_PHY_CTRL_14_SHDW);
writel(EMIF_EXT_PHY_CTRL_15_VAL, base + EMIF_EXT_PHY_CTRL_15_SHDW);
writel(EMIF_EXT_PHY_CTRL_16_VAL, base + EMIF_EXT_PHY_CTRL_16_SHDW);
writel(EMIF_EXT_PHY_CTRL_17_VAL, base + EMIF_EXT_PHY_CTRL_17_SHDW);
writel(EMIF_EXT_PHY_CTRL_18_VAL, base + EMIF_EXT_PHY_CTRL_18_SHDW);
writel(EMIF_EXT_PHY_CTRL_19_VAL, base + EMIF_EXT_PHY_CTRL_19_SHDW);
writel(EMIF_EXT_PHY_CTRL_20_VAL, base + EMIF_EXT_PHY_CTRL_20_SHDW);
writel(EMIF_EXT_PHY_CTRL_21_VAL, base + EMIF_EXT_PHY_CTRL_21_SHDW);
writel(EMIF_EXT_PHY_CTRL_22_VAL, base + EMIF_EXT_PHY_CTRL_22_SHDW);
writel(EMIF_EXT_PHY_CTRL_23_VAL, base + EMIF_EXT_PHY_CTRL_23_SHDW);
writel(EMIF_EXT_PHY_CTRL_24_VAL, base + EMIF_EXT_PHY_CTRL_24_SHDW);
}
static void get_default_timings(struct emif_data *emif)
{
struct emif_platform_data *pd = emif->plat_data;
pd->timings = lpddr2_jedec_timings;
pd->timings_arr_size = ARRAY_SIZE(lpddr2_jedec_timings);
dev_warn(emif->dev, "%s: using default timings\n", __func__);
}
static int is_dev_data_valid(u32 type, u32 density, u32 io_width, u32 phy_type,
u32 ip_rev, struct device *dev)
{
int valid;
valid = (type == DDR_TYPE_LPDDR2_S4 ||
type == DDR_TYPE_LPDDR2_S2)
&& (density >= DDR_DENSITY_64Mb
&& density <= DDR_DENSITY_8Gb)
&& (io_width >= DDR_IO_WIDTH_8
&& io_width <= DDR_IO_WIDTH_32);
switch (ip_rev) {
case EMIF_4D:
valid = valid && (phy_type == EMIF_PHY_TYPE_ATTILAPHY);
break;
case EMIF_4D5:
valid = valid && (phy_type == EMIF_PHY_TYPE_INTELLIPHY);
break;
default:
valid = 0;
}
if (!valid)
dev_err(dev, "%s: invalid DDR details\n", __func__);
return valid;
}
static int is_custom_config_valid(struct emif_custom_configs *cust_cfgs,
struct device *dev)
{
int valid = 1;
if ((cust_cfgs->mask & EMIF_CUSTOM_CONFIG_LPMODE) &&
(cust_cfgs->lpmode != EMIF_LP_MODE_DISABLE))
valid = cust_cfgs->lpmode_freq_threshold &&
cust_cfgs->lpmode_timeout_performance &&
cust_cfgs->lpmode_timeout_power;
if (cust_cfgs->mask & EMIF_CUSTOM_CONFIG_TEMP_ALERT_POLL_INTERVAL)
valid = valid && cust_cfgs->temp_alert_poll_interval_ms;
if (!valid)
dev_warn(dev, "%s: invalid custom configs\n", __func__);
return valid;
}
static void __init_or_module of_get_custom_configs(struct device_node *np_emif,
struct emif_data *emif)
{
struct emif_custom_configs *cust_cfgs = NULL;
int len;
const __be32 *lpmode, *poll_intvl;
lpmode = of_get_property(np_emif, "low-power-mode", &len);
poll_intvl = of_get_property(np_emif, "temp-alert-poll-interval", &len);
if (lpmode || poll_intvl)
cust_cfgs = devm_kzalloc(emif->dev, sizeof(*cust_cfgs),
GFP_KERNEL);
if (!cust_cfgs)
return;
if (lpmode) {
cust_cfgs->mask |= EMIF_CUSTOM_CONFIG_LPMODE;
cust_cfgs->lpmode = be32_to_cpup(lpmode);
of_property_read_u32(np_emif,
"low-power-mode-timeout-performance",
&cust_cfgs->lpmode_timeout_performance);
of_property_read_u32(np_emif,
"low-power-mode-timeout-power",
&cust_cfgs->lpmode_timeout_power);
of_property_read_u32(np_emif,
"low-power-mode-freq-threshold",
&cust_cfgs->lpmode_freq_threshold);
}
if (poll_intvl) {
cust_cfgs->mask |=
EMIF_CUSTOM_CONFIG_TEMP_ALERT_POLL_INTERVAL;
cust_cfgs->temp_alert_poll_interval_ms =
be32_to_cpup(poll_intvl);
}
if (of_find_property(np_emif, "extended-temp-part", &len))
cust_cfgs->mask |= EMIF_CUSTOM_CONFIG_EXTENDED_TEMP_PART;
if (!is_custom_config_valid(cust_cfgs, emif->dev)) {
devm_kfree(emif->dev, cust_cfgs);
return;
}
emif->plat_data->custom_configs = cust_cfgs;
}
static void __init_or_module of_get_ddr_info(struct device_node *np_emif,
struct device_node *np_ddr,
struct ddr_device_info *dev_info)
{
u32 density = 0, io_width = 0;
int len;
if (of_find_property(np_emif, "cs1-used", &len))
dev_info->cs1_used = true;
if (of_find_property(np_emif, "cal-resistor-per-cs", &len))
dev_info->cal_resistors_per_cs = true;
if (of_device_is_compatible(np_ddr , "jedec,lpddr2-s4"))
dev_info->type = DDR_TYPE_LPDDR2_S4;
else if (of_device_is_compatible(np_ddr , "jedec,lpddr2-s2"))
dev_info->type = DDR_TYPE_LPDDR2_S2;
of_property_read_u32(np_ddr, "density", &density);
of_property_read_u32(np_ddr, "io-width", &io_width);
if (density & (density - 1))
dev_info->density = 0;
else
dev_info->density = __fls(density) - 5;
if (io_width & (io_width - 1))
dev_info->io_width = 0;
else
dev_info->io_width = __fls(io_width) - 1;
}
static struct emif_data * __init_or_module of_get_memory_device_details(
struct device_node *np_emif, struct device *dev)
{
struct emif_data *emif = NULL;
struct ddr_device_info *dev_info = NULL;
struct emif_platform_data *pd = NULL;
struct device_node *np_ddr;
int len;
np_ddr = of_parse_phandle(np_emif, "device-handle", 0);
if (!np_ddr)
goto error;
emif = devm_kzalloc(dev, sizeof(struct emif_data), GFP_KERNEL);
pd = devm_kzalloc(dev, sizeof(*pd), GFP_KERNEL);
dev_info = devm_kzalloc(dev, sizeof(*dev_info), GFP_KERNEL);
if (!emif || !pd || !dev_info) {
dev_err(dev, "%s: Out of memory!!\n",
__func__);
goto error;
}
emif->plat_data = pd;
pd->device_info = dev_info;
emif->dev = dev;
emif->np_ddr = np_ddr;
emif->temperature_level = SDRAM_TEMP_NOMINAL;
if (of_device_is_compatible(np_emif, "ti,emif-4d"))
emif->plat_data->ip_rev = EMIF_4D;
else if (of_device_is_compatible(np_emif, "ti,emif-4d5"))
emif->plat_data->ip_rev = EMIF_4D5;
of_property_read_u32(np_emif, "phy-type", &pd->phy_type);
if (of_find_property(np_emif, "hw-caps-ll-interface", &len))
pd->hw_caps |= EMIF_HW_CAPS_LL_INTERFACE;
of_get_ddr_info(np_emif, np_ddr, dev_info);
if (!is_dev_data_valid(pd->device_info->type, pd->device_info->density,
pd->device_info->io_width, pd->phy_type, pd->ip_rev,
emif->dev)) {
dev_err(dev, "%s: invalid device data!!\n", __func__);
goto error;
}
if (emif1 && emif1->np_ddr == np_ddr) {
emif->duplicate = true;
goto out;
} else if (emif1) {
dev_warn(emif->dev, "%s: Non-symmetric DDR geometry\n",
__func__);
}
of_get_custom_configs(np_emif, emif);
emif->plat_data->timings = of_get_ddr_timings(np_ddr, emif->dev,
emif->plat_data->device_info->type,
&emif->plat_data->timings_arr_size);
emif->plat_data->min_tck = of_get_min_tck(np_ddr, emif->dev);
goto out;
error:
return NULL;
out:
return emif;
}
static struct emif_data * __init_or_module of_get_memory_device_details(
struct device_node *np_emif, struct device *dev)
{
return NULL;
}
static struct emif_data *__init_or_module get_device_details(
struct platform_device *pdev)
{
u32 size;
struct emif_data *emif = NULL;
struct ddr_device_info *dev_info;
struct emif_custom_configs *cust_cfgs;
struct emif_platform_data *pd;
struct device *dev;
void *temp;
pd = pdev->dev.platform_data;
dev = &pdev->dev;
if (!(pd && pd->device_info && is_dev_data_valid(pd->device_info->type,
pd->device_info->density, pd->device_info->io_width,
pd->phy_type, pd->ip_rev, dev))) {
dev_err(dev, "%s: invalid device data\n", __func__);
goto error;
}
emif = devm_kzalloc(dev, sizeof(*emif), GFP_KERNEL);
temp = devm_kzalloc(dev, sizeof(*pd), GFP_KERNEL);
dev_info = devm_kzalloc(dev, sizeof(*dev_info), GFP_KERNEL);
if (!emif || !pd || !dev_info) {
dev_err(dev, "%s:%d: allocation error\n", __func__, __LINE__);
goto error;
}
memcpy(temp, pd, sizeof(*pd));
pd = temp;
memcpy(dev_info, pd->device_info, sizeof(*dev_info));
pd->device_info = dev_info;
emif->plat_data = pd;
emif->dev = dev;
emif->temperature_level = SDRAM_TEMP_NOMINAL;
emif->duplicate = emif1 && (memcmp(dev_info,
emif1->plat_data->device_info,
sizeof(struct ddr_device_info)) == 0);
if (emif->duplicate) {
pd->timings = NULL;
pd->min_tck = NULL;
goto out;
} else if (emif1) {
dev_warn(emif->dev, "%s: Non-symmetric DDR geometry\n",
__func__);
}
cust_cfgs = pd->custom_configs;
if (cust_cfgs && is_custom_config_valid(cust_cfgs, dev)) {
temp = devm_kzalloc(dev, sizeof(*cust_cfgs), GFP_KERNEL);
if (temp)
memcpy(temp, cust_cfgs, sizeof(*cust_cfgs));
else
dev_warn(dev, "%s:%d: allocation error\n", __func__,
__LINE__);
pd->custom_configs = temp;
}
size = sizeof(struct lpddr2_timings) * pd->timings_arr_size;
if (pd->timings) {
temp = devm_kzalloc(dev, size, GFP_KERNEL);
if (temp) {
memcpy(temp, pd->timings, size);
pd->timings = temp;
} else {
dev_warn(dev, "%s:%d: allocation error\n", __func__,
__LINE__);
get_default_timings(emif);
}
} else {
get_default_timings(emif);
}
if (pd->min_tck) {
temp = devm_kzalloc(dev, sizeof(*pd->min_tck), GFP_KERNEL);
if (temp) {
memcpy(temp, pd->min_tck, sizeof(*pd->min_tck));
pd->min_tck = temp;
} else {
dev_warn(dev, "%s:%d: allocation error\n", __func__,
__LINE__);
pd->min_tck = &lpddr2_jedec_min_tck;
}
} else {
pd->min_tck = &lpddr2_jedec_min_tck;
}
out:
return emif;
error:
return NULL;
}
static int __init_or_module emif_probe(struct platform_device *pdev)
{
struct emif_data *emif;
struct resource *res;
int irq;
if (pdev->dev.of_node)
emif = of_get_memory_device_details(pdev->dev.of_node, &pdev->dev);
else
emif = get_device_details(pdev);
if (!emif) {
pr_err("%s: error getting device data\n", __func__);
goto error;
}
list_add(&emif->node, &device_list);
emif->addressing = get_addressing_table(emif->plat_data->device_info);
emif->dev = &pdev->dev;
platform_set_drvdata(pdev, emif);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
emif->base = devm_ioremap_resource(emif->dev, res);
if (IS_ERR(emif->base))
goto error;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(emif->dev, "%s: error getting IRQ resource - %d\n",
__func__, irq);
goto error;
}
emif_onetime_settings(emif);
emif_debugfs_init(emif);
disable_and_clear_all_interrupts(emif);
setup_interrupts(emif, irq);
if (!emif1) {
emif1 = emif;
spin_lock_init(&emif_lock);
}
dev_info(&pdev->dev, "%s: device configured with addr = %p and IRQ%d\n",
__func__, emif->base, irq);
return 0;
error:
return -ENODEV;
}
static int __exit emif_remove(struct platform_device *pdev)
{
struct emif_data *emif = platform_get_drvdata(pdev);
emif_debugfs_exit(emif);
return 0;
}
static void emif_shutdown(struct platform_device *pdev)
{
struct emif_data *emif = platform_get_drvdata(pdev);
disable_and_clear_all_interrupts(emif);
}
static int get_emif_reg_values(struct emif_data *emif, u32 freq,
struct emif_regs *regs)
{
u32 cs1_used, ip_rev, phy_type;
u32 cl, type;
const struct lpddr2_timings *timings;
const struct lpddr2_min_tck *min_tck;
const struct ddr_device_info *device_info;
const struct lpddr2_addressing *addressing;
struct emif_data *emif_for_calc;
struct device *dev;
const struct emif_custom_configs *custom_configs;
dev = emif->dev;
emif_for_calc = emif->duplicate ? emif1 : emif;
timings = get_timings_table(emif_for_calc, freq);
addressing = emif_for_calc->addressing;
if (!timings || !addressing) {
dev_err(dev, "%s: not enough data available for %dHz",
__func__, freq);
return -1;
}
device_info = emif_for_calc->plat_data->device_info;
type = device_info->type;
cs1_used = device_info->cs1_used;
ip_rev = emif_for_calc->plat_data->ip_rev;
phy_type = emif_for_calc->plat_data->phy_type;
min_tck = emif_for_calc->plat_data->min_tck;
custom_configs = emif_for_calc->plat_data->custom_configs;
set_ddr_clk_period(freq);
regs->ref_ctrl_shdw = get_sdram_ref_ctrl_shdw(freq, addressing);
regs->sdram_tim1_shdw = get_sdram_tim_1_shdw(timings, min_tck,
addressing);
regs->sdram_tim2_shdw = get_sdram_tim_2_shdw(timings, min_tck,
addressing, type);
regs->sdram_tim3_shdw = get_sdram_tim_3_shdw(timings, min_tck,
addressing, type, ip_rev, EMIF_NORMAL_TIMINGS);
cl = get_cl(emif);
if (phy_type == EMIF_PHY_TYPE_ATTILAPHY && ip_rev == EMIF_4D) {
regs->phy_ctrl_1_shdw = get_ddr_phy_ctrl_1_attilaphy_4d(
timings, freq, cl);
} else if (phy_type == EMIF_PHY_TYPE_INTELLIPHY && ip_rev == EMIF_4D5) {
regs->phy_ctrl_1_shdw = get_phy_ctrl_1_intelliphy_4d5(freq, cl);
regs->ext_phy_ctrl_2_shdw = get_ext_phy_ctrl_2_intelliphy_4d5();
regs->ext_phy_ctrl_3_shdw = get_ext_phy_ctrl_3_intelliphy_4d5();
regs->ext_phy_ctrl_4_shdw = get_ext_phy_ctrl_4_intelliphy_4d5();
} else {
return -1;
}
regs->pwr_mgmt_ctrl_shdw =
get_pwr_mgmt_ctrl(freq, emif_for_calc, ip_rev) &
(CS_TIM_MASK | SR_TIM_MASK | PD_TIM_MASK);
if (ip_rev & EMIF_4D) {
regs->read_idle_ctrl_shdw_normal =
get_read_idle_ctrl_shdw(DDR_VOLTAGE_STABLE);
regs->read_idle_ctrl_shdw_volt_ramp =
get_read_idle_ctrl_shdw(DDR_VOLTAGE_RAMPING);
} else if (ip_rev & EMIF_4D5) {
regs->dll_calib_ctrl_shdw_normal =
get_dll_calib_ctrl_shdw(DDR_VOLTAGE_STABLE);
regs->dll_calib_ctrl_shdw_volt_ramp =
get_dll_calib_ctrl_shdw(DDR_VOLTAGE_RAMPING);
}
if (type == DDR_TYPE_LPDDR2_S2 || type == DDR_TYPE_LPDDR2_S4) {
regs->ref_ctrl_shdw_derated = get_sdram_ref_ctrl_shdw(freq / 4,
addressing);
regs->sdram_tim1_shdw_derated =
get_sdram_tim_1_shdw_derated(timings, min_tck,
addressing);
regs->sdram_tim3_shdw_derated = get_sdram_tim_3_shdw(timings,
min_tck, addressing, type, ip_rev,
EMIF_DERATED_TIMINGS);
}
regs->freq = freq;
return 0;
}
static struct emif_regs *get_regs(struct emif_data *emif, u32 freq)
{
int i;
struct emif_regs **regs_cache;
struct emif_regs *regs = NULL;
struct device *dev;
dev = emif->dev;
if (emif->curr_regs && emif->curr_regs->freq == freq) {
dev_dbg(dev, "%s: using curr_regs - %u Hz", __func__, freq);
return emif->curr_regs;
}
if (emif->duplicate)
regs_cache = emif1->regs_cache;
else
regs_cache = emif->regs_cache;
for (i = 0; i < EMIF_MAX_NUM_FREQUENCIES && regs_cache[i]; i++) {
if (regs_cache[i]->freq == freq) {
regs = regs_cache[i];
dev_dbg(dev,
"%s: reg dump found in reg cache for %u Hz\n",
__func__, freq);
break;
}
}
if (!regs) {
regs = devm_kzalloc(emif->dev, sizeof(*regs), GFP_ATOMIC);
if (!regs)
return NULL;
if (get_emif_reg_values(emif, freq, regs)) {
devm_kfree(emif->dev, regs);
return NULL;
}
for (i = 0; i < EMIF_MAX_NUM_FREQUENCIES && regs_cache[i]; i++)
;
if (i >= EMIF_MAX_NUM_FREQUENCIES) {
dev_warn(dev, "%s: regs_cache full - reusing a slot!!\n",
__func__);
i = EMIF_MAX_NUM_FREQUENCIES - 1;
devm_kfree(emif->dev, regs_cache[i]);
}
regs_cache[i] = regs;
}
return regs;
}
static void do_volt_notify_handling(struct emif_data *emif, u32 volt_state)
{
dev_dbg(emif->dev, "%s: voltage notification : %d", __func__,
volt_state);
if (!emif->curr_regs) {
dev_err(emif->dev,
"%s: volt-notify before registers are ready: %d\n",
__func__, volt_state);
return;
}
setup_volt_sensitive_regs(emif, emif->curr_regs, volt_state);
}
static void do_freq_pre_notify_handling(struct emif_data *emif, u32 new_freq)
{
struct emif_regs *regs;
regs = get_regs(emif, new_freq);
if (!regs)
return;
emif->curr_regs = regs;
dev_dbg(emif->dev, "%s: setting up shadow registers for %uHz",
__func__, new_freq);
setup_registers(emif, regs);
setup_temperature_sensitive_regs(emif, regs);
setup_volt_sensitive_regs(emif, regs, DDR_VOLTAGE_STABLE);
if (emif->lpmode == EMIF_LP_MODE_SELF_REFRESH)
set_lpmode(emif, EMIF_LP_MODE_DISABLE);
}
static void do_freq_post_notify_handling(struct emif_data *emif)
{
if (emif->lpmode == EMIF_LP_MODE_SELF_REFRESH)
set_lpmode(emif, EMIF_LP_MODE_SELF_REFRESH);
}
