int arch_gnttab_map_shared(unsigned long *frames, unsigned long nr_gframes,
unsigned long max_nr_gframes,
void **__shared)
{
void *shared = *__shared;
unsigned long addr;
unsigned long i;
if (shared == NULL)
*__shared = shared = gnttab_shared_vm_area.area->addr;
addr = (unsigned long)shared;
for (i = 0; i < nr_gframes; i++) {
set_pte_at(&init_mm, addr, gnttab_shared_vm_area.ptes[i],
mfn_pte(frames[i], PAGE_KERNEL));
addr += PAGE_SIZE;
}
return 0;
}
void arch_gnttab_unmap(void *shared, unsigned long nr_gframes)
{
unsigned long addr;
unsigned long i;
addr = (unsigned long)shared;
for (i = 0; i < nr_gframes; i++) {
set_pte_at(&init_mm, addr, gnttab_shared_vm_area.ptes[i],
__pte(0));
addr += PAGE_SIZE;
}
}
static int arch_gnttab_valloc(struct gnttab_vm_area *area, unsigned nr_frames)
{
area->ptes = kmalloc_array(nr_frames, sizeof(*area->ptes), GFP_KERNEL);
if (area->ptes == NULL)
return -ENOMEM;
area->area = alloc_vm_area(PAGE_SIZE * nr_frames, area->ptes);
if (area->area == NULL) {
kfree(area->ptes);
return -ENOMEM;
}
return 0;
}
int arch_gnttab_init(unsigned long nr_shared)
{
if (!xen_pv_domain())
return 0;
return arch_gnttab_valloc(&gnttab_shared_vm_area, nr_shared);
}
static int __init xen_pvh_gnttab_setup(void)
{
if (!xen_pvh_domain())
return -ENODEV;
xen_auto_xlat_grant_frames.count = gnttab_max_grant_frames();
return xen_xlate_map_ballooned_pages(&xen_auto_xlat_grant_frames.pfn,
&xen_auto_xlat_grant_frames.vaddr,
xen_auto_xlat_grant_frames.count);
}
