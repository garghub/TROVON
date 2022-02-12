static int bcmsdh_sdmmc_probe(struct sdio_func *func,
const struct sdio_device_id *id)
{
int ret = 0;
static struct sdio_func sdio_func_0;
sd_trace(("bcmsdh_sdmmc: %s Enter\n", __func__));
sd_trace(("sdio_bcmsdh: func->class=%x\n", func->class));
sd_trace(("sdio_vendor: 0x%04x\n", func->vendor));
sd_trace(("sdio_device: 0x%04x\n", func->device));
sd_trace(("Function#: 0x%04x\n", func->num));
if (func->num == 1) {
sdio_func_0.num = 0;
sdio_func_0.card = func->card;
gInstance->func[0] = &sdio_func_0;
if (func->device == 0x4) {
gInstance->func[2] = NULL;
sd_trace(("NIC found, calling bcmsdh_probe...\n"));
ret = bcmsdh_probe(&sdmmc_dev);
}
}
gInstance->func[func->num] = func;
if (func->num == 2) {
wl_cfg80211_sdio_func(func);
sd_trace(("F2 found, calling bcmsdh_probe...\n"));
ret = bcmsdh_probe(&sdmmc_dev);
}
return ret;
}
static void bcmsdh_sdmmc_remove(struct sdio_func *func)
{
sd_trace(("bcmsdh_sdmmc: %s Enter\n", __func__));
sd_info(("sdio_bcmsdh: func->class=%x\n", func->class));
sd_info(("sdio_vendor: 0x%04x\n", func->vendor));
sd_info(("sdio_device: 0x%04x\n", func->device));
sd_info(("Function#: 0x%04x\n", func->num));
if (func->num == 2) {
sd_trace(("F2 found, calling bcmsdh_remove...\n"));
bcmsdh_remove(&sdmmc_dev);
}
}
int sdioh_sdmmc_osinit(sdioh_info_t *sd)
{
struct sdos_info *sdos;
sdos = kmalloc(sizeof(struct sdos_info), GFP_ATOMIC);
sd->sdos_info = (void *)sdos;
if (sdos == NULL)
return -ENOMEM;
sdos->sd = sd;
spin_lock_init(&sdos->lock);
return 0;
}
void sdioh_sdmmc_osfree(sdioh_info_t *sd)
{
struct sdos_info *sdos;
ASSERT(sd && sd->sdos_info);
sdos = (struct sdos_info *)sd->sdos_info;
kfree(sdos);
}
SDIOH_API_RC sdioh_interrupt_set(sdioh_info_t *sd, bool enable)
{
unsigned long flags;
struct sdos_info *sdos;
sd_trace(("%s: %s\n", __func__, enable ? "Enabling" : "Disabling"));
sdos = (struct sdos_info *)sd->sdos_info;
ASSERT(sdos);
#if !defined(OOB_INTR_ONLY)
if (enable && !(sd->intr_handler && sd->intr_handler_arg)) {
sd_err(("%s: no handler registered, will not enable\n",
__func__));
return SDIOH_API_RC_FAIL;
}
#endif
spin_lock_irqsave(&sdos->lock, flags);
sd->client_intr_enabled = enable;
if (enable)
sdioh_sdmmc_devintr_on(sd);
else
sdioh_sdmmc_devintr_off(sd);
spin_unlock_irqrestore(&sdos->lock, flags);
return SDIOH_API_RC_SUCCESS;
}
int sdio_function_init(void)
{
int error = 0;
sd_trace(("bcmsdh_sdmmc: %s Enter\n", __func__));
gInstance = kzalloc(sizeof(BCMSDH_SDMMC_INSTANCE), GFP_KERNEL);
if (!gInstance)
return -ENOMEM;
memset(&sdmmc_dev, 0, sizeof(sdmmc_dev));
error = sdio_register_driver(&bcmsdh_sdmmc_driver);
return error;
}
void sdio_function_cleanup(void)
{
sd_trace(("%s Enter\n", __func__));
sdio_unregister_driver(&bcmsdh_sdmmc_driver);
kfree(gInstance);
}
