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
static void mic_x100_send_sbox_intr(struct mic_mw *mw, int doorbell)
{
u64 apic_icr_offset = MIC_X100_SBOX_APICICR0 + doorbell * 8;
u32 apicicr_low = mic_mmio_read(mw, MIC_X100_SBOX_BASE_ADDRESS +
apic_icr_offset);
apicicr_low = (apicicr_low | (1 << 13));
wmb();
mic_mmio_write(mw, apicicr_low,
MIC_X100_SBOX_BASE_ADDRESS + apic_icr_offset);
}
static void mic_x100_send_rdmasr_intr(struct mic_mw *mw, int doorbell)
{
int rdmasr_offset = MIC_X100_SBOX_RDMASR0 + (doorbell << 2);
wmb();
mic_mmio_write(mw, 0, MIC_X100_SBOX_BASE_ADDRESS + rdmasr_offset);
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
void mic_send_p2p_intr(int db, struct mic_mw *mw)
{
int rdmasr_index;
if (db < MIC_X100_NUM_SBOX_IRQ) {
mic_x100_send_sbox_intr(mw, db);
} else {
rdmasr_index = db - MIC_X100_NUM_SBOX_IRQ;
mic_x100_send_rdmasr_intr(mw, rdmasr_index);
}
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
rdmasr_index = db - MIC_X100_NUM_SBOX_IRQ;
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
static inline struct mic_driver *mbdev_to_mdrv(struct mbus_device *mbdev)
{
return dev_get_drvdata(mbdev->dev.parent);
}
static struct mic_irq *
_mic_request_threaded_irq(struct mbus_device *mbdev,
irq_handler_t handler, irq_handler_t thread_fn,
const char *name, void *data, int intr_src)
{
int rc = 0;
unsigned int irq = intr_src;
unsigned long cookie = irq;
rc = request_threaded_irq(irq, handler, thread_fn, 0, name, data);
if (rc) {
dev_err(mbdev_to_mdrv(mbdev)->dev,
"request_threaded_irq failed rc = %d\n", rc);
return ERR_PTR(rc);
}
return (struct mic_irq *)cookie;
}
static void _mic_free_irq(struct mbus_device *mbdev,
struct mic_irq *cookie, void *data)
{
unsigned long irq = (unsigned long)cookie;
free_irq(irq, data);
}
static void _mic_ack_interrupt(struct mbus_device *mbdev, int num)
{
mic_ack_interrupt(&mbdev_to_mdrv(mbdev)->mdev);
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
mdev->mmio.va = devm_ioremap(&pdev->dev, MIC_X100_MMIO_BASE,
MIC_X100_MMIO_LEN);
if (!mdev->mmio.va) {
dev_err(&pdev->dev, "Cannot remap MMIO BAR\n");
rc = -EIO;
goto done;
}
mic_hw_intr_init(mdrv);
platform_set_drvdata(pdev, mdrv);
mdrv->dma_mbdev = mbus_register_device(mdrv->dev, MBUS_DEV_DMA_MIC,
NULL, &mbus_hw_ops, 0,
mdrv->mdev.mmio.va);
if (IS_ERR(mdrv->dma_mbdev)) {
rc = PTR_ERR(mdrv->dma_mbdev);
dev_err(&pdev->dev, "mbus_add_device failed rc %d\n", rc);
goto done;
}
rc = mic_driver_init(mdrv);
if (rc) {
dev_err(&pdev->dev, "mic_driver_init failed rc %d\n", rc);
goto remove_dma;
}
done:
return rc;
remove_dma:
mbus_unregister_device(mdrv->dma_mbdev);
return rc;
}
static int mic_remove(struct platform_device *pdev)
{
struct mic_driver *mdrv = &g_drv;
mic_driver_uninit(mdrv);
mbus_unregister_device(mdrv->dma_mbdev);
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
