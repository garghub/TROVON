static void
ah_esp_conn_fill_param_proto(struct net *net, int af,
const struct ip_vs_iphdr *iph, int inverse,
struct ip_vs_conn_param *p)
{
if (likely(!inverse))
ip_vs_conn_fill_param(net, af, IPPROTO_UDP,
&iph->saddr, htons(PORT_ISAKMP),
&iph->daddr, htons(PORT_ISAKMP), p);
else
ip_vs_conn_fill_param(net, af, IPPROTO_UDP,
&iph->daddr, htons(PORT_ISAKMP),
&iph->saddr, htons(PORT_ISAKMP), p);
}
static struct ip_vs_conn *
ah_esp_conn_in_get(int af, const struct sk_buff *skb,
const struct ip_vs_iphdr *iph,
int inverse)
{
struct ip_vs_conn *cp;
struct ip_vs_conn_param p;
struct net *net = skb_net(skb);
ah_esp_conn_fill_param_proto(net, af, iph, inverse, &p);
cp = ip_vs_conn_in_get(&p);
if (!cp) {
IP_VS_DBG_BUF(12, "Unknown ISAKMP entry for outin packet "
"%s%s %s->%s\n",
inverse ? "ICMP+" : "",
ip_vs_proto_get(iph->protocol)->name,
IP_VS_DBG_ADDR(af, &iph->saddr),
IP_VS_DBG_ADDR(af, &iph->daddr));
}
return cp;
}
static struct ip_vs_conn *
ah_esp_conn_out_get(int af, const struct sk_buff *skb,
const struct ip_vs_iphdr *iph, int inverse)
{
struct ip_vs_conn *cp;
struct ip_vs_conn_param p;
struct net *net = skb_net(skb);
ah_esp_conn_fill_param_proto(net, af, iph, inverse, &p);
cp = ip_vs_conn_out_get(&p);
if (!cp) {
IP_VS_DBG_BUF(12, "Unknown ISAKMP entry for inout packet "
"%s%s %s->%s\n",
inverse ? "ICMP+" : "",
ip_vs_proto_get(iph->protocol)->name,
IP_VS_DBG_ADDR(af, &iph->saddr),
IP_VS_DBG_ADDR(af, &iph->daddr));
}
return cp;
}
static int
ah_esp_conn_schedule(int af, struct sk_buff *skb, struct ip_vs_proto_data *pd,
int *verdict, struct ip_vs_conn **cpp,
struct ip_vs_iphdr *iph)
{
*verdict = NF_ACCEPT;
return 0;
}
