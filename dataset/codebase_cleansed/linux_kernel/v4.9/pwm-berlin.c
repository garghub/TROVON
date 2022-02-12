static inline struct berlin_pwm_chip *to_berlin_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct berlin_pwm_chip, chip);
}
static inline u32 berlin_pwm_readl(struct berlin_pwm_chip *chip,
unsigned int channel, unsigned long offset)
{
return readl_relaxed(chip->base + channel * 0x10 + offset);
}
static inline void berlin_pwm_writel(struct berlin_pwm_chip *chip,
unsigned int channel, u32 value,
unsigned long offset)
{
writel_relaxed(value, chip->base + channel * 0x10 + offset);
}
static int berlin_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct berlin_pwm_channel *channel;
channel = kzalloc(sizeof(*channel), GFP_KERNEL);
if (!channel)
return -ENOMEM;
return pwm_set_chip_data(pwm, channel);
}
static void berlin_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct berlin_pwm_channel *channel = pwm_get_chip_data(pwm);
pwm_set_chip_data(pwm, NULL);
kfree(channel);
}
static int berlin_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm_dev,
int duty_ns, int period_ns)
{
struct berlin_pwm_chip *pwm = to_berlin_pwm_chip(chip);
unsigned int prescale;
u32 value, duty, period;
u64 cycles, tmp;
cycles = clk_get_rate(pwm->clk);
cycles *= period_ns;
do_div(cycles, NSEC_PER_SEC);
for (prescale = 0; prescale < ARRAY_SIZE(prescaler_table); prescale++) {
tmp = cycles;
do_div(tmp, prescaler_table[prescale]);
if (tmp <= BERLIN_PWM_MAX_TCNT)
break;
}
if (tmp > BERLIN_PWM_MAX_TCNT)
return -ERANGE;
period = tmp;
cycles = tmp * duty_ns;
do_div(cycles, period_ns);
duty = cycles;
value = berlin_pwm_readl(pwm, pwm_dev->hwpwm, BERLIN_PWM_CONTROL);
value &= ~BERLIN_PWM_PRESCALE_MASK;
value |= prescale;
berlin_pwm_writel(pwm, pwm_dev->hwpwm, value, BERLIN_PWM_CONTROL);
berlin_pwm_writel(pwm, pwm_dev->hwpwm, duty, BERLIN_PWM_DUTY);
berlin_pwm_writel(pwm, pwm_dev->hwpwm, period, BERLIN_PWM_TCNT);
return 0;
}
static int berlin_pwm_set_polarity(struct pwm_chip *chip,
struct pwm_device *pwm_dev,
enum pwm_polarity polarity)
{
struct berlin_pwm_chip *pwm = to_berlin_pwm_chip(chip);
u32 value;
value = berlin_pwm_readl(pwm, pwm_dev->hwpwm, BERLIN_PWM_CONTROL);
if (polarity == PWM_POLARITY_NORMAL)
value &= ~BERLIN_PWM_INVERT_POLARITY;
else
value |= BERLIN_PWM_INVERT_POLARITY;
berlin_pwm_writel(pwm, pwm_dev->hwpwm, value, BERLIN_PWM_CONTROL);
return 0;
}
static int berlin_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm_dev)
{
struct berlin_pwm_chip *pwm = to_berlin_pwm_chip(chip);
u32 value;
value = berlin_pwm_readl(pwm, pwm_dev->hwpwm, BERLIN_PWM_EN);
value |= BERLIN_PWM_ENABLE;
berlin_pwm_writel(pwm, pwm_dev->hwpwm, value, BERLIN_PWM_EN);
return 0;
}
static void berlin_pwm_disable(struct pwm_chip *chip,
struct pwm_device *pwm_dev)
{
struct berlin_pwm_chip *pwm = to_berlin_pwm_chip(chip);
u32 value;
value = berlin_pwm_readl(pwm, pwm_dev->hwpwm, BERLIN_PWM_EN);
value &= ~BERLIN_PWM_ENABLE;
berlin_pwm_writel(pwm, pwm_dev->hwpwm, value, BERLIN_PWM_EN);
}
static int berlin_pwm_probe(struct platform_device *pdev)
{
struct berlin_pwm_chip *pwm;
struct resource *res;
int ret;
pwm = devm_kzalloc(&pdev->dev, sizeof(*pwm), GFP_KERNEL);
if (!pwm)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pwm->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pwm->base))
return PTR_ERR(pwm->base);
pwm->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pwm->clk))
return PTR_ERR(pwm->clk);
ret = clk_prepare_enable(pwm->clk);
if (ret)
return ret;
pwm->chip.dev = &pdev->dev;
pwm->chip.ops = &berlin_pwm_ops;
pwm->chip.base = -1;
pwm->chip.npwm = 4;
pwm->chip.can_sleep = true;
pwm->chip.of_xlate = of_pwm_xlate_with_flags;
pwm->chip.of_pwm_n_cells = 3;
ret = pwmchip_add(&pwm->chip);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add PWM chip: %d\n", ret);
clk_disable_unprepare(pwm->clk);
return ret;
}
platform_set_drvdata(pdev, pwm);
return 0;
}
static int berlin_pwm_remove(struct platform_device *pdev)
{
struct berlin_pwm_chip *pwm = platform_get_drvdata(pdev);
int ret;
ret = pwmchip_remove(&pwm->chip);
clk_disable_unprepare(pwm->clk);
return ret;
}
static int berlin_pwm_suspend(struct device *dev)
{
struct berlin_pwm_chip *pwm = dev_get_drvdata(dev);
unsigned int i;
for (i = 0; i < pwm->chip.npwm; i++) {
struct berlin_pwm_channel *channel;
channel = pwm_get_chip_data(&pwm->chip.pwms[i]);
if (!channel)
continue;
channel->enable = berlin_pwm_readl(pwm, i, BERLIN_PWM_ENABLE);
channel->ctrl = berlin_pwm_readl(pwm, i, BERLIN_PWM_CONTROL);
channel->duty = berlin_pwm_readl(pwm, i, BERLIN_PWM_DUTY);
channel->tcnt = berlin_pwm_readl(pwm, i, BERLIN_PWM_TCNT);
}
clk_disable_unprepare(pwm->clk);
return 0;
}
static int berlin_pwm_resume(struct device *dev)
{
struct berlin_pwm_chip *pwm = dev_get_drvdata(dev);
unsigned int i;
int ret;
ret = clk_prepare_enable(pwm->clk);
if (ret)
return ret;
for (i = 0; i < pwm->chip.npwm; i++) {
struct berlin_pwm_channel *channel;
channel = pwm_get_chip_data(&pwm->chip.pwms[i]);
if (!channel)
continue;
berlin_pwm_writel(pwm, i, channel->ctrl, BERLIN_PWM_CONTROL);
berlin_pwm_writel(pwm, i, channel->duty, BERLIN_PWM_DUTY);
berlin_pwm_writel(pwm, i, channel->tcnt, BERLIN_PWM_TCNT);
berlin_pwm_writel(pwm, i, channel->enable, BERLIN_PWM_ENABLE);
}
return 0;
}
