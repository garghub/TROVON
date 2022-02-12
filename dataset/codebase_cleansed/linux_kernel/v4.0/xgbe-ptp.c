static cycle_t xgbe_cc_read(const struct cyclecounter *cc)
{
struct xgbe_prv_data *pdata = container_of(cc,
struct xgbe_prv_data,
tstamp_cc);
u64 nsec;
nsec = pdata->hw_if.get_tstamp_time(pdata);
return nsec;
}
static int xgbe_adjfreq(struct ptp_clock_info *info, s32 delta)
{
struct xgbe_prv_data *pdata = container_of(info,
struct xgbe_prv_data,
ptp_clock_info);
unsigned long flags;
u64 adjust;
u32 addend, diff;
unsigned int neg_adjust = 0;
if (delta < 0) {
neg_adjust = 1;
delta = -delta;
}
adjust = pdata->tstamp_addend;
adjust *= delta;
diff = div_u64(adjust, 1000000000UL);
addend = (neg_adjust) ? pdata->tstamp_addend - diff :
pdata->tstamp_addend + diff;
spin_lock_irqsave(&pdata->tstamp_lock, flags);
pdata->hw_if.update_tstamp_addend(pdata, addend);
spin_unlock_irqrestore(&pdata->tstamp_lock, flags);
return 0;
}
static int xgbe_adjtime(struct ptp_clock_info *info, s64 delta)
{
struct xgbe_prv_data *pdata = container_of(info,
struct xgbe_prv_data,
ptp_clock_info);
unsigned long flags;
spin_lock_irqsave(&pdata->tstamp_lock, flags);
timecounter_adjtime(&pdata->tstamp_tc, delta);
spin_unlock_irqrestore(&pdata->tstamp_lock, flags);
return 0;
}
static int xgbe_gettime(struct ptp_clock_info *info, struct timespec *ts)
{
struct xgbe_prv_data *pdata = container_of(info,
struct xgbe_prv_data,
ptp_clock_info);
unsigned long flags;
u64 nsec;
spin_lock_irqsave(&pdata->tstamp_lock, flags);
nsec = timecounter_read(&pdata->tstamp_tc);
spin_unlock_irqrestore(&pdata->tstamp_lock, flags);
*ts = ns_to_timespec(nsec);
return 0;
}
static int xgbe_settime(struct ptp_clock_info *info, const struct timespec *ts)
{
struct xgbe_prv_data *pdata = container_of(info,
struct xgbe_prv_data,
ptp_clock_info);
unsigned long flags;
u64 nsec;
nsec = timespec_to_ns(ts);
spin_lock_irqsave(&pdata->tstamp_lock, flags);
timecounter_init(&pdata->tstamp_tc, &pdata->tstamp_cc, nsec);
spin_unlock_irqrestore(&pdata->tstamp_lock, flags);
return 0;
}
static int xgbe_enable(struct ptp_clock_info *info,
struct ptp_clock_request *request, int on)
{
return -EOPNOTSUPP;
}
void xgbe_ptp_register(struct xgbe_prv_data *pdata)
{
struct ptp_clock_info *info = &pdata->ptp_clock_info;
struct ptp_clock *clock;
struct cyclecounter *cc = &pdata->tstamp_cc;
u64 dividend;
snprintf(info->name, sizeof(info->name), "%s",
netdev_name(pdata->netdev));
info->owner = THIS_MODULE;
info->max_adj = pdata->ptpclk_rate;
info->adjfreq = xgbe_adjfreq;
info->adjtime = xgbe_adjtime;
info->gettime = xgbe_gettime;
info->settime = xgbe_settime;
info->enable = xgbe_enable;
clock = ptp_clock_register(info, pdata->dev);
if (IS_ERR(clock)) {
dev_err(pdata->dev, "ptp_clock_register failed\n");
return;
}
pdata->ptp_clock = clock;
dividend = 50000000;
dividend <<= 32;
pdata->tstamp_addend = div_u64(dividend, pdata->ptpclk_rate);
cc->read = xgbe_cc_read;
cc->mask = CLOCKSOURCE_MASK(64);
cc->mult = 1;
cc->shift = 0;
timecounter_init(&pdata->tstamp_tc, &pdata->tstamp_cc,
ktime_to_ns(ktime_get_real()));
XGMAC_IOWRITE(pdata, MAC_TCR, 0);
pdata->tstamp_config.tx_type = HWTSTAMP_TX_OFF;
pdata->tstamp_config.rx_filter = HWTSTAMP_FILTER_NONE;
}
void xgbe_ptp_unregister(struct xgbe_prv_data *pdata)
{
if (pdata->ptp_clock)
ptp_clock_unregister(pdata->ptp_clock);
}
