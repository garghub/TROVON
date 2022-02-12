void ravb_modify(struct net_device *ndev, enum ravb_reg reg, u32 clear,
u32 set)
{
ravb_write(ndev, (ravb_read(ndev, reg) & ~clear) | set, reg);
}
int ravb_wait(struct net_device *ndev, enum ravb_reg reg, u32 mask, u32 value)
{
int i;
for (i = 0; i < 10000; i++) {
if ((ravb_read(ndev, reg) & mask) == value)
return 0;
udelay(10);
}
return -ETIMEDOUT;
}
static int ravb_config(struct net_device *ndev)
{
int error;
ravb_modify(ndev, CCC, CCC_OPC, CCC_OPC_CONFIG);
error = ravb_wait(ndev, CSR, CSR_OPS, CSR_OPS_CONFIG);
if (error)
netdev_err(ndev, "failed to switch device to config mode\n");
return error;
}
static void ravb_set_duplex(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
ravb_modify(ndev, ECMR, ECMR_DM, priv->duplex ? ECMR_DM : 0);
}
static void ravb_set_rate(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
switch (priv->speed) {
case 100:
ravb_write(ndev, GECMR_SPEED_100, GECMR);
break;
case 1000:
ravb_write(ndev, GECMR_SPEED_1000, GECMR);
break;
}
}
static void ravb_set_buffer_align(struct sk_buff *skb)
{
u32 reserve = (unsigned long)skb->data & (RAVB_ALIGN - 1);
if (reserve)
skb_reserve(skb, RAVB_ALIGN - reserve);
}
static void ravb_read_mac_address(struct net_device *ndev, const u8 *mac)
{
if (mac) {
ether_addr_copy(ndev->dev_addr, mac);
} else {
u32 mahr = ravb_read(ndev, MAHR);
u32 malr = ravb_read(ndev, MALR);
ndev->dev_addr[0] = (mahr >> 24) & 0xFF;
ndev->dev_addr[1] = (mahr >> 16) & 0xFF;
ndev->dev_addr[2] = (mahr >> 8) & 0xFF;
ndev->dev_addr[3] = (mahr >> 0) & 0xFF;
ndev->dev_addr[4] = (malr >> 8) & 0xFF;
ndev->dev_addr[5] = (malr >> 0) & 0xFF;
}
}
static void ravb_mdio_ctrl(struct mdiobb_ctrl *ctrl, u32 mask, int set)
{
struct ravb_private *priv = container_of(ctrl, struct ravb_private,
mdiobb);
ravb_modify(priv->ndev, PIR, mask, set ? mask : 0);
}
static void ravb_set_mdc(struct mdiobb_ctrl *ctrl, int level)
{
ravb_mdio_ctrl(ctrl, PIR_MDC, level);
}
static void ravb_set_mdio_dir(struct mdiobb_ctrl *ctrl, int output)
{
ravb_mdio_ctrl(ctrl, PIR_MMD, output);
}
static void ravb_set_mdio_data(struct mdiobb_ctrl *ctrl, int value)
{
ravb_mdio_ctrl(ctrl, PIR_MDO, value);
}
static int ravb_get_mdio_data(struct mdiobb_ctrl *ctrl)
{
struct ravb_private *priv = container_of(ctrl, struct ravb_private,
mdiobb);
return (ravb_read(priv->ndev, PIR) & PIR_MDI) != 0;
}
static void ravb_ring_free(struct net_device *ndev, int q)
{
struct ravb_private *priv = netdev_priv(ndev);
int ring_size;
int i;
if (priv->rx_skb[q]) {
for (i = 0; i < priv->num_rx_ring[q]; i++)
dev_kfree_skb(priv->rx_skb[q][i]);
}
kfree(priv->rx_skb[q]);
priv->rx_skb[q] = NULL;
if (priv->tx_skb[q]) {
for (i = 0; i < priv->num_tx_ring[q]; i++)
dev_kfree_skb(priv->tx_skb[q][i]);
}
kfree(priv->tx_skb[q]);
priv->tx_skb[q] = NULL;
kfree(priv->tx_align[q]);
priv->tx_align[q] = NULL;
if (priv->rx_ring[q]) {
ring_size = sizeof(struct ravb_ex_rx_desc) *
(priv->num_rx_ring[q] + 1);
dma_free_coherent(ndev->dev.parent, ring_size, priv->rx_ring[q],
priv->rx_desc_dma[q]);
priv->rx_ring[q] = NULL;
}
if (priv->tx_ring[q]) {
ring_size = sizeof(struct ravb_tx_desc) *
(priv->num_tx_ring[q] * NUM_TX_DESC + 1);
dma_free_coherent(ndev->dev.parent, ring_size, priv->tx_ring[q],
priv->tx_desc_dma[q]);
priv->tx_ring[q] = NULL;
}
}
static void ravb_ring_format(struct net_device *ndev, int q)
{
struct ravb_private *priv = netdev_priv(ndev);
struct ravb_ex_rx_desc *rx_desc;
struct ravb_tx_desc *tx_desc;
struct ravb_desc *desc;
int rx_ring_size = sizeof(*rx_desc) * priv->num_rx_ring[q];
int tx_ring_size = sizeof(*tx_desc) * priv->num_tx_ring[q] *
NUM_TX_DESC;
dma_addr_t dma_addr;
int i;
priv->cur_rx[q] = 0;
priv->cur_tx[q] = 0;
priv->dirty_rx[q] = 0;
priv->dirty_tx[q] = 0;
memset(priv->rx_ring[q], 0, rx_ring_size);
for (i = 0; i < priv->num_rx_ring[q]; i++) {
rx_desc = &priv->rx_ring[q][i];
rx_desc->ds_cc = cpu_to_le16(PKT_BUF_SZ);
dma_addr = dma_map_single(ndev->dev.parent, priv->rx_skb[q][i]->data,
PKT_BUF_SZ,
DMA_FROM_DEVICE);
if (dma_mapping_error(ndev->dev.parent, dma_addr))
rx_desc->ds_cc = cpu_to_le16(0);
rx_desc->dptr = cpu_to_le32(dma_addr);
rx_desc->die_dt = DT_FEMPTY;
}
rx_desc = &priv->rx_ring[q][i];
rx_desc->dptr = cpu_to_le32((u32)priv->rx_desc_dma[q]);
rx_desc->die_dt = DT_LINKFIX;
memset(priv->tx_ring[q], 0, tx_ring_size);
for (i = 0, tx_desc = priv->tx_ring[q]; i < priv->num_tx_ring[q];
i++, tx_desc++) {
tx_desc->die_dt = DT_EEMPTY;
tx_desc++;
tx_desc->die_dt = DT_EEMPTY;
}
tx_desc->dptr = cpu_to_le32((u32)priv->tx_desc_dma[q]);
tx_desc->die_dt = DT_LINKFIX;
desc = &priv->desc_bat[RX_QUEUE_OFFSET + q];
desc->die_dt = DT_LINKFIX;
desc->dptr = cpu_to_le32((u32)priv->rx_desc_dma[q]);
desc = &priv->desc_bat[q];
desc->die_dt = DT_LINKFIX;
desc->dptr = cpu_to_le32((u32)priv->tx_desc_dma[q]);
}
static int ravb_ring_init(struct net_device *ndev, int q)
{
struct ravb_private *priv = netdev_priv(ndev);
struct sk_buff *skb;
int ring_size;
int i;
priv->rx_skb[q] = kcalloc(priv->num_rx_ring[q],
sizeof(*priv->rx_skb[q]), GFP_KERNEL);
priv->tx_skb[q] = kcalloc(priv->num_tx_ring[q],
sizeof(*priv->tx_skb[q]), GFP_KERNEL);
if (!priv->rx_skb[q] || !priv->tx_skb[q])
goto error;
for (i = 0; i < priv->num_rx_ring[q]; i++) {
skb = netdev_alloc_skb(ndev, PKT_BUF_SZ + RAVB_ALIGN - 1);
if (!skb)
goto error;
ravb_set_buffer_align(skb);
priv->rx_skb[q][i] = skb;
}
priv->tx_align[q] = kmalloc(DPTR_ALIGN * priv->num_tx_ring[q] +
DPTR_ALIGN - 1, GFP_KERNEL);
if (!priv->tx_align[q])
goto error;
ring_size = sizeof(struct ravb_ex_rx_desc) * (priv->num_rx_ring[q] + 1);
priv->rx_ring[q] = dma_alloc_coherent(ndev->dev.parent, ring_size,
&priv->rx_desc_dma[q],
GFP_KERNEL);
if (!priv->rx_ring[q])
goto error;
priv->dirty_rx[q] = 0;
ring_size = sizeof(struct ravb_tx_desc) *
(priv->num_tx_ring[q] * NUM_TX_DESC + 1);
priv->tx_ring[q] = dma_alloc_coherent(ndev->dev.parent, ring_size,
&priv->tx_desc_dma[q],
GFP_KERNEL);
if (!priv->tx_ring[q])
goto error;
return 0;
error:
ravb_ring_free(ndev, q);
return -ENOMEM;
}
static void ravb_emac_init(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
ravb_write(ndev, ndev->mtu + ETH_HLEN + VLAN_HLEN + ETH_FCS_LEN, RFLR);
ravb_write(ndev, ECMR_ZPF | (priv->duplex ? ECMR_DM : 0) |
ECMR_TE | ECMR_RE, ECMR);
ravb_set_rate(ndev);
ravb_write(ndev,
(ndev->dev_addr[0] << 24) | (ndev->dev_addr[1] << 16) |
(ndev->dev_addr[2] << 8) | (ndev->dev_addr[3]), MAHR);
ravb_write(ndev,
(ndev->dev_addr[4] << 8) | (ndev->dev_addr[5]), MALR);
ravb_write(ndev, ECSR_ICD | ECSR_MPD, ECSR);
ravb_write(ndev, ECSIPR_ICDIP | ECSIPR_MPDIP | ECSIPR_LCHNGIP, ECSIPR);
}
static int ravb_dmac_init(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
int error;
error = ravb_config(ndev);
if (error)
return error;
error = ravb_ring_init(ndev, RAVB_BE);
if (error)
return error;
error = ravb_ring_init(ndev, RAVB_NC);
if (error) {
ravb_ring_free(ndev, RAVB_BE);
return error;
}
ravb_ring_format(ndev, RAVB_BE);
ravb_ring_format(ndev, RAVB_NC);
#if defined(__LITTLE_ENDIAN)
ravb_modify(ndev, CCC, CCC_BOC, 0);
#else
ravb_modify(ndev, CCC, CCC_BOC, CCC_BOC);
#endif
ravb_write(ndev,
RCR_EFFS | RCR_ENCF | RCR_ETS0 | RCR_ESF | 0x18000000, RCR);
ravb_write(ndev, TGC_TQP_AVBMODE1 | 0x00222200, TGC);
ravb_write(ndev, TCCR_TFEN, TCCR);
if (priv->chip_id == RCAR_GEN3) {
ravb_write(ndev, 0, DIL);
ravb_write(ndev, CIE_CRIE | CIE_CTIE | CIE_CL0M, CIE);
}
ravb_write(ndev, RIC0_FRE0 | RIC0_FRE1, RIC0);
ravb_write(ndev, 0, RIC1);
ravb_write(ndev, RIC2_QFE0 | RIC2_QFE1 | RIC2_RFFE, RIC2);
ravb_write(ndev, TIC_FTE0 | TIC_FTE1 | TIC_TFUE, TIC);
ravb_modify(ndev, CCC, CCC_OPC, CCC_OPC_OPERATION);
return 0;
}
static int ravb_tx_free(struct net_device *ndev, int q)
{
struct ravb_private *priv = netdev_priv(ndev);
struct net_device_stats *stats = &priv->stats[q];
struct ravb_tx_desc *desc;
int free_num = 0;
int entry;
u32 size;
for (; priv->cur_tx[q] - priv->dirty_tx[q] > 0; priv->dirty_tx[q]++) {
entry = priv->dirty_tx[q] % (priv->num_tx_ring[q] *
NUM_TX_DESC);
desc = &priv->tx_ring[q][entry];
if (desc->die_dt != DT_FEMPTY)
break;
dma_rmb();
size = le16_to_cpu(desc->ds_tagl) & TX_DS;
if (priv->tx_skb[q][entry / NUM_TX_DESC]) {
dma_unmap_single(ndev->dev.parent, le32_to_cpu(desc->dptr),
size, DMA_TO_DEVICE);
if (entry % NUM_TX_DESC == NUM_TX_DESC - 1) {
entry /= NUM_TX_DESC;
dev_kfree_skb_any(priv->tx_skb[q][entry]);
priv->tx_skb[q][entry] = NULL;
stats->tx_packets++;
}
free_num++;
}
stats->tx_bytes += size;
desc->die_dt = DT_EEMPTY;
}
return free_num;
}
static void ravb_get_tx_tstamp(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
struct ravb_tstamp_skb *ts_skb, *ts_skb2;
struct skb_shared_hwtstamps shhwtstamps;
struct sk_buff *skb;
struct timespec64 ts;
u16 tag, tfa_tag;
int count;
u32 tfa2;
count = (ravb_read(ndev, TSR) & TSR_TFFL) >> 8;
while (count--) {
tfa2 = ravb_read(ndev, TFA2);
tfa_tag = (tfa2 & TFA2_TST) >> 16;
ts.tv_nsec = (u64)ravb_read(ndev, TFA0);
ts.tv_sec = ((u64)(tfa2 & TFA2_TSV) << 32) |
ravb_read(ndev, TFA1);
memset(&shhwtstamps, 0, sizeof(shhwtstamps));
shhwtstamps.hwtstamp = timespec64_to_ktime(ts);
list_for_each_entry_safe(ts_skb, ts_skb2, &priv->ts_skb_list,
list) {
skb = ts_skb->skb;
tag = ts_skb->tag;
list_del(&ts_skb->list);
kfree(ts_skb);
if (tag == tfa_tag) {
skb_tstamp_tx(skb, &shhwtstamps);
break;
}
}
ravb_modify(ndev, TCCR, TCCR_TFR, TCCR_TFR);
}
}
static bool ravb_rx(struct net_device *ndev, int *quota, int q)
{
struct ravb_private *priv = netdev_priv(ndev);
int entry = priv->cur_rx[q] % priv->num_rx_ring[q];
int boguscnt = (priv->dirty_rx[q] + priv->num_rx_ring[q]) -
priv->cur_rx[q];
struct net_device_stats *stats = &priv->stats[q];
struct ravb_ex_rx_desc *desc;
struct sk_buff *skb;
dma_addr_t dma_addr;
struct timespec64 ts;
u8 desc_status;
u16 pkt_len;
int limit;
boguscnt = min(boguscnt, *quota);
limit = boguscnt;
desc = &priv->rx_ring[q][entry];
while (desc->die_dt != DT_FEMPTY) {
dma_rmb();
desc_status = desc->msc;
pkt_len = le16_to_cpu(desc->ds_cc) & RX_DS;
if (--boguscnt < 0)
break;
if (!pkt_len)
continue;
if (desc_status & MSC_MC)
stats->multicast++;
if (desc_status & (MSC_CRC | MSC_RFE | MSC_RTSF | MSC_RTLF |
MSC_CEEF)) {
stats->rx_errors++;
if (desc_status & MSC_CRC)
stats->rx_crc_errors++;
if (desc_status & MSC_RFE)
stats->rx_frame_errors++;
if (desc_status & (MSC_RTLF | MSC_RTSF))
stats->rx_length_errors++;
if (desc_status & MSC_CEEF)
stats->rx_missed_errors++;
} else {
u32 get_ts = priv->tstamp_rx_ctrl & RAVB_RXTSTAMP_TYPE;
skb = priv->rx_skb[q][entry];
priv->rx_skb[q][entry] = NULL;
dma_unmap_single(ndev->dev.parent, le32_to_cpu(desc->dptr),
PKT_BUF_SZ,
DMA_FROM_DEVICE);
get_ts &= (q == RAVB_NC) ?
RAVB_RXTSTAMP_TYPE_V2_L2_EVENT :
~RAVB_RXTSTAMP_TYPE_V2_L2_EVENT;
if (get_ts) {
struct skb_shared_hwtstamps *shhwtstamps;
shhwtstamps = skb_hwtstamps(skb);
memset(shhwtstamps, 0, sizeof(*shhwtstamps));
ts.tv_sec = ((u64) le16_to_cpu(desc->ts_sh) <<
32) | le32_to_cpu(desc->ts_sl);
ts.tv_nsec = le32_to_cpu(desc->ts_n);
shhwtstamps->hwtstamp = timespec64_to_ktime(ts);
}
skb_put(skb, pkt_len);
skb->protocol = eth_type_trans(skb, ndev);
napi_gro_receive(&priv->napi[q], skb);
stats->rx_packets++;
stats->rx_bytes += pkt_len;
}
entry = (++priv->cur_rx[q]) % priv->num_rx_ring[q];
desc = &priv->rx_ring[q][entry];
}
for (; priv->cur_rx[q] - priv->dirty_rx[q] > 0; priv->dirty_rx[q]++) {
entry = priv->dirty_rx[q] % priv->num_rx_ring[q];
desc = &priv->rx_ring[q][entry];
desc->ds_cc = cpu_to_le16(PKT_BUF_SZ);
if (!priv->rx_skb[q][entry]) {
skb = netdev_alloc_skb(ndev,
PKT_BUF_SZ + RAVB_ALIGN - 1);
if (!skb)
break;
ravb_set_buffer_align(skb);
dma_addr = dma_map_single(ndev->dev.parent, skb->data,
le16_to_cpu(desc->ds_cc),
DMA_FROM_DEVICE);
skb_checksum_none_assert(skb);
if (dma_mapping_error(ndev->dev.parent, dma_addr))
desc->ds_cc = cpu_to_le16(0);
desc->dptr = cpu_to_le32(dma_addr);
priv->rx_skb[q][entry] = skb;
}
dma_wmb();
desc->die_dt = DT_FEMPTY;
}
*quota -= limit - (++boguscnt);
return boguscnt <= 0;
}
static void ravb_rcv_snd_disable(struct net_device *ndev)
{
ravb_modify(ndev, ECMR, ECMR_RE | ECMR_TE, 0);
}
static void ravb_rcv_snd_enable(struct net_device *ndev)
{
ravb_modify(ndev, ECMR, ECMR_RE | ECMR_TE, ECMR_RE | ECMR_TE);
}
static int ravb_stop_dma(struct net_device *ndev)
{
int error;
error = ravb_wait(ndev, TCCR,
TCCR_TSRQ0 | TCCR_TSRQ1 | TCCR_TSRQ2 | TCCR_TSRQ3, 0);
if (error)
return error;
error = ravb_wait(ndev, CSR, CSR_TPO0 | CSR_TPO1 | CSR_TPO2 | CSR_TPO3,
0);
if (error)
return error;
ravb_rcv_snd_disable(ndev);
error = ravb_wait(ndev, CSR, CSR_RPO, 0);
if (error)
return error;
return ravb_config(ndev);
}
static void ravb_emac_interrupt_unlocked(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
u32 ecsr, psr;
ecsr = ravb_read(ndev, ECSR);
ravb_write(ndev, ecsr, ECSR);
if (ecsr & ECSR_ICD)
ndev->stats.tx_carrier_errors++;
if (ecsr & ECSR_LCHNG) {
if (priv->no_avb_link)
return;
psr = ravb_read(ndev, PSR);
if (priv->avb_link_active_low)
psr ^= PSR_LMON;
if (!(psr & PSR_LMON)) {
ravb_rcv_snd_disable(ndev);
} else {
ravb_rcv_snd_enable(ndev);
}
}
}
static irqreturn_t ravb_emac_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = dev_id;
struct ravb_private *priv = netdev_priv(ndev);
spin_lock(&priv->lock);
ravb_emac_interrupt_unlocked(ndev);
mmiowb();
spin_unlock(&priv->lock);
return IRQ_HANDLED;
}
static void ravb_error_interrupt(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
u32 eis, ris2;
eis = ravb_read(ndev, EIS);
ravb_write(ndev, ~EIS_QFS, EIS);
if (eis & EIS_QFS) {
ris2 = ravb_read(ndev, RIS2);
ravb_write(ndev, ~(RIS2_QFF0 | RIS2_RFFF), RIS2);
if (ris2 & RIS2_QFF0)
priv->stats[RAVB_BE].rx_over_errors++;
if (ris2 & RIS2_QFF1)
priv->stats[RAVB_NC].rx_over_errors++;
if (ris2 & RIS2_RFFF)
priv->rx_fifo_errors++;
}
}
static bool ravb_queue_interrupt(struct net_device *ndev, int q)
{
struct ravb_private *priv = netdev_priv(ndev);
u32 ris0 = ravb_read(ndev, RIS0);
u32 ric0 = ravb_read(ndev, RIC0);
u32 tis = ravb_read(ndev, TIS);
u32 tic = ravb_read(ndev, TIC);
if (((ris0 & ric0) & BIT(q)) || ((tis & tic) & BIT(q))) {
if (napi_schedule_prep(&priv->napi[q])) {
if (priv->chip_id == RCAR_GEN2) {
ravb_write(ndev, ric0 & ~BIT(q), RIC0);
ravb_write(ndev, tic & ~BIT(q), TIC);
} else {
ravb_write(ndev, BIT(q), RID0);
ravb_write(ndev, BIT(q), TID);
}
__napi_schedule(&priv->napi[q]);
} else {
netdev_warn(ndev,
"ignoring interrupt, rx status 0x%08x, rx mask 0x%08x,\n",
ris0, ric0);
netdev_warn(ndev,
" tx status 0x%08x, tx mask 0x%08x.\n",
tis, tic);
}
return true;
}
return false;
}
static bool ravb_timestamp_interrupt(struct net_device *ndev)
{
u32 tis = ravb_read(ndev, TIS);
if (tis & TIS_TFUF) {
ravb_write(ndev, ~TIS_TFUF, TIS);
ravb_get_tx_tstamp(ndev);
return true;
}
return false;
}
static irqreturn_t ravb_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = dev_id;
struct ravb_private *priv = netdev_priv(ndev);
irqreturn_t result = IRQ_NONE;
u32 iss;
spin_lock(&priv->lock);
iss = ravb_read(ndev, ISS);
if (iss & (ISS_FRS | ISS_FTS | ISS_TFUS)) {
int q;
if (ravb_timestamp_interrupt(ndev))
result = IRQ_HANDLED;
for (q = RAVB_NC; q >= RAVB_BE; q--) {
if (ravb_queue_interrupt(ndev, q))
result = IRQ_HANDLED;
}
}
if (iss & ISS_MS) {
ravb_emac_interrupt_unlocked(ndev);
result = IRQ_HANDLED;
}
if (iss & ISS_ES) {
ravb_error_interrupt(ndev);
result = IRQ_HANDLED;
}
if (iss & ISS_CGIS) {
ravb_ptp_interrupt(ndev);
result = IRQ_HANDLED;
}
mmiowb();
spin_unlock(&priv->lock);
return result;
}
static irqreturn_t ravb_multi_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = dev_id;
struct ravb_private *priv = netdev_priv(ndev);
irqreturn_t result = IRQ_NONE;
u32 iss;
spin_lock(&priv->lock);
iss = ravb_read(ndev, ISS);
if ((iss & ISS_TFUS) && ravb_timestamp_interrupt(ndev))
result = IRQ_HANDLED;
if (iss & ISS_ES) {
ravb_error_interrupt(ndev);
result = IRQ_HANDLED;
}
if (iss & ISS_CGIS) {
ravb_ptp_interrupt(ndev);
result = IRQ_HANDLED;
}
mmiowb();
spin_unlock(&priv->lock);
return result;
}
static irqreturn_t ravb_dma_interrupt(int irq, void *dev_id, int q)
{
struct net_device *ndev = dev_id;
struct ravb_private *priv = netdev_priv(ndev);
irqreturn_t result = IRQ_NONE;
spin_lock(&priv->lock);
if (ravb_queue_interrupt(ndev, q))
result = IRQ_HANDLED;
mmiowb();
spin_unlock(&priv->lock);
return result;
}
static irqreturn_t ravb_be_interrupt(int irq, void *dev_id)
{
return ravb_dma_interrupt(irq, dev_id, RAVB_BE);
}
static irqreturn_t ravb_nc_interrupt(int irq, void *dev_id)
{
return ravb_dma_interrupt(irq, dev_id, RAVB_NC);
}
static int ravb_poll(struct napi_struct *napi, int budget)
{
struct net_device *ndev = napi->dev;
struct ravb_private *priv = netdev_priv(ndev);
unsigned long flags;
int q = napi - priv->napi;
int mask = BIT(q);
int quota = budget;
u32 ris0, tis;
for (;;) {
tis = ravb_read(ndev, TIS);
ris0 = ravb_read(ndev, RIS0);
if (!((ris0 & mask) || (tis & mask)))
break;
if (ris0 & mask) {
ravb_write(ndev, ~mask, RIS0);
if (ravb_rx(ndev, &quota, q))
goto out;
}
if (tis & mask) {
spin_lock_irqsave(&priv->lock, flags);
ravb_write(ndev, ~mask, TIS);
ravb_tx_free(ndev, q);
netif_wake_subqueue(ndev, q);
mmiowb();
spin_unlock_irqrestore(&priv->lock, flags);
}
}
napi_complete(napi);
spin_lock_irqsave(&priv->lock, flags);
if (priv->chip_id == RCAR_GEN2) {
ravb_modify(ndev, RIC0, mask, mask);
ravb_modify(ndev, TIC, mask, mask);
} else {
ravb_write(ndev, mask, RIE0);
ravb_write(ndev, mask, TIE);
}
mmiowb();
spin_unlock_irqrestore(&priv->lock, flags);
priv->rx_over_errors = priv->stats[RAVB_BE].rx_over_errors;
priv->rx_over_errors += priv->stats[RAVB_NC].rx_over_errors;
if (priv->rx_over_errors != ndev->stats.rx_over_errors) {
ndev->stats.rx_over_errors = priv->rx_over_errors;
netif_err(priv, rx_err, ndev, "Receive Descriptor Empty\n");
}
if (priv->rx_fifo_errors != ndev->stats.rx_fifo_errors) {
ndev->stats.rx_fifo_errors = priv->rx_fifo_errors;
netif_err(priv, rx_err, ndev, "Receive FIFO Overflow\n");
}
out:
return budget - quota;
}
static void ravb_adjust_link(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
struct phy_device *phydev = ndev->phydev;
bool new_state = false;
if (phydev->link) {
if (phydev->duplex != priv->duplex) {
new_state = true;
priv->duplex = phydev->duplex;
ravb_set_duplex(ndev);
}
if (phydev->speed != priv->speed) {
new_state = true;
priv->speed = phydev->speed;
ravb_set_rate(ndev);
}
if (!priv->link) {
ravb_modify(ndev, ECMR, ECMR_TXF, 0);
new_state = true;
priv->link = phydev->link;
if (priv->no_avb_link)
ravb_rcv_snd_enable(ndev);
}
} else if (priv->link) {
new_state = true;
priv->link = 0;
priv->speed = 0;
priv->duplex = -1;
if (priv->no_avb_link)
ravb_rcv_snd_disable(ndev);
}
if (new_state && netif_msg_link(priv))
phy_print_status(phydev);
}
static int ravb_phy_init(struct net_device *ndev)
{
struct device_node *np = ndev->dev.parent->of_node;
struct ravb_private *priv = netdev_priv(ndev);
struct phy_device *phydev;
struct device_node *pn;
int err;
priv->link = 0;
priv->speed = 0;
priv->duplex = -1;
pn = of_parse_phandle(np, "phy-handle", 0);
if (!pn) {
if (of_phy_is_fixed_link(np)) {
err = of_phy_register_fixed_link(np);
if (err)
return err;
}
pn = of_node_get(np);
}
phydev = of_phy_connect(ndev, pn, ravb_adjust_link, 0,
priv->phy_interface);
of_node_put(pn);
if (!phydev) {
netdev_err(ndev, "failed to connect PHY\n");
err = -ENOENT;
goto err_deregister_fixed_link;
}
if (priv->chip_id == RCAR_GEN3) {
err = phy_set_max_speed(phydev, SPEED_100);
if (err) {
netdev_err(ndev, "failed to limit PHY to 100Mbit/s\n");
goto err_phy_disconnect;
}
netdev_info(ndev, "limited PHY to 100Mbit/s\n");
}
phydev->supported &= ~PHY_10BT_FEATURES;
phy_attached_info(phydev);
return 0;
err_phy_disconnect:
phy_disconnect(phydev);
err_deregister_fixed_link:
if (of_phy_is_fixed_link(np))
of_phy_deregister_fixed_link(np);
return err;
}
static int ravb_phy_start(struct net_device *ndev)
{
int error;
error = ravb_phy_init(ndev);
if (error)
return error;
phy_start(ndev->phydev);
return 0;
}
static int ravb_get_link_ksettings(struct net_device *ndev,
struct ethtool_link_ksettings *cmd)
{
struct ravb_private *priv = netdev_priv(ndev);
int error = -ENODEV;
unsigned long flags;
if (ndev->phydev) {
spin_lock_irqsave(&priv->lock, flags);
error = phy_ethtool_ksettings_get(ndev->phydev, cmd);
spin_unlock_irqrestore(&priv->lock, flags);
}
return error;
}
static int ravb_set_link_ksettings(struct net_device *ndev,
const struct ethtool_link_ksettings *cmd)
{
struct ravb_private *priv = netdev_priv(ndev);
unsigned long flags;
int error;
if (!ndev->phydev)
return -ENODEV;
spin_lock_irqsave(&priv->lock, flags);
ravb_rcv_snd_disable(ndev);
error = phy_ethtool_ksettings_set(ndev->phydev, cmd);
if (error)
goto error_exit;
if (cmd->base.duplex == DUPLEX_FULL)
priv->duplex = 1;
else
priv->duplex = 0;
ravb_set_duplex(ndev);
error_exit:
mdelay(1);
ravb_rcv_snd_enable(ndev);
mmiowb();
spin_unlock_irqrestore(&priv->lock, flags);
return error;
}
static int ravb_nway_reset(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
int error = -ENODEV;
unsigned long flags;
if (ndev->phydev) {
spin_lock_irqsave(&priv->lock, flags);
error = phy_start_aneg(ndev->phydev);
spin_unlock_irqrestore(&priv->lock, flags);
}
return error;
}
static u32 ravb_get_msglevel(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
return priv->msg_enable;
}
static void ravb_set_msglevel(struct net_device *ndev, u32 value)
{
struct ravb_private *priv = netdev_priv(ndev);
priv->msg_enable = value;
}
static int ravb_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return RAVB_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void ravb_get_ethtool_stats(struct net_device *ndev,
struct ethtool_stats *stats, u64 *data)
{
struct ravb_private *priv = netdev_priv(ndev);
int i = 0;
int q;
for (q = RAVB_BE; q < NUM_RX_QUEUE; q++) {
struct net_device_stats *stats = &priv->stats[q];
data[i++] = priv->cur_rx[q];
data[i++] = priv->cur_tx[q];
data[i++] = priv->dirty_rx[q];
data[i++] = priv->dirty_tx[q];
data[i++] = stats->rx_packets;
data[i++] = stats->tx_packets;
data[i++] = stats->rx_bytes;
data[i++] = stats->tx_bytes;
data[i++] = stats->multicast;
data[i++] = stats->rx_errors;
data[i++] = stats->rx_crc_errors;
data[i++] = stats->rx_frame_errors;
data[i++] = stats->rx_length_errors;
data[i++] = stats->rx_missed_errors;
data[i++] = stats->rx_over_errors;
}
}
static void ravb_get_strings(struct net_device *ndev, u32 stringset, u8 *data)
{
switch (stringset) {
case ETH_SS_STATS:
memcpy(data, *ravb_gstrings_stats, sizeof(ravb_gstrings_stats));
break;
}
}
static void ravb_get_ringparam(struct net_device *ndev,
struct ethtool_ringparam *ring)
{
struct ravb_private *priv = netdev_priv(ndev);
ring->rx_max_pending = BE_RX_RING_MAX;
ring->tx_max_pending = BE_TX_RING_MAX;
ring->rx_pending = priv->num_rx_ring[RAVB_BE];
ring->tx_pending = priv->num_tx_ring[RAVB_BE];
}
static int ravb_set_ringparam(struct net_device *ndev,
struct ethtool_ringparam *ring)
{
struct ravb_private *priv = netdev_priv(ndev);
int error;
if (ring->tx_pending > BE_TX_RING_MAX ||
ring->rx_pending > BE_RX_RING_MAX ||
ring->tx_pending < BE_TX_RING_MIN ||
ring->rx_pending < BE_RX_RING_MIN)
return -EINVAL;
if (ring->rx_mini_pending || ring->rx_jumbo_pending)
return -EINVAL;
if (netif_running(ndev)) {
netif_device_detach(ndev);
if (priv->chip_id == RCAR_GEN2)
ravb_ptp_stop(ndev);
error = ravb_stop_dma(ndev);
if (error) {
netdev_err(ndev,
"cannot set ringparam! Any AVB processes are still running?\n");
return error;
}
synchronize_irq(ndev->irq);
ravb_ring_free(ndev, RAVB_BE);
ravb_ring_free(ndev, RAVB_NC);
}
priv->num_rx_ring[RAVB_BE] = ring->rx_pending;
priv->num_tx_ring[RAVB_BE] = ring->tx_pending;
if (netif_running(ndev)) {
error = ravb_dmac_init(ndev);
if (error) {
netdev_err(ndev,
"%s: ravb_dmac_init() failed, error %d\n",
__func__, error);
return error;
}
ravb_emac_init(ndev);
if (priv->chip_id == RCAR_GEN2)
ravb_ptp_init(ndev, priv->pdev);
netif_device_attach(ndev);
}
return 0;
}
static int ravb_get_ts_info(struct net_device *ndev,
struct ethtool_ts_info *info)
{
struct ravb_private *priv = netdev_priv(ndev);
info->so_timestamping =
SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_SOFTWARE |
SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RAW_HARDWARE;
info->tx_types = (1 << HWTSTAMP_TX_OFF) | (1 << HWTSTAMP_TX_ON);
info->rx_filters =
(1 << HWTSTAMP_FILTER_NONE) |
(1 << HWTSTAMP_FILTER_PTP_V2_L2_EVENT) |
(1 << HWTSTAMP_FILTER_ALL);
info->phc_index = ptp_clock_index(priv->ptp.clock);
return 0;
}
static inline int ravb_hook_irq(unsigned int irq, irq_handler_t handler,
struct net_device *ndev, struct device *dev,
const char *ch)
{
char *name;
int error;
name = devm_kasprintf(dev, GFP_KERNEL, "%s:%s", ndev->name, ch);
if (!name)
return -ENOMEM;
error = request_irq(irq, handler, 0, name, ndev);
if (error)
netdev_err(ndev, "cannot request IRQ %s\n", name);
return error;
}
static int ravb_open(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
struct platform_device *pdev = priv->pdev;
struct device *dev = &pdev->dev;
int error;
napi_enable(&priv->napi[RAVB_BE]);
napi_enable(&priv->napi[RAVB_NC]);
if (priv->chip_id == RCAR_GEN2) {
error = request_irq(ndev->irq, ravb_interrupt, IRQF_SHARED,
ndev->name, ndev);
if (error) {
netdev_err(ndev, "cannot request IRQ\n");
goto out_napi_off;
}
} else {
error = ravb_hook_irq(ndev->irq, ravb_multi_interrupt, ndev,
dev, "ch22:multi");
if (error)
goto out_napi_off;
error = ravb_hook_irq(priv->emac_irq, ravb_emac_interrupt, ndev,
dev, "ch24:emac");
if (error)
goto out_free_irq;
error = ravb_hook_irq(priv->rx_irqs[RAVB_BE], ravb_be_interrupt,
ndev, dev, "ch0:rx_be");
if (error)
goto out_free_irq_emac;
error = ravb_hook_irq(priv->tx_irqs[RAVB_BE], ravb_be_interrupt,
ndev, dev, "ch18:tx_be");
if (error)
goto out_free_irq_be_rx;
error = ravb_hook_irq(priv->rx_irqs[RAVB_NC], ravb_nc_interrupt,
ndev, dev, "ch1:rx_nc");
if (error)
goto out_free_irq_be_tx;
error = ravb_hook_irq(priv->tx_irqs[RAVB_NC], ravb_nc_interrupt,
ndev, dev, "ch19:tx_nc");
if (error)
goto out_free_irq_nc_rx;
}
error = ravb_dmac_init(ndev);
if (error)
goto out_free_irq_nc_tx;
ravb_emac_init(ndev);
if (priv->chip_id == RCAR_GEN2)
ravb_ptp_init(ndev, priv->pdev);
netif_tx_start_all_queues(ndev);
error = ravb_phy_start(ndev);
if (error)
goto out_ptp_stop;
return 0;
out_ptp_stop:
if (priv->chip_id == RCAR_GEN2)
ravb_ptp_stop(ndev);
out_free_irq_nc_tx:
if (priv->chip_id == RCAR_GEN2)
goto out_free_irq;
free_irq(priv->tx_irqs[RAVB_NC], ndev);
out_free_irq_nc_rx:
free_irq(priv->rx_irqs[RAVB_NC], ndev);
out_free_irq_be_tx:
free_irq(priv->tx_irqs[RAVB_BE], ndev);
out_free_irq_be_rx:
free_irq(priv->rx_irqs[RAVB_BE], ndev);
out_free_irq_emac:
free_irq(priv->emac_irq, ndev);
out_free_irq:
free_irq(ndev->irq, ndev);
out_napi_off:
napi_disable(&priv->napi[RAVB_NC]);
napi_disable(&priv->napi[RAVB_BE]);
return error;
}
static void ravb_tx_timeout(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
netif_err(priv, tx_err, ndev,
"transmit timed out, status %08x, resetting...\n",
ravb_read(ndev, ISS));
ndev->stats.tx_errors++;
schedule_work(&priv->work);
}
static void ravb_tx_timeout_work(struct work_struct *work)
{
struct ravb_private *priv = container_of(work, struct ravb_private,
work);
struct net_device *ndev = priv->ndev;
netif_tx_stop_all_queues(ndev);
if (priv->chip_id == RCAR_GEN2)
ravb_ptp_stop(ndev);
ravb_stop_dma(ndev);
ravb_ring_free(ndev, RAVB_BE);
ravb_ring_free(ndev, RAVB_NC);
ravb_dmac_init(ndev);
ravb_emac_init(ndev);
if (priv->chip_id == RCAR_GEN2)
ravb_ptp_init(ndev, priv->pdev);
netif_tx_start_all_queues(ndev);
}
static netdev_tx_t ravb_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
u16 q = skb_get_queue_mapping(skb);
struct ravb_tstamp_skb *ts_skb;
struct ravb_tx_desc *desc;
unsigned long flags;
u32 dma_addr;
void *buffer;
u32 entry;
u32 len;
spin_lock_irqsave(&priv->lock, flags);
if (priv->cur_tx[q] - priv->dirty_tx[q] > (priv->num_tx_ring[q] - 1) *
NUM_TX_DESC) {
netif_err(priv, tx_queued, ndev,
"still transmitting with the full ring!\n");
netif_stop_subqueue(ndev, q);
spin_unlock_irqrestore(&priv->lock, flags);
return NETDEV_TX_BUSY;
}
entry = priv->cur_tx[q] % (priv->num_tx_ring[q] * NUM_TX_DESC);
priv->tx_skb[q][entry / NUM_TX_DESC] = skb;
if (skb_put_padto(skb, ETH_ZLEN))
goto drop;
buffer = PTR_ALIGN(priv->tx_align[q], DPTR_ALIGN) +
entry / NUM_TX_DESC * DPTR_ALIGN;
len = PTR_ALIGN(skb->data, DPTR_ALIGN) - skb->data;
memcpy(buffer, skb->data, len);
dma_addr = dma_map_single(ndev->dev.parent, buffer, len, DMA_TO_DEVICE);
if (dma_mapping_error(ndev->dev.parent, dma_addr))
goto drop;
desc = &priv->tx_ring[q][entry];
desc->ds_tagl = cpu_to_le16(len);
desc->dptr = cpu_to_le32(dma_addr);
buffer = skb->data + len;
len = skb->len - len;
dma_addr = dma_map_single(ndev->dev.parent, buffer, len, DMA_TO_DEVICE);
if (dma_mapping_error(ndev->dev.parent, dma_addr))
goto unmap;
desc++;
desc->ds_tagl = cpu_to_le16(len);
desc->dptr = cpu_to_le32(dma_addr);
if (q == RAVB_NC) {
ts_skb = kmalloc(sizeof(*ts_skb), GFP_ATOMIC);
if (!ts_skb) {
desc--;
dma_unmap_single(ndev->dev.parent, dma_addr, len,
DMA_TO_DEVICE);
goto unmap;
}
ts_skb->skb = skb;
ts_skb->tag = priv->ts_skb_tag++;
priv->ts_skb_tag &= 0x3ff;
list_add_tail(&ts_skb->list, &priv->ts_skb_list);
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
desc->tagh_tsr = (ts_skb->tag >> 4) | TX_TSR;
desc->ds_tagl |= le16_to_cpu(ts_skb->tag << 12);
}
skb_tx_timestamp(skb);
dma_wmb();
desc->die_dt = DT_FEND;
desc--;
desc->die_dt = DT_FSTART;
ravb_modify(ndev, TCCR, TCCR_TSRQ0 << q, TCCR_TSRQ0 << q);
priv->cur_tx[q] += NUM_TX_DESC;
if (priv->cur_tx[q] - priv->dirty_tx[q] >
(priv->num_tx_ring[q] - 1) * NUM_TX_DESC && !ravb_tx_free(ndev, q))
netif_stop_subqueue(ndev, q);
exit:
mmiowb();
spin_unlock_irqrestore(&priv->lock, flags);
return NETDEV_TX_OK;
unmap:
dma_unmap_single(ndev->dev.parent, le32_to_cpu(desc->dptr),
le16_to_cpu(desc->ds_tagl), DMA_TO_DEVICE);
drop:
dev_kfree_skb_any(skb);
priv->tx_skb[q][entry / NUM_TX_DESC] = NULL;
goto exit;
}
static u16 ravb_select_queue(struct net_device *ndev, struct sk_buff *skb,
void *accel_priv, select_queue_fallback_t fallback)
{
return (skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) ? RAVB_NC :
RAVB_BE;
}
static struct net_device_stats *ravb_get_stats(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
struct net_device_stats *nstats, *stats0, *stats1;
nstats = &ndev->stats;
stats0 = &priv->stats[RAVB_BE];
stats1 = &priv->stats[RAVB_NC];
nstats->tx_dropped += ravb_read(ndev, TROCR);
ravb_write(ndev, 0, TROCR);
nstats->collisions += ravb_read(ndev, CDCR);
ravb_write(ndev, 0, CDCR);
nstats->tx_carrier_errors += ravb_read(ndev, LCCR);
ravb_write(ndev, 0, LCCR);
nstats->tx_carrier_errors += ravb_read(ndev, CERCR);
ravb_write(ndev, 0, CERCR);
nstats->tx_carrier_errors += ravb_read(ndev, CEECR);
ravb_write(ndev, 0, CEECR);
nstats->rx_packets = stats0->rx_packets + stats1->rx_packets;
nstats->tx_packets = stats0->tx_packets + stats1->tx_packets;
nstats->rx_bytes = stats0->rx_bytes + stats1->rx_bytes;
nstats->tx_bytes = stats0->tx_bytes + stats1->tx_bytes;
nstats->multicast = stats0->multicast + stats1->multicast;
nstats->rx_errors = stats0->rx_errors + stats1->rx_errors;
nstats->rx_crc_errors = stats0->rx_crc_errors + stats1->rx_crc_errors;
nstats->rx_frame_errors =
stats0->rx_frame_errors + stats1->rx_frame_errors;
nstats->rx_length_errors =
stats0->rx_length_errors + stats1->rx_length_errors;
nstats->rx_missed_errors =
stats0->rx_missed_errors + stats1->rx_missed_errors;
nstats->rx_over_errors =
stats0->rx_over_errors + stats1->rx_over_errors;
return nstats;
}
static void ravb_set_rx_mode(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
ravb_modify(ndev, ECMR, ECMR_PRM,
ndev->flags & IFF_PROMISC ? ECMR_PRM : 0);
mmiowb();
spin_unlock_irqrestore(&priv->lock, flags);
}
static int ravb_close(struct net_device *ndev)
{
struct device_node *np = ndev->dev.parent->of_node;
struct ravb_private *priv = netdev_priv(ndev);
struct ravb_tstamp_skb *ts_skb, *ts_skb2;
netif_tx_stop_all_queues(ndev);
ravb_write(ndev, 0, RIC0);
ravb_write(ndev, 0, RIC2);
ravb_write(ndev, 0, TIC);
if (priv->chip_id == RCAR_GEN2)
ravb_ptp_stop(ndev);
if (ravb_stop_dma(ndev) < 0)
netdev_err(ndev,
"device will be stopped after h/w processes are done.\n");
list_for_each_entry_safe(ts_skb, ts_skb2, &priv->ts_skb_list, list) {
list_del(&ts_skb->list);
kfree(ts_skb);
}
if (ndev->phydev) {
phy_stop(ndev->phydev);
phy_disconnect(ndev->phydev);
if (of_phy_is_fixed_link(np))
of_phy_deregister_fixed_link(np);
}
if (priv->chip_id != RCAR_GEN2) {
free_irq(priv->tx_irqs[RAVB_NC], ndev);
free_irq(priv->rx_irqs[RAVB_NC], ndev);
free_irq(priv->tx_irqs[RAVB_BE], ndev);
free_irq(priv->rx_irqs[RAVB_BE], ndev);
free_irq(priv->emac_irq, ndev);
}
free_irq(ndev->irq, ndev);
napi_disable(&priv->napi[RAVB_NC]);
napi_disable(&priv->napi[RAVB_BE]);
ravb_ring_free(ndev, RAVB_BE);
ravb_ring_free(ndev, RAVB_NC);
return 0;
}
static int ravb_hwtstamp_get(struct net_device *ndev, struct ifreq *req)
{
struct ravb_private *priv = netdev_priv(ndev);
struct hwtstamp_config config;
config.flags = 0;
config.tx_type = priv->tstamp_tx_ctrl ? HWTSTAMP_TX_ON :
HWTSTAMP_TX_OFF;
if (priv->tstamp_rx_ctrl & RAVB_RXTSTAMP_TYPE_V2_L2_EVENT)
config.rx_filter = HWTSTAMP_FILTER_PTP_V2_L2_EVENT;
else if (priv->tstamp_rx_ctrl & RAVB_RXTSTAMP_TYPE_ALL)
config.rx_filter = HWTSTAMP_FILTER_ALL;
else
config.rx_filter = HWTSTAMP_FILTER_NONE;
return copy_to_user(req->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
static int ravb_hwtstamp_set(struct net_device *ndev, struct ifreq *req)
{
struct ravb_private *priv = netdev_priv(ndev);
struct hwtstamp_config config;
u32 tstamp_rx_ctrl = RAVB_RXTSTAMP_ENABLED;
u32 tstamp_tx_ctrl;
if (copy_from_user(&config, req->ifr_data, sizeof(config)))
return -EFAULT;
if (config.flags)
return -EINVAL;
switch (config.tx_type) {
case HWTSTAMP_TX_OFF:
tstamp_tx_ctrl = 0;
break;
case HWTSTAMP_TX_ON:
tstamp_tx_ctrl = RAVB_TXTSTAMP_ENABLED;
break;
default:
return -ERANGE;
}
switch (config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
tstamp_rx_ctrl = 0;
break;
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
tstamp_rx_ctrl |= RAVB_RXTSTAMP_TYPE_V2_L2_EVENT;
break;
default:
config.rx_filter = HWTSTAMP_FILTER_ALL;
tstamp_rx_ctrl |= RAVB_RXTSTAMP_TYPE_ALL;
}
priv->tstamp_tx_ctrl = tstamp_tx_ctrl;
priv->tstamp_rx_ctrl = tstamp_rx_ctrl;
return copy_to_user(req->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
static int ravb_do_ioctl(struct net_device *ndev, struct ifreq *req, int cmd)
{
struct phy_device *phydev = ndev->phydev;
if (!netif_running(ndev))
return -EINVAL;
if (!phydev)
return -ENODEV;
switch (cmd) {
case SIOCGHWTSTAMP:
return ravb_hwtstamp_get(ndev, req);
case SIOCSHWTSTAMP:
return ravb_hwtstamp_set(ndev, req);
}
return phy_mii_ioctl(phydev, req, cmd);
}
static int ravb_mdio_init(struct ravb_private *priv)
{
struct platform_device *pdev = priv->pdev;
struct device *dev = &pdev->dev;
int error;
priv->mdiobb.ops = &bb_ops;
priv->mii_bus = alloc_mdio_bitbang(&priv->mdiobb);
if (!priv->mii_bus)
return -ENOMEM;
priv->mii_bus->name = "ravb_mii";
priv->mii_bus->parent = dev;
snprintf(priv->mii_bus->id, MII_BUS_ID_SIZE, "%s-%x",
pdev->name, pdev->id);
error = of_mdiobus_register(priv->mii_bus, dev->of_node);
if (error)
goto out_free_bus;
return 0;
out_free_bus:
free_mdio_bitbang(priv->mii_bus);
return error;
}
static int ravb_mdio_release(struct ravb_private *priv)
{
mdiobus_unregister(priv->mii_bus);
free_mdio_bitbang(priv->mii_bus);
return 0;
}
static int ravb_set_gti(struct net_device *ndev)
{
struct device *dev = ndev->dev.parent;
struct device_node *np = dev->of_node;
unsigned long rate;
struct clk *clk;
uint64_t inc;
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
dev_err(dev, "could not get clock\n");
return PTR_ERR(clk);
}
rate = clk_get_rate(clk);
clk_put(clk);
if (!rate)
return -EINVAL;
inc = 1000000000ULL << 20;
do_div(inc, rate);
if (inc < GTI_TIV_MIN || inc > GTI_TIV_MAX) {
dev_err(dev, "gti.tiv increment 0x%llx is outside the range 0x%x - 0x%x\n",
inc, GTI_TIV_MIN, GTI_TIV_MAX);
return -EINVAL;
}
ravb_write(ndev, inc, GTI);
return 0;
}
static void ravb_set_config_mode(struct net_device *ndev)
{
struct ravb_private *priv = netdev_priv(ndev);
if (priv->chip_id == RCAR_GEN2) {
ravb_modify(ndev, CCC, CCC_OPC, CCC_OPC_CONFIG);
ravb_modify(ndev, CCC, CCC_CSEL, CCC_CSEL_HPB);
} else {
ravb_modify(ndev, CCC, CCC_OPC, CCC_OPC_CONFIG |
CCC_GAC | CCC_CSEL_HPB);
}
}
static int ravb_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct ravb_private *priv;
enum ravb_chip_id chip_id;
struct net_device *ndev;
int error, irq, q;
struct resource *res;
int i;
if (!np) {
dev_err(&pdev->dev,
"this driver is required to be instantiated from device tree\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "invalid resource\n");
return -EINVAL;
}
ndev = alloc_etherdev_mqs(sizeof(struct ravb_private),
NUM_TX_QUEUE, NUM_RX_QUEUE);
if (!ndev)
return -ENOMEM;
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
ndev->base_addr = res->start;
chip_id = (enum ravb_chip_id)of_device_get_match_data(&pdev->dev);
if (chip_id == RCAR_GEN3)
irq = platform_get_irq_byname(pdev, "ch22");
else
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
error = irq;
goto out_release;
}
ndev->irq = irq;
SET_NETDEV_DEV(ndev, &pdev->dev);
priv = netdev_priv(ndev);
priv->ndev = ndev;
priv->pdev = pdev;
priv->num_tx_ring[RAVB_BE] = BE_TX_RING_SIZE;
priv->num_rx_ring[RAVB_BE] = BE_RX_RING_SIZE;
priv->num_tx_ring[RAVB_NC] = NC_TX_RING_SIZE;
priv->num_rx_ring[RAVB_NC] = NC_RX_RING_SIZE;
priv->addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->addr)) {
error = PTR_ERR(priv->addr);
goto out_release;
}
spin_lock_init(&priv->lock);
INIT_WORK(&priv->work, ravb_tx_timeout_work);
priv->phy_interface = of_get_phy_mode(np);
priv->no_avb_link = of_property_read_bool(np, "renesas,no-ether-link");
priv->avb_link_active_low =
of_property_read_bool(np, "renesas,ether-link-active-low");
if (chip_id == RCAR_GEN3) {
irq = platform_get_irq_byname(pdev, "ch24");
if (irq < 0) {
error = irq;
goto out_release;
}
priv->emac_irq = irq;
for (i = 0; i < NUM_RX_QUEUE; i++) {
irq = platform_get_irq_byname(pdev, ravb_rx_irqs[i]);
if (irq < 0) {
error = irq;
goto out_release;
}
priv->rx_irqs[i] = irq;
}
for (i = 0; i < NUM_TX_QUEUE; i++) {
irq = platform_get_irq_byname(pdev, ravb_tx_irqs[i]);
if (irq < 0) {
error = irq;
goto out_release;
}
priv->tx_irqs[i] = irq;
}
}
priv->chip_id = chip_id;
ndev->netdev_ops = &ravb_netdev_ops;
ndev->ethtool_ops = &ravb_ethtool_ops;
ravb_set_config_mode(ndev);
error = ravb_set_gti(ndev);
if (error)
goto out_release;
ravb_modify(ndev, GCCR, GCCR_LTI, GCCR_LTI);
priv->desc_bat_size = sizeof(struct ravb_desc) * DBAT_ENTRY_NUM;
priv->desc_bat = dma_alloc_coherent(ndev->dev.parent, priv->desc_bat_size,
&priv->desc_bat_dma, GFP_KERNEL);
if (!priv->desc_bat) {
dev_err(&pdev->dev,
"Cannot allocate desc base address table (size %d bytes)\n",
priv->desc_bat_size);
error = -ENOMEM;
goto out_release;
}
for (q = RAVB_BE; q < DBAT_ENTRY_NUM; q++)
priv->desc_bat[q].die_dt = DT_EOS;
ravb_write(ndev, priv->desc_bat_dma, DBAT);
INIT_LIST_HEAD(&priv->ts_skb_list);
if (chip_id != RCAR_GEN2)
ravb_ptp_init(ndev, pdev);
priv->msg_enable = RAVB_DEF_MSG_ENABLE;
ravb_read_mac_address(ndev, of_get_mac_address(np));
if (!is_valid_ether_addr(ndev->dev_addr)) {
dev_warn(&pdev->dev,
"no valid MAC address supplied, using a random one\n");
eth_hw_addr_random(ndev);
}
error = ravb_mdio_init(priv);
if (error) {
dev_err(&pdev->dev, "failed to initialize MDIO\n");
goto out_dma_free;
}
netif_napi_add(ndev, &priv->napi[RAVB_BE], ravb_poll, 64);
netif_napi_add(ndev, &priv->napi[RAVB_NC], ravb_poll, 64);
error = register_netdev(ndev);
if (error)
goto out_napi_del;
netdev_info(ndev, "Base address at %#x, %pM, IRQ %d.\n",
(u32)ndev->base_addr, ndev->dev_addr, ndev->irq);
platform_set_drvdata(pdev, ndev);
return 0;
out_napi_del:
netif_napi_del(&priv->napi[RAVB_NC]);
netif_napi_del(&priv->napi[RAVB_BE]);
ravb_mdio_release(priv);
out_dma_free:
dma_free_coherent(ndev->dev.parent, priv->desc_bat_size, priv->desc_bat,
priv->desc_bat_dma);
if (chip_id != RCAR_GEN2)
ravb_ptp_stop(ndev);
out_release:
if (ndev)
free_netdev(ndev);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return error;
}
static int ravb_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct ravb_private *priv = netdev_priv(ndev);
if (priv->chip_id != RCAR_GEN2)
ravb_ptp_stop(ndev);
dma_free_coherent(ndev->dev.parent, priv->desc_bat_size, priv->desc_bat,
priv->desc_bat_dma);
ravb_write(ndev, CCC_OPC_RESET, CCC);
pm_runtime_put_sync(&pdev->dev);
unregister_netdev(ndev);
netif_napi_del(&priv->napi[RAVB_NC]);
netif_napi_del(&priv->napi[RAVB_BE]);
ravb_mdio_release(priv);
pm_runtime_disable(&pdev->dev);
free_netdev(ndev);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __maybe_unused ravb_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
int ret = 0;
if (netif_running(ndev)) {
netif_device_detach(ndev);
ret = ravb_close(ndev);
}
return ret;
}
static int __maybe_unused ravb_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct ravb_private *priv = netdev_priv(ndev);
int ret = 0;
ravb_set_config_mode(ndev);
ret = ravb_set_gti(ndev);
if (ret)
return ret;
ravb_modify(ndev, GCCR, GCCR_LTI, GCCR_LTI);
ravb_write(ndev, priv->desc_bat_dma, DBAT);
if (netif_running(ndev)) {
ret = ravb_open(ndev);
if (ret < 0)
return ret;
netif_device_attach(ndev);
}
return ret;
}
static int __maybe_unused ravb_runtime_nop(struct device *dev)
{
return 0;
}
