static int nfp_hwmon_sensor_id(enum hwmon_sensor_types type, int channel)
{
if (type == hwmon_temp)
return NFP_SENSOR_CHIP_TEMPERATURE;
if (type == hwmon_power)
return NFP_SENSOR_ASSEMBLY_POWER + channel;
return -EINVAL;
}
static int
nfp_hwmon_read(struct device *dev, enum hwmon_sensor_types type, u32 attr,
int channel, long *val)
{
static const struct {
enum hwmon_sensor_types type;
u32 attr;
long val;
} const_vals[] = {
{ hwmon_temp, hwmon_temp_max, NFP_TEMP_MAX },
{ hwmon_temp, hwmon_temp_crit, NFP_TEMP_CRIT },
{ hwmon_power, hwmon_power_max, NFP_POWER_MAX },
};
struct nfp_pf *pf = dev_get_drvdata(dev);
enum nfp_nsp_sensor_id id;
int err, i;
for (i = 0; i < ARRAY_SIZE(const_vals); i++)
if (const_vals[i].type == type && const_vals[i].attr == attr) {
*val = const_vals[i].val;
return 0;
}
err = nfp_hwmon_sensor_id(type, channel);
if (err < 0)
return err;
id = err;
if (!(pf->nspi->sensor_mask & BIT(id)))
return -EOPNOTSUPP;
if (type == hwmon_temp && attr == hwmon_temp_input)
return nfp_hwmon_read_sensor(pf->cpp, id, val);
if (type == hwmon_power && attr == hwmon_power_input)
return nfp_hwmon_read_sensor(pf->cpp, id, val);
return -EINVAL;
}
static umode_t
nfp_hwmon_is_visible(const void *data, enum hwmon_sensor_types type, u32 attr,
int channel)
{
if (type == hwmon_temp) {
switch (attr) {
case hwmon_temp_input:
case hwmon_temp_crit:
case hwmon_temp_max:
return 0444;
}
} else if (type == hwmon_power) {
switch (attr) {
case hwmon_power_input:
case hwmon_power_max:
return 0444;
}
}
return 0;
}
int nfp_hwmon_register(struct nfp_pf *pf)
{
if (!IS_REACHABLE(CONFIG_HWMON))
return 0;
if (!pf->nspi) {
nfp_warn(pf->cpp, "not registering HWMON (no NSP info)\n");
return 0;
}
if (!pf->nspi->sensor_mask) {
nfp_info(pf->cpp,
"not registering HWMON (NSP doesn't report sensors)\n");
return 0;
}
pf->hwmon_dev = hwmon_device_register_with_info(&pf->pdev->dev, "nfp",
pf, &nfp_chip_info,
NULL);
return PTR_ERR_OR_ZERO(pf->hwmon_dev);
}
void nfp_hwmon_unregister(struct nfp_pf *pf)
{
if (!IS_REACHABLE(CONFIG_HWMON) || !pf->hwmon_dev)
return;
hwmon_device_unregister(pf->hwmon_dev);
}
