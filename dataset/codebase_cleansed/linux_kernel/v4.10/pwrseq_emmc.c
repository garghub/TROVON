static void __mmc_pwrseq_emmc_reset(struct mmc_pwrseq_emmc *pwrseq)
{
gpiod_set_value(pwrseq->reset_gpio, 1);
udelay(1);
gpiod_set_value(pwrseq->reset_gpio, 0);
udelay(200);
}
static void mmc_pwrseq_emmc_reset(struct mmc_host *host)
{
struct mmc_pwrseq_emmc *pwrseq = to_pwrseq_emmc(host->pwrseq);
__mmc_pwrseq_emmc_reset(pwrseq);
}
static int mmc_pwrseq_emmc_reset_nb(struct notifier_block *this,
unsigned long mode, void *cmd)
{
struct mmc_pwrseq_emmc *pwrseq = container_of(this,
struct mmc_pwrseq_emmc, reset_nb);
__mmc_pwrseq_emmc_reset(pwrseq);
return NOTIFY_DONE;
}
static int mmc_pwrseq_emmc_probe(struct platform_device *pdev)
{
struct mmc_pwrseq_emmc *pwrseq;
struct device *dev = &pdev->dev;
pwrseq = devm_kzalloc(dev, sizeof(*pwrseq), GFP_KERNEL);
if (!pwrseq)
return -ENOMEM;
pwrseq->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(pwrseq->reset_gpio))
return PTR_ERR(pwrseq->reset_gpio);
pwrseq->reset_nb.notifier_call = mmc_pwrseq_emmc_reset_nb;
pwrseq->reset_nb.priority = 255;
register_restart_handler(&pwrseq->reset_nb);
pwrseq->pwrseq.ops = &mmc_pwrseq_emmc_ops;
pwrseq->pwrseq.dev = dev;
pwrseq->pwrseq.owner = THIS_MODULE;
platform_set_drvdata(pdev, pwrseq);
return mmc_pwrseq_register(&pwrseq->pwrseq);
}
static int mmc_pwrseq_emmc_remove(struct platform_device *pdev)
{
struct mmc_pwrseq_emmc *pwrseq = platform_get_drvdata(pdev);
unregister_restart_handler(&pwrseq->reset_nb);
mmc_pwrseq_unregister(&pwrseq->pwrseq);
return 0;
}
