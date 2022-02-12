static void
_fill_label_value_string_bitmask(char *label, guint32 value, const value_string *vals)
{
char tmp[16];
label[0] = '\0';
while (vals->strptr) {
if (value & vals->value) {
value &= ~(vals->value);
if (label[0])
g_strlcat(label, ", ", ITEM_LABEL_LENGTH);
g_strlcat(label, vals->strptr, ITEM_LABEL_LENGTH);
}
vals++;
}
if (value) {
if (label[0])
g_strlcat(label, ", ", ITEM_LABEL_LENGTH);
g_snprintf(tmp, sizeof(tmp), "0x%x", value);
g_strlcat(label, tmp, ITEM_LABEL_LENGTH);
}
}
static int
dissect_netlink_route_attributes(tvbuff_t *tvb, header_field_info *hfi_type, struct netlink_route_info *info, proto_tree *tree, int offset, netlink_route_attributes_cb_t cb)
{
return dissect_netlink_attributes(tvb, hfi_type, ett_netlink_route_attr, info, tree, offset, (netlink_attributes_cb_t *) cb);
}
static void
hfi_netlink_route_ifi_flags_label(char *label, guint32 value)
{
static const value_string iff_vals[] = {
{ WS_IFF_UP, "UP" },
{ WS_IFF_BROADCAST, "BROADCAST" },
{ WS_IFF_DEBUG, "DEBUG" },
{ WS_IFF_LOOPBACK, "LOOPBACK" },
{ WS_IFF_POINTOPOINT, "POINTOPOINT" },
{ WS_IFF_NOTRAILERS, "NOTRAILERS" },
{ WS_IFF_RUNNING, "RUNNING" },
{ WS_IFF_NOARP, "NOARP" },
{ WS_IFF_PROMISC, "PROMISC" },
{ WS_IFF_ALLMULTI, "ALLMULTI" },
{ WS_IFF_MASTER, "MASTER" },
{ WS_IFF_SLAVE, "SLAVE" },
{ WS_IFF_MULTICAST, "MULTICAST" },
{ WS_IFF_PORTSEL, "PORTSEL" },
{ WS_IFF_AUTOMEDIA, "AUTOMEDIA" },
{ WS_IFF_DYNAMIC, "DYNAMIC" },
{ WS_IFF_LOWER_UP, "LOWER_UP" },
{ WS_IFF_DORMANT, "DORMANT" },
{ WS_IFF_ECHO, "ECHO" },
{ 0x00, NULL }
};
char tmp[16];
_fill_label_value_string_bitmask(label, value, iff_vals);
g_snprintf(tmp, sizeof(tmp), " (0x%.8x)", value);
g_strlcat(label, tmp, ITEM_LABEL_LENGTH);
}
static int
dissect_netlink_route_ifinfomsg(tvbuff_t *tvb, struct netlink_route_info *info, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *if_flags_tree;
proto_tree_add_item(tree, &hfi_netlink_route_ifi_family, tvb, offset, 1, info->encoding);
offset += 1;
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_ifi_type, tvb, offset, 2, info->encoding);
offset += 2;
proto_tree_add_item(tree, &hfi_netlink_route_ifi_index, tvb, offset, 4, info->encoding);
offset += 4;
ti = proto_tree_add_item(tree, &hfi_netlink_route_ifi_flags, tvb, offset, 4, info->encoding);
if_flags_tree = proto_item_add_subtree(ti, ett_netlink_route_if_flags);
if (if_flags_tree) {
proto_tree_add_item(if_flags_tree, &hfi_netlink_route_ifi_flags_iff_up, tvb, offset, 4, info->encoding);
proto_tree_add_item(if_flags_tree, &hfi_netlink_route_ifi_flags_iff_broadcast, tvb, offset, 4, info->encoding);
}
offset += 4;
proto_tree_add_item(tree, &hfi_netlink_route_ifi_change, tvb, offset, 4, info->encoding);
offset += 4;
return offset;
}
static int
dissect_netlink_route_ifla_attrs(tvbuff_t *tvb, struct netlink_route_info *info, proto_tree *tree, int rta_type, int offset, int len)
{
enum ws_ifla_attr_type type = (enum ws_ifla_attr_type) rta_type;
const guint8* str;
switch (type) {
case WS_IFLA_IFNAME:
proto_tree_add_item_ret_string(tree, hfi_netlink_route_ifla_ifname.id, tvb, offset, len, ENC_ASCII | ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(tree, ": %s", str);
return 1;
case WS_IFLA_MTU:
if (len == 4) {
proto_item_append_text(tree, ": %u", tvb_get_letohl(tvb, offset));
proto_tree_add_item(tree, &hfi_netlink_route_ifla_mtu, tvb, offset, len, info->encoding);
return 1;
}
return 0;
default:
return 0;
}
}
static void
hfi_netlink_route_ifa_flags_label(char *label, guint32 value)
{
static const value_string iff_vals[] = {
{ WS_IFA_F_SECONDARY, "secondary/temporary" },
{ WS_IFA_F_NODAD, "nodad" },
{ WS_IFA_F_OPTIMISTIC, "optimistic" },
{ WS_IFA_F_DADFAILED, "dadfailed" },
{ WS_IFA_F_HOMEADDRESS, "homeaddress" },
{ WS_IFA_F_DEPRECATED, "deprecated" },
{ WS_IFA_F_TENTATIVE, "tentative" },
{ WS_IFA_F_PERMANENT, "permanent" },
{ 0x00, NULL }
};
char tmp[16];
_fill_label_value_string_bitmask(label, value, iff_vals);
g_snprintf(tmp, sizeof(tmp), " (0x%.8x)", value);
g_strlcat(label, tmp, ITEM_LABEL_LENGTH);
}
static int
dissect_netlink_route_ifaddrmsg(tvbuff_t *tvb, struct netlink_route_info *info, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, &hfi_netlink_route_ifa_family, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_ifa_prefixlen, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_ifa_flags, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_ifa_scope, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_ifa_index, tvb, offset, 4, info->encoding);
offset += 4;
return offset;
}
static int
dissect_netlink_route_ifa_attrs(tvbuff_t *tvb, struct netlink_route_info *info _U_, proto_tree *tree, int rta_type, int offset, int len)
{
enum ws_ifa_attr_type type = (enum ws_ifa_attr_type) rta_type;
const guint8* str;
switch (type) {
case WS_IFA_LABEL:
proto_tree_add_item_ret_string(tree, hfi_netlink_route_ifa_label.id, tvb, offset, len, ENC_ASCII | ENC_NA, wmem_packet_scope(), &str);
proto_item_append_text(tree, ": %s", str);
return 1;
default:
return 0;
}
}
static int
dissect_netlink_route_rtmsg(tvbuff_t *tvb, struct netlink_route_info *info, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, &hfi_netlink_route_rt_family, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_rt_dst_len, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_rt_src_len, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_rt_tos, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_rt_table, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_rt_protocol, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_rt_scope, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_rt_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_rt_flags, tvb, offset, 4, info->encoding);
offset += 4;
return offset;
}
static int
dissect_netlink_route_route_attrs(tvbuff_t *tvb, struct netlink_route_info *info, proto_tree *tree, int rta_type, int offset, int len)
{
enum ws_rta_attr_type type = (enum ws_rta_attr_type) rta_type;
switch (type) {
case WS_RTA_IIF:
if (len == 4) {
proto_item_append_text(tree, ": %u", tvb_get_letohl(tvb, offset));
proto_tree_add_item(tree, &hfi_netlink_route_rta_iif, tvb, offset, 4, info->encoding);
return 1;
}
return 0;
case WS_RTA_OIF:
if (len == 4) {
proto_item_append_text(tree, ": %u", tvb_get_letohl(tvb, offset));
proto_tree_add_item(tree, &hfi_netlink_route_rta_oif, tvb, offset, 4, info->encoding);
return 1;
}
return 0;
default:
return 0;
}
}
static void
hfi_netlink_route_nd_states_label(char *label, guint32 value)
{
static const value_string flags_vals[] = {
{ WS_NUD_INCOMPLETE, "INCOMPLETE" },
{ WS_NUD_REACHABLE, "REACHABLE" },
{ WS_NUD_STALE, "STALE" },
{ WS_NUD_DELAY, "DELAY" },
{ WS_NUD_PROBE, "PROBE" },
{ WS_NUD_FAILED, "FAILED" },
{ WS_NUD_NOARP, "NOARP" },
{ WS_NUD_PERMANENT, "PERMAMENT" },
{ 0x00, NULL }
};
char tmp[16];
_fill_label_value_string_bitmask(label, value, flags_vals);
g_snprintf(tmp, sizeof(tmp), " (0x%.4x)", value);
g_strlcat(label, tmp, ITEM_LABEL_LENGTH);
}
static int
dissect_netlink_route_ndmsg(tvbuff_t *tvb, struct netlink_route_info *info, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, &hfi_netlink_route_nd_family, tvb, offset, 1, ENC_NA);
offset += 1;
offset += 3;
proto_tree_add_item(tree, &hfi_netlink_route_nd_index, tvb, offset, 4, info->encoding);
offset += 4;
proto_tree_add_item(tree, &hfi_netlink_route_nd_state, tvb, offset, 2, info->encoding);
offset += 2;
proto_tree_add_item(tree, &hfi_netlink_route_nd_flags, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_route_nd_type, tvb, offset, 1, ENC_NA);
offset += 1;
return offset;
}
static int
dissect_netlink_route(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *_data)
{
int offset;
struct netlink_route_info info;
struct packet_netlink_data *data = NULL;
if (_data) {
if (((struct packet_netlink_data *) _data)->magic == PACKET_NETLINK_MAGIC)
data = (struct packet_netlink_data *) _data;
}
DISSECTOR_ASSERT(data);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Netlink route");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
if (tree) {
proto_item_set_text(tree, "Linux rtnetlink (route netlink) message");
proto_tree_add_uint(tree, &hfi_netlink_route_nltype, NULL, 0, 0, data->type);
}
info.encoding = data->encoding;
info.pinfo = pinfo;
info.data = data;
switch (data->type) {
case WS_RTM_NEWLINK:
case WS_RTM_DELLINK:
case WS_RTM_GETLINK:
offset = dissect_netlink_route_ifinfomsg(tvb, &info, tree, offset);
offset = dissect_netlink_route_attributes(tvb, &hfi_netlink_route_ifla_attr_type, &info, tree, offset, dissect_netlink_route_ifla_attrs);
break;
case WS_RTM_NEWADDR:
case WS_RTM_DELADDR:
case WS_RTM_GETADDR:
offset = dissect_netlink_route_ifaddrmsg(tvb, &info, tree, offset);
offset = dissect_netlink_route_attributes(tvb, &hfi_netlink_route_ifa_attr_type, &info, tree, offset, dissect_netlink_route_ifa_attrs);
break;
case WS_RTM_NEWROUTE:
case WS_RTM_DELROUTE:
case WS_RTM_GETROUTE:
offset = dissect_netlink_route_rtmsg(tvb, &info, tree, offset);
offset = dissect_netlink_route_attributes(tvb, &hfi_netlink_route_rta_attr_type, &info, tree, offset, dissect_netlink_route_route_attrs);
break;
case WS_RTM_NEWNEIGH:
case WS_RTM_DELNEIGH:
case WS_RTM_GETNEIGH:
offset = dissect_netlink_route_ndmsg(tvb, &info, tree, offset);
break;
}
return offset;
}
void
proto_register_netlink_route(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_netlink_route_nltype,
&hfi_netlink_route_ifi_family,
&hfi_netlink_route_ifi_type,
&hfi_netlink_route_ifi_index,
&hfi_netlink_route_ifi_flags,
&hfi_netlink_route_ifi_flags_iff_up,
&hfi_netlink_route_ifi_flags_iff_broadcast,
&hfi_netlink_route_ifi_change,
&hfi_netlink_route_ifla_attr_type,
&hfi_netlink_route_ifla_ifname,
&hfi_netlink_route_ifla_mtu,
&hfi_netlink_route_ifa_family,
&hfi_netlink_route_ifa_prefixlen,
&hfi_netlink_route_ifa_flags,
&hfi_netlink_route_ifa_scope,
&hfi_netlink_route_ifa_index,
&hfi_netlink_route_ifa_attr_type,
&hfi_netlink_route_ifa_label,
&hfi_netlink_route_rt_family,
&hfi_netlink_route_rt_dst_len,
&hfi_netlink_route_rt_src_len,
&hfi_netlink_route_rt_tos,
&hfi_netlink_route_rt_table,
&hfi_netlink_route_rt_protocol,
&hfi_netlink_route_rt_scope,
&hfi_netlink_route_rt_type,
&hfi_netlink_route_rt_flags,
&hfi_netlink_route_rta_attr_type,
&hfi_netlink_route_rta_iif,
&hfi_netlink_route_rta_oif,
&hfi_netlink_route_nd_family,
&hfi_netlink_route_nd_index,
&hfi_netlink_route_nd_state,
&hfi_netlink_route_nd_flags,
&hfi_netlink_route_nd_type,
};
#endif
static gint *ett[] = {
&ett_netlink_route,
&ett_netlink_route_attr,
&ett_netlink_route_if_flags
};
int proto_netlink_route;
proto_netlink_route = proto_register_protocol("Linux rtnetlink (route netlink) protocol", "rtnetlink", "netlink-route" );
hfi_netlink_route = proto_registrar_get_nth(proto_netlink_route);
proto_register_fields(proto_netlink_route, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
netlink_route_handle = create_dissector_handle(dissect_netlink_route, proto_netlink_route);
}
void
proto_reg_handoff_netlink_route(void)
{
dissector_add_uint("netlink.protocol", WS_NETLINK_ROUTE, netlink_route_handle);
}
