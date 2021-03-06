static inline u32 rdl(struct pxa168_eth_private *pep, int offset)
{
return readl(pep->base + offset);
}
static inline void wrl(struct pxa168_eth_private *pep, int offset, u32 data)
{
writel(data, pep->base + offset);
}
static void abort_dma(struct pxa168_eth_private *pep)
{
int delay;
int max_retries = 40;
do {
wrl(pep, SDMA_CMD, SDMA_CMD_AR | SDMA_CMD_AT);
udelay(100);
delay = 10;
while ((rdl(pep, SDMA_CMD) & (SDMA_CMD_AR | SDMA_CMD_AT))
&& delay-- > 0) {
udelay(10);
}
} while (max_retries-- > 0 && delay <= 0);
if (max_retries <= 0)
printk(KERN_ERR "%s : DMA Stuck\n", __func__);
}
static int ethernet_phy_get(struct pxa168_eth_private *pep)
{
unsigned int reg_data;
reg_data = rdl(pep, PHY_ADDRESS);
return (reg_data >> (5 * pep->port_num)) & 0x1f;
}
static void ethernet_phy_set_addr(struct pxa168_eth_private *pep, int phy_addr)
{
u32 reg_data;
int addr_shift = 5 * pep->port_num;
reg_data = rdl(pep, PHY_ADDRESS);
reg_data &= ~(0x1f << addr_shift);
reg_data |= (phy_addr & 0x1f) << addr_shift;
wrl(pep, PHY_ADDRESS, reg_data);
}
static void ethernet_phy_reset(struct pxa168_eth_private *pep)
{
int data;
data = phy_read(pep->phy, MII_BMCR);
if (data < 0)
return;
data |= BMCR_RESET;
if (phy_write(pep->phy, MII_BMCR, data) < 0)
return;
do {
data = phy_read(pep->phy, MII_BMCR);
} while (data >= 0 && data & BMCR_RESET);
}
static void rxq_refill(struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
struct sk_buff *skb;
struct rx_desc *p_used_rx_desc;
int used_rx_desc;
while (pep->rx_desc_count < pep->rx_ring_size) {
int size;
skb = netdev_alloc_skb(dev, pep->skb_size);
if (!skb)
break;
if (SKB_DMA_REALIGN)
skb_reserve(skb, SKB_DMA_REALIGN);
pep->rx_desc_count++;
used_rx_desc = pep->rx_used_desc_q;
p_used_rx_desc = &pep->p_rx_desc_area[used_rx_desc];
size = skb_end_pointer(skb) - skb->data;
p_used_rx_desc->buf_ptr = dma_map_single(NULL,
skb->data,
size,
DMA_FROM_DEVICE);
p_used_rx_desc->buf_size = size;
pep->rx_skb[used_rx_desc] = skb;
wmb();
p_used_rx_desc->cmd_sts = BUF_OWNED_BY_DMA | RX_EN_INT;
wmb();
pep->rx_used_desc_q = (used_rx_desc + 1) % pep->rx_ring_size;
pep->rx_resource_err = 0;
skb_reserve(skb, ETH_HW_IP_ALIGN);
}
if (pep->rx_desc_count == 0) {
pep->timeout.expires = jiffies + (HZ / 10);
add_timer(&pep->timeout);
}
}
static inline void rxq_refill_timer_wrapper(unsigned long data)
{
struct pxa168_eth_private *pep = (void *)data;
napi_schedule(&pep->napi);
}
static inline u8 flip_8_bits(u8 x)
{
return (((x) & 0x01) << 3) | (((x) & 0x02) << 1)
| (((x) & 0x04) >> 1) | (((x) & 0x08) >> 3)
| (((x) & 0x10) << 3) | (((x) & 0x20) << 1)
| (((x) & 0x40) >> 1) | (((x) & 0x80) >> 3);
}
static void nibble_swap_every_byte(unsigned char *mac_addr)
{
int i;
for (i = 0; i < ETH_ALEN; i++) {
mac_addr[i] = ((mac_addr[i] & 0x0f) << 4) |
((mac_addr[i] & 0xf0) >> 4);
}
}
static void inverse_every_nibble(unsigned char *mac_addr)
{
int i;
for (i = 0; i < ETH_ALEN; i++)
mac_addr[i] = flip_8_bits(mac_addr[i]);
}
static u32 hash_function(unsigned char *mac_addr_orig)
{
u32 hash_result;
u32 addr0;
u32 addr1;
u32 addr2;
u32 addr3;
unsigned char mac_addr[ETH_ALEN];
memcpy(mac_addr, mac_addr_orig, ETH_ALEN);
nibble_swap_every_byte(mac_addr);
inverse_every_nibble(mac_addr);
addr0 = (mac_addr[5] >> 2) & 0x3f;
addr1 = (mac_addr[5] & 0x03) | (((mac_addr[4] & 0x7f)) << 2);
addr2 = ((mac_addr[4] & 0x80) >> 7) | mac_addr[3] << 1;
addr3 = (mac_addr[2] & 0xff) | ((mac_addr[1] & 1) << 8);
hash_result = (addr0 << 9) | (addr1 ^ addr2 ^ addr3);
hash_result = hash_result & 0x07ff;
return hash_result;
}
static int add_del_hash_entry(struct pxa168_eth_private *pep,
unsigned char *mac_addr,
u32 rd, u32 skip, int del)
{
struct addr_table_entry *entry, *start;
u32 new_high;
u32 new_low;
u32 i;
new_low = (((mac_addr[1] >> 4) & 0xf) << 15)
| (((mac_addr[1] >> 0) & 0xf) << 11)
| (((mac_addr[0] >> 4) & 0xf) << 7)
| (((mac_addr[0] >> 0) & 0xf) << 3)
| (((mac_addr[3] >> 4) & 0x1) << 31)
| (((mac_addr[3] >> 0) & 0xf) << 27)
| (((mac_addr[2] >> 4) & 0xf) << 23)
| (((mac_addr[2] >> 0) & 0xf) << 19)
| (skip << SKIP) | (rd << HASH_ENTRY_RECEIVE_DISCARD_BIT)
| HASH_ENTRY_VALID;
new_high = (((mac_addr[5] >> 4) & 0xf) << 15)
| (((mac_addr[5] >> 0) & 0xf) << 11)
| (((mac_addr[4] >> 4) & 0xf) << 7)
| (((mac_addr[4] >> 0) & 0xf) << 3)
| (((mac_addr[3] >> 5) & 0x7) << 0);
start = pep->htpr;
entry = start + hash_function(mac_addr);
for (i = 0; i < HOP_NUMBER; i++) {
if (!(le32_to_cpu(entry->lo) & HASH_ENTRY_VALID)) {
break;
} else {
if (((le32_to_cpu(entry->lo) & 0xfffffff8) ==
(new_low & 0xfffffff8)) &&
(le32_to_cpu(entry->hi) == new_high)) {
break;
}
}
if (entry == start + 0x7ff)
entry = start;
else
entry++;
}
if (((le32_to_cpu(entry->lo) & 0xfffffff8) != (new_low & 0xfffffff8)) &&
(le32_to_cpu(entry->hi) != new_high) && del)
return 0;
if (i == HOP_NUMBER) {
if (!del) {
printk(KERN_INFO "%s: table section is full, need to "
"move to 16kB implementation?\n",
__FILE__);
return -ENOSPC;
} else
return 0;
}
if (del) {
entry->hi = 0;
entry->lo = 0;
} else {
entry->hi = cpu_to_le32(new_high);
entry->lo = cpu_to_le32(new_low);
}
return 0;
}
static void update_hash_table_mac_address(struct pxa168_eth_private *pep,
unsigned char *oaddr,
unsigned char *addr)
{
if (oaddr)
add_del_hash_entry(pep, oaddr, 1, 0, HASH_DELETE);
add_del_hash_entry(pep, addr, 1, 0, HASH_ADD);
}
static int init_hash_table(struct pxa168_eth_private *pep)
{
if (pep->htpr == NULL) {
pep->htpr = dma_zalloc_coherent(pep->dev->dev.parent,
HASH_ADDR_TABLE_SIZE,
&pep->htpr_dma, GFP_KERNEL);
if (pep->htpr == NULL)
return -ENOMEM;
} else {
memset(pep->htpr, 0, HASH_ADDR_TABLE_SIZE);
}
wrl(pep, HTPR, pep->htpr_dma);
return 0;
}
static void pxa168_eth_set_rx_mode(struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
struct netdev_hw_addr *ha;
u32 val;
val = rdl(pep, PORT_CONFIG);
if (dev->flags & IFF_PROMISC)
val |= PCR_PM;
else
val &= ~PCR_PM;
wrl(pep, PORT_CONFIG, val);
memset(pep->htpr, 0, HASH_ADDR_TABLE_SIZE);
update_hash_table_mac_address(pep, NULL, dev->dev_addr);
netdev_for_each_mc_addr(ha, dev)
update_hash_table_mac_address(pep, NULL, ha->addr);
}
static int pxa168_eth_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr *sa = addr;
struct pxa168_eth_private *pep = netdev_priv(dev);
unsigned char oldMac[ETH_ALEN];
if (!is_valid_ether_addr(sa->sa_data))
return -EADDRNOTAVAIL;
memcpy(oldMac, dev->dev_addr, ETH_ALEN);
memcpy(dev->dev_addr, sa->sa_data, ETH_ALEN);
netif_addr_lock_bh(dev);
update_hash_table_mac_address(pep, oldMac, dev->dev_addr);
netif_addr_unlock_bh(dev);
return 0;
}
static void eth_port_start(struct net_device *dev)
{
unsigned int val = 0;
struct pxa168_eth_private *pep = netdev_priv(dev);
int tx_curr_desc, rx_curr_desc;
if (pep->phy != NULL) {
struct ethtool_cmd cmd;
pxa168_get_settings(pep->dev, &cmd);
ethernet_phy_reset(pep);
pxa168_set_settings(pep->dev, &cmd);
}
tx_curr_desc = pep->tx_curr_desc_q;
wrl(pep, ETH_C_TX_DESC_1,
(u32) (pep->tx_desc_dma + tx_curr_desc * sizeof(struct tx_desc)));
rx_curr_desc = pep->rx_curr_desc_q;
wrl(pep, ETH_C_RX_DESC_0,
(u32) (pep->rx_desc_dma + rx_curr_desc * sizeof(struct rx_desc)));
wrl(pep, ETH_F_RX_DESC_0,
(u32) (pep->rx_desc_dma + rx_curr_desc * sizeof(struct rx_desc)));
wrl(pep, INT_CAUSE, 0);
wrl(pep, INT_MASK, ALL_INTS);
val = rdl(pep, PORT_CONFIG);
val |= PCR_EN;
wrl(pep, PORT_CONFIG, val);
val = rdl(pep, SDMA_CMD);
val |= SDMA_CMD_ERD;
wrl(pep, SDMA_CMD, val);
}
static void eth_port_reset(struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
unsigned int val = 0;
wrl(pep, INT_MASK, 0);
wrl(pep, INT_CAUSE, 0);
val = rdl(pep, SDMA_CMD);
val &= ~SDMA_CMD_ERD;
abort_dma(pep);
val = rdl(pep, PORT_CONFIG);
val &= ~PCR_EN;
wrl(pep, PORT_CONFIG, val);
}
static int txq_reclaim(struct net_device *dev, int force)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
struct tx_desc *desc;
u32 cmd_sts;
struct sk_buff *skb;
int tx_index;
dma_addr_t addr;
int count;
int released = 0;
netif_tx_lock(dev);
pep->work_todo &= ~WORK_TX_DONE;
while (pep->tx_desc_count > 0) {
tx_index = pep->tx_used_desc_q;
desc = &pep->p_tx_desc_area[tx_index];
cmd_sts = desc->cmd_sts;
if (!force && (cmd_sts & BUF_OWNED_BY_DMA)) {
if (released > 0) {
goto txq_reclaim_end;
} else {
released = -1;
goto txq_reclaim_end;
}
}
pep->tx_used_desc_q = (tx_index + 1) % pep->tx_ring_size;
pep->tx_desc_count--;
addr = desc->buf_ptr;
count = desc->byte_cnt;
skb = pep->tx_skb[tx_index];
if (skb)
pep->tx_skb[tx_index] = NULL;
if (cmd_sts & TX_ERROR) {
if (net_ratelimit())
printk(KERN_ERR "%s: Error in TX\n", dev->name);
dev->stats.tx_errors++;
}
dma_unmap_single(NULL, addr, count, DMA_TO_DEVICE);
if (skb)
dev_kfree_skb_irq(skb);
released++;
}
txq_reclaim_end:
netif_tx_unlock(dev);
return released;
}
static void pxa168_eth_tx_timeout(struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
printk(KERN_INFO "%s: TX timeout desc_count %d\n",
dev->name, pep->tx_desc_count);
schedule_work(&pep->tx_timeout_task);
}
static void pxa168_eth_tx_timeout_task(struct work_struct *work)
{
struct pxa168_eth_private *pep = container_of(work,
struct pxa168_eth_private,
tx_timeout_task);
struct net_device *dev = pep->dev;
pxa168_eth_stop(dev);
pxa168_eth_open(dev);
}
static int rxq_process(struct net_device *dev, int budget)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
unsigned int received_packets = 0;
struct sk_buff *skb;
while (budget-- > 0) {
int rx_next_curr_desc, rx_curr_desc, rx_used_desc;
struct rx_desc *rx_desc;
unsigned int cmd_sts;
if (pep->rx_resource_err)
break;
rx_curr_desc = pep->rx_curr_desc_q;
rx_used_desc = pep->rx_used_desc_q;
rx_desc = &pep->p_rx_desc_area[rx_curr_desc];
cmd_sts = rx_desc->cmd_sts;
rmb();
if (cmd_sts & (BUF_OWNED_BY_DMA))
break;
skb = pep->rx_skb[rx_curr_desc];
pep->rx_skb[rx_curr_desc] = NULL;
rx_next_curr_desc = (rx_curr_desc + 1) % pep->rx_ring_size;
pep->rx_curr_desc_q = rx_next_curr_desc;
if (rx_next_curr_desc == rx_used_desc)
pep->rx_resource_err = 1;
pep->rx_desc_count--;
dma_unmap_single(NULL, rx_desc->buf_ptr,
rx_desc->buf_size,
DMA_FROM_DEVICE);
received_packets++;
stats->rx_packets++;
stats->rx_bytes += rx_desc->byte_cnt;
if (((cmd_sts & (RX_FIRST_DESC | RX_LAST_DESC)) !=
(RX_FIRST_DESC | RX_LAST_DESC))
|| (cmd_sts & RX_ERROR)) {
stats->rx_dropped++;
if ((cmd_sts & (RX_FIRST_DESC | RX_LAST_DESC)) !=
(RX_FIRST_DESC | RX_LAST_DESC)) {
if (net_ratelimit())
printk(KERN_ERR
"%s: Rx pkt on multiple desc\n",
dev->name);
}
if (cmd_sts & RX_ERROR)
stats->rx_errors++;
dev_kfree_skb_irq(skb);
} else {
skb_put(skb, rx_desc->byte_cnt - 4);
skb->protocol = eth_type_trans(skb, dev);
netif_receive_skb(skb);
}
}
rxq_refill(dev);
return received_packets;
}
static int pxa168_eth_collect_events(struct pxa168_eth_private *pep,
struct net_device *dev)
{
u32 icr;
int ret = 0;
icr = rdl(pep, INT_CAUSE);
if (icr == 0)
return IRQ_NONE;
wrl(pep, INT_CAUSE, ~icr);
if (icr & (ICR_TXBUF_H | ICR_TXBUF_L)) {
pep->work_todo |= WORK_TX_DONE;
ret = 1;
}
if (icr & ICR_RXBUF)
ret = 1;
if (icr & ICR_MII_CH) {
pep->work_todo |= WORK_LINK;
ret = 1;
}
return ret;
}
static void handle_link_event(struct pxa168_eth_private *pep)
{
struct net_device *dev = pep->dev;
u32 port_status;
int speed;
int duplex;
int fc;
port_status = rdl(pep, PORT_STATUS);
if (!(port_status & LINK_UP)) {
if (netif_carrier_ok(dev)) {
printk(KERN_INFO "%s: link down\n", dev->name);
netif_carrier_off(dev);
txq_reclaim(dev, 1);
}
return;
}
if (port_status & PORT_SPEED_100)
speed = 100;
else
speed = 10;
duplex = (port_status & FULL_DUPLEX) ? 1 : 0;
fc = (port_status & FLOW_CONTROL_ENABLED) ? 1 : 0;
printk(KERN_INFO "%s: link up, %d Mb/s, %s duplex, "
"flow control %sabled\n", dev->name,
speed, duplex ? "full" : "half", fc ? "en" : "dis");
if (!netif_carrier_ok(dev))
netif_carrier_on(dev);
}
static irqreturn_t pxa168_eth_int_handler(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct pxa168_eth_private *pep = netdev_priv(dev);
if (unlikely(!pxa168_eth_collect_events(pep, dev)))
return IRQ_NONE;
wrl(pep, INT_MASK, 0);
napi_schedule(&pep->napi);
return IRQ_HANDLED;
}
static void pxa168_eth_recalc_skb_size(struct pxa168_eth_private *pep)
{
int skb_size;
skb_size = pep->dev->mtu + 36;
pep->skb_size = (skb_size + 7) & ~7;
pep->skb_size += SKB_DMA_REALIGN;
}
static int set_port_config_ext(struct pxa168_eth_private *pep)
{
int skb_size;
pxa168_eth_recalc_skb_size(pep);
if (pep->skb_size <= 1518)
skb_size = PCXR_MFL_1518;
else if (pep->skb_size <= 1536)
skb_size = PCXR_MFL_1536;
else if (pep->skb_size <= 2048)
skb_size = PCXR_MFL_2048;
else
skb_size = PCXR_MFL_64K;
wrl(pep,
PORT_CONFIG_EXT, PCXR_2BSM |
PCXR_DSCP_EN |
skb_size | PCXR_FLP |
PCXR_TX_HIGH_PRI);
return 0;
}
static int pxa168_init_hw(struct pxa168_eth_private *pep)
{
int err = 0;
wrl(pep, INT_MASK, 0);
wrl(pep, INT_CAUSE, 0);
wrl(pep, INT_W_CLEAR, 0);
abort_dma(pep);
err = init_hash_table(pep);
if (err)
return err;
wrl(pep, SDMA_CONFIG, SDCR_BSZ8 |
SDCR_RIFB |
SDCR_BLMT |
SDCR_BLMR |
SDCR_RC_MAX_RETRANS);
wrl(pep, PORT_CONFIG, PCR_HS);
set_port_config_ext(pep);
return err;
}
static int rxq_init(struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
struct rx_desc *p_rx_desc;
int size = 0, i = 0;
int rx_desc_num = pep->rx_ring_size;
pep->rx_skb = kzalloc(sizeof(*pep->rx_skb) * pep->rx_ring_size,
GFP_KERNEL);
if (!pep->rx_skb)
return -ENOMEM;
pep->rx_desc_count = 0;
size = pep->rx_ring_size * sizeof(struct rx_desc);
pep->rx_desc_area_size = size;
pep->p_rx_desc_area = dma_zalloc_coherent(pep->dev->dev.parent, size,
&pep->rx_desc_dma,
GFP_KERNEL);
if (!pep->p_rx_desc_area)
goto out;
p_rx_desc = pep->p_rx_desc_area;
for (i = 0; i < rx_desc_num; i++) {
p_rx_desc[i].next_desc_ptr = pep->rx_desc_dma +
((i + 1) % rx_desc_num) * sizeof(struct rx_desc);
}
pep->rx_curr_desc_q = 0;
pep->rx_used_desc_q = 0;
pep->rx_desc_area_size = rx_desc_num * sizeof(struct rx_desc);
return 0;
out:
kfree(pep->rx_skb);
return -ENOMEM;
}
static void rxq_deinit(struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
int curr;
for (curr = 0; pep->rx_desc_count && curr < pep->rx_ring_size; curr++) {
if (pep->rx_skb[curr]) {
dev_kfree_skb(pep->rx_skb[curr]);
pep->rx_desc_count--;
}
}
if (pep->rx_desc_count)
printk(KERN_ERR
"Error in freeing Rx Ring. %d skb's still\n",
pep->rx_desc_count);
if (pep->p_rx_desc_area)
dma_free_coherent(pep->dev->dev.parent, pep->rx_desc_area_size,
pep->p_rx_desc_area, pep->rx_desc_dma);
kfree(pep->rx_skb);
}
static int txq_init(struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
struct tx_desc *p_tx_desc;
int size = 0, i = 0;
int tx_desc_num = pep->tx_ring_size;
pep->tx_skb = kzalloc(sizeof(*pep->tx_skb) * pep->tx_ring_size,
GFP_KERNEL);
if (!pep->tx_skb)
return -ENOMEM;
pep->tx_desc_count = 0;
size = pep->tx_ring_size * sizeof(struct tx_desc);
pep->tx_desc_area_size = size;
pep->p_tx_desc_area = dma_zalloc_coherent(pep->dev->dev.parent, size,
&pep->tx_desc_dma,
GFP_KERNEL);
if (!pep->p_tx_desc_area)
goto out;
p_tx_desc = pep->p_tx_desc_area;
for (i = 0; i < tx_desc_num; i++) {
p_tx_desc[i].next_desc_ptr = pep->tx_desc_dma +
((i + 1) % tx_desc_num) * sizeof(struct tx_desc);
}
pep->tx_curr_desc_q = 0;
pep->tx_used_desc_q = 0;
pep->tx_desc_area_size = tx_desc_num * sizeof(struct tx_desc);
return 0;
out:
kfree(pep->tx_skb);
return -ENOMEM;
}
static void txq_deinit(struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
txq_reclaim(dev, 1);
BUG_ON(pep->tx_used_desc_q != pep->tx_curr_desc_q);
if (pep->p_tx_desc_area)
dma_free_coherent(pep->dev->dev.parent, pep->tx_desc_area_size,
pep->p_tx_desc_area, pep->tx_desc_dma);
kfree(pep->tx_skb);
}
static int pxa168_eth_open(struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
int err;
err = request_irq(dev->irq, pxa168_eth_int_handler, 0, dev->name, dev);
if (err) {
dev_err(&dev->dev, "can't assign irq\n");
return -EAGAIN;
}
pep->rx_resource_err = 0;
err = rxq_init(dev);
if (err != 0)
goto out_free_irq;
err = txq_init(dev);
if (err != 0)
goto out_free_rx_skb;
pep->rx_used_desc_q = 0;
pep->rx_curr_desc_q = 0;
rxq_refill(dev);
pep->rx_used_desc_q = 0;
pep->rx_curr_desc_q = 0;
netif_carrier_off(dev);
eth_port_start(dev);
napi_enable(&pep->napi);
return 0;
out_free_rx_skb:
rxq_deinit(dev);
out_free_irq:
free_irq(dev->irq, dev);
return err;
}
static int pxa168_eth_stop(struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
eth_port_reset(dev);
wrl(pep, INT_MASK, 0);
wrl(pep, INT_CAUSE, 0);
wrl(pep, INT_W_CLEAR, 0);
napi_disable(&pep->napi);
del_timer_sync(&pep->timeout);
netif_carrier_off(dev);
free_irq(dev->irq, dev);
rxq_deinit(dev);
txq_deinit(dev);
return 0;
}
static int pxa168_eth_change_mtu(struct net_device *dev, int mtu)
{
int retval;
struct pxa168_eth_private *pep = netdev_priv(dev);
if ((mtu > 9500) || (mtu < 68))
return -EINVAL;
dev->mtu = mtu;
retval = set_port_config_ext(pep);
if (!netif_running(dev))
return 0;
pxa168_eth_stop(dev);
if (pxa168_eth_open(dev)) {
dev_err(&dev->dev,
"fatal error on re-opening device after MTU change\n");
}
return 0;
}
static int eth_alloc_tx_desc_index(struct pxa168_eth_private *pep)
{
int tx_desc_curr;
tx_desc_curr = pep->tx_curr_desc_q;
pep->tx_curr_desc_q = (tx_desc_curr + 1) % pep->tx_ring_size;
BUG_ON(pep->tx_curr_desc_q == pep->tx_used_desc_q);
pep->tx_desc_count++;
return tx_desc_curr;
}
static int pxa168_rx_poll(struct napi_struct *napi, int budget)
{
struct pxa168_eth_private *pep =
container_of(napi, struct pxa168_eth_private, napi);
struct net_device *dev = pep->dev;
int work_done = 0;
if (unlikely(pep->work_todo & WORK_LINK)) {
pep->work_todo &= ~(WORK_LINK);
handle_link_event(pep);
}
txq_reclaim(dev, 0);
if (netif_queue_stopped(dev)
&& pep->tx_ring_size - pep->tx_desc_count > 1) {
netif_wake_queue(dev);
}
work_done = rxq_process(dev, budget);
if (work_done < budget) {
napi_complete(napi);
wrl(pep, INT_MASK, ALL_INTS);
}
return work_done;
}
static int pxa168_eth_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct tx_desc *desc;
int tx_index;
int length;
tx_index = eth_alloc_tx_desc_index(pep);
desc = &pep->p_tx_desc_area[tx_index];
length = skb->len;
pep->tx_skb[tx_index] = skb;
desc->byte_cnt = length;
desc->buf_ptr = dma_map_single(NULL, skb->data, length, DMA_TO_DEVICE);
skb_tx_timestamp(skb);
wmb();
desc->cmd_sts = BUF_OWNED_BY_DMA | TX_GEN_CRC | TX_FIRST_DESC |
TX_ZERO_PADDING | TX_LAST_DESC | TX_EN_INT;
wmb();
wrl(pep, SDMA_CMD, SDMA_CMD_TXDH | SDMA_CMD_ERD);
stats->tx_bytes += length;
stats->tx_packets++;
dev->trans_start = jiffies;
if (pep->tx_ring_size - pep->tx_desc_count <= 1) {
netif_stop_queue(dev);
}
return NETDEV_TX_OK;
}
static int smi_wait_ready(struct pxa168_eth_private *pep)
{
int i = 0;
for (i = 0; rdl(pep, SMI) & SMI_BUSY; i++) {
if (i == PHY_WAIT_ITERATIONS)
return -ETIMEDOUT;
msleep(10);
}
return 0;
}
static int pxa168_smi_read(struct mii_bus *bus, int phy_addr, int regnum)
{
struct pxa168_eth_private *pep = bus->priv;
int i = 0;
int val;
if (smi_wait_ready(pep)) {
printk(KERN_WARNING "pxa168_eth: SMI bus busy timeout\n");
return -ETIMEDOUT;
}
wrl(pep, SMI, (phy_addr << 16) | (regnum << 21) | SMI_OP_R);
for (i = 0; !((val = rdl(pep, SMI)) & SMI_R_VALID); i++) {
if (i == PHY_WAIT_ITERATIONS) {
printk(KERN_WARNING
"pxa168_eth: SMI bus read not valid\n");
return -ENODEV;
}
msleep(10);
}
return val & 0xffff;
}
static int pxa168_smi_write(struct mii_bus *bus, int phy_addr, int regnum,
u16 value)
{
struct pxa168_eth_private *pep = bus->priv;
if (smi_wait_ready(pep)) {
printk(KERN_WARNING "pxa168_eth: SMI bus busy timeout\n");
return -ETIMEDOUT;
}
wrl(pep, SMI, (phy_addr << 16) | (regnum << 21) |
SMI_OP_W | (value & 0xffff));
if (smi_wait_ready(pep)) {
printk(KERN_ERR "pxa168_eth: SMI bus busy timeout\n");
return -ETIMEDOUT;
}
return 0;
}
static int pxa168_eth_do_ioctl(struct net_device *dev, struct ifreq *ifr,
int cmd)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
if (pep->phy != NULL)
return phy_mii_ioctl(pep->phy, ifr, cmd);
return -EOPNOTSUPP;
}
static struct phy_device *phy_scan(struct pxa168_eth_private *pep, int phy_addr)
{
struct mii_bus *bus = pep->smi_bus;
struct phy_device *phydev;
int start;
int num;
int i;
if (phy_addr == PXA168_ETH_PHY_ADDR_DEFAULT) {
start = ethernet_phy_get(pep);
num = 32;
} else {
start = phy_addr & 0x1f;
num = 1;
}
phydev = NULL;
for (i = 0; i < num; i++) {
int addr = (start + i) & 0x1f;
if (bus->phy_map[addr] == NULL)
mdiobus_scan(bus, addr);
if (phydev == NULL) {
phydev = bus->phy_map[addr];
if (phydev != NULL)
ethernet_phy_set_addr(pep, addr);
}
}
return phydev;
}
static void phy_init(struct pxa168_eth_private *pep, int speed, int duplex)
{
struct phy_device *phy = pep->phy;
ethernet_phy_reset(pep);
phy_attach(pep->dev, dev_name(&phy->dev), PHY_INTERFACE_MODE_MII);
if (speed == 0) {
phy->autoneg = AUTONEG_ENABLE;
phy->speed = 0;
phy->duplex = 0;
phy->supported &= PHY_BASIC_FEATURES;
phy->advertising = phy->supported | ADVERTISED_Autoneg;
} else {
phy->autoneg = AUTONEG_DISABLE;
phy->advertising = 0;
phy->speed = speed;
phy->duplex = duplex;
}
phy_start_aneg(phy);
}
static int ethernet_phy_setup(struct net_device *dev)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
if (pep->pd->init)
pep->pd->init();
pep->phy = phy_scan(pep, pep->pd->phy_addr & 0x1f);
if (pep->phy != NULL)
phy_init(pep, pep->pd->speed, pep->pd->duplex);
update_hash_table_mac_address(pep, NULL, dev->dev_addr);
return 0;
}
static int pxa168_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
int err;
err = phy_read_status(pep->phy);
if (err == 0)
err = phy_ethtool_gset(pep->phy, cmd);
return err;
}
static int pxa168_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct pxa168_eth_private *pep = netdev_priv(dev);
return phy_ethtool_sset(pep->phy, cmd);
}
static void pxa168_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRIVER_NAME, sizeof(info->driver));
strlcpy(info->version, DRIVER_VERSION, sizeof(info->version));
strlcpy(info->fw_version, "N/A", sizeof(info->fw_version));
strlcpy(info->bus_info, "N/A", sizeof(info->bus_info));
}
static int pxa168_eth_probe(struct platform_device *pdev)
{
struct pxa168_eth_private *pep = NULL;
struct net_device *dev = NULL;
struct resource *res;
struct clk *clk;
int err;
printk(KERN_NOTICE "PXA168 10/100 Ethernet Driver\n");
clk = clk_get(&pdev->dev, "MFUCLK");
if (IS_ERR(clk)) {
printk(KERN_ERR "%s: Fast Ethernet failed to get clock\n",
DRIVER_NAME);
return -ENODEV;
}
clk_enable(clk);
dev = alloc_etherdev(sizeof(struct pxa168_eth_private));
if (!dev) {
err = -ENOMEM;
goto err_clk;
}
platform_set_drvdata(pdev, dev);
pep = netdev_priv(dev);
pep->dev = dev;
pep->clk = clk;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
err = -ENODEV;
goto err_netdev;
}
pep->base = ioremap(res->start, resource_size(res));
if (pep->base == NULL) {
err = -ENOMEM;
goto err_netdev;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
BUG_ON(!res);
dev->irq = res->start;
dev->netdev_ops = &pxa168_eth_netdev_ops;
dev->watchdog_timeo = 2 * HZ;
dev->base_addr = 0;
SET_ETHTOOL_OPS(dev, &pxa168_ethtool_ops);
INIT_WORK(&pep->tx_timeout_task, pxa168_eth_tx_timeout_task);
printk(KERN_INFO "%s:Using random mac address\n", DRIVER_NAME);
eth_hw_addr_random(dev);
pep->pd = dev_get_platdata(&pdev->dev);
pep->rx_ring_size = NUM_RX_DESCS;
if (pep->pd->rx_queue_size)
pep->rx_ring_size = pep->pd->rx_queue_size;
pep->tx_ring_size = NUM_TX_DESCS;
if (pep->pd->tx_queue_size)
pep->tx_ring_size = pep->pd->tx_queue_size;
pep->port_num = pep->pd->port_number;
BUG_ON(pep->port_num > 2);
netif_napi_add(dev, &pep->napi, pxa168_rx_poll, pep->rx_ring_size);
memset(&pep->timeout, 0, sizeof(struct timer_list));
init_timer(&pep->timeout);
pep->timeout.function = rxq_refill_timer_wrapper;
pep->timeout.data = (unsigned long)pep;
pep->smi_bus = mdiobus_alloc();
if (pep->smi_bus == NULL) {
err = -ENOMEM;
goto err_base;
}
pep->smi_bus->priv = pep;
pep->smi_bus->name = "pxa168_eth smi";
pep->smi_bus->read = pxa168_smi_read;
pep->smi_bus->write = pxa168_smi_write;
snprintf(pep->smi_bus->id, MII_BUS_ID_SIZE, "%s-%d",
pdev->name, pdev->id);
pep->smi_bus->parent = &pdev->dev;
pep->smi_bus->phy_mask = 0xffffffff;
err = mdiobus_register(pep->smi_bus);
if (err)
goto err_free_mdio;
pxa168_init_hw(pep);
err = ethernet_phy_setup(dev);
if (err)
goto err_mdiobus;
SET_NETDEV_DEV(dev, &pdev->dev);
err = register_netdev(dev);
if (err)
goto err_mdiobus;
return 0;
err_mdiobus:
mdiobus_unregister(pep->smi_bus);
err_free_mdio:
mdiobus_free(pep->smi_bus);
err_base:
iounmap(pep->base);
err_netdev:
free_netdev(dev);
err_clk:
clk_disable(clk);
clk_put(clk);
return err;
}
static int pxa168_eth_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct pxa168_eth_private *pep = netdev_priv(dev);
if (pep->htpr) {
dma_free_coherent(pep->dev->dev.parent, HASH_ADDR_TABLE_SIZE,
pep->htpr, pep->htpr_dma);
pep->htpr = NULL;
}
if (pep->clk) {
clk_disable(pep->clk);
clk_put(pep->clk);
pep->clk = NULL;
}
if (pep->phy != NULL)
phy_detach(pep->phy);
iounmap(pep->base);
pep->base = NULL;
mdiobus_unregister(pep->smi_bus);
mdiobus_free(pep->smi_bus);
unregister_netdev(dev);
cancel_work_sync(&pep->tx_timeout_task);
free_netdev(dev);
return 0;
}
static void pxa168_eth_shutdown(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
eth_port_reset(dev);
}
static int pxa168_eth_resume(struct platform_device *pdev)
{
return -ENOSYS;
}
static int pxa168_eth_suspend(struct platform_device *pdev, pm_message_t state)
{
return -ENOSYS;
}
