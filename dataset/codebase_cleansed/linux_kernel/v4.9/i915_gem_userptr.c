static void wait_rendering(struct drm_i915_gem_object *obj)
{
unsigned long active = __I915_BO_ACTIVE(obj);
int idx;
for_each_active(active, idx)
i915_gem_active_wait_unlocked(&obj->last_read[idx],
0, NULL, NULL);
}
static void cancel_userptr(struct work_struct *work)
{
struct i915_mmu_object *mo = container_of(work, typeof(*mo), work);
struct drm_i915_gem_object *obj = mo->obj;
struct drm_device *dev = obj->base.dev;
wait_rendering(obj);
mutex_lock(&dev->struct_mutex);
obj->userptr.work = NULL;
if (obj->pages != NULL) {
WARN_ON(i915_gem_object_unbind(obj));
WARN_ON(i915_gem_object_put_pages(obj));
}
i915_gem_object_put(obj);
mutex_unlock(&dev->struct_mutex);
}
static void add_object(struct i915_mmu_object *mo)
{
if (mo->attached)
return;
interval_tree_insert(&mo->it, &mo->mn->objects);
mo->attached = true;
}
static void del_object(struct i915_mmu_object *mo)
{
if (!mo->attached)
return;
interval_tree_remove(&mo->it, &mo->mn->objects);
mo->attached = false;
}
static void i915_gem_userptr_mn_invalidate_range_start(struct mmu_notifier *_mn,
struct mm_struct *mm,
unsigned long start,
unsigned long end)
{
struct i915_mmu_notifier *mn =
container_of(_mn, struct i915_mmu_notifier, mn);
struct i915_mmu_object *mo;
struct interval_tree_node *it;
LIST_HEAD(cancelled);
if (RB_EMPTY_ROOT(&mn->objects))
return;
end--;
spin_lock(&mn->lock);
it = interval_tree_iter_first(&mn->objects, start, end);
while (it) {
mo = container_of(it, struct i915_mmu_object, it);
if (kref_get_unless_zero(&mo->obj->base.refcount))
queue_work(mn->wq, &mo->work);
list_add(&mo->link, &cancelled);
it = interval_tree_iter_next(it, start, end);
}
list_for_each_entry(mo, &cancelled, link)
del_object(mo);
spin_unlock(&mn->lock);
flush_workqueue(mn->wq);
}
static struct i915_mmu_notifier *
i915_mmu_notifier_create(struct mm_struct *mm)
{
struct i915_mmu_notifier *mn;
int ret;
mn = kmalloc(sizeof(*mn), GFP_KERNEL);
if (mn == NULL)
return ERR_PTR(-ENOMEM);
spin_lock_init(&mn->lock);
mn->mn.ops = &i915_gem_userptr_notifier;
mn->objects = RB_ROOT;
mn->wq = alloc_workqueue("i915-userptr-release", WQ_UNBOUND, 0);
if (mn->wq == NULL) {
kfree(mn);
return ERR_PTR(-ENOMEM);
}
ret = __mmu_notifier_register(&mn->mn, mm);
if (ret) {
destroy_workqueue(mn->wq);
kfree(mn);
return ERR_PTR(ret);
}
return mn;
}
static void
i915_gem_userptr_release__mmu_notifier(struct drm_i915_gem_object *obj)
{
struct i915_mmu_object *mo;
mo = obj->userptr.mmu_object;
if (mo == NULL)
return;
spin_lock(&mo->mn->lock);
del_object(mo);
spin_unlock(&mo->mn->lock);
kfree(mo);
obj->userptr.mmu_object = NULL;
}
static struct i915_mmu_notifier *
i915_mmu_notifier_find(struct i915_mm_struct *mm)
{
struct i915_mmu_notifier *mn = mm->mn;
mn = mm->mn;
if (mn)
return mn;
down_write(&mm->mm->mmap_sem);
mutex_lock(&mm->i915->mm_lock);
if ((mn = mm->mn) == NULL) {
mn = i915_mmu_notifier_create(mm->mm);
if (!IS_ERR(mn))
mm->mn = mn;
}
mutex_unlock(&mm->i915->mm_lock);
up_write(&mm->mm->mmap_sem);
return mn;
}
static int
i915_gem_userptr_init__mmu_notifier(struct drm_i915_gem_object *obj,
unsigned flags)
{
struct i915_mmu_notifier *mn;
struct i915_mmu_object *mo;
if (flags & I915_USERPTR_UNSYNCHRONIZED)
return capable(CAP_SYS_ADMIN) ? 0 : -EPERM;
if (WARN_ON(obj->userptr.mm == NULL))
return -EINVAL;
mn = i915_mmu_notifier_find(obj->userptr.mm);
if (IS_ERR(mn))
return PTR_ERR(mn);
mo = kzalloc(sizeof(*mo), GFP_KERNEL);
if (mo == NULL)
return -ENOMEM;
mo->mn = mn;
mo->obj = obj;
mo->it.start = obj->userptr.ptr;
mo->it.last = obj->userptr.ptr + obj->base.size - 1;
INIT_WORK(&mo->work, cancel_userptr);
obj->userptr.mmu_object = mo;
return 0;
}
static void
i915_mmu_notifier_free(struct i915_mmu_notifier *mn,
struct mm_struct *mm)
{
if (mn == NULL)
return;
mmu_notifier_unregister(&mn->mn, mm);
destroy_workqueue(mn->wq);
kfree(mn);
}
static void
i915_gem_userptr_release__mmu_notifier(struct drm_i915_gem_object *obj)
{
}
static int
i915_gem_userptr_init__mmu_notifier(struct drm_i915_gem_object *obj,
unsigned flags)
{
if ((flags & I915_USERPTR_UNSYNCHRONIZED) == 0)
return -ENODEV;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
return 0;
}
static void
i915_mmu_notifier_free(struct i915_mmu_notifier *mn,
struct mm_struct *mm)
{
}
static struct i915_mm_struct *
__i915_mm_struct_find(struct drm_i915_private *dev_priv, struct mm_struct *real)
{
struct i915_mm_struct *mm;
hash_for_each_possible(dev_priv->mm_structs, mm, node, (unsigned long)real)
if (mm->mm == real)
return mm;
return NULL;
}
static int
i915_gem_userptr_init__mm_struct(struct drm_i915_gem_object *obj)
{
struct drm_i915_private *dev_priv = to_i915(obj->base.dev);
struct i915_mm_struct *mm;
int ret = 0;
mutex_lock(&dev_priv->mm_lock);
mm = __i915_mm_struct_find(dev_priv, current->mm);
if (mm == NULL) {
mm = kmalloc(sizeof(*mm), GFP_KERNEL);
if (mm == NULL) {
ret = -ENOMEM;
goto out;
}
kref_init(&mm->kref);
mm->i915 = to_i915(obj->base.dev);
mm->mm = current->mm;
atomic_inc(&current->mm->mm_count);
mm->mn = NULL;
hash_add(dev_priv->mm_structs,
&mm->node, (unsigned long)mm->mm);
} else
kref_get(&mm->kref);
obj->userptr.mm = mm;
out:
mutex_unlock(&dev_priv->mm_lock);
return ret;
}
static void
__i915_mm_struct_free__worker(struct work_struct *work)
{
struct i915_mm_struct *mm = container_of(work, typeof(*mm), work);
i915_mmu_notifier_free(mm->mn, mm->mm);
mmdrop(mm->mm);
kfree(mm);
}
static void
__i915_mm_struct_free(struct kref *kref)
{
struct i915_mm_struct *mm = container_of(kref, typeof(*mm), kref);
hash_del(&mm->node);
mutex_unlock(&mm->i915->mm_lock);
INIT_WORK(&mm->work, __i915_mm_struct_free__worker);
schedule_work(&mm->work);
}
static void
i915_gem_userptr_release__mm_struct(struct drm_i915_gem_object *obj)
{
if (obj->userptr.mm == NULL)
return;
kref_put_mutex(&obj->userptr.mm->kref,
__i915_mm_struct_free,
&to_i915(obj->base.dev)->mm_lock);
obj->userptr.mm = NULL;
}
static int
st_set_pages(struct sg_table **st, struct page **pvec, int num_pages)
{
struct scatterlist *sg;
int ret, n;
*st = kmalloc(sizeof(**st), GFP_KERNEL);
if (*st == NULL)
return -ENOMEM;
if (swiotlb_active()) {
ret = sg_alloc_table(*st, num_pages, GFP_KERNEL);
if (ret)
goto err;
for_each_sg((*st)->sgl, sg, num_pages, n)
sg_set_page(sg, pvec[n], PAGE_SIZE, 0);
} else {
ret = sg_alloc_table_from_pages(*st, pvec, num_pages,
0, num_pages << PAGE_SHIFT,
GFP_KERNEL);
if (ret)
goto err;
}
return 0;
err:
kfree(*st);
*st = NULL;
return ret;
}
static int
__i915_gem_userptr_set_pages(struct drm_i915_gem_object *obj,
struct page **pvec, int num_pages)
{
int ret;
ret = st_set_pages(&obj->pages, pvec, num_pages);
if (ret)
return ret;
ret = i915_gem_gtt_prepare_object(obj);
if (ret) {
sg_free_table(obj->pages);
kfree(obj->pages);
obj->pages = NULL;
}
return ret;
}
static int
__i915_gem_userptr_set_active(struct drm_i915_gem_object *obj,
bool value)
{
int ret = 0;
#if defined(CONFIG_MMU_NOTIFIER)
if (obj->userptr.mmu_object == NULL)
return 0;
spin_lock(&obj->userptr.mmu_object->mn->lock);
if (!value)
del_object(obj->userptr.mmu_object);
else if (!work_pending(&obj->userptr.mmu_object->work))
add_object(obj->userptr.mmu_object);
else
ret = -EAGAIN;
spin_unlock(&obj->userptr.mmu_object->mn->lock);
#endif
return ret;
}
static void
__i915_gem_userptr_get_pages_worker(struct work_struct *_work)
{
struct get_pages_work *work = container_of(_work, typeof(*work), work);
struct drm_i915_gem_object *obj = work->obj;
struct drm_device *dev = obj->base.dev;
const int npages = obj->base.size >> PAGE_SHIFT;
struct page **pvec;
int pinned, ret;
ret = -ENOMEM;
pinned = 0;
pvec = drm_malloc_gfp(npages, sizeof(struct page *), GFP_TEMPORARY);
if (pvec != NULL) {
struct mm_struct *mm = obj->userptr.mm->mm;
unsigned int flags = 0;
if (!obj->userptr.read_only)
flags |= FOLL_WRITE;
ret = -EFAULT;
if (atomic_inc_not_zero(&mm->mm_users)) {
down_read(&mm->mmap_sem);
while (pinned < npages) {
ret = get_user_pages_remote
(work->task, mm,
obj->userptr.ptr + pinned * PAGE_SIZE,
npages - pinned,
flags,
pvec + pinned, NULL);
if (ret < 0)
break;
pinned += ret;
}
up_read(&mm->mmap_sem);
mmput(mm);
}
}
mutex_lock(&dev->struct_mutex);
if (obj->userptr.work == &work->work) {
if (pinned == npages) {
ret = __i915_gem_userptr_set_pages(obj, pvec, npages);
if (ret == 0) {
list_add_tail(&obj->global_list,
&to_i915(dev)->mm.unbound_list);
obj->get_page.sg = obj->pages->sgl;
obj->get_page.last = 0;
pinned = 0;
}
}
obj->userptr.work = ERR_PTR(ret);
}
obj->userptr.workers--;
i915_gem_object_put(obj);
mutex_unlock(&dev->struct_mutex);
release_pages(pvec, pinned, 0);
drm_free_large(pvec);
put_task_struct(work->task);
kfree(work);
}
static int
__i915_gem_userptr_get_pages_schedule(struct drm_i915_gem_object *obj,
bool *active)
{
struct get_pages_work *work;
if (obj->userptr.workers >= I915_GEM_USERPTR_MAX_WORKERS)
return -EAGAIN;
work = kmalloc(sizeof(*work), GFP_KERNEL);
if (work == NULL)
return -ENOMEM;
obj->userptr.work = &work->work;
obj->userptr.workers++;
work->obj = i915_gem_object_get(obj);
work->task = current;
get_task_struct(work->task);
INIT_WORK(&work->work, __i915_gem_userptr_get_pages_worker);
schedule_work(&work->work);
*active = true;
return -EAGAIN;
}
static int
i915_gem_userptr_get_pages(struct drm_i915_gem_object *obj)
{
const int num_pages = obj->base.size >> PAGE_SHIFT;
struct page **pvec;
int pinned, ret;
bool active;
if (obj->userptr.work) {
if (IS_ERR(obj->userptr.work))
return PTR_ERR(obj->userptr.work);
else
return -EAGAIN;
}
ret = __i915_gem_userptr_set_active(obj, true);
if (ret)
return ret;
pvec = NULL;
pinned = 0;
if (obj->userptr.mm->mm == current->mm) {
pvec = drm_malloc_gfp(num_pages, sizeof(struct page *),
GFP_TEMPORARY);
if (pvec == NULL) {
__i915_gem_userptr_set_active(obj, false);
return -ENOMEM;
}
pinned = __get_user_pages_fast(obj->userptr.ptr, num_pages,
!obj->userptr.read_only, pvec);
}
active = false;
if (pinned < 0)
ret = pinned, pinned = 0;
else if (pinned < num_pages)
ret = __i915_gem_userptr_get_pages_schedule(obj, &active);
else
ret = __i915_gem_userptr_set_pages(obj, pvec, num_pages);
if (ret) {
__i915_gem_userptr_set_active(obj, active);
release_pages(pvec, pinned, 0);
}
drm_free_large(pvec);
return ret;
}
static void
i915_gem_userptr_put_pages(struct drm_i915_gem_object *obj)
{
struct sgt_iter sgt_iter;
struct page *page;
BUG_ON(obj->userptr.work != NULL);
__i915_gem_userptr_set_active(obj, false);
if (obj->madv != I915_MADV_WILLNEED)
obj->dirty = 0;
i915_gem_gtt_finish_object(obj);
for_each_sgt_page(page, sgt_iter, obj->pages) {
if (obj->dirty)
set_page_dirty(page);
mark_page_accessed(page);
put_page(page);
}
obj->dirty = 0;
sg_free_table(obj->pages);
kfree(obj->pages);
}
static void
i915_gem_userptr_release(struct drm_i915_gem_object *obj)
{
i915_gem_userptr_release__mmu_notifier(obj);
i915_gem_userptr_release__mm_struct(obj);
}
static int
i915_gem_userptr_dmabuf_export(struct drm_i915_gem_object *obj)
{
if (obj->userptr.mmu_object)
return 0;
return i915_gem_userptr_init__mmu_notifier(obj, 0);
}
int
i915_gem_userptr_ioctl(struct drm_device *dev, void *data, struct drm_file *file)
{
struct drm_i915_gem_userptr *args = data;
struct drm_i915_gem_object *obj;
int ret;
u32 handle;
if (!HAS_LLC(dev) && !HAS_SNOOP(dev)) {
return -ENODEV;
}
if (args->flags & ~(I915_USERPTR_READ_ONLY |
I915_USERPTR_UNSYNCHRONIZED))
return -EINVAL;
if (offset_in_page(args->user_ptr | args->user_size))
return -EINVAL;
if (!access_ok(args->flags & I915_USERPTR_READ_ONLY ? VERIFY_READ : VERIFY_WRITE,
(char __user *)(unsigned long)args->user_ptr, args->user_size))
return -EFAULT;
if (args->flags & I915_USERPTR_READ_ONLY) {
return -ENODEV;
}
obj = i915_gem_object_alloc(dev);
if (obj == NULL)
return -ENOMEM;
drm_gem_private_object_init(dev, &obj->base, args->user_size);
i915_gem_object_init(obj, &i915_gem_userptr_ops);
obj->cache_level = I915_CACHE_LLC;
obj->base.write_domain = I915_GEM_DOMAIN_CPU;
obj->base.read_domains = I915_GEM_DOMAIN_CPU;
obj->userptr.ptr = args->user_ptr;
obj->userptr.read_only = !!(args->flags & I915_USERPTR_READ_ONLY);
ret = i915_gem_userptr_init__mm_struct(obj);
if (ret == 0)
ret = i915_gem_userptr_init__mmu_notifier(obj, args->flags);
if (ret == 0)
ret = drm_gem_handle_create(file, &obj->base, &handle);
i915_gem_object_put_unlocked(obj);
if (ret)
return ret;
args->handle = handle;
return 0;
}
void i915_gem_init_userptr(struct drm_i915_private *dev_priv)
{
mutex_init(&dev_priv->mm_lock);
hash_init(dev_priv->mm_structs);
}
