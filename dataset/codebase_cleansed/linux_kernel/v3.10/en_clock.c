int mlx4_en_timestamp_config(struct net_device *dev, int tx_type, int rx_filter)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
struct mlx4_en_dev *mdev = priv->mdev;
int port_up = 0;
int err = 0;
mutex_lock(&mdev->state_lock);
if (priv->port_up) {
port_up = 1;
mlx4_en_stop_port(dev, 1);
}
mlx4_en_free_resources(priv);
en_warn(priv, "Changing Time Stamp configuration\n");
priv->hwtstamp_config.tx_type = tx_type;
priv->hwtstamp_config.rx_filter = rx_filter;
if (rx_filter != HWTSTAMP_FILTER_NONE)
dev->features &= ~NETIF_F_HW_VLAN_CTAG_RX;
else
dev->features |= NETIF_F_HW_VLAN_CTAG_RX;
err = mlx4_en_alloc_resources(priv);
if (err) {
en_err(priv, "Failed reallocating port resources\n");
goto out;
}
if (port_up) {
err = mlx4_en_start_port(dev);
if (err)
en_err(priv, "Failed starting port\n");
}
out:
mutex_unlock(&mdev->state_lock);
netdev_features_change(dev);
return err;
}
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
u64 nsec;
nsec = timecounter_cyc2time(&mdev->clock, timestamp);
memset(hwts, 0, sizeof(struct skb_shared_hwtstamps));
hwts->hwtstamp = ns_to_ktime(nsec);
}
void mlx4_en_init_timestamp(struct mlx4_en_dev *mdev)
{
struct mlx4_dev *dev = mdev->dev;
u64 ns;
memset(&mdev->cycles, 0, sizeof(mdev->cycles));
mdev->cycles.read = mlx4_en_read_clock;
mdev->cycles.mask = CLOCKSOURCE_MASK(48);
mdev->cycles.shift = 14;
mdev->cycles.mult =
clocksource_khz2mult(1000 * dev->caps.hca_core_clock, mdev->cycles.shift);
timecounter_init(&mdev->clock, &mdev->cycles,
ktime_to_ns(ktime_get_real()));
ns = cyclecounter_cyc2ns(&mdev->cycles, mdev->cycles.mask);
do_div(ns, NSEC_PER_SEC / 2 / HZ);
mdev->overflow_period = ns;
}
void mlx4_en_ptp_overflow_check(struct mlx4_en_dev *mdev)
{
bool timeout = time_is_before_jiffies(mdev->last_overflow_check +
mdev->overflow_period);
if (timeout) {
timecounter_read(&mdev->clock);
mdev->last_overflow_check = jiffies;
}
}
