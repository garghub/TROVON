static int fec_ptp_enable_pps(struct fec_enet_private *fep, uint enable)
{
unsigned long flags;
u32 val, tempval;
int inc;
struct timespec64 ts;
u64 ns;
val = 0;
if (!(fep->hwts_tx_en || fep->hwts_rx_en)) {
dev_err(&fep->pdev->dev, "No ptp stack is running\n");
return -EINVAL;
}
if (fep->pps_enable == enable)
return 0;
fep->pps_channel = DEFAULT_PPS_CHANNEL;
fep->reload_period = PPS_OUPUT_RELOAD_PERIOD;
inc = fep->ptp_inc;
spin_lock_irqsave(&fep->tmreg_lock, flags);
if (enable) {
writel(FEC_T_TF_MASK, fep->hwp + FEC_TCSR(fep->pps_channel));
val = readl(fep->hwp + FEC_TCSR(fep->pps_channel));
do {
val &= ~(FEC_T_TMODE_MASK);
writel(val, fep->hwp + FEC_TCSR(fep->pps_channel));
val = readl(fep->hwp + FEC_TCSR(fep->pps_channel));
} while (val & FEC_T_TMODE_MASK);
timecounter_read(&fep->tc);
tempval = readl(fep->hwp + FEC_ATIME_CTRL);
tempval |= FEC_T_CTRL_CAPTURE;
writel(tempval, fep->hwp + FEC_ATIME_CTRL);
tempval = readl(fep->hwp + FEC_ATIME);
ns = timecounter_cyc2time(&fep->tc, tempval);
ts = ns_to_timespec64(ns);
val = NSEC_PER_SEC - (u32)ts.tv_nsec + tempval;
val += NSEC_PER_SEC;
val &= fep->cc.mask;
writel(val, fep->hwp + FEC_TCCR(fep->pps_channel));
fep->next_counter = (val + fep->reload_period) & fep->cc.mask;
val = readl(fep->hwp + FEC_ATIME_CTRL);
val |= FEC_T_CTRL_PINPER;
writel(val, fep->hwp + FEC_ATIME_CTRL);
val = readl(fep->hwp + FEC_TCSR(fep->pps_channel));
val |= (1 << FEC_T_TF_OFFSET | 1 << FEC_T_TIE_OFFSET);
val &= ~(1 << FEC_T_TDRE_OFFSET);
val &= ~(FEC_T_TMODE_MASK);
val |= (FEC_HIGH_PULSE << FEC_T_TMODE_OFFSET);
writel(val, fep->hwp + FEC_TCSR(fep->pps_channel));
writel(fep->next_counter, fep->hwp + FEC_TCCR(fep->pps_channel));
fep->next_counter = (fep->next_counter + fep->reload_period) & fep->cc.mask;
} else {
writel(0, fep->hwp + FEC_TCSR(fep->pps_channel));
}
fep->pps_enable = enable;
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
return 0;
}
static u64 fec_ptp_read(const struct cyclecounter *cc)
{
struct fec_enet_private *fep =
container_of(cc, struct fec_enet_private, cc);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
u32 tempval;
tempval = readl(fep->hwp + FEC_ATIME_CTRL);
tempval |= FEC_T_CTRL_CAPTURE;
writel(tempval, fep->hwp + FEC_ATIME_CTRL);
if (id_entry->driver_data & FEC_QUIRK_BUG_CAPTURE)
udelay(1);
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
writel(FEC_COUNTER_PERIOD, fep->hwp + FEC_ATIME_EVT_PERIOD);
writel(FEC_T_CTRL_ENABLE | FEC_T_CTRL_PERIOD_RST,
fep->hwp + FEC_ATIME_CTRL);
memset(&fep->cc, 0, sizeof(fep->cc));
fep->cc.read = fec_ptp_read;
fep->cc.mask = CLOCKSOURCE_MASK(31);
fep->cc.shift = 31;
fep->cc.mult = FEC_CC_MULT;
timecounter_init(&fep->tc, &fep->cc, ktime_to_ns(ktime_get_real()));
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
}
static int fec_ptp_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
unsigned long flags;
int neg_adj = 0;
u32 i, tmp;
u32 corr_inc, corr_period;
u32 corr_ns;
u64 lhs, rhs;
struct fec_enet_private *fep =
container_of(ptp, struct fec_enet_private, ptp_caps);
if (ppb == 0)
return 0;
if (ppb < 0) {
ppb = -ppb;
neg_adj = 1;
}
lhs = NSEC_PER_SEC;
rhs = (u64)ppb * (u64)fep->ptp_inc;
for (i = 1; i <= fep->ptp_inc; i++) {
if (lhs >= rhs) {
corr_inc = i;
corr_period = div_u64(lhs, rhs);
break;
}
lhs += NSEC_PER_SEC;
}
if (i > fep->ptp_inc) {
corr_inc = fep->ptp_inc;
corr_period = 1;
}
if (neg_adj)
corr_ns = fep->ptp_inc - corr_inc;
else
corr_ns = fep->ptp_inc + corr_inc;
spin_lock_irqsave(&fep->tmreg_lock, flags);
tmp = readl(fep->hwp + FEC_ATIME_INC) & FEC_T_INC_MASK;
tmp |= corr_ns << FEC_T_INC_CORR_OFFSET;
writel(tmp, fep->hwp + FEC_ATIME_INC);
corr_period = corr_period > 1 ? corr_period - 1 : corr_period;
writel(corr_period, fep->hwp + FEC_ATIME_CORR);
timecounter_read(&fep->tc);
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
return 0;
}
static int fec_ptp_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
struct fec_enet_private *fep =
container_of(ptp, struct fec_enet_private, ptp_caps);
unsigned long flags;
spin_lock_irqsave(&fep->tmreg_lock, flags);
timecounter_adjtime(&fep->tc, delta);
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
return 0;
}
static int fec_ptp_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
struct fec_enet_private *adapter =
container_of(ptp, struct fec_enet_private, ptp_caps);
u64 ns;
unsigned long flags;
spin_lock_irqsave(&adapter->tmreg_lock, flags);
ns = timecounter_read(&adapter->tc);
spin_unlock_irqrestore(&adapter->tmreg_lock, flags);
*ts = ns_to_timespec64(ns);
return 0;
}
static int fec_ptp_settime(struct ptp_clock_info *ptp,
const struct timespec64 *ts)
{
struct fec_enet_private *fep =
container_of(ptp, struct fec_enet_private, ptp_caps);
u64 ns;
unsigned long flags;
u32 counter;
mutex_lock(&fep->ptp_clk_mutex);
if (!fep->ptp_clk_on) {
mutex_unlock(&fep->ptp_clk_mutex);
return -EINVAL;
}
ns = timespec64_to_ns(ts);
counter = ns & fep->cc.mask;
spin_lock_irqsave(&fep->tmreg_lock, flags);
writel(counter, fep->hwp + FEC_ATIME);
timecounter_init(&fep->tc, &fep->cc, ns);
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
mutex_unlock(&fep->ptp_clk_mutex);
return 0;
}
static int fec_ptp_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
struct fec_enet_private *fep =
container_of(ptp, struct fec_enet_private, ptp_caps);
int ret = 0;
if (rq->type == PTP_CLK_REQ_PPS) {
ret = fec_ptp_enable_pps(fep, on);
return ret;
}
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
static void fec_time_keep(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct fec_enet_private *fep = container_of(dwork, struct fec_enet_private, time_keep);
u64 ns;
unsigned long flags;
mutex_lock(&fep->ptp_clk_mutex);
if (fep->ptp_clk_on) {
spin_lock_irqsave(&fep->tmreg_lock, flags);
ns = timecounter_read(&fep->tc);
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
}
mutex_unlock(&fep->ptp_clk_mutex);
schedule_delayed_work(&fep->time_keep, HZ);
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
fep->ptp_caps.pps = 1;
fep->ptp_caps.adjfreq = fec_ptp_adjfreq;
fep->ptp_caps.adjtime = fec_ptp_adjtime;
fep->ptp_caps.gettime64 = fec_ptp_gettime;
fep->ptp_caps.settime64 = fec_ptp_settime;
fep->ptp_caps.enable = fec_ptp_enable;
fep->cycle_speed = clk_get_rate(fep->clk_ptp);
fep->ptp_inc = NSEC_PER_SEC / fep->cycle_speed;
spin_lock_init(&fep->tmreg_lock);
fec_ptp_start_cyclecounter(ndev);
INIT_DELAYED_WORK(&fep->time_keep, fec_time_keep);
fep->ptp_clock = ptp_clock_register(&fep->ptp_caps, &pdev->dev);
if (IS_ERR(fep->ptp_clock)) {
fep->ptp_clock = NULL;
pr_err("ptp_clock_register failed\n");
}
schedule_delayed_work(&fep->time_keep, HZ);
}
void fec_ptp_stop(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct fec_enet_private *fep = netdev_priv(ndev);
cancel_delayed_work_sync(&fep->time_keep);
if (fep->ptp_clock)
ptp_clock_unregister(fep->ptp_clock);
}
uint fec_ptp_check_pps_event(struct fec_enet_private *fep)
{
u32 val;
u8 channel = fep->pps_channel;
struct ptp_clock_event event;
val = readl(fep->hwp + FEC_TCSR(channel));
if (val & FEC_T_TF_MASK) {
writel(fep->next_counter, fep->hwp + FEC_TCCR(channel));
do {
writel(val, fep->hwp + FEC_TCSR(channel));
} while (readl(fep->hwp + FEC_TCSR(channel)) & FEC_T_TF_MASK);
fep->next_counter = (fep->next_counter + fep->reload_period) & fep->cc.mask;
event.type = PTP_CLOCK_PPS;
ptp_clock_event(fep->ptp_clock, &event);
return 1;
}
return 0;
}
