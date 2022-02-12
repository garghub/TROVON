static void ulog_send(unsigned int nlgroup)
{
ebt_ulog_buff_t *ub = &ulog_buffers[nlgroup];
if (timer_pending(&ub->timer))
del_timer(&ub->timer);
if (!ub->skb)
return;
if (ub->qlen > 1)
ub->lastnlh->nlmsg_type = NLMSG_DONE;
NETLINK_CB(ub->skb).dst_group = nlgroup + 1;
netlink_broadcast(ebtulognl, ub->skb, 0, nlgroup + 1, GFP_ATOMIC);
ub->qlen = 0;
ub->skb = NULL;
}
static void ulog_timer(unsigned long data)
{
spin_lock_bh(&ulog_buffers[data].lock);
if (ulog_buffers[data].skb)
ulog_send(data);
spin_unlock_bh(&ulog_buffers[data].lock);
}
static struct sk_buff *ulog_alloc_skb(unsigned int size)
{
struct sk_buff *skb;
unsigned int n;
n = max(size, nlbufsiz);
skb = alloc_skb(n, GFP_ATOMIC);
if (!skb) {
pr_debug("cannot alloc whole buffer of size %ub!\n", n);
if (n > size) {
skb = alloc_skb(size, GFP_ATOMIC);
if (!skb)
pr_debug("cannot even allocate "
"buffer of size %ub\n", size);
}
}
return skb;
}
static void ebt_ulog_packet(unsigned int hooknr, const struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
const struct ebt_ulog_info *uloginfo, const char *prefix)
{
ebt_ulog_packet_msg_t *pm;
size_t size, copy_len;
struct nlmsghdr *nlh;
unsigned int group = uloginfo->nlgroup;
ebt_ulog_buff_t *ub = &ulog_buffers[group];
spinlock_t *lock = &ub->lock;
ktime_t kt;
if ((uloginfo->cprange == 0) ||
(uloginfo->cprange > skb->len + ETH_HLEN))
copy_len = skb->len + ETH_HLEN;
else
copy_len = uloginfo->cprange;
size = NLMSG_SPACE(sizeof(*pm) + copy_len);
if (size > nlbufsiz) {
pr_debug("Size %Zd needed, but nlbufsiz=%d\n", size, nlbufsiz);
return;
}
spin_lock_bh(lock);
if (!ub->skb) {
if (!(ub->skb = ulog_alloc_skb(size)))
goto alloc_failure;
} else if (size > skb_tailroom(ub->skb)) {
ulog_send(group);
if (!(ub->skb = ulog_alloc_skb(size)))
goto alloc_failure;
}
nlh = NLMSG_PUT(ub->skb, 0, ub->qlen, 0,
size - NLMSG_ALIGN(sizeof(*nlh)));
ub->qlen++;
pm = NLMSG_DATA(nlh);
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
else
*(pm->prefix) = '\0';
if (in) {
strcpy(pm->physindev, in->name);
if (br_port_exists(in))
strcpy(pm->indev, br_port_get_rcu(in)->br->dev->name);
else
strcpy(pm->indev, in->name);
} else
pm->indev[0] = pm->physindev[0] = '\0';
if (out) {
strcpy(pm->physoutdev, out->name);
strcpy(pm->outdev, br_port_get_rcu(out)->br->dev->name);
} else
pm->outdev[0] = pm->physoutdev[0] = '\0';
if (skb_copy_bits(skb, -ETH_HLEN, pm->data, copy_len) < 0)
BUG();
if (ub->qlen > 1)
ub->lastnlh->nlmsg_flags |= NLM_F_MULTI;
ub->lastnlh = nlh;
if (ub->qlen >= uloginfo->qthreshold)
ulog_send(group);
else if (!timer_pending(&ub->timer)) {
ub->timer.expires = jiffies + flushtimeout * HZ / 100;
add_timer(&ub->timer);
}
unlock:
spin_unlock_bh(lock);
return;
nlmsg_failure:
pr_debug("error during NLMSG_PUT. This should "
"not happen, please report to author.\n");
goto unlock;
alloc_failure:
goto unlock;
}
static void ebt_log_packet(u_int8_t pf, unsigned int hooknum,
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
ebt_ulog_packet(hooknum, skb, in, out, &loginfo, prefix);
}
static unsigned int
ebt_ulog_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
ebt_ulog_packet(par->hooknum, skb, par->in, par->out,
par->targinfo, NULL);
return EBT_CONTINUE;
}
static int ebt_ulog_tg_check(const struct xt_tgchk_param *par)
{
struct ebt_ulog_info *uloginfo = par->targinfo;
if (uloginfo->nlgroup > 31)
return -EINVAL;
uloginfo->prefix[EBT_ULOG_PREFIX_LEN - 1] = '\0';
if (uloginfo->qthreshold > EBT_ULOG_MAX_QLEN)
uloginfo->qthreshold = EBT_ULOG_MAX_QLEN;
return 0;
}
static int __init ebt_ulog_init(void)
{
int ret;
int i;
if (nlbufsiz >= 128*1024) {
pr_warning("Netlink buffer has to be <= 128kB,"
" please try a smaller nlbufsiz parameter.\n");
return -EINVAL;
}
for (i = 0; i < EBT_ULOG_MAXNLGROUPS; i++) {
setup_timer(&ulog_buffers[i].timer, ulog_timer, i);
spin_lock_init(&ulog_buffers[i].lock);
}
ebtulognl = netlink_kernel_create(&init_net, NETLINK_NFLOG,
EBT_ULOG_MAXNLGROUPS, NULL, NULL,
THIS_MODULE);
if (!ebtulognl)
ret = -ENOMEM;
else if ((ret = xt_register_target(&ebt_ulog_tg_reg)) != 0)
netlink_kernel_release(ebtulognl);
if (ret == 0)
nf_log_register(NFPROTO_BRIDGE, &ebt_ulog_logger);
return ret;
}
static void __exit ebt_ulog_fini(void)
{
ebt_ulog_buff_t *ub;
int i;
nf_log_unregister(&ebt_ulog_logger);
xt_unregister_target(&ebt_ulog_tg_reg);
for (i = 0; i < EBT_ULOG_MAXNLGROUPS; i++) {
ub = &ulog_buffers[i];
if (timer_pending(&ub->timer))
del_timer(&ub->timer);
spin_lock_bh(&ub->lock);
if (ub->skb) {
kfree_skb(ub->skb);
ub->skb = NULL;
}
spin_unlock_bh(&ub->lock);
}
netlink_kernel_release(ebtulognl);
}
