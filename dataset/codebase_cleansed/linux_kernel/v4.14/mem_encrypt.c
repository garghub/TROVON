static void __init __sme_early_enc_dec(resource_size_t paddr,
unsigned long size, bool enc)
{
void *src, *dst;
size_t len;
if (!sme_me_mask)
return;
local_flush_tlb();
wbinvd();
while (size) {
len = min_t(size_t, sizeof(sme_early_buffer), size);
src = enc ? early_memremap_decrypted_wp(paddr, len) :
early_memremap_encrypted_wp(paddr, len);
dst = enc ? early_memremap_encrypted(paddr, len) :
early_memremap_decrypted(paddr, len);
BUG_ON(!src || !dst);
memcpy(sme_early_buffer, src, len);
memcpy(dst, sme_early_buffer, len);
early_memunmap(dst, len);
early_memunmap(src, len);
paddr += len;
size -= len;
}
}
void __init sme_early_encrypt(resource_size_t paddr, unsigned long size)
{
__sme_early_enc_dec(paddr, size, true);
}
void __init sme_early_decrypt(resource_size_t paddr, unsigned long size)
{
__sme_early_enc_dec(paddr, size, false);
}
static void __init __sme_early_map_unmap_mem(void *vaddr, unsigned long size,
bool map)
{
unsigned long paddr = (unsigned long)vaddr - __PAGE_OFFSET;
pmdval_t pmd_flags, pmd;
pmd_flags = __sme_clr(early_pmd_flags);
do {
pmd = map ? (paddr & PMD_MASK) + pmd_flags : 0;
__early_make_pgtable((unsigned long)vaddr, pmd);
vaddr += PMD_SIZE;
paddr += PMD_SIZE;
size = (size <= PMD_SIZE) ? 0 : size - PMD_SIZE;
} while (size);
__native_flush_tlb();
}
void __init sme_unmap_bootdata(char *real_mode_data)
{
struct boot_params *boot_data;
unsigned long cmdline_paddr;
if (!sme_active())
return;
boot_data = (struct boot_params *)real_mode_data;
cmdline_paddr = boot_data->hdr.cmd_line_ptr | ((u64)boot_data->ext_cmd_line_ptr << 32);
__sme_early_map_unmap_mem(real_mode_data, sizeof(boot_params), false);
if (!cmdline_paddr)
return;
__sme_early_map_unmap_mem(__va(cmdline_paddr), COMMAND_LINE_SIZE, false);
}
void __init sme_map_bootdata(char *real_mode_data)
{
struct boot_params *boot_data;
unsigned long cmdline_paddr;
if (!sme_active())
return;
__sme_early_map_unmap_mem(real_mode_data, sizeof(boot_params), true);
boot_data = (struct boot_params *)real_mode_data;
cmdline_paddr = boot_data->hdr.cmd_line_ptr | ((u64)boot_data->ext_cmd_line_ptr << 32);
if (!cmdline_paddr)
return;
__sme_early_map_unmap_mem(__va(cmdline_paddr), COMMAND_LINE_SIZE, true);
}
void __init sme_early_init(void)
{
unsigned int i;
if (!sme_me_mask)
return;
early_pmd_flags = __sme_set(early_pmd_flags);
__supported_pte_mask = __sme_set(__supported_pte_mask);
for (i = 0; i < ARRAY_SIZE(protection_map); i++)
protection_map[i] = pgprot_encrypted(protection_map[i]);
}
void __init mem_encrypt_init(void)
{
if (!sme_me_mask)
return;
swiotlb_update_mem_attributes();
pr_info("AMD Secure Memory Encryption (SME) active\n");
}
void swiotlb_set_mem_attributes(void *vaddr, unsigned long size)
{
WARN(PAGE_ALIGN(size) != size,
"size is not page-aligned (%#lx)\n", size);
set_memory_decrypted((unsigned long)vaddr, size >> PAGE_SHIFT);
}
static void __init sme_clear_pgd(pgd_t *pgd_base, unsigned long start,
unsigned long end)
{
unsigned long pgd_start, pgd_end, pgd_size;
pgd_t *pgd_p;
pgd_start = start & PGDIR_MASK;
pgd_end = end & PGDIR_MASK;
pgd_size = (((pgd_end - pgd_start) / PGDIR_SIZE) + 1);
pgd_size *= sizeof(pgd_t);
pgd_p = pgd_base + pgd_index(start);
memset(pgd_p, 0, pgd_size);
}
static void __init *sme_populate_pgd(pgd_t *pgd_base, void *pgtable_area,
unsigned long vaddr, pmdval_t pmd_val)
{
pgd_t *pgd_p;
p4d_t *p4d_p;
pud_t *pud_p;
pmd_t *pmd_p;
pgd_p = pgd_base + pgd_index(vaddr);
if (native_pgd_val(*pgd_p)) {
if (IS_ENABLED(CONFIG_X86_5LEVEL))
p4d_p = (p4d_t *)(native_pgd_val(*pgd_p) & ~PTE_FLAGS_MASK);
else
pud_p = (pud_t *)(native_pgd_val(*pgd_p) & ~PTE_FLAGS_MASK);
} else {
pgd_t pgd;
if (IS_ENABLED(CONFIG_X86_5LEVEL)) {
p4d_p = pgtable_area;
memset(p4d_p, 0, sizeof(*p4d_p) * PTRS_PER_P4D);
pgtable_area += sizeof(*p4d_p) * PTRS_PER_P4D;
pgd = native_make_pgd((pgdval_t)p4d_p + PGD_FLAGS);
} else {
pud_p = pgtable_area;
memset(pud_p, 0, sizeof(*pud_p) * PTRS_PER_PUD);
pgtable_area += sizeof(*pud_p) * PTRS_PER_PUD;
pgd = native_make_pgd((pgdval_t)pud_p + PGD_FLAGS);
}
native_set_pgd(pgd_p, pgd);
}
if (IS_ENABLED(CONFIG_X86_5LEVEL)) {
p4d_p += p4d_index(vaddr);
if (native_p4d_val(*p4d_p)) {
pud_p = (pud_t *)(native_p4d_val(*p4d_p) & ~PTE_FLAGS_MASK);
} else {
p4d_t p4d;
pud_p = pgtable_area;
memset(pud_p, 0, sizeof(*pud_p) * PTRS_PER_PUD);
pgtable_area += sizeof(*pud_p) * PTRS_PER_PUD;
p4d = native_make_p4d((pudval_t)pud_p + P4D_FLAGS);
native_set_p4d(p4d_p, p4d);
}
}
pud_p += pud_index(vaddr);
if (native_pud_val(*pud_p)) {
if (native_pud_val(*pud_p) & _PAGE_PSE)
goto out;
pmd_p = (pmd_t *)(native_pud_val(*pud_p) & ~PTE_FLAGS_MASK);
} else {
pud_t pud;
pmd_p = pgtable_area;
memset(pmd_p, 0, sizeof(*pmd_p) * PTRS_PER_PMD);
pgtable_area += sizeof(*pmd_p) * PTRS_PER_PMD;
pud = native_make_pud((pmdval_t)pmd_p + PUD_FLAGS);
native_set_pud(pud_p, pud);
}
pmd_p += pmd_index(vaddr);
if (!native_pmd_val(*pmd_p) || !(native_pmd_val(*pmd_p) & _PAGE_PSE))
native_set_pmd(pmd_p, native_make_pmd(pmd_val));
out:
return pgtable_area;
}
static unsigned long __init sme_pgtable_calc(unsigned long len)
{
unsigned long p4d_size, pud_size, pmd_size;
unsigned long total;
if (IS_ENABLED(CONFIG_X86_5LEVEL)) {
p4d_size = (ALIGN(len, PGDIR_SIZE) / PGDIR_SIZE) + 1;
p4d_size *= sizeof(p4d_t) * PTRS_PER_P4D;
pud_size = (ALIGN(len, P4D_SIZE) / P4D_SIZE) + 1;
pud_size *= sizeof(pud_t) * PTRS_PER_PUD;
} else {
p4d_size = 0;
pud_size = (ALIGN(len, PGDIR_SIZE) / PGDIR_SIZE) + 1;
pud_size *= sizeof(pud_t) * PTRS_PER_PUD;
}
pmd_size = (ALIGN(len, PUD_SIZE) / PUD_SIZE) + 1;
pmd_size *= sizeof(pmd_t) * PTRS_PER_PMD;
total = p4d_size + pud_size + pmd_size;
if (IS_ENABLED(CONFIG_X86_5LEVEL)) {
p4d_size = ALIGN(total, PGDIR_SIZE) / PGDIR_SIZE;
p4d_size *= sizeof(p4d_t) * PTRS_PER_P4D;
pud_size = ALIGN(total, P4D_SIZE) / P4D_SIZE;
pud_size *= sizeof(pud_t) * PTRS_PER_PUD;
} else {
p4d_size = 0;
pud_size = ALIGN(total, PGDIR_SIZE) / PGDIR_SIZE;
pud_size *= sizeof(pud_t) * PTRS_PER_PUD;
}
pmd_size = ALIGN(total, PUD_SIZE) / PUD_SIZE;
pmd_size *= sizeof(pmd_t) * PTRS_PER_PMD;
total += p4d_size + pud_size + pmd_size;
return total;
}
void __init sme_encrypt_kernel(void)
{
unsigned long workarea_start, workarea_end, workarea_len;
unsigned long execute_start, execute_end, execute_len;
unsigned long kernel_start, kernel_end, kernel_len;
unsigned long pgtable_area_len;
unsigned long paddr, pmd_flags;
unsigned long decrypted_base;
void *pgtable_area;
pgd_t *pgd;
if (!sme_active())
return;
kernel_start = __pa_symbol(_text);
kernel_end = ALIGN(__pa_symbol(_end), PMD_PAGE_SIZE);
kernel_len = kernel_end - kernel_start;
workarea_start = kernel_end;
execute_start = workarea_start;
execute_end = execute_start + (PAGE_SIZE * 2) + PMD_PAGE_SIZE;
execute_len = execute_end - execute_start;
pgtable_area_len = sizeof(pgd_t) * PTRS_PER_PGD;
pgtable_area_len += sme_pgtable_calc(execute_end - kernel_start) * 2;
pgtable_area_len += sme_pgtable_calc(execute_len + pgtable_area_len);
workarea_len = execute_len + pgtable_area_len;
workarea_end = workarea_start + workarea_len;
pgtable_area = (void *)execute_end;
pgd = (pgd_t *)native_read_cr3_pa();
paddr = workarea_start;
while (paddr < workarea_end) {
pgtable_area = sme_populate_pgd(pgd, pgtable_area,
paddr,
paddr + PMD_FLAGS);
paddr += PMD_PAGE_SIZE;
}
native_write_cr3(__native_read_cr3());
pgd = pgtable_area;
memset(pgd, 0, sizeof(*pgd) * PTRS_PER_PGD);
pgtable_area += sizeof(*pgd) * PTRS_PER_PGD;
pmd_flags = PMD_FLAGS | _PAGE_ENC;
paddr = kernel_start;
while (paddr < kernel_end) {
pgtable_area = sme_populate_pgd(pgd, pgtable_area,
paddr,
paddr + pmd_flags);
paddr += PMD_PAGE_SIZE;
}
decrypted_base = (pgd_index(workarea_end) + 1) & (PTRS_PER_PGD - 1);
decrypted_base <<= PGDIR_SHIFT;
pmd_flags = (PMD_FLAGS & ~_PAGE_CACHE_MASK) | (_PAGE_PAT | _PAGE_PWT);
paddr = kernel_start;
while (paddr < kernel_end) {
pgtable_area = sme_populate_pgd(pgd, pgtable_area,
paddr + decrypted_base,
paddr + pmd_flags);
paddr += PMD_PAGE_SIZE;
}
paddr = workarea_start;
while (paddr < workarea_end) {
pgtable_area = sme_populate_pgd(pgd, pgtable_area,
paddr,
paddr + PMD_FLAGS);
pgtable_area = sme_populate_pgd(pgd, pgtable_area,
paddr + decrypted_base,
paddr + PMD_FLAGS);
paddr += PMD_PAGE_SIZE;
}
sme_encrypt_execute(kernel_start, kernel_start + decrypted_base,
kernel_len, workarea_start, (unsigned long)pgd);
sme_clear_pgd(pgd, kernel_start + decrypted_base,
kernel_end + decrypted_base);
sme_clear_pgd(pgd, workarea_start + decrypted_base,
workarea_end + decrypted_base);
native_write_cr3(__native_read_cr3());
}
void __init __nostackprotector sme_enable(struct boot_params *bp)
{
const char *cmdline_ptr, *cmdline_arg, *cmdline_on, *cmdline_off;
unsigned int eax, ebx, ecx, edx;
bool active_by_default;
unsigned long me_mask;
char buffer[16];
u64 msr;
eax = 0x80000000;
ecx = 0;
native_cpuid(&eax, &ebx, &ecx, &edx);
if (eax < 0x8000001f)
return;
eax = 0x8000001f;
ecx = 0;
native_cpuid(&eax, &ebx, &ecx, &edx);
if (!(eax & 1))
return;
me_mask = 1UL << (ebx & 0x3f);
msr = __rdmsr(MSR_K8_SYSCFG);
if (!(msr & MSR_K8_SYSCFG_MEM_ENCRYPT))
return;
asm ("lea sme_cmdline_arg(%%rip), %0"
: "=r" (cmdline_arg)
: "p" (sme_cmdline_arg));
asm ("lea sme_cmdline_on(%%rip), %0"
: "=r" (cmdline_on)
: "p" (sme_cmdline_on));
asm ("lea sme_cmdline_off(%%rip), %0"
: "=r" (cmdline_off)
: "p" (sme_cmdline_off));
if (IS_ENABLED(CONFIG_AMD_MEM_ENCRYPT_ACTIVE_BY_DEFAULT))
active_by_default = true;
else
active_by_default = false;
cmdline_ptr = (const char *)((u64)bp->hdr.cmd_line_ptr |
((u64)bp->ext_cmd_line_ptr << 32));
cmdline_find_option(cmdline_ptr, cmdline_arg, buffer, sizeof(buffer));
if (!strncmp(buffer, cmdline_on, sizeof(buffer)))
sme_me_mask = me_mask;
else if (!strncmp(buffer, cmdline_off, sizeof(buffer)))
sme_me_mask = 0;
else
sme_me_mask = active_by_default ? me_mask : 0;
}
