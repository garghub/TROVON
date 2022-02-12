static CsrResult
ConvertSdioToCsrSdioResult(int r)
{
CsrResult csrResult = CSR_RESULT_FAILURE;
switch (r) {
case 0:
csrResult = CSR_RESULT_SUCCESS;
break;
case -EIO:
case -EILSEQ:
csrResult = CSR_SDIO_RESULT_CRC_ERROR;
break;
case -ETIMEDOUT:
case -EBUSY:
csrResult = CSR_SDIO_RESULT_TIMEOUT;
break;
case -ENODEV:
case -ENOMEDIUM:
csrResult = CSR_SDIO_RESULT_NO_DEVICE;
break;
case -EINVAL:
csrResult = CSR_SDIO_RESULT_INVALID_VALUE;
break;
case -ENOMEM:
case -ENOSYS:
case -ERANGE:
case -ENXIO:
csrResult = CSR_RESULT_FAILURE;
break;
default:
unifi_warning(NULL, "Unrecognised SDIO error code: %d\n", r);
break;
}
return csrResult;
}
static int
csr_io_rw_direct(struct mmc_card *card, int write, uint8_t fn,
uint32_t addr, uint8_t in, uint8_t* out)
{
struct mmc_command cmd;
int err;
BUG_ON(!card);
BUG_ON(fn > 7);
memset(&cmd, 0, sizeof(struct mmc_command));
cmd.opcode = SD_IO_RW_DIRECT;
cmd.arg = write ? 0x80000000 : 0x00000000;
cmd.arg |= fn << 28;
cmd.arg |= (write && out) ? 0x08000000 : 0x00000000;
cmd.arg |= addr << 9;
cmd.arg |= in;
cmd.flags = MMC_RSP_SPI_R5 | MMC_RSP_R5 | MMC_CMD_AC;
err = mmc_wait_for_cmd(card->host, &cmd, 0);
if (err)
return err;
if (0) {
} else {
if (cmd.resp[0] & R5_ERROR) {
printk(KERN_ERR "%s: r5 error 0x%02x\n",
__FUNCTION__, cmd.resp[0]);
return -EIO;
}
if (cmd.resp[0] & R5_FUNCTION_NUMBER)
return -EINVAL;
if (cmd.resp[0] & R5_OUT_OF_RANGE)
return -ERANGE;
}
if (out) {
if (0) {
*out = (cmd.resp[0] >> 8) & 0xFF;
}
else {
*out = cmd.resp[0] & 0xFF;
}
}
return CSR_RESULT_SUCCESS;
}
CsrResult
CsrSdioRead8(CsrSdioFunction *function, u32 address, u8 *data)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err = 0;
_sdio_claim_host(func);
*data = sdio_readb(func, address, &err);
_sdio_release_host(func);
if (err) {
return ConvertSdioToCsrSdioResult(err);
}
return CSR_RESULT_SUCCESS;
}
CsrResult
CsrSdioWrite8(CsrSdioFunction *function, u32 address, u8 data)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err = 0;
_sdio_claim_host(func);
sdio_writeb(func, data, address, &err);
_sdio_release_host(func);
if (err) {
return ConvertSdioToCsrSdioResult(err);
}
return CSR_RESULT_SUCCESS;
}
CsrResult
CsrSdioRead16(CsrSdioFunction *function, u32 address, u16 *data)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err;
uint8_t b0, b1;
_sdio_claim_host(func);
b0 = sdio_readb(func, address, &err);
if (err) {
_sdio_release_host(func);
return ConvertSdioToCsrSdioResult(err);
}
b1 = sdio_readb(func, address+1, &err);
if (err) {
_sdio_release_host(func);
return ConvertSdioToCsrSdioResult(err);
}
_sdio_release_host(func);
*data = ((uint16_t)b1 << 8) | b0;
return CSR_RESULT_SUCCESS;
}
CsrResult
CsrSdioWrite16(CsrSdioFunction *function, u32 address, u16 data)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err;
uint8_t b0, b1;
_sdio_claim_host(func);
b1 = (data >> 8) & 0xFF;
sdio_writeb(func, b1, address+1, &err);
if (err) {
_sdio_release_host(func);
return ConvertSdioToCsrSdioResult(err);
}
b0 = data & 0xFF;
sdio_writeb(func, b0, address, &err);
if (err) {
_sdio_release_host(func);
return ConvertSdioToCsrSdioResult(err);
}
_sdio_release_host(func);
return CSR_RESULT_SUCCESS;
}
CsrResult
CsrSdioF0Read8(CsrSdioFunction *function, u32 address, u8 *data)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err = 0;
_sdio_claim_host(func);
#ifdef MMC_QUIRK_LENIENT_FN0
*data = sdio_f0_readb(func, address, &err);
#else
err = csr_io_rw_direct(func->card, 0, 0, address, 0, data);
#endif
_sdio_release_host(func);
if (err) {
return ConvertSdioToCsrSdioResult(err);
}
return CSR_RESULT_SUCCESS;
}
CsrResult
CsrSdioF0Write8(CsrSdioFunction *function, u32 address, u8 data)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err = 0;
_sdio_claim_host(func);
#ifdef MMC_QUIRK_LENIENT_FN0
sdio_f0_writeb(func, data, address, &err);
#else
err = csr_io_rw_direct(func->card, 1, 0, address, data, NULL);
#endif
_sdio_release_host(func);
if (err) {
return ConvertSdioToCsrSdioResult(err);
}
return CSR_RESULT_SUCCESS;
}
CsrResult
CsrSdioRead(CsrSdioFunction *function, u32 address, void *data, u32 length)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err;
_sdio_claim_host(func);
err = sdio_readsb(func, data, address, length);
_sdio_release_host(func);
if (err) {
return ConvertSdioToCsrSdioResult(err);
}
return CSR_RESULT_SUCCESS;
}
CsrResult
CsrSdioWrite(CsrSdioFunction *function, u32 address, const void *data, u32 length)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err;
_sdio_claim_host(func);
err = sdio_writesb(func, address, (void*)data, length);
_sdio_release_host(func);
if (err) {
return ConvertSdioToCsrSdioResult(err);
}
return CSR_RESULT_SUCCESS;
}
static int
csr_sdio_enable_hs(struct mmc_card *card)
{
int ret;
u8 speed;
if (!(card->host->caps & MMC_CAP_SD_HIGHSPEED)) {
printk(KERN_INFO "unifi: request HS but not MMC_CAP_SD_HIGHSPEED");
return 0;
}
if (!card->cccr.high_speed)
return 0;
#if 1
ret = csr_io_rw_direct(card, 0, 0, SDIO_CCCR_SPEED, 0, &speed);
if (ret)
return ret;
speed |= SDIO_SPEED_EHS;
#else
speed = SDIO_SPEED_EHS | SDIO_SPEED_SHS;
#endif
ret = csr_io_rw_direct(card, 1, 0, SDIO_CCCR_SPEED, speed, NULL);
if (ret)
return ret;
mmc_card_set_highspeed(card);
card->host->ios.timing = MMC_TIMING_SD_HS;
card->host->ops->set_ios(card->host, &card->host->ios);
return 0;
}
static int
csr_sdio_disable_hs(struct mmc_card *card)
{
int ret;
u8 speed;
if (!(card->host->caps & MMC_CAP_SD_HIGHSPEED))
return 0;
if (!card->cccr.high_speed)
return 0;
#if 1
ret = csr_io_rw_direct(card, 0, 0, SDIO_CCCR_SPEED, 0, &speed);
if (ret)
return ret;
speed &= ~SDIO_SPEED_EHS;
#else
speed = SDIO_SPEED_SHS;
#endif
ret = csr_io_rw_direct(card, 1, 0, SDIO_CCCR_SPEED, speed, NULL);
if (ret)
return ret;
card->state &= ~MMC_STATE_HIGHSPEED;
card->host->ios.timing = MMC_TIMING_LEGACY;
card->host->ops->set_ios(card->host, &card->host->ios);
return 0;
}
CsrResult
CsrSdioMaxBusClockFrequencySet(CsrSdioFunction *function, u32 maxFrequency)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
struct mmc_host *host = func->card->host;
struct mmc_ios *ios = &host->ios;
unsigned int max_hz;
int err;
u32 max_khz = maxFrequency/1000;
if (!max_khz || max_khz > sdio_clock) {
max_khz = sdio_clock;
}
_sdio_claim_host(func);
max_hz = 1000 * max_khz;
if (max_hz > host->f_max) {
max_hz = host->f_max;
}
if (max_hz > 25000000) {
err = csr_sdio_enable_hs(func->card);
} else {
err = csr_sdio_disable_hs(func->card);
}
if (err) {
printk(KERN_ERR "SDIO warning: Failed to configure SDIO clock mode\n");
_sdio_release_host(func);
return CSR_RESULT_SUCCESS;
}
ios->clock = max_hz;
host->ops->set_ios(host, ios);
_sdio_release_host(func);
return CSR_RESULT_SUCCESS;
}
CsrResult
CsrSdioInterruptEnable(CsrSdioFunction *function)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err = 0;
#ifdef CSR_CONFIG_MMC_INT_BYPASS_KSOFTIRQD
sdio_unblock_card_irq(func);
#else
_sdio_claim_host(func);
#ifdef MMC_QUIRK_LENIENT_FN0
sdio_f0_writeb(func, 0x3, SDIO_CCCR_IENx, &err);
#else
err = csr_io_rw_direct(func->card, 1, 0, SDIO_CCCR_IENx, 0x03, NULL);
#endif
_sdio_release_host(func);
if (err) {
printk(KERN_ERR "unifi: %s: error %d writing IENx\n", __FUNCTION__, err);
return ConvertSdioToCsrSdioResult(err);
}
#endif
return CSR_RESULT_SUCCESS;
}
CsrResult
CsrSdioInterruptDisable(CsrSdioFunction *function)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err = 0;
#ifdef CSR_CONFIG_MMC_INT_BYPASS_KSOFTIRQD
sdio_block_card_irq(func);
#else
_sdio_claim_host(func);
#ifdef MMC_QUIRK_LENIENT_FN0
sdio_f0_writeb(func, 0, SDIO_CCCR_IENx, &err);
#else
err = csr_io_rw_direct(func->card, 1, 0, SDIO_CCCR_IENx, 0x00, NULL);
#endif
_sdio_release_host(func);
if (err) {
printk(KERN_ERR "unifi: %s: error %d writing IENx\n", __FUNCTION__, err);
return ConvertSdioToCsrSdioResult(err);
}
#endif
return CSR_RESULT_SUCCESS;
}
void CsrSdioInterruptAcknowledge(CsrSdioFunction *function)
{
}
CsrResult
CsrSdioFunctionEnable(CsrSdioFunction *function)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err;
_sdio_claim_host(func);
err = sdio_enable_func(func);
_sdio_release_host(func);
if (err) {
unifi_error(NULL, "Failed to enable SDIO function %d\n", func->num);
}
return ConvertSdioToCsrSdioResult(err);
}
CsrResult
CsrSdioFunctionDisable(CsrSdioFunction *function)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int err;
_sdio_claim_host(func);
err = sdio_disable_func(func);
_sdio_release_host(func);
if (err) {
unifi_error(NULL, "Failed to disable SDIO function %d\n", func->num);
}
return ConvertSdioToCsrSdioResult(err);
}
void
CsrSdioFunctionActive(CsrSdioFunction *function)
{
}
void
CsrSdioFunctionIdle(CsrSdioFunction *function)
{
}
CsrResult
CsrSdioPowerOn(CsrSdioFunction *function)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
struct mmc_host *host = func->card->host;
_sdio_claim_host(func);
if (!card_is_powered) {
mmc_power_restore_host(host);
card_is_powered = 1;
} else {
printk(KERN_INFO "SDIO: Skip power on; card is already powered.\n");
}
_sdio_release_host(func);
return CSR_RESULT_SUCCESS;
}
void
CsrSdioPowerOff(CsrSdioFunction *function)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
struct mmc_host *host = func->card->host;
_sdio_claim_host(func);
if (card_is_powered) {
mmc_power_save_host(host);
card_is_powered = 0;
} else {
printk(KERN_INFO "SDIO: Skip power off; card is already powered off.\n");
}
_sdio_release_host(func);
}
static int
sdio_set_block_size_ignore_first_error(struct sdio_func *func, unsigned blksz)
{
int ret;
if (blksz > func->card->host->max_blk_size)
return -EINVAL;
if (blksz == 0) {
blksz = min(func->max_blksize, func->card->host->max_blk_size);
blksz = min(blksz, 512u);
}
ret = csr_io_rw_direct(func->card, 1, 0,
SDIO_FBR_BASE(func->num) + SDIO_FBR_BLKSIZE,
blksz & 0xff, NULL);
if (ret && ret != -ERANGE)
return ret;
ret = csr_io_rw_direct(func->card, 1, 0,
SDIO_FBR_BASE(func->num) + SDIO_FBR_BLKSIZE + 1,
(blksz >> 8) & 0xff, NULL);
if (ret)
return ret;
func->cur_blksize = blksz;
return 0;
}
CsrResult
CsrSdioBlockSizeSet(CsrSdioFunction *function, u16 blockSize)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int r = 0;
if (sdio_block_size > -1) {
blockSize = sdio_block_size;
}
unifi_trace(NULL, UDBG1, "Set SDIO function block size to %d\n",
blockSize);
_sdio_claim_host(func);
r = sdio_set_block_size(func, blockSize);
_sdio_release_host(func);
if (r == -ERANGE) {
_sdio_claim_host(func);
r = sdio_set_block_size_ignore_first_error(func, blockSize);
_sdio_release_host(func);
}
if (r) {
unifi_error(NULL, "Error %d setting block size\n", r);
}
function->blockSize = func->cur_blksize;
return ConvertSdioToCsrSdioResult(r);
}
CsrResult
CsrSdioHardReset(CsrSdioFunction *function)
{
return CSR_RESULT_FAILURE;
}
static void
uf_glue_sdio_int_handler(struct sdio_func *func)
{
CsrSdioFunction *sdio_ctx;
CsrSdioInterruptDsrCallback func_dsr_callback;
int r;
sdio_ctx = sdio_get_drvdata(func);
if (!sdio_ctx) {
return;
}
#ifndef CSR_CONFIG_MMC_INT_BYPASS_KSOFTIRQD
#ifdef MMC_QUIRK_LENIENT_FN0
sdio_f0_writeb(func, 0, SDIO_CCCR_IENx, &r);
#else
r = csr_io_rw_direct(func->card, 1, 0, SDIO_CCCR_IENx, 0x00, NULL);
#endif
if (r) {
printk(KERN_ERR "UniFi MMC Int handler: Failed to disable interrupts %d\n", r);
}
#endif
if (sdio_func_drv && sdio_func_drv->intr) {
func_dsr_callback = sdio_func_drv->intr(sdio_ctx);
if (func_dsr_callback) {
func_dsr_callback(sdio_ctx);
}
}
}
int csr_sdio_linux_remove_irq(CsrSdioFunction *function)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int r;
unifi_trace(NULL, UDBG1, "csr_sdio_linux_remove_irq\n");
sdio_claim_host(func);
r = sdio_release_irq(func);
sdio_release_host(func);
return r;
}
int csr_sdio_linux_install_irq(CsrSdioFunction *function)
{
struct sdio_func *func = (struct sdio_func *)function->priv;
int r;
unifi_trace(NULL, UDBG1, "csr_sdio_linux_install_irq\n");
sdio_claim_host(func);
r = sdio_claim_irq(func, uf_glue_sdio_int_handler);
sdio_release_host(func);
if (r == -EBUSY)
r = 0;
return r;
}
static struct uf_sdio_mmc_pm_notifier *
uf_sdio_mmc_register_pm_notifier(CsrSdioFunction *sdio_ctx)
{
struct uf_sdio_mmc_pm_notifier *notifier_ctx = kmalloc(sizeof(struct uf_sdio_mmc_pm_notifier), GFP_KERNEL);
if (notifier_ctx)
{
notifier_ctx->sdio_ctx = sdio_ctx;
notifier_ctx->pm_notifier.notifier_call = uf_sdio_mmc_power_event;
list_add(&notifier_ctx->list, &uf_sdio_mmc_pm_notifiers.list);
if (register_pm_notifier(&notifier_ctx->pm_notifier)) {
printk(KERN_ERR "unifi: register_pm_notifier failed\n");
}
}
return notifier_ctx;
}
static void
uf_sdio_mmc_unregister_pm_notifier(CsrSdioFunction *sdio_ctx)
{
struct uf_sdio_mmc_pm_notifier *notifier_ctx;
struct list_head *node, *q;
list_for_each_safe(node, q, &uf_sdio_mmc_pm_notifiers.list) {
notifier_ctx = list_entry(node, struct uf_sdio_mmc_pm_notifier, list);
if (notifier_ctx && notifier_ctx->sdio_ctx == sdio_ctx)
{
if (unregister_pm_notifier(&notifier_ctx->pm_notifier)) {
printk(KERN_ERR "unifi: unregister_pm_notifier failed\n");
}
notifier_ctx->sdio_ctx = NULL;
list_del(node);
kfree(notifier_ctx);
}
}
}
static int
uf_sdio_mmc_power_event(struct notifier_block *this, unsigned long event, void *ptr)
{
struct uf_sdio_mmc_pm_notifier *notifier_ctx = container_of(this,
struct uf_sdio_mmc_pm_notifier,
pm_notifier);
switch (event) {
case PM_POST_HIBERNATION:
case PM_POST_SUSPEND:
printk(KERN_INFO "%s:%d resume\n", __FUNCTION__, __LINE__ );
if (sdio_func_drv && sdio_func_drv->resume) {
sdio_func_drv->resume(notifier_ctx->sdio_ctx);
}
break;
case PM_HIBERNATION_PREPARE:
case PM_SUSPEND_PREPARE:
printk(KERN_INFO "%s:%d suspend\n", __FUNCTION__, __LINE__ );
if (sdio_func_drv && sdio_func_drv->suspend) {
sdio_func_drv->suspend(notifier_ctx->sdio_ctx);
}
break;
}
return NOTIFY_DONE;
}
static int
uf_glue_sdio_probe(struct sdio_func *func,
const struct sdio_device_id *id)
{
int instance;
CsrSdioFunction *sdio_ctx;
sdio_claim_host(func);
card_is_powered = 1;
instance = func->card->host->index;
printk("sdio bus_id: %16s - UniFi card 0x%X inserted\n",
sdio_func_id(func), instance);
sdio_ctx = kmalloc(sizeof(CsrSdioFunction), GFP_KERNEL);
if (sdio_ctx == NULL) {
sdio_release_host(func);
return -ENOMEM;
}
sdio_ctx->sdioId.manfId = func->vendor;
sdio_ctx->sdioId.cardId = func->device;
sdio_ctx->sdioId.sdioFunction = func->num;
sdio_ctx->sdioId.sdioInterface = func->class;
sdio_ctx->blockSize = func->cur_blksize;
sdio_ctx->priv = (void *)func;
sdio_ctx->features = 0;
if (sdio_byte_mode) {
sdio_ctx->features |= CSR_SDIO_FEATURE_BYTE_MODE;
}
if (func->card->host->caps & MMC_CAP_SD_HIGHSPEED) {
unifi_trace(NULL, UDBG1, "MMC_CAP_SD_HIGHSPEED is available\n");
}
#ifdef MMC_QUIRK_LENIENT_FN0
func->card->quirks |= MMC_QUIRK_LENIENT_FN0;
#endif
sdio_set_drvdata(func, sdio_ctx);
#ifdef CONFIG_PM
if (uf_sdio_mmc_register_pm_notifier(sdio_ctx) == NULL) {
unifi_error(NULL, "%s: Failed to register for PM events\n", __FUNCTION__);
}
#endif
if (sdio_func_drv && sdio_func_drv->inserted) {
uf_add_os_device(instance, &func->dev);
sdio_func_drv->inserted(sdio_ctx);
}
sdio_release_host(func);
#ifdef ANDROID_BUILD
unifi_trace(NULL, UDBG1, "probe: take wake lock\n");
wake_lock(&unifi_sdio_wake_lock);
#endif
return 0;
}
static void
uf_glue_sdio_remove(struct sdio_func *func)
{
CsrSdioFunction *sdio_ctx;
sdio_ctx = sdio_get_drvdata(func);
if (!sdio_ctx) {
return;
}
unifi_info(NULL, "UniFi card removed\n");
if (sdio_func_drv && sdio_func_drv->removed) {
uf_remove_os_device(func->card->host->index);
sdio_func_drv->removed(sdio_ctx);
}
#ifdef CONFIG_PM
uf_sdio_mmc_unregister_pm_notifier(sdio_ctx);
#endif
kfree(sdio_ctx);
}
static int
uf_glue_sdio_suspend(struct device *dev)
{
unifi_trace(NULL, UDBG1, "uf_glue_sdio_suspend");
return 0;
}
static int
uf_glue_sdio_resume(struct device *dev)
{
unifi_trace(NULL, UDBG1, "uf_glue_sdio_resume");
#ifdef ANDROID_BUILD
unifi_trace(NULL, UDBG1, "resume: take wakelock\n");
wake_lock(&unifi_sdio_wake_lock);
#endif
return 0;
}
CsrResult
CsrSdioFunctionDriverRegister(CsrSdioFunctionDriver *sdio_drv)
{
int r;
printk("UniFi: Using native Linux MMC driver for SDIO.\n");
if (sdio_func_drv) {
unifi_error(NULL, "sdio_mmc: UniFi driver already registered\n");
return CSR_SDIO_RESULT_INVALID_VALUE;
}
#ifdef ANDROID_BUILD
wake_lock_init(&unifi_sdio_wake_lock, WAKE_LOCK_SUSPEND, "unifi_sdio_work");
#endif
sdio_func_drv = sdio_drv;
#ifdef CONFIG_PM
INIT_LIST_HEAD(&uf_sdio_mmc_pm_notifiers.list);
#endif
r = sdio_register_driver(&unifi_driver);
if (r) {
printk(KERN_ERR "unifi_sdio: Failed to register UniFi SDIO driver: %d\n", r);
return ConvertSdioToCsrSdioResult(r);
}
return CSR_RESULT_SUCCESS;
}
void
CsrSdioFunctionDriverUnregister(CsrSdioFunctionDriver *sdio_drv)
{
printk(KERN_INFO "UniFi: unregister from MMC sdio\n");
#ifdef ANDROID_BUILD
wake_lock_destroy(&unifi_sdio_wake_lock);
#endif
sdio_unregister_driver(&unifi_driver);
sdio_func_drv = NULL;
}
