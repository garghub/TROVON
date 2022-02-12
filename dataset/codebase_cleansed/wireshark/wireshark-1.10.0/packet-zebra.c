static int
dissect_zebra_request(proto_tree *tree, gboolean request, tvbuff_t *tvb,
int offset, guint16 len, guint8 command)
{
guint32 prefix4;
guint16 i;
guint8 buffer6[16], prefixlen, message;
proto_item *ti;
proto_tree *msg_tree;
proto_tree_add_uint(tree, hf_zebra_len, tvb, offset, 2, len);
offset += 2;
proto_tree_add_uint(tree, hf_zebra_command, tvb, offset, 1,
command);
offset += 1;
switch(command) {
case ZEBRA_INTERFACE_ADD:
case ZEBRA_INTERFACE_UP:
case ZEBRA_INTERFACE_DOWN:
if (request) break;
proto_tree_add_item(tree, hf_zebra_interface,
tvb, offset, INTERFACE_NAMSIZ, ENC_ASCII|ENC_NA);
offset += INTERFACE_NAMSIZ;
proto_tree_add_item(tree, hf_zebra_index, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_zebra_intflags, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_zebra_metric, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_zebra_mtu, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_zebra_bandwidth, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case ZEBRA_INTERFACE_DELETE:
proto_tree_add_item(tree, hf_zebra_interface,
tvb, offset, INTERFACE_NAMSIZ, ENC_ASCII|ENC_NA);
offset += INTERFACE_NAMSIZ;
proto_tree_add_item(tree, hf_zebra_index, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case ZEBRA_INTERFACE_ADDRESS_ADD:
case ZEBRA_INTERFACE_ADDRESS_DELETE:
proto_tree_add_item(tree, hf_zebra_index, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_zebra_family, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (len == 17) {
proto_tree_add_item(tree, hf_zebra_prefix4,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else if (len == 41) {
proto_tree_add_item(tree, hf_zebra_prefix6,
tvb, offset, 16, ENC_NA);
offset += 16;
}
else break;
proto_tree_add_item(tree, hf_zebra_prefixlen, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (len == 17) {
proto_tree_add_item(tree, hf_zebra_dest4,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else if (len == 41) {
proto_tree_add_item(tree, hf_zebra_dest6,
tvb, offset, 16, ENC_NA);
offset += 16;
}
break;
case ZEBRA_IPV4_ROUTE_ADD:
case ZEBRA_IPV4_ROUTE_DELETE:
proto_tree_add_item(tree, hf_zebra_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_zebra_rtflags, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
message = tvb_get_guint8(tvb, offset);
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
prefixlen = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zebra_prefixlen, tvb,
offset, 1, prefixlen);
offset += 1;
prefix4 = 0;
tvb_memcpy(tvb, (guint8 *)&prefix4, offset,
MIN((unsigned) PSIZE(prefixlen), sizeof prefix4));
proto_tree_add_ipv4(tree, hf_zebra_prefix4,
tvb, offset, PSIZE(prefixlen), prefix4);
offset += PSIZE(prefixlen);
if (message & ZEBRA_ZAPI_MESSAGE_NEXTHOP) {
i = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zebra_nexthopnum,
tvb, offset, 1, i);
offset += 1;
if (i>len) break;
while (i--) {
proto_tree_add_item(tree,
hf_zebra_nexthop4, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
}
if (message & ZEBRA_ZAPI_MESSAGE_IFINDEX) {
i = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zebra_indexnum,
tvb, offset, 1, i);
offset += 1;
if (i>len) break;
while (i--) {
proto_tree_add_item(tree,
hf_zebra_index, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
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
break;
case ZEBRA_IPV6_ROUTE_ADD:
case ZEBRA_IPV6_ROUTE_DELETE:
proto_tree_add_item(tree, hf_zebra_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_zebra_rtflags, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
message = tvb_get_guint8(tvb, offset);
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
prefixlen = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zebra_prefixlen, tvb,
offset, 1, prefixlen);
offset += 1;
memset(buffer6, '\0', sizeof buffer6);
tvb_memcpy(tvb, buffer6, offset,
MIN((unsigned) PSIZE(prefixlen), sizeof buffer6));
proto_tree_add_ipv6(tree, hf_zebra_prefix6,
tvb, offset, PSIZE(prefixlen), buffer6);
offset += PSIZE(prefixlen);
if (message & ZEBRA_ZAPI_MESSAGE_NEXTHOP) {
i = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zebra_nexthopnum,
tvb, offset, 1, i);
offset += 1;
if (i>len) break;
while (i--) {
proto_tree_add_item(tree,
hf_zebra_nexthop6, tvb,
offset, 16, ENC_NA);
offset += 16;
}
}
if (message & ZEBRA_ZAPI_MESSAGE_IFINDEX) {
i = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zebra_indexnum,
tvb, offset, 1, i);
offset += 1;
if (i>len) break;
while (i--) {
proto_tree_add_item(tree,
hf_zebra_index, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
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
break;
case ZEBRA_REDISTRIBUTE_ADD:
case ZEBRA_REDISTRIBUTE_DELETE:
proto_tree_add_item(tree, hf_zebra_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case ZEBRA_REDISTRIBUTE_DEFAULT_ADD:
case ZEBRA_REDISTRIBUTE_DEFAULT_DELETE:
break;
case ZEBRA_IPV4_NEXTHOP_LOOKUP:
proto_tree_add_item(tree, hf_zebra_nexthop4,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_zebra_metric,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case ZEBRA_IPV6_NEXTHOP_LOOKUP:
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
if (check_col(pinfo->cinfo, COL_INFO)) {
col_set_str(pinfo->cinfo, COL_INFO,
request? "ZEBRA Request" : "ZEBRA Reply");
}
if (tree) {
ti = proto_tree_add_item(tree, proto_zebra, tvb, offset, -1,
ENC_NA);
zebra_tree = proto_item_add_subtree(ti, ett_zebra);
ti = proto_tree_add_boolean(zebra_tree, hf_zebra_request,
tvb, offset, 0, request);
PROTO_ITEM_SET_HIDDEN(ti);
for (;;) {
guint8 command;
guint16 len;
proto_tree *zebra_request_tree;
if (left < 3) break;
len = tvb_get_ntohs(tvb, offset);
if (len < 3) break;
command = tvb_get_guint8(tvb, offset+2);
ti = proto_tree_add_uint(zebra_tree,
hf_zebra_command, tvb, offset, len,
command);
zebra_request_tree = proto_item_add_subtree(ti,
ett_zebra_request);
dissect_zebra_request(zebra_request_tree, request, tvb,
offset, len, command);
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
{ &hf_zebra_indexnum,
{ "Index Number", "zebra.indexnum",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of indices for route", HFILL }},
{ &hf_zebra_intflags,
{ "Flags", "zebra.intflags",
FT_UINT32, BASE_DEC, NULL, 0x0,
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
{ &hf_zebra_bandwidth,
{ "Bandwidth", "zebra.bandwidth",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Bandwidth of interface", HFILL }},
{ &hf_zebra_family,
{ "Family", "zebra.family",
FT_UINT32, BASE_DEC, VALS(families), 0x0,
"Family of IP address", HFILL }},
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
