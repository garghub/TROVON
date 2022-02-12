static void dissect_ismacryp_v11(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_ISMACRYP_11);
col_set_str(pinfo->cinfo, COL_INFO, "(PT=enc-mpeg4-generic)");
dissect_ismacryp_common( tvb, pinfo, tree, V11);
}
static void dissect_ismacryp_v20(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_ISMACRYP_20);
col_set_str(pinfo->cinfo, COL_INFO, "(PT=enc-isoff-generic)");
dissect_ismacryp_common( tvb, pinfo, tree, V20);
}
static void dissect_ismacryp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_INFO, "Manual version");
dissect_ismacryp_common( tvb, pinfo, tree, version_type);
}
static void dissect_ismacryp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint ismacryp_version)
{
guint set_version;
proto_item *ismacryp_item;
proto_tree *ismacryp_tree;
proto_tree *ismacryp_message_tree;
if ((ismacryp_version!=version_type) && override_flag){
col_append_str(pinfo->cinfo, COL_INFO, " Manual version");
set_version = version_type;
}
else {
set_version = ismacryp_version;
}
if (set_version == V11){
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_ISMACRYP_11);
if (pref_user_mode == FALSE){
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",val_to_str_const(mode, modetypenames, "user mode"));
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s","user mode");
}
user_mode = pref_user_mode;
}
if (set_version == V20){
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_ISMACRYP_20);
user_mode = TRUE;
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s","user mode");
}
if (user_mode == TRUE){
au_size_length = pref_au_size_length;
au_index_length = pref_au_index_length;
au_index_delta_length = pref_au_index_delta_length;
cts_delta_length = pref_cts_delta_length;
dts_delta_length = pref_dts_delta_length;
random_access_indication = pref_random_access_indication;
stream_state_indication = pref_stream_state_indication;
}
if (user_mode == FALSE){
switch (mode){
case AAC_HBR_MODE:
au_size_length = 13;
au_index_length = 3;
au_index_delta_length = 3;
cts_delta_length = 0;
dts_delta_length = 0;
random_access_indication = FALSE;
stream_state_indication = 0;
break;
case MPEG4_VIDEO_MODE:
au_size_length = 0;
au_index_length = 0;
au_index_delta_length = 0;
cts_delta_length = 0;
dts_delta_length = 22;
random_access_indication = TRUE;
stream_state_indication = 0;
break;
case AVC_VIDEO_MODE:
au_size_length = 0;
au_index_length = 0;
au_index_delta_length = 0;
cts_delta_length = 0;
dts_delta_length = 22;
random_access_indication = TRUE;
stream_state_indication = 0;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
if (tree)
{
guint16 au_headers_length = 0;
guint16 totalbits =0;
int deltabits = -1;
guint16 totalbit_offset = 0;
int nbpadding_bits = 0;
offset_struct s_offset;
offset_struct* poffset;
guint16 nbmessage_bytes = 0;
s_offset.offset_bytes = 0;
s_offset.offset_bits = 0;
poffset = &s_offset;
ismacryp_item = proto_tree_add_item(tree, proto_ismacryp, tvb, 0, -1, ENC_NA);
ismacryp_tree = proto_item_add_subtree(ismacryp_item, ett_ismacryp);
proto_item_append_text(tree, ", %s", "ismacryp packet");
ismacryp_item = proto_tree_add_item(ismacryp_tree, hf_ismacryp_au_headers_length,
tvb, poffset->offset_bytes, AU_HEADERS_LENGTH_SIZE, ENC_BIG_ENDIAN );
proto_item_append_text(ismacryp_item, " (bits)");
au_headers_length=tvb_get_ntohs(tvb,poffset->offset_bytes);
poffset->offset_bytes+=AU_HEADERS_LENGTH_SIZE;
totalbits=(poffset->offset_bytes*8)+poffset->offset_bits;
while( ((totalbits-8*AU_HEADERS_LENGTH_SIZE)<au_headers_length) && deltabits!=0 )
{
poffset=dissect_auheader( tvb, poffset, pinfo, ismacryp_tree, set_version);
deltabits=(poffset->offset_bytes*8)+poffset->offset_bits - totalbits;
totalbits+=deltabits;
}
if ( (totalbits-8*AU_HEADERS_LENGTH_SIZE) != au_headers_length)
{
proto_item_append_text(ismacryp_item,
" Error - expected total AU headers size (%d bits) "
"does not match calculated size (%d bits) - check parameters!",
au_headers_length,(totalbits-8*AU_HEADERS_LENGTH_SIZE));
}
if (poffset->offset_bits!=0)
{
totalbit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
nbpadding_bits = (8-poffset->offset_bits);
ismacryp_item = proto_tree_add_bits_item(ismacryp_tree, hf_ismacryp_padding,
tvb, totalbit_offset, nbpadding_bits , ENC_BIG_ENDIAN);
proto_item_append_text(ismacryp_item, ": Length=%d bits",nbpadding_bits);
add_bits(poffset, nbpadding_bits);
}
ismacryp_item = proto_tree_add_item( ismacryp_tree, hf_ismacryp_message,
tvb, poffset->offset_bytes, -1, ENC_NA );
ismacryp_message_tree = proto_item_add_subtree(ismacryp_item, ett_ismacryp_message);
proto_item_append_text(ismacryp_item, ", %s", "Encrypted data");
nbmessage_bytes = tvb_reported_length_remaining(tvb, poffset->offset_bytes);
proto_item_append_text(ismacryp_item, ", Length= %d bytes", nbmessage_bytes );
if (ismacryp_message_tree)
{
poffset->offset_bytes+= nbmessage_bytes;
}
}
}
static offset_struct* dissect_auheader( tvbuff_t *tvb, offset_struct *poffset, packet_info *pinfo, proto_tree *ismacryp_tree, guint set_version )
{
proto_item *ismacryp_item;
proto_tree *ismacryp_header_tree;
proto_tree *ismacryp_header_byte_tree;
guint16 header_len_bytes = 0;
gint header_len = 0;
gint cts_flag =0;
gint dts_flag =0;
gboolean first_au_flag=FALSE;
gint bit_offset = 0;
switch (set_version) {
case V11:
if (selective_encryption)
header_len+=8;
break;
case V20:
if (selective_encryption || slice_indication || padding_indication)
header_len+=8;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
header_len+=au_size_length;
if (poffset->offset_bytes==AU_HEADERS_LENGTH_SIZE){
header_len+=8*(iv_length);
header_len+=8*key_indicator_length;
header_len+=au_index_length;
first_au_flag = TRUE;
}
else {
if (key_indicator_per_au_flag == TRUE)
header_len+=8*key_indicator_length;
header_len+=8*(delta_iv_length);
header_len+=au_index_delta_length;
}
if (cts_delta_length != 0){
cts_flag=tvb_get_bits8(tvb, AU_HEADERS_LENGTH_SIZE*8+header_len, 1);
header_len+=1;
if (cts_flag==1)
header_len+=cts_delta_length;
}
if (dts_delta_length != 0){
dts_flag=tvb_get_bits8(tvb, AU_HEADERS_LENGTH_SIZE*8+header_len, 1);
header_len+=1;
if (dts_flag==1)
header_len+=dts_delta_length;
}
if (random_access_indication != FALSE)
header_len+=1;
if (stream_state_indication !=0)
header_len+=stream_state_indication;
if (header_len% 8!=0)
{
header_len_bytes=((header_len)/8)+1;
}
else
header_len_bytes=((header_len)/8);
ismacryp_item = proto_tree_add_item(ismacryp_tree, hf_ismacryp_header, tvb, poffset->offset_bytes, header_len_bytes, ENC_NA );
proto_item_append_text(ismacryp_item, ": Length=%d bits", header_len);
if ( header_len == 0)
{
proto_item_append_text(ismacryp_item, " Error - zero bit AU header size - check parameters!");
}
ismacryp_header_tree = proto_item_add_subtree(ismacryp_item, ett_ismacryp_header);
if ((set_version==V20 && (selective_encryption || slice_indication || padding_indication))
|| (set_version==V11 && selective_encryption)){
ismacryp_item = proto_tree_add_item(ismacryp_header_tree, hf_ismacryp_header_byte,
tvb, poffset->offset_bytes, 1, ENC_NA );
proto_item_append_text(ismacryp_item, ": Length=8 bits");
ismacryp_header_byte_tree = proto_item_add_subtree(ismacryp_item, ett_ismacryp_header_byte);
add_bits(poffset,7);
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
if (selective_encryption){
proto_tree_add_bits_item(ismacryp_header_byte_tree, hf_ismacryp_au_is_encrypted,
tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_bits_item(ismacryp_header_byte_tree, hf_ismacryp_unused_bits,
tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}
switch (set_version){
case V11:
add_bits(poffset, -7);
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
proto_tree_add_bits_item(ismacryp_header_byte_tree, hf_ismacryp_reserved_bits,
tvb, bit_offset, 7, ENC_BIG_ENDIAN);
add_bits(poffset,8);
break;
case V20:
add_bits(poffset, -1);
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
if (slice_indication){
proto_tree_add_bits_item(ismacryp_header_byte_tree, hf_ismacryp_slice_start,
tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_bits_item(ismacryp_header_byte_tree, hf_ismacryp_unused_bits,
tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}
add_bits(poffset, -1);
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
if (slice_indication){
proto_tree_add_bits_item(ismacryp_header_byte_tree, hf_ismacryp_slice_end,
tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_bits_item(ismacryp_header_byte_tree, hf_ismacryp_unused_bits,
tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}
add_bits(poffset, -3);
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
if (padding_indication){
proto_tree_add_bits_item(ismacryp_header_byte_tree, hf_ismacryp_padding_bitcount,
tvb, bit_offset, 3, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_bits_item(ismacryp_header_byte_tree, hf_ismacryp_unused_bits,
tvb, bit_offset, 3, ENC_BIG_ENDIAN);
}
add_bits(poffset, -2);
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
proto_tree_add_bits_item(ismacryp_header_byte_tree, hf_ismacryp_reserved_bits,
tvb, bit_offset, 2, ENC_BIG_ENDIAN);
add_bits(poffset,8);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
if (first_au_flag == TRUE && iv_length != 0)
{
ismacryp_item = proto_tree_add_item(ismacryp_header_tree, hf_ismacryp_iv, tvb, poffset->offset_bytes, iv_length, ENC_NA);
proto_item_append_text(ismacryp_item, ": Length=%d bytes",iv_length);
col_append_fstr( pinfo->cinfo, COL_INFO,
", IV=0x%s", tvb_bytes_to_str_punct(tvb, poffset->offset_bytes, iv_length,' '));
poffset->offset_bytes+=iv_length;
}
if (first_au_flag == FALSE && delta_iv_length != 0)
{
ismacryp_item = proto_tree_add_item(ismacryp_header_tree, hf_ismacryp_delta_iv,
tvb, poffset->offset_bytes, delta_iv_length, ENC_NA);
proto_item_append_text(ismacryp_item, ": Length=%d bytes",delta_iv_length);
col_append_fstr( pinfo->cinfo, COL_INFO,
", Delta IV=0x%s", tvb_bytes_to_str_punct(tvb, poffset->offset_bytes, delta_iv_length,' '));
poffset->offset_bytes+=iv_length;
}
if ( key_indicator_length != 0 && ( first_au_flag == TRUE || key_indicator_per_au_flag == TRUE) )
{
ismacryp_item = proto_tree_add_item(ismacryp_header_tree, hf_ismacryp_key_indicator,
tvb, poffset->offset_bytes, key_indicator_length, ENC_NA);
proto_item_append_text(ismacryp_item,": Length=%d bytes",key_indicator_length);
col_append_fstr( pinfo->cinfo, COL_INFO,
", KI=0x%s", tvb_bytes_to_str_punct(tvb, poffset->offset_bytes, key_indicator_length,' '));
poffset->offset_bytes+=key_indicator_length;
}
if (au_size_length != 0)
{
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
ismacryp_item = proto_tree_add_bits_item(ismacryp_header_tree,hf_ismacryp_au_size,
tvb, bit_offset, au_size_length, ENC_BIG_ENDIAN);
proto_item_append_text(ismacryp_item, " bytes: Length=%d bits",au_size_length);
add_bits(poffset, au_size_length);
}
if (first_au_flag == TRUE && au_index_length != 0)
{
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
ismacryp_item = proto_tree_add_bits_item(ismacryp_header_tree,hf_ismacryp_au_index,
tvb, bit_offset, au_index_length, ENC_BIG_ENDIAN);
proto_item_append_text(ismacryp_item, " bits: Length=%d bits",au_index_length);
add_bits(poffset, au_index_length);
}
if (first_au_flag == FALSE && au_index_delta_length != 0)
{
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
ismacryp_item = proto_tree_add_bits_item(ismacryp_header_tree,hf_ismacryp_au_index_delta,
tvb, bit_offset, au_index_delta_length, ENC_BIG_ENDIAN);
proto_item_append_text(ismacryp_item, ": Length=%d bits", au_index_delta_length);
add_bits(poffset, au_index_delta_length);
}
if (cts_delta_length != 0)
{
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
proto_tree_add_bits_item(ismacryp_header_tree, hf_ismacryp_cts_flag,
tvb, bit_offset, 1, ENC_BIG_ENDIAN);
add_bits(poffset, 1);
if (cts_flag==1)
{
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
ismacryp_item = proto_tree_add_bits_item(ismacryp_header_tree, hf_ismacryp_cts_delta,
tvb, bit_offset, cts_delta_length, ENC_BIG_ENDIAN);
proto_item_append_text(ismacryp_item, ": Length=%d bits",cts_delta_length);
add_bits(poffset, cts_delta_length);
}
}
if (dts_delta_length != 0)
{
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
proto_tree_add_bits_item(ismacryp_header_tree, hf_ismacryp_dts_flag,
tvb, bit_offset, 1, ENC_BIG_ENDIAN);
add_bits(poffset, 1);
if (dts_flag ==1)
{
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
ismacryp_item = proto_tree_add_bits_item(ismacryp_header_tree, hf_ismacryp_dts_delta,
tvb, bit_offset, dts_delta_length, ENC_BIG_ENDIAN);
proto_item_append_text(ismacryp_item, ": Length=%d bits",dts_delta_length);
add_bits(poffset, dts_delta_length);
}
}
if (random_access_indication != FALSE)
{
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
proto_tree_add_bits_item(ismacryp_header_tree, hf_ismacryp_rap_flag,
tvb, bit_offset, 1, ENC_BIG_ENDIAN);
add_bits(poffset, 1);
}
if (stream_state_indication != 0)
{
bit_offset = (poffset->offset_bytes)*8+poffset->offset_bits;
proto_tree_add_bits_item(ismacryp_header_tree, hf_ismacryp_stream_state,
tvb, bit_offset, stream_state_indication, ENC_BIG_ENDIAN);
add_bits(poffset, stream_state_indication);
}
return poffset;
}
static void add_bits(offset_struct* poffset, gint len_bits)
{
gint nbbitstotal=0;
nbbitstotal=poffset->offset_bytes*8+(poffset->offset_bits)+len_bits;
poffset->offset_bytes=(nbbitstotal / 8);
poffset->offset_bits=(nbbitstotal % 8);
}
void proto_register_ismacryp (void)
{
static hf_register_info hf[] = {
#if 0
{ &hf_ismacryp,
{ "Data", "ismacryp.data", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#endif
#if 0
{ &hf_ismacryp_length,
{ "Total Length", "ismacryp.len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_ismacryp_header,
{ "AU Header", "ismacryp.header", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_ismacryp_header_length,
{ "Header Length", "ismacryp.header.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_ismacryp_au_headers_length,
{ "AU Headers Length", "ismacryp.au_headers.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_header_byte,
{ "Header Byte", "ismacryp.header.byte", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_ismacryp_version,
{ "Version", "ismacryp.version", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_ismacryp_message,
{ "Message", "ismacryp.message", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_ismacryp_message_length,
{ "Message Length", "ismacryp.message.len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
#if 0
{ &hf_ismacryp_parameter,
{ "Parameter", "ismacryp.parameter", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#endif
#if 0
{ &hf_ismacryp_parameter_length,
{ "Parameter Length", "ismacryp.parameter.len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_ismacryp_iv,
{ "IV", "ismacryp.iv", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_delta_iv,
{ "Delta IV", "ismacryp.delta_iv", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_key_indicator,
{ "Key Indicator", "ismacryp.key_indicator", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_ismacryp_parameter_value,
{ "Parameter Value", "ismacryp.parameter.value", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_ismacryp_au_size,
{ "AU size", "ismacryp.au.size", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_au_index,
{ "AU index", "ismacryp.au.index", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_au_index_delta,
{ "AU index delta", "ismacryp.au.index_delta", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_cts_delta,
{ "CTS delta", "ismacryp.cts_delta", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_cts_flag,
{ "CTS flag", "ismacryp.cts_flag", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_dts_delta,
{ "DTS delta", "ismacryp.dts_delta", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_dts_flag,
{ "DTS flag", "ismacryp.dts_flag", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_rap_flag,
{ "RAP flag", "ismacryp.rap_flag", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_stream_state,
{ "Stream state", "ismacryp.stream_state", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_au_is_encrypted,
{ "AU_is_encrypted flag", "ismacryp.au_is_encrypted", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_slice_start,
{ "Slice_start flag", "ismacryp.slice_start", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_slice_end,
{ "Slice_end flag", "ismacryp.slice_end", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_padding_bitcount,
{ "Padding_bitcount bits", "ismacryp.padding_bitcount", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_padding,
{ "Padding bits", "ismacryp.padding", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_reserved_bits,
{ "Reserved bits", "ismacryp.reserved", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ismacryp_unused_bits,
{ "Unused bits", "ismacryp.unused", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] =
{
&ett_ismacryp,
&ett_ismacryp_header,
&ett_ismacryp_header_byte,
&ett_ismacryp_message
};
static const enum_val_t version_types[] = {
{PROTO_TAG_ISMACRYP_11, "ISMACryp v1.1", V11},
{PROTO_TAG_ISMACRYP_20, "ISMACryp v2.0", V20},
{NULL, NULL, -1}
};
static const enum_val_t mode_types[] = {
{"aac-hbr", "aac-hbr", AAC_HBR_MODE},
{"mpeg4-video", "mpeg4-video", MPEG4_VIDEO_MODE},
{"avc-video", "avc-video", AVC_VIDEO_MODE},
{NULL, NULL, -1}
};
module_t *ismacryp_module;
proto_ismacryp = proto_register_protocol ("ISMACryp Protocol", "ISMACRYP", "ismacryp");
proto_register_field_array (proto_ismacryp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
ismacryp_module = prefs_register_protocol(proto_ismacryp, proto_reg_handoff_ismacryp);
prefs_register_uint_preference(ismacryp_module, "dynamic.payload.type",
"ISMACryp dynamic payload type",
"The dynamic payload type which will be interpreted as ISMACryp",
10,
&pref_dynamic_payload_type);
prefs_register_enum_preference(ismacryp_module, "version",
"ISMACryp version",
"ISMACryp version",
&version_type, version_types, TRUE);
prefs_register_static_text_preference(ismacryp_module, "text_override",
"The following option allows the version to be set manually"
" and to override the version if detected from RTP payload type:",
"The following option allows the version to be set manually"
" and to override the version if detected from RTP payload type:");
prefs_register_bool_preference(ismacryp_module,
"override_rtp_pt","Override RTP payload type for version",
"Indicates whether or not the ISMACryp version deduced"
" from RTP payload type, if present, is used or whether the"
" version above is used",
&override_flag);
prefs_register_static_text_preference(ismacryp_module,
"v11_parameters",
"ISMACryp v1.1 parameters:",
"ISMACryp v1.1 parameters declared in SDP");
prefs_register_uint_preference(ismacryp_module,
"iv_length","ISMACrypIVLength (bytes)",
"Set the length of the IV in the ISMACryp AU Header in bytes",
10, &iv_length);
prefs_register_uint_preference(ismacryp_module,
"delta_iv_length","ISMACrypDeltaIVLength (bytes)",
"Set the length of the Delta IV in the ISMACryp AU Header in bytes",
10, &delta_iv_length);
prefs_register_uint_preference(ismacryp_module,
"key_indicator_length","ISMACrypKeyIndicatorLength (bytes)",
"Set the length of the Key Indicator in the ISMACryp AU Header in bytes",
10, &key_indicator_length);
prefs_register_bool_preference(ismacryp_module,
"key_indicator_per_au_flag","ISMACrypKeyIndicatorPerAU (T/F)",
"Indicates whether or not the Key Indicator is present in all AU Headers (T/F)",
&key_indicator_per_au_flag);
prefs_register_bool_preference(ismacryp_module,
"selective_encryption","ISMACrypSelectiveEncryption (T/F)",
"Indicates whether or not selective encryption is enabled (T/F)",
&selective_encryption);
prefs_register_static_text_preference(ismacryp_module,
"v20_parameters",
"ISMACryp v2.0 parameters:",
"ISMACryp v2.0 parameters declared in SDP");
prefs_register_bool_preference(ismacryp_module,
"slice_indication","ISMACrypSliceIndication (T/F)",
"Indicates whether or not slice start / end is present (T/F)",
&slice_indication);
prefs_register_bool_preference(ismacryp_module,
"padding_indication","ISMACrypPaddingIndication (T/F)",
"Indicates whether or not padding information is present (T/F)",
&padding_indication);
prefs_register_static_text_preference(ismacryp_module,
"codec_modes",
"Codec mode selection (RFC3640 for ISMACryp v1.1 only):",
"AU parameters set according to RFC3640 mode or user defined");
prefs_register_enum_preference(ismacryp_module,
"rfc3640_mode",
"RFC3640 mode",
"RFC3640 mode",
&mode, mode_types, TRUE);
prefs_register_bool_preference(ismacryp_module,
"user_mode","User mode (T/F)",
"Indicates use of user mode instead of RFC3640 modes (T/F)",
&pref_user_mode);
prefs_register_static_text_preference(ismacryp_module,
"user_defined_modes",
"Following parameters only valid and used for user mode:",
"AU parameters defined by the user");
prefs_register_uint_preference(ismacryp_module,
"au_size_length","User mode: SizeLength (bits)",
"Set the length of the AU size in the AU Header in bits",
10, &pref_au_size_length);
prefs_register_uint_preference(ismacryp_module,
"au_index_length","User mode: IndexLength (bits)",
"Set the length of the AU index in the AU Header in bits",
10, &pref_au_index_length);
prefs_register_uint_preference(ismacryp_module,
"au_index_delta_length","User mode: IndexDeltaLength (bits)",
"Set the length of the AU delta index in the AU Header in bits",
10, &pref_au_index_delta_length);
prefs_register_uint_preference(ismacryp_module,
"cts_delta_length","User mode: CTSDeltaLength (bits)",
"Set the length of the CTS delta field in the AU Header in bits",
10, &pref_cts_delta_length);
prefs_register_uint_preference(ismacryp_module,
"dts_delta_length","User mode: DTSDeltaLength (bits)",
"Set the length of the DTS delta field in the AU Header in bits",
10, &pref_dts_delta_length);
prefs_register_bool_preference(ismacryp_module,
"random_access_indication","User mode: RandomAccessIndication (T/F)",
"Indicates whether or not the RAP field is present in the AU Header (T/F)",
&pref_random_access_indication);
prefs_register_uint_preference(ismacryp_module,
"stream_state_indication","User mode: StreamStateIndication (number of bits)",
"Indicates the number of bits on which the stream state field is encoded"
" in the AU Header (bits)",
10, &pref_stream_state_indication);
}
void proto_reg_handoff_ismacryp(void)
{
static gboolean ismacryp_prefs_initialized=FALSE;
static dissector_handle_t ismacryp_handle;
static guint dynamic_payload_type;
if (!ismacryp_prefs_initialized) {
dissector_handle_t ismacryp_v11_handle;
dissector_handle_t ismacryp_v20_handle;
ismacryp_handle = create_dissector_handle(dissect_ismacryp, proto_ismacryp);
ismacryp_v11_handle = create_dissector_handle(dissect_ismacryp_v11, proto_ismacryp);
ismacryp_v20_handle = create_dissector_handle(dissect_ismacryp_v20, proto_ismacryp);
ismacryp_prefs_initialized = TRUE;
dissector_add_string("rtp_dyn_payload_type", "ISMACRYP", ismacryp_handle);
dissector_add_string("rtp_dyn_payload_type", "enc-mpeg4-generic", ismacryp_v11_handle);
dissector_add_string("rtp_dyn_payload_type", "enc-isoff-generic", ismacryp_v20_handle);
}
else {
if ( dynamic_payload_type > 95 ){
dissector_delete_uint("rtp.pt", dynamic_payload_type, ismacryp_handle);
}
}
dynamic_payload_type = pref_dynamic_payload_type;
if ( dynamic_payload_type > 95 ){
dissector_add_uint("rtp.pt", dynamic_payload_type, ismacryp_handle);
}
}
