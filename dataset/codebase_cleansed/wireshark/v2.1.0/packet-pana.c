static void
dissect_pana_flags(proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint16 flags)
{
static const int * flag_fields[] = {
&hf_pana_flag_r,
&hf_pana_flag_s,
&hf_pana_flag_c,
&hf_pana_flag_a,
&hf_pana_flag_p,
&hf_pana_flag_i,
NULL,
};
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_pana_flags,
ett_pana_flags, flag_fields, flags, BMT_NO_TFS|BMT_NO_FALSE);
}
static void
dissect_pana_avp_flags(proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint16 flags)
{
static const int * flag_fields[] = {
&hf_pana_avp_flag_v,
NULL,
};
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_pana_avp_flags,
ett_pana_avp_flags, flag_fields, flags, BMT_NO_TFS|BMT_NO_FALSE);
}
static pana_avp_types
pana_avp_get_type(guint16 avp_code, guint32 vendor_id)
{
if(vendor_id == 0) {
switch(avp_code) {
case 1: return PANA_OCTET_STRING;
case 2: return PANA_EAP;
case 3: return PANA_UNSIGNED32;
case 4: return PANA_INTEGER32;
case 5: return PANA_OCTET_STRING;
case 6: return PANA_UNSIGNED32;
case 7: return PANA_RESULT_CODE;
case 8: return PANA_UNSIGNED32;
case 9: return PANA_ENUMERATED;
case 10: return PANA_OCTET_STRING;
case 11: return PANA_ENCAPSULATED;
case 12: return PANA_OCTET_STRING;
case 13: return PANA_UNSIGNED32;
default: return PANA_OCTET_STRING;
}
} else {
return PANA_OCTET_STRING;
}
}
static void
dissect_avps(tvbuff_t *tvb, packet_info *pinfo, proto_tree *avp_tree)
{
gint offset;
guint16 avp_code;
guint16 avp_flags;
guint32 avp_length;
guint16 avp_type;
guint32 vendor_id;
guint32 avp_hdr_length;
guint32 avp_data_length, result_code;
guint32 padding;
gint32 buffer_length;
tvbuff_t *group_tvb;
tvbuff_t *eap_tvb;
tvbuff_t *encap_tvb;
proto_tree *single_avp_tree;
proto_tree *avp_eap_tree;
proto_tree *avp_encap_tree;
offset = 0;
buffer_length = tvb_reported_length(tvb);
while (buffer_length > 0) {
avp_code = tvb_get_ntohs(tvb, offset);
avp_flags = tvb_get_ntohs(tvb, offset + 2);
avp_data_length = tvb_get_ntohs(tvb, offset + 4);
if (avp_flags & PANA_AVP_FLAG_V) {
vendor_id = tvb_get_ntohl(tvb, 8);
avp_hdr_length = 12;
} else {
vendor_id = 0;
avp_hdr_length = 8;
}
avp_length = avp_hdr_length + avp_data_length;
avp_type = pana_avp_get_type(avp_code, vendor_id);
padding = (4 - (avp_length % 4)) % 4;
single_avp_tree = proto_tree_add_subtree_format(avp_tree, tvb, offset, avp_length + padding,
ett_pana_avp_info, NULL, "%s (%s) length: %d bytes (%d padded bytes)",
val_to_str(avp_code, avp_code_names, "Unknown (%d)"),
val_to_str(avp_type, avp_type_names, "Unknown (%d)"),
avp_length,
avp_length + padding);
proto_tree_add_uint_format_value(single_avp_tree, hf_pana_avp_code, tvb,
offset, 2, avp_code, "%s (%u)",
val_to_str(avp_code, avp_code_names, "Unknown (%d)"),
avp_code);
offset += 2;
dissect_pana_avp_flags(single_avp_tree, tvb, offset, avp_flags);
offset += 2;
proto_tree_add_item(single_avp_tree, hf_pana_avp_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(single_avp_tree, hf_pana_avp_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
if (avp_flags & PANA_AVP_FLAG_V) {
proto_tree_add_item(single_avp_tree, hf_pana_avp_vendorid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (! (avp_flags & PANA_AVP_FLAG_V)) {
switch(avp_type) {
case PANA_GROUPED: {
proto_tree *avp_group_tree;
avp_group_tree = proto_tree_add_subtree(single_avp_tree,
tvb, offset, avp_data_length,
ett_pana_avp, NULL, "Grouped AVP");
group_tvb = tvb_new_subset(tvb, offset,
MIN(avp_data_length, tvb_reported_length(tvb)-offset),
avp_data_length);
dissect_avps(group_tvb, pinfo, avp_group_tree);
break;
}
case PANA_UTF8STRING: {
guint8 *data = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, avp_data_length, ENC_UTF_8);
proto_tree_add_string_format(single_avp_tree, hf_pana_avp_data_string, tvb,
offset, avp_data_length, data,
"UTF8String: %s", data);
break;
}
case PANA_OCTET_STRING: {
proto_tree_add_item(single_avp_tree, hf_pana_avp_data_bytes, tvb,
offset, avp_data_length, ENC_NA);
break;
}
case PANA_INTEGER32: {
proto_tree_add_item(single_avp_tree, hf_pana_avp_data_int32, tvb,
offset, 4, ENC_BIG_ENDIAN);
break;
}
case PANA_UNSIGNED32: {
proto_tree_add_item(single_avp_tree, hf_pana_avp_data_uint32, tvb,
offset, 4, ENC_BIG_ENDIAN);
break;
}
case PANA_INTEGER64: {
proto_tree_add_item(single_avp_tree, hf_pana_avp_data_int64, tvb,
offset, 8, ENC_BIG_ENDIAN);
break;
}
case PANA_UNSIGNED64: {
proto_tree_add_item(single_avp_tree, hf_pana_avp_data_uint64, tvb,
offset, 8, ENC_BIG_ENDIAN);
break;
}
case PANA_ENUMERATED: {
proto_tree_add_item(single_avp_tree, hf_pana_avp_data_enumerated, tvb,
offset, 4, ENC_BIG_ENDIAN);
break;
}
case PANA_RESULT_CODE: {
result_code = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format(single_avp_tree, hf_pana_avp_code, tvb, offset, avp_data_length,
result_code, "Value: %d (%s)",
result_code,
val_to_str(result_code, avp_code_names, "Unknown (%d)"));
break;
}
case PANA_EAP: {
avp_eap_tree = proto_tree_add_subtree(single_avp_tree,
tvb, offset, avp_data_length,
ett_pana_avp, NULL, "AVP Value (EAP packet)");
eap_tvb = tvb_new_subset_length(tvb, offset, avp_data_length);
DISSECTOR_ASSERT_HINT(eap_handle, "EAP Dissector not available");
call_dissector(eap_handle, eap_tvb, pinfo, avp_eap_tree);
break;
}
case PANA_ENCAPSULATED: {
avp_encap_tree = proto_tree_add_subtree(single_avp_tree,
tvb, offset, avp_data_length,
ett_pana_avp, NULL, "AVP Value (PANA packet)");
encap_tvb = tvb_new_subset_length(tvb, offset, avp_data_length);
dissect_pana_pdu(encap_tvb, pinfo, avp_encap_tree);
break;
}
}
}
offset += avp_data_length + padding;
buffer_length -= avp_length + padding;
}
}
static void
dissect_pana_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *pana_tree = NULL;
guint16 flags;
guint16 msg_type;
guint32 msg_length;
guint32 avp_length;
guint32 seq_num;
conversation_t *conversation;
pana_conv_info_t *pana_info;
pana_transaction_t *pana_trans;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PANA");
col_clear(pinfo->cinfo, COL_INFO);
msg_length = tvb_get_ntohs(tvb, 2);
flags = tvb_get_ntohs(tvb, 4);
msg_type = tvb_get_ntohs(tvb, 6);
seq_num = tvb_get_ntohl(tvb, 12);
avp_length = msg_length - 16;
col_add_fstr(pinfo->cinfo, COL_INFO, "Type %s-%s",
val_to_str(msg_type, msg_type_names, "Unknown (%d)"),
val_to_str(flags & PANA_FLAG_R, msg_subtype_names, "Unknown (%d)"));
if (tree) {
proto_item *ti;
ti = proto_tree_add_item(tree, proto_pana, tvb, 0, -1, ENC_NA);
pana_tree = proto_item_add_subtree(ti, ett_pana);
}
conversation = find_or_create_conversation(pinfo);
pana_info = (pana_conv_info_t *)conversation_get_proto_data(conversation, proto_pana);
if (!pana_info) {
pana_info = wmem_new(wmem_file_scope(), pana_conv_info_t);
pana_info->pdus=wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
conversation_add_proto_data(conversation, proto_pana, pana_info);
}
if(!pinfo->fd->flags.visited){
if(flags&PANA_FLAG_R){
pana_trans=wmem_new(wmem_file_scope(), pana_transaction_t);
pana_trans->req_frame=pinfo->num;
pana_trans->rep_frame=0;
pana_trans->req_time=pinfo->abs_ts;
wmem_map_insert(pana_info->pdus, GUINT_TO_POINTER(seq_num), (void *)pana_trans);
} else {
pana_trans=(pana_transaction_t *)wmem_map_lookup(pana_info->pdus, GUINT_TO_POINTER(seq_num));
if(pana_trans){
pana_trans->rep_frame=pinfo->num;
}
}
} else {
pana_trans=(pana_transaction_t *)wmem_map_lookup(pana_info->pdus, GUINT_TO_POINTER(seq_num));
}
if(!pana_trans){
pana_trans=wmem_new(wmem_packet_scope(), pana_transaction_t);
pana_trans->req_frame=0;
pana_trans->rep_frame=0;
pana_trans->req_time=pinfo->abs_ts;
}
if(flags&PANA_FLAG_R){
if(pana_trans->rep_frame){
proto_item *it;
it=proto_tree_add_uint(pana_tree, hf_pana_response_in, tvb, 0, 0, pana_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(it);
}
} else {
if(pana_trans->req_frame){
proto_item *it;
nstime_t ns;
it=proto_tree_add_uint(pana_tree, hf_pana_response_to, tvb, 0, 0, pana_trans->req_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->abs_ts, &pana_trans->req_time);
it=proto_tree_add_time(pana_tree, hf_pana_response_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(it);
}
}
proto_tree_add_item(pana_tree, hf_pana_reserved_type, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(pana_tree, hf_pana_length_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dissect_pana_flags(pana_tree, tvb, offset, flags);
offset += 2;
proto_tree_add_uint_format_value(pana_tree, hf_pana_msg_type, tvb,
offset, 2, msg_type, "%s-%s (%d)",
val_to_str(msg_type, msg_type_names, "Unknown (%d)"),
val_to_str(flags & PANA_FLAG_R, msg_subtype_names, "Unknown (%d)"),
msg_type);
offset += 2;
proto_tree_add_item(pana_tree, hf_pana_session_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pana_tree, hf_pana_seqnumber, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if(avp_length != 0){
tvbuff_t *avp_tvb;
proto_tree *avp_tree;
avp_tvb = tvb_new_subset_length(tvb, offset, avp_length);
avp_tree = proto_tree_add_subtree(pana_tree, tvb, offset, avp_length, ett_pana_avp, NULL, "Attribute Value Pairs");
dissect_avps(avp_tvb, pinfo, avp_tree);
}
}
static int
dissect_pana(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint16 pana_res;
guint32 msg_length;
guint16 flags;
guint32 buffer_length;
guint16 msg_type;
guint32 avp_length;
buffer_length = tvb_captured_length(tvb);
if(buffer_length < 12) {
return 0;
}
msg_length = tvb_get_ntohs(tvb, 2);
if(msg_length < 16) {
return 0;
}
if(msg_length != tvb_reported_length(tvb)) {
return 0;
}
pana_res = tvb_get_ntohs(tvb, 0);
if (pana_res != 0) {
return 0;
}
flags = tvb_get_ntohs(tvb, 4);
if (flags & PANA_FLAG_RESERVED) {
return 0;
}
msg_type = tvb_get_ntohs(tvb, 6);
if ((msg_type > MSG_TYPE_MAX) || (msg_type == 0)) {
return 0;
}
avp_length = msg_length - 16;
if (avp_length != 0) {
guint32 avp_offset;
guint16 avp_code;
guint32 first_avp_length;
guint16 avp_flags;
if (avp_length < MIN_AVP_SIZE) {
return 0;
}
avp_offset = 16;
if ((avp_offset + 8) > buffer_length ) {
return 0;
}
avp_code = tvb_get_ntohs(tvb, avp_offset);
if ((avp_code == 0) || (avp_code > AVP_CODE_MAX)) {
return 0;
}
avp_flags = tvb_get_ntohs(tvb, avp_offset + 2);
if (avp_flags & PANA_AVP_FLAG_RESERVED) {
return 0;
}
if (avp_flags & PANA_AVP_FLAG_V) {
first_avp_length = 12;
} else {
first_avp_length = 8;
}
first_avp_length += tvb_get_ntohs(tvb, avp_offset + 4);
if (first_avp_length > avp_length) {
return 0;
}
}
dissect_pana_pdu(tvb, pinfo, tree);
return tvb_reported_length(tvb);
}
void
proto_register_pana(void)
{
static hf_register_info hf[] = {
{ &hf_pana_response_in,
{ "Response In", "pana.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this PANA request is in this frame", HFILL }
},
{ &hf_pana_response_to,
{ "Request In", "pana.response_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the PANA request in this frame", HFILL }
},
{ &hf_pana_response_time,
{ "Response Time", "pana.response_time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the Call and the Reply", HFILL }
},
{ &hf_pana_reserved_type,
{ "PANA Reserved", "pana.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_length_type,
{ "PANA Message Length", "pana.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_flags,
{ "Flags", "pana.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_flag_r,
{ "Request", "pana.flags.r",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), PANA_FLAG_R,
NULL, HFILL }
},
{ &hf_pana_flag_s,
{ "Start", "pana.flags.s",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), PANA_FLAG_S,
NULL, HFILL }
},
{ &hf_pana_flag_c,
{ "Complete","pana.flags.c",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), PANA_FLAG_C,
NULL, HFILL }
},
{ &hf_pana_flag_a,
{ "Auth","pana.flags.a",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), PANA_FLAG_A,
NULL, HFILL }
},
{ &hf_pana_flag_p,
{ "Ping","pana.flags.p",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), PANA_FLAG_P,
NULL, HFILL }
},
{ &hf_pana_flag_i,
{ "IP Reconfig","pana.flags.i",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), PANA_FLAG_I,
NULL, HFILL }
},
{ &hf_pana_msg_type,
{ "PANA Message Type", "pana.type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_session_id,
{ "PANA Session ID", "pana.sid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_seqnumber,
{ "PANA Sequence Number", "pana.seq",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_code,
{ "AVP Code", "pana.avp.code",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_data_length,
{ "AVP Data Length", "pana.avp.data_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_flags,
{ "AVP Flags", "pana.avp.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_flag_v,
{ "Vendor", "pana.avp.flags.v",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), PANA_AVP_FLAG_V,
NULL, HFILL }
},
{ &hf_pana_avp_reserved,
{ "AVP Reserved", "pana.avp.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_vendorid,
{ "AVP Vendor ID", "pana.avp.vendorid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_data_uint64,
{ "Value", "pana.avp.data.uint64",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_data_int64,
{ "Value", "pana.avp.data.int64",
FT_INT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_data_uint32,
{ "Value", "pana.avp.data.uint32",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_data_int32,
{ "Value", "pana.avp.data.int32",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_data_bytes,
{ "Value", "pana.avp.data.bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_data_string,
{ "Value", "pana.avp.data.string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pana_avp_data_enumerated,
{ "Value", "pana.avp.data.enum",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_pana,
&ett_pana_flags,
&ett_pana_avp,
&ett_pana_avp_info,
&ett_pana_avp_flags
};
proto_pana = proto_register_protocol("Protocol for carrying Authentication for Network Access",
"PANA", "pana");
proto_register_field_array(proto_pana, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pana(void)
{
dissector_handle_t pana_handle;
heur_dissector_add("udp", dissect_pana, "PANA over UDP", "pana_udp", proto_pana, HEURISTIC_ENABLE);
pana_handle = create_dissector_handle(dissect_pana, proto_pana);
dissector_add_for_decode_as("udp.port", pana_handle);
eap_handle = find_dissector_add_dependency("eap", proto_pana);
}
