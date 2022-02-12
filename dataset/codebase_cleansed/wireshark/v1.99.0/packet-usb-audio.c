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
dissect_ac_if_hdr_body(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, usb_conv_info_t *usb_conv_info)
{
gint offset_start;
guint16 bcdADC;
guint8 ver_major;
double ver;
guint8 if_in_collection, i;
audio_conv_info_t *audio_conv_info;
offset_start = offset;
bcdADC = tvb_get_letohs(tvb, offset);
ver_major = USB_AUDIO_BCD44_TO_DEC(bcdADC>>8);
ver = ver_major + USB_AUDIO_BCD44_TO_DEC(bcdADC&0xFF) / 100.0;
proto_tree_add_double_format_value(tree, hf_ac_if_hdr_ver,
tvb, offset, 2, ver, "%2.2f", ver);
audio_conv_info = (audio_conv_info_t *)usb_conv_info->class_data;
if(!audio_conv_info) {
audio_conv_info = wmem_new(wmem_file_scope(), audio_conv_info_t);
usb_conv_info->class_data = audio_conv_info;
}
audio_conv_info->ver_major = ver_major;
offset += 2;
if (ver_major==1) {
proto_tree_add_item(tree, hf_ac_if_hdr_total_len,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if_in_collection = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ac_if_hdr_bInCollection,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
for (i=0; i<if_in_collection; i++) {
proto_tree_add_item(tree, hf_ac_if_hdr_if_num,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
}
}
return offset-offset_start;
}
static gint
dissect_as_if_general_body(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, usb_conv_info_t *usb_conv_info)
{
audio_conv_info_t *audio_conv_info;
gint offset_start;
audio_conv_info = (audio_conv_info_t *)usb_conv_info->class_data;
if (!audio_conv_info)
return 0;
offset_start = offset;
if (audio_conv_info->ver_major==1) {
proto_tree_add_item(tree, hf_as_if_gen_term_id,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_as_if_gen_delay,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_as_if_gen_format,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
return offset-offset_start;
}
static gint
dissect_usb_audio_descriptor(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data)
{
gint offset = 0;
usb_conv_info_t *usb_conv_info;
proto_tree *desc_tree = NULL;
proto_item *desc_tree_item;
guint8 desc_len;
guint8 desc_type;
guint8 desc_subtype;
const gchar *subtype_str;
usb_conv_info = (usb_conv_info_t *)data;
if (!usb_conv_info || usb_conv_info->interfaceClass!=IF_CLASS_AUDIO)
return 0;
desc_len = tvb_get_guint8(tvb, offset);
desc_type = tvb_get_guint8(tvb, offset+1);
if (desc_type==CS_INTERFACE &&
usb_conv_info->interfaceSubclass==AUDIO_IF_SUBCLASS_AUDIOCONTROL) {
desc_tree = proto_tree_add_subtree(tree, tvb, offset, desc_len,
ett_usb_audio_desc, &desc_tree_item,
"Class-specific Audio Control Interface Descriptor");
dissect_usb_descriptor_header(desc_tree, tvb, offset,
&aud_descriptor_type_vals_ext);
offset += 2;
desc_subtype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(desc_tree, hf_ac_if_desc_subtype,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
subtype_str = try_val_to_str_ext(desc_subtype, &ac_subtype_vals_ext);
if (subtype_str)
proto_item_append_text(desc_tree_item, ": %s", subtype_str);
offset++;
switch(desc_subtype) {
case AC_SUBTYPE_HEADER:
dissect_ac_if_hdr_body(tvb, offset, pinfo, desc_tree, usb_conv_info);
break;
default:
break;
}
}
else if (desc_type==CS_INTERFACE &&
usb_conv_info->interfaceSubclass==AUDIO_IF_SUBCLASS_AUDIOSTREAMING) {
desc_tree = proto_tree_add_subtree(tree, tvb, offset, desc_len,
ett_usb_audio_desc, &desc_tree_item,
"Class-specific Audio Streaming Interface Descriptor");
dissect_usb_descriptor_header(desc_tree, tvb, offset,
&aud_descriptor_type_vals_ext);
offset += 2;
desc_subtype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(desc_tree, hf_as_if_desc_subtype,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
subtype_str = try_val_to_str_ext(desc_subtype, &as_subtype_vals_ext);
if (subtype_str)
proto_item_append_text(desc_tree_item, ": %s", subtype_str);
offset++;
switch(desc_subtype) {
case AS_SUBTYPE_GENERAL:
dissect_as_if_general_body(tvb, offset, pinfo,
desc_tree, usb_conv_info);
break;
default:
break;
}
}
else if (desc_type == CS_ENDPOINT &&
usb_conv_info->interfaceSubclass==AUDIO_IF_SUBCLASS_AUDIOSTREAMING) {
desc_tree = proto_tree_add_subtree(tree, tvb, offset, desc_len,
ett_usb_audio_desc, &desc_tree_item,
"Class-specific Audio Streaming Endpoint Descriptor");
dissect_usb_descriptor_header(desc_tree, tvb, offset,
&aud_descriptor_type_vals_ext);
offset += 2;
proto_tree_add_item(desc_tree, hf_as_ep_desc_subtype,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
else
return 0;
return desc_len;
}
static int
dissect_usb_audio_bulk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data)
{
usb_conv_info_t *usb_conv_info;
proto_tree *tree = NULL;
gint offset;
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
case AUDIO_IF_SUBCLASS_MIDISTREAMING:
offset = 0;
col_set_str(pinfo->cinfo, COL_INFO, "USB-MIDI Event Packets");
while (offset > 0 && (guint) offset < length)
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
{ &hf_ac_if_desc_subtype,
{ "Subtype", "usbaudio.ac_if_subtype", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&ac_subtype_vals_ext, 0x00, "bDescriptorSubtype", HFILL }},
{ &hf_ac_if_hdr_ver,
{ "Version", "usbaudio.ac_if_hdr.bcdADC",
FT_DOUBLE, BASE_NONE, NULL, 0, "bcdADC", HFILL }},
{ &hf_ac_if_hdr_total_len,
{ "Total length", "usbaudio.ac_if_hdr.wTotalLength",
FT_UINT16, BASE_DEC, NULL, 0x00, "wTotalLength", HFILL }},
{ &hf_ac_if_hdr_bInCollection,
{ "Total number of interfaces", "usbaudio.ac_if_hdr.bInCollection",
FT_UINT8, BASE_DEC, NULL, 0x00, "bInCollection", HFILL }},
{ &hf_ac_if_hdr_if_num,
{ "Interface number", "usbaudio.ac_if_hdr.baInterfaceNr",
FT_UINT8, BASE_DEC, NULL, 0x00, "baInterfaceNr", HFILL }},
{ &hf_as_if_desc_subtype,
{ "Subtype", "usbaudio.as_if_subtype", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&as_subtype_vals_ext, 0x00, "bDescriptorSubtype", HFILL }},
{ &hf_as_if_gen_term_id,
{ "Terminal ID", "usbaudio.as_if_gen.bTerminalLink",
FT_UINT8, BASE_DEC, NULL, 0x00, "bTerminalLink", HFILL }},
{ &hf_as_if_gen_delay,
{ "Interface delay in frames", "usbaudio.as_if_gen.bDelay",
FT_UINT8, BASE_DEC, NULL, 0x00, "bDelay", HFILL }},
{ &hf_as_if_gen_format,
{ "Format", "usbaudio.as_if_gen.wFormatTag",
FT_UINT16, BASE_HEX, NULL, 0x00, "wFormatTag", HFILL }},
{ &hf_as_ep_desc_subtype,
{ "Subtype", "usbaudio.as_ep_subtype", FT_UINT8,
BASE_HEX, NULL, 0x00, "bDescriptorSubtype", HFILL }},
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
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }}
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
expert_module_t *expert_usb_audio;
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
