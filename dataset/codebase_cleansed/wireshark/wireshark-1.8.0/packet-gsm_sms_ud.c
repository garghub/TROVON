static void
gsm_sms_ud_defragment_init(void)
{
fragment_table_init(&sm_fragment_table);
reassembled_table_init(&sm_reassembled_table);
}
static void
parse_gsm_sms_ud_message(proto_tree *sm_tree, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *top_tree)
{
tvbuff_t *sm_tvb = NULL;
proto_item *ti;
proto_tree *subtree, *tree;
guint8 udh_len, udh, len;
guint sm_len = tvb_reported_length(tvb);
guint sm_data_len;
guint32 i = 0;
gboolean is_fragmented = FALSE;
fragment_data *fd_sm = NULL;
guint16 sm_id = 0;
guint16 frags = 0;
guint16 frag = 0;
gboolean save_fragmented = FALSE;
gboolean try_gsm_sms_ud_reassemble = FALSE;
gboolean reassembled = FALSE;
guint32 reassembled_in = 0;
guint16 p_src = 0;
guint16 p_dst = 0;
gboolean ports_available = FALSE;
udh_len = tvb_get_guint8(tvb, i++);
ti = proto_tree_add_uint(sm_tree, hf_gsm_sms_udh_length, tvb, 0, 1, udh_len);
tree = proto_item_add_subtree(ti, ett_udh);
while (i < udh_len) {
udh = tvb_get_guint8(tvb, i++);
len = tvb_get_guint8(tvb, i++);
subtree = proto_tree_add_uint(tree, hf_gsm_sms_udh_iei,
tvb, i-2, 2+len, udh);
switch (udh) {
case 0x00:
if (len == 3) {
sm_id = tvb_get_guint8(tvb, i++);
frags = tvb_get_guint8(tvb, i++);
frag = tvb_get_guint8(tvb, i++);
if (frags > 1)
is_fragmented = TRUE;
proto_item_append_text(subtree,
": message %u, part %u of %u", sm_id, frag, frags);
subtree = proto_item_add_subtree(subtree,
ett_udh_ie);
proto_tree_add_uint(subtree,
hf_gsm_sms_udh_multiple_messages_msg_id,
tvb, i-3, 1, sm_id);
proto_tree_add_uint(subtree,
hf_gsm_sms_udh_multiple_messages_msg_parts,
tvb, i-2, 1, frags);
proto_tree_add_uint(subtree,
hf_gsm_sms_udh_multiple_messages_msg_part,
tvb, i-1, 1, frag);
} else {
proto_item_append_text(subtree, " - Invalid format!");
i += len;
}
break;
case 0x08:
if (len == 4) {
sm_id = tvb_get_ntohs(tvb, i); i += 2;
frags = tvb_get_guint8(tvb, i++);
frag = tvb_get_guint8(tvb, i++);
if (frags > 1)
is_fragmented = TRUE;
proto_item_append_text(subtree,
": message %u, part %u of %u", sm_id, frag, frags);
subtree = proto_item_add_subtree(subtree,
ett_udh_ie);
proto_tree_add_uint(subtree,
hf_gsm_sms_udh_multiple_messages_msg_id,
tvb, i-4, 2, sm_id);
proto_tree_add_uint(subtree,
hf_gsm_sms_udh_multiple_messages_msg_parts,
tvb, i-2, 1, frags);
proto_tree_add_uint(subtree,
hf_gsm_sms_udh_multiple_messages_msg_part,
tvb, i-1, 1, frag);
} else {
proto_item_append_text(subtree, " - Invalid format!");
i += len;
}
break;
case 0x04:
if (len == 2) {
p_dst = tvb_get_guint8(tvb, i++);
p_src = tvb_get_guint8(tvb, i++);
proto_item_append_text(subtree,
": source port %u, destination port %u",
p_src, p_dst);
subtree = proto_item_add_subtree(subtree, ett_udh_ie);
proto_tree_add_uint(subtree, hf_gsm_sms_udh_ports_dst,
tvb, i-2, 1, p_dst);
proto_tree_add_uint(subtree, hf_gsm_sms_udh_ports_src,
tvb, i-1, 1, p_src);
ports_available = TRUE;
} else {
proto_item_append_text(subtree, " - Invalid format!");
i += len;
}
break;
case 0x05:
if (len == 4) {
p_dst = tvb_get_ntohs(tvb, i); i += 2;
p_src = tvb_get_ntohs(tvb, i); i += 2;
proto_item_append_text(subtree,
": source port %u, destination port %u",
p_src, p_dst);
subtree = proto_item_add_subtree(subtree, ett_udh_ie);
proto_tree_add_uint(subtree, hf_gsm_sms_udh_ports_dst,
tvb, i-4, 2, p_dst);
proto_tree_add_uint(subtree, hf_gsm_sms_udh_ports_src,
tvb, i-2, 2, p_src);
ports_available = TRUE;
} else {
proto_item_append_text(subtree, " - Invalid format!");
i += len;
}
break;
default:
i += len;
break;
}
}
if (tvb_reported_length_remaining(tvb, i) <= 0)
return;
sm_data_len = sm_len - (1 + udh_len);
if (sm_data_len == 0)
return;
if (is_fragmented && frag != 0 && frags != 0 &&
tvb_bytes_exist(tvb, i, sm_data_len)) {
try_gsm_sms_ud_reassemble = TRUE;
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
fd_sm = fragment_add_seq_check(tvb, i, pinfo,
sm_id,
sm_fragment_table,
sm_reassembled_table,
frag-1,
sm_data_len,
(frag != frags));
if (fd_sm) {
reassembled = TRUE;
reassembled_in = fd_sm->reassembled_in;
}
sm_tvb = process_reassembled_data(tvb, i, pinfo,
"Reassembled Short Message", fd_sm, &sm_frag_items,
NULL, sm_tree);
if (reassembled) {
col_append_str(pinfo->cinfo, COL_INFO,
" (Short Message Reassembled)");
} else {
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Short Message fragment %u of %u)", frag, frags);
}
}
if (! sm_tvb)
sm_tvb = tvb_new_subset_remaining(tvb, i);
if (sm_tvb) {
if ((reassembled && pinfo->fd->num == reassembled_in)
|| frag==0 || (frag==1 && try_dissect_1st_frag)) {
if (ports_available) {
gboolean disallow_write = FALSE;
if (prevent_subdissectors_changing_columns && col_get_writable(pinfo->cinfo)) {
disallow_write = TRUE;
col_set_writable(pinfo->cinfo, FALSE);
}
if (port_number_udh_means_wsp) {
call_dissector(wsp_handle, sm_tvb, pinfo, top_tree);
} else {
if (! dissector_try_uint(gsm_sms_dissector_table, p_src,
sm_tvb, pinfo, top_tree)) {
if (! dissector_try_uint(gsm_sms_dissector_table, p_dst,
sm_tvb, pinfo, top_tree)) {
if (sm_tree) {
proto_tree_add_text(sm_tree, sm_tvb, 0, -1,
"Short Message body");
}
}
}
}
if (disallow_write)
col_set_writable(pinfo->cinfo, TRUE);
} else {
proto_tree_add_text(sm_tree, sm_tvb, 0, -1,
"Short Message body");
}
} else {
proto_tree_add_text(sm_tree, sm_tvb, 0, -1,
"Unreassembled Short Message fragment %u of %u",
frag, frags);
}
}
if (try_gsm_sms_ud_reassemble)
pinfo->fragmented = save_fragmented;
return;
}
static void
dissect_gsm_sms_ud(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_item(tree, proto_gsm_sms_ud, tvb, 0, -1, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_gsm_sms);
parse_gsm_sms_ud_message(subtree, tvb, pinfo, tree);
}
void
proto_register_gsm_sms_ud(void)
{
module_t *gsm_sms_ud_module;
static hf_register_info hf[] = {
{ &hf_gsm_sms_udh_iei,
{ "IE Id", "gsm-sms-ud.udh.iei",
FT_UINT8, BASE_HEX, VALS(vals_udh_iei), 0x00,
"Name of the User Data Header Information Element.",
HFILL
}
},
{ &hf_gsm_sms_udh_length,
{ "UDH Length", "gsm-sms-ud.udh.len",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Length of the User Data Header (bytes)",
HFILL
}
},
{ &hf_gsm_sms_udh_multiple_messages,
{ "Multiple messages UDH", "gsm-sms-ud.udh.mm",
FT_NONE, BASE_NONE, NULL, 0x00,
"Multiple messages User Data Header",
HFILL
}
},
{ &hf_gsm_sms_udh_multiple_messages_msg_id,
{ "Message identifier", "gsm-sms-ud.udh.mm.msg_id",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Identification of the message",
HFILL
}
},
{ &hf_gsm_sms_udh_multiple_messages_msg_parts,
{ "Message parts", "gsm-sms-ud.udh.mm.msg_parts",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Total number of message parts (fragments)",
HFILL
}
},
{ &hf_gsm_sms_udh_multiple_messages_msg_part,
{ "Message part number", "gsm-sms-ud.udh.mm.msg_part",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Message part (fragment) sequence number",
HFILL
}
},
{ &hf_gsm_sms_udh_ports,
{ "Port number UDH", "gsm-sms-ud.udh.ports",
FT_NONE, BASE_NONE, NULL, 0x00,
"Port number User Data Header",
HFILL
}
},
{ &hf_gsm_sms_udh_ports_src,
{ "Source port", "gsm-sms-ud.udh.ports.src",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_gsm_sms_udh_ports_dst,
{ "Destination port", "gsm-sms-ud.udh.ports.dst",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_gsm_sms_ud_fragments,
{ "Short Message fragments", "gsm-sms-ud.fragments",
FT_NONE, BASE_NONE, NULL, 0x00,
"GSM Short Message fragments",
HFILL
}
},
{ &hf_gsm_sms_ud_fragment,
{ "Short Message fragment", "gsm-sms-ud.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
"GSM Short Message fragment",
HFILL
}
},
{ &hf_gsm_sms_ud_fragment_overlap,
{ "Short Message fragment overlap", "gsm-sms-ud.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"GSM Short Message fragment overlaps with other fragment(s)",
HFILL
}
},
{ &hf_gsm_sms_ud_fragment_overlap_conflicts,
{ "Short Message fragment overlapping with conflicting data",
"gsm-sms-ud.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"GSM Short Message fragment overlaps with conflicting data",
HFILL
}
},
{ &hf_gsm_sms_ud_fragment_multiple_tails,
{ "Short Message has multiple tail fragments",
"gsm-sms-ud.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"GSM Short Message fragment has multiple tail fragments",
HFILL
}
},
{ &hf_gsm_sms_ud_fragment_too_long_fragment,
{ "Short Message fragment too long",
"gsm-sms-ud.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"GSM Short Message fragment data goes beyond the packet end",
HFILL
}
},
{ &hf_gsm_sms_ud_fragment_error,
{ "Short Message defragmentation error", "gsm-sms-ud.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
"GSM Short Message defragmentation error due to illegal fragments",
HFILL
}
},
{ &hf_gsm_sms_ud_fragment_count,
{ "Short Message fragment count", "gsm-sms-ud.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL,
HFILL
}
},
{ &hf_gsm_sms_ud_reassembled_in,
{ "Reassembled in",
"gsm-sms-ud.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
"GSM Short Message has been reassembled in this packet.",
HFILL
}
},
{ &hf_gsm_sms_ud_reassembled_length,
{ "Reassembled Short Message length",
"gsm-sms-ud.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"The total length of the reassembled payload",
HFILL
}
},
};
static gint *ett[] = {
&ett_gsm_sms,
&ett_udh,
&ett_udh_ie,
&ett_gsm_sms_ud_fragment,
&ett_gsm_sms_ud_fragments,
};
proto_gsm_sms_ud = proto_register_protocol(
"GSM Short Message Service User Data",
"GSM SMS UD",
"gsm-sms-ud");
proto_register_field_array(proto_gsm_sms_ud, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
gsm_sms_dissector_table = register_dissector_table("gsm-sms-ud.udh.port",
"GSM SMS port IE in UDH", FT_UINT16, BASE_DEC);
gsm_sms_ud_module = prefs_register_protocol(proto_gsm_sms_ud, NULL);
prefs_register_bool_preference(gsm_sms_ud_module,
"port_number_udh_means_wsp",
"Port Number IE in UDH always triggers CL-WSP dissection",
"Always decode a GSM Short Message as Connectionless WSP "
"if a Port Number Information Element is present "
"in the SMS User Data Header.",
&port_number_udh_means_wsp);
prefs_register_bool_preference(gsm_sms_ud_module, "try_dissect_1st_fragment",
"Always try subdissection of 1st Short Message fragment",
"Always try subdissection of the 1st fragment of a fragmented "
"GSM Short Message. If reassembly is possible, the Short Message "
"may be dissected twice (once as a short frame, once in its "
"entirety).",
&try_dissect_1st_frag);
prefs_register_bool_preference(gsm_sms_ud_module, "prevent_dissectors_chg_cols",
"Prevent sub-dissectors from changing column data",
"Prevent sub-dissectors from replacing column data with their "
"own. Eg. Prevent WSP dissector overwriting SMPP information.",
&prevent_subdissectors_changing_columns);
register_dissector("gsm-sms-ud", dissect_gsm_sms_ud, proto_gsm_sms_ud);
register_init_routine(gsm_sms_ud_defragment_init);
}
void
proto_reg_handoff_gsm_sms_ud(void)
{
wsp_handle = find_dissector("wsp-cl");
DISSECTOR_ASSERT(wsp_handle);
}
