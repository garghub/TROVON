static int collect_cpu_info(int cpu_num, struct cpu_signature *csig)
{
struct cpuinfo_x86 *c = &cpu_data(cpu_num);
unsigned int val[2];
memset(csig, 0, sizeof(*csig));
if (c->x86_vendor != X86_VENDOR_INTEL || c->x86 < 6 ||
cpu_has(c, X86_FEATURE_IA64)) {
pr_err("CPU%d not a capable Intel processor\n", cpu_num);
return -1;
}
csig->sig = cpuid_eax(0x00000001);
if ((c->x86_model >= 5) || (c->x86 > 6)) {
rdmsr(MSR_IA32_PLATFORM_ID, val[0], val[1]);
csig->pf = 1 << ((val[1] >> 18) & 7);
}
wrmsr(MSR_IA32_UCODE_REV, 0, 0);
sync_core();
rdmsr(MSR_IA32_UCODE_REV, val[0], csig->rev);
pr_info("CPU%d sig=0x%x, pf=0x%x, revision=0x%x\n",
cpu_num, csig->sig, csig->pf, csig->rev);
return 0;
}
static inline int update_match_cpu(struct cpu_signature *csig, int sig, int pf)
{
return (!sigmatch(sig, csig->sig, pf, csig->pf)) ? 0 : 1;
}
static inline int
update_match_revision(struct microcode_header_intel *mc_header, int rev)
{
return (mc_header->rev <= rev) ? 0 : 1;
}
static int microcode_sanity_check(void *mc)
{
unsigned long total_size, data_size, ext_table_size;
struct microcode_header_intel *mc_header = mc;
struct extended_sigtable *ext_header = NULL;
int sum, orig_sum, ext_sigcount = 0, i;
struct extended_signature *ext_sig;
total_size = get_totalsize(mc_header);
data_size = get_datasize(mc_header);
if (data_size + MC_HEADER_SIZE > total_size) {
pr_err("error! Bad data size in microcode data file\n");
return -EINVAL;
}
if (mc_header->ldrver != 1 || mc_header->hdrver != 1) {
pr_err("error! Unknown microcode update format\n");
return -EINVAL;
}
ext_table_size = total_size - (MC_HEADER_SIZE + data_size);
if (ext_table_size) {
if ((ext_table_size < EXT_HEADER_SIZE)
|| ((ext_table_size - EXT_HEADER_SIZE) % EXT_SIGNATURE_SIZE)) {
pr_err("error! Small exttable size in microcode data file\n");
return -EINVAL;
}
ext_header = mc + MC_HEADER_SIZE + data_size;
if (ext_table_size != exttable_size(ext_header)) {
pr_err("error! Bad exttable size in microcode data file\n");
return -EFAULT;
}
ext_sigcount = ext_header->count;
}
if (ext_table_size) {
int ext_table_sum = 0;
int *ext_tablep = (int *)ext_header;
i = ext_table_size / DWSIZE;
while (i--)
ext_table_sum += ext_tablep[i];
if (ext_table_sum) {
pr_warning("aborting, bad extended signature table checksum\n");
return -EINVAL;
}
}
orig_sum = 0;
i = (MC_HEADER_SIZE + data_size) / DWSIZE;
while (i--)
orig_sum += ((int *)mc)[i];
if (orig_sum) {
pr_err("aborting, bad checksum\n");
return -EINVAL;
}
if (!ext_table_size)
return 0;
for (i = 0; i < ext_sigcount; i++) {
ext_sig = (void *)ext_header + EXT_HEADER_SIZE +
EXT_SIGNATURE_SIZE * i;
sum = orig_sum
- (mc_header->sig + mc_header->pf + mc_header->cksum)
+ (ext_sig->sig + ext_sig->pf + ext_sig->cksum);
if (sum) {
pr_err("aborting, bad checksum\n");
return -EINVAL;
}
}
return 0;
}
static int
get_matching_microcode(struct cpu_signature *cpu_sig, void *mc, int rev)
{
struct microcode_header_intel *mc_header = mc;
struct extended_sigtable *ext_header;
unsigned long total_size = get_totalsize(mc_header);
int ext_sigcount, i;
struct extended_signature *ext_sig;
if (!update_match_revision(mc_header, rev))
return 0;
if (update_match_cpu(cpu_sig, mc_header->sig, mc_header->pf))
return 1;
if (total_size <= get_datasize(mc_header) + MC_HEADER_SIZE)
return 0;
ext_header = mc + get_datasize(mc_header) + MC_HEADER_SIZE;
ext_sigcount = ext_header->count;
ext_sig = (void *)ext_header + EXT_HEADER_SIZE;
for (i = 0; i < ext_sigcount; i++) {
if (update_match_cpu(cpu_sig, ext_sig->sig, ext_sig->pf))
return 1;
ext_sig++;
}
return 0;
}
static int apply_microcode(int cpu)
{
struct microcode_intel *mc_intel;
struct ucode_cpu_info *uci;
unsigned int val[2];
int cpu_num;
cpu_num = raw_smp_processor_id();
uci = ucode_cpu_info + cpu;
mc_intel = uci->mc;
BUG_ON(cpu_num != cpu);
if (mc_intel == NULL)
return 0;
wrmsr(MSR_IA32_UCODE_WRITE,
(unsigned long) mc_intel->bits,
(unsigned long) mc_intel->bits >> 16 >> 16);
wrmsr(MSR_IA32_UCODE_REV, 0, 0);
sync_core();
rdmsr(MSR_IA32_UCODE_REV, val[0], val[1]);
if (val[1] != mc_intel->hdr.rev) {
pr_err("CPU%d update to revision 0x%x failed\n",
cpu_num, mc_intel->hdr.rev);
return -1;
}
pr_info("CPU%d updated to revision 0x%x, date = %04x-%02x-%02x\n",
cpu_num, val[1],
mc_intel->hdr.date & 0xffff,
mc_intel->hdr.date >> 24,
(mc_intel->hdr.date >> 16) & 0xff);
uci->cpu_sig.rev = val[1];
return 0;
}
static enum ucode_state generic_load_microcode(int cpu, void *data, size_t size,
int (*get_ucode_data)(void *, const void *, size_t))
{
struct ucode_cpu_info *uci = ucode_cpu_info + cpu;
u8 *ucode_ptr = data, *new_mc = NULL, *mc = NULL;
int new_rev = uci->cpu_sig.rev;
unsigned int leftover = size;
enum ucode_state state = UCODE_OK;
unsigned int curr_mc_size = 0;
while (leftover) {
struct microcode_header_intel mc_header;
unsigned int mc_size;
if (get_ucode_data(&mc_header, ucode_ptr, sizeof(mc_header)))
break;
mc_size = get_totalsize(&mc_header);
if (!mc_size || mc_size > leftover) {
pr_err("error! Bad data in microcode data file\n");
break;
}
if (!mc || mc_size > curr_mc_size) {
vfree(mc);
mc = vmalloc(mc_size);
if (!mc)
break;
curr_mc_size = mc_size;
}
if (get_ucode_data(mc, ucode_ptr, mc_size) ||
microcode_sanity_check(mc) < 0) {
break;
}
if (get_matching_microcode(&uci->cpu_sig, mc, new_rev)) {
vfree(new_mc);
new_rev = mc_header.rev;
new_mc = mc;
mc = NULL;
}
ucode_ptr += mc_size;
leftover -= mc_size;
}
vfree(mc);
if (leftover) {
vfree(new_mc);
state = UCODE_ERROR;
goto out;
}
if (!new_mc) {
state = UCODE_NFOUND;
goto out;
}
vfree(uci->mc);
uci->mc = (struct microcode_intel *)new_mc;
pr_debug("CPU%d found a matching microcode update with version 0x%x (current=0x%x)\n",
cpu, new_rev, uci->cpu_sig.rev);
out:
return state;
}
static int get_ucode_fw(void *to, const void *from, size_t n)
{
memcpy(to, from, n);
return 0;
}
static enum ucode_state request_microcode_fw(int cpu, struct device *device)
{
char name[30];
struct cpuinfo_x86 *c = &cpu_data(cpu);
const struct firmware *firmware;
enum ucode_state ret;
sprintf(name, "intel-ucode/%02x-%02x-%02x",
c->x86, c->x86_model, c->x86_mask);
if (request_firmware(&firmware, name, device)) {
pr_debug("data file %s load failed\n", name);
return UCODE_NFOUND;
}
ret = generic_load_microcode(cpu, (void *)firmware->data,
firmware->size, &get_ucode_fw);
release_firmware(firmware);
return ret;
}
static int get_ucode_user(void *to, const void *from, size_t n)
{
return copy_from_user(to, from, n);
}
static enum ucode_state
request_microcode_user(int cpu, const void __user *buf, size_t size)
{
return generic_load_microcode(cpu, (void *)buf, size, &get_ucode_user);
}
static void microcode_fini_cpu(int cpu)
{
struct ucode_cpu_info *uci = ucode_cpu_info + cpu;
vfree(uci->mc);
uci->mc = NULL;
}
struct microcode_ops * __init init_intel_microcode(void)
{
return &microcode_intel_ops;
}
