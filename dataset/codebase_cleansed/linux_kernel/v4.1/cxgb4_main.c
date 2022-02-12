static void link_report(struct net_device *dev)
{
if (!netif_carrier_ok(dev))
netdev_info(dev, "link down\n");
else {
static const char *fc[] = { "no", "Rx", "Tx", "Tx/Rx" };
const char *s = "10Mbps";
const struct port_info *p = netdev_priv(dev);
switch (p->link_cfg.speed) {
case 10000:
s = "10Gbps";
break;
case 1000:
s = "1000Mbps";
break;
case 100:
s = "100Mbps";
break;
case 40000:
s = "40Gbps";
break;
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
err = t4_set_params_nosleep(adap, adap->mbox, adap->fn, 0, 1,
&name, &value);
if (err)
dev_err(adap->pdev_dev,
"Can't %s DCB Priority on port %d, TX Queue %d: err=%d\n",
enable ? "set" : "unset", pi->port_id, i, -err);
else
txq->dcb_prio = value;
}
}
void t4_os_link_changed(struct adapter *adapter, int port_id, int link_stat)
{
struct net_device *dev = adapter->port[port_id];
if (netif_running(dev) && link_stat != netif_carrier_ok(dev)) {
if (link_stat)
netif_carrier_on(dev);
else {
#ifdef CONFIG_CHELSIO_T4_DCB
cxgb4_dcb_state_init(dev);
dcb_tx_queue_prio_enable(dev, false);
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
}
static int set_addr_filters(const struct net_device *dev, bool sleep)
{
u64 mhash = 0;
u64 uhash = 0;
bool free = true;
u16 filt_idx[7];
const u8 *addr[7];
int ret, naddr = 0;
const struct netdev_hw_addr *ha;
int uc_cnt = netdev_uc_count(dev);
int mc_cnt = netdev_mc_count(dev);
const struct port_info *pi = netdev_priv(dev);
unsigned int mb = pi->adapter->fn;
netdev_for_each_uc_addr(ha, dev) {
addr[naddr++] = ha->addr;
if (--uc_cnt == 0 || naddr >= ARRAY_SIZE(addr)) {
ret = t4_alloc_mac_filt(pi->adapter, mb, pi->viid, free,
naddr, addr, filt_idx, &uhash, sleep);
if (ret < 0)
return ret;
free = false;
naddr = 0;
}
}
netdev_for_each_mc_addr(ha, dev) {
addr[naddr++] = ha->addr;
if (--mc_cnt == 0 || naddr >= ARRAY_SIZE(addr)) {
ret = t4_alloc_mac_filt(pi->adapter, mb, pi->viid, free,
naddr, addr, filt_idx, &mhash, sleep);
if (ret < 0)
return ret;
free = false;
naddr = 0;
}
}
return t4_set_addr_hash(pi->adapter, mb, pi->viid, uhash != 0,
uhash | mhash, sleep);
}
static int set_rxmode(struct net_device *dev, int mtu, bool sleep_ok)
{
int ret;
struct port_info *pi = netdev_priv(dev);
ret = set_addr_filters(dev, sleep_ok);
if (ret == 0)
ret = t4_set_rxmode(pi->adapter, pi->adapter->fn, pi->viid, mtu,
(dev->flags & IFF_PROMISC) ? 1 : 0,
(dev->flags & IFF_ALLMULTI) ? 1 : 0, 1, -1,
sleep_ok);
return ret;
}
static int link_start(struct net_device *dev)
{
int ret;
struct port_info *pi = netdev_priv(dev);
unsigned int mb = pi->adapter->fn;
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
ret = t4_link_start(pi->adapter, mb, pi->tx_chan,
&pi->link_cfg);
if (ret == 0) {
local_bh_disable();
ret = t4_enable_vi_params(pi->adapter, mb, pi->viid, true,
true, CXGB4_DCB_ENABLED);
local_bh_enable();
}
return ret;
}
int cxgb4_dcb_enabled(const struct net_device *dev)
{
#ifdef CONFIG_CHELSIO_T4_DCB
struct port_info *pi = netdev_priv(dev);
if (!pi->dcb.enabled)
return 0;
return ((pi->dcb.state == CXGB4_DCB_STATE_FW_ALLSYNCED) ||
(pi->dcb.state == CXGB4_DCB_STATE_HOST));
#else
return 0;
#endif
}
static void dcb_rpl(struct adapter *adap, const struct fw_port_cmd *pcmd)
{
int port = FW_PORT_CMD_PORTID_G(ntohl(pcmd->op_to_portid));
struct net_device *dev = adap->port[port];
int old_dcb_enabled = cxgb4_dcb_enabled(dev);
int new_dcb_enabled;
cxgb4_dcb_handle_fw_update(adap, pcmd);
new_dcb_enabled = cxgb4_dcb_enabled(dev);
if (new_dcb_enabled != old_dcb_enabled)
dcb_tx_queue_prio_enable(dev, new_dcb_enabled);
}
static void clear_filter(struct adapter *adap, struct filter_entry *f)
{
if (f->l2t)
cxgb4_l2t_release(f->l2t);
memset(f, 0, sizeof(*f));
}
static void filter_rpl(struct adapter *adap, const struct cpl_set_tcb_rpl *rpl)
{
unsigned int idx = GET_TID(rpl);
unsigned int nidx = idx - adap->tids.ftid_base;
unsigned int ret;
struct filter_entry *f;
if (idx >= adap->tids.ftid_base && nidx <
(adap->tids.nftids + adap->tids.nsftids)) {
idx = nidx;
ret = TCB_COOKIE_G(rpl->cookie);
f = &adap->tids.ftid_tab[idx];
if (ret == FW_FILTER_WR_FLT_DELETED) {
clear_filter(adap, f);
} else if (ret == FW_FILTER_WR_SMT_TBL_FULL) {
dev_err(adap->pdev_dev, "filter %u setup failed due to full SMT\n",
idx);
clear_filter(adap, f);
} else if (ret == FW_FILTER_WR_FLT_ADDED) {
f->smtidx = (be64_to_cpu(rpl->oldval) >> 24) & 0xff;
f->pending = 0;
f->valid = 1;
} else {
dev_err(adap->pdev_dev, "filter %u setup failed with error %u\n",
idx, ret);
clear_filter(adap, f);
}
}
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
if ((u8 *)txq < (u8 *)q->adap->sge.ofldtxq) {
struct sge_eth_txq *eq;
eq = container_of(txq, struct sge_eth_txq, q);
netif_tx_wake_queue(eq->txq);
} else {
struct sge_ofld_txq *oq;
oq = container_of(txq, struct sge_ofld_txq, q);
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
action == FW_PORT_ACTION_GET_PORT_INFO) {
int port = FW_PORT_CMD_PORTID_G(
be32_to_cpu(pcmd->op_to_portid));
struct net_device *dev = q->adap->port[port];
int state_input = ((pcmd->u.info.dcbxdis_pkd &
FW_PORT_CMD_DCBXDIS_F)
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
static int uldrx_handler(struct sge_rspq *q, const __be64 *rsp,
const struct pkt_gl *gl)
{
struct sge_ofld_rxq *rxq = container_of(q, struct sge_ofld_rxq, rspq);
if (((const struct rss_header *)rsp)->opcode == CPL_FW4_MSG &&
((const struct cpl_fw4_msg *)(rsp + 1))->type == FW_TYPE_RSSCPL)
rsp += 2;
if (ulds[q->uld].rx_handler(q->adap->uld_handle[q->uld], rsp, gl)) {
rxq->stats.nomem++;
return -1;
}
if (gl == NULL)
rxq->stats.imm++;
else if (gl == CXGB4_MSG_AN)
rxq->stats.an++;
else
rxq->stats.pkts++;
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
for_each_ofldrxq(&adap->sge, i)
snprintf(adap->msix_info[msi_idx++].desc, n, "%s-ofld%d",
adap->port[0]->name, i);
for_each_rdmarxq(&adap->sge, i)
snprintf(adap->msix_info[msi_idx++].desc, n, "%s-rdma%d",
adap->port[0]->name, i);
for_each_rdmaciq(&adap->sge, i)
snprintf(adap->msix_info[msi_idx++].desc, n, "%s-rdma-ciq%d",
adap->port[0]->name, i);
}
static int request_msix_queue_irqs(struct adapter *adap)
{
struct sge *s = &adap->sge;
int err, ethqidx, ofldqidx = 0, rdmaqidx = 0, rdmaciqqidx = 0;
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
for_each_ofldrxq(s, ofldqidx) {
err = request_irq(adap->msix_info[msi_index].vec,
t4_sge_intr_msix, 0,
adap->msix_info[msi_index].desc,
&s->ofldrxq[ofldqidx].rspq);
if (err)
goto unwind;
msi_index++;
}
for_each_rdmarxq(s, rdmaqidx) {
err = request_irq(adap->msix_info[msi_index].vec,
t4_sge_intr_msix, 0,
adap->msix_info[msi_index].desc,
&s->rdmarxq[rdmaqidx].rspq);
if (err)
goto unwind;
msi_index++;
}
for_each_rdmaciq(s, rdmaciqqidx) {
err = request_irq(adap->msix_info[msi_index].vec,
t4_sge_intr_msix, 0,
adap->msix_info[msi_index].desc,
&s->rdmaciq[rdmaciqqidx].rspq);
if (err)
goto unwind;
msi_index++;
}
return 0;
unwind:
while (--rdmaciqqidx >= 0)
free_irq(adap->msix_info[--msi_index].vec,
&s->rdmaciq[rdmaciqqidx].rspq);
while (--rdmaqidx >= 0)
free_irq(adap->msix_info[--msi_index].vec,
&s->rdmarxq[rdmaqidx].rspq);
while (--ofldqidx >= 0)
free_irq(adap->msix_info[--msi_index].vec,
&s->ofldrxq[ofldqidx].rspq);
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
for_each_ofldrxq(s, i)
free_irq(adap->msix_info[msi_index++].vec, &s->ofldrxq[i].rspq);
for_each_rdmarxq(s, i)
free_irq(adap->msix_info[msi_index++].vec, &s->rdmarxq[i].rspq);
for_each_rdmaciq(s, i)
free_irq(adap->msix_info[msi_index++].vec, &s->rdmaciq[i].rspq);
}
int cxgb4_write_rss(const struct port_info *pi, const u16 *queues)
{
u16 *rss;
int i, err;
const struct sge_eth_rxq *q = &pi->adapter->sge.ethrxq[pi->first_qset];
rss = kmalloc(pi->rss_size * sizeof(u16), GFP_KERNEL);
if (!rss)
return -ENOMEM;
for (i = 0; i < pi->rss_size; i++, queues++)
rss[i] = q[*queues].rspq.abs_id;
err = t4_config_rss_range(pi->adapter, pi->adapter->fn, pi->viid, 0,
pi->rss_size, rss, pi->rss_size);
kfree(rss);
return err;
}
static int setup_rss(struct adapter *adap)
{
int i, err;
for_each_port(adap, i) {
const struct port_info *pi = adap2pinfo(adap, i);
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
if (q && q->handler) {
napi_disable(&q->napi);
local_bh_disable();
while (!cxgb_poll_lock_napi(q))
mdelay(1);
local_bh_enable();
}
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
if (q->handler) {
cxgb_busy_poll_init_lock(q);
napi_enable(&q->napi);
}
t4_write_reg(adap, MYPF_REG(SGE_PF_GTS_A),
SEINTARM_V(q->intr_params) |
INGRESSQID_V(q->cntxt_id));
}
}
static int alloc_ofld_rxqs(struct adapter *adap, struct sge_ofld_rxq *q,
unsigned int nq, unsigned int per_chan, int msi_idx,
u16 *ids)
{
int i, err;
for (i = 0; i < nq; i++, q++) {
if (msi_idx > 0)
msi_idx++;
err = t4_sge_alloc_rxq(adap, &q->rspq, false,
adap->port[i / per_chan],
msi_idx, q->fl.size ? &q->fl : NULL,
uldrx_handler);
if (err)
return err;
memset(&q->stats, 0, sizeof(q->stats));
if (ids)
ids[i] = q->rspq.abs_id;
}
return 0;
}
static int setup_sge_queues(struct adapter *adap)
{
int err, msi_idx, i, j;
struct sge *s = &adap->sge;
bitmap_zero(s->starving_fl, s->egr_sz);
bitmap_zero(s->txq_maperr, s->egr_sz);
if (adap->flags & USING_MSIX)
msi_idx = 1;
else {
err = t4_sge_alloc_rxq(adap, &s->intrq, false, adap->port[0], 0,
NULL, NULL);
if (err)
return err;
msi_idx = -((int)s->intrq.abs_id + 1);
}
err = t4_sge_alloc_rxq(adap, &s->fw_evtq, true, adap->port[0],
msi_idx, NULL, fwevtq_handler);
if (err) {
freeout: t4_free_sge_resources(adap);
return err;
}
for_each_port(adap, i) {
struct net_device *dev = adap->port[i];
struct port_info *pi = netdev_priv(dev);
struct sge_eth_rxq *q = &s->ethrxq[pi->first_qset];
struct sge_eth_txq *t = &s->ethtxq[pi->first_qset];
for (j = 0; j < pi->nqsets; j++, q++) {
if (msi_idx > 0)
msi_idx++;
err = t4_sge_alloc_rxq(adap, &q->rspq, false, dev,
msi_idx, &q->fl,
t4_ethrx_handler);
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
j = s->ofldqsets / adap->params.nports;
for_each_ofldrxq(s, i) {
err = t4_sge_alloc_ofld_txq(adap, &s->ofldtxq[i],
adap->port[i / j],
s->fw_evtq.cntxt_id);
if (err)
goto freeout;
}
#define ALLOC_OFLD_RXQS(firstq, nq, per_chan, ids) do { \
err = alloc_ofld_rxqs(adap, firstq, nq, per_chan, msi_idx, ids); \
if (err) \
goto freeout; \
if (msi_idx > 0) \
msi_idx += nq; \
} while (0)
ALLOC_OFLD_RXQS(s->ofldrxq, s->ofldqsets, j, s->ofld_rxq);
ALLOC_OFLD_RXQS(s->rdmarxq, s->rdmaqs, 1, s->rdma_rxq);
j = s->rdmaciqs / adap->params.nports;
ALLOC_OFLD_RXQS(s->rdmaciq, s->rdmaciqs, j, s->rdma_ciq);
#undef ALLOC_OFLD_RXQS
for_each_port(adap, i) {
err = t4_sge_alloc_ctrl_txq(adap, &s->ctrlq[i], adap->port[i],
s->fw_evtq.cntxt_id,
s->rdmarxq[i].rspq.cntxt_id);
if (err)
goto freeout;
}
t4_write_reg(adap, is_t4(adap->params.chip) ?
MPS_TRC_RSS_CONTROL_A :
MPS_T5_TRC_RSS_CONTROL_A,
RSSCONTROL_V(netdev2pinfo(adap->port[0])->tx_chan) |
QUEUENUMBER_V(s->ethrxq[0].rspq.abs_id));
return 0;
}
void *t4_alloc_mem(size_t size)
{
void *p = kzalloc(size, GFP_KERNEL | __GFP_NOWARN);
if (!p)
p = vzalloc(size);
return p;
}
void t4_free_mem(void *addr)
{
if (is_vmalloc_addr(addr))
vfree(addr);
else
kfree(addr);
}
static int set_filter_wr(struct adapter *adapter, int fidx)
{
struct filter_entry *f = &adapter->tids.ftid_tab[fidx];
struct sk_buff *skb;
struct fw_filter_wr *fwr;
unsigned int ftid;
skb = alloc_skb(sizeof(*fwr), GFP_KERNEL);
if (!skb)
return -ENOMEM;
if (f->fs.newdmac || f->fs.newvlan) {
f->l2t = t4_l2t_alloc_switching(adapter->l2t);
if (f->l2t == NULL) {
kfree_skb(skb);
return -EAGAIN;
}
if (t4_l2t_set_switching(adapter, f->l2t, f->fs.vlan,
f->fs.eport, f->fs.dmac)) {
cxgb4_l2t_release(f->l2t);
f->l2t = NULL;
kfree_skb(skb);
return -ENOMEM;
}
}
ftid = adapter->tids.ftid_base + fidx;
fwr = (struct fw_filter_wr *)__skb_put(skb, sizeof(*fwr));
memset(fwr, 0, sizeof(*fwr));
fwr->op_pkd = htonl(FW_WR_OP_V(FW_FILTER_WR));
fwr->len16_pkd = htonl(FW_WR_LEN16_V(sizeof(*fwr)/16));
fwr->tid_to_iq =
htonl(FW_FILTER_WR_TID_V(ftid) |
FW_FILTER_WR_RQTYPE_V(f->fs.type) |
FW_FILTER_WR_NOREPLY_V(0) |
FW_FILTER_WR_IQ_V(f->fs.iq));
fwr->del_filter_to_l2tix =
htonl(FW_FILTER_WR_RPTTID_V(f->fs.rpttid) |
FW_FILTER_WR_DROP_V(f->fs.action == FILTER_DROP) |
FW_FILTER_WR_DIRSTEER_V(f->fs.dirsteer) |
FW_FILTER_WR_MASKHASH_V(f->fs.maskhash) |
FW_FILTER_WR_DIRSTEERHASH_V(f->fs.dirsteerhash) |
FW_FILTER_WR_LPBK_V(f->fs.action == FILTER_SWITCH) |
FW_FILTER_WR_DMAC_V(f->fs.newdmac) |
FW_FILTER_WR_SMAC_V(f->fs.newsmac) |
FW_FILTER_WR_INSVLAN_V(f->fs.newvlan == VLAN_INSERT ||
f->fs.newvlan == VLAN_REWRITE) |
FW_FILTER_WR_RMVLAN_V(f->fs.newvlan == VLAN_REMOVE ||
f->fs.newvlan == VLAN_REWRITE) |
FW_FILTER_WR_HITCNTS_V(f->fs.hitcnts) |
FW_FILTER_WR_TXCHAN_V(f->fs.eport) |
FW_FILTER_WR_PRIO_V(f->fs.prio) |
FW_FILTER_WR_L2TIX_V(f->l2t ? f->l2t->idx : 0));
fwr->ethtype = htons(f->fs.val.ethtype);
fwr->ethtypem = htons(f->fs.mask.ethtype);
fwr->frag_to_ovlan_vldm =
(FW_FILTER_WR_FRAG_V(f->fs.val.frag) |
FW_FILTER_WR_FRAGM_V(f->fs.mask.frag) |
FW_FILTER_WR_IVLAN_VLD_V(f->fs.val.ivlan_vld) |
FW_FILTER_WR_OVLAN_VLD_V(f->fs.val.ovlan_vld) |
FW_FILTER_WR_IVLAN_VLDM_V(f->fs.mask.ivlan_vld) |
FW_FILTER_WR_OVLAN_VLDM_V(f->fs.mask.ovlan_vld));
fwr->smac_sel = 0;
fwr->rx_chan_rx_rpl_iq =
htons(FW_FILTER_WR_RX_CHAN_V(0) |
FW_FILTER_WR_RX_RPL_IQ_V(adapter->sge.fw_evtq.abs_id));
fwr->maci_to_matchtypem =
htonl(FW_FILTER_WR_MACI_V(f->fs.val.macidx) |
FW_FILTER_WR_MACIM_V(f->fs.mask.macidx) |
FW_FILTER_WR_FCOE_V(f->fs.val.fcoe) |
FW_FILTER_WR_FCOEM_V(f->fs.mask.fcoe) |
FW_FILTER_WR_PORT_V(f->fs.val.iport) |
FW_FILTER_WR_PORTM_V(f->fs.mask.iport) |
FW_FILTER_WR_MATCHTYPE_V(f->fs.val.matchtype) |
FW_FILTER_WR_MATCHTYPEM_V(f->fs.mask.matchtype));
fwr->ptcl = f->fs.val.proto;
fwr->ptclm = f->fs.mask.proto;
fwr->ttyp = f->fs.val.tos;
fwr->ttypm = f->fs.mask.tos;
fwr->ivlan = htons(f->fs.val.ivlan);
fwr->ivlanm = htons(f->fs.mask.ivlan);
fwr->ovlan = htons(f->fs.val.ovlan);
fwr->ovlanm = htons(f->fs.mask.ovlan);
memcpy(fwr->lip, f->fs.val.lip, sizeof(fwr->lip));
memcpy(fwr->lipm, f->fs.mask.lip, sizeof(fwr->lipm));
memcpy(fwr->fip, f->fs.val.fip, sizeof(fwr->fip));
memcpy(fwr->fipm, f->fs.mask.fip, sizeof(fwr->fipm));
fwr->lp = htons(f->fs.val.lport);
fwr->lpm = htons(f->fs.mask.lport);
fwr->fp = htons(f->fs.val.fport);
fwr->fpm = htons(f->fs.mask.fport);
if (f->fs.newsmac)
memcpy(fwr->sma, f->fs.smac, sizeof(fwr->sma));
f->pending = 1;
set_wr_txq(skb, CPL_PRIORITY_CONTROL, f->fs.val.iport & 0x3);
t4_ofld_send(adapter, skb);
return 0;
}
static int del_filter_wr(struct adapter *adapter, int fidx)
{
struct filter_entry *f = &adapter->tids.ftid_tab[fidx];
struct sk_buff *skb;
struct fw_filter_wr *fwr;
unsigned int len, ftid;
len = sizeof(*fwr);
ftid = adapter->tids.ftid_base + fidx;
skb = alloc_skb(len, GFP_KERNEL);
if (!skb)
return -ENOMEM;
fwr = (struct fw_filter_wr *)__skb_put(skb, len);
t4_mk_filtdelwr(ftid, fwr, adapter->sge.fw_evtq.abs_id);
f->pending = 1;
t4_mgmt_tx(adapter, skb);
return 0;
}
static u16 cxgb_select_queue(struct net_device *dev, struct sk_buff *skb,
void *accel_priv, select_queue_fallback_t fallback)
{
int txq;
#ifdef CONFIG_CHELSIO_T4_DCB
if (cxgb4_dcb_enabled(dev)) {
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
static inline int is_offload(const struct adapter *adap)
{
return adap->params.offload;
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
err = t4_set_params(adap, adap->fn, adap->fn, 0, 1, &v,
&new_idx);
if (err)
return err;
}
q->pktcnt_idx = new_idx;
}
us = us == 0 ? 6 : closest_timer(&adap->sge, us);
q->intr_params = QINTR_TIMER_IDX(us) | (cnt > 0 ? QINTR_CNT_EN : 0);
return 0;
}
static int cxgb_set_features(struct net_device *dev, netdev_features_t features)
{
const struct port_info *pi = netdev_priv(dev);
netdev_features_t changed = dev->features ^ features;
int err;
if (!(changed & NETIF_F_HW_VLAN_CTAG_RX))
return 0;
err = t4_set_rxmode(pi->adapter, pi->adapter->fn, pi->viid, -1,
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
stid = bitmap_find_free_region(t->stid_bmap, t->nstids, 2);
if (stid < 0)
stid = -1;
}
if (stid >= 0) {
t->stid_tab[stid].data = data;
stid += t->stid_base;
if (family == PF_INET)
t->stids_in_use++;
else
t->stids_in_use += 4;
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
t->stids_in_use++;
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
bitmap_release_region(t->stid_bmap, stid, 2);
t->stid_tab[stid].data = NULL;
if (family == PF_INET)
t->stids_in_use--;
else
t->stids_in_use -= 4;
spin_unlock_bh(&t->stid_lock);
}
static void mk_tid_release(struct sk_buff *skb, unsigned int chan,
unsigned int tid)
{
struct cpl_tid_release *req;
set_wr_txq(skb, CPL_PRIORITY_SETUP, chan);
req = (struct cpl_tid_release *)__skb_put(skb, sizeof(*req));
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
void cxgb4_remove_tid(struct tid_info *t, unsigned int chan, unsigned int tid)
{
void *old;
struct sk_buff *skb;
struct adapter *adap = container_of(t, struct adapter, tids);
old = t->tid_tab[tid];
skb = alloc_skb(sizeof(struct cpl_tid_release), GFP_ATOMIC);
if (likely(skb)) {
t->tid_tab[tid] = NULL;
mk_tid_release(skb, chan, tid);
t4_ofld_send(adap, skb);
} else
cxgb4_queue_tid_release(t, chan, tid);
if (old)
atomic_dec(&t->tids_in_use);
}
static int tid_init(struct tid_info *t)
{
size_t size;
unsigned int stid_bmap_size;
unsigned int natids = t->natids;
struct adapter *adap = container_of(t, struct adapter, tids);
stid_bmap_size = BITS_TO_LONGS(t->nstids + t->nsftids);
size = t->ntids * sizeof(*t->tid_tab) +
natids * sizeof(*t->atid_tab) +
t->nstids * sizeof(*t->stid_tab) +
t->nsftids * sizeof(*t->stid_tab) +
stid_bmap_size * sizeof(long) +
t->nftids * sizeof(*t->ftid_tab) +
t->nsftids * sizeof(*t->ftid_tab);
t->tid_tab = t4_alloc_mem(size);
if (!t->tid_tab)
return -ENOMEM;
t->atid_tab = (union aopen_entry *)&t->tid_tab[t->ntids];
t->stid_tab = (struct serv_entry *)&t->atid_tab[natids];
t->stid_bmap = (unsigned long *)&t->stid_tab[t->nstids + t->nsftids];
t->ftid_tab = (struct filter_entry *)&t->stid_bmap[stid_bmap_size];
spin_lock_init(&t->stid_lock);
spin_lock_init(&t->atid_lock);
t->stids_in_use = 0;
t->afree = NULL;
t->atids_in_use = 0;
atomic_set(&t->tids_in_use, 0);
if (natids) {
while (--natids)
t->atid_tab[natids - 1].next = &t->atid_tab[natids];
t->afree = t->atid_tab;
}
bitmap_zero(t->stid_bmap, t->nstids + t->nsftids);
if (!t->stid_base &&
(is_t4(adap->params.chip) || is_t5(adap->params.chip)))
__set_bit(0, t->stid_bmap);
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
req = (struct cpl_pass_open_req *)__skb_put(skb, sizeof(*req));
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
req = (struct cpl_pass_open_req6 *)__skb_put(skb, sizeof(*req));
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
req = (struct cpl_close_listsvr_req *)__skb_put(skb, sizeof(*req));
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
int ret;
ret = t4_fwaddrspace_write(adap, adap->mbox,
0xe1000000 + SGE_CTXT_CMD_A, 0x20000000);
return ret;
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
void cxgb4_disable_db_coalescing(struct net_device *dev)
{
struct adapter *adap;
adap = netdev2adap(dev);
t4_set_reg_field(adap, SGE_DOORBELL_CONTROL_A, NOCOALESCE_F,
NOCOALESCE_F);
}
void cxgb4_enable_db_coalescing(struct net_device *dev)
{
struct adapter *adap;
adap = netdev2adap(dev);
t4_set_reg_field(adap, SGE_DOORBELL_CONTROL_A, NOCOALESCE_F, 0);
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
} else if (is_t4(adap->params.chip)) {
goto err;
} else {
size = t4_read_reg(adap, MA_EXT_MEMORY1_BAR_A);
mc1_size = EXT_MEM1_SIZE_G(size) << 20;
mc1_end = mc0_end + mc1_size;
if (offset < mc1_end) {
memtype = MEM_MC1;
memaddr = offset - mc0_end;
} else {
goto err;
}
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
u64 *pbar2_qoffset,
unsigned int *pbar2_qid)
{
return cxgb4_t4_bar2_sge_qregs(netdev2adap(dev),
qid,
(qtype == CXGB4_BAR2_QTYPE_EGRESS
? T4_BAR2_QTYPE_EGRESS
: T4_BAR2_QTYPE_INGRESS),
pbar2_qoffset,
pbar2_qid);
}
static void check_neigh_update(struct neighbour *neigh)
{
const struct device *parent;
const struct net_device *netdev = neigh->dev;
if (netdev->priv_flags & IFF_802_1Q_VLAN)
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
for_each_ofldrxq(&adap->sge, i)
disable_txq_db(&adap->sge.ofldtxq[i].q);
for_each_port(adap, i)
disable_txq_db(&adap->sge.ctrlq[i].q);
}
static void enable_dbs(struct adapter *adap)
{
int i;
for_each_ethrxq(&adap->sge, i)
enable_txq_db(adap, &adap->sge.ethtxq[i].q);
for_each_ofldrxq(&adap->sge, i)
enable_txq_db(adap, &adap->sge.ofldtxq[i].q);
for_each_port(adap, i)
enable_txq_db(adap, &adap->sge.ctrlq[i].q);
}
static void notify_rdma_uld(struct adapter *adap, enum cxgb4_control cmd)
{
if (adap->uld_handle[CXGB4_ULD_RDMA])
ulds[CXGB4_ULD_RDMA].control(adap->uld_handle[CXGB4_ULD_RDMA],
cmd);
}
static void process_db_full(struct work_struct *work)
{
struct adapter *adap;
adap = container_of(work, struct adapter, db_full_task);
drain_db_fifo(adap, dbfifo_drain_delay);
enable_dbs(adap);
notify_rdma_uld(adap, CXGB4_CONTROL_DB_EMPTY);
t4_set_reg_field(adap, SGE_INT_ENABLE3_A,
DBFIFO_HP_INT_F | DBFIFO_LP_INT_F,
DBFIFO_HP_INT_F | DBFIFO_LP_INT_F);
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
for_each_ofldrxq(&adap->sge, i)
sync_txq_pidx(adap, &adap->sge.ofldtxq[i].q);
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
} else {
u32 dropped_db = t4_read_reg(adap, 0x010ac);
u16 qid = (dropped_db >> 15) & 0x1ffff;
u16 pidx_inc = dropped_db & 0x1fff;
u64 bar2_qoffset;
unsigned int bar2_qid;
int ret;
ret = cxgb4_t4_bar2_sge_qregs(adap, qid, T4_BAR2_QTYPE_EGRESS,
&bar2_qoffset, &bar2_qid);
if (ret)
dev_err(adap->pdev_dev, "doorbell drop recovery: "
"qid=%d, pidx_inc=%d\n", qid, pidx_inc);
else
writel(PIDX_T5_V(pidx_inc) | QID_V(bar2_qid),
adap->bar2 + bar2_qoffset + SGE_UDB_KDOORBELL);
t4_set_reg_field(adap, 0x10b0, 1<<15, 1<<15);
}
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
static void uld_attach(struct adapter *adap, unsigned int uld)
{
void *handle;
struct cxgb4_lld_info lli;
unsigned short i;
lli.pdev = adap->pdev;
lli.pf = adap->fn;
lli.l2t = adap->l2t;
lli.tids = &adap->tids;
lli.ports = adap->port;
lli.vr = &adap->vres;
lli.mtus = adap->params.mtus;
if (uld == CXGB4_ULD_RDMA) {
lli.rxq_ids = adap->sge.rdma_rxq;
lli.ciq_ids = adap->sge.rdma_ciq;
lli.nrxq = adap->sge.rdmaqs;
lli.nciq = adap->sge.rdmaciqs;
} else if (uld == CXGB4_ULD_ISCSI) {
lli.rxq_ids = adap->sge.ofld_rxq;
lli.nrxq = adap->sge.ofldqsets;
}
lli.ntxq = adap->sge.ofldqsets;
lli.nchan = adap->params.nports;
lli.nports = adap->params.nports;
lli.wr_cred = adap->params.ofldq_wr_cred;
lli.adapter_type = adap->params.chip;
lli.iscsi_iolen = MAXRXDATA_G(t4_read_reg(adap, TP_PARA_REG2_A));
lli.cclk_ps = 1000000000 / adap->params.vpd.cclk;
lli.udb_density = 1 << adap->params.sge.eq_qpp;
lli.ucq_density = 1 << adap->params.sge.iq_qpp;
lli.filt_mode = adap->params.tp.vlan_pri_map;
for (i = 0; i < NCHAN; i++)
lli.tx_modq[i] = i;
lli.gts_reg = adap->regs + MYPF_REG(SGE_PF_GTS_A);
lli.db_reg = adap->regs + MYPF_REG(SGE_PF_KDOORBELL_A);
lli.fw_vers = adap->params.fw_vers;
lli.dbfifo_int_thresh = dbfifo_int_thresh;
lli.sge_ingpadboundary = adap->sge.fl_align;
lli.sge_egrstatuspagesize = adap->sge.stat_len;
lli.sge_pktshift = adap->sge.pktshift;
lli.enable_fw_ofld_conn = adap->flags & FW_OFLD_CONN;
lli.max_ordird_qp = adap->params.max_ordird_qp;
lli.max_ird_adapter = adap->params.max_ird_adapter;
lli.ulptx_memwrite_dsgl = adap->params.ulptx_memwrite_dsgl;
handle = ulds[uld].add(&lli);
if (IS_ERR(handle)) {
dev_warn(adap->pdev_dev,
"could not attach to the %s driver, error %ld\n",
uld_str[uld], PTR_ERR(handle));
return;
}
adap->uld_handle[uld] = handle;
if (!netevent_registered) {
register_netevent_notifier(&cxgb4_netevent_nb);
netevent_registered = true;
}
if (adap->flags & FULL_INIT_DONE)
ulds[uld].state_change(handle, CXGB4_STATE_UP);
}
static void attach_ulds(struct adapter *adap)
{
unsigned int i;
spin_lock(&adap_rcu_lock);
list_add_tail_rcu(&adap->rcu_node, &adap_rcu_list);
spin_unlock(&adap_rcu_lock);
mutex_lock(&uld_mutex);
list_add_tail(&adap->list_node, &adapter_list);
for (i = 0; i < CXGB4_ULD_MAX; i++)
if (ulds[i].add)
uld_attach(adap, i);
mutex_unlock(&uld_mutex);
}
static void detach_ulds(struct adapter *adap)
{
unsigned int i;
mutex_lock(&uld_mutex);
list_del(&adap->list_node);
for (i = 0; i < CXGB4_ULD_MAX; i++)
if (adap->uld_handle[i]) {
ulds[i].state_change(adap->uld_handle[i],
CXGB4_STATE_DETACH);
adap->uld_handle[i] = NULL;
}
if (netevent_registered && list_empty(&adapter_list)) {
unregister_netevent_notifier(&cxgb4_netevent_nb);
netevent_registered = false;
}
mutex_unlock(&uld_mutex);
spin_lock(&adap_rcu_lock);
list_del_rcu(&adap->rcu_node);
spin_unlock(&adap_rcu_lock);
}
static void notify_ulds(struct adapter *adap, enum cxgb4_state new_state)
{
unsigned int i;
mutex_lock(&uld_mutex);
for (i = 0; i < CXGB4_ULD_MAX; i++)
if (adap->uld_handle[i])
ulds[i].state_change(adap->uld_handle[i], new_state);
mutex_unlock(&uld_mutex);
}
int cxgb4_register_uld(enum cxgb4_uld type, const struct cxgb4_uld_info *p)
{
int ret = 0;
struct adapter *adap;
if (type >= CXGB4_ULD_MAX)
return -EINVAL;
mutex_lock(&uld_mutex);
if (ulds[type].add) {
ret = -EBUSY;
goto out;
}
ulds[type] = *p;
list_for_each_entry(adap, &adapter_list, list_node)
uld_attach(adap, type);
out: mutex_unlock(&uld_mutex);
return ret;
}
int cxgb4_unregister_uld(enum cxgb4_uld type)
{
struct adapter *adap;
if (type >= CXGB4_ULD_MAX)
return -EINVAL;
mutex_lock(&uld_mutex);
list_for_each_entry(adap, &adapter_list, list_node)
adap->uld_handle[type] = NULL;
ulds[type].add = NULL;
mutex_unlock(&uld_mutex);
return 0;
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
if (event_dev->priv_flags & IFF_802_1Q_VLAN)
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
err = setup_sge_queues(adap);
if (err)
goto out;
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
notify_ulds(adap, CXGB4_STATE_UP);
#if IS_ENABLED(CONFIG_IPV6)
update_clip(adap);
#endif
out:
return err;
irq_err:
dev_err(adap->pdev_dev, "request_irq failed, err %d\n", err);
freeq:
t4_free_sge_resources(adap);
goto out;
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
return t4_enable_vi(adapter, adapter->fn, pi->viid, false, false);
}
static int writable_filter(struct filter_entry *f)
{
if (f->locked)
return -EPERM;
if (f->pending)
return -EBUSY;
return 0;
}
static int delete_filter(struct adapter *adapter, unsigned int fidx)
{
struct filter_entry *f;
int ret;
if (fidx >= adapter->tids.nftids + adapter->tids.nsftids)
return -EINVAL;
f = &adapter->tids.ftid_tab[fidx];
ret = writable_filter(f);
if (ret)
return ret;
if (f->valid)
return del_filter_wr(adapter, fidx);
return 0;
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
int ret;
struct filter_entry *f;
struct adapter *adap;
adap = netdev2adap(dev);
stid -= adap->tids.sftid_base;
stid += adap->tids.nftids;
f = &adap->tids.ftid_tab[stid];
f->locked = 0;
ret = delete_filter(adap, stid);
if (ret)
return ret;
return 0;
}
static struct rtnl_link_stats64 *cxgb_get_stats(struct net_device *dev,
struct rtnl_link_stats64 *ns)
{
struct port_stats stats;
struct port_info *p = netdev_priv(dev);
struct adapter *adapter = p->adapter;
spin_lock(&adapter->stats_lock);
if (!netif_device_present(dev)) {
spin_unlock(&adapter->stats_lock);
return ns;
}
t4_get_port_stats(adapter, p->tx_chan, &stats);
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
ns->rx_fifo_errors = stats.rx_ovflow0 + stats.rx_ovflow1 +
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
return ns;
}
static int cxgb_ioctl(struct net_device *dev, struct ifreq *req, int cmd)
{
unsigned int mbox;
int ret = 0, prtad, devad;
struct port_info *pi = netdev_priv(dev);
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
mbox = pi->adapter->fn;
if (cmd == SIOCGMIIREG)
ret = t4_mdio_rd(pi->adapter, mbox, prtad, devad,
data->reg_num, &data->val_out);
else
ret = t4_mdio_wr(pi->adapter, mbox, prtad, devad,
data->reg_num, data->val_in);
break;
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
if (new_mtu < 81 || new_mtu > MAX_MTU)
return -EINVAL;
ret = t4_set_rxmode(pi->adapter, pi->adapter->fn, pi->viid, new_mtu, -1,
-1, -1, -1, true);
if (!ret)
dev->mtu = new_mtu;
return ret;
}
static int cxgb_set_mac_addr(struct net_device *dev, void *p)
{
int ret;
struct sockaddr *addr = p;
struct port_info *pi = netdev_priv(dev);
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
ret = t4_change_mac(pi->adapter, pi->adapter->fn, pi->viid,
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
void t4_fatal_err(struct adapter *adap)
{
t4_set_reg_field(adap, SGE_CONTROL_A, GLOBALENABLE_F, 0);
t4_intr_disable(adap);
dev_alert(adap->pdev_dev, "encountered fatal error, adapter stopped\n");
}
static u32 t4_read_pcie_cfg4(struct adapter *adap, int reg)
{
struct fw_ldst_cmd ldst_cmd;
u32 val;
int ret;
memset(&ldst_cmd, 0, sizeof(ldst_cmd));
ldst_cmd.op_to_addrspace =
htonl(FW_CMD_OP_V(FW_LDST_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F |
FW_LDST_CMD_ADDRSPACE_V(FW_LDST_ADDRSPC_FUNC_PCIE));
ldst_cmd.cycles_to_len16 = htonl(FW_LEN16(ldst_cmd));
ldst_cmd.u.pcie.select_naccess = FW_LDST_CMD_NACCESS_V(1);
ldst_cmd.u.pcie.ctrl_to_fn =
(FW_LDST_CMD_LC_F | FW_LDST_CMD_FN_V(adap->fn));
ldst_cmd.u.pcie.r = reg;
ret = t4_wr_mbox(adap, adap->mbox, &ldst_cmd, sizeof(ldst_cmd),
&ldst_cmd);
if (ret == 0)
val = ntohl(ldst_cmd.u.pcie.data[0]);
else
t4_hw_pci_read_cfg4(adap, reg, &val);
return val;
}
static void setup_memwin(struct adapter *adap)
{
u32 mem_win0_base, mem_win1_base, mem_win2_base, mem_win2_aperture;
if (is_t4(adap->params.chip)) {
u32 bar0;
bar0 = t4_read_pcie_cfg4(adap, PCI_BASE_ADDRESS_0);
bar0 &= PCI_BASE_ADDRESS_MEM_MASK;
adap->t4_bar0 = bar0;
mem_win0_base = bar0 + MEMWIN0_BASE;
mem_win1_base = bar0 + MEMWIN1_BASE;
mem_win2_base = bar0 + MEMWIN2_BASE;
mem_win2_aperture = MEMWIN2_APERTURE;
} else {
mem_win0_base = MEMWIN0_BASE;
mem_win1_base = MEMWIN1_BASE;
mem_win2_base = MEMWIN2_BASE_T5;
mem_win2_aperture = MEMWIN2_APERTURE_T5;
}
t4_write_reg(adap, PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_BASE_WIN_A, 0),
mem_win0_base | BIR_V(0) |
WINDOW_V(ilog2(MEMWIN0_APERTURE) - 10));
t4_write_reg(adap, PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_BASE_WIN_A, 1),
mem_win1_base | BIR_V(0) |
WINDOW_V(ilog2(MEMWIN1_APERTURE) - 10));
t4_write_reg(adap, PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_BASE_WIN_A, 2),
mem_win2_base | BIR_V(0) |
WINDOW_V(ilog2(mem_win2_aperture) - 10));
t4_read_reg(adap, PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_BASE_WIN_A, 2));
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
ret = t4_wr_mbox(adap, adap->fn, c, sizeof(*c), c);
if (ret < 0)
return ret;
if (c->niccaps & htons(FW_CAPS_CONFIG_NIC_VM)) {
if (!vf_acls)
c->niccaps ^= htons(FW_CAPS_CONFIG_NIC_VM);
else
c->niccaps = htons(FW_CAPS_CONFIG_NIC_VM);
} else if (vf_acls) {
dev_err(adap->pdev_dev, "virtualization ACLs not supported");
return ret;
}
c->op_to_write = htonl(FW_CMD_OP_V(FW_CAPS_CONFIG_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F);
ret = t4_wr_mbox(adap, adap->fn, c, sizeof(*c), NULL);
if (ret < 0)
return ret;
ret = t4_config_glbl_rss(adap, adap->fn,
FW_RSS_GLB_CONFIG_CMD_MODE_BASICVIRTUAL,
FW_RSS_GLB_CONFIG_CMD_TNLMAPEN_F |
FW_RSS_GLB_CONFIG_CMD_TNLALLLKP_F);
if (ret < 0)
return ret;
ret = t4_cfg_pfvf(adap, adap->fn, adap->fn, 0, adap->sge.egr_sz, 64,
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
return t4_early_init(adap, adap->fn);
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
switch (CHELSIO_CHIP_VERSION(adapter->params.chip)) {
case CHELSIO_T4:
fw_config_file = FW4_CFNAME;
break;
case CHELSIO_T5:
fw_config_file = FW5_CFNAME;
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
adapter->fn, 0, 1, params, val);
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
ret = t4_fw_hello(adap, adap->mbox, adap->mbox, MASTER_MAY, &state);
if (ret < 0) {
dev_err(adap->pdev_dev, "could not connect to FW, error %d\n",
ret);
return ret;
}
if (ret == adap->mbox)
adap->flags |= MASTER_PF;
t4_get_fw_version(adap, &adap->params.fw_vers);
t4_get_tp_version(adap, &adap->params.tp_vers);
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
card_fw = t4_alloc_mem(sizeof(*card_fw));
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
t4_free_mem(card_fw);
if (ret < 0)
goto bye;
}
ret = get_vpd_params(adap, &adap->params.vpd);
if (ret < 0)
goto bye;
v =
FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_PORTVEC);
ret = t4_query_params(adap, adap->mbox, adap->fn, 0, 1, &v, &port_vec);
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
ret = t4_query_params(adap, adap->mbox, adap->fn, 0, 1,
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
ret = t4_query_params(adap, adap->mbox, adap->fn, 0, 6, params, val);
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
ret = t4_query_params(adap, adap->mbox, adap->fn, 0, 2, params, val);
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
params[0] = FW_PARAM_PFVF(CLIP_START);
params[1] = FW_PARAM_PFVF(CLIP_END);
ret = t4_query_params(adap, adap->mbox, adap->fn, 0, 2, params, val);
if (ret < 0)
goto bye;
adap->clipt_start = val[0];
adap->clipt_end = val[1];
params[0] = FW_PARAM_PFVF(ACTIVE_FILTER_START);
params[1] = FW_PARAM_PFVF(ACTIVE_FILTER_END);
ret = t4_query_params(adap, adap->mbox, adap->fn, 0, 2, params, val);
if ((val[0] != val[1]) && (ret >= 0)) {
adap->flags |= FW_OFLD_CONN;
adap->tids.aftid_base = val[0];
adap->tids.aftid_end = val[1];
}
params[0] = FW_PARAM_PFVF(CPLFW4MSG_ENCAP);
val[0] = 1;
(void) t4_set_params(adap, adap->mbox, adap->fn, 0, 1, params, val);
if (is_t4(adap->params.chip)) {
adap->params.ulptx_memwrite_dsgl = false;
} else {
params[0] = FW_PARAM_DEV(ULPTX_MEMWRITE_DSGL);
ret = t4_query_params(adap, adap->mbox, adap->fn, 0,
1, params, val);
adap->params.ulptx_memwrite_dsgl = (ret == 0 && val[0] != 0);
}
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
ret = t4_query_params(adap, adap->mbox, adap->fn, 0, 6,
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
}
if (caps_cmd.rdmacaps) {
params[0] = FW_PARAM_PFVF(STAG_START);
params[1] = FW_PARAM_PFVF(STAG_END);
params[2] = FW_PARAM_PFVF(RQ_START);
params[3] = FW_PARAM_PFVF(RQ_END);
params[4] = FW_PARAM_PFVF(PBL_START);
params[5] = FW_PARAM_PFVF(PBL_END);
ret = t4_query_params(adap, adap->mbox, adap->fn, 0, 6,
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
ret = t4_query_params(adap, adap->mbox, adap->fn, 0, 6, params,
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
ret = t4_query_params(adap, adap->mbox, adap->fn, 0, 2, params,
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
}
if (caps_cmd.iscsicaps) {
params[0] = FW_PARAM_PFVF(ISCSI_START);
params[1] = FW_PARAM_PFVF(ISCSI_END);
ret = t4_query_params(adap, adap->mbox, adap->fn, 0, 2,
params, val);
if (ret < 0)
goto bye;
adap->vres.iscsi.start = val[0];
adap->vres.iscsi.size = val[1] - val[0] + 1;
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
t4_init_tp_params(adap);
adap->flags |= FW_OK;
return 0;
bye:
kfree(adap->sge.egr_map);
kfree(adap->sge.ingr_map);
kfree(adap->sge.starving_fl);
kfree(adap->sge.txq_maperr);
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
netif_device_detach(dev);
netif_carrier_off(dev);
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
if (t4_fw_hello(adap, adap->fn, adap->fn, MASTER_MUST, NULL) < 0)
return PCI_ERS_RESULT_DISCONNECT;
adap->flags |= FW_OK;
if (adap_init1(adap, &c))
return PCI_ERS_RESULT_DISCONNECT;
for_each_port(adap, i) {
struct port_info *p = adap2pinfo(adap, i);
ret = t4_alloc_vi(adap, adap->fn, p->tx_chan, adap->fn, 0, 1,
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
if (netif_running(dev)) {
link_start(dev);
cxgb_set_rxmode(dev);
}
netif_device_attach(dev);
}
rtnl_unlock();
}
static inline bool is_x_10g_port(const struct link_config *lc)
{
return (lc->supported & FW_PORT_CAP_SPEED_10G) != 0 ||
(lc->supported & FW_PORT_CAP_SPEED_40G) != 0;
}
static inline void init_rspq(struct adapter *adap, struct sge_rspq *q,
unsigned int us, unsigned int cnt,
unsigned int size, unsigned int iqe_size)
{
q->adap = adap;
cxgb4_set_rspq_intr_params(q, us, cnt);
q->iqe_len = iqe_size;
q->size = size;
}
static void cfg_queues(struct adapter *adap)
{
struct sge *s = &adap->sge;
int i, n10g = 0, qidx = 0;
#ifndef CONFIG_CHELSIO_T4_DCB
int q10g = 0;
#endif
int ciq_size;
for_each_port(adap, i)
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
pi->nqsets = 8;
qidx += pi->nqsets;
}
#else
if (n10g)
q10g = (MAX_ETH_QSETS - (adap->params.nports - n10g)) / n10g;
if (q10g > netif_get_num_default_rss_queues())
q10g = netif_get_num_default_rss_queues();
for_each_port(adap, i) {
struct port_info *pi = adap2pinfo(adap, i);
pi->first_qset = qidx;
pi->nqsets = is_x_10g_port(&pi->link_cfg) ? q10g : 1;
qidx += pi->nqsets;
}
#endif
s->ethqsets = qidx;
s->max_ethqsets = qidx;
if (is_offload(adap)) {
if (n10g) {
i = min_t(int, ARRAY_SIZE(s->ofldrxq),
num_online_cpus());
s->ofldqsets = roundup(i, adap->params.nports);
} else
s->ofldqsets = adap->params.nports;
s->rdmaqs = adap->params.nports;
s->rdmaciqs = min_t(int, MAX_RDMA_CIQS, num_online_cpus());
s->rdmaciqs = (s->rdmaciqs / adap->params.nports) *
adap->params.nports;
s->rdmaciqs = max_t(int, s->rdmaciqs, adap->params.nports);
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
for (i = 0; i < ARRAY_SIZE(s->ofldtxq); i++)
s->ofldtxq[i].q.size = 1024;
for (i = 0; i < ARRAY_SIZE(s->ofldrxq); i++) {
struct sge_ofld_rxq *r = &s->ofldrxq[i];
init_rspq(adap, &r->rspq, 5, 1, 1024, 64);
r->rspq.uld = CXGB4_ULD_ISCSI;
r->fl.size = 72;
}
for (i = 0; i < ARRAY_SIZE(s->rdmarxq); i++) {
struct sge_ofld_rxq *r = &s->rdmarxq[i];
init_rspq(adap, &r->rspq, 5, 1, 511, 64);
r->rspq.uld = CXGB4_ULD_RDMA;
r->fl.size = 72;
}
ciq_size = 64 + adap->vres.cq.size + adap->tids.nftids;
if (ciq_size > SGE_MAX_IQ_SIZE) {
CH_WARN(adap, "CIQ size too small for available IQs\n");
ciq_size = SGE_MAX_IQ_SIZE;
}
for (i = 0; i < ARRAY_SIZE(s->rdmaciq); i++) {
struct sge_ofld_rxq *r = &s->rdmaciq[i];
init_rspq(adap, &r->rspq, 5, 1, ciq_size, 64);
r->rspq.uld = CXGB4_ULD_RDMA;
}
init_rspq(adap, &s->fw_evtq, 0, 1, 1024, 64);
init_rspq(adap, &s->intrq, 0, 1, 2 * MAX_INGQ, 64);
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
static int enable_msix(struct adapter *adap)
{
int ofld_need = 0;
int i, want, need, allocated;
struct sge *s = &adap->sge;
unsigned int nchan = adap->params.nports;
struct msix_entry *entries;
entries = kmalloc(sizeof(*entries) * (MAX_INGQ + 1),
GFP_KERNEL);
if (!entries)
return -ENOMEM;
for (i = 0; i < MAX_INGQ + 1; ++i)
entries[i].entry = i;
want = s->max_ethqsets + EXTRA_VECS;
if (is_offload(adap)) {
want += s->rdmaqs + s->rdmaciqs + s->ofldqsets;
ofld_need = 3 * nchan;
}
#ifdef CONFIG_CHELSIO_T4_DCB
need = 8 * adap->params.nports + EXTRA_VECS + ofld_need;
#else
need = adap->params.nports + EXTRA_VECS + ofld_need;
#endif
allocated = pci_enable_msix_range(adap->pdev, entries, need, want);
if (allocated < 0) {
dev_info(adap->pdev_dev, "not enough MSI-X vectors left,"
" not using MSI-X\n");
kfree(entries);
return allocated;
}
i = allocated - EXTRA_VECS - ofld_need;
if (i < s->max_ethqsets) {
s->max_ethqsets = i;
if (i < s->ethqsets)
reduce_ethqs(adap, i);
}
if (is_offload(adap)) {
if (allocated < want) {
s->rdmaqs = nchan;
s->rdmaciqs = nchan;
}
i = allocated - EXTRA_VECS - s->max_ethqsets -
s->rdmaqs - s->rdmaciqs;
s->ofldqsets = (i / nchan) * nchan;
}
for (i = 0; i < allocated; ++i)
adap->msix_info[i].vec = entries[i].vector;
kfree(entries);
return 0;
}
static int init_rss(struct adapter *adap)
{
unsigned int i, j;
for_each_port(adap, i) {
struct port_info *pi = adap2pinfo(adap, i);
pi->rss = kcalloc(pi->rss_size, sizeof(u16), GFP_KERNEL);
if (!pi->rss)
return -ENOMEM;
for (j = 0; j < pi->rss_size; j++)
pi->rss[j] = ethtool_rxfh_indir_default(j, pi->nqsets);
}
return 0;
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
if (pi->link_cfg.supported & FW_PORT_CAP_SPEED_100M)
bufp += sprintf(bufp, "100/");
if (pi->link_cfg.supported & FW_PORT_CAP_SPEED_1G)
bufp += sprintf(bufp, "1000/");
if (pi->link_cfg.supported & FW_PORT_CAP_SPEED_10G)
bufp += sprintf(bufp, "10G/");
if (pi->link_cfg.supported & FW_PORT_CAP_SPEED_40G)
bufp += sprintf(bufp, "40G/");
if (bufp != buf)
--bufp;
sprintf(bufp, "BASE-%s", t4_get_port_type_description(pi->port_type));
netdev_info(dev, "Chelsio %s rev %d %s %sNIC PCIe x%d%s%s\n",
adap->params.vpd.id,
CHELSIO_CHIP_RELEASE(adap->params.chip), buf,
is_offload(adap) ? "R" : "", adap->params.pci.width, spd,
(adap->flags & USING_MSIX) ? " MSI-X" :
(adap->flags & USING_MSI) ? " MSI" : "");
netdev_info(dev, "S/N: %s, P/N: %s\n",
adap->params.vpd.sn, adap->params.vpd.pn);
}
static void enable_pcie_relaxed_ordering(struct pci_dev *dev)
{
pcie_capability_set_word(dev, PCI_EXP_DEVCTL, PCI_EXP_DEVCTL_RELAX_EN);
}
static void free_some_resources(struct adapter *adapter)
{
unsigned int i;
t4_free_mem(adapter->l2t);
t4_free_mem(adapter->tids.tid_tab);
kfree(adapter->sge.egr_map);
kfree(adapter->sge.ingr_map);
kfree(adapter->sge.starving_fl);
kfree(adapter->sge.txq_maperr);
disable_msi(adapter);
for_each_port(adapter, i)
if (adapter->port[i]) {
kfree(adap2pinfo(adapter, i)->rss);
free_netdev(adapter->port[i]);
}
if (adapter->flags & FW_OK)
t4_fw_bye(adapter, adapter->fn);
}
static int init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int func, i, err, s_qpp, qpp, num_seg;
struct port_info *pi;
bool highdma = false;
struct adapter *adapter = NULL;
void __iomem *regs;
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
func = SOURCEPF_G(readl(regs + PL_WHOAMI_A));
if (func != ent->driver_data) {
iounmap(regs);
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
enable_pcie_relaxed_ordering(pdev);
pci_set_master(pdev);
pci_save_state(pdev);
adapter = kzalloc(sizeof(*adapter), GFP_KERNEL);
if (!adapter) {
err = -ENOMEM;
goto out_unmap_bar0;
}
adapter->workq = create_singlethread_workqueue("cxgb4");
if (!adapter->workq) {
err = -ENOMEM;
goto out_free_adapter;
}
adapter->flags |= DEV_ENABLED;
adapter->regs = regs;
adapter->pdev = pdev;
adapter->pdev_dev = &pdev->dev;
adapter->mbox = func;
adapter->fn = func;
adapter->msg_enable = dflt_msg_enable;
memset(adapter->chan_map, 0xff, sizeof(adapter->chan_map));
spin_lock_init(&adapter->stats_lock);
spin_lock_init(&adapter->tid_release_lock);
spin_lock_init(&adapter->win0_lock);
INIT_WORK(&adapter->tid_release_task, process_tid_release_list);
INIT_WORK(&adapter->db_full_task, process_db_full);
INIT_WORK(&adapter->db_drop_task, process_db_drop);
err = t4_prep_adapter(adapter);
if (err)
goto out_free_adapter;
if (!is_t4(adapter->params.chip)) {
s_qpp = (QUEUESPERPAGEPF0_S +
(QUEUESPERPAGEPF1_S - QUEUESPERPAGEPF0_S) *
adapter->fn);
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
setup_memwin_rdma(adapter);
if (err)
goto out_unmap_bar;
for_each_port(adapter, i) {
struct net_device *netdev;
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
NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX;
if (highdma)
netdev->hw_features |= NETIF_F_HIGHDMA;
netdev->features |= netdev->hw_features;
netdev->vlan_features = netdev->features & VLAN_FEAT;
netdev->priv_flags |= IFF_UNICAST_FLT;
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
}
cfg_queues(adapter);
adapter->l2t = t4_init_l2t();
if (!adapter->l2t) {
dev_warn(&pdev->dev, "could not allocate L2T, continuing\n");
adapter->params.offload = 0;
}
#if IS_ENABLED(CONFIG_IPV6)
adapter->clipt = t4_init_clip_tbl(adapter->clipt_start,
adapter->clipt_end);
if (!adapter->clipt) {
dev_warn(&pdev->dev,
"could not allocate Clip table, continuing\n");
adapter->params.offload = 0;
}
#endif
if (is_offload(adapter) && tid_init(&adapter->tids) < 0) {
dev_warn(&pdev->dev, "could not allocate TID table, "
"continuing\n");
adapter->params.offload = 0;
}
if (msi > 1 && enable_msix(adapter) == 0)
adapter->flags |= USING_MSIX;
else if (msi > 0 && pci_enable_msi(pdev) == 0)
adapter->flags |= USING_MSI;
err = init_rss(adapter);
if (err)
goto out_free_dev;
for_each_port(adapter, i) {
pi = adap2pinfo(adapter, i);
netif_set_real_num_tx_queues(adapter->port[i], pi->nqsets);
netif_set_real_num_rx_queues(adapter->port[i], pi->nqsets);
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
if (is_offload(adapter))
attach_ulds(adapter);
sriov:
#ifdef CONFIG_PCI_IOV
if (func < ARRAY_SIZE(num_vf) && num_vf[func] > 0)
if (pci_enable_sriov(pdev, num_vf[func]) == 0)
dev_info(&pdev->dev,
"instantiated %u virtual functions\n",
num_vf[func]);
#endif
return 0;
out_free_dev:
free_some_resources(adapter);
out_unmap_bar:
if (!is_t4(adapter->params.chip))
iounmap(adapter->bar2);
out_free_adapter:
if (adapter->workq)
destroy_workqueue(adapter->workq);
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
#ifdef CONFIG_PCI_IOV
pci_disable_sriov(pdev);
#endif
if (adapter) {
int i;
destroy_workqueue(adapter->workq);
if (is_offload(adapter))
detach_ulds(adapter);
disable_interrupts(adapter);
for_each_port(adapter, i)
if (adapter->port[i]->reg_state == NETREG_REGISTERED)
unregister_netdev(adapter->port[i]);
debugfs_remove_recursive(adapter->debugfs_root);
if (adapter->tids.ftid_tab) {
struct filter_entry *f = &adapter->tids.ftid_tab[0];
for (i = 0; i < (adapter->tids.nftids +
adapter->tids.nsftids); i++, f++)
if (f->valid)
clear_filter(adapter, f);
}
if (adapter->flags & FULL_INIT_DONE)
cxgb_down(adapter);
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
synchronize_rcu();
kfree(adapter);
} else
pci_release_regions(pdev);
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
