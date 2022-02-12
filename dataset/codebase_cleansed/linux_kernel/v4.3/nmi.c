static void s390_handle_damage(char *msg)
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
if (mcck.kill_task) {
local_irq_enable();
printk(KERN_EMERG "mcck: Terminating task because of machine "
"malfunction (code 0x%016llx).\n", mcck.mcck_code);
printk(KERN_EMERG "mcck: task: %s, pid: %d.\n",
current->comm, current->pid);
do_exit(SIGSEGV);
}
}
static int notrace s390_revalidate_registers(struct mci *mci)
{
int kill_task;
u64 zero;
void *fpt_save_area, *fpt_creg_save_area;
kill_task = 0;
zero = 0;
if (!mci->gr) {
kill_task = 1;
}
if (!mci->fp) {
kill_task = 1;
}
fpt_save_area = &S390_lowcore.floating_pt_save_area;
fpt_creg_save_area = &S390_lowcore.fpt_creg_save_area;
if (!mci->fc) {
asm volatile("lfpc 0(%0)" : : "a" (&zero), "m" (zero));
kill_task = 1;
} else
asm volatile("lfpc 0(%0)" : : "a" (fpt_creg_save_area));
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
: : "a" (fpt_save_area));
} else {
union ctlreg0 cr0;
if (!mci->vr) {
kill_task = 1;
}
cr0.val = S390_lowcore.cregs_save_area[0];
cr0.afp = cr0.vx = 1;
__ctl_load(cr0.val, 0, 0);
asm volatile(
" la 1,%0\n"
" .word 0xe70f,0x1000,0x0036\n"
" .word 0xe70f,0x1100,0x0c36\n"
: : "Q" (*(struct vx_array *)
&S390_lowcore.vector_save_area) : "1");
__ctl_load(S390_lowcore.cregs_save_area[0], 0, 0);
}
asm volatile(
" lam 0,15,0(%0)"
: : "a" (&S390_lowcore.access_regs_save_area));
if (!mci->ar) {
kill_task = 1;
}
if (!mci->cr) {
s390_handle_damage("invalid control registers.");
} else {
asm volatile(
" lctlg 0,15,0(%0)"
: : "a" (&S390_lowcore.cregs_save_area));
}
if (!mci->pr)
asm volatile(
" sr 0,0\n"
" sckpf"
: : : "0", "cc");
else
asm volatile(
" l 0,0(%0)\n"
" sckpf"
: : "a" (&S390_lowcore.tod_progreg_save_area)
: "0", "cc");
set_clock_comparator(S390_lowcore.clock_comparator);
if (!mci->wp)
s390_handle_damage("old psw invalid.");
if (!mci->ms || !mci->pm || !mci->ia)
kill_task = 1;
return kill_task;
}
void notrace s390_do_machine_check(struct pt_regs *regs)
{
static int ipd_count;
static DEFINE_SPINLOCK(ipd_lock);
static unsigned long long last_ipd;
struct mcck_struct *mcck;
unsigned long long tmp;
struct mci *mci;
int umode;
nmi_enter();
inc_irq_stat(NMI_NMI);
mci = (struct mci *) &S390_lowcore.mcck_interruption_code;
mcck = this_cpu_ptr(&cpu_mcck);
umode = user_mode(regs);
if (mci->sd) {
s390_handle_damage("received system damage machine check.");
}
if (mci->pd) {
if (mci->b) {
u64 z_mcic, o_mcic, t_mcic;
z_mcic = (1ULL<<63 | 1ULL<<59 | 1ULL<<29);
o_mcic = (1ULL<<43 | 1ULL<<42 | 1ULL<<41 | 1ULL<<40 |
1ULL<<36 | 1ULL<<35 | 1ULL<<34 | 1ULL<<32 |
1ULL<<30 | 1ULL<<21 | 1ULL<<20 | 1ULL<<17 |
1ULL<<16);
t_mcic = *(u64 *)mci;
if (((t_mcic & z_mcic) != 0) ||
((t_mcic & o_mcic) != o_mcic)) {
s390_handle_damage("processing backup machine "
"check with damage.");
}
spin_lock(&ipd_lock);
tmp = get_tod_clock();
if (((tmp - last_ipd) >> 12) < MAX_IPD_TIME)
ipd_count++;
else
ipd_count = 1;
last_ipd = tmp;
if (ipd_count == MAX_IPD_COUNT)
s390_handle_damage("too many ipd retries.");
spin_unlock(&ipd_lock);
} else {
s390_handle_damage("received instruction processing "
"damage machine check.");
}
}
if (s390_revalidate_registers(mci)) {
if (umode) {
mcck->kill_task = 1;
mcck->mcck_code = *(unsigned long long *) mci;
set_cpu_flag(CIF_MCCK_PENDING);
} else {
s390_handle_damage("unable to revalidate registers.");
}
}
if (mci->cd) {
s390_handle_damage("TOD clock damaged");
}
if (mci->ed && mci->ec) {
if (S390_lowcore.external_damage_code & (1U << ED_ETR_SYNC))
etr_sync_check();
if (S390_lowcore.external_damage_code & (1U << ED_ETR_SWITCH))
etr_switch_to_local();
if (S390_lowcore.external_damage_code & (1U << ED_STP_SYNC))
stp_sync_check();
if (S390_lowcore.external_damage_code & (1U << ED_STP_ISLAND))
stp_island_check();
}
if (mci->se)
s390_handle_damage("received storage error uncorrected "
"machine check.");
if (mci->ke)
s390_handle_damage("received storage key-error uncorrected "
"machine check.");
if (mci->ds && mci->fa)
s390_handle_damage("received storage degradation machine "
"check.");
if (mci->cp) {
mcck->channel_report = 1;
set_cpu_flag(CIF_MCCK_PENDING);
}
if (mci->w) {
mcck->warning = 1;
set_cpu_flag(CIF_MCCK_PENDING);
}
nmi_exit();
}
static int __init machine_check_init(void)
{
ctl_set_bit(14, 25);
ctl_set_bit(14, 27);
ctl_set_bit(14, 24);
return 0;
}
