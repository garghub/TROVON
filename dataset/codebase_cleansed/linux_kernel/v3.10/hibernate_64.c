static void *alloc_pgt_page(void *context)
{
return (void *)get_safe_page(GFP_ATOMIC);
}
static int set_up_temporary_mappings(void)
{
struct x86_mapping_info info = {
.alloc_pgt_page = alloc_pgt_page,
.pmd_flag = __PAGE_KERNEL_LARGE_EXEC,
.kernel_mapping = true,
};
unsigned long mstart, mend;
int result;
int i;
temp_level4_pgt = (pgd_t *)get_safe_page(GFP_ATOMIC);
if (!temp_level4_pgt)
return -ENOMEM;
set_pgd(temp_level4_pgt + pgd_index(__START_KERNEL_map),
init_level4_pgt[pgd_index(__START_KERNEL_map)]);
for (i = 0; i < nr_pfn_mapped; i++) {
mstart = pfn_mapped[i].start << PAGE_SHIFT;
mend = pfn_mapped[i].end << PAGE_SHIFT;
result = kernel_ident_mapping_init(&info, temp_level4_pgt,
mstart, mend);
if (result)
return result;
}
return 0;
}
int swsusp_arch_resume(void)
{
int error;
if ((error = set_up_temporary_mappings()))
return error;
relocated_restore_code = (void *)get_safe_page(GFP_ATOMIC);
if (!relocated_restore_code)
return -ENOMEM;
memcpy(relocated_restore_code, &core_restore_code,
&restore_registers - &core_restore_code);
restore_image();
return 0;
}
int pfn_is_nosave(unsigned long pfn)
{
unsigned long nosave_begin_pfn = __pa_symbol(&__nosave_begin) >> PAGE_SHIFT;
unsigned long nosave_end_pfn = PAGE_ALIGN(__pa_symbol(&__nosave_end)) >> PAGE_SHIFT;
return (pfn >= nosave_begin_pfn) && (pfn < nosave_end_pfn);
}
int arch_hibernation_header_save(void *addr, unsigned int max_size)
{
struct restore_data_record *rdr = addr;
if (max_size < sizeof(struct restore_data_record))
return -EOVERFLOW;
rdr->jump_address = restore_jump_address;
rdr->cr3 = restore_cr3;
rdr->magic = RESTORE_MAGIC;
return 0;
}
int arch_hibernation_header_restore(void *addr)
{
struct restore_data_record *rdr = addr;
restore_jump_address = rdr->jump_address;
restore_cr3 = rdr->cr3;
return (rdr->magic == RESTORE_MAGIC) ? 0 : -EINVAL;
}
