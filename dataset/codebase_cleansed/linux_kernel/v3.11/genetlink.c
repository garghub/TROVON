void genl_lock(void)
{
mutex_lock(&genl_mutex);
}
void genl_unlock(void)
{
mutex_unlock(&genl_mutex);
}
int lockdep_genl_is_held(void)
{
return lockdep_is_held(&genl_mutex);
}
static void genl_lock_all(void)
{
down_write(&cb_lock);
genl_lock();
}
static void genl_unlock_all(void)
{
genl_unlock();
up_write(&cb_lock);
}
static inline unsigned int genl_family_hash(unsigned int id)
{
return id & GENL_FAM_TAB_MASK;
}
static inline struct list_head *genl_family_chain(unsigned int id)
{
return &family_ht[genl_family_hash(id)];
}
static struct genl_family *genl_family_find_byid(unsigned int id)
{
struct genl_family *f;
list_for_each_entry(f, genl_family_chain(id), family_list)
if (f->id == id)
return f;
return NULL;
}
static struct genl_family *genl_family_find_byname(char *name)
{
struct genl_family *f;
int i;
for (i = 0; i < GENL_FAM_TAB_SIZE; i++)
list_for_each_entry(f, genl_family_chain(i), family_list)
if (strcmp(f->name, name) == 0)
return f;
return NULL;
}
static struct genl_ops *genl_get_cmd(u8 cmd, struct genl_family *family)
{
struct genl_ops *ops;
list_for_each_entry(ops, &family->ops_list, ops_list)
if (ops->cmd == cmd)
return ops;
return NULL;
}
static u16 genl_generate_id(void)
{
static u16 id_gen_idx = GENL_MIN_ID;
int i;
for (i = 0; i <= GENL_MAX_ID - GENL_MIN_ID; i++) {
if (!genl_family_find_byid(id_gen_idx))
return id_gen_idx;
if (++id_gen_idx > GENL_MAX_ID)
id_gen_idx = GENL_MIN_ID;
}
return 0;
}
int genl_register_mc_group(struct genl_family *family,
struct genl_multicast_group *grp)
{
int id;
unsigned long *new_groups;
int err = 0;
BUG_ON(grp->name[0] == '\0');
BUG_ON(memchr(grp->name, '\0', GENL_NAMSIZ) == NULL);
genl_lock_all();
if (grp == &notify_grp)
id = GENL_ID_CTRL;
else
id = find_first_zero_bit(mc_groups,
mc_groups_longs * BITS_PER_LONG);
if (id >= mc_groups_longs * BITS_PER_LONG) {
size_t nlen = (mc_groups_longs + 1) * sizeof(unsigned long);
if (mc_groups == &mc_group_start) {
new_groups = kzalloc(nlen, GFP_KERNEL);
if (!new_groups) {
err = -ENOMEM;
goto out;
}
mc_groups = new_groups;
*mc_groups = mc_group_start;
} else {
new_groups = krealloc(mc_groups, nlen, GFP_KERNEL);
if (!new_groups) {
err = -ENOMEM;
goto out;
}
mc_groups = new_groups;
mc_groups[mc_groups_longs] = 0;
}
mc_groups_longs++;
}
if (family->netnsok) {
struct net *net;
netlink_table_grab();
rcu_read_lock();
for_each_net_rcu(net) {
err = __netlink_change_ngroups(net->genl_sock,
mc_groups_longs * BITS_PER_LONG);
if (err) {
rcu_read_unlock();
netlink_table_ungrab();
goto out;
}
}
rcu_read_unlock();
netlink_table_ungrab();
} else {
err = netlink_change_ngroups(init_net.genl_sock,
mc_groups_longs * BITS_PER_LONG);
if (err)
goto out;
}
grp->id = id;
set_bit(id, mc_groups);
list_add_tail(&grp->list, &family->mcast_groups);
grp->family = family;
genl_ctrl_event(CTRL_CMD_NEWMCAST_GRP, grp);
out:
genl_unlock_all();
return err;
}
static void __genl_unregister_mc_group(struct genl_family *family,
struct genl_multicast_group *grp)
{
struct net *net;
BUG_ON(grp->family != family);
netlink_table_grab();
rcu_read_lock();
for_each_net_rcu(net)
__netlink_clear_multicast_users(net->genl_sock, grp->id);
rcu_read_unlock();
netlink_table_ungrab();
clear_bit(grp->id, mc_groups);
list_del(&grp->list);
genl_ctrl_event(CTRL_CMD_DELMCAST_GRP, grp);
grp->id = 0;
grp->family = NULL;
}
void genl_unregister_mc_group(struct genl_family *family,
struct genl_multicast_group *grp)
{
genl_lock_all();
__genl_unregister_mc_group(family, grp);
genl_unlock_all();
}
static void genl_unregister_mc_groups(struct genl_family *family)
{
struct genl_multicast_group *grp, *tmp;
list_for_each_entry_safe(grp, tmp, &family->mcast_groups, list)
__genl_unregister_mc_group(family, grp);
}
int genl_register_ops(struct genl_family *family, struct genl_ops *ops)
{
int err = -EINVAL;
if (ops->dumpit == NULL && ops->doit == NULL)
goto errout;
if (genl_get_cmd(ops->cmd, family)) {
err = -EEXIST;
goto errout;
}
if (ops->dumpit)
ops->flags |= GENL_CMD_CAP_DUMP;
if (ops->doit)
ops->flags |= GENL_CMD_CAP_DO;
if (ops->policy)
ops->flags |= GENL_CMD_CAP_HASPOL;
genl_lock_all();
list_add_tail(&ops->ops_list, &family->ops_list);
genl_unlock_all();
genl_ctrl_event(CTRL_CMD_NEWOPS, ops);
err = 0;
errout:
return err;
}
int genl_unregister_ops(struct genl_family *family, struct genl_ops *ops)
{
struct genl_ops *rc;
genl_lock_all();
list_for_each_entry(rc, &family->ops_list, ops_list) {
if (rc == ops) {
list_del(&ops->ops_list);
genl_unlock_all();
genl_ctrl_event(CTRL_CMD_DELOPS, ops);
return 0;
}
}
genl_unlock_all();
return -ENOENT;
}
int __genl_register_family(struct genl_family *family)
{
int err = -EINVAL;
if (family->id && family->id < GENL_MIN_ID)
goto errout;
if (family->id > GENL_MAX_ID)
goto errout;
INIT_LIST_HEAD(&family->ops_list);
INIT_LIST_HEAD(&family->mcast_groups);
genl_lock_all();
if (genl_family_find_byname(family->name)) {
err = -EEXIST;
goto errout_locked;
}
if (family->id == GENL_ID_GENERATE) {
u16 newid = genl_generate_id();
if (!newid) {
err = -ENOMEM;
goto errout_locked;
}
family->id = newid;
} else if (genl_family_find_byid(family->id)) {
err = -EEXIST;
goto errout_locked;
}
if (family->maxattr && !family->parallel_ops) {
family->attrbuf = kmalloc((family->maxattr+1) *
sizeof(struct nlattr *), GFP_KERNEL);
if (family->attrbuf == NULL) {
err = -ENOMEM;
goto errout_locked;
}
} else
family->attrbuf = NULL;
list_add_tail(&family->family_list, genl_family_chain(family->id));
genl_unlock_all();
genl_ctrl_event(CTRL_CMD_NEWFAMILY, family);
return 0;
errout_locked:
genl_unlock_all();
errout:
return err;
}
int __genl_register_family_with_ops(struct genl_family *family,
struct genl_ops *ops, size_t n_ops)
{
int err, i;
err = __genl_register_family(family);
if (err)
return err;
for (i = 0; i < n_ops; ++i, ++ops) {
err = genl_register_ops(family, ops);
if (err)
goto err_out;
}
return 0;
err_out:
genl_unregister_family(family);
return err;
}
int genl_unregister_family(struct genl_family *family)
{
struct genl_family *rc;
genl_lock_all();
genl_unregister_mc_groups(family);
list_for_each_entry(rc, genl_family_chain(family->id), family_list) {
if (family->id != rc->id || strcmp(rc->name, family->name))
continue;
list_del(&rc->family_list);
INIT_LIST_HEAD(&family->ops_list);
genl_unlock_all();
kfree(family->attrbuf);
genl_ctrl_event(CTRL_CMD_DELFAMILY, family);
return 0;
}
genl_unlock_all();
return -ENOENT;
}
void *genlmsg_put(struct sk_buff *skb, u32 portid, u32 seq,
struct genl_family *family, int flags, u8 cmd)
{
struct nlmsghdr *nlh;
struct genlmsghdr *hdr;
nlh = nlmsg_put(skb, portid, seq, family->id, GENL_HDRLEN +
family->hdrsize, flags);
if (nlh == NULL)
return NULL;
hdr = nlmsg_data(nlh);
hdr->cmd = cmd;
hdr->version = family->version;
hdr->reserved = 0;
return (char *) hdr + GENL_HDRLEN;
}
static int genl_lock_dumpit(struct sk_buff *skb, struct netlink_callback *cb)
{
struct genl_ops *ops = cb->data;
int rc;
genl_lock();
rc = ops->dumpit(skb, cb);
genl_unlock();
return rc;
}
static int genl_lock_done(struct netlink_callback *cb)
{
struct genl_ops *ops = cb->data;
int rc = 0;
if (ops->done) {
genl_lock();
rc = ops->done(cb);
genl_unlock();
}
return rc;
}
static int genl_family_rcv_msg(struct genl_family *family,
struct sk_buff *skb,
struct nlmsghdr *nlh)
{
struct genl_ops *ops;
struct net *net = sock_net(skb->sk);
struct genl_info info;
struct genlmsghdr *hdr = nlmsg_data(nlh);
struct nlattr **attrbuf;
int hdrlen, err;
if (!family->netnsok && !net_eq(net, &init_net))
return -ENOENT;
hdrlen = GENL_HDRLEN + family->hdrsize;
if (nlh->nlmsg_len < nlmsg_msg_size(hdrlen))
return -EINVAL;
ops = genl_get_cmd(hdr->cmd, family);
if (ops == NULL)
return -EOPNOTSUPP;
if ((ops->flags & GENL_ADMIN_PERM) &&
!capable(CAP_NET_ADMIN))
return -EPERM;
if ((nlh->nlmsg_flags & NLM_F_DUMP) == NLM_F_DUMP) {
int rc;
if (ops->dumpit == NULL)
return -EOPNOTSUPP;
if (!family->parallel_ops) {
struct netlink_dump_control c = {
.module = family->module,
.data = ops,
.dump = genl_lock_dumpit,
.done = genl_lock_done,
};
genl_unlock();
rc = __netlink_dump_start(net->genl_sock, skb, nlh, &c);
genl_lock();
} else {
struct netlink_dump_control c = {
.module = family->module,
.dump = ops->dumpit,
.done = ops->done,
};
rc = __netlink_dump_start(net->genl_sock, skb, nlh, &c);
}
return rc;
}
if (ops->doit == NULL)
return -EOPNOTSUPP;
if (family->maxattr && family->parallel_ops) {
attrbuf = kmalloc((family->maxattr+1) *
sizeof(struct nlattr *), GFP_KERNEL);
if (attrbuf == NULL)
return -ENOMEM;
} else
attrbuf = family->attrbuf;
if (attrbuf) {
err = nlmsg_parse(nlh, hdrlen, attrbuf, family->maxattr,
ops->policy);
if (err < 0)
goto out;
}
info.snd_seq = nlh->nlmsg_seq;
info.snd_portid = NETLINK_CB(skb).portid;
info.nlhdr = nlh;
info.genlhdr = nlmsg_data(nlh);
info.userhdr = nlmsg_data(nlh) + GENL_HDRLEN;
info.attrs = attrbuf;
genl_info_net_set(&info, net);
memset(&info.user_ptr, 0, sizeof(info.user_ptr));
if (family->pre_doit) {
err = family->pre_doit(ops, skb, &info);
if (err)
goto out;
}
err = ops->doit(skb, &info);
if (family->post_doit)
family->post_doit(ops, skb, &info);
out:
if (family->parallel_ops)
kfree(attrbuf);
return err;
}
static int genl_rcv_msg(struct sk_buff *skb, struct nlmsghdr *nlh)
{
struct genl_family *family;
int err;
family = genl_family_find_byid(nlh->nlmsg_type);
if (family == NULL)
return -ENOENT;
if (!family->parallel_ops)
genl_lock();
err = genl_family_rcv_msg(family, skb, nlh);
if (!family->parallel_ops)
genl_unlock();
return err;
}
static void genl_rcv(struct sk_buff *skb)
{
down_read(&cb_lock);
netlink_rcv_skb(skb, &genl_rcv_msg);
up_read(&cb_lock);
}
static int ctrl_fill_info(struct genl_family *family, u32 portid, u32 seq,
u32 flags, struct sk_buff *skb, u8 cmd)
{
void *hdr;
hdr = genlmsg_put(skb, portid, seq, &genl_ctrl, flags, cmd);
if (hdr == NULL)
return -1;
if (nla_put_string(skb, CTRL_ATTR_FAMILY_NAME, family->name) ||
nla_put_u16(skb, CTRL_ATTR_FAMILY_ID, family->id) ||
nla_put_u32(skb, CTRL_ATTR_VERSION, family->version) ||
nla_put_u32(skb, CTRL_ATTR_HDRSIZE, family->hdrsize) ||
nla_put_u32(skb, CTRL_ATTR_MAXATTR, family->maxattr))
goto nla_put_failure;
if (!list_empty(&family->ops_list)) {
struct nlattr *nla_ops;
struct genl_ops *ops;
int idx = 1;
nla_ops = nla_nest_start(skb, CTRL_ATTR_OPS);
if (nla_ops == NULL)
goto nla_put_failure;
list_for_each_entry(ops, &family->ops_list, ops_list) {
struct nlattr *nest;
nest = nla_nest_start(skb, idx++);
if (nest == NULL)
goto nla_put_failure;
if (nla_put_u32(skb, CTRL_ATTR_OP_ID, ops->cmd) ||
nla_put_u32(skb, CTRL_ATTR_OP_FLAGS, ops->flags))
goto nla_put_failure;
nla_nest_end(skb, nest);
}
nla_nest_end(skb, nla_ops);
}
if (!list_empty(&family->mcast_groups)) {
struct genl_multicast_group *grp;
struct nlattr *nla_grps;
int idx = 1;
nla_grps = nla_nest_start(skb, CTRL_ATTR_MCAST_GROUPS);
if (nla_grps == NULL)
goto nla_put_failure;
list_for_each_entry(grp, &family->mcast_groups, list) {
struct nlattr *nest;
nest = nla_nest_start(skb, idx++);
if (nest == NULL)
goto nla_put_failure;
if (nla_put_u32(skb, CTRL_ATTR_MCAST_GRP_ID, grp->id) ||
nla_put_string(skb, CTRL_ATTR_MCAST_GRP_NAME,
grp->name))
goto nla_put_failure;
nla_nest_end(skb, nest);
}
nla_nest_end(skb, nla_grps);
}
return genlmsg_end(skb, hdr);
nla_put_failure:
genlmsg_cancel(skb, hdr);
return -EMSGSIZE;
}
static int ctrl_fill_mcgrp_info(struct genl_multicast_group *grp, u32 portid,
u32 seq, u32 flags, struct sk_buff *skb,
u8 cmd)
{
void *hdr;
struct nlattr *nla_grps;
struct nlattr *nest;
hdr = genlmsg_put(skb, portid, seq, &genl_ctrl, flags, cmd);
if (hdr == NULL)
return -1;
if (nla_put_string(skb, CTRL_ATTR_FAMILY_NAME, grp->family->name) ||
nla_put_u16(skb, CTRL_ATTR_FAMILY_ID, grp->family->id))
goto nla_put_failure;
nla_grps = nla_nest_start(skb, CTRL_ATTR_MCAST_GROUPS);
if (nla_grps == NULL)
goto nla_put_failure;
nest = nla_nest_start(skb, 1);
if (nest == NULL)
goto nla_put_failure;
if (nla_put_u32(skb, CTRL_ATTR_MCAST_GRP_ID, grp->id) ||
nla_put_string(skb, CTRL_ATTR_MCAST_GRP_NAME,
grp->name))
goto nla_put_failure;
nla_nest_end(skb, nest);
nla_nest_end(skb, nla_grps);
return genlmsg_end(skb, hdr);
nla_put_failure:
genlmsg_cancel(skb, hdr);
return -EMSGSIZE;
}
static int ctrl_dumpfamily(struct sk_buff *skb, struct netlink_callback *cb)
{
int i, n = 0;
struct genl_family *rt;
struct net *net = sock_net(skb->sk);
int chains_to_skip = cb->args[0];
int fams_to_skip = cb->args[1];
for (i = chains_to_skip; i < GENL_FAM_TAB_SIZE; i++) {
n = 0;
list_for_each_entry(rt, genl_family_chain(i), family_list) {
if (!rt->netnsok && !net_eq(net, &init_net))
continue;
if (++n < fams_to_skip)
continue;
if (ctrl_fill_info(rt, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, NLM_F_MULTI,
skb, CTRL_CMD_NEWFAMILY) < 0)
goto errout;
}
fams_to_skip = 0;
}
errout:
cb->args[0] = i;
cb->args[1] = n;
return skb->len;
}
static struct sk_buff *ctrl_build_family_msg(struct genl_family *family,
u32 portid, int seq, u8 cmd)
{
struct sk_buff *skb;
int err;
skb = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (skb == NULL)
return ERR_PTR(-ENOBUFS);
err = ctrl_fill_info(family, portid, seq, 0, skb, cmd);
if (err < 0) {
nlmsg_free(skb);
return ERR_PTR(err);
}
return skb;
}
static struct sk_buff *ctrl_build_mcgrp_msg(struct genl_multicast_group *grp,
u32 portid, int seq, u8 cmd)
{
struct sk_buff *skb;
int err;
skb = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (skb == NULL)
return ERR_PTR(-ENOBUFS);
err = ctrl_fill_mcgrp_info(grp, portid, seq, 0, skb, cmd);
if (err < 0) {
nlmsg_free(skb);
return ERR_PTR(err);
}
return skb;
}
static int ctrl_getfamily(struct sk_buff *skb, struct genl_info *info)
{
struct sk_buff *msg;
struct genl_family *res = NULL;
int err = -EINVAL;
if (info->attrs[CTRL_ATTR_FAMILY_ID]) {
u16 id = nla_get_u16(info->attrs[CTRL_ATTR_FAMILY_ID]);
res = genl_family_find_byid(id);
err = -ENOENT;
}
if (info->attrs[CTRL_ATTR_FAMILY_NAME]) {
char *name;
name = nla_data(info->attrs[CTRL_ATTR_FAMILY_NAME]);
res = genl_family_find_byname(name);
#ifdef CONFIG_MODULES
if (res == NULL) {
genl_unlock();
up_read(&cb_lock);
request_module("net-pf-%d-proto-%d-family-%s",
PF_NETLINK, NETLINK_GENERIC, name);
down_read(&cb_lock);
genl_lock();
res = genl_family_find_byname(name);
}
#endif
err = -ENOENT;
}
if (res == NULL)
return err;
if (!res->netnsok && !net_eq(genl_info_net(info), &init_net)) {
return -ENOENT;
}
msg = ctrl_build_family_msg(res, info->snd_portid, info->snd_seq,
CTRL_CMD_NEWFAMILY);
if (IS_ERR(msg))
return PTR_ERR(msg);
return genlmsg_reply(msg, info);
}
static int genl_ctrl_event(int event, void *data)
{
struct sk_buff *msg;
struct genl_family *family;
struct genl_multicast_group *grp;
if (!init_net.genl_sock)
return 0;
switch (event) {
case CTRL_CMD_NEWFAMILY:
case CTRL_CMD_DELFAMILY:
family = data;
msg = ctrl_build_family_msg(family, 0, 0, event);
break;
case CTRL_CMD_NEWMCAST_GRP:
case CTRL_CMD_DELMCAST_GRP:
grp = data;
family = grp->family;
msg = ctrl_build_mcgrp_msg(data, 0, 0, event);
break;
default:
return -EINVAL;
}
if (IS_ERR(msg))
return PTR_ERR(msg);
if (!family->netnsok) {
genlmsg_multicast_netns(&init_net, msg, 0,
GENL_ID_CTRL, GFP_KERNEL);
} else {
rcu_read_lock();
genlmsg_multicast_allns(msg, 0, GENL_ID_CTRL, GFP_ATOMIC);
rcu_read_unlock();
}
return 0;
}
static int __net_init genl_pernet_init(struct net *net)
{
struct netlink_kernel_cfg cfg = {
.input = genl_rcv,
.flags = NL_CFG_F_NONROOT_RECV,
};
net->genl_sock = netlink_kernel_create(net, NETLINK_GENERIC, &cfg);
if (!net->genl_sock && net_eq(net, &init_net))
panic("GENL: Cannot initialize generic netlink\n");
if (!net->genl_sock)
return -ENOMEM;
return 0;
}
static void __net_exit genl_pernet_exit(struct net *net)
{
netlink_kernel_release(net->genl_sock);
net->genl_sock = NULL;
}
static int __init genl_init(void)
{
int i, err;
for (i = 0; i < GENL_FAM_TAB_SIZE; i++)
INIT_LIST_HEAD(&family_ht[i]);
err = genl_register_family_with_ops(&genl_ctrl, &genl_ctrl_ops, 1);
if (err < 0)
goto problem;
err = register_pernet_subsys(&genl_pernet_ops);
if (err)
goto problem;
err = genl_register_mc_group(&genl_ctrl, &notify_grp);
if (err < 0)
goto problem;
return 0;
problem:
panic("GENL: Cannot register controller: %d\n", err);
}
static int genlmsg_mcast(struct sk_buff *skb, u32 portid, unsigned long group,
gfp_t flags)
{
struct sk_buff *tmp;
struct net *net, *prev = NULL;
int err;
for_each_net_rcu(net) {
if (prev) {
tmp = skb_clone(skb, flags);
if (!tmp) {
err = -ENOMEM;
goto error;
}
err = nlmsg_multicast(prev->genl_sock, tmp,
portid, group, flags);
if (err)
goto error;
}
prev = net;
}
return nlmsg_multicast(prev->genl_sock, skb, portid, group, flags);
error:
kfree_skb(skb);
return err;
}
int genlmsg_multicast_allns(struct sk_buff *skb, u32 portid, unsigned int group,
gfp_t flags)
{
return genlmsg_mcast(skb, portid, group, flags);
}
void genl_notify(struct sk_buff *skb, struct net *net, u32 portid, u32 group,
struct nlmsghdr *nlh, gfp_t flags)
{
struct sock *sk = net->genl_sock;
int report = 0;
if (nlh)
report = nlmsg_report(nlh);
nlmsg_notify(sk, skb, portid, group, report, flags);
}
