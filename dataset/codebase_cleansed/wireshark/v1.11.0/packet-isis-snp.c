static void
dissect_snp_lsp_entries_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length, int length)
{
proto_tree *subtree,*ti;
while ( length > 0 ) {
if ( length < 2+id_length+2+4+2 ) {
isis_dissect_unknown(tvb, tree, offset,
"Short SNP header entry (%d vs %d)", length,
2+id_length+2+4+2 );
return;
}
ti = proto_tree_add_text(tree, tvb, offset, 2+id_length+2+4+2,
"LSP-ID: %s, Sequence: 0x%08x, Lifetime: %5us, Checksum: 0x%04x",
print_system_id( tvb_get_ptr(tvb, offset+2, id_length+2), id_length+2 ),
tvb_get_ntohl(tvb, offset+2+id_length+2),
tvb_get_ntohs(tvb, offset),
tvb_get_ntohs(tvb, offset+2+id_length+2+4));
subtree = proto_item_add_subtree(ti,ett_isis_csnp_lsp_entry);
proto_tree_add_text(subtree, tvb, offset+2, 8,
"LSP-ID: : %s",
print_system_id( tvb_get_ptr(tvb, offset+2, id_length+2), id_length+2 ));
proto_tree_add_text(subtree, tvb, offset+2+id_length+2, 4,
"LSP Sequence Number : 0x%08x",
tvb_get_ntohl(tvb, offset+2+id_length+2));
proto_tree_add_text(subtree, tvb, offset, 2,
"Remaining Lifetime : %us",
tvb_get_ntohs(tvb, offset));
proto_tree_add_text(subtree, tvb, offset+2+id_length+2+4, 2,
"LSP checksum : 0x%04x",
tvb_get_ntohs(tvb, offset+2+id_length+2+4));
length -= 2+id_length+2+4+2;
offset += 2+id_length+2+4+2;
}
}
void
isis_dissect_isis_csnp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
int type, int header_length, int id_length)
{
proto_item *ti;
proto_tree *csnp_tree = NULL;
guint16 pdu_length;
int len;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, -1,
PROTO_STRING_CSNP);
csnp_tree = proto_item_add_subtree(ti, ett_isis_csnp);
}
pdu_length = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(csnp_tree, hf_isis_csnp_pdu_length, tvb,
offset, 2, pdu_length);
}
offset += 2;
if (tree) {
proto_tree_add_text(csnp_tree, tvb, offset, id_length + 1,
"Source-ID: %s",
print_system_id( tvb_get_ptr(tvb, offset, id_length+1), id_length+1 ) );
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Source-ID: %s",
print_system_id( tvb_get_ptr(tvb, offset, id_length+1), id_length+1 ) );
offset += id_length + 1;
proto_tree_add_text(csnp_tree, tvb, offset, id_length + 2, "Start LSP-ID: %s",
print_system_id( tvb_get_ptr(tvb, offset, id_length+2), id_length+2 ) );
col_append_fstr(pinfo->cinfo, COL_INFO, ", Start LSP-ID: %s",
print_system_id( tvb_get_ptr(tvb, offset, id_length+2), id_length+2 ) );
offset += id_length + 2;
proto_tree_add_text(csnp_tree, tvb, offset, id_length + 2, "End LSP-ID: %s",
print_system_id( tvb_get_ptr(tvb, offset, id_length+2), id_length+2 ) );
col_append_fstr(pinfo->cinfo, COL_INFO, ", End LSP-ID: %s",
print_system_id( tvb_get_ptr(tvb, offset, id_length+2), id_length+2 ) );
offset += id_length + 2;
len = pdu_length - header_length;
if (len < 0) {
return;
}
if (type == ISIS_TYPE_L1_CSNP ) {
isis_dissect_clvs(tvb, csnp_tree, offset,
clv_l1_csnp_opts, len, id_length,
ett_isis_csnp_clv_unknown );
} else {
isis_dissect_clvs(tvb, csnp_tree, offset,
clv_l2_csnp_opts, len, id_length,
ett_isis_csnp_clv_unknown );
}
}
void
isis_dissect_isis_psnp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
int type, int header_length, int id_length)
{
proto_item *ti;
proto_tree *psnp_tree = NULL;
guint16 pdu_length;
int len;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, -1,
PROTO_STRING_PSNP);
psnp_tree = proto_item_add_subtree(ti, ett_isis_psnp);
}
pdu_length = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(psnp_tree, hf_isis_psnp_pdu_length, tvb,
offset, 2, pdu_length);
}
offset += 2;
proto_tree_add_text(psnp_tree, tvb, offset, id_length + 1, "Source-ID: %s",
print_system_id( tvb_get_ptr(tvb, offset, id_length+1), id_length + 1 ) );
col_append_fstr(pinfo->cinfo, COL_INFO, ", Source-ID: %s",
print_system_id( tvb_get_ptr(tvb, offset, id_length+1), id_length+1 ) );
offset += id_length + 1;
len = pdu_length - header_length;
if (len < 0) {
isis_dissect_unknown(tvb, tree, offset,
"packet header length %d went beyond packet",
header_length );
return;
}
if (type == ISIS_TYPE_L1_PSNP ) {
isis_dissect_clvs(tvb, psnp_tree, offset,
clv_l1_psnp_opts, len, id_length,
ett_isis_psnp_clv_unknown );
} else {
isis_dissect_clvs(tvb, psnp_tree, offset,
clv_l2_psnp_opts, len, id_length,
ett_isis_psnp_clv_unknown );
}
}
static void
dissect_snp_authentication_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_authentication_clv(tvb, tree, offset, length);
}
static void
dissect_snp_ip_authentication_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
isis_dissect_ip_authentication_clv(tvb, tree, offset, length);
}
static void
dissect_snp_checksum_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length) {
guint16 pdu_length,checksum, cacl_checksum=0;
if (tree) {
if ( length != 2 ) {
proto_tree_add_text ( tree, tvb, offset, length,
"incorrect checksum length (%u), should be (2)", length );
return;
}
checksum = tvb_get_ntohs(tvb, offset);
pdu_length = tvb_get_ntohs(tvb, 8);
switch (check_and_get_checksum(tvb, 0, pdu_length, checksum, offset, &cacl_checksum))
{
case NO_CKSUM :
proto_tree_add_text ( tree, tvb, offset, length,
"Checksum: 0x%04x [unused]", checksum);
break;
case DATA_MISSING :
isis_dissect_unknown(tvb, tree, offset,
"[packet length %d went beyond packet]",
tvb_length(tvb));
break;
case CKSUM_NOT_OK :
proto_tree_add_text ( tree, tvb, offset, length,
"Checksum: 0x%04x [incorrect, should be 0x%04x]",
checksum,
cacl_checksum);
break;
case CKSUM_OK :
proto_tree_add_text ( tree, tvb, offset, length,
"Checksum: 0x%04x [correct]", checksum);
break;
default :
g_message("'check_and_get_checksum' returned an invalid value");
}
}
}
void
isis_register_csnp(int proto_isis) {
static hf_register_info hf[] = {
{ &hf_isis_csnp_pdu_length,
{ "PDU length", "isis.csnp.pdu_length", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_isis_csnp,
&ett_isis_csnp_clv_lsp_entries,
&ett_isis_csnp_lsp_entry,
&ett_isis_csnp_clv_authentication,
&ett_isis_csnp_clv_ip_authentication,
&ett_isis_csnp_clv_checksum,
&ett_isis_csnp_clv_unknown,
};
proto_register_field_array(proto_isis, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
isis_register_psnp(int proto_isis) {
static hf_register_info hf[] = {
{ &hf_isis_psnp_pdu_length,
{ "PDU length", "isis.psnp.pdu_length", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_isis_psnp,
&ett_isis_psnp_clv_lsp_entries,
&ett_isis_psnp_lsp_entry,
&ett_isis_psnp_clv_authentication,
&ett_isis_psnp_clv_ip_authentication,
&ett_isis_psnp_clv_checksum,
&ett_isis_psnp_clv_unknown,
};
proto_register_field_array(proto_isis, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
