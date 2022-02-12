static int unsolicited_report_interval(struct in_device *in_dev)
{
int interval_ms, interval_jiffies;
if (IGMP_V1_SEEN(in_dev) || IGMP_V2_SEEN(in_dev))
interval_ms = IN_DEV_CONF_GET(
in_dev,
IGMPV2_UNSOLICITED_REPORT_INTERVAL);
else
interval_ms = IN_DEV_CONF_GET(
in_dev,
IGMPV3_UNSOLICITED_REPORT_INTERVAL);
interval_jiffies = msecs_to_jiffies(interval_ms);
if (interval_jiffies <= 0)
interval_jiffies = 1;
return interval_jiffies;
}
static void ip_ma_put(struct ip_mc_list *im)
{
if (atomic_dec_and_test(&im->refcnt)) {
in_dev_put(im->interface);
kfree_rcu(im, rcu);
}
}
static void igmp_stop_timer(struct ip_mc_list *im)
{
spin_lock_bh(&im->lock);
if (del_timer(&im->timer))
atomic_dec(&im->refcnt);
im->tm_running = 0;
im->reporter = 0;
im->unsolicit_count = 0;
spin_unlock_bh(&im->lock);
}
static void igmp_start_timer(struct ip_mc_list *im, int max_delay)
{
int tv = prandom_u32() % max_delay;
im->tm_running = 1;
if (!mod_timer(&im->timer, jiffies+tv+2))
atomic_inc(&im->refcnt);
}
static void igmp_gq_start_timer(struct in_device *in_dev)
{
int tv = prandom_u32() % in_dev->mr_maxdelay;
unsigned long exp = jiffies + tv + 2;
if (in_dev->mr_gq_running &&
time_after_eq(exp, (in_dev->mr_gq_timer).expires))
return;
in_dev->mr_gq_running = 1;
if (!mod_timer(&in_dev->mr_gq_timer, exp))
in_dev_hold(in_dev);
}
static void igmp_ifc_start_timer(struct in_device *in_dev, int delay)
{
int tv = prandom_u32() % delay;
if (!mod_timer(&in_dev->mr_ifc_timer, jiffies+tv+2))
in_dev_hold(in_dev);
}
static void igmp_mod_timer(struct ip_mc_list *im, int max_delay)
{
spin_lock_bh(&im->lock);
im->unsolicit_count = 0;
if (del_timer(&im->timer)) {
if ((long)(im->timer.expires-jiffies) < max_delay) {
add_timer(&im->timer);
im->tm_running = 1;
spin_unlock_bh(&im->lock);
return;
}
atomic_dec(&im->refcnt);
}
igmp_start_timer(im, max_delay);
spin_unlock_bh(&im->lock);
}
static int is_in(struct ip_mc_list *pmc, struct ip_sf_list *psf, int type,
int gdeleted, int sdeleted)
{
switch (type) {
case IGMPV3_MODE_IS_INCLUDE:
case IGMPV3_MODE_IS_EXCLUDE:
if (gdeleted || sdeleted)
return 0;
if (!(pmc->gsquery && !psf->sf_gsresp)) {
if (pmc->sfmode == MCAST_INCLUDE)
return 1;
if (psf->sf_count[MCAST_INCLUDE])
return type == IGMPV3_MODE_IS_INCLUDE;
return pmc->sfcount[MCAST_EXCLUDE] ==
psf->sf_count[MCAST_EXCLUDE];
}
return 0;
case IGMPV3_CHANGE_TO_INCLUDE:
if (gdeleted || sdeleted)
return 0;
return psf->sf_count[MCAST_INCLUDE] != 0;
case IGMPV3_CHANGE_TO_EXCLUDE:
if (gdeleted || sdeleted)
return 0;
if (pmc->sfcount[MCAST_EXCLUDE] == 0 ||
psf->sf_count[MCAST_INCLUDE])
return 0;
return pmc->sfcount[MCAST_EXCLUDE] ==
psf->sf_count[MCAST_EXCLUDE];
case IGMPV3_ALLOW_NEW_SOURCES:
if (gdeleted || !psf->sf_crcount)
return 0;
return (pmc->sfmode == MCAST_INCLUDE) ^ sdeleted;
case IGMPV3_BLOCK_OLD_SOURCES:
if (pmc->sfmode == MCAST_INCLUDE)
return gdeleted || (psf->sf_crcount && sdeleted);
return psf->sf_crcount && !gdeleted && !sdeleted;
}
return 0;
}
static int
igmp_scount(struct ip_mc_list *pmc, int type, int gdeleted, int sdeleted)
{
struct ip_sf_list *psf;
int scount = 0;
for (psf = pmc->sources; psf; psf = psf->sf_next) {
if (!is_in(pmc, psf, type, gdeleted, sdeleted))
continue;
scount++;
}
return scount;
}
static struct sk_buff *igmpv3_newpack(struct net_device *dev, unsigned int mtu)
{
struct sk_buff *skb;
struct rtable *rt;
struct iphdr *pip;
struct igmpv3_report *pig;
struct net *net = dev_net(dev);
struct flowi4 fl4;
int hlen = LL_RESERVED_SPACE(dev);
int tlen = dev->needed_tailroom;
unsigned int size = mtu;
while (1) {
skb = alloc_skb(size + hlen + tlen,
GFP_ATOMIC | __GFP_NOWARN);
if (skb)
break;
size >>= 1;
if (size < 256)
return NULL;
}
skb->priority = TC_PRIO_CONTROL;
rt = ip_route_output_ports(net, &fl4, NULL, IGMPV3_ALL_MCR, 0,
0, 0,
IPPROTO_IGMP, 0, dev->ifindex);
if (IS_ERR(rt)) {
kfree_skb(skb);
return NULL;
}
skb_dst_set(skb, &rt->dst);
skb->dev = dev;
skb_reserve(skb, hlen);
skb_tailroom_reserve(skb, mtu, tlen);
skb_reset_network_header(skb);
pip = ip_hdr(skb);
skb_put(skb, sizeof(struct iphdr) + 4);
pip->version = 4;
pip->ihl = (sizeof(struct iphdr)+4)>>2;
pip->tos = 0xc0;
pip->frag_off = htons(IP_DF);
pip->ttl = 1;
pip->daddr = fl4.daddr;
pip->saddr = fl4.saddr;
pip->protocol = IPPROTO_IGMP;
pip->tot_len = 0;
ip_select_ident(net, skb, NULL);
((u8 *)&pip[1])[0] = IPOPT_RA;
((u8 *)&pip[1])[1] = 4;
((u8 *)&pip[1])[2] = 0;
((u8 *)&pip[1])[3] = 0;
skb->transport_header = skb->network_header + sizeof(struct iphdr) + 4;
skb_put(skb, sizeof(*pig));
pig = igmpv3_report_hdr(skb);
pig->type = IGMPV3_HOST_MEMBERSHIP_REPORT;
pig->resv1 = 0;
pig->csum = 0;
pig->resv2 = 0;
pig->ngrec = 0;
return skb;
}
static int igmpv3_sendpack(struct sk_buff *skb)
{
struct igmphdr *pig = igmp_hdr(skb);
const int igmplen = skb_tail_pointer(skb) - skb_transport_header(skb);
pig->csum = ip_compute_csum(igmp_hdr(skb), igmplen);
return ip_local_out(dev_net(skb_dst(skb)->dev), skb->sk, skb);
}
static int grec_size(struct ip_mc_list *pmc, int type, int gdel, int sdel)
{
return sizeof(struct igmpv3_grec) + 4*igmp_scount(pmc, type, gdel, sdel);
}
static struct sk_buff *add_grhead(struct sk_buff *skb, struct ip_mc_list *pmc,
int type, struct igmpv3_grec **ppgr)
{
struct net_device *dev = pmc->interface->dev;
struct igmpv3_report *pih;
struct igmpv3_grec *pgr;
if (!skb)
skb = igmpv3_newpack(dev, dev->mtu);
if (!skb)
return NULL;
pgr = (struct igmpv3_grec *)skb_put(skb, sizeof(struct igmpv3_grec));
pgr->grec_type = type;
pgr->grec_auxwords = 0;
pgr->grec_nsrcs = 0;
pgr->grec_mca = pmc->multiaddr;
pih = igmpv3_report_hdr(skb);
pih->ngrec = htons(ntohs(pih->ngrec)+1);
*ppgr = pgr;
return skb;
}
static struct sk_buff *add_grec(struct sk_buff *skb, struct ip_mc_list *pmc,
int type, int gdeleted, int sdeleted)
{
struct net_device *dev = pmc->interface->dev;
struct net *net = dev_net(dev);
struct igmpv3_report *pih;
struct igmpv3_grec *pgr = NULL;
struct ip_sf_list *psf, *psf_next, *psf_prev, **psf_list;
int scount, stotal, first, isquery, truncate;
if (pmc->multiaddr == IGMP_ALL_HOSTS)
return skb;
if (ipv4_is_local_multicast(pmc->multiaddr) && !net->ipv4.sysctl_igmp_llm_reports)
return skb;
isquery = type == IGMPV3_MODE_IS_INCLUDE ||
type == IGMPV3_MODE_IS_EXCLUDE;
truncate = type == IGMPV3_MODE_IS_EXCLUDE ||
type == IGMPV3_CHANGE_TO_EXCLUDE;
stotal = scount = 0;
psf_list = sdeleted ? &pmc->tomb : &pmc->sources;
if (!*psf_list)
goto empty_source;
pih = skb ? igmpv3_report_hdr(skb) : NULL;
if (truncate) {
if (pih && pih->ngrec &&
AVAILABLE(skb) < grec_size(pmc, type, gdeleted, sdeleted)) {
if (skb)
igmpv3_sendpack(skb);
skb = igmpv3_newpack(dev, dev->mtu);
}
}
first = 1;
psf_prev = NULL;
for (psf = *psf_list; psf; psf = psf_next) {
__be32 *psrc;
psf_next = psf->sf_next;
if (!is_in(pmc, psf, type, gdeleted, sdeleted)) {
psf_prev = psf;
continue;
}
if (((gdeleted && pmc->sfmode == MCAST_EXCLUDE) ||
(!gdeleted && pmc->crcount)) &&
(type == IGMPV3_ALLOW_NEW_SOURCES ||
type == IGMPV3_BLOCK_OLD_SOURCES) && psf->sf_crcount)
goto decrease_sf_crcount;
if (isquery)
psf->sf_gsresp = 0;
if (AVAILABLE(skb) < sizeof(__be32) +
first*sizeof(struct igmpv3_grec)) {
if (truncate && !first)
break;
if (pgr)
pgr->grec_nsrcs = htons(scount);
if (skb)
igmpv3_sendpack(skb);
skb = igmpv3_newpack(dev, dev->mtu);
first = 1;
scount = 0;
}
if (first) {
skb = add_grhead(skb, pmc, type, &pgr);
first = 0;
}
if (!skb)
return NULL;
psrc = (__be32 *)skb_put(skb, sizeof(__be32));
*psrc = psf->sf_inaddr;
scount++; stotal++;
if ((type == IGMPV3_ALLOW_NEW_SOURCES ||
type == IGMPV3_BLOCK_OLD_SOURCES) && psf->sf_crcount) {
decrease_sf_crcount:
psf->sf_crcount--;
if ((sdeleted || gdeleted) && psf->sf_crcount == 0) {
if (psf_prev)
psf_prev->sf_next = psf->sf_next;
else
*psf_list = psf->sf_next;
kfree(psf);
continue;
}
}
psf_prev = psf;
}
empty_source:
if (!stotal) {
if (type == IGMPV3_ALLOW_NEW_SOURCES ||
type == IGMPV3_BLOCK_OLD_SOURCES)
return skb;
if (pmc->crcount || isquery) {
if (skb && AVAILABLE(skb) < sizeof(struct igmpv3_grec)) {
igmpv3_sendpack(skb);
skb = NULL;
}
skb = add_grhead(skb, pmc, type, &pgr);
}
}
if (pgr)
pgr->grec_nsrcs = htons(scount);
if (isquery)
pmc->gsquery = 0;
return skb;
}
static int igmpv3_send_report(struct in_device *in_dev, struct ip_mc_list *pmc)
{
struct sk_buff *skb = NULL;
struct net *net = dev_net(in_dev->dev);
int type;
if (!pmc) {
rcu_read_lock();
for_each_pmc_rcu(in_dev, pmc) {
if (pmc->multiaddr == IGMP_ALL_HOSTS)
continue;
if (ipv4_is_local_multicast(pmc->multiaddr) &&
!net->ipv4.sysctl_igmp_llm_reports)
continue;
spin_lock_bh(&pmc->lock);
if (pmc->sfcount[MCAST_EXCLUDE])
type = IGMPV3_MODE_IS_EXCLUDE;
else
type = IGMPV3_MODE_IS_INCLUDE;
skb = add_grec(skb, pmc, type, 0, 0);
spin_unlock_bh(&pmc->lock);
}
rcu_read_unlock();
} else {
spin_lock_bh(&pmc->lock);
if (pmc->sfcount[MCAST_EXCLUDE])
type = IGMPV3_MODE_IS_EXCLUDE;
else
type = IGMPV3_MODE_IS_INCLUDE;
skb = add_grec(skb, pmc, type, 0, 0);
spin_unlock_bh(&pmc->lock);
}
if (!skb)
return 0;
return igmpv3_sendpack(skb);
}
static void igmpv3_clear_zeros(struct ip_sf_list **ppsf)
{
struct ip_sf_list *psf_prev, *psf_next, *psf;
psf_prev = NULL;
for (psf = *ppsf; psf; psf = psf_next) {
psf_next = psf->sf_next;
if (psf->sf_crcount == 0) {
if (psf_prev)
psf_prev->sf_next = psf->sf_next;
else
*ppsf = psf->sf_next;
kfree(psf);
} else
psf_prev = psf;
}
}
static void igmpv3_send_cr(struct in_device *in_dev)
{
struct ip_mc_list *pmc, *pmc_prev, *pmc_next;
struct sk_buff *skb = NULL;
int type, dtype;
rcu_read_lock();
spin_lock_bh(&in_dev->mc_tomb_lock);
pmc_prev = NULL;
for (pmc = in_dev->mc_tomb; pmc; pmc = pmc_next) {
pmc_next = pmc->next;
if (pmc->sfmode == MCAST_INCLUDE) {
type = IGMPV3_BLOCK_OLD_SOURCES;
dtype = IGMPV3_BLOCK_OLD_SOURCES;
skb = add_grec(skb, pmc, type, 1, 0);
skb = add_grec(skb, pmc, dtype, 1, 1);
}
if (pmc->crcount) {
if (pmc->sfmode == MCAST_EXCLUDE) {
type = IGMPV3_CHANGE_TO_INCLUDE;
skb = add_grec(skb, pmc, type, 1, 0);
}
pmc->crcount--;
if (pmc->crcount == 0) {
igmpv3_clear_zeros(&pmc->tomb);
igmpv3_clear_zeros(&pmc->sources);
}
}
if (pmc->crcount == 0 && !pmc->tomb && !pmc->sources) {
if (pmc_prev)
pmc_prev->next = pmc_next;
else
in_dev->mc_tomb = pmc_next;
in_dev_put(pmc->interface);
kfree(pmc);
} else
pmc_prev = pmc;
}
spin_unlock_bh(&in_dev->mc_tomb_lock);
for_each_pmc_rcu(in_dev, pmc) {
spin_lock_bh(&pmc->lock);
if (pmc->sfcount[MCAST_EXCLUDE]) {
type = IGMPV3_BLOCK_OLD_SOURCES;
dtype = IGMPV3_ALLOW_NEW_SOURCES;
} else {
type = IGMPV3_ALLOW_NEW_SOURCES;
dtype = IGMPV3_BLOCK_OLD_SOURCES;
}
skb = add_grec(skb, pmc, type, 0, 0);
skb = add_grec(skb, pmc, dtype, 0, 1);
if (pmc->crcount) {
if (pmc->sfmode == MCAST_EXCLUDE)
type = IGMPV3_CHANGE_TO_EXCLUDE;
else
type = IGMPV3_CHANGE_TO_INCLUDE;
skb = add_grec(skb, pmc, type, 0, 0);
pmc->crcount--;
}
spin_unlock_bh(&pmc->lock);
}
rcu_read_unlock();
if (!skb)
return;
(void) igmpv3_sendpack(skb);
}
static int igmp_send_report(struct in_device *in_dev, struct ip_mc_list *pmc,
int type)
{
struct sk_buff *skb;
struct iphdr *iph;
struct igmphdr *ih;
struct rtable *rt;
struct net_device *dev = in_dev->dev;
struct net *net = dev_net(dev);
__be32 group = pmc ? pmc->multiaddr : 0;
struct flowi4 fl4;
__be32 dst;
int hlen, tlen;
if (type == IGMPV3_HOST_MEMBERSHIP_REPORT)
return igmpv3_send_report(in_dev, pmc);
if (ipv4_is_local_multicast(group) && !net->ipv4.sysctl_igmp_llm_reports)
return 0;
if (type == IGMP_HOST_LEAVE_MESSAGE)
dst = IGMP_ALL_ROUTER;
else
dst = group;
rt = ip_route_output_ports(net, &fl4, NULL, dst, 0,
0, 0,
IPPROTO_IGMP, 0, dev->ifindex);
if (IS_ERR(rt))
return -1;
hlen = LL_RESERVED_SPACE(dev);
tlen = dev->needed_tailroom;
skb = alloc_skb(IGMP_SIZE + hlen + tlen, GFP_ATOMIC);
if (!skb) {
ip_rt_put(rt);
return -1;
}
skb->priority = TC_PRIO_CONTROL;
skb_dst_set(skb, &rt->dst);
skb_reserve(skb, hlen);
skb_reset_network_header(skb);
iph = ip_hdr(skb);
skb_put(skb, sizeof(struct iphdr) + 4);
iph->version = 4;
iph->ihl = (sizeof(struct iphdr)+4)>>2;
iph->tos = 0xc0;
iph->frag_off = htons(IP_DF);
iph->ttl = 1;
iph->daddr = dst;
iph->saddr = fl4.saddr;
iph->protocol = IPPROTO_IGMP;
ip_select_ident(net, skb, NULL);
((u8 *)&iph[1])[0] = IPOPT_RA;
((u8 *)&iph[1])[1] = 4;
((u8 *)&iph[1])[2] = 0;
((u8 *)&iph[1])[3] = 0;
ih = (struct igmphdr *)skb_put(skb, sizeof(struct igmphdr));
ih->type = type;
ih->code = 0;
ih->csum = 0;
ih->group = group;
ih->csum = ip_compute_csum((void *)ih, sizeof(struct igmphdr));
return ip_local_out(net, skb->sk, skb);
}
static void igmp_gq_timer_expire(unsigned long data)
{
struct in_device *in_dev = (struct in_device *)data;
in_dev->mr_gq_running = 0;
igmpv3_send_report(in_dev, NULL);
in_dev_put(in_dev);
}
static void igmp_ifc_timer_expire(unsigned long data)
{
struct in_device *in_dev = (struct in_device *)data;
igmpv3_send_cr(in_dev);
if (in_dev->mr_ifc_count) {
in_dev->mr_ifc_count--;
igmp_ifc_start_timer(in_dev,
unsolicited_report_interval(in_dev));
}
in_dev_put(in_dev);
}
static void igmp_ifc_event(struct in_device *in_dev)
{
struct net *net = dev_net(in_dev->dev);
if (IGMP_V1_SEEN(in_dev) || IGMP_V2_SEEN(in_dev))
return;
in_dev->mr_ifc_count = in_dev->mr_qrv ?: net->ipv4.sysctl_igmp_qrv;
igmp_ifc_start_timer(in_dev, 1);
}
static void igmp_timer_expire(unsigned long data)
{
struct ip_mc_list *im = (struct ip_mc_list *)data;
struct in_device *in_dev = im->interface;
spin_lock(&im->lock);
im->tm_running = 0;
if (im->unsolicit_count) {
im->unsolicit_count--;
igmp_start_timer(im, unsolicited_report_interval(in_dev));
}
im->reporter = 1;
spin_unlock(&im->lock);
if (IGMP_V1_SEEN(in_dev))
igmp_send_report(in_dev, im, IGMP_HOST_MEMBERSHIP_REPORT);
else if (IGMP_V2_SEEN(in_dev))
igmp_send_report(in_dev, im, IGMPV2_HOST_MEMBERSHIP_REPORT);
else
igmp_send_report(in_dev, im, IGMPV3_HOST_MEMBERSHIP_REPORT);
ip_ma_put(im);
}
static int igmp_xmarksources(struct ip_mc_list *pmc, int nsrcs, __be32 *srcs)
{
struct ip_sf_list *psf;
int i, scount;
scount = 0;
for (psf = pmc->sources; psf; psf = psf->sf_next) {
if (scount == nsrcs)
break;
for (i = 0; i < nsrcs; i++) {
if (psf->sf_count[MCAST_INCLUDE] ||
pmc->sfcount[MCAST_EXCLUDE] !=
psf->sf_count[MCAST_EXCLUDE])
break;
if (srcs[i] == psf->sf_inaddr) {
scount++;
break;
}
}
}
pmc->gsquery = 0;
if (scount == nsrcs)
return 0;
return 1;
}
static int igmp_marksources(struct ip_mc_list *pmc, int nsrcs, __be32 *srcs)
{
struct ip_sf_list *psf;
int i, scount;
if (pmc->sfmode == MCAST_EXCLUDE)
return igmp_xmarksources(pmc, nsrcs, srcs);
scount = 0;
for (psf = pmc->sources; psf; psf = psf->sf_next) {
if (scount == nsrcs)
break;
for (i = 0; i < nsrcs; i++)
if (srcs[i] == psf->sf_inaddr) {
psf->sf_gsresp = 1;
scount++;
break;
}
}
if (!scount) {
pmc->gsquery = 0;
return 0;
}
pmc->gsquery = 1;
return 1;
}
static bool igmp_heard_report(struct in_device *in_dev, __be32 group)
{
struct ip_mc_list *im;
struct net *net = dev_net(in_dev->dev);
if (group == IGMP_ALL_HOSTS)
return false;
if (ipv4_is_local_multicast(group) && !net->ipv4.sysctl_igmp_llm_reports)
return false;
rcu_read_lock();
for_each_pmc_rcu(in_dev, im) {
if (im->multiaddr == group) {
igmp_stop_timer(im);
break;
}
}
rcu_read_unlock();
return false;
}
static bool igmp_heard_query(struct in_device *in_dev, struct sk_buff *skb,
int len)
{
struct igmphdr *ih = igmp_hdr(skb);
struct igmpv3_query *ih3 = igmpv3_query_hdr(skb);
struct ip_mc_list *im;
__be32 group = ih->group;
int max_delay;
int mark = 0;
struct net *net = dev_net(in_dev->dev);
if (len == 8) {
if (ih->code == 0) {
max_delay = IGMP_QUERY_RESPONSE_INTERVAL;
in_dev->mr_v1_seen = jiffies +
IGMP_V1_ROUTER_PRESENT_TIMEOUT;
group = 0;
} else {
max_delay = ih->code*(HZ/IGMP_TIMER_SCALE);
in_dev->mr_v2_seen = jiffies +
IGMP_V2_ROUTER_PRESENT_TIMEOUT;
}
in_dev->mr_ifc_count = 0;
if (del_timer(&in_dev->mr_ifc_timer))
__in_dev_put(in_dev);
igmpv3_clear_delrec(in_dev);
} else if (len < 12) {
return true;
} else if (IGMP_V1_SEEN(in_dev)) {
max_delay = IGMP_QUERY_RESPONSE_INTERVAL;
group = 0;
} else if (IGMP_V2_SEEN(in_dev)) {
max_delay = IGMPV3_MRC(ih3->code)*(HZ/IGMP_TIMER_SCALE);
if (!max_delay)
max_delay = 1;
} else {
if (!pskb_may_pull(skb, sizeof(struct igmpv3_query)))
return true;
ih3 = igmpv3_query_hdr(skb);
if (ih3->nsrcs) {
if (!pskb_may_pull(skb, sizeof(struct igmpv3_query)
+ ntohs(ih3->nsrcs)*sizeof(__be32)))
return true;
ih3 = igmpv3_query_hdr(skb);
}
max_delay = IGMPV3_MRC(ih3->code)*(HZ/IGMP_TIMER_SCALE);
if (!max_delay)
max_delay = 1;
in_dev->mr_maxdelay = max_delay;
if (ih3->qrv)
in_dev->mr_qrv = ih3->qrv;
if (!group) {
if (ih3->nsrcs)
return true;
igmp_gq_start_timer(in_dev);
return false;
}
mark = ih3->nsrcs != 0;
}
rcu_read_lock();
for_each_pmc_rcu(in_dev, im) {
int changed;
if (group && group != im->multiaddr)
continue;
if (im->multiaddr == IGMP_ALL_HOSTS)
continue;
if (ipv4_is_local_multicast(im->multiaddr) &&
!net->ipv4.sysctl_igmp_llm_reports)
continue;
spin_lock_bh(&im->lock);
if (im->tm_running)
im->gsquery = im->gsquery && mark;
else
im->gsquery = mark;
changed = !im->gsquery ||
igmp_marksources(im, ntohs(ih3->nsrcs), ih3->srcs);
spin_unlock_bh(&im->lock);
if (changed)
igmp_mod_timer(im, max_delay);
}
rcu_read_unlock();
return false;
}
int igmp_rcv(struct sk_buff *skb)
{
struct igmphdr *ih;
struct in_device *in_dev = __in_dev_get_rcu(skb->dev);
int len = skb->len;
bool dropped = true;
if (!in_dev)
goto drop;
if (!pskb_may_pull(skb, sizeof(struct igmphdr)))
goto drop;
if (skb_checksum_simple_validate(skb))
goto drop;
ih = igmp_hdr(skb);
switch (ih->type) {
case IGMP_HOST_MEMBERSHIP_QUERY:
dropped = igmp_heard_query(in_dev, skb, len);
break;
case IGMP_HOST_MEMBERSHIP_REPORT:
case IGMPV2_HOST_MEMBERSHIP_REPORT:
if (rt_is_output_route(skb_rtable(skb)))
break;
if (skb->pkt_type == PACKET_MULTICAST ||
skb->pkt_type == PACKET_BROADCAST)
dropped = igmp_heard_report(in_dev, ih->group);
break;
case IGMP_PIM:
#ifdef CONFIG_IP_PIMSM_V1
return pim_rcv_v1(skb);
#endif
case IGMPV3_HOST_MEMBERSHIP_REPORT:
case IGMP_DVMRP:
case IGMP_TRACE:
case IGMP_HOST_LEAVE_MESSAGE:
case IGMP_MTRACE:
case IGMP_MTRACE_RESP:
break;
default:
break;
}
drop:
if (dropped)
kfree_skb(skb);
else
consume_skb(skb);
return 0;
}
static void ip_mc_filter_add(struct in_device *in_dev, __be32 addr)
{
char buf[MAX_ADDR_LEN];
struct net_device *dev = in_dev->dev;
if (arp_mc_map(addr, buf, dev, 0) == 0)
dev_mc_add(dev, buf);
}
static void ip_mc_filter_del(struct in_device *in_dev, __be32 addr)
{
char buf[MAX_ADDR_LEN];
struct net_device *dev = in_dev->dev;
if (arp_mc_map(addr, buf, dev, 0) == 0)
dev_mc_del(dev, buf);
}
static void igmpv3_add_delrec(struct in_device *in_dev, struct ip_mc_list *im)
{
struct ip_mc_list *pmc;
struct net *net = dev_net(in_dev->dev);
pmc = kzalloc(sizeof(*pmc), GFP_KERNEL);
if (!pmc)
return;
spin_lock_init(&pmc->lock);
spin_lock_bh(&im->lock);
pmc->interface = im->interface;
in_dev_hold(in_dev);
pmc->multiaddr = im->multiaddr;
pmc->crcount = in_dev->mr_qrv ?: net->ipv4.sysctl_igmp_qrv;
pmc->sfmode = im->sfmode;
if (pmc->sfmode == MCAST_INCLUDE) {
struct ip_sf_list *psf;
pmc->tomb = im->tomb;
pmc->sources = im->sources;
im->tomb = im->sources = NULL;
for (psf = pmc->sources; psf; psf = psf->sf_next)
psf->sf_crcount = pmc->crcount;
}
spin_unlock_bh(&im->lock);
spin_lock_bh(&in_dev->mc_tomb_lock);
pmc->next = in_dev->mc_tomb;
in_dev->mc_tomb = pmc;
spin_unlock_bh(&in_dev->mc_tomb_lock);
}
static void igmpv3_del_delrec(struct in_device *in_dev, struct ip_mc_list *im)
{
struct ip_mc_list *pmc, *pmc_prev;
struct ip_sf_list *psf;
struct net *net = dev_net(in_dev->dev);
__be32 multiaddr = im->multiaddr;
spin_lock_bh(&in_dev->mc_tomb_lock);
pmc_prev = NULL;
for (pmc = in_dev->mc_tomb; pmc; pmc = pmc->next) {
if (pmc->multiaddr == multiaddr)
break;
pmc_prev = pmc;
}
if (pmc) {
if (pmc_prev)
pmc_prev->next = pmc->next;
else
in_dev->mc_tomb = pmc->next;
}
spin_unlock_bh(&in_dev->mc_tomb_lock);
spin_lock_bh(&im->lock);
if (pmc) {
im->interface = pmc->interface;
im->crcount = in_dev->mr_qrv ?: net->ipv4.sysctl_igmp_qrv;
im->sfmode = pmc->sfmode;
if (pmc->sfmode == MCAST_INCLUDE) {
im->tomb = pmc->tomb;
im->sources = pmc->sources;
for (psf = im->sources; psf; psf = psf->sf_next)
psf->sf_crcount = im->crcount;
}
in_dev_put(pmc->interface);
kfree(pmc);
}
spin_unlock_bh(&im->lock);
}
static void igmpv3_clear_delrec(struct in_device *in_dev)
{
struct ip_mc_list *pmc, *nextpmc;
spin_lock_bh(&in_dev->mc_tomb_lock);
pmc = in_dev->mc_tomb;
in_dev->mc_tomb = NULL;
spin_unlock_bh(&in_dev->mc_tomb_lock);
for (; pmc; pmc = nextpmc) {
nextpmc = pmc->next;
ip_mc_clear_src(pmc);
in_dev_put(pmc->interface);
kfree(pmc);
}
rcu_read_lock();
for_each_pmc_rcu(in_dev, pmc) {
struct ip_sf_list *psf, *psf_next;
spin_lock_bh(&pmc->lock);
psf = pmc->tomb;
pmc->tomb = NULL;
spin_unlock_bh(&pmc->lock);
for (; psf; psf = psf_next) {
psf_next = psf->sf_next;
kfree(psf);
}
}
rcu_read_unlock();
}
static void igmp_group_dropped(struct ip_mc_list *im)
{
struct in_device *in_dev = im->interface;
#ifdef CONFIG_IP_MULTICAST
struct net *net = dev_net(in_dev->dev);
int reporter;
#endif
if (im->loaded) {
im->loaded = 0;
ip_mc_filter_del(in_dev, im->multiaddr);
}
#ifdef CONFIG_IP_MULTICAST
if (im->multiaddr == IGMP_ALL_HOSTS)
return;
if (ipv4_is_local_multicast(im->multiaddr) && !net->ipv4.sysctl_igmp_llm_reports)
return;
reporter = im->reporter;
igmp_stop_timer(im);
if (!in_dev->dead) {
if (IGMP_V1_SEEN(in_dev))
return;
if (IGMP_V2_SEEN(in_dev)) {
if (reporter)
igmp_send_report(in_dev, im, IGMP_HOST_LEAVE_MESSAGE);
return;
}
igmpv3_add_delrec(in_dev, im);
igmp_ifc_event(in_dev);
}
#endif
}
static void igmp_group_added(struct ip_mc_list *im)
{
struct in_device *in_dev = im->interface;
#ifdef CONFIG_IP_MULTICAST
struct net *net = dev_net(in_dev->dev);
#endif
if (im->loaded == 0) {
im->loaded = 1;
ip_mc_filter_add(in_dev, im->multiaddr);
}
#ifdef CONFIG_IP_MULTICAST
if (im->multiaddr == IGMP_ALL_HOSTS)
return;
if (ipv4_is_local_multicast(im->multiaddr) && !net->ipv4.sysctl_igmp_llm_reports)
return;
if (in_dev->dead)
return;
if (IGMP_V1_SEEN(in_dev) || IGMP_V2_SEEN(in_dev)) {
spin_lock_bh(&im->lock);
igmp_start_timer(im, IGMP_INITIAL_REPORT_DELAY);
spin_unlock_bh(&im->lock);
return;
}
im->crcount = in_dev->mr_qrv ?: net->ipv4.sysctl_igmp_qrv;
igmp_ifc_event(in_dev);
#endif
}
static u32 ip_mc_hash(const struct ip_mc_list *im)
{
return hash_32((__force u32)im->multiaddr, MC_HASH_SZ_LOG);
}
static void ip_mc_hash_add(struct in_device *in_dev,
struct ip_mc_list *im)
{
struct ip_mc_list __rcu **mc_hash;
u32 hash;
mc_hash = rtnl_dereference(in_dev->mc_hash);
if (mc_hash) {
hash = ip_mc_hash(im);
im->next_hash = mc_hash[hash];
rcu_assign_pointer(mc_hash[hash], im);
return;
}
if (in_dev->mc_count < 4)
return;
mc_hash = kzalloc(sizeof(struct ip_mc_list *) << MC_HASH_SZ_LOG,
GFP_KERNEL);
if (!mc_hash)
return;
for_each_pmc_rtnl(in_dev, im) {
hash = ip_mc_hash(im);
im->next_hash = mc_hash[hash];
RCU_INIT_POINTER(mc_hash[hash], im);
}
rcu_assign_pointer(in_dev->mc_hash, mc_hash);
}
static void ip_mc_hash_remove(struct in_device *in_dev,
struct ip_mc_list *im)
{
struct ip_mc_list __rcu **mc_hash = rtnl_dereference(in_dev->mc_hash);
struct ip_mc_list *aux;
if (!mc_hash)
return;
mc_hash += ip_mc_hash(im);
while ((aux = rtnl_dereference(*mc_hash)) != im)
mc_hash = &aux->next_hash;
*mc_hash = im->next_hash;
}
void ip_mc_inc_group(struct in_device *in_dev, __be32 addr)
{
struct ip_mc_list *im;
#ifdef CONFIG_IP_MULTICAST
struct net *net = dev_net(in_dev->dev);
#endif
ASSERT_RTNL();
for_each_pmc_rtnl(in_dev, im) {
if (im->multiaddr == addr) {
im->users++;
ip_mc_add_src(in_dev, &addr, MCAST_EXCLUDE, 0, NULL, 0);
goto out;
}
}
im = kzalloc(sizeof(*im), GFP_KERNEL);
if (!im)
goto out;
im->users = 1;
im->interface = in_dev;
in_dev_hold(in_dev);
im->multiaddr = addr;
im->sfmode = MCAST_EXCLUDE;
im->sfcount[MCAST_EXCLUDE] = 1;
atomic_set(&im->refcnt, 1);
spin_lock_init(&im->lock);
#ifdef CONFIG_IP_MULTICAST
setup_timer(&im->timer, igmp_timer_expire, (unsigned long)im);
im->unsolicit_count = net->ipv4.sysctl_igmp_qrv;
#endif
im->next_rcu = in_dev->mc_list;
in_dev->mc_count++;
rcu_assign_pointer(in_dev->mc_list, im);
ip_mc_hash_add(in_dev, im);
#ifdef CONFIG_IP_MULTICAST
igmpv3_del_delrec(in_dev, im);
#endif
igmp_group_added(im);
if (!in_dev->dead)
ip_rt_multicast_event(in_dev);
out:
return;
}
static int ip_mc_check_iphdr(struct sk_buff *skb)
{
const struct iphdr *iph;
unsigned int len;
unsigned int offset = skb_network_offset(skb) + sizeof(*iph);
if (!pskb_may_pull(skb, offset))
return -EINVAL;
iph = ip_hdr(skb);
if (iph->version != 4 || ip_hdrlen(skb) < sizeof(*iph))
return -EINVAL;
offset += ip_hdrlen(skb) - sizeof(*iph);
if (!pskb_may_pull(skb, offset))
return -EINVAL;
iph = ip_hdr(skb);
if (unlikely(ip_fast_csum((u8 *)iph, iph->ihl)))
return -EINVAL;
len = skb_network_offset(skb) + ntohs(iph->tot_len);
if (skb->len < len || len < offset)
return -EINVAL;
skb_set_transport_header(skb, offset);
return 0;
}
static int ip_mc_check_igmp_reportv3(struct sk_buff *skb)
{
unsigned int len = skb_transport_offset(skb);
len += sizeof(struct igmpv3_report);
return pskb_may_pull(skb, len) ? 0 : -EINVAL;
}
static int ip_mc_check_igmp_query(struct sk_buff *skb)
{
unsigned int len = skb_transport_offset(skb);
len += sizeof(struct igmphdr);
if (skb->len < len)
return -EINVAL;
if (skb->len != len) {
len += sizeof(struct igmpv3_query) - sizeof(struct igmphdr);
if (skb->len < len || !pskb_may_pull(skb, len))
return -EINVAL;
}
if (!igmp_hdr(skb)->group &&
ip_hdr(skb)->daddr != htonl(INADDR_ALLHOSTS_GROUP))
return -EINVAL;
return 0;
}
static int ip_mc_check_igmp_msg(struct sk_buff *skb)
{
switch (igmp_hdr(skb)->type) {
case IGMP_HOST_LEAVE_MESSAGE:
case IGMP_HOST_MEMBERSHIP_REPORT:
case IGMPV2_HOST_MEMBERSHIP_REPORT:
return 0;
case IGMPV3_HOST_MEMBERSHIP_REPORT:
return ip_mc_check_igmp_reportv3(skb);
case IGMP_HOST_MEMBERSHIP_QUERY:
return ip_mc_check_igmp_query(skb);
default:
return -ENOMSG;
}
}
static inline __sum16 ip_mc_validate_checksum(struct sk_buff *skb)
{
return skb_checksum_simple_validate(skb);
}
static int __ip_mc_check_igmp(struct sk_buff *skb, struct sk_buff **skb_trimmed)
{
struct sk_buff *skb_chk;
unsigned int transport_len;
unsigned int len = skb_transport_offset(skb) + sizeof(struct igmphdr);
int ret = -EINVAL;
transport_len = ntohs(ip_hdr(skb)->tot_len) - ip_hdrlen(skb);
skb_chk = skb_checksum_trimmed(skb, transport_len,
ip_mc_validate_checksum);
if (!skb_chk)
goto err;
if (!pskb_may_pull(skb_chk, len))
goto err;
ret = ip_mc_check_igmp_msg(skb_chk);
if (ret)
goto err;
if (skb_trimmed)
*skb_trimmed = skb_chk;
else if (skb_chk != skb)
kfree_skb(skb_chk);
ret = 0;
err:
if (ret && skb_chk && skb_chk != skb)
kfree_skb(skb_chk);
return ret;
}
int ip_mc_check_igmp(struct sk_buff *skb, struct sk_buff **skb_trimmed)
{
int ret = ip_mc_check_iphdr(skb);
if (ret < 0)
return ret;
if (ip_hdr(skb)->protocol != IPPROTO_IGMP)
return -ENOMSG;
return __ip_mc_check_igmp(skb, skb_trimmed);
}
static void ip_mc_rejoin_groups(struct in_device *in_dev)
{
#ifdef CONFIG_IP_MULTICAST
struct ip_mc_list *im;
int type;
struct net *net = dev_net(in_dev->dev);
ASSERT_RTNL();
for_each_pmc_rtnl(in_dev, im) {
if (im->multiaddr == IGMP_ALL_HOSTS)
continue;
if (ipv4_is_local_multicast(im->multiaddr) &&
!net->ipv4.sysctl_igmp_llm_reports)
continue;
if (IGMP_V1_SEEN(in_dev))
type = IGMP_HOST_MEMBERSHIP_REPORT;
else if (IGMP_V2_SEEN(in_dev))
type = IGMPV2_HOST_MEMBERSHIP_REPORT;
else
type = IGMPV3_HOST_MEMBERSHIP_REPORT;
igmp_send_report(in_dev, im, type);
}
#endif
}
void ip_mc_dec_group(struct in_device *in_dev, __be32 addr)
{
struct ip_mc_list *i;
struct ip_mc_list __rcu **ip;
ASSERT_RTNL();
for (ip = &in_dev->mc_list;
(i = rtnl_dereference(*ip)) != NULL;
ip = &i->next_rcu) {
if (i->multiaddr == addr) {
if (--i->users == 0) {
ip_mc_hash_remove(in_dev, i);
*ip = i->next_rcu;
in_dev->mc_count--;
igmp_group_dropped(i);
ip_mc_clear_src(i);
if (!in_dev->dead)
ip_rt_multicast_event(in_dev);
ip_ma_put(i);
return;
}
break;
}
}
}
void ip_mc_unmap(struct in_device *in_dev)
{
struct ip_mc_list *pmc;
ASSERT_RTNL();
for_each_pmc_rtnl(in_dev, pmc)
igmp_group_dropped(pmc);
}
void ip_mc_remap(struct in_device *in_dev)
{
struct ip_mc_list *pmc;
ASSERT_RTNL();
for_each_pmc_rtnl(in_dev, pmc) {
#ifdef CONFIG_IP_MULTICAST
igmpv3_del_delrec(in_dev, pmc);
#endif
igmp_group_added(pmc);
}
}
void ip_mc_down(struct in_device *in_dev)
{
struct ip_mc_list *pmc;
ASSERT_RTNL();
for_each_pmc_rtnl(in_dev, pmc)
igmp_group_dropped(pmc);
#ifdef CONFIG_IP_MULTICAST
in_dev->mr_ifc_count = 0;
if (del_timer(&in_dev->mr_ifc_timer))
__in_dev_put(in_dev);
in_dev->mr_gq_running = 0;
if (del_timer(&in_dev->mr_gq_timer))
__in_dev_put(in_dev);
#endif
ip_mc_dec_group(in_dev, IGMP_ALL_HOSTS);
}
void ip_mc_init_dev(struct in_device *in_dev)
{
#ifdef CONFIG_IP_MULTICAST
struct net *net = dev_net(in_dev->dev);
#endif
ASSERT_RTNL();
#ifdef CONFIG_IP_MULTICAST
setup_timer(&in_dev->mr_gq_timer, igmp_gq_timer_expire,
(unsigned long)in_dev);
setup_timer(&in_dev->mr_ifc_timer, igmp_ifc_timer_expire,
(unsigned long)in_dev);
in_dev->mr_qrv = net->ipv4.sysctl_igmp_qrv;
#endif
spin_lock_init(&in_dev->mc_tomb_lock);
}
void ip_mc_up(struct in_device *in_dev)
{
struct ip_mc_list *pmc;
#ifdef CONFIG_IP_MULTICAST
struct net *net = dev_net(in_dev->dev);
#endif
ASSERT_RTNL();
#ifdef CONFIG_IP_MULTICAST
in_dev->mr_qrv = net->ipv4.sysctl_igmp_qrv;
#endif
ip_mc_inc_group(in_dev, IGMP_ALL_HOSTS);
for_each_pmc_rtnl(in_dev, pmc) {
#ifdef CONFIG_IP_MULTICAST
igmpv3_del_delrec(in_dev, pmc);
#endif
igmp_group_added(pmc);
}
}
void ip_mc_destroy_dev(struct in_device *in_dev)
{
struct ip_mc_list *i;
ASSERT_RTNL();
ip_mc_down(in_dev);
#ifdef CONFIG_IP_MULTICAST
igmpv3_clear_delrec(in_dev);
#endif
while ((i = rtnl_dereference(in_dev->mc_list)) != NULL) {
in_dev->mc_list = i->next_rcu;
in_dev->mc_count--;
ip_ma_put(i);
}
}
static struct in_device *ip_mc_find_dev(struct net *net, struct ip_mreqn *imr)
{
struct net_device *dev = NULL;
struct in_device *idev = NULL;
if (imr->imr_ifindex) {
idev = inetdev_by_index(net, imr->imr_ifindex);
return idev;
}
if (imr->imr_address.s_addr) {
dev = __ip_dev_find(net, imr->imr_address.s_addr, false);
if (!dev)
return NULL;
}
if (!dev) {
struct rtable *rt = ip_route_output(net,
imr->imr_multiaddr.s_addr,
0, 0, 0);
if (!IS_ERR(rt)) {
dev = rt->dst.dev;
ip_rt_put(rt);
}
}
if (dev) {
imr->imr_ifindex = dev->ifindex;
idev = __in_dev_get_rtnl(dev);
}
return idev;
}
static int ip_mc_del1_src(struct ip_mc_list *pmc, int sfmode,
__be32 *psfsrc)
{
struct ip_sf_list *psf, *psf_prev;
int rv = 0;
psf_prev = NULL;
for (psf = pmc->sources; psf; psf = psf->sf_next) {
if (psf->sf_inaddr == *psfsrc)
break;
psf_prev = psf;
}
if (!psf || psf->sf_count[sfmode] == 0) {
return -ESRCH;
}
psf->sf_count[sfmode]--;
if (psf->sf_count[sfmode] == 0) {
ip_rt_multicast_event(pmc->interface);
}
if (!psf->sf_count[MCAST_INCLUDE] && !psf->sf_count[MCAST_EXCLUDE]) {
#ifdef CONFIG_IP_MULTICAST
struct in_device *in_dev = pmc->interface;
struct net *net = dev_net(in_dev->dev);
#endif
if (psf_prev)
psf_prev->sf_next = psf->sf_next;
else
pmc->sources = psf->sf_next;
#ifdef CONFIG_IP_MULTICAST
if (psf->sf_oldin &&
!IGMP_V1_SEEN(in_dev) && !IGMP_V2_SEEN(in_dev)) {
psf->sf_crcount = in_dev->mr_qrv ?: net->ipv4.sysctl_igmp_qrv;
psf->sf_next = pmc->tomb;
pmc->tomb = psf;
rv = 1;
} else
#endif
kfree(psf);
}
return rv;
}
static int ip_mc_del_src(struct in_device *in_dev, __be32 *pmca, int sfmode,
int sfcount, __be32 *psfsrc, int delta)
{
struct ip_mc_list *pmc;
int changerec = 0;
int i, err;
if (!in_dev)
return -ENODEV;
rcu_read_lock();
for_each_pmc_rcu(in_dev, pmc) {
if (*pmca == pmc->multiaddr)
break;
}
if (!pmc) {
rcu_read_unlock();
return -ESRCH;
}
spin_lock_bh(&pmc->lock);
rcu_read_unlock();
#ifdef CONFIG_IP_MULTICAST
sf_markstate(pmc);
#endif
if (!delta) {
err = -EINVAL;
if (!pmc->sfcount[sfmode])
goto out_unlock;
pmc->sfcount[sfmode]--;
}
err = 0;
for (i = 0; i < sfcount; i++) {
int rv = ip_mc_del1_src(pmc, sfmode, &psfsrc[i]);
changerec |= rv > 0;
if (!err && rv < 0)
err = rv;
}
if (pmc->sfmode == MCAST_EXCLUDE &&
pmc->sfcount[MCAST_EXCLUDE] == 0 &&
pmc->sfcount[MCAST_INCLUDE]) {
#ifdef CONFIG_IP_MULTICAST
struct ip_sf_list *psf;
struct net *net = dev_net(in_dev->dev);
#endif
pmc->sfmode = MCAST_INCLUDE;
#ifdef CONFIG_IP_MULTICAST
pmc->crcount = in_dev->mr_qrv ?: net->ipv4.sysctl_igmp_qrv;
in_dev->mr_ifc_count = pmc->crcount;
for (psf = pmc->sources; psf; psf = psf->sf_next)
psf->sf_crcount = 0;
igmp_ifc_event(pmc->interface);
} else if (sf_setstate(pmc) || changerec) {
igmp_ifc_event(pmc->interface);
#endif
}
out_unlock:
spin_unlock_bh(&pmc->lock);
return err;
}
static int ip_mc_add1_src(struct ip_mc_list *pmc, int sfmode,
__be32 *psfsrc)
{
struct ip_sf_list *psf, *psf_prev;
psf_prev = NULL;
for (psf = pmc->sources; psf; psf = psf->sf_next) {
if (psf->sf_inaddr == *psfsrc)
break;
psf_prev = psf;
}
if (!psf) {
psf = kzalloc(sizeof(*psf), GFP_ATOMIC);
if (!psf)
return -ENOBUFS;
psf->sf_inaddr = *psfsrc;
if (psf_prev) {
psf_prev->sf_next = psf;
} else
pmc->sources = psf;
}
psf->sf_count[sfmode]++;
if (psf->sf_count[sfmode] == 1) {
ip_rt_multicast_event(pmc->interface);
}
return 0;
}
static void sf_markstate(struct ip_mc_list *pmc)
{
struct ip_sf_list *psf;
int mca_xcount = pmc->sfcount[MCAST_EXCLUDE];
for (psf = pmc->sources; psf; psf = psf->sf_next)
if (pmc->sfcount[MCAST_EXCLUDE]) {
psf->sf_oldin = mca_xcount ==
psf->sf_count[MCAST_EXCLUDE] &&
!psf->sf_count[MCAST_INCLUDE];
} else
psf->sf_oldin = psf->sf_count[MCAST_INCLUDE] != 0;
}
static int sf_setstate(struct ip_mc_list *pmc)
{
struct ip_sf_list *psf, *dpsf;
int mca_xcount = pmc->sfcount[MCAST_EXCLUDE];
int qrv = pmc->interface->mr_qrv;
int new_in, rv;
rv = 0;
for (psf = pmc->sources; psf; psf = psf->sf_next) {
if (pmc->sfcount[MCAST_EXCLUDE]) {
new_in = mca_xcount == psf->sf_count[MCAST_EXCLUDE] &&
!psf->sf_count[MCAST_INCLUDE];
} else
new_in = psf->sf_count[MCAST_INCLUDE] != 0;
if (new_in) {
if (!psf->sf_oldin) {
struct ip_sf_list *prev = NULL;
for (dpsf = pmc->tomb; dpsf; dpsf = dpsf->sf_next) {
if (dpsf->sf_inaddr == psf->sf_inaddr)
break;
prev = dpsf;
}
if (dpsf) {
if (prev)
prev->sf_next = dpsf->sf_next;
else
pmc->tomb = dpsf->sf_next;
kfree(dpsf);
}
psf->sf_crcount = qrv;
rv++;
}
} else if (psf->sf_oldin) {
psf->sf_crcount = 0;
for (dpsf = pmc->tomb; dpsf; dpsf = dpsf->sf_next)
if (dpsf->sf_inaddr == psf->sf_inaddr)
break;
if (!dpsf) {
dpsf = kmalloc(sizeof(*dpsf), GFP_ATOMIC);
if (!dpsf)
continue;
*dpsf = *psf;
dpsf->sf_next = pmc->tomb;
pmc->tomb = dpsf;
}
dpsf->sf_crcount = qrv;
rv++;
}
}
return rv;
}
static int ip_mc_add_src(struct in_device *in_dev, __be32 *pmca, int sfmode,
int sfcount, __be32 *psfsrc, int delta)
{
struct ip_mc_list *pmc;
int isexclude;
int i, err;
if (!in_dev)
return -ENODEV;
rcu_read_lock();
for_each_pmc_rcu(in_dev, pmc) {
if (*pmca == pmc->multiaddr)
break;
}
if (!pmc) {
rcu_read_unlock();
return -ESRCH;
}
spin_lock_bh(&pmc->lock);
rcu_read_unlock();
#ifdef CONFIG_IP_MULTICAST
sf_markstate(pmc);
#endif
isexclude = pmc->sfmode == MCAST_EXCLUDE;
if (!delta)
pmc->sfcount[sfmode]++;
err = 0;
for (i = 0; i < sfcount; i++) {
err = ip_mc_add1_src(pmc, sfmode, &psfsrc[i]);
if (err)
break;
}
if (err) {
int j;
if (!delta)
pmc->sfcount[sfmode]--;
for (j = 0; j < i; j++)
(void) ip_mc_del1_src(pmc, sfmode, &psfsrc[j]);
} else if (isexclude != (pmc->sfcount[MCAST_EXCLUDE] != 0)) {
#ifdef CONFIG_IP_MULTICAST
struct ip_sf_list *psf;
struct net *net = dev_net(pmc->interface->dev);
in_dev = pmc->interface;
#endif
if (pmc->sfcount[MCAST_EXCLUDE])
pmc->sfmode = MCAST_EXCLUDE;
else if (pmc->sfcount[MCAST_INCLUDE])
pmc->sfmode = MCAST_INCLUDE;
#ifdef CONFIG_IP_MULTICAST
pmc->crcount = in_dev->mr_qrv ?: net->ipv4.sysctl_igmp_qrv;
in_dev->mr_ifc_count = pmc->crcount;
for (psf = pmc->sources; psf; psf = psf->sf_next)
psf->sf_crcount = 0;
igmp_ifc_event(in_dev);
} else if (sf_setstate(pmc)) {
igmp_ifc_event(in_dev);
#endif
}
spin_unlock_bh(&pmc->lock);
return err;
}
static void ip_mc_clear_src(struct ip_mc_list *pmc)
{
struct ip_sf_list *psf, *nextpsf, *tomb, *sources;
spin_lock_bh(&pmc->lock);
tomb = pmc->tomb;
pmc->tomb = NULL;
sources = pmc->sources;
pmc->sources = NULL;
pmc->sfmode = MCAST_EXCLUDE;
pmc->sfcount[MCAST_INCLUDE] = 0;
pmc->sfcount[MCAST_EXCLUDE] = 1;
spin_unlock_bh(&pmc->lock);
for (psf = tomb; psf; psf = nextpsf) {
nextpsf = psf->sf_next;
kfree(psf);
}
for (psf = sources; psf; psf = nextpsf) {
nextpsf = psf->sf_next;
kfree(psf);
}
}
int ip_mc_join_group(struct sock *sk, struct ip_mreqn *imr)
{
__be32 addr = imr->imr_multiaddr.s_addr;
struct ip_mc_socklist *iml, *i;
struct in_device *in_dev;
struct inet_sock *inet = inet_sk(sk);
struct net *net = sock_net(sk);
int ifindex;
int count = 0;
int err;
ASSERT_RTNL();
if (!ipv4_is_multicast(addr))
return -EINVAL;
in_dev = ip_mc_find_dev(net, imr);
if (!in_dev) {
err = -ENODEV;
goto done;
}
err = -EADDRINUSE;
ifindex = imr->imr_ifindex;
for_each_pmc_rtnl(inet, i) {
if (i->multi.imr_multiaddr.s_addr == addr &&
i->multi.imr_ifindex == ifindex)
goto done;
count++;
}
err = -ENOBUFS;
if (count >= net->ipv4.sysctl_igmp_max_memberships)
goto done;
iml = sock_kmalloc(sk, sizeof(*iml), GFP_KERNEL);
if (!iml)
goto done;
memcpy(&iml->multi, imr, sizeof(*imr));
iml->next_rcu = inet->mc_list;
iml->sflist = NULL;
iml->sfmode = MCAST_EXCLUDE;
rcu_assign_pointer(inet->mc_list, iml);
ip_mc_inc_group(in_dev, addr);
err = 0;
done:
return err;
}
static int ip_mc_leave_src(struct sock *sk, struct ip_mc_socklist *iml,
struct in_device *in_dev)
{
struct ip_sf_socklist *psf = rtnl_dereference(iml->sflist);
int err;
if (!psf) {
return ip_mc_del_src(in_dev, &iml->multi.imr_multiaddr.s_addr,
iml->sfmode, 0, NULL, 0);
}
err = ip_mc_del_src(in_dev, &iml->multi.imr_multiaddr.s_addr,
iml->sfmode, psf->sl_count, psf->sl_addr, 0);
RCU_INIT_POINTER(iml->sflist, NULL);
atomic_sub(IP_SFLSIZE(psf->sl_max), &sk->sk_omem_alloc);
kfree_rcu(psf, rcu);
return err;
}
int ip_mc_leave_group(struct sock *sk, struct ip_mreqn *imr)
{
struct inet_sock *inet = inet_sk(sk);
struct ip_mc_socklist *iml;
struct ip_mc_socklist __rcu **imlp;
struct in_device *in_dev;
struct net *net = sock_net(sk);
__be32 group = imr->imr_multiaddr.s_addr;
u32 ifindex;
int ret = -EADDRNOTAVAIL;
ASSERT_RTNL();
in_dev = ip_mc_find_dev(net, imr);
if (!imr->imr_ifindex && !imr->imr_address.s_addr && !in_dev) {
ret = -ENODEV;
goto out;
}
ifindex = imr->imr_ifindex;
for (imlp = &inet->mc_list;
(iml = rtnl_dereference(*imlp)) != NULL;
imlp = &iml->next_rcu) {
if (iml->multi.imr_multiaddr.s_addr != group)
continue;
if (ifindex) {
if (iml->multi.imr_ifindex != ifindex)
continue;
} else if (imr->imr_address.s_addr && imr->imr_address.s_addr !=
iml->multi.imr_address.s_addr)
continue;
(void) ip_mc_leave_src(sk, iml, in_dev);
*imlp = iml->next_rcu;
if (in_dev)
ip_mc_dec_group(in_dev, group);
atomic_sub(sizeof(*iml), &sk->sk_omem_alloc);
kfree_rcu(iml, rcu);
return 0;
}
out:
return ret;
}
int ip_mc_source(int add, int omode, struct sock *sk, struct
ip_mreq_source *mreqs, int ifindex)
{
int err;
struct ip_mreqn imr;
__be32 addr = mreqs->imr_multiaddr;
struct ip_mc_socklist *pmc;
struct in_device *in_dev = NULL;
struct inet_sock *inet = inet_sk(sk);
struct ip_sf_socklist *psl;
struct net *net = sock_net(sk);
int leavegroup = 0;
int i, j, rv;
if (!ipv4_is_multicast(addr))
return -EINVAL;
ASSERT_RTNL();
imr.imr_multiaddr.s_addr = mreqs->imr_multiaddr;
imr.imr_address.s_addr = mreqs->imr_interface;
imr.imr_ifindex = ifindex;
in_dev = ip_mc_find_dev(net, &imr);
if (!in_dev) {
err = -ENODEV;
goto done;
}
err = -EADDRNOTAVAIL;
for_each_pmc_rtnl(inet, pmc) {
if ((pmc->multi.imr_multiaddr.s_addr ==
imr.imr_multiaddr.s_addr) &&
(pmc->multi.imr_ifindex == imr.imr_ifindex))
break;
}
if (!pmc) {
err = -EINVAL;
goto done;
}
if (pmc->sflist) {
if (pmc->sfmode != omode) {
err = -EINVAL;
goto done;
}
} else if (pmc->sfmode != omode) {
ip_mc_add_src(in_dev, &mreqs->imr_multiaddr, omode, 0, NULL, 0);
ip_mc_del_src(in_dev, &mreqs->imr_multiaddr, pmc->sfmode, 0,
NULL, 0);
pmc->sfmode = omode;
}
psl = rtnl_dereference(pmc->sflist);
if (!add) {
if (!psl)
goto done;
rv = !0;
for (i = 0; i < psl->sl_count; i++) {
rv = memcmp(&psl->sl_addr[i], &mreqs->imr_sourceaddr,
sizeof(__be32));
if (rv == 0)
break;
}
if (rv)
goto done;
if (psl->sl_count == 1 && omode == MCAST_INCLUDE) {
leavegroup = 1;
goto done;
}
ip_mc_del_src(in_dev, &mreqs->imr_multiaddr, omode, 1,
&mreqs->imr_sourceaddr, 1);
for (j = i+1; j < psl->sl_count; j++)
psl->sl_addr[j-1] = psl->sl_addr[j];
psl->sl_count--;
err = 0;
goto done;
}
if (psl && psl->sl_count >= net->ipv4.sysctl_igmp_max_msf) {
err = -ENOBUFS;
goto done;
}
if (!psl || psl->sl_count == psl->sl_max) {
struct ip_sf_socklist *newpsl;
int count = IP_SFBLOCK;
if (psl)
count += psl->sl_max;
newpsl = sock_kmalloc(sk, IP_SFLSIZE(count), GFP_KERNEL);
if (!newpsl) {
err = -ENOBUFS;
goto done;
}
newpsl->sl_max = count;
newpsl->sl_count = count - IP_SFBLOCK;
if (psl) {
for (i = 0; i < psl->sl_count; i++)
newpsl->sl_addr[i] = psl->sl_addr[i];
atomic_sub(IP_SFLSIZE(psl->sl_max), &sk->sk_omem_alloc);
kfree_rcu(psl, rcu);
}
rcu_assign_pointer(pmc->sflist, newpsl);
psl = newpsl;
}
rv = 1;
for (i = 0; i < psl->sl_count; i++) {
rv = memcmp(&psl->sl_addr[i], &mreqs->imr_sourceaddr,
sizeof(__be32));
if (rv == 0)
break;
}
if (rv == 0)
goto done;
for (j = psl->sl_count-1; j >= i; j--)
psl->sl_addr[j+1] = psl->sl_addr[j];
psl->sl_addr[i] = mreqs->imr_sourceaddr;
psl->sl_count++;
err = 0;
ip_mc_add_src(in_dev, &mreqs->imr_multiaddr, omode, 1,
&mreqs->imr_sourceaddr, 1);
done:
if (leavegroup)
err = ip_mc_leave_group(sk, &imr);
return err;
}
int ip_mc_msfilter(struct sock *sk, struct ip_msfilter *msf, int ifindex)
{
int err = 0;
struct ip_mreqn imr;
__be32 addr = msf->imsf_multiaddr;
struct ip_mc_socklist *pmc;
struct in_device *in_dev;
struct inet_sock *inet = inet_sk(sk);
struct ip_sf_socklist *newpsl, *psl;
struct net *net = sock_net(sk);
int leavegroup = 0;
if (!ipv4_is_multicast(addr))
return -EINVAL;
if (msf->imsf_fmode != MCAST_INCLUDE &&
msf->imsf_fmode != MCAST_EXCLUDE)
return -EINVAL;
ASSERT_RTNL();
imr.imr_multiaddr.s_addr = msf->imsf_multiaddr;
imr.imr_address.s_addr = msf->imsf_interface;
imr.imr_ifindex = ifindex;
in_dev = ip_mc_find_dev(net, &imr);
if (!in_dev) {
err = -ENODEV;
goto done;
}
if (msf->imsf_fmode == MCAST_INCLUDE && msf->imsf_numsrc == 0) {
leavegroup = 1;
goto done;
}
for_each_pmc_rtnl(inet, pmc) {
if (pmc->multi.imr_multiaddr.s_addr == msf->imsf_multiaddr &&
pmc->multi.imr_ifindex == imr.imr_ifindex)
break;
}
if (!pmc) {
err = -EINVAL;
goto done;
}
if (msf->imsf_numsrc) {
newpsl = sock_kmalloc(sk, IP_SFLSIZE(msf->imsf_numsrc),
GFP_KERNEL);
if (!newpsl) {
err = -ENOBUFS;
goto done;
}
newpsl->sl_max = newpsl->sl_count = msf->imsf_numsrc;
memcpy(newpsl->sl_addr, msf->imsf_slist,
msf->imsf_numsrc * sizeof(msf->imsf_slist[0]));
err = ip_mc_add_src(in_dev, &msf->imsf_multiaddr,
msf->imsf_fmode, newpsl->sl_count, newpsl->sl_addr, 0);
if (err) {
sock_kfree_s(sk, newpsl, IP_SFLSIZE(newpsl->sl_max));
goto done;
}
} else {
newpsl = NULL;
(void) ip_mc_add_src(in_dev, &msf->imsf_multiaddr,
msf->imsf_fmode, 0, NULL, 0);
}
psl = rtnl_dereference(pmc->sflist);
if (psl) {
(void) ip_mc_del_src(in_dev, &msf->imsf_multiaddr, pmc->sfmode,
psl->sl_count, psl->sl_addr, 0);
atomic_sub(IP_SFLSIZE(psl->sl_max), &sk->sk_omem_alloc);
kfree_rcu(psl, rcu);
} else
(void) ip_mc_del_src(in_dev, &msf->imsf_multiaddr, pmc->sfmode,
0, NULL, 0);
rcu_assign_pointer(pmc->sflist, newpsl);
pmc->sfmode = msf->imsf_fmode;
err = 0;
done:
if (leavegroup)
err = ip_mc_leave_group(sk, &imr);
return err;
}
int ip_mc_msfget(struct sock *sk, struct ip_msfilter *msf,
struct ip_msfilter __user *optval, int __user *optlen)
{
int err, len, count, copycount;
struct ip_mreqn imr;
__be32 addr = msf->imsf_multiaddr;
struct ip_mc_socklist *pmc;
struct in_device *in_dev;
struct inet_sock *inet = inet_sk(sk);
struct ip_sf_socklist *psl;
struct net *net = sock_net(sk);
ASSERT_RTNL();
if (!ipv4_is_multicast(addr))
return -EINVAL;
imr.imr_multiaddr.s_addr = msf->imsf_multiaddr;
imr.imr_address.s_addr = msf->imsf_interface;
imr.imr_ifindex = 0;
in_dev = ip_mc_find_dev(net, &imr);
if (!in_dev) {
err = -ENODEV;
goto done;
}
err = -EADDRNOTAVAIL;
for_each_pmc_rtnl(inet, pmc) {
if (pmc->multi.imr_multiaddr.s_addr == msf->imsf_multiaddr &&
pmc->multi.imr_ifindex == imr.imr_ifindex)
break;
}
if (!pmc)
goto done;
msf->imsf_fmode = pmc->sfmode;
psl = rtnl_dereference(pmc->sflist);
if (!psl) {
len = 0;
count = 0;
} else {
count = psl->sl_count;
}
copycount = count < msf->imsf_numsrc ? count : msf->imsf_numsrc;
len = copycount * sizeof(psl->sl_addr[0]);
msf->imsf_numsrc = count;
if (put_user(IP_MSFILTER_SIZE(copycount), optlen) ||
copy_to_user(optval, msf, IP_MSFILTER_SIZE(0))) {
return -EFAULT;
}
if (len &&
copy_to_user(&optval->imsf_slist[0], psl->sl_addr, len))
return -EFAULT;
return 0;
done:
return err;
}
int ip_mc_gsfget(struct sock *sk, struct group_filter *gsf,
struct group_filter __user *optval, int __user *optlen)
{
int err, i, count, copycount;
struct sockaddr_in *psin;
__be32 addr;
struct ip_mc_socklist *pmc;
struct inet_sock *inet = inet_sk(sk);
struct ip_sf_socklist *psl;
ASSERT_RTNL();
psin = (struct sockaddr_in *)&gsf->gf_group;
if (psin->sin_family != AF_INET)
return -EINVAL;
addr = psin->sin_addr.s_addr;
if (!ipv4_is_multicast(addr))
return -EINVAL;
err = -EADDRNOTAVAIL;
for_each_pmc_rtnl(inet, pmc) {
if (pmc->multi.imr_multiaddr.s_addr == addr &&
pmc->multi.imr_ifindex == gsf->gf_interface)
break;
}
if (!pmc)
goto done;
gsf->gf_fmode = pmc->sfmode;
psl = rtnl_dereference(pmc->sflist);
count = psl ? psl->sl_count : 0;
copycount = count < gsf->gf_numsrc ? count : gsf->gf_numsrc;
gsf->gf_numsrc = count;
if (put_user(GROUP_FILTER_SIZE(copycount), optlen) ||
copy_to_user(optval, gsf, GROUP_FILTER_SIZE(0))) {
return -EFAULT;
}
for (i = 0; i < copycount; i++) {
struct sockaddr_storage ss;
psin = (struct sockaddr_in *)&ss;
memset(&ss, 0, sizeof(ss));
psin->sin_family = AF_INET;
psin->sin_addr.s_addr = psl->sl_addr[i];
if (copy_to_user(&optval->gf_slist[i], &ss, sizeof(ss)))
return -EFAULT;
}
return 0;
done:
return err;
}
int ip_mc_sf_allow(struct sock *sk, __be32 loc_addr, __be32 rmt_addr, int dif)
{
struct inet_sock *inet = inet_sk(sk);
struct ip_mc_socklist *pmc;
struct ip_sf_socklist *psl;
int i;
int ret;
ret = 1;
if (!ipv4_is_multicast(loc_addr))
goto out;
rcu_read_lock();
for_each_pmc_rcu(inet, pmc) {
if (pmc->multi.imr_multiaddr.s_addr == loc_addr &&
pmc->multi.imr_ifindex == dif)
break;
}
ret = inet->mc_all;
if (!pmc)
goto unlock;
psl = rcu_dereference(pmc->sflist);
ret = (pmc->sfmode == MCAST_EXCLUDE);
if (!psl)
goto unlock;
for (i = 0; i < psl->sl_count; i++) {
if (psl->sl_addr[i] == rmt_addr)
break;
}
ret = 0;
if (pmc->sfmode == MCAST_INCLUDE && i >= psl->sl_count)
goto unlock;
if (pmc->sfmode == MCAST_EXCLUDE && i < psl->sl_count)
goto unlock;
ret = 1;
unlock:
rcu_read_unlock();
out:
return ret;
}
void ip_mc_drop_socket(struct sock *sk)
{
struct inet_sock *inet = inet_sk(sk);
struct ip_mc_socklist *iml;
struct net *net = sock_net(sk);
if (!inet->mc_list)
return;
rtnl_lock();
while ((iml = rtnl_dereference(inet->mc_list)) != NULL) {
struct in_device *in_dev;
inet->mc_list = iml->next_rcu;
in_dev = inetdev_by_index(net, iml->multi.imr_ifindex);
(void) ip_mc_leave_src(sk, iml, in_dev);
if (in_dev)
ip_mc_dec_group(in_dev, iml->multi.imr_multiaddr.s_addr);
atomic_sub(sizeof(*iml), &sk->sk_omem_alloc);
kfree_rcu(iml, rcu);
}
rtnl_unlock();
}
int ip_check_mc_rcu(struct in_device *in_dev, __be32 mc_addr, __be32 src_addr, u8 proto)
{
struct ip_mc_list *im;
struct ip_mc_list __rcu **mc_hash;
struct ip_sf_list *psf;
int rv = 0;
mc_hash = rcu_dereference(in_dev->mc_hash);
if (mc_hash) {
u32 hash = hash_32((__force u32)mc_addr, MC_HASH_SZ_LOG);
for (im = rcu_dereference(mc_hash[hash]);
im != NULL;
im = rcu_dereference(im->next_hash)) {
if (im->multiaddr == mc_addr)
break;
}
} else {
for_each_pmc_rcu(in_dev, im) {
if (im->multiaddr == mc_addr)
break;
}
}
if (im && proto == IPPROTO_IGMP) {
rv = 1;
} else if (im) {
if (src_addr) {
for (psf = im->sources; psf; psf = psf->sf_next) {
if (psf->sf_inaddr == src_addr)
break;
}
if (psf)
rv = psf->sf_count[MCAST_INCLUDE] ||
psf->sf_count[MCAST_EXCLUDE] !=
im->sfcount[MCAST_EXCLUDE];
else
rv = im->sfcount[MCAST_EXCLUDE] != 0;
} else
rv = 1;
}
return rv;
}
static inline struct ip_mc_list *igmp_mc_get_first(struct seq_file *seq)
{
struct net *net = seq_file_net(seq);
struct ip_mc_list *im = NULL;
struct igmp_mc_iter_state *state = igmp_mc_seq_private(seq);
state->in_dev = NULL;
for_each_netdev_rcu(net, state->dev) {
struct in_device *in_dev;
in_dev = __in_dev_get_rcu(state->dev);
if (!in_dev)
continue;
im = rcu_dereference(in_dev->mc_list);
if (im) {
state->in_dev = in_dev;
break;
}
}
return im;
}
static struct ip_mc_list *igmp_mc_get_next(struct seq_file *seq, struct ip_mc_list *im)
{
struct igmp_mc_iter_state *state = igmp_mc_seq_private(seq);
im = rcu_dereference(im->next_rcu);
while (!im) {
state->dev = next_net_device_rcu(state->dev);
if (!state->dev) {
state->in_dev = NULL;
break;
}
state->in_dev = __in_dev_get_rcu(state->dev);
if (!state->in_dev)
continue;
im = rcu_dereference(state->in_dev->mc_list);
}
return im;
}
static struct ip_mc_list *igmp_mc_get_idx(struct seq_file *seq, loff_t pos)
{
struct ip_mc_list *im = igmp_mc_get_first(seq);
if (im)
while (pos && (im = igmp_mc_get_next(seq, im)) != NULL)
--pos;
return pos ? NULL : im;
}
static void *igmp_mc_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(rcu)
{
rcu_read_lock();
return *pos ? igmp_mc_get_idx(seq, *pos - 1) : SEQ_START_TOKEN;
}
static void *igmp_mc_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct ip_mc_list *im;
if (v == SEQ_START_TOKEN)
im = igmp_mc_get_first(seq);
else
im = igmp_mc_get_next(seq, v);
++*pos;
return im;
}
static void igmp_mc_seq_stop(struct seq_file *seq, void *v)
__releases(rcu)
{
struct igmp_mc_iter_state *state = igmp_mc_seq_private(seq);
state->in_dev = NULL;
state->dev = NULL;
rcu_read_unlock();
}
static int igmp_mc_seq_show(struct seq_file *seq, void *v)
{
if (v == SEQ_START_TOKEN)
seq_puts(seq,
"Idx\tDevice : Count Querier\tGroup Users Timer\tReporter\n");
else {
struct ip_mc_list *im = (struct ip_mc_list *)v;
struct igmp_mc_iter_state *state = igmp_mc_seq_private(seq);
char *querier;
long delta;
#ifdef CONFIG_IP_MULTICAST
querier = IGMP_V1_SEEN(state->in_dev) ? "V1" :
IGMP_V2_SEEN(state->in_dev) ? "V2" :
"V3";
#else
querier = "NONE";
#endif
if (rcu_access_pointer(state->in_dev->mc_list) == im) {
seq_printf(seq, "%d\t%-10s: %5d %7s\n",
state->dev->ifindex, state->dev->name, state->in_dev->mc_count, querier);
}
delta = im->timer.expires - jiffies;
seq_printf(seq,
"\t\t\t\t%08X %5d %d:%08lX\t\t%d\n",
im->multiaddr, im->users,
im->tm_running,
im->tm_running ? jiffies_delta_to_clock_t(delta) : 0,
im->reporter);
}
return 0;
}
static int igmp_mc_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &igmp_mc_seq_ops,
sizeof(struct igmp_mc_iter_state));
}
static inline struct ip_sf_list *igmp_mcf_get_first(struct seq_file *seq)
{
struct net *net = seq_file_net(seq);
struct ip_sf_list *psf = NULL;
struct ip_mc_list *im = NULL;
struct igmp_mcf_iter_state *state = igmp_mcf_seq_private(seq);
state->idev = NULL;
state->im = NULL;
for_each_netdev_rcu(net, state->dev) {
struct in_device *idev;
idev = __in_dev_get_rcu(state->dev);
if (unlikely(!idev))
continue;
im = rcu_dereference(idev->mc_list);
if (likely(im)) {
spin_lock_bh(&im->lock);
psf = im->sources;
if (likely(psf)) {
state->im = im;
state->idev = idev;
break;
}
spin_unlock_bh(&im->lock);
}
}
return psf;
}
static struct ip_sf_list *igmp_mcf_get_next(struct seq_file *seq, struct ip_sf_list *psf)
{
struct igmp_mcf_iter_state *state = igmp_mcf_seq_private(seq);
psf = psf->sf_next;
while (!psf) {
spin_unlock_bh(&state->im->lock);
state->im = state->im->next;
while (!state->im) {
state->dev = next_net_device_rcu(state->dev);
if (!state->dev) {
state->idev = NULL;
goto out;
}
state->idev = __in_dev_get_rcu(state->dev);
if (!state->idev)
continue;
state->im = rcu_dereference(state->idev->mc_list);
}
if (!state->im)
break;
spin_lock_bh(&state->im->lock);
psf = state->im->sources;
}
out:
return psf;
}
static struct ip_sf_list *igmp_mcf_get_idx(struct seq_file *seq, loff_t pos)
{
struct ip_sf_list *psf = igmp_mcf_get_first(seq);
if (psf)
while (pos && (psf = igmp_mcf_get_next(seq, psf)) != NULL)
--pos;
return pos ? NULL : psf;
}
static void *igmp_mcf_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(rcu)
{
rcu_read_lock();
return *pos ? igmp_mcf_get_idx(seq, *pos - 1) : SEQ_START_TOKEN;
}
static void *igmp_mcf_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct ip_sf_list *psf;
if (v == SEQ_START_TOKEN)
psf = igmp_mcf_get_first(seq);
else
psf = igmp_mcf_get_next(seq, v);
++*pos;
return psf;
}
static void igmp_mcf_seq_stop(struct seq_file *seq, void *v)
__releases(rcu)
{
struct igmp_mcf_iter_state *state = igmp_mcf_seq_private(seq);
if (likely(state->im)) {
spin_unlock_bh(&state->im->lock);
state->im = NULL;
}
state->idev = NULL;
state->dev = NULL;
rcu_read_unlock();
}
static int igmp_mcf_seq_show(struct seq_file *seq, void *v)
{
struct ip_sf_list *psf = (struct ip_sf_list *)v;
struct igmp_mcf_iter_state *state = igmp_mcf_seq_private(seq);
if (v == SEQ_START_TOKEN) {
seq_puts(seq, "Idx Device MCA SRC INC EXC\n");
} else {
seq_printf(seq,
"%3d %6.6s 0x%08x "
"0x%08x %6lu %6lu\n",
state->dev->ifindex, state->dev->name,
ntohl(state->im->multiaddr),
ntohl(psf->sf_inaddr),
psf->sf_count[MCAST_INCLUDE],
psf->sf_count[MCAST_EXCLUDE]);
}
return 0;
}
static int igmp_mcf_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &igmp_mcf_seq_ops,
sizeof(struct igmp_mcf_iter_state));
}
static int __net_init igmp_net_init(struct net *net)
{
struct proc_dir_entry *pde;
int err;
pde = proc_create("igmp", S_IRUGO, net->proc_net, &igmp_mc_seq_fops);
if (!pde)
goto out_igmp;
pde = proc_create("mcfilter", S_IRUGO, net->proc_net,
&igmp_mcf_seq_fops);
if (!pde)
goto out_mcfilter;
err = inet_ctl_sock_create(&net->ipv4.mc_autojoin_sk, AF_INET,
SOCK_DGRAM, 0, net);
if (err < 0) {
pr_err("Failed to initialize the IGMP autojoin socket (err %d)\n",
err);
goto out_sock;
}
net->ipv4.sysctl_igmp_max_memberships = 20;
net->ipv4.sysctl_igmp_max_msf = 10;
net->ipv4.sysctl_igmp_llm_reports = 1;
net->ipv4.sysctl_igmp_qrv = 2;
return 0;
out_sock:
remove_proc_entry("mcfilter", net->proc_net);
out_mcfilter:
remove_proc_entry("igmp", net->proc_net);
out_igmp:
return -ENOMEM;
}
static void __net_exit igmp_net_exit(struct net *net)
{
remove_proc_entry("mcfilter", net->proc_net);
remove_proc_entry("igmp", net->proc_net);
inet_ctl_sock_destroy(net->ipv4.mc_autojoin_sk);
}
static int igmp_netdev_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct in_device *in_dev;
switch (event) {
case NETDEV_RESEND_IGMP:
in_dev = __in_dev_get_rtnl(dev);
if (in_dev)
ip_mc_rejoin_groups(in_dev);
break;
default:
break;
}
return NOTIFY_DONE;
}
int __init igmp_mc_init(void)
{
#if defined(CONFIG_PROC_FS)
int err;
err = register_pernet_subsys(&igmp_net_ops);
if (err)
return err;
err = register_netdevice_notifier(&igmp_notifier);
if (err)
goto reg_notif_fail;
return 0;
reg_notif_fail:
unregister_pernet_subsys(&igmp_net_ops);
return err;
#else
return register_netdevice_notifier(&igmp_notifier);
#endif
}
