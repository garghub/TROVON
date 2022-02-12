static struct ip_vs_dest *
ip_vs_lc_schedule(struct ip_vs_service *svc, const struct sk_buff *skb)
{
struct ip_vs_dest *dest, *least = NULL;
unsigned int loh = 0, doh;
IP_VS_DBG(6, "%s(): Scheduling...\n", __func__);
list_for_each_entry(dest, &svc->destinations, n_list) {
if ((dest->flags & IP_VS_DEST_F_OVERLOAD) ||
atomic_read(&dest->weight) == 0)
continue;
doh = ip_vs_dest_conn_overhead(dest);
if (!least || doh < loh) {
least = dest;
loh = doh;
}
}
if (!least)
ip_vs_scheduler_err(svc, "no destination available");
else
IP_VS_DBG_BUF(6, "LC: server %s:%u activeconns %d "
"inactconns %d\n",
IP_VS_DBG_ADDR(svc->af, &least->addr),
ntohs(least->port),
atomic_read(&least->activeconns),
atomic_read(&least->inactconns));
return least;
}
static int __init ip_vs_lc_init(void)
{
return register_ip_vs_scheduler(&ip_vs_lc_scheduler) ;
}
static void __exit ip_vs_lc_cleanup(void)
{
unregister_ip_vs_scheduler(&ip_vs_lc_scheduler);
}
