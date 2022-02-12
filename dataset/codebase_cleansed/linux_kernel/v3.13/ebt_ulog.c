static struct ebt_ulog_net *ebt_ulog_pernet(struct net *net)
{
return net_generic(net, ebt_ulog_net_id);
}
static void ulog_send(struct ebt_ulog_net *ebt, unsigned int nlgroup)
{
ebt_ulog_buff_t *ub = &ebt->ulog_buffers[nlgroup];
del_timer(&ub->timer);
if (!ub->skb)
return;
if (ub->qlen > 1)
ub->lastnlh->nlmsg_type = NLMSG_DONE;
NETLINK_CB(ub->skb).dst_group = nlgroup + 1;
netlink_broadcast(ebt->ebtulognl, ub->skb, 0, nlgroup + 1, GFP_ATOMIC);
ub->qlen = 0;
ub->skb = NULL;
}
static void ulog_timer(unsigned long data)
{
struct ebt_ulog_net *ebt = container_of((void *)data,
struct ebt_ulog_net,
nlgroup[*(unsigned int *)data]);
ebt_ulog_buff_t *ub = &ebt->ulog_buffers[*(unsigned int *)data];
spin_lock_bh(&ub->lock);
if (ub->skb)
ulog_send(ebt, *(unsigned int *)data);
spin_unlock_bh(&ub->lock);
}
static struct sk_buff *ulog_alloc_skb(unsigned int size)
{
struct sk_buff *skb;
unsigned int n;
n = max(size, nlbufsiz);
skb = alloc_skb(n, GFP_ATOMIC | __GFP_NOWARN);
if (!skb) {
if (n > size) {
skb = alloc_skb(size, GFP_ATOMIC);
if (!skb)
pr_debug("cannot even allocate buffer of size %ub\n",
size);
}
}
return skb;
}
static void ebt_ulog_packet(struct net *net, unsigned int hooknr,
const struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
const struct ebt_ulog_info *uloginfo,
const char *prefix)
{
ebt_ulog_packet_msg_t *pm;
size_t size, copy_len;
struct nlmsghdr *nlh;
struct ebt_ulog_net *ebt = ebt_ulog_pernet(net);
unsigned int group = uloginfo->nlgroup;
ebt_ulog_buff_t *ub = &ebt->ulog_buffers[group];
spinlock_t *lock = &ub->lock;
ktime_t kt;
if ((uloginfo->cprange == 0) ||
(uloginfo->cprange > skb->len + ETH_HLEN))
copy_len = skb->len + ETH_HLEN;
else
copy_len = uloginfo->cprange;
size = nlmsg_total_size(sizeof(*pm) + copy_len);
if (size > nlbufsiz) {
pr_debug("Size %Zd needed, but nlbufsiz=%d\n", size, nlbufsiz);
return;
}
spin_lock_bh(lock);
if (!ub->skb) {
if (!(ub->skb = ulog_alloc_skb(size)))
goto unlock;
} else if (size > skb_tailroom(ub->skb)) {
ulog_send(ebt, group);
if (!(ub->skb = ulog_alloc_skb(size)))
goto unlock;
}
nlh = nlmsg_put(ub->skb, 0, ub->qlen, 0,
size - NLMSG_ALIGN(sizeof(*nlh)), 0);
if (!nlh) {
kfree_skb(ub->skb);
ub->skb = NULL;
goto unlock;
}
ub->qlen++;
pm = nlmsg_data(nlh);
memset(pm, 0, sizeof(*pm));
pm->version = EBT_ULOG_VERSION;
kt = ktime_get_real();
pm->stamp = ktime_to_timeval(kt);
if (ub->qlen == 1)
ub->skb->tstamp = kt;
pm->data_len = copy_len;
pm->mark = skb->mark;
pm->hook = hooknr;
if (uloginfo->prefix != NULL)
strcpy(pm->prefix, uloginfo->prefix);
if (in) {
strcpy(pm->physindev, in->name);
if (br_port_exists(in))
strcpy(pm->indev, br_port_get_rcu(in)->br->dev->name);
else
strcpy(pm->indev, in->name);
}
if (out) {
strcpy(pm->physoutdev, out->name);
strcpy(pm->outdev, br_port_get_rcu(out)->br->dev->name);
}
if (skb_copy_bits(skb, -ETH_HLEN, pm->data, copy_len) < 0)
BUG();
if (ub->qlen > 1)
ub->lastnlh->nlmsg_flags |= NLM_F_MULTI;
ub->lastnlh = nlh;
if (ub->qlen >= uloginfo->qthreshold)
ulog_send(ebt, group);
else if (!timer_pending(&ub->timer)) {
ub->timer.expires = jiffies + flushtimeout * HZ / 100;
add_timer(&ub->timer);
}
unlock:
spin_unlock_bh(lock);
}
static void ebt_log_packet(struct net *net, u_int8_t pf, unsigned int hooknum,
const struct sk_buff *skb, const struct net_device *in,
const struct net_device *out, const struct nf_loginfo *li,
const char *prefix)
{
struct ebt_ulog_info loginfo;
if (!li || li->type != NF_LOG_TYPE_ULOG) {
loginfo.nlgroup = EBT_ULOG_DEFAULT_NLGROUP;
loginfo.cprange = 0;
loginfo.qthreshold = EBT_ULOG_DEFAULT_QTHRESHOLD;
loginfo.prefix[0] = '\0';
} else {
loginfo.nlgroup = li->u.ulog.group;
loginfo.cprange = li->u.ulog.copy_len;
loginfo.qthreshold = li->u.ulog.qthreshold;
strlcpy(loginfo.prefix, prefix, sizeof(loginfo.prefix));
}
ebt_ulog_packet(net, hooknum, skb, in, out, &loginfo, prefix);
}
static unsigned int
ebt_ulog_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
struct net *net = dev_net(par->in ? par->in : par->out);
ebt_ulog_packet(net, par->hooknum, skb, par->in, par->out,
par->targinfo, NULL);
return EBT_CONTINUE;
}
static int ebt_ulog_tg_check(const struct xt_tgchk_param *par)
{
struct ebt_ulog_info *uloginfo = par->targinfo;
if (!par->net->xt.ebt_ulog_warn_deprecated) {
pr_info("ebt_ulog is deprecated and it will be removed soon, "
"use ebt_nflog instead\n");
par->net->xt.ebt_ulog_warn_deprecated = true;
}
if (uloginfo->nlgroup > 31)
return -EINVAL;
uloginfo->prefix[EBT_ULOG_PREFIX_LEN - 1] = '\0';
if (uloginfo->qthreshold > EBT_ULOG_MAX_QLEN)
uloginfo->qthreshold = EBT_ULOG_MAX_QLEN;
return 0;
}
static int __net_init ebt_ulog_net_init(struct net *net)
{
int i;
struct ebt_ulog_net *ebt = ebt_ulog_pernet(net);
struct netlink_kernel_cfg cfg = {
.groups = EBT_ULOG_MAXNLGROUPS,
};
for (i = 0; i < EBT_ULOG_MAXNLGROUPS; i++) {
ebt->nlgroup[i] = i;
setup_timer(&ebt->ulog_buffers[i].timer, ulog_timer,
(unsigned long)&ebt->nlgroup[i]);
spin_lock_init(&ebt->ulog_buffers[i].lock);
}
ebt->ebtulognl = netlink_kernel_create(net, NETLINK_NFLOG, &cfg);
if (!ebt->ebtulognl)
return -ENOMEM;
nf_log_set(net, NFPROTO_BRIDGE, &ebt_ulog_logger);
return 0;
}
static void __net_exit ebt_ulog_net_fini(struct net *net)
{
int i;
struct ebt_ulog_net *ebt = ebt_ulog_pernet(net);
nf_log_unset(net, &ebt_ulog_logger);
for (i = 0; i < EBT_ULOG_MAXNLGROUPS; i++) {
ebt_ulog_buff_t *ub = &ebt->ulog_buffers[i];
del_timer(&ub->timer);
if (ub->skb) {
kfree_skb(ub->skb);
ub->skb = NULL;
}
}
netlink_kernel_release(ebt->ebtulognl);
}
static int __init ebt_ulog_init(void)
{
int ret;
if (nlbufsiz >= 128*1024) {
pr_warn("Netlink buffer has to be <= 128kB,"
"please try a smaller nlbufsiz parameter.\n");
return -EINVAL;
}
ret = register_pernet_subsys(&ebt_ulog_net_ops);
if (ret)
goto out_pernet;
ret = xt_register_target(&ebt_ulog_tg_reg);
if (ret)
goto out_target;
nf_log_register(NFPROTO_BRIDGE, &ebt_ulog_logger);
return 0;
out_target:
unregister_pernet_subsys(&ebt_ulog_net_ops);
out_pernet:
return ret;
}
static void __exit ebt_ulog_fini(void)
{
nf_log_unregister(&ebt_ulog_logger);
xt_unregister_target(&ebt_ulog_tg_reg);
unregister_pernet_subsys(&ebt_ulog_net_ops);
}
