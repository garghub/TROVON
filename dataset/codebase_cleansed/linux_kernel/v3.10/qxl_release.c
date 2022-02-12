uint64_t
qxl_release_alloc(struct qxl_device *qdev, int type,
struct qxl_release **ret)
{
struct qxl_release *release;
int handle;
size_t size = sizeof(*release);
int idr_ret;
release = kmalloc(size, GFP_KERNEL);
if (!release) {
DRM_ERROR("Out of memory\n");
return 0;
}
release->type = type;
release->bo_count = 0;
release->release_offset = 0;
release->surface_release_id = 0;
idr_preload(GFP_KERNEL);
spin_lock(&qdev->release_idr_lock);
idr_ret = idr_alloc(&qdev->release_idr, release, 1, 0, GFP_NOWAIT);
spin_unlock(&qdev->release_idr_lock);
idr_preload_end();
handle = idr_ret;
if (idr_ret < 0)
goto release_fail;
*ret = release;
QXL_INFO(qdev, "allocated release %lld\n", handle);
release->id = handle;
release_fail:
return handle;
}
void
qxl_release_free(struct qxl_device *qdev,
struct qxl_release *release)
{
int i;
QXL_INFO(qdev, "release %d, type %d, %d bos\n", release->id,
release->type, release->bo_count);
if (release->surface_release_id)
qxl_surface_id_dealloc(qdev, release->surface_release_id);
for (i = 0 ; i < release->bo_count; ++i) {
QXL_INFO(qdev, "release %llx\n",
release->bos[i]->tbo.addr_space_offset
- DRM_FILE_OFFSET);
qxl_fence_remove_release(&release->bos[i]->fence, release->id);
qxl_bo_unref(&release->bos[i]);
}
spin_lock(&qdev->release_idr_lock);
idr_remove(&qdev->release_idr, release->id);
spin_unlock(&qdev->release_idr_lock);
kfree(release);
}
void
qxl_release_add_res(struct qxl_device *qdev, struct qxl_release *release,
struct qxl_bo *bo)
{
int i;
for (i = 0; i < release->bo_count; i++)
if (release->bos[i] == bo)
return;
if (release->bo_count >= QXL_MAX_RES) {
DRM_ERROR("exceeded max resource on a qxl_release item\n");
return;
}
release->bos[release->bo_count++] = qxl_bo_ref(bo);
}
static int qxl_release_bo_alloc(struct qxl_device *qdev,
struct qxl_bo **bo)
{
int ret;
ret = qxl_bo_create(qdev, PAGE_SIZE, false, QXL_GEM_DOMAIN_VRAM, NULL,
bo);
return ret;
}
int qxl_release_reserve(struct qxl_device *qdev,
struct qxl_release *release, bool no_wait)
{
int ret;
if (atomic_inc_return(&release->bos[0]->reserve_count) == 1) {
ret = qxl_bo_reserve(release->bos[0], no_wait);
if (ret)
return ret;
}
return 0;
}
void qxl_release_unreserve(struct qxl_device *qdev,
struct qxl_release *release)
{
if (atomic_dec_and_test(&release->bos[0]->reserve_count))
qxl_bo_unreserve(release->bos[0]);
}
int qxl_alloc_surface_release_reserved(struct qxl_device *qdev,
enum qxl_surface_cmd_type surface_cmd_type,
struct qxl_release *create_rel,
struct qxl_release **release)
{
int ret;
if (surface_cmd_type == QXL_SURFACE_CMD_DESTROY && create_rel) {
int idr_ret;
struct qxl_bo *bo;
union qxl_release_info *info;
idr_ret = qxl_release_alloc(qdev, QXL_RELEASE_SURFACE_CMD, release);
bo = qxl_bo_ref(create_rel->bos[0]);
(*release)->release_offset = create_rel->release_offset + 64;
qxl_release_add_res(qdev, *release, bo);
ret = qxl_release_reserve(qdev, *release, false);
if (ret) {
DRM_ERROR("release reserve failed\n");
goto out_unref;
}
info = qxl_release_map(qdev, *release);
info->id = idr_ret;
qxl_release_unmap(qdev, *release, info);
out_unref:
qxl_bo_unref(&bo);
return ret;
}
return qxl_alloc_release_reserved(qdev, sizeof(struct qxl_surface_cmd),
QXL_RELEASE_SURFACE_CMD, release, NULL);
}
int qxl_alloc_release_reserved(struct qxl_device *qdev, unsigned long size,
int type, struct qxl_release **release,
struct qxl_bo **rbo)
{
struct qxl_bo *bo;
int idr_ret;
int ret;
union qxl_release_info *info;
int cur_idx;
if (type == QXL_RELEASE_DRAWABLE)
cur_idx = 0;
else if (type == QXL_RELEASE_SURFACE_CMD)
cur_idx = 1;
else if (type == QXL_RELEASE_CURSOR_CMD)
cur_idx = 2;
else {
DRM_ERROR("got illegal type: %d\n", type);
return -EINVAL;
}
idr_ret = qxl_release_alloc(qdev, type, release);
mutex_lock(&qdev->release_mutex);
if (qdev->current_release_bo_offset[cur_idx] + 1 >= releases_per_bo[cur_idx]) {
qxl_bo_unref(&qdev->current_release_bo[cur_idx]);
qdev->current_release_bo_offset[cur_idx] = 0;
qdev->current_release_bo[cur_idx] = NULL;
}
if (!qdev->current_release_bo[cur_idx]) {
ret = qxl_release_bo_alloc(qdev, &qdev->current_release_bo[cur_idx]);
if (ret) {
mutex_unlock(&qdev->release_mutex);
return ret;
}
ret = qxl_bo_reserve(qdev->current_release_bo[cur_idx], false);
qxl_bo_pin(qdev->current_release_bo[cur_idx], QXL_GEM_DOMAIN_VRAM, NULL);
qxl_bo_unreserve(qdev->current_release_bo[cur_idx]);
}
bo = qxl_bo_ref(qdev->current_release_bo[cur_idx]);
(*release)->release_offset = qdev->current_release_bo_offset[cur_idx] * release_size_per_bo[cur_idx];
qdev->current_release_bo_offset[cur_idx]++;
if (rbo)
*rbo = bo;
qxl_release_add_res(qdev, *release, bo);
ret = qxl_release_reserve(qdev, *release, false);
mutex_unlock(&qdev->release_mutex);
if (ret)
goto out_unref;
info = qxl_release_map(qdev, *release);
info->id = idr_ret;
qxl_release_unmap(qdev, *release, info);
out_unref:
qxl_bo_unref(&bo);
return ret;
}
int qxl_fence_releaseable(struct qxl_device *qdev,
struct qxl_release *release)
{
int i, ret;
for (i = 0; i < release->bo_count; i++) {
if (!release->bos[i]->tbo.sync_obj)
release->bos[i]->tbo.sync_obj = &release->bos[i]->fence;
ret = qxl_fence_add_release(&release->bos[i]->fence, release->id);
if (ret)
return ret;
}
return 0;
}
struct qxl_release *qxl_release_from_id_locked(struct qxl_device *qdev,
uint64_t id)
{
struct qxl_release *release;
spin_lock(&qdev->release_idr_lock);
release = idr_find(&qdev->release_idr, id);
spin_unlock(&qdev->release_idr_lock);
if (!release) {
DRM_ERROR("failed to find id in release_idr\n");
return NULL;
}
if (release->bo_count < 1) {
DRM_ERROR("read a released resource with 0 bos\n");
return NULL;
}
return release;
}
union qxl_release_info *qxl_release_map(struct qxl_device *qdev,
struct qxl_release *release)
{
void *ptr;
union qxl_release_info *info;
struct qxl_bo *bo = release->bos[0];
ptr = qxl_bo_kmap_atomic_page(qdev, bo, release->release_offset & PAGE_SIZE);
info = ptr + (release->release_offset & ~PAGE_SIZE);
return info;
}
void qxl_release_unmap(struct qxl_device *qdev,
struct qxl_release *release,
union qxl_release_info *info)
{
struct qxl_bo *bo = release->bos[0];
void *ptr;
ptr = ((void *)info) - (release->release_offset & ~PAGE_SIZE);
qxl_bo_kunmap_atomic_page(qdev, bo, ptr);
}
