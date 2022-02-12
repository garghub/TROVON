static gint dissect_image_leader(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_bitmask(gvsp_tree, tvb, offset, hf_gvsp_fieldinfo,
ett_gvsp_fieldinfo, fieldinfo_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_timestamp, tvb, offset + 4, 8, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(gvsp_tree, tvb, offset + 12, hf_gvsp_pixelformat, ett_gvsp_pixelformat,
pixelformat_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sizex, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sizey, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_offsetx, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_offsety, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_paddingx, tvb, offset + 32, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_paddingy, tvb, offset + 34, 2, ENC_BIG_ENDIAN);
return 36;
}
static gint dissect_image_trailer(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sizey, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
return 8;
}
static gint dissect_raw_data_leader(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_timestamp, tvb, offset + 4, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloaddatasize, tvb, offset + 12, 8, ENC_BIG_ENDIAN);
return 20;
}
static gint dissect_file_leader(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
guint file_length = 0;
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_timestamp, tvb, offset + 4, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloaddatasize, tvb, offset + 12, 8, ENC_BIG_ENDIAN);
file_length = tvb_strsize(tvb, offset + 20);
proto_tree_add_item(gvsp_tree, hf_gvsp_filename, tvb, offset + 20, file_length, ENC_ASCII|ENC_NA);
if (20 + file_length > G_MAXINT)
return -1;
return (gint)(20 + file_length);
}
static gint dissect_chunk_data_leader(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_timestamp, tvb, offset + 4, 8, ENC_BIG_ENDIAN);
return 12;
}
static gint dissect_chunk_data_trailer(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadlength, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
return 8;
}
static gint dissect_extended_chunk_data_leader(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_bitmask(gvsp_tree, tvb, offset, hf_gvsp_fieldinfo,
ett_gvsp_fieldinfo, fieldinfo_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_genericflags, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_timestamp, tvb, offset + 4, 8, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(gvsp_tree, tvb, offset + 12, hf_gvsp_pixelformat, ett_gvsp_pixelformat,
pixelformat_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sizex, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sizey, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_offsetx, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_offsety, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_paddingx, tvb, offset + 32, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_paddingy, tvb, offset + 34, 2, ENC_BIG_ENDIAN);
return 36;
}
static gint dissect_extended_chunk_data_trailer(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadlength, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sizey, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_chunklayoutidex, tvb, offset + 12, 4, ENC_BIG_ENDIAN);
return 16;
}
static gint dissect_jpeg_leader(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_bitmask(gvsp_tree, tvb, offset, hf_gvsp_fieldinfo,
ett_gvsp_fieldinfo, fieldinfo_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_genericflags, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_timestamp, tvb, offset + 4, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloaddatasize, tvb, offset + 12, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_timestamptickfrequency, tvb, offset + 20, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_dataformat, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
return 32;
}
static gint dissect_h264_leader(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_bitmask(gvsp_tree, tvb, offset, hf_gvsp_fieldinfo,
ett_gvsp_fieldinfo, fieldinfo_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloaddatasize, tvb, offset + 4, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_packetizationmode, tvb, offset + 13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_packetsize, tvb, offset + 14, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_profileidc, tvb, offset + 17, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(gvsp_tree, tvb, offset + 18, hf_gvsp_cs, ett_gvsp_cs,
cs_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_levelidc, tvb, offset + 19, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sropinterleavingdepth, tvb, offset + 20, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sropmaxdondiff, tvb, offset + 22, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sropdeintbufreq, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sropinitbuftime, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
return 32;
}
static gint dissect_multizone_image_leader(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_bitmask(gvsp_tree, tvb, offset, hf_gvsp_fieldinfo,
ett_gvsp_fieldinfo, fieldinfo_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_timestamp, tvb, offset + 4, 8, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(gvsp_tree, tvb, offset + 12, hf_gvsp_sc_zone_direction,
ett_gvsp_sc_zone_direction, sc_zone_direction_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(gvsp_tree, tvb, offset + 16, hf_gvsp_pixelformat, ett_gvsp_pixelformat,
pixelformat_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sizex, tvb, offset + 20, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_sizey, tvb, offset + 24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_offsetx, tvb, offset + 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_offsety, tvb, offset + 32, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_paddingx, tvb, offset + 36, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_paddingy, tvb, offset + 38, 2, ENC_BIG_ENDIAN);
return 40;
}
static gint dissect_generic_trailer(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(gvsp_tree, hf_gvsp_payloadtype, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
return 4;
}
static gint dissect_extra_chunk_info(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(gvsp_tree, hf_gvsp_chunkdatapayloadlengthex, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_chunklayoutidex, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
return 8;
}
static void dissect_packet_payload(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(gvsp_tree, hf_gvsp_payloaddata, tvb, offset, -1, ENC_NA);
}
static void dissect_packet_payload_h264(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_item(gvsp_tree, hf_gvsp_timestamp, tvb, offset, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloaddata, tvb, offset + 8, -1, ENC_NA);
}
static void dissect_packet_payload_multizone(proto_tree *gvsp_tree, tvbuff_t *tvb, packet_info *pinfo _U_, gint offset)
{
proto_tree_add_bitmask(gvsp_tree, tvb, offset + 1, hf_gvsp_zoneinfo,
ett_gvsp_zoneinfo, zoneinfo_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_addressoffsethigh, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_addressoffsetlow, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvsp_tree, hf_gvsp_payloaddata, tvb, offset + 8, -1, ENC_NA);
}
static void dissect_packet_all_in(proto_tree *gvsp_tree, tvbuff_t *tvb, gint offset, packet_info *pinfo, gvsp_packet_info *info)
{
gint ret;
switch (info->payloadtype)
{
case GVSP_PAYLOAD_IMAGE:
offset += dissect_image_leader(gvsp_tree, tvb, pinfo, offset);
offset += dissect_image_trailer(gvsp_tree, tvb, pinfo, offset);
if (info->chunk != 0)
{
offset += dissect_extra_chunk_info(gvsp_tree, tvb, pinfo, offset);
}
dissect_packet_payload(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_RAWDATA:
offset += dissect_raw_data_leader(gvsp_tree, tvb, pinfo, offset);
offset += dissect_generic_trailer(gvsp_tree, tvb, pinfo, offset);
if (info->chunk != 0)
{
offset += dissect_extra_chunk_info(gvsp_tree, tvb, pinfo, offset);
}
dissect_packet_payload(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_FILE:
ret = dissect_file_leader(gvsp_tree, tvb, pinfo, offset);
if (ret < 0)
break;
offset += ret;
offset += dissect_generic_trailer(gvsp_tree, tvb, pinfo, offset);
if (info->chunk != 0)
{
offset += dissect_extra_chunk_info(gvsp_tree, tvb, pinfo, offset);
}
dissect_packet_payload(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_CHUNKDATA:
offset += dissect_chunk_data_leader(gvsp_tree, tvb, pinfo, offset);
offset += dissect_chunk_data_trailer(gvsp_tree, tvb, pinfo, offset);
if (info->chunk != 0)
{
offset += dissect_extra_chunk_info(gvsp_tree, tvb, pinfo, offset);
}
dissect_packet_payload(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_EXTENDEDCHUNKDATA:
offset += dissect_extended_chunk_data_leader(gvsp_tree, tvb, pinfo, offset);
offset += dissect_extended_chunk_data_trailer(gvsp_tree, tvb, pinfo, offset);
if (info->chunk != 0)
{
offset += dissect_extra_chunk_info(gvsp_tree, tvb, pinfo, offset);
}
dissect_packet_payload(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_JPEG:
case GVSP_PAYLOAD_JPEG2000:
offset += dissect_jpeg_leader(gvsp_tree, tvb, pinfo, offset);
offset += dissect_generic_trailer(gvsp_tree, tvb, pinfo, offset);
if (info->chunk != 0)
{
offset += dissect_extra_chunk_info(gvsp_tree, tvb, pinfo, offset);
}
dissect_packet_payload(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_H264:
offset += dissect_h264_leader(gvsp_tree, tvb, pinfo, offset);
offset += dissect_generic_trailer(gvsp_tree, tvb, pinfo, offset);
if (info->chunk != 0)
{
offset += dissect_extra_chunk_info(gvsp_tree, tvb, pinfo, offset);
}
dissect_packet_payload_h264(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_MULTIZONEIMAGE:
offset += dissect_multizone_image_leader(gvsp_tree, tvb, pinfo, offset);
offset += dissect_image_trailer(gvsp_tree, tvb, pinfo, offset);
if (info->chunk != 0)
{
offset += dissect_extra_chunk_info(gvsp_tree, tvb, pinfo, offset);
}
dissect_packet_payload_multizone(gvsp_tree, tvb, pinfo, offset);
break;
}
}
static void dissect_packet_leader(proto_tree *gvsp_tree, tvbuff_t *tvb, gint offset, packet_info *pinfo, gvsp_packet_info *info)
{
switch (info->payloadtype)
{
case GVSP_PAYLOAD_IMAGE:
dissect_image_leader(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_RAWDATA:
dissect_raw_data_leader(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_FILE:
dissect_file_leader(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_CHUNKDATA:
dissect_chunk_data_leader(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_EXTENDEDCHUNKDATA:
dissect_extended_chunk_data_leader(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_JPEG:
case GVSP_PAYLOAD_JPEG2000:
dissect_jpeg_leader(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_H264:
dissect_h264_leader(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_MULTIZONEIMAGE:
dissect_multizone_image_leader(gvsp_tree, tvb, pinfo, offset);
break;
default:
break;
}
}
static void dissect_packet_trailer(proto_tree *gvsp_tree, tvbuff_t *tvb, gint offset, packet_info *pinfo, gvsp_packet_info *info)
{
switch (info->payloadtype)
{
case GVSP_PAYLOAD_IMAGE:
case GVSP_PAYLOAD_MULTIZONEIMAGE:
offset += dissect_image_trailer(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_CHUNKDATA:
offset += dissect_chunk_data_trailer(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_EXTENDEDCHUNKDATA:
offset += dissect_extended_chunk_data_trailer(gvsp_tree, tvb, pinfo, offset);
break;
case GVSP_PAYLOAD_RAWDATA:
case GVSP_PAYLOAD_FILE:
case GVSP_PAYLOAD_JPEG:
case GVSP_PAYLOAD_JPEG2000:
case GVSP_PAYLOAD_H264:
offset += dissect_generic_trailer(gvsp_tree, tvb, pinfo, offset);
break;
default:
break;
}
if (info->chunk != 0)
{
dissect_extra_chunk_info(gvsp_tree, tvb, pinfo, offset);
}
}
static int dissect_gvsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti = NULL;
gint offset = 0;
proto_tree *gvsp_tree = NULL;
gvsp_packet_info info;
if ((tvb_reported_length(tvb) < GVSP_MIN_PACKET_SIZE) ||
(tvb_captured_length(tvb) < 5))
{
return 0;
}
memset(&info, 0x00, sizeof(info));
info.format = tvb_get_guint8(tvb, 4);
if ((info.format & 0x80) && tvb_reported_length(tvb) < GVSP_V2_MIN_PACKET_SIZE)
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GVSP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_gvsp, tvb, offset, -1, ENC_NA);
gvsp_tree = proto_item_add_subtree(ti, ett_gvsp);
info.enhanced = info.format & 0x80;
info.format &= 0x7F;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(info.format, formatnames, "Unknown Format (0x%x)"));
proto_tree_add_item(gvsp_tree, hf_gvsp_status, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (info.enhanced == 0)
{
info.blockid = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(gvsp_tree, hf_gvsp_blockid16, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else
{
guint8 flags;
flags = tvb_get_guint8(tvb, offset + 1);
info.flag_resendrangeerror = flags & 0x04;
info.flag_previousblockdropped = flags & 0x02;
info.flag_packetresend = flags & 0x01;
proto_tree_add_bitmask(gvsp_tree, tvb, offset, hf_gvsp_flags,
ett_gvsp_flags, flags_fields, ENC_BIG_ENDIAN);
}
offset += 2;
proto_tree_add_item(gvsp_tree, hf_gvsp_format, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (info.enhanced == 0)
{
info.packetid = tvb_get_ntohl(tvb, offset - 1);
info.packetid &= 0x00FFFFFF;
proto_tree_add_item(gvsp_tree, hf_gvsp_packetid24, tvb, offset, 3, ENC_BIG_ENDIAN);
}
offset += 3;
if (info.enhanced != 0)
{
info.blockid = tvb_get_ntoh64(tvb, offset);
proto_tree_add_item(gvsp_tree, hf_gvsp_blockid64, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
info.packetid = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(gvsp_tree, hf_gvsp_packetid32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
col_append_fstr(pinfo->cinfo, COL_INFO, "[Block ID: %" G_GINT64_MODIFIER "u Packet ID: %d] ", (guint64)info.blockid, info.packetid);
if (info.flag_resendrangeerror != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "[RANGE_ERROR] ");
}
if (info.flag_previousblockdropped != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "[BLOCK_DROPPED] ");
}
if (info.flag_packetresend != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "[PACKET_RESEND] ");
}
switch (info.format)
{
case GVSP_PACKET_PAYLOAD:
dissect_packet_payload(gvsp_tree, tvb, pinfo, offset);
return tvb_captured_length(tvb);
case GVSP_PACKET_PAYLOAD_H264:
dissect_packet_payload_h264(gvsp_tree, tvb, pinfo, offset);
return tvb_captured_length(tvb);
case GVSP_PACKET_PAYLOAD_MULTIZONE:
dissect_packet_payload_multizone(gvsp_tree, tvb, pinfo, offset);
return tvb_captured_length(tvb);
default:
break;
}
if (tvb_captured_length_remaining(tvb, offset) >= 2)
{
info.payloadtype = tvb_get_ntohs(tvb, offset + 2);
}
info.chunk = info.payloadtype & 0x4000;
info.payloadtype &= 0x3FFF;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_ext(info.payloadtype, &payloadtypenames_ext, "Unknown Payload Type (0x%x)"));
switch (info.format)
{
case GVSP_PACKET_ALLIN:
dissect_packet_all_in(gvsp_tree, tvb, offset, pinfo, &info);
break;
case GVSP_PACKET_LEADER:
dissect_packet_leader(gvsp_tree, tvb, offset, pinfo, &info);
break;
case GVSP_PACKET_TRAILER:
dissect_packet_trailer(gvsp_tree, tvb, offset, pinfo, &info);
break;
default:
break;
}
return tvb_captured_length(tvb);
}
static gboolean dissect_gvsp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
conversation_t *conversation = NULL;
guint16 status_code = 0;
guint8 format = 0;
if ((tvb_reported_length(tvb) < GVSP_MIN_PACKET_SIZE) ||
(tvb_captured_length(tvb) < 5))
{
return FALSE;
}
format = tvb_get_guint8(tvb, 4);
if ((format & 0x80) && tvb_reported_length(tvb) < GVSP_V2_MIN_PACKET_SIZE)
{
return FALSE;
}
status_code = tvb_get_ntohs(tvb, 0);
if (status_code == 0x0000 ||
status_code == 0x0100 ||
(status_code >= 0x8001 && status_code <= 0x8016) ||
status_code == 0x8FFF)
{
format &= 0x7F;
if (format >= 1 && format <= 6)
{
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, gvsp_handle);
dissect_gvsp(tvb, pinfo, tree, data);
return TRUE;
}
}
return FALSE;
}
void proto_register_gvsp(void)
{
module_t *gvsp_module;
static hf_register_info hfgvsp[] =
{
{& hf_gvsp_status,
{ "Status", "gvsp.status",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &statusnames_ext, 0x0,
NULL, HFILL
}},
{& hf_gvsp_blockid16,
{ "Block ID (16 bits)", "gvsp.blockid16",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_flags,
{ "Flags", "gvsp.flags",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_flagdevicespecific0,
{ "Flag Device Specific 0", "gvsp.flag.devicespecific0",
FT_UINT16, BASE_HEX, NULL, 0x8000,
NULL, HFILL
}},
{& hf_gvsp_flagdevicespecific1,
{ "Flag Device Specific 1", "gvsp.flag.devicespecific1",
FT_UINT16, BASE_HEX, NULL, 0x4000,
NULL, HFILL
}},
{& hf_gvsp_flagdevicespecific2,
{ "Flag Device Specific 2", "gvsp.flag.devicespecific2",
FT_UINT16, BASE_HEX, NULL, 0x2000,
NULL, HFILL
}},
{& hf_gvsp_flagdevicespecific3,
{ "Flag Device Specific 3", "gvsp.flag.devicespecific3",
FT_UINT16, BASE_HEX, NULL, 0x1000,
NULL, HFILL
}},
{& hf_gvsp_flagdevicespecific4,
{ "Flag Device Specific 4", "gvsp.flag.devicespecific4",
FT_UINT16, BASE_HEX, NULL, 0x0800,
NULL, HFILL
}},
{& hf_gvsp_flagdevicespecific5,
{ "Flag Device Specific 5", "gvsp.flag.devicespecific5",
FT_UINT16, BASE_HEX, NULL, 0x0400,
NULL, HFILL
}},
{& hf_gvsp_flagdevicespecific6,
{ "Flag Device Specific 6", "gvsp.flag.devicespecific6",
FT_UINT16, BASE_HEX, NULL, 0x0200,
NULL, HFILL
}},
{& hf_gvsp_flagdevicespecific7,
{ "Flag Device Specific 7", "gvsp.flag.devicespecific7",
FT_UINT16, BASE_HEX, NULL, 0x0100,
NULL, HFILL
}},
{& hf_gvsp_flagresendrangeerror,
{ "Flag Resend Range Error 7", "gvsp.flag.resendrangeerror",
FT_UINT16, BASE_HEX, NULL, 0x0004,
NULL, HFILL
}},
{& hf_gvsp_flagpreviousblockdropped,
{ "Flag Previous Block Dropped", "gvsp.flag.previousblockdropped",
FT_UINT16, BASE_HEX, NULL, 0x0002,
NULL, HFILL
}},
{& hf_gvsp_flagpacketresend,
{ "Flag Packet Resend", "gvsp.flag.packetresend",
FT_UINT16, BASE_HEX, NULL, 0x0001,
NULL, HFILL
}},
{& hf_gvsp_format,
{ "Format", "gvsp.format",
FT_UINT8, BASE_HEX, VALS(formatnames), 0,
NULL, HFILL
}},
{& hf_gvsp_packetid24,
{ "Packet ID (24 bits)", "gvsp.packetid24",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_blockid64,
{ "Block ID (64 bits v2.0)", "gvsp.blockid64",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_packetid32,
{ "Packet ID (32 bits v2.0)", "gvsp.packetid32",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_payloadtype,
{ "Payload Type", "gvsp.payloadtype",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &payloadtypenames_ext, 0x0,
NULL, HFILL
}},
{& hf_gvsp_payloaddata,
{ "Payload Data", "gvsp.payloaddata",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_timestamp,
{ "Timestamp", "gvsp.timestamp",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_pixelformat,
{ "Pixel Format", "gvsp.pixel",
FT_UINT32, BASE_HEX|BASE_EXT_STRING, &pixeltypenames_ext, 0x0,
NULL, HFILL
}},
{& hf_gvsp_sizex,
{ "Size X", "gvsp.sizex",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_sizey,
{ "Size Y", "gvsp.sizey",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_offsetx,
{ "Offset X", "gvsp.offsetx",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_offsety,
{ "Offset Y", "gvsp.offsety",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_paddingx,
{ "Padding X", "gvsp.paddingx",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_paddingy,
{ "Padding Y", "gvsp.paddingy",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_payloaddatasize,
{ "Payload Data Size", "gvsp.payloaddatasize",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_pixelcolor,
{ "Monochrome or Color", "gvsp.pixel.color",
FT_UINT32, BASE_HEX, VALS(colornames), 0xFF000000,
NULL, HFILL
}},
{& hf_gvsp_pixeloccupy,
{ "Occupy Bits", "gvsp.pixel.occupy",
FT_UINT32, BASE_DEC, NULL, 0x00FF0000,
NULL, HFILL
}},
{& hf_gvsp_pixelid,
{ "ID", "gvsp.pixel.id",
FT_UINT32, BASE_HEX, NULL, 0x0000FFFF,
NULL, HFILL
}},
{& hf_gvsp_filename,
{ "ID", "gvsp.filename",
FT_STRINGZ, BASE_NONE, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_payloadlength,
{ "Payload Length", "gvsp.payloadlength",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_fieldinfo,
{ "Field Info", "gvsp.fieldinfo",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_fieldid,
{ "Field ID", "gvsp.fieldid",
FT_UINT8, BASE_HEX, NULL, 0xF0,
NULL, HFILL
}},
{& hf_gvsp_fieldcount,
{ "Field Count", "gvsp.fieldcount",
FT_UINT8, BASE_HEX, NULL, 0x0F,
NULL, HFILL
}},
{& hf_gvsp_genericflags,
{ "Generic Flag", "gvsp.genericflag",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_timestamptickfrequency ,
{ "Timestamp Tick Frequency", "gvsp.timestamptickfrequency",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_dataformat,
{ "Data Format", "gvsp.dataformat",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_packetizationmode,
{ "packetization_mode", "gvsp.packetizationmode",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_packetsize,
{ "packet_size", "gvsp.packetsize",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_profileidc,
{ "profile_idc", "gvsp.profileidc",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_cs,
{ "cs", "gvsp.cs",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_cs0,
{ "cs0", "gvsp.cs0",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL
}},
{& hf_gvsp_cs1,
{ "cs1", "gvsp.cs1",
FT_UINT8, BASE_HEX, NULL, 0x40,
NULL, HFILL
}},
{& hf_gvsp_cs2,
{ "cs2", "gvsp.cs2",
FT_UINT8, BASE_HEX, NULL, 0x20,
NULL, HFILL
}},
{& hf_gvsp_cs3,
{ "cs3", "gvsp.cs3",
FT_UINT8, BASE_HEX, NULL, 0x10,
NULL, HFILL
}},
{& hf_gvsp_levelidc,
{ "level_idc", "gvsp.levelidc",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_sropinterleavingdepth,
{ "srop_interlaving_depth", "gvsp.sropinterleavingdepth",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_sropmaxdondiff,
{ "srop_max_don_diff", "gvsp.sropmaxdondiff",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_sropdeintbufreq,
{ "srop_deint_buf_req", "gvsp.sropdeintbufreq",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_sropinitbuftime,
{ "srop_init_buf_time", "gvsp.sropinitbuftime",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_zoneinfo,
{ "Zone Info", "gvsp.zoneinfo",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_zoneid,
{ "Zone ID", "gvsp.zoneid",
FT_UINT8, BASE_HEX, NULL, 0x3E,
NULL, HFILL
}},
{& hf_gvsp_endofzone,
{ "End of Zone", "gvsp.endofzone",
FT_UINT8, BASE_HEX, NULL, 0x01,
NULL, HFILL
}},
{& hf_gvsp_addressoffsethigh,
{ "Address Offset High", "gvsp.addressoffsethigh",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_addressoffsetlow,
{ "Address Offset Low", "gvsp.addressoffsetlow",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_sc_zone_direction,
{ "Zone Directions Mask", "gvsp.zonedirection",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL
}},
{& hf_gvsp_sc_zone0_direction,
{ "Zone 0 Direction", "gvsp.zone0direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x80000000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone1_direction,
{ "Zone 1 Direction", "gvsp.zone1direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x40000000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone2_direction,
{ "Zone 2 Direction", "gvsp.zone2direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x20000000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone3_direction,
{ "Zone 3 Direction", "gvsp.zone3direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x10000000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone4_direction,
{ "Zone 4 Direction", "gvsp.zone4direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x08000000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone5_direction,
{ "Zone 5 Direction", "gvsp.zone5direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x04000000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone6_direction,
{ "Zone 6 Direction", "gvsp.zone6direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x02000000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone7_direction,
{ "Zone 7 Direction", "gvsp.zone7direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x01000000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone8_direction,
{ "Zone 8 Direction", "gvsp.zone8direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00800000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone9_direction,
{ "Zone 9 Direction", "gvsp.zone9direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00400000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone10_direction,
{ "Zone 10 Direction", "gvsp.zone10direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00200000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone11_direction,
{ "Zone 11 Direction", "gvsp.zone1direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00100000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone12_direction,
{ "Zone 12 Direction", "gvsp.zone12direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00080000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone13_direction,
{ "Zone 13 Direction", "gvsp.zone13direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00040000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone14_direction,
{ "Zone 14 Direction", "gvsp.zone14direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00020000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone15_direction,
{ "Zone 15 Direction", "gvsp.zone15direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00010000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone16_direction,
{ "Zone 16 Direction", "gvsp.zone16direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00008000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone17_direction,
{ "Zone 17 Direction", "gvsp.zone17direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00004000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone18_direction,
{ "Zone 18 Direction", "gvsp.zone18direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00002000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone19_direction,
{ "Zone 19 Direction", "gvsp.zone19direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00001000,
NULL, HFILL
}},
{& hf_gvsp_sc_zone20_direction,
{ "Zone 20 Direction", "gvsp.zone20direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000800,
NULL, HFILL
}},
{& hf_gvsp_sc_zone21_direction,
{ "Zone 21 Direction", "gvsp.zone21direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000400,
NULL, HFILL
}},
{& hf_gvsp_sc_zone22_direction,
{ "Zone 22 Direction", "gvsp.zone22direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000200,
NULL, HFILL
}},
{& hf_gvsp_sc_zone23_direction,
{ "Zone 23 Direction", "gvsp.zone23direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000100,
NULL, HFILL
}},
{& hf_gvsp_sc_zone24_direction,
{ "Zone 24 Direction", "gvsp.zone24direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000080,
NULL, HFILL
}},
{& hf_gvsp_sc_zone25_direction,
{ "Zone 25 Direction", "gvsp.zone25direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000040,
NULL, HFILL
}},
{& hf_gvsp_sc_zone26_direction,
{ "Zone 26 Direction", "gvsp.zone26direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000020,
NULL, HFILL
}},
{& hf_gvsp_sc_zone27_direction,
{ "Zone 27 Direction", "gvsp.zone27direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000010,
NULL, HFILL
}},
{& hf_gvsp_sc_zone28_direction,
{ "Zone 28 Direction", "gvsp.zone28direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000008,
NULL, HFILL
}},
{& hf_gvsp_sc_zone29_direction,
{ "Zone 29 Direction", "gvsp.zone29direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000004,
NULL, HFILL
}},
{& hf_gvsp_sc_zone30_direction,
{ "Zone 30 Direction", "gvsp.zone30direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000002,
NULL, HFILL
}},
{& hf_gvsp_sc_zone31_direction,
{ "Zone 31 Direction", "gvsp.zone31direction",
FT_BOOLEAN, 32, TFS(&directionnames), 0x00000001,
NULL, HFILL
}},
{& hf_gvsp_chunkdatapayloadlengthex,
{ "Chunk Data Payload Length", "gvsp.chunkdatapayloadlengthex",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL
}},
{& hf_gvsp_chunklayoutidex,
{ "Chunk Layout ID", "gvsp.chunklayoutidex",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL
}},
};
static gint *ett[] = {
&ett_gvsp,
&ett_gvsp_flags,
&ett_gvsp_header,
&ett_gvsp_payload,
&ett_gvsp_trailer,
&ett_gvsp_pixelformat,
&ett_gvsp_fieldinfo,
&ett_gvsp_cs,
&ett_gvsp_sc_zone_direction,
&ett_gvsp_zoneinfo
};
proto_gvsp = proto_register_protocol("GigE Vision Streaming Protocol", "GVSP", "gvsp");
new_register_dissector("gvsp", dissect_gvsp, proto_gvsp);
proto_register_field_array(proto_gvsp, hfgvsp, array_length(hfgvsp));
proto_register_subtree_array(ett, array_length(ett));
gvsp_module = prefs_register_protocol(proto_gvsp, proto_reg_handoff_gvsp);
prefs_register_obsolete_preference(gvsp_module, "enable_heuristic");
}
void proto_reg_handoff_gvsp(void)
{
static gboolean initialized = FALSE;
if (!initialized) {
gvsp_handle = new_create_dissector_handle((new_dissector_t)dissect_gvsp, proto_gvsp);
dissector_add_for_decode_as("udp.port", gvsp_handle);
heur_dissector_add("udp", dissect_gvsp_heur, "GigE Vision over UDP", "gvsp_udp", proto_gvsp, HEURISTIC_ENABLE);
initialized = TRUE;
}
}
