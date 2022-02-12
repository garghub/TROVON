static int e1000e_phc_adjfreq(struct ptp_clock_info *ptp, s32 delta)
{
struct e1000_adapter *adapter = container_of(ptp, struct e1000_adapter,
ptp_clock_info);
struct e1000_hw *hw = &adapter->hw;
bool neg_adj = false;
unsigned long flags;
u64 adjustment;
u32 timinca, incvalue;
s32 ret_val;
if ((delta > ptp->max_adj) || (delta <= -1000000000))
return -EINVAL;
if (delta < 0) {
neg_adj = true;
delta = -delta;
}
ret_val = e1000e_get_base_timinca(adapter, &timinca);
if (ret_val)
return ret_val;
spin_lock_irqsave(&adapter->systim_lock, flags);
incvalue = timinca & E1000_TIMINCA_INCVALUE_MASK;
adjustment = incvalue;
adjustment *= delta;
adjustment = div_u64(adjustment, 1000000000);
incvalue = neg_adj ? (incvalue - adjustment) : (incvalue + adjustment);
timinca &= ~E1000_TIMINCA_INCVALUE_MASK;
timinca |= incvalue;
ew32(TIMINCA, timinca);
adapter->ptp_delta = delta;
spin_unlock_irqrestore(&adapter->systim_lock, flags);
return 0;
}
static int e1000e_phc_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
struct e1000_adapter *adapter = container_of(ptp, struct e1000_adapter,
ptp_clock_info);
unsigned long flags;
spin_lock_irqsave(&adapter->systim_lock, flags);
timecounter_adjtime(&adapter->tc, delta);
spin_unlock_irqrestore(&adapter->systim_lock, flags);
return 0;
}
static int e1000e_phc_get_syncdevicetime(ktime_t *device,
struct system_counterval_t *system,
void *ctx)
{
struct e1000_adapter *adapter = (struct e1000_adapter *)ctx;
struct e1000_hw *hw = &adapter->hw;
unsigned long flags;
int i;
u32 tsync_ctrl;
u64 dev_cycles;
u64 sys_cycles;
tsync_ctrl = er32(TSYNCTXCTL);
tsync_ctrl |= E1000_TSYNCTXCTL_START_SYNC |
E1000_TSYNCTXCTL_MAX_ALLOWED_DLY_MASK;
ew32(TSYNCTXCTL, tsync_ctrl);
for (i = 0; i < MAX_HW_WAIT_COUNT; ++i) {
udelay(1);
tsync_ctrl = er32(TSYNCTXCTL);
if (tsync_ctrl & E1000_TSYNCTXCTL_SYNC_COMP)
break;
}
if (i == MAX_HW_WAIT_COUNT)
return -ETIMEDOUT;
dev_cycles = er32(SYSSTMPH);
dev_cycles <<= 32;
dev_cycles |= er32(SYSSTMPL);
spin_lock_irqsave(&adapter->systim_lock, flags);
*device = ns_to_ktime(timecounter_cyc2time(&adapter->tc, dev_cycles));
spin_unlock_irqrestore(&adapter->systim_lock, flags);
sys_cycles = er32(PLTSTMPH);
sys_cycles <<= 32;
sys_cycles |= er32(PLTSTMPL);
*system = convert_art_to_tsc(sys_cycles);
return 0;
}
static int e1000e_phc_getcrosststamp(struct ptp_clock_info *ptp,
struct system_device_crosststamp *xtstamp)
{
struct e1000_adapter *adapter = container_of(ptp, struct e1000_adapter,
ptp_clock_info);
return get_device_system_crosststamp(e1000e_phc_get_syncdevicetime,
adapter, NULL, xtstamp);
}
static int e1000e_phc_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
struct e1000_adapter *adapter = container_of(ptp, struct e1000_adapter,
ptp_clock_info);
unsigned long flags;
u64 ns;
spin_lock_irqsave(&adapter->systim_lock, flags);
ns = timecounter_read(&adapter->tc);
spin_unlock_irqrestore(&adapter->systim_lock, flags);
*ts = ns_to_timespec64(ns);
return 0;
}
static int e1000e_phc_settime(struct ptp_clock_info *ptp,
const struct timespec64 *ts)
{
struct e1000_adapter *adapter = container_of(ptp, struct e1000_adapter,
ptp_clock_info);
unsigned long flags;
u64 ns;
ns = timespec64_to_ns(ts);
spin_lock_irqsave(&adapter->systim_lock, flags);
timecounter_init(&adapter->tc, &adapter->cc, ns);
spin_unlock_irqrestore(&adapter->systim_lock, flags);
return 0;
}
static int e1000e_phc_enable(struct ptp_clock_info __always_unused *ptp,
struct ptp_clock_request __always_unused *request,
int __always_unused on)
{
return -EOPNOTSUPP;
}
static void e1000e_systim_overflow_work(struct work_struct *work)
{
struct e1000_adapter *adapter = container_of(work, struct e1000_adapter,
systim_overflow_work.work);
struct e1000_hw *hw = &adapter->hw;
struct timespec64 ts;
adapter->ptp_clock_info.gettime64(&adapter->ptp_clock_info, &ts);
e_dbg("SYSTIM overflow check at %lld.%09lu\n",
(long long) ts.tv_sec, ts.tv_nsec);
schedule_delayed_work(&adapter->systim_overflow_work,
E1000_SYSTIM_OVERFLOW_PERIOD);
}
void e1000e_ptp_init(struct e1000_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
adapter->ptp_clock = NULL;
if (!(adapter->flags & FLAG_HAS_HW_TIMESTAMP))
return;
adapter->ptp_clock_info = e1000e_ptp_clock_info;
snprintf(adapter->ptp_clock_info.name,
sizeof(adapter->ptp_clock_info.name), "%pm",
adapter->netdev->perm_addr);
switch (hw->mac.type) {
case e1000_pch2lan:
case e1000_pch_lpt:
case e1000_pch_spt:
case e1000_pch_cnp:
if ((hw->mac.type < e1000_pch_lpt) ||
(er32(TSYNCRXCTL) & E1000_TSYNCRXCTL_SYSCFI)) {
adapter->ptp_clock_info.max_adj = 24000000 - 1;
break;
}
case e1000_82574:
case e1000_82583:
adapter->ptp_clock_info.max_adj = 600000000 - 1;
break;
default:
break;
}
#ifdef CONFIG_E1000E_HWTS
if (hw->mac.type >= e1000_pch_spt && boot_cpu_has(X86_FEATURE_ART))
adapter->ptp_clock_info.getcrosststamp =
e1000e_phc_getcrosststamp;
#endif
INIT_DELAYED_WORK(&adapter->systim_overflow_work,
e1000e_systim_overflow_work);
schedule_delayed_work(&adapter->systim_overflow_work,
E1000_SYSTIM_OVERFLOW_PERIOD);
adapter->ptp_clock = ptp_clock_register(&adapter->ptp_clock_info,
&adapter->pdev->dev);
if (IS_ERR(adapter->ptp_clock)) {
adapter->ptp_clock = NULL;
e_err("ptp_clock_register failed\n");
} else if (adapter->ptp_clock) {
e_info("registered PHC clock\n");
}
}
void e1000e_ptp_remove(struct e1000_adapter *adapter)
{
if (!(adapter->flags & FLAG_HAS_HW_TIMESTAMP))
return;
cancel_delayed_work_sync(&adapter->systim_overflow_work);
if (adapter->ptp_clock) {
ptp_clock_unregister(adapter->ptp_clock);
adapter->ptp_clock = NULL;
e_info("removed PHC\n");
}
}
