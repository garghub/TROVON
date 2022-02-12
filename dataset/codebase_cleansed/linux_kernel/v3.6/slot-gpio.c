static irqreturn_t mmc_gpio_cd_irqt(int irq, void *dev_id)
{
mmc_detect_change(dev_id, msecs_to_jiffies(100));
return IRQ_HANDLED;
}
static int mmc_gpio_alloc(struct mmc_host *host)
{
size_t len = strlen(dev_name(host->parent)) + 4;
struct mmc_gpio *ctx;
mutex_lock(&host->slot.lock);
ctx = host->slot.handler_priv;
if (!ctx) {
ctx = devm_kzalloc(&host->class_dev, sizeof(*ctx) + 2 * len,
GFP_KERNEL);
if (ctx) {
ctx->ro_label = ctx->cd_label + len;
snprintf(ctx->cd_label, len, "%s cd", dev_name(host->parent));
snprintf(ctx->ro_label, len, "%s ro", dev_name(host->parent));
ctx->cd_gpio = -EINVAL;
ctx->ro_gpio = -EINVAL;
host->slot.handler_priv = ctx;
}
}
mutex_unlock(&host->slot.lock);
return ctx ? 0 : -ENOMEM;
}
int mmc_gpio_get_ro(struct mmc_host *host)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
if (!ctx || !gpio_is_valid(ctx->ro_gpio))
return -ENOSYS;
return !gpio_get_value_cansleep(ctx->ro_gpio) ^
!!(host->caps2 & MMC_CAP2_RO_ACTIVE_HIGH);
}
int mmc_gpio_get_cd(struct mmc_host *host)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
if (!ctx || !gpio_is_valid(ctx->cd_gpio))
return -ENOSYS;
return !gpio_get_value_cansleep(ctx->cd_gpio) ^
!!(host->caps2 & MMC_CAP2_CD_ACTIVE_HIGH);
}
int mmc_gpio_request_ro(struct mmc_host *host, unsigned int gpio)
{
struct mmc_gpio *ctx;
int ret;
if (!gpio_is_valid(gpio))
return -EINVAL;
ret = mmc_gpio_alloc(host);
if (ret < 0)
return ret;
ctx = host->slot.handler_priv;
return gpio_request_one(gpio, GPIOF_DIR_IN, ctx->ro_label);
}
int mmc_gpio_request_cd(struct mmc_host *host, unsigned int gpio)
{
struct mmc_gpio *ctx;
int irq = gpio_to_irq(gpio);
int ret;
ret = mmc_gpio_alloc(host);
if (ret < 0)
return ret;
ctx = host->slot.handler_priv;
ret = gpio_request_one(gpio, GPIOF_DIR_IN, ctx->cd_label);
if (ret < 0)
return ret;
if (irq >= 0 && host->caps & MMC_CAP_NEEDS_POLL)
irq = -EINVAL;
if (irq >= 0) {
ret = request_threaded_irq(irq, NULL, mmc_gpio_cd_irqt,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
ctx->cd_label, host);
if (ret < 0)
irq = ret;
}
host->slot.cd_irq = irq;
if (irq < 0)
host->caps |= MMC_CAP_NEEDS_POLL;
ctx->cd_gpio = gpio;
return 0;
}
void mmc_gpio_free_ro(struct mmc_host *host)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
int gpio;
if (!ctx || !gpio_is_valid(ctx->ro_gpio))
return;
gpio = ctx->ro_gpio;
ctx->ro_gpio = -EINVAL;
gpio_free(gpio);
}
void mmc_gpio_free_cd(struct mmc_host *host)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
int gpio;
if (!ctx || !gpio_is_valid(ctx->cd_gpio))
return;
if (host->slot.cd_irq >= 0) {
free_irq(host->slot.cd_irq, host);
host->slot.cd_irq = -EINVAL;
}
gpio = ctx->cd_gpio;
ctx->cd_gpio = -EINVAL;
gpio_free(gpio);
}
