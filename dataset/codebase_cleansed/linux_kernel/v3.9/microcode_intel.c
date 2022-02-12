static int collect_cpu_info(int cpu_num, struct cpu_signature *csig)
{
struct cpuinfo_x86 *c = &cpu_data(cpu_num);
unsigned int val[2];
memset(csig, 0, sizeof(*csig));
csig->sig = cpuid_eax(0x00000001);
if ((c->x86_model >= 5) || (c->x86 > 6)) {
rdmsr(MSR_IA32_PLATFORM_ID, val[0], val[1]);
csig->pf = 1 << ((val[1] >> 18) & 7);
}
csig->rev = c->microcode;
pr_info("CPU%d sig=0x%x, pf=0x%x, revision=0x%x\n",
cpu_num, csig->sig, csig->pf, csig->rev);
return 0;
}
static int get_matching_mc(struct microcode_intel *mc_intel, int cpu)
{
struct cpu_signature cpu_sig;
unsigned int csig, cpf, crev;
collect_cpu_info(cpu, &cpu_sig);
csig = cpu_sig.sig;
cpf = cpu_sig.pf;
crev = cpu_sig.rev;
return get_matching_microcode(csig, cpf, mc_intel, crev);
}
int apply_microcode(int cpu)
{
struct microcode_intel *mc_intel;
struct ucode_cpu_info *uci;
unsigned int val[2];
int cpu_num = raw_smp_processor_id();
struct cpuinfo_x86 *c = &cpu_data(cpu_num);
uci = ucode_cpu_info + cpu;
mc_intel = uci->mc;
BUG_ON(cpu_num != cpu);
if (mc_intel == NULL)
return 0;
if (get_matching_mc(mc_intel, cpu) == 0)
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
c->microcode = val[1];
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
unsigned int csig, cpf;
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
microcode_sanity_check(mc, 1) < 0) {
break;
}
csig = uci->cpu_sig.sig;
cpf = uci->cpu_sig.pf;
if (get_matching_microcode(csig, cpf, mc, new_rev)) {
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
save_mc_for_early(new_mc);
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
static enum ucode_state request_microcode_fw(int cpu, struct device *device,
bool refresh_fw)
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
struct cpuinfo_x86 *c = &cpu_data(0);
if (c->x86_vendor != X86_VENDOR_INTEL || c->x86 < 6 ||
cpu_has(c, X86_FEATURE_IA64)) {
pr_err("Intel CPU family 0x%x not supported\n", c->x86);
return NULL;
}
return &microcode_intel_ops;
}
