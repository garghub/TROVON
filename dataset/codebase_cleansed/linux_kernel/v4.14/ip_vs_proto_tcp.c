static int
tcp_conn_schedule(struct netns_ipvs *ipvs, int af, struct sk_buff *skb,
struct ip_vs_proto_data *pd,
int *verdict, struct ip_vs_conn **cpp,
struct ip_vs_iphdr *iph)
{
struct ip_vs_service *svc;
struct tcphdr _tcph, *th;
__be16 _ports[2], *ports = NULL;
if (likely(!ip_vs_iph_icmp(iph))) {
th = skb_header_pointer(skb, iph->len, sizeof(_tcph), &_tcph);
if (th) {
if (th->rst || !(sysctl_sloppy_tcp(ipvs) || th->syn))
return 1;
ports = &th->source;
}
} else {
ports = skb_header_pointer(
skb, iph->len, sizeof(_ports), &_ports);
}
if (!ports) {
*verdict = NF_DROP;
return 0;
}
if (likely(!ip_vs_iph_inverse(iph)))
svc = ip_vs_service_find(ipvs, af, skb->mark, iph->protocol,
&iph->daddr, ports[1]);
else
svc = ip_vs_service_find(ipvs, af, skb->mark, iph->protocol,
&iph->saddr, ports[0]);
if (svc) {
int ignored;
if (ip_vs_todrop(ipvs)) {
*verdict = NF_DROP;
return 0;
}
*cpp = ip_vs_schedule(svc, skb, pd, &ignored, iph);
if (!*cpp && ignored <= 0) {
if (!ignored)
*verdict = ip_vs_leave(svc, skb, pd, iph);
else
*verdict = NF_DROP;
return 0;
}
}
return 1;
}
static inline void
tcp_fast_csum_update(int af, struct tcphdr *tcph,
const union nf_inet_addr *oldip,
const union nf_inet_addr *newip,
__be16 oldport, __be16 newport)
{
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
tcph->check =
csum_fold(ip_vs_check_diff16(oldip->ip6, newip->ip6,
ip_vs_check_diff2(oldport, newport,
~csum_unfold(tcph->check))));
else
#endif
tcph->check =
csum_fold(ip_vs_check_diff4(oldip->ip, newip->ip,
ip_vs_check_diff2(oldport, newport,
~csum_unfold(tcph->check))));
}
static inline void
tcp_partial_csum_update(int af, struct tcphdr *tcph,
const union nf_inet_addr *oldip,
const union nf_inet_addr *newip,
__be16 oldlen, __be16 newlen)
{
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
tcph->check =
~csum_fold(ip_vs_check_diff16(oldip->ip6, newip->ip6,
ip_vs_check_diff2(oldlen, newlen,
csum_unfold(tcph->check))));
else
#endif
tcph->check =
~csum_fold(ip_vs_check_diff4(oldip->ip, newip->ip,
ip_vs_check_diff2(oldlen, newlen,
csum_unfold(tcph->check))));
}
static int
tcp_snat_handler(struct sk_buff *skb, struct ip_vs_protocol *pp,
struct ip_vs_conn *cp, struct ip_vs_iphdr *iph)
{
struct tcphdr *tcph;
unsigned int tcphoff = iph->len;
int oldlen;
int payload_csum = 0;
#ifdef CONFIG_IP_VS_IPV6
if (cp->af == AF_INET6 && iph->fragoffs)
return 1;
#endif
oldlen = skb->len - tcphoff;
if (!skb_make_writable(skb, tcphoff+sizeof(*tcph)))
return 0;
if (unlikely(cp->app != NULL)) {
int ret;
if (pp->csum_check && !pp->csum_check(cp->af, skb, pp))
return 0;
if (!(ret = ip_vs_app_pkt_out(cp, skb)))
return 0;
if (ret == 1)
oldlen = skb->len - tcphoff;
else
payload_csum = 1;
}
tcph = (void *)skb_network_header(skb) + tcphoff;
tcph->source = cp->vport;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
tcp_partial_csum_update(cp->af, tcph, &cp->daddr, &cp->vaddr,
htons(oldlen),
htons(skb->len - tcphoff));
} else if (!payload_csum) {
tcp_fast_csum_update(cp->af, tcph, &cp->daddr, &cp->vaddr,
cp->dport, cp->vport);
if (skb->ip_summed == CHECKSUM_COMPLETE)
skb->ip_summed = (cp->app && pp->csum_check) ?
CHECKSUM_UNNECESSARY : CHECKSUM_NONE;
} else {
tcph->check = 0;
skb->csum = skb_checksum(skb, tcphoff, skb->len - tcphoff, 0);
#ifdef CONFIG_IP_VS_IPV6
if (cp->af == AF_INET6)
tcph->check = csum_ipv6_magic(&cp->vaddr.in6,
&cp->caddr.in6,
skb->len - tcphoff,
cp->protocol, skb->csum);
else
#endif
tcph->check = csum_tcpudp_magic(cp->vaddr.ip,
cp->caddr.ip,
skb->len - tcphoff,
cp->protocol,
skb->csum);
skb->ip_summed = CHECKSUM_UNNECESSARY;
IP_VS_DBG(11, "O-pkt: %s O-csum=%d (+%zd)\n",
pp->name, tcph->check,
(char*)&(tcph->check) - (char*)tcph);
}
return 1;
}
static int
tcp_dnat_handler(struct sk_buff *skb, struct ip_vs_protocol *pp,
struct ip_vs_conn *cp, struct ip_vs_iphdr *iph)
{
struct tcphdr *tcph;
unsigned int tcphoff = iph->len;
int oldlen;
int payload_csum = 0;
#ifdef CONFIG_IP_VS_IPV6
if (cp->af == AF_INET6 && iph->fragoffs)
return 1;
#endif
oldlen = skb->len - tcphoff;
if (!skb_make_writable(skb, tcphoff+sizeof(*tcph)))
return 0;
if (unlikely(cp->app != NULL)) {
int ret;
if (pp->csum_check && !pp->csum_check(cp->af, skb, pp))
return 0;
if (!(ret = ip_vs_app_pkt_in(cp, skb)))
return 0;
if (ret == 1)
oldlen = skb->len - tcphoff;
else
payload_csum = 1;
}
tcph = (void *)skb_network_header(skb) + tcphoff;
tcph->dest = cp->dport;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
tcp_partial_csum_update(cp->af, tcph, &cp->vaddr, &cp->daddr,
htons(oldlen),
htons(skb->len - tcphoff));
} else if (!payload_csum) {
tcp_fast_csum_update(cp->af, tcph, &cp->vaddr, &cp->daddr,
cp->vport, cp->dport);
if (skb->ip_summed == CHECKSUM_COMPLETE)
skb->ip_summed = (cp->app && pp->csum_check) ?
CHECKSUM_UNNECESSARY : CHECKSUM_NONE;
} else {
tcph->check = 0;
skb->csum = skb_checksum(skb, tcphoff, skb->len - tcphoff, 0);
#ifdef CONFIG_IP_VS_IPV6
if (cp->af == AF_INET6)
tcph->check = csum_ipv6_magic(&cp->caddr.in6,
&cp->daddr.in6,
skb->len - tcphoff,
cp->protocol, skb->csum);
else
#endif
tcph->check = csum_tcpudp_magic(cp->caddr.ip,
cp->daddr.ip,
skb->len - tcphoff,
cp->protocol,
skb->csum);
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
return 1;
}
static int
tcp_csum_check(int af, struct sk_buff *skb, struct ip_vs_protocol *pp)
{
unsigned int tcphoff;
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
tcphoff = sizeof(struct ipv6hdr);
else
#endif
tcphoff = ip_hdrlen(skb);
switch (skb->ip_summed) {
case CHECKSUM_NONE:
skb->csum = skb_checksum(skb, tcphoff, skb->len - tcphoff, 0);
case CHECKSUM_COMPLETE:
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6) {
if (csum_ipv6_magic(&ipv6_hdr(skb)->saddr,
&ipv6_hdr(skb)->daddr,
skb->len - tcphoff,
ipv6_hdr(skb)->nexthdr,
skb->csum)) {
IP_VS_DBG_RL_PKT(0, af, pp, skb, 0,
"Failed checksum for");
return 0;
}
} else
#endif
if (csum_tcpudp_magic(ip_hdr(skb)->saddr,
ip_hdr(skb)->daddr,
skb->len - tcphoff,
ip_hdr(skb)->protocol,
skb->csum)) {
IP_VS_DBG_RL_PKT(0, af, pp, skb, 0,
"Failed checksum for");
return 0;
}
break;
default:
break;
}
return 1;
}
static const char * tcp_state_name(int state)
{
if (state >= IP_VS_TCP_S_LAST)
return "ERR!";
return tcp_state_name_table[state] ? tcp_state_name_table[state] : "?";
}
static bool tcp_state_active(int state)
{
if (state >= IP_VS_TCP_S_LAST)
return false;
return tcp_state_active_table[state];
}
static void tcp_timeout_change(struct ip_vs_proto_data *pd, int flags)
{
int on = (flags & 1);
pd->tcp_state_table = (on ? tcp_states_dos : tcp_states);
}
static inline int tcp_state_idx(struct tcphdr *th)
{
if (th->rst)
return 3;
if (th->syn)
return 0;
if (th->fin)
return 1;
if (th->ack)
return 2;
return -1;
}
static inline void
set_tcp_state(struct ip_vs_proto_data *pd, struct ip_vs_conn *cp,
int direction, struct tcphdr *th)
{
int state_idx;
int new_state = IP_VS_TCP_S_CLOSE;
int state_off = tcp_state_off[direction];
if (cp->flags & IP_VS_CONN_F_NOOUTPUT) {
if (state_off == TCP_DIR_OUTPUT)
cp->flags &= ~IP_VS_CONN_F_NOOUTPUT;
else
state_off = TCP_DIR_INPUT_ONLY;
}
if ((state_idx = tcp_state_idx(th)) < 0) {
IP_VS_DBG(8, "tcp_state_idx=%d!!!\n", state_idx);
goto tcp_state_out;
}
new_state =
pd->tcp_state_table[state_off+state_idx].next_state[cp->state];
tcp_state_out:
if (new_state != cp->state) {
struct ip_vs_dest *dest = cp->dest;
IP_VS_DBG_BUF(8, "%s %s [%c%c%c%c] %s:%d->"
"%s:%d state: %s->%s conn->refcnt:%d\n",
pd->pp->name,
((state_off == TCP_DIR_OUTPUT) ?
"output " : "input "),
th->syn ? 'S' : '.',
th->fin ? 'F' : '.',
th->ack ? 'A' : '.',
th->rst ? 'R' : '.',
IP_VS_DBG_ADDR(cp->daf, &cp->daddr),
ntohs(cp->dport),
IP_VS_DBG_ADDR(cp->af, &cp->caddr),
ntohs(cp->cport),
tcp_state_name(cp->state),
tcp_state_name(new_state),
refcount_read(&cp->refcnt));
if (dest) {
if (!(cp->flags & IP_VS_CONN_F_INACTIVE) &&
!tcp_state_active(new_state)) {
atomic_dec(&dest->activeconns);
atomic_inc(&dest->inactconns);
cp->flags |= IP_VS_CONN_F_INACTIVE;
} else if ((cp->flags & IP_VS_CONN_F_INACTIVE) &&
tcp_state_active(new_state)) {
atomic_inc(&dest->activeconns);
atomic_dec(&dest->inactconns);
cp->flags &= ~IP_VS_CONN_F_INACTIVE;
}
}
}
if (likely(pd))
cp->timeout = pd->timeout_table[cp->state = new_state];
else
cp->timeout = tcp_timeouts[cp->state = new_state];
}
static void
tcp_state_transition(struct ip_vs_conn *cp, int direction,
const struct sk_buff *skb,
struct ip_vs_proto_data *pd)
{
struct tcphdr _tcph, *th;
#ifdef CONFIG_IP_VS_IPV6
int ihl = cp->af == AF_INET ? ip_hdrlen(skb) : sizeof(struct ipv6hdr);
#else
int ihl = ip_hdrlen(skb);
#endif
th = skb_header_pointer(skb, ihl, sizeof(_tcph), &_tcph);
if (th == NULL)
return;
spin_lock_bh(&cp->lock);
set_tcp_state(pd, cp, direction, th);
spin_unlock_bh(&cp->lock);
}
static inline __u16 tcp_app_hashkey(__be16 port)
{
return (((__force u16)port >> TCP_APP_TAB_BITS) ^ (__force u16)port)
& TCP_APP_TAB_MASK;
}
static int tcp_register_app(struct netns_ipvs *ipvs, struct ip_vs_app *inc)
{
struct ip_vs_app *i;
__u16 hash;
__be16 port = inc->port;
int ret = 0;
struct ip_vs_proto_data *pd = ip_vs_proto_data_get(ipvs, IPPROTO_TCP);
hash = tcp_app_hashkey(port);
list_for_each_entry(i, &ipvs->tcp_apps[hash], p_list) {
if (i->port == port) {
ret = -EEXIST;
goto out;
}
}
list_add_rcu(&inc->p_list, &ipvs->tcp_apps[hash]);
atomic_inc(&pd->appcnt);
out:
return ret;
}
static void
tcp_unregister_app(struct netns_ipvs *ipvs, struct ip_vs_app *inc)
{
struct ip_vs_proto_data *pd = ip_vs_proto_data_get(ipvs, IPPROTO_TCP);
atomic_dec(&pd->appcnt);
list_del_rcu(&inc->p_list);
}
static int
tcp_app_conn_bind(struct ip_vs_conn *cp)
{
struct netns_ipvs *ipvs = cp->ipvs;
int hash;
struct ip_vs_app *inc;
int result = 0;
if (IP_VS_FWD_METHOD(cp) != IP_VS_CONN_F_MASQ)
return 0;
hash = tcp_app_hashkey(cp->vport);
list_for_each_entry_rcu(inc, &ipvs->tcp_apps[hash], p_list) {
if (inc->port == cp->vport) {
if (unlikely(!ip_vs_app_inc_get(inc)))
break;
IP_VS_DBG_BUF(9, "%s(): Binding conn %s:%u->"
"%s:%u to app %s on port %u\n",
__func__,
IP_VS_DBG_ADDR(cp->af, &cp->caddr),
ntohs(cp->cport),
IP_VS_DBG_ADDR(cp->af, &cp->vaddr),
ntohs(cp->vport),
inc->name, ntohs(inc->port));
cp->app = inc;
if (inc->init_conn)
result = inc->init_conn(inc, cp);
break;
}
}
return result;
}
void ip_vs_tcp_conn_listen(struct ip_vs_conn *cp)
{
struct ip_vs_proto_data *pd = ip_vs_proto_data_get(cp->ipvs, IPPROTO_TCP);
spin_lock_bh(&cp->lock);
cp->state = IP_VS_TCP_S_LISTEN;
cp->timeout = (pd ? pd->timeout_table[IP_VS_TCP_S_LISTEN]
: tcp_timeouts[IP_VS_TCP_S_LISTEN]);
spin_unlock_bh(&cp->lock);
}
static int __ip_vs_tcp_init(struct netns_ipvs *ipvs, struct ip_vs_proto_data *pd)
{
ip_vs_init_hash_table(ipvs->tcp_apps, TCP_APP_TAB_SIZE);
pd->timeout_table = ip_vs_create_timeout_table((int *)tcp_timeouts,
sizeof(tcp_timeouts));
if (!pd->timeout_table)
return -ENOMEM;
pd->tcp_state_table = tcp_states;
return 0;
}
static void __ip_vs_tcp_exit(struct netns_ipvs *ipvs, struct ip_vs_proto_data *pd)
{
kfree(pd->timeout_table);
}
