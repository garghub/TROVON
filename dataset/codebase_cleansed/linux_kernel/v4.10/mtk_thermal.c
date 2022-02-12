static int raw_to_mcelsius(struct mtk_thermal *mt, int sensno, s32 raw)
{
s32 tmp;
raw &= 0xfff;
tmp = 203450520 << 3;
tmp /= 165 + mt->o_slope;
tmp /= 10000 + mt->adc_ge;
tmp *= raw - mt->vts[sensno] - 3350;
tmp >>= 3;
return mt->degc_cali * 500 - tmp;
}
static void mtk_thermal_get_bank(struct mtk_thermal_bank *bank)
{
struct mtk_thermal *mt = bank->mt;
u32 val;
mutex_lock(&mt->lock);
val = readl(mt->thermal_base + PTPCORESEL);
val &= ~0xf;
val |= bank->id;
writel(val, mt->thermal_base + PTPCORESEL);
}
static void mtk_thermal_put_bank(struct mtk_thermal_bank *bank)
{
struct mtk_thermal *mt = bank->mt;
mutex_unlock(&mt->lock);
}
static int mtk_thermal_bank_temperature(struct mtk_thermal_bank *bank)
{
struct mtk_thermal *mt = bank->mt;
const struct mtk_thermal_data *conf = mt->conf;
int i, temp = INT_MIN, max = INT_MIN;
u32 raw;
for (i = 0; i < conf->bank_data[bank->id].num_sensors; i++) {
raw = readl(mt->thermal_base + conf->msr[i]);
temp = raw_to_mcelsius(mt,
conf->bank_data[bank->id].sensors[i],
raw);
if (temp > 200000)
temp = 0;
if (temp > max)
max = temp;
}
return max;
}
static int mtk_read_temp(void *data, int *temperature)
{
struct mtk_thermal *mt = data;
int i;
int tempmax = INT_MIN;
for (i = 0; i < mt->conf->num_banks; i++) {
struct mtk_thermal_bank *bank = &mt->banks[i];
mtk_thermal_get_bank(bank);
tempmax = max(tempmax, mtk_thermal_bank_temperature(bank));
mtk_thermal_put_bank(bank);
}
*temperature = tempmax;
return 0;
}
static void mtk_thermal_init_bank(struct mtk_thermal *mt, int num,
u32 apmixed_phys_base, u32 auxadc_phys_base)
{
struct mtk_thermal_bank *bank = &mt->banks[num];
const struct mtk_thermal_data *conf = mt->conf;
int i;
bank->id = num;
bank->mt = mt;
mtk_thermal_get_bank(bank);
writel(TEMP_MONCTL1_PERIOD_UNIT(12), mt->thermal_base + TEMP_MONCTL1);
writel(TEMP_MONCTL2_FILTER_INTERVAL(1) |
TEMP_MONCTL2_SENSOR_INTERVAL(429),
mt->thermal_base + TEMP_MONCTL2);
writel(TEMP_AHBPOLL_ADC_POLL_INTERVAL(768),
mt->thermal_base + TEMP_AHBPOLL);
writel(0x0, mt->thermal_base + TEMP_MSRCTL0);
writel(0xffffffff, mt->thermal_base + TEMP_AHBTO);
writel(0x0, mt->thermal_base + TEMP_MONIDET0);
writel(0x0, mt->thermal_base + TEMP_MONIDET1);
writel(BIT(conf->auxadc_channel), mt->thermal_base + TEMP_ADCMUX);
writel(auxadc_phys_base + AUXADC_CON1_CLR_V,
mt->thermal_base + TEMP_ADCMUXADDR);
writel(apmixed_phys_base + APMIXED_SYS_TS_CON1,
mt->thermal_base + TEMP_PNPMUXADDR);
writel(BIT(conf->auxadc_channel), mt->thermal_base + TEMP_ADCEN);
writel(auxadc_phys_base + AUXADC_CON1_SET_V,
mt->thermal_base + TEMP_ADCENADDR);
writel(auxadc_phys_base + AUXADC_DATA(conf->auxadc_channel),
mt->thermal_base + TEMP_ADCVALIDADDR);
writel(auxadc_phys_base + AUXADC_DATA(conf->auxadc_channel),
mt->thermal_base + TEMP_ADCVOLTADDR);
writel(0x0, mt->thermal_base + TEMP_RDCTRL);
writel(TEMP_ADCVALIDMASK_VALID_HIGH | TEMP_ADCVALIDMASK_VALID_POS(12),
mt->thermal_base + TEMP_ADCVALIDMASK);
writel(0x0, mt->thermal_base + TEMP_ADCVOLTAGESHIFT);
writel(TEMP_ADCWRITECTRL_ADC_MUX_WRITE,
mt->thermal_base + TEMP_ADCWRITECTRL);
for (i = 0; i < conf->bank_data[num].num_sensors; i++)
writel(conf->sensor_mux_values[conf->bank_data[num].sensors[i]],
mt->thermal_base + conf->adcpnp[i]);
writel((1 << conf->bank_data[num].num_sensors) - 1,
mt->thermal_base + TEMP_MONCTL0);
writel(TEMP_ADCWRITECTRL_ADC_PNP_WRITE |
TEMP_ADCWRITECTRL_ADC_MUX_WRITE,
mt->thermal_base + TEMP_ADCWRITECTRL);
mtk_thermal_put_bank(bank);
}
static u64 of_get_phys_base(struct device_node *np)
{
u64 size64;
const __be32 *regaddr_p;
regaddr_p = of_get_address(np, 0, &size64, NULL);
if (!regaddr_p)
return OF_BAD_ADDR;
return of_translate_address(np, regaddr_p);
}
static int mtk_thermal_get_calibration_data(struct device *dev,
struct mtk_thermal *mt)
{
struct nvmem_cell *cell;
u32 *buf;
size_t len;
int i, ret = 0;
mt->adc_ge = 512;
for (i = 0; i < mt->conf->num_sensors; i++)
mt->vts[i] = 260;
mt->degc_cali = 40;
mt->o_slope = 0;
cell = nvmem_cell_get(dev, "calibration-data");
if (IS_ERR(cell)) {
if (PTR_ERR(cell) == -EPROBE_DEFER)
return PTR_ERR(cell);
return 0;
}
buf = (u32 *)nvmem_cell_read(cell, &len);
nvmem_cell_put(cell);
if (IS_ERR(buf))
return PTR_ERR(buf);
if (len < 3 * sizeof(u32)) {
dev_warn(dev, "invalid calibration data\n");
ret = -EINVAL;
goto out;
}
if (buf[0] & MT8173_CALIB_BUF0_VALID) {
mt->adc_ge = MT8173_CALIB_BUF1_ADC_GE(buf[1]);
mt->vts[MT8173_TS1] = MT8173_CALIB_BUF0_VTS_TS1(buf[0]);
mt->vts[MT8173_TS2] = MT8173_CALIB_BUF0_VTS_TS2(buf[0]);
mt->vts[MT8173_TS3] = MT8173_CALIB_BUF1_VTS_TS3(buf[1]);
mt->vts[MT8173_TS4] = MT8173_CALIB_BUF2_VTS_TS4(buf[2]);
mt->vts[MT8173_TSABB] = MT8173_CALIB_BUF2_VTS_TSABB(buf[2]);
mt->degc_cali = MT8173_CALIB_BUF0_DEGC_CALI(buf[0]);
mt->o_slope = MT8173_CALIB_BUF0_O_SLOPE(buf[0]);
} else {
dev_info(dev, "Device not calibrated, using default calibration values\n");
}
out:
kfree(buf);
return ret;
}
static int mtk_thermal_probe(struct platform_device *pdev)
{
int ret, i;
struct device_node *auxadc, *apmixedsys, *np = pdev->dev.of_node;
struct mtk_thermal *mt;
struct resource *res;
const struct of_device_id *of_id;
u64 auxadc_phys_base, apmixed_phys_base;
struct thermal_zone_device *tzdev;
mt = devm_kzalloc(&pdev->dev, sizeof(*mt), GFP_KERNEL);
if (!mt)
return -ENOMEM;
of_id = of_match_device(mtk_thermal_of_match, &pdev->dev);
if (of_id)
mt->conf = (const struct mtk_thermal_data *)of_id->data;
mt->clk_peri_therm = devm_clk_get(&pdev->dev, "therm");
if (IS_ERR(mt->clk_peri_therm))
return PTR_ERR(mt->clk_peri_therm);
mt->clk_auxadc = devm_clk_get(&pdev->dev, "auxadc");
if (IS_ERR(mt->clk_auxadc))
return PTR_ERR(mt->clk_auxadc);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mt->thermal_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mt->thermal_base))
return PTR_ERR(mt->thermal_base);
ret = mtk_thermal_get_calibration_data(&pdev->dev, mt);
if (ret)
return ret;
mutex_init(&mt->lock);
mt->dev = &pdev->dev;
auxadc = of_parse_phandle(np, "mediatek,auxadc", 0);
if (!auxadc) {
dev_err(&pdev->dev, "missing auxadc node\n");
return -ENODEV;
}
auxadc_phys_base = of_get_phys_base(auxadc);
of_node_put(auxadc);
if (auxadc_phys_base == OF_BAD_ADDR) {
dev_err(&pdev->dev, "Can't get auxadc phys address\n");
return -EINVAL;
}
apmixedsys = of_parse_phandle(np, "mediatek,apmixedsys", 0);
if (!apmixedsys) {
dev_err(&pdev->dev, "missing apmixedsys node\n");
return -ENODEV;
}
apmixed_phys_base = of_get_phys_base(apmixedsys);
of_node_put(apmixedsys);
if (apmixed_phys_base == OF_BAD_ADDR) {
dev_err(&pdev->dev, "Can't get auxadc phys address\n");
return -EINVAL;
}
ret = clk_prepare_enable(mt->clk_auxadc);
if (ret) {
dev_err(&pdev->dev, "Can't enable auxadc clk: %d\n", ret);
return ret;
}
ret = device_reset(&pdev->dev);
if (ret)
goto err_disable_clk_auxadc;
ret = clk_prepare_enable(mt->clk_peri_therm);
if (ret) {
dev_err(&pdev->dev, "Can't enable peri clk: %d\n", ret);
goto err_disable_clk_auxadc;
}
for (i = 0; i < mt->conf->num_banks; i++)
mtk_thermal_init_bank(mt, i, apmixed_phys_base,
auxadc_phys_base);
platform_set_drvdata(pdev, mt);
tzdev = devm_thermal_zone_of_sensor_register(&pdev->dev, 0, mt,
&mtk_thermal_ops);
if (IS_ERR(tzdev)) {
ret = PTR_ERR(tzdev);
goto err_disable_clk_peri_therm;
}
return 0;
err_disable_clk_peri_therm:
clk_disable_unprepare(mt->clk_peri_therm);
err_disable_clk_auxadc:
clk_disable_unprepare(mt->clk_auxadc);
return ret;
}
static int mtk_thermal_remove(struct platform_device *pdev)
{
struct mtk_thermal *mt = platform_get_drvdata(pdev);
clk_disable_unprepare(mt->clk_peri_therm);
clk_disable_unprepare(mt->clk_auxadc);
return 0;
}
