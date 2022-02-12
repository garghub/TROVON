static inline struct atmel_hlcdc_pwm *to_atmel_hlcdc_pwm(struct pwm_chip *chip)
{
return container_of(chip, struct atmel_hlcdc_pwm, chip);
}
static int atmel_hlcdc_pwm_config(struct pwm_chip *c,
struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct atmel_hlcdc_pwm *chip = to_atmel_hlcdc_pwm(c);
struct atmel_hlcdc *hlcdc = chip->hlcdc;
struct clk *new_clk = hlcdc->slow_clk;
u64 pwmcval = duty_ns * 256;
unsigned long clk_freq;
u64 clk_period_ns;
u32 pwmcfg;
int pres;
if (!chip->errata || !chip->errata->slow_clk_erratum) {
clk_freq = clk_get_rate(new_clk);
if (!clk_freq)
return -EINVAL;
clk_period_ns = (u64)NSEC_PER_SEC * 256;
do_div(clk_period_ns, clk_freq);
}
if ((chip->errata && chip->errata->slow_clk_erratum) ||
clk_period_ns > period_ns) {
new_clk = hlcdc->sys_clk;
clk_freq = clk_get_rate(new_clk);
if (!clk_freq)
return -EINVAL;
clk_period_ns = (u64)NSEC_PER_SEC * 256;
do_div(clk_period_ns, clk_freq);
}
for (pres = 0; pres <= ATMEL_HLCDC_PWMPS_MAX; pres++) {
if (!pres && chip->errata && chip->errata->div1_clk_erratum)
continue;
if ((clk_period_ns << pres) >= period_ns)
break;
}
if (pres > ATMEL_HLCDC_PWMPS_MAX)
return -EINVAL;
pwmcfg = ATMEL_HLCDC_PWMPS(pres);
if (new_clk != chip->cur_clk) {
u32 gencfg = 0;
int ret;
ret = clk_prepare_enable(new_clk);
if (ret)
return ret;
clk_disable_unprepare(chip->cur_clk);
chip->cur_clk = new_clk;
if (new_clk == hlcdc->sys_clk)
gencfg = ATMEL_HLCDC_CLKPWMSEL;
ret = regmap_update_bits(hlcdc->regmap, ATMEL_HLCDC_CFG(0),
ATMEL_HLCDC_CLKPWMSEL, gencfg);
if (ret)
return ret;
}
do_div(pwmcval, period_ns);
if (pwmcval > 255)
pwmcval = 255;
pwmcfg |= ATMEL_HLCDC_PWMCVAL(pwmcval);
return regmap_update_bits(hlcdc->regmap, ATMEL_HLCDC_CFG(6),
ATMEL_HLCDC_PWMCVAL_MASK |
ATMEL_HLCDC_PWMPS_MASK,
pwmcfg);
}
static int atmel_hlcdc_pwm_set_polarity(struct pwm_chip *c,
struct pwm_device *pwm,
enum pwm_polarity polarity)
{
struct atmel_hlcdc_pwm *chip = to_atmel_hlcdc_pwm(c);
struct atmel_hlcdc *hlcdc = chip->hlcdc;
u32 cfg = 0;
if (polarity == PWM_POLARITY_NORMAL)
cfg = ATMEL_HLCDC_PWMPOL;
return regmap_update_bits(hlcdc->regmap, ATMEL_HLCDC_CFG(6),
ATMEL_HLCDC_PWMPOL, cfg);
}
static int atmel_hlcdc_pwm_enable(struct pwm_chip *c, struct pwm_device *pwm)
{
struct atmel_hlcdc_pwm *chip = to_atmel_hlcdc_pwm(c);
struct atmel_hlcdc *hlcdc = chip->hlcdc;
u32 status;
int ret;
ret = regmap_write(hlcdc->regmap, ATMEL_HLCDC_EN, ATMEL_HLCDC_PWM);
if (ret)
return ret;
while (true) {
ret = regmap_read(hlcdc->regmap, ATMEL_HLCDC_SR, &status);
if (ret)
return ret;
if ((status & ATMEL_HLCDC_PWM) != 0)
break;
usleep_range(1, 10);
}
return 0;
}
static void atmel_hlcdc_pwm_disable(struct pwm_chip *c,
struct pwm_device *pwm)
{
struct atmel_hlcdc_pwm *chip = to_atmel_hlcdc_pwm(c);
struct atmel_hlcdc *hlcdc = chip->hlcdc;
u32 status;
int ret;
ret = regmap_write(hlcdc->regmap, ATMEL_HLCDC_DIS, ATMEL_HLCDC_PWM);
if (ret)
return;
while (true) {
ret = regmap_read(hlcdc->regmap, ATMEL_HLCDC_SR, &status);
if (ret)
return;
if ((status & ATMEL_HLCDC_PWM) == 0)
break;
usleep_range(1, 10);
}
}
static int atmel_hlcdc_pwm_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct device *dev = &pdev->dev;
struct atmel_hlcdc_pwm *chip;
struct atmel_hlcdc *hlcdc;
int ret;
hlcdc = dev_get_drvdata(dev->parent);
chip = devm_kzalloc(dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
ret = clk_prepare_enable(hlcdc->periph_clk);
if (ret)
return ret;
match = of_match_node(atmel_hlcdc_dt_ids, dev->parent->of_node);
if (match)
chip->errata = match->data;
chip->hlcdc = hlcdc;
chip->chip.ops = &atmel_hlcdc_pwm_ops;
chip->chip.dev = dev;
chip->chip.base = -1;
chip->chip.npwm = 1;
chip->chip.of_xlate = of_pwm_xlate_with_flags;
chip->chip.of_pwm_n_cells = 3;
ret = pwmchip_add_with_polarity(&chip->chip, PWM_POLARITY_INVERSED);
if (ret) {
clk_disable_unprepare(hlcdc->periph_clk);
return ret;
}
platform_set_drvdata(pdev, chip);
return 0;
}
static int atmel_hlcdc_pwm_remove(struct platform_device *pdev)
{
struct atmel_hlcdc_pwm *chip = platform_get_drvdata(pdev);
int ret;
ret = pwmchip_remove(&chip->chip);
if (ret)
return ret;
clk_disable_unprepare(chip->hlcdc->periph_clk);
return 0;
}
