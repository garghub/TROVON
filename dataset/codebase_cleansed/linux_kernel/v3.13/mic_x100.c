u32 mic_read_spad(struct mic_device *mdev, unsigned int idx)
{
return mic_mmio_read(&mdev->mmio,
MIC_X100_SBOX_BASE_ADDRESS +
MIC_X100_SBOX_SPAD0 + idx * 4);
}
void mic_send_intr(struct mic_device *mdev, int doorbell)
{
struct mic_mw *mw = &mdev->mmio;
if (doorbell > MIC_X100_MAX_DOORBELL_IDX)
return;
wmb();
mic_mmio_write(mw, MIC_X100_SBOX_SDBIC0_DBREQ_BIT,
MIC_X100_SBOX_BASE_ADDRESS +
(MIC_X100_SBOX_SDBIC0 + (4 * doorbell)));
}
u32 mic_ack_interrupt(struct mic_device *mdev)
{
return 0;
}
static inline int mic_get_sbox_irq(int db)
{
return MIC_X100_IRQ_BASE + db;
}
static inline int mic_get_rdmasr_irq(int index)
{
return MIC_X100_RDMASR_IRQ_BASE + index;
}
void mic_hw_intr_init(struct mic_driver *mdrv)
{
mdrv->intr_info.num_intr = MIC_X100_NUM_SBOX_IRQ +
MIC_X100_NUM_RDMASR_IRQ;
}
int mic_db_to_irq(struct mic_driver *mdrv, int db)
{
int rdmasr_index;
if (db < MIC_X100_NUM_SBOX_IRQ) {
return mic_get_sbox_irq(db);
} else {
rdmasr_index = db - MIC_X100_NUM_SBOX_IRQ +
MIC_X100_RDMASR_IRQ_BASE;
return mic_get_rdmasr_irq(rdmasr_index);
}
}
void __iomem *
mic_card_map(struct mic_device *mdev, dma_addr_t addr, size_t size)
{
return ioremap(addr, size);
}
void mic_card_unmap(struct mic_device *mdev, void __iomem *addr)
{
iounmap(addr);
}
static int __init mic_probe(struct platform_device *pdev)
{
struct mic_driver *mdrv = &g_drv;
struct mic_device *mdev = &mdrv->mdev;
int rc = 0;
mdrv->dev = &pdev->dev;
snprintf(mdrv->name, sizeof(mic_driver_name), mic_driver_name);
mdev->mmio.pa = MIC_X100_MMIO_BASE;
mdev->mmio.len = MIC_X100_MMIO_LEN;
mdev->mmio.va = ioremap(MIC_X100_MMIO_BASE, MIC_X100_MMIO_LEN);
if (!mdev->mmio.va) {
dev_err(&pdev->dev, "Cannot remap MMIO BAR\n");
rc = -EIO;
goto done;
}
mic_hw_intr_init(mdrv);
rc = mic_driver_init(mdrv);
if (rc) {
dev_err(&pdev->dev, "mic_driver_init failed rc %d\n", rc);
goto iounmap;
}
done:
return rc;
iounmap:
iounmap(mdev->mmio.va);
return rc;
}
static int mic_remove(struct platform_device *pdev)
{
struct mic_driver *mdrv = &g_drv;
struct mic_device *mdev = &mdrv->mdev;
mic_driver_uninit(mdrv);
iounmap(mdev->mmio.va);
return 0;
}
static void mic_platform_shutdown(struct platform_device *pdev)
{
mic_remove(pdev);
}
static int __init mic_init(void)
{
int ret;
struct cpuinfo_x86 *c = &cpu_data(0);
if (!(c->x86 == 11 && c->x86_model == 1)) {
ret = -ENODEV;
pr_err("%s not running on X100 ret %d\n", __func__, ret);
goto done;
}
mic_init_card_debugfs();
ret = platform_device_register(&mic_platform_dev);
if (ret) {
pr_err("platform_device_register ret %d\n", ret);
goto cleanup_debugfs;
}
ret = platform_driver_register(&mic_platform_driver);
if (ret) {
pr_err("platform_driver_register ret %d\n", ret);
goto device_unregister;
}
return ret;
device_unregister:
platform_device_unregister(&mic_platform_dev);
cleanup_debugfs:
mic_exit_card_debugfs();
done:
return ret;
}
static void __exit mic_exit(void)
{
platform_driver_unregister(&mic_platform_driver);
platform_device_unregister(&mic_platform_dev);
mic_exit_card_debugfs();
}
