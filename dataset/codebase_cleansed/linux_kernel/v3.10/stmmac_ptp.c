static int stmmac_adjust_freq(struct ptp_clock_info *ptp, s32 ppb)
{
struct stmmac_priv *priv =
container_of(ptp, struct stmmac_priv, ptp_clock_ops);
unsigned long flags;
u32 diff, addend;
int neg_adj = 0;
u64 adj;
if (ppb < 0) {
neg_adj = 1;
ppb = -ppb;
}
addend = priv->default_addend;
adj = addend;
adj *= ppb;
diff = div_u64(adj, 1000000000ULL);
addend = neg_adj ? (addend - diff) : (addend + diff);
spin_lock_irqsave(&priv->ptp_lock, flags);
priv->hw->ptp->config_addend(priv->ioaddr, addend);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int stmmac_adjust_time(struct ptp_clock_info *ptp, s64 delta)
{
struct stmmac_priv *priv =
container_of(ptp, struct stmmac_priv, ptp_clock_ops);
unsigned long flags;
u32 sec, nsec;
u32 quotient, reminder;
int neg_adj = 0;
if (delta < 0) {
neg_adj = 1;
delta = -delta;
}
quotient = div_u64_rem(delta, 1000000000ULL, &reminder);
sec = quotient;
nsec = reminder;
spin_lock_irqsave(&priv->ptp_lock, flags);
priv->hw->ptp->adjust_systime(priv->ioaddr, sec, nsec, neg_adj);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int stmmac_get_time(struct ptp_clock_info *ptp, struct timespec *ts)
{
struct stmmac_priv *priv =
container_of(ptp, struct stmmac_priv, ptp_clock_ops);
unsigned long flags;
u64 ns;
u32 reminder;
spin_lock_irqsave(&priv->ptp_lock, flags);
ns = priv->hw->ptp->get_systime(priv->ioaddr);
spin_unlock_irqrestore(&priv->ptp_lock, flags);
ts->tv_sec = div_u64_rem(ns, 1000000000ULL, &reminder);
ts->tv_nsec = reminder;
return 0;
}
static int stmmac_set_time(struct ptp_clock_info *ptp,
const struct timespec *ts)
{
struct stmmac_priv *priv =
container_of(ptp, struct stmmac_priv, ptp_clock_ops);
unsigned long flags;
spin_lock_irqsave(&priv->ptp_lock, flags);
priv->hw->ptp->init_systime(priv->ioaddr, ts->tv_sec, ts->tv_nsec);
spin_unlock_irqrestore(&priv->ptp_lock, flags);
return 0;
}
static int stmmac_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
return -EOPNOTSUPP;
}
int stmmac_ptp_register(struct stmmac_priv *priv)
{
spin_lock_init(&priv->ptp_lock);
priv->ptp_clock_ops = stmmac_ptp_clock_ops;
priv->ptp_clock = ptp_clock_register(&priv->ptp_clock_ops,
priv->device);
if (IS_ERR(priv->ptp_clock)) {
priv->ptp_clock = NULL;
pr_err("ptp_clock_register() failed on %s\n", priv->dev->name);
} else
pr_debug("Added PTP HW clock successfully on %s\n",
priv->dev->name);
return 0;
}
void stmmac_ptp_unregister(struct stmmac_priv *priv)
{
if (priv->ptp_clock) {
ptp_clock_unregister(priv->ptp_clock);
pr_debug("Removed PTP HW clock successfully on %s\n",
priv->dev->name);
}
}
