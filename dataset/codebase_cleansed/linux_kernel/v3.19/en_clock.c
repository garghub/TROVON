static cycle_t mlx4_en_read_clock(const struct cyclecounter *tc)
{
struct mlx4_en_dev *mdev =
container_of(tc, struct mlx4_en_dev, cycles);
struct mlx4_dev *dev = mdev->dev;
return mlx4_read_clock(dev) & tc->mask;
}
u64 mlx4_en_get_cqe_ts(struct mlx4_cqe *cqe)
{
u64 hi, lo;
struct mlx4_ts_cqe *ts_cqe = (struct mlx4_ts_cqe *)cqe;
lo = (u64)be16_to_cpu(ts_cqe->timestamp_lo);
hi = ((u64)be32_to_cpu(ts_cqe->timestamp_hi) + !lo) << 16;
return hi | lo;
}
void mlx4_en_fill_hwtstamps(struct mlx4_en_dev *mdev,
struct skb_shared_hwtstamps *hwts,
u64 timestamp)
{
unsigned long flags;
u64 nsec;
read_lock_irqsave(&mdev->clock_lock, flags);
nsec = timecounter_cyc2time(&mdev->clock, timestamp);
read_unlock_irqrestore(&mdev->clock_lock, flags);
memset(hwts, 0, sizeof(struct skb_shared_hwtstamps));
hwts->hwtstamp = ns_to_ktime(nsec);
}
void mlx4_en_remove_timestamp(struct mlx4_en_dev *mdev)
{
if (mdev->ptp_clock) {
ptp_clock_unregister(mdev->ptp_clock);
mdev->ptp_clock = NULL;
mlx4_info(mdev, "removed PHC\n");
}
}
void mlx4_en_ptp_overflow_check(struct mlx4_en_dev *mdev)
{
bool timeout = time_is_before_jiffies(mdev->last_overflow_check +
mdev->overflow_period);
unsigned long flags;
if (timeout) {
write_lock_irqsave(&mdev->clock_lock, flags);
timecounter_read(&mdev->clock);
write_unlock_irqrestore(&mdev->clock_lock, flags);
mdev->last_overflow_check = jiffies;
}
}
static int mlx4_en_phc_adjfreq(struct ptp_clock_info *ptp, s32 delta)
{
u64 adj;
u32 diff, mult;
int neg_adj = 0;
unsigned long flags;
struct mlx4_en_dev *mdev = container_of(ptp, struct mlx4_en_dev,
ptp_clock_info);
if (delta < 0) {
neg_adj = 1;
delta = -delta;
}
mult = mdev->nominal_c_mult;
adj = mult;
adj *= delta;
diff = div_u64(adj, 1000000000ULL);
write_lock_irqsave(&mdev->clock_lock, flags);
timecounter_read(&mdev->clock);
mdev->cycles.mult = neg_adj ? mult - diff : mult + diff;
write_unlock_irqrestore(&mdev->clock_lock, flags);
return 0;
}
static int mlx4_en_phc_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
struct mlx4_en_dev *mdev = container_of(ptp, struct mlx4_en_dev,
ptp_clock_info);
unsigned long flags;
s64 now;
write_lock_irqsave(&mdev->clock_lock, flags);
now = timecounter_read(&mdev->clock);
now += delta;
timecounter_init(&mdev->clock, &mdev->cycles, now);
write_unlock_irqrestore(&mdev->clock_lock, flags);
return 0;
}
static int mlx4_en_phc_gettime(struct ptp_clock_info *ptp, struct timespec *ts)
{
struct mlx4_en_dev *mdev = container_of(ptp, struct mlx4_en_dev,
ptp_clock_info);
unsigned long flags;
u32 remainder;
u64 ns;
write_lock_irqsave(&mdev->clock_lock, flags);
ns = timecounter_read(&mdev->clock);
write_unlock_irqrestore(&mdev->clock_lock, flags);
ts->tv_sec = div_u64_rem(ns, NSEC_PER_SEC, &remainder);
ts->tv_nsec = remainder;
return 0;
}
static int mlx4_en_phc_settime(struct ptp_clock_info *ptp,
const struct timespec *ts)
{
struct mlx4_en_dev *mdev = container_of(ptp, struct mlx4_en_dev,
ptp_clock_info);
u64 ns = timespec_to_ns(ts);
unsigned long flags;
write_lock_irqsave(&mdev->clock_lock, flags);
timecounter_init(&mdev->clock, &mdev->cycles, ns);
write_unlock_irqrestore(&mdev->clock_lock, flags);
return 0;
}
static int mlx4_en_phc_enable(struct ptp_clock_info __always_unused *ptp,
struct ptp_clock_request __always_unused *request,
int __always_unused on)
{
return -EOPNOTSUPP;
}
void mlx4_en_init_timestamp(struct mlx4_en_dev *mdev)
{
struct mlx4_dev *dev = mdev->dev;
unsigned long flags;
u64 ns;
rwlock_init(&mdev->clock_lock);
memset(&mdev->cycles, 0, sizeof(mdev->cycles));
mdev->cycles.read = mlx4_en_read_clock;
mdev->cycles.mask = CLOCKSOURCE_MASK(48);
mdev->cycles.shift = 14;
mdev->cycles.mult =
clocksource_khz2mult(1000 * dev->caps.hca_core_clock, mdev->cycles.shift);
mdev->nominal_c_mult = mdev->cycles.mult;
write_lock_irqsave(&mdev->clock_lock, flags);
timecounter_init(&mdev->clock, &mdev->cycles,
ktime_to_ns(ktime_get_real()));
write_unlock_irqrestore(&mdev->clock_lock, flags);
ns = cyclecounter_cyc2ns(&mdev->cycles, mdev->cycles.mask);
do_div(ns, NSEC_PER_SEC / 2 / HZ);
mdev->overflow_period = ns;
mdev->ptp_clock_info = mlx4_en_ptp_clock_info;
snprintf(mdev->ptp_clock_info.name, 16, "mlx4 ptp");
mdev->ptp_clock = ptp_clock_register(&mdev->ptp_clock_info,
&mdev->pdev->dev);
if (IS_ERR(mdev->ptp_clock)) {
mdev->ptp_clock = NULL;
mlx4_err(mdev, "ptp_clock_register failed\n");
} else {
mlx4_info(mdev, "registered PHC clock\n");
}
}
