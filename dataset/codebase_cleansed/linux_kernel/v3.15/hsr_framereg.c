static struct node_entry *find_node_by_AddrA(struct list_head *node_db,
const unsigned char addr[ETH_ALEN])
{
struct node_entry *node;
list_for_each_entry_rcu(node, node_db, mac_list) {
if (ether_addr_equal(node->MacAddressA, addr))
return node;
}
return NULL;
}
static struct node_entry *find_node_by_AddrB(struct list_head *node_db,
const unsigned char addr[ETH_ALEN])
{
struct node_entry *node;
list_for_each_entry_rcu(node, node_db, mac_list) {
if (ether_addr_equal(node->MacAddressB, addr))
return node;
}
return NULL;
}
struct node_entry *hsr_find_node(struct list_head *node_db, struct sk_buff *skb)
{
struct node_entry *node;
struct ethhdr *ethhdr;
if (!skb_mac_header_was_set(skb))
return NULL;
ethhdr = (struct ethhdr *) skb_mac_header(skb);
list_for_each_entry_rcu(node, node_db, mac_list) {
if (ether_addr_equal(node->MacAddressA, ethhdr->h_source))
return node;
if (ether_addr_equal(node->MacAddressB, ethhdr->h_source))
return node;
}
return NULL;
}
int hsr_create_self_node(struct list_head *self_node_db,
unsigned char addr_a[ETH_ALEN],
unsigned char addr_b[ETH_ALEN])
{
struct node_entry *node, *oldnode;
node = kmalloc(sizeof(*node), GFP_KERNEL);
if (!node)
return -ENOMEM;
ether_addr_copy(node->MacAddressA, addr_a);
ether_addr_copy(node->MacAddressB, addr_b);
rcu_read_lock();
oldnode = list_first_or_null_rcu(self_node_db,
struct node_entry, mac_list);
if (oldnode) {
list_replace_rcu(&oldnode->mac_list, &node->mac_list);
rcu_read_unlock();
synchronize_rcu();
kfree(oldnode);
} else {
rcu_read_unlock();
list_add_tail_rcu(&node->mac_list, self_node_db);
}
return 0;
}
struct node_entry *hsr_merge_node(struct hsr_priv *hsr_priv,
struct node_entry *node,
struct sk_buff *skb,
enum hsr_dev_idx dev_idx)
{
struct hsr_sup_payload *hsr_sp;
struct hsr_ethhdr_sp *hsr_ethsup;
int i;
unsigned long now;
hsr_ethsup = (struct hsr_ethhdr_sp *) skb_mac_header(skb);
hsr_sp = (struct hsr_sup_payload *) skb->data;
if (node && !ether_addr_equal(node->MacAddressA, hsr_sp->MacAddressA)) {
list_del_rcu(&node->mac_list);
kfree_rcu(node, rcu_head);
node = NULL;
}
if (node && (dev_idx == node->AddrB_if) &&
!ether_addr_equal(node->MacAddressB, hsr_ethsup->ethhdr.h_source)) {
list_del_rcu(&node->mac_list);
kfree_rcu(node, rcu_head);
node = NULL;
}
if (node && (dev_idx != node->AddrB_if) &&
(node->AddrB_if != HSR_DEV_NONE) &&
!ether_addr_equal(node->MacAddressA, hsr_ethsup->ethhdr.h_source)) {
list_del_rcu(&node->mac_list);
kfree_rcu(node, rcu_head);
node = NULL;
}
if (node)
return node;
node = find_node_by_AddrA(&hsr_priv->node_db, hsr_sp->MacAddressA);
if (node) {
ether_addr_copy(node->MacAddressB, hsr_ethsup->ethhdr.h_source);
node->AddrB_if = dev_idx;
return node;
}
node = kzalloc(sizeof(*node), GFP_ATOMIC);
if (!node)
return NULL;
ether_addr_copy(node->MacAddressA, hsr_sp->MacAddressA);
ether_addr_copy(node->MacAddressB, hsr_ethsup->ethhdr.h_source);
if (!ether_addr_equal(hsr_sp->MacAddressA, hsr_ethsup->ethhdr.h_source))
node->AddrB_if = dev_idx;
else
node->AddrB_if = HSR_DEV_NONE;
now = jiffies;
for (i = 0; i < HSR_MAX_SLAVE; i++)
node->time_in[i] = now;
for (i = 0; i < HSR_MAX_DEV; i++)
node->seq_out[i] = ntohs(hsr_ethsup->hsr_sup.sequence_nr) - 1;
list_add_tail_rcu(&node->mac_list, &hsr_priv->node_db);
return node;
}
void hsr_addr_subst_source(struct hsr_priv *hsr_priv, struct sk_buff *skb)
{
struct ethhdr *ethhdr;
struct node_entry *node;
if (!skb_mac_header_was_set(skb)) {
WARN_ONCE(1, "%s: Mac header not set\n", __func__);
return;
}
ethhdr = (struct ethhdr *) skb_mac_header(skb);
rcu_read_lock();
node = find_node_by_AddrB(&hsr_priv->node_db, ethhdr->h_source);
if (node)
ether_addr_copy(ethhdr->h_source, node->MacAddressA);
rcu_read_unlock();
}
void hsr_addr_subst_dest(struct hsr_priv *hsr_priv, struct ethhdr *ethhdr,
enum hsr_dev_idx dev_idx)
{
struct node_entry *node;
rcu_read_lock();
node = find_node_by_AddrA(&hsr_priv->node_db, ethhdr->h_dest);
if (node && (node->AddrB_if == dev_idx))
ether_addr_copy(ethhdr->h_dest, node->MacAddressB);
rcu_read_unlock();
}
static bool seq_nr_after(u16 a, u16 b)
{
if ((int) b - a == 32768)
return false;
return (((s16) (b - a)) < 0);
}
void hsr_register_frame_in(struct node_entry *node, enum hsr_dev_idx dev_idx)
{
if ((dev_idx < 0) || (dev_idx >= HSR_MAX_SLAVE)) {
WARN_ONCE(1, "%s: Invalid dev_idx (%d)\n", __func__, dev_idx);
return;
}
node->time_in[dev_idx] = jiffies;
node->time_in_stale[dev_idx] = false;
}
int hsr_register_frame_out(struct node_entry *node, enum hsr_dev_idx dev_idx,
struct sk_buff *skb)
{
struct hsr_ethhdr *hsr_ethhdr;
u16 sequence_nr;
if ((dev_idx < 0) || (dev_idx >= HSR_MAX_DEV)) {
WARN_ONCE(1, "%s: Invalid dev_idx (%d)\n", __func__, dev_idx);
return -EINVAL;
}
if (!skb_mac_header_was_set(skb)) {
WARN_ONCE(1, "%s: Mac header not set\n", __func__);
return -EINVAL;
}
hsr_ethhdr = (struct hsr_ethhdr *) skb_mac_header(skb);
sequence_nr = ntohs(hsr_ethhdr->hsr_tag.sequence_nr);
if (seq_nr_before_or_eq(sequence_nr, node->seq_out[dev_idx]))
return 1;
node->seq_out[dev_idx] = sequence_nr;
return 0;
}
static bool is_late(struct node_entry *node, enum hsr_dev_idx dev_idx)
{
enum hsr_dev_idx other;
if (node->time_in_stale[dev_idx])
return true;
if (dev_idx == HSR_DEV_SLAVE_A)
other = HSR_DEV_SLAVE_B;
else
other = HSR_DEV_SLAVE_A;
if (node->time_in_stale[other])
return false;
if (time_after(node->time_in[other], node->time_in[dev_idx] +
msecs_to_jiffies(MAX_SLAVE_DIFF)))
return true;
return false;
}
void hsr_prune_nodes(struct hsr_priv *hsr_priv)
{
struct node_entry *node;
unsigned long timestamp;
unsigned long time_a, time_b;
rcu_read_lock();
list_for_each_entry_rcu(node, &hsr_priv->node_db, mac_list) {
time_a = node->time_in[HSR_DEV_SLAVE_A];
time_b = node->time_in[HSR_DEV_SLAVE_B];
if (time_after(jiffies, time_a + MAX_JIFFY_OFFSET/2))
node->time_in_stale[HSR_DEV_SLAVE_A] = true;
if (time_after(jiffies, time_b + MAX_JIFFY_OFFSET/2))
node->time_in_stale[HSR_DEV_SLAVE_B] = true;
timestamp = time_a;
if (node->time_in_stale[HSR_DEV_SLAVE_A] ||
(!node->time_in_stale[HSR_DEV_SLAVE_B] &&
time_after(time_b, time_a)))
timestamp = time_b;
if (time_is_after_jiffies(timestamp +
msecs_to_jiffies(1.5*MAX_SLAVE_DIFF))) {
if (is_late(node, HSR_DEV_SLAVE_A))
hsr_nl_ringerror(hsr_priv, node->MacAddressA,
HSR_DEV_SLAVE_A);
else if (is_late(node, HSR_DEV_SLAVE_B))
hsr_nl_ringerror(hsr_priv, node->MacAddressA,
HSR_DEV_SLAVE_B);
}
if (time_is_before_jiffies(timestamp +
msecs_to_jiffies(HSR_NODE_FORGET_TIME))) {
hsr_nl_nodedown(hsr_priv, node->MacAddressA);
list_del_rcu(&node->mac_list);
kfree_rcu(node, rcu_head);
}
}
rcu_read_unlock();
}
void *hsr_get_next_node(struct hsr_priv *hsr_priv, void *_pos,
unsigned char addr[ETH_ALEN])
{
struct node_entry *node;
if (!_pos) {
node = list_first_or_null_rcu(&hsr_priv->node_db,
struct node_entry, mac_list);
if (node)
ether_addr_copy(addr, node->MacAddressA);
return node;
}
node = _pos;
list_for_each_entry_continue_rcu(node, &hsr_priv->node_db, mac_list) {
ether_addr_copy(addr, node->MacAddressA);
return node;
}
return NULL;
}
int hsr_get_node_data(struct hsr_priv *hsr_priv,
const unsigned char *addr,
unsigned char addr_b[ETH_ALEN],
unsigned int *addr_b_ifindex,
int *if1_age,
u16 *if1_seq,
int *if2_age,
u16 *if2_seq)
{
struct node_entry *node;
unsigned long tdiff;
rcu_read_lock();
node = find_node_by_AddrA(&hsr_priv->node_db, addr);
if (!node) {
rcu_read_unlock();
return -ENOENT;
}
ether_addr_copy(addr_b, node->MacAddressB);
tdiff = jiffies - node->time_in[HSR_DEV_SLAVE_A];
if (node->time_in_stale[HSR_DEV_SLAVE_A])
*if1_age = INT_MAX;
#if HZ <= MSEC_PER_SEC
else if (tdiff > msecs_to_jiffies(INT_MAX))
*if1_age = INT_MAX;
#endif
else
*if1_age = jiffies_to_msecs(tdiff);
tdiff = jiffies - node->time_in[HSR_DEV_SLAVE_B];
if (node->time_in_stale[HSR_DEV_SLAVE_B])
*if2_age = INT_MAX;
#if HZ <= MSEC_PER_SEC
else if (tdiff > msecs_to_jiffies(INT_MAX))
*if2_age = INT_MAX;
#endif
else
*if2_age = jiffies_to_msecs(tdiff);
*if1_seq = node->seq_out[HSR_DEV_SLAVE_B];
*if2_seq = node->seq_out[HSR_DEV_SLAVE_A];
if ((node->AddrB_if != HSR_DEV_NONE) && hsr_priv->slave[node->AddrB_if])
*addr_b_ifindex = hsr_priv->slave[node->AddrB_if]->ifindex;
else
*addr_b_ifindex = -1;
rcu_read_unlock();
return 0;
}
