static inline int pwm_is_tdiv(struct s3c_chip *chip)
{
return clk_get_parent(chip->clk) == chip->clk_div;
}
static int s3c_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct s3c_chip *s3c = to_s3c_chip(chip);
unsigned long flags;
unsigned long tcon;
local_irq_save(flags);
tcon = __raw_readl(S3C2410_TCON);
tcon |= pwm_tcon_start(s3c);
__raw_writel(tcon, S3C2410_TCON);
local_irq_restore(flags);
return 0;
}
static void s3c_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct s3c_chip *s3c = to_s3c_chip(chip);
unsigned long flags;
unsigned long tcon;
local_irq_save(flags);
tcon = __raw_readl(S3C2410_TCON);
tcon &= ~pwm_tcon_start(s3c);
__raw_writel(tcon, S3C2410_TCON);
local_irq_restore(flags);
}
static unsigned long pwm_calc_tin(struct s3c_chip *s3c, unsigned long freq)
{
unsigned long tin_parent_rate;
unsigned int div;
tin_parent_rate = clk_get_rate(clk_get_parent(s3c->clk_div));
pwm_dbg(s3c, "tin parent at %lu\n", tin_parent_rate);
for (div = 2; div <= 16; div *= 2) {
if ((tin_parent_rate / (div << 16)) < freq)
return tin_parent_rate / div;
}
return tin_parent_rate / 16;
}
static int s3c_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct s3c_chip *s3c = to_s3c_chip(chip);
unsigned long tin_rate;
unsigned long tin_ns;
unsigned long period;
unsigned long flags;
unsigned long tcon;
unsigned long tcnt;
long tcmp;
if (period_ns > NS_IN_HZ || duty_ns > NS_IN_HZ)
return -ERANGE;
if (period_ns == s3c->period_ns &&
duty_ns == s3c->duty_ns)
return 0;
tcmp = __raw_readl(S3C2410_TCMPB(s3c->pwm_id));
tcnt = __raw_readl(S3C2410_TCNTB(s3c->pwm_id));
period = NS_IN_HZ / period_ns;
pwm_dbg(s3c, "duty_ns=%d, period_ns=%d (%lu)\n",
duty_ns, period_ns, period);
if (s3c->period_ns != period_ns) {
if (pwm_is_tdiv(s3c)) {
tin_rate = pwm_calc_tin(s3c, period);
clk_set_rate(s3c->clk_div, tin_rate);
} else
tin_rate = clk_get_rate(s3c->clk);
s3c->period_ns = period_ns;
pwm_dbg(s3c, "tin_rate=%lu\n", tin_rate);
tin_ns = NS_IN_HZ / tin_rate;
tcnt = period_ns / tin_ns;
} else
tin_ns = NS_IN_HZ / clk_get_rate(s3c->clk);
tcmp = duty_ns / tin_ns;
tcmp = tcnt - tcmp;
if (tcmp == tcnt)
tcmp--;
pwm_dbg(s3c, "tin_ns=%lu, tcmp=%ld/%lu\n", tin_ns, tcmp, tcnt);
if (tcmp < 0)
tcmp = 0;
local_irq_save(flags);
__raw_writel(tcmp, S3C2410_TCMPB(s3c->pwm_id));
__raw_writel(tcnt, S3C2410_TCNTB(s3c->pwm_id));
tcon = __raw_readl(S3C2410_TCON);
tcon |= pwm_tcon_manulupdate(s3c);
tcon |= pwm_tcon_autoreload(s3c);
__raw_writel(tcon, S3C2410_TCON);
tcon &= ~pwm_tcon_manulupdate(s3c);
__raw_writel(tcon, S3C2410_TCON);
local_irq_restore(flags);
return 0;
}
static int s3c_pwm_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct s3c_chip *s3c;
unsigned long flags;
unsigned long tcon;
unsigned int id = pdev->id;
int ret;
if (id == 4) {
dev_err(dev, "TIMER4 is currently not supported\n");
return -ENXIO;
}
s3c = devm_kzalloc(&pdev->dev, sizeof(*s3c), GFP_KERNEL);
if (s3c == NULL) {
dev_err(dev, "failed to allocate pwm_device\n");
return -ENOMEM;
}
s3c->tcon_base = id == 0 ? 0 : (id * 4) + 4;
s3c->pwm_id = id;
s3c->chip.dev = &pdev->dev;
s3c->chip.ops = &s3c_pwm_ops;
s3c->chip.base = -1;
s3c->chip.npwm = 1;
s3c->clk = devm_clk_get(dev, "pwm-tin");
if (IS_ERR(s3c->clk)) {
dev_err(dev, "failed to get pwm tin clk\n");
return PTR_ERR(s3c->clk);
}
s3c->clk_div = devm_clk_get(dev, "pwm-tdiv");
if (IS_ERR(s3c->clk_div)) {
dev_err(dev, "failed to get pwm tdiv clk\n");
return PTR_ERR(s3c->clk_div);
}
clk_enable(s3c->clk);
clk_enable(s3c->clk_div);
local_irq_save(flags);
tcon = __raw_readl(S3C2410_TCON);
tcon |= pwm_tcon_invert(s3c);
__raw_writel(tcon, S3C2410_TCON);
local_irq_restore(flags);
ret = pwmchip_add(&s3c->chip);
if (ret < 0) {
dev_err(dev, "failed to register pwm\n");
goto err_clk_tdiv;
}
pwm_dbg(s3c, "config bits %02x\n",
(__raw_readl(S3C2410_TCON) >> s3c->tcon_base) & 0x0f);
dev_info(dev, "tin at %lu, tdiv at %lu, tin=%sclk, base %d\n",
clk_get_rate(s3c->clk),
clk_get_rate(s3c->clk_div),
pwm_is_tdiv(s3c) ? "div" : "ext", s3c->tcon_base);
platform_set_drvdata(pdev, s3c);
return 0;
err_clk_tdiv:
clk_disable(s3c->clk_div);
clk_disable(s3c->clk);
return ret;
}
static int s3c_pwm_remove(struct platform_device *pdev)
{
struct s3c_chip *s3c = platform_get_drvdata(pdev);
int err;
err = pwmchip_remove(&s3c->chip);
if (err < 0)
return err;
clk_disable(s3c->clk_div);
clk_disable(s3c->clk);
return 0;
}
static int s3c_pwm_suspend(struct platform_device *pdev, pm_message_t state)
{
struct s3c_chip *s3c = platform_get_drvdata(pdev);
s3c->period_ns = 0;
s3c->duty_ns = 0;
return 0;
}
static int s3c_pwm_resume(struct platform_device *pdev)
{
struct s3c_chip *s3c = platform_get_drvdata(pdev);
unsigned long tcon;
tcon = __raw_readl(S3C2410_TCON);
tcon |= pwm_tcon_invert(s3c);
__raw_writel(tcon, S3C2410_TCON);
return 0;
}
static int __init pwm_init(void)
{
int ret;
clk_scaler[0] = clk_get(NULL, "pwm-scaler0");
clk_scaler[1] = clk_get(NULL, "pwm-scaler1");
if (IS_ERR(clk_scaler[0]) || IS_ERR(clk_scaler[1])) {
pr_err("failed to get scaler clocks\n");
return -EINVAL;
}
ret = platform_driver_register(&s3c_pwm_driver);
if (ret)
pr_err("failed to add pwm driver\n");
return ret;
}
