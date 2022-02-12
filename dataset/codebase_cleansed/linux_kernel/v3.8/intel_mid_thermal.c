static int to_msic_die_temp(uint16_t adc_val)
{
return (368 * (adc_val) / 1000) - 220;
}
static int is_valid_adc(uint16_t adc_val, uint16_t min, uint16_t max)
{
return (adc_val >= min) && (adc_val <= max);
}
static int adc_to_temp(int direct, uint16_t adc_val, unsigned long *tp)
{
int temp;
if (direct) {
if (is_valid_adc(adc_val, MSIC_DIE_ADC_MIN, MSIC_DIE_ADC_MAX)) {
*tp = to_msic_die_temp(adc_val) * 1000;
return 0;
}
return -ERANGE;
}
if (!is_valid_adc(adc_val, ADC_MIN, ADC_MAX))
return -ERANGE;
if (adc_val > ADC_VAL0C)
temp = 177 - (adc_val/5);
else if ((adc_val <= ADC_VAL0C) && (adc_val > ADC_VAL20C))
temp = 111 - (adc_val/8);
else if ((adc_val <= ADC_VAL20C) && (adc_val > ADC_VAL40C))
temp = 92 - (adc_val/10);
else if ((adc_val <= ADC_VAL40C) && (adc_val > ADC_VAL60C))
temp = 91 - (adc_val/10);
else
temp = 112 - (adc_val/6);
*tp = temp * 1000;
return 0;
}
static int mid_read_temp(struct thermal_zone_device *tzd, unsigned long *temp)
{
struct thermal_device_info *td_info = tzd->devdata;
uint16_t adc_val, addr;
uint8_t data = 0;
int ret;
unsigned long curr_temp;
addr = td_info->chnl_addr;
ret = intel_msic_reg_write(INTEL_MSIC_ADC1CNTL3, MSIC_ADCRRDATA_ENBL);
if (ret)
return ret;
ret = intel_msic_reg_write(INTEL_MSIC_ADC1CNTL3, MSIC_ADCTHERM_ENBL);
if (ret)
return ret;
ret = intel_msic_reg_read(addr, &data);
if (ret)
return ret;
adc_val = (data << 2);
addr++;
ret = intel_msic_reg_read(addr, &data);
if (ret)
return ret;
data &= 03;
adc_val += data;
ret = adc_to_temp(td_info->direct, adc_val, &curr_temp);
if (ret == 0)
*temp = td_info->curr_temp = curr_temp;
return ret;
}
static int configure_adc(int val)
{
int ret;
uint8_t data;
ret = intel_msic_reg_read(INTEL_MSIC_ADC1CNTL1, &data);
if (ret)
return ret;
if (val) {
data |= (MSIC_ADC_ENBL | MSIC_ADC_START);
} else {
data &= (~MSIC_ADC_START);
}
return intel_msic_reg_write(INTEL_MSIC_ADC1CNTL1, data);
}
static int set_up_therm_channel(u16 base_addr)
{
int ret;
ret = intel_msic_reg_write(base_addr, SKIN_SENSOR0_CODE);
if (ret)
return ret;
ret = intel_msic_reg_write(base_addr + 1, SKIN_SENSOR1_CODE);
if (ret)
return ret;
ret = intel_msic_reg_write(base_addr + 2, SYS_SENSOR_CODE);
if (ret)
return ret;
ret = intel_msic_reg_write(base_addr + 3,
(MSIC_DIE_SENSOR_CODE | 0x10));
if (ret)
return ret;
return configure_adc(1);
}
static int reset_stopbit(uint16_t addr)
{
int ret;
uint8_t data;
ret = intel_msic_reg_read(addr, &data);
if (ret)
return ret;
return intel_msic_reg_write(addr, (data & 0xEF));
}
static int find_free_channel(void)
{
int ret;
int i;
uint8_t data;
ret = intel_msic_reg_read(INTEL_MSIC_ADC1CNTL1, &data);
if (ret)
return ret;
if ((data & MSIC_ADC_ENBL) == 0)
return 0;
for (i = 0; i < ADC_CHANLS_MAX; i++) {
ret = intel_msic_reg_read(ADC_CHNL_START_ADDR + i, &data);
if (ret)
return ret;
if (data & MSIC_STOPBIT_MASK) {
ret = i;
break;
}
}
return (ret > ADC_LOOP_MAX) ? (-EINVAL) : ret;
}
static int mid_initialize_adc(struct device *dev)
{
u8 data;
u16 base_addr;
int ret;
ret = intel_msic_reg_read(INTEL_MSIC_ADC1CNTL3, &data);
if (ret)
return ret;
data &= ~MSIC_ADCTHERM_MASK;
ret = intel_msic_reg_write(INTEL_MSIC_ADC1CNTL3, data);
if (ret)
return ret;
channel_index = find_free_channel();
if (channel_index < 0) {
dev_err(dev, "No free ADC channels");
return channel_index;
}
base_addr = ADC_CHNL_START_ADDR + channel_index;
if (!(channel_index == 0 || channel_index == ADC_LOOP_MAX)) {
ret = reset_stopbit(base_addr);
if (ret)
return ret;
base_addr++;
channel_index++;
}
ret = set_up_therm_channel(base_addr);
if (ret) {
dev_err(dev, "unable to enable ADC");
return ret;
}
dev_dbg(dev, "ADC initialization successful");
return ret;
}
static struct thermal_device_info *initialize_sensor(int index)
{
struct thermal_device_info *td_info =
kzalloc(sizeof(struct thermal_device_info), GFP_KERNEL);
if (!td_info)
return NULL;
td_info->chnl_addr = ADC_DATA_START_ADDR + 2 * (channel_index + index);
if (index == 3)
td_info->direct = 1;
return td_info;
}
static int mid_thermal_resume(struct device *dev)
{
return mid_initialize_adc(dev);
}
static int mid_thermal_suspend(struct device *dev)
{
return configure_adc(0);
}
static int read_curr_temp(struct thermal_zone_device *tzd, unsigned long *temp)
{
WARN_ON(tzd == NULL);
return mid_read_temp(tzd, temp);
}
static int mid_thermal_probe(struct platform_device *pdev)
{
static char *name[MSIC_THERMAL_SENSORS] = {
"skin0", "skin1", "sys", "msicdie"
};
int ret;
int i;
struct platform_info *pinfo;
pinfo = kzalloc(sizeof(struct platform_info), GFP_KERNEL);
if (!pinfo)
return -ENOMEM;
ret = mid_initialize_adc(&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "ADC init failed");
kfree(pinfo);
return ret;
}
for (i = 0; i < MSIC_THERMAL_SENSORS; i++) {
struct thermal_device_info *td_info = initialize_sensor(i);
if (!td_info) {
ret = -ENOMEM;
goto err;
}
pinfo->tzd[i] = thermal_zone_device_register(name[i],
0, 0, td_info, &tzd_ops, NULL, 0, 0);
if (IS_ERR(pinfo->tzd[i])) {
kfree(td_info);
ret = PTR_ERR(pinfo->tzd[i]);
goto err;
}
}
pinfo->pdev = pdev;
platform_set_drvdata(pdev, pinfo);
return 0;
err:
while (--i >= 0) {
kfree(pinfo->tzd[i]->devdata);
thermal_zone_device_unregister(pinfo->tzd[i]);
}
configure_adc(0);
kfree(pinfo);
return ret;
}
static int mid_thermal_remove(struct platform_device *pdev)
{
int i;
struct platform_info *pinfo = platform_get_drvdata(pdev);
for (i = 0; i < MSIC_THERMAL_SENSORS; i++) {
kfree(pinfo->tzd[i]->devdata);
thermal_zone_device_unregister(pinfo->tzd[i]);
}
kfree(pinfo);
platform_set_drvdata(pdev, NULL);
return configure_adc(0);
}
