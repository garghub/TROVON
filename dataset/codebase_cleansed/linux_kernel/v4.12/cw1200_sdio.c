void __init cw1200_sdio_set_platform_data(struct cw1200_platform_data_sdio *pdata)
{
global_plat_data = pdata;
}
static int cw1200_sdio_memcpy_fromio(struct hwbus_priv *self,
unsigned int addr,
void *dst, int count)
{
return sdio_memcpy_fromio(self->func, dst, addr, count);
}
static int cw1200_sdio_memcpy_toio(struct hwbus_priv *self,
unsigned int addr,
const void *src, int count)
{
return sdio_memcpy_toio(self->func, addr, (void *)src, count);
}
static void cw1200_sdio_lock(struct hwbus_priv *self)
{
sdio_claim_host(self->func);
}
static void cw1200_sdio_unlock(struct hwbus_priv *self)
{
sdio_release_host(self->func);
}
static void cw1200_sdio_irq_handler(struct sdio_func *func)
{
struct hwbus_priv *self = sdio_get_drvdata(func);
if (self->core)
cw1200_irq_handler(self->core);
}
static irqreturn_t cw1200_gpio_hardirq(int irq, void *dev_id)
{
return IRQ_WAKE_THREAD;
}
static irqreturn_t cw1200_gpio_irq(int irq, void *dev_id)
{
struct hwbus_priv *self = dev_id;
if (self->core) {
cw1200_sdio_lock(self);
cw1200_irq_handler(self->core);
cw1200_sdio_unlock(self);
return IRQ_HANDLED;
} else {
return IRQ_NONE;
}
}
static int cw1200_request_irq(struct hwbus_priv *self)
{
int ret;
u8 cccr;
cccr = sdio_f0_readb(self->func, SDIO_CCCR_IENx, &ret);
if (WARN_ON(ret))
goto err;
cccr |= BIT(0);
cccr |= BIT(self->func->num);
sdio_f0_writeb(self->func, cccr, SDIO_CCCR_IENx, &ret);
if (WARN_ON(ret))
goto err;
ret = enable_irq_wake(self->pdata->irq);
if (WARN_ON(ret))
goto err;
ret = request_threaded_irq(self->pdata->irq, cw1200_gpio_hardirq,
cw1200_gpio_irq,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
"cw1200_wlan_irq", self);
if (WARN_ON(ret))
goto err;
return 0;
err:
return ret;
}
static int cw1200_sdio_irq_subscribe(struct hwbus_priv *self)
{
int ret = 0;
pr_debug("SW IRQ subscribe\n");
sdio_claim_host(self->func);
if (self->pdata->irq)
ret = cw1200_request_irq(self);
else
ret = sdio_claim_irq(self->func, cw1200_sdio_irq_handler);
sdio_release_host(self->func);
return ret;
}
static int cw1200_sdio_irq_unsubscribe(struct hwbus_priv *self)
{
int ret = 0;
pr_debug("SW IRQ unsubscribe\n");
if (self->pdata->irq) {
disable_irq_wake(self->pdata->irq);
free_irq(self->pdata->irq, self);
} else {
sdio_claim_host(self->func);
ret = sdio_release_irq(self->func);
sdio_release_host(self->func);
}
return ret;
}
static int cw1200_sdio_off(const struct cw1200_platform_data_sdio *pdata)
{
if (pdata->reset) {
gpio_set_value(pdata->reset, 0);
msleep(30);
gpio_free(pdata->reset);
}
if (pdata->power_ctrl)
pdata->power_ctrl(pdata, false);
if (pdata->clk_ctrl)
pdata->clk_ctrl(pdata, false);
return 0;
}
static int cw1200_sdio_on(const struct cw1200_platform_data_sdio *pdata)
{
if (pdata->reset) {
gpio_request(pdata->reset, "cw1200_wlan_reset");
gpio_direction_output(pdata->reset, 0);
}
if (pdata->powerup) {
gpio_request(pdata->powerup, "cw1200_wlan_powerup");
gpio_direction_output(pdata->powerup, 0);
}
if (pdata->reset || pdata->powerup)
msleep(10);
if (pdata->power_ctrl) {
if (pdata->power_ctrl(pdata, true)) {
pr_err("power_ctrl() failed!\n");
return -1;
}
}
if (pdata->clk_ctrl) {
if (pdata->clk_ctrl(pdata, true)) {
pr_err("clk_ctrl() failed!\n");
return -1;
}
msleep(10);
}
if (pdata->powerup) {
gpio_set_value(pdata->powerup, 1);
msleep(250);
}
if (pdata->reset) {
gpio_set_value(pdata->reset, 1);
msleep(50);
}
return 0;
}
static size_t cw1200_sdio_align_size(struct hwbus_priv *self, size_t size)
{
if (self->pdata->no_nptb)
size = round_up(size, SDIO_BLOCK_SIZE);
else
size = sdio_align_size(self->func, size);
return size;
}
static int cw1200_sdio_pm(struct hwbus_priv *self, bool suspend)
{
int ret = 0;
if (self->pdata->irq)
ret = irq_set_irq_wake(self->pdata->irq, suspend);
return ret;
}
static int cw1200_sdio_probe(struct sdio_func *func,
const struct sdio_device_id *id)
{
struct hwbus_priv *self;
int status;
pr_info("cw1200_wlan_sdio: Probe called\n");
if (func->num != 0x01)
return -ENODEV;
self = kzalloc(sizeof(*self), GFP_KERNEL);
if (!self) {
pr_err("Can't allocate SDIO hwbus_priv.\n");
return -ENOMEM;
}
func->card->quirks |= MMC_QUIRK_LENIENT_FN0;
self->pdata = global_plat_data;
self->func = func;
sdio_set_drvdata(func, self);
sdio_claim_host(func);
sdio_enable_func(func);
sdio_release_host(func);
status = cw1200_sdio_irq_subscribe(self);
status = cw1200_core_probe(&cw1200_sdio_hwbus_ops,
self, &func->dev, &self->core,
self->pdata->ref_clk,
self->pdata->macaddr,
self->pdata->sdd_file,
self->pdata->have_5ghz);
if (status) {
cw1200_sdio_irq_unsubscribe(self);
sdio_claim_host(func);
sdio_disable_func(func);
sdio_release_host(func);
sdio_set_drvdata(func, NULL);
kfree(self);
}
return status;
}
static void cw1200_sdio_disconnect(struct sdio_func *func)
{
struct hwbus_priv *self = sdio_get_drvdata(func);
if (self) {
cw1200_sdio_irq_unsubscribe(self);
if (self->core) {
cw1200_core_release(self->core);
self->core = NULL;
}
sdio_claim_host(func);
sdio_disable_func(func);
sdio_release_host(func);
sdio_set_drvdata(func, NULL);
kfree(self);
}
}
static int cw1200_sdio_suspend(struct device *dev)
{
int ret;
struct sdio_func *func = dev_to_sdio_func(dev);
struct hwbus_priv *self = sdio_get_drvdata(func);
if (!cw1200_can_suspend(self->core))
return -EAGAIN;
ret = sdio_set_host_pm_flags(func, MMC_PM_KEEP_POWER);
if (ret)
pr_err("Error setting SDIO pm flags: %i\n", ret);
return ret;
}
static int cw1200_sdio_resume(struct device *dev)
{
return 0;
}
static int __init cw1200_sdio_init(void)
{
const struct cw1200_platform_data_sdio *pdata;
int ret;
pdata = global_plat_data;
if (cw1200_sdio_on(pdata)) {
ret = -1;
goto err;
}
ret = sdio_register_driver(&sdio_driver);
if (ret)
goto err;
return 0;
err:
cw1200_sdio_off(pdata);
return ret;
}
static void __exit cw1200_sdio_exit(void)
{
const struct cw1200_platform_data_sdio *pdata;
pdata = global_plat_data;
sdio_unregister_driver(&sdio_driver);
cw1200_sdio_off(pdata);
}
