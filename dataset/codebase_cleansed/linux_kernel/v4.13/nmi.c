static void s390_handle_damage(void)
{
smp_send_stop();
disabled_wait((unsigned long) __builtin_return_address(0));
while (1);
}
void s390_handle_mcck(void)
{
unsigned long flags;
struct mcck_struct mcck;
local_irq_save(flags);
local_mcck_disable();
mcck = *this_cpu_ptr(&cpu_mcck);
memset(this_cpu_ptr(&cpu_mcck), 0, sizeof(mcck));
clear_cpu_flag(CIF_MCCK_PENDING);
local_mcck_enable();
local_irq_restore(flags);
if (mcck.channel_report)
crw_handle_channel_report();
if (mcck.warning) {
static int mchchk_wng_posted = 0;
__ctl_clear_bit(14, 24);
if (xchg(&mchchk_wng_posted, 1) == 0)
kill_cad_pid(SIGPWR, 1);
}
if (mcck.stp_queue)
stp_queue_work();
if (mcck.kill_task) {
local_irq_enable();
printk(KERN_EMERG "mcck: Terminating task because of machine "
"malfunction (code 0x%016lx).\n", mcck.mcck_code);
printk(KERN_EMERG "mcck: task: %s, pid: %d.\n",
current->comm, current->pid);
do_exit(SIGSEGV);
}
}
static int notrace s390_validate_registers(union mci mci, int umode)
{
int kill_task;
u64 zero;
void *fpt_save_area;
struct mcesa *mcesa;
kill_task = 0;
zero = 0;
if (!mci.gr) {
if (!umode)
s390_handle_damage();
kill_task = 1;
}
if (!mci.cr) {
s390_handle_damage();
} else {
asm volatile(
" lctlg 0,15,0(%0)\n"
" ptlb\n"
: : "a" (&S390_lowcore.cregs_save_area) : "memory");
}
if (!mci.fp) {
if (S390_lowcore.fpu_flags & KERNEL_VXR_V0V7)
s390_handle_damage();
if (!test_cpu_flag(CIF_FPU))
kill_task = 1;
}
fpt_save_area = &S390_lowcore.floating_pt_save_area;
if (!mci.fc) {
if (S390_lowcore.fpu_flags & KERNEL_FPC)
s390_handle_damage();
asm volatile("lfpc %0" : : "Q" (zero));
if (!test_cpu_flag(CIF_FPU))
kill_task = 1;
} else {
asm volatile("lfpc %0"
: : "Q" (S390_lowcore.fpt_creg_save_area));
}
mcesa = (struct mcesa *)(S390_lowcore.mcesad & MCESA_ORIGIN_MASK);
if (!MACHINE_HAS_VX) {
asm volatile(
" ld 0,0(%0)\n"
" ld 1,8(%0)\n"
" ld 2,16(%0)\n"
" ld 3,24(%0)\n"
" ld 4,32(%0)\n"
" ld 5,40(%0)\n"
" ld 6,48(%0)\n"
" ld 7,56(%0)\n"
" ld 8,64(%0)\n"
" ld 9,72(%0)\n"
" ld 10,80(%0)\n"
" ld 11,88(%0)\n"
" ld 12,96(%0)\n"
" ld 13,104(%0)\n"
" ld 14,112(%0)\n"
" ld 15,120(%0)\n"
: : "a" (fpt_save_area) : "memory");
} else {
union ctlreg0 cr0;
if (!mci.vr) {
if (S390_lowcore.fpu_flags & KERNEL_VXR)
s390_handle_damage();
if (!test_cpu_flag(CIF_FPU))
kill_task = 1;
}
cr0.val = S390_lowcore.cregs_save_area[0];
cr0.afp = cr0.vx = 1;
__ctl_load(cr0.val, 0, 0);
asm volatile(
" la 1,%0\n"
" .word 0xe70f,0x1000,0x0036\n"
" .word 0xe70f,0x1100,0x0c36\n"
: : "Q" (*(struct vx_array *) mcesa->vector_save_area)
: "1");
__ctl_load(S390_lowcore.cregs_save_area[0], 0, 0);
}
asm volatile(
" lam 0,15,0(%0)"
: : "a" (&S390_lowcore.access_regs_save_area));
if (!mci.ar) {
kill_task = 1;
}
if (MACHINE_HAS_GS && (S390_lowcore.cregs_save_area[2] & (1UL << 4))) {
if (!mci.gs)
kill_task = 1;
else
load_gs_cb((struct gs_cb *)
mcesa->guarded_storage_save_area);
}
if (!mci.pr)
asm volatile(
" sr 0,0\n"
" sckpf"
: : : "0", "cc");
else
asm volatile(
" l 0,%0\n"
" sckpf"
: : "Q" (S390_lowcore.tod_progreg_save_area)
: "0", "cc");
set_clock_comparator(S390_lowcore.clock_comparator);
if (!mci.wp)
s390_handle_damage();
if (!mci.ms || !mci.pm || !mci.ia)
kill_task = 1;
return kill_task;
}
static void notrace s390_backup_mcck_info(struct pt_regs *regs)
{
struct mcck_volatile_info *mcck_backup;
struct sie_page *sie_page;
struct kvm_s390_sie_block *sie_block =
(struct kvm_s390_sie_block *) regs->gprs[14];
if (sie_block == NULL)
s390_handle_damage();
sie_page = container_of(sie_block, struct sie_page, sie_block);
mcck_backup = &sie_page->mcck_info;
mcck_backup->mcic = S390_lowcore.mcck_interruption_code &
~(MCCK_CODE_CP | MCCK_CODE_EXT_DAMAGE);
mcck_backup->ext_damage_code = S390_lowcore.external_damage_code;
mcck_backup->failing_storage_address
= S390_lowcore.failing_storage_address;
}
void notrace s390_do_machine_check(struct pt_regs *regs)
{
static int ipd_count;
static DEFINE_SPINLOCK(ipd_lock);
static unsigned long long last_ipd;
struct mcck_struct *mcck;
unsigned long long tmp;
union mci mci;
unsigned long mcck_dam_code;
nmi_enter();
inc_irq_stat(NMI_NMI);
mci.val = S390_lowcore.mcck_interruption_code;
mcck = this_cpu_ptr(&cpu_mcck);
if (mci.sd) {
s390_handle_damage();
}
if (mci.pd && !test_cpu_flag(CIF_MCCK_GUEST)) {
if (mci.b) {
u64 z_mcic, o_mcic, t_mcic;
z_mcic = (1ULL<<63 | 1ULL<<59 | 1ULL<<29);
o_mcic = (1ULL<<43 | 1ULL<<42 | 1ULL<<41 | 1ULL<<40 |
1ULL<<36 | 1ULL<<35 | 1ULL<<34 | 1ULL<<32 |
1ULL<<30 | 1ULL<<21 | 1ULL<<20 | 1ULL<<17 |
1ULL<<16);
t_mcic = mci.val;
if (((t_mcic & z_mcic) != 0) ||
((t_mcic & o_mcic) != o_mcic)) {
s390_handle_damage();
}
spin_lock(&ipd_lock);
tmp = get_tod_clock();
if (((tmp - last_ipd) >> 12) < MAX_IPD_TIME)
ipd_count++;
else
ipd_count = 1;
last_ipd = tmp;
if (ipd_count == MAX_IPD_COUNT)
s390_handle_damage();
spin_unlock(&ipd_lock);
} else {
s390_handle_damage();
}
}
if (s390_validate_registers(mci, user_mode(regs))) {
mcck->kill_task = 1;
mcck->mcck_code = mci.val;
set_cpu_flag(CIF_MCCK_PENDING);
}
if (test_cpu_flag(CIF_MCCK_GUEST))
s390_backup_mcck_info(regs);
if (mci.cd) {
s390_handle_damage();
}
if (mci.ed && mci.ec) {
if (S390_lowcore.external_damage_code & (1U << ED_STP_SYNC))
mcck->stp_queue |= stp_sync_check();
if (S390_lowcore.external_damage_code & (1U << ED_STP_ISLAND))
mcck->stp_queue |= stp_island_check();
if (mcck->stp_queue)
set_cpu_flag(CIF_MCCK_PENDING);
}
if (!test_cpu_flag(CIF_MCCK_GUEST)) {
if (mci.se)
s390_handle_damage();
if (mci.ke)
s390_handle_damage();
if (mci.ds && mci.fa)
s390_handle_damage();
}
if (mci.cp) {
mcck->channel_report = 1;
set_cpu_flag(CIF_MCCK_PENDING);
}
if (mci.w) {
mcck->warning = 1;
set_cpu_flag(CIF_MCCK_PENDING);
}
mcck_dam_code = (mci.val & MCIC_SUBCLASS_MASK);
if (test_cpu_flag(CIF_MCCK_GUEST) &&
(mcck_dam_code & MCCK_CODE_NO_GUEST) != mcck_dam_code) {
*((long *)(regs->gprs[15] + __SF_SIE_REASON)) = -EINTR;
}
clear_cpu_flag(CIF_MCCK_GUEST);
nmi_exit();
}
static int __init machine_check_init(void)
{
ctl_set_bit(14, 25);
ctl_set_bit(14, 27);
ctl_set_bit(14, 24);
return 0;
}
