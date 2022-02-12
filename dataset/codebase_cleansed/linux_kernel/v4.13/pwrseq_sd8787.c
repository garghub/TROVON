static void mmc_pwrseq_sd8787_pre_power_on(struct mmc_host *host)
{
struct mmc_pwrseq_sd8787 *pwrseq = to_pwrseq_sd8787(host->pwrseq);
gpiod_set_value_cansleep(pwrseq->reset_gpio, 1);
msleep(300);
gpiod_set_value_cansleep(pwrseq->pwrdn_gpio, 1);
}
static void mmc_pwrseq_sd8787_power_off(struct mmc_host *host)
{
struct mmc_pwrseq_sd8787 *pwrseq = to_pwrseq_sd8787(host->pwrseq);
gpiod_set_value_cansleep(pwrseq->pwrdn_gpio, 0);
gpiod_set_value_cansleep(pwrseq->reset_gpio, 0);
}
static int mmc_pwrseq_sd8787_probe(struct platform_device *pdev)
{
struct mmc_pwrseq_sd8787 *pwrseq;
struct device *dev = &pdev->dev;
pwrseq = devm_kzalloc(dev, sizeof(*pwrseq), GFP_KERNEL);
if (!pwrseq)
return -ENOMEM;
pwrseq->pwrdn_gpio = devm_gpiod_get(dev, "powerdown", GPIOD_OUT_LOW);
if (IS_ERR(pwrseq->pwrdn_gpio))
return PTR_ERR(pwrseq->pwrdn_gpio);
pwrseq->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(pwrseq->reset_gpio))
return PTR_ERR(pwrseq->reset_gpio);
pwrseq->pwrseq.dev = dev;
pwrseq->pwrseq.ops = &mmc_pwrseq_sd8787_ops;
pwrseq->pwrseq.owner = THIS_MODULE;
platform_set_drvdata(pdev, pwrseq);
return mmc_pwrseq_register(&pwrseq->pwrseq);
}
static int mmc_pwrseq_sd8787_remove(struct platform_device *pdev)
{
struct mmc_pwrseq_sd8787 *pwrseq = platform_get_drvdata(pdev);
mmc_pwrseq_unregister(&pwrseq->pwrseq);
return 0;
}
