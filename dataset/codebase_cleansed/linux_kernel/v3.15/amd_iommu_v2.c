static u16 device_id(struct pci_dev *pdev)
{
u16 devid;
devid = pdev->bus->number;
devid = (devid << 8) | pdev->devfn;
return devid;
}
static struct device_state *get_device_state(u16 devid)
{
struct device_state *dev_state;
unsigned long flags;
spin_lock_irqsave(&state_lock, flags);
dev_state = state_table[devid];
if (dev_state != NULL)
atomic_inc(&dev_state->count);
spin_unlock_irqrestore(&state_lock, flags);
return dev_state;
}
static void free_device_state(struct device_state *dev_state)
{
iommu_detach_device(dev_state->domain, &dev_state->pdev->dev);
iommu_domain_free(dev_state->domain);
kfree(dev_state);
}
static void put_device_state(struct device_state *dev_state)
{
if (atomic_dec_and_test(&dev_state->count))
wake_up(&dev_state->wq);
}
static void put_device_state_wait(struct device_state *dev_state)
{
DEFINE_WAIT(wait);
prepare_to_wait(&dev_state->wq, &wait, TASK_UNINTERRUPTIBLE);
if (!atomic_dec_and_test(&dev_state->count))
schedule();
finish_wait(&dev_state->wq, &wait);
free_device_state(dev_state);
}
static void link_pasid_state(struct pasid_state *pasid_state)
{
spin_lock(&ps_lock);
list_add_tail(&pasid_state->list, &pasid_state_list);
spin_unlock(&ps_lock);
}
static void __unlink_pasid_state(struct pasid_state *pasid_state)
{
list_del(&pasid_state->list);
}
static void unlink_pasid_state(struct pasid_state *pasid_state)
{
spin_lock(&ps_lock);
__unlink_pasid_state(pasid_state);
spin_unlock(&ps_lock);
}
static struct pasid_state **__get_pasid_state_ptr(struct device_state *dev_state,
int pasid, bool alloc)
{
struct pasid_state **root, **ptr;
int level, index;
level = dev_state->pasid_levels;
root = dev_state->states;
while (true) {
index = (pasid >> (9 * level)) & 0x1ff;
ptr = &root[index];
if (level == 0)
break;
if (*ptr == NULL) {
if (!alloc)
return NULL;
*ptr = (void *)get_zeroed_page(GFP_ATOMIC);
if (*ptr == NULL)
return NULL;
}
root = (struct pasid_state **)*ptr;
level -= 1;
}
return ptr;
}
static int set_pasid_state(struct device_state *dev_state,
struct pasid_state *pasid_state,
int pasid)
{
struct pasid_state **ptr;
unsigned long flags;
int ret;
spin_lock_irqsave(&dev_state->lock, flags);
ptr = __get_pasid_state_ptr(dev_state, pasid, true);
ret = -ENOMEM;
if (ptr == NULL)
goto out_unlock;
ret = -ENOMEM;
if (*ptr != NULL)
goto out_unlock;
*ptr = pasid_state;
ret = 0;
out_unlock:
spin_unlock_irqrestore(&dev_state->lock, flags);
return ret;
}
static void clear_pasid_state(struct device_state *dev_state, int pasid)
{
struct pasid_state **ptr;
unsigned long flags;
spin_lock_irqsave(&dev_state->lock, flags);
ptr = __get_pasid_state_ptr(dev_state, pasid, true);
if (ptr == NULL)
goto out_unlock;
*ptr = NULL;
out_unlock:
spin_unlock_irqrestore(&dev_state->lock, flags);
}
static struct pasid_state *get_pasid_state(struct device_state *dev_state,
int pasid)
{
struct pasid_state **ptr, *ret = NULL;
unsigned long flags;
spin_lock_irqsave(&dev_state->lock, flags);
ptr = __get_pasid_state_ptr(dev_state, pasid, false);
if (ptr == NULL)
goto out_unlock;
ret = *ptr;
if (ret)
atomic_inc(&ret->count);
out_unlock:
spin_unlock_irqrestore(&dev_state->lock, flags);
return ret;
}
static void free_pasid_state(struct pasid_state *pasid_state)
{
kfree(pasid_state);
}
static void put_pasid_state(struct pasid_state *pasid_state)
{
if (atomic_dec_and_test(&pasid_state->count)) {
put_device_state(pasid_state->device_state);
wake_up(&pasid_state->wq);
}
}
static void put_pasid_state_wait(struct pasid_state *pasid_state)
{
DEFINE_WAIT(wait);
prepare_to_wait(&pasid_state->wq, &wait, TASK_UNINTERRUPTIBLE);
if (atomic_dec_and_test(&pasid_state->count))
put_device_state(pasid_state->device_state);
else
schedule();
finish_wait(&pasid_state->wq, &wait);
mmput(pasid_state->mm);
free_pasid_state(pasid_state);
}
static void __unbind_pasid(struct pasid_state *pasid_state)
{
struct iommu_domain *domain;
domain = pasid_state->device_state->domain;
amd_iommu_domain_clear_gcr3(domain, pasid_state->pasid);
clear_pasid_state(pasid_state->device_state, pasid_state->pasid);
flush_workqueue(iommu_wq);
mmu_notifier_unregister(&pasid_state->mn, pasid_state->mm);
put_pasid_state(pasid_state);
}
static void unbind_pasid(struct device_state *dev_state, int pasid)
{
struct pasid_state *pasid_state;
pasid_state = get_pasid_state(dev_state, pasid);
if (pasid_state == NULL)
return;
unlink_pasid_state(pasid_state);
__unbind_pasid(pasid_state);
put_pasid_state_wait(pasid_state);
}
static void free_pasid_states_level1(struct pasid_state **tbl)
{
int i;
for (i = 0; i < 512; ++i) {
if (tbl[i] == NULL)
continue;
free_page((unsigned long)tbl[i]);
}
}
static void free_pasid_states_level2(struct pasid_state **tbl)
{
struct pasid_state **ptr;
int i;
for (i = 0; i < 512; ++i) {
if (tbl[i] == NULL)
continue;
ptr = (struct pasid_state **)tbl[i];
free_pasid_states_level1(ptr);
}
}
static void free_pasid_states(struct device_state *dev_state)
{
struct pasid_state *pasid_state;
int i;
for (i = 0; i < dev_state->max_pasids; ++i) {
pasid_state = get_pasid_state(dev_state, i);
if (pasid_state == NULL)
continue;
put_pasid_state(pasid_state);
unbind_pasid(dev_state, i);
}
if (dev_state->pasid_levels == 2)
free_pasid_states_level2(dev_state->states);
else if (dev_state->pasid_levels == 1)
free_pasid_states_level1(dev_state->states);
else if (dev_state->pasid_levels != 0)
BUG();
free_page((unsigned long)dev_state->states);
}
static struct pasid_state *mn_to_state(struct mmu_notifier *mn)
{
return container_of(mn, struct pasid_state, mn);
}
static void __mn_flush_page(struct mmu_notifier *mn,
unsigned long address)
{
struct pasid_state *pasid_state;
struct device_state *dev_state;
pasid_state = mn_to_state(mn);
dev_state = pasid_state->device_state;
amd_iommu_flush_page(dev_state->domain, pasid_state->pasid, address);
}
static int mn_clear_flush_young(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long address)
{
__mn_flush_page(mn, address);
return 0;
}
static void mn_change_pte(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long address,
pte_t pte)
{
__mn_flush_page(mn, address);
}
static void mn_invalidate_page(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long address)
{
__mn_flush_page(mn, address);
}
static void mn_invalidate_range_start(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start, unsigned long end)
{
struct pasid_state *pasid_state;
struct device_state *dev_state;
pasid_state = mn_to_state(mn);
dev_state = pasid_state->device_state;
amd_iommu_domain_set_gcr3(dev_state->domain, pasid_state->pasid,
__pa(empty_page_table));
}
static void mn_invalidate_range_end(struct mmu_notifier *mn,
struct mm_struct *mm,
unsigned long start, unsigned long end)
{
struct pasid_state *pasid_state;
struct device_state *dev_state;
pasid_state = mn_to_state(mn);
dev_state = pasid_state->device_state;
amd_iommu_domain_set_gcr3(dev_state->domain, pasid_state->pasid,
__pa(pasid_state->mm->pgd));
}
static void set_pri_tag_status(struct pasid_state *pasid_state,
u16 tag, int status)
{
unsigned long flags;
spin_lock_irqsave(&pasid_state->lock, flags);
pasid_state->pri[tag].status = status;
spin_unlock_irqrestore(&pasid_state->lock, flags);
}
static void finish_pri_tag(struct device_state *dev_state,
struct pasid_state *pasid_state,
u16 tag)
{
unsigned long flags;
spin_lock_irqsave(&pasid_state->lock, flags);
if (atomic_dec_and_test(&pasid_state->pri[tag].inflight) &&
pasid_state->pri[tag].finish) {
amd_iommu_complete_ppr(dev_state->pdev, pasid_state->pasid,
pasid_state->pri[tag].status, tag);
pasid_state->pri[tag].finish = false;
pasid_state->pri[tag].status = PPR_SUCCESS;
}
spin_unlock_irqrestore(&pasid_state->lock, flags);
}
static void do_fault(struct work_struct *work)
{
struct fault *fault = container_of(work, struct fault, work);
int npages, write;
struct page *page;
write = !!(fault->flags & PPR_FAULT_WRITE);
down_read(&fault->state->mm->mmap_sem);
npages = get_user_pages(fault->state->task, fault->state->mm,
fault->address, 1, write, 0, &page, NULL);
up_read(&fault->state->mm->mmap_sem);
if (npages == 1) {
put_page(page);
} else if (fault->dev_state->inv_ppr_cb) {
int status;
status = fault->dev_state->inv_ppr_cb(fault->dev_state->pdev,
fault->pasid,
fault->address,
fault->flags);
switch (status) {
case AMD_IOMMU_INV_PRI_RSP_SUCCESS:
set_pri_tag_status(fault->state, fault->tag, PPR_SUCCESS);
break;
case AMD_IOMMU_INV_PRI_RSP_INVALID:
set_pri_tag_status(fault->state, fault->tag, PPR_INVALID);
break;
case AMD_IOMMU_INV_PRI_RSP_FAIL:
set_pri_tag_status(fault->state, fault->tag, PPR_FAILURE);
break;
default:
BUG();
}
} else {
set_pri_tag_status(fault->state, fault->tag, PPR_INVALID);
}
finish_pri_tag(fault->dev_state, fault->state, fault->tag);
put_pasid_state(fault->state);
kfree(fault);
}
static int ppr_notifier(struct notifier_block *nb, unsigned long e, void *data)
{
struct amd_iommu_fault *iommu_fault;
struct pasid_state *pasid_state;
struct device_state *dev_state;
unsigned long flags;
struct fault *fault;
bool finish;
u16 tag;
int ret;
iommu_fault = data;
tag = iommu_fault->tag & 0x1ff;
finish = (iommu_fault->tag >> 9) & 1;
ret = NOTIFY_DONE;
dev_state = get_device_state(iommu_fault->device_id);
if (dev_state == NULL)
goto out;
pasid_state = get_pasid_state(dev_state, iommu_fault->pasid);
if (pasid_state == NULL) {
amd_iommu_complete_ppr(dev_state->pdev, iommu_fault->pasid,
PPR_INVALID, tag);
goto out_drop_state;
}
spin_lock_irqsave(&pasid_state->lock, flags);
atomic_inc(&pasid_state->pri[tag].inflight);
if (finish)
pasid_state->pri[tag].finish = true;
spin_unlock_irqrestore(&pasid_state->lock, flags);
fault = kzalloc(sizeof(*fault), GFP_ATOMIC);
if (fault == NULL) {
finish_pri_tag(dev_state, pasid_state, tag);
goto out_drop_state;
}
fault->dev_state = dev_state;
fault->address = iommu_fault->address;
fault->state = pasid_state;
fault->tag = tag;
fault->finish = finish;
fault->flags = iommu_fault->flags;
INIT_WORK(&fault->work, do_fault);
queue_work(iommu_wq, &fault->work);
ret = NOTIFY_OK;
out_drop_state:
put_device_state(dev_state);
out:
return ret;
}
static int task_exit(struct notifier_block *nb, unsigned long e, void *data)
{
struct pasid_state *pasid_state;
struct task_struct *task;
task = data;
again:
spin_lock(&ps_lock);
list_for_each_entry(pasid_state, &pasid_state_list, list) {
struct device_state *dev_state;
int pasid;
if (pasid_state->task != task)
continue;
spin_unlock(&ps_lock);
dev_state = pasid_state->device_state;
pasid = pasid_state->pasid;
if (pasid_state->device_state->inv_ctx_cb)
dev_state->inv_ctx_cb(dev_state->pdev, pasid);
unbind_pasid(dev_state, pasid);
goto again;
}
spin_unlock(&ps_lock);
return NOTIFY_OK;
}
int amd_iommu_bind_pasid(struct pci_dev *pdev, int pasid,
struct task_struct *task)
{
struct pasid_state *pasid_state;
struct device_state *dev_state;
u16 devid;
int ret;
might_sleep();
if (!amd_iommu_v2_supported())
return -ENODEV;
devid = device_id(pdev);
dev_state = get_device_state(devid);
if (dev_state == NULL)
return -EINVAL;
ret = -EINVAL;
if (pasid < 0 || pasid >= dev_state->max_pasids)
goto out;
ret = -ENOMEM;
pasid_state = kzalloc(sizeof(*pasid_state), GFP_KERNEL);
if (pasid_state == NULL)
goto out;
atomic_set(&pasid_state->count, 1);
init_waitqueue_head(&pasid_state->wq);
spin_lock_init(&pasid_state->lock);
pasid_state->task = task;
pasid_state->mm = get_task_mm(task);
pasid_state->device_state = dev_state;
pasid_state->pasid = pasid;
pasid_state->mn.ops = &iommu_mn;
if (pasid_state->mm == NULL)
goto out_free;
mmu_notifier_register(&pasid_state->mn, pasid_state->mm);
ret = set_pasid_state(dev_state, pasid_state, pasid);
if (ret)
goto out_unregister;
ret = amd_iommu_domain_set_gcr3(dev_state->domain, pasid,
__pa(pasid_state->mm->pgd));
if (ret)
goto out_clear_state;
link_pasid_state(pasid_state);
return 0;
out_clear_state:
clear_pasid_state(dev_state, pasid);
out_unregister:
mmu_notifier_unregister(&pasid_state->mn, pasid_state->mm);
out_free:
free_pasid_state(pasid_state);
out:
put_device_state(dev_state);
return ret;
}
void amd_iommu_unbind_pasid(struct pci_dev *pdev, int pasid)
{
struct device_state *dev_state;
u16 devid;
might_sleep();
if (!amd_iommu_v2_supported())
return;
devid = device_id(pdev);
dev_state = get_device_state(devid);
if (dev_state == NULL)
return;
if (pasid < 0 || pasid >= dev_state->max_pasids)
goto out;
unbind_pasid(dev_state, pasid);
out:
put_device_state(dev_state);
}
int amd_iommu_init_device(struct pci_dev *pdev, int pasids)
{
struct device_state *dev_state;
unsigned long flags;
int ret, tmp;
u16 devid;
might_sleep();
if (!amd_iommu_v2_supported())
return -ENODEV;
if (pasids <= 0 || pasids > (PASID_MASK + 1))
return -EINVAL;
devid = device_id(pdev);
dev_state = kzalloc(sizeof(*dev_state), GFP_KERNEL);
if (dev_state == NULL)
return -ENOMEM;
spin_lock_init(&dev_state->lock);
init_waitqueue_head(&dev_state->wq);
dev_state->pdev = pdev;
tmp = pasids;
for (dev_state->pasid_levels = 0; (tmp - 1) & ~0x1ff; tmp >>= 9)
dev_state->pasid_levels += 1;
atomic_set(&dev_state->count, 1);
dev_state->max_pasids = pasids;
ret = -ENOMEM;
dev_state->states = (void *)get_zeroed_page(GFP_KERNEL);
if (dev_state->states == NULL)
goto out_free_dev_state;
dev_state->domain = iommu_domain_alloc(&pci_bus_type);
if (dev_state->domain == NULL)
goto out_free_states;
amd_iommu_domain_direct_map(dev_state->domain);
ret = amd_iommu_domain_enable_v2(dev_state->domain, pasids);
if (ret)
goto out_free_domain;
ret = iommu_attach_device(dev_state->domain, &pdev->dev);
if (ret != 0)
goto out_free_domain;
spin_lock_irqsave(&state_lock, flags);
if (state_table[devid] != NULL) {
spin_unlock_irqrestore(&state_lock, flags);
ret = -EBUSY;
goto out_free_domain;
}
state_table[devid] = dev_state;
spin_unlock_irqrestore(&state_lock, flags);
return 0;
out_free_domain:
iommu_domain_free(dev_state->domain);
out_free_states:
free_page((unsigned long)dev_state->states);
out_free_dev_state:
kfree(dev_state);
return ret;
}
void amd_iommu_free_device(struct pci_dev *pdev)
{
struct device_state *dev_state;
unsigned long flags;
u16 devid;
if (!amd_iommu_v2_supported())
return;
devid = device_id(pdev);
spin_lock_irqsave(&state_lock, flags);
dev_state = state_table[devid];
if (dev_state == NULL) {
spin_unlock_irqrestore(&state_lock, flags);
return;
}
state_table[devid] = NULL;
spin_unlock_irqrestore(&state_lock, flags);
free_pasid_states(dev_state);
put_device_state_wait(dev_state);
}
int amd_iommu_set_invalid_ppr_cb(struct pci_dev *pdev,
amd_iommu_invalid_ppr_cb cb)
{
struct device_state *dev_state;
unsigned long flags;
u16 devid;
int ret;
if (!amd_iommu_v2_supported())
return -ENODEV;
devid = device_id(pdev);
spin_lock_irqsave(&state_lock, flags);
ret = -EINVAL;
dev_state = state_table[devid];
if (dev_state == NULL)
goto out_unlock;
dev_state->inv_ppr_cb = cb;
ret = 0;
out_unlock:
spin_unlock_irqrestore(&state_lock, flags);
return ret;
}
int amd_iommu_set_invalidate_ctx_cb(struct pci_dev *pdev,
amd_iommu_invalidate_ctx cb)
{
struct device_state *dev_state;
unsigned long flags;
u16 devid;
int ret;
if (!amd_iommu_v2_supported())
return -ENODEV;
devid = device_id(pdev);
spin_lock_irqsave(&state_lock, flags);
ret = -EINVAL;
dev_state = state_table[devid];
if (dev_state == NULL)
goto out_unlock;
dev_state->inv_ctx_cb = cb;
ret = 0;
out_unlock:
spin_unlock_irqrestore(&state_lock, flags);
return ret;
}
static int __init amd_iommu_v2_init(void)
{
size_t state_table_size;
int ret;
pr_info("AMD IOMMUv2 driver by Joerg Roedel <joerg.roedel@amd.com>\n");
if (!amd_iommu_v2_supported()) {
pr_info("AMD IOMMUv2 functionality not available on this system\n");
return 0;
}
spin_lock_init(&state_lock);
state_table_size = MAX_DEVICES * sizeof(struct device_state *);
state_table = (void *)__get_free_pages(GFP_KERNEL | __GFP_ZERO,
get_order(state_table_size));
if (state_table == NULL)
return -ENOMEM;
ret = -ENOMEM;
iommu_wq = create_workqueue("amd_iommu_v2");
if (iommu_wq == NULL)
goto out_free;
ret = -ENOMEM;
empty_page_table = (u64 *)get_zeroed_page(GFP_KERNEL);
if (empty_page_table == NULL)
goto out_destroy_wq;
amd_iommu_register_ppr_notifier(&ppr_nb);
profile_event_register(PROFILE_TASK_EXIT, &profile_nb);
return 0;
out_destroy_wq:
destroy_workqueue(iommu_wq);
out_free:
free_pages((unsigned long)state_table, get_order(state_table_size));
return ret;
}
static void __exit amd_iommu_v2_exit(void)
{
struct device_state *dev_state;
size_t state_table_size;
int i;
if (!amd_iommu_v2_supported())
return;
profile_event_unregister(PROFILE_TASK_EXIT, &profile_nb);
amd_iommu_unregister_ppr_notifier(&ppr_nb);
flush_workqueue(iommu_wq);
for (i = 0; i < MAX_DEVICES; ++i) {
dev_state = get_device_state(i);
if (dev_state == NULL)
continue;
WARN_ON_ONCE(1);
put_device_state(dev_state);
amd_iommu_free_device(dev_state->pdev);
}
destroy_workqueue(iommu_wq);
state_table_size = MAX_DEVICES * sizeof(struct device_state *);
free_pages((unsigned long)state_table, get_order(state_table_size));
free_page((unsigned long)empty_page_table);
}
