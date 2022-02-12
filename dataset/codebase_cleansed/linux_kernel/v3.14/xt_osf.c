static int xt_osf_add_callback(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const osf_attrs[])
{
struct xt_osf_user_finger *f;
struct xt_osf_finger *kf = NULL, *sf;
int err = 0;
if (!osf_attrs[OSF_ATTR_FINGER])
return -EINVAL;
if (!(nlh->nlmsg_flags & NLM_F_CREATE))
return -EINVAL;
f = nla_data(osf_attrs[OSF_ATTR_FINGER]);
kf = kmalloc(sizeof(struct xt_osf_finger), GFP_KERNEL);
if (!kf)
return -ENOMEM;
memcpy(&kf->finger, f, sizeof(struct xt_osf_user_finger));
list_for_each_entry(sf, &xt_osf_fingers[!!f->df], finger_entry) {
if (memcmp(&sf->finger, f, sizeof(struct xt_osf_user_finger)))
continue;
kfree(kf);
kf = NULL;
if (nlh->nlmsg_flags & NLM_F_EXCL)
err = -EEXIST;
break;
}
if (kf)
list_add_tail_rcu(&kf->finger_entry, &xt_osf_fingers[!!f->df]);
return err;
}
static int xt_osf_remove_callback(struct sock *ctnl, struct sk_buff *skb,
const struct nlmsghdr *nlh,
const struct nlattr * const osf_attrs[])
{
struct xt_osf_user_finger *f;
struct xt_osf_finger *sf;
int err = -ENOENT;
if (!osf_attrs[OSF_ATTR_FINGER])
return -EINVAL;
f = nla_data(osf_attrs[OSF_ATTR_FINGER]);
list_for_each_entry(sf, &xt_osf_fingers[!!f->df], finger_entry) {
if (memcmp(&sf->finger, f, sizeof(struct xt_osf_user_finger)))
continue;
list_del_rcu(&sf->finger_entry);
kfree_rcu(sf, rcu_head);
err = 0;
break;
}
return err;
}
static inline int xt_osf_ttl(const struct sk_buff *skb, const struct xt_osf_info *info,
unsigned char f_ttl)
{
const struct iphdr *ip = ip_hdr(skb);
if (info->flags & XT_OSF_TTL) {
if (info->ttl == XT_OSF_TTL_TRUE)
return ip->ttl == f_ttl;
if (info->ttl == XT_OSF_TTL_NOCHECK)
return 1;
else if (ip->ttl <= f_ttl)
return 1;
else {
struct in_device *in_dev = __in_dev_get_rcu(skb->dev);
int ret = 0;
for_ifa(in_dev) {
if (inet_ifa_match(ip->saddr, ifa)) {
ret = (ip->ttl == f_ttl);
break;
}
}
endfor_ifa(in_dev);
return ret;
}
}
return ip->ttl == f_ttl;
}
static bool
xt_osf_match_packet(const struct sk_buff *skb, struct xt_action_param *p)
{
const struct xt_osf_info *info = p->matchinfo;
const struct iphdr *ip = ip_hdr(skb);
const struct tcphdr *tcp;
struct tcphdr _tcph;
int fmatch = FMATCH_WRONG, fcount = 0;
unsigned int optsize = 0, check_WSS = 0;
u16 window, totlen, mss = 0;
bool df;
const unsigned char *optp = NULL, *_optp = NULL;
unsigned char opts[MAX_IPOPTLEN];
const struct xt_osf_finger *kf;
const struct xt_osf_user_finger *f;
struct net *net = dev_net(p->in ? p->in : p->out);
if (!info)
return false;
tcp = skb_header_pointer(skb, ip_hdrlen(skb), sizeof(struct tcphdr), &_tcph);
if (!tcp)
return false;
if (!tcp->syn)
return false;
totlen = ntohs(ip->tot_len);
df = ntohs(ip->frag_off) & IP_DF;
window = ntohs(tcp->window);
if (tcp->doff * 4 > sizeof(struct tcphdr)) {
optsize = tcp->doff * 4 - sizeof(struct tcphdr);
_optp = optp = skb_header_pointer(skb, ip_hdrlen(skb) +
sizeof(struct tcphdr), optsize, opts);
}
rcu_read_lock();
list_for_each_entry_rcu(kf, &xt_osf_fingers[df], finger_entry) {
f = &kf->finger;
if (!(info->flags & XT_OSF_LOG) && strcmp(info->genre, f->genre))
continue;
optp = _optp;
fmatch = FMATCH_WRONG;
if (totlen == f->ss && xt_osf_ttl(skb, info, f->ttl)) {
int foptsize, optnum;
if (f->wss.wc >= OSF_WSS_MAX)
continue;
foptsize = 0;
for (optnum = 0; optnum < f->opt_num; ++optnum)
foptsize += f->opt[optnum].length;
if (foptsize > MAX_IPOPTLEN ||
optsize > MAX_IPOPTLEN ||
optsize != foptsize)
continue;
check_WSS = f->wss.wc;
for (optnum = 0; optnum < f->opt_num; ++optnum) {
if (f->opt[optnum].kind == (*optp)) {
__u32 len = f->opt[optnum].length;
const __u8 *optend = optp + len;
int loop_cont = 0;
fmatch = FMATCH_OK;
switch (*optp) {
case OSFOPT_MSS:
mss = optp[3];
mss <<= 8;
mss |= optp[2];
mss = ntohs((__force __be16)mss);
break;
case OSFOPT_TS:
loop_cont = 1;
break;
}
optp = optend;
} else
fmatch = FMATCH_OPT_WRONG;
if (fmatch != FMATCH_OK)
break;
}
if (fmatch != FMATCH_OPT_WRONG) {
fmatch = FMATCH_WRONG;
switch (check_WSS) {
case OSF_WSS_PLAIN:
if (f->wss.val == 0 || window == f->wss.val)
fmatch = FMATCH_OK;
break;
case OSF_WSS_MSS:
#define SMART_MSS_1 1460
#define SMART_MSS_2 1448
if (window == f->wss.val * mss ||
window == f->wss.val * SMART_MSS_1 ||
window == f->wss.val * SMART_MSS_2)
fmatch = FMATCH_OK;
break;
case OSF_WSS_MTU:
if (window == f->wss.val * (mss + 40) ||
window == f->wss.val * (SMART_MSS_1 + 40) ||
window == f->wss.val * (SMART_MSS_2 + 40))
fmatch = FMATCH_OK;
break;
case OSF_WSS_MODULO:
if ((window % f->wss.val) == 0)
fmatch = FMATCH_OK;
break;
}
}
if (fmatch != FMATCH_OK)
continue;
fcount++;
if (info->flags & XT_OSF_LOG)
nf_log_packet(net, p->family, p->hooknum, skb,
p->in, p->out, NULL,
"%s [%s:%s] : %pI4:%d -> %pI4:%d hops=%d\n",
f->genre, f->version, f->subtype,
&ip->saddr, ntohs(tcp->source),
&ip->daddr, ntohs(tcp->dest),
f->ttl - ip->ttl);
if ((info->flags & XT_OSF_LOG) &&
info->loglevel == XT_OSF_LOGLEVEL_FIRST)
break;
}
}
rcu_read_unlock();
if (!fcount && (info->flags & XT_OSF_LOG))
nf_log_packet(net, p->family, p->hooknum, skb, p->in,
p->out, NULL,
"Remote OS is not known: %pI4:%u -> %pI4:%u\n",
&ip->saddr, ntohs(tcp->source),
&ip->daddr, ntohs(tcp->dest));
if (fcount)
fmatch = FMATCH_OK;
return fmatch == FMATCH_OK;
}
static int __init xt_osf_init(void)
{
int err = -EINVAL;
int i;
for (i=0; i<ARRAY_SIZE(xt_osf_fingers); ++i)
INIT_LIST_HEAD(&xt_osf_fingers[i]);
err = nfnetlink_subsys_register(&xt_osf_nfnetlink);
if (err < 0) {
pr_err("Failed to register OSF nsfnetlink helper (%d)\n", err);
goto err_out_exit;
}
err = xt_register_match(&xt_osf_match);
if (err) {
pr_err("Failed to register OS fingerprint "
"matching module (%d)\n", err);
goto err_out_remove;
}
return 0;
err_out_remove:
nfnetlink_subsys_unregister(&xt_osf_nfnetlink);
err_out_exit:
return err;
}
static void __exit xt_osf_fini(void)
{
struct xt_osf_finger *f;
int i;
nfnetlink_subsys_unregister(&xt_osf_nfnetlink);
xt_unregister_match(&xt_osf_match);
rcu_read_lock();
for (i=0; i<ARRAY_SIZE(xt_osf_fingers); ++i) {
list_for_each_entry_rcu(f, &xt_osf_fingers[i], finger_entry) {
list_del_rcu(&f->finger_entry);
kfree_rcu(f, rcu_head);
}
}
rcu_read_unlock();
rcu_barrier();
}
