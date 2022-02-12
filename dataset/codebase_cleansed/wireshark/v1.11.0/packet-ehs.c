static int
ehs_secondary_header_size ( int protocol, tvbuff_t* tvb, int offset )
{
int size = EHS_SECONDARY_HEADER_SIZE;
switch ( protocol )
{
case EHS_PROTOCOL__TDM_TELEMETRY:
size = tvb_get_ntohs ( tvb, offset );
break;
case EHS_PROTOCOL__NASCOM_TELEMETRY:
break;
case EHS_PROTOCOL__PSEUDO_TELEMETRY:
size = 8;
break;
case EHS_PROTOCOL__TDS_DATA:
break;
case EHS_PROTOCOL__TEST_DATA:
break;
case EHS_PROTOCOL__GSE_DATA:
size = 16;
break;
case EHS_PROTOCOL__CUSTOM_DATA:
break;
case EHS_PROTOCOL__HDRS_DQ:
break;
case EHS_PROTOCOL__CSS:
break;
case EHS_PROTOCOL__AOS_LOS:
break;
case EHS_PROTOCOL__PDSS_PAYLOAD_CCSDS_PACKET:
break;
case EHS_PROTOCOL__PDSS_CORE_CCSDS_PACKET:
break;
case EHS_PROTOCOL__PDSS_PAYLOAD_BPDU:
break;
case EHS_PROTOCOL__PDSS_UDSM:
break;
case EHS_PROTOCOL__PDSS_RPSM:
break;
default:
break;
}
return size;
}
static void
common_secondary_header_dissector ( proto_tree* ehs_secondary_header_tree, tvbuff_t* tvb, int* offset )
{
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_vcdu_sequence_number, tvb, *offset, 3, ENC_BIG_ENDIAN );
*offset += 3;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_stream_id, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
++(*offset);
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_gse_pkt_id, tvb, *offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_payload_vs_core_id, tvb, *offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_apid, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_virtual_channel, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_pdss_reserved_sync, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
}
static void
aoslos_secondary_header_dissector ( proto_tree* ehs_secondary_header_tree, tvbuff_t* tvb, int* offset )
{
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_version, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_5, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_4, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_3, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_2, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_1, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_0, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
common_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
}
static void
payload_ccsds_secondary_header_dissector ( proto_tree* ehs_secondary_header_tree, tvbuff_t* tvb, int* offset )
{
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_version, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_5, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_4, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_3, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_vcdu_sequence_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_packet_sequence_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_0, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
common_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
}
static void
core_ccsds_secondary_header_dissector ( proto_tree* ehs_secondary_header_tree, tvbuff_t* tvb, int* offset )
{
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_version, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_5, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_4, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_parent_stream_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_vcdu_sequence_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_packet_sequence_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_0, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
common_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
}
static void
payload_bpdu_secondary_header_dissector ( proto_tree* ehs_secondary_header_tree, tvbuff_t* tvb, int* offset )
{
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_version, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_5, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_4, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_3, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_vcdu_sequence_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_1, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_0, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
common_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
}
static void
udsm_secondary_header_dissector ( proto_tree* ehs_secondary_header_tree, tvbuff_t* tvb, int* offset )
{
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_version, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_5, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_4, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_3, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_2, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_1, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_data_status_bit_0, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
common_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
}
static void
tdm_secondary_header_dissector ( proto_tree* ehs_secondary_header_tree, tvbuff_t* tvb, int* offset )
{
int j;
int num_major_frames = 0;
int num_minor_frames = 0;
int cntmet_present = 0;
int obt_present = 0;
int mjfs_present = 0;
int year, jday, hour, minute, second, tenths;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_secondary_header_length, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_extra_data_packet, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_backup_stream_id_number, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_end_of_data_flag, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_parent_frame_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_checksum_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_fixed_value_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_minor_frame_counter_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_format_id_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_bit_slip_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_sync_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_aoslos_flag, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_override_errors_flag, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_data_status, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_idq, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_cdq, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_adq, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_data_dq, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
*offset += 2;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_format_id, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_major_frame_packet_index, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_numpkts_per_major_frame, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
num_minor_frames = 1 + tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_num_minor_frames_per_packet, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
cntmet_present = tvb_get_guint8 ( tvb, *offset ) & 0x80;
obt_present = tvb_get_guint8 ( tvb, *offset ) & 0x40;
mjfs_present = tvb_get_guint8 ( tvb, *offset ) & 0x20;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_cntmet_present, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_obt_present, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_major_frame_status_present, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
if ( cntmet_present )
{
year = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_cnt_year, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
jday = tvb_get_ntohs ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_cnt_jday, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
hour = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_cnt_hour, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
minute = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_cnt_minute, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
second = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_cnt_second, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
tenths = tvb_get_guint8 ( tvb, *offset ) >> 4;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_cnt_tenths, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
proto_tree_add_text ( ehs_secondary_header_tree, tvb, *offset-7, 7,
"%04d/%03d:%02d:%02d:%02d.%1d = CNT/MET Time", year + 1900, jday, hour, minute, second, tenths );
}
if ( obt_present )
{
year = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_obt_year, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
jday = tvb_get_ntohs ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_obt_jday, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
hour = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_obt_hour, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
minute = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_obt_minute, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
second = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_obt_second, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
tenths = tvb_get_guint8 ( tvb, *offset ) >> 4;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_obt_tenths, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
proto_tree_add_text ( ehs_secondary_header_tree, tvb, *offset-7, 7,
"%04d/%03d:%02d:%02d:%02d.%1d = OBT Time", year + 1900, jday, hour, minute, second, tenths );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_obt_delta_time_flag, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_obt_computed_flag, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_obt_not_retrieved_flag, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_obt_source_apid, tvb, *offset, 1, ENC_BIG_ENDIAN );
}
if ( mjfs_present )
{
proto_tree_add_text ( ehs_secondary_header_tree, tvb, *offset, 0, " " );
num_major_frames = 1 + tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_num_major_frame_status_words, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
for ( j=0; j < num_major_frames; ++j )
{
proto_tree_add_text ( ehs_secondary_header_tree, tvb, *offset, 1, "Major Frame Status Byte# %d", j );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_mjfs_parent_frame_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_mjfs_checksum_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_mjfs_fixed_value_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
}
}
proto_tree_add_text ( ehs_secondary_header_tree, tvb, *offset, 0, " " );
for ( j=0; j < num_minor_frames; ++j )
{
proto_tree_add_text ( ehs_secondary_header_tree, tvb, *offset, 1, "Minor Frame Status Byte# %d", j );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_mnfs_parent_frame_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_mnfs_data_not_available, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_mnfs_checksum_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_mnfs_fixed_value_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_mnfs_counter_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_mnfs_format_id_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_mnfs_bit_slip_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_tdm_mnfs_sync_error, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
}
}
static void
pseudo_secondary_header_dissector ( proto_tree* ehs_secondary_header_tree, tvbuff_t* tvb, int* offset )
{
*offset += 2;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_pseudo_workstation_id, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_pseudo_user_id, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_secondary_header_tree, hf_ehs_sh_pseudo_comp_id, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
}
static void
ehs_secondary_header_dissector ( int protocol, proto_tree* ehs_secondary_header_tree, tvbuff_t* tvb, int* offset )
{
switch ( protocol )
{
case EHS_PROTOCOL__TDM_TELEMETRY:
tdm_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
break;
case EHS_PROTOCOL__NASCOM_TELEMETRY:
*offset += ehs_secondary_header_size ( protocol, tvb, *offset );
break;
case EHS_PROTOCOL__PSEUDO_TELEMETRY:
pseudo_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
break;
case EHS_PROTOCOL__TDS_DATA:
*offset += ehs_secondary_header_size ( protocol, tvb, *offset );
break;
case EHS_PROTOCOL__TEST_DATA:
*offset += ehs_secondary_header_size ( protocol, tvb, *offset );
break;
case EHS_PROTOCOL__GSE_DATA:
*offset += ehs_secondary_header_size ( protocol, tvb, *offset );
break;
case EHS_PROTOCOL__CUSTOM_DATA:
*offset += ehs_secondary_header_size ( protocol, tvb, *offset );
break;
case EHS_PROTOCOL__HDRS_DQ:
*offset += ehs_secondary_header_size ( protocol, tvb, *offset );
break;
case EHS_PROTOCOL__CSS:
*offset += ehs_secondary_header_size ( protocol, tvb, *offset );
break;
case EHS_PROTOCOL__AOS_LOS:
aoslos_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
break;
case EHS_PROTOCOL__PDSS_PAYLOAD_CCSDS_PACKET:
payload_ccsds_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
break;
case EHS_PROTOCOL__PDSS_CORE_CCSDS_PACKET:
core_ccsds_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
break;
case EHS_PROTOCOL__PDSS_PAYLOAD_BPDU:
payload_bpdu_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
break;
case EHS_PROTOCOL__PDSS_UDSM:
udsm_secondary_header_dissector ( ehs_secondary_header_tree, tvb, offset );
break;
case EHS_PROTOCOL__PDSS_RPSM:
*offset += ehs_secondary_header_size ( protocol, tvb, *offset );
break;
default:
*offset += ehs_secondary_header_size ( protocol, tvb, *offset );
break;
}
}
static void
aoslos_data_zone_dissector ( proto_tree* ehs_tree, tvbuff_t* tvb, int* offset, packet_info* pinfo )
{
proto_item *ehs_data_zone;
proto_tree *ehs_data_zone_tree;
ehs_data_zone = proto_tree_add_text ( ehs_tree, tvb, *offset, pinfo->iplen - IP_HEADER_LENGTH - *offset, "AOS/LOS Data Zone" );
ehs_data_zone_tree = proto_item_add_subtree ( ehs_data_zone, ett_ehs_data_zone );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_aoslos_indicator, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
}
static void
udsm_data_zone_dissector ( proto_tree* ehs_tree, tvbuff_t* tvb, int* offset, packet_info* pinfo )
{
proto_item *ehs_data_zone;
proto_tree *ehs_data_zone_tree;
int year, jday, hour, minute, second;
ehs_data_zone = proto_tree_add_text ( ehs_tree, tvb, *offset, pinfo->iplen - IP_HEADER_LENGTH - *offset, "UDSM Data Zone" );
ehs_data_zone_tree = proto_item_add_subtree ( ehs_data_zone, ett_ehs_data_zone );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_ccsds_vs_bpdu, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
++(*offset);
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_gse_pkt_id, tvb, *offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_payload_vs_core, tvb, *offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_apid, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
year = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_start_time_year, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
jday = tvb_get_ntohs ( tvb, *offset );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_start_time_jday, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
hour = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_start_time_hour, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
minute = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_start_time_minute, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
second = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_start_time_second, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
proto_tree_add_text ( ehs_data_zone_tree, tvb, *offset-7, 7,
"%04d/%03d:%02d:%02d:%02d = UDSM Start Time", year + 1900, jday, hour, minute, second );
year = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_stop_time_year, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
jday = tvb_get_ntohs ( tvb, *offset );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_stop_time_jday, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
hour = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_stop_time_hour, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
minute = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_stop_time_minute, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
second = tvb_get_guint8 ( tvb, *offset );
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_stop_time_second, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
proto_tree_add_text ( ehs_data_zone_tree, tvb, *offset-7, 7,
"%04d/%03d:%02d:%02d:%02d = UDSM Stop Time", year + 1900, jday, hour, minute, second );
*offset += 2;
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_num_pkts_xmtd, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_num_vcdu_seqerrs, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_num_pkt_seqerrs, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_num_pktlen_errors, tvb, *offset, 2, ENC_BIG_ENDIAN );
*offset += 2;
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_event, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
proto_tree_add_item ( ehs_data_zone_tree, hf_ehs_dz_udsm_num_pkts_xmtd_rollover, tvb, *offset, 1, ENC_BIG_ENDIAN );
++(*offset);
}
static void
ehs_data_zone_dissector ( int protocol, proto_tree* ehs_tree, tvbuff_t* tvb, int* offset, packet_info* pinfo )
{
switch ( protocol )
{
case EHS_PROTOCOL__TDM_TELEMETRY:
break;
case EHS_PROTOCOL__NASCOM_TELEMETRY:
break;
case EHS_PROTOCOL__PSEUDO_TELEMETRY:
break;
case EHS_PROTOCOL__TDS_DATA:
break;
case EHS_PROTOCOL__TEST_DATA:
break;
case EHS_PROTOCOL__GSE_DATA:
break;
case EHS_PROTOCOL__CUSTOM_DATA:
break;
case EHS_PROTOCOL__HDRS_DQ:
break;
case EHS_PROTOCOL__CSS:
break;
case EHS_PROTOCOL__AOS_LOS:
aoslos_data_zone_dissector ( ehs_tree, tvb, offset, pinfo );
break;
case EHS_PROTOCOL__PDSS_PAYLOAD_CCSDS_PACKET:
break;
case EHS_PROTOCOL__PDSS_CORE_CCSDS_PACKET:
break;
case EHS_PROTOCOL__PDSS_PAYLOAD_BPDU:
break;
case EHS_PROTOCOL__PDSS_UDSM:
udsm_data_zone_dissector ( ehs_tree, tvb, offset, pinfo );
break;
case EHS_PROTOCOL__PDSS_RPSM:
break;
default:
break;
}
}
static void
dissect_ehs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint16 first_word;
tvbuff_t *new_tvb;
proto_item *ehs_packet;
proto_tree *ehs_tree;
proto_item *ehs_primary_header;
proto_tree *ehs_primary_header_tree;
proto_item *ehs_secondary_header;
proto_tree *ehs_secondary_header_tree;
int protocol;
int year, jday, hour, minute, second, tenths;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EHS");
col_set_str(pinfo->cinfo, COL_INFO, "EHS");
ehs_packet = proto_tree_add_item ( tree, proto_ehs, tvb, 0, -1, ENC_NA );
ehs_tree = proto_item_add_subtree ( ehs_packet, ett_ehs );
ehs_primary_header = proto_tree_add_text ( ehs_tree, tvb, offset, EHS_PRIMARY_HEADER_SIZE, "Primary EHS Header" );
ehs_primary_header_tree = proto_item_add_subtree ( ehs_primary_header, ett_ehs_primary_header );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_version, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_project, tvb, offset, 1, ENC_BIG_ENDIAN );
++offset;
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_support_mode, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_data_mode, tvb, offset, 1, ENC_BIG_ENDIAN );
++offset;
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_mission, tvb, offset, 1, ENC_BIG_ENDIAN );
++offset;
protocol = tvb_get_guint8 ( tvb, offset );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_protocol, tvb, offset, 1, ENC_BIG_ENDIAN );
++offset;
year = tvb_get_guint8 ( tvb, offset );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_year, tvb, offset, 1, ENC_BIG_ENDIAN );
++offset;
jday = tvb_get_ntohs ( tvb, offset );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_jday, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
hour = tvb_get_guint8 ( tvb, offset );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_hour, tvb, offset, 1, ENC_BIG_ENDIAN );
++offset;
minute = tvb_get_guint8 ( tvb, offset );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_minute, tvb, offset, 1, ENC_BIG_ENDIAN );
++offset;
second = tvb_get_guint8 ( tvb, offset );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_second, tvb, offset, 1, ENC_BIG_ENDIAN );
++offset;
tenths = tvb_get_guint8 ( tvb, offset ) >> 4;
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_tenths, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_text ( ehs_primary_header_tree, tvb, offset-7, 7,
"%04d/%03d:%02d:%02d:%02d.%1d = EHS Ground Receipt Time", year + 1900, jday, hour, minute, second, tenths );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_new_data_flag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_hold_flag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_sign_flag, tvb, offset, 1, ENC_BIG_ENDIAN );
++offset;
++offset;
++offset;
++offset;
proto_tree_add_item ( ehs_primary_header_tree, hf_ehs_ph_hosc_packet_size, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
ehs_secondary_header = proto_tree_add_text ( ehs_tree, tvb, offset,
ehs_secondary_header_size ( protocol, tvb, offset ), "Secondary EHS Header" );
ehs_secondary_header_tree = proto_item_add_subtree ( ehs_secondary_header, ett_ehs_secondary_header );
ehs_secondary_header_dissector ( protocol, ehs_secondary_header_tree, tvb, &offset );
switch ( protocol )
{
case EHS_PROTOCOL__TDM_TELEMETRY:
case EHS_PROTOCOL__PSEUDO_TELEMETRY:
case EHS_PROTOCOL__AOS_LOS:
case EHS_PROTOCOL__PDSS_PAYLOAD_CCSDS_PACKET:
case EHS_PROTOCOL__PDSS_CORE_CCSDS_PACKET:
case EHS_PROTOCOL__PDSS_UDSM:
new_tvb = tvb_new_subset_remaining ( tvb, offset);
call_dissector ( ccsds_handle, new_tvb, pinfo, ehs_tree );
first_word = tvb_get_ntohs ( tvb, offset );
offset += CCSDS_PRIMARY_HEADER_LENGTH;
if ( first_word & HDR_SECHDR ) offset += CCSDS_SECONDARY_HEADER_LENGTH;
break;
default:
break;
}
ehs_data_zone_dissector ( protocol, ehs_tree, tvb, &offset, pinfo );
}
void
proto_register_ehs(void)
{
static hf_register_info hf[] =
{
{ &hf_ehs_ph_version,
{ "Version", "ehs.version",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ehs_ph_project,
{ "Project", "ehs.project",
FT_UINT8, BASE_DEC, VALS(ehs_primary_header_project), 0x0f,
NULL, HFILL }
},
{ &hf_ehs_ph_support_mode,
{ "Support Mode", "ehs.support_mode",
FT_UINT8, BASE_DEC, VALS(ehs_primary_header_support_mode), 0xf0,
NULL, HFILL }
},
{ &hf_ehs_ph_data_mode,
{ "Data Mode", "ehs.data_mode",
FT_UINT8, BASE_DEC, VALS(ehs_primary_header_data_mode), 0x0f,
NULL, HFILL }
},
{ &hf_ehs_ph_mission,
{ "Mission", "ehs.mission",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_ph_protocol,
{ "Protocol", "ehs.protocol",
FT_UINT8, BASE_DEC, VALS(ehs_primary_header_protocol), 0xff,
NULL, HFILL }
},
{ &hf_ehs_ph_year,
{ "Years since 1900", "ehs.year",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_ph_jday,
{ "Julian Day of Year", "ehs.jday",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_ph_hour,
{ "Hour", "ehs.hour",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_ph_minute,
{ "Minute", "ehs.minute",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_ph_second,
{ "Second", "ehs.second",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_ph_tenths,
{ "Tenths", "ehs.tenths",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ehs_ph_new_data_flag,
{ "New Data Flag", "ehs.new_data_flag",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
#if 0
{ &hf_ehs_ph_pad1,
{ "Pad1", "ehs.pad1",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }
},
#endif
{ &hf_ehs_ph_hold_flag,
{ "Hold Flag", "ehs.hold_flag",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_ehs_ph_sign_flag,
{ "Sign Flag (1->CDT)", "ehs.sign_flag",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }
},
#if 0
{ &hf_ehs_ph_pad2,
{ "Pad2", "ehs.pad2",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_ph_pad3,
{ "Pad3", "ehs.pad3",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_ph_pad4,
{ "Pad4", "ehs.pad4",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
#endif
{ &hf_ehs_ph_hosc_packet_size,
{ "HOSC Packet Size", "ehs.hosc_packet_size",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_version,
{ "Version", "ehs2.version",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_ehs_sh_data_status_bit_5,
{ "Data Status Bit 5", "ehs2.data_status_bit_5",
FT_UINT8, BASE_DEC, NULL, 0x20,
NULL, HFILL }
},
{ &hf_ehs_sh_data_status_bit_4,
{ "Data Status Bit 4", "ehs2.data_status_bit_4",
FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL }
},
{ &hf_ehs_sh_data_status_bit_3,
{ "Data Status Bit 3", "ehs2.data_status_bit_3",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }
},
{ &hf_ehs_sh_data_status_bit_2,
{ "Data Status Bit 2", "ehs2.data_status_bit_2",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }
},
{ &hf_ehs_sh_data_status_bit_1,
{ "Data Status Bit 1", "ehs2.data_status_bit_1",
FT_UINT8, BASE_DEC, NULL, 0x02,
NULL, HFILL }
},
{ &hf_ehs_sh_data_status_bit_0,
{ "Data Status Bit 0", "ehs2.data_status_bit_0",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ehs_sh_parent_stream_error,
{ "Parent Stream Error", "ehs2.parent_stream_error",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_ehs_sh_vcdu_sequence_error,
{ "VCDU Sequence Error", "ehs2.vcdu_sequence_error",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_ehs_sh_packet_sequence_error,
{ "Packet Sequence Error", "ehs2.packet_sequence_error",
FT_UINT8, BASE_DEC, NULL, 0x02,
NULL, HFILL }
},
{ &hf_ehs_sh_vcdu_sequence_number,
{ "VCDU Sequence Number", "ehs2.vcdu_seqno",
FT_UINT24, BASE_DEC, NULL, 0xffffff,
NULL, HFILL }
},
{ &hf_ehs_sh_data_stream_id,
{ "Data Stream ID", "ehs2.data_stream_id",
FT_UINT8, BASE_DEC, VALS(ehs_secondary_header_data_stream_id), 0x80,
NULL, HFILL }
},
#if 0
{ &hf_ehs_sh_pdss_reserved_1,
{ "Pdss Reserved 1", "ehs2.pdss_reserved_1",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_ehs_sh_pdss_reserved_2,
{ "Pdss Reserved 2", "ehs2.pdss_reserved_2",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_pdss_reserved_3,
{ "Pdss Reserved 3", "ehs2.pdss_reserved_3",
FT_UINT16, BASE_DEC, NULL, 0xe000,
NULL, HFILL }
},
#endif
{ &hf_ehs_sh_gse_pkt_id,
{ "GSE Packet ID (1=GSE)", "ehs2.gse_pkt_id",
FT_UINT16, BASE_DEC, NULL, 0x1000,
NULL, HFILL }
},
{ &hf_ehs_sh_payload_vs_core_id,
{ "Payload vs Core ID", "ehs2.payload_vs_core_id",
FT_UINT16, BASE_DEC, VALS(ehs_secondary_header_payload_vs_core_id), 0x0800,
NULL, HFILL }
},
{ &hf_ehs_sh_apid,
{ "APID", "ehs2.apid",
FT_UINT16, BASE_DEC, NULL, 0x07ff,
NULL, HFILL }
},
{ &hf_ehs_sh_virtual_channel,
{ "Virtual Channel", "ehs2.vcid",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_pdss_reserved_sync,
{ "Pdss Reserved Sync", "ehs2.sync",
FT_UINT16, BASE_HEX, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_secondary_header_length,
{ "Secondary Header Length", "ehs2.tdm_secondary_header_length",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_extra_data_packet,
{ "Extra Data Packet", "ehs2.tdm_extra_data_packet",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_backup_stream_id_number,
{ "Backup Stream ID Number", "ehs2.tdm_backup_stream_id_number",
FT_UINT8, BASE_DEC, VALS(ehs_secondary_header_tdm_backup_stream_id), 0x60,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_end_of_data_flag,
{ "End of Data Flag", "ehs2.tdm_end_of_data_flag",
FT_UINT8, BASE_DEC, VALS(ehs_secondary_header_tdm_end_of_data_flag), 0x18,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_parent_frame_error,
{ "Parent Frame Error", "ehs2.tdm_parent_frame_error",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_checksum_error,
{ "Checksum Error", "ehs2.tdm_checksum_error",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_fixed_value_error,
{ "Fixed Value Error", "ehs2.tdm_fixed_value_error",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_minor_frame_counter_error,
{ "Minor Frame Counter Error", "ehs2.tdm_minor_frame_counter_error",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_format_id_error,
{ "Format ID Error", "ehs2.tdm_format_id_error",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_bit_slip_error,
{ "Bit Slip Error", "ehs2.tdm_bit_slip_error",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_sync_error,
{ "Sync Error", "ehs2.tdm_sync_error",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_aoslos_flag,
{ "AOS/LOS Flag", "ehs2.tdm_aoslos_flag",
FT_BOOLEAN, 8, TFS(&ehs_tfs_secondary_header_tdm_aoslos_flag), 0x08,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_override_errors_flag,
{ "Override Errors", "ehs2.tdm_override_errors_flag",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_data_status,
{ "Data Status", "ehs2.tdm_data_status",
FT_UINT8, BASE_DEC, VALS(ehs_secondary_header_tdm_data_status), 0x03,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_idq,
{ "IDQ", "ehs2.tdm_idq",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_cdq,
{ "CDQ", "ehs2.tdm_cdq",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_adq,
{ "ADQ", "ehs2.tdm_adq",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_data_dq,
{ "Data DQ", "ehs2.tdm_data_dq",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
#if 0
{ &hf_ehs_sh_tdm_unused,
{ "Unused", "ehs2.tdm_unused",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
#endif
{ &hf_ehs_sh_tdm_format_id,
{ "Format ID", "ehs2.tdm_format_id",
FT_UINT16, BASE_HEX, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_major_frame_packet_index,
{ "Major Frame Packet Index", "ehs2.tdm_major_frame_packet_index",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_numpkts_per_major_frame,
{ "Num Packets per Major Frame", "ehs2.tdm_numpkts_per_major_frame",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_num_minor_frames_per_packet,
{ "Num Minor Frames per Packet", "ehs2.tdm_num_minor_frame_per_packet",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_cntmet_present,
{ "CNT or MET Present", "ehs2.tdm_cntmet_present",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_obt_present,
{ "OBT Present", "ehs2.tdm_obt_present",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_major_frame_status_present,
{ "Major Frame Status Present", "ehs2.tdm_major_frame_status_present",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
#if 0
{ &hf_ehs_sh_tdm_reserved,
{ "Reserved", "ehs2.tdm_reserved",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
#endif
{ &hf_ehs_sh_tdm_cnt_year,
{ "CNT Years since 1900", "ehs2.tdm_cnt_year",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_cnt_jday,
{ "CNT Julian Day of Year", "ehs2.tdm_cnt_jday",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_cnt_hour,
{ "CNT Hour", "ehs2.tdm_cnt_hour",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_cnt_minute,
{ "CNT Minute", "ehs2.tdm_cnt_minute",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_cnt_second,
{ "CNT Second", "ehs2.tdm_cnt_second",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_cnt_tenths,
{ "CNT Tenths", "ehs2.tdm_cnt_tenths",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_obt_year,
{ "OBT Years since 1900", "ehs2.tdm_cnt_year",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_obt_jday,
{ "OBT Julian Day of Year", "ehs2.tdm_cnt_jday",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_obt_hour,
{ "OBT Hour", "ehs2.tdm_cnt_hour",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_obt_minute,
{ "OBT Minute", "ehs2.tdm_cnt_minute",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_obt_second,
{ "OBT Second", "ehs2.tdm_cnt_second",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_obt_tenths,
{ "OBT Tenths", "ehs2.tdm_cnt_tenths",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_obt_delta_time_flag,
{ "OBT is Delta Time Instead of GMT", "ehs2.tdm_obt_delta_time_flag",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_obt_computed_flag,
{ "OBT Computed", "ehs2.tdm_obt_computed_flag",
FT_BOOLEAN, 16, NULL, 0x4000,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_obt_not_retrieved_flag,
{ "OBT Not Retrieved", "ehs2.tdm_obt_not_retrieved_flag",
FT_BOOLEAN, 16, NULL, 0x2000,
NULL, HFILL }
},
#if 0
{ &hf_ehs_sh_tdm_obt_reserved,
{ "OBT Reserved", "ehs2.tdm_obt_reserved",
FT_BOOLEAN, 16, NULL, 0x1800,
NULL, HFILL }
},
#endif
{ &hf_ehs_sh_tdm_obt_source_apid,
{ "OBT Source APID", "ehs2.tdm_obt_source_apid",
FT_UINT16, BASE_DEC, NULL, 0x07ff,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_num_major_frame_status_words,
{ "Number of Major Frame Status Words", "ehs2.tdm_num_major_frame_status_words",
FT_UINT8, BASE_DEC, NULL, 0x0ff,
NULL, HFILL }
},
#if 0
{ &hf_ehs_sh_tdm_mjfs_reserved,
{ "Reserved", "ehs2.tdm_mjfs_reserved",
FT_UINT8, BASE_DEC, NULL, 0xf8,
NULL, HFILL }
},
#endif
{ &hf_ehs_sh_tdm_mjfs_parent_frame_error,
{ "Parent Frame Error", "ehs2.tdm_mjfs_parent_frame_error",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_mjfs_checksum_error,
{ "Checksum Error", "ehs2.tdm_mjfs_checksum_error",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_mjfs_fixed_value_error,
{ "Fixed Value Error", "ehs2.tdm_mjfs_fixed_value_error",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_mnfs_parent_frame_error,
{ "Parent Frame Error", "ehs2.tdm_mnfs_parent_frame_error",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_mnfs_data_not_available,
{ "Data Not Available", "ehs2.tdm_mnfs_data_not_available",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_mnfs_checksum_error,
{ "Checksum Error", "ehs2.tdm_mnfs_checksum_error",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_mnfs_fixed_value_error,
{ "Fixed Value Error", "ehs2.tdm_mnfs_fixed_value_error",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_mnfs_counter_error,
{ "Counter Error", "ehs2.tdm_mnfs_counter_error",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_mnfs_format_id_error,
{ "Format ID Error", "ehs2.tdm_mnfs_format_id_error",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_mnfs_bit_slip_error,
{ "Bit Slip Error", "ehs2.tdm_mnfs_bit_slip_error",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_ehs_sh_tdm_mnfs_sync_error,
{ "Sync Error", "ehs2.tdm_mnfs_sync_error",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
#if 0
{ &hf_ehs_sh_pseudo_unused,
{ "Unused", "ehs2.pseudo_unused",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
#endif
{ &hf_ehs_sh_pseudo_workstation_id,
{ "Workstation ID", "ehs2.pseudo_workstation_id",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_pseudo_user_id,
{ "User ID", "ehs2.pseudo_user_id",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_sh_pseudo_comp_id,
{ "Comp ID", "ehs2.pseudo_comp_id",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_dz_aoslos_indicator,
{ "AOS/LOS Indicator", "ehs.dz.aoslos_indicator",
FT_UINT8, BASE_DEC, VALS(ehs_data_zone_aoslos_indicator), 0x03,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_ccsds_vs_bpdu,
{ "CCSDS vs BPDU", "ehs.dz.udsm_ccsds_vs_bpdu",
FT_UINT8, BASE_DEC, VALS(ehs_data_zone_udsm_ccsds_vs_bpdu), 0x80,
NULL, HFILL }
},
#if 0
{ &hf_ehs_dz_udsm_unused1,
{ "Unused 1", "ehs.dz.udsm_unused1",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_unused2,
{ "Unused 2", "ehs.dz.udsm_unused2",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_unused3,
{ "Unused 3", "ehs.dz.udsm_unused3",
FT_UINT16, BASE_DEC, NULL, 0xe000,
NULL, HFILL }
},
#endif
{ &hf_ehs_dz_udsm_gse_pkt_id,
{ "GSE Pkt ID", "ehs.dz.udsm_gse_pkt_id",
FT_BOOLEAN, 16, NULL, 0x1000,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_payload_vs_core,
{ "Payload vs Core", "ehs.dz.udsm_payload_vs_core",
FT_UINT16, BASE_DEC, VALS(ehs_data_zone_udsm_payload_vs_core), 0x0800,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_apid,
{ "APID", "ehs.dz.udsm_apid",
FT_UINT16, BASE_DEC, NULL, 0x07ff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_start_time_year,
{ "Start Time Years since 1900", "ehs.dz.udsm_start_time_year",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_start_time_jday,
{ "Start Time Julian Day", "ehs.dz.udsm_start_time_jday",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_start_time_hour,
{ "Start Time Hour", "ehs.dz.udsm_start_time_hour",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_start_time_minute,
{ "Start Time Minute", "ehs.dz.udsm_start_time_minute",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_start_time_second,
{ "Start Time Second", "ehs.dz.udsm_start_time_second",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_stop_time_year,
{ "Stop Time Years since 1900", "ehs.dz.udsm_stop_time_year",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_stop_time_jday,
{ "Stop Time Julian Day", "ehs.dz.udsm_stop_time_jday",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_stop_time_hour,
{ "Stop Time Hour", "ehs.dz.udsm_stop_time_hour",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_stop_time_minute,
{ "Stop Time Minute", "ehs.dz.udsm_stop_time_minute",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_stop_time_second,
{ "Stop Time Second", "ehs.dz.udsm_stop_time_second",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
#if 0
{ &hf_ehs_dz_udsm_unused4,
{ "Unused 4", "ehs.dz.udsm_unused4",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
#endif
{ &hf_ehs_dz_udsm_num_pkts_xmtd,
{ "Num Pkts Transmitted", "ehs.dz.udsm_num_pkts_xmtd",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_num_vcdu_seqerrs,
{ "Num VCDU Sequence Errors", "ehs.dz.udsm_num_vcdu_seqerrs",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_num_pkt_seqerrs,
{ "Num Packet Sequence Errors", "ehs.dz.udsm_num_pkt_seqerrs",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_num_pktlen_errors,
{ "Num Pkt Length Errors", "ehs.dz.udsm_num_pktlen_errors",
FT_UINT16, BASE_DEC, NULL, 0xffff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_event,
{ "UDSM Event Code", "ehs.dz.udsm_event",
FT_UINT8, BASE_DEC, VALS(ehs_data_zone_udsm_event), 0xff,
NULL, HFILL }
},
{ &hf_ehs_dz_udsm_num_pkts_xmtd_rollover,
{ "Num Pkts Transmitted Rollover Counter", "ehs.dz.udsm_num_pkts_xmtd_rollover",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_ehs,
&ett_ehs_primary_header,
&ett_ehs_secondary_header,
&ett_ehs_data_zone
};
proto_ehs = proto_register_protocol("EHS", "EHS", "ehs");
proto_register_field_array(proto_ehs, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector ( "ehs", dissect_ehs, proto_ehs );
}
void
proto_reg_handoff_ehs(void)
{
dissector_add_handle ( "udp.port", find_dissector("ehs") );
ccsds_handle = find_dissector ( "ccsds" );
}
