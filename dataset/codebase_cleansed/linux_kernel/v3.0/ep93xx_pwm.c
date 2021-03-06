static inline void ep93xx_pwm_writel(struct ep93xx_pwm *pwm,
unsigned int val, unsigned int off)
{
__raw_writel(val, pwm->mmio_base + off);
}
static inline unsigned int ep93xx_pwm_readl(struct ep93xx_pwm *pwm,
unsigned int off)
{
return __raw_readl(pwm->mmio_base + off);
}
static inline void ep93xx_pwm_write_tc(struct ep93xx_pwm *pwm, u16 value)
{
ep93xx_pwm_writel(pwm, value, EP93XX_PWMx_TERM_COUNT);
}
static inline u16 ep93xx_pwm_read_tc(struct ep93xx_pwm *pwm)
{
return ep93xx_pwm_readl(pwm, EP93XX_PWMx_TERM_COUNT);
}
static inline void ep93xx_pwm_write_dc(struct ep93xx_pwm *pwm, u16 value)
{
ep93xx_pwm_writel(pwm, value, EP93XX_PWMx_DUTY_CYCLE);
}
static inline void ep93xx_pwm_enable(struct ep93xx_pwm *pwm)
{
ep93xx_pwm_writel(pwm, 0x1, EP93XX_PWMx_ENABLE);
}
static inline void ep93xx_pwm_disable(struct ep93xx_pwm *pwm)
{
ep93xx_pwm_writel(pwm, 0x0, EP93XX_PWMx_ENABLE);
}
static inline int ep93xx_pwm_is_enabled(struct ep93xx_pwm *pwm)
{
return ep93xx_pwm_readl(pwm, EP93XX_PWMx_ENABLE) & 0x1;
}
static inline void ep93xx_pwm_invert(struct ep93xx_pwm *pwm)
{
ep93xx_pwm_writel(pwm, 0x1, EP93XX_PWMx_INVERT);
}
static inline void ep93xx_pwm_normal(struct ep93xx_pwm *pwm)
{
ep93xx_pwm_writel(pwm, 0x0, EP93XX_PWMx_INVERT);
}
static inline int ep93xx_pwm_is_inverted(struct ep93xx_pwm *pwm)
{
return ep93xx_pwm_readl(pwm, EP93XX_PWMx_INVERT) & 0x1;
}
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
if (ep93xx_pwm_is_enabled(pwm)) {
unsigned long rate = clk_get_rate(pwm->clk);
u16 term = ep93xx_pwm_read_tc(pwm);
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
err = strict_strtol(buf, 10, &val);
if (err)
return -EINVAL;
if (val == 0) {
ep93xx_pwm_disable(pwm);
} else if (val <= (clk_get_rate(pwm->clk) / 2)) {
u32 term, duty;
val = (clk_get_rate(pwm->clk) / val) - 1;
if (val > EP93XX_PWM_MAX_COUNT)
val = EP93XX_PWM_MAX_COUNT;
if (val < 1)
val = 1;
term = ep93xx_pwm_read_tc(pwm);
duty = ((val + 1) * pwm->duty_percent / 100) - 1;
if (val > term) {
ep93xx_pwm_write_tc(pwm, val);
ep93xx_pwm_write_dc(pwm, duty);
} else {
ep93xx_pwm_write_dc(pwm, duty);
ep93xx_pwm_write_tc(pwm, val);
}
if (!ep93xx_pwm_is_enabled(pwm))
ep93xx_pwm_enable(pwm);
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
err = strict_strtol(buf, 10, &val);
if (err)
return -EINVAL;
if (val > 0 && val < 100) {
u32 term = ep93xx_pwm_read_tc(pwm);
ep93xx_pwm_write_dc(pwm, ((term + 1) * val / 100) - 1);
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
return sprintf(buf, "%d\n", ep93xx_pwm_is_inverted(pwm));
}
static ssize_t ep93xx_pwm_set_invert(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct platform_device *pdev = to_platform_device(dev);
struct ep93xx_pwm *pwm = platform_get_drvdata(pdev);
long val;
int err;
err = strict_strtol(buf, 10, &val);
if (err)
return -EINVAL;
if (val == 0)
ep93xx_pwm_normal(pwm);
else if (val == 1)
ep93xx_pwm_invert(pwm);
else
return -EINVAL;
return count;
}
static int __init ep93xx_pwm_probe(struct platform_device *pdev)
{
struct ep93xx_pwm *pwm;
struct resource *res;
int err;
err = ep93xx_pwm_acquire_gpio(pdev);
if (err)
return err;
pwm = kzalloc(sizeof(struct ep93xx_pwm), GFP_KERNEL);
if (!pwm) {
err = -ENOMEM;
goto fail_no_mem;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
err = -ENXIO;
goto fail_no_mem_resource;
}
res = request_mem_region(res->start, resource_size(res), pdev->name);
if (res == NULL) {
err = -EBUSY;
goto fail_no_mem_resource;
}
pwm->mmio_base = ioremap(res->start, resource_size(res));
if (pwm->mmio_base == NULL) {
err = -ENXIO;
goto fail_no_ioremap;
}
err = sysfs_create_group(&pdev->dev.kobj, &ep93xx_pwm_sysfs_files);
if (err)
goto fail_no_sysfs;
pwm->clk = clk_get(&pdev->dev, "pwm_clk");
if (IS_ERR(pwm->clk)) {
err = PTR_ERR(pwm->clk);
goto fail_no_clk;
}
pwm->duty_percent = 50;
platform_set_drvdata(pdev, pwm);
ep93xx_pwm_disable(pwm);
ep93xx_pwm_write_tc(pwm, EP93XX_PWM_MAX_COUNT);
ep93xx_pwm_write_dc(pwm, EP93XX_PWM_MAX_COUNT / 2);
clk_enable(pwm->clk);
return 0;
fail_no_clk:
sysfs_remove_group(&pdev->dev.kobj, &ep93xx_pwm_sysfs_files);
fail_no_sysfs:
iounmap(pwm->mmio_base);
fail_no_ioremap:
release_mem_region(res->start, resource_size(res));
fail_no_mem_resource:
kfree(pwm);
fail_no_mem:
ep93xx_pwm_release_gpio(pdev);
return err;
}
static int __exit ep93xx_pwm_remove(struct platform_device *pdev)
{
struct ep93xx_pwm *pwm = platform_get_drvdata(pdev);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ep93xx_pwm_disable(pwm);
clk_disable(pwm->clk);
clk_put(pwm->clk);
platform_set_drvdata(pdev, NULL);
sysfs_remove_group(&pdev->dev.kobj, &ep93xx_pwm_sysfs_files);
iounmap(pwm->mmio_base);
release_mem_region(res->start, resource_size(res));
kfree(pwm);
ep93xx_pwm_release_gpio(pdev);
return 0;
}
static int __init ep93xx_pwm_init(void)
{
return platform_driver_probe(&ep93xx_pwm_driver, ep93xx_pwm_probe);
}
static void __exit ep93xx_pwm_exit(void)
{
platform_driver_unregister(&ep93xx_pwm_driver);
}
