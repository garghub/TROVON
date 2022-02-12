static void setup_inj_struct(struct mce *m)
{
memset(m, 0, sizeof(struct mce));
m->cpuvendor = boot_cpu_data.x86_vendor;
}
static void inject_mce(struct mce *m)
{
struct mce *i = &per_cpu(injectm, m->extcpu);
i->finished = 0;
mb();
m->finished = 0;
i->extcpu = m->extcpu;
mb();
memcpy(i, m, sizeof(struct mce));
mb();
i->finished = 1;
}
static void raise_poll(struct mce *m)
{
unsigned long flags;
mce_banks_t b;
memset(&b, 0xff, sizeof(mce_banks_t));
local_irq_save(flags);
machine_check_poll(0, &b);
local_irq_restore(flags);
m->finished = 0;
}
static void raise_exception(struct mce *m, struct pt_regs *pregs)
{
struct pt_regs regs;
unsigned long flags;
if (!pregs) {
memset(&regs, 0, sizeof(struct pt_regs));
regs.ip = m->ip;
regs.cs = m->cs;
pregs = &regs;
}
local_irq_save(flags);
do_machine_check(pregs, 0);
local_irq_restore(flags);
m->finished = 0;
}
static int mce_raise_notify(unsigned int cmd, struct pt_regs *regs)
{
int cpu = smp_processor_id();
struct mce *m = this_cpu_ptr(&injectm);
if (!cpumask_test_cpu(cpu, mce_inject_cpumask))
return NMI_DONE;
cpumask_clear_cpu(cpu, mce_inject_cpumask);
if (m->inject_flags & MCJ_EXCEPTION)
raise_exception(m, regs);
else if (m->status)
raise_poll(m);
return NMI_HANDLED;
}
static void mce_irq_ipi(void *info)
{
int cpu = smp_processor_id();
struct mce *m = this_cpu_ptr(&injectm);
if (cpumask_test_cpu(cpu, mce_inject_cpumask) &&
m->inject_flags & MCJ_EXCEPTION) {
cpumask_clear_cpu(cpu, mce_inject_cpumask);
raise_exception(m, NULL);
}
}
static int raise_local(void)
{
struct mce *m = this_cpu_ptr(&injectm);
int context = MCJ_CTX(m->inject_flags);
int ret = 0;
int cpu = m->extcpu;
if (m->inject_flags & MCJ_EXCEPTION) {
pr_info("Triggering MCE exception on CPU %d\n", cpu);
switch (context) {
case MCJ_CTX_IRQ:
case MCJ_CTX_PROCESS:
raise_exception(m, NULL);
break;
default:
pr_info("Invalid MCE context\n");
ret = -EINVAL;
}
pr_info("MCE exception done on CPU %d\n", cpu);
} else if (m->status) {
pr_info("Starting machine check poll CPU %d\n", cpu);
raise_poll(m);
mce_notify_irq();
pr_info("Machine check poll done on CPU %d\n", cpu);
} else
m->finished = 0;
return ret;
}
static void __maybe_unused raise_mce(struct mce *m)
{
int context = MCJ_CTX(m->inject_flags);
inject_mce(m);
if (context == MCJ_CTX_RANDOM)
return;
if (m->inject_flags & (MCJ_IRQ_BROADCAST | MCJ_NMI_BROADCAST)) {
unsigned long start;
int cpu;
get_online_cpus();
cpumask_copy(mce_inject_cpumask, cpu_online_mask);
cpumask_clear_cpu(get_cpu(), mce_inject_cpumask);
for_each_online_cpu(cpu) {
struct mce *mcpu = &per_cpu(injectm, cpu);
if (!mcpu->finished ||
MCJ_CTX(mcpu->inject_flags) != MCJ_CTX_RANDOM)
cpumask_clear_cpu(cpu, mce_inject_cpumask);
}
if (!cpumask_empty(mce_inject_cpumask)) {
if (m->inject_flags & MCJ_IRQ_BROADCAST) {
preempt_disable();
smp_call_function_many(mce_inject_cpumask,
mce_irq_ipi, NULL, 0);
preempt_enable();
} else if (m->inject_flags & MCJ_NMI_BROADCAST)
apic->send_IPI_mask(mce_inject_cpumask,
NMI_VECTOR);
}
start = jiffies;
while (!cpumask_empty(mce_inject_cpumask)) {
if (!time_before(jiffies, start + 2*HZ)) {
pr_err("Timeout waiting for mce inject %lx\n",
*cpumask_bits(mce_inject_cpumask));
break;
}
cpu_relax();
}
raise_local();
put_cpu();
put_online_cpus();
} else {
preempt_disable();
raise_local();
preempt_enable();
}
}
static int mce_inject_raise(struct notifier_block *nb, unsigned long val,
void *data)
{
struct mce *m = (struct mce *)data;
if (!m)
return NOTIFY_DONE;
mutex_lock(&mce_inject_mutex);
raise_mce(m);
mutex_unlock(&mce_inject_mutex);
return NOTIFY_DONE;
}
static int toggle_hw_mce_inject(unsigned int cpu, bool enable)
{
u32 l, h;
int err;
err = rdmsr_on_cpu(cpu, MSR_K7_HWCR, &l, &h);
if (err) {
pr_err("%s: error reading HWCR\n", __func__);
return err;
}
enable ? (l |= BIT(18)) : (l &= ~BIT(18));
err = wrmsr_on_cpu(cpu, MSR_K7_HWCR, l, h);
if (err)
pr_err("%s: error writing HWCR\n", __func__);
return err;
}
static int __set_inj(const char *buf)
{
int i;
for (i = 0; i < N_INJ_TYPES; i++) {
if (!strncmp(flags_options[i], buf, strlen(flags_options[i]))) {
inj_type = i;
return 0;
}
}
return -EINVAL;
}
static ssize_t flags_read(struct file *filp, char __user *ubuf,
size_t cnt, loff_t *ppos)
{
char buf[MAX_FLAG_OPT_SIZE];
int n;
n = sprintf(buf, "%s\n", flags_options[inj_type]);
return simple_read_from_buffer(ubuf, cnt, ppos, buf, n);
}
static ssize_t flags_write(struct file *filp, const char __user *ubuf,
size_t cnt, loff_t *ppos)
{
char buf[MAX_FLAG_OPT_SIZE], *__buf;
int err;
if (cnt > MAX_FLAG_OPT_SIZE)
return -EINVAL;
if (copy_from_user(&buf, ubuf, cnt))
return -EFAULT;
buf[cnt - 1] = 0;
__buf = strstrip(buf);
err = __set_inj(__buf);
if (err) {
pr_err("%s: Invalid flags value: %s\n", __func__, __buf);
return err;
}
*ppos += cnt;
return cnt;
}
static int inj_extcpu_set(void *data, u64 val)
{
struct mce *m = (struct mce *)data;
if (val >= nr_cpu_ids || !cpu_online(val)) {
pr_err("%s: Invalid CPU: %llu\n", __func__, val);
return -EINVAL;
}
m->extcpu = val;
return 0;
}
static void trigger_mce(void *info)
{
asm volatile("int $18");
}
static void trigger_dfr_int(void *info)
{
asm volatile("int %0" :: "i" (DEFERRED_ERROR_VECTOR));
}
static void trigger_thr_int(void *info)
{
asm volatile("int %0" :: "i" (THRESHOLD_APIC_VECTOR));
}
static u32 get_nbc_for_node(int node_id)
{
struct cpuinfo_x86 *c = &boot_cpu_data;
u32 cores_per_node;
cores_per_node = (c->x86_max_cores * smp_num_siblings) / amd_get_nodes_per_socket();
return cores_per_node * node_id;
}
static void toggle_nb_mca_mst_cpu(u16 nid)
{
struct amd_northbridge *nb;
struct pci_dev *F3;
u32 val;
int err;
nb = node_to_amd_nb(nid);
if (!nb)
return;
F3 = nb->misc;
if (!F3)
return;
err = pci_read_config_dword(F3, NBCFG, &val);
if (err) {
pr_err("%s: Error reading F%dx%03x.\n",
__func__, PCI_FUNC(F3->devfn), NBCFG);
return;
}
if (val & BIT(27))
return;
pr_err("%s: Set D18F3x44[NbMcaToMstCpuEn] which BIOS hasn't done.\n",
__func__);
val |= BIT(27);
err = pci_write_config_dword(F3, NBCFG, val);
if (err)
pr_err("%s: Error writing F%dx%03x.\n",
__func__, PCI_FUNC(F3->devfn), NBCFG);
}
static void prepare_msrs(void *info)
{
struct mce m = *(struct mce *)info;
u8 b = m.bank;
wrmsrl(MSR_IA32_MCG_STATUS, m.mcgstatus);
if (boot_cpu_has(X86_FEATURE_SMCA)) {
if (m.inject_flags == DFR_INT_INJ) {
wrmsrl(MSR_AMD64_SMCA_MCx_DESTAT(b), m.status);
wrmsrl(MSR_AMD64_SMCA_MCx_DEADDR(b), m.addr);
} else {
wrmsrl(MSR_AMD64_SMCA_MCx_STATUS(b), m.status);
wrmsrl(MSR_AMD64_SMCA_MCx_ADDR(b), m.addr);
}
wrmsrl(MSR_AMD64_SMCA_MCx_MISC(b), m.misc);
wrmsrl(MSR_AMD64_SMCA_MCx_SYND(b), m.synd);
} else {
wrmsrl(MSR_IA32_MCx_STATUS(b), m.status);
wrmsrl(MSR_IA32_MCx_ADDR(b), m.addr);
wrmsrl(MSR_IA32_MCx_MISC(b), m.misc);
}
}
static void do_inject(void)
{
u64 mcg_status = 0;
unsigned int cpu = i_mce.extcpu;
u8 b = i_mce.bank;
rdtscll(i_mce.tsc);
if (i_mce.misc)
i_mce.status |= MCI_STATUS_MISCV;
if (i_mce.synd)
i_mce.status |= MCI_STATUS_SYNDV;
if (inj_type == SW_INJ) {
mce_inject_log(&i_mce);
return;
}
mcg_status = MCG_STATUS_MCIP | MCG_STATUS_EIPV;
if (!(i_mce.status & MCI_STATUS_PCC))
mcg_status |= MCG_STATUS_RIPV;
if (inj_type == DFR_INT_INJ) {
i_mce.status |= MCI_STATUS_DEFERRED;
i_mce.status |= (i_mce.status & ~MCI_STATUS_UC);
}
if (static_cpu_has(X86_FEATURE_AMD_DCM) &&
b == 4 &&
boot_cpu_data.x86 < 0x17) {
toggle_nb_mca_mst_cpu(amd_get_nb_id(cpu));
cpu = get_nbc_for_node(amd_get_nb_id(cpu));
}
get_online_cpus();
if (!cpu_online(cpu))
goto err;
toggle_hw_mce_inject(cpu, true);
i_mce.mcgstatus = mcg_status;
i_mce.inject_flags = inj_type;
smp_call_function_single(cpu, prepare_msrs, &i_mce, 0);
toggle_hw_mce_inject(cpu, false);
switch (inj_type) {
case DFR_INT_INJ:
smp_call_function_single(cpu, trigger_dfr_int, NULL, 0);
break;
case THR_INT_INJ:
smp_call_function_single(cpu, trigger_thr_int, NULL, 0);
break;
default:
smp_call_function_single(cpu, trigger_mce, NULL, 0);
}
err:
put_online_cpus();
}
static int inj_bank_set(void *data, u64 val)
{
struct mce *m = (struct mce *)data;
if (val >= n_banks) {
pr_err("Non-existent MCE bank: %llu\n", val);
return -EINVAL;
}
m->bank = val;
do_inject();
return 0;
}
static ssize_t
inj_readme_read(struct file *filp, char __user *ubuf,
size_t cnt, loff_t *ppos)
{
return simple_read_from_buffer(ubuf, cnt, ppos,
readme_msg, strlen(readme_msg));
}
static int __init debugfs_init(void)
{
unsigned int i;
u64 cap;
rdmsrl(MSR_IA32_MCG_CAP, cap);
n_banks = cap & MCG_BANKCNT_MASK;
dfs_inj = debugfs_create_dir("mce-inject", NULL);
if (!dfs_inj)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(dfs_fls); i++) {
dfs_fls[i].d = debugfs_create_file(dfs_fls[i].name,
dfs_fls[i].perm,
dfs_inj,
&i_mce,
dfs_fls[i].fops);
if (!dfs_fls[i].d)
goto err_dfs_add;
}
return 0;
err_dfs_add:
while (i-- > 0)
debugfs_remove(dfs_fls[i].d);
debugfs_remove(dfs_inj);
dfs_inj = NULL;
return -ENODEV;
}
static int __init inject_init(void)
{
int err;
if (!alloc_cpumask_var(&mce_inject_cpumask, GFP_KERNEL))
return -ENOMEM;
err = debugfs_init();
if (err) {
free_cpumask_var(mce_inject_cpumask);
return err;
}
register_nmi_handler(NMI_LOCAL, mce_raise_notify, 0, "mce_notify");
mce_register_injector_chain(&inject_nb);
setup_inj_struct(&i_mce);
pr_info("Machine check injector initialized\n");
return 0;
}
static void __exit inject_exit(void)
{
mce_unregister_injector_chain(&inject_nb);
unregister_nmi_handler(NMI_LOCAL, "mce_notify");
debugfs_remove_recursive(dfs_inj);
dfs_inj = NULL;
memset(&dfs_fls, 0, sizeof(dfs_fls));
free_cpumask_var(mce_inject_cpumask);
}
