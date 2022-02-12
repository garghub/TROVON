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
ip_vs_dh_get(int af, struct ip_vs_dh_state *s, const union nf_inet_addr *addr)
{
return rcu_dereference(s->buckets[ip_vs_dh_hashkey(af, addr)].dest);
}
static int
ip_vs_dh_reassign(struct ip_vs_dh_state *s, struct ip_vs_service *svc)
{
int i;
struct ip_vs_dh_bucket *b;
struct list_head *p;
struct ip_vs_dest *dest;
bool empty;
b = &s->buckets[0];
p = &svc->destinations;
empty = list_empty(p);
for (i=0; i<IP_VS_DH_TAB_SIZE; i++) {
dest = rcu_dereference_protected(b->dest, 1);
if (dest)
ip_vs_dest_put(dest);
if (empty)
RCU_INIT_POINTER(b->dest, NULL);
else {
if (p == &svc->destinations)
p = p->next;
dest = list_entry(p, struct ip_vs_dest, n_list);
ip_vs_dest_hold(dest);
RCU_INIT_POINTER(b->dest, dest);
p = p->next;
}
b++;
}
return 0;
}
static void ip_vs_dh_flush(struct ip_vs_dh_state *s)
{
int i;
struct ip_vs_dh_bucket *b;
struct ip_vs_dest *dest;
b = &s->buckets[0];
for (i=0; i<IP_VS_DH_TAB_SIZE; i++) {
dest = rcu_dereference_protected(b->dest, 1);
if (dest) {
ip_vs_dest_put(dest);
RCU_INIT_POINTER(b->dest, NULL);
}
b++;
}
}
static int ip_vs_dh_init_svc(struct ip_vs_service *svc)
{
struct ip_vs_dh_state *s;
s = kzalloc(sizeof(struct ip_vs_dh_state), GFP_KERNEL);
if (s == NULL)
return -ENOMEM;
svc->sched_data = s;
IP_VS_DBG(6, "DH hash table (memory=%Zdbytes) allocated for "
"current service\n",
sizeof(struct ip_vs_dh_bucket)*IP_VS_DH_TAB_SIZE);
ip_vs_dh_reassign(s, svc);
return 0;
}
static void ip_vs_dh_done_svc(struct ip_vs_service *svc)
{
struct ip_vs_dh_state *s = svc->sched_data;
ip_vs_dh_flush(s);
kfree_rcu(s, rcu_head);
IP_VS_DBG(6, "DH hash table (memory=%Zdbytes) released\n",
sizeof(struct ip_vs_dh_bucket)*IP_VS_DH_TAB_SIZE);
}
static int ip_vs_dh_dest_changed(struct ip_vs_service *svc,
struct ip_vs_dest *dest)
{
struct ip_vs_dh_state *s = svc->sched_data;
ip_vs_dh_reassign(s, svc);
return 0;
}
static inline int is_overloaded(struct ip_vs_dest *dest)
{
return dest->flags & IP_VS_DEST_F_OVERLOAD;
}
static struct ip_vs_dest *
ip_vs_dh_schedule(struct ip_vs_service *svc, const struct sk_buff *skb,
struct ip_vs_iphdr *iph)
{
struct ip_vs_dest *dest;
struct ip_vs_dh_state *s;
IP_VS_DBG(6, "%s(): Scheduling...\n", __func__);
s = (struct ip_vs_dh_state *) svc->sched_data;
dest = ip_vs_dh_get(svc->af, s, &iph->daddr);
if (!dest
|| !(dest->flags & IP_VS_DEST_F_AVAILABLE)
|| atomic_read(&dest->weight) <= 0
|| is_overloaded(dest)) {
ip_vs_scheduler_err(svc, "no destination available");
return NULL;
}
IP_VS_DBG_BUF(6, "DH: destination IP address %s --> server %s:%d\n",
IP_VS_DBG_ADDR(svc->af, &iph->daddr),
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
synchronize_rcu();
}
