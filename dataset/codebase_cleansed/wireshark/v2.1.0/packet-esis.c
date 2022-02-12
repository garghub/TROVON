static void
esis_dissect_esh_pdu( guint8 len, tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo) {
proto_tree *esis_area_tree;
int offset = 0;
int no_sa = 0;
int sal = 0;
proto_item *ti;
offset += ESIS_HDR_FIXED_LENGTH;
no_sa = tvb_get_guint8(tvb, offset);
len -= 1;
ti = proto_tree_add_uint( tree, hf_esis_number_of_source_addresses, tvb, offset, 1, no_sa);
offset++;
esis_area_tree = proto_item_add_subtree( ti, ett_esis_area_addr );
while ( no_sa-- > 0 ) {
sal = (int) tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(esis_area_tree, hf_esis_sal, tvb, offset, 1, sal, "%2u Octets", sal);
offset++;
proto_tree_add_string(esis_area_tree, hf_esis_sa, tvb, offset, sal, print_nsap_net(tvb, offset, sal ) );
offset += sal;
len -= ( sal + 1 );
}
dissect_osi_options( len, tvb, offset, tree, pinfo );
}
static void
esis_dissect_ish_pdu( guint8 len, tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo) {
int offset = 0;
int netl = 0;
proto_tree* network_tree;
offset += ESIS_HDR_FIXED_LENGTH;
netl = (int) tvb_get_guint8(tvb, offset);
network_tree = proto_tree_add_subtree( tree, tvb, offset, netl + 1, ett_esis_network, NULL,
"### Network Entity Title Section ###");
proto_tree_add_uint_format_value(network_tree, hf_esis_netl, tvb, offset++, 1, netl, "%2u Octets", netl);
proto_tree_add_string(network_tree, hf_esis_net, tvb, offset, netl, print_nsap_net( tvb, offset, netl ) );
offset += netl;
len -= ( netl + 1 );
dissect_osi_options( len, tvb, offset, network_tree, pinfo );
}
static void
esis_dissect_redirect_pdu( guint8 len, tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo) {
int offset = 0;
int tmpl = 0;
proto_tree *dest_tree, *subnet_tree, *network_tree;
offset += ESIS_HDR_FIXED_LENGTH;
tmpl = (int) tvb_get_guint8(tvb, offset);
dest_tree = proto_tree_add_subtree( tree, tvb, offset, tmpl + 1, ett_esis_dest_addr, NULL,
"### Destination Address Section ###" );
proto_tree_add_uint_format_value(dest_tree, hf_esis_dal, tvb, offset++, 1, tmpl, "%2u Octets", tmpl);
proto_tree_add_string( dest_tree, hf_esis_da, tvb, offset, tmpl,
print_nsap_net( tvb, offset, tmpl ) );
offset += tmpl;
len -= ( tmpl + 1 );
tmpl = (int) tvb_get_guint8(tvb, offset);
subnet_tree = proto_tree_add_subtree( tree, tvb, offset, tmpl + 1, ett_esis_subnetwork, NULL,
"### Subnetwork Address Section ###");
proto_tree_add_uint_format_value(subnet_tree, hf_esis_bsnpal, tvb, offset++, 1, tmpl, "%2u Octets", tmpl);
proto_tree_add_item(subnet_tree, hf_esis_bsnpa, tvb, offset, tmpl, ENC_NA);
offset += tmpl;
len -= ( tmpl + 1 );
tmpl = (int) tvb_get_guint8(tvb, offset);
if ( 0 == tmpl ) {
network_tree = proto_tree_add_subtree( tree, tvb, offset, 1, ett_esis_network, NULL,
"### No Network Entity Title Section ###" );
offset++;
len--;
}
else {
network_tree = proto_tree_add_subtree( tree, tvb, offset, 1, ett_esis_network, NULL,
"### Network Entity Title Section ###" );
proto_tree_add_uint_format_value(network_tree, hf_esis_netl, tvb, offset++, 1, tmpl, "%2u Octets", tmpl );
proto_tree_add_string( network_tree, hf_esis_net, tvb, offset, tmpl,
print_nsap_net( tvb, offset, tmpl ) );
offset += tmpl;
len -= ( tmpl + 1 );
}
dissect_osi_options( len, tvb, offset, network_tree, pinfo );
}
static int
dissect_esis(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
guint8 version, length;
proto_item *ti, *type_item;
proto_tree *esis_tree = NULL;
guint8 variable_len, type;
guint16 holdtime, checksum;
const char *cksum_status;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ESIS");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_esis, tvb, 0, -1, ENC_NA);
esis_tree = proto_item_add_subtree(ti, ett_esis);
proto_tree_add_item( esis_tree, hf_esis_nlpi, tvb, 0, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item( esis_tree, hf_esis_length, tvb, 1, 1, ENC_BIG_ENDIAN );
length = tvb_get_guint8(tvb, 1);
if (length < ESIS_HDR_FIXED_LENGTH) {
expert_add_info_format(pinfo, ti, &ei_esis_length,
"Bogus ESIS length (%u, must be >= %u)",
length, ESIS_HDR_FIXED_LENGTH );
}
version = tvb_get_guint8(tvb, 2);
ti = proto_tree_add_item( esis_tree, hf_esis_version, tvb, 2, 1, ENC_BIG_ENDIAN);
if (version != ESIS_REQUIRED_VERSION){
expert_add_info_format(pinfo, ti, &ei_esis_version,
"Unknown ESIS version (%u vs %u)",
version, ESIS_REQUIRED_VERSION );
}
proto_tree_add_item( esis_tree, hf_esis_reserved, tvb, 3, 1, ENC_BIG_ENDIAN);
type_item = proto_tree_add_item( esis_tree, hf_esis_type, tvb, 4, 1, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb, 4) & OSI_PDU_TYPE_MASK;
holdtime = tvb_get_ntohs(tvb, 5);
proto_tree_add_uint_format_value(esis_tree, hf_esis_holdtime, tvb, 5, 2,
holdtime, "%u seconds", holdtime);
checksum = tvb_get_ntohs(tvb, 7);
switch (calc_checksum( tvb, 0, length, checksum)) {
case NO_CKSUM:
cksum_status = "Not Used";
break;
case DATA_MISSING:
cksum_status = "Not checkable - not all of packet was captured";
break;
case CKSUM_OK:
cksum_status = "Is good";
break;
case CKSUM_NOT_OK:
cksum_status = "Is wrong";
break;
default:
cksum_status = NULL;
DISSECTOR_ASSERT_NOT_REACHED();
}
proto_tree_add_uint_format_value( esis_tree, hf_esis_checksum, tvb, 7, 2,
checksum, "0x%x ( %s )", checksum, cksum_status );
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str( type, esis_vals,
"Unknown (0x%x)" ) );
variable_len = length - ESIS_HDR_FIXED_LENGTH;
switch (type) {
case ESIS_ESH_PDU:
esis_dissect_esh_pdu( variable_len, tvb, esis_tree, pinfo);
break;
case ESIS_ISH_PDU:
esis_dissect_ish_pdu( variable_len, tvb, esis_tree, pinfo);
break;
case ESIS_RD_PDU:
esis_dissect_redirect_pdu( variable_len, tvb, esis_tree, pinfo);
break;
default:
expert_add_info(pinfo, type_item, &ei_esis_type);
}
return tvb_captured_length(tvb);
}
void
proto_register_esis(void) {
static hf_register_info hf[] = {
{ &hf_esis_nlpi,
{ "Network Layer Protocol Identifier", "esis.nlpi",
FT_UINT8, BASE_HEX, VALS(nlpid_vals), 0x0, NULL, HFILL }},
{ &hf_esis_length,
{ "PDU Length", "esis.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_version,
{ "Version", "esis.ver", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_reserved,
{ "Reserved(==0)", "esis.res", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_type,
{ "PDU Type", "esis.type", FT_UINT8, BASE_DEC, VALS(esis_vals), OSI_PDU_TYPE_MASK, NULL, HFILL }},
{ &hf_esis_holdtime,
{ "Holding Time", "esis.htime", FT_UINT16, BASE_DEC, NULL, 0x0, "s", HFILL }},
{ &hf_esis_checksum,
{ "Checksum", "esis.chksum", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_number_of_source_addresses, { "Number of Source Addresses (SA, Format: NSAP)", "esis.number_of_source_addresses", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_sal, { "SAL", "esis.sal", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_sa, { "SA", "esis.sa", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_netl, { "NETL", "esis.netl", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_dal, { "DAL", "esis.dal", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_bsnpal, { "BSNPAL", "esis.bsnpal", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_net, { "NET", "esis.net", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_da, { "DA", "esis.da", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_bsnpa, { "BSNPA", "esis.bsnpa", FT_SYSTEM_ID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_esis,
&ett_esis_area_addr,
&ett_esis_network,
&ett_esis_dest_addr,
&ett_esis_subnetwork
};
static ei_register_info ei[] = {
{ &ei_esis_version, { "esis.ver.unknown", PI_PROTOCOL, PI_WARN, "Unknown ESIS version", EXPFILL }},
{ &ei_esis_length, { "esis.length.invalid", PI_MALFORMED, PI_ERROR, "Bogus ESIS length", EXPFILL }},
{ &ei_esis_type, { "esis.type.unknown", PI_PROTOCOL, PI_WARN, "Unknown ESIS packet type", EXPFILL }},
};
expert_module_t* expert_esis;
proto_esis = proto_register_protocol( PROTO_STRING_ESIS, "ESIS", "esis");
proto_register_field_array(proto_esis, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_esis = expert_register_protocol(proto_esis);
expert_register_field_array(expert_esis, ei, array_length(ei));
register_dissector("esis", dissect_esis, proto_esis);
}
void
proto_reg_handoff_esis(void)
{
dissector_handle_t esis_handle;
esis_handle = find_dissector("esis");
dissector_add_uint("osinl.incl", NLPID_ISO9542_ESIS, esis_handle);
}
