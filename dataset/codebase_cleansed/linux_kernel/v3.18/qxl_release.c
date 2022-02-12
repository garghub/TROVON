static const char *qxl_get_driver_name(struct fence *fence)
{
return "qxl";
}
static const char *qxl_get_timeline_name(struct fence *fence)
{
return "release";
}
static bool qxl_nop_signaling(struct fence *fence)
{
return true;
}
static long qxl_fence_wait(struct fence *fence, bool intr, signed long timeout)
{
struct qxl_device *qdev;
struct qxl_release *release;
int count = 0, sc = 0;
bool have_drawable_releases;
unsigned long cur, end = jiffies + timeout;
qdev = container_of(fence->lock, struct qxl_device, release_lock);
release = container_of(fence, struct qxl_release, base);
have_drawable_releases = release->type == QXL_RELEASE_DRAWABLE;
retry:
sc++;
if (fence_is_signaled(fence))
goto signaled;
qxl_io_notify_oom(qdev);
for (count = 0; count < 11; count++) {
if (!qxl_queue_garbage_collect(qdev, true))
break;
if (fence_is_signaled(fence))
goto signaled;
}
if (fence_is_signaled(fence))
goto signaled;
if (have_drawable_releases || sc < 4) {
if (sc > 2)
usleep_range(500, 1000);
if (time_after(jiffies, end))
return 0;
if (have_drawable_releases && sc > 300) {
FENCE_WARN(fence, "failed to wait on release %d "
"after spincount %d\n",
fence->context & ~0xf0000000, sc);
goto signaled;
}
goto retry;
}
signaled:
cur = jiffies;
if (time_after(cur, end))
return 0;
return end - cur;
}
static uint64_t
qxl_release_alloc(struct qxl_device *qdev, int type,
struct qxl_release **ret)
{
struct qxl_release *release;
int handle;
size_t size = sizeof(*release);
release = kmalloc(size, GFP_KERNEL);
if (!release) {
DRM_ERROR("Out of memory\n");
return 0;
}
release->base.ops = NULL;
release->type = type;
release->release_offset = 0;
release->surface_release_id = 0;
INIT_LIST_HEAD(&release->bos);
idr_preload(GFP_KERNEL);
spin_lock(&qdev->release_idr_lock);
handle = idr_alloc(&qdev->release_idr, release, 1, 0, GFP_NOWAIT);
release->base.seqno = ++qdev->release_seqno;
spin_unlock(&qdev->release_idr_lock);
idr_preload_end();
if (handle < 0) {
kfree(release);
*ret = NULL;
return handle;
}
*ret = release;
QXL_INFO(qdev, "allocated release %lld\n", handle);
release->id = handle;
return handle;
}
static void
qxl_release_free_list(struct qxl_release *release)
{
while (!list_empty(&release->bos)) {
struct qxl_bo_list *entry;
struct qxl_bo *bo;
entry = container_of(release->bos.next,
struct qxl_bo_list, tv.head);
bo = to_qxl_bo(entry->tv.bo);
qxl_bo_unref(&bo);
list_del(&entry->tv.head);
kfree(entry);
}
}
void
qxl_release_free(struct qxl_device *qdev,
struct qxl_release *release)
{
QXL_INFO(qdev, "release %d, type %d\n", release->id,
release->type);
if (release->surface_release_id)
qxl_surface_id_dealloc(qdev, release->surface_release_id);
spin_lock(&qdev->release_idr_lock);
idr_remove(&qdev->release_idr, release->id);
spin_unlock(&qdev->release_idr_lock);
if (release->base.ops) {
WARN_ON(list_empty(&release->bos));
qxl_release_free_list(release);
fence_signal(&release->base);
fence_put(&release->base);
} else {
qxl_release_free_list(release);
kfree(release);
}
}
static int qxl_release_bo_alloc(struct qxl_device *qdev,
struct qxl_bo **bo)
{
int ret;
ret = qxl_bo_create(qdev, PAGE_SIZE, false, true,
QXL_GEM_DOMAIN_VRAM, NULL,
bo);
return ret;
}
int qxl_release_list_add(struct qxl_release *release, struct qxl_bo *bo)
{
struct qxl_bo_list *entry;
list_for_each_entry(entry, &release->bos, tv.head) {
if (entry->tv.bo == &bo->tbo)
return 0;
}
entry = kmalloc(sizeof(struct qxl_bo_list), GFP_KERNEL);
if (!entry)
return -ENOMEM;
qxl_bo_ref(bo);
entry->tv.bo = &bo->tbo;
entry->tv.shared = false;
list_add_tail(&entry->tv.head, &release->bos);
return 0;
}
static int qxl_release_validate_bo(struct qxl_bo *bo)
{
int ret;
if (!bo->pin_count) {
qxl_ttm_placement_from_domain(bo, bo->type, false);
ret = ttm_bo_validate(&bo->tbo, &bo->placement,
true, false);
if (ret)
return ret;
}
ret = reservation_object_reserve_shared(bo->tbo.resv);
if (ret)
return ret;
ret = qxl_bo_check_id(bo->gem_base.dev->dev_private, bo);
if (ret)
return ret;
return 0;
}
int qxl_release_reserve_list(struct qxl_release *release, bool no_intr)
{
int ret;
struct qxl_bo_list *entry;
if (list_is_singular(&release->bos))
return 0;
ret = ttm_eu_reserve_buffers(&release->ticket, &release->bos, !no_intr);
if (ret)
return ret;
list_for_each_entry(entry, &release->bos, tv.head) {
struct qxl_bo *bo = to_qxl_bo(entry->tv.bo);
ret = qxl_release_validate_bo(bo);
if (ret) {
ttm_eu_backoff_reservation(&release->ticket, &release->bos);
return ret;
}
}
return 0;
}
void qxl_release_backoff_reserve_list(struct qxl_release *release)
{
if (list_is_singular(&release->bos))
return;
ttm_eu_backoff_reservation(&release->ticket, &release->bos);
}
int qxl_alloc_surface_release_reserved(struct qxl_device *qdev,
enum qxl_surface_cmd_type surface_cmd_type,
struct qxl_release *create_rel,
struct qxl_release **release)
{
if (surface_cmd_type == QXL_SURFACE_CMD_DESTROY && create_rel) {
int idr_ret;
struct qxl_bo_list *entry = list_first_entry(&create_rel->bos, struct qxl_bo_list, tv.head);
struct qxl_bo *bo;
union qxl_release_info *info;
idr_ret = qxl_release_alloc(qdev, QXL_RELEASE_SURFACE_CMD, release);
if (idr_ret < 0)
return idr_ret;
bo = qxl_bo_ref(to_qxl_bo(entry->tv.bo));
(*release)->release_offset = create_rel->release_offset + 64;
qxl_release_list_add(*release, bo);
info = qxl_release_map(qdev, *release);
info->id = idr_ret;
qxl_release_unmap(qdev, *release, info);
qxl_bo_unref(&bo);
return 0;
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
int ret = 0;
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
if (idr_ret < 0) {
if (rbo)
*rbo = NULL;
return idr_ret;
}
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
}
bo = qxl_bo_ref(qdev->current_release_bo[cur_idx]);
(*release)->release_offset = qdev->current_release_bo_offset[cur_idx] * release_size_per_bo[cur_idx];
qdev->current_release_bo_offset[cur_idx]++;
if (rbo)
*rbo = bo;
mutex_unlock(&qdev->release_mutex);
qxl_release_list_add(*release, bo);
info = qxl_release_map(qdev, *release);
info->id = idr_ret;
qxl_release_unmap(qdev, *release, info);
qxl_bo_unref(&bo);
return ret;
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
return release;
}
union qxl_release_info *qxl_release_map(struct qxl_device *qdev,
struct qxl_release *release)
{
void *ptr;
union qxl_release_info *info;
struct qxl_bo_list *entry = list_first_entry(&release->bos, struct qxl_bo_list, tv.head);
struct qxl_bo *bo = to_qxl_bo(entry->tv.bo);
ptr = qxl_bo_kmap_atomic_page(qdev, bo, release->release_offset & PAGE_SIZE);
if (!ptr)
return NULL;
info = ptr + (release->release_offset & ~PAGE_SIZE);
return info;
}
void qxl_release_unmap(struct qxl_device *qdev,
struct qxl_release *release,
union qxl_release_info *info)
{
struct qxl_bo_list *entry = list_first_entry(&release->bos, struct qxl_bo_list, tv.head);
struct qxl_bo *bo = to_qxl_bo(entry->tv.bo);
void *ptr;
ptr = ((void *)info) - (release->release_offset & ~PAGE_SIZE);
qxl_bo_kunmap_atomic_page(qdev, bo, ptr);
}
void qxl_release_fence_buffer_objects(struct qxl_release *release)
{
struct ttm_buffer_object *bo;
struct ttm_bo_global *glob;
struct ttm_bo_device *bdev;
struct ttm_bo_driver *driver;
struct qxl_bo *qbo;
struct ttm_validate_buffer *entry;
struct qxl_device *qdev;
if (list_is_singular(&release->bos) || list_empty(&release->bos))
return;
bo = list_first_entry(&release->bos, struct ttm_validate_buffer, head)->bo;
bdev = bo->bdev;
qdev = container_of(bdev, struct qxl_device, mman.bdev);
fence_init(&release->base, &qxl_fence_ops, &qdev->release_lock,
release->id | 0xf0000000, release->base.seqno);
trace_fence_emit(&release->base);
driver = bdev->driver;
glob = bo->glob;
spin_lock(&glob->lru_lock);
list_for_each_entry(entry, &release->bos, head) {
bo = entry->bo;
qbo = to_qxl_bo(bo);
reservation_object_add_shared_fence(bo->resv, &release->base);
ttm_bo_add_to_lru(bo);
__ttm_bo_unreserve(bo);
}
spin_unlock(&glob->lru_lock);
ww_acquire_fini(&release->ticket);
}
