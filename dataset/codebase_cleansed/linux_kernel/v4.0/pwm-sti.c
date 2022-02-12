static inline struct sti_pwm_chip *to_sti_pwmchip(struct pwm_chip *chip)
{
return container_of(chip, struct sti_pwm_chip, chip);
}
static int sti_pwm_get_prescale(struct sti_pwm_chip *pc, unsigned long period,
unsigned int *prescale)
{
struct sti_pwm_compat_data *cdata = pc->cdata;
unsigned long val;
unsigned int ps;
val = NSEC_PER_SEC / pc->clk_rate;
val *= cdata->max_pwm_cnt + 1;
if (period % val) {
return -EINVAL;
} else {
ps = period / val - 1;
if (ps > cdata->max_prescale)
return -EINVAL;
}
*prescale = ps;
return 0;
}
static int sti_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct sti_pwm_chip *pc = to_sti_pwmchip(chip);
struct sti_pwm_compat_data *cdata = pc->cdata;
struct pwm_device *cur = pc->cur;
struct device *dev = pc->dev;
unsigned int prescale = 0, pwmvalx;
int ret;
unsigned int ncfg;
bool period_same = false;
ncfg = hweight_long(pc->configured);
if (ncfg)
period_same = (period_ns == pwm_get_period(cur));
if (!ncfg ||
((ncfg == 1) && (pwm->hwpwm == cur->hwpwm)) ||
((ncfg == 1) && (pwm->hwpwm != cur->hwpwm) && period_same) ||
((ncfg > 1) && period_same)) {
ret = clk_enable(pc->clk);
if (ret)
return ret;
if (!period_same) {
ret = sti_pwm_get_prescale(pc, period_ns, &prescale);
if (ret)
goto clk_dis;
ret =
regmap_field_write(pc->prescale_low,
prescale & PWM_PRESCALE_LOW_MASK);
if (ret)
goto clk_dis;
ret =
regmap_field_write(pc->prescale_high,
(prescale & PWM_PRESCALE_HIGH_MASK) >> 4);
if (ret)
goto clk_dis;
}
pwmvalx = cdata->max_pwm_cnt * duty_ns / period_ns;
ret = regmap_write(pc->regmap, STI_DS_REG(pwm->hwpwm), pwmvalx);
if (ret)
goto clk_dis;
ret = regmap_field_write(pc->pwm_int_en, 0);
set_bit(pwm->hwpwm, &pc->configured);
pc->cur = pwm;
dev_dbg(dev, "prescale:%u, period:%i, duty:%i, pwmvalx:%u\n",
prescale, period_ns, duty_ns, pwmvalx);
} else {
return -EINVAL;
}
clk_dis:
clk_disable(pc->clk);
return ret;
}
static int sti_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct sti_pwm_chip *pc = to_sti_pwmchip(chip);
struct device *dev = pc->dev;
int ret = 0;
mutex_lock(&pc->sti_pwm_lock);
if (!pc->en_count) {
ret = clk_enable(pc->clk);
if (ret)
goto out;
ret = regmap_field_write(pc->pwm_en, 1);
if (ret) {
dev_err(dev, "failed to enable PWM device:%d\n",
pwm->hwpwm);
goto out;
}
}
pc->en_count++;
out:
mutex_unlock(&pc->sti_pwm_lock);
return ret;
}
static void sti_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct sti_pwm_chip *pc = to_sti_pwmchip(chip);
mutex_lock(&pc->sti_pwm_lock);
if (--pc->en_count) {
mutex_unlock(&pc->sti_pwm_lock);
return;
}
regmap_field_write(pc->pwm_en, 0);
clk_disable(pc->clk);
mutex_unlock(&pc->sti_pwm_lock);
}
static void sti_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct sti_pwm_chip *pc = to_sti_pwmchip(chip);
clear_bit(pwm->hwpwm, &pc->configured);
}
static int sti_pwm_probe_dt(struct sti_pwm_chip *pc)
{
struct device *dev = pc->dev;
const struct reg_field *reg_fields;
struct device_node *np = dev->of_node;
struct sti_pwm_compat_data *cdata = pc->cdata;
u32 num_chan;
of_property_read_u32(np, "st,pwm-num-chan", &num_chan);
if (num_chan)
cdata->num_chan = num_chan;
reg_fields = cdata->reg_fields;
pc->prescale_low = devm_regmap_field_alloc(dev, pc->regmap,
reg_fields[PWMCLK_PRESCALE_LOW]);
if (IS_ERR(pc->prescale_low))
return PTR_ERR(pc->prescale_low);
pc->prescale_high = devm_regmap_field_alloc(dev, pc->regmap,
reg_fields[PWMCLK_PRESCALE_HIGH]);
if (IS_ERR(pc->prescale_high))
return PTR_ERR(pc->prescale_high);
pc->pwm_en = devm_regmap_field_alloc(dev, pc->regmap,
reg_fields[PWM_EN]);
if (IS_ERR(pc->pwm_en))
return PTR_ERR(pc->pwm_en);
pc->pwm_int_en = devm_regmap_field_alloc(dev, pc->regmap,
reg_fields[PWM_INT_EN]);
if (IS_ERR(pc->pwm_int_en))
return PTR_ERR(pc->pwm_int_en);
return 0;
}
static int sti_pwm_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct sti_pwm_compat_data *cdata;
struct sti_pwm_chip *pc;
struct resource *res;
int ret;
pc = devm_kzalloc(dev, sizeof(*pc), GFP_KERNEL);
if (!pc)
return -ENOMEM;
cdata = devm_kzalloc(dev, sizeof(*cdata), GFP_KERNEL);
if (!cdata)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pc->mmio = devm_ioremap_resource(dev, res);
if (IS_ERR(pc->mmio))
return PTR_ERR(pc->mmio);
pc->regmap = devm_regmap_init_mmio(dev, pc->mmio,
&sti_pwm_regmap_config);
if (IS_ERR(pc->regmap))
return PTR_ERR(pc->regmap);
cdata->reg_fields = &sti_pwm_regfields[0];
cdata->max_prescale = 0xff;
cdata->max_pwm_cnt = 255;
cdata->num_chan = 1;
pc->cdata = cdata;
pc->dev = dev;
pc->en_count = 0;
mutex_init(&pc->sti_pwm_lock);
ret = sti_pwm_probe_dt(pc);
if (ret)
return ret;
pc->clk = of_clk_get_by_name(dev->of_node, "pwm");
if (IS_ERR(pc->clk)) {
dev_err(dev, "failed to get PWM clock\n");
return PTR_ERR(pc->clk);
}
pc->clk_rate = clk_get_rate(pc->clk);
if (!pc->clk_rate) {
dev_err(dev, "failed to get clock rate\n");
return -EINVAL;
}
ret = clk_prepare(pc->clk);
if (ret) {
dev_err(dev, "failed to prepare clock\n");
return ret;
}
pc->chip.dev = dev;
pc->chip.ops = &sti_pwm_ops;
pc->chip.base = -1;
pc->chip.npwm = pc->cdata->num_chan;
pc->chip.can_sleep = true;
ret = pwmchip_add(&pc->chip);
if (ret < 0) {
clk_unprepare(pc->clk);
return ret;
}
platform_set_drvdata(pdev, pc);
return 0;
}
static int sti_pwm_remove(struct platform_device *pdev)
{
struct sti_pwm_chip *pc = platform_get_drvdata(pdev);
unsigned int i;
for (i = 0; i < pc->cdata->num_chan; i++)
pwm_disable(&pc->chip.pwms[i]);
clk_unprepare(pc->clk);
return pwmchip_remove(&pc->chip);
}
