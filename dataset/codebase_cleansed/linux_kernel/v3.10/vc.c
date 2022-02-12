static int omap_vc_config_channel(struct voltagedomain *voltdm)
{
struct omap_vc_channel *vc = voltdm->vc;
if (vc->flags & OMAP_VC_CHANNEL_DEFAULT)
vc->cfg_channel &= vc_cfg_bits->racen;
voltdm->rmw(CFG_CHANNEL_MASK << vc->cfg_channel_sa_shift,
vc->cfg_channel << vc->cfg_channel_sa_shift,
vc->cfg_channel_reg);
return 0;
}
int omap_vc_pre_scale(struct voltagedomain *voltdm,
unsigned long target_volt,
u8 *target_vsel, u8 *current_vsel)
{
struct omap_vc_channel *vc = voltdm->vc;
u32 vc_cmdval;
if (!voltdm->pmic) {
pr_err("%s: Insufficient pmic info to scale the vdd_%s\n",
__func__, voltdm->name);
return -EINVAL;
}
if (!voltdm->pmic->uv_to_vsel) {
pr_err("%s: PMIC function to convert voltage in uV to vsel not registered. Hence unable to scale voltage for vdd_%s\n",
__func__, voltdm->name);
return -ENODATA;
}
if (!voltdm->read || !voltdm->write) {
pr_err("%s: No read/write API for accessing vdd_%s regs\n",
__func__, voltdm->name);
return -EINVAL;
}
*target_vsel = voltdm->pmic->uv_to_vsel(target_volt);
*current_vsel = voltdm->pmic->uv_to_vsel(voltdm->nominal_volt);
vc_cmdval = voltdm->read(vc->cmdval_reg);
vc_cmdval &= ~vc->common->cmd_on_mask;
vc_cmdval |= (*target_vsel << vc->common->cmd_on_shift);
voltdm->write(vc_cmdval, vc->cmdval_reg);
voltdm->vc_param->on = target_volt;
omap_vp_update_errorgain(voltdm, target_volt);
return 0;
}
void omap_vc_post_scale(struct voltagedomain *voltdm,
unsigned long target_volt,
u8 target_vsel, u8 current_vsel)
{
u32 smps_steps = 0, smps_delay = 0;
smps_steps = abs(target_vsel - current_vsel);
smps_delay = ((smps_steps * voltdm->pmic->step_size) /
voltdm->pmic->slew_rate) + 2;
udelay(smps_delay);
}
int omap_vc_bypass_scale(struct voltagedomain *voltdm,
unsigned long target_volt)
{
struct omap_vc_channel *vc = voltdm->vc;
u32 loop_cnt = 0, retries_cnt = 0;
u32 vc_valid, vc_bypass_val_reg, vc_bypass_value;
u8 target_vsel, current_vsel;
int ret;
ret = omap_vc_pre_scale(voltdm, target_volt, &target_vsel, &current_vsel);
if (ret)
return ret;
vc_valid = vc->common->valid;
vc_bypass_val_reg = vc->common->bypass_val_reg;
vc_bypass_value = (target_vsel << vc->common->data_shift) |
(vc->volt_reg_addr << vc->common->regaddr_shift) |
(vc->i2c_slave_addr << vc->common->slaveaddr_shift);
voltdm->write(vc_bypass_value, vc_bypass_val_reg);
voltdm->write(vc_bypass_value | vc_valid, vc_bypass_val_reg);
vc_bypass_value = voltdm->read(vc_bypass_val_reg);
while (!(vc_bypass_value & vc_valid)) {
loop_cnt++;
if (retries_cnt > 10) {
pr_warning("%s: Retry count exceeded\n", __func__);
return -ETIMEDOUT;
}
if (loop_cnt > 50) {
retries_cnt++;
loop_cnt = 0;
udelay(10);
}
vc_bypass_value = voltdm->read(vc_bypass_val_reg);
}
omap_vc_post_scale(voltdm, target_volt, target_vsel, current_vsel);
return 0;
}
static inline u32 omap_usec_to_32k(u32 usec)
{
return DIV_ROUND_UP_ULL(32768ULL * (u64)usec, 1000000ULL);
}
static void omap3_set_clksetup(u32 usec, struct voltagedomain *voltdm)
{
voltdm->write(omap_usec_to_32k(usec), OMAP3_PRM_CLKSETUP_OFFSET);
}
static void omap3_set_i2c_timings(struct voltagedomain *voltdm, bool off_mode)
{
unsigned long voltsetup1;
u32 tgt_volt;
omap3_set_clksetup(1, voltdm);
if (off_mode)
tgt_volt = voltdm->vc_param->off;
else
tgt_volt = voltdm->vc_param->ret;
voltsetup1 = (voltdm->vc_param->on - tgt_volt) /
voltdm->pmic->slew_rate;
voltsetup1 = voltsetup1 * voltdm->sys_clk.rate / 8 / 1000000 + 1;
voltdm->rmw(voltdm->vfsm->voltsetup_mask,
voltsetup1 << __ffs(voltdm->vfsm->voltsetup_mask),
voltdm->vfsm->voltsetup_reg);
voltdm->write(0, OMAP3_PRM_VOLTSETUP2_OFFSET);
}
static void omap3_set_off_timings(struct voltagedomain *voltdm)
{
unsigned long clksetup;
unsigned long voltsetup2;
unsigned long voltsetup2_old;
u32 val;
u32 tstart, tshut;
val = voltdm->read(OMAP3_PRM_VOLTCTRL_OFFSET);
if (!(val & OMAP3430_SEL_OFF_MASK)) {
omap3_set_i2c_timings(voltdm, true);
return;
}
omap_pm_get_oscillator(&tstart, &tshut);
omap3_set_clksetup(tstart, voltdm);
clksetup = voltdm->read(OMAP3_PRM_CLKSETUP_OFFSET);
voltsetup2 = voltdm->vc_param->on / voltdm->pmic->slew_rate;
voltsetup2 = DIV_ROUND_UP(voltsetup2 * 32768, 1000000);
voltsetup2_old = voltdm->read(OMAP3_PRM_VOLTSETUP2_OFFSET);
if (voltsetup2 > voltsetup2_old) {
voltdm->write(voltsetup2, OMAP3_PRM_VOLTSETUP2_OFFSET);
voltdm->write(clksetup - voltsetup2,
OMAP3_PRM_VOLTOFFSET_OFFSET);
} else
voltdm->write(clksetup - voltsetup2_old,
OMAP3_PRM_VOLTOFFSET_OFFSET);
voltdm->rmw(voltdm->vfsm->voltsetup_mask, 0,
voltdm->vfsm->voltsetup_reg);
voltdm->write(clksetup - voltsetup2, OMAP3_PRM_VOLTOFFSET_OFFSET);
}
static void __init omap3_vc_init_channel(struct voltagedomain *voltdm)
{
omap3_set_off_timings(voltdm);
}
static u32 omap4_calc_volt_ramp(struct voltagedomain *voltdm, u32 voltage_diff)
{
u32 prescaler;
u32 cycles;
u32 time;
time = voltage_diff / voltdm->pmic->slew_rate;
cycles = voltdm->sys_clk.rate / 1000 * time / 1000;
cycles /= 64;
prescaler = 0;
if (cycles > 63) {
cycles /= 4;
prescaler++;
}
if (cycles > 63) {
cycles /= 2;
prescaler++;
}
if (cycles > 63) {
cycles /= 4;
prescaler++;
}
if (cycles > 63) {
pr_warn("%s: invalid setuptime for vdd_%s\n", __func__,
voltdm->name);
return 0;
}
cycles++;
return (prescaler << OMAP4430_RAMP_UP_PRESCAL_SHIFT) |
(cycles << OMAP4430_RAMP_UP_COUNT_SHIFT);
}
static u32 omap4_usec_to_val_scrm(u32 usec, int shift, u32 mask)
{
u32 val;
val = omap_usec_to_32k(usec) << shift;
if (val > mask)
val = mask;
return val;
}
static void omap4_set_timings(struct voltagedomain *voltdm, bool off_mode)
{
u32 val;
u32 ramp;
int offset;
u32 tstart, tshut;
if (off_mode) {
ramp = omap4_calc_volt_ramp(voltdm,
voltdm->vc_param->on - voltdm->vc_param->off);
offset = voltdm->vfsm->voltsetup_off_reg;
} else {
ramp = omap4_calc_volt_ramp(voltdm,
voltdm->vc_param->on - voltdm->vc_param->ret);
offset = voltdm->vfsm->voltsetup_reg;
}
if (!ramp)
return;
val = voltdm->read(offset);
val |= ramp << OMAP4430_RAMP_DOWN_COUNT_SHIFT;
val |= ramp << OMAP4430_RAMP_UP_COUNT_SHIFT;
voltdm->write(val, offset);
omap_pm_get_oscillator(&tstart, &tshut);
val = omap4_usec_to_val_scrm(tstart, OMAP4_SETUPTIME_SHIFT,
OMAP4_SETUPTIME_MASK);
val |= omap4_usec_to_val_scrm(tshut, OMAP4_DOWNTIME_SHIFT,
OMAP4_DOWNTIME_MASK);
__raw_writel(val, OMAP4_SCRM_CLKSETUPTIME);
}
static void __init omap4_vc_init_channel(struct voltagedomain *voltdm)
{
omap4_set_timings(voltdm, true);
omap4_set_timings(voltdm, false);
}
static void __init omap4_vc_i2c_timing_init(struct voltagedomain *voltdm)
{
u32 capacitance;
u32 val;
u16 hsscll;
const struct i2c_init_data *i2c_data;
if (!voltdm->pmic->i2c_high_speed) {
pr_warn("%s: only high speed supported!\n", __func__);
return;
}
capacitance = DIV_ROUND_UP(sr_i2c_pcb_length, 8);
capacitance += 4;
capacitance += voltdm->pmic->i2c_pad_load;
i2c_data = omap4_i2c_timing_data;
while (i2c_data->load > capacitance)
i2c_data++;
switch (voltdm->sys_clk.rate) {
case 38400000:
hsscll = i2c_data->hsscll_38_4;
break;
case 26000000:
hsscll = i2c_data->hsscll_26;
break;
case 19200000:
hsscll = i2c_data->hsscll_19_2;
break;
case 16800000:
hsscll = i2c_data->hsscll_16_8;
break;
case 12000000:
hsscll = i2c_data->hsscll_12;
break;
default:
pr_warn("%s: unsupported sysclk rate: %d!\n", __func__,
voltdm->sys_clk.rate);
return;
}
val = i2c_data->loadbits << 25 | i2c_data->loadbits << 29;
__raw_writel(val, OMAP2_L4_IO_ADDRESS(OMAP4_CTRL_MODULE_PAD_WKUP +
OMAP4_CTRL_MODULE_PAD_WKUP_CONTROL_I2C_2));
val = hsscll << OMAP4430_HSSCLL_SHIFT;
val |= (0x28 << OMAP4430_SCLL_SHIFT | 0x2c << OMAP4430_SCLH_SHIFT);
voltdm->write(val, OMAP4_PRM_VC_CFG_I2C_CLK_OFFSET);
}
static void __init omap_vc_i2c_init(struct voltagedomain *voltdm)
{
struct omap_vc_channel *vc = voltdm->vc;
static bool initialized;
static bool i2c_high_speed;
u8 mcode;
if (initialized) {
if (voltdm->pmic->i2c_high_speed != i2c_high_speed)
pr_warn("%s: I2C config for vdd_%s does not match other channels (%u).\n",
__func__, voltdm->name, i2c_high_speed);
return;
}
i2c_high_speed = voltdm->pmic->i2c_high_speed;
if (i2c_high_speed)
voltdm->rmw(vc->common->i2c_cfg_hsen_mask,
vc->common->i2c_cfg_hsen_mask,
vc->common->i2c_cfg_reg);
mcode = voltdm->pmic->i2c_mcode;
if (mcode)
voltdm->rmw(vc->common->i2c_mcode_mask,
mcode << __ffs(vc->common->i2c_mcode_mask),
vc->common->i2c_cfg_reg);
if (cpu_is_omap44xx())
omap4_vc_i2c_timing_init(voltdm);
initialized = true;
}
static u8 omap_vc_calc_vsel(struct voltagedomain *voltdm, u32 uvolt)
{
if (voltdm->pmic->vddmin > uvolt)
uvolt = voltdm->pmic->vddmin;
if (voltdm->pmic->vddmax < uvolt) {
WARN(1, "%s: voltage not supported by pmic: %u vs max %u\n",
__func__, uvolt, voltdm->pmic->vddmax);
uvolt = voltdm->pmic->vddmax;
}
return voltdm->pmic->uv_to_vsel(uvolt);
}
void __init omap_pm_setup_sr_i2c_pcb_length(u32 mm)
{
sr_i2c_pcb_length = mm;
}
void __init omap_vc_init_channel(struct voltagedomain *voltdm)
{
struct omap_vc_channel *vc = voltdm->vc;
u8 on_vsel, onlp_vsel, ret_vsel, off_vsel;
u32 val;
if (!voltdm->pmic || !voltdm->pmic->uv_to_vsel) {
pr_err("%s: No PMIC info for vdd_%s\n", __func__, voltdm->name);
return;
}
if (!voltdm->read || !voltdm->write) {
pr_err("%s: No read/write API for accessing vdd_%s regs\n",
__func__, voltdm->name);
return;
}
vc->cfg_channel = 0;
if (vc->flags & OMAP_VC_CHANNEL_CFG_MUTANT)
vc_cfg_bits = &vc_mutant_channel_cfg;
else
vc_cfg_bits = &vc_default_channel_cfg;
vc->i2c_slave_addr = voltdm->pmic->i2c_slave_addr;
vc->volt_reg_addr = voltdm->pmic->volt_reg_addr;
vc->cmd_reg_addr = voltdm->pmic->cmd_reg_addr;
voltdm->rmw(vc->smps_sa_mask,
vc->i2c_slave_addr << __ffs(vc->smps_sa_mask),
vc->smps_sa_reg);
vc->cfg_channel |= vc_cfg_bits->sa;
voltdm->rmw(vc->smps_volra_mask,
vc->volt_reg_addr << __ffs(vc->smps_volra_mask),
vc->smps_volra_reg);
vc->cfg_channel |= vc_cfg_bits->rav;
if (vc->cmd_reg_addr) {
voltdm->rmw(vc->smps_cmdra_mask,
vc->cmd_reg_addr << __ffs(vc->smps_cmdra_mask),
vc->smps_cmdra_reg);
vc->cfg_channel |= vc_cfg_bits->rac;
}
if (vc->cmd_reg_addr == vc->volt_reg_addr)
vc->cfg_channel |= vc_cfg_bits->racen;
on_vsel = omap_vc_calc_vsel(voltdm, voltdm->vc_param->on);
onlp_vsel = omap_vc_calc_vsel(voltdm, voltdm->vc_param->onlp);
ret_vsel = omap_vc_calc_vsel(voltdm, voltdm->vc_param->ret);
off_vsel = omap_vc_calc_vsel(voltdm, voltdm->vc_param->off);
val = ((on_vsel << vc->common->cmd_on_shift) |
(onlp_vsel << vc->common->cmd_onlp_shift) |
(ret_vsel << vc->common->cmd_ret_shift) |
(off_vsel << vc->common->cmd_off_shift));
voltdm->write(val, vc->cmdval_reg);
vc->cfg_channel |= vc_cfg_bits->cmd;
omap_vc_config_channel(voltdm);
omap_vc_i2c_init(voltdm);
if (cpu_is_omap34xx())
omap3_vc_init_channel(voltdm);
else if (cpu_is_omap44xx())
omap4_vc_init_channel(voltdm);
}
