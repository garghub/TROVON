static int batadv_mcast_mla_softif_get(struct net_device *dev,
struct hlist_head *mcast_list)
{
struct netdev_hw_addr *mc_list_entry;
struct batadv_hw_addr *new;
int ret = 0;
netif_addr_lock_bh(dev);
netdev_for_each_mc_addr(mc_list_entry, dev) {
new = kmalloc(sizeof(*new), GFP_ATOMIC);
if (!new) {
ret = -ENOMEM;
break;
}
ether_addr_copy(new->addr, mc_list_entry->addr);
hlist_add_head(&new->list, mcast_list);
ret++;
}
netif_addr_unlock_bh(dev);
return ret;
}
static bool batadv_mcast_mla_is_duplicate(u8 *mcast_addr,
struct hlist_head *mcast_list)
{
struct batadv_hw_addr *mcast_entry;
hlist_for_each_entry(mcast_entry, mcast_list, list)
if (batadv_compare_eth(mcast_entry->addr, mcast_addr))
return true;
return false;
}
static void batadv_mcast_mla_list_free(struct batadv_priv *bat_priv,
struct hlist_head *mcast_list)
{
struct batadv_hw_addr *mcast_entry;
struct hlist_node *tmp;
lockdep_assert_held(&bat_priv->tt.commit_lock);
hlist_for_each_entry_safe(mcast_entry, tmp, mcast_list, list) {
hlist_del(&mcast_entry->list);
kfree(mcast_entry);
}
}
static void batadv_mcast_mla_tt_retract(struct batadv_priv *bat_priv,
struct hlist_head *mcast_list)
{
struct batadv_hw_addr *mcast_entry;
struct hlist_node *tmp;
lockdep_assert_held(&bat_priv->tt.commit_lock);
hlist_for_each_entry_safe(mcast_entry, tmp, &bat_priv->mcast.mla_list,
list) {
if (mcast_list &&
batadv_mcast_mla_is_duplicate(mcast_entry->addr,
mcast_list))
continue;
batadv_tt_local_remove(bat_priv, mcast_entry->addr,
BATADV_NO_FLAGS,
"mcast TT outdated", false);
hlist_del(&mcast_entry->list);
kfree(mcast_entry);
}
}
static void batadv_mcast_mla_tt_add(struct batadv_priv *bat_priv,
struct hlist_head *mcast_list)
{
struct batadv_hw_addr *mcast_entry;
struct hlist_node *tmp;
lockdep_assert_held(&bat_priv->tt.commit_lock);
if (!mcast_list)
return;
hlist_for_each_entry_safe(mcast_entry, tmp, mcast_list, list) {
if (batadv_mcast_mla_is_duplicate(mcast_entry->addr,
&bat_priv->mcast.mla_list))
continue;
if (!batadv_tt_local_add(bat_priv->soft_iface,
mcast_entry->addr, BATADV_NO_FLAGS,
BATADV_NULL_IFINDEX, BATADV_NO_MARK))
continue;
hlist_del(&mcast_entry->list);
hlist_add_head(&mcast_entry->list, &bat_priv->mcast.mla_list);
}
}
static bool batadv_mcast_has_bridge(struct batadv_priv *bat_priv)
{
struct net_device *upper = bat_priv->soft_iface;
rcu_read_lock();
do {
upper = netdev_master_upper_dev_get_rcu(upper);
} while (upper && !(upper->priv_flags & IFF_EBRIDGE));
rcu_read_unlock();
return upper;
}
static bool batadv_mcast_mla_tvlv_update(struct batadv_priv *bat_priv)
{
struct batadv_tvlv_mcast_data mcast_data;
mcast_data.flags = BATADV_NO_FLAGS;
memset(mcast_data.reserved, 0, sizeof(mcast_data.reserved));
if (batadv_mcast_has_bridge(bat_priv)) {
if (bat_priv->mcast.enabled) {
batadv_tvlv_container_unregister(bat_priv,
BATADV_TVLV_MCAST, 1);
bat_priv->mcast.enabled = false;
}
return false;
}
if (!bat_priv->mcast.enabled ||
mcast_data.flags != bat_priv->mcast.flags) {
batadv_tvlv_container_register(bat_priv, BATADV_TVLV_MCAST, 1,
&mcast_data, sizeof(mcast_data));
bat_priv->mcast.flags = mcast_data.flags;
bat_priv->mcast.enabled = true;
}
return true;
}
void batadv_mcast_mla_update(struct batadv_priv *bat_priv)
{
struct net_device *soft_iface = bat_priv->soft_iface;
struct hlist_head mcast_list = HLIST_HEAD_INIT;
int ret;
if (!batadv_mcast_mla_tvlv_update(bat_priv))
goto update;
ret = batadv_mcast_mla_softif_get(soft_iface, &mcast_list);
if (ret < 0)
goto out;
update:
batadv_mcast_mla_tt_retract(bat_priv, &mcast_list);
batadv_mcast_mla_tt_add(bat_priv, &mcast_list);
out:
batadv_mcast_mla_list_free(bat_priv, &mcast_list);
}
static int batadv_mcast_forw_mode_check_ipv4(struct batadv_priv *bat_priv,
struct sk_buff *skb,
bool *is_unsnoopable)
{
struct iphdr *iphdr;
if (!pskb_may_pull(skb, sizeof(struct ethhdr) + sizeof(*iphdr)))
return -ENOMEM;
iphdr = ip_hdr(skb);
if (!ipv4_is_local_multicast(iphdr->daddr))
return -EINVAL;
*is_unsnoopable = true;
return 0;
}
static int batadv_mcast_forw_mode_check_ipv6(struct batadv_priv *bat_priv,
struct sk_buff *skb,
bool *is_unsnoopable)
{
struct ipv6hdr *ip6hdr;
if (!pskb_may_pull(skb, sizeof(struct ethhdr) + sizeof(*ip6hdr)))
return -ENOMEM;
ip6hdr = ipv6_hdr(skb);
if (IPV6_ADDR_MC_SCOPE(&ip6hdr->daddr) != IPV6_ADDR_SCOPE_LINKLOCAL)
return -EINVAL;
if (ipv6_addr_is_ll_all_nodes(&ip6hdr->daddr))
*is_unsnoopable = true;
return 0;
}
static int batadv_mcast_forw_mode_check(struct batadv_priv *bat_priv,
struct sk_buff *skb,
bool *is_unsnoopable)
{
struct ethhdr *ethhdr = eth_hdr(skb);
if (!atomic_read(&bat_priv->multicast_mode))
return -EINVAL;
if (atomic_read(&bat_priv->mcast.num_disabled))
return -EINVAL;
switch (ntohs(ethhdr->h_proto)) {
case ETH_P_IP:
return batadv_mcast_forw_mode_check_ipv4(bat_priv, skb,
is_unsnoopable);
case ETH_P_IPV6:
return batadv_mcast_forw_mode_check_ipv6(bat_priv, skb,
is_unsnoopable);
default:
return -EINVAL;
}
}
static int batadv_mcast_forw_want_all_ip_count(struct batadv_priv *bat_priv,
struct ethhdr *ethhdr)
{
switch (ntohs(ethhdr->h_proto)) {
case ETH_P_IP:
return atomic_read(&bat_priv->mcast.num_want_all_ipv4);
case ETH_P_IPV6:
return atomic_read(&bat_priv->mcast.num_want_all_ipv6);
default:
return 0;
}
}
static struct batadv_orig_node *
batadv_mcast_forw_tt_node_get(struct batadv_priv *bat_priv,
struct ethhdr *ethhdr)
{
return batadv_transtable_search(bat_priv, ethhdr->h_source,
ethhdr->h_dest, BATADV_NO_FLAGS);
}
static struct batadv_orig_node *
batadv_mcast_forw_ipv4_node_get(struct batadv_priv *bat_priv)
{
struct batadv_orig_node *tmp_orig_node, *orig_node = NULL;
rcu_read_lock();
hlist_for_each_entry_rcu(tmp_orig_node,
&bat_priv->mcast.want_all_ipv4_list,
mcast_want_all_ipv4_node) {
if (!atomic_inc_not_zero(&tmp_orig_node->refcount))
continue;
orig_node = tmp_orig_node;
break;
}
rcu_read_unlock();
return orig_node;
}
static struct batadv_orig_node *
batadv_mcast_forw_ipv6_node_get(struct batadv_priv *bat_priv)
{
struct batadv_orig_node *tmp_orig_node, *orig_node = NULL;
rcu_read_lock();
hlist_for_each_entry_rcu(tmp_orig_node,
&bat_priv->mcast.want_all_ipv6_list,
mcast_want_all_ipv6_node) {
if (!atomic_inc_not_zero(&tmp_orig_node->refcount))
continue;
orig_node = tmp_orig_node;
break;
}
rcu_read_unlock();
return orig_node;
}
static struct batadv_orig_node *
batadv_mcast_forw_ip_node_get(struct batadv_priv *bat_priv,
struct ethhdr *ethhdr)
{
switch (ntohs(ethhdr->h_proto)) {
case ETH_P_IP:
return batadv_mcast_forw_ipv4_node_get(bat_priv);
case ETH_P_IPV6:
return batadv_mcast_forw_ipv6_node_get(bat_priv);
default:
return NULL;
}
}
static struct batadv_orig_node *
batadv_mcast_forw_unsnoop_node_get(struct batadv_priv *bat_priv)
{
struct batadv_orig_node *tmp_orig_node, *orig_node = NULL;
rcu_read_lock();
hlist_for_each_entry_rcu(tmp_orig_node,
&bat_priv->mcast.want_all_unsnoopables_list,
mcast_want_all_unsnoopables_node) {
if (!atomic_inc_not_zero(&tmp_orig_node->refcount))
continue;
orig_node = tmp_orig_node;
break;
}
rcu_read_unlock();
return orig_node;
}
enum batadv_forw_mode
batadv_mcast_forw_mode(struct batadv_priv *bat_priv, struct sk_buff *skb,
struct batadv_orig_node **orig)
{
int ret, tt_count, ip_count, unsnoop_count, total_count;
bool is_unsnoopable = false;
struct ethhdr *ethhdr;
ret = batadv_mcast_forw_mode_check(bat_priv, skb, &is_unsnoopable);
if (ret == -ENOMEM)
return BATADV_FORW_NONE;
else if (ret < 0)
return BATADV_FORW_ALL;
ethhdr = eth_hdr(skb);
tt_count = batadv_tt_global_hash_count(bat_priv, ethhdr->h_dest,
BATADV_NO_FLAGS);
ip_count = batadv_mcast_forw_want_all_ip_count(bat_priv, ethhdr);
unsnoop_count = !is_unsnoopable ? 0 :
atomic_read(&bat_priv->mcast.num_want_all_unsnoopables);
total_count = tt_count + ip_count + unsnoop_count;
switch (total_count) {
case 1:
if (tt_count)
*orig = batadv_mcast_forw_tt_node_get(bat_priv, ethhdr);
else if (ip_count)
*orig = batadv_mcast_forw_ip_node_get(bat_priv, ethhdr);
else if (unsnoop_count)
*orig = batadv_mcast_forw_unsnoop_node_get(bat_priv);
if (*orig)
return BATADV_FORW_SINGLE;
case 0:
return BATADV_FORW_NONE;
default:
return BATADV_FORW_ALL;
}
}
static void batadv_mcast_want_unsnoop_update(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig,
u8 mcast_flags)
{
struct hlist_node *node = &orig->mcast_want_all_unsnoopables_node;
struct hlist_head *head = &bat_priv->mcast.want_all_unsnoopables_list;
lockdep_assert_held(&orig->mcast_handler_lock);
if (mcast_flags & BATADV_MCAST_WANT_ALL_UNSNOOPABLES &&
!(orig->mcast_flags & BATADV_MCAST_WANT_ALL_UNSNOOPABLES)) {
atomic_inc(&bat_priv->mcast.num_want_all_unsnoopables);
spin_lock_bh(&bat_priv->mcast.want_lists_lock);
WARN_ON(!hlist_unhashed(node));
hlist_add_head_rcu(node, head);
spin_unlock_bh(&bat_priv->mcast.want_lists_lock);
} else if (!(mcast_flags & BATADV_MCAST_WANT_ALL_UNSNOOPABLES) &&
orig->mcast_flags & BATADV_MCAST_WANT_ALL_UNSNOOPABLES) {
atomic_dec(&bat_priv->mcast.num_want_all_unsnoopables);
spin_lock_bh(&bat_priv->mcast.want_lists_lock);
WARN_ON(hlist_unhashed(node));
hlist_del_init_rcu(node);
spin_unlock_bh(&bat_priv->mcast.want_lists_lock);
}
}
static void batadv_mcast_want_ipv4_update(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig,
u8 mcast_flags)
{
struct hlist_node *node = &orig->mcast_want_all_ipv4_node;
struct hlist_head *head = &bat_priv->mcast.want_all_ipv4_list;
lockdep_assert_held(&orig->mcast_handler_lock);
if (mcast_flags & BATADV_MCAST_WANT_ALL_IPV4 &&
!(orig->mcast_flags & BATADV_MCAST_WANT_ALL_IPV4)) {
atomic_inc(&bat_priv->mcast.num_want_all_ipv4);
spin_lock_bh(&bat_priv->mcast.want_lists_lock);
WARN_ON(!hlist_unhashed(node));
hlist_add_head_rcu(node, head);
spin_unlock_bh(&bat_priv->mcast.want_lists_lock);
} else if (!(mcast_flags & BATADV_MCAST_WANT_ALL_IPV4) &&
orig->mcast_flags & BATADV_MCAST_WANT_ALL_IPV4) {
atomic_dec(&bat_priv->mcast.num_want_all_ipv4);
spin_lock_bh(&bat_priv->mcast.want_lists_lock);
WARN_ON(hlist_unhashed(node));
hlist_del_init_rcu(node);
spin_unlock_bh(&bat_priv->mcast.want_lists_lock);
}
}
static void batadv_mcast_want_ipv6_update(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig,
u8 mcast_flags)
{
struct hlist_node *node = &orig->mcast_want_all_ipv6_node;
struct hlist_head *head = &bat_priv->mcast.want_all_ipv6_list;
lockdep_assert_held(&orig->mcast_handler_lock);
if (mcast_flags & BATADV_MCAST_WANT_ALL_IPV6 &&
!(orig->mcast_flags & BATADV_MCAST_WANT_ALL_IPV6)) {
atomic_inc(&bat_priv->mcast.num_want_all_ipv6);
spin_lock_bh(&bat_priv->mcast.want_lists_lock);
WARN_ON(!hlist_unhashed(node));
hlist_add_head_rcu(node, head);
spin_unlock_bh(&bat_priv->mcast.want_lists_lock);
} else if (!(mcast_flags & BATADV_MCAST_WANT_ALL_IPV6) &&
orig->mcast_flags & BATADV_MCAST_WANT_ALL_IPV6) {
atomic_dec(&bat_priv->mcast.num_want_all_ipv6);
spin_lock_bh(&bat_priv->mcast.want_lists_lock);
WARN_ON(hlist_unhashed(node));
hlist_del_init_rcu(node);
spin_unlock_bh(&bat_priv->mcast.want_lists_lock);
}
}
static void batadv_mcast_tvlv_ogm_handler_v1(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig,
u8 flags,
void *tvlv_value,
u16 tvlv_value_len)
{
bool orig_mcast_enabled = !(flags & BATADV_TVLV_HANDLER_OGM_CIFNOTFND);
u8 mcast_flags = BATADV_NO_FLAGS;
bool orig_initialized;
if (orig_mcast_enabled && tvlv_value &&
(tvlv_value_len >= sizeof(mcast_flags)))
mcast_flags = *(u8 *)tvlv_value;
spin_lock_bh(&orig->mcast_handler_lock);
orig_initialized = test_bit(BATADV_ORIG_CAPA_HAS_MCAST,
&orig->capa_initialized);
if (orig_mcast_enabled &&
!test_bit(BATADV_ORIG_CAPA_HAS_MCAST, &orig->capabilities)) {
if (orig_initialized)
atomic_dec(&bat_priv->mcast.num_disabled);
set_bit(BATADV_ORIG_CAPA_HAS_MCAST, &orig->capabilities);
} else if (!orig_mcast_enabled &&
(test_bit(BATADV_ORIG_CAPA_HAS_MCAST, &orig->capabilities) ||
!orig_initialized)) {
atomic_inc(&bat_priv->mcast.num_disabled);
clear_bit(BATADV_ORIG_CAPA_HAS_MCAST, &orig->capabilities);
}
set_bit(BATADV_ORIG_CAPA_HAS_MCAST, &orig->capa_initialized);
batadv_mcast_want_unsnoop_update(bat_priv, orig, mcast_flags);
batadv_mcast_want_ipv4_update(bat_priv, orig, mcast_flags);
batadv_mcast_want_ipv6_update(bat_priv, orig, mcast_flags);
orig->mcast_flags = mcast_flags;
spin_unlock_bh(&orig->mcast_handler_lock);
}
void batadv_mcast_init(struct batadv_priv *bat_priv)
{
batadv_tvlv_handler_register(bat_priv, batadv_mcast_tvlv_ogm_handler_v1,
NULL, BATADV_TVLV_MCAST, 1,
BATADV_TVLV_HANDLER_OGM_CIFNOTFND);
}
void batadv_mcast_free(struct batadv_priv *bat_priv)
{
batadv_tvlv_container_unregister(bat_priv, BATADV_TVLV_MCAST, 1);
batadv_tvlv_handler_unregister(bat_priv, BATADV_TVLV_MCAST, 1);
batadv_mcast_mla_tt_retract(bat_priv, NULL);
}
void batadv_mcast_purge_orig(struct batadv_orig_node *orig)
{
struct batadv_priv *bat_priv = orig->bat_priv;
spin_lock_bh(&orig->mcast_handler_lock);
if (!test_bit(BATADV_ORIG_CAPA_HAS_MCAST, &orig->capabilities) &&
test_bit(BATADV_ORIG_CAPA_HAS_MCAST, &orig->capa_initialized))
atomic_dec(&bat_priv->mcast.num_disabled);
batadv_mcast_want_unsnoop_update(bat_priv, orig, BATADV_NO_FLAGS);
batadv_mcast_want_ipv4_update(bat_priv, orig, BATADV_NO_FLAGS);
batadv_mcast_want_ipv6_update(bat_priv, orig, BATADV_NO_FLAGS);
spin_unlock_bh(&orig->mcast_handler_lock);
}
