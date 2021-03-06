static void __init patch_vdso(void *vdso, size_t len)
{
Elf64_Ehdr *hdr = vdso;
Elf64_Shdr *sechdrs, *alt_sec = 0;
char *secstrings;
void *alt_data;
int i;
BUG_ON(len < sizeof(Elf64_Ehdr));
BUG_ON(memcmp(hdr->e_ident, ELFMAG, SELFMAG) != 0);
sechdrs = (void *)hdr + hdr->e_shoff;
secstrings = (void *)hdr + sechdrs[hdr->e_shstrndx].sh_offset;
for (i = 1; i < hdr->e_shnum; i++) {
Elf64_Shdr *shdr = &sechdrs[i];
if (!strcmp(secstrings + shdr->sh_name, ".altinstructions")) {
alt_sec = shdr;
goto found;
}
}
pr_warning("patch_vdso: .altinstructions not found\n");
return;
found:
alt_data = (void *)hdr + alt_sec->sh_offset;
apply_alternatives(alt_data, alt_data + alt_sec->sh_size);
}
static int __init init_vdso(void)
{
int npages = (vdso_end - vdso_start + PAGE_SIZE - 1) / PAGE_SIZE;
int i;
patch_vdso(vdso_start, vdso_end - vdso_start);
vdso_size = npages << PAGE_SHIFT;
for (i = 0; i < npages; i++)
vdso_pages[i] = virt_to_page(vdso_start + i*PAGE_SIZE);
return 0;
}
static unsigned long vdso_addr(unsigned long start, unsigned len)
{
unsigned long addr, end;
unsigned offset;
end = (start + PMD_SIZE - 1) & PMD_MASK;
if (end >= TASK_SIZE_MAX)
end = TASK_SIZE_MAX;
end -= len;
offset = get_random_int() & (PTRS_PER_PTE - 1);
addr = start + (offset << PAGE_SHIFT);
if (addr >= end)
addr = end;
addr = PAGE_ALIGN(addr);
addr = align_addr(addr, NULL, ALIGN_VDSO);
return addr;
}
int arch_setup_additional_pages(struct linux_binprm *bprm, int uses_interp)
{
struct mm_struct *mm = current->mm;
unsigned long addr;
int ret;
if (!vdso_enabled)
return 0;
down_write(&mm->mmap_sem);
addr = vdso_addr(mm->start_stack, vdso_size);
addr = get_unmapped_area(NULL, addr, vdso_size, 0, 0);
if (IS_ERR_VALUE(addr)) {
ret = addr;
goto up_fail;
}
current->mm->context.vdso = (void *)addr;
ret = install_special_mapping(mm, addr, vdso_size,
VM_READ|VM_EXEC|
VM_MAYREAD|VM_MAYWRITE|VM_MAYEXEC|
VM_ALWAYSDUMP,
vdso_pages);
if (ret) {
current->mm->context.vdso = NULL;
goto up_fail;
}
up_fail:
up_write(&mm->mmap_sem);
return ret;
}
static __init int vdso_setup(char *s)
{
vdso_enabled = simple_strtoul(s, NULL, 0);
return 0;
}
