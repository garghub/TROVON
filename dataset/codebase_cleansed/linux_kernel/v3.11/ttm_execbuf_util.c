static void ttm_eu_backoff_reservation_locked(struct list_head *list,
struct ww_acquire_ctx *ticket)
{
struct ttm_validate_buffer *entry;
list_for_each_entry(entry, list, head) {
struct ttm_buffer_object *bo = entry->bo;
if (!entry->reserved)
continue;
entry->reserved = false;
if (entry->removed) {
ttm_bo_add_to_lru(bo);
entry->removed = false;
}
ww_mutex_unlock(&bo->resv->lock);
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
void ttm_eu_backoff_reservation(struct ww_acquire_ctx *ticket,
struct list_head *list)
{
struct ttm_validate_buffer *entry;
struct ttm_bo_global *glob;
if (list_empty(list))
return;
entry = list_first_entry(list, struct ttm_validate_buffer, head);
glob = entry->bo->glob;
spin_lock(&glob->lru_lock);
ttm_eu_backoff_reservation_locked(list, ticket);
ww_acquire_fini(ticket);
spin_unlock(&glob->lru_lock);
}
int ttm_eu_reserve_buffers(struct ww_acquire_ctx *ticket,
struct list_head *list)
{
struct ttm_bo_global *glob;
struct ttm_validate_buffer *entry;
int ret;
if (list_empty(list))
return 0;
list_for_each_entry(entry, list, head) {
entry->reserved = false;
entry->put_count = 0;
entry->removed = false;
}
entry = list_first_entry(list, struct ttm_validate_buffer, head);
glob = entry->bo->glob;
ww_acquire_init(ticket, &reservation_ww_class);
retry:
list_for_each_entry(entry, list, head) {
struct ttm_buffer_object *bo = entry->bo;
if (entry->reserved)
continue;
ret = ttm_bo_reserve_nolru(bo, true, false, true, ticket);
if (ret == -EDEADLK) {
spin_lock(&glob->lru_lock);
ttm_eu_backoff_reservation_locked(list, ticket);
spin_unlock(&glob->lru_lock);
ttm_eu_list_ref_sub(list);
ret = ww_mutex_lock_slow_interruptible(&bo->resv->lock,
ticket);
if (unlikely(ret != 0)) {
if (ret == -EINTR)
ret = -ERESTARTSYS;
goto err_fini;
}
entry->reserved = true;
if (unlikely(atomic_read(&bo->cpu_writers) > 0)) {
ret = -EBUSY;
goto err;
}
goto retry;
} else if (ret)
goto err;
entry->reserved = true;
if (unlikely(atomic_read(&bo->cpu_writers) > 0)) {
ret = -EBUSY;
goto err;
}
}
ww_acquire_done(ticket);
spin_lock(&glob->lru_lock);
ttm_eu_del_from_lru_locked(list);
spin_unlock(&glob->lru_lock);
ttm_eu_list_ref_sub(list);
return 0;
err:
spin_lock(&glob->lru_lock);
ttm_eu_backoff_reservation_locked(list, ticket);
spin_unlock(&glob->lru_lock);
ttm_eu_list_ref_sub(list);
err_fini:
ww_acquire_done(ticket);
ww_acquire_fini(ticket);
return ret;
}
void ttm_eu_fence_buffer_objects(struct ww_acquire_ctx *ticket,
struct list_head *list, void *sync_obj)
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
spin_lock(&glob->lru_lock);
spin_lock(&bdev->fence_lock);
list_for_each_entry(entry, list, head) {
bo = entry->bo;
entry->old_sync_obj = bo->sync_obj;
bo->sync_obj = driver->sync_obj_ref(sync_obj);
ttm_bo_add_to_lru(bo);
ww_mutex_unlock(&bo->resv->lock);
entry->reserved = false;
}
spin_unlock(&bdev->fence_lock);
spin_unlock(&glob->lru_lock);
ww_acquire_fini(ticket);
list_for_each_entry(entry, list, head) {
if (entry->old_sync_obj)
driver->sync_obj_unref(&entry->old_sync_obj);
}
}
