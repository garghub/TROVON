static void
esis_dissect_unknown( tvbuff_t *tvb, proto_tree *tree, const char *fmat, ...){
va_list ap;
va_start(ap, fmat);
proto_tree_add_text_valist(tree, tvb, 0, -1, fmat, ap);
va_end(ap);
}
static void
esis_dissect_esh_pdu( guint8 len, tvbuff_t *tvb, proto_tree *tree) {
proto_tree *esis_area_tree;
int offset = 0;
int no_sa = 0;
int sal = 0;
proto_item *ti;
if (tree) {
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
proto_tree_add_text(esis_area_tree, tvb, offset, sal,
" SA: %s",
print_nsap_net( tvb_get_ptr(tvb, offset, sal), sal ) );
offset += sal;
len -= ( sal + 1 );
}
dissect_osi_options( len, tvb, offset, tree );
}
}
static void
esis_dissect_ish_pdu( guint8 len, tvbuff_t *tvb, proto_tree *tree) {
int offset = 0;
int netl = 0;
if (tree) {
offset += ESIS_HDR_FIXED_LENGTH;
netl = (int) tvb_get_guint8(tvb, offset);
proto_tree_add_text( tree, tvb, offset, netl + 1,
"### Network Entity Title Section ###");
proto_tree_add_uint_format_value(tree, hf_esis_netl, tvb, offset++, 1, netl, "%2u Octets", netl);
proto_tree_add_text( tree, tvb, offset, netl,
" NET: %s",
print_nsap_net( tvb_get_ptr(tvb, offset, netl), netl ) );
offset += netl;
len -= ( netl + 1 );
dissect_osi_options( len, tvb, offset, tree );
}
}
static void
esis_dissect_redirect_pdu( guint8 len, tvbuff_t *tvb, proto_tree *tree) {
int offset = 0;
int tmpl = 0;
if (tree) {
offset += ESIS_HDR_FIXED_LENGTH;
tmpl = (int) tvb_get_guint8(tvb, offset);
proto_tree_add_text( tree, tvb, offset, tmpl + 1,
"### Destination Address Section ###" );
proto_tree_add_uint_format_value(tree, hf_esis_dal, tvb, offset++, 1, tmpl, "%2u Octets", tmpl);
proto_tree_add_text( tree, tvb, offset, tmpl,
" DA : %s",
print_nsap_net( tvb_get_ptr(tvb, offset, tmpl), tmpl ) );
offset += tmpl;
len -= ( tmpl + 1 );
tmpl = (int) tvb_get_guint8(tvb, offset);
proto_tree_add_text( tree, tvb, offset, tmpl + 1,
"### Subnetwork Address Section ###");
proto_tree_add_uint_format_value(tree, hf_esis_bsnpal, tvb, offset++, 1, tmpl, "%2u Octets", tmpl);
proto_tree_add_text( tree, tvb, offset, tmpl,
" BSNPA: %s",
print_system_id( tvb_get_ptr(tvb, offset, tmpl), tmpl ) );
offset += tmpl;
len -= ( tmpl + 1 );
tmpl = (int) tvb_get_guint8(tvb, offset);
if ( 0 == tmpl ) {
proto_tree_add_text( tree, tvb, offset, 1,
"### No Network Entity Title Section ###" );
offset++;
len--;
}
else {
proto_tree_add_text( tree, tvb, offset, 1,
"### Network Entity Title Section ###" );
proto_tree_add_uint_format_value(tree, hf_esis_netl, tvb, offset++, 1, tmpl, "%2u Octets", tmpl );
proto_tree_add_text( tree, tvb, offset, tmpl,
" NET: %s",
print_nsap_net( tvb_get_ptr(tvb, offset, tmpl), tmpl ) );
offset += tmpl;
len -= ( tmpl + 1 );
}
dissect_osi_options( len, tvb, offset, tree );
}
}
static void
dissect_esis(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
const char *pdu_type_string = NULL;
const char *pdu_type_format_string = "PDU Type : %s (R:%s%s%s)";
esis_hdr_t ehdr;
proto_item *ti;
proto_tree *esis_tree = NULL;
guint8 variable_len;
guint tmp_uint = 0;
const char *cksum_status;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ESIS");
col_clear(pinfo->cinfo, COL_INFO);
tvb_memcpy(tvb, (guint8 *)&ehdr, 0, sizeof ehdr);
if (tree) {
ti = proto_tree_add_item(tree, proto_esis, tvb, 0, -1, ENC_NA);
esis_tree = proto_item_add_subtree(ti, ett_esis);
if (ehdr.esis_version != ESIS_REQUIRED_VERSION){
esis_dissect_unknown(tvb, esis_tree,
"Unknown ESIS version (%u vs %u)",
ehdr.esis_version, ESIS_REQUIRED_VERSION );
return;
}
if (ehdr.esis_length < ESIS_HDR_FIXED_LENGTH) {
esis_dissect_unknown(tvb, esis_tree,
"Bogus ESIS length (%u, must be >= %u)",
ehdr.esis_length, ESIS_HDR_FIXED_LENGTH );
return;
}
proto_tree_add_uint( esis_tree, hf_esis_nlpi, tvb, 0, 1, ehdr.esis_nlpi );
proto_tree_add_uint( esis_tree, hf_esis_length, tvb,
1, 1, ehdr.esis_length );
proto_tree_add_uint( esis_tree, hf_esis_version, tvb, 2, 1,
ehdr.esis_version );
proto_tree_add_uint( esis_tree, hf_esis_reserved, tvb, 3, 1,
ehdr.esis_reserved );
pdu_type_string = val_to_str(ehdr.esis_type&OSI_PDU_TYPE_MASK,
esis_vals, "Unknown (0x%x)");
proto_tree_add_uint_format( esis_tree, hf_esis_type, tvb, 4, 1,
ehdr.esis_type,
pdu_type_format_string,
pdu_type_string,
(ehdr.esis_type&BIT_8) ? "1" : "0",
(ehdr.esis_type&BIT_7) ? "1" : "0",
(ehdr.esis_type&BIT_6) ? "1" : "0");
tmp_uint = pntohs( ehdr.esis_holdtime );
proto_tree_add_uint_format_value(esis_tree, hf_esis_holdtime, tvb, 5, 2,
tmp_uint, "%u seconds",
tmp_uint );
tmp_uint = pntohs( ehdr.esis_checksum );
switch (calc_checksum( tvb, 0, ehdr.esis_length, tmp_uint )) {
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
tmp_uint, "0x%x ( %s )",
tmp_uint, cksum_status );
}
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str( ehdr.esis_type&OSI_PDU_TYPE_MASK, esis_vals,
"Unknown (0x%x)" ) );
variable_len = ehdr.esis_length - ESIS_HDR_FIXED_LENGTH;
switch (ehdr.esis_type & OSI_PDU_TYPE_MASK) {
case ESIS_ESH_PDU:
esis_dissect_esh_pdu( variable_len, tvb, esis_tree);
break;
case ESIS_ISH_PDU:
esis_dissect_ish_pdu( variable_len, tvb, esis_tree);
break;
case ESIS_RD_PDU:
esis_dissect_redirect_pdu( variable_len, tvb, esis_tree);
break;
default:
esis_dissect_unknown(tvb, esis_tree,
"Unknown ESIS packet type 0x%x",
ehdr.esis_type & OSI_PDU_TYPE_MASK );
}
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
{ "Version (==1)", "esis.ver", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_reserved,
{ "Reserved(==0)", "esis.res", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_type,
{ "PDU Type", "esis.type", FT_UINT8, BASE_DEC, VALS(esis_vals), 0xff, NULL, HFILL }},
{ &hf_esis_holdtime,
{ "Holding Time", "esis.htime", FT_UINT16, BASE_DEC, NULL, 0x0, "s", HFILL }},
{ &hf_esis_checksum,
{ "Checksum", "esis.chksum", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_number_of_source_addresses, { "Number of Source Addresses (SA, Format: NSAP)", "esis.number_of_source_addresses", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_sal, { "SAL", "esis.sal", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_netl, { "NETL", "esis.netl", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_dal, { "DAL", "esis.dal", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_esis_bsnpal, { "BSNPAL", "esis.bsnpal", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_esis,
&ett_esis_area_addr,
};
proto_esis = proto_register_protocol( PROTO_STRING_ESIS, "ESIS", "esis");
proto_register_field_array(proto_esis, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("esis", dissect_esis, proto_esis);
}
void
proto_reg_handoff_esis(void)
{
dissector_handle_t esis_handle;
esis_handle = find_dissector("esis");
dissector_add_uint("osinl.incl", NLPID_ISO9542_ESIS, esis_handle);
}
