static gint
dissect_sbc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *sbc_tree;
proto_item *pitem;
proto_item *ritem;
proto_tree *rtree;
gint offset = 0;
guint8 number_of_frames;
guint8 syncword;
guint8 byte;
guint8 blocks;
guint8 channels;
guint8 subbands;
guint8 bitpool;
guint frequency;
guint8 sbc_blocks;
gint sbc_channels;
guint8 sbc_subbands;
gint val;
gint counter = 1;
gint frame_length;
gint expected_speed_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SBC");
ti = proto_tree_add_item(tree, proto_sbc, tvb, offset, -1, ENC_NA);
sbc_tree = proto_item_add_subtree(ti, ett_sbc);
proto_tree_add_item(sbc_tree, hf_sbc_fragmented, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sbc_tree, hf_sbc_starting_packet, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sbc_tree, hf_sbc_last_packet, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sbc_tree, hf_sbc_rfa, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sbc_tree, hf_sbc_number_of_frames, tvb, offset, 1, ENC_BIG_ENDIAN);
number_of_frames = tvb_get_guint8(tvb, offset) & 0x0F;
offset += 1;
while (tvb_length_remaining(tvb, offset) > 0) {
byte = tvb_get_guint8(tvb, offset + 1);
frequency = (byte & 0xC0) >> 6;
blocks = (byte & 0x30) >> 4;
channels = (byte & 0x0C)>> 2;
subbands = byte & 0x01;
bitpool = tvb_get_guint8(tvb, offset + 2);
if (channels == CHANNELS_MONO)
sbc_channels = 1;
else
sbc_channels = 2;
switch (frequency) {
case FREQUENCY_16000:
frequency = 16000;
break;
case FREQUENCY_32000:
frequency = 32000;
break;
case FREQUENCY_44100:
frequency = 44100;
break;
case FREQUENCY_48000:
frequency = 48000;
break;
default:
frequency = 0;
}
sbc_subbands = 4 * (subbands + 1);
sbc_blocks = 4 * (blocks + 1);
frame_length = (4 * sbc_subbands * sbc_channels) / 8;
if (sbc_channels == 1)
val = sbc_blocks * sbc_channels * bitpool;
else
val = (((channels == CHANNELS_JOINT_STEREO) ? 1 : 0) * sbc_subbands + sbc_blocks * bitpool);
frame_length += val / 8;
if (val % 8)
frame_length += 1;
expected_speed_data = (frame_length * frequency) / (sbc_subbands * sbc_blocks);
ritem = proto_tree_add_text(sbc_tree, tvb, offset, 4 + frame_length,
"Frame: %3u/%3u", counter, number_of_frames);
rtree = proto_item_add_subtree(ritem, ett_sbc_list);
pitem = proto_tree_add_item(rtree, hf_sbc_syncword, tvb, offset, 1, ENC_BIG_ENDIAN);
syncword = tvb_get_guint8(tvb, offset);
if (syncword != 0x9C) {
expert_add_info(pinfo, pitem, &ei_sbc_syncword);
}
offset += 1;
proto_tree_add_item(ritem, hf_sbc_sampling_frequency, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ritem, hf_sbc_blocks, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ritem, hf_sbc_channel_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ritem, hf_sbc_allocation_method, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ritem, hf_sbc_subbands, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ritem, hf_sbc_bitpool, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ritem, hf_sbc_crc_check, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ritem, hf_sbc_data, tvb, offset, frame_length, ENC_NA);
offset += frame_length;
pitem = proto_tree_add_text(ritem, tvb, offset, 0, "Expected speed data: %u KiB/s", expected_speed_data / 1024);
PROTO_ITEM_SET_GENERATED(pitem);
counter += 1;
}
col_append_fstr(pinfo->cinfo, COL_INFO, " Frames=%u", number_of_frames);
return offset;
}
void
proto_register_sbc(void)
{
module_t *module;
expert_module_t* expert_sbc;
static hf_register_info hf[] = {
{ &hf_sbc_fragmented,
{ "Fragmented", "sbc.fragmented",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_sbc_starting_packet,
{ "Starting Packet", "sbc.starting_packet",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_sbc_last_packet,
{ "Last Packet", "sbc.last_packet",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_sbc_rfa,
{ "RFA", "sbc.rfa",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_sbc_number_of_frames,
{ "Number of Frames", "sbc.number_of_frames",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_sbc_syncword,
{ "Sync Word", "sbc.syncword",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_sbc_sampling_frequency,
{ "Sampling Frequency", "sbc.sampling_frequency",
FT_UINT8, BASE_HEX, VALS(sampling_frequency_vals), 0xC0,
NULL, HFILL }
},
{ &hf_sbc_blocks,
{ "Blocks", "sbc.blocks",
FT_UINT8, BASE_HEX, VALS(blocks_vals), 0x30,
NULL, HFILL }
},
{ &hf_sbc_channel_mode,
{ "Channel Mode", "sbc.channel_mode",
FT_UINT8, BASE_HEX, VALS(channel_mode_vals), 0x0C,
NULL, HFILL }
},
{ &hf_sbc_allocation_method,
{ "Allocation Method", "sbc.allocation_method",
FT_UINT8, BASE_HEX, VALS(allocation_method_vals), 0x02,
NULL, HFILL }
},
{ &hf_sbc_subbands,
{ "Subbands", "sbc.subbands",
FT_UINT8, BASE_HEX, VALS(subbands_vals), 0x01,
NULL, HFILL }
},
{ &hf_sbc_bitpool,
{ "Bitpool", "sbc.bitpool",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_sbc_crc_check,
{ "CRC Check", "sbc.crc_check",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_sbc_data,
{ "Data", "sbc.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_sbc,
&ett_sbc_list,
};
static ei_register_info ei[] = {
{ &ei_sbc_syncword, { "sbc.syncword.unexpected", PI_PROTOCOL, PI_WARN, "Unexpected syncword", EXPFILL }},
};
proto_sbc = proto_register_protocol("Bluetooth SBC Codec", "SBC", "sbc");
proto_register_field_array(proto_sbc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_sbc = expert_register_protocol(proto_sbc);
expert_register_field_array(expert_sbc, ei, array_length(ei));
new_register_dissector("sbc", dissect_sbc, proto_sbc);
module = prefs_register_protocol(proto_sbc, NULL);
prefs_register_static_text_preference(module, "a2dp.version",
"Bluetooth Audio Codec SBC version based on A2DP 1.3",
"Version of codec supported by this dissector.");
}
