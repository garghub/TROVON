static void ulog_send(unsigned int nlgroupnum)
{
ulog_buff_t *ub = &ulog_buffers[nlgroupnum];
if (timer_pending(&ub->timer)) {
pr_debug("ulog_send: timer was pending, deleting\n");
del_timer(&ub->timer);
}
if (!ub->skb) {
pr_debug("ulog_send: nothing to send\n");
return;
}
if (ub->qlen > 1)
ub->lastnlh->nlmsg_type = NLMSG_DONE;
NETLINK_CB(ub->skb).dst_group = nlgroupnum + 1;
pr_debug("throwing %d packets to netlink group %u\n",
ub->qlen, nlgroupnum + 1);
netlink_broadcast(nflognl, ub->skb, 0, nlgroupnum + 1, GFP_ATOMIC);
ub->qlen = 0;
ub->skb = NULL;
ub->lastnlh = NULL;
}
static void ulog_timer(unsigned long data)
{
pr_debug("timer function called, calling ulog_send\n");
spin_lock_bh(&ulog_lock);
ulog_send(data);
spin_unlock_bh(&ulog_lock);
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
pr_debug("cannot even allocate %ub\n", size);
}
}
return skb;
}
static void ipt_ulog_packet(unsigned int hooknum,
const struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
const struct ipt_ulog_info *loginfo,
const char *prefix)
{
ulog_buff_t *ub;
ulog_packet_msg_t *pm;
size_t size, copy_len;
struct nlmsghdr *nlh;
struct timeval tv;
unsigned int groupnum = ffs(loginfo->nl_group) - 1;
if (loginfo->copy_range == 0 || loginfo->copy_range > skb->len)
copy_len = skb->len;
else
copy_len = loginfo->copy_range;
size = NLMSG_SPACE(sizeof(*pm) + copy_len);
ub = &ulog_buffers[groupnum];
spin_lock_bh(&ulog_lock);
if (!ub->skb) {
if (!(ub->skb = ulog_alloc_skb(size)))
goto alloc_failure;
} else if (ub->qlen >= loginfo->qthreshold ||
size > skb_tailroom(ub->skb)) {
ulog_send(groupnum);
if (!(ub->skb = ulog_alloc_skb(size)))
goto alloc_failure;
}
pr_debug("qlen %d, qthreshold %Zu\n", ub->qlen, loginfo->qthreshold);
nlh = NLMSG_PUT(ub->skb, 0, ub->qlen, ULOG_NL_EVENT,
sizeof(*pm)+copy_len);
ub->qlen++;
pm = NLMSG_DATA(nlh);
if (skb->tstamp.tv64 == 0)
__net_timestamp((struct sk_buff *)skb);
pm->data_len = copy_len;
tv = ktime_to_timeval(skb->tstamp);
put_unaligned(tv.tv_sec, &pm->timestamp_sec);
put_unaligned(tv.tv_usec, &pm->timestamp_usec);
put_unaligned(skb->mark, &pm->mark);
pm->hook = hooknum;
if (prefix != NULL)
strncpy(pm->prefix, prefix, sizeof(pm->prefix));
else if (loginfo->prefix[0] != '\0')
strncpy(pm->prefix, loginfo->prefix, sizeof(pm->prefix));
else
*(pm->prefix) = '\0';
if (in && in->hard_header_len > 0 &&
skb->mac_header != skb->network_header &&
in->hard_header_len <= ULOG_MAC_LEN) {
memcpy(pm->mac, skb_mac_header(skb), in->hard_header_len);
pm->mac_len = in->hard_header_len;
} else
pm->mac_len = 0;
if (in)
strncpy(pm->indev_name, in->name, sizeof(pm->indev_name));
else
pm->indev_name[0] = '\0';
if (out)
strncpy(pm->outdev_name, out->name, sizeof(pm->outdev_name));
else
pm->outdev_name[0] = '\0';
if (skb_copy_bits(skb, 0, pm->payload, copy_len) < 0)
BUG();
if (ub->qlen > 1)
ub->lastnlh->nlmsg_flags |= NLM_F_MULTI;
ub->lastnlh = nlh;
if (!timer_pending(&ub->timer)) {
ub->timer.expires = jiffies + flushtimeout * HZ / 100;
add_timer(&ub->timer);
}
if (ub->qlen >= loginfo->qthreshold) {
if (loginfo->qthreshold > 1)
nlh->nlmsg_type = NLMSG_DONE;
ulog_send(groupnum);
}
spin_unlock_bh(&ulog_lock);
return;
nlmsg_failure:
pr_debug("error during NLMSG_PUT\n");
alloc_failure:
pr_debug("Error building netlink message\n");
spin_unlock_bh(&ulog_lock);
}
static unsigned int
ulog_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
ipt_ulog_packet(par->hooknum, skb, par->in, par->out,
par->targinfo, NULL);
return XT_CONTINUE;
}
static void ipt_logfn(u_int8_t pf,
unsigned int hooknum,
const struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
const struct nf_loginfo *li,
const char *prefix)
{
struct ipt_ulog_info loginfo;
if (!li || li->type != NF_LOG_TYPE_ULOG) {
loginfo.nl_group = ULOG_DEFAULT_NLGROUP;
loginfo.copy_range = 0;
loginfo.qthreshold = ULOG_DEFAULT_QTHRESHOLD;
loginfo.prefix[0] = '\0';
} else {
loginfo.nl_group = li->u.ulog.group;
loginfo.copy_range = li->u.ulog.copy_len;
loginfo.qthreshold = li->u.ulog.qthreshold;
strlcpy(loginfo.prefix, prefix, sizeof(loginfo.prefix));
}
ipt_ulog_packet(hooknum, skb, in, out, &loginfo, prefix);
}
static int ulog_tg_check(const struct xt_tgchk_param *par)
{
const struct ipt_ulog_info *loginfo = par->targinfo;
if (loginfo->prefix[sizeof(loginfo->prefix) - 1] != '\0') {
pr_debug("prefix not null-terminated\n");
return -EINVAL;
}
if (loginfo->qthreshold > ULOG_MAX_QLEN) {
pr_debug("queue threshold %Zu > MAX_QLEN\n",
loginfo->qthreshold);
return -EINVAL;
}
return 0;
}
static void ulog_tg_compat_from_user(void *dst, const void *src)
{
const struct compat_ipt_ulog_info *cl = src;
struct ipt_ulog_info l = {
.nl_group = cl->nl_group,
.copy_range = cl->copy_range,
.qthreshold = cl->qthreshold,
};
memcpy(l.prefix, cl->prefix, sizeof(l.prefix));
memcpy(dst, &l, sizeof(l));
}
static int ulog_tg_compat_to_user(void __user *dst, const void *src)
{
const struct ipt_ulog_info *l = src;
struct compat_ipt_ulog_info cl = {
.nl_group = l->nl_group,
.copy_range = l->copy_range,
.qthreshold = l->qthreshold,
};
memcpy(cl.prefix, l->prefix, sizeof(cl.prefix));
return copy_to_user(dst, &cl, sizeof(cl)) ? -EFAULT : 0;
}
static int __init ulog_tg_init(void)
{
int ret, i;
pr_debug("init module\n");
if (nlbufsiz > 128*1024) {
pr_warning("Netlink buffer has to be <= 128kB\n");
return -EINVAL;
}
for (i = 0; i < ULOG_MAXNLGROUPS; i++)
setup_timer(&ulog_buffers[i].timer, ulog_timer, i);
nflognl = netlink_kernel_create(&init_net,
NETLINK_NFLOG, ULOG_MAXNLGROUPS, NULL,
NULL, THIS_MODULE);
if (!nflognl)
return -ENOMEM;
ret = xt_register_target(&ulog_tg_reg);
if (ret < 0) {
netlink_kernel_release(nflognl);
return ret;
}
if (nflog)
nf_log_register(NFPROTO_IPV4, &ipt_ulog_logger);
return 0;
}
static void __exit ulog_tg_exit(void)
{
ulog_buff_t *ub;
int i;
pr_debug("cleanup_module\n");
if (nflog)
nf_log_unregister(&ipt_ulog_logger);
xt_unregister_target(&ulog_tg_reg);
netlink_kernel_release(nflognl);
for (i = 0; i < ULOG_MAXNLGROUPS; i++) {
ub = &ulog_buffers[i];
if (timer_pending(&ub->timer)) {
pr_debug("timer was pending, deleting\n");
del_timer(&ub->timer);
}
if (ub->skb) {
kfree_skb(ub->skb);
ub->skb = NULL;
}
}
}
