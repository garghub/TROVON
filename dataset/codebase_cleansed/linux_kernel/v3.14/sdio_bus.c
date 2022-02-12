static ssize_t modalias_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sdio_func *func = dev_to_sdio_func (dev);
return sprintf(buf, "sdio:c%02Xv%04Xd%04X\n",
func->class, func->vendor, func->device);
}
static const struct sdio_device_id *sdio_match_one(struct sdio_func *func,
const struct sdio_device_id *id)
{
if (id->class != (__u8)SDIO_ANY_ID && id->class != func->class)
return NULL;
if (id->vendor != (__u16)SDIO_ANY_ID && id->vendor != func->vendor)
return NULL;
if (id->device != (__u16)SDIO_ANY_ID && id->device != func->device)
return NULL;
return id;
}
static const struct sdio_device_id *sdio_match_device(struct sdio_func *func,
struct sdio_driver *sdrv)
{
const struct sdio_device_id *ids;
ids = sdrv->id_table;
if (ids) {
while (ids->class || ids->vendor || ids->device) {
if (sdio_match_one(func, ids))
return ids;
ids++;
}
}
return NULL;
}
static int sdio_bus_match(struct device *dev, struct device_driver *drv)
{
struct sdio_func *func = dev_to_sdio_func(dev);
struct sdio_driver *sdrv = to_sdio_driver(drv);
if (sdio_match_device(func, sdrv))
return 1;
return 0;
}
static int
sdio_bus_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct sdio_func *func = dev_to_sdio_func(dev);
if (add_uevent_var(env,
"SDIO_CLASS=%02X", func->class))
return -ENOMEM;
if (add_uevent_var(env,
"SDIO_ID=%04X:%04X", func->vendor, func->device))
return -ENOMEM;
if (add_uevent_var(env,
"MODALIAS=sdio:c%02Xv%04Xd%04X",
func->class, func->vendor, func->device))
return -ENOMEM;
return 0;
}
static int sdio_bus_probe(struct device *dev)
{
struct sdio_driver *drv = to_sdio_driver(dev->driver);
struct sdio_func *func = dev_to_sdio_func(dev);
const struct sdio_device_id *id;
int ret;
id = sdio_match_device(func, drv);
if (!id)
return -ENODEV;
if (func->card->host->caps & MMC_CAP_POWER_OFF_CARD) {
ret = pm_runtime_get_sync(dev);
if (ret < 0)
goto disable_runtimepm;
}
sdio_claim_host(func);
ret = sdio_set_block_size(func, 0);
sdio_release_host(func);
if (ret)
goto disable_runtimepm;
ret = drv->probe(func, id);
if (ret)
goto disable_runtimepm;
return 0;
disable_runtimepm:
if (func->card->host->caps & MMC_CAP_POWER_OFF_CARD)
pm_runtime_put_noidle(dev);
return ret;
}
static int sdio_bus_remove(struct device *dev)
{
struct sdio_driver *drv = to_sdio_driver(dev->driver);
struct sdio_func *func = dev_to_sdio_func(dev);
int ret = 0;
if (func->card->host->caps & MMC_CAP_POWER_OFF_CARD)
pm_runtime_get_sync(dev);
drv->remove(func);
if (func->irq_handler) {
pr_warning("WARNING: driver %s did not remove "
"its interrupt handler!\n", drv->name);
sdio_claim_host(func);
sdio_release_irq(func);
sdio_release_host(func);
}
if (func->card->host->caps & MMC_CAP_POWER_OFF_CARD)
pm_runtime_put_noidle(dev);
if (func->card->host->caps & MMC_CAP_POWER_OFF_CARD)
pm_runtime_put_sync(dev);
return ret;
}
static int pm_no_operation(struct device *dev)
{
return 0;
}
int sdio_register_bus(void)
{
return bus_register(&sdio_bus_type);
}
void sdio_unregister_bus(void)
{
bus_unregister(&sdio_bus_type);
}
int sdio_register_driver(struct sdio_driver *drv)
{
drv->drv.name = drv->name;
drv->drv.bus = &sdio_bus_type;
return driver_register(&drv->drv);
}
void sdio_unregister_driver(struct sdio_driver *drv)
{
drv->drv.bus = &sdio_bus_type;
driver_unregister(&drv->drv);
}
static void sdio_release_func(struct device *dev)
{
struct sdio_func *func = dev_to_sdio_func(dev);
sdio_free_func_cis(func);
kfree(func->info);
kfree(func);
}
struct sdio_func *sdio_alloc_func(struct mmc_card *card)
{
struct sdio_func *func;
func = kzalloc(sizeof(struct sdio_func), GFP_KERNEL);
if (!func)
return ERR_PTR(-ENOMEM);
func->card = card;
device_initialize(&func->dev);
func->dev.parent = &card->dev;
func->dev.bus = &sdio_bus_type;
func->dev.release = sdio_release_func;
return func;
}
static void sdio_acpi_set_handle(struct sdio_func *func)
{
struct mmc_host *host = func->card->host;
u64 addr = (host->slotno << 16) | func->num;
acpi_preset_companion(&func->dev, ACPI_COMPANION(host->parent), addr);
}
static inline void sdio_acpi_set_handle(struct sdio_func *func) {}
int sdio_add_func(struct sdio_func *func)
{
int ret;
dev_set_name(&func->dev, "%s:%d", mmc_card_id(func->card), func->num);
sdio_acpi_set_handle(func);
ret = device_add(&func->dev);
if (ret == 0) {
sdio_func_set_present(func);
acpi_dev_pm_attach(&func->dev, false);
}
return ret;
}
void sdio_remove_func(struct sdio_func *func)
{
if (!sdio_func_present(func))
return;
acpi_dev_pm_detach(&func->dev, false);
device_del(&func->dev);
put_device(&func->dev);
}
