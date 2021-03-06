static unsigned int *calc_addr(struct fixup_entry *fcur, long offset)
{
return (unsigned int *)((unsigned long)fcur + offset);
}
static int patch_alt_instruction(unsigned int *src, unsigned int *dest,
unsigned int *alt_start, unsigned int *alt_end)
{
unsigned int instr;
instr = *src;
if (instr_is_relative_branch(*src)) {
unsigned int *target = (unsigned int *)branch_target(src);
if (target < alt_start || target >= alt_end) {
instr = translate_branch(dest, src);
if (!instr)
return 1;
}
}
patch_instruction(dest, instr);
return 0;
}
static int patch_feature_section(unsigned long value, struct fixup_entry *fcur)
{
unsigned int *start, *end, *alt_start, *alt_end, *src, *dest;
start = calc_addr(fcur, fcur->start_off);
end = calc_addr(fcur, fcur->end_off);
alt_start = calc_addr(fcur, fcur->alt_start_off);
alt_end = calc_addr(fcur, fcur->alt_end_off);
if ((alt_end - alt_start) > (end - start))
return 1;
if ((value & fcur->mask) == fcur->value)
return 0;
src = alt_start;
dest = start;
for (; src < alt_end; src++, dest++) {
if (patch_alt_instruction(src, dest, alt_start, alt_end))
return 1;
}
for (; dest < end; dest++)
patch_instruction(dest, PPC_INST_NOP);
return 0;
}
void do_feature_fixups(unsigned long value, void *fixup_start, void *fixup_end)
{
struct fixup_entry *fcur, *fend;
fcur = fixup_start;
fend = fixup_end;
for (; fcur < fend; fcur++) {
if (patch_feature_section(value, fcur)) {
WARN_ON(1);
printk("Unable to patch feature section at %p - %p" \
" with %p - %p\n",
calc_addr(fcur, fcur->start_off),
calc_addr(fcur, fcur->end_off),
calc_addr(fcur, fcur->alt_start_off),
calc_addr(fcur, fcur->alt_end_off));
}
}
}
void do_lwsync_fixups(unsigned long value, void *fixup_start, void *fixup_end)
{
long *start, *end;
unsigned int *dest;
if (!(value & CPU_FTR_LWSYNC))
return ;
start = fixup_start;
end = fixup_end;
for (; start < end; start++) {
dest = (void *)start + *start;
patch_instruction(dest, PPC_INST_LWSYNC);
}
}
void do_final_fixups(void)
{
#if defined(CONFIG_PPC64) && defined(CONFIG_RELOCATABLE)
int *src, *dest;
unsigned long length;
if (PHYSICAL_START == 0)
return;
src = (int *)(KERNELBASE + PHYSICAL_START);
dest = (int *)KERNELBASE;
length = (__end_interrupts - _stext) / sizeof(int);
while (length--) {
patch_instruction(dest, *src);
src++;
dest++;
}
#endif
}
static long calc_offset(struct fixup_entry *entry, unsigned int *p)
{
return (unsigned long)p - (unsigned long)entry;
}
static void test_basic_patching(void)
{
extern unsigned int ftr_fixup_test1;
extern unsigned int end_ftr_fixup_test1;
extern unsigned int ftr_fixup_test1_orig;
extern unsigned int ftr_fixup_test1_expected;
int size = &end_ftr_fixup_test1 - &ftr_fixup_test1;
fixup.value = fixup.mask = 8;
fixup.start_off = calc_offset(&fixup, &ftr_fixup_test1 + 1);
fixup.end_off = calc_offset(&fixup, &ftr_fixup_test1 + 2);
fixup.alt_start_off = fixup.alt_end_off = 0;
check(memcmp(&ftr_fixup_test1, &ftr_fixup_test1_orig, size) == 0);
patch_feature_section(8, &fixup);
check(memcmp(&ftr_fixup_test1, &ftr_fixup_test1_orig, size) == 0);
patch_feature_section(0, &fixup);
check(memcmp(&ftr_fixup_test1, &ftr_fixup_test1_expected, size) == 0);
memcpy(&ftr_fixup_test1, &ftr_fixup_test1_orig, size);
check(memcmp(&ftr_fixup_test1, &ftr_fixup_test1_orig, size) == 0);
patch_feature_section(~8, &fixup);
check(memcmp(&ftr_fixup_test1, &ftr_fixup_test1_expected, size) == 0);
}
static void test_alternative_patching(void)
{
extern unsigned int ftr_fixup_test2;
extern unsigned int end_ftr_fixup_test2;
extern unsigned int ftr_fixup_test2_orig;
extern unsigned int ftr_fixup_test2_alt;
extern unsigned int ftr_fixup_test2_expected;
int size = &end_ftr_fixup_test2 - &ftr_fixup_test2;
fixup.value = fixup.mask = 0xF;
fixup.start_off = calc_offset(&fixup, &ftr_fixup_test2 + 1);
fixup.end_off = calc_offset(&fixup, &ftr_fixup_test2 + 2);
fixup.alt_start_off = calc_offset(&fixup, &ftr_fixup_test2_alt);
fixup.alt_end_off = calc_offset(&fixup, &ftr_fixup_test2_alt + 1);
check(memcmp(&ftr_fixup_test2, &ftr_fixup_test2_orig, size) == 0);
patch_feature_section(0xF, &fixup);
check(memcmp(&ftr_fixup_test2, &ftr_fixup_test2_orig, size) == 0);
patch_feature_section(0, &fixup);
check(memcmp(&ftr_fixup_test2, &ftr_fixup_test2_expected, size) == 0);
memcpy(&ftr_fixup_test2, &ftr_fixup_test2_orig, size);
check(memcmp(&ftr_fixup_test2, &ftr_fixup_test2_orig, size) == 0);
patch_feature_section(~0xF, &fixup);
check(memcmp(&ftr_fixup_test2, &ftr_fixup_test2_expected, size) == 0);
}
static void test_alternative_case_too_big(void)
{
extern unsigned int ftr_fixup_test3;
extern unsigned int end_ftr_fixup_test3;
extern unsigned int ftr_fixup_test3_orig;
extern unsigned int ftr_fixup_test3_alt;
int size = &end_ftr_fixup_test3 - &ftr_fixup_test3;
fixup.value = fixup.mask = 0xC;
fixup.start_off = calc_offset(&fixup, &ftr_fixup_test3 + 1);
fixup.end_off = calc_offset(&fixup, &ftr_fixup_test3 + 2);
fixup.alt_start_off = calc_offset(&fixup, &ftr_fixup_test3_alt);
fixup.alt_end_off = calc_offset(&fixup, &ftr_fixup_test3_alt + 2);
check(memcmp(&ftr_fixup_test3, &ftr_fixup_test3_orig, size) == 0);
check(patch_feature_section(0xF, &fixup) == 1);
check(memcmp(&ftr_fixup_test3, &ftr_fixup_test3_orig, size) == 0);
check(patch_feature_section(0, &fixup) == 1);
check(memcmp(&ftr_fixup_test3, &ftr_fixup_test3_orig, size) == 0);
check(patch_feature_section(~0xF, &fixup) == 1);
check(memcmp(&ftr_fixup_test3, &ftr_fixup_test3_orig, size) == 0);
}
static void test_alternative_case_too_small(void)
{
extern unsigned int ftr_fixup_test4;
extern unsigned int end_ftr_fixup_test4;
extern unsigned int ftr_fixup_test4_orig;
extern unsigned int ftr_fixup_test4_alt;
extern unsigned int ftr_fixup_test4_expected;
int size = &end_ftr_fixup_test4 - &ftr_fixup_test4;
unsigned long flag;
flag = 1UL << ((sizeof(unsigned long) - 1) * 8);
fixup.value = fixup.mask = flag;
fixup.start_off = calc_offset(&fixup, &ftr_fixup_test4 + 1);
fixup.end_off = calc_offset(&fixup, &ftr_fixup_test4 + 5);
fixup.alt_start_off = calc_offset(&fixup, &ftr_fixup_test4_alt);
fixup.alt_end_off = calc_offset(&fixup, &ftr_fixup_test4_alt + 2);
check(memcmp(&ftr_fixup_test4, &ftr_fixup_test4_orig, size) == 0);
patch_feature_section(flag, &fixup);
check(memcmp(&ftr_fixup_test4, &ftr_fixup_test4_orig, size) == 0);
patch_feature_section(0, &fixup);
check(memcmp(&ftr_fixup_test4, &ftr_fixup_test4_expected, size) == 0);
memcpy(&ftr_fixup_test4, &ftr_fixup_test4_orig, size);
check(memcmp(&ftr_fixup_test4, &ftr_fixup_test4_orig, size) == 0);
patch_feature_section(~flag, &fixup);
check(memcmp(&ftr_fixup_test4, &ftr_fixup_test4_expected, size) == 0);
}
static void test_alternative_case_with_branch(void)
{
extern unsigned int ftr_fixup_test5;
extern unsigned int end_ftr_fixup_test5;
extern unsigned int ftr_fixup_test5_expected;
int size = &end_ftr_fixup_test5 - &ftr_fixup_test5;
check(memcmp(&ftr_fixup_test5, &ftr_fixup_test5_expected, size) == 0);
}
static void test_alternative_case_with_external_branch(void)
{
extern unsigned int ftr_fixup_test6;
extern unsigned int end_ftr_fixup_test6;
extern unsigned int ftr_fixup_test6_expected;
int size = &end_ftr_fixup_test6 - &ftr_fixup_test6;
check(memcmp(&ftr_fixup_test6, &ftr_fixup_test6_expected, size) == 0);
}
static void test_cpu_macros(void)
{
extern u8 ftr_fixup_test_FTR_macros;
extern u8 ftr_fixup_test_FTR_macros_expected;
unsigned long size = &ftr_fixup_test_FTR_macros_expected -
&ftr_fixup_test_FTR_macros;
check(memcmp(&ftr_fixup_test_FTR_macros,
&ftr_fixup_test_FTR_macros_expected, size) == 0);
}
static void test_fw_macros(void)
{
#ifdef CONFIG_PPC64
extern u8 ftr_fixup_test_FW_FTR_macros;
extern u8 ftr_fixup_test_FW_FTR_macros_expected;
unsigned long size = &ftr_fixup_test_FW_FTR_macros_expected -
&ftr_fixup_test_FW_FTR_macros;
check(memcmp(&ftr_fixup_test_FW_FTR_macros,
&ftr_fixup_test_FW_FTR_macros_expected, size) == 0);
#endif
}
static void test_lwsync_macros(void)
{
extern u8 lwsync_fixup_test;
extern u8 end_lwsync_fixup_test;
extern u8 lwsync_fixup_test_expected_LWSYNC;
extern u8 lwsync_fixup_test_expected_SYNC;
unsigned long size = &end_lwsync_fixup_test -
&lwsync_fixup_test;
if (cur_cpu_spec->cpu_features & CPU_FTR_LWSYNC) {
check(memcmp(&lwsync_fixup_test,
&lwsync_fixup_test_expected_LWSYNC, size) == 0);
} else {
check(memcmp(&lwsync_fixup_test,
&lwsync_fixup_test_expected_SYNC, size) == 0);
}
}
static int __init test_feature_fixups(void)
{
printk(KERN_DEBUG "Running feature fixup self-tests ...\n");
test_basic_patching();
test_alternative_patching();
test_alternative_case_too_big();
test_alternative_case_too_small();
test_alternative_case_with_branch();
test_alternative_case_with_external_branch();
test_cpu_macros();
test_fw_macros();
test_lwsync_macros();
return 0;
}
