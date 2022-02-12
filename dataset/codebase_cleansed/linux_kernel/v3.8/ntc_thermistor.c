static inline u64 div64_u64_safe(u64 dividend, u64 divisor)
{
if (divisor == 0 && dividend == 0)
return 0;
if (divisor == 0)
return UINT_MAX;
return div64_u64(dividend, divisor);
}
static int get_ohm_of_thermistor(struct ntc_data *data, unsigned int uV)
{
struct ntc_thermistor_platform_data *pdata = data->pdata;
u64 mV = uV / 1000;
u64 pmV = pdata->pullup_uV / 1000;
u64 N, puO, pdO;
puO = pdata->pullup_ohm;
pdO = pdata->pulldown_ohm;
if (mV == 0) {
if (pdata->connect == NTC_CONNECTED_POSITIVE)
return INT_MAX;
return 0;
}
if (mV >= pmV)
return (pdata->connect == NTC_CONNECTED_POSITIVE) ?
0 : INT_MAX;
if (pdata->connect == NTC_CONNECTED_POSITIVE && puO == 0)
N = div64_u64_safe(pdO * (pmV - mV), mV);
else if (pdata->connect == NTC_CONNECTED_GROUND && pdO == 0)
N = div64_u64_safe(puO * mV, pmV - mV);
else if (pdata->connect == NTC_CONNECTED_POSITIVE)
N = div64_u64_safe(pdO * puO * (pmV - mV),
puO * mV - pdO * (pmV - mV));
else
N = div64_u64_safe(pdO * puO * mV, pdO * (pmV - mV) - puO * mV);
if (N > INT_MAX)
N = INT_MAX;
return N;
}
static void lookup_comp(struct ntc_data *data, unsigned int ohm,
int *i_low, int *i_high)
{
int start, end, mid;
if (ohm >= data->comp[0].ohm) {
*i_low = 0;
*i_high = 0;
return;
}
if (ohm <= data->comp[data->n_comp - 1].ohm) {
*i_low = data->n_comp - 1;
*i_high = data->n_comp - 1;
return;
}
start = 0;
end = data->n_comp;
while (start < end) {
mid = start + (end - start) / 2;
if (ohm >= data->comp[mid].ohm) {
end = mid;
} else {
start = mid + 1;
if (ohm >= data->comp[start].ohm)
end = start;
}
}
*i_low = end;
if (ohm == data->comp[end].ohm)
*i_high = end;
else
*i_high = end - 1;
}
static int get_temp_mC(struct ntc_data *data, unsigned int ohm)
{
int low, high;
int temp;
lookup_comp(data, ohm, &low, &high);
if (low == high) {
temp = data->comp[low].temp_C * 1000;
} else {
temp = data->comp[low].temp_C * 1000 +
((data->comp[high].temp_C - data->comp[low].temp_C) *
1000 * ((int)ohm - (int)data->comp[low].ohm)) /
((int)data->comp[high].ohm - (int)data->comp[low].ohm);
}
return temp;
}
static int ntc_thermistor_get_ohm(struct ntc_data *data)
{
int read_uV;
if (data->pdata->read_ohm)
return data->pdata->read_ohm();
if (data->pdata->read_uV) {
read_uV = data->pdata->read_uV();
if (read_uV < 0)
return read_uV;
return get_ohm_of_thermistor(data, read_uV);
}
return -EINVAL;
}
static ssize_t ntc_show_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ntc_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static ssize_t ntc_show_type(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "4\n");
}
static ssize_t ntc_show_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ntc_data *data = dev_get_drvdata(dev);
int ohm;
ohm = ntc_thermistor_get_ohm(data);
if (ohm < 0)
return ohm;
return sprintf(buf, "%d\n", get_temp_mC(data, ohm));
}
static int ntc_thermistor_probe(struct platform_device *pdev)
{
struct ntc_data *data;
struct ntc_thermistor_platform_data *pdata = pdev->dev.platform_data;
int ret = 0;
if (!pdata) {
dev_err(&pdev->dev, "No platform init data supplied.\n");
return -ENODEV;
}
if (!pdata->read_uV && !pdata->read_ohm) {
dev_err(&pdev->dev,
"Both read_uV and read_ohm missing. Need either one of the two.\n");
return -EINVAL;
}
if (pdata->read_uV && pdata->read_ohm) {
dev_warn(&pdev->dev,
"Only one of read_uV and read_ohm is needed; ignoring read_uV.\n");
pdata->read_uV = NULL;
}
if (pdata->read_uV && (pdata->pullup_uV == 0 ||
(pdata->pullup_ohm == 0 && pdata->connect ==
NTC_CONNECTED_GROUND) ||
(pdata->pulldown_ohm == 0 && pdata->connect ==
NTC_CONNECTED_POSITIVE) ||
(pdata->connect != NTC_CONNECTED_POSITIVE &&
pdata->connect != NTC_CONNECTED_GROUND))) {
dev_err(&pdev->dev,
"Required data to use read_uV not supplied.\n");
return -EINVAL;
}
data = devm_kzalloc(&pdev->dev, sizeof(struct ntc_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->dev = &pdev->dev;
data->pdata = pdata;
strlcpy(data->name, pdev->id_entry->name, sizeof(data->name));
switch (pdev->id_entry->driver_data) {
case TYPE_NCPXXWB473:
data->comp = ncpXXwb473;
data->n_comp = ARRAY_SIZE(ncpXXwb473);
break;
case TYPE_NCPXXWL333:
data->comp = ncpXXwl333;
data->n_comp = ARRAY_SIZE(ncpXXwl333);
break;
default:
dev_err(&pdev->dev, "Unknown device type: %lu(%s)\n",
pdev->id_entry->driver_data,
pdev->id_entry->name);
return -EINVAL;
}
platform_set_drvdata(pdev, data);
ret = sysfs_create_group(&data->dev->kobj, &ntc_attr_group);
if (ret) {
dev_err(data->dev, "unable to create sysfs files\n");
return ret;
}
data->hwmon_dev = hwmon_device_register(data->dev);
if (IS_ERR(data->hwmon_dev)) {
dev_err(data->dev, "unable to register as hwmon device.\n");
ret = PTR_ERR(data->hwmon_dev);
goto err_after_sysfs;
}
dev_info(&pdev->dev, "Thermistor %s:%d (type: %s/%lu) successfully probed.\n",
pdev->name, pdev->id, pdev->id_entry->name,
pdev->id_entry->driver_data);
return 0;
err_after_sysfs:
sysfs_remove_group(&data->dev->kobj, &ntc_attr_group);
return ret;
}
static int ntc_thermistor_remove(struct platform_device *pdev)
{
struct ntc_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&data->dev->kobj, &ntc_attr_group);
platform_set_drvdata(pdev, NULL);
return 0;
}
