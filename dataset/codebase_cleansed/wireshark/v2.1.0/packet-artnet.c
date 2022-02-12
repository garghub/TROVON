static guint
dissect_artnet_poll(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_artnet_poll_talktome,
ett_artnet_poll_talktome,
artnet_poll_talktome_fields,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_poll_diag_priority, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static guint
dissect_artnet_poll_reply(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree *hi, *si, *ti;
proto_item *tf;
guint16 universe,uni_port;
proto_tree_add_item(tree, hf_artnet_poll_reply_ip_address, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_artnet_poll_reply_port_nr, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_artnet_poll_reply_versinfo, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_artnet_poll_reply_netswitch, tvb,
offset, 1, ENC_BIG_ENDIAN);
universe = (tvb_get_guint8(tvb, offset) & 0x7F) << 8;
offset += 1;
proto_tree_add_item(tree, hf_artnet_poll_reply_subswitch, tvb,
offset, 1, ENC_BIG_ENDIAN);
universe |= tvb_get_guint8(tvb, offset) & 0xF0;
offset += 1;
proto_tree_add_item(tree, hf_artnet_poll_reply_oem, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_artnet_poll_reply_ubea_version, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_artnet_poll_reply_status,
ett_artnet_poll_reply_status,
artnet_poll_reply_status_fields,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_poll_reply_esta_man, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_artnet_poll_reply_short_name,
tvb, offset, 18, ENC_ASCII|ENC_NA);
offset += 18;
proto_tree_add_item(tree, hf_artnet_poll_reply_long_name,
tvb, offset, 64, ENC_ASCII|ENC_NA);
offset += 64;
proto_tree_add_item(tree, hf_artnet_poll_reply_node_report,
tvb, offset, 64, ENC_ASCII|ENC_NA);
offset += 64;
hi = proto_tree_add_item(tree,
hf_artnet_poll_reply_port_info,
tvb,
offset,
ARTNET_POLL_REPLY_PORT_INFO_LENGTH,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
proto_tree_add_item(si, hf_artnet_poll_reply_num_ports, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
hi = proto_tree_add_item(si,
hf_artnet_poll_reply_port_types,
tvb,
offset,
ARTNET_POLL_REPLY_PORT_TYPES_LENGTH,
ENC_NA);
ti = proto_item_add_subtree(hi, ett_artnet);
proto_tree_add_item(ti, hf_artnet_poll_reply_port_types_1, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti, hf_artnet_poll_reply_port_types_2, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti, hf_artnet_poll_reply_port_types_3, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti, hf_artnet_poll_reply_port_types_4, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
hi = proto_tree_add_item(si,
hf_artnet_poll_reply_good_input,
tvb,
offset,
ARTNET_POLL_REPLY_GOOD_INPUT_LENGTH,
ENC_NA);
ti = proto_item_add_subtree(hi, ett_artnet);
proto_tree_add_bitmask(ti, tvb, offset, hf_artnet_poll_reply_good_input_1,
ett_artnet_poll_reply_good_input_1,
artnet_poll_reply_good_input_fields,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(ti, tvb, offset, hf_artnet_poll_reply_good_input_2,
ett_artnet_poll_reply_good_input_2,
artnet_poll_reply_good_input_fields,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(ti, tvb, offset, hf_artnet_poll_reply_good_input_3,
ett_artnet_poll_reply_good_input_3,
artnet_poll_reply_good_input_fields,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(ti, tvb, offset, hf_artnet_poll_reply_good_input_4,
ett_artnet_poll_reply_good_input_4,
artnet_poll_reply_good_input_fields,
ENC_BIG_ENDIAN);
offset += 1;
hi = proto_tree_add_item(si,
hf_artnet_poll_reply_good_output,
tvb,
offset,
ARTNET_POLL_REPLY_GOOD_OUTPUT_LENGTH,
ENC_NA);
ti = proto_item_add_subtree(hi, ett_artnet);
proto_tree_add_bitmask(ti, tvb, offset, hf_artnet_poll_reply_good_output_1,
ett_artnet_poll_reply_good_output_1,
artnet_poll_reply_good_output_fields,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(ti, tvb, offset, hf_artnet_poll_reply_good_output_2,
ett_artnet_poll_reply_good_output_2,
artnet_poll_reply_good_output_fields,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(ti, tvb, offset, hf_artnet_poll_reply_good_output_3,
ett_artnet_poll_reply_good_output_3,
artnet_poll_reply_good_output_fields,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(ti, tvb, offset, hf_artnet_poll_reply_good_output_4,
ett_artnet_poll_reply_good_output_4,
artnet_poll_reply_good_output_fields,
ENC_BIG_ENDIAN);
offset += 1;
hi = proto_tree_add_item(si,
hf_artnet_poll_reply_swin,
tvb,
offset,
ARTNET_POLL_REPLY_SWIN_LENGTH,
ENC_NA);
ti = proto_item_add_subtree(hi, ett_artnet);
proto_tree_add_item(ti, hf_artnet_poll_reply_swin_1, tvb,
offset, 1, ENC_BIG_ENDIAN);
uni_port = tvb_get_guint8(tvb, offset) & 0x0F;
tf = proto_tree_add_uint(ti,hf_artnet_poll_reply_swin_1_universe,tvb,
offset, 0, universe | uni_port);
PROTO_ITEM_SET_GENERATED(tf);
offset += 1;
proto_tree_add_item(ti, hf_artnet_poll_reply_swin_2, tvb,
offset, 1, ENC_BIG_ENDIAN);
uni_port = tvb_get_guint8(tvb, offset) & 0x0F;
tf = proto_tree_add_uint(ti,hf_artnet_poll_reply_swin_2_universe,tvb,
offset, 0, universe | uni_port);
PROTO_ITEM_SET_GENERATED(tf);
offset += 1;
proto_tree_add_item(ti, hf_artnet_poll_reply_swin_3, tvb,
offset, 1, ENC_BIG_ENDIAN);
uni_port = tvb_get_guint8(tvb, offset) & 0x0F;
tf = proto_tree_add_uint(ti,hf_artnet_poll_reply_swin_3_universe,tvb,
offset, 0, universe | uni_port);
PROTO_ITEM_SET_GENERATED(tf);
offset += 1;
proto_tree_add_item(ti, hf_artnet_poll_reply_swin_4, tvb,
offset, 1, ENC_BIG_ENDIAN);
uni_port = tvb_get_guint8(tvb, offset) & 0x0F;
tf = proto_tree_add_uint(ti,hf_artnet_poll_reply_swin_4_universe,tvb,
offset, 0, universe | uni_port);
PROTO_ITEM_SET_GENERATED(tf);
offset += 1;
hi = proto_tree_add_item(si,
hf_artnet_poll_reply_swout,
tvb,
offset,
ARTNET_POLL_REPLY_SWOUT_LENGTH,
ENC_NA);
ti = proto_item_add_subtree(hi, ett_artnet);
proto_tree_add_item(ti, hf_artnet_poll_reply_swout_1, tvb,
offset, 1, ENC_BIG_ENDIAN);
uni_port = tvb_get_guint8(tvb, offset) & 0x0F;
tf = proto_tree_add_uint(ti,hf_artnet_poll_reply_swout_1_universe,tvb,
offset, 0, universe | uni_port);
PROTO_ITEM_SET_GENERATED(tf);
offset += 1;
proto_tree_add_item(ti, hf_artnet_poll_reply_swout_2, tvb,
offset, 1, ENC_BIG_ENDIAN);
uni_port = tvb_get_guint8(tvb, offset) & 0x0F;
tf = proto_tree_add_uint(ti,hf_artnet_poll_reply_swout_2_universe,tvb,
offset, 0, universe | uni_port);
PROTO_ITEM_SET_GENERATED(tf);
offset += 1;
proto_tree_add_item(ti, hf_artnet_poll_reply_swout_3, tvb,
offset, 1, ENC_BIG_ENDIAN);
uni_port = tvb_get_guint8(tvb, offset) & 0x0F;
tf = proto_tree_add_uint(ti,hf_artnet_poll_reply_swout_3_universe,tvb,
offset, 0, universe | uni_port);
PROTO_ITEM_SET_GENERATED(tf);
offset += 1;
proto_tree_add_item(ti, hf_artnet_poll_reply_swout_4, tvb,
offset, 1, ENC_BIG_ENDIAN);
uni_port = tvb_get_guint8(tvb, offset) & 0x0F;
tf = proto_tree_add_uint(ti,hf_artnet_poll_reply_swout_4_universe,tvb,
offset, 0, universe | uni_port);
PROTO_ITEM_SET_GENERATED(tf);
offset += 1;
proto_tree_add_item(tree, hf_artnet_poll_reply_swvideo, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_poll_reply_swmacro, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_poll_reply_swremote, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_poll_reply_style, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_artnet_poll_reply_mac,
tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_artnet_poll_reply_bind_ip_address, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_artnet_poll_reply_bind_index, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_artnet_poll_reply_status2,
ett_artnet_poll_reply_status2,
artnet_poll_reply_status2_fields,
ENC_BIG_ENDIAN);
offset += 1;
if (offset < tvb_reported_length(tvb))
{
proto_tree_add_item(tree, hf_artnet_filler, tvb, offset, -1, ENC_NA);
offset = tvb_reported_length(tvb);
}
return offset;
}
static guint
dissect_artnet_output(tvbuff_t *tvb, guint offset, proto_tree *tree, packet_info *pinfo, proto_tree* base_tree)
{
tvbuff_t *next_tvb;
guint16 length;
guint size;
gboolean save_info;
proto_tree_add_item(tree, hf_artnet_output_sequence, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_output_physical, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_output_universe, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_artnet_output_length, tvb,
offset, 2, length);
offset += 2;
size = tvb_reported_length_remaining(tvb, offset);
save_info = col_get_writable(pinfo->cinfo);
col_set_writable(pinfo->cinfo, FALSE);
next_tvb = tvb_new_subset_length(tvb, offset, length);
call_dissector(dmx_chan_handle, next_tvb, pinfo, base_tree);
col_set_writable(pinfo->cinfo, save_info);
return offset + size;
}
static guint
dissect_artnet_address(tvbuff_t *tvb, guint offset, proto_tree *tree) {
proto_tree *hi, *si, *ti;
guint8 net, sub;
net = tvb_get_guint8(tvb, offset);
if (net == 0x00 || net == 0x7F) {
proto_tree_add_uint(tree,hf_artnet_address_netswitch_special, tvb,
offset, 0, net);
} else {
proto_tree_add_bitmask_text(tree, tvb, offset, 1, "NetSwitch: ",
"NetSwitch Error: ", ett_artnet_address_netswitch,
artnet_address_netswitch_fields, ENC_BIG_ENDIAN, 0);
}
offset += 1;
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_address_short_name,
tvb, offset, 18, ENC_ASCII|ENC_NA);
offset += 18;
proto_tree_add_item(tree, hf_artnet_address_long_name,
tvb, offset, 64, ENC_ASCII|ENC_NA);
offset += 64;
hi = proto_tree_add_item(tree,
hf_artnet_address_swin,
tvb,
offset,
ARTNET_ADDRESS_SWIN_LENGTH,
ENC_NA);
ti = proto_item_add_subtree(hi, ett_artnet);
proto_tree_add_item(ti, hf_artnet_address_swin_1, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti, hf_artnet_address_swin_2, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti, hf_artnet_address_swin_3, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ti, hf_artnet_address_swin_4, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
hi = proto_tree_add_item(tree,
hf_artnet_address_swout,
tvb,
offset,
ARTNET_ADDRESS_SWOUT_LENGTH,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
proto_tree_add_item(si, hf_artnet_address_swout_1, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(si, hf_artnet_address_swout_2, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(si, hf_artnet_address_swout_3, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(si, hf_artnet_address_swout_4, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
sub = tvb_get_guint8(tvb, offset);
if (sub == 0x00 || sub == 0x7F) {
proto_tree_add_uint(tree,hf_artnet_address_subswitch_special, tvb,
offset, 0, sub);
} else {
proto_tree_add_bitmask_text(tree, tvb, offset, 1, "SubSwitch: ",
"SubSwitch Error: ", ett_artnet_address_subswitch,
artnet_address_subswitch_fields, ENC_BIG_ENDIAN, 0);
}
offset += 1;
proto_tree_add_item(tree, hf_artnet_address_swvideo, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_address_command, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static guint
dissect_artnet_input(tvbuff_t *tvb, guint offset, proto_tree *tree) {
proto_tree *hi, *si;
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_artnet_input_num_ports, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
hi = proto_tree_add_item(tree,
hf_artnet_input_input,
tvb,
offset,
ARTNET_INPUT_INPUT_LENGTH,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
proto_tree_add_item(si, hf_artnet_input_input_1, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(si, hf_artnet_input_input_2, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(si, hf_artnet_input_input_3, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(si, hf_artnet_input_input_4, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static guint
dissect_artnet_video_setup(tvbuff_t *tvb, guint offset, proto_tree *tree ) {
guint32 size;
guint8 font_height, last_font;
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_artnet_video_setup_control, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
font_height = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_artnet_video_setup_font_height, tvb,
offset, 1, font_height);
offset += 1;
proto_tree_add_item(tree, hf_artnet_video_setup_first_font, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
last_font = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_artnet_video_setup_last_font, tvb,
offset, 1, last_font);
offset += 1;
proto_tree_add_item(tree, hf_artnet_video_setup_win_font_name,
tvb, offset, 64, ENC_ASCII|ENC_NA);
offset += 64;
size = last_font * font_height;
proto_tree_add_item(tree, hf_artnet_video_setup_font_data, tvb,
offset, size, ENC_NA );
offset += size;
return offset;
}
static guint
dissect_artnet_video_palette(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_artnet_video_palette_colour_red, tvb,
offset, 17, ENC_NA );
offset += 17;
proto_tree_add_item(tree, hf_artnet_video_palette_colour_green, tvb,
offset, 17, ENC_NA );
offset += 17;
proto_tree_add_item(tree, hf_artnet_video_palette_colour_blue, tvb,
offset, 17, ENC_NA );
offset += 17;
return offset;
}
static guint
dissect_artnet_video_data(tvbuff_t *tvb, guint offset, proto_tree *tree) {
guint8 len_x, len_y;
guint32 size;
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_artnet_video_data_pos_x, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_video_data_pos_y, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len_x = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_artnet_video_data_len_x, tvb,
offset, 1, len_x);
offset += 1;
len_y = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_artnet_video_data_len_y, tvb,
offset, 1, len_y);
offset += 1;
size = len_x * len_y * 2;
proto_tree_add_item(tree, hf_artnet_video_data_data, tvb,
offset, size, ENC_NA );
offset += size;
return offset;
}
static guint
dissect_artnet_firmware_master(tvbuff_t *tvb, guint offset, proto_tree *tree ) {
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_artnet_firmware_master_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_firmware_master_block_id, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_firmware_master_length, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 20, ENC_NA );
offset += 20;
proto_tree_add_item(tree, hf_artnet_firmware_master_data, tvb,
offset, 1024, ENC_NA );
offset += 1024;
return offset;
}
static guint
dissect_artnet_firmware_reply(tvbuff_t *tvb, guint offset, proto_tree *tree) {
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_artnet_firmware_reply_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 21, ENC_NA );
offset += 21;
return offset;
}
static guint
dissect_artnet_tod_request(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint8 ad_count;
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 7, ENC_NA);
offset += 7;
proto_tree_add_item(tree, hf_artnet_tod_request_net, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_tod_request_command, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ad_count = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_artnet_tod_request_ad_count, tvb,
offset, 1, ad_count);
offset += 1;
proto_tree_add_item(tree, hf_artnet_tod_request_address, tvb,
offset, ad_count, ENC_NA);
offset += ad_count;
return offset;
}
static guint
dissect_artnet_tod_data(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint16 universe;
proto_item *tf;
guint8 i, uid_count;
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_tod_data_port, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 7, ENC_NA);
offset += 7;
proto_tree_add_item(tree, hf_artnet_tod_data_net, tvb,
offset, 1, ENC_BIG_ENDIAN);
universe = (tvb_get_guint8(tvb, offset) & 0x7F) << 8;
offset += 1;
proto_tree_add_item(tree, hf_artnet_tod_data_command_response, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_tod_data_address, tvb,
offset, 1, ENC_BIG_ENDIAN);
universe |= tvb_get_guint8(tvb, offset);
tf = proto_tree_add_uint(tree,hf_artnet_tod_control_universe,tvb,
offset, 0, universe);
PROTO_ITEM_SET_GENERATED(tf);
offset += 1;
proto_tree_add_item(tree, hf_artnet_tod_data_uid_total, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_artnet_tod_data_block_count, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
uid_count = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_artnet_tod_data_uid_count, tvb,
offset, 1, uid_count);
offset += 1;
for( i = 0; i < uid_count; i++)
{
proto_tree_add_item(tree, hf_artnet_tod_data_tod, tvb,
offset, 6, ENC_NA);
offset += 6;
}
return offset;
}
static guint
dissect_artnet_tod_control(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint16 universe;
proto_item *tf;
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 7, ENC_NA);
offset += 7;
proto_tree_add_item(tree, hf_artnet_tod_control_net, tvb,
offset, 1, ENC_BIG_ENDIAN);
universe = (tvb_get_guint8(tvb, offset) & 0x7F) << 8;
offset += 1;
proto_tree_add_item(tree, hf_artnet_tod_control_command, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_tod_control_address, tvb,
offset, 1, ENC_BIG_ENDIAN);
universe |= tvb_get_guint8(tvb, offset);
tf = proto_tree_add_uint(tree,hf_artnet_tod_control_universe,tvb,
offset, 0, universe);
PROTO_ITEM_SET_GENERATED(tf);
offset += 1;
return offset;
}
static guint
dissect_artnet_rdm(tvbuff_t *tvb, guint offset, proto_tree *tree, packet_info *pinfo, proto_tree *base_tree)
{
guint16 universe;
proto_item *tf;
guint8 rdmver;
guint8 sc;
guint size;
gboolean save_info;
tvbuff_t *next_tvb;
rdmver = tvb_get_guint8(tvb, offset);
if (rdmver == 0x00) {
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 8, ENC_NA);
offset += 8;
universe = 0;
} else {
proto_tree_add_item(tree, hf_artnet_rdm_rdmver, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 7, ENC_NA);
offset += 7;
proto_tree_add_item(tree, hf_artnet_rdm_net, tvb,
offset, 1, ENC_BIG_ENDIAN);
universe = (tvb_get_guint8(tvb, offset) & 0x7F) << 8;
offset += 1;
}
proto_tree_add_item(tree, hf_artnet_rdm_command, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_rdm_address, tvb,
offset, 1, ENC_BIG_ENDIAN);
universe |= tvb_get_guint8(tvb, offset);
tf = proto_tree_add_uint(tree,hf_artnet_tod_control_universe,tvb,
offset, 0, universe);
PROTO_ITEM_SET_GENERATED(tf);
offset += 1;
sc = tvb_get_guint8(tvb, offset);
if (sc == 0xCC) {
proto_tree_add_item(tree, hf_artnet_rdm_sc, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
size = tvb_reported_length_remaining(tvb, offset);
save_info = col_get_writable(pinfo->cinfo);
col_set_writable(pinfo->cinfo, FALSE);
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(rdm_handle, next_tvb, pinfo, base_tree);
col_set_writable(pinfo->cinfo, save_info);
return offset + size;
}
static guint
dissect_artnet_rdm_sub(tvbuff_t *tvb, guint offset, proto_tree *tree, packet_info *pinfo _U_)
{
guint8 cc;
gint size;
proto_tree_add_item(tree, hf_artnet_rdm_rdmver, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_rdm_sub_uid, tvb,
offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 1, ENC_NA);
offset += 1;
cc = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_artnet_rdm_sub_command_class, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_rdm_sub_pid, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_artnet_rdm_sub_sub_device, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_artnet_rdm_sub_sub_count, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 4, ENC_NA);
offset += 4;
switch (cc) {
case ARTNET_CC_SET_COMMAND:
case ARTNET_CC_GET_COMMAND_RESPONSE:
size = tvb_reported_length_remaining(tvb, offset);
proto_tree_add_item(tree, hf_artnet_rdm_sub_data, tvb,
offset, size, ENC_NA);
offset += size;
break;
case ARTNET_CC_DISCOVERY_COMMAND:
case ARTNET_CC_DISCOVERY_COMMAND_RESPONSE:
case ARTNET_CC_GET_COMMAND:
case ARTNET_CC_SET_COMMAND_RESPONSE:
default:
break;
}
return offset;
}
static guint
dissect_artnet_ip_prog(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_artnet_ip_prog_command,
ett_artnet_ip_prog_command,
artnet_ip_prog_command_fields,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_ip_prog_ip, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_artnet_ip_prog_sm, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_artnet_ip_prog_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 8, ENC_NA);
offset += 8;
return offset;
}
static guint
dissect_artnet_ip_prog_reply(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_artnet_ip_prog_reply_ip, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_artnet_ip_prog_reply_sm, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_artnet_ip_prog_reply_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_artnet_ip_prog_reply_status,
ett_artnet_ip_prog_reply_status,
artnet_ip_prog_reply_status_fields,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_artnet_spare, tvb,
offset, 7, ENC_NA);
offset += 7;
return offset;
}
static guint
dissect_artnet_poll_fp_reply(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_diag_data(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
guint16 length;
proto_tree_add_item(tree, hf_artnet_filler, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_diag_data_priority, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_diag_data_index, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_artnet_diag_data_length, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_artnet_diag_data_data, tvb,
offset, length, ENC_ASCII|ENC_NA);
offset += length;
return offset;
}
static guint
dissect_artnet_command(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_media(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_media_patch(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_media_control(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_media_control_reply(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_time_code(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_time_sync(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_trigger(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_directory(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_artnet_directory_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_artnet_directory_cmd, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_directory_file, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static guint
dissect_artnet_directory_reply(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_artnet_directory_reply_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_artnet_directory_reply_flags, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_directory_reply_file, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_artnet_directory_reply_name, tvb,
offset, 16, ENC_ASCII|ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_artnet_directory_reply_desc, tvb,
offset, 64, ENC_ASCII|ENC_NA);
offset += 64;
proto_tree_add_item(tree, hf_artnet_directory_reply_length, tvb,
offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_artnet_directory_reply_data, tvb,
offset, 64, ENC_NA);
offset += 64;
return offset;
}
static guint
dissect_artnet_mac_master(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_mac_slave(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_file_tn_master(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_artnet_file_tn_master_filler, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_artnet_file_tn_master_type, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_file_tn_master_block_id, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_artnet_file_tn_master_length, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_artnet_file_tn_master_name, tvb,
offset, 14, ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(tree, hf_artnet_file_tn_master_checksum, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_artnet_file_tn_master_spare, tvb,
offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_artnet_file_tn_master_data, tvb,
offset, 512, ENC_NA);
offset += 512;
return offset;
}
static guint
dissect_artnet_file_fn_master(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static guint
dissect_artnet_file_fn_reply(tvbuff_t *tvb _U_, guint offset, proto_tree *tree _U_)
{
return offset;
}
static int
dissect_artnet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
gint offset = 0;
guint size;
guint16 opcode;
proto_tree *ti = NULL, *hi = NULL, *si = NULL, *artnet_tree = NULL, *artnet_header_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ARTNET");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_artnet, tvb, offset, -1, ENC_NA);
artnet_tree = proto_item_add_subtree(ti, ett_artnet);
hi = proto_tree_add_item(artnet_tree,
hf_artnet_header,
tvb,
offset,
ARTNET_HEADER_LENGTH ,
ENC_NA);
artnet_header_tree = proto_item_add_subtree(hi, ett_artnet);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s",
tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 8, ENC_ASCII|ENC_NA));
if (tree) {
proto_tree_add_item(artnet_header_tree, hf_artnet_header_id,
tvb, offset, 8, ENC_ASCII|ENC_NA);
}
offset += 8;
opcode = tvb_get_letohs(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s (0x%04x)",
val_to_str_ext_const(opcode, &artnet_opcode_vals_ext, "Unknown"), opcode);
if (tree) {
proto_tree_add_uint(artnet_header_tree, hf_artnet_header_opcode, tvb,
offset, 2, opcode);
proto_item_append_text(ti, ", Opcode: %s (0x%04x)", val_to_str_ext_const(opcode, &artnet_opcode_vals_ext, "Unknown"), opcode);
}
offset += 2;
if (opcode != ARTNET_OP_POLL_REPLY && opcode != ARTNET_OP_POLL_FP_REPLY) {
if (tree) {
proto_tree_add_item(artnet_header_tree, hf_artnet_header_protver, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_item_set_len(artnet_header_tree, ARTNET_HEADER_LENGTH+2 );
}
offset += 2;
}
switch (opcode) {
case ARTNET_OP_POLL:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_poll,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_poll( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_POLL_REPLY:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_poll_reply,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_poll_reply( tvb, offset, si);
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_POLL_FP_REPLY:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_poll_fp_reply,
tvb,
offset,
0,
ENC_NA );
si = proto_item_add_subtree(hi, ett_artnet );
size = dissect_artnet_poll_fp_reply( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size );
offset += size;
}
break;
case ARTNET_OP_DIAG_DATA:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_diag_data,
tvb,
offset,
0,
ENC_NA );
si = proto_item_add_subtree(hi, ett_artnet );
size = dissect_artnet_diag_data( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size );
offset += size;
}
break;
case ARTNET_OP_COMMAND:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_command,
tvb,
offset,
0,
ENC_NA );
si = proto_item_add_subtree(hi, ett_artnet );
size = dissect_artnet_command( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size );
offset += size;
}
break;
case ARTNET_OP_OUTPUT:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_output,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_output( tvb, offset, si, pinfo, tree);
size -= offset;
proto_item_set_len(si, size );
offset += size;
}
break;
case ARTNET_OP_ADDRESS:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_address,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_address( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_INPUT:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_input,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_input( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_TOD_REQUEST:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_tod_request,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_tod_request( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_TOD_DATA:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_tod_data,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet );
size = dissect_artnet_tod_data( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size );
offset += size;
}
break;
case ARTNET_OP_TOD_CONTROL:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_tod_control,
tvb,
offset,
0,
ENC_NA );
si = proto_item_add_subtree(hi, ett_artnet );
size = dissect_artnet_tod_control( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size );
offset += size;
}
break;
case ARTNET_OP_RDM:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_rdm,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_rdm(tvb, offset, si, pinfo, tree);
size -= offset;
proto_item_set_len( si, size );
offset += size;
}
break;
case ARTNET_OP_RDM_SUB:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_rdm_sub,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_rdm_sub( tvb, offset, si, pinfo );
size -= offset;
proto_item_set_len( si, size );
offset += size;
}
break;
case ARTNET_OP_MEDIA:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_media,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_media( tvb, offset, si);
size -= offset;
proto_item_set_len( si, size );
offset += size;
}
break;
case ARTNET_OP_MEDIA_PATCH:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_media_patch,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_media_patch( tvb, offset, si);
size -= offset;
proto_item_set_len( si, size );
offset += size;
}
break;
case ARTNET_OP_MEDIA_CONTROL:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_media_control,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_media_control( tvb, offset, si);
size -= offset;
proto_item_set_len( si, size );
offset += size;
}
break;
case ARTNET_OP_MEDIA_CONTRL_REPLY:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_media_control_reply,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_media_control_reply( tvb, offset, si);
size -= offset;
proto_item_set_len( si, size );
offset += size;
}
break;
case ARTNET_OP_TIME_CODE:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_time_code,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_time_code( tvb, offset, si);
size -= offset;
proto_item_set_len( si, size );
offset += size;
}
break;
case ARTNET_OP_TIME_SYNC:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_time_sync,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_time_sync( tvb, offset, si);
size -= offset;
proto_item_set_len( si, size );
offset += size;
}
break;
case ARTNET_OP_TRIGGER:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_trigger,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_trigger( tvb, offset, si);
size -= offset;
proto_item_set_len( si, size );
offset += size;
}
break;
case ARTNET_OP_DIRECTORY:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_directory,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_directory( tvb, offset, si);
size -= offset;
proto_item_set_len( si, size );
offset += size;
}
break;
case ARTNET_OP_DIRECTORY_REPLY:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_directory_reply,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_directory_reply( tvb, offset, si);
size -= offset;
proto_item_set_len( si, size );
offset += size;
}
break;
case ARTNET_OP_VIDEO_SETUP:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_input,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_video_setup( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_VIDEO_PALETTE:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_input,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_video_palette( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_VIDEO_DATA:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_input,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_video_data( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_MAC_MASTER:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_mac_master,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_mac_master( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_MAC_SLAVE:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_mac_slave,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_mac_slave( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_FIRMWARE_MASTER:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_firmware_master,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_firmware_master( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_FIRMWARE_REPLY:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_firmware_reply,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet);
size = dissect_artnet_firmware_reply( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size);
offset += size;
}
break;
case ARTNET_OP_FILE_TN_MASTER:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_file_tn_master,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet );
size = dissect_artnet_file_tn_master( tvb, offset, si);
size -= offset;
proto_item_set_len(si, size );
offset += size;
}
break;
case ARTNET_OP_FILE_FN_MASTER:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_file_fn_master,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet );
size = dissect_artnet_file_fn_master( tvb, offset, si);
size -= offset;
proto_item_set_len(si, size );
offset += size;
}
break;
case ARTNET_OP_FILE_FN_REPLY:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_file_fn_reply,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet );
size = dissect_artnet_file_fn_reply( tvb, offset, si);
size -= offset;
proto_item_set_len(si, size );
offset += size;
}
break;
case ARTNET_OP_IP_PROG:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_ip_prog,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet );
size = dissect_artnet_ip_prog( tvb,offset, si);
size -= offset;
proto_item_set_len(si, size );
offset += size;
}
break;
case ARTNET_OP_IP_PROG_REPLY:
if (tree) {
hi = proto_tree_add_item(artnet_tree,
hf_artnet_ip_prog_reply,
tvb,
offset,
0,
ENC_NA);
si = proto_item_add_subtree(hi, ett_artnet );
size = dissect_artnet_ip_prog_reply( tvb, offset, si );
size -= offset;
proto_item_set_len(si, size );
offset += size;
}
break;
default:
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(artnet_tree, hf_artnet_data, tvb, offset, -1, ENC_NA);
}
return tvb_captured_length(tvb);
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(artnet_tree, hf_artnet_excess_bytes, tvb,
offset, -1, ENC_NA);
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_artnet_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint64 qword;
if (tvb_captured_length(tvb) < 8)
return FALSE;
qword = tvb_get_ntoh64(tvb,0);
if(qword != G_GUINT64_CONSTANT (0x4172742d4e657400))
return FALSE;
dissect_artnet(tvb, pinfo, tree, data);
return TRUE;
}
void
proto_register_artnet(void) {
static hf_register_info hf[] = {
{ &hf_artnet_excess_bytes,
{ "Excess Bytes",
"artnet.excess_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_data,
{ "Data",
"artnet.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_filler,
{ "filler",
"artnet.filler",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_spare,
{ "spare",
"artnet.spare",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_header,
{ "Descriptor Header",
"artnet.header",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net Descriptor Header", HFILL }},
{ &hf_artnet_header_id,
{ "ID",
"artnet.header.id",
FT_STRING, BASE_NONE, NULL, 0x0,
"ArtNET ID", HFILL }},
{ &hf_artnet_header_opcode,
{ "OpCode",
"artnet.header.opcode",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &artnet_opcode_vals_ext, 0x0,
"Art-Net message type", HFILL }},
{ &hf_artnet_header_protver,
{ "ProtVer",
"artnet.header.protver",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Protocol revision number", HFILL }},
{ &hf_artnet_poll,
{ "ArtPoll packet",
"artnet.poll",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtPoll packet", HFILL }},
{ &hf_artnet_poll_talktome,
{ "TalkToMe",
"artnet.poll.talktome",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_talktome_reply_change,
{ "Send me ArtPollReply on change",
"artnet.poll.talktome_reply_change",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x02,
NULL, HFILL }},
{ &hf_artnet_poll_talktome_diag,
{ "Send diagnostics messages",
"artnet.poll.talktome_diag",
FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled), 0x04,
NULL, HFILL }},
{ &hf_artnet_poll_talktome_diag_unicast,
{ "Send diagnostics unicast",
"artnet.poll.talktome_diag_unicast",
FT_UINT8, BASE_HEX, VALS(artnet_talktome_diag_unicast_vals), 0x08,
NULL, HFILL }},
{ &hf_artnet_poll_diag_priority,
{ "Priority",
"artnet.poll.diag_priority",
FT_UINT8, BASE_DEC, VALS(artnet_talktome_diag_priority_vals), 0x0,
"Minimum diagnostics message priority", HFILL }},
{ &hf_artnet_poll_reply,
{ "ArtPollReply packet",
"artnet.poll_reply",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtPollReply packet", HFILL }},
{ &hf_artnet_poll_reply_ip_address,
{ "IP Address",
"artnet.poll_reply.ip_address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_port_nr,
{ "Port number",
"artnet.poll_reply.port_nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_versinfo,
{ "Version Info",
"artnet.poll_reply.versinfo",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_netswitch,
{ "NetSwitch",
"artnet.poll_reply.netswitch",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Bits 14-8 of port address", HFILL }},
{ &hf_artnet_poll_reply_subswitch,
{ "SubSwitch",
"artnet.poll_reply.subswitch",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Bits 7-4 of port address", HFILL }},
{ &hf_artnet_poll_reply_oem,
{ "Oem",
"artnet.poll_reply.oem",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &artnet_oem_code_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_ubea_version,
{ "UBEA Version",
"artnet.poll_reply.ubea_version",
FT_UINT8, BASE_DEC, NULL, 0x0,
"UBEA version number", HFILL }},
{ &hf_artnet_poll_reply_status,
{ "Status",
"artnet.poll_reply.status",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_status_ubea_present,
{ "Ubea Present",
"artnet.poll_reply.ubea_present",
FT_BOOLEAN, 8, TFS(&tfs_present_absent), 0x01,
NULL, HFILL }},
{ &hf_artnet_poll_reply_status_rdm_supported,
{ "RDM Supported",
"artnet.poll_reply.rdm_supported",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02,
NULL, HFILL }},
{ &hf_artnet_poll_reply_status_rom_booted,
{ "ROM Booted",
"artnet.poll_reply.rom_booted",
FT_UINT8, BASE_HEX, NULL, 0x04,
NULL, HFILL }},
{ &hf_artnet_poll_reply_status_port_prog,
{ "Port Address Programming Authority",
"artnet.poll_reply.port_prog",
FT_UINT8, BASE_HEX, VALS(artnet_port_prog_auth_vals), 0x30,
NULL, HFILL }},
{ &hf_artnet_poll_reply_status_indicator,
{ "Indicator State",
"artnet.poll_reply.indicator",
FT_UINT8, BASE_HEX, VALS(artnet_indicator_state_vals), 0xC0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_esta_man,
{ "ESTA Code",
"artnet.poll_reply.esta_man",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &artnet_esta_man_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_short_name,
{ "Short Name",
"artnet.poll_reply.short_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_long_name,
{ "Long Name",
"artnet.poll_reply.long_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_node_report,
{ "Node Report",
"artnet.poll_reply.node_report",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_port_info,
{ "Port Info",
"artnet.poll_reply.port_info",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_num_ports,
{ "Number of Ports",
"artnet.poll_reply.num_ports",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_port_types,
{ "Port Types",
"artnet.poll_reply.port_types",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_port_types_1,
{ "Type of Port 1",
"artnet.poll_reply.port_types_1",
FT_UINT8, BASE_HEX, VALS(artnet_port_type_vals), 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_port_types_2,
{ "Type of Port 2",
"artnet.poll_reply.port_types_2",
FT_UINT8, BASE_HEX, VALS(artnet_port_type_vals), 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_port_types_3,
{ "Type of Port 3",
"artnet.poll_reply.port_types_3",
FT_UINT8, BASE_HEX, VALS(artnet_port_type_vals), 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_port_types_4,
{ "Type of Port 4",
"artnet.poll_reply.port_types_4",
FT_UINT8, BASE_HEX, VALS(artnet_port_type_vals), 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_input,
{ "Input Status",
"artnet.poll_reply.good_input",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_input_1,
{ "Input status of Port 1",
"artnet.poll_reply.good_input_1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_input_recv_error,
{ "Receive errors detected",
"artnet.poll_reply.good_input_recv_error",
FT_UINT8, BASE_HEX, NULL, 0x04,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_input_disabled,
{ "Input is disabled",
"artnet.poll_reply.good_input_disabled",
FT_UINT8, BASE_HEX, NULL, 0x08,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_input_dmx_text,
{ "DMX text packets supported",
"artnet.poll_reply.good_input_dmx_text",
FT_UINT8, BASE_HEX, NULL, 0x010,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_input_dmx_sip,
{ "DMX SIPs supported",
"artnet.poll_reply.good_input_dmx_sip",
FT_UINT8, BASE_HEX, NULL, 0x20,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_input_dmx_test,
{ "DMX test packets supported",
"artnet.poll_reply.good_input_dmx_text",
FT_UINT8, BASE_HEX, NULL, 0x40,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_input_data,
{ "Data received",
"artnet.poll_reply.good_input_data",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_input_2,
{ "Input status of Port 2",
"artnet.poll_reply.good_input_2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_input_3,
{ "Input status of Port 3",
"artnet.poll_reply.good_input_3",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_input_4,
{ "Input status of Port 4",
"artnet.poll_reply.good_input_4",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_output,
{ "Output Status",
"artnet.poll_reply.good_output",
FT_NONE, BASE_NONE, NULL, 0,
"Port output status", HFILL }},
{ &hf_artnet_poll_reply_good_output_1,
{ "Output status of Port 1",
"artnet.poll_reply.good_output_1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_output_merge_ltp,
{ "Merge mode is LTP",
"artnet.poll_reply.good_output_merge_ltp",
FT_UINT8, BASE_HEX, NULL, 0x02,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_output_short,
{ "DMX output short circuit",
"artnet.poll_reply.good_output_short",
FT_UINT8, BASE_HEX, NULL, 0x04,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_output_merge_artnet,
{ "Merging Art-Net data",
"artnet.poll_reply.good_output_merge_artnet",
FT_UINT8, BASE_HEX, NULL, 0x08,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_output_dmx_text,
{ "DMX text packets supported",
"artnet.poll_reply.good_output_dmx_text",
FT_UINT8, BASE_HEX, NULL, 0x10,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_output_dmx_sip,
{ "DMX SIPs supported",
"artnet.poll_reply.good_output_dmx_sip",
FT_UINT8, BASE_HEX, NULL, 0x20,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_output_dmx_test,
{ "DMX test packets supported",
"artnet.poll_reply.good_output_dmx_test",
FT_UINT8, BASE_HEX, NULL, 0x40,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_output_data,
{ "Data transmitted",
"artnet.poll_reply.good_output_data",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_output_2,
{ "Output status of Port 2",
"artnet.poll_reply.good_output_2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_output_3,
{ "Output status of Port 3",
"artnet.poll_reply.good_output_3",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_good_output_4,
{ "Output status of Port 4",
"artnet.poll_reply.good_output_4",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Outpus status of Port 4", HFILL }},
{ &hf_artnet_poll_reply_swin,
{ "Input Subswitch",
"artnet.poll_reply.swin",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swin_1,
{ "Input Subswitch of Port 1",
"artnet.poll_reply.swin_1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swin_2,
{ "Input Subswitch of Port 2",
"artnet.poll_reply.swin_2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swin_3,
{ "Input Subswitch of Port 3",
"artnet.poll_reply.swin_3",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swin_4,
{ "Input Subswitch of Port 4",
"artnet.poll_reply.swin_4",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swin_1_universe,
{ "Universe of input port 1",
"artnet.poll_reply.swin_1_universe",
FT_UINT16, BASE_DEC,NULL, 0x0,
NULL,HFILL }},
{ &hf_artnet_poll_reply_swin_2_universe,
{ "Universe of input port 2",
"artnet.poll_reply.swin_2_universe",
FT_UINT16, BASE_DEC,NULL, 0x0,
NULL,HFILL }},
{ &hf_artnet_poll_reply_swin_3_universe,
{ "Universe of input port 3",
"artnet.poll_reply.swin_3_universe",
FT_UINT16, BASE_DEC,NULL, 0x0,
NULL,HFILL }},
{ &hf_artnet_poll_reply_swin_4_universe,
{ "Universe of input port 4",
"artnet.poll_reply.swin_4_universe",
FT_UINT16, BASE_DEC,NULL, 0x0,
NULL,HFILL }},
{ &hf_artnet_poll_reply_swout,
{ "Output Subswitch",
"artnet.poll_reply.swout",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swout_1,
{ "Output Subswitch of Port 1",
"artnet.poll_reply.swout_1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swout_2,
{ "Output Subswitch of Port 2",
"artnet.poll_reply.swout_2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swout_3,
{ "Output Subswitch of Port 3",
"artnet.poll_reply.swout_3",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swout_4,
{ "Output Subswitch of Port 4",
"artnet.poll_reply.swout_4",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swout_1_universe,
{ "Universe of output port 1",
"artnet.poll_reply.swout_1_universe",
FT_UINT16, BASE_DEC,NULL, 0x0,
NULL,HFILL }},
{ &hf_artnet_poll_reply_swout_2_universe,
{ "Universe of output port 2",
"artnet.poll_reply.swout_2_universe",
FT_UINT16, BASE_DEC,NULL, 0x0,
NULL,HFILL }},
{ &hf_artnet_poll_reply_swout_3_universe,
{ "Universe of output port 3",
"artnet.poll_reply.swout_3_universe",
FT_UINT16, BASE_DEC,NULL, 0x0,
NULL,HFILL }},
{ &hf_artnet_poll_reply_swout_4_universe,
{ "Universe of output port 4",
"artnet.poll_reply.swout_4_universe",
FT_UINT16, BASE_DEC,NULL, 0x0,
NULL,HFILL }},
{ &hf_artnet_poll_reply_swvideo,
{ "SwVideo",
"artnet.poll_reply.swvideo",
FT_UINT8, BASE_HEX, VALS(vals_artnet_poll_reply_swvideo), 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swmacro,
{ "SwMacro",
"artnet.poll_reply.swmacro",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_swremote,
{ "SwRemote",
"artnet.poll_reply.swremote",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_style,
{ "Style",
"artnet.poll_reply.style",
FT_UINT8, BASE_HEX, VALS(vals_artnet_poll_reply_style), 0x0,
"Equipment style", HFILL }},
{ &hf_artnet_poll_reply_mac,
{ "MAC",
"artnet.poll_reply.mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_bind_ip_address,
{ "Bind IP Address",
"artnet.poll_reply.bind_ip_address",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IP address of root device", HFILL }},
{ &hf_artnet_poll_reply_bind_index,
{ "Bind Index",
"artnet.poll_reply.bind_index",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_status2,
{ "Status2",
"artnet.poll_reply.status2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_poll_reply_status2_web_supported,
{ "Web configuration supported",
"artnet.poll_reply.websupport",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01,
NULL, HFILL }},
{ &hf_artnet_poll_reply_status2_dhcp_used,
{ "DHCP configuration used",
"artnet.poll_reply.dhcpused",
FT_BOOLEAN, 8, TFS(&tfs_used_notused), 0x02,
NULL, HFILL }},
{ &hf_artnet_poll_reply_status2_dhcp_supported,
{ "DHCP configuration supported",
"artnet.poll_reply.dhcpsupport",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }},
{ &hf_artnet_poll_reply_status2_bigaddr_supported,
{ "Port-Address size",
"artnet.poll_reply.addrsupport",
FT_UINT8, BASE_HEX, VALS(artnet_poll_reply_status2_bigaddr_supported_vals), 0x08,
NULL, HFILL }},
{ &hf_artnet_output,
{ "ArtDMX packet",
"artnet.output",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtDMX packet", HFILL }},
{ &hf_artnet_output_sequence,
{ "Sequence",
"artnet.output.sequence",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_output_physical,
{ "Physical",
"artnet.output.physical",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_output_universe,
{ "Universe",
"artnet.output.universe",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_output_length,
{ "Length",
"artnet.output.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address,
{ "ArtAddress packet",
"artnet.address",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtAddress packet", HFILL }},
{ &hf_artnet_address_netswitch_special,
{ "NetSwitch",
"artnet.address.netswitch_special",
FT_UINT8, BASE_HEX, VALS(artnet_address_switch_vals), 0,
NULL, HFILL }},
{ &hf_artnet_address_netswitch_net,
{ "Net",
"artnet.address.netswitch_net",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }},
{ &hf_artnet_address_netswitch_write,
{ "Write Net",
"artnet.address.netswitch_write",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_artnet_address_short_name,
{ "Short Name",
"artnet.address.short_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address_long_name,
{ "Long Name",
"artnet.address.long_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address_swin,
{ "Input Subswitch",
"artnet.address.swin",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_artnet_address_swin_1,
{ "Input Subswitch of Port 1",
"artnet.address.swin_1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address_swin_2,
{ "Input Subswitch of Port 2",
"artnet.address.swin_2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address_swin_3,
{ "Input Subswitch of Port 3",
"artnet.address.swin_3",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address_swin_4,
{ "Input Subswitch of Port 4",
"artnet.address.swin_4",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address_swout,
{ "Output Subswitch",
"artnet.address.swout",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_artnet_address_swout_1,
{ "Output Subswitch of Port 1",
"artnet.address.swout_1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address_swout_2,
{ "Output Subswitch of Port 2",
"artnet.address.swout_2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address_swout_3,
{ "Output Subswitch of Port 3",
"artnet.address.swout_3",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address_swout_4,
{ "Output Subswitch of Port 4",
"artnet.address.swout_4",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address_subswitch_special,
{ "NetSwitch",
"artnet.address.subswitch_special",
FT_UINT8, BASE_HEX, VALS(artnet_address_switch_vals), 0,
NULL, HFILL }},
{ &hf_artnet_address_subswitch_sub,
{ "Sub-Net",
"artnet.address.subswitch_sub",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }},
{ &hf_artnet_address_subswitch_write,
{ "Write Sub-Net",
"artnet.address.subswitch_write",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_artnet_address_swvideo,
{ "SwVideo",
"artnet.address.swvideo",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_address_command,
{ "Command",
"artnet.address.command",
FT_UINT8, BASE_HEX, VALS(artnet_address_command_vals), 0x0,
NULL, HFILL }},
{ &hf_artnet_input,
{ "ArtInput packet",
"artnet.input",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtInput packet", HFILL }},
{ &hf_artnet_input_num_ports,
{ "Number of Ports",
"artnet.input.num_ports",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_input_input,
{ "Port Status",
"artnet.input.input",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_artnet_input_input_1,
{ "Status of Port 1",
"artnet.input.input_1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_input_input_2,
{ "Status of Port 2",
"artnet.input.input_2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_input_input_3,
{ "Status of Port 3",
"artnet.input.input_3",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_input_input_4,
{ "Status of Port 4",
"artnet.input.input_4",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_firmware_master,
{ "ArtFirmwareMaster packet",
"artnet.firmware_master",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtFirmwareMaster packet", HFILL }},
{ &hf_artnet_firmware_master_type,
{ "Type",
"artnet.firmware_master.type",
FT_UINT8, BASE_HEX, VALS(artnet_firmware_master_type_vals), 0x0,
"Number of Ports", HFILL }},
{ &hf_artnet_firmware_master_block_id,
{ "Block ID",
"artnet.firmware_master.block_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_firmware_master_length,
{ "Length",
"artnet.firmware_master.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_firmware_master_data,
{ "data",
"artnet.firmware_master.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_firmware_reply,
{ "ArtFirmwareReply packet",
"artnet.firmware_reply",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtFirmwareReply packet", HFILL }},
{ &hf_artnet_firmware_reply_type,
{ "Type",
"artnet.firmware_reply.type",
FT_UINT8, BASE_HEX, VALS(artnet_firmware_reply_type_vals), 0x0,
"Number of Ports", HFILL }},
{ &hf_artnet_video_setup_control,
{ "control",
"artnet.video_setup.control",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_setup_font_height,
{ "Font Height",
"artnet.video_setup.font_height",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_setup_first_font,
{ "First Font",
"artnet.video_setup.first_font",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_setup_last_font,
{ "Last Font",
"artnet.video_setup.last_font",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_setup_win_font_name,
{ "Windows Font Name",
"artnet.video_setup.win_font_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_setup_font_data,
{ "Font data",
"artnet.video_setup.font_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Font Date", HFILL }},
{ &hf_artnet_video_palette_colour_red,
{ "Colour Red",
"artnet.video_palette.colour_red",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_palette_colour_green,
{ "Colour Green",
"artnet.video_palette.colour_green",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_palette_colour_blue,
{ "Colour Blue",
"artnet.video_palette.colour_blue",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_data_pos_x,
{ "PosX",
"artnet.video_data.pos_x",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_data_pos_y,
{ "PosY",
"artnet.video_data.pos_y",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_data_len_x,
{ "LenX",
"artnet.video_data.len_x",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_data_len_y,
{ "LenY",
"artnet.video_data.len_y",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_video_data_data,
{ "Video Data",
"artnet.video_data.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_request,
{ "ArtTodRequest packet",
"artnet.tod_request",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtTodRequest packet", HFILL }},
{ &hf_artnet_tod_request_net,
{ "Net",
"artnet.tod_request.net",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_request_command,
{ "Command",
"artnet.tod_request.command",
FT_UINT8, BASE_HEX, VALS(artnet_tod_request_command_vals), 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_request_ad_count,
{ "Address Count",
"artnet.tod_request.ad_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_request_address,
{ "Address",
"artnet.tod_request.address",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_data,
{ "ArtTodData packet",
"artnet.tod_data",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtTodData packet", HFILL }},
{ &hf_artnet_tod_data_port,
{ "Port",
"artnet.tod_data.port",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_data_net,
{ "Net",
"artnet.tod_data.net",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_data_command_response,
{ "Command Response",
"artnet.tod_data.command_response",
FT_UINT8, BASE_HEX, VALS(artnet_tod_data_command_vals), 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_data_address,
{ "Address",
"artnet.tod_data.address",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_data_uid_total,
{ "UID Total",
"artnet.tod_data.uid_total",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_data_block_count,
{ "Block Count",
"artnet.tod_data.block_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_data_uid_count,
{ "UID Count",
"artnet.tod_data.uid_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_data_tod,
{ "TOD",
"artnet.tod_data.tod",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_control,
{ "ArtTodControl packet",
"artnet.tod_control",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtTodControl packet", HFILL }},
{ &hf_artnet_tod_control_net,
{ "Net",
"artnet.tod_control.net",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Top 7 bits of the port address", HFILL }},
{ &hf_artnet_tod_control_command,
{ "Command",
"artnet.tod_control.command",
FT_UINT8, BASE_HEX, VALS(artnet_tod_control_command_vals), 0x0,
NULL, HFILL }},
{ &hf_artnet_tod_control_address,
{ "Address",
"artnet.tod_control.address",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Lower byte of the port address", HFILL }},
{ &hf_artnet_tod_control_universe,
{ "Universe",
"artnet.tod_control.universe",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_rdm,
{ "ArtRdm packet",
"artnet.rdm",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtRdm packet", HFILL }},
{ &hf_artnet_rdm_command,
{ "Command",
"artnet.rdm.command",
FT_UINT8, BASE_HEX, VALS(artnet_rdm_command_vals), 0x0,
NULL, HFILL }},
{ &hf_artnet_rdm_address,
{ "Address",
"artnet.rdm.address",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_rdm_sc,
{ "Startcode",
"artnet.rdm.sc",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_rdm_rdmver,
{ "RDM Version",
"artnet.rdm.rdmver",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_rdm_net,
{ "Address High",
"artnet.rdm.net",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_rdm_sub,
{ "ArtRdmSub packet",
"artnet.rdm_sub",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtRdmSub packet", HFILL }},
{ &hf_artnet_rdm_sub_uid,
{ "UID",
"artnet.rdm_sub.uid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_rdm_sub_command_class,
{ "Command Class",
"artnet.rdm_sub.command_class",
FT_UINT8, BASE_HEX, VALS(artnet_cc_vals), 0x0,
NULL, HFILL }},
{ &hf_artnet_rdm_sub_pid,
{ "Parameter ID",
"artnet.rdm_sub.param_id",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &rdm_param_id_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_artnet_rdm_sub_sub_device,
{ "Sub Device",
"artnet.rdm_sub.sub_device",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_rdm_sub_sub_count,
{ "Sub Count",
"artnet.rdm_sub.sub_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_rdm_sub_data,
{ "Data",
"artnet.rdm_sub.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_ip_prog,
{ "ArtIpProg packet",
"artnet.ip_prog",
FT_NONE, BASE_NONE, NULL, 0,
"ArtNET ArtIpProg packet", HFILL }},
{ &hf_artnet_ip_prog_command,
{ "Command",
"artnet.ip_prog.command",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_ip_prog_command_prog_port,
{ "Program Port",
"artnet.ip_prog.command_prog_port",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_artnet_ip_prog_command_prog_sm,
{ "Program Subnet Mask",
"artnet.ip_prog.command_prog_sm",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_artnet_ip_prog_command_prog_ip,
{ "Program IP",
"artnet.ip_prog.command_prog_ip",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_artnet_ip_prog_command_reset,
{ "Reset Parameters",
"artnet.ip_prog.command_reset",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_artnet_ip_prog_command_unused,
{ "Unused",
"artnet.ip_prog.command_unused",
FT_UINT8, BASE_HEX, NULL, 0x30,
NULL, HFILL }},
{ &hf_artnet_ip_prog_command_dhcp_enable,
{ "Enable DHCP",
"artnet.ip_prog.command_dhcp_enable",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_artnet_ip_prog_command_prog_enable,
{ "Enable Programming",
"artnet.ip_prog.command_prog_enable",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_artnet_ip_prog_ip,
{ "IP Address",
"artnet.ip_prog.ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_ip_prog_sm,
{ "Subnet Mask",
"artnet.ip_prog.sm",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IP Subnet mask", HFILL }},
{ &hf_artnet_ip_prog_port,
{ "Port",
"artnet.ip_prog.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_ip_prog_reply,
{ "ArtIpProgReply packet",
"artnet.ip_prog_reply",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtIpProgReply packet", HFILL }},
{ &hf_artnet_ip_prog_reply_ip,
{ "IP Address",
"artnet.ip_prog_reply.ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_ip_prog_reply_sm,
{ "Subnet mask",
"artnet.ip_prog_reply.sm",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IP Subnet mask", HFILL }},
{ &hf_artnet_ip_prog_reply_port,
{ "Port",
"artnet.ip_prog_reply.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_ip_prog_reply_status,
{ "Status",
"artnet.ip_prog_reply.status",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_ip_prog_reply_status_unused,
{ "Unused",
"artnet.ip_prog_reply.unused",
FT_UINT8, BASE_HEX, NULL, 0xbf,
NULL, HFILL }},
{ &hf_artnet_ip_prog_reply_status_dhcp_enable,
{ "DHCP Enabled",
"artnet.ip_prog_reply.status_dhcp_enable",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_artnet_poll_fp_reply,
{ "ArtPollFpReply packet",
"artnet.poll_fp_reply",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtPollFpReply packet", HFILL }},
{ &hf_artnet_diag_data,
{ "ArtDiagData packet",
"artnet.diag_data",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtDiagData packet", HFILL }},
{ &hf_artnet_diag_data_priority,
{ "Priotity",
"artnet.diag_data.priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_diag_data_index,
{ "Index",
"artnet.diag_data.index",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_diag_data_length,
{ "Length",
"artnet.diag_data.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_diag_data_data,
{ "Data",
"artnet.diag_data.data",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_command,
{ "ArtCommand packet",
"artnet.command",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtCommand packet", HFILL }},
{ &hf_artnet_media,
{ "ArtMedia packet",
"artnet.media",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtMedia packet", HFILL }},
{ &hf_artnet_media_patch,
{ "ArtMediaPatch packet",
"artnet.media_patch",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtMediaPatch packet", HFILL }},
{ &hf_artnet_media_control,
{ "ArtMediaControl packet",
"artnet.media_control",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtMediaControl packet", HFILL }},
{ &hf_artnet_media_control_reply,
{ "ArtMediaControlReply packet",
"artnet.media_control_reply",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtMediaControlReply packet", HFILL }},
{ &hf_artnet_time_code,
{ "ArtTimeCode packet",
"artnet.time_code",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtTimeCode packet", HFILL }},
{ &hf_artnet_time_sync,
{ "ArtTimeSync packet",
"artnet.time_sync",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtTimeSync packet", HFILL }},
{ &hf_artnet_trigger,
{ "ArtTrigger packet",
"artnet.trigger",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtTrigger packet", HFILL }},
{ &hf_artnet_directory,
{ "ArtDirectory packet",
"artnet.directory",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtDirectory packet", HFILL }},
{ &hf_artnet_directory_filler,
{ "Filler",
"artnet.directory.filler",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_directory_cmd,
{ "Command",
"artnet.directory.cmd",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_directory_file,
{ "File Nr.",
"artnet.directory.file",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_directory_reply,
{ "ArtDirectoryReply packet",
"artnet.directory_reply",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtDirectoryReply packet", HFILL }},
{ &hf_artnet_directory_reply_filler,
{ "Filler",
"artnet.directory_reply.filler",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_directory_reply_flags,
{ "Flags",
"artnet.directory_reply.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_directory_reply_file,
{ "File",
"artnet.directory_reply.file",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_directory_reply_name,
{ "Name",
"artnet.directory_reply.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_directory_reply_desc,
{ "Description",
"artnet.directory_reply.desc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_directory_reply_length,
{ "Length",
"artnet.directory_reply.length",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_directory_reply_data,
{ "Data",
"artnet.directory_reply.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_mac_master,
{ "ArtMacMaster packet",
"artnet.mac_master",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtMacMaster packet", HFILL }},
{ &hf_artnet_mac_slave,
{ "ArtMacSlave packet",
"artnet.mac_slave",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtMacSlave packet", HFILL }},
{ &hf_artnet_file_tn_master,
{ "ArtFileTnMaster packet",
"artnet.file_tn_master",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtFileTnMaster packet", HFILL }},
{ &hf_artnet_file_tn_master_filler,
{ "Filler",
"artnet.file_tn_master.filler",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_file_tn_master_type,
{ "Type",
"artnet.file_tn_master.type",
FT_UINT8, BASE_HEX, VALS(artnet_file_type_vals), 0x0,
NULL, HFILL }},
{ &hf_artnet_file_tn_master_block_id,
{ "Block ID",
"artnet.file_tn_master.block_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_file_tn_master_length,
{ "Length",
"artnet.file_tn_master.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_file_tn_master_name,
{ "Name",
"artnet.file_tn_master.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_file_tn_master_checksum,
{ "Checksum",
"artnet.file_tn_master.checksum",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_file_tn_master_spare,
{ "Spare",
"artnet.file_tn_master.spare",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_file_tn_master_data,
{ "Data",
"artnet.file_tn_master.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_artnet_file_fn_master,
{ "ArtFileFnMaster packet",
"artnet.file_fn_master",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtFileFnMaster packet", HFILL }},
{ &hf_artnet_file_fn_reply,
{ "ArtFileFnReply packet",
"artnet.file_fn_reply",
FT_NONE, BASE_NONE, NULL, 0,
"Art-Net ArtFileFnReply packet", HFILL }}
};
static gint *ett[] = {
&ett_artnet,
&ett_artnet_poll_talktome,
&ett_artnet_poll_reply_status,
&ett_artnet_poll_reply_good_input_1,
&ett_artnet_poll_reply_good_input_2,
&ett_artnet_poll_reply_good_input_3,
&ett_artnet_poll_reply_good_input_4,
&ett_artnet_poll_reply_good_output_1,
&ett_artnet_poll_reply_good_output_2,
&ett_artnet_poll_reply_good_output_3,
&ett_artnet_poll_reply_good_output_4,
&ett_artnet_poll_reply_status2,
&ett_artnet_ip_prog_command,
&ett_artnet_ip_prog_reply_status,
&ett_artnet_address_netswitch,
&ett_artnet_address_subswitch
};
proto_artnet = proto_register_protocol("Art-Net", "ARTNET", "artnet");
proto_register_field_array(proto_artnet, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_artnet(void) {
dissector_handle_t artnet_handle;
artnet_handle = create_dissector_handle(dissect_artnet, proto_artnet);
dissector_add_for_decode_as("udp.port", artnet_handle);
rdm_handle = find_dissector_add_dependency("rdm", proto_artnet);
dmx_chan_handle = find_dissector_add_dependency("dmx-chan", proto_artnet);
heur_dissector_add("udp", dissect_artnet_heur, "ARTNET over UDP", "artnet_udp", proto_artnet, HEURISTIC_ENABLE);
}
