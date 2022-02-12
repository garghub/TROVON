static inline gboolean
is_sysex_code(guint8 code)
{
return (code == 0x04 || code == 0x05 || code == 0x06 || code == 0x07);
}
static gboolean
is_last_sysex_packet_in_tvb(tvbuff_t *tvb, gint offset)
{
gboolean last = TRUE;
gint length = tvb_length(tvb);
offset += 4;
while (offset < length)
{
guint8 code = tvb_get_guint8(tvb, offset);
code &= 0x0F;
if (is_sysex_code(code))
{
last = FALSE;
break;
}
offset += 4;
}
return last;
}
static void
dissect_usb_midi_event(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *usb_audio_tree, proto_tree *parent_tree,
gint offset)
{
guint8 code;
guint8 cable;
gboolean save_fragmented;
proto_tree *tree = NULL;
col_set_str(pinfo->cinfo, COL_INFO, "USB-MIDI Event Packets");
code = tvb_get_guint8(tvb, offset);
cable = (code & 0xF0) >> 4;
code &= 0x0F;
if (parent_tree)
{
proto_item *ti;
ti = proto_tree_add_protocol_format(usb_audio_tree, proto_usb_audio, tvb, offset, 4, "USB Midi Event Packet");
tree = proto_item_add_subtree(ti, ett_usb_audio);
proto_tree_add_item(tree, hf_midi_cable_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_midi_code_index, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_midi_event, tvb, offset+1, 3, ENC_BIG_ENDIAN);
}
save_fragmented = pinfo->fragmented;
if (is_sysex_code(code))
{
tvbuff_t* new_tvb = NULL;
fragment_head *frag_sysex_msg = NULL;
pinfo->fragmented = TRUE;
if (code == 0x04)
{
frag_sysex_msg = fragment_add_seq_next(&midi_data_reassembly_table,
tvb, offset+1,
pinfo,
cable,
NULL,
3,
TRUE);
}
else
{
frag_sysex_msg = fragment_add_seq_next(&midi_data_reassembly_table,
tvb, offset+1,
pinfo,
cable,
NULL,
(gint)(code - 4),
FALSE);
}
if (is_last_sysex_packet_in_tvb(tvb, offset))
{
new_tvb = process_reassembled_data(tvb, offset+1, pinfo,
"Reassembled Message", frag_sysex_msg, &sysex_msg_frag_items,
NULL, usb_audio_tree);
if (code != 0x04) {
col_append_str(pinfo->cinfo, COL_INFO,
" (SysEx Reassembled)");
} else {
col_append_str(pinfo->cinfo, COL_INFO,
" (SysEx fragment)");
}
if (new_tvb)
{
call_dissector(sysex_handle, new_tvb, pinfo, parent_tree);
}
}
}
pinfo->fragmented = save_fragmented;
}
static gint
dissect_usb_audio_descriptor(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint8 descriptor_len;
guint8 descriptor_type;
proto_item *item = NULL;
proto_tree *desc_tree;
descriptor_len = tvb_get_guint8(tvb, offset);
descriptor_type = tvb_get_guint8(tvb, offset+1);
if (descriptor_type == CS_INTERFACE) {
item = proto_tree_add_text(tree, tvb, offset, descriptor_len,
"AUDIO CONTROL INTERFACE DESCRIPTOR");
}
else if (descriptor_type == CS_ENDPOINT) {
item = proto_tree_add_text(tree, tvb, offset, descriptor_len,
"AUDIO CONTROL ENDPOINT DESCRIPTOR");
}
else
return 0;
desc_tree = proto_item_add_subtree(item, ett_usb_audio_desc);
dissect_usb_descriptor_header(desc_tree, tvb, offset,
&aud_descriptor_type_vals_ext);
return descriptor_len;
}
static int
dissect_usb_audio_bulk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data)
{
usb_conv_info_t *usb_conv_info;
proto_tree *tree = NULL;
guint offset;
guint length = tvb_length(tvb);
if (data == NULL)
return 0;
usb_conv_info = (usb_conv_info_t *)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBAUDIO");
if (parent_tree)
{
proto_item *ti;
ti = proto_tree_add_protocol_format(parent_tree, proto_usb_audio, tvb, 0, -1, "USB Audio");
tree = proto_item_add_subtree(ti, ett_usb_audio);
}
switch (usb_conv_info->interfaceSubclass)
{
case AUDIO_SUBCLASS_MIDISTREAMING:
offset = 0;
col_set_str(pinfo->cinfo, COL_INFO, "USB-MIDI Event Packets");
while (offset < length)
{
dissect_usb_midi_event(tvb, pinfo, tree, parent_tree, offset);
offset += 4;
}
break;
default:
offset = 0;
proto_tree_add_expert(tree, pinfo, &ei_usb_audio_undecoded, tvb, offset, length - offset);
}
return tvb_length(tvb);
}
static void
midi_data_reassemble_init(void)
{
reassembly_table_init(&midi_data_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_register_usb_audio(void)
{
static hf_register_info hf[] = {
{ &hf_midi_cable_number,
{ "Cable Number", "usbaudio.midi.cable_number", FT_UINT8, BASE_HEX,
NULL, 0xF0, NULL, HFILL }},
{ &hf_midi_code_index,
{ "Code Index", "usbaudio.midi.code_index", FT_UINT8, BASE_HEX,
VALS(code_index_vals), 0x0F, NULL, HFILL }},
{ &hf_midi_event,
{ "MIDI Event", "usbaudio.midi.event", FT_UINT24, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_sysex_msg_fragments,
{ "Message fragments", "usbaudio.sysex.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_sysex_msg_fragment,
{ "Message fragment", "usbaudio.sysex.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_sysex_msg_fragment_overlap,
{ "Message fragment overlap", "usbaudio.sysex.fragment.overlap",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL }},
{ &hf_sysex_msg_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data",
"usbaudio.sysex.fragment.overlap.conflicts",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL }},
{ &hf_sysex_msg_fragment_multiple_tails,
{ "Message has multiple tail fragments",
"usbaudio.sysex.fragment.multiple_tails",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL }},
{ &hf_sysex_msg_fragment_too_long_fragment,
{ "Message fragment too long", "usbaudio.sysex.fragment.too_long_fragment",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL }},
{ &hf_sysex_msg_fragment_error,
{ "Message defragmentation error", "usbaudio.sysex.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_sysex_msg_fragment_count,
{ "Message fragment count", "usbaudio.sysex.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_sysex_msg_reassembled_in,
{ "Reassembled in", "usbaudio.sysex.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_sysex_msg_reassembled_length,
{ "Reassembled length", "usbaudio.sysex.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_sysex_msg_reassembled_data,
{ "Reassembled data", "usbaudio.sysex.reassembled.data",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }},
};
static gint *usb_audio_subtrees[] = {
&ett_usb_audio,
&ett_usb_audio_desc,
&ett_sysex_msg_fragment,
&ett_sysex_msg_fragments
};
static ei_register_info ei[] = {
{ &ei_usb_audio_undecoded, { "usbaudio.undecoded", PI_UNDECODED, PI_WARN, "Not dissected yet (report to wireshark.org)", EXPFILL }},
};
expert_module_t* expert_usb_audio;
proto_usb_audio = proto_register_protocol("USB Audio", "USBAUDIO", "usbaudio");
proto_register_field_array(proto_usb_audio, hf, array_length(hf));
proto_register_subtree_array(usb_audio_subtrees, array_length(usb_audio_subtrees));
expert_usb_audio = expert_register_protocol(proto_usb_audio);
expert_register_field_array(expert_usb_audio, ei, array_length(ei));
register_init_routine(&midi_data_reassemble_init);
new_register_dissector("usbaudio", dissect_usb_audio_bulk, proto_usb_audio);
}
void
proto_reg_handoff_usb_audio(void)
{
dissector_handle_t usb_audio_bulk_handle, usb_audio_descr_handle;
usb_audio_descr_handle = new_create_dissector_handle(
dissect_usb_audio_descriptor, proto_usb_audio);
dissector_add_uint("usb.descriptor", IF_CLASS_AUDIO, usb_audio_descr_handle);
usb_audio_bulk_handle = find_dissector("usbaudio");
dissector_add_uint("usb.bulk", IF_CLASS_AUDIO, usb_audio_bulk_handle);
sysex_handle = find_dissector("sysex");
}
