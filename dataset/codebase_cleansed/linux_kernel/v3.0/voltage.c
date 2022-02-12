static u32 omap3_voltage_read_reg(u16 mod, u8 offset)
{
return omap2_prm_read_mod_reg(mod, offset);
}
static void omap3_voltage_write_reg(u32 val, u16 mod, u8 offset)
{
omap2_prm_write_mod_reg(val, mod, offset);
}
static u32 omap4_voltage_read_reg(u16 mod, u8 offset)
{
return omap4_prminst_read_inst_reg(OMAP4430_PRM_PARTITION,
mod, offset);
}
static void omap4_voltage_write_reg(u32 val, u16 mod, u8 offset)
{
omap4_prminst_write_inst_reg(val, OMAP4430_PRM_PARTITION, mod, offset);
}
static int __init _config_common_vdd_data(struct omap_vdd_info *vdd)
{
char *sys_ck_name;
struct clk *sys_ck;
u32 sys_clk_speed, timeout_val, waittime;
if (cpu_is_omap24xx() || cpu_is_omap34xx())
sys_ck_name = "sys_ck";
else if (cpu_is_omap44xx())
sys_ck_name = "sys_clkin_ck";
else
return -EINVAL;
sys_ck = clk_get(NULL, sys_ck_name);
if (IS_ERR(sys_ck)) {
pr_warning("%s: Could not get the sys clk to calculate"
"various vdd_%s params\n", __func__, vdd->voltdm.name);
return -EINVAL;
}
sys_clk_speed = clk_get_rate(sys_ck);
clk_put(sys_ck);
sys_clk_speed /= 1000;
vdd->volt_scale = vp_forceupdate_scale_voltage;
vdd->vp_enabled = false;
vdd->vp_rt_data.vpconfig_erroroffset =
(vdd->pmic_info->vp_erroroffset <<
vdd->vp_data->vp_common->vpconfig_erroroffset_shift);
timeout_val = (sys_clk_speed * vdd->pmic_info->vp_timeout_us) / 1000;
vdd->vp_rt_data.vlimitto_timeout = timeout_val;
vdd->vp_rt_data.vlimitto_vddmin = vdd->pmic_info->vp_vddmin;
vdd->vp_rt_data.vlimitto_vddmax = vdd->pmic_info->vp_vddmax;
waittime = ((vdd->pmic_info->step_size / vdd->pmic_info->slew_rate) *
sys_clk_speed) / 1000;
vdd->vp_rt_data.vstepmin_smpswaittimemin = waittime;
vdd->vp_rt_data.vstepmax_smpswaittimemax = waittime;
vdd->vp_rt_data.vstepmin_stepmin = vdd->pmic_info->vp_vstepmin;
vdd->vp_rt_data.vstepmax_stepmax = vdd->pmic_info->vp_vstepmax;
return 0;
}
static int vp_volt_debug_get(void *data, u64 *val)
{
struct omap_vdd_info *vdd = (struct omap_vdd_info *) data;
u8 vsel;
if (!vdd) {
pr_warning("Wrong paramater passed\n");
return -EINVAL;
}
vsel = vdd->read_reg(prm_mod_offs, vdd->vp_data->voltage);
if (!vdd->pmic_info->vsel_to_uv) {
pr_warning("PMIC function to convert vsel to voltage"
"in uV not registerd\n");
return -EINVAL;
}
*val = vdd->pmic_info->vsel_to_uv(vsel);
return 0;
}
static int nom_volt_debug_get(void *data, u64 *val)
{
struct omap_vdd_info *vdd = (struct omap_vdd_info *) data;
if (!vdd) {
pr_warning("Wrong paramater passed\n");
return -EINVAL;
}
*val = omap_voltage_get_nom_volt(&vdd->voltdm);
return 0;
}
static void vp_latch_vsel(struct omap_vdd_info *vdd)
{
u32 vpconfig;
unsigned long uvdc;
char vsel;
uvdc = omap_voltage_get_nom_volt(&vdd->voltdm);
if (!uvdc) {
pr_warning("%s: unable to find current voltage for vdd_%s\n",
__func__, vdd->voltdm.name);
return;
}
if (!vdd->pmic_info || !vdd->pmic_info->uv_to_vsel) {
pr_warning("%s: PMIC function to convert voltage in uV to"
" vsel not registered\n", __func__);
return;
}
vsel = vdd->pmic_info->uv_to_vsel(uvdc);
vpconfig = vdd->read_reg(prm_mod_offs, vdd->vp_data->vpconfig);
vpconfig &= ~(vdd->vp_data->vp_common->vpconfig_initvoltage_mask |
vdd->vp_data->vp_common->vpconfig_initvdd);
vpconfig |= vsel << vdd->vp_data->vp_common->vpconfig_initvoltage_shift;
vdd->write_reg(vpconfig, prm_mod_offs, vdd->vp_data->vpconfig);
vdd->write_reg((vpconfig | vdd->vp_data->vp_common->vpconfig_initvdd),
prm_mod_offs, vdd->vp_data->vpconfig);
vdd->write_reg(vpconfig, prm_mod_offs, vdd->vp_data->vpconfig);
}
static void __init vp_init(struct omap_vdd_info *vdd)
{
u32 vp_val;
if (!vdd->read_reg || !vdd->write_reg) {
pr_err("%s: No read/write API for accessing vdd_%s regs\n",
__func__, vdd->voltdm.name);
return;
}
vp_val = vdd->vp_rt_data.vpconfig_erroroffset |
(vdd->vp_rt_data.vpconfig_errorgain <<
vdd->vp_data->vp_common->vpconfig_errorgain_shift) |
vdd->vp_data->vp_common->vpconfig_timeouten;
vdd->write_reg(vp_val, prm_mod_offs, vdd->vp_data->vpconfig);
vp_val = ((vdd->vp_rt_data.vstepmin_smpswaittimemin <<
vdd->vp_data->vp_common->vstepmin_smpswaittimemin_shift) |
(vdd->vp_rt_data.vstepmin_stepmin <<
vdd->vp_data->vp_common->vstepmin_stepmin_shift));
vdd->write_reg(vp_val, prm_mod_offs, vdd->vp_data->vstepmin);
vp_val = ((vdd->vp_rt_data.vstepmax_smpswaittimemax <<
vdd->vp_data->vp_common->vstepmax_smpswaittimemax_shift) |
(vdd->vp_rt_data.vstepmax_stepmax <<
vdd->vp_data->vp_common->vstepmax_stepmax_shift));
vdd->write_reg(vp_val, prm_mod_offs, vdd->vp_data->vstepmax);
vp_val = ((vdd->vp_rt_data.vlimitto_vddmax <<
vdd->vp_data->vp_common->vlimitto_vddmax_shift) |
(vdd->vp_rt_data.vlimitto_vddmin <<
vdd->vp_data->vp_common->vlimitto_vddmin_shift) |
(vdd->vp_rt_data.vlimitto_timeout <<
vdd->vp_data->vp_common->vlimitto_timeout_shift));
vdd->write_reg(vp_val, prm_mod_offs, vdd->vp_data->vlimitto);
}
static void __init vdd_debugfs_init(struct omap_vdd_info *vdd)
{
char *name;
name = kzalloc(VOLTAGE_DIR_SIZE, GFP_KERNEL);
if (!name) {
pr_warning("%s: Unable to allocate memory for debugfs"
" directory name for vdd_%s",
__func__, vdd->voltdm.name);
return;
}
strcpy(name, "vdd_");
strcat(name, vdd->voltdm.name);
vdd->debug_dir = debugfs_create_dir(name, voltage_dir);
kfree(name);
if (IS_ERR(vdd->debug_dir)) {
pr_warning("%s: Unable to create debugfs directory for"
" vdd_%s\n", __func__, vdd->voltdm.name);
vdd->debug_dir = NULL;
return;
}
(void) debugfs_create_x16("vp_errorgain", S_IRUGO, vdd->debug_dir,
&(vdd->vp_rt_data.vpconfig_errorgain));
(void) debugfs_create_x16("vp_smpswaittimemin", S_IRUGO,
vdd->debug_dir,
&(vdd->vp_rt_data.vstepmin_smpswaittimemin));
(void) debugfs_create_x8("vp_stepmin", S_IRUGO, vdd->debug_dir,
&(vdd->vp_rt_data.vstepmin_stepmin));
(void) debugfs_create_x16("vp_smpswaittimemax", S_IRUGO,
vdd->debug_dir,
&(vdd->vp_rt_data.vstepmax_smpswaittimemax));
(void) debugfs_create_x8("vp_stepmax", S_IRUGO, vdd->debug_dir,
&(vdd->vp_rt_data.vstepmax_stepmax));
(void) debugfs_create_x8("vp_vddmax", S_IRUGO, vdd->debug_dir,
&(vdd->vp_rt_data.vlimitto_vddmax));
(void) debugfs_create_x8("vp_vddmin", S_IRUGO, vdd->debug_dir,
&(vdd->vp_rt_data.vlimitto_vddmin));
(void) debugfs_create_x16("vp_timeout", S_IRUGO, vdd->debug_dir,
&(vdd->vp_rt_data.vlimitto_timeout));
(void) debugfs_create_file("curr_vp_volt", S_IRUGO, vdd->debug_dir,
(void *) vdd, &vp_volt_debug_fops);
(void) debugfs_create_file("curr_nominal_volt", S_IRUGO,
vdd->debug_dir, (void *) vdd,
&nom_volt_debug_fops);
}
static int _pre_volt_scale(struct omap_vdd_info *vdd,
unsigned long target_volt, u8 *target_vsel, u8 *current_vsel)
{
struct omap_volt_data *volt_data;
const struct omap_vc_common_data *vc_common;
const struct omap_vp_common_data *vp_common;
u32 vc_cmdval, vp_errgain_val;
vc_common = vdd->vc_data->vc_common;
vp_common = vdd->vp_data->vp_common;
if (!vdd->pmic_info) {
pr_err("%s: Insufficient pmic info to scale the vdd_%s\n",
__func__, vdd->voltdm.name);
return -EINVAL;
}
if (!vdd->pmic_info->uv_to_vsel) {
pr_err("%s: PMIC function to convert voltage in uV to"
"vsel not registered. Hence unable to scale voltage"
"for vdd_%s\n", __func__, vdd->voltdm.name);
return -ENODATA;
}
if (!vdd->read_reg || !vdd->write_reg) {
pr_err("%s: No read/write API for accessing vdd_%s regs\n",
__func__, vdd->voltdm.name);
return -EINVAL;
}
volt_data = omap_voltage_get_voltdata(&vdd->voltdm, target_volt);
if (IS_ERR(volt_data))
volt_data = NULL;
*target_vsel = vdd->pmic_info->uv_to_vsel(target_volt);
*current_vsel = vdd->read_reg(prm_mod_offs, vdd->vp_data->voltage);
vc_cmdval = vdd->read_reg(prm_mod_offs, vdd->vc_data->cmdval_reg);
vc_cmdval &= ~vc_common->cmd_on_mask;
vc_cmdval |= (*target_vsel << vc_common->cmd_on_shift);
vdd->write_reg(vc_cmdval, prm_mod_offs, vdd->vc_data->cmdval_reg);
if (volt_data) {
vp_errgain_val = vdd->read_reg(prm_mod_offs,
vdd->vp_data->vpconfig);
vdd->vp_rt_data.vpconfig_errorgain = volt_data->vp_errgain;
vp_errgain_val &= ~vp_common->vpconfig_errorgain_mask;
vp_errgain_val |= vdd->vp_rt_data.vpconfig_errorgain <<
vp_common->vpconfig_errorgain_shift;
vdd->write_reg(vp_errgain_val, prm_mod_offs,
vdd->vp_data->vpconfig);
}
return 0;
}
static void _post_volt_scale(struct omap_vdd_info *vdd,
unsigned long target_volt, u8 target_vsel, u8 current_vsel)
{
u32 smps_steps = 0, smps_delay = 0;
smps_steps = abs(target_vsel - current_vsel);
smps_delay = ((smps_steps * vdd->pmic_info->step_size) /
vdd->pmic_info->slew_rate) + 2;
udelay(smps_delay);
vdd->curr_volt = target_volt;
}
static int vc_bypass_scale_voltage(struct omap_vdd_info *vdd,
unsigned long target_volt)
{
u32 loop_cnt = 0, retries_cnt = 0;
u32 vc_valid, vc_bypass_val_reg, vc_bypass_value;
u8 target_vsel, current_vsel;
int ret;
ret = _pre_volt_scale(vdd, target_volt, &target_vsel, &current_vsel);
if (ret)
return ret;
vc_valid = vdd->vc_data->vc_common->valid;
vc_bypass_val_reg = vdd->vc_data->vc_common->bypass_val_reg;
vc_bypass_value = (target_vsel << vdd->vc_data->vc_common->data_shift) |
(vdd->pmic_info->pmic_reg <<
vdd->vc_data->vc_common->regaddr_shift) |
(vdd->pmic_info->i2c_slave_addr <<
vdd->vc_data->vc_common->slaveaddr_shift);
vdd->write_reg(vc_bypass_value, prm_mod_offs, vc_bypass_val_reg);
vdd->write_reg(vc_bypass_value | vc_valid, prm_mod_offs,
vc_bypass_val_reg);
vc_bypass_value = vdd->read_reg(prm_mod_offs, vc_bypass_val_reg);
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
vc_bypass_value = vdd->read_reg(prm_mod_offs,
vc_bypass_val_reg);
}
_post_volt_scale(vdd, target_volt, target_vsel, current_vsel);
return 0;
}
static int vp_forceupdate_scale_voltage(struct omap_vdd_info *vdd,
unsigned long target_volt)
{
u32 vpconfig;
u8 target_vsel, current_vsel, prm_irqst_reg;
int ret, timeout = 0;
ret = _pre_volt_scale(vdd, target_volt, &target_vsel, &current_vsel);
if (ret)
return ret;
prm_irqst_reg = vdd->vp_data->prm_irqst_data->prm_irqst_reg;
while (timeout++ < VP_TRANXDONE_TIMEOUT) {
vdd->write_reg(vdd->vp_data->prm_irqst_data->tranxdone_status,
prm_irqst_ocp_mod_offs, prm_irqst_reg);
if (!(vdd->read_reg(prm_irqst_ocp_mod_offs, prm_irqst_reg) &
vdd->vp_data->prm_irqst_data->tranxdone_status))
break;
udelay(1);
}
if (timeout >= VP_TRANXDONE_TIMEOUT) {
pr_warning("%s: vdd_%s TRANXDONE timeout exceeded."
"Voltage change aborted", __func__, vdd->voltdm.name);
return -ETIMEDOUT;
}
vpconfig = vdd->read_reg(prm_mod_offs, vdd->vp_data->vpconfig);
vpconfig &= ~(vdd->vp_data->vp_common->vpconfig_initvdd |
vdd->vp_data->vp_common->vpconfig_forceupdate |
vdd->vp_data->vp_common->vpconfig_initvoltage_mask);
vpconfig |= ((target_vsel <<
vdd->vp_data->vp_common->vpconfig_initvoltage_shift));
vdd->write_reg(vpconfig, prm_mod_offs, vdd->vp_data->vpconfig);
vpconfig |= vdd->vp_data->vp_common->vpconfig_initvdd;
vdd->write_reg(vpconfig, prm_mod_offs, vdd->vp_data->vpconfig);
vpconfig |= vdd->vp_data->vp_common->vpconfig_forceupdate;
vdd->write_reg(vpconfig, prm_mod_offs, vdd->vp_data->vpconfig);
timeout = 0;
omap_test_timeout((vdd->read_reg(prm_irqst_ocp_mod_offs, prm_irqst_reg) &
vdd->vp_data->prm_irqst_data->tranxdone_status),
VP_TRANXDONE_TIMEOUT, timeout);
if (timeout >= VP_TRANXDONE_TIMEOUT)
pr_err("%s: vdd_%s TRANXDONE timeout exceeded."
"TRANXDONE never got set after the voltage update\n",
__func__, vdd->voltdm.name);
_post_volt_scale(vdd, target_volt, target_vsel, current_vsel);
timeout = 0;
while (timeout++ < VP_TRANXDONE_TIMEOUT) {
vdd->write_reg(vdd->vp_data->prm_irqst_data->tranxdone_status,
prm_irqst_ocp_mod_offs, prm_irqst_reg);
if (!(vdd->read_reg(prm_irqst_ocp_mod_offs, prm_irqst_reg) &
vdd->vp_data->prm_irqst_data->tranxdone_status))
break;
udelay(1);
}
if (timeout >= VP_TRANXDONE_TIMEOUT)
pr_warning("%s: vdd_%s TRANXDONE timeout exceeded while trying"
"to clear the TRANXDONE status\n",
__func__, vdd->voltdm.name);
vpconfig = vdd->read_reg(prm_mod_offs, vdd->vp_data->vpconfig);
vpconfig &= ~vdd->vp_data->vp_common->vpconfig_initvdd;
vdd->write_reg(vpconfig, prm_mod_offs, vdd->vp_data->vpconfig);
vpconfig &= ~vdd->vp_data->vp_common->vpconfig_forceupdate;
vdd->write_reg(vpconfig, prm_mod_offs, vdd->vp_data->vpconfig);
return 0;
}
static void __init omap3_vfsm_init(struct omap_vdd_info *vdd)
{
vdd->write_reg(OMAP3_CLKSETUP, prm_mod_offs, OMAP3_PRM_CLKSETUP_OFFSET);
vdd->write_reg(OMAP3_VOLTOFFSET, prm_mod_offs,
OMAP3_PRM_VOLTOFFSET_OFFSET);
vdd->write_reg(OMAP3_VOLTSETUP2, prm_mod_offs,
OMAP3_PRM_VOLTSETUP2_OFFSET);
}
static void __init omap3_vc_init(struct omap_vdd_info *vdd)
{
static bool is_initialized;
u8 on_vsel, onlp_vsel, ret_vsel, off_vsel;
u32 vc_val;
if (is_initialized)
return;
on_vsel = vdd->pmic_info->uv_to_vsel(vdd->pmic_info->on_volt);
onlp_vsel = vdd->pmic_info->uv_to_vsel(vdd->pmic_info->onlp_volt);
ret_vsel = vdd->pmic_info->uv_to_vsel(vdd->pmic_info->ret_volt);
off_vsel = vdd->pmic_info->uv_to_vsel(vdd->pmic_info->off_volt);
vc_val = ((on_vsel << vdd->vc_data->vc_common->cmd_on_shift) |
(onlp_vsel << vdd->vc_data->vc_common->cmd_onlp_shift) |
(ret_vsel << vdd->vc_data->vc_common->cmd_ret_shift) |
(off_vsel << vdd->vc_data->vc_common->cmd_off_shift));
vdd->write_reg(vc_val, prm_mod_offs, vdd->vc_data->cmdval_reg);
vdd->write_reg(OMAP3430_CMD1_MASK | OMAP3430_RAV1_MASK, prm_mod_offs,
OMAP3_PRM_VC_CH_CONF_OFFSET);
vdd->write_reg(OMAP3430_MCODE_SHIFT | OMAP3430_HSEN_MASK, prm_mod_offs,
OMAP3_PRM_VC_I2C_CFG_OFFSET);
omap3_vfsm_init(vdd);
is_initialized = true;
}
static void __init omap4_vc_init(struct omap_vdd_info *vdd)
{
static bool is_initialized;
u32 vc_val;
if (is_initialized)
return;
vc_val = (OMAP4430_RAV_VDD_MPU_L_MASK | OMAP4430_CMD_VDD_MPU_L_MASK |
OMAP4430_RAV_VDD_IVA_L_MASK | OMAP4430_CMD_VDD_IVA_L_MASK |
OMAP4430_RAV_VDD_CORE_L_MASK | OMAP4430_CMD_VDD_CORE_L_MASK);
vdd->write_reg(vc_val, prm_mod_offs, OMAP4_PRM_VC_CFG_CHANNEL_OFFSET);
vc_val = (0x60 << OMAP4430_SCLL_SHIFT | 0x26 << OMAP4430_SCLH_SHIFT);
vdd->write_reg(vc_val, prm_mod_offs, OMAP4_PRM_VC_CFG_I2C_CLK_OFFSET);
is_initialized = true;
}
static void __init omap_vc_init(struct omap_vdd_info *vdd)
{
u32 vc_val;
if (!vdd->pmic_info || !vdd->pmic_info->uv_to_vsel) {
pr_err("%s: PMIC info requried to configure vc for"
"vdd_%s not populated.Hence cannot initialize vc\n",
__func__, vdd->voltdm.name);
return;
}
if (!vdd->read_reg || !vdd->write_reg) {
pr_err("%s: No read/write API for accessing vdd_%s regs\n",
__func__, vdd->voltdm.name);
return;
}
vc_val = vdd->read_reg(prm_mod_offs,
vdd->vc_data->vc_common->smps_sa_reg);
vc_val &= ~vdd->vc_data->smps_sa_mask;
vc_val |= vdd->pmic_info->i2c_slave_addr << vdd->vc_data->smps_sa_shift;
vdd->write_reg(vc_val, prm_mod_offs,
vdd->vc_data->vc_common->smps_sa_reg);
vc_val = vdd->read_reg(prm_mod_offs,
vdd->vc_data->vc_common->smps_volra_reg);
vc_val &= ~vdd->vc_data->smps_volra_mask;
vc_val |= vdd->pmic_info->pmic_reg << vdd->vc_data->smps_volra_shift;
vdd->write_reg(vc_val, prm_mod_offs,
vdd->vc_data->vc_common->smps_volra_reg);
vc_val = vdd->read_reg(prm_mod_offs, vdd->vfsm->voltsetup_reg);
vc_val &= ~vdd->vfsm->voltsetup_mask;
vc_val |= vdd->pmic_info->volt_setup_time <<
vdd->vfsm->voltsetup_shift;
vdd->write_reg(vc_val, prm_mod_offs, vdd->vfsm->voltsetup_reg);
if (cpu_is_omap34xx())
omap3_vc_init(vdd);
else if (cpu_is_omap44xx())
omap4_vc_init(vdd);
}
static int __init omap_vdd_data_configure(struct omap_vdd_info *vdd)
{
int ret = -EINVAL;
if (!vdd->pmic_info) {
pr_err("%s: PMIC info requried to configure vdd_%s not"
"populated.Hence cannot initialize vdd_%s\n",
__func__, vdd->voltdm.name, vdd->voltdm.name);
goto ovdc_out;
}
if (IS_ERR_VALUE(_config_common_vdd_data(vdd)))
goto ovdc_out;
if (cpu_is_omap34xx()) {
vdd->read_reg = omap3_voltage_read_reg;
vdd->write_reg = omap3_voltage_write_reg;
ret = 0;
} else if (cpu_is_omap44xx()) {
vdd->read_reg = omap4_voltage_read_reg;
vdd->write_reg = omap4_voltage_write_reg;
ret = 0;
}
ovdc_out:
return ret;
}
unsigned long omap_voltage_get_nom_volt(struct voltagedomain *voltdm)
{
struct omap_vdd_info *vdd;
if (!voltdm || IS_ERR(voltdm)) {
pr_warning("%s: VDD specified does not exist!\n", __func__);
return 0;
}
vdd = container_of(voltdm, struct omap_vdd_info, voltdm);
return vdd->curr_volt;
}
unsigned long omap_vp_get_curr_volt(struct voltagedomain *voltdm)
{
struct omap_vdd_info *vdd;
u8 curr_vsel;
if (!voltdm || IS_ERR(voltdm)) {
pr_warning("%s: VDD specified does not exist!\n", __func__);
return 0;
}
vdd = container_of(voltdm, struct omap_vdd_info, voltdm);
if (!vdd->read_reg) {
pr_err("%s: No read API for reading vdd_%s regs\n",
__func__, voltdm->name);
return 0;
}
curr_vsel = vdd->read_reg(prm_mod_offs, vdd->vp_data->voltage);
if (!vdd->pmic_info || !vdd->pmic_info->vsel_to_uv) {
pr_warning("%s: PMIC function to convert vsel to voltage"
"in uV not registerd\n", __func__);
return 0;
}
return vdd->pmic_info->vsel_to_uv(curr_vsel);
}
void omap_vp_enable(struct voltagedomain *voltdm)
{
struct omap_vdd_info *vdd;
u32 vpconfig;
if (!voltdm || IS_ERR(voltdm)) {
pr_warning("%s: VDD specified does not exist!\n", __func__);
return;
}
vdd = container_of(voltdm, struct omap_vdd_info, voltdm);
if (!vdd->read_reg || !vdd->write_reg) {
pr_err("%s: No read/write API for accessing vdd_%s regs\n",
__func__, voltdm->name);
return;
}
if (vdd->vp_enabled)
return;
vp_latch_vsel(vdd);
vpconfig = vdd->read_reg(prm_mod_offs, vdd->vp_data->vpconfig);
vpconfig |= vdd->vp_data->vp_common->vpconfig_vpenable;
vdd->write_reg(vpconfig, prm_mod_offs, vdd->vp_data->vpconfig);
vdd->vp_enabled = true;
}
void omap_vp_disable(struct voltagedomain *voltdm)
{
struct omap_vdd_info *vdd;
u32 vpconfig;
int timeout;
if (!voltdm || IS_ERR(voltdm)) {
pr_warning("%s: VDD specified does not exist!\n", __func__);
return;
}
vdd = container_of(voltdm, struct omap_vdd_info, voltdm);
if (!vdd->read_reg || !vdd->write_reg) {
pr_err("%s: No read/write API for accessing vdd_%s regs\n",
__func__, voltdm->name);
return;
}
if (!vdd->vp_enabled) {
pr_warning("%s: Trying to disable VP for vdd_%s when"
"it is already disabled\n", __func__, voltdm->name);
return;
}
vpconfig = vdd->read_reg(prm_mod_offs, vdd->vp_data->vpconfig);
vpconfig &= ~vdd->vp_data->vp_common->vpconfig_vpenable;
vdd->write_reg(vpconfig, prm_mod_offs, vdd->vp_data->vpconfig);
omap_test_timeout((vdd->read_reg(prm_mod_offs, vdd->vp_data->vstatus)),
VP_IDLE_TIMEOUT, timeout);
if (timeout >= VP_IDLE_TIMEOUT)
pr_warning("%s: vdd_%s idle timedout\n",
__func__, voltdm->name);
vdd->vp_enabled = false;
return;
}
int omap_voltage_scale_vdd(struct voltagedomain *voltdm,
unsigned long target_volt)
{
struct omap_vdd_info *vdd;
if (!voltdm || IS_ERR(voltdm)) {
pr_warning("%s: VDD specified does not exist!\n", __func__);
return -EINVAL;
}
vdd = container_of(voltdm, struct omap_vdd_info, voltdm);
if (!vdd->volt_scale) {
pr_err("%s: No voltage scale API registered for vdd_%s\n",
__func__, voltdm->name);
return -ENODATA;
}
return vdd->volt_scale(vdd, target_volt);
}
void omap_voltage_reset(struct voltagedomain *voltdm)
{
unsigned long target_uvdc;
if (!voltdm || IS_ERR(voltdm)) {
pr_warning("%s: VDD specified does not exist!\n", __func__);
return;
}
target_uvdc = omap_voltage_get_nom_volt(voltdm);
if (!target_uvdc) {
pr_err("%s: unable to find current voltage for vdd_%s\n",
__func__, voltdm->name);
return;
}
omap_voltage_scale_vdd(voltdm, target_uvdc);
}
void omap_voltage_get_volttable(struct voltagedomain *voltdm,
struct omap_volt_data **volt_data)
{
struct omap_vdd_info *vdd;
if (!voltdm || IS_ERR(voltdm)) {
pr_warning("%s: VDD specified does not exist!\n", __func__);
return;
}
vdd = container_of(voltdm, struct omap_vdd_info, voltdm);
*volt_data = vdd->volt_data;
}
struct omap_volt_data *omap_voltage_get_voltdata(struct voltagedomain *voltdm,
unsigned long volt)
{
struct omap_vdd_info *vdd;
int i;
if (!voltdm || IS_ERR(voltdm)) {
pr_warning("%s: VDD specified does not exist!\n", __func__);
return ERR_PTR(-EINVAL);
}
vdd = container_of(voltdm, struct omap_vdd_info, voltdm);
if (!vdd->volt_data) {
pr_warning("%s: voltage table does not exist for vdd_%s\n",
__func__, voltdm->name);
return ERR_PTR(-ENODATA);
}
for (i = 0; vdd->volt_data[i].volt_nominal != 0; i++) {
if (vdd->volt_data[i].volt_nominal == volt)
return &vdd->volt_data[i];
}
pr_notice("%s: Unable to match the current voltage with the voltage"
"table for vdd_%s\n", __func__, voltdm->name);
return ERR_PTR(-ENODATA);
}
int omap_voltage_register_pmic(struct voltagedomain *voltdm,
struct omap_volt_pmic_info *pmic_info)
{
struct omap_vdd_info *vdd;
if (!voltdm || IS_ERR(voltdm)) {
pr_warning("%s: VDD specified does not exist!\n", __func__);
return -EINVAL;
}
vdd = container_of(voltdm, struct omap_vdd_info, voltdm);
vdd->pmic_info = pmic_info;
return 0;
}
struct dentry *omap_voltage_get_dbgdir(struct voltagedomain *voltdm)
{
struct omap_vdd_info *vdd;
if (!voltdm || IS_ERR(voltdm)) {
pr_warning("%s: VDD specified does not exist!\n", __func__);
return NULL;
}
vdd = container_of(voltdm, struct omap_vdd_info, voltdm);
return vdd->debug_dir;
}
void omap_change_voltscale_method(struct voltagedomain *voltdm,
int voltscale_method)
{
struct omap_vdd_info *vdd;
if (!voltdm || IS_ERR(voltdm)) {
pr_warning("%s: VDD specified does not exist!\n", __func__);
return;
}
vdd = container_of(voltdm, struct omap_vdd_info, voltdm);
switch (voltscale_method) {
case VOLTSCALE_VPFORCEUPDATE:
vdd->volt_scale = vp_forceupdate_scale_voltage;
return;
case VOLTSCALE_VCBYPASS:
vdd->volt_scale = vc_bypass_scale_voltage;
return;
default:
pr_warning("%s: Trying to change the method of voltage scaling"
"to an unsupported one!\n", __func__);
}
}
struct voltagedomain *omap_voltage_domain_lookup(char *name)
{
int i;
if (!vdd_info) {
pr_err("%s: Voltage driver init not yet happened.Faulting!\n",
__func__);
return ERR_PTR(-EINVAL);
}
if (!name) {
pr_err("%s: No name to get the votage domain!\n", __func__);
return ERR_PTR(-EINVAL);
}
for (i = 0; i < nr_scalable_vdd; i++) {
if (!(strcmp(name, vdd_info[i]->voltdm.name)))
return &vdd_info[i]->voltdm;
}
return ERR_PTR(-EINVAL);
}
int __init omap_voltage_late_init(void)
{
int i;
if (!vdd_info) {
pr_err("%s: Voltage driver support not added\n",
__func__);
return -EINVAL;
}
voltage_dir = debugfs_create_dir("voltage", NULL);
if (IS_ERR(voltage_dir))
pr_err("%s: Unable to create voltage debugfs main dir\n",
__func__);
for (i = 0; i < nr_scalable_vdd; i++) {
if (omap_vdd_data_configure(vdd_info[i]))
continue;
omap_vc_init(vdd_info[i]);
vp_init(vdd_info[i]);
vdd_debugfs_init(vdd_info[i]);
}
return 0;
}
int __init omap_voltage_early_init(s16 prm_mod, s16 prm_irqst_ocp_mod,
struct omap_vdd_info *omap_vdd_array[],
u8 omap_vdd_count)
{
prm_mod_offs = prm_mod;
prm_irqst_ocp_mod_offs = prm_irqst_ocp_mod;
vdd_info = omap_vdd_array;
nr_scalable_vdd = omap_vdd_count;
return 0;
}
