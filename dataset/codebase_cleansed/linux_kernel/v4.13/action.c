static void nfp_fl_pop_vlan(struct nfp_fl_pop_vlan *pop_vlan)
{
size_t act_size = sizeof(struct nfp_fl_pop_vlan);
u16 tmp_pop_vlan_op;
tmp_pop_vlan_op =
FIELD_PREP(NFP_FL_ACT_LEN_LW, act_size >> NFP_FL_LW_SIZ) |
FIELD_PREP(NFP_FL_ACT_JMP_ID, NFP_FL_ACTION_OPCODE_POP_VLAN);
pop_vlan->a_op = cpu_to_be16(tmp_pop_vlan_op);
pop_vlan->reserved = 0;
}
static void
nfp_fl_push_vlan(struct nfp_fl_push_vlan *push_vlan,
const struct tc_action *action)
{
size_t act_size = sizeof(struct nfp_fl_push_vlan);
struct tcf_vlan *vlan = to_vlan(action);
u16 tmp_push_vlan_tci;
u16 tmp_push_vlan_op;
tmp_push_vlan_op =
FIELD_PREP(NFP_FL_ACT_LEN_LW, act_size >> NFP_FL_LW_SIZ) |
FIELD_PREP(NFP_FL_ACT_JMP_ID, NFP_FL_ACTION_OPCODE_PUSH_VLAN);
push_vlan->a_op = cpu_to_be16(tmp_push_vlan_op);
push_vlan->reserved = 0;
push_vlan->vlan_tpid = tcf_vlan_push_proto(action);
tmp_push_vlan_tci =
FIELD_PREP(NFP_FL_PUSH_VLAN_PRIO, vlan->tcfv_push_prio) |
FIELD_PREP(NFP_FL_PUSH_VLAN_VID, vlan->tcfv_push_vid) |
NFP_FL_PUSH_VLAN_CFI;
push_vlan->vlan_tci = cpu_to_be16(tmp_push_vlan_tci);
}
static int
nfp_fl_output(struct nfp_fl_output *output, const struct tc_action *action,
struct nfp_fl_payload *nfp_flow, bool last,
struct net_device *in_dev)
{
size_t act_size = sizeof(struct nfp_fl_output);
struct net_device *out_dev;
u16 tmp_output_op;
int ifindex;
tmp_output_op =
FIELD_PREP(NFP_FL_ACT_LEN_LW, act_size >> NFP_FL_LW_SIZ) |
FIELD_PREP(NFP_FL_ACT_JMP_ID, NFP_FL_ACTION_OPCODE_OUTPUT);
output->a_op = cpu_to_be16(tmp_output_op);
output->flags = cpu_to_be16(last ? NFP_FL_OUT_FLAGS_LAST : 0);
ifindex = tcf_mirred_ifindex(action);
out_dev = __dev_get_by_index(dev_net(in_dev), ifindex);
if (!out_dev)
return -EOPNOTSUPP;
if (!switchdev_port_same_parent_id(in_dev, out_dev))
return -EOPNOTSUPP;
output->port = cpu_to_be32(nfp_repr_get_port_id(out_dev));
if (!output->port)
return -EOPNOTSUPP;
nfp_flow->meta.shortcut = output->port;
return 0;
}
static int
nfp_flower_loop_action(const struct tc_action *a,
struct nfp_fl_payload *nfp_fl, int *a_len,
struct net_device *netdev)
{
struct nfp_fl_push_vlan *psh_v;
struct nfp_fl_pop_vlan *pop_v;
struct nfp_fl_output *output;
int err;
if (is_tcf_gact_shot(a)) {
nfp_fl->meta.shortcut = cpu_to_be32(NFP_FL_SC_ACT_DROP);
} else if (is_tcf_mirred_egress_redirect(a)) {
if (*a_len + sizeof(struct nfp_fl_output) > NFP_FL_MAX_A_SIZ)
return -EOPNOTSUPP;
output = (struct nfp_fl_output *)&nfp_fl->action_data[*a_len];
err = nfp_fl_output(output, a, nfp_fl, true, netdev);
if (err)
return err;
*a_len += sizeof(struct nfp_fl_output);
} else if (is_tcf_mirred_egress_mirror(a)) {
if (*a_len + sizeof(struct nfp_fl_output) > NFP_FL_MAX_A_SIZ)
return -EOPNOTSUPP;
output = (struct nfp_fl_output *)&nfp_fl->action_data[*a_len];
err = nfp_fl_output(output, a, nfp_fl, false, netdev);
if (err)
return err;
*a_len += sizeof(struct nfp_fl_output);
} else if (is_tcf_vlan(a) && tcf_vlan_action(a) == TCA_VLAN_ACT_POP) {
if (*a_len + sizeof(struct nfp_fl_pop_vlan) > NFP_FL_MAX_A_SIZ)
return -EOPNOTSUPP;
pop_v = (struct nfp_fl_pop_vlan *)&nfp_fl->action_data[*a_len];
nfp_fl->meta.shortcut = cpu_to_be32(NFP_FL_SC_ACT_POPV);
nfp_fl_pop_vlan(pop_v);
*a_len += sizeof(struct nfp_fl_pop_vlan);
} else if (is_tcf_vlan(a) && tcf_vlan_action(a) == TCA_VLAN_ACT_PUSH) {
if (*a_len + sizeof(struct nfp_fl_push_vlan) > NFP_FL_MAX_A_SIZ)
return -EOPNOTSUPP;
psh_v = (struct nfp_fl_push_vlan *)&nfp_fl->action_data[*a_len];
nfp_fl->meta.shortcut = cpu_to_be32(NFP_FL_SC_ACT_NULL);
nfp_fl_push_vlan(psh_v, a);
*a_len += sizeof(struct nfp_fl_push_vlan);
} else {
return -EOPNOTSUPP;
}
return 0;
}
int nfp_flower_compile_action(struct tc_cls_flower_offload *flow,
struct net_device *netdev,
struct nfp_fl_payload *nfp_flow)
{
int act_len, act_cnt, err;
const struct tc_action *a;
LIST_HEAD(actions);
memset(nfp_flow->action_data, 0, NFP_FL_MAX_A_SIZ);
nfp_flow->meta.act_len = 0;
act_len = 0;
act_cnt = 0;
tcf_exts_to_list(flow->exts, &actions);
list_for_each_entry(a, &actions, list) {
err = nfp_flower_loop_action(a, nfp_flow, &act_len, netdev);
if (err)
return err;
act_cnt++;
}
if (act_cnt > 1)
nfp_flow->meta.shortcut = cpu_to_be32(NFP_FL_SC_ACT_NULL);
nfp_flow->meta.act_len = act_len;
return 0;
}
