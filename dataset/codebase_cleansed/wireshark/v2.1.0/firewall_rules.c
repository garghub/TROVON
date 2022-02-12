size_t firewall_product_count(void)
{
return NUM_PRODS;
}
const char *firewall_product_name(size_t product_idx)
{
if (product_idx >= NUM_PRODS) return "Unknown";
return products[product_idx].name;
}
const char *firewall_product_rule_hint(size_t product_idx)
{
if (product_idx >= NUM_PRODS) return "";
return products[product_idx].rule_hint;
}
const char *firewall_product_comment_prefix(size_t product_idx)
{
if (product_idx >= NUM_PRODS) return "";
return products[product_idx].comment_pfx;
}
syntax_func firewall_product_mac_func(size_t product_idx)
{
if (product_idx >= NUM_PRODS) return NULL;
return products[product_idx].mac_func;
}
syntax_func firewall_product_ipv4_func(size_t product_idx)
{
if (product_idx >= NUM_PRODS) return NULL;
return products[product_idx].ipv4_func;
}
syntax_func firewall_product_port_func(size_t product_idx)
{
if (product_idx >= NUM_PRODS) return NULL;
return products[product_idx].port_func;
}
syntax_func firewall_product_ipv4_port_func(size_t product_idx)
{
if (product_idx >= NUM_PRODS) return NULL;
return products[product_idx].ipv4_port_func;
}
gboolean firewall_product_does_inbound(size_t product_idx)
{
if (product_idx >= NUM_PRODS) return FALSE;
return products[product_idx].does_inbound;
}
static void sf_ipfw_mac(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "add %s MAC %s any %s",
IPFW_DENY, addr, IPFW_IN);
}
static void sf_netfilter_mac(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "iptables --append %s --in-interface eth0 --mac-source %s --jump %s",
NF_INPUT, addr, NF_DROP);
}
static void sf_ios_std_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound _U_, gboolean deny) {
g_string_append_printf(rtxt, "access-list NUMBER %s host %s", IOS_DENY, addr);
}
static void sf_ios_ext_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
if (inbound)
g_string_append_printf(rtxt, "access-list NUMBER %s ip host %s any", IOS_DENY, addr);
else
g_string_append_printf(rtxt, "access-list NUMBER %s ip any host %s", IOS_DENY, addr);
}
static void sf_ipfilter_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "%s %s on le0 from %s to any",
IPFILTER_DENY, IPFILTER_IN, addr);
}
static void sf_ipfw_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "add %s ip from %s to any %s",
IPFW_DENY, addr, IPFW_IN);
}
static void sf_netfilter_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "iptables --append %s --in-interface eth0 %s %s/32 --jump %s",
NF_INPUT, NF_ADDR_DIR, addr, NF_DROP);
}
static void sf_pf_ipv4(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "%s %s quick on $ext_if from %s to any",
PF_DENY, PF_IN, addr);
}
static void sf_ios_ext_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype, gboolean inbound _U_, gboolean deny) {
g_string_append_printf(rtxt, "access-list NUMBER %s %s any any eq %u",
IOS_DENY, RT_TCP_UDP, port);
}
static void sf_ipfilter_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype _U_, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "%s %s on le0 proto %s from any to any port = %u",
IPFILTER_DENY, IPFILTER_IN, RT_TCP_UDP, port);
}
static void sf_ipfw_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "add %s %s from any to any %u %s",
IPFW_DENY, RT_TCP_UDP, port, IPFW_IN);
}
static void sf_netfilter_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "iptables --append %s --in-interface eth0 --protocol %s %s %u --jump %s",
NF_INPUT, RT_TCP_UDP, NF_PORT_DIR, port, NF_DROP);
}
static void sf_pf_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "%s %s quick on $ext_if proto %s from any to any port %u",
PF_DENY, PF_IN, RT_TCP_UDP, port);
}
static void sf_netsh_port(GString *rtxt, gchar *addr _U_, guint32 port, port_type ptype, gboolean inbound _U_, gboolean deny) {
g_string_append_printf(rtxt, "add portopening %s %u Wireshark %s",
RT_TCP_UDP, port, NETSH_DENY);
}
static void sf_ios_ext_ipv4_port(GString *rtxt, gchar *addr, guint32 port _U_, port_type ptype _U_, gboolean inbound, gboolean deny) {
if (inbound)
g_string_append_printf(rtxt, "access-list NUMBER %s %s host %s any eq %u", IOS_DENY, RT_TCP_UDP, addr, port);
else
g_string_append_printf(rtxt, "access-list NUMBER %s %s any host %s eq %u", IOS_DENY, RT_TCP_UDP, addr, port);
}
static void sf_ipfilter_ipv4_port(GString *rtxt, gchar *addr, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
if (inbound)
g_string_append_printf(rtxt, "%s %s on le0 proto %s from %s to any port = %u",
IPFILTER_DENY, IPFILTER_IN, RT_TCP_UDP, addr, port);
else
g_string_append_printf(rtxt, "%s %s on le0 proto %s from any to %s port = %u",
IPFILTER_DENY, IPFILTER_IN, RT_TCP_UDP, addr, port);
}
static void sf_ipfw_ipv4_port(GString *rtxt, gchar *addr, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "add %s %s from %s to any %u %s",
IPFW_DENY, RT_TCP_UDP, addr, port, IPFW_IN);
}
static void sf_pf_ipv4_port(GString *rtxt, gchar *addr, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "%s %s quick on $ext_if proto %s from %s to any port %u",
PF_DENY, PF_IN, RT_TCP_UDP, addr, port);
}
static void sf_netfilter_ipv4_port(GString *rtxt, gchar *addr, guint32 port, port_type ptype, gboolean inbound, gboolean deny) {
g_string_append_printf(rtxt, "iptables --append %s --in-interface eth0 --protocol %s %s %s/32 %s %u --jump %s",
NF_INPUT, RT_TCP_UDP, NF_ADDR_DIR, addr, NF_PORT_DIR, port, NF_DROP);
}
static void sf_netsh_ipv4_port(GString *rtxt, gchar *addr, guint32 port, port_type ptype, gboolean inbound _U_, gboolean deny) {
g_string_append_printf(rtxt, "add portopening %s %u Wireshark %s %s",
RT_TCP_UDP, port, NETSH_DENY, addr);
}
