static inline gboolean
is_sysex_code(guint8 code)
{
return (code == 0x04 || code == 0x05 || code == 0x06 || code == 0x07);
}
static gboolean
is_last_sysex_packet_in_tvb(tvbuff_t *tvb, gint offset)
{
gboolean last = TRUE;
gint length = tvb_reported_length(tvb);
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
usb_conv_info->class_data_type = USB_CONV_AUDIO;
} else if (usb_conv_info->class_data_type != USB_CONV_AUDIO) {
return 0;
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
dissect_ac_if_input_terminal(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, usb_conv_info_t *usb_conv_info _U_)
{
gint offset_start;
static const int *input_channelconfig[] = {
&hf_ac_if_input_channelconfig_d0,
&hf_ac_if_input_channelconfig_d1,
&hf_ac_if_input_channelconfig_d2,
&hf_ac_if_input_channelconfig_d3,
&hf_ac_if_input_channelconfig_d4,
&hf_ac_if_input_channelconfig_d5,
&hf_ac_if_input_channelconfig_d6,
&hf_ac_if_input_channelconfig_d7,
&hf_ac_if_input_channelconfig_d8,
&hf_ac_if_input_channelconfig_d9,
&hf_ac_if_input_channelconfig_d10,
&hf_ac_if_input_channelconfig_d11,
&hf_ac_if_input_channelconfig_rsv,
NULL
};
offset_start = offset;
proto_tree_add_item(tree, hf_ac_if_input_terminalid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ac_if_input_terminaltype, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ac_if_input_assocterminal, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ac_if_input_nrchannels, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_ac_if_input_channelconfig, ett_ac_if_input_channelconfig, input_channelconfig, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ac_if_input_channelnames, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ac_if_input_terminal, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset-offset_start;
}
static gint
dissect_ac_if_output_terminal(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, usb_conv_info_t *usb_conv_info _U_)
{
gint offset_start;
offset_start = offset;
proto_tree_add_item(tree, hf_ac_if_output_terminalid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ac_if_output_terminaltype, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ac_if_output_assocterminal, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ac_if_output_sourceid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ac_if_output_terminal, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset-offset_start;
}
static gint
dissect_ac_if_feature_unit(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, usb_conv_info_t *usb_conv_info _U_, guint8 desc_len)
{
gint offset_start;
guint8 controlsize;
proto_tree *bitmap_tree;
proto_item *ti;
static const int *fu_controls0[] = {
&hf_ac_if_fu_controls_d0,
&hf_ac_if_fu_controls_d1,
&hf_ac_if_fu_controls_d2,
&hf_ac_if_fu_controls_d3,
&hf_ac_if_fu_controls_d4,
&hf_ac_if_fu_controls_d5,
&hf_ac_if_fu_controls_d6,
&hf_ac_if_fu_controls_d7,
NULL };
static const int *fu_controls1[] = {
&hf_ac_if_fu_controls_d8,
&hf_ac_if_fu_controls_d9,
&hf_ac_if_fu_controls_rsv,
NULL };
offset_start = offset;
proto_tree_add_item(tree, hf_ac_if_fu_unitid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ac_if_fu_sourceid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ac_if_fu_controlsize, tvb, offset, 1, ENC_LITTLE_ENDIAN);
controlsize = tvb_get_guint8(tvb, offset) + 1;
offset += 1;
ti = proto_tree_add_item(tree, hf_ac_if_fu_controls, tvb, offset, controlsize, ENC_NA);
bitmap_tree = proto_item_add_subtree(ti, ett_ac_if_fu_controls);
proto_tree_add_bitmask(bitmap_tree, tvb, offset, hf_ac_if_fu_control, ett_ac_if_fu_controls0, fu_controls0, ENC_LITTLE_ENDIAN);
if(controlsize >= 1){
proto_tree_add_bitmask(bitmap_tree, tvb, offset + 1, hf_ac_if_fu_control, ett_ac_if_fu_controls1, fu_controls1, ENC_LITTLE_ENDIAN);
}
offset += controlsize;
if(offset < desc_len){
proto_tree_add_item(tree, hf_ac_if_fu_ifeature, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
return offset-offset_start;
}
static gint
dissect_ac_if_mixed_unit(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, usb_conv_info_t *usb_conv_info _U_)
{
gint offset_start;
guint8 nrinpins;
static const int *mu_channelconfig[] = {
&hf_ac_if_mu_channelconfig_d0,
&hf_ac_if_mu_channelconfig_d1,
&hf_ac_if_mu_channelconfig_d2,
&hf_ac_if_mu_channelconfig_d3,
&hf_ac_if_mu_channelconfig_d4,
&hf_ac_if_mu_channelconfig_d5,
&hf_ac_if_mu_channelconfig_d6,
&hf_ac_if_mu_channelconfig_d7,
&hf_ac_if_mu_channelconfig_d8,
&hf_ac_if_mu_channelconfig_d9,
&hf_ac_if_mu_channelconfig_d10,
&hf_ac_if_mu_channelconfig_d11,
&hf_ac_if_mu_channelconfig_rsv,
NULL
};
offset_start = offset;
proto_tree_add_item(tree, hf_ac_if_mu_unitid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ac_if_mu_nrinpins, tvb, offset, 1, ENC_LITTLE_ENDIAN);
nrinpins = tvb_get_guint8(tvb, offset);
offset += 1;
while(nrinpins){
proto_tree_add_item(tree, hf_ac_if_mu_sourceid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
nrinpins--;
offset += 1;
}
proto_tree_add_item(tree, hf_ac_if_mu_nrchannels, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_ac_if_mu_channelconfig, ett_ac_if_mu_channelconfig, mu_channelconfig, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ac_if_mu_channelnames, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ac_if_mu_controls, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ac_if_mu_imixer, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
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
dissect_as_if_format_type_body(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, usb_conv_info_t *usb_conv_info)
{
audio_conv_info_t *audio_conv_info;
gint offset_start;
guint8 SamFreqType;
guint8 format_type;
audio_conv_info = (audio_conv_info_t *)usb_conv_info->class_data;
if (!audio_conv_info)
return 0;
offset_start = offset;
proto_tree_add_item(tree, hf_as_if_ft_formattype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
format_type = tvb_get_guint8(tvb, offset);
offset++;
switch(format_type){
case 1:
proto_tree_add_item(tree, hf_as_if_ft_nrchannels, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_as_if_ft_subframesize, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_as_if_ft_bitresolution, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_as_if_ft_samfreqtype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
SamFreqType = tvb_get_guint8(tvb, offset);
offset++;
if(SamFreqType == 0){
proto_tree_add_item(tree, hf_as_if_ft_lowersamfreq, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_as_if_ft_uppersamfreq, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
}else {
while(SamFreqType){
proto_tree_add_item(tree, hf_as_if_ft_samfreq, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
SamFreqType--;
}
}
break;
case 2:
proto_tree_add_item(tree, hf_as_if_ft_maxbitrate, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_as_if_ft_samplesperframe, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_as_if_ft_samfreqtype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
SamFreqType = tvb_get_guint8(tvb, offset);
offset++;
if(SamFreqType == 0){
proto_tree_add_item(tree, hf_as_if_ft_lowersamfreq, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_as_if_ft_uppersamfreq, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
}else {
while(SamFreqType){
proto_tree_add_item(tree, hf_as_if_ft_samfreq, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
SamFreqType--;
}
}
break;
default:
break;
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
case AC_SUBTYPE_INPUT_TERMINAL:
dissect_ac_if_input_terminal(tvb, offset, pinfo, desc_tree, usb_conv_info);
break;
case AC_SUBTYPE_OUTPUT_TERMINAL:
dissect_ac_if_output_terminal(tvb, offset, pinfo, desc_tree, usb_conv_info);
break;
case AC_SUBTYPE_MIXER_UNIT:
dissect_ac_if_mixed_unit(tvb, offset, pinfo, desc_tree, usb_conv_info);
break;
case AC_SUBTYPE_FEATURE_UNIT:
dissect_ac_if_feature_unit(tvb, offset, pinfo, desc_tree, usb_conv_info, desc_len);
break;
default:
proto_tree_add_expert(desc_tree, pinfo, &ei_usb_audio_undecoded, tvb, offset-3, desc_len);
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
case AS_SUBTYPE_FORMAT_TYPE:
dissect_as_if_format_type_body(tvb, offset, pinfo,
desc_tree, usb_conv_info);
break;
default:
proto_tree_add_expert(desc_tree, pinfo, &ei_usb_audio_undecoded, tvb, offset-3, desc_len);
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
proto_tree *tree;
proto_item *ti;
gint offset, length;
gint i;
if (data == NULL)
return 0;
usb_conv_info = (usb_conv_info_t *)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBAUDIO");
ti = proto_tree_add_protocol_format(parent_tree, proto_usb_audio, tvb, 0, -1, "USB Audio");
tree = proto_item_add_subtree(ti, ett_usb_audio);
length = tvb_reported_length(tvb);
offset = 0;
switch (usb_conv_info->interfaceSubclass)
{
case AUDIO_IF_SUBCLASS_MIDISTREAMING:
col_set_str(pinfo->cinfo, COL_INFO, "USB-MIDI Event Packets");
for (i = 0; i < length / 4; i++)
{
dissect_usb_midi_event(tvb, pinfo, tree, parent_tree, offset);
offset += 4;
}
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_usb_audio_undecoded, tvb, offset, length);
}
return length;
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
{ &hf_ac_if_input_terminalid,
{ "Terminal ID", "usbaudio.ac_if_input.bTerminalID",
FT_UINT8, BASE_DEC, NULL, 0x00, "bTerminalID", HFILL }},
{ &hf_ac_if_input_terminaltype,
{ "Terminal Type", "usbaudio.ac_if_input.wTerminalType", FT_UINT16,
BASE_HEX|BASE_EXT_STRING, &terminal_types_vals_ext, 0x00, "wTerminalType", HFILL }},
{ &hf_ac_if_input_assocterminal,
{ "Assoc Terminal", "usbaudio.ac_if_input.bAssocTerminal",
FT_UINT8, BASE_DEC, NULL, 0x00, "bAssocTerminal", HFILL }},
{ &hf_ac_if_input_nrchannels,
{ "Number Channels", "usbaudio.ac_if_input.bNrChannels",
FT_UINT8, BASE_DEC, NULL, 0x00, "bNrChannels", HFILL }},
{ &hf_ac_if_input_channelconfig,
{ "Channel Config", "usbaudio.ac_if_input.wChannelConfig",
FT_UINT16, BASE_HEX, NULL, 0x00, "wChannelConfig", HFILL }},
{ &hf_ac_if_input_channelconfig_d0,
{ "Left Front", "usbaudio.ac_if_input.wChannelConfig.d0",
FT_BOOLEAN, 16, NULL, 0x0001, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_d1,
{ "Right Front", "usbaudio.ac_if_input.wChannelConfig.d1",
FT_BOOLEAN, 16, NULL, 0x0002, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_d2,
{ "Center Front", "usbaudio.ac_if_input.wChannelConfig.d2",
FT_BOOLEAN, 16, NULL, 0x0004, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_d3,
{ "Low Frequency Enhancement", "usbaudio.ac_if_input.wChannelConfig.d3",
FT_BOOLEAN, 16, NULL, 0x0008, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_d4,
{ "Left Surround", "usbaudio.ac_if_input.wChannelConfig.d4",
FT_BOOLEAN, 16, NULL, 0x0010, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_d5,
{ "Right Surround", "usbaudio.ac_if_input.wChannelConfig.d5",
FT_BOOLEAN, 16, NULL, 0x0020, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_d6,
{ "Left of Center", "usbaudio.ac_if_input.wChannelConfig.d6",
FT_BOOLEAN, 16, NULL, 0x0040, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_d7,
{ "Right of Center", "usbaudio.ac_if_input.wChannelConfig.d7",
FT_BOOLEAN, 16, NULL, 0x0080, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_d8,
{ "Surround", "usbaudio.ac_if_input.wChannelConfig.d8",
FT_BOOLEAN, 16, NULL, 0x0100, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_d9,
{ "Side Left", "usbaudio.ac_if_input.wChannelConfig.d9",
FT_BOOLEAN, 16, NULL, 0x0200, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_d10,
{ "Side Right", "usbaudio.ac_if_input.wChannelConfig.d10",
FT_BOOLEAN, 16, NULL, 0x0400, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_d11,
{ "Top", "usbaudio.ac_if_input.wChannelConfig.d11",
FT_BOOLEAN, 16, NULL, 0x0800, NULL, HFILL }},
{ &hf_ac_if_input_channelconfig_rsv,
{ "Reserved", "usbaudio.ac_if_input.wChannelConfig.rsv",
FT_UINT16, BASE_HEX, NULL, 0xF000, NULL, HFILL }},
{ &hf_ac_if_input_channelnames,
{ "Channel Names", "usbaudio.ac_if_input.iChannelNames",
FT_UINT8, BASE_DEC, NULL, 0x00, "iChannelNames", HFILL }},
{ &hf_ac_if_input_terminal,
{ "Terminal", "usbaudio.ac_if_input.iTerminal",
FT_UINT8, BASE_DEC, NULL, 0x00, "iTerminal", HFILL }},
{ &hf_ac_if_output_terminalid,
{ "Terminal ID", "usbaudio.ac_if_output.bTerminalID",
FT_UINT8, BASE_DEC, NULL, 0x00, "bTerminalID", HFILL }},
{ &hf_ac_if_output_terminaltype,
{ "Terminal Type", "usbaudio.ac_if_output.wTerminalType", FT_UINT16,
BASE_HEX|BASE_EXT_STRING, &terminal_types_vals_ext, 0x00, "wTerminalType", HFILL }},
{ &hf_ac_if_output_assocterminal,
{ "Assoc Terminal", "usbaudio.ac_if_output.bAssocTerminal",
FT_UINT8, BASE_DEC, NULL, 0x00, "bAssocTerminal", HFILL }},
{ &hf_ac_if_output_sourceid,
{ "Source ID", "usbaudio.ac_if_output.bSourceID",
FT_UINT8, BASE_DEC, NULL, 0x00, "bSourceID", HFILL }},
{ &hf_ac_if_output_terminal,
{ "Terminal", "usbaudio.ac_if_output.iTerminal",
FT_UINT8, BASE_DEC, NULL, 0x00, "iTerminal", HFILL }},
{ &hf_ac_if_fu_unitid,
{ "Unit ID", "usbaudio.ac_if_fu.bUnitID",
FT_UINT8, BASE_DEC, NULL, 0x00, "bUnitID", HFILL }},
{ &hf_ac_if_fu_sourceid,
{ "Source ID", "usbaudio.ac_if_fu.bSourceID",
FT_UINT8, BASE_DEC, NULL, 0x00, "bSourceID", HFILL }},
{ &hf_ac_if_fu_controlsize,
{ "Control Size", "usbaudio.ac_if_fu.bControlSize",
FT_UINT8, BASE_DEC, NULL, 0x00, "bControlSize", HFILL }},
{ &hf_ac_if_fu_controls,
{ "Controls", "usbaudio.ac_if_fu.bmaControls",
FT_BYTES, BASE_NONE, NULL, 0x00, "bmaControls", HFILL }},
{ &hf_ac_if_fu_control,
{ "Control", "usbaudio.ac_if_fu.bmaControl",
FT_UINT8, BASE_HEX, NULL, 0x00, "bmaControls", HFILL }},
{ &hf_ac_if_fu_controls_d0,
{ "Mute", "usbaudio.ac_if_fu.bmaControls.d0",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ac_if_fu_controls_d1,
{ "Volume", "usbaudio.ac_if_fu.bmaControls.d1",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ac_if_fu_controls_d2,
{ "Bass", "usbaudio.ac_if_fu.bmaControls.d2",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ac_if_fu_controls_d3,
{ "Mid", "usbaudio.ac_if_fu.bmaControls.d3",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ac_if_fu_controls_d4,
{ "Treble", "usbaudio.ac_if_fu.bmaControls.d4",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ac_if_fu_controls_d5,
{ "Graphic Equalizer", "usbaudio.ac_if_fu.bmaControls.d5",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ac_if_fu_controls_d6,
{ "Automatic Gain", "usbaudio.ac_if_fu.bmaControls.d6",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ac_if_fu_controls_d7,
{ "Delay", "usbaudio.ac_if_fu.bmaControls.d7",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ac_if_fu_controls_d8,
{ "Bass Boost", "usbaudio.ac_if_fu.bmaControls.d8",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ac_if_fu_controls_d9,
{ "Loudness", "usbaudio.ac_if_fu.bmaControls.d9",
FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ac_if_fu_controls_rsv,
{ "Reserved", "usbaudio.ac_if_fu.bmaControls.rsv",
FT_UINT8, BASE_HEX, NULL, 0xFC, "Must be zero", HFILL }},
{ &hf_ac_if_fu_ifeature,
{ "Feature", "usbaudio.ac_if_fu.iFeature",
FT_UINT8, BASE_DEC, NULL, 0x00, "iFeature", HFILL }},
{ &hf_ac_if_mu_unitid,
{ "Unit ID", "usbaudio.ac_if_mu.bUnitID",
FT_UINT8, BASE_DEC, NULL, 0x00, "bUnitID", HFILL }},
{ &hf_ac_if_mu_nrinpins,
{ "Number In Pins", "usbaudio.ac_if_mu.bNrInPins",
FT_UINT8, BASE_DEC, NULL, 0x00, "bNrInPins", HFILL }},
{ &hf_ac_if_mu_sourceid,
{ "Source ID", "usbaudio.ac_if_mu.baSourceID",
FT_UINT8, BASE_DEC, NULL, 0x00, "baSourceID", HFILL }},
{ &hf_ac_if_mu_nrchannels,
{ "Number Channels", "usbaudio.ac_if_mu.bNrChannels",
FT_UINT8, BASE_DEC, NULL, 0x00, "bNrChannels", HFILL }},
{ &hf_ac_if_mu_channelconfig,
{ "Channel Config", "usbaudio.ac_if_mu.wChannelConfig",
FT_UINT16, BASE_HEX, NULL, 0x00, "wChannelConfig", HFILL }},
{ &hf_ac_if_mu_channelconfig_d0,
{ "Left Front", "usbaudio.ac_if_mu.wChannelConfig.d0",
FT_BOOLEAN, 16, NULL, 0x0001, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_d1,
{ "Right Front", "usbaudio.ac_if_mu.wChannelConfig.d1",
FT_BOOLEAN, 16, NULL, 0x0002, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_d2,
{ "Center Front", "usbaudio.ac_if_mu.wChannelConfig.d2",
FT_BOOLEAN, 16, NULL, 0x0004, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_d3,
{ "Low Frequency Enhancement", "usbaudio.ac_if_mu.wChannelConfig.d3",
FT_BOOLEAN, 16, NULL, 0x0008, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_d4,
{ "Left Surround", "usbaudio.ac_if_mu.wChannelConfig.d4",
FT_BOOLEAN, 16, NULL, 0x0010, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_d5,
{ "Right Surround", "usbaudio.ac_if_mu.wChannelConfig.d5",
FT_BOOLEAN, 16, NULL, 0x0020, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_d6,
{ "Left of Center", "usbaudio.ac_if_mu.wChannelConfig.d6",
FT_BOOLEAN, 16, NULL, 0x0040, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_d7,
{ "Right of Center", "usbaudio.ac_if_mu.wChannelConfig.d7",
FT_BOOLEAN, 16, NULL, 0x0080, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_d8,
{ "Surround", "usbaudio.ac_if_mu.wChannelConfig.d8",
FT_BOOLEAN, 16, NULL, 0x0100, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_d9,
{ "Side Left", "usbaudio.ac_if_mu.wChannelConfig.d9",
FT_BOOLEAN, 16, NULL, 0x0200, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_d10,
{ "Side Right", "usbaudio.ac_if_mu.wChannelConfig.d10",
FT_BOOLEAN, 16, NULL, 0x0400, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_d11,
{ "Top", "usbaudio.ac_if_mu.wChannelConfig.d11",
FT_BOOLEAN, 16, NULL, 0x0800, NULL, HFILL }},
{ &hf_ac_if_mu_channelconfig_rsv,
{ "Reserved", "usbaudio.ac_if_mu.wChannelConfig.rsv",
FT_UINT16, BASE_HEX, NULL, 0xF000, NULL, HFILL }},
{ &hf_ac_if_mu_channelnames,
{ "Channel Names", "usbaudio.ac_if_mu.iChannelNames",
FT_UINT8, BASE_DEC, NULL, 0x00, "iChannelNames", HFILL }},
{ &hf_ac_if_mu_controls,
{ "Controls", "usbaudio.ac_if_mu.bmControls",
FT_UINT8, BASE_HEX, NULL, 0x00, "bmControls", HFILL }},
{ &hf_ac_if_mu_imixer,
{ "Mixer", "usbaudio.ac_if_mu.iMixer",
FT_UINT8, BASE_DEC, NULL, 0x00, "iMixer", HFILL }},
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
{ &hf_as_if_ft_formattype,
{ "FormatType", "usbaudio.as_if_ft.bFormatType",
FT_UINT8, BASE_DEC, NULL, 0x00, "wFormatType", HFILL }},
{ &hf_as_if_ft_maxbitrate,
{ "Max Bit Rate", "usbaudio.as_if_ft.wMaxBitRate",
FT_UINT16, BASE_DEC, NULL, 0x00, "wMaxBitRate", HFILL }},
{ &hf_as_if_ft_nrchannels,
{ "Number Channels", "usbaudio.as_if_ft.bNrChannels",
FT_UINT8, BASE_DEC, NULL, 0x00, "bNrChannels", HFILL }},
{ &hf_as_if_ft_subframesize,
{ "Subframe Size", "usbaudio.as_if_ft.bSubframeSize",
FT_UINT8, BASE_DEC, NULL, 0x00, "bSubframeSize", HFILL }},
{ &hf_as_if_ft_bitresolution,
{ "Bit Resolution", "usbaudio.as_if_ft.bBitResolution",
FT_UINT8, BASE_DEC, NULL, 0x00, "bBitResolution", HFILL }},
{ &hf_as_if_ft_samplesperframe,
{ "Samples Per Frame", "usbaudio.as_if_ft.wSamplesPerFrame",
FT_UINT16, BASE_DEC, NULL, 0x00, "wSamplesPerFrame", HFILL }},
{ &hf_as_if_ft_samfreqtype,
{ "Samples Frequence Type", "usbaudio.as_if_ft.bSamFreqType",
FT_UINT8, BASE_DEC, NULL, 0x00, "bSamFreqType", HFILL }},
{ &hf_as_if_ft_lowersamfreq,
{ "Lower Samples Frequence", "usbaudio.as_if_ft.tLowerSamFreq",
FT_UINT24, BASE_DEC, NULL, 0x00, "tLowerSamFreq", HFILL }},
{ &hf_as_if_ft_uppersamfreq,
{ "Upper Samples Frequence", "usbaudio.as_if_ft.tUpperSamFreq",
FT_UINT24, BASE_DEC, NULL, 0x00, "tUpperSamFreq", HFILL }},
{ &hf_as_if_ft_samfreq,
{ "Samples Frequence", "usbaudio.as_if_ft.tSamFreq",
FT_UINT24, BASE_DEC, NULL, 0x00, "tSamFreq", HFILL }},
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
&ett_sysex_msg_fragments,
&ett_ac_if_fu_controls,
&ett_ac_if_fu_controls0,
&ett_ac_if_fu_controls1,
&ett_ac_if_input_channelconfig,
&ett_ac_if_mu_channelconfig
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
reassembly_table_register(&midi_data_reassembly_table,
&addresses_reassembly_table_functions);
usb_audio_bulk_handle = register_dissector("usbaudio", dissect_usb_audio_bulk, proto_usb_audio);
}
void
proto_reg_handoff_usb_audio(void)
{
dissector_handle_t usb_audio_descr_handle;
usb_audio_descr_handle = create_dissector_handle(
dissect_usb_audio_descriptor, proto_usb_audio);
dissector_add_uint("usb.descriptor", IF_CLASS_AUDIO, usb_audio_descr_handle);
dissector_add_uint("usb.bulk", IF_CLASS_AUDIO, usb_audio_bulk_handle);
sysex_handle = find_dissector_add_dependency("sysex", proto_usb_audio);
}
