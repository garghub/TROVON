static int qcom_vadc_map_voltage_temp(const struct vadc_map_pt *pts,
u32 tablesize, s32 input, s64 *output)
{
bool descending = 1;
u32 i = 0;
if (!pts)
return -EINVAL;
if (tablesize > 1) {
if (pts[0].x < pts[1].x)
descending = 0;
}
while (i < tablesize) {
if ((descending) && (pts[i].x < input)) {
break;
} else if ((!descending) &&
(pts[i].x > input)) {
break;
}
i++;
}
if (i == 0) {
*output = pts[0].y;
} else if (i == tablesize) {
*output = pts[tablesize - 1].y;
} else {
*output = (((s32)((pts[i].y - pts[i - 1].y) *
(input - pts[i - 1].x)) /
(pts[i].x - pts[i - 1].x)) +
pts[i - 1].y);
}
return 0;
}
static void qcom_vadc_scale_calib(const struct vadc_linear_graph *calib_graph,
u16 adc_code,
bool absolute,
s64 *scale_voltage)
{
*scale_voltage = (adc_code - calib_graph->gnd);
*scale_voltage *= calib_graph->dx;
*scale_voltage = div64_s64(*scale_voltage, calib_graph->dy);
if (absolute)
*scale_voltage += calib_graph->dx;
if (*scale_voltage < 0)
*scale_voltage = 0;
}
static int qcom_vadc_scale_volt(const struct vadc_linear_graph *calib_graph,
const struct vadc_prescale_ratio *prescale,
bool absolute, u16 adc_code,
int *result_uv)
{
s64 voltage = 0, result = 0;
qcom_vadc_scale_calib(calib_graph, adc_code, absolute, &voltage);
voltage = voltage * prescale->den;
result = div64_s64(voltage, prescale->num);
*result_uv = result;
return 0;
}
static int qcom_vadc_scale_therm(const struct vadc_linear_graph *calib_graph,
const struct vadc_prescale_ratio *prescale,
bool absolute, u16 adc_code,
int *result_mdec)
{
s64 voltage = 0, result = 0;
int ret;
qcom_vadc_scale_calib(calib_graph, adc_code, absolute, &voltage);
if (absolute)
voltage = div64_s64(voltage, 1000);
ret = qcom_vadc_map_voltage_temp(adcmap_100k_104ef_104fb,
ARRAY_SIZE(adcmap_100k_104ef_104fb),
voltage, &result);
if (ret)
return ret;
result *= 1000;
*result_mdec = result;
return 0;
}
static int qcom_vadc_scale_die_temp(const struct vadc_linear_graph *calib_graph,
const struct vadc_prescale_ratio *prescale,
bool absolute,
u16 adc_code, int *result_mdec)
{
s64 voltage = 0;
u64 temp;
qcom_vadc_scale_calib(calib_graph, adc_code, absolute, &voltage);
if (voltage > 0) {
temp = voltage * prescale->den;
do_div(temp, prescale->num * 2);
voltage = temp;
} else {
voltage = 0;
}
voltage -= KELVINMIL_CELSIUSMIL;
*result_mdec = voltage;
return 0;
}
static int qcom_vadc_scale_chg_temp(const struct vadc_linear_graph *calib_graph,
const struct vadc_prescale_ratio *prescale,
bool absolute,
u16 adc_code, int *result_mdec)
{
s64 voltage = 0, result = 0;
qcom_vadc_scale_calib(calib_graph, adc_code, absolute, &voltage);
voltage = voltage * prescale->den;
voltage = div64_s64(voltage, prescale->num);
voltage = ((PMI_CHG_SCALE_1) * (voltage * 2));
voltage = (voltage + PMI_CHG_SCALE_2);
result = div64_s64(voltage, 1000000);
*result_mdec = result;
return 0;
}
int qcom_vadc_scale(enum vadc_scale_fn_type scaletype,
const struct vadc_linear_graph *calib_graph,
const struct vadc_prescale_ratio *prescale,
bool absolute,
u16 adc_code, int *result)
{
switch (scaletype) {
case SCALE_DEFAULT:
return qcom_vadc_scale_volt(calib_graph, prescale,
absolute, adc_code,
result);
case SCALE_THERM_100K_PULLUP:
case SCALE_XOTHERM:
return qcom_vadc_scale_therm(calib_graph, prescale,
absolute, adc_code,
result);
case SCALE_PMIC_THERM:
return qcom_vadc_scale_die_temp(calib_graph, prescale,
absolute, adc_code,
result);
case SCALE_PMI_CHG_TEMP:
return qcom_vadc_scale_chg_temp(calib_graph, prescale,
absolute, adc_code,
result);
default:
return -EINVAL;
}
}
int qcom_vadc_decimation_from_dt(u32 value)
{
if (!is_power_of_2(value) || value < VADC_DECIMATION_MIN ||
value > VADC_DECIMATION_MAX)
return -EINVAL;
return __ffs64(value / VADC_DECIMATION_MIN);
}
