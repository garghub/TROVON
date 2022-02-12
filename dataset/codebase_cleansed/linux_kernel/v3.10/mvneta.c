static void mvreg_write(struct mvneta_port *pp, u32 offset, u32 data)
{
writel(data, pp->base + offset);
}
static u32 mvreg_read(struct mvneta_port *pp, u32 offset)
{
return readl(pp->base + offset);
}
static void mvneta_txq_inc_get(struct mvneta_tx_queue *txq)
{
txq->txq_get_index++;
if (txq->txq_get_index == txq->size)
txq->txq_get_index = 0;
}
static void mvneta_txq_inc_put(struct mvneta_tx_queue *txq)
{
txq->txq_put_index++;
if (txq->txq_put_index == txq->size)
txq->txq_put_index = 0;
}
static void mvneta_mib_counters_clear(struct mvneta_port *pp)
{
int i;
u32 dummy;
for (i = 0; i < MVNETA_MIB_LATE_COLLISION; i += 4)
dummy = mvreg_read(pp, (MVNETA_MIB_COUNTERS_BASE + i));
}
struct rtnl_link_stats64 *mvneta_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
struct mvneta_port *pp = netdev_priv(dev);
unsigned int start;
memset(stats, 0, sizeof(struct rtnl_link_stats64));
do {
start = u64_stats_fetch_begin_bh(&pp->rx_stats.syncp);
stats->rx_packets = pp->rx_stats.packets;
stats->rx_bytes = pp->rx_stats.bytes;
} while (u64_stats_fetch_retry_bh(&pp->rx_stats.syncp, start));
do {
start = u64_stats_fetch_begin_bh(&pp->tx_stats.syncp);
stats->tx_packets = pp->tx_stats.packets;
stats->tx_bytes = pp->tx_stats.bytes;
} while (u64_stats_fetch_retry_bh(&pp->tx_stats.syncp, start));
stats->rx_errors = dev->stats.rx_errors;
stats->rx_dropped = dev->stats.rx_dropped;
stats->tx_dropped = dev->stats.tx_dropped;
return stats;
}
static int mvneta_rxq_desc_is_first_last(struct mvneta_rx_desc *desc)
{
return (desc->status & MVNETA_RXD_FIRST_LAST_DESC) ==
MVNETA_RXD_FIRST_LAST_DESC;
}
static void mvneta_rxq_non_occup_desc_add(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq,
int ndescs)
{
while (ndescs > MVNETA_RXQ_ADD_NON_OCCUPIED_MAX) {
mvreg_write(pp, MVNETA_RXQ_STATUS_UPDATE_REG(rxq->id),
(MVNETA_RXQ_ADD_NON_OCCUPIED_MAX <<
MVNETA_RXQ_ADD_NON_OCCUPIED_SHIFT));
ndescs -= MVNETA_RXQ_ADD_NON_OCCUPIED_MAX;
}
mvreg_write(pp, MVNETA_RXQ_STATUS_UPDATE_REG(rxq->id),
(ndescs << MVNETA_RXQ_ADD_NON_OCCUPIED_SHIFT));
}
static int mvneta_rxq_busy_desc_num_get(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq)
{
u32 val;
val = mvreg_read(pp, MVNETA_RXQ_STATUS_REG(rxq->id));
return val & MVNETA_RXQ_OCCUPIED_ALL_MASK;
}
static void mvneta_rxq_desc_num_update(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq,
int rx_done, int rx_filled)
{
u32 val;
if ((rx_done <= 0xff) && (rx_filled <= 0xff)) {
val = rx_done |
(rx_filled << MVNETA_RXQ_ADD_NON_OCCUPIED_SHIFT);
mvreg_write(pp, MVNETA_RXQ_STATUS_UPDATE_REG(rxq->id), val);
return;
}
while ((rx_done > 0) || (rx_filled > 0)) {
if (rx_done <= 0xff) {
val = rx_done;
rx_done = 0;
} else {
val = 0xff;
rx_done -= 0xff;
}
if (rx_filled <= 0xff) {
val |= rx_filled << MVNETA_RXQ_ADD_NON_OCCUPIED_SHIFT;
rx_filled = 0;
} else {
val |= 0xff << MVNETA_RXQ_ADD_NON_OCCUPIED_SHIFT;
rx_filled -= 0xff;
}
mvreg_write(pp, MVNETA_RXQ_STATUS_UPDATE_REG(rxq->id), val);
}
}
static struct mvneta_rx_desc *
mvneta_rxq_next_desc_get(struct mvneta_rx_queue *rxq)
{
int rx_desc = rxq->next_desc_to_proc;
rxq->next_desc_to_proc = MVNETA_QUEUE_NEXT_DESC(rxq, rx_desc);
return rxq->descs + rx_desc;
}
static void mvneta_max_rx_size_set(struct mvneta_port *pp, int max_rx_size)
{
u32 val;
val = mvreg_read(pp, MVNETA_GMAC_CTRL_0);
val &= ~MVNETA_GMAC_MAX_RX_SIZE_MASK;
val |= ((max_rx_size - MVNETA_MH_SIZE) / 2) <<
MVNETA_GMAC_MAX_RX_SIZE_SHIFT;
mvreg_write(pp, MVNETA_GMAC_CTRL_0, val);
}
static void mvneta_rxq_offset_set(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq,
int offset)
{
u32 val;
val = mvreg_read(pp, MVNETA_RXQ_CONFIG_REG(rxq->id));
val &= ~MVNETA_RXQ_PKT_OFFSET_ALL_MASK;
val |= MVNETA_RXQ_PKT_OFFSET_MASK(offset >> 3);
mvreg_write(pp, MVNETA_RXQ_CONFIG_REG(rxq->id), val);
}
static void mvneta_txq_pend_desc_add(struct mvneta_port *pp,
struct mvneta_tx_queue *txq,
int pend_desc)
{
u32 val;
val = pend_desc;
mvreg_write(pp, MVNETA_TXQ_UPDATE_REG(txq->id), val);
}
static struct mvneta_tx_desc *
mvneta_txq_next_desc_get(struct mvneta_tx_queue *txq)
{
int tx_desc = txq->next_desc_to_proc;
txq->next_desc_to_proc = MVNETA_QUEUE_NEXT_DESC(txq, tx_desc);
return txq->descs + tx_desc;
}
static void mvneta_txq_desc_put(struct mvneta_tx_queue *txq)
{
if (txq->next_desc_to_proc == 0)
txq->next_desc_to_proc = txq->last_desc - 1;
else
txq->next_desc_to_proc--;
}
static void mvneta_rxq_buf_size_set(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq,
int buf_size)
{
u32 val;
val = mvreg_read(pp, MVNETA_RXQ_SIZE_REG(rxq->id));
val &= ~MVNETA_RXQ_BUF_SIZE_MASK;
val |= ((buf_size >> 3) << MVNETA_RXQ_BUF_SIZE_SHIFT);
mvreg_write(pp, MVNETA_RXQ_SIZE_REG(rxq->id), val);
}
static void mvneta_rxq_bm_disable(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq)
{
u32 val;
val = mvreg_read(pp, MVNETA_RXQ_CONFIG_REG(rxq->id));
val &= ~MVNETA_RXQ_HW_BUF_ALLOC;
mvreg_write(pp, MVNETA_RXQ_CONFIG_REG(rxq->id), val);
}
static void mvneta_gmac_rgmii_set(struct mvneta_port *pp, int enable)
{
u32 val;
val = mvreg_read(pp, MVNETA_GMAC_CTRL_2);
if (enable)
val |= MVNETA_GMAC2_PORT_RGMII;
else
val &= ~MVNETA_GMAC2_PORT_RGMII;
mvreg_write(pp, MVNETA_GMAC_CTRL_2, val);
}
static void mvneta_port_sgmii_config(struct mvneta_port *pp)
{
u32 val;
val = mvreg_read(pp, MVNETA_GMAC_CTRL_2);
val |= MVNETA_GMAC2_PSC_ENABLE;
mvreg_write(pp, MVNETA_GMAC_CTRL_2, val);
}
static void mvneta_port_up(struct mvneta_port *pp)
{
int queue;
u32 q_map;
mvneta_mib_counters_clear(pp);
q_map = 0;
for (queue = 0; queue < txq_number; queue++) {
struct mvneta_tx_queue *txq = &pp->txqs[queue];
if (txq->descs != NULL)
q_map |= (1 << queue);
}
mvreg_write(pp, MVNETA_TXQ_CMD, q_map);
q_map = 0;
for (queue = 0; queue < rxq_number; queue++) {
struct mvneta_rx_queue *rxq = &pp->rxqs[queue];
if (rxq->descs != NULL)
q_map |= (1 << queue);
}
mvreg_write(pp, MVNETA_RXQ_CMD, q_map);
}
static void mvneta_port_down(struct mvneta_port *pp)
{
u32 val;
int count;
val = mvreg_read(pp, MVNETA_RXQ_CMD) & MVNETA_RXQ_ENABLE_MASK;
if (val != 0)
mvreg_write(pp, MVNETA_RXQ_CMD,
val << MVNETA_RXQ_DISABLE_SHIFT);
count = 0;
do {
if (count++ >= MVNETA_RX_DISABLE_TIMEOUT_MSEC) {
netdev_warn(pp->dev,
"TIMEOUT for RX stopped ! rx_queue_cmd: 0x08%x\n",
val);
break;
}
mdelay(1);
val = mvreg_read(pp, MVNETA_RXQ_CMD);
} while (val & 0xff);
val = (mvreg_read(pp, MVNETA_TXQ_CMD)) & MVNETA_TXQ_ENABLE_MASK;
if (val != 0)
mvreg_write(pp, MVNETA_TXQ_CMD,
(val << MVNETA_TXQ_DISABLE_SHIFT));
count = 0;
do {
if (count++ >= MVNETA_TX_DISABLE_TIMEOUT_MSEC) {
netdev_warn(pp->dev,
"TIMEOUT for TX stopped status=0x%08x\n",
val);
break;
}
mdelay(1);
val = mvreg_read(pp, MVNETA_TXQ_CMD);
} while (val & 0xff);
count = 0;
do {
if (count++ >= MVNETA_TX_FIFO_EMPTY_TIMEOUT) {
netdev_warn(pp->dev,
"TX FIFO empty timeout status=0x08%x\n",
val);
break;
}
mdelay(1);
val = mvreg_read(pp, MVNETA_PORT_STATUS);
} while (!(val & MVNETA_TX_FIFO_EMPTY) &&
(val & MVNETA_TX_IN_PRGRS));
udelay(200);
}
static void mvneta_port_enable(struct mvneta_port *pp)
{
u32 val;
val = mvreg_read(pp, MVNETA_GMAC_CTRL_0);
val |= MVNETA_GMAC0_PORT_ENABLE;
mvreg_write(pp, MVNETA_GMAC_CTRL_0, val);
}
static void mvneta_port_disable(struct mvneta_port *pp)
{
u32 val;
val = mvreg_read(pp, MVNETA_GMAC_CTRL_0);
val &= ~MVNETA_GMAC0_PORT_ENABLE;
mvreg_write(pp, MVNETA_GMAC_CTRL_0, val);
udelay(200);
}
static void mvneta_set_ucast_table(struct mvneta_port *pp, int queue)
{
int offset;
u32 val;
if (queue == -1) {
val = 0;
} else {
val = 0x1 | (queue << 1);
val |= (val << 24) | (val << 16) | (val << 8);
}
for (offset = 0; offset <= 0xc; offset += 4)
mvreg_write(pp, MVNETA_DA_FILT_UCAST_BASE + offset, val);
}
static void mvneta_set_special_mcast_table(struct mvneta_port *pp, int queue)
{
int offset;
u32 val;
if (queue == -1) {
val = 0;
} else {
val = 0x1 | (queue << 1);
val |= (val << 24) | (val << 16) | (val << 8);
}
for (offset = 0; offset <= 0xfc; offset += 4)
mvreg_write(pp, MVNETA_DA_FILT_SPEC_MCAST + offset, val);
}
static void mvneta_set_other_mcast_table(struct mvneta_port *pp, int queue)
{
int offset;
u32 val;
if (queue == -1) {
memset(pp->mcast_count, 0, sizeof(pp->mcast_count));
val = 0;
} else {
memset(pp->mcast_count, 1, sizeof(pp->mcast_count));
val = 0x1 | (queue << 1);
val |= (val << 24) | (val << 16) | (val << 8);
}
for (offset = 0; offset <= 0xfc; offset += 4)
mvreg_write(pp, MVNETA_DA_FILT_OTH_MCAST + offset, val);
}
static void mvneta_defaults_set(struct mvneta_port *pp)
{
int cpu;
int queue;
u32 val;
mvreg_write(pp, MVNETA_INTR_NEW_CAUSE, 0);
mvreg_write(pp, MVNETA_INTR_OLD_CAUSE, 0);
mvreg_write(pp, MVNETA_INTR_MISC_CAUSE, 0);
mvreg_write(pp, MVNETA_INTR_NEW_MASK, 0);
mvreg_write(pp, MVNETA_INTR_OLD_MASK, 0);
mvreg_write(pp, MVNETA_INTR_MISC_MASK, 0);
mvreg_write(pp, MVNETA_INTR_ENABLE, 0);
mvreg_write(pp, MVNETA_MBUS_RETRY, 0x20);
for (cpu = 0; cpu < CONFIG_NR_CPUS; cpu++)
mvreg_write(pp, MVNETA_CPU_MAP(cpu),
(MVNETA_CPU_RXQ_ACCESS_ALL_MASK |
MVNETA_CPU_TXQ_ACCESS_ALL_MASK));
mvreg_write(pp, MVNETA_PORT_RX_RESET, MVNETA_PORT_RX_DMA_RESET);
mvreg_write(pp, MVNETA_PORT_TX_RESET, MVNETA_PORT_TX_DMA_RESET);
mvreg_write(pp, MVNETA_TXQ_CMD_1, 0);
for (queue = 0; queue < txq_number; queue++) {
mvreg_write(pp, MVETH_TXQ_TOKEN_COUNT_REG(queue), 0);
mvreg_write(pp, MVETH_TXQ_TOKEN_CFG_REG(queue), 0);
}
mvreg_write(pp, MVNETA_PORT_TX_RESET, 0);
mvreg_write(pp, MVNETA_PORT_RX_RESET, 0);
val = MVNETA_ACC_MODE_EXT;
mvreg_write(pp, MVNETA_ACC_MODE, val);
val = MVNETA_PORT_CONFIG_DEFL_VALUE(rxq_def);
mvreg_write(pp, MVNETA_PORT_CONFIG, val);
val = 0;
mvreg_write(pp, MVNETA_PORT_CONFIG_EXTEND, val);
mvreg_write(pp, MVNETA_RX_MIN_FRAME_SIZE, 64);
val = 0;
val |= MVNETA_TX_BRST_SZ_MASK(MVNETA_SDMA_BRST_SIZE_16);
val |= MVNETA_RX_BRST_SZ_MASK(MVNETA_SDMA_BRST_SIZE_16);
val |= (MVNETA_RX_NO_DATA_SWAP | MVNETA_TX_NO_DATA_SWAP |
MVNETA_NO_DESC_SWAP);
mvreg_write(pp, MVNETA_SDMA_CONFIG, val);
mvneta_set_ucast_table(pp, -1);
mvneta_set_special_mcast_table(pp, -1);
mvneta_set_other_mcast_table(pp, -1);
mvreg_write(pp, MVNETA_INTR_ENABLE,
(MVNETA_RXQ_INTR_ENABLE_ALL_MASK
| MVNETA_TXQ_INTR_ENABLE_ALL_MASK));
}
static void mvneta_txq_max_tx_size_set(struct mvneta_port *pp, int max_tx_size)
{
u32 val, size, mtu;
int queue;
mtu = max_tx_size * 8;
if (mtu > MVNETA_TX_MTU_MAX)
mtu = MVNETA_TX_MTU_MAX;
val = mvreg_read(pp, MVNETA_TX_MTU);
val &= ~MVNETA_TX_MTU_MAX;
val |= mtu;
mvreg_write(pp, MVNETA_TX_MTU, val);
val = mvreg_read(pp, MVNETA_TX_TOKEN_SIZE);
size = val & MVNETA_TX_TOKEN_SIZE_MAX;
if (size < mtu) {
size = mtu;
val &= ~MVNETA_TX_TOKEN_SIZE_MAX;
val |= size;
mvreg_write(pp, MVNETA_TX_TOKEN_SIZE, val);
}
for (queue = 0; queue < txq_number; queue++) {
val = mvreg_read(pp, MVNETA_TXQ_TOKEN_SIZE_REG(queue));
size = val & MVNETA_TXQ_TOKEN_SIZE_MAX;
if (size < mtu) {
size = mtu;
val &= ~MVNETA_TXQ_TOKEN_SIZE_MAX;
val |= size;
mvreg_write(pp, MVNETA_TXQ_TOKEN_SIZE_REG(queue), val);
}
}
}
static void mvneta_set_ucast_addr(struct mvneta_port *pp, u8 last_nibble,
int queue)
{
unsigned int unicast_reg;
unsigned int tbl_offset;
unsigned int reg_offset;
last_nibble = (0xf & last_nibble);
tbl_offset = (last_nibble / 4) * 4;
reg_offset = last_nibble % 4;
unicast_reg = mvreg_read(pp, (MVNETA_DA_FILT_UCAST_BASE + tbl_offset));
if (queue == -1) {
unicast_reg &= ~(0xff << (8 * reg_offset));
} else {
unicast_reg &= ~(0xff << (8 * reg_offset));
unicast_reg |= ((0x01 | (queue << 1)) << (8 * reg_offset));
}
mvreg_write(pp, (MVNETA_DA_FILT_UCAST_BASE + tbl_offset), unicast_reg);
}
static void mvneta_mac_addr_set(struct mvneta_port *pp, unsigned char *addr,
int queue)
{
unsigned int mac_h;
unsigned int mac_l;
if (queue != -1) {
mac_l = (addr[4] << 8) | (addr[5]);
mac_h = (addr[0] << 24) | (addr[1] << 16) |
(addr[2] << 8) | (addr[3] << 0);
mvreg_write(pp, MVNETA_MAC_ADDR_LOW, mac_l);
mvreg_write(pp, MVNETA_MAC_ADDR_HIGH, mac_h);
}
mvneta_set_ucast_addr(pp, addr[5], queue);
}
static void mvneta_rx_pkts_coal_set(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq, u32 value)
{
mvreg_write(pp, MVNETA_RXQ_THRESHOLD_REG(rxq->id),
value | MVNETA_RXQ_NON_OCCUPIED(0));
rxq->pkts_coal = value;
}
static void mvneta_rx_time_coal_set(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq, u32 value)
{
u32 val;
unsigned long clk_rate;
clk_rate = clk_get_rate(pp->clk);
val = (clk_rate / 1000000) * value;
mvreg_write(pp, MVNETA_RXQ_TIME_COAL_REG(rxq->id), val);
rxq->time_coal = value;
}
static void mvneta_tx_done_pkts_coal_set(struct mvneta_port *pp,
struct mvneta_tx_queue *txq, u32 value)
{
u32 val;
val = mvreg_read(pp, MVNETA_TXQ_SIZE_REG(txq->id));
val &= ~MVNETA_TXQ_SENT_THRESH_ALL_MASK;
val |= MVNETA_TXQ_SENT_THRESH_MASK(value);
mvreg_write(pp, MVNETA_TXQ_SIZE_REG(txq->id), val);
txq->done_pkts_coal = value;
}
static void mvneta_add_tx_done_timer(struct mvneta_port *pp)
{
if (test_and_set_bit(MVNETA_F_TX_DONE_TIMER_BIT, &pp->flags) == 0) {
pp->tx_done_timer.expires = jiffies +
msecs_to_jiffies(MVNETA_TX_DONE_TIMER_PERIOD);
add_timer(&pp->tx_done_timer);
}
}
static void mvneta_rx_desc_fill(struct mvneta_rx_desc *rx_desc,
u32 phys_addr, u32 cookie)
{
rx_desc->buf_cookie = cookie;
rx_desc->buf_phys_addr = phys_addr;
}
static void mvneta_txq_sent_desc_dec(struct mvneta_port *pp,
struct mvneta_tx_queue *txq,
int sent_desc)
{
u32 val;
while (sent_desc > 0xff) {
val = 0xff << MVNETA_TXQ_DEC_SENT_SHIFT;
mvreg_write(pp, MVNETA_TXQ_UPDATE_REG(txq->id), val);
sent_desc = sent_desc - 0xff;
}
val = sent_desc << MVNETA_TXQ_DEC_SENT_SHIFT;
mvreg_write(pp, MVNETA_TXQ_UPDATE_REG(txq->id), val);
}
static int mvneta_txq_sent_desc_num_get(struct mvneta_port *pp,
struct mvneta_tx_queue *txq)
{
u32 val;
int sent_desc;
val = mvreg_read(pp, MVNETA_TXQ_STATUS_REG(txq->id));
sent_desc = (val & MVNETA_TXQ_SENT_DESC_MASK) >>
MVNETA_TXQ_SENT_DESC_SHIFT;
return sent_desc;
}
static int mvneta_txq_sent_desc_proc(struct mvneta_port *pp,
struct mvneta_tx_queue *txq)
{
int sent_desc;
sent_desc = mvneta_txq_sent_desc_num_get(pp, txq);
if (sent_desc)
mvneta_txq_sent_desc_dec(pp, txq, sent_desc);
return sent_desc;
}
static u32 mvneta_txq_desc_csum(int l3_offs, int l3_proto,
int ip_hdr_len, int l4_proto)
{
u32 command;
command = l3_offs << MVNETA_TX_L3_OFF_SHIFT;
command |= ip_hdr_len << MVNETA_TX_IP_HLEN_SHIFT;
if (l3_proto == swab16(ETH_P_IP))
command |= MVNETA_TXD_IP_CSUM;
else
command |= MVNETA_TX_L3_IP6;
if (l4_proto == IPPROTO_TCP)
command |= MVNETA_TX_L4_CSUM_FULL;
else if (l4_proto == IPPROTO_UDP)
command |= MVNETA_TX_L4_UDP | MVNETA_TX_L4_CSUM_FULL;
else
command |= MVNETA_TX_L4_CSUM_NOT;
return command;
}
static void mvneta_rx_error(struct mvneta_port *pp,
struct mvneta_rx_desc *rx_desc)
{
u32 status = rx_desc->status;
if (!mvneta_rxq_desc_is_first_last(rx_desc)) {
netdev_err(pp->dev,
"bad rx status %08x (buffer oversize), size=%d\n",
rx_desc->status, rx_desc->data_size);
return;
}
switch (status & MVNETA_RXD_ERR_CODE_MASK) {
case MVNETA_RXD_ERR_CRC:
netdev_err(pp->dev, "bad rx status %08x (crc error), size=%d\n",
status, rx_desc->data_size);
break;
case MVNETA_RXD_ERR_OVERRUN:
netdev_err(pp->dev, "bad rx status %08x (overrun error), size=%d\n",
status, rx_desc->data_size);
break;
case MVNETA_RXD_ERR_LEN:
netdev_err(pp->dev, "bad rx status %08x (max frame length error), size=%d\n",
status, rx_desc->data_size);
break;
case MVNETA_RXD_ERR_RESOURCE:
netdev_err(pp->dev, "bad rx status %08x (resource error), size=%d\n",
status, rx_desc->data_size);
break;
}
}
static void mvneta_rx_csum(struct mvneta_port *pp,
struct mvneta_rx_desc *rx_desc,
struct sk_buff *skb)
{
if ((rx_desc->status & MVNETA_RXD_L3_IP4) &&
(rx_desc->status & MVNETA_RXD_L4_CSUM_OK)) {
skb->csum = 0;
skb->ip_summed = CHECKSUM_UNNECESSARY;
return;
}
skb->ip_summed = CHECKSUM_NONE;
}
static struct mvneta_tx_queue *mvneta_tx_done_policy(struct mvneta_port *pp,
u32 cause)
{
int queue = fls(cause) - 1;
return (queue < 0 || queue >= txq_number) ? NULL : &pp->txqs[queue];
}
static void mvneta_txq_bufs_free(struct mvneta_port *pp,
struct mvneta_tx_queue *txq, int num)
{
int i;
for (i = 0; i < num; i++) {
struct mvneta_tx_desc *tx_desc = txq->descs +
txq->txq_get_index;
struct sk_buff *skb = txq->tx_skb[txq->txq_get_index];
mvneta_txq_inc_get(txq);
if (!skb)
continue;
dma_unmap_single(pp->dev->dev.parent, tx_desc->buf_phys_addr,
tx_desc->data_size, DMA_TO_DEVICE);
dev_kfree_skb_any(skb);
}
}
static int mvneta_txq_done(struct mvneta_port *pp,
struct mvneta_tx_queue *txq)
{
struct netdev_queue *nq = netdev_get_tx_queue(pp->dev, txq->id);
int tx_done;
tx_done = mvneta_txq_sent_desc_proc(pp, txq);
if (tx_done == 0)
return tx_done;
mvneta_txq_bufs_free(pp, txq, tx_done);
txq->count -= tx_done;
if (netif_tx_queue_stopped(nq)) {
if (txq->size - txq->count >= MAX_SKB_FRAGS + 1)
netif_tx_wake_queue(nq);
}
return tx_done;
}
static int mvneta_rx_refill(struct mvneta_port *pp,
struct mvneta_rx_desc *rx_desc)
{
dma_addr_t phys_addr;
struct sk_buff *skb;
skb = netdev_alloc_skb(pp->dev, pp->pkt_size);
if (!skb)
return -ENOMEM;
phys_addr = dma_map_single(pp->dev->dev.parent, skb->head,
MVNETA_RX_BUF_SIZE(pp->pkt_size),
DMA_FROM_DEVICE);
if (unlikely(dma_mapping_error(pp->dev->dev.parent, phys_addr))) {
dev_kfree_skb(skb);
return -ENOMEM;
}
mvneta_rx_desc_fill(rx_desc, phys_addr, (u32)skb);
return 0;
}
static u32 mvneta_skb_tx_csum(struct mvneta_port *pp, struct sk_buff *skb)
{
if (skb->ip_summed == CHECKSUM_PARTIAL) {
int ip_hdr_len = 0;
u8 l4_proto;
if (skb->protocol == htons(ETH_P_IP)) {
struct iphdr *ip4h = ip_hdr(skb);
ip_hdr_len = ip4h->ihl;
l4_proto = ip4h->protocol;
} else if (skb->protocol == htons(ETH_P_IPV6)) {
struct ipv6hdr *ip6h = ipv6_hdr(skb);
if (skb_network_header_len(skb) > 0)
ip_hdr_len = (skb_network_header_len(skb) >> 2);
l4_proto = ip6h->nexthdr;
} else
return MVNETA_TX_L4_CSUM_NOT;
return mvneta_txq_desc_csum(skb_network_offset(skb),
skb->protocol, ip_hdr_len, l4_proto);
}
return MVNETA_TX_L4_CSUM_NOT;
}
static struct mvneta_rx_queue *mvneta_rx_policy(struct mvneta_port *pp,
u32 cause)
{
int queue = fls(cause >> 8) - 1;
return (queue < 0 || queue >= rxq_number) ? NULL : &pp->rxqs[queue];
}
static void mvneta_rxq_drop_pkts(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq)
{
int rx_done, i;
rx_done = mvneta_rxq_busy_desc_num_get(pp, rxq);
for (i = 0; i < rxq->size; i++) {
struct mvneta_rx_desc *rx_desc = rxq->descs + i;
struct sk_buff *skb = (struct sk_buff *)rx_desc->buf_cookie;
dev_kfree_skb_any(skb);
dma_unmap_single(pp->dev->dev.parent, rx_desc->buf_phys_addr,
rx_desc->data_size, DMA_FROM_DEVICE);
}
if (rx_done)
mvneta_rxq_desc_num_update(pp, rxq, rx_done, rx_done);
}
static int mvneta_rx(struct mvneta_port *pp, int rx_todo,
struct mvneta_rx_queue *rxq)
{
struct net_device *dev = pp->dev;
int rx_done, rx_filled;
rx_done = mvneta_rxq_busy_desc_num_get(pp, rxq);
if (rx_todo > rx_done)
rx_todo = rx_done;
rx_done = 0;
rx_filled = 0;
while (rx_done < rx_todo) {
struct mvneta_rx_desc *rx_desc = mvneta_rxq_next_desc_get(rxq);
struct sk_buff *skb;
u32 rx_status;
int rx_bytes, err;
prefetch(rx_desc);
rx_done++;
rx_filled++;
rx_status = rx_desc->status;
skb = (struct sk_buff *)rx_desc->buf_cookie;
if (!mvneta_rxq_desc_is_first_last(rx_desc) ||
(rx_status & MVNETA_RXD_ERR_SUMMARY)) {
dev->stats.rx_errors++;
mvneta_rx_error(pp, rx_desc);
mvneta_rx_desc_fill(rx_desc, rx_desc->buf_phys_addr,
(u32)skb);
continue;
}
dma_unmap_single(pp->dev->dev.parent, rx_desc->buf_phys_addr,
rx_desc->data_size, DMA_FROM_DEVICE);
rx_bytes = rx_desc->data_size -
(ETH_FCS_LEN + MVNETA_MH_SIZE);
u64_stats_update_begin(&pp->rx_stats.syncp);
pp->rx_stats.packets++;
pp->rx_stats.bytes += rx_bytes;
u64_stats_update_end(&pp->rx_stats.syncp);
skb_reserve(skb, MVNETA_MH_SIZE);
skb_put(skb, rx_bytes);
skb->protocol = eth_type_trans(skb, dev);
mvneta_rx_csum(pp, rx_desc, skb);
napi_gro_receive(&pp->napi, skb);
err = mvneta_rx_refill(pp, rx_desc);
if (err) {
netdev_err(pp->dev, "Linux processing - Can't refill\n");
rxq->missed++;
rx_filled--;
}
}
mvneta_rxq_desc_num_update(pp, rxq, rx_done, rx_filled);
return rx_done;
}
static int mvneta_tx_frag_process(struct mvneta_port *pp, struct sk_buff *skb,
struct mvneta_tx_queue *txq)
{
struct mvneta_tx_desc *tx_desc;
int i;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
void *addr = page_address(frag->page.p) + frag->page_offset;
tx_desc = mvneta_txq_next_desc_get(txq);
tx_desc->data_size = frag->size;
tx_desc->buf_phys_addr =
dma_map_single(pp->dev->dev.parent, addr,
tx_desc->data_size, DMA_TO_DEVICE);
if (dma_mapping_error(pp->dev->dev.parent,
tx_desc->buf_phys_addr)) {
mvneta_txq_desc_put(txq);
goto error;
}
if (i == (skb_shinfo(skb)->nr_frags - 1)) {
tx_desc->command = MVNETA_TXD_L_DESC | MVNETA_TXD_Z_PAD;
txq->tx_skb[txq->txq_put_index] = skb;
mvneta_txq_inc_put(txq);
} else {
tx_desc->command = 0;
txq->tx_skb[txq->txq_put_index] = NULL;
mvneta_txq_inc_put(txq);
}
}
return 0;
error:
for (i = i - 1; i >= 0; i--) {
tx_desc = txq->descs + i;
dma_unmap_single(pp->dev->dev.parent,
tx_desc->buf_phys_addr,
tx_desc->data_size,
DMA_TO_DEVICE);
mvneta_txq_desc_put(txq);
}
return -ENOMEM;
}
static int mvneta_tx(struct sk_buff *skb, struct net_device *dev)
{
struct mvneta_port *pp = netdev_priv(dev);
u16 txq_id = skb_get_queue_mapping(skb);
struct mvneta_tx_queue *txq = &pp->txqs[txq_id];
struct mvneta_tx_desc *tx_desc;
struct netdev_queue *nq;
int frags = 0;
u32 tx_cmd;
if (!netif_running(dev))
goto out;
frags = skb_shinfo(skb)->nr_frags + 1;
nq = netdev_get_tx_queue(dev, txq_id);
tx_desc = mvneta_txq_next_desc_get(txq);
tx_cmd = mvneta_skb_tx_csum(pp, skb);
tx_desc->data_size = skb_headlen(skb);
tx_desc->buf_phys_addr = dma_map_single(dev->dev.parent, skb->data,
tx_desc->data_size,
DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(dev->dev.parent,
tx_desc->buf_phys_addr))) {
mvneta_txq_desc_put(txq);
frags = 0;
goto out;
}
if (frags == 1) {
tx_cmd |= MVNETA_TXD_FLZ_DESC;
tx_desc->command = tx_cmd;
txq->tx_skb[txq->txq_put_index] = skb;
mvneta_txq_inc_put(txq);
} else {
tx_cmd |= MVNETA_TXD_F_DESC;
txq->tx_skb[txq->txq_put_index] = NULL;
mvneta_txq_inc_put(txq);
tx_desc->command = tx_cmd;
if (mvneta_tx_frag_process(pp, skb, txq)) {
dma_unmap_single(dev->dev.parent,
tx_desc->buf_phys_addr,
tx_desc->data_size,
DMA_TO_DEVICE);
mvneta_txq_desc_put(txq);
frags = 0;
goto out;
}
}
txq->count += frags;
mvneta_txq_pend_desc_add(pp, txq, frags);
if (txq->size - txq->count < MAX_SKB_FRAGS + 1)
netif_tx_stop_queue(nq);
out:
if (frags > 0) {
u64_stats_update_begin(&pp->tx_stats.syncp);
pp->tx_stats.packets++;
pp->tx_stats.bytes += skb->len;
u64_stats_update_end(&pp->tx_stats.syncp);
} else {
dev->stats.tx_dropped++;
dev_kfree_skb_any(skb);
}
if (txq->count >= MVNETA_TXDONE_COAL_PKTS)
mvneta_txq_done(pp, txq);
if (txq->count == frags && frags > 0)
mvneta_add_tx_done_timer(pp);
return NETDEV_TX_OK;
}
static void mvneta_txq_done_force(struct mvneta_port *pp,
struct mvneta_tx_queue *txq)
{
int tx_done = txq->count;
mvneta_txq_bufs_free(pp, txq, tx_done);
txq->count = 0;
txq->txq_put_index = 0;
txq->txq_get_index = 0;
}
static u32 mvneta_tx_done_gbe(struct mvneta_port *pp, u32 cause_tx_done,
int *tx_todo)
{
struct mvneta_tx_queue *txq;
u32 tx_done = 0;
struct netdev_queue *nq;
*tx_todo = 0;
while (cause_tx_done != 0) {
txq = mvneta_tx_done_policy(pp, cause_tx_done);
if (!txq)
break;
nq = netdev_get_tx_queue(pp->dev, txq->id);
__netif_tx_lock(nq, smp_processor_id());
if (txq->count) {
tx_done += mvneta_txq_done(pp, txq);
*tx_todo += txq->count;
}
__netif_tx_unlock(nq);
cause_tx_done &= ~((1 << txq->id));
}
return tx_done;
}
static int mvneta_addr_crc(unsigned char *addr)
{
int crc = 0;
int i;
for (i = 0; i < ETH_ALEN; i++) {
int j;
crc = (crc ^ addr[i]) << 8;
for (j = 7; j >= 0; j--) {
if (crc & (0x100 << j))
crc ^= 0x107 << j;
}
}
return crc;
}
static void mvneta_set_special_mcast_addr(struct mvneta_port *pp,
unsigned char last_byte,
int queue)
{
unsigned int smc_table_reg;
unsigned int tbl_offset;
unsigned int reg_offset;
tbl_offset = (last_byte / 4);
reg_offset = last_byte % 4;
smc_table_reg = mvreg_read(pp, (MVNETA_DA_FILT_SPEC_MCAST
+ tbl_offset * 4));
if (queue == -1)
smc_table_reg &= ~(0xff << (8 * reg_offset));
else {
smc_table_reg &= ~(0xff << (8 * reg_offset));
smc_table_reg |= ((0x01 | (queue << 1)) << (8 * reg_offset));
}
mvreg_write(pp, MVNETA_DA_FILT_SPEC_MCAST + tbl_offset * 4,
smc_table_reg);
}
static void mvneta_set_other_mcast_addr(struct mvneta_port *pp,
unsigned char crc8,
int queue)
{
unsigned int omc_table_reg;
unsigned int tbl_offset;
unsigned int reg_offset;
tbl_offset = (crc8 / 4) * 4;
reg_offset = crc8 % 4;
omc_table_reg = mvreg_read(pp, MVNETA_DA_FILT_OTH_MCAST + tbl_offset);
if (queue == -1) {
omc_table_reg &= ~(0xff << (8 * reg_offset));
} else {
omc_table_reg &= ~(0xff << (8 * reg_offset));
omc_table_reg |= ((0x01 | (queue << 1)) << (8 * reg_offset));
}
mvreg_write(pp, MVNETA_DA_FILT_OTH_MCAST + tbl_offset, omc_table_reg);
}
static int mvneta_mcast_addr_set(struct mvneta_port *pp, unsigned char *p_addr,
int queue)
{
unsigned char crc_result = 0;
if (memcmp(p_addr, "\x01\x00\x5e\x00\x00", 5) == 0) {
mvneta_set_special_mcast_addr(pp, p_addr[5], queue);
return 0;
}
crc_result = mvneta_addr_crc(p_addr);
if (queue == -1) {
if (pp->mcast_count[crc_result] == 0) {
netdev_info(pp->dev, "No valid Mcast for crc8=0x%02x\n",
crc_result);
return -EINVAL;
}
pp->mcast_count[crc_result]--;
if (pp->mcast_count[crc_result] != 0) {
netdev_info(pp->dev,
"After delete there are %d valid Mcast for crc8=0x%02x\n",
pp->mcast_count[crc_result], crc_result);
return -EINVAL;
}
} else
pp->mcast_count[crc_result]++;
mvneta_set_other_mcast_addr(pp, crc_result, queue);
return 0;
}
static void mvneta_rx_unicast_promisc_set(struct mvneta_port *pp,
int is_promisc)
{
u32 port_cfg_reg, val;
port_cfg_reg = mvreg_read(pp, MVNETA_PORT_CONFIG);
val = mvreg_read(pp, MVNETA_TYPE_PRIO);
if (is_promisc) {
port_cfg_reg |= MVNETA_UNI_PROMISC_MODE;
val |= MVNETA_FORCE_UNI;
mvreg_write(pp, MVNETA_MAC_ADDR_LOW, 0xffff);
mvreg_write(pp, MVNETA_MAC_ADDR_HIGH, 0xffffffff);
} else {
port_cfg_reg &= ~MVNETA_UNI_PROMISC_MODE;
val &= ~MVNETA_FORCE_UNI;
}
mvreg_write(pp, MVNETA_PORT_CONFIG, port_cfg_reg);
mvreg_write(pp, MVNETA_TYPE_PRIO, val);
}
static void mvneta_set_rx_mode(struct net_device *dev)
{
struct mvneta_port *pp = netdev_priv(dev);
struct netdev_hw_addr *ha;
if (dev->flags & IFF_PROMISC) {
mvneta_rx_unicast_promisc_set(pp, 1);
mvneta_set_ucast_table(pp, rxq_def);
mvneta_set_special_mcast_table(pp, rxq_def);
mvneta_set_other_mcast_table(pp, rxq_def);
} else {
mvneta_rx_unicast_promisc_set(pp, 0);
mvneta_set_ucast_table(pp, -1);
mvneta_mac_addr_set(pp, dev->dev_addr, rxq_def);
if (dev->flags & IFF_ALLMULTI) {
mvneta_set_special_mcast_table(pp, rxq_def);
mvneta_set_other_mcast_table(pp, rxq_def);
} else {
mvneta_set_special_mcast_table(pp, -1);
mvneta_set_other_mcast_table(pp, -1);
if (!netdev_mc_empty(dev)) {
netdev_for_each_mc_addr(ha, dev) {
mvneta_mcast_addr_set(pp, ha->addr,
rxq_def);
}
}
}
}
}
static irqreturn_t mvneta_isr(int irq, void *dev_id)
{
struct mvneta_port *pp = (struct mvneta_port *)dev_id;
mvreg_write(pp, MVNETA_INTR_NEW_MASK, 0);
napi_schedule(&pp->napi);
return IRQ_HANDLED;
}
static int mvneta_poll(struct napi_struct *napi, int budget)
{
int rx_done = 0;
u32 cause_rx_tx;
unsigned long flags;
struct mvneta_port *pp = netdev_priv(napi->dev);
if (!netif_running(pp->dev)) {
napi_complete(napi);
return rx_done;
}
cause_rx_tx = mvreg_read(pp, MVNETA_INTR_NEW_CAUSE) &
MVNETA_RX_INTR_MASK(rxq_number);
cause_rx_tx |= pp->cause_rx_tx;
if (rxq_number > 1) {
while ((cause_rx_tx != 0) && (budget > 0)) {
int count;
struct mvneta_rx_queue *rxq;
rxq = mvneta_rx_policy(pp, cause_rx_tx);
if (!rxq)
break;
count = mvneta_rx(pp, budget, rxq);
rx_done += count;
budget -= count;
if (budget > 0) {
cause_rx_tx &= ~((1 << rxq->id) << 8);
}
}
} else {
rx_done = mvneta_rx(pp, budget, &pp->rxqs[rxq_def]);
budget -= rx_done;
}
if (budget > 0) {
cause_rx_tx = 0;
napi_complete(napi);
local_irq_save(flags);
mvreg_write(pp, MVNETA_INTR_NEW_MASK,
MVNETA_RX_INTR_MASK(rxq_number));
local_irq_restore(flags);
}
pp->cause_rx_tx = cause_rx_tx;
return rx_done;
}
static void mvneta_tx_done_timer_callback(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct mvneta_port *pp = netdev_priv(dev);
int tx_done = 0, tx_todo = 0;
if (!netif_running(dev))
return ;
clear_bit(MVNETA_F_TX_DONE_TIMER_BIT, &pp->flags);
tx_done = mvneta_tx_done_gbe(pp,
(((1 << txq_number) - 1) &
MVNETA_CAUSE_TXQ_SENT_DESC_ALL_MASK),
&tx_todo);
if (tx_todo > 0)
mvneta_add_tx_done_timer(pp);
}
static int mvneta_rxq_fill(struct mvneta_port *pp, struct mvneta_rx_queue *rxq,
int num)
{
struct net_device *dev = pp->dev;
int i;
for (i = 0; i < num; i++) {
struct sk_buff *skb;
struct mvneta_rx_desc *rx_desc;
unsigned long phys_addr;
skb = dev_alloc_skb(pp->pkt_size);
if (!skb) {
netdev_err(dev, "%s:rxq %d, %d of %d buffs filled\n",
__func__, rxq->id, i, num);
break;
}
rx_desc = rxq->descs + i;
memset(rx_desc, 0, sizeof(struct mvneta_rx_desc));
phys_addr = dma_map_single(dev->dev.parent, skb->head,
MVNETA_RX_BUF_SIZE(pp->pkt_size),
DMA_FROM_DEVICE);
if (unlikely(dma_mapping_error(dev->dev.parent, phys_addr))) {
dev_kfree_skb(skb);
break;
}
mvneta_rx_desc_fill(rx_desc, phys_addr, (u32)skb);
}
mvneta_rxq_non_occup_desc_add(pp, rxq, i);
return i;
}
static void mvneta_tx_reset(struct mvneta_port *pp)
{
int queue;
for (queue = 0; queue < txq_number; queue++)
mvneta_txq_done_force(pp, &pp->txqs[queue]);
mvreg_write(pp, MVNETA_PORT_TX_RESET, MVNETA_PORT_TX_DMA_RESET);
mvreg_write(pp, MVNETA_PORT_TX_RESET, 0);
}
static void mvneta_rx_reset(struct mvneta_port *pp)
{
mvreg_write(pp, MVNETA_PORT_RX_RESET, MVNETA_PORT_RX_DMA_RESET);
mvreg_write(pp, MVNETA_PORT_RX_RESET, 0);
}
static int mvneta_rxq_init(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq)
{
rxq->size = pp->rx_ring_size;
rxq->descs = dma_alloc_coherent(pp->dev->dev.parent,
rxq->size * MVNETA_DESC_ALIGNED_SIZE,
&rxq->descs_phys, GFP_KERNEL);
if (rxq->descs == NULL)
return -ENOMEM;
BUG_ON(rxq->descs !=
PTR_ALIGN(rxq->descs, MVNETA_CPU_D_CACHE_LINE_SIZE));
rxq->last_desc = rxq->size - 1;
mvreg_write(pp, MVNETA_RXQ_BASE_ADDR_REG(rxq->id), rxq->descs_phys);
mvreg_write(pp, MVNETA_RXQ_SIZE_REG(rxq->id), rxq->size);
mvneta_rxq_offset_set(pp, rxq, NET_SKB_PAD);
mvneta_rx_pkts_coal_set(pp, rxq, rxq->pkts_coal);
mvneta_rx_time_coal_set(pp, rxq, rxq->time_coal);
mvneta_rxq_buf_size_set(pp, rxq, MVNETA_RX_BUF_SIZE(pp->pkt_size));
mvneta_rxq_bm_disable(pp, rxq);
mvneta_rxq_fill(pp, rxq, rxq->size);
return 0;
}
static void mvneta_rxq_deinit(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq)
{
mvneta_rxq_drop_pkts(pp, rxq);
if (rxq->descs)
dma_free_coherent(pp->dev->dev.parent,
rxq->size * MVNETA_DESC_ALIGNED_SIZE,
rxq->descs,
rxq->descs_phys);
rxq->descs = NULL;
rxq->last_desc = 0;
rxq->next_desc_to_proc = 0;
rxq->descs_phys = 0;
}
static int mvneta_txq_init(struct mvneta_port *pp,
struct mvneta_tx_queue *txq)
{
txq->size = pp->tx_ring_size;
txq->descs = dma_alloc_coherent(pp->dev->dev.parent,
txq->size * MVNETA_DESC_ALIGNED_SIZE,
&txq->descs_phys, GFP_KERNEL);
if (txq->descs == NULL)
return -ENOMEM;
BUG_ON(txq->descs !=
PTR_ALIGN(txq->descs, MVNETA_CPU_D_CACHE_LINE_SIZE));
txq->last_desc = txq->size - 1;
mvreg_write(pp, MVETH_TXQ_TOKEN_CFG_REG(txq->id), 0x03ffffff);
mvreg_write(pp, MVETH_TXQ_TOKEN_COUNT_REG(txq->id), 0x3fffffff);
mvreg_write(pp, MVNETA_TXQ_BASE_ADDR_REG(txq->id), txq->descs_phys);
mvreg_write(pp, MVNETA_TXQ_SIZE_REG(txq->id), txq->size);
txq->tx_skb = kmalloc(txq->size * sizeof(*txq->tx_skb), GFP_KERNEL);
if (txq->tx_skb == NULL) {
dma_free_coherent(pp->dev->dev.parent,
txq->size * MVNETA_DESC_ALIGNED_SIZE,
txq->descs, txq->descs_phys);
return -ENOMEM;
}
mvneta_tx_done_pkts_coal_set(pp, txq, txq->done_pkts_coal);
return 0;
}
static void mvneta_txq_deinit(struct mvneta_port *pp,
struct mvneta_tx_queue *txq)
{
kfree(txq->tx_skb);
if (txq->descs)
dma_free_coherent(pp->dev->dev.parent,
txq->size * MVNETA_DESC_ALIGNED_SIZE,
txq->descs, txq->descs_phys);
txq->descs = NULL;
txq->last_desc = 0;
txq->next_desc_to_proc = 0;
txq->descs_phys = 0;
mvreg_write(pp, MVETH_TXQ_TOKEN_CFG_REG(txq->id), 0);
mvreg_write(pp, MVETH_TXQ_TOKEN_COUNT_REG(txq->id), 0);
mvreg_write(pp, MVNETA_TXQ_BASE_ADDR_REG(txq->id), 0);
mvreg_write(pp, MVNETA_TXQ_SIZE_REG(txq->id), 0);
}
static void mvneta_cleanup_txqs(struct mvneta_port *pp)
{
int queue;
for (queue = 0; queue < txq_number; queue++)
mvneta_txq_deinit(pp, &pp->txqs[queue]);
}
static void mvneta_cleanup_rxqs(struct mvneta_port *pp)
{
int queue;
for (queue = 0; queue < rxq_number; queue++)
mvneta_rxq_deinit(pp, &pp->rxqs[queue]);
}
static int mvneta_setup_rxqs(struct mvneta_port *pp)
{
int queue;
for (queue = 0; queue < rxq_number; queue++) {
int err = mvneta_rxq_init(pp, &pp->rxqs[queue]);
if (err) {
netdev_err(pp->dev, "%s: can't create rxq=%d\n",
__func__, queue);
mvneta_cleanup_rxqs(pp);
return err;
}
}
return 0;
}
static int mvneta_setup_txqs(struct mvneta_port *pp)
{
int queue;
for (queue = 0; queue < txq_number; queue++) {
int err = mvneta_txq_init(pp, &pp->txqs[queue]);
if (err) {
netdev_err(pp->dev, "%s: can't create txq=%d\n",
__func__, queue);
mvneta_cleanup_txqs(pp);
return err;
}
}
return 0;
}
static void mvneta_start_dev(struct mvneta_port *pp)
{
mvneta_max_rx_size_set(pp, pp->pkt_size);
mvneta_txq_max_tx_size_set(pp, pp->pkt_size);
mvneta_port_enable(pp);
napi_enable(&pp->napi);
mvreg_write(pp, MVNETA_INTR_NEW_MASK,
MVNETA_RX_INTR_MASK(rxq_number));
phy_start(pp->phy_dev);
netif_tx_start_all_queues(pp->dev);
}
static void mvneta_stop_dev(struct mvneta_port *pp)
{
phy_stop(pp->phy_dev);
napi_disable(&pp->napi);
netif_carrier_off(pp->dev);
mvneta_port_down(pp);
netif_tx_stop_all_queues(pp->dev);
mvneta_port_disable(pp);
mvreg_write(pp, MVNETA_INTR_MISC_CAUSE, 0);
mvreg_write(pp, MVNETA_INTR_OLD_CAUSE, 0);
mvreg_write(pp, MVNETA_INTR_NEW_MASK, 0);
mvreg_write(pp, MVNETA_INTR_OLD_MASK, 0);
mvreg_write(pp, MVNETA_INTR_MISC_MASK, 0);
mvneta_tx_reset(pp);
mvneta_rx_reset(pp);
}
static void mvneta_tx_timeout(struct net_device *dev)
{
struct mvneta_port *pp = netdev_priv(dev);
netdev_info(dev, "tx timeout\n");
mvneta_stop_dev(pp);
mvneta_start_dev(pp);
}
static int mvneta_check_mtu_valid(struct net_device *dev, int mtu)
{
if (mtu < 68) {
netdev_err(dev, "cannot change mtu to less than 68\n");
return -EINVAL;
}
if (mtu > 9676) {
netdev_info(dev, "Illegal MTU value %d, round to 9676\n", mtu);
mtu = 9676;
}
if (!IS_ALIGNED(MVNETA_RX_PKT_SIZE(mtu), 8)) {
netdev_info(dev, "Illegal MTU value %d, rounding to %d\n",
mtu, ALIGN(MVNETA_RX_PKT_SIZE(mtu), 8));
mtu = ALIGN(MVNETA_RX_PKT_SIZE(mtu), 8);
}
return mtu;
}
static int mvneta_change_mtu(struct net_device *dev, int mtu)
{
struct mvneta_port *pp = netdev_priv(dev);
int ret;
mtu = mvneta_check_mtu_valid(dev, mtu);
if (mtu < 0)
return -EINVAL;
dev->mtu = mtu;
if (!netif_running(dev))
return 0;
mvneta_stop_dev(pp);
mvneta_cleanup_txqs(pp);
mvneta_cleanup_rxqs(pp);
pp->pkt_size = MVNETA_RX_PKT_SIZE(pp->dev->mtu);
ret = mvneta_setup_rxqs(pp);
if (ret) {
netdev_err(pp->dev, "unable to setup rxqs after MTU change\n");
return ret;
}
mvneta_setup_txqs(pp);
mvneta_start_dev(pp);
mvneta_port_up(pp);
return 0;
}
static int mvneta_set_mac_addr(struct net_device *dev, void *addr)
{
struct mvneta_port *pp = netdev_priv(dev);
u8 *mac = addr + 2;
int i;
if (netif_running(dev))
return -EBUSY;
mvneta_mac_addr_set(pp, dev->dev_addr, -1);
mvneta_mac_addr_set(pp, mac, rxq_def);
for (i = 0; i < ETH_ALEN; i++)
dev->dev_addr[i] = mac[i];
return 0;
}
static void mvneta_adjust_link(struct net_device *ndev)
{
struct mvneta_port *pp = netdev_priv(ndev);
struct phy_device *phydev = pp->phy_dev;
int status_change = 0;
if (phydev->link) {
if ((pp->speed != phydev->speed) ||
(pp->duplex != phydev->duplex)) {
u32 val;
val = mvreg_read(pp, MVNETA_GMAC_AUTONEG_CONFIG);
val &= ~(MVNETA_GMAC_CONFIG_MII_SPEED |
MVNETA_GMAC_CONFIG_GMII_SPEED |
MVNETA_GMAC_CONFIG_FULL_DUPLEX);
if (phydev->duplex)
val |= MVNETA_GMAC_CONFIG_FULL_DUPLEX;
if (phydev->speed == SPEED_1000)
val |= MVNETA_GMAC_CONFIG_GMII_SPEED;
else
val |= MVNETA_GMAC_CONFIG_MII_SPEED;
mvreg_write(pp, MVNETA_GMAC_AUTONEG_CONFIG, val);
pp->duplex = phydev->duplex;
pp->speed = phydev->speed;
}
}
if (phydev->link != pp->link) {
if (!phydev->link) {
pp->duplex = -1;
pp->speed = 0;
}
pp->link = phydev->link;
status_change = 1;
}
if (status_change) {
if (phydev->link) {
u32 val = mvreg_read(pp, MVNETA_GMAC_AUTONEG_CONFIG);
val |= (MVNETA_GMAC_FORCE_LINK_PASS |
MVNETA_GMAC_FORCE_LINK_DOWN);
mvreg_write(pp, MVNETA_GMAC_AUTONEG_CONFIG, val);
mvneta_port_up(pp);
netdev_info(pp->dev, "link up\n");
} else {
mvneta_port_down(pp);
netdev_info(pp->dev, "link down\n");
}
}
}
static int mvneta_mdio_probe(struct mvneta_port *pp)
{
struct phy_device *phy_dev;
phy_dev = of_phy_connect(pp->dev, pp->phy_node, mvneta_adjust_link, 0,
pp->phy_interface);
if (!phy_dev) {
netdev_err(pp->dev, "could not find the PHY\n");
return -ENODEV;
}
phy_dev->supported &= PHY_GBIT_FEATURES;
phy_dev->advertising = phy_dev->supported;
pp->phy_dev = phy_dev;
pp->link = 0;
pp->duplex = 0;
pp->speed = 0;
return 0;
}
static void mvneta_mdio_remove(struct mvneta_port *pp)
{
phy_disconnect(pp->phy_dev);
pp->phy_dev = NULL;
}
static int mvneta_open(struct net_device *dev)
{
struct mvneta_port *pp = netdev_priv(dev);
int ret;
mvneta_mac_addr_set(pp, dev->dev_addr, rxq_def);
pp->pkt_size = MVNETA_RX_PKT_SIZE(pp->dev->mtu);
ret = mvneta_setup_rxqs(pp);
if (ret)
return ret;
ret = mvneta_setup_txqs(pp);
if (ret)
goto err_cleanup_rxqs;
ret = request_irq(pp->dev->irq, mvneta_isr, 0,
MVNETA_DRIVER_NAME, pp);
if (ret) {
netdev_err(pp->dev, "cannot request irq %d\n", pp->dev->irq);
goto err_cleanup_txqs;
}
netif_carrier_off(pp->dev);
ret = mvneta_mdio_probe(pp);
if (ret < 0) {
netdev_err(dev, "cannot probe MDIO bus\n");
goto err_free_irq;
}
mvneta_start_dev(pp);
return 0;
err_free_irq:
free_irq(pp->dev->irq, pp);
err_cleanup_txqs:
mvneta_cleanup_txqs(pp);
err_cleanup_rxqs:
mvneta_cleanup_rxqs(pp);
return ret;
}
static int mvneta_stop(struct net_device *dev)
{
struct mvneta_port *pp = netdev_priv(dev);
mvneta_stop_dev(pp);
mvneta_mdio_remove(pp);
free_irq(dev->irq, pp);
mvneta_cleanup_rxqs(pp);
mvneta_cleanup_txqs(pp);
del_timer(&pp->tx_done_timer);
clear_bit(MVNETA_F_TX_DONE_TIMER_BIT, &pp->flags);
return 0;
}
int mvneta_ethtool_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct mvneta_port *pp = netdev_priv(dev);
if (!pp->phy_dev)
return -ENODEV;
return phy_ethtool_gset(pp->phy_dev, cmd);
}
int mvneta_ethtool_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct mvneta_port *pp = netdev_priv(dev);
if (!pp->phy_dev)
return -ENODEV;
return phy_ethtool_sset(pp->phy_dev, cmd);
}
static int mvneta_ethtool_set_coalesce(struct net_device *dev,
struct ethtool_coalesce *c)
{
struct mvneta_port *pp = netdev_priv(dev);
int queue;
for (queue = 0; queue < rxq_number; queue++) {
struct mvneta_rx_queue *rxq = &pp->rxqs[queue];
rxq->time_coal = c->rx_coalesce_usecs;
rxq->pkts_coal = c->rx_max_coalesced_frames;
mvneta_rx_pkts_coal_set(pp, rxq, rxq->pkts_coal);
mvneta_rx_time_coal_set(pp, rxq, rxq->time_coal);
}
for (queue = 0; queue < txq_number; queue++) {
struct mvneta_tx_queue *txq = &pp->txqs[queue];
txq->done_pkts_coal = c->tx_max_coalesced_frames;
mvneta_tx_done_pkts_coal_set(pp, txq, txq->done_pkts_coal);
}
return 0;
}
static int mvneta_ethtool_get_coalesce(struct net_device *dev,
struct ethtool_coalesce *c)
{
struct mvneta_port *pp = netdev_priv(dev);
c->rx_coalesce_usecs = pp->rxqs[0].time_coal;
c->rx_max_coalesced_frames = pp->rxqs[0].pkts_coal;
c->tx_max_coalesced_frames = pp->txqs[0].done_pkts_coal;
return 0;
}
static void mvneta_ethtool_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *drvinfo)
{
strlcpy(drvinfo->driver, MVNETA_DRIVER_NAME,
sizeof(drvinfo->driver));
strlcpy(drvinfo->version, MVNETA_DRIVER_VERSION,
sizeof(drvinfo->version));
strlcpy(drvinfo->bus_info, dev_name(&dev->dev),
sizeof(drvinfo->bus_info));
}
static void mvneta_ethtool_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct mvneta_port *pp = netdev_priv(netdev);
ring->rx_max_pending = MVNETA_MAX_RXD;
ring->tx_max_pending = MVNETA_MAX_TXD;
ring->rx_pending = pp->rx_ring_size;
ring->tx_pending = pp->tx_ring_size;
}
static int mvneta_ethtool_set_ringparam(struct net_device *dev,
struct ethtool_ringparam *ring)
{
struct mvneta_port *pp = netdev_priv(dev);
if ((ring->rx_pending == 0) || (ring->tx_pending == 0))
return -EINVAL;
pp->rx_ring_size = ring->rx_pending < MVNETA_MAX_RXD ?
ring->rx_pending : MVNETA_MAX_RXD;
pp->tx_ring_size = ring->tx_pending < MVNETA_MAX_TXD ?
ring->tx_pending : MVNETA_MAX_TXD;
if (netif_running(dev)) {
mvneta_stop(dev);
if (mvneta_open(dev)) {
netdev_err(dev,
"error on opening device after ring param change\n");
return -ENOMEM;
}
}
return 0;
}
static int mvneta_init(struct mvneta_port *pp, int phy_addr)
{
int queue;
mvneta_port_disable(pp);
mvneta_defaults_set(pp);
pp->txqs = kzalloc(txq_number * sizeof(struct mvneta_tx_queue),
GFP_KERNEL);
if (!pp->txqs)
return -ENOMEM;
for (queue = 0; queue < txq_number; queue++) {
struct mvneta_tx_queue *txq = &pp->txqs[queue];
txq->id = queue;
txq->size = pp->tx_ring_size;
txq->done_pkts_coal = MVNETA_TXDONE_COAL_PKTS;
}
pp->rxqs = kzalloc(rxq_number * sizeof(struct mvneta_rx_queue),
GFP_KERNEL);
if (!pp->rxqs) {
kfree(pp->txqs);
return -ENOMEM;
}
for (queue = 0; queue < rxq_number; queue++) {
struct mvneta_rx_queue *rxq = &pp->rxqs[queue];
rxq->id = queue;
rxq->size = pp->rx_ring_size;
rxq->pkts_coal = MVNETA_RX_COAL_PKTS;
rxq->time_coal = MVNETA_RX_COAL_USEC;
}
return 0;
}
static void mvneta_deinit(struct mvneta_port *pp)
{
kfree(pp->txqs);
kfree(pp->rxqs);
}
static void mvneta_conf_mbus_windows(struct mvneta_port *pp,
const struct mbus_dram_target_info *dram)
{
u32 win_enable;
u32 win_protect;
int i;
for (i = 0; i < 6; i++) {
mvreg_write(pp, MVNETA_WIN_BASE(i), 0);
mvreg_write(pp, MVNETA_WIN_SIZE(i), 0);
if (i < 4)
mvreg_write(pp, MVNETA_WIN_REMAP(i), 0);
}
win_enable = 0x3f;
win_protect = 0;
for (i = 0; i < dram->num_cs; i++) {
const struct mbus_dram_window *cs = dram->cs + i;
mvreg_write(pp, MVNETA_WIN_BASE(i), (cs->base & 0xffff0000) |
(cs->mbus_attr << 8) | dram->mbus_dram_target_id);
mvreg_write(pp, MVNETA_WIN_SIZE(i),
(cs->size - 1) & 0xffff0000);
win_enable &= ~(1 << i);
win_protect |= 3 << (2 * i);
}
mvreg_write(pp, MVNETA_BASE_ADDR_ENABLE, win_enable);
}
static void mvneta_port_power_up(struct mvneta_port *pp, int phy_mode)
{
u32 val;
mvreg_write(pp, MVNETA_UNIT_INTR_CAUSE, 0);
if (phy_mode == PHY_INTERFACE_MODE_SGMII)
mvneta_port_sgmii_config(pp);
mvneta_gmac_rgmii_set(pp, 1);
val = mvreg_read(pp, MVNETA_GMAC_CTRL_2);
val &= ~MVNETA_GMAC2_PORT_RESET;
mvreg_write(pp, MVNETA_GMAC_CTRL_2, val);
while ((mvreg_read(pp, MVNETA_GMAC_CTRL_2) &
MVNETA_GMAC2_PORT_RESET) != 0)
continue;
}
static int mvneta_probe(struct platform_device *pdev)
{
const struct mbus_dram_target_info *dram_target_info;
struct device_node *dn = pdev->dev.of_node;
struct device_node *phy_node;
u32 phy_addr;
struct mvneta_port *pp;
struct net_device *dev;
const char *mac_addr;
int phy_mode;
int err;
if (rxq_def != 0) {
dev_err(&pdev->dev, "Invalid rxq_def argument: %d\n", rxq_def);
return -EINVAL;
}
dev = alloc_etherdev_mqs(sizeof(struct mvneta_port), txq_number, rxq_number);
if (!dev)
return -ENOMEM;
dev->irq = irq_of_parse_and_map(dn, 0);
if (dev->irq == 0) {
err = -EINVAL;
goto err_free_netdev;
}
phy_node = of_parse_phandle(dn, "phy", 0);
if (!phy_node) {
dev_err(&pdev->dev, "no associated PHY\n");
err = -ENODEV;
goto err_free_irq;
}
phy_mode = of_get_phy_mode(dn);
if (phy_mode < 0) {
dev_err(&pdev->dev, "incorrect phy-mode\n");
err = -EINVAL;
goto err_free_irq;
}
mac_addr = of_get_mac_address(dn);
if (!mac_addr || !is_valid_ether_addr(mac_addr))
eth_hw_addr_random(dev);
else
memcpy(dev->dev_addr, mac_addr, ETH_ALEN);
dev->tx_queue_len = MVNETA_MAX_TXD;
dev->watchdog_timeo = 5 * HZ;
dev->netdev_ops = &mvneta_netdev_ops;
SET_ETHTOOL_OPS(dev, &mvneta_eth_tool_ops);
pp = netdev_priv(dev);
pp->tx_done_timer.function = mvneta_tx_done_timer_callback;
init_timer(&pp->tx_done_timer);
clear_bit(MVNETA_F_TX_DONE_TIMER_BIT, &pp->flags);
pp->weight = MVNETA_RX_POLL_WEIGHT;
pp->phy_node = phy_node;
pp->phy_interface = phy_mode;
pp->base = of_iomap(dn, 0);
if (pp->base == NULL) {
err = -ENOMEM;
goto err_free_irq;
}
pp->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pp->clk)) {
err = PTR_ERR(pp->clk);
goto err_unmap;
}
clk_prepare_enable(pp->clk);
pp->tx_done_timer.data = (unsigned long)dev;
pp->tx_ring_size = MVNETA_MAX_TXD;
pp->rx_ring_size = MVNETA_MAX_RXD;
pp->dev = dev;
SET_NETDEV_DEV(dev, &pdev->dev);
err = mvneta_init(pp, phy_addr);
if (err < 0) {
dev_err(&pdev->dev, "can't init eth hal\n");
goto err_clk;
}
mvneta_port_power_up(pp, phy_mode);
dram_target_info = mv_mbus_dram_info();
if (dram_target_info)
mvneta_conf_mbus_windows(pp, dram_target_info);
netif_napi_add(dev, &pp->napi, mvneta_poll, pp->weight);
dev->features = NETIF_F_SG | NETIF_F_IP_CSUM;
dev->hw_features |= NETIF_F_SG | NETIF_F_IP_CSUM;
dev->vlan_features |= NETIF_F_SG | NETIF_F_IP_CSUM;
dev->priv_flags |= IFF_UNICAST_FLT;
err = register_netdev(dev);
if (err < 0) {
dev_err(&pdev->dev, "failed to register\n");
goto err_deinit;
}
netdev_info(dev, "mac: %pM\n", dev->dev_addr);
platform_set_drvdata(pdev, pp->dev);
return 0;
err_deinit:
mvneta_deinit(pp);
err_clk:
clk_disable_unprepare(pp->clk);
err_unmap:
iounmap(pp->base);
err_free_irq:
irq_dispose_mapping(dev->irq);
err_free_netdev:
free_netdev(dev);
return err;
}
static int mvneta_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct mvneta_port *pp = netdev_priv(dev);
unregister_netdev(dev);
mvneta_deinit(pp);
clk_disable_unprepare(pp->clk);
iounmap(pp->base);
irq_dispose_mapping(dev->irq);
free_netdev(dev);
platform_set_drvdata(pdev, NULL);
return 0;
}
