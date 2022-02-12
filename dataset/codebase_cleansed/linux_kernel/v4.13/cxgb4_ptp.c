bool cxgb4_ptp_is_ptp_tx(struct sk_buff *skb)
{
struct udphdr *uh;
uh = udp_hdr(skb);
return skb->len >= PTP_MIN_LENGTH &&
skb->len <= PTP_IN_TRANSMIT_PACKET_MAXNUM &&
likely(skb->protocol == htons(ETH_P_IP)) &&
ip_hdr(skb)->protocol == IPPROTO_UDP &&
uh->dest == htons(PTP_EVENT_PORT);
}
bool is_ptp_enabled(struct sk_buff *skb, struct net_device *dev)
{
struct port_info *pi;
pi = netdev_priv(dev);
return (pi->ptp_enable && cxgb4_xmit_with_hwtstamp(skb) &&
cxgb4_ptp_is_ptp_tx(skb));
}
bool cxgb4_ptp_is_ptp_rx(struct sk_buff *skb)
{
struct udphdr *uh = (struct udphdr *)(skb->data + ETH_HLEN +
IPV4_HLEN(skb->data));
return uh->dest == htons(PTP_EVENT_PORT) &&
uh->source == htons(PTP_EVENT_PORT);
}
void cxgb4_ptp_read_hwstamp(struct adapter *adapter, struct port_info *pi)
{
struct skb_shared_hwtstamps *skb_ts = NULL;
u64 tx_ts;
skb_ts = skb_hwtstamps(adapter->ptp_tx_skb);
tx_ts = t4_read_reg(adapter,
T5_PORT_REG(pi->port_id, MAC_PORT_TX_TS_VAL_LO));
tx_ts |= (u64)t4_read_reg(adapter,
T5_PORT_REG(pi->port_id,
MAC_PORT_TX_TS_VAL_HI)) << 32;
skb_ts->hwtstamp = ns_to_ktime(tx_ts);
skb_tstamp_tx(adapter->ptp_tx_skb, skb_ts);
dev_kfree_skb_any(adapter->ptp_tx_skb);
spin_lock(&adapter->ptp_lock);
adapter->ptp_tx_skb = NULL;
spin_unlock(&adapter->ptp_lock);
}
int cxgb4_ptprx_timestamping(struct port_info *pi, u8 port, u16 mode)
{
struct adapter *adapter = pi->adapter;
struct fw_ptp_cmd c;
int err;
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PTP_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_PTP_CMD_PORTID_V(port));
c.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(sizeof(c) / 16));
c.u.init.sc = FW_PTP_SC_RXTIME_STAMP;
c.u.init.mode = cpu_to_be16(mode);
err = t4_wr_mbox(adapter, adapter->mbox, &c, sizeof(c), NULL);
if (err < 0)
dev_err(adapter->pdev_dev,
"PTP: %s error %d\n", __func__, -err);
return err;
}
int cxgb4_ptp_txtype(struct adapter *adapter, u8 port)
{
struct fw_ptp_cmd c;
int err;
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PTP_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_PTP_CMD_PORTID_V(port));
c.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(sizeof(c) / 16));
c.u.init.sc = FW_PTP_SC_TX_TYPE;
c.u.init.mode = cpu_to_be16(PTP_TS_NONE);
err = t4_wr_mbox(adapter, adapter->mbox, &c, sizeof(c), NULL);
if (err < 0)
dev_err(adapter->pdev_dev,
"PTP: %s error %d\n", __func__, -err);
return err;
}
int cxgb4_ptp_redirect_rx_packet(struct adapter *adapter, struct port_info *pi)
{
struct sge *s = &adapter->sge;
struct sge_eth_rxq *receive_q = &s->ethrxq[pi->first_qset];
struct fw_ptp_cmd c;
int err;
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PTP_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_PTP_CMD_PORTID_V(pi->port_id));
c.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(sizeof(c) / 16));
c.u.init.sc = FW_PTP_SC_RDRX_TYPE;
c.u.init.txchan = pi->tx_chan;
c.u.init.absid = cpu_to_be16(receive_q->rspq.abs_id);
err = t4_wr_mbox(adapter, adapter->mbox, &c, sizeof(c), NULL);
if (err < 0)
dev_err(adapter->pdev_dev,
"PTP: %s error %d\n", __func__, -err);
return err;
}
static int cxgb4_ptp_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
struct adapter *adapter = (struct adapter *)container_of(ptp,
struct adapter, ptp_clock_info);
struct fw_ptp_cmd c;
int err;
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PTP_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_PTP_CMD_PORTID_V(0));
c.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(sizeof(c) / 16));
c.u.ts.sc = FW_PTP_SC_ADJ_FREQ;
c.u.ts.sign = (ppb < 0) ? 1 : 0;
if (ppb < 0)
ppb = -ppb;
c.u.ts.ppb = cpu_to_be32(ppb);
err = t4_wr_mbox(adapter, adapter->mbox, &c, sizeof(c), NULL);
if (err < 0)
dev_err(adapter->pdev_dev,
"PTP: %s error %d\n", __func__, -err);
return err;
}
static int cxgb4_ptp_fineadjtime(struct adapter *adapter, s64 delta)
{
struct fw_ptp_cmd c;
int err;
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PTP_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_PTP_CMD_PORTID_V(0));
c.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(sizeof(c) / 16));
c.u.ts.sc = FW_PTP_SC_ADJ_FTIME;
c.u.ts.tm = cpu_to_be64(delta);
err = t4_wr_mbox(adapter, adapter->mbox, &c, sizeof(c), NULL);
if (err < 0)
dev_err(adapter->pdev_dev,
"PTP: %s error %d\n", __func__, -err);
return err;
}
static int cxgb4_ptp_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
struct adapter *adapter =
(struct adapter *)container_of(ptp, struct adapter,
ptp_clock_info);
struct fw_ptp_cmd c;
s64 sign = 1;
int err;
if (delta < 0)
sign = -1;
if (delta * sign > PTP_CLOCK_MAX_ADJTIME) {
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PTP_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_PTP_CMD_PORTID_V(0));
c.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(sizeof(c) / 16));
c.u.ts.sc = FW_PTP_SC_ADJ_TIME;
c.u.ts.sign = (delta < 0) ? 1 : 0;
if (delta < 0)
delta = -delta;
c.u.ts.tm = cpu_to_be64(delta);
err = t4_wr_mbox(adapter, adapter->mbox, &c, sizeof(c), NULL);
if (err < 0)
dev_err(adapter->pdev_dev,
"PTP: %s error %d\n", __func__, -err);
} else {
err = cxgb4_ptp_fineadjtime(adapter, delta);
}
return err;
}
static int cxgb4_ptp_gettime(struct ptp_clock_info *ptp, struct timespec64 *ts)
{
struct adapter *adapter = (struct adapter *)container_of(ptp,
struct adapter, ptp_clock_info);
struct fw_ptp_cmd c;
u64 ns;
int err;
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PTP_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F |
FW_PTP_CMD_PORTID_V(0));
c.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(sizeof(c) / 16));
c.u.ts.sc = FW_PTP_SC_GET_TIME;
err = t4_wr_mbox(adapter, adapter->mbox, &c, sizeof(c), &c);
if (err < 0) {
dev_err(adapter->pdev_dev,
"PTP: %s error %d\n", __func__, -err);
return err;
}
ns = be64_to_cpu(c.u.ts.tm);
*ts = ns_to_timespec64(ns);
return err;
}
static int cxgb4_ptp_settime(struct ptp_clock_info *ptp,
const struct timespec64 *ts)
{
struct adapter *adapter = (struct adapter *)container_of(ptp,
struct adapter, ptp_clock_info);
struct fw_ptp_cmd c;
u64 ns;
int err;
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PTP_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_PTP_CMD_PORTID_V(0));
c.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(sizeof(c) / 16));
c.u.ts.sc = FW_PTP_SC_SET_TIME;
ns = timespec64_to_ns(ts);
c.u.ts.tm = cpu_to_be64(ns);
err = t4_wr_mbox(adapter, adapter->mbox, &c, sizeof(c), NULL);
if (err < 0)
dev_err(adapter->pdev_dev,
"PTP: %s error %d\n", __func__, -err);
return err;
}
static void cxgb4_init_ptp_timer(struct adapter *adapter)
{
struct fw_ptp_cmd c;
int err;
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PTP_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_PTP_CMD_PORTID_V(0));
c.retval_len16 = cpu_to_be32(FW_CMD_LEN16_V(sizeof(c) / 16));
c.u.scmd.sc = FW_PTP_SC_INIT_TIMER;
err = t4_wr_mbox(adapter, adapter->mbox, &c, sizeof(c), NULL);
if (err < 0)
dev_err(adapter->pdev_dev,
"PTP: %s error %d\n", __func__, -err);
}
static int cxgb4_ptp_enable(struct ptp_clock_info __always_unused *ptp,
struct ptp_clock_request __always_unused *request,
int __always_unused on)
{
return -ENOTSUPP;
}
void cxgb4_ptp_init(struct adapter *adapter)
{
struct timespec64 now;
if (!IS_ERR_OR_NULL(adapter->ptp_clock))
return;
adapter->ptp_tx_skb = NULL;
adapter->ptp_clock_info = cxgb4_ptp_clock_info;
spin_lock_init(&adapter->ptp_lock);
adapter->ptp_clock = ptp_clock_register(&adapter->ptp_clock_info,
&adapter->pdev->dev);
if (IS_ERR_OR_NULL(adapter->ptp_clock)) {
adapter->ptp_clock = NULL;
dev_err(adapter->pdev_dev,
"PTP %s Clock registration has failed\n", __func__);
return;
}
now = ktime_to_timespec64(ktime_get_real());
cxgb4_init_ptp_timer(adapter);
if (cxgb4_ptp_settime(&adapter->ptp_clock_info, &now) < 0) {
ptp_clock_unregister(adapter->ptp_clock);
adapter->ptp_clock = NULL;
}
}
void cxgb4_ptp_stop(struct adapter *adapter)
{
if (adapter->ptp_tx_skb) {
dev_kfree_skb_any(adapter->ptp_tx_skb);
adapter->ptp_tx_skb = NULL;
}
if (adapter->ptp_clock) {
ptp_clock_unregister(adapter->ptp_clock);
adapter->ptp_clock = NULL;
}
}
