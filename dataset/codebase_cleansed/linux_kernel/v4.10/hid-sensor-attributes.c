static int pow_10(unsigned power)
{
int i;
int ret = 1;
for (i = 0; i < power; ++i)
ret = ret * 10;
return ret;
}
static void simple_div(int dividend, int divisor, int *whole,
int *micro_frac)
{
int rem;
int exp = 0;
*micro_frac = 0;
if (divisor == 0) {
*whole = 0;
return;
}
*whole = dividend/divisor;
rem = dividend % divisor;
if (rem) {
while (rem <= divisor) {
rem *= 10;
exp++;
}
*micro_frac = (rem / divisor) * pow_10(6-exp);
}
}
static void split_micro_fraction(unsigned int no, int exp, int *val1, int *val2)
{
*val1 = no/pow_10(exp);
*val2 = no%pow_10(exp) * pow_10(6-exp);
}
static void convert_from_vtf_format(u32 value, int size, int exp,
int *val1, int *val2)
{
int sign = 1;
if (value & BIT(size*8 - 1)) {
value = ((1LL << (size * 8)) - value);
sign = -1;
}
exp = hid_sensor_convert_exponent(exp);
if (exp >= 0) {
*val1 = sign * value * pow_10(exp);
*val2 = 0;
} else {
split_micro_fraction(value, -exp, val1, val2);
if (*val1)
*val1 = sign * (*val1);
else
*val2 = sign * (*val2);
}
}
static u32 convert_to_vtf_format(int size, int exp, int val1, int val2)
{
u32 value;
int sign = 1;
if (val1 < 0 || val2 < 0)
sign = -1;
exp = hid_sensor_convert_exponent(exp);
if (exp < 0) {
value = abs(val1) * pow_10(-exp);
value += abs(val2) / pow_10(6+exp);
} else
value = abs(val1) / pow_10(exp);
if (sign < 0)
value = ((1LL << (size * 8)) - value);
return value;
}
s32 hid_sensor_read_poll_value(struct hid_sensor_common *st)
{
s32 value = 0;
int ret;
ret = sensor_hub_get_feature(st->hsdev,
st->poll.report_id,
st->poll.index, sizeof(value), &value);
if (ret < 0 || value < 0) {
return -EINVAL;
} else {
if (st->poll.units == HID_USAGE_SENSOR_UNITS_SECOND)
value = value * 1000;
}
return value;
}
int hid_sensor_read_samp_freq_value(struct hid_sensor_common *st,
int *val1, int *val2)
{
s32 value;
int ret;
ret = sensor_hub_get_feature(st->hsdev,
st->poll.report_id,
st->poll.index, sizeof(value), &value);
if (ret < 0 || value < 0) {
*val1 = *val2 = 0;
return -EINVAL;
} else {
if (st->poll.units == HID_USAGE_SENSOR_UNITS_MILLISECOND)
simple_div(1000, value, val1, val2);
else if (st->poll.units == HID_USAGE_SENSOR_UNITS_SECOND)
simple_div(1, value, val1, val2);
else {
*val1 = *val2 = 0;
return -EINVAL;
}
}
return IIO_VAL_INT_PLUS_MICRO;
}
int hid_sensor_write_samp_freq_value(struct hid_sensor_common *st,
int val1, int val2)
{
s32 value;
int ret;
if (val1 < 0 || val2 < 0)
return -EINVAL;
value = val1 * pow_10(6) + val2;
if (value) {
if (st->poll.units == HID_USAGE_SENSOR_UNITS_MILLISECOND)
value = pow_10(9)/value;
else if (st->poll.units == HID_USAGE_SENSOR_UNITS_SECOND)
value = pow_10(6)/value;
else
value = 0;
}
ret = sensor_hub_set_feature(st->hsdev, st->poll.report_id,
st->poll.index, sizeof(value), &value);
if (ret < 0 || value < 0)
ret = -EINVAL;
return ret;
}
int hid_sensor_read_raw_hyst_value(struct hid_sensor_common *st,
int *val1, int *val2)
{
s32 value;
int ret;
ret = sensor_hub_get_feature(st->hsdev,
st->sensitivity.report_id,
st->sensitivity.index, sizeof(value),
&value);
if (ret < 0 || value < 0) {
*val1 = *val2 = 0;
return -EINVAL;
} else {
convert_from_vtf_format(value, st->sensitivity.size,
st->sensitivity.unit_expo,
val1, val2);
}
return IIO_VAL_INT_PLUS_MICRO;
}
int hid_sensor_write_raw_hyst_value(struct hid_sensor_common *st,
int val1, int val2)
{
s32 value;
int ret;
if (val1 < 0 || val2 < 0)
return -EINVAL;
value = convert_to_vtf_format(st->sensitivity.size,
st->sensitivity.unit_expo,
val1, val2);
ret = sensor_hub_set_feature(st->hsdev, st->sensitivity.report_id,
st->sensitivity.index, sizeof(value),
&value);
if (ret < 0 || value < 0)
ret = -EINVAL;
return ret;
}
static void adjust_exponent_nano(int *val0, int *val1, int scale0,
int scale1, int exp)
{
int i;
int x;
int res;
int rem;
if (exp > 0) {
*val0 = scale0 * pow_10(exp);
res = 0;
if (exp > 9) {
*val1 = 0;
return;
}
for (i = 0; i < exp; ++i) {
x = scale1 / pow_10(8 - i);
res += (pow_10(exp - 1 - i) * x);
scale1 = scale1 % pow_10(8 - i);
}
*val0 += res;
*val1 = scale1 * pow_10(exp);
} else if (exp < 0) {
exp = abs(exp);
if (exp > 9) {
*val0 = *val1 = 0;
return;
}
*val0 = scale0 / pow_10(exp);
rem = scale0 % pow_10(exp);
res = 0;
for (i = 0; i < (9 - exp); ++i) {
x = scale1 / pow_10(8 - i);
res += (pow_10(8 - exp - i) * x);
scale1 = scale1 % pow_10(8 - i);
}
*val1 = rem * pow_10(9 - exp) + res;
} else {
*val0 = scale0;
*val1 = scale1;
}
}
int hid_sensor_format_scale(u32 usage_id,
struct hid_sensor_hub_attribute_info *attr_info,
int *val0, int *val1)
{
int i;
int exp;
*val0 = 1;
*val1 = 0;
for (i = 0; i < ARRAY_SIZE(unit_conversion); ++i) {
if (unit_conversion[i].usage_id == usage_id &&
unit_conversion[i].unit == attr_info->units) {
exp = hid_sensor_convert_exponent(
attr_info->unit_expo);
adjust_exponent_nano(val0, val1,
unit_conversion[i].scale_val0,
unit_conversion[i].scale_val1, exp);
break;
}
}
return IIO_VAL_INT_PLUS_NANO;
}
static
int hid_sensor_get_reporting_interval(struct hid_sensor_hub_device *hsdev,
u32 usage_id,
struct hid_sensor_common *st)
{
sensor_hub_input_get_attribute_info(hsdev,
HID_FEATURE_REPORT, usage_id,
HID_USAGE_SENSOR_PROP_REPORT_INTERVAL,
&st->poll);
if (st->poll.units == 0)
st->poll.units = HID_USAGE_SENSOR_UNITS_MILLISECOND;
return 0;
}
int hid_sensor_parse_common_attributes(struct hid_sensor_hub_device *hsdev,
u32 usage_id,
struct hid_sensor_common *st)
{
hid_sensor_get_reporting_interval(hsdev, usage_id, st);
sensor_hub_input_get_attribute_info(hsdev,
HID_FEATURE_REPORT, usage_id,
HID_USAGE_SENSOR_PROP_REPORT_STATE,
&st->report_state);
sensor_hub_input_get_attribute_info(hsdev,
HID_FEATURE_REPORT, usage_id,
HID_USAGE_SENSOR_PROY_POWER_STATE,
&st->power_state);
sensor_hub_input_get_attribute_info(hsdev,
HID_FEATURE_REPORT, usage_id,
HID_USAGE_SENSOR_PROP_SENSITIVITY_ABS,
&st->sensitivity);
hid_dbg(hsdev->hdev, "common attributes: %x:%x, %x:%x, %x:%x %x:%x\n",
st->poll.index, st->poll.report_id,
st->report_state.index, st->report_state.report_id,
st->power_state.index, st->power_state.report_id,
st->sensitivity.index, st->sensitivity.report_id);
return 0;
}
