static u32 rk_tsadcv2_temp_to_code(struct chip_tsadc_table table,
int temp)
{
int high, low, mid;
low = 0;
high = table.length - 1;
mid = (high + low) / 2;
if (temp < table.id[low].temp || temp > table.id[high].temp)
return 0;
while (low <= high) {
if (temp == table.id[mid].temp)
return table.id[mid].code;
else if (temp < table.id[mid].temp)
high = mid - 1;
else
low = mid + 1;
mid = (low + high) / 2;
}
return 0;
}
static int rk_tsadcv2_code_to_temp(struct chip_tsadc_table table, u32 code,
int *temp)
{
unsigned int low = 1;
unsigned int high = table.length - 1;
unsigned int mid = (low + high) / 2;
unsigned int num;
unsigned long denom;
WARN_ON(table.length < 2);
switch (table.mode) {
case ADC_DECREMENT:
code &= table.data_mask;
if (code < table.id[high].code)
return -EAGAIN;
while (low <= high) {
if (code >= table.id[mid].code &&
code < table.id[mid - 1].code)
break;
else if (code < table.id[mid].code)
low = mid + 1;
else
high = mid - 1;
mid = (low + high) / 2;
}
break;
case ADC_INCREMENT:
code &= table.data_mask;
if (code < table.id[low].code)
return -EAGAIN;
while (low <= high) {
if (code >= table.id[mid - 1].code &&
code < table.id[mid].code)
break;
else if (code > table.id[mid].code)
low = mid + 1;
else
high = mid - 1;
mid = (low + high) / 2;
}
break;
default:
pr_err("Invalid the conversion table\n");
}
num = table.id[mid].temp - v2_code_table[mid - 1].temp;
num *= abs(table.id[mid - 1].code - code);
denom = abs(table.id[mid - 1].code - table.id[mid].code);
*temp = table.id[mid - 1].temp + (num / denom);
return 0;
}
static void rk_tsadcv2_initialize(void __iomem *regs,
enum tshut_polarity tshut_polarity)
{
if (tshut_polarity == TSHUT_HIGH_ACTIVE)
writel_relaxed(0U | TSADCV2_AUTO_TSHUT_POLARITY_HIGH,
regs + TSADCV2_AUTO_CON);
else
writel_relaxed(0U & ~TSADCV2_AUTO_TSHUT_POLARITY_HIGH,
regs + TSADCV2_AUTO_CON);
writel_relaxed(TSADCV2_AUTO_PERIOD_TIME, regs + TSADCV2_AUTO_PERIOD);
writel_relaxed(TSADCV2_HIGHT_INT_DEBOUNCE_COUNT,
regs + TSADCV2_HIGHT_INT_DEBOUNCE);
writel_relaxed(TSADCV2_AUTO_PERIOD_HT_TIME,
regs + TSADCV2_AUTO_PERIOD_HT);
writel_relaxed(TSADCV2_HIGHT_TSHUT_DEBOUNCE_COUNT,
regs + TSADCV2_HIGHT_TSHUT_DEBOUNCE);
}
static void rk_tsadcv1_irq_ack(void __iomem *regs)
{
u32 val;
val = readl_relaxed(regs + TSADCV2_INT_PD);
writel_relaxed(val & TSADCV1_INT_PD_CLEAR_MASK, regs + TSADCV2_INT_PD);
}
static void rk_tsadcv2_irq_ack(void __iomem *regs)
{
u32 val;
val = readl_relaxed(regs + TSADCV2_INT_PD);
writel_relaxed(val & TSADCV2_INT_PD_CLEAR_MASK, regs + TSADCV2_INT_PD);
}
static void rk_tsadcv2_control(void __iomem *regs, bool enable)
{
u32 val;
val = readl_relaxed(regs + TSADCV2_AUTO_CON);
if (enable)
val |= TSADCV2_AUTO_EN;
else
val &= ~TSADCV2_AUTO_EN;
writel_relaxed(val, regs + TSADCV2_AUTO_CON);
}
static int rk_tsadcv2_get_temp(struct chip_tsadc_table table,
int chn, void __iomem *regs, int *temp)
{
u32 val;
val = readl_relaxed(regs + TSADCV2_DATA(chn));
return rk_tsadcv2_code_to_temp(table, val, temp);
}
static void rk_tsadcv2_tshut_temp(struct chip_tsadc_table table,
int chn, void __iomem *regs, int temp)
{
u32 tshut_value, val;
tshut_value = rk_tsadcv2_temp_to_code(table, temp);
writel_relaxed(tshut_value, regs + TSADCV2_COMP_SHUT(chn));
val = readl_relaxed(regs + TSADCV2_AUTO_CON);
writel_relaxed(val | TSADCV2_AUTO_SRC_EN(chn), regs + TSADCV2_AUTO_CON);
}
static void rk_tsadcv2_tshut_mode(int chn, void __iomem *regs,
enum tshut_mode mode)
{
u32 val;
val = readl_relaxed(regs + TSADCV2_INT_EN);
if (mode == TSHUT_MODE_GPIO) {
val &= ~TSADCV2_SHUT_2CRU_SRC_EN(chn);
val |= TSADCV2_SHUT_2GPIO_SRC_EN(chn);
} else {
val &= ~TSADCV2_SHUT_2GPIO_SRC_EN(chn);
val |= TSADCV2_SHUT_2CRU_SRC_EN(chn);
}
writel_relaxed(val, regs + TSADCV2_INT_EN);
}
static void
rockchip_thermal_toggle_sensor(struct rockchip_thermal_sensor *sensor, bool on)
{
struct thermal_zone_device *tzd = sensor->tzd;
tzd->ops->set_mode(tzd,
on ? THERMAL_DEVICE_ENABLED : THERMAL_DEVICE_DISABLED);
}
static irqreturn_t rockchip_thermal_alarm_irq_thread(int irq, void *dev)
{
struct rockchip_thermal_data *thermal = dev;
int i;
dev_dbg(&thermal->pdev->dev, "thermal alarm\n");
thermal->chip->irq_ack(thermal->regs);
for (i = 0; i < thermal->chip->chn_num; i++)
thermal_zone_device_update(thermal->sensors[i].tzd);
return IRQ_HANDLED;
}
static int rockchip_thermal_get_temp(void *_sensor, int *out_temp)
{
struct rockchip_thermal_sensor *sensor = _sensor;
struct rockchip_thermal_data *thermal = sensor->thermal;
const struct rockchip_tsadc_chip *tsadc = sensor->thermal->chip;
int retval;
retval = tsadc->get_temp(tsadc->table,
sensor->id, thermal->regs, out_temp);
dev_dbg(&thermal->pdev->dev, "sensor %d - temp: %d, retval: %d\n",
sensor->id, *out_temp, retval);
return retval;
}
static int rockchip_configure_from_dt(struct device *dev,
struct device_node *np,
struct rockchip_thermal_data *thermal)
{
u32 shut_temp, tshut_mode, tshut_polarity;
if (of_property_read_u32(np, "rockchip,hw-tshut-temp", &shut_temp)) {
dev_warn(dev,
"Missing tshut temp property, using default %d\n",
thermal->chip->tshut_temp);
thermal->tshut_temp = thermal->chip->tshut_temp;
} else {
thermal->tshut_temp = shut_temp;
}
if (thermal->tshut_temp > INT_MAX) {
dev_err(dev, "Invalid tshut temperature specified: %d\n",
thermal->tshut_temp);
return -ERANGE;
}
if (of_property_read_u32(np, "rockchip,hw-tshut-mode", &tshut_mode)) {
dev_warn(dev,
"Missing tshut mode property, using default (%s)\n",
thermal->chip->tshut_mode == TSHUT_MODE_GPIO ?
"gpio" : "cru");
thermal->tshut_mode = thermal->chip->tshut_mode;
} else {
thermal->tshut_mode = tshut_mode;
}
if (thermal->tshut_mode > 1) {
dev_err(dev, "Invalid tshut mode specified: %d\n",
thermal->tshut_mode);
return -EINVAL;
}
if (of_property_read_u32(np, "rockchip,hw-tshut-polarity",
&tshut_polarity)) {
dev_warn(dev,
"Missing tshut-polarity property, using default (%s)\n",
thermal->chip->tshut_polarity == TSHUT_LOW_ACTIVE ?
"low" : "high");
thermal->tshut_polarity = thermal->chip->tshut_polarity;
} else {
thermal->tshut_polarity = tshut_polarity;
}
if (thermal->tshut_polarity > 1) {
dev_err(dev, "Invalid tshut-polarity specified: %d\n",
thermal->tshut_polarity);
return -EINVAL;
}
return 0;
}
static int
rockchip_thermal_register_sensor(struct platform_device *pdev,
struct rockchip_thermal_data *thermal,
struct rockchip_thermal_sensor *sensor,
int id)
{
const struct rockchip_tsadc_chip *tsadc = thermal->chip;
int error;
tsadc->set_tshut_mode(id, thermal->regs, thermal->tshut_mode);
tsadc->set_tshut_temp(tsadc->table, id, thermal->regs,
thermal->tshut_temp);
sensor->thermal = thermal;
sensor->id = id;
sensor->tzd = thermal_zone_of_sensor_register(&pdev->dev, id, sensor,
&rockchip_of_thermal_ops);
if (IS_ERR(sensor->tzd)) {
error = PTR_ERR(sensor->tzd);
dev_err(&pdev->dev, "failed to register sensor %d: %d\n",
id, error);
return error;
}
return 0;
}
static void rockchip_thermal_reset_controller(struct reset_control *reset)
{
reset_control_assert(reset);
usleep_range(10, 20);
reset_control_deassert(reset);
}
static int rockchip_thermal_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct rockchip_thermal_data *thermal;
const struct of_device_id *match;
struct resource *res;
int irq;
int i, j;
int error;
match = of_match_node(of_rockchip_thermal_match, np);
if (!match)
return -ENXIO;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return -EINVAL;
}
thermal = devm_kzalloc(&pdev->dev, sizeof(struct rockchip_thermal_data),
GFP_KERNEL);
if (!thermal)
return -ENOMEM;
thermal->pdev = pdev;
thermal->chip = (const struct rockchip_tsadc_chip *)match->data;
if (!thermal->chip)
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
thermal->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(thermal->regs))
return PTR_ERR(thermal->regs);
thermal->reset = devm_reset_control_get(&pdev->dev, "tsadc-apb");
if (IS_ERR(thermal->reset)) {
error = PTR_ERR(thermal->reset);
dev_err(&pdev->dev, "failed to get tsadc reset: %d\n", error);
return error;
}
thermal->clk = devm_clk_get(&pdev->dev, "tsadc");
if (IS_ERR(thermal->clk)) {
error = PTR_ERR(thermal->clk);
dev_err(&pdev->dev, "failed to get tsadc clock: %d\n", error);
return error;
}
thermal->pclk = devm_clk_get(&pdev->dev, "apb_pclk");
if (IS_ERR(thermal->pclk)) {
error = PTR_ERR(thermal->pclk);
dev_err(&pdev->dev, "failed to get apb_pclk clock: %d\n",
error);
return error;
}
error = clk_prepare_enable(thermal->clk);
if (error) {
dev_err(&pdev->dev, "failed to enable converter clock: %d\n",
error);
return error;
}
error = clk_prepare_enable(thermal->pclk);
if (error) {
dev_err(&pdev->dev, "failed to enable pclk: %d\n", error);
goto err_disable_clk;
}
rockchip_thermal_reset_controller(thermal->reset);
error = rockchip_configure_from_dt(&pdev->dev, np, thermal);
if (error) {
dev_err(&pdev->dev, "failed to parse device tree data: %d\n",
error);
goto err_disable_pclk;
}
thermal->chip->initialize(thermal->regs, thermal->tshut_polarity);
for (i = 0; i < thermal->chip->chn_num; i++) {
error = rockchip_thermal_register_sensor(pdev, thermal,
&thermal->sensors[i],
thermal->chip->chn_id[i]);
if (error) {
dev_err(&pdev->dev,
"failed to register sensor[%d] : error = %d\n",
i, error);
for (j = 0; j < i; j++)
thermal_zone_of_sensor_unregister(&pdev->dev,
thermal->sensors[j].tzd);
goto err_disable_pclk;
}
}
error = devm_request_threaded_irq(&pdev->dev, irq, NULL,
&rockchip_thermal_alarm_irq_thread,
IRQF_ONESHOT,
"rockchip_thermal", thermal);
if (error) {
dev_err(&pdev->dev,
"failed to request tsadc irq: %d\n", error);
goto err_unregister_sensor;
}
thermal->chip->control(thermal->regs, true);
for (i = 0; i < thermal->chip->chn_num; i++)
rockchip_thermal_toggle_sensor(&thermal->sensors[i], true);
platform_set_drvdata(pdev, thermal);
return 0;
err_unregister_sensor:
while (i--)
thermal_zone_of_sensor_unregister(&pdev->dev,
thermal->sensors[i].tzd);
err_disable_pclk:
clk_disable_unprepare(thermal->pclk);
err_disable_clk:
clk_disable_unprepare(thermal->clk);
return error;
}
static int rockchip_thermal_remove(struct platform_device *pdev)
{
struct rockchip_thermal_data *thermal = platform_get_drvdata(pdev);
int i;
for (i = 0; i < thermal->chip->chn_num; i++) {
struct rockchip_thermal_sensor *sensor = &thermal->sensors[i];
rockchip_thermal_toggle_sensor(sensor, false);
thermal_zone_of_sensor_unregister(&pdev->dev, sensor->tzd);
}
thermal->chip->control(thermal->regs, false);
clk_disable_unprepare(thermal->pclk);
clk_disable_unprepare(thermal->clk);
return 0;
}
static int __maybe_unused rockchip_thermal_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct rockchip_thermal_data *thermal = platform_get_drvdata(pdev);
int i;
for (i = 0; i < thermal->chip->chn_num; i++)
rockchip_thermal_toggle_sensor(&thermal->sensors[i], false);
thermal->chip->control(thermal->regs, false);
clk_disable(thermal->pclk);
clk_disable(thermal->clk);
pinctrl_pm_select_sleep_state(dev);
return 0;
}
static int __maybe_unused rockchip_thermal_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct rockchip_thermal_data *thermal = platform_get_drvdata(pdev);
int i;
int error;
error = clk_enable(thermal->clk);
if (error)
return error;
error = clk_enable(thermal->pclk);
if (error)
return error;
rockchip_thermal_reset_controller(thermal->reset);
thermal->chip->initialize(thermal->regs, thermal->tshut_polarity);
for (i = 0; i < thermal->chip->chn_num; i++) {
int id = thermal->sensors[i].id;
thermal->chip->set_tshut_mode(id, thermal->regs,
thermal->tshut_mode);
thermal->chip->set_tshut_temp(thermal->chip->table,
id, thermal->regs,
thermal->tshut_temp);
}
thermal->chip->control(thermal->regs, true);
for (i = 0; i < thermal->chip->chn_num; i++)
rockchip_thermal_toggle_sensor(&thermal->sensors[i], true);
pinctrl_pm_select_default_state(dev);
return 0;
}
