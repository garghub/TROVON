static inline unsigned int
ip_vs_nq_dest_overhead(struct ip_vs_dest *dest)
{
return atomic_read(&dest->activeconns) + 1;
}
static struct ip_vs_dest *
ip_vs_nq_schedule(struct ip_vs_service *svc, const struct sk_buff *skb,
struct ip_vs_iphdr *iph)
{
struct ip_vs_dest *dest, *least = NULL;
unsigned int loh = 0, doh;
IP_VS_DBG(6, "%s(): Scheduling...\n", __func__);
list_for_each_entry_rcu(dest, &svc->destinations, n_list) {
if (dest->flags & IP_VS_DEST_F_OVERLOAD ||
!atomic_read(&dest->weight))
continue;
doh = ip_vs_nq_dest_overhead(dest);
if (atomic_read(&dest->activeconns) == 0) {
least = dest;
loh = doh;
goto out;
}
if (!least ||
(loh * atomic_read(&dest->weight) >
doh * atomic_read(&least->weight))) {
least = dest;
loh = doh;
}
}
if (!least) {
ip_vs_scheduler_err(svc, "no destination available");
return NULL;
}
out:
IP_VS_DBG_BUF(6, "NQ: server %s:%u "
"activeconns %d refcnt %d weight %d overhead %d\n",
IP_VS_DBG_ADDR(svc->af, &least->addr), ntohs(least->port),
atomic_read(&least->activeconns),
atomic_read(&least->refcnt),
atomic_read(&least->weight), loh);
return least;
}
static int __init ip_vs_nq_init(void)
{
return register_ip_vs_scheduler(&ip_vs_nq_scheduler);
}
static void __exit ip_vs_nq_cleanup(void)
{
unregister_ip_vs_scheduler(&ip_vs_nq_scheduler);
synchronize_rcu();
}
