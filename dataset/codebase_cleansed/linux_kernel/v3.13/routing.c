static void _batadv_update_route(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
struct batadv_neigh_node *neigh_node)
{
struct batadv_neigh_node *curr_router;
curr_router = batadv_orig_node_get_router(orig_node);
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
batadv_neigh_node_free_ref(curr_router);
if (neigh_node && !atomic_inc_not_zero(&neigh_node->refcount))
neigh_node = NULL;
spin_lock_bh(&orig_node->neigh_list_lock);
rcu_assign_pointer(orig_node->router, neigh_node);
spin_unlock_bh(&orig_node->neigh_list_lock);
if (curr_router)
batadv_neigh_node_free_ref(curr_router);
}
void batadv_update_route(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
struct batadv_neigh_node *neigh_node)
{
struct batadv_neigh_node *router = NULL;
if (!orig_node)
goto out;
router = batadv_orig_node_get_router(orig_node);
if (router != neigh_node)
_batadv_update_route(bat_priv, orig_node, neigh_node);
out:
if (router)
batadv_neigh_node_free_ref(router);
}
void batadv_bonding_candidate_del(struct batadv_orig_node *orig_node,
struct batadv_neigh_node *neigh_node)
{
if (list_empty(&neigh_node->bonding_list))
goto out;
list_del_rcu(&neigh_node->bonding_list);
INIT_LIST_HEAD(&neigh_node->bonding_list);
batadv_neigh_node_free_ref(neigh_node);
atomic_dec(&orig_node->bond_candidates);
out:
return;
}
void batadv_bonding_candidate_add(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
struct batadv_neigh_node *neigh_node)
{
struct batadv_algo_ops *bao = bat_priv->bat_algo_ops;
struct batadv_neigh_node *tmp_neigh_node, *router = NULL;
uint8_t interference_candidate = 0;
spin_lock_bh(&orig_node->neigh_list_lock);
if (!batadv_compare_eth(orig_node->orig,
neigh_node->orig_node->primary_addr))
goto candidate_del;
router = batadv_orig_node_get_router(orig_node);
if (!router)
goto candidate_del;
if (bao->bat_neigh_is_equiv_or_better(neigh_node, router))
goto candidate_del;
hlist_for_each_entry_rcu(tmp_neigh_node,
&orig_node->neigh_list, list) {
if (tmp_neigh_node == neigh_node)
continue;
if (list_empty(&tmp_neigh_node->bonding_list))
continue;
if ((neigh_node->if_incoming == tmp_neigh_node->if_incoming) ||
(batadv_compare_eth(neigh_node->addr,
tmp_neigh_node->addr))) {
interference_candidate = 1;
break;
}
}
if (interference_candidate)
goto candidate_del;
if (!list_empty(&neigh_node->bonding_list))
goto out;
if (!atomic_inc_not_zero(&neigh_node->refcount))
goto out;
list_add_rcu(&neigh_node->bonding_list, &orig_node->bond_list);
atomic_inc(&orig_node->bond_candidates);
goto out;
candidate_del:
batadv_bonding_candidate_del(orig_node, neigh_node);
out:
spin_unlock_bh(&orig_node->neigh_list_lock);
if (router)
batadv_neigh_node_free_ref(router);
}
void
batadv_bonding_save_primary(const struct batadv_orig_node *orig_node,
struct batadv_orig_node *orig_neigh_node,
const struct batadv_ogm_packet *batman_ogm_packet)
{
if (!(batman_ogm_packet->flags & BATADV_PRIMARIES_FIRST_HOP))
return;
memcpy(orig_neigh_node->primary_addr, orig_node->orig, ETH_ALEN);
}
int batadv_window_protected(struct batadv_priv *bat_priv, int32_t seq_num_diff,
unsigned long *last_reset)
{
if (seq_num_diff <= -BATADV_TQ_LOCAL_WINDOW_SIZE ||
seq_num_diff >= BATADV_EXPECTED_SEQNO_RANGE) {
if (!batadv_has_timed_out(*last_reset,
BATADV_RESET_PROTECTION_MS))
return 1;
*last_reset = jiffies;
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
memcpy(icmph->dst, icmph->orig, ETH_ALEN);
memcpy(icmph->orig, primary_if->net_dev->dev_addr, ETH_ALEN);
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
batadv_hardif_free_ref(primary_if);
if (orig_node)
batadv_orig_node_free_ref(orig_node);
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
memcpy(icmp_packet->dst, icmp_packet->orig, ETH_ALEN);
memcpy(icmp_packet->orig, primary_if->net_dev->dev_addr,
ETH_ALEN);
icmp_packet->msg_type = BATADV_TTL_EXCEEDED;
icmp_packet->ttl = BATADV_TTL;
if (batadv_send_skb_to_orig(skb, orig_node, NULL) != NET_XMIT_DROP)
ret = NET_RX_SUCCESS;
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
if (orig_node)
batadv_orig_node_free_ref(orig_node);
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
memcpy(&(icmp_packet_rr->rr[icmp_packet_rr->rr_cur]),
ethhdr->h_dest, ETH_ALEN);
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
batadv_orig_node_free_ref(orig_node);
return ret;
}
static struct batadv_neigh_node *
batadv_find_bond_router(struct batadv_orig_node *primary_orig,
const struct batadv_hard_iface *recv_if)
{
struct batadv_neigh_node *tmp_neigh_node;
struct batadv_neigh_node *router = NULL, *first_candidate = NULL;
rcu_read_lock();
list_for_each_entry_rcu(tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if (!first_candidate)
first_candidate = tmp_neigh_node;
if (tmp_neigh_node->if_incoming == recv_if)
continue;
if (!atomic_inc_not_zero(&tmp_neigh_node->refcount))
continue;
router = tmp_neigh_node;
break;
}
if (!router && first_candidate &&
atomic_inc_not_zero(&first_candidate->refcount))
router = first_candidate;
if (!router)
goto out;
spin_lock_bh(&primary_orig->neigh_list_lock);
list_del_rcu(&primary_orig->bond_list);
list_add_rcu(&primary_orig->bond_list,
&router->bonding_list);
spin_unlock_bh(&primary_orig->neigh_list_lock);
out:
rcu_read_unlock();
return router;
}
static struct batadv_neigh_node *
batadv_find_ifalter_router(struct batadv_priv *bat_priv,
struct batadv_orig_node *primary_orig,
const struct batadv_hard_iface *recv_if)
{
struct batadv_neigh_node *router = NULL, *first_candidate = NULL;
struct batadv_algo_ops *bao = bat_priv->bat_algo_ops;
struct batadv_neigh_node *tmp_neigh_node;
rcu_read_lock();
list_for_each_entry_rcu(tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if (!first_candidate)
first_candidate = tmp_neigh_node;
if (tmp_neigh_node->if_incoming == recv_if)
continue;
if (router && bao->bat_neigh_cmp(tmp_neigh_node, router))
continue;
if (!atomic_inc_not_zero(&tmp_neigh_node->refcount))
continue;
if (router)
batadv_neigh_node_free_ref(router);
router = tmp_neigh_node;
}
if (!router && first_candidate &&
atomic_inc_not_zero(&first_candidate->refcount))
router = first_candidate;
rcu_read_unlock();
return router;
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
const struct batadv_hard_iface *recv_if)
{
struct batadv_orig_node *primary_orig_node;
struct batadv_orig_node *router_orig;
struct batadv_neigh_node *router;
static uint8_t zero_mac[ETH_ALEN] = {0, 0, 0, 0, 0, 0};
int bonding_enabled;
uint8_t *primary_addr;
if (!orig_node)
return NULL;
router = batadv_orig_node_get_router(orig_node);
if (!router)
goto err;
bonding_enabled = atomic_read(&bat_priv->bonding);
rcu_read_lock();
router_orig = router->orig_node;
if (!router_orig)
goto err_unlock;
if ((!recv_if) && (!bonding_enabled))
goto return_router;
primary_addr = router_orig->primary_addr;
if (batadv_compare_eth(primary_addr, zero_mac))
goto return_router;
if (batadv_compare_eth(primary_addr, router_orig->orig)) {
primary_orig_node = router_orig;
} else {
primary_orig_node = batadv_orig_hash_find(bat_priv,
primary_addr);
if (!primary_orig_node)
goto return_router;
batadv_orig_node_free_ref(primary_orig_node);
}
if (atomic_read(&primary_orig_node->bond_candidates) < 2)
goto return_router;
batadv_neigh_node_free_ref(router);
if (bonding_enabled)
router = batadv_find_bond_router(primary_orig_node, recv_if);
else
router = batadv_find_ifalter_router(bat_priv, primary_orig_node,
recv_if);
return_router:
if (router && router->if_incoming->if_status != BATADV_IF_ACTIVE)
goto err_unlock;
rcu_read_unlock();
return router;
err_unlock:
rcu_read_unlock();
err:
if (router)
batadv_neigh_node_free_ref(router);
return NULL;
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
batadv_orig_node_free_ref(orig_node);
return ret;
}
static bool
batadv_reroute_unicast_packet(struct batadv_priv *bat_priv,
struct batadv_unicast_packet *unicast_packet,
uint8_t *dst_addr, unsigned short vid)
{
struct batadv_orig_node *orig_node = NULL;
struct batadv_hard_iface *primary_if = NULL;
bool ret = false;
uint8_t *orig_addr, orig_ttvn;
if (batadv_is_my_client(bat_priv, dst_addr, vid)) {
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
orig_addr = primary_if->net_dev->dev_addr;
orig_ttvn = (uint8_t)atomic_read(&bat_priv->tt.vn);
} else {
orig_node = batadv_transtable_search(bat_priv, NULL, dst_addr,
vid);
if (!orig_node)
goto out;
if (batadv_compare_eth(orig_node->orig, unicast_packet->dest))
goto out;
orig_addr = orig_node->orig;
orig_ttvn = (uint8_t)atomic_read(&orig_node->last_ttvn);
}
memcpy(unicast_packet->dest, orig_addr, ETH_ALEN);
unicast_packet->ttvn = orig_ttvn;
ret = true;
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
if (orig_node)
batadv_orig_node_free_ref(orig_node);
return ret;
}
static int batadv_check_unicast_ttvn(struct batadv_priv *bat_priv,
struct sk_buff *skb, int hdr_len) {
struct batadv_unicast_packet *unicast_packet;
struct batadv_hard_iface *primary_if;
struct batadv_orig_node *orig_node;
uint8_t curr_ttvn, old_ttvn;
struct ethhdr *ethhdr;
unsigned short vid;
int is_old_ttvn;
if (pskb_may_pull(skb, hdr_len + ETH_HLEN) < 0)
return 0;
if (skb_cow(skb, sizeof(*unicast_packet)) < 0)
return 0;
unicast_packet = (struct batadv_unicast_packet *)skb->data;
vid = batadv_get_vid(skb, hdr_len);
ethhdr = (struct ethhdr *)(skb->data + hdr_len);
if (batadv_tt_local_client_is_roaming(bat_priv, ethhdr->h_dest, vid)) {
if (batadv_reroute_unicast_packet(bat_priv, unicast_packet,
ethhdr->h_dest, vid))
net_ratelimited_function(batadv_dbg, BATADV_DBG_TT,
bat_priv,
"Rerouting unicast packet to %pM (dst=%pM): Local Roaming\n",
unicast_packet->dest,
ethhdr->h_dest);
return 1;
}
curr_ttvn = (uint8_t)atomic_read(&bat_priv->tt.vn);
if (!batadv_is_my_mac(bat_priv, unicast_packet->dest)) {
orig_node = batadv_orig_hash_find(bat_priv,
unicast_packet->dest);
if (!orig_node)
return 0;
curr_ttvn = (uint8_t)atomic_read(&orig_node->last_ttvn);
batadv_orig_node_free_ref(orig_node);
}
is_old_ttvn = batadv_seq_before(unicast_packet->ttvn, curr_ttvn);
if (!is_old_ttvn)
return 1;
old_ttvn = unicast_packet->ttvn;
if (batadv_reroute_unicast_packet(bat_priv, unicast_packet,
ethhdr->h_dest, vid)) {
net_ratelimited_function(batadv_dbg, BATADV_DBG_TT, bat_priv,
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
memcpy(unicast_packet->dest, primary_if->net_dev->dev_addr, ETH_ALEN);
batadv_hardif_free_ref(primary_if);
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
uint8_t *orig_addr;
struct batadv_orig_node *orig_node = NULL;
int check, hdr_size = sizeof(*unicast_packet);
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
batadv_dat_inc_counter(bat_priv,
unicast_4addr_packet->subtype);
orig_addr = unicast_4addr_packet->src;
orig_node = batadv_orig_hash_find(bat_priv, orig_addr);
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
batadv_orig_node_free_ref(orig_node);
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
uint16_t tvlv_buff_len;
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
batadv_orig_node_free_ref(orig_node_src);
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
int32_t seq_diff;
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
if (batadv_test_bit(orig_node->bcast_bits, orig_node->last_bcast_seqno,
ntohl(bcast_packet->seqno)))
goto spin_unlock;
seq_diff = ntohl(bcast_packet->seqno) - orig_node->last_bcast_seqno;
if (batadv_window_protected(bat_priv, seq_diff,
&orig_node->bcast_seqno_reset))
goto spin_unlock;
if (batadv_bit_get_packet(bat_priv, orig_node->bcast_bits, seq_diff, 1))
orig_node->last_bcast_seqno = ntohl(bcast_packet->seqno);
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
batadv_orig_node_free_ref(orig_node);
return ret;
}
