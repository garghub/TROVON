void get_vmalloc_info(struct vmalloc_info *vmi)
{
struct vm_struct *vma;
unsigned long free_area_size;
unsigned long prev_end;
vmi->used = 0;
if (!vmlist) {
vmi->largest_chunk = VMALLOC_TOTAL;
}
else {
vmi->largest_chunk = 0;
prev_end = VMALLOC_START;
read_lock(&vmlist_lock);
for (vma = vmlist; vma; vma = vma->next) {
unsigned long addr = (unsigned long) vma->addr;
if (addr < VMALLOC_START)
continue;
if (addr >= VMALLOC_END)
break;
vmi->used += vma->size;
free_area_size = addr - prev_end;
if (vmi->largest_chunk < free_area_size)
vmi->largest_chunk = free_area_size;
prev_end = vma->size + addr;
}
if (VMALLOC_END - prev_end > vmi->largest_chunk)
vmi->largest_chunk = VMALLOC_END - prev_end;
read_unlock(&vmlist_lock);
}
}
