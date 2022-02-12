static inline struct crystalcove_pwm *to_crc_pwm(struct pwm_chip *pc)
{
return container_of(pc, struct crystalcove_pwm, chip);
}
static int crc_pwm_enable(struct pwm_chip *c, struct pwm_device *pwm)
{
struct crystalcove_pwm *crc_pwm = to_crc_pwm(c);
regmap_write(crc_pwm->regmap, BACKLIGHT_EN, 1);
return 0;
}
static void crc_pwm_disable(struct pwm_chip *c, struct pwm_device *pwm)
{
struct crystalcove_pwm *crc_pwm = to_crc_pwm(c);
regmap_write(crc_pwm->regmap, BACKLIGHT_EN, 0);
}
static int crc_pwm_config(struct pwm_chip *c, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct crystalcove_pwm *crc_pwm = to_crc_pwm(c);
struct device *dev = crc_pwm->chip.dev;
int level;
if (period_ns > PWM_MAX_PERIOD_NS) {
dev_err(dev, "un-supported period_ns\n");
return -EINVAL;
}
if (pwm->period != period_ns) {
int clk_div;
crc_pwm_disable(c, pwm);
clk_div = PWM_BASE_CLK * period_ns / NSEC_PER_SEC;
regmap_write(crc_pwm->regmap, PWM0_CLK_DIV,
clk_div | PWM_OUTPUT_ENABLE);
crc_pwm_enable(c, pwm);
}
level = duty_ns * PWM_MAX_LEVEL / period_ns;
regmap_write(crc_pwm->regmap, PWM0_DUTY_CYCLE, level);
return 0;
}
static int crystalcove_pwm_probe(struct platform_device *pdev)
{
struct crystalcove_pwm *pwm;
struct device *dev = pdev->dev.parent;
struct intel_soc_pmic *pmic = dev_get_drvdata(dev);
pwm = devm_kzalloc(&pdev->dev, sizeof(*pwm), GFP_KERNEL);
if (!pwm)
return -ENOMEM;
pwm->chip.dev = &pdev->dev;
pwm->chip.ops = &crc_pwm_ops;
pwm->chip.base = -1;
pwm->chip.npwm = 1;
pwm->regmap = pmic->regmap;
platform_set_drvdata(pdev, pwm);
return pwmchip_add(&pwm->chip);
}
static int crystalcove_pwm_remove(struct platform_device *pdev)
{
struct crystalcove_pwm *pwm = platform_get_drvdata(pdev);
return pwmchip_remove(&pwm->chip);
}
