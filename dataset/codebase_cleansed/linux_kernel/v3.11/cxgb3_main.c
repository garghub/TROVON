static void link_report(struct net_device *dev)
{
if (!netif_carrier_ok(dev))
netdev_info(dev, "link down\n");
else {
const char *s = "10Mbps";
const struct port_info *p = netdev_priv(dev);
switch (p->link_config.speed) {
case SPEED_10000:
s = "10Gbps";
break;
case SPEED_1000:
s = "1000Mbps";
break;
case SPEED_100:
s = "100Mbps";
break;
}
netdev_info(dev, "link up, %s, %s-duplex\n",
s, p->link_config.duplex == DUPLEX_FULL
? "full" : "half");
}
}
static void enable_tx_fifo_drain(struct adapter *adapter,
struct port_info *pi)
{
t3_set_reg_field(adapter, A_XGM_TXFIFO_CFG + pi->mac.offset, 0,
F_ENDROPPKT);
t3_write_reg(adapter, A_XGM_RX_CTRL + pi->mac.offset, 0);
t3_write_reg(adapter, A_XGM_TX_CTRL + pi->mac.offset, F_TXEN);
t3_write_reg(adapter, A_XGM_RX_CTRL + pi->mac.offset, F_RXEN);
}
static void disable_tx_fifo_drain(struct adapter *adapter,
struct port_info *pi)
{
t3_set_reg_field(adapter, A_XGM_TXFIFO_CFG + pi->mac.offset,
F_ENDROPPKT, 0);
}
void t3_os_link_fault(struct adapter *adap, int port_id, int state)
{
struct net_device *dev = adap->port[port_id];
struct port_info *pi = netdev_priv(dev);
if (state == netif_carrier_ok(dev))
return;
if (state) {
struct cmac *mac = &pi->mac;
netif_carrier_on(dev);
disable_tx_fifo_drain(adap, pi);
t3_xgm_intr_disable(adap, pi->port_id);
t3_read_reg(adap, A_XGM_INT_STATUS +
pi->mac.offset);
t3_write_reg(adap,
A_XGM_INT_CAUSE + pi->mac.offset,
F_XGM_INT);
t3_set_reg_field(adap,
A_XGM_INT_ENABLE +
pi->mac.offset,
F_XGM_INT, F_XGM_INT);
t3_xgm_intr_enable(adap, pi->port_id);
t3_mac_enable(mac, MAC_DIRECTION_TX);
} else {
netif_carrier_off(dev);
enable_tx_fifo_drain(adap, pi);
}
link_report(dev);
}
void t3_os_link_changed(struct adapter *adapter, int port_id, int link_stat,
int speed, int duplex, int pause)
{
struct net_device *dev = adapter->port[port_id];
struct port_info *pi = netdev_priv(dev);
struct cmac *mac = &pi->mac;
if (!netif_running(dev))
return;
if (link_stat != netif_carrier_ok(dev)) {
if (link_stat) {
disable_tx_fifo_drain(adapter, pi);
t3_mac_enable(mac, MAC_DIRECTION_RX);
t3_xgm_intr_disable(adapter, pi->port_id);
t3_read_reg(adapter, A_XGM_INT_STATUS +
pi->mac.offset);
t3_write_reg(adapter,
A_XGM_INT_CAUSE + pi->mac.offset,
F_XGM_INT);
t3_set_reg_field(adapter,
A_XGM_INT_ENABLE + pi->mac.offset,
F_XGM_INT, F_XGM_INT);
t3_xgm_intr_enable(adapter, pi->port_id);
netif_carrier_on(dev);
} else {
netif_carrier_off(dev);
t3_xgm_intr_disable(adapter, pi->port_id);
t3_read_reg(adapter, A_XGM_INT_STATUS + pi->mac.offset);
t3_set_reg_field(adapter,
A_XGM_INT_ENABLE + pi->mac.offset,
F_XGM_INT, 0);
if (is_10G(adapter))
pi->phy.ops->power_down(&pi->phy, 1);
t3_read_reg(adapter, A_XGM_INT_STATUS + pi->mac.offset);
t3_mac_disable(mac, MAC_DIRECTION_RX);
t3_link_start(&pi->phy, mac, &pi->link_config);
enable_tx_fifo_drain(adapter, pi);
}
link_report(dev);
}
}
void t3_os_phymod_changed(struct adapter *adap, int port_id)
{
static const char *mod_str[] = {
NULL, "SR", "LR", "LRM", "TWINAX", "TWINAX", "unknown"
};
const struct net_device *dev = adap->port[port_id];
const struct port_info *pi = netdev_priv(dev);
if (pi->phy.modtype == phy_modtype_none)
netdev_info(dev, "PHY module unplugged\n");
else
netdev_info(dev, "%s PHY module inserted\n",
mod_str[pi->phy.modtype]);
}
static void cxgb_set_rxmode(struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
t3_mac_set_rx_mode(&pi->mac, dev);
}
static void link_start(struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
struct cmac *mac = &pi->mac;
t3_mac_reset(mac);
t3_mac_set_num_ucast(mac, MAX_MAC_IDX);
t3_mac_set_mtu(mac, dev->mtu);
t3_mac_set_address(mac, LAN_MAC_IDX, dev->dev_addr);
t3_mac_set_address(mac, SAN_MAC_IDX, pi->iscsic.mac_addr);
t3_mac_set_rx_mode(mac, dev);
t3_link_start(&pi->phy, mac, &pi->link_config);
t3_mac_enable(mac, MAC_DIRECTION_RX | MAC_DIRECTION_TX);
}
static inline void cxgb_disable_msi(struct adapter *adapter)
{
if (adapter->flags & USING_MSIX) {
pci_disable_msix(adapter->pdev);
adapter->flags &= ~USING_MSIX;
} else if (adapter->flags & USING_MSI) {
pci_disable_msi(adapter->pdev);
adapter->flags &= ~USING_MSI;
}
}
static irqreturn_t t3_async_intr_handler(int irq, void *cookie)
{
t3_slow_intr_handler(cookie);
return IRQ_HANDLED;
}
static void name_msix_vecs(struct adapter *adap)
{
int i, j, msi_idx = 1, n = sizeof(adap->msix_info[0].desc) - 1;
snprintf(adap->msix_info[0].desc, n, "%s", adap->name);
adap->msix_info[0].desc[n] = 0;
for_each_port(adap, j) {
struct net_device *d = adap->port[j];
const struct port_info *pi = netdev_priv(d);
for (i = 0; i < pi->nqsets; i++, msi_idx++) {
snprintf(adap->msix_info[msi_idx].desc, n,
"%s-%d", d->name, pi->first_qset + i);
adap->msix_info[msi_idx].desc[n] = 0;
}
}
}
static int request_msix_data_irqs(struct adapter *adap)
{
int i, j, err, qidx = 0;
for_each_port(adap, i) {
int nqsets = adap2pinfo(adap, i)->nqsets;
for (j = 0; j < nqsets; ++j) {
err = request_irq(adap->msix_info[qidx + 1].vec,
t3_intr_handler(adap,
adap->sge.qs[qidx].
rspq.polling), 0,
adap->msix_info[qidx + 1].desc,
&adap->sge.qs[qidx]);
if (err) {
while (--qidx >= 0)
free_irq(adap->msix_info[qidx + 1].vec,
&adap->sge.qs[qidx]);
return err;
}
qidx++;
}
}
return 0;
}
static void free_irq_resources(struct adapter *adapter)
{
if (adapter->flags & USING_MSIX) {
int i, n = 0;
free_irq(adapter->msix_info[0].vec, adapter);
for_each_port(adapter, i)
n += adap2pinfo(adapter, i)->nqsets;
for (i = 0; i < n; ++i)
free_irq(adapter->msix_info[i + 1].vec,
&adapter->sge.qs[i]);
} else
free_irq(adapter->pdev->irq, adapter);
}
static int await_mgmt_replies(struct adapter *adap, unsigned long init_cnt,
unsigned long n)
{
int attempts = 10;
while (adap->sge.qs[0].rspq.offload_pkts < init_cnt + n) {
if (!--attempts)
return -ETIMEDOUT;
msleep(10);
}
return 0;
}
static int init_tp_parity(struct adapter *adap)
{
int i;
struct sk_buff *skb;
struct cpl_set_tcb_field *greq;
unsigned long cnt = adap->sge.qs[0].rspq.offload_pkts;
t3_tp_set_offload_mode(adap, 1);
for (i = 0; i < 16; i++) {
struct cpl_smt_write_req *req;
skb = alloc_skb(sizeof(*req), GFP_KERNEL);
if (!skb)
skb = adap->nofail_skb;
if (!skb)
goto alloc_skb_fail;
req = (struct cpl_smt_write_req *)__skb_put(skb, sizeof(*req));
memset(req, 0, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_SMT_WRITE_REQ, i));
req->mtu_idx = NMTUS - 1;
req->iff = i;
t3_mgmt_tx(adap, skb);
if (skb == adap->nofail_skb) {
await_mgmt_replies(adap, cnt, i + 1);
adap->nofail_skb = alloc_skb(sizeof(*greq), GFP_KERNEL);
if (!adap->nofail_skb)
goto alloc_skb_fail;
}
}
for (i = 0; i < 2048; i++) {
struct cpl_l2t_write_req *req;
skb = alloc_skb(sizeof(*req), GFP_KERNEL);
if (!skb)
skb = adap->nofail_skb;
if (!skb)
goto alloc_skb_fail;
req = (struct cpl_l2t_write_req *)__skb_put(skb, sizeof(*req));
memset(req, 0, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_L2T_WRITE_REQ, i));
req->params = htonl(V_L2T_W_IDX(i));
t3_mgmt_tx(adap, skb);
if (skb == adap->nofail_skb) {
await_mgmt_replies(adap, cnt, 16 + i + 1);
adap->nofail_skb = alloc_skb(sizeof(*greq), GFP_KERNEL);
if (!adap->nofail_skb)
goto alloc_skb_fail;
}
}
for (i = 0; i < 2048; i++) {
struct cpl_rte_write_req *req;
skb = alloc_skb(sizeof(*req), GFP_KERNEL);
if (!skb)
skb = adap->nofail_skb;
if (!skb)
goto alloc_skb_fail;
req = (struct cpl_rte_write_req *)__skb_put(skb, sizeof(*req));
memset(req, 0, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_RTE_WRITE_REQ, i));
req->l2t_idx = htonl(V_L2T_W_IDX(i));
t3_mgmt_tx(adap, skb);
if (skb == adap->nofail_skb) {
await_mgmt_replies(adap, cnt, 16 + 2048 + i + 1);
adap->nofail_skb = alloc_skb(sizeof(*greq), GFP_KERNEL);
if (!adap->nofail_skb)
goto alloc_skb_fail;
}
}
skb = alloc_skb(sizeof(*greq), GFP_KERNEL);
if (!skb)
skb = adap->nofail_skb;
if (!skb)
goto alloc_skb_fail;
greq = (struct cpl_set_tcb_field *)__skb_put(skb, sizeof(*greq));
memset(greq, 0, sizeof(*greq));
greq->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
OPCODE_TID(greq) = htonl(MK_OPCODE_TID(CPL_SET_TCB_FIELD, 0));
greq->mask = cpu_to_be64(1);
t3_mgmt_tx(adap, skb);
i = await_mgmt_replies(adap, cnt, 16 + 2048 + 2048 + 1);
if (skb == adap->nofail_skb) {
i = await_mgmt_replies(adap, cnt, 16 + 2048 + 2048 + 1);
adap->nofail_skb = alloc_skb(sizeof(*greq), GFP_KERNEL);
}
t3_tp_set_offload_mode(adap, 0);
return i;
alloc_skb_fail:
t3_tp_set_offload_mode(adap, 0);
return -ENOMEM;
}
static void setup_rss(struct adapter *adap)
{
int i;
unsigned int nq0 = adap2pinfo(adap, 0)->nqsets;
unsigned int nq1 = adap->port[1] ? adap2pinfo(adap, 1)->nqsets : 1;
u8 cpus[SGE_QSETS + 1];
u16 rspq_map[RSS_TABLE_SIZE];
for (i = 0; i < SGE_QSETS; ++i)
cpus[i] = i;
cpus[SGE_QSETS] = 0xff;
for (i = 0; i < RSS_TABLE_SIZE / 2; ++i) {
rspq_map[i] = i % nq0;
rspq_map[i + RSS_TABLE_SIZE / 2] = (i % nq1) + nq0;
}
t3_config_rss(adap, F_RQFEEDBACKENABLE | F_TNLLKPEN | F_TNLMAPEN |
F_TNLPRTEN | F_TNL2TUPEN | F_TNL4TUPEN |
V_RRCPLCPUSIZE(6) | F_HASHTOEPLITZ, cpus, rspq_map);
}
static void ring_dbs(struct adapter *adap)
{
int i, j;
for (i = 0; i < SGE_QSETS; i++) {
struct sge_qset *qs = &adap->sge.qs[i];
if (qs->adap)
for (j = 0; j < SGE_TXQ_PER_SET; j++)
t3_write_reg(adap, A_SG_KDOORBELL, F_SELEGRCNTX | V_EGRCNTX(qs->txq[j].cntxt_id));
}
}
static void init_napi(struct adapter *adap)
{
int i;
for (i = 0; i < SGE_QSETS; i++) {
struct sge_qset *qs = &adap->sge.qs[i];
if (qs->adap)
netif_napi_add(qs->netdev, &qs->napi, qs->napi.poll,
64);
}
adap->flags |= NAPI_INIT;
}
static void quiesce_rx(struct adapter *adap)
{
int i;
for (i = 0; i < SGE_QSETS; i++)
if (adap->sge.qs[i].adap)
napi_disable(&adap->sge.qs[i].napi);
}
static void enable_all_napi(struct adapter *adap)
{
int i;
for (i = 0; i < SGE_QSETS; i++)
if (adap->sge.qs[i].adap)
napi_enable(&adap->sge.qs[i].napi);
}
static int setup_sge_qsets(struct adapter *adap)
{
int i, j, err, irq_idx = 0, qset_idx = 0;
unsigned int ntxq = SGE_TXQ_PER_SET;
if (adap->params.rev > 0 && !(adap->flags & USING_MSI))
irq_idx = -1;
for_each_port(adap, i) {
struct net_device *dev = adap->port[i];
struct port_info *pi = netdev_priv(dev);
pi->qs = &adap->sge.qs[pi->first_qset];
for (j = 0; j < pi->nqsets; ++j, ++qset_idx) {
err = t3_sge_alloc_qset(adap, qset_idx, 1,
(adap->flags & USING_MSIX) ? qset_idx + 1 :
irq_idx,
&adap->params.sge.qset[qset_idx], ntxq, dev,
netdev_get_tx_queue(dev, j));
if (err) {
t3_free_sge_resources(adap);
return err;
}
}
}
return 0;
}
static ssize_t attr_show(struct device *d, char *buf,
ssize_t(*format) (struct net_device *, char *))
{
ssize_t len;
rtnl_lock();
len = (*format) (to_net_dev(d), buf);
rtnl_unlock();
return len;
}
static ssize_t attr_store(struct device *d,
const char *buf, size_t len,
ssize_t(*set) (struct net_device *, unsigned int),
unsigned int min_val, unsigned int max_val)
{
char *endp;
ssize_t ret;
unsigned int val;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
val = simple_strtoul(buf, &endp, 0);
if (endp == buf || val < min_val || val > max_val)
return -EINVAL;
rtnl_lock();
ret = (*set) (to_net_dev(d), val);
if (!ret)
ret = len;
rtnl_unlock();
return ret;
}
static ssize_t set_nfilters(struct net_device *dev, unsigned int val)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adap = pi->adapter;
int min_tids = is_offload(adap) ? MC5_MIN_TIDS : 0;
if (adap->flags & FULL_INIT_DONE)
return -EBUSY;
if (val && adap->params.rev == 0)
return -EINVAL;
if (val > t3_mc5_size(&adap->mc5) - adap->params.mc5.nservers -
min_tids)
return -EINVAL;
adap->params.mc5.nfilters = val;
return 0;
}
static ssize_t store_nfilters(struct device *d, struct device_attribute *attr,
const char *buf, size_t len)
{
return attr_store(d, buf, len, set_nfilters, 0, ~0);
}
static ssize_t set_nservers(struct net_device *dev, unsigned int val)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adap = pi->adapter;
if (adap->flags & FULL_INIT_DONE)
return -EBUSY;
if (val > t3_mc5_size(&adap->mc5) - adap->params.mc5.nfilters -
MC5_MIN_TIDS)
return -EINVAL;
adap->params.mc5.nservers = val;
return 0;
}
static ssize_t store_nservers(struct device *d, struct device_attribute *attr,
const char *buf, size_t len)
{
return attr_store(d, buf, len, set_nservers, 0, ~0);
}
static ssize_t tm_attr_show(struct device *d,
char *buf, int sched)
{
struct port_info *pi = netdev_priv(to_net_dev(d));
struct adapter *adap = pi->adapter;
unsigned int v, addr, bpt, cpt;
ssize_t len;
addr = A_TP_TX_MOD_Q1_Q0_RATE_LIMIT - sched / 2;
rtnl_lock();
t3_write_reg(adap, A_TP_TM_PIO_ADDR, addr);
v = t3_read_reg(adap, A_TP_TM_PIO_DATA);
if (sched & 1)
v >>= 16;
bpt = (v >> 8) & 0xff;
cpt = v & 0xff;
if (!cpt)
len = sprintf(buf, "disabled\n");
else {
v = (adap->params.vpd.cclk * 1000) / cpt;
len = sprintf(buf, "%u Kbps\n", (v * bpt) / 125);
}
rtnl_unlock();
return len;
}
static ssize_t tm_attr_store(struct device *d,
const char *buf, size_t len, int sched)
{
struct port_info *pi = netdev_priv(to_net_dev(d));
struct adapter *adap = pi->adapter;
unsigned int val;
char *endp;
ssize_t ret;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
val = simple_strtoul(buf, &endp, 0);
if (endp == buf || val > 10000000)
return -EINVAL;
rtnl_lock();
ret = t3_config_sched(adap, val, sched);
if (!ret)
ret = len;
rtnl_unlock();
return ret;
}
static inline int offload_tx(struct t3cdev *tdev, struct sk_buff *skb)
{
int ret;
local_bh_disable();
ret = t3_offload_tx(tdev, skb);
local_bh_enable();
return ret;
}
static int write_smt_entry(struct adapter *adapter, int idx)
{
struct cpl_smt_write_req *req;
struct port_info *pi = netdev_priv(adapter->port[idx]);
struct sk_buff *skb = alloc_skb(sizeof(*req), GFP_KERNEL);
if (!skb)
return -ENOMEM;
req = (struct cpl_smt_write_req *)__skb_put(skb, sizeof(*req));
req->wr.wr_hi = htonl(V_WR_OP(FW_WROPCODE_FORWARD));
OPCODE_TID(req) = htonl(MK_OPCODE_TID(CPL_SMT_WRITE_REQ, idx));
req->mtu_idx = NMTUS - 1;
req->iff = idx;
memcpy(req->src_mac0, adapter->port[idx]->dev_addr, ETH_ALEN);
memcpy(req->src_mac1, pi->iscsic.mac_addr, ETH_ALEN);
skb->priority = 1;
offload_tx(&adapter->tdev, skb);
return 0;
}
static int init_smt(struct adapter *adapter)
{
int i;
for_each_port(adapter, i)
write_smt_entry(adapter, i);
return 0;
}
static void init_port_mtus(struct adapter *adapter)
{
unsigned int mtus = adapter->port[0]->mtu;
if (adapter->port[1])
mtus |= adapter->port[1]->mtu << 16;
t3_write_reg(adapter, A_TP_MTU_PORT_TABLE, mtus);
}
static int send_pktsched_cmd(struct adapter *adap, int sched, int qidx, int lo,
int hi, int port)
{
struct sk_buff *skb;
struct mngt_pktsched_wr *req;
int ret;
skb = alloc_skb(sizeof(*req), GFP_KERNEL);
if (!skb)
skb = adap->nofail_skb;
if (!skb)
return -ENOMEM;
req = (struct mngt_pktsched_wr *)skb_put(skb, sizeof(*req));
req->wr_hi = htonl(V_WR_OP(FW_WROPCODE_MNGT));
req->mngt_opcode = FW_MNGTOPCODE_PKTSCHED_SET;
req->sched = sched;
req->idx = qidx;
req->min = lo;
req->max = hi;
req->binding = port;
ret = t3_mgmt_tx(adap, skb);
if (skb == adap->nofail_skb) {
adap->nofail_skb = alloc_skb(sizeof(struct cpl_set_tcb_field),
GFP_KERNEL);
if (!adap->nofail_skb)
ret = -ENOMEM;
}
return ret;
}
static int bind_qsets(struct adapter *adap)
{
int i, j, err = 0;
for_each_port(adap, i) {
const struct port_info *pi = adap2pinfo(adap, i);
for (j = 0; j < pi->nqsets; ++j) {
int ret = send_pktsched_cmd(adap, 1,
pi->first_qset + j, -1,
-1, i);
if (ret)
err = ret;
}
}
return err;
}
static inline const char *get_edc_fw_name(int edc_idx)
{
const char *fw_name = NULL;
switch (edc_idx) {
case EDC_OPT_AEL2005:
fw_name = AEL2005_OPT_EDC_NAME;
break;
case EDC_TWX_AEL2005:
fw_name = AEL2005_TWX_EDC_NAME;
break;
case EDC_TWX_AEL2020:
fw_name = AEL2020_TWX_EDC_NAME;
break;
}
return fw_name;
}
int t3_get_edc_fw(struct cphy *phy, int edc_idx, int size)
{
struct adapter *adapter = phy->adapter;
const struct firmware *fw;
char buf[64];
u32 csum;
const __be32 *p;
u16 *cache = phy->phy_cache;
int i, ret;
snprintf(buf, sizeof(buf), get_edc_fw_name(edc_idx));
ret = request_firmware(&fw, buf, &adapter->pdev->dev);
if (ret < 0) {
dev_err(&adapter->pdev->dev,
"could not upgrade firmware: unable to load %s\n",
buf);
return ret;
}
if (fw->size > size + 4) {
CH_ERR(adapter, "firmware image too large %u, expected %d\n",
(unsigned int)fw->size, size + 4);
ret = -EINVAL;
}
p = (const __be32 *)fw->data;
for (csum = 0, i = 0; i < fw->size / sizeof(csum); i++)
csum += ntohl(p[i]);
if (csum != 0xffffffff) {
CH_ERR(adapter, "corrupted firmware image, checksum %u\n",
csum);
ret = -EINVAL;
}
for (i = 0; i < size / 4 ; i++) {
*cache++ = (be32_to_cpu(p[i]) & 0xffff0000) >> 16;
*cache++ = be32_to_cpu(p[i]) & 0xffff;
}
release_firmware(fw);
return ret;
}
static int upgrade_fw(struct adapter *adap)
{
int ret;
const struct firmware *fw;
struct device *dev = &adap->pdev->dev;
ret = request_firmware(&fw, FW_FNAME, dev);
if (ret < 0) {
dev_err(dev, "could not upgrade firmware: unable to load %s\n",
FW_FNAME);
return ret;
}
ret = t3_load_fw(adap, fw->data, fw->size);
release_firmware(fw);
if (ret == 0)
dev_info(dev, "successful upgrade to firmware %d.%d.%d\n",
FW_VERSION_MAJOR, FW_VERSION_MINOR, FW_VERSION_MICRO);
else
dev_err(dev, "failed to upgrade to firmware %d.%d.%d\n",
FW_VERSION_MAJOR, FW_VERSION_MINOR, FW_VERSION_MICRO);
return ret;
}
static inline char t3rev2char(struct adapter *adapter)
{
char rev = 0;
switch(adapter->params.rev) {
case T3_REV_B:
case T3_REV_B2:
rev = 'b';
break;
case T3_REV_C:
rev = 'c';
break;
}
return rev;
}
static int update_tpsram(struct adapter *adap)
{
const struct firmware *tpsram;
char buf[64];
struct device *dev = &adap->pdev->dev;
int ret;
char rev;
rev = t3rev2char(adap);
if (!rev)
return 0;
snprintf(buf, sizeof(buf), TPSRAM_NAME, rev);
ret = request_firmware(&tpsram, buf, dev);
if (ret < 0) {
dev_err(dev, "could not load TP SRAM: unable to load %s\n",
buf);
return ret;
}
ret = t3_check_tpsram(adap, tpsram->data, tpsram->size);
if (ret)
goto release_tpsram;
ret = t3_set_proto_sram(adap, tpsram->data);
if (ret == 0)
dev_info(dev,
"successful update of protocol engine "
"to %d.%d.%d\n",
TP_VERSION_MAJOR, TP_VERSION_MINOR, TP_VERSION_MICRO);
else
dev_err(dev, "failed to update of protocol engine %d.%d.%d\n",
TP_VERSION_MAJOR, TP_VERSION_MINOR, TP_VERSION_MICRO);
if (ret)
dev_err(dev, "loading protocol SRAM failed\n");
release_tpsram:
release_firmware(tpsram);
return ret;
}
static void t3_synchronize_rx(struct adapter *adap, const struct port_info *p)
{
int i;
for (i = p->first_qset; i < p->first_qset + p->nqsets; i++) {
struct sge_rspq *q = &adap->sge.qs[i].rspq;
spin_lock_irq(&q->lock);
spin_unlock_irq(&q->lock);
}
}
static void cxgb_vlan_mode(struct net_device *dev, netdev_features_t features)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
if (adapter->params.rev > 0) {
t3_set_vlan_accel(adapter, 1 << pi->port_id,
features & NETIF_F_HW_VLAN_CTAG_RX);
} else {
unsigned int i, have_vlans = features & NETIF_F_HW_VLAN_CTAG_RX;
for_each_port(adapter, i)
have_vlans |=
adapter->port[i]->features &
NETIF_F_HW_VLAN_CTAG_RX;
t3_set_vlan_accel(adapter, 1, have_vlans);
}
t3_synchronize_rx(adapter, pi);
}
static int cxgb_up(struct adapter *adap)
{
int i, err;
if (!(adap->flags & FULL_INIT_DONE)) {
err = t3_check_fw_version(adap);
if (err == -EINVAL) {
err = upgrade_fw(adap);
CH_WARN(adap, "FW upgrade to %d.%d.%d %s\n",
FW_VERSION_MAJOR, FW_VERSION_MINOR,
FW_VERSION_MICRO, err ? "failed" : "succeeded");
}
err = t3_check_tpsram_version(adap);
if (err == -EINVAL) {
err = update_tpsram(adap);
CH_WARN(adap, "TP upgrade to %d.%d.%d %s\n",
TP_VERSION_MAJOR, TP_VERSION_MINOR,
TP_VERSION_MICRO, err ? "failed" : "succeeded");
}
t3_intr_clear(adap);
err = t3_init_hw(adap, 0);
if (err)
goto out;
t3_set_reg_field(adap, A_TP_PARA_REG5, 0, F_RXDDPOFFINIT);
t3_write_reg(adap, A_ULPRX_TDDP_PSZ, V_HPZ0(PAGE_SHIFT - 12));
err = setup_sge_qsets(adap);
if (err)
goto out;
for_each_port(adap, i)
cxgb_vlan_mode(adap->port[i], adap->port[i]->features);
setup_rss(adap);
if (!(adap->flags & NAPI_INIT))
init_napi(adap);
t3_start_sge_timers(adap);
adap->flags |= FULL_INIT_DONE;
}
t3_intr_clear(adap);
if (adap->flags & USING_MSIX) {
name_msix_vecs(adap);
err = request_irq(adap->msix_info[0].vec,
t3_async_intr_handler, 0,
adap->msix_info[0].desc, adap);
if (err)
goto irq_err;
err = request_msix_data_irqs(adap);
if (err) {
free_irq(adap->msix_info[0].vec, adap);
goto irq_err;
}
} else if ((err = request_irq(adap->pdev->irq,
t3_intr_handler(adap,
adap->sge.qs[0].rspq.
polling),
(adap->flags & USING_MSI) ?
0 : IRQF_SHARED,
adap->name, adap)))
goto irq_err;
enable_all_napi(adap);
t3_sge_start(adap);
t3_intr_enable(adap);
if (adap->params.rev >= T3_REV_C && !(adap->flags & TP_PARITY_INIT) &&
is_offload(adap) && init_tp_parity(adap) == 0)
adap->flags |= TP_PARITY_INIT;
if (adap->flags & TP_PARITY_INIT) {
t3_write_reg(adap, A_TP_INT_CAUSE,
F_CMCACHEPERR | F_ARPLUTPERR);
t3_write_reg(adap, A_TP_INT_ENABLE, 0x7fbfffff);
}
if (!(adap->flags & QUEUES_BOUND)) {
int ret = bind_qsets(adap);
if (ret < 0) {
CH_ERR(adap, "failed to bind qsets, err %d\n", ret);
t3_intr_disable(adap);
free_irq_resources(adap);
err = ret;
goto out;
}
adap->flags |= QUEUES_BOUND;
}
out:
return err;
irq_err:
CH_ERR(adap, "request_irq failed, err %d\n", err);
goto out;
}
static void cxgb_down(struct adapter *adapter, int on_wq)
{
t3_sge_stop(adapter);
spin_lock_irq(&adapter->work_lock);
t3_intr_disable(adapter);
spin_unlock_irq(&adapter->work_lock);
free_irq_resources(adapter);
quiesce_rx(adapter);
t3_sge_stop(adapter);
if (!on_wq)
flush_workqueue(cxgb3_wq);
}
static void schedule_chk_task(struct adapter *adap)
{
unsigned int timeo;
timeo = adap->params.linkpoll_period ?
(HZ * adap->params.linkpoll_period) / 10 :
adap->params.stats_update_period * HZ;
if (timeo)
queue_delayed_work(cxgb3_wq, &adap->adap_check_task, timeo);
}
static int offload_open(struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
struct t3cdev *tdev = dev2t3cdev(dev);
int adap_up = adapter->open_device_map & PORT_MASK;
int err;
if (test_and_set_bit(OFFLOAD_DEVMAP_BIT, &adapter->open_device_map))
return 0;
if (!adap_up && (err = cxgb_up(adapter)) < 0)
goto out;
t3_tp_set_offload_mode(adapter, 1);
tdev->lldev = adapter->port[0];
err = cxgb3_offload_activate(adapter);
if (err)
goto out;
init_port_mtus(adapter);
t3_load_mtus(adapter, adapter->params.mtus, adapter->params.a_wnd,
adapter->params.b_wnd,
adapter->params.rev == 0 ?
adapter->port[0]->mtu : 0xffff);
init_smt(adapter);
if (sysfs_create_group(&tdev->lldev->dev.kobj, &offload_attr_group))
dev_dbg(&dev->dev, "cannot create sysfs group\n");
cxgb3_add_clients(tdev);
out:
if (err) {
t3_tp_set_offload_mode(adapter, 0);
clear_bit(OFFLOAD_DEVMAP_BIT, &adapter->open_device_map);
cxgb3_set_dummy_ops(tdev);
}
return err;
}
static int offload_close(struct t3cdev *tdev)
{
struct adapter *adapter = tdev2adap(tdev);
struct t3c_data *td = T3C_DATA(tdev);
if (!test_bit(OFFLOAD_DEVMAP_BIT, &adapter->open_device_map))
return 0;
cxgb3_remove_clients(tdev);
sysfs_remove_group(&tdev->lldev->dev.kobj, &offload_attr_group);
flush_work(&td->tid_release_task);
tdev->lldev = NULL;
cxgb3_set_dummy_ops(tdev);
t3_tp_set_offload_mode(adapter, 0);
clear_bit(OFFLOAD_DEVMAP_BIT, &adapter->open_device_map);
if (!adapter->open_device_map)
cxgb_down(adapter, 0);
cxgb3_offload_deactivate(adapter);
return 0;
}
static int cxgb_open(struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
int other_ports = adapter->open_device_map & PORT_MASK;
int err;
if (!adapter->open_device_map && (err = cxgb_up(adapter)) < 0)
return err;
set_bit(pi->port_id, &adapter->open_device_map);
if (is_offload(adapter) && !ofld_disable) {
err = offload_open(dev);
if (err)
pr_warn("Could not initialize offload capabilities\n");
}
netif_set_real_num_tx_queues(dev, pi->nqsets);
err = netif_set_real_num_rx_queues(dev, pi->nqsets);
if (err)
return err;
link_start(dev);
t3_port_intr_enable(adapter, pi->port_id);
netif_tx_start_all_queues(dev);
if (!other_ports)
schedule_chk_task(adapter);
cxgb3_event_notify(&adapter->tdev, OFFLOAD_PORT_UP, pi->port_id);
return 0;
}
static int __cxgb_close(struct net_device *dev, int on_wq)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
if (!adapter->open_device_map)
return 0;
t3_xgm_intr_disable(adapter, pi->port_id);
t3_read_reg(adapter, A_XGM_INT_STATUS + pi->mac.offset);
t3_port_intr_disable(adapter, pi->port_id);
netif_tx_stop_all_queues(dev);
pi->phy.ops->power_down(&pi->phy, 1);
netif_carrier_off(dev);
t3_mac_disable(&pi->mac, MAC_DIRECTION_TX | MAC_DIRECTION_RX);
spin_lock_irq(&adapter->work_lock);
clear_bit(pi->port_id, &adapter->open_device_map);
spin_unlock_irq(&adapter->work_lock);
if (!(adapter->open_device_map & PORT_MASK))
cancel_delayed_work_sync(&adapter->adap_check_task);
if (!adapter->open_device_map)
cxgb_down(adapter, on_wq);
cxgb3_event_notify(&adapter->tdev, OFFLOAD_PORT_DOWN, pi->port_id);
return 0;
}
static int cxgb_close(struct net_device *dev)
{
return __cxgb_close(dev, 0);
}
static struct net_device_stats *cxgb_get_stats(struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
struct net_device_stats *ns = &pi->netstats;
const struct mac_stats *pstats;
spin_lock(&adapter->stats_lock);
pstats = t3_mac_update_stats(&pi->mac);
spin_unlock(&adapter->stats_lock);
ns->tx_bytes = pstats->tx_octets;
ns->tx_packets = pstats->tx_frames;
ns->rx_bytes = pstats->rx_octets;
ns->rx_packets = pstats->rx_frames;
ns->multicast = pstats->rx_mcast_frames;
ns->tx_errors = pstats->tx_underrun;
ns->rx_errors = pstats->rx_symbol_errs + pstats->rx_fcs_errs +
pstats->rx_too_long + pstats->rx_jabber + pstats->rx_short +
pstats->rx_fifo_ovfl;
ns->rx_length_errors = pstats->rx_jabber + pstats->rx_too_long;
ns->rx_over_errors = 0;
ns->rx_crc_errors = pstats->rx_fcs_errs;
ns->rx_frame_errors = pstats->rx_symbol_errs;
ns->rx_fifo_errors = pstats->rx_fifo_ovfl;
ns->rx_missed_errors = pstats->rx_cong_drops;
ns->tx_aborted_errors = 0;
ns->tx_carrier_errors = 0;
ns->tx_fifo_errors = pstats->tx_underrun;
ns->tx_heartbeat_errors = 0;
ns->tx_window_errors = 0;
return ns;
}
static u32 get_msglevel(struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
return adapter->msg_enable;
}
static void set_msglevel(struct net_device *dev, u32 val)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
adapter->msg_enable = val;
}
static int get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(stats_strings);
default:
return -EOPNOTSUPP;
}
}
static int get_regs_len(struct net_device *dev)
{
return T3_REGMAP_SIZE;
}
static int get_eeprom_len(struct net_device *dev)
{
return EEPROMSIZE;
}
static void get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
u32 fw_vers = 0;
u32 tp_vers = 0;
spin_lock(&adapter->stats_lock);
t3_get_fw_version(adapter, &fw_vers);
t3_get_tp_version(adapter, &tp_vers);
spin_unlock(&adapter->stats_lock);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(adapter->pdev),
sizeof(info->bus_info));
if (fw_vers)
snprintf(info->fw_version, sizeof(info->fw_version),
"%s %u.%u.%u TP %u.%u.%u",
G_FW_VERSION_TYPE(fw_vers) ? "T" : "N",
G_FW_VERSION_MAJOR(fw_vers),
G_FW_VERSION_MINOR(fw_vers),
G_FW_VERSION_MICRO(fw_vers),
G_TP_VERSION_MAJOR(tp_vers),
G_TP_VERSION_MINOR(tp_vers),
G_TP_VERSION_MICRO(tp_vers));
}
static void get_strings(struct net_device *dev, u32 stringset, u8 * data)
{
if (stringset == ETH_SS_STATS)
memcpy(data, stats_strings, sizeof(stats_strings));
}
static unsigned long collect_sge_port_stats(struct adapter *adapter,
struct port_info *p, int idx)
{
int i;
unsigned long tot = 0;
for (i = p->first_qset; i < p->first_qset + p->nqsets; ++i)
tot += adapter->sge.qs[i].port_stats[idx];
return tot;
}
static void get_stats(struct net_device *dev, struct ethtool_stats *stats,
u64 *data)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
const struct mac_stats *s;
spin_lock(&adapter->stats_lock);
s = t3_mac_update_stats(&pi->mac);
spin_unlock(&adapter->stats_lock);
*data++ = s->tx_octets;
*data++ = s->tx_frames;
*data++ = s->tx_mcast_frames;
*data++ = s->tx_bcast_frames;
*data++ = s->tx_pause;
*data++ = s->tx_underrun;
*data++ = s->tx_fifo_urun;
*data++ = s->tx_frames_64;
*data++ = s->tx_frames_65_127;
*data++ = s->tx_frames_128_255;
*data++ = s->tx_frames_256_511;
*data++ = s->tx_frames_512_1023;
*data++ = s->tx_frames_1024_1518;
*data++ = s->tx_frames_1519_max;
*data++ = s->rx_octets;
*data++ = s->rx_frames;
*data++ = s->rx_mcast_frames;
*data++ = s->rx_bcast_frames;
*data++ = s->rx_pause;
*data++ = s->rx_fcs_errs;
*data++ = s->rx_symbol_errs;
*data++ = s->rx_short;
*data++ = s->rx_jabber;
*data++ = s->rx_too_long;
*data++ = s->rx_fifo_ovfl;
*data++ = s->rx_frames_64;
*data++ = s->rx_frames_65_127;
*data++ = s->rx_frames_128_255;
*data++ = s->rx_frames_256_511;
*data++ = s->rx_frames_512_1023;
*data++ = s->rx_frames_1024_1518;
*data++ = s->rx_frames_1519_max;
*data++ = pi->phy.fifo_errors;
*data++ = collect_sge_port_stats(adapter, pi, SGE_PSTAT_TSO);
*data++ = collect_sge_port_stats(adapter, pi, SGE_PSTAT_VLANEX);
*data++ = collect_sge_port_stats(adapter, pi, SGE_PSTAT_VLANINS);
*data++ = collect_sge_port_stats(adapter, pi, SGE_PSTAT_TX_CSUM);
*data++ = collect_sge_port_stats(adapter, pi, SGE_PSTAT_RX_CSUM_GOOD);
*data++ = 0;
*data++ = 0;
*data++ = 0;
*data++ = s->rx_cong_drops;
*data++ = s->num_toggled;
*data++ = s->num_resets;
*data++ = s->link_faults;
}
static inline void reg_block_dump(struct adapter *ap, void *buf,
unsigned int start, unsigned int end)
{
u32 *p = buf + start;
for (; start <= end; start += sizeof(u32))
*p++ = t3_read_reg(ap, start);
}
static void get_regs(struct net_device *dev, struct ethtool_regs *regs,
void *buf)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *ap = pi->adapter;
regs->version = 3 | (ap->params.rev << 10) | (is_pcie(ap) << 31);
memset(buf, 0, T3_REGMAP_SIZE);
reg_block_dump(ap, buf, 0, A_SG_RSPQ_CREDIT_RETURN);
reg_block_dump(ap, buf, A_SG_HI_DRB_HI_THRSH, A_ULPRX_PBL_ULIMIT);
reg_block_dump(ap, buf, A_ULPTX_CONFIG, A_MPS_INT_CAUSE);
reg_block_dump(ap, buf, A_CPL_SWITCH_CNTRL, A_CPL_MAP_TBL_DATA);
reg_block_dump(ap, buf, A_SMB_GLOBAL_TIME_CFG, A_XGM_SERDES_STAT3);
reg_block_dump(ap, buf, A_XGM_SERDES_STATUS0,
XGM_REG(A_XGM_SERDES_STAT3, 1));
reg_block_dump(ap, buf, XGM_REG(A_XGM_SERDES_STATUS0, 1),
XGM_REG(A_XGM_RX_SPI4_SOP_EOP_CNT, 1));
}
static int restart_autoneg(struct net_device *dev)
{
struct port_info *p = netdev_priv(dev);
if (!netif_running(dev))
return -EAGAIN;
if (p->link_config.autoneg != AUTONEG_ENABLE)
return -EINVAL;
p->phy.ops->autoneg_restart(&p->phy);
return 0;
}
static int set_phys_id(struct net_device *dev,
enum ethtool_phys_id_state state)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
switch (state) {
case ETHTOOL_ID_ACTIVE:
return 1;
case ETHTOOL_ID_OFF:
t3_set_reg_field(adapter, A_T3DBG_GPIO_EN, F_GPIO0_OUT_VAL, 0);
break;
case ETHTOOL_ID_ON:
case ETHTOOL_ID_INACTIVE:
t3_set_reg_field(adapter, A_T3DBG_GPIO_EN, F_GPIO0_OUT_VAL,
F_GPIO0_OUT_VAL);
}
return 0;
}
static int get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct port_info *p = netdev_priv(dev);
cmd->supported = p->link_config.supported;
cmd->advertising = p->link_config.advertising;
if (netif_carrier_ok(dev)) {
ethtool_cmd_speed_set(cmd, p->link_config.speed);
cmd->duplex = p->link_config.duplex;
} else {
ethtool_cmd_speed_set(cmd, -1);
cmd->duplex = -1;
}
cmd->port = (cmd->supported & SUPPORTED_TP) ? PORT_TP : PORT_FIBRE;
cmd->phy_address = p->phy.mdio.prtad;
cmd->transceiver = XCVR_EXTERNAL;
cmd->autoneg = p->link_config.autoneg;
cmd->maxtxpkt = 0;
cmd->maxrxpkt = 0;
return 0;
}
static int speed_duplex_to_caps(int speed, int duplex)
{
int cap = 0;
switch (speed) {
case SPEED_10:
if (duplex == DUPLEX_FULL)
cap = SUPPORTED_10baseT_Full;
else
cap = SUPPORTED_10baseT_Half;
break;
case SPEED_100:
if (duplex == DUPLEX_FULL)
cap = SUPPORTED_100baseT_Full;
else
cap = SUPPORTED_100baseT_Half;
break;
case SPEED_1000:
if (duplex == DUPLEX_FULL)
cap = SUPPORTED_1000baseT_Full;
else
cap = SUPPORTED_1000baseT_Half;
break;
case SPEED_10000:
if (duplex == DUPLEX_FULL)
cap = SUPPORTED_10000baseT_Full;
}
return cap;
}
static int set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct port_info *p = netdev_priv(dev);
struct link_config *lc = &p->link_config;
if (!(lc->supported & SUPPORTED_Autoneg)) {
if (cmd->autoneg == AUTONEG_DISABLE) {
u32 speed = ethtool_cmd_speed(cmd);
int cap = speed_duplex_to_caps(speed, cmd->duplex);
if (lc->supported & cap)
return 0;
}
return -EINVAL;
}
if (cmd->autoneg == AUTONEG_DISABLE) {
u32 speed = ethtool_cmd_speed(cmd);
int cap = speed_duplex_to_caps(speed, cmd->duplex);
if (!(lc->supported & cap) || (speed == SPEED_1000))
return -EINVAL;
lc->requested_speed = speed;
lc->requested_duplex = cmd->duplex;
lc->advertising = 0;
} else {
cmd->advertising &= ADVERTISED_MASK;
cmd->advertising &= lc->supported;
if (!cmd->advertising)
return -EINVAL;
lc->requested_speed = SPEED_INVALID;
lc->requested_duplex = DUPLEX_INVALID;
lc->advertising = cmd->advertising | ADVERTISED_Autoneg;
}
lc->autoneg = cmd->autoneg;
if (netif_running(dev))
t3_link_start(&p->phy, &p->mac, lc);
return 0;
}
static void get_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *epause)
{
struct port_info *p = netdev_priv(dev);
epause->autoneg = (p->link_config.requested_fc & PAUSE_AUTONEG) != 0;
epause->rx_pause = (p->link_config.fc & PAUSE_RX) != 0;
epause->tx_pause = (p->link_config.fc & PAUSE_TX) != 0;
}
static int set_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *epause)
{
struct port_info *p = netdev_priv(dev);
struct link_config *lc = &p->link_config;
if (epause->autoneg == AUTONEG_DISABLE)
lc->requested_fc = 0;
else if (lc->supported & SUPPORTED_Autoneg)
lc->requested_fc = PAUSE_AUTONEG;
else
return -EINVAL;
if (epause->rx_pause)
lc->requested_fc |= PAUSE_RX;
if (epause->tx_pause)
lc->requested_fc |= PAUSE_TX;
if (lc->autoneg == AUTONEG_ENABLE) {
if (netif_running(dev))
t3_link_start(&p->phy, &p->mac, lc);
} else {
lc->fc = lc->requested_fc & (PAUSE_RX | PAUSE_TX);
if (netif_running(dev))
t3_mac_set_speed_duplex_fc(&p->mac, -1, -1, lc->fc);
}
return 0;
}
static void get_sge_param(struct net_device *dev, struct ethtool_ringparam *e)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
const struct qset_params *q = &adapter->params.sge.qset[pi->first_qset];
e->rx_max_pending = MAX_RX_BUFFERS;
e->rx_jumbo_max_pending = MAX_RX_JUMBO_BUFFERS;
e->tx_max_pending = MAX_TXQ_ENTRIES;
e->rx_pending = q->fl_size;
e->rx_mini_pending = q->rspq_size;
e->rx_jumbo_pending = q->jumbo_size;
e->tx_pending = q->txq_size[0];
}
static int set_sge_param(struct net_device *dev, struct ethtool_ringparam *e)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
struct qset_params *q;
int i;
if (e->rx_pending > MAX_RX_BUFFERS ||
e->rx_jumbo_pending > MAX_RX_JUMBO_BUFFERS ||
e->tx_pending > MAX_TXQ_ENTRIES ||
e->rx_mini_pending > MAX_RSPQ_ENTRIES ||
e->rx_mini_pending < MIN_RSPQ_ENTRIES ||
e->rx_pending < MIN_FL_ENTRIES ||
e->rx_jumbo_pending < MIN_FL_ENTRIES ||
e->tx_pending < adapter->params.nports * MIN_TXQ_ENTRIES)
return -EINVAL;
if (adapter->flags & FULL_INIT_DONE)
return -EBUSY;
q = &adapter->params.sge.qset[pi->first_qset];
for (i = 0; i < pi->nqsets; ++i, ++q) {
q->rspq_size = e->rx_mini_pending;
q->fl_size = e->rx_pending;
q->jumbo_size = e->rx_jumbo_pending;
q->txq_size[0] = e->tx_pending;
q->txq_size[1] = e->tx_pending;
q->txq_size[2] = e->tx_pending;
}
return 0;
}
static int set_coalesce(struct net_device *dev, struct ethtool_coalesce *c)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
struct qset_params *qsp;
struct sge_qset *qs;
int i;
if (c->rx_coalesce_usecs * 10 > M_NEWTIMER)
return -EINVAL;
for (i = 0; i < pi->nqsets; i++) {
qsp = &adapter->params.sge.qset[i];
qs = &adapter->sge.qs[i];
qsp->coalesce_usecs = c->rx_coalesce_usecs;
t3_update_qset_coalesce(qs, qsp);
}
return 0;
}
static int get_coalesce(struct net_device *dev, struct ethtool_coalesce *c)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
struct qset_params *q = adapter->params.sge.qset;
c->rx_coalesce_usecs = q->coalesce_usecs;
return 0;
}
static int get_eeprom(struct net_device *dev, struct ethtool_eeprom *e,
u8 * data)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
int i, err = 0;
u8 *buf = kmalloc(EEPROMSIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
e->magic = EEPROM_MAGIC;
for (i = e->offset & ~3; !err && i < e->offset + e->len; i += 4)
err = t3_seeprom_read(adapter, i, (__le32 *) & buf[i]);
if (!err)
memcpy(data, buf + e->offset, e->len);
kfree(buf);
return err;
}
static int set_eeprom(struct net_device *dev, struct ethtool_eeprom *eeprom,
u8 * data)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
u32 aligned_offset, aligned_len;
__le32 *p;
u8 *buf;
int err;
if (eeprom->magic != EEPROM_MAGIC)
return -EINVAL;
aligned_offset = eeprom->offset & ~3;
aligned_len = (eeprom->len + (eeprom->offset & 3) + 3) & ~3;
if (aligned_offset != eeprom->offset || aligned_len != eeprom->len) {
buf = kmalloc(aligned_len, GFP_KERNEL);
if (!buf)
return -ENOMEM;
err = t3_seeprom_read(adapter, aligned_offset, (__le32 *) buf);
if (!err && aligned_len > 4)
err = t3_seeprom_read(adapter,
aligned_offset + aligned_len - 4,
(__le32 *) & buf[aligned_len - 4]);
if (err)
goto out;
memcpy(buf + (eeprom->offset & 3), data, eeprom->len);
} else
buf = data;
err = t3_seeprom_wp(adapter, 0);
if (err)
goto out;
for (p = (__le32 *) buf; !err && aligned_len; aligned_len -= 4, p++) {
err = t3_seeprom_write(adapter, aligned_offset, *p);
aligned_offset += 4;
}
if (!err)
err = t3_seeprom_wp(adapter, 1);
out:
if (buf != data)
kfree(buf);
return err;
}
static void get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
wol->supported = 0;
wol->wolopts = 0;
memset(&wol->sopass, 0, sizeof(wol->sopass));
}
static int in_range(int val, int lo, int hi)
{
return val < 0 || (val <= hi && val >= lo);
}
static int cxgb_extension_ioctl(struct net_device *dev, void __user *useraddr)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
u32 cmd;
int ret;
if (copy_from_user(&cmd, useraddr, sizeof(cmd)))
return -EFAULT;
switch (cmd) {
case CHELSIO_SET_QSET_PARAMS:{
int i;
struct qset_params *q;
struct ch_qset_params t;
int q1 = pi->first_qset;
int nqsets = pi->nqsets;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (copy_from_user(&t, useraddr, sizeof(t)))
return -EFAULT;
if (t.qset_idx >= SGE_QSETS)
return -EINVAL;
if (!in_range(t.intr_lat, 0, M_NEWTIMER) ||
!in_range(t.cong_thres, 0, 255) ||
!in_range(t.txq_size[0], MIN_TXQ_ENTRIES,
MAX_TXQ_ENTRIES) ||
!in_range(t.txq_size[1], MIN_TXQ_ENTRIES,
MAX_TXQ_ENTRIES) ||
!in_range(t.txq_size[2], MIN_CTRL_TXQ_ENTRIES,
MAX_CTRL_TXQ_ENTRIES) ||
!in_range(t.fl_size[0], MIN_FL_ENTRIES,
MAX_RX_BUFFERS) ||
!in_range(t.fl_size[1], MIN_FL_ENTRIES,
MAX_RX_JUMBO_BUFFERS) ||
!in_range(t.rspq_size, MIN_RSPQ_ENTRIES,
MAX_RSPQ_ENTRIES))
return -EINVAL;
if ((adapter->flags & FULL_INIT_DONE) &&
(t.rspq_size >= 0 || t.fl_size[0] >= 0 ||
t.fl_size[1] >= 0 || t.txq_size[0] >= 0 ||
t.txq_size[1] >= 0 || t.txq_size[2] >= 0 ||
t.polling >= 0 || t.cong_thres >= 0))
return -EBUSY;
if (test_bit(OFFLOAD_DEVMAP_BIT, &adapter->open_device_map)) {
q1 = 0;
for_each_port(adapter, i) {
pi = adap2pinfo(adapter, i);
nqsets += pi->first_qset + pi->nqsets;
}
}
if (t.qset_idx < q1)
return -EINVAL;
if (t.qset_idx > q1 + nqsets - 1)
return -EINVAL;
q = &adapter->params.sge.qset[t.qset_idx];
if (t.rspq_size >= 0)
q->rspq_size = t.rspq_size;
if (t.fl_size[0] >= 0)
q->fl_size = t.fl_size[0];
if (t.fl_size[1] >= 0)
q->jumbo_size = t.fl_size[1];
if (t.txq_size[0] >= 0)
q->txq_size[0] = t.txq_size[0];
if (t.txq_size[1] >= 0)
q->txq_size[1] = t.txq_size[1];
if (t.txq_size[2] >= 0)
q->txq_size[2] = t.txq_size[2];
if (t.cong_thres >= 0)
q->cong_thres = t.cong_thres;
if (t.intr_lat >= 0) {
struct sge_qset *qs =
&adapter->sge.qs[t.qset_idx];
q->coalesce_usecs = t.intr_lat;
t3_update_qset_coalesce(qs, q);
}
if (t.polling >= 0) {
if (adapter->flags & USING_MSIX)
q->polling = t.polling;
else {
if (adapter->params.rev == 0 &&
!(adapter->flags & USING_MSI))
t.polling = 0;
for (i = 0; i < SGE_QSETS; i++) {
q = &adapter->params.sge.
qset[i];
q->polling = t.polling;
}
}
}
if (t.lro >= 0) {
if (t.lro)
dev->wanted_features |= NETIF_F_GRO;
else
dev->wanted_features &= ~NETIF_F_GRO;
netdev_update_features(dev);
}
break;
}
case CHELSIO_GET_QSET_PARAMS:{
struct qset_params *q;
struct ch_qset_params t;
int q1 = pi->first_qset;
int nqsets = pi->nqsets;
int i;
if (copy_from_user(&t, useraddr, sizeof(t)))
return -EFAULT;
if (test_bit(OFFLOAD_DEVMAP_BIT, &adapter->open_device_map)) {
q1 = 0;
for_each_port(adapter, i) {
pi = adap2pinfo(adapter, i);
nqsets = pi->first_qset + pi->nqsets;
}
}
if (t.qset_idx >= nqsets)
return -EINVAL;
q = &adapter->params.sge.qset[q1 + t.qset_idx];
t.rspq_size = q->rspq_size;
t.txq_size[0] = q->txq_size[0];
t.txq_size[1] = q->txq_size[1];
t.txq_size[2] = q->txq_size[2];
t.fl_size[0] = q->fl_size;
t.fl_size[1] = q->jumbo_size;
t.polling = q->polling;
t.lro = !!(dev->features & NETIF_F_GRO);
t.intr_lat = q->coalesce_usecs;
t.cong_thres = q->cong_thres;
t.qnum = q1;
if (adapter->flags & USING_MSIX)
t.vector = adapter->msix_info[q1 + t.qset_idx + 1].vec;
else
t.vector = adapter->pdev->irq;
if (copy_to_user(useraddr, &t, sizeof(t)))
return -EFAULT;
break;
}
case CHELSIO_SET_QSET_NUM:{
struct ch_reg edata;
unsigned int i, first_qset = 0, other_qsets = 0;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (adapter->flags & FULL_INIT_DONE)
return -EBUSY;
if (copy_from_user(&edata, useraddr, sizeof(edata)))
return -EFAULT;
if (edata.val < 1 ||
(edata.val > 1 && !(adapter->flags & USING_MSIX)))
return -EINVAL;
for_each_port(adapter, i)
if (adapter->port[i] && adapter->port[i] != dev)
other_qsets += adap2pinfo(adapter, i)->nqsets;
if (edata.val + other_qsets > SGE_QSETS)
return -EINVAL;
pi->nqsets = edata.val;
for_each_port(adapter, i)
if (adapter->port[i]) {
pi = adap2pinfo(adapter, i);
pi->first_qset = first_qset;
first_qset += pi->nqsets;
}
break;
}
case CHELSIO_GET_QSET_NUM:{
struct ch_reg edata;
memset(&edata, 0, sizeof(struct ch_reg));
edata.cmd = CHELSIO_GET_QSET_NUM;
edata.val = pi->nqsets;
if (copy_to_user(useraddr, &edata, sizeof(edata)))
return -EFAULT;
break;
}
case CHELSIO_LOAD_FW:{
u8 *fw_data;
struct ch_mem_range t;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
if (copy_from_user(&t, useraddr, sizeof(t)))
return -EFAULT;
fw_data = memdup_user(useraddr + sizeof(t), t.len);
if (IS_ERR(fw_data))
return PTR_ERR(fw_data);
ret = t3_load_fw(adapter, fw_data, t.len);
kfree(fw_data);
if (ret)
return ret;
break;
}
case CHELSIO_SETMTUTAB:{
struct ch_mtus m;
int i;
if (!is_offload(adapter))
return -EOPNOTSUPP;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (offload_running(adapter))
return -EBUSY;
if (copy_from_user(&m, useraddr, sizeof(m)))
return -EFAULT;
if (m.nmtus != NMTUS)
return -EINVAL;
if (m.mtus[0] < 81)
return -EINVAL;
for (i = 1; i < NMTUS; ++i)
if (m.mtus[i] < m.mtus[i - 1])
return -EINVAL;
memcpy(adapter->params.mtus, m.mtus,
sizeof(adapter->params.mtus));
break;
}
case CHELSIO_GET_PM:{
struct tp_params *p = &adapter->params.tp;
struct ch_pm m = {.cmd = CHELSIO_GET_PM };
if (!is_offload(adapter))
return -EOPNOTSUPP;
m.tx_pg_sz = p->tx_pg_size;
m.tx_num_pg = p->tx_num_pgs;
m.rx_pg_sz = p->rx_pg_size;
m.rx_num_pg = p->rx_num_pgs;
m.pm_total = p->pmtx_size + p->chan_rx_size * p->nchan;
if (copy_to_user(useraddr, &m, sizeof(m)))
return -EFAULT;
break;
}
case CHELSIO_SET_PM:{
struct ch_pm m;
struct tp_params *p = &adapter->params.tp;
if (!is_offload(adapter))
return -EOPNOTSUPP;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (adapter->flags & FULL_INIT_DONE)
return -EBUSY;
if (copy_from_user(&m, useraddr, sizeof(m)))
return -EFAULT;
if (!is_power_of_2(m.rx_pg_sz) ||
!is_power_of_2(m.tx_pg_sz))
return -EINVAL;
if (!(m.rx_pg_sz & 0x14000))
return -EINVAL;
if (!(m.tx_pg_sz & 0x1554000))
return -EINVAL;
if (m.tx_num_pg == -1)
m.tx_num_pg = p->tx_num_pgs;
if (m.rx_num_pg == -1)
m.rx_num_pg = p->rx_num_pgs;
if (m.tx_num_pg % 24 || m.rx_num_pg % 24)
return -EINVAL;
if (m.rx_num_pg * m.rx_pg_sz > p->chan_rx_size ||
m.tx_num_pg * m.tx_pg_sz > p->chan_tx_size)
return -EINVAL;
p->rx_pg_size = m.rx_pg_sz;
p->tx_pg_size = m.tx_pg_sz;
p->rx_num_pgs = m.rx_num_pg;
p->tx_num_pgs = m.tx_num_pg;
break;
}
case CHELSIO_GET_MEM:{
struct ch_mem_range t;
struct mc7 *mem;
u64 buf[32];
if (!is_offload(adapter))
return -EOPNOTSUPP;
if (!(adapter->flags & FULL_INIT_DONE))
return -EIO;
if (copy_from_user(&t, useraddr, sizeof(t)))
return -EFAULT;
if ((t.addr & 7) || (t.len & 7))
return -EINVAL;
if (t.mem_id == MEM_CM)
mem = &adapter->cm;
else if (t.mem_id == MEM_PMRX)
mem = &adapter->pmrx;
else if (t.mem_id == MEM_PMTX)
mem = &adapter->pmtx;
else
return -EINVAL;
t.version = 3 | (adapter->params.rev << 10);
if (copy_to_user(useraddr, &t, sizeof(t)))
return -EFAULT;
useraddr += sizeof(t);
while (t.len) {
unsigned int chunk =
min_t(unsigned int, t.len, sizeof(buf));
ret =
t3_mc7_bd_read(mem, t.addr / 8, chunk / 8,
buf);
if (ret)
return ret;
if (copy_to_user(useraddr, buf, chunk))
return -EFAULT;
useraddr += chunk;
t.addr += chunk;
t.len -= chunk;
}
break;
}
case CHELSIO_SET_TRACE_FILTER:{
struct ch_trace t;
const struct trace_params *tp;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (!offload_running(adapter))
return -EAGAIN;
if (copy_from_user(&t, useraddr, sizeof(t)))
return -EFAULT;
tp = (const struct trace_params *)&t.sip;
if (t.config_tx)
t3_config_trace_filter(adapter, tp, 0,
t.invert_match,
t.trace_tx);
if (t.config_rx)
t3_config_trace_filter(adapter, tp, 1,
t.invert_match,
t.trace_rx);
break;
}
default:
return -EOPNOTSUPP;
}
return 0;
}
static int cxgb_ioctl(struct net_device *dev, struct ifreq *req, int cmd)
{
struct mii_ioctl_data *data = if_mii(req);
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
switch (cmd) {
case SIOCGMIIREG:
case SIOCSMIIREG:
if (is_10G(adapter) &&
!mdio_phy_id_is_c45(data->phy_id) &&
(data->phy_id & 0x1f00) &&
!(data->phy_id & 0xe0e0))
data->phy_id = mdio_phy_id_c45(data->phy_id >> 8,
data->phy_id & 0x1f);
case SIOCGMIIPHY:
return mdio_mii_ioctl(&pi->phy.mdio, data, cmd);
case SIOCCHIOCTL:
return cxgb_extension_ioctl(dev, req->ifr_data);
default:
return -EOPNOTSUPP;
}
}
static int cxgb_change_mtu(struct net_device *dev, int new_mtu)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
int ret;
if (new_mtu < 81)
return -EINVAL;
if ((ret = t3_mac_set_mtu(&pi->mac, new_mtu)))
return ret;
dev->mtu = new_mtu;
init_port_mtus(adapter);
if (adapter->params.rev == 0 && offload_running(adapter))
t3_load_mtus(adapter, adapter->params.mtus,
adapter->params.a_wnd, adapter->params.b_wnd,
adapter->port[0]->mtu);
return 0;
}
static int cxgb_set_mac_addr(struct net_device *dev, void *p)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
t3_mac_set_address(&pi->mac, LAN_MAC_IDX, dev->dev_addr);
if (offload_running(adapter))
write_smt_entry(adapter, pi->port_id);
return 0;
}
static netdev_features_t cxgb_fix_features(struct net_device *dev,
netdev_features_t features)
{
if (features & NETIF_F_HW_VLAN_CTAG_RX)
features |= NETIF_F_HW_VLAN_CTAG_TX;
else
features &= ~NETIF_F_HW_VLAN_CTAG_TX;
return features;
}
static int cxgb_set_features(struct net_device *dev, netdev_features_t features)
{
netdev_features_t changed = dev->features ^ features;
if (changed & NETIF_F_HW_VLAN_CTAG_RX)
cxgb_vlan_mode(dev, features);
return 0;
}
static void cxgb_netpoll(struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
int qidx;
for (qidx = pi->first_qset; qidx < pi->first_qset + pi->nqsets; qidx++) {
struct sge_qset *qs = &adapter->sge.qs[qidx];
void *source;
if (adapter->flags & USING_MSIX)
source = qs;
else
source = adapter;
t3_intr_handler(adapter, qs->rspq.polling) (0, source);
}
}
static void mac_stats_update(struct adapter *adapter)
{
int i;
for_each_port(adapter, i) {
struct net_device *dev = adapter->port[i];
struct port_info *p = netdev_priv(dev);
if (netif_running(dev)) {
spin_lock(&adapter->stats_lock);
t3_mac_update_stats(&p->mac);
spin_unlock(&adapter->stats_lock);
}
}
}
static void check_link_status(struct adapter *adapter)
{
int i;
for_each_port(adapter, i) {
struct net_device *dev = adapter->port[i];
struct port_info *p = netdev_priv(dev);
int link_fault;
spin_lock_irq(&adapter->work_lock);
link_fault = p->link_fault;
spin_unlock_irq(&adapter->work_lock);
if (link_fault) {
t3_link_fault(adapter, i);
continue;
}
if (!(p->phy.caps & SUPPORTED_IRQ) && netif_running(dev)) {
t3_xgm_intr_disable(adapter, i);
t3_read_reg(adapter, A_XGM_INT_STATUS + p->mac.offset);
t3_link_changed(adapter, i);
t3_xgm_intr_enable(adapter, i);
}
}
}
static void check_t3b2_mac(struct adapter *adapter)
{
int i;
if (!rtnl_trylock())
return;
for_each_port(adapter, i) {
struct net_device *dev = adapter->port[i];
struct port_info *p = netdev_priv(dev);
int status;
if (!netif_running(dev))
continue;
status = 0;
if (netif_running(dev) && netif_carrier_ok(dev))
status = t3b2_mac_watchdog_task(&p->mac);
if (status == 1)
p->mac.stats.num_toggled++;
else if (status == 2) {
struct cmac *mac = &p->mac;
t3_mac_set_mtu(mac, dev->mtu);
t3_mac_set_address(mac, LAN_MAC_IDX, dev->dev_addr);
cxgb_set_rxmode(dev);
t3_link_start(&p->phy, mac, &p->link_config);
t3_mac_enable(mac, MAC_DIRECTION_RX | MAC_DIRECTION_TX);
t3_port_intr_enable(adapter, p->port_id);
p->mac.stats.num_resets++;
}
}
rtnl_unlock();
}
static void t3_adap_check_task(struct work_struct *work)
{
struct adapter *adapter = container_of(work, struct adapter,
adap_check_task.work);
const struct adapter_params *p = &adapter->params;
int port;
unsigned int v, status, reset;
adapter->check_task_cnt++;
check_link_status(adapter);
if (!p->linkpoll_period ||
(adapter->check_task_cnt * p->linkpoll_period) / 10 >=
p->stats_update_period) {
mac_stats_update(adapter);
adapter->check_task_cnt = 0;
}
if (p->rev == T3_REV_B2)
check_t3b2_mac(adapter);
for_each_port(adapter, port) {
struct cmac *mac = &adap2pinfo(adapter, port)->mac;
u32 cause;
cause = t3_read_reg(adapter, A_XGM_INT_CAUSE + mac->offset);
reset = 0;
if (cause & F_RXFIFO_OVERFLOW) {
mac->stats.rx_fifo_ovfl++;
reset |= F_RXFIFO_OVERFLOW;
}
t3_write_reg(adapter, A_XGM_INT_CAUSE + mac->offset, reset);
}
status = t3_read_reg(adapter, A_SG_INT_CAUSE);
reset = 0;
if (status & F_FLEMPTY) {
struct sge_qset *qs = &adapter->sge.qs[0];
int i = 0;
reset |= F_FLEMPTY;
v = (t3_read_reg(adapter, A_SG_RSPQ_FL_STATUS) >> S_FL0EMPTY) &
0xffff;
while (v) {
qs->fl[i].empty += (v & 1);
if (i)
qs++;
i ^= 1;
v >>= 1;
}
}
t3_write_reg(adapter, A_SG_INT_CAUSE, reset);
spin_lock_irq(&adapter->work_lock);
if (adapter->open_device_map & PORT_MASK)
schedule_chk_task(adapter);
spin_unlock_irq(&adapter->work_lock);
}
static void db_full_task(struct work_struct *work)
{
struct adapter *adapter = container_of(work, struct adapter,
db_full_task);
cxgb3_event_notify(&adapter->tdev, OFFLOAD_DB_FULL, 0);
}
static void db_empty_task(struct work_struct *work)
{
struct adapter *adapter = container_of(work, struct adapter,
db_empty_task);
cxgb3_event_notify(&adapter->tdev, OFFLOAD_DB_EMPTY, 0);
}
static void db_drop_task(struct work_struct *work)
{
struct adapter *adapter = container_of(work, struct adapter,
db_drop_task);
unsigned long delay = 1000;
unsigned short r;
cxgb3_event_notify(&adapter->tdev, OFFLOAD_DB_DROP, 0);
get_random_bytes(&r, 2);
delay += r & 1023;
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(usecs_to_jiffies(delay));
ring_dbs(adapter);
}
static void ext_intr_task(struct work_struct *work)
{
struct adapter *adapter = container_of(work, struct adapter,
ext_intr_handler_task);
int i;
for_each_port(adapter, i) {
struct net_device *dev = adapter->port[i];
struct port_info *p = netdev_priv(dev);
t3_xgm_intr_disable(adapter, i);
t3_read_reg(adapter, A_XGM_INT_STATUS + p->mac.offset);
}
t3_phy_intr_handler(adapter);
for_each_port(adapter, i)
t3_xgm_intr_enable(adapter, i);
spin_lock_irq(&adapter->work_lock);
if (adapter->slow_intr_mask) {
adapter->slow_intr_mask |= F_T3DBG;
t3_write_reg(adapter, A_PL_INT_CAUSE0, F_T3DBG);
t3_write_reg(adapter, A_PL_INT_ENABLE0,
adapter->slow_intr_mask);
}
spin_unlock_irq(&adapter->work_lock);
}
void t3_os_ext_intr_handler(struct adapter *adapter)
{
spin_lock(&adapter->work_lock);
if (adapter->slow_intr_mask) {
adapter->slow_intr_mask &= ~F_T3DBG;
t3_write_reg(adapter, A_PL_INT_ENABLE0,
adapter->slow_intr_mask);
queue_work(cxgb3_wq, &adapter->ext_intr_handler_task);
}
spin_unlock(&adapter->work_lock);
}
void t3_os_link_fault_handler(struct adapter *adapter, int port_id)
{
struct net_device *netdev = adapter->port[port_id];
struct port_info *pi = netdev_priv(netdev);
spin_lock(&adapter->work_lock);
pi->link_fault = 1;
spin_unlock(&adapter->work_lock);
}
static int t3_adapter_error(struct adapter *adapter, int reset, int on_wq)
{
int i, ret = 0;
if (is_offload(adapter) &&
test_bit(OFFLOAD_DEVMAP_BIT, &adapter->open_device_map)) {
cxgb3_event_notify(&adapter->tdev, OFFLOAD_STATUS_DOWN, 0);
offload_close(&adapter->tdev);
}
for_each_port(adapter, i) {
struct net_device *netdev = adapter->port[i];
if (netif_running(netdev))
__cxgb_close(netdev, on_wq);
}
t3_stop_sge_timers(adapter);
adapter->flags &= ~FULL_INIT_DONE;
if (reset)
ret = t3_reset_adapter(adapter);
pci_disable_device(adapter->pdev);
return ret;
}
static int t3_reenable_adapter(struct adapter *adapter)
{
if (pci_enable_device(adapter->pdev)) {
dev_err(&adapter->pdev->dev,
"Cannot re-enable PCI device after reset.\n");
goto err;
}
pci_set_master(adapter->pdev);
pci_restore_state(adapter->pdev);
pci_save_state(adapter->pdev);
t3_free_sge_resources(adapter);
if (t3_replay_prep_adapter(adapter))
goto err;
return 0;
err:
return -1;
}
static void t3_resume_ports(struct adapter *adapter)
{
int i;
for_each_port(adapter, i) {
struct net_device *netdev = adapter->port[i];
if (netif_running(netdev)) {
if (cxgb_open(netdev)) {
dev_err(&adapter->pdev->dev,
"can't bring device back up"
" after reset\n");
continue;
}
}
}
if (is_offload(adapter) && !ofld_disable)
cxgb3_event_notify(&adapter->tdev, OFFLOAD_STATUS_UP, 0);
}
static void fatal_error_task(struct work_struct *work)
{
struct adapter *adapter = container_of(work, struct adapter,
fatal_error_handler_task);
int err = 0;
rtnl_lock();
err = t3_adapter_error(adapter, 1, 1);
if (!err)
err = t3_reenable_adapter(adapter);
if (!err)
t3_resume_ports(adapter);
CH_ALERT(adapter, "adapter reset %s\n", err ? "failed" : "succeeded");
rtnl_unlock();
}
void t3_fatal_err(struct adapter *adapter)
{
unsigned int fw_status[4];
if (adapter->flags & FULL_INIT_DONE) {
t3_sge_stop(adapter);
t3_write_reg(adapter, A_XGM_TX_CTRL, 0);
t3_write_reg(adapter, A_XGM_RX_CTRL, 0);
t3_write_reg(adapter, XGM_REG(A_XGM_TX_CTRL, 1), 0);
t3_write_reg(adapter, XGM_REG(A_XGM_RX_CTRL, 1), 0);
spin_lock(&adapter->work_lock);
t3_intr_disable(adapter);
queue_work(cxgb3_wq, &adapter->fatal_error_handler_task);
spin_unlock(&adapter->work_lock);
}
CH_ALERT(adapter, "encountered fatal error, operation suspended\n");
if (!t3_cim_ctl_blk_read(adapter, 0xa0, 4, fw_status))
CH_ALERT(adapter, "FW status: 0x%x, 0x%x, 0x%x, 0x%x\n",
fw_status[0], fw_status[1],
fw_status[2], fw_status[3]);
}
static pci_ers_result_t t3_io_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct adapter *adapter = pci_get_drvdata(pdev);
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
t3_adapter_error(adapter, 0, 0);
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t t3_io_slot_reset(struct pci_dev *pdev)
{
struct adapter *adapter = pci_get_drvdata(pdev);
if (!t3_reenable_adapter(adapter))
return PCI_ERS_RESULT_RECOVERED;
return PCI_ERS_RESULT_DISCONNECT;
}
static void t3_io_resume(struct pci_dev *pdev)
{
struct adapter *adapter = pci_get_drvdata(pdev);
CH_ALERT(adapter, "adapter recovering, PEX ERR 0x%x\n",
t3_read_reg(adapter, A_PCIE_PEX_ERR));
rtnl_lock();
t3_resume_ports(adapter);
rtnl_unlock();
}
static void set_nqsets(struct adapter *adap)
{
int i, j = 0;
int num_cpus = netif_get_num_default_rss_queues();
int hwports = adap->params.nports;
int nqsets = adap->msix_nvectors - 1;
if (adap->params.rev > 0 && adap->flags & USING_MSIX) {
if (hwports == 2 &&
(hwports * nqsets > SGE_QSETS ||
num_cpus >= nqsets / hwports))
nqsets /= hwports;
if (nqsets > num_cpus)
nqsets = num_cpus;
if (nqsets < 1 || hwports == 4)
nqsets = 1;
} else
nqsets = 1;
for_each_port(adap, i) {
struct port_info *pi = adap2pinfo(adap, i);
pi->first_qset = j;
pi->nqsets = nqsets;
j = pi->first_qset + nqsets;
dev_info(&adap->pdev->dev,
"Port %d using %d queue sets.\n", i, nqsets);
}
}
static int cxgb_enable_msix(struct adapter *adap)
{
struct msix_entry entries[SGE_QSETS + 1];
int vectors;
int i, err;
vectors = ARRAY_SIZE(entries);
for (i = 0; i < vectors; ++i)
entries[i].entry = i;
while ((err = pci_enable_msix(adap->pdev, entries, vectors)) > 0)
vectors = err;
if (err < 0)
pci_disable_msix(adap->pdev);
if (!err && vectors < (adap->params.nports + 1)) {
pci_disable_msix(adap->pdev);
err = -1;
}
if (!err) {
for (i = 0; i < vectors; ++i)
adap->msix_info[i].vec = entries[i].vector;
adap->msix_nvectors = vectors;
}
return err;
}
static void print_port_info(struct adapter *adap, const struct adapter_info *ai)
{
static const char *pci_variant[] = {
"PCI", "PCI-X", "PCI-X ECC", "PCI-X 266", "PCI Express"
};
int i;
char buf[80];
if (is_pcie(adap))
snprintf(buf, sizeof(buf), "%s x%d",
pci_variant[adap->params.pci.variant],
adap->params.pci.width);
else
snprintf(buf, sizeof(buf), "%s %dMHz/%d-bit",
pci_variant[adap->params.pci.variant],
adap->params.pci.speed, adap->params.pci.width);
for_each_port(adap, i) {
struct net_device *dev = adap->port[i];
const struct port_info *pi = netdev_priv(dev);
if (!test_bit(i, &adap->registered_device_map))
continue;
netdev_info(dev, "%s %s %sNIC (rev %d) %s%s\n",
ai->desc, pi->phy.desc,
is_offload(adap) ? "R" : "", adap->params.rev, buf,
(adap->flags & USING_MSIX) ? " MSI-X" :
(adap->flags & USING_MSI) ? " MSI" : "");
if (adap->name == dev->name && adap->params.vpd.mclk)
pr_info("%s: %uMB CM, %uMB PMTX, %uMB PMRX, S/N: %s\n",
adap->name, t3_mc7_size(&adap->cm) >> 20,
t3_mc7_size(&adap->pmtx) >> 20,
t3_mc7_size(&adap->pmrx) >> 20,
adap->params.vpd.sn);
}
}
static void cxgb3_init_iscsi_mac(struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
memcpy(pi->iscsic.mac_addr, dev->dev_addr, ETH_ALEN);
pi->iscsic.mac_addr[3] |= 0x80;
}
static int init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int i, err, pci_using_dac = 0;
resource_size_t mmio_start, mmio_len;
const struct adapter_info *ai;
struct adapter *adapter = NULL;
struct port_info *pi;
pr_info_once("%s - version %s\n", DRV_DESC, DRV_VERSION);
if (!cxgb3_wq) {
cxgb3_wq = create_singlethread_workqueue(DRV_NAME);
if (!cxgb3_wq) {
pr_err("cannot initialize work queue\n");
return -ENOMEM;
}
}
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "cannot enable PCI device\n");
goto out;
}
err = pci_request_regions(pdev, DRV_NAME);
if (err) {
dev_info(&pdev->dev, "cannot obtain PCI resources\n");
goto out_disable_device;
}
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
pci_using_dac = 1;
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (err) {
dev_err(&pdev->dev, "unable to obtain 64-bit DMA for "
"coherent allocations\n");
goto out_release_regions;
}
} else if ((err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) != 0) {
dev_err(&pdev->dev, "no usable DMA configuration\n");
goto out_release_regions;
}
pci_set_master(pdev);
pci_save_state(pdev);
mmio_start = pci_resource_start(pdev, 0);
mmio_len = pci_resource_len(pdev, 0);
ai = t3_get_adapter_info(ent->driver_data);
adapter = kzalloc(sizeof(*adapter), GFP_KERNEL);
if (!adapter) {
err = -ENOMEM;
goto out_release_regions;
}
adapter->nofail_skb =
alloc_skb(sizeof(struct cpl_set_tcb_field), GFP_KERNEL);
if (!adapter->nofail_skb) {
dev_err(&pdev->dev, "cannot allocate nofail buffer\n");
err = -ENOMEM;
goto out_free_adapter;
}
adapter->regs = ioremap_nocache(mmio_start, mmio_len);
if (!adapter->regs) {
dev_err(&pdev->dev, "cannot map device registers\n");
err = -ENOMEM;
goto out_free_adapter;
}
adapter->pdev = pdev;
adapter->name = pci_name(pdev);
adapter->msg_enable = dflt_msg_enable;
adapter->mmio_len = mmio_len;
mutex_init(&adapter->mdio_lock);
spin_lock_init(&adapter->work_lock);
spin_lock_init(&adapter->stats_lock);
INIT_LIST_HEAD(&adapter->adapter_list);
INIT_WORK(&adapter->ext_intr_handler_task, ext_intr_task);
INIT_WORK(&adapter->fatal_error_handler_task, fatal_error_task);
INIT_WORK(&adapter->db_full_task, db_full_task);
INIT_WORK(&adapter->db_empty_task, db_empty_task);
INIT_WORK(&adapter->db_drop_task, db_drop_task);
INIT_DELAYED_WORK(&adapter->adap_check_task, t3_adap_check_task);
for (i = 0; i < ai->nports0 + ai->nports1; ++i) {
struct net_device *netdev;
netdev = alloc_etherdev_mq(sizeof(struct port_info), SGE_QSETS);
if (!netdev) {
err = -ENOMEM;
goto out_free_dev;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
adapter->port[i] = netdev;
pi = netdev_priv(netdev);
pi->adapter = adapter;
pi->port_id = i;
netif_carrier_off(netdev);
netdev->irq = pdev->irq;
netdev->mem_start = mmio_start;
netdev->mem_end = mmio_start + mmio_len - 1;
netdev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM |
NETIF_F_TSO | NETIF_F_RXCSUM | NETIF_F_HW_VLAN_CTAG_RX;
netdev->features |= netdev->hw_features |
NETIF_F_HW_VLAN_CTAG_TX;
netdev->vlan_features |= netdev->features & VLAN_FEAT;
if (pci_using_dac)
netdev->features |= NETIF_F_HIGHDMA;
netdev->netdev_ops = &cxgb_netdev_ops;
SET_ETHTOOL_OPS(netdev, &cxgb_ethtool_ops);
}
pci_set_drvdata(pdev, adapter);
if (t3_prep_adapter(adapter, ai, 1) < 0) {
err = -ENODEV;
goto out_free_dev;
}
for_each_port(adapter, i) {
err = register_netdev(adapter->port[i]);
if (err)
dev_warn(&pdev->dev,
"cannot register net device %s, skipping\n",
adapter->port[i]->name);
else {
if (!adapter->registered_device_map)
adapter->name = adapter->port[i]->name;
__set_bit(i, &adapter->registered_device_map);
}
}
if (!adapter->registered_device_map) {
dev_err(&pdev->dev, "could not register any net devices\n");
goto out_free_dev;
}
for_each_port(adapter, i)
cxgb3_init_iscsi_mac(adapter->port[i]);
t3_led_ready(adapter);
if (is_offload(adapter)) {
__set_bit(OFFLOAD_DEVMAP_BIT, &adapter->registered_device_map);
cxgb3_adapter_ofld(adapter);
}
if (msi > 1 && cxgb_enable_msix(adapter) == 0)
adapter->flags |= USING_MSIX;
else if (msi > 0 && pci_enable_msi(pdev) == 0)
adapter->flags |= USING_MSI;
set_nqsets(adapter);
err = sysfs_create_group(&adapter->port[0]->dev.kobj,
&cxgb3_attr_group);
print_port_info(adapter, ai);
return 0;
out_free_dev:
iounmap(adapter->regs);
for (i = ai->nports0 + ai->nports1 - 1; i >= 0; --i)
if (adapter->port[i])
free_netdev(adapter->port[i]);
out_free_adapter:
kfree(adapter);
out_release_regions:
pci_release_regions(pdev);
out_disable_device:
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
out:
return err;
}
static void remove_one(struct pci_dev *pdev)
{
struct adapter *adapter = pci_get_drvdata(pdev);
if (adapter) {
int i;
t3_sge_stop(adapter);
sysfs_remove_group(&adapter->port[0]->dev.kobj,
&cxgb3_attr_group);
if (is_offload(adapter)) {
cxgb3_adapter_unofld(adapter);
if (test_bit(OFFLOAD_DEVMAP_BIT,
&adapter->open_device_map))
offload_close(&adapter->tdev);
}
for_each_port(adapter, i)
if (test_bit(i, &adapter->registered_device_map))
unregister_netdev(adapter->port[i]);
t3_stop_sge_timers(adapter);
t3_free_sge_resources(adapter);
cxgb_disable_msi(adapter);
for_each_port(adapter, i)
if (adapter->port[i])
free_netdev(adapter->port[i]);
iounmap(adapter->regs);
if (adapter->nofail_skb)
kfree_skb(adapter->nofail_skb);
kfree(adapter);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
}
static int __init cxgb3_init_module(void)
{
int ret;
cxgb3_offload_init();
ret = pci_register_driver(&driver);
return ret;
}
static void __exit cxgb3_cleanup_module(void)
{
pci_unregister_driver(&driver);
if (cxgb3_wq)
destroy_workqueue(cxgb3_wq);
}
