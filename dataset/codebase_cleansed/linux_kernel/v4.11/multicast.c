static void batadv_mcast_start_timer(struct batadv_priv *bat_priv)
{
queue_delayed_work(batadv_event_workqueue, &bat_priv->mcast.work,
msecs_to_jiffies(BATADV_MCAST_WORK_PERIOD));
}
static struct net_device *batadv_mcast_get_bridge(struct net_device *soft_iface)
{
struct net_device *upper = soft_iface;
rcu_read_lock();
do {
upper = netdev_master_upper_dev_get_rcu(upper);
} while (upper && !(upper->priv_flags & IFF_EBRIDGE));
if (upper)
dev_hold(upper);
rcu_read_unlock();
return upper;
}
static int batadv_mcast_mla_softif_get(struct net_device *dev,
struct hlist_head *mcast_list)
{
struct net_device *bridge = batadv_mcast_get_bridge(dev);
struct netdev_hw_addr *mc_list_entry;
struct batadv_hw_addr *new;
int ret = 0;
netif_addr_lock_bh(bridge ? bridge : dev);
netdev_for_each_mc_addr(mc_list_entry, bridge ? bridge : dev) {
new = kmalloc(sizeof(*new), GFP_ATOMIC);
if (!new) {
ret = -ENOMEM;
break;
}
ether_addr_copy(new->addr, mc_list_entry->addr);
hlist_add_head(&new->list, mcast_list);
ret++;
}
netif_addr_unlock_bh(bridge ? bridge : dev);
if (bridge)
dev_put(bridge);
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
static void batadv_mcast_mla_br_addr_cpy(char *dst, const struct br_ip *src)
{
if (src->proto == htons(ETH_P_IP))
ip_eth_mc_map(src->u.ip4, dst);
#if IS_ENABLED(CONFIG_IPV6)
else if (src->proto == htons(ETH_P_IPV6))
ipv6_eth_mc_map(&src->u.ip6, dst);
#endif
else
eth_zero_addr(dst);
}
static int batadv_mcast_mla_bridge_get(struct net_device *dev,
struct hlist_head *mcast_list)
{
struct list_head bridge_mcast_list = LIST_HEAD_INIT(bridge_mcast_list);
struct br_ip_list *br_ip_entry, *tmp;
struct batadv_hw_addr *new;
u8 mcast_addr[ETH_ALEN];
int ret;
ret = br_multicast_list_adjacent(dev, &bridge_mcast_list);
if (ret < 0)
goto out;
list_for_each_entry(br_ip_entry, &bridge_mcast_list, list) {
batadv_mcast_mla_br_addr_cpy(mcast_addr, &br_ip_entry->addr);
if (batadv_mcast_mla_is_duplicate(mcast_addr, mcast_list))
continue;
new = kmalloc(sizeof(*new), GFP_ATOMIC);
if (!new) {
ret = -ENOMEM;
break;
}
ether_addr_copy(new->addr, mcast_addr);
hlist_add_head(&new->list, mcast_list);
}
out:
list_for_each_entry_safe(br_ip_entry, tmp, &bridge_mcast_list, list) {
list_del(&br_ip_entry->list);
kfree(br_ip_entry);
}
return ret;
}
static void batadv_mcast_mla_list_free(struct hlist_head *mcast_list)
{
struct batadv_hw_addr *mcast_entry;
struct hlist_node *tmp;
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
WARN_ON(delayed_work_pending(&bat_priv->mcast.work));
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
WARN_ON(delayed_work_pending(&bat_priv->mcast.work));
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
static void
batadv_mcast_querier_log(struct batadv_priv *bat_priv, char *str_proto,
struct batadv_mcast_querier_state *old_state,
struct batadv_mcast_querier_state *new_state)
{
if (!old_state->exists && new_state->exists)
batadv_info(bat_priv->soft_iface, "%s Querier appeared\n",
str_proto);
else if (old_state->exists && !new_state->exists)
batadv_info(bat_priv->soft_iface,
"%s Querier disappeared - multicast optimizations disabled\n",
str_proto);
else if (!bat_priv->mcast.bridged && !new_state->exists)
batadv_info(bat_priv->soft_iface,
"No %s Querier present - multicast optimizations disabled\n",
str_proto);
if (new_state->exists) {
if ((!old_state->shadowing && new_state->shadowing) ||
(!old_state->exists && new_state->shadowing))
batadv_dbg(BATADV_DBG_MCAST, bat_priv,
"%s Querier is behind our bridged segment: Might shadow listeners\n",
str_proto);
else if (old_state->shadowing && !new_state->shadowing)
batadv_dbg(BATADV_DBG_MCAST, bat_priv,
"%s Querier is not behind our bridged segment\n",
str_proto);
}
}
static void
batadv_mcast_bridge_log(struct batadv_priv *bat_priv, bool bridged,
struct batadv_mcast_querier_state *querier_ipv4,
struct batadv_mcast_querier_state *querier_ipv6)
{
if (!bat_priv->mcast.bridged && bridged)
batadv_dbg(BATADV_DBG_MCAST, bat_priv,
"Bridge added: Setting Unsnoopables(U)-flag\n");
else if (bat_priv->mcast.bridged && !bridged)
batadv_dbg(BATADV_DBG_MCAST, bat_priv,
"Bridge removed: Unsetting Unsnoopables(U)-flag\n");
if (bridged) {
batadv_mcast_querier_log(bat_priv, "IGMP",
&bat_priv->mcast.querier_ipv4,
querier_ipv4);
batadv_mcast_querier_log(bat_priv, "MLD",
&bat_priv->mcast.querier_ipv6,
querier_ipv6);
}
}
static void batadv_mcast_flags_log(struct batadv_priv *bat_priv, u8 flags)
{
u8 old_flags = bat_priv->mcast.flags;
char str_old_flags[] = "[...]";
sprintf(str_old_flags, "[%c%c%c]",
(old_flags & BATADV_MCAST_WANT_ALL_UNSNOOPABLES) ? 'U' : '.',
(old_flags & BATADV_MCAST_WANT_ALL_IPV4) ? '4' : '.',
(old_flags & BATADV_MCAST_WANT_ALL_IPV6) ? '6' : '.');
batadv_dbg(BATADV_DBG_MCAST, bat_priv,
"Changing multicast flags from '%s' to '[%c%c%c]'\n",
bat_priv->mcast.enabled ? str_old_flags : "<undefined>",
(flags & BATADV_MCAST_WANT_ALL_UNSNOOPABLES) ? 'U' : '.',
(flags & BATADV_MCAST_WANT_ALL_IPV4) ? '4' : '.',
(flags & BATADV_MCAST_WANT_ALL_IPV6) ? '6' : '.');
}
static bool batadv_mcast_mla_tvlv_update(struct batadv_priv *bat_priv)
{
struct batadv_tvlv_mcast_data mcast_data;
struct batadv_mcast_querier_state querier4 = {false, false};
struct batadv_mcast_querier_state querier6 = {false, false};
struct net_device *dev = bat_priv->soft_iface;
bool bridged;
mcast_data.flags = BATADV_NO_FLAGS;
memset(mcast_data.reserved, 0, sizeof(mcast_data.reserved));
bridged = batadv_mcast_has_bridge(bat_priv);
if (!bridged)
goto update;
#if !IS_ENABLED(CONFIG_BRIDGE_IGMP_SNOOPING)
pr_warn_once("No bridge IGMP snooping compiled - multicast optimizations disabled\n");
#endif
querier4.exists = br_multicast_has_querier_anywhere(dev, ETH_P_IP);
querier4.shadowing = br_multicast_has_querier_adjacent(dev, ETH_P_IP);
querier6.exists = br_multicast_has_querier_anywhere(dev, ETH_P_IPV6);
querier6.shadowing = br_multicast_has_querier_adjacent(dev, ETH_P_IPV6);
mcast_data.flags |= BATADV_MCAST_WANT_ALL_UNSNOOPABLES;
if (!querier4.exists || querier4.shadowing)
mcast_data.flags |= BATADV_MCAST_WANT_ALL_IPV4;
if (!querier6.exists || querier6.shadowing)
mcast_data.flags |= BATADV_MCAST_WANT_ALL_IPV6;
update:
batadv_mcast_bridge_log(bat_priv, bridged, &querier4, &querier6);
bat_priv->mcast.querier_ipv4.exists = querier4.exists;
bat_priv->mcast.querier_ipv4.shadowing = querier4.shadowing;
bat_priv->mcast.querier_ipv6.exists = querier6.exists;
bat_priv->mcast.querier_ipv6.shadowing = querier6.shadowing;
bat_priv->mcast.bridged = bridged;
if (!bat_priv->mcast.enabled ||
mcast_data.flags != bat_priv->mcast.flags) {
batadv_mcast_flags_log(bat_priv, mcast_data.flags);
batadv_tvlv_container_register(bat_priv, BATADV_TVLV_MCAST, 2,
&mcast_data, sizeof(mcast_data));
bat_priv->mcast.flags = mcast_data.flags;
bat_priv->mcast.enabled = true;
}
return !(mcast_data.flags &
(BATADV_MCAST_WANT_ALL_IPV4 | BATADV_MCAST_WANT_ALL_IPV6));
}
static void __batadv_mcast_mla_update(struct batadv_priv *bat_priv)
{
struct net_device *soft_iface = bat_priv->soft_iface;
struct hlist_head mcast_list = HLIST_HEAD_INIT;
int ret;
if (!batadv_mcast_mla_tvlv_update(bat_priv))
goto update;
ret = batadv_mcast_mla_softif_get(soft_iface, &mcast_list);
if (ret < 0)
goto out;
ret = batadv_mcast_mla_bridge_get(soft_iface, &mcast_list);
if (ret < 0)
goto out;
update:
batadv_mcast_mla_tt_retract(bat_priv, &mcast_list);
batadv_mcast_mla_tt_add(bat_priv, &mcast_list);
out:
batadv_mcast_mla_list_free(&mcast_list);
}
static void batadv_mcast_mla_update(struct work_struct *work)
{
struct delayed_work *delayed_work;
struct batadv_priv_mcast *priv_mcast;
struct batadv_priv *bat_priv;
delayed_work = to_delayed_work(work);
priv_mcast = container_of(delayed_work, struct batadv_priv_mcast, work);
bat_priv = container_of(priv_mcast, struct batadv_priv, mcast);
__batadv_mcast_mla_update(bat_priv);
batadv_mcast_start_timer(bat_priv);
}
static bool batadv_mcast_is_report_ipv4(struct sk_buff *skb)
{
if (ip_mc_check_igmp(skb, NULL) < 0)
return false;
switch (igmp_hdr(skb)->type) {
case IGMP_HOST_MEMBERSHIP_REPORT:
case IGMPV2_HOST_MEMBERSHIP_REPORT:
case IGMPV3_HOST_MEMBERSHIP_REPORT:
return true;
}
return false;
}
static int batadv_mcast_forw_mode_check_ipv4(struct batadv_priv *bat_priv,
struct sk_buff *skb,
bool *is_unsnoopable)
{
struct iphdr *iphdr;
if (!pskb_may_pull(skb, sizeof(struct ethhdr) + sizeof(*iphdr)))
return -ENOMEM;
if (batadv_mcast_is_report_ipv4(skb))
return -EINVAL;
iphdr = ip_hdr(skb);
if (!ipv4_is_local_multicast(iphdr->daddr))
return -EINVAL;
*is_unsnoopable = true;
return 0;
}
static bool batadv_mcast_is_report_ipv6(struct sk_buff *skb)
{
if (ipv6_mc_check_mld(skb, NULL) < 0)
return false;
switch (icmp6_hdr(skb)->icmp6_type) {
case ICMPV6_MGM_REPORT:
case ICMPV6_MLD2_REPORT:
return true;
}
return false;
}
static int batadv_mcast_forw_mode_check_ipv6(struct batadv_priv *bat_priv,
struct sk_buff *skb,
bool *is_unsnoopable)
{
struct ipv6hdr *ip6hdr;
if (!pskb_may_pull(skb, sizeof(struct ethhdr) + sizeof(*ip6hdr)))
return -ENOMEM;
if (batadv_mcast_is_report_ipv6(skb))
return -EINVAL;
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
#if IS_ENABLED(CONFIG_IPV6)
case ETH_P_IPV6:
return batadv_mcast_forw_mode_check_ipv6(bat_priv, skb,
is_unsnoopable);
#endif
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
if (!kref_get_unless_zero(&tmp_orig_node->refcount))
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
if (!kref_get_unless_zero(&tmp_orig_node->refcount))
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
if (!kref_get_unless_zero(&tmp_orig_node->refcount))
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
static void batadv_mcast_tvlv_ogm_handler(struct batadv_priv *bat_priv,
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
batadv_tvlv_handler_register(bat_priv, batadv_mcast_tvlv_ogm_handler,
NULL, BATADV_TVLV_MCAST, 2,
BATADV_TVLV_HANDLER_OGM_CIFNOTFND);
INIT_DELAYED_WORK(&bat_priv->mcast.work, batadv_mcast_mla_update);
batadv_mcast_start_timer(bat_priv);
}
static void batadv_mcast_flags_print_header(struct batadv_priv *bat_priv,
struct seq_file *seq)
{
u8 flags = bat_priv->mcast.flags;
char querier4, querier6, shadowing4, shadowing6;
bool bridged = bat_priv->mcast.bridged;
if (bridged) {
querier4 = bat_priv->mcast.querier_ipv4.exists ? '.' : '4';
querier6 = bat_priv->mcast.querier_ipv6.exists ? '.' : '6';
shadowing4 = bat_priv->mcast.querier_ipv4.shadowing ? '4' : '.';
shadowing6 = bat_priv->mcast.querier_ipv6.shadowing ? '6' : '.';
} else {
querier4 = '?';
querier6 = '?';
shadowing4 = '?';
shadowing6 = '?';
}
seq_printf(seq, "Multicast flags (own flags: [%c%c%c])\n",
(flags & BATADV_MCAST_WANT_ALL_UNSNOOPABLES) ? 'U' : '.',
(flags & BATADV_MCAST_WANT_ALL_IPV4) ? '4' : '.',
(flags & BATADV_MCAST_WANT_ALL_IPV6) ? '6' : '.');
seq_printf(seq, "* Bridged [U]\t\t\t\t%c\n", bridged ? 'U' : '.');
seq_printf(seq, "* No IGMP/MLD Querier [4/6]:\t\t%c/%c\n",
querier4, querier6);
seq_printf(seq, "* Shadowing IGMP/MLD Querier [4/6]:\t%c/%c\n",
shadowing4, shadowing6);
seq_puts(seq, "-------------------------------------------\n");
seq_printf(seq, " %-10s %s\n", "Originator", "Flags");
}
int batadv_mcast_flags_seq_print_text(struct seq_file *seq, void *offset)
{
struct net_device *net_dev = (struct net_device *)seq->private;
struct batadv_priv *bat_priv = netdev_priv(net_dev);
struct batadv_hard_iface *primary_if;
struct batadv_hashtable *hash = bat_priv->orig_hash;
struct batadv_orig_node *orig_node;
struct hlist_head *head;
u8 flags;
u32 i;
primary_if = batadv_seq_print_text_primary_if_get(seq);
if (!primary_if)
return 0;
batadv_mcast_flags_print_header(bat_priv, seq);
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(orig_node, head, hash_entry) {
if (!test_bit(BATADV_ORIG_CAPA_HAS_MCAST,
&orig_node->capa_initialized))
continue;
if (!test_bit(BATADV_ORIG_CAPA_HAS_MCAST,
&orig_node->capabilities)) {
seq_printf(seq, "%pM -\n", orig_node->orig);
continue;
}
flags = orig_node->mcast_flags;
seq_printf(seq, "%pM [%c%c%c]\n", orig_node->orig,
(flags & BATADV_MCAST_WANT_ALL_UNSNOOPABLES)
? 'U' : '.',
(flags & BATADV_MCAST_WANT_ALL_IPV4)
? '4' : '.',
(flags & BATADV_MCAST_WANT_ALL_IPV6)
? '6' : '.');
}
rcu_read_unlock();
}
batadv_hardif_put(primary_if);
return 0;
}
void batadv_mcast_free(struct batadv_priv *bat_priv)
{
cancel_delayed_work_sync(&bat_priv->mcast.work);
batadv_tvlv_container_unregister(bat_priv, BATADV_TVLV_MCAST, 2);
batadv_tvlv_handler_unregister(bat_priv, BATADV_TVLV_MCAST, 2);
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
