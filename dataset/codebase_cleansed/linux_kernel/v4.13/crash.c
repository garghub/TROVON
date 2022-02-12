void
crash_save_this_cpu(void)
{
void *buf;
unsigned long cfm, sof, sol;
int cpu = smp_processor_id();
struct elf_prstatus *prstatus = &per_cpu(elf_prstatus, cpu);
elf_greg_t *dst = (elf_greg_t *)&(prstatus->pr_reg);
memset(prstatus, 0, sizeof(*prstatus));
prstatus->pr_pid = current->pid;
ia64_dump_cpu_regs(dst);
cfm = dst[43];
sol = (cfm >> 7) & 0x7f;
sof = cfm & 0x7f;
dst[46] = (unsigned long)ia64_rse_skip_regs((unsigned long *)dst[46],
sof - sol);
buf = (u64 *) per_cpu_ptr(crash_notes, cpu);
if (!buf)
return;
buf = append_elf_note(buf, KEXEC_CORE_NOTE_NAME, NT_PRSTATUS, prstatus,
sizeof(*prstatus));
final_note(buf);
}
static int
kdump_wait_cpu_freeze(void)
{
int cpu_num = num_online_cpus() - 1;
int timeout = 1000;
while(timeout-- > 0) {
if (atomic_read(&kdump_cpu_frozen) == cpu_num)
return 0;
udelay(1000);
}
return 1;
}
void
machine_crash_shutdown(struct pt_regs *pt)
{
kexec_disable_iosapic();
#ifdef CONFIG_SMP
local_irq_disable();
ia64_set_psr_mc();
if (atomic_inc_return(&kdump_in_progress) != 1)
unw_init_running(kdump_cpu_freeze, NULL);
kdump_smp_send_stop();
if (kdump_wait_cpu_freeze()) {
kdump_smp_send_init();
kdump_wait_cpu_freeze();
}
#endif
}
static void
machine_kdump_on_init(void)
{
crash_save_vmcoreinfo();
local_irq_disable();
kexec_disable_iosapic();
machine_kexec(ia64_kimage);
}
void
kdump_cpu_freeze(struct unw_frame_info *info, void *arg)
{
int cpuid;
local_irq_disable();
cpuid = smp_processor_id();
crash_save_this_cpu();
current->thread.ksp = (__u64)info->sw - 16;
ia64_set_psr_mc();
atomic_inc(&kdump_cpu_frozen);
kdump_status[cpuid] = 1;
mb();
for (;;)
cpu_relax();
}
static int
kdump_init_notifier(struct notifier_block *self, unsigned long val, void *data)
{
struct ia64_mca_notify_die *nd;
struct die_args *args = data;
if (atomic_read(&kdump_in_progress)) {
switch (val) {
case DIE_INIT_MONARCH_LEAVE:
if (!kdump_freeze_monarch)
break;
case DIE_INIT_SLAVE_LEAVE:
case DIE_INIT_MONARCH_ENTER:
case DIE_MCA_RENDZVOUS_LEAVE:
unw_init_running(kdump_cpu_freeze, NULL);
break;
}
}
if (!kdump_on_init && !kdump_on_fatal_mca)
return NOTIFY_DONE;
if (!ia64_kimage) {
if (val == DIE_INIT_MONARCH_LEAVE)
ia64_mca_printk(KERN_NOTICE
"%s: kdump not configured\n",
__func__);
return NOTIFY_DONE;
}
if (val != DIE_INIT_MONARCH_LEAVE &&
val != DIE_INIT_MONARCH_PROCESS &&
val != DIE_MCA_MONARCH_LEAVE)
return NOTIFY_DONE;
nd = (struct ia64_mca_notify_die *)args->err;
switch (val) {
case DIE_INIT_MONARCH_PROCESS:
if (kdump_on_init && (nd->sos->rv_rc != 1)) {
if (atomic_inc_return(&kdump_in_progress) != 1)
kdump_freeze_monarch = 1;
}
break;
case DIE_INIT_MONARCH_LEAVE:
if (kdump_on_init && (nd->sos->rv_rc != 1))
machine_kdump_on_init();
break;
case DIE_MCA_MONARCH_LEAVE:
if (kdump_on_fatal_mca && !(*(nd->data))) {
if (atomic_inc_return(&kdump_in_progress) == 1)
machine_kdump_on_init();
}
break;
}
return NOTIFY_DONE;
}
static int
machine_crash_setup(void)
{
static struct notifier_block kdump_init_notifier_nb = {
.notifier_call = kdump_init_notifier,
.priority = 1,
};
int ret;
if((ret = register_die_notifier(&kdump_init_notifier_nb)) != 0)
return ret;
#ifdef CONFIG_SYSCTL
register_sysctl_table(sys_table);
#endif
return 0;
}
