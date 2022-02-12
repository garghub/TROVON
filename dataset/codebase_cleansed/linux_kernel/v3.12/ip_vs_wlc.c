static struct ip_vs_dest *
ip_vs_wlc_schedule(struct ip_vs_service *svc, const struct sk_buff *skb,
struct ip_vs_iphdr *iph)
{
struct ip_vs_dest *dest, *least;
int loh, doh;
IP_VS_DBG(6, "ip_vs_wlc_schedule(): Scheduling...\n");
list_for_each_entry_rcu(dest, &svc->destinations, n_list) {
if (!(dest->flags & IP_VS_DEST_F_OVERLOAD) &&
atomic_read(&dest->weight) > 0) {
least = dest;
loh = ip_vs_dest_conn_overhead(least);
goto nextstage;
}
}
ip_vs_scheduler_err(svc, "no destination available");
return NULL;
nextstage:
list_for_each_entry_continue_rcu(dest, &svc->destinations, n_list) {
if (dest->flags & IP_VS_DEST_F_OVERLOAD)
continue;
doh = ip_vs_dest_conn_overhead(dest);
if ((__s64)loh * atomic_read(&dest->weight) >
(__s64)doh * atomic_read(&least->weight)) {
least = dest;
loh = doh;
}
}
IP_VS_DBG_BUF(6, "WLC: server %s:%u "
"activeconns %d refcnt %d weight %d overhead %d\n",
IP_VS_DBG_ADDR(svc->af, &least->addr), ntohs(least->port),
atomic_read(&least->activeconns),
atomic_read(&least->refcnt),
atomic_read(&least->weight), loh);
return least;
}
static int __init ip_vs_wlc_init(void)
{
return register_ip_vs_scheduler(&ip_vs_wlc_scheduler);
}
static void __exit ip_vs_wlc_cleanup(void)
{
unregister_ip_vs_scheduler(&ip_vs_wlc_scheduler);
synchronize_rcu();
}
