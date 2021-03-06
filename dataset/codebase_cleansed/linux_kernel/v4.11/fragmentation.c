static void batadv_frag_clear_chain(struct hlist_head *head, bool dropped)
{
struct batadv_frag_list_entry *entry;
struct hlist_node *node;
hlist_for_each_entry_safe(entry, node, head, list) {
hlist_del(&entry->list);
if (dropped)
kfree_skb(entry->skb);
else
consume_skb(entry->skb);
kfree(entry);
}
}
void batadv_frag_purge_orig(struct batadv_orig_node *orig_node,
bool (*check_cb)(struct batadv_frag_table_entry *))
{
struct batadv_frag_table_entry *chain;
u8 i;
for (i = 0; i < BATADV_FRAG_BUFFER_COUNT; i++) {
chain = &orig_node->fragments[i];
spin_lock_bh(&chain->lock);
if (!check_cb || check_cb(chain)) {
batadv_frag_clear_chain(&chain->fragment_list, true);
chain->size = 0;
}
spin_unlock_bh(&chain->lock);
}
}
static int batadv_frag_size_limit(void)
{
int limit = BATADV_FRAG_MAX_FRAG_SIZE;
limit -= sizeof(struct batadv_frag_packet);
limit *= BATADV_FRAG_MAX_FRAGMENTS;
return limit;
}
static bool batadv_frag_init_chain(struct batadv_frag_table_entry *chain,
u16 seqno)
{
lockdep_assert_held(&chain->lock);
if (chain->seqno == seqno)
return false;
if (!hlist_empty(&chain->fragment_list))
batadv_frag_clear_chain(&chain->fragment_list, true);
chain->size = 0;
chain->seqno = seqno;
return true;
}
static bool batadv_frag_insert_packet(struct batadv_orig_node *orig_node,
struct sk_buff *skb,
struct hlist_head *chain_out)
{
struct batadv_frag_table_entry *chain;
struct batadv_frag_list_entry *frag_entry_new = NULL, *frag_entry_curr;
struct batadv_frag_list_entry *frag_entry_last = NULL;
struct batadv_frag_packet *frag_packet;
u8 bucket;
u16 seqno, hdr_size = sizeof(struct batadv_frag_packet);
bool ret = false;
if (skb_linearize(skb) < 0)
goto err;
frag_packet = (struct batadv_frag_packet *)skb->data;
seqno = ntohs(frag_packet->seqno);
bucket = seqno % BATADV_FRAG_BUFFER_COUNT;
frag_entry_new = kmalloc(sizeof(*frag_entry_new), GFP_ATOMIC);
if (!frag_entry_new)
goto err;
frag_entry_new->skb = skb;
frag_entry_new->no = frag_packet->no;
chain = &orig_node->fragments[bucket];
spin_lock_bh(&chain->lock);
if (batadv_frag_init_chain(chain, seqno)) {
hlist_add_head(&frag_entry_new->list, &chain->fragment_list);
chain->size = skb->len - hdr_size;
chain->timestamp = jiffies;
chain->total_size = ntohs(frag_packet->total_size);
ret = true;
goto out;
}
hlist_for_each_entry(frag_entry_curr, &chain->fragment_list, list) {
if (frag_entry_curr->no == frag_entry_new->no)
goto err_unlock;
if (frag_entry_curr->no < frag_entry_new->no) {
hlist_add_before(&frag_entry_new->list,
&frag_entry_curr->list);
chain->size += skb->len - hdr_size;
chain->timestamp = jiffies;
ret = true;
goto out;
}
frag_entry_last = frag_entry_curr;
}
if (likely(frag_entry_last)) {
hlist_add_behind(&frag_entry_new->list, &frag_entry_last->list);
chain->size += skb->len - hdr_size;
chain->timestamp = jiffies;
ret = true;
}
out:
if (chain->size > batadv_frag_size_limit() ||
chain->total_size != ntohs(frag_packet->total_size) ||
chain->total_size > batadv_frag_size_limit()) {
batadv_frag_clear_chain(&chain->fragment_list, true);
chain->size = 0;
} else if (ntohs(frag_packet->total_size) == chain->size) {
hlist_move_list(&chain->fragment_list, chain_out);
chain->size = 0;
}
err_unlock:
spin_unlock_bh(&chain->lock);
err:
if (!ret) {
kfree(frag_entry_new);
kfree_skb(skb);
}
return ret;
}
static struct sk_buff *
batadv_frag_merge_packets(struct hlist_head *chain)
{
struct batadv_frag_packet *packet;
struct batadv_frag_list_entry *entry;
struct sk_buff *skb_out;
int size, hdr_size = sizeof(struct batadv_frag_packet);
bool dropped = false;
entry = hlist_entry(chain->first, struct batadv_frag_list_entry, list);
hlist_del(&entry->list);
skb_out = entry->skb;
kfree(entry);
packet = (struct batadv_frag_packet *)skb_out->data;
size = ntohs(packet->total_size);
if (pskb_expand_head(skb_out, 0, size - skb_out->len, GFP_ATOMIC) < 0) {
kfree_skb(skb_out);
skb_out = NULL;
dropped = true;
goto free;
}
skb_pull_rcsum(skb_out, hdr_size);
memmove(skb_out->data - ETH_HLEN, skb_mac_header(skb_out), ETH_HLEN);
skb_set_mac_header(skb_out, -ETH_HLEN);
skb_reset_network_header(skb_out);
skb_reset_transport_header(skb_out);
hlist_for_each_entry(entry, chain, list) {
size = entry->skb->len - hdr_size;
memcpy(skb_put(skb_out, size), entry->skb->data + hdr_size,
size);
}
free:
batadv_frag_clear_chain(chain, dropped);
return skb_out;
}
bool batadv_frag_skb_buffer(struct sk_buff **skb,
struct batadv_orig_node *orig_node_src)
{
struct sk_buff *skb_out = NULL;
struct hlist_head head = HLIST_HEAD_INIT;
bool ret = false;
if (!batadv_frag_insert_packet(orig_node_src, *skb, &head))
goto out_err;
if (hlist_empty(&head))
goto out;
skb_out = batadv_frag_merge_packets(&head);
if (!skb_out)
goto out_err;
out:
ret = true;
out_err:
*skb = skb_out;
return ret;
}
bool batadv_frag_skb_fwd(struct sk_buff *skb,
struct batadv_hard_iface *recv_if,
struct batadv_orig_node *orig_node_src)
{
struct batadv_priv *bat_priv = netdev_priv(recv_if->soft_iface);
struct batadv_orig_node *orig_node_dst;
struct batadv_neigh_node *neigh_node = NULL;
struct batadv_frag_packet *packet;
u16 total_size;
bool ret = false;
packet = (struct batadv_frag_packet *)skb->data;
orig_node_dst = batadv_orig_hash_find(bat_priv, packet->dest);
if (!orig_node_dst)
goto out;
neigh_node = batadv_find_router(bat_priv, orig_node_dst, recv_if);
if (!neigh_node)
goto out;
total_size = ntohs(packet->total_size);
if (total_size > neigh_node->if_incoming->net_dev->mtu) {
batadv_inc_counter(bat_priv, BATADV_CNT_FRAG_FWD);
batadv_add_counter(bat_priv, BATADV_CNT_FRAG_FWD_BYTES,
skb->len + ETH_HLEN);
packet->ttl--;
batadv_send_unicast_skb(skb, neigh_node);
ret = true;
}
out:
if (orig_node_dst)
batadv_orig_node_put(orig_node_dst);
if (neigh_node)
batadv_neigh_node_put(neigh_node);
return ret;
}
static struct sk_buff *batadv_frag_create(struct sk_buff *skb,
struct batadv_frag_packet *frag_head,
unsigned int fragment_size)
{
struct sk_buff *skb_fragment;
unsigned int header_size = sizeof(*frag_head);
unsigned int mtu = fragment_size + header_size;
skb_fragment = netdev_alloc_skb(NULL, mtu + ETH_HLEN);
if (!skb_fragment)
goto err;
skb_fragment->priority = skb->priority;
skb_reserve(skb_fragment, header_size + ETH_HLEN);
skb_split(skb, skb_fragment, skb->len - fragment_size);
skb_push(skb_fragment, header_size);
memcpy(skb_fragment->data, frag_head, header_size);
err:
return skb_fragment;
}
int batadv_frag_send_packet(struct sk_buff *skb,
struct batadv_orig_node *orig_node,
struct batadv_neigh_node *neigh_node)
{
struct batadv_priv *bat_priv;
struct batadv_hard_iface *primary_if = NULL;
struct batadv_frag_packet frag_header;
struct sk_buff *skb_fragment;
unsigned int mtu = neigh_node->if_incoming->net_dev->mtu;
unsigned int header_size = sizeof(frag_header);
unsigned int max_fragment_size, num_fragments;
int ret;
mtu = min_t(unsigned int, mtu, BATADV_FRAG_MAX_FRAG_SIZE);
max_fragment_size = mtu - header_size;
if (skb->len == 0 || max_fragment_size == 0)
return -EINVAL;
num_fragments = (skb->len - 1) / max_fragment_size + 1;
max_fragment_size = (skb->len - 1) / num_fragments + 1;
if (num_fragments > BATADV_FRAG_MAX_FRAGMENTS) {
ret = -EAGAIN;
goto free_skb;
}
bat_priv = orig_node->bat_priv;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if) {
ret = -EINVAL;
goto free_skb;
}
frag_header.packet_type = BATADV_UNICAST_FRAG;
frag_header.version = BATADV_COMPAT_VERSION;
frag_header.ttl = BATADV_TTL;
frag_header.seqno = htons(atomic_inc_return(&bat_priv->frag_seqno));
frag_header.reserved = 0;
frag_header.no = 0;
frag_header.total_size = htons(skb->len);
if (skb->priority >= 256 && skb->priority <= 263)
frag_header.priority = skb->priority - 256;
ether_addr_copy(frag_header.orig, primary_if->net_dev->dev_addr);
ether_addr_copy(frag_header.dest, orig_node->orig);
while (skb->len > max_fragment_size) {
if (unlikely(frag_header.no == BATADV_FRAG_MAX_FRAGMENTS - 1)) {
ret = -EINVAL;
goto put_primary_if;
}
skb_fragment = batadv_frag_create(skb, &frag_header,
max_fragment_size);
if (!skb_fragment) {
ret = -ENOMEM;
goto put_primary_if;
}
batadv_inc_counter(bat_priv, BATADV_CNT_FRAG_TX);
batadv_add_counter(bat_priv, BATADV_CNT_FRAG_TX_BYTES,
skb_fragment->len + ETH_HLEN);
ret = batadv_send_unicast_skb(skb_fragment, neigh_node);
if (ret != NET_XMIT_SUCCESS) {
ret = NET_XMIT_DROP;
goto put_primary_if;
}
frag_header.no++;
}
if (batadv_skb_head_push(skb, header_size) < 0 ||
pskb_expand_head(skb, header_size + ETH_HLEN, 0, GFP_ATOMIC) < 0) {
ret = -ENOMEM;
goto put_primary_if;
}
memcpy(skb->data, &frag_header, header_size);
batadv_inc_counter(bat_priv, BATADV_CNT_FRAG_TX);
batadv_add_counter(bat_priv, BATADV_CNT_FRAG_TX_BYTES,
skb->len + ETH_HLEN);
ret = batadv_send_unicast_skb(skb, neigh_node);
skb = NULL;
put_primary_if:
batadv_hardif_put(primary_if);
free_skb:
kfree_skb(skb);
return ret;
}
