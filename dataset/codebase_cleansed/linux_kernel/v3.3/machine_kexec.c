int machine_kexec_prepare(struct kimage *image)
{
void *control_code_buffer;
const unsigned long *func;
func = (unsigned long *)&relocate_new_kernel;
control_code_buffer = page_address(image->control_code_page);
memcpy((void *)control_code_buffer, (const void *)func[0],
relocate_new_kernel_size);
flush_icache_range((unsigned long)control_code_buffer,
(unsigned long)control_code_buffer + relocate_new_kernel_size);
ia64_kimage = image;
return 0;
}
void machine_kexec_cleanup(struct kimage *image)
{
}
static void ia64_machine_kexec(struct unw_frame_info *info, void *arg)
{
struct kimage *image = arg;
relocate_new_kernel_t rnk;
void *pal_addr = efi_get_pal_addr();
unsigned long code_addr = (unsigned long)page_address(image->control_code_page);
int ii;
u64 fp, gp;
ia64_fptr_t *init_handler = (ia64_fptr_t *)ia64_os_init_on_kdump;
BUG_ON(!image);
if (image->type == KEXEC_TYPE_CRASH) {
crash_save_this_cpu();
current->thread.ksp = (__u64)info->sw - 16;
fp = ia64_tpa(init_handler->fp);
gp = ia64_tpa(ia64_getreg(_IA64_REG_GP));
ia64_sal_set_vectors(SAL_VECTOR_OS_INIT, fp, gp, 0, fp, gp, 0);
} else {
ia64_sal_set_vectors(SAL_VECTOR_OS_INIT, 0, 0, 0, 0, 0, 0);
}
ia64_sal_set_vectors(SAL_VECTOR_OS_MCA, 0, 0, 0, 0, 0, 0);
local_irq_disable();
ia64_setreg(_IA64_REG_CR_PMV, 1 << 16);
ia64_setreg(_IA64_REG_CR_CMCV, 1 << 16);
ia64_set_itv(1 << 16);
ia64_set_lrr0(1 << 16);
ia64_set_lrr1(1 << 16);
for (ii = 0; ii < 16; ii++)
ia64_eoi();
ia64_setreg(_IA64_REG_CR_TPR, 0);
ia64_srlz_d();
while (ia64_get_ivr() != IA64_SPURIOUS_INT_VECTOR)
ia64_eoi();
platform_kernel_launch_event();
rnk = (relocate_new_kernel_t)&code_addr;
(*rnk)(image->head, image->start, ia64_boot_param,
GRANULEROUNDDOWN((unsigned long) pal_addr));
BUG();
}
void machine_kexec(struct kimage *image)
{
BUG_ON(!image);
unw_init_running(ia64_machine_kexec, image);
for(;;);
}
void arch_crash_save_vmcoreinfo(void)
{
#if defined(CONFIG_DISCONTIGMEM) || defined(CONFIG_SPARSEMEM)
VMCOREINFO_SYMBOL(pgdat_list);
VMCOREINFO_LENGTH(pgdat_list, MAX_NUMNODES);
#endif
#ifdef CONFIG_NUMA
VMCOREINFO_SYMBOL(node_memblk);
VMCOREINFO_LENGTH(node_memblk, NR_NODE_MEMBLKS);
VMCOREINFO_STRUCT_SIZE(node_memblk_s);
VMCOREINFO_OFFSET(node_memblk_s, start_paddr);
VMCOREINFO_OFFSET(node_memblk_s, size);
#endif
#ifdef CONFIG_PGTABLE_3
VMCOREINFO_CONFIG(PGTABLE_3);
#elif CONFIG_PGTABLE_4
VMCOREINFO_CONFIG(PGTABLE_4);
#endif
}
unsigned long paddr_vmcoreinfo_note(void)
{
return ia64_tpa((unsigned long)(char *)&vmcoreinfo_note);
}
