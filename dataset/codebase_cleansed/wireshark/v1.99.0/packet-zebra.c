static int
zebra_route_nexthop(proto_tree *tree, tvbuff_t *tvb, int offset, guint16 len)
{
guint8 nexthoptype, nexthopcount, interfacenamelength;
nexthopcount = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zebra_nexthopnum,
tvb, offset, 1, nexthopcount);
offset += 1;
if (nexthopcount > len)
return offset;
while (nexthopcount--) {
nexthoptype = tvb_get_guint8(tvb, offset);
offset += 1;
if (nexthoptype == ZEBRA_NEXTHOP_TYPE_IFINDEX ||
nexthoptype == ZEBRA_NEXTHOP_TYPE_IPV4_IFINDEX ||
nexthoptype == ZEBRA_NEXTHOP_TYPE_IPV6_IFINDEX){
proto_tree_add_item(tree,hf_zebra_index, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (nexthoptype == ZEBRA_NEXTHOP_TYPE_IFNAME ||
nexthoptype == ZEBRA_NEXTHOP_TYPE_IPV4_IFNAME ||
nexthoptype == ZEBRA_NEXTHOP_TYPE_IPV6_IFNAME) {
interfacenamelength = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_zebra_interface,
tvb, offset, interfacenamelength,
ENC_ASCII|ENC_NA);
offset += interfacenamelength;
}
if (nexthoptype == ZEBRA_NEXTHOP_TYPE_IPV6 ||
nexthoptype == ZEBRA_NEXTHOP_TYPE_IPV6_IFINDEX ||
nexthoptype == ZEBRA_NEXTHOP_TYPE_IPV6_IFNAME) {
proto_tree_add_item(tree, hf_zebra_nexthop6,
tvb, offset, 16, ENC_NA);
offset += 16;
}
if (nexthoptype == ZEBRA_NEXTHOP_TYPE_IPV4 ||
nexthoptype == ZEBRA_NEXTHOP_TYPE_IPV4_IFINDEX ||
nexthoptype == ZEBRA_NEXTHOP_TYPE_IPV4_IFNAME) {
proto_tree_add_item(tree, hf_zebra_nexthop4,
tvb, offset, 4, ENC_NA);
offset += 4;
}
}
return offset;
}
static int
zebra_route_ifindex(proto_tree *tree, tvbuff_t *tvb, int offset, guint16 len)
{
guint16 indexcount = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zebra_indexnum,
tvb, offset, 1, indexcount);
offset += 1;
if (indexcount > len)
return offset;
while (indexcount--) {
proto_tree_add_item(tree, hf_zebra_index, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static guint8
zebra_route_message(proto_tree *tree, tvbuff_t *tvb, int offset, guint8 message)
{
proto_item *ti;
proto_tree *msg_tree;
ti = proto_tree_add_uint(tree, hf_zebra_message, tvb,
offset, 1, message);
msg_tree = proto_item_add_subtree(ti, ett_message);
proto_tree_add_boolean(msg_tree, hf_zebra_msg_nexthop,
tvb, offset, 1, message);
proto_tree_add_boolean(msg_tree, hf_zebra_msg_index,
tvb, offset, 1, message);
proto_tree_add_boolean(msg_tree, hf_zebra_msg_distance,
tvb, offset, 1, message);
proto_tree_add_boolean(msg_tree, hf_zebra_msg_metric,
tvb, offset, 1, message);
offset += 1;
return offset;
}
static int
zebra_route(proto_tree *tree, tvbuff_t *tvb, int offset, guint16 len,
guint8 family)
{
guint32 prefix4;
guint8 message, prefixlen, buffer6[16];
proto_tree_add_item(tree, hf_zebra_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_zebra_rtflags, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
message = tvb_get_guint8(tvb, offset);
offset = zebra_route_message(tree, tvb, offset, message);
prefixlen = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zebra_prefixlen, tvb,
offset, 1, prefixlen);
offset += 1;
if (family == ZEBRA_FAMILY_IPV6) {
memset(buffer6, '\0', sizeof buffer6);
tvb_memcpy(tvb, buffer6, offset,
MIN((unsigned) PSIZE(prefixlen), sizeof buffer6));
proto_tree_add_ipv6(tree, hf_zebra_prefix6,
tvb, offset, PSIZE(prefixlen), buffer6);
}else {
prefix4 = 0;
tvb_memcpy(tvb, (guint8 *)&prefix4, offset,
MIN((unsigned) PSIZE(prefixlen), sizeof prefix4));
proto_tree_add_ipv4(tree, hf_zebra_prefix4,
tvb, offset, PSIZE(prefixlen), prefix4);
}
offset += PSIZE(prefixlen);
if (message & ZEBRA_ZAPI_MESSAGE_NEXTHOP) {
offset = zebra_route_nexthop(tree, tvb, offset, len);
}
if (message & ZEBRA_ZAPI_MESSAGE_IFINDEX) {
offset = zebra_route_ifindex(tree, tvb, offset, len);
}
if (message & ZEBRA_ZAPI_MESSAGE_DISTANCE) {
proto_tree_add_item(tree, hf_zebra_distance,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (message & ZEBRA_ZAPI_MESSAGE_METRIC) {
proto_tree_add_item(tree, hf_zebra_metric,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static int
zebra_interface_address(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 family;
proto_tree_add_item(tree, hf_zebra_index, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_zebra_flags, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_zebra_family, tvb,
offset, 1, ENC_BIG_ENDIAN);
family = tvb_get_guint8(tvb, offset);
offset += 1;
if (family == ZEBRA_FAMILY_IPV4) {
proto_tree_add_item(tree, hf_zebra_prefix4,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else if (family == ZEBRA_FAMILY_IPV6) {
proto_tree_add_item(tree, hf_zebra_prefix6,
tvb, offset, 16, ENC_NA);
offset += 16;
}
else
return offset;
proto_tree_add_item(tree, hf_zebra_prefixlen, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (family == ZEBRA_FAMILY_IPV4) {
proto_tree_add_item(tree, hf_zebra_dest4,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else if (family == ZEBRA_FAMILY_IPV6) {
proto_tree_add_item(tree, hf_zebra_dest6,
tvb, offset, 16, ENC_NA);
offset += 16;
}
return offset;
}
static int
zebra_interface_del(proto_tree *tree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(tree, hf_zebra_interface,
tvb, offset, INTERFACE_NAMSIZ, ENC_ASCII|ENC_NA);
offset += INTERFACE_NAMSIZ;
proto_tree_add_item(tree, hf_zebra_index, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
zebra_interface(proto_tree *tree, tvbuff_t *tvb, int offset, guint8 version)
{
gint maclen;
proto_tree_add_item(tree, hf_zebra_interface,
tvb, offset, INTERFACE_NAMSIZ, ENC_ASCII|ENC_NA);
offset += INTERFACE_NAMSIZ;
proto_tree_add_item(tree, hf_zebra_index, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_zebra_intstatus, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (version != 0) {
proto_tree_add_item(tree, hf_zebra_intflags, tvb,
offset, 8, ENC_BIG_ENDIAN);
offset += 8;
} else {
proto_tree_add_item(tree, hf_zebra_intflags, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(tree, hf_zebra_metric, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_zebra_mtu, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (version != 0) {
proto_tree_add_item(tree, hf_zebra_mtu6, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(tree, hf_zebra_bandwidth, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (version != 0) {
maclen = (gint)tvb_get_ntohl(tvb, offset);
offset += 4;
if (maclen > 0)
proto_tree_add_item(tree, hf_zebra_mac, tvb,
offset, maclen, ENC_NA);
offset += maclen;
}
return offset;
}
static int
zebra_nexthop_lookup(proto_tree *tree, tvbuff_t *tvb, int offset, guint16 len,
guint8 family)
{
if (family == ZEBRA_FAMILY_IPV6) {
proto_tree_add_item(tree, hf_zebra_dest6, tvb, offset, 16,
ENC_NA);
offset += 16;
}else {
proto_tree_add_item(tree, hf_zebra_dest4, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(tree, hf_zebra_metric,tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = zebra_route_nexthop(tree, tvb, offset, len);
return offset;
}
static int
zerba_router_update(proto_tree *tree, tvbuff_t *tvb, int offset)
{
offset += 1;
proto_tree_add_item(tree, hf_zebra_routeridaddress, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_zebra_routeridmask, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_zebra_request(proto_tree *tree, gboolean request, tvbuff_t *tvb,
int offset, guint16 len, guint16 command, guint8 version)
{
proto_tree_add_uint(tree, hf_zebra_len, tvb, offset, 2, len);
offset += 2;
if (version != 0) {
proto_tree_add_uint(tree, hf_zebra_version, tvb, offset, 1,
version);
offset += 2;
proto_tree_add_uint(tree, hf_zebra_command, tvb, offset, 2,
command);
offset += 2;
} else {
proto_tree_add_uint(tree, hf_zebra_command, tvb, offset, 1,
command);
offset += 1;
}
switch(command) {
case ZEBRA_INTERFACE_ADD:
case ZEBRA_INTERFACE_UP:
case ZEBRA_INTERFACE_DOWN:
if (request)
break;
offset = zebra_interface(tree, tvb, offset, version);
break;
case ZEBRA_INTERFACE_DELETE:
offset = zebra_interface_del(tree, tvb, offset);
break;
case ZEBRA_INTERFACE_ADDRESS_ADD:
case ZEBRA_INTERFACE_ADDRESS_DELETE:
offset = zebra_interface_address(tree, tvb, offset);
break;
case ZEBRA_IPV4_ROUTE_ADD:
case ZEBRA_IPV4_ROUTE_DELETE:
offset = zebra_route(tree, tvb, offset, len,
ZEBRA_FAMILY_IPV4);
break;
case ZEBRA_IPV6_ROUTE_ADD:
case ZEBRA_IPV6_ROUTE_DELETE:
offset = zebra_route(tree, tvb, offset, len,
ZEBRA_FAMILY_IPV6);
break;
case ZEBRA_REDISTRIBUTE_ADD:
case ZEBRA_REDISTRIBUTE_DEFAULT_ADD:
proto_tree_add_item(tree, hf_zebra_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset = 1;
break;
case ZEBRA_IPV4_IMPORT_LOOKUP:
case ZEBRA_IPV4_NEXTHOP_LOOKUP:
offset = zebra_nexthop_lookup(tree, tvb, offset, len,
ZEBRA_FAMILY_IPV4);
break;
case ZEBRA_IPV6_IMPORT_LOOKUP:
case ZEBRA_IPV6_NEXTHOP_LOOKUP:
offset = zebra_nexthop_lookup(tree, tvb, offset, len,
ZEBRA_FAMILY_IPV6);
break;
case ZEBRA_ROUTER_ID_UPDATE:
offset = zerba_router_update(tree, tvb, offset);
break;
case ZEBRA_REDISTRIBUTE_DEFAULT_DELETE:
case ZEBRA_REDISTRIBUTE_DELETE:
break;
}
return offset;
}
static void
dissect_zebra(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *zebra_tree;
gboolean request;
int left, offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ZEBRA");
request = (pinfo->destport == pinfo->match_uint);
left = tvb_reported_length(tvb);
offset = 0;
col_set_str(pinfo->cinfo, COL_INFO,
request? "ZEBRA Request" : "ZEBRA Reply");
if (tree) {
ti = proto_tree_add_item(tree, proto_zebra, tvb, offset, -1,
ENC_NA);
zebra_tree = proto_item_add_subtree(ti, ett_zebra);
ti = proto_tree_add_boolean(zebra_tree, hf_zebra_request,
tvb, offset, 0, request);
PROTO_ITEM_SET_HIDDEN(ti);
for (;;) {
guint8 headermarker, version;
guint16 command, len;
proto_tree *zebra_request_tree;
if (left < 3)
break;
len = tvb_get_ntohs(tvb, offset);
if (len < 3)
break;
headermarker = tvb_get_guint8(tvb,offset+2);
if (headermarker != 0xFF) {
command = headermarker;
version = 0;
} else {
version = tvb_get_guint8(tvb, offset+3);
command = tvb_get_ntohs(tvb, offset+4);
}
ti = proto_tree_add_uint(zebra_tree,
hf_zebra_command, tvb,
offset, len, command);
zebra_request_tree = proto_item_add_subtree(ti,
ett_zebra_request);
dissect_zebra_request(zebra_request_tree, request, tvb,
offset, len, command, version);
offset += len;
left -= len;
}
}
}
void
proto_register_zebra(void)
{
static hf_register_info hf[] = {
{ &hf_zebra_len,
{ "Length", "zebra.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of ZEBRA request", HFILL }},
{ &hf_zebra_version,
{ "Version", "zebra.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Zerbra srv version", HFILL }},
{ &hf_zebra_request,
{ "Request", "zebra.request",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if ZEBRA request", HFILL }},
{ &hf_zebra_command,
{ "Command", "zebra.command",
FT_UINT8, BASE_DEC, VALS(messages), 0x0,
"ZEBRA command", HFILL }},
{ &hf_zebra_interface,
{ "Interface", "zebra.interface",
FT_STRING, BASE_NONE, NULL, 0x0,
"Interface name of ZEBRA request", HFILL }},
{ &hf_zebra_index,
{ "Index", "zebra.index",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Index of interface", HFILL }},
{ &hf_zebra_intstatus,
{ "Status", "zebra.intstatus",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Status of interface", HFILL}},
{ &hf_zebra_indexnum,
{ "Index Number", "zebra.indexnum",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of indices for route", HFILL }},
{ &hf_zebra_intflags,
{ "Flags", "zebra.intflags",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Flags of interface", HFILL }},
{ &hf_zebra_rtflags,
{ "Flags", "zebra.rtflags",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Flags of route", HFILL }},
{ &hf_zebra_message,
{ "Message", "zebra.message",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Message type of route", HFILL }},
{ &hf_zebra_msg_nexthop,
{ "Message Nexthop", "zebra.message.nexthop",
FT_BOOLEAN, 8, NULL, ZEBRA_ZAPI_MESSAGE_NEXTHOP,
"Message contains nexthop", HFILL }},
{ &hf_zebra_msg_index,
{ "Message Index", "zebra.message.index",
FT_BOOLEAN, 8, NULL, ZEBRA_ZAPI_MESSAGE_IFINDEX,
"Message contains index", HFILL }},
{ &hf_zebra_msg_distance,
{ "Message Distance", "zebra.message.distance",
FT_BOOLEAN, 8, NULL, ZEBRA_ZAPI_MESSAGE_DISTANCE,
"Message contains distance", HFILL }},
{ &hf_zebra_msg_metric,
{ "Message Metric", "zebra.message.metric",
FT_BOOLEAN, 8, NULL, ZEBRA_ZAPI_MESSAGE_METRIC,
"Message contains metric", HFILL }},
{ &hf_zebra_type,
{ "Type", "zebra.type",
FT_UINT8, BASE_DEC, VALS(routes), 0x0,
"Type of route", HFILL }},
{ &hf_zebra_distance,
{ "Distance", "zebra.distance",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Distance of route", HFILL }},
{ &hf_zebra_metric,
{ "Metric", "zebra.metric",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Metric of interface or route", HFILL }},
{ &hf_zebra_mtu,
{ "MTU", "zebra.mtu",
FT_UINT32, BASE_DEC, NULL, 0x0,
"MTU of interface", HFILL }},
{ &hf_zebra_mtu6,
{ "MTUv6", "zebra.mtu6",
FT_UINT32, BASE_DEC, NULL, 0x0,
"MTUv6 of interface", HFILL }},
{ &hf_zebra_bandwidth,
{ "Bandwidth", "zebra.bandwidth",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Bandwidth of interface", HFILL }},
{ &hf_zebra_family,
{ "Family", "zebra.family",
FT_UINT8, BASE_DEC, VALS(families), 0x0,
"Family of IP address", HFILL }},
{ &hf_zebra_flags,
{ "Flags", "zebra.flags",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Flags of Address Info", HFILL }},
{ &hf_zebra_dest4,
{ "Destination", "zebra.dest4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Destination IPv4 field", HFILL }},
{ &hf_zebra_dest6,
{ "Destination", "zebra.dest6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Destination IPv6 field", HFILL }},
{ &hf_zebra_nexthopnum,
{ "Nexthop Number", "zebra.nexthopnum",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of nexthops in route", HFILL }},
{ &hf_zebra_nexthop4,
{ "Nexthop", "zebra.nexthop4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Nethop IPv4 field of route", HFILL }},
{ &hf_zebra_nexthop6,
{ "Nexthop", "zebra.nexthop6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Nethop IPv6 field of route", HFILL }},
{ &hf_zebra_prefixlen,
{ "Prefix length", "zebra.prefixlen",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zebra_prefix4,
{ "Prefix", "zebra.prefix4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Prefix IPv4", HFILL }},
{ &hf_zebra_prefix6,
{ "Prefix", "zebra.prefix6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Prefix IPv6", HFILL }},
{ &hf_zebra_routeridaddress,
{ "Router ID address", "zebra.routerIDAddress",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Router ID", HFILL }},
{ &hf_zebra_routeridmask,
{ "Router ID mask", "zebra.routerIDMask",
FT_UINT8, BASE_DEC, NULL, 0x0,
"netmask of Router ID", HFILL }},
{ &hf_zebra_mac,
{ "MAC address", "zebra.macaddress",
FT_ETHER, BASE_NONE, NULL, 0x0,
"MAC address of interface", HFILL }},
};
static gint *ett[] = {
&ett_zebra,
&ett_zebra_request,
&ett_message,
};
proto_zebra = proto_register_protocol("Zebra Protocol", "ZEBRA", "zebra");
proto_register_field_array(proto_zebra, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_zebra(void)
{
dissector_handle_t zebra_handle;
zebra_handle = create_dissector_handle(dissect_zebra, proto_zebra);
dissector_add_uint("tcp.port", TCP_PORT_ZEBRA, zebra_handle);
}
