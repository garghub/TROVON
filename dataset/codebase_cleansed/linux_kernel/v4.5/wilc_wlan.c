static void wilc_debug(u32 flag, char *fmt, ...)
{
char buf[256];
va_list args;
if (flag & dbgflag) {
va_start(args, fmt);
vsprintf(buf, fmt, args);
va_end(args);
wilc_dbg(buf);
}
}
static inline void acquire_bus(struct wilc *wilc, BUS_ACQUIRE_T acquire)
{
mutex_lock(&wilc->hif_cs);
#ifndef WILC_OPTIMIZE_SLEEP_INT
if (chip_ps_state != CHIP_WAKEDUP)
#endif
{
if (acquire == ACQUIRE_AND_WAKEUP)
chip_wakeup(wilc);
}
}
static inline void release_bus(struct wilc *wilc, BUS_RELEASE_T release)
{
#ifdef WILC_OPTIMIZE_SLEEP_INT
if (release == RELEASE_ALLOW_SLEEP)
chip_allow_sleep(wilc);
#endif
mutex_unlock(&wilc->hif_cs);
}
static void wilc_wlan_txq_remove(struct txq_entry_t *tqe)
{
if (tqe == wilc->txq_head) {
wilc->txq_head = tqe->next;
if (wilc->txq_head)
wilc->txq_head->prev = NULL;
} else if (tqe == wilc->txq_tail) {
wilc->txq_tail = (tqe->prev);
if (wilc->txq_tail)
wilc->txq_tail->next = NULL;
} else {
tqe->prev->next = tqe->next;
tqe->next->prev = tqe->prev;
}
wilc->txq_entries -= 1;
}
static struct txq_entry_t *
wilc_wlan_txq_remove_from_head(struct net_device *dev)
{
struct txq_entry_t *tqe;
unsigned long flags;
struct wilc_vif *vif;
struct wilc *wilc;
vif = netdev_priv(dev);
wilc = vif->wilc;
spin_lock_irqsave(&wilc->txq_spinlock, flags);
if (wilc->txq_head) {
tqe = wilc->txq_head;
wilc->txq_head = tqe->next;
if (wilc->txq_head)
wilc->txq_head->prev = NULL;
wilc->txq_entries -= 1;
} else {
tqe = NULL;
}
spin_unlock_irqrestore(&wilc->txq_spinlock, flags);
return tqe;
}
static void wilc_wlan_txq_add_to_tail(struct net_device *dev,
struct txq_entry_t *tqe)
{
unsigned long flags;
struct wilc_vif *vif;
struct wilc *wilc;
vif = netdev_priv(dev);
wilc = vif->wilc;
spin_lock_irqsave(&wilc->txq_spinlock, flags);
if (!wilc->txq_head) {
tqe->next = NULL;
tqe->prev = NULL;
wilc->txq_head = tqe;
wilc->txq_tail = tqe;
} else {
tqe->next = NULL;
tqe->prev = wilc->txq_tail;
wilc->txq_tail->next = tqe;
wilc->txq_tail = tqe;
}
wilc->txq_entries += 1;
PRINT_D(TX_DBG, "Number of entries in TxQ = %d\n", wilc->txq_entries);
spin_unlock_irqrestore(&wilc->txq_spinlock, flags);
PRINT_D(TX_DBG, "Wake the txq_handling\n");
up(&wilc->txq_event);
}
static int wilc_wlan_txq_add_to_head(struct wilc *wilc, struct txq_entry_t *tqe)
{
unsigned long flags;
if (wilc_lock_timeout(wilc, &wilc->txq_add_to_head_cs,
CFG_PKTS_TIMEOUT))
return -1;
spin_lock_irqsave(&wilc->txq_spinlock, flags);
if (!wilc->txq_head) {
tqe->next = NULL;
tqe->prev = NULL;
wilc->txq_head = tqe;
wilc->txq_tail = tqe;
} else {
tqe->next = wilc->txq_head;
tqe->prev = NULL;
wilc->txq_head->prev = tqe;
wilc->txq_head = tqe;
}
wilc->txq_entries += 1;
PRINT_D(TX_DBG, "Number of entries in TxQ = %d\n", wilc->txq_entries);
spin_unlock_irqrestore(&wilc->txq_spinlock, flags);
up(&wilc->txq_add_to_head_cs);
up(&wilc->txq_event);
PRINT_D(TX_DBG, "Wake up the txq_handler\n");
return 0;
}
static inline int init_tcp_tracking(void)
{
return 0;
}
static inline int add_tcp_session(u32 src_prt, u32 dst_prt, u32 seq)
{
ack_session_info[tcp_session].seq_num = seq;
ack_session_info[tcp_session].bigger_ack_num = 0;
ack_session_info[tcp_session].src_port = src_prt;
ack_session_info[tcp_session].dst_port = dst_prt;
tcp_session++;
PRINT_D(TCP_ENH, "TCP Session %d to Ack %d\n", tcp_session, seq);
return 0;
}
static inline int update_tcp_session(u32 index, u32 ack)
{
if (ack > ack_session_info[index].bigger_ack_num)
ack_session_info[index].bigger_ack_num = ack;
return 0;
}
static inline int add_tcp_pending_ack(u32 ack, u32 session_index,
struct txq_entry_t *txqe)
{
if (pending_acks < MAX_PENDING_ACKS) {
pending_acks_info[pending_base + pending_acks].ack_num = ack;
pending_acks_info[pending_base + pending_acks].txqe = txqe;
pending_acks_info[pending_base + pending_acks].session_index = session_index;
txqe->tcp_pending_ack_idx = pending_base + pending_acks;
pending_acks++;
}
return 0;
}
static inline int remove_TCP_related(struct wilc *wilc)
{
unsigned long flags;
spin_lock_irqsave(&wilc->txq_spinlock, flags);
spin_unlock_irqrestore(&wilc->txq_spinlock, flags);
return 0;
}
static inline int tcp_process(struct net_device *dev, struct txq_entry_t *tqe)
{
int ret;
u8 *eth_hdr_ptr;
u8 *buffer = tqe->buffer;
unsigned short h_proto;
int i;
unsigned long flags;
struct wilc_vif *vif;
struct wilc *wilc;
vif = netdev_priv(dev);
wilc = vif->wilc;
eth_hdr_ptr = &buffer[0];
h_proto = ntohs(*((unsigned short *)&eth_hdr_ptr[12]));
if (h_proto == 0x0800) {
u8 *ip_hdr_ptr;
u8 protocol;
ip_hdr_ptr = &buffer[ETHERNET_HDR_LEN];
protocol = ip_hdr_ptr[9];
if (protocol == 0x06) {
u8 *tcp_hdr_ptr;
u32 IHL, total_length, data_offset;
tcp_hdr_ptr = &ip_hdr_ptr[IP_HDR_LEN];
IHL = (ip_hdr_ptr[0] & 0xf) << 2;
total_length = ((u32)ip_hdr_ptr[2] << 8) +
(u32)ip_hdr_ptr[3];
data_offset = ((u32)tcp_hdr_ptr[12] & 0xf0) >> 2;
if (total_length == (IHL + data_offset)) {
u32 seq_no, ack_no;
seq_no = ((u32)tcp_hdr_ptr[4] << 24) +
((u32)tcp_hdr_ptr[5] << 16) +
((u32)tcp_hdr_ptr[6] << 8) +
(u32)tcp_hdr_ptr[7];
ack_no = ((u32)tcp_hdr_ptr[8] << 24) +
((u32)tcp_hdr_ptr[9] << 16) +
((u32)tcp_hdr_ptr[10] << 8) +
(u32)tcp_hdr_ptr[11];
for (i = 0; i < tcp_session; i++) {
if (ack_session_info[i].seq_num == seq_no) {
update_tcp_session(i, ack_no);
break;
}
}
if (i == tcp_session)
add_tcp_session(0, 0, seq_no);
add_tcp_pending_ack(ack_no, i, tqe);
}
} else {
ret = 0;
}
} else {
ret = 0;
}
spin_unlock_irqrestore(&wilc->txq_spinlock, flags);
return ret;
}
static int wilc_wlan_txq_filter_dup_tcp_ack(struct net_device *dev)
{
struct wilc_vif *vif;
struct wilc *wilc;
u32 i = 0;
u32 dropped = 0;
vif = netdev_priv(dev);
wilc = vif->wilc;
spin_lock_irqsave(&wilc->txq_spinlock, wilc->txq_spinlock_flags);
for (i = pending_base; i < (pending_base + pending_acks); i++) {
if (pending_acks_info[i].ack_num < ack_session_info[pending_acks_info[i].session_index].bigger_ack_num) {
struct txq_entry_t *tqe;
PRINT_D(TCP_ENH, "DROP ACK: %u\n",
pending_acks_info[i].ack_num);
tqe = pending_acks_info[i].txqe;
if (tqe) {
wilc_wlan_txq_remove(tqe);
tqe->status = 1;
if (tqe->tx_complete_func)
tqe->tx_complete_func(tqe->priv,
tqe->status);
kfree(tqe);
dropped++;
}
}
}
pending_acks = 0;
tcp_session = 0;
if (pending_base == 0)
pending_base = MAX_TCP_SESSION;
else
pending_base = 0;
spin_unlock_irqrestore(&wilc->txq_spinlock, wilc->txq_spinlock_flags);
while (dropped > 0) {
wilc_lock_timeout(wilc, &wilc->txq_event, 1);
dropped--;
}
return 1;
}
void wilc_enable_tcp_ack_filter(bool value)
{
enabled = value;
}
static bool is_tcp_ack_filter_enabled(void)
{
return enabled;
}
static int wilc_wlan_txq_add_cfg_pkt(struct wilc *wilc, u8 *buffer, u32 buffer_size)
{
struct txq_entry_t *tqe;
PRINT_D(TX_DBG, "Adding config packet ...\n");
if (wilc->quit) {
PRINT_D(TX_DBG, "Return due to clear function\n");
up(&wilc->cfg_event);
return 0;
}
tqe = kmalloc(sizeof(*tqe), GFP_ATOMIC);
if (!tqe) {
PRINT_ER("Failed to allocate memory\n");
return 0;
}
tqe->type = WILC_CFG_PKT;
tqe->buffer = buffer;
tqe->buffer_size = buffer_size;
tqe->tx_complete_func = NULL;
tqe->priv = NULL;
#ifdef TCP_ACK_FILTER
tqe->tcp_pending_ack_idx = NOT_TCP_ACK;
#endif
PRINT_D(TX_DBG, "Adding the config packet at the Queue tail\n");
if (wilc_wlan_txq_add_to_head(wilc, tqe))
return 0;
return 1;
}
int wilc_wlan_txq_add_net_pkt(struct net_device *dev, void *priv, u8 *buffer,
u32 buffer_size, wilc_tx_complete_func_t func)
{
struct txq_entry_t *tqe;
struct wilc_vif *vif = netdev_priv(dev);
struct wilc *wilc;
wilc = vif->wilc;
if (wilc->quit)
return 0;
tqe = kmalloc(sizeof(*tqe), GFP_ATOMIC);
if (!tqe)
return 0;
tqe->type = WILC_NET_PKT;
tqe->buffer = buffer;
tqe->buffer_size = buffer_size;
tqe->tx_complete_func = func;
tqe->priv = priv;
PRINT_D(TX_DBG, "Adding mgmt packet at the Queue tail\n");
#ifdef TCP_ACK_FILTER
tqe->tcp_pending_ack_idx = NOT_TCP_ACK;
if (is_tcp_ack_filter_enabled())
tcp_process(dev, tqe);
#endif
wilc_wlan_txq_add_to_tail(dev, tqe);
return wilc->txq_entries;
}
int wilc_wlan_txq_add_mgmt_pkt(struct net_device *dev, void *priv, u8 *buffer,
u32 buffer_size, wilc_tx_complete_func_t func)
{
struct txq_entry_t *tqe;
struct wilc_vif *vif = netdev_priv(dev);
struct wilc *wilc;
wilc = vif->wilc;
if (wilc->quit)
return 0;
tqe = kmalloc(sizeof(*tqe), GFP_KERNEL);
if (!tqe)
return 0;
tqe->type = WILC_MGMT_PKT;
tqe->buffer = buffer;
tqe->buffer_size = buffer_size;
tqe->tx_complete_func = func;
tqe->priv = priv;
#ifdef TCP_ACK_FILTER
tqe->tcp_pending_ack_idx = NOT_TCP_ACK;
#endif
PRINT_D(TX_DBG, "Adding Network packet at the Queue tail\n");
wilc_wlan_txq_add_to_tail(dev, tqe);
return 1;
}
static struct txq_entry_t *wilc_wlan_txq_get_first(struct wilc *wilc)
{
struct txq_entry_t *tqe;
unsigned long flags;
spin_lock_irqsave(&wilc->txq_spinlock, flags);
tqe = wilc->txq_head;
spin_unlock_irqrestore(&wilc->txq_spinlock, flags);
return tqe;
}
static struct txq_entry_t *wilc_wlan_txq_get_next(struct wilc *wilc,
struct txq_entry_t *tqe)
{
unsigned long flags;
spin_lock_irqsave(&wilc->txq_spinlock, flags);
tqe = tqe->next;
spin_unlock_irqrestore(&wilc->txq_spinlock, flags);
return tqe;
}
static int wilc_wlan_rxq_add(struct wilc *wilc, struct rxq_entry_t *rqe)
{
if (wilc->quit)
return 0;
mutex_lock(&wilc->rxq_cs);
if (!wilc->rxq_head) {
PRINT_D(RX_DBG, "Add to Queue head\n");
rqe->next = NULL;
wilc->rxq_head = rqe;
wilc->rxq_tail = rqe;
} else {
PRINT_D(RX_DBG, "Add to Queue tail\n");
wilc->rxq_tail->next = rqe;
rqe->next = NULL;
wilc->rxq_tail = rqe;
}
wilc->rxq_entries += 1;
PRINT_D(RX_DBG, "Number of queue entries: %d\n", wilc->rxq_entries);
mutex_unlock(&wilc->rxq_cs);
return wilc->rxq_entries;
}
static struct rxq_entry_t *wilc_wlan_rxq_remove(struct wilc *wilc)
{
PRINT_D(RX_DBG, "Getting rxQ element\n");
if (wilc->rxq_head) {
struct rxq_entry_t *rqe;
mutex_lock(&wilc->rxq_cs);
rqe = wilc->rxq_head;
wilc->rxq_head = wilc->rxq_head->next;
wilc->rxq_entries -= 1;
PRINT_D(RX_DBG, "RXQ entries decreased\n");
mutex_unlock(&wilc->rxq_cs);
return rqe;
}
PRINT_D(RX_DBG, "Nothing to get from Q\n");
return NULL;
}
static inline void chip_allow_sleep(struct wilc *wilc)
{
u32 reg = 0;
wilc->hif_func->hif_read_reg(wilc, 0xf0, &reg);
wilc->hif_func->hif_write_reg(wilc, 0xf0, reg & ~BIT(0));
}
static inline void chip_wakeup(struct wilc *wilc)
{
u32 reg, clk_status_reg, trials = 0;
u32 sleep_time;
if ((wilc->io_type & 0x1) == HIF_SPI) {
do {
wilc->hif_func->hif_read_reg(wilc, 1, &reg);
wilc->hif_func->hif_write_reg(wilc, 1, reg | BIT(1));
wilc->hif_func->hif_write_reg(wilc, 1, reg & ~BIT(1));
do {
usleep_range(2 * 1000, 2 * 1000);
if ((wilc_get_chipid(wilc, true) == 0))
wilc_debug(N_ERR, "Couldn't read chip id. Wake up failed\n");
} while ((wilc_get_chipid(wilc, true) == 0) && ((++trials % 3) == 0));
} while (wilc_get_chipid(wilc, true) == 0);
} else if ((wilc->io_type & 0x1) == HIF_SDIO) {
wilc->hif_func->hif_read_reg(wilc, 0xf0, &reg);
do {
wilc->hif_func->hif_write_reg(wilc, 0xf0,
reg | BIT(0));
wilc->hif_func->hif_read_reg(wilc, 0xf1,
&clk_status_reg);
while (((clk_status_reg & 0x1) == 0) && (((++trials) % 3) == 0)) {
usleep_range(2 * 1000, 2 * 1000);
wilc->hif_func->hif_read_reg(wilc, 0xf1,
&clk_status_reg);
if ((clk_status_reg & 0x1) == 0)
wilc_debug(N_ERR, "clocks still OFF. Wake up failed\n");
}
if ((clk_status_reg & 0x1) == 0) {
wilc->hif_func->hif_write_reg(wilc, 0xf0,
reg & (~BIT(0)));
}
} while ((clk_status_reg & 0x1) == 0);
}
if (chip_ps_state == CHIP_SLEEPING_MANUAL) {
wilc->hif_func->hif_read_reg(wilc, 0x1C0C, &reg);
reg &= ~BIT(0);
wilc->hif_func->hif_write_reg(wilc, 0x1C0C, reg);
if (wilc_get_chipid(wilc, false) >= 0x1002b0) {
u32 val32;
wilc->hif_func->hif_read_reg(wilc, 0x1e1c, &val32);
val32 |= BIT(6);
wilc->hif_func->hif_write_reg(wilc, 0x1e1c, val32);
wilc->hif_func->hif_read_reg(wilc, 0x1e9c, &val32);
val32 |= BIT(6);
wilc->hif_func->hif_write_reg(wilc, 0x1e9c, val32);
}
}
chip_ps_state = CHIP_WAKEDUP;
}
static inline void chip_wakeup(struct wilc *wilc)
{
u32 reg, trials = 0;
do {
if ((wilc->io_type & 0x1) == HIF_SPI) {
wilc->hif_func->hif_read_reg(wilc, 1, &reg);
wilc->hif_func->hif_write_reg(wilc, 1, reg & ~BIT(1));
wilc->hif_func->hif_write_reg(wilc, 1, reg | BIT(1));
wilc->hif_func->hif_write_reg(wilc, 1, reg & ~BIT(1));
} else if ((wilc->io_type & 0x1) == HIF_SDIO) {
wilc->hif_func->hif_read_reg(wilc, 0xf0, &reg);
wilc->hif_func->hif_write_reg(wilc, 0xf0,
reg & ~BIT(0));
wilc->hif_func->hif_write_reg(wilc, 0xf0,
reg | BIT(0));
wilc->hif_func->hif_write_reg(wilc, 0xf0,
reg & ~BIT(0));
}
do {
mdelay(3);
if ((wilc_get_chipid(wilc, true) == 0))
wilc_debug(N_ERR, "Couldn't read chip id. Wake up failed\n");
} while ((wilc_get_chipid(wilc, true) == 0) && ((++trials % 3) == 0));
} while (wilc_get_chipid(wilc, true) == 0);
if (chip_ps_state == CHIP_SLEEPING_MANUAL) {
wilc->hif_func->hif_read_reg(wilc, 0x1C0C, &reg);
reg &= ~BIT(0);
wilc->hif_func->hif_write_reg(wilc, 0x1C0C, reg);
if (wilc_get_chipid(wilc, false) >= 0x1002b0) {
u32 val32;
wilc->hif_func->hif_read_reg(wilc, 0x1e1c, &val32);
val32 |= BIT(6);
wilc->hif_func->hif_write_reg(wilc, 0x1e1c, val32);
wilc->hif_func->hif_read_reg(wilc, 0x1e9c, &val32);
val32 |= BIT(6);
wilc->hif_func->hif_write_reg(wilc, 0x1e9c, val32);
}
}
chip_ps_state = CHIP_WAKEDUP;
}
void wilc_chip_sleep_manually(struct wilc *wilc)
{
if (chip_ps_state != CHIP_WAKEDUP)
return;
acquire_bus(wilc, ACQUIRE_ONLY);
#ifdef WILC_OPTIMIZE_SLEEP_INT
chip_allow_sleep(wilc);
#endif
wilc->hif_func->hif_write_reg(wilc, 0x10a8, 1);
chip_ps_state = CHIP_SLEEPING_MANUAL;
release_bus(wilc, RELEASE_ONLY);
}
int wilc_wlan_handle_txq(struct net_device *dev, u32 *txq_count)
{
int i, entries = 0;
u32 sum;
u32 reg;
u8 *txb;
u32 offset = 0;
int vmm_sz = 0;
struct txq_entry_t *tqe;
int ret = 0;
int counter;
int timeout;
u32 vmm_table[WILC_VMM_TBL_SIZE];
struct wilc_vif *vif;
struct wilc *wilc;
vif = netdev_priv(dev);
wilc = vif->wilc;
txb = wilc->tx_buffer;
wilc->txq_exit = 0;
do {
if (wilc->quit)
break;
wilc_lock_timeout(wilc, &wilc->txq_add_to_head_cs,
CFG_PKTS_TIMEOUT);
#ifdef TCP_ACK_FILTER
wilc_wlan_txq_filter_dup_tcp_ack(dev);
#endif
PRINT_D(TX_DBG, "Getting the head of the TxQ\n");
tqe = wilc_wlan_txq_get_first(wilc);
i = 0;
sum = 0;
do {
if (tqe && (i < (WILC_VMM_TBL_SIZE - 1))) {
if (tqe->type == WILC_CFG_PKT)
vmm_sz = ETH_CONFIG_PKT_HDR_OFFSET;
else if (tqe->type == WILC_NET_PKT)
vmm_sz = ETH_ETHERNET_HDR_OFFSET;
else
vmm_sz = HOST_HDR_OFFSET;
vmm_sz += tqe->buffer_size;
PRINT_D(TX_DBG, "VMM Size before alignment = %d\n", vmm_sz);
if (vmm_sz & 0x3)
vmm_sz = (vmm_sz + 4) & ~0x3;
if ((sum + vmm_sz) > LINUX_TX_SIZE)
break;
PRINT_D(TX_DBG, "VMM Size AFTER alignment = %d\n", vmm_sz);
vmm_table[i] = vmm_sz / 4;
PRINT_D(TX_DBG, "VMMTable entry size = %d\n",
vmm_table[i]);
if (tqe->type == WILC_CFG_PKT) {
vmm_table[i] |= BIT(10);
PRINT_D(TX_DBG, "VMMTable entry changed for CFG packet = %d\n", vmm_table[i]);
}
vmm_table[i] = cpu_to_le32(vmm_table[i]);
i++;
sum += vmm_sz;
PRINT_D(TX_DBG, "sum = %d\n", sum);
tqe = wilc_wlan_txq_get_next(wilc, tqe);
} else {
break;
}
} while (1);
if (i == 0) {
PRINT_D(TX_DBG, "Nothing in TX-Q\n");
break;
} else {
PRINT_D(TX_DBG, "Mark the last entry in VMM table - number of previous entries = %d\n", i);
vmm_table[i] = 0x0;
}
acquire_bus(wilc, ACQUIRE_AND_WAKEUP);
counter = 0;
do {
ret = wilc->hif_func->hif_read_reg(wilc, WILC_HOST_TX_CTRL,
&reg);
if (!ret) {
wilc_debug(N_ERR, "[wilc txq]: fail can't read reg vmm_tbl_entry..\n");
break;
}
if ((reg & 0x1) == 0) {
PRINT_D(TX_DBG, "Writing VMM table ... with Size = %d\n", ((i + 1) * 4));
break;
} else {
counter++;
if (counter > 200) {
counter = 0;
PRINT_D(TX_DBG, "Looping in tx ctrl , forcce quit\n");
ret = wilc->hif_func->hif_write_reg(wilc, WILC_HOST_TX_CTRL, 0);
break;
}
PRINT_WRN(GENERIC_DBG, "[wilc txq]: warn, vmm table not clear yet, wait...\n");
release_bus(wilc, RELEASE_ALLOW_SLEEP);
usleep_range(3000, 3000);
acquire_bus(wilc, ACQUIRE_AND_WAKEUP);
}
} while (!wilc->quit);
if (!ret)
goto _end_;
timeout = 200;
do {
ret = wilc->hif_func->hif_block_tx(wilc, WILC_VMM_TBL_RX_SHADOW_BASE, (u8 *)vmm_table, ((i + 1) * 4));
if (!ret) {
wilc_debug(N_ERR, "ERR block TX of VMM table.\n");
break;
}
ret = wilc->hif_func->hif_write_reg(wilc, WILC_HOST_VMM_CTL,
0x2);
if (!ret) {
wilc_debug(N_ERR, "[wilc txq]: fail can't write reg host_vmm_ctl..\n");
break;
}
do {
ret = wilc->hif_func->hif_read_reg(wilc, WILC_HOST_VMM_CTL, &reg);
if (!ret) {
wilc_debug(N_ERR, "[wilc txq]: fail can't read reg host_vmm_ctl..\n");
break;
}
if ((reg >> 2) & 0x1) {
entries = ((reg >> 3) & 0x3f);
break;
} else {
release_bus(wilc, RELEASE_ALLOW_SLEEP);
usleep_range(3000, 3000);
acquire_bus(wilc, ACQUIRE_AND_WAKEUP);
PRINT_WRN(GENERIC_DBG, "Can't get VMM entery - reg = %2x\n", reg);
}
} while (--timeout);
if (timeout <= 0) {
ret = wilc->hif_func->hif_write_reg(wilc, WILC_HOST_VMM_CTL, 0x0);
break;
}
if (!ret)
break;
if (entries == 0) {
PRINT_WRN(GENERIC_DBG, "[wilc txq]: no more buffer in the chip (reg: %08x), retry later [[ %d, %x ]]\n", reg, i, vmm_table[i - 1]);
ret = wilc->hif_func->hif_read_reg(wilc, WILC_HOST_TX_CTRL, &reg);
if (!ret) {
wilc_debug(N_ERR, "[wilc txq]: fail can't read reg WILC_HOST_TX_CTRL..\n");
break;
}
reg &= ~BIT(0);
ret = wilc->hif_func->hif_write_reg(wilc, WILC_HOST_TX_CTRL, reg);
if (!ret) {
wilc_debug(N_ERR, "[wilc txq]: fail can't write reg WILC_HOST_TX_CTRL..\n");
break;
}
break;
} else {
break;
}
} while (1);
if (!ret)
goto _end_;
if (entries == 0) {
ret = WILC_TX_ERR_NO_BUF;
goto _end_;
}
release_bus(wilc, RELEASE_ALLOW_SLEEP);
offset = 0;
i = 0;
do {
tqe = wilc_wlan_txq_remove_from_head(dev);
if (tqe && (vmm_table[i] != 0)) {
u32 header, buffer_offset;
vmm_table[i] = cpu_to_le32(vmm_table[i]);
vmm_sz = (vmm_table[i] & 0x3ff);
vmm_sz *= 4;
header = (tqe->type << 31) |
(tqe->buffer_size << 15) |
vmm_sz;
if (tqe->type == WILC_MGMT_PKT)
header |= BIT(30);
else
header &= ~BIT(30);
header = cpu_to_le32(header);
memcpy(&txb[offset], &header, 4);
if (tqe->type == WILC_CFG_PKT) {
buffer_offset = ETH_CONFIG_PKT_HDR_OFFSET;
} else if (tqe->type == WILC_NET_PKT) {
char *bssid = ((struct tx_complete_data *)(tqe->priv))->pBssid;
buffer_offset = ETH_ETHERNET_HDR_OFFSET;
memcpy(&txb[offset + 4], bssid, 6);
} else {
buffer_offset = HOST_HDR_OFFSET;
}
memcpy(&txb[offset + buffer_offset],
tqe->buffer, tqe->buffer_size);
offset += vmm_sz;
i++;
tqe->status = 1;
if (tqe->tx_complete_func)
tqe->tx_complete_func(tqe->priv,
tqe->status);
#ifdef TCP_ACK_FILTER
if (tqe->tcp_pending_ack_idx != NOT_TCP_ACK)
pending_acks_info[tqe->tcp_pending_ack_idx].txqe = NULL;
#endif
kfree(tqe);
} else {
break;
}
} while (--entries);
acquire_bus(wilc, ACQUIRE_AND_WAKEUP);
ret = wilc->hif_func->hif_clear_int_ext(wilc, ENABLE_TX_VMM);
if (!ret) {
wilc_debug(N_ERR, "[wilc txq]: fail can't start tx VMM ...\n");
goto _end_;
}
ret = wilc->hif_func->hif_block_tx_ext(wilc, 0, txb, offset);
if (!ret) {
wilc_debug(N_ERR, "[wilc txq]: fail can't block tx ext...\n");
goto _end_;
}
_end_:
release_bus(wilc, RELEASE_ALLOW_SLEEP);
if (ret != 1)
break;
} while (0);
up(&wilc->txq_add_to_head_cs);
wilc->txq_exit = 1;
PRINT_D(TX_DBG, "THREAD: Exiting txq\n");
*txq_count = wilc->txq_entries;
return ret;
}
static void wilc_wlan_handle_rxq(struct wilc *wilc)
{
int offset = 0, size, has_packet = 0;
u8 *buffer;
struct rxq_entry_t *rqe;
wilc->rxq_exit = 0;
do {
if (wilc->quit) {
PRINT_D(RX_DBG, "exit 1st do-while due to Clean_UP function\n");
up(&wilc->cfg_event);
break;
}
rqe = wilc_wlan_rxq_remove(wilc);
if (!rqe) {
PRINT_D(RX_DBG, "nothing in the queue - exit 1st do-while\n");
break;
}
buffer = rqe->buffer;
size = rqe->buffer_size;
PRINT_D(RX_DBG, "rxQ entery Size = %d - Address = %p\n",
size, buffer);
offset = 0;
do {
u32 header;
u32 pkt_len, pkt_offset, tp_len;
int is_cfg_packet;
PRINT_D(RX_DBG, "In the 2nd do-while\n");
memcpy(&header, &buffer[offset], 4);
header = cpu_to_le32(header);
PRINT_D(RX_DBG, "Header = %04x - Offset = %d\n",
header, offset);
is_cfg_packet = (header >> 31) & 0x1;
pkt_offset = (header >> 22) & 0x1ff;
tp_len = (header >> 11) & 0x7ff;
pkt_len = header & 0x7ff;
if (pkt_len == 0 || tp_len == 0) {
wilc_debug(N_RXQ, "[wilc rxq]: data corrupt, packet len or tp_len is 0 [%d][%d]\n", pkt_len, tp_len);
break;
}
#define IS_MANAGMEMENT 0x100
#define IS_MANAGMEMENT_CALLBACK 0x080
#define IS_MGMT_STATUS_SUCCES 0x040
if (pkt_offset & IS_MANAGMEMENT) {
pkt_offset &= ~(IS_MANAGMEMENT |
IS_MANAGMEMENT_CALLBACK |
IS_MGMT_STATUS_SUCCES);
WILC_WFI_mgmt_rx(wilc, &buffer[offset + HOST_HDR_OFFSET], pkt_len);
} else {
if (!is_cfg_packet) {
if (pkt_len > 0) {
wilc_frmw_to_linux(wilc,
&buffer[offset],
pkt_len,
pkt_offset);
has_packet = 1;
}
} else {
struct wilc_cfg_rsp rsp;
wilc_wlan_cfg_indicate_rx(wilc, &buffer[pkt_offset + offset], pkt_len, &rsp);
if (rsp.type == WILC_CFG_RSP) {
PRINT_D(RX_DBG, "wilc->cfg_seq_no = %d - rsp.seq_no = %d\n", wilc->cfg_seq_no, rsp.seq_no);
if (wilc->cfg_seq_no == rsp.seq_no)
up(&wilc->cfg_event);
} else if (rsp.type == WILC_CFG_RSP_STATUS) {
wilc_mac_indicate(wilc, WILC_MAC_INDICATE_STATUS);
} else if (rsp.type == WILC_CFG_RSP_SCAN) {
wilc_mac_indicate(wilc, WILC_MAC_INDICATE_SCAN);
}
}
}
offset += tp_len;
if (offset >= size)
break;
} while (1);
kfree(rqe);
if (has_packet)
wilc_rx_complete(wilc);
} while (1);
wilc->rxq_exit = 1;
PRINT_D(RX_DBG, "THREAD: Exiting RX thread\n");
}
static void wilc_unknown_isr_ext(struct wilc *wilc)
{
wilc->hif_func->hif_clear_int_ext(wilc, 0);
}
static void wilc_pllupdate_isr_ext(struct wilc *wilc, u32 int_stats)
{
int trials = 10;
wilc->hif_func->hif_clear_int_ext(wilc, PLL_INT_CLR);
if (wilc->io_type == HIF_SDIO)
mdelay(WILC_PLL_TO_SDIO);
else
mdelay(WILC_PLL_TO_SPI);
while (!(ISWILC1000(wilc_get_chipid(wilc, true)) && --trials)) {
PRINT_D(TX_DBG, "PLL update retrying\n");
mdelay(1);
}
}
static void wilc_sleeptimer_isr_ext(struct wilc *wilc, u32 int_stats1)
{
wilc->hif_func->hif_clear_int_ext(wilc, SLEEP_INT_CLR);
#ifndef WILC_OPTIMIZE_SLEEP_INT
chip_ps_state = CHIP_SLEEPING_AUTO;
#endif
}
static void wilc_wlan_handle_isr_ext(struct wilc *wilc, u32 int_status)
{
u32 offset = wilc->rx_buffer_offset;
u8 *buffer = NULL;
u32 size;
u32 retries = 0;
int ret = 0;
struct rxq_entry_t *rqe;
size = ((int_status & 0x7fff) << 2);
while (!size && retries < 10) {
u32 time = 0;
wilc_debug(N_ERR, "RX Size equal zero ... Trying to read it again for %d time\n", time++);
wilc->hif_func->hif_read_size(wilc, &size);
size = ((size & 0x7fff) << 2);
retries++;
}
if (size > 0) {
if (LINUX_RX_SIZE - offset < size)
offset = 0;
if (wilc->rx_buffer) {
buffer = &wilc->rx_buffer[offset];
} else {
wilc_debug(N_ERR, "[wilc isr]: fail Rx Buffer is NULL...drop the packets (%d)\n", size);
goto _end_;
}
wilc->hif_func->hif_clear_int_ext(wilc,
DATA_INT_CLR | ENABLE_RX_VMM);
ret = wilc->hif_func->hif_block_rx_ext(wilc, 0, buffer, size);
if (!ret) {
wilc_debug(N_ERR, "[wilc isr]: fail block rx...\n");
goto _end_;
}
_end_:
if (ret) {
offset += size;
wilc->rx_buffer_offset = offset;
rqe = kmalloc(sizeof(*rqe), GFP_KERNEL);
if (rqe) {
rqe->buffer = buffer;
rqe->buffer_size = size;
PRINT_D(RX_DBG, "rxq entery Size= %d - Address = %p\n", rqe->buffer_size, rqe->buffer);
wilc_wlan_rxq_add(wilc, rqe);
}
}
}
wilc_wlan_handle_rxq(wilc);
}
void wilc_handle_isr(struct wilc *wilc)
{
u32 int_status;
acquire_bus(wilc, ACQUIRE_AND_WAKEUP);
wilc->hif_func->hif_read_int(wilc, &int_status);
if (int_status & PLL_INT_EXT)
wilc_pllupdate_isr_ext(wilc, int_status);
if (int_status & DATA_INT_EXT) {
wilc_wlan_handle_isr_ext(wilc, int_status);
#ifndef WILC_OPTIMIZE_SLEEP_INT
chip_ps_state = CHIP_WAKEDUP;
#endif
}
if (int_status & SLEEP_INT_EXT)
wilc_sleeptimer_isr_ext(wilc, int_status);
if (!(int_status & (ALL_INT_EXT))) {
wilc_unknown_isr_ext(wilc);
}
release_bus(wilc, RELEASE_ALLOW_SLEEP);
}
int wilc_wlan_firmware_download(struct wilc *wilc, const u8 *buffer, u32 buffer_size)
{
u32 offset;
u32 addr, size, size2, blksz;
u8 *dma_buffer;
int ret = 0;
blksz = BIT(12);
dma_buffer = kmalloc(blksz, GFP_KERNEL);
if (!dma_buffer) {
ret = -EIO;
PRINT_ER("Can't allocate buffer for firmware download IO error\n ");
goto _fail_1;
}
PRINT_D(INIT_DBG, "Downloading firmware size = %d ...\n", buffer_size);
offset = 0;
do {
memcpy(&addr, &buffer[offset], 4);
memcpy(&size, &buffer[offset + 4], 4);
addr = cpu_to_le32(addr);
size = cpu_to_le32(size);
acquire_bus(wilc, ACQUIRE_ONLY);
offset += 8;
while (((int)size) && (offset < buffer_size)) {
if (size <= blksz)
size2 = size;
else
size2 = blksz;
memcpy(dma_buffer, &buffer[offset], size2);
ret = wilc->hif_func->hif_block_tx(wilc, addr, dma_buffer,
size2);
if (!ret)
break;
addr += size2;
offset += size2;
size -= size2;
}
release_bus(wilc, RELEASE_ONLY);
if (!ret) {
ret = -EIO;
PRINT_ER("Can't download firmware IO error\n ");
goto _fail_;
}
PRINT_D(INIT_DBG, "Offset = %d\n", offset);
} while (offset < buffer_size);
_fail_:
kfree(dma_buffer);
_fail_1:
return (ret < 0) ? ret : 0;
}
int wilc_wlan_start(struct wilc *wilc)
{
u32 reg = 0;
int ret;
u32 chipid;
if (wilc->io_type == HIF_SDIO) {
reg = 0;
reg |= BIT(3);
} else if (wilc->io_type == HIF_SPI) {
reg = 1;
}
acquire_bus(wilc, ACQUIRE_ONLY);
ret = wilc->hif_func->hif_write_reg(wilc, WILC_VMM_CORE_CFG, reg);
if (!ret) {
wilc_debug(N_ERR, "[wilc start]: fail write reg vmm_core_cfg...\n");
release_bus(wilc, RELEASE_ONLY);
ret = -EIO;
return ret;
}
reg = 0;
if (wilc->io_type == HIF_SDIO && wilc->dev_irq_num)
reg |= WILC_HAVE_SDIO_IRQ_GPIO;
#ifdef WILC_DISABLE_PMU
#else
reg |= WILC_HAVE_USE_PMU;
#endif
#ifdef WILC_SLEEP_CLK_SRC_XO
reg |= WILC_HAVE_SLEEP_CLK_SRC_XO;
#elif defined WILC_SLEEP_CLK_SRC_RTC
reg |= WILC_HAVE_SLEEP_CLK_SRC_RTC;
#endif
#ifdef WILC_EXT_PA_INV_TX_RX
reg |= WILC_HAVE_EXT_PA_INV_TX_RX;
#endif
reg |= WILC_HAVE_LEGACY_RF_SETTINGS;
#ifdef XTAL_24
reg |= WILC_HAVE_XTAL_24;
#endif
#ifdef DISABLE_WILC_UART
reg |= WILC_HAVE_DISABLE_WILC_UART;
#endif
ret = wilc->hif_func->hif_write_reg(wilc, WILC_GP_REG_1, reg);
if (!ret) {
wilc_debug(N_ERR, "[wilc start]: fail write WILC_GP_REG_1 ...\n");
release_bus(wilc, RELEASE_ONLY);
ret = -EIO;
return ret;
}
wilc->hif_func->hif_sync_ext(wilc, NUM_INT_EXT);
ret = wilc->hif_func->hif_read_reg(wilc, 0x1000, &chipid);
if (!ret) {
wilc_debug(N_ERR, "[wilc start]: fail read reg 0x1000 ...\n");
release_bus(wilc, RELEASE_ONLY);
ret = -EIO;
return ret;
}
wilc->hif_func->hif_read_reg(wilc, WILC_GLB_RESET_0, &reg);
if ((reg & BIT(10)) == BIT(10)) {
reg &= ~BIT(10);
wilc->hif_func->hif_write_reg(wilc, WILC_GLB_RESET_0, reg);
wilc->hif_func->hif_read_reg(wilc, WILC_GLB_RESET_0, &reg);
}
reg |= BIT(10);
ret = wilc->hif_func->hif_write_reg(wilc, WILC_GLB_RESET_0, reg);
wilc->hif_func->hif_read_reg(wilc, WILC_GLB_RESET_0, &reg);
release_bus(wilc, RELEASE_ONLY);
return (ret < 0) ? ret : 0;
}
void wilc_wlan_global_reset(struct wilc *wilc)
{
acquire_bus(wilc, ACQUIRE_AND_WAKEUP);
wilc->hif_func->hif_write_reg(wilc, WILC_GLB_RESET_0, 0x0);
release_bus(wilc, RELEASE_ONLY);
}
int wilc_wlan_stop(struct wilc *wilc)
{
u32 reg = 0;
int ret;
u8 timeout = 10;
acquire_bus(wilc, ACQUIRE_AND_WAKEUP);
ret = wilc->hif_func->hif_read_reg(wilc, WILC_GLB_RESET_0, &reg);
if (!ret) {
PRINT_ER("Error while reading reg\n");
release_bus(wilc, RELEASE_ALLOW_SLEEP);
return ret;
}
reg &= ~BIT(10);
ret = wilc->hif_func->hif_write_reg(wilc, WILC_GLB_RESET_0, reg);
if (!ret) {
PRINT_ER("Error while writing reg\n");
release_bus(wilc, RELEASE_ALLOW_SLEEP);
return ret;
}
do {
ret = wilc->hif_func->hif_read_reg(wilc, WILC_GLB_RESET_0, &reg);
if (!ret) {
PRINT_ER("Error while reading reg\n");
release_bus(wilc, RELEASE_ALLOW_SLEEP);
return ret;
}
PRINT_D(GENERIC_DBG, "Read RESET Reg %x : Retry%d\n",
reg, timeout);
if ((reg & BIT(10))) {
PRINT_D(GENERIC_DBG, "Bit 10 not reset : Retry %d\n",
timeout);
reg &= ~BIT(10);
ret = wilc->hif_func->hif_write_reg(wilc, WILC_GLB_RESET_0,
reg);
timeout--;
} else {
PRINT_D(GENERIC_DBG, "Bit 10 reset after : Retry %d\n",
timeout);
ret = wilc->hif_func->hif_read_reg(wilc, WILC_GLB_RESET_0,
&reg);
if (!ret) {
PRINT_ER("Error while reading reg\n");
release_bus(wilc, RELEASE_ALLOW_SLEEP);
return ret;
}
PRINT_D(GENERIC_DBG, "Read RESET Reg %x : Retry%d\n",
reg, timeout);
break;
}
} while (timeout);
reg = (BIT(0) | BIT(1) | BIT(2) | BIT(3) | BIT(8) | BIT(9) | BIT(26) |
BIT(29) | BIT(30) | BIT(31));
wilc->hif_func->hif_write_reg(wilc, WILC_GLB_RESET_0, reg);
reg = (u32)~BIT(10);
ret = wilc->hif_func->hif_write_reg(wilc, WILC_GLB_RESET_0, reg);
release_bus(wilc, RELEASE_ALLOW_SLEEP);
return ret;
}
void wilc_wlan_cleanup(struct net_device *dev)
{
struct txq_entry_t *tqe;
struct rxq_entry_t *rqe;
u32 reg = 0;
int ret;
struct wilc_vif *vif;
struct wilc *wilc;
vif = netdev_priv(dev);
wilc = vif->wilc;
wilc->quit = 1;
do {
tqe = wilc_wlan_txq_remove_from_head(dev);
if (!tqe)
break;
if (tqe->tx_complete_func)
tqe->tx_complete_func(tqe->priv, 0);
kfree(tqe);
} while (1);
do {
rqe = wilc_wlan_rxq_remove(wilc);
if (!rqe)
break;
kfree(rqe);
} while (1);
kfree(wilc->rx_buffer);
wilc->rx_buffer = NULL;
kfree(wilc->tx_buffer);
wilc->tx_buffer = NULL;
acquire_bus(wilc, ACQUIRE_AND_WAKEUP);
ret = wilc->hif_func->hif_read_reg(wilc, WILC_GP_REG_0, &reg);
if (!ret) {
PRINT_ER("Error while reading reg\n");
release_bus(wilc, RELEASE_ALLOW_SLEEP);
}
PRINT_ER("Writing ABORT reg\n");
ret = wilc->hif_func->hif_write_reg(wilc, WILC_GP_REG_0,
(reg | ABORT_INT));
if (!ret) {
PRINT_ER("Error while writing reg\n");
release_bus(wilc, RELEASE_ALLOW_SLEEP);
}
release_bus(wilc, RELEASE_ALLOW_SLEEP);
wilc->hif_func->hif_deinit(NULL);
}
static int wilc_wlan_cfg_commit(struct wilc *wilc, int type, u32 drv_handler)
{
struct wilc_cfg_frame *cfg = &wilc->cfg_frame;
int total_len = wilc->cfg_frame_offset + 4 + DRIVER_HANDLER_SIZE;
int seq_no = wilc->cfg_seq_no % 256;
int driver_handler = (u32)drv_handler;
if (type == WILC_CFG_SET)
cfg->wid_header[0] = 'W';
else
cfg->wid_header[0] = 'Q';
cfg->wid_header[1] = seq_no;
cfg->wid_header[2] = (u8)total_len;
cfg->wid_header[3] = (u8)(total_len >> 8);
cfg->wid_header[4] = (u8)driver_handler;
cfg->wid_header[5] = (u8)(driver_handler >> 8);
cfg->wid_header[6] = (u8)(driver_handler >> 16);
cfg->wid_header[7] = (u8)(driver_handler >> 24);
wilc->cfg_seq_no = seq_no;
if (!wilc_wlan_txq_add_cfg_pkt(wilc, &cfg->wid_header[0], total_len))
return -1;
return 0;
}
int wilc_wlan_cfg_set(struct wilc *wilc, int start, u32 wid, u8 *buffer,
u32 buffer_size, int commit, u32 drv_handler)
{
u32 offset;
int ret_size;
if (wilc->cfg_frame_in_use)
return 0;
if (start)
wilc->cfg_frame_offset = 0;
offset = wilc->cfg_frame_offset;
ret_size = wilc_wlan_cfg_set_wid(wilc->cfg_frame.frame, offset,
(u16)wid, buffer, buffer_size);
offset += ret_size;
wilc->cfg_frame_offset = offset;
if (commit) {
PRINT_D(TX_DBG, "[WILC]PACKET Commit with sequence number %d\n",
wilc->cfg_seq_no);
PRINT_D(RX_DBG, "Processing cfg_set()\n");
wilc->cfg_frame_in_use = 1;
if (wilc_wlan_cfg_commit(wilc, WILC_CFG_SET, drv_handler))
ret_size = 0;
if (wilc_lock_timeout(wilc, &wilc->cfg_event,
CFG_PKTS_TIMEOUT)) {
PRINT_D(TX_DBG, "Set Timed Out\n");
ret_size = 0;
}
wilc->cfg_frame_in_use = 0;
wilc->cfg_frame_offset = 0;
wilc->cfg_seq_no += 1;
}
return ret_size;
}
int wilc_wlan_cfg_get(struct wilc *wilc, int start, u32 wid, int commit,
u32 drv_handler)
{
u32 offset;
int ret_size;
if (wilc->cfg_frame_in_use)
return 0;
if (start)
wilc->cfg_frame_offset = 0;
offset = wilc->cfg_frame_offset;
ret_size = wilc_wlan_cfg_get_wid(wilc->cfg_frame.frame, offset,
(u16)wid);
offset += ret_size;
wilc->cfg_frame_offset = offset;
if (commit) {
wilc->cfg_frame_in_use = 1;
if (wilc_wlan_cfg_commit(wilc, WILC_CFG_QUERY, drv_handler))
ret_size = 0;
if (wilc_lock_timeout(wilc, &wilc->cfg_event,
CFG_PKTS_TIMEOUT)) {
PRINT_D(TX_DBG, "Get Timed Out\n");
ret_size = 0;
}
PRINT_D(GENERIC_DBG, "[WILC]Get Response received\n");
wilc->cfg_frame_in_use = 0;
wilc->cfg_frame_offset = 0;
wilc->cfg_seq_no += 1;
}
return ret_size;
}
int wilc_wlan_cfg_get_val(u32 wid, u8 *buffer, u32 buffer_size)
{
int ret;
ret = wilc_wlan_cfg_get_wid_value((u16)wid, buffer, buffer_size);
return ret;
}
static u32 init_chip(struct net_device *dev)
{
u32 chipid;
u32 reg, ret = 0;
struct wilc_vif *vif;
struct wilc *wilc;
vif = netdev_priv(dev);
wilc = vif->wilc;
acquire_bus(wilc, ACQUIRE_ONLY);
chipid = wilc_get_chipid(wilc, true);
if ((chipid & 0xfff) != 0xa0) {
ret = wilc->hif_func->hif_read_reg(wilc, 0x1118, &reg);
if (!ret) {
wilc_debug(N_ERR, "[wilc start]: fail read reg 0x1118 ...\n");
return ret;
}
reg |= BIT(0);
ret = wilc->hif_func->hif_write_reg(wilc, 0x1118, reg);
if (!ret) {
wilc_debug(N_ERR, "[wilc start]: fail write reg 0x1118 ...\n");
return ret;
}
ret = wilc->hif_func->hif_write_reg(wilc, 0xc0000, 0x71);
if (!ret) {
wilc_debug(N_ERR, "[wilc start]: fail write reg 0xc0000 ...\n");
return ret;
}
}
release_bus(wilc, RELEASE_ONLY);
return ret;
}
u32 wilc_get_chipid(struct wilc *wilc, u8 update)
{
static u32 chipid;
u32 tempchipid = 0;
u32 rfrevid;
if (chipid == 0 || update != 0) {
wilc->hif_func->hif_read_reg(wilc, 0x1000, &tempchipid);
wilc->hif_func->hif_read_reg(wilc, 0x13f4, &rfrevid);
if (!ISWILC1000(tempchipid)) {
chipid = 0;
goto _fail_;
}
if (tempchipid == 0x1002a0) {
if (rfrevid == 0x1) {
} else {
tempchipid = 0x1002a1;
}
} else if (tempchipid == 0x1002b0) {
if (rfrevid == 3) {
} else if (rfrevid == 4) {
tempchipid = 0x1002b1;
} else {
tempchipid = 0x1002b2;
}
}
chipid = tempchipid;
}
_fail_:
return chipid;
}
int wilc_wlan_init(struct net_device *dev)
{
int ret = 0;
struct wilc_vif *vif = netdev_priv(dev);
struct wilc *wilc;
wilc = vif->wilc;
PRINT_D(INIT_DBG, "Initializing WILC_Wlan ...\n");
if (!wilc->hif_func->hif_init(wilc)) {
ret = -EIO;
goto _fail_;
}
if (!wilc_wlan_cfg_init(wilc_debug)) {
ret = -ENOBUFS;
goto _fail_;
}
if (!wilc->tx_buffer)
wilc->tx_buffer = kmalloc(LINUX_TX_SIZE, GFP_KERNEL);
PRINT_D(TX_DBG, "wilc->tx_buffer = %p\n", wilc->tx_buffer);
if (!wilc->tx_buffer) {
ret = -ENOBUFS;
PRINT_ER("Can't allocate Tx Buffer");
goto _fail_;
}
if (!wilc->rx_buffer)
wilc->rx_buffer = kmalloc(LINUX_RX_SIZE, GFP_KERNEL);
PRINT_D(TX_DBG, "wilc->rx_buffer =%p\n", wilc->rx_buffer);
if (!wilc->rx_buffer) {
ret = -ENOBUFS;
PRINT_ER("Can't allocate Rx Buffer");
goto _fail_;
}
if (!init_chip(dev)) {
ret = -EIO;
goto _fail_;
}
#ifdef TCP_ACK_FILTER
init_tcp_tracking();
#endif
return 1;
_fail_:
kfree(wilc->rx_buffer);
wilc->rx_buffer = NULL;
kfree(wilc->tx_buffer);
wilc->tx_buffer = NULL;
return ret;
}
u16 wilc_set_machw_change_vir_if(struct net_device *dev, bool value)
{
u16 ret;
u32 reg;
struct wilc_vif *vif;
struct wilc *wilc;
vif = netdev_priv(dev);
wilc = vif->wilc;
mutex_lock(&wilc->hif_cs);
ret = wilc->hif_func->hif_read_reg(wilc, WILC_CHANGING_VIR_IF,
&reg);
if (!ret)
PRINT_ER("Error while Reading reg WILC_CHANGING_VIR_IF\n");
if (value)
reg |= BIT(31);
else
reg &= ~BIT(31);
ret = wilc->hif_func->hif_write_reg(wilc, WILC_CHANGING_VIR_IF,
reg);
if (!ret)
PRINT_ER("Error while writing reg WILC_CHANGING_VIR_IF\n");
mutex_unlock(&wilc->hif_cs);
return ret;
}
