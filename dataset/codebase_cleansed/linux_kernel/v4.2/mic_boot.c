static inline struct mic_device *scdev_to_mdev(struct scif_hw_dev *scdev)
{
return dev_get_drvdata(scdev->dev.parent);
}
static void *__mic_dma_alloc(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t gfp,
struct dma_attrs *attrs)
{
struct scif_hw_dev *scdev = dev_get_drvdata(dev);
struct mic_device *mdev = scdev_to_mdev(scdev);
dma_addr_t tmp;
void *va = kmalloc(size, gfp);
if (va) {
tmp = mic_map_single(mdev, va, size);
if (dma_mapping_error(dev, tmp)) {
kfree(va);
va = NULL;
} else {
*dma_handle = tmp;
}
}
return va;
}
static void __mic_dma_free(struct device *dev, size_t size, void *vaddr,
dma_addr_t dma_handle, struct dma_attrs *attrs)
{
struct scif_hw_dev *scdev = dev_get_drvdata(dev);
struct mic_device *mdev = scdev_to_mdev(scdev);
mic_unmap_single(mdev, dma_handle, size);
kfree(vaddr);
}
static dma_addr_t
__mic_dma_map_page(struct device *dev, struct page *page, unsigned long offset,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
void *va = phys_to_virt(page_to_phys(page)) + offset;
struct scif_hw_dev *scdev = dev_get_drvdata(dev);
struct mic_device *mdev = scdev_to_mdev(scdev);
return mic_map_single(mdev, va, size);
}
static void
__mic_dma_unmap_page(struct device *dev, dma_addr_t dma_addr,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct scif_hw_dev *scdev = dev_get_drvdata(dev);
struct mic_device *mdev = scdev_to_mdev(scdev);
mic_unmap_single(mdev, dma_addr, size);
}
static int __mic_dma_map_sg(struct device *dev, struct scatterlist *sg,
int nents, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct scif_hw_dev *scdev = dev_get_drvdata(dev);
struct mic_device *mdev = scdev_to_mdev(scdev);
struct scatterlist *s;
int i, j, ret;
dma_addr_t da;
ret = dma_map_sg(mdev->sdev->parent, sg, nents, dir);
if (ret <= 0)
return 0;
for_each_sg(sg, s, nents, i) {
da = mic_map(mdev, sg_dma_address(s) + s->offset, s->length);
if (!da)
goto err;
sg_dma_address(s) = da;
}
return nents;
err:
for_each_sg(sg, s, i, j) {
mic_unmap(mdev, sg_dma_address(s), s->length);
sg_dma_address(s) = mic_to_dma_addr(mdev, sg_dma_address(s));
}
dma_unmap_sg(mdev->sdev->parent, sg, nents, dir);
return 0;
}
static void __mic_dma_unmap_sg(struct device *dev,
struct scatterlist *sg, int nents,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct scif_hw_dev *scdev = dev_get_drvdata(dev);
struct mic_device *mdev = scdev_to_mdev(scdev);
struct scatterlist *s;
dma_addr_t da;
int i;
for_each_sg(sg, s, nents, i) {
da = mic_to_dma_addr(mdev, sg_dma_address(s));
mic_unmap(mdev, sg_dma_address(s), s->length);
sg_dma_address(s) = da;
}
dma_unmap_sg(mdev->sdev->parent, sg, nents, dir);
}
static struct mic_irq *
___mic_request_irq(struct scif_hw_dev *scdev,
irqreturn_t (*func)(int irq, void *data),
const char *name,
void *data, int db)
{
struct mic_device *mdev = scdev_to_mdev(scdev);
return mic_request_threaded_irq(mdev, func, NULL, name, data,
db, MIC_INTR_DB);
}
static void
___mic_free_irq(struct scif_hw_dev *scdev,
struct mic_irq *cookie, void *data)
{
struct mic_device *mdev = scdev_to_mdev(scdev);
return mic_free_irq(mdev, cookie, data);
}
static void ___mic_ack_interrupt(struct scif_hw_dev *scdev, int num)
{
struct mic_device *mdev = scdev_to_mdev(scdev);
mdev->ops->intr_workarounds(mdev);
}
static int ___mic_next_db(struct scif_hw_dev *scdev)
{
struct mic_device *mdev = scdev_to_mdev(scdev);
return mic_next_db(mdev);
}
static void ___mic_send_intr(struct scif_hw_dev *scdev, int db)
{
struct mic_device *mdev = scdev_to_mdev(scdev);
mdev->ops->send_intr(mdev, db);
}
static void __iomem *___mic_ioremap(struct scif_hw_dev *scdev,
phys_addr_t pa, size_t len)
{
struct mic_device *mdev = scdev_to_mdev(scdev);
return mdev->aper.va + pa;
}
static void ___mic_iounmap(struct scif_hw_dev *scdev, void __iomem *va)
{
}
static inline struct mic_device *mbdev_to_mdev(struct mbus_device *mbdev)
{
return dev_get_drvdata(mbdev->dev.parent);
}
static dma_addr_t
mic_dma_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
void *va = phys_to_virt(page_to_phys(page)) + offset;
struct mic_device *mdev = dev_get_drvdata(dev->parent);
return mic_map_single(mdev, va, size);
}
static void
mic_dma_unmap_page(struct device *dev, dma_addr_t dma_addr,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct mic_device *mdev = dev_get_drvdata(dev->parent);
mic_unmap_single(mdev, dma_addr, size);
}
static struct mic_irq *
_mic_request_threaded_irq(struct mbus_device *mbdev,
irq_handler_t handler, irq_handler_t thread_fn,
const char *name, void *data, int intr_src)
{
return mic_request_threaded_irq(mbdev_to_mdev(mbdev), handler,
thread_fn, name, data,
intr_src, MIC_INTR_DMA);
}
static void _mic_free_irq(struct mbus_device *mbdev,
struct mic_irq *cookie, void *data)
{
return mic_free_irq(mbdev_to_mdev(mbdev), cookie, data);
}
static void _mic_ack_interrupt(struct mbus_device *mbdev, int num)
{
struct mic_device *mdev = mbdev_to_mdev(mbdev);
mdev->ops->intr_workarounds(mdev);
}
static void mic_reset(struct mic_device *mdev)
{
int i;
#define MIC_RESET_TO (45)
reinit_completion(&mdev->reset_wait);
mdev->ops->reset_fw_ready(mdev);
mdev->ops->reset(mdev);
for (i = 0; i < MIC_RESET_TO; i++) {
if (mdev->ops->is_fw_ready(mdev))
goto done;
msleep(1000);
}
mic_set_state(mdev, MIC_RESET_FAILED);
done:
complete_all(&mdev->reset_wait);
}
void mic_bootparam_init(struct mic_device *mdev)
{
struct mic_bootparam *bootparam = mdev->dp;
bootparam->magic = cpu_to_le32(MIC_MAGIC);
bootparam->c2h_shutdown_db = mdev->shutdown_db;
bootparam->h2c_shutdown_db = -1;
bootparam->h2c_config_db = -1;
bootparam->shutdown_status = 0;
bootparam->shutdown_card = 0;
bootparam->tot_nodes = atomic_read(&g_num_mics) + 1;
bootparam->node_id = mdev->id + 1;
bootparam->scif_host_dma_addr = 0x0;
bootparam->scif_card_dma_addr = 0x0;
bootparam->c2h_scif_db = -1;
bootparam->h2c_scif_db = -1;
}
static int mic_request_dma_chans(struct mic_device *mdev)
{
dma_cap_mask_t mask;
struct dma_chan *chan;
request_module("mic_x100_dma");
dma_cap_zero(mask);
dma_cap_set(DMA_MEMCPY, mask);
do {
chan = dma_request_channel(mask, mdev->ops->dma_filter,
mdev->sdev->parent);
if (chan) {
mdev->dma_ch[mdev->num_dma_ch++] = chan;
if (mdev->num_dma_ch >= MIC_MAX_DMA_CHAN)
break;
}
} while (chan);
dev_info(mdev->sdev->parent, "DMA channels # %d\n", mdev->num_dma_ch);
return mdev->num_dma_ch;
}
static void mic_free_dma_chans(struct mic_device *mdev)
{
int i = 0;
for (i = 0; i < mdev->num_dma_ch; i++) {
dma_release_channel(mdev->dma_ch[i]);
mdev->dma_ch[i] = NULL;
}
mdev->num_dma_ch = 0;
}
int mic_start(struct mic_device *mdev, const char *buf)
{
int rc;
mutex_lock(&mdev->mic_mutex);
mic_bootparam_init(mdev);
retry:
if (MIC_OFFLINE != mdev->state) {
rc = -EINVAL;
goto unlock_ret;
}
if (!mdev->ops->is_fw_ready(mdev)) {
mic_reset(mdev);
goto retry;
}
mdev->dma_mbdev = mbus_register_device(mdev->sdev->parent,
MBUS_DEV_DMA_HOST, &mic_dma_ops,
&mbus_hw_ops, mdev->mmio.va);
if (IS_ERR(mdev->dma_mbdev)) {
rc = PTR_ERR(mdev->dma_mbdev);
goto unlock_ret;
}
if (!mic_request_dma_chans(mdev)) {
rc = -ENODEV;
goto dma_remove;
}
mdev->scdev = scif_register_device(mdev->sdev->parent, MIC_SCIF_DEV,
&__mic_dma_ops, &scif_hw_ops,
mdev->id + 1, 0, &mdev->mmio,
&mdev->aper, mdev->dp, NULL,
mdev->dma_ch, mdev->num_dma_ch);
if (IS_ERR(mdev->scdev)) {
rc = PTR_ERR(mdev->scdev);
goto dma_free;
}
rc = mdev->ops->load_mic_fw(mdev, buf);
if (rc)
goto scif_remove;
mic_smpt_restore(mdev);
mic_intr_restore(mdev);
mdev->intr_ops->enable_interrupts(mdev);
mdev->ops->write_spad(mdev, MIC_DPLO_SPAD, mdev->dp_dma_addr);
mdev->ops->write_spad(mdev, MIC_DPHI_SPAD, mdev->dp_dma_addr >> 32);
mdev->ops->send_firmware_intr(mdev);
mic_set_state(mdev, MIC_ONLINE);
goto unlock_ret;
scif_remove:
scif_unregister_device(mdev->scdev);
dma_free:
mic_free_dma_chans(mdev);
dma_remove:
mbus_unregister_device(mdev->dma_mbdev);
unlock_ret:
mutex_unlock(&mdev->mic_mutex);
return rc;
}
void mic_stop(struct mic_device *mdev, bool force)
{
mutex_lock(&mdev->mic_mutex);
if (MIC_OFFLINE != mdev->state || force) {
scif_unregister_device(mdev->scdev);
mic_virtio_reset_devices(mdev);
mic_free_dma_chans(mdev);
mbus_unregister_device(mdev->dma_mbdev);
mic_bootparam_init(mdev);
mic_reset(mdev);
if (MIC_RESET_FAILED == mdev->state)
goto unlock;
mic_set_shutdown_status(mdev, MIC_NOP);
if (MIC_SUSPENDED != mdev->state)
mic_set_state(mdev, MIC_OFFLINE);
}
unlock:
mutex_unlock(&mdev->mic_mutex);
}
void mic_shutdown(struct mic_device *mdev)
{
struct mic_bootparam *bootparam = mdev->dp;
s8 db = bootparam->h2c_shutdown_db;
mutex_lock(&mdev->mic_mutex);
if (MIC_ONLINE == mdev->state && db != -1) {
bootparam->shutdown_card = 1;
mdev->ops->send_intr(mdev, db);
mic_set_state(mdev, MIC_SHUTTING_DOWN);
}
mutex_unlock(&mdev->mic_mutex);
}
void mic_shutdown_work(struct work_struct *work)
{
struct mic_device *mdev = container_of(work, struct mic_device,
shutdown_work);
struct mic_bootparam *bootparam = mdev->dp;
mutex_lock(&mdev->mic_mutex);
mic_set_shutdown_status(mdev, bootparam->shutdown_status);
bootparam->shutdown_status = 0;
if (MIC_SHUTTING_DOWN != mdev->state &&
MIC_SUSPENDED != mdev->state)
mic_set_state(mdev, MIC_SHUTTING_DOWN);
mutex_unlock(&mdev->mic_mutex);
}
void mic_reset_trigger_work(struct work_struct *work)
{
struct mic_device *mdev = container_of(work, struct mic_device,
reset_trigger_work);
mic_stop(mdev, false);
}
void mic_complete_resume(struct mic_device *mdev)
{
if (mdev->state != MIC_SUSPENDED) {
dev_warn(mdev->sdev->parent, "state %d should be %d\n",
mdev->state, MIC_SUSPENDED);
return;
}
if (!mdev->ops->is_fw_ready(mdev))
mic_stop(mdev, true);
mutex_lock(&mdev->mic_mutex);
mic_set_state(mdev, MIC_OFFLINE);
mutex_unlock(&mdev->mic_mutex);
}
void mic_prepare_suspend(struct mic_device *mdev)
{
unsigned long timeout;
#define MIC_SUSPEND_TIMEOUT (60 * HZ)
mutex_lock(&mdev->mic_mutex);
switch (mdev->state) {
case MIC_OFFLINE:
mic_set_state(mdev, MIC_SUSPENDED);
mutex_unlock(&mdev->mic_mutex);
break;
case MIC_ONLINE:
mic_set_state(mdev, MIC_SUSPENDING);
mutex_unlock(&mdev->mic_mutex);
timeout = wait_for_completion_timeout(&mdev->reset_wait,
MIC_SUSPEND_TIMEOUT);
if (!timeout) {
mutex_lock(&mdev->mic_mutex);
mic_set_state(mdev, MIC_SUSPENDED);
mutex_unlock(&mdev->mic_mutex);
mic_stop(mdev, true);
}
break;
case MIC_SHUTTING_DOWN:
mic_set_state(mdev, MIC_SUSPENDED);
mutex_unlock(&mdev->mic_mutex);
timeout = wait_for_completion_timeout(&mdev->reset_wait,
MIC_SUSPEND_TIMEOUT);
if (!timeout)
mic_stop(mdev, true);
break;
default:
mutex_unlock(&mdev->mic_mutex);
break;
}
}
void mic_suspend(struct mic_device *mdev)
{
struct mic_bootparam *bootparam = mdev->dp;
s8 db = bootparam->h2c_shutdown_db;
mutex_lock(&mdev->mic_mutex);
if (MIC_SUSPENDING == mdev->state && db != -1) {
bootparam->shutdown_card = 1;
mdev->ops->send_intr(mdev, db);
mic_set_state(mdev, MIC_SUSPENDED);
}
mutex_unlock(&mdev->mic_mutex);
}
