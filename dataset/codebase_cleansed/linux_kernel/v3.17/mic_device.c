static void mic_notify_host(u8 state)
{
struct mic_driver *mdrv = g_drv;
struct mic_bootparam __iomem *bootparam = mdrv->dp;
iowrite8(state, &bootparam->shutdown_status);
dev_dbg(mdrv->dev, "%s %d system_state %d\n",
__func__, __LINE__, state);
mic_send_intr(&mdrv->mdev, ioread8(&bootparam->c2h_shutdown_db));
}
static int mic_panic_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
struct mic_driver *mdrv = g_drv;
struct mic_bootparam __iomem *bootparam = mdrv->dp;
iowrite8(-1, &bootparam->h2c_config_db);
iowrite8(-1, &bootparam->h2c_shutdown_db);
mic_notify_host(MIC_CRASHED);
return NOTIFY_DONE;
}
static irqreturn_t mic_shutdown_isr(int irq, void *data)
{
struct mic_driver *mdrv = g_drv;
struct mic_bootparam __iomem *bootparam = mdrv->dp;
mic_ack_interrupt(&g_drv->mdev);
if (ioread8(&bootparam->shutdown_card))
orderly_poweroff(true);
return IRQ_HANDLED;
}
static int mic_shutdown_init(void)
{
int rc = 0;
struct mic_driver *mdrv = g_drv;
struct mic_bootparam __iomem *bootparam = mdrv->dp;
int shutdown_db;
shutdown_db = mic_next_card_db();
shutdown_cookie = mic_request_card_irq(mic_shutdown_isr, NULL,
"Shutdown", mdrv, shutdown_db);
if (IS_ERR(shutdown_cookie))
rc = PTR_ERR(shutdown_cookie);
else
iowrite8(shutdown_db, &bootparam->h2c_shutdown_db);
return rc;
}
static void mic_shutdown_uninit(void)
{
struct mic_driver *mdrv = g_drv;
struct mic_bootparam __iomem *bootparam = mdrv->dp;
iowrite8(-1, &bootparam->h2c_shutdown_db);
mic_free_card_irq(shutdown_cookie, mdrv);
}
static int __init mic_dp_init(void)
{
struct mic_driver *mdrv = g_drv;
struct mic_device *mdev = &mdrv->mdev;
struct mic_bootparam __iomem *bootparam;
u64 lo, hi, dp_dma_addr;
u32 magic;
lo = mic_read_spad(&mdrv->mdev, MIC_DPLO_SPAD);
hi = mic_read_spad(&mdrv->mdev, MIC_DPHI_SPAD);
dp_dma_addr = lo | (hi << 32);
mdrv->dp = mic_card_map(mdev, dp_dma_addr, MIC_DP_SIZE);
if (!mdrv->dp) {
dev_err(mdrv->dev, "Cannot remap Aperture BAR\n");
return -ENOMEM;
}
bootparam = mdrv->dp;
magic = ioread32(&bootparam->magic);
if (MIC_MAGIC != magic) {
dev_err(mdrv->dev, "bootparam magic mismatch 0x%x\n", magic);
return -EIO;
}
return 0;
}
static void mic_dp_uninit(void)
{
mic_card_unmap(&g_drv->mdev, g_drv->dp);
}
struct mic_irq *
mic_request_card_irq(irq_handler_t handler,
irq_handler_t thread_fn, const char *name,
void *data, int index)
{
int rc = 0;
unsigned long cookie;
struct mic_driver *mdrv = g_drv;
rc = request_threaded_irq(mic_db_to_irq(mdrv, index), handler,
thread_fn, 0, name, data);
if (rc) {
dev_err(mdrv->dev, "request_threaded_irq failed rc = %d\n", rc);
goto err;
}
mdrv->irq_info.irq_usage_count[index]++;
cookie = index;
return (struct mic_irq *)cookie;
err:
return ERR_PTR(rc);
}
void mic_free_card_irq(struct mic_irq *cookie, void *data)
{
int index;
struct mic_driver *mdrv = g_drv;
index = (unsigned long)cookie & 0xFFFFU;
free_irq(mic_db_to_irq(mdrv, index), data);
mdrv->irq_info.irq_usage_count[index]--;
}
int mic_next_card_db(void)
{
int i;
int index = 0;
struct mic_driver *mdrv = g_drv;
for (i = 0; i < mdrv->intr_info.num_intr; i++) {
if (mdrv->irq_info.irq_usage_count[i] <
mdrv->irq_info.irq_usage_count[index])
index = i;
}
return index;
}
static int mic_init_irq(void)
{
struct mic_driver *mdrv = g_drv;
mdrv->irq_info.irq_usage_count = kzalloc((sizeof(u32) *
mdrv->intr_info.num_intr),
GFP_KERNEL);
if (!mdrv->irq_info.irq_usage_count)
return -ENOMEM;
return 0;
}
static void mic_uninit_irq(void)
{
struct mic_driver *mdrv = g_drv;
kfree(mdrv->irq_info.irq_usage_count);
}
int __init mic_driver_init(struct mic_driver *mdrv)
{
int rc;
g_drv = mdrv;
if (!try_module_get(mdrv->dev->driver->owner)) {
rc = -ENODEV;
goto done;
}
rc = mic_dp_init();
if (rc)
goto put;
rc = mic_init_irq();
if (rc)
goto dp_uninit;
rc = mic_shutdown_init();
if (rc)
goto irq_uninit;
rc = mic_devices_init(mdrv);
if (rc)
goto shutdown_uninit;
mic_create_card_debug_dir(mdrv);
atomic_notifier_chain_register(&panic_notifier_list, &mic_panic);
done:
return rc;
shutdown_uninit:
mic_shutdown_uninit();
irq_uninit:
mic_uninit_irq();
dp_uninit:
mic_dp_uninit();
put:
module_put(mdrv->dev->driver->owner);
return rc;
}
void mic_driver_uninit(struct mic_driver *mdrv)
{
mic_delete_card_debug_dir(mdrv);
mic_devices_uninit(mdrv);
mic_notify_host(system_state);
mic_shutdown_uninit();
mic_uninit_irq();
mic_dp_uninit();
module_put(mdrv->dev->driver->owner);
}
