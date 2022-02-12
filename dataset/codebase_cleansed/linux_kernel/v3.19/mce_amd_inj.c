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
static int flags_get(void *data, u64 *val)
{
struct mce *m = (struct mce *)data;
*val = m->inject_flags;
return 0;
}
static int flags_set(void *data, u64 val)
{
struct mce *m = (struct mce *)data;
m->inject_flags = (u8)val;
return 0;
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
static void do_inject(void)
{
u64 mcg_status = 0;
unsigned int cpu = i_mce.extcpu;
u8 b = i_mce.bank;
if (!(i_mce.inject_flags & MCJ_EXCEPTION)) {
amd_decode_mce(NULL, 0, &i_mce);
return;
}
get_online_cpus();
if (!cpu_online(cpu))
goto err;
mcg_status = MCG_STATUS_MCIP | MCG_STATUS_EIPV;
if (!(i_mce.status & MCI_STATUS_PCC))
mcg_status |= MCG_STATUS_RIPV;
toggle_hw_mce_inject(cpu, true);
wrmsr_on_cpu(cpu, MSR_IA32_MCG_STATUS,
(u32)mcg_status, (u32)(mcg_status >> 32));
wrmsr_on_cpu(cpu, MSR_IA32_MCx_STATUS(b),
(u32)i_mce.status, (u32)(i_mce.status >> 32));
wrmsr_on_cpu(cpu, MSR_IA32_MCx_ADDR(b),
(u32)i_mce.addr, (u32)(i_mce.addr >> 32));
wrmsr_on_cpu(cpu, MSR_IA32_MCx_MISC(b),
(u32)i_mce.misc, (u32)(i_mce.misc >> 32));
toggle_hw_mce_inject(cpu, false);
smp_call_function_single(cpu, trigger_mce, NULL, 0);
err:
put_online_cpus();
}
static int inj_bank_set(void *data, u64 val)
{
struct mce *m = (struct mce *)data;
if (val > 5) {
if (boot_cpu_data.x86 != 0x15 || val > 6) {
pr_err("Non-existent MCE bank: %llu\n", val);
return -EINVAL;
}
}
m->bank = val;
do_inject();
return 0;
}
static int inj_bank_get(void *data, u64 *val)
{
struct mce *m = (struct mce *)data;
*val = m->bank;
return 0;
}
static int __init init_mce_inject(void)
{
int i;
dfs_inj = debugfs_create_dir("mce-inject", NULL);
if (!dfs_inj)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(dfs_fls); i++) {
dfs_fls[i].d = debugfs_create_file(dfs_fls[i].name,
S_IRUSR | S_IWUSR,
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
