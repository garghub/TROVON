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
dummy = mvreg_read(pp, MVNETA_RX_DISCARD_FRAME_COUNT);
dummy = mvreg_read(pp, MVNETA_OVERRUN_FRAME_COUNT);
}
struct rtnl_link_stats64 *mvneta_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
struct mvneta_port *pp = netdev_priv(dev);
unsigned int start;
int cpu;
for_each_possible_cpu(cpu) {
struct mvneta_pcpu_stats *cpu_stats;
u64 rx_packets;
u64 rx_bytes;
u64 tx_packets;
u64 tx_bytes;
cpu_stats = per_cpu_ptr(pp->stats, cpu);
do {
start = u64_stats_fetch_begin_irq(&cpu_stats->syncp);
rx_packets = cpu_stats->rx_packets;
rx_bytes = cpu_stats->rx_bytes;
tx_packets = cpu_stats->tx_packets;
tx_bytes = cpu_stats->tx_bytes;
} while (u64_stats_fetch_retry_irq(&cpu_stats->syncp, start));
stats->rx_packets += rx_packets;
stats->rx_bytes += rx_bytes;
stats->tx_packets += tx_packets;
stats->tx_bytes += tx_bytes;
}
stats->rx_errors = dev->stats.rx_errors;
stats->rx_dropped = dev->stats.rx_dropped;
stats->tx_dropped = dev->stats.tx_dropped;
return stats;
}
static int mvneta_rxq_desc_is_first_last(u32 status)
{
return (status & MVNETA_RXD_FIRST_LAST_DESC) ==
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
prefetch(rxq->descs + rxq->next_desc_to_proc);
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
static void mvneta_rxq_bm_enable(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq)
{
u32 val;
val = mvreg_read(pp, MVNETA_RXQ_CONFIG_REG(rxq->id));
val |= MVNETA_RXQ_HW_BUF_ALLOC;
mvreg_write(pp, MVNETA_RXQ_CONFIG_REG(rxq->id), val);
}
static void mvneta_rxq_long_pool_set(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq)
{
u32 val;
val = mvreg_read(pp, MVNETA_RXQ_CONFIG_REG(rxq->id));
val &= ~MVNETA_RXQ_LONG_POOL_ID_MASK;
val |= (pp->pool_long->id << MVNETA_RXQ_LONG_POOL_ID_SHIFT);
mvreg_write(pp, MVNETA_RXQ_CONFIG_REG(rxq->id), val);
}
static void mvneta_rxq_short_pool_set(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq)
{
u32 val;
val = mvreg_read(pp, MVNETA_RXQ_CONFIG_REG(rxq->id));
val &= ~MVNETA_RXQ_SHORT_POOL_ID_MASK;
val |= (pp->pool_short->id << MVNETA_RXQ_SHORT_POOL_ID_SHIFT);
mvreg_write(pp, MVNETA_RXQ_CONFIG_REG(rxq->id), val);
}
static inline void mvneta_bm_pool_bufsize_set(struct mvneta_port *pp,
int buf_size,
u8 pool_id)
{
u32 val;
if (!IS_ALIGNED(buf_size, 8)) {
dev_warn(pp->dev->dev.parent,
"illegal buf_size value %d, round to %d\n",
buf_size, ALIGN(buf_size, 8));
buf_size = ALIGN(buf_size, 8);
}
val = mvreg_read(pp, MVNETA_PORT_POOL_BUFFER_SZ_REG(pool_id));
val |= buf_size & MVNETA_PORT_POOL_BUFFER_SZ_MASK;
mvreg_write(pp, MVNETA_PORT_POOL_BUFFER_SZ_REG(pool_id), val);
}
static int mvneta_mbus_io_win_set(struct mvneta_port *pp, u32 base, u32 wsize,
u8 target, u8 attr)
{
u32 win_enable, win_protect;
int i;
win_enable = mvreg_read(pp, MVNETA_BASE_ADDR_ENABLE);
if (pp->bm_win_id < 0) {
for (i = 0; i < MVNETA_MAX_DECODE_WIN; i++) {
if (win_enable & (1 << i)) {
pp->bm_win_id = i;
break;
}
}
if (i == MVNETA_MAX_DECODE_WIN)
return -ENOMEM;
} else {
i = pp->bm_win_id;
}
mvreg_write(pp, MVNETA_WIN_BASE(i), 0);
mvreg_write(pp, MVNETA_WIN_SIZE(i), 0);
if (i < 4)
mvreg_write(pp, MVNETA_WIN_REMAP(i), 0);
mvreg_write(pp, MVNETA_WIN_BASE(i), (base & 0xffff0000) |
(attr << 8) | target);
mvreg_write(pp, MVNETA_WIN_SIZE(i), (wsize - 1) & 0xffff0000);
win_protect = mvreg_read(pp, MVNETA_ACCESS_PROTECT_ENABLE);
win_protect |= 3 << (2 * i);
mvreg_write(pp, MVNETA_ACCESS_PROTECT_ENABLE, win_protect);
win_enable &= ~(1 << i);
mvreg_write(pp, MVNETA_BASE_ADDR_ENABLE, win_enable);
return 0;
}
static int mvneta_bm_port_init(struct platform_device *pdev,
struct mvneta_port *pp)
{
struct device_node *dn = pdev->dev.of_node;
u32 long_pool_id, short_pool_id, wsize;
u8 target, attr;
int err;
err = mvebu_mbus_get_io_win_info(pp->bm_priv->bppi_phys_addr, &wsize,
&target, &attr);
if (err < 0)
return err;
pp->bm_win_id = -1;
err = mvneta_mbus_io_win_set(pp, pp->bm_priv->bppi_phys_addr, wsize,
target, attr);
if (err < 0) {
netdev_info(pp->dev, "fail to configure mbus window to BM\n");
return err;
}
if (of_property_read_u32(dn, "bm,pool-long", &long_pool_id)) {
netdev_info(pp->dev, "missing long pool id\n");
return -EINVAL;
}
pp->pool_long = mvneta_bm_pool_use(pp->bm_priv, long_pool_id,
MVNETA_BM_LONG, pp->id,
MVNETA_RX_PKT_SIZE(pp->dev->mtu));
if (!pp->pool_long) {
netdev_info(pp->dev, "fail to obtain long pool for port\n");
return -ENOMEM;
}
pp->pool_long->port_map |= 1 << pp->id;
mvneta_bm_pool_bufsize_set(pp, pp->pool_long->buf_size,
pp->pool_long->id);
if (of_property_read_u32(dn, "bm,pool-short", &short_pool_id))
short_pool_id = long_pool_id;
pp->pool_short = mvneta_bm_pool_use(pp->bm_priv, short_pool_id,
MVNETA_BM_SHORT, pp->id,
MVNETA_BM_SHORT_PKT_SIZE);
if (!pp->pool_short) {
netdev_info(pp->dev, "fail to obtain short pool for port\n");
mvneta_bm_pool_destroy(pp->bm_priv, pp->pool_long, 1 << pp->id);
return -ENOMEM;
}
if (short_pool_id != long_pool_id) {
pp->pool_short->port_map |= 1 << pp->id;
mvneta_bm_pool_bufsize_set(pp, pp->pool_short->buf_size,
pp->pool_short->id);
}
return 0;
}
static void mvneta_bm_update_mtu(struct mvneta_port *pp, int mtu)
{
struct mvneta_bm_pool *bm_pool = pp->pool_long;
struct hwbm_pool *hwbm_pool = &bm_pool->hwbm_pool;
int num;
mvneta_bm_bufs_free(pp->bm_priv, bm_pool, 1 << pp->id);
if (hwbm_pool->buf_num) {
WARN(1, "cannot free all buffers in pool %d\n",
bm_pool->id);
goto bm_mtu_err;
}
bm_pool->pkt_size = MVNETA_RX_PKT_SIZE(mtu);
bm_pool->buf_size = MVNETA_RX_BUF_SIZE(bm_pool->pkt_size);
hwbm_pool->frag_size = SKB_DATA_ALIGN(sizeof(struct skb_shared_info)) +
SKB_DATA_ALIGN(MVNETA_RX_BUF_SIZE(bm_pool->pkt_size));
num = hwbm_pool_add(hwbm_pool, hwbm_pool->size, GFP_ATOMIC);
if (num != hwbm_pool->size) {
WARN(1, "pool %d: %d of %d allocated\n",
bm_pool->id, num, hwbm_pool->size);
goto bm_mtu_err;
}
mvneta_bm_pool_bufsize_set(pp, bm_pool->buf_size, bm_pool->id);
return;
bm_mtu_err:
mvneta_bm_pool_destroy(pp->bm_priv, pp->pool_long, 1 << pp->id);
mvneta_bm_pool_destroy(pp->bm_priv, pp->pool_short, 1 << pp->id);
pp->bm_priv = NULL;
mvreg_write(pp, MVNETA_ACC_MODE, MVNETA_ACC_MODE_EXT1);
netdev_info(pp->dev, "fail to update MTU, fall back to software BM\n");
}
static void mvneta_port_up(struct mvneta_port *pp)
{
int queue;
u32 q_map;
q_map = 0;
for (queue = 0; queue < txq_number; queue++) {
struct mvneta_tx_queue *txq = &pp->txqs[queue];
if (txq->descs != NULL)
q_map |= (1 << queue);
}
mvreg_write(pp, MVNETA_TXQ_CMD, q_map);
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
"TIMEOUT for RX stopped ! rx_queue_cmd: 0x%08x\n",
val);
break;
}
mdelay(1);
val = mvreg_read(pp, MVNETA_RXQ_CMD);
} while (val & MVNETA_RXQ_ENABLE_MASK);
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
} while (val & MVNETA_TXQ_ENABLE_MASK);
count = 0;
do {
if (count++ >= MVNETA_TX_FIFO_EMPTY_TIMEOUT) {
netdev_warn(pp->dev,
"TX FIFO empty timeout status=0x%08x\n",
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
static void mvneta_set_autoneg(struct mvneta_port *pp, int enable)
{
u32 val;
if (enable) {
val = mvreg_read(pp, MVNETA_GMAC_AUTONEG_CONFIG);
val &= ~(MVNETA_GMAC_FORCE_LINK_PASS |
MVNETA_GMAC_FORCE_LINK_DOWN |
MVNETA_GMAC_AN_FLOW_CTRL_EN);
val |= MVNETA_GMAC_INBAND_AN_ENABLE |
MVNETA_GMAC_AN_SPEED_EN |
MVNETA_GMAC_AN_DUPLEX_EN;
mvreg_write(pp, MVNETA_GMAC_AUTONEG_CONFIG, val);
val = mvreg_read(pp, MVNETA_GMAC_CLOCK_DIVIDER);
val |= MVNETA_GMAC_1MS_CLOCK_ENABLE;
mvreg_write(pp, MVNETA_GMAC_CLOCK_DIVIDER, val);
val = mvreg_read(pp, MVNETA_GMAC_CTRL_2);
val |= MVNETA_GMAC2_INBAND_AN_ENABLE;
mvreg_write(pp, MVNETA_GMAC_CTRL_2, val);
} else {
val = mvreg_read(pp, MVNETA_GMAC_AUTONEG_CONFIG);
val &= ~(MVNETA_GMAC_INBAND_AN_ENABLE |
MVNETA_GMAC_AN_SPEED_EN |
MVNETA_GMAC_AN_DUPLEX_EN);
mvreg_write(pp, MVNETA_GMAC_AUTONEG_CONFIG, val);
val = mvreg_read(pp, MVNETA_GMAC_CLOCK_DIVIDER);
val &= ~MVNETA_GMAC_1MS_CLOCK_ENABLE;
mvreg_write(pp, MVNETA_GMAC_CLOCK_DIVIDER, val);
val = mvreg_read(pp, MVNETA_GMAC_CTRL_2);
val &= ~MVNETA_GMAC2_INBAND_AN_ENABLE;
mvreg_write(pp, MVNETA_GMAC_CTRL_2, val);
}
}
static void mvneta_percpu_unmask_interrupt(void *arg)
{
struct mvneta_port *pp = arg;
mvreg_write(pp, MVNETA_INTR_NEW_MASK,
MVNETA_RX_INTR_MASK_ALL |
MVNETA_TX_INTR_MASK_ALL |
MVNETA_MISCINTR_INTR_MASK);
}
static void mvneta_percpu_mask_interrupt(void *arg)
{
struct mvneta_port *pp = arg;
mvreg_write(pp, MVNETA_INTR_NEW_MASK, 0);
mvreg_write(pp, MVNETA_INTR_OLD_MASK, 0);
mvreg_write(pp, MVNETA_INTR_MISC_MASK, 0);
}
static void mvneta_percpu_clear_intr_cause(void *arg)
{
struct mvneta_port *pp = arg;
mvreg_write(pp, MVNETA_INTR_NEW_CAUSE, 0);
mvreg_write(pp, MVNETA_INTR_MISC_CAUSE, 0);
mvreg_write(pp, MVNETA_INTR_OLD_CAUSE, 0);
}
static void mvneta_defaults_set(struct mvneta_port *pp)
{
int cpu;
int queue;
u32 val;
int max_cpu = num_present_cpus();
on_each_cpu(mvneta_percpu_clear_intr_cause, pp, true);
on_each_cpu(mvneta_percpu_mask_interrupt, pp, true);
mvreg_write(pp, MVNETA_INTR_ENABLE, 0);
mvreg_write(pp, MVNETA_MBUS_RETRY, 0x20);
for_each_present_cpu(cpu) {
int rxq_map = 0, txq_map = 0;
int rxq, txq;
for (rxq = 0; rxq < rxq_number; rxq++)
if ((rxq % max_cpu) == cpu)
rxq_map |= MVNETA_CPU_RXQ_ACCESS(rxq);
for (txq = 0; txq < txq_number; txq++)
if ((txq % max_cpu) == cpu)
txq_map |= MVNETA_CPU_TXQ_ACCESS(txq);
if (txq_number == 1)
txq_map = (cpu == pp->rxq_def) ?
MVNETA_CPU_TXQ_ACCESS(1) : 0;
mvreg_write(pp, MVNETA_CPU_MAP(cpu), rxq_map | txq_map);
}
mvreg_write(pp, MVNETA_PORT_RX_RESET, MVNETA_PORT_RX_DMA_RESET);
mvreg_write(pp, MVNETA_PORT_TX_RESET, MVNETA_PORT_TX_DMA_RESET);
mvreg_write(pp, MVNETA_TXQ_CMD_1, 0);
for (queue = 0; queue < txq_number; queue++) {
mvreg_write(pp, MVETH_TXQ_TOKEN_COUNT_REG(queue), 0);
mvreg_write(pp, MVETH_TXQ_TOKEN_CFG_REG(queue), 0);
}
mvreg_write(pp, MVNETA_PORT_TX_RESET, 0);
mvreg_write(pp, MVNETA_PORT_RX_RESET, 0);
if (pp->bm_priv)
val = MVNETA_ACC_MODE_EXT2;
else
val = MVNETA_ACC_MODE_EXT1;
mvreg_write(pp, MVNETA_ACC_MODE, val);
if (pp->bm_priv)
mvreg_write(pp, MVNETA_BM_ADDRESS, pp->bm_priv->bppi_phys_addr);
val = MVNETA_PORT_CONFIG_DEFL_VALUE(pp->rxq_def);
mvreg_write(pp, MVNETA_PORT_CONFIG, val);
val = 0;
mvreg_write(pp, MVNETA_PORT_CONFIG_EXTEND, val);
mvreg_write(pp, MVNETA_RX_MIN_FRAME_SIZE, 64);
val = 0;
val |= MVNETA_TX_BRST_SZ_MASK(MVNETA_SDMA_BRST_SIZE_16);
val |= MVNETA_RX_BRST_SZ_MASK(MVNETA_SDMA_BRST_SIZE_16);
val |= MVNETA_RX_NO_DATA_SWAP | MVNETA_TX_NO_DATA_SWAP;
#if defined(__BIG_ENDIAN)
val |= MVNETA_DESC_SWAP;
#endif
mvreg_write(pp, MVNETA_SDMA_CONFIG, val);
val = mvreg_read(pp, MVNETA_UNIT_CONTROL);
val &= ~MVNETA_PHY_POLLING_ENABLE;
mvreg_write(pp, MVNETA_UNIT_CONTROL, val);
mvneta_set_autoneg(pp, pp->use_inband_status);
mvneta_set_ucast_table(pp, -1);
mvneta_set_special_mcast_table(pp, -1);
mvneta_set_other_mcast_table(pp, -1);
mvreg_write(pp, MVNETA_INTR_ENABLE,
(MVNETA_RXQ_INTR_ENABLE_ALL_MASK
| MVNETA_TXQ_INTR_ENABLE_ALL_MASK));
mvneta_mib_counters_clear(pp);
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
if (l3_proto == htons(ETH_P_IP))
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
if (!mvneta_rxq_desc_is_first_last(status)) {
netdev_err(pp->dev,
"bad rx status %08x (buffer oversize), size=%d\n",
status, rx_desc->data_size);
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
static void mvneta_rx_csum(struct mvneta_port *pp, u32 status,
struct sk_buff *skb)
{
if ((status & MVNETA_RXD_L3_IP4) &&
(status & MVNETA_RXD_L4_CSUM_OK)) {
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
return &pp->txqs[queue];
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
if (!IS_TSO_HEADER(txq, tx_desc->buf_phys_addr))
dma_unmap_single(pp->dev->dev.parent,
tx_desc->buf_phys_addr,
tx_desc->data_size, DMA_TO_DEVICE);
if (!skb)
continue;
dev_kfree_skb_any(skb);
}
}
static void mvneta_txq_done(struct mvneta_port *pp,
struct mvneta_tx_queue *txq)
{
struct netdev_queue *nq = netdev_get_tx_queue(pp->dev, txq->id);
int tx_done;
tx_done = mvneta_txq_sent_desc_proc(pp, txq);
if (!tx_done)
return;
mvneta_txq_bufs_free(pp, txq, tx_done);
txq->count -= tx_done;
if (netif_tx_queue_stopped(nq)) {
if (txq->count <= txq->tx_wake_threshold)
netif_tx_wake_queue(nq);
}
}
void *mvneta_frag_alloc(unsigned int frag_size)
{
if (likely(frag_size <= PAGE_SIZE))
return netdev_alloc_frag(frag_size);
else
return kmalloc(frag_size, GFP_ATOMIC);
}
void mvneta_frag_free(unsigned int frag_size, void *data)
{
if (likely(frag_size <= PAGE_SIZE))
skb_free_frag(data);
else
kfree(data);
}
static int mvneta_rx_refill(struct mvneta_port *pp,
struct mvneta_rx_desc *rx_desc)
{
dma_addr_t phys_addr;
void *data;
data = mvneta_frag_alloc(pp->frag_size);
if (!data)
return -ENOMEM;
phys_addr = dma_map_single(pp->dev->dev.parent, data,
MVNETA_RX_BUF_SIZE(pp->pkt_size),
DMA_FROM_DEVICE);
if (unlikely(dma_mapping_error(pp->dev->dev.parent, phys_addr))) {
mvneta_frag_free(pp->frag_size, data);
return -ENOMEM;
}
mvneta_rx_desc_fill(rx_desc, phys_addr, (u32)data);
return 0;
}
static u32 mvneta_skb_tx_csum(struct mvneta_port *pp, struct sk_buff *skb)
{
if (skb->ip_summed == CHECKSUM_PARTIAL) {
int ip_hdr_len = 0;
__be16 l3_proto = vlan_get_protocol(skb);
u8 l4_proto;
if (l3_proto == htons(ETH_P_IP)) {
struct iphdr *ip4h = ip_hdr(skb);
ip_hdr_len = ip4h->ihl;
l4_proto = ip4h->protocol;
} else if (l3_proto == htons(ETH_P_IPV6)) {
struct ipv6hdr *ip6h = ipv6_hdr(skb);
if (skb_network_header_len(skb) > 0)
ip_hdr_len = (skb_network_header_len(skb) >> 2);
l4_proto = ip6h->nexthdr;
} else
return MVNETA_TX_L4_CSUM_NOT;
return mvneta_txq_desc_csum(skb_network_offset(skb),
l3_proto, ip_hdr_len, l4_proto);
}
return MVNETA_TX_L4_CSUM_NOT;
}
static void mvneta_rxq_drop_pkts(struct mvneta_port *pp,
struct mvneta_rx_queue *rxq)
{
int rx_done, i;
rx_done = mvneta_rxq_busy_desc_num_get(pp, rxq);
if (rx_done)
mvneta_rxq_desc_num_update(pp, rxq, rx_done, rx_done);
if (pp->bm_priv) {
for (i = 0; i < rx_done; i++) {
struct mvneta_rx_desc *rx_desc =
mvneta_rxq_next_desc_get(rxq);
u8 pool_id = MVNETA_RX_GET_BM_POOL_ID(rx_desc);
struct mvneta_bm_pool *bm_pool;
bm_pool = &pp->bm_priv->bm_pools[pool_id];
mvneta_bm_pool_put_bp(pp->bm_priv, bm_pool,
rx_desc->buf_phys_addr);
}
return;
}
for (i = 0; i < rxq->size; i++) {
struct mvneta_rx_desc *rx_desc = rxq->descs + i;
void *data = (void *)rx_desc->buf_cookie;
dma_unmap_single(pp->dev->dev.parent, rx_desc->buf_phys_addr,
MVNETA_RX_BUF_SIZE(pp->pkt_size), DMA_FROM_DEVICE);
mvneta_frag_free(pp->frag_size, data);
}
}
static int mvneta_rx_swbm(struct mvneta_port *pp, int rx_todo,
struct mvneta_rx_queue *rxq)
{
struct mvneta_pcpu_port *port = this_cpu_ptr(pp->ports);
struct net_device *dev = pp->dev;
int rx_done;
u32 rcvd_pkts = 0;
u32 rcvd_bytes = 0;
rx_done = mvneta_rxq_busy_desc_num_get(pp, rxq);
if (rx_todo > rx_done)
rx_todo = rx_done;
rx_done = 0;
while (rx_done < rx_todo) {
struct mvneta_rx_desc *rx_desc = mvneta_rxq_next_desc_get(rxq);
struct sk_buff *skb;
unsigned char *data;
dma_addr_t phys_addr;
u32 rx_status, frag_size;
int rx_bytes, err;
rx_done++;
rx_status = rx_desc->status;
rx_bytes = rx_desc->data_size - (ETH_FCS_LEN + MVNETA_MH_SIZE);
data = (unsigned char *)rx_desc->buf_cookie;
phys_addr = rx_desc->buf_phys_addr;
if (!mvneta_rxq_desc_is_first_last(rx_status) ||
(rx_status & MVNETA_RXD_ERR_SUMMARY)) {
err_drop_frame:
dev->stats.rx_errors++;
mvneta_rx_error(pp, rx_desc);
continue;
}
if (rx_bytes <= rx_copybreak) {
skb = netdev_alloc_skb_ip_align(dev, rx_bytes);
if (unlikely(!skb))
goto err_drop_frame;
dma_sync_single_range_for_cpu(dev->dev.parent,
rx_desc->buf_phys_addr,
MVNETA_MH_SIZE + NET_SKB_PAD,
rx_bytes,
DMA_FROM_DEVICE);
memcpy(skb_put(skb, rx_bytes),
data + MVNETA_MH_SIZE + NET_SKB_PAD,
rx_bytes);
skb->protocol = eth_type_trans(skb, dev);
mvneta_rx_csum(pp, rx_status, skb);
napi_gro_receive(&port->napi, skb);
rcvd_pkts++;
rcvd_bytes += rx_bytes;
continue;
}
err = mvneta_rx_refill(pp, rx_desc);
if (err) {
netdev_err(dev, "Linux processing - Can't refill\n");
rxq->missed++;
goto err_drop_frame;
}
frag_size = pp->frag_size;
skb = build_skb(data, frag_size > PAGE_SIZE ? 0 : frag_size);
dma_unmap_single(dev->dev.parent, phys_addr,
MVNETA_RX_BUF_SIZE(pp->pkt_size),
DMA_FROM_DEVICE);
if (!skb)
goto err_drop_frame;
rcvd_pkts++;
rcvd_bytes += rx_bytes;
skb_reserve(skb, MVNETA_MH_SIZE + NET_SKB_PAD);
skb_put(skb, rx_bytes);
skb->protocol = eth_type_trans(skb, dev);
mvneta_rx_csum(pp, rx_status, skb);
napi_gro_receive(&port->napi, skb);
}
if (rcvd_pkts) {
struct mvneta_pcpu_stats *stats = this_cpu_ptr(pp->stats);
u64_stats_update_begin(&stats->syncp);
stats->rx_packets += rcvd_pkts;
stats->rx_bytes += rcvd_bytes;
u64_stats_update_end(&stats->syncp);
}
mvneta_rxq_desc_num_update(pp, rxq, rx_done, rx_done);
return rx_done;
}
static int mvneta_rx_hwbm(struct mvneta_port *pp, int rx_todo,
struct mvneta_rx_queue *rxq)
{
struct mvneta_pcpu_port *port = this_cpu_ptr(pp->ports);
struct net_device *dev = pp->dev;
int rx_done;
u32 rcvd_pkts = 0;
u32 rcvd_bytes = 0;
rx_done = mvneta_rxq_busy_desc_num_get(pp, rxq);
if (rx_todo > rx_done)
rx_todo = rx_done;
rx_done = 0;
while (rx_done < rx_todo) {
struct mvneta_rx_desc *rx_desc = mvneta_rxq_next_desc_get(rxq);
struct mvneta_bm_pool *bm_pool = NULL;
struct sk_buff *skb;
unsigned char *data;
dma_addr_t phys_addr;
u32 rx_status, frag_size;
int rx_bytes, err;
u8 pool_id;
rx_done++;
rx_status = rx_desc->status;
rx_bytes = rx_desc->data_size - (ETH_FCS_LEN + MVNETA_MH_SIZE);
data = (unsigned char *)rx_desc->buf_cookie;
phys_addr = rx_desc->buf_phys_addr;
pool_id = MVNETA_RX_GET_BM_POOL_ID(rx_desc);
bm_pool = &pp->bm_priv->bm_pools[pool_id];
if (!mvneta_rxq_desc_is_first_last(rx_status) ||
(rx_status & MVNETA_RXD_ERR_SUMMARY)) {
err_drop_frame_ret_pool:
mvneta_bm_pool_put_bp(pp->bm_priv, bm_pool,
rx_desc->buf_phys_addr);
err_drop_frame:
dev->stats.rx_errors++;
mvneta_rx_error(pp, rx_desc);
continue;
}
if (rx_bytes <= rx_copybreak) {
skb = netdev_alloc_skb_ip_align(dev, rx_bytes);
if (unlikely(!skb))
goto err_drop_frame_ret_pool;
dma_sync_single_range_for_cpu(dev->dev.parent,
rx_desc->buf_phys_addr,
MVNETA_MH_SIZE + NET_SKB_PAD,
rx_bytes,
DMA_FROM_DEVICE);
memcpy(skb_put(skb, rx_bytes),
data + MVNETA_MH_SIZE + NET_SKB_PAD,
rx_bytes);
skb->protocol = eth_type_trans(skb, dev);
mvneta_rx_csum(pp, rx_status, skb);
napi_gro_receive(&port->napi, skb);
rcvd_pkts++;
rcvd_bytes += rx_bytes;
mvneta_bm_pool_put_bp(pp->bm_priv, bm_pool,
rx_desc->buf_phys_addr);
continue;
}
err = hwbm_pool_refill(&bm_pool->hwbm_pool, GFP_ATOMIC);
if (err) {
netdev_err(dev, "Linux processing - Can't refill\n");
rxq->missed++;
goto err_drop_frame_ret_pool;
}
frag_size = bm_pool->hwbm_pool.frag_size;
skb = build_skb(data, frag_size > PAGE_SIZE ? 0 : frag_size);
dma_unmap_single(&pp->bm_priv->pdev->dev, phys_addr,
bm_pool->buf_size, DMA_FROM_DEVICE);
if (!skb)
goto err_drop_frame;
rcvd_pkts++;
rcvd_bytes += rx_bytes;
skb_reserve(skb, MVNETA_MH_SIZE + NET_SKB_PAD);
skb_put(skb, rx_bytes);
skb->protocol = eth_type_trans(skb, dev);
mvneta_rx_csum(pp, rx_status, skb);
napi_gro_receive(&port->napi, skb);
}
if (rcvd_pkts) {
struct mvneta_pcpu_stats *stats = this_cpu_ptr(pp->stats);
u64_stats_update_begin(&stats->syncp);
stats->rx_packets += rcvd_pkts;
stats->rx_bytes += rcvd_bytes;
u64_stats_update_end(&stats->syncp);
}
mvneta_rxq_desc_num_update(pp, rxq, rx_done, rx_done);
return rx_done;
}
static inline void
mvneta_tso_put_hdr(struct sk_buff *skb,
struct mvneta_port *pp, struct mvneta_tx_queue *txq)
{
struct mvneta_tx_desc *tx_desc;
int hdr_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
txq->tx_skb[txq->txq_put_index] = NULL;
tx_desc = mvneta_txq_next_desc_get(txq);
tx_desc->data_size = hdr_len;
tx_desc->command = mvneta_skb_tx_csum(pp, skb);
tx_desc->command |= MVNETA_TXD_F_DESC;
tx_desc->buf_phys_addr = txq->tso_hdrs_phys +
txq->txq_put_index * TSO_HEADER_SIZE;
mvneta_txq_inc_put(txq);
}
static inline int
mvneta_tso_put_data(struct net_device *dev, struct mvneta_tx_queue *txq,
struct sk_buff *skb, char *data, int size,
bool last_tcp, bool is_last)
{
struct mvneta_tx_desc *tx_desc;
tx_desc = mvneta_txq_next_desc_get(txq);
tx_desc->data_size = size;
tx_desc->buf_phys_addr = dma_map_single(dev->dev.parent, data,
size, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(dev->dev.parent,
tx_desc->buf_phys_addr))) {
mvneta_txq_desc_put(txq);
return -ENOMEM;
}
tx_desc->command = 0;
txq->tx_skb[txq->txq_put_index] = NULL;
if (last_tcp) {
tx_desc->command = MVNETA_TXD_L_DESC;
if (is_last)
txq->tx_skb[txq->txq_put_index] = skb;
}
mvneta_txq_inc_put(txq);
return 0;
}
static int mvneta_tx_tso(struct sk_buff *skb, struct net_device *dev,
struct mvneta_tx_queue *txq)
{
int total_len, data_left;
int desc_count = 0;
struct mvneta_port *pp = netdev_priv(dev);
struct tso_t tso;
int hdr_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
int i;
if ((txq->count + tso_count_descs(skb)) >= txq->size)
return 0;
if (skb_headlen(skb) < (skb_transport_offset(skb) + tcp_hdrlen(skb))) {
pr_info("*** Is this even possible???!?!?\n");
return 0;
}
tso_start(skb, &tso);
total_len = skb->len - hdr_len;
while (total_len > 0) {
char *hdr;
data_left = min_t(int, skb_shinfo(skb)->gso_size, total_len);
total_len -= data_left;
desc_count++;
hdr = txq->tso_hdrs + txq->txq_put_index * TSO_HEADER_SIZE;
tso_build_hdr(skb, hdr, &tso, data_left, total_len == 0);
mvneta_tso_put_hdr(skb, pp, txq);
while (data_left > 0) {
int size;
desc_count++;
size = min_t(int, tso.size, data_left);
if (mvneta_tso_put_data(dev, txq, skb,
tso.data, size,
size == data_left,
total_len == 0))
goto err_release;
data_left -= size;
tso_build_data(skb, &tso, size);
}
}
return desc_count;
err_release:
for (i = desc_count - 1; i >= 0; i--) {
struct mvneta_tx_desc *tx_desc = txq->descs + i;
if (!IS_TSO_HEADER(txq, tx_desc->buf_phys_addr))
dma_unmap_single(pp->dev->dev.parent,
tx_desc->buf_phys_addr,
tx_desc->data_size,
DMA_TO_DEVICE);
mvneta_txq_desc_put(txq);
}
return 0;
}
static int mvneta_tx_frag_process(struct mvneta_port *pp, struct sk_buff *skb,
struct mvneta_tx_queue *txq)
{
struct mvneta_tx_desc *tx_desc;
int i, nr_frags = skb_shinfo(skb)->nr_frags;
for (i = 0; i < nr_frags; i++) {
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
if (i == nr_frags - 1) {
tx_desc->command = MVNETA_TXD_L_DESC | MVNETA_TXD_Z_PAD;
txq->tx_skb[txq->txq_put_index] = skb;
} else {
tx_desc->command = 0;
txq->tx_skb[txq->txq_put_index] = NULL;
}
mvneta_txq_inc_put(txq);
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
int len = skb->len;
int frags = 0;
u32 tx_cmd;
if (!netif_running(dev))
goto out;
if (skb_is_gso(skb)) {
frags = mvneta_tx_tso(skb, dev, txq);
goto out;
}
frags = skb_shinfo(skb)->nr_frags + 1;
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
out:
if (frags > 0) {
struct mvneta_pcpu_stats *stats = this_cpu_ptr(pp->stats);
struct netdev_queue *nq = netdev_get_tx_queue(dev, txq_id);
txq->count += frags;
mvneta_txq_pend_desc_add(pp, txq, frags);
if (txq->count >= txq->tx_stop_threshold)
netif_tx_stop_queue(nq);
u64_stats_update_begin(&stats->syncp);
stats->tx_packets++;
stats->tx_bytes += len;
u64_stats_update_end(&stats->syncp);
} else {
dev->stats.tx_dropped++;
dev_kfree_skb_any(skb);
}
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
static void mvneta_tx_done_gbe(struct mvneta_port *pp, u32 cause_tx_done)
{
struct mvneta_tx_queue *txq;
struct netdev_queue *nq;
while (cause_tx_done) {
txq = mvneta_tx_done_policy(pp, cause_tx_done);
nq = netdev_get_tx_queue(pp->dev, txq->id);
__netif_tx_lock(nq, smp_processor_id());
if (txq->count)
mvneta_txq_done(pp, txq);
__netif_tx_unlock(nq);
cause_tx_done &= ~((1 << txq->id));
}
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
mvneta_set_ucast_table(pp, pp->rxq_def);
mvneta_set_special_mcast_table(pp, pp->rxq_def);
mvneta_set_other_mcast_table(pp, pp->rxq_def);
} else {
mvneta_rx_unicast_promisc_set(pp, 0);
mvneta_set_ucast_table(pp, -1);
mvneta_mac_addr_set(pp, dev->dev_addr, pp->rxq_def);
if (dev->flags & IFF_ALLMULTI) {
mvneta_set_special_mcast_table(pp, pp->rxq_def);
mvneta_set_other_mcast_table(pp, pp->rxq_def);
} else {
mvneta_set_special_mcast_table(pp, -1);
mvneta_set_other_mcast_table(pp, -1);
if (!netdev_mc_empty(dev)) {
netdev_for_each_mc_addr(ha, dev) {
mvneta_mcast_addr_set(pp, ha->addr,
pp->rxq_def);
}
}
}
}
}
static irqreturn_t mvneta_isr(int irq, void *dev_id)
{
struct mvneta_pcpu_port *port = (struct mvneta_pcpu_port *)dev_id;
disable_percpu_irq(port->pp->dev->irq);
napi_schedule(&port->napi);
return IRQ_HANDLED;
}
static int mvneta_fixed_link_update(struct mvneta_port *pp,
struct phy_device *phy)
{
struct fixed_phy_status status;
struct fixed_phy_status changed = {};
u32 gmac_stat = mvreg_read(pp, MVNETA_GMAC_STATUS);
status.link = !!(gmac_stat & MVNETA_GMAC_LINK_UP);
if (gmac_stat & MVNETA_GMAC_SPEED_1000)
status.speed = SPEED_1000;
else if (gmac_stat & MVNETA_GMAC_SPEED_100)
status.speed = SPEED_100;
else
status.speed = SPEED_10;
status.duplex = !!(gmac_stat & MVNETA_GMAC_FULL_DUPLEX);
changed.link = 1;
changed.speed = 1;
changed.duplex = 1;
fixed_phy_update_state(phy, &status, &changed);
return 0;
}
static int mvneta_poll(struct napi_struct *napi, int budget)
{
int rx_done = 0;
u32 cause_rx_tx;
int rx_queue;
struct mvneta_port *pp = netdev_priv(napi->dev);
struct mvneta_pcpu_port *port = this_cpu_ptr(pp->ports);
if (!netif_running(pp->dev)) {
napi_complete(&port->napi);
return rx_done;
}
cause_rx_tx = mvreg_read(pp, MVNETA_INTR_NEW_CAUSE);
if (cause_rx_tx & MVNETA_MISCINTR_INTR_MASK) {
u32 cause_misc = mvreg_read(pp, MVNETA_INTR_MISC_CAUSE);
mvreg_write(pp, MVNETA_INTR_MISC_CAUSE, 0);
if (pp->use_inband_status && (cause_misc &
(MVNETA_CAUSE_PHY_STATUS_CHANGE |
MVNETA_CAUSE_LINK_CHANGE |
MVNETA_CAUSE_PSC_SYNC_CHANGE))) {
mvneta_fixed_link_update(pp, pp->phy_dev);
}
}
if (cause_rx_tx & MVNETA_TX_INTR_MASK_ALL) {
mvneta_tx_done_gbe(pp, (cause_rx_tx & MVNETA_TX_INTR_MASK_ALL));
cause_rx_tx &= ~MVNETA_TX_INTR_MASK_ALL;
}
rx_queue = fls(((cause_rx_tx >> 8) & 0xff));
cause_rx_tx |= port->cause_rx_tx;
if (rx_queue) {
rx_queue = rx_queue - 1;
if (pp->bm_priv)
rx_done = mvneta_rx_hwbm(pp, budget, &pp->rxqs[rx_queue]);
else
rx_done = mvneta_rx_swbm(pp, budget, &pp->rxqs[rx_queue]);
}
budget -= rx_done;
if (budget > 0) {
cause_rx_tx = 0;
napi_complete(&port->napi);
enable_percpu_irq(pp->dev->irq, 0);
}
port->cause_rx_tx = cause_rx_tx;
return rx_done;
}
static int mvneta_rxq_fill(struct mvneta_port *pp, struct mvneta_rx_queue *rxq,
int num)
{
int i;
for (i = 0; i < num; i++) {
memset(rxq->descs + i, 0, sizeof(struct mvneta_rx_desc));
if (mvneta_rx_refill(pp, rxq->descs + i) != 0) {
netdev_err(pp->dev, "%s:rxq %d, %d of %d buffs filled\n",
__func__, rxq->id, i, num);
break;
}
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
rxq->last_desc = rxq->size - 1;
mvreg_write(pp, MVNETA_RXQ_BASE_ADDR_REG(rxq->id), rxq->descs_phys);
mvreg_write(pp, MVNETA_RXQ_SIZE_REG(rxq->id), rxq->size);
mvneta_rxq_offset_set(pp, rxq, NET_SKB_PAD);
mvneta_rx_pkts_coal_set(pp, rxq, rxq->pkts_coal);
mvneta_rx_time_coal_set(pp, rxq, rxq->time_coal);
if (!pp->bm_priv) {
mvneta_rxq_buf_size_set(pp, rxq,
MVNETA_RX_BUF_SIZE(pp->pkt_size));
mvneta_rxq_bm_disable(pp, rxq);
} else {
mvneta_rxq_bm_enable(pp, rxq);
mvneta_rxq_long_pool_set(pp, rxq);
mvneta_rxq_short_pool_set(pp, rxq);
}
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
int cpu;
txq->size = pp->tx_ring_size;
txq->tx_stop_threshold = txq->size - MVNETA_MAX_SKB_DESCS;
txq->tx_wake_threshold = txq->tx_stop_threshold / 2;
txq->descs = dma_alloc_coherent(pp->dev->dev.parent,
txq->size * MVNETA_DESC_ALIGNED_SIZE,
&txq->descs_phys, GFP_KERNEL);
if (txq->descs == NULL)
return -ENOMEM;
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
txq->tso_hdrs = dma_alloc_coherent(pp->dev->dev.parent,
txq->size * TSO_HEADER_SIZE,
&txq->tso_hdrs_phys, GFP_KERNEL);
if (txq->tso_hdrs == NULL) {
kfree(txq->tx_skb);
dma_free_coherent(pp->dev->dev.parent,
txq->size * MVNETA_DESC_ALIGNED_SIZE,
txq->descs, txq->descs_phys);
return -ENOMEM;
}
mvneta_tx_done_pkts_coal_set(pp, txq, txq->done_pkts_coal);
if (txq_number > 1)
cpu = txq->id % num_present_cpus();
else
cpu = pp->rxq_def % num_present_cpus();
cpumask_set_cpu(cpu, &txq->affinity_mask);
netif_set_xps_queue(pp->dev, &txq->affinity_mask, txq->id);
return 0;
}
static void mvneta_txq_deinit(struct mvneta_port *pp,
struct mvneta_tx_queue *txq)
{
kfree(txq->tx_skb);
if (txq->tso_hdrs)
dma_free_coherent(pp->dev->dev.parent,
txq->size * TSO_HEADER_SIZE,
txq->tso_hdrs, txq->tso_hdrs_phys);
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
for (queue = 0; queue < txq_number; queue++)
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
int cpu;
mvneta_max_rx_size_set(pp, pp->pkt_size);
mvneta_txq_max_tx_size_set(pp, pp->pkt_size);
mvneta_port_enable(pp);
for_each_online_cpu(cpu) {
struct mvneta_pcpu_port *port = per_cpu_ptr(pp->ports, cpu);
napi_enable(&port->napi);
}
on_each_cpu(mvneta_percpu_unmask_interrupt, pp, true);
mvreg_write(pp, MVNETA_INTR_MISC_MASK,
MVNETA_CAUSE_PHY_STATUS_CHANGE |
MVNETA_CAUSE_LINK_CHANGE |
MVNETA_CAUSE_PSC_SYNC_CHANGE);
phy_start(pp->phy_dev);
netif_tx_start_all_queues(pp->dev);
}
static void mvneta_stop_dev(struct mvneta_port *pp)
{
unsigned int cpu;
phy_stop(pp->phy_dev);
for_each_online_cpu(cpu) {
struct mvneta_pcpu_port *port = per_cpu_ptr(pp->ports, cpu);
napi_disable(&port->napi);
}
netif_carrier_off(pp->dev);
mvneta_port_down(pp);
netif_tx_stop_all_queues(pp->dev);
mvneta_port_disable(pp);
on_each_cpu(mvneta_percpu_clear_intr_cause, pp, true);
on_each_cpu(mvneta_percpu_mask_interrupt, pp, true);
mvneta_tx_reset(pp);
mvneta_rx_reset(pp);
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
static void mvneta_percpu_enable(void *arg)
{
struct mvneta_port *pp = arg;
enable_percpu_irq(pp->dev->irq, IRQ_TYPE_NONE);
}
static void mvneta_percpu_disable(void *arg)
{
struct mvneta_port *pp = arg;
disable_percpu_irq(pp->dev->irq);
}
static int mvneta_change_mtu(struct net_device *dev, int mtu)
{
struct mvneta_port *pp = netdev_priv(dev);
int ret;
mtu = mvneta_check_mtu_valid(dev, mtu);
if (mtu < 0)
return -EINVAL;
dev->mtu = mtu;
if (!netif_running(dev)) {
if (pp->bm_priv)
mvneta_bm_update_mtu(pp, mtu);
netdev_update_features(dev);
return 0;
}
mvneta_stop_dev(pp);
on_each_cpu(mvneta_percpu_disable, pp, true);
mvneta_cleanup_txqs(pp);
mvneta_cleanup_rxqs(pp);
if (pp->bm_priv)
mvneta_bm_update_mtu(pp, mtu);
pp->pkt_size = MVNETA_RX_PKT_SIZE(dev->mtu);
pp->frag_size = SKB_DATA_ALIGN(MVNETA_RX_BUF_SIZE(pp->pkt_size)) +
SKB_DATA_ALIGN(sizeof(struct skb_shared_info));
ret = mvneta_setup_rxqs(pp);
if (ret) {
netdev_err(dev, "unable to setup rxqs after MTU change\n");
return ret;
}
ret = mvneta_setup_txqs(pp);
if (ret) {
netdev_err(dev, "unable to setup txqs after MTU change\n");
return ret;
}
on_each_cpu(mvneta_percpu_enable, pp, true);
mvneta_start_dev(pp);
mvneta_port_up(pp);
netdev_update_features(dev);
return 0;
}
static netdev_features_t mvneta_fix_features(struct net_device *dev,
netdev_features_t features)
{
struct mvneta_port *pp = netdev_priv(dev);
if (pp->tx_csum_limit && dev->mtu > pp->tx_csum_limit) {
features &= ~(NETIF_F_IP_CSUM | NETIF_F_TSO);
netdev_info(dev,
"Disable IP checksum for MTU greater than %dB\n",
pp->tx_csum_limit);
}
return features;
}
static void mvneta_get_mac_addr(struct mvneta_port *pp, unsigned char *addr)
{
u32 mac_addr_l, mac_addr_h;
mac_addr_l = mvreg_read(pp, MVNETA_MAC_ADDR_LOW);
mac_addr_h = mvreg_read(pp, MVNETA_MAC_ADDR_HIGH);
addr[0] = (mac_addr_h >> 24) & 0xFF;
addr[1] = (mac_addr_h >> 16) & 0xFF;
addr[2] = (mac_addr_h >> 8) & 0xFF;
addr[3] = mac_addr_h & 0xFF;
addr[4] = (mac_addr_l >> 8) & 0xFF;
addr[5] = mac_addr_l & 0xFF;
}
static int mvneta_set_mac_addr(struct net_device *dev, void *addr)
{
struct mvneta_port *pp = netdev_priv(dev);
struct sockaddr *sockaddr = addr;
int ret;
ret = eth_prepare_mac_addr_change(dev, addr);
if (ret < 0)
return ret;
mvneta_mac_addr_set(pp, dev->dev_addr, -1);
mvneta_mac_addr_set(pp, sockaddr->sa_data, pp->rxq_def);
eth_commit_mac_addr_change(dev, addr);
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
else if (phydev->speed == SPEED_100)
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
if (!pp->use_inband_status) {
u32 val = mvreg_read(pp,
MVNETA_GMAC_AUTONEG_CONFIG);
val &= ~MVNETA_GMAC_FORCE_LINK_DOWN;
val |= MVNETA_GMAC_FORCE_LINK_PASS;
mvreg_write(pp, MVNETA_GMAC_AUTONEG_CONFIG,
val);
}
mvneta_port_up(pp);
} else {
if (!pp->use_inband_status) {
u32 val = mvreg_read(pp,
MVNETA_GMAC_AUTONEG_CONFIG);
val &= ~MVNETA_GMAC_FORCE_LINK_PASS;
val |= MVNETA_GMAC_FORCE_LINK_DOWN;
mvreg_write(pp, MVNETA_GMAC_AUTONEG_CONFIG,
val);
}
mvneta_port_down(pp);
}
phy_print_status(phydev);
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
static void mvneta_percpu_elect(struct mvneta_port *pp)
{
int elected_cpu = 0, max_cpu, cpu, i = 0;
if (cpu_online(pp->rxq_def))
elected_cpu = pp->rxq_def;
max_cpu = num_present_cpus();
for_each_online_cpu(cpu) {
int rxq_map = 0, txq_map = 0;
int rxq;
for (rxq = 0; rxq < rxq_number; rxq++)
if ((rxq % max_cpu) == cpu)
rxq_map |= MVNETA_CPU_RXQ_ACCESS(rxq);
if (cpu == elected_cpu)
rxq_map |= MVNETA_CPU_RXQ_ACCESS(pp->rxq_def);
if (txq_number == 1)
txq_map = (cpu == elected_cpu) ?
MVNETA_CPU_TXQ_ACCESS(1) : 0;
else
txq_map = mvreg_read(pp, MVNETA_CPU_MAP(cpu)) &
MVNETA_CPU_TXQ_ACCESS_ALL_MASK;
mvreg_write(pp, MVNETA_CPU_MAP(cpu), rxq_map | txq_map);
smp_call_function_single(cpu, mvneta_percpu_unmask_interrupt,
pp, true);
i++;
}
}
static int mvneta_percpu_notifier(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
struct mvneta_port *pp = container_of(nfb, struct mvneta_port,
cpu_notifier);
int cpu = (unsigned long)hcpu, other_cpu;
struct mvneta_pcpu_port *port = per_cpu_ptr(pp->ports, cpu);
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
case CPU_DOWN_FAILED:
case CPU_DOWN_FAILED_FROZEN:
spin_lock(&pp->lock);
if (pp->is_stopped) {
spin_unlock(&pp->lock);
break;
}
netif_tx_stop_all_queues(pp->dev);
for_each_online_cpu(other_cpu) {
if (other_cpu != cpu) {
struct mvneta_pcpu_port *other_port =
per_cpu_ptr(pp->ports, other_cpu);
napi_synchronize(&other_port->napi);
}
}
on_each_cpu(mvneta_percpu_mask_interrupt, pp, true);
napi_enable(&port->napi);
mvneta_percpu_enable(pp);
mvneta_percpu_elect(pp);
on_each_cpu(mvneta_percpu_unmask_interrupt, pp, true);
mvreg_write(pp, MVNETA_INTR_MISC_MASK,
MVNETA_CAUSE_PHY_STATUS_CHANGE |
MVNETA_CAUSE_LINK_CHANGE |
MVNETA_CAUSE_PSC_SYNC_CHANGE);
netif_tx_start_all_queues(pp->dev);
spin_unlock(&pp->lock);
break;
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
netif_tx_stop_all_queues(pp->dev);
spin_lock(&pp->lock);
on_each_cpu(mvneta_percpu_mask_interrupt, pp, true);
spin_unlock(&pp->lock);
napi_synchronize(&port->napi);
napi_disable(&port->napi);
mvneta_percpu_disable(pp);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
spin_lock(&pp->lock);
mvneta_percpu_elect(pp);
spin_unlock(&pp->lock);
on_each_cpu(mvneta_percpu_unmask_interrupt, pp, true);
mvreg_write(pp, MVNETA_INTR_MISC_MASK,
MVNETA_CAUSE_PHY_STATUS_CHANGE |
MVNETA_CAUSE_LINK_CHANGE |
MVNETA_CAUSE_PSC_SYNC_CHANGE);
netif_tx_start_all_queues(pp->dev);
break;
}
return NOTIFY_OK;
}
static int mvneta_open(struct net_device *dev)
{
struct mvneta_port *pp = netdev_priv(dev);
int ret;
pp->pkt_size = MVNETA_RX_PKT_SIZE(pp->dev->mtu);
pp->frag_size = SKB_DATA_ALIGN(MVNETA_RX_BUF_SIZE(pp->pkt_size)) +
SKB_DATA_ALIGN(sizeof(struct skb_shared_info));
ret = mvneta_setup_rxqs(pp);
if (ret)
return ret;
ret = mvneta_setup_txqs(pp);
if (ret)
goto err_cleanup_rxqs;
ret = request_percpu_irq(pp->dev->irq, mvneta_isr,
MVNETA_DRIVER_NAME, pp->ports);
if (ret) {
netdev_err(pp->dev, "cannot request irq %d\n", pp->dev->irq);
goto err_cleanup_txqs;
}
on_each_cpu(mvneta_percpu_enable, pp, true);
pp->is_stopped = false;
register_cpu_notifier(&pp->cpu_notifier);
netif_carrier_off(pp->dev);
ret = mvneta_mdio_probe(pp);
if (ret < 0) {
netdev_err(dev, "cannot probe MDIO bus\n");
goto err_free_irq;
}
mvneta_start_dev(pp);
return 0;
err_free_irq:
unregister_cpu_notifier(&pp->cpu_notifier);
on_each_cpu(mvneta_percpu_disable, pp, true);
free_percpu_irq(pp->dev->irq, pp->ports);
err_cleanup_txqs:
mvneta_cleanup_txqs(pp);
err_cleanup_rxqs:
mvneta_cleanup_rxqs(pp);
return ret;
}
static int mvneta_stop(struct net_device *dev)
{
struct mvneta_port *pp = netdev_priv(dev);
spin_lock(&pp->lock);
pp->is_stopped = true;
spin_unlock(&pp->lock);
mvneta_stop_dev(pp);
mvneta_mdio_remove(pp);
unregister_cpu_notifier(&pp->cpu_notifier);
on_each_cpu(mvneta_percpu_disable, pp, true);
free_percpu_irq(dev->irq, pp->ports);
mvneta_cleanup_rxqs(pp);
mvneta_cleanup_txqs(pp);
return 0;
}
static int mvneta_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct mvneta_port *pp = netdev_priv(dev);
if (!pp->phy_dev)
return -ENOTSUPP;
return phy_mii_ioctl(pp->phy_dev, ifr, cmd);
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
struct phy_device *phydev = pp->phy_dev;
if (!phydev)
return -ENODEV;
if ((cmd->autoneg == AUTONEG_ENABLE) != pp->use_inband_status) {
u32 val;
mvneta_set_autoneg(pp, cmd->autoneg == AUTONEG_ENABLE);
if (cmd->autoneg == AUTONEG_DISABLE) {
val = mvreg_read(pp, MVNETA_GMAC_AUTONEG_CONFIG);
val &= ~(MVNETA_GMAC_CONFIG_MII_SPEED |
MVNETA_GMAC_CONFIG_GMII_SPEED |
MVNETA_GMAC_CONFIG_FULL_DUPLEX);
if (phydev->duplex)
val |= MVNETA_GMAC_CONFIG_FULL_DUPLEX;
if (phydev->speed == SPEED_1000)
val |= MVNETA_GMAC_CONFIG_GMII_SPEED;
else if (phydev->speed == SPEED_100)
val |= MVNETA_GMAC_CONFIG_MII_SPEED;
mvreg_write(pp, MVNETA_GMAC_AUTONEG_CONFIG, val);
}
pp->use_inband_status = (cmd->autoneg == AUTONEG_ENABLE);
netdev_info(pp->dev, "autoneg status set to %i\n",
pp->use_inband_status);
if (netif_running(dev)) {
mvneta_port_down(pp);
mvneta_port_up(pp);
}
}
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
pp->tx_ring_size = clamp_t(u16, ring->tx_pending,
MVNETA_MAX_SKB_DESCS * 2, MVNETA_MAX_TXD);
if (pp->tx_ring_size != ring->tx_pending)
netdev_warn(dev, "TX queue size set to %u (requested %u)\n",
pp->tx_ring_size, ring->tx_pending);
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
static void mvneta_ethtool_get_strings(struct net_device *netdev, u32 sset,
u8 *data)
{
if (sset == ETH_SS_STATS) {
int i;
for (i = 0; i < ARRAY_SIZE(mvneta_statistics); i++)
memcpy(data + i * ETH_GSTRING_LEN,
mvneta_statistics[i].name, ETH_GSTRING_LEN);
}
}
static void mvneta_ethtool_update_stats(struct mvneta_port *pp)
{
const struct mvneta_statistic *s;
void __iomem *base = pp->base;
u32 high, low, val;
u64 val64;
int i;
for (i = 0, s = mvneta_statistics;
s < mvneta_statistics + ARRAY_SIZE(mvneta_statistics);
s++, i++) {
switch (s->type) {
case T_REG_32:
val = readl_relaxed(base + s->offset);
pp->ethtool_stats[i] += val;
break;
case T_REG_64:
low = readl_relaxed(base + s->offset);
high = readl_relaxed(base + s->offset + 4);
val64 = (u64)high << 32 | low;
pp->ethtool_stats[i] += val64;
break;
}
}
}
static void mvneta_ethtool_get_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct mvneta_port *pp = netdev_priv(dev);
int i;
mvneta_ethtool_update_stats(pp);
for (i = 0; i < ARRAY_SIZE(mvneta_statistics); i++)
*data++ = pp->ethtool_stats[i];
}
static int mvneta_ethtool_get_sset_count(struct net_device *dev, int sset)
{
if (sset == ETH_SS_STATS)
return ARRAY_SIZE(mvneta_statistics);
return -EOPNOTSUPP;
}
static u32 mvneta_ethtool_get_rxfh_indir_size(struct net_device *dev)
{
return MVNETA_RSS_LU_TABLE_SIZE;
}
static int mvneta_ethtool_get_rxnfc(struct net_device *dev,
struct ethtool_rxnfc *info,
u32 *rules __always_unused)
{
switch (info->cmd) {
case ETHTOOL_GRXRINGS:
info->data = rxq_number;
return 0;
case ETHTOOL_GRXFH:
return -EOPNOTSUPP;
default:
return -EOPNOTSUPP;
}
}
static int mvneta_config_rss(struct mvneta_port *pp)
{
int cpu;
u32 val;
netif_tx_stop_all_queues(pp->dev);
on_each_cpu(mvneta_percpu_mask_interrupt, pp, true);
for_each_online_cpu(cpu) {
struct mvneta_pcpu_port *pcpu_port =
per_cpu_ptr(pp->ports, cpu);
napi_synchronize(&pcpu_port->napi);
napi_disable(&pcpu_port->napi);
}
pp->rxq_def = pp->indir[0];
mvneta_set_rx_mode(pp->dev);
val = MVNETA_PORT_CONFIG_DEFL_VALUE(pp->rxq_def);
mvreg_write(pp, MVNETA_PORT_CONFIG, val);
spin_lock(&pp->lock);
mvneta_percpu_elect(pp);
spin_unlock(&pp->lock);
for_each_online_cpu(cpu) {
struct mvneta_pcpu_port *pcpu_port =
per_cpu_ptr(pp->ports, cpu);
napi_enable(&pcpu_port->napi);
}
netif_tx_start_all_queues(pp->dev);
return 0;
}
static int mvneta_ethtool_set_rxfh(struct net_device *dev, const u32 *indir,
const u8 *key, const u8 hfunc)
{
struct mvneta_port *pp = netdev_priv(dev);
if (key ||
(hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP))
return -EOPNOTSUPP;
if (!indir)
return 0;
memcpy(pp->indir, indir, MVNETA_RSS_LU_TABLE_SIZE);
return mvneta_config_rss(pp);
}
static int mvneta_ethtool_get_rxfh(struct net_device *dev, u32 *indir, u8 *key,
u8 *hfunc)
{
struct mvneta_port *pp = netdev_priv(dev);
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
if (!indir)
return 0;
memcpy(indir, pp->indir, MVNETA_RSS_LU_TABLE_SIZE);
return 0;
}
static int mvneta_init(struct device *dev, struct mvneta_port *pp)
{
int queue;
mvneta_port_disable(pp);
mvneta_defaults_set(pp);
pp->txqs = devm_kcalloc(dev, txq_number, sizeof(struct mvneta_tx_queue),
GFP_KERNEL);
if (!pp->txqs)
return -ENOMEM;
for (queue = 0; queue < txq_number; queue++) {
struct mvneta_tx_queue *txq = &pp->txqs[queue];
txq->id = queue;
txq->size = pp->tx_ring_size;
txq->done_pkts_coal = MVNETA_TXDONE_COAL_PKTS;
}
pp->rxqs = devm_kcalloc(dev, rxq_number, sizeof(struct mvneta_rx_queue),
GFP_KERNEL);
if (!pp->rxqs)
return -ENOMEM;
for (queue = 0; queue < rxq_number; queue++) {
struct mvneta_rx_queue *rxq = &pp->rxqs[queue];
rxq->id = queue;
rxq->size = pp->rx_ring_size;
rxq->pkts_coal = MVNETA_RX_COAL_PKTS;
rxq->time_coal = MVNETA_RX_COAL_USEC;
}
return 0;
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
mvreg_write(pp, MVNETA_ACCESS_PROTECT_ENABLE, win_protect);
}
static int mvneta_port_power_up(struct mvneta_port *pp, int phy_mode)
{
u32 ctrl;
mvreg_write(pp, MVNETA_UNIT_INTR_CAUSE, 0);
ctrl = mvreg_read(pp, MVNETA_GMAC_CTRL_2);
switch(phy_mode) {
case PHY_INTERFACE_MODE_QSGMII:
mvreg_write(pp, MVNETA_SERDES_CFG, MVNETA_QSGMII_SERDES_PROTO);
ctrl |= MVNETA_GMAC2_PCS_ENABLE | MVNETA_GMAC2_PORT_RGMII;
break;
case PHY_INTERFACE_MODE_SGMII:
mvreg_write(pp, MVNETA_SERDES_CFG, MVNETA_SGMII_SERDES_PROTO);
ctrl |= MVNETA_GMAC2_PCS_ENABLE | MVNETA_GMAC2_PORT_RGMII;
break;
case PHY_INTERFACE_MODE_RGMII:
case PHY_INTERFACE_MODE_RGMII_ID:
ctrl |= MVNETA_GMAC2_PORT_RGMII;
break;
default:
return -EINVAL;
}
ctrl &= ~MVNETA_GMAC2_PORT_RESET;
mvreg_write(pp, MVNETA_GMAC_CTRL_2, ctrl);
while ((mvreg_read(pp, MVNETA_GMAC_CTRL_2) &
MVNETA_GMAC2_PORT_RESET) != 0)
continue;
return 0;
}
static int mvneta_probe(struct platform_device *pdev)
{
const struct mbus_dram_target_info *dram_target_info;
struct resource *res;
struct device_node *dn = pdev->dev.of_node;
struct device_node *phy_node;
struct device_node *bm_node;
struct mvneta_port *pp;
struct net_device *dev;
const char *dt_mac_addr;
char hw_mac_addr[ETH_ALEN];
const char *mac_from;
const char *managed;
int tx_csum_limit;
int phy_mode;
int err;
int cpu;
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
if (!of_phy_is_fixed_link(dn)) {
dev_err(&pdev->dev, "no PHY specified\n");
err = -ENODEV;
goto err_free_irq;
}
err = of_phy_register_fixed_link(dn);
if (err < 0) {
dev_err(&pdev->dev, "cannot register fixed PHY\n");
goto err_free_irq;
}
phy_node = of_node_get(dn);
}
phy_mode = of_get_phy_mode(dn);
if (phy_mode < 0) {
dev_err(&pdev->dev, "incorrect phy-mode\n");
err = -EINVAL;
goto err_put_phy_node;
}
dev->tx_queue_len = MVNETA_MAX_TXD;
dev->watchdog_timeo = 5 * HZ;
dev->netdev_ops = &mvneta_netdev_ops;
dev->ethtool_ops = &mvneta_eth_tool_ops;
pp = netdev_priv(dev);
spin_lock_init(&pp->lock);
pp->phy_node = phy_node;
pp->phy_interface = phy_mode;
err = of_property_read_string(dn, "managed", &managed);
pp->use_inband_status = (err == 0 &&
strcmp(managed, "in-band-status") == 0);
pp->cpu_notifier.notifier_call = mvneta_percpu_notifier;
pp->rxq_def = rxq_def;
pp->indir[0] = rxq_def;
pp->clk = devm_clk_get(&pdev->dev, "core");
if (IS_ERR(pp->clk))
pp->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pp->clk)) {
err = PTR_ERR(pp->clk);
goto err_put_phy_node;
}
clk_prepare_enable(pp->clk);
pp->clk_bus = devm_clk_get(&pdev->dev, "bus");
if (!IS_ERR(pp->clk_bus))
clk_prepare_enable(pp->clk_bus);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pp->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pp->base)) {
err = PTR_ERR(pp->base);
goto err_clk;
}
pp->ports = alloc_percpu(struct mvneta_pcpu_port);
if (!pp->ports) {
err = -ENOMEM;
goto err_clk;
}
pp->stats = netdev_alloc_pcpu_stats(struct mvneta_pcpu_stats);
if (!pp->stats) {
err = -ENOMEM;
goto err_free_ports;
}
dt_mac_addr = of_get_mac_address(dn);
if (dt_mac_addr) {
mac_from = "device tree";
memcpy(dev->dev_addr, dt_mac_addr, ETH_ALEN);
} else {
mvneta_get_mac_addr(pp, hw_mac_addr);
if (is_valid_ether_addr(hw_mac_addr)) {
mac_from = "hardware";
memcpy(dev->dev_addr, hw_mac_addr, ETH_ALEN);
} else {
mac_from = "random";
eth_hw_addr_random(dev);
}
}
if (!of_property_read_u32(dn, "tx-csum-limit", &tx_csum_limit)) {
if (tx_csum_limit < 0 ||
tx_csum_limit > MVNETA_TX_CSUM_MAX_SIZE) {
tx_csum_limit = MVNETA_TX_CSUM_DEF_SIZE;
dev_info(&pdev->dev,
"Wrong TX csum limit in DT, set to %dB\n",
MVNETA_TX_CSUM_DEF_SIZE);
}
} else if (of_device_is_compatible(dn, "marvell,armada-370-neta")) {
tx_csum_limit = MVNETA_TX_CSUM_DEF_SIZE;
} else {
tx_csum_limit = MVNETA_TX_CSUM_MAX_SIZE;
}
pp->tx_csum_limit = tx_csum_limit;
dram_target_info = mv_mbus_dram_info();
if (dram_target_info)
mvneta_conf_mbus_windows(pp, dram_target_info);
pp->tx_ring_size = MVNETA_MAX_TXD;
pp->rx_ring_size = MVNETA_MAX_RXD;
pp->dev = dev;
SET_NETDEV_DEV(dev, &pdev->dev);
pp->id = global_port_id++;
bm_node = of_parse_phandle(dn, "buffer-manager", 0);
if (bm_node && bm_node->data) {
pp->bm_priv = bm_node->data;
err = mvneta_bm_port_init(pdev, pp);
if (err < 0) {
dev_info(&pdev->dev, "use SW buffer management\n");
pp->bm_priv = NULL;
}
}
of_node_put(bm_node);
err = mvneta_init(&pdev->dev, pp);
if (err < 0)
goto err_netdev;
err = mvneta_port_power_up(pp, phy_mode);
if (err < 0) {
dev_err(&pdev->dev, "can't power up port\n");
goto err_netdev;
}
for_each_present_cpu(cpu) {
struct mvneta_pcpu_port *port = per_cpu_ptr(pp->ports, cpu);
netif_napi_add(dev, &port->napi, mvneta_poll, NAPI_POLL_WEIGHT);
port->pp = pp;
}
dev->features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_TSO;
dev->hw_features |= dev->features;
dev->vlan_features |= dev->features;
dev->priv_flags |= IFF_UNICAST_FLT | IFF_LIVE_ADDR_CHANGE;
dev->gso_max_segs = MVNETA_MAX_TSO_SEGS;
err = register_netdev(dev);
if (err < 0) {
dev_err(&pdev->dev, "failed to register\n");
goto err_free_stats;
}
netdev_info(dev, "Using %s mac address %pM\n", mac_from,
dev->dev_addr);
platform_set_drvdata(pdev, pp->dev);
if (pp->use_inband_status) {
struct phy_device *phy = of_phy_find_device(dn);
mvneta_fixed_link_update(pp, phy);
put_device(&phy->mdio.dev);
}
return 0;
err_netdev:
unregister_netdev(dev);
if (pp->bm_priv) {
mvneta_bm_pool_destroy(pp->bm_priv, pp->pool_long, 1 << pp->id);
mvneta_bm_pool_destroy(pp->bm_priv, pp->pool_short,
1 << pp->id);
}
err_free_stats:
free_percpu(pp->stats);
err_free_ports:
free_percpu(pp->ports);
err_clk:
clk_disable_unprepare(pp->clk_bus);
clk_disable_unprepare(pp->clk);
err_put_phy_node:
of_node_put(phy_node);
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
clk_disable_unprepare(pp->clk_bus);
clk_disable_unprepare(pp->clk);
free_percpu(pp->ports);
free_percpu(pp->stats);
irq_dispose_mapping(dev->irq);
of_node_put(pp->phy_node);
free_netdev(dev);
if (pp->bm_priv) {
mvneta_bm_pool_destroy(pp->bm_priv, pp->pool_long, 1 << pp->id);
mvneta_bm_pool_destroy(pp->bm_priv, pp->pool_short,
1 << pp->id);
}
return 0;
}
