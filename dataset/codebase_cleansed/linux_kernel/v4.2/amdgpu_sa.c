int amdgpu_sa_bo_manager_init(struct amdgpu_device *adev,
struct amdgpu_sa_manager *sa_manager,
unsigned size, u32 align, u32 domain)
{
int i, r;
init_waitqueue_head(&sa_manager->wq);
sa_manager->bo = NULL;
sa_manager->size = size;
sa_manager->domain = domain;
sa_manager->align = align;
sa_manager->hole = &sa_manager->olist;
INIT_LIST_HEAD(&sa_manager->olist);
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
INIT_LIST_HEAD(&sa_manager->flist[i]);
}
r = amdgpu_bo_create(adev, size, align, true,
domain, 0, NULL, &sa_manager->bo);
if (r) {
dev_err(adev->dev, "(%d) failed to allocate bo for manager\n", r);
return r;
}
return r;
}
void amdgpu_sa_bo_manager_fini(struct amdgpu_device *adev,
struct amdgpu_sa_manager *sa_manager)
{
struct amdgpu_sa_bo *sa_bo, *tmp;
if (!list_empty(&sa_manager->olist)) {
sa_manager->hole = &sa_manager->olist,
amdgpu_sa_bo_try_free(sa_manager);
if (!list_empty(&sa_manager->olist)) {
dev_err(adev->dev, "sa_manager is not empty, clearing anyway\n");
}
}
list_for_each_entry_safe(sa_bo, tmp, &sa_manager->olist, olist) {
amdgpu_sa_bo_remove_locked(sa_bo);
}
amdgpu_bo_unref(&sa_manager->bo);
sa_manager->size = 0;
}
int amdgpu_sa_bo_manager_start(struct amdgpu_device *adev,
struct amdgpu_sa_manager *sa_manager)
{
int r;
if (sa_manager->bo == NULL) {
dev_err(adev->dev, "no bo for sa manager\n");
return -EINVAL;
}
r = amdgpu_bo_reserve(sa_manager->bo, false);
if (r) {
dev_err(adev->dev, "(%d) failed to reserve manager bo\n", r);
return r;
}
r = amdgpu_bo_pin(sa_manager->bo, sa_manager->domain, &sa_manager->gpu_addr);
if (r) {
amdgpu_bo_unreserve(sa_manager->bo);
dev_err(adev->dev, "(%d) failed to pin manager bo\n", r);
return r;
}
r = amdgpu_bo_kmap(sa_manager->bo, &sa_manager->cpu_ptr);
amdgpu_bo_unreserve(sa_manager->bo);
return r;
}
int amdgpu_sa_bo_manager_suspend(struct amdgpu_device *adev,
struct amdgpu_sa_manager *sa_manager)
{
int r;
if (sa_manager->bo == NULL) {
dev_err(adev->dev, "no bo for sa manager\n");
return -EINVAL;
}
r = amdgpu_bo_reserve(sa_manager->bo, false);
if (!r) {
amdgpu_bo_kunmap(sa_manager->bo);
amdgpu_bo_unpin(sa_manager->bo);
amdgpu_bo_unreserve(sa_manager->bo);
}
return r;
}
static void amdgpu_sa_bo_remove_locked(struct amdgpu_sa_bo *sa_bo)
{
struct amdgpu_sa_manager *sa_manager = sa_bo->manager;
if (sa_manager->hole == &sa_bo->olist) {
sa_manager->hole = sa_bo->olist.prev;
}
list_del_init(&sa_bo->olist);
list_del_init(&sa_bo->flist);
amdgpu_fence_unref(&sa_bo->fence);
kfree(sa_bo);
}
static void amdgpu_sa_bo_try_free(struct amdgpu_sa_manager *sa_manager)
{
struct amdgpu_sa_bo *sa_bo, *tmp;
if (sa_manager->hole->next == &sa_manager->olist)
return;
sa_bo = list_entry(sa_manager->hole->next, struct amdgpu_sa_bo, olist);
list_for_each_entry_safe_from(sa_bo, tmp, &sa_manager->olist, olist) {
if (sa_bo->fence == NULL || !amdgpu_fence_signaled(sa_bo->fence)) {
return;
}
amdgpu_sa_bo_remove_locked(sa_bo);
}
}
static inline unsigned amdgpu_sa_bo_hole_soffset(struct amdgpu_sa_manager *sa_manager)
{
struct list_head *hole = sa_manager->hole;
if (hole != &sa_manager->olist) {
return list_entry(hole, struct amdgpu_sa_bo, olist)->eoffset;
}
return 0;
}
static inline unsigned amdgpu_sa_bo_hole_eoffset(struct amdgpu_sa_manager *sa_manager)
{
struct list_head *hole = sa_manager->hole;
if (hole->next != &sa_manager->olist) {
return list_entry(hole->next, struct amdgpu_sa_bo, olist)->soffset;
}
return sa_manager->size;
}
static bool amdgpu_sa_bo_try_alloc(struct amdgpu_sa_manager *sa_manager,
struct amdgpu_sa_bo *sa_bo,
unsigned size, unsigned align)
{
unsigned soffset, eoffset, wasted;
soffset = amdgpu_sa_bo_hole_soffset(sa_manager);
eoffset = amdgpu_sa_bo_hole_eoffset(sa_manager);
wasted = (align - (soffset % align)) % align;
if ((eoffset - soffset) >= (size + wasted)) {
soffset += wasted;
sa_bo->manager = sa_manager;
sa_bo->soffset = soffset;
sa_bo->eoffset = soffset + size;
list_add(&sa_bo->olist, sa_manager->hole);
INIT_LIST_HEAD(&sa_bo->flist);
sa_manager->hole = &sa_bo->olist;
return true;
}
return false;
}
static bool amdgpu_sa_event(struct amdgpu_sa_manager *sa_manager,
unsigned size, unsigned align)
{
unsigned soffset, eoffset, wasted;
int i;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
if (!list_empty(&sa_manager->flist[i])) {
return true;
}
}
soffset = amdgpu_sa_bo_hole_soffset(sa_manager);
eoffset = amdgpu_sa_bo_hole_eoffset(sa_manager);
wasted = (align - (soffset % align)) % align;
if ((eoffset - soffset) >= (size + wasted)) {
return true;
}
return false;
}
static bool amdgpu_sa_bo_next_hole(struct amdgpu_sa_manager *sa_manager,
struct amdgpu_fence **fences,
unsigned *tries)
{
struct amdgpu_sa_bo *best_bo = NULL;
unsigned i, soffset, best, tmp;
if (sa_manager->hole->next == &sa_manager->olist) {
sa_manager->hole = &sa_manager->olist;
return true;
}
soffset = amdgpu_sa_bo_hole_soffset(sa_manager);
best = sa_manager->size * 2;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
struct amdgpu_sa_bo *sa_bo;
if (list_empty(&sa_manager->flist[i])) {
continue;
}
sa_bo = list_first_entry(&sa_manager->flist[i],
struct amdgpu_sa_bo, flist);
if (!amdgpu_fence_signaled(sa_bo->fence)) {
fences[i] = sa_bo->fence;
continue;
}
if (tries[i] > 2) {
continue;
}
tmp = sa_bo->soffset;
if (tmp < soffset) {
tmp += sa_manager->size;
}
tmp -= soffset;
if (tmp < best) {
best = tmp;
best_bo = sa_bo;
}
}
if (best_bo) {
++tries[best_bo->fence->ring->idx];
sa_manager->hole = best_bo->olist.prev;
amdgpu_sa_bo_remove_locked(best_bo);
return true;
}
return false;
}
int amdgpu_sa_bo_new(struct amdgpu_device *adev,
struct amdgpu_sa_manager *sa_manager,
struct amdgpu_sa_bo **sa_bo,
unsigned size, unsigned align)
{
struct amdgpu_fence *fences[AMDGPU_MAX_RINGS];
unsigned tries[AMDGPU_MAX_RINGS];
int i, r;
BUG_ON(align > sa_manager->align);
BUG_ON(size > sa_manager->size);
*sa_bo = kmalloc(sizeof(struct amdgpu_sa_bo), GFP_KERNEL);
if ((*sa_bo) == NULL) {
return -ENOMEM;
}
(*sa_bo)->manager = sa_manager;
(*sa_bo)->fence = NULL;
INIT_LIST_HEAD(&(*sa_bo)->olist);
INIT_LIST_HEAD(&(*sa_bo)->flist);
spin_lock(&sa_manager->wq.lock);
do {
for (i = 0; i < AMDGPU_MAX_RINGS; ++i) {
fences[i] = NULL;
tries[i] = 0;
}
do {
amdgpu_sa_bo_try_free(sa_manager);
if (amdgpu_sa_bo_try_alloc(sa_manager, *sa_bo,
size, align)) {
spin_unlock(&sa_manager->wq.lock);
return 0;
}
} while (amdgpu_sa_bo_next_hole(sa_manager, fences, tries));
spin_unlock(&sa_manager->wq.lock);
r = amdgpu_fence_wait_any(adev, fences, false);
spin_lock(&sa_manager->wq.lock);
if (r == -ENOENT) {
r = wait_event_interruptible_locked(
sa_manager->wq,
amdgpu_sa_event(sa_manager, size, align)
);
}
} while (!r);
spin_unlock(&sa_manager->wq.lock);
kfree(*sa_bo);
*sa_bo = NULL;
return r;
}
void amdgpu_sa_bo_free(struct amdgpu_device *adev, struct amdgpu_sa_bo **sa_bo,
struct amdgpu_fence *fence)
{
struct amdgpu_sa_manager *sa_manager;
if (sa_bo == NULL || *sa_bo == NULL) {
return;
}
sa_manager = (*sa_bo)->manager;
spin_lock(&sa_manager->wq.lock);
if (fence && !amdgpu_fence_signaled(fence)) {
(*sa_bo)->fence = amdgpu_fence_ref(fence);
list_add_tail(&(*sa_bo)->flist,
&sa_manager->flist[fence->ring->idx]);
} else {
amdgpu_sa_bo_remove_locked(*sa_bo);
}
wake_up_all_locked(&sa_manager->wq);
spin_unlock(&sa_manager->wq.lock);
*sa_bo = NULL;
}
void amdgpu_sa_bo_dump_debug_info(struct amdgpu_sa_manager *sa_manager,
struct seq_file *m)
{
struct amdgpu_sa_bo *i;
spin_lock(&sa_manager->wq.lock);
list_for_each_entry(i, &sa_manager->olist, olist) {
uint64_t soffset = i->soffset + sa_manager->gpu_addr;
uint64_t eoffset = i->eoffset + sa_manager->gpu_addr;
if (&i->olist == sa_manager->hole) {
seq_printf(m, ">");
} else {
seq_printf(m, " ");
}
seq_printf(m, "[0x%010llx 0x%010llx] size %8lld",
soffset, eoffset, eoffset - soffset);
if (i->fence) {
seq_printf(m, " protected by 0x%016llx on ring %d",
i->fence->seq, i->fence->ring->idx);
}
seq_printf(m, "\n");
}
spin_unlock(&sa_manager->wq.lock);
}
