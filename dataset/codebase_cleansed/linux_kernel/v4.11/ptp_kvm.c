static int ptp_kvm_get_time_fn(ktime_t *device_time,
struct system_counterval_t *system_counter,
void *ctx)
{
unsigned long ret;
struct timespec64 tspec;
unsigned version;
int cpu;
struct pvclock_vcpu_time_info *src;
spin_lock(&kvm_ptp_lock);
preempt_disable_notrace();
cpu = smp_processor_id();
src = &hv_clock[cpu].pvti;
do {
version = pvclock_read_begin(src);
ret = kvm_hypercall2(KVM_HC_CLOCK_PAIRING,
clock_pair_gpa,
KVM_CLOCK_PAIRING_WALLCLOCK);
if (ret != 0) {
pr_err_ratelimited("clock pairing hypercall ret %lu\n", ret);
spin_unlock(&kvm_ptp_lock);
preempt_enable_notrace();
return -EOPNOTSUPP;
}
tspec.tv_sec = clock_pair.sec;
tspec.tv_nsec = clock_pair.nsec;
ret = __pvclock_read_cycles(src, clock_pair.tsc);
} while (pvclock_read_retry(src, version));
preempt_enable_notrace();
system_counter->cycles = ret;
system_counter->cs = &kvm_clock;
*device_time = timespec64_to_ktime(tspec);
spin_unlock(&kvm_ptp_lock);
return 0;
}
static int ptp_kvm_getcrosststamp(struct ptp_clock_info *ptp,
struct system_device_crosststamp *xtstamp)
{
return get_device_system_crosststamp(ptp_kvm_get_time_fn, NULL,
NULL, xtstamp);
}
static int ptp_kvm_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
return -EOPNOTSUPP;
}
static int ptp_kvm_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
return -EOPNOTSUPP;
}
static int ptp_kvm_settime(struct ptp_clock_info *ptp,
const struct timespec64 *ts)
{
return -EOPNOTSUPP;
}
static int ptp_kvm_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
unsigned long ret;
struct timespec64 tspec;
spin_lock(&kvm_ptp_lock);
ret = kvm_hypercall2(KVM_HC_CLOCK_PAIRING,
clock_pair_gpa,
KVM_CLOCK_PAIRING_WALLCLOCK);
if (ret != 0) {
pr_err_ratelimited("clock offset hypercall ret %lu\n", ret);
spin_unlock(&kvm_ptp_lock);
return -EOPNOTSUPP;
}
tspec.tv_sec = clock_pair.sec;
tspec.tv_nsec = clock_pair.nsec;
spin_unlock(&kvm_ptp_lock);
memcpy(ts, &tspec, sizeof(struct timespec64));
return 0;
}
static int ptp_kvm_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
return -EOPNOTSUPP;
}
static void __exit ptp_kvm_exit(void)
{
ptp_clock_unregister(kvm_ptp_clock.ptp_clock);
}
static int __init ptp_kvm_init(void)
{
long ret;
clock_pair_gpa = slow_virt_to_phys(&clock_pair);
hv_clock = pvclock_pvti_cpu0_va();
if (!hv_clock)
return -ENODEV;
ret = kvm_hypercall2(KVM_HC_CLOCK_PAIRING, clock_pair_gpa,
KVM_CLOCK_PAIRING_WALLCLOCK);
if (ret == -KVM_ENOSYS || ret == -KVM_EOPNOTSUPP)
return -ENODEV;
kvm_ptp_clock.caps = ptp_kvm_caps;
kvm_ptp_clock.ptp_clock = ptp_clock_register(&kvm_ptp_clock.caps, NULL);
return PTR_ERR_OR_ZERO(kvm_ptp_clock.ptp_clock);
}
