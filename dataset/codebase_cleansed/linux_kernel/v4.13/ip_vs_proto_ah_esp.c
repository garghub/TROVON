static void
ah_esp_conn_fill_param_proto(struct netns_ipvs *ipvs, int af,
const struct ip_vs_iphdr *iph,
struct ip_vs_conn_param *p)
{
if (likely(!ip_vs_iph_inverse(iph)))
ip_vs_conn_fill_param(ipvs, af, IPPROTO_UDP,
&iph->saddr, htons(PORT_ISAKMP),
&iph->daddr, htons(PORT_ISAKMP), p);
else
ip_vs_conn_fill_param(ipvs, af, IPPROTO_UDP,
&iph->daddr, htons(PORT_ISAKMP),
&iph->saddr, htons(PORT_ISAKMP), p);
}
static struct ip_vs_conn *
ah_esp_conn_in_get(struct netns_ipvs *ipvs, int af, const struct sk_buff *skb,
const struct ip_vs_iphdr *iph)
{
struct ip_vs_conn *cp;
struct ip_vs_conn_param p;
ah_esp_conn_fill_param_proto(ipvs, af, iph, &p);
cp = ip_vs_conn_in_get(&p);
if (!cp) {
IP_VS_DBG_BUF(12, "Unknown ISAKMP entry for outin packet "
"%s%s %s->%s\n",
ip_vs_iph_icmp(iph) ? "ICMP+" : "",
ip_vs_proto_get(iph->protocol)->name,
IP_VS_DBG_ADDR(af, &iph->saddr),
IP_VS_DBG_ADDR(af, &iph->daddr));
}
return cp;
}
static struct ip_vs_conn *
ah_esp_conn_out_get(struct netns_ipvs *ipvs, int af, const struct sk_buff *skb,
const struct ip_vs_iphdr *iph)
{
struct ip_vs_conn *cp;
struct ip_vs_conn_param p;
ah_esp_conn_fill_param_proto(ipvs, af, iph, &p);
cp = ip_vs_conn_out_get(&p);
if (!cp) {
IP_VS_DBG_BUF(12, "Unknown ISAKMP entry for inout packet "
"%s%s %s->%s\n",
ip_vs_iph_icmp(iph) ? "ICMP+" : "",
ip_vs_proto_get(iph->protocol)->name,
IP_VS_DBG_ADDR(af, &iph->saddr),
IP_VS_DBG_ADDR(af, &iph->daddr));
}
return cp;
}
static int
ah_esp_conn_schedule(struct netns_ipvs *ipvs, int af, struct sk_buff *skb,
struct ip_vs_proto_data *pd,
int *verdict, struct ip_vs_conn **cpp,
struct ip_vs_iphdr *iph)
{
*verdict = NF_ACCEPT;
return 0;
}
