static void link_report(struct net_device *dev)
{
if (!netif_carrier_ok(dev))
netdev_info(dev, "link down\n");
else {
static const char *fc[] = { "no", "Rx", "Tx", "Tx/Rx" };
const char *s;
const struct port_info *p = netdev_priv(dev);
switch (p->link_cfg.speed) {
case 100:
s = "100Mbps";
break;
case 1000:
s = "1Gbps";
break;
case 10000:
s = "10Gbps";
break;
case 25000:
s = "25Gbps";
break;
case 40000:
s = "40Gbps";
break;
case 100000:
s = "100Gbps";
break;
default:
pr_info("%s: unsupported speed: %d\n",
dev->name, p->link_cfg.speed);
return;
}
netdev_info(dev, "link up, %s, full-duplex, %s PAUSE\n", s,
fc[p->link_cfg.fc]);
}
}
static void dcb_tx_queue_prio_enable(struct net_device *dev, int enable)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adap = pi->adapter;
struct sge_eth_txq *txq = &adap->sge.ethtxq[pi->first_qset];
int i;
for (i = 0; i < pi->nqsets; i++, txq++) {
u32 name, value;
int err;
name = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DMAQ) |
FW_PARAMS_PARAM_X_V(
FW_PARAMS_PARAM_DMAQ_EQ_DCBPRIO_ETH) |
FW_PARAMS_PARAM_YZ_V(txq->q.cntxt_id));
value = enable ? i : 0xffffffff;
err = t4_set_params_timeout(adap, adap->mbox, adap->pf, 0, 1,
&name, &value,
-FW_CMD_MAX_TIMEOUT);
if (err)
dev_err(adap->pdev_dev,
"Can't %s DCB Priority on port %d, TX Queue %d: err=%d\n",
enable ? "set" : "unset", pi->port_id, i, -err);
else
txq->dcb_prio = value;
}
}
static int cxgb4_dcb_enabled(const struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
if (!pi->dcb.enabled)
return 0;
return ((pi->dcb.state == CXGB4_DCB_STATE_FW_ALLSYNCED) ||
(pi->dcb.state == CXGB4_DCB_STATE_HOST));
}
void t4_os_link_changed(struct adapter *adapter, int port_id, int link_stat)
{
struct net_device *dev = adapter->port[port_id];
if (netif_running(dev) && link_stat != netif_carrier_ok(dev)) {
if (link_stat)
netif_carrier_on(dev);
else {
#ifdef CONFIG_CHELSIO_T4_DCB
if (cxgb4_dcb_enabled(dev)) {
cxgb4_dcb_state_init(dev);
dcb_tx_queue_prio_enable(dev, false);
}
#endif
netif_carrier_off(dev);
}
link_report(dev);
}
}
void t4_os_portmod_changed(const struct adapter *adap, int port_id)
{
static const char *mod_str[] = {
NULL, "LR", "SR", "ER", "passive DA", "active DA", "LRM"
};
const struct net_device *dev = adap->port[port_id];
const struct port_info *pi = netdev_priv(dev);
if (pi->mod_type == FW_PORT_MOD_TYPE_NONE)
netdev_info(dev, "port module unplugged\n");
else if (pi->mod_type < ARRAY_SIZE(mod_str))
netdev_info(dev, "%s module inserted\n", mod_str[pi->mod_type]);
else if (pi->mod_type == FW_PORT_MOD_TYPE_NOTSUPPORTED)
netdev_info(dev, "%s: unsupported port module inserted\n",
dev->name);
else if (pi->mod_type == FW_PORT_MOD_TYPE_UNKNOWN)
netdev_info(dev, "%s: unknown port module inserted\n",
dev->name);
else if (pi->mod_type == FW_PORT_MOD_TYPE_ERROR)
netdev_info(dev, "%s: transceiver module error\n", dev->name);
else
netdev_info(dev, "%s: unknown module type %d inserted\n",
dev->name, pi->mod_type);
}
static inline int cxgb4_set_addr_hash(struct port_info *pi)
{
struct adapter *adap = pi->adapter;
u64 vec = 0;
bool ucast = false;
struct hash_mac_addr *entry;
list_for_each_entry(entry, &adap->mac_hlist, list) {
ucast |= is_unicast_ether_addr(entry->addr);
vec |= (1ULL << hash_mac_addr(entry->addr));
}
return t4_set_addr_hash(adap, adap->mbox, pi->viid, ucast,
vec, false);
}
static int cxgb4_mac_sync(struct net_device *netdev, const u8 *mac_addr)
{
struct port_info *pi = netdev_priv(netdev);
struct adapter *adap = pi->adapter;
int ret;
u64 mhash = 0;
u64 uhash = 0;
bool free = false;
bool ucast = is_unicast_ether_addr(mac_addr);
const u8 *maclist[1] = {mac_addr};
struct hash_mac_addr *new_entry;
ret = t4_alloc_mac_filt(adap, adap->mbox, pi->viid, free, 1, maclist,
NULL, ucast ? &uhash : &mhash, false);
if (ret < 0)
goto out;
if (uhash || mhash) {
new_entry = kzalloc(sizeof(*new_entry), GFP_ATOMIC);
if (!new_entry)
return -ENOMEM;
ether_addr_copy(new_entry->addr, mac_addr);
list_add_tail(&new_entry->list, &adap->mac_hlist);
ret = cxgb4_set_addr_hash(pi);
}
out:
return ret < 0 ? ret : 0;
}
static int cxgb4_mac_unsync(struct net_device *netdev, const u8 *mac_addr)
{
struct port_info *pi = netdev_priv(netdev);
struct adapter *adap = pi->adapter;
int ret;
const u8 *maclist[1] = {mac_addr};
struct hash_mac_addr *entry, *tmp;
list_for_each_entry_safe(entry, tmp, &adap->mac_hlist, list) {
if (ether_addr_equal(entry->addr, mac_addr)) {
list_del(&entry->list);
kfree(entry);
return cxgb4_set_addr_hash(pi);
}
}
ret = t4_free_mac_filt(adap, adap->mbox, pi->viid, 1, maclist, false);
return ret < 0 ? -EINVAL : 0;
}
static int set_rxmode(struct net_device *dev, int mtu, bool sleep_ok)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
__dev_uc_sync(dev, cxgb4_mac_sync, cxgb4_mac_unsync);
__dev_mc_sync(dev, cxgb4_mac_sync, cxgb4_mac_unsync);
return t4_set_rxmode(adapter, adapter->mbox, pi->viid, mtu,
(dev->flags & IFF_PROMISC) ? 1 : 0,
(dev->flags & IFF_ALLMULTI) ? 1 : 0, 1, -1,
sleep_ok);
}
static int link_start(struct net_device *dev)
{
int ret;
struct port_info *pi = netdev_priv(dev);
unsigned int mb = pi->adapter->pf;
ret = t4_set_rxmode(pi->adapter, mb, pi->viid, dev->mtu, -1, -1, -1,
!!(dev->features & NETIF_F_HW_VLAN_CTAG_RX), true);
if (ret == 0) {
ret = t4_change_mac(pi->adapter, mb, pi->viid,
pi->xact_addr_filt, dev->dev_addr, true,
true);
if (ret >= 0) {
pi->xact_addr_filt = ret;
ret = 0;
}
}
if (ret == 0)
ret = t4_link_l1cfg(pi->adapter, mb, pi->tx_chan,
&pi->link_cfg);
if (ret == 0) {
local_bh_disable();
ret = t4_enable_vi_params(pi->adapter, mb, pi->viid, true,
true, CXGB4_DCB_ENABLED);
local_bh_enable();
}
return ret;
}
static void dcb_rpl(struct adapter *adap, const struct fw_port_cmd *pcmd)
{
int port = FW_PORT_CMD_PORTID_G(ntohl(pcmd->op_to_portid));
struct net_device *dev = adap->port[adap->chan_map[port]];
int old_dcb_enabled = cxgb4_dcb_enabled(dev);
int new_dcb_enabled;
cxgb4_dcb_handle_fw_update(adap, pcmd);
new_dcb_enabled = cxgb4_dcb_enabled(dev);
if (new_dcb_enabled != old_dcb_enabled)
dcb_tx_queue_prio_enable(dev, new_dcb_enabled);
}
static int fwevtq_handler(struct sge_rspq *q, const __be64 *rsp,
const struct pkt_gl *gl)
{
u8 opcode = ((const struct rss_header *)rsp)->opcode;
rsp++;
if (unlikely(opcode == CPL_FW4_MSG &&
((const struct cpl_fw4_msg *)rsp)->type == FW_TYPE_RSSCPL)) {
rsp++;
opcode = ((const struct rss_header *)rsp)->opcode;
rsp++;
if (opcode != CPL_SGE_EGR_UPDATE) {
dev_err(q->adap->pdev_dev, "unexpected FW4/CPL %#x on FW event queue\n"
, opcode);
goto out;
}
}
if (likely(opcode == CPL_SGE_EGR_UPDATE)) {
const struct cpl_sge_egr_update *p = (void *)rsp;
unsigned int qid = EGR_QID_G(ntohl(p->opcode_qid));
struct sge_txq *txq;
txq = q->adap->sge.egr_map[qid - q->adap->sge.egr_start];
txq->restarts++;
if (txq->q_type == CXGB4_TXQ_ETH) {
struct sge_eth_txq *eq;
eq = container_of(txq, struct sge_eth_txq, q);
netif_tx_wake_queue(eq->txq);
} else {
struct sge_uld_txq *oq;
oq = container_of(txq, struct sge_uld_txq, q);
tasklet_schedule(&oq->qresume_tsk);
}
} else if (opcode == CPL_FW6_MSG || opcode == CPL_FW4_MSG) {
const struct cpl_fw6_msg *p = (void *)rsp;
#ifdef CONFIG_CHELSIO_T4_DCB
const struct fw_port_cmd *pcmd = (const void *)p->data;
unsigned int cmd = FW_CMD_OP_G(ntohl(pcmd->op_to_portid));
unsigned int action =
FW_PORT_CMD_ACTION_G(ntohl(pcmd->action_to_len16));
if (cmd == FW_PORT_CMD &&
(action == FW_PORT_ACTION_GET_PORT_INFO ||
action == FW_PORT_ACTION_GET_PORT_INFO32)) {
int port = FW_PORT_CMD_PORTID_G(
be32_to_cpu(pcmd->op_to_portid));
struct net_device *dev;
int dcbxdis, state_input;
dev = q->adap->port[q->adap->chan_map[port]];
dcbxdis = (action == FW_PORT_ACTION_GET_PORT_INFO
? !!(pcmd->u.info.dcbxdis_pkd &
FW_PORT_CMD_DCBXDIS_F)
: !!(pcmd->u.info32.lstatus32_to_cbllen32 &
FW_PORT_CMD_DCBXDIS32_F));
state_input = (dcbxdis
? CXGB4_DCB_INPUT_FW_DISABLED
: CXGB4_DCB_INPUT_FW_ENABLED);
cxgb4_dcb_state_fsm(dev, state_input);
}
if (cmd == FW_PORT_CMD &&
action == FW_PORT_ACTION_L2_DCB_CFG)
dcb_rpl(q->adap, pcmd);
else
#endif
if (p->type == 0)
t4_handle_fw_rpl(q->adap, p->data);
} else if (opcode == CPL_L2T_WRITE_RPL) {
const struct cpl_l2t_write_rpl *p = (void *)rsp;
do_l2t_write_rpl(q->adap, p);
} else if (opcode == CPL_SET_TCB_RPL) {
const struct cpl_set_tcb_rpl *p = (void *)rsp;
filter_rpl(q->adap, p);
} else
dev_err(q->adap->pdev_dev,
"unexpected CPL %#x on FW event queue\n", opcode);
out:
return 0;
}
static void disable_msi(struct adapter *adapter)
{
if (adapter->flags & USING_MSIX) {
pci_disable_msix(adapter->pdev);
adapter->flags &= ~USING_MSIX;
} else if (adapter->flags & USING_MSI) {
pci_disable_msi(adapter->pdev);
adapter->flags &= ~USING_MSI;
}
}
static irqreturn_t t4_nondata_intr(int irq, void *cookie)
{
struct adapter *adap = cookie;
u32 v = t4_read_reg(adap, MYPF_REG(PL_PF_INT_CAUSE_A));
if (v & PFSW_F) {
adap->swintr = 1;
t4_write_reg(adap, MYPF_REG(PL_PF_INT_CAUSE_A), v);
}
if (adap->flags & MASTER_PF)
t4_slow_intr_handler(adap);
return IRQ_HANDLED;
}
static void name_msix_vecs(struct adapter *adap)
{
int i, j, msi_idx = 2, n = sizeof(adap->msix_info[0].desc);
snprintf(adap->msix_info[0].desc, n, "%s", adap->port[0]->name);
snprintf(adap->msix_info[1].desc, n, "%s-FWeventq",
adap->port[0]->name);
for_each_port(adap, j) {
struct net_device *d = adap->port[j];
const struct port_info *pi = netdev_priv(d);
for (i = 0; i < pi->nqsets; i++, msi_idx++)
snprintf(adap->msix_info[msi_idx].desc, n, "%s-Rx%d",
d->name, i);
}
}
static int request_msix_queue_irqs(struct adapter *adap)
{
struct sge *s = &adap->sge;
int err, ethqidx;
int msi_index = 2;
err = request_irq(adap->msix_info[1].vec, t4_sge_intr_msix, 0,
adap->msix_info[1].desc, &s->fw_evtq);
if (err)
return err;
for_each_ethrxq(s, ethqidx) {
err = request_irq(adap->msix_info[msi_index].vec,
t4_sge_intr_msix, 0,
adap->msix_info[msi_index].desc,
&s->ethrxq[ethqidx].rspq);
if (err)
goto unwind;
msi_index++;
}
return 0;
unwind:
while (--ethqidx >= 0)
free_irq(adap->msix_info[--msi_index].vec,
&s->ethrxq[ethqidx].rspq);
free_irq(adap->msix_info[1].vec, &s->fw_evtq);
return err;
}
static void free_msix_queue_irqs(struct adapter *adap)
{
int i, msi_index = 2;
struct sge *s = &adap->sge;
free_irq(adap->msix_info[1].vec, &s->fw_evtq);
for_each_ethrxq(s, i)
free_irq(adap->msix_info[msi_index++].vec, &s->ethrxq[i].rspq);
}
int cxgb4_write_rss(const struct port_info *pi, const u16 *queues)
{
u16 *rss;
int i, err;
struct adapter *adapter = pi->adapter;
const struct sge_eth_rxq *rxq;
rxq = &adapter->sge.ethrxq[pi->first_qset];
rss = kmalloc(pi->rss_size * sizeof(u16), GFP_KERNEL);
if (!rss)
return -ENOMEM;
for (i = 0; i < pi->rss_size; i++, queues++)
rss[i] = rxq[*queues].rspq.abs_id;
err = t4_config_rss_range(adapter, adapter->pf, pi->viid, 0,
pi->rss_size, rss, pi->rss_size);
if (!err)
err = t4_config_vi_rss(adapter, adapter->mbox, pi->viid,
FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN_F |
FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN_F |
FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN_F |
FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN_F |
FW_RSS_VI_CONFIG_CMD_UDPEN_F,
rss[0]);
kfree(rss);
return err;
}
static int setup_rss(struct adapter *adap)
{
int i, j, err;
for_each_port(adap, i) {
const struct port_info *pi = adap2pinfo(adap, i);
for (j = 0; j < pi->rss_size; j++)
pi->rss[j] = j % pi->nqsets;
err = cxgb4_write_rss(pi, pi->rss);
if (err)
return err;
}
return 0;
}
static unsigned int rxq_to_chan(const struct sge *p, unsigned int qid)
{
qid -= p->ingr_start;
return netdev2pinfo(p->ingr_map[qid]->netdev)->tx_chan;
}
static void quiesce_rx(struct adapter *adap)
{
int i;
for (i = 0; i < adap->sge.ingr_sz; i++) {
struct sge_rspq *q = adap->sge.ingr_map[i];
if (q && q->handler)
napi_disable(&q->napi);
}
}
static void disable_interrupts(struct adapter *adap)
{
if (adap->flags & FULL_INIT_DONE) {
t4_intr_disable(adap);
if (adap->flags & USING_MSIX) {
free_msix_queue_irqs(adap);
free_irq(adap->msix_info[0].vec, adap);
} else {
free_irq(adap->pdev->irq, adap);
}
quiesce_rx(adap);
}
}
static void enable_rx(struct adapter *adap)
{
int i;
for (i = 0; i < adap->sge.ingr_sz; i++) {
struct sge_rspq *q = adap->sge.ingr_map[i];
if (!q)
continue;
if (q->handler)
napi_enable(&q->napi);
t4_write_reg(adap, MYPF_REG(SGE_PF_GTS_A),
SEINTARM_V(q->intr_params) |
INGRESSQID_V(q->cntxt_id));
}
}
static int setup_fw_sge_queues(struct adapter *adap)
{
struct sge *s = &adap->sge;
int err = 0;
bitmap_zero(s->starving_fl, s->egr_sz);
bitmap_zero(s->txq_maperr, s->egr_sz);
if (adap->flags & USING_MSIX)
adap->msi_idx = 1;
else {
err = t4_sge_alloc_rxq(adap, &s->intrq, false, adap->port[0], 0,
NULL, NULL, NULL, -1);
if (err)
return err;
adap->msi_idx = -((int)s->intrq.abs_id + 1);
}
err = t4_sge_alloc_rxq(adap, &s->fw_evtq, true, adap->port[0],
adap->msi_idx, NULL, fwevtq_handler, NULL, -1);
if (err)
t4_free_sge_resources(adap);
return err;
}
static int setup_sge_queues(struct adapter *adap)
{
int err, i, j;
struct sge *s = &adap->sge;
struct sge_uld_rxq_info *rxq_info = NULL;
unsigned int cmplqid = 0;
if (is_uld(adap))
rxq_info = s->uld_rxq_info[CXGB4_ULD_RDMA];
for_each_port(adap, i) {
struct net_device *dev = adap->port[i];
struct port_info *pi = netdev_priv(dev);
struct sge_eth_rxq *q = &s->ethrxq[pi->first_qset];
struct sge_eth_txq *t = &s->ethtxq[pi->first_qset];
for (j = 0; j < pi->nqsets; j++, q++) {
if (adap->msi_idx > 0)
adap->msi_idx++;
err = t4_sge_alloc_rxq(adap, &q->rspq, false, dev,
adap->msi_idx, &q->fl,
t4_ethrx_handler,
NULL,
t4_get_tp_ch_map(adap,
pi->tx_chan));
if (err)
goto freeout;
q->rspq.idx = j;
memset(&q->stats, 0, sizeof(q->stats));
}
for (j = 0; j < pi->nqsets; j++, t++) {
err = t4_sge_alloc_eth_txq(adap, t, dev,
netdev_get_tx_queue(dev, j),
s->fw_evtq.cntxt_id);
if (err)
goto freeout;
}
}
for_each_port(adap, i) {
if (rxq_info)
cmplqid = rxq_info->uldrxq[i].rspq.cntxt_id;
err = t4_sge_alloc_ctrl_txq(adap, &s->ctrlq[i], adap->port[i],
s->fw_evtq.cntxt_id, cmplqid);
if (err)
goto freeout;
}
if (!is_t4(adap->params.chip)) {
err = t4_sge_alloc_eth_txq(adap, &s->ptptxq, adap->port[0],
netdev_get_tx_queue(adap->port[0], 0)
, s->fw_evtq.cntxt_id);
if (err)
goto freeout;
}
t4_write_reg(adap, is_t4(adap->params.chip) ?
MPS_TRC_RSS_CONTROL_A :
MPS_T5_TRC_RSS_CONTROL_A,
RSSCONTROL_V(netdev2pinfo(adap->port[0])->tx_chan) |
QUEUENUMBER_V(s->ethrxq[0].rspq.abs_id));
return 0;
freeout:
t4_free_sge_resources(adap);
return err;
}
static u16 cxgb_select_queue(struct net_device *dev, struct sk_buff *skb,
void *accel_priv, select_queue_fallback_t fallback)
{
int txq;
#ifdef CONFIG_CHELSIO_T4_DCB
if (cxgb4_dcb_enabled(dev) && !is_kdump_kernel()) {
u16 vlan_tci;
int err;
err = vlan_get_tag(skb, &vlan_tci);
if (unlikely(err)) {
if (net_ratelimit())
netdev_warn(dev,
"TX Packet without VLAN Tag on DCB Link\n");
txq = 0;
} else {
txq = (vlan_tci & VLAN_PRIO_MASK) >> VLAN_PRIO_SHIFT;
#ifdef CONFIG_CHELSIO_T4_FCOE
if (skb->protocol == htons(ETH_P_FCOE))
txq = skb->priority & 0x7;
#endif
}
return txq;
}
#endif
if (select_queue) {
txq = (skb_rx_queue_recorded(skb)
? skb_get_rx_queue(skb)
: smp_processor_id());
while (unlikely(txq >= dev->real_num_tx_queues))
txq -= dev->real_num_tx_queues;
return txq;
}
return fallback(dev, skb) % dev->real_num_tx_queues;
}
static int closest_timer(const struct sge *s, int time)
{
int i, delta, match = 0, min_delta = INT_MAX;
for (i = 0; i < ARRAY_SIZE(s->timer_val); i++) {
delta = time - s->timer_val[i];
if (delta < 0)
delta = -delta;
if (delta < min_delta) {
min_delta = delta;
match = i;
}
}
return match;
}
static int closest_thres(const struct sge *s, int thres)
{
int i, delta, match = 0, min_delta = INT_MAX;
for (i = 0; i < ARRAY_SIZE(s->counter_val); i++) {
delta = thres - s->counter_val[i];
if (delta < 0)
delta = -delta;
if (delta < min_delta) {
min_delta = delta;
match = i;
}
}
return match;
}
int cxgb4_set_rspq_intr_params(struct sge_rspq *q,
unsigned int us, unsigned int cnt)
{
struct adapter *adap = q->adap;
if ((us | cnt) == 0)
cnt = 1;
if (cnt) {
int err;
u32 v, new_idx;
new_idx = closest_thres(&adap->sge, cnt);
if (q->desc && q->pktcnt_idx != new_idx) {
v = FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DMAQ) |
FW_PARAMS_PARAM_X_V(
FW_PARAMS_PARAM_DMAQ_IQ_INTCNTTHRESH) |
FW_PARAMS_PARAM_YZ_V(q->cntxt_id);
err = t4_set_params(adap, adap->mbox, adap->pf, 0, 1,
&v, &new_idx);
if (err)
return err;
}
q->pktcnt_idx = new_idx;
}
us = us == 0 ? 6 : closest_timer(&adap->sge, us);
q->intr_params = QINTR_TIMER_IDX_V(us) | QINTR_CNT_EN_V(cnt > 0);
return 0;
}
static int cxgb_set_features(struct net_device *dev, netdev_features_t features)
{
const struct port_info *pi = netdev_priv(dev);
netdev_features_t changed = dev->features ^ features;
int err;
if (!(changed & NETIF_F_HW_VLAN_CTAG_RX))
return 0;
err = t4_set_rxmode(pi->adapter, pi->adapter->pf, pi->viid, -1,
-1, -1, -1,
!!(features & NETIF_F_HW_VLAN_CTAG_RX), true);
if (unlikely(err))
dev->features = features ^ NETIF_F_HW_VLAN_CTAG_RX;
return err;
}
static int setup_debugfs(struct adapter *adap)
{
if (IS_ERR_OR_NULL(adap->debugfs_root))
return -1;
#ifdef CONFIG_DEBUG_FS
t4_setup_debugfs(adap);
#endif
return 0;
}
int cxgb4_alloc_atid(struct tid_info *t, void *data)
{
int atid = -1;
spin_lock_bh(&t->atid_lock);
if (t->afree) {
union aopen_entry *p = t->afree;
atid = (p - t->atid_tab) + t->atid_base;
t->afree = p->next;
p->data = data;
t->atids_in_use++;
}
spin_unlock_bh(&t->atid_lock);
return atid;
}
void cxgb4_free_atid(struct tid_info *t, unsigned int atid)
{
union aopen_entry *p = &t->atid_tab[atid - t->atid_base];
spin_lock_bh(&t->atid_lock);
p->next = t->afree;
t->afree = p;
t->atids_in_use--;
spin_unlock_bh(&t->atid_lock);
}
int cxgb4_alloc_stid(struct tid_info *t, int family, void *data)
{
int stid;
spin_lock_bh(&t->stid_lock);
if (family == PF_INET) {
stid = find_first_zero_bit(t->stid_bmap, t->nstids);
if (stid < t->nstids)
__set_bit(stid, t->stid_bmap);
else
stid = -1;
} else {
stid = bitmap_find_free_region(t->stid_bmap, t->nstids, 1);
if (stid < 0)
stid = -1;
}
if (stid >= 0) {
t->stid_tab[stid].data = data;
stid += t->stid_base;
if (family == PF_INET6) {
t->stids_in_use += 2;
t->v6_stids_in_use += 2;
} else {
t->stids_in_use++;
}
}
spin_unlock_bh(&t->stid_lock);
return stid;
}
int cxgb4_alloc_sftid(struct tid_info *t, int family, void *data)
{
int stid;
spin_lock_bh(&t->stid_lock);
if (family == PF_INET) {
stid = find_next_zero_bit(t->stid_bmap,
t->nstids + t->nsftids, t->nstids);
if (stid < (t->nstids + t->nsftids))
__set_bit(stid, t->stid_bmap);
else
stid = -1;
} else {
stid = -1;
}
if (stid >= 0) {
t->stid_tab[stid].data = data;
stid -= t->nstids;
stid += t->sftid_base;
t->sftids_in_use++;
}
spin_unlock_bh(&t->stid_lock);
return stid;
}
void cxgb4_free_stid(struct tid_info *t, unsigned int stid, int family)
{
if (t->nsftids && (stid >= t->sftid_base)) {
stid -= t->sftid_base;
stid += t->nstids;
} else {
stid -= t->stid_base;
}
spin_lock_bh(&t->stid_lock);
if (family == PF_INET)
__clear_bit(stid, t->stid_bmap);
else
bitmap_release_region(t->stid_bmap, stid, 1);
t->stid_tab[stid].data = NULL;
if (stid < t->nstids) {
if (family == PF_INET6) {
t->stids_in_use -= 2;
t->v6_stids_in_use -= 2;
} else {
t->stids_in_use--;
}
} else {
t->sftids_in_use--;
}
spin_unlock_bh(&t->stid_lock);
}
static void mk_tid_release(struct sk_buff *skb, unsigned int chan,
unsigned int tid)
{
struct cpl_tid_release *req;
set_wr_txq(skb, CPL_PRIORITY_SETUP, chan);
req = __skb_put(skb, sizeof(*req));
INIT_TP_WR(req, tid);
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_TID_RELEASE, tid));
}
static void cxgb4_queue_tid_release(struct tid_info *t, unsigned int chan,
unsigned int tid)
{
void **p = &t->tid_tab[tid];
struct adapter *adap = container_of(t, struct adapter, tids);
spin_lock_bh(&adap->tid_release_lock);
*p = adap->tid_release_head;
adap->tid_release_head = (void **)((uintptr_t)p | chan);
if (!adap->tid_release_task_busy) {
adap->tid_release_task_busy = true;
queue_work(adap->workq, &adap->tid_release_task);
}
spin_unlock_bh(&adap->tid_release_lock);
}
static void process_tid_release_list(struct work_struct *work)
{
struct sk_buff *skb;
struct adapter *adap;
adap = container_of(work, struct adapter, tid_release_task);
spin_lock_bh(&adap->tid_release_lock);
while (adap->tid_release_head) {
void **p = adap->tid_release_head;
unsigned int chan = (uintptr_t)p & 3;
p = (void *)p - chan;
adap->tid_release_head = *p;
*p = NULL;
spin_unlock_bh(&adap->tid_release_lock);
while (!(skb = alloc_skb(sizeof(struct cpl_tid_release),
GFP_KERNEL)))
schedule_timeout_uninterruptible(1);
mk_tid_release(skb, chan, p - adap->tids.tid_tab);
t4_ofld_send(adap, skb);
spin_lock_bh(&adap->tid_release_lock);
}
adap->tid_release_task_busy = false;
spin_unlock_bh(&adap->tid_release_lock);
}
void cxgb4_remove_tid(struct tid_info *t, unsigned int chan, unsigned int tid,
unsigned short family)
{
struct sk_buff *skb;
struct adapter *adap = container_of(t, struct adapter, tids);
WARN_ON(tid >= t->ntids);
if (t->tid_tab[tid]) {
t->tid_tab[tid] = NULL;
atomic_dec(&t->conns_in_use);
if (t->hash_base && (tid >= t->hash_base)) {
if (family == AF_INET6)
atomic_sub(2, &t->hash_tids_in_use);
else
atomic_dec(&t->hash_tids_in_use);
} else {
if (family == AF_INET6)
atomic_sub(2, &t->tids_in_use);
else
atomic_dec(&t->tids_in_use);
}
}
skb = alloc_skb(sizeof(struct cpl_tid_release), GFP_ATOMIC);
if (likely(skb)) {
mk_tid_release(skb, chan, tid);
t4_ofld_send(adap, skb);
} else
cxgb4_queue_tid_release(t, chan, tid);
}
static int tid_init(struct tid_info *t)
{
struct adapter *adap = container_of(t, struct adapter, tids);
unsigned int max_ftids = t->nftids + t->nsftids;
unsigned int natids = t->natids;
unsigned int stid_bmap_size;
unsigned int ftid_bmap_size;
size_t size;
stid_bmap_size = BITS_TO_LONGS(t->nstids + t->nsftids);
ftid_bmap_size = BITS_TO_LONGS(t->nftids);
size = t->ntids * sizeof(*t->tid_tab) +
natids * sizeof(*t->atid_tab) +
t->nstids * sizeof(*t->stid_tab) +
t->nsftids * sizeof(*t->stid_tab) +
stid_bmap_size * sizeof(long) +
max_ftids * sizeof(*t->ftid_tab) +
ftid_bmap_size * sizeof(long);
t->tid_tab = kvzalloc(size, GFP_KERNEL);
if (!t->tid_tab)
return -ENOMEM;
t->atid_tab = (union aopen_entry *)&t->tid_tab[t->ntids];
t->stid_tab = (struct serv_entry *)&t->atid_tab[natids];
t->stid_bmap = (unsigned long *)&t->stid_tab[t->nstids + t->nsftids];
t->ftid_tab = (struct filter_entry *)&t->stid_bmap[stid_bmap_size];
t->ftid_bmap = (unsigned long *)&t->ftid_tab[max_ftids];
spin_lock_init(&t->stid_lock);
spin_lock_init(&t->atid_lock);
spin_lock_init(&t->ftid_lock);
t->stids_in_use = 0;
t->v6_stids_in_use = 0;
t->sftids_in_use = 0;
t->afree = NULL;
t->atids_in_use = 0;
atomic_set(&t->tids_in_use, 0);
atomic_set(&t->conns_in_use, 0);
atomic_set(&t->hash_tids_in_use, 0);
if (natids) {
while (--natids)
t->atid_tab[natids - 1].next = &t->atid_tab[natids];
t->afree = t->atid_tab;
}
if (is_offload(adap)) {
bitmap_zero(t->stid_bmap, t->nstids + t->nsftids);
if (!t->stid_base &&
CHELSIO_CHIP_VERSION(adap->params.chip) <= CHELSIO_T5)
__set_bit(0, t->stid_bmap);
}
bitmap_zero(t->ftid_bmap, t->nftids);
return 0;
}
int cxgb4_create_server(const struct net_device *dev, unsigned int stid,
__be32 sip, __be16 sport, __be16 vlan,
unsigned int queue)
{
unsigned int chan;
struct sk_buff *skb;
struct adapter *adap;
struct cpl_pass_open_req *req;
int ret;
skb = alloc_skb(sizeof(*req), GFP_KERNEL);
if (!skb)
return -ENOMEM;
adap = netdev2adap(dev);
req = __skb_put(skb, sizeof(*req));
INIT_TP_WR(req, 0);
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_PASS_OPEN_REQ, stid));
req->local_port = sport;
req->peer_port = htons(0);
req->local_ip = sip;
req->peer_ip = htonl(0);
chan = rxq_to_chan(&adap->sge, queue);
req->opt0 = cpu_to_be64(TX_CHAN_V(chan));
req->opt1 = cpu_to_be64(CONN_POLICY_V(CPL_CONN_POLICY_ASK) |
SYN_RSS_ENABLE_F | SYN_RSS_QUEUE_V(queue));
ret = t4_mgmt_tx(adap, skb);
return net_xmit_eval(ret);
}
int cxgb4_create_server6(const struct net_device *dev, unsigned int stid,
const struct in6_addr *sip, __be16 sport,
unsigned int queue)
{
unsigned int chan;
struct sk_buff *skb;
struct adapter *adap;
struct cpl_pass_open_req6 *req;
int ret;
skb = alloc_skb(sizeof(*req), GFP_KERNEL);
if (!skb)
return -ENOMEM;
adap = netdev2adap(dev);
req = __skb_put(skb, sizeof(*req));
INIT_TP_WR(req, 0);
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_PASS_OPEN_REQ6, stid));
req->local_port = sport;
req->peer_port = htons(0);
req->local_ip_hi = *(__be64 *)(sip->s6_addr);
req->local_ip_lo = *(__be64 *)(sip->s6_addr + 8);
req->peer_ip_hi = cpu_to_be64(0);
req->peer_ip_lo = cpu_to_be64(0);
chan = rxq_to_chan(&adap->sge, queue);
req->opt0 = cpu_to_be64(TX_CHAN_V(chan));
req->opt1 = cpu_to_be64(CONN_POLICY_V(CPL_CONN_POLICY_ASK) |
SYN_RSS_ENABLE_F | SYN_RSS_QUEUE_V(queue));
ret = t4_mgmt_tx(adap, skb);
return net_xmit_eval(ret);
}
int cxgb4_remove_server(const struct net_device *dev, unsigned int stid,
unsigned int queue, bool ipv6)
{
struct sk_buff *skb;
struct adapter *adap;
struct cpl_close_listsvr_req *req;
int ret;
adap = netdev2adap(dev);
skb = alloc_skb(sizeof(*req), GFP_KERNEL);
if (!skb)
return -ENOMEM;
req = __skb_put(skb, sizeof(*req));
INIT_TP_WR(req, 0);
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_CLOSE_LISTSRV_REQ, stid));
req->reply_ctrl = htons(NO_REPLY_V(0) | (ipv6 ? LISTSVR_IPV6_V(1) :
LISTSVR_IPV6_V(0)) | QUEUENO_V(queue));
ret = t4_mgmt_tx(adap, skb);
return net_xmit_eval(ret);
}
unsigned int cxgb4_best_mtu(const unsigned short *mtus, unsigned short mtu,
unsigned int *idx)
{
unsigned int i = 0;
while (i < NMTUS - 1 && mtus[i + 1] <= mtu)
++i;
if (idx)
*idx = i;
return mtus[i];
}
unsigned int cxgb4_best_aligned_mtu(const unsigned short *mtus,
unsigned short header_size,
unsigned short data_size_max,
unsigned short data_size_align,
unsigned int *mtu_idxp)
{
unsigned short max_mtu = header_size + data_size_max;
unsigned short data_size_align_mask = data_size_align - 1;
int mtu_idx, aligned_mtu_idx;
for (mtu_idx = 0, aligned_mtu_idx = -1; mtu_idx < NMTUS; mtu_idx++) {
unsigned short data_size = mtus[mtu_idx] - header_size;
if ((data_size & data_size_align_mask) == 0)
aligned_mtu_idx = mtu_idx;
if (mtu_idx+1 < NMTUS && mtus[mtu_idx+1] > max_mtu)
break;
}
if (mtu_idx == NMTUS)
mtu_idx--;
if (aligned_mtu_idx >= 0 &&
mtu_idx - aligned_mtu_idx <= 1)
mtu_idx = aligned_mtu_idx;
if (mtu_idxp)
*mtu_idxp = mtu_idx;
return mtus[mtu_idx];
}
unsigned int cxgb4_tp_smt_idx(enum chip_type chip, unsigned int viid)
{
if (CHELSIO_CHIP_VERSION(chip) <= CHELSIO_T5)
return ((viid & 0x7f) << 1);
else
return (viid & 0x7f);
}
unsigned int cxgb4_port_chan(const struct net_device *dev)
{
return netdev2pinfo(dev)->tx_chan;
}
unsigned int cxgb4_dbfifo_count(const struct net_device *dev, int lpfifo)
{
struct adapter *adap = netdev2adap(dev);
u32 v1, v2, lp_count, hp_count;
v1 = t4_read_reg(adap, SGE_DBFIFO_STATUS_A);
v2 = t4_read_reg(adap, SGE_DBFIFO_STATUS2_A);
if (is_t4(adap->params.chip)) {
lp_count = LP_COUNT_G(v1);
hp_count = HP_COUNT_G(v1);
} else {
lp_count = LP_COUNT_T5_G(v1);
hp_count = HP_COUNT_T5_G(v2);
}
return lpfifo ? lp_count : hp_count;
}
unsigned int cxgb4_port_viid(const struct net_device *dev)
{
return netdev2pinfo(dev)->viid;
}
unsigned int cxgb4_port_idx(const struct net_device *dev)
{
return netdev2pinfo(dev)->port_id;
}
void cxgb4_get_tcp_stats(struct pci_dev *pdev, struct tp_tcp_stats *v4,
struct tp_tcp_stats *v6)
{
struct adapter *adap = pci_get_drvdata(pdev);
spin_lock(&adap->stats_lock);
t4_tp_get_tcp_stats(adap, v4, v6);
spin_unlock(&adap->stats_lock);
}
void cxgb4_iscsi_init(struct net_device *dev, unsigned int tag_mask,
const unsigned int *pgsz_order)
{
struct adapter *adap = netdev2adap(dev);
t4_write_reg(adap, ULP_RX_ISCSI_TAGMASK_A, tag_mask);
t4_write_reg(adap, ULP_RX_ISCSI_PSZ_A, HPZ0_V(pgsz_order[0]) |
HPZ1_V(pgsz_order[1]) | HPZ2_V(pgsz_order[2]) |
HPZ3_V(pgsz_order[3]));
}
int cxgb4_flush_eq_cache(struct net_device *dev)
{
struct adapter *adap = netdev2adap(dev);
return t4_sge_ctxt_flush(adap, adap->mbox);
}
static int read_eq_indices(struct adapter *adap, u16 qid, u16 *pidx, u16 *cidx)
{
u32 addr = t4_read_reg(adap, SGE_DBQ_CTXT_BADDR_A) + 24 * qid + 8;
__be64 indices;
int ret;
spin_lock(&adap->win0_lock);
ret = t4_memory_rw(adap, 0, MEM_EDC0, addr,
sizeof(indices), (__be32 *)&indices,
T4_MEMORY_READ);
spin_unlock(&adap->win0_lock);
if (!ret) {
*cidx = (be64_to_cpu(indices) >> 25) & 0xffff;
*pidx = (be64_to_cpu(indices) >> 9) & 0xffff;
}
return ret;
}
int cxgb4_sync_txq_pidx(struct net_device *dev, u16 qid, u16 pidx,
u16 size)
{
struct adapter *adap = netdev2adap(dev);
u16 hw_pidx, hw_cidx;
int ret;
ret = read_eq_indices(adap, qid, &hw_pidx, &hw_cidx);
if (ret)
goto out;
if (pidx != hw_pidx) {
u16 delta;
u32 val;
if (pidx >= hw_pidx)
delta = pidx - hw_pidx;
else
delta = size - hw_pidx + pidx;
if (is_t4(adap->params.chip))
val = PIDX_V(delta);
else
val = PIDX_T5_V(delta);
wmb();
t4_write_reg(adap, MYPF_REG(SGE_PF_KDOORBELL_A),
QID_V(qid) | val);
}
out:
return ret;
}
int cxgb4_read_tpte(struct net_device *dev, u32 stag, __be32 *tpte)
{
struct adapter *adap;
u32 offset, memtype, memaddr;
u32 edc0_size, edc1_size, mc0_size, mc1_size, size;
u32 edc0_end, edc1_end, mc0_end, mc1_end;
int ret;
adap = netdev2adap(dev);
offset = ((stag >> 8) * 32) + adap->vres.stag.start;
size = t4_read_reg(adap, MA_EDRAM0_BAR_A);
edc0_size = EDRAM0_SIZE_G(size) << 20;
size = t4_read_reg(adap, MA_EDRAM1_BAR_A);
edc1_size = EDRAM1_SIZE_G(size) << 20;
size = t4_read_reg(adap, MA_EXT_MEMORY0_BAR_A);
mc0_size = EXT_MEM0_SIZE_G(size) << 20;
edc0_end = edc0_size;
edc1_end = edc0_end + edc1_size;
mc0_end = edc1_end + mc0_size;
if (offset < edc0_end) {
memtype = MEM_EDC0;
memaddr = offset;
} else if (offset < edc1_end) {
memtype = MEM_EDC1;
memaddr = offset - edc0_end;
} else {
if (offset < mc0_end) {
memtype = MEM_MC0;
memaddr = offset - edc1_end;
} else if (is_t5(adap->params.chip)) {
size = t4_read_reg(adap, MA_EXT_MEMORY1_BAR_A);
mc1_size = EXT_MEM1_SIZE_G(size) << 20;
mc1_end = mc0_end + mc1_size;
if (offset < mc1_end) {
memtype = MEM_MC1;
memaddr = offset - mc0_end;
} else {
goto err;
}
} else {
goto err;
}
}
spin_lock(&adap->win0_lock);
ret = t4_memory_rw(adap, 0, memtype, memaddr, 32, tpte, T4_MEMORY_READ);
spin_unlock(&adap->win0_lock);
return ret;
err:
dev_err(adap->pdev_dev, "stag %#x, offset %#x out of range\n",
stag, offset);
return -EINVAL;
}
u64 cxgb4_read_sge_timestamp(struct net_device *dev)
{
u32 hi, lo;
struct adapter *adap;
adap = netdev2adap(dev);
lo = t4_read_reg(adap, SGE_TIMESTAMP_LO_A);
hi = TSVAL_G(t4_read_reg(adap, SGE_TIMESTAMP_HI_A));
return ((u64)hi << 32) | (u64)lo;
}
int cxgb4_bar2_sge_qregs(struct net_device *dev,
unsigned int qid,
enum cxgb4_bar2_qtype qtype,
int user,
u64 *pbar2_qoffset,
unsigned int *pbar2_qid)
{
return t4_bar2_sge_qregs(netdev2adap(dev),
qid,
(qtype == CXGB4_BAR2_QTYPE_EGRESS
? T4_BAR2_QTYPE_EGRESS
: T4_BAR2_QTYPE_INGRESS),
user,
pbar2_qoffset,
pbar2_qid);
}
static void check_neigh_update(struct neighbour *neigh)
{
const struct device *parent;
const struct net_device *netdev = neigh->dev;
if (is_vlan_dev(netdev))
netdev = vlan_dev_real_dev(netdev);
parent = netdev->dev.parent;
if (parent && parent->driver == &cxgb4_driver.driver)
t4_l2t_update(dev_get_drvdata(parent), neigh);
}
static int netevent_cb(struct notifier_block *nb, unsigned long event,
void *data)
{
switch (event) {
case NETEVENT_NEIGH_UPDATE:
check_neigh_update(data);
break;
case NETEVENT_REDIRECT:
default:
break;
}
return 0;
}
static void drain_db_fifo(struct adapter *adap, int usecs)
{
u32 v1, v2, lp_count, hp_count;
do {
v1 = t4_read_reg(adap, SGE_DBFIFO_STATUS_A);
v2 = t4_read_reg(adap, SGE_DBFIFO_STATUS2_A);
if (is_t4(adap->params.chip)) {
lp_count = LP_COUNT_G(v1);
hp_count = HP_COUNT_G(v1);
} else {
lp_count = LP_COUNT_T5_G(v1);
hp_count = HP_COUNT_T5_G(v2);
}
if (lp_count == 0 && hp_count == 0)
break;
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(usecs_to_jiffies(usecs));
} while (1);
}
static void disable_txq_db(struct sge_txq *q)
{
unsigned long flags;
spin_lock_irqsave(&q->db_lock, flags);
q->db_disabled = 1;
spin_unlock_irqrestore(&q->db_lock, flags);
}
static void enable_txq_db(struct adapter *adap, struct sge_txq *q)
{
spin_lock_irq(&q->db_lock);
if (q->db_pidx_inc) {
wmb();
t4_write_reg(adap, MYPF_REG(SGE_PF_KDOORBELL_A),
QID_V(q->cntxt_id) | PIDX_V(q->db_pidx_inc));
q->db_pidx_inc = 0;
}
q->db_disabled = 0;
spin_unlock_irq(&q->db_lock);
}
static void disable_dbs(struct adapter *adap)
{
int i;
for_each_ethrxq(&adap->sge, i)
disable_txq_db(&adap->sge.ethtxq[i].q);
if (is_offload(adap)) {
struct sge_uld_txq_info *txq_info =
adap->sge.uld_txq_info[CXGB4_TX_OFLD];
if (txq_info) {
for_each_ofldtxq(&adap->sge, i) {
struct sge_uld_txq *txq = &txq_info->uldtxq[i];
disable_txq_db(&txq->q);
}
}
}
for_each_port(adap, i)
disable_txq_db(&adap->sge.ctrlq[i].q);
}
static void enable_dbs(struct adapter *adap)
{
int i;
for_each_ethrxq(&adap->sge, i)
enable_txq_db(adap, &adap->sge.ethtxq[i].q);
if (is_offload(adap)) {
struct sge_uld_txq_info *txq_info =
adap->sge.uld_txq_info[CXGB4_TX_OFLD];
if (txq_info) {
for_each_ofldtxq(&adap->sge, i) {
struct sge_uld_txq *txq = &txq_info->uldtxq[i];
enable_txq_db(adap, &txq->q);
}
}
}
for_each_port(adap, i)
enable_txq_db(adap, &adap->sge.ctrlq[i].q);
}
static void notify_rdma_uld(struct adapter *adap, enum cxgb4_control cmd)
{
enum cxgb4_uld type = CXGB4_ULD_RDMA;
if (adap->uld && adap->uld[type].handle)
adap->uld[type].control(adap->uld[type].handle, cmd);
}
static void process_db_full(struct work_struct *work)
{
struct adapter *adap;
adap = container_of(work, struct adapter, db_full_task);
drain_db_fifo(adap, dbfifo_drain_delay);
enable_dbs(adap);
notify_rdma_uld(adap, CXGB4_CONTROL_DB_EMPTY);
if (CHELSIO_CHIP_VERSION(adap->params.chip) <= CHELSIO_T5)
t4_set_reg_field(adap, SGE_INT_ENABLE3_A,
DBFIFO_HP_INT_F | DBFIFO_LP_INT_F,
DBFIFO_HP_INT_F | DBFIFO_LP_INT_F);
else
t4_set_reg_field(adap, SGE_INT_ENABLE3_A,
DBFIFO_LP_INT_F, DBFIFO_LP_INT_F);
}
static void sync_txq_pidx(struct adapter *adap, struct sge_txq *q)
{
u16 hw_pidx, hw_cidx;
int ret;
spin_lock_irq(&q->db_lock);
ret = read_eq_indices(adap, (u16)q->cntxt_id, &hw_pidx, &hw_cidx);
if (ret)
goto out;
if (q->db_pidx != hw_pidx) {
u16 delta;
u32 val;
if (q->db_pidx >= hw_pidx)
delta = q->db_pidx - hw_pidx;
else
delta = q->size - hw_pidx + q->db_pidx;
if (is_t4(adap->params.chip))
val = PIDX_V(delta);
else
val = PIDX_T5_V(delta);
wmb();
t4_write_reg(adap, MYPF_REG(SGE_PF_KDOORBELL_A),
QID_V(q->cntxt_id) | val);
}
out:
q->db_disabled = 0;
q->db_pidx_inc = 0;
spin_unlock_irq(&q->db_lock);
if (ret)
CH_WARN(adap, "DB drop recovery failed.\n");
}
static void recover_all_queues(struct adapter *adap)
{
int i;
for_each_ethrxq(&adap->sge, i)
sync_txq_pidx(adap, &adap->sge.ethtxq[i].q);
if (is_offload(adap)) {
struct sge_uld_txq_info *txq_info =
adap->sge.uld_txq_info[CXGB4_TX_OFLD];
if (txq_info) {
for_each_ofldtxq(&adap->sge, i) {
struct sge_uld_txq *txq = &txq_info->uldtxq[i];
sync_txq_pidx(adap, &txq->q);
}
}
}
for_each_port(adap, i)
sync_txq_pidx(adap, &adap->sge.ctrlq[i].q);
}
static void process_db_drop(struct work_struct *work)
{
struct adapter *adap;
adap = container_of(work, struct adapter, db_drop_task);
if (is_t4(adap->params.chip)) {
drain_db_fifo(adap, dbfifo_drain_delay);
notify_rdma_uld(adap, CXGB4_CONTROL_DB_DROP);
drain_db_fifo(adap, dbfifo_drain_delay);
recover_all_queues(adap);
drain_db_fifo(adap, dbfifo_drain_delay);
enable_dbs(adap);
notify_rdma_uld(adap, CXGB4_CONTROL_DB_EMPTY);
} else if (is_t5(adap->params.chip)) {
u32 dropped_db = t4_read_reg(adap, 0x010ac);
u16 qid = (dropped_db >> 15) & 0x1ffff;
u16 pidx_inc = dropped_db & 0x1fff;
u64 bar2_qoffset;
unsigned int bar2_qid;
int ret;
ret = t4_bar2_sge_qregs(adap, qid, T4_BAR2_QTYPE_EGRESS,
0, &bar2_qoffset, &bar2_qid);
if (ret)
dev_err(adap->pdev_dev, "doorbell drop recovery: "
"qid=%d, pidx_inc=%d\n", qid, pidx_inc);
else
writel(PIDX_T5_V(pidx_inc) | QID_V(bar2_qid),
adap->bar2 + bar2_qoffset + SGE_UDB_KDOORBELL);
t4_set_reg_field(adap, 0x10b0, 1<<15, 1<<15);
}
if (CHELSIO_CHIP_VERSION(adap->params.chip) <= CHELSIO_T5)
t4_set_reg_field(adap, SGE_DOORBELL_CONTROL_A, DROPPED_DB_F, 0);
}
void t4_db_full(struct adapter *adap)
{
if (is_t4(adap->params.chip)) {
disable_dbs(adap);
notify_rdma_uld(adap, CXGB4_CONTROL_DB_FULL);
t4_set_reg_field(adap, SGE_INT_ENABLE3_A,
DBFIFO_HP_INT_F | DBFIFO_LP_INT_F, 0);
queue_work(adap->workq, &adap->db_full_task);
}
}
void t4_db_dropped(struct adapter *adap)
{
if (is_t4(adap->params.chip)) {
disable_dbs(adap);
notify_rdma_uld(adap, CXGB4_CONTROL_DB_FULL);
}
queue_work(adap->workq, &adap->db_drop_task);
}
void t4_register_netevent_notifier(void)
{
if (!netevent_registered) {
register_netevent_notifier(&cxgb4_netevent_nb);
netevent_registered = true;
}
}
static void detach_ulds(struct adapter *adap)
{
unsigned int i;
mutex_lock(&uld_mutex);
list_del(&adap->list_node);
for (i = 0; i < CXGB4_ULD_MAX; i++)
if (adap->uld && adap->uld[i].handle)
adap->uld[i].state_change(adap->uld[i].handle,
CXGB4_STATE_DETACH);
if (netevent_registered && list_empty(&adapter_list)) {
unregister_netevent_notifier(&cxgb4_netevent_nb);
netevent_registered = false;
}
mutex_unlock(&uld_mutex);
}
static void notify_ulds(struct adapter *adap, enum cxgb4_state new_state)
{
unsigned int i;
mutex_lock(&uld_mutex);
for (i = 0; i < CXGB4_ULD_MAX; i++)
if (adap->uld && adap->uld[i].handle)
adap->uld[i].state_change(adap->uld[i].handle,
new_state);
mutex_unlock(&uld_mutex);
}
static int cxgb4_inet6addr_handler(struct notifier_block *this,
unsigned long event, void *data)
{
struct inet6_ifaddr *ifa = data;
struct net_device *event_dev = ifa->idev->dev;
const struct device *parent = NULL;
#if IS_ENABLED(CONFIG_BONDING)
struct adapter *adap;
#endif
if (is_vlan_dev(event_dev))
event_dev = vlan_dev_real_dev(event_dev);
#if IS_ENABLED(CONFIG_BONDING)
if (event_dev->flags & IFF_MASTER) {
list_for_each_entry(adap, &adapter_list, list_node) {
switch (event) {
case NETDEV_UP:
cxgb4_clip_get(adap->port[0],
(const u32 *)ifa, 1);
break;
case NETDEV_DOWN:
cxgb4_clip_release(adap->port[0],
(const u32 *)ifa, 1);
break;
default:
break;
}
}
return NOTIFY_OK;
}
#endif
if (event_dev)
parent = event_dev->dev.parent;
if (parent && parent->driver == &cxgb4_driver.driver) {
switch (event) {
case NETDEV_UP:
cxgb4_clip_get(event_dev, (const u32 *)ifa, 1);
break;
case NETDEV_DOWN:
cxgb4_clip_release(event_dev, (const u32 *)ifa, 1);
break;
default:
break;
}
}
return NOTIFY_OK;
}
static void update_clip(const struct adapter *adap)
{
int i;
struct net_device *dev;
int ret;
rcu_read_lock();
for (i = 0; i < MAX_NPORTS; i++) {
dev = adap->port[i];
ret = 0;
if (dev)
ret = cxgb4_update_root_dev_clip(dev);
if (ret < 0)
break;
}
rcu_read_unlock();
}
static int cxgb_up(struct adapter *adap)
{
int err;
mutex_lock(&uld_mutex);
err = setup_sge_queues(adap);
if (err)
goto rel_lock;
err = setup_rss(adap);
if (err)
goto freeq;
if (adap->flags & USING_MSIX) {
name_msix_vecs(adap);
err = request_irq(adap->msix_info[0].vec, t4_nondata_intr, 0,
adap->msix_info[0].desc, adap);
if (err)
goto irq_err;
err = request_msix_queue_irqs(adap);
if (err) {
free_irq(adap->msix_info[0].vec, adap);
goto irq_err;
}
} else {
err = request_irq(adap->pdev->irq, t4_intr_handler(adap),
(adap->flags & USING_MSI) ? 0 : IRQF_SHARED,
adap->port[0]->name, adap);
if (err)
goto irq_err;
}
enable_rx(adap);
t4_sge_start(adap);
t4_intr_enable(adap);
adap->flags |= FULL_INIT_DONE;
mutex_unlock(&uld_mutex);
notify_ulds(adap, CXGB4_STATE_UP);
#if IS_ENABLED(CONFIG_IPV6)
update_clip(adap);
#endif
INIT_LIST_HEAD(&adap->mac_hlist);
return err;
irq_err:
dev_err(adap->pdev_dev, "request_irq failed, err %d\n", err);
freeq:
t4_free_sge_resources(adap);
rel_lock:
mutex_unlock(&uld_mutex);
return err;
}
static void cxgb_down(struct adapter *adapter)
{
cancel_work_sync(&adapter->tid_release_task);
cancel_work_sync(&adapter->db_full_task);
cancel_work_sync(&adapter->db_drop_task);
adapter->tid_release_task_busy = false;
adapter->tid_release_head = NULL;
t4_sge_stop(adapter);
t4_free_sge_resources(adapter);
adapter->flags &= ~FULL_INIT_DONE;
}
static int cxgb_open(struct net_device *dev)
{
int err;
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
netif_carrier_off(dev);
if (!(adapter->flags & FULL_INIT_DONE)) {
err = cxgb_up(adapter);
if (err < 0)
return err;
}
err = t4_update_port_info(pi);
if (err < 0)
return err;
err = link_start(dev);
if (!err)
netif_tx_start_all_queues(dev);
return err;
}
static int cxgb_close(struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
netif_tx_stop_all_queues(dev);
netif_carrier_off(dev);
return t4_enable_vi(adapter, adapter->pf, pi->viid, false, false);
}
int cxgb4_create_server_filter(const struct net_device *dev, unsigned int stid,
__be32 sip, __be16 sport, __be16 vlan,
unsigned int queue, unsigned char port, unsigned char mask)
{
int ret;
struct filter_entry *f;
struct adapter *adap;
int i;
u8 *val;
adap = netdev2adap(dev);
stid -= adap->tids.sftid_base;
stid += adap->tids.nftids;
f = &adap->tids.ftid_tab[stid];
ret = writable_filter(f);
if (ret)
return ret;
if (f->valid)
clear_filter(adap, f);
memset(&f->fs, 0, sizeof(struct ch_filter_specification));
f->fs.val.lport = cpu_to_be16(sport);
f->fs.mask.lport = ~0;
val = (u8 *)&sip;
if ((val[0] | val[1] | val[2] | val[3]) != 0) {
for (i = 0; i < 4; i++) {
f->fs.val.lip[i] = val[i];
f->fs.mask.lip[i] = ~0;
}
if (adap->params.tp.vlan_pri_map & PORT_F) {
f->fs.val.iport = port;
f->fs.mask.iport = mask;
}
}
if (adap->params.tp.vlan_pri_map & PROTOCOL_F) {
f->fs.val.proto = IPPROTO_TCP;
f->fs.mask.proto = ~0;
}
f->fs.dirsteer = 1;
f->fs.iq = queue;
f->locked = 1;
f->fs.rpttid = 1;
f->tid = stid + adap->tids.ftid_base;
ret = set_filter_wr(adap, stid);
if (ret) {
clear_filter(adap, f);
return ret;
}
return 0;
}
int cxgb4_remove_server_filter(const struct net_device *dev, unsigned int stid,
unsigned int queue, bool ipv6)
{
struct filter_entry *f;
struct adapter *adap;
adap = netdev2adap(dev);
stid -= adap->tids.sftid_base;
stid += adap->tids.nftids;
f = &adap->tids.ftid_tab[stid];
f->locked = 0;
return delete_filter(adap, stid);
}
static void cxgb_get_stats(struct net_device *dev,
struct rtnl_link_stats64 *ns)
{
struct port_stats stats;
struct port_info *p = netdev_priv(dev);
struct adapter *adapter = p->adapter;
spin_lock(&adapter->stats_lock);
if (!netif_device_present(dev)) {
spin_unlock(&adapter->stats_lock);
return;
}
t4_get_port_stats_offset(adapter, p->tx_chan, &stats,
&p->stats_base);
spin_unlock(&adapter->stats_lock);
ns->tx_bytes = stats.tx_octets;
ns->tx_packets = stats.tx_frames;
ns->rx_bytes = stats.rx_octets;
ns->rx_packets = stats.rx_frames;
ns->multicast = stats.rx_mcast_frames;
ns->rx_length_errors = stats.rx_jabber + stats.rx_too_long +
stats.rx_runt;
ns->rx_over_errors = 0;
ns->rx_crc_errors = stats.rx_fcs_err;
ns->rx_frame_errors = stats.rx_symbol_err;
ns->rx_dropped = stats.rx_ovflow0 + stats.rx_ovflow1 +
stats.rx_ovflow2 + stats.rx_ovflow3 +
stats.rx_trunc0 + stats.rx_trunc1 +
stats.rx_trunc2 + stats.rx_trunc3;
ns->rx_missed_errors = 0;
ns->tx_aborted_errors = 0;
ns->tx_carrier_errors = 0;
ns->tx_fifo_errors = 0;
ns->tx_heartbeat_errors = 0;
ns->tx_window_errors = 0;
ns->tx_errors = stats.tx_error_frames;
ns->rx_errors = stats.rx_symbol_err + stats.rx_fcs_err +
ns->rx_length_errors + stats.rx_len_err + ns->rx_fifo_errors;
}
static int cxgb_ioctl(struct net_device *dev, struct ifreq *req, int cmd)
{
unsigned int mbox;
int ret = 0, prtad, devad;
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
struct mii_ioctl_data *data = (struct mii_ioctl_data *)&req->ifr_data;
switch (cmd) {
case SIOCGMIIPHY:
if (pi->mdio_addr < 0)
return -EOPNOTSUPP;
data->phy_id = pi->mdio_addr;
break;
case SIOCGMIIREG:
case SIOCSMIIREG:
if (mdio_phy_id_is_c45(data->phy_id)) {
prtad = mdio_phy_id_prtad(data->phy_id);
devad = mdio_phy_id_devad(data->phy_id);
} else if (data->phy_id < 32) {
prtad = data->phy_id;
devad = 0;
data->reg_num &= 0x1f;
} else
return -EINVAL;
mbox = pi->adapter->pf;
if (cmd == SIOCGMIIREG)
ret = t4_mdio_rd(pi->adapter, mbox, prtad, devad,
data->reg_num, &data->val_out);
else
ret = t4_mdio_wr(pi->adapter, mbox, prtad, devad,
data->reg_num, data->val_in);
break;
case SIOCGHWTSTAMP:
return copy_to_user(req->ifr_data, &pi->tstamp_config,
sizeof(pi->tstamp_config)) ?
-EFAULT : 0;
case SIOCSHWTSTAMP:
if (copy_from_user(&pi->tstamp_config, req->ifr_data,
sizeof(pi->tstamp_config)))
return -EFAULT;
if (!is_t4(adapter->params.chip)) {
switch (pi->tstamp_config.tx_type) {
case HWTSTAMP_TX_OFF:
case HWTSTAMP_TX_ON:
break;
default:
return -ERANGE;
}
switch (pi->tstamp_config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
pi->rxtstamp = false;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
cxgb4_ptprx_timestamping(pi, pi->port_id,
PTP_TS_L4);
break;
case HWTSTAMP_FILTER_PTP_V2_EVENT:
cxgb4_ptprx_timestamping(pi, pi->port_id,
PTP_TS_L2_L4);
break;
case HWTSTAMP_FILTER_ALL:
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
pi->rxtstamp = true;
break;
default:
pi->tstamp_config.rx_filter =
HWTSTAMP_FILTER_NONE;
return -ERANGE;
}
if ((pi->tstamp_config.tx_type == HWTSTAMP_TX_OFF) &&
(pi->tstamp_config.rx_filter ==
HWTSTAMP_FILTER_NONE)) {
if (cxgb4_ptp_txtype(adapter, pi->port_id) >= 0)
pi->ptp_enable = false;
}
if (pi->tstamp_config.rx_filter !=
HWTSTAMP_FILTER_NONE) {
if (cxgb4_ptp_redirect_rx_packet(adapter,
pi) >= 0)
pi->ptp_enable = true;
}
} else {
switch (pi->tstamp_config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
pi->rxtstamp = false;
break;
case HWTSTAMP_FILTER_ALL:
pi->rxtstamp = true;
break;
default:
pi->tstamp_config.rx_filter =
HWTSTAMP_FILTER_NONE;
return -ERANGE;
}
}
return copy_to_user(req->ifr_data, &pi->tstamp_config,
sizeof(pi->tstamp_config)) ?
-EFAULT : 0;
default:
return -EOPNOTSUPP;
}
return ret;
}
static void cxgb_set_rxmode(struct net_device *dev)
{
set_rxmode(dev, -1, false);
}
static int cxgb_change_mtu(struct net_device *dev, int new_mtu)
{
int ret;
struct port_info *pi = netdev_priv(dev);
ret = t4_set_rxmode(pi->adapter, pi->adapter->pf, pi->viid, new_mtu, -1,
-1, -1, -1, true);
if (!ret)
dev->mtu = new_mtu;
return ret;
}
static int dummy_open(struct net_device *dev)
{
netif_carrier_off(dev);
return 0;
}
static void fill_vf_station_mac_addr(struct adapter *adap)
{
unsigned int i;
u8 hw_addr[ETH_ALEN], macaddr[ETH_ALEN];
int err;
u8 *na;
u16 a, b;
err = t4_get_raw_vpd_params(adap, &adap->params.vpd);
if (!err) {
na = adap->params.vpd.na;
for (i = 0; i < ETH_ALEN; i++)
hw_addr[i] = (hex2val(na[2 * i + 0]) * 16 +
hex2val(na[2 * i + 1]));
a = (hw_addr[0] << 8) | hw_addr[1];
b = (hw_addr[1] << 8) | hw_addr[2];
a ^= b;
a |= 0x0200;
a &= ~0x0100;
macaddr[0] = a >> 8;
macaddr[1] = a & 0xff;
for (i = 2; i < 5; i++)
macaddr[i] = hw_addr[i + 1];
for (i = 0; i < adap->num_vfs; i++) {
macaddr[5] = adap->pf * 16 + i;
ether_addr_copy(adap->vfinfo[i].vf_mac_addr, macaddr);
}
}
}
static int cxgb_set_vf_mac(struct net_device *dev, int vf, u8 *mac)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adap = pi->adapter;
int ret;
if (!is_valid_ether_addr(mac)) {
dev_err(pi->adapter->pdev_dev,
"Invalid Ethernet address %pM for VF %d\n",
mac, vf);
return -EINVAL;
}
dev_info(pi->adapter->pdev_dev,
"Setting MAC %pM on VF %d\n", mac, vf);
ret = t4_set_vf_mac_acl(adap, vf + 1, 1, mac);
if (!ret)
ether_addr_copy(adap->vfinfo[vf].vf_mac_addr, mac);
return ret;
}
static int cxgb_get_vf_config(struct net_device *dev,
int vf, struct ifla_vf_info *ivi)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adap = pi->adapter;
if (vf >= adap->num_vfs)
return -EINVAL;
ivi->vf = vf;
ivi->max_tx_rate = adap->vfinfo[vf].tx_rate;
ivi->min_tx_rate = 0;
ether_addr_copy(ivi->mac, adap->vfinfo[vf].vf_mac_addr);
return 0;
}
static int cxgb_get_phys_port_id(struct net_device *dev,
struct netdev_phys_item_id *ppid)
{
struct port_info *pi = netdev_priv(dev);
unsigned int phy_port_id;
phy_port_id = pi->adapter->adap_idx * 10 + pi->port_id;
ppid->id_len = sizeof(phy_port_id);
memcpy(ppid->id, &phy_port_id, ppid->id_len);
return 0;
}
static int cxgb_set_vf_rate(struct net_device *dev, int vf, int min_tx_rate,
int max_tx_rate)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adap = pi->adapter;
unsigned int link_ok, speed, mtu;
u32 fw_pfvf, fw_class;
int class_id = vf;
int ret;
u16 pktsize;
if (vf >= adap->num_vfs)
return -EINVAL;
if (min_tx_rate) {
dev_err(adap->pdev_dev,
"Min tx rate (%d) (> 0) for VF %d is Invalid.\n",
min_tx_rate, vf);
return -EINVAL;
}
ret = t4_get_link_params(pi, &link_ok, &speed, &mtu);
if (ret != FW_SUCCESS) {
dev_err(adap->pdev_dev,
"Failed to get link information for VF %d\n", vf);
return -EINVAL;
}
if (!link_ok) {
dev_err(adap->pdev_dev, "Link down for VF %d\n", vf);
return -EINVAL;
}
if (max_tx_rate > speed) {
dev_err(adap->pdev_dev,
"Max tx rate %d for VF %d can't be > link-speed %u",
max_tx_rate, vf, speed);
return -EINVAL;
}
pktsize = mtu;
pktsize = pktsize - sizeof(struct ethhdr) - 4;
pktsize = pktsize - sizeof(struct iphdr) - sizeof(struct tcphdr);
ret = t4_sched_params(adap, SCHED_CLASS_TYPE_PACKET,
SCHED_CLASS_LEVEL_CL_RL,
SCHED_CLASS_MODE_CLASS,
SCHED_CLASS_RATEUNIT_BITS,
SCHED_CLASS_RATEMODE_ABS,
pi->tx_chan, class_id, 0,
max_tx_rate * 1000, 0, pktsize);
if (ret) {
dev_err(adap->pdev_dev, "Err %d for Traffic Class config\n",
ret);
return -EINVAL;
}
dev_info(adap->pdev_dev,
"Class %d with MSS %u configured with rate %u\n",
class_id, pktsize, max_tx_rate);
fw_pfvf = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_SCHEDCLASS_ETH));
fw_class = class_id;
ret = t4_set_params(adap, adap->mbox, adap->pf, vf + 1, 1, &fw_pfvf,
&fw_class);
if (ret) {
dev_err(adap->pdev_dev,
"Err %d in binding VF %d to Traffic Class %d\n",
ret, vf, class_id);
return -EINVAL;
}
dev_info(adap->pdev_dev, "PF %d VF %d is bound to Class %d\n",
adap->pf, vf, class_id);
adap->vfinfo[vf].tx_rate = max_tx_rate;
return 0;
}
static int cxgb_set_mac_addr(struct net_device *dev, void *p)
{
int ret;
struct sockaddr *addr = p;
struct port_info *pi = netdev_priv(dev);
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
ret = t4_change_mac(pi->adapter, pi->adapter->pf, pi->viid,
pi->xact_addr_filt, addr->sa_data, true, true);
if (ret < 0)
return ret;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
pi->xact_addr_filt = ret;
return 0;
}
static void cxgb_netpoll(struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adap = pi->adapter;
if (adap->flags & USING_MSIX) {
int i;
struct sge_eth_rxq *rx = &adap->sge.ethrxq[pi->first_qset];
for (i = pi->nqsets; i; i--, rx++)
t4_sge_intr_msix(0, &rx->rspq);
} else
t4_intr_handler(adap)(0, adap);
}
static int cxgb_set_tx_maxrate(struct net_device *dev, int index, u32 rate)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adap = pi->adapter;
struct sched_class *e;
struct ch_sched_params p;
struct ch_sched_queue qe;
u32 req_rate;
int err = 0;
if (!can_sched(dev))
return -ENOTSUPP;
if (index < 0 || index > pi->nqsets - 1)
return -EINVAL;
if (!(adap->flags & FULL_INIT_DONE)) {
dev_err(adap->pdev_dev,
"Failed to rate limit on queue %d. Link Down?\n",
index);
return -EINVAL;
}
req_rate = rate << 10;
if (req_rate >= SCHED_MAX_RATE_KBPS) {
dev_err(adap->pdev_dev,
"Invalid rate %u Mbps, Max rate is %u Gbps\n",
rate, SCHED_MAX_RATE_KBPS);
return -ERANGE;
}
memset(&qe, 0, sizeof(qe));
qe.queue = index;
qe.class = SCHED_CLS_NONE;
err = cxgb4_sched_class_unbind(dev, (void *)(&qe), SCHED_QUEUE);
if (err) {
dev_err(adap->pdev_dev,
"Unbinding Queue %d on port %d fail. Err: %d\n",
index, pi->port_id, err);
return err;
}
if (!req_rate)
return 0;
memset(&p, 0, sizeof(p));
p.type = SCHED_CLASS_TYPE_PACKET;
p.u.params.level = SCHED_CLASS_LEVEL_CL_RL;
p.u.params.mode = SCHED_CLASS_MODE_CLASS;
p.u.params.rateunit = SCHED_CLASS_RATEUNIT_BITS;
p.u.params.ratemode = SCHED_CLASS_RATEMODE_ABS;
p.u.params.channel = pi->tx_chan;
p.u.params.class = SCHED_CLS_NONE;
p.u.params.minrate = 0;
p.u.params.maxrate = req_rate;
p.u.params.weight = 0;
p.u.params.pktsize = dev->mtu;
e = cxgb4_sched_class_alloc(dev, &p);
if (!e)
return -ENOMEM;
memset(&qe, 0, sizeof(qe));
qe.queue = index;
qe.class = e->idx;
err = cxgb4_sched_class_bind(dev, (void *)(&qe), SCHED_QUEUE);
if (err)
dev_err(adap->pdev_dev,
"Queue rate limiting failed. Err: %d\n", err);
return err;
}
static int cxgb_setup_tc_cls_u32(struct net_device *dev,
struct tc_cls_u32_offload *cls_u32)
{
if (!is_classid_clsact_ingress(cls_u32->common.classid) ||
cls_u32->common.chain_index)
return -EOPNOTSUPP;
switch (cls_u32->command) {
case TC_CLSU32_NEW_KNODE:
case TC_CLSU32_REPLACE_KNODE:
return cxgb4_config_knode(dev, cls_u32);
case TC_CLSU32_DELETE_KNODE:
return cxgb4_delete_knode(dev, cls_u32);
default:
return -EOPNOTSUPP;
}
}
static int cxgb_setup_tc(struct net_device *dev, enum tc_setup_type type,
void *type_data)
{
struct port_info *pi = netdev2pinfo(dev);
struct adapter *adap = netdev2adap(dev);
if (!(adap->flags & FULL_INIT_DONE)) {
dev_err(adap->pdev_dev,
"Failed to setup tc on port %d. Link Down?\n",
pi->port_id);
return -EINVAL;
}
switch (type) {
case TC_SETUP_CLSU32:
return cxgb_setup_tc_cls_u32(dev, type_data);
default:
return -EOPNOTSUPP;
}
}
static netdev_features_t cxgb_fix_features(struct net_device *dev,
netdev_features_t features)
{
if (!(features & NETIF_F_RXCSUM))
features &= ~NETIF_F_GRO;
return features;
}
static void get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct adapter *adapter = netdev2adap(dev);
strlcpy(info->driver, cxgb4_driver_name, sizeof(info->driver));
strlcpy(info->version, cxgb4_driver_version,
sizeof(info->version));
strlcpy(info->bus_info, pci_name(adapter->pdev),
sizeof(info->bus_info));
}
void t4_fatal_err(struct adapter *adap)
{
int port;
if (pci_channel_offline(adap->pdev))
return;
t4_shutdown_adapter(adap);
for_each_port(adap, port) {
struct net_device *dev = adap->port[port];
if (!dev)
continue;
netif_tx_stop_all_queues(dev);
netif_carrier_off(dev);
}
dev_alert(adap->pdev_dev, "encountered fatal error, adapter stopped\n");
}
static void setup_memwin(struct adapter *adap)
{
u32 nic_win_base = t4_get_util_window(adap);
t4_setup_memwin(adap, nic_win_base, MEMWIN_NIC);
}
static void setup_memwin_rdma(struct adapter *adap)
{
if (adap->vres.ocq.size) {
u32 start;
unsigned int sz_kb;
start = t4_read_pcie_cfg4(adap, PCI_BASE_ADDRESS_2);
start &= PCI_BASE_ADDRESS_MEM_MASK;
start += OCQ_WIN_OFFSET(adap->pdev, &adap->vres);
sz_kb = roundup_pow_of_two(adap->vres.ocq.size) >> 10;
t4_write_reg(adap,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_BASE_WIN_A, 3),
start | BIR_V(1) | WINDOW_V(ilog2(sz_kb)));
t4_write_reg(adap,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_OFFSET_A, 3),
adap->vres.ocq.start);
t4_read_reg(adap,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_OFFSET_A, 3));
}
}
static int adap_init1(struct adapter *adap, struct fw_caps_config_cmd *c)
{
u32 v;
int ret;
memset(c, 0, sizeof(*c));
c->op_to_write = htonl(FW_CMD_OP_V(FW_CAPS_CONFIG_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F);
c->cfvalid_to_len16 = htonl(FW_LEN16(*c));
ret = t4_wr_mbox(adap, adap->mbox, c, sizeof(*c), c);
if (ret < 0)
return ret;
c->op_to_write = htonl(FW_CMD_OP_V(FW_CAPS_CONFIG_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F);
ret = t4_wr_mbox(adap, adap->mbox, c, sizeof(*c), NULL);
if (ret < 0)
return ret;
ret = t4_config_glbl_rss(adap, adap->pf,
FW_RSS_GLB_CONFIG_CMD_MODE_BASICVIRTUAL,
FW_RSS_GLB_CONFIG_CMD_TNLMAPEN_F |
FW_RSS_GLB_CONFIG_CMD_TNLALLLKP_F);
if (ret < 0)
return ret;
ret = t4_cfg_pfvf(adap, adap->mbox, adap->pf, 0, adap->sge.egr_sz, 64,
MAX_INGQ, 0, 0, 4, 0xf, 0xf, 16, FW_CMD_CAP_PF,
FW_CMD_CAP_PF);
if (ret < 0)
return ret;
t4_sge_init(adap);
t4_write_reg(adap, TP_SHIFT_CNT_A, 0x64f8849);
t4_write_reg(adap, ULP_RX_TDDP_PSZ_A, HPZ0_V(PAGE_SHIFT - 12));
t4_write_reg(adap, TP_PIO_ADDR_A, TP_INGRESS_CONFIG_A);
v = t4_read_reg(adap, TP_PIO_DATA_A);
t4_write_reg(adap, TP_PIO_DATA_A, v & ~CSUM_HAS_PSEUDO_HDR_F);
adap->params.tp.tx_modq_map = 0xE4;
t4_write_reg(adap, TP_TX_MOD_QUEUE_REQ_MAP_A,
TX_MOD_QUEUE_REQ_MAP_V(adap->params.tp.tx_modq_map));
v = 0x84218421;
t4_write_indirect(adap, TP_PIO_ADDR_A, TP_PIO_DATA_A,
&v, 1, TP_TX_SCHED_HDR_A);
t4_write_indirect(adap, TP_PIO_ADDR_A, TP_PIO_DATA_A,
&v, 1, TP_TX_SCHED_FIFO_A);
t4_write_indirect(adap, TP_PIO_ADDR_A, TP_PIO_DATA_A,
&v, 1, TP_TX_SCHED_PCMD_A);
#define T4_TX_MODQ_10G_WEIGHT_DEFAULT 16
if (is_offload(adap)) {
t4_write_reg(adap, TP_TX_MOD_QUEUE_WEIGHT0_A,
TX_MODQ_WEIGHT0_V(T4_TX_MODQ_10G_WEIGHT_DEFAULT) |
TX_MODQ_WEIGHT1_V(T4_TX_MODQ_10G_WEIGHT_DEFAULT) |
TX_MODQ_WEIGHT2_V(T4_TX_MODQ_10G_WEIGHT_DEFAULT) |
TX_MODQ_WEIGHT3_V(T4_TX_MODQ_10G_WEIGHT_DEFAULT));
t4_write_reg(adap, TP_TX_MOD_CHANNEL_WEIGHT_A,
TX_MODQ_WEIGHT0_V(T4_TX_MODQ_10G_WEIGHT_DEFAULT) |
TX_MODQ_WEIGHT1_V(T4_TX_MODQ_10G_WEIGHT_DEFAULT) |
TX_MODQ_WEIGHT2_V(T4_TX_MODQ_10G_WEIGHT_DEFAULT) |
TX_MODQ_WEIGHT3_V(T4_TX_MODQ_10G_WEIGHT_DEFAULT));
}
return t4_early_init(adap, adap->pf);
}
static int adap_init0_tweaks(struct adapter *adapter)
{
t4_fixup_host_params(adapter, PAGE_SIZE, L1_CACHE_BYTES);
if (rx_dma_offset != 2 && rx_dma_offset != 0) {
dev_err(&adapter->pdev->dev,
"Ignoring illegal rx_dma_offset=%d, using 2\n",
rx_dma_offset);
rx_dma_offset = 2;
}
t4_set_reg_field(adapter, SGE_CONTROL_A,
PKTSHIFT_V(PKTSHIFT_M),
PKTSHIFT_V(rx_dma_offset));
t4_tp_wr_bits_indirect(adapter, TP_INGRESS_CONFIG_A,
CSUM_HAS_PSEUDO_HDR_F, 0);
return 0;
}
static int phy_aq1202_version(const u8 *phy_fw_data,
size_t phy_fw_size)
{
int offset;
#define be16(__p) (((__p)[0] << 8) | (__p)[1])
#define le16(__p) ((__p)[0] | ((__p)[1] << 8))
#define le24(__p) (le16(__p) | ((__p)[2] << 16))
offset = le24(phy_fw_data + 0x8) << 12;
offset = le24(phy_fw_data + offset + 0xa);
return be16(phy_fw_data + offset + 0x27e);
#undef be16
#undef le16
#undef le24
}
static struct info_10gbt_phy_fw *find_phy_info(int devid)
{
int i;
for (i = 0; i < ARRAY_SIZE(phy_info_array); i++) {
if (phy_info_array[i].phy_fw_id == devid)
return &phy_info_array[i];
}
return NULL;
}
static int adap_init0_phy(struct adapter *adap)
{
const struct firmware *phyf;
int ret;
struct info_10gbt_phy_fw *phy_info;
phy_info = find_phy_info(adap->pdev->device);
if (!phy_info) {
dev_warn(adap->pdev_dev,
"No PHY Firmware file found for this PHY\n");
return -EOPNOTSUPP;
}
ret = request_firmware_direct(&phyf, phy_info->phy_fw_file,
adap->pdev_dev);
if (ret < 0) {
dev_err(adap->pdev_dev, "unable to find PHY Firmware image "
"/lib/firmware/%s, error %d\n",
phy_info->phy_fw_file, -ret);
if (phy_info->phy_flash) {
int cur_phy_fw_ver = 0;
t4_phy_fw_ver(adap, &cur_phy_fw_ver);
dev_warn(adap->pdev_dev, "continuing with, on-adapter "
"FLASH copy, version %#x\n", cur_phy_fw_ver);
ret = 0;
}
return ret;
}
ret = t4_load_phy_fw(adap, MEMWIN_NIC, &adap->win0_lock,
phy_info->phy_fw_version,
(u8 *)phyf->data, phyf->size);
if (ret < 0)
dev_err(adap->pdev_dev, "PHY Firmware transfer error %d\n",
-ret);
else if (ret > 0) {
int new_phy_fw_ver = 0;
if (phy_info->phy_fw_version)
new_phy_fw_ver = phy_info->phy_fw_version(phyf->data,
phyf->size);
dev_info(adap->pdev_dev, "Successfully transferred PHY "
"Firmware /lib/firmware/%s, version %#x\n",
phy_info->phy_fw_file, new_phy_fw_ver);
}
release_firmware(phyf);
return ret;
}
static int adap_init0_config(struct adapter *adapter, int reset)
{
struct fw_caps_config_cmd caps_cmd;
const struct firmware *cf;
unsigned long mtype = 0, maddr = 0;
u32 finiver, finicsum, cfcsum;
int ret;
int config_issued = 0;
char *fw_config_file, fw_config_file_path[256];
char *config_name = NULL;
if (reset) {
ret = t4_fw_reset(adapter, adapter->mbox,
PIORSTMODE_F | PIORST_F);
if (ret < 0)
goto bye;
}
if (is_10gbt_device(adapter->pdev->device)) {
ret = adap_init0_phy(adapter);
if (ret < 0)
goto bye;
}
switch (CHELSIO_CHIP_VERSION(adapter->params.chip)) {
case CHELSIO_T4:
fw_config_file = FW4_CFNAME;
break;
case CHELSIO_T5:
fw_config_file = FW5_CFNAME;
break;
case CHELSIO_T6:
fw_config_file = FW6_CFNAME;
break;
default:
dev_err(adapter->pdev_dev, "Device %d is not supported\n",
adapter->pdev->device);
ret = -EINVAL;
goto bye;
}
ret = request_firmware(&cf, fw_config_file, adapter->pdev_dev);
if (ret < 0) {
config_name = "On FLASH";
mtype = FW_MEMTYPE_CF_FLASH;
maddr = t4_flash_cfg_addr(adapter);
} else {
u32 params[7], val[7];
sprintf(fw_config_file_path,
"/lib/firmware/%s", fw_config_file);
config_name = fw_config_file_path;
if (cf->size >= FLASH_CFG_MAX_SIZE)
ret = -ENOMEM;
else {
params[0] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_CF));
ret = t4_query_params(adapter, adapter->mbox,
adapter->pf, 0, 1, params, val);
if (ret == 0) {
size_t resid = cf->size & 0x3;
size_t size = cf->size & ~0x3;
__be32 *data = (__be32 *)cf->data;
mtype = FW_PARAMS_PARAM_Y_G(val[0]);
maddr = FW_PARAMS_PARAM_Z_G(val[0]) << 16;
spin_lock(&adapter->win0_lock);
ret = t4_memory_rw(adapter, 0, mtype, maddr,
size, data, T4_MEMORY_WRITE);
if (ret == 0 && resid != 0) {
union {
__be32 word;
char buf[4];
} last;
int i;
last.word = data[size >> 2];
for (i = resid; i < 4; i++)
last.buf[i] = 0;
ret = t4_memory_rw(adapter, 0, mtype,
maddr + size,
4, &last.word,
T4_MEMORY_WRITE);
}
spin_unlock(&adapter->win0_lock);
}
}
release_firmware(cf);
if (ret)
goto bye;
}
memset(&caps_cmd, 0, sizeof(caps_cmd));
caps_cmd.op_to_write =
htonl(FW_CMD_OP_V(FW_CAPS_CONFIG_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F);
caps_cmd.cfvalid_to_len16 =
htonl(FW_CAPS_CONFIG_CMD_CFVALID_F |
FW_CAPS_CONFIG_CMD_MEMTYPE_CF_V(mtype) |
FW_CAPS_CONFIG_CMD_MEMADDR64K_CF_V(maddr >> 16) |
FW_LEN16(caps_cmd));
ret = t4_wr_mbox(adapter, adapter->mbox, &caps_cmd, sizeof(caps_cmd),
&caps_cmd);
if (ret == -ENOENT) {
memset(&caps_cmd, 0, sizeof(caps_cmd));
caps_cmd.op_to_write =
htonl(FW_CMD_OP_V(FW_CAPS_CONFIG_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F);
caps_cmd.cfvalid_to_len16 = htonl(FW_LEN16(caps_cmd));
ret = t4_wr_mbox(adapter, adapter->mbox, &caps_cmd,
sizeof(caps_cmd), &caps_cmd);
config_name = "Firmware Default";
}
config_issued = 1;
if (ret < 0)
goto bye;
finiver = ntohl(caps_cmd.finiver);
finicsum = ntohl(caps_cmd.finicsum);
cfcsum = ntohl(caps_cmd.cfcsum);
if (finicsum != cfcsum)
dev_warn(adapter->pdev_dev, "Configuration File checksum "\
"mismatch: [fini] csum=%#x, computed csum=%#x\n",
finicsum, cfcsum);
caps_cmd.op_to_write =
htonl(FW_CMD_OP_V(FW_CAPS_CONFIG_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F);
caps_cmd.cfvalid_to_len16 = htonl(FW_LEN16(caps_cmd));
ret = t4_wr_mbox(adapter, adapter->mbox, &caps_cmd, sizeof(caps_cmd),
NULL);
if (ret < 0)
goto bye;
ret = adap_init0_tweaks(adapter);
if (ret < 0)
goto bye;
ret = t4_fw_initialize(adapter, adapter->mbox);
if (ret < 0)
goto bye;
dev_info(adapter->pdev_dev, "Successfully configured using Firmware "\
"Configuration File \"%s\", version %#x, computed checksum %#x\n",
config_name, finiver, cfcsum);
return 0;
bye:
if (config_issued && ret != -ENOENT)
dev_warn(adapter->pdev_dev, "\"%s\" configuration file error %d\n",
config_name, -ret);
return ret;
}
static struct fw_info *find_fw_info(int chip)
{
int i;
for (i = 0; i < ARRAY_SIZE(fw_info_array); i++) {
if (fw_info_array[i].chip == chip)
return &fw_info_array[i];
}
return NULL;
}
static int adap_init0(struct adapter *adap)
{
int ret;
u32 v, port_vec;
enum dev_state state;
u32 params[7], val[7];
struct fw_caps_config_cmd caps_cmd;
int reset = 1;
ret = t4_init_devlog_params(adap);
if (ret < 0)
return ret;
ret = t4_fw_hello(adap, adap->mbox, adap->mbox,
is_kdump_kernel() ? MASTER_MUST : MASTER_MAY, &state);
if (ret < 0) {
dev_err(adap->pdev_dev, "could not connect to FW, error %d\n",
ret);
return ret;
}
if (ret == adap->mbox)
adap->flags |= MASTER_PF;
t4_get_version_info(adap);
ret = t4_check_fw_version(adap);
if (ret)
state = DEV_STATE_UNINIT;
if ((adap->flags & MASTER_PF) && state != DEV_STATE_INIT) {
struct fw_info *fw_info;
struct fw_hdr *card_fw;
const struct firmware *fw;
const u8 *fw_data = NULL;
unsigned int fw_size = 0;
fw_info = find_fw_info(CHELSIO_CHIP_VERSION(adap->params.chip));
if (fw_info == NULL) {
dev_err(adap->pdev_dev,
"unable to get firmware info for chip %d.\n",
CHELSIO_CHIP_VERSION(adap->params.chip));
return -EINVAL;
}
card_fw = kvzalloc(sizeof(*card_fw), GFP_KERNEL);
ret = request_firmware(&fw, fw_info->fw_mod_name,
adap->pdev_dev);
if (ret < 0) {
dev_err(adap->pdev_dev,
"unable to load firmware image %s, error %d\n",
fw_info->fw_mod_name, ret);
} else {
fw_data = fw->data;
fw_size = fw->size;
}
ret = t4_prep_fw(adap, fw_info, fw_data, fw_size, card_fw,
state, &reset);
release_firmware(fw);
kvfree(card_fw);
if (ret < 0)
goto bye;
}
ret = t4_get_vpd_params(adap, &adap->params.vpd);
if (ret < 0)
goto bye;
v =
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_PORTVEC);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 1, &v, &port_vec);
if (ret < 0)
goto bye;
adap->params.nports = hweight32(port_vec);
adap->params.portvec = port_vec;
if (state == DEV_STATE_INIT) {
dev_info(adap->pdev_dev, "Coming up as %s: "\
"Adapter already initialized\n",
adap->flags & MASTER_PF ? "MASTER" : "SLAVE");
} else {
dev_info(adap->pdev_dev, "Coming up as MASTER: "\
"Initializing adapter\n");
params[0] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_CF));
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 1,
params, val);
if (ret < 0) {
dev_err(adap->pdev_dev, "firmware doesn't support "
"Firmware Configuration Files\n");
goto bye;
}
ret = adap_init0_config(adap, reset);
if (ret == -ENOENT) {
dev_err(adap->pdev_dev, "no Configuration File "
"present on adapter.\n");
goto bye;
}
if (ret < 0) {
dev_err(adap->pdev_dev, "could not initialize "
"adapter, error %d\n", -ret);
goto bye;
}
}
ret = t4_sge_init(adap);
if (ret < 0)
goto bye;
if (is_bypass_device(adap->pdev->device))
adap->params.bypass = 1;
#define FW_PARAM_DEV(param) \
(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_##param))
#define FW_PARAM_PFVF(param) \
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_PFVF) | \
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_PFVF_##param)| \
FW_PARAMS_PARAM_Y_V(0) | \
FW_PARAMS_PARAM_Z_V(0)
params[0] = FW_PARAM_PFVF(EQ_START);
params[1] = FW_PARAM_PFVF(L2T_START);
params[2] = FW_PARAM_PFVF(L2T_END);
params[3] = FW_PARAM_PFVF(FILTER_START);
params[4] = FW_PARAM_PFVF(FILTER_END);
params[5] = FW_PARAM_PFVF(IQFLINT_START);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 6, params, val);
if (ret < 0)
goto bye;
adap->sge.egr_start = val[0];
adap->l2t_start = val[1];
adap->l2t_end = val[2];
adap->tids.ftid_base = val[3];
adap->tids.nftids = val[4] - val[3] + 1;
adap->sge.ingr_start = val[5];
params[0] = FW_PARAM_PFVF(EQ_END);
params[1] = FW_PARAM_PFVF(IQFLINT_END);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 2, params, val);
if (ret < 0)
goto bye;
adap->sge.egr_sz = val[0] - adap->sge.egr_start + 1;
adap->sge.ingr_sz = val[1] - adap->sge.ingr_start + 1;
adap->sge.egr_map = kcalloc(adap->sge.egr_sz,
sizeof(*adap->sge.egr_map), GFP_KERNEL);
if (!adap->sge.egr_map) {
ret = -ENOMEM;
goto bye;
}
adap->sge.ingr_map = kcalloc(adap->sge.ingr_sz,
sizeof(*adap->sge.ingr_map), GFP_KERNEL);
if (!adap->sge.ingr_map) {
ret = -ENOMEM;
goto bye;
}
adap->sge.starving_fl = kcalloc(BITS_TO_LONGS(adap->sge.egr_sz),
sizeof(long), GFP_KERNEL);
if (!adap->sge.starving_fl) {
ret = -ENOMEM;
goto bye;
}
adap->sge.txq_maperr = kcalloc(BITS_TO_LONGS(adap->sge.egr_sz),
sizeof(long), GFP_KERNEL);
if (!adap->sge.txq_maperr) {
ret = -ENOMEM;
goto bye;
}
#ifdef CONFIG_DEBUG_FS
adap->sge.blocked_fl = kcalloc(BITS_TO_LONGS(adap->sge.egr_sz),
sizeof(long), GFP_KERNEL);
if (!adap->sge.blocked_fl) {
ret = -ENOMEM;
goto bye;
}
#endif
params[0] = FW_PARAM_PFVF(CLIP_START);
params[1] = FW_PARAM_PFVF(CLIP_END);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 2, params, val);
if (ret < 0)
goto bye;
adap->clipt_start = val[0];
adap->clipt_end = val[1];
adap->params.nsched_cls = is_t4(adap->params.chip) ? 15 : 16;
params[0] = FW_PARAM_PFVF(ACTIVE_FILTER_START);
params[1] = FW_PARAM_PFVF(ACTIVE_FILTER_END);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 2, params, val);
if ((val[0] != val[1]) && (ret >= 0)) {
adap->flags |= FW_OFLD_CONN;
adap->tids.aftid_base = val[0];
adap->tids.aftid_end = val[1];
}
params[0] = FW_PARAM_PFVF(CPLFW4MSG_ENCAP);
val[0] = 1;
(void)t4_set_params(adap, adap->mbox, adap->pf, 0, 1, params, val);
if (is_t4(adap->params.chip)) {
adap->params.ulptx_memwrite_dsgl = false;
} else {
params[0] = FW_PARAM_DEV(ULPTX_MEMWRITE_DSGL);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0,
1, params, val);
adap->params.ulptx_memwrite_dsgl = (ret == 0 && val[0] != 0);
}
params[0] = FW_PARAM_DEV(RI_FR_NSMR_TPTE_WR);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0,
1, params, val);
adap->params.fr_nsmr_tpte_wr_support = (ret == 0 && val[0] != 0);
memset(&caps_cmd, 0, sizeof(caps_cmd));
caps_cmd.op_to_write = htonl(FW_CMD_OP_V(FW_CAPS_CONFIG_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F);
caps_cmd.cfvalid_to_len16 = htonl(FW_LEN16(caps_cmd));
ret = t4_wr_mbox(adap, adap->mbox, &caps_cmd, sizeof(caps_cmd),
&caps_cmd);
if (ret < 0)
goto bye;
if (caps_cmd.ofldcaps) {
params[0] = FW_PARAM_DEV(NTID);
params[1] = FW_PARAM_PFVF(SERVER_START);
params[2] = FW_PARAM_PFVF(SERVER_END);
params[3] = FW_PARAM_PFVF(TDDP_START);
params[4] = FW_PARAM_PFVF(TDDP_END);
params[5] = FW_PARAM_DEV(FLOWC_BUFFIFO_SZ);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 6,
params, val);
if (ret < 0)
goto bye;
adap->tids.ntids = val[0];
adap->tids.natids = min(adap->tids.ntids / 2, MAX_ATIDS);
adap->tids.stid_base = val[1];
adap->tids.nstids = val[2] - val[1] + 1;
if (adap->flags & FW_OFLD_CONN && !is_bypass(adap)) {
adap->tids.sftid_base = adap->tids.ftid_base +
DIV_ROUND_UP(adap->tids.nftids, 3);
adap->tids.nsftids = adap->tids.nftids -
DIV_ROUND_UP(adap->tids.nftids, 3);
adap->tids.nftids = adap->tids.sftid_base -
adap->tids.ftid_base;
}
adap->vres.ddp.start = val[3];
adap->vres.ddp.size = val[4] - val[3] + 1;
adap->params.ofldq_wr_cred = val[5];
adap->params.offload = 1;
adap->num_ofld_uld += 1;
}
if (caps_cmd.rdmacaps) {
params[0] = FW_PARAM_PFVF(STAG_START);
params[1] = FW_PARAM_PFVF(STAG_END);
params[2] = FW_PARAM_PFVF(RQ_START);
params[3] = FW_PARAM_PFVF(RQ_END);
params[4] = FW_PARAM_PFVF(PBL_START);
params[5] = FW_PARAM_PFVF(PBL_END);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 6,
params, val);
if (ret < 0)
goto bye;
adap->vres.stag.start = val[0];
adap->vres.stag.size = val[1] - val[0] + 1;
adap->vres.rq.start = val[2];
adap->vres.rq.size = val[3] - val[2] + 1;
adap->vres.pbl.start = val[4];
adap->vres.pbl.size = val[5] - val[4] + 1;
params[0] = FW_PARAM_PFVF(SQRQ_START);
params[1] = FW_PARAM_PFVF(SQRQ_END);
params[2] = FW_PARAM_PFVF(CQ_START);
params[3] = FW_PARAM_PFVF(CQ_END);
params[4] = FW_PARAM_PFVF(OCQ_START);
params[5] = FW_PARAM_PFVF(OCQ_END);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 6, params,
val);
if (ret < 0)
goto bye;
adap->vres.qp.start = val[0];
adap->vres.qp.size = val[1] - val[0] + 1;
adap->vres.cq.start = val[2];
adap->vres.cq.size = val[3] - val[2] + 1;
adap->vres.ocq.start = val[4];
adap->vres.ocq.size = val[5] - val[4] + 1;
params[0] = FW_PARAM_DEV(MAXORDIRD_QP);
params[1] = FW_PARAM_DEV(MAXIRD_ADAPTER);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 2, params,
val);
if (ret < 0) {
adap->params.max_ordird_qp = 8;
adap->params.max_ird_adapter = 32 * adap->tids.ntids;
ret = 0;
} else {
adap->params.max_ordird_qp = val[0];
adap->params.max_ird_adapter = val[1];
}
dev_info(adap->pdev_dev,
"max_ordird_qp %d max_ird_adapter %d\n",
adap->params.max_ordird_qp,
adap->params.max_ird_adapter);
adap->num_ofld_uld += 2;
}
if (caps_cmd.iscsicaps) {
params[0] = FW_PARAM_PFVF(ISCSI_START);
params[1] = FW_PARAM_PFVF(ISCSI_END);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 2,
params, val);
if (ret < 0)
goto bye;
adap->vres.iscsi.start = val[0];
adap->vres.iscsi.size = val[1] - val[0] + 1;
adap->num_ofld_uld += 2;
}
if (caps_cmd.cryptocaps) {
params[0] = FW_PARAM_PFVF(NCRYPTO_LOOKASIDE);
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 2,
params, val);
if (ret < 0) {
if (ret != -EINVAL)
goto bye;
} else {
adap->vres.ncrypto_fc = val[0];
}
adap->params.crypto |= ULP_CRYPTO_LOOKASIDE;
adap->num_uld += 1;
}
#undef FW_PARAM_PFVF
#undef FW_PARAM_DEV
t4_read_mtu_tbl(adap, adap->params.mtus, NULL);
if (state != DEV_STATE_INIT) {
int i;
for (i = 0; i < NMTUS; i++)
if (adap->params.mtus[i] == 1492) {
adap->params.mtus[i] = 1488;
break;
}
t4_load_mtus(adap, adap->params.mtus, adap->params.a_wnd,
adap->params.b_wnd);
}
t4_init_sge_params(adap);
adap->flags |= FW_OK;
t4_init_tp_params(adap);
return 0;
bye:
kfree(adap->sge.egr_map);
kfree(adap->sge.ingr_map);
kfree(adap->sge.starving_fl);
kfree(adap->sge.txq_maperr);
#ifdef CONFIG_DEBUG_FS
kfree(adap->sge.blocked_fl);
#endif
if (ret != -ETIMEDOUT && ret != -EIO)
t4_fw_bye(adap, adap->mbox);
return ret;
}
static pci_ers_result_t eeh_err_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
int i;
struct adapter *adap = pci_get_drvdata(pdev);
if (!adap)
goto out;
rtnl_lock();
adap->flags &= ~FW_OK;
notify_ulds(adap, CXGB4_STATE_START_RECOVERY);
spin_lock(&adap->stats_lock);
for_each_port(adap, i) {
struct net_device *dev = adap->port[i];
if (dev) {
netif_device_detach(dev);
netif_carrier_off(dev);
}
}
spin_unlock(&adap->stats_lock);
disable_interrupts(adap);
if (adap->flags & FULL_INIT_DONE)
cxgb_down(adap);
rtnl_unlock();
if ((adap->flags & DEV_ENABLED)) {
pci_disable_device(pdev);
adap->flags &= ~DEV_ENABLED;
}
out: return state == pci_channel_io_perm_failure ?
PCI_ERS_RESULT_DISCONNECT : PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t eeh_slot_reset(struct pci_dev *pdev)
{
int i, ret;
struct fw_caps_config_cmd c;
struct adapter *adap = pci_get_drvdata(pdev);
if (!adap) {
pci_restore_state(pdev);
pci_save_state(pdev);
return PCI_ERS_RESULT_RECOVERED;
}
if (!(adap->flags & DEV_ENABLED)) {
if (pci_enable_device(pdev)) {
dev_err(&pdev->dev, "Cannot reenable PCI "
"device after reset\n");
return PCI_ERS_RESULT_DISCONNECT;
}
adap->flags |= DEV_ENABLED;
}
pci_set_master(pdev);
pci_restore_state(pdev);
pci_save_state(pdev);
pci_cleanup_aer_uncorrect_error_status(pdev);
if (t4_wait_dev_ready(adap->regs) < 0)
return PCI_ERS_RESULT_DISCONNECT;
if (t4_fw_hello(adap, adap->mbox, adap->pf, MASTER_MUST, NULL) < 0)
return PCI_ERS_RESULT_DISCONNECT;
adap->flags |= FW_OK;
if (adap_init1(adap, &c))
return PCI_ERS_RESULT_DISCONNECT;
for_each_port(adap, i) {
struct port_info *p = adap2pinfo(adap, i);
ret = t4_alloc_vi(adap, adap->mbox, p->tx_chan, adap->pf, 0, 1,
NULL, NULL);
if (ret < 0)
return PCI_ERS_RESULT_DISCONNECT;
p->viid = ret;
p->xact_addr_filt = -1;
}
t4_load_mtus(adap, adap->params.mtus, adap->params.a_wnd,
adap->params.b_wnd);
setup_memwin(adap);
if (cxgb_up(adap))
return PCI_ERS_RESULT_DISCONNECT;
return PCI_ERS_RESULT_RECOVERED;
}
static void eeh_resume(struct pci_dev *pdev)
{
int i;
struct adapter *adap = pci_get_drvdata(pdev);
if (!adap)
return;
rtnl_lock();
for_each_port(adap, i) {
struct net_device *dev = adap->port[i];
if (dev) {
if (netif_running(dev)) {
link_start(dev);
cxgb_set_rxmode(dev);
}
netif_device_attach(dev);
}
}
rtnl_unlock();
}
static inline bool is_x_10g_port(const struct link_config *lc)
{
unsigned int speeds, high_speeds;
speeds = FW_PORT_CAP32_SPEED_V(FW_PORT_CAP32_SPEED_G(lc->pcaps));
high_speeds = speeds &
~(FW_PORT_CAP32_SPEED_100M | FW_PORT_CAP32_SPEED_1G);
return high_speeds != 0;
}
static void cfg_queues(struct adapter *adap)
{
struct sge *s = &adap->sge;
int i = 0, n10g = 0, qidx = 0;
#ifndef CONFIG_CHELSIO_T4_DCB
int q10g = 0;
#endif
if (is_kdump_kernel() || (is_uld(adap) && t4_uld_mem_alloc(adap))) {
adap->params.offload = 0;
adap->params.crypto = 0;
}
n10g += is_x_10g_port(&adap2pinfo(adap, i)->link_cfg);
#ifdef CONFIG_CHELSIO_T4_DCB
if (adap->params.nports * 8 > MAX_ETH_QSETS) {
dev_err(adap->pdev_dev, "MAX_ETH_QSETS=%d < %d!\n",
MAX_ETH_QSETS, adap->params.nports * 8);
BUG_ON(1);
}
for_each_port(adap, i) {
struct port_info *pi = adap2pinfo(adap, i);
pi->first_qset = qidx;
pi->nqsets = is_kdump_kernel() ? 1 : 8;
qidx += pi->nqsets;
}
#else
if (n10g)
q10g = (MAX_ETH_QSETS - (adap->params.nports - n10g)) / n10g;
if (q10g > netif_get_num_default_rss_queues())
q10g = netif_get_num_default_rss_queues();
if (is_kdump_kernel())
q10g = 1;
for_each_port(adap, i) {
struct port_info *pi = adap2pinfo(adap, i);
pi->first_qset = qidx;
pi->nqsets = is_x_10g_port(&pi->link_cfg) ? q10g : 1;
qidx += pi->nqsets;
}
#endif
s->ethqsets = qidx;
s->max_ethqsets = qidx;
if (is_uld(adap)) {
if (n10g) {
i = min_t(int, MAX_OFLD_QSETS, num_online_cpus());
s->ofldqsets = roundup(i, adap->params.nports);
} else {
s->ofldqsets = adap->params.nports;
}
}
for (i = 0; i < ARRAY_SIZE(s->ethrxq); i++) {
struct sge_eth_rxq *r = &s->ethrxq[i];
init_rspq(adap, &r->rspq, 5, 10, 1024, 64);
r->fl.size = 72;
}
for (i = 0; i < ARRAY_SIZE(s->ethtxq); i++)
s->ethtxq[i].q.size = 1024;
for (i = 0; i < ARRAY_SIZE(s->ctrlq); i++)
s->ctrlq[i].q.size = 512;
if (!is_t4(adap->params.chip))
s->ptptxq.q.size = 8;
init_rspq(adap, &s->fw_evtq, 0, 1, 1024, 64);
init_rspq(adap, &s->intrq, 0, 1, 512, 64);
}
static void reduce_ethqs(struct adapter *adap, int n)
{
int i;
struct port_info *pi;
while (n < adap->sge.ethqsets)
for_each_port(adap, i) {
pi = adap2pinfo(adap, i);
if (pi->nqsets > 1) {
pi->nqsets--;
adap->sge.ethqsets--;
if (adap->sge.ethqsets <= n)
break;
}
}
n = 0;
for_each_port(adap, i) {
pi = adap2pinfo(adap, i);
pi->first_qset = n;
n += pi->nqsets;
}
}
static int get_msix_info(struct adapter *adap)
{
struct uld_msix_info *msix_info;
unsigned int max_ingq = 0;
if (is_offload(adap))
max_ingq += MAX_OFLD_QSETS * adap->num_ofld_uld;
if (is_pci_uld(adap))
max_ingq += MAX_OFLD_QSETS * adap->num_uld;
if (!max_ingq)
goto out;
msix_info = kcalloc(max_ingq, sizeof(*msix_info), GFP_KERNEL);
if (!msix_info)
return -ENOMEM;
adap->msix_bmap_ulds.msix_bmap = kcalloc(BITS_TO_LONGS(max_ingq),
sizeof(long), GFP_KERNEL);
if (!adap->msix_bmap_ulds.msix_bmap) {
kfree(msix_info);
return -ENOMEM;
}
spin_lock_init(&adap->msix_bmap_ulds.lock);
adap->msix_info_ulds = msix_info;
out:
return 0;
}
static void free_msix_info(struct adapter *adap)
{
if (!(adap->num_uld && adap->num_ofld_uld))
return;
kfree(adap->msix_info_ulds);
kfree(adap->msix_bmap_ulds.msix_bmap);
}
static int enable_msix(struct adapter *adap)
{
int ofld_need = 0, uld_need = 0;
int i, j, want, need, allocated;
struct sge *s = &adap->sge;
unsigned int nchan = adap->params.nports;
struct msix_entry *entries;
int max_ingq = MAX_INGQ;
if (is_pci_uld(adap))
max_ingq += (MAX_OFLD_QSETS * adap->num_uld);
if (is_offload(adap))
max_ingq += (MAX_OFLD_QSETS * adap->num_ofld_uld);
entries = kmalloc(sizeof(*entries) * (max_ingq + 1),
GFP_KERNEL);
if (!entries)
return -ENOMEM;
if (get_msix_info(adap)) {
adap->params.offload = 0;
adap->params.crypto = 0;
}
for (i = 0; i < max_ingq + 1; ++i)
entries[i].entry = i;
want = s->max_ethqsets + EXTRA_VECS;
if (is_offload(adap)) {
want += adap->num_ofld_uld * s->ofldqsets;
ofld_need = adap->num_ofld_uld * nchan;
}
if (is_pci_uld(adap)) {
want += adap->num_uld * s->ofldqsets;
uld_need = adap->num_uld * nchan;
}
#ifdef CONFIG_CHELSIO_T4_DCB
need = 8 * adap->params.nports + EXTRA_VECS + ofld_need + uld_need;
#else
need = adap->params.nports + EXTRA_VECS + ofld_need + uld_need;
#endif
allocated = pci_enable_msix_range(adap->pdev, entries, need, want);
if (allocated < 0) {
dev_info(adap->pdev_dev, "not enough MSI-X vectors left,"
" not using MSI-X\n");
kfree(entries);
return allocated;
}
i = allocated - EXTRA_VECS - ofld_need - uld_need;
if (i < s->max_ethqsets) {
s->max_ethqsets = i;
if (i < s->ethqsets)
reduce_ethqs(adap, i);
}
if (is_uld(adap)) {
if (allocated < want)
s->nqs_per_uld = nchan;
else
s->nqs_per_uld = s->ofldqsets;
}
for (i = 0; i < (s->max_ethqsets + EXTRA_VECS); ++i)
adap->msix_info[i].vec = entries[i].vector;
if (is_uld(adap)) {
for (j = 0 ; i < allocated; ++i, j++) {
adap->msix_info_ulds[j].vec = entries[i].vector;
adap->msix_info_ulds[j].idx = i;
}
adap->msix_bmap_ulds.mapsize = j;
}
dev_info(adap->pdev_dev, "%d MSI-X vectors allocated, "
"nic %d per uld %d\n",
allocated, s->max_ethqsets, s->nqs_per_uld);
kfree(entries);
return 0;
}
static int init_rss(struct adapter *adap)
{
unsigned int i;
int err;
err = t4_init_rss_mode(adap, adap->mbox);
if (err)
return err;
for_each_port(adap, i) {
struct port_info *pi = adap2pinfo(adap, i);
pi->rss = kcalloc(pi->rss_size, sizeof(u16), GFP_KERNEL);
if (!pi->rss)
return -ENOMEM;
}
return 0;
}
static int cxgb4_get_pcie_dev_link_caps(struct adapter *adap,
enum pci_bus_speed *speed,
enum pcie_link_width *width)
{
u32 lnkcap1, lnkcap2;
int err1, err2;
#define PCIE_MLW_CAP_SHIFT 4
*speed = PCI_SPEED_UNKNOWN;
*width = PCIE_LNK_WIDTH_UNKNOWN;
err1 = pcie_capability_read_dword(adap->pdev, PCI_EXP_LNKCAP,
&lnkcap1);
err2 = pcie_capability_read_dword(adap->pdev, PCI_EXP_LNKCAP2,
&lnkcap2);
if (!err2 && lnkcap2) {
if (lnkcap2 & PCI_EXP_LNKCAP2_SLS_8_0GB)
*speed = PCIE_SPEED_8_0GT;
else if (lnkcap2 & PCI_EXP_LNKCAP2_SLS_5_0GB)
*speed = PCIE_SPEED_5_0GT;
else if (lnkcap2 & PCI_EXP_LNKCAP2_SLS_2_5GB)
*speed = PCIE_SPEED_2_5GT;
}
if (!err1) {
*width = (lnkcap1 & PCI_EXP_LNKCAP_MLW) >> PCIE_MLW_CAP_SHIFT;
if (!lnkcap2) {
if (lnkcap1 & PCI_EXP_LNKCAP_SLS_5_0GB)
*speed = PCIE_SPEED_5_0GT;
else if (lnkcap1 & PCI_EXP_LNKCAP_SLS_2_5GB)
*speed = PCIE_SPEED_2_5GT;
}
}
if (*speed == PCI_SPEED_UNKNOWN || *width == PCIE_LNK_WIDTH_UNKNOWN)
return err1 ? err1 : err2 ? err2 : -EINVAL;
return 0;
}
static void cxgb4_check_pcie_caps(struct adapter *adap)
{
enum pcie_link_width width, width_cap;
enum pci_bus_speed speed, speed_cap;
#define PCIE_SPEED_STR(speed) \
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" : \
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" : \
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" : \
"Unknown")
if (cxgb4_get_pcie_dev_link_caps(adap, &speed_cap, &width_cap)) {
dev_warn(adap->pdev_dev,
"Unable to determine PCIe device BW capabilities\n");
return;
}
if (pcie_get_minimum_link(adap->pdev, &speed, &width) ||
speed == PCI_SPEED_UNKNOWN || width == PCIE_LNK_WIDTH_UNKNOWN) {
dev_warn(adap->pdev_dev,
"Unable to determine PCI Express bandwidth.\n");
return;
}
dev_info(adap->pdev_dev, "PCIe link speed is %s, device supports %s\n",
PCIE_SPEED_STR(speed), PCIE_SPEED_STR(speed_cap));
dev_info(adap->pdev_dev, "PCIe link width is x%d, device supports x%d\n",
width, width_cap);
if (speed < speed_cap || width < width_cap)
dev_info(adap->pdev_dev,
"A slot with more lanes and/or higher speed is "
"suggested for optimal performance.\n");
}
static void print_adapter_info(struct adapter *adapter)
{
t4_dump_version_info(adapter);
dev_info(adapter->pdev_dev, "Configuration: %sNIC %s, %s capable\n",
is_offload(adapter) ? "R" : "",
((adapter->flags & USING_MSIX) ? "MSI-X" :
(adapter->flags & USING_MSI) ? "MSI" : ""),
is_offload(adapter) ? "Offload" : "non-Offload");
}
static void print_port_info(const struct net_device *dev)
{
char buf[80];
char *bufp = buf;
const char *spd = "";
const struct port_info *pi = netdev_priv(dev);
const struct adapter *adap = pi->adapter;
if (adap->params.pci.speed == PCI_EXP_LNKSTA_CLS_2_5GB)
spd = " 2.5 GT/s";
else if (adap->params.pci.speed == PCI_EXP_LNKSTA_CLS_5_0GB)
spd = " 5 GT/s";
else if (adap->params.pci.speed == PCI_EXP_LNKSTA_CLS_8_0GB)
spd = " 8 GT/s";
if (pi->link_cfg.pcaps & FW_PORT_CAP32_SPEED_100M)
bufp += sprintf(bufp, "100M/");
if (pi->link_cfg.pcaps & FW_PORT_CAP32_SPEED_1G)
bufp += sprintf(bufp, "1G/");
if (pi->link_cfg.pcaps & FW_PORT_CAP32_SPEED_10G)
bufp += sprintf(bufp, "10G/");
if (pi->link_cfg.pcaps & FW_PORT_CAP32_SPEED_25G)
bufp += sprintf(bufp, "25G/");
if (pi->link_cfg.pcaps & FW_PORT_CAP32_SPEED_40G)
bufp += sprintf(bufp, "40G/");
if (pi->link_cfg.pcaps & FW_PORT_CAP32_SPEED_50G)
bufp += sprintf(bufp, "50G/");
if (pi->link_cfg.pcaps & FW_PORT_CAP32_SPEED_100G)
bufp += sprintf(bufp, "100G/");
if (pi->link_cfg.pcaps & FW_PORT_CAP32_SPEED_200G)
bufp += sprintf(bufp, "200G/");
if (pi->link_cfg.pcaps & FW_PORT_CAP32_SPEED_400G)
bufp += sprintf(bufp, "400G/");
if (bufp != buf)
--bufp;
sprintf(bufp, "BASE-%s", t4_get_port_type_description(pi->port_type));
netdev_info(dev, "%s: Chelsio %s (%s) %s\n",
dev->name, adap->params.vpd.id, adap->name, buf);
}
static void free_some_resources(struct adapter *adapter)
{
unsigned int i;
kvfree(adapter->l2t);
t4_cleanup_sched(adapter);
kvfree(adapter->tids.tid_tab);
cxgb4_cleanup_tc_u32(adapter);
kfree(adapter->sge.egr_map);
kfree(adapter->sge.ingr_map);
kfree(adapter->sge.starving_fl);
kfree(adapter->sge.txq_maperr);
#ifdef CONFIG_DEBUG_FS
kfree(adapter->sge.blocked_fl);
#endif
disable_msi(adapter);
for_each_port(adapter, i)
if (adapter->port[i]) {
struct port_info *pi = adap2pinfo(adapter, i);
if (pi->viid != 0)
t4_free_vi(adapter, adapter->mbox, adapter->pf,
0, pi->viid);
kfree(adap2pinfo(adapter, i)->rss);
free_netdev(adapter->port[i]);
}
if (adapter->flags & FW_OK)
t4_fw_bye(adapter, adapter->pf);
}
static int get_chip_type(struct pci_dev *pdev, u32 pl_rev)
{
u16 device_id;
pci_read_config_word(pdev, PCI_DEVICE_ID, &device_id);
switch (device_id >> 12) {
case CHELSIO_T4:
return CHELSIO_CHIP_CODE(CHELSIO_T4, pl_rev);
case CHELSIO_T5:
return CHELSIO_CHIP_CODE(CHELSIO_T5, pl_rev);
case CHELSIO_T6:
return CHELSIO_CHIP_CODE(CHELSIO_T6, pl_rev);
default:
dev_err(&pdev->dev, "Device %d is not supported\n",
device_id);
}
return -EINVAL;
}
static void dummy_setup(struct net_device *dev)
{
dev->type = ARPHRD_NONE;
dev->mtu = 0;
dev->hard_header_len = 0;
dev->addr_len = 0;
dev->tx_queue_len = 0;
dev->flags |= IFF_NOARP;
dev->priv_flags |= IFF_NO_QUEUE;
dev->netdev_ops = &cxgb4_mgmt_netdev_ops;
dev->ethtool_ops = &cxgb4_mgmt_ethtool_ops;
dev->needs_free_netdev = true;
}
static int config_mgmt_dev(struct pci_dev *pdev)
{
struct adapter *adap = pci_get_drvdata(pdev);
struct net_device *netdev;
struct port_info *pi;
char name[IFNAMSIZ];
int err;
snprintf(name, IFNAMSIZ, "mgmtpf%d%d", adap->adap_idx, adap->pf);
netdev = alloc_netdev(sizeof(struct port_info), name, NET_NAME_UNKNOWN,
dummy_setup);
if (!netdev)
return -ENOMEM;
pi = netdev_priv(netdev);
pi->adapter = adap;
pi->tx_chan = adap->pf % adap->params.nports;
SET_NETDEV_DEV(netdev, &pdev->dev);
adap->port[0] = netdev;
pi->port_id = 0;
err = register_netdev(adap->port[0]);
if (err) {
pr_info("Unable to register VF mgmt netdev %s\n", name);
free_netdev(adap->port[0]);
adap->port[0] = NULL;
return err;
}
return 0;
}
static int cxgb4_iov_configure(struct pci_dev *pdev, int num_vfs)
{
struct adapter *adap = pci_get_drvdata(pdev);
int err = 0;
int current_vfs = pci_num_vf(pdev);
u32 pcie_fw;
pcie_fw = readl(adap->regs + PCIE_FW_A);
if (!(pcie_fw & PCIE_FW_INIT_F) ||
!(pcie_fw & PCIE_FW_MASTER_VLD_F) ||
PCIE_FW_MASTER_G(pcie_fw) != 4) {
dev_warn(&pdev->dev,
"cxgb4 driver needs to be MASTER to support SRIOV\n");
return -EOPNOTSUPP;
}
if (current_vfs && pci_vfs_assigned(pdev)) {
dev_err(&pdev->dev,
"Cannot modify SR-IOV while VFs are assigned\n");
num_vfs = current_vfs;
return num_vfs;
}
if (!num_vfs) {
pci_disable_sriov(pdev);
if (adap->port[0]) {
unregister_netdev(adap->port[0]);
adap->port[0] = NULL;
}
kfree(adap->vfinfo);
adap->vfinfo = NULL;
adap->num_vfs = 0;
return num_vfs;
}
if (num_vfs != current_vfs) {
err = pci_enable_sriov(pdev, num_vfs);
if (err)
return err;
adap->num_vfs = num_vfs;
err = config_mgmt_dev(pdev);
if (err)
return err;
}
adap->vfinfo = kcalloc(adap->num_vfs,
sizeof(struct vf_info), GFP_KERNEL);
if (adap->vfinfo)
fill_vf_station_mac_addr(adap);
return num_vfs;
}
static int init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int func, i, err, s_qpp, qpp, num_seg;
struct port_info *pi;
bool highdma = false;
struct adapter *adapter = NULL;
struct net_device *netdev;
void __iomem *regs;
u32 whoami, pl_rev;
enum chip_type chip;
static int adap_idx = 1;
#ifdef CONFIG_PCI_IOV
u32 v, port_vec;
#endif
printk_once(KERN_INFO "%s - version %s\n", DRV_DESC, DRV_VERSION);
err = pci_request_regions(pdev, KBUILD_MODNAME);
if (err) {
dev_info(&pdev->dev, "cannot obtain PCI resources\n");
return err;
}
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "cannot enable PCI device\n");
goto out_release_regions;
}
regs = pci_ioremap_bar(pdev, 0);
if (!regs) {
dev_err(&pdev->dev, "cannot map device registers\n");
err = -ENOMEM;
goto out_disable_device;
}
err = t4_wait_dev_ready(regs);
if (err < 0)
goto out_unmap_bar0;
whoami = readl(regs + PL_WHOAMI_A);
pl_rev = REV_G(readl(regs + PL_REV_A));
chip = get_chip_type(pdev, pl_rev);
func = CHELSIO_CHIP_VERSION(chip) <= CHELSIO_T5 ?
SOURCEPF_G(whoami) : T6_SOURCEPF_G(whoami);
if (func != ent->driver_data) {
#ifndef CONFIG_PCI_IOV
iounmap(regs);
#endif
pci_disable_device(pdev);
pci_save_state(pdev);
goto sriov;
}
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
highdma = true;
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (err) {
dev_err(&pdev->dev, "unable to obtain 64-bit DMA for "
"coherent allocations\n");
goto out_unmap_bar0;
}
} else {
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "no usable DMA configuration\n");
goto out_unmap_bar0;
}
}
pci_enable_pcie_error_reporting(pdev);
pci_set_master(pdev);
pci_save_state(pdev);
adapter = kzalloc(sizeof(*adapter), GFP_KERNEL);
if (!adapter) {
err = -ENOMEM;
goto out_unmap_bar0;
}
adap_idx++;
adapter->workq = create_singlethread_workqueue("cxgb4");
if (!adapter->workq) {
err = -ENOMEM;
goto out_free_adapter;
}
adapter->mbox_log = kzalloc(sizeof(*adapter->mbox_log) +
(sizeof(struct mbox_cmd) *
T4_OS_LOG_MBOX_CMDS),
GFP_KERNEL);
if (!adapter->mbox_log) {
err = -ENOMEM;
goto out_free_adapter;
}
adapter->mbox_log->size = T4_OS_LOG_MBOX_CMDS;
adapter->flags |= DEV_ENABLED;
adapter->regs = regs;
adapter->pdev = pdev;
adapter->pdev_dev = &pdev->dev;
adapter->name = pci_name(pdev);
adapter->mbox = func;
adapter->pf = func;
adapter->msg_enable = DFLT_MSG_ENABLE;
memset(adapter->chan_map, 0xff, sizeof(adapter->chan_map));
if (!pcie_relaxed_ordering_enabled(pdev))
adapter->flags |= ROOT_NO_RELAXED_ORDERING;
spin_lock_init(&adapter->stats_lock);
spin_lock_init(&adapter->tid_release_lock);
spin_lock_init(&adapter->win0_lock);
spin_lock_init(&adapter->mbox_lock);
INIT_LIST_HEAD(&adapter->mlist.list);
INIT_WORK(&adapter->tid_release_task, process_tid_release_list);
INIT_WORK(&adapter->db_full_task, process_db_full);
INIT_WORK(&adapter->db_drop_task, process_db_drop);
err = t4_prep_adapter(adapter);
if (err)
goto out_free_adapter;
if (!is_t4(adapter->params.chip)) {
s_qpp = (QUEUESPERPAGEPF0_S +
(QUEUESPERPAGEPF1_S - QUEUESPERPAGEPF0_S) *
adapter->pf);
qpp = 1 << QUEUESPERPAGEPF0_G(t4_read_reg(adapter,
SGE_EGRESS_QUEUES_PER_PAGE_PF_A) >> s_qpp);
num_seg = PAGE_SIZE / SEGMENT_SIZE;
if (qpp > num_seg) {
dev_err(&pdev->dev,
"Incorrect number of egress queues per page\n");
err = -EINVAL;
goto out_free_adapter;
}
adapter->bar2 = ioremap_wc(pci_resource_start(pdev, 2),
pci_resource_len(pdev, 2));
if (!adapter->bar2) {
dev_err(&pdev->dev, "cannot map device bar2 region\n");
err = -ENOMEM;
goto out_free_adapter;
}
}
setup_memwin(adapter);
err = adap_init0(adapter);
#ifdef CONFIG_DEBUG_FS
bitmap_zero(adapter->sge.blocked_fl, adapter->sge.egr_sz);
#endif
setup_memwin_rdma(adapter);
if (err)
goto out_unmap_bar;
if (!is_t4(adapter->params.chip))
t4_write_reg(adapter, SGE_STAT_CFG_A, STATSOURCE_T5_V(7) |
(is_t5(adapter->params.chip) ? STATMODE_V(0) :
T6_STATMODE_V(0)));
for_each_port(adapter, i) {
netdev = alloc_etherdev_mq(sizeof(struct port_info),
MAX_ETH_QSETS);
if (!netdev) {
err = -ENOMEM;
goto out_free_dev;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
adapter->port[i] = netdev;
pi = netdev_priv(netdev);
pi->adapter = adapter;
pi->xact_addr_filt = -1;
pi->port_id = i;
netdev->irq = pdev->irq;
netdev->hw_features = NETIF_F_SG | TSO_FLAGS |
NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_RXCSUM | NETIF_F_RXHASH |
NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_TC;
if (highdma)
netdev->hw_features |= NETIF_F_HIGHDMA;
netdev->features |= netdev->hw_features;
netdev->vlan_features = netdev->features & VLAN_FEAT;
netdev->priv_flags |= IFF_UNICAST_FLT;
netdev->min_mtu = 81;
netdev->max_mtu = MAX_MTU;
netdev->netdev_ops = &cxgb4_netdev_ops;
#ifdef CONFIG_CHELSIO_T4_DCB
netdev->dcbnl_ops = &cxgb4_dcb_ops;
cxgb4_dcb_state_init(netdev);
#endif
cxgb4_set_ethtool_ops(netdev);
}
pci_set_drvdata(pdev, adapter);
if (adapter->flags & FW_OK) {
err = t4_port_init(adapter, func, func, 0);
if (err)
goto out_free_dev;
} else if (adapter->params.nports == 1) {
u8 hw_addr[ETH_ALEN];
u8 *na = adapter->params.vpd.na;
err = t4_get_raw_vpd_params(adapter, &adapter->params.vpd);
if (!err) {
for (i = 0; i < ETH_ALEN; i++)
hw_addr[i] = (hex2val(na[2 * i + 0]) * 16 +
hex2val(na[2 * i + 1]));
t4_set_hw_addr(adapter, 0, hw_addr);
}
}
cfg_queues(adapter);
adapter->l2t = t4_init_l2t(adapter->l2t_start, adapter->l2t_end);
if (!adapter->l2t) {
dev_warn(&pdev->dev, "could not allocate L2T, continuing\n");
adapter->params.offload = 0;
}
#if IS_ENABLED(CONFIG_IPV6)
if ((CHELSIO_CHIP_VERSION(adapter->params.chip) <= CHELSIO_T5) &&
(!(t4_read_reg(adapter, LE_DB_CONFIG_A) & ASLIPCOMPEN_F))) {
dev_warn(&pdev->dev,
"CLIP not enabled in hardware, continuing\n");
adapter->params.offload = 0;
} else {
adapter->clipt = t4_init_clip_tbl(adapter->clipt_start,
adapter->clipt_end);
if (!adapter->clipt) {
dev_warn(&pdev->dev,
"could not allocate Clip table, continuing\n");
adapter->params.offload = 0;
}
}
#endif
for_each_port(adapter, i) {
pi = adap2pinfo(adapter, i);
pi->sched_tbl = t4_init_sched(adapter->params.nsched_cls);
if (!pi->sched_tbl)
dev_warn(&pdev->dev,
"could not activate scheduling on port %d\n",
i);
}
if (tid_init(&adapter->tids) < 0) {
dev_warn(&pdev->dev, "could not allocate TID table, "
"continuing\n");
adapter->params.offload = 0;
} else {
adapter->tc_u32 = cxgb4_init_tc_u32(adapter);
if (!adapter->tc_u32)
dev_warn(&pdev->dev,
"could not offload tc u32, continuing\n");
}
if (is_offload(adapter)) {
if (t4_read_reg(adapter, LE_DB_CONFIG_A) & HASHEN_F) {
u32 hash_base, hash_reg;
if (chip <= CHELSIO_T5) {
hash_reg = LE_DB_TID_HASHBASE_A;
hash_base = t4_read_reg(adapter, hash_reg);
adapter->tids.hash_base = hash_base / 4;
} else {
hash_reg = T6_LE_DB_HASH_TID_BASE_A;
hash_base = t4_read_reg(adapter, hash_reg);
adapter->tids.hash_base = hash_base;
}
}
}
if (msi > 1 && enable_msix(adapter) == 0)
adapter->flags |= USING_MSIX;
else if (msi > 0 && pci_enable_msi(pdev) == 0) {
adapter->flags |= USING_MSI;
if (msi > 1)
free_msix_info(adapter);
}
cxgb4_check_pcie_caps(adapter);
err = init_rss(adapter);
if (err)
goto out_free_dev;
for_each_port(adapter, i) {
pi = adap2pinfo(adapter, i);
adapter->port[i]->dev_port = pi->lport;
netif_set_real_num_tx_queues(adapter->port[i], pi->nqsets);
netif_set_real_num_rx_queues(adapter->port[i], pi->nqsets);
netif_carrier_off(adapter->port[i]);
err = register_netdev(adapter->port[i]);
if (err)
break;
adapter->chan_map[pi->tx_chan] = i;
print_port_info(adapter->port[i]);
}
if (i == 0) {
dev_err(&pdev->dev, "could not register any net devices\n");
goto out_free_dev;
}
if (err) {
dev_warn(&pdev->dev, "only %d net devices registered\n", i);
err = 0;
}
if (cxgb4_debugfs_root) {
adapter->debugfs_root = debugfs_create_dir(pci_name(pdev),
cxgb4_debugfs_root);
setup_debugfs(adapter);
}
pdev->needs_freset = 1;
if (is_uld(adapter)) {
mutex_lock(&uld_mutex);
list_add_tail(&adapter->list_node, &adapter_list);
mutex_unlock(&uld_mutex);
}
if (!is_t4(adapter->params.chip))
cxgb4_ptp_init(adapter);
print_adapter_info(adapter);
setup_fw_sge_queues(adapter);
return 0;
sriov:
#ifdef CONFIG_PCI_IOV
adapter = kzalloc(sizeof(*adapter), GFP_KERNEL);
if (!adapter) {
err = -ENOMEM;
goto free_pci_region;
}
adapter->pdev = pdev;
adapter->pdev_dev = &pdev->dev;
adapter->name = pci_name(pdev);
adapter->mbox = func;
adapter->pf = func;
adapter->regs = regs;
adapter->adap_idx = adap_idx;
adapter->mbox_log = kzalloc(sizeof(*adapter->mbox_log) +
(sizeof(struct mbox_cmd) *
T4_OS_LOG_MBOX_CMDS),
GFP_KERNEL);
if (!adapter->mbox_log) {
err = -ENOMEM;
goto free_adapter;
}
spin_lock_init(&adapter->mbox_lock);
INIT_LIST_HEAD(&adapter->mlist.list);
v = FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_PORTVEC);
err = t4_query_params(adapter, adapter->mbox, adapter->pf, 0, 1,
&v, &port_vec);
if (err < 0) {
dev_err(adapter->pdev_dev, "Could not fetch port params\n");
goto free_mbox_log;
}
adapter->params.nports = hweight32(port_vec);
pci_set_drvdata(pdev, adapter);
return 0;
free_mbox_log:
kfree(adapter->mbox_log);
free_adapter:
kfree(adapter);
free_pci_region:
iounmap(regs);
pci_disable_sriov(pdev);
pci_release_regions(pdev);
return err;
#else
return 0;
#endif
out_free_dev:
free_some_resources(adapter);
if (adapter->flags & USING_MSIX)
free_msix_info(adapter);
if (adapter->num_uld || adapter->num_ofld_uld)
t4_uld_mem_free(adapter);
out_unmap_bar:
if (!is_t4(adapter->params.chip))
iounmap(adapter->bar2);
out_free_adapter:
if (adapter->workq)
destroy_workqueue(adapter->workq);
kfree(adapter->mbox_log);
kfree(adapter);
out_unmap_bar0:
iounmap(regs);
out_disable_device:
pci_disable_pcie_error_reporting(pdev);
pci_disable_device(pdev);
out_release_regions:
pci_release_regions(pdev);
return err;
}
static void remove_one(struct pci_dev *pdev)
{
struct adapter *adapter = pci_get_drvdata(pdev);
if (!adapter) {
pci_release_regions(pdev);
return;
}
if (adapter->pf == 4) {
int i;
destroy_workqueue(adapter->workq);
if (is_uld(adapter)) {
detach_ulds(adapter);
t4_uld_clean_up(adapter);
}
disable_interrupts(adapter);
for_each_port(adapter, i)
if (adapter->port[i]->reg_state == NETREG_REGISTERED)
unregister_netdev(adapter->port[i]);
debugfs_remove_recursive(adapter->debugfs_root);
if (!is_t4(adapter->params.chip))
cxgb4_ptp_stop(adapter);
clear_all_filters(adapter);
if (adapter->flags & FULL_INIT_DONE)
cxgb_down(adapter);
if (adapter->flags & USING_MSIX)
free_msix_info(adapter);
if (adapter->num_uld || adapter->num_ofld_uld)
t4_uld_mem_free(adapter);
free_some_resources(adapter);
#if IS_ENABLED(CONFIG_IPV6)
t4_cleanup_clip_tbl(adapter);
#endif
iounmap(adapter->regs);
if (!is_t4(adapter->params.chip))
iounmap(adapter->bar2);
pci_disable_pcie_error_reporting(pdev);
if ((adapter->flags & DEV_ENABLED)) {
pci_disable_device(pdev);
adapter->flags &= ~DEV_ENABLED;
}
pci_release_regions(pdev);
kfree(adapter->mbox_log);
synchronize_rcu();
kfree(adapter);
}
#ifdef CONFIG_PCI_IOV
else {
if (adapter->port[0])
unregister_netdev(adapter->port[0]);
iounmap(adapter->regs);
kfree(adapter->vfinfo);
kfree(adapter->mbox_log);
kfree(adapter);
pci_disable_sriov(pdev);
pci_release_regions(pdev);
}
#endif
}
static void shutdown_one(struct pci_dev *pdev)
{
struct adapter *adapter = pci_get_drvdata(pdev);
if (!adapter) {
pci_release_regions(pdev);
return;
}
if (adapter->pf == 4) {
int i;
for_each_port(adapter, i)
if (adapter->port[i]->reg_state == NETREG_REGISTERED)
cxgb_close(adapter->port[i]);
if (is_uld(adapter)) {
detach_ulds(adapter);
t4_uld_clean_up(adapter);
}
disable_interrupts(adapter);
disable_msi(adapter);
t4_sge_stop(adapter);
if (adapter->flags & FW_OK)
t4_fw_bye(adapter, adapter->mbox);
}
#ifdef CONFIG_PCI_IOV
else {
if (adapter->port[0])
unregister_netdev(adapter->port[0]);
iounmap(adapter->regs);
kfree(adapter->vfinfo);
kfree(adapter->mbox_log);
kfree(adapter);
pci_disable_sriov(pdev);
pci_release_regions(pdev);
}
#endif
}
static int __init cxgb4_init_module(void)
{
int ret;
cxgb4_debugfs_root = debugfs_create_dir(KBUILD_MODNAME, NULL);
if (!cxgb4_debugfs_root)
pr_warn("could not create debugfs entry, continuing\n");
ret = pci_register_driver(&cxgb4_driver);
if (ret < 0)
debugfs_remove(cxgb4_debugfs_root);
#if IS_ENABLED(CONFIG_IPV6)
if (!inet6addr_registered) {
register_inet6addr_notifier(&cxgb4_inet6addr_notifier);
inet6addr_registered = true;
}
#endif
return ret;
}
static void __exit cxgb4_cleanup_module(void)
{
#if IS_ENABLED(CONFIG_IPV6)
if (inet6addr_registered) {
unregister_inet6addr_notifier(&cxgb4_inet6addr_notifier);
inet6addr_registered = false;
}
#endif
pci_unregister_driver(&cxgb4_driver);
debugfs_remove(cxgb4_debugfs_root);
}
