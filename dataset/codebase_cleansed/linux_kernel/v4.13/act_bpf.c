static int tcf_bpf(struct sk_buff *skb, const struct tc_action *act,
struct tcf_result *res)
{
bool at_ingress = skb_at_tc_ingress(skb);
struct tcf_bpf *prog = to_bpf(act);
struct bpf_prog *filter;
int action, filter_res;
tcf_lastuse_update(&prog->tcf_tm);
bstats_cpu_update(this_cpu_ptr(prog->common.cpu_bstats), skb);
rcu_read_lock();
filter = rcu_dereference(prog->filter);
if (at_ingress) {
__skb_push(skb, skb->mac_len);
bpf_compute_data_end(skb);
filter_res = BPF_PROG_RUN(filter, skb);
__skb_pull(skb, skb->mac_len);
} else {
bpf_compute_data_end(skb);
filter_res = BPF_PROG_RUN(filter, skb);
}
rcu_read_unlock();
switch (filter_res) {
case TC_ACT_PIPE:
case TC_ACT_RECLASSIFY:
case TC_ACT_OK:
case TC_ACT_REDIRECT:
action = filter_res;
break;
case TC_ACT_SHOT:
action = filter_res;
qstats_drop_inc(this_cpu_ptr(prog->common.cpu_qstats));
break;
case TC_ACT_UNSPEC:
action = prog->tcf_action;
break;
default:
action = TC_ACT_UNSPEC;
break;
}
return action;
}
static bool tcf_bpf_is_ebpf(const struct tcf_bpf *prog)
{
return !prog->bpf_ops;
}
static int tcf_bpf_dump_bpf_info(const struct tcf_bpf *prog,
struct sk_buff *skb)
{
struct nlattr *nla;
if (nla_put_u16(skb, TCA_ACT_BPF_OPS_LEN, prog->bpf_num_ops))
return -EMSGSIZE;
nla = nla_reserve(skb, TCA_ACT_BPF_OPS, prog->bpf_num_ops *
sizeof(struct sock_filter));
if (nla == NULL)
return -EMSGSIZE;
memcpy(nla_data(nla), prog->bpf_ops, nla_len(nla));
return 0;
}
static int tcf_bpf_dump_ebpf_info(const struct tcf_bpf *prog,
struct sk_buff *skb)
{
struct nlattr *nla;
if (prog->bpf_name &&
nla_put_string(skb, TCA_ACT_BPF_NAME, prog->bpf_name))
return -EMSGSIZE;
if (nla_put_u32(skb, TCA_ACT_BPF_ID, prog->filter->aux->id))
return -EMSGSIZE;
nla = nla_reserve(skb, TCA_ACT_BPF_TAG, sizeof(prog->filter->tag));
if (nla == NULL)
return -EMSGSIZE;
memcpy(nla_data(nla), prog->filter->tag, nla_len(nla));
return 0;
}
static int tcf_bpf_dump(struct sk_buff *skb, struct tc_action *act,
int bind, int ref)
{
unsigned char *tp = skb_tail_pointer(skb);
struct tcf_bpf *prog = to_bpf(act);
struct tc_act_bpf opt = {
.index = prog->tcf_index,
.refcnt = prog->tcf_refcnt - ref,
.bindcnt = prog->tcf_bindcnt - bind,
.action = prog->tcf_action,
};
struct tcf_t tm;
int ret;
if (nla_put(skb, TCA_ACT_BPF_PARMS, sizeof(opt), &opt))
goto nla_put_failure;
if (tcf_bpf_is_ebpf(prog))
ret = tcf_bpf_dump_ebpf_info(prog, skb);
else
ret = tcf_bpf_dump_bpf_info(prog, skb);
if (ret)
goto nla_put_failure;
tcf_tm_dump(&tm, &prog->tcf_tm);
if (nla_put_64bit(skb, TCA_ACT_BPF_TM, sizeof(tm), &tm,
TCA_ACT_BPF_PAD))
goto nla_put_failure;
return skb->len;
nla_put_failure:
nlmsg_trim(skb, tp);
return -1;
}
static int tcf_bpf_init_from_ops(struct nlattr **tb, struct tcf_bpf_cfg *cfg)
{
struct sock_filter *bpf_ops;
struct sock_fprog_kern fprog_tmp;
struct bpf_prog *fp;
u16 bpf_size, bpf_num_ops;
int ret;
bpf_num_ops = nla_get_u16(tb[TCA_ACT_BPF_OPS_LEN]);
if (bpf_num_ops > BPF_MAXINSNS || bpf_num_ops == 0)
return -EINVAL;
bpf_size = bpf_num_ops * sizeof(*bpf_ops);
if (bpf_size != nla_len(tb[TCA_ACT_BPF_OPS]))
return -EINVAL;
bpf_ops = kzalloc(bpf_size, GFP_KERNEL);
if (bpf_ops == NULL)
return -ENOMEM;
memcpy(bpf_ops, nla_data(tb[TCA_ACT_BPF_OPS]), bpf_size);
fprog_tmp.len = bpf_num_ops;
fprog_tmp.filter = bpf_ops;
ret = bpf_prog_create(&fp, &fprog_tmp);
if (ret < 0) {
kfree(bpf_ops);
return ret;
}
cfg->bpf_ops = bpf_ops;
cfg->bpf_num_ops = bpf_num_ops;
cfg->filter = fp;
cfg->is_ebpf = false;
return 0;
}
static int tcf_bpf_init_from_efd(struct nlattr **tb, struct tcf_bpf_cfg *cfg)
{
struct bpf_prog *fp;
char *name = NULL;
u32 bpf_fd;
bpf_fd = nla_get_u32(tb[TCA_ACT_BPF_FD]);
fp = bpf_prog_get_type(bpf_fd, BPF_PROG_TYPE_SCHED_ACT);
if (IS_ERR(fp))
return PTR_ERR(fp);
if (tb[TCA_ACT_BPF_NAME]) {
name = nla_memdup(tb[TCA_ACT_BPF_NAME], GFP_KERNEL);
if (!name) {
bpf_prog_put(fp);
return -ENOMEM;
}
}
cfg->bpf_name = name;
cfg->filter = fp;
cfg->is_ebpf = true;
return 0;
}
static void tcf_bpf_cfg_cleanup(const struct tcf_bpf_cfg *cfg)
{
if (cfg->is_ebpf)
bpf_prog_put(cfg->filter);
else
bpf_prog_destroy(cfg->filter);
kfree(cfg->bpf_ops);
kfree(cfg->bpf_name);
}
static void tcf_bpf_prog_fill_cfg(const struct tcf_bpf *prog,
struct tcf_bpf_cfg *cfg)
{
cfg->is_ebpf = tcf_bpf_is_ebpf(prog);
cfg->filter = rcu_dereference_protected(prog->filter, 1);
cfg->bpf_ops = prog->bpf_ops;
cfg->bpf_name = prog->bpf_name;
}
static int tcf_bpf_init(struct net *net, struct nlattr *nla,
struct nlattr *est, struct tc_action **act,
int replace, int bind)
{
struct tc_action_net *tn = net_generic(net, bpf_net_id);
struct nlattr *tb[TCA_ACT_BPF_MAX + 1];
struct tcf_bpf_cfg cfg, old;
struct tc_act_bpf *parm;
struct tcf_bpf *prog;
bool is_bpf, is_ebpf;
int ret, res = 0;
if (!nla)
return -EINVAL;
ret = nla_parse_nested(tb, TCA_ACT_BPF_MAX, nla, act_bpf_policy, NULL);
if (ret < 0)
return ret;
if (!tb[TCA_ACT_BPF_PARMS])
return -EINVAL;
parm = nla_data(tb[TCA_ACT_BPF_PARMS]);
if (!tcf_hash_check(tn, parm->index, act, bind)) {
ret = tcf_hash_create(tn, parm->index, est, act,
&act_bpf_ops, bind, true);
if (ret < 0)
return ret;
res = ACT_P_CREATED;
} else {
if (bind)
return 0;
tcf_hash_release(*act, bind);
if (!replace)
return -EEXIST;
}
is_bpf = tb[TCA_ACT_BPF_OPS_LEN] && tb[TCA_ACT_BPF_OPS];
is_ebpf = tb[TCA_ACT_BPF_FD];
if ((!is_bpf && !is_ebpf) || (is_bpf && is_ebpf)) {
ret = -EINVAL;
goto out;
}
memset(&cfg, 0, sizeof(cfg));
ret = is_bpf ? tcf_bpf_init_from_ops(tb, &cfg) :
tcf_bpf_init_from_efd(tb, &cfg);
if (ret < 0)
goto out;
prog = to_bpf(*act);
ASSERT_RTNL();
if (res != ACT_P_CREATED)
tcf_bpf_prog_fill_cfg(prog, &old);
prog->bpf_ops = cfg.bpf_ops;
prog->bpf_name = cfg.bpf_name;
if (cfg.bpf_num_ops)
prog->bpf_num_ops = cfg.bpf_num_ops;
prog->tcf_action = parm->action;
rcu_assign_pointer(prog->filter, cfg.filter);
if (res == ACT_P_CREATED) {
tcf_hash_insert(tn, *act);
} else {
synchronize_rcu();
tcf_bpf_cfg_cleanup(&old);
}
return res;
out:
if (res == ACT_P_CREATED)
tcf_hash_cleanup(*act, est);
return ret;
}
static void tcf_bpf_cleanup(struct tc_action *act, int bind)
{
struct tcf_bpf_cfg tmp;
tcf_bpf_prog_fill_cfg(to_bpf(act), &tmp);
tcf_bpf_cfg_cleanup(&tmp);
}
static int tcf_bpf_walker(struct net *net, struct sk_buff *skb,
struct netlink_callback *cb, int type,
const struct tc_action_ops *ops)
{
struct tc_action_net *tn = net_generic(net, bpf_net_id);
return tcf_generic_walker(tn, skb, cb, type, ops);
}
static int tcf_bpf_search(struct net *net, struct tc_action **a, u32 index)
{
struct tc_action_net *tn = net_generic(net, bpf_net_id);
return tcf_hash_search(tn, a, index);
}
static __net_init int bpf_init_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, bpf_net_id);
return tc_action_net_init(tn, &act_bpf_ops, BPF_TAB_MASK);
}
static void __net_exit bpf_exit_net(struct net *net)
{
struct tc_action_net *tn = net_generic(net, bpf_net_id);
tc_action_net_exit(tn);
}
static int __init bpf_init_module(void)
{
return tcf_register_action(&act_bpf_ops, &bpf_net_ops);
}
static void __exit bpf_cleanup_module(void)
{
tcf_unregister_action(&act_bpf_ops, &bpf_net_ops);
}
