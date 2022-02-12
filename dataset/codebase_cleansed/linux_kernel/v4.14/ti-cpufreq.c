static unsigned long amx3_efuse_xlate(struct ti_cpufreq_data *opp_data,
unsigned long efuse)
{
if (!efuse)
efuse = opp_data->soc_data->efuse_fallback;
return ~efuse;
}
static unsigned long dra7_efuse_xlate(struct ti_cpufreq_data *opp_data,
unsigned long efuse)
{
unsigned long calculated_efuse = DRA7_EFUSE_NOM_MPU_OPP;
switch (efuse) {
case DRA7_EFUSE_HAS_ALL_MPU_OPP:
case DRA7_EFUSE_HAS_HIGH_MPU_OPP:
calculated_efuse |= DRA7_EFUSE_HIGH_MPU_OPP;
case DRA7_EFUSE_HAS_OD_MPU_OPP:
calculated_efuse |= DRA7_EFUSE_OD_MPU_OPP;
}
return calculated_efuse;
}
static int ti_cpufreq_get_efuse(struct ti_cpufreq_data *opp_data,
u32 *efuse_value)
{
struct device *dev = opp_data->cpu_dev;
u32 efuse;
int ret;
ret = regmap_read(opp_data->syscon, opp_data->soc_data->efuse_offset,
&efuse);
if (ret) {
dev_err(dev,
"Failed to read the efuse value from syscon: %d\n",
ret);
return ret;
}
efuse = (efuse & opp_data->soc_data->efuse_mask);
efuse >>= opp_data->soc_data->efuse_shift;
*efuse_value = opp_data->soc_data->efuse_xlate(opp_data, efuse);
return 0;
}
static int ti_cpufreq_get_rev(struct ti_cpufreq_data *opp_data,
u32 *revision_value)
{
struct device *dev = opp_data->cpu_dev;
u32 revision;
int ret;
ret = regmap_read(opp_data->syscon, opp_data->soc_data->rev_offset,
&revision);
if (ret) {
dev_err(dev,
"Failed to read the revision number from syscon: %d\n",
ret);
return ret;
}
*revision_value = BIT((revision >> REVISION_SHIFT) & REVISION_MASK);
return 0;
}
static int ti_cpufreq_setup_syscon_register(struct ti_cpufreq_data *opp_data)
{
struct device *dev = opp_data->cpu_dev;
struct device_node *np = opp_data->opp_node;
opp_data->syscon = syscon_regmap_lookup_by_phandle(np,
"syscon");
if (IS_ERR(opp_data->syscon)) {
dev_err(dev,
"\"syscon\" is missing, cannot use OPPv2 table.\n");
return PTR_ERR(opp_data->syscon);
}
return 0;
}
static int ti_cpufreq_init(void)
{
u32 version[VERSION_COUNT];
struct device_node *np;
const struct of_device_id *match;
struct ti_cpufreq_data *opp_data;
int ret;
np = of_find_node_by_path("/");
match = of_match_node(ti_cpufreq_of_match, np);
if (!match)
return -ENODEV;
opp_data = kzalloc(sizeof(*opp_data), GFP_KERNEL);
if (!opp_data)
return -ENOMEM;
opp_data->soc_data = match->data;
opp_data->cpu_dev = get_cpu_device(0);
if (!opp_data->cpu_dev) {
pr_err("%s: Failed to get device for CPU0\n", __func__);
return -ENODEV;
}
opp_data->opp_node = dev_pm_opp_of_get_opp_desc_node(opp_data->cpu_dev);
if (!opp_data->opp_node) {
dev_info(opp_data->cpu_dev,
"OPP-v2 not supported, cpufreq-dt will attempt to use legacy tables.\n");
goto register_cpufreq_dt;
}
ret = ti_cpufreq_setup_syscon_register(opp_data);
if (ret)
goto fail_put_node;
ret = ti_cpufreq_get_rev(opp_data, &version[0]);
if (ret)
goto fail_put_node;
ret = ti_cpufreq_get_efuse(opp_data, &version[1]);
if (ret)
goto fail_put_node;
ret = PTR_ERR_OR_ZERO(dev_pm_opp_set_supported_hw(opp_data->cpu_dev,
version, VERSION_COUNT));
if (ret) {
dev_err(opp_data->cpu_dev,
"Failed to set supported hardware\n");
goto fail_put_node;
}
of_node_put(opp_data->opp_node);
register_cpufreq_dt:
platform_device_register_simple("cpufreq-dt", -1, NULL, 0);
return 0;
fail_put_node:
of_node_put(opp_data->opp_node);
return ret;
}
