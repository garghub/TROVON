static inline u32 __init get_synci_step(void)
{
u32 res;
__asm__("rdhwr %0, $1" : "=r" (res));
return res;
}
static void __init sync_icache(void *kbase, unsigned long kernel_length)
{
void *kend = kbase + kernel_length;
u32 step = get_synci_step();
do {
__asm__ __volatile__(
"synci 0(%0)"
:
: "r" (kbase));
kbase += step;
} while (kbase < kend);
__sync();
}
static int __init apply_r_mips_64_rel(u32 *loc_orig, u32 *loc_new, long offset)
{
*(u64 *)loc_new += offset;
return 0;
}
static int __init apply_r_mips_32_rel(u32 *loc_orig, u32 *loc_new, long offset)
{
*loc_new += offset;
return 0;
}
static int __init apply_r_mips_26_rel(u32 *loc_orig, u32 *loc_new, long offset)
{
unsigned long target_addr = (*loc_orig) & 0x03ffffff;
if (offset % 4) {
pr_err("Dangerous R_MIPS_26 REL relocation\n");
return -ENOEXEC;
}
target_addr <<= 2;
target_addr += (unsigned long)loc_orig & ~0x03ffffff;
target_addr += offset;
if ((target_addr & 0xf0000000) != ((unsigned long)loc_new & 0xf0000000)) {
pr_err("R_MIPS_26 REL relocation overflow\n");
return -ENOEXEC;
}
target_addr -= (unsigned long)loc_new & ~0x03ffffff;
target_addr >>= 2;
*loc_new = (*loc_new & ~0x03ffffff) | (target_addr & 0x03ffffff);
return 0;
}
static int __init apply_r_mips_hi16_rel(u32 *loc_orig, u32 *loc_new, long offset)
{
unsigned long insn = *loc_orig;
unsigned long target = (insn & 0xffff) << 16;
target += offset;
*loc_new = (insn & ~0xffff) | ((target >> 16) & 0xffff);
return 0;
}
int __init do_relocations(void *kbase_old, void *kbase_new, long offset)
{
u32 *r;
u32 *loc_orig;
u32 *loc_new;
int type;
int res;
for (r = _relocation_start; r < _relocation_end; r++) {
if (*r == 0)
break;
type = (*r >> 24) & 0xff;
loc_orig = (void *)(kbase_old + ((*r & 0x00ffffff) << 2));
loc_new = RELOCATED(loc_orig);
if (reloc_handlers_rel[type] == NULL) {
pr_err("Unhandled relocation type %d at 0x%pK\n",
type, loc_orig);
return -ENOEXEC;
}
res = reloc_handlers_rel[type](loc_orig, loc_new, offset);
if (res)
return res;
}
return 0;
}
static int __init relocate_exception_table(long offset)
{
unsigned long *etable_start, *etable_end, *e;
etable_start = RELOCATED(&__start___ex_table);
etable_end = RELOCATED(&__stop___ex_table);
for (e = etable_start; e < etable_end; e++)
*e += offset;
return 0;
}
static inline __init unsigned long rotate_xor(unsigned long hash,
const void *area, size_t size)
{
size_t i;
unsigned long *ptr = (unsigned long *)area;
for (i = 0; i < size / sizeof(hash); i++) {
hash = (hash << ((sizeof(hash) * 8) - 7)) | (hash >> 7);
hash ^= ptr[i];
}
return hash;
}
static inline __init unsigned long get_random_boot(void)
{
unsigned long entropy = random_get_entropy();
unsigned long hash = 0;
hash = rotate_xor(hash, linux_banner, strlen(linux_banner));
hash = rotate_xor(hash, &entropy, sizeof(entropy));
#if defined(CONFIG_USE_OF)
if (initial_boot_params) {
int node, len;
u64 *prop;
node = fdt_path_offset(initial_boot_params, "/chosen");
if (node >= 0) {
prop = fdt_getprop_w(initial_boot_params, node,
"kaslr-seed", &len);
if (prop && (len == sizeof(u64)))
hash = rotate_xor(hash, prop, sizeof(*prop));
}
}
#endif
return hash;
}
static inline __init bool kaslr_disabled(void)
{
char *str;
#if defined(CONFIG_CMDLINE_BOOL)
const char *builtin_cmdline = CONFIG_CMDLINE;
str = strstr(builtin_cmdline, "nokaslr");
if (str == builtin_cmdline ||
(str > builtin_cmdline && *(str - 1) == ' '))
return true;
#endif
str = strstr(arcs_cmdline, "nokaslr");
if (str == arcs_cmdline || (str > arcs_cmdline && *(str - 1) == ' '))
return true;
return false;
}
static inline void __init *determine_relocation_address(void)
{
unsigned long kernel_length;
void *dest = &_text;
unsigned long offset;
if (kaslr_disabled())
return dest;
kernel_length = (long)_end - (long)(&_text);
offset = get_random_boot() << 16;
offset &= (CONFIG_RANDOMIZE_BASE_MAX_OFFSET - 1);
if (offset < kernel_length)
offset += ALIGN(kernel_length, 0xffff);
return RELOCATED(dest);
}
static inline void __init *determine_relocation_address(void)
{
return (void *)0xffffffff81000000;
}
static inline int __init relocation_addr_valid(void *loc_new)
{
if ((unsigned long)loc_new & 0x0000ffff) {
return 0;
}
if ((unsigned long)loc_new < (unsigned long)&_end) {
return 0;
}
return 1;
}
void *__init relocate_kernel(void)
{
void *loc_new;
unsigned long kernel_length;
unsigned long bss_length;
long offset = 0;
int res = 1;
void *kernel_entry = start_kernel;
fw_init_cmdline();
#if defined(CONFIG_USE_OF)
early_init_dt_scan(plat_get_fdt());
if (boot_command_line[0]) {
strlcpy(arcs_cmdline, boot_command_line, COMMAND_LINE_SIZE);
}
#endif
kernel_length = (long)(&_relocation_start) - (long)(&_text);
bss_length = (long)&__bss_stop - (long)&__bss_start;
loc_new = determine_relocation_address();
if (relocation_addr_valid(loc_new))
offset = (unsigned long)loc_new - (unsigned long)(&_text);
arcs_cmdline[0] = '\0';
if (offset) {
memcpy(loc_new, &_text, kernel_length);
res = do_relocations(&_text, loc_new, offset);
if (res < 0)
goto out;
sync_icache(loc_new, kernel_length);
res = relocate_exception_table(offset);
if (res < 0)
goto out;
memcpy(RELOCATED(&__bss_start), &__bss_start, bss_length);
__current_thread_info = RELOCATED(&init_thread_union);
kernel_entry = RELOCATED(start_kernel);
}
out:
return kernel_entry;
}
void show_kernel_relocation(const char *level)
{
unsigned long offset;
offset = __pa_symbol(_text) - __pa_symbol(VMLINUX_LOAD_ADDRESS);
if (IS_ENABLED(CONFIG_RELOCATABLE) && offset > 0) {
printk(level);
pr_cont("Kernel relocated by 0x%pK\n", (void *)offset);
pr_cont(" .text @ 0x%pK\n", _text);
pr_cont(" .data @ 0x%pK\n", _sdata);
pr_cont(" .bss @ 0x%pK\n", __bss_start);
}
}
static int kernel_location_notifier_fn(struct notifier_block *self,
unsigned long v, void *p)
{
show_kernel_relocation(KERN_EMERG);
return NOTIFY_DONE;
}
static int __init register_kernel_offset_dumper(void)
{
atomic_notifier_chain_register(&panic_notifier_list,
&kernel_location_notifier);
return 0;
}
