static inline struct atmel_tcb_pwm_chip *to_tcb_chip(struct pwm_chip *chip)
{
return container_of(chip, struct atmel_tcb_pwm_chip, chip);
}
static int atmel_tcb_pwm_set_polarity(struct pwm_chip *chip,
struct pwm_device *pwm,
enum pwm_polarity polarity)
{
struct atmel_tcb_pwm_device *tcbpwm = pwm_get_chip_data(pwm);
tcbpwm->polarity = polarity;
return 0;
}
static int atmel_tcb_pwm_request(struct pwm_chip *chip,
struct pwm_device *pwm)
{
struct atmel_tcb_pwm_chip *tcbpwmc = to_tcb_chip(chip);
struct atmel_tcb_pwm_device *tcbpwm;
struct atmel_tc *tc = tcbpwmc->tc;
void __iomem *regs = tc->regs;
unsigned group = pwm->hwpwm / 2;
unsigned index = pwm->hwpwm % 2;
unsigned cmr;
int ret;
tcbpwm = devm_kzalloc(chip->dev, sizeof(*tcbpwm), GFP_KERNEL);
if (!tcbpwm)
return -ENOMEM;
ret = clk_prepare_enable(tc->clk[group]);
if (ret) {
devm_kfree(chip->dev, tcbpwm);
return ret;
}
pwm_set_chip_data(pwm, tcbpwm);
tcbpwm->polarity = PWM_POLARITY_NORMAL;
tcbpwm->duty = 0;
tcbpwm->period = 0;
tcbpwm->div = 0;
spin_lock(&tcbpwmc->lock);
cmr = __raw_readl(regs + ATMEL_TC_REG(group, CMR));
if (cmr & ATMEL_TC_WAVE) {
if (index == 0)
tcbpwm->duty =
__raw_readl(regs + ATMEL_TC_REG(group, RA));
else
tcbpwm->duty =
__raw_readl(regs + ATMEL_TC_REG(group, RB));
tcbpwm->div = cmr & ATMEL_TC_TCCLKS;
tcbpwm->period = __raw_readl(regs + ATMEL_TC_REG(group, RC));
cmr &= (ATMEL_TC_TCCLKS | ATMEL_TC_ACMR_MASK |
ATMEL_TC_BCMR_MASK);
} else
cmr = 0;
cmr |= ATMEL_TC_WAVE | ATMEL_TC_WAVESEL_UP_AUTO | ATMEL_TC_EEVT_XC0;
__raw_writel(cmr, regs + ATMEL_TC_REG(group, CMR));
spin_unlock(&tcbpwmc->lock);
tcbpwmc->pwms[pwm->hwpwm] = tcbpwm;
return 0;
}
static void atmel_tcb_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct atmel_tcb_pwm_chip *tcbpwmc = to_tcb_chip(chip);
struct atmel_tcb_pwm_device *tcbpwm = pwm_get_chip_data(pwm);
struct atmel_tc *tc = tcbpwmc->tc;
clk_disable_unprepare(tc->clk[pwm->hwpwm / 2]);
tcbpwmc->pwms[pwm->hwpwm] = NULL;
devm_kfree(chip->dev, tcbpwm);
}
static void atmel_tcb_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct atmel_tcb_pwm_chip *tcbpwmc = to_tcb_chip(chip);
struct atmel_tcb_pwm_device *tcbpwm = pwm_get_chip_data(pwm);
struct atmel_tc *tc = tcbpwmc->tc;
void __iomem *regs = tc->regs;
unsigned group = pwm->hwpwm / 2;
unsigned index = pwm->hwpwm % 2;
unsigned cmr;
enum pwm_polarity polarity = tcbpwm->polarity;
if (tcbpwm->duty == 0)
polarity = !polarity;
spin_lock(&tcbpwmc->lock);
cmr = __raw_readl(regs + ATMEL_TC_REG(group, CMR));
if (index == 0) {
cmr &= ~ATMEL_TC_ACMR_MASK;
if (polarity == PWM_POLARITY_INVERSED)
cmr |= ATMEL_TC_ASWTRG_CLEAR;
else
cmr |= ATMEL_TC_ASWTRG_SET;
} else {
cmr &= ~ATMEL_TC_BCMR_MASK;
if (polarity == PWM_POLARITY_INVERSED)
cmr |= ATMEL_TC_BSWTRG_CLEAR;
else
cmr |= ATMEL_TC_BSWTRG_SET;
}
__raw_writel(cmr, regs + ATMEL_TC_REG(group, CMR));
if (!(cmr & (ATMEL_TC_ACPC | ATMEL_TC_BCPC)))
__raw_writel(ATMEL_TC_SWTRG | ATMEL_TC_CLKDIS,
regs + ATMEL_TC_REG(group, CCR));
else
__raw_writel(ATMEL_TC_SWTRG, regs +
ATMEL_TC_REG(group, CCR));
spin_unlock(&tcbpwmc->lock);
}
static int atmel_tcb_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct atmel_tcb_pwm_chip *tcbpwmc = to_tcb_chip(chip);
struct atmel_tcb_pwm_device *tcbpwm = pwm_get_chip_data(pwm);
struct atmel_tc *tc = tcbpwmc->tc;
void __iomem *regs = tc->regs;
unsigned group = pwm->hwpwm / 2;
unsigned index = pwm->hwpwm % 2;
u32 cmr;
enum pwm_polarity polarity = tcbpwm->polarity;
if (tcbpwm->duty == 0)
polarity = !polarity;
spin_lock(&tcbpwmc->lock);
cmr = __raw_readl(regs + ATMEL_TC_REG(group, CMR));
cmr &= ~ATMEL_TC_TCCLKS;
if (index == 0) {
cmr &= ~ATMEL_TC_ACMR_MASK;
if (polarity == PWM_POLARITY_INVERSED)
cmr |= ATMEL_TC_ASWTRG_CLEAR;
else
cmr |= ATMEL_TC_ASWTRG_SET;
} else {
cmr &= ~ATMEL_TC_BCMR_MASK;
if (polarity == PWM_POLARITY_INVERSED)
cmr |= ATMEL_TC_BSWTRG_CLEAR;
else
cmr |= ATMEL_TC_BSWTRG_SET;
}
if (tcbpwm->duty != tcbpwm->period && tcbpwm->duty > 0) {
if (index == 0) {
if (polarity == PWM_POLARITY_INVERSED)
cmr |= ATMEL_TC_ACPA_SET | ATMEL_TC_ACPC_CLEAR;
else
cmr |= ATMEL_TC_ACPA_CLEAR | ATMEL_TC_ACPC_SET;
} else {
if (polarity == PWM_POLARITY_INVERSED)
cmr |= ATMEL_TC_BCPB_SET | ATMEL_TC_BCPC_CLEAR;
else
cmr |= ATMEL_TC_BCPB_CLEAR | ATMEL_TC_BCPC_SET;
}
}
cmr |= (tcbpwm->div & ATMEL_TC_TCCLKS);
__raw_writel(cmr, regs + ATMEL_TC_REG(group, CMR));
if (index == 0)
__raw_writel(tcbpwm->duty, regs + ATMEL_TC_REG(group, RA));
else
__raw_writel(tcbpwm->duty, regs + ATMEL_TC_REG(group, RB));
__raw_writel(tcbpwm->period, regs + ATMEL_TC_REG(group, RC));
__raw_writel(ATMEL_TC_CLKEN | ATMEL_TC_SWTRG,
regs + ATMEL_TC_REG(group, CCR));
spin_unlock(&tcbpwmc->lock);
return 0;
}
static int atmel_tcb_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct atmel_tcb_pwm_chip *tcbpwmc = to_tcb_chip(chip);
struct atmel_tcb_pwm_device *tcbpwm = pwm_get_chip_data(pwm);
unsigned group = pwm->hwpwm / 2;
unsigned index = pwm->hwpwm % 2;
struct atmel_tcb_pwm_device *atcbpwm = NULL;
struct atmel_tc *tc = tcbpwmc->tc;
int i;
int slowclk = 0;
unsigned period;
unsigned duty;
unsigned rate = clk_get_rate(tc->clk[group]);
unsigned long long min;
unsigned long long max;
for (i = 0; i < 5; ++i) {
if (atmel_tc_divisors[i] == 0) {
slowclk = i;
continue;
}
min = div_u64((u64)NSEC_PER_SEC * atmel_tc_divisors[i], rate);
max = min << tc->tcb_config->counter_width;
if (max >= period_ns)
break;
}
if (i == 5) {
i = slowclk;
rate = clk_get_rate(tc->slow_clk);
min = div_u64(NSEC_PER_SEC, rate);
max = min << tc->tcb_config->counter_width;
if (max < period_ns)
return -ERANGE;
}
duty = div_u64(duty_ns, min);
period = div_u64(period_ns, min);
if (index == 0)
atcbpwm = tcbpwmc->pwms[pwm->hwpwm + 1];
else
atcbpwm = tcbpwmc->pwms[pwm->hwpwm - 1];
if ((atcbpwm && atcbpwm->duty > 0 &&
atcbpwm->duty != atcbpwm->period) &&
(atcbpwm->div != i || atcbpwm->period != period)) {
dev_err(chip->dev,
"failed to configure period_ns: PWM group already configured with a different value\n");
return -EINVAL;
}
tcbpwm->period = period;
tcbpwm->div = i;
tcbpwm->duty = duty;
if (pwm_is_enabled(pwm))
atmel_tcb_pwm_enable(chip, pwm);
return 0;
}
static int atmel_tcb_pwm_probe(struct platform_device *pdev)
{
struct atmel_tcb_pwm_chip *tcbpwm;
struct device_node *np = pdev->dev.of_node;
struct atmel_tc *tc;
int err;
int tcblock;
err = of_property_read_u32(np, "tc-block", &tcblock);
if (err < 0) {
dev_err(&pdev->dev,
"failed to get Timer Counter Block number from device tree (error: %d)\n",
err);
return err;
}
tc = atmel_tc_alloc(tcblock);
if (tc == NULL) {
dev_err(&pdev->dev, "failed to allocate Timer Counter Block\n");
return -ENOMEM;
}
tcbpwm = devm_kzalloc(&pdev->dev, sizeof(*tcbpwm), GFP_KERNEL);
if (tcbpwm == NULL) {
err = -ENOMEM;
dev_err(&pdev->dev, "failed to allocate memory\n");
goto err_free_tc;
}
tcbpwm->chip.dev = &pdev->dev;
tcbpwm->chip.ops = &atmel_tcb_pwm_ops;
tcbpwm->chip.of_xlate = of_pwm_xlate_with_flags;
tcbpwm->chip.of_pwm_n_cells = 3;
tcbpwm->chip.base = -1;
tcbpwm->chip.npwm = NPWM;
tcbpwm->tc = tc;
err = clk_prepare_enable(tc->slow_clk);
if (err)
goto err_free_tc;
spin_lock_init(&tcbpwm->lock);
err = pwmchip_add(&tcbpwm->chip);
if (err < 0)
goto err_disable_clk;
platform_set_drvdata(pdev, tcbpwm);
return 0;
err_disable_clk:
clk_disable_unprepare(tcbpwm->tc->slow_clk);
err_free_tc:
atmel_tc_free(tc);
return err;
}
static int atmel_tcb_pwm_remove(struct platform_device *pdev)
{
struct atmel_tcb_pwm_chip *tcbpwm = platform_get_drvdata(pdev);
int err;
clk_disable_unprepare(tcbpwm->tc->slow_clk);
err = pwmchip_remove(&tcbpwm->chip);
if (err < 0)
return err;
atmel_tc_free(tcbpwm->tc);
return 0;
}
