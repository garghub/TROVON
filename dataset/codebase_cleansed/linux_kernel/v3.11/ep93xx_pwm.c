static ssize_t ep93xx_pwm_get_min_freq(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct ep93xx_pwm *pwm = platform_get_drvdata(pdev);
unsigned long rate = clk_get_rate(pwm->clk);
return sprintf(buf, "%ld\n", rate / (EP93XX_PWM_MAX_COUNT + 1));
}
static ssize_t ep93xx_pwm_get_max_freq(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct ep93xx_pwm *pwm = platform_get_drvdata(pdev);
unsigned long rate = clk_get_rate(pwm->clk);
return sprintf(buf, "%ld\n", rate / 2);
}
static ssize_t ep93xx_pwm_get_freq(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct ep93xx_pwm *pwm = platform_get_drvdata(pdev);
if (readl(pwm->mmio_base + EP93XX_PWMx_ENABLE) & 0x1) {
unsigned long rate = clk_get_rate(pwm->clk);
u16 term = readl(pwm->mmio_base + EP93XX_PWMx_TERM_COUNT);
return sprintf(buf, "%ld\n", rate / (term + 1));
} else {
return sprintf(buf, "disabled\n");
}
}
static ssize_t ep93xx_pwm_set_freq(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct platform_device *pdev = to_platform_device(dev);
struct ep93xx_pwm *pwm = platform_get_drvdata(pdev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return -EINVAL;
if (val == 0) {
writel(0x0, pwm->mmio_base + EP93XX_PWMx_ENABLE);
} else if (val <= (clk_get_rate(pwm->clk) / 2)) {
u32 term, duty;
val = (clk_get_rate(pwm->clk) / val) - 1;
if (val > EP93XX_PWM_MAX_COUNT)
val = EP93XX_PWM_MAX_COUNT;
if (val < 1)
val = 1;
term = readl(pwm->mmio_base + EP93XX_PWMx_TERM_COUNT);
duty = ((val + 1) * pwm->duty_percent / 100) - 1;
if (val > term) {
writel(val, pwm->mmio_base + EP93XX_PWMx_TERM_COUNT);
writel(duty, pwm->mmio_base + EP93XX_PWMx_DUTY_CYCLE);
} else {
writel(duty, pwm->mmio_base + EP93XX_PWMx_DUTY_CYCLE);
writel(val, pwm->mmio_base + EP93XX_PWMx_TERM_COUNT);
}
if (!readl(pwm->mmio_base + EP93XX_PWMx_ENABLE) & 0x1)
writel(0x1, pwm->mmio_base + EP93XX_PWMx_ENABLE);
} else {
return -EINVAL;
}
return count;
}
static ssize_t ep93xx_pwm_get_duty_percent(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct ep93xx_pwm *pwm = platform_get_drvdata(pdev);
return sprintf(buf, "%d\n", pwm->duty_percent);
}
static ssize_t ep93xx_pwm_set_duty_percent(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct platform_device *pdev = to_platform_device(dev);
struct ep93xx_pwm *pwm = platform_get_drvdata(pdev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return -EINVAL;
if (val > 0 && val < 100) {
u32 term = readl(pwm->mmio_base + EP93XX_PWMx_TERM_COUNT);
u32 duty = ((term + 1) * val / 100) - 1;
writel(duty, pwm->mmio_base + EP93XX_PWMx_DUTY_CYCLE);
pwm->duty_percent = val;
return count;
}
return -EINVAL;
}
static ssize_t ep93xx_pwm_get_invert(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct ep93xx_pwm *pwm = platform_get_drvdata(pdev);
int inverted = readl(pwm->mmio_base + EP93XX_PWMx_INVERT) & 0x1;
return sprintf(buf, "%d\n", inverted);
}
static ssize_t ep93xx_pwm_set_invert(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct platform_device *pdev = to_platform_device(dev);
struct ep93xx_pwm *pwm = platform_get_drvdata(pdev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return -EINVAL;
if (val == 0)
writel(0x0, pwm->mmio_base + EP93XX_PWMx_INVERT);
else if (val == 1)
writel(0x1, pwm->mmio_base + EP93XX_PWMx_INVERT);
else
return -EINVAL;
return count;
}
static int ep93xx_pwm_probe(struct platform_device *pdev)
{
struct ep93xx_pwm *pwm;
struct resource *res;
int ret;
pwm = devm_kzalloc(&pdev->dev, sizeof(*pwm), GFP_KERNEL);
if (!pwm)
return -ENOMEM;
pwm->clk = devm_clk_get(&pdev->dev, "pwm_clk");
if (IS_ERR(pwm->clk))
return PTR_ERR(pwm->clk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pwm->mmio_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pwm->mmio_base))
return PTR_ERR(pwm->mmio_base);
ret = ep93xx_pwm_acquire_gpio(pdev);
if (ret)
return ret;
ret = sysfs_create_group(&pdev->dev.kobj, &ep93xx_pwm_sysfs_files);
if (ret) {
ep93xx_pwm_release_gpio(pdev);
return ret;
}
pwm->duty_percent = 50;
writel(0x0, pwm->mmio_base + EP93XX_PWMx_ENABLE);
writel(EP93XX_PWM_MAX_COUNT, pwm->mmio_base + EP93XX_PWMx_TERM_COUNT);
writel(EP93XX_PWM_MAX_COUNT/2, pwm->mmio_base + EP93XX_PWMx_DUTY_CYCLE);
clk_enable(pwm->clk);
platform_set_drvdata(pdev, pwm);
return 0;
}
static int ep93xx_pwm_remove(struct platform_device *pdev)
{
struct ep93xx_pwm *pwm = platform_get_drvdata(pdev);
writel(0x0, pwm->mmio_base + EP93XX_PWMx_ENABLE);
clk_disable(pwm->clk);
sysfs_remove_group(&pdev->dev.kobj, &ep93xx_pwm_sysfs_files);
ep93xx_pwm_release_gpio(pdev);
return 0;
}
