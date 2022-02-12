static
void dissect_pw_cesopsn( tvbuff_t * tvb_original
,packet_info * pinfo
,proto_tree * tree
,pwc_demux_type_t demux)
{
const int encaps_size = 4;
gint packet_size;
gint payload_size;
gint padding_size;
int properties;
packet_size = tvb_reported_length_remaining(tvb_original, 0);
if (packet_size < 4)
{
proto_item *item;
item = proto_tree_add_item(tree, proto, tvb_original, 0, -1, ENC_NA);
expert_add_info_format(pinfo, item, &ei_packet_size_too_small,
"PW packet size (%d) is too small to carry sensible information"
,(int)packet_size);
col_set_str(pinfo->cinfo, COL_PROTOCOL, shortname);
col_set_str(pinfo->cinfo, COL_INFO, "Malformed: PW packet is too small");
return;
}
switch (demux)
{
case PWC_DEMUX_MPLS:
if (dissect_try_cw_first_nibble(tvb_original, pinfo, tree))
{
return;
}
break;
case PWC_DEMUX_UDP:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return;
}
properties = PWC_PACKET_PROPERTIES_T_INITIALIZER;
if (0 != (tvb_get_guint8(tvb_original, 0) & 0xf0 ))
{
properties |= PWC_CW_BAD_BITS03;
}
if (0 != (tvb_get_guint8(tvb_original, 1) & 0xc0 ))
{
properties |= PWC_CW_BAD_FRAG;
}
{
int cw_len;
gint payload_size_from_packet;
cw_len = tvb_get_guint8(tvb_original, 1) & 0x3f;
payload_size_from_packet = packet_size - encaps_size;
if (cw_len != 0)
{
gint payload_size_from_cw;
payload_size_from_cw = cw_len - encaps_size;
payload_size = payload_size_from_packet;
padding_size = 0;
if (payload_size_from_cw < 0)
{
properties |= PWC_CW_BAD_PAYLEN_LT_0;
}
else if (payload_size_from_cw > payload_size_from_packet)
{
properties |= PWC_CW_BAD_PAYLEN_GT_PACKET;
}
else if (payload_size_from_packet >= 64)
{
properties |= PWC_CW_BAD_LEN_MUST_BE_0;
}
else
{
payload_size = payload_size_from_cw;
padding_size = payload_size_from_packet - payload_size_from_cw;
}
}
else
{
payload_size = payload_size_from_packet;
padding_size = 0;
}
}
{
guint8 cw_lm;
cw_lm = tvb_get_guint8(tvb_original, 0) & 0x0b ;
if (NULL == try_val_to_str(cw_lm, vals_cw_lm))
{
properties |= PWC_CW_SUSPECT_LM;
}
{
guint8 l_bit, m_bits;
l_bit = (cw_lm & 0x08) >> 3;
m_bits = (cw_lm & 0x03) >> 0;
if ((l_bit == 0 && m_bits == 0x0)
||(l_bit == 0 && m_bits == 0x2) )
{
if ((payload_size == 0) || ((payload_size % 8) != 0))
{
properties |= PWC_PAY_SIZE_BAD;
}
}
else if (l_bit == 1 && m_bits == 0x0)
{
}
else
{
}
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, shortname);
col_clear(pinfo->cinfo, COL_INFO);
if (properties & PWC_ANYOF_CW_BAD)
{
col_append_str(pinfo->cinfo, COL_INFO, "CW:Bad, ");
}
else if (properties & PWC_ANYOF_CW_SUSPECT)
{
col_append_str(pinfo->cinfo, COL_INFO, "CW:Suspect, ");
}
if (properties & PWC_PAY_SIZE_BAD)
{
col_append_str(pinfo->cinfo, COL_INFO, "Payload size:Bad, ");
}
col_append_fstr(pinfo->cinfo, COL_INFO, "TDM octets:%d", (int)payload_size);
if (padding_size != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ", Padding:%d", (int)padding_size);
}
{
proto_item* item;
item = proto_tree_add_item(tree, proto, tvb_original, 0, -1, ENC_NA);
pwc_item_append_cw(item,tvb_get_ntohl(tvb_original, 0),TRUE);
pwc_item_append_text_n_items(item,(int)payload_size,"octet");
{
proto_tree* tree2;
tree2 = proto_item_add_subtree(item, ett);
{
tvbuff_t* tvb;
proto_item* item2;
tvb = tvb_new_subset(tvb_original, 0, PWC_SIZEOF_CW, PWC_SIZEOF_CW);
item2 = proto_tree_add_item(tree2, hf_cw, tvb, 0, -1, ENC_NA);
pwc_item_append_cw(item2,tvb_get_ntohl(tvb, 0),FALSE);
{
proto_tree* tree3;
tree3 = proto_item_add_subtree(item, ett);
{
proto_item* item3;
if (properties & PWC_CW_BAD_BITS03)
{
item3 = proto_tree_add_item(tree3, hf_cw_bits03, tvb, 0, 1, ENC_BIG_ENDIAN);
expert_add_info(pinfo, item3, &ei_cw_bits03);
}
item3 = proto_tree_add_item(tree3, hf_cw_lm, tvb, 0, 1, ENC_BIG_ENDIAN);
if (properties & PWC_CW_SUSPECT_LM)
{
expert_add_info(pinfo, item3, &ei_cw_lm);
}
proto_tree_add_item(tree3, hf_cw_r, tvb, 0, 1, ENC_BIG_ENDIAN);
item3 = proto_tree_add_item(tree3, hf_cw_frg, tvb, 1, 1, ENC_BIG_ENDIAN);
if (properties & PWC_CW_BAD_FRAG)
{
expert_add_info(pinfo, item3, &ei_cw_frg);
}
item3 = proto_tree_add_item(tree3, hf_cw_len, tvb, 1, 1, ENC_BIG_ENDIAN);
if (properties & PWC_CW_BAD_PAYLEN_LT_0)
{
expert_add_info_format(pinfo, item3, &ei_pref_cw_len,
"Bad Length: too small, must be > %d",
(int)encaps_size);
}
if (properties & PWC_CW_BAD_PAYLEN_GT_PACKET)
{
expert_add_info_format(pinfo, item3, &ei_pref_cw_len,
"Bad Length: must be <= than PSN packet size (%d)",
(int)packet_size);
}
if (properties & PWC_CW_BAD_LEN_MUST_BE_0)
{
expert_add_info_format(pinfo, item3, &ei_pref_cw_len,
"Bad Length: must be 0 if CESoPSN packet size (%d) is > 64",
(int)packet_size);
}
proto_tree_add_item(tree3, hf_cw_seq, tvb, 2, 2, ENC_BIG_ENDIAN);
}
}
}
}
if (payload_size == 0)
{
if (properties & PWC_PAY_SIZE_BAD)
{
expert_add_info_format(pinfo, item, &ei_payload_size_invalid_error,
"CESoPSN payload: none found. Size of payload must be <> 0");
}
else
{
expert_add_info_format(pinfo, item, &ei_payload_size_invalid_undecoded,
"CESoPSN payload: omitted to conserve bandwidth");
}
}
else
{
proto_tree* tree2;
tree2 = proto_item_add_subtree(item, ett);
{
proto_item* item2;
tvbuff_t* tvb;
tvb = tvb_new_subset(tvb_original, PWC_SIZEOF_CW, payload_size, payload_size);
item2 = proto_tree_add_item(tree2, hf_payload, tvb, 0, -1, ENC_NA);
pwc_item_append_text_n_items(item2,(int)payload_size,"octet");
if (properties & PWC_PAY_SIZE_BAD)
{
expert_add_info_format(pinfo, item2, &ei_payload_size_invalid_error,
"CESoPSN packet payload size must be multiple of 8");
}
tree2 = proto_item_add_subtree(item2, ett);
call_dissector(data_handle, tvb, pinfo, tree2);
item2 = proto_tree_add_int(tree2, hf_payload_l, tvb, 0, 0
,(int)payload_size);
PROTO_ITEM_SET_HIDDEN(item2);
}
}
if (padding_size > 0)
{
proto_tree* tree2;
tree2 = proto_item_add_subtree(item, ett);
{
tvbuff_t* tvb;
tvb = tvb_new_subset(tvb_original, PWC_SIZEOF_CW + payload_size, padding_size, -1);
call_dissector(pw_padding_handle, tvb, pinfo, tree2);
}
}
}
return;
}
static
void dissect_pw_cesopsn_mpls( tvbuff_t * tvb_original, packet_info * pinfo, proto_tree * tree)
{
dissect_pw_cesopsn(tvb_original,pinfo,tree,PWC_DEMUX_MPLS);
return;
}
static
void dissect_pw_cesopsn_udp( tvbuff_t * tvb_original, packet_info * pinfo, proto_tree * tree)
{
dissect_pw_cesopsn(tvb_original,pinfo,tree,PWC_DEMUX_UDP);
return;
}
void proto_register_pw_cesopsn(void)
{
static hf_register_info hf[] = {
{ &hf_cw ,{"Control Word" ,"pwcesopsn.cw"
,FT_NONE ,BASE_NONE ,NULL
,0 ,NULL ,HFILL }},
{&hf_cw_bits03,{"Bits 0 to 3" ,"pwcesopsn.cw.bits03"
,FT_UINT8 ,BASE_DEC ,NULL
,0xf0 ,NULL ,HFILL }},
{ &hf_cw_lm, {"L+M bits" ,"pwcesopsn.cw.lm"
,FT_UINT8 ,BASE_HEX ,VALS(vals_cw_lm)
,0x0b ,NULL ,HFILL }},
{&hf_cw_r, {"R bit: Local CE-bound IWF" ,"pwcesopsn.cw.rbit"
,FT_UINT8 ,BASE_DEC ,VALS(pwc_vals_cw_r_bit)
,0x04 ,NULL ,HFILL }},
{&hf_cw_frg, {"Fragmentation" ,"pwcesopsn.cw.frag"
,FT_UINT8 ,BASE_DEC ,VALS(pwc_vals_cw_frag)
,0xc0 ,NULL ,HFILL }},
{&hf_cw_len, {"Length" ,"pwcesopsn.cw.length"
,FT_UINT8 ,BASE_DEC ,NULL
,0x3f ,NULL ,HFILL }},
{&hf_cw_seq, {"Sequence number" ,"pwcesopsn.cw.seqno"
,FT_UINT16 ,BASE_DEC ,NULL
,0 ,NULL ,HFILL }},
{&hf_payload ,{"TDM payload" ,"pwcesopsn.payload"
,FT_BYTES ,BASE_NONE ,NULL
,0 ,NULL ,HFILL }},
{&hf_payload_l ,{"TDM payload length" ,"pwcesopsn.payload.len"
,FT_INT32 ,BASE_DEC ,NULL
,0 ,NULL ,HFILL }}
};
static gint *ett_array[] = {
&ett
};
static ei_register_info ei[] = {
{ &ei_packet_size_too_small, { "pwcesopsn.packet_size_too_small", PI_MALFORMED, PI_ERROR, "PW packet size is too small to carry sensible information", EXPFILL }},
{ &ei_cw_bits03, { "pwcesopsn.cw.bits03.not_zero", PI_MALFORMED, PI_ERROR, "Bits 0..3 of Control Word must be 0", EXPFILL }},
{ &ei_cw_lm, { "pwcesopsn.cw.lm.reserved", PI_UNDECODED, PI_WARN, "Reserved combination of L and Modifier bits", EXPFILL }},
{ &ei_cw_frg, { "pwcesopsn.cw.frag.not_allowed", PI_MALFORMED, PI_ERROR, "Fragmentation of payload is not allowed for basic CESoPSN mode", EXPFILL }},
{ &ei_pref_cw_len, { "pwcesopsn.cw.length.invalid", PI_MALFORMED, PI_ERROR, "Bad Length: too small", EXPFILL }},
{ &ei_payload_size_invalid_error, { "pwcesopsn.payload.size_invalid", PI_MALFORMED, PI_ERROR, "CESoPSN payload size invalid", EXPFILL }},
{ &ei_payload_size_invalid_undecoded, { "pwcesopsn.payload.undecoded", PI_UNDECODED, PI_NOTE, "CESoPSN payload: omitted to conserve bandwidth", EXPFILL }},
};
expert_module_t* expert_pwcesopsn;
proto = proto_register_protocol(pwc_longname_pw_cesopsn, shortname, "pwcesopsn");
proto_register_field_array(proto, hf, array_length(hf));
proto_register_subtree_array(ett_array, array_length(ett_array));
expert_pwcesopsn = expert_register_protocol(proto);
expert_register_field_array(expert_pwcesopsn, ei, array_length(ei));
register_dissector("pw_cesopsn_mpls", dissect_pw_cesopsn_mpls, proto);
register_dissector("pw_cesopsn_udp", dissect_pw_cesopsn_udp, proto);
return;
}
void proto_reg_handoff_pw_cesopsn(void)
{
data_handle = find_dissector("data");
pw_padding_handle = find_dissector("pw_padding");
dissector_add_uint("mpls.label", MPLS_LABEL_INVALID, find_dissector("pw_cesopsn_mpls"));
dissector_add_handle("udp.port", find_dissector("pw_cesopsn_udp"));
return;
}
