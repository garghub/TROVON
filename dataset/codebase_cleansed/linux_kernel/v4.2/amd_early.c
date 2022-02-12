static struct cpio_data __init find_ucode_in_initrd(void)
{
long offset = 0;
char *path;
void *start;
size_t size;
#ifdef CONFIG_X86_32
struct boot_params *p;
p = (struct boot_params *)__pa_nodebug(&boot_params);
path = (char *)__pa_nodebug(ucode_path);
start = (void *)p->hdr.ramdisk_image;
size = p->hdr.ramdisk_size;
#else
path = ucode_path;
start = (void *)(boot_params.hdr.ramdisk_image + PAGE_OFFSET);
size = boot_params.hdr.ramdisk_size;
#endif
return find_cpio_data(path, start, size, &offset);
}
static size_t compute_container_size(u8 *data, u32 total_size)
{
size_t size = 0;
u32 *header = (u32 *)data;
if (header[0] != UCODE_MAGIC ||
header[1] != UCODE_EQUIV_CPU_TABLE_TYPE ||
header[2] == 0)
return size;
size = header[2] + CONTAINER_HDR_SZ;
total_size -= size;
data += size;
while (total_size) {
u16 patch_size;
header = (u32 *)data;
if (header[0] != UCODE_UCODE_TYPE)
break;
patch_size = header[1];
if (patch_size > PATCH_MAX_SIZE)
break;
size += patch_size + SECTION_HDR_SIZE;
data += patch_size + SECTION_HDR_SIZE;
total_size -= patch_size + SECTION_HDR_SIZE;
}
return size;
}
static void apply_ucode_in_initrd(void *ucode, size_t size, bool save_patch)
{
struct equiv_cpu_entry *eq;
size_t *cont_sz;
u32 *header;
u8 *data, **cont;
u8 (*patch)[PATCH_MAX_SIZE];
u16 eq_id = 0;
int offset, left;
u32 rev, eax, ebx, ecx, edx;
u32 *new_rev;
#ifdef CONFIG_X86_32
new_rev = (u32 *)__pa_nodebug(&ucode_new_rev);
cont_sz = (size_t *)__pa_nodebug(&container_size);
cont = (u8 **)__pa_nodebug(&container);
patch = (u8 (*)[PATCH_MAX_SIZE])__pa_nodebug(&amd_ucode_patch);
#else
new_rev = &ucode_new_rev;
cont_sz = &container_size;
cont = &container;
patch = &amd_ucode_patch;
#endif
data = ucode;
left = size;
header = (u32 *)data;
if (header[0] != UCODE_MAGIC ||
header[1] != UCODE_EQUIV_CPU_TABLE_TYPE ||
header[2] == 0)
return;
eax = 0x00000001;
ecx = 0;
native_cpuid(&eax, &ebx, &ecx, &edx);
while (left > 0) {
eq = (struct equiv_cpu_entry *)(data + CONTAINER_HDR_SZ);
*cont = data;
offset = header[2] + CONTAINER_HDR_SZ;
data += offset;
left -= offset;
eq_id = find_equiv_id(eq, eax);
if (eq_id) {
this_equiv_id = eq_id;
*cont_sz = compute_container_size(*cont, left + offset);
left = *cont_sz - offset;
break;
}
while (left > 0) {
header = (u32 *)data;
if (header[0] == UCODE_MAGIC &&
header[1] == UCODE_EQUIV_CPU_TABLE_TYPE)
break;
offset = header[1] + SECTION_HDR_SIZE;
data += offset;
left -= offset;
}
offset = data - (u8 *)ucode;
ucode = data;
}
if (!eq_id) {
*cont = NULL;
*cont_sz = 0;
return;
}
native_rdmsr(MSR_AMD64_PATCH_LEVEL, rev, eax);
while (left > 0) {
struct microcode_amd *mc;
header = (u32 *)data;
if (header[0] != UCODE_UCODE_TYPE ||
header[1] == 0)
break;
mc = (struct microcode_amd *)(data + SECTION_HDR_SIZE);
if (eq_id == mc->hdr.processor_rev_id && rev < mc->hdr.patch_id) {
if (!__apply_microcode_amd(mc)) {
rev = mc->hdr.patch_id;
*new_rev = rev;
if (save_patch)
memcpy(patch, mc,
min_t(u32, header[1], PATCH_MAX_SIZE));
}
}
offset = header[1] + SECTION_HDR_SIZE;
data += offset;
left -= offset;
}
}
static bool __init load_builtin_amd_microcode(struct cpio_data *cp,
unsigned int family)
{
#ifdef CONFIG_X86_64
char fw_name[36] = "amd-ucode/microcode_amd.bin";
if (family >= 0x15)
snprintf(fw_name, sizeof(fw_name),
"amd-ucode/microcode_amd_fam%.2xh.bin", family);
return get_builtin_firmware(cp, fw_name);
#else
return false;
#endif
}
void __init load_ucode_amd_bsp(unsigned int family)
{
struct cpio_data cp;
void **data;
size_t *size;
#ifdef CONFIG_X86_32
data = (void **)__pa_nodebug(&ucode_cpio.data);
size = (size_t *)__pa_nodebug(&ucode_cpio.size);
#else
data = &ucode_cpio.data;
size = &ucode_cpio.size;
#endif
cp = find_ucode_in_initrd();
if (!cp.data) {
if (!load_builtin_amd_microcode(&cp, family))
return;
}
*data = cp.data;
*size = cp.size;
apply_ucode_in_initrd(cp.data, cp.size, true);
}
void load_ucode_amd_ap(void)
{
struct microcode_amd *mc;
size_t *usize;
void **ucode;
mc = (struct microcode_amd *)__pa_nodebug(amd_ucode_patch);
if (mc->hdr.patch_id && mc->hdr.processor_rev_id) {
__apply_microcode_amd(mc);
return;
}
ucode = (void *)__pa_nodebug(&container);
usize = (size_t *)__pa_nodebug(&container_size);
if (!*ucode || !*usize)
return;
apply_ucode_in_initrd(*ucode, *usize, false);
}
static void __init collect_cpu_sig_on_bsp(void *arg)
{
unsigned int cpu = smp_processor_id();
struct ucode_cpu_info *uci = ucode_cpu_info + cpu;
uci->cpu_sig.sig = cpuid_eax(0x00000001);
}
static void __init get_bsp_sig(void)
{
unsigned int bsp = boot_cpu_data.cpu_index;
struct ucode_cpu_info *uci = ucode_cpu_info + bsp;
if (!uci->cpu_sig.sig)
smp_call_function_single(bsp, collect_cpu_sig_on_bsp, NULL, 1);
}
void load_ucode_amd_ap(void)
{
unsigned int cpu = smp_processor_id();
struct ucode_cpu_info *uci = ucode_cpu_info + cpu;
struct equiv_cpu_entry *eq;
struct microcode_amd *mc;
u32 rev, eax;
u16 eq_id;
if (!cpu)
return;
if (!container)
return;
rdmsr(MSR_AMD64_PATCH_LEVEL, rev, eax);
uci->cpu_sig.rev = rev;
uci->cpu_sig.sig = eax;
eax = cpuid_eax(0x00000001);
eq = (struct equiv_cpu_entry *)(container + CONTAINER_HDR_SZ);
eq_id = find_equiv_id(eq, eax);
if (!eq_id)
return;
if (eq_id == this_equiv_id) {
mc = (struct microcode_amd *)amd_ucode_patch;
if (mc && rev < mc->hdr.patch_id) {
if (!__apply_microcode_amd(mc))
ucode_new_rev = mc->hdr.patch_id;
}
} else {
if (!ucode_cpio.data)
return;
apply_ucode_in_initrd(ucode_cpio.data, ucode_cpio.size, false);
}
}
int __init save_microcode_in_initrd_amd(void)
{
unsigned long cont;
int retval = 0;
enum ucode_state ret;
u8 *cont_va;
u32 eax;
if (!container)
return -EINVAL;
#ifdef CONFIG_X86_32
get_bsp_sig();
cont = (unsigned long)container;
cont_va = __va(container);
#else
cont = __pa(container);
cont_va = container;
#endif
if (relocated_ramdisk)
container = (u8 *)(__va(relocated_ramdisk) +
(cont - boot_params.hdr.ramdisk_image));
else
container = cont_va;
if (ucode_new_rev)
pr_info("microcode: updated early to new patch_level=0x%08x\n",
ucode_new_rev);
eax = cpuid_eax(0x00000001);
eax = ((eax >> 8) & 0xf) + ((eax >> 20) & 0xff);
ret = load_microcode_amd(smp_processor_id(), eax, container, container_size);
if (ret != UCODE_OK)
retval = -EINVAL;
container = NULL;
container_size = 0;
return retval;
}
void reload_ucode_amd(void)
{
struct microcode_amd *mc;
u32 rev, eax;
rdmsr(MSR_AMD64_PATCH_LEVEL, rev, eax);
mc = (struct microcode_amd *)amd_ucode_patch;
if (mc && rev < mc->hdr.patch_id) {
if (!__apply_microcode_amd(mc)) {
ucode_new_rev = mc->hdr.patch_id;
pr_info("microcode: reload patch_level=0x%08x\n",
ucode_new_rev);
}
}
}
