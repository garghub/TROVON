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
static struct datapath *get_dp(struct net *net, int dp_ifindex)
{
struct datapath *dp = NULL;
struct net_device *dev;
rcu_read_lock();
dev = dev_get_by_index_rcu(net, dp_ifindex);
if (dev) {
struct vport *vport = ovs_internal_dev_get_vport(dev);
if (vport)
dp = vport->dp;
}
rcu_read_unlock();
return dp;
}
static const char *ovs_dp_name(const struct datapath *dp)
{
struct vport *vport = ovs_vport_ovsl_rcu(dp, OVSP_LOCAL);
return vport->ops->get_name(vport);
}
static int get_dpifindex(struct datapath *dp)
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
free_percpu(dp->stats_percpu);
release_net(ovs_dp_get_net(dp));
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
void ovs_dp_process_received_packet(struct vport *p, struct sk_buff *skb)
{
struct datapath *dp = p->dp;
struct sw_flow *flow;
struct dp_stats_percpu *stats;
struct sw_flow_key key;
u64 *stats_counter;
u32 n_mask_hit;
int error;
stats = this_cpu_ptr(dp->stats_percpu);
error = ovs_flow_extract(skb, p->port_no, &key);
if (unlikely(error)) {
kfree_skb(skb);
return;
}
flow = ovs_flow_tbl_lookup_stats(&dp->table, &key, &n_mask_hit);
if (unlikely(!flow)) {
struct dp_upcall_info upcall;
upcall.cmd = OVS_PACKET_CMD_MISS;
upcall.key = &key;
upcall.userdata = NULL;
upcall.portid = p->upcall_portid;
ovs_dp_upcall(dp, skb, &upcall);
consume_skb(skb);
stats_counter = &stats->n_missed;
goto out;
}
OVS_CB(skb)->flow = flow;
OVS_CB(skb)->pkt_key = &key;
ovs_flow_stats_update(OVS_CB(skb)->flow, skb);
ovs_execute_actions(dp, skb);
stats_counter = &stats->n_hit;
out:
u64_stats_update_begin(&stats->syncp);
(*stats_counter)++;
stats->n_mask_hit += n_mask_hit;
u64_stats_update_end(&stats->syncp);
}
int ovs_dp_upcall(struct datapath *dp, struct sk_buff *skb,
const struct dp_upcall_info *upcall_info)
{
struct dp_stats_percpu *stats;
int err;
if (upcall_info->portid == 0) {
err = -ENOTCONN;
goto err;
}
if (!skb_is_gso(skb))
err = queue_userspace_packet(dp, skb, upcall_info);
else
err = queue_gso_packets(dp, skb, upcall_info);
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
const struct dp_upcall_info *upcall_info)
{
unsigned short gso_type = skb_shinfo(skb)->gso_type;
struct dp_upcall_info later_info;
struct sw_flow_key later_key;
struct sk_buff *segs, *nskb;
int err;
segs = __skb_gso_segment(skb, NETIF_F_SG, false);
if (IS_ERR(segs))
return PTR_ERR(segs);
skb = segs;
do {
err = queue_userspace_packet(dp, skb, upcall_info);
if (err)
break;
if (skb == segs && gso_type & SKB_GSO_UDP) {
later_key = *upcall_info->key;
later_key.ip.frag = OVS_FRAG_TYPE_LATER;
later_info = *upcall_info;
later_info.key = &later_key;
upcall_info = &later_info;
}
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
static size_t key_attr_size(void)
{
return nla_total_size(4)
+ nla_total_size(0)
+ nla_total_size(8)
+ nla_total_size(4)
+ nla_total_size(4)
+ nla_total_size(1)
+ nla_total_size(1)
+ nla_total_size(0)
+ nla_total_size(0)
+ nla_total_size(4)
+ nla_total_size(4)
+ nla_total_size(12)
+ nla_total_size(2)
+ nla_total_size(4)
+ nla_total_size(0)
+ nla_total_size(2)
+ nla_total_size(40)
+ nla_total_size(2)
+ nla_total_size(28);
}
static size_t upcall_msg_size(const struct nlattr *userdata,
unsigned int hdrlen)
{
size_t size = NLMSG_ALIGN(sizeof(struct ovs_header))
+ nla_total_size(hdrlen)
+ nla_total_size(key_attr_size());
if (userdata)
size += NLA_ALIGN(userdata->nla_len);
return size;
}
static int queue_userspace_packet(struct datapath *dp, struct sk_buff *skb,
const struct dp_upcall_info *upcall_info)
{
struct ovs_header *upcall;
struct sk_buff *nskb = NULL;
struct sk_buff *user_skb;
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
if (vlan_tx_tag_present(skb)) {
nskb = skb_clone(skb, GFP_ATOMIC);
if (!nskb)
return -ENOMEM;
nskb = __vlan_put_tag(nskb, nskb->vlan_proto, vlan_tx_tag_get(nskb));
if (!nskb)
return -ENOMEM;
nskb->vlan_tci = 0;
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
len = upcall_msg_size(upcall_info->userdata, hlen);
user_skb = genlmsg_new_unicast(len, &info, GFP_ATOMIC);
if (!user_skb) {
err = -ENOMEM;
goto out;
}
upcall = genlmsg_put(user_skb, 0, 0, &dp_packet_genl_family,
0, upcall_info->cmd);
upcall->dp_ifindex = dp_ifindex;
nla = nla_nest_start(user_skb, OVS_PACKET_ATTR_KEY);
ovs_nla_put_flow(upcall_info->key, upcall_info->key, user_skb);
nla_nest_end(user_skb, nla);
if (upcall_info->userdata)
__nla_put(user_skb, OVS_PACKET_ATTR_USERDATA,
nla_len(upcall_info->userdata),
nla_data(upcall_info->userdata));
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
out:
if (err)
skb_tx_error(skb);
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
struct datapath *dp;
struct ethhdr *eth;
int len;
int err;
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
flow = ovs_flow_alloc(false);
err = PTR_ERR(flow);
if (IS_ERR(flow))
goto err_kfree_skb;
err = ovs_flow_extract(packet, -1, &flow->key);
if (err)
goto err_flow_free;
err = ovs_nla_get_flow_metadata(flow, a[OVS_PACKET_ATTR_KEY]);
if (err)
goto err_flow_free;
acts = ovs_nla_alloc_flow_actions(nla_len(a[OVS_PACKET_ATTR_ACTIONS]));
err = PTR_ERR(acts);
if (IS_ERR(acts))
goto err_flow_free;
err = ovs_nla_copy_actions(a[OVS_PACKET_ATTR_ACTIONS],
&flow->key, 0, &acts);
rcu_assign_pointer(flow->sf_acts, acts);
if (err)
goto err_flow_free;
OVS_CB(packet)->flow = flow;
OVS_CB(packet)->pkt_key = &flow->key;
packet->priority = flow->key.phy.priority;
packet->mark = flow->key.phy.skb_mark;
rcu_read_lock();
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
err = -ENODEV;
if (!dp)
goto err_unlock;
local_bh_disable();
err = ovs_execute_actions(dp, packet);
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
static void get_dp_stats(struct datapath *dp, struct ovs_dp_stats *stats,
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
static size_t ovs_flow_cmd_msg_size(const struct sw_flow_actions *acts)
{
return NLMSG_ALIGN(sizeof(struct ovs_header))
+ nla_total_size(key_attr_size())
+ nla_total_size(key_attr_size())
+ nla_total_size(sizeof(struct ovs_flow_stats))
+ nla_total_size(1)
+ nla_total_size(8)
+ nla_total_size(acts->actions_len);
}
static int ovs_flow_cmd_fill_info(struct sw_flow *flow, struct datapath *dp,
struct sk_buff *skb, u32 portid,
u32 seq, u32 flags, u8 cmd)
{
const int skb_orig_len = skb->len;
struct nlattr *start;
struct ovs_flow_stats stats;
__be16 tcp_flags;
unsigned long used;
struct ovs_header *ovs_header;
struct nlattr *nla;
int err;
ovs_header = genlmsg_put(skb, portid, seq, &dp_flow_genl_family, flags, cmd);
if (!ovs_header)
return -EMSGSIZE;
ovs_header->dp_ifindex = get_dpifindex(dp);
nla = nla_nest_start(skb, OVS_FLOW_ATTR_KEY);
if (!nla)
goto nla_put_failure;
err = ovs_nla_put_flow(&flow->unmasked_key, &flow->unmasked_key, skb);
if (err)
goto error;
nla_nest_end(skb, nla);
nla = nla_nest_start(skb, OVS_FLOW_ATTR_MASK);
if (!nla)
goto nla_put_failure;
err = ovs_nla_put_flow(&flow->key, &flow->mask->key, skb);
if (err)
goto error;
nla_nest_end(skb, nla);
ovs_flow_stats_get(flow, &stats, &used, &tcp_flags);
if (used &&
nla_put_u64(skb, OVS_FLOW_ATTR_USED, ovs_flow_used_time(used)))
goto nla_put_failure;
if (stats.n_packets &&
nla_put(skb, OVS_FLOW_ATTR_STATS, sizeof(struct ovs_flow_stats), &stats))
goto nla_put_failure;
if ((u8)ntohs(tcp_flags) &&
nla_put_u8(skb, OVS_FLOW_ATTR_TCP_FLAGS, (u8)ntohs(tcp_flags)))
goto nla_put_failure;
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
goto error;
nla_nest_cancel(skb, start);
}
} else if (skb_orig_len)
goto nla_put_failure;
return genlmsg_end(skb, ovs_header);
nla_put_failure:
err = -EMSGSIZE;
error:
genlmsg_cancel(skb, ovs_header);
return err;
}
static struct sk_buff *ovs_flow_cmd_alloc_info(struct sw_flow *flow,
struct genl_info *info)
{
size_t len;
len = ovs_flow_cmd_msg_size(ovsl_dereference(flow->sf_acts));
return genlmsg_new_unicast(len, info, GFP_KERNEL);
}
static struct sk_buff *ovs_flow_cmd_build_info(struct sw_flow *flow,
struct datapath *dp,
struct genl_info *info,
u8 cmd)
{
struct sk_buff *skb;
int retval;
skb = ovs_flow_cmd_alloc_info(flow, info);
if (!skb)
return ERR_PTR(-ENOMEM);
retval = ovs_flow_cmd_fill_info(flow, dp, skb, info->snd_portid,
info->snd_seq, 0, cmd);
BUG_ON(retval < 0);
return skb;
}
static int ovs_flow_cmd_new_or_set(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct ovs_header *ovs_header = info->userhdr;
struct sw_flow_key key, masked_key;
struct sw_flow *flow = NULL;
struct sw_flow_mask mask;
struct sk_buff *reply;
struct datapath *dp;
struct sw_flow_actions *acts = NULL;
struct sw_flow_match match;
bool exact_5tuple;
int error;
error = -EINVAL;
if (!a[OVS_FLOW_ATTR_KEY])
goto error;
ovs_match_init(&match, &key, &mask);
error = ovs_nla_get_match(&match, &exact_5tuple,
a[OVS_FLOW_ATTR_KEY], a[OVS_FLOW_ATTR_MASK]);
if (error)
goto error;
if (a[OVS_FLOW_ATTR_ACTIONS]) {
acts = ovs_nla_alloc_flow_actions(nla_len(a[OVS_FLOW_ATTR_ACTIONS]));
error = PTR_ERR(acts);
if (IS_ERR(acts))
goto error;
ovs_flow_mask_key(&masked_key, &key, &mask);
error = ovs_nla_copy_actions(a[OVS_FLOW_ATTR_ACTIONS],
&masked_key, 0, &acts);
if (error) {
OVS_NLERR("Flow actions may not be safe on all matching packets.\n");
goto err_kfree;
}
} else if (info->genlhdr->cmd == OVS_FLOW_CMD_NEW) {
error = -EINVAL;
goto error;
}
ovs_lock();
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
error = -ENODEV;
if (!dp)
goto err_unlock_ovs;
flow = ovs_flow_tbl_lookup(&dp->table, &key);
if (!flow) {
error = -ENOENT;
if (info->genlhdr->cmd == OVS_FLOW_CMD_SET)
goto err_unlock_ovs;
flow = ovs_flow_alloc(!exact_5tuple);
if (IS_ERR(flow)) {
error = PTR_ERR(flow);
goto err_unlock_ovs;
}
flow->key = masked_key;
flow->unmasked_key = key;
rcu_assign_pointer(flow->sf_acts, acts);
error = ovs_flow_tbl_insert(&dp->table, flow, &mask);
if (error) {
acts = NULL;
goto err_flow_free;
}
reply = ovs_flow_cmd_build_info(flow, dp, info, OVS_FLOW_CMD_NEW);
} else {
struct sw_flow_actions *old_acts;
error = -EEXIST;
if (info->genlhdr->cmd == OVS_FLOW_CMD_NEW &&
info->nlhdr->nlmsg_flags & (NLM_F_CREATE | NLM_F_EXCL))
goto err_unlock_ovs;
if (!ovs_flow_cmp_unmasked_key(flow, &match))
goto err_unlock_ovs;
old_acts = ovsl_dereference(flow->sf_acts);
rcu_assign_pointer(flow->sf_acts, acts);
ovs_nla_free_flow_actions(old_acts);
reply = ovs_flow_cmd_build_info(flow, dp, info, OVS_FLOW_CMD_NEW);
if (a[OVS_FLOW_ATTR_CLEAR])
ovs_flow_stats_clear(flow);
}
ovs_unlock();
if (!IS_ERR(reply))
ovs_notify(&dp_flow_genl_family, reply, info);
else
genl_set_err(&dp_flow_genl_family, sock_net(skb->sk), 0,
0, PTR_ERR(reply));
return 0;
err_flow_free:
ovs_flow_free(flow, false);
err_unlock_ovs:
ovs_unlock();
err_kfree:
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
int err;
if (!a[OVS_FLOW_ATTR_KEY]) {
OVS_NLERR("Flow get message rejected, Key attribute missing.\n");
return -EINVAL;
}
ovs_match_init(&match, &key, NULL);
err = ovs_nla_get_match(&match, NULL, a[OVS_FLOW_ATTR_KEY], NULL);
if (err)
return err;
ovs_lock();
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
if (!dp) {
err = -ENODEV;
goto unlock;
}
flow = ovs_flow_tbl_lookup(&dp->table, &key);
if (!flow || !ovs_flow_cmp_unmasked_key(flow, &match)) {
err = -ENOENT;
goto unlock;
}
reply = ovs_flow_cmd_build_info(flow, dp, info, OVS_FLOW_CMD_NEW);
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
struct sw_flow *flow;
struct datapath *dp;
struct sw_flow_match match;
int err;
ovs_lock();
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
if (!dp) {
err = -ENODEV;
goto unlock;
}
if (!a[OVS_FLOW_ATTR_KEY]) {
err = ovs_flow_tbl_flush(&dp->table);
goto unlock;
}
ovs_match_init(&match, &key, NULL);
err = ovs_nla_get_match(&match, NULL, a[OVS_FLOW_ATTR_KEY], NULL);
if (err)
goto unlock;
flow = ovs_flow_tbl_lookup(&dp->table, &key);
if (!flow || !ovs_flow_cmp_unmasked_key(flow, &match)) {
err = -ENOENT;
goto unlock;
}
reply = ovs_flow_cmd_alloc_info(flow, info);
if (!reply) {
err = -ENOMEM;
goto unlock;
}
ovs_flow_tbl_remove(&dp->table, flow);
err = ovs_flow_cmd_fill_info(flow, dp, reply, info->snd_portid,
info->snd_seq, 0, OVS_FLOW_CMD_DEL);
BUG_ON(err < 0);
ovs_flow_free(flow, true);
ovs_unlock();
ovs_notify(&dp_flow_genl_family, reply, info);
return 0;
unlock:
ovs_unlock();
return err;
}
static int ovs_flow_cmd_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct ovs_header *ovs_header = genlmsg_data(nlmsg_data(cb->nlh));
struct table_instance *ti;
struct datapath *dp;
rcu_read_lock();
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
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
if (ovs_flow_cmd_fill_info(flow, dp, skb,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, NLM_F_MULTI,
OVS_FLOW_CMD_NEW) < 0)
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
rcu_read_lock();
err = nla_put_string(skb, OVS_DP_ATTR_NAME, ovs_dp_name(dp));
rcu_read_unlock();
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
return genlmsg_end(skb, ovs_header);
nla_put_failure:
genlmsg_cancel(skb, ovs_header);
error:
return -EMSGSIZE;
}
static struct sk_buff *ovs_dp_cmd_build_info(struct datapath *dp,
struct genl_info *info, u8 cmd)
{
struct sk_buff *skb;
int retval;
skb = genlmsg_new_unicast(ovs_dp_cmd_msg_size(), info, GFP_KERNEL);
if (!skb)
return ERR_PTR(-ENOMEM);
retval = ovs_dp_cmd_fill_info(dp, skb, info->snd_portid, info->snd_seq, 0, cmd);
if (retval < 0) {
kfree_skb(skb);
return ERR_PTR(retval);
}
return skb;
}
static struct datapath *lookup_datapath(struct net *net,
struct ovs_header *ovs_header,
struct nlattr *a[OVS_DP_ATTR_MAX + 1])
{
struct datapath *dp;
if (!a[OVS_DP_ATTR_NAME])
dp = get_dp(net, ovs_header->dp_ifindex);
else {
struct vport *vport;
rcu_read_lock();
vport = ovs_vport_locate(net, nla_data(a[OVS_DP_ATTR_NAME]));
dp = vport && vport->port_no == OVSP_LOCAL ? vport->dp : NULL;
rcu_read_unlock();
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
static void ovs_dp_change(struct datapath *dp, struct nlattr **a)
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
ovs_lock();
err = -ENOMEM;
dp = kzalloc(sizeof(*dp), GFP_KERNEL);
if (dp == NULL)
goto err_unlock_ovs;
ovs_dp_set_net(dp, hold_net(sock_net(skb->sk)));
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
parms.upcall_portid = nla_get_u32(a[OVS_DP_ATTR_UPCALL_PID]);
ovs_dp_change(dp, a);
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
reply = ovs_dp_cmd_build_info(dp, info, OVS_DP_CMD_NEW);
err = PTR_ERR(reply);
if (IS_ERR(reply))
goto err_destroy_local_port;
ovs_net = net_generic(ovs_dp_get_net(dp), ovs_net_id);
list_add_tail_rcu(&dp->list_node, &ovs_net->dps);
ovs_unlock();
ovs_notify(&dp_datapath_genl_family, reply, info);
return 0;
err_destroy_local_port:
ovs_dp_detach_port(ovs_vport_ovsl(dp, OVSP_LOCAL));
err_destroy_ports_array:
kfree(dp->ports);
err_destroy_percpu:
free_percpu(dp->stats_percpu);
err_destroy_table:
ovs_flow_tbl_destroy(&dp->table, false);
err_free_dp:
release_net(ovs_dp_get_net(dp));
kfree(dp);
err_unlock_ovs:
ovs_unlock();
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
ovs_flow_tbl_destroy(&dp->table, true);
call_rcu(&dp->rcu, destroy_dp_rcu);
}
static int ovs_dp_cmd_del(struct sk_buff *skb, struct genl_info *info)
{
struct sk_buff *reply;
struct datapath *dp;
int err;
ovs_lock();
dp = lookup_datapath(sock_net(skb->sk), info->userhdr, info->attrs);
err = PTR_ERR(dp);
if (IS_ERR(dp))
goto unlock;
reply = ovs_dp_cmd_build_info(dp, info, OVS_DP_CMD_DEL);
err = PTR_ERR(reply);
if (IS_ERR(reply))
goto unlock;
__dp_destroy(dp);
ovs_unlock();
ovs_notify(&dp_datapath_genl_family, reply, info);
return 0;
unlock:
ovs_unlock();
return err;
}
static int ovs_dp_cmd_set(struct sk_buff *skb, struct genl_info *info)
{
struct sk_buff *reply;
struct datapath *dp;
int err;
ovs_lock();
dp = lookup_datapath(sock_net(skb->sk), info->userhdr, info->attrs);
err = PTR_ERR(dp);
if (IS_ERR(dp))
goto unlock;
ovs_dp_change(dp, info->attrs);
reply = ovs_dp_cmd_build_info(dp, info, OVS_DP_CMD_NEW);
if (IS_ERR(reply)) {
err = PTR_ERR(reply);
genl_set_err(&dp_datapath_genl_family, sock_net(skb->sk), 0,
0, err);
err = 0;
goto unlock;
}
ovs_unlock();
ovs_notify(&dp_datapath_genl_family, reply, info);
return 0;
unlock:
ovs_unlock();
return err;
}
static int ovs_dp_cmd_get(struct sk_buff *skb, struct genl_info *info)
{
struct sk_buff *reply;
struct datapath *dp;
int err;
ovs_lock();
dp = lookup_datapath(sock_net(skb->sk), info->userhdr, info->attrs);
if (IS_ERR(dp)) {
err = PTR_ERR(dp);
goto unlock;
}
reply = ovs_dp_cmd_build_info(dp, info, OVS_DP_CMD_NEW);
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
static int ovs_dp_cmd_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct ovs_net *ovs_net = net_generic(sock_net(skb->sk), ovs_net_id);
struct datapath *dp;
int skip = cb->args[0];
int i = 0;
rcu_read_lock();
list_for_each_entry_rcu(dp, &ovs_net->dps, list_node) {
if (i >= skip &&
ovs_dp_cmd_fill_info(dp, skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, NLM_F_MULTI,
OVS_DP_CMD_NEW) < 0)
break;
i++;
}
rcu_read_unlock();
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
nla_put_string(skb, OVS_VPORT_ATTR_NAME, vport->ops->get_name(vport)) ||
nla_put_u32(skb, OVS_VPORT_ATTR_UPCALL_PID, vport->upcall_portid))
goto nla_put_failure;
ovs_vport_get_stats(vport, &vport_stats);
if (nla_put(skb, OVS_VPORT_ATTR_STATS, sizeof(struct ovs_vport_stats),
&vport_stats))
goto nla_put_failure;
err = ovs_vport_get_options(vport, skb);
if (err == -EMSGSIZE)
goto error;
return genlmsg_end(skb, ovs_header);
nla_put_failure:
err = -EMSGSIZE;
error:
genlmsg_cancel(skb, ovs_header);
return err;
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
struct ovs_header *ovs_header,
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
err = -EINVAL;
if (!a[OVS_VPORT_ATTR_NAME] || !a[OVS_VPORT_ATTR_TYPE] ||
!a[OVS_VPORT_ATTR_UPCALL_PID])
goto exit;
ovs_lock();
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
err = -ENODEV;
if (!dp)
goto exit_unlock;
if (a[OVS_VPORT_ATTR_PORT_NO]) {
port_no = nla_get_u32(a[OVS_VPORT_ATTR_PORT_NO]);
err = -EFBIG;
if (port_no >= DP_MAX_PORTS)
goto exit_unlock;
vport = ovs_vport_ovsl(dp, port_no);
err = -EBUSY;
if (vport)
goto exit_unlock;
} else {
for (port_no = 1; ; port_no++) {
if (port_no >= DP_MAX_PORTS) {
err = -EFBIG;
goto exit_unlock;
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
parms.upcall_portid = nla_get_u32(a[OVS_VPORT_ATTR_UPCALL_PID]);
vport = new_vport(&parms);
err = PTR_ERR(vport);
if (IS_ERR(vport))
goto exit_unlock;
err = 0;
reply = ovs_vport_cmd_build_info(vport, info->snd_portid, info->snd_seq,
OVS_VPORT_CMD_NEW);
if (IS_ERR(reply)) {
err = PTR_ERR(reply);
ovs_dp_detach_port(vport);
goto exit_unlock;
}
ovs_notify(&dp_vport_genl_family, reply, info);
exit_unlock:
ovs_unlock();
exit:
return err;
}
static int ovs_vport_cmd_set(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct sk_buff *reply;
struct vport *vport;
int err;
ovs_lock();
vport = lookup_vport(sock_net(skb->sk), info->userhdr, a);
err = PTR_ERR(vport);
if (IS_ERR(vport))
goto exit_unlock;
if (a[OVS_VPORT_ATTR_TYPE] &&
nla_get_u32(a[OVS_VPORT_ATTR_TYPE]) != vport->ops->type) {
err = -EINVAL;
goto exit_unlock;
}
reply = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!reply) {
err = -ENOMEM;
goto exit_unlock;
}
if (a[OVS_VPORT_ATTR_OPTIONS]) {
err = ovs_vport_set_options(vport, a[OVS_VPORT_ATTR_OPTIONS]);
if (err)
goto exit_free;
}
if (a[OVS_VPORT_ATTR_UPCALL_PID])
vport->upcall_portid = nla_get_u32(a[OVS_VPORT_ATTR_UPCALL_PID]);
err = ovs_vport_cmd_fill_info(vport, reply, info->snd_portid,
info->snd_seq, 0, OVS_VPORT_CMD_NEW);
BUG_ON(err < 0);
ovs_unlock();
ovs_notify(&dp_vport_genl_family, reply, info);
return 0;
exit_free:
kfree_skb(reply);
exit_unlock:
ovs_unlock();
return err;
}
static int ovs_vport_cmd_del(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct sk_buff *reply;
struct vport *vport;
int err;
ovs_lock();
vport = lookup_vport(sock_net(skb->sk), info->userhdr, a);
err = PTR_ERR(vport);
if (IS_ERR(vport))
goto exit_unlock;
if (vport->port_no == OVSP_LOCAL) {
err = -EINVAL;
goto exit_unlock;
}
reply = ovs_vport_cmd_build_info(vport, info->snd_portid,
info->snd_seq, OVS_VPORT_CMD_DEL);
err = PTR_ERR(reply);
if (IS_ERR(reply))
goto exit_unlock;
err = 0;
ovs_dp_detach_port(vport);
ovs_notify(&dp_vport_genl_family, reply, info);
exit_unlock:
ovs_unlock();
return err;
}
static int ovs_vport_cmd_get(struct sk_buff *skb, struct genl_info *info)
{
struct nlattr **a = info->attrs;
struct ovs_header *ovs_header = info->userhdr;
struct sk_buff *reply;
struct vport *vport;
int err;
rcu_read_lock();
vport = lookup_vport(sock_net(skb->sk), ovs_header, a);
err = PTR_ERR(vport);
if (IS_ERR(vport))
goto exit_unlock;
reply = ovs_vport_cmd_build_info(vport, info->snd_portid,
info->snd_seq, OVS_VPORT_CMD_NEW);
err = PTR_ERR(reply);
if (IS_ERR(reply))
goto exit_unlock;
rcu_read_unlock();
return genlmsg_reply(reply, info);
exit_unlock:
rcu_read_unlock();
return err;
}
static int ovs_vport_cmd_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct ovs_header *ovs_header = genlmsg_data(nlmsg_data(cb->nlh));
struct datapath *dp;
int bucket = cb->args[0], skip = cb->args[1];
int i, j = 0;
rcu_read_lock();
dp = get_dp(sock_net(skb->sk), ovs_header->dp_ifindex);
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
genl_unregister_family(dp_genl_families[i].family);
}
static int dp_register_genl(void)
{
int n_registered;
int err;
int i;
n_registered = 0;
for (i = 0; i < ARRAY_SIZE(dp_genl_families); i++) {
const struct genl_family_and_ops *f = &dp_genl_families[i];
f->family->ops = f->ops;
f->family->n_ops = f->n_ops;
f->family->mcgrps = f->group;
f->family->n_mcgrps = f->group ? 1 : 0;
err = genl_register_family(f->family);
if (err)
goto error;
n_registered++;
}
return 0;
error:
dp_unregister_genl(n_registered);
return err;
}
static int __net_init ovs_init_net(struct net *net)
{
struct ovs_net *ovs_net = net_generic(net, ovs_net_id);
INIT_LIST_HEAD(&ovs_net->dps);
INIT_WORK(&ovs_net->dp_notify_work, ovs_dp_notify_wq);
return 0;
}
static void __net_exit ovs_exit_net(struct net *net)
{
struct datapath *dp, *dp_next;
struct ovs_net *ovs_net = net_generic(net, ovs_net_id);
ovs_lock();
list_for_each_entry_safe(dp, dp_next, &ovs_net->dps, list_node)
__dp_destroy(dp);
ovs_unlock();
cancel_work_sync(&ovs_net->dp_notify_work);
}
static int __init dp_init(void)
{
int err;
BUILD_BUG_ON(sizeof(struct ovs_skb_cb) > FIELD_SIZEOF(struct sk_buff, cb));
pr_info("Open vSwitch switching datapath\n");
err = ovs_flow_init();
if (err)
goto error;
err = ovs_vport_init();
if (err)
goto error_flow_exit;
err = register_pernet_device(&ovs_net_ops);
if (err)
goto error_vport_exit;
err = register_netdevice_notifier(&ovs_dp_device_notifier);
if (err)
goto error_netns_exit;
err = dp_register_genl();
if (err < 0)
goto error_unreg_notifier;
return 0;
error_unreg_notifier:
unregister_netdevice_notifier(&ovs_dp_device_notifier);
error_netns_exit:
unregister_pernet_device(&ovs_net_ops);
error_vport_exit:
ovs_vport_exit();
error_flow_exit:
ovs_flow_exit();
error:
return err;
}
static void dp_cleanup(void)
{
dp_unregister_genl(ARRAY_SIZE(dp_genl_families));
unregister_netdevice_notifier(&ovs_dp_device_notifier);
unregister_pernet_device(&ovs_net_ops);
rcu_barrier();
ovs_vport_exit();
ovs_flow_exit();
}
