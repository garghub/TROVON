static inline u32 ti_abb_rmw(u32 mask, u32 value, u32 offset,
void __iomem *base)
{
u32 val;
val = readl(base + offset);
val &= ~mask;
val |= (value << __ffs(mask)) & mask;
writel(val, base + offset);
return val;
}
static inline bool ti_abb_check_txdone(const struct ti_abb *abb)
{
return !!(readl(abb->int_base) & abb->txdone_mask);
}
static inline void ti_abb_clear_txdone(const struct ti_abb *abb)
{
writel(abb->txdone_mask, abb->int_base);
}
static int ti_abb_wait_txdone(struct device *dev, struct ti_abb *abb)
{
int timeout = 0;
bool status;
while (timeout++ <= abb->settling_time) {
status = ti_abb_check_txdone(abb);
if (status)
break;
udelay(1);
}
if (timeout > abb->settling_time) {
dev_warn_ratelimited(dev,
"%s:TRANXDONE timeout(%duS) int=0x%08x\n",
__func__, timeout, readl(abb->int_base));
return -ETIMEDOUT;
}
return 0;
}
static int ti_abb_clear_all_txdone(struct device *dev, const struct ti_abb *abb)
{
int timeout = 0;
bool status;
while (timeout++ <= abb->settling_time) {
ti_abb_clear_txdone(abb);
status = ti_abb_check_txdone(abb);
if (!status)
break;
udelay(1);
}
if (timeout > abb->settling_time) {
dev_warn_ratelimited(dev,
"%s:TRANXDONE timeout(%duS) int=0x%08x\n",
__func__, timeout, readl(abb->int_base));
return -ETIMEDOUT;
}
return 0;
}
static void ti_abb_program_ldovbb(struct device *dev, const struct ti_abb *abb,
struct ti_abb_info *info)
{
u32 val;
val = readl(abb->ldo_base);
val &= ~(abb->ldovbb_override_mask | abb->ldovbb_vset_mask);
switch (info->opp_sel) {
case TI_ABB_SLOW_OPP:
case TI_ABB_FAST_OPP:
val |= abb->ldovbb_override_mask;
val |= info->vset << __ffs(abb->ldovbb_vset_mask);
break;
}
writel(val, abb->ldo_base);
}
static int ti_abb_set_opp(struct regulator_dev *rdev, struct ti_abb *abb,
struct ti_abb_info *info)
{
const struct ti_abb_reg *regs = abb->regs;
struct device *dev = &rdev->dev;
int ret;
ret = ti_abb_clear_all_txdone(dev, abb);
if (ret)
goto out;
ti_abb_rmw(regs->fbb_sel_mask | regs->rbb_sel_mask, 0, regs->setup_reg,
abb->base);
switch (info->opp_sel) {
case TI_ABB_SLOW_OPP:
ti_abb_rmw(regs->rbb_sel_mask, 1, regs->setup_reg, abb->base);
break;
case TI_ABB_FAST_OPP:
ti_abb_rmw(regs->fbb_sel_mask, 1, regs->setup_reg, abb->base);
break;
}
ti_abb_rmw(regs->opp_sel_mask, info->opp_sel, regs->control_reg,
abb->base);
if (abb->ldo_base && info->opp_sel != TI_ABB_NOMINAL_OPP)
ti_abb_program_ldovbb(dev, abb, info);
ti_abb_rmw(regs->opp_change_mask, 1, regs->control_reg, abb->base);
ret = ti_abb_wait_txdone(dev, abb);
if (ret)
goto out;
ret = ti_abb_clear_all_txdone(dev, abb);
if (ret)
goto out;
if (abb->ldo_base && info->opp_sel == TI_ABB_NOMINAL_OPP)
ti_abb_program_ldovbb(dev, abb, info);
out:
return ret;
}
static int ti_abb_set_voltage_sel(struct regulator_dev *rdev, unsigned sel)
{
const struct regulator_desc *desc = rdev->desc;
struct ti_abb *abb = rdev_get_drvdata(rdev);
struct device *dev = &rdev->dev;
struct ti_abb_info *info, *oinfo;
int ret = 0;
if (!abb) {
dev_err_ratelimited(dev, "%s: No regulator drvdata\n",
__func__);
return -ENODEV;
}
if (!desc->n_voltages || !abb->info) {
dev_err_ratelimited(dev,
"%s: No valid voltage table entries?\n",
__func__);
return -EINVAL;
}
if (sel >= desc->n_voltages) {
dev_err(dev, "%s: sel idx(%d) >= n_voltages(%d)\n", __func__,
sel, desc->n_voltages);
return -EINVAL;
}
if (sel == abb->current_info_idx) {
dev_dbg(dev, "%s: Already at sel=%d\n", __func__, sel);
return ret;
}
info = &abb->info[sel];
oinfo = &abb->info[abb->current_info_idx];
if (!memcmp(info, oinfo, sizeof(*info))) {
dev_dbg(dev, "%s: Same data new idx=%d, old idx=%d\n", __func__,
sel, abb->current_info_idx);
goto out;
}
ret = ti_abb_set_opp(rdev, abb, info);
out:
if (!ret)
abb->current_info_idx = sel;
else
dev_err_ratelimited(dev,
"%s: Volt[%d] idx[%d] mode[%d] Fail(%d)\n",
__func__, desc->volt_table[sel], sel,
info->opp_sel, ret);
return ret;
}
static int ti_abb_get_voltage_sel(struct regulator_dev *rdev)
{
const struct regulator_desc *desc = rdev->desc;
struct ti_abb *abb = rdev_get_drvdata(rdev);
struct device *dev = &rdev->dev;
if (!abb) {
dev_err_ratelimited(dev, "%s: No regulator drvdata\n",
__func__);
return -ENODEV;
}
if (!desc->n_voltages || !abb->info) {
dev_err_ratelimited(dev,
"%s: No valid voltage table entries?\n",
__func__);
return -EINVAL;
}
if (abb->current_info_idx >= (int)desc->n_voltages) {
dev_err(dev, "%s: Corrupted data? idx(%d) >= n_voltages(%d)\n",
__func__, abb->current_info_idx, desc->n_voltages);
return -EINVAL;
}
return abb->current_info_idx;
}
static int ti_abb_init_timings(struct device *dev, struct ti_abb *abb)
{
u32 clock_cycles;
u32 clk_rate, sr2_wt_cnt_val, cycle_rate;
const struct ti_abb_reg *regs = abb->regs;
int ret;
char *pname = "ti,settling-time";
ret = of_property_read_u32(dev->of_node, pname, &abb->settling_time);
if (ret) {
dev_err(dev, "Unable to get property '%s'(%d)\n", pname, ret);
return ret;
}
if (!abb->settling_time) {
dev_err(dev, "Invalid property:'%s' set as 0!\n", pname);
return -EINVAL;
}
pname = "ti,clock-cycles";
ret = of_property_read_u32(dev->of_node, pname, &clock_cycles);
if (ret) {
dev_err(dev, "Unable to get property '%s'(%d)\n", pname, ret);
return ret;
}
if (!clock_cycles) {
dev_err(dev, "Invalid property:'%s' set as 0!\n", pname);
return -EINVAL;
}
abb->clk = devm_clk_get(dev, NULL);
if (IS_ERR(abb->clk)) {
ret = PTR_ERR(abb->clk);
dev_err(dev, "%s: Unable to get clk(%d)\n", __func__, ret);
return ret;
}
clk_rate = DIV_ROUND_CLOSEST(clk_get_rate(abb->clk), 1000000);
cycle_rate = DIV_ROUND_CLOSEST(clock_cycles * 10, clk_rate);
sr2_wt_cnt_val = DIV_ROUND_CLOSEST(abb->settling_time * 10, cycle_rate);
dev_dbg(dev, "%s: Clk_rate=%ld, sr2_cnt=0x%08x\n", __func__,
clk_get_rate(abb->clk), sr2_wt_cnt_val);
ti_abb_rmw(regs->sr2_wtcnt_value_mask, sr2_wt_cnt_val, regs->setup_reg,
abb->base);
return 0;
}
static int ti_abb_init_table(struct device *dev, struct ti_abb *abb,
struct regulator_init_data *rinit_data)
{
struct ti_abb_info *info;
const struct property *prop;
const __be32 *abb_info;
const u32 num_values = 6;
char *pname = "ti,abb_info";
u32 num_entries, i;
unsigned int *volt_table;
int min_uV = INT_MAX, max_uV = 0;
struct regulation_constraints *c = &rinit_data->constraints;
prop = of_find_property(dev->of_node, pname, NULL);
if (!prop) {
dev_err(dev, "No '%s' property?\n", pname);
return -ENODEV;
}
if (!prop->value) {
dev_err(dev, "Empty '%s' property?\n", pname);
return -ENODATA;
}
num_entries = prop->length / sizeof(u32);
if (!num_entries || (num_entries % num_values)) {
dev_err(dev, "All '%s' list entries need %d vals\n", pname,
num_values);
return -EINVAL;
}
num_entries /= num_values;
info = devm_kzalloc(dev, sizeof(*info) * num_entries, GFP_KERNEL);
if (!info) {
dev_err(dev, "Can't allocate info table for '%s' property\n",
pname);
return -ENOMEM;
}
abb->info = info;
volt_table = devm_kzalloc(dev, sizeof(unsigned int) * num_entries,
GFP_KERNEL);
if (!volt_table) {
dev_err(dev, "Can't allocate voltage table for '%s' property\n",
pname);
return -ENOMEM;
}
abb->rdesc.n_voltages = num_entries;
abb->rdesc.volt_table = volt_table;
abb->current_info_idx = -EINVAL;
abb_info = prop->value;
for (i = 0; i < num_entries; i++, info++, volt_table++) {
u32 efuse_offset, rbb_mask, fbb_mask, vset_mask;
u32 efuse_val;
*volt_table = be32_to_cpup(abb_info++);
info->opp_sel = be32_to_cpup(abb_info++);
efuse_offset = be32_to_cpup(abb_info++);
rbb_mask = be32_to_cpup(abb_info++);
fbb_mask = be32_to_cpup(abb_info++);
vset_mask = be32_to_cpup(abb_info++);
dev_dbg(dev,
"[%d]v=%d ABB=%d ef=0x%x rbb=0x%x fbb=0x%x vset=0x%x\n",
i, *volt_table, info->opp_sel, efuse_offset, rbb_mask,
fbb_mask, vset_mask);
if (min_uV > *volt_table)
min_uV = *volt_table;
if (max_uV < *volt_table)
max_uV = *volt_table;
if (!abb->efuse_base) {
if (efuse_offset || rbb_mask || fbb_mask || vset_mask)
dev_err(dev, "prop '%s': v=%d,bad efuse/mask\n",
pname, *volt_table);
goto check_abb;
}
efuse_val = readl(abb->efuse_base + efuse_offset);
if (efuse_val & rbb_mask)
info->opp_sel = TI_ABB_SLOW_OPP;
else if (efuse_val & fbb_mask)
info->opp_sel = TI_ABB_FAST_OPP;
else if (rbb_mask || fbb_mask)
info->opp_sel = TI_ABB_NOMINAL_OPP;
dev_dbg(dev,
"[%d]v=%d efusev=0x%x final ABB=%d\n",
i, *volt_table, efuse_val, info->opp_sel);
if (!abb->ldo_base) {
if (vset_mask)
dev_err(dev, "prop'%s':v=%d vst=%x LDO base?\n",
pname, *volt_table, vset_mask);
continue;
}
info->vset = efuse_val & vset_mask >> __ffs(vset_mask);
dev_dbg(dev, "[%d]v=%d vset=%x\n", i, *volt_table, info->vset);
check_abb:
switch (info->opp_sel) {
case TI_ABB_NOMINAL_OPP:
case TI_ABB_FAST_OPP:
case TI_ABB_SLOW_OPP:
break;
default:
dev_err(dev, "%s:[%d]v=%d, ABB=%d is invalid! Abort!\n",
__func__, i, *volt_table, info->opp_sel);
return -EINVAL;
}
}
c->min_uV = min_uV;
c->max_uV = max_uV;
return 0;
}
static int ti_abb_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *match;
struct resource *res;
struct ti_abb *abb;
struct regulator_init_data *initdata = NULL;
struct regulator_dev *rdev = NULL;
struct regulator_desc *desc;
struct regulation_constraints *c;
struct regulator_config config = { };
char *pname;
int ret = 0;
match = of_match_device(ti_abb_of_match, dev);
if (!match) {
ret = -ENODEV;
dev_err(dev, "%s: Unable to match device\n", __func__);
goto err;
}
if (!match->data) {
ret = -EINVAL;
dev_err(dev, "%s: Bad data in match\n", __func__);
goto err;
}
abb = devm_kzalloc(dev, sizeof(struct ti_abb), GFP_KERNEL);
if (!abb) {
dev_err(dev, "%s: Unable to allocate ABB struct\n", __func__);
ret = -ENOMEM;
goto err;
}
abb->regs = match->data;
pname = "base-address";
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, pname);
abb->base = devm_ioremap_resource(dev, res);
if (IS_ERR(abb->base)) {
ret = PTR_ERR(abb->base);
goto err;
}
pname = "int-address";
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, pname);
if (!res) {
dev_err(dev, "Missing '%s' IO resource\n", pname);
ret = -ENODEV;
goto err;
}
abb->int_base = devm_ioremap_nocache(dev, res->start,
resource_size(res));
if (!abb->int_base) {
dev_err(dev, "Unable to map '%s'\n", pname);
ret = -ENOMEM;
goto err;
}
pname = "efuse-address";
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, pname);
if (!res) {
dev_dbg(dev, "Missing '%s' IO resource\n", pname);
ret = -ENODEV;
goto skip_opt;
}
abb->efuse_base = devm_ioremap_nocache(dev, res->start,
resource_size(res));
if (!abb->efuse_base) {
dev_err(dev, "Unable to map '%s'\n", pname);
ret = -ENOMEM;
goto err;
}
pname = "ldo-address";
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, pname);
abb->ldo_base = devm_ioremap_resource(dev, res);
if (IS_ERR(abb->ldo_base)) {
ret = PTR_ERR(abb->ldo_base);
goto err;
}
pname = "ti,ldovbb-override-mask";
ret =
of_property_read_u32(pdev->dev.of_node, pname,
&abb->ldovbb_override_mask);
if (ret) {
dev_err(dev, "Missing '%s' (%d)\n", pname, ret);
goto err;
}
if (!abb->ldovbb_override_mask) {
dev_err(dev, "Invalid property:'%s' set as 0!\n", pname);
ret = -EINVAL;
goto err;
}
pname = "ti,ldovbb-vset-mask";
ret =
of_property_read_u32(pdev->dev.of_node, pname,
&abb->ldovbb_vset_mask);
if (ret) {
dev_err(dev, "Missing '%s' (%d)\n", pname, ret);
goto err;
}
if (!abb->ldovbb_vset_mask) {
dev_err(dev, "Invalid property:'%s' set as 0!\n", pname);
ret = -EINVAL;
goto err;
}
skip_opt:
pname = "ti,tranxdone-status-mask";
ret =
of_property_read_u32(pdev->dev.of_node, pname,
&abb->txdone_mask);
if (ret) {
dev_err(dev, "Missing '%s' (%d)\n", pname, ret);
goto err;
}
if (!abb->txdone_mask) {
dev_err(dev, "Invalid property:'%s' set as 0!\n", pname);
ret = -EINVAL;
goto err;
}
initdata = of_get_regulator_init_data(dev, pdev->dev.of_node);
if (!initdata) {
ret = -ENOMEM;
dev_err(dev, "%s: Unable to alloc regulator init data\n",
__func__);
goto err;
}
ret = ti_abb_init_table(dev, abb, initdata);
if (ret)
goto err;
ret = ti_abb_init_timings(dev, abb);
if (ret)
goto err;
desc = &abb->rdesc;
desc->name = dev_name(dev);
desc->owner = THIS_MODULE;
desc->type = REGULATOR_VOLTAGE;
desc->ops = &ti_abb_reg_ops;
c = &initdata->constraints;
if (desc->n_voltages > 1)
c->valid_ops_mask |= REGULATOR_CHANGE_VOLTAGE;
c->always_on = true;
config.dev = dev;
config.init_data = initdata;
config.driver_data = abb;
config.of_node = pdev->dev.of_node;
rdev = regulator_register(desc, &config);
if (IS_ERR(rdev)) {
ret = PTR_ERR(rdev);
dev_err(dev, "%s: failed to register regulator(%d)\n",
__func__, ret);
goto err;
}
platform_set_drvdata(pdev, rdev);
ti_abb_rmw(abb->regs->sr2_en_mask, 1, abb->regs->setup_reg, abb->base);
return 0;
err:
dev_err(dev, "%s: Failed to initialize(%d)\n", __func__, ret);
return ret;
}
static int ti_abb_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
regulator_unregister(rdev);
return 0;
}
