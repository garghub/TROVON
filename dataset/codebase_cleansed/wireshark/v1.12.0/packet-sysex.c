static tvbuff_t *
unpack_digitech_message(tvbuff_t *tvb, gint offset)
{
tvbuff_t *next_tvb;
gint length = tvb_length(tvb);
gint data_len = length - offset - 2;
const guint8* data_ptr;
gint remaining = data_len;
guchar* unpacked;
guchar* unpacked_ptr;
gint unpacked_size;
guint8 msb;
gint i;
unpacked_size = data_len - (data_len / 8);
if (data_len % 8)
{
unpacked_size--;
}
data_ptr = tvb_get_ptr(tvb, offset, data_len);
unpacked = (guchar*)g_malloc(unpacked_size);
unpacked_ptr = unpacked;
while (remaining > 0)
{
msb = *data_ptr++;
remaining--;
for (i = 0; (i < 7) && (remaining > 0); ++i, --remaining)
{
*unpacked_ptr = *data_ptr | ((msb << (i + 1)) & 0x80);
unpacked_ptr++;
data_ptr++;
}
}
next_tvb = tvb_new_child_real_data(tvb, unpacked, unpacked_size, unpacked_size);
tvb_set_free_cb(next_tvb, g_free);
return next_tvb;
}
static int
get_digitech_hf_parameter_id_by_position(guint8 position)
{
int hf_parameter = hf_digitech_parameter_id;
switch (position)
{
case DIGITECH_POSITION_GLOBAL:
hf_parameter = hf_digitech_parameter_id_global;
break;
case DIGITECH_POSITION_PICKUP:
hf_parameter = hf_digitech_parameter_id_pickup;
break;
case DIGITECH_POSITION_WAH:
hf_parameter = hf_digitech_parameter_id_wah;
break;
case DIGITECH_POSITION_COMPRESSOR:
hf_parameter = hf_digitech_parameter_id_compressor;
break;
case DIGITECH_POSITION_GNX3K_WHAMMY:
hf_parameter = hf_digitech_parameter_id_gnx3k_whammy;
break;
case DIGITECH_POSITION_DISTORTION:
hf_parameter = hf_digitech_parameter_id_distortion;
break;
case DIGITECH_POSITION_AMP_CHANNEL:
hf_parameter = hf_digitech_parameter_id_amp_channel;
break;
case DIGITECH_POSITION_AMP:
hf_parameter = hf_digitech_parameter_id_amp;
break;
case DIGITECH_POSITION_AMP_CABINET:
hf_parameter = hf_digitech_parameter_id_amp_cabinet;
break;
case DIGITECH_POSITION_AMP_B:
hf_parameter = hf_digitech_parameter_id_amp_b;
break;
case DIGITECH_POSITION_AMP_CABINET_B:
hf_parameter = hf_digitech_parameter_id_amp_cabinet_b;
break;
case DIGITECH_POSITION_NOISEGATE:
hf_parameter = hf_digitech_parameter_id_noisegate;
break;
case DIGITECH_POSITION_VOLUME_PRE_FX:
hf_parameter = hf_digitech_parameter_id_volume_pre_fx;
break;
case DIGITECH_POSITION_CHORUS_FX:
hf_parameter = hf_digitech_parameter_id_chorusfx;
break;
case DIGITECH_POSITION_DELAY:
hf_parameter = hf_digitech_parameter_id_delay;
break;
case DIGITECH_POSITION_REVERB:
hf_parameter = hf_digitech_parameter_id_reverb;
break;
case DIGITECH_POSITION_VOLUME_POST_FX:
hf_parameter = hf_digitech_parameter_id_volume_post_fx;
break;
case DIGITECH_POSITION_PRESET:
hf_parameter = hf_digitech_parameter_id_preset;
break;
case DIGITECH_POSITION_WAH_MIN_MAX:
hf_parameter = hf_digitech_parameter_id_wah_min_max;
break;
case DIGITECH_POSITION_EQUALIZER:
hf_parameter = hf_digitech_parameter_id_equalizer;
break;
case DIGITECH_POSITION_EQUALIZER_B:
hf_parameter = hf_digitech_parameter_id_equalizer_b;
break;
case DIGITECH_POSITION_AMP_LOOP:
hf_parameter = hf_digitech_parameter_id_amp_loop;
break;
case DIGITECH_POSITION_EXPRESSION:
case DIGITECH_POSITION_V_SWITCH_ASSIGN:
case DIGITECH_POSITION_LFO_1:
case DIGITECH_POSITION_LFO_2:
case DIGITECH_POSITION_LIBRARY:
case DIGITECH_POSITION_WAH_PEDAL:
default:
break;
}
return hf_parameter;
}
static gint
dissect_digitech_parameter(tvbuff_t *data_tvb, proto_tree *tree,
digitech_conv_data_t *conv_data, gint data_offset)
{
guint8 digitech_helper;
int hf_parameter = hf_digitech_parameter_id;
if (conv_data->protocol_version >= 1)
{
digitech_helper = tvb_get_guint8(data_tvb, data_offset+2);
hf_parameter = get_digitech_hf_parameter_id_by_position(digitech_helper);
}
proto_tree_add_item(tree, hf_parameter, data_tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
if (conv_data->protocol_version >= 1)
{
proto_tree_add_item(tree, hf_digitech_parameter_position, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
}
digitech_helper = tvb_get_guint8(data_tvb, data_offset);
if (digitech_helper < 0x80)
{
proto_tree_add_item(tree, hf_digitech_parameter_data, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
}
else
{
guint16 data_count;
if (digitech_helper > 0x80)
{
data_count = (guint16)(digitech_helper & ~0x80);
proto_tree_add_uint(tree, hf_digitech_parameter_data_count, data_tvb,
data_offset, 1, (guint32)data_count);
data_offset++;
}
else
{
data_count = (guint16)tvb_get_ntohs(data_tvb, data_offset+1);
proto_tree_add_uint(tree, hf_digitech_parameter_data_two_byte_count, data_tvb,
data_offset, 3, (guint32)data_count);
data_offset += 3;
}
proto_tree_add_item(tree, hf_digitech_parameter_multibyte_data, data_tvb,
data_offset, (gint)data_count, ENC_NA);
data_offset += data_count;
}
return data_offset;
}
static int
get_digitech_hf_product_by_family(guint8 family)
{
int hf_product = hf_digitech_unknown_product_id;
switch (family)
{
case DIGITECH_FAMILY_RP:
hf_product = hf_digitech_rp_product_id;
break;
default:
break;
}
return hf_product;
}
static void
dissect_digitech_procedure(guint8 procedure, const gint offset,
tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *data_tvb;
gint data_offset;
gint data_len;
guint8 *tmp_string;
guint str_size;
guint16 count;
guint8 digitech_helper;
conversation_t *conversation;
digitech_conv_data_t *conv_data;
conversation = find_or_create_conversation(pinfo);
conv_data = (digitech_conv_data_t *)conversation_get_proto_data(conversation, proto_sysex);
if (conv_data == NULL)
{
conv_data = wmem_new(wmem_file_scope(), digitech_conv_data_t);
conv_data->protocol_version = 1;
}
if (tvb_length(tvb) - offset < 2)
{
return;
}
data_tvb = unpack_digitech_message(tvb, offset);
add_new_data_source(pinfo, data_tvb, "Unpacked Procedure Data");
data_offset = 0;
data_len = tvb_length(data_tvb);
switch (procedure)
{
case DIGITECH_PROCEDURE_REQUEST_WHO_AM_I:
proto_tree_add_item(tree, hf_digitech_desired_device_id, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
proto_tree_add_item(tree, hf_digitech_desired_family_id, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
proto_tree_add_item(tree, hf_digitech_desired_product_id, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
break;
case DIGITECH_PROCEDURE_RECEIVE_WHO_AM_I:
proto_tree_add_item(tree, hf_digitech_device_id, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
digitech_helper = tvb_get_guint8(data_tvb, data_offset);
proto_tree_add_item(tree, hf_digitech_family_id, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
proto_tree_add_item(tree, get_digitech_hf_product_by_family(digitech_helper),
data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
if (data_len == 3)
{
conv_data->protocol_version = 0;
}
else if (data_len == 4)
{
conv_data->protocol_version = 1;
proto_tree_add_item(tree, hf_digitech_os_mode, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
}
break;
case DIGITECH_PROCEDURE_REQUEST_PRESET_NAMES:
proto_tree_add_item(tree, hf_digitech_preset_bank, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
break;
case DIGITECH_PROCEDURE_RECEIVE_PRESET_NAMES:
proto_tree_add_item(tree, hf_digitech_preset_bank, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
count = (guint16)tvb_get_guint8(data_tvb, data_offset);
proto_tree_add_item(tree, hf_digitech_preset_count, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
while ((count > 0) && (str_size = tvb_strsize(data_tvb, data_offset)))
{
tmp_string = tvb_get_string(wmem_packet_scope(), data_tvb, data_offset, str_size - 1);
proto_tree_add_string(tree, hf_digitech_preset_name, data_tvb, data_offset, str_size, tmp_string);
data_offset += (gint)str_size;
count--;
}
break;
case DIGITECH_PROCEDURE_REQUEST_PRESET:
proto_tree_add_item(tree, hf_digitech_preset_bank, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
proto_tree_add_item(tree, hf_digitech_preset_index, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
break;
case DIGITECH_PROCEDURE_RECEIVE_PRESET_START:
proto_tree_add_item(tree, hf_digitech_preset_bank, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
proto_tree_add_item(tree, hf_digitech_preset_index, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
str_size = tvb_strsize(data_tvb, data_offset);
tmp_string = tvb_get_string(wmem_packet_scope(), data_tvb, data_offset, str_size - 1);
proto_tree_add_string(tree, hf_digitech_preset_name, data_tvb, data_offset, str_size, tmp_string);
data_offset += (gint)str_size;
proto_tree_add_item(tree, hf_digitech_preset_modified, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
proto_tree_add_item(tree, hf_digitech_message_count, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
break;
case DIGITECH_PROCEDURE_RECEIVE_PRESET_PARAMETERS:
count = tvb_get_ntohs(data_tvb, data_offset);
proto_tree_add_item(tree, hf_digitech_parameter_count, data_tvb, data_offset, 2, ENC_BIG_ENDIAN);
data_offset += 2;
while (count > 0)
{
data_offset = dissect_digitech_parameter(data_tvb, tree, conv_data, data_offset);
count--;
}
break;
case DIGITECH_PROCEDURE_RECEIVE_PARAMETER_VALUE:
data_offset = dissect_digitech_parameter(data_tvb, tree, conv_data, data_offset);
break;
case DIGITECH_PROCEDURE_ACK:
proto_tree_add_item(tree, hf_digitech_ack_request_proc_id, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
break;
case DIGITECH_PROCEDURE_NACK:
proto_tree_add_item(tree, hf_digitech_nack_request_proc_id, data_tvb, data_offset, 1, ENC_BIG_ENDIAN);
data_offset++;
break;
default:
break;
}
if (data_offset < data_len)
{
proto_tree_add_expert(tree, pinfo, &ei_sysex_undecoded,
data_tvb, data_offset, data_len - data_offset);
}
}
static void
dissect_sysex_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
guint8 sysex_helper;
gint data_len;
proto_item *item;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SYSEX");
col_set_str(pinfo->cinfo, COL_INFO, "MIDI System Exclusive Command");
data_len = tvb_length(tvb);
if (parent_tree)
{
proto_item *ti = NULL;
proto_tree *tree = NULL;
gint offset = 0;
guint8 manufacturer_id;
guint32 three_byte_manufacturer_id = 0xFFFFFF;
guint8 procedure_id;
ti = proto_tree_add_protocol_format(parent_tree, proto_sysex, tvb, 0, -1, "MIDI System Exclusive Command");
tree = proto_item_add_subtree(ti, ett_sysex);
sysex_helper = tvb_get_guint8(tvb, 0);
item = proto_tree_add_item(tree, hf_sysex_message_start, tvb, offset, 1, ENC_BIG_ENDIAN);
if (sysex_helper != 0xF0)
{
expert_add_info(pinfo, item, &ei_sysex_message_start_byte);
}
offset++;
manufacturer_id = tvb_get_guint8(tvb, offset);
if (manufacturer_id == 0)
{
three_byte_manufacturer_id = tvb_get_ntoh24(tvb, offset);
proto_tree_add_item(tree, hf_sysex_three_byte_manufacturer_id, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
}
else
{
proto_tree_add_item(tree, hf_sysex_manufacturer_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
proto_tree_add_item(tree, hf_sysex_device_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (three_byte_manufacturer_id)
{
case SYSEX_MANUFACTURER_DOD:
{
guint8 digitech_helper;
const guint8 *data_ptr;
int len;
int i;
digitech_helper = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_digitech_family_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, get_digitech_hf_product_by_family(digitech_helper),
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
procedure_id = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_digitech_procedure_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dissect_digitech_procedure(procedure_id, offset, tvb, pinfo, tree);
len = tvb_length(tvb) - 2;
offset = len;
data_ptr = tvb_get_ptr(tvb, 1, len);
for (i = 0, digitech_helper = 0; i < len; ++i)
{
digitech_helper ^= *data_ptr++;
}
item = proto_tree_add_item(tree, hf_digitech_checksum, tvb, offset, 1, ENC_BIG_ENDIAN);
if (digitech_helper == 0)
{
proto_item_append_text(item, " (correct)");
}
else
{
proto_item_append_text(item, " (NOT correct)");
expert_add_info(pinfo, item, &ei_digitech_checksum_bad);
}
offset++;
break;
}
default:
break;
}
if (offset < data_len - 1)
{
proto_tree_add_expert(tree, pinfo, &ei_sysex_undecoded,
tvb, offset, data_len - offset - 1);
}
sysex_helper = tvb_get_guint8(tvb, data_len - 1);
item = proto_tree_add_item(tree, hf_sysex_message_eox, tvb, data_len - 1, 1, ENC_BIG_ENDIAN);
if (sysex_helper != 0xF7)
{
expert_add_info(pinfo, item, &ei_sysex_message_end_byte);
}
}
}
void
proto_register_sysex(void)
{
static hf_register_info hf[] = {
{ &hf_sysex_message_start,
{ "SysEx message start", "sysex.start", FT_UINT8, BASE_HEX,
NULL, 0, "System Exclusive Message start (0xF0)", HFILL }},
{ &hf_sysex_manufacturer_id,
{ "Manufacturer ID", "sysex.manufacturer_id", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_sysex_three_byte_manufacturer_id,
{ "Manufacturer ID", "sysex.manufacturer_id", FT_UINT24, BASE_HEX,
VALS(sysex_three_byte_manufacturer_id), 0, NULL, HFILL }},
{ &hf_sysex_device_id,
{ "Device ID", "sysex.device_id", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_sysex_message_eox,
{ "EOX", "sysex.eox", FT_UINT8, BASE_HEX,
NULL, 0, "System Exclusive Message end (0xF7)", HFILL}},
{ &hf_digitech_family_id,
{ "Family ID", "sysex.digitech.family_id", FT_UINT8, BASE_HEX,
VALS(digitech_family_id), 0, NULL, HFILL }},
{ &hf_digitech_unknown_product_id,
{ "Product ID", "sysex.digitech.product_id", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_rp_product_id,
{ "Product ID", "sysex.digitech.product_id", FT_UINT8, BASE_HEX,
VALS(digitech_rp_product_id), 0, NULL, HFILL }},
{ &hf_digitech_procedure_id,
{ "Procedure ID", "sysex.digitech.procedure_id", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&digitech_procedures_ext, 0, NULL, HFILL }},
{ &hf_digitech_desired_device_id,
{ "Desired Device ID", "sysex.digitech.desired_device_id", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_desired_family_id,
{ "Desired Family ID", "sysex.digitech.desired_family_id", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_desired_product_id,
{ "Desired Product ID", "sysex.digitech.desired_product_id", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_device_id,
{ "Device ID", "sysex.digitech.device_id", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_os_mode,
{ "OS Mode", "sysex.digitech.os_mode", FT_UINT8, BASE_HEX,
VALS(digitech_os_modes), 0, "DigiTech OS Mode", HFILL }},
{ &hf_digitech_preset_bank,
{ "Preset Bank", "sysex.digitech.preset_bank", FT_UINT8, BASE_HEX,
VALS(digitech_preset_banks), 0, NULL, HFILL }},
{ &hf_digitech_preset_index,
{ "Preset Index", "sysex.digitech.preset_index", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_preset_count,
{ "Preset Count", "sysex.digitech.preset_count", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_preset_name,
{ "Preset Name", "sysex.digitech.preset_name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_preset_modified,
{ "Preset Modified", "sysex.digitech.preset_modified", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_yes_no), 0, "Modified flag (0 = unmodified)", HFILL }},
{ &hf_digitech_message_count,
{ "Messages to follow", "sysex.digitech.message_count", FT_UINT8, BASE_DEC,
NULL, 0, "Number of messages to follow", HFILL }},
{ &hf_digitech_parameter_count,
{ "Parameter Count", "sysex.digitech.parameter_count", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_parameter_id,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_global,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_global), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_pickup,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_pickup), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_wah,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_wah), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_compressor,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_compressor), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_gnx3k_whammy,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC | BASE_EXT_STRING,
&digitech_parameter_ids_gnx3k_whammy_ext, 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_distortion,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC | BASE_EXT_STRING,
&digitech_parameter_ids_distortion_ext, 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_amp_channel,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_amp_channel), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_amp,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC | BASE_EXT_STRING,
&digitech_parameter_ids_amp_ext, 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_amp_cabinet,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_amp_cabinet), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_amp_b,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_amp_b), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_amp_cabinet_b,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_amp_cabinet_b), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_noisegate,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_noisegate), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_volume_pre_fx,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_volume_pre_fx), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_chorusfx,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC | BASE_EXT_STRING,
&digitech_parameter_ids_chorusfx_ext, 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_delay,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC | BASE_EXT_STRING,
&digitech_parameter_ids_delay_ext, 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_reverb,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_reverb), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_volume_post_fx,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_volume_post_fx), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_preset,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_preset), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_wah_min_max,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_wah_min_max), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_equalizer,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_equalizer), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_equalizer_b,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_equalizer_b), 0, NULL, HFILL }},
{ &hf_digitech_parameter_id_amp_loop,
{ "Parameter ID", "sysex.digitech.parameter_id", FT_UINT16, BASE_DEC,
VALS(digitech_parameter_ids_amp_loop), 0, NULL, HFILL }},
{ &hf_digitech_parameter_position,
{ "Parameter position", "sysex.digitech.parameter_position", FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&digitech_parameter_positions_ext, 0, NULL, HFILL }},
{ &hf_digitech_parameter_data,
{ "Parameter data", "sysex.digitech.parameter_data", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_parameter_data_count,
{ "Parameter value count", "sysex.digitech.parameter_data_count", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_parameter_data_two_byte_count,
{ "Parameter data count", "sysex.digitech.parameter_data_count", FT_UINT24, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_parameter_multibyte_data,
{ "Parameter data", "sysex.digitech.parameter_data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_digitech_ack_request_proc_id,
{ "Requesting Procedure ID", "sysex.digitech.ack.procedure_id", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&digitech_procedures_ext, 0, "Procedure ID of the request being ACKed", HFILL }},
{ &hf_digitech_nack_request_proc_id,
{ "Requesting Procedure ID", "sysex.digitech.ack.procedure_id", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&digitech_procedures_ext, 0, "Procedure ID of the request being NACKed", HFILL }},
{ &hf_digitech_checksum,
{ "Checksum", "sysex.digitech.checksum", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
};
static gint *sysex_subtrees[] = {
&ett_sysex
};
static ei_register_info ei[] = {
{ &ei_sysex_message_start_byte, { "sysex.message_start_byte", PI_PROTOCOL, PI_WARN, "SYSEX Error: Wrong start byte", EXPFILL }},
{ &ei_digitech_checksum_bad, { "sysex.digitech.checksum_bad", PI_CHECKSUM, PI_WARN, "ARP packet storm detected", EXPFILL }},
{ &ei_sysex_message_end_byte, { "sysex.message_end_byte", PI_PROTOCOL, PI_WARN, "SYSEX Error: Wrong end byte", EXPFILL }},
{ &ei_sysex_undecoded, { "sysex.undecoded", PI_UNDECODED, PI_WARN, "Not dissected yet (report to wireshark.org)", EXPFILL }},
};
expert_module_t* expert_sysex;
proto_sysex = proto_register_protocol("MIDI System Exclusive", "SYSEX", "sysex");
proto_register_field_array(proto_sysex, hf, array_length(hf));
proto_register_subtree_array(sysex_subtrees, array_length(sysex_subtrees));
expert_sysex = expert_register_protocol(proto_sysex);
expert_register_field_array(expert_sysex, ei, array_length(ei));
register_dissector("sysex", dissect_sysex_command, proto_sysex);
}
void
proto_reg_handoff_sysex(void)
{
}
