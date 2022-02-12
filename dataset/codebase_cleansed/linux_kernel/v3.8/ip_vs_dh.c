static inline unsigned int ip_vs_dh_hashkey(int af, const union nf_inet_addr *addr)
{
__be32 addr_fold = addr->ip;
#ifdef CONFIG_IP_VS_IPV6
if (af == AF_INET6)
addr_fold = addr->ip6[0]^addr->ip6[1]^
addr->ip6[2]^addr->ip6[3];
#endif
return (ntohl(addr_fold)*2654435761UL) & IP_VS_DH_TAB_MASK;
}
static inline struct ip_vs_dest *
ip_vs_dh_get(int af, struct ip_vs_dh_bucket *tbl,
const union nf_inet_addr *addr)
{
return (tbl[ip_vs_dh_hashkey(af, addr)]).dest;
}
static int
ip_vs_dh_assign(struct ip_vs_dh_bucket *tbl, struct ip_vs_service *svc)
{
int i;
struct ip_vs_dh_bucket *b;
struct list_head *p;
struct ip_vs_dest *dest;
b = tbl;
p = &svc->destinations;
for (i=0; i<IP_VS_DH_TAB_SIZE; i++) {
if (list_empty(p)) {
b->dest = NULL;
} else {
if (p == &svc->destinations)
p = p->next;
dest = list_entry(p, struct ip_vs_dest, n_list);
atomic_inc(&dest->refcnt);
b->dest = dest;
p = p->next;
}
b++;
}
return 0;
}
static void ip_vs_dh_flush(struct ip_vs_dh_bucket *tbl)
{
int i;
struct ip_vs_dh_bucket *b;
b = tbl;
for (i=0; i<IP_VS_DH_TAB_SIZE; i++) {
if (b->dest) {
atomic_dec(&b->dest->refcnt);
b->dest = NULL;
}
b++;
}
}
static int ip_vs_dh_init_svc(struct ip_vs_service *svc)
{
struct ip_vs_dh_bucket *tbl;
tbl = kmalloc(sizeof(struct ip_vs_dh_bucket)*IP_VS_DH_TAB_SIZE,
GFP_KERNEL);
if (tbl == NULL)
return -ENOMEM;
svc->sched_data = tbl;
IP_VS_DBG(6, "DH hash table (memory=%Zdbytes) allocated for "
"current service\n",
sizeof(struct ip_vs_dh_bucket)*IP_VS_DH_TAB_SIZE);
ip_vs_dh_assign(tbl, svc);
return 0;
}
static int ip_vs_dh_done_svc(struct ip_vs_service *svc)
{
struct ip_vs_dh_bucket *tbl = svc->sched_data;
ip_vs_dh_flush(tbl);
kfree(svc->sched_data);
IP_VS_DBG(6, "DH hash table (memory=%Zdbytes) released\n",
sizeof(struct ip_vs_dh_bucket)*IP_VS_DH_TAB_SIZE);
return 0;
}
static int ip_vs_dh_update_svc(struct ip_vs_service *svc)
{
struct ip_vs_dh_bucket *tbl = svc->sched_data;
ip_vs_dh_flush(tbl);
ip_vs_dh_assign(tbl, svc);
return 0;
}
static inline int is_overloaded(struct ip_vs_dest *dest)
{
return dest->flags & IP_VS_DEST_F_OVERLOAD;
}
static struct ip_vs_dest *
ip_vs_dh_schedule(struct ip_vs_service *svc, const struct sk_buff *skb)
{
struct ip_vs_dest *dest;
struct ip_vs_dh_bucket *tbl;
struct ip_vs_iphdr iph;
ip_vs_fill_iph_addr_only(svc->af, skb, &iph);
IP_VS_DBG(6, "%s(): Scheduling...\n", __func__);
tbl = (struct ip_vs_dh_bucket *)svc->sched_data;
dest = ip_vs_dh_get(svc->af, tbl, &iph.daddr);
if (!dest
|| !(dest->flags & IP_VS_DEST_F_AVAILABLE)
|| atomic_read(&dest->weight) <= 0
|| is_overloaded(dest)) {
return NULL;
}
IP_VS_DBG_BUF(6, "DH: destination IP address %s --> server %s:%d\n",
IP_VS_DBG_ADDR(svc->af, &iph.daddr),
IP_VS_DBG_ADDR(svc->af, &dest->addr),
ntohs(dest->port));
return dest;
}
static int __init ip_vs_dh_init(void)
{
return register_ip_vs_scheduler(&ip_vs_dh_scheduler);
}
static void __exit ip_vs_dh_cleanup(void)
{
unregister_ip_vs_scheduler(&ip_vs_dh_scheduler);
}
