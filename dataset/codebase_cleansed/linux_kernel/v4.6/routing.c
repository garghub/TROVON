static void _batadv_update_route(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
struct batadv_hard_iface *recv_if,
struct batadv_neigh_node *neigh_node)
{
struct batadv_orig_ifinfo *orig_ifinfo;
struct batadv_neigh_node *curr_router;
orig_ifinfo = batadv_orig_ifinfo_get(orig_node, recv_if);
if (!orig_ifinfo)
return;
rcu_read_lock();
curr_router = rcu_dereference(orig_ifinfo->router);
if (curr_router && !kref_get_unless_zero(&curr_router->refcount))
curr_router = NULL;
rcu_read_unlock();
if ((curr_router) && (!neigh_node)) {
batadv_dbg(BATADV_DBG_ROUTES, bat_priv,
"Deleting route towards: %pM\n", orig_node->orig);
batadv_tt_global_del_orig(bat_priv, orig_node, -1,
"Deleted route towards originator");
} else if ((!curr_router) && (neigh_node)) {
batadv_dbg(BATADV_DBG_ROUTES, bat_priv,
"Adding route towards: %pM (via %pM)\n",
orig_node->orig, neigh_node->addr);
} else if (neigh_node && curr_router) {
batadv_dbg(BATADV_DBG_ROUTES, bat_priv,
"Changing route towards: %pM (now via %pM - was via %pM)\n",
orig_node->orig, neigh_node->addr,
curr_router->addr);
}
if (curr_router)
batadv_neigh_node_put(curr_router);
if (neigh_node && !kref_get_unless_zero(&neigh_node->refcount))
neigh_node = NULL;
spin_lock_bh(&orig_node->neigh_list_lock);
curr_router = rcu_dereference_protected(orig_ifinfo->router, true);
rcu_assign_pointer(orig_ifinfo->router, neigh_node);
spin_unlock_bh(&orig_node->neigh_list_lock);
batadv_orig_ifinfo_put(orig_ifinfo);
if (curr_router)
batadv_neigh_node_put(curr_router);
}
void batadv_update_route(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
struct batadv_hard_iface *recv_if,
struct batadv_neigh_node *neigh_node)
{
struct batadv_neigh_node *router = NULL;
if (!orig_node)
goto out;
router = batadv_orig_router_get(orig_node, recv_if);
if (router != neigh_node)
_batadv_update_route(bat_priv, orig_node, recv_if, neigh_node);
out:
if (router)
batadv_neigh_node_put(router);
}
int batadv_window_protected(struct batadv_priv *bat_priv, s32 seq_num_diff,
s32 seq_old_max_diff, unsigned long *last_reset,
bool *protection_started)
{
if (seq_num_diff <= -seq_old_max_diff ||
seq_num_diff >= BATADV_EXPECTED_SEQNO_RANGE) {
if (!batadv_has_timed_out(*last_reset,
BATADV_RESET_PROTECTION_MS))
return 1;
*last_reset = jiffies;
if (protection_started)
*protection_started = true;
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"old packet received, start protection\n");
}
return 0;
}
bool batadv_check_management_packet(struct sk_buff *skb,
struct batadv_hard_iface *hard_iface,
int header_len)
{
struct ethhdr *ethhdr;
if (unlikely(!pskb_may_pull(skb, header_len)))
return false;
ethhdr = eth_hdr(skb);
if (!is_broadcast_ether_addr(ethhdr->h_dest))
return false;
if (is_broadcast_ether_addr(ethhdr->h_source))
return false;
if (skb_cow(skb, 0) < 0)
return false;
if (skb_linearize(skb) < 0)
return false;
return true;
}
static int batadv_recv_my_icmp_packet(struct batadv_priv *bat_priv,
struct sk_buff *skb)
{
struct batadv_hard_iface *primary_if = NULL;
struct batadv_orig_node *orig_node = NULL;
struct batadv_icmp_header *icmph;
int res, ret = NET_RX_DROP;
icmph = (struct batadv_icmp_header *)skb->data;
switch (icmph->msg_type) {
case BATADV_ECHO_REPLY:
case BATADV_DESTINATION_UNREACHABLE:
case BATADV_TTL_EXCEEDED:
if (skb_linearize(skb) < 0)
break;
batadv_socket_receive_packet(icmph, skb->len);
break;
case BATADV_ECHO_REQUEST:
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
orig_node = batadv_orig_hash_find(bat_priv, icmph->orig);
if (!orig_node)
goto out;
if (skb_cow(skb, ETH_HLEN) < 0)
goto out;
icmph = (struct batadv_icmp_header *)skb->data;
ether_addr_copy(icmph->dst, icmph->orig);
ether_addr_copy(icmph->orig, primary_if->net_dev->dev_addr);
icmph->msg_type = BATADV_ECHO_REPLY;
icmph->ttl = BATADV_TTL;
res = batadv_send_skb_to_orig(skb, orig_node, NULL);
if (res != NET_XMIT_DROP)
ret = NET_RX_SUCCESS;
break;
default:
goto out;
}
out:
if (primary_if)
batadv_hardif_put(primary_if);
if (orig_node)
batadv_orig_node_put(orig_node);
return ret;
}
static int batadv_recv_icmp_ttl_exceeded(struct batadv_priv *bat_priv,
struct sk_buff *skb)
{
struct batadv_hard_iface *primary_if = NULL;
struct batadv_orig_node *orig_node = NULL;
struct batadv_icmp_packet *icmp_packet;
int ret = NET_RX_DROP;
icmp_packet = (struct batadv_icmp_packet *)skb->data;
if (icmp_packet->msg_type != BATADV_ECHO_REQUEST) {
pr_debug("Warning - can't forward icmp packet from %pM to %pM: ttl exceeded\n",
icmp_packet->orig, icmp_packet->dst);
goto out;
}
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
orig_node = batadv_orig_hash_find(bat_priv, icmp_packet->orig);
if (!orig_node)
goto out;
if (skb_cow(skb, ETH_HLEN) < 0)
goto out;
icmp_packet = (struct batadv_icmp_packet *)skb->data;
ether_addr_copy(icmp_packet->dst, icmp_packet->orig);
ether_addr_copy(icmp_packet->orig, primary_if->net_dev->dev_addr);
icmp_packet->msg_type = BATADV_TTL_EXCEEDED;
icmp_packet->ttl = BATADV_TTL;
if (batadv_send_skb_to_orig(skb, orig_node, NULL) != NET_XMIT_DROP)
ret = NET_RX_SUCCESS;
out:
if (primary_if)
batadv_hardif_put(primary_if);
if (orig_node)
batadv_orig_node_put(orig_node);
return ret;
}
int batadv_recv_icmp_packet(struct sk_buff *skb,
struct batadv_hard_iface *recv_if)
{
struct batadv_priv *bat_priv = netdev_priv(recv_if->soft_iface);
struct batadv_icmp_header *icmph;
struct batadv_icmp_packet_rr *icmp_packet_rr;
struct ethhdr *ethhdr;
struct batadv_orig_node *orig_node = NULL;
int hdr_size = sizeof(struct batadv_icmp_header);
int ret = NET_RX_DROP;
if (unlikely(!pskb_may_pull(skb, hdr_size)))
goto out;
ethhdr = eth_hdr(skb);
if (is_broadcast_ether_addr(ethhdr->h_dest))
goto out;
if (is_broadcast_ether_addr(ethhdr->h_source))
goto out;
if (!batadv_is_my_mac(bat_priv, ethhdr->h_dest))
goto out;
icmph = (struct batadv_icmp_header *)skb->data;
if ((icmph->msg_type == BATADV_ECHO_REPLY ||
icmph->msg_type == BATADV_ECHO_REQUEST) &&
(skb->len >= sizeof(struct batadv_icmp_packet_rr))) {
if (skb_linearize(skb) < 0)
goto out;
if (skb_cow(skb, ETH_HLEN) < 0)
goto out;
icmph = (struct batadv_icmp_header *)skb->data;
icmp_packet_rr = (struct batadv_icmp_packet_rr *)icmph;
if (icmp_packet_rr->rr_cur >= BATADV_RR_LEN)
goto out;
ether_addr_copy(icmp_packet_rr->rr[icmp_packet_rr->rr_cur],
ethhdr->h_dest);
icmp_packet_rr->rr_cur++;
}
if (batadv_is_my_mac(bat_priv, icmph->dst))
return batadv_recv_my_icmp_packet(bat_priv, skb);
if (icmph->ttl < 2)
return batadv_recv_icmp_ttl_exceeded(bat_priv, skb);
orig_node = batadv_orig_hash_find(bat_priv, icmph->dst);
if (!orig_node)
goto out;
if (skb_cow(skb, ETH_HLEN) < 0)
goto out;
icmph = (struct batadv_icmp_header *)skb->data;
icmph->ttl--;
if (batadv_send_skb_to_orig(skb, orig_node, recv_if) != NET_XMIT_DROP)
ret = NET_RX_SUCCESS;
out:
if (orig_node)
batadv_orig_node_put(orig_node);
return ret;
}
static int batadv_check_unicast_packet(struct batadv_priv *bat_priv,
struct sk_buff *skb, int hdr_size)
{
struct ethhdr *ethhdr;
if (unlikely(!pskb_may_pull(skb, hdr_size)))
return -ENODATA;
ethhdr = eth_hdr(skb);
if (is_broadcast_ether_addr(ethhdr->h_dest))
return -EBADR;
if (is_broadcast_ether_addr(ethhdr->h_source))
return -EBADR;
if (!batadv_is_my_mac(bat_priv, ethhdr->h_dest))
return -EREMOTE;
return 0;
}
struct batadv_neigh_node *
batadv_find_router(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
struct batadv_hard_iface *recv_if)
{
struct batadv_algo_ops *bao = bat_priv->bat_algo_ops;
struct batadv_neigh_node *first_candidate_router = NULL;
struct batadv_neigh_node *next_candidate_router = NULL;
struct batadv_neigh_node *router, *cand_router = NULL;
struct batadv_neigh_node *last_cand_router = NULL;
struct batadv_orig_ifinfo *cand, *first_candidate = NULL;
struct batadv_orig_ifinfo *next_candidate = NULL;
struct batadv_orig_ifinfo *last_candidate;
bool last_candidate_found = false;
if (!orig_node)
return NULL;
router = batadv_orig_router_get(orig_node, recv_if);
if (!router)
return router;
if (!(recv_if == BATADV_IF_DEFAULT && atomic_read(&bat_priv->bonding)))
return router;
rcu_read_lock();
last_candidate = orig_node->last_bonding_candidate;
if (last_candidate)
last_cand_router = rcu_dereference(last_candidate->router);
hlist_for_each_entry_rcu(cand, &orig_node->ifinfo_list, list) {
if (!kref_get_unless_zero(&cand->refcount))
continue;
cand_router = rcu_dereference(cand->router);
if (!cand_router)
goto next;
if (!kref_get_unless_zero(&cand_router->refcount)) {
cand_router = NULL;
goto next;
}
if (!bao->bat_neigh_is_similar_or_better(cand_router,
cand->if_outgoing,
router, recv_if))
goto next;
if (last_cand_router == cand_router)
goto next;
if (!first_candidate) {
kref_get(&cand_router->refcount);
kref_get(&cand->refcount);
first_candidate = cand;
first_candidate_router = cand_router;
}
if (!last_candidate || last_candidate_found) {
next_candidate = cand;
next_candidate_router = cand_router;
break;
}
if (last_candidate == cand)
last_candidate_found = true;
next:
if (cand_router) {
batadv_neigh_node_put(cand_router);
cand_router = NULL;
}
batadv_orig_ifinfo_put(cand);
}
rcu_read_unlock();
if (orig_node->last_bonding_candidate)
batadv_orig_ifinfo_put(orig_node->last_bonding_candidate);
if (next_candidate) {
batadv_neigh_node_put(router);
if (first_candidate) {
batadv_neigh_node_put(first_candidate_router);
batadv_orig_ifinfo_put(first_candidate);
}
router = next_candidate_router;
orig_node->last_bonding_candidate = next_candidate;
} else if (first_candidate) {
batadv_neigh_node_put(router);
router = first_candidate_router;
orig_node->last_bonding_candidate = first_candidate;
} else {
orig_node->last_bonding_candidate = NULL;
}
return router;
}
static int batadv_route_unicast_packet(struct sk_buff *skb,
struct batadv_hard_iface *recv_if)
{
struct batadv_priv *bat_priv = netdev_priv(recv_if->soft_iface);
struct batadv_orig_node *orig_node = NULL;
struct batadv_unicast_packet *unicast_packet;
struct ethhdr *ethhdr = eth_hdr(skb);
int res, hdr_len, ret = NET_RX_DROP;
unicast_packet = (struct batadv_unicast_packet *)skb->data;
if (unicast_packet->ttl < 2) {
pr_debug("Warning - can't forward unicast packet from %pM to %pM: ttl exceeded\n",
ethhdr->h_source, unicast_packet->dest);
goto out;
}
orig_node = batadv_orig_hash_find(bat_priv, unicast_packet->dest);
if (!orig_node)
goto out;
if (skb_cow(skb, ETH_HLEN) < 0)
goto out;
unicast_packet = (struct batadv_unicast_packet *)skb->data;
unicast_packet->ttl--;
switch (unicast_packet->packet_type) {
case BATADV_UNICAST_4ADDR:
hdr_len = sizeof(struct batadv_unicast_4addr_packet);
break;
case BATADV_UNICAST:
hdr_len = sizeof(struct batadv_unicast_packet);
break;
default:
hdr_len = -1;
break;
}
if (hdr_len > 0)
batadv_skb_set_priority(skb, hdr_len);
res = batadv_send_skb_to_orig(skb, orig_node, recv_if);
if (res == NET_XMIT_SUCCESS) {
batadv_inc_counter(bat_priv, BATADV_CNT_FORWARD);
batadv_add_counter(bat_priv, BATADV_CNT_FORWARD_BYTES,
skb->len + ETH_HLEN);
ret = NET_RX_SUCCESS;
} else if (res == NET_XMIT_POLICED) {
ret = NET_RX_SUCCESS;
}
out:
if (orig_node)
batadv_orig_node_put(orig_node);
return ret;
}
static bool
batadv_reroute_unicast_packet(struct batadv_priv *bat_priv,
struct batadv_unicast_packet *unicast_packet,
u8 *dst_addr, unsigned short vid)
{
struct batadv_orig_node *orig_node = NULL;
struct batadv_hard_iface *primary_if = NULL;
bool ret = false;
u8 *orig_addr, orig_ttvn;
if (batadv_is_my_client(bat_priv, dst_addr, vid)) {
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
orig_addr = primary_if->net_dev->dev_addr;
orig_ttvn = (u8)atomic_read(&bat_priv->tt.vn);
} else {
orig_node = batadv_transtable_search(bat_priv, NULL, dst_addr,
vid);
if (!orig_node)
goto out;
if (batadv_compare_eth(orig_node->orig, unicast_packet->dest))
goto out;
orig_addr = orig_node->orig;
orig_ttvn = (u8)atomic_read(&orig_node->last_ttvn);
}
ether_addr_copy(unicast_packet->dest, orig_addr);
unicast_packet->ttvn = orig_ttvn;
ret = true;
out:
if (primary_if)
batadv_hardif_put(primary_if);
if (orig_node)
batadv_orig_node_put(orig_node);
return ret;
}
static int batadv_check_unicast_ttvn(struct batadv_priv *bat_priv,
struct sk_buff *skb, int hdr_len) {
struct batadv_unicast_packet *unicast_packet;
struct batadv_hard_iface *primary_if;
struct batadv_orig_node *orig_node;
u8 curr_ttvn, old_ttvn;
struct ethhdr *ethhdr;
unsigned short vid;
int is_old_ttvn;
if (!pskb_may_pull(skb, hdr_len + ETH_HLEN))
return 0;
if (skb_cow(skb, sizeof(*unicast_packet)) < 0)
return 0;
unicast_packet = (struct batadv_unicast_packet *)skb->data;
vid = batadv_get_vid(skb, hdr_len);
ethhdr = (struct ethhdr *)(skb->data + hdr_len);
if (batadv_tt_local_client_is_roaming(bat_priv, ethhdr->h_dest, vid)) {
if (batadv_reroute_unicast_packet(bat_priv, unicast_packet,
ethhdr->h_dest, vid))
batadv_dbg_ratelimited(BATADV_DBG_TT,
bat_priv,
"Rerouting unicast packet to %pM (dst=%pM): Local Roaming\n",
unicast_packet->dest,
ethhdr->h_dest);
return 1;
}
curr_ttvn = (u8)atomic_read(&bat_priv->tt.vn);
if (!batadv_is_my_mac(bat_priv, unicast_packet->dest)) {
orig_node = batadv_orig_hash_find(bat_priv,
unicast_packet->dest);
if (!orig_node)
return 0;
curr_ttvn = (u8)atomic_read(&orig_node->last_ttvn);
batadv_orig_node_put(orig_node);
}
is_old_ttvn = batadv_seq_before(unicast_packet->ttvn, curr_ttvn);
if (!is_old_ttvn)
return 1;
old_ttvn = unicast_packet->ttvn;
if (batadv_reroute_unicast_packet(bat_priv, unicast_packet,
ethhdr->h_dest, vid)) {
batadv_dbg_ratelimited(BATADV_DBG_TT, bat_priv,
"Rerouting unicast packet to %pM (dst=%pM): TTVN mismatch old_ttvn=%u new_ttvn=%u\n",
unicast_packet->dest, ethhdr->h_dest,
old_ttvn, curr_ttvn);
return 1;
}
if (!batadv_is_my_client(bat_priv, ethhdr->h_dest, vid))
return 0;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
return 0;
ether_addr_copy(unicast_packet->dest, primary_if->net_dev->dev_addr);
batadv_hardif_put(primary_if);
unicast_packet->ttvn = curr_ttvn;
return 1;
}
int batadv_recv_unhandled_unicast_packet(struct sk_buff *skb,
struct batadv_hard_iface *recv_if)
{
struct batadv_unicast_packet *unicast_packet;
struct batadv_priv *bat_priv = netdev_priv(recv_if->soft_iface);
int check, hdr_size = sizeof(*unicast_packet);
check = batadv_check_unicast_packet(bat_priv, skb, hdr_size);
if (check < 0)
return NET_RX_DROP;
unicast_packet = (struct batadv_unicast_packet *)skb->data;
if (batadv_is_my_mac(bat_priv, unicast_packet->dest))
return NET_RX_DROP;
return batadv_route_unicast_packet(skb, recv_if);
}
int batadv_recv_unicast_packet(struct sk_buff *skb,
struct batadv_hard_iface *recv_if)
{
struct batadv_priv *bat_priv = netdev_priv(recv_if->soft_iface);
struct batadv_unicast_packet *unicast_packet;
struct batadv_unicast_4addr_packet *unicast_4addr_packet;
u8 *orig_addr;
struct batadv_orig_node *orig_node = NULL;
int check, hdr_size = sizeof(*unicast_packet);
enum batadv_subtype subtype;
bool is4addr;
unicast_packet = (struct batadv_unicast_packet *)skb->data;
unicast_4addr_packet = (struct batadv_unicast_4addr_packet *)skb->data;
is4addr = unicast_packet->packet_type == BATADV_UNICAST_4ADDR;
if (is4addr)
hdr_size = sizeof(*unicast_4addr_packet);
check = batadv_check_unicast_packet(bat_priv, skb, hdr_size);
if (check == -EREMOTE)
batadv_nc_skb_store_sniffed_unicast(bat_priv, skb);
if (check < 0)
return NET_RX_DROP;
if (!batadv_check_unicast_ttvn(bat_priv, skb, hdr_size))
return NET_RX_DROP;
if (batadv_is_my_mac(bat_priv, unicast_packet->dest)) {
if (is4addr) {
subtype = unicast_4addr_packet->subtype;
batadv_dat_inc_counter(bat_priv, subtype);
if (subtype == BATADV_P_DATA) {
orig_addr = unicast_4addr_packet->src;
orig_node = batadv_orig_hash_find(bat_priv,
orig_addr);
}
}
if (batadv_dat_snoop_incoming_arp_request(bat_priv, skb,
hdr_size))
goto rx_success;
if (batadv_dat_snoop_incoming_arp_reply(bat_priv, skb,
hdr_size))
goto rx_success;
batadv_interface_rx(recv_if->soft_iface, skb, recv_if, hdr_size,
orig_node);
rx_success:
if (orig_node)
batadv_orig_node_put(orig_node);
return NET_RX_SUCCESS;
}
return batadv_route_unicast_packet(skb, recv_if);
}
int batadv_recv_unicast_tvlv(struct sk_buff *skb,
struct batadv_hard_iface *recv_if)
{
struct batadv_priv *bat_priv = netdev_priv(recv_if->soft_iface);
struct batadv_unicast_tvlv_packet *unicast_tvlv_packet;
unsigned char *tvlv_buff;
u16 tvlv_buff_len;
int hdr_size = sizeof(*unicast_tvlv_packet);
int ret = NET_RX_DROP;
if (batadv_check_unicast_packet(bat_priv, skb, hdr_size) < 0)
return NET_RX_DROP;
if (skb_cow(skb, hdr_size) < 0)
return NET_RX_DROP;
if (skb_linearize(skb) < 0)
return NET_RX_DROP;
unicast_tvlv_packet = (struct batadv_unicast_tvlv_packet *)skb->data;
tvlv_buff = (unsigned char *)(skb->data + hdr_size);
tvlv_buff_len = ntohs(unicast_tvlv_packet->tvlv_len);
if (tvlv_buff_len > skb->len - hdr_size)
return NET_RX_DROP;
ret = batadv_tvlv_containers_process(bat_priv, false, NULL,
unicast_tvlv_packet->src,
unicast_tvlv_packet->dst,
tvlv_buff, tvlv_buff_len);
if (ret != NET_RX_SUCCESS)
ret = batadv_route_unicast_packet(skb, recv_if);
else
consume_skb(skb);
return ret;
}
int batadv_recv_frag_packet(struct sk_buff *skb,
struct batadv_hard_iface *recv_if)
{
struct batadv_priv *bat_priv = netdev_priv(recv_if->soft_iface);
struct batadv_orig_node *orig_node_src = NULL;
struct batadv_frag_packet *frag_packet;
int ret = NET_RX_DROP;
if (batadv_check_unicast_packet(bat_priv, skb,
sizeof(*frag_packet)) < 0)
goto out;
frag_packet = (struct batadv_frag_packet *)skb->data;
orig_node_src = batadv_orig_hash_find(bat_priv, frag_packet->orig);
if (!orig_node_src)
goto out;
if (!batadv_is_my_mac(bat_priv, frag_packet->dest) &&
batadv_frag_skb_fwd(skb, recv_if, orig_node_src)) {
ret = NET_RX_SUCCESS;
goto out;
}
batadv_inc_counter(bat_priv, BATADV_CNT_FRAG_RX);
batadv_add_counter(bat_priv, BATADV_CNT_FRAG_RX_BYTES, skb->len);
if (!batadv_frag_skb_buffer(&skb, orig_node_src))
goto out;
if (skb)
batadv_batman_skb_recv(skb, recv_if->net_dev,
&recv_if->batman_adv_ptype, NULL);
ret = NET_RX_SUCCESS;
out:
if (orig_node_src)
batadv_orig_node_put(orig_node_src);
return ret;
}
int batadv_recv_bcast_packet(struct sk_buff *skb,
struct batadv_hard_iface *recv_if)
{
struct batadv_priv *bat_priv = netdev_priv(recv_if->soft_iface);
struct batadv_orig_node *orig_node = NULL;
struct batadv_bcast_packet *bcast_packet;
struct ethhdr *ethhdr;
int hdr_size = sizeof(*bcast_packet);
int ret = NET_RX_DROP;
s32 seq_diff;
u32 seqno;
if (unlikely(!pskb_may_pull(skb, hdr_size)))
goto out;
ethhdr = eth_hdr(skb);
if (!is_broadcast_ether_addr(ethhdr->h_dest))
goto out;
if (is_broadcast_ether_addr(ethhdr->h_source))
goto out;
if (batadv_is_my_mac(bat_priv, ethhdr->h_source))
goto out;
bcast_packet = (struct batadv_bcast_packet *)skb->data;
if (batadv_is_my_mac(bat_priv, bcast_packet->orig))
goto out;
if (bcast_packet->ttl < 2)
goto out;
orig_node = batadv_orig_hash_find(bat_priv, bcast_packet->orig);
if (!orig_node)
goto out;
spin_lock_bh(&orig_node->bcast_seqno_lock);
seqno = ntohl(bcast_packet->seqno);
if (batadv_test_bit(orig_node->bcast_bits, orig_node->last_bcast_seqno,
seqno))
goto spin_unlock;
seq_diff = seqno - orig_node->last_bcast_seqno;
if (batadv_window_protected(bat_priv, seq_diff,
BATADV_BCAST_MAX_AGE,
&orig_node->bcast_seqno_reset, NULL))
goto spin_unlock;
if (batadv_bit_get_packet(bat_priv, orig_node->bcast_bits, seq_diff, 1))
orig_node->last_bcast_seqno = seqno;
spin_unlock_bh(&orig_node->bcast_seqno_lock);
if (batadv_bla_check_bcast_duplist(bat_priv, skb))
goto out;
batadv_skb_set_priority(skb, sizeof(struct batadv_bcast_packet));
batadv_add_bcast_packet_to_list(bat_priv, skb, 1);
if (batadv_bla_is_backbone_gw(skb, orig_node, hdr_size))
goto out;
if (batadv_dat_snoop_incoming_arp_request(bat_priv, skb, hdr_size))
goto rx_success;
if (batadv_dat_snoop_incoming_arp_reply(bat_priv, skb, hdr_size))
goto rx_success;
batadv_interface_rx(recv_if->soft_iface, skb, recv_if, hdr_size,
orig_node);
rx_success:
ret = NET_RX_SUCCESS;
goto out;
spin_unlock:
spin_unlock_bh(&orig_node->bcast_seqno_lock);
out:
if (orig_node)
batadv_orig_node_put(orig_node);
return ret;
}
