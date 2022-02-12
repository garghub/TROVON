static void
reset_dissector(void)
{
bDissector_Called_Once_Before = FALSE;
}
static void
setup_dissector(void)
{
if ( local_scm_udid != NULL )
local_scm_udid = NULL;
reassembly_table_init(&os_reassembly_table, &addresses_reassembly_table_functions);
}
void opensafety_add_expert_note(packet_info *pinfo, proto_item *pi, int group, int severity, const char *format, ...)
{
va_list ap;
va_start(ap, format);
expert_add_info_format(pinfo, pi, group, severity, format, ap);
va_end(ap);
}
static guint16
findFrame1Position ( tvbuff_t *message_tvb, guint16 byte_offset, guint8 dataLength, gboolean checkIfSlimMistake )
{
guint16 i_wFrame1Position = 0;
guint16 i_payloadLength, i_calculatedLength = 0;
guint16 i_offset = 0, calcCRC = 0, frameCRC = 0;
guint8 b_tempByte = 0;
guint8 *bytes = NULL;
i_wFrame1Position = dataLength / 2 + 1;
i_payloadLength = tvb_get_guint8(message_tvb, byte_offset + i_wFrame1Position + 2 );
i_calculatedLength = i_payloadLength * 2 + 11 + 2 * (i_payloadLength > OSS_PAYLOAD_MAXSIZE_FOR_CRC8 ? 1 : 0);
if ( checkIfSlimMistake && i_calculatedLength == dataLength )
{
bytes = (guint8*)ep_tvb_memdup(message_tvb, byte_offset + i_wFrame1Position, dataLength + 4);
if ( dataLength > OSS_PAYLOAD_MAXSIZE_FOR_CRC8 )
calcCRC = crc16_0x5935(bytes, dataLength + 4, 0);
else
calcCRC = crc8_0x2F(bytes, dataLength + 4, 0);
if (dataLength > OSS_PAYLOAD_MAXSIZE_FOR_CRC8)
frameCRC = tvb_get_letohs(message_tvb, byte_offset + i_wFrame1Position + dataLength + OSS_FRAME_POS_DATA);
else
frameCRC = tvb_get_guint8(message_tvb, byte_offset + i_wFrame1Position + dataLength + OSS_FRAME_POS_DATA);
if ( frameCRC != calcCRC )
dataLength = 0;
}
if ( i_calculatedLength != dataLength )
{
i_wFrame1Position = 0;
i_offset = OSS_SLIM_FRAME2_WITH_CRC8 + ( dataLength < (OSS_SLIM_FRAME_WITH_CRC8_MAXSIZE + 1) ? 0 : 1 );
b_tempByte = ( tvb_get_guint8 ( message_tvb, byte_offset + i_offset + 1 ) ) & 0xFC;
if ( ( ( b_tempByte ^ OPENSAFETY_MSG_SSDO_SLIM_SERVICE_REQUEST ) == 0 ) ||
( ( b_tempByte ^ OPENSAFETY_MSG_SSDO_SLIM_SERVICE_RESPONSE ) == 0 ) )
{
i_wFrame1Position = i_offset;
}
}
return i_wFrame1Position;
}
static guint8 findSafetyFrame ( tvbuff_t * message_tvb, guint u_Offset, gboolean b_frame2first, guint *u_frameOffset, guint *u_frameLength )
{
guint ctr, rem_length;
guint16 crc, calcCrc;
guint8 b_Length, crcOffset;
guint8 *bytes;
guint b_ID;
gboolean found;
found = 0;
ctr = u_Offset;
rem_length = tvb_reported_length_remaining (message_tvb, ctr);
while ( rem_length >= OSS_MINIMUM_LENGTH)
{
if ( ctr != 0 )
{
*u_frameLength = 0;
*u_frameOffset = 0;
crcOffset = 0;
b_ID = tvb_get_guint8(message_tvb, ctr );
if ( b_ID != 0x0 )
{
b_Length = tvb_get_guint8(message_tvb, ctr + 1 );
if ( ( b_ID != 0xFF ) && ( b_ID & 0x80 ) )
{
if ( ( b_Length <= (guint) 8 && ( b_Length <= rem_length ) ) ||
( b_Length > (guint) 8 && ( ( b_Length + (guint) 5 ) <= rem_length ) ) )
{
if ( tvb_bytes_exist(message_tvb, ctr - 1, b_Length + 5) )
{
if ( ( ( b_ID >> 4 ) != 0x09 ) && ( ( b_ID >> 4 ) != 0x0F ) )
{
calcCrc = 0;
crc = tvb_get_guint8(message_tvb, ctr + 3 + b_Length );
bytes = (guint8 *)ep_tvb_memdup(message_tvb, ctr - 1, b_Length + 5 );
if ( b_Length > 8 ) {
crc = tvb_get_letohs ( message_tvb, ctr + 3 + b_Length );
crcOffset = 1;
if ( crc != 0x00 )
calcCrc = crc16_0x5935( bytes, b_Length + 4, 0 );
} else {
if ( crc != 0x00 )
calcCrc = crc8_0x2F ( bytes, b_Length + 4, 0 );
}
if ( ( crc != 0x00 ) && ( crc ^ calcCrc ) == 0 )
{
if ( ( b_ID >> 3 ) == ( OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE >> 3 ) )
{
*u_frameOffset = ( ctr - 1 );
*u_frameLength = b_Length + 2 * crcOffset + 11;
found = 1;
break;
}
else
{
*u_frameLength = 2 * b_Length + 2 * crcOffset + 11;
*u_frameOffset = ( ctr - 1 );
if ( tvb_get_guint8(message_tvb, *u_frameOffset + *u_frameLength - 2 ) != 0x00 ||
tvb_get_guint8(message_tvb, *u_frameOffset + *u_frameLength - 1 ) != 0x00 )
{
found = 1;
break;
}
}
}
}
}
}
}
}
}
ctr++;
rem_length = tvb_reported_length_remaining(message_tvb, ctr);
}
if ( b_frame2first && found )
*u_frameOffset = u_Offset;
return (found ? 1 : 0);
}
static void
dissect_opensafety_spdo_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *opensafety_tree,
guint16 frameStart1, guint16 frameStart2 , gboolean validSCMUDID, guint8 scm_udid[6])
{
proto_item *item;
proto_tree *spdo_tree;
guint16 ct;
gint16 taddr;
guint dataLength;
guint8 tr, b_ID, conn_Valid;
dataLength = tvb_get_guint8(message_tvb, OSS_FRAME_POS_LEN + frameStart1);
b_ID = tvb_get_guint8(message_tvb, frameStart1 + 1) & 0xF8;
conn_Valid = ( (tvb_get_guint8(message_tvb, frameStart1 + 1) & 0x04) == 0x04);
ct = tvb_get_guint8(message_tvb, frameStart1 + 3);
if ( validSCMUDID )
ct = (guint16)((tvb_get_guint8(message_tvb, frameStart2 + 2) ^ scm_udid[2]) << 8) +
(tvb_get_guint8(message_tvb, frameStart1 + 3));
taddr = ( ( OSS_FRAME_ADDR_T(message_tvb, frameStart1) ) ^ ( OSS_FRAME_ADDR_T2(message_tvb, frameStart2, scm_udid[0], scm_udid[1]) ) );
if ( ! validSCMUDID )
taddr = ( -1 * taddr );
PACKET_SENDER( pinfo, OSS_FRAME_ADDR_T(message_tvb, frameStart1), OSS_FRAME_POS_ADDR + frameStart1, frameStart2, taddr );
item = proto_tree_add_uint_format_value(opensafety_tree, hf_oss_msg_category, message_tvb,
OSS_FRAME_POS_ID + frameStart1, 1, OPENSAFETY_SPDO_MESSAGE_TYPE,
"%s", val_to_str_const(OPENSAFETY_SPDO_MESSAGE_TYPE, message_id_values, "Unknown") );
PROTO_ITEM_SET_GENERATED(item);
spdo_tree = proto_item_add_subtree(item, ett_opensafety_spdo);
if ( b_ID == OPENSAFETY_MSG_SPDO_DATA_WITH_TIME_RESPONSE )
proto_tree_add_boolean(spdo_tree, hf_oss_msg_direction, message_tvb,
OSS_FRAME_POS_ID + frameStart1, 1, OPENSAFETY_RESPONSE);
else if ( b_ID == OPENSAFETY_MSG_SPDO_DATA_WITH_TIME_REQUEST || b_ID == OPENSAFETY_MSG_SPDO_DATA_ONLY )
proto_tree_add_boolean(spdo_tree, hf_oss_msg_direction, message_tvb,
OSS_FRAME_POS_ID + frameStart1, 1, OPENSAFETY_REQUEST);
proto_tree_add_uint_format_value(spdo_tree, hf_oss_msg, message_tvb, OSS_FRAME_POS_ID + frameStart1, 1,
b_ID, "%s", val_to_str_const(b_ID, message_type_values, "Unknown") );
proto_tree_add_uint(spdo_tree, hf_oss_spdo_producer, message_tvb,
OSS_FRAME_POS_ADDR + frameStart1, 2, OSS_FRAME_ADDR_T(message_tvb, frameStart1));
proto_tree_add_boolean(spdo_tree, hf_oss_spdo_connection_valid, message_tvb,
OSS_FRAME_POS_ID + frameStart1, 1, conn_Valid);
taddr = OSS_FRAME_ADDR_T2(message_tvb, frameStart2 + 3, scm_udid[3], scm_udid[4]);
tr = ( tvb_get_guint8(message_tvb, frameStart2 + 4) ^ scm_udid[4] ) & 0xFC;
if ( b_ID == OPENSAFETY_MSG_SPDO_DATA_WITH_TIME_REQUEST )
{
item = proto_tree_add_uint_format_value(spdo_tree, hf_oss_spdo_time_value_sn, message_tvb, 0, 0, ct,
"0x%04X [%d] (%s)", ct, ct,
(validSCMUDID ? "Complete" : "Low byte only"));
PROTO_ITEM_SET_GENERATED(item);
proto_tree_add_uint(spdo_tree, hf_oss_spdo_time_request, message_tvb,
OSS_FRAME_POS_ADDR + frameStart2 + 4, 1, tr);
proto_tree_add_uint(spdo_tree, hf_oss_spdo_time_request_from, message_tvb,
OSS_FRAME_POS_ADDR + frameStart2 + 3, 2, taddr);
}
else
{
item = proto_tree_add_uint_format_value(spdo_tree, hf_oss_spdo_producer_time, message_tvb, 0, 0, ct,
"0x%04X [%d] (%s)", ct, ct, (validSCMUDID ? "Complete" : "Low byte only"));
PROTO_ITEM_SET_GENERATED(item);
if ( b_ID == OPENSAFETY_MSG_SPDO_DATA_WITH_TIME_RESPONSE )
{
proto_tree_add_uint(spdo_tree, hf_oss_spdo_time_request, message_tvb, OSS_FRAME_POS_ADDR + frameStart2 + 4, 1, tr);
proto_tree_add_uint(spdo_tree, hf_oss_spdo_time_request_to, message_tvb, OSS_FRAME_POS_ADDR + frameStart2 + 3, 2, taddr);
}
}
if ( dataLength > 0 )
proto_tree_add_item(spdo_tree, hf_oss_spdo_payload, message_tvb, OSS_FRAME_POS_ID + 3, dataLength, ENC_NA);
}
static void dissect_ssdo_payload ( packet_info *pinfo, tvbuff_t *new_tvb, proto_tree *ssdo_payload, guint8 sacmd )
{
guint dataLength = 0, ctr = 0, n = 0;
guint8 ssdoSubIndex = 0;
guint16 ssdoIndex = 0, dispSSDOIndex = 0;
guint32 sodLength = 0, entry = 0;
proto_item *item;
proto_tree *sod_tree, *ext_tree;
dataLength = tvb_length(new_tvb);
ssdoIndex = tvb_get_letohs(new_tvb, 0);
sodLength = tvb_get_letohl(new_tvb, 4);
if ( dataLength == 16 || sodLength == ( dataLength - 16 ) || ssdoIndex == 0x0101 )
{
item = proto_tree_add_string_format(ssdo_payload, hf_oss_ssdo_extpar,
new_tvb, 0, dataLength, "", "Extended Parameter Set: %s",
(dataLength == 16 ? "Header only" : "Header & Data") );
ext_tree = proto_item_add_subtree(item, ett_opensafety_ssdo_extpar);
proto_tree_add_item(ext_tree, hf_oss_ssdo_extpar_parset, new_tvb, 0, 1, ENC_BIG_ENDIAN );
proto_tree_add_item(ext_tree, hf_oss_ssdo_extpar_version, new_tvb, 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item(ext_tree, hf_oss_ssdo_extpar_saddr, new_tvb, 2, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_uint_format_value(ext_tree, hf_oss_ssdo_extpar_length,
new_tvb, 4, 4, sodLength, "0x%04X (%d octets)",
sodLength, sodLength );
proto_tree_add_item(ext_tree, hf_oss_ssdo_extpar_crc, new_tvb, 8, 4, ENC_LITTLE_ENDIAN );
proto_tree_add_item(ext_tree, hf_oss_ssdo_extpar_tstamp, new_tvb, 12, 4, ENC_LITTLE_ENDIAN );
if ( dataLength != 16 )
{
item = proto_tree_add_item(ext_tree, hf_oss_ssdo_extpar_data, new_tvb, 16, dataLength - 16, ENC_NA );
if ( ( dataLength - sodLength ) != 16 )
opensafety_add_error ( pinfo, item, "Reassembled message size differs from size in header!");
}
}
else
{
if ( sacmd == OPENSAFETY_MSG_SSDO_UPLOAD_SEGMENT_END && ( dataLength % 4 == 0 ) )
{
item = proto_tree_add_uint_format_value(ssdo_payload, hf_oss_ssdo_sod_index, new_tvb,
0, 0, 0x1018, "0x%04X (%s)", 0x1018,
val_to_str_const( ((guint32) (0x1018 << 16) ),
sod_idx_names, "Unknown") );
sod_tree = proto_item_add_subtree(item, ett_opensafety_ssdo_sodentry);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_uint_format_value(sod_tree, hf_oss_ssdo_sod_subindex, new_tvb, 0, 0,
0x06, "0x%02X (%s)", 0x06,
val_to_str_const(((guint32) (0x1018 << 16) + 0x06),
sod_idx_names, "Unknown") );
PROTO_ITEM_SET_GENERATED(item);
entry = tvb_get_letohl ( new_tvb, 0 );
proto_tree_add_uint_format_value ( sod_tree, hf_oss_sod_par_timestamp, new_tvb, 0,
4, entry, "0x%08X", entry );
for ( n = 4; n < dataLength; n+=4 )
{
entry = tvb_get_letohl ( new_tvb, n );
proto_tree_add_uint_format_value ( sod_tree, hf_oss_sod_par_checksum, new_tvb, (n ),
4, entry, "[#%d] 0x%08X", ( n / 4 ), entry );
}
}
else
{
for ( ctr = 0; ctr < dataLength; ctr++ )
{
ssdoIndex = tvb_get_letohs(new_tvb, ctr);
ssdoSubIndex = tvb_get_guint8(new_tvb, ctr + 2);
dispSSDOIndex = ssdoIndex;
if ( ssdoIndex >= 0x1400 && ssdoIndex <= 0x17FE )
dispSSDOIndex = 0x1400;
else if ( ssdoIndex >= 0x1800 && ssdoIndex <= 0x1BFE )
dispSSDOIndex = 0x1800;
else if ( ssdoIndex >= 0x1C00 && ssdoIndex <= 0x1FFE )
dispSSDOIndex = 0x1C00;
else if ( ssdoIndex >= 0xC000 && ssdoIndex <= 0xC3FE )
dispSSDOIndex = 0xC000;
item = proto_tree_add_uint_format_value(ssdo_payload, hf_oss_ssdo_sod_index, new_tvb,
ctr, 2, ssdoIndex, "0x%04X (%s)", ssdoIndex,
val_to_str_const( ((guint32) (dispSSDOIndex << 16) ),
sod_idx_names, "Unknown") );
if ( ssdoIndex < 0x1000 || ssdoIndex > 0xE7FF )
opensafety_add_error ( pinfo, item, "Unknown payload format detected!" );
sod_tree = proto_item_add_subtree(item, ett_opensafety_ssdo_sodentry);
if ( ssdoSubIndex != 0 )
proto_tree_add_uint_format_value(sod_tree, hf_oss_ssdo_sod_subindex, new_tvb, ctr + 2, 1,
ssdoSubIndex, "0x%02X (%s)", ssdoSubIndex,
val_to_str_const(((guint32) (ssdoIndex << 16) + ssdoSubIndex),
sod_idx_names, "Unknown") );
else
proto_tree_add_uint_format_value(sod_tree, hf_oss_ssdo_sod_subindex, new_tvb, ctr + 2, 1,
ssdoSubIndex, "0x%02X",ssdoSubIndex );
ctr += 2;
sodLength = tvb_get_letohl ( new_tvb, ctr + 1 );
if ( sodLength > (dataLength - ctr) )
sodLength = 0;
if ( ( sodLength + 4 + ctr ) > dataLength )
break;
if ( ssdoIndex == OPENSAFETY_SOD_DVI && ssdoSubIndex == 0x06 )
{
entry = tvb_get_letohl ( new_tvb, ctr + 5 );
proto_tree_add_uint_format_value ( sod_tree, hf_oss_sod_par_timestamp, new_tvb, ctr + 5,
4, entry, "0x%08X", entry );
for ( n = 4; n < sodLength; n+=4 )
{
entry = tvb_get_letohl ( new_tvb, ctr + 5 + n );
proto_tree_add_uint_format_value ( sod_tree, hf_oss_sod_par_checksum, new_tvb, (ctr + 5 + n ),
4, entry, "[#%d] 0x%08X", ( n / 4 ), entry );
}
} else if ( ssdoIndex == OPENSAFETY_SOD_DVI && ssdoSubIndex == 0x07 ) {
entry = tvb_get_letohl ( new_tvb, ctr + 5 );
proto_tree_add_uint_format_value ( sod_tree, hf_oss_sod_par_timestamp, new_tvb, ctr + 5,
4, entry, "0x%08X", entry );
} else if ( ( dispSSDOIndex == OPENSAFETY_SOD_RXMAP || dispSSDOIndex == OPENSAFETY_SOD_TXMAP ) && ssdoSubIndex != 0x0 ) {
proto_tree_add_uint(sod_tree, hf_oss_ssdo_sodentry_size, new_tvb, ctr + 1, 4, sodLength );
item = proto_tree_add_item(sod_tree, hf_oss_ssdo_sodmapping, new_tvb, ctr + 5, sodLength, ENC_NA );
ext_tree = proto_item_add_subtree(item, ett_opensafety_sod_mapping);
proto_tree_add_item(ext_tree, hf_oss_ssdo_sodmapping_bits, new_tvb, ctr + 5, 1, ENC_NA);
entry = tvb_get_letohl ( new_tvb, ctr + 7 );
proto_tree_add_item(ext_tree, hf_oss_ssdo_sod_index, new_tvb, ctr + 7, 2, entry);
proto_tree_add_item(ext_tree, hf_oss_ssdo_sod_subindex, new_tvb, ctr + 6, 1, ENC_NA);
} else {
proto_tree_add_uint(sod_tree, hf_oss_ssdo_sodentry_size, new_tvb, ctr + 1, 4, sodLength );
if ( sodLength > 0 )
proto_tree_add_item(sod_tree, hf_oss_ssdo_sodentry_data, new_tvb, ctr + 5, sodLength, ENC_LITTLE_ENDIAN );
}
ctr += sodLength + 4;
}
}
}
}
static void
dissect_opensafety_ssdo_message(tvbuff_t *message_tvb , packet_info *pinfo, proto_tree *opensafety_tree ,
guint16 frameStart1, guint16 frameStart2 , gboolean validSCMUDID, guint8 scm_udid[6])
{
proto_item *item;
proto_tree *ssdo_tree, *ssdo_payload, *ssdo_sacmd_tree;
guint16 taddr = 0, sdn = 0, server = 0, client = 0, n = 0, ct = 0;
guint32 abortcode, ssdoIndex = 0, ssdoSubIndex = 0, payloadSize, fragmentId = 0, entry = 0;
guint8 db0Offset, db0, sacmd, payloadOffset;
guint dataLength;
gint calcDataLength;
gboolean isResponse, decodePayload, isEndSegment, isSegmented, saveFragmented;
tvbuff_t* new_tvb = NULL;
fragment_data *frag_msg = NULL;
dataLength = tvb_get_guint8(message_tvb, OSS_FRAME_POS_LEN + frameStart1);
decodePayload = FALSE;
db0Offset = frameStart1 + OSS_FRAME_POS_DATA;
db0 = tvb_get_guint8(message_tvb, db0Offset);
sacmd = db0;
ssdoIndex = 0;
ssdoSubIndex = 0;
if ( ( sacmd & OPENSAFETY_SSDO_SACMD_TGL ) == OPENSAFETY_SSDO_SACMD_TGL )
sacmd = sacmd & ( ~OPENSAFETY_SSDO_SACMD_TGL );
isResponse = ( ( OSS_FRAME_ID_T(message_tvb, frameStart1) & 0x04 ) == 0x04 );
if ( validSCMUDID )
{
taddr = OSS_FRAME_ADDR_T2(message_tvb, frameStart2 + 3, scm_udid[3], scm_udid[4]);
sdn = ( OSS_FRAME_ADDR_T(message_tvb, frameStart1) ^
( OSS_FRAME_ADDR_T2(message_tvb, frameStart2, scm_udid[0], scm_udid[1]) ) );
PACKET_SENDER_RECEIVER ( pinfo, taddr, frameStart2 + 3, OSS_FRAME_ADDR_T(message_tvb, frameStart1),
frameStart1, frameStart2, sdn );
}
else if ( ! isResponse )
{
PACKET_SENDER(pinfo, OSS_FRAME_ADDR_T(message_tvb, frameStart1), frameStart1, frameStart2,
-1 * ( ( OSS_FRAME_ADDR_T(message_tvb, frameStart1) ) ^ ( OSS_FRAME_ADDR_T2(message_tvb, frameStart2, scm_udid[0], scm_udid[1]) ) ) );
}
else if ( isResponse )
{
PACKET_RECEIVER(pinfo, OSS_FRAME_ADDR_T(message_tvb, frameStart1), frameStart1, frameStart2,
-1 * ( ( OSS_FRAME_ADDR_T(message_tvb, frameStart1) ) ^ ( OSS_FRAME_ADDR_T2(message_tvb, frameStart2, scm_udid[0], scm_udid[1]) ) ) );
}
if ( ( OSS_FRAME_ID_T(message_tvb, frameStart1) == OPENSAFETY_MSG_SSDO_SLIM_SERVICE_REQUEST ) ||
( OSS_FRAME_ID_T(message_tvb, frameStart1) == OPENSAFETY_MSG_SSDO_SLIM_SERVICE_RESPONSE ) )
item = proto_tree_add_uint_format_value(opensafety_tree, hf_oss_msg_category, message_tvb,
OSS_FRAME_POS_ID + frameStart1, 1,
OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE,
"%s", val_to_str_const(OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE, message_id_values, "Unknown") );
else
item = proto_tree_add_uint_format_value(opensafety_tree, hf_oss_msg_category, message_tvb, OSS_FRAME_POS_ID + frameStart1, 1,
OPENSAFETY_SSDO_MESSAGE_TYPE,
"%s", val_to_str_const(OPENSAFETY_SSDO_MESSAGE_TYPE, message_id_values, "Unknown") );
PROTO_ITEM_SET_GENERATED(item);
ssdo_tree = proto_item_add_subtree(item, ett_opensafety_ssdo);
if ( ( OSS_FRAME_ID_T(message_tvb, frameStart1) == OPENSAFETY_MSG_SSDO_SERVICE_RESPONSE ) ||
( OSS_FRAME_ID_T(message_tvb, frameStart1) == OPENSAFETY_MSG_SSDO_SLIM_SERVICE_RESPONSE ) )
proto_tree_add_boolean(ssdo_tree, hf_oss_msg_direction, message_tvb, OSS_FRAME_POS_ID + frameStart1, 1, OPENSAFETY_RESPONSE);
else
proto_tree_add_boolean(ssdo_tree, hf_oss_msg_direction, message_tvb, OSS_FRAME_POS_ID + frameStart1, 1, OPENSAFETY_REQUEST);
proto_tree_add_uint_format_value(ssdo_tree, hf_oss_msg, message_tvb, OSS_FRAME_POS_ID + frameStart1, 1,
OSS_FRAME_ID_T(message_tvb, frameStart1),
"%s", val_to_str_const(OSS_FRAME_ID_T(message_tvb, frameStart1), message_type_values, "Unknown") );
if ( isResponse )
{
if ( validSCMUDID )
{
proto_tree_add_uint(ssdo_tree, hf_oss_ssdo_client, message_tvb, frameStart1, 2, OSS_FRAME_ADDR_T(message_tvb, frameStart1));
client = OSS_FRAME_ADDR_T(message_tvb, frameStart1);
proto_tree_add_uint(ssdo_tree, hf_oss_ssdo_server, message_tvb, frameStart2 + 3, 2, taddr);
server = taddr;
}
else
{
proto_tree_add_uint(ssdo_tree, hf_oss_ssdo_client, message_tvb, frameStart1, 2, OSS_FRAME_ADDR_T(message_tvb, frameStart1));
client = OSS_FRAME_ADDR_T(message_tvb, frameStart1);
}
}
else if ( ! isResponse )
{
if ( validSCMUDID )
{
proto_tree_add_uint(ssdo_tree, hf_oss_ssdo_server, message_tvb, frameStart1, 2, OSS_FRAME_ADDR_T(message_tvb, frameStart1));
server = OSS_FRAME_ADDR_T(message_tvb, frameStart1);
proto_tree_add_uint(ssdo_tree, hf_oss_ssdo_client, message_tvb, frameStart2 + 3, 2, taddr);
client = taddr;
}
else
{
proto_tree_add_uint(ssdo_tree, hf_oss_ssdo_server, message_tvb, frameStart1, 2, OSS_FRAME_ADDR_T(message_tvb, frameStart1));
server = OSS_FRAME_ADDR_T(message_tvb, frameStart1);
}
}
item = proto_tree_add_uint(ssdo_tree, hf_oss_ssdo_sacmd, message_tvb, db0Offset, 1, sacmd);
col_append_fstr(pinfo->cinfo, COL_INFO, ", SACMD: %s", val_to_str_const(sacmd, ssdo_sacmd_values, " "));
ssdo_sacmd_tree = proto_item_add_subtree(item, ett_opensafety_ssdo_sacmd);
proto_tree_add_boolean(ssdo_sacmd_tree, hf_oss_ssdo_sacmd_block_transfer, message_tvb, db0Offset, 1, db0);
proto_tree_add_boolean(ssdo_sacmd_tree, hf_oss_ssdo_sacmd_end_segment, message_tvb, db0Offset, 1, db0);
proto_tree_add_boolean(ssdo_sacmd_tree, hf_oss_ssdo_sacmd_initiate, message_tvb, db0Offset, 1, db0);
proto_tree_add_boolean(ssdo_sacmd_tree, hf_oss_ssdo_sacmd_toggle, message_tvb, db0Offset, 1, db0);
proto_tree_add_boolean(ssdo_sacmd_tree, hf_oss_ssdo_sacmd_segmentation, message_tvb, db0Offset, 1, db0);
proto_tree_add_boolean(ssdo_sacmd_tree, hf_oss_ssdo_sacmd_abort_transfer, message_tvb, db0Offset, 1, db0);
proto_tree_add_boolean(ssdo_sacmd_tree, hf_oss_ssdo_sacmd_access_type, message_tvb, db0Offset, 1, db0);
payloadOffset = db0Offset + 1;
ct = tvb_get_guint8(message_tvb, frameStart1 + 3);
if ( validSCMUDID )
ct = (guint16)((tvb_get_guint8(message_tvb, frameStart2 + 2) ^ scm_udid[2]) << 8) + (tvb_get_guint8(message_tvb, frameStart1 + 3));
proto_tree_add_uint(ssdo_tree, hf_oss_ssdo_sano, message_tvb, frameStart1 + 3, 1, ct );
if ( ( ( sacmd & OPENSAFETY_SSDO_SACMD_INI ) == OPENSAFETY_SSDO_SACMD_INI ) ||
( sacmd == OPENSAFETY_MSG_SSDO_ABORT )
)
{
ssdoIndex = tvb_get_letohs(message_tvb, db0Offset + 1);
ssdoSubIndex = tvb_get_guint8(message_tvb, db0Offset + 3);
proto_tree_add_uint_format_value(ssdo_tree, hf_oss_ssdo_sod_index, message_tvb, db0Offset + 1, 2,
ssdoIndex, "0x%04X (%s)", ssdoIndex,
val_to_str_const(((guint32) (ssdoIndex << 16)), sod_idx_names, "Unknown") );
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s", val_to_str_const(((guint32) (ssdoIndex << 16)), sod_idx_names, "0x%04X"));
if ( ssdoSubIndex != 0x0 )
{
proto_tree_add_uint_format_value(ssdo_tree, hf_oss_ssdo_sod_subindex, message_tvb, db0Offset + 3, 1,
ssdoSubIndex, "0x%02X (%s)", ssdoSubIndex,
val_to_str_const(((guint32) (ssdoIndex << 16) + ssdoSubIndex), sod_idx_names, "Unknown") );
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s",
val_to_str_const(((guint32) (ssdoIndex << 16) + ssdoSubIndex), sod_idx_names, "0x%02X"));
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", "]" );
payloadOffset += 3;
}
if ( sacmd == OPENSAFETY_MSG_SSDO_ABORT )
{
abortcode = tvb_get_ntohl(message_tvb, frameStart1 + OSS_FRAME_POS_DATA + 4);
proto_tree_add_uint_format_value(ssdo_tree, hf_oss_ssdo_abort_code, message_tvb, payloadOffset, 4, abortcode,
"0x%04X %04X - %s", (guint16)(abortcode >> 16), (guint16)(abortcode),
val_to_str_const(abortcode, abort_codes, "Unknown"));
} else {
if ( ( isResponse && (sacmd == OPENSAFETY_MSG_SSDO_UPLOAD_INITIATE_SEGMENTED ||
sacmd == OPENSAFETY_MSG_SSDO_UPLOAD_INITIATE_EXPEDITED ||
sacmd == OPENSAFETY_MSG_SSDO_UPLOAD_SEGMENT_MIDDLE ||
sacmd == OPENSAFETY_MSG_SSDO_UPLOAD_SEGMENT_END ) )||
( !isResponse && (sacmd == OPENSAFETY_MSG_SSDO_DOWNLOAD_INITIATE_SEGMENTED ||
sacmd == OPENSAFETY_MSG_SSDO_DOWNLOAD_INITIATE_EXPEDITED ||
sacmd == OPENSAFETY_MSG_SSDO_DOWNLOAD_SEGMENT_MIDDLE ||
sacmd == OPENSAFETY_MSG_SSDO_DOWNLOAD_SEGMENT_END ) ) )
{
decodePayload = TRUE;
}
if ( decodePayload )
{
saveFragmented = pinfo->fragmented;
if ( server != 0 && client != 0 )
fragmentId = (guint32)((((guint32)client) << 16 ) + server );
isSegmented = ( ( db0 & OPENSAFETY_SSDO_SACMD_SEG ) == OPENSAFETY_SSDO_SACMD_SEG );
if ( ( sacmd == OPENSAFETY_MSG_SSDO_DOWNLOAD_INITIATE_SEGMENTED ) ||
( sacmd == OPENSAFETY_MSG_SSDO_UPLOAD_INITIATE_SEGMENTED )
)
{
payloadOffset += 4;
payloadSize = tvb_get_letohl(message_tvb, payloadOffset - 4);
calcDataLength = dataLength - (payloadOffset - db0Offset);
item = proto_tree_add_uint_format_value(ssdo_tree, hf_oss_ssdo_payload_size, message_tvb, payloadOffset - 4, 4,
payloadSize, "%d octets total (%d octets in this frame)", payloadSize, calcDataLength);
if ( fragmentId != 0 && isSegmented )
{
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_check(&os_reassembly_table, message_tvb, payloadOffset, pinfo,
fragmentId, NULL, 0, calcDataLength, TRUE );
fragment_add_seq_offset ( &os_reassembly_table, pinfo, fragmentId, NULL, ct );
if ( frag_msg != NULL )
{
item = proto_tree_add_bytes_format_value(ssdo_tree, hf_oss_ssdo_payload, message_tvb, 0, 0, NULL, "Reassembled" );
PROTO_ITEM_SET_GENERATED(item);
ssdo_payload = proto_item_add_subtree(item, ett_opensafety_ssdo_payload);
process_reassembled_data(message_tvb, 0, pinfo, "Reassembled Message", frag_msg, &oss_frag_items, NULL, ssdo_payload );
}
}
if ( (gint) calcDataLength >= (gint) 0 )
{
proto_tree_add_item(ssdo_tree, hf_oss_ssdo_payload, message_tvb, payloadOffset, calcDataLength, ENC_NA );
} else {
opensafety_add_warning1(pinfo, item, "Calculation for payload length yielded non-positive result [%d]", (guint) calcDataLength );
}
}
else
{
isEndSegment = FALSE;
if ( ( sacmd == OPENSAFETY_MSG_SSDO_DOWNLOAD_SEGMENT_END ) || ( sacmd == OPENSAFETY_MSG_SSDO_UPLOAD_SEGMENT_END ) )
isEndSegment = TRUE;
payloadSize = dataLength - (payloadOffset - db0Offset);
if ( fragmentId != 0 && isSegmented )
{
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_check(&os_reassembly_table, message_tvb, payloadOffset, pinfo,
fragmentId, NULL,ct,
payloadSize, isEndSegment ? FALSE : TRUE );
}
if ( frag_msg )
{
item = proto_tree_add_bytes_format_value(ssdo_tree, hf_oss_ssdo_payload, message_tvb,
0, 0, NULL, "Reassembled" );
PROTO_ITEM_SET_GENERATED(item);
ssdo_payload = proto_item_add_subtree(item, ett_opensafety_ssdo_payload);
new_tvb = process_reassembled_data(message_tvb, 0, pinfo, "Reassembled Message", frag_msg,
&oss_frag_items, NULL, ssdo_payload );
if ( isEndSegment && new_tvb )
{
item = proto_tree_add_uint_format_value(ssdo_payload, hf_oss_ssdo_payload_size, message_tvb, 0, 0,
payloadSize, "%d octets (over all fragments)", frag_msg->len);
PROTO_ITEM_SET_GENERATED(item);
col_append_str(pinfo->cinfo, COL_INFO, " (Message Reassembled)" );
dissect_ssdo_payload ( pinfo, new_tvb, ssdo_payload, sacmd );
}
}
else
{
item = proto_tree_add_uint_format_value(ssdo_tree, hf_oss_ssdo_payload_size, message_tvb, 0, 0, payloadSize,
"%d octets", payloadSize);
PROTO_ITEM_SET_GENERATED(item);
if ( ssdoIndex == OPENSAFETY_SOD_DVI && ssdoSubIndex == 0x06 )
{
entry = tvb_get_letohl ( message_tvb, payloadOffset );
proto_tree_add_uint_format_value ( ssdo_tree, hf_oss_sod_par_timestamp, message_tvb, payloadOffset,
4, entry, "0x%08X", entry );
for ( n = 4; n < payloadSize; n+=4 )
{
entry = tvb_get_letohl ( message_tvb, payloadOffset + n );
proto_tree_add_uint_format_value ( ssdo_tree, hf_oss_sod_par_checksum, message_tvb, (payloadOffset + n ),
4, entry, "[#%d] 0x%08X", ( n / 4 ), entry );
}
} else if ( ssdoIndex == OPENSAFETY_SOD_DVI && ssdoSubIndex == 0x07 ) {
entry = tvb_get_letohl ( message_tvb, payloadOffset );
proto_tree_add_uint_format_value ( ssdo_tree, hf_oss_sod_par_timestamp, message_tvb, payloadOffset,
4, entry, "0x%08X", entry );
} else
proto_tree_add_item(ssdo_tree, hf_oss_ssdo_payload, message_tvb, payloadOffset, payloadSize, ENC_NA );
}
}
pinfo->fragmented = saveFragmented;
}
}
}
static void
dissect_opensafety_snmt_message(tvbuff_t *message_tvb, packet_info *pinfo , proto_tree *opensafety_tree,
guint16 frameStart1, guint16 frameStart2 )
{
proto_item *item;
proto_tree *snmt_tree;
guint32 entry = 0;
guint16 addr, taddr, sdn;
guint8 db0, byte;
guint dataLength;
char *tempString;
dataLength = OSS_FRAME_LENGTH_T(message_tvb, frameStart1);
addr = OSS_FRAME_ADDR_T(message_tvb, frameStart1);
taddr = OSS_FRAME_ADDR_T(message_tvb, frameStart2 + 3);
sdn = OSS_FRAME_ADDR_T(message_tvb, frameStart2) ^ addr;
db0 = -1;
if (dataLength > 0)
db0 = tvb_get_guint8(message_tvb, frameStart1 + OSS_FRAME_POS_DATA);
if ( ( (OSS_FRAME_ID_T(message_tvb, frameStart1) ^ OPENSAFETY_MSG_SNMT_SERVICE_RESPONSE) == 0 ) &&
( (db0 ^ OPENSAFETY_MSG_SNMT_EXT_SCM_SET_TO_STOP) == 0 || (db0 ^ OPENSAFETY_MSG_SNMT_EXT_SCM_SET_TO_OP) == 0 ) )
{
PACKET_RECEIVER( pinfo, addr, OSS_FRAME_POS_ADDR + frameStart1, frameStart2, sdn );
}
else
{
PACKET_SENDER_RECEIVER ( pinfo, taddr, OSS_FRAME_POS_ADDR + frameStart1, addr, frameStart2 + 3,
frameStart2, sdn );
}
item = proto_tree_add_uint_format_value(opensafety_tree, hf_oss_msg_category, message_tvb, OSS_FRAME_POS_ID + frameStart1, 1,
OPENSAFETY_SNMT_MESSAGE_TYPE,
"%s", val_to_str_const(OPENSAFETY_SNMT_MESSAGE_TYPE, message_id_values, "Unknown") );
PROTO_ITEM_SET_GENERATED(item);
snmt_tree = proto_item_add_subtree(item, ett_opensafety_snmt);
if ( ( OSS_FRAME_ID_T(message_tvb, frameStart1) == OPENSAFETY_MSG_SNMT_RESPONSE_UDID ) ||
( OSS_FRAME_ID_T(message_tvb, frameStart1) == OPENSAFETY_MSG_SNMT_SADR_ASSIGNED ) ||
( OSS_FRAME_ID_T(message_tvb, frameStart1) == OPENSAFETY_MSG_SNMT_SERVICE_RESPONSE ) )
proto_tree_add_boolean(snmt_tree, hf_oss_msg_direction, message_tvb, OSS_FRAME_POS_ID + frameStart1, 1, OPENSAFETY_RESPONSE);
else
proto_tree_add_boolean(snmt_tree, hf_oss_msg_direction, message_tvb, OSS_FRAME_POS_ID + frameStart1, 1, OPENSAFETY_REQUEST);
proto_tree_add_uint_format_value(snmt_tree, hf_oss_msg, message_tvb, OSS_FRAME_POS_ID + frameStart1, 1,
OSS_FRAME_ID_T(message_tvb, frameStart1),
"%s", val_to_str_const(OSS_FRAME_ID_T(message_tvb, frameStart1), message_type_values, "Unknown") );
if ( (OSS_FRAME_ID_T(message_tvb, frameStart1) ^ OPENSAFETY_MSG_SNMT_SN_RESET_GUARDING_SCM) == 0 )
{
proto_tree_add_uint(snmt_tree, hf_oss_snmt_master, message_tvb, OSS_FRAME_POS_ADDR + frameStart1, 2, addr);
proto_tree_add_uint(snmt_tree, hf_oss_snmt_slave, message_tvb, frameStart2 + 3, 2, taddr);
}
else if ( (OSS_FRAME_ID_T(message_tvb, frameStart1) ^ OPENSAFETY_MSG_SNMT_SERVICE_RESPONSE) == 0 )
{
proto_tree_add_uint(snmt_tree, hf_oss_snmt_service_id, message_tvb, OSS_FRAME_POS_DATA + frameStart1, 1, db0);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", val_to_str_const(db0, message_service_type, "Unknown"));
proto_tree_add_uint(snmt_tree, hf_oss_snmt_master, message_tvb, OSS_FRAME_POS_ADDR + frameStart1, 2, addr);
proto_tree_add_uint(snmt_tree, hf_oss_snmt_slave, message_tvb, frameStart2 + 3, 2, taddr);
if ( (db0 ^ OPENSAFETY_MSG_SNMT_EXT_SN_FAIL) == 0 )
{
byte = tvb_get_guint8(message_tvb, OSS_FRAME_POS_DATA + frameStart1 + 1);
proto_tree_add_uint_format(snmt_tree, hf_oss_snmt_error_group, message_tvb, OSS_FRAME_POS_DATA + frameStart1 + 1, 1,
byte, "%s", ( byte == 0 ? "Device" : val_to_str(byte, sn_fail_error_group, "Reserved [%d]" ) ) );
byte = tvb_get_guint8(message_tvb, OSS_FRAME_POS_DATA + frameStart1 + 2);
proto_tree_add_uint_format(snmt_tree, hf_oss_snmt_error_code, message_tvb, OSS_FRAME_POS_DATA + frameStart1 + 2, 1,
byte, "%s [%d]", ( byte == 0 ? "Default" : "Vendor Specific" ), byte );
}
else if ( (db0 ^ OPENSAFETY_MSG_SNMT_EXT_SN_ASSIGNED_UDID_SCM) == 0 )
{
item = proto_tree_add_item(snmt_tree, hf_oss_snmt_udid, message_tvb, OSS_FRAME_POS_DATA + frameStart1 + 1, 6, ENC_NA);
if ( global_scm_udid_autoset == TRUE )
{
tempString = (char *)ep_alloc0(128 * sizeof(char));
g_snprintf ( tempString, 18, "%s", tvb_bytes_to_str_punct(message_tvb, OSS_FRAME_POS_DATA + frameStart1 + 1, 6, ':' ) );
if ( memcmp ( global_scm_udid, tempString, 17 ) != 0 )
{
local_scm_udid = (char *)se_alloc0(18 * sizeof(char));
g_snprintf(local_scm_udid, 18, "%s", tempString );
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_NOTE, "Auto detected payload as SCM UDID [%s].", tempString);
}
}
}
}
else if ( (OSS_FRAME_ID_T(message_tvb, frameStart1) ^ OPENSAFETY_MSG_SNMT_SERVICE_REQUEST) == 0 )
{
proto_tree_add_uint(snmt_tree, hf_oss_snmt_service_id, message_tvb, OSS_FRAME_POS_DATA + frameStart1, 1, db0);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", val_to_str_const(db0, message_service_type, "Unknown"));
if ( (db0 ^ OPENSAFETY_MSG_SNMT_EXT_SCM_SET_TO_STOP) == 0 || (db0 ^ OPENSAFETY_MSG_SNMT_EXT_SCM_SET_TO_OP) == 0 )
{
proto_tree_add_uint(snmt_tree, hf_oss_snmt_scm, message_tvb, OSS_FRAME_POS_ADDR + frameStart1, 2, addr);
proto_tree_add_uint(snmt_tree, hf_oss_snmt_tool, message_tvb, frameStart2 + 3, 2, taddr);
}
else if ( (db0 ^ OPENSAFETY_MSG_SNMT_EXT_SN_ASSIGN_UDID_SCM) == 0 )
{
proto_tree_add_uint(snmt_tree, hf_oss_snmt_master, message_tvb, OSS_FRAME_POS_ADDR + frameStart1, 2, addr);
proto_tree_add_uint(snmt_tree, hf_oss_snmt_slave, message_tvb, frameStart2 + 3, 2, taddr);
item = proto_tree_add_item(snmt_tree, hf_oss_snmt_udid, message_tvb, OSS_FRAME_POS_DATA + frameStart1 + 1, 6, ENC_NA);
if ( global_scm_udid_autoset == TRUE )
{
tempString = (char *)ep_alloc0(18 * sizeof(char));
g_snprintf ( tempString, 18, "%s", tvb_bytes_to_str_punct(message_tvb, OSS_FRAME_POS_DATA + frameStart1 + 1, 6, ':' ) );
if ( memcmp ( global_scm_udid, tempString, 17 ) != 0 )
{
local_scm_udid = (char *)se_alloc0(18 * sizeof(char));
g_snprintf(local_scm_udid, 18, "%s", tempString );
expert_add_info_format(pinfo, item, PI_PROTOCOL, PI_NOTE, "Auto detected payload as SCM UDID [%s].", tempString);
}
}
}
else
{
proto_tree_add_uint(snmt_tree, hf_oss_snmt_master, message_tvb, frameStart2 + 3, 2, taddr);
proto_tree_add_uint(snmt_tree, hf_oss_snmt_slave, message_tvb, OSS_FRAME_POS_ADDR + frameStart1, 2, addr);
if ( (db0 ^ OPENSAFETY_MSG_SNMT_EXT_SN_SET_TO_OP) == 0 )
{
entry = tvb_get_letohl ( message_tvb, frameStart1 + OSS_FRAME_POS_DATA + 1 );
proto_tree_add_uint_format_value ( snmt_tree, hf_oss_sod_par_timestamp, message_tvb,
OSS_FRAME_POS_DATA + frameStart1 + 1, 4, entry, "0x%08X", entry );
}
}
}
else if ( (OSS_FRAME_ID_T(message_tvb, frameStart1) ^ OPENSAFETY_MSG_SNMT_SADR_ASSIGNED) == 0 )
{
proto_tree_add_uint(snmt_tree, hf_oss_snmt_master, message_tvb, OSS_FRAME_POS_ADDR + frameStart1, 2, addr);
proto_tree_add_uint(snmt_tree, hf_oss_snmt_slave, message_tvb, frameStart2 + 3, 2, taddr);
if (dataLength > 0)
proto_tree_add_item(snmt_tree, hf_oss_snmt_udid, message_tvb, OSS_FRAME_POS_DATA + frameStart1, 6, ENC_NA);
}
else if ( (OSS_FRAME_ID_T(message_tvb, frameStart1) ^ OPENSAFETY_MSG_SNMT_ASSIGN_SADR) == 0 )
{
proto_tree_add_uint(snmt_tree, hf_oss_snmt_master, message_tvb, frameStart2 + 3, 2, taddr);
proto_tree_add_uint(snmt_tree, hf_oss_snmt_slave, message_tvb, OSS_FRAME_POS_ADDR + frameStart1, 2, addr);
if (dataLength > 0)
proto_tree_add_item(snmt_tree, hf_oss_snmt_udid, message_tvb, OSS_FRAME_POS_DATA + frameStart1, 6, ENC_NA);
}
else if ( (OSS_FRAME_ID_T(message_tvb, frameStart1) ^ OPENSAFETY_MSG_SNMT_RESPONSE_UDID) == 0 )
{
proto_tree_add_uint(snmt_tree, hf_oss_snmt_master, message_tvb, OSS_FRAME_POS_ADDR + frameStart1, 2, addr);
proto_tree_add_uint(snmt_tree, hf_oss_snmt_slave, message_tvb, frameStart2 + 3, 2, taddr);
if (dataLength > 0)
proto_tree_add_item(snmt_tree, hf_oss_snmt_udid, message_tvb, OSS_FRAME_POS_DATA + frameStart1, 6, ENC_NA);
}
else if ( (OSS_FRAME_ID_T(message_tvb, frameStart1) ^ OPENSAFETY_MSG_SNMT_REQUEST_UDID) == 0 )
{
proto_tree_add_uint(snmt_tree, hf_oss_snmt_master, message_tvb, frameStart2 + 3, 2, taddr);
proto_tree_add_uint(snmt_tree, hf_oss_snmt_slave, message_tvb, OSS_FRAME_POS_ADDR + frameStart1, 2, addr);
}
}
static gboolean
dissect_opensafety_checksum(tvbuff_t *message_tvb, proto_tree *opensafety_tree,
guint16 frameStart1, guint16 frameStart2 )
{
guint16 frame1_crc, frame2_crc;
guint16 calc1_crc;
guint dataLength;
guint8 *bytes;
proto_item *item;
proto_tree *checksum_tree;
gint start;
gint length;
gboolean isSlim = FALSE;
dataLength = OSS_FRAME_LENGTH_T(message_tvb, frameStart1);
start = OSS_FRAME_POS_DATA + dataLength + frameStart1;
if (OSS_FRAME_LENGTH_T(message_tvb, frameStart1) > OSS_PAYLOAD_MAXSIZE_FOR_CRC8)
frame1_crc = tvb_get_letohs(message_tvb, start);
else
frame1_crc = tvb_get_guint8(message_tvb, start);
length = (dataLength > OSS_PAYLOAD_MAXSIZE_FOR_CRC8 ? OPENSAFETY_CHECKSUM_CRC16 : OPENSAFETY_CHECKSUM_CRC8);
item = proto_tree_add_uint_format(opensafety_tree, hf_oss_crc, message_tvb, start, length, frame1_crc,
"CRC for subframe #1: 0x%04X", frame1_crc);
checksum_tree = proto_item_add_subtree(item, ett_opensafety_checksum);
bytes = (guint8*)ep_tvb_memdup(message_tvb, frameStart1, dataLength + 4);
if ( dataLength > OSS_PAYLOAD_MAXSIZE_FOR_CRC8 )
calc1_crc = crc16_0x5935(&bytes[frameStart1], dataLength + 4, 0);
else
calc1_crc = crc8_0x2F(&bytes[frameStart1], dataLength + 4, 0);
item = proto_tree_add_boolean(checksum_tree, hf_oss_crc_valid, message_tvb, start, length, (frame1_crc == calc1_crc));
PROTO_ITEM_SET_GENERATED(item);
proto_tree_add_uint(checksum_tree, hf_oss_crc_type, message_tvb, start, length,
( dataLength > OSS_PAYLOAD_MAXSIZE_FOR_CRC8 ? OPENSAFETY_CHECKSUM_CRC16 : OPENSAFETY_CHECKSUM_CRC8 ) );
if ( ( OSS_FRAME_ID_T(message_tvb, frameStart1) & OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE ) == OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE )
isSlim = TRUE;
start = frameStart2 + (isSlim ? 5 : dataLength + OSS_FRAME_POS_DATA + 1 );
if (OSS_FRAME_LENGTH_T(message_tvb, frameStart1) > OSS_PAYLOAD_MAXSIZE_FOR_CRC8)
frame2_crc = tvb_get_letohs(message_tvb, start);
else
frame2_crc = tvb_get_guint8(message_tvb, start);
proto_tree_add_uint_format(opensafety_tree, hf_oss_crc, message_tvb, start, length, frame2_crc,
"CRC for subframe #2: 0x%04X", frame2_crc);
return (gboolean) (frame1_crc == calc1_crc);
}
static gboolean
dissect_opensafety_message(guint16 frameStart1, guint16 frameStart2, guint8 type,
tvbuff_t *message_tvb, packet_info *pinfo,
proto_item *opensafety_item, proto_tree *opensafety_tree, guint8 u_nrInPackage)
{
guint8 b_ID, ctr;
guint8 scm_udid[6];
GByteArray *scmUDID = NULL;
gboolean validSCMUDID;
proto_item *item;
gboolean messageTypeUnknown, crcValid;
messageTypeUnknown = FALSE;
for ( ctr = 0; ctr < 6; ctr++ )
scm_udid[ctr] = 0;
b_ID = OSS_FRAME_ID_T(message_tvb, frameStart1);
if ( type == OPENSAFETY_SPDO_MESSAGE_TYPE )
b_ID = b_ID & 0xF8;
col_append_fstr(pinfo->cinfo, COL_INFO, (u_nrInPackage > 1 ? " | %s" : "%s" ),
val_to_str(b_ID, message_type_values, "Unknown Message (0x%02X) "));
{
if ( type == OPENSAFETY_SNMT_MESSAGE_TYPE )
{
dissect_opensafety_snmt_message ( message_tvb, pinfo, opensafety_tree, frameStart1, frameStart2 );
}
else
{
validSCMUDID = FALSE;
scmUDID = g_byte_array_new();
if ( hex_str_to_bytes((local_scm_udid != NULL ? local_scm_udid : global_scm_udid), scmUDID, TRUE) && scmUDID->len == 6 )
{
validSCMUDID = TRUE;
b_ID = OSS_FRAME_ID_T(message_tvb, frameStart2) ^ (guint8)(scmUDID->data[OSS_FRAME_POS_ID]);
if ( ( OSS_FRAME_ID_T(message_tvb, frameStart1) ^ b_ID ) != 0 )
validSCMUDID = FALSE;
else
for ( ctr = 0; ctr < 6; ctr++ )
scm_udid[ctr] = scmUDID->data[ctr];
}
if ( strlen ( (local_scm_udid != NULL ? local_scm_udid : global_scm_udid) ) > 0 && scmUDID->len == 6 )
{
if ( local_scm_udid != NULL )
item = proto_tree_add_string(opensafety_tree, hf_oss_scm_udid_auto, message_tvb, 0, 0, local_scm_udid);
else
item = proto_tree_add_string(opensafety_tree, hf_oss_scm_udid, message_tvb, 0, 0, global_scm_udid);
PROTO_ITEM_SET_GENERATED(item);
}
item = proto_tree_add_boolean(opensafety_tree, hf_oss_scm_udid_valid, message_tvb, 0, 0, validSCMUDID);
if ( scmUDID->len != 6 )
opensafety_add_warning(pinfo, item, "openSAFETY protocol settings are invalid! SCM UDID first octet will be assumed to be 00" );
PROTO_ITEM_SET_GENERATED(item);
g_byte_array_free( scmUDID, TRUE);
if ( type == OPENSAFETY_SSDO_MESSAGE_TYPE || type == OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE )
{
dissect_opensafety_ssdo_message ( message_tvb, pinfo, opensafety_tree, frameStart1, frameStart2, validSCMUDID, scm_udid );
}
else if ( type == OPENSAFETY_SPDO_MESSAGE_TYPE )
{
dissect_opensafety_spdo_message ( message_tvb, pinfo, opensafety_tree, frameStart1, frameStart2, validSCMUDID, scm_udid );
}
else
{
messageTypeUnknown = TRUE;
}
}
crcValid = FALSE;
item = proto_tree_add_uint(opensafety_tree, hf_oss_length,
message_tvb, OSS_FRAME_POS_LEN + frameStart1, 1, OSS_FRAME_LENGTH_T(message_tvb, frameStart1));
if ( messageTypeUnknown )
{
opensafety_add_error(pinfo, item, "Unknown openSAFETY message type" );
}
else
{
crcValid = dissect_opensafety_checksum ( message_tvb, opensafety_tree, frameStart1, frameStart2 );
}
if ( ! crcValid )
{
opensafety_add_error(pinfo, opensafety_item, "Frame 1 CRC invalid => possible error in package" );
}
if ( crcValid && type == OPENSAFETY_SNMT_MESSAGE_TYPE )
{
if ( OSS_FRAME_ID_T(message_tvb, frameStart1) != OSS_FRAME_ID_T(message_tvb, frameStart2) )
opensafety_add_error(pinfo, opensafety_item, "Frame 1 is valid, frame 2 id is invalid => error in openSAFETY frame" );
}
}
return TRUE;
}
static gboolean
opensafety_package_dissector(const gchar *protocolName, const gchar *sub_diss_handle,
gboolean b_frame2First, gboolean do_byte_swap, guint8 force_nr_in_package,
tvbuff_t *given_tvb , packet_info *pinfo , proto_tree *tree )
{
tvbuff_t *next_tvb, *message_tvb = NULL;
guint length, len, frameOffset, frameLength, nodeAddress;
guint8 *bytes;
gboolean handled, dissectorCalled, call_sub_dissector, markAsMalformed;
guint8 type, found, packageCounter, i, tempByte;
guint16 frameStart1, frameStart2, byte_offset;
gint reported_len;
dissector_handle_t protocol_dissector = NULL;
proto_item *opensafety_item;
proto_tree *opensafety_tree;
handled = FALSE;
dissectorCalled = FALSE;
call_sub_dissector = FALSE;
markAsMalformed = FALSE;
register_frame_end_routine(pinfo, reset_dissector);
length = tvb_reported_length(given_tvb);
if ( length < OSS_MINIMUM_LENGTH )
return FALSE;
if ( strlen( sub_diss_handle ) > 0 )
{
call_sub_dissector = TRUE;
protocol_dissector = find_dissector ( sub_diss_handle );
if ( protocol_dissector == NULL )
protocol_dissector = find_dissector ( "data" );
}
reported_len = tvb_reported_length_remaining(given_tvb, 0);
bytes = (guint8 *) ep_tvb_memdup(given_tvb, 0, length);
if ( do_byte_swap == TRUE && global_mbtcp_big_endian == TRUE )
{
len = (length / 2);
for ( i = 0; i < len; i++ )
{
tempByte = bytes [ 2 * i ]; bytes [ 2 * i ] = bytes [ 2 * i + 1 ]; bytes [ 2 * i + 1 ] = tempByte;
}
message_tvb = tvb_new_real_data(bytes, length, reported_len);
} else {
message_tvb = given_tvb;
}
frameOffset = 0;
frameLength = 0;
found = 0;
packageCounter = 0;
while ( frameOffset < length )
{
if ( tvb_length_remaining(message_tvb, frameOffset ) < OSS_MINIMUM_LENGTH )
break;
if ( findSafetyFrame(message_tvb, frameOffset, b_frame2First, &frameOffset, &frameLength) )
{
if ( ( frameOffset + frameLength ) > (guint)reported_len )
break;
found++;
byte_offset = ( b_frame2First ? 0 : frameOffset );
if ( b_frame2First )
{
frameStart1 = findFrame1Position (message_tvb, byte_offset, frameLength, FALSE );
frameStart2 = 0;
}
else
{
frameStart1 = 0;
frameStart2 = ((OSS_FRAME_LENGTH_T(message_tvb, byte_offset + frameStart1) - 1) +
(OSS_FRAME_LENGTH_T(message_tvb, byte_offset + frameStart1) > OSS_PAYLOAD_MAXSIZE_FOR_CRC8 ? OSS_SLIM_FRAME2_WITH_CRC16 : OSS_SLIM_FRAME2_WITH_CRC8));
}
if (frameStart1 == frameStart2)
{
found--;
frameOffset += frameLength ;
continue;
}
if ( ( OSS_FRAME_ID_T(message_tvb, byte_offset + frameStart1) & OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE ) == OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE )
type = OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE;
else if ( ( OSS_FRAME_ID_T(message_tvb, byte_offset + frameStart1) & OPENSAFETY_SSDO_MESSAGE_TYPE ) == OPENSAFETY_SSDO_MESSAGE_TYPE )
type = OPENSAFETY_SSDO_MESSAGE_TYPE;
else if ( ( OSS_FRAME_ID_T(message_tvb, byte_offset + frameStart1) & OPENSAFETY_SPDO_MESSAGE_TYPE ) == OPENSAFETY_SPDO_MESSAGE_TYPE )
type = OPENSAFETY_SPDO_MESSAGE_TYPE;
else if ( ( OSS_FRAME_ID_T(message_tvb, byte_offset + frameStart1) & OPENSAFETY_SNMT_MESSAGE_TYPE ) == OPENSAFETY_SNMT_MESSAGE_TYPE )
type = OPENSAFETY_SNMT_MESSAGE_TYPE;
else
{
if ( b_frame2First )
{
frameStart1 = findFrame1Position(message_tvb, ( b_frame2First ? 0 : frameOffset ), frameLength, TRUE );
frameStart2 = 0;
if ( ( OSS_FRAME_ID_T(message_tvb, byte_offset + frameStart1) & OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE ) == OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE )
type = OPENSAFETY_SLIM_SSDO_MESSAGE_TYPE;
else if ( ( OSS_FRAME_ID_T(message_tvb, byte_offset + frameStart1) & OPENSAFETY_SSDO_MESSAGE_TYPE ) == OPENSAFETY_SSDO_MESSAGE_TYPE )
type = OPENSAFETY_SSDO_MESSAGE_TYPE;
else if ( ( OSS_FRAME_ID_T(message_tvb, byte_offset + frameStart1) & OPENSAFETY_SPDO_MESSAGE_TYPE ) == OPENSAFETY_SPDO_MESSAGE_TYPE )
type = OPENSAFETY_SPDO_MESSAGE_TYPE;
else if ( ( OSS_FRAME_ID_T(message_tvb, byte_offset + frameStart1) & OPENSAFETY_SNMT_MESSAGE_TYPE ) == OPENSAFETY_SNMT_MESSAGE_TYPE )
type = OPENSAFETY_SNMT_MESSAGE_TYPE;
else {
frameOffset += 2;
found--;
continue;
}
} else {
frameOffset += 2;
found--;
continue;
}
}
if ( type != OPENSAFETY_SPDO_MESSAGE_TYPE )
{
gint idx = -1;
try_val_to_str_idx(OSS_FRAME_ID_T(message_tvb, byte_offset + frameStart1), message_type_values, &idx );
if ( idx < 0 )
{
frameOffset += 2;
found--;
continue;
}
else if ( type == OPENSAFETY_SNMT_MESSAGE_TYPE &&
(OSS_FRAME_ID_T(message_tvb, byte_offset + frameStart1) != OSS_FRAME_ID_T(message_tvb, byte_offset + frameStart2)) )
{
frameOffset += 2;
found--;
continue;
}
}
if ( type == OPENSAFETY_SPDO_MESSAGE_TYPE )
{
nodeAddress = OSS_FRAME_ADDR_T(message_tvb, byte_offset + frameStart1);
if ( nodeAddress > 1024 ) {
markAsMalformed = TRUE;
}
}
if ( ( (gint)frameLength - (gint)( frameStart2 > frameStart1 ? frameStart2 : frameLength - frameStart1 ) ) < 0 )
return FALSE;
if ( do_byte_swap == TRUE && global_mbtcp_big_endian == TRUE )
{
next_tvb = tvb_new_child_real_data(message_tvb, &bytes[frameOffset], (frameLength), reported_len);
add_new_data_source(pinfo, next_tvb, "openSAFETY Frame (Swapped)");
}
else
{
next_tvb = tvb_new_subset(message_tvb, frameOffset, frameLength, reported_len);
add_new_data_source(pinfo, next_tvb, "openSAFETY Frame");
}
if ( force_nr_in_package > 0 )
{
found = force_nr_in_package + 1;
dissectorCalled = TRUE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, protocolName);
}
if ( ! dissectorCalled )
{
if ( call_sub_dissector )
call_dissector(protocol_dissector, message_tvb, pinfo, tree);
dissectorCalled = TRUE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, protocolName);
col_clear(pinfo->cinfo,COL_INFO);
}
if ( tree )
{
opensafety_item = proto_tree_add_item(tree, proto_opensafety, message_tvb, frameOffset, frameLength, ENC_BIG_ENDIAN);
opensafety_tree = proto_item_add_subtree(opensafety_item, ett_opensafety);
} else {
opensafety_item = NULL;
opensafety_tree = NULL;
}
if ( dissect_opensafety_message(frameStart1, frameStart2, type, next_tvb, pinfo, opensafety_item, opensafety_tree, found) == TRUE )
packageCounter++;
else
markAsMalformed = TRUE;
if ( tree && markAsMalformed )
{
if ( OSS_FRAME_ADDR_T(message_tvb, byte_offset + frameStart1) > 1024 )
opensafety_add_error(pinfo, opensafety_item, "SPDO address is invalid" );
}
handled = TRUE;
}
else
break;
frameOffset += frameLength;
}
if ( handled == TRUE && packageCounter == 0 )
handled = FALSE;
if ( ! handled )
{
if ( call_sub_dissector )
call_dissector(protocol_dissector, message_tvb, pinfo, tree);
handled = TRUE;
}
return ( handled ? TRUE : FALSE );
}
static gboolean
dissect_opensafety_epl(tvbuff_t *message_tvb , packet_info *pinfo , proto_tree *tree , void *data _U_ )
{
gboolean result = FALSE;
guint8 firstByte;
if ( ! global_enable_plk )
return result;
if ( bDissector_Called_Once_Before == FALSE )
{
bDissector_Called_Once_Before = TRUE;
firstByte = ( tvb_get_guint8(message_tvb, 0) << 1 );
if ( ( firstByte != 0x02 ) && ( firstByte != 0x0A ) )
{
result = opensafety_package_dissector("openSAFETY/Powerlink", "epl",
FALSE, FALSE, 0, message_tvb, pinfo, tree);
}
bDissector_Called_Once_Before = FALSE;
}
return result;
}
static gboolean
dissect_opensafety_siii(tvbuff_t *message_tvb , packet_info *pinfo , proto_tree *tree , void *data _U_ )
{
gboolean result = FALSE;
guint8 firstByte;
if ( ! global_enable_siii )
return result;
if ( pinfo->ipproto == IPPROTO_UDP )
{
return opensafety_package_dissector("openSAFETY/SercosIII UDP", "", FALSE, FALSE, 0, message_tvb, pinfo, tree);
}
if ( bDissector_Called_Once_Before == FALSE )
{
bDissector_Called_Once_Before = TRUE;
firstByte = ( tvb_get_guint8(message_tvb, 0) << 1 );
if ( ( firstByte & 0x40 ) == 0x40 )
{
result = opensafety_package_dissector("openSAFETY/SercosIII", "sercosiii",
FALSE, FALSE, 0, message_tvb, pinfo, tree);
}
bDissector_Called_Once_Before = FALSE;
}
return result;
}
static gboolean
dissect_opensafety_pn_io(tvbuff_t *message_tvb , packet_info *pinfo , proto_tree *tree , void *data _U_ )
{
gboolean result = FALSE;
if ( ! global_enable_pnio )
return result;
if ( bDissector_Called_Once_Before == FALSE )
{
bDissector_Called_Once_Before = TRUE;
result = opensafety_package_dissector("openSAFETY/Profinet IO", "pn_io",
FALSE, FALSE, 0, message_tvb, pinfo, tree);
bDissector_Called_Once_Before = FALSE;
}
return result;
}
static gboolean
dissect_opensafety_mbtcp(tvbuff_t *message_tvb , packet_info *pinfo , proto_tree *tree, void *data _U_ )
{
if ( ! global_enable_mbtcp )
return FALSE;
return opensafety_package_dissector("openSAFETY/Modbus TCP", "", FALSE, TRUE, 0,
message_tvb, pinfo, ( tree->parent != NULL ? tree->parent : tree ));
}
static gboolean
dissect_opensafety_udpdata(tvbuff_t *message_tvb , packet_info *pinfo , proto_tree *tree , void *data _U_ )
{
gboolean result = FALSE;
static guint32 frameNum = 0;
static guint32 frameIdx = 0;
if ( ! global_enable_udp )
return result;
if ( tvb_length ( message_tvb ) < OSS_MINIMUM_LENGTH )
return result;
if ( pinfo->fd->num != frameNum )
{
frameIdx = 0;
frameNum = pinfo->fd->num;
}
result = opensafety_package_dissector((pinfo->destport == UDP_PORT_SIII ? "openSAFETY/SercosIII" : "openSAFETY/UDP" ),
"", pinfo->destport == UDP_PORT_SIII ? global_siii_udp_frame2_first : global_udp_frame2_first,
FALSE, frameIdx, message_tvb, pinfo, tree);
if ( result )
frameIdx++;
return result;
}
static void
apply_prefs ( void )
{
static gboolean opensafety_init = FALSE;
static guint opensafety_udp_port_number;
static guint opensafety_udp_siii_port_number;
if ( opensafety_init )
{
dissector_delete_uint ("udp.port", opensafety_udp_port_number, find_dissector("opensafety_udpdata"));
dissector_delete_uint ("udp.port", opensafety_udp_siii_port_number, find_dissector("opensafety_siii"));
}
opensafety_init = TRUE;
opensafety_udp_port_number = global_network_udp_port;
opensafety_udp_siii_port_number = global_network_udp_port_sercosiii;
dissector_add_uint("udp.port", opensafety_udp_port_number, find_dissector("opensafety_udpdata"));
dissector_add_uint("udp.port", opensafety_udp_siii_port_number, find_dissector("opensafety_siii"));
}
void
proto_register_opensafety(void)
{
static hf_register_info hf[] = {
{ &hf_oss_scm_udid,
{ "SCM UDID Configured", "opensafety.scm_udid",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_scm_udid_auto,
{ "SCM UDID Auto Detect", "opensafety.scm_udid_auto",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_scm_udid_valid,
{ "SCM UDID Valid", "opensafety.scm_udid_valid",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_msg,
{ "Message", "opensafety.msg.id",
FT_UINT8, BASE_HEX, VALS(message_type_values), 0x0, NULL, HFILL } },
{ &hf_oss_msg_category,
{ "Type", "opensafety.msg.type",
FT_UINT16, BASE_HEX, VALS(message_id_values), 0x0, NULL, HFILL } },
{ &hf_oss_msg_direction,
{ "Direction", "opensafety.msg.direction",
FT_BOOLEAN, BASE_NONE, TFS(&opensafety_message_direction), 0x0, NULL, HFILL } },
{ &hf_oss_msg_node,
{ "Safety Node", "opensafety.msg.node",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_msg_network,
{ "Safety Domain", "opensafety.msg.network",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_msg_sender,
{ "Sender", "opensafety.msg.sender",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_msg_receiver,
{ "Receiver", "opensafety.msg.receiver",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_length,
{ "Length", "opensafety.length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_crc,
{ "CRC", "opensafety.crc.data",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_crc_valid,
{ "Is Valid", "opensafety.crc.valid",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_crc_type,
{ "CRC Type", "opensafety.crc.type",
FT_UINT8, BASE_DEC, VALS(message_crc_type), 0x0, NULL, HFILL } },
{ &hf_oss_snmt_slave,
{ "SNMT Slave", "opensafety.snmt.slave",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_snmt_master,
{ "SNMT Master", "opensafety.snmt.master",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_snmt_scm,
{ "SCM", "opensafety.snmt.scm",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_snmt_tool,
{ "Tool ID", "opensafety.snmt.tool_id",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_snmt_udid,
{ "UDID for SN", "opensafety.snmt.udid",
FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_snmt_service_id,
{ "Extended Service ID", "opensafety.snmt.service_id",
FT_UINT8, BASE_HEX, VALS(message_service_type), 0x0, NULL, HFILL } },
{ &hf_oss_snmt_error_group,
{ "Error Group", "opensafety.snmt.error_group",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_snmt_error_code,
{ "Error Code", "opensafety.snmt.error_code",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_server,
{ "SSDO Server", "opensafety.ssdo.master",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_client,
{ "SSDO Client", "opensafety.ssdo.client",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_sano,
{ "SOD Access Request Number", "opensafety.ssdo.sano",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_sacmd,
{ "SOD Access Command", "opensafety.ssdo.sacmd",
FT_UINT8, BASE_HEX, VALS(ssdo_sacmd_values), 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_sod_index,
{ "SOD Index", "opensafety.ssdo.sodentry.index",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_sod_subindex,
{ "SOD Sub Index", "opensafety.ssdo.sodentry.subindex",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_payload,
{ "SOD Payload", "opensafety.ssdo.payload",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_payload_size,
{ "SOD Payload Size", "opensafety.ssdo.payloadsize",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_sodentry_size,
{ "SOD Entry Size", "opensafety.ssdo.sodentry.size",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_sodentry_data,
{ "SOD Data", "opensafety.ssdo.sodentry.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_sod_par_timestamp,
{ "Parameter Timestamp", "opensafety.sod.parameter.timestamp",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_sod_par_checksum,
{ "Parameter Checksum", "opensafety.sod.parameter.checksum",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_sodmapping,
{ "Mapping entry", "opensafety.sod.mapping",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_sodmapping_bits,
{ "Mapping size", "opensafety.sod.mapping.bits",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_extpar_parset,
{ "Set Nr", "opensafety.ssdo.extpar.setnr",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_extpar_version,
{ "Version", "opensafety.ssdo.extpar.version",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_extpar_saddr,
{ "SADDR", "opensafety.ssdo.extpar.saddr",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_extpar_length,
{ "Set Length", "opensafety.ssdo.extpar.length",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_extpar_crc,
{ "Set CRC", "opensafety.ssdo.extpar.crc",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_extpar_tstamp,
{ "Timestamp", "opensafety.ssdo.extpar.timestamp",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_extpar_data,
{ "Ext. Parameter Data", "opensafety.ssdo.extpar.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_extpar,
{ "Ext. Parameter", "opensafety.ssdo.extpar",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{&hf_oss_fragments,
{"Message fragments", "opensafety.ssdo.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_oss_fragment,
{"Message fragment", "opensafety.ssdo.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_oss_fragment_overlap,
{"Message fragment overlap", "opensafety.ssdo.fragment.overlap",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_oss_fragment_overlap_conflicts,
{"Message fragment overlapping with conflicting data",
"opensafety.ssdo.fragment.overlap.conflicts",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_oss_fragment_multiple_tails,
{"Message has multiple tail fragments", "opensafety.ssdo.fragment.multiple_tails",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_oss_fragment_too_long_fragment,
{"Message fragment too long", "opensafety.ssdo.fragment.too_long_fragment",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_oss_fragment_error,
{"Message defragmentation error", "opensafety.ssdo.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_oss_fragment_count,
{"Message fragment count", "opensafety.ssdo.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{&hf_oss_reassembled_in,
{"Reassembled in", "opensafety.ssdo.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_oss_reassembled_length,
{"Reassembled length", "opensafety.ssdo.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{&hf_oss_reassembled_data,
{"Reassembled Data", "opensafety.ssdo.reassembled.data",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL } },
#if 0
{ &hf_oss_ssdo_inhibit_time,
{ "Inhibit Time", "opensafety.ssdo.inhibittime",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
#endif
{ &hf_oss_ssdo_abort_code,
{ "Abort Code", "opensafety.ssdo.abortcode",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_ssdo_sacmd_access_type,
{ "Access Type", "opensafety.ssdo.sacmd.access",
FT_BOOLEAN, 8, TFS(&opensafety_sacmd_acc), OPENSAFETY_SSDO_SACMD_ACC, NULL, HFILL } },
#if 0
{ &hf_oss_ssdo_sacmd_reserved,
{ "Reserved", "opensafety.ssdo.sacmd.reserved",
FT_BOOLEAN, 8, TFS(&opensafety_sacmd_res), OPENSAFETY_SSDO_SACMD_RES, NULL, HFILL } },
#endif
{ &hf_oss_ssdo_sacmd_abort_transfer,
{ "Abort Transfer", "opensafety.ssdo.sacmd.abort_transfer",
FT_BOOLEAN, 8, TFS(&opensafety_sacmd_abrt), OPENSAFETY_SSDO_SACMD_ABRT, NULL, HFILL } },
{ &hf_oss_ssdo_sacmd_segmentation,
{ "Segmentation", "opensafety.ssdo.sacmd.segmentation",
FT_BOOLEAN, 8, TFS(&opensafety_sacmd_seg), OPENSAFETY_SSDO_SACMD_SEG, NULL, HFILL } },
{ &hf_oss_ssdo_sacmd_toggle,
{ "Toggle Bit", "opensafety.ssdo.sacmd.toggle",
FT_BOOLEAN, 8, TFS(&opensafety_on_off), OPENSAFETY_SSDO_SACMD_TGL, NULL, HFILL } },
{ &hf_oss_ssdo_sacmd_initiate,
{ "Initiate Transfer", "opensafety.ssdo.sacmd.initiate",
FT_BOOLEAN, 8, TFS(&opensafety_sacmd_ini), OPENSAFETY_SSDO_SACMD_INI, NULL, HFILL } },
{ &hf_oss_ssdo_sacmd_end_segment,
{ "End Segment", "opensafety.ssdo.sacmd.end_segment",
FT_BOOLEAN, 8, TFS(&opensafety_sacmd_ensg), OPENSAFETY_SSDO_SACMD_ENSG, NULL, HFILL } },
{ &hf_oss_ssdo_sacmd_block_transfer,
{ "Block Transfer", "opensafety.ssdo.sacmd.block_transfer",
FT_BOOLEAN, 8, TFS(&opensafety_sacmd_blk), OPENSAFETY_SSDO_SACMD_BLK, NULL, HFILL } },
{ &hf_oss_spdo_connection_valid,
{ "Connection Valid Bit", "opensafety.spdo.connection_valid",
FT_BOOLEAN, BASE_NONE, TFS(&opensafety_set_notset), 0x0, NULL, HFILL } },
{ &hf_oss_spdo_payload,
{ "SPDO Payload", "opensafety.spdo.payload",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_spdo_producer,
{ "Producer", "opensafety.spdo.producer",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_spdo_producer_time,
{ "Internal Time Producer", "opensafety.spdo.time.producer",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_spdo_time_value_sn,
{ "Internal Time SN", "opensafety.spdo.time.sn",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_spdo_time_request,
{ "Time Request Counter", "opensafety.spdo.time.request_counter",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_spdo_time_request_to,
{ "Time Request from", "opensafety.spdo.time.request_from",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_oss_spdo_time_request_from,
{ "Time Request by", "opensafety.spdo.time.request_to",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_opensafety,
&ett_opensafety_sender,
&ett_opensafety_receiver,
&ett_opensafety_checksum,
&ett_opensafety_snmt,
&ett_opensafety_ssdo,
&ett_opensafety_ssdo_sacmd,
&ett_opensafety_ssdo_fragment,
&ett_opensafety_ssdo_fragments,
&ett_opensafety_ssdo_payload,
&ett_opensafety_ssdo_sodentry,
&ett_opensafety_sod_mapping,
&ett_opensafety_ssdo_extpar,
&ett_opensafety_spdo,
};
module_t *opensafety_module;
proto_opensafety = proto_register_protocol("openSAFETY", "openSAFETY", "opensafety");
opensafety_module = prefs_register_protocol(proto_opensafety, apply_prefs);
proto_register_field_array(proto_opensafety, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
prefs_register_string_preference(opensafety_module, "scm_udid",
"SCM UDID (xx:xx:xx:xx:xx:xx)",
"To be able to fully dissect SSDO and SPDO packages, a valid UDID for the SCM has to be provided",
&global_scm_udid);
prefs_register_bool_preference(opensafety_module, "scm_udid_autoset",
"Set SCM UDID if detected in stream",
"Automatically assign a detected SCM UDID (by reading SNMT->SNTM_assign_UDID_SCM) and set it for the file",
&global_scm_udid_autoset);
prefs_register_uint_preference(opensafety_module, "network_udp_port",
"Port used for Generic UDP",
"Port used by any UDP demo implementation to transport data", 10,
&global_network_udp_port);
prefs_register_uint_preference(opensafety_module, "network_udp_port_sercosiii",
"Port used for SercosIII/UDP",
"UDP port used by SercosIII to transport data", 10,
&global_network_udp_port_sercosiii);
prefs_register_bool_preference(opensafety_module, "network_udp_frame_first_sercosiii",
"openSAFETY frame 2 before frame 1 (SercosIII/UDP only)",
"In an SercosIII/UDP transport stream, openSAFETY frame 2 will be expected before frame 1",
&global_siii_udp_frame2_first );
prefs_register_bool_preference(opensafety_module, "network_udp_frame_first",
"openSAFETY frame 2 before frame 1 (UDP only)",
"In the transport stream, openSAFETY frame 2 will be expected before frame 1",
&global_udp_frame2_first );
prefs_register_bool_preference(opensafety_module, "mbtcp_big_endian",
"Big Endian Word Coding (Modbus/TCP only)",
"Modbus/TCP words can be transcoded either big- or little endian. Default will be little endian",
&global_mbtcp_big_endian);
prefs_register_bool_preference(opensafety_module, "enable_plk",
"Enable heuristic dissection for Ethernet POWERLINK", "Enable heuristic dissection for Ethernet POWERLINK",
&global_enable_plk);
prefs_register_bool_preference(opensafety_module, "enable_udp",
"Enable heuristic dissection for openSAFETY over UDP encoded traffic", "Enable heuristic dissection for openSAFETY over UDP encoded traffic",
&global_enable_udp);
prefs_register_bool_preference(opensafety_module, "enable_genudp",
"Enable heuristic dissection for generic UDP encoded traffic", "Enable heuristic dissection for generic UDP encoded traffic",
&global_enable_genudp);
prefs_register_bool_preference(opensafety_module, "enable_siii",
"Enable heuristic dissection for SercosIII", "Enable heuristic dissection for SercosIII",
&global_enable_siii);
prefs_register_bool_preference(opensafety_module, "enable_pnio",
"Enable heuristic dissection for Profinet IO", "Enable heuristic dissection for Profinet IO",
&global_enable_pnio);
prefs_register_bool_preference(opensafety_module, "enable_mbtcp",
"Enable heuristic dissection for Modbus/TCP", "Enable heuristic dissection for Modbus/TCP",
&global_enable_mbtcp);
new_register_dissector("opensafety_udpdata", dissect_opensafety_udpdata, proto_opensafety );
new_register_dissector("opensafety_mbtcp", dissect_opensafety_mbtcp, proto_opensafety );
new_register_dissector("opensafety_siii", dissect_opensafety_siii, proto_opensafety );
new_register_dissector("opensafety_pnio", dissect_opensafety_pn_io, proto_opensafety);
}
void
proto_reg_handoff_opensafety(void)
{
static int opensafety_inited = FALSE;
if ( !opensafety_inited )
{
heur_dissector_add("epl", dissect_opensafety_epl, proto_opensafety);
heur_dissector_add("sercosiii", dissect_opensafety_siii, proto_opensafety);
if ( find_dissector("opensafety_udp") != NULL )
heur_dissector_add("opensafety_udp", dissect_opensafety_udpdata, proto_opensafety);
dissector_add_string("modbus.data", "data", find_dissector("opensafety_mbtcp"));
if ( find_dissector("pn_io") != NULL )
{
heur_dissector_add("pn_io", dissect_opensafety_pn_io, proto_opensafety);
}
else
{
dissector_add_uint("ethertype", ETHERTYPE_PROFINET, find_dissector("opensafety_pnio"));
}
register_init_routine ( setup_dissector );
}
}
