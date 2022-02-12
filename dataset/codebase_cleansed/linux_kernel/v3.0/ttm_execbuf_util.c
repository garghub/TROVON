static void ttm_eu_backoff_reservation_locked(struct list_head *list)
{
struct ttm_validate_buffer *entry;
list_for_each_entry(entry, list, head) {
struct ttm_buffer_object *bo = entry->bo;
if (!entry->reserved)
continue;
if (entry->removed) {
ttm_bo_add_to_lru(bo);
entry->removed = false;
}
entry->reserved = false;
atomic_set(&bo->reserved, 0);
wake_up_all(&bo->event_queue);
}
}
static void ttm_eu_del_from_lru_locked(struct list_head *list)
{
struct ttm_validate_buffer *entry;
list_for_each_entry(entry, list, head) {
struct ttm_buffer_object *bo = entry->bo;
if (!entry->reserved)
continue;
if (!entry->removed) {
entry->put_count = ttm_bo_del_from_lru(bo);
entry->removed = true;
}
}
}
static void ttm_eu_list_ref_sub(struct list_head *list)
{
struct ttm_validate_buffer *entry;
list_for_each_entry(entry, list, head) {
struct ttm_buffer_object *bo = entry->bo;
if (entry->put_count) {
ttm_bo_list_ref_sub(bo, entry->put_count, true);
entry->put_count = 0;
}
}
}
static int ttm_eu_wait_unreserved_locked(struct list_head *list,
struct ttm_buffer_object *bo)
{
struct ttm_bo_global *glob = bo->glob;
int ret;
ttm_eu_del_from_lru_locked(list);
spin_unlock(&glob->lru_lock);
ret = ttm_bo_wait_unreserved(bo, true);
spin_lock(&glob->lru_lock);
if (unlikely(ret != 0))
ttm_eu_backoff_reservation_locked(list);
return ret;
}
void ttm_eu_backoff_reservation(struct list_head *list)
{
struct ttm_validate_buffer *entry;
struct ttm_bo_global *glob;
if (list_empty(list))
return;
entry = list_first_entry(list, struct ttm_validate_buffer, head);
glob = entry->bo->glob;
spin_lock(&glob->lru_lock);
ttm_eu_backoff_reservation_locked(list);
spin_unlock(&glob->lru_lock);
}
int ttm_eu_reserve_buffers(struct list_head *list)
{
struct ttm_bo_global *glob;
struct ttm_validate_buffer *entry;
int ret;
uint32_t val_seq;
if (list_empty(list))
return 0;
list_for_each_entry(entry, list, head) {
entry->reserved = false;
entry->put_count = 0;
entry->removed = false;
}
entry = list_first_entry(list, struct ttm_validate_buffer, head);
glob = entry->bo->glob;
retry:
spin_lock(&glob->lru_lock);
val_seq = entry->bo->bdev->val_seq++;
list_for_each_entry(entry, list, head) {
struct ttm_buffer_object *bo = entry->bo;
retry_this_bo:
ret = ttm_bo_reserve_locked(bo, true, true, true, val_seq);
switch (ret) {
case 0:
break;
case -EBUSY:
ret = ttm_eu_wait_unreserved_locked(list, bo);
if (unlikely(ret != 0)) {
spin_unlock(&glob->lru_lock);
ttm_eu_list_ref_sub(list);
return ret;
}
goto retry_this_bo;
case -EAGAIN:
ttm_eu_backoff_reservation_locked(list);
spin_unlock(&glob->lru_lock);
ttm_eu_list_ref_sub(list);
ret = ttm_bo_wait_unreserved(bo, true);
if (unlikely(ret != 0))
return ret;
goto retry;
default:
ttm_eu_backoff_reservation_locked(list);
spin_unlock(&glob->lru_lock);
ttm_eu_list_ref_sub(list);
return ret;
}
entry->reserved = true;
if (unlikely(atomic_read(&bo->cpu_writers) > 0)) {
ttm_eu_backoff_reservation_locked(list);
spin_unlock(&glob->lru_lock);
ttm_eu_list_ref_sub(list);
ret = ttm_bo_wait_cpu(bo, false);
if (ret)
return ret;
goto retry;
}
}
ttm_eu_del_from_lru_locked(list);
spin_unlock(&glob->lru_lock);
ttm_eu_list_ref_sub(list);
return 0;
}
void ttm_eu_fence_buffer_objects(struct list_head *list, void *sync_obj)
{
struct ttm_validate_buffer *entry;
struct ttm_buffer_object *bo;
struct ttm_bo_global *glob;
struct ttm_bo_device *bdev;
struct ttm_bo_driver *driver;
if (list_empty(list))
return;
bo = list_first_entry(list, struct ttm_validate_buffer, head)->bo;
bdev = bo->bdev;
driver = bdev->driver;
glob = bo->glob;
spin_lock(&bdev->fence_lock);
spin_lock(&glob->lru_lock);
list_for_each_entry(entry, list, head) {
bo = entry->bo;
entry->old_sync_obj = bo->sync_obj;
bo->sync_obj = driver->sync_obj_ref(sync_obj);
bo->sync_obj_arg = entry->new_sync_obj_arg;
ttm_bo_unreserve_locked(bo);
entry->reserved = false;
}
spin_unlock(&glob->lru_lock);
spin_unlock(&bdev->fence_lock);
list_for_each_entry(entry, list, head) {
if (entry->old_sync_obj)
driver->sync_obj_unref(&entry->old_sync_obj);
}
}
