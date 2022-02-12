static inline struct ttm_object_file *
ttm_object_file_ref(struct ttm_object_file *tfile)
{
kref_get(&tfile->refcount);
return tfile;
}
static void ttm_object_file_destroy(struct kref *kref)
{
struct ttm_object_file *tfile =
container_of(kref, struct ttm_object_file, refcount);
kfree(tfile);
}
static inline void ttm_object_file_unref(struct ttm_object_file **p_tfile)
{
struct ttm_object_file *tfile = *p_tfile;
*p_tfile = NULL;
kref_put(&tfile->refcount, ttm_object_file_destroy);
}
int ttm_base_object_init(struct ttm_object_file *tfile,
struct ttm_base_object *base,
bool shareable,
enum ttm_object_type object_type,
void (*refcount_release) (struct ttm_base_object **),
void (*ref_obj_release) (struct ttm_base_object *,
enum ttm_ref_type ref_type))
{
struct ttm_object_device *tdev = tfile->tdev;
int ret;
base->shareable = shareable;
base->tfile = ttm_object_file_ref(tfile);
base->refcount_release = refcount_release;
base->ref_obj_release = ref_obj_release;
base->object_type = object_type;
kref_init(&base->refcount);
spin_lock(&tdev->object_lock);
ret = drm_ht_just_insert_please_rcu(&tdev->object_hash,
&base->hash,
(unsigned long)base, 31, 0, 0);
spin_unlock(&tdev->object_lock);
if (unlikely(ret != 0))
goto out_err0;
ret = ttm_ref_object_add(tfile, base, TTM_REF_USAGE, NULL);
if (unlikely(ret != 0))
goto out_err1;
ttm_base_object_unref(&base);
return 0;
out_err1:
spin_lock(&tdev->object_lock);
(void)drm_ht_remove_item_rcu(&tdev->object_hash, &base->hash);
spin_unlock(&tdev->object_lock);
out_err0:
return ret;
}
static void ttm_release_base(struct kref *kref)
{
struct ttm_base_object *base =
container_of(kref, struct ttm_base_object, refcount);
struct ttm_object_device *tdev = base->tfile->tdev;
spin_lock(&tdev->object_lock);
(void)drm_ht_remove_item_rcu(&tdev->object_hash, &base->hash);
spin_unlock(&tdev->object_lock);
ttm_object_file_unref(&base->tfile);
if (base->refcount_release)
base->refcount_release(&base);
}
void ttm_base_object_unref(struct ttm_base_object **p_base)
{
struct ttm_base_object *base = *p_base;
*p_base = NULL;
kref_put(&base->refcount, ttm_release_base);
}
struct ttm_base_object *ttm_base_object_lookup(struct ttm_object_file *tfile,
uint32_t key)
{
struct ttm_base_object *base = NULL;
struct drm_hash_item *hash;
struct drm_open_hash *ht = &tfile->ref_hash[TTM_REF_USAGE];
int ret;
rcu_read_lock();
ret = drm_ht_find_item_rcu(ht, key, &hash);
if (likely(ret == 0)) {
base = drm_hash_entry(hash, struct ttm_ref_object, hash)->obj;
if (!kref_get_unless_zero(&base->refcount))
base = NULL;
}
rcu_read_unlock();
return base;
}
struct ttm_base_object *
ttm_base_object_lookup_for_ref(struct ttm_object_device *tdev, uint32_t key)
{
struct ttm_base_object *base = NULL;
struct drm_hash_item *hash;
struct drm_open_hash *ht = &tdev->object_hash;
int ret;
rcu_read_lock();
ret = drm_ht_find_item_rcu(ht, key, &hash);
if (likely(ret == 0)) {
base = drm_hash_entry(hash, struct ttm_base_object, hash);
if (!kref_get_unless_zero(&base->refcount))
base = NULL;
}
rcu_read_unlock();
return base;
}
bool ttm_ref_object_exists(struct ttm_object_file *tfile,
struct ttm_base_object *base)
{
struct drm_open_hash *ht = &tfile->ref_hash[TTM_REF_USAGE];
struct drm_hash_item *hash;
struct ttm_ref_object *ref;
rcu_read_lock();
if (unlikely(drm_ht_find_item_rcu(ht, base->hash.key, &hash) != 0))
goto out_false;
ref = drm_hash_entry(hash, struct ttm_ref_object, hash);
if (unlikely(base != ref->obj))
goto out_false;
rmb();
if (unlikely(atomic_read(&ref->kref.refcount) == 0))
goto out_false;
rcu_read_unlock();
return true;
out_false:
rcu_read_unlock();
return false;
}
int ttm_ref_object_add(struct ttm_object_file *tfile,
struct ttm_base_object *base,
enum ttm_ref_type ref_type, bool *existed)
{
struct drm_open_hash *ht = &tfile->ref_hash[ref_type];
struct ttm_ref_object *ref;
struct drm_hash_item *hash;
struct ttm_mem_global *mem_glob = tfile->tdev->mem_glob;
int ret = -EINVAL;
if (base->tfile != tfile && !base->shareable)
return -EPERM;
if (existed != NULL)
*existed = true;
while (ret == -EINVAL) {
rcu_read_lock();
ret = drm_ht_find_item_rcu(ht, base->hash.key, &hash);
if (ret == 0) {
ref = drm_hash_entry(hash, struct ttm_ref_object, hash);
if (kref_get_unless_zero(&ref->kref)) {
rcu_read_unlock();
break;
}
}
rcu_read_unlock();
ret = ttm_mem_global_alloc(mem_glob, sizeof(*ref),
false, false);
if (unlikely(ret != 0))
return ret;
ref = kmalloc(sizeof(*ref), GFP_KERNEL);
if (unlikely(ref == NULL)) {
ttm_mem_global_free(mem_glob, sizeof(*ref));
return -ENOMEM;
}
ref->hash.key = base->hash.key;
ref->obj = base;
ref->tfile = tfile;
ref->ref_type = ref_type;
kref_init(&ref->kref);
spin_lock(&tfile->lock);
ret = drm_ht_insert_item_rcu(ht, &ref->hash);
if (likely(ret == 0)) {
list_add_tail(&ref->head, &tfile->ref_list);
kref_get(&base->refcount);
spin_unlock(&tfile->lock);
if (existed != NULL)
*existed = false;
break;
}
spin_unlock(&tfile->lock);
BUG_ON(ret != -EINVAL);
ttm_mem_global_free(mem_glob, sizeof(*ref));
kfree(ref);
}
return ret;
}
static void ttm_ref_object_release(struct kref *kref)
{
struct ttm_ref_object *ref =
container_of(kref, struct ttm_ref_object, kref);
struct ttm_base_object *base = ref->obj;
struct ttm_object_file *tfile = ref->tfile;
struct drm_open_hash *ht;
struct ttm_mem_global *mem_glob = tfile->tdev->mem_glob;
ht = &tfile->ref_hash[ref->ref_type];
(void)drm_ht_remove_item_rcu(ht, &ref->hash);
list_del(&ref->head);
spin_unlock(&tfile->lock);
if (ref->ref_type != TTM_REF_USAGE && base->ref_obj_release)
base->ref_obj_release(base, ref->ref_type);
ttm_base_object_unref(&ref->obj);
ttm_mem_global_free(mem_glob, sizeof(*ref));
kfree_rcu(ref, rcu_head);
spin_lock(&tfile->lock);
}
int ttm_ref_object_base_unref(struct ttm_object_file *tfile,
unsigned long key, enum ttm_ref_type ref_type)
{
struct drm_open_hash *ht = &tfile->ref_hash[ref_type];
struct ttm_ref_object *ref;
struct drm_hash_item *hash;
int ret;
spin_lock(&tfile->lock);
ret = drm_ht_find_item(ht, key, &hash);
if (unlikely(ret != 0)) {
spin_unlock(&tfile->lock);
return -EINVAL;
}
ref = drm_hash_entry(hash, struct ttm_ref_object, hash);
kref_put(&ref->kref, ttm_ref_object_release);
spin_unlock(&tfile->lock);
return 0;
}
void ttm_object_file_release(struct ttm_object_file **p_tfile)
{
struct ttm_ref_object *ref;
struct list_head *list;
unsigned int i;
struct ttm_object_file *tfile = *p_tfile;
*p_tfile = NULL;
spin_lock(&tfile->lock);
while (!list_empty(&tfile->ref_list)) {
list = tfile->ref_list.next;
ref = list_entry(list, struct ttm_ref_object, head);
ttm_ref_object_release(&ref->kref);
}
for (i = 0; i < TTM_REF_NUM; ++i)
drm_ht_remove(&tfile->ref_hash[i]);
spin_unlock(&tfile->lock);
ttm_object_file_unref(&tfile);
}
struct ttm_object_file *ttm_object_file_init(struct ttm_object_device *tdev,
unsigned int hash_order)
{
struct ttm_object_file *tfile = kmalloc(sizeof(*tfile), GFP_KERNEL);
unsigned int i;
unsigned int j = 0;
int ret;
if (unlikely(tfile == NULL))
return NULL;
spin_lock_init(&tfile->lock);
tfile->tdev = tdev;
kref_init(&tfile->refcount);
INIT_LIST_HEAD(&tfile->ref_list);
for (i = 0; i < TTM_REF_NUM; ++i) {
ret = drm_ht_create(&tfile->ref_hash[i], hash_order);
if (ret) {
j = i;
goto out_err;
}
}
return tfile;
out_err:
for (i = 0; i < j; ++i)
drm_ht_remove(&tfile->ref_hash[i]);
kfree(tfile);
return NULL;
}
struct ttm_object_device *
ttm_object_device_init(struct ttm_mem_global *mem_glob,
unsigned int hash_order,
const struct dma_buf_ops *ops)
{
struct ttm_object_device *tdev = kmalloc(sizeof(*tdev), GFP_KERNEL);
int ret;
if (unlikely(tdev == NULL))
return NULL;
tdev->mem_glob = mem_glob;
spin_lock_init(&tdev->object_lock);
atomic_set(&tdev->object_count, 0);
ret = drm_ht_create(&tdev->object_hash, hash_order);
if (ret != 0)
goto out_no_object_hash;
tdev->ops = *ops;
tdev->dmabuf_release = tdev->ops.release;
tdev->ops.release = ttm_prime_dmabuf_release;
tdev->dma_buf_size = ttm_round_pot(sizeof(struct dma_buf)) +
ttm_round_pot(sizeof(struct file));
return tdev;
out_no_object_hash:
kfree(tdev);
return NULL;
}
void ttm_object_device_release(struct ttm_object_device **p_tdev)
{
struct ttm_object_device *tdev = *p_tdev;
*p_tdev = NULL;
spin_lock(&tdev->object_lock);
drm_ht_remove(&tdev->object_hash);
spin_unlock(&tdev->object_lock);
kfree(tdev);
}
static bool __must_check get_dma_buf_unless_doomed(struct dma_buf *dmabuf)
{
return atomic_long_inc_not_zero(&dmabuf->file->f_count) != 0L;
}
static void ttm_prime_refcount_release(struct ttm_base_object **p_base)
{
struct ttm_base_object *base = *p_base;
struct ttm_prime_object *prime;
*p_base = NULL;
prime = container_of(base, struct ttm_prime_object, base);
BUG_ON(prime->dma_buf != NULL);
mutex_destroy(&prime->mutex);
if (prime->refcount_release)
prime->refcount_release(&base);
}
static void ttm_prime_dmabuf_release(struct dma_buf *dma_buf)
{
struct ttm_prime_object *prime =
(struct ttm_prime_object *) dma_buf->priv;
struct ttm_base_object *base = &prime->base;
struct ttm_object_device *tdev = base->tfile->tdev;
if (tdev->dmabuf_release)
tdev->dmabuf_release(dma_buf);
mutex_lock(&prime->mutex);
if (prime->dma_buf == dma_buf)
prime->dma_buf = NULL;
mutex_unlock(&prime->mutex);
ttm_mem_global_free(tdev->mem_glob, tdev->dma_buf_size);
ttm_base_object_unref(&base);
}
int ttm_prime_fd_to_handle(struct ttm_object_file *tfile,
int fd, u32 *handle)
{
struct ttm_object_device *tdev = tfile->tdev;
struct dma_buf *dma_buf;
struct ttm_prime_object *prime;
struct ttm_base_object *base;
int ret;
dma_buf = dma_buf_get(fd);
if (IS_ERR(dma_buf))
return PTR_ERR(dma_buf);
if (dma_buf->ops != &tdev->ops)
return -ENOSYS;
prime = (struct ttm_prime_object *) dma_buf->priv;
base = &prime->base;
*handle = base->hash.key;
ret = ttm_ref_object_add(tfile, base, TTM_REF_USAGE, NULL);
dma_buf_put(dma_buf);
return ret;
}
int ttm_prime_handle_to_fd(struct ttm_object_file *tfile,
uint32_t handle, uint32_t flags,
int *prime_fd)
{
struct ttm_object_device *tdev = tfile->tdev;
struct ttm_base_object *base;
struct dma_buf *dma_buf;
struct ttm_prime_object *prime;
int ret;
base = ttm_base_object_lookup(tfile, handle);
if (unlikely(base == NULL ||
base->object_type != ttm_prime_type)) {
ret = -ENOENT;
goto out_unref;
}
prime = container_of(base, struct ttm_prime_object, base);
if (unlikely(!base->shareable)) {
ret = -EPERM;
goto out_unref;
}
ret = mutex_lock_interruptible(&prime->mutex);
if (unlikely(ret != 0)) {
ret = -ERESTARTSYS;
goto out_unref;
}
dma_buf = prime->dma_buf;
if (!dma_buf || !get_dma_buf_unless_doomed(dma_buf)) {
ret = ttm_mem_global_alloc(tdev->mem_glob, tdev->dma_buf_size,
false, true);
if (unlikely(ret != 0)) {
mutex_unlock(&prime->mutex);
goto out_unref;
}
dma_buf = dma_buf_export(prime, &tdev->ops,
prime->size, flags, NULL);
if (IS_ERR(dma_buf)) {
ret = PTR_ERR(dma_buf);
ttm_mem_global_free(tdev->mem_glob,
tdev->dma_buf_size);
mutex_unlock(&prime->mutex);
goto out_unref;
}
base = NULL;
prime->dma_buf = dma_buf;
}
mutex_unlock(&prime->mutex);
ret = dma_buf_fd(dma_buf, flags);
if (ret >= 0) {
*prime_fd = ret;
ret = 0;
} else
dma_buf_put(dma_buf);
out_unref:
if (base)
ttm_base_object_unref(&base);
return ret;
}
int ttm_prime_object_init(struct ttm_object_file *tfile, size_t size,
struct ttm_prime_object *prime, bool shareable,
enum ttm_object_type type,
void (*refcount_release) (struct ttm_base_object **),
void (*ref_obj_release) (struct ttm_base_object *,
enum ttm_ref_type ref_type))
{
mutex_init(&prime->mutex);
prime->size = PAGE_ALIGN(size);
prime->real_type = type;
prime->dma_buf = NULL;
prime->refcount_release = refcount_release;
return ttm_base_object_init(tfile, &prime->base, shareable,
ttm_prime_type,
ttm_prime_refcount_release,
ref_obj_release);
}
