int radeon_sa_bo_manager_init(struct radeon_device *rdev,
struct radeon_sa_manager *sa_manager,
unsigned size, u32 domain)
{
int r;
sa_manager->bo = NULL;
sa_manager->size = size;
sa_manager->domain = domain;
INIT_LIST_HEAD(&sa_manager->sa_bo);
r = radeon_bo_create(rdev, size, RADEON_GPU_PAGE_SIZE, true,
RADEON_GEM_DOMAIN_CPU, &sa_manager->bo);
if (r) {
dev_err(rdev->dev, "(%d) failed to allocate bo for manager\n", r);
return r;
}
return r;
}
void radeon_sa_bo_manager_fini(struct radeon_device *rdev,
struct radeon_sa_manager *sa_manager)
{
struct radeon_sa_bo *sa_bo, *tmp;
if (!list_empty(&sa_manager->sa_bo)) {
dev_err(rdev->dev, "sa_manager is not empty, clearing anyway\n");
}
list_for_each_entry_safe(sa_bo, tmp, &sa_manager->sa_bo, list) {
list_del_init(&sa_bo->list);
}
radeon_bo_unref(&sa_manager->bo);
sa_manager->size = 0;
}
int radeon_sa_bo_manager_start(struct radeon_device *rdev,
struct radeon_sa_manager *sa_manager)
{
int r;
if (sa_manager->bo == NULL) {
dev_err(rdev->dev, "no bo for sa manager\n");
return -EINVAL;
}
r = radeon_bo_reserve(sa_manager->bo, false);
if (r) {
dev_err(rdev->dev, "(%d) failed to reserve manager bo\n", r);
return r;
}
r = radeon_bo_pin(sa_manager->bo, sa_manager->domain, &sa_manager->gpu_addr);
if (r) {
radeon_bo_unreserve(sa_manager->bo);
dev_err(rdev->dev, "(%d) failed to pin manager bo\n", r);
return r;
}
r = radeon_bo_kmap(sa_manager->bo, &sa_manager->cpu_ptr);
radeon_bo_unreserve(sa_manager->bo);
return r;
}
int radeon_sa_bo_manager_suspend(struct radeon_device *rdev,
struct radeon_sa_manager *sa_manager)
{
int r;
if (sa_manager->bo == NULL) {
dev_err(rdev->dev, "no bo for sa manager\n");
return -EINVAL;
}
r = radeon_bo_reserve(sa_manager->bo, false);
if (!r) {
radeon_bo_kunmap(sa_manager->bo);
radeon_bo_unpin(sa_manager->bo);
radeon_bo_unreserve(sa_manager->bo);
}
return r;
}
int radeon_sa_bo_new(struct radeon_device *rdev,
struct radeon_sa_manager *sa_manager,
struct radeon_sa_bo *sa_bo,
unsigned size, unsigned align)
{
struct radeon_sa_bo *tmp;
struct list_head *head;
unsigned offset = 0, wasted = 0;
BUG_ON(align > RADEON_GPU_PAGE_SIZE);
BUG_ON(size > sa_manager->size);
head = sa_manager->sa_bo.prev;
if (list_empty(&sa_manager->sa_bo)) {
goto out;
}
offset = 0;
list_for_each_entry(tmp, &sa_manager->sa_bo, list) {
if ((tmp->offset - offset) >= size) {
head = tmp->list.prev;
goto out;
}
offset = tmp->offset + tmp->size;
wasted = offset % align;
if (wasted) {
wasted = align - wasted;
}
offset += wasted;
}
head = sa_manager->sa_bo.prev;
tmp = list_entry(head, struct radeon_sa_bo, list);
offset = tmp->offset + tmp->size;
wasted = offset % align;
if (wasted) {
wasted = align - wasted;
}
offset += wasted;
if ((sa_manager->size - offset) < size) {
return -ENOMEM;
}
out:
sa_bo->manager = sa_manager;
sa_bo->offset = offset;
sa_bo->size = size;
list_add(&sa_bo->list, head);
return 0;
}
void radeon_sa_bo_free(struct radeon_device *rdev, struct radeon_sa_bo *sa_bo)
{
list_del_init(&sa_bo->list);
}
