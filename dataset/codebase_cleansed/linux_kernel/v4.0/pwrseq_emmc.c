static void __mmc_pwrseq_emmc_reset(struct mmc_pwrseq_emmc *pwrseq)
{
gpiod_set_value(pwrseq->reset_gpio, 1);
udelay(1);
gpiod_set_value(pwrseq->reset_gpio, 0);
udelay(200);
}
static void mmc_pwrseq_emmc_reset(struct mmc_host *host)
{
struct mmc_pwrseq_emmc *pwrseq = container_of(host->pwrseq,
struct mmc_pwrseq_emmc, pwrseq);
__mmc_pwrseq_emmc_reset(pwrseq);
}
static void mmc_pwrseq_emmc_free(struct mmc_host *host)
{
struct mmc_pwrseq_emmc *pwrseq = container_of(host->pwrseq,
struct mmc_pwrseq_emmc, pwrseq);
unregister_restart_handler(&pwrseq->reset_nb);
gpiod_put(pwrseq->reset_gpio);
kfree(pwrseq);
host->pwrseq = NULL;
}
static int mmc_pwrseq_emmc_reset_nb(struct notifier_block *this,
unsigned long mode, void *cmd)
{
struct mmc_pwrseq_emmc *pwrseq = container_of(this,
struct mmc_pwrseq_emmc, reset_nb);
__mmc_pwrseq_emmc_reset(pwrseq);
return NOTIFY_DONE;
}
int mmc_pwrseq_emmc_alloc(struct mmc_host *host, struct device *dev)
{
struct mmc_pwrseq_emmc *pwrseq;
int ret = 0;
pwrseq = kzalloc(sizeof(struct mmc_pwrseq_emmc), GFP_KERNEL);
if (!pwrseq)
return -ENOMEM;
pwrseq->reset_gpio = gpiod_get_index(dev, "reset", 0, GPIOD_OUT_LOW);
if (IS_ERR(pwrseq->reset_gpio)) {
ret = PTR_ERR(pwrseq->reset_gpio);
goto free;
}
pwrseq->reset_nb.notifier_call = mmc_pwrseq_emmc_reset_nb;
pwrseq->reset_nb.priority = 129;
register_restart_handler(&pwrseq->reset_nb);
pwrseq->pwrseq.ops = &mmc_pwrseq_emmc_ops;
host->pwrseq = &pwrseq->pwrseq;
return 0;
free:
kfree(pwrseq);
return ret;
}
