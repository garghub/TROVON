static void vcdu_uat_data_update_cb(void* p, const char** err) {
uat_channel_t *ud = p;
if (ud->channel >= 64) {
*err = ep_strdup_printf("Channel must be between 0-63.");
return;
}
}
static void vcdu_prefs_apply_cb(void)
{
guint i;
if (num_channels_uat > 0)
{
memset ( bitstream_channels, 0, sizeof(bitstream_channels) );
for (i = 0; i < num_channels_uat; i++)
{
bitstream_channels[uat_bitchannels[i].channel] = 1;
}
}
}
static const char* smex_time_to_string ( int pb5_days_since_midnight_9_10_oct_1995, int pb5_seconds, int pb5_milliseconds )
{
static int utcdiff = 0;
nstime_t t;
static int Days[2][13] =
{
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};
int yr;
int ix, days, month;
if ( 0 == utcdiff )
{
for ( yr=1970; yr < 1995; ++yr )
{
utcdiff += ( Leap(yr) ? 366 : 365 ) * 24 * 60 * 60;
}
days = 0;
ix = ( Leap(1995) ? 1 : 0 );
for ( month=1; month < 10; ++month )
{
days += Days[ix][month];
}
days += 9;
utcdiff += days * 24 * 60 * 60;
}
t.secs = ( pb5_days_since_midnight_9_10_oct_1995 * 86400 ) + pb5_seconds + utcdiff;
t.nsecs = pb5_milliseconds*1000000;
return abs_time_to_str(&t, ABSOLUTE_TIME_DOY_UTC, TRUE);
}
static void
dissect_vcdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int packet_boundary = 0;
int offset = 0;
int new_offset=0;
int ccsds_tree_added = 0;
int ccsds_len = 0;
proto_item *smex_header = NULL;
proto_tree *smex_tree = NULL;
proto_item *vcdu_header = NULL;
proto_tree *vcdu_tree = NULL;
guint16 first_word = 0;
guint32 long_word = 0;
guint16 new_ptr = 0;
tvbuff_t *new_tvb = NULL;
int vcid = 0, pb5_days = 0, pb5_seconds = 0, pb5_milliseconds = 0;
const char* time_string = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "VCDU");
col_set_str(pinfo->cinfo, COL_INFO, "Virtual Channel Data Unit");
{
smex_header=proto_tree_add_text(tree, tvb, offset, SMEX_HEADER_LENGTH, "SMEX Header");
smex_tree=proto_item_add_subtree(smex_header, ett_smex);
proto_tree_add_item(smex_tree, hf_smex_gsc, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
offset += 2;
first_word=tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(smex_tree, hf_smex_version, tvb, offset, 2, first_word);
proto_tree_add_uint(smex_tree, hf_smex_framelen, tvb, offset, 2, first_word);
offset += 2;
proto_tree_add_item(smex_tree, hf_smex_rs_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(smex_tree, hf_smex_rs_error, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(smex_tree, hf_smex_crc_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(smex_tree, hf_smex_crc_error, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(smex_tree, hf_smex_mcs_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(smex_tree, hf_smex_mcs_num_error, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(smex_tree, hf_smex_data_inv, tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
proto_tree_add_item(smex_tree, hf_smex_frame_sync, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(smex_tree, hf_smex_data_dir, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(smex_tree, hf_smex_data_class, tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
long_word = tvb_get_ntohl ( tvb, offset );
pb5_days = ( long_word >> 17 ) & PB5_JULIAN_DAY_MASK;
pb5_seconds = ( long_word & PB5_SECONDS_MASK );
first_word = tvb_get_ntohs ( tvb, offset+4 );
pb5_milliseconds = ( first_word & PB5_MILLISECONDS_MASK ) >> 6;
proto_tree_add_item(smex_tree, hf_smex_pb5, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(smex_tree, hf_smex_jday, tvb, offset, 2, ENC_BIG_ENDIAN);
++offset;
proto_tree_add_item(smex_tree, hf_smex_seconds, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(smex_tree, hf_smex_msec, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
time_string = smex_time_to_string ( pb5_days, pb5_seconds, pb5_milliseconds );
proto_tree_add_text (smex_tree, tvb, offset-6, 6, "%s = Ground Receipt Time", time_string );
proto_item_set_end(smex_header, tvb, offset);
vcdu_header=proto_tree_add_text(tree, tvb, offset, VCDU_HEADER_LENGTH, "VCDU Header");
vcdu_tree = proto_item_add_subtree(vcdu_header, ett_vcdu);
first_word=tvb_get_ntohs(tvb, offset);
vcid = first_word & 0x3f;
proto_tree_add_item(vcdu_tree, hf_vcdu_version, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(vcdu_tree, hf_vcdu_sp_id, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(vcdu_tree, hf_vcdu_vc_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(vcdu_tree, hf_vcdu_seq, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(vcdu_tree, hf_vcdu_replay, tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
first_word=tvb_get_ntohs(tvb, offset);
if ( bitstream_channels[vcid] )
{
new_ptr=first_word & LBP_MASK;
proto_tree_add_item(vcdu_tree, hf_vcdu_lbp, tvb, offset, 2, ENC_BIG_ENDIAN);
switch ( new_ptr )
{
case LBP_ALL_DATA:
proto_tree_add_text(vcdu_tree, tvb, 0, -1, "Bitream ALL Data");
break;
case LBP_ALL_DATA_ANOMALY:
proto_tree_add_text(vcdu_tree, tvb, 0, -1, "Bitream ALL Data (Anomaly)");
break;
case LBP_ALL_FILL:
proto_tree_add_text(vcdu_tree, tvb, 0, -1, "Bitream ALL Fill");
break;
default:
break;
}
}
else
{
new_ptr=first_word & FHP_MASK;
proto_tree_add_item(vcdu_tree, hf_vcdu_fhp, tvb, offset, 2, ENC_BIG_ENDIAN);
if ( FHP_ALL_FILL == new_ptr )
{
proto_tree_add_text(vcdu_tree, tvb, 0, -1, "Ccsds ALL Fill");
}
else if ( FHP_CONTINUATION == new_ptr )
{
proto_tree_add_text(vcdu_tree, tvb, 0, -1, "Ccsds Continuation Packet");
}
else
{
new_offset=offset+2+new_ptr;
packet_boundary = pinfo->iplen - IP_HEADER_LENGTH - VCDU_HEADER_LENGTH - CCSDS_PRIMARY_HEADER_LENGTH - CCSDS_SECONDARY_HEADER_LENGTH;
while ( (new_offset-offset+2) < packet_boundary && (new_offset-offset+2) >= 4 )
{
ccsds_tree_added = 1;
ccsds_len=tvb_get_ntohs(tvb, new_offset+4);
new_tvb = tvb_new_subset_remaining(tvb, new_offset);
call_dissector(ccsds_handle, new_tvb, pinfo, vcdu_tree);
new_offset=new_offset+ccsds_len+7;
}
if ( ! ccsds_tree_added )
{
proto_tree_add_text(vcdu_tree, tvb, 0, -1, "FHP too close to end of VCDU. Incomplete Hdr Info Available - Unable to format CCSDS Hdr(s)." );
}
}
}
proto_item_set_end(vcdu_tree, tvb, offset);
if ( ! ccsds_tree_added )
{
proto_tree_add_text(vcdu_tree, tvb, offset, -1, "Data");
}
}
}
void
proto_register_vcdu(void)
{
module_t *vcdu_module;
static hf_register_info hf[] = {
{ &hf_smex_gsc,
{ "Ground Sequence Counter", "smex.gsc",
FT_UINT64, BASE_DEC, NULL, 0x0,
"SMEX Ground Sequence Counter", HFILL }
},
{ &hf_smex_unused,
{ "Unused", "smex.unused",
FT_UINT16, BASE_DEC, NULL, 0x0,
"SMEX Unused", HFILL }
},
{ &hf_smex_version,
{ "Version", "smex.version",
FT_UINT16, BASE_DEC, NULL, SMEX_VERSION,
"SMEX Version", HFILL }
},
{ &hf_smex_framelen,
{ "Frame Length", "smex.frame_len",
FT_UINT16, BASE_DEC, NULL, SMEX_FRAMELEN,
"SMEX Frame Length", HFILL }
},
{ &hf_smex_rs_enable,
{ "RS Enable", "smex.rs_enable",
FT_BOOLEAN, 8, NULL, 0x80,
"SMEX RS Enable", HFILL }
},
{ &hf_smex_rs_error,
{ "RS Error", "smex.rs_error",
FT_BOOLEAN, 8, NULL, 0x40,
"SMEX RS Error", HFILL }
},
{ &hf_smex_crc_enable,
{ "CRC Enable", "smex.crc_enable",
FT_BOOLEAN, 8, NULL, 0x20,
"SMEX CRC Enable", HFILL }
},
{ &hf_smex_crc_error,
{ "CRC Error", "smex.crc_error",
FT_BOOLEAN, 8, NULL, 0x10,
"SMEX CRC Error", HFILL }
},
{ &hf_smex_mcs_enable,
{ "MCS Enable", "smex.mcs_enable",
FT_BOOLEAN, 8, NULL, 0x08,
"SMEX MCS Enable", HFILL }
},
{ &hf_smex_mcs_num_error,
{ "MCS Number Error", "smex.mcs_numerr",
FT_BOOLEAN, 8, NULL, 0x04,
"SMEX MCS Number Error", HFILL }
},
{ &hf_smex_data_inv,
{ "Data Inversion", "smex.data_inv",
FT_UINT16, BASE_DEC, VALS(smex_data_inversion_type), 0x03,
"SMEX Data Inversion", HFILL }
},
{ &hf_smex_frame_sync,
{ "Frame Sync", "smex.frame_sync",
FT_UINT16, BASE_DEC, VALS(smex_frame_sync_mode), 0xc0,
"SMEX Frame Sync Flag", HFILL }
},
{ &hf_smex_data_dir,
{ "Data Direction", "smex.data_dir",
FT_UINT16, BASE_DEC, VALS(smex_data_direction), 0x20,
"SMEX Data Direction flag", HFILL }
},
{ &hf_smex_data_class,
{ "Data Class", "smex.data_class",
FT_UINT16, BASE_DEC, VALS(smex_data_class), 0x1f,
"SMEX Data Class", HFILL }
},
{ &hf_smex_pb5,
{ "PB5 Flag", "smex.pb5",
FT_UINT16, BASE_DEC, NULL, 0x8000,
"SMEX PB5 Flag", HFILL }
},
{ &hf_smex_jday,
{ "Julian Day", "smex.jday",
FT_UINT16, BASE_DEC, NULL, PB5_JULIAN_DAY_MASK,
"SMEX Julian Day", HFILL }
},
{ &hf_smex_seconds,
{ "Seconds", "smex.seconds",
FT_UINT24, BASE_DEC, NULL, PB5_SECONDS_MASK,
"SMEX Seconds", HFILL }
},
{ &hf_smex_msec,
{ "Milliseconds", "smex.msec",
FT_UINT16, BASE_DEC, NULL, PB5_MILLISECONDS_MASK,
"SMEX Milliseconds", HFILL }
},
{ &hf_smex_spare,
{ "Spare", "smex.spare",
FT_UINT16, BASE_DEC, NULL, 0x03f,
"SMEX Spare", HFILL }
},
{ &hf_vcdu_version,
{ "Version", "vcdu.version",
FT_UINT16, BASE_DEC, NULL, 0xc0,
"VCDU Version", HFILL }
},
{ &hf_vcdu_sp_id,
{ "Space Craft ID", "vcdu.spid",
FT_UINT16, BASE_DEC, NULL, 0x3fc0,
"VCDU Space Craft ID", HFILL }
},
{ &hf_vcdu_vc_id,
{ "Virtual Channel ID", "vcdu.vcid",
FT_UINT16, BASE_DEC, NULL, 0x3f,
"VCDU Virtual Channel ID", HFILL }
},
{ &hf_vcdu_seq,
{ "Sequence Count", "vcdu.seq",
FT_UINT16, BASE_DEC, NULL, 0xffffff,
"VCDU Sequence Count", HFILL }
},
{ &hf_vcdu_replay,
{ "Replay Flag", "vcdu.replay",
FT_BOOLEAN, 8, NULL, 0x80,
"VCDU Replay Flag", HFILL }
},
{ &hf_vcdu_fhp,
{ "First Header Pointer", "vcdu.fhp",
FT_UINT16, BASE_DEC, NULL, FHP_MASK,
"VCDU/MPDU First Header Pointer", HFILL }
},
{ &hf_vcdu_lbp,
{ "Last Bit Pointer", "vcdu.lbp",
FT_UINT16, BASE_DEC, NULL, LBP_MASK,
"VCDU/BPDU Last Bit Pointer", HFILL }
}
};
static uat_field_t vcdu_uat_flds[] = {
UAT_FLD_DEC(uat_bitchannels, channel, "Bitstream Channel", "Bitstream Channel"),
UAT_END_FIELDS
};
static gint *ett[] = {
&ett_vcdu,
&ett_smex,
&ett_vcduh,
};
proto_vcdu = proto_register_protocol("VCDU", "VCDU", "vcdu");
proto_register_field_array(proto_vcdu, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector ( "vcdu", dissect_vcdu, proto_vcdu );
vcdu_module = prefs_register_protocol(proto_vcdu, vcdu_prefs_apply_cb);
vcdu_uat = uat_new("Bitstream Channel Table",
sizeof(uat_channel_t),
"vcdu_bitstream_channels",
TRUE,
(void*)&uat_bitchannels,
&num_channels_uat,
UAT_CAT_GENERAL,
NULL,
NULL,
vcdu_uat_data_update_cb,
NULL,
NULL,
vcdu_uat_flds);
prefs_register_uat_preference(vcdu_module,
"bitstream_channels",
"Bitstream Channel Table",
"Bitstream Channel Table",
vcdu_uat);
}
void
proto_reg_handoff_vcdu(void)
{
dissector_add_handle ( "udp.port", find_dissector("vcdu") );
ccsds_handle = find_dissector ( "ccsds" );
}
