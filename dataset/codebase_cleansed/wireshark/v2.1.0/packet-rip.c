static int
dissect_rip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_tree *rip_tree = NULL;
proto_item *ti;
guint8 command;
guint8 version;
guint16 family;
gint trailer_len = 0;
gboolean is_md5_auth = FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RIP");
col_clear(pinfo->cinfo, COL_INFO);
command = tvb_get_guint8(tvb, 0);
version = tvb_get_guint8(tvb, 1);
col_set_str(pinfo->cinfo, COL_PROTOCOL,
val_to_str_const(version, version_vals, "RIP"));
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(command, command_vals, "Unknown command (%u)"));
ti = proto_tree_add_item(tree, hfi_rip, tvb, 0, -1, ENC_NA);
rip_tree = proto_item_add_subtree(ti, ett_rip);
proto_tree_add_uint(rip_tree, &hfi_rip_command, tvb, 0, 1, command);
proto_tree_add_uint(rip_tree, &hfi_rip_version, tvb, 1, 1, version);
if (version == RIPv2 && pref_display_routing_domain == TRUE)
proto_tree_add_uint(rip_tree, &hfi_rip_routing_domain, tvb, 2, 2,
tvb_get_ntohs(tvb, 2));
offset = RIP_HEADER_LENGTH;
while (tvb_reported_length_remaining(tvb, offset) > trailer_len ) {
family = tvb_get_ntohs(tvb, offset);
switch (family) {
case AFVAL_UNSPEC:
dissect_unspec_rip_vektor(tvb, offset, version, rip_tree);
break;
case AFVAL_IP:
dissect_ip_rip_vektor(tvb, offset, version, rip_tree);
break;
case 0xFFFF:
if( offset == RIP_HEADER_LENGTH ) {
trailer_len=dissect_rip_authentication(tvb, offset, rip_tree);
is_md5_auth = TRUE;
break;
}
if(is_md5_auth && tvb_reported_length_remaining(tvb, offset) == 20)
break;
default:
proto_tree_add_expert_format(rip_tree, pinfo, &ei_rip_unknown_address_family, tvb, offset,
RIP_ENTRY_LENGTH, "Unknown address family %u", family);
break;
}
offset += RIP_ENTRY_LENGTH;
}
return tvb_captured_length(tvb);
}
static void
dissect_unspec_rip_vektor(tvbuff_t *tvb, int offset, guint8 version,
proto_tree *tree)
{
proto_tree *rip_vektor_tree;
guint32 metric;
metric = tvb_get_ntohl(tvb, offset+16);
rip_vektor_tree = proto_tree_add_subtree_format(tree, tvb, offset,
RIP_ENTRY_LENGTH, ett_rip_vec, NULL, "Address not specified, Metric: %u",
metric);
proto_tree_add_item(rip_vektor_tree, &hfi_rip_family, tvb, offset, 2, ENC_BIG_ENDIAN);
if (version == RIPv2) {
proto_tree_add_item(rip_vektor_tree, &hfi_rip_route_tag, tvb, offset+2, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item(rip_vektor_tree, &hfi_rip_netmask, tvb, offset+8, 4,
ENC_BIG_ENDIAN);
proto_tree_add_item(rip_vektor_tree, &hfi_rip_next_hop, tvb, offset+12, 4,
ENC_BIG_ENDIAN);
}
proto_tree_add_uint(rip_vektor_tree, &hfi_rip_metric, tvb,
offset+16, 4, metric);
}
static void
dissect_ip_rip_vektor(tvbuff_t *tvb, int offset, guint8 version,
proto_tree *tree)
{
proto_tree *rip_vektor_tree;
guint32 metric;
metric = tvb_get_ntohl(tvb, offset+16);
rip_vektor_tree = proto_tree_add_subtree_format(tree, tvb, offset,
RIP_ENTRY_LENGTH, ett_rip_vec, NULL, "IP Address: %s, Metric: %u",
tvb_ip_to_str(tvb, offset+4), metric);
proto_tree_add_item(rip_vektor_tree, &hfi_rip_family, tvb, offset, 2, ENC_BIG_ENDIAN);
if (version == RIPv2) {
proto_tree_add_item(rip_vektor_tree, &hfi_rip_route_tag, tvb, offset+2, 2,
ENC_BIG_ENDIAN);
}
proto_tree_add_item(rip_vektor_tree, &hfi_rip_ip, tvb, offset+4, 4, ENC_BIG_ENDIAN);
if (version == RIPv2) {
proto_tree_add_item(rip_vektor_tree, &hfi_rip_netmask, tvb, offset+8, 4,
ENC_BIG_ENDIAN);
proto_tree_add_item(rip_vektor_tree, &hfi_rip_next_hop, tvb, offset+12, 4,
ENC_BIG_ENDIAN);
}
proto_tree_add_uint(rip_vektor_tree, &hfi_rip_metric, tvb,
offset+16, 4, metric);
}
static gint
dissect_rip_authentication(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree *rip_authentication_tree;
guint16 authtype;
guint32 digest_off, auth_data_len;
auth_data_len = 0;
authtype = tvb_get_ntohs(tvb, offset + 2);
rip_authentication_tree = proto_tree_add_subtree_format(tree, tvb, offset, RIP_ENTRY_LENGTH,
ett_rip_vec, NULL, "Authentication: %s", val_to_str( authtype, rip_auth_type, "Unknown (%u)" ) );
proto_tree_add_uint(rip_authentication_tree, &hfi_rip_auth, tvb, offset+2, 2,
authtype);
switch ( authtype ) {
case AUTH_PASSWORD:
proto_tree_add_item(rip_authentication_tree, &hfi_rip_auth_passwd,
tvb, offset+4, 16, ENC_ASCII|ENC_NA);
break;
case AUTH_KEYED_MSG_DIGEST:
digest_off = tvb_get_ntohs( tvb, offset+4 );
proto_tree_add_item( rip_authentication_tree, &hfi_rip_digest_offset, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item( rip_authentication_tree, &hfi_rip_key_id, tvb, offset+6, 1, ENC_NA);
auth_data_len = tvb_get_guint8( tvb, offset+7 );
proto_tree_add_item( rip_authentication_tree, &hfi_rip_auth_data_len, tvb, offset+7, 1, ENC_NA);
proto_tree_add_item( rip_authentication_tree, &hfi_rip_auth_seq_num, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rip_authentication_tree, &hfi_rip_zero_padding, tvb, offset+12, 8, ENC_NA);
rip_authentication_tree = proto_tree_add_subtree( rip_authentication_tree, tvb, offset-4+digest_off,
MD5_AUTH_DATA_LEN+4, ett_auth_vec, NULL, "Authentication Data Trailer" );
proto_tree_add_item( rip_authentication_tree, &hfi_rip_authentication_data, tvb, offset-4+digest_off+4,
MD5_AUTH_DATA_LEN, ENC_NA);
break;
}
return auth_data_len;
}
void
proto_register_rip(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_rip_command,
&hfi_rip_version,
&hfi_rip_routing_domain,
&hfi_rip_ip,
&hfi_rip_netmask,
&hfi_rip_next_hop,
&hfi_rip_metric,
&hfi_rip_auth,
&hfi_rip_auth_passwd,
&hfi_rip_family,
&hfi_rip_route_tag,
&hfi_rip_zero_padding,
&hfi_rip_digest_offset,
&hfi_rip_key_id,
&hfi_rip_auth_data_len,
&hfi_rip_auth_seq_num,
&hfi_rip_authentication_data,
};
#endif
static gint *ett[] = {
&ett_rip,
&ett_rip_vec,
&ett_auth_vec,
};
static ei_register_info ei[] = {
{ &ei_rip_unknown_address_family, { "rip.unknown_address_family", PI_PROTOCOL, PI_WARN, "Unknown address family", EXPFILL }},
};
expert_module_t* expert_rip;
module_t *rip_module;
int proto_rip;
proto_rip = proto_register_protocol("Routing Information Protocol", "RIP", "rip");
hfi_rip = proto_registrar_get_nth(proto_rip);
proto_register_fields(proto_rip, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
expert_rip = expert_register_protocol(proto_rip);
expert_register_field_array(expert_rip, ei, array_length(ei));
rip_module = prefs_register_protocol(proto_rip, proto_reg_handoff_rip);
prefs_register_bool_preference(rip_module, "display_routing_domain", "Display Routing Domain field", "Display the third and forth bytes of the RIPv2 header as the Routing Domain field (introduced in RFC 1388 [January 1993] and obsolete as of RFC 1723 [November 1994])", &pref_display_routing_domain);
rip_handle = create_dissector_handle(dissect_rip, proto_rip);
}
void
proto_reg_handoff_rip(void)
{
dissector_add_uint("udp.port", UDP_PORT_RIP, rip_handle);
}
