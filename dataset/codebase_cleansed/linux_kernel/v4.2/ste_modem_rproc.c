static int sproc_load_segments(struct rproc *rproc, const struct firmware *fw)
{
struct sproc *sproc = rproc->priv;
memcpy(sproc->fw_addr, fw->data, fw->size);
return 0;
}
static const struct ste_toc_entry *sproc_find_rsc_entry(const void *data)
{
int i;
const struct ste_toc *toc = data;
for (i = 0; i < SPROC_MAX_TOC_ENTRIES &&
toc->table[i].start != 0xffffffff; i++) {
if (!strncmp(toc->table[i].name, SPROC_RESOURCE_NAME,
sizeof(toc->table[i].name)))
return &toc->table[i];
}
return NULL;
}
static struct resource_table *
sproc_find_rsc_table(struct rproc *rproc, const struct firmware *fw,
int *tablesz)
{
struct sproc *sproc = rproc->priv;
struct resource_table *table;
const struct ste_toc_entry *entry;
if (!fw)
return NULL;
entry = sproc_find_rsc_entry(fw->data);
if (!entry) {
sproc_err(sproc, "resource table not found in fw\n");
return NULL;
}
table = (void *)(fw->data + entry->start);
if (entry->start > SPROC_FW_SIZE ||
entry->size > SPROC_FW_SIZE ||
fw->size > SPROC_FW_SIZE ||
entry->start + entry->size > fw->size ||
sizeof(struct resource_table) > entry->size) {
sproc_err(sproc, "bad size of fw or resource table\n");
return NULL;
}
if (table->ver != 1) {
sproc_err(sproc, "unsupported fw ver: %d\n", table->ver);
return NULL;
}
if (table->reserved[0] || table->reserved[1]) {
sproc_err(sproc, "non zero reserved bytes\n");
return NULL;
}
if (table->num > SPROC_MAX_TOC_ENTRIES ||
table->num * sizeof(table->offset[0]) +
sizeof(struct resource_table) > entry->size) {
sproc_err(sproc, "resource table incomplete\n");
return NULL;
}
if (SPROC_FW_SIZE < fw->size) {
sproc_err(sproc, "Insufficient space for fw (%d < %zd)\n",
SPROC_FW_SIZE, fw->size);
return NULL;
}
sproc->fw_size = fw->size;
*tablesz = entry->size;
return table;
}
static struct resource_table *
sproc_find_loaded_rsc_table(struct rproc *rproc, const struct firmware *fw)
{
struct sproc *sproc = rproc->priv;
const struct ste_toc_entry *entry;
if (!fw || !sproc->fw_addr)
return NULL;
entry = sproc_find_rsc_entry(sproc->fw_addr);
if (!entry) {
sproc_err(sproc, "resource table not found in fw\n");
return NULL;
}
return sproc->fw_addr + entry->start;
}
static void sproc_kick(struct rproc *rproc, int vqid)
{
struct sproc *sproc = rproc->priv;
sproc_dbg(sproc, "kick vqid:%d\n", vqid);
sproc->mdev->ops.kick(sproc->mdev, vqid + SPROC_MAX_NOTIFY_ID);
}
static void sproc_kick_callback(struct ste_modem_device *mdev, int vqid)
{
struct sproc *sproc = mdev->drv_data;
if (rproc_vq_interrupt(sproc->rproc, vqid) == IRQ_NONE)
sproc_dbg(sproc, "no message was found in vqid %d\n", vqid);
}
static int sproc_start(struct rproc *rproc)
{
struct sproc *sproc = rproc->priv;
int i, err;
sproc_dbg(sproc, "start ste-modem\n");
if (rproc->max_notifyid > SPROC_MAX_NOTIFY_ID) {
sproc_err(sproc, "Notification IDs too high:%d\n",
rproc->max_notifyid);
return -EINVAL;
}
for (i = 0; i <= rproc->max_notifyid; i++) {
err = sproc->mdev->ops.kick_subscribe(sproc->mdev, i);
if (err) {
sproc_err(sproc,
"subscription of kicks failed:%d\n", err);
return err;
}
}
return sproc->mdev->ops.power(sproc->mdev, true);
}
static int sproc_stop(struct rproc *rproc)
{
struct sproc *sproc = rproc->priv;
sproc_dbg(sproc, "stop ste-modem\n");
return sproc->mdev->ops.power(sproc->mdev, false);
}
static int sproc_drv_remove(struct platform_device *pdev)
{
struct ste_modem_device *mdev =
container_of(pdev, struct ste_modem_device, pdev);
struct sproc *sproc = mdev->drv_data;
sproc_dbg(sproc, "remove ste-modem\n");
sproc->mdev->ops.setup(sproc->mdev, NULL);
rproc_del(sproc->rproc);
dma_free_coherent(sproc->rproc->dev.parent, SPROC_FW_SIZE,
sproc->fw_addr, sproc->fw_dma_addr);
rproc_put(sproc->rproc);
mdev->drv_data = NULL;
return 0;
}
static int sproc_probe(struct platform_device *pdev)
{
struct ste_modem_device *mdev =
container_of(pdev, struct ste_modem_device, pdev);
struct sproc *sproc;
struct rproc *rproc;
int err;
dev_dbg(&mdev->pdev.dev, "probe ste-modem\n");
if (!mdev->ops.setup || !mdev->ops.kick || !mdev->ops.kick_subscribe ||
!mdev->ops.power) {
dev_err(&mdev->pdev.dev, "invalid mdev ops\n");
return -EINVAL;
}
rproc = rproc_alloc(&mdev->pdev.dev, mdev->pdev.name, &sproc_ops,
SPROC_MODEM_FIRMWARE, sizeof(*sproc));
if (!rproc)
return -ENOMEM;
sproc = rproc->priv;
sproc->mdev = mdev;
sproc->rproc = rproc;
rproc->has_iommu = false;
mdev->drv_data = sproc;
sproc->mdev->ops.setup(sproc->mdev, &sproc_dev_cb);
rproc->fw_ops = &sproc_fw_ops;
sproc->fw_addr = dma_alloc_coherent(rproc->dev.parent, SPROC_FW_SIZE,
&sproc->fw_dma_addr,
GFP_KERNEL);
if (!sproc->fw_addr) {
sproc_err(sproc, "Cannot allocate memory for fw\n");
err = -ENOMEM;
goto free_rproc;
}
err = rproc_add(rproc);
if (err)
goto free_mem;
return 0;
free_mem:
dma_free_coherent(rproc->dev.parent, SPROC_FW_SIZE,
sproc->fw_addr, sproc->fw_dma_addr);
free_rproc:
mdev->drv_data = NULL;
rproc_put(rproc);
return err;
}
