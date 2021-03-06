void *tcm_alloc(size_t len)
{
unsigned long vaddr;
if (!tcm_pool)
return NULL;
vaddr = gen_pool_alloc(tcm_pool, len);
if (!vaddr)
return NULL;
return (void *) vaddr;
}
void tcm_free(void *addr, size_t len)
{
gen_pool_free(tcm_pool, (unsigned long) addr, len);
}
bool tcm_dtcm_present(void)
{
return dtcm_present;
}
bool tcm_itcm_present(void)
{
return itcm_present;
}
static int __init setup_tcm_bank(u8 type, u8 bank, u8 banks,
u32 *offset)
{
const int tcm_sizes[16] = { 0, -1, -1, 4, 8, 16, 32, 64, 128,
256, 512, 1024, -1, -1, -1, -1 };
u32 tcm_region;
int tcm_size;
if (banks > 1)
asm("mcr p15, 0, %0, c9, c2, 0"
:
: "r" (bank));
if (!type)
asm("mrc p15, 0, %0, c9, c1, 0"
: "=r" (tcm_region));
else
asm("mrc p15, 0, %0, c9, c1, 1"
: "=r" (tcm_region));
tcm_size = tcm_sizes[(tcm_region >> 2) & 0x0f];
if (tcm_size < 0) {
pr_err("CPU: %sTCM%d of unknown size\n",
type ? "I" : "D", bank);
return -EINVAL;
} else if (tcm_size > 32) {
pr_err("CPU: %sTCM%d larger than 32k found\n",
type ? "I" : "D", bank);
return -EINVAL;
} else {
pr_info("CPU: found %sTCM%d %dk @ %08x, %senabled\n",
type ? "I" : "D",
bank,
tcm_size,
(tcm_region & 0xfffff000U),
(tcm_region & 1) ? "" : "not ");
}
if (tcm_size == 0)
return 0;
tcm_region = *offset | (tcm_region & 0x00000ffeU) | 1;
if (!type)
asm("mcr p15, 0, %0, c9, c1, 0"
:
: "r" (tcm_region));
else
asm("mcr p15, 0, %0, c9, c1, 1"
:
: "r" (tcm_region));
*offset += (tcm_size << 10);
pr_info("CPU: moved %sTCM%d %dk to %08x, enabled\n",
type ? "I" : "D",
bank,
tcm_size,
(tcm_region & 0xfffff000U));
return 0;
}
void __init tcm_init(void)
{
u32 tcm_status;
u8 dtcm_banks;
u8 itcm_banks;
size_t dtcm_code_sz = &__edtcm_data - &__sdtcm_data;
size_t itcm_code_sz = &__eitcm_text - &__sitcm_text;
char *start;
char *end;
char *ram;
int ret;
int i;
if (cpu_architecture() < CPU_ARCH_ARMv5) {
if (dtcm_code_sz || itcm_code_sz)
pr_info("CPU TCM: %u bytes of DTCM and %u bytes of "
"ITCM code compiled in, but no TCM present "
"in pre-v5 CPU\n", dtcm_code_sz, itcm_code_sz);
return;
}
tcm_status = read_cpuid_tcmstatus();
dtcm_banks = (tcm_status >> 16) & 0x03;
itcm_banks = (tcm_status & 0x03);
if (dtcm_banks > 2)
dtcm_banks = 0;
if (itcm_banks > 2)
itcm_banks = 0;
if (dtcm_banks > 0) {
for (i = 0; i < dtcm_banks; i++) {
ret = setup_tcm_bank(0, i, dtcm_banks, &dtcm_end);
if (ret)
return;
}
if (dtcm_code_sz > (dtcm_end - DTCM_OFFSET)) {
pr_info("CPU DTCM: %u bytes of code compiled to "
"DTCM but only %lu bytes of DTCM present\n",
dtcm_code_sz, (dtcm_end - DTCM_OFFSET));
goto no_dtcm;
}
dtcm_res.end = dtcm_end - 1;
request_resource(&iomem_resource, &dtcm_res);
dtcm_iomap[0].length = dtcm_end - DTCM_OFFSET;
iotable_init(dtcm_iomap, 1);
start = &__sdtcm_data;
end = &__edtcm_data;
ram = &__dtcm_start;
memcpy(start, ram, dtcm_code_sz);
pr_debug("CPU DTCM: copied data from %p - %p\n",
start, end);
dtcm_present = true;
} else if (dtcm_code_sz) {
pr_info("CPU DTCM: %u bytes of code compiled to DTCM but no "
"DTCM banks present in CPU\n", dtcm_code_sz);
}
no_dtcm:
if (itcm_banks > 0) {
for (i = 0; i < itcm_banks; i++) {
ret = setup_tcm_bank(1, i, itcm_banks, &itcm_end);
if (ret)
return;
}
if (itcm_code_sz > (itcm_end - ITCM_OFFSET)) {
pr_info("CPU ITCM: %u bytes of code compiled to "
"ITCM but only %lu bytes of ITCM present\n",
itcm_code_sz, (itcm_end - ITCM_OFFSET));
return;
}
itcm_res.end = itcm_end - 1;
request_resource(&iomem_resource, &itcm_res);
itcm_iomap[0].length = itcm_end - ITCM_OFFSET;
iotable_init(itcm_iomap, 1);
start = &__sitcm_text;
end = &__eitcm_text;
ram = &__itcm_start;
memcpy(start, ram, itcm_code_sz);
pr_debug("CPU ITCM: copied code from %p - %p\n",
start, end);
itcm_present = true;
} else if (itcm_code_sz) {
pr_info("CPU ITCM: %u bytes of code compiled to ITCM but no "
"ITCM banks present in CPU\n", itcm_code_sz);
}
}
static int __init setup_tcm_pool(void)
{
u32 dtcm_pool_start = (u32) &__edtcm_data;
u32 itcm_pool_start = (u32) &__eitcm_text;
int ret;
tcm_pool = gen_pool_create(2, -1);
pr_debug("Setting up TCM memory pool\n");
if (dtcm_present) {
if (dtcm_pool_start < dtcm_end) {
ret = gen_pool_add(tcm_pool, dtcm_pool_start,
dtcm_end - dtcm_pool_start, -1);
if (ret) {
pr_err("CPU DTCM: could not add DTCM " \
"remainder to pool!\n");
return ret;
}
pr_debug("CPU DTCM: Added %08x bytes @ %08x to " \
"the TCM memory pool\n",
dtcm_end - dtcm_pool_start,
dtcm_pool_start);
}
}
if (itcm_present) {
if (itcm_pool_start < itcm_end) {
ret = gen_pool_add(tcm_pool, itcm_pool_start,
itcm_end - itcm_pool_start, -1);
if (ret) {
pr_err("CPU ITCM: could not add ITCM " \
"remainder to pool!\n");
return ret;
}
pr_debug("CPU ITCM: Added %08x bytes @ %08x to " \
"the TCM memory pool\n",
itcm_end - itcm_pool_start,
itcm_pool_start);
}
}
return 0;
}
