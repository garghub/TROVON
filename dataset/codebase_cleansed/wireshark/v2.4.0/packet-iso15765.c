static void
iso15765_prompt(packet_info *pinfo _U_, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Next level protocol as");
}
static gpointer
iso15765_value(packet_info *pinfo _U_)
{
return 0;
}
static guint8
masked_guint8_value(const guint8 value, const guint8 mask)
{
return (value & mask) >> ws_ctz(mask);
}
static int
dissect_iso15765(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
static guint32 msg_seqid = 0;
proto_tree *iso15765_tree;
proto_item *ti;
proto_item *message_type_item;
tvbuff_t* next_tvb = NULL;
guint8 pci, message_type;
can_identifier_t* can_info;
iso15765_identifier_t* iso15765_info;
guint8 ae = (addressing == NORMAL_ADDRESSING)?0:1;
guint8 frag_id_low = 0;
guint32 offset;
gint32 data_length;
gboolean fragmented = FALSE;
gboolean complete = FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISO15765");
col_clear(pinfo->cinfo,COL_INFO);
DISSECTOR_ASSERT(data);
can_info = ((can_identifier_t*)data);
iso15765_info = (iso15765_identifier_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_iso15765, 0);
if (!iso15765_info) {
iso15765_info = wmem_new0(wmem_file_scope(), iso15765_identifier_t);
iso15765_info->id = can_info->id;
iso15765_info->last = FALSE;
p_add_proto_data(wmem_file_scope(), pinfo, proto_iso15765, 0, iso15765_info);
}
ti = proto_tree_add_item(tree, proto_iso15765, tvb, 0, -1, ENC_NA);
iso15765_tree = proto_item_add_subtree(ti, ett_iso15765);
message_type_item = proto_tree_add_item(iso15765_tree, hf_iso15765_message_type, tvb,
ae + ISO15765_PCI_OFFSET, ISO15765_PCI_LEN, ENC_BIG_ENDIAN);
pci = tvb_get_guint8(tvb, ae + ISO15765_PCI_OFFSET);
message_type = masked_guint8_value(pci, ISO15765_MESSAGE_TYPE_MASK);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str(message_type, iso15765_message_types, "Unknown (0x%02x)"));
switch(message_type) {
case ISO15765_MESSAGE_TYPES_SINGLE_FRAME: {
offset = ae + ISO15765_PCI_OFFSET + ISO15765_PCI_LEN;
data_length = masked_guint8_value(pci, ISO15765_MESSAGE_DATA_LENGTH_MASK);
next_tvb = tvb_new_subset_length_caplen(tvb, offset, data_length, data_length);
complete = TRUE;
proto_tree_add_item(iso15765_tree, hf_iso15765_data_length, tvb,
ae + ISO15765_PCI_OFFSET, ISO15765_PCI_LEN, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "(Len: %d)", data_length);
break;
}
case ISO15765_MESSAGE_TYPES_FIRST_FRAME: {
guint32 full_len = tvb_get_ntohs(tvb, ae + ISO15765_PCI_OFFSET) & 0xFFF;
offset = ae + ISO15765_MESSAGE_FRAME_LENGTH_OFFSET + ISO15765_MESSAGE_FRAME_LENGTH_LEN;
data_length = tvb_reported_length(tvb) - offset;
frag_id_low = 0;
fragmented = TRUE;
if (!(pinfo->fd->flags.visited)) {
iso15765_frame_t *iso15765_frame = wmem_new0(wmem_file_scope(), iso15765_frame_t);
iso15765_frame->seq = iso15765_info->seq = ++msg_seqid;
iso15765_frame->len = full_len;
wmem_map_insert(iso15765_frame_table, GUINT_TO_POINTER(iso15765_info->seq), iso15765_frame);
}
proto_tree_add_item(iso15765_tree, hf_iso15765_frame_length, tvb,
ae + ISO15765_PCI_OFFSET, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "(Frame Len: %d)", full_len);
break;
}
case ISO15765_MESSAGE_TYPES_CONSECUTIVE_FRAME: {
offset = ae + ISO15765_PCI_OFFSET + ISO15765_PCI_LEN;
data_length = tvb_reported_length(tvb) - offset;
frag_id_low = masked_guint8_value(pci, ISO15765_MESSAGE_SEQUENCE_NUMBER_MASK);
fragmented = TRUE;
if (!(pinfo->fd->flags.visited)) {
iso15765_info->seq = msg_seqid;
}
proto_tree_add_item(iso15765_tree, hf_iso15765_sequence_number,
tvb, ae + ISO15765_PCI_OFFSET, ISO15765_PCI_LEN, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "(Seq: %d)", (pci & ISO15765_MESSAGE_DATA_LENGTH_MASK));
break;
}
case ISO15765_MESSAGE_TYPES_FLOW_CONTROL: {
guint8 status = masked_guint8_value(pci, ISO15765_MESSAGE_DATA_LENGTH_MASK);
guint8 bs = tvb_get_guint8(tvb, ae + ISO15765_FC_BS_OFFSET);
guint8 stmin = tvb_get_guint8(tvb, ae + ISO15765_FC_STMIN_OFFSET);
data_length = 0;
proto_tree_add_item(iso15765_tree, hf_iso15765_flow_status, tvb,
ae + ISO15765_PCI_OFFSET, ISO15765_PCI_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(iso15765_tree, hf_iso15765_fc_bs, tvb,
ae + ISO15765_FC_BS_OFFSET, ISO15765_FC_BS_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(iso15765_tree, hf_iso15765_fc_stmin, tvb,
ae + ISO15765_FC_STMIN_OFFSET, ISO15765_FC_STMIN_LEN, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "(Status: %d, Block size:0x%x, Seperation time minimum: %d ms)",
status, bs, stmin);
break;
}
default:
expert_add_info_format(pinfo, message_type_item, &ei_iso15765_message_type_bad,
"Bad Message Type value %u <= 3", message_type);
return ae + ISO15765_PCI_OFFSET;
}
if (data_length > 0) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
tvb_bytes_to_str_punct(wmem_packet_scope(), tvb, offset, data_length, ' '));
}
if (fragmented) {
tvbuff_t *new_tvb = NULL;
iso15765_frame_t *iso15765_frame;
guint16 frag_id = frag_id_low;
iso15765_frame = (iso15765_frame_t *)wmem_map_lookup(iso15765_frame_table,
GUINT_TO_POINTER(iso15765_info->seq));
if (iso15765_frame != NULL)
{
if (!(pinfo->fd->flags.visited)) {
frag_id += ((iso15765_frame->frag_id_high[frag_id]++) * 16);
iso15765_info->frag_id = frag_id;
if (iso15765_info->frag_id + window < iso15765_frame->last_frag_id) {
iso15765_frame->error = TRUE;
}
}
if (!iso15765_frame->error) {
gboolean save_fragmented = pinfo->fragmented;
guint32 len = data_length;
fragment_head *frag_msg;
if (!(pinfo->fd->flags.visited)) {
if (frag_id > iso15765_frame->last_frag_id) {
iso15765_frame->last_frag_id = frag_id;
}
iso15765_frame->offset += len;
if (iso15765_frame->offset >= iso15765_frame->len) {
iso15765_info->last = TRUE;
iso15765_frame->complete = TRUE;
len -= (iso15765_frame->offset - iso15765_frame->len);
}
}
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_check(&iso15765_reassembly_table, tvb, offset, pinfo, iso15765_info->seq, NULL,
iso15765_info->frag_id, len, !iso15765_info->last);
new_tvb = process_reassembled_data(tvb, offset, pinfo, "Reassembled Message", frag_msg,
&iso15765_frag_items, NULL, iso15765_tree);
if (frag_msg && frag_msg->reassembled_in != pinfo->num) {
col_append_fstr(pinfo->cinfo, COL_INFO, " [Reassembled in #%u]",
frag_msg->reassembled_in);
}
pinfo->fragmented = save_fragmented;
}
if (new_tvb) {
next_tvb = new_tvb;
complete = TRUE;
} else {
next_tvb = tvb_new_subset_length_caplen(tvb, offset, data_length, data_length);
}
}
}
if (next_tvb) {
if (!complete || !dissector_try_uint_new(subdissector_table, 0, next_tvb, pinfo, tree, TRUE, NULL)) {
call_data_dissector(next_tvb, pinfo, tree);
}
}
return tvb_captured_length(tvb);
}
void
proto_register_iso15765(void)
{
static hf_register_info hf[] = {
{
&hf_iso15765_message_type,
{
"Message Type", "iso15765.message_type",
FT_UINT8, BASE_HEX,
VALS(iso15765_message_types), ISO15765_MESSAGE_TYPE_MASK,
NULL, HFILL
}
},
{
&hf_iso15765_data_length,
{
"Data length", "iso15765.data_length",
FT_UINT8, BASE_DEC,
NULL, ISO15765_MESSAGE_DATA_LENGTH_MASK,
NULL, HFILL
}
},
{
&hf_iso15765_frame_length,
{
"Frame length", "iso15765.frame_length",
FT_UINT16, BASE_DEC,
NULL, 0x0fff,
NULL, HFILL
}
},
{
&hf_iso15765_sequence_number,
{
"Sequence number", "iso15765.sequence_number",
FT_UINT8, BASE_HEX,
NULL, ISO15765_MESSAGE_SEQUENCE_NUMBER_MASK,
NULL, HFILL
}
},
{
&hf_iso15765_flow_status,
{
"Flow status", "iso15765.flow_status",
FT_UINT8, BASE_HEX,
NULL, ISO15765_MESSAGE_FLOW_STATUS_MASK,
NULL, HFILL
}
},
{
&hf_iso15765_fc_bs,
{
"Block size", "iso15765.flow_control.bs",
FT_UINT8, BASE_HEX,
NULL, 0x00,
NULL, HFILL
}
},
{
&hf_iso15765_fc_stmin,
{
"Separation time minimum (ms)", "iso15765.flow_control.stmin",
FT_UINT8, BASE_DEC,
NULL, 0x00,
NULL, HFILL
}
},
{
&hf_iso15765_fragments,
{
"Message fragments", "iso15765.fragments",
FT_NONE, BASE_NONE,
NULL, 0x00,
NULL, HFILL
},
},
{
&hf_iso15765_fragment,
{
"Message fragment", "iso15765.fragment",
FT_FRAMENUM, BASE_NONE,
NULL, 0x00,
NULL, HFILL
}
},
{
&hf_iso15765_fragment_overlap,
{
"Message fragment overlap", "iso15765.fragment.overlap",
FT_BOOLEAN, 0,
NULL, 0x00,
NULL, HFILL
}
},
{
&hf_iso15765_fragment_overlap_conflicts,
{
"Message fragment overlapping with conflicting data", "iso15765.fragment.overlap.conflicts",
FT_BOOLEAN, 0,
NULL, 0x00,
NULL, HFILL
}
},
{
&hf_iso15765_fragment_multiple_tails,
{
"Message has multiple tail fragments", "iso15765.fragment.multiple_tails",
FT_BOOLEAN, 0,
NULL, 0x00,
NULL, HFILL
}
},
{
&hf_iso15765_fragment_too_long_fragment,
{
"Message fragment too long", "iso15765.fragment.too_long_fragment",
FT_BOOLEAN, 0, NULL,
0x00, NULL, HFILL
}
},
{
&hf_iso15765_fragment_error,
{
"Message defragmentation error", "iso15765.fragment.error",
FT_FRAMENUM, BASE_NONE,
NULL, 0x00,
NULL, HFILL
}
},
{
&hf_iso15765_fragment_count,
{
"Message fragment count", "iso15765.fragment.count",
FT_UINT32, BASE_DEC,
NULL, 0x00,
NULL, HFILL
}
},
{
&hf_iso15765_reassembled_in,
{
"Reassembled in", "iso15765.reassembled.in",
FT_FRAMENUM, BASE_NONE,
NULL, 0x00,
NULL, HFILL
}
},
{
&hf_iso15765_reassembled_length,
{
"Reassembled length", "iso15765.reassembled.length",
FT_UINT32, BASE_DEC,
NULL, 0x00,
NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_iso15765,
&ett_iso15765_fragment,
&ett_iso15765_fragments,
};
static ei_register_info ei[] = {
{
&ei_iso15765_message_type_bad,
{
"iso15765.message_type.bad", PI_MALFORMED,
PI_ERROR, "Bad Message Type value", EXPFILL
}
},
};
module_t *iso15765_module;
expert_module_t* expert_iso15765;
static build_valid_func iso15765_da_build_value[1] = {iso15765_value};
static decode_as_value_t iso15765_da_values = {iso15765_prompt, 1, iso15765_da_build_value};
static decode_as_t can_iso15765 = {"iso15765", "Transport", "iso15765.subdissector", 1, 0, &iso15765_da_values,
NULL, NULL, decode_as_default_populate_list, decode_as_default_reset,
decode_as_default_change, NULL};
proto_iso15765 = proto_register_protocol (
"ISO15765 Protocol",
"ISO 15765",
"iso15765"
);
register_dissector("iso15765", dissect_iso15765, proto_iso15765);
expert_iso15765 = expert_register_protocol(proto_iso15765);
proto_register_field_array(proto_iso15765, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_register_field_array(expert_iso15765, ei, array_length(ei));
subdissector_table = register_dissector_table("iso15765.subdissector",
"ISO15765 next level dissector", proto_iso15765,
FT_UINT32, BASE_HEX);
iso15765_module = prefs_register_protocol(proto_iso15765, NULL);
prefs_register_enum_preference(iso15765_module, "addressing",
"Addressing",
"Addressing of ISO 15765. Normal or Extended",
&addressing,
enum_addressing, TRUE);
prefs_register_uint_preference(iso15765_module, "window",
"Window",
"Window of ISO 15765 fragments",
10, &window);
register_decode_as(&can_iso15765);
iso15765_frame_table = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), g_direct_hash, g_direct_equal);
reassembly_table_register(&iso15765_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_reg_handoff_iso15765(void)
{
static dissector_handle_t iso15765_handle;
iso15765_handle = create_dissector_handle(dissect_iso15765, proto_iso15765);
dissector_add_for_decode_as("can.subdissector", iso15765_handle);
}
