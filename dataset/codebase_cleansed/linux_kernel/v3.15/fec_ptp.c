static cycle_t fec_ptp_read(const struct cyclecounter *cc)
{
struct fec_enet_private *fep =
container_of(cc, struct fec_enet_private, cc);
u32 tempval;
tempval = readl(fep->hwp + FEC_ATIME_CTRL);
tempval |= FEC_T_CTRL_CAPTURE;
writel(tempval, fep->hwp + FEC_ATIME_CTRL);
return readl(fep->hwp + FEC_ATIME);
}
void fec_ptp_start_cyclecounter(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
unsigned long flags;
int inc;
inc = 1000000000 / fep->cycle_speed;
spin_lock_irqsave(&fep->tmreg_lock, flags);
writel(inc << FEC_T_INC_OFFSET, fep->hwp + FEC_ATIME_INC);
writel(0, fep->hwp + FEC_ATIME_EVT_PERIOD);
writel(FEC_T_CTRL_ENABLE, fep->hwp + FEC_ATIME_CTRL);
memset(&fep->cc, 0, sizeof(fep->cc));
fep->cc.read = fec_ptp_read;
fep->cc.mask = CLOCKSOURCE_MASK(32);
fep->cc.shift = 31;
fep->cc.mult = FEC_CC_MULT;
timecounter_init(&fep->tc, &fep->cc, ktime_to_ns(ktime_get_real()));
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
}
static int fec_ptp_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
u64 diff;
unsigned long flags;
int neg_adj = 0;
u32 mult = FEC_CC_MULT;
struct fec_enet_private *fep =
container_of(ptp, struct fec_enet_private, ptp_caps);
if (ppb < 0) {
ppb = -ppb;
neg_adj = 1;
}
diff = mult;
diff *= ppb;
diff = div_u64(diff, 1000000000ULL);
spin_lock_irqsave(&fep->tmreg_lock, flags);
timecounter_read(&fep->tc);
fep->cc.mult = neg_adj ? mult - diff : mult + diff;
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
return 0;
}
static int fec_ptp_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
struct fec_enet_private *fep =
container_of(ptp, struct fec_enet_private, ptp_caps);
unsigned long flags;
u64 now;
spin_lock_irqsave(&fep->tmreg_lock, flags);
now = timecounter_read(&fep->tc);
now += delta;
timecounter_init(&fep->tc, &fep->cc, now);
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
return 0;
}
static int fec_ptp_gettime(struct ptp_clock_info *ptp, struct timespec *ts)
{
struct fec_enet_private *adapter =
container_of(ptp, struct fec_enet_private, ptp_caps);
u64 ns;
u32 remainder;
unsigned long flags;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
ns = timecounter_read(&adapter->tc);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
ts->tv_sec = div_u64_rem(ns, 1000000000ULL, &remainder);
ts->tv_nsec = remainder;
return 0;
}
static int fec_ptp_settime(struct ptp_clock_info *ptp,
const struct timespec *ts)
{
struct fec_enet_private *fep =
container_of(ptp, struct fec_enet_private, ptp_caps);
u64 ns;
unsigned long flags;
ns = ts->tv_sec * 1000000000ULL;
ns += ts->tv_nsec;
spin_lock_irqsave(&fep->tmreg_lock, flags);
timecounter_init(&fep->tc, &fep->cc, ns);
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
return 0;
}
static int fec_ptp_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
return -EOPNOTSUPP;
}
int fec_ptp_set(struct net_device *ndev, struct ifreq *ifr)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct hwtstamp_config config;
if (copy_from_user(&config, ifr->ifr_data, sizeof(config)))
return -EFAULT;
if (config.flags)
return -EINVAL;
switch (config.tx_type) {
case HWTSTAMP_TX_OFF:
fep->hwts_tx_en = 0;
break;
case HWTSTAMP_TX_ON:
fep->hwts_tx_en = 1;
break;
default:
return -ERANGE;
}
switch (config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
if (fep->hwts_rx_en)
fep->hwts_rx_en = 0;
config.rx_filter = HWTSTAMP_FILTER_NONE;
break;
default:
fep->hwts_rx_en = 1;
config.rx_filter = HWTSTAMP_FILTER_ALL;
break;
}
return copy_to_user(ifr->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
int fec_ptp_get(struct net_device *ndev, struct ifreq *ifr)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct hwtstamp_config config;
config.flags = 0;
config.tx_type = fep->hwts_tx_en ? HWTSTAMP_TX_ON : HWTSTAMP_TX_OFF;
config.rx_filter = (fep->hwts_rx_en ?
HWTSTAMP_FILTER_ALL : HWTSTAMP_FILTER_NONE);
return copy_to_user(ifr->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
static void fec_time_keep(unsigned long _data)
{
struct fec_enet_private *fep = (struct fec_enet_private *)_data;
u64 ns;
unsigned long flags;
spin_lock_irqsave(&fep->tmreg_lock, flags);
ns = timecounter_read(&fep->tc);
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
mod_timer(&fep->time_keep, jiffies + HZ);
}
void fec_ptp_init(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct fec_enet_private *fep = netdev_priv(ndev);
fep->ptp_caps.owner = THIS_MODULE;
snprintf(fep->ptp_caps.name, 16, "fec ptp");
fep->ptp_caps.max_adj = 250000000;
fep->ptp_caps.n_alarm = 0;
fep->ptp_caps.n_ext_ts = 0;
fep->ptp_caps.n_per_out = 0;
fep->ptp_caps.n_pins = 0;
fep->ptp_caps.pps = 0;
fep->ptp_caps.adjfreq = fec_ptp_adjfreq;
fep->ptp_caps.adjtime = fec_ptp_adjtime;
fep->ptp_caps.gettime = fec_ptp_gettime;
fep->ptp_caps.settime = fec_ptp_settime;
fep->ptp_caps.enable = fec_ptp_enable;
fep->cycle_speed = clk_get_rate(fep->clk_ptp);
spin_lock_init(&fep->tmreg_lock);
fec_ptp_start_cyclecounter(ndev);
init_timer(&fep->time_keep);
fep->time_keep.data = (unsigned long)fep;
fep->time_keep.function = fec_time_keep;
fep->time_keep.expires = jiffies + HZ;
add_timer(&fep->time_keep);
fep->ptp_clock = ptp_clock_register(&fep->ptp_caps, &pdev->dev);
if (IS_ERR(fep->ptp_clock)) {
fep->ptp_clock = NULL;
pr_err("ptp_clock_register failed\n");
}
}
