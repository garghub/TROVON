static void amdgpu_mn_destroy(struct work_struct *work)
{
struct amdgpu_mn *rmn = container_of(work, struct amdgpu_mn, work);
struct amdgpu_device *adev = rmn->adev;
struct amdgpu_mn_node *node, *next_node;
struct amdgpu_bo *bo, *next_bo;
mutex_lock(&adev->mn_lock);
mutex_lock(&rmn->lock);
hash_del(&rmn->node);
rbtree_postorder_for_each_entry_safe(node, next_node, &rmn->objects,
it.rb) {
list_for_each_entry_safe(bo, next_bo, &node->bos, mn_list) {
bo->mn = NULL;
list_del_init(&bo->mn_list);
}
kfree(node);
}
mutex_unlock(&rmn->lock);
mutex_unlock(&adev->mn_lock);
mmu_notifier_unregister_no_release(&rmn->mn, rmn->mm);
kfree(rmn);
}
static void amdgpu_mn_release(struct mmu_notifier *mn,
struct mm_struct *mm)
{
struct amdgpu_mn *rmn = container_of(mn, struct amdgpu_mn, mn);
INIT_WORK(&rmn->work, amdgpu_mn_destroy);
schedule_work(&rmn->work);
}
static void amdgpu_mn_invalidate_node(struct amdgpu_mn_node *node,
unsigned long start,
unsigned long end)
{
struct amdgpu_bo *bo;
long r;
list_for_each_entry(bo, &node->bos, mn_list) {
if (!amdgpu_ttm_tt_affect_userptr(bo->tbo.ttm, start, end))
continue;
r = amdgpu_bo_reserve(bo, true);
if (r) {
DRM_ERROR("(%ld) failed to reserve user bo\n", r);
continue;
}
r = reservation_object_wait_timeout_rcu(bo->tbo.resv,
true, false, MAX_SCHEDULE_TIMEOUT);
if (r <= 0)
DRM_ERROR("(%ld) failed to wait for user bo\n", r);
amdgpu_ttm_placement_from_domain(bo, AMDGPU_GEM_DOMAIN_CPU);
r = ttm_bo_validate(&bo->tbo, &bo->placement, false, false);
if (r)
DRM_ERROR("(%ld) failed to validate user bo\n", r);
amdgpu_bo_unreserve(bo);
}
}
static void amdgpu_mn_invalidate_page(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long address)
{
struct amdgpu_mn *rmn = container_of(mn, struct amdgpu_mn, mn);
struct interval_tree_node *it;
mutex_lock(&rmn->lock);
it = interval_tree_iter_first(&rmn->objects, address, address);
if (it) {
struct amdgpu_mn_node *node;
node = container_of(it, struct amdgpu_mn_node, it);
amdgpu_mn_invalidate_node(node, address, address);
}
mutex_unlock(&rmn->lock);
}
static void amdgpu_mn_invalidate_range_start(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start,
unsigned long end)
{
struct amdgpu_mn *rmn = container_of(mn, struct amdgpu_mn, mn);
struct interval_tree_node *it;
end -= 1;
mutex_lock(&rmn->lock);
it = interval_tree_iter_first(&rmn->objects, start, end);
while (it) {
struct amdgpu_mn_node *node;
node = container_of(it, struct amdgpu_mn_node, it);
it = interval_tree_iter_next(it, start, end);
amdgpu_mn_invalidate_node(node, start, end);
}
mutex_unlock(&rmn->lock);
}
static struct amdgpu_mn *amdgpu_mn_get(struct amdgpu_device *adev)
{
struct mm_struct *mm = current->mm;
struct amdgpu_mn *rmn;
int r;
mutex_lock(&adev->mn_lock);
down_write(&mm->mmap_sem);
hash_for_each_possible(adev->mn_hash, rmn, node, (unsigned long)mm)
if (rmn->mm == mm)
goto release_locks;
rmn = kzalloc(sizeof(*rmn), GFP_KERNEL);
if (!rmn) {
rmn = ERR_PTR(-ENOMEM);
goto release_locks;
}
rmn->adev = adev;
rmn->mm = mm;
rmn->mn.ops = &amdgpu_mn_ops;
mutex_init(&rmn->lock);
rmn->objects = RB_ROOT;
r = __mmu_notifier_register(&rmn->mn, mm);
if (r)
goto free_rmn;
hash_add(adev->mn_hash, &rmn->node, (unsigned long)mm);
release_locks:
up_write(&mm->mmap_sem);
mutex_unlock(&adev->mn_lock);
return rmn;
free_rmn:
up_write(&mm->mmap_sem);
mutex_unlock(&adev->mn_lock);
kfree(rmn);
return ERR_PTR(r);
}
int amdgpu_mn_register(struct amdgpu_bo *bo, unsigned long addr)
{
unsigned long end = addr + amdgpu_bo_size(bo) - 1;
struct amdgpu_device *adev = bo->adev;
struct amdgpu_mn *rmn;
struct amdgpu_mn_node *node = NULL;
struct list_head bos;
struct interval_tree_node *it;
rmn = amdgpu_mn_get(adev);
if (IS_ERR(rmn))
return PTR_ERR(rmn);
INIT_LIST_HEAD(&bos);
mutex_lock(&rmn->lock);
while ((it = interval_tree_iter_first(&rmn->objects, addr, end))) {
kfree(node);
node = container_of(it, struct amdgpu_mn_node, it);
interval_tree_remove(&node->it, &rmn->objects);
addr = min(it->start, addr);
end = max(it->last, end);
list_splice(&node->bos, &bos);
}
if (!node) {
node = kmalloc(sizeof(struct amdgpu_mn_node), GFP_KERNEL);
if (!node) {
mutex_unlock(&rmn->lock);
return -ENOMEM;
}
}
bo->mn = rmn;
node->it.start = addr;
node->it.last = end;
INIT_LIST_HEAD(&node->bos);
list_splice(&bos, &node->bos);
list_add(&bo->mn_list, &node->bos);
interval_tree_insert(&node->it, &rmn->objects);
mutex_unlock(&rmn->lock);
return 0;
}
void amdgpu_mn_unregister(struct amdgpu_bo *bo)
{
struct amdgpu_device *adev = bo->adev;
struct amdgpu_mn *rmn;
struct list_head *head;
mutex_lock(&adev->mn_lock);
rmn = bo->mn;
if (rmn == NULL) {
mutex_unlock(&adev->mn_lock);
return;
}
mutex_lock(&rmn->lock);
head = bo->mn_list.next;
bo->mn = NULL;
list_del(&bo->mn_list);
if (list_empty(head)) {
struct amdgpu_mn_node *node;
node = container_of(head, struct amdgpu_mn_node, bos);
interval_tree_remove(&node->it, &rmn->objects);
kfree(node);
}
mutex_unlock(&rmn->lock);
mutex_unlock(&adev->mn_lock);
}
