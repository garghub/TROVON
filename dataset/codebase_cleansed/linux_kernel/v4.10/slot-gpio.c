static irqreturn_t mmc_gpio_cd_irqt(int irq, void *dev_id)
{
struct mmc_host *host = dev_id;
host->trigger_card_event = true;
mmc_detect_change(host, msecs_to_jiffies(200));
return IRQ_HANDLED;
}
int mmc_gpio_alloc(struct mmc_host *host)
{
size_t len = strlen(dev_name(host->parent)) + 4;
struct mmc_gpio *ctx = devm_kzalloc(host->parent,
sizeof(*ctx) + 2 * len, GFP_KERNEL);
if (ctx) {
ctx->ro_label = ctx->cd_label + len;
snprintf(ctx->cd_label, len, "%s cd", dev_name(host->parent));
snprintf(ctx->ro_label, len, "%s ro", dev_name(host->parent));
host->slot.handler_priv = ctx;
host->slot.cd_irq = -EINVAL;
}
return ctx ? 0 : -ENOMEM;
}
int mmc_gpio_get_ro(struct mmc_host *host)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
if (!ctx || !ctx->ro_gpio)
return -ENOSYS;
if (ctx->override_ro_active_level)
return !gpiod_get_raw_value_cansleep(ctx->ro_gpio) ^
!!(host->caps2 & MMC_CAP2_RO_ACTIVE_HIGH);
return gpiod_get_value_cansleep(ctx->ro_gpio);
}
int mmc_gpio_get_cd(struct mmc_host *host)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
if (!ctx || !ctx->cd_gpio)
return -ENOSYS;
if (ctx->override_cd_active_level)
return !gpiod_get_raw_value_cansleep(ctx->cd_gpio) ^
!!(host->caps2 & MMC_CAP2_CD_ACTIVE_HIGH);
return gpiod_get_value_cansleep(ctx->cd_gpio);
}
int mmc_gpio_request_ro(struct mmc_host *host, unsigned int gpio)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
int ret;
if (!gpio_is_valid(gpio))
return -EINVAL;
ret = devm_gpio_request_one(host->parent, gpio, GPIOF_DIR_IN,
ctx->ro_label);
if (ret < 0)
return ret;
ctx->override_ro_active_level = true;
ctx->ro_gpio = gpio_to_desc(gpio);
return 0;
}
void mmc_gpiod_request_cd_irq(struct mmc_host *host)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
int ret, irq;
if (host->slot.cd_irq >= 0 || !ctx || !ctx->cd_gpio)
return;
irq = gpiod_to_irq(ctx->cd_gpio);
if (irq >= 0 && host->caps & MMC_CAP_NEEDS_POLL)
irq = -EINVAL;
if (irq >= 0) {
if (!ctx->cd_gpio_isr)
ctx->cd_gpio_isr = mmc_gpio_cd_irqt;
ret = devm_request_threaded_irq(host->parent, irq,
NULL, ctx->cd_gpio_isr,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
ctx->cd_label, host);
if (ret < 0)
irq = ret;
}
host->slot.cd_irq = irq;
if (irq < 0)
host->caps |= MMC_CAP_NEEDS_POLL;
}
void mmc_gpio_set_cd_isr(struct mmc_host *host,
irqreturn_t (*isr)(int irq, void *dev_id))
{
struct mmc_gpio *ctx = host->slot.handler_priv;
WARN_ON(ctx->cd_gpio_isr);
ctx->cd_gpio_isr = isr;
}
int mmc_gpio_request_cd(struct mmc_host *host, unsigned int gpio,
unsigned int debounce)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
int ret;
ret = devm_gpio_request_one(host->parent, gpio, GPIOF_DIR_IN,
ctx->cd_label);
if (ret < 0)
return ret;
if (debounce) {
ret = gpio_set_debounce(gpio, debounce);
if (ret < 0)
return ret;
}
ctx->override_cd_active_level = true;
ctx->cd_gpio = gpio_to_desc(gpio);
return 0;
}
int mmc_gpiod_request_cd(struct mmc_host *host, const char *con_id,
unsigned int idx, bool override_active_level,
unsigned int debounce, bool *gpio_invert)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
struct gpio_desc *desc;
int ret;
if (!con_id)
con_id = ctx->cd_label;
desc = devm_gpiod_get_index(host->parent, con_id, idx, GPIOD_IN);
if (IS_ERR(desc))
return PTR_ERR(desc);
if (debounce) {
ret = gpiod_set_debounce(desc, debounce);
if (ret < 0)
return ret;
}
if (gpio_invert)
*gpio_invert = !gpiod_is_active_low(desc);
ctx->override_cd_active_level = override_active_level;
ctx->cd_gpio = desc;
return 0;
}
bool mmc_can_gpio_cd(struct mmc_host *host)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
return ctx->cd_gpio ? true : false;
}
int mmc_gpiod_request_ro(struct mmc_host *host, const char *con_id,
unsigned int idx, bool override_active_level,
unsigned int debounce, bool *gpio_invert)
{
struct mmc_gpio *ctx = host->slot.handler_priv;
struct gpio_desc *desc;
int ret;
if (!con_id)
con_id = ctx->ro_label;
desc = devm_gpiod_get_index(host->parent, con_id, idx, GPIOD_IN);
if (IS_ERR(desc))
return PTR_ERR(desc);
if (debounce) {
ret = gpiod_set_debounce(desc, debounce);
if (ret < 0)
return ret;
}
if (gpio_invert)
*gpio_invert = !gpiod_is_active_low(desc);
ctx->override_ro_active_level = override_active_level;
ctx->ro_gpio = desc;
return 0;
}
