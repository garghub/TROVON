static inline u64 div64_u64_safe(u64 dividend, u64 divisor)
{
if (divisor == 0 && dividend == 0)
return 0;
if (divisor == 0)
return UINT_MAX;
return div64_u64(dividend, divisor);
}
static unsigned int get_ohm_of_thermistor(struct ntc_data *data,
unsigned int uV)
{
struct ntc_thermistor_platform_data *pdata = data->pdata;
u64 mV = uV / 1000;
u64 pmV = pdata->pullup_uV / 1000;
u64 N, puO, pdO;
puO = pdata->pullup_ohm;
pdO = pdata->pulldown_ohm;
if (mV == 0) {
if (pdata->connect == NTC_CONNECTED_POSITIVE)
return UINT_MAX;
return 0;
}
if (mV >= pmV)
return (pdata->connect == NTC_CONNECTED_POSITIVE) ?
0 : UINT_MAX;
if (pdata->connect == NTC_CONNECTED_POSITIVE && puO == 0)
N = div64_u64_safe(pdO * (pmV - mV), mV);
else if (pdata->connect == NTC_CONNECTED_GROUND && pdO == 0)
N = div64_u64_safe(puO * mV, pmV - mV);
else if (pdata->connect == NTC_CONNECTED_POSITIVE)
N = div64_u64_safe(pdO * puO * (pmV - mV),
puO * mV - pdO * (pmV - mV));
else
N = div64_u64_safe(pdO * puO * mV, pdO * (pmV - mV) - puO * mV);
return (unsigned int) N;
}
static int lookup_comp(struct ntc_data *data,
unsigned int ohm, int *i_low, int *i_high)
{
int start, end, mid = -1;
start = 0;
end = data->n_comp;
while (end > start) {
mid = start + (end - start) / 2;
if (data->comp[mid].ohm < ohm)
end = mid;
else if (data->comp[mid].ohm > ohm)
start = mid + 1;
else
break;
}
if (mid == 0) {
if (data->comp[mid].ohm > ohm) {
*i_high = mid;
*i_low = mid + 1;
return 0;
} else {
*i_low = mid;
*i_high = -1;
return -EINVAL;
}
}
if (mid == (data->n_comp - 1)) {
if (data->comp[mid].ohm <= ohm) {
*i_low = mid;
*i_high = mid - 1;
return 0;
} else {
*i_low = -1;
*i_high = mid;
return -EINVAL;
}
}
if (data->comp[mid].ohm <= ohm) {
*i_low = mid;
*i_high = mid - 1;
} else {
*i_low = mid + 1;
*i_high = mid;
}
return 0;
}
static int get_temp_mC(struct ntc_data *data, unsigned int ohm, int *temp)
{
int low, high;
int ret;
ret = lookup_comp(data, ohm, &low, &high);
if (ret) {
if (low != -1)
*temp = data->comp[low].temp_C * 1000;
else if (high != -1)
*temp = data->comp[high].temp_C * 1000;
else
return ret;
} else {
*temp = data->comp[low].temp_C * 1000 +
((data->comp[high].temp_C - data->comp[low].temp_C) *
1000 * ((int)ohm - (int)data->comp[low].ohm)) /
((int)data->comp[high].ohm - (int)data->comp[low].ohm);
}
return 0;
}
static int ntc_thermistor_read(struct ntc_data *data, int *temp)
{
int ret;
int read_ohm, read_uV;
unsigned int ohm = 0;
if (data->pdata->read_ohm) {
read_ohm = data->pdata->read_ohm();
if (read_ohm < 0)
return read_ohm;
ohm = (unsigned int)read_ohm;
}
if (data->pdata->read_uV) {
read_uV = data->pdata->read_uV();
if (read_uV < 0)
return read_uV;
ohm = get_ohm_of_thermistor(data, (unsigned int)read_uV);
}
ret = get_temp_mC(data, ohm, temp);
if (ret) {
dev_dbg(data->dev, "Sensor reading function not available.\n");
return ret;
}
return 0;
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
int temp, ret;
ret = ntc_thermistor_read(data, &temp);
if (ret)
return ret;
return sprintf(buf, "%d\n", temp);
}
static int __devinit ntc_thermistor_probe(struct platform_device *pdev)
{
struct ntc_data *data;
struct ntc_thermistor_platform_data *pdata = pdev->dev.platform_data;
int ret = 0;
if (!pdata) {
dev_err(&pdev->dev, "No platform init data supplied.\n");
return -ENODEV;
}
if (!pdata->read_uV && !pdata->read_ohm) {
dev_err(&pdev->dev, "Both read_uV and read_ohm missing."
"Need either one of the two.\n");
return -EINVAL;
}
if (pdata->read_uV && pdata->read_ohm) {
dev_warn(&pdev->dev, "Only one of read_uV and read_ohm "
"is needed; ignoring read_uV.\n");
pdata->read_uV = NULL;
}
if (pdata->read_uV && (pdata->pullup_uV == 0 ||
(pdata->pullup_ohm == 0 && pdata->connect ==
NTC_CONNECTED_GROUND) ||
(pdata->pulldown_ohm == 0 && pdata->connect ==
NTC_CONNECTED_POSITIVE) ||
(pdata->connect != NTC_CONNECTED_POSITIVE &&
pdata->connect != NTC_CONNECTED_GROUND))) {
dev_err(&pdev->dev, "Required data to use read_uV not "
"supplied.\n");
return -EINVAL;
}
data = kzalloc(sizeof(struct ntc_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->dev = &pdev->dev;
data->pdata = pdata;
strncpy(data->name, pdev->id_entry->name, PLATFORM_NAME_SIZE);
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
ret = -EINVAL;
goto err;
}
platform_set_drvdata(pdev, data);
ret = sysfs_create_group(&data->dev->kobj, &ntc_attr_group);
if (ret) {
dev_err(data->dev, "unable to create sysfs files\n");
goto err;
}
data->hwmon_dev = hwmon_device_register(data->dev);
if (IS_ERR_OR_NULL(data->hwmon_dev)) {
dev_err(data->dev, "unable to register as hwmon device.\n");
ret = -EINVAL;
goto err_after_sysfs;
}
dev_info(&pdev->dev, "Thermistor %s:%d (type: %s/%lu) successfully probed.\n",
pdev->name, pdev->id, pdev->id_entry->name,
pdev->id_entry->driver_data);
return 0;
err_after_sysfs:
sysfs_remove_group(&data->dev->kobj, &ntc_attr_group);
err:
kfree(data);
return ret;
}
static int __devexit ntc_thermistor_remove(struct platform_device *pdev)
{
struct ntc_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&data->dev->kobj, &ntc_attr_group);
platform_set_drvdata(pdev, NULL);
kfree(data);
return 0;
}
