static enum ucode_state
generic_load_microcode_early(struct microcode_intel **mc_saved_p,
unsigned int mc_saved_count,
struct ucode_cpu_info *uci)
{
struct microcode_intel *ucode_ptr, *new_mc = NULL;
int new_rev = uci->cpu_sig.rev;
enum ucode_state state = UCODE_OK;
unsigned int mc_size;
struct microcode_header_intel *mc_header;
unsigned int csig = uci->cpu_sig.sig;
unsigned int cpf = uci->cpu_sig.pf;
int i;
for (i = 0; i < mc_saved_count; i++) {
ucode_ptr = mc_saved_p[i];
mc_header = (struct microcode_header_intel *)ucode_ptr;
mc_size = get_totalsize(mc_header);
if (get_matching_microcode(csig, cpf, ucode_ptr, new_rev)) {
new_rev = mc_header->rev;
new_mc = ucode_ptr;
}
}
if (!new_mc) {
state = UCODE_NFOUND;
goto out;
}
uci->mc = (struct microcode_intel *)new_mc;
out:
return state;
}
static void
microcode_pointer(struct microcode_intel **mc_saved,
unsigned long *mc_saved_in_initrd,
unsigned long initrd_start, int mc_saved_count)
{
int i;
for (i = 0; i < mc_saved_count; i++)
mc_saved[i] = (struct microcode_intel *)
(mc_saved_in_initrd[i] + initrd_start);
}
static void
microcode_phys(struct microcode_intel **mc_saved_tmp,
struct mc_saved_data *mc_saved_data)
{
int i;
struct microcode_intel ***mc_saved;
mc_saved = (struct microcode_intel ***)
__pa_nodebug(&mc_saved_data->mc_saved);
for (i = 0; i < mc_saved_data->mc_saved_count; i++) {
struct microcode_intel *p;
p = *(struct microcode_intel **)
__pa_nodebug(mc_saved_data->mc_saved + i);
mc_saved_tmp[i] = (struct microcode_intel *)__pa_nodebug(p);
}
}
static enum ucode_state
load_microcode(struct mc_saved_data *mc_saved_data,
unsigned long *mc_saved_in_initrd,
unsigned long initrd_start,
struct ucode_cpu_info *uci)
{
struct microcode_intel *mc_saved_tmp[MAX_UCODE_COUNT];
unsigned int count = mc_saved_data->mc_saved_count;
if (!mc_saved_data->mc_saved) {
microcode_pointer(mc_saved_tmp, mc_saved_in_initrd,
initrd_start, count);
return generic_load_microcode_early(mc_saved_tmp, count, uci);
} else {
#ifdef CONFIG_X86_32
microcode_phys(mc_saved_tmp, mc_saved_data);
return generic_load_microcode_early(mc_saved_tmp, count, uci);
#else
return generic_load_microcode_early(mc_saved_data->mc_saved,
count, uci);
#endif
}
}
static u8 get_x86_family(unsigned long sig)
{
u8 x86;
x86 = (sig >> 8) & 0xf;
if (x86 == 0xf)
x86 += (sig >> 20) & 0xff;
return x86;
}
static u8 get_x86_model(unsigned long sig)
{
u8 x86, x86_model;
x86 = get_x86_family(sig);
x86_model = (sig >> 4) & 0xf;
if (x86 == 0x6 || x86 == 0xf)
x86_model += ((sig >> 16) & 0xf) << 4;
return x86_model;
}
static enum ucode_state
matching_model_microcode(struct microcode_header_intel *mc_header,
unsigned long sig)
{
u8 x86, x86_model;
u8 x86_ucode, x86_model_ucode;
struct extended_sigtable *ext_header;
unsigned long total_size = get_totalsize(mc_header);
unsigned long data_size = get_datasize(mc_header);
int ext_sigcount, i;
struct extended_signature *ext_sig;
x86 = get_x86_family(sig);
x86_model = get_x86_model(sig);
x86_ucode = get_x86_family(mc_header->sig);
x86_model_ucode = get_x86_model(mc_header->sig);
if (x86 == x86_ucode && x86_model == x86_model_ucode)
return UCODE_OK;
if (total_size <= data_size + MC_HEADER_SIZE)
return UCODE_NFOUND;
ext_header = (struct extended_sigtable *)
mc_header + data_size + MC_HEADER_SIZE;
ext_sigcount = ext_header->count;
ext_sig = (void *)ext_header + EXT_HEADER_SIZE;
for (i = 0; i < ext_sigcount; i++) {
x86_ucode = get_x86_family(ext_sig->sig);
x86_model_ucode = get_x86_model(ext_sig->sig);
if (x86 == x86_ucode && x86_model == x86_model_ucode)
return UCODE_OK;
ext_sig++;
}
return UCODE_NFOUND;
}
static int
save_microcode(struct mc_saved_data *mc_saved_data,
struct microcode_intel **mc_saved_src,
unsigned int mc_saved_count)
{
int i, j;
struct microcode_intel **mc_saved_p;
int ret;
if (!mc_saved_count)
return -EINVAL;
mc_saved_p = kmalloc(mc_saved_count*sizeof(struct microcode_intel *),
GFP_KERNEL);
if (!mc_saved_p)
return -ENOMEM;
for (i = 0; i < mc_saved_count; i++) {
struct microcode_intel *mc = mc_saved_src[i];
struct microcode_header_intel *mc_header = &mc->hdr;
unsigned long mc_size = get_totalsize(mc_header);
mc_saved_p[i] = kmalloc(mc_size, GFP_KERNEL);
if (!mc_saved_p[i]) {
ret = -ENOMEM;
goto err;
}
if (!mc_saved_src[i]) {
ret = -EINVAL;
goto err;
}
memcpy(mc_saved_p[i], mc, mc_size);
}
mc_saved_data->mc_saved = mc_saved_p;
mc_saved_data->mc_saved_count = mc_saved_count;
return 0;
err:
for (j = 0; j <= i; j++)
kfree(mc_saved_p[j]);
kfree(mc_saved_p);
return ret;
}
static void _save_mc(struct microcode_intel **mc_saved, u8 *ucode_ptr,
unsigned int *mc_saved_count_p)
{
int i;
int found = 0;
unsigned int mc_saved_count = *mc_saved_count_p;
struct microcode_header_intel *mc_header;
mc_header = (struct microcode_header_intel *)ucode_ptr;
for (i = 0; i < mc_saved_count; i++) {
unsigned int sig, pf;
unsigned int new_rev;
struct microcode_header_intel *mc_saved_header =
(struct microcode_header_intel *)mc_saved[i];
sig = mc_saved_header->sig;
pf = mc_saved_header->pf;
new_rev = mc_header->rev;
if (get_matching_sig(sig, pf, ucode_ptr, new_rev)) {
found = 1;
if (update_match_revision(mc_header, new_rev)) {
mc_saved[i] =
(struct microcode_intel *)ucode_ptr;
break;
}
}
}
if (i >= mc_saved_count && !found)
mc_saved[mc_saved_count++] =
(struct microcode_intel *)ucode_ptr;
*mc_saved_count_p = mc_saved_count;
}
static enum ucode_state __init
get_matching_model_microcode(int cpu, unsigned long start,
void *data, size_t size,
struct mc_saved_data *mc_saved_data,
unsigned long *mc_saved_in_initrd,
struct ucode_cpu_info *uci)
{
u8 *ucode_ptr = data;
unsigned int leftover = size;
enum ucode_state state = UCODE_OK;
unsigned int mc_size;
struct microcode_header_intel *mc_header;
struct microcode_intel *mc_saved_tmp[MAX_UCODE_COUNT];
unsigned int mc_saved_count = mc_saved_data->mc_saved_count;
int i;
while (leftover) {
mc_header = (struct microcode_header_intel *)ucode_ptr;
mc_size = get_totalsize(mc_header);
if (!mc_size || mc_size > leftover ||
microcode_sanity_check(ucode_ptr, 0) < 0)
break;
leftover -= mc_size;
if (matching_model_microcode(mc_header, uci->cpu_sig.sig) !=
UCODE_OK) {
ucode_ptr += mc_size;
continue;
}
_save_mc(mc_saved_tmp, ucode_ptr, &mc_saved_count);
ucode_ptr += mc_size;
}
if (leftover) {
state = UCODE_ERROR;
goto out;
}
if (mc_saved_count == 0) {
state = UCODE_NFOUND;
goto out;
}
for (i = 0; i < mc_saved_count; i++)
mc_saved_in_initrd[i] = (unsigned long)mc_saved_tmp[i] - start;
mc_saved_data->mc_saved_count = mc_saved_count;
out:
return state;
}
static int collect_cpu_info_early(struct ucode_cpu_info *uci)
{
unsigned int val[2];
u8 x86, x86_model;
struct cpu_signature csig;
unsigned int eax, ebx, ecx, edx;
csig.sig = 0;
csig.pf = 0;
csig.rev = 0;
memset(uci, 0, sizeof(*uci));
eax = 0x00000001;
ecx = 0;
native_cpuid(&eax, &ebx, &ecx, &edx);
csig.sig = eax;
x86 = get_x86_family(csig.sig);
x86_model = get_x86_model(csig.sig);
if ((x86_model >= 5) || (x86 > 6)) {
native_rdmsr(MSR_IA32_PLATFORM_ID, val[0], val[1]);
csig.pf = 1 << ((val[1] >> 18) & 7);
}
native_wrmsr(MSR_IA32_UCODE_REV, 0, 0);
sync_core();
native_rdmsr(MSR_IA32_UCODE_REV, val[0], val[1]);
csig.rev = val[1];
uci->cpu_sig = csig;
uci->valid = 1;
return 0;
}
static void __ref show_saved_mc(void)
{
int i, j;
unsigned int sig, pf, rev, total_size, data_size, date;
struct ucode_cpu_info uci;
if (mc_saved_data.mc_saved_count == 0) {
pr_debug("no microcode data saved.\n");
return;
}
pr_debug("Total microcode saved: %d\n", mc_saved_data.mc_saved_count);
collect_cpu_info_early(&uci);
sig = uci.cpu_sig.sig;
pf = uci.cpu_sig.pf;
rev = uci.cpu_sig.rev;
pr_debug("CPU%d: sig=0x%x, pf=0x%x, rev=0x%x\n",
smp_processor_id(), sig, pf, rev);
for (i = 0; i < mc_saved_data.mc_saved_count; i++) {
struct microcode_header_intel *mc_saved_header;
struct extended_sigtable *ext_header;
int ext_sigcount;
struct extended_signature *ext_sig;
mc_saved_header = (struct microcode_header_intel *)
mc_saved_data.mc_saved[i];
sig = mc_saved_header->sig;
pf = mc_saved_header->pf;
rev = mc_saved_header->rev;
total_size = get_totalsize(mc_saved_header);
data_size = get_datasize(mc_saved_header);
date = mc_saved_header->date;
pr_debug("mc_saved[%d]: sig=0x%x, pf=0x%x, rev=0x%x, toal size=0x%x, date = %04x-%02x-%02x\n",
i, sig, pf, rev, total_size,
date & 0xffff,
date >> 24,
(date >> 16) & 0xff);
if (total_size <= data_size + MC_HEADER_SIZE)
continue;
ext_header = (struct extended_sigtable *)
mc_saved_header + data_size + MC_HEADER_SIZE;
ext_sigcount = ext_header->count;
ext_sig = (void *)ext_header + EXT_HEADER_SIZE;
for (j = 0; j < ext_sigcount; j++) {
sig = ext_sig->sig;
pf = ext_sig->pf;
pr_debug("\tExtended[%d]: sig=0x%x, pf=0x%x\n",
j, sig, pf);
ext_sig++;
}
}
}
static inline void show_saved_mc(void)
{
}
int save_mc_for_early(u8 *mc)
{
struct microcode_intel *mc_saved_tmp[MAX_UCODE_COUNT];
unsigned int mc_saved_count_init;
unsigned int mc_saved_count;
struct microcode_intel **mc_saved;
int ret = 0;
int i;
mutex_lock(&x86_cpu_microcode_mutex);
mc_saved_count_init = mc_saved_data.mc_saved_count;
mc_saved_count = mc_saved_data.mc_saved_count;
mc_saved = mc_saved_data.mc_saved;
if (mc_saved && mc_saved_count)
memcpy(mc_saved_tmp, mc_saved,
mc_saved_count * sizeof(struct microcode_intel *));
_save_mc(mc_saved_tmp, mc, &mc_saved_count);
ret = save_microcode(&mc_saved_data, mc_saved_tmp, mc_saved_count);
if (ret) {
pr_err("Cannot save microcode patch.\n");
goto out;
}
show_saved_mc();
if (mc_saved) {
for (i = 0; i < mc_saved_count_init; i++)
kfree(mc_saved[i]);
kfree(mc_saved);
}
out:
mutex_unlock(&x86_cpu_microcode_mutex);
return ret;
}
static __init enum ucode_state
scan_microcode(unsigned long start, unsigned long end,
struct mc_saved_data *mc_saved_data,
unsigned long *mc_saved_in_initrd,
struct ucode_cpu_info *uci)
{
unsigned int size = end - start + 1;
struct cpio_data cd;
long offset = 0;
#ifdef CONFIG_X86_32
char *p = (char *)__pa_nodebug(ucode_name);
#else
char *p = ucode_name;
#endif
cd.data = NULL;
cd.size = 0;
cd = find_cpio_data(p, (void *)start, size, &offset);
if (!cd.data)
return UCODE_ERROR;
return get_matching_model_microcode(0, start, cd.data, cd.size,
mc_saved_data, mc_saved_in_initrd,
uci);
}
static void
print_ucode_info(struct ucode_cpu_info *uci, unsigned int date)
{
int cpu = smp_processor_id();
pr_info("CPU%d microcode updated early to revision 0x%x, date = %04x-%02x-%02x\n",
cpu,
uci->cpu_sig.rev,
date & 0xffff,
date >> 24,
(date >> 16) & 0xff);
}
void show_ucode_info_early(void)
{
struct ucode_cpu_info uci;
if (delay_ucode_info) {
collect_cpu_info_early(&uci);
print_ucode_info(&uci, current_mc_date);
delay_ucode_info = 0;
}
}
static void print_ucode(struct ucode_cpu_info *uci)
{
struct microcode_intel *mc_intel;
int *delay_ucode_info_p;
int *current_mc_date_p;
mc_intel = uci->mc;
if (mc_intel == NULL)
return;
delay_ucode_info_p = (int *)__pa_nodebug(&delay_ucode_info);
current_mc_date_p = (int *)__pa_nodebug(&current_mc_date);
*delay_ucode_info_p = 1;
*current_mc_date_p = mc_intel->hdr.date;
}
static inline void flush_tlb_early(void)
{
__native_flush_tlb_global_irq_disabled();
}
static inline void print_ucode(struct ucode_cpu_info *uci)
{
struct microcode_intel *mc_intel;
mc_intel = uci->mc;
if (mc_intel == NULL)
return;
print_ucode_info(uci, mc_intel->hdr.date);
}
static int apply_microcode_early(struct mc_saved_data *mc_saved_data,
struct ucode_cpu_info *uci)
{
struct microcode_intel *mc_intel;
unsigned int val[2];
mc_intel = uci->mc;
if (mc_intel == NULL)
return 0;
native_wrmsr(MSR_IA32_UCODE_WRITE,
(unsigned long) mc_intel->bits,
(unsigned long) mc_intel->bits >> 16 >> 16);
native_wrmsr(MSR_IA32_UCODE_REV, 0, 0);
sync_core();
native_rdmsr(MSR_IA32_UCODE_REV, val[0], val[1]);
if (val[1] != mc_intel->hdr.rev)
return -1;
#ifdef CONFIG_X86_64
flush_tlb_early();
#endif
uci->cpu_sig.rev = val[1];
print_ucode(uci);
return 0;
}
int __init save_microcode_in_initrd_intel(void)
{
unsigned int count = mc_saved_data.mc_saved_count;
struct microcode_intel *mc_saved[MAX_UCODE_COUNT];
int ret = 0;
if (count == 0)
return ret;
microcode_pointer(mc_saved, mc_saved_in_initrd, initrd_start, count);
ret = save_microcode(&mc_saved_data, mc_saved, count);
if (ret)
pr_err("Cannot save microcode patches from initrd.\n");
show_saved_mc();
return ret;
}
static void __init
_load_ucode_intel_bsp(struct mc_saved_data *mc_saved_data,
unsigned long *mc_saved_in_initrd,
unsigned long initrd_start_early,
unsigned long initrd_end_early,
struct ucode_cpu_info *uci)
{
collect_cpu_info_early(uci);
scan_microcode(initrd_start_early, initrd_end_early, mc_saved_data,
mc_saved_in_initrd, uci);
load_microcode(mc_saved_data, mc_saved_in_initrd,
initrd_start_early, uci);
apply_microcode_early(mc_saved_data, uci);
}
void __init
load_ucode_intel_bsp(void)
{
u64 ramdisk_image, ramdisk_size;
unsigned long initrd_start_early, initrd_end_early;
struct ucode_cpu_info uci;
#ifdef CONFIG_X86_32
struct boot_params *boot_params_p;
boot_params_p = (struct boot_params *)__pa_nodebug(&boot_params);
ramdisk_image = boot_params_p->hdr.ramdisk_image;
ramdisk_size = boot_params_p->hdr.ramdisk_size;
initrd_start_early = ramdisk_image;
initrd_end_early = initrd_start_early + ramdisk_size;
_load_ucode_intel_bsp(
(struct mc_saved_data *)__pa_nodebug(&mc_saved_data),
(unsigned long *)__pa_nodebug(&mc_saved_in_initrd),
initrd_start_early, initrd_end_early, &uci);
#else
ramdisk_image = boot_params.hdr.ramdisk_image;
ramdisk_size = boot_params.hdr.ramdisk_size;
initrd_start_early = ramdisk_image + PAGE_OFFSET;
initrd_end_early = initrd_start_early + ramdisk_size;
_load_ucode_intel_bsp(&mc_saved_data, mc_saved_in_initrd,
initrd_start_early, initrd_end_early, &uci);
#endif
}
void load_ucode_intel_ap(void)
{
struct mc_saved_data *mc_saved_data_p;
struct ucode_cpu_info uci;
unsigned long *mc_saved_in_initrd_p;
unsigned long initrd_start_addr;
#ifdef CONFIG_X86_32
unsigned long *initrd_start_p;
mc_saved_in_initrd_p =
(unsigned long *)__pa_nodebug(mc_saved_in_initrd);
mc_saved_data_p = (struct mc_saved_data *)__pa_nodebug(&mc_saved_data);
initrd_start_p = (unsigned long *)__pa_nodebug(&initrd_start);
initrd_start_addr = (unsigned long)__pa_nodebug(*initrd_start_p);
#else
mc_saved_data_p = &mc_saved_data;
mc_saved_in_initrd_p = mc_saved_in_initrd;
initrd_start_addr = initrd_start;
#endif
if (mc_saved_data_p->mc_saved_count == 0)
return;
collect_cpu_info_early(&uci);
load_microcode(mc_saved_data_p, mc_saved_in_initrd_p,
initrd_start_addr, &uci);
apply_microcode_early(mc_saved_data_p, &uci);
}
