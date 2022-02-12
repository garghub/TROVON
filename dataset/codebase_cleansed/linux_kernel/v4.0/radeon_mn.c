static void radeon_mn_destroy(struct work_struct *work)
{
struct radeon_mn *rmn = container_of(work, struct radeon_mn, work);
struct radeon_device *rdev = rmn->rdev;
struct radeon_bo *bo, *next;
mutex_lock(&rdev->mn_lock);
mutex_lock(&rmn->lock);
hash_del(&rmn->node);
rbtree_postorder_for_each_entry_safe(bo, next, &rmn->objects, mn_it.rb) {
interval_tree_remove(&bo->mn_it, &rmn->objects);
bo->mn = NULL;
}
mutex_unlock(&rmn->lock);
mutex_unlock(&rdev->mn_lock);
mmu_notifier_unregister(&rmn->mn, rmn->mm);
kfree(rmn);
}
static void radeon_mn_release(struct mmu_notifier *mn,
struct mm_struct *mm)
{
struct radeon_mn *rmn = container_of(mn, struct radeon_mn, mn);
INIT_WORK(&rmn->work, radeon_mn_destroy);
schedule_work(&rmn->work);
}
static void radeon_mn_invalidate_range_start(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start,
unsigned long end)
{
struct radeon_mn *rmn = container_of(mn, struct radeon_mn, mn);
struct interval_tree_node *it;
end -= 1;
mutex_lock(&rmn->lock);
it = interval_tree_iter_first(&rmn->objects, start, end);
while (it) {
struct radeon_bo *bo;
int r;
bo = container_of(it, struct radeon_bo, mn_it);
it = interval_tree_iter_next(it, start, end);
r = radeon_bo_reserve(bo, true);
if (r) {
DRM_ERROR("(%d) failed to reserve user bo\n", r);
continue;
}
r = reservation_object_wait_timeout_rcu(bo->tbo.resv, true,
false, MAX_SCHEDULE_TIMEOUT);
if (r)
DRM_ERROR("(%d) failed to wait for user bo\n", r);
radeon_ttm_placement_from_domain(bo, RADEON_GEM_DOMAIN_CPU);
r = ttm_bo_validate(&bo->tbo, &bo->placement, false, false);
if (r)
DRM_ERROR("(%d) failed to validate user bo\n", r);
radeon_bo_unreserve(bo);
}
mutex_unlock(&rmn->lock);
}
static struct radeon_mn *radeon_mn_get(struct radeon_device *rdev)
{
struct mm_struct *mm = current->mm;
struct radeon_mn *rmn;
int r;
down_write(&mm->mmap_sem);
mutex_lock(&rdev->mn_lock);
hash_for_each_possible(rdev->mn_hash, rmn, node, (unsigned long)mm)
if (rmn->mm == mm)
goto release_locks;
rmn = kzalloc(sizeof(*rmn), GFP_KERNEL);
if (!rmn) {
rmn = ERR_PTR(-ENOMEM);
goto release_locks;
}
rmn->rdev = rdev;
rmn->mm = mm;
rmn->mn.ops = &radeon_mn_ops;
mutex_init(&rmn->lock);
rmn->objects = RB_ROOT;
r = __mmu_notifier_register(&rmn->mn, mm);
if (r)
goto free_rmn;
hash_add(rdev->mn_hash, &rmn->node, (unsigned long)mm);
release_locks:
mutex_unlock(&rdev->mn_lock);
up_write(&mm->mmap_sem);
return rmn;
free_rmn:
mutex_unlock(&rdev->mn_lock);
up_write(&mm->mmap_sem);
kfree(rmn);
return ERR_PTR(r);
}
int radeon_mn_register(struct radeon_bo *bo, unsigned long addr)
{
unsigned long end = addr + radeon_bo_size(bo) - 1;
struct radeon_device *rdev = bo->rdev;
struct radeon_mn *rmn;
struct interval_tree_node *it;
rmn = radeon_mn_get(rdev);
if (IS_ERR(rmn))
return PTR_ERR(rmn);
mutex_lock(&rmn->lock);
it = interval_tree_iter_first(&rmn->objects, addr, end);
if (it) {
mutex_unlock(&rmn->lock);
return -EEXIST;
}
bo->mn = rmn;
bo->mn_it.start = addr;
bo->mn_it.last = end;
interval_tree_insert(&bo->mn_it, &rmn->objects);
mutex_unlock(&rmn->lock);
return 0;
}
void radeon_mn_unregister(struct radeon_bo *bo)
{
struct radeon_device *rdev = bo->rdev;
struct radeon_mn *rmn;
mutex_lock(&rdev->mn_lock);
rmn = bo->mn;
if (rmn == NULL) {
mutex_unlock(&rdev->mn_lock);
return;
}
mutex_lock(&rmn->lock);
interval_tree_remove(&bo->mn_it, &rmn->objects);
bo->mn = NULL;
mutex_unlock(&rmn->lock);
mutex_unlock(&rdev->mn_lock);
}
