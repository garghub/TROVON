static inline u64 readq(void __iomem *addr)
{
return readl(addr) | (((u64) readl(addr + 4)) << 32LL);
}
static inline void writeq(u64 val, void __iomem *addr)
{
writel(((u32) (val)), (addr));
writel(((u32) (val >> 32)), (addr + 4));
}
static void __iomem *pci_base_offset(struct netxen_adapter *adapter,
unsigned long off)
{
if (ADDR_IN_RANGE(off, FIRST_PAGE_GROUP_START, FIRST_PAGE_GROUP_END))
return PCI_OFFSET_FIRST_RANGE(adapter, off);
if (ADDR_IN_RANGE(off, SECOND_PAGE_GROUP_START, SECOND_PAGE_GROUP_END))
return PCI_OFFSET_SECOND_RANGE(adapter, off);
if (ADDR_IN_RANGE(off, THIRD_PAGE_GROUP_START, THIRD_PAGE_GROUP_END))
return PCI_OFFSET_THIRD_RANGE(adapter, off);
return NULL;
}
int
netxen_pcie_sem_lock(struct netxen_adapter *adapter, int sem, u32 id_reg)
{
int done = 0, timeout = 0;
while (!done) {
done = NXRD32(adapter, NETXEN_PCIE_REG(PCIE_SEM_LOCK(sem)));
if (done == 1)
break;
if (++timeout >= NETXEN_PCIE_SEM_TIMEOUT)
return -EIO;
msleep(1);
}
if (id_reg)
NXWR32(adapter, id_reg, adapter->portnum);
return 0;
}
void
netxen_pcie_sem_unlock(struct netxen_adapter *adapter, int sem)
{
NXRD32(adapter, NETXEN_PCIE_REG(PCIE_SEM_UNLOCK(sem)));
}
static int netxen_niu_xg_init_port(struct netxen_adapter *adapter, int port)
{
if (NX_IS_REVISION_P2(adapter->ahw.revision_id)) {
NXWR32(adapter, NETXEN_NIU_XGE_CONFIG_1+(0x10000*port), 0x1447);
NXWR32(adapter, NETXEN_NIU_XGE_CONFIG_0+(0x10000*port), 0x5);
}
return 0;
}
static int netxen_niu_disable_xg_port(struct netxen_adapter *adapter)
{
__u32 mac_cfg;
u32 port = adapter->physical_port;
if (NX_IS_REVISION_P3(adapter->ahw.revision_id))
return 0;
if (port > NETXEN_NIU_MAX_XG_PORTS)
return -EINVAL;
mac_cfg = 0;
if (NXWR32(adapter,
NETXEN_NIU_XGE_CONFIG_0 + (0x10000 * port), mac_cfg))
return -EIO;
return 0;
}
static int netxen_p2_nic_set_promisc(struct netxen_adapter *adapter, u32 mode)
{
u32 mac_cfg;
u32 cnt = 0;
__u32 reg = 0x0200;
u32 port = adapter->physical_port;
u16 board_type = adapter->ahw.board_type;
if (port > NETXEN_NIU_MAX_XG_PORTS)
return -EINVAL;
mac_cfg = NXRD32(adapter, NETXEN_NIU_XGE_CONFIG_0 + (0x10000 * port));
mac_cfg &= ~0x4;
NXWR32(adapter, NETXEN_NIU_XGE_CONFIG_0 + (0x10000 * port), mac_cfg);
if ((board_type == NETXEN_BRDTYPE_P2_SB31_10G_IMEZ) ||
(board_type == NETXEN_BRDTYPE_P2_SB31_10G_HMEZ))
reg = (0x20 << port);
NXWR32(adapter, NETXEN_NIU_FRAME_COUNT_SELECT, reg);
mdelay(10);
while (NXRD32(adapter, NETXEN_NIU_FRAME_COUNT) && ++cnt < 20)
mdelay(10);
if (cnt < 20) {
reg = NXRD32(adapter,
NETXEN_NIU_XGE_CONFIG_1 + (0x10000 * port));
if (mode == NETXEN_NIU_PROMISC_MODE)
reg = (reg | 0x2000UL);
else
reg = (reg & ~0x2000UL);
if (mode == NETXEN_NIU_ALLMULTI_MODE)
reg = (reg | 0x1000UL);
else
reg = (reg & ~0x1000UL);
NXWR32(adapter,
NETXEN_NIU_XGE_CONFIG_1 + (0x10000 * port), reg);
}
mac_cfg |= 0x4;
NXWR32(adapter, NETXEN_NIU_XGE_CONFIG_0 + (0x10000 * port), mac_cfg);
return 0;
}
static int netxen_p2_nic_set_mac_addr(struct netxen_adapter *adapter, u8 *addr)
{
u32 mac_hi, mac_lo;
u32 reg_hi, reg_lo;
u8 phy = adapter->physical_port;
if (phy >= NETXEN_NIU_MAX_XG_PORTS)
return -EINVAL;
mac_lo = ((u32)addr[0] << 16) | ((u32)addr[1] << 24);
mac_hi = addr[2] | ((u32)addr[3] << 8) |
((u32)addr[4] << 16) | ((u32)addr[5] << 24);
reg_lo = NETXEN_NIU_XGE_STATION_ADDR_0_1 + (0x10000 * phy);
reg_hi = NETXEN_NIU_XGE_STATION_ADDR_0_HI + (0x10000 * phy);
if (NXWR32(adapter, reg_lo, mac_lo) || NXWR32(adapter, reg_hi, mac_hi))
return -EIO;
if (NXWR32(adapter, reg_lo, mac_lo) || NXWR32(adapter, reg_hi, mac_hi))
return -EIO;
return 0;
}
static int
netxen_nic_enable_mcast_filter(struct netxen_adapter *adapter)
{
u32 val = 0;
u16 port = adapter->physical_port;
u8 *addr = adapter->mac_addr;
if (adapter->mc_enabled)
return 0;
val = NXRD32(adapter, NETXEN_MAC_ADDR_CNTL_REG);
val |= (1UL << (28+port));
NXWR32(adapter, NETXEN_MAC_ADDR_CNTL_REG, val);
val = 0xffffff;
NXWR32(adapter, NETXEN_UNICAST_ADDR(port, 0), val);
NXWR32(adapter, NETXEN_UNICAST_ADDR(port, 0)+4, val);
val = MAC_HI(addr);
NXWR32(adapter, NETXEN_UNICAST_ADDR(port, 1), val);
val = MAC_LO(addr);
NXWR32(adapter, NETXEN_UNICAST_ADDR(port, 1)+4, val);
adapter->mc_enabled = 1;
return 0;
}
static int
netxen_nic_disable_mcast_filter(struct netxen_adapter *adapter)
{
u32 val = 0;
u16 port = adapter->physical_port;
u8 *addr = adapter->mac_addr;
if (!adapter->mc_enabled)
return 0;
val = NXRD32(adapter, NETXEN_MAC_ADDR_CNTL_REG);
val &= ~(1UL << (28+port));
NXWR32(adapter, NETXEN_MAC_ADDR_CNTL_REG, val);
val = MAC_HI(addr);
NXWR32(adapter, NETXEN_UNICAST_ADDR(port, 0), val);
val = MAC_LO(addr);
NXWR32(adapter, NETXEN_UNICAST_ADDR(port, 0)+4, val);
NXWR32(adapter, NETXEN_UNICAST_ADDR(port, 1), 0);
NXWR32(adapter, NETXEN_UNICAST_ADDR(port, 1)+4, 0);
adapter->mc_enabled = 0;
return 0;
}
static int
netxen_nic_set_mcast_addr(struct netxen_adapter *adapter,
int index, u8 *addr)
{
u32 hi = 0, lo = 0;
u16 port = adapter->physical_port;
lo = MAC_LO(addr);
hi = MAC_HI(addr);
NXWR32(adapter, NETXEN_MCAST_ADDR(port, index), hi);
NXWR32(adapter, NETXEN_MCAST_ADDR(port, index)+4, lo);
return 0;
}
static void netxen_p2_nic_set_multi(struct net_device *netdev)
{
struct netxen_adapter *adapter = netdev_priv(netdev);
struct netdev_hw_addr *ha;
u8 null_addr[6];
int i;
memset(null_addr, 0, 6);
if (netdev->flags & IFF_PROMISC) {
adapter->set_promisc(adapter,
NETXEN_NIU_PROMISC_MODE);
netxen_nic_disable_mcast_filter(adapter);
return;
}
if (netdev_mc_empty(netdev)) {
adapter->set_promisc(adapter,
NETXEN_NIU_NON_PROMISC_MODE);
netxen_nic_disable_mcast_filter(adapter);
return;
}
adapter->set_promisc(adapter, NETXEN_NIU_ALLMULTI_MODE);
if (netdev->flags & IFF_ALLMULTI ||
netdev_mc_count(netdev) > adapter->max_mc_count) {
netxen_nic_disable_mcast_filter(adapter);
return;
}
netxen_nic_enable_mcast_filter(adapter);
i = 0;
netdev_for_each_mc_addr(ha, netdev)
netxen_nic_set_mcast_addr(adapter, i++, ha->addr);
while (i < adapter->max_mc_count)
netxen_nic_set_mcast_addr(adapter, i++, null_addr);
}
static int
netxen_send_cmd_descs(struct netxen_adapter *adapter,
struct cmd_desc_type0 *cmd_desc_arr, int nr_desc)
{
u32 i, producer, consumer;
struct netxen_cmd_buffer *pbuf;
struct cmd_desc_type0 *cmd_desc;
struct nx_host_tx_ring *tx_ring;
i = 0;
if (adapter->is_up != NETXEN_ADAPTER_UP_MAGIC)
return -EIO;
tx_ring = adapter->tx_ring;
__netif_tx_lock_bh(tx_ring->txq);
producer = tx_ring->producer;
consumer = tx_ring->sw_consumer;
if (nr_desc >= netxen_tx_avail(tx_ring)) {
netif_tx_stop_queue(tx_ring->txq);
smp_mb();
if (netxen_tx_avail(tx_ring) > nr_desc) {
if (netxen_tx_avail(tx_ring) > TX_STOP_THRESH)
netif_tx_wake_queue(tx_ring->txq);
} else {
__netif_tx_unlock_bh(tx_ring->txq);
return -EBUSY;
}
}
do {
cmd_desc = &cmd_desc_arr[i];
pbuf = &tx_ring->cmd_buf_arr[producer];
pbuf->skb = NULL;
pbuf->frag_count = 0;
memcpy(&tx_ring->desc_head[producer],
&cmd_desc_arr[i], sizeof(struct cmd_desc_type0));
producer = get_next_index(producer, tx_ring->num_desc);
i++;
} while (i != nr_desc);
tx_ring->producer = producer;
netxen_nic_update_cmd_producer(adapter, tx_ring);
__netif_tx_unlock_bh(tx_ring->txq);
return 0;
}
static int
nx_p3_sre_macaddr_change(struct netxen_adapter *adapter, u8 *addr, unsigned op)
{
nx_nic_req_t req;
nx_mac_req_t *mac_req;
u64 word;
memset(&req, 0, sizeof(nx_nic_req_t));
req.qhdr = cpu_to_le64(NX_NIC_REQUEST << 23);
word = NX_MAC_EVENT | ((u64)adapter->portnum << 16);
req.req_hdr = cpu_to_le64(word);
mac_req = (nx_mac_req_t *)&req.words[0];
mac_req->op = op;
memcpy(mac_req->mac_addr, addr, 6);
return netxen_send_cmd_descs(adapter, (struct cmd_desc_type0 *)&req, 1);
}
static int nx_p3_nic_add_mac(struct netxen_adapter *adapter,
const u8 *addr, struct list_head *del_list)
{
struct list_head *head;
nx_mac_list_t *cur;
list_for_each(head, del_list) {
cur = list_entry(head, nx_mac_list_t, list);
if (memcmp(addr, cur->mac_addr, ETH_ALEN) == 0) {
list_move_tail(head, &adapter->mac_list);
return 0;
}
}
cur = kzalloc(sizeof(nx_mac_list_t), GFP_ATOMIC);
if (cur == NULL) {
printk(KERN_ERR "%s: failed to add mac address filter\n",
adapter->netdev->name);
return -ENOMEM;
}
memcpy(cur->mac_addr, addr, ETH_ALEN);
list_add_tail(&cur->list, &adapter->mac_list);
return nx_p3_sre_macaddr_change(adapter,
cur->mac_addr, NETXEN_MAC_ADD);
}
static void netxen_p3_nic_set_multi(struct net_device *netdev)
{
struct netxen_adapter *adapter = netdev_priv(netdev);
struct netdev_hw_addr *ha;
static const u8 bcast_addr[ETH_ALEN] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
u32 mode = VPORT_MISS_MODE_DROP;
LIST_HEAD(del_list);
struct list_head *head;
nx_mac_list_t *cur;
if (adapter->is_up != NETXEN_ADAPTER_UP_MAGIC)
return;
list_splice_tail_init(&adapter->mac_list, &del_list);
nx_p3_nic_add_mac(adapter, adapter->mac_addr, &del_list);
nx_p3_nic_add_mac(adapter, bcast_addr, &del_list);
if (netdev->flags & IFF_PROMISC) {
mode = VPORT_MISS_MODE_ACCEPT_ALL;
goto send_fw_cmd;
}
if ((netdev->flags & IFF_ALLMULTI) ||
(netdev_mc_count(netdev) > adapter->max_mc_count)) {
mode = VPORT_MISS_MODE_ACCEPT_MULTI;
goto send_fw_cmd;
}
if (!netdev_mc_empty(netdev)) {
netdev_for_each_mc_addr(ha, netdev)
nx_p3_nic_add_mac(adapter, ha->addr, &del_list);
}
send_fw_cmd:
adapter->set_promisc(adapter, mode);
head = &del_list;
while (!list_empty(head)) {
cur = list_entry(head->next, nx_mac_list_t, list);
nx_p3_sre_macaddr_change(adapter,
cur->mac_addr, NETXEN_MAC_DEL);
list_del(&cur->list);
kfree(cur);
}
}
static int netxen_p3_nic_set_promisc(struct netxen_adapter *adapter, u32 mode)
{
nx_nic_req_t req;
u64 word;
memset(&req, 0, sizeof(nx_nic_req_t));
req.qhdr = cpu_to_le64(NX_HOST_REQUEST << 23);
word = NX_NIC_H2C_OPCODE_PROXY_SET_VPORT_MISS_MODE |
((u64)adapter->portnum << 16);
req.req_hdr = cpu_to_le64(word);
req.words[0] = cpu_to_le64(mode);
return netxen_send_cmd_descs(adapter,
(struct cmd_desc_type0 *)&req, 1);
}
void netxen_p3_free_mac_list(struct netxen_adapter *adapter)
{
nx_mac_list_t *cur;
struct list_head *head = &adapter->mac_list;
while (!list_empty(head)) {
cur = list_entry(head->next, nx_mac_list_t, list);
nx_p3_sre_macaddr_change(adapter,
cur->mac_addr, NETXEN_MAC_DEL);
list_del(&cur->list);
kfree(cur);
}
}
static int netxen_p3_nic_set_mac_addr(struct netxen_adapter *adapter, u8 *addr)
{
netxen_p3_nic_set_multi(adapter->netdev);
return 0;
}
int netxen_config_intr_coalesce(struct netxen_adapter *adapter)
{
nx_nic_req_t req;
u64 word[6];
int rv, i;
memset(&req, 0, sizeof(nx_nic_req_t));
memset(word, 0, sizeof(word));
req.qhdr = cpu_to_le64(NX_HOST_REQUEST << 23);
word[0] = NETXEN_CONFIG_INTR_COALESCE | ((u64)adapter->portnum << 16);
req.req_hdr = cpu_to_le64(word[0]);
memcpy(&word[0], &adapter->coal, sizeof(adapter->coal));
for (i = 0; i < 6; i++)
req.words[i] = cpu_to_le64(word[i]);
rv = netxen_send_cmd_descs(adapter, (struct cmd_desc_type0 *)&req, 1);
if (rv != 0) {
printk(KERN_ERR "ERROR. Could not send "
"interrupt coalescing parameters\n");
}
return rv;
}
int netxen_config_hw_lro(struct netxen_adapter *adapter, int enable)
{
nx_nic_req_t req;
u64 word;
int rv = 0;
if (!test_bit(__NX_FW_ATTACHED, &adapter->state))
return 0;
memset(&req, 0, sizeof(nx_nic_req_t));
req.qhdr = cpu_to_le64(NX_HOST_REQUEST << 23);
word = NX_NIC_H2C_OPCODE_CONFIG_HW_LRO | ((u64)adapter->portnum << 16);
req.req_hdr = cpu_to_le64(word);
req.words[0] = cpu_to_le64(enable);
rv = netxen_send_cmd_descs(adapter, (struct cmd_desc_type0 *)&req, 1);
if (rv != 0) {
printk(KERN_ERR "ERROR. Could not send "
"configure hw lro request\n");
}
return rv;
}
int netxen_config_bridged_mode(struct netxen_adapter *adapter, int enable)
{
nx_nic_req_t req;
u64 word;
int rv = 0;
if (!!(adapter->flags & NETXEN_NIC_BRIDGE_ENABLED) == enable)
return rv;
memset(&req, 0, sizeof(nx_nic_req_t));
req.qhdr = cpu_to_le64(NX_HOST_REQUEST << 23);
word = NX_NIC_H2C_OPCODE_CONFIG_BRIDGING |
((u64)adapter->portnum << 16);
req.req_hdr = cpu_to_le64(word);
req.words[0] = cpu_to_le64(enable);
rv = netxen_send_cmd_descs(adapter, (struct cmd_desc_type0 *)&req, 1);
if (rv != 0) {
printk(KERN_ERR "ERROR. Could not send "
"configure bridge mode request\n");
}
adapter->flags ^= NETXEN_NIC_BRIDGE_ENABLED;
return rv;
}
int netxen_config_rss(struct netxen_adapter *adapter, int enable)
{
nx_nic_req_t req;
u64 word;
int i, rv;
static const u64 key[] = {
0xbeac01fa6a42b73bULL, 0x8030f20c77cb2da3ULL,
0xae7b30b4d0ca2bcbULL, 0x43a38fb04167253dULL,
0x255b0ec26d5a56daULL
};
memset(&req, 0, sizeof(nx_nic_req_t));
req.qhdr = cpu_to_le64(NX_HOST_REQUEST << 23);
word = NX_NIC_H2C_OPCODE_CONFIG_RSS | ((u64)adapter->portnum << 16);
req.req_hdr = cpu_to_le64(word);
word = ((u64)(RSS_HASHTYPE_IP_TCP & 0x3) << 4) |
((u64)(RSS_HASHTYPE_IP_TCP & 0x3) << 6) |
((u64)(enable & 0x1) << 8) |
((0x7ULL) << 48);
req.words[0] = cpu_to_le64(word);
for (i = 0; i < ARRAY_SIZE(key); i++)
req.words[i+1] = cpu_to_le64(key[i]);
rv = netxen_send_cmd_descs(adapter, (struct cmd_desc_type0 *)&req, 1);
if (rv != 0) {
printk(KERN_ERR "%s: could not configure RSS\n",
adapter->netdev->name);
}
return rv;
}
int netxen_config_ipaddr(struct netxen_adapter *adapter, u32 ip, int cmd)
{
nx_nic_req_t req;
u64 word;
int rv;
memset(&req, 0, sizeof(nx_nic_req_t));
req.qhdr = cpu_to_le64(NX_HOST_REQUEST << 23);
word = NX_NIC_H2C_OPCODE_CONFIG_IPADDR | ((u64)adapter->portnum << 16);
req.req_hdr = cpu_to_le64(word);
req.words[0] = cpu_to_le64(cmd);
req.words[1] = cpu_to_le64(ip);
rv = netxen_send_cmd_descs(adapter, (struct cmd_desc_type0 *)&req, 1);
if (rv != 0) {
printk(KERN_ERR "%s: could not notify %s IP 0x%x reuqest\n",
adapter->netdev->name,
(cmd == NX_IP_UP) ? "Add" : "Remove", ip);
}
return rv;
}
int netxen_linkevent_request(struct netxen_adapter *adapter, int enable)
{
nx_nic_req_t req;
u64 word;
int rv;
memset(&req, 0, sizeof(nx_nic_req_t));
req.qhdr = cpu_to_le64(NX_HOST_REQUEST << 23);
word = NX_NIC_H2C_OPCODE_GET_LINKEVENT | ((u64)adapter->portnum << 16);
req.req_hdr = cpu_to_le64(word);
req.words[0] = cpu_to_le64(enable | (enable << 8));
rv = netxen_send_cmd_descs(adapter, (struct cmd_desc_type0 *)&req, 1);
if (rv != 0) {
printk(KERN_ERR "%s: could not configure link notification\n",
adapter->netdev->name);
}
return rv;
}
int netxen_send_lro_cleanup(struct netxen_adapter *adapter)
{
nx_nic_req_t req;
u64 word;
int rv;
if (!test_bit(__NX_FW_ATTACHED, &adapter->state))
return 0;
memset(&req, 0, sizeof(nx_nic_req_t));
req.qhdr = cpu_to_le64(NX_HOST_REQUEST << 23);
word = NX_NIC_H2C_OPCODE_LRO_REQUEST |
((u64)adapter->portnum << 16) |
((u64)NX_NIC_LRO_REQUEST_CLEANUP << 56) ;
req.req_hdr = cpu_to_le64(word);
rv = netxen_send_cmd_descs(adapter, (struct cmd_desc_type0 *)&req, 1);
if (rv != 0) {
printk(KERN_ERR "%s: could not cleanup lro flows\n",
adapter->netdev->name);
}
return rv;
}
int netxen_nic_change_mtu(struct net_device *netdev, int mtu)
{
struct netxen_adapter *adapter = netdev_priv(netdev);
int max_mtu;
int rc = 0;
if (NX_IS_REVISION_P3(adapter->ahw.revision_id))
max_mtu = P3_MAX_MTU;
else
max_mtu = P2_MAX_MTU;
if (mtu > max_mtu) {
printk(KERN_ERR "%s: mtu > %d bytes unsupported\n",
netdev->name, max_mtu);
return -EINVAL;
}
if (adapter->set_mtu)
rc = adapter->set_mtu(adapter, mtu);
if (!rc)
netdev->mtu = mtu;
return rc;
}
static int netxen_get_flash_block(struct netxen_adapter *adapter, int base,
int size, __le32 * buf)
{
int i, v, addr;
__le32 *ptr32;
addr = base;
ptr32 = buf;
for (i = 0; i < size / sizeof(u32); i++) {
if (netxen_rom_fast_read(adapter, addr, &v) == -1)
return -1;
*ptr32 = cpu_to_le32(v);
ptr32++;
addr += sizeof(u32);
}
if ((char *)buf + size > (char *)ptr32) {
__le32 local;
if (netxen_rom_fast_read(adapter, addr, &v) == -1)
return -1;
local = cpu_to_le32(v);
memcpy(ptr32, &local, (char *)buf + size - (char *)ptr32);
}
return 0;
}
int netxen_get_flash_mac_addr(struct netxen_adapter *adapter, u64 *mac)
{
__le32 *pmac = (__le32 *) mac;
u32 offset;
offset = NX_FW_MAC_ADDR_OFFSET + (adapter->portnum * sizeof(u64));
if (netxen_get_flash_block(adapter, offset, sizeof(u64), pmac) == -1)
return -1;
if (*mac == cpu_to_le64(~0ULL)) {
offset = NX_OLD_MAC_ADDR_OFFSET +
(adapter->portnum * sizeof(u64));
if (netxen_get_flash_block(adapter,
offset, sizeof(u64), pmac) == -1)
return -1;
if (*mac == cpu_to_le64(~0ULL))
return -1;
}
return 0;
}
int netxen_p3_get_mac_addr(struct netxen_adapter *adapter, u64 *mac)
{
uint32_t crbaddr, mac_hi, mac_lo;
int pci_func = adapter->ahw.pci_func;
crbaddr = CRB_MAC_BLOCK_START +
(4 * ((pci_func/2) * 3)) + (4 * (pci_func & 1));
mac_lo = NXRD32(adapter, crbaddr);
mac_hi = NXRD32(adapter, crbaddr+4);
if (pci_func & 1)
*mac = le64_to_cpu((mac_lo >> 16) | ((u64)mac_hi << 16));
else
*mac = le64_to_cpu((u64)mac_lo | ((u64)mac_hi << 32));
return 0;
}
static void
netxen_nic_pci_set_crbwindow_128M(struct netxen_adapter *adapter,
u32 window)
{
void __iomem *offset;
int count = 10;
u8 func = adapter->ahw.pci_func;
if (adapter->ahw.crb_win == window)
return;
offset = PCI_OFFSET_SECOND_RANGE(adapter,
NETXEN_PCIX_PH_REG(PCIE_CRB_WINDOW_REG(func)));
writel(window, offset);
do {
if (window == readl(offset))
break;
if (printk_ratelimit())
dev_warn(&adapter->pdev->dev,
"failed to set CRB window to %d\n",
(window == NETXEN_WINDOW_ONE));
udelay(1);
} while (--count > 0);
if (count > 0)
adapter->ahw.crb_win = window;
}
static int
netxen_nic_pci_get_crb_addr_2M(struct netxen_adapter *adapter,
ulong off, void __iomem **addr)
{
crb_128M_2M_sub_block_map_t *m;
if ((off >= NETXEN_CRB_MAX) || (off < NETXEN_PCI_CRBSPACE))
return -EINVAL;
off -= NETXEN_PCI_CRBSPACE;
m = &crb_128M_2M_map[CRB_BLK(off)].sub_block[CRB_SUBBLK(off)];
if (m->valid && (m->start_128M <= off) && (m->end_128M > off)) {
*addr = adapter->ahw.pci_base0 + m->start_2M +
(off - m->start_128M);
return 0;
}
*addr = adapter->ahw.pci_base0 + CRB_INDIRECT_2M +
(off & MASK(16));
return 1;
}
static void
netxen_nic_pci_set_crbwindow_2M(struct netxen_adapter *adapter, ulong off)
{
u32 window;
void __iomem *addr = adapter->ahw.pci_base0 + CRB_WINDOW_2M;
off -= NETXEN_PCI_CRBSPACE;
window = CRB_HI(off);
writel(window, addr);
if (readl(addr) != window) {
if (printk_ratelimit())
dev_warn(&adapter->pdev->dev,
"failed to set CRB window to %d off 0x%lx\n",
window, off);
}
}
static void __iomem *
netxen_nic_map_indirect_address_128M(struct netxen_adapter *adapter,
ulong win_off, void __iomem **mem_ptr)
{
ulong off = win_off;
void __iomem *addr;
resource_size_t mem_base;
if (ADDR_IN_WINDOW1(win_off))
off = NETXEN_CRB_NORMAL(win_off);
addr = pci_base_offset(adapter, off);
if (addr)
return addr;
if (adapter->ahw.pci_len0 == 0)
off -= NETXEN_PCI_CRBSPACE;
mem_base = pci_resource_start(adapter->pdev, 0);
*mem_ptr = ioremap(mem_base + (off & PAGE_MASK), PAGE_SIZE);
if (*mem_ptr)
addr = *mem_ptr + (off & (PAGE_SIZE - 1));
return addr;
}
static int
netxen_nic_hw_write_wx_128M(struct netxen_adapter *adapter, ulong off, u32 data)
{
unsigned long flags;
void __iomem *addr, *mem_ptr = NULL;
addr = netxen_nic_map_indirect_address_128M(adapter, off, &mem_ptr);
if (!addr)
return -EIO;
if (ADDR_IN_WINDOW1(off)) {
netxen_nic_io_write_128M(adapter, addr, data);
} else {
write_lock_irqsave(&adapter->ahw.crb_lock, flags);
netxen_nic_pci_set_crbwindow_128M(adapter, 0);
writel(data, addr);
netxen_nic_pci_set_crbwindow_128M(adapter,
NETXEN_WINDOW_ONE);
write_unlock_irqrestore(&adapter->ahw.crb_lock, flags);
}
if (mem_ptr)
iounmap(mem_ptr);
return 0;
}
static u32
netxen_nic_hw_read_wx_128M(struct netxen_adapter *adapter, ulong off)
{
unsigned long flags;
void __iomem *addr, *mem_ptr = NULL;
u32 data;
addr = netxen_nic_map_indirect_address_128M(adapter, off, &mem_ptr);
if (!addr)
return -EIO;
if (ADDR_IN_WINDOW1(off)) {
data = netxen_nic_io_read_128M(adapter, addr);
} else {
write_lock_irqsave(&adapter->ahw.crb_lock, flags);
netxen_nic_pci_set_crbwindow_128M(adapter, 0);
data = readl(addr);
netxen_nic_pci_set_crbwindow_128M(adapter,
NETXEN_WINDOW_ONE);
write_unlock_irqrestore(&adapter->ahw.crb_lock, flags);
}
if (mem_ptr)
iounmap(mem_ptr);
return data;
}
static int
netxen_nic_hw_write_wx_2M(struct netxen_adapter *adapter, ulong off, u32 data)
{
unsigned long flags;
int rv;
void __iomem *addr = NULL;
rv = netxen_nic_pci_get_crb_addr_2M(adapter, off, &addr);
if (rv == 0) {
writel(data, addr);
return 0;
}
if (rv > 0) {
write_lock_irqsave(&adapter->ahw.crb_lock, flags);
crb_win_lock(adapter);
netxen_nic_pci_set_crbwindow_2M(adapter, off);
writel(data, addr);
crb_win_unlock(adapter);
write_unlock_irqrestore(&adapter->ahw.crb_lock, flags);
return 0;
}
dev_err(&adapter->pdev->dev,
"%s: invalid offset: 0x%016lx\n", __func__, off);
dump_stack();
return -EIO;
}
static u32
netxen_nic_hw_read_wx_2M(struct netxen_adapter *adapter, ulong off)
{
unsigned long flags;
int rv;
u32 data;
void __iomem *addr = NULL;
rv = netxen_nic_pci_get_crb_addr_2M(adapter, off, &addr);
if (rv == 0)
return readl(addr);
if (rv > 0) {
write_lock_irqsave(&adapter->ahw.crb_lock, flags);
crb_win_lock(adapter);
netxen_nic_pci_set_crbwindow_2M(adapter, off);
data = readl(addr);
crb_win_unlock(adapter);
write_unlock_irqrestore(&adapter->ahw.crb_lock, flags);
return data;
}
dev_err(&adapter->pdev->dev,
"%s: invalid offset: 0x%016lx\n", __func__, off);
dump_stack();
return -1;
}
static void netxen_nic_io_write_128M(struct netxen_adapter *adapter,
void __iomem *addr, u32 data)
{
read_lock(&adapter->ahw.crb_lock);
writel(data, addr);
read_unlock(&adapter->ahw.crb_lock);
}
static u32 netxen_nic_io_read_128M(struct netxen_adapter *adapter,
void __iomem *addr)
{
u32 val;
read_lock(&adapter->ahw.crb_lock);
val = readl(addr);
read_unlock(&adapter->ahw.crb_lock);
return val;
}
static void netxen_nic_io_write_2M(struct netxen_adapter *adapter,
void __iomem *addr, u32 data)
{
writel(data, addr);
}
static u32 netxen_nic_io_read_2M(struct netxen_adapter *adapter,
void __iomem *addr)
{
return readl(addr);
}
void __iomem *
netxen_get_ioaddr(struct netxen_adapter *adapter, u32 offset)
{
void __iomem *addr = NULL;
if (NX_IS_REVISION_P2(adapter->ahw.revision_id)) {
if ((offset < NETXEN_CRB_PCIX_HOST2) &&
(offset > NETXEN_CRB_PCIX_HOST))
addr = PCI_OFFSET_SECOND_RANGE(adapter, offset);
else
addr = NETXEN_CRB_NORMALIZE(adapter, offset);
} else {
WARN_ON(netxen_nic_pci_get_crb_addr_2M(adapter,
offset, &addr));
}
return addr;
}
static int
netxen_nic_pci_set_window_128M(struct netxen_adapter *adapter,
u64 addr, u32 *start)
{
if (ADDR_IN_RANGE(addr, NETXEN_ADDR_OCM0, NETXEN_ADDR_OCM0_MAX)) {
*start = (addr - NETXEN_ADDR_OCM0 + NETXEN_PCI_OCM0);
return 0;
} else if (ADDR_IN_RANGE(addr,
NETXEN_ADDR_OCM1, NETXEN_ADDR_OCM1_MAX)) {
*start = (addr - NETXEN_ADDR_OCM1 + NETXEN_PCI_OCM1);
return 0;
}
return -EIO;
}
static int
netxen_nic_pci_set_window_2M(struct netxen_adapter *adapter,
u64 addr, u32 *start)
{
u32 window;
window = OCM_WIN(addr);
writel(window, adapter->ahw.ocm_win_crb);
readl(adapter->ahw.ocm_win_crb);
adapter->ahw.ocm_win = window;
*start = NETXEN_PCI_OCM0_2M + GET_MEM_OFFS_2M(addr);
return 0;
}
static int
netxen_nic_pci_mem_access_direct(struct netxen_adapter *adapter, u64 off,
u64 *data, int op)
{
void __iomem *addr, *mem_ptr = NULL;
resource_size_t mem_base;
int ret;
u32 start;
spin_lock(&adapter->ahw.mem_lock);
ret = adapter->pci_set_window(adapter, off, &start);
if (ret != 0)
goto unlock;
if (NX_IS_REVISION_P3(adapter->ahw.revision_id)) {
addr = adapter->ahw.pci_base0 + start;
} else {
addr = pci_base_offset(adapter, start);
if (addr)
goto noremap;
mem_base = pci_resource_start(adapter->pdev, 0) +
(start & PAGE_MASK);
mem_ptr = ioremap(mem_base, PAGE_SIZE);
if (mem_ptr == NULL) {
ret = -EIO;
goto unlock;
}
addr = mem_ptr + (start & (PAGE_SIZE-1));
}
noremap:
if (op == 0)
*data = readq(addr);
else
writeq(*data, addr);
unlock:
spin_unlock(&adapter->ahw.mem_lock);
if (mem_ptr)
iounmap(mem_ptr);
return ret;
}
void
netxen_pci_camqm_read_2M(struct netxen_adapter *adapter, u64 off, u64 *data)
{
void __iomem *addr = adapter->ahw.pci_base0 +
NETXEN_PCI_CAMQM_2M_BASE + (off - NETXEN_PCI_CAMQM);
spin_lock(&adapter->ahw.mem_lock);
*data = readq(addr);
spin_unlock(&adapter->ahw.mem_lock);
}
void
netxen_pci_camqm_write_2M(struct netxen_adapter *adapter, u64 off, u64 data)
{
void __iomem *addr = adapter->ahw.pci_base0 +
NETXEN_PCI_CAMQM_2M_BASE + (off - NETXEN_PCI_CAMQM);
spin_lock(&adapter->ahw.mem_lock);
writeq(data, addr);
spin_unlock(&adapter->ahw.mem_lock);
}
static int
netxen_nic_pci_mem_write_128M(struct netxen_adapter *adapter,
u64 off, u64 data)
{
int j, ret;
u32 temp, off_lo, off_hi, addr_hi, data_hi, data_lo;
void __iomem *mem_crb;
if (off & 7)
return -EIO;
if (ADDR_IN_RANGE(off, NETXEN_ADDR_QDR_NET,
NETXEN_ADDR_QDR_NET_MAX_P2)) {
mem_crb = pci_base_offset(adapter,
NETXEN_CRB_QDR_NET+SIU_TEST_AGT_BASE);
addr_hi = SIU_TEST_AGT_ADDR_HI;
data_lo = SIU_TEST_AGT_WRDATA_LO;
data_hi = SIU_TEST_AGT_WRDATA_HI;
off_lo = off & SIU_TEST_AGT_ADDR_MASK;
off_hi = SIU_TEST_AGT_UPPER_ADDR(off);
goto correct;
}
if (ADDR_IN_RANGE(off, NETXEN_ADDR_DDR_NET, NETXEN_ADDR_DDR_NET_MAX)) {
mem_crb = pci_base_offset(adapter,
NETXEN_CRB_DDR_NET+MIU_TEST_AGT_BASE);
addr_hi = MIU_TEST_AGT_ADDR_HI;
data_lo = MIU_TEST_AGT_WRDATA_LO;
data_hi = MIU_TEST_AGT_WRDATA_HI;
off_lo = off & MIU_TEST_AGT_ADDR_MASK;
off_hi = 0;
goto correct;
}
if (ADDR_IN_RANGE(off, NETXEN_ADDR_OCM0, NETXEN_ADDR_OCM0_MAX) ||
ADDR_IN_RANGE(off, NETXEN_ADDR_OCM1, NETXEN_ADDR_OCM1_MAX)) {
if (adapter->ahw.pci_len0 != 0) {
return netxen_nic_pci_mem_access_direct(adapter,
off, &data, 1);
}
}
return -EIO;
correct:
spin_lock(&adapter->ahw.mem_lock);
netxen_nic_pci_set_crbwindow_128M(adapter, 0);
writel(off_lo, (mem_crb + MIU_TEST_AGT_ADDR_LO));
writel(off_hi, (mem_crb + addr_hi));
writel(data & 0xffffffff, (mem_crb + data_lo));
writel((data >> 32) & 0xffffffff, (mem_crb + data_hi));
writel((TA_CTL_ENABLE | TA_CTL_WRITE), (mem_crb + TEST_AGT_CTRL));
writel((TA_CTL_START | TA_CTL_ENABLE | TA_CTL_WRITE),
(mem_crb + TEST_AGT_CTRL));
for (j = 0; j < MAX_CTL_CHECK; j++) {
temp = readl((mem_crb + TEST_AGT_CTRL));
if ((temp & TA_CTL_BUSY) == 0)
break;
}
if (j >= MAX_CTL_CHECK) {
if (printk_ratelimit())
dev_err(&adapter->pdev->dev,
"failed to write through agent\n");
ret = -EIO;
} else
ret = 0;
netxen_nic_pci_set_crbwindow_128M(adapter, NETXEN_WINDOW_ONE);
spin_unlock(&adapter->ahw.mem_lock);
return ret;
}
static int
netxen_nic_pci_mem_read_128M(struct netxen_adapter *adapter,
u64 off, u64 *data)
{
int j, ret;
u32 temp, off_lo, off_hi, addr_hi, data_hi, data_lo;
u64 val;
void __iomem *mem_crb;
if (off & 7)
return -EIO;
if (ADDR_IN_RANGE(off, NETXEN_ADDR_QDR_NET,
NETXEN_ADDR_QDR_NET_MAX_P2)) {
mem_crb = pci_base_offset(adapter,
NETXEN_CRB_QDR_NET+SIU_TEST_AGT_BASE);
addr_hi = SIU_TEST_AGT_ADDR_HI;
data_lo = SIU_TEST_AGT_RDDATA_LO;
data_hi = SIU_TEST_AGT_RDDATA_HI;
off_lo = off & SIU_TEST_AGT_ADDR_MASK;
off_hi = SIU_TEST_AGT_UPPER_ADDR(off);
goto correct;
}
if (ADDR_IN_RANGE(off, NETXEN_ADDR_DDR_NET, NETXEN_ADDR_DDR_NET_MAX)) {
mem_crb = pci_base_offset(adapter,
NETXEN_CRB_DDR_NET+MIU_TEST_AGT_BASE);
addr_hi = MIU_TEST_AGT_ADDR_HI;
data_lo = MIU_TEST_AGT_RDDATA_LO;
data_hi = MIU_TEST_AGT_RDDATA_HI;
off_lo = off & MIU_TEST_AGT_ADDR_MASK;
off_hi = 0;
goto correct;
}
if (ADDR_IN_RANGE(off, NETXEN_ADDR_OCM0, NETXEN_ADDR_OCM0_MAX) ||
ADDR_IN_RANGE(off, NETXEN_ADDR_OCM1, NETXEN_ADDR_OCM1_MAX)) {
if (adapter->ahw.pci_len0 != 0) {
return netxen_nic_pci_mem_access_direct(adapter,
off, data, 0);
}
}
return -EIO;
correct:
spin_lock(&adapter->ahw.mem_lock);
netxen_nic_pci_set_crbwindow_128M(adapter, 0);
writel(off_lo, (mem_crb + MIU_TEST_AGT_ADDR_LO));
writel(off_hi, (mem_crb + addr_hi));
writel(TA_CTL_ENABLE, (mem_crb + TEST_AGT_CTRL));
writel((TA_CTL_START|TA_CTL_ENABLE), (mem_crb + TEST_AGT_CTRL));
for (j = 0; j < MAX_CTL_CHECK; j++) {
temp = readl(mem_crb + TEST_AGT_CTRL);
if ((temp & TA_CTL_BUSY) == 0)
break;
}
if (j >= MAX_CTL_CHECK) {
if (printk_ratelimit())
dev_err(&adapter->pdev->dev,
"failed to read through agent\n");
ret = -EIO;
} else {
temp = readl(mem_crb + data_hi);
val = ((u64)temp << 32);
val |= readl(mem_crb + data_lo);
*data = val;
ret = 0;
}
netxen_nic_pci_set_crbwindow_128M(adapter, NETXEN_WINDOW_ONE);
spin_unlock(&adapter->ahw.mem_lock);
return ret;
}
static int
netxen_nic_pci_mem_write_2M(struct netxen_adapter *adapter,
u64 off, u64 data)
{
int j, ret;
u32 temp, off8;
void __iomem *mem_crb;
if (off & 7)
return -EIO;
if (ADDR_IN_RANGE(off, NETXEN_ADDR_QDR_NET,
NETXEN_ADDR_QDR_NET_MAX_P3)) {
mem_crb = netxen_get_ioaddr(adapter,
NETXEN_CRB_QDR_NET+MIU_TEST_AGT_BASE);
goto correct;
}
if (ADDR_IN_RANGE(off, NETXEN_ADDR_DDR_NET, NETXEN_ADDR_DDR_NET_MAX)) {
mem_crb = netxen_get_ioaddr(adapter,
NETXEN_CRB_DDR_NET+MIU_TEST_AGT_BASE);
goto correct;
}
if (ADDR_IN_RANGE(off, NETXEN_ADDR_OCM0, NETXEN_ADDR_OCM0_MAX))
return netxen_nic_pci_mem_access_direct(adapter, off, &data, 1);
return -EIO;
correct:
off8 = off & 0xfffffff8;
spin_lock(&adapter->ahw.mem_lock);
writel(off8, (mem_crb + MIU_TEST_AGT_ADDR_LO));
writel(0, (mem_crb + MIU_TEST_AGT_ADDR_HI));
writel(data & 0xffffffff,
mem_crb + MIU_TEST_AGT_WRDATA_LO);
writel((data >> 32) & 0xffffffff,
mem_crb + MIU_TEST_AGT_WRDATA_HI);
writel((TA_CTL_ENABLE | TA_CTL_WRITE), (mem_crb + TEST_AGT_CTRL));
writel((TA_CTL_START | TA_CTL_ENABLE | TA_CTL_WRITE),
(mem_crb + TEST_AGT_CTRL));
for (j = 0; j < MAX_CTL_CHECK; j++) {
temp = readl(mem_crb + TEST_AGT_CTRL);
if ((temp & TA_CTL_BUSY) == 0)
break;
}
if (j >= MAX_CTL_CHECK) {
if (printk_ratelimit())
dev_err(&adapter->pdev->dev,
"failed to write through agent\n");
ret = -EIO;
} else
ret = 0;
spin_unlock(&adapter->ahw.mem_lock);
return ret;
}
static int
netxen_nic_pci_mem_read_2M(struct netxen_adapter *adapter,
u64 off, u64 *data)
{
int j, ret;
u32 temp, off8;
u64 val;
void __iomem *mem_crb;
if (off & 7)
return -EIO;
if (ADDR_IN_RANGE(off, NETXEN_ADDR_QDR_NET,
NETXEN_ADDR_QDR_NET_MAX_P3)) {
mem_crb = netxen_get_ioaddr(adapter,
NETXEN_CRB_QDR_NET+MIU_TEST_AGT_BASE);
goto correct;
}
if (ADDR_IN_RANGE(off, NETXEN_ADDR_DDR_NET, NETXEN_ADDR_DDR_NET_MAX)) {
mem_crb = netxen_get_ioaddr(adapter,
NETXEN_CRB_DDR_NET+MIU_TEST_AGT_BASE);
goto correct;
}
if (ADDR_IN_RANGE(off, NETXEN_ADDR_OCM0, NETXEN_ADDR_OCM0_MAX)) {
return netxen_nic_pci_mem_access_direct(adapter,
off, data, 0);
}
return -EIO;
correct:
off8 = off & 0xfffffff8;
spin_lock(&adapter->ahw.mem_lock);
writel(off8, (mem_crb + MIU_TEST_AGT_ADDR_LO));
writel(0, (mem_crb + MIU_TEST_AGT_ADDR_HI));
writel(TA_CTL_ENABLE, (mem_crb + TEST_AGT_CTRL));
writel((TA_CTL_START | TA_CTL_ENABLE), (mem_crb + TEST_AGT_CTRL));
for (j = 0; j < MAX_CTL_CHECK; j++) {
temp = readl(mem_crb + TEST_AGT_CTRL);
if ((temp & TA_CTL_BUSY) == 0)
break;
}
if (j >= MAX_CTL_CHECK) {
if (printk_ratelimit())
dev_err(&adapter->pdev->dev,
"failed to read through agent\n");
ret = -EIO;
} else {
val = (u64)(readl(mem_crb + MIU_TEST_AGT_RDDATA_HI)) << 32;
val |= readl(mem_crb + MIU_TEST_AGT_RDDATA_LO);
*data = val;
ret = 0;
}
spin_unlock(&adapter->ahw.mem_lock);
return ret;
}
void
netxen_setup_hwops(struct netxen_adapter *adapter)
{
adapter->init_port = netxen_niu_xg_init_port;
adapter->stop_port = netxen_niu_disable_xg_port;
if (NX_IS_REVISION_P2(adapter->ahw.revision_id)) {
adapter->crb_read = netxen_nic_hw_read_wx_128M,
adapter->crb_write = netxen_nic_hw_write_wx_128M,
adapter->pci_set_window = netxen_nic_pci_set_window_128M,
adapter->pci_mem_read = netxen_nic_pci_mem_read_128M,
adapter->pci_mem_write = netxen_nic_pci_mem_write_128M,
adapter->io_read = netxen_nic_io_read_128M,
adapter->io_write = netxen_nic_io_write_128M,
adapter->macaddr_set = netxen_p2_nic_set_mac_addr;
adapter->set_multi = netxen_p2_nic_set_multi;
adapter->set_mtu = netxen_nic_set_mtu_xgb;
adapter->set_promisc = netxen_p2_nic_set_promisc;
} else {
adapter->crb_read = netxen_nic_hw_read_wx_2M,
adapter->crb_write = netxen_nic_hw_write_wx_2M,
adapter->pci_set_window = netxen_nic_pci_set_window_2M,
adapter->pci_mem_read = netxen_nic_pci_mem_read_2M,
adapter->pci_mem_write = netxen_nic_pci_mem_write_2M,
adapter->io_read = netxen_nic_io_read_2M,
adapter->io_write = netxen_nic_io_write_2M,
adapter->set_mtu = nx_fw_cmd_set_mtu;
adapter->set_promisc = netxen_p3_nic_set_promisc;
adapter->macaddr_set = netxen_p3_nic_set_mac_addr;
adapter->set_multi = netxen_p3_nic_set_multi;
adapter->phy_read = nx_fw_cmd_query_phy;
adapter->phy_write = nx_fw_cmd_set_phy;
}
}
int netxen_nic_get_board_info(struct netxen_adapter *adapter)
{
int offset, board_type, magic;
struct pci_dev *pdev = adapter->pdev;
offset = NX_FW_MAGIC_OFFSET;
if (netxen_rom_fast_read(adapter, offset, &magic))
return -EIO;
if (magic != NETXEN_BDINFO_MAGIC) {
dev_err(&pdev->dev, "invalid board config, magic=%08x\n",
magic);
return -EIO;
}
offset = NX_BRDTYPE_OFFSET;
if (netxen_rom_fast_read(adapter, offset, &board_type))
return -EIO;
if (board_type == NETXEN_BRDTYPE_P3_4_GB_MM) {
u32 gpio = NXRD32(adapter, NETXEN_ROMUSB_GLB_PAD_GPIO_I);
if ((gpio & 0x8000) == 0)
board_type = NETXEN_BRDTYPE_P3_10G_TP;
}
adapter->ahw.board_type = board_type;
switch (board_type) {
case NETXEN_BRDTYPE_P2_SB35_4G:
adapter->ahw.port_type = NETXEN_NIC_GBE;
break;
case NETXEN_BRDTYPE_P2_SB31_10G:
case NETXEN_BRDTYPE_P2_SB31_10G_IMEZ:
case NETXEN_BRDTYPE_P2_SB31_10G_HMEZ:
case NETXEN_BRDTYPE_P2_SB31_10G_CX4:
case NETXEN_BRDTYPE_P3_HMEZ:
case NETXEN_BRDTYPE_P3_XG_LOM:
case NETXEN_BRDTYPE_P3_10G_CX4:
case NETXEN_BRDTYPE_P3_10G_CX4_LP:
case NETXEN_BRDTYPE_P3_IMEZ:
case NETXEN_BRDTYPE_P3_10G_SFP_PLUS:
case NETXEN_BRDTYPE_P3_10G_SFP_CT:
case NETXEN_BRDTYPE_P3_10G_SFP_QT:
case NETXEN_BRDTYPE_P3_10G_XFP:
case NETXEN_BRDTYPE_P3_10000_BASE_T:
adapter->ahw.port_type = NETXEN_NIC_XGBE;
break;
case NETXEN_BRDTYPE_P1_BD:
case NETXEN_BRDTYPE_P1_SB:
case NETXEN_BRDTYPE_P1_SMAX:
case NETXEN_BRDTYPE_P1_SOCK:
case NETXEN_BRDTYPE_P3_REF_QG:
case NETXEN_BRDTYPE_P3_4_GB:
case NETXEN_BRDTYPE_P3_4_GB_MM:
adapter->ahw.port_type = NETXEN_NIC_GBE;
break;
case NETXEN_BRDTYPE_P3_10G_TP:
adapter->ahw.port_type = (adapter->portnum < 2) ?
NETXEN_NIC_XGBE : NETXEN_NIC_GBE;
break;
default:
dev_err(&pdev->dev, "unknown board type %x\n", board_type);
adapter->ahw.port_type = NETXEN_NIC_XGBE;
break;
}
return 0;
}
static int netxen_nic_set_mtu_xgb(struct netxen_adapter *adapter, int new_mtu)
{
new_mtu += MTU_FUDGE_FACTOR;
if (adapter->physical_port == 0)
NXWR32(adapter, NETXEN_NIU_XGE_MAX_FRAME_SIZE, new_mtu);
else
NXWR32(adapter, NETXEN_NIU_XG1_MAX_FRAME_SIZE, new_mtu);
return 0;
}
void netxen_nic_set_link_parameters(struct netxen_adapter *adapter)
{
__u32 status;
__u32 autoneg;
__u32 port_mode;
if (!netif_carrier_ok(adapter->netdev)) {
adapter->link_speed = 0;
adapter->link_duplex = -1;
adapter->link_autoneg = AUTONEG_ENABLE;
return;
}
if (adapter->ahw.port_type == NETXEN_NIC_GBE) {
port_mode = NXRD32(adapter, NETXEN_PORT_MODE_ADDR);
if (port_mode == NETXEN_PORT_MODE_802_3_AP) {
adapter->link_speed = SPEED_1000;
adapter->link_duplex = DUPLEX_FULL;
adapter->link_autoneg = AUTONEG_DISABLE;
return;
}
if (adapter->phy_read &&
adapter->phy_read(adapter,
NETXEN_NIU_GB_MII_MGMT_ADDR_PHY_STATUS,
&status) == 0) {
if (netxen_get_phy_link(status)) {
switch (netxen_get_phy_speed(status)) {
case 0:
adapter->link_speed = SPEED_10;
break;
case 1:
adapter->link_speed = SPEED_100;
break;
case 2:
adapter->link_speed = SPEED_1000;
break;
default:
adapter->link_speed = 0;
break;
}
switch (netxen_get_phy_duplex(status)) {
case 0:
adapter->link_duplex = DUPLEX_HALF;
break;
case 1:
adapter->link_duplex = DUPLEX_FULL;
break;
default:
adapter->link_duplex = -1;
break;
}
if (adapter->phy_read &&
adapter->phy_read(adapter,
NETXEN_NIU_GB_MII_MGMT_ADDR_AUTONEG,
&autoneg) != 0)
adapter->link_autoneg = autoneg;
} else
goto link_down;
} else {
link_down:
adapter->link_speed = 0;
adapter->link_duplex = -1;
}
}
}
int
netxen_nic_wol_supported(struct netxen_adapter *adapter)
{
u32 wol_cfg;
if (NX_IS_REVISION_P2(adapter->ahw.revision_id))
return 0;
wol_cfg = NXRD32(adapter, NETXEN_WOL_CONFIG_NV);
if (wol_cfg & (1UL << adapter->portnum)) {
wol_cfg = NXRD32(adapter, NETXEN_WOL_CONFIG);
if (wol_cfg & (1 << adapter->portnum))
return 1;
}
return 0;
}
