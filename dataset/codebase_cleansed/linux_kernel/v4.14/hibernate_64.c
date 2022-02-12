static int set_up_temporary_text_mapping(pgd_t *pgd)
{
pmd_t *pmd;
pud_t *pud;
p4d_t *p4d;
if (IS_ENABLED(CONFIG_X86_5LEVEL)) {
p4d = (p4d_t *)get_safe_page(GFP_ATOMIC);
if (!p4d)
return -ENOMEM;
}
pud = (pud_t *)get_safe_page(GFP_ATOMIC);
if (!pud)
return -ENOMEM;
pmd = (pmd_t *)get_safe_page(GFP_ATOMIC);
if (!pmd)
return -ENOMEM;
set_pmd(pmd + pmd_index(restore_jump_address),
__pmd((jump_address_phys & PMD_MASK) | __PAGE_KERNEL_LARGE_EXEC));
set_pud(pud + pud_index(restore_jump_address),
__pud(__pa(pmd) | _KERNPG_TABLE));
if (IS_ENABLED(CONFIG_X86_5LEVEL)) {
set_p4d(p4d + p4d_index(restore_jump_address), __p4d(__pa(pud) | _KERNPG_TABLE));
set_pgd(pgd + pgd_index(restore_jump_address), __pgd(__pa(p4d) | _KERNPG_TABLE));
} else {
set_pgd(pgd + pgd_index(restore_jump_address), __pgd(__pa(pud) | _KERNPG_TABLE));
}
return 0;
}
static void *alloc_pgt_page(void *context)
{
return (void *)get_safe_page(GFP_ATOMIC);
}
static int set_up_temporary_mappings(void)
{
struct x86_mapping_info info = {
.alloc_pgt_page = alloc_pgt_page,
.page_flag = __PAGE_KERNEL_LARGE_EXEC,
.offset = __PAGE_OFFSET,
};
unsigned long mstart, mend;
pgd_t *pgd;
int result;
int i;
pgd = (pgd_t *)get_safe_page(GFP_ATOMIC);
if (!pgd)
return -ENOMEM;
result = set_up_temporary_text_mapping(pgd);
if (result)
return result;
for (i = 0; i < nr_pfn_mapped; i++) {
mstart = pfn_mapped[i].start << PAGE_SHIFT;
mend = pfn_mapped[i].end << PAGE_SHIFT;
result = kernel_ident_mapping_init(&info, pgd, mstart, mend);
if (result)
return result;
}
temp_level4_pgt = __pa(pgd);
return 0;
}
static int relocate_restore_code(void)
{
pgd_t *pgd;
p4d_t *p4d;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
relocated_restore_code = get_safe_page(GFP_ATOMIC);
if (!relocated_restore_code)
return -ENOMEM;
memcpy((void *)relocated_restore_code, core_restore_code, PAGE_SIZE);
pgd = (pgd_t *)__va(read_cr3_pa()) +
pgd_index(relocated_restore_code);
p4d = p4d_offset(pgd, relocated_restore_code);
if (p4d_large(*p4d)) {
set_p4d(p4d, __p4d(p4d_val(*p4d) & ~_PAGE_NX));
goto out;
}
pud = pud_offset(p4d, relocated_restore_code);
if (pud_large(*pud)) {
set_pud(pud, __pud(pud_val(*pud) & ~_PAGE_NX));
goto out;
}
pmd = pmd_offset(pud, relocated_restore_code);
if (pmd_large(*pmd)) {
set_pmd(pmd, __pmd(pmd_val(*pmd) & ~_PAGE_NX));
goto out;
}
pte = pte_offset_kernel(pmd, relocated_restore_code);
set_pte(pte, __pte(pte_val(*pte) & ~_PAGE_NX));
out:
__flush_tlb_all();
return 0;
}
int swsusp_arch_resume(void)
{
int error;
error = set_up_temporary_mappings();
if (error)
return error;
error = relocate_restore_code();
if (error)
return error;
restore_image();
return 0;
}
int pfn_is_nosave(unsigned long pfn)
{
unsigned long nosave_begin_pfn = __pa_symbol(&__nosave_begin) >> PAGE_SHIFT;
unsigned long nosave_end_pfn = PAGE_ALIGN(__pa_symbol(&__nosave_end)) >> PAGE_SHIFT;
return (pfn >= nosave_begin_pfn) && (pfn < nosave_end_pfn);
}
static int get_e820_md5(struct e820_table *table, void *buf)
{
struct scatterlist sg;
struct crypto_ahash *tfm;
int size;
int ret = 0;
tfm = crypto_alloc_ahash("md5", 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm))
return -ENOMEM;
{
AHASH_REQUEST_ON_STACK(req, tfm);
size = offsetof(struct e820_table, entries) + sizeof(struct e820_entry) * table->nr_entries;
ahash_request_set_tfm(req, tfm);
sg_init_one(&sg, (u8 *)table, size);
ahash_request_set_callback(req, 0, NULL, NULL);
ahash_request_set_crypt(req, &sg, buf, size);
if (crypto_ahash_digest(req))
ret = -EINVAL;
ahash_request_zero(req);
}
crypto_free_ahash(tfm);
return ret;
}
static void hibernation_e820_save(void *buf)
{
get_e820_md5(e820_table_firmware, buf);
}
static bool hibernation_e820_mismatch(void *buf)
{
int ret;
u8 result[MD5_DIGEST_SIZE];
memset(result, 0, MD5_DIGEST_SIZE);
if (!memcmp(result, buf, MD5_DIGEST_SIZE))
return false;
ret = get_e820_md5(e820_table_firmware, result);
if (ret)
return true;
return memcmp(result, buf, MD5_DIGEST_SIZE) ? true : false;
}
static void hibernation_e820_save(void *buf)
{
}
static bool hibernation_e820_mismatch(void *buf)
{
return false;
}
int arch_hibernation_header_save(void *addr, unsigned int max_size)
{
struct restore_data_record *rdr = addr;
if (max_size < sizeof(struct restore_data_record))
return -EOVERFLOW;
rdr->jump_address = (unsigned long)restore_registers;
rdr->jump_address_phys = __pa_symbol(restore_registers);
rdr->cr3 = restore_cr3 & ~CR3_PCID_MASK;
rdr->magic = RESTORE_MAGIC;
hibernation_e820_save(rdr->e820_digest);
return 0;
}
int arch_hibernation_header_restore(void *addr)
{
struct restore_data_record *rdr = addr;
restore_jump_address = rdr->jump_address;
jump_address_phys = rdr->jump_address_phys;
restore_cr3 = rdr->cr3;
if (rdr->magic != RESTORE_MAGIC) {
pr_crit("Unrecognized hibernate image header format!\n");
return -EINVAL;
}
if (hibernation_e820_mismatch(rdr->e820_digest)) {
pr_crit("Hibernate inconsistent memory map detected!\n");
return -ENODEV;
}
return 0;
}
