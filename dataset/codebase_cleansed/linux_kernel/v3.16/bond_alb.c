static inline struct arp_pkt *arp_pkt(const struct sk_buff *skb)
{
return (struct arp_pkt *)skb_network_header(skb);
}
static inline u8 _simple_hash(const u8 *hash_start, int hash_size)
{
int i;
u8 hash = 0;
for (i = 0; i < hash_size; i++)
hash ^= hash_start[i];
return hash;
}
static inline void _lock_tx_hashtbl_bh(struct bonding *bond)
{
spin_lock_bh(&(BOND_ALB_INFO(bond).tx_hashtbl_lock));
}
static inline void _unlock_tx_hashtbl_bh(struct bonding *bond)
{
spin_unlock_bh(&(BOND_ALB_INFO(bond).tx_hashtbl_lock));
}
static inline void _lock_tx_hashtbl(struct bonding *bond)
{
spin_lock(&(BOND_ALB_INFO(bond).tx_hashtbl_lock));
}
static inline void _unlock_tx_hashtbl(struct bonding *bond)
{
spin_unlock(&(BOND_ALB_INFO(bond).tx_hashtbl_lock));
}
static inline void tlb_init_table_entry(struct tlb_client_info *entry, int save_load)
{
if (save_load) {
entry->load_history = 1 + entry->tx_bytes /
BOND_TLB_REBALANCE_INTERVAL;
entry->tx_bytes = 0;
}
entry->tx_slave = NULL;
entry->next = TLB_NULL_INDEX;
entry->prev = TLB_NULL_INDEX;
}
static inline void tlb_init_slave(struct slave *slave)
{
SLAVE_TLB_INFO(slave).load = 0;
SLAVE_TLB_INFO(slave).head = TLB_NULL_INDEX;
}
static void __tlb_clear_slave(struct bonding *bond, struct slave *slave,
int save_load)
{
struct tlb_client_info *tx_hash_table;
u32 index;
tx_hash_table = BOND_ALB_INFO(bond).tx_hashtbl;
if (tx_hash_table) {
index = SLAVE_TLB_INFO(slave).head;
while (index != TLB_NULL_INDEX) {
u32 next_index = tx_hash_table[index].next;
tlb_init_table_entry(&tx_hash_table[index], save_load);
index = next_index;
}
}
tlb_init_slave(slave);
}
static void tlb_clear_slave(struct bonding *bond, struct slave *slave,
int save_load)
{
_lock_tx_hashtbl_bh(bond);
__tlb_clear_slave(bond, slave, save_load);
_unlock_tx_hashtbl_bh(bond);
}
static int tlb_initialize(struct bonding *bond)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
int size = TLB_HASH_TABLE_SIZE * sizeof(struct tlb_client_info);
struct tlb_client_info *new_hashtbl;
int i;
new_hashtbl = kzalloc(size, GFP_KERNEL);
if (!new_hashtbl)
return -1;
_lock_tx_hashtbl_bh(bond);
bond_info->tx_hashtbl = new_hashtbl;
for (i = 0; i < TLB_HASH_TABLE_SIZE; i++)
tlb_init_table_entry(&bond_info->tx_hashtbl[i], 0);
_unlock_tx_hashtbl_bh(bond);
return 0;
}
static void tlb_deinitialize(struct bonding *bond)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
_lock_tx_hashtbl_bh(bond);
kfree(bond_info->tx_hashtbl);
bond_info->tx_hashtbl = NULL;
_unlock_tx_hashtbl_bh(bond);
}
static long long compute_gap(struct slave *slave)
{
return (s64) (slave->speed << 20) -
(s64) (SLAVE_TLB_INFO(slave).load << 3);
}
static struct slave *tlb_get_least_loaded_slave(struct bonding *bond)
{
struct slave *slave, *least_loaded;
struct list_head *iter;
long long max_gap;
least_loaded = NULL;
max_gap = LLONG_MIN;
bond_for_each_slave_rcu(bond, slave, iter) {
if (bond_slave_can_tx(slave)) {
long long gap = compute_gap(slave);
if (max_gap < gap) {
least_loaded = slave;
max_gap = gap;
}
}
}
return least_loaded;
}
static struct slave *__tlb_choose_channel(struct bonding *bond, u32 hash_index,
u32 skb_len)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct tlb_client_info *hash_table;
struct slave *assigned_slave;
hash_table = bond_info->tx_hashtbl;
assigned_slave = hash_table[hash_index].tx_slave;
if (!assigned_slave) {
assigned_slave = tlb_get_least_loaded_slave(bond);
if (assigned_slave) {
struct tlb_slave_info *slave_info =
&(SLAVE_TLB_INFO(assigned_slave));
u32 next_index = slave_info->head;
hash_table[hash_index].tx_slave = assigned_slave;
hash_table[hash_index].next = next_index;
hash_table[hash_index].prev = TLB_NULL_INDEX;
if (next_index != TLB_NULL_INDEX)
hash_table[next_index].prev = hash_index;
slave_info->head = hash_index;
slave_info->load +=
hash_table[hash_index].load_history;
}
}
if (assigned_slave)
hash_table[hash_index].tx_bytes += skb_len;
return assigned_slave;
}
static struct slave *tlb_choose_channel(struct bonding *bond, u32 hash_index,
u32 skb_len)
{
struct slave *tx_slave;
_lock_tx_hashtbl(bond);
tx_slave = __tlb_choose_channel(bond, hash_index, skb_len);
_unlock_tx_hashtbl(bond);
return tx_slave;
}
static inline void _lock_rx_hashtbl_bh(struct bonding *bond)
{
spin_lock_bh(&(BOND_ALB_INFO(bond).rx_hashtbl_lock));
}
static inline void _unlock_rx_hashtbl_bh(struct bonding *bond)
{
spin_unlock_bh(&(BOND_ALB_INFO(bond).rx_hashtbl_lock));
}
static inline void _lock_rx_hashtbl(struct bonding *bond)
{
spin_lock(&(BOND_ALB_INFO(bond).rx_hashtbl_lock));
}
static inline void _unlock_rx_hashtbl(struct bonding *bond)
{
spin_unlock(&(BOND_ALB_INFO(bond).rx_hashtbl_lock));
}
static void rlb_update_entry_from_arp(struct bonding *bond, struct arp_pkt *arp)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct rlb_client_info *client_info;
u32 hash_index;
_lock_rx_hashtbl_bh(bond);
hash_index = _simple_hash((u8 *)&(arp->ip_src), sizeof(arp->ip_src));
client_info = &(bond_info->rx_hashtbl[hash_index]);
if ((client_info->assigned) &&
(client_info->ip_src == arp->ip_dst) &&
(client_info->ip_dst == arp->ip_src) &&
(!ether_addr_equal_64bits(client_info->mac_dst, arp->mac_src))) {
ether_addr_copy(client_info->mac_dst, arp->mac_src);
client_info->ntt = 1;
bond_info->rx_ntt = 1;
}
_unlock_rx_hashtbl_bh(bond);
}
static int rlb_arp_recv(const struct sk_buff *skb, struct bonding *bond,
struct slave *slave)
{
struct arp_pkt *arp, _arp;
if (skb->protocol != cpu_to_be16(ETH_P_ARP))
goto out;
arp = skb_header_pointer(skb, 0, sizeof(_arp), &_arp);
if (!arp)
goto out;
rlb_purge_src_ip(bond, arp);
if (arp->op_code == htons(ARPOP_REPLY)) {
rlb_update_entry_from_arp(bond, arp);
pr_debug("Server received an ARP Reply from client\n");
}
out:
return RX_HANDLER_ANOTHER;
}
static struct slave *rlb_next_rx_slave(struct bonding *bond)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct slave *before = NULL, *rx_slave = NULL, *slave;
struct list_head *iter;
bool found = false;
bond_for_each_slave(bond, slave, iter) {
if (!bond_slave_can_tx(slave))
continue;
if (!found) {
if (!before || before->speed < slave->speed)
before = slave;
} else {
if (!rx_slave || rx_slave->speed < slave->speed)
rx_slave = slave;
}
if (slave == bond_info->rx_slave)
found = true;
}
if (!rx_slave || (before && rx_slave->speed < before->speed))
rx_slave = before;
if (rx_slave)
bond_info->rx_slave = rx_slave;
return rx_slave;
}
static struct slave *__rlb_next_rx_slave(struct bonding *bond)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct slave *before = NULL, *rx_slave = NULL, *slave;
struct list_head *iter;
bool found = false;
bond_for_each_slave_rcu(bond, slave, iter) {
if (!bond_slave_can_tx(slave))
continue;
if (!found) {
if (!before || before->speed < slave->speed)
before = slave;
} else {
if (!rx_slave || rx_slave->speed < slave->speed)
rx_slave = slave;
}
if (slave == bond_info->rx_slave)
found = true;
}
if (!rx_slave || (before && rx_slave->speed < before->speed))
rx_slave = before;
if (rx_slave)
bond_info->rx_slave = rx_slave;
return rx_slave;
}
static void rlb_teach_disabled_mac_on_primary(struct bonding *bond, u8 addr[])
{
if (!bond->curr_active_slave)
return;
if (!bond->alb_info.primary_is_promisc) {
if (!dev_set_promiscuity(bond->curr_active_slave->dev, 1))
bond->alb_info.primary_is_promisc = 1;
else
bond->alb_info.primary_is_promisc = 0;
}
bond->alb_info.rlb_promisc_timeout_counter = 0;
alb_send_learning_packets(bond->curr_active_slave, addr, true);
}
static void rlb_clear_slave(struct bonding *bond, struct slave *slave)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct rlb_client_info *rx_hash_table;
u32 index, next_index;
_lock_rx_hashtbl_bh(bond);
rx_hash_table = bond_info->rx_hashtbl;
index = bond_info->rx_hashtbl_used_head;
for (; index != RLB_NULL_INDEX; index = next_index) {
next_index = rx_hash_table[index].used_next;
if (rx_hash_table[index].slave == slave) {
struct slave *assigned_slave = rlb_next_rx_slave(bond);
if (assigned_slave) {
rx_hash_table[index].slave = assigned_slave;
if (!ether_addr_equal_64bits(rx_hash_table[index].mac_dst,
mac_bcast)) {
bond_info->rx_hashtbl[index].ntt = 1;
bond_info->rx_ntt = 1;
bond_info->rlb_update_retry_counter =
RLB_UPDATE_RETRY;
}
} else {
rx_hash_table[index].slave = NULL;
}
}
}
_unlock_rx_hashtbl_bh(bond);
write_lock_bh(&bond->curr_slave_lock);
if (slave != bond->curr_active_slave)
rlb_teach_disabled_mac_on_primary(bond, slave->dev->dev_addr);
write_unlock_bh(&bond->curr_slave_lock);
}
static void rlb_update_client(struct rlb_client_info *client_info)
{
int i;
if (!client_info->slave)
return;
for (i = 0; i < RLB_ARP_BURST_SIZE; i++) {
struct sk_buff *skb;
skb = arp_create(ARPOP_REPLY, ETH_P_ARP,
client_info->ip_dst,
client_info->slave->dev,
client_info->ip_src,
client_info->mac_dst,
client_info->slave->dev->dev_addr,
client_info->mac_dst);
if (!skb) {
pr_err("%s: Error: failed to create an ARP packet\n",
client_info->slave->bond->dev->name);
continue;
}
skb->dev = client_info->slave->dev;
if (client_info->vlan_id) {
skb = vlan_put_tag(skb, htons(ETH_P_8021Q), client_info->vlan_id);
if (!skb) {
pr_err("%s: Error: failed to insert VLAN tag\n",
client_info->slave->bond->dev->name);
continue;
}
}
arp_xmit(skb);
}
}
static void rlb_update_rx_clients(struct bonding *bond)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct rlb_client_info *client_info;
u32 hash_index;
_lock_rx_hashtbl_bh(bond);
hash_index = bond_info->rx_hashtbl_used_head;
for (; hash_index != RLB_NULL_INDEX;
hash_index = client_info->used_next) {
client_info = &(bond_info->rx_hashtbl[hash_index]);
if (client_info->ntt) {
rlb_update_client(client_info);
if (bond_info->rlb_update_retry_counter == 0)
client_info->ntt = 0;
}
}
bond_info->rlb_update_delay_counter = RLB_UPDATE_DELAY;
_unlock_rx_hashtbl_bh(bond);
}
static void rlb_req_update_slave_clients(struct bonding *bond, struct slave *slave)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct rlb_client_info *client_info;
int ntt = 0;
u32 hash_index;
_lock_rx_hashtbl_bh(bond);
hash_index = bond_info->rx_hashtbl_used_head;
for (; hash_index != RLB_NULL_INDEX;
hash_index = client_info->used_next) {
client_info = &(bond_info->rx_hashtbl[hash_index]);
if ((client_info->slave == slave) &&
!ether_addr_equal_64bits(client_info->mac_dst, mac_bcast)) {
client_info->ntt = 1;
ntt = 1;
}
}
if (ntt) {
bond_info->rx_ntt = 1;
bond_info->rlb_update_retry_counter = RLB_UPDATE_RETRY;
}
_unlock_rx_hashtbl_bh(bond);
}
static void rlb_req_update_subnet_clients(struct bonding *bond, __be32 src_ip)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct rlb_client_info *client_info;
u32 hash_index;
_lock_rx_hashtbl(bond);
hash_index = bond_info->rx_hashtbl_used_head;
for (; hash_index != RLB_NULL_INDEX;
hash_index = client_info->used_next) {
client_info = &(bond_info->rx_hashtbl[hash_index]);
if (!client_info->slave) {
pr_err("%s: Error: found a client with no channel in the client's hash table\n",
bond->dev->name);
continue;
}
if ((client_info->ip_src == src_ip) &&
!ether_addr_equal_64bits(client_info->slave->dev->dev_addr,
bond->dev->dev_addr) &&
!ether_addr_equal_64bits(client_info->mac_dst, mac_bcast)) {
client_info->ntt = 1;
bond_info->rx_ntt = 1;
}
}
_unlock_rx_hashtbl(bond);
}
static struct slave *rlb_choose_channel(struct sk_buff *skb, struct bonding *bond)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct arp_pkt *arp = arp_pkt(skb);
struct slave *assigned_slave, *curr_active_slave;
struct rlb_client_info *client_info;
u32 hash_index = 0;
_lock_rx_hashtbl(bond);
curr_active_slave = rcu_dereference(bond->curr_active_slave);
hash_index = _simple_hash((u8 *)&arp->ip_dst, sizeof(arp->ip_dst));
client_info = &(bond_info->rx_hashtbl[hash_index]);
if (client_info->assigned) {
if ((client_info->ip_src == arp->ip_src) &&
(client_info->ip_dst == arp->ip_dst)) {
if (!ether_addr_equal_64bits(arp->mac_dst, mac_bcast)) {
ether_addr_copy(client_info->mac_dst, arp->mac_dst);
}
ether_addr_copy(client_info->mac_src, arp->mac_src);
assigned_slave = client_info->slave;
if (assigned_slave) {
_unlock_rx_hashtbl(bond);
return assigned_slave;
}
} else {
if (bond->curr_active_slave &&
client_info->slave != curr_active_slave) {
client_info->slave = curr_active_slave;
rlb_update_client(client_info);
}
}
}
assigned_slave = __rlb_next_rx_slave(bond);
if (assigned_slave) {
if (!(client_info->assigned &&
client_info->ip_src == arp->ip_src)) {
u32 hash_src = _simple_hash((u8 *)&arp->ip_src,
sizeof(arp->ip_src));
rlb_src_unlink(bond, hash_index);
rlb_src_link(bond, hash_src, hash_index);
}
client_info->ip_src = arp->ip_src;
client_info->ip_dst = arp->ip_dst;
ether_addr_copy(client_info->mac_dst, arp->mac_dst);
ether_addr_copy(client_info->mac_src, arp->mac_src);
client_info->slave = assigned_slave;
if (!ether_addr_equal_64bits(client_info->mac_dst, mac_bcast)) {
client_info->ntt = 1;
bond->alb_info.rx_ntt = 1;
} else {
client_info->ntt = 0;
}
if (vlan_get_tag(skb, &client_info->vlan_id))
client_info->vlan_id = 0;
if (!client_info->assigned) {
u32 prev_tbl_head = bond_info->rx_hashtbl_used_head;
bond_info->rx_hashtbl_used_head = hash_index;
client_info->used_next = prev_tbl_head;
if (prev_tbl_head != RLB_NULL_INDEX) {
bond_info->rx_hashtbl[prev_tbl_head].used_prev =
hash_index;
}
client_info->assigned = 1;
}
}
_unlock_rx_hashtbl(bond);
return assigned_slave;
}
static struct slave *rlb_arp_xmit(struct sk_buff *skb, struct bonding *bond)
{
struct arp_pkt *arp = arp_pkt(skb);
struct slave *tx_slave = NULL;
if (!bond_slave_has_mac_rx(bond, arp->mac_src))
return NULL;
if (arp->op_code == htons(ARPOP_REPLY)) {
tx_slave = rlb_choose_channel(skb, bond);
if (tx_slave)
ether_addr_copy(arp->mac_src, tx_slave->dev->dev_addr);
pr_debug("Server sent ARP Reply packet\n");
} else if (arp->op_code == htons(ARPOP_REQUEST)) {
rlb_choose_channel(skb, bond);
bond->alb_info.rlb_update_delay_counter = RLB_UPDATE_DELAY;
rlb_req_update_subnet_clients(bond, arp->ip_src);
pr_debug("Server sent ARP Request packet\n");
}
return tx_slave;
}
static void rlb_rebalance(struct bonding *bond)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct slave *assigned_slave;
struct rlb_client_info *client_info;
int ntt;
u32 hash_index;
_lock_rx_hashtbl_bh(bond);
ntt = 0;
hash_index = bond_info->rx_hashtbl_used_head;
for (; hash_index != RLB_NULL_INDEX;
hash_index = client_info->used_next) {
client_info = &(bond_info->rx_hashtbl[hash_index]);
assigned_slave = __rlb_next_rx_slave(bond);
if (assigned_slave && (client_info->slave != assigned_slave)) {
client_info->slave = assigned_slave;
client_info->ntt = 1;
ntt = 1;
}
}
if (ntt)
bond_info->rx_ntt = 1;
_unlock_rx_hashtbl_bh(bond);
}
static void rlb_init_table_entry_dst(struct rlb_client_info *entry)
{
entry->used_next = RLB_NULL_INDEX;
entry->used_prev = RLB_NULL_INDEX;
entry->assigned = 0;
entry->slave = NULL;
entry->vlan_id = 0;
}
static void rlb_init_table_entry_src(struct rlb_client_info *entry)
{
entry->src_first = RLB_NULL_INDEX;
entry->src_prev = RLB_NULL_INDEX;
entry->src_next = RLB_NULL_INDEX;
}
static void rlb_init_table_entry(struct rlb_client_info *entry)
{
memset(entry, 0, sizeof(struct rlb_client_info));
rlb_init_table_entry_dst(entry);
rlb_init_table_entry_src(entry);
}
static void rlb_delete_table_entry_dst(struct bonding *bond, u32 index)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
u32 next_index = bond_info->rx_hashtbl[index].used_next;
u32 prev_index = bond_info->rx_hashtbl[index].used_prev;
if (index == bond_info->rx_hashtbl_used_head)
bond_info->rx_hashtbl_used_head = next_index;
if (prev_index != RLB_NULL_INDEX)
bond_info->rx_hashtbl[prev_index].used_next = next_index;
if (next_index != RLB_NULL_INDEX)
bond_info->rx_hashtbl[next_index].used_prev = prev_index;
}
static void rlb_src_unlink(struct bonding *bond, u32 index)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
u32 next_index = bond_info->rx_hashtbl[index].src_next;
u32 prev_index = bond_info->rx_hashtbl[index].src_prev;
bond_info->rx_hashtbl[index].src_next = RLB_NULL_INDEX;
bond_info->rx_hashtbl[index].src_prev = RLB_NULL_INDEX;
if (next_index != RLB_NULL_INDEX)
bond_info->rx_hashtbl[next_index].src_prev = prev_index;
if (prev_index == RLB_NULL_INDEX)
return;
if (bond_info->rx_hashtbl[prev_index].src_first == index)
bond_info->rx_hashtbl[prev_index].src_first = next_index;
else
bond_info->rx_hashtbl[prev_index].src_next = next_index;
}
static void rlb_delete_table_entry(struct bonding *bond, u32 index)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct rlb_client_info *entry = &(bond_info->rx_hashtbl[index]);
rlb_delete_table_entry_dst(bond, index);
rlb_init_table_entry_dst(entry);
rlb_src_unlink(bond, index);
}
static void rlb_src_link(struct bonding *bond, u32 ip_src_hash, u32 ip_dst_hash)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
u32 next;
bond_info->rx_hashtbl[ip_dst_hash].src_prev = ip_src_hash;
next = bond_info->rx_hashtbl[ip_src_hash].src_first;
bond_info->rx_hashtbl[ip_dst_hash].src_next = next;
if (next != RLB_NULL_INDEX)
bond_info->rx_hashtbl[next].src_prev = ip_dst_hash;
bond_info->rx_hashtbl[ip_src_hash].src_first = ip_dst_hash;
}
static void rlb_purge_src_ip(struct bonding *bond, struct arp_pkt *arp)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
u32 ip_src_hash = _simple_hash((u8 *)&(arp->ip_src), sizeof(arp->ip_src));
u32 index;
_lock_rx_hashtbl_bh(bond);
index = bond_info->rx_hashtbl[ip_src_hash].src_first;
while (index != RLB_NULL_INDEX) {
struct rlb_client_info *entry = &(bond_info->rx_hashtbl[index]);
u32 next_index = entry->src_next;
if (entry->ip_src == arp->ip_src &&
!ether_addr_equal_64bits(arp->mac_src, entry->mac_src))
rlb_delete_table_entry(bond, index);
index = next_index;
}
_unlock_rx_hashtbl_bh(bond);
}
static int rlb_initialize(struct bonding *bond)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct rlb_client_info *new_hashtbl;
int size = RLB_HASH_TABLE_SIZE * sizeof(struct rlb_client_info);
int i;
new_hashtbl = kmalloc(size, GFP_KERNEL);
if (!new_hashtbl)
return -1;
_lock_rx_hashtbl_bh(bond);
bond_info->rx_hashtbl = new_hashtbl;
bond_info->rx_hashtbl_used_head = RLB_NULL_INDEX;
for (i = 0; i < RLB_HASH_TABLE_SIZE; i++)
rlb_init_table_entry(bond_info->rx_hashtbl + i);
_unlock_rx_hashtbl_bh(bond);
bond->recv_probe = rlb_arp_recv;
return 0;
}
static void rlb_deinitialize(struct bonding *bond)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
_lock_rx_hashtbl_bh(bond);
kfree(bond_info->rx_hashtbl);
bond_info->rx_hashtbl = NULL;
bond_info->rx_hashtbl_used_head = RLB_NULL_INDEX;
_unlock_rx_hashtbl_bh(bond);
}
static void rlb_clear_vlan(struct bonding *bond, unsigned short vlan_id)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
u32 curr_index;
_lock_rx_hashtbl_bh(bond);
curr_index = bond_info->rx_hashtbl_used_head;
while (curr_index != RLB_NULL_INDEX) {
struct rlb_client_info *curr = &(bond_info->rx_hashtbl[curr_index]);
u32 next_index = bond_info->rx_hashtbl[curr_index].used_next;
if (curr->vlan_id == vlan_id)
rlb_delete_table_entry(bond, curr_index);
curr_index = next_index;
}
_unlock_rx_hashtbl_bh(bond);
}
static void alb_send_lp_vid(struct slave *slave, u8 mac_addr[],
__be16 vlan_proto, u16 vid)
{
struct learning_pkt pkt;
struct sk_buff *skb;
int size = sizeof(struct learning_pkt);
char *data;
memset(&pkt, 0, size);
ether_addr_copy(pkt.mac_dst, mac_addr);
ether_addr_copy(pkt.mac_src, mac_addr);
pkt.type = cpu_to_be16(ETH_P_LOOPBACK);
skb = dev_alloc_skb(size);
if (!skb)
return;
data = skb_put(skb, size);
memcpy(data, &pkt, size);
skb_reset_mac_header(skb);
skb->network_header = skb->mac_header + ETH_HLEN;
skb->protocol = pkt.type;
skb->priority = TC_PRIO_CONTROL;
skb->dev = slave->dev;
if (vid) {
skb = vlan_put_tag(skb, vlan_proto, vid);
if (!skb) {
pr_err("%s: Error: failed to insert VLAN tag\n",
slave->bond->dev->name);
return;
}
}
dev_queue_xmit(skb);
}
static void alb_send_learning_packets(struct slave *slave, u8 mac_addr[],
bool strict_match)
{
struct bonding *bond = bond_get_bond_by_slave(slave);
struct net_device *upper;
struct list_head *iter;
struct bond_vlan_tag tags[BOND_MAX_VLAN_ENCAP];
alb_send_lp_vid(slave, mac_addr, 0, 0);
rcu_read_lock();
netdev_for_each_all_upper_dev_rcu(bond->dev, upper, iter) {
if (is_vlan_dev(upper) && vlan_get_encap_level(upper) == 0) {
if (strict_match &&
ether_addr_equal_64bits(mac_addr,
upper->dev_addr)) {
alb_send_lp_vid(slave, mac_addr,
vlan_dev_vlan_proto(upper),
vlan_dev_vlan_id(upper));
} else if (!strict_match) {
alb_send_lp_vid(slave, upper->dev_addr,
vlan_dev_vlan_proto(upper),
vlan_dev_vlan_id(upper));
}
}
if (netif_is_macvlan(upper) && !strict_match) {
memset(tags, 0, sizeof(tags));
bond_verify_device_path(bond->dev, upper, tags);
alb_send_lp_vid(slave, upper->dev_addr,
tags[0].vlan_proto, tags[0].vlan_id);
}
}
rcu_read_unlock();
}
static int alb_set_slave_mac_addr(struct slave *slave, u8 addr[])
{
struct net_device *dev = slave->dev;
struct sockaddr s_addr;
if (BOND_MODE(slave->bond) == BOND_MODE_TLB) {
memcpy(dev->dev_addr, addr, dev->addr_len);
return 0;
}
memcpy(s_addr.sa_data, addr, dev->addr_len);
s_addr.sa_family = dev->type;
if (dev_set_mac_address(dev, &s_addr)) {
pr_err("%s: Error: dev_set_mac_address of dev %s failed!\n"
"ALB mode requires that the base driver support setting the hw address also when the network device's interface is open\n",
slave->bond->dev->name, dev->name);
return -EOPNOTSUPP;
}
return 0;
}
static void alb_swap_mac_addr(struct slave *slave1, struct slave *slave2)
{
u8 tmp_mac_addr[ETH_ALEN];
ether_addr_copy(tmp_mac_addr, slave1->dev->dev_addr);
alb_set_slave_mac_addr(slave1, slave2->dev->dev_addr);
alb_set_slave_mac_addr(slave2, tmp_mac_addr);
}
static void alb_fasten_mac_swap(struct bonding *bond, struct slave *slave1,
struct slave *slave2)
{
int slaves_state_differ = (bond_slave_can_tx(slave1) != bond_slave_can_tx(slave2));
struct slave *disabled_slave = NULL;
ASSERT_RTNL();
if (bond_slave_can_tx(slave1)) {
alb_send_learning_packets(slave1, slave1->dev->dev_addr, false);
if (bond->alb_info.rlb_enabled) {
rlb_req_update_slave_clients(bond, slave1);
}
} else {
disabled_slave = slave1;
}
if (bond_slave_can_tx(slave2)) {
alb_send_learning_packets(slave2, slave2->dev->dev_addr, false);
if (bond->alb_info.rlb_enabled) {
rlb_req_update_slave_clients(bond, slave2);
}
} else {
disabled_slave = slave2;
}
if (bond->alb_info.rlb_enabled && slaves_state_differ) {
rlb_teach_disabled_mac_on_primary(bond,
disabled_slave->dev->dev_addr);
}
}
static void alb_change_hw_addr_on_detach(struct bonding *bond, struct slave *slave)
{
int perm_curr_diff;
int perm_bond_diff;
struct slave *found_slave;
perm_curr_diff = !ether_addr_equal_64bits(slave->perm_hwaddr,
slave->dev->dev_addr);
perm_bond_diff = !ether_addr_equal_64bits(slave->perm_hwaddr,
bond->dev->dev_addr);
if (perm_curr_diff && perm_bond_diff) {
found_slave = bond_slave_has_mac(bond, slave->perm_hwaddr);
if (found_slave) {
alb_swap_mac_addr(slave, found_slave);
alb_fasten_mac_swap(bond, slave, found_slave);
}
}
}
static int alb_handle_addr_collision_on_attach(struct bonding *bond, struct slave *slave)
{
struct slave *has_bond_addr = bond->curr_active_slave;
struct slave *tmp_slave1, *free_mac_slave = NULL;
struct list_head *iter;
if (!bond_has_slaves(bond)) {
return 0;
}
if (!ether_addr_equal_64bits(slave->perm_hwaddr, bond->dev->dev_addr)) {
if (!bond_slave_has_mac(bond, slave->dev->dev_addr))
return 0;
alb_set_slave_mac_addr(slave, bond->dev->dev_addr);
}
bond_for_each_slave(bond, tmp_slave1, iter) {
if (!bond_slave_has_mac(bond, tmp_slave1->perm_hwaddr)) {
free_mac_slave = tmp_slave1;
break;
}
if (!has_bond_addr) {
if (ether_addr_equal_64bits(tmp_slave1->dev->dev_addr,
bond->dev->dev_addr)) {
has_bond_addr = tmp_slave1;
}
}
}
if (free_mac_slave) {
alb_set_slave_mac_addr(slave, free_mac_slave->perm_hwaddr);
pr_warn("%s: Warning: the hw address of slave %s is in use by the bond; giving it the hw address of %s\n",
bond->dev->name, slave->dev->name,
free_mac_slave->dev->name);
} else if (has_bond_addr) {
pr_err("%s: Error: the hw address of slave %s is in use by the bond; couldn't find a slave with a free hw address to give it (this should not have happened)\n",
bond->dev->name, slave->dev->name);
return -EFAULT;
}
return 0;
}
static int alb_set_mac_address(struct bonding *bond, void *addr)
{
struct slave *slave, *rollback_slave;
struct list_head *iter;
struct sockaddr sa;
char tmp_addr[ETH_ALEN];
int res;
if (bond->alb_info.rlb_enabled)
return 0;
bond_for_each_slave(bond, slave, iter) {
ether_addr_copy(tmp_addr, slave->dev->dev_addr);
res = dev_set_mac_address(slave->dev, addr);
ether_addr_copy(slave->dev->dev_addr, tmp_addr);
if (res)
goto unwind;
}
return 0;
unwind:
memcpy(sa.sa_data, bond->dev->dev_addr, bond->dev->addr_len);
sa.sa_family = bond->dev->type;
bond_for_each_slave(bond, rollback_slave, iter) {
if (rollback_slave == slave)
break;
ether_addr_copy(tmp_addr, rollback_slave->dev->dev_addr);
dev_set_mac_address(rollback_slave->dev, &sa);
ether_addr_copy(rollback_slave->dev->dev_addr, tmp_addr);
}
return res;
}
int bond_alb_initialize(struct bonding *bond, int rlb_enabled)
{
int res;
res = tlb_initialize(bond);
if (res)
return res;
if (rlb_enabled) {
bond->alb_info.rlb_enabled = 1;
res = rlb_initialize(bond);
if (res) {
tlb_deinitialize(bond);
return res;
}
} else {
bond->alb_info.rlb_enabled = 0;
}
return 0;
}
void bond_alb_deinitialize(struct bonding *bond)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
tlb_deinitialize(bond);
if (bond_info->rlb_enabled)
rlb_deinitialize(bond);
}
static int bond_do_alb_xmit(struct sk_buff *skb, struct bonding *bond,
struct slave *tx_slave)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct ethhdr *eth_data = eth_hdr(skb);
if (!tx_slave) {
tx_slave = rcu_dereference(bond->curr_active_slave);
if (bond->params.tlb_dynamic_lb)
bond_info->unbalanced_load += skb->len;
}
if (tx_slave && bond_slave_can_tx(tx_slave)) {
if (tx_slave != rcu_dereference(bond->curr_active_slave)) {
ether_addr_copy(eth_data->h_source,
tx_slave->dev->dev_addr);
}
bond_dev_queue_xmit(bond, skb, tx_slave->dev);
goto out;
}
if (tx_slave && bond->params.tlb_dynamic_lb) {
_lock_tx_hashtbl(bond);
__tlb_clear_slave(bond, tx_slave, 0);
_unlock_tx_hashtbl(bond);
}
dev_kfree_skb_any(skb);
out:
return NETDEV_TX_OK;
}
int bond_tlb_xmit(struct sk_buff *skb, struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
struct ethhdr *eth_data;
struct slave *tx_slave = NULL;
u32 hash_index;
skb_reset_mac_header(skb);
eth_data = eth_hdr(skb);
if (!is_multicast_ether_addr(eth_data->h_dest)) {
switch (skb->protocol) {
case htons(ETH_P_IP):
case htons(ETH_P_IPX):
case htons(ETH_P_IPV6):
hash_index = bond_xmit_hash(bond, skb);
if (bond->params.tlb_dynamic_lb) {
tx_slave = tlb_choose_channel(bond,
hash_index & 0xFF,
skb->len);
} else {
struct list_head *iter;
int idx = hash_index % bond->slave_cnt;
bond_for_each_slave_rcu(bond, tx_slave, iter)
if (--idx < 0)
break;
}
break;
}
}
return bond_do_alb_xmit(skb, bond, tx_slave);
}
int bond_alb_xmit(struct sk_buff *skb, struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
struct ethhdr *eth_data;
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct slave *tx_slave = NULL;
static const __be32 ip_bcast = htonl(0xffffffff);
int hash_size = 0;
bool do_tx_balance = true;
u32 hash_index = 0;
const u8 *hash_start = NULL;
struct ipv6hdr *ip6hdr;
skb_reset_mac_header(skb);
eth_data = eth_hdr(skb);
switch (ntohs(skb->protocol)) {
case ETH_P_IP: {
const struct iphdr *iph = ip_hdr(skb);
if (ether_addr_equal_64bits(eth_data->h_dest, mac_bcast) ||
(iph->daddr == ip_bcast) ||
(iph->protocol == IPPROTO_IGMP)) {
do_tx_balance = false;
break;
}
hash_start = (char *)&(iph->daddr);
hash_size = sizeof(iph->daddr);
}
break;
case ETH_P_IPV6:
if (ether_addr_equal_64bits(eth_data->h_dest, mac_bcast)) {
do_tx_balance = false;
break;
}
if (ether_addr_equal_64bits(eth_data->h_dest, mac_v6_allmcast)) {
do_tx_balance = false;
break;
}
ip6hdr = ipv6_hdr(skb);
if (ipv6_addr_any(&ip6hdr->saddr)) {
do_tx_balance = false;
break;
}
hash_start = (char *)&(ipv6_hdr(skb)->daddr);
hash_size = sizeof(ipv6_hdr(skb)->daddr);
break;
case ETH_P_IPX:
if (ipx_hdr(skb)->ipx_checksum != IPX_NO_CHECKSUM) {
do_tx_balance = false;
break;
}
if (ipx_hdr(skb)->ipx_type != IPX_TYPE_NCP) {
do_tx_balance = false;
break;
}
hash_start = (char *)eth_data->h_dest;
hash_size = ETH_ALEN;
break;
case ETH_P_ARP:
do_tx_balance = false;
if (bond_info->rlb_enabled)
tx_slave = rlb_arp_xmit(skb, bond);
break;
default:
do_tx_balance = false;
break;
}
if (do_tx_balance) {
hash_index = _simple_hash(hash_start, hash_size);
tx_slave = tlb_choose_channel(bond, hash_index, skb->len);
}
return bond_do_alb_xmit(skb, bond, tx_slave);
}
void bond_alb_monitor(struct work_struct *work)
{
struct bonding *bond = container_of(work, struct bonding,
alb_work.work);
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
struct list_head *iter;
struct slave *slave;
if (!bond_has_slaves(bond)) {
bond_info->tx_rebalance_counter = 0;
bond_info->lp_counter = 0;
goto re_arm;
}
rcu_read_lock();
bond_info->tx_rebalance_counter++;
bond_info->lp_counter++;
if (bond_info->lp_counter >= BOND_ALB_LP_TICKS(bond)) {
bool strict_match;
read_lock(&bond->curr_slave_lock);
bond_for_each_slave_rcu(bond, slave, iter) {
strict_match = (slave != bond->curr_active_slave ||
bond_info->rlb_enabled);
alb_send_learning_packets(slave, slave->dev->dev_addr,
strict_match);
}
read_unlock(&bond->curr_slave_lock);
bond_info->lp_counter = 0;
}
if (bond_info->tx_rebalance_counter >= BOND_TLB_REBALANCE_TICKS) {
read_lock(&bond->curr_slave_lock);
bond_for_each_slave_rcu(bond, slave, iter) {
tlb_clear_slave(bond, slave, 1);
if (slave == bond->curr_active_slave) {
SLAVE_TLB_INFO(slave).load =
bond_info->unbalanced_load /
BOND_TLB_REBALANCE_INTERVAL;
bond_info->unbalanced_load = 0;
}
}
read_unlock(&bond->curr_slave_lock);
bond_info->tx_rebalance_counter = 0;
}
if (bond_info->rlb_enabled) {
if (bond_info->primary_is_promisc &&
(++bond_info->rlb_promisc_timeout_counter >= RLB_PROMISC_TIMEOUT)) {
rcu_read_unlock();
if (!rtnl_trylock())
goto re_arm;
bond_info->rlb_promisc_timeout_counter = 0;
dev_set_promiscuity(bond->curr_active_slave->dev, -1);
bond_info->primary_is_promisc = 0;
rtnl_unlock();
rcu_read_lock();
}
if (bond_info->rlb_rebalance) {
bond_info->rlb_rebalance = 0;
rlb_rebalance(bond);
}
if (bond_info->rx_ntt) {
if (bond_info->rlb_update_delay_counter) {
--bond_info->rlb_update_delay_counter;
} else {
rlb_update_rx_clients(bond);
if (bond_info->rlb_update_retry_counter)
--bond_info->rlb_update_retry_counter;
else
bond_info->rx_ntt = 0;
}
}
}
rcu_read_unlock();
re_arm:
queue_delayed_work(bond->wq, &bond->alb_work, alb_delta_in_ticks);
}
int bond_alb_init_slave(struct bonding *bond, struct slave *slave)
{
int res;
res = alb_set_slave_mac_addr(slave, slave->perm_hwaddr);
if (res)
return res;
res = alb_handle_addr_collision_on_attach(bond, slave);
if (res)
return res;
tlb_init_slave(slave);
bond->alb_info.tx_rebalance_counter = BOND_TLB_REBALANCE_TICKS;
if (bond->alb_info.rlb_enabled)
bond->alb_info.rlb_rebalance = 1;
return 0;
}
void bond_alb_deinit_slave(struct bonding *bond, struct slave *slave)
{
if (bond_has_slaves(bond))
alb_change_hw_addr_on_detach(bond, slave);
tlb_clear_slave(bond, slave, 0);
if (bond->alb_info.rlb_enabled) {
bond->alb_info.rx_slave = NULL;
rlb_clear_slave(bond, slave);
}
}
void bond_alb_handle_link_change(struct bonding *bond, struct slave *slave, char link)
{
struct alb_bond_info *bond_info = &(BOND_ALB_INFO(bond));
if (link == BOND_LINK_DOWN) {
tlb_clear_slave(bond, slave, 0);
if (bond->alb_info.rlb_enabled)
rlb_clear_slave(bond, slave);
} else if (link == BOND_LINK_UP) {
bond_info->tx_rebalance_counter = BOND_TLB_REBALANCE_TICKS;
if (bond->alb_info.rlb_enabled) {
bond->alb_info.rlb_rebalance = 1;
}
}
}
void bond_alb_handle_active_change(struct bonding *bond, struct slave *new_slave)
__releases(&bond->curr_slave_lock
int bond_alb_set_mac_address(struct net_device *bond_dev, void *addr)
__acquires(&bond->lock
void bond_alb_clear_vlan(struct bonding *bond, unsigned short vlan_id)
{
if (bond->alb_info.rlb_enabled)
rlb_clear_vlan(bond, vlan_id);
}
