static void dissect_igrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 ver_and_opcode,version,opcode,network;
gint offset=IGRP_HEADER_LENGTH;
guint16 ninterior,nsystem,nexterior;
const guint8 *ipsrc;
proto_item *ti;
proto_tree *igrp_tree, *igrp_vektor_tree;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IGRP");
col_clear(pinfo->cinfo, COL_INFO);
ver_and_opcode = tvb_get_guint8(tvb,0);
switch (ver_and_opcode) {
case 0x11:
col_set_str(pinfo->cinfo, COL_INFO, "Response" );
break;
case 0x12:
col_set_str(pinfo->cinfo, COL_INFO, "Request" );
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unknown version or opcode");
}
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_igrp, tvb, 0, -1,
"Cisco IGRP");
igrp_tree = proto_item_add_subtree(ti, ett_igrp);
version = (ver_and_opcode&0xf0)>>4 ;
opcode = ver_and_opcode&0x0f ;
ti = proto_tree_add_item(igrp_tree, hf_igrp_version, tvb, 0, 1, ENC_BIG_ENDIAN);
if (version != 1)
expert_add_info(pinfo, ti, &ei_igrp_version);
ti = proto_tree_add_item(igrp_tree, hf_igrp_command, tvb, 0, 1, ENC_BIG_ENDIAN);
if (opcode==1)
proto_item_append_text(ti, " (Response)");
else
proto_item_append_text(ti, " (Request)");
proto_tree_add_item(igrp_tree, hf_igrp_update, tvb, 1,1, ENC_BIG_ENDIAN);
proto_tree_add_item(igrp_tree, hf_igrp_as, tvb, 2,2, ENC_BIG_ENDIAN);
ninterior = tvb_get_ntohs(tvb,4);
nsystem = tvb_get_ntohs(tvb,6);
nexterior = tvb_get_ntohs(tvb,8);
if (pinfo->net_src.type == AT_IPv4) {
ipsrc = (const guint8 *)pinfo->net_src.data;
network = ipsrc[0];
} else
network = 0;
ti = proto_tree_add_item(igrp_tree, hf_igrp_interior_routes, tvb, 4, 2, ENC_BIG_ENDIAN);
for( ; ninterior>0 ; ninterior-- ) {
igrp_vektor_tree = proto_item_add_subtree(ti,ett_igrp_vektor);
next_tvb = tvb_new_subset(tvb, offset, IGRP_ENTRY_LENGTH, -1);
dissect_vektor_igrp (next_tvb,igrp_vektor_tree,network);
offset+=IGRP_ENTRY_LENGTH;
}
ti = proto_tree_add_item(igrp_tree, hf_igrp_system_routes, tvb, 6, 2, ENC_BIG_ENDIAN);
for( ; nsystem>0 ; nsystem-- ) {
igrp_vektor_tree = proto_item_add_subtree(ti,ett_igrp_vektor);
next_tvb = tvb_new_subset(tvb, offset, IGRP_ENTRY_LENGTH, -1);
dissect_vektor_igrp (next_tvb,igrp_vektor_tree,0);
offset+=IGRP_ENTRY_LENGTH;
}
ti = proto_tree_add_item(igrp_tree, hf_igrp_exterior_routes, tvb, 8, 2, ENC_BIG_ENDIAN);
for( ; nexterior>0 ; nexterior-- ) {
igrp_vektor_tree = proto_item_add_subtree(ti,ett_igrp_vektor);
next_tvb = tvb_new_subset(tvb, offset, IGRP_ENTRY_LENGTH, -1);
dissect_vektor_igrp (next_tvb,igrp_vektor_tree,0);
offset+=IGRP_ENTRY_LENGTH;
}
proto_tree_add_item(igrp_tree, hf_igrp_checksum, tvb, 10, 2, ENC_BIG_ENDIAN);
}
}
static void dissect_vektor_igrp (tvbuff_t *tvb, proto_tree *igrp_vektor_tree, guint8 network)
{
union {
guint8 addr_bytes[4];
guint32 addr_word;
} addr;
address ip_addr;
if (network != 0) {
addr.addr_bytes[0]=network;
addr.addr_bytes[1]=tvb_get_guint8(tvb,0);
addr.addr_bytes[2]=tvb_get_guint8(tvb,1);
addr.addr_bytes[3]=tvb_get_guint8(tvb,2);
} else {
addr.addr_bytes[0]=tvb_get_guint8(tvb,0);
addr.addr_bytes[1]=tvb_get_guint8(tvb,1);
addr.addr_bytes[2]=tvb_get_guint8(tvb,2);
addr.addr_bytes[3]=0;
}
SET_ADDRESS(&ip_addr, AT_IPv4, 4, &addr);
igrp_vektor_tree = proto_tree_add_subtree_format(igrp_vektor_tree, tvb, 0 ,14,
ett_igrp_net, NULL, "Entry for network %s", address_to_str(wmem_packet_scope(), &ip_addr));
proto_tree_add_ipv4(igrp_vektor_tree, hf_igrp_network, tvb, 0, 3, addr.addr_word);
proto_tree_add_item(igrp_vektor_tree, hf_igrp_delay, tvb, 3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(igrp_vektor_tree, hf_igrp_bandwidth, tvb, 6, 3, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(igrp_vektor_tree, hf_igrp_mtu, tvb, 9, 2, tvb_get_ntohs(tvb,9), "%d bytes", tvb_get_ntohs(tvb,9));
proto_tree_add_item(igrp_vektor_tree, hf_igrp_reliability, tvb, 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(igrp_vektor_tree, hf_igrp_load, tvb, 12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(igrp_vektor_tree, hf_igrp_hop_count, tvb, 13, 1, ENC_BIG_ENDIAN);
}
void proto_register_igrp(void)
{
static hf_register_info hf[] = {
{ &hf_igrp_update,
{ "Update Release", "igrp.update",
FT_UINT8, BASE_DEC, NULL, 0x0 ,
"Update Release number", HFILL }
},
{ &hf_igrp_as,
{ "Autonomous System", "igrp.as",
FT_UINT16, BASE_DEC, NULL, 0x0 ,
"Autonomous System number", HFILL }
},
{ &hf_igrp_version, { "IGRP Version", "igrp.version", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }},
{ &hf_igrp_command, { "Command", "igrp.command", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{ &hf_igrp_interior_routes, { "Interior routes", "igrp.interior_routes", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_igrp_system_routes, { "System routes", "igrp.system_routes", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_igrp_exterior_routes, { "Exterior routes", "igrp.exterior_routes", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_igrp_checksum, { "Checksum", "igrp.checksum", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_igrp_network, { "Network", "igrp.network", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_igrp_delay, { "Delay", "igrp.delay", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_igrp_bandwidth, { "Bandwidth", "igrp.bandwidth", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_igrp_mtu, { "MTU", "igrp.mtu", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_igrp_reliability, { "Reliability", "igrp.reliability", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_igrp_load, { "Load", "igrp.load", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_igrp_hop_count, { "Hop count", "igrp.hop_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_igrp,
&ett_igrp_vektor,
&ett_igrp_net
};
static ei_register_info ei[] = {
{ &ei_igrp_version, { "igrp.version.invalid", PI_PROTOCOL, PI_WARN, "Unknown Version, The dissection may be inaccurate", EXPFILL }},
};
expert_module_t* expert_igrp;
proto_igrp = proto_register_protocol("Cisco Interior Gateway Routing Protocol",
"IGRP", "igrp");
proto_register_field_array(proto_igrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_igrp = expert_register_protocol(proto_igrp);
expert_register_field_array(expert_igrp, ei, array_length(ei));
}
void
proto_reg_handoff_igrp(void)
{
dissector_handle_t igrp_handle;
igrp_handle = create_dissector_handle(dissect_igrp, proto_igrp);
dissector_add_uint("ip.proto", IP_PROTO_IGRP, igrp_handle);
}
