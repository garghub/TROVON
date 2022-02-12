static guint32 get_len_offset(guint8 frame_type){
guint32 len;
switch((frame_type & FTFLAGS_STREAM_OOO) >> 2){
case 0:
len = 0;
break;
case 1:
len = 2;
break;
case 2:
len = 3;
break;
case 3:
len = 4;
break;
case 4:
len = 5;
break;
case 5:
len = 6;
break;
case 6:
len = 7;
break;
case 7:
len = 8;
break;
default:
len = 0;
break;
}
return len;
}
static guint32 get_len_stream(guint8 frame_type){
guint32 len;
switch(frame_type & FTFLAGS_STREAM_SS){
case 0:
len = 1;
break;
case 1:
len = 2;
break;
case 2:
len = 3;
break;
case 3:
len = 4;
break;
default:
len = 1;
break;
}
return len;
}
static guint32 get_len_largest_observed(guint8 frame_type){
guint32 len;
switch((frame_type & FTFLAGS_ACK_LL) >> 2){
case 0:
len = 1;
break;
case 1:
len = 2;
break;
case 2:
len = 4;
break;
case 3:
len = 6;
break;
default:
len = 1;
break;
}
return len;
}
static guint32 get_len_missing_packet(guint8 frame_type){
guint32 len;
switch(frame_type & FTFLAGS_ACK_MM){
case 0:
len = 1;
break;
case 1:
len = 2;
break;
case 2:
len = 4;
break;
case 3:
len = 6;
break;
default:
len = 1;
break;
}
return len;
}
static gboolean is_quic_unencrypt(tvbuff_t *tvb, guint offset, guint16 len_pkn, quic_info_data_t *quic_info){
guint8 frame_type;
guint8 num_ranges, num_revived, num_timestamp;
guint32 len_stream = 0, len_offset = 0, len_data = 0, len_largest_observed = 1, len_missing_packet = 1;
guint32 message_tag;
if(tvb_captured_length_remaining(tvb, offset) <= 13){
return FALSE;
}
offset += 12;
if(quic_info->version < 34){
offset += 1;
}
while(tvb_reported_length_remaining(tvb, offset) > 0){
if (tvb_captured_length_remaining(tvb, offset) <= 1){
return FALSE;
}
frame_type = tvb_get_guint8(tvb, offset);
if((frame_type & FTFLAGS_SPECIAL) == 0){
offset += 1;
switch(frame_type){
case FT_PADDING:
return FALSE;
break;
case FT_RST_STREAM:
offset += 4;
offset += 8;
offset += 4;
break;
case FT_CONNECTION_CLOSE:{
guint16 len_reason;
offset += 4;
if (tvb_captured_length_remaining(tvb, offset) <= 2){
return FALSE;
}
len_reason = tvb_get_letohs(tvb, offset);
offset += 2;
if (tvb_captured_length_remaining(tvb, offset) == len_reason){
return TRUE;
}
}
break;
case FT_GOAWAY:{
guint16 len_reason;
offset += 4;
offset += 4;
if (tvb_captured_length_remaining(tvb, offset) <= 2){
return FALSE;
}
len_reason = tvb_get_letohs(tvb, offset);
offset += 2;
offset += len_reason;
}
break;
case FT_WINDOW_UPDATE:
offset += 4;
offset += 8;
break;
case FT_BLOCKED:
offset += 4;
break;
case FT_STOP_WAITING:
if(quic_info->version < 34){
offset += 1;
}
offset += len_pkn;
break;
case FT_PING:
default:
break;
}
} else {
if(frame_type & FTFLAGS_STREAM){
if(frame_type & FTFLAGS_STREAM_D){
len_data = 2;
}
len_offset = get_len_offset(frame_type);
len_stream = get_len_stream(frame_type);
offset += 1;
offset += len_stream;
offset += len_offset;
offset += len_data;
if (tvb_captured_length_remaining(tvb, offset) <= 4){
return FALSE;
}
message_tag = tvb_get_ntohl(tvb, offset);
if (message_tag == MTAG_CHLO|| message_tag == MTAG_SHLO || message_tag == MTAG_REJ) {
return TRUE;
}
} else if (frame_type & FTFLAGS_ACK) {
len_largest_observed = get_len_largest_observed(frame_type);
len_missing_packet = get_len_missing_packet(frame_type);
offset += 1;
if(quic_info->version < 34){
offset += 1;
}
offset += len_largest_observed;
offset += 2;
if (tvb_captured_length_remaining(tvb, offset) <= 1){
return FALSE;
}
num_timestamp = tvb_get_guint8(tvb, offset);
offset += 1;
if(num_timestamp > 0){
offset += 1;
offset += 4;
offset += (num_timestamp - 1)*(1+2);
}
if(frame_type & FTFLAGS_ACK_N){
if (tvb_captured_length_remaining(tvb, offset) <= 1){
return FALSE;
}
num_ranges = tvb_get_guint8(tvb, offset);
offset += 1;
offset += num_ranges*(len_missing_packet+1);
if (tvb_captured_length_remaining(tvb, offset) <= 1){
return FALSE;
}
num_revived = tvb_get_guint8(tvb, offset);
offset += 1;
offset += num_revived*len_largest_observed;
}
} else {
offset += 1;
}
}
}
return FALSE;
}
static guint32
dissect_quic_tag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *quic_tree, guint offset, guint32 tag_number, quic_info_data_t *quic_info){
guint32 tag_offset_start = offset + tag_number*4*2;
guint32 tag_offset = 0, total_tag_len = 0;
gint32 tag_len;
while(tag_number){
proto_tree *tag_tree, *ti_len, *ti_tag, *ti_type;
guint32 offset_end, tag;
ti_tag = proto_tree_add_item(quic_tree, hf_quic_tags, tvb, offset, 8, ENC_NA);
tag_tree = proto_item_add_subtree(ti_tag, ett_quic_tag_value);
ti_type = proto_tree_add_item(tag_tree, hf_quic_tag_type, tvb, offset, 4, ENC_ASCII|ENC_NA);
tag = tvb_get_ntohl(tvb, offset);
proto_item_append_text(ti_type, " (%s)", val_to_str(tag, tag_vals, "Unknown"));
proto_item_append_text(ti_tag, ": %s (%s)", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 4, ENC_ASCII|ENC_NA), val_to_str(tag, tag_vals, "Unknown"));
offset += 4;
proto_tree_add_item(tag_tree, hf_quic_tag_offset_end, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset_end = tvb_get_letohl(tvb, offset);
tag_len = offset_end - tag_offset;
total_tag_len += tag_len;
ti_len = proto_tree_add_uint(tag_tree, hf_quic_tag_length, tvb, offset, 4, tag_len);
proto_item_append_text(ti_tag, " (l=%u)", tag_len);
PROTO_ITEM_SET_GENERATED(ti_len);
offset += 4;
if( tag_len > tvb_reported_length_remaining(tvb, tag_offset_start + tag_offset)){
tag_len = tvb_reported_length_remaining(tvb, tag_offset_start + tag_offset);
expert_add_info(pinfo, ti_len, &ei_quic_tag_length);
}
proto_tree_add_item(tag_tree, hf_quic_tag_value, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
switch(tag){
case TAG_PAD:
proto_tree_add_item(tag_tree, hf_quic_tag_pad, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_SNI:
proto_tree_add_item(tag_tree, hf_quic_tag_sni, tvb, tag_offset_start + tag_offset, tag_len, ENC_ASCII|ENC_NA);
proto_item_append_text(ti_tag, ": %s", tvb_get_string_enc(wmem_packet_scope(), tvb, tag_offset_start + tag_offset, tag_len, ENC_ASCII|ENC_NA));
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_VER:
proto_tree_add_item(tag_tree, hf_quic_tag_ver, tvb, tag_offset_start + tag_offset, 4, ENC_ASCII|ENC_NA);
proto_item_append_text(ti_tag, " %s", tvb_get_string_enc(wmem_packet_scope(), tvb, tag_offset_start + tag_offset, 4, ENC_ASCII|ENC_NA));
tag_offset += 4;
tag_len -= 4;
break;
case TAG_CCS:
while(tag_len > 0){
proto_tree_add_item(tag_tree, hf_quic_tag_ccs, tvb, tag_offset_start + tag_offset, 8, ENC_NA);
tag_offset += 8;
tag_len -= 8;
}
break;
case TAG_PDMD:
proto_tree_add_item(tag_tree, hf_quic_tag_pdmd, tvb, tag_offset_start + tag_offset, tag_len, ENC_ASCII|ENC_NA);
proto_item_append_text(ti_tag, ": %s", tvb_get_string_enc(wmem_packet_scope(), tvb, tag_offset_start + tag_offset, tag_len, ENC_ASCII|ENC_NA));
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_UAID:
proto_tree_add_item(tag_tree, hf_quic_tag_uaid, tvb, tag_offset_start + tag_offset, tag_len, ENC_ASCII|ENC_NA);
proto_item_append_text(ti_tag, ": %s", tvb_get_string_enc(wmem_packet_scope(), tvb, tag_offset_start + tag_offset, tag_len, ENC_ASCII|ENC_NA));
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_STK:
proto_tree_add_item(tag_tree, hf_quic_tag_stk, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_SNO:
proto_tree_add_item(tag_tree, hf_quic_tag_sno, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_PROF:
proto_tree_add_item(tag_tree, hf_quic_tag_prof, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_SCFG:{
guint32 scfg_tag_number;
proto_tree_add_item(tag_tree, hf_quic_tag_scfg, tvb, tag_offset_start + tag_offset, 4, ENC_ASCII|ENC_NA);
tag_offset += 4;
tag_len -= 4;
proto_tree_add_item(tag_tree, hf_quic_tag_scfg_number, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
scfg_tag_number = tvb_get_letohl(tvb, tag_offset_start + tag_offset);
tag_offset += 4;
tag_len -= 4;
dissect_quic_tag(tvb, pinfo, tag_tree, tag_offset_start + tag_offset, scfg_tag_number, quic_info);
tag_offset += tag_len;
tag_len -= tag_len;
}
break;
case TAG_RREJ:
while(tag_len > 0){
proto_tree_add_item(tag_tree, hf_quic_tag_rrej, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_tag, ", Code %s", val_to_str_ext(tvb_get_letohl(tvb, tag_offset_start + tag_offset), &handshake_failure_reason_vals_ext, "Unknown"));
tag_offset += 4;
tag_len -= 4;
}
break;
case TAG_CRT:
proto_tree_add_item(tag_tree, hf_quic_tag_crt, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_AEAD:
while(tag_len > 0){
proto_tree *ti_aead;
ti_aead = proto_tree_add_item(tag_tree, hf_quic_tag_aead, tvb, tag_offset_start + tag_offset, 4, ENC_ASCII|ENC_NA);
proto_item_append_text(ti_aead, " (%s)", val_to_str(tvb_get_ntohl(tvb, tag_offset_start + tag_offset), tag_aead_vals, "Unknown"));
proto_item_append_text(ti_tag, ", %s", val_to_str(tvb_get_ntohl(tvb, tag_offset_start + tag_offset), tag_aead_vals, "Unknown"));
tag_offset += 4;
tag_len -= 4;
}
break;
case TAG_SCID:
proto_tree_add_item(tag_tree, hf_quic_tag_scid, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_PUBS:
proto_tree_add_item(tag_tree, hf_quic_tag_pubs, tvb, tag_offset_start + tag_offset, 2, ENC_LITTLE_ENDIAN);
tag_offset +=2;
tag_len -= 2;
while(tag_len > 0){
proto_tree_add_item(tag_tree, hf_quic_tag_pubs, tvb, tag_offset_start + tag_offset, 3, ENC_LITTLE_ENDIAN);
tag_offset += 3;
tag_len -= 3;
}
break;
case TAG_KEXS:
while(tag_len > 0){
proto_tree *ti_kexs;
ti_kexs = proto_tree_add_item(tag_tree, hf_quic_tag_kexs, tvb, tag_offset_start + tag_offset, 4, ENC_ASCII|ENC_NA);
proto_item_append_text(ti_kexs, " (%s)", val_to_str(tvb_get_ntohl(tvb, tag_offset_start + tag_offset), tag_kexs_vals, "Unknown"));
proto_item_append_text(ti_tag, ", %s", val_to_str(tvb_get_ntohl(tvb, tag_offset_start + tag_offset), tag_kexs_vals, "Unknown"));
tag_offset += 4;
tag_len -= 4;
}
break;
case TAG_OBIT:
proto_tree_add_item(tag_tree, hf_quic_tag_obit, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_EXPY:
proto_tree_add_item(tag_tree, hf_quic_tag_expy, tvb, tag_offset_start + tag_offset, 8, ENC_LITTLE_ENDIAN);
tag_offset += 8;
tag_len -= 8;
break;
case TAG_NONC:
proto_tree_add_item(tag_tree, hf_quic_tag_nonc, tvb, tag_offset_start + tag_offset, 32, ENC_NA);
tag_offset += 32;
tag_len -= 32;
break;
case TAG_MSPC:
proto_tree_add_item(tag_tree, hf_quic_tag_mspc, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_tag, ": %u", tvb_get_letohl(tvb, tag_offset_start + tag_offset));
tag_offset += 4;
tag_len -= 4;
break;
case TAG_TCID:
proto_tree_add_item(tag_tree, hf_quic_tag_tcid, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
tag_offset += 4;
tag_len -= 4;
break;
case TAG_SRBF:
proto_tree_add_item(tag_tree, hf_quic_tag_srbf, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
tag_offset += 4;
tag_len -= 4;
break;
case TAG_ICSL:
proto_tree_add_item(tag_tree, hf_quic_tag_icsl, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
tag_offset += 4;
tag_len -= 4;
break;
case TAG_SCLS:
proto_tree_add_item(tag_tree, hf_quic_tag_scls, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
tag_offset += 4;
tag_len -= 4;
break;
case TAG_COPT:
if(tag_len){
proto_tree_add_item(tag_tree, hf_quic_tag_copt, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
tag_offset += 4;
tag_len -= 4;
}
break;
case TAG_CCRT:
proto_tree_add_item(tag_tree, hf_quic_tag_ccrt, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_IRTT:
proto_tree_add_item(tag_tree, hf_quic_tag_irtt, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_tag, ": %u", tvb_get_letohl(tvb, tag_offset_start + tag_offset));
tag_offset += 4;
tag_len -= 4;
break;
case TAG_CFCW:
proto_tree_add_item(tag_tree, hf_quic_tag_cfcw, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_tag, ": %u", tvb_get_letohl(tvb, tag_offset_start + tag_offset));
tag_offset += 4;
tag_len -= 4;
break;
case TAG_SFCW:
proto_tree_add_item(tag_tree, hf_quic_tag_sfcw, tvb, tag_offset_start + tag_offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_tag, ": %u", tvb_get_letohl(tvb, tag_offset_start + tag_offset));
tag_offset += 4;
tag_len -= 4;
break;
case TAG_CETV:
proto_tree_add_item(tag_tree, hf_quic_tag_cetv, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_XLCT:
proto_tree_add_item(tag_tree, hf_quic_tag_xlct, tvb, tag_offset_start + tag_offset, 8, ENC_NA);
tag_offset += 8;
tag_len -= 8;
break;
case TAG_NONP:
proto_tree_add_item(tag_tree, hf_quic_tag_nonp, tvb, tag_offset_start + tag_offset, 32, ENC_NA);
tag_offset += 32;
tag_len -= 32;
break;
case TAG_CSCT:
proto_tree_add_item(tag_tree, hf_quic_tag_csct, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
tag_offset += tag_len;
tag_len -= tag_len;
break;
case TAG_CTIM:
proto_tree_add_item(tag_tree, hf_quic_tag_ctim, tvb, tag_offset_start + tag_offset, 8, ENC_TIME_TIMESPEC);
tag_offset += 8;
tag_len -= 8;
break;
case TAG_RNON:
proto_tree_add_item(tag_tree, hf_quic_tag_rnon, tvb, tag_offset_start + tag_offset, 8, ENC_LITTLE_ENDIAN);
tag_offset += 8;
tag_len -= 8;
break;
case TAG_RSEQ:
proto_tree_add_item(tag_tree, hf_quic_tag_rseq, tvb, tag_offset_start + tag_offset, 8, ENC_LITTLE_ENDIAN);
tag_offset += 8;
tag_len -= 8;
break;
case TAG_CADR: {
guint32 addr_type;
proto_tree_add_item_ret_uint(tag_tree, hf_quic_tag_cadr_addr_type, tvb, tag_offset_start + tag_offset, 2, ENC_LITTLE_ENDIAN, &addr_type);
tag_offset += 2;
tag_len -= 2;
switch(addr_type){
case 2:
proto_tree_add_item(tag_tree, hf_quic_tag_cadr_addr_ipv4, tvb, tag_offset_start + tag_offset, 4, ENC_NA);
tag_offset += 4;
tag_len -= 4;
break;
case 10:
proto_tree_add_item(tag_tree, hf_quic_tag_cadr_addr_ipv6, tvb, tag_offset_start + tag_offset, 16, ENC_NA);
tag_offset += 16;
tag_len -= 16;
break;
default:
proto_tree_add_item(tag_tree, hf_quic_tag_cadr_addr, tvb, tag_offset_start + tag_offset, tag_len - 2 - 2, ENC_NA);
tag_offset += tag_len + 2 + 2 ;
tag_len -= tag_len - 2 - 2;
break;
}
proto_tree_add_item(tag_tree, hf_quic_tag_cadr_port, tvb, tag_offset_start + tag_offset, 2, ENC_LITTLE_ENDIAN);
tag_offset += 2;
tag_len -= 2;
}
break;
default:
proto_tree_add_item(tag_tree, hf_quic_tag_unknown, tvb, tag_offset_start + tag_offset, tag_len, ENC_NA);
expert_add_info_format(pinfo, ti_tag, &ei_quic_tag_undecoded,
"Dissector for QUIC Tag"
" %s (%s) code not implemented, Contact"
" Wireshark developers if you want this supported", tvb_get_string_enc(wmem_packet_scope(), tvb, offset-8, 4, ENC_ASCII|ENC_NA), val_to_str(tag, tag_vals, "Unknown"));
tag_offset += tag_len;
tag_len -= tag_len;
break;
}
if(tag_len){
proto_tree_add_expert(tag_tree, pinfo, &ei_quic_tag_unknown, tvb, tag_offset_start + tag_offset, tag_len);
tag_offset += tag_len;
tag_len -= tag_len;
}
tag_number--;
}
return offset + total_tag_len;
}
static int
dissect_quic_frame_type(tvbuff_t *tvb, packet_info *pinfo, proto_tree *quic_tree, guint offset, guint8 len_pkn, quic_info_data_t *quic_info){
proto_item *ti, *ti_ft, *ti_ftflags ;
proto_tree *ft_tree, *ftflags_tree;
guint8 frame_type;
guint8 num_ranges, num_revived, num_timestamp;
guint32 tag_number;
guint32 len_stream = 0, len_offset = 0, len_data = 0, len_largest_observed = 1, len_missing_packet = 1;
ti_ft = proto_tree_add_item(quic_tree, hf_quic_frame, tvb, offset, 1, ENC_NA);
ft_tree = proto_item_add_subtree(ti_ft, ett_quic_ft);
ti_ftflags = proto_tree_add_item(ft_tree, hf_quic_frame_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
frame_type = tvb_get_guint8(tvb, offset);
proto_item_set_text(ti_ft, "%s", rval_to_str(frame_type, frame_type_vals, "Unknown"));
if((frame_type & FTFLAGS_SPECIAL) == 0){
offset += 1;
switch(frame_type){
case FT_PADDING:{
proto_item *ti_pad_len;
guint32 pad_len = tvb_reported_length_remaining(tvb, offset);
ti_pad_len = proto_tree_add_uint(ft_tree, hf_quic_frame_type_padding_length, tvb, offset, 0, pad_len);
PROTO_ITEM_SET_GENERATED(ti_pad_len);
proto_item_append_text(ti_ft, " Length: %u", pad_len);
proto_tree_add_item(ft_tree, hf_quic_frame_type_padding, tvb, offset, -1, ENC_NA);
offset += pad_len;
}
break;
case FT_RST_STREAM:{
guint32 stream_id, error_code;
proto_tree_add_item_ret_uint(ft_tree, hf_quic_frame_type_rsts_stream_id, tvb, offset, 4, ENC_LITTLE_ENDIAN, &stream_id);
offset += 4;
proto_tree_add_item(ft_tree, hf_quic_frame_type_rsts_byte_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item_ret_uint(ft_tree, hf_quic_frame_type_rsts_error_code, tvb, offset, 4, ENC_LITTLE_ENDIAN, &error_code);
offset += 4;
proto_item_append_text(ti_ft, " Stream ID: %u, Error code: %s", stream_id, val_to_str_ext(error_code, &error_code_vals_ext, "Unknown (%d)"));
}
break;
case FT_CONNECTION_CLOSE:{
guint16 len_reason;
guint32 error_code;
proto_tree_add_item_ret_uint(ft_tree, hf_quic_frame_type_cc_error_code, tvb, offset, 4, ENC_LITTLE_ENDIAN, &error_code);
offset += 4;
proto_tree_add_item(ft_tree, hf_quic_frame_type_cc_reason_phrase_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
len_reason = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(ft_tree, hf_quic_frame_type_cc_reason_phrase, tvb, offset, len_reason, ENC_ASCII|ENC_NA);
offset += len_reason;
proto_item_append_text(ti_ft, " Error code: %s", val_to_str_ext(error_code, &error_code_vals_ext, "Unknown (%d)"));
col_set_str(pinfo->cinfo, COL_INFO, "Connection Close");
}
break;
case FT_GOAWAY:{
guint16 len_reason;
guint32 error_code, last_good_stream_id;
proto_tree_add_item_ret_uint(ft_tree, hf_quic_frame_type_goaway_error_code, tvb, offset, 4, ENC_LITTLE_ENDIAN, &error_code);
offset += 4;
proto_tree_add_item_ret_uint(ft_tree, hf_quic_frame_type_goaway_last_good_stream_id, tvb, offset, 4, ENC_LITTLE_ENDIAN, &last_good_stream_id);
offset += 4;
proto_tree_add_item(ft_tree, hf_quic_frame_type_goaway_reason_phrase_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
len_reason = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(ft_tree, hf_quic_frame_type_goaway_reason_phrase, tvb, offset, len_reason, ENC_ASCII|ENC_NA);
offset += len_reason;
proto_item_append_text(ti_ft, " Stream ID: %u, Error code: %s", last_good_stream_id, val_to_str_ext(error_code, &error_code_vals_ext, "Unknown (%d)"));
}
break;
case FT_WINDOW_UPDATE:{
guint32 stream_id;
proto_tree_add_item_ret_uint(ft_tree, hf_quic_frame_type_wu_stream_id, tvb, offset, 4, ENC_LITTLE_ENDIAN, &stream_id);
offset += 4;
proto_tree_add_item(ft_tree, hf_quic_frame_type_wu_byte_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_item_append_text(ti_ft, " Stream ID: %u", stream_id);
}
break;
case FT_BLOCKED:{
guint32 stream_id;
proto_tree_add_item_ret_uint(ft_tree, hf_quic_frame_type_blocked_stream_id, tvb, offset, 4, ENC_LITTLE_ENDIAN, &stream_id);
offset += 4;
proto_item_append_text(ti_ft, " Stream ID: %u", stream_id);
}
break;
case FT_STOP_WAITING:{
guint8 send_entropy;
if(quic_info->version < 34){
proto_tree_add_item(ft_tree, hf_quic_frame_type_sw_send_entropy, tvb, offset, 1, ENC_LITTLE_ENDIAN);
send_entropy = tvb_get_guint8(tvb, offset);
proto_item_append_text(ti_ft, " Send Entropy: %u", send_entropy);
offset += 1;
}
proto_tree_add_item(ft_tree, hf_quic_frame_type_sw_least_unacked_delta, tvb, offset, len_pkn, ENC_LITTLE_ENDIAN);
offset += len_pkn;
}
break;
case FT_PING:
default:
break;
}
}
else {
guint32 stream_id = 0, message_tag;
ftflags_tree = proto_item_add_subtree(ti_ftflags, ett_quic_ftflags);
proto_tree_add_item(ftflags_tree, hf_quic_frame_type_stream , tvb, offset, 1, ENC_LITTLE_ENDIAN);
if(frame_type & FTFLAGS_STREAM){
proto_tree_add_item(ftflags_tree, hf_quic_frame_type_stream_f, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ftflags_tree, hf_quic_frame_type_stream_d, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if(frame_type & FTFLAGS_STREAM_D){
len_data = 2;
}
proto_tree_add_item(ftflags_tree, hf_quic_frame_type_stream_ooo, tvb, offset, 1, ENC_LITTLE_ENDIAN);
len_offset = get_len_offset(frame_type);
proto_tree_add_item(ftflags_tree, hf_quic_frame_type_stream_ss, tvb, offset, 1, ENC_LITTLE_ENDIAN);
len_stream = get_len_stream(frame_type);
offset += 1;
if(len_stream) {
proto_tree_add_item_ret_uint(ft_tree, hf_quic_stream_id, tvb, offset, len_stream, ENC_LITTLE_ENDIAN, &stream_id);
offset += len_stream;
}
if(len_offset) {
proto_tree_add_item(ft_tree, hf_quic_offset_len, tvb, offset, len_offset, ENC_LITTLE_ENDIAN);
offset += len_offset;
}
if(len_data) {
proto_tree_add_item(ft_tree, hf_quic_data_len, tvb, offset, len_data, ENC_LITTLE_ENDIAN);
offset += len_data;
}
ti = proto_tree_add_item(ft_tree, hf_quic_tag, tvb, offset, 4, ENC_ASCII|ENC_NA);
message_tag = tvb_get_ntohl(tvb, offset);
proto_item_append_text(ti, " (%s)", val_to_str(message_tag, message_tag_vals, "Unknown Tag"));
proto_item_append_text(ti_ft, " Stream ID:%u, Type: %s (%s)", stream_id, tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 4, ENC_ASCII|ENC_NA), val_to_str(message_tag, message_tag_vals, "Unknown Tag"));
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str(message_tag, message_tag_vals, "Unknown"));
offset += 4;
proto_tree_add_item(ft_tree, hf_quic_tag_number, tvb, offset, 2, ENC_LITTLE_ENDIAN);
tag_number = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(ft_tree, hf_quic_padding, tvb, offset, 2, ENC_NA);
offset += 2;
offset = dissect_quic_tag(tvb, pinfo, ft_tree, offset, tag_number, quic_info);
} else if (frame_type & FTFLAGS_ACK) {
proto_tree_add_item(ftflags_tree, hf_quic_frame_type_ack, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ftflags_tree, hf_quic_frame_type_ack_n, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ftflags_tree, hf_quic_frame_type_ack_t, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ftflags_tree, hf_quic_frame_type_ack_ll, tvb, offset, 1, ENC_LITTLE_ENDIAN);
len_largest_observed = get_len_largest_observed(frame_type);
proto_tree_add_item(ftflags_tree, hf_quic_frame_type_ack_mm, tvb, offset, 1, ENC_LITTLE_ENDIAN);
len_missing_packet = get_len_missing_packet(frame_type);
offset += 1;
if(quic_info->version < 34){
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_received_entropy, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_largest_observed, tvb, offset, len_largest_observed, ENC_LITTLE_ENDIAN);
offset += len_largest_observed;
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_ack_delay_time, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_num_timestamp, tvb, offset, 1, ENC_LITTLE_ENDIAN);
num_timestamp = tvb_get_guint8(tvb, offset);
offset += 1;
if(num_timestamp){
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_delta_largest_observed, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_first_timestamp, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
num_timestamp -= 1;
while(num_timestamp){
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_delta_largest_observed, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_time_since_previous_timestamp, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
num_timestamp--;
}
}
if(frame_type & FTFLAGS_ACK_N){
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_num_ranges, tvb, offset, 1, ENC_LITTLE_ENDIAN);
num_ranges = tvb_get_guint8(tvb, offset);
offset += 1;
while(num_ranges){
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_missing_packet, tvb, offset, len_missing_packet, ENC_LITTLE_ENDIAN);
offset += len_missing_packet;
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_range_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
num_ranges--;
}
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_num_revived, tvb, offset, 1, ENC_LITTLE_ENDIAN);
num_revived = tvb_get_guint8(tvb, offset);
offset += 1;
while(num_revived){
proto_tree_add_item(ft_tree, hf_quic_frame_type_ack_revived_packet, tvb, offset, len_largest_observed, ENC_LITTLE_ENDIAN);
offset += len_largest_observed;
num_revived--;
}
}
} else {
offset += 1;
}
}
return offset;
}
static int
dissect_quic_unencrypt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *quic_tree, guint offset, guint8 len_pkn, quic_info_data_t *quic_info){
proto_item *ti_prflags;
proto_tree *prflags_tree;
proto_tree_add_item(quic_tree, hf_quic_message_authentication_hash, tvb, offset, 12, ENC_NA);
offset += 12;
if(quic_info->version < 34){
ti_prflags = proto_tree_add_item(quic_tree, hf_quic_prflags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
prflags_tree = proto_item_add_subtree(ti_prflags, ett_quic_prflags);
proto_tree_add_item(prflags_tree, hf_quic_prflags_entropy, tvb, offset, 1, ENC_NA);
proto_tree_add_item(prflags_tree, hf_quic_prflags_fecg, tvb, offset, 1, ENC_NA);
proto_tree_add_item(prflags_tree, hf_quic_prflags_fec, tvb, offset, 1, ENC_NA);
proto_tree_add_item(prflags_tree, hf_quic_prflags_rsv, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset +=1;
}
while(tvb_reported_length_remaining(tvb, offset) > 0){
offset = dissect_quic_frame_type(tvb, pinfo, quic_tree, offset, len_pkn, quic_info);
}
return offset;
}
static int
dissect_quic_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti, *ti_puflags;
proto_tree *quic_tree, *puflags_tree;
guint offset = 0;
guint8 puflags, len_cid = 0, len_pkn;
guint64 cid = 0, pkn;
conversation_t *conv;
quic_info_data_t *quic_info;
if (tvb_captured_length(tvb) < QUIC_MIN_LENGTH)
return 0;
conv = find_or_create_conversation(pinfo);
quic_info = (quic_info_data_t *)conversation_get_proto_data(conv, proto_quic);
if (!quic_info) {
quic_info = wmem_new(wmem_file_scope(), quic_info_data_t);
quic_info->version = 0;
conversation_add_proto_data(conv, proto_quic, quic_info);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "QUIC");
ti = proto_tree_add_item(tree, proto_quic, tvb, 0, -1, ENC_NA);
quic_tree = proto_item_add_subtree(ti, ett_quic);
puflags = tvb_get_guint8(tvb, offset);
if(puflags & PUFLAGS_CID){
len_cid = 8;
}
if(puflags & PUFLAGS_VRSN){
quic_info->version = atoi(tvb_get_string_enc(wmem_packet_scope(), tvb,offset + 1 + len_cid + 1, 3, ENC_ASCII));
}
ti_puflags = proto_tree_add_item(quic_tree, hf_quic_puflags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
puflags_tree = proto_item_add_subtree(ti_puflags, ett_quic_puflags);
proto_tree_add_item(puflags_tree, hf_quic_puflags_vrsn, tvb, offset, 1, ENC_NA);
proto_tree_add_item(puflags_tree, hf_quic_puflags_rst, tvb, offset, 1, ENC_NA);
if(quic_info->version < 33){
proto_tree_add_item(puflags_tree, hf_quic_puflags_cid_old, tvb, offset, 1, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(puflags_tree, hf_quic_puflags_dnonce, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(puflags_tree, hf_quic_puflags_cid, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
proto_tree_add_item(puflags_tree, hf_quic_puflags_pkn, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(puflags_tree, hf_quic_puflags_mpth, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(puflags_tree, hf_quic_puflags_rsv, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (len_cid) {
cid = tvb_get_letoh64(tvb, offset);
proto_tree_add_item(quic_tree, hf_quic_cid, tvb, offset, len_cid, ENC_LITTLE_ENDIAN);
offset += len_cid;
}
if(puflags & PUFLAGS_VRSN){
if(pinfo->srcport == 443){
while(tvb_reported_length_remaining(tvb, offset) > 0){
proto_tree_add_item(quic_tree, hf_quic_version, tvb, offset, 4, ENC_ASCII|ENC_NA);
offset += 4;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Version Negotiation, CID: %" G_GINT64_MODIFIER "u", cid);
return offset;
}
else{
proto_tree_add_item(quic_tree, hf_quic_version, tvb, offset, 4, ENC_ASCII|ENC_NA);
offset += 4;
}
}
if(puflags & PUFLAGS_RST){
guint32 tag_number, message_tag;
ti = proto_tree_add_item(quic_tree, hf_quic_tag, tvb, offset, 4, ENC_ASCII|ENC_NA);
message_tag = tvb_get_ntohl(tvb, offset);
proto_item_append_text(ti, " (%s)", val_to_str(message_tag, message_tag_vals, "Unknown Tag"));
offset += 4;
proto_tree_add_item(quic_tree, hf_quic_tag_number, tvb, offset, 2, ENC_LITTLE_ENDIAN);
tag_number = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(quic_tree, hf_quic_padding, tvb, offset, 2, ENC_NA);
offset += 2;
offset = dissect_quic_tag(tvb, pinfo, quic_tree, offset, tag_number, quic_info);
col_add_fstr(pinfo->cinfo, COL_INFO, "Public Reset, CID: %" G_GINT64_MODIFIER "u", cid);
return offset;
}
if(puflags & PUFLAGS_DNONCE && quic_info->version >= 33){
if(pinfo->srcport == 443){
proto_tree_add_item(quic_tree, hf_quic_diversification_nonce, tvb, offset, 32, ENC_NA);
offset += 32;
}
}
switch((puflags & PUFLAGS_PKN) >> 4){
case 0:
len_pkn = 1;
pkn = tvb_get_guint8(tvb, offset);
break;
case 1:
len_pkn = 2;
pkn = tvb_get_letohs(tvb, offset);
break;
case 2:
len_pkn = 4;
pkn = tvb_get_letohl(tvb, offset);
break;
case 3:
len_pkn = 6;
pkn = tvb_get_letoh48(tvb, offset);
break;
default:
len_pkn = 6;
pkn = tvb_get_letoh48(tvb, offset);
break;
}
proto_tree_add_item(quic_tree, hf_quic_packet_number, tvb, offset, len_pkn, ENC_LITTLE_ENDIAN);
offset += len_pkn;
if (is_quic_unencrypt(tvb, offset, len_pkn, quic_info)){
offset = dissect_quic_unencrypt(tvb, pinfo, quic_tree, offset, len_pkn, quic_info);
}else {
col_add_str(pinfo->cinfo, COL_INFO, "Payload (Encrypted)");
proto_tree_add_item(quic_tree, hf_quic_payload, tvb, offset, -1, ENC_NA);
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", PKN: %" G_GINT64_MODIFIER "u", pkn);
if(cid){
col_append_fstr(pinfo->cinfo, COL_INFO, ", CID: %" G_GINT64_MODIFIER "u", cid);
}
return offset;
}
static int
dissect_quic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
return dissect_quic_common(tvb, pinfo, tree, NULL);
}
void
proto_register_quic(void)
{
module_t *quic_module;
static hf_register_info hf[] = {
{ &hf_quic_puflags,
{ "Public Flags", "quic.puflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Specifying per-packet public flags", HFILL }
},
{ &hf_quic_puflags_vrsn,
{ "Version", "quic.puflags.version",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PUFLAGS_VRSN,
"Signifies that this packet also contains the version of the QUIC protocol", HFILL }
},
{ &hf_quic_puflags_rst,
{ "Reset", "quic.puflags.reset",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PUFLAGS_RST,
"Signifies that this packet is a public reset packet", HFILL }
},
{ &hf_quic_puflags_dnonce,
{ "Diversification nonce", "quic.puflags.cid",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PUFLAGS_DNONCE,
"Indicates the presence of a 32 byte diversification nonce", HFILL }
},
{ &hf_quic_puflags_cid,
{ "CID Length", "quic.puflags.cid",
FT_BOOLEAN, 8, TFS(&puflags_cid_tfs), PUFLAGS_CID,
"Indicates the full 8 byte Connection ID is present", HFILL }
},
{ &hf_quic_puflags_cid_old,
{ "CID Length", "quic.puflags.cid.old",
FT_UINT8, BASE_HEX, VALS(puflags_cid_old_vals), PUFLAGS_CID_OLD,
"Signifies the Length of CID", HFILL }
},
{ &hf_quic_puflags_pkn,
{ "Packet Number Length", "quic.puflags.pkn",
FT_UINT8, BASE_HEX, VALS(puflags_pkn_vals), PUFLAGS_PKN,
"Signifies the Length of packet number", HFILL }
},
{ &hf_quic_puflags_mpth,
{ "Multipath", "quic.puflags.mpth",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PUFLAGS_MPTH,
"Reserved for multipath use", HFILL }
},
{ &hf_quic_puflags_rsv,
{ "Reserved", "quic.puflags.rsv",
FT_UINT8, BASE_HEX, NULL, PUFLAGS_RSV,
"Must be Zero", HFILL }
},
{ &hf_quic_cid,
{ "CID", "quic.cid",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Connection ID 64 bit pseudo random number", HFILL }
},
{ &hf_quic_version,
{ "Version", "quic.version",
FT_STRING, BASE_NONE, NULL, 0x0,
"32 bit opaque tag that represents the version of the QUIC", HFILL }
},
{ &hf_quic_diversification_nonce,
{ "Diversification nonce", "quic.diversification_nonce",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_packet_number,
{ "Packet Number", "quic.packet_number",
FT_UINT64, BASE_DEC, NULL, 0x0,
"The lower 8, 16, 32, or 48 bits of the packet number", HFILL }
},
{ &hf_quic_prflags,
{ "Private Flags", "quic.prflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Specifying per-packet Private flags", HFILL }
},
{ &hf_quic_prflags_entropy,
{ "Entropy", "quic.prflags.entropy",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PRFLAGS_ENTROPY,
"For data packets, signifies that this packet contains the 1 bit of entropy, for fec packets, contains the xor of the entropy of protected packets", HFILL }
},
{ &hf_quic_prflags_fecg,
{ "FEC Group", "quic.prflags.fecg",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PRFLAGS_FECG,
"Indicates whether the fec byte is present.", HFILL }
},
{ &hf_quic_prflags_fec,
{ "FEC", "quic.prflags.fec",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PRFLAGS_FEC,
"Signifies that this packet represents an FEC packet", HFILL }
},
{ &hf_quic_prflags_rsv,
{ "Reserved", "quic.prflags.rsv",
FT_UINT8, BASE_HEX, NULL, PRFLAGS_RSV,
"Must be Zero", HFILL }
},
{ &hf_quic_message_authentication_hash,
{ "Message Authentication Hash", "quic.message_authentication_hash",
FT_BYTES, BASE_NONE, NULL, 0x0,
"The hash is an FNV1a-128 hash, serialized in little endian order", HFILL }
},
{ &hf_quic_frame,
{ "Frame", "quic.frame",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_frame_type,
{ "Frame Type", "quic.frame_type",
FT_UINT8 ,BASE_RANGE_STRING | BASE_HEX, RVALS(frame_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_quic_frame_type_padding_length,
{ "Padding Length", "quic.frame_type.padding.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_frame_type_padding,
{ "Padding", "quic.frame_type.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Must be zero", HFILL }
},
{ &hf_quic_frame_type_rsts_stream_id,
{ "Stream ID", "quic.frame_type.rsts.stream_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Stream ID of the stream being terminated", HFILL }
},
{ &hf_quic_frame_type_rsts_byte_offset,
{ "Byte offset", "quic.frame_type.rsts.byte_offset",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Indicating the absolute byte offset of the end of data for this stream", HFILL }
},
{ &hf_quic_frame_type_rsts_error_code,
{ "Error code", "quic.frame_type.rsts.error_code",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &error_code_vals_ext, 0x0,
"Indicates why the stream is being closed", HFILL }
},
{ &hf_quic_frame_type_cc_error_code,
{ "Error code", "quic.frame_type.cc.error_code",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &error_code_vals_ext, 0x0,
"Stream ID of the stream being terminated", HFILL }
},
{ &hf_quic_frame_type_cc_reason_phrase_length,
{ "Reason phrase Length", "quic.frame_type.cc.reason_phrase.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifying the length of the reason phrase", HFILL }
},
{ &hf_quic_frame_type_cc_reason_phrase,
{ "Reason phrase", "quic.frame_type.cc.reason_phrase",
FT_STRING, BASE_NONE, NULL, 0x0,
"An optional human-readable explanation for why the connection was closed", HFILL }
},
{ &hf_quic_frame_type_goaway_error_code,
{ "Error code", "quic.frame_type.goaway.error_code",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &error_code_vals_ext, 0x0,
"Stream ID of the stream being terminated", HFILL }
},
{ &hf_quic_frame_type_goaway_last_good_stream_id,
{ "Error code", "quic.frame_type.goaway.error_code",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &error_code_vals_ext, 0x0,
"Stream ID of the stream being terminated", HFILL }
},
{ &hf_quic_frame_type_goaway_reason_phrase_length,
{ "Reason phrase Length", "quic.frame_type.goaway.reason_phrase.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifying the length of the reason phrase", HFILL }
},
{ &hf_quic_frame_type_goaway_reason_phrase,
{ "Reason phrase", "quic.frame_type.goaway.reason_phrase",
FT_STRING, BASE_NONE, NULL, 0x0,
"An optional human-readable explanation for why the connection was closed", HFILL }
},
{ &hf_quic_frame_type_wu_stream_id,
{ "Stream ID", "quic.frame_type.wu.stream_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"ID of the stream whose flow control windows is begin updated, or 0 to specify the connection-level flow control window", HFILL }
},
{ &hf_quic_frame_type_wu_byte_offset,
{ "Byte offset", "quic.frame_type.wu.byte_offset",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Indicating the absolute byte offset of data which can be sent on the given stream", HFILL }
},
{ &hf_quic_frame_type_blocked_stream_id,
{ "Stream ID", "quic.frame_type.blocked.stream_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicating the stream which is flow control blocked", HFILL }
},
{ &hf_quic_frame_type_sw_send_entropy,
{ "Send Entropy", "quic.frame_type.sw.send_entropy",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifying the cumulative hash of entropy in all sent packets up to the packet with packet number one less than the least unacked packet", HFILL }
},
{ &hf_quic_frame_type_sw_least_unacked_delta,
{ "Least unacked delta", "quic.frame_type.sw.least_unacked_delta",
FT_UINT64, BASE_DEC, NULL, 0x0,
"A variable length packet number delta with the same length as the packet header's packet number", HFILL }
},
{ &hf_quic_frame_type_stream,
{ "Stream", "quic.frame_type.stream",
FT_BOOLEAN, 8, NULL, FTFLAGS_STREAM,
NULL, HFILL }
},
{ &hf_quic_frame_type_stream_f,
{ "FIN", "quic.frame_type.stream.f",
FT_BOOLEAN, 8, NULL, FTFLAGS_STREAM_F,
NULL, HFILL }
},
{ &hf_quic_frame_type_stream_d,
{ "Data Length", "quic.frame_type.stream.d",
FT_BOOLEAN, 8, TFS(&len_data_vals), FTFLAGS_STREAM_D,
NULL, HFILL }
},
{ &hf_quic_frame_type_stream_ooo,
{ "Offset Length", "quic.frame_type.stream.ooo",
FT_UINT8, BASE_DEC, VALS(len_offset_vals), FTFLAGS_STREAM_OOO,
NULL, HFILL }
},
{ &hf_quic_frame_type_stream_ss,
{ "Stream Length", "quic.frame_type.stream.ss",
FT_UINT8, BASE_DEC, VALS(len_stream_vals), FTFLAGS_STREAM_SS,
NULL, HFILL }
},
{ &hf_quic_frame_type_ack,
{ "ACK", "quic.frame_type.ack",
FT_BOOLEAN, 8, NULL, FTFLAGS_ACK,
NULL, HFILL }
},
{ &hf_quic_frame_type_ack_n,
{ "NACK", "quic.frame_type.ack.n",
FT_BOOLEAN, 8, NULL, FTFLAGS_ACK_N,
NULL, HFILL }
},
{ &hf_quic_frame_type_ack_t,
{ "Truncated", "quic.frame_type.ack.t",
FT_BOOLEAN, 8, NULL, FTFLAGS_ACK_T,
NULL, HFILL }
},
{ &hf_quic_frame_type_ack_ll,
{ "Largest Observed Length", "quic.frame_type.ack.ll",
FT_UINT8, BASE_DEC, VALS(len_largest_observed_vals), FTFLAGS_ACK_LL,
"Length of the Largest Observed field as 1, 2, 4, or 6 bytes long", HFILL }
},
{ &hf_quic_frame_type_ack_mm,
{ "Missing Packet Length", "quic.frame_type.ack.mm",
FT_UINT8, BASE_DEC, VALS(len_missing_packet_vals), FTFLAGS_ACK_MM,
"Length of the Missing Packet Number Delta field as 1, 2, 4, or 6 bytes long", HFILL }
},
{ &hf_quic_frame_type_ack_received_entropy,
{ "Received Entropy", "quic.frame_type.ack.received_entropy",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifying the cumulative hash of entropy in all received packets up to the largest observed packet", HFILL }
},
{ &hf_quic_frame_type_ack_largest_observed,
{ "Largest Observed", "quic.frame_type.ack.largest_observed",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Representing the largest packet number the peer has observed", HFILL }
},
{ &hf_quic_frame_type_ack_ack_delay_time,
{ "Ack Delay time", "quic.frame_type.ack.ack_delay_time",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifying the time elapsed in microseconds from when largest observed was received until this Ack frame was sent", HFILL }
},
{ &hf_quic_frame_type_ack_num_timestamp,
{ "Num Timestamp", "quic.frame_type.ack.num_timestamp",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifying the number of TCP timestamps that are included in this frame", HFILL }
},
{ &hf_quic_frame_type_ack_delta_largest_observed,
{ "Delta Largest Observed", "quic.frame_type.ack.delta_largest_observed",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifying the packet number delta from the first timestamp to the largest observed", HFILL }
},
{ &hf_quic_frame_type_ack_first_timestamp,
{ "First Timestamp", "quic.frame_type.ack.first_timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Specifying the time delta in microseconds, from the beginning of the connection of the arrival of the packet specified by Largest Observed minus Delta Largest Observed", HFILL }
},
{ &hf_quic_frame_type_ack_time_since_previous_timestamp,
{ "Time since Previous timestamp", "quic.frame_type.ack.time_since_previous_timestamp",
FT_UINT16, BASE_DEC, NULL, 0x0,
"This is the time delta from the previous timestamp", HFILL }
},
{ &hf_quic_frame_type_ack_num_ranges,
{ "Num Ranges", "quic.frame_type.ack.num_ranges",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifying the number of missing packet ranges between largest observed and least unacked", HFILL }
},
{ &hf_quic_frame_type_ack_missing_packet,
{ "Missing Packet Packet Number Delta", "quic.frame_type.ack.missing_packet",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_frame_type_ack_range_length,
{ "Range Length", "quic.frame_type.ack.range_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifying one less than the number of sequential nacks in the range", HFILL }
},
{ &hf_quic_frame_type_ack_num_revived,
{ "Num Ranges", "quic.frame_type.ack.num_revived",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifying the number of revived packets, recovered via FEC", HFILL }
},
{ &hf_quic_frame_type_ack_revived_packet,
{ "Revived Packet Packet Number", "quic.frame_type.ack.revived_packet",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Representing a packet the peer has revived via FEC", HFILL }
},
{ &hf_quic_stream_id,
{ "Stream ID", "quic.stream_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_offset_len,
{ "Offset Length", "quic.offset_len",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_data_len,
{ "Data Length", "quic.data_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag,
{ "Tag", "quic.tag",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_number,
{ "Tag Number", "quic.tag_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tags,
{ "Tag/value", "quic.tags",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_type,
{ "Tag Type", "quic.tag_type",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_offset_end,
{ "Tag offset end", "quic.tag_offset_end",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_length,
{ "Tag length", "quic.tag_offset_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_value,
{ "Tag/value", "quic.tag_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_sni,
{ "Server Name Indication", "quic.tag.sni",
FT_STRING, BASE_NONE, NULL, 0x0,
"The fully qualified DNS name of the server, canonicalised to lowercase with no trailing period", HFILL }
},
{ &hf_quic_tag_pad,
{ "Padding", "quic.tag.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Pad.....", HFILL }
},
{ &hf_quic_tag_ver,
{ "Version", "quic.tag.version",
FT_STRING, BASE_NONE, NULL, 0x0,
"Version of QUIC supported", HFILL }
},
{ &hf_quic_tag_pdmd,
{ "Proof demand", "quic.tag.pdmd",
FT_STRING, BASE_NONE, NULL, 0x0,
"a list of tags describing the types of proof acceptable to the client, in preference order", HFILL }
},
{ &hf_quic_tag_ccs,
{ "Common certificate sets", "quic.tag.ccs",
FT_UINT64, BASE_HEX, NULL, 0x0,
"A series of 64-bit, FNV-1a hashes of sets of common certificates that the client possesses", HFILL }
},
{ &hf_quic_tag_uaid,
{ "Client's User Agent ID", "quic.tag.uaid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_stk,
{ "Source-address token", "quic.tag.stk",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_sno,
{ "Server nonce", "quic.tag.sno",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_prof,
{ "Proof (Signature)", "quic.tag.prof",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_scfg,
{ "Server Config Tag", "quic.tag.scfg",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_scfg_number,
{ "Number Server Config Tag", "quic.tag.scfg.number",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_rrej,
{ "Reasons for server sending", "quic.tag.rrej",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &handshake_failure_reason_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_crt,
{ "Certificate chain", "quic.tag.crt",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_aead,
{ "Authenticated encryption algorithms", "quic.tag.aead",
FT_STRING, BASE_NONE, NULL, 0x0,
"A list of tags, in preference order, specifying the AEAD primitives supported by the server", HFILL }
},
{ &hf_quic_tag_scid,
{ "Server Config ID", "quic.tag.scid",
FT_BYTES, BASE_NONE, NULL, 0x0,
"An opaque, 16-byte identifier for this server config", HFILL }
},
{ &hf_quic_tag_pubs,
{ "Public value", "quic.tag.pubs",
FT_UINT24, BASE_DEC_HEX, NULL, 0x0,
"A list of public values, 24-bit, little-endian length prefixed", HFILL }
},
{ &hf_quic_tag_kexs,
{ "Key exchange algorithms", "quic.tag.kexs",
FT_STRING, BASE_NONE, NULL, 0x0,
"A list of tags, in preference order, specifying the key exchange algorithms that the server supports", HFILL }
},
{ &hf_quic_tag_obit,
{ "Server orbit", "quic.tag.obit",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_expy,
{ "Expiry", "quic.tag.expy",
FT_UINT64, BASE_DEC, NULL, 0x0,
"a 64-bit expiry time for the server config in UNIX epoch seconds", HFILL }
},
{ &hf_quic_tag_nonc,
{ "Client nonce", "quic.tag.nonc",
FT_BYTES, BASE_NONE, NULL, 0x0,
"32 bytes consisting of 4 bytes of timestamp (big-endian, UNIX epoch seconds), 8 bytes of server orbit and 20 bytes of random data", HFILL }
},
{ &hf_quic_tag_mspc,
{ "Max streams per connection", "quic.tag.mspc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_tcid,
{ "Connection ID truncation", "quic.tag.tcid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_srbf,
{ "Socket receive buffer", "quic.tag.srbf",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_icsl,
{ "Idle connection state", "quic.tag.icsl",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_scls,
{ "Silently close on timeout", "quic.tag.scls",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_copt,
{ "Connection options", "quic.tag.copt",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_ccrt,
{ "Cached certificates", "quic.tag.ccrt",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_irtt,
{ "Estimated initial RTT", "quic.tag.irtt",
FT_UINT32, BASE_DEC, NULL, 0x0,
"in us", HFILL }
},
{ &hf_quic_tag_cfcw,
{ "Initial session/connection", "quic.tag.cfcw",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_sfcw,
{ "Initial stream flow control", "quic.tag.sfcw",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_cetv,
{ "Client encrypted tag-value", "quic.tag.cetv",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_xlct,
{ "Expected leaf certificate", "quic.tag.xlct",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_nonp,
{ "Client Proof nonce", "quic.tag.nonp",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_csct,
{ "Signed cert timestamp", "quic.tag.csct",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_ctim,
{ "Client Timestamp", "quic.tag.ctim",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_rnon,
{ "Public reset nonce proof", "quic.tag.rnon",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_rseq,
{ "Rejected Packet Number", "quic.tag.rseq",
FT_UINT64, BASE_DEC, NULL, 0x0,
"a 64-bit packet number", HFILL }
},
{ &hf_quic_tag_cadr_addr_type,
{ "Client IP Address Type", "quic.tag.caddr.addr.type",
FT_UINT16, BASE_DEC, VALS(cadr_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_cadr_addr_ipv4,
{ "Client IP Address", "quic.tag.caddr.addr.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_cadr_addr_ipv6,
{ "Client IP Address", "quic.tag.caddr.addr.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_cadr_addr,
{ "Client IP Address", "quic.tag.caddr.addr",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_cadr_port,
{ "Client Port (Source)", "quic.tag.caddr.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_tag_unknown,
{ "Unknown tag", "quic.tag.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_padding,
{ "Padding", "quic.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_quic_payload,
{ "Payload", "quic.payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Quic Payload..", HFILL }
},
};
static gint *ett[] = {
&ett_quic,
&ett_quic_puflags,
&ett_quic_prflags,
&ett_quic_ft,
&ett_quic_ftflags,
&ett_quic_tag_value
};
static ei_register_info ei[] = {
{ &ei_quic_tag_undecoded, { "quic.tag.undecoded", PI_UNDECODED, PI_NOTE, "Dissector for QUIC Tag code not implemented, Contact Wireshark developers if you want this supported", EXPFILL }},
{ &ei_quic_tag_length, { "quic.tag.length.truncated", PI_MALFORMED, PI_NOTE, "Truncated Tag Length...", EXPFILL }},
{ &ei_quic_tag_unknown, { "quic.tag.unknown.data", PI_UNDECODED, PI_NOTE, "Unknown Data", EXPFILL }}
};
expert_module_t *expert_quic;
proto_quic = proto_register_protocol("QUIC (Quick UDP Internet Connections)",
"QUIC", "quic");
proto_register_field_array(proto_quic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
quic_module = prefs_register_protocol(proto_quic, proto_reg_handoff_quic);
prefs_register_uint_preference(quic_module, "udp.quic.port", "QUIC UDP Port",
"QUIC UDP port if other than the default",
10, &g_quic_port);
prefs_register_uint_preference(quic_module, "udp.quics.port", "QUICS UDP Port",
"QUICS (Secure) UDP port if other than the default",
10, &g_quics_port);
expert_quic = expert_register_protocol(proto_quic);
expert_register_field_array(expert_quic, ei, array_length(ei));
}
void
proto_reg_handoff_quic(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t quic_handle;
static int current_quic_port;
static int current_quics_port;
if (!initialized) {
quic_handle = create_dissector_handle(dissect_quic,
proto_quic);
initialized = TRUE;
} else {
dissector_delete_uint("udp.port", current_quic_port, quic_handle);
dissector_delete_uint("udp.port", current_quics_port, quic_handle);
}
current_quic_port = g_quic_port;
current_quics_port = g_quics_port;
dissector_add_uint("udp.port", current_quic_port, quic_handle);
dissector_add_uint("udp.port", current_quics_port, quic_handle);
}
