static inline void rcar_canfd_update(u32 mask, u32 val, u32 __iomem *reg)
{
u32 data = readl(reg);
data &= ~mask;
data |= (val & mask);
writel(data, reg);
}
static inline u32 rcar_canfd_read(void __iomem *base, u32 offset)
{
return readl(base + (offset));
}
static inline void rcar_canfd_write(void __iomem *base, u32 offset, u32 val)
{
writel(val, base + (offset));
}
static void rcar_canfd_set_bit(void __iomem *base, u32 reg, u32 val)
{
rcar_canfd_update(val, val, base + (reg));
}
static void rcar_canfd_clear_bit(void __iomem *base, u32 reg, u32 val)
{
rcar_canfd_update(val, 0, base + (reg));
}
static void rcar_canfd_update_bit(void __iomem *base, u32 reg,
u32 mask, u32 val)
{
rcar_canfd_update(mask, val, base + (reg));
}
static void rcar_canfd_get_data(struct rcar_canfd_channel *priv,
struct canfd_frame *cf, u32 off)
{
u32 i, lwords;
lwords = DIV_ROUND_UP(cf->len, sizeof(u32));
for (i = 0; i < lwords; i++)
*((u32 *)cf->data + i) =
rcar_canfd_read(priv->base, off + (i * sizeof(u32)));
}
static void rcar_canfd_put_data(struct rcar_canfd_channel *priv,
struct canfd_frame *cf, u32 off)
{
u32 i, lwords;
lwords = DIV_ROUND_UP(cf->len, sizeof(u32));
for (i = 0; i < lwords; i++)
rcar_canfd_write(priv->base, off + (i * sizeof(u32)),
*((u32 *)cf->data + i));
}
static void rcar_canfd_tx_failure_cleanup(struct net_device *ndev)
{
u32 i;
for (i = 0; i < RCANFD_FIFO_DEPTH; i++)
can_free_echo_skb(ndev, i);
}
static int rcar_canfd_reset_controller(struct rcar_canfd_global *gpriv)
{
u32 sts, ch;
int err;
err = readl_poll_timeout((gpriv->base + RCANFD_GSTS), sts,
!(sts & RCANFD_GSTS_GRAMINIT), 2, 500000);
if (err) {
dev_dbg(&gpriv->pdev->dev, "global raminit failed\n");
return err;
}
rcar_canfd_clear_bit(gpriv->base, RCANFD_GCTR, RCANFD_GCTR_GSLPR);
rcar_canfd_update_bit(gpriv->base, RCANFD_GCTR,
RCANFD_GCTR_GMDC_MASK, RCANFD_GCTR_GMDC_GRESET);
err = readl_poll_timeout((gpriv->base + RCANFD_GSTS), sts,
(sts & RCANFD_GSTS_GRSTSTS), 2, 500000);
if (err) {
dev_dbg(&gpriv->pdev->dev, "global reset failed\n");
return err;
}
rcar_canfd_write(gpriv->base, RCANFD_GERFL, 0x0);
if (gpriv->fdmode)
rcar_canfd_set_bit(gpriv->base, RCANFD_GRMCFG,
RCANFD_GRMCFG_RCMC);
else
rcar_canfd_clear_bit(gpriv->base, RCANFD_GRMCFG,
RCANFD_GRMCFG_RCMC);
for_each_set_bit(ch, &gpriv->channels_mask, RCANFD_NUM_CHANNELS) {
rcar_canfd_clear_bit(gpriv->base,
RCANFD_CCTR(ch), RCANFD_CCTR_CSLPR);
rcar_canfd_update_bit(gpriv->base, RCANFD_CCTR(ch),
RCANFD_CCTR_CHMDC_MASK,
RCANFD_CCTR_CHDMC_CRESET);
err = readl_poll_timeout((gpriv->base + RCANFD_CSTS(ch)), sts,
(sts & RCANFD_CSTS_CRSTSTS),
2, 500000);
if (err) {
dev_dbg(&gpriv->pdev->dev,
"channel %u reset failed\n", ch);
return err;
}
}
return 0;
}
static void rcar_canfd_configure_controller(struct rcar_canfd_global *gpriv)
{
u32 cfg, ch;
cfg = RCANFD_GCFG_EEFE;
if (gpriv->fdmode)
cfg |= RCANFD_GCFG_CMPOC;
if (gpriv->fcan != RCANFD_CANFDCLK)
cfg |= RCANFD_GCFG_DCS;
rcar_canfd_set_bit(gpriv->base, RCANFD_GCFG, cfg);
for_each_set_bit(ch, &gpriv->channels_mask, RCANFD_NUM_CHANNELS) {
rcar_canfd_set_bit(gpriv->base, RCANFD_CCTR(ch),
RCANFD_CCTR_ERRD);
rcar_canfd_update_bit(gpriv->base, RCANFD_CCTR(ch),
RCANFD_CCTR_BOM_MASK,
RCANFD_CCTR_BOM_BENTRY);
}
}
static void rcar_canfd_configure_afl_rules(struct rcar_canfd_global *gpriv,
u32 ch)
{
u32 cfg;
int offset, start, page, num_rules = RCANFD_CHANNEL_NUMRULES;
u32 ridx = ch + RCANFD_RFFIFO_IDX;
if (ch == 0) {
start = 0;
} else {
cfg = rcar_canfd_read(gpriv->base, RCANFD_GAFLCFG0);
start = RCANFD_GAFLCFG_GETRNC(0, cfg);
}
page = RCANFD_GAFL_PAGENUM(start);
rcar_canfd_set_bit(gpriv->base, RCANFD_GAFLECTR,
(RCANFD_GAFLECTR_AFLPN(page) |
RCANFD_GAFLECTR_AFLDAE));
rcar_canfd_set_bit(gpriv->base, RCANFD_GAFLCFG0,
RCANFD_GAFLCFG_SETRNC(ch, num_rules));
if (gpriv->fdmode)
offset = RCANFD_F_GAFL_OFFSET;
else
offset = RCANFD_C_GAFL_OFFSET;
rcar_canfd_write(gpriv->base, RCANFD_GAFLID(offset, start), 0);
rcar_canfd_write(gpriv->base, RCANFD_GAFLM(offset, start), 0);
rcar_canfd_write(gpriv->base, RCANFD_GAFLP0(offset, start), 0);
rcar_canfd_write(gpriv->base, RCANFD_GAFLP1(offset, start),
RCANFD_GAFLP1_GAFLFDP(ridx));
rcar_canfd_clear_bit(gpriv->base,
RCANFD_GAFLECTR, RCANFD_GAFLECTR_AFLDAE);
}
static void rcar_canfd_configure_rx(struct rcar_canfd_global *gpriv, u32 ch)
{
u32 cfg;
u16 rfdc, rfpls;
u32 ridx = ch + RCANFD_RFFIFO_IDX;
rfdc = 2;
if (gpriv->fdmode)
rfpls = 7;
else
rfpls = 0;
cfg = (RCANFD_RFCC_RFIM | RCANFD_RFCC_RFDC(rfdc) |
RCANFD_RFCC_RFPLS(rfpls) | RCANFD_RFCC_RFIE);
rcar_canfd_write(gpriv->base, RCANFD_RFCC(ridx), cfg);
}
static void rcar_canfd_configure_tx(struct rcar_canfd_global *gpriv, u32 ch)
{
u32 cfg;
u16 cftml, cfm, cfdc, cfpls;
cftml = 0;
cfm = 1;
cfdc = 2;
if (gpriv->fdmode)
cfpls = 7;
else
cfpls = 0;
cfg = (RCANFD_CFCC_CFTML(cftml) | RCANFD_CFCC_CFM(cfm) |
RCANFD_CFCC_CFIM | RCANFD_CFCC_CFDC(cfdc) |
RCANFD_CFCC_CFPLS(cfpls) | RCANFD_CFCC_CFTXIE);
rcar_canfd_write(gpriv->base, RCANFD_CFCC(ch, RCANFD_CFFIFO_IDX), cfg);
if (gpriv->fdmode)
rcar_canfd_write(gpriv->base,
RCANFD_F_CFFDCSTS(ch, RCANFD_CFFIFO_IDX), 0);
}
static void rcar_canfd_enable_global_interrupts(struct rcar_canfd_global *gpriv)
{
u32 ctr;
rcar_canfd_write(gpriv->base, RCANFD_GERFL, 0);
ctr = RCANFD_GCTR_MEIE;
if (gpriv->fdmode)
ctr |= RCANFD_GCTR_CFMPOFIE;
rcar_canfd_set_bit(gpriv->base, RCANFD_GCTR, ctr);
}
static void rcar_canfd_disable_global_interrupts(struct rcar_canfd_global
*gpriv)
{
rcar_canfd_write(gpriv->base, RCANFD_GCTR, 0);
rcar_canfd_write(gpriv->base, RCANFD_GERFL, 0);
}
static void rcar_canfd_enable_channel_interrupts(struct rcar_canfd_channel
*priv)
{
u32 ctr, ch = priv->channel;
rcar_canfd_write(priv->base, RCANFD_CERFL(ch), 0);
ctr = (RCANFD_CCTR_TAIE |
RCANFD_CCTR_ALIE | RCANFD_CCTR_BLIE |
RCANFD_CCTR_OLIE | RCANFD_CCTR_BORIE |
RCANFD_CCTR_BOEIE | RCANFD_CCTR_EPIE |
RCANFD_CCTR_EWIE | RCANFD_CCTR_BEIE);
rcar_canfd_set_bit(priv->base, RCANFD_CCTR(ch), ctr);
}
static void rcar_canfd_disable_channel_interrupts(struct rcar_canfd_channel
*priv)
{
u32 ctr, ch = priv->channel;
ctr = (RCANFD_CCTR_TAIE |
RCANFD_CCTR_ALIE | RCANFD_CCTR_BLIE |
RCANFD_CCTR_OLIE | RCANFD_CCTR_BORIE |
RCANFD_CCTR_BOEIE | RCANFD_CCTR_EPIE |
RCANFD_CCTR_EWIE | RCANFD_CCTR_BEIE);
rcar_canfd_clear_bit(priv->base, RCANFD_CCTR(ch), ctr);
rcar_canfd_write(priv->base, RCANFD_CERFL(ch), 0);
}
static void rcar_canfd_global_error(struct net_device *ndev)
{
struct rcar_canfd_channel *priv = netdev_priv(ndev);
struct rcar_canfd_global *gpriv = priv->gpriv;
struct net_device_stats *stats = &ndev->stats;
u32 ch = priv->channel;
u32 gerfl, sts;
u32 ridx = ch + RCANFD_RFFIFO_IDX;
gerfl = rcar_canfd_read(priv->base, RCANFD_GERFL);
if ((gerfl & RCANFD_GERFL_EEF0) && (ch == 0)) {
netdev_dbg(ndev, "Ch0: ECC Error flag\n");
stats->tx_dropped++;
}
if ((gerfl & RCANFD_GERFL_EEF1) && (ch == 1)) {
netdev_dbg(ndev, "Ch1: ECC Error flag\n");
stats->tx_dropped++;
}
if (gerfl & RCANFD_GERFL_MES) {
sts = rcar_canfd_read(priv->base,
RCANFD_CFSTS(ch, RCANFD_CFFIFO_IDX));
if (sts & RCANFD_CFSTS_CFMLT) {
netdev_dbg(ndev, "Tx Message Lost flag\n");
stats->tx_dropped++;
rcar_canfd_write(priv->base,
RCANFD_CFSTS(ch, RCANFD_CFFIFO_IDX),
sts & ~RCANFD_CFSTS_CFMLT);
}
sts = rcar_canfd_read(priv->base, RCANFD_RFSTS(ridx));
if (sts & RCANFD_RFSTS_RFMLT) {
netdev_dbg(ndev, "Rx Message Lost flag\n");
stats->rx_dropped++;
rcar_canfd_write(priv->base, RCANFD_RFSTS(ridx),
sts & ~RCANFD_RFSTS_RFMLT);
}
}
if (gpriv->fdmode && gerfl & RCANFD_GERFL_CMPOF) {
netdev_dbg(ndev, "global payload overflow interrupt\n");
}
rcar_canfd_write(priv->base, RCANFD_GERFL, 0);
}
static void rcar_canfd_error(struct net_device *ndev, u32 cerfl,
u16 txerr, u16 rxerr)
{
struct rcar_canfd_channel *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
struct can_frame *cf;
struct sk_buff *skb;
u32 ch = priv->channel;
netdev_dbg(ndev, "ch erfl %x txerr %u rxerr %u\n", cerfl, txerr, rxerr);
skb = alloc_can_err_skb(ndev, &cf);
if (!skb) {
stats->rx_dropped++;
return;
}
if (cerfl & RCANFD_CERFL_BEF) {
netdev_dbg(ndev, "Bus error\n");
cf->can_id |= CAN_ERR_BUSERROR | CAN_ERR_PROT;
cf->data[2] = CAN_ERR_PROT_UNSPEC;
priv->can.can_stats.bus_error++;
}
if (cerfl & RCANFD_CERFL_ADERR) {
netdev_dbg(ndev, "ACK Delimiter Error\n");
stats->tx_errors++;
cf->data[3] |= CAN_ERR_PROT_LOC_ACK_DEL;
}
if (cerfl & RCANFD_CERFL_B0ERR) {
netdev_dbg(ndev, "Bit Error (dominant)\n");
stats->tx_errors++;
cf->data[2] |= CAN_ERR_PROT_BIT0;
}
if (cerfl & RCANFD_CERFL_B1ERR) {
netdev_dbg(ndev, "Bit Error (recessive)\n");
stats->tx_errors++;
cf->data[2] |= CAN_ERR_PROT_BIT1;
}
if (cerfl & RCANFD_CERFL_CERR) {
netdev_dbg(ndev, "CRC Error\n");
stats->rx_errors++;
cf->data[3] |= CAN_ERR_PROT_LOC_CRC_SEQ;
}
if (cerfl & RCANFD_CERFL_AERR) {
netdev_dbg(ndev, "ACK Error\n");
stats->tx_errors++;
cf->can_id |= CAN_ERR_ACK;
cf->data[3] |= CAN_ERR_PROT_LOC_ACK;
}
if (cerfl & RCANFD_CERFL_FERR) {
netdev_dbg(ndev, "Form Error\n");
stats->rx_errors++;
cf->data[2] |= CAN_ERR_PROT_FORM;
}
if (cerfl & RCANFD_CERFL_SERR) {
netdev_dbg(ndev, "Stuff Error\n");
stats->rx_errors++;
cf->data[2] |= CAN_ERR_PROT_STUFF;
}
if (cerfl & RCANFD_CERFL_ALF) {
netdev_dbg(ndev, "Arbitration lost Error\n");
priv->can.can_stats.arbitration_lost++;
cf->can_id |= CAN_ERR_LOSTARB;
cf->data[0] |= CAN_ERR_LOSTARB_UNSPEC;
}
if (cerfl & RCANFD_CERFL_BLF) {
netdev_dbg(ndev, "Bus Lock Error\n");
stats->rx_errors++;
cf->can_id |= CAN_ERR_BUSERROR;
}
if (cerfl & RCANFD_CERFL_EWF) {
netdev_dbg(ndev, "Error warning interrupt\n");
priv->can.state = CAN_STATE_ERROR_WARNING;
priv->can.can_stats.error_warning++;
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = txerr > rxerr ? CAN_ERR_CRTL_TX_WARNING :
CAN_ERR_CRTL_RX_WARNING;
cf->data[6] = txerr;
cf->data[7] = rxerr;
}
if (cerfl & RCANFD_CERFL_EPF) {
netdev_dbg(ndev, "Error passive interrupt\n");
priv->can.state = CAN_STATE_ERROR_PASSIVE;
priv->can.can_stats.error_passive++;
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = txerr > rxerr ? CAN_ERR_CRTL_TX_PASSIVE :
CAN_ERR_CRTL_RX_PASSIVE;
cf->data[6] = txerr;
cf->data[7] = rxerr;
}
if (cerfl & RCANFD_CERFL_BOEF) {
netdev_dbg(ndev, "Bus-off entry interrupt\n");
rcar_canfd_tx_failure_cleanup(ndev);
priv->can.state = CAN_STATE_BUS_OFF;
priv->can.can_stats.bus_off++;
can_bus_off(ndev);
cf->can_id |= CAN_ERR_BUSOFF;
}
if (cerfl & RCANFD_CERFL_OVLF) {
netdev_dbg(ndev,
"Overload Frame Transmission error interrupt\n");
stats->tx_errors++;
cf->can_id |= CAN_ERR_PROT;
cf->data[2] |= CAN_ERR_PROT_OVERLOAD;
}
rcar_canfd_write(priv->base, RCANFD_CERFL(ch),
RCANFD_CERFL_ERR(~cerfl));
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
}
static void rcar_canfd_tx_done(struct net_device *ndev)
{
struct rcar_canfd_channel *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
u32 sts;
unsigned long flags;
u32 ch = priv->channel;
do {
u8 unsent, sent;
sent = priv->tx_tail % RCANFD_FIFO_DEPTH;
stats->tx_packets++;
stats->tx_bytes += priv->tx_len[sent];
priv->tx_len[sent] = 0;
can_get_echo_skb(ndev, sent);
spin_lock_irqsave(&priv->tx_lock, flags);
priv->tx_tail++;
sts = rcar_canfd_read(priv->base,
RCANFD_CFSTS(ch, RCANFD_CFFIFO_IDX));
unsent = RCANFD_CFSTS_CFMC(sts);
if (unsent != RCANFD_FIFO_DEPTH)
netif_wake_queue(ndev);
if (priv->tx_head - priv->tx_tail <= unsent) {
spin_unlock_irqrestore(&priv->tx_lock, flags);
break;
}
spin_unlock_irqrestore(&priv->tx_lock, flags);
} while (1);
rcar_canfd_write(priv->base, RCANFD_CFSTS(ch, RCANFD_CFFIFO_IDX),
sts & ~RCANFD_CFSTS_CFTXIF);
can_led_event(ndev, CAN_LED_EVENT_TX);
}
static irqreturn_t rcar_canfd_global_interrupt(int irq, void *dev_id)
{
struct rcar_canfd_global *gpriv = dev_id;
struct net_device *ndev;
struct rcar_canfd_channel *priv;
u32 sts, gerfl;
u32 ch, ridx;
for_each_set_bit(ch, &gpriv->channels_mask, RCANFD_NUM_CHANNELS) {
priv = gpriv->ch[ch];
ndev = priv->ndev;
ridx = ch + RCANFD_RFFIFO_IDX;
gerfl = rcar_canfd_read(priv->base, RCANFD_GERFL);
if (unlikely(RCANFD_GERFL_ERR(gpriv, gerfl)))
rcar_canfd_global_error(ndev);
sts = rcar_canfd_read(priv->base, RCANFD_RFSTS(ridx));
if (likely(sts & RCANFD_RFSTS_RFIF)) {
if (napi_schedule_prep(&priv->napi)) {
rcar_canfd_clear_bit(priv->base,
RCANFD_RFCC(ridx),
RCANFD_RFCC_RFIE);
__napi_schedule(&priv->napi);
}
}
}
return IRQ_HANDLED;
}
static void rcar_canfd_state_change(struct net_device *ndev,
u16 txerr, u16 rxerr)
{
struct rcar_canfd_channel *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
enum can_state rx_state, tx_state, state = priv->can.state;
struct can_frame *cf;
struct sk_buff *skb;
if (txerr < 96 && rxerr < 96)
state = CAN_STATE_ERROR_ACTIVE;
else if (txerr < 128 && rxerr < 128)
state = CAN_STATE_ERROR_WARNING;
if (state != priv->can.state) {
netdev_dbg(ndev, "state: new %d, old %d: txerr %u, rxerr %u\n",
state, priv->can.state, txerr, rxerr);
skb = alloc_can_err_skb(ndev, &cf);
if (!skb) {
stats->rx_dropped++;
return;
}
tx_state = txerr >= rxerr ? state : 0;
rx_state = txerr <= rxerr ? state : 0;
can_change_state(ndev, cf, tx_state, rx_state);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
}
}
static irqreturn_t rcar_canfd_channel_interrupt(int irq, void *dev_id)
{
struct rcar_canfd_global *gpriv = dev_id;
struct net_device *ndev;
struct rcar_canfd_channel *priv;
u32 sts, ch, cerfl;
u16 txerr, rxerr;
for_each_set_bit(ch, &gpriv->channels_mask, RCANFD_NUM_CHANNELS) {
priv = gpriv->ch[ch];
ndev = priv->ndev;
cerfl = rcar_canfd_read(priv->base, RCANFD_CERFL(ch));
sts = rcar_canfd_read(priv->base, RCANFD_CSTS(ch));
txerr = RCANFD_CSTS_TECCNT(sts);
rxerr = RCANFD_CSTS_RECCNT(sts);
if (unlikely(RCANFD_CERFL_ERR(cerfl)))
rcar_canfd_error(ndev, cerfl, txerr, rxerr);
if (unlikely((priv->can.state != CAN_STATE_ERROR_ACTIVE) &&
(priv->can.state != CAN_STATE_BUS_OFF)))
rcar_canfd_state_change(ndev, txerr, rxerr);
sts = rcar_canfd_read(priv->base,
RCANFD_CFSTS(ch, RCANFD_CFFIFO_IDX));
if (likely(sts & RCANFD_CFSTS_CFTXIF))
rcar_canfd_tx_done(ndev);
}
return IRQ_HANDLED;
}
static void rcar_canfd_set_bittiming(struct net_device *dev)
{
struct rcar_canfd_channel *priv = netdev_priv(dev);
const struct can_bittiming *bt = &priv->can.bittiming;
const struct can_bittiming *dbt = &priv->can.data_bittiming;
u16 brp, sjw, tseg1, tseg2;
u32 cfg;
u32 ch = priv->channel;
brp = bt->brp - 1;
sjw = bt->sjw - 1;
tseg1 = bt->prop_seg + bt->phase_seg1 - 1;
tseg2 = bt->phase_seg2 - 1;
if (priv->can.ctrlmode & CAN_CTRLMODE_FD) {
cfg = (RCANFD_NCFG_NTSEG1(tseg1) | RCANFD_NCFG_NBRP(brp) |
RCANFD_NCFG_NSJW(sjw) | RCANFD_NCFG_NTSEG2(tseg2));
rcar_canfd_write(priv->base, RCANFD_CCFG(ch), cfg);
netdev_dbg(priv->ndev, "nrate: brp %u, sjw %u, tseg1 %u, tseg2 %u\n",
brp, sjw, tseg1, tseg2);
brp = dbt->brp - 1;
sjw = dbt->sjw - 1;
tseg1 = dbt->prop_seg + dbt->phase_seg1 - 1;
tseg2 = dbt->phase_seg2 - 1;
cfg = (RCANFD_DCFG_DTSEG1(tseg1) | RCANFD_DCFG_DBRP(brp) |
RCANFD_DCFG_DSJW(sjw) | RCANFD_DCFG_DTSEG2(tseg2));
rcar_canfd_write(priv->base, RCANFD_F_DCFG(ch), cfg);
netdev_dbg(priv->ndev, "drate: brp %u, sjw %u, tseg1 %u, tseg2 %u\n",
brp, sjw, tseg1, tseg2);
} else {
cfg = (RCANFD_CFG_TSEG1(tseg1) | RCANFD_CFG_BRP(brp) |
RCANFD_CFG_SJW(sjw) | RCANFD_CFG_TSEG2(tseg2));
rcar_canfd_write(priv->base, RCANFD_CCFG(ch), cfg);
netdev_dbg(priv->ndev,
"rate: brp %u, sjw %u, tseg1 %u, tseg2 %u\n",
brp, sjw, tseg1, tseg2);
}
}
static int rcar_canfd_start(struct net_device *ndev)
{
struct rcar_canfd_channel *priv = netdev_priv(ndev);
int err = -EOPNOTSUPP;
u32 sts, ch = priv->channel;
u32 ridx = ch + RCANFD_RFFIFO_IDX;
rcar_canfd_set_bittiming(ndev);
rcar_canfd_enable_channel_interrupts(priv);
rcar_canfd_update_bit(priv->base, RCANFD_CCTR(ch),
RCANFD_CCTR_CHMDC_MASK, RCANFD_CCTR_CHDMC_COPM);
err = readl_poll_timeout((priv->base + RCANFD_CSTS(ch)), sts,
(sts & RCANFD_CSTS_COMSTS), 2, 500000);
if (err) {
netdev_err(ndev, "channel %u communication state failed\n", ch);
goto fail_mode_change;
}
rcar_canfd_set_bit(priv->base, RCANFD_CFCC(ch, RCANFD_CFFIFO_IDX),
RCANFD_CFCC_CFE);
rcar_canfd_set_bit(priv->base, RCANFD_RFCC(ridx), RCANFD_RFCC_RFE);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
return 0;
fail_mode_change:
rcar_canfd_disable_channel_interrupts(priv);
return err;
}
static int rcar_canfd_open(struct net_device *ndev)
{
struct rcar_canfd_channel *priv = netdev_priv(ndev);
struct rcar_canfd_global *gpriv = priv->gpriv;
int err;
err = clk_prepare_enable(gpriv->can_clk);
if (err) {
netdev_err(ndev, "failed to enable CAN clock, error %d\n", err);
goto out_clock;
}
err = open_candev(ndev);
if (err) {
netdev_err(ndev, "open_candev() failed, error %d\n", err);
goto out_can_clock;
}
napi_enable(&priv->napi);
err = rcar_canfd_start(ndev);
if (err)
goto out_close;
netif_start_queue(ndev);
can_led_event(ndev, CAN_LED_EVENT_OPEN);
return 0;
out_close:
napi_disable(&priv->napi);
close_candev(ndev);
out_can_clock:
clk_disable_unprepare(gpriv->can_clk);
out_clock:
return err;
}
static void rcar_canfd_stop(struct net_device *ndev)
{
struct rcar_canfd_channel *priv = netdev_priv(ndev);
int err;
u32 sts, ch = priv->channel;
u32 ridx = ch + RCANFD_RFFIFO_IDX;
rcar_canfd_update_bit(priv->base, RCANFD_CCTR(ch),
RCANFD_CCTR_CHMDC_MASK, RCANFD_CCTR_CHDMC_CRESET);
err = readl_poll_timeout((priv->base + RCANFD_CSTS(ch)), sts,
(sts & RCANFD_CSTS_CRSTSTS), 2, 500000);
if (err)
netdev_err(ndev, "channel %u reset failed\n", ch);
rcar_canfd_disable_channel_interrupts(priv);
rcar_canfd_clear_bit(priv->base, RCANFD_CFCC(ch, RCANFD_CFFIFO_IDX),
RCANFD_CFCC_CFE);
rcar_canfd_clear_bit(priv->base, RCANFD_RFCC(ridx), RCANFD_RFCC_RFE);
priv->can.state = CAN_STATE_STOPPED;
}
static int rcar_canfd_close(struct net_device *ndev)
{
struct rcar_canfd_channel *priv = netdev_priv(ndev);
struct rcar_canfd_global *gpriv = priv->gpriv;
netif_stop_queue(ndev);
rcar_canfd_stop(ndev);
napi_disable(&priv->napi);
clk_disable_unprepare(gpriv->can_clk);
close_candev(ndev);
can_led_event(ndev, CAN_LED_EVENT_STOP);
return 0;
}
static netdev_tx_t rcar_canfd_start_xmit(struct sk_buff *skb,
struct net_device *ndev)
{
struct rcar_canfd_channel *priv = netdev_priv(ndev);
struct canfd_frame *cf = (struct canfd_frame *)skb->data;
u32 sts = 0, id, dlc;
unsigned long flags;
u32 ch = priv->channel;
if (can_dropped_invalid_skb(ndev, skb))
return NETDEV_TX_OK;
if (cf->can_id & CAN_EFF_FLAG) {
id = cf->can_id & CAN_EFF_MASK;
id |= RCANFD_CFID_CFIDE;
} else {
id = cf->can_id & CAN_SFF_MASK;
}
if (cf->can_id & CAN_RTR_FLAG)
id |= RCANFD_CFID_CFRTR;
dlc = RCANFD_CFPTR_CFDLC(can_len2dlc(cf->len));
if (priv->can.ctrlmode & CAN_CTRLMODE_FD) {
rcar_canfd_write(priv->base,
RCANFD_F_CFID(ch, RCANFD_CFFIFO_IDX), id);
rcar_canfd_write(priv->base,
RCANFD_F_CFPTR(ch, RCANFD_CFFIFO_IDX), dlc);
if (can_is_canfd_skb(skb)) {
sts |= RCANFD_CFFDCSTS_CFFDF;
if (cf->flags & CANFD_BRS)
sts |= RCANFD_CFFDCSTS_CFBRS;
if (priv->can.state == CAN_STATE_ERROR_PASSIVE)
sts |= RCANFD_CFFDCSTS_CFESI;
}
rcar_canfd_write(priv->base,
RCANFD_F_CFFDCSTS(ch, RCANFD_CFFIFO_IDX), sts);
rcar_canfd_put_data(priv, cf,
RCANFD_F_CFDF(ch, RCANFD_CFFIFO_IDX, 0));
} else {
rcar_canfd_write(priv->base,
RCANFD_C_CFID(ch, RCANFD_CFFIFO_IDX), id);
rcar_canfd_write(priv->base,
RCANFD_C_CFPTR(ch, RCANFD_CFFIFO_IDX), dlc);
rcar_canfd_put_data(priv, cf,
RCANFD_C_CFDF(ch, RCANFD_CFFIFO_IDX, 0));
}
priv->tx_len[priv->tx_head % RCANFD_FIFO_DEPTH] = cf->len;
can_put_echo_skb(skb, ndev, priv->tx_head % RCANFD_FIFO_DEPTH);
spin_lock_irqsave(&priv->tx_lock, flags);
priv->tx_head++;
if (priv->tx_head - priv->tx_tail >= RCANFD_FIFO_DEPTH)
netif_stop_queue(ndev);
rcar_canfd_write(priv->base,
RCANFD_CFPCTR(ch, RCANFD_CFFIFO_IDX), 0xff);
spin_unlock_irqrestore(&priv->tx_lock, flags);
return NETDEV_TX_OK;
}
static void rcar_canfd_rx_pkt(struct rcar_canfd_channel *priv)
{
struct net_device_stats *stats = &priv->ndev->stats;
struct canfd_frame *cf;
struct sk_buff *skb;
u32 sts = 0, id, dlc;
u32 ch = priv->channel;
u32 ridx = ch + RCANFD_RFFIFO_IDX;
if (priv->can.ctrlmode & CAN_CTRLMODE_FD) {
id = rcar_canfd_read(priv->base, RCANFD_F_RFID(ridx));
dlc = rcar_canfd_read(priv->base, RCANFD_F_RFPTR(ridx));
sts = rcar_canfd_read(priv->base, RCANFD_F_RFFDSTS(ridx));
if (sts & RCANFD_RFFDSTS_RFFDF)
skb = alloc_canfd_skb(priv->ndev, &cf);
else
skb = alloc_can_skb(priv->ndev,
(struct can_frame **)&cf);
} else {
id = rcar_canfd_read(priv->base, RCANFD_C_RFID(ridx));
dlc = rcar_canfd_read(priv->base, RCANFD_C_RFPTR(ridx));
skb = alloc_can_skb(priv->ndev, (struct can_frame **)&cf);
}
if (!skb) {
stats->rx_dropped++;
return;
}
if (id & RCANFD_RFID_RFIDE)
cf->can_id = (id & CAN_EFF_MASK) | CAN_EFF_FLAG;
else
cf->can_id = id & CAN_SFF_MASK;
if (priv->can.ctrlmode & CAN_CTRLMODE_FD) {
if (sts & RCANFD_RFFDSTS_RFFDF)
cf->len = can_dlc2len(RCANFD_RFPTR_RFDLC(dlc));
else
cf->len = get_can_dlc(RCANFD_RFPTR_RFDLC(dlc));
if (sts & RCANFD_RFFDSTS_RFESI) {
cf->flags |= CANFD_ESI;
netdev_dbg(priv->ndev, "ESI Error\n");
}
if (!(sts & RCANFD_RFFDSTS_RFFDF) && (id & RCANFD_RFID_RFRTR)) {
cf->can_id |= CAN_RTR_FLAG;
} else {
if (sts & RCANFD_RFFDSTS_RFBRS)
cf->flags |= CANFD_BRS;
rcar_canfd_get_data(priv, cf, RCANFD_F_RFDF(ridx, 0));
}
} else {
cf->len = get_can_dlc(RCANFD_RFPTR_RFDLC(dlc));
if (id & RCANFD_RFID_RFRTR)
cf->can_id |= CAN_RTR_FLAG;
else
rcar_canfd_get_data(priv, cf, RCANFD_C_RFDF(ridx, 0));
}
rcar_canfd_write(priv->base, RCANFD_RFPCTR(ridx), 0xff);
can_led_event(priv->ndev, CAN_LED_EVENT_RX);
stats->rx_bytes += cf->len;
stats->rx_packets++;
netif_receive_skb(skb);
}
static int rcar_canfd_rx_poll(struct napi_struct *napi, int quota)
{
struct rcar_canfd_channel *priv =
container_of(napi, struct rcar_canfd_channel, napi);
int num_pkts;
u32 sts;
u32 ch = priv->channel;
u32 ridx = ch + RCANFD_RFFIFO_IDX;
for (num_pkts = 0; num_pkts < quota; num_pkts++) {
sts = rcar_canfd_read(priv->base, RCANFD_RFSTS(ridx));
if (sts & RCANFD_RFSTS_RFEMP)
break;
rcar_canfd_rx_pkt(priv);
if (sts & RCANFD_RFSTS_RFIF)
rcar_canfd_write(priv->base, RCANFD_RFSTS(ridx),
sts & ~RCANFD_RFSTS_RFIF);
}
if (num_pkts < quota) {
napi_complete_done(napi, num_pkts);
rcar_canfd_set_bit(priv->base, RCANFD_RFCC(ridx),
RCANFD_RFCC_RFIE);
}
return num_pkts;
}
static int rcar_canfd_do_set_mode(struct net_device *ndev, enum can_mode mode)
{
int err;
switch (mode) {
case CAN_MODE_START:
err = rcar_canfd_start(ndev);
if (err)
return err;
netif_wake_queue(ndev);
return 0;
default:
return -EOPNOTSUPP;
}
}
static int rcar_canfd_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
struct rcar_canfd_channel *priv = netdev_priv(dev);
u32 val, ch = priv->channel;
val = rcar_canfd_read(priv->base, RCANFD_CSTS(ch));
bec->txerr = RCANFD_CSTS_TECCNT(val);
bec->rxerr = RCANFD_CSTS_RECCNT(val);
return 0;
}
static int rcar_canfd_channel_probe(struct rcar_canfd_global *gpriv, u32 ch,
u32 fcan_freq)
{
struct platform_device *pdev = gpriv->pdev;
struct rcar_canfd_channel *priv;
struct net_device *ndev;
int err = -ENODEV;
ndev = alloc_candev(sizeof(*priv), RCANFD_FIFO_DEPTH);
if (!ndev) {
dev_err(&pdev->dev, "alloc_candev() failed\n");
err = -ENOMEM;
goto fail;
}
priv = netdev_priv(ndev);
ndev->netdev_ops = &rcar_canfd_netdev_ops;
ndev->flags |= IFF_ECHO;
priv->ndev = ndev;
priv->base = gpriv->base;
priv->channel = ch;
priv->can.clock.freq = fcan_freq;
dev_info(&pdev->dev, "can_clk rate is %u\n", priv->can.clock.freq);
if (gpriv->fdmode) {
priv->can.bittiming_const = &rcar_canfd_nom_bittiming_const;
priv->can.data_bittiming_const =
&rcar_canfd_data_bittiming_const;
can_set_static_ctrlmode(ndev, CAN_CTRLMODE_FD);
priv->can.ctrlmode_supported = CAN_CTRLMODE_BERR_REPORTING;
} else {
priv->can.bittiming_const = &rcar_canfd_bittiming_const;
priv->can.ctrlmode_supported = CAN_CTRLMODE_BERR_REPORTING;
}
priv->can.do_set_mode = rcar_canfd_do_set_mode;
priv->can.do_get_berr_counter = rcar_canfd_get_berr_counter;
priv->gpriv = gpriv;
SET_NETDEV_DEV(ndev, &pdev->dev);
netif_napi_add(ndev, &priv->napi, rcar_canfd_rx_poll,
RCANFD_NAPI_WEIGHT);
err = register_candev(ndev);
if (err) {
dev_err(&pdev->dev,
"register_candev() failed, error %d\n", err);
goto fail_candev;
}
spin_lock_init(&priv->tx_lock);
devm_can_led_init(ndev);
gpriv->ch[priv->channel] = priv;
dev_info(&pdev->dev, "device registered (channel %u)\n", priv->channel);
return 0;
fail_candev:
netif_napi_del(&priv->napi);
free_candev(ndev);
fail:
return err;
}
static void rcar_canfd_channel_remove(struct rcar_canfd_global *gpriv, u32 ch)
{
struct rcar_canfd_channel *priv = gpriv->ch[ch];
if (priv) {
unregister_candev(priv->ndev);
netif_napi_del(&priv->napi);
free_candev(priv->ndev);
}
}
static int rcar_canfd_probe(struct platform_device *pdev)
{
struct resource *mem;
void __iomem *addr;
u32 sts, ch, fcan_freq;
struct rcar_canfd_global *gpriv;
struct device_node *of_child;
unsigned long channels_mask = 0;
int err, ch_irq, g_irq;
bool fdmode = true;
if (of_property_read_bool(pdev->dev.of_node, "renesas,no-can-fd"))
fdmode = false;
of_child = of_get_child_by_name(pdev->dev.of_node, "channel0");
if (of_child && of_device_is_available(of_child))
channels_mask |= BIT(0);
of_child = of_get_child_by_name(pdev->dev.of_node, "channel1");
if (of_child && of_device_is_available(of_child))
channels_mask |= BIT(1);
ch_irq = platform_get_irq(pdev, 0);
if (ch_irq < 0) {
dev_err(&pdev->dev, "no Channel IRQ resource\n");
err = ch_irq;
goto fail_dev;
}
g_irq = platform_get_irq(pdev, 1);
if (g_irq < 0) {
dev_err(&pdev->dev, "no Global IRQ resource\n");
err = g_irq;
goto fail_dev;
}
gpriv = devm_kzalloc(&pdev->dev, sizeof(*gpriv), GFP_KERNEL);
if (!gpriv) {
err = -ENOMEM;
goto fail_dev;
}
gpriv->pdev = pdev;
gpriv->channels_mask = channels_mask;
gpriv->fdmode = fdmode;
gpriv->clkp = devm_clk_get(&pdev->dev, "fck");
if (IS_ERR(gpriv->clkp)) {
err = PTR_ERR(gpriv->clkp);
dev_err(&pdev->dev, "cannot get peripheral clock, error %d\n",
err);
goto fail_dev;
}
gpriv->can_clk = devm_clk_get(&pdev->dev, "can_clk");
if (IS_ERR(gpriv->can_clk) || (clk_get_rate(gpriv->can_clk) == 0)) {
gpriv->can_clk = devm_clk_get(&pdev->dev, "canfd");
if (IS_ERR(gpriv->can_clk)) {
err = PTR_ERR(gpriv->can_clk);
dev_err(&pdev->dev,
"cannot get canfd clock, error %d\n", err);
goto fail_dev;
}
gpriv->fcan = RCANFD_CANFDCLK;
} else {
gpriv->fcan = RCANFD_EXTCLK;
}
fcan_freq = clk_get_rate(gpriv->can_clk);
if (gpriv->fcan == RCANFD_CANFDCLK)
fcan_freq /= 2;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
addr = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(addr)) {
err = PTR_ERR(addr);
goto fail_dev;
}
gpriv->base = addr;
err = devm_request_irq(&pdev->dev, ch_irq,
rcar_canfd_channel_interrupt, 0,
"canfd.chn", gpriv);
if (err) {
dev_err(&pdev->dev, "devm_request_irq(%d) failed, error %d\n",
ch_irq, err);
goto fail_dev;
}
err = devm_request_irq(&pdev->dev, g_irq,
rcar_canfd_global_interrupt, 0,
"canfd.gbl", gpriv);
if (err) {
dev_err(&pdev->dev, "devm_request_irq(%d) failed, error %d\n",
g_irq, err);
goto fail_dev;
}
err = clk_prepare_enable(gpriv->clkp);
if (err) {
dev_err(&pdev->dev,
"failed to enable peripheral clock, error %d\n", err);
goto fail_dev;
}
err = rcar_canfd_reset_controller(gpriv);
if (err) {
dev_err(&pdev->dev, "reset controller failed\n");
goto fail_clk;
}
rcar_canfd_configure_controller(gpriv);
for_each_set_bit(ch, &gpriv->channels_mask, RCANFD_NUM_CHANNELS) {
rcar_canfd_configure_rx(gpriv, ch);
rcar_canfd_configure_tx(gpriv, ch);
rcar_canfd_configure_afl_rules(gpriv, ch);
}
rcar_canfd_enable_global_interrupts(gpriv);
rcar_canfd_update_bit(gpriv->base, RCANFD_GCTR, RCANFD_GCTR_GMDC_MASK,
RCANFD_GCTR_GMDC_GOPM);
err = readl_poll_timeout((gpriv->base + RCANFD_GSTS), sts,
!(sts & RCANFD_GSTS_GNOPM), 2, 500000);
if (err) {
dev_err(&pdev->dev, "global operational mode failed\n");
goto fail_mode;
}
for_each_set_bit(ch, &gpriv->channels_mask, RCANFD_NUM_CHANNELS) {
err = rcar_canfd_channel_probe(gpriv, ch, fcan_freq);
if (err)
goto fail_channel;
}
platform_set_drvdata(pdev, gpriv);
dev_info(&pdev->dev, "global operational state (clk %d, fdmode %d)\n",
gpriv->fcan, gpriv->fdmode);
return 0;
fail_channel:
for_each_set_bit(ch, &gpriv->channels_mask, RCANFD_NUM_CHANNELS)
rcar_canfd_channel_remove(gpriv, ch);
fail_mode:
rcar_canfd_disable_global_interrupts(gpriv);
fail_clk:
clk_disable_unprepare(gpriv->clkp);
fail_dev:
return err;
}
static int rcar_canfd_remove(struct platform_device *pdev)
{
struct rcar_canfd_global *gpriv = platform_get_drvdata(pdev);
u32 ch;
rcar_canfd_reset_controller(gpriv);
rcar_canfd_disable_global_interrupts(gpriv);
for_each_set_bit(ch, &gpriv->channels_mask, RCANFD_NUM_CHANNELS) {
rcar_canfd_disable_channel_interrupts(gpriv->ch[ch]);
rcar_canfd_channel_remove(gpriv, ch);
}
rcar_canfd_set_bit(gpriv->base, RCANFD_GCTR, RCANFD_GCTR_GSLPR);
clk_disable_unprepare(gpriv->clkp);
return 0;
}
static int __maybe_unused rcar_canfd_suspend(struct device *dev)
{
return 0;
}
static int __maybe_unused rcar_canfd_resume(struct device *dev)
{
return 0;
}
