static gboolean
event_present(const struct msh *msh) {
return msh->trigger_event[0] == 0 ? FALSE : TRUE;
}
static int
parse_msh(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, gint offset,
struct msh *msh)
{
gint segment_len = -1;
gint end_of_segment_offset = -1;
gint field_separator_offset = -1;
gint field_number = 0;
msh->trigger_event[0] ='\0';
msh->message_type[0] = '\0';
field_number = 1;
offset += 3;
msh->field_separator = tvb_get_guint8(tvb, offset);
offset += 1;
msh->component_separator = tvb_get_guint8(tvb, offset);
offset += 1;
msh->repetition_separator = tvb_get_guint8(tvb, offset);
offset += 1;
msh->escape_character = tvb_get_guint8(tvb, offset);
offset += 1;
msh->subcomponent_separator = tvb_get_guint8(tvb, offset);
offset += 1;
field_number++;
segment_len = tvb_find_line_end(tvb, offset, -1, NULL, TRUE);
if (segment_len == -1) {
expert_add_info_format(pinfo, NULL, &ei_hl7_malformed,
"Segments must be terminated with CR");
return -1;
}
end_of_segment_offset = offset + segment_len;
while (offset < end_of_segment_offset) {
field_separator_offset =
tvb_find_guint8(tvb, offset, end_of_segment_offset - offset,
msh->field_separator);
if (field_separator_offset == -1) {
if (field_number < 9) {
expert_add_info_format(pinfo, NULL, &ei_hl7_malformed,
"MSH must have at least 9 fields");
return -1;
}
return 0;
}
field_number++;
offset = field_separator_offset + 1;
if (tvb_get_guint8(tvb, offset) == msh->field_separator) {
continue;
}
if (field_number == 9) {
msh->message_type[0] = tvb_get_guint8(tvb, offset);
msh->message_type[1] = tvb_get_guint8(tvb, offset + 1);
msh->message_type[2] = tvb_get_guint8(tvb, offset + 2);
msh->message_type[3] = '\0';
if (tree) {
proto_item *hidden_item;
hidden_item = proto_tree_add_item(tree, hf_hl7_message_type,
tvb, offset, 3,
ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (tvb_get_guint8(tvb, offset + 3) == msh->component_separator) {
msh->trigger_event[0] = tvb_get_guint8(tvb, offset + 4);
msh->trigger_event[1] = tvb_get_guint8(tvb, offset + 5);
msh->trigger_event[2] = tvb_get_guint8(tvb, offset + 6);
msh->trigger_event[3] = '\0';
if (tree) {
proto_item *hidden_item;
hidden_item = proto_tree_add_item(tree, hf_hl7_event_type,
tvb, offset + 4, 3,
ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
}
return 0;
}
static void
dissect_hl7_segment(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_,
gint offset, gint segment_len, gint segment_len_crlf _U_,
const struct msh *msh _U_)
{
proto_tree *segment_tree = NULL;
proto_item *ti = NULL;
char *field_str = NULL;
gint end_of_segment_offset = 0;
gint field_separator_offset = 0;
gint field_num = 0;
gint field_len = 0;
gint segment_consumed = 0;
gboolean last_field = FALSE;
end_of_segment_offset = offset + segment_len;
while (offset < end_of_segment_offset) {
field_num++;
field_separator_offset =
tvb_find_guint8(tvb, offset,
segment_len - segment_consumed,
msh->field_separator);
if (field_separator_offset == -1) {
if (segment_consumed != segment_len) {
last_field = TRUE;
field_len = segment_len - segment_consumed;
segment_consumed += field_len + 1;
} else {
return;
}
} else {
field_len = field_separator_offset - offset;
segment_consumed += field_len + 1;
}
if (field_len == 0) {
offset = field_separator_offset + 1;
continue;
}
if (field_num == 1) {
char *segment_type_id = NULL;
segment_type_id = tvb_get_string_enc(wmem_packet_scope(),
tvb, offset, 3, ENC_ASCII);
ti = proto_tree_add_item(tree, hf_hl7_segment,
tvb, offset, segment_len_crlf,
ENC_ASCII|ENC_NA);
proto_item_set_text(ti, "%s (%s)", segment_type_id,
str_to_str(segment_type_id, hl7_seg_type_vals,
"Unknown Segment"));
segment_tree = proto_item_add_subtree(ti, ett_hl7_segment);
if (global_hl7_raw) {
proto_tree_add_item(segment_tree, hf_hl7_raw_segment, tvb, offset,
segment_len_crlf, ENC_ASCII|ENC_NA);
}
}
field_str = tvb_get_string_enc(wmem_packet_scope(),
tvb, offset, field_len, ENC_ASCII);
ti = proto_tree_add_item(segment_tree, hf_hl7_field,
tvb, offset, field_len, ENC_ASCII|ENC_NA);
proto_item_set_text(ti, "field %d: %s", field_num, field_str);
if (last_field) {
return;
}
offset = field_separator_offset + 1;
}
}
static void
dissect_hl7_message(tvbuff_t *tvb, guint tvb_offset, gint len,
packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint offset = tvb_offset;
guint sob_offset = offset;
guint eob_offset = offset + len - 2;
proto_tree *hl7_tree = NULL;
proto_item *ti = NULL;
struct msh msh;
int ret = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HL7");
col_clear(pinfo->cinfo, COL_INFO);
ret = parse_msh(tvb, pinfo, tree, offset + 1, &msh);
if (ret == -1)
return;
if (event_present(&msh)) {
if (offset == 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (%s)",
msh.message_type,
msh.trigger_event);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s (%s)",
msh.message_type,
msh.trigger_event);
}
} else {
if (offset == 0) {
col_append_str(pinfo->cinfo, COL_INFO,
msh.message_type);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
msh.message_type);
}
}
col_set_fence(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_hl7, tvb, offset, len, ENC_NA);
if (event_present(&msh)) {
proto_item_append_text(ti, ", Type: %s, Event: %s",
str_to_str(msh.message_type,
hl7_msg_type_vals, "Unknown"),
str_to_str(msh.trigger_event,
hl7_event_type_vals, "Unknown"));
} else {
proto_item_append_text(ti, ", Type: %s",
str_to_str(msh.message_type,
hl7_msg_type_vals, "Unknown"));
}
hl7_tree = proto_item_add_subtree(ti, ett_hl7);
if (global_hl7_llp) {
proto_tree_add_item(hl7_tree, hf_hl7_llp_sob, tvb, sob_offset, 1, ENC_NA);
}
offset++;
if (global_hl7_raw) {
proto_tree_add_item(hl7_tree, hf_hl7_raw, tvb, offset, len - 3,
ENC_ASCII|ENC_NA);
}
while (offset < eob_offset) {
gint next_offset = -1;
gint segment_len = -1;
gint segment_len_crlf = -1;
segment_len = tvb_find_line_end(tvb, offset, -1, &next_offset, TRUE);
if (segment_len == -1) {
expert_add_info_format(pinfo, NULL, &ei_hl7_malformed,
"Segments must be terminated with CR");
return;
}
segment_len_crlf = next_offset - offset;
dissect_hl7_segment(tvb, pinfo, hl7_tree,
offset, segment_len, segment_len_crlf, &msh);
offset += segment_len_crlf;
}
if (global_hl7_llp) {
proto_tree_add_item(hl7_tree, hf_hl7_llp_eob, tvb, eob_offset, 2,
ENC_BIG_ENDIAN);
}
}
static int
dissect_hl7(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint offset = 0;
while (offset < tvb_reported_length(tvb)) {
gint available = tvb_reported_length_remaining(tvb, offset);
gint llp_eob_offset = tvb_find_guint16(tvb, offset, offset + available, LLP_EOB);
if (llp_eob_offset == -1) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return (offset + available);
}
gint llp_block_len = llp_eob_offset - offset + 2;
if (tvb_get_guint8(tvb, 0) != LLP_SOB) {
tvbuff_t *new_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(new_tvb, pinfo, tree);
return (offset + available);
}
dissect_hl7_message(tvb, offset, llp_block_len, pinfo, tree, data);
offset += (guint)llp_block_len;
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_hl7_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_)
{
conversation_t *conversation = NULL;
if ((tvb_reported_length_remaining(tvb, 0) < 5) ||
(tvb_get_guint8(tvb, 0) != LLP_SOB) ||
(tvb_strncaseeql(tvb, 1, "MSH|", 4) != 0)) {
return FALSE;
}
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, hl7_handle);
gint llp_eob_offset = tvb_find_guint16(tvb, 0, -1, LLP_EOB);
if (llp_eob_offset == -1) {
pinfo->desegment_offset = 0;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
}
return TRUE;
}
void
proto_reg_handoff_hl7(void)
{
hl7_heur_handle = create_dissector_handle(dissect_hl7_heur, proto_hl7);
heur_dissector_add("tcp", dissect_hl7_heur, "HL7 over TCP",
"hl7_tcp", proto_hl7, HEURISTIC_ENABLE);
hl7_handle = create_dissector_handle(dissect_hl7, proto_hl7);
dissector_add_uint_with_preference("tcp.port", TCP_PORT_HL7, hl7_handle);
}
void
proto_register_hl7(void)
{
static hf_register_info hl7f_info[] = {
{ &hf_hl7_raw,
{ "raw message", "hl7.raw", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_hl7_llp_sob,
{ "LLP Start Of Block", "hl7.llp.sob", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_hl7_llp_eob,
{ "LLP End Of Block", "hl7.llp.eob", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_hl7_raw_segment,
{ "raw segment", "hl7.raw.segment", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_hl7_segment,
{ "xyz", "hl7.segment", FT_STRING,
BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_hl7_message_type,
{ "xyz", "hl7.message.type", FT_STRING,
BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_hl7_event_type,
{ "xyz", "hl7.event.type", FT_STRING,
BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_hl7_field,
{ "xyz", "hl7.field", FT_STRING,
BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_hl7,
&ett_hl7_segment,
};
static ei_register_info ei[] = {
{ &ei_hl7_malformed, { "hl7.malformed", PI_MALFORMED, PI_WARN, "Malformed", EXPFILL }},
};
expert_module_t *expert_hl7 = NULL;
module_t *hl7_module = NULL;
proto_hl7 = proto_register_protocol("Health Level Seven", "HL7", "hl7");
proto_register_field_array(proto_hl7, hl7f_info, array_length(hl7f_info));
proto_register_subtree_array(ett, array_length(ett));
expert_hl7 = expert_register_protocol(proto_hl7);
expert_register_field_array(expert_hl7, ei, array_length(ei));
hl7_module = prefs_register_protocol(proto_hl7, proto_reg_handoff_hl7);
prefs_register_bool_preference(hl7_module, "display_raw",
"Display raw text for HL7 message",
"Specifies that the raw text of the "
"HL7 message should be displayed "
"in addition to the dissection tree",
&global_hl7_raw);
prefs_register_bool_preference(hl7_module, "display_llp",
"Display LLP markers (Start/End Of Block)",
"Specifies that the LLP session information "
"should be displayed (Start/End Of Block) "
"in addition to the dissection tree",
&global_hl7_llp);
}
