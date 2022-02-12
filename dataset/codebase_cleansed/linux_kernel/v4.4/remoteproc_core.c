static const char *rproc_crash_to_string(enum rproc_crash_type type)
{
if (type < ARRAY_SIZE(rproc_crash_names))
return rproc_crash_names[type];
return "unknown";
}
static int rproc_iommu_fault(struct iommu_domain *domain, struct device *dev,
unsigned long iova, int flags, void *token)
{
struct rproc *rproc = token;
dev_err(dev, "iommu fault: da 0x%lx flags 0x%x\n", iova, flags);
rproc_report_crash(rproc, RPROC_MMUFAULT);
return -ENOSYS;
}
static int rproc_enable_iommu(struct rproc *rproc)
{
struct iommu_domain *domain;
struct device *dev = rproc->dev.parent;
int ret;
if (!rproc->has_iommu) {
dev_dbg(dev, "iommu not present\n");
return 0;
}
domain = iommu_domain_alloc(dev->bus);
if (!domain) {
dev_err(dev, "can't alloc iommu domain\n");
return -ENOMEM;
}
iommu_set_fault_handler(domain, rproc_iommu_fault, rproc);
ret = iommu_attach_device(domain, dev);
if (ret) {
dev_err(dev, "can't attach iommu device: %d\n", ret);
goto free_domain;
}
rproc->domain = domain;
return 0;
free_domain:
iommu_domain_free(domain);
return ret;
}
static void rproc_disable_iommu(struct rproc *rproc)
{
struct iommu_domain *domain = rproc->domain;
struct device *dev = rproc->dev.parent;
if (!domain)
return;
iommu_detach_device(domain, dev);
iommu_domain_free(domain);
}
void *rproc_da_to_va(struct rproc *rproc, u64 da, int len)
{
struct rproc_mem_entry *carveout;
void *ptr = NULL;
if (rproc->ops->da_to_va) {
ptr = rproc->ops->da_to_va(rproc, da, len);
if (ptr)
goto out;
}
list_for_each_entry(carveout, &rproc->carveouts, node) {
int offset = da - carveout->da;
if (offset < 0)
continue;
if (offset + len > carveout->len)
continue;
ptr = carveout->va + offset;
break;
}
out:
return ptr;
}
int rproc_alloc_vring(struct rproc_vdev *rvdev, int i)
{
struct rproc *rproc = rvdev->rproc;
struct device *dev = &rproc->dev;
struct rproc_vring *rvring = &rvdev->vring[i];
struct fw_rsc_vdev *rsc;
dma_addr_t dma;
void *va;
int ret, size, notifyid;
size = PAGE_ALIGN(vring_size(rvring->len, rvring->align));
va = dma_alloc_coherent(dev->parent, size, &dma, GFP_KERNEL);
if (!va) {
dev_err(dev->parent, "dma_alloc_coherent failed\n");
return -EINVAL;
}
ret = idr_alloc(&rproc->notifyids, rvring, 0, 0, GFP_KERNEL);
if (ret < 0) {
dev_err(dev, "idr_alloc failed: %d\n", ret);
dma_free_coherent(dev->parent, size, va, dma);
return ret;
}
notifyid = ret;
dev_dbg(dev, "vring%d: va %p dma %llx size %x idr %d\n", i, va,
(unsigned long long)dma, size, notifyid);
rvring->va = va;
rvring->dma = dma;
rvring->notifyid = notifyid;
rsc = (void *)rproc->table_ptr + rvdev->rsc_offset;
rsc->vring[i].da = dma;
rsc->vring[i].notifyid = notifyid;
return 0;
}
static int
rproc_parse_vring(struct rproc_vdev *rvdev, struct fw_rsc_vdev *rsc, int i)
{
struct rproc *rproc = rvdev->rproc;
struct device *dev = &rproc->dev;
struct fw_rsc_vdev_vring *vring = &rsc->vring[i];
struct rproc_vring *rvring = &rvdev->vring[i];
dev_dbg(dev, "vdev rsc: vring%d: da %x, qsz %d, align %d\n",
i, vring->da, vring->num, vring->align);
if (vring->reserved) {
dev_err(dev, "vring rsc has non zero reserved bytes\n");
return -EINVAL;
}
if (!vring->num || !vring->align) {
dev_err(dev, "invalid qsz (%d) or alignment (%d)\n",
vring->num, vring->align);
return -EINVAL;
}
rvring->len = vring->num;
rvring->align = vring->align;
rvring->rvdev = rvdev;
return 0;
}
void rproc_free_vring(struct rproc_vring *rvring)
{
int size = PAGE_ALIGN(vring_size(rvring->len, rvring->align));
struct rproc *rproc = rvring->rvdev->rproc;
int idx = rvring->rvdev->vring - rvring;
struct fw_rsc_vdev *rsc;
dma_free_coherent(rproc->dev.parent, size, rvring->va, rvring->dma);
idr_remove(&rproc->notifyids, rvring->notifyid);
rsc = (void *)rproc->table_ptr + rvring->rvdev->rsc_offset;
rsc->vring[idx].da = 0;
rsc->vring[idx].notifyid = -1;
}
static int rproc_handle_vdev(struct rproc *rproc, struct fw_rsc_vdev *rsc,
int offset, int avail)
{
struct device *dev = &rproc->dev;
struct rproc_vdev *rvdev;
int i, ret;
if (sizeof(*rsc) + rsc->num_of_vrings * sizeof(struct fw_rsc_vdev_vring)
+ rsc->config_len > avail) {
dev_err(dev, "vdev rsc is truncated\n");
return -EINVAL;
}
if (rsc->reserved[0] || rsc->reserved[1]) {
dev_err(dev, "vdev rsc has non zero reserved bytes\n");
return -EINVAL;
}
dev_dbg(dev, "vdev rsc: id %d, dfeatures %x, cfg len %d, %d vrings\n",
rsc->id, rsc->dfeatures, rsc->config_len, rsc->num_of_vrings);
if (rsc->num_of_vrings > ARRAY_SIZE(rvdev->vring)) {
dev_err(dev, "too many vrings: %d\n", rsc->num_of_vrings);
return -EINVAL;
}
rvdev = kzalloc(sizeof(struct rproc_vdev), GFP_KERNEL);
if (!rvdev)
return -ENOMEM;
rvdev->rproc = rproc;
for (i = 0; i < rsc->num_of_vrings; i++) {
ret = rproc_parse_vring(rvdev, rsc, i);
if (ret)
goto free_rvdev;
}
rvdev->rsc_offset = offset;
list_add_tail(&rvdev->node, &rproc->rvdevs);
ret = rproc_add_virtio_dev(rvdev, rsc->id);
if (ret)
goto remove_rvdev;
return 0;
remove_rvdev:
list_del(&rvdev->node);
free_rvdev:
kfree(rvdev);
return ret;
}
static int rproc_handle_trace(struct rproc *rproc, struct fw_rsc_trace *rsc,
int offset, int avail)
{
struct rproc_mem_entry *trace;
struct device *dev = &rproc->dev;
void *ptr;
char name[15];
if (sizeof(*rsc) > avail) {
dev_err(dev, "trace rsc is truncated\n");
return -EINVAL;
}
if (rsc->reserved) {
dev_err(dev, "trace rsc has non zero reserved bytes\n");
return -EINVAL;
}
ptr = rproc_da_to_va(rproc, rsc->da, rsc->len);
if (!ptr) {
dev_err(dev, "erroneous trace resource entry\n");
return -EINVAL;
}
trace = kzalloc(sizeof(*trace), GFP_KERNEL);
if (!trace)
return -ENOMEM;
trace->len = rsc->len;
trace->va = ptr;
snprintf(name, sizeof(name), "trace%d", rproc->num_traces);
trace->priv = rproc_create_trace_file(name, rproc, trace);
if (!trace->priv) {
trace->va = NULL;
kfree(trace);
return -EINVAL;
}
list_add_tail(&trace->node, &rproc->traces);
rproc->num_traces++;
dev_dbg(dev, "%s added: va %p, da 0x%x, len 0x%x\n", name, ptr,
rsc->da, rsc->len);
return 0;
}
static int rproc_handle_devmem(struct rproc *rproc, struct fw_rsc_devmem *rsc,
int offset, int avail)
{
struct rproc_mem_entry *mapping;
struct device *dev = &rproc->dev;
int ret;
if (!rproc->domain)
return -EINVAL;
if (sizeof(*rsc) > avail) {
dev_err(dev, "devmem rsc is truncated\n");
return -EINVAL;
}
if (rsc->reserved) {
dev_err(dev, "devmem rsc has non zero reserved bytes\n");
return -EINVAL;
}
mapping = kzalloc(sizeof(*mapping), GFP_KERNEL);
if (!mapping)
return -ENOMEM;
ret = iommu_map(rproc->domain, rsc->da, rsc->pa, rsc->len, rsc->flags);
if (ret) {
dev_err(dev, "failed to map devmem: %d\n", ret);
goto out;
}
mapping->da = rsc->da;
mapping->len = rsc->len;
list_add_tail(&mapping->node, &rproc->mappings);
dev_dbg(dev, "mapped devmem pa 0x%x, da 0x%x, len 0x%x\n",
rsc->pa, rsc->da, rsc->len);
return 0;
out:
kfree(mapping);
return ret;
}
static int rproc_handle_carveout(struct rproc *rproc,
struct fw_rsc_carveout *rsc,
int offset, int avail)
{
struct rproc_mem_entry *carveout, *mapping;
struct device *dev = &rproc->dev;
dma_addr_t dma;
void *va;
int ret;
if (sizeof(*rsc) > avail) {
dev_err(dev, "carveout rsc is truncated\n");
return -EINVAL;
}
if (rsc->reserved) {
dev_err(dev, "carveout rsc has non zero reserved bytes\n");
return -EINVAL;
}
dev_dbg(dev, "carveout rsc: da %x, pa %x, len %x, flags %x\n",
rsc->da, rsc->pa, rsc->len, rsc->flags);
carveout = kzalloc(sizeof(*carveout), GFP_KERNEL);
if (!carveout)
return -ENOMEM;
va = dma_alloc_coherent(dev->parent, rsc->len, &dma, GFP_KERNEL);
if (!va) {
dev_err(dev->parent, "dma_alloc_coherent err: %d\n", rsc->len);
ret = -ENOMEM;
goto free_carv;
}
dev_dbg(dev, "carveout va %p, dma %llx, len 0x%x\n", va,
(unsigned long long)dma, rsc->len);
if (rproc->domain) {
mapping = kzalloc(sizeof(*mapping), GFP_KERNEL);
if (!mapping) {
dev_err(dev, "kzalloc mapping failed\n");
ret = -ENOMEM;
goto dma_free;
}
ret = iommu_map(rproc->domain, rsc->da, dma, rsc->len,
rsc->flags);
if (ret) {
dev_err(dev, "iommu_map failed: %d\n", ret);
goto free_mapping;
}
mapping->da = rsc->da;
mapping->len = rsc->len;
list_add_tail(&mapping->node, &rproc->mappings);
dev_dbg(dev, "carveout mapped 0x%x to 0x%llx\n",
rsc->da, (unsigned long long)dma);
}
rsc->pa = dma;
carveout->va = va;
carveout->len = rsc->len;
carveout->dma = dma;
carveout->da = rsc->da;
list_add_tail(&carveout->node, &rproc->carveouts);
return 0;
free_mapping:
kfree(mapping);
dma_free:
dma_free_coherent(dev->parent, rsc->len, va, dma);
free_carv:
kfree(carveout);
return ret;
}
static int rproc_count_vrings(struct rproc *rproc, struct fw_rsc_vdev *rsc,
int offset, int avail)
{
rproc->max_notifyid += rsc->num_of_vrings;
return 0;
}
static int rproc_handle_resources(struct rproc *rproc, int len,
rproc_handle_resource_t handlers[RSC_LAST])
{
struct device *dev = &rproc->dev;
rproc_handle_resource_t handler;
int ret = 0, i;
for (i = 0; i < rproc->table_ptr->num; i++) {
int offset = rproc->table_ptr->offset[i];
struct fw_rsc_hdr *hdr = (void *)rproc->table_ptr + offset;
int avail = len - offset - sizeof(*hdr);
void *rsc = (void *)hdr + sizeof(*hdr);
if (avail < 0) {
dev_err(dev, "rsc table is truncated\n");
return -EINVAL;
}
dev_dbg(dev, "rsc: type %d\n", hdr->type);
if (hdr->type >= RSC_LAST) {
dev_warn(dev, "unsupported resource %d\n", hdr->type);
continue;
}
handler = handlers[hdr->type];
if (!handler)
continue;
ret = handler(rproc, rsc, offset + sizeof(*hdr), avail);
if (ret)
break;
}
return ret;
}
static void rproc_resource_cleanup(struct rproc *rproc)
{
struct rproc_mem_entry *entry, *tmp;
struct device *dev = &rproc->dev;
list_for_each_entry_safe(entry, tmp, &rproc->traces, node) {
rproc_remove_trace_file(entry->priv);
rproc->num_traces--;
list_del(&entry->node);
kfree(entry);
}
list_for_each_entry_safe(entry, tmp, &rproc->mappings, node) {
size_t unmapped;
unmapped = iommu_unmap(rproc->domain, entry->da, entry->len);
if (unmapped != entry->len) {
dev_err(dev, "failed to unmap %u/%zu\n", entry->len,
unmapped);
}
list_del(&entry->node);
kfree(entry);
}
list_for_each_entry_safe(entry, tmp, &rproc->carveouts, node) {
dma_free_coherent(dev->parent, entry->len, entry->va,
entry->dma);
list_del(&entry->node);
kfree(entry);
}
}
static int rproc_fw_boot(struct rproc *rproc, const struct firmware *fw)
{
struct device *dev = &rproc->dev;
const char *name = rproc->firmware;
struct resource_table *table, *loaded_table;
int ret, tablesz;
if (!rproc->table_ptr)
return -ENOMEM;
ret = rproc_fw_sanity_check(rproc, fw);
if (ret)
return ret;
dev_info(dev, "Booting fw image %s, size %zd\n", name, fw->size);
ret = rproc_enable_iommu(rproc);
if (ret) {
dev_err(dev, "can't enable iommu: %d\n", ret);
return ret;
}
rproc->bootaddr = rproc_get_boot_addr(rproc, fw);
ret = -EINVAL;
table = rproc_find_rsc_table(rproc, fw, &tablesz);
if (!table)
goto clean_up;
if (rproc->table_csum != crc32(0, table, tablesz)) {
dev_err(dev, "resource checksum failed, fw changed?\n");
goto clean_up;
}
ret = rproc_handle_resources(rproc, tablesz, rproc_loading_handlers);
if (ret) {
dev_err(dev, "Failed to process resources: %d\n", ret);
goto clean_up;
}
ret = rproc_load_segments(rproc, fw);
if (ret) {
dev_err(dev, "Failed to load program segments: %d\n", ret);
goto clean_up;
}
loaded_table = rproc_find_loaded_rsc_table(rproc, fw);
if (!loaded_table) {
ret = -EINVAL;
goto clean_up;
}
memcpy(loaded_table, rproc->cached_table, tablesz);
ret = rproc->ops->start(rproc);
if (ret) {
dev_err(dev, "can't start rproc %s: %d\n", rproc->name, ret);
goto clean_up;
}
rproc->table_ptr = loaded_table;
rproc->state = RPROC_RUNNING;
dev_info(dev, "remote processor %s is now up\n", rproc->name);
return 0;
clean_up:
rproc_resource_cleanup(rproc);
rproc_disable_iommu(rproc);
return ret;
}
static void rproc_fw_config_virtio(const struct firmware *fw, void *context)
{
struct rproc *rproc = context;
struct resource_table *table;
int ret, tablesz;
if (rproc_fw_sanity_check(rproc, fw) < 0)
goto out;
table = rproc_find_rsc_table(rproc, fw, &tablesz);
if (!table)
goto out;
rproc->table_csum = crc32(0, table, tablesz);
rproc->cached_table = kmemdup(table, tablesz, GFP_KERNEL);
if (!rproc->cached_table)
goto out;
rproc->table_ptr = rproc->cached_table;
rproc->max_notifyid = -1;
ret = rproc_handle_resources(rproc, tablesz,
rproc_count_vrings_handler);
if (ret)
goto out;
ret = rproc_handle_resources(rproc, tablesz, rproc_vdev_handler);
out:
release_firmware(fw);
complete_all(&rproc->firmware_loading_complete);
}
static int rproc_add_virtio_devices(struct rproc *rproc)
{
int ret;
init_completion(&rproc->firmware_loading_complete);
ret = request_firmware_nowait(THIS_MODULE, FW_ACTION_HOTPLUG,
rproc->firmware, &rproc->dev, GFP_KERNEL,
rproc, rproc_fw_config_virtio);
if (ret < 0) {
dev_err(&rproc->dev, "request_firmware_nowait err: %d\n", ret);
complete_all(&rproc->firmware_loading_complete);
}
return ret;
}
int rproc_trigger_recovery(struct rproc *rproc)
{
struct rproc_vdev *rvdev, *rvtmp;
dev_err(&rproc->dev, "recovering %s\n", rproc->name);
init_completion(&rproc->crash_comp);
list_for_each_entry_safe(rvdev, rvtmp, &rproc->rvdevs, node)
rproc_remove_virtio_dev(rvdev);
wait_for_completion(&rproc->crash_comp);
kfree(rproc->cached_table);
return rproc_add_virtio_devices(rproc);
}
static void rproc_crash_handler_work(struct work_struct *work)
{
struct rproc *rproc = container_of(work, struct rproc, crash_handler);
struct device *dev = &rproc->dev;
dev_dbg(dev, "enter %s\n", __func__);
mutex_lock(&rproc->lock);
if (rproc->state == RPROC_CRASHED || rproc->state == RPROC_OFFLINE) {
mutex_unlock(&rproc->lock);
return;
}
rproc->state = RPROC_CRASHED;
dev_err(dev, "handling crash #%u in %s\n", ++rproc->crash_cnt,
rproc->name);
mutex_unlock(&rproc->lock);
if (!rproc->recovery_disabled)
rproc_trigger_recovery(rproc);
}
int rproc_boot(struct rproc *rproc)
{
const struct firmware *firmware_p;
struct device *dev;
int ret;
if (!rproc) {
pr_err("invalid rproc handle\n");
return -EINVAL;
}
dev = &rproc->dev;
ret = mutex_lock_interruptible(&rproc->lock);
if (ret) {
dev_err(dev, "can't lock rproc %s: %d\n", rproc->name, ret);
return ret;
}
if (!rproc->firmware) {
dev_err(dev, "%s: no firmware to load\n", __func__);
ret = -EINVAL;
goto unlock_mutex;
}
if (!try_module_get(dev->parent->driver->owner)) {
dev_err(dev, "%s: can't get owner\n", __func__);
ret = -EINVAL;
goto unlock_mutex;
}
if (atomic_inc_return(&rproc->power) > 1) {
ret = 0;
goto unlock_mutex;
}
dev_info(dev, "powering up %s\n", rproc->name);
ret = request_firmware(&firmware_p, rproc->firmware, dev);
if (ret < 0) {
dev_err(dev, "request_firmware failed: %d\n", ret);
goto downref_rproc;
}
ret = rproc_fw_boot(rproc, firmware_p);
release_firmware(firmware_p);
downref_rproc:
if (ret) {
module_put(dev->parent->driver->owner);
atomic_dec(&rproc->power);
}
unlock_mutex:
mutex_unlock(&rproc->lock);
return ret;
}
void rproc_shutdown(struct rproc *rproc)
{
struct device *dev = &rproc->dev;
int ret;
ret = mutex_lock_interruptible(&rproc->lock);
if (ret) {
dev_err(dev, "can't lock rproc %s: %d\n", rproc->name, ret);
return;
}
if (!atomic_dec_and_test(&rproc->power))
goto out;
ret = rproc->ops->stop(rproc);
if (ret) {
atomic_inc(&rproc->power);
dev_err(dev, "can't stop rproc: %d\n", ret);
goto out;
}
rproc_resource_cleanup(rproc);
rproc_disable_iommu(rproc);
rproc->table_ptr = rproc->cached_table;
if (rproc->state == RPROC_CRASHED)
complete_all(&rproc->crash_comp);
rproc->state = RPROC_OFFLINE;
dev_info(dev, "stopped remote processor %s\n", rproc->name);
out:
mutex_unlock(&rproc->lock);
if (!ret)
module_put(dev->parent->driver->owner);
}
struct rproc *rproc_get_by_phandle(phandle phandle)
{
struct rproc *rproc = NULL, *r;
struct device_node *np;
np = of_find_node_by_phandle(phandle);
if (!np)
return NULL;
mutex_lock(&rproc_list_mutex);
list_for_each_entry(r, &rproc_list, node) {
if (r->dev.parent && r->dev.parent->of_node == np) {
rproc = r;
get_device(&rproc->dev);
break;
}
}
mutex_unlock(&rproc_list_mutex);
of_node_put(np);
return rproc;
}
struct rproc *rproc_get_by_phandle(phandle phandle)
{
return NULL;
}
int rproc_add(struct rproc *rproc)
{
struct device *dev = &rproc->dev;
int ret;
ret = device_add(dev);
if (ret < 0)
return ret;
mutex_lock(&rproc_list_mutex);
list_add(&rproc->node, &rproc_list);
mutex_unlock(&rproc_list_mutex);
dev_info(dev, "%s is available\n", rproc->name);
dev_info(dev, "Note: remoteproc is still under development and considered experimental.\n");
dev_info(dev, "THE BINARY FORMAT IS NOT YET FINALIZED, and backward compatibility isn't yet guaranteed.\n");
rproc_create_debug_dir(rproc);
return rproc_add_virtio_devices(rproc);
}
static void rproc_type_release(struct device *dev)
{
struct rproc *rproc = container_of(dev, struct rproc, dev);
dev_info(&rproc->dev, "releasing %s\n", rproc->name);
rproc_delete_debug_dir(rproc);
idr_destroy(&rproc->notifyids);
if (rproc->index >= 0)
ida_simple_remove(&rproc_dev_index, rproc->index);
kfree(rproc);
}
struct rproc *rproc_alloc(struct device *dev, const char *name,
const struct rproc_ops *ops,
const char *firmware, int len)
{
struct rproc *rproc;
char *p, *template = "rproc-%s-fw";
int name_len = 0;
if (!dev || !name || !ops)
return NULL;
if (!firmware)
name_len = strlen(name) + strlen(template) - 2 + 1;
rproc = kzalloc(sizeof(struct rproc) + len + name_len, GFP_KERNEL);
if (!rproc)
return NULL;
if (!firmware) {
p = (char *)rproc + sizeof(struct rproc) + len;
snprintf(p, name_len, template, name);
} else {
p = (char *)firmware;
}
rproc->firmware = p;
rproc->name = name;
rproc->ops = ops;
rproc->priv = &rproc[1];
device_initialize(&rproc->dev);
rproc->dev.parent = dev;
rproc->dev.type = &rproc_type;
rproc->index = ida_simple_get(&rproc_dev_index, 0, 0, GFP_KERNEL);
if (rproc->index < 0) {
dev_err(dev, "ida_simple_get failed: %d\n", rproc->index);
put_device(&rproc->dev);
return NULL;
}
dev_set_name(&rproc->dev, "remoteproc%d", rproc->index);
atomic_set(&rproc->power, 0);
rproc->fw_ops = &rproc_elf_fw_ops;
mutex_init(&rproc->lock);
idr_init(&rproc->notifyids);
INIT_LIST_HEAD(&rproc->carveouts);
INIT_LIST_HEAD(&rproc->mappings);
INIT_LIST_HEAD(&rproc->traces);
INIT_LIST_HEAD(&rproc->rvdevs);
INIT_WORK(&rproc->crash_handler, rproc_crash_handler_work);
init_completion(&rproc->crash_comp);
rproc->state = RPROC_OFFLINE;
return rproc;
}
void rproc_put(struct rproc *rproc)
{
put_device(&rproc->dev);
}
int rproc_del(struct rproc *rproc)
{
struct rproc_vdev *rvdev, *tmp;
if (!rproc)
return -EINVAL;
wait_for_completion(&rproc->firmware_loading_complete);
list_for_each_entry_safe(rvdev, tmp, &rproc->rvdevs, node)
rproc_remove_virtio_dev(rvdev);
kfree(rproc->cached_table);
mutex_lock(&rproc_list_mutex);
list_del(&rproc->node);
mutex_unlock(&rproc_list_mutex);
device_del(&rproc->dev);
return 0;
}
void rproc_report_crash(struct rproc *rproc, enum rproc_crash_type type)
{
if (!rproc) {
pr_err("NULL rproc pointer\n");
return;
}
dev_err(&rproc->dev, "crash detected in %s: type %s\n",
rproc->name, rproc_crash_to_string(type));
schedule_work(&rproc->crash_handler);
}
static int __init remoteproc_init(void)
{
rproc_init_debugfs();
return 0;
}
static void __exit remoteproc_exit(void)
{
ida_destroy(&rproc_dev_index);
rproc_exit_debugfs();
}
