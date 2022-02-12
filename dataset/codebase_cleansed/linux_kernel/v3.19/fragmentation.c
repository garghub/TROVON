static void batadv_frag_clear_chain(struct hlist_head *head)
{
struct batadv_frag_list_entry *entry;
struct hlist_node *node;
hlist_for_each_entry_safe(entry, node, head, list) {
hlist_del(&entry->list);
kfree_skb(entry->skb);
kfree(entry);
}
}
void batadv_frag_purge_orig(struct batadv_orig_node *orig_node,
bool (*check_cb)(struct batadv_frag_table_entry *))
{
struct batadv_frag_table_entry *chain;
uint8_t i;
for (i = 0; i < BATADV_FRAG_BUFFER_COUNT; i++) {
chain = &orig_node->fragments[i];
spin_lock_bh(&orig_node->fragments[i].lock);
if (!check_cb || check_cb(chain)) {
batadv_frag_clear_chain(&orig_node->fragments[i].head);
orig_node->fragments[i].size = 0;
}
spin_unlock_bh(&orig_node->fragments[i].lock);
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
uint16_t seqno)
{
if (chain->seqno == seqno)
return false;
if (!hlist_empty(&chain->head))
batadv_frag_clear_chain(&chain->head);
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
uint8_t bucket;
uint16_t seqno, hdr_size = sizeof(struct batadv_frag_packet);
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
hlist_add_head(&frag_entry_new->list, &chain->head);
chain->size = skb->len - hdr_size;
chain->timestamp = jiffies;
ret = true;
goto out;
}
hlist_for_each_entry(frag_entry_curr, &chain->head, list) {
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
ntohs(frag_packet->total_size) > batadv_frag_size_limit()) {
batadv_frag_clear_chain(&chain->head);
chain->size = 0;
} else if (ntohs(frag_packet->total_size) == chain->size) {
hlist_move_list(&chain->head, chain_out);
chain->size = 0;
}
err_unlock:
spin_unlock_bh(&chain->lock);
err:
if (!ret)
kfree(frag_entry_new);
return ret;
}
static struct sk_buff *
batadv_frag_merge_packets(struct hlist_head *chain, struct sk_buff *skb)
{
struct batadv_frag_packet *packet;
struct batadv_frag_list_entry *entry;
struct sk_buff *skb_out = NULL;
int size, hdr_size = sizeof(struct batadv_frag_packet);
packet = (struct batadv_frag_packet *)skb->data;
size = ntohs(packet->total_size);
if (size > batadv_frag_size_limit())
goto free;
entry = hlist_entry(chain->first, struct batadv_frag_list_entry, list);
hlist_del(&entry->list);
skb_out = entry->skb;
kfree(entry);
if (pskb_expand_head(skb_out, 0, size - skb_out->len, GFP_ATOMIC) < 0) {
kfree_skb(skb_out);
skb_out = NULL;
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
batadv_frag_clear_chain(chain);
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
skb_out = batadv_frag_merge_packets(&head, *skb);
if (!skb_out)
goto out_err;
out:
*skb = skb_out;
ret = true;
out_err:
return ret;
}
bool batadv_frag_skb_fwd(struct sk_buff *skb,
struct batadv_hard_iface *recv_if,
struct batadv_orig_node *orig_node_src)
{
struct batadv_priv *bat_priv = netdev_priv(recv_if->soft_iface);
struct batadv_orig_node *orig_node_dst = NULL;
struct batadv_neigh_node *neigh_node = NULL;
struct batadv_frag_packet *packet;
uint16_t total_size;
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
batadv_send_skb_packet(skb, neigh_node->if_incoming,
neigh_node->addr);
ret = true;
}
out:
if (orig_node_dst)
batadv_orig_node_free_ref(orig_node_dst);
if (neigh_node)
batadv_neigh_node_free_ref(neigh_node);
return ret;
}
static struct sk_buff *batadv_frag_create(struct sk_buff *skb,
struct batadv_frag_packet *frag_head,
unsigned int mtu)
{
struct sk_buff *skb_fragment;
unsigned header_size = sizeof(*frag_head);
unsigned fragment_size = mtu - header_size;
skb_fragment = netdev_alloc_skb(NULL, mtu + ETH_HLEN);
if (!skb_fragment)
goto err;
skb->priority = TC_PRIO_CONTROL;
skb_reserve(skb_fragment, header_size + ETH_HLEN);
skb_split(skb, skb_fragment, skb->len - fragment_size);
skb_push(skb_fragment, header_size);
memcpy(skb_fragment->data, frag_head, header_size);
err:
return skb_fragment;
}
bool batadv_frag_send_packet(struct sk_buff *skb,
struct batadv_orig_node *orig_node,
struct batadv_neigh_node *neigh_node)
{
struct batadv_priv *bat_priv;
struct batadv_hard_iface *primary_if = NULL;
struct batadv_frag_packet frag_header;
struct sk_buff *skb_fragment;
unsigned mtu = neigh_node->if_incoming->net_dev->mtu;
unsigned header_size = sizeof(frag_header);
unsigned max_fragment_size, max_packet_size;
bool ret = false;
mtu = min_t(unsigned, mtu, BATADV_FRAG_MAX_FRAG_SIZE);
max_fragment_size = mtu - header_size;
max_packet_size = max_fragment_size * BATADV_FRAG_MAX_FRAGMENTS;
if (skb->len > max_packet_size)
goto out_err;
bat_priv = orig_node->bat_priv;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out_err;
frag_header.packet_type = BATADV_UNICAST_FRAG;
frag_header.version = BATADV_COMPAT_VERSION;
frag_header.ttl = BATADV_TTL;
frag_header.seqno = htons(atomic_inc_return(&bat_priv->frag_seqno));
frag_header.reserved = 0;
frag_header.no = 0;
frag_header.total_size = htons(skb->len);
ether_addr_copy(frag_header.orig, primary_if->net_dev->dev_addr);
ether_addr_copy(frag_header.dest, orig_node->orig);
while (skb->len > max_fragment_size) {
skb_fragment = batadv_frag_create(skb, &frag_header, mtu);
if (!skb_fragment)
goto out_err;
batadv_inc_counter(bat_priv, BATADV_CNT_FRAG_TX);
batadv_add_counter(bat_priv, BATADV_CNT_FRAG_TX_BYTES,
skb_fragment->len + ETH_HLEN);
batadv_send_skb_packet(skb_fragment, neigh_node->if_incoming,
neigh_node->addr);
frag_header.no++;
if (frag_header.no == BATADV_FRAG_MAX_FRAGMENTS - 1)
goto out_err;
}
if (batadv_skb_head_push(skb, header_size) < 0 ||
pskb_expand_head(skb, header_size + ETH_HLEN, 0, GFP_ATOMIC) < 0)
goto out_err;
memcpy(skb->data, &frag_header, header_size);
batadv_inc_counter(bat_priv, BATADV_CNT_FRAG_TX);
batadv_add_counter(bat_priv, BATADV_CNT_FRAG_TX_BYTES,
skb->len + ETH_HLEN);
batadv_send_skb_packet(skb, neigh_node->if_incoming, neigh_node->addr);
ret = true;
out_err:
if (primary_if)
batadv_hardif_free_ref(primary_if);
return ret;
}
