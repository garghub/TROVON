static unsigned long ac100_clkout_recalc_rate(struct clk_hw *hw,
unsigned long prate)
{
struct ac100_clkout *clk = to_ac100_clkout(hw);
unsigned int reg, div;
regmap_read(clk->regmap, clk->offset, &reg);
if (prate != AC100_RTC_32K_RATE) {
div = (reg >> AC100_CLKOUT_PRE_DIV_SHIFT) &
((1 << AC100_CLKOUT_PRE_DIV_WIDTH) - 1);
prate = divider_recalc_rate(hw, prate, div,
ac100_clkout_prediv, 0);
}
div = (reg >> AC100_CLKOUT_DIV_SHIFT) &
(BIT(AC100_CLKOUT_DIV_WIDTH) - 1);
return divider_recalc_rate(hw, prate, div, NULL,
CLK_DIVIDER_POWER_OF_TWO);
}
static long ac100_clkout_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long prate)
{
unsigned long best_rate = 0, tmp_rate, tmp_prate;
int i;
if (prate == AC100_RTC_32K_RATE)
return divider_round_rate(hw, rate, &prate, NULL,
AC100_CLKOUT_DIV_WIDTH,
CLK_DIVIDER_POWER_OF_TWO);
for (i = 0; ac100_clkout_prediv[i].div; i++) {
tmp_prate = DIV_ROUND_UP(prate, ac100_clkout_prediv[i].val);
tmp_rate = divider_round_rate(hw, rate, &tmp_prate, NULL,
AC100_CLKOUT_DIV_WIDTH,
CLK_DIVIDER_POWER_OF_TWO);
if (tmp_rate > rate)
continue;
if (rate - tmp_rate < best_rate - tmp_rate)
best_rate = tmp_rate;
}
return best_rate;
}
static int ac100_clkout_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct clk_hw *best_parent;
unsigned long best = 0;
int i, num_parents = clk_hw_get_num_parents(hw);
for (i = 0; i < num_parents; i++) {
struct clk_hw *parent = clk_hw_get_parent_by_index(hw, i);
unsigned long tmp, prate = clk_hw_get_rate(parent);
tmp = ac100_clkout_round_rate(hw, req->rate, prate);
if (tmp > req->rate)
continue;
if (req->rate - tmp < req->rate - best) {
best = tmp;
best_parent = parent;
}
}
if (!best)
return -EINVAL;
req->best_parent_hw = best_parent;
req->best_parent_rate = best;
req->rate = best;
return 0;
}
static int ac100_clkout_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long prate)
{
struct ac100_clkout *clk = to_ac100_clkout(hw);
int div = 0, pre_div = 0;
do {
div = divider_get_val(rate * ac100_clkout_prediv[pre_div].div,
prate, NULL, AC100_CLKOUT_DIV_WIDTH,
CLK_DIVIDER_POWER_OF_TWO);
if (div >= 0)
break;
} while (prate != AC100_RTC_32K_RATE &&
ac100_clkout_prediv[++pre_div].div);
if (div < 0)
return div;
pre_div = ac100_clkout_prediv[pre_div].val;
regmap_update_bits(clk->regmap, clk->offset,
((1 << AC100_CLKOUT_DIV_WIDTH) - 1) << AC100_CLKOUT_DIV_SHIFT |
((1 << AC100_CLKOUT_PRE_DIV_WIDTH) - 1) << AC100_CLKOUT_PRE_DIV_SHIFT,
(div - 1) << AC100_CLKOUT_DIV_SHIFT |
(pre_div - 1) << AC100_CLKOUT_PRE_DIV_SHIFT);
return 0;
}
static int ac100_clkout_prepare(struct clk_hw *hw)
{
struct ac100_clkout *clk = to_ac100_clkout(hw);
return regmap_update_bits(clk->regmap, clk->offset, AC100_CLKOUT_EN,
AC100_CLKOUT_EN);
}
static void ac100_clkout_unprepare(struct clk_hw *hw)
{
struct ac100_clkout *clk = to_ac100_clkout(hw);
regmap_update_bits(clk->regmap, clk->offset, AC100_CLKOUT_EN, 0);
}
static int ac100_clkout_is_prepared(struct clk_hw *hw)
{
struct ac100_clkout *clk = to_ac100_clkout(hw);
unsigned int reg;
regmap_read(clk->regmap, clk->offset, &reg);
return reg & AC100_CLKOUT_EN;
}
static u8 ac100_clkout_get_parent(struct clk_hw *hw)
{
struct ac100_clkout *clk = to_ac100_clkout(hw);
unsigned int reg;
regmap_read(clk->regmap, clk->offset, &reg);
return (reg >> AC100_CLKOUT_MUX_SHIFT) & 0x1;
}
static int ac100_clkout_set_parent(struct clk_hw *hw, u8 index)
{
struct ac100_clkout *clk = to_ac100_clkout(hw);
return regmap_update_bits(clk->regmap, clk->offset,
BIT(AC100_CLKOUT_MUX_SHIFT),
index ? BIT(AC100_CLKOUT_MUX_SHIFT) : 0);
}
static int ac100_rtc_register_clks(struct ac100_rtc_dev *chip)
{
struct device_node *np = chip->dev->of_node;
const char *parents[2] = {AC100_RTC_32K_NAME};
int i, ret;
chip->clk_data = devm_kzalloc(chip->dev, sizeof(*chip->clk_data) +
sizeof(*chip->clk_data->hws) *
AC100_CLKOUT_NUM,
GFP_KERNEL);
if (!chip->clk_data)
return -ENOMEM;
chip->rtc_32k_clk = clk_hw_register_fixed_rate(chip->dev,
AC100_RTC_32K_NAME,
NULL, 0,
AC100_RTC_32K_RATE);
if (IS_ERR(chip->rtc_32k_clk)) {
ret = PTR_ERR(chip->rtc_32k_clk);
dev_err(chip->dev, "Failed to register RTC-32k clock: %d\n",
ret);
return ret;
}
parents[1] = of_clk_get_parent_name(np, 0);
if (!parents[1]) {
dev_err(chip->dev, "Failed to get ADDA 4M clock\n");
return -EINVAL;
}
for (i = 0; i < AC100_CLKOUT_NUM; i++) {
struct ac100_clkout *clk = &chip->clks[i];
struct clk_init_data init = {
.name = ac100_clkout_names[i],
.ops = &ac100_clkout_ops,
.parent_names = parents,
.num_parents = ARRAY_SIZE(parents),
.flags = 0,
};
of_property_read_string_index(np, "clock-output-names",
i, &init.name);
clk->regmap = chip->regmap;
clk->offset = AC100_CLKOUT_CTRL1 + i;
clk->hw.init = &init;
ret = devm_clk_hw_register(chip->dev, &clk->hw);
if (ret) {
dev_err(chip->dev, "Failed to register clk '%s': %d\n",
init.name, ret);
goto err_unregister_rtc_32k;
}
chip->clk_data->hws[i] = &clk->hw;
}
chip->clk_data->num = i;
ret = of_clk_add_hw_provider(np, of_clk_hw_onecell_get, chip->clk_data);
if (ret)
goto err_unregister_rtc_32k;
return 0;
err_unregister_rtc_32k:
clk_unregister_fixed_rate(chip->rtc_32k_clk->clk);
return ret;
}
static void ac100_rtc_unregister_clks(struct ac100_rtc_dev *chip)
{
of_clk_del_provider(chip->dev->of_node);
clk_unregister_fixed_rate(chip->rtc_32k_clk->clk);
}
static int ac100_rtc_get_time(struct device *dev, struct rtc_time *rtc_tm)
{
struct ac100_rtc_dev *chip = dev_get_drvdata(dev);
struct regmap *regmap = chip->regmap;
u16 reg[7];
int ret;
ret = regmap_bulk_read(regmap, AC100_RTC_SEC, reg, 7);
if (ret)
return ret;
rtc_tm->tm_sec = bcd2bin(reg[0] & AC100_RTC_SEC_MASK);
rtc_tm->tm_min = bcd2bin(reg[1] & AC100_RTC_MIN_MASK);
rtc_tm->tm_hour = bcd2bin(reg[2] & AC100_RTC_HOU_MASK);
rtc_tm->tm_wday = bcd2bin(reg[3] & AC100_RTC_WEE_MASK);
rtc_tm->tm_mday = bcd2bin(reg[4] & AC100_RTC_DAY_MASK);
rtc_tm->tm_mon = bcd2bin(reg[5] & AC100_RTC_MON_MASK) - 1;
rtc_tm->tm_year = bcd2bin(reg[6] & AC100_RTC_YEA_MASK) +
AC100_YEAR_OFF;
return rtc_valid_tm(rtc_tm);
}
static int ac100_rtc_set_time(struct device *dev, struct rtc_time *rtc_tm)
{
struct ac100_rtc_dev *chip = dev_get_drvdata(dev);
struct regmap *regmap = chip->regmap;
int year;
u16 reg[8];
year = rtc_tm->tm_year - AC100_YEAR_OFF;
if (year < 0 || year > (AC100_YEAR_MAX - 1900)) {
dev_err(dev, "rtc only supports year in range %d - %d\n",
AC100_YEAR_MIN, AC100_YEAR_MAX);
return -EINVAL;
}
reg[0] = bin2bcd(rtc_tm->tm_sec) & AC100_RTC_SEC_MASK;
reg[1] = bin2bcd(rtc_tm->tm_min) & AC100_RTC_MIN_MASK;
reg[2] = bin2bcd(rtc_tm->tm_hour) & AC100_RTC_HOU_MASK;
reg[3] = bin2bcd(rtc_tm->tm_wday) & AC100_RTC_WEE_MASK;
reg[4] = bin2bcd(rtc_tm->tm_mday) & AC100_RTC_DAY_MASK;
reg[5] = bin2bcd(rtc_tm->tm_mon + 1) & AC100_RTC_MON_MASK;
reg[6] = bin2bcd(year) & AC100_RTC_YEA_MASK;
reg[7] = AC100_RTC_UPD_TRIGGER;
if (is_leap_year(year + AC100_YEAR_OFF + 1900))
reg[6] |= AC100_RTC_YEA_LEAP;
return regmap_bulk_write(regmap, AC100_RTC_SEC, reg, 8);
}
static int ac100_rtc_alarm_irq_enable(struct device *dev, unsigned int en)
{
struct ac100_rtc_dev *chip = dev_get_drvdata(dev);
struct regmap *regmap = chip->regmap;
unsigned int val;
val = en ? AC100_ALM_INT_ENABLE : 0;
return regmap_write(regmap, AC100_ALM_INT_ENA, val);
}
static int ac100_rtc_get_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct ac100_rtc_dev *chip = dev_get_drvdata(dev);
struct regmap *regmap = chip->regmap;
struct rtc_time *alrm_tm = &alrm->time;
u16 reg[7];
unsigned int val;
int ret;
ret = regmap_read(regmap, AC100_ALM_INT_ENA, &val);
if (ret)
return ret;
alrm->enabled = !!(val & AC100_ALM_INT_ENABLE);
ret = regmap_bulk_read(regmap, AC100_ALM_SEC, reg, 7);
if (ret)
return ret;
alrm_tm->tm_sec = bcd2bin(reg[0] & AC100_ALM_SEC_MASK);
alrm_tm->tm_min = bcd2bin(reg[1] & AC100_ALM_MIN_MASK);
alrm_tm->tm_hour = bcd2bin(reg[2] & AC100_ALM_HOU_MASK);
alrm_tm->tm_wday = bcd2bin(reg[3] & AC100_ALM_WEE_MASK);
alrm_tm->tm_mday = bcd2bin(reg[4] & AC100_ALM_DAY_MASK);
alrm_tm->tm_mon = bcd2bin(reg[5] & AC100_ALM_MON_MASK) - 1;
alrm_tm->tm_year = bcd2bin(reg[6] & AC100_ALM_YEA_MASK) +
AC100_YEAR_OFF;
return 0;
}
static int ac100_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct ac100_rtc_dev *chip = dev_get_drvdata(dev);
struct regmap *regmap = chip->regmap;
struct rtc_time *alrm_tm = &alrm->time;
u16 reg[8];
int year;
int ret;
year = alrm_tm->tm_year - AC100_YEAR_OFF;
if (year < 0 || year > (AC100_YEAR_MAX - 1900)) {
dev_err(dev, "alarm only supports year in range %d - %d\n",
AC100_YEAR_MIN, AC100_YEAR_MAX);
return -EINVAL;
}
reg[0] = (bin2bcd(alrm_tm->tm_sec) & AC100_ALM_SEC_MASK) |
AC100_ALM_ENABLE_FLAG;
reg[1] = (bin2bcd(alrm_tm->tm_min) & AC100_ALM_MIN_MASK) |
AC100_ALM_ENABLE_FLAG;
reg[2] = (bin2bcd(alrm_tm->tm_hour) & AC100_ALM_HOU_MASK) |
AC100_ALM_ENABLE_FLAG;
reg[3] = bin2bcd(alrm_tm->tm_wday) & AC100_ALM_WEE_MASK;
reg[4] = (bin2bcd(alrm_tm->tm_mday) & AC100_ALM_DAY_MASK) |
AC100_ALM_ENABLE_FLAG;
reg[5] = (bin2bcd(alrm_tm->tm_mon + 1) & AC100_ALM_MON_MASK) |
AC100_ALM_ENABLE_FLAG;
reg[6] = (bin2bcd(year) & AC100_ALM_YEA_MASK) |
AC100_ALM_ENABLE_FLAG;
reg[7] = AC100_ALM_UPD_TRIGGER;
ret = regmap_bulk_write(regmap, AC100_ALM_SEC, reg, 8);
if (ret)
return ret;
return ac100_rtc_alarm_irq_enable(dev, alrm->enabled);
}
static irqreturn_t ac100_rtc_irq(int irq, void *data)
{
struct ac100_rtc_dev *chip = data;
struct regmap *regmap = chip->regmap;
unsigned int val = 0;
int ret;
mutex_lock(&chip->rtc->ops_lock);
ret = regmap_read(regmap, AC100_ALM_INT_STA, &val);
if (ret)
goto out;
if (val & AC100_ALM_INT_ENABLE) {
rtc_update_irq(chip->rtc, 1, RTC_AF | RTC_IRQF);
ret = regmap_write(regmap, AC100_ALM_INT_STA, val);
if (ret)
goto out;
ret = ac100_rtc_alarm_irq_enable(chip->dev, 0);
if (ret)
goto out;
}
out:
mutex_unlock(&chip->rtc->ops_lock);
return IRQ_HANDLED;
}
static int ac100_rtc_probe(struct platform_device *pdev)
{
struct ac100_dev *ac100 = dev_get_drvdata(pdev->dev.parent);
struct ac100_rtc_dev *chip;
int ret;
chip = devm_kzalloc(&pdev->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
platform_set_drvdata(pdev, chip);
chip->dev = &pdev->dev;
chip->regmap = ac100->regmap;
chip->irq = platform_get_irq(pdev, 0);
if (chip->irq < 0) {
dev_err(&pdev->dev, "No IRQ resource\n");
return chip->irq;
}
ret = devm_request_threaded_irq(&pdev->dev, chip->irq, NULL,
ac100_rtc_irq,
IRQF_SHARED | IRQF_ONESHOT,
dev_name(&pdev->dev), chip);
if (ret) {
dev_err(&pdev->dev, "Could not request IRQ\n");
return ret;
}
regmap_write_bits(chip->regmap, AC100_RTC_CTRL, AC100_RTC_CTRL_24HOUR,
AC100_RTC_CTRL_24HOUR);
regmap_write(chip->regmap, AC100_ALM_INT_ENA, 0);
regmap_write(chip->regmap, AC100_ALM_INT_STA, AC100_ALM_INT_ENABLE);
chip->rtc = devm_rtc_device_register(&pdev->dev, "rtc-ac100",
&ac100_rtc_ops, THIS_MODULE);
if (IS_ERR(chip->rtc)) {
dev_err(&pdev->dev, "unable to register device\n");
return PTR_ERR(chip->rtc);
}
ret = ac100_rtc_register_clks(chip);
if (ret)
return ret;
dev_info(&pdev->dev, "RTC enabled\n");
return 0;
}
static int ac100_rtc_remove(struct platform_device *pdev)
{
struct ac100_rtc_dev *chip = platform_get_drvdata(pdev);
ac100_rtc_unregister_clks(chip);
return 0;
}
