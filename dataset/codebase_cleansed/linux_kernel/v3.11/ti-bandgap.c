static u32 ti_bandgap_readl(struct ti_bandgap *bgp, u32 reg)
{
return readl(bgp->base + reg);
}
static void ti_bandgap_writel(struct ti_bandgap *bgp, u32 val, u32 reg)
{
writel(val, bgp->base + reg);
}
static int ti_bandgap_power(struct ti_bandgap *bgp, bool on)
{
int i, ret = 0;
if (!TI_BANDGAP_HAS(bgp, POWER_SWITCH)) {
ret = -ENOTSUPP;
goto exit;
}
for (i = 0; i < bgp->conf->sensor_count; i++)
RMW_BITS(bgp, i, temp_sensor_ctrl, bgap_tempsoff_mask, !on);
exit:
return ret;
}
static u32 ti_bandgap_read_temp(struct ti_bandgap *bgp, int id)
{
struct temp_sensor_registers *tsr;
u32 temp, reg;
tsr = bgp->conf->sensors[id].registers;
reg = tsr->temp_sensor_ctrl;
if (TI_BANDGAP_HAS(bgp, FREEZE_BIT)) {
RMW_BITS(bgp, id, bgap_mask_ctrl, mask_freeze_mask, 1);
reg = tsr->ctrl_dtemp_1;
}
temp = ti_bandgap_readl(bgp, reg);
temp &= tsr->bgap_dtemp_mask;
if (TI_BANDGAP_HAS(bgp, FREEZE_BIT))
RMW_BITS(bgp, id, bgap_mask_ctrl, mask_freeze_mask, 0);
return temp;
}
static irqreturn_t ti_bandgap_talert_irq_handler(int irq, void *data)
{
struct ti_bandgap *bgp = data;
struct temp_sensor_registers *tsr;
u32 t_hot = 0, t_cold = 0, ctrl;
int i;
spin_lock(&bgp->lock);
for (i = 0; i < bgp->conf->sensor_count; i++) {
tsr = bgp->conf->sensors[i].registers;
ctrl = ti_bandgap_readl(bgp, tsr->bgap_status);
t_hot = ctrl & tsr->status_hot_mask;
t_cold = ctrl & tsr->status_cold_mask;
if (!t_cold && !t_hot)
continue;
ctrl = ti_bandgap_readl(bgp, tsr->bgap_mask_ctrl);
if (t_hot) {
ctrl &= ~tsr->mask_hot_mask;
ctrl |= tsr->mask_cold_mask;
} else if (t_cold) {
ctrl &= ~tsr->mask_cold_mask;
ctrl |= tsr->mask_hot_mask;
}
ti_bandgap_writel(bgp, ctrl, tsr->bgap_mask_ctrl);
dev_dbg(bgp->dev,
"%s: IRQ from %s sensor: hotevent %d coldevent %d\n",
__func__, bgp->conf->sensors[i].domain,
t_hot, t_cold);
if (bgp->conf->report_temperature)
bgp->conf->report_temperature(bgp, i);
}
spin_unlock(&bgp->lock);
return IRQ_HANDLED;
}
static irqreturn_t ti_bandgap_tshut_irq_handler(int irq, void *data)
{
pr_emerg("%s: TSHUT temperature reached. Needs shut down...\n",
__func__);
orderly_poweroff(true);
return IRQ_HANDLED;
}
static
int ti_bandgap_adc_to_mcelsius(struct ti_bandgap *bgp, int adc_val, int *t)
{
const struct ti_bandgap_data *conf = bgp->conf;
int ret = 0;
if (adc_val < conf->adc_start_val || adc_val > conf->adc_end_val) {
ret = -ERANGE;
goto exit;
}
*t = bgp->conf->conv_table[adc_val - conf->adc_start_val];
exit:
return ret;
}
static
int ti_bandgap_mcelsius_to_adc(struct ti_bandgap *bgp, long temp, int *adc)
{
const struct ti_bandgap_data *conf = bgp->conf;
const int *conv_table = bgp->conf->conv_table;
int high, low, mid, ret = 0;
low = 0;
high = conf->adc_end_val - conf->adc_start_val;
mid = (high + low) / 2;
if (temp < conv_table[low] || temp > conv_table[high]) {
ret = -ERANGE;
goto exit;
}
while (low < high) {
if (temp < conv_table[mid])
high = mid - 1;
else
low = mid + 1;
mid = (low + high) / 2;
}
*adc = conf->adc_start_val + low;
exit:
return ret;
}
static
int ti_bandgap_add_hyst(struct ti_bandgap *bgp, int adc_val, int hyst_val,
u32 *sum)
{
int temp, ret;
ret = ti_bandgap_adc_to_mcelsius(bgp, adc_val, &temp);
if (ret < 0)
goto exit;
temp += hyst_val;
ret = ti_bandgap_mcelsius_to_adc(bgp, temp, sum);
exit:
return ret;
}
static void ti_bandgap_unmask_interrupts(struct ti_bandgap *bgp, int id,
u32 t_hot, u32 t_cold)
{
struct temp_sensor_registers *tsr;
u32 temp, reg_val;
temp = ti_bandgap_read_temp(bgp, id);
tsr = bgp->conf->sensors[id].registers;
reg_val = ti_bandgap_readl(bgp, tsr->bgap_mask_ctrl);
if (temp < t_hot)
reg_val |= tsr->mask_hot_mask;
else
reg_val &= ~tsr->mask_hot_mask;
if (t_cold < temp)
reg_val |= tsr->mask_cold_mask;
else
reg_val &= ~tsr->mask_cold_mask;
ti_bandgap_writel(bgp, reg_val, tsr->bgap_mask_ctrl);
}
static int ti_bandgap_update_alert_threshold(struct ti_bandgap *bgp, int id,
int val, bool hot)
{
struct temp_sensor_data *ts_data = bgp->conf->sensors[id].ts_data;
struct temp_sensor_registers *tsr;
u32 thresh_val, reg_val, t_hot, t_cold;
int err = 0;
tsr = bgp->conf->sensors[id].registers;
thresh_val = ti_bandgap_readl(bgp, tsr->bgap_threshold);
t_cold = (thresh_val & tsr->threshold_tcold_mask) >>
__ffs(tsr->threshold_tcold_mask);
t_hot = (thresh_val & tsr->threshold_thot_mask) >>
__ffs(tsr->threshold_thot_mask);
if (hot)
t_hot = val;
else
t_cold = val;
if (t_cold > t_hot) {
if (hot)
err = ti_bandgap_add_hyst(bgp, t_hot,
-ts_data->hyst_val,
&t_cold);
else
err = ti_bandgap_add_hyst(bgp, t_cold,
ts_data->hyst_val,
&t_hot);
}
reg_val = thresh_val &
~(tsr->threshold_thot_mask | tsr->threshold_tcold_mask);
reg_val |= (t_hot << __ffs(tsr->threshold_thot_mask)) |
(t_cold << __ffs(tsr->threshold_tcold_mask));
ti_bandgap_writel(bgp, reg_val, tsr->bgap_threshold);
if (err) {
dev_err(bgp->dev, "failed to reprogram thot threshold\n");
err = -EIO;
goto exit;
}
ti_bandgap_unmask_interrupts(bgp, id, t_hot, t_cold);
exit:
return err;
}
static inline int ti_bandgap_validate(struct ti_bandgap *bgp, int id)
{
int ret = 0;
if (!bgp || IS_ERR(bgp)) {
pr_err("%s: invalid bandgap pointer\n", __func__);
ret = -EINVAL;
goto exit;
}
if ((id < 0) || (id >= bgp->conf->sensor_count)) {
dev_err(bgp->dev, "%s: sensor id out of range (%d)\n",
__func__, id);
ret = -ERANGE;
}
exit:
return ret;
}
static int _ti_bandgap_write_threshold(struct ti_bandgap *bgp, int id, int val,
bool hot)
{
struct temp_sensor_data *ts_data;
struct temp_sensor_registers *tsr;
u32 adc_val;
int ret;
ret = ti_bandgap_validate(bgp, id);
if (ret)
goto exit;
if (!TI_BANDGAP_HAS(bgp, TALERT)) {
ret = -ENOTSUPP;
goto exit;
}
ts_data = bgp->conf->sensors[id].ts_data;
tsr = bgp->conf->sensors[id].registers;
if (hot) {
if (val < ts_data->min_temp + ts_data->hyst_val)
ret = -EINVAL;
} else {
if (val > ts_data->max_temp + ts_data->hyst_val)
ret = -EINVAL;
}
if (ret)
goto exit;
ret = ti_bandgap_mcelsius_to_adc(bgp, val, &adc_val);
if (ret < 0)
goto exit;
spin_lock(&bgp->lock);
ret = ti_bandgap_update_alert_threshold(bgp, id, adc_val, hot);
spin_unlock(&bgp->lock);
exit:
return ret;
}
static int _ti_bandgap_read_threshold(struct ti_bandgap *bgp, int id,
int *val, bool hot)
{
struct temp_sensor_registers *tsr;
u32 temp, mask;
int ret = 0;
ret = ti_bandgap_validate(bgp, id);
if (ret)
goto exit;
if (!TI_BANDGAP_HAS(bgp, TALERT)) {
ret = -ENOTSUPP;
goto exit;
}
tsr = bgp->conf->sensors[id].registers;
if (hot)
mask = tsr->threshold_thot_mask;
else
mask = tsr->threshold_tcold_mask;
temp = ti_bandgap_readl(bgp, tsr->bgap_threshold);
temp = (temp & mask) >> __ffs(mask);
ret |= ti_bandgap_adc_to_mcelsius(bgp, temp, &temp);
if (ret) {
dev_err(bgp->dev, "failed to read thot\n");
ret = -EIO;
goto exit;
}
*val = temp;
exit:
return ret;
}
int ti_bandgap_read_thot(struct ti_bandgap *bgp, int id, int *thot)
{
return _ti_bandgap_read_threshold(bgp, id, thot, true);
}
int ti_bandgap_write_thot(struct ti_bandgap *bgp, int id, int val)
{
return _ti_bandgap_write_threshold(bgp, id, val, true);
}
int ti_bandgap_read_tcold(struct ti_bandgap *bgp, int id, int *tcold)
{
return _ti_bandgap_read_threshold(bgp, id, tcold, false);
}
int ti_bandgap_write_tcold(struct ti_bandgap *bgp, int id, int val)
{
return _ti_bandgap_write_threshold(bgp, id, val, false);
}
static void ti_bandgap_read_counter(struct ti_bandgap *bgp, int id,
int *interval)
{
struct temp_sensor_registers *tsr;
int time;
tsr = bgp->conf->sensors[id].registers;
time = ti_bandgap_readl(bgp, tsr->bgap_counter);
time = (time & tsr->counter_mask) >>
__ffs(tsr->counter_mask);
time = time * 1000 / bgp->clk_rate;
*interval = time;
}
static void ti_bandgap_read_counter_delay(struct ti_bandgap *bgp, int id,
int *interval)
{
struct temp_sensor_registers *tsr;
int reg_val;
tsr = bgp->conf->sensors[id].registers;
reg_val = ti_bandgap_readl(bgp, tsr->bgap_mask_ctrl);
reg_val = (reg_val & tsr->mask_counter_delay_mask) >>
__ffs(tsr->mask_counter_delay_mask);
switch (reg_val) {
case 0:
*interval = 0;
break;
case 1:
*interval = 1;
break;
case 2:
*interval = 10;
break;
case 3:
*interval = 100;
break;
case 4:
*interval = 250;
break;
case 5:
*interval = 500;
break;
default:
dev_warn(bgp->dev, "Wrong counter delay value read from register %X",
reg_val);
}
}
int ti_bandgap_read_update_interval(struct ti_bandgap *bgp, int id,
int *interval)
{
int ret = 0;
ret = ti_bandgap_validate(bgp, id);
if (ret)
goto exit;
if (!TI_BANDGAP_HAS(bgp, COUNTER) &&
!TI_BANDGAP_HAS(bgp, COUNTER_DELAY)) {
ret = -ENOTSUPP;
goto exit;
}
if (TI_BANDGAP_HAS(bgp, COUNTER)) {
ti_bandgap_read_counter(bgp, id, interval);
goto exit;
}
ti_bandgap_read_counter_delay(bgp, id, interval);
exit:
return ret;
}
static int ti_bandgap_write_counter_delay(struct ti_bandgap *bgp, int id,
u32 interval)
{
int rval;
switch (interval) {
case 0:
rval = 0x0;
break;
case 1:
rval = 0x1;
break;
case 10:
rval = 0x2;
break;
case 100:
rval = 0x3;
break;
case 250:
rval = 0x4;
break;
case 500:
rval = 0x5;
break;
default:
dev_warn(bgp->dev, "Delay %d ms is not supported\n", interval);
return -EINVAL;
}
spin_lock(&bgp->lock);
RMW_BITS(bgp, id, bgap_mask_ctrl, mask_counter_delay_mask, rval);
spin_unlock(&bgp->lock);
return 0;
}
static void ti_bandgap_write_counter(struct ti_bandgap *bgp, int id,
u32 interval)
{
interval = interval * bgp->clk_rate / 1000;
spin_lock(&bgp->lock);
RMW_BITS(bgp, id, bgap_counter, counter_mask, interval);
spin_unlock(&bgp->lock);
}
int ti_bandgap_write_update_interval(struct ti_bandgap *bgp,
int id, u32 interval)
{
int ret = ti_bandgap_validate(bgp, id);
if (ret)
goto exit;
if (!TI_BANDGAP_HAS(bgp, COUNTER) &&
!TI_BANDGAP_HAS(bgp, COUNTER_DELAY)) {
ret = -ENOTSUPP;
goto exit;
}
if (TI_BANDGAP_HAS(bgp, COUNTER)) {
ti_bandgap_write_counter(bgp, id, interval);
goto exit;
}
ret = ti_bandgap_write_counter_delay(bgp, id, interval);
exit:
return ret;
}
int ti_bandgap_read_temperature(struct ti_bandgap *bgp, int id,
int *temperature)
{
u32 temp;
int ret;
ret = ti_bandgap_validate(bgp, id);
if (ret)
return ret;
spin_lock(&bgp->lock);
temp = ti_bandgap_read_temp(bgp, id);
spin_unlock(&bgp->lock);
ret |= ti_bandgap_adc_to_mcelsius(bgp, temp, &temp);
if (ret)
return -EIO;
*temperature = temp;
return 0;
}
int ti_bandgap_set_sensor_data(struct ti_bandgap *bgp, int id, void *data)
{
int ret = ti_bandgap_validate(bgp, id);
if (ret)
return ret;
bgp->regval[id].data = data;
return 0;
}
void *ti_bandgap_get_sensor_data(struct ti_bandgap *bgp, int id)
{
int ret = ti_bandgap_validate(bgp, id);
if (ret)
return ERR_PTR(ret);
return bgp->regval[id].data;
}
static int
ti_bandgap_force_single_read(struct ti_bandgap *bgp, int id)
{
u32 temp = 0, counter = 1000;
if (TI_BANDGAP_HAS(bgp, MODE_CONFIG))
RMW_BITS(bgp, id, bgap_mode_ctrl, mode_ctrl_mask, 0);
RMW_BITS(bgp, id, temp_sensor_ctrl, bgap_soc_mask, 1);
temp = ti_bandgap_read_temp(bgp, id);
while ((temp == 0) && --counter)
temp = ti_bandgap_read_temp(bgp, id);
RMW_BITS(bgp, id, temp_sensor_ctrl, bgap_soc_mask, 0);
return 0;
}
static int ti_bandgap_set_continuous_mode(struct ti_bandgap *bgp)
{
int i;
for (i = 0; i < bgp->conf->sensor_count; i++) {
ti_bandgap_force_single_read(bgp, i);
RMW_BITS(bgp, i, bgap_mode_ctrl, mode_ctrl_mask, 1);
}
return 0;
}
int ti_bandgap_get_trend(struct ti_bandgap *bgp, int id, int *trend)
{
struct temp_sensor_registers *tsr;
u32 temp1, temp2, reg1, reg2;
int t1, t2, interval, ret = 0;
ret = ti_bandgap_validate(bgp, id);
if (ret)
goto exit;
if (!TI_BANDGAP_HAS(bgp, HISTORY_BUFFER) ||
!TI_BANDGAP_HAS(bgp, FREEZE_BIT)) {
ret = -ENOTSUPP;
goto exit;
}
spin_lock(&bgp->lock);
tsr = bgp->conf->sensors[id].registers;
RMW_BITS(bgp, id, bgap_mask_ctrl, mask_freeze_mask, 1);
reg1 = tsr->ctrl_dtemp_1;
reg2 = tsr->ctrl_dtemp_2;
temp1 = ti_bandgap_readl(bgp, reg1);
temp1 &= tsr->bgap_dtemp_mask;
temp2 = ti_bandgap_readl(bgp, reg2);
temp2 &= tsr->bgap_dtemp_mask;
ret = ti_bandgap_adc_to_mcelsius(bgp, temp1, &t1);
if (ret)
goto unfreeze;
ret = ti_bandgap_adc_to_mcelsius(bgp, temp2, &t2);
if (ret)
goto unfreeze;
ret = ti_bandgap_read_update_interval(bgp, id, &interval);
if (ret || !interval)
goto unfreeze;
*trend = (t1 - t2) / interval;
dev_dbg(bgp->dev, "The temperatures are t1 = %d and t2 = %d and trend =%d\n",
t1, t2, *trend);
unfreeze:
RMW_BITS(bgp, id, bgap_mask_ctrl, mask_freeze_mask, 0);
spin_unlock(&bgp->lock);
exit:
return ret;
}
static int ti_bandgap_tshut_init(struct ti_bandgap *bgp,
struct platform_device *pdev)
{
int gpio_nr = bgp->tshut_gpio;
int status;
status = gpio_request(gpio_nr, "tshut");
if (status < 0) {
dev_err(bgp->dev, "Could not request for TSHUT GPIO:%i\n", 86);
return status;
}
status = gpio_direction_input(gpio_nr);
if (status) {
dev_err(bgp->dev, "Cannot set input TSHUT GPIO %d\n", gpio_nr);
return status;
}
status = request_irq(gpio_to_irq(gpio_nr), ti_bandgap_tshut_irq_handler,
IRQF_TRIGGER_RISING, "tshut", NULL);
if (status) {
gpio_free(gpio_nr);
dev_err(bgp->dev, "request irq failed for TSHUT");
}
return 0;
}
static int ti_bandgap_talert_init(struct ti_bandgap *bgp,
struct platform_device *pdev)
{
int ret;
bgp->irq = platform_get_irq(pdev, 0);
if (bgp->irq < 0) {
dev_err(&pdev->dev, "get_irq failed\n");
return bgp->irq;
}
ret = request_threaded_irq(bgp->irq, NULL,
ti_bandgap_talert_irq_handler,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
"talert", bgp);
if (ret) {
dev_err(&pdev->dev, "Request threaded irq failed.\n");
return ret;
}
return 0;
}
static struct ti_bandgap *ti_bandgap_build(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
const struct of_device_id *of_id;
struct ti_bandgap *bgp;
struct resource *res;
int i;
if (!node) {
dev_err(&pdev->dev, "no platform information available\n");
return ERR_PTR(-EINVAL);
}
bgp = devm_kzalloc(&pdev->dev, sizeof(*bgp), GFP_KERNEL);
if (!bgp) {
dev_err(&pdev->dev, "Unable to allocate mem for driver ref\n");
return ERR_PTR(-ENOMEM);
}
of_id = of_match_device(of_ti_bandgap_match, &pdev->dev);
if (of_id)
bgp->conf = of_id->data;
bgp->regval = devm_kzalloc(&pdev->dev, sizeof(*bgp->regval) *
bgp->conf->sensor_count, GFP_KERNEL);
if (!bgp) {
dev_err(&pdev->dev, "Unable to allocate mem for driver ref\n");
return ERR_PTR(-ENOMEM);
}
i = 0;
do {
void __iomem *chunk;
res = platform_get_resource(pdev, IORESOURCE_MEM, i);
if (!res)
break;
chunk = devm_ioremap_resource(&pdev->dev, res);
if (i == 0)
bgp->base = chunk;
if (IS_ERR(chunk))
return ERR_CAST(chunk);
i++;
} while (res);
if (TI_BANDGAP_HAS(bgp, TSHUT)) {
bgp->tshut_gpio = of_get_gpio(node, 0);
if (!gpio_is_valid(bgp->tshut_gpio)) {
dev_err(&pdev->dev, "invalid gpio for tshut (%d)\n",
bgp->tshut_gpio);
return ERR_PTR(-EINVAL);
}
}
return bgp;
}
static
int ti_bandgap_probe(struct platform_device *pdev)
{
struct ti_bandgap *bgp;
int clk_rate, ret = 0, i;
bgp = ti_bandgap_build(pdev);
if (IS_ERR(bgp)) {
dev_err(&pdev->dev, "failed to fetch platform data\n");
return PTR_ERR(bgp);
}
bgp->dev = &pdev->dev;
if (TI_BANDGAP_HAS(bgp, TSHUT)) {
ret = ti_bandgap_tshut_init(bgp, pdev);
if (ret) {
dev_err(&pdev->dev,
"failed to initialize system tshut IRQ\n");
return ret;
}
}
bgp->fclock = clk_get(NULL, bgp->conf->fclock_name);
ret = IS_ERR(bgp->fclock);
if (ret) {
dev_err(&pdev->dev, "failed to request fclock reference\n");
ret = PTR_ERR(bgp->fclock);
goto free_irqs;
}
bgp->div_clk = clk_get(NULL, bgp->conf->div_ck_name);
ret = IS_ERR(bgp->div_clk);
if (ret) {
dev_err(&pdev->dev,
"failed to request div_ts_ck clock ref\n");
ret = PTR_ERR(bgp->div_clk);
goto free_irqs;
}
for (i = 0; i < bgp->conf->sensor_count; i++) {
struct temp_sensor_registers *tsr;
u32 val;
tsr = bgp->conf->sensors[i].registers;
val = ti_bandgap_readl(bgp, tsr->bgap_efuse);
if (ret || !val)
dev_info(&pdev->dev,
"Non-trimmed BGAP, Temp not accurate\n");
}
clk_rate = clk_round_rate(bgp->div_clk,
bgp->conf->sensors[0].ts_data->max_freq);
if (clk_rate < bgp->conf->sensors[0].ts_data->min_freq ||
clk_rate == 0xffffffff) {
ret = -ENODEV;
dev_err(&pdev->dev, "wrong clock rate (%d)\n", clk_rate);
goto put_clks;
}
ret = clk_set_rate(bgp->div_clk, clk_rate);
if (ret)
dev_err(&pdev->dev, "Cannot re-set clock rate. Continuing\n");
bgp->clk_rate = clk_rate;
if (TI_BANDGAP_HAS(bgp, CLK_CTRL))
clk_prepare_enable(bgp->fclock);
spin_lock_init(&bgp->lock);
bgp->dev = &pdev->dev;
platform_set_drvdata(pdev, bgp);
ti_bandgap_power(bgp, true);
if (TI_BANDGAP_HAS(bgp, COUNTER))
for (i = 0; i < bgp->conf->sensor_count; i++)
RMW_BITS(bgp, i, bgap_counter, counter_mask, 1);
for (i = 0; i < bgp->conf->sensor_count; i++) {
struct temp_sensor_data *ts_data;
ts_data = bgp->conf->sensors[i].ts_data;
if (TI_BANDGAP_HAS(bgp, TALERT)) {
RMW_BITS(bgp, i, bgap_threshold,
threshold_tcold_mask, ts_data->t_cold);
RMW_BITS(bgp, i, bgap_threshold,
threshold_thot_mask, ts_data->t_hot);
RMW_BITS(bgp, i, bgap_mask_ctrl, mask_hot_mask, 1);
RMW_BITS(bgp, i, bgap_mask_ctrl, mask_cold_mask, 1);
}
if (TI_BANDGAP_HAS(bgp, TSHUT_CONFIG)) {
RMW_BITS(bgp, i, tshut_threshold,
tshut_hot_mask, ts_data->tshut_hot);
RMW_BITS(bgp, i, tshut_threshold,
tshut_cold_mask, ts_data->tshut_cold);
}
}
if (TI_BANDGAP_HAS(bgp, MODE_CONFIG))
ti_bandgap_set_continuous_mode(bgp);
if (TI_BANDGAP_HAS(bgp, COUNTER))
for (i = 0; i < bgp->conf->sensor_count; i++)
RMW_BITS(bgp, i, bgap_counter, counter_mask,
bgp->clk_rate / 4);
for (i = 0; i < bgp->conf->sensor_count; i++) {
char *domain;
if (bgp->conf->sensors[i].register_cooling) {
ret = bgp->conf->sensors[i].register_cooling(bgp, i);
if (ret)
goto remove_sensors;
}
if (bgp->conf->expose_sensor) {
domain = bgp->conf->sensors[i].domain;
ret = bgp->conf->expose_sensor(bgp, i, domain);
if (ret)
goto remove_last_cooling;
}
}
if (TI_BANDGAP_HAS(bgp, TALERT)) {
ret = ti_bandgap_talert_init(bgp, pdev);
if (ret) {
dev_err(&pdev->dev, "failed to initialize Talert IRQ\n");
i = bgp->conf->sensor_count;
goto disable_clk;
}
}
return 0;
remove_last_cooling:
if (bgp->conf->sensors[i].unregister_cooling)
bgp->conf->sensors[i].unregister_cooling(bgp, i);
remove_sensors:
for (i--; i >= 0; i--) {
if (bgp->conf->sensors[i].unregister_cooling)
bgp->conf->sensors[i].unregister_cooling(bgp, i);
if (bgp->conf->remove_sensor)
bgp->conf->remove_sensor(bgp, i);
}
ti_bandgap_power(bgp, false);
disable_clk:
if (TI_BANDGAP_HAS(bgp, CLK_CTRL))
clk_disable_unprepare(bgp->fclock);
put_clks:
clk_put(bgp->fclock);
clk_put(bgp->div_clk);
free_irqs:
if (TI_BANDGAP_HAS(bgp, TSHUT)) {
free_irq(gpio_to_irq(bgp->tshut_gpio), NULL);
gpio_free(bgp->tshut_gpio);
}
return ret;
}
static
int ti_bandgap_remove(struct platform_device *pdev)
{
struct ti_bandgap *bgp = platform_get_drvdata(pdev);
int i;
for (i = 0; i < bgp->conf->sensor_count; i++) {
if (bgp->conf->sensors[i].unregister_cooling)
bgp->conf->sensors[i].unregister_cooling(bgp, i);
if (bgp->conf->remove_sensor)
bgp->conf->remove_sensor(bgp, i);
}
ti_bandgap_power(bgp, false);
if (TI_BANDGAP_HAS(bgp, CLK_CTRL))
clk_disable_unprepare(bgp->fclock);
clk_put(bgp->fclock);
clk_put(bgp->div_clk);
if (TI_BANDGAP_HAS(bgp, TALERT))
free_irq(bgp->irq, bgp);
if (TI_BANDGAP_HAS(bgp, TSHUT)) {
free_irq(gpio_to_irq(bgp->tshut_gpio), NULL);
gpio_free(bgp->tshut_gpio);
}
return 0;
}
static int ti_bandgap_save_ctxt(struct ti_bandgap *bgp)
{
int i;
for (i = 0; i < bgp->conf->sensor_count; i++) {
struct temp_sensor_registers *tsr;
struct temp_sensor_regval *rval;
rval = &bgp->regval[i];
tsr = bgp->conf->sensors[i].registers;
if (TI_BANDGAP_HAS(bgp, MODE_CONFIG))
rval->bg_mode_ctrl = ti_bandgap_readl(bgp,
tsr->bgap_mode_ctrl);
if (TI_BANDGAP_HAS(bgp, COUNTER))
rval->bg_counter = ti_bandgap_readl(bgp,
tsr->bgap_counter);
if (TI_BANDGAP_HAS(bgp, TALERT)) {
rval->bg_threshold = ti_bandgap_readl(bgp,
tsr->bgap_threshold);
rval->bg_ctrl = ti_bandgap_readl(bgp,
tsr->bgap_mask_ctrl);
}
if (TI_BANDGAP_HAS(bgp, TSHUT_CONFIG))
rval->tshut_threshold = ti_bandgap_readl(bgp,
tsr->tshut_threshold);
}
return 0;
}
static int ti_bandgap_restore_ctxt(struct ti_bandgap *bgp)
{
int i;
for (i = 0; i < bgp->conf->sensor_count; i++) {
struct temp_sensor_registers *tsr;
struct temp_sensor_regval *rval;
u32 val = 0;
rval = &bgp->regval[i];
tsr = bgp->conf->sensors[i].registers;
if (TI_BANDGAP_HAS(bgp, COUNTER))
val = ti_bandgap_readl(bgp, tsr->bgap_counter);
if (TI_BANDGAP_HAS(bgp, TSHUT_CONFIG))
ti_bandgap_writel(bgp, rval->tshut_threshold,
tsr->tshut_threshold);
ti_bandgap_force_single_read(bgp, i);
if (TI_BANDGAP_HAS(bgp, COUNTER))
ti_bandgap_writel(bgp, rval->bg_counter,
tsr->bgap_counter);
if (TI_BANDGAP_HAS(bgp, MODE_CONFIG))
ti_bandgap_writel(bgp, rval->bg_mode_ctrl,
tsr->bgap_mode_ctrl);
if (TI_BANDGAP_HAS(bgp, TALERT)) {
ti_bandgap_writel(bgp, rval->bg_threshold,
tsr->bgap_threshold);
ti_bandgap_writel(bgp, rval->bg_ctrl,
tsr->bgap_mask_ctrl);
}
}
return 0;
}
static int ti_bandgap_suspend(struct device *dev)
{
struct ti_bandgap *bgp = dev_get_drvdata(dev);
int err;
err = ti_bandgap_save_ctxt(bgp);
ti_bandgap_power(bgp, false);
if (TI_BANDGAP_HAS(bgp, CLK_CTRL))
clk_disable_unprepare(bgp->fclock);
return err;
}
static int ti_bandgap_resume(struct device *dev)
{
struct ti_bandgap *bgp = dev_get_drvdata(dev);
if (TI_BANDGAP_HAS(bgp, CLK_CTRL))
clk_prepare_enable(bgp->fclock);
ti_bandgap_power(bgp, true);
return ti_bandgap_restore_ctxt(bgp);
}
