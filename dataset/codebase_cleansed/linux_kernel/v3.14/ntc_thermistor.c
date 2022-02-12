static int ntc_adc_iio_read(struct ntc_thermistor_platform_data *pdata)
{
struct iio_channel *channel = pdata->chan;
s64 result;
int val, ret;
ret = iio_read_channel_raw(channel, &val);
if (ret < 0) {
pr_err("read channel() error: %d\n", ret);
return ret;
}
result = pdata->pullup_uv * (s64) val;
result >>= 12;
return (int)result;
}
static struct ntc_thermistor_platform_data *
ntc_thermistor_parse_dt(struct platform_device *pdev)
{
struct iio_channel *chan;
struct device_node *np = pdev->dev.of_node;
struct ntc_thermistor_platform_data *pdata;
if (!np)
return NULL;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
chan = iio_channel_get(&pdev->dev, NULL);
if (IS_ERR(chan))
return ERR_CAST(chan);
if (of_property_read_u32(np, "pullup-uv", &pdata->pullup_uv))
return ERR_PTR(-ENODEV);
if (of_property_read_u32(np, "pullup-ohm", &pdata->pullup_ohm))
return ERR_PTR(-ENODEV);
if (of_property_read_u32(np, "pulldown-ohm", &pdata->pulldown_ohm))
return ERR_PTR(-ENODEV);
if (of_find_property(np, "connected-positive", NULL))
pdata->connect = NTC_CONNECTED_POSITIVE;
else
pdata->connect = NTC_CONNECTED_GROUND;
pdata->chan = chan;
pdata->read_uv = ntc_adc_iio_read;
return pdata;
}
static void ntc_iio_channel_release(struct ntc_thermistor_platform_data *pdata)
{
if (pdata->chan)
iio_channel_release(pdata->chan);
}
static struct ntc_thermistor_platform_data *
ntc_thermistor_parse_dt(struct platform_device *pdev)
{
return NULL;
}
static void ntc_iio_channel_release(struct ntc_thermistor_platform_data *pdata)
{ }
static inline u64 div64_u64_safe(u64 dividend, u64 divisor)
{
if (divisor == 0 && dividend == 0)
return 0;
if (divisor == 0)
return UINT_MAX;
return div64_u64(dividend, divisor);
}
static int get_ohm_of_thermistor(struct ntc_data *data, unsigned int uv)
{
struct ntc_thermistor_platform_data *pdata = data->pdata;
u64 mv = uv / 1000;
u64 pmv = pdata->pullup_uv / 1000;
u64 n, puo, pdo;
puo = pdata->pullup_ohm;
pdo = pdata->pulldown_ohm;
if (mv == 0) {
if (pdata->connect == NTC_CONNECTED_POSITIVE)
return INT_MAX;
return 0;
}
if (mv >= pmv)
return (pdata->connect == NTC_CONNECTED_POSITIVE) ?
0 : INT_MAX;
if (pdata->connect == NTC_CONNECTED_POSITIVE && puo == 0)
n = div64_u64_safe(pdo * (pmv - mv), mv);
else if (pdata->connect == NTC_CONNECTED_GROUND && pdo == 0)
n = div64_u64_safe(puo * mv, pmv - mv);
else if (pdata->connect == NTC_CONNECTED_POSITIVE)
n = div64_u64_safe(pdo * puo * (pmv - mv),
puo * mv - pdo * (pmv - mv));
else
n = div64_u64_safe(pdo * puo * mv, pdo * (pmv - mv) - puo * mv);
if (n > INT_MAX)
n = INT_MAX;
return n;
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
static int get_temp_mc(struct ntc_data *data, unsigned int ohm)
{
int low, high;
int temp;
lookup_comp(data, ohm, &low, &high);
if (low == high) {
temp = data->comp[low].temp_c * 1000;
} else {
temp = data->comp[low].temp_c * 1000 +
((data->comp[high].temp_c - data->comp[low].temp_c) *
1000 * ((int)ohm - (int)data->comp[low].ohm)) /
((int)data->comp[high].ohm - (int)data->comp[low].ohm);
}
return temp;
}
static int ntc_thermistor_get_ohm(struct ntc_data *data)
{
int read_uv;
if (data->pdata->read_ohm)
return data->pdata->read_ohm();
if (data->pdata->read_uv) {
read_uv = data->pdata->read_uv(data->pdata);
if (read_uv < 0)
return read_uv;
return get_ohm_of_thermistor(data, read_uv);
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
return sprintf(buf, "%d\n", get_temp_mc(data, ohm));
}
static int ntc_thermistor_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(of_match_ptr(ntc_match), &pdev->dev);
const struct platform_device_id *pdev_id;
struct ntc_thermistor_platform_data *pdata;
struct ntc_data *data;
int ret;
pdata = ntc_thermistor_parse_dt(pdev);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
else if (pdata == NULL)
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "No platform init data supplied.\n");
return -ENODEV;
}
if (!pdata->read_uv && !pdata->read_ohm) {
dev_err(&pdev->dev,
"Both read_uv and read_ohm missing. Need either one of the two.\n");
return -EINVAL;
}
if (pdata->read_uv && pdata->read_ohm) {
dev_warn(&pdev->dev,
"Only one of read_uv and read_ohm is needed; ignoring read_uv.\n");
pdata->read_uv = NULL;
}
if (pdata->read_uv && (pdata->pullup_uv == 0 ||
(pdata->pullup_ohm == 0 && pdata->connect ==
NTC_CONNECTED_GROUND) ||
(pdata->pulldown_ohm == 0 && pdata->connect ==
NTC_CONNECTED_POSITIVE) ||
(pdata->connect != NTC_CONNECTED_POSITIVE &&
pdata->connect != NTC_CONNECTED_GROUND))) {
dev_err(&pdev->dev,
"Required data to use read_uv not supplied.\n");
return -EINVAL;
}
data = devm_kzalloc(&pdev->dev, sizeof(struct ntc_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
pdev_id = of_id ? of_id->data : platform_get_device_id(pdev);
data->dev = &pdev->dev;
data->pdata = pdata;
strlcpy(data->name, pdev_id->name, sizeof(data->name));
switch (pdev_id->driver_data) {
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
pdev_id->driver_data, pdev_id->name);
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
dev_info(&pdev->dev, "Thermistor type: %s successfully probed.\n",
pdev->name);
return 0;
err_after_sysfs:
sysfs_remove_group(&data->dev->kobj, &ntc_attr_group);
ntc_iio_channel_release(pdata);
return ret;
}
static int ntc_thermistor_remove(struct platform_device *pdev)
{
struct ntc_data *data = platform_get_drvdata(pdev);
struct ntc_thermistor_platform_data *pdata = data->pdata;
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&data->dev->kobj, &ntc_attr_group);
ntc_iio_channel_release(pdata);
return 0;
}
