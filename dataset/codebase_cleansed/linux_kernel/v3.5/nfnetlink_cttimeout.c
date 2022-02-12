static int
ctnl_timeout_parse_policy(struct ctnl_timeout *timeout,
struct nf_conntrack_l4proto *l4proto,
const struct nlattr *attr)
{
int ret = 0;
if (likely(l4proto->ctnl_timeout.nlattr_to_obj)) {
struct nlattr *tb[l4proto->ctnl_timeout.nlattr_max+1];
nla_parse_nested(tb, l4proto->ctnl_timeout.nlattr_max,
attr, l4proto->ctnl_timeout.nla_policy);
ret = l4proto->ctnl_timeout.nlattr_to_obj(tb, &timeout->data);
}
return ret;
}
static int
cttimeout_new_timeout(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const cda[])
{
__u16 l3num;
__u8 l4num;
struct nf_conntrack_l4proto *l4proto;
struct ctnl_timeout *timeout, *matching = NULL;
char *name;
int ret;
if (!cda[CTA_TIMEOUT_NAME] ||
!cda[CTA_TIMEOUT_L3PROTO] ||
!cda[CTA_TIMEOUT_L4PROTO] ||
!cda[CTA_TIMEOUT_DATA])
return -EINVAL;
name = nla_data(cda[CTA_TIMEOUT_NAME]);
l3num = ntohs(nla_get_be16(cda[CTA_TIMEOUT_L3PROTO]));
l4num = nla_get_u8(cda[CTA_TIMEOUT_L4PROTO]);
list_for_each_entry(timeout, &cttimeout_list, head) {
if (strncmp(timeout->name, name, CTNL_TIMEOUT_NAME_MAX) != 0)
continue;
if (nlh->nlmsg_flags & NLM_F_EXCL)
return -EEXIST;
matching = timeout;
break;
}
l4proto = nf_ct_l4proto_find_get(l3num, l4num);
if (l4proto->l4proto != l4num) {
ret = -EOPNOTSUPP;
goto err_proto_put;
}
if (matching) {
if (nlh->nlmsg_flags & NLM_F_REPLACE) {
if (matching->l3num != l3num ||
matching->l4proto->l4proto != l4num) {
ret = -EINVAL;
goto err_proto_put;
}
ret = ctnl_timeout_parse_policy(matching, l4proto,
cda[CTA_TIMEOUT_DATA]);
return ret;
}
ret = -EBUSY;
goto err_proto_put;
}
timeout = kzalloc(sizeof(struct ctnl_timeout) +
l4proto->ctnl_timeout.obj_size, GFP_KERNEL);
if (timeout == NULL) {
ret = -ENOMEM;
goto err_proto_put;
}
ret = ctnl_timeout_parse_policy(timeout, l4proto,
cda[CTA_TIMEOUT_DATA]);
if (ret < 0)
goto err;
strcpy(timeout->name, nla_data(cda[CTA_TIMEOUT_NAME]));
timeout->l3num = l3num;
timeout->l4proto = l4proto;
atomic_set(&timeout->refcnt, 1);
list_add_tail_rcu(&timeout->head, &cttimeout_list);
return 0;
err:
kfree(timeout);
err_proto_put:
nf_ct_l4proto_put(l4proto);
return ret;
}
static int
ctnl_timeout_fill_info(struct sk_buff *skb, u32 pid, u32 seq, u32 type,
int event, struct ctnl_timeout *timeout)
{
struct nlmsghdr *nlh;
struct nfgenmsg *nfmsg;
unsigned int flags = pid ? NLM_F_MULTI : 0;
struct nf_conntrack_l4proto *l4proto = timeout->l4proto;
event |= NFNL_SUBSYS_CTNETLINK_TIMEOUT << 8;
nlh = nlmsg_put(skb, pid, seq, event, sizeof(*nfmsg), flags);
if (nlh == NULL)
goto nlmsg_failure;
nfmsg = nlmsg_data(nlh);
nfmsg->nfgen_family = AF_UNSPEC;
nfmsg->version = NFNETLINK_V0;
nfmsg->res_id = 0;
if (nla_put_string(skb, CTA_TIMEOUT_NAME, timeout->name) ||
nla_put_be16(skb, CTA_TIMEOUT_L3PROTO, htons(timeout->l3num)) ||
nla_put_u8(skb, CTA_TIMEOUT_L4PROTO, timeout->l4proto->l4proto) ||
nla_put_be32(skb, CTA_TIMEOUT_USE,
htonl(atomic_read(&timeout->refcnt))))
goto nla_put_failure;
if (likely(l4proto->ctnl_timeout.obj_to_nlattr)) {
struct nlattr *nest_parms;
int ret;
nest_parms = nla_nest_start(skb,
CTA_TIMEOUT_DATA | NLA_F_NESTED);
if (!nest_parms)
goto nla_put_failure;
ret = l4proto->ctnl_timeout.obj_to_nlattr(skb, &timeout->data);
if (ret < 0)
goto nla_put_failure;
nla_nest_end(skb, nest_parms);
}
nlmsg_end(skb, nlh);
return skb->len;
nlmsg_failure:
nla_put_failure:
nlmsg_cancel(skb, nlh);
return -1;
}
static int
ctnl_timeout_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct ctnl_timeout *cur, *last;
if (cb->args[2])
return 0;
last = (struct ctnl_timeout *)cb->args[1];
if (cb->args[1])
cb->args[1] = 0;
rcu_read_lock();
list_for_each_entry_rcu(cur, &cttimeout_list, head) {
if (last && cur != last)
continue;
if (ctnl_timeout_fill_info(skb, NETLINK_CB(cb->skb).pid,
cb->nlh->nlmsg_seq,
NFNL_MSG_TYPE(cb->nlh->nlmsg_type),
IPCTNL_MSG_TIMEOUT_NEW, cur) < 0) {
cb->args[1] = (unsigned long)cur;
break;
}
}
if (!cb->args[1])
cb->args[2] = 1;
rcu_read_unlock();
return skb->len;
}
static int
cttimeout_get_timeout(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const cda[])
{
int ret = -ENOENT;
char *name;
struct ctnl_timeout *cur;
if (nlh->nlmsg_flags & NLM_F_DUMP) {
struct netlink_dump_control c = {
.dump = ctnl_timeout_dump,
};
return netlink_dump_start(ctnl, skb, nlh, &c);
}
if (!cda[CTA_TIMEOUT_NAME])
return -EINVAL;
name = nla_data(cda[CTA_TIMEOUT_NAME]);
list_for_each_entry(cur, &cttimeout_list, head) {
struct sk_buff *skb2;
if (strncmp(cur->name, name, CTNL_TIMEOUT_NAME_MAX) != 0)
continue;
skb2 = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (skb2 == NULL) {
ret = -ENOMEM;
break;
}
ret = ctnl_timeout_fill_info(skb2, NETLINK_CB(skb).pid,
nlh->nlmsg_seq,
NFNL_MSG_TYPE(nlh->nlmsg_type),
IPCTNL_MSG_TIMEOUT_NEW, cur);
if (ret <= 0) {
kfree_skb(skb2);
break;
}
ret = netlink_unicast(ctnl, skb2, NETLINK_CB(skb).pid,
MSG_DONTWAIT);
if (ret > 0)
ret = 0;
return ret == -EAGAIN ? -ENOBUFS : ret;
}
return ret;
}
static int ctnl_timeout_try_del(struct ctnl_timeout *timeout)
{
int ret = 0;
if (atomic_dec_and_test(&timeout->refcnt)) {
list_del_rcu(&timeout->head);
nf_ct_l4proto_put(timeout->l4proto);
kfree_rcu(timeout, rcu_head);
} else {
atomic_inc(&timeout->refcnt);
ret = -EBUSY;
}
return ret;
}
static int
cttimeout_del_timeout(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const cda[])
{
char *name;
struct ctnl_timeout *cur;
int ret = -ENOENT;
if (!cda[CTA_TIMEOUT_NAME]) {
list_for_each_entry(cur, &cttimeout_list, head)
ctnl_timeout_try_del(cur);
return 0;
}
name = nla_data(cda[CTA_TIMEOUT_NAME]);
list_for_each_entry(cur, &cttimeout_list, head) {
if (strncmp(cur->name, name, CTNL_TIMEOUT_NAME_MAX) != 0)
continue;
ret = ctnl_timeout_try_del(cur);
if (ret < 0)
return ret;
break;
}
return ret;
}
static struct ctnl_timeout *ctnl_timeout_find_get(const char *name)
{
struct ctnl_timeout *timeout, *matching = NULL;
rcu_read_lock();
list_for_each_entry_rcu(timeout, &cttimeout_list, head) {
if (strncmp(timeout->name, name, CTNL_TIMEOUT_NAME_MAX) != 0)
continue;
if (!try_module_get(THIS_MODULE))
goto err;
if (!atomic_inc_not_zero(&timeout->refcnt)) {
module_put(THIS_MODULE);
goto err;
}
matching = timeout;
break;
}
err:
rcu_read_unlock();
return matching;
}
static void ctnl_timeout_put(struct ctnl_timeout *timeout)
{
atomic_dec(&timeout->refcnt);
module_put(THIS_MODULE);
}
static int __init cttimeout_init(void)
{
int ret;
ret = nfnetlink_subsys_register(&cttimeout_subsys);
if (ret < 0) {
pr_err("cttimeout_init: cannot register cttimeout with "
"nfnetlink.\n");
goto err_out;
}
#ifdef CONFIG_NF_CONNTRACK_TIMEOUT
RCU_INIT_POINTER(nf_ct_timeout_find_get_hook, ctnl_timeout_find_get);
RCU_INIT_POINTER(nf_ct_timeout_put_hook, ctnl_timeout_put);
#endif
return 0;
err_out:
return ret;
}
static void __exit cttimeout_exit(void)
{
struct ctnl_timeout *cur, *tmp;
pr_info("cttimeout: unregistering from nfnetlink.\n");
nfnetlink_subsys_unregister(&cttimeout_subsys);
list_for_each_entry_safe(cur, tmp, &cttimeout_list, head) {
list_del_rcu(&cur->head);
nf_ct_l4proto_put(cur->l4proto);
kfree_rcu(cur, rcu_head);
}
#ifdef CONFIG_NF_CONNTRACK_TIMEOUT
RCU_INIT_POINTER(nf_ct_timeout_find_get_hook, NULL);
RCU_INIT_POINTER(nf_ct_timeout_put_hook, NULL);
#endif
}
