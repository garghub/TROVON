static void i915_gem_userptr_mn_invalidate_range_start(struct mmu_notifier *_mn,
struct mm_struct *mm,
unsigned long start,
unsigned long end)
{
struct i915_mmu_notifier *mn = container_of(_mn, struct i915_mmu_notifier, mn);
struct interval_tree_node *it = NULL;
unsigned long serial = 0;
end--;
while (start < end) {
struct drm_i915_gem_object *obj;
obj = NULL;
spin_lock(&mn->lock);
if (serial == mn->serial)
it = interval_tree_iter_next(it, start, end);
else
it = interval_tree_iter_first(&mn->objects, start, end);
if (it != NULL) {
obj = container_of(it, struct i915_mmu_object, it)->obj;
drm_gem_object_reference(&obj->base);
serial = mn->serial;
}
spin_unlock(&mn->lock);
if (obj == NULL)
return;
mutex_lock(&mn->dev->struct_mutex);
obj->userptr.work = NULL;
if (obj->pages != NULL) {
struct drm_i915_private *dev_priv = to_i915(mn->dev);
struct i915_vma *vma, *tmp;
bool was_interruptible;
was_interruptible = dev_priv->mm.interruptible;
dev_priv->mm.interruptible = false;
list_for_each_entry_safe(vma, tmp, &obj->vma_list, vma_link) {
int ret = i915_vma_unbind(vma);
WARN_ON(ret && ret != -EIO);
}
WARN_ON(i915_gem_object_put_pages(obj));
dev_priv->mm.interruptible = was_interruptible;
}
start = obj->userptr.ptr + obj->base.size;
drm_gem_object_unreference(&obj->base);
mutex_unlock(&mn->dev->struct_mutex);
}
}
static struct i915_mmu_notifier *
__i915_mmu_notifier_lookup(struct drm_device *dev, struct mm_struct *mm)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_mmu_notifier *mmu;
hash_for_each_possible(dev_priv->mmu_notifiers, mmu, node, (unsigned long)mm)
if (mmu->mm == mm)
return mmu;
return NULL;
}
static struct i915_mmu_notifier *
i915_mmu_notifier_get(struct drm_device *dev, struct mm_struct *mm)
{
struct drm_i915_private *dev_priv = to_i915(dev);
struct i915_mmu_notifier *mmu;
int ret;
lockdep_assert_held(&dev->struct_mutex);
mmu = __i915_mmu_notifier_lookup(dev, mm);
if (mmu)
return mmu;
mmu = kmalloc(sizeof(*mmu), GFP_KERNEL);
if (mmu == NULL)
return ERR_PTR(-ENOMEM);
spin_lock_init(&mmu->lock);
mmu->dev = dev;
mmu->mn.ops = &i915_gem_userptr_notifier;
mmu->mm = mm;
mmu->objects = RB_ROOT;
mmu->count = 0;
mmu->serial = 0;
ret = __mmu_notifier_register(&mmu->mn, mm);
if (ret) {
kfree(mmu);
return ERR_PTR(ret);
}
hash_add(dev_priv->mmu_notifiers, &mmu->node, (unsigned long)mm);
return mmu;
}
static void
__i915_mmu_notifier_destroy_worker(struct work_struct *work)
{
struct i915_mmu_notifier *mmu = container_of(work, typeof(*mmu), work);
mmu_notifier_unregister(&mmu->mn, mmu->mm);
kfree(mmu);
}
static void
__i915_mmu_notifier_destroy(struct i915_mmu_notifier *mmu)
{
lockdep_assert_held(&mmu->dev->struct_mutex);
hash_del(&mmu->node);
INIT_WORK(&mmu->work, __i915_mmu_notifier_destroy_worker);
schedule_work(&mmu->work);
}
static void __i915_mmu_notifier_update_serial(struct i915_mmu_notifier *mmu)
{
if (++mmu->serial == 0)
mmu->serial = 1;
}
static void
i915_mmu_notifier_del(struct i915_mmu_notifier *mmu,
struct i915_mmu_object *mn)
{
lockdep_assert_held(&mmu->dev->struct_mutex);
spin_lock(&mmu->lock);
interval_tree_remove(&mn->it, &mmu->objects);
__i915_mmu_notifier_update_serial(mmu);
spin_unlock(&mmu->lock);
if (--mmu->count == 0)
__i915_mmu_notifier_destroy(mmu);
}
static int
i915_mmu_notifier_add(struct i915_mmu_notifier *mmu,
struct i915_mmu_object *mn)
{
struct interval_tree_node *it;
int ret;
ret = i915_mutex_lock_interruptible(mmu->dev);
if (ret)
return ret;
i915_gem_retire_requests(mmu->dev);
spin_lock(&mmu->lock);
it = interval_tree_iter_first(&mmu->objects,
mn->it.start, mn->it.last);
if (it) {
struct drm_i915_gem_object *obj;
obj = container_of(it, struct i915_mmu_object, it)->obj;
ret = obj->userptr.workers ? -EAGAIN : -EINVAL;
} else {
interval_tree_insert(&mn->it, &mmu->objects);
__i915_mmu_notifier_update_serial(mmu);
ret = 0;
}
spin_unlock(&mmu->lock);
mutex_unlock(&mmu->dev->struct_mutex);
return ret;
}
static void
i915_gem_userptr_release__mmu_notifier(struct drm_i915_gem_object *obj)
{
struct i915_mmu_object *mn;
mn = obj->userptr.mn;
if (mn == NULL)
return;
i915_mmu_notifier_del(mn->mmu, mn);
obj->userptr.mn = NULL;
}
static int
i915_gem_userptr_init__mmu_notifier(struct drm_i915_gem_object *obj,
unsigned flags)
{
struct i915_mmu_notifier *mmu;
struct i915_mmu_object *mn;
int ret;
if (flags & I915_USERPTR_UNSYNCHRONIZED)
return capable(CAP_SYS_ADMIN) ? 0 : -EPERM;
down_write(&obj->userptr.mm->mmap_sem);
ret = i915_mutex_lock_interruptible(obj->base.dev);
if (ret == 0) {
mmu = i915_mmu_notifier_get(obj->base.dev, obj->userptr.mm);
if (!IS_ERR(mmu))
mmu->count++;
else
ret = PTR_ERR(mmu);
mutex_unlock(&obj->base.dev->struct_mutex);
}
up_write(&obj->userptr.mm->mmap_sem);
if (ret)
return ret;
mn = kzalloc(sizeof(*mn), GFP_KERNEL);
if (mn == NULL) {
ret = -ENOMEM;
goto destroy_mmu;
}
mn->mmu = mmu;
mn->it.start = obj->userptr.ptr;
mn->it.last = mn->it.start + obj->base.size - 1;
mn->obj = obj;
ret = i915_mmu_notifier_add(mmu, mn);
if (ret)
goto free_mn;
obj->userptr.mn = mn;
return 0;
free_mn:
kfree(mn);
destroy_mmu:
mutex_lock(&obj->base.dev->struct_mutex);
if (--mmu->count == 0)
__i915_mmu_notifier_destroy(mmu);
mutex_unlock(&obj->base.dev->struct_mutex);
return ret;
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
static void
__i915_gem_userptr_get_pages_worker(struct work_struct *_work)
{
struct get_pages_work *work = container_of(_work, typeof(*work), work);
struct drm_i915_gem_object *obj = work->obj;
struct drm_device *dev = obj->base.dev;
const int num_pages = obj->base.size >> PAGE_SHIFT;
struct page **pvec;
int pinned, ret;
ret = -ENOMEM;
pinned = 0;
pvec = kmalloc(num_pages*sizeof(struct page *),
GFP_TEMPORARY | __GFP_NOWARN | __GFP_NORETRY);
if (pvec == NULL)
pvec = drm_malloc_ab(num_pages, sizeof(struct page *));
if (pvec != NULL) {
struct mm_struct *mm = obj->userptr.mm;
down_read(&mm->mmap_sem);
while (pinned < num_pages) {
ret = get_user_pages(work->task, mm,
obj->userptr.ptr + pinned * PAGE_SIZE,
num_pages - pinned,
!obj->userptr.read_only, 0,
pvec + pinned, NULL);
if (ret < 0)
break;
pinned += ret;
}
up_read(&mm->mmap_sem);
}
mutex_lock(&dev->struct_mutex);
if (obj->userptr.work != &work->work) {
ret = 0;
} else if (pinned == num_pages) {
ret = st_set_pages(&obj->pages, pvec, num_pages);
if (ret == 0) {
list_add_tail(&obj->global_list, &to_i915(dev)->mm.unbound_list);
pinned = 0;
}
}
obj->userptr.work = ERR_PTR(ret);
obj->userptr.workers--;
drm_gem_object_unreference(&obj->base);
mutex_unlock(&dev->struct_mutex);
release_pages(pvec, pinned, 0);
drm_free_large(pvec);
put_task_struct(work->task);
kfree(work);
}
static int
i915_gem_userptr_get_pages(struct drm_i915_gem_object *obj)
{
const int num_pages = obj->base.size >> PAGE_SHIFT;
struct page **pvec;
int pinned, ret;
pvec = NULL;
pinned = 0;
if (obj->userptr.mm == current->mm) {
pvec = kmalloc(num_pages*sizeof(struct page *),
GFP_TEMPORARY | __GFP_NOWARN | __GFP_NORETRY);
if (pvec == NULL) {
pvec = drm_malloc_ab(num_pages, sizeof(struct page *));
if (pvec == NULL)
return -ENOMEM;
}
pinned = __get_user_pages_fast(obj->userptr.ptr, num_pages,
!obj->userptr.read_only, pvec);
}
if (pinned < num_pages) {
if (pinned < 0) {
ret = pinned;
pinned = 0;
} else {
ret = -EAGAIN;
if (obj->userptr.work == NULL &&
obj->userptr.workers < I915_GEM_USERPTR_MAX_WORKERS) {
struct get_pages_work *work;
work = kmalloc(sizeof(*work), GFP_KERNEL);
if (work != NULL) {
obj->userptr.work = &work->work;
obj->userptr.workers++;
work->obj = obj;
drm_gem_object_reference(&obj->base);
work->task = current;
get_task_struct(work->task);
INIT_WORK(&work->work, __i915_gem_userptr_get_pages_worker);
schedule_work(&work->work);
} else
ret = -ENOMEM;
} else {
if (IS_ERR(obj->userptr.work)) {
ret = PTR_ERR(obj->userptr.work);
obj->userptr.work = NULL;
}
}
}
} else {
ret = st_set_pages(&obj->pages, pvec, num_pages);
if (ret == 0) {
obj->userptr.work = NULL;
pinned = 0;
}
}
release_pages(pvec, pinned, 0);
drm_free_large(pvec);
return ret;
}
static void
i915_gem_userptr_put_pages(struct drm_i915_gem_object *obj)
{
struct scatterlist *sg;
int i;
BUG_ON(obj->userptr.work != NULL);
if (obj->madv != I915_MADV_WILLNEED)
obj->dirty = 0;
for_each_sg(obj->pages->sgl, sg, obj->pages->nents, i) {
struct page *page = sg_page(sg);
if (obj->dirty)
set_page_dirty(page);
mark_page_accessed(page);
page_cache_release(page);
}
obj->dirty = 0;
sg_free_table(obj->pages);
kfree(obj->pages);
}
static void
i915_gem_userptr_release(struct drm_i915_gem_object *obj)
{
i915_gem_userptr_release__mmu_notifier(obj);
if (obj->userptr.mm) {
mmput(obj->userptr.mm);
obj->userptr.mm = NULL;
}
}
static int
i915_gem_userptr_dmabuf_export(struct drm_i915_gem_object *obj)
{
if (obj->userptr.mn)
return 0;
return i915_gem_userptr_init__mmu_notifier(obj, 0);
}
int
i915_gem_userptr_ioctl(struct drm_device *dev, void *data, struct drm_file *file)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_i915_gem_userptr *args = data;
struct drm_i915_gem_object *obj;
int ret;
u32 handle;
if (args->flags & ~(I915_USERPTR_READ_ONLY |
I915_USERPTR_UNSYNCHRONIZED))
return -EINVAL;
if (offset_in_page(args->user_ptr | args->user_size))
return -EINVAL;
if (args->user_size > dev_priv->gtt.base.total)
return -E2BIG;
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
ret = -ENOMEM;
if ((obj->userptr.mm = get_task_mm(current)))
ret = i915_gem_userptr_init__mmu_notifier(obj, args->flags);
if (ret == 0)
ret = drm_gem_handle_create(file, &obj->base, &handle);
drm_gem_object_unreference_unlocked(&obj->base);
if (ret)
return ret;
args->handle = handle;
return 0;
}
int
i915_gem_init_userptr(struct drm_device *dev)
{
#if defined(CONFIG_MMU_NOTIFIER)
struct drm_i915_private *dev_priv = to_i915(dev);
hash_init(dev_priv->mmu_notifiers);
#endif
return 0;
}
