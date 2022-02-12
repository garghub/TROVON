static int
rsip_parameter(tvbuff_t *tvb, proto_tree *rsip_tree, int off, int eoff)
{
int consumed, i, paramleft;
guint8 addrtype, flowpolicy, method, number, paramtype, tuntype;
guint16 error, ind, paramlen, portnum;
guint32 bid, cid, leasetm, msgc;
proto_tree *p_tree, *v_tree;
proto_item *pti, *vti;
if (off >= eoff)
return 0;
paramtype = tvb_get_guint8(tvb, off);
paramlen = tvb_get_ntohs(tvb, off + 1);
p_tree = proto_tree_add_subtree(rsip_tree, tvb, off, 3 + paramlen,
ett_rsip_param, &pti,
val_to_str(paramtype, param_type_vals, "Unknown (%d)"));
proto_tree_add_item(p_tree, hf_rsip_parameter_type, tvb,
off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(p_tree, hf_rsip_parameter_length, tvb,
off + 1, 2, ENC_BIG_ENDIAN);
consumed = 3;
if (paramlen == 0)
return consumed;
vti = proto_tree_add_item(p_tree, hf_rsip_parameter_value,
tvb, off + 3, paramlen, ENC_NA);
v_tree = proto_item_add_subtree(vti, ett_rsip_param_val);
switch (paramtype) {
case 1:
proto_tree_add_item(v_tree, hf_rsip_parameter_address_type,
tvb, off + 3, 1, ENC_BIG_ENDIAN);
addrtype = tvb_get_guint8(tvb, off + 3);
switch (addrtype) {
case 0:
break;
case 1:
if (paramlen - 1 > 0) {
proto_tree_add_item(v_tree,
hf_rsip_parameter_address_ipv4, tvb,
off + 4, paramlen - 1, ENC_BIG_ENDIAN);
proto_item_append_text(pti, ": %s",
tvb_ip_to_str(tvb, off + 4));
} else
proto_item_append_text(pti,
": Any IPv4 Address");
break;
case 2:
if (paramlen - 1 > 0) {
proto_tree_add_item(v_tree,
hf_rsip_parameter_address_ipv4_netmask,
tvb, off + 4, paramlen - 1, ENC_BIG_ENDIAN);
proto_item_append_text(pti, "(netmask): %s",
tvb_ip_to_str(tvb, off + 4));
} else
proto_item_append_text(pti,
": Any IPv4 Netmask");
break;
case 3:
if (paramlen - 1 > 0) {
proto_tree_add_item(v_tree,
hf_rsip_parameter_address_ipv6, tvb,
off + 4, paramlen - 1, ENC_NA);
proto_item_append_text(pti, ": %s",
tvb_ip6_to_str(tvb, off + 4));
} else
proto_item_append_text(pti,
": Any IPv6 Address");
break;
case 4:
if (paramlen - 1 > 0) {
proto_tree_add_item(v_tree,
hf_rsip_parameter_address_fqdn, tvb,
off + 4, paramlen - 1, ENC_ASCII|ENC_NA);
proto_item_append_text(pti, ": %s",
tvb_format_text(tvb, off + 4, paramlen - 1));
} else
proto_item_append_text(pti,
": Any Fully Qualified Domain Name");
break;
default:
proto_item_append_text(pti, ": Unknown Address Type");
break;
}
break;
case 2:
proto_tree_add_item(v_tree, hf_rsip_parameter_ports_number,
tvb, off + 3, 1, ENC_BIG_ENDIAN);
number = tvb_get_guint8(tvb, off + 3);
if (paramlen == 1) {
switch (number) {
case 0:
proto_item_append_text(pti, ": Unspecified");
break;
case 1:
proto_item_append_text(pti, ": Any port");
break;
default:
proto_item_append_text(pti, ": Any %d ports",
number);
break;
}
} else {
portnum = tvb_get_ntohs(tvb, off + 4);
if (number == 1) {
proto_tree_add_item(v_tree,
hf_rsip_parameter_ports_port_number,
tvb, off + 4, 2, ENC_BIG_ENDIAN);
} else {
paramleft = paramlen - 1;
if (paramleft == 2) {
proto_tree_add_uint_format_value(v_tree,
hf_rsip_parameter_ports_port_number,
tvb, off + 4, 2, portnum, "%d - %d",
portnum, portnum + number);
proto_item_append_text(pti,
": %d - %d", portnum,
portnum + number);
} else {
for (i = off + 4;
paramleft > 0;
i += 2, paramleft -= 2)
proto_tree_add_item(v_tree,
hf_rsip_parameter_ports_port_number,
tvb, i, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pti,
": List of %d Ports", number);
}
}
}
break;
case 3:
proto_tree_add_item(v_tree, hf_rsip_parameter_lease_time,
tvb, off + 3, paramlen, ENC_BIG_ENDIAN);
leasetm = tvb_get_ntohl(tvb, off + 3);
proto_item_append_text(pti, ": %d seconds", leasetm);
break;
case 4:
proto_tree_add_item(v_tree, hf_rsip_parameter_client_id,
tvb, off + 3, paramlen, ENC_BIG_ENDIAN);
cid = tvb_get_ntohl(tvb, off + 3);
proto_item_append_text(pti, ": %d", cid);
break;
case 5:
proto_tree_add_item(v_tree, hf_rsip_parameter_bind_id,
tvb, off + 3, paramlen, ENC_BIG_ENDIAN);
bid = tvb_get_ntohl(tvb, off + 3);
proto_item_append_text(pti, ": %d", bid);
break;
case 6:
proto_tree_add_item(v_tree, hf_rsip_parameter_tunnel_type,
tvb, off + 3, paramlen, ENC_BIG_ENDIAN);
tuntype = tvb_get_guint8(tvb, off + 3);
proto_item_append_text(pti, ": %s",
val_to_str(tuntype, tunnel_type_vals,
"Unknown Tunnel Type (%d)"));
break;
case 7:
proto_tree_add_item(v_tree, hf_rsip_parameter_method,
tvb, off + 3, paramlen, ENC_BIG_ENDIAN);
method = tvb_get_guint8(tvb, off + 3);
proto_item_append_text(pti, ": %s",
val_to_str(method, method_vals,
"Unknown RSIP Method (%d)"));
break;
case 8:
proto_tree_add_item(v_tree, hf_rsip_parameter_error,
tvb, off + 3, paramlen, ENC_BIG_ENDIAN);
error = tvb_get_ntohs(tvb, off + 3);
proto_item_append_text(pti, ": %s",
val_to_str(error, error_number_vals, "Undefined Error (%d)"));
break;
case 9:
proto_tree_add_item(v_tree,
hf_rsip_parameter_flow_policy_local, tvb, off + 3, 1, ENC_BIG_ENDIAN);
flowpolicy = tvb_get_guint8(tvb, off + 3);
proto_item_append_text(pti, ": %s",
val_to_str(flowpolicy, lcl_flow_policy_vals,
"Undefined Local Flow Policy (%d)"));
proto_tree_add_item(v_tree,
hf_rsip_parameter_flow_policy_remote, tvb, off + 4, 1,
ENC_BIG_ENDIAN);
flowpolicy = tvb_get_guint8(tvb, off + 4);
proto_item_append_text(pti, "/%s",
val_to_str(flowpolicy, rmt_flow_policy_vals,
"Undefined Remote Flow Policy (%d)"));
break;
case 10:
proto_tree_add_item(v_tree, hf_rsip_parameter_indicator, tvb,
off + 3, 2, ENC_BIG_ENDIAN);
ind = tvb_get_ntohs(tvb, off + 3);
proto_item_append_text(pti, ": %d", ind);
break;
case 11:
proto_tree_add_item(v_tree, hf_rsip_parameter_message_counter,
tvb, off + 3, 4, ENC_BIG_ENDIAN);
msgc = tvb_get_ntohl(tvb, off + 3);
proto_item_append_text(pti, ": %d", msgc);
break;
case 12:
proto_tree_add_item(v_tree,
hf_rsip_parameter_vendor_specific_vendor_id, tvb, off + 3,
2, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree,
hf_rsip_parameter_vendor_specific_subtype, tvb, off + 5,
2, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree,
hf_rsip_parameter_vendor_specific_value, tvb, off + 9,
paramlen - 4, ENC_NA);
break;
case 22:
proto_tree_add_item(v_tree, hf_rsip_parameter_spi_number, tvb,
off + 3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(v_tree, hf_rsip_parameter_spi, tvb,
off + 5, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
consumed += paramlen;
return consumed;
}
static int
rsip_message_error_response(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_register_request(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_register_response(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_deregister_request(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_deregister_response(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
return rsip_message_deregister_request(tvb, rsip_tree, offset, eoffset);
}
static int
rsip_message_assign_request_rsaip(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_assign_response_rsaip(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_assign_request_rsapip(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_assign_response_rsapip(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_extend_request(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_extend_response(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_free_request(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_free_response(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_query_request(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_query_response(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_listen_request(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_listen_response(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_assign_request_rsipsec(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
rsip_message_assign_response_rsipsec(tvbuff_t *tvb, proto_tree *rsip_tree,
int offset, int eoffset)
{
int consumed, offset_delta;
consumed = 0;
do {
offset_delta =
rsip_parameter(tvb, rsip_tree, offset, eoffset);
offset += offset_delta;
consumed += offset_delta;
} while ((offset_delta > 0) && (offset < eoffset));
return consumed;
}
static int
dissect_rsip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *rsip_tree;
guint8 msgtype;
int eoff;
msgtype = tvb_get_guint8(tvb, 1);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RSIP");
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(msgtype, msg_type_vals,
"Unknown Message Type (0x%0x)"));
if (tree) {
ti = proto_tree_add_item(tree, proto_rsip, tvb, 0, -1, ENC_NA);
rsip_tree = proto_item_add_subtree(ti, ett_rsip);
proto_tree_add_item(rsip_tree,
hf_rsip_version, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsip_tree,
hf_rsip_message_type, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rsip_tree,
hf_rsip_message_length, tvb, 2, 2, ENC_BIG_ENDIAN);
eoff = tvb_reported_length(tvb);
switch (msgtype) {
case 1:
rsip_message_error_response(tvb, rsip_tree, 4, eoff);
break;
case 2:
rsip_message_register_request(tvb, rsip_tree, 4, eoff);
break;
case 3:
rsip_message_register_response(tvb, rsip_tree, 4, eoff);
break;
case 4:
rsip_message_deregister_request(tvb, rsip_tree, 4, eoff);
break;
case 5:
rsip_message_deregister_response(tvb, rsip_tree, 4, eoff);
break;
case 6:
rsip_message_assign_request_rsaip(tvb, rsip_tree, 4, eoff);
break;
case 7:
rsip_message_assign_response_rsaip(tvb, rsip_tree, 4, eoff);
break;
case 8:
rsip_message_assign_request_rsapip(tvb, rsip_tree, 4, eoff);
break;
case 9:
rsip_message_assign_response_rsapip(tvb, rsip_tree, 4, eoff);
break;
case 10:
rsip_message_extend_request(tvb, rsip_tree, 4, eoff);
break;
case 11:
rsip_message_extend_response(tvb, rsip_tree, 4, eoff);
break;
case 12:
rsip_message_free_request(tvb, rsip_tree, 4, eoff);
break;
case 13:
rsip_message_free_response(tvb, rsip_tree, 4, eoff);
break;
case 14:
rsip_message_query_request(tvb, rsip_tree, 4, eoff);
break;
case 15:
rsip_message_query_response(tvb, rsip_tree, 4, eoff);
break;
case 16:
rsip_message_listen_request(tvb, rsip_tree, 4, eoff);
break;
case 17:
rsip_message_listen_response(tvb, rsip_tree, 4, eoff);
break;
case 22:
rsip_message_assign_request_rsipsec(tvb, rsip_tree, 4, eoff);
break;
case 23:
rsip_message_assign_response_rsipsec(tvb, rsip_tree, 4, eoff);
break;
}
}
return tvb_captured_length(tvb);
}
void
proto_register_rsip(void)
{
static hf_register_info hf[] = {
{ &hf_rsip_version,
{ "Protocol version", "rsip.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_message_type,
{ "Message type", "rsip.message_type",
FT_UINT8, BASE_DEC, VALS(msg_type_appendix_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsip_message_length,
{ "Message length", "rsip.message_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_type,
{ "Type", "rsip.parameter.type",
FT_UINT8, BASE_DEC, VALS(param_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_length,
{ "Length", "rsip.parameter.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_value,
{ "Value", "rsip.parameter.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_rsip_parameter_address_type,
{ "Address type", "rsip.parameter.address_type",
FT_UINT8, BASE_DEC, VALS(addr_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_address_ipv4,
{ "IPv4 Address", "rsip.parameter.address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_address_ipv4_netmask,
{ "IPv4 Netmask", "rsip.parameter.netmask",
FT_IPv4, BASE_NETMASK, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_address_ipv6,
{ "IPv6 Address", "rsip.parameter.address.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_address_fqdn,
{ "Fully Qualified Domain Name", "rsip.parameter.fqdn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_ports_number,
{ "Number", "rsip.parameter.ports.number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_ports_port_number,
{ "Port", "rsip.parameter.ports.port_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_lease_time,
{ "Lease time", "rsip.parameter.lease_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_client_id,
{ "Client ID", "rsip.parameter.client_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_bind_id,
{ "Bind ID", "rsip.parameter.bind_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_tunnel_type,
{ "Tunnel type", "rsip.parameter.tunnel_type",
FT_UINT8, BASE_DEC, VALS(tunnel_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_method,
{ "Method", "rsip.method_param.method",
FT_UINT8, BASE_DEC, VALS(method_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_error,
{ "Error", "rsip.parameter.error",
FT_UINT16, BASE_DEC, VALS(error_number_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_flow_policy_local,
{ "Local Flow Policy", "rsip.parameter.local_flow_policy",
FT_UINT8, BASE_DEC, VALS(lcl_flow_policy_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_flow_policy_remote,
{ "Remote Flow Policy", "rsip.parameter.remote_flow_policy",
FT_UINT8, BASE_DEC, VALS(rmt_flow_policy_vals), 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_indicator,
{ "Value", "rsip.parameter.indicator",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_message_counter,
{ "Counter", "rsip.parameter.message_counter",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_vendor_specific_vendor_id,
{ "Vendor ID", "rsip.parameter.vendor_specific.vendor_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_vendor_specific_subtype,
{ "Subtype", "rsip.parameter.vendor_specific.subtype",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_vendor_specific_value,
{ "Value", "rsip.parameter.vendor_specific.value",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_spi_number,
{ "Number", "rsip.parameter.spi_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rsip_parameter_spi,
{ "SPI", "rsip.parameter.spi",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_rsip,
&ett_rsip_param,
&ett_rsip_param_val
};
proto_rsip = proto_register_protocol("Realm Specific IP Protocol",
"RSIP", "rsip");
proto_register_field_array(proto_rsip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_rsip(void)
{
dissector_handle_t rsip_handle;
rsip_handle = create_dissector_handle(dissect_rsip, proto_rsip);
dissector_add_uint_with_preference("udp.port", UDP_PORT_RSIP, rsip_handle);
dissector_add_uint_with_preference("tcp.port", TCP_PORT_RSIP, rsip_handle);
}
