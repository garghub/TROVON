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
struct pci_dev *F3 = node_to_amd_nb(nid)->misc;
u32 val;
int err;
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
static void do_inject(void)
{
u64 mcg_status = 0;
unsigned int cpu = i_mce.extcpu;
u8 b = i_mce.bank;
if (i_mce.misc)
i_mce.status |= MCI_STATUS_MISCV;
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
if (static_cpu_has(X86_FEATURE_AMD_DCM) && b == 4) {
toggle_nb_mca_mst_cpu(amd_get_nb_id(cpu));
cpu = get_nbc_for_node(amd_get_nb_id(cpu));
}
get_online_cpus();
if (!cpu_online(cpu))
goto err;
toggle_hw_mce_inject(cpu, true);
wrmsr_on_cpu(cpu, MSR_IA32_MCG_STATUS,
(u32)mcg_status, (u32)(mcg_status >> 32));
if (boot_cpu_has(X86_FEATURE_SMCA)) {
if (inj_type == DFR_INT_INJ) {
wrmsr_on_cpu(cpu, MSR_AMD64_SMCA_MCx_DESTAT(b),
(u32)i_mce.status, (u32)(i_mce.status >> 32));
wrmsr_on_cpu(cpu, MSR_AMD64_SMCA_MCx_DEADDR(b),
(u32)i_mce.addr, (u32)(i_mce.addr >> 32));
} else {
wrmsr_on_cpu(cpu, MSR_AMD64_SMCA_MCx_STATUS(b),
(u32)i_mce.status, (u32)(i_mce.status >> 32));
wrmsr_on_cpu(cpu, MSR_AMD64_SMCA_MCx_ADDR(b),
(u32)i_mce.addr, (u32)(i_mce.addr >> 32));
}
wrmsr_on_cpu(cpu, MSR_AMD64_SMCA_MCx_MISC(b),
(u32)i_mce.misc, (u32)(i_mce.misc >> 32));
} else {
wrmsr_on_cpu(cpu, MSR_IA32_MCx_STATUS(b),
(u32)i_mce.status, (u32)(i_mce.status >> 32));
wrmsr_on_cpu(cpu, MSR_IA32_MCx_ADDR(b),
(u32)i_mce.addr, (u32)(i_mce.addr >> 32));
wrmsr_on_cpu(cpu, MSR_IA32_MCx_MISC(b),
(u32)i_mce.misc, (u32)(i_mce.misc >> 32));
}
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
static int __init init_mce_inject(void)
{
int i;
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
while (--i >= 0)
debugfs_remove(dfs_fls[i].d);
debugfs_remove(dfs_inj);
dfs_inj = NULL;
return -ENOMEM;
}
static void __exit exit_mce_inject(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(dfs_fls); i++)
debugfs_remove(dfs_fls[i].d);
memset(&dfs_fls, 0, sizeof(dfs_fls));
debugfs_remove(dfs_inj);
dfs_inj = NULL;
}
