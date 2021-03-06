static int xen_oldmem_pfn_is_ram(unsigned long pfn)
{
struct xen_hvm_get_mem_type a = {
.domid = DOMID_SELF,
.pfn = pfn,
};
int ram;
if (HYPERVISOR_hvm_op(HVMOP_get_mem_type, &a))
return -ENXIO;
switch (a.mem_type) {
case HVMMEM_mmio_dm:
ram = 0;
break;
case HVMMEM_ram_rw:
case HVMMEM_ram_ro:
default:
ram = 1;
break;
}
return ram;
}
static void xen_hvm_exit_mmap(struct mm_struct *mm)
{
struct xen_hvm_pagetable_dying a;
int rc;
a.domid = DOMID_SELF;
a.gpa = __pa(mm->pgd);
rc = HYPERVISOR_hvm_op(HVMOP_pagetable_dying, &a);
WARN_ON_ONCE(rc < 0);
}
static int is_pagetable_dying_supported(void)
{
struct xen_hvm_pagetable_dying a;
int rc = 0;
a.domid = DOMID_SELF;
a.gpa = 0x00;
rc = HYPERVISOR_hvm_op(HVMOP_pagetable_dying, &a);
if (rc < 0) {
printk(KERN_DEBUG "HVMOP_pagetable_dying not supported\n");
return 0;
}
return 1;
}
void __init xen_hvm_init_mmu_ops(void)
{
if (is_pagetable_dying_supported())
pv_mmu_ops.exit_mmap = xen_hvm_exit_mmap;
#ifdef CONFIG_PROC_VMCORE
register_oldmem_pfn_is_ram(&xen_oldmem_pfn_is_ram);
#endif
}
