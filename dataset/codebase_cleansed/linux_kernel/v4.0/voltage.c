unsigned long voltdm_get_voltage(struct voltagedomain *voltdm)
{
if (!voltdm || IS_ERR(voltdm)) {
pr_warn("%s: VDD specified does not exist!\n", __func__);
return 0;
}
return voltdm->nominal_volt;
}
int voltdm_scale(struct voltagedomain *voltdm,
unsigned long target_volt)
{
int ret, i;
unsigned long volt = 0;
if (!voltdm || IS_ERR(voltdm)) {
pr_warn("%s: VDD specified does not exist!\n", __func__);
return -EINVAL;
}
if (!voltdm->scale) {
pr_err("%s: No voltage scale API registered for vdd_%s\n",
__func__, voltdm->name);
return -ENODATA;
}
for (i = 0; voltdm->volt_data[i].volt_nominal != 0; i++) {
if (voltdm->volt_data[i].volt_nominal >= target_volt) {
volt = voltdm->volt_data[i].volt_nominal;
break;
}
}
if (!volt) {
pr_warn("%s: not scaling. OPP voltage for %lu, not found.\n",
__func__, target_volt);
return -EINVAL;
}
ret = voltdm->scale(voltdm, volt);
if (!ret)
voltdm->nominal_volt = volt;
return ret;
}
void voltdm_reset(struct voltagedomain *voltdm)
{
unsigned long target_volt;
if (!voltdm || IS_ERR(voltdm)) {
pr_warn("%s: VDD specified does not exist!\n", __func__);
return;
}
target_volt = voltdm_get_voltage(voltdm);
if (!target_volt) {
pr_err("%s: unable to find current voltage for vdd_%s\n",
__func__, voltdm->name);
return;
}
voltdm_scale(voltdm, target_volt);
}
void omap_voltage_get_volttable(struct voltagedomain *voltdm,
struct omap_volt_data **volt_data)
{
if (!voltdm || IS_ERR(voltdm)) {
pr_warn("%s: VDD specified does not exist!\n", __func__);
return;
}
*volt_data = voltdm->volt_data;
}
struct omap_volt_data *omap_voltage_get_voltdata(struct voltagedomain *voltdm,
unsigned long volt)
{
int i;
if (!voltdm || IS_ERR(voltdm)) {
pr_warn("%s: VDD specified does not exist!\n", __func__);
return ERR_PTR(-EINVAL);
}
if (!voltdm->volt_data) {
pr_warn("%s: voltage table does not exist for vdd_%s\n",
__func__, voltdm->name);
return ERR_PTR(-ENODATA);
}
for (i = 0; voltdm->volt_data[i].volt_nominal != 0; i++) {
if (voltdm->volt_data[i].volt_nominal == volt)
return &voltdm->volt_data[i];
}
pr_notice("%s: Unable to match the current voltage with the voltage table for vdd_%s\n",
__func__, voltdm->name);
return ERR_PTR(-ENODATA);
}
int omap_voltage_register_pmic(struct voltagedomain *voltdm,
struct omap_voltdm_pmic *pmic)
{
if (!voltdm || IS_ERR(voltdm)) {
pr_warn("%s: VDD specified does not exist!\n", __func__);
return -EINVAL;
}
voltdm->pmic = pmic;
return 0;
}
int __init omap_voltage_late_init(void)
{
struct voltagedomain *voltdm;
if (list_empty(&voltdm_list)) {
pr_err("%s: Voltage driver support not added\n",
__func__);
return -EINVAL;
}
list_for_each_entry(voltdm, &voltdm_list, node) {
struct clk *sys_ck;
if (!voltdm->scalable)
continue;
sys_ck = clk_get(NULL, voltdm->sys_clk.name);
if (IS_ERR(sys_ck)) {
pr_warn("%s: Could not get sys clk.\n", __func__);
return -EINVAL;
}
voltdm->sys_clk.rate = clk_get_rate(sys_ck);
WARN_ON(!voltdm->sys_clk.rate);
clk_put(sys_ck);
if (voltdm->vc) {
voltdm->scale = omap_vc_bypass_scale;
omap_vc_init_channel(voltdm);
}
if (voltdm->vp) {
voltdm->scale = omap_vp_forceupdate_scale;
omap_vp_init(voltdm);
}
}
return 0;
}
static struct voltagedomain *_voltdm_lookup(const char *name)
{
struct voltagedomain *voltdm, *temp_voltdm;
voltdm = NULL;
list_for_each_entry(temp_voltdm, &voltdm_list, node) {
if (!strcmp(name, temp_voltdm->name)) {
voltdm = temp_voltdm;
break;
}
}
return voltdm;
}
static int _voltdm_register(struct voltagedomain *voltdm)
{
if (!voltdm || !voltdm->name)
return -EINVAL;
list_add(&voltdm->node, &voltdm_list);
pr_debug("voltagedomain: registered %s\n", voltdm->name);
return 0;
}
struct voltagedomain *voltdm_lookup(const char *name)
{
struct voltagedomain *voltdm ;
if (!name)
return NULL;
voltdm = _voltdm_lookup(name);
return voltdm;
}
void voltdm_init(struct voltagedomain **voltdms)
{
struct voltagedomain **v;
if (voltdms) {
for (v = voltdms; *v; v++)
_voltdm_register(*v);
}
}
