static bool ovs_must_notify(struct genl_family *family, struct genl_info *info,
unsigned int group)
{
return info->nlhdr->nlmsg_flags & NLM_F_ECHO ||
genl_has_listeners(family, genl_info_net(info), group);
}
static void ovs_notify(struct genl_family *family,
struct sk_buff *skb, struct genl_info *info)
{
genl_notify(family, skb, genl_info_net(info), info->snd_portid,
0, info->nlhdr, GFP_KERNEL);
}
void ovs_lock(void)
{
mutex_lock(&ovs_mutex);
}
void ovs_unlock(void)
{
mutex_unlock(&ovs_mutex);
}
int lockdep_ovsl_is_held(void)
{
if (debug_locks)
return lockdep_is_held(&ovs_mutex);
else
return 1;
}
static struct datapath *get_dp_rcu(struct net *net, int dp_ifindex)
{
struct net_device *dev = dev_get_by_index_rcu(net, dp_ifindex);
if (dev) {
struct vport *vport = ovs_internal_dev_get_vport(dev);
if (vport)
return vport->dp;
}
return NULL;
}
static inline struct datapath *get_dp(struct net *net, int dp_ifindex)
{
struct datapath *dp;
WARN_ON_ONCE(!rcu_read_lock_held() && !lockdep_ovsl_is_held());
rcu_read_lock();
dp = get_dp_rcu(net, dp_ifindex);
rcu_read_unlock();
return dp;
}
const char *ovs_dp_name(const struct datapath *dp)
{
struct vport *vport = ovs_vport_ovsl_rcu(dp, OVSP_LOCAL);
return vport->ops->get_name(vport);
}
static int get_dpifindex(const struct datapath *dp)
{
struct vport *local;
int ifindex;
rcu_read_lock();
local = ovs_vport_rcu(dp, OVSP_LOCAL);
if (local)
ifindex = netdev_vport_priv(local)->dev->ifindex;
else
ifindex = 0;
rcu_read_unlock();
return ifindex;
}
static void destroy_dp_rcu(struct rcu_head *rcu)
{
struct datapath *dp = container_of(rcu, struct datapath, rcu);
ovs_flow_tbl_destroy(&dp->table);
free_percpu(dp->stats_percpu);
kfree(dp->ports);
kfree(dp);
}
static struct hlist_head *vport_hash_bucket(const struct datapath *dp,
u16 port_no)
{
return &dp->ports[port_no & (DP_VPORT_HASH_BUCKETS - 1)];
}
struct vport *ovs_lookup_vport(const struct datapath *dp, u16 port_no)
{
struct vport *vport;
struct hlist_head *head;
head = vport_hash_bucket(dp, port_no);
hlist_for_each_entry_rcu(vport, head, dp_hash_node) {
if (vport->port_no == port_no)
return vport;
}
return NULL;
}
static struct vport *new_vport(const struct vport_parms *parms)
{
struct vport *vport;
vport = ovs_vport_add(parms);
if (!IS_ERR(vport)) {
struct datapath *dp = parms->dp;
struct hlist_head *head = vport_hash_bucket(dp, vport->port_no);
hlist_add_head_rcu(&vport->dp_hash_node, head);
}
return vport;
}
void ovs_dp_detach_port(struct vport *p)
{
ASSERT_OVSL();
hlist_del_rcu(&p->dp_hash_node);
ovs_vport_del(p);
}
void ovs_dp_process_packet(struct sk_buff *skb, struct sw_flow_key *key)
{
const struct vport *p = OVS_CB(skb)->input_vport;
struct datapath *dp = p->dp;
struct sw_flow *flow;
struct sw_flow_actions *sf_acts;
struct dp_stats_percpu *stats;
u64 *stats_counter;
u32 n_mask_hit;
stats = this_cpu_ptr(dp->stats_percpu);
flow = ovs_flow_tbl_lookup_stats(&dp->table, key, &n_mask_hit);
if (unlikely(!flow)) {
struct dp_upcall_info upcall;
int error;
upcall.cmd = OVS_PACKET_CMD_MISS;
upcall.userdata = NULL;
upcall.portid = ovs_vport_find_upcall_portid(p, skb);
upcall.egress_tun_info = NULL;
error = ovs_dp_upcall(dp, skb, key, &upcall);
if (unlikely(error))
kfree_skb(skb);
else
consume_skb(skb);
stats_counter = &stats->n_missed;
goto out;
}
ovs_flow_stats_update(flow, key->tp.flags, skb);
sf_acts = rcu_dereference(flow->sf_acts);
ovs_execute_actions(dp, skb, sf_acts, key);
stats_counter = &stats->n_hit;
out:
u64_stats_update_begin(&stats->syncp);
(*stats_counter)++;
stats->n_mask_hit += n_mask_hit;
u64_stats_update_end(&stats->syncp);
}
int ovs_dp_upcall(struct datapath *dp, struct sk_buff *skb,
const struct sw_flow_key *key,
const struct dp_upcall_info *upcall_info)
{
struct dp_stats_percpu *stats;
int err;
if (upcall_info->portid == 0) {
err = -ENOTCONN;
goto err;
}
if (!skb_is_gso(skb))
err = queue_userspace_packet(dp, skb, key, upcall_info);
else
err = queue_gso_packets(dp, skb, key, upcall_info);
if (err)
goto err;
return 0;
err:
stats = this_cpu_ptr(dp->stats_percpu);
u64_stats_update_begin(&stats->syncp);
stats->n_lost++;
u64_stats_update_end(&stats->syncp);
return err;
}
static int queue_gso_packets(struct datapath *dp, struct sk_buff *skb,
const struct sw_flow_key *key,
const struct dp_upcall_info *upcall_info)
{
unsigned short gso_type = skb_shinfo(skb)->gso_type;
struct sw_flow_key later_key;
struct sk_buff *segs, *nskb;
struct ovs_skb_cb ovs_cb;
int err;
ovs_cb = *OVS_CB(skb);
segs = __skb_gso_segment(skb, NETIF_F_SG, false);
*OVS_CB(skb) = ovs_cb;
if (IS_ERR(segs))
return PTR_ERR(segs);
if (segs == NULL)
return -EINVAL;
if (gso_type & SKB_GSO_UDP) {
later_key = *key;
later_key.ip.frag = OVS_FRAG_TYPE_LATER;
}
skb = segs;
do {
*OVS_CB(skb) = ovs_cb;
if (gso_type & SKB_GSO_UDP && skb != segs)
key = &later_key;
err = queue_userspace_packet(dp, skb, key, upcall_info);
if (err)
break;
} while ((skb = skb->next));
skb = segs;
do {
nskb = skb->next;
if (err)
kfree_skb(skb);
else
consume_skb(skb);
} while ((skb = nskb));
return err;
}
static size_t upcall_msg_size(const struct dp_upcall_info *upcall_info,
unsigned int hdrlen)
{
size_t size = NLMSG_ALIGN(sizeof(struct ovs_header))
+ nla_total_size(hdrlen)
+ nla_total_size(ovs_key_attr_size());
if (upcall_info->userdata)
size += NLA_ALIGN(upcall_info->userdata->nla_len);
if (upcall_info->egress_tun_info)
size += nla_total_size(ovs_tun_key_attr_size());
return size;
}
static int queue_userspace_packet(struct datapath *dp, struct sk_buff *skb,
const struct sw_flow_key *key,
const struct dp_upcall_info *upcall_info)
{
struct ovs_header *upcall;
struct sk_buff *nskb = NULL;
struct sk_buff *user_skb = NULL;
struct nlattr *nla;
struct genl_info info = {
.dst_sk = ovs_dp_get_net(dp)->genl_sock,
.snd_portid = upcall_info->portid,
};
size_t len;
unsigned int hlen;
int err, dp_ifindex;
dp_ifindex = get_dpifindex(dp);
if (!dp_ifindex)
return -ENODEV;
if (skb_vlan_tag_present(skb)) {
nskb = skb_clone(skb, GFP_ATOMIC);
if (!nskb)
return -ENOMEM;
nskb = __vlan_hwaccel_push_inside(nskb);
if (!nskb)
return -ENOMEM;
skb = nskb;
}
if (nla_attr_size(skb->len) > USHRT_MAX) {
err = -EFBIG;
goto out;
}
if (skb->ip_summed == CHECKSUM_PARTIAL &&
(err = skb_checksum_help(skb)))
goto out;
if (dp->user_features & OVS_DP_F_UNALIGNED)
hlen = skb_zerocopy_headlen(skb);
else
hlen = skb->len;
len = upcall_msg_size(upcall_info, hlen);
user_skb = genlmsg_new_unicast(len, &info, GFP_ATOMIC);
if (!user_skb) {
err = -ENOMEM;
goto out;
}
upcall = genlmsg_put(user_skb, 0, 0, &dp_packet_genl_family,
0, upcall_info->cmd);
upcall->dp_ifindex = dp_ifindex;
err = ovs_nla_put_key(key, key, OVS_PACKET_ATTR_KEY, false, user_skb);
BUG_ON(err);
if (upcall_info->userdata)
__nla_put(user_skb, OVS_PACKET_ATTR_USERDATA,
nla_len(upcall_info->userdata),
nla_data(upcall_info->userdata));
if (upcall_info->egress_tun_info) {
nla = nla_nest_start(user_skb, OVS_PACKET_ATTR_EGRESS_TUN_KEY);
err = ovs_nla_put_egress_tunnel_key(user_skb,
upcall_info->egress_tun_info);
BUG_ON(err);
nla_nest_end(user_skb, nla);
}
if (!(nla = nla_reserve(user_skb, OVS_PACKET_ATTR_PACKET, 0))) {
err = -ENOBUFS;
goto out;
}
nla->nla_len = nla_attr_size(skb->len);
err = skb_zerocopy(user_skb, skb, skb->len, hlen);
if (err)
goto out;
if (!(dp->user_features & OVS_DP_F_UNALIGNED)) {
size_t plen = NLA_ALIGN(user_skb->len) - user_skb->len;
if (plen > 0)
memset(skb_put(user_skb, plen), 0, plen);
}
((struct nlmsghdr *) user_skb->data)->nlmsg_len = user_skb->len;
err = genlmsg_unicast(ovs_dp_get_net(dp), user_skb, upcall_info->portid);
user_skb = NULL;
out:
if (err)
skb_tx_error(skb);
kfree_skb(user_skb);
kfree_skb(nskb);
return err;
}
static int ovs_packet_cmd_execute(struct sk_buff *skb, struct genl_info *info)
{
struct ovs_header *ovs_header = info->userhdr;
struct nlattr **a = info->attrs;
struct sw_flow_actions *acts;
struct sk_buff *packet;
struct sw_flow *flow;
struct sw_flow_actions *sf_acts;
struct datapath *dp;
struct ethhdr *eth;
struct vport *input_vport;
int len;
int err;
bool log = !a[OVS_PACKET_ATTR_PROBE];
err = -EINVAL;
if (!a[OVS_PACKET_ATTR_PACKET] || !a[OVS_PACKET_ATTR_KEY] ||
!a[OVS_PACKET_ATTR_ACTIONS])
goto err;
len = nla_len(a[OVS_PACKET_ATTR_PACKET]);
packet = __dev_alloc_skb(NET_IP_ALIGN + len, GFP_KERNEL);
err = -ENOMEM;
if (!packet)
goto err;
skb_reserve(packet, NET_IP_ALIGN);
nla_memcpy(__skb_put(packet, len), a[OVS_PACKET_ATTR_PACKET], len);
skb_reset_mac_header(packet);
eth = eth_hdr(packet);
if (ntohs(eth->h_proto) >= ETH_P_802_3_MIN)
packet->protocol = eth->h_proto;
else
packet->protocol = htons(ETH_P_802_2);
flow = ovs_flow_alloc();
err = PTR_ERR(flow);
if (IS_ERR(flow))
goto err_kfree_skb;
err = ovs_flow_key_extract_userspace(a[OVS_PACKET_ATTR_KEY], packet,
&flow->key, log);
if (err)
goto err_flow_free;
err = ovs_nla_copy_actions(a[OVS_PACKET_ATTR_ACTIONS],
&flow->key, &acts, log);
if (err)
goto err_flow_free;
rcu_assign_pointer(flow->sf_acts, acts);
OVS_CB(packet)->egress_tun_info = NULL;
packet->priority = flow->key.phy.priority;
packet->mark = flow->key.phy.skb_mark;
rcu_read_lock();
dp = get_dp_rcu(sock_net(skb->sk), ovs_header->dp_ifindex);
err = -ENODEV;
if (!dp)
goto err_unlock;
input_vport = ovs_vport_rcu(dp, flow->key.phy.in_port);
if (!input_vport)
input_vport = ovs_vport_rcu(dp, OVSP_LOCAL);
if (!input_vport)
goto err_unlock;
OVS_CB(packet)->input_vport = input_vport;
sf_acts = rcu_dereference(flow->sf_acts);
local_bh_disable();
err = ovs_execute_actions(dp, packet, sf_acts, &flow->key);
local_bh_enable();
rcu_read_unlock();
ovs_flow_free(flow, false);
return err;
err_unlock:
rcu_read_unlock();
err_flow_free:
ovs_flow_free(flow, false);
err_kfree_skb:
kfree_skb(packet);
err:
return err;
}
static void get_dp_stats(const struct datapath *dp, struct ovs_dp_stats *stats,
struct ovs_dp_megaflow_stats *mega_stats)
{
int i;
memset(mega_stats, 0, sizeof(*mega_stats));
stats->n_flows = ovs_flow_tbl_count(&dp->table);
mega_stats->n_masks = ovs_flow_tbl_num_masks(&dp->table);
stats->n_hit = stats->n_missed = stats->n_lost = 0;
for_each_possible_cpu(i) {
const struct dp_stats_percpu *percpu_stats;
struct dp_stats_percpu local_stats;
unsigned int start;
percpu_stats = per_cpu_ptr(dp->stats_percpu, i);
do {
start = u64_stats_fetch_begin_irq(&percpu_stats->syncp);
local_stats = *percpu_stats;
} while (u64_stats_fetch_retry_irq(&percpu_stats->syncp, start));
stats->n_hit += local_stats.n_hit;
stats->n_missed += local_stats.n_missed;
stats->n_lost += local_stats.n_lost;
mega_stats->n_mask_hit += local_stats.n_mask_hit;
}
}
static bool should_fill_key(const struct sw_flow_id *sfid, uint32_t ufid_flags)
{
return ovs_identifier_is_ufid(sfid) &&
!(ufid_flags & OVS_UFID_F_OMIT_KEY);
}
static bool should_fill_mask(uint32_t ufid_flags)
{
return !(ufid_flags & OVS_UFID_F_OMIT_MASK);
}
static bool should_fill_actions(uint32_t ufid_flags)
{
return !(ufid_flags & OVS_UFID_F_OMIT_ACTIONS);
}
static size_t ovs_flow_cmd_msg_size(const struct sw_flow_actions *acts,
const struct sw_flow_id *sfid,
uint32_t ufid_flags)
{
size_t len = NLMSG_ALIGN(sizeof(struct ovs_header));
if (sfid && ovs_identifier_is_ufid(sfid))
len += nla_total_size(sfid->ufid_len);
if (!sfid || should_fill_key(sfid, ufid_flags))
len += nla_total_size(ovs_key_attr_size());
if (should_fill_mask(ufid_flags))
len += nla_total_size(ovs_key_attr_size());
if (should_fill_actions(ufid_flags))
len += nla_total_size(acts->actions_len);
return len
+ nla_total_size(sizeof(struct ovs_flow_stats))
+ nla_total_size(1)
+ nla_total_size(8);
}
static int ovs_flow_cmd_fill_stats(const struct sw_flow *flow,
struct sk_buff *skb)
{
struct ovs_flow_stats stats;
__be16 tcp_flags;
unsigned long used;
ovs_flow_stats_get(flow, &stats, &used, &tcp_flags);
if (used &&
nla_put_u64(skb, OVS_FLOW_ATTR_USED, ovs_flow_used_time(used)))
return -EMSGSIZE;
if (stats.n_packets &&
nla_put(skb, OVS_FLOW_ATTR_STATS, sizeof(struct ovs_flow_stats), &stats))
return -EMSGSIZE;
if ((u8)ntohs(tcp_flags) &&
nla_put_u8(skb, OVS_FLOW_ATTR_TCP_FLAGS, (u8)ntohs(tcp_flags)))
return -EMSGSIZE;
return 0;
}
static int ovs_flow_cmd_fill_actions(const struct sw_flow *flow,
struct sk_buff *skb, int skb_orig_len)
{
struct nlattr *start;
int err;
start = nla_nest_start(skb, OVS_FLOW_ATTR_ACTIONS);
if (start) {
const struct sw_flow_actions *sf_acts;
sf_acts = rcu_dereference_ovsl(flow->sf_acts);
err = ovs_nla_put_actions(sf_acts->actions,
sf_acts->actions_len, skb);
if (!err)
nla_nest_end(skb, start);
else {
if (skb_orig_len)
return err;
nla_nest_cancel(skb, start);
}
} else if (skb_orig_len) {
return -EMSGSIZE;
}
return 0;
}
static int ovs_flow_cmd_fill_info(const struct sw_flow *flow, int dp_ifindex,
struct sk_buff *skb, u32 portid,
u32 seq, u32 flags, u8 cmd, u32 ufid_flags)
{
const int skb_orig_len = skb->len;
struct ovs_header *ovs_header;
int err;
ovs_header = genlmsg_put(skb, portid, seq, &dp_flow_genl_family,
flags, cmd);
if (!ovs_header)
return -EMSGSIZE;
ovs_header->dp_ifindex = dp_ifindex;
err = ovs_nla_put_identifier(flow, skb);
if (err)
goto error;
if (should_fill_key(&flow->id, ufid_flags)) {
err = ovs_nla_put_masked_key(flow, skb);
if (err)
goto error;
}
if (should_fill_mask(ufid_flags)) {
err = ovs_nla_put_mask(flow, skb);
if (err)
goto error;
}
err = ovs_flow_cmd_fill_stats(flow, skb);
if (err)
goto error;
if (should_fill_actions(ufid_flags)) {
err = ovs_flow_cmd_fill_actions(flow, skb, skb_orig_len);
if (err)
goto error;
}
genlmsg_end(skb, ovs_header);
return 0;
error:
genlmsg_cancel(skb, ovs_header);
return err;
}
static struct sk_buff *ovs_flow_cmd_alloc_info(const struct sw_flow_actions *acts,
const struct sw_flow_id *sfid,
struct genl_info *info,
bool always,
uint32_t ufid_flags)
{
struct sk_buff *skb;
size_t len;
if (!always && !ovs_must_notify(&dp_flow_genl_family, info, 0))
return NULL;
len = ovs_flow_cmd_msg_size(acts, sfid, ufid_flags);
skb = genlmsg_new_unicast(len, info, GFP_KERNEL);
if (!skb)
return ERR_PTR(-ENOMEM);
return skb;
}
static struct sk_buff *ovs_flow_cmd_build_info(const struct sw_flow *flow,
int dp_ifindex,
struct genl_info *info, u8 cmd,
bool always, u32 ufid_flags)
{
struct sk_buff *skb;
int retval;
skb = ovs_flow_cmd_alloc_info(ovsl_dereference(flow->sf_acts),
&flow->id, info, always, ufid_flags);
if (IS_ERR_OR_NULL(skb))
return skb;
retval = ovs_flow_cmd_fill_info(flow, dp_ifindex, skb,
info->snd_portid, info->snd_seq, 0,
cmd, ufid_flags);
BUG_ON(retval < 0);
return skb;
}
static int ovs_flow_cmd_new(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct ovs_header *ovs_header = info->userhdr;
struct sw_flow *flow = NULL, *new_flow;
struct sw_flow_mask mask;
struct sk_buff *reply;
struct datapath *dp;
struct sw_flow_key key;
struct sw_flow_actions *acts;
struct sw_flow_match match;
u32 ufid_flags = ovs_nla_get_ufid_flags(a[OVS_FLOW_ATTR_UFID_FLAGS]);
int error;
bool log = !a[OVS_FLOW_ATTR_PROBE];
error = -EINVAL;
if (!a[OVS_FLOW_ATTR_KEY]) {
OVS_NLERR(log, "Flow key attr not present in new flow.");
goto error;
}
if (!a[OVS_FLOW_ATTR_ACTIONS]) {
OVS_NLERR(log, "Flow actions attr not present in new flow.");
goto error;
}
new_flow = ovs_flow_alloc();
if (IS_ERR(new_flow)) {
error = PTR_ERR(new_flow);
goto error;
}
ovs_match_init(&match, &key, &mask);
error = ovs_nla_get_match(&match, a[OVS_FLOW_ATTR_KEY],
a[OVS_FLOW_ATTR_MASK], log);
if (error)
goto err_kfree_flow;
ovs_flow_mask_key(&new_flow->key, &key, &mask);
error = ovs_nla_get_identifier(&new_flow->id, a[OVS_FLOW_ATTR_UFID],
&key, log);
if (error)
goto err_kfree_flow;
error = ovs_nla_copy_actions(a[OVS_FLOW_ATTR_ACTIONS], &new_flow->key,
&acts, log);
if (error) {
OVS_NLERR(log, "Flow actions may not be safe on all matching packets.");
goto err_kfree_flow;
}
reply = ovs_flow_cmd_alloc_info(acts, &new_flow->id, info, false,
ufid_flags);
if (IS_ERR(reply)) {
error = PTR_ERR(reply);
goto err_kfree_acts;
}
ovs_lock();
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
if (unlikely(!dp)) {
error = -ENODEV;
goto err_unlock_ovs;
}
if (ovs_identifier_is_ufid(&new_flow->id))
flow = ovs_flow_tbl_lookup_ufid(&dp->table, &new_flow->id);
if (!flow)
flow = ovs_flow_tbl_lookup(&dp->table, &key);
if (likely(!flow)) {
rcu_assign_pointer(new_flow->sf_acts, acts);
error = ovs_flow_tbl_insert(&dp->table, new_flow, &mask);
if (unlikely(error)) {
acts = NULL;
goto err_unlock_ovs;
}
if (unlikely(reply)) {
error = ovs_flow_cmd_fill_info(new_flow,
ovs_header->dp_ifindex,
reply, info->snd_portid,
info->snd_seq, 0,
OVS_FLOW_CMD_NEW,
ufid_flags);
BUG_ON(error < 0);
}
ovs_unlock();
} else {
struct sw_flow_actions *old_acts;
if (unlikely(info->nlhdr->nlmsg_flags & (NLM_F_CREATE
| NLM_F_EXCL))) {
error = -EEXIST;
goto err_unlock_ovs;
}
if (unlikely(!ovs_flow_cmp(flow, &match))) {
if (ovs_identifier_is_key(&flow->id))
flow = ovs_flow_tbl_lookup_exact(&dp->table,
&match);
else
flow = NULL;
if (!flow) {
error = -ENOENT;
goto err_unlock_ovs;
}
}
old_acts = ovsl_dereference(flow->sf_acts);
rcu_assign_pointer(flow->sf_acts, acts);
if (unlikely(reply)) {
error = ovs_flow_cmd_fill_info(flow,
ovs_header->dp_ifindex,
reply, info->snd_portid,
info->snd_seq, 0,
OVS_FLOW_CMD_NEW,
ufid_flags);
BUG_ON(error < 0);
}
ovs_unlock();
ovs_nla_free_flow_actions(old_acts);
ovs_flow_free(new_flow, false);
}
if (reply)
ovs_notify(&dp_flow_genl_family, reply, info);
return 0;
err_unlock_ovs:
ovs_unlock();
kfree_skb(reply);
err_kfree_acts:
kfree(acts);
err_kfree_flow:
ovs_flow_free(new_flow, false);
error:
return error;
}
static struct sw_flow_actions *get_flow_actions(const struct nlattr *a,
const struct sw_flow_key *key,
const struct sw_flow_mask *mask,
bool log)
{
struct sw_flow_actions *acts;
struct sw_flow_key masked_key;
int error;
ovs_flow_mask_key(&masked_key, key, mask);
error = ovs_nla_copy_actions(a, &masked_key, &acts, log);
if (error) {
OVS_NLERR(log,
"Actions may not be safe on all matching packets");
return ERR_PTR(error);
}
return acts;
}
static int ovs_flow_cmd_set(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct ovs_header *ovs_header = info->userhdr;
struct sw_flow_key key;
struct sw_flow *flow;
struct sw_flow_mask mask;
struct sk_buff *reply = NULL;
struct datapath *dp;
struct sw_flow_actions *old_acts = NULL, *acts = NULL;
struct sw_flow_match match;
struct sw_flow_id sfid;
u32 ufid_flags = ovs_nla_get_ufid_flags(a[OVS_FLOW_ATTR_UFID_FLAGS]);
int error;
bool log = !a[OVS_FLOW_ATTR_PROBE];
bool ufid_present;
error = -EINVAL;
if (!a[OVS_FLOW_ATTR_KEY]) {
OVS_NLERR(log, "Flow key attribute not present in set flow.");
goto error;
}
ufid_present = ovs_nla_get_ufid(&sfid, a[OVS_FLOW_ATTR_UFID], log);
ovs_match_init(&match, &key, &mask);
error = ovs_nla_get_match(&match, a[OVS_FLOW_ATTR_KEY],
a[OVS_FLOW_ATTR_MASK], log);
if (error)
goto error;
if (a[OVS_FLOW_ATTR_ACTIONS]) {
acts = get_flow_actions(a[OVS_FLOW_ATTR_ACTIONS], &key, &mask,
log);
if (IS_ERR(acts)) {
error = PTR_ERR(acts);
goto error;
}
reply = ovs_flow_cmd_alloc_info(acts, &sfid, info, false,
ufid_flags);
if (IS_ERR(reply)) {
error = PTR_ERR(reply);
goto err_kfree_acts;
}
}
ovs_lock();
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
if (unlikely(!dp)) {
error = -ENODEV;
goto err_unlock_ovs;
}
if (ufid_present)
flow = ovs_flow_tbl_lookup_ufid(&dp->table, &sfid);
else
flow = ovs_flow_tbl_lookup_exact(&dp->table, &match);
if (unlikely(!flow)) {
error = -ENOENT;
goto err_unlock_ovs;
}
if (likely(acts)) {
old_acts = ovsl_dereference(flow->sf_acts);
rcu_assign_pointer(flow->sf_acts, acts);
if (unlikely(reply)) {
error = ovs_flow_cmd_fill_info(flow,
ovs_header->dp_ifindex,
reply, info->snd_portid,
info->snd_seq, 0,
OVS_FLOW_CMD_NEW,
ufid_flags);
BUG_ON(error < 0);
}
} else {
reply = ovs_flow_cmd_build_info(flow, ovs_header->dp_ifindex,
info, OVS_FLOW_CMD_NEW, false,
ufid_flags);
if (unlikely(IS_ERR(reply))) {
error = PTR_ERR(reply);
goto err_unlock_ovs;
}
}
if (a[OVS_FLOW_ATTR_CLEAR])
ovs_flow_stats_clear(flow);
ovs_unlock();
if (reply)
ovs_notify(&dp_flow_genl_family, reply, info);
if (old_acts)
ovs_nla_free_flow_actions(old_acts);
return 0;
err_unlock_ovs:
ovs_unlock();
kfree_skb(reply);
err_kfree_acts:
kfree(acts);
error:
return error;
}
static int ovs_flow_cmd_get(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct ovs_header *ovs_header = info->userhdr;
struct sw_flow_key key;
struct sk_buff *reply;
struct sw_flow *flow;
struct datapath *dp;
struct sw_flow_match match;
struct sw_flow_id ufid;
u32 ufid_flags = ovs_nla_get_ufid_flags(a[OVS_FLOW_ATTR_UFID_FLAGS]);
int err = 0;
bool log = !a[OVS_FLOW_ATTR_PROBE];
bool ufid_present;
ufid_present = ovs_nla_get_ufid(&ufid, a[OVS_FLOW_ATTR_UFID], log);
if (a[OVS_FLOW_ATTR_KEY]) {
ovs_match_init(&match, &key, NULL);
err = ovs_nla_get_match(&match, a[OVS_FLOW_ATTR_KEY], NULL,
log);
} else if (!ufid_present) {
OVS_NLERR(log,
"Flow get message rejected, Key attribute missing.");
err = -EINVAL;
}
if (err)
return err;
ovs_lock();
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
if (!dp) {
err = -ENODEV;
goto unlock;
}
if (ufid_present)
flow = ovs_flow_tbl_lookup_ufid(&dp->table, &ufid);
else
flow = ovs_flow_tbl_lookup_exact(&dp->table, &match);
if (!flow) {
err = -ENOENT;
goto unlock;
}
reply = ovs_flow_cmd_build_info(flow, ovs_header->dp_ifindex, info,
OVS_FLOW_CMD_NEW, true, ufid_flags);
if (IS_ERR(reply)) {
err = PTR_ERR(reply);
goto unlock;
}
ovs_unlock();
return genlmsg_reply(reply, info);
unlock:
ovs_unlock();
return err;
}
static int ovs_flow_cmd_del(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct ovs_header *ovs_header = info->userhdr;
struct sw_flow_key key;
struct sk_buff *reply;
struct sw_flow *flow = NULL;
struct datapath *dp;
struct sw_flow_match match;
struct sw_flow_id ufid;
u32 ufid_flags = ovs_nla_get_ufid_flags(a[OVS_FLOW_ATTR_UFID_FLAGS]);
int err;
bool log = !a[OVS_FLOW_ATTR_PROBE];
bool ufid_present;
ufid_present = ovs_nla_get_ufid(&ufid, a[OVS_FLOW_ATTR_UFID], log);
if (a[OVS_FLOW_ATTR_KEY]) {
ovs_match_init(&match, &key, NULL);
err = ovs_nla_get_match(&match, a[OVS_FLOW_ATTR_KEY], NULL,
log);
if (unlikely(err))
return err;
}
ovs_lock();
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
if (unlikely(!dp)) {
err = -ENODEV;
goto unlock;
}
if (unlikely(!a[OVS_FLOW_ATTR_KEY] && !ufid_present)) {
err = ovs_flow_tbl_flush(&dp->table);
goto unlock;
}
if (ufid_present)
flow = ovs_flow_tbl_lookup_ufid(&dp->table, &ufid);
else
flow = ovs_flow_tbl_lookup_exact(&dp->table, &match);
if (unlikely(!flow)) {
err = -ENOENT;
goto unlock;
}
ovs_flow_tbl_remove(&dp->table, flow);
ovs_unlock();
reply = ovs_flow_cmd_alloc_info((const struct sw_flow_actions __force *) flow->sf_acts,
&flow->id, info, false, ufid_flags);
if (likely(reply)) {
if (likely(!IS_ERR(reply))) {
rcu_read_lock();
err = ovs_flow_cmd_fill_info(flow, ovs_header->dp_ifindex,
reply, info->snd_portid,
info->snd_seq, 0,
OVS_FLOW_CMD_DEL,
ufid_flags);
rcu_read_unlock();
BUG_ON(err < 0);
ovs_notify(&dp_flow_genl_family, reply, info);
} else {
netlink_set_err(sock_net(skb->sk)->genl_sock, 0, 0, PTR_ERR(reply));
}
}
ovs_flow_free(flow, true);
return 0;
unlock:
ovs_unlock();
return err;
}
static int ovs_flow_cmd_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct nlattr *a[__OVS_FLOW_ATTR_MAX];
struct ovs_header *ovs_header = genlmsg_data(nlmsg_data(cb->nlh));
struct table_instance *ti;
struct datapath *dp;
u32 ufid_flags;
int err;
err = genlmsg_parse(cb->nlh, &dp_flow_genl_family, a,
OVS_FLOW_ATTR_MAX, flow_policy);
if (err)
return err;
ufid_flags = ovs_nla_get_ufid_flags(a[OVS_FLOW_ATTR_UFID_FLAGS]);
rcu_read_lock();
dp = get_dp_rcu(sock_net(skb->sk), ovs_header->dp_ifindex);
if (!dp) {
rcu_read_unlock();
return -ENODEV;
}
ti = rcu_dereference(dp->table.ti);
for (;;) {
struct sw_flow *flow;
u32 bucket, obj;
bucket = cb->args[0];
obj = cb->args[1];
flow = ovs_flow_tbl_dump_next(ti, &bucket, &obj);
if (!flow)
break;
if (ovs_flow_cmd_fill_info(flow, ovs_header->dp_ifindex, skb,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, NLM_F_MULTI,
OVS_FLOW_CMD_NEW, ufid_flags) < 0)
break;
cb->args[0] = bucket;
cb->args[1] = obj;
}
rcu_read_unlock();
return skb->len;
}
static size_t ovs_dp_cmd_msg_size(void)
{
size_t msgsize = NLMSG_ALIGN(sizeof(struct ovs_header));
msgsize += nla_total_size(IFNAMSIZ);
msgsize += nla_total_size(sizeof(struct ovs_dp_stats));
msgsize += nla_total_size(sizeof(struct ovs_dp_megaflow_stats));
msgsize += nla_total_size(sizeof(u32));
return msgsize;
}
static int ovs_dp_cmd_fill_info(struct datapath *dp, struct sk_buff *skb,
u32 portid, u32 seq, u32 flags, u8 cmd)
{
struct ovs_header *ovs_header;
struct ovs_dp_stats dp_stats;
struct ovs_dp_megaflow_stats dp_megaflow_stats;
int err;
ovs_header = genlmsg_put(skb, portid, seq, &dp_datapath_genl_family,
flags, cmd);
if (!ovs_header)
goto error;
ovs_header->dp_ifindex = get_dpifindex(dp);
err = nla_put_string(skb, OVS_DP_ATTR_NAME, ovs_dp_name(dp));
if (err)
goto nla_put_failure;
get_dp_stats(dp, &dp_stats, &dp_megaflow_stats);
if (nla_put(skb, OVS_DP_ATTR_STATS, sizeof(struct ovs_dp_stats),
&dp_stats))
goto nla_put_failure;
if (nla_put(skb, OVS_DP_ATTR_MEGAFLOW_STATS,
sizeof(struct ovs_dp_megaflow_stats),
&dp_megaflow_stats))
goto nla_put_failure;
if (nla_put_u32(skb, OVS_DP_ATTR_USER_FEATURES, dp->user_features))
goto nla_put_failure;
genlmsg_end(skb, ovs_header);
return 0;
nla_put_failure:
genlmsg_cancel(skb, ovs_header);
error:
return -EMSGSIZE;
}
static struct sk_buff *ovs_dp_cmd_alloc_info(struct genl_info *info)
{
return genlmsg_new_unicast(ovs_dp_cmd_msg_size(), info, GFP_KERNEL);
}
static struct datapath *lookup_datapath(struct net *net,
const struct ovs_header *ovs_header,
struct nlattr *a[OVS_DP_ATTR_MAX + 1])
{
struct datapath *dp;
if (!a[OVS_DP_ATTR_NAME])
dp = get_dp(net, ovs_header->dp_ifindex);
else {
struct vport *vport;
vport = ovs_vport_locate(net, nla_data(a[OVS_DP_ATTR_NAME]));
dp = vport && vport->port_no == OVSP_LOCAL ? vport->dp : NULL;
}
return dp ? dp : ERR_PTR(-ENODEV);
}
static void ovs_dp_reset_user_features(struct sk_buff *skb, struct genl_info *info)
{
struct datapath *dp;
dp = lookup_datapath(sock_net(skb->sk), info->userhdr, info->attrs);
if (IS_ERR(dp))
return;
WARN(dp->user_features, "Dropping previously announced user features\n");
dp->user_features = 0;
}
static void ovs_dp_change(struct datapath *dp, struct nlattr *a[])
{
if (a[OVS_DP_ATTR_USER_FEATURES])
dp->user_features = nla_get_u32(a[OVS_DP_ATTR_USER_FEATURES]);
}
static int ovs_dp_cmd_new(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct vport_parms parms;
struct sk_buff *reply;
struct datapath *dp;
struct vport *vport;
struct ovs_net *ovs_net;
int err, i;
err = -EINVAL;
if (!a[OVS_DP_ATTR_NAME] || !a[OVS_DP_ATTR_UPCALL_PID])
goto err;
reply = ovs_dp_cmd_alloc_info(info);
if (!reply)
return -ENOMEM;
err = -ENOMEM;
dp = kzalloc(sizeof(*dp), GFP_KERNEL);
if (dp == NULL)
goto err_free_reply;
ovs_dp_set_net(dp, sock_net(skb->sk));
err = ovs_flow_tbl_init(&dp->table);
if (err)
goto err_free_dp;
dp->stats_percpu = netdev_alloc_pcpu_stats(struct dp_stats_percpu);
if (!dp->stats_percpu) {
err = -ENOMEM;
goto err_destroy_table;
}
dp->ports = kmalloc(DP_VPORT_HASH_BUCKETS * sizeof(struct hlist_head),
GFP_KERNEL);
if (!dp->ports) {
err = -ENOMEM;
goto err_destroy_percpu;
}
for (i = 0; i < DP_VPORT_HASH_BUCKETS; i++)
INIT_HLIST_HEAD(&dp->ports[i]);
parms.name = nla_data(a[OVS_DP_ATTR_NAME]);
parms.type = OVS_VPORT_TYPE_INTERNAL;
parms.options = NULL;
parms.dp = dp;
parms.port_no = OVSP_LOCAL;
parms.upcall_portids = a[OVS_DP_ATTR_UPCALL_PID];
ovs_dp_change(dp, a);
ovs_lock();
vport = new_vport(&parms);
if (IS_ERR(vport)) {
err = PTR_ERR(vport);
if (err == -EBUSY)
err = -EEXIST;
if (err == -EEXIST) {
if (info->genlhdr->version < OVS_DP_VER_FEATURES)
ovs_dp_reset_user_features(skb, info);
}
goto err_destroy_ports_array;
}
err = ovs_dp_cmd_fill_info(dp, reply, info->snd_portid,
info->snd_seq, 0, OVS_DP_CMD_NEW);
BUG_ON(err < 0);
ovs_net = net_generic(ovs_dp_get_net(dp), ovs_net_id);
list_add_tail_rcu(&dp->list_node, &ovs_net->dps);
ovs_unlock();
ovs_notify(&dp_datapath_genl_family, reply, info);
return 0;
err_destroy_ports_array:
ovs_unlock();
kfree(dp->ports);
err_destroy_percpu:
free_percpu(dp->stats_percpu);
err_destroy_table:
ovs_flow_tbl_destroy(&dp->table);
err_free_dp:
kfree(dp);
err_free_reply:
kfree_skb(reply);
err:
return err;
}
static void __dp_destroy(struct datapath *dp)
{
int i;
for (i = 0; i < DP_VPORT_HASH_BUCKETS; i++) {
struct vport *vport;
struct hlist_node *n;
hlist_for_each_entry_safe(vport, n, &dp->ports[i], dp_hash_node)
if (vport->port_no != OVSP_LOCAL)
ovs_dp_detach_port(vport);
}
list_del_rcu(&dp->list_node);
ovs_dp_detach_port(ovs_vport_ovsl(dp, OVSP_LOCAL));
call_rcu(&dp->rcu, destroy_dp_rcu);
}
static int ovs_dp_cmd_del(struct sk_buff *skb, struct genl_info *info)
{
struct sk_buff *reply;
struct datapath *dp;
int err;
reply = ovs_dp_cmd_alloc_info(info);
if (!reply)
return -ENOMEM;
ovs_lock();
dp = lookup_datapath(sock_net(skb->sk), info->userhdr, info->attrs);
err = PTR_ERR(dp);
if (IS_ERR(dp))
goto err_unlock_free;
err = ovs_dp_cmd_fill_info(dp, reply, info->snd_portid,
info->snd_seq, 0, OVS_DP_CMD_DEL);
BUG_ON(err < 0);
__dp_destroy(dp);
ovs_unlock();
ovs_notify(&dp_datapath_genl_family, reply, info);
return 0;
err_unlock_free:
ovs_unlock();
kfree_skb(reply);
return err;
}
static int ovs_dp_cmd_set(struct sk_buff *skb, struct genl_info *info)
{
struct sk_buff *reply;
struct datapath *dp;
int err;
reply = ovs_dp_cmd_alloc_info(info);
if (!reply)
return -ENOMEM;
ovs_lock();
dp = lookup_datapath(sock_net(skb->sk), info->userhdr, info->attrs);
err = PTR_ERR(dp);
if (IS_ERR(dp))
goto err_unlock_free;
ovs_dp_change(dp, info->attrs);
err = ovs_dp_cmd_fill_info(dp, reply, info->snd_portid,
info->snd_seq, 0, OVS_DP_CMD_NEW);
BUG_ON(err < 0);
ovs_unlock();
ovs_notify(&dp_datapath_genl_family, reply, info);
return 0;
err_unlock_free:
ovs_unlock();
kfree_skb(reply);
return err;
}
static int ovs_dp_cmd_get(struct sk_buff *skb, struct genl_info *info)
{
struct sk_buff *reply;
struct datapath *dp;
int err;
reply = ovs_dp_cmd_alloc_info(info);
if (!reply)
return -ENOMEM;
ovs_lock();
dp = lookup_datapath(sock_net(skb->sk), info->userhdr, info->attrs);
if (IS_ERR(dp)) {
err = PTR_ERR(dp);
goto err_unlock_free;
}
err = ovs_dp_cmd_fill_info(dp, reply, info->snd_portid,
info->snd_seq, 0, OVS_DP_CMD_NEW);
BUG_ON(err < 0);
ovs_unlock();
return genlmsg_reply(reply, info);
err_unlock_free:
ovs_unlock();
kfree_skb(reply);
return err;
}
static int ovs_dp_cmd_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct ovs_net *ovs_net = net_generic(sock_net(skb->sk), ovs_net_id);
struct datapath *dp;
int skip = cb->args[0];
int i = 0;
ovs_lock();
list_for_each_entry(dp, &ovs_net->dps, list_node) {
if (i >= skip &&
ovs_dp_cmd_fill_info(dp, skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, NLM_F_MULTI,
OVS_DP_CMD_NEW) < 0)
break;
i++;
}
ovs_unlock();
cb->args[0] = i;
return skb->len;
}
static int ovs_vport_cmd_fill_info(struct vport *vport, struct sk_buff *skb,
u32 portid, u32 seq, u32 flags, u8 cmd)
{
struct ovs_header *ovs_header;
struct ovs_vport_stats vport_stats;
int err;
ovs_header = genlmsg_put(skb, portid, seq, &dp_vport_genl_family,
flags, cmd);
if (!ovs_header)
return -EMSGSIZE;
ovs_header->dp_ifindex = get_dpifindex(vport->dp);
if (nla_put_u32(skb, OVS_VPORT_ATTR_PORT_NO, vport->port_no) ||
nla_put_u32(skb, OVS_VPORT_ATTR_TYPE, vport->ops->type) ||
nla_put_string(skb, OVS_VPORT_ATTR_NAME,
vport->ops->get_name(vport)))
goto nla_put_failure;
ovs_vport_get_stats(vport, &vport_stats);
if (nla_put(skb, OVS_VPORT_ATTR_STATS, sizeof(struct ovs_vport_stats),
&vport_stats))
goto nla_put_failure;
if (ovs_vport_get_upcall_portids(vport, skb))
goto nla_put_failure;
err = ovs_vport_get_options(vport, skb);
if (err == -EMSGSIZE)
goto error;
genlmsg_end(skb, ovs_header);
return 0;
nla_put_failure:
err = -EMSGSIZE;
error:
genlmsg_cancel(skb, ovs_header);
return err;
}
static struct sk_buff *ovs_vport_cmd_alloc_info(void)
{
return nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
}
struct sk_buff *ovs_vport_cmd_build_info(struct vport *vport, u32 portid,
u32 seq, u8 cmd)
{
struct sk_buff *skb;
int retval;
skb = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_ATOMIC);
if (!skb)
return ERR_PTR(-ENOMEM);
retval = ovs_vport_cmd_fill_info(vport, skb, portid, seq, 0, cmd);
BUG_ON(retval < 0);
return skb;
}
static struct vport *lookup_vport(struct net *net,
const struct ovs_header *ovs_header,
struct nlattr *a[OVS_VPORT_ATTR_MAX + 1])
{
struct datapath *dp;
struct vport *vport;
if (a[OVS_VPORT_ATTR_NAME]) {
vport = ovs_vport_locate(net, nla_data(a[OVS_VPORT_ATTR_NAME]));
if (!vport)
return ERR_PTR(-ENODEV);
if (ovs_header->dp_ifindex &&
ovs_header->dp_ifindex != get_dpifindex(vport->dp))
return ERR_PTR(-ENODEV);
return vport;
} else if (a[OVS_VPORT_ATTR_PORT_NO]) {
u32 port_no = nla_get_u32(a[OVS_VPORT_ATTR_PORT_NO]);
if (port_no >= DP_MAX_PORTS)
return ERR_PTR(-EFBIG);
dp = get_dp(net, ovs_header->dp_ifindex);
if (!dp)
return ERR_PTR(-ENODEV);
vport = ovs_vport_ovsl_rcu(dp, port_no);
if (!vport)
return ERR_PTR(-ENODEV);
return vport;
} else
return ERR_PTR(-EINVAL);
}
static int ovs_vport_cmd_new(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct ovs_header *ovs_header = info->userhdr;
struct vport_parms parms;
struct sk_buff *reply;
struct vport *vport;
struct datapath *dp;
u32 port_no;
int err;
if (!a[OVS_VPORT_ATTR_NAME] || !a[OVS_VPORT_ATTR_TYPE] ||
!a[OVS_VPORT_ATTR_UPCALL_PID])
return -EINVAL;
port_no = a[OVS_VPORT_ATTR_PORT_NO]
? nla_get_u32(a[OVS_VPORT_ATTR_PORT_NO]) : 0;
if (port_no >= DP_MAX_PORTS)
return -EFBIG;
reply = ovs_vport_cmd_alloc_info();
if (!reply)
return -ENOMEM;
ovs_lock();
restart:
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
err = -ENODEV;
if (!dp)
goto exit_unlock_free;
if (port_no) {
vport = ovs_vport_ovsl(dp, port_no);
err = -EBUSY;
if (vport)
goto exit_unlock_free;
} else {
for (port_no = 1; ; port_no++) {
if (port_no >= DP_MAX_PORTS) {
err = -EFBIG;
goto exit_unlock_free;
}
vport = ovs_vport_ovsl(dp, port_no);
if (!vport)
break;
}
}
parms.name = nla_data(a[OVS_VPORT_ATTR_NAME]);
parms.type = nla_get_u32(a[OVS_VPORT_ATTR_TYPE]);
parms.options = a[OVS_VPORT_ATTR_OPTIONS];
parms.dp = dp;
parms.port_no = port_no;
parms.upcall_portids = a[OVS_VPORT_ATTR_UPCALL_PID];
vport = new_vport(&parms);
err = PTR_ERR(vport);
if (IS_ERR(vport)) {
if (err == -EAGAIN)
goto restart;
goto exit_unlock_free;
}
err = ovs_vport_cmd_fill_info(vport, reply, info->snd_portid,
info->snd_seq, 0, OVS_VPORT_CMD_NEW);
BUG_ON(err < 0);
ovs_unlock();
ovs_notify(&dp_vport_genl_family, reply, info);
return 0;
exit_unlock_free:
ovs_unlock();
kfree_skb(reply);
return err;
}
static int ovs_vport_cmd_set(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct sk_buff *reply;
struct vport *vport;
int err;
reply = ovs_vport_cmd_alloc_info();
if (!reply)
return -ENOMEM;
ovs_lock();
vport = lookup_vport(sock_net(skb->sk), info->userhdr, a);
err = PTR_ERR(vport);
if (IS_ERR(vport))
goto exit_unlock_free;
if (a[OVS_VPORT_ATTR_TYPE] &&
nla_get_u32(a[OVS_VPORT_ATTR_TYPE]) != vport->ops->type) {
err = -EINVAL;
goto exit_unlock_free;
}
if (a[OVS_VPORT_ATTR_OPTIONS]) {
err = ovs_vport_set_options(vport, a[OVS_VPORT_ATTR_OPTIONS]);
if (err)
goto exit_unlock_free;
}
if (a[OVS_VPORT_ATTR_UPCALL_PID]) {
struct nlattr *ids = a[OVS_VPORT_ATTR_UPCALL_PID];
err = ovs_vport_set_upcall_portids(vport, ids);
if (err)
goto exit_unlock_free;
}
err = ovs_vport_cmd_fill_info(vport, reply, info->snd_portid,
info->snd_seq, 0, OVS_VPORT_CMD_NEW);
BUG_ON(err < 0);
ovs_unlock();
ovs_notify(&dp_vport_genl_family, reply, info);
return 0;
exit_unlock_free:
ovs_unlock();
kfree_skb(reply);
return err;
}
static int ovs_vport_cmd_del(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct sk_buff *reply;
struct vport *vport;
int err;
reply = ovs_vport_cmd_alloc_info();
if (!reply)
return -ENOMEM;
ovs_lock();
vport = lookup_vport(sock_net(skb->sk), info->userhdr, a);
err = PTR_ERR(vport);
if (IS_ERR(vport))
goto exit_unlock_free;
if (vport->port_no == OVSP_LOCAL) {
err = -EINVAL;
goto exit_unlock_free;
}
err = ovs_vport_cmd_fill_info(vport, reply, info->snd_portid,
info->snd_seq, 0, OVS_VPORT_CMD_DEL);
BUG_ON(err < 0);
ovs_dp_detach_port(vport);
ovs_unlock();
ovs_notify(&dp_vport_genl_family, reply, info);
return 0;
exit_unlock_free:
ovs_unlock();
kfree_skb(reply);
return err;
}
static int ovs_vport_cmd_get(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct ovs_header *ovs_header = info->userhdr;
struct sk_buff *reply;
struct vport *vport;
int err;
reply = ovs_vport_cmd_alloc_info();
if (!reply)
return -ENOMEM;
rcu_read_lock();
vport = lookup_vport(sock_net(skb->sk), ovs_header, a);
err = PTR_ERR(vport);
if (IS_ERR(vport))
goto exit_unlock_free;
err = ovs_vport_cmd_fill_info(vport, reply, info->snd_portid,
info->snd_seq, 0, OVS_VPORT_CMD_NEW);
BUG_ON(err < 0);
rcu_read_unlock();
return genlmsg_reply(reply, info);
exit_unlock_free:
rcu_read_unlock();
kfree_skb(reply);
return err;
}
static int ovs_vport_cmd_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct ovs_header *ovs_header = genlmsg_data(nlmsg_data(cb->nlh));
struct datapath *dp;
int bucket = cb->args[0], skip = cb->args[1];
int i, j = 0;
rcu_read_lock();
dp = get_dp_rcu(sock_net(skb->sk), ovs_header->dp_ifindex);
if (!dp) {
rcu_read_unlock();
return -ENODEV;
}
for (i = bucket; i < DP_VPORT_HASH_BUCKETS; i++) {
struct vport *vport;
j = 0;
hlist_for_each_entry_rcu(vport, &dp->ports[i], dp_hash_node) {
if (j >= skip &&
ovs_vport_cmd_fill_info(vport, skb,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
NLM_F_MULTI,
OVS_VPORT_CMD_NEW) < 0)
goto out;
j++;
}
skip = 0;
}
out:
rcu_read_unlock();
cb->args[0] = i;
cb->args[1] = j;
return skb->len;
}
static void dp_unregister_genl(int n_families)
{
int i;
for (i = 0; i < n_families; i++)
genl_unregister_family(dp_genl_families[i]);
}
static int dp_register_genl(void)
{
int err;
int i;
for (i = 0; i < ARRAY_SIZE(dp_genl_families); i++) {
err = genl_register_family(dp_genl_families[i]);
if (err)
goto error;
}
return 0;
error:
dp_unregister_genl(i);
return err;
}
static int __net_init ovs_init_net(struct net *net)
{
struct ovs_net *ovs_net = net_generic(net, ovs_net_id);
INIT_LIST_HEAD(&ovs_net->dps);
INIT_WORK(&ovs_net->dp_notify_work, ovs_dp_notify_wq);
return 0;
}
static void __net_exit list_vports_from_net(struct net *net, struct net *dnet,
struct list_head *head)
{
struct ovs_net *ovs_net = net_generic(net, ovs_net_id);
struct datapath *dp;
list_for_each_entry(dp, &ovs_net->dps, list_node) {
int i;
for (i = 0; i < DP_VPORT_HASH_BUCKETS; i++) {
struct vport *vport;
hlist_for_each_entry(vport, &dp->ports[i], dp_hash_node) {
struct netdev_vport *netdev_vport;
if (vport->ops->type != OVS_VPORT_TYPE_INTERNAL)
continue;
netdev_vport = netdev_vport_priv(vport);
if (dev_net(netdev_vport->dev) == dnet)
list_add(&vport->detach_list, head);
}
}
}
}
static void __net_exit ovs_exit_net(struct net *dnet)
{
struct datapath *dp, *dp_next;
struct ovs_net *ovs_net = net_generic(dnet, ovs_net_id);
struct vport *vport, *vport_next;
struct net *net;
LIST_HEAD(head);
ovs_lock();
list_for_each_entry_safe(dp, dp_next, &ovs_net->dps, list_node)
__dp_destroy(dp);
rtnl_lock();
for_each_net(net)
list_vports_from_net(net, dnet, &head);
rtnl_unlock();
list_for_each_entry_safe(vport, vport_next, &head, detach_list) {
list_del(&vport->detach_list);
ovs_dp_detach_port(vport);
}
ovs_unlock();
cancel_work_sync(&ovs_net->dp_notify_work);
}
static int __init dp_init(void)
{
int err;
BUILD_BUG_ON(sizeof(struct ovs_skb_cb) > FIELD_SIZEOF(struct sk_buff, cb));
pr_info("Open vSwitch switching datapath\n");
err = action_fifos_init();
if (err)
goto error;
err = ovs_internal_dev_rtnl_link_register();
if (err)
goto error_action_fifos_exit;
err = ovs_flow_init();
if (err)
goto error_unreg_rtnl_link;
err = ovs_vport_init();
if (err)
goto error_flow_exit;
err = register_pernet_device(&ovs_net_ops);
if (err)
goto error_vport_exit;
err = register_netdevice_notifier(&ovs_dp_device_notifier);
if (err)
goto error_netns_exit;
err = ovs_netdev_init();
if (err)
goto error_unreg_notifier;
err = dp_register_genl();
if (err < 0)
goto error_unreg_netdev;
return 0;
error_unreg_netdev:
ovs_netdev_exit();
error_unreg_notifier:
unregister_netdevice_notifier(&ovs_dp_device_notifier);
error_netns_exit:
unregister_pernet_device(&ovs_net_ops);
error_vport_exit:
ovs_vport_exit();
error_flow_exit:
ovs_flow_exit();
error_unreg_rtnl_link:
ovs_internal_dev_rtnl_link_unregister();
error_action_fifos_exit:
action_fifos_exit();
error:
return err;
}
static void dp_cleanup(void)
{
dp_unregister_genl(ARRAY_SIZE(dp_genl_families));
ovs_netdev_exit();
unregister_netdevice_notifier(&ovs_dp_device_notifier);
unregister_pernet_device(&ovs_net_ops);
rcu_barrier();
ovs_vport_exit();
ovs_flow_exit();
ovs_internal_dev_rtnl_link_unregister();
action_fifos_exit();
}
