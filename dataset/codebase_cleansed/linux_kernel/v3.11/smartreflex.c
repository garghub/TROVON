static inline void sr_write_reg(struct omap_sr *sr, unsigned offset, u32 value)
{
__raw_writel(value, (sr->base + offset));
}
static inline void sr_modify_reg(struct omap_sr *sr, unsigned offset, u32 mask,
u32 value)
{
u32 reg_val;
if (sr->ip_type == SR_TYPE_V1 && offset == ERRCONFIG_V1)
mask |= ERRCONFIG_STATUS_V1_MASK;
else if (sr->ip_type == SR_TYPE_V2 && offset == ERRCONFIG_V2)
mask |= ERRCONFIG_VPBOUNDINTST_V2;
reg_val = __raw_readl(sr->base + offset);
reg_val &= ~mask;
value &= mask;
reg_val |= value;
__raw_writel(reg_val, (sr->base + offset));
}
static inline u32 sr_read_reg(struct omap_sr *sr, unsigned offset)
{
return __raw_readl(sr->base + offset);
}
static struct omap_sr *_sr_lookup(struct voltagedomain *voltdm)
{
struct omap_sr *sr_info;
if (!voltdm) {
pr_err("%s: Null voltage domain passed!\n", __func__);
return ERR_PTR(-EINVAL);
}
list_for_each_entry(sr_info, &sr_list, node) {
if (voltdm == sr_info->voltdm)
return sr_info;
}
return ERR_PTR(-ENODATA);
}
static irqreturn_t sr_interrupt(int irq, void *data)
{
struct omap_sr *sr_info = data;
u32 status = 0;
switch (sr_info->ip_type) {
case SR_TYPE_V1:
status = sr_read_reg(sr_info, ERRCONFIG_V1);
sr_write_reg(sr_info, ERRCONFIG_V1, status);
break;
case SR_TYPE_V2:
status = sr_read_reg(sr_info, IRQSTATUS);
sr_write_reg(sr_info, IRQSTATUS, status);
break;
default:
dev_err(&sr_info->pdev->dev, "UNKNOWN IP type %d\n",
sr_info->ip_type);
return IRQ_NONE;
}
if (sr_class->notify)
sr_class->notify(sr_info, status);
return IRQ_HANDLED;
}
static void sr_set_clk_length(struct omap_sr *sr)
{
struct clk *fck;
u32 fclk_speed;
fck = clk_get(&sr->pdev->dev, "fck");
if (IS_ERR(fck)) {
dev_err(&sr->pdev->dev, "%s: unable to get fck for device %s\n",
__func__, dev_name(&sr->pdev->dev));
return;
}
fclk_speed = clk_get_rate(fck);
clk_put(fck);
switch (fclk_speed) {
case 12000000:
sr->clk_length = SRCLKLENGTH_12MHZ_SYSCLK;
break;
case 13000000:
sr->clk_length = SRCLKLENGTH_13MHZ_SYSCLK;
break;
case 19200000:
sr->clk_length = SRCLKLENGTH_19MHZ_SYSCLK;
break;
case 26000000:
sr->clk_length = SRCLKLENGTH_26MHZ_SYSCLK;
break;
case 38400000:
sr->clk_length = SRCLKLENGTH_38MHZ_SYSCLK;
break;
default:
dev_err(&sr->pdev->dev, "%s: Invalid fclk rate: %d\n",
__func__, fclk_speed);
break;
}
}
static void sr_start_vddautocomp(struct omap_sr *sr)
{
if (!sr_class || !(sr_class->enable) || !(sr_class->configure)) {
dev_warn(&sr->pdev->dev,
"%s: smartreflex class driver not registered\n",
__func__);
return;
}
if (!sr_class->enable(sr))
sr->autocomp_active = true;
}
static void sr_stop_vddautocomp(struct omap_sr *sr)
{
if (!sr_class || !(sr_class->disable)) {
dev_warn(&sr->pdev->dev,
"%s: smartreflex class driver not registered\n",
__func__);
return;
}
if (sr->autocomp_active) {
sr_class->disable(sr, 1);
sr->autocomp_active = false;
}
}
static int sr_late_init(struct omap_sr *sr_info)
{
struct omap_sr_data *pdata = sr_info->pdev->dev.platform_data;
int ret = 0;
if (sr_class->notify && sr_class->notify_flags && sr_info->irq) {
ret = devm_request_irq(&sr_info->pdev->dev, sr_info->irq,
sr_interrupt, 0, sr_info->name, sr_info);
if (ret)
goto error;
disable_irq(sr_info->irq);
}
if (pdata && pdata->enable_on_init)
sr_start_vddautocomp(sr_info);
return ret;
error:
list_del(&sr_info->node);
dev_err(&sr_info->pdev->dev, "%s: ERROR in registering"
"interrupt handler. Smartreflex will"
"not function as desired\n", __func__);
return ret;
}
static void sr_v1_disable(struct omap_sr *sr)
{
int timeout = 0;
int errconf_val = ERRCONFIG_MCUACCUMINTST | ERRCONFIG_MCUVALIDINTST |
ERRCONFIG_MCUBOUNDINTST;
sr_modify_reg(sr, ERRCONFIG_V1,
ERRCONFIG_MCUDISACKINTEN, ERRCONFIG_MCUDISACKINTEN);
sr_modify_reg(sr, SRCONFIG, SRCONFIG_SRENABLE, 0x0);
if (sr_read_reg(sr, ERRCONFIG_V1) & ERRCONFIG_VPBOUNDINTST_V1)
errconf_val |= ERRCONFIG_VPBOUNDINTST_V1;
sr_modify_reg(sr, ERRCONFIG_V1,
(ERRCONFIG_MCUACCUMINTEN | ERRCONFIG_MCUVALIDINTEN |
ERRCONFIG_MCUBOUNDINTEN | ERRCONFIG_VPBOUNDINTEN_V1),
errconf_val);
sr_test_cond_timeout((sr_read_reg(sr, ERRCONFIG_V1) &
ERRCONFIG_MCUDISACKINTST), SR_DISABLE_TIMEOUT,
timeout);
if (timeout >= SR_DISABLE_TIMEOUT)
dev_warn(&sr->pdev->dev, "%s: Smartreflex disable timedout\n",
__func__);
sr_modify_reg(sr, ERRCONFIG_V1, ERRCONFIG_MCUDISACKINTEN,
ERRCONFIG_MCUDISACKINTST);
}
static void sr_v2_disable(struct omap_sr *sr)
{
int timeout = 0;
sr_write_reg(sr, IRQENABLE_SET, IRQENABLE_MCUDISABLEACKINT);
sr_modify_reg(sr, SRCONFIG, SRCONFIG_SRENABLE, 0x0);
if (sr_read_reg(sr, ERRCONFIG_V2) & ERRCONFIG_VPBOUNDINTST_V2)
sr_modify_reg(sr, ERRCONFIG_V2, ERRCONFIG_VPBOUNDINTEN_V2,
ERRCONFIG_VPBOUNDINTST_V2);
else
sr_modify_reg(sr, ERRCONFIG_V2, ERRCONFIG_VPBOUNDINTEN_V2,
0x0);
sr_write_reg(sr, IRQENABLE_CLR, (IRQENABLE_MCUACCUMINT |
IRQENABLE_MCUVALIDINT |
IRQENABLE_MCUBOUNDSINT));
sr_write_reg(sr, IRQSTATUS, (IRQSTATUS_MCUACCUMINT |
IRQSTATUS_MCVALIDINT |
IRQSTATUS_MCBOUNDSINT));
sr_test_cond_timeout((sr_read_reg(sr, IRQSTATUS) &
IRQSTATUS_MCUDISABLEACKINT), SR_DISABLE_TIMEOUT,
timeout);
if (timeout >= SR_DISABLE_TIMEOUT)
dev_warn(&sr->pdev->dev, "%s: Smartreflex disable timedout\n",
__func__);
sr_write_reg(sr, IRQENABLE_CLR, IRQENABLE_MCUDISABLEACKINT);
sr_write_reg(sr, IRQSTATUS, IRQSTATUS_MCUDISABLEACKINT);
}
static struct omap_sr_nvalue_table *sr_retrieve_nvalue_row(
struct omap_sr *sr, u32 efuse_offs)
{
int i;
if (!sr->nvalue_table) {
dev_warn(&sr->pdev->dev, "%s: Missing ntarget value table\n",
__func__);
return NULL;
}
for (i = 0; i < sr->nvalue_count; i++) {
if (sr->nvalue_table[i].efuse_offs == efuse_offs)
return &sr->nvalue_table[i];
}
return NULL;
}
int sr_configure_errgen(struct omap_sr *sr)
{
u32 sr_config, sr_errconfig, errconfig_offs;
u32 vpboundint_en, vpboundint_st;
u32 senp_en = 0, senn_en = 0;
u8 senp_shift, senn_shift;
if (!sr) {
pr_warn("%s: NULL omap_sr from %pF\n", __func__,
(void *)_RET_IP_);
return -EINVAL;
}
if (!sr->clk_length)
sr_set_clk_length(sr);
senp_en = sr->senp_mod;
senn_en = sr->senn_mod;
sr_config = (sr->clk_length << SRCONFIG_SRCLKLENGTH_SHIFT) |
SRCONFIG_SENENABLE | SRCONFIG_ERRGEN_EN;
switch (sr->ip_type) {
case SR_TYPE_V1:
sr_config |= SRCONFIG_DELAYCTRL;
senn_shift = SRCONFIG_SENNENABLE_V1_SHIFT;
senp_shift = SRCONFIG_SENPENABLE_V1_SHIFT;
errconfig_offs = ERRCONFIG_V1;
vpboundint_en = ERRCONFIG_VPBOUNDINTEN_V1;
vpboundint_st = ERRCONFIG_VPBOUNDINTST_V1;
break;
case SR_TYPE_V2:
senn_shift = SRCONFIG_SENNENABLE_V2_SHIFT;
senp_shift = SRCONFIG_SENPENABLE_V2_SHIFT;
errconfig_offs = ERRCONFIG_V2;
vpboundint_en = ERRCONFIG_VPBOUNDINTEN_V2;
vpboundint_st = ERRCONFIG_VPBOUNDINTST_V2;
break;
default:
dev_err(&sr->pdev->dev, "%s: Trying to Configure smartreflex"
"module without specifying the ip\n", __func__);
return -EINVAL;
}
sr_config |= ((senn_en << senn_shift) | (senp_en << senp_shift));
sr_write_reg(sr, SRCONFIG, sr_config);
sr_errconfig = (sr->err_weight << ERRCONFIG_ERRWEIGHT_SHIFT) |
(sr->err_maxlimit << ERRCONFIG_ERRMAXLIMIT_SHIFT) |
(sr->err_minlimit << ERRCONFIG_ERRMINLIMIT_SHIFT);
sr_modify_reg(sr, errconfig_offs, (SR_ERRWEIGHT_MASK |
SR_ERRMAXLIMIT_MASK | SR_ERRMINLIMIT_MASK),
sr_errconfig);
sr_modify_reg(sr, errconfig_offs, (vpboundint_en | vpboundint_st),
vpboundint_en);
return 0;
}
int sr_disable_errgen(struct omap_sr *sr)
{
u32 errconfig_offs;
u32 vpboundint_en, vpboundint_st;
if (!sr) {
pr_warn("%s: NULL omap_sr from %pF\n", __func__,
(void *)_RET_IP_);
return -EINVAL;
}
switch (sr->ip_type) {
case SR_TYPE_V1:
errconfig_offs = ERRCONFIG_V1;
vpboundint_en = ERRCONFIG_VPBOUNDINTEN_V1;
vpboundint_st = ERRCONFIG_VPBOUNDINTST_V1;
break;
case SR_TYPE_V2:
errconfig_offs = ERRCONFIG_V2;
vpboundint_en = ERRCONFIG_VPBOUNDINTEN_V2;
vpboundint_st = ERRCONFIG_VPBOUNDINTST_V2;
break;
default:
dev_err(&sr->pdev->dev, "%s: Trying to Configure smartreflex"
"module without specifying the ip\n", __func__);
return -EINVAL;
}
sr_modify_reg(sr, SRCONFIG, SRCONFIG_SENENABLE | SRCONFIG_ERRGEN_EN, 0);
sr_modify_reg(sr, errconfig_offs, vpboundint_en | vpboundint_st, 0);
return 0;
}
int sr_configure_minmax(struct omap_sr *sr)
{
u32 sr_config, sr_avgwt;
u32 senp_en = 0, senn_en = 0;
u8 senp_shift, senn_shift;
if (!sr) {
pr_warn("%s: NULL omap_sr from %pF\n", __func__,
(void *)_RET_IP_);
return -EINVAL;
}
if (!sr->clk_length)
sr_set_clk_length(sr);
senp_en = sr->senp_mod;
senn_en = sr->senn_mod;
sr_config = (sr->clk_length << SRCONFIG_SRCLKLENGTH_SHIFT) |
SRCONFIG_SENENABLE |
(sr->accum_data << SRCONFIG_ACCUMDATA_SHIFT);
switch (sr->ip_type) {
case SR_TYPE_V1:
sr_config |= SRCONFIG_DELAYCTRL;
senn_shift = SRCONFIG_SENNENABLE_V1_SHIFT;
senp_shift = SRCONFIG_SENPENABLE_V1_SHIFT;
break;
case SR_TYPE_V2:
senn_shift = SRCONFIG_SENNENABLE_V2_SHIFT;
senp_shift = SRCONFIG_SENPENABLE_V2_SHIFT;
break;
default:
dev_err(&sr->pdev->dev, "%s: Trying to Configure smartreflex"
"module without specifying the ip\n", __func__);
return -EINVAL;
}
sr_config |= ((senn_en << senn_shift) | (senp_en << senp_shift));
sr_write_reg(sr, SRCONFIG, sr_config);
sr_avgwt = (sr->senp_avgweight << AVGWEIGHT_SENPAVGWEIGHT_SHIFT) |
(sr->senn_avgweight << AVGWEIGHT_SENNAVGWEIGHT_SHIFT);
sr_write_reg(sr, AVGWEIGHT, sr_avgwt);
switch (sr->ip_type) {
case SR_TYPE_V1:
sr_modify_reg(sr, ERRCONFIG_V1,
(ERRCONFIG_MCUACCUMINTEN | ERRCONFIG_MCUVALIDINTEN |
ERRCONFIG_MCUBOUNDINTEN),
(ERRCONFIG_MCUACCUMINTEN | ERRCONFIG_MCUACCUMINTST |
ERRCONFIG_MCUVALIDINTEN | ERRCONFIG_MCUVALIDINTST |
ERRCONFIG_MCUBOUNDINTEN | ERRCONFIG_MCUBOUNDINTST));
break;
case SR_TYPE_V2:
sr_write_reg(sr, IRQSTATUS,
IRQSTATUS_MCUACCUMINT | IRQSTATUS_MCVALIDINT |
IRQSTATUS_MCBOUNDSINT | IRQSTATUS_MCUDISABLEACKINT);
sr_write_reg(sr, IRQENABLE_SET,
IRQENABLE_MCUACCUMINT | IRQENABLE_MCUVALIDINT |
IRQENABLE_MCUBOUNDSINT | IRQENABLE_MCUDISABLEACKINT);
break;
default:
dev_err(&sr->pdev->dev, "%s: Trying to Configure smartreflex"
"module without specifying the ip\n", __func__);
return -EINVAL;
}
return 0;
}
int sr_enable(struct omap_sr *sr, unsigned long volt)
{
struct omap_volt_data *volt_data;
struct omap_sr_nvalue_table *nvalue_row;
int ret;
if (!sr) {
pr_warn("%s: NULL omap_sr from %pF\n", __func__,
(void *)_RET_IP_);
return -EINVAL;
}
volt_data = omap_voltage_get_voltdata(sr->voltdm, volt);
if (IS_ERR(volt_data)) {
dev_warn(&sr->pdev->dev, "%s: Unable to get voltage table"
"for nominal voltage %ld\n", __func__, volt);
return PTR_ERR(volt_data);
}
nvalue_row = sr_retrieve_nvalue_row(sr, volt_data->sr_efuse_offs);
if (!nvalue_row) {
dev_warn(&sr->pdev->dev, "%s: failure getting SR data for this voltage %ld\n",
__func__, volt);
return -ENODATA;
}
sr->err_minlimit = nvalue_row->errminlimit;
pm_runtime_get_sync(&sr->pdev->dev);
if (sr_read_reg(sr, SRCONFIG) & SRCONFIG_SRENABLE)
return 0;
ret = sr_class->configure(sr);
if (ret)
return ret;
sr_write_reg(sr, NVALUERECIPROCAL, nvalue_row->nvalue);
sr_modify_reg(sr, SRCONFIG, SRCONFIG_SRENABLE, SRCONFIG_SRENABLE);
return 0;
}
void sr_disable(struct omap_sr *sr)
{
if (!sr) {
pr_warn("%s: NULL omap_sr from %pF\n", __func__,
(void *)_RET_IP_);
return;
}
if (pm_runtime_suspended(&sr->pdev->dev))
return;
if (sr_read_reg(sr, SRCONFIG) & SRCONFIG_SRENABLE) {
switch (sr->ip_type) {
case SR_TYPE_V1:
sr_v1_disable(sr);
break;
case SR_TYPE_V2:
sr_v2_disable(sr);
break;
default:
dev_err(&sr->pdev->dev, "UNKNOWN IP type %d\n",
sr->ip_type);
}
}
pm_runtime_put_sync_suspend(&sr->pdev->dev);
}
int sr_register_class(struct omap_sr_class_data *class_data)
{
struct omap_sr *sr_info;
if (!class_data) {
pr_warning("%s:, Smartreflex class data passed is NULL\n",
__func__);
return -EINVAL;
}
if (sr_class) {
pr_warning("%s: Smartreflex class driver already registered\n",
__func__);
return -EBUSY;
}
sr_class = class_data;
list_for_each_entry(sr_info, &sr_list, node)
sr_late_init(sr_info);
return 0;
}
void omap_sr_enable(struct voltagedomain *voltdm)
{
struct omap_sr *sr = _sr_lookup(voltdm);
if (IS_ERR(sr)) {
pr_warning("%s: omap_sr struct for voltdm not found\n", __func__);
return;
}
if (!sr->autocomp_active)
return;
if (!sr_class || !(sr_class->enable) || !(sr_class->configure)) {
dev_warn(&sr->pdev->dev, "%s: smartreflex class driver not"
"registered\n", __func__);
return;
}
sr_class->enable(sr);
}
void omap_sr_disable(struct voltagedomain *voltdm)
{
struct omap_sr *sr = _sr_lookup(voltdm);
if (IS_ERR(sr)) {
pr_warning("%s: omap_sr struct for voltdm not found\n", __func__);
return;
}
if (!sr->autocomp_active)
return;
if (!sr_class || !(sr_class->disable)) {
dev_warn(&sr->pdev->dev, "%s: smartreflex class driver not"
"registered\n", __func__);
return;
}
sr_class->disable(sr, 0);
}
void omap_sr_disable_reset_volt(struct voltagedomain *voltdm)
{
struct omap_sr *sr = _sr_lookup(voltdm);
if (IS_ERR(sr)) {
pr_warning("%s: omap_sr struct for voltdm not found\n", __func__);
return;
}
if (!sr->autocomp_active)
return;
if (!sr_class || !(sr_class->disable)) {
dev_warn(&sr->pdev->dev, "%s: smartreflex class driver not"
"registered\n", __func__);
return;
}
sr_class->disable(sr, 1);
}
void omap_sr_register_pmic(struct omap_sr_pmic_data *pmic_data)
{
if (!pmic_data) {
pr_warning("%s: Trying to register NULL PMIC data structure"
"with smartreflex\n", __func__);
return;
}
sr_pmic_data = pmic_data;
}
static int omap_sr_autocomp_show(void *data, u64 *val)
{
struct omap_sr *sr_info = data;
if (!sr_info) {
pr_warning("%s: omap_sr struct not found\n", __func__);
return -EINVAL;
}
*val = sr_info->autocomp_active;
return 0;
}
static int omap_sr_autocomp_store(void *data, u64 val)
{
struct omap_sr *sr_info = data;
if (!sr_info) {
pr_warning("%s: omap_sr struct not found\n", __func__);
return -EINVAL;
}
if (val > 1) {
pr_warning("%s: Invalid argument %lld\n", __func__, val);
return -EINVAL;
}
if (sr_info->autocomp_active != val) {
if (!val)
sr_stop_vddautocomp(sr_info);
else
sr_start_vddautocomp(sr_info);
}
return 0;
}
static int __init omap_sr_probe(struct platform_device *pdev)
{
struct omap_sr *sr_info;
struct omap_sr_data *pdata = pdev->dev.platform_data;
struct resource *mem, *irq;
struct dentry *nvalue_dir;
int i, ret = 0;
sr_info = devm_kzalloc(&pdev->dev, sizeof(struct omap_sr), GFP_KERNEL);
if (!sr_info) {
dev_err(&pdev->dev, "%s: unable to allocate sr_info\n",
__func__);
return -ENOMEM;
}
sr_info->name = devm_kzalloc(&pdev->dev,
SMARTREFLEX_NAME_LEN, GFP_KERNEL);
if (!sr_info->name) {
dev_err(&pdev->dev, "%s: unable to allocate SR instance name\n",
__func__);
return -ENOMEM;
}
platform_set_drvdata(pdev, sr_info);
if (!pdata) {
dev_err(&pdev->dev, "%s: platform data missing\n", __func__);
return -EINVAL;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sr_info->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(sr_info->base)) {
dev_err(&pdev->dev, "%s: ioremap fail\n", __func__);
return PTR_ERR(sr_info->base);
}
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
pm_runtime_enable(&pdev->dev);
pm_runtime_irq_safe(&pdev->dev);
snprintf(sr_info->name, SMARTREFLEX_NAME_LEN, "%s", pdata->name);
sr_info->pdev = pdev;
sr_info->srid = pdev->id;
sr_info->voltdm = pdata->voltdm;
sr_info->nvalue_table = pdata->nvalue_table;
sr_info->nvalue_count = pdata->nvalue_count;
sr_info->senn_mod = pdata->senn_mod;
sr_info->senp_mod = pdata->senp_mod;
sr_info->err_weight = pdata->err_weight;
sr_info->err_maxlimit = pdata->err_maxlimit;
sr_info->accum_data = pdata->accum_data;
sr_info->senn_avgweight = pdata->senn_avgweight;
sr_info->senp_avgweight = pdata->senp_avgweight;
sr_info->autocomp_active = false;
sr_info->ip_type = pdata->ip_type;
if (irq)
sr_info->irq = irq->start;
sr_set_clk_length(sr_info);
list_add(&sr_info->node, &sr_list);
if (sr_class) {
ret = sr_late_init(sr_info);
if (ret) {
pr_warning("%s: Error in SR late init\n", __func__);
goto err_list_del;
}
}
dev_info(&pdev->dev, "%s: SmartReflex driver initialized\n", __func__);
if (!sr_dbg_dir) {
sr_dbg_dir = debugfs_create_dir("smartreflex", NULL);
if (IS_ERR_OR_NULL(sr_dbg_dir)) {
ret = PTR_ERR(sr_dbg_dir);
pr_err("%s:sr debugfs dir creation failed(%d)\n",
__func__, ret);
goto err_list_del;
}
}
sr_info->dbg_dir = debugfs_create_dir(sr_info->name, sr_dbg_dir);
if (IS_ERR_OR_NULL(sr_info->dbg_dir)) {
dev_err(&pdev->dev, "%s: Unable to create debugfs directory\n",
__func__);
ret = PTR_ERR(sr_info->dbg_dir);
goto err_debugfs;
}
(void) debugfs_create_file("autocomp", S_IRUGO | S_IWUSR,
sr_info->dbg_dir, (void *)sr_info, &pm_sr_fops);
(void) debugfs_create_x32("errweight", S_IRUGO, sr_info->dbg_dir,
&sr_info->err_weight);
(void) debugfs_create_x32("errmaxlimit", S_IRUGO, sr_info->dbg_dir,
&sr_info->err_maxlimit);
nvalue_dir = debugfs_create_dir("nvalue", sr_info->dbg_dir);
if (IS_ERR_OR_NULL(nvalue_dir)) {
dev_err(&pdev->dev, "%s: Unable to create debugfs directory"
"for n-values\n", __func__);
ret = PTR_ERR(nvalue_dir);
goto err_debugfs;
}
if (sr_info->nvalue_count == 0 || !sr_info->nvalue_table) {
dev_warn(&pdev->dev, "%s: %s: No Voltage table for the corresponding vdd. Cannot create debugfs entries for n-values\n",
__func__, sr_info->name);
ret = -ENODATA;
goto err_debugfs;
}
for (i = 0; i < sr_info->nvalue_count; i++) {
char name[NVALUE_NAME_LEN + 1];
snprintf(name, sizeof(name), "volt_%lu",
sr_info->nvalue_table[i].volt_nominal);
(void) debugfs_create_x32(name, S_IRUGO | S_IWUSR, nvalue_dir,
&(sr_info->nvalue_table[i].nvalue));
snprintf(name, sizeof(name), "errminlimit_%lu",
sr_info->nvalue_table[i].volt_nominal);
(void) debugfs_create_x32(name, S_IRUGO | S_IWUSR, nvalue_dir,
&(sr_info->nvalue_table[i].errminlimit));
}
return ret;
err_debugfs:
debugfs_remove_recursive(sr_info->dbg_dir);
err_list_del:
list_del(&sr_info->node);
return ret;
}
static int omap_sr_remove(struct platform_device *pdev)
{
struct omap_sr_data *pdata = pdev->dev.platform_data;
struct omap_sr *sr_info;
if (!pdata) {
dev_err(&pdev->dev, "%s: platform data missing\n", __func__);
return -EINVAL;
}
sr_info = _sr_lookup(pdata->voltdm);
if (IS_ERR(sr_info)) {
dev_warn(&pdev->dev, "%s: omap_sr struct not found\n",
__func__);
return PTR_ERR(sr_info);
}
if (sr_info->autocomp_active)
sr_stop_vddautocomp(sr_info);
if (sr_info->dbg_dir)
debugfs_remove_recursive(sr_info->dbg_dir);
pm_runtime_disable(&pdev->dev);
list_del(&sr_info->node);
return 0;
}
static void omap_sr_shutdown(struct platform_device *pdev)
{
struct omap_sr_data *pdata = pdev->dev.platform_data;
struct omap_sr *sr_info;
if (!pdata) {
dev_err(&pdev->dev, "%s: platform data missing\n", __func__);
return;
}
sr_info = _sr_lookup(pdata->voltdm);
if (IS_ERR(sr_info)) {
dev_warn(&pdev->dev, "%s: omap_sr struct not found\n",
__func__);
return;
}
if (sr_info->autocomp_active)
sr_stop_vddautocomp(sr_info);
return;
}
static int __init sr_init(void)
{
int ret = 0;
if (sr_pmic_data && sr_pmic_data->sr_pmic_init)
sr_pmic_data->sr_pmic_init();
else
pr_warning("%s: No PMIC hook to init smartreflex\n", __func__);
ret = platform_driver_probe(&smartreflex_driver, omap_sr_probe);
if (ret) {
pr_err("%s: platform driver register failed for SR\n",
__func__);
return ret;
}
return 0;
}
static void __exit sr_exit(void)
{
platform_driver_unregister(&smartreflex_driver);
}
