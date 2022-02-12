static void dissect_ccsrl(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *ccsrl_item;
proto_tree *ccsrl_tree=NULL;
guint8 lastseg = tvb_get_guint8(tvb,0);
tvbuff_t *next_tvb;
if (tree) {
ccsrl_item = proto_tree_add_item (tree, proto_ccsrl, tvb, 0, -1, ENC_NA);
ccsrl_tree = proto_item_add_subtree (ccsrl_item, ett_ccsrl);
proto_tree_add_uint(ccsrl_tree,hf_ccsrl_ls,tvb,0,1,lastseg);
}
next_tvb = tvb_new_subset_remaining(tvb, 1);
call_dissector( h245dg_handle, next_tvb, pinfo, ccsrl_tree );
}
static void dissect_srp_command(tvbuff_t * tvb, packet_info * pinfo, proto_tree * srp_tree)
{
tvbuff_t *next_tvb;
guint payload_len;
if( srp_tree )
proto_tree_add_item(srp_tree,hf_srp_seqno,tvb,1,1,ENC_BIG_ENDIAN);
payload_len = tvb_reported_length_remaining(tvb,4);
next_tvb = tvb_new_subset_length(tvb, 2, payload_len);
call_dissector(ccsrl_handle, next_tvb, pinfo, srp_tree );
}
static void dissect_srp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *srp_item = NULL;
proto_tree *srp_tree = NULL;
proto_item *hidden_item;
guint8 header = tvb_get_guint8(tvb,0);
if (tree) {
srp_item = proto_tree_add_item (tree, proto_srp, tvb, 0, -1, ENC_NA);
srp_tree = proto_item_add_subtree (srp_item, ett_srp);
proto_tree_add_uint(srp_tree,hf_srp_header,tvb,0,1,header);
}
switch( header ) {
case SRP_SRP_COMMAND:
dissect_srp_command(tvb,pinfo,srp_tree);
break;
case SRP_SRP_RESPONSE:
break;
case SRP_NSRP_RESPONSE:
if( srp_tree )
proto_tree_add_item(srp_tree,hf_srp_seqno,tvb,1,1,ENC_BIG_ENDIAN);
break;
default:
break;
}
if( srp_tree ) {
guint16 crc, calc_crc;
guint crc_offset = tvb_reported_length(tvb)-2;
crc = tvb_get_letohs(tvb,-2);
calc_crc = crc16_ccitt_tvb(tvb,crc_offset);
if( crc == calc_crc ) {
proto_tree_add_uint_format_value(srp_tree, hf_srp_crc, tvb,
crc_offset, 2, crc,
"0x%04x (correct)", crc);
} else {
hidden_item = proto_tree_add_boolean(srp_tree, hf_srp_crc_bad, tvb,
crc_offset, 2, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint_format_value(srp_tree, hf_srp_crc, tvb,
crc_offset, 2, crc,
"0x%04x (incorrect, should be 0x%04x)",
crc,
calc_crc);
}
}
}
void proto_register_ccsrl (void)
{
static hf_register_info hf[] = {
{ &hf_ccsrl_ls,
{ "Last Segment","ccsrl.ls",FT_UINT8, BASE_HEX, VALS(ccsrl_ls_vals), 0x0,
"Last segment indicator", HFILL}},
};
static gint *ett[] = {
&ett_ccsrl,
};
proto_ccsrl = proto_register_protocol ("H.324/CCSRL", "CCSRL", "ccsrl");
proto_register_field_array (proto_ccsrl, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector("ccsrl", dissect_ccsrl, proto_ccsrl);
}
void proto_register_srp (void)
{
static hf_register_info hf[] = {
{&hf_srp_header,
{ "Header", "srp.header", FT_UINT8, BASE_DEC, VALS(srp_frame_types), 0x0,
"SRP header octet", HFILL }},
{&hf_srp_seqno,
{ "Sequence Number", "srp.seqno", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_srp_crc,
{ "CRC", "srp.crc", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_srp_crc_bad,
{ "Bad CRC","srp.crc_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_srp,
};
proto_srp = proto_register_protocol ("H.324/SRP", "SRP", "srp");
proto_register_field_array (proto_srp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector("srp", dissect_srp, proto_srp);
}
void proto_reg_handoff_srp(void) {
ccsrl_handle = find_dissector("ccsrl");
h245dg_handle = find_dissector("h245dg");
}
