static inline struct pwm_lpss_chip *to_lpwm(struct pwm_chip *chip)
{
return container_of(chip, struct pwm_lpss_chip, chip);
}
static int pwm_lpss_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct pwm_lpss_chip *lpwm = to_lpwm(chip);
u8 on_time_div;
unsigned long c;
unsigned long long base_unit, freq = NSECS_PER_SEC;
u32 ctrl;
do_div(freq, period_ns);
base_unit = freq * 65536;
c = lpwm->clk_rate;
if (!c)
return -EINVAL;
do_div(base_unit, c);
base_unit += PWM_DIVISION_CORRECTION;
if (base_unit > PWM_LIMIT)
return -EINVAL;
if (duty_ns <= 0)
duty_ns = 1;
on_time_div = 255 - (255 * duty_ns / period_ns);
ctrl = readl(lpwm->regs + PWM);
ctrl &= ~(PWM_BASE_UNIT_MASK | PWM_ON_TIME_DIV_MASK);
ctrl |= (u16) base_unit << PWM_BASE_UNIT_SHIFT;
ctrl |= on_time_div;
ctrl |= PWM_SW_UPDATE;
writel(ctrl, lpwm->regs + PWM);
return 0;
}
static int pwm_lpss_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct pwm_lpss_chip *lpwm = to_lpwm(chip);
u32 ctrl;
ctrl = readl(lpwm->regs + PWM);
writel(ctrl | PWM_ENABLE, lpwm->regs + PWM);
return 0;
}
static void pwm_lpss_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct pwm_lpss_chip *lpwm = to_lpwm(chip);
u32 ctrl;
ctrl = readl(lpwm->regs + PWM);
writel(ctrl & ~PWM_ENABLE, lpwm->regs + PWM);
}
static struct pwm_lpss_chip *pwm_lpss_probe(struct device *dev,
struct resource *r,
const struct pwm_lpss_boardinfo *info)
{
struct pwm_lpss_chip *lpwm;
int ret;
lpwm = devm_kzalloc(dev, sizeof(*lpwm), GFP_KERNEL);
if (!lpwm)
return ERR_PTR(-ENOMEM);
lpwm->regs = devm_ioremap_resource(dev, r);
if (IS_ERR(lpwm->regs))
return ERR_CAST(lpwm->regs);
lpwm->clk_rate = info->clk_rate;
lpwm->chip.dev = dev;
lpwm->chip.ops = &pwm_lpss_ops;
lpwm->chip.base = -1;
lpwm->chip.npwm = 1;
ret = pwmchip_add(&lpwm->chip);
if (ret) {
dev_err(dev, "failed to add PWM chip: %d\n", ret);
return ERR_PTR(ret);
}
return lpwm;
}
static int pwm_lpss_remove(struct pwm_lpss_chip *lpwm)
{
u32 ctrl;
ctrl = readl(lpwm->regs + PWM);
writel(ctrl & ~PWM_ENABLE, lpwm->regs + PWM);
return pwmchip_remove(&lpwm->chip);
}
static int pwm_lpss_probe_pci(struct pci_dev *pdev,
const struct pci_device_id *id)
{
const struct pwm_lpss_boardinfo *info;
struct pwm_lpss_chip *lpwm;
int err;
err = pci_enable_device(pdev);
if (err < 0)
return err;
info = (struct pwm_lpss_boardinfo *)id->driver_data;
lpwm = pwm_lpss_probe(&pdev->dev, &pdev->resource[0], info);
if (IS_ERR(lpwm))
return PTR_ERR(lpwm);
pci_set_drvdata(pdev, lpwm);
return 0;
}
static void pwm_lpss_remove_pci(struct pci_dev *pdev)
{
struct pwm_lpss_chip *lpwm = pci_get_drvdata(pdev);
pwm_lpss_remove(lpwm);
pci_disable_device(pdev);
}
static int pwm_lpss_probe_platform(struct platform_device *pdev)
{
const struct pwm_lpss_boardinfo *info;
const struct acpi_device_id *id;
struct pwm_lpss_chip *lpwm;
struct resource *r;
id = acpi_match_device(pdev->dev.driver->acpi_match_table, &pdev->dev);
if (!id)
return -ENODEV;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info = (struct pwm_lpss_boardinfo *)id->driver_data;
lpwm = pwm_lpss_probe(&pdev->dev, r, info);
if (IS_ERR(lpwm))
return PTR_ERR(lpwm);
platform_set_drvdata(pdev, lpwm);
return 0;
}
static int pwm_lpss_remove_platform(struct platform_device *pdev)
{
struct pwm_lpss_chip *lpwm = platform_get_drvdata(pdev);
return pwm_lpss_remove(lpwm);
}
static int __init pwm_init(void)
{
pci_drv = pci_register_driver(&pwm_lpss_driver_pci);
plat_drv = platform_driver_register(&pwm_lpss_driver_platform);
if (pci_drv && plat_drv)
return pci_drv;
return 0;
}
static void __exit pwm_exit(void)
{
if (!pci_drv)
pci_unregister_driver(&pwm_lpss_driver_pci);
if (!plat_drv)
platform_driver_unregister(&pwm_lpss_driver_platform);
}
