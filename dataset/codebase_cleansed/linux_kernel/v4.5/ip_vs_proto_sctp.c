static int
sctp_conn_schedule(struct netns_ipvs *ipvs, int af, struct sk_buff *skb,
struct ip_vs_proto_data *pd,
int *verdict, struct ip_vs_conn **cpp,
struct ip_vs_iphdr *iph)
{
struct ip_vs_service *svc;
sctp_chunkhdr_t _schunkh, *sch;
sctp_sctphdr_t *sh, _sctph;
__be16 _ports[2], *ports = NULL;
if (likely(!ip_vs_iph_icmp(iph))) {
sh = skb_header_pointer(skb, iph->len, sizeof(_sctph), &_sctph);
if (sh) {
sch = skb_header_pointer(
skb, iph->len + sizeof(sctp_sctphdr_t),
sizeof(_schunkh), &_schunkh);
if (sch && (sch->type == SCTP_CID_INIT ||
sysctl_sloppy_sctp(ipvs)))
ports = &sh->source;
}
} else {
ports = skb_header_pointer(
skb, iph->len, sizeof(_ports), &_ports);
}
if (!ports) {
*verdict = NF_DROP;
return 0;
}
rcu_read_lock();
if (likely(!ip_vs_iph_inverse(iph)))
svc = ip_vs_service_find(ipvs, af, skb->mark, iph->protocol,
&iph->daddr, ports[1]);
else
svc = ip_vs_service_find(ipvs, af, skb->mark, iph->protocol,
&iph->saddr, ports[0]);
if (svc) {
int ignored;
if (ip_vs_todrop(ipvs)) {
rcu_read_unlock();
*verdict = NF_DROP;
return 0;
}
*cpp = ip_vs_schedule(svc, skb, pd, &ignored, iph);
if (!*cpp && ignored <= 0) {
if (!ignored)
*verdict = ip_vs_leave(svc, skb, pd, iph);
else
*verdict = NF_DROP;
rcu_read_unlock();
return 0;
}
}
rcu_read_unlock();
return 1;
}
static void sctp_nat_csum(struct sk_buff *skb, sctp_sctphdr_t *sctph,
unsigned int sctphoff)
{
sctph->checksum = sctp_compute_cksum(skb, sctphoff);
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
static int
sctp_snat_handler(struct sk_buff *skb, struct ip_vs_protocol *pp,
struct ip_vs_conn *cp, struct ip_vs_iphdr *iph)
{
sctp_sctphdr_t *sctph;
unsigned int sctphoff = iph->len;
bool payload_csum = false;
#ifdef CONFIG_IP_VS_IPV6
if (cp->af == AF_INET6 && iph->fragoffs)
return 1;
#endif
if (!skb_make_writable(skb, sctphoff + sizeof(*sctph)))
return 0;
if (unlikely(cp->app != NULL)) {
int ret;
if (pp->csum_check && !pp->csum_check(cp->af, skb, pp))
return 0;
ret = ip_vs_app_pkt_out(cp, skb);
if (ret == 0)
return 0;
if (ret == 2)
payload_csum = true;
}
sctph = (void *) skb_network_header(skb) + sctphoff;
if (sctph->source != cp->vport || payload_csum ||
skb->ip_summed == CHECKSUM_PARTIAL) {
sctph->source = cp->vport;
sctp_nat_csum(skb, sctph, sctphoff);
} else {
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
return 1;
}
static int
sctp_dnat_handler(struct sk_buff *skb, struct ip_vs_protocol *pp,
struct ip_vs_conn *cp, struct ip_vs_iphdr *iph)
{
sctp_sctphdr_t *sctph;
unsigned int sctphoff = iph->len;
bool payload_csum = false;
#ifdef CONFIG_IP_VS_IPV6
if (cp->af == AF_INET6 && iph->fragoffs)
return 1;
#endif
if (!skb_make_writable(skb, sctphoff + sizeof(*sctph)))
return 0;
if (unlikely(cp->app != NULL)) {
int ret;
if (pp->csum_check && !pp->csum_check(cp->af, skb, pp))
return 0;
ret = ip_vs_app_pkt_in(cp, skb);
if (ret == 0)
return 0;
if (ret == 2)
payload_csum = true;
}
sctph = (void *) skb_network_header(skb) + sctphoff;
if (sctph->dest != cp->dport || payload_csum ||
(skb->ip_summed == CHECKSUM_PARTIAL &&
!(skb_dst(skb)->dev->features & NETIF_F_SCTP_CRC))) {
sctph->dest = cp->dport;
sctp_nat_csum(skb, sctph, sctphoff);
} else if (skb->ip_summed != CHECKSUM_PARTIAL) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
return 1;
}
static int
sctp_csum_check(int af, struct sk_buff *skb, struct ip_vs_protocol *pp)
{
unsigned int sctphoff;
struct sctphdr *sh, _sctph;
__le32 cmp, val;
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
sctphoff = sizeof(struct ipv6hdr);
else
#endif
sctphoff = ip_hdrlen(skb);
sh = skb_header_pointer(skb, sctphoff, sizeof(_sctph), &_sctph);
if (sh == NULL)
return 0;
cmp = sh->checksum;
val = sctp_compute_cksum(skb, sctphoff);
if (val != cmp) {
IP_VS_DBG_RL_PKT(0, af, pp, skb, 0,
"Failed checksum for");
return 0;
}
return 1;
}
static const char *sctp_state_name(int state)
{
if (state >= IP_VS_SCTP_S_LAST)
return "ERR!";
if (sctp_state_name_table[state])
return sctp_state_name_table[state];
return "?";
}
static inline void
set_sctp_state(struct ip_vs_proto_data *pd, struct ip_vs_conn *cp,
int direction, const struct sk_buff *skb)
{
sctp_chunkhdr_t _sctpch, *sch;
unsigned char chunk_type;
int event, next_state;
int ihl, cofs;
#ifdef CONFIG_IP_VS_IPV6
ihl = cp->af == AF_INET ? ip_hdrlen(skb) : sizeof(struct ipv6hdr);
#else
ihl = ip_hdrlen(skb);
#endif
cofs = ihl + sizeof(sctp_sctphdr_t);
sch = skb_header_pointer(skb, cofs, sizeof(_sctpch), &_sctpch);
if (sch == NULL)
return;
chunk_type = sch->type;
if ((sch->type == SCTP_CID_COOKIE_ECHO) ||
(sch->type == SCTP_CID_COOKIE_ACK)) {
int clen = ntohs(sch->length);
if (clen >= sizeof(sctp_chunkhdr_t)) {
sch = skb_header_pointer(skb, cofs + ALIGN(clen, 4),
sizeof(_sctpch), &_sctpch);
if (sch && sch->type == SCTP_CID_ABORT)
chunk_type = sch->type;
}
}
event = (chunk_type < sizeof(sctp_events)) ?
sctp_events[chunk_type] : IP_VS_SCTP_DATA;
if (cp->flags & IP_VS_CONN_F_NOOUTPUT) {
if (direction == IP_VS_DIR_OUTPUT)
cp->flags &= ~IP_VS_CONN_F_NOOUTPUT;
else
direction = IP_VS_DIR_INPUT_ONLY;
}
next_state = sctp_states[direction][event][cp->state];
if (next_state != cp->state) {
struct ip_vs_dest *dest = cp->dest;
IP_VS_DBG_BUF(8, "%s %s %s:%d->"
"%s:%d state: %s->%s conn->refcnt:%d\n",
pd->pp->name,
((direction == IP_VS_DIR_OUTPUT) ?
"output " : "input "),
IP_VS_DBG_ADDR(cp->daf, &cp->daddr),
ntohs(cp->dport),
IP_VS_DBG_ADDR(cp->af, &cp->caddr),
ntohs(cp->cport),
sctp_state_name(cp->state),
sctp_state_name(next_state),
atomic_read(&cp->refcnt));
if (dest) {
if (!(cp->flags & IP_VS_CONN_F_INACTIVE) &&
(next_state != IP_VS_SCTP_S_ESTABLISHED)) {
atomic_dec(&dest->activeconns);
atomic_inc(&dest->inactconns);
cp->flags |= IP_VS_CONN_F_INACTIVE;
} else if ((cp->flags & IP_VS_CONN_F_INACTIVE) &&
(next_state == IP_VS_SCTP_S_ESTABLISHED)) {
atomic_inc(&dest->activeconns);
atomic_dec(&dest->inactconns);
cp->flags &= ~IP_VS_CONN_F_INACTIVE;
}
}
}
if (likely(pd))
cp->timeout = pd->timeout_table[cp->state = next_state];
else
cp->timeout = sctp_timeouts[cp->state = next_state];
}
static void
sctp_state_transition(struct ip_vs_conn *cp, int direction,
const struct sk_buff *skb, struct ip_vs_proto_data *pd)
{
spin_lock_bh(&cp->lock);
set_sctp_state(pd, cp, direction, skb);
spin_unlock_bh(&cp->lock);
}
static inline __u16 sctp_app_hashkey(__be16 port)
{
return (((__force u16)port >> SCTP_APP_TAB_BITS) ^ (__force u16)port)
& SCTP_APP_TAB_MASK;
}
static int sctp_register_app(struct netns_ipvs *ipvs, struct ip_vs_app *inc)
{
struct ip_vs_app *i;
__u16 hash;
__be16 port = inc->port;
int ret = 0;
struct ip_vs_proto_data *pd = ip_vs_proto_data_get(ipvs, IPPROTO_SCTP);
hash = sctp_app_hashkey(port);
list_for_each_entry(i, &ipvs->sctp_apps[hash], p_list) {
if (i->port == port) {
ret = -EEXIST;
goto out;
}
}
list_add_rcu(&inc->p_list, &ipvs->sctp_apps[hash]);
atomic_inc(&pd->appcnt);
out:
return ret;
}
static void sctp_unregister_app(struct netns_ipvs *ipvs, struct ip_vs_app *inc)
{
struct ip_vs_proto_data *pd = ip_vs_proto_data_get(ipvs, IPPROTO_SCTP);
atomic_dec(&pd->appcnt);
list_del_rcu(&inc->p_list);
}
static int sctp_app_conn_bind(struct ip_vs_conn *cp)
{
struct netns_ipvs *ipvs = cp->ipvs;
int hash;
struct ip_vs_app *inc;
int result = 0;
if (IP_VS_FWD_METHOD(cp) != IP_VS_CONN_F_MASQ)
return 0;
hash = sctp_app_hashkey(cp->vport);
rcu_read_lock();
list_for_each_entry_rcu(inc, &ipvs->sctp_apps[hash], p_list) {
if (inc->port == cp->vport) {
if (unlikely(!ip_vs_app_inc_get(inc)))
break;
rcu_read_unlock();
IP_VS_DBG_BUF(9, "%s: Binding conn %s:%u->"
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
goto out;
}
}
rcu_read_unlock();
out:
return result;
}
static int __ip_vs_sctp_init(struct netns_ipvs *ipvs, struct ip_vs_proto_data *pd)
{
ip_vs_init_hash_table(ipvs->sctp_apps, SCTP_APP_TAB_SIZE);
pd->timeout_table = ip_vs_create_timeout_table((int *)sctp_timeouts,
sizeof(sctp_timeouts));
if (!pd->timeout_table)
return -ENOMEM;
return 0;
}
static void __ip_vs_sctp_exit(struct netns_ipvs *ipvs, struct ip_vs_proto_data *pd)
{
kfree(pd->timeout_table);
}
