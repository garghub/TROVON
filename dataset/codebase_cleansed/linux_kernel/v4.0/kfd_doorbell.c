static inline size_t doorbell_process_allocation(void)
{
return roundup(KFD_SIZE_OF_DOORBELL_IN_BYTES *
KFD_MAX_NUM_OF_QUEUES_PER_PROCESS,
PAGE_SIZE);
}
void kfd_doorbell_init(struct kfd_dev *kfd)
{
size_t doorbell_start_offset;
size_t doorbell_aperture_size;
size_t doorbell_process_limit;
doorbell_start_offset =
roundup(kfd->shared_resources.doorbell_start_offset,
doorbell_process_allocation());
doorbell_aperture_size =
rounddown(kfd->shared_resources.doorbell_aperture_size,
doorbell_process_allocation());
if (doorbell_aperture_size > doorbell_start_offset)
doorbell_process_limit =
(doorbell_aperture_size - doorbell_start_offset) /
doorbell_process_allocation();
else
doorbell_process_limit = 0;
kfd->doorbell_base = kfd->shared_resources.doorbell_physical_address +
doorbell_start_offset;
kfd->doorbell_id_offset = doorbell_start_offset / sizeof(u32);
kfd->doorbell_process_limit = doorbell_process_limit - 1;
kfd->doorbell_kernel_ptr = ioremap(kfd->doorbell_base,
doorbell_process_allocation());
BUG_ON(!kfd->doorbell_kernel_ptr);
pr_debug("kfd: doorbell initialization:\n");
pr_debug("kfd: doorbell base == 0x%08lX\n",
(uintptr_t)kfd->doorbell_base);
pr_debug("kfd: doorbell_id_offset == 0x%08lX\n",
kfd->doorbell_id_offset);
pr_debug("kfd: doorbell_process_limit == 0x%08lX\n",
doorbell_process_limit);
pr_debug("kfd: doorbell_kernel_offset == 0x%08lX\n",
(uintptr_t)kfd->doorbell_base);
pr_debug("kfd: doorbell aperture size == 0x%08lX\n",
kfd->shared_resources.doorbell_aperture_size);
pr_debug("kfd: doorbell kernel address == 0x%08lX\n",
(uintptr_t)kfd->doorbell_kernel_ptr);
}
int kfd_doorbell_mmap(struct kfd_process *process, struct vm_area_struct *vma)
{
phys_addr_t address;
struct kfd_dev *dev;
if (vma->vm_end - vma->vm_start != doorbell_process_allocation())
return -EINVAL;
dev = kfd_device_by_id(vma->vm_pgoff);
if (dev == NULL)
return -EINVAL;
address = kfd_get_process_doorbells(dev, process);
vma->vm_flags |= VM_IO | VM_DONTCOPY | VM_DONTEXPAND | VM_NORESERVE |
VM_DONTDUMP | VM_PFNMAP;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
pr_debug("kfd: mapping doorbell page in kfd_doorbell_mmap\n"
" target user address == 0x%08llX\n"
" physical address == 0x%08llX\n"
" vm_flags == 0x%04lX\n"
" size == 0x%04lX\n",
(unsigned long long) vma->vm_start, address, vma->vm_flags,
doorbell_process_allocation());
return io_remap_pfn_range(vma,
vma->vm_start,
address >> PAGE_SHIFT,
doorbell_process_allocation(),
vma->vm_page_prot);
}
u32 __iomem *kfd_get_kernel_doorbell(struct kfd_dev *kfd,
unsigned int *doorbell_off)
{
u32 inx;
BUG_ON(!kfd || !doorbell_off);
mutex_lock(&doorbell_mutex);
inx = find_first_zero_bit(doorbell_available_index,
KFD_MAX_NUM_OF_QUEUES_PER_PROCESS);
__set_bit(inx, doorbell_available_index);
mutex_unlock(&doorbell_mutex);
if (inx >= KFD_MAX_NUM_OF_QUEUES_PER_PROCESS)
return NULL;
*doorbell_off = KERNEL_DOORBELL_PASID * (doorbell_process_allocation() /
sizeof(u32)) + inx;
pr_debug("kfd: get kernel queue doorbell\n"
" doorbell offset == 0x%08d\n"
" kernel address == 0x%08lX\n",
*doorbell_off, (uintptr_t)(kfd->doorbell_kernel_ptr + inx));
return kfd->doorbell_kernel_ptr + inx;
}
void kfd_release_kernel_doorbell(struct kfd_dev *kfd, u32 __iomem *db_addr)
{
unsigned int inx;
BUG_ON(!kfd || !db_addr);
inx = (unsigned int)(db_addr - kfd->doorbell_kernel_ptr);
mutex_lock(&doorbell_mutex);
__clear_bit(inx, doorbell_available_index);
mutex_unlock(&doorbell_mutex);
}
inline void write_kernel_doorbell(u32 __iomem *db, u32 value)
{
if (db) {
writel(value, db);
pr_debug("writing %d to doorbell address 0x%p\n", value, db);
}
}
unsigned int kfd_queue_id_to_doorbell(struct kfd_dev *kfd,
struct kfd_process *process,
unsigned int queue_id)
{
return kfd->doorbell_id_offset +
process->pasid * (doorbell_process_allocation()/sizeof(u32)) +
queue_id;
}
uint64_t kfd_get_number_elems(struct kfd_dev *kfd)
{
uint64_t num_of_elems = (kfd->shared_resources.doorbell_aperture_size -
kfd->shared_resources.doorbell_start_offset) /
doorbell_process_allocation() + 1;
return num_of_elems;
}
phys_addr_t kfd_get_process_doorbells(struct kfd_dev *dev,
struct kfd_process *process)
{
return dev->doorbell_base +
process->pasid * doorbell_process_allocation();
}
