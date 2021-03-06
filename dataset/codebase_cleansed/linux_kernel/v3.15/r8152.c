static
int get_registers(struct r8152 *tp, u16 value, u16 index, u16 size, void *data)
{
int ret;
void *tmp;
tmp = kmalloc(size, GFP_KERNEL);
if (!tmp)
return -ENOMEM;
ret = usb_control_msg(tp->udev, usb_rcvctrlpipe(tp->udev, 0),
RTL8152_REQ_GET_REGS, RTL8152_REQT_READ,
value, index, tmp, size, 500);
memcpy(data, tmp, size);
kfree(tmp);
return ret;
}
static
int set_registers(struct r8152 *tp, u16 value, u16 index, u16 size, void *data)
{
int ret;
void *tmp;
tmp = kmalloc(size, GFP_KERNEL);
if (!tmp)
return -ENOMEM;
memcpy(tmp, data, size);
ret = usb_control_msg(tp->udev, usb_sndctrlpipe(tp->udev, 0),
RTL8152_REQ_SET_REGS, RTL8152_REQT_WRITE,
value, index, tmp, size, 500);
kfree(tmp);
return ret;
}
static int generic_ocp_read(struct r8152 *tp, u16 index, u16 size,
void *data, u16 type)
{
u16 limit = 64;
int ret = 0;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return -ENODEV;
if ((size & 3) || !size || (index & 3) || !data)
return -EPERM;
if ((u32)index + (u32)size > 0xffff)
return -EPERM;
while (size) {
if (size > limit) {
ret = get_registers(tp, index, type, limit, data);
if (ret < 0)
break;
index += limit;
data += limit;
size -= limit;
} else {
ret = get_registers(tp, index, type, size, data);
if (ret < 0)
break;
index += size;
data += size;
size = 0;
break;
}
}
return ret;
}
static int generic_ocp_write(struct r8152 *tp, u16 index, u16 byteen,
u16 size, void *data, u16 type)
{
int ret;
u16 byteen_start, byteen_end, byen;
u16 limit = 512;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return -ENODEV;
if ((size & 3) || !size || (index & 3) || !data)
return -EPERM;
if ((u32)index + (u32)size > 0xffff)
return -EPERM;
byteen_start = byteen & BYTE_EN_START_MASK;
byteen_end = byteen & BYTE_EN_END_MASK;
byen = byteen_start | (byteen_start << 4);
ret = set_registers(tp, index, type | byen, 4, data);
if (ret < 0)
goto error1;
index += 4;
data += 4;
size -= 4;
if (size) {
size -= 4;
while (size) {
if (size > limit) {
ret = set_registers(tp, index,
type | BYTE_EN_DWORD,
limit, data);
if (ret < 0)
goto error1;
index += limit;
data += limit;
size -= limit;
} else {
ret = set_registers(tp, index,
type | BYTE_EN_DWORD,
size, data);
if (ret < 0)
goto error1;
index += size;
data += size;
size = 0;
break;
}
}
byen = byteen_end | (byteen_end >> 4);
ret = set_registers(tp, index, type | byen, 4, data);
if (ret < 0)
goto error1;
}
error1:
return ret;
}
static inline
int pla_ocp_read(struct r8152 *tp, u16 index, u16 size, void *data)
{
return generic_ocp_read(tp, index, size, data, MCU_TYPE_PLA);
}
static inline
int pla_ocp_write(struct r8152 *tp, u16 index, u16 byteen, u16 size, void *data)
{
return generic_ocp_write(tp, index, byteen, size, data, MCU_TYPE_PLA);
}
static inline
int usb_ocp_read(struct r8152 *tp, u16 index, u16 size, void *data)
{
return generic_ocp_read(tp, index, size, data, MCU_TYPE_USB);
}
static inline
int usb_ocp_write(struct r8152 *tp, u16 index, u16 byteen, u16 size, void *data)
{
return generic_ocp_write(tp, index, byteen, size, data, MCU_TYPE_USB);
}
static u32 ocp_read_dword(struct r8152 *tp, u16 type, u16 index)
{
__le32 data;
generic_ocp_read(tp, index, sizeof(data), &data, type);
return __le32_to_cpu(data);
}
static void ocp_write_dword(struct r8152 *tp, u16 type, u16 index, u32 data)
{
__le32 tmp = __cpu_to_le32(data);
generic_ocp_write(tp, index, BYTE_EN_DWORD, sizeof(tmp), &tmp, type);
}
static u16 ocp_read_word(struct r8152 *tp, u16 type, u16 index)
{
u32 data;
__le32 tmp;
u8 shift = index & 2;
index &= ~3;
generic_ocp_read(tp, index, sizeof(tmp), &tmp, type);
data = __le32_to_cpu(tmp);
data >>= (shift * 8);
data &= 0xffff;
return (u16)data;
}
static void ocp_write_word(struct r8152 *tp, u16 type, u16 index, u32 data)
{
u32 mask = 0xffff;
__le32 tmp;
u16 byen = BYTE_EN_WORD;
u8 shift = index & 2;
data &= mask;
if (index & 2) {
byen <<= shift;
mask <<= (shift * 8);
data <<= (shift * 8);
index &= ~3;
}
generic_ocp_read(tp, index, sizeof(tmp), &tmp, type);
data |= __le32_to_cpu(tmp) & ~mask;
tmp = __cpu_to_le32(data);
generic_ocp_write(tp, index, byen, sizeof(tmp), &tmp, type);
}
static u8 ocp_read_byte(struct r8152 *tp, u16 type, u16 index)
{
u32 data;
__le32 tmp;
u8 shift = index & 3;
index &= ~3;
generic_ocp_read(tp, index, sizeof(tmp), &tmp, type);
data = __le32_to_cpu(tmp);
data >>= (shift * 8);
data &= 0xff;
return (u8)data;
}
static void ocp_write_byte(struct r8152 *tp, u16 type, u16 index, u32 data)
{
u32 mask = 0xff;
__le32 tmp;
u16 byen = BYTE_EN_BYTE;
u8 shift = index & 3;
data &= mask;
if (index & 3) {
byen <<= shift;
mask <<= (shift * 8);
data <<= (shift * 8);
index &= ~3;
}
generic_ocp_read(tp, index, sizeof(tmp), &tmp, type);
data |= __le32_to_cpu(tmp) & ~mask;
tmp = __cpu_to_le32(data);
generic_ocp_write(tp, index, byen, sizeof(tmp), &tmp, type);
}
static u16 ocp_reg_read(struct r8152 *tp, u16 addr)
{
u16 ocp_base, ocp_index;
ocp_base = addr & 0xf000;
if (ocp_base != tp->ocp_base) {
ocp_write_word(tp, MCU_TYPE_PLA, PLA_OCP_GPHY_BASE, ocp_base);
tp->ocp_base = ocp_base;
}
ocp_index = (addr & 0x0fff) | 0xb000;
return ocp_read_word(tp, MCU_TYPE_PLA, ocp_index);
}
static void ocp_reg_write(struct r8152 *tp, u16 addr, u16 data)
{
u16 ocp_base, ocp_index;
ocp_base = addr & 0xf000;
if (ocp_base != tp->ocp_base) {
ocp_write_word(tp, MCU_TYPE_PLA, PLA_OCP_GPHY_BASE, ocp_base);
tp->ocp_base = ocp_base;
}
ocp_index = (addr & 0x0fff) | 0xb000;
ocp_write_word(tp, MCU_TYPE_PLA, ocp_index, data);
}
static inline void r8152_mdio_write(struct r8152 *tp, u32 reg_addr, u32 value)
{
ocp_reg_write(tp, OCP_BASE_MII + reg_addr * 2, value);
}
static inline int r8152_mdio_read(struct r8152 *tp, u32 reg_addr)
{
return ocp_reg_read(tp, OCP_BASE_MII + reg_addr * 2);
}
static void sram_write(struct r8152 *tp, u16 addr, u16 data)
{
ocp_reg_write(tp, OCP_SRAM_ADDR, addr);
ocp_reg_write(tp, OCP_SRAM_DATA, data);
}
static u16 sram_read(struct r8152 *tp, u16 addr)
{
ocp_reg_write(tp, OCP_SRAM_ADDR, addr);
return ocp_reg_read(tp, OCP_SRAM_DATA);
}
static int read_mii_word(struct net_device *netdev, int phy_id, int reg)
{
struct r8152 *tp = netdev_priv(netdev);
int ret;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return -ENODEV;
if (phy_id != R8152_PHY_ID)
return -EINVAL;
ret = usb_autopm_get_interface(tp->intf);
if (ret < 0)
goto out;
ret = r8152_mdio_read(tp, reg);
usb_autopm_put_interface(tp->intf);
out:
return ret;
}
static
void write_mii_word(struct net_device *netdev, int phy_id, int reg, int val)
{
struct r8152 *tp = netdev_priv(netdev);
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return;
if (phy_id != R8152_PHY_ID)
return;
if (usb_autopm_get_interface(tp->intf) < 0)
return;
r8152_mdio_write(tp, reg, val);
usb_autopm_put_interface(tp->intf);
}
static inline void set_ethernet_addr(struct r8152 *tp)
{
struct net_device *dev = tp->netdev;
int ret;
u8 node_id[8] = {0};
if (tp->version == RTL_VER_01)
ret = pla_ocp_read(tp, PLA_IDR, sizeof(node_id), node_id);
else
ret = pla_ocp_read(tp, PLA_BACKUP, sizeof(node_id), node_id);
if (ret < 0) {
netif_notice(tp, probe, dev, "inet addr fail\n");
} else {
if (tp->version != RTL_VER_01) {
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CRWECR,
CRWECR_CONFIG);
pla_ocp_write(tp, PLA_IDR, BYTE_EN_SIX_BYTES,
sizeof(node_id), node_id);
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CRWECR,
CRWECR_NORAML);
}
memcpy(dev->dev_addr, node_id, dev->addr_len);
memcpy(dev->perm_addr, dev->dev_addr, dev->addr_len);
}
}
static int rtl8152_set_mac_address(struct net_device *netdev, void *p)
{
struct r8152 *tp = netdev_priv(netdev);
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CRWECR, CRWECR_CONFIG);
pla_ocp_write(tp, PLA_IDR, BYTE_EN_SIX_BYTES, 8, addr->sa_data);
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CRWECR, CRWECR_NORAML);
return 0;
}
static void read_bulk_callback(struct urb *urb)
{
struct net_device *netdev;
int status = urb->status;
struct rx_agg *agg;
struct r8152 *tp;
int result;
agg = urb->context;
if (!agg)
return;
tp = agg->context;
if (!tp)
return;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return;
if (!test_bit(WORK_ENABLE, &tp->flags))
return;
netdev = tp->netdev;
if (!netif_carrier_ok(netdev))
return;
usb_mark_last_busy(tp->udev);
switch (status) {
case 0:
if (urb->actual_length < ETH_ZLEN)
break;
spin_lock(&tp->rx_lock);
list_add_tail(&agg->list, &tp->rx_done);
spin_unlock(&tp->rx_lock);
tasklet_schedule(&tp->tl);
return;
case -ESHUTDOWN:
set_bit(RTL8152_UNPLUG, &tp->flags);
netif_device_detach(tp->netdev);
return;
case -ENOENT:
return;
case -ETIME:
if (net_ratelimit())
netdev_warn(netdev, "maybe reset is needed?\n");
break;
default:
if (net_ratelimit())
netdev_warn(netdev, "Rx status %d\n", status);
break;
}
result = r8152_submit_rx(tp, agg, GFP_ATOMIC);
if (result == -ENODEV) {
netif_device_detach(tp->netdev);
} else if (result) {
spin_lock(&tp->rx_lock);
list_add_tail(&agg->list, &tp->rx_done);
spin_unlock(&tp->rx_lock);
tasklet_schedule(&tp->tl);
}
}
static void write_bulk_callback(struct urb *urb)
{
struct net_device_stats *stats;
struct net_device *netdev;
struct tx_agg *agg;
struct r8152 *tp;
int status = urb->status;
agg = urb->context;
if (!agg)
return;
tp = agg->context;
if (!tp)
return;
netdev = tp->netdev;
stats = &netdev->stats;
if (status) {
if (net_ratelimit())
netdev_warn(netdev, "Tx status %d\n", status);
stats->tx_errors += agg->skb_num;
} else {
stats->tx_packets += agg->skb_num;
stats->tx_bytes += agg->skb_len;
}
spin_lock(&tp->tx_lock);
list_add_tail(&agg->list, &tp->tx_free);
spin_unlock(&tp->tx_lock);
usb_autopm_put_interface_async(tp->intf);
if (!netif_carrier_ok(netdev))
return;
if (!test_bit(WORK_ENABLE, &tp->flags))
return;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return;
if (!skb_queue_empty(&tp->tx_queue))
tasklet_schedule(&tp->tl);
}
static void intr_callback(struct urb *urb)
{
struct r8152 *tp;
__le16 *d;
int status = urb->status;
int res;
tp = urb->context;
if (!tp)
return;
if (!test_bit(WORK_ENABLE, &tp->flags))
return;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ESHUTDOWN:
netif_device_detach(tp->netdev);
case -ENOENT:
return;
case -EOVERFLOW:
netif_info(tp, intr, tp->netdev, "intr status -EOVERFLOW\n");
goto resubmit;
default:
netif_info(tp, intr, tp->netdev, "intr status %d\n", status);
goto resubmit;
}
d = urb->transfer_buffer;
if (INTR_LINK & __le16_to_cpu(d[0])) {
if (!(tp->speed & LINK_STATUS)) {
set_bit(RTL8152_LINK_CHG, &tp->flags);
schedule_delayed_work(&tp->schedule, 0);
}
} else {
if (tp->speed & LINK_STATUS) {
set_bit(RTL8152_LINK_CHG, &tp->flags);
schedule_delayed_work(&tp->schedule, 0);
}
}
resubmit:
res = usb_submit_urb(urb, GFP_ATOMIC);
if (res == -ENODEV)
netif_device_detach(tp->netdev);
else if (res)
netif_err(tp, intr, tp->netdev,
"can't resubmit intr, status %d\n", res);
}
static inline void *rx_agg_align(void *data)
{
return (void *)ALIGN((uintptr_t)data, RX_ALIGN);
}
static inline void *tx_agg_align(void *data)
{
return (void *)ALIGN((uintptr_t)data, TX_ALIGN);
}
static void free_all_mem(struct r8152 *tp)
{
int i;
for (i = 0; i < RTL8152_MAX_RX; i++) {
usb_free_urb(tp->rx_info[i].urb);
tp->rx_info[i].urb = NULL;
kfree(tp->rx_info[i].buffer);
tp->rx_info[i].buffer = NULL;
tp->rx_info[i].head = NULL;
}
for (i = 0; i < RTL8152_MAX_TX; i++) {
usb_free_urb(tp->tx_info[i].urb);
tp->tx_info[i].urb = NULL;
kfree(tp->tx_info[i].buffer);
tp->tx_info[i].buffer = NULL;
tp->tx_info[i].head = NULL;
}
usb_free_urb(tp->intr_urb);
tp->intr_urb = NULL;
kfree(tp->intr_buff);
tp->intr_buff = NULL;
}
static int alloc_all_mem(struct r8152 *tp)
{
struct net_device *netdev = tp->netdev;
struct usb_interface *intf = tp->intf;
struct usb_host_interface *alt = intf->cur_altsetting;
struct usb_host_endpoint *ep_intr = alt->endpoint + 2;
struct urb *urb;
int node, i;
u8 *buf;
node = netdev->dev.parent ? dev_to_node(netdev->dev.parent) : -1;
spin_lock_init(&tp->rx_lock);
spin_lock_init(&tp->tx_lock);
INIT_LIST_HEAD(&tp->rx_done);
INIT_LIST_HEAD(&tp->tx_free);
skb_queue_head_init(&tp->tx_queue);
for (i = 0; i < RTL8152_MAX_RX; i++) {
buf = kmalloc_node(rx_buf_sz, GFP_KERNEL, node);
if (!buf)
goto err1;
if (buf != rx_agg_align(buf)) {
kfree(buf);
buf = kmalloc_node(rx_buf_sz + RX_ALIGN, GFP_KERNEL,
node);
if (!buf)
goto err1;
}
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb) {
kfree(buf);
goto err1;
}
INIT_LIST_HEAD(&tp->rx_info[i].list);
tp->rx_info[i].context = tp;
tp->rx_info[i].urb = urb;
tp->rx_info[i].buffer = buf;
tp->rx_info[i].head = rx_agg_align(buf);
}
for (i = 0; i < RTL8152_MAX_TX; i++) {
buf = kmalloc_node(rx_buf_sz, GFP_KERNEL, node);
if (!buf)
goto err1;
if (buf != tx_agg_align(buf)) {
kfree(buf);
buf = kmalloc_node(rx_buf_sz + TX_ALIGN, GFP_KERNEL,
node);
if (!buf)
goto err1;
}
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb) {
kfree(buf);
goto err1;
}
INIT_LIST_HEAD(&tp->tx_info[i].list);
tp->tx_info[i].context = tp;
tp->tx_info[i].urb = urb;
tp->tx_info[i].buffer = buf;
tp->tx_info[i].head = tx_agg_align(buf);
list_add_tail(&tp->tx_info[i].list, &tp->tx_free);
}
tp->intr_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!tp->intr_urb)
goto err1;
tp->intr_buff = kmalloc(INTBUFSIZE, GFP_KERNEL);
if (!tp->intr_buff)
goto err1;
tp->intr_interval = (int)ep_intr->desc.bInterval;
usb_fill_int_urb(tp->intr_urb, tp->udev, usb_rcvintpipe(tp->udev, 3),
tp->intr_buff, INTBUFSIZE, intr_callback,
tp, tp->intr_interval);
return 0;
err1:
free_all_mem(tp);
return -ENOMEM;
}
static struct tx_agg *r8152_get_tx_agg(struct r8152 *tp)
{
struct tx_agg *agg = NULL;
unsigned long flags;
if (list_empty(&tp->tx_free))
return NULL;
spin_lock_irqsave(&tp->tx_lock, flags);
if (!list_empty(&tp->tx_free)) {
struct list_head *cursor;
cursor = tp->tx_free.next;
list_del_init(cursor);
agg = list_entry(cursor, struct tx_agg, list);
}
spin_unlock_irqrestore(&tp->tx_lock, flags);
return agg;
}
static inline __be16 get_protocol(struct sk_buff *skb)
{
__be16 protocol;
if (skb->protocol == htons(ETH_P_8021Q))
protocol = vlan_eth_hdr(skb)->h_vlan_encapsulated_proto;
else
protocol = skb->protocol;
return protocol;
}
static void r8152_csum_workaround(struct r8152 *tp, struct sk_buff *skb,
struct sk_buff_head *list)
{
if (skb_shinfo(skb)->gso_size) {
netdev_features_t features = tp->netdev->features;
struct sk_buff_head seg_list;
struct sk_buff *segs, *nskb;
features &= ~(NETIF_F_IP_CSUM | NETIF_F_SG | NETIF_F_TSO);
segs = skb_gso_segment(skb, features);
if (IS_ERR(segs) || !segs)
goto drop;
__skb_queue_head_init(&seg_list);
do {
nskb = segs;
segs = segs->next;
nskb->next = NULL;
__skb_queue_tail(&seg_list, nskb);
} while (segs);
skb_queue_splice(&seg_list, list);
dev_kfree_skb(skb);
} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
if (skb_checksum_help(skb) < 0)
goto drop;
__skb_queue_head(list, skb);
} else {
struct net_device_stats *stats;
drop:
stats = &tp->netdev->stats;
stats->tx_dropped++;
dev_kfree_skb(skb);
}
}
static int msdn_giant_send_check(struct sk_buff *skb)
{
const struct ipv6hdr *ipv6h;
struct tcphdr *th;
int ret;
ret = skb_cow_head(skb, 0);
if (ret)
return ret;
ipv6h = ipv6_hdr(skb);
th = tcp_hdr(skb);
th->check = 0;
th->check = ~tcp_v6_check(0, &ipv6h->saddr, &ipv6h->daddr, 0);
return ret;
}
static int r8152_tx_csum(struct r8152 *tp, struct tx_desc *desc,
struct sk_buff *skb, u32 len, u32 transport_offset)
{
u32 mss = skb_shinfo(skb)->gso_size;
u32 opts1, opts2 = 0;
int ret = TX_CSUM_SUCCESS;
WARN_ON_ONCE(len > TX_LEN_MAX);
opts1 = len | TX_FS | TX_LS;
if (mss) {
if (transport_offset > GTTCPHO_MAX) {
netif_warn(tp, tx_err, tp->netdev,
"Invalid transport offset 0x%x for TSO\n",
transport_offset);
ret = TX_CSUM_TSO;
goto unavailable;
}
switch (get_protocol(skb)) {
case htons(ETH_P_IP):
opts1 |= GTSENDV4;
break;
case htons(ETH_P_IPV6):
if (msdn_giant_send_check(skb)) {
ret = TX_CSUM_TSO;
goto unavailable;
}
opts1 |= GTSENDV6;
break;
default:
WARN_ON_ONCE(1);
break;
}
opts1 |= transport_offset << GTTCPHO_SHIFT;
opts2 |= min(mss, MSS_MAX) << MSS_SHIFT;
} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
u8 ip_protocol;
if (transport_offset > TCPHO_MAX) {
netif_warn(tp, tx_err, tp->netdev,
"Invalid transport offset 0x%x\n",
transport_offset);
ret = TX_CSUM_NONE;
goto unavailable;
}
switch (get_protocol(skb)) {
case htons(ETH_P_IP):
opts2 |= IPV4_CS;
ip_protocol = ip_hdr(skb)->protocol;
break;
case htons(ETH_P_IPV6):
opts2 |= IPV6_CS;
ip_protocol = ipv6_hdr(skb)->nexthdr;
break;
default:
ip_protocol = IPPROTO_RAW;
break;
}
if (ip_protocol == IPPROTO_TCP)
opts2 |= TCP_CS;
else if (ip_protocol == IPPROTO_UDP)
opts2 |= UDP_CS;
else
WARN_ON_ONCE(1);
opts2 |= transport_offset << TCPHO_SHIFT;
}
desc->opts2 = cpu_to_le32(opts2);
desc->opts1 = cpu_to_le32(opts1);
unavailable:
return ret;
}
static int r8152_tx_agg_fill(struct r8152 *tp, struct tx_agg *agg)
{
struct sk_buff_head skb_head, *tx_queue = &tp->tx_queue;
int remain, ret;
u8 *tx_data;
__skb_queue_head_init(&skb_head);
spin_lock(&tx_queue->lock);
skb_queue_splice_init(tx_queue, &skb_head);
spin_unlock(&tx_queue->lock);
tx_data = agg->head;
agg->skb_num = agg->skb_len = 0;
remain = rx_buf_sz;
while (remain >= ETH_ZLEN + sizeof(struct tx_desc)) {
struct tx_desc *tx_desc;
struct sk_buff *skb;
unsigned int len;
u32 offset;
skb = __skb_dequeue(&skb_head);
if (!skb)
break;
len = skb->len + sizeof(*tx_desc);
if (len > remain) {
__skb_queue_head(&skb_head, skb);
break;
}
tx_data = tx_agg_align(tx_data);
tx_desc = (struct tx_desc *)tx_data;
offset = (u32)skb_transport_offset(skb);
if (r8152_tx_csum(tp, tx_desc, skb, skb->len, offset)) {
r8152_csum_workaround(tp, skb, &skb_head);
continue;
}
tx_data += sizeof(*tx_desc);
len = skb->len;
if (skb_copy_bits(skb, 0, tx_data, len) < 0) {
struct net_device_stats *stats = &tp->netdev->stats;
stats->tx_dropped++;
dev_kfree_skb_any(skb);
tx_data -= sizeof(*tx_desc);
continue;
}
tx_data += len;
agg->skb_len += len;
agg->skb_num++;
dev_kfree_skb_any(skb);
remain = rx_buf_sz - (int)(tx_agg_align(tx_data) - agg->head);
}
if (!skb_queue_empty(&skb_head)) {
spin_lock(&tx_queue->lock);
skb_queue_splice(&skb_head, tx_queue);
spin_unlock(&tx_queue->lock);
}
netif_tx_lock(tp->netdev);
if (netif_queue_stopped(tp->netdev) &&
skb_queue_len(&tp->tx_queue) < tp->tx_qlen)
netif_wake_queue(tp->netdev);
netif_tx_unlock(tp->netdev);
ret = usb_autopm_get_interface_async(tp->intf);
if (ret < 0)
goto out_tx_fill;
usb_fill_bulk_urb(agg->urb, tp->udev, usb_sndbulkpipe(tp->udev, 2),
agg->head, (int)(tx_data - (u8 *)agg->head),
(usb_complete_t)write_bulk_callback, agg);
ret = usb_submit_urb(agg->urb, GFP_ATOMIC);
if (ret < 0)
usb_autopm_put_interface_async(tp->intf);
out_tx_fill:
return ret;
}
static u8 r8152_rx_csum(struct r8152 *tp, struct rx_desc *rx_desc)
{
u8 checksum = CHECKSUM_NONE;
u32 opts2, opts3;
if (tp->version == RTL_VER_01)
goto return_result;
opts2 = le32_to_cpu(rx_desc->opts2);
opts3 = le32_to_cpu(rx_desc->opts3);
if (opts2 & RD_IPV4_CS) {
if (opts3 & IPF)
checksum = CHECKSUM_NONE;
else if ((opts2 & RD_UDP_CS) && (opts3 & UDPF))
checksum = CHECKSUM_NONE;
else if ((opts2 & RD_TCP_CS) && (opts3 & TCPF))
checksum = CHECKSUM_NONE;
else
checksum = CHECKSUM_UNNECESSARY;
} else if (RD_IPV6_CS) {
if ((opts2 & RD_UDP_CS) && !(opts3 & UDPF))
checksum = CHECKSUM_UNNECESSARY;
else if ((opts2 & RD_TCP_CS) && !(opts3 & TCPF))
checksum = CHECKSUM_UNNECESSARY;
}
return_result:
return checksum;
}
static void rx_bottom(struct r8152 *tp)
{
unsigned long flags;
struct list_head *cursor, *next, rx_queue;
if (list_empty(&tp->rx_done))
return;
INIT_LIST_HEAD(&rx_queue);
spin_lock_irqsave(&tp->rx_lock, flags);
list_splice_init(&tp->rx_done, &rx_queue);
spin_unlock_irqrestore(&tp->rx_lock, flags);
list_for_each_safe(cursor, next, &rx_queue) {
struct rx_desc *rx_desc;
struct rx_agg *agg;
int len_used = 0;
struct urb *urb;
u8 *rx_data;
int ret;
list_del_init(cursor);
agg = list_entry(cursor, struct rx_agg, list);
urb = agg->urb;
if (urb->actual_length < ETH_ZLEN)
goto submit;
rx_desc = agg->head;
rx_data = agg->head;
len_used += sizeof(struct rx_desc);
while (urb->actual_length > len_used) {
struct net_device *netdev = tp->netdev;
struct net_device_stats *stats = &netdev->stats;
unsigned int pkt_len;
struct sk_buff *skb;
pkt_len = le32_to_cpu(rx_desc->opts1) & RX_LEN_MASK;
if (pkt_len < ETH_ZLEN)
break;
len_used += pkt_len;
if (urb->actual_length < len_used)
break;
pkt_len -= CRC_SIZE;
rx_data += sizeof(struct rx_desc);
skb = netdev_alloc_skb_ip_align(netdev, pkt_len);
if (!skb) {
stats->rx_dropped++;
goto find_next_rx;
}
skb->ip_summed = r8152_rx_csum(tp, rx_desc);
memcpy(skb->data, rx_data, pkt_len);
skb_put(skb, pkt_len);
skb->protocol = eth_type_trans(skb, netdev);
netif_receive_skb(skb);
stats->rx_packets++;
stats->rx_bytes += pkt_len;
find_next_rx:
rx_data = rx_agg_align(rx_data + pkt_len + CRC_SIZE);
rx_desc = (struct rx_desc *)rx_data;
len_used = (int)(rx_data - (u8 *)agg->head);
len_used += sizeof(struct rx_desc);
}
submit:
ret = r8152_submit_rx(tp, agg, GFP_ATOMIC);
if (ret && ret != -ENODEV) {
spin_lock_irqsave(&tp->rx_lock, flags);
list_add_tail(&agg->list, &tp->rx_done);
spin_unlock_irqrestore(&tp->rx_lock, flags);
tasklet_schedule(&tp->tl);
}
}
}
static void tx_bottom(struct r8152 *tp)
{
int res;
do {
struct tx_agg *agg;
if (skb_queue_empty(&tp->tx_queue))
break;
agg = r8152_get_tx_agg(tp);
if (!agg)
break;
res = r8152_tx_agg_fill(tp, agg);
if (res) {
struct net_device *netdev = tp->netdev;
if (res == -ENODEV) {
netif_device_detach(netdev);
} else {
struct net_device_stats *stats = &netdev->stats;
unsigned long flags;
netif_warn(tp, tx_err, netdev,
"failed tx_urb %d\n", res);
stats->tx_dropped += agg->skb_num;
spin_lock_irqsave(&tp->tx_lock, flags);
list_add_tail(&agg->list, &tp->tx_free);
spin_unlock_irqrestore(&tp->tx_lock, flags);
}
}
} while (res == 0);
}
static void bottom_half(unsigned long data)
{
struct r8152 *tp;
tp = (struct r8152 *)data;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return;
if (!test_bit(WORK_ENABLE, &tp->flags))
return;
if (!netif_carrier_ok(tp->netdev))
return;
rx_bottom(tp);
tx_bottom(tp);
}
static
int r8152_submit_rx(struct r8152 *tp, struct rx_agg *agg, gfp_t mem_flags)
{
usb_fill_bulk_urb(agg->urb, tp->udev, usb_rcvbulkpipe(tp->udev, 1),
agg->head, rx_buf_sz,
(usb_complete_t)read_bulk_callback, agg);
return usb_submit_urb(agg->urb, mem_flags);
}
static void rtl_drop_queued_tx(struct r8152 *tp)
{
struct net_device_stats *stats = &tp->netdev->stats;
struct sk_buff_head skb_head, *tx_queue = &tp->tx_queue;
struct sk_buff *skb;
if (skb_queue_empty(tx_queue))
return;
__skb_queue_head_init(&skb_head);
spin_lock_bh(&tx_queue->lock);
skb_queue_splice_init(tx_queue, &skb_head);
spin_unlock_bh(&tx_queue->lock);
while ((skb = __skb_dequeue(&skb_head))) {
dev_kfree_skb(skb);
stats->tx_dropped++;
}
}
static void rtl8152_tx_timeout(struct net_device *netdev)
{
struct r8152 *tp = netdev_priv(netdev);
int i;
netif_warn(tp, tx_err, netdev, "Tx timeout\n");
for (i = 0; i < RTL8152_MAX_TX; i++)
usb_unlink_urb(tp->tx_info[i].urb);
}
static void rtl8152_set_rx_mode(struct net_device *netdev)
{
struct r8152 *tp = netdev_priv(netdev);
if (tp->speed & LINK_STATUS) {
set_bit(RTL8152_SET_RX_MODE, &tp->flags);
schedule_delayed_work(&tp->schedule, 0);
}
}
static void _rtl8152_set_rx_mode(struct net_device *netdev)
{
struct r8152 *tp = netdev_priv(netdev);
u32 mc_filter[2];
__le32 tmp[2];
u32 ocp_data;
clear_bit(RTL8152_SET_RX_MODE, &tp->flags);
netif_stop_queue(netdev);
ocp_data = ocp_read_dword(tp, MCU_TYPE_PLA, PLA_RCR);
ocp_data &= ~RCR_ACPT_ALL;
ocp_data |= RCR_AB | RCR_APM;
if (netdev->flags & IFF_PROMISC) {
netif_notice(tp, link, netdev, "Promiscuous mode enabled\n");
ocp_data |= RCR_AM | RCR_AAP;
mc_filter[1] = mc_filter[0] = 0xffffffff;
} else if ((netdev_mc_count(netdev) > multicast_filter_limit) ||
(netdev->flags & IFF_ALLMULTI)) {
ocp_data |= RCR_AM;
mc_filter[1] = mc_filter[0] = 0xffffffff;
} else {
struct netdev_hw_addr *ha;
mc_filter[1] = mc_filter[0] = 0;
netdev_for_each_mc_addr(ha, netdev) {
int bit_nr = ether_crc(ETH_ALEN, ha->addr) >> 26;
mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
ocp_data |= RCR_AM;
}
}
tmp[0] = __cpu_to_le32(swab32(mc_filter[1]));
tmp[1] = __cpu_to_le32(swab32(mc_filter[0]));
pla_ocp_write(tp, PLA_MAR, BYTE_EN_DWORD, sizeof(tmp), tmp);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RCR, ocp_data);
netif_wake_queue(netdev);
}
static netdev_tx_t rtl8152_start_xmit(struct sk_buff *skb,
struct net_device *netdev)
{
struct r8152 *tp = netdev_priv(netdev);
skb_tx_timestamp(skb);
skb_queue_tail(&tp->tx_queue, skb);
if (!list_empty(&tp->tx_free)) {
if (test_bit(SELECTIVE_SUSPEND, &tp->flags)) {
set_bit(SCHEDULE_TASKLET, &tp->flags);
schedule_delayed_work(&tp->schedule, 0);
} else {
usb_mark_last_busy(tp->udev);
tasklet_schedule(&tp->tl);
}
} else if (skb_queue_len(&tp->tx_queue) > tp->tx_qlen)
netif_stop_queue(netdev);
return NETDEV_TX_OK;
}
static void r8152b_reset_packet_filter(struct r8152 *tp)
{
u32 ocp_data;
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_FMC);
ocp_data &= ~FMC_FCR_MCU_EN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_FMC, ocp_data);
ocp_data |= FMC_FCR_MCU_EN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_FMC, ocp_data);
}
static void rtl8152_nic_reset(struct r8152 *tp)
{
int i;
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CR, CR_RST);
for (i = 0; i < 1000; i++) {
if (!(ocp_read_byte(tp, MCU_TYPE_PLA, PLA_CR) & CR_RST))
break;
udelay(100);
}
}
static void set_tx_qlen(struct r8152 *tp)
{
struct net_device *netdev = tp->netdev;
tp->tx_qlen = rx_buf_sz / (netdev->mtu + VLAN_ETH_HLEN + VLAN_HLEN +
sizeof(struct tx_desc));
}
static inline u8 rtl8152_get_speed(struct r8152 *tp)
{
return ocp_read_byte(tp, MCU_TYPE_PLA, PLA_PHYSTATUS);
}
static void rtl_set_eee_plus(struct r8152 *tp)
{
u32 ocp_data;
u8 speed;
speed = rtl8152_get_speed(tp);
if (speed & _10bps) {
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_EEEP_CR);
ocp_data |= EEEP_CR_EEEP_TX;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_EEEP_CR, ocp_data);
} else {
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_EEEP_CR);
ocp_data &= ~EEEP_CR_EEEP_TX;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_EEEP_CR, ocp_data);
}
}
static void rxdy_gated_en(struct r8152 *tp, bool enable)
{
u32 ocp_data;
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_MISC_1);
if (enable)
ocp_data |= RXDY_GATED_EN;
else
ocp_data &= ~RXDY_GATED_EN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_MISC_1, ocp_data);
}
static int rtl_enable(struct r8152 *tp)
{
u32 ocp_data;
int i, ret;
r8152b_reset_packet_filter(tp);
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_CR);
ocp_data |= CR_RE | CR_TE;
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CR, ocp_data);
rxdy_gated_en(tp, false);
INIT_LIST_HEAD(&tp->rx_done);
ret = 0;
for (i = 0; i < RTL8152_MAX_RX; i++) {
INIT_LIST_HEAD(&tp->rx_info[i].list);
ret |= r8152_submit_rx(tp, &tp->rx_info[i], GFP_KERNEL);
}
return ret;
}
static int rtl8152_enable(struct r8152 *tp)
{
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return -ENODEV;
set_tx_qlen(tp);
rtl_set_eee_plus(tp);
return rtl_enable(tp);
}
static void r8153_set_rx_agg(struct r8152 *tp)
{
u8 speed;
speed = rtl8152_get_speed(tp);
if (speed & _1000bps) {
if (tp->udev->speed == USB_SPEED_SUPER) {
ocp_write_dword(tp, MCU_TYPE_USB, USB_RX_BUF_TH,
RX_THR_SUPPER);
ocp_write_dword(tp, MCU_TYPE_USB, USB_RX_EARLY_AGG,
EARLY_AGG_SUPPER);
} else {
ocp_write_dword(tp, MCU_TYPE_USB, USB_RX_BUF_TH,
RX_THR_HIGH);
ocp_write_dword(tp, MCU_TYPE_USB, USB_RX_EARLY_AGG,
EARLY_AGG_HIGH);
}
} else {
ocp_write_dword(tp, MCU_TYPE_USB, USB_RX_BUF_TH, RX_THR_SLOW);
ocp_write_dword(tp, MCU_TYPE_USB, USB_RX_EARLY_AGG,
EARLY_AGG_SLOW);
}
}
static int rtl8153_enable(struct r8152 *tp)
{
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return -ENODEV;
set_tx_qlen(tp);
rtl_set_eee_plus(tp);
r8153_set_rx_agg(tp);
return rtl_enable(tp);
}
static void rtl8152_disable(struct r8152 *tp)
{
u32 ocp_data;
int i;
if (test_bit(RTL8152_UNPLUG, &tp->flags)) {
rtl_drop_queued_tx(tp);
return;
}
ocp_data = ocp_read_dword(tp, MCU_TYPE_PLA, PLA_RCR);
ocp_data &= ~RCR_ACPT_ALL;
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RCR, ocp_data);
rtl_drop_queued_tx(tp);
for (i = 0; i < RTL8152_MAX_TX; i++)
usb_kill_urb(tp->tx_info[i].urb);
rxdy_gated_en(tp, true);
for (i = 0; i < 1000; i++) {
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
if ((ocp_data & FIFO_EMPTY) == FIFO_EMPTY)
break;
mdelay(1);
}
for (i = 0; i < 1000; i++) {
if (ocp_read_word(tp, MCU_TYPE_PLA, PLA_TCR0) & TCR0_TX_EMPTY)
break;
mdelay(1);
}
for (i = 0; i < RTL8152_MAX_RX; i++)
usb_kill_urb(tp->rx_info[i].urb);
rtl8152_nic_reset(tp);
}
static void r8152_power_cut_en(struct r8152 *tp, bool enable)
{
u32 ocp_data;
ocp_data = ocp_read_word(tp, MCU_TYPE_USB, USB_UPS_CTRL);
if (enable)
ocp_data |= POWER_CUT;
else
ocp_data &= ~POWER_CUT;
ocp_write_word(tp, MCU_TYPE_USB, USB_UPS_CTRL, ocp_data);
ocp_data = ocp_read_word(tp, MCU_TYPE_USB, USB_PM_CTRL_STATUS);
ocp_data &= ~RESUME_INDICATE;
ocp_write_word(tp, MCU_TYPE_USB, USB_PM_CTRL_STATUS, ocp_data);
}
static u32 __rtl_get_wol(struct r8152 *tp)
{
u32 ocp_data;
u32 wolopts = 0;
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_CONFIG5);
if (!(ocp_data & LAN_WAKE_EN))
return 0;
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CONFIG34);
if (ocp_data & LINK_ON_WAKE_EN)
wolopts |= WAKE_PHY;
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CONFIG5);
if (ocp_data & UWF_EN)
wolopts |= WAKE_UCAST;
if (ocp_data & BWF_EN)
wolopts |= WAKE_BCAST;
if (ocp_data & MWF_EN)
wolopts |= WAKE_MCAST;
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CFG_WOL);
if (ocp_data & MAGIC_EN)
wolopts |= WAKE_MAGIC;
return wolopts;
}
static void __rtl_set_wol(struct r8152 *tp, u32 wolopts)
{
u32 ocp_data;
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CRWECR, CRWECR_CONFIG);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CONFIG34);
ocp_data &= ~LINK_ON_WAKE_EN;
if (wolopts & WAKE_PHY)
ocp_data |= LINK_ON_WAKE_EN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_CONFIG34, ocp_data);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CONFIG5);
ocp_data &= ~(UWF_EN | BWF_EN | MWF_EN | LAN_WAKE_EN);
if (wolopts & WAKE_UCAST)
ocp_data |= UWF_EN;
if (wolopts & WAKE_BCAST)
ocp_data |= BWF_EN;
if (wolopts & WAKE_MCAST)
ocp_data |= MWF_EN;
if (wolopts & WAKE_ANY)
ocp_data |= LAN_WAKE_EN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_CONFIG5, ocp_data);
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CRWECR, CRWECR_NORAML);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CFG_WOL);
ocp_data &= ~MAGIC_EN;
if (wolopts & WAKE_MAGIC)
ocp_data |= MAGIC_EN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_CFG_WOL, ocp_data);
if (wolopts & WAKE_ANY)
device_set_wakeup_enable(&tp->udev->dev, true);
else
device_set_wakeup_enable(&tp->udev->dev, false);
}
static void rtl_runtime_suspend_enable(struct r8152 *tp, bool enable)
{
if (enable) {
u32 ocp_data;
__rtl_set_wol(tp, WAKE_ANY);
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CRWECR, CRWECR_CONFIG);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CONFIG34);
ocp_data |= LINK_OFF_WAKE_EN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_CONFIG34, ocp_data);
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CRWECR, CRWECR_NORAML);
} else {
__rtl_set_wol(tp, tp->saved_wolopts);
}
}
static void rtl_phy_reset(struct r8152 *tp)
{
u16 data;
int i;
clear_bit(PHY_RESET, &tp->flags);
data = r8152_mdio_read(tp, MII_BMCR);
if (data & BMCR_RESET)
return;
data |= BMCR_RESET;
r8152_mdio_write(tp, MII_BMCR, data);
for (i = 0; i < 50; i++) {
msleep(20);
if ((r8152_mdio_read(tp, MII_BMCR) & BMCR_RESET) == 0)
break;
}
}
static void rtl_clear_bp(struct r8152 *tp)
{
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_BP_0, 0);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_BP_2, 0);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_BP_4, 0);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_BP_6, 0);
ocp_write_dword(tp, MCU_TYPE_USB, USB_BP_0, 0);
ocp_write_dword(tp, MCU_TYPE_USB, USB_BP_2, 0);
ocp_write_dword(tp, MCU_TYPE_USB, USB_BP_4, 0);
ocp_write_dword(tp, MCU_TYPE_USB, USB_BP_6, 0);
mdelay(3);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_BP_BA, 0);
ocp_write_word(tp, MCU_TYPE_USB, USB_BP_BA, 0);
}
static void r8153_clear_bp(struct r8152 *tp)
{
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_BP_EN, 0);
ocp_write_byte(tp, MCU_TYPE_USB, USB_BP_EN, 0);
rtl_clear_bp(tp);
}
static void r8153_teredo_off(struct r8152 *tp)
{
u32 ocp_data;
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_TEREDO_CFG);
ocp_data &= ~(TEREDO_SEL | TEREDO_RS_EVENT_MASK | OOB_TEREDO_EN);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_TEREDO_CFG, ocp_data);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_WDT6_CTRL, WDT6_SET_MODE);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_REALWOW_TIMER, 0);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_TEREDO_TIMER, 0);
}
static void r8152b_disable_aldps(struct r8152 *tp)
{
ocp_reg_write(tp, OCP_ALDPS_CONFIG, ENPDNPS | LINKENA | DIS_SDSAVE);
msleep(20);
}
static inline void r8152b_enable_aldps(struct r8152 *tp)
{
ocp_reg_write(tp, OCP_ALDPS_CONFIG, ENPWRSAVE | ENPDNPS |
LINKENA | DIS_SDSAVE);
}
static void r8152b_hw_phy_cfg(struct r8152 *tp)
{
u16 data;
data = r8152_mdio_read(tp, MII_BMCR);
if (data & BMCR_PDOWN) {
data &= ~BMCR_PDOWN;
r8152_mdio_write(tp, MII_BMCR, data);
}
r8152b_disable_aldps(tp);
rtl_clear_bp(tp);
r8152b_enable_aldps(tp);
set_bit(PHY_RESET, &tp->flags);
}
static void r8152b_exit_oob(struct r8152 *tp)
{
u32 ocp_data;
int i;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return;
ocp_data = ocp_read_dword(tp, MCU_TYPE_PLA, PLA_RCR);
ocp_data &= ~RCR_ACPT_ALL;
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RCR, ocp_data);
rxdy_gated_en(tp, true);
r8153_teredo_off(tp);
r8152b_hw_phy_cfg(tp);
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CRWECR, CRWECR_NORAML);
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_CR, 0x00);
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
ocp_data &= ~NOW_IS_OOB;
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL, ocp_data);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7);
ocp_data &= ~MCU_BORW_EN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7, ocp_data);
for (i = 0; i < 1000; i++) {
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
if (ocp_data & LINK_LIST_READY)
break;
mdelay(1);
}
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7);
ocp_data |= RE_INIT_LL;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7, ocp_data);
for (i = 0; i < 1000; i++) {
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
if (ocp_data & LINK_LIST_READY)
break;
mdelay(1);
}
rtl8152_nic_reset(tp);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RXFIFO_CTRL0, RXFIFO_THR1_NORMAL);
ocp_data = ocp_read_word(tp, MCU_TYPE_USB, USB_DEV_STAT);
ocp_data &= STAT_SPEED_MASK;
if (ocp_data == STAT_SPEED_FULL) {
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RXFIFO_CTRL1,
RXFIFO_THR2_FULL);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RXFIFO_CTRL2,
RXFIFO_THR3_FULL);
} else {
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RXFIFO_CTRL1,
RXFIFO_THR2_HIGH);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RXFIFO_CTRL2,
RXFIFO_THR3_HIGH);
}
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_TXFIFO_CTRL, TXFIFO_THR_NORMAL);
ocp_write_byte(tp, MCU_TYPE_USB, USB_TX_AGG, TX_AGG_MAX_THRESHOLD);
ocp_write_dword(tp, MCU_TYPE_USB, USB_RX_BUF_TH, RX_THR_HIGH);
ocp_write_dword(tp, MCU_TYPE_USB, USB_TX_DMA,
TEST_MODE_DISABLE | TX_SIZE_ADJUST1);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CPCR);
ocp_data &= ~CPCR_RX_VLAN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_CPCR, ocp_data);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_RMS, RTL8152_RMS);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_TCR0);
ocp_data |= TCR0_AUTO_FIFO;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_TCR0, ocp_data);
}
static void r8152b_enter_oob(struct r8152 *tp)
{
u32 ocp_data;
int i;
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
ocp_data &= ~NOW_IS_OOB;
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL, ocp_data);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RXFIFO_CTRL0, RXFIFO_THR1_OOB);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RXFIFO_CTRL1, RXFIFO_THR2_OOB);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RXFIFO_CTRL2, RXFIFO_THR3_OOB);
rtl8152_disable(tp);
for (i = 0; i < 1000; i++) {
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
if (ocp_data & LINK_LIST_READY)
break;
mdelay(1);
}
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7);
ocp_data |= RE_INIT_LL;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7, ocp_data);
for (i = 0; i < 1000; i++) {
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
if (ocp_data & LINK_LIST_READY)
break;
mdelay(1);
}
ocp_write_word(tp, MCU_TYPE_PLA, PLA_RMS, RTL8152_RMS);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CPCR);
ocp_data |= CPCR_RX_VLAN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_CPCR, ocp_data);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PAL_BDC_CR);
ocp_data |= ALDPS_PROXY_MODE;
ocp_write_word(tp, MCU_TYPE_PLA, PAL_BDC_CR, ocp_data);
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
ocp_data |= NOW_IS_OOB | DIS_MCU_CLROOB;
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL, ocp_data);
rxdy_gated_en(tp, false);
ocp_data = ocp_read_dword(tp, MCU_TYPE_PLA, PLA_RCR);
ocp_data |= RCR_APM | RCR_AM | RCR_AB;
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RCR, ocp_data);
}
static void r8153_hw_phy_cfg(struct r8152 *tp)
{
u32 ocp_data;
u16 data;
ocp_reg_write(tp, OCP_ADC_CFG, CKADSEL_L | ADC_EN | EN_EMI_L);
data = r8152_mdio_read(tp, MII_BMCR);
if (data & BMCR_PDOWN) {
data &= ~BMCR_PDOWN;
r8152_mdio_write(tp, MII_BMCR, data);
}
r8153_clear_bp(tp);
if (tp->version == RTL_VER_03) {
data = ocp_reg_read(tp, OCP_EEE_CFG);
data &= ~CTAP_SHORT_EN;
ocp_reg_write(tp, OCP_EEE_CFG, data);
}
data = ocp_reg_read(tp, OCP_POWER_CFG);
data |= EEE_CLKDIV_EN;
ocp_reg_write(tp, OCP_POWER_CFG, data);
data = ocp_reg_read(tp, OCP_DOWN_SPEED);
data |= EN_10M_BGOFF;
ocp_reg_write(tp, OCP_DOWN_SPEED, data);
data = ocp_reg_read(tp, OCP_POWER_CFG);
data |= EN_10M_PLLOFF;
ocp_reg_write(tp, OCP_POWER_CFG, data);
data = sram_read(tp, SRAM_IMPEDANCE);
data &= ~RX_DRIVING_MASK;
sram_write(tp, SRAM_IMPEDANCE, data);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_PHY_PWR);
ocp_data |= PFM_PWM_SWITCH;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_PHY_PWR, ocp_data);
data = sram_read(tp, SRAM_LPF_CFG);
data |= LPF_AUTO_TUNE;
sram_write(tp, SRAM_LPF_CFG, data);
data = sram_read(tp, SRAM_10M_AMP1);
data |= GDAC_IB_UPALL;
sram_write(tp, SRAM_10M_AMP1, data);
data = sram_read(tp, SRAM_10M_AMP2);
data |= AMP_DN;
sram_write(tp, SRAM_10M_AMP2, data);
set_bit(PHY_RESET, &tp->flags);
}
static void r8153_u1u2en(struct r8152 *tp, bool enable)
{
u8 u1u2[8];
if (enable)
memset(u1u2, 0xff, sizeof(u1u2));
else
memset(u1u2, 0x00, sizeof(u1u2));
usb_ocp_write(tp, USB_TOLERANCE, BYTE_EN_SIX_BYTES, sizeof(u1u2), u1u2);
}
static void r8153_u2p3en(struct r8152 *tp, bool enable)
{
u32 ocp_data;
ocp_data = ocp_read_word(tp, MCU_TYPE_USB, USB_U2P3_CTRL);
if (enable)
ocp_data |= U2P3_ENABLE;
else
ocp_data &= ~U2P3_ENABLE;
ocp_write_word(tp, MCU_TYPE_USB, USB_U2P3_CTRL, ocp_data);
}
static void r8153_power_cut_en(struct r8152 *tp, bool enable)
{
u32 ocp_data;
ocp_data = ocp_read_word(tp, MCU_TYPE_USB, USB_POWER_CUT);
if (enable)
ocp_data |= PWR_EN | PHASE2_EN;
else
ocp_data &= ~(PWR_EN | PHASE2_EN);
ocp_write_word(tp, MCU_TYPE_USB, USB_POWER_CUT, ocp_data);
ocp_data = ocp_read_word(tp, MCU_TYPE_USB, USB_MISC_0);
ocp_data &= ~PCUT_STATUS;
ocp_write_word(tp, MCU_TYPE_USB, USB_MISC_0, ocp_data);
}
static void r8153_first_init(struct r8152 *tp)
{
u32 ocp_data;
int i;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return;
rxdy_gated_en(tp, true);
r8153_teredo_off(tp);
ocp_data = ocp_read_dword(tp, MCU_TYPE_PLA, PLA_RCR);
ocp_data &= ~RCR_ACPT_ALL;
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RCR, ocp_data);
r8153_hw_phy_cfg(tp);
rtl8152_nic_reset(tp);
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
ocp_data &= ~NOW_IS_OOB;
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL, ocp_data);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7);
ocp_data &= ~MCU_BORW_EN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7, ocp_data);
for (i = 0; i < 1000; i++) {
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
if (ocp_data & LINK_LIST_READY)
break;
mdelay(1);
}
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7);
ocp_data |= RE_INIT_LL;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7, ocp_data);
for (i = 0; i < 1000; i++) {
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
if (ocp_data & LINK_LIST_READY)
break;
mdelay(1);
}
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CPCR);
ocp_data &= ~CPCR_RX_VLAN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_CPCR, ocp_data);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_RMS, RTL8152_RMS);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_TCR0);
ocp_data |= TCR0_AUTO_FIFO;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_TCR0, ocp_data);
rtl8152_nic_reset(tp);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RXFIFO_CTRL0, RXFIFO_THR1_NORMAL);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_RXFIFO_CTRL1, RXFIFO_THR2_NORMAL);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_RXFIFO_CTRL2, RXFIFO_THR3_NORMAL);
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_TXFIFO_CTRL, TXFIFO_THR_NORMAL2);
ocp_data = ocp_read_word(tp, MCU_TYPE_USB, USB_USB_CTRL);
ocp_data &= ~RX_AGG_DISABLE;
ocp_write_word(tp, MCU_TYPE_USB, USB_USB_CTRL, ocp_data);
}
static void r8153_enter_oob(struct r8152 *tp)
{
u32 ocp_data;
int i;
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
ocp_data &= ~NOW_IS_OOB;
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL, ocp_data);
rtl8152_disable(tp);
for (i = 0; i < 1000; i++) {
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
if (ocp_data & LINK_LIST_READY)
break;
mdelay(1);
}
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7);
ocp_data |= RE_INIT_LL;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_SFF_STS_7, ocp_data);
for (i = 0; i < 1000; i++) {
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
if (ocp_data & LINK_LIST_READY)
break;
mdelay(1);
}
ocp_write_word(tp, MCU_TYPE_PLA, PLA_RMS, RTL8152_RMS);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_TEREDO_CFG);
ocp_data &= ~TEREDO_WAKE_MASK;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_TEREDO_CFG, ocp_data);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CPCR);
ocp_data |= CPCR_RX_VLAN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_CPCR, ocp_data);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PAL_BDC_CR);
ocp_data |= ALDPS_PROXY_MODE;
ocp_write_word(tp, MCU_TYPE_PLA, PAL_BDC_CR, ocp_data);
ocp_data = ocp_read_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL);
ocp_data |= NOW_IS_OOB | DIS_MCU_CLROOB;
ocp_write_byte(tp, MCU_TYPE_PLA, PLA_OOB_CTRL, ocp_data);
rxdy_gated_en(tp, false);
ocp_data = ocp_read_dword(tp, MCU_TYPE_PLA, PLA_RCR);
ocp_data |= RCR_APM | RCR_AM | RCR_AB;
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_RCR, ocp_data);
}
static void r8153_disable_aldps(struct r8152 *tp)
{
u16 data;
data = ocp_reg_read(tp, OCP_POWER_CFG);
data &= ~EN_ALDPS;
ocp_reg_write(tp, OCP_POWER_CFG, data);
msleep(20);
}
static void r8153_enable_aldps(struct r8152 *tp)
{
u16 data;
data = ocp_reg_read(tp, OCP_POWER_CFG);
data |= EN_ALDPS;
ocp_reg_write(tp, OCP_POWER_CFG, data);
}
static int rtl8152_set_speed(struct r8152 *tp, u8 autoneg, u16 speed, u8 duplex)
{
u16 bmcr, anar, gbcr;
int ret = 0;
cancel_delayed_work_sync(&tp->schedule);
anar = r8152_mdio_read(tp, MII_ADVERTISE);
anar &= ~(ADVERTISE_10HALF | ADVERTISE_10FULL |
ADVERTISE_100HALF | ADVERTISE_100FULL);
if (tp->mii.supports_gmii) {
gbcr = r8152_mdio_read(tp, MII_CTRL1000);
gbcr &= ~(ADVERTISE_1000FULL | ADVERTISE_1000HALF);
} else {
gbcr = 0;
}
if (autoneg == AUTONEG_DISABLE) {
if (speed == SPEED_10) {
bmcr = 0;
anar |= ADVERTISE_10HALF | ADVERTISE_10FULL;
} else if (speed == SPEED_100) {
bmcr = BMCR_SPEED100;
anar |= ADVERTISE_100HALF | ADVERTISE_100FULL;
} else if (speed == SPEED_1000 && tp->mii.supports_gmii) {
bmcr = BMCR_SPEED1000;
gbcr |= ADVERTISE_1000FULL | ADVERTISE_1000HALF;
} else {
ret = -EINVAL;
goto out;
}
if (duplex == DUPLEX_FULL)
bmcr |= BMCR_FULLDPLX;
} else {
if (speed == SPEED_10) {
if (duplex == DUPLEX_FULL)
anar |= ADVERTISE_10HALF | ADVERTISE_10FULL;
else
anar |= ADVERTISE_10HALF;
} else if (speed == SPEED_100) {
if (duplex == DUPLEX_FULL) {
anar |= ADVERTISE_10HALF | ADVERTISE_10FULL;
anar |= ADVERTISE_100HALF | ADVERTISE_100FULL;
} else {
anar |= ADVERTISE_10HALF;
anar |= ADVERTISE_100HALF;
}
} else if (speed == SPEED_1000 && tp->mii.supports_gmii) {
if (duplex == DUPLEX_FULL) {
anar |= ADVERTISE_10HALF | ADVERTISE_10FULL;
anar |= ADVERTISE_100HALF | ADVERTISE_100FULL;
gbcr |= ADVERTISE_1000FULL | ADVERTISE_1000HALF;
} else {
anar |= ADVERTISE_10HALF;
anar |= ADVERTISE_100HALF;
gbcr |= ADVERTISE_1000HALF;
}
} else {
ret = -EINVAL;
goto out;
}
bmcr = BMCR_ANENABLE | BMCR_ANRESTART;
}
if (test_bit(PHY_RESET, &tp->flags))
bmcr |= BMCR_RESET;
if (tp->mii.supports_gmii)
r8152_mdio_write(tp, MII_CTRL1000, gbcr);
r8152_mdio_write(tp, MII_ADVERTISE, anar);
r8152_mdio_write(tp, MII_BMCR, bmcr);
if (test_bit(PHY_RESET, &tp->flags)) {
int i;
clear_bit(PHY_RESET, &tp->flags);
for (i = 0; i < 50; i++) {
msleep(20);
if ((r8152_mdio_read(tp, MII_BMCR) & BMCR_RESET) == 0)
break;
}
}
out:
return ret;
}
static void rtl8152_down(struct r8152 *tp)
{
if (test_bit(RTL8152_UNPLUG, &tp->flags)) {
rtl_drop_queued_tx(tp);
return;
}
r8152_power_cut_en(tp, false);
r8152b_disable_aldps(tp);
r8152b_enter_oob(tp);
r8152b_enable_aldps(tp);
}
static void rtl8153_down(struct r8152 *tp)
{
if (test_bit(RTL8152_UNPLUG, &tp->flags)) {
rtl_drop_queued_tx(tp);
return;
}
r8153_u1u2en(tp, false);
r8153_power_cut_en(tp, false);
r8153_disable_aldps(tp);
r8153_enter_oob(tp);
r8153_enable_aldps(tp);
}
static void set_carrier(struct r8152 *tp)
{
struct net_device *netdev = tp->netdev;
u8 speed;
clear_bit(RTL8152_LINK_CHG, &tp->flags);
speed = rtl8152_get_speed(tp);
if (speed & LINK_STATUS) {
if (!(tp->speed & LINK_STATUS)) {
tp->rtl_ops.enable(tp);
set_bit(RTL8152_SET_RX_MODE, &tp->flags);
netif_carrier_on(netdev);
}
} else {
if (tp->speed & LINK_STATUS) {
netif_carrier_off(netdev);
tasklet_disable(&tp->tl);
tp->rtl_ops.disable(tp);
tasklet_enable(&tp->tl);
}
}
tp->speed = speed;
}
static void rtl_work_func_t(struct work_struct *work)
{
struct r8152 *tp = container_of(work, struct r8152, schedule.work);
if (usb_autopm_get_interface(tp->intf) < 0)
return;
if (!test_bit(WORK_ENABLE, &tp->flags))
goto out1;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
goto out1;
if (test_bit(RTL8152_LINK_CHG, &tp->flags))
set_carrier(tp);
if (test_bit(RTL8152_SET_RX_MODE, &tp->flags))
_rtl8152_set_rx_mode(tp->netdev);
if (test_bit(SCHEDULE_TASKLET, &tp->flags) &&
(tp->speed & LINK_STATUS)) {
clear_bit(SCHEDULE_TASKLET, &tp->flags);
tasklet_schedule(&tp->tl);
}
if (test_bit(PHY_RESET, &tp->flags))
rtl_phy_reset(tp);
out1:
usb_autopm_put_interface(tp->intf);
}
static int rtl8152_open(struct net_device *netdev)
{
struct r8152 *tp = netdev_priv(netdev);
int res = 0;
res = alloc_all_mem(tp);
if (res)
goto out;
res = usb_autopm_get_interface(tp->intf);
if (res < 0) {
free_all_mem(tp);
goto out;
}
if (test_bit(WORK_ENABLE, &tp->flags)) {
clear_bit(WORK_ENABLE, &tp->flags);
usb_kill_urb(tp->intr_urb);
cancel_delayed_work_sync(&tp->schedule);
if (tp->speed & LINK_STATUS)
tp->rtl_ops.disable(tp);
}
tp->rtl_ops.up(tp);
rtl8152_set_speed(tp, AUTONEG_ENABLE,
tp->mii.supports_gmii ? SPEED_1000 : SPEED_100,
DUPLEX_FULL);
tp->speed = 0;
netif_carrier_off(netdev);
netif_start_queue(netdev);
set_bit(WORK_ENABLE, &tp->flags);
res = usb_submit_urb(tp->intr_urb, GFP_KERNEL);
if (res) {
if (res == -ENODEV)
netif_device_detach(tp->netdev);
netif_warn(tp, ifup, netdev, "intr_urb submit failed: %d\n",
res);
free_all_mem(tp);
}
usb_autopm_put_interface(tp->intf);
out:
return res;
}
static int rtl8152_close(struct net_device *netdev)
{
struct r8152 *tp = netdev_priv(netdev);
int res = 0;
clear_bit(WORK_ENABLE, &tp->flags);
usb_kill_urb(tp->intr_urb);
cancel_delayed_work_sync(&tp->schedule);
netif_stop_queue(netdev);
res = usb_autopm_get_interface(tp->intf);
if (res < 0) {
rtl_drop_queued_tx(tp);
} else {
if (test_bit(SELECTIVE_SUSPEND, &tp->flags)) {
rtl_runtime_suspend_enable(tp, false);
clear_bit(SELECTIVE_SUSPEND, &tp->flags);
}
tasklet_disable(&tp->tl);
tp->rtl_ops.down(tp);
tasklet_enable(&tp->tl);
usb_autopm_put_interface(tp->intf);
}
free_all_mem(tp);
return res;
}
static void r8152b_enable_eee(struct r8152 *tp)
{
u32 ocp_data;
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_EEE_CR);
ocp_data |= EEE_RX_EN | EEE_TX_EN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_EEE_CR, ocp_data);
ocp_reg_write(tp, OCP_EEE_CONFIG1, RG_TXLPI_MSK_HFDUP | RG_MATCLR_EN |
EEE_10_CAP | EEE_NWAY_EN |
TX_QUIET_EN | RX_QUIET_EN |
SDRISETIME | RG_RXLPI_MSK_HFDUP |
SDFALLTIME);
ocp_reg_write(tp, OCP_EEE_CONFIG2, RG_LPIHYS_NUM | RG_DACQUIET_EN |
RG_LDVQUIET_EN | RG_CKRSEL |
RG_EEEPRG_EN);
ocp_reg_write(tp, OCP_EEE_CONFIG3, FST_SNR_EYE_R | RG_LFS_SEL | MSK_PH);
ocp_reg_write(tp, OCP_EEE_AR, FUN_ADDR | DEVICE_ADDR);
ocp_reg_write(tp, OCP_EEE_DATA, EEE_ADDR);
ocp_reg_write(tp, OCP_EEE_AR, FUN_DATA | DEVICE_ADDR);
ocp_reg_write(tp, OCP_EEE_DATA, EEE_DATA);
ocp_reg_write(tp, OCP_EEE_AR, 0x0000);
}
static void r8153_enable_eee(struct r8152 *tp)
{
u32 ocp_data;
u16 data;
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_EEE_CR);
ocp_data |= EEE_RX_EN | EEE_TX_EN;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_EEE_CR, ocp_data);
data = ocp_reg_read(tp, OCP_EEE_CFG);
data |= EEE10_EN;
ocp_reg_write(tp, OCP_EEE_CFG, data);
data = ocp_reg_read(tp, OCP_EEE_CFG2);
data |= MY1000_EEE | MY100_EEE;
ocp_reg_write(tp, OCP_EEE_CFG2, data);
}
static void r8152b_enable_fc(struct r8152 *tp)
{
u16 anar;
anar = r8152_mdio_read(tp, MII_ADVERTISE);
anar |= ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM;
r8152_mdio_write(tp, MII_ADVERTISE, anar);
}
static void rtl_tally_reset(struct r8152 *tp)
{
u32 ocp_data;
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_RSTTALLY);
ocp_data |= TALLY_RESET;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_RSTTALLY, ocp_data);
}
static void r8152b_init(struct r8152 *tp)
{
u32 ocp_data;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return;
if (tp->version == RTL_VER_01) {
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_LED_FEATURE);
ocp_data &= ~LED_MODE_MASK;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_LED_FEATURE, ocp_data);
}
r8152_power_cut_en(tp, false);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_PHY_PWR);
ocp_data |= TX_10M_IDLE_EN | PFM_PWM_SWITCH;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_PHY_PWR, ocp_data);
ocp_data = ocp_read_dword(tp, MCU_TYPE_PLA, PLA_MAC_PWR_CTRL);
ocp_data &= ~MCU_CLK_RATIO_MASK;
ocp_data |= MCU_CLK_RATIO | D3_CLK_GATED_EN;
ocp_write_dword(tp, MCU_TYPE_PLA, PLA_MAC_PWR_CTRL, ocp_data);
ocp_data = GPHY_STS_MSK | SPEED_DOWN_MSK |
SPDWN_RXDV_MSK | SPDWN_LINKCHG_MSK;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_GPHY_INTR_IMR, ocp_data);
r8152b_enable_eee(tp);
r8152b_enable_aldps(tp);
r8152b_enable_fc(tp);
rtl_tally_reset(tp);
ocp_data = ocp_read_word(tp, MCU_TYPE_USB, USB_USB_CTRL);
ocp_data &= ~RX_AGG_DISABLE;
ocp_write_word(tp, MCU_TYPE_USB, USB_USB_CTRL, ocp_data);
}
static void r8153_init(struct r8152 *tp)
{
u32 ocp_data;
int i;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return;
r8153_u1u2en(tp, false);
for (i = 0; i < 500; i++) {
if (ocp_read_word(tp, MCU_TYPE_PLA, PLA_BOOT_CTRL) &
AUTOLOAD_DONE)
break;
msleep(20);
}
for (i = 0; i < 500; i++) {
ocp_data = ocp_reg_read(tp, OCP_PHY_STATUS) & PHY_STAT_MASK;
if (ocp_data == PHY_STAT_LAN_ON || ocp_data == PHY_STAT_PWRDN)
break;
msleep(20);
}
r8153_u2p3en(tp, false);
ocp_data = ocp_read_word(tp, MCU_TYPE_USB, USB_WDT11_CTRL);
ocp_data &= ~TIMER11_EN;
ocp_write_word(tp, MCU_TYPE_USB, USB_WDT11_CTRL, ocp_data);
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_LED_FEATURE);
ocp_data &= ~LED_MODE_MASK;
ocp_write_word(tp, MCU_TYPE_PLA, PLA_LED_FEATURE, ocp_data);
ocp_data = ocp_read_byte(tp, MCU_TYPE_USB, USB_LPM_CTRL);
ocp_data &= ~LPM_TIMER_MASK;
if (tp->udev->speed == USB_SPEED_SUPER)
ocp_data |= LPM_TIMER_500US;
else
ocp_data |= LPM_TIMER_500MS;
ocp_write_byte(tp, MCU_TYPE_USB, USB_LPM_CTRL, ocp_data);
ocp_data = ocp_read_word(tp, MCU_TYPE_USB, USB_AFE_CTRL2);
ocp_data &= ~SEN_VAL_MASK;
ocp_data |= SEN_VAL_NORMAL | SEL_RXIDLE;
ocp_write_word(tp, MCU_TYPE_USB, USB_AFE_CTRL2, ocp_data);
r8153_power_cut_en(tp, false);
r8153_u1u2en(tp, true);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_MAC_PWR_CTRL, ALDPS_SPDWN_RATIO);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_MAC_PWR_CTRL2, EEE_SPDWN_RATIO);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_MAC_PWR_CTRL3,
PKT_AVAIL_SPDWN_EN | SUSPEND_SPDWN_EN |
U1U2_SPDWN_EN | L1_SPDWN_EN);
ocp_write_word(tp, MCU_TYPE_PLA, PLA_MAC_PWR_CTRL4,
PWRSAVE_SPDWN_EN | RXDV_SPDWN_EN | TX10MIDLE_EN |
TP100_SPDWN_EN | TP500_SPDWN_EN | TP1000_SPDWN_EN |
EEE_SPDWN_EN);
r8153_enable_eee(tp);
r8153_enable_aldps(tp);
r8152b_enable_fc(tp);
rtl_tally_reset(tp);
}
static int rtl8152_suspend(struct usb_interface *intf, pm_message_t message)
{
struct r8152 *tp = usb_get_intfdata(intf);
if (PMSG_IS_AUTO(message))
set_bit(SELECTIVE_SUSPEND, &tp->flags);
else
netif_device_detach(tp->netdev);
if (netif_running(tp->netdev)) {
clear_bit(WORK_ENABLE, &tp->flags);
usb_kill_urb(tp->intr_urb);
cancel_delayed_work_sync(&tp->schedule);
if (test_bit(SELECTIVE_SUSPEND, &tp->flags)) {
rtl_runtime_suspend_enable(tp, true);
} else {
tasklet_disable(&tp->tl);
tp->rtl_ops.down(tp);
tasklet_enable(&tp->tl);
}
}
return 0;
}
static int rtl8152_resume(struct usb_interface *intf)
{
struct r8152 *tp = usb_get_intfdata(intf);
if (!test_bit(SELECTIVE_SUSPEND, &tp->flags)) {
tp->rtl_ops.init(tp);
netif_device_attach(tp->netdev);
}
if (netif_running(tp->netdev)) {
if (test_bit(SELECTIVE_SUSPEND, &tp->flags)) {
rtl_runtime_suspend_enable(tp, false);
clear_bit(SELECTIVE_SUSPEND, &tp->flags);
if (tp->speed & LINK_STATUS)
tp->rtl_ops.disable(tp);
} else {
tp->rtl_ops.up(tp);
rtl8152_set_speed(tp, AUTONEG_ENABLE,
tp->mii.supports_gmii ? SPEED_1000 : SPEED_100,
DUPLEX_FULL);
}
tp->speed = 0;
netif_carrier_off(tp->netdev);
set_bit(WORK_ENABLE, &tp->flags);
usb_submit_urb(tp->intr_urb, GFP_KERNEL);
}
return 0;
}
static void rtl8152_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct r8152 *tp = netdev_priv(dev);
if (usb_autopm_get_interface(tp->intf) < 0)
return;
wol->supported = WAKE_ANY;
wol->wolopts = __rtl_get_wol(tp);
usb_autopm_put_interface(tp->intf);
}
static int rtl8152_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct r8152 *tp = netdev_priv(dev);
int ret;
ret = usb_autopm_get_interface(tp->intf);
if (ret < 0)
goto out_set_wol;
__rtl_set_wol(tp, wol->wolopts);
tp->saved_wolopts = wol->wolopts & WAKE_ANY;
usb_autopm_put_interface(tp->intf);
out_set_wol:
return ret;
}
static u32 rtl8152_get_msglevel(struct net_device *dev)
{
struct r8152 *tp = netdev_priv(dev);
return tp->msg_enable;
}
static void rtl8152_set_msglevel(struct net_device *dev, u32 value)
{
struct r8152 *tp = netdev_priv(dev);
tp->msg_enable = value;
}
static void rtl8152_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *info)
{
struct r8152 *tp = netdev_priv(netdev);
strncpy(info->driver, MODULENAME, ETHTOOL_BUSINFO_LEN);
strncpy(info->version, DRIVER_VERSION, ETHTOOL_BUSINFO_LEN);
usb_make_path(tp->udev, info->bus_info, sizeof(info->bus_info));
}
static
int rtl8152_get_settings(struct net_device *netdev, struct ethtool_cmd *cmd)
{
struct r8152 *tp = netdev_priv(netdev);
if (!tp->mii.mdio_read)
return -EOPNOTSUPP;
return mii_ethtool_gset(&tp->mii, cmd);
}
static int rtl8152_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct r8152 *tp = netdev_priv(dev);
int ret;
ret = usb_autopm_get_interface(tp->intf);
if (ret < 0)
goto out;
ret = rtl8152_set_speed(tp, cmd->autoneg, cmd->speed, cmd->duplex);
usb_autopm_put_interface(tp->intf);
out:
return ret;
}
static int rtl8152_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(rtl8152_gstrings);
default:
return -EOPNOTSUPP;
}
}
static void rtl8152_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct r8152 *tp = netdev_priv(dev);
struct tally_counter tally;
generic_ocp_read(tp, PLA_TALLYCNT, sizeof(tally), &tally, MCU_TYPE_PLA);
data[0] = le64_to_cpu(tally.tx_packets);
data[1] = le64_to_cpu(tally.rx_packets);
data[2] = le64_to_cpu(tally.tx_errors);
data[3] = le32_to_cpu(tally.rx_errors);
data[4] = le16_to_cpu(tally.rx_missed);
data[5] = le16_to_cpu(tally.align_errors);
data[6] = le32_to_cpu(tally.tx_one_collision);
data[7] = le32_to_cpu(tally.tx_multi_collision);
data[8] = le64_to_cpu(tally.rx_unicast);
data[9] = le64_to_cpu(tally.rx_broadcast);
data[10] = le32_to_cpu(tally.rx_multicast);
data[11] = le16_to_cpu(tally.tx_aborted);
data[12] = le16_to_cpu(tally.tx_underun);
}
static void rtl8152_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
switch (stringset) {
case ETH_SS_STATS:
memcpy(data, *rtl8152_gstrings, sizeof(rtl8152_gstrings));
break;
}
}
static int rtl8152_ioctl(struct net_device *netdev, struct ifreq *rq, int cmd)
{
struct r8152 *tp = netdev_priv(netdev);
struct mii_ioctl_data *data = if_mii(rq);
int res;
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return -ENODEV;
res = usb_autopm_get_interface(tp->intf);
if (res < 0)
goto out;
switch (cmd) {
case SIOCGMIIPHY:
data->phy_id = R8152_PHY_ID;
break;
case SIOCGMIIREG:
data->val_out = r8152_mdio_read(tp, data->reg_num);
break;
case SIOCSMIIREG:
if (!capable(CAP_NET_ADMIN)) {
res = -EPERM;
break;
}
r8152_mdio_write(tp, data->reg_num, data->val_in);
break;
default:
res = -EOPNOTSUPP;
}
usb_autopm_put_interface(tp->intf);
out:
return res;
}
static void r8152b_get_version(struct r8152 *tp)
{
u32 ocp_data;
u16 version;
ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_TCR1);
version = (u16)(ocp_data & VERSION_MASK);
switch (version) {
case 0x4c00:
tp->version = RTL_VER_01;
break;
case 0x4c10:
tp->version = RTL_VER_02;
break;
case 0x5c00:
tp->version = RTL_VER_03;
tp->mii.supports_gmii = 1;
break;
case 0x5c10:
tp->version = RTL_VER_04;
tp->mii.supports_gmii = 1;
break;
case 0x5c20:
tp->version = RTL_VER_05;
tp->mii.supports_gmii = 1;
break;
default:
netif_info(tp, probe, tp->netdev,
"Unknown version 0x%04x\n", version);
break;
}
}
static void rtl8152_unload(struct r8152 *tp)
{
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return;
if (tp->version != RTL_VER_01)
r8152_power_cut_en(tp, true);
}
static void rtl8153_unload(struct r8152 *tp)
{
if (test_bit(RTL8152_UNPLUG, &tp->flags))
return;
r8153_power_cut_en(tp, true);
}
static int rtl_ops_init(struct r8152 *tp, const struct usb_device_id *id)
{
struct rtl_ops *ops = &tp->rtl_ops;
int ret = -ENODEV;
switch (id->idVendor) {
case VENDOR_ID_REALTEK:
switch (id->idProduct) {
case PRODUCT_ID_RTL8152:
ops->init = r8152b_init;
ops->enable = rtl8152_enable;
ops->disable = rtl8152_disable;
ops->up = r8152b_exit_oob;
ops->down = rtl8152_down;
ops->unload = rtl8152_unload;
ret = 0;
break;
case PRODUCT_ID_RTL8153:
ops->init = r8153_init;
ops->enable = rtl8153_enable;
ops->disable = rtl8152_disable;
ops->up = r8153_first_init;
ops->down = rtl8153_down;
ops->unload = rtl8153_unload;
ret = 0;
break;
default:
break;
}
break;
case VENDOR_ID_SAMSUNG:
switch (id->idProduct) {
case PRODUCT_ID_SAMSUNG:
ops->init = r8153_init;
ops->enable = rtl8153_enable;
ops->disable = rtl8152_disable;
ops->up = r8153_first_init;
ops->down = rtl8153_down;
ops->unload = rtl8153_unload;
ret = 0;
break;
default:
break;
}
break;
default:
break;
}
if (ret)
netif_err(tp, probe, tp->netdev, "Unknown Device\n");
return ret;
}
static int rtl8152_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct r8152 *tp;
struct net_device *netdev;
int ret;
if (udev->actconfig->desc.bConfigurationValue != 1) {
usb_driver_set_configuration(udev, 1);
return -ENODEV;
}
usb_reset_device(udev);
netdev = alloc_etherdev(sizeof(struct r8152));
if (!netdev) {
dev_err(&intf->dev, "Out of memory\n");
return -ENOMEM;
}
SET_NETDEV_DEV(netdev, &intf->dev);
tp = netdev_priv(netdev);
tp->msg_enable = 0x7FFF;
tp->udev = udev;
tp->netdev = netdev;
tp->intf = intf;
ret = rtl_ops_init(tp, id);
if (ret)
goto out;
tasklet_init(&tp->tl, bottom_half, (unsigned long)tp);
INIT_DELAYED_WORK(&tp->schedule, rtl_work_func_t);
netdev->netdev_ops = &rtl8152_netdev_ops;
netdev->watchdog_timeo = RTL8152_TX_TIMEOUT;
netdev->features |= NETIF_F_RXCSUM | NETIF_F_IP_CSUM | NETIF_F_SG |
NETIF_F_TSO | NETIF_F_FRAGLIST | NETIF_F_IPV6_CSUM |
NETIF_F_TSO6;
netdev->hw_features = NETIF_F_RXCSUM | NETIF_F_IP_CSUM | NETIF_F_SG |
NETIF_F_TSO | NETIF_F_FRAGLIST |
NETIF_F_IPV6_CSUM | NETIF_F_TSO6;
SET_ETHTOOL_OPS(netdev, &ops);
netif_set_gso_max_size(netdev, RTL_LIMITED_TSO_SIZE);
tp->mii.dev = netdev;
tp->mii.mdio_read = read_mii_word;
tp->mii.mdio_write = write_mii_word;
tp->mii.phy_id_mask = 0x3f;
tp->mii.reg_num_mask = 0x1f;
tp->mii.phy_id = R8152_PHY_ID;
tp->mii.supports_gmii = 0;
intf->needs_remote_wakeup = 1;
r8152b_get_version(tp);
tp->rtl_ops.init(tp);
set_ethernet_addr(tp);
usb_set_intfdata(intf, tp);
ret = register_netdev(netdev);
if (ret != 0) {
netif_err(tp, probe, netdev, "couldn't register the device\n");
goto out1;
}
tp->saved_wolopts = __rtl_get_wol(tp);
if (tp->saved_wolopts)
device_set_wakeup_enable(&udev->dev, true);
else
device_set_wakeup_enable(&udev->dev, false);
netif_info(tp, probe, netdev, "%s\n", DRIVER_VERSION);
return 0;
out1:
usb_set_intfdata(intf, NULL);
out:
free_netdev(netdev);
return ret;
}
static void rtl8152_disconnect(struct usb_interface *intf)
{
struct r8152 *tp = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
if (tp) {
set_bit(RTL8152_UNPLUG, &tp->flags);
tasklet_kill(&tp->tl);
unregister_netdev(tp->netdev);
tp->rtl_ops.unload(tp);
free_netdev(tp->netdev);
}
}
