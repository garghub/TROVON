static struct mlx5_flow_handle *
mlx5e_tc_add_nic_flow(struct mlx5e_priv *priv,
struct mlx5e_tc_flow_parse_attr *parse_attr,
struct mlx5e_tc_flow *flow)
{
struct mlx5_nic_flow_attr *attr = flow->nic_attr;
struct mlx5_core_dev *dev = priv->mdev;
struct mlx5_flow_destination dest = {};
struct mlx5_flow_act flow_act = {
.action = attr->action,
.flow_tag = attr->flow_tag,
.encap_id = 0,
};
struct mlx5_fc *counter = NULL;
struct mlx5_flow_handle *rule;
bool table_created = false;
int err;
if (attr->action & MLX5_FLOW_CONTEXT_ACTION_FWD_DEST) {
dest.type = MLX5_FLOW_DESTINATION_TYPE_FLOW_TABLE;
dest.ft = priv->fs.vlan.ft.t;
} else if (attr->action & MLX5_FLOW_CONTEXT_ACTION_COUNT) {
counter = mlx5_fc_create(dev, true);
if (IS_ERR(counter))
return ERR_CAST(counter);
dest.type = MLX5_FLOW_DESTINATION_TYPE_COUNTER;
dest.counter = counter;
}
if (attr->action & MLX5_FLOW_CONTEXT_ACTION_MOD_HDR) {
err = mlx5_modify_header_alloc(dev, MLX5_FLOW_NAMESPACE_KERNEL,
parse_attr->num_mod_hdr_actions,
parse_attr->mod_hdr_actions,
&attr->mod_hdr_id);
flow_act.modify_id = attr->mod_hdr_id;
kfree(parse_attr->mod_hdr_actions);
if (err) {
rule = ERR_PTR(err);
goto err_create_mod_hdr_id;
}
}
if (IS_ERR_OR_NULL(priv->fs.tc.t)) {
priv->fs.tc.t =
mlx5_create_auto_grouped_flow_table(priv->fs.ns,
MLX5E_TC_PRIO,
MLX5E_TC_TABLE_NUM_ENTRIES,
MLX5E_TC_TABLE_NUM_GROUPS,
0, 0);
if (IS_ERR(priv->fs.tc.t)) {
netdev_err(priv->netdev,
"Failed to create tc offload table\n");
rule = ERR_CAST(priv->fs.tc.t);
goto err_create_ft;
}
table_created = true;
}
parse_attr->spec.match_criteria_enable = MLX5_MATCH_OUTER_HEADERS;
rule = mlx5_add_flow_rules(priv->fs.tc.t, &parse_attr->spec,
&flow_act, &dest, 1);
if (IS_ERR(rule))
goto err_add_rule;
return rule;
err_add_rule:
if (table_created) {
mlx5_destroy_flow_table(priv->fs.tc.t);
priv->fs.tc.t = NULL;
}
err_create_ft:
if (attr->action & MLX5_FLOW_CONTEXT_ACTION_MOD_HDR)
mlx5_modify_header_dealloc(priv->mdev,
attr->mod_hdr_id);
err_create_mod_hdr_id:
mlx5_fc_destroy(dev, counter);
return rule;
}
static void mlx5e_tc_del_nic_flow(struct mlx5e_priv *priv,
struct mlx5e_tc_flow *flow)
{
struct mlx5_fc *counter = NULL;
counter = mlx5_flow_rule_counter(flow->rule);
mlx5_del_flow_rules(flow->rule);
mlx5_fc_destroy(priv->mdev, counter);
if (!mlx5e_tc_num_filters(priv) && (priv->fs.tc.t)) {
mlx5_destroy_flow_table(priv->fs.tc.t);
priv->fs.tc.t = NULL;
}
if (flow->nic_attr->action & MLX5_FLOW_CONTEXT_ACTION_MOD_HDR)
mlx5_modify_header_dealloc(priv->mdev,
flow->nic_attr->mod_hdr_id);
}
static struct mlx5_flow_handle *
mlx5e_tc_add_fdb_flow(struct mlx5e_priv *priv,
struct mlx5e_tc_flow_parse_attr *parse_attr,
struct mlx5e_tc_flow *flow)
{
struct mlx5_eswitch *esw = priv->mdev->priv.eswitch;
struct mlx5_esw_flow_attr *attr = flow->esw_attr;
struct mlx5_flow_handle *rule;
int err;
err = mlx5_eswitch_add_vlan_action(esw, attr);
if (err) {
rule = ERR_PTR(err);
goto err_add_vlan;
}
if (attr->action & MLX5_FLOW_CONTEXT_ACTION_MOD_HDR) {
err = mlx5_modify_header_alloc(priv->mdev, MLX5_FLOW_NAMESPACE_FDB,
parse_attr->num_mod_hdr_actions,
parse_attr->mod_hdr_actions,
&attr->mod_hdr_id);
kfree(parse_attr->mod_hdr_actions);
if (err) {
rule = ERR_PTR(err);
goto err_mod_hdr;
}
}
rule = mlx5_eswitch_add_offloaded_rule(esw, &parse_attr->spec, attr);
if (IS_ERR(rule))
goto err_add_rule;
return rule;
err_add_rule:
if (flow->esw_attr->action & MLX5_FLOW_CONTEXT_ACTION_MOD_HDR)
mlx5_modify_header_dealloc(priv->mdev,
attr->mod_hdr_id);
err_mod_hdr:
mlx5_eswitch_del_vlan_action(esw, attr);
err_add_vlan:
if (attr->action & MLX5_FLOW_CONTEXT_ACTION_ENCAP)
mlx5e_detach_encap(priv, flow);
return rule;
}
static void mlx5e_tc_del_fdb_flow(struct mlx5e_priv *priv,
struct mlx5e_tc_flow *flow)
{
struct mlx5_eswitch *esw = priv->mdev->priv.eswitch;
struct mlx5_esw_flow_attr *attr = flow->esw_attr;
if (flow->flags & MLX5E_TC_FLOW_OFFLOADED) {
flow->flags &= ~MLX5E_TC_FLOW_OFFLOADED;
mlx5_eswitch_del_offloaded_rule(esw, flow->rule, flow->esw_attr);
}
mlx5_eswitch_del_vlan_action(esw, flow->esw_attr);
if (flow->esw_attr->action & MLX5_FLOW_CONTEXT_ACTION_ENCAP) {
mlx5e_detach_encap(priv, flow);
kvfree(flow->esw_attr->parse_attr);
}
if (flow->esw_attr->action & MLX5_FLOW_CONTEXT_ACTION_MOD_HDR)
mlx5_modify_header_dealloc(priv->mdev,
attr->mod_hdr_id);
}
void mlx5e_tc_encap_flows_add(struct mlx5e_priv *priv,
struct mlx5e_encap_entry *e)
{
struct mlx5e_tc_flow *flow;
int err;
err = mlx5_encap_alloc(priv->mdev, e->tunnel_type,
e->encap_size, e->encap_header,
&e->encap_id);
if (err) {
mlx5_core_warn(priv->mdev, "Failed to offload cached encapsulation header, %d\n",
err);
return;
}
e->flags |= MLX5_ENCAP_ENTRY_VALID;
mlx5e_rep_queue_neigh_stats_work(priv);
list_for_each_entry(flow, &e->flows, encap) {
flow->esw_attr->encap_id = e->encap_id;
flow->rule = mlx5e_tc_add_fdb_flow(priv,
flow->esw_attr->parse_attr,
flow);
if (IS_ERR(flow->rule)) {
err = PTR_ERR(flow->rule);
mlx5_core_warn(priv->mdev, "Failed to update cached encapsulation flow, %d\n",
err);
continue;
}
flow->flags |= MLX5E_TC_FLOW_OFFLOADED;
}
}
void mlx5e_tc_encap_flows_del(struct mlx5e_priv *priv,
struct mlx5e_encap_entry *e)
{
struct mlx5e_tc_flow *flow;
struct mlx5_fc *counter;
list_for_each_entry(flow, &e->flows, encap) {
if (flow->flags & MLX5E_TC_FLOW_OFFLOADED) {
flow->flags &= ~MLX5E_TC_FLOW_OFFLOADED;
counter = mlx5_flow_rule_counter(flow->rule);
mlx5_del_flow_rules(flow->rule);
mlx5_fc_destroy(priv->mdev, counter);
}
}
if (e->flags & MLX5_ENCAP_ENTRY_VALID) {
e->flags &= ~MLX5_ENCAP_ENTRY_VALID;
mlx5_encap_dealloc(priv->mdev, e->encap_id);
}
}
void mlx5e_tc_update_neigh_used_value(struct mlx5e_neigh_hash_entry *nhe)
{
struct mlx5e_neigh *m_neigh = &nhe->m_neigh;
u64 bytes, packets, lastuse = 0;
struct mlx5e_tc_flow *flow;
struct mlx5e_encap_entry *e;
struct mlx5_fc *counter;
struct neigh_table *tbl;
bool neigh_used = false;
struct neighbour *n;
if (m_neigh->family == AF_INET)
tbl = &arp_tbl;
#if IS_ENABLED(CONFIG_IPV6)
else if (m_neigh->family == AF_INET6)
tbl = ipv6_stub->nd_tbl;
#endif
else
return;
list_for_each_entry(e, &nhe->encap_list, encap_list) {
if (!(e->flags & MLX5_ENCAP_ENTRY_VALID))
continue;
list_for_each_entry(flow, &e->flows, encap) {
if (flow->flags & MLX5E_TC_FLOW_OFFLOADED) {
counter = mlx5_flow_rule_counter(flow->rule);
mlx5_fc_query_cached(counter, &bytes, &packets, &lastuse);
if (time_after((unsigned long)lastuse, nhe->reported_lastuse)) {
neigh_used = true;
break;
}
}
}
}
if (neigh_used) {
nhe->reported_lastuse = jiffies;
n = neigh_lookup(tbl, &m_neigh->dst_ip, m_neigh->dev);
if (!n) {
WARN(1, "The neighbour already freed\n");
return;
}
neigh_event_send(n, NULL);
neigh_release(n);
}
}
static void mlx5e_detach_encap(struct mlx5e_priv *priv,
struct mlx5e_tc_flow *flow)
{
struct list_head *next = flow->encap.next;
list_del(&flow->encap);
if (list_empty(next)) {
struct mlx5e_encap_entry *e;
e = list_entry(next, struct mlx5e_encap_entry, flows);
mlx5e_rep_encap_entry_detach(netdev_priv(e->out_dev), e);
if (e->flags & MLX5_ENCAP_ENTRY_VALID)
mlx5_encap_dealloc(priv->mdev, e->encap_id);
hash_del_rcu(&e->encap_hlist);
kfree(e->encap_header);
kfree(e);
}
}
static void mlx5e_tc_del_flow(struct mlx5e_priv *priv,
struct mlx5e_tc_flow *flow)
{
if (flow->flags & MLX5E_TC_FLOW_ESWITCH)
mlx5e_tc_del_fdb_flow(priv, flow);
else
mlx5e_tc_del_nic_flow(priv, flow);
}
static void parse_vxlan_attr(struct mlx5_flow_spec *spec,
struct tc_cls_flower_offload *f)
{
void *headers_c = MLX5_ADDR_OF(fte_match_param, spec->match_criteria,
outer_headers);
void *headers_v = MLX5_ADDR_OF(fte_match_param, spec->match_value,
outer_headers);
void *misc_c = MLX5_ADDR_OF(fte_match_param, spec->match_criteria,
misc_parameters);
void *misc_v = MLX5_ADDR_OF(fte_match_param, spec->match_value,
misc_parameters);
MLX5_SET_TO_ONES(fte_match_set_lyr_2_4, headers_c, ip_protocol);
MLX5_SET(fte_match_set_lyr_2_4, headers_v, ip_protocol, IPPROTO_UDP);
if (dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_ENC_KEYID)) {
struct flow_dissector_key_keyid *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ENC_KEYID,
f->key);
struct flow_dissector_key_keyid *mask =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ENC_KEYID,
f->mask);
MLX5_SET(fte_match_set_misc, misc_c, vxlan_vni,
be32_to_cpu(mask->keyid));
MLX5_SET(fte_match_set_misc, misc_v, vxlan_vni,
be32_to_cpu(key->keyid));
}
}
static int parse_tunnel_attr(struct mlx5e_priv *priv,
struct mlx5_flow_spec *spec,
struct tc_cls_flower_offload *f)
{
void *headers_c = MLX5_ADDR_OF(fte_match_param, spec->match_criteria,
outer_headers);
void *headers_v = MLX5_ADDR_OF(fte_match_param, spec->match_value,
outer_headers);
struct flow_dissector_key_control *enc_control =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ENC_CONTROL,
f->key);
if (dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_ENC_PORTS)) {
struct flow_dissector_key_ports *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ENC_PORTS,
f->key);
struct flow_dissector_key_ports *mask =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ENC_PORTS,
f->mask);
struct mlx5_eswitch *esw = priv->mdev->priv.eswitch;
struct net_device *up_dev = mlx5_eswitch_get_uplink_netdev(esw);
struct mlx5e_priv *up_priv = netdev_priv(up_dev);
if (memchr_inv(&mask->dst, 0xff, sizeof(mask->dst)))
goto vxlan_match_offload_err;
if (mlx5e_vxlan_lookup_port(up_priv, be16_to_cpu(key->dst)) &&
MLX5_CAP_ESW(priv->mdev, vxlan_encap_decap))
parse_vxlan_attr(spec, f);
else {
netdev_warn(priv->netdev,
"%d isn't an offloaded vxlan udp dport\n", be16_to_cpu(key->dst));
return -EOPNOTSUPP;
}
MLX5_SET(fte_match_set_lyr_2_4, headers_c,
udp_dport, ntohs(mask->dst));
MLX5_SET(fte_match_set_lyr_2_4, headers_v,
udp_dport, ntohs(key->dst));
MLX5_SET(fte_match_set_lyr_2_4, headers_c,
udp_sport, ntohs(mask->src));
MLX5_SET(fte_match_set_lyr_2_4, headers_v,
udp_sport, ntohs(key->src));
} else {
vxlan_match_offload_err:
netdev_warn(priv->netdev,
"IP tunnel decap offload supported only for vxlan, must set UDP dport\n");
return -EOPNOTSUPP;
}
if (enc_control->addr_type == FLOW_DISSECTOR_KEY_IPV4_ADDRS) {
struct flow_dissector_key_ipv4_addrs *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ENC_IPV4_ADDRS,
f->key);
struct flow_dissector_key_ipv4_addrs *mask =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ENC_IPV4_ADDRS,
f->mask);
MLX5_SET(fte_match_set_lyr_2_4, headers_c,
src_ipv4_src_ipv6.ipv4_layout.ipv4,
ntohl(mask->src));
MLX5_SET(fte_match_set_lyr_2_4, headers_v,
src_ipv4_src_ipv6.ipv4_layout.ipv4,
ntohl(key->src));
MLX5_SET(fte_match_set_lyr_2_4, headers_c,
dst_ipv4_dst_ipv6.ipv4_layout.ipv4,
ntohl(mask->dst));
MLX5_SET(fte_match_set_lyr_2_4, headers_v,
dst_ipv4_dst_ipv6.ipv4_layout.ipv4,
ntohl(key->dst));
MLX5_SET_TO_ONES(fte_match_set_lyr_2_4, headers_c, ethertype);
MLX5_SET(fte_match_set_lyr_2_4, headers_v, ethertype, ETH_P_IP);
} else if (enc_control->addr_type == FLOW_DISSECTOR_KEY_IPV6_ADDRS) {
struct flow_dissector_key_ipv6_addrs *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ENC_IPV6_ADDRS,
f->key);
struct flow_dissector_key_ipv6_addrs *mask =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ENC_IPV6_ADDRS,
f->mask);
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
src_ipv4_src_ipv6.ipv6_layout.ipv6),
&mask->src, MLX5_FLD_SZ_BYTES(ipv6_layout, ipv6));
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
src_ipv4_src_ipv6.ipv6_layout.ipv6),
&key->src, MLX5_FLD_SZ_BYTES(ipv6_layout, ipv6));
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
dst_ipv4_dst_ipv6.ipv6_layout.ipv6),
&mask->dst, MLX5_FLD_SZ_BYTES(ipv6_layout, ipv6));
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
dst_ipv4_dst_ipv6.ipv6_layout.ipv6),
&key->dst, MLX5_FLD_SZ_BYTES(ipv6_layout, ipv6));
MLX5_SET_TO_ONES(fte_match_set_lyr_2_4, headers_c, ethertype);
MLX5_SET(fte_match_set_lyr_2_4, headers_v, ethertype, ETH_P_IPV6);
}
MLX5_SET_TO_ONES(fte_match_set_lyr_2_4, headers_c, dmac_47_16);
MLX5_SET_TO_ONES(fte_match_set_lyr_2_4, headers_c, dmac_15_0);
ether_addr_copy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
dmac_47_16), priv->netdev->dev_addr);
MLX5_SET(fte_match_set_lyr_2_4, headers_c, frag, 1);
MLX5_SET(fte_match_set_lyr_2_4, headers_v, frag, 0);
return 0;
}
static int __parse_cls_flower(struct mlx5e_priv *priv,
struct mlx5_flow_spec *spec,
struct tc_cls_flower_offload *f,
u8 *min_inline)
{
void *headers_c = MLX5_ADDR_OF(fte_match_param, spec->match_criteria,
outer_headers);
void *headers_v = MLX5_ADDR_OF(fte_match_param, spec->match_value,
outer_headers);
u16 addr_type = 0;
u8 ip_proto = 0;
*min_inline = MLX5_INLINE_MODE_L2;
if (f->dissector->used_keys &
~(BIT(FLOW_DISSECTOR_KEY_CONTROL) |
BIT(FLOW_DISSECTOR_KEY_BASIC) |
BIT(FLOW_DISSECTOR_KEY_ETH_ADDRS) |
BIT(FLOW_DISSECTOR_KEY_VLAN) |
BIT(FLOW_DISSECTOR_KEY_IPV4_ADDRS) |
BIT(FLOW_DISSECTOR_KEY_IPV6_ADDRS) |
BIT(FLOW_DISSECTOR_KEY_PORTS) |
BIT(FLOW_DISSECTOR_KEY_ENC_KEYID) |
BIT(FLOW_DISSECTOR_KEY_ENC_IPV4_ADDRS) |
BIT(FLOW_DISSECTOR_KEY_ENC_IPV6_ADDRS) |
BIT(FLOW_DISSECTOR_KEY_ENC_PORTS) |
BIT(FLOW_DISSECTOR_KEY_ENC_CONTROL))) {
netdev_warn(priv->netdev, "Unsupported key used: 0x%x\n",
f->dissector->used_keys);
return -EOPNOTSUPP;
}
if ((dissector_uses_key(f->dissector,
FLOW_DISSECTOR_KEY_ENC_IPV4_ADDRS) ||
dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_ENC_KEYID) ||
dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_ENC_PORTS)) &&
dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_ENC_CONTROL)) {
struct flow_dissector_key_control *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ENC_CONTROL,
f->key);
switch (key->addr_type) {
case FLOW_DISSECTOR_KEY_IPV4_ADDRS:
case FLOW_DISSECTOR_KEY_IPV6_ADDRS:
if (parse_tunnel_attr(priv, spec, f))
return -EOPNOTSUPP;
break;
default:
return -EOPNOTSUPP;
}
headers_c = MLX5_ADDR_OF(fte_match_param, spec->match_criteria,
inner_headers);
headers_v = MLX5_ADDR_OF(fte_match_param, spec->match_value,
inner_headers);
}
if (dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_CONTROL)) {
struct flow_dissector_key_control *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_CONTROL,
f->key);
struct flow_dissector_key_control *mask =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_CONTROL,
f->mask);
addr_type = key->addr_type;
if (mask->flags & FLOW_DIS_IS_FRAGMENT) {
MLX5_SET(fte_match_set_lyr_2_4, headers_c, frag, 1);
MLX5_SET(fte_match_set_lyr_2_4, headers_v, frag,
key->flags & FLOW_DIS_IS_FRAGMENT);
if (key->flags & FLOW_DIS_IS_FRAGMENT)
*min_inline = MLX5_INLINE_MODE_IP;
}
}
if (dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_BASIC)) {
struct flow_dissector_key_basic *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_BASIC,
f->key);
struct flow_dissector_key_basic *mask =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_BASIC,
f->mask);
ip_proto = key->ip_proto;
MLX5_SET(fte_match_set_lyr_2_4, headers_c, ethertype,
ntohs(mask->n_proto));
MLX5_SET(fte_match_set_lyr_2_4, headers_v, ethertype,
ntohs(key->n_proto));
MLX5_SET(fte_match_set_lyr_2_4, headers_c, ip_protocol,
mask->ip_proto);
MLX5_SET(fte_match_set_lyr_2_4, headers_v, ip_protocol,
key->ip_proto);
if (mask->ip_proto)
*min_inline = MLX5_INLINE_MODE_IP;
}
if (dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_ETH_ADDRS)) {
struct flow_dissector_key_eth_addrs *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ETH_ADDRS,
f->key);
struct flow_dissector_key_eth_addrs *mask =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_ETH_ADDRS,
f->mask);
ether_addr_copy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
dmac_47_16),
mask->dst);
ether_addr_copy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
dmac_47_16),
key->dst);
ether_addr_copy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
smac_47_16),
mask->src);
ether_addr_copy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
smac_47_16),
key->src);
}
if (dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_VLAN)) {
struct flow_dissector_key_vlan *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_VLAN,
f->key);
struct flow_dissector_key_vlan *mask =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_VLAN,
f->mask);
if (mask->vlan_id || mask->vlan_priority) {
MLX5_SET(fte_match_set_lyr_2_4, headers_c, cvlan_tag, 1);
MLX5_SET(fte_match_set_lyr_2_4, headers_v, cvlan_tag, 1);
MLX5_SET(fte_match_set_lyr_2_4, headers_c, first_vid, mask->vlan_id);
MLX5_SET(fte_match_set_lyr_2_4, headers_v, first_vid, key->vlan_id);
MLX5_SET(fte_match_set_lyr_2_4, headers_c, first_prio, mask->vlan_priority);
MLX5_SET(fte_match_set_lyr_2_4, headers_v, first_prio, key->vlan_priority);
}
}
if (addr_type == FLOW_DISSECTOR_KEY_IPV4_ADDRS) {
struct flow_dissector_key_ipv4_addrs *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_IPV4_ADDRS,
f->key);
struct flow_dissector_key_ipv4_addrs *mask =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_IPV4_ADDRS,
f->mask);
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
src_ipv4_src_ipv6.ipv4_layout.ipv4),
&mask->src, sizeof(mask->src));
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
src_ipv4_src_ipv6.ipv4_layout.ipv4),
&key->src, sizeof(key->src));
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
dst_ipv4_dst_ipv6.ipv4_layout.ipv4),
&mask->dst, sizeof(mask->dst));
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
dst_ipv4_dst_ipv6.ipv4_layout.ipv4),
&key->dst, sizeof(key->dst));
if (mask->src || mask->dst)
*min_inline = MLX5_INLINE_MODE_IP;
}
if (addr_type == FLOW_DISSECTOR_KEY_IPV6_ADDRS) {
struct flow_dissector_key_ipv6_addrs *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_IPV6_ADDRS,
f->key);
struct flow_dissector_key_ipv6_addrs *mask =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_IPV6_ADDRS,
f->mask);
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
src_ipv4_src_ipv6.ipv6_layout.ipv6),
&mask->src, sizeof(mask->src));
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
src_ipv4_src_ipv6.ipv6_layout.ipv6),
&key->src, sizeof(key->src));
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_c,
dst_ipv4_dst_ipv6.ipv6_layout.ipv6),
&mask->dst, sizeof(mask->dst));
memcpy(MLX5_ADDR_OF(fte_match_set_lyr_2_4, headers_v,
dst_ipv4_dst_ipv6.ipv6_layout.ipv6),
&key->dst, sizeof(key->dst));
if (ipv6_addr_type(&mask->src) != IPV6_ADDR_ANY ||
ipv6_addr_type(&mask->dst) != IPV6_ADDR_ANY)
*min_inline = MLX5_INLINE_MODE_IP;
}
if (dissector_uses_key(f->dissector, FLOW_DISSECTOR_KEY_PORTS)) {
struct flow_dissector_key_ports *key =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_PORTS,
f->key);
struct flow_dissector_key_ports *mask =
skb_flow_dissector_target(f->dissector,
FLOW_DISSECTOR_KEY_PORTS,
f->mask);
switch (ip_proto) {
case IPPROTO_TCP:
MLX5_SET(fte_match_set_lyr_2_4, headers_c,
tcp_sport, ntohs(mask->src));
MLX5_SET(fte_match_set_lyr_2_4, headers_v,
tcp_sport, ntohs(key->src));
MLX5_SET(fte_match_set_lyr_2_4, headers_c,
tcp_dport, ntohs(mask->dst));
MLX5_SET(fte_match_set_lyr_2_4, headers_v,
tcp_dport, ntohs(key->dst));
break;
case IPPROTO_UDP:
MLX5_SET(fte_match_set_lyr_2_4, headers_c,
udp_sport, ntohs(mask->src));
MLX5_SET(fte_match_set_lyr_2_4, headers_v,
udp_sport, ntohs(key->src));
MLX5_SET(fte_match_set_lyr_2_4, headers_c,
udp_dport, ntohs(mask->dst));
MLX5_SET(fte_match_set_lyr_2_4, headers_v,
udp_dport, ntohs(key->dst));
break;
default:
netdev_err(priv->netdev,
"Only UDP and TCP transport are supported\n");
return -EINVAL;
}
if (mask->src || mask->dst)
*min_inline = MLX5_INLINE_MODE_TCP_UDP;
}
return 0;
}
static int parse_cls_flower(struct mlx5e_priv *priv,
struct mlx5e_tc_flow *flow,
struct mlx5_flow_spec *spec,
struct tc_cls_flower_offload *f)
{
struct mlx5_core_dev *dev = priv->mdev;
struct mlx5_eswitch *esw = dev->priv.eswitch;
struct mlx5e_rep_priv *rpriv = priv->ppriv;
struct mlx5_eswitch_rep *rep;
u8 min_inline;
int err;
err = __parse_cls_flower(priv, spec, f, &min_inline);
if (!err && (flow->flags & MLX5E_TC_FLOW_ESWITCH)) {
rep = rpriv->rep;
if (rep->vport != FDB_UPLINK_VPORT &&
(esw->offloads.inline_mode != MLX5_INLINE_MODE_NONE &&
esw->offloads.inline_mode < min_inline)) {
netdev_warn(priv->netdev,
"Flow is not offloaded due to min inline setting, required %d actual %d\n",
min_inline, esw->offloads.inline_mode);
return -EOPNOTSUPP;
}
}
return err;
}
static int set_pedit_val(u8 hdr_type, u32 mask, u32 val, u32 offset,
struct pedit_headers *masks,
struct pedit_headers *vals)
{
u32 *curr_pmask, *curr_pval;
if (hdr_type >= __PEDIT_HDR_TYPE_MAX)
goto out_err;
curr_pmask = (u32 *)(pedit_header(masks, hdr_type) + offset);
curr_pval = (u32 *)(pedit_header(vals, hdr_type) + offset);
if (*curr_pmask & mask)
goto out_err;
*curr_pmask |= mask;
*curr_pval |= (val & mask);
return 0;
out_err:
return -EOPNOTSUPP;
}
static int offload_pedit_fields(struct pedit_headers *masks,
struct pedit_headers *vals,
struct mlx5e_tc_flow_parse_attr *parse_attr)
{
struct pedit_headers *set_masks, *add_masks, *set_vals, *add_vals;
int i, action_size, nactions, max_actions, first, last, first_z;
void *s_masks_p, *a_masks_p, *vals_p;
struct mlx5_fields *f;
u8 cmd, field_bsize;
u32 s_mask, a_mask;
unsigned long mask;
void *action;
set_masks = &masks[TCA_PEDIT_KEY_EX_CMD_SET];
add_masks = &masks[TCA_PEDIT_KEY_EX_CMD_ADD];
set_vals = &vals[TCA_PEDIT_KEY_EX_CMD_SET];
add_vals = &vals[TCA_PEDIT_KEY_EX_CMD_ADD];
action_size = MLX5_UN_SZ_BYTES(set_action_in_add_action_in_auto);
action = parse_attr->mod_hdr_actions;
max_actions = parse_attr->num_mod_hdr_actions;
nactions = 0;
for (i = 0; i < ARRAY_SIZE(fields); i++) {
f = &fields[i];
s_mask = 0;
a_mask = 0;
s_masks_p = (void *)set_masks + f->offset;
a_masks_p = (void *)add_masks + f->offset;
memcpy(&s_mask, s_masks_p, f->size);
memcpy(&a_mask, a_masks_p, f->size);
if (!s_mask && !a_mask)
continue;
if (s_mask && a_mask) {
printk(KERN_WARNING "mlx5: can't set and add to the same HW field (%x)\n", f->field);
return -EOPNOTSUPP;
}
if (nactions == max_actions) {
printk(KERN_WARNING "mlx5: parsed %d pedit actions, can't do more\n", nactions);
return -EOPNOTSUPP;
}
if (s_mask) {
cmd = MLX5_ACTION_TYPE_SET;
mask = s_mask;
vals_p = (void *)set_vals + f->offset;
memset(s_masks_p, 0, f->size);
} else {
cmd = MLX5_ACTION_TYPE_ADD;
mask = a_mask;
vals_p = (void *)add_vals + f->offset;
memset(a_masks_p, 0, f->size);
}
field_bsize = f->size * BITS_PER_BYTE;
first_z = find_first_zero_bit(&mask, field_bsize);
first = find_first_bit(&mask, field_bsize);
last = find_last_bit(&mask, field_bsize);
if (first > 0 || last != (field_bsize - 1) || first_z < last) {
printk(KERN_WARNING "mlx5: partial rewrite (mask %lx) is currently not offloaded\n",
mask);
return -EOPNOTSUPP;
}
MLX5_SET(set_action_in, action, action_type, cmd);
MLX5_SET(set_action_in, action, field, f->field);
if (cmd == MLX5_ACTION_TYPE_SET) {
MLX5_SET(set_action_in, action, offset, 0);
MLX5_SET(set_action_in, action, length, field_bsize);
}
if (field_bsize == 32)
MLX5_SET(set_action_in, action, data, ntohl(*(__be32 *)vals_p));
else if (field_bsize == 16)
MLX5_SET(set_action_in, action, data, ntohs(*(__be16 *)vals_p));
else if (field_bsize == 8)
MLX5_SET(set_action_in, action, data, *(u8 *)vals_p);
action += action_size;
nactions++;
}
parse_attr->num_mod_hdr_actions = nactions;
return 0;
}
static int alloc_mod_hdr_actions(struct mlx5e_priv *priv,
const struct tc_action *a, int namespace,
struct mlx5e_tc_flow_parse_attr *parse_attr)
{
int nkeys, action_size, max_actions;
nkeys = tcf_pedit_nkeys(a);
action_size = MLX5_UN_SZ_BYTES(set_action_in_add_action_in_auto);
if (namespace == MLX5_FLOW_NAMESPACE_FDB)
max_actions = MLX5_CAP_ESW_FLOWTABLE_FDB(priv->mdev, max_modify_header_actions);
else
max_actions = MLX5_CAP_FLOWTABLE_NIC_RX(priv->mdev, max_modify_header_actions);
max_actions = min(max_actions, nkeys * 16);
parse_attr->mod_hdr_actions = kcalloc(max_actions, action_size, GFP_KERNEL);
if (!parse_attr->mod_hdr_actions)
return -ENOMEM;
parse_attr->num_mod_hdr_actions = max_actions;
return 0;
}
static int parse_tc_pedit_action(struct mlx5e_priv *priv,
const struct tc_action *a, int namespace,
struct mlx5e_tc_flow_parse_attr *parse_attr)
{
struct pedit_headers masks[__PEDIT_CMD_MAX], vals[__PEDIT_CMD_MAX], *cmd_masks;
int nkeys, i, err = -EOPNOTSUPP;
u32 mask, val, offset;
u8 cmd, htype;
nkeys = tcf_pedit_nkeys(a);
memset(masks, 0, sizeof(struct pedit_headers) * __PEDIT_CMD_MAX);
memset(vals, 0, sizeof(struct pedit_headers) * __PEDIT_CMD_MAX);
for (i = 0; i < nkeys; i++) {
htype = tcf_pedit_htype(a, i);
cmd = tcf_pedit_cmd(a, i);
err = -EOPNOTSUPP;
if (htype == TCA_PEDIT_KEY_EX_HDR_TYPE_NETWORK) {
printk(KERN_WARNING "mlx5: legacy pedit isn't offloaded\n");
goto out_err;
}
if (cmd != TCA_PEDIT_KEY_EX_CMD_SET && cmd != TCA_PEDIT_KEY_EX_CMD_ADD) {
printk(KERN_WARNING "mlx5: pedit cmd %d isn't offloaded\n", cmd);
goto out_err;
}
mask = tcf_pedit_mask(a, i);
val = tcf_pedit_val(a, i);
offset = tcf_pedit_offset(a, i);
err = set_pedit_val(htype, ~mask, val, offset, &masks[cmd], &vals[cmd]);
if (err)
goto out_err;
}
err = alloc_mod_hdr_actions(priv, a, namespace, parse_attr);
if (err)
goto out_err;
err = offload_pedit_fields(masks, vals, parse_attr);
if (err < 0)
goto out_dealloc_parsed_actions;
for (cmd = 0; cmd < __PEDIT_CMD_MAX; cmd++) {
cmd_masks = &masks[cmd];
if (memcmp(cmd_masks, &zero_masks, sizeof(zero_masks))) {
printk(KERN_WARNING "mlx5: attempt to offload an unsupported field (cmd %d)\n",
cmd);
print_hex_dump(KERN_WARNING, "mask: ", DUMP_PREFIX_ADDRESS,
16, 1, cmd_masks, sizeof(zero_masks), true);
err = -EOPNOTSUPP;
goto out_dealloc_parsed_actions;
}
}
return 0;
out_dealloc_parsed_actions:
kfree(parse_attr->mod_hdr_actions);
out_err:
return err;
}
static bool csum_offload_supported(struct mlx5e_priv *priv, u32 action, u32 update_flags)
{
u32 prot_flags = TCA_CSUM_UPDATE_FLAG_IPV4HDR | TCA_CSUM_UPDATE_FLAG_TCP |
TCA_CSUM_UPDATE_FLAG_UDP;
if (!(action & MLX5_FLOW_CONTEXT_ACTION_MOD_HDR)) {
netdev_warn(priv->netdev,
"TC csum action is only offloaded with pedit\n");
return false;
}
if (update_flags & ~prot_flags) {
netdev_warn(priv->netdev,
"can't offload TC csum action for some header/s - flags %#x\n",
update_flags);
return false;
}
return true;
}
static int parse_tc_nic_actions(struct mlx5e_priv *priv, struct tcf_exts *exts,
struct mlx5e_tc_flow_parse_attr *parse_attr,
struct mlx5e_tc_flow *flow)
{
struct mlx5_nic_flow_attr *attr = flow->nic_attr;
const struct tc_action *a;
LIST_HEAD(actions);
int err;
if (tc_no_actions(exts))
return -EINVAL;
attr->flow_tag = MLX5_FS_DEFAULT_FLOW_TAG;
attr->action = 0;
tcf_exts_to_list(exts, &actions);
list_for_each_entry(a, &actions, list) {
if (attr->action)
return -EINVAL;
if (is_tcf_gact_shot(a)) {
attr->action |= MLX5_FLOW_CONTEXT_ACTION_DROP;
if (MLX5_CAP_FLOWTABLE(priv->mdev,
flow_table_properties_nic_receive.flow_counter))
attr->action |= MLX5_FLOW_CONTEXT_ACTION_COUNT;
continue;
}
if (is_tcf_pedit(a)) {
err = parse_tc_pedit_action(priv, a, MLX5_FLOW_NAMESPACE_KERNEL,
parse_attr);
if (err)
return err;
attr->action |= MLX5_FLOW_CONTEXT_ACTION_MOD_HDR |
MLX5_FLOW_CONTEXT_ACTION_FWD_DEST;
continue;
}
if (is_tcf_csum(a)) {
if (csum_offload_supported(priv, attr->action,
tcf_csum_update_flags(a)))
continue;
return -EOPNOTSUPP;
}
if (is_tcf_skbedit_mark(a)) {
u32 mark = tcf_skbedit_mark(a);
if (mark & ~MLX5E_TC_FLOW_ID_MASK) {
netdev_warn(priv->netdev, "Bad flow mark - only 16 bit is supported: 0x%x\n",
mark);
return -EINVAL;
}
attr->flow_tag = mark;
attr->action |= MLX5_FLOW_CONTEXT_ACTION_FWD_DEST;
continue;
}
return -EINVAL;
}
return 0;
}
static inline int cmp_encap_info(struct ip_tunnel_key *a,
struct ip_tunnel_key *b)
{
return memcmp(a, b, sizeof(*a));
}
static inline int hash_encap_info(struct ip_tunnel_key *key)
{
return jhash(key, sizeof(*key), 0);
}
static int mlx5e_route_lookup_ipv4(struct mlx5e_priv *priv,
struct net_device *mirred_dev,
struct net_device **out_dev,
struct flowi4 *fl4,
struct neighbour **out_n,
int *out_ttl)
{
struct mlx5_eswitch *esw = priv->mdev->priv.eswitch;
struct rtable *rt;
struct neighbour *n = NULL;
#if IS_ENABLED(CONFIG_INET)
int ret;
rt = ip_route_output_key(dev_net(mirred_dev), fl4);
ret = PTR_ERR_OR_ZERO(rt);
if (ret)
return ret;
#else
return -EOPNOTSUPP;
#endif
if (!switchdev_port_same_parent_id(priv->netdev, rt->dst.dev))
*out_dev = mlx5_eswitch_get_uplink_netdev(esw);
else
*out_dev = rt->dst.dev;
*out_ttl = ip4_dst_hoplimit(&rt->dst);
n = dst_neigh_lookup(&rt->dst, &fl4->daddr);
ip_rt_put(rt);
if (!n)
return -ENOMEM;
*out_n = n;
return 0;
}
static int mlx5e_route_lookup_ipv6(struct mlx5e_priv *priv,
struct net_device *mirred_dev,
struct net_device **out_dev,
struct flowi6 *fl6,
struct neighbour **out_n,
int *out_ttl)
{
struct neighbour *n = NULL;
struct dst_entry *dst;
#if IS_ENABLED(CONFIG_INET) && IS_ENABLED(CONFIG_IPV6)
struct mlx5_eswitch *esw = priv->mdev->priv.eswitch;
int ret;
dst = ip6_route_output(dev_net(mirred_dev), NULL, fl6);
ret = dst->error;
if (ret) {
dst_release(dst);
return ret;
}
*out_ttl = ip6_dst_hoplimit(dst);
if (!switchdev_port_same_parent_id(priv->netdev, dst->dev))
*out_dev = mlx5_eswitch_get_uplink_netdev(esw);
else
*out_dev = dst->dev;
#else
return -EOPNOTSUPP;
#endif
n = dst_neigh_lookup(dst, &fl6->daddr);
dst_release(dst);
if (!n)
return -ENOMEM;
*out_n = n;
return 0;
}
static void gen_vxlan_header_ipv4(struct net_device *out_dev,
char buf[], int encap_size,
unsigned char h_dest[ETH_ALEN],
int ttl,
__be32 daddr,
__be32 saddr,
__be16 udp_dst_port,
__be32 vx_vni)
{
struct ethhdr *eth = (struct ethhdr *)buf;
struct iphdr *ip = (struct iphdr *)((char *)eth + sizeof(struct ethhdr));
struct udphdr *udp = (struct udphdr *)((char *)ip + sizeof(struct iphdr));
struct vxlanhdr *vxh = (struct vxlanhdr *)((char *)udp + sizeof(struct udphdr));
memset(buf, 0, encap_size);
ether_addr_copy(eth->h_dest, h_dest);
ether_addr_copy(eth->h_source, out_dev->dev_addr);
eth->h_proto = htons(ETH_P_IP);
ip->daddr = daddr;
ip->saddr = saddr;
ip->ttl = ttl;
ip->protocol = IPPROTO_UDP;
ip->version = 0x4;
ip->ihl = 0x5;
udp->dest = udp_dst_port;
vxh->vx_flags = VXLAN_HF_VNI;
vxh->vx_vni = vxlan_vni_field(vx_vni);
}
static void gen_vxlan_header_ipv6(struct net_device *out_dev,
char buf[], int encap_size,
unsigned char h_dest[ETH_ALEN],
int ttl,
struct in6_addr *daddr,
struct in6_addr *saddr,
__be16 udp_dst_port,
__be32 vx_vni)
{
struct ethhdr *eth = (struct ethhdr *)buf;
struct ipv6hdr *ip6h = (struct ipv6hdr *)((char *)eth + sizeof(struct ethhdr));
struct udphdr *udp = (struct udphdr *)((char *)ip6h + sizeof(struct ipv6hdr));
struct vxlanhdr *vxh = (struct vxlanhdr *)((char *)udp + sizeof(struct udphdr));
memset(buf, 0, encap_size);
ether_addr_copy(eth->h_dest, h_dest);
ether_addr_copy(eth->h_source, out_dev->dev_addr);
eth->h_proto = htons(ETH_P_IPV6);
ip6_flow_hdr(ip6h, 0, 0);
ip6h->nexthdr = IPPROTO_UDP;
ip6h->hop_limit = ttl;
ip6h->daddr = *daddr;
ip6h->saddr = *saddr;
udp->dest = udp_dst_port;
vxh->vx_flags = VXLAN_HF_VNI;
vxh->vx_vni = vxlan_vni_field(vx_vni);
}
static int mlx5e_create_encap_header_ipv4(struct mlx5e_priv *priv,
struct net_device *mirred_dev,
struct mlx5e_encap_entry *e)
{
int max_encap_size = MLX5_CAP_ESW(priv->mdev, max_encap_header_size);
int ipv4_encap_size = ETH_HLEN + sizeof(struct iphdr) + VXLAN_HLEN;
struct ip_tunnel_key *tun_key = &e->tun_info.key;
struct net_device *out_dev;
struct neighbour *n = NULL;
struct flowi4 fl4 = {};
char *encap_header;
int ttl, err;
u8 nud_state;
if (max_encap_size < ipv4_encap_size) {
mlx5_core_warn(priv->mdev, "encap size %d too big, max supported is %d\n",
ipv4_encap_size, max_encap_size);
return -EOPNOTSUPP;
}
encap_header = kzalloc(ipv4_encap_size, GFP_KERNEL);
if (!encap_header)
return -ENOMEM;
switch (e->tunnel_type) {
case MLX5_HEADER_TYPE_VXLAN:
fl4.flowi4_proto = IPPROTO_UDP;
fl4.fl4_dport = tun_key->tp_dst;
break;
default:
err = -EOPNOTSUPP;
goto out;
}
fl4.flowi4_tos = tun_key->tos;
fl4.daddr = tun_key->u.ipv4.dst;
fl4.saddr = tun_key->u.ipv4.src;
err = mlx5e_route_lookup_ipv4(priv, mirred_dev, &out_dev,
&fl4, &n, &ttl);
if (err)
goto out;
e->m_neigh.dev = n->dev;
e->m_neigh.family = n->ops->family;
memcpy(&e->m_neigh.dst_ip, n->primary_key, n->tbl->key_len);
e->out_dev = out_dev;
err = mlx5e_rep_encap_entry_attach(netdev_priv(out_dev), e);
if (err)
goto out;
read_lock_bh(&n->lock);
nud_state = n->nud_state;
ether_addr_copy(e->h_dest, n->ha);
read_unlock_bh(&n->lock);
switch (e->tunnel_type) {
case MLX5_HEADER_TYPE_VXLAN:
gen_vxlan_header_ipv4(out_dev, encap_header,
ipv4_encap_size, e->h_dest, ttl,
fl4.daddr,
fl4.saddr, tun_key->tp_dst,
tunnel_id_to_key32(tun_key->tun_id));
break;
default:
err = -EOPNOTSUPP;
goto destroy_neigh_entry;
}
e->encap_size = ipv4_encap_size;
e->encap_header = encap_header;
if (!(nud_state & NUD_VALID)) {
neigh_event_send(n, NULL);
neigh_release(n);
return -EAGAIN;
}
err = mlx5_encap_alloc(priv->mdev, e->tunnel_type,
ipv4_encap_size, encap_header, &e->encap_id);
if (err)
goto destroy_neigh_entry;
e->flags |= MLX5_ENCAP_ENTRY_VALID;
mlx5e_rep_queue_neigh_stats_work(netdev_priv(out_dev));
neigh_release(n);
return err;
destroy_neigh_entry:
mlx5e_rep_encap_entry_detach(netdev_priv(e->out_dev), e);
out:
kfree(encap_header);
if (n)
neigh_release(n);
return err;
}
static int mlx5e_create_encap_header_ipv6(struct mlx5e_priv *priv,
struct net_device *mirred_dev,
struct mlx5e_encap_entry *e)
{
int max_encap_size = MLX5_CAP_ESW(priv->mdev, max_encap_header_size);
int ipv6_encap_size = ETH_HLEN + sizeof(struct ipv6hdr) + VXLAN_HLEN;
struct ip_tunnel_key *tun_key = &e->tun_info.key;
struct net_device *out_dev;
struct neighbour *n = NULL;
struct flowi6 fl6 = {};
char *encap_header;
int err, ttl = 0;
u8 nud_state;
if (max_encap_size < ipv6_encap_size) {
mlx5_core_warn(priv->mdev, "encap size %d too big, max supported is %d\n",
ipv6_encap_size, max_encap_size);
return -EOPNOTSUPP;
}
encap_header = kzalloc(ipv6_encap_size, GFP_KERNEL);
if (!encap_header)
return -ENOMEM;
switch (e->tunnel_type) {
case MLX5_HEADER_TYPE_VXLAN:
fl6.flowi6_proto = IPPROTO_UDP;
fl6.fl6_dport = tun_key->tp_dst;
break;
default:
err = -EOPNOTSUPP;
goto out;
}
fl6.flowlabel = ip6_make_flowinfo(RT_TOS(tun_key->tos), tun_key->label);
fl6.daddr = tun_key->u.ipv6.dst;
fl6.saddr = tun_key->u.ipv6.src;
err = mlx5e_route_lookup_ipv6(priv, mirred_dev, &out_dev,
&fl6, &n, &ttl);
if (err)
goto out;
e->m_neigh.dev = n->dev;
e->m_neigh.family = n->ops->family;
memcpy(&e->m_neigh.dst_ip, n->primary_key, n->tbl->key_len);
e->out_dev = out_dev;
err = mlx5e_rep_encap_entry_attach(netdev_priv(out_dev), e);
if (err)
goto out;
read_lock_bh(&n->lock);
nud_state = n->nud_state;
ether_addr_copy(e->h_dest, n->ha);
read_unlock_bh(&n->lock);
switch (e->tunnel_type) {
case MLX5_HEADER_TYPE_VXLAN:
gen_vxlan_header_ipv6(out_dev, encap_header,
ipv6_encap_size, e->h_dest, ttl,
&fl6.daddr,
&fl6.saddr, tun_key->tp_dst,
tunnel_id_to_key32(tun_key->tun_id));
break;
default:
err = -EOPNOTSUPP;
goto destroy_neigh_entry;
}
e->encap_size = ipv6_encap_size;
e->encap_header = encap_header;
if (!(nud_state & NUD_VALID)) {
neigh_event_send(n, NULL);
neigh_release(n);
return -EAGAIN;
}
err = mlx5_encap_alloc(priv->mdev, e->tunnel_type,
ipv6_encap_size, encap_header, &e->encap_id);
if (err)
goto destroy_neigh_entry;
e->flags |= MLX5_ENCAP_ENTRY_VALID;
mlx5e_rep_queue_neigh_stats_work(netdev_priv(out_dev));
neigh_release(n);
return err;
destroy_neigh_entry:
mlx5e_rep_encap_entry_detach(netdev_priv(e->out_dev), e);
out:
kfree(encap_header);
if (n)
neigh_release(n);
return err;
}
static int mlx5e_attach_encap(struct mlx5e_priv *priv,
struct ip_tunnel_info *tun_info,
struct net_device *mirred_dev,
struct net_device **encap_dev,
struct mlx5e_tc_flow *flow)
{
struct mlx5_eswitch *esw = priv->mdev->priv.eswitch;
struct net_device *up_dev = mlx5_eswitch_get_uplink_netdev(esw);
unsigned short family = ip_tunnel_info_af(tun_info);
struct mlx5e_priv *up_priv = netdev_priv(up_dev);
struct mlx5_esw_flow_attr *attr = flow->esw_attr;
struct ip_tunnel_key *key = &tun_info->key;
struct mlx5e_encap_entry *e;
int tunnel_type, err = 0;
uintptr_t hash_key;
bool found = false;
if (!memchr_inv(&key->tp_dst, 0, sizeof(key->tp_dst)))
goto vxlan_encap_offload_err;
if (memchr_inv(&key->tp_src, 0, sizeof(key->tp_src))) {
vxlan_encap_offload_err:
netdev_warn(priv->netdev,
"must set udp dst port and not set udp src port\n");
return -EOPNOTSUPP;
}
if (mlx5e_vxlan_lookup_port(up_priv, be16_to_cpu(key->tp_dst)) &&
MLX5_CAP_ESW(priv->mdev, vxlan_encap_decap)) {
tunnel_type = MLX5_HEADER_TYPE_VXLAN;
} else {
netdev_warn(priv->netdev,
"%d isn't an offloaded vxlan udp dport\n", be16_to_cpu(key->tp_dst));
return -EOPNOTSUPP;
}
hash_key = hash_encap_info(key);
hash_for_each_possible_rcu(esw->offloads.encap_tbl, e,
encap_hlist, hash_key) {
if (!cmp_encap_info(&e->tun_info.key, key)) {
found = true;
break;
}
}
if (found)
goto attach_flow;
e = kzalloc(sizeof(*e), GFP_KERNEL);
if (!e)
return -ENOMEM;
e->tun_info = *tun_info;
e->tunnel_type = tunnel_type;
INIT_LIST_HEAD(&e->flows);
if (family == AF_INET)
err = mlx5e_create_encap_header_ipv4(priv, mirred_dev, e);
else if (family == AF_INET6)
err = mlx5e_create_encap_header_ipv6(priv, mirred_dev, e);
if (err && err != -EAGAIN)
goto out_err;
hash_add_rcu(esw->offloads.encap_tbl, &e->encap_hlist, hash_key);
attach_flow:
list_add(&flow->encap, &e->flows);
*encap_dev = e->out_dev;
if (e->flags & MLX5_ENCAP_ENTRY_VALID)
attr->encap_id = e->encap_id;
return err;
out_err:
kfree(e);
return err;
}
static int parse_tc_fdb_actions(struct mlx5e_priv *priv, struct tcf_exts *exts,
struct mlx5e_tc_flow_parse_attr *parse_attr,
struct mlx5e_tc_flow *flow)
{
struct mlx5_esw_flow_attr *attr = flow->esw_attr;
struct mlx5e_rep_priv *rpriv = priv->ppriv;
struct ip_tunnel_info *info = NULL;
const struct tc_action *a;
LIST_HEAD(actions);
bool encap = false;
int err = 0;
if (tc_no_actions(exts))
return -EINVAL;
memset(attr, 0, sizeof(*attr));
attr->in_rep = rpriv->rep;
tcf_exts_to_list(exts, &actions);
list_for_each_entry(a, &actions, list) {
if (is_tcf_gact_shot(a)) {
attr->action |= MLX5_FLOW_CONTEXT_ACTION_DROP |
MLX5_FLOW_CONTEXT_ACTION_COUNT;
continue;
}
if (is_tcf_pedit(a)) {
err = parse_tc_pedit_action(priv, a, MLX5_FLOW_NAMESPACE_FDB,
parse_attr);
if (err)
return err;
attr->action |= MLX5_FLOW_CONTEXT_ACTION_MOD_HDR;
continue;
}
if (is_tcf_csum(a)) {
if (csum_offload_supported(priv, attr->action,
tcf_csum_update_flags(a)))
continue;
return -EOPNOTSUPP;
}
if (is_tcf_mirred_egress_redirect(a)) {
int ifindex = tcf_mirred_ifindex(a);
struct net_device *out_dev, *encap_dev = NULL;
struct mlx5e_priv *out_priv;
out_dev = __dev_get_by_index(dev_net(priv->netdev), ifindex);
if (switchdev_port_same_parent_id(priv->netdev,
out_dev)) {
attr->action |= MLX5_FLOW_CONTEXT_ACTION_FWD_DEST |
MLX5_FLOW_CONTEXT_ACTION_COUNT;
out_priv = netdev_priv(out_dev);
rpriv = out_priv->ppriv;
attr->out_rep = rpriv->rep;
} else if (encap) {
err = mlx5e_attach_encap(priv, info,
out_dev, &encap_dev, flow);
if (err && err != -EAGAIN)
return err;
attr->action |= MLX5_FLOW_CONTEXT_ACTION_ENCAP |
MLX5_FLOW_CONTEXT_ACTION_FWD_DEST |
MLX5_FLOW_CONTEXT_ACTION_COUNT;
out_priv = netdev_priv(encap_dev);
rpriv = out_priv->ppriv;
attr->out_rep = rpriv->rep;
attr->parse_attr = parse_attr;
} else {
pr_err("devices %s %s not on same switch HW, can't offload forwarding\n",
priv->netdev->name, out_dev->name);
return -EINVAL;
}
continue;
}
if (is_tcf_tunnel_set(a)) {
info = tcf_tunnel_info(a);
if (info)
encap = true;
else
return -EOPNOTSUPP;
continue;
}
if (is_tcf_vlan(a)) {
if (tcf_vlan_action(a) == TCA_VLAN_ACT_POP) {
attr->action |= MLX5_FLOW_CONTEXT_ACTION_VLAN_POP;
} else if (tcf_vlan_action(a) == TCA_VLAN_ACT_PUSH) {
if (tcf_vlan_push_proto(a) != htons(ETH_P_8021Q))
return -EOPNOTSUPP;
attr->action |= MLX5_FLOW_CONTEXT_ACTION_VLAN_PUSH;
attr->vlan = tcf_vlan_push_vid(a);
} else {
return -EOPNOTSUPP;
}
continue;
}
if (is_tcf_tunnel_release(a)) {
attr->action |= MLX5_FLOW_CONTEXT_ACTION_DECAP;
continue;
}
return -EINVAL;
}
return err;
}
int mlx5e_configure_flower(struct mlx5e_priv *priv, __be16 protocol,
struct tc_cls_flower_offload *f)
{
struct mlx5_eswitch *esw = priv->mdev->priv.eswitch;
struct mlx5e_tc_flow_parse_attr *parse_attr;
struct mlx5e_tc_table *tc = &priv->fs.tc;
struct mlx5e_tc_flow *flow;
int attr_size, err = 0;
u8 flow_flags = 0;
if (esw && esw->mode == SRIOV_OFFLOADS) {
flow_flags = MLX5E_TC_FLOW_ESWITCH;
attr_size = sizeof(struct mlx5_esw_flow_attr);
} else {
flow_flags = MLX5E_TC_FLOW_NIC;
attr_size = sizeof(struct mlx5_nic_flow_attr);
}
flow = kzalloc(sizeof(*flow) + attr_size, GFP_KERNEL);
parse_attr = mlx5_vzalloc(sizeof(*parse_attr));
if (!parse_attr || !flow) {
err = -ENOMEM;
goto err_free;
}
flow->cookie = f->cookie;
flow->flags = flow_flags;
err = parse_cls_flower(priv, flow, &parse_attr->spec, f);
if (err < 0)
goto err_free;
if (flow->flags & MLX5E_TC_FLOW_ESWITCH) {
err = parse_tc_fdb_actions(priv, f->exts, parse_attr, flow);
if (err < 0)
goto err_handle_encap_flow;
flow->rule = mlx5e_tc_add_fdb_flow(priv, parse_attr, flow);
} else {
err = parse_tc_nic_actions(priv, f->exts, parse_attr, flow);
if (err < 0)
goto err_free;
flow->rule = mlx5e_tc_add_nic_flow(priv, parse_attr, flow);
}
if (IS_ERR(flow->rule)) {
err = PTR_ERR(flow->rule);
goto err_free;
}
flow->flags |= MLX5E_TC_FLOW_OFFLOADED;
err = rhashtable_insert_fast(&tc->ht, &flow->node,
tc->ht_params);
if (err)
goto err_del_rule;
if (flow->flags & MLX5E_TC_FLOW_ESWITCH &&
!(flow->esw_attr->action & MLX5_FLOW_CONTEXT_ACTION_ENCAP))
kvfree(parse_attr);
return err;
err_del_rule:
mlx5e_tc_del_flow(priv, flow);
err_handle_encap_flow:
if (err == -EAGAIN) {
err = rhashtable_insert_fast(&tc->ht, &flow->node,
tc->ht_params);
if (err)
mlx5e_tc_del_flow(priv, flow);
else
return 0;
}
err_free:
kvfree(parse_attr);
kfree(flow);
return err;
}
int mlx5e_delete_flower(struct mlx5e_priv *priv,
struct tc_cls_flower_offload *f)
{
struct mlx5e_tc_flow *flow;
struct mlx5e_tc_table *tc = &priv->fs.tc;
flow = rhashtable_lookup_fast(&tc->ht, &f->cookie,
tc->ht_params);
if (!flow)
return -EINVAL;
rhashtable_remove_fast(&tc->ht, &flow->node, tc->ht_params);
mlx5e_tc_del_flow(priv, flow);
kfree(flow);
return 0;
}
int mlx5e_stats_flower(struct mlx5e_priv *priv,
struct tc_cls_flower_offload *f)
{
struct mlx5e_tc_table *tc = &priv->fs.tc;
struct mlx5e_tc_flow *flow;
struct tc_action *a;
struct mlx5_fc *counter;
LIST_HEAD(actions);
u64 bytes;
u64 packets;
u64 lastuse;
flow = rhashtable_lookup_fast(&tc->ht, &f->cookie,
tc->ht_params);
if (!flow)
return -EINVAL;
if (!(flow->flags & MLX5E_TC_FLOW_OFFLOADED))
return 0;
counter = mlx5_flow_rule_counter(flow->rule);
if (!counter)
return 0;
mlx5_fc_query_cached(counter, &bytes, &packets, &lastuse);
preempt_disable();
tcf_exts_to_list(f->exts, &actions);
list_for_each_entry(a, &actions, list)
tcf_action_stats_update(a, bytes, packets, lastuse);
preempt_enable();
return 0;
}
int mlx5e_tc_init(struct mlx5e_priv *priv)
{
struct mlx5e_tc_table *tc = &priv->fs.tc;
tc->ht_params = mlx5e_tc_flow_ht_params;
return rhashtable_init(&tc->ht, &tc->ht_params);
}
static void _mlx5e_tc_del_flow(void *ptr, void *arg)
{
struct mlx5e_tc_flow *flow = ptr;
struct mlx5e_priv *priv = arg;
mlx5e_tc_del_flow(priv, flow);
kfree(flow);
}
void mlx5e_tc_cleanup(struct mlx5e_priv *priv)
{
struct mlx5e_tc_table *tc = &priv->fs.tc;
rhashtable_free_and_destroy(&tc->ht, _mlx5e_tc_del_flow, priv);
if (!IS_ERR_OR_NULL(tc->t)) {
mlx5_destroy_flow_table(tc->t);
tc->t = NULL;
}
}
