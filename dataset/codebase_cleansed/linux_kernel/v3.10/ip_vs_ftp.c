static int
ip_vs_ftp_init_conn(struct ip_vs_app *app, struct ip_vs_conn *cp)
{
cp->flags |= IP_VS_CONN_F_NFCT;
return 0;
}
static int
ip_vs_ftp_done_conn(struct ip_vs_app *app, struct ip_vs_conn *cp)
{
return 0;
}
static int ip_vs_ftp_get_addrport(char *data, char *data_limit,
const char *pattern, size_t plen,
char skip, char term,
__be32 *addr, __be16 *port,
char **start, char **end)
{
char *s, c;
unsigned char p[6];
int i = 0;
if (data_limit - data < plen) {
if (strnicmp(data, pattern, data_limit - data) == 0)
return -1;
else
return 0;
}
if (strnicmp(data, pattern, plen) != 0) {
return 0;
}
s = data + plen;
if (skip) {
int found = 0;
for (;; s++) {
if (s == data_limit)
return -1;
if (!found) {
if (*s == skip)
found = 1;
} else if (*s != skip) {
break;
}
}
}
for (data = s; ; data++) {
if (data == data_limit)
return -1;
if (*data == term)
break;
}
*end = data;
memset(p, 0, sizeof(p));
for (data = s; ; data++) {
c = *data;
if (c == term)
break;
if (c >= '0' && c <= '9') {
p[i] = p[i]*10 + c - '0';
} else if (c == ',' && i < 5) {
i++;
} else {
return -1;
}
}
if (i != 5)
return -1;
*start = s;
*addr = get_unaligned((__be32 *) p);
*port = get_unaligned((__be16 *) (p + 4));
return 1;
}
static int ip_vs_ftp_out(struct ip_vs_app *app, struct ip_vs_conn *cp,
struct sk_buff *skb, int *diff)
{
struct iphdr *iph;
struct tcphdr *th;
char *data, *data_limit;
char *start, *end;
union nf_inet_addr from;
__be16 port;
struct ip_vs_conn *n_cp;
char buf[24];
unsigned int buf_len;
int ret = 0;
enum ip_conntrack_info ctinfo;
struct nf_conn *ct;
struct net *net;
#ifdef CONFIG_IP_VS_IPV6
if (cp->af == AF_INET6)
return 1;
#endif
*diff = 0;
if (cp->state != IP_VS_TCP_S_ESTABLISHED)
return 1;
if (!skb_make_writable(skb, skb->len))
return 0;
if (cp->app_data == &ip_vs_ftp_pasv) {
iph = ip_hdr(skb);
th = (struct tcphdr *)&(((char *)iph)[iph->ihl*4]);
data = (char *)th + (th->doff << 2);
data_limit = skb_tail_pointer(skb);
if (ip_vs_ftp_get_addrport(data, data_limit,
SERVER_STRING,
sizeof(SERVER_STRING)-1,
'(', ')',
&from.ip, &port,
&start, &end) != 1)
return 1;
IP_VS_DBG(7, "PASV response (%pI4:%d) -> %pI4:%d detected\n",
&from.ip, ntohs(port), &cp->caddr.ip, 0);
{
struct ip_vs_conn_param p;
ip_vs_conn_fill_param(ip_vs_conn_net(cp), AF_INET,
iph->protocol, &from, port,
&cp->caddr, 0, &p);
n_cp = ip_vs_conn_out_get(&p);
}
if (!n_cp) {
struct ip_vs_conn_param p;
ip_vs_conn_fill_param(ip_vs_conn_net(cp),
AF_INET, IPPROTO_TCP, &cp->caddr,
0, &cp->vaddr, port, &p);
n_cp = ip_vs_conn_new(&p, &from, port,
IP_VS_CONN_F_NO_CPORT |
IP_VS_CONN_F_NFCT,
cp->dest, skb->mark);
if (!n_cp)
return 0;
ip_vs_control_add(n_cp, cp);
}
from.ip = n_cp->vaddr.ip;
port = n_cp->vport;
snprintf(buf, sizeof(buf), "%u,%u,%u,%u,%u,%u",
((unsigned char *)&from.ip)[0],
((unsigned char *)&from.ip)[1],
((unsigned char *)&from.ip)[2],
((unsigned char *)&from.ip)[3],
ntohs(port) >> 8,
ntohs(port) & 0xFF);
buf_len = strlen(buf);
ct = nf_ct_get(skb, &ctinfo);
if (ct && !nf_ct_is_untracked(ct) && nfct_nat(ct)) {
rcu_read_lock();
ret = nf_nat_mangle_tcp_packet(skb, ct, ctinfo,
iph->ihl * 4,
start-data, end-start,
buf, buf_len);
rcu_read_unlock();
if (ret) {
ip_vs_nfct_expect_related(skb, ct, n_cp,
IPPROTO_TCP, 0, 0);
if (skb->ip_summed == CHECKSUM_COMPLETE)
skb->ip_summed = CHECKSUM_UNNECESSARY;
ret = 1;
}
}
net = skb_net(skb);
cp->app_data = NULL;
ip_vs_tcp_conn_listen(net, n_cp);
ip_vs_conn_put(n_cp);
return ret;
}
return 1;
}
static int ip_vs_ftp_in(struct ip_vs_app *app, struct ip_vs_conn *cp,
struct sk_buff *skb, int *diff)
{
struct iphdr *iph;
struct tcphdr *th;
char *data, *data_start, *data_limit;
char *start, *end;
union nf_inet_addr to;
__be16 port;
struct ip_vs_conn *n_cp;
struct net *net;
#ifdef CONFIG_IP_VS_IPV6
if (cp->af == AF_INET6)
return 1;
#endif
*diff = 0;
if (cp->state != IP_VS_TCP_S_ESTABLISHED)
return 1;
if (!skb_make_writable(skb, skb->len))
return 0;
iph = ip_hdr(skb);
th = (struct tcphdr *)&(((char *)iph)[iph->ihl*4]);
data = data_start = (char *)th + (th->doff << 2);
data_limit = skb_tail_pointer(skb);
while (data <= data_limit - 6) {
if (strnicmp(data, "PASV\r\n", 6) == 0) {
IP_VS_DBG(7, "got PASV at %td of %td\n",
data - data_start,
data_limit - data_start);
cp->app_data = &ip_vs_ftp_pasv;
return 1;
}
data++;
}
if (ip_vs_ftp_get_addrport(data_start, data_limit,
CLIENT_STRING, sizeof(CLIENT_STRING)-1,
' ', '\r', &to.ip, &port,
&start, &end) != 1)
return 1;
IP_VS_DBG(7, "PORT %pI4:%d detected\n", &to.ip, ntohs(port));
cp->app_data = NULL;
IP_VS_DBG(7, "protocol %s %pI4:%d %pI4:%d\n",
ip_vs_proto_name(iph->protocol),
&to.ip, ntohs(port), &cp->vaddr.ip, 0);
{
struct ip_vs_conn_param p;
ip_vs_conn_fill_param(ip_vs_conn_net(cp), AF_INET,
iph->protocol, &to, port, &cp->vaddr,
htons(ntohs(cp->vport)-1), &p);
n_cp = ip_vs_conn_in_get(&p);
if (!n_cp) {
n_cp = ip_vs_conn_new(&p, &cp->daddr,
htons(ntohs(cp->dport)-1),
IP_VS_CONN_F_NFCT, cp->dest,
skb->mark);
if (!n_cp)
return 0;
ip_vs_control_add(n_cp, cp);
}
}
net = skb_net(skb);
ip_vs_tcp_conn_listen(net, n_cp);
ip_vs_conn_put(n_cp);
return 1;
}
static int __net_init __ip_vs_ftp_init(struct net *net)
{
int i, ret;
struct ip_vs_app *app;
struct netns_ipvs *ipvs = net_ipvs(net);
if (!ipvs)
return -ENOENT;
app = register_ip_vs_app(net, &ip_vs_ftp);
if (IS_ERR(app))
return PTR_ERR(app);
for (i = 0; i < ports_count; i++) {
if (!ports[i])
continue;
ret = register_ip_vs_app_inc(net, app, app->protocol, ports[i]);
if (ret)
goto err_unreg;
pr_info("%s: loaded support on port[%d] = %d\n",
app->name, i, ports[i]);
}
return 0;
err_unreg:
unregister_ip_vs_app(net, &ip_vs_ftp);
return ret;
}
static void __ip_vs_ftp_exit(struct net *net)
{
unregister_ip_vs_app(net, &ip_vs_ftp);
}
static int __init ip_vs_ftp_init(void)
{
int rv;
rv = register_pernet_subsys(&ip_vs_ftp_ops);
return rv;
}
static void __exit ip_vs_ftp_exit(void)
{
unregister_pernet_subsys(&ip_vs_ftp_ops);
}
