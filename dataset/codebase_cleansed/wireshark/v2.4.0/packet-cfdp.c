static void
dissect_cfdp_src_entity_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint8 len_ent_id)
{
if(len_ent_id > 0 && len_ent_id <= 8){
proto_tree_add_item(tree, hf_cfdp_srcid, tvb, offset, len_ent_id, ENC_BIG_ENDIAN);
}
else{
proto_tree_add_expert_format(tree, pinfo, &ei_cfdp_bad_length, tvb, offset, 0, "Wrong length for the entity ID");
}
}
static void
dissect_cfdp_dst_entity_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint8 len_ent_id)
{
if(len_ent_id > 0 && len_ent_id <= 8){
proto_tree_add_item(tree, hf_cfdp_dstid, tvb, offset, len_ent_id, ENC_BIG_ENDIAN);
}
else{
proto_tree_add_expert_format(tree, pinfo, &ei_cfdp_bad_length, tvb, offset, 0, "Wrong length for the entity ID");
}
}
static void
dissect_cfdp_tseq_num(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, guint8 len_tseq_num)
{
if(len_tseq_num > 0 && len_tseq_num <= 8){
proto_tree_add_item(tree, hf_cfdp_transeqnum, tvb, offset, len_tseq_num, ENC_BIG_ENDIAN);
}
else{
proto_tree_add_expert_format(tree, pinfo, &ei_cfdp_bad_length, tvb, offset, 0, "Wrong length for transaction sequence number");
}
}
static guint32 dissect_cfdp_filestore_req_tlv(tvbuff_t *tvb, proto_tree *tree, guint32 ext_offset){
guint8 tlv_len;
guint32 offset = ext_offset;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
if(tlv_len > 0){
proto_tree *cfdp_filestore_req_tree;
guint8 aux_byte;
cfdp_filestore_req_tree = proto_tree_add_subtree(tree, tvb, offset-2, tlv_len+2,
ett_cfdp_filestore_req, NULL, "Filestore Request TLV");
proto_tree_add_uint(cfdp_filestore_req_tree, hf_cfdp_tlv_len, tvb, offset-1, 1, tlv_len);
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_filestore_req_tree, hf_cfdp_action_code, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_filestore_req_tree, hf_cfdp_spare_four, tvb, offset, 1, aux_byte);
offset += 1;
aux_byte = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cfdp_filestore_req_tree, hf_cfdp_first_file_name, tvb, offset, aux_byte, ENC_ASCII|ENC_NA);
offset += aux_byte;
aux_byte = tvb_get_guint8(tvb, offset);
offset += 1;
if(aux_byte > 0){
proto_tree_add_item(cfdp_filestore_req_tree, hf_cfdp_second_file_name, tvb, offset, aux_byte, ENC_ASCII|ENC_NA);
offset += aux_byte;
}
}
return offset;
}
static guint32 dissect_cfdp_filestore_resp_tlv(tvbuff_t *tvb, proto_tree *tree, guint32 ext_offset){
guint8 tlv_len;
guint32 offset = ext_offset;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
if(tlv_len > 0){
proto_tree *cfdp_filestore_resp_tree;
guint8 aux_byte;
cfdp_filestore_resp_tree = proto_tree_add_subtree(tree, tvb, offset-2, tlv_len+2,
ett_cfdp_filestore_resp, NULL, "Filestore Response TLV");
proto_tree_add_uint(cfdp_filestore_resp_tree, hf_cfdp_tlv_len, tvb, offset-1, 1, tlv_len);
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_filestore_resp_tree, hf_cfdp_action_code, tvb, offset, 1, aux_byte);
switch((aux_byte & 0xF0) >> 4){
case 0:
proto_tree_add_uint(cfdp_filestore_resp_tree, hf_cfdp_status_code_1, tvb, offset, 1, aux_byte);
break;
case 1:
proto_tree_add_uint(cfdp_filestore_resp_tree, hf_cfdp_status_code_2, tvb, offset, 1, aux_byte);
break;
case 2:
proto_tree_add_uint(cfdp_filestore_resp_tree, hf_cfdp_status_code_3, tvb, offset, 1, aux_byte);
break;
case 3:
proto_tree_add_uint(cfdp_filestore_resp_tree, hf_cfdp_status_code_4, tvb, offset, 1, aux_byte);
break;
case 4:
proto_tree_add_uint(cfdp_filestore_resp_tree, hf_cfdp_status_code_5, tvb, offset, 1, aux_byte);
break;
case 5:
proto_tree_add_uint(cfdp_filestore_resp_tree, hf_cfdp_status_code_6, tvb, offset, 1, aux_byte);
break;
case 6:
proto_tree_add_uint(cfdp_filestore_resp_tree, hf_cfdp_status_code_7, tvb, offset, 1, aux_byte);
break;
case 7: case 8:
proto_tree_add_uint(cfdp_filestore_resp_tree, hf_cfdp_status_code_8, tvb, offset, 1, aux_byte);
break;
default:
break;
}
offset += 1;
aux_byte = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cfdp_filestore_resp_tree, hf_cfdp_first_file_name, tvb, offset, aux_byte, ENC_ASCII|ENC_NA);
offset += aux_byte;
aux_byte = tvb_get_guint8(tvb, offset);
offset += 1;
if(aux_byte > 0){
proto_tree_add_item(cfdp_filestore_resp_tree, hf_cfdp_second_file_name, tvb, offset, aux_byte, ENC_ASCII|ENC_NA);
offset += aux_byte;
}
aux_byte = tvb_get_guint8(tvb, offset);
offset += 1;
if(aux_byte > 0){
proto_tree_add_item(cfdp_filestore_resp_tree, hf_cfdp_filestore_message, tvb, offset, tlv_len, ENC_NA);
offset += aux_byte;
}
}
return offset;
}
static guint32 dissect_cfdp_fault_location_tlv(tvbuff_t *tvb, proto_tree *tree, guint32 ext_offset){
guint8 tlv_len;
guint32 offset = ext_offset;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
if(tlv_len > 0){
proto_tree *cfdp_fault_location_tree;
cfdp_fault_location_tree = proto_tree_add_subtree(tree, tvb, offset-2, tlv_len+2,
ett_cfdp_fault_location, NULL, "Fault location TLV");
proto_tree_add_uint(cfdp_fault_location_tree, hf_cfdp_tlv_len, tvb, offset-1, 1, tlv_len);
proto_tree_add_item(cfdp_fault_location_tree, hf_cfdp_entity, tvb, offset, tlv_len, ENC_NA);
offset += tlv_len;
}
return offset;
}
static guint32 dissect_cfdp_msg_to_user_tlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 ext_offset){
guint8 aux_byte, tlv_type, tlv_len;
proto_tree *cfdp_msg_to_user_tree;
guint32 offset = ext_offset;
guint32 msg_to_user_id;
int len_ent_id;
int len_tseq_num;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
cfdp_msg_to_user_tree = proto_tree_add_subtree(tree, tvb, offset-2, tlv_len+2,
ett_cfdp_filestore_resp, NULL, "Message To User TLV");
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_tlv_len, tvb, offset-1, 1, tlv_len);
msg_to_user_id = tvb_get_ntohl(tvb, offset);
if(msg_to_user_id == CFDP_MSG_TO_USER){
offset += 4;
tlv_type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_proxy_msg_type, tvb, offset, 1, tlv_type);
offset += 1;
switch(tlv_type){
case PROXY_PUT_REQ:
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
dissect_cfdp_dst_entity_id(tvb, pinfo, cfdp_msg_to_user_tree, offset, tlv_len);
offset += tlv_len;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cfdp_msg_to_user_tree, hf_cfdp_src_file_name, tvb, offset, tlv_len, ENC_ASCII|ENC_NA);
offset += tlv_len;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cfdp_msg_to_user_tree, hf_cfdp_dst_file_name, tvb, offset, tlv_len, ENC_ASCII|ENC_NA);
offset += tlv_len;
break;
case PROXY_MSG_TO_USER:
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cfdp_msg_to_user_tree, hf_cfdp_message_to_user, tvb, offset, tlv_len, ENC_NA);
break;
case PROXY_FILESTORE_REQ:
offset = dissect_cfdp_filestore_req_tlv(tvb, cfdp_msg_to_user_tree, offset);
break;
case PROXY_FAULT_HDL_OVERR:
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_condition_code, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_handler_code, tvb, offset, 1, aux_byte);
offset += 1;
break;
case PROXY_TRANS_MODE:
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_spare_seven_2, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_trans_mode_msg, tvb, offset, 1, aux_byte);
offset += 1;
break;
case PROXY_FLOW_LABEL:
proto_tree_add_item(cfdp_msg_to_user_tree, hf_cfdp_flow_label, tvb, offset, tlv_len, ENC_NA);
break;
case PROXY_SEGMENT_CONTROL:
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_spare_seven_2, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_proxy_segment_control, tvb, offset, 1, aux_byte);
offset += 1;
break;
case PROXY_PUT_RESP:
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_condition_code, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_spare_one, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_condition_code, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_proxy_delivery_code, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_file_stat, tvb, offset, 1, aux_byte);
offset += 1;
break;
case PROXY_FILESTORE_RESP:
offset = dissect_cfdp_filestore_req_tlv(tvb, cfdp_msg_to_user_tree, offset);
break;
case PROXY_PUT_CANCEL:
break;
case ORIG_TRANS_ID:
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_res2, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_entid_length, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_res3, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_transeqnum_length, tvb, offset, 1, aux_byte);
offset += 1;
len_ent_id = ((aux_byte & HDR_LEN_ENT_ID) >> 4) + 1;
dissect_cfdp_src_entity_id(tvb, pinfo, cfdp_msg_to_user_tree, offset, len_ent_id);
offset += len_ent_id;
len_tseq_num = (aux_byte & HDR_LEN_TSEQ_NUM) +1;
dissect_cfdp_tseq_num(tvb, pinfo, cfdp_msg_to_user_tree, offset, len_tseq_num);
offset += len_tseq_num;
break;
case DIRECTORY_LIST_REQ:
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cfdp_msg_to_user_tree, hf_cfdp_directory_name, tvb, offset, tlv_len, ENC_ASCII|ENC_NA);
offset += tlv_len;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cfdp_msg_to_user_tree, hf_cfdp_directory_file_name, tvb, offset, tlv_len, ENC_ASCII|ENC_NA);
offset += tlv_len;
break;
case DIRECTORY_LIST_RESP:
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_listing_resp_code, tvb, offset, 1, aux_byte);
offset += 1;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cfdp_msg_to_user_tree, hf_cfdp_directory_name, tvb, offset, tlv_len, ENC_ASCII|ENC_NA);
offset += tlv_len;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cfdp_msg_to_user_tree, hf_cfdp_directory_file_name, tvb, offset, tlv_len, ENC_ASCII|ENC_NA);
offset += tlv_len;
break;
case REMOTE_STAT_REP_REQ:
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_res2, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_entid_length, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_res3, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_transeqnum_length, tvb, offset, 1, aux_byte);
offset += 1;
len_ent_id = ((aux_byte & HDR_LEN_ENT_ID) >> 4) + 1;
dissect_cfdp_src_entity_id(tvb, pinfo, cfdp_msg_to_user_tree, offset, len_ent_id);
offset += len_ent_id;
len_tseq_num = (aux_byte & HDR_LEN_TSEQ_NUM) +1;
dissect_cfdp_tseq_num(tvb, pinfo, cfdp_msg_to_user_tree, offset, len_tseq_num);
offset += len_tseq_num;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(cfdp_msg_to_user_tree, hf_cfdp_report_file_name, tvb, offset, tlv_len, ENC_ASCII|ENC_NA);
offset += tlv_len;
break;
case REMOTE_STAT_REP_RESP:
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_trans_stat, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_spare_five, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_rep_resp_code, tvb, offset, 1, aux_byte);
offset += 1;
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_spare_one_2, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_entid_length, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_spare_one, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_transeqnum_length, tvb, offset, 1, aux_byte);
offset += 1;
len_ent_id = ((aux_byte & HDR_LEN_ENT_ID) >> 4) + 1;
dissect_cfdp_src_entity_id(tvb, pinfo, cfdp_msg_to_user_tree, offset, len_ent_id);
offset += len_ent_id;
len_tseq_num = (aux_byte & HDR_LEN_TSEQ_NUM) +1;
dissect_cfdp_tseq_num(tvb, pinfo, cfdp_msg_to_user_tree, offset, len_tseq_num);
offset += len_tseq_num;
break;
case REMOTE_SUSPEND_REQ:
case REMOTE_RESUME_REQ:
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_spare_one_2, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_entid_length, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_spare_one, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_transeqnum_length, tvb, offset, 1, aux_byte);
offset += 1;
len_ent_id = ((aux_byte & HDR_LEN_ENT_ID) >> 4) + 1;
dissect_cfdp_src_entity_id(tvb, pinfo, cfdp_msg_to_user_tree, offset, len_ent_id);
offset += len_ent_id;
len_tseq_num = (aux_byte & HDR_LEN_TSEQ_NUM) +1;
dissect_cfdp_tseq_num(tvb, pinfo, cfdp_msg_to_user_tree, offset, len_tseq_num);
offset += len_tseq_num;
break;
case REMOTE_SUSPEND_RESP:
case REMOTE_RESUME_RESP:
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_suspension_ind, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_trans_stat_2, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_spare_five, tvb, offset, 1, aux_byte);
offset += 1;
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_spare_one_2, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_entid_length, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_spare_one, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_msg_to_user_tree, hf_cfdp_transeqnum_length, tvb, offset, 1, aux_byte);
offset += 1;
len_ent_id = ((aux_byte & HDR_LEN_ENT_ID) >> 4) + 1;
dissect_cfdp_src_entity_id(tvb, pinfo, cfdp_msg_to_user_tree, offset, len_ent_id);
offset += len_ent_id;
len_tseq_num = (aux_byte & HDR_LEN_TSEQ_NUM) +1;
dissect_cfdp_tseq_num(tvb, pinfo, cfdp_msg_to_user_tree, offset, len_tseq_num);
offset += len_tseq_num;
break;
default:
break;
}
}else{
proto_tree_add_item(cfdp_msg_to_user_tree, hf_cfdp_message_to_user, tvb, offset, tlv_len, ENC_NA);
offset += tlv_len;
}
return offset;
}
static guint32 dissect_cfdp_fault_handler_overr_tlv(tvbuff_t *tvb, proto_tree *tree, guint32 ext_offset){
guint8 aux_byte, tlv_len;
proto_tree *cfdp_fault_hdl_overr_tree;
guint32 offset = ext_offset;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
cfdp_fault_hdl_overr_tree = proto_tree_add_subtree(tree, tvb, offset-2, tlv_len+2,
ett_cfdp_fault_hdl_overr, NULL, "Fault Handler Override TLV");
proto_tree_add_uint(cfdp_fault_hdl_overr_tree, hf_cfdp_tlv_len, tvb, offset-1, 1, tlv_len);
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_fault_hdl_overr_tree, hf_cfdp_condition_code, tvb, offset, 1, aux_byte);
proto_tree_add_uint(cfdp_fault_hdl_overr_tree, hf_cfdp_handler_code, tvb, offset, 1, aux_byte);
offset += 1;
return offset;
}
static guint32 dissect_cfdp_flow_label_tlv(tvbuff_t *tvb, proto_tree *tree, guint32 ext_offset){
guint8 tlv_len;
proto_tree *cfdp_flow_label_tree;
guint32 offset = ext_offset;
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
cfdp_flow_label_tree = proto_tree_add_subtree(tree, tvb, offset-2, tlv_len+2,
ett_cfdp_flow_label, NULL, "Flow Label TLV");
proto_tree_add_item(cfdp_flow_label_tree, hf_cfdp_flow_label, tvb, offset, tlv_len, ENC_NA);
return offset;
}
static guint32 dissect_cfdp_eof_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 ext_offset, guint ext_packet_len){
guint8 aux_byte, tlv_type, tlv_len;
proto_tree *cfdp_fault_location_tree;
guint32 offset = ext_offset;
guint cfdp_packet_data_length = ext_packet_len;
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_cfdp_condition_code, tvb, offset, 1, aux_byte);
proto_tree_add_uint(tree, hf_cfdp_spare_four, tvb, offset, 1, aux_byte);
offset += 1;
col_add_fstr(pinfo->cinfo, COL_INFO, "EOF (%s)", val_to_str_const((aux_byte & 0xF0) >> 4, cfdp_condition_codes, "Reserved Code"));
proto_tree_add_checksum(tree, tvb, offset, hf_cfdp_file_checksum, -1, NULL, pinfo, 0, ENC_BIG_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
offset += 4;
proto_tree_add_item(tree, hf_cfdp_file_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if(offset < cfdp_packet_data_length){
tlv_type = tvb_get_guint8(tvb, offset);
offset += 1;
if(tlv_type == FAULT_LOCATION){
tlv_len = tvb_get_guint8(tvb, offset);
offset += 1;
cfdp_fault_location_tree = proto_tree_add_subtree(tree, tvb, offset-2, tlv_len+2,
ett_cfdp_fault_location, NULL, "Fault location TLV");
proto_tree_add_item(cfdp_fault_location_tree, hf_cfdp_entity, tvb, offset, tlv_len, ENC_NA);
offset += tlv_len;
}
}
return offset;
}
static guint32 dissect_cfdp_finished_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 ext_offset, guint ext_packet_len){
guint32 offset = ext_offset;
guint8 aux_byte, tlv_type;
guint cfdp_packet_data_length = ext_packet_len;
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_cfdp_condition_code, tvb, offset, 1, aux_byte);
proto_tree_add_uint(tree, hf_cfdp_end_system_stat, tvb, offset, 1, aux_byte);
proto_tree_add_uint(tree, hf_cfdp_delivery_code, tvb, offset, 1, aux_byte);
proto_tree_add_uint(tree, hf_cfdp_file_stat, tvb, offset, 1, aux_byte);
offset += 1;
col_add_fstr(pinfo->cinfo, COL_INFO, "Finished PDU (%s)", val_to_str_const((aux_byte & 0xF0) >> 4, cfdp_condition_codes, "Reserved Code"));
while(offset < cfdp_packet_data_length){
tlv_type = tvb_get_guint8(tvb, offset);
offset += 1;
switch(tlv_type){
case FILESTORE_RESP:
offset = dissect_cfdp_filestore_resp_tlv(tvb, tree, offset);
break;
case FAULT_LOCATION:
offset = dissect_cfdp_fault_location_tlv(tvb, tree, offset);
break;
default:
break;
}
}
return offset;
}
static guint32 dissect_cfdp_ack_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 ext_offset){
guint8 aux_byte;
guint32 offset = ext_offset;
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_cfdp_dir_code_ack, tvb, offset, 1, aux_byte);
proto_tree_add_uint(tree, hf_cfdp_dir_subtype_ack, tvb, offset, 1, aux_byte);
offset += 1;
col_add_fstr(pinfo->cinfo, COL_INFO, "ACK PDU (%s)", val_to_str_const((aux_byte & 0xF0) >> 4, cfdp_directive_codes, "Unknown PDU"));
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_cfdp_condition_code, tvb, offset, 1, aux_byte);
proto_tree_add_uint(tree, hf_cfdp_spare_two, tvb, offset, 1, aux_byte);
proto_tree_add_uint(tree, hf_cfdp_trans_stat_ack, tvb, offset, 1, aux_byte);
offset += 1;
return offset;
}
static guint32 dissect_cfdp_metadata_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 ext_offset, guint ext_packet_len){
guint8 aux_byte, tlv_type;
guint cfdp_packet_data_length = ext_packet_len;
guint32 offset = ext_offset;
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_cfdp_segment_control, tvb, offset, 1, aux_byte);
proto_tree_add_uint(tree, hf_cfdp_spare_seven, tvb, offset, 1, aux_byte);
offset += 1;
proto_tree_add_item(tree, hf_cfdp_file_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
aux_byte = tvb_get_guint8(tvb, offset);
if(aux_byte >0){
proto_tree_add_item(tree, hf_cfdp_src_file_name, tvb, offset+1, aux_byte, ENC_ASCII|ENC_NA);
offset += aux_byte+1;
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_cfdp_dst_file_name, tvb, offset+1, aux_byte, ENC_ASCII|ENC_NA);
offset += aux_byte+1;
}
while(offset < cfdp_packet_data_length){
tlv_type = tvb_get_guint8(tvb, offset);
offset += 1;
switch(tlv_type){
case FILESTORE_REQ:
offset = dissect_cfdp_filestore_req_tlv(tvb, tree, offset);
break;
case MSG_TO_USER:
offset = dissect_cfdp_msg_to_user_tlv(tvb, pinfo, tree, offset);
break;
case FAULT_HDL_OVERR:
offset = dissect_cfdp_fault_handler_overr_tlv(tvb, tree, offset);
break;
case FLOW_LABEL:
offset = dissect_cfdp_flow_label_tlv(tvb, tree, offset);
break;
default:
break;
}
}
return offset;
}
static guint32 dissect_cfdp_nak_pdu(tvbuff_t *tvb, proto_tree *tree, guint32 ext_offset, guint ext_packet_len){
guint32 offset = ext_offset;
guint cfdp_packet_data_length = ext_packet_len;
proto_tree_add_item(tree, hf_cfdp_nak_st_scope, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cfdp_nak_sp_scope, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cfdp_segment_requests, tvb, offset, cfdp_packet_data_length-9, ENC_NA);
offset += cfdp_packet_data_length-9;
return offset;
}
static guint32 dissect_cfdp_prompt_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 ext_offset){
guint8 aux_byte;
guint32 offset = ext_offset;
aux_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_cfdp_response_req, tvb, offset, 1, aux_byte);
proto_tree_add_uint(tree, hf_cfdp_spare_seven, tvb, offset, 1, aux_byte);
offset += 1;
col_add_fstr(pinfo->cinfo, COL_INFO, "Prompt PDU (%s)", val_to_str_const((aux_byte & 0x80) >> 7, cfdp_response_req, "Unknown"));
return offset;
}
static guint32 dissect_cfdp_keep_alive_pdu(tvbuff_t *tvb, proto_tree *tree, guint32 ext_offset){
guint32 offset = ext_offset;
proto_tree_add_item(tree, hf_cfdp_progress, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_cfdp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_item *cfdp_packet;
proto_item *cfdp_tree;
proto_item *cfdp_header;
proto_tree *cfdp_header_tree;
gint cfdp_packet_length;
gint cfdp_packet_reported_length;
gint cfdp_packet_header_length;
gint cfdp_packet_data_length;
gint length;
guint8 first_byte;
guint8 second_byte;
gint len_ent_id;
gint len_tseq_num;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CFDP");
col_clear(pinfo->cinfo, COL_INFO);
cfdp_packet_reported_length = tvb_reported_length_remaining(tvb, 0);
cfdp_packet_header_length = (tvb_get_guint8(tvb, 3) & HDR_LEN_TSEQ_NUM) + 1 + 2*(((tvb_get_guint8(tvb, 3) & HDR_LEN_ENT_ID) >>4) +1) + CFDP_HEADER_FIXED_FIELDS_LEN;
cfdp_packet_length = tvb_get_ntohs(tvb, 1) + cfdp_packet_header_length;
if(cfdp_packet_length > cfdp_packet_reported_length)
length = cfdp_packet_reported_length;
else if(cfdp_packet_length < cfdp_packet_header_length + 2)
length = cfdp_packet_header_length + 2;
else
length = cfdp_packet_length;
cfdp_packet = proto_tree_add_item(tree, proto_cfdp, tvb, 0, length, ENC_NA);
cfdp_tree = proto_item_add_subtree(cfdp_packet, ett_cfdp);
cfdp_header_tree = proto_tree_add_subtree(cfdp_tree, tvb, offset, cfdp_packet_header_length,
ett_cfdp_header, &cfdp_header, "CFDP Header");
first_byte = tvb_get_guint8(tvb, offset);
cfdp_packet_data_length = tvb_get_ntohs(tvb, 1)-2*((first_byte & HDR_CRCF) >>1);
proto_tree_add_uint(cfdp_header_tree, hf_cfdp_version, tvb, offset, 1, first_byte);
proto_tree_add_uint(cfdp_header_tree, hf_cfdp_pdu_type, tvb, offset, 1, first_byte);
proto_tree_add_uint(cfdp_header_tree, hf_cfdp_direction, tvb, offset, 1, first_byte);
proto_tree_add_uint(cfdp_header_tree, hf_cfdp_trans_mode, tvb, offset, 1, first_byte);
proto_tree_add_uint(cfdp_header_tree, hf_cfdp_crc_flag, tvb, offset, 1, first_byte);
proto_tree_add_uint(cfdp_header_tree, hf_cfdp_res1, tvb, offset, 1, first_byte);
offset += 1;
proto_tree_add_item(cfdp_header_tree, hf_cfdp_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
second_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_header_tree, hf_cfdp_res2, tvb, offset, 1, second_byte);
proto_tree_add_uint(cfdp_header_tree, hf_cfdp_entid_length, tvb, offset, 1, second_byte);
proto_tree_add_uint(cfdp_header_tree, hf_cfdp_res3, tvb, offset, 1, second_byte);
proto_tree_add_uint(cfdp_header_tree, hf_cfdp_transeqnum_length, tvb, offset, 1, second_byte);
offset += 1;
len_ent_id = ((second_byte & HDR_LEN_ENT_ID) >> 4) + 1;
dissect_cfdp_src_entity_id(tvb, pinfo, cfdp_header_tree, offset, len_ent_id);
offset += len_ent_id;
len_tseq_num = (second_byte & HDR_LEN_TSEQ_NUM) +1;
dissect_cfdp_tseq_num(tvb, pinfo, cfdp_header_tree, offset, len_tseq_num);
offset += len_tseq_num;
dissect_cfdp_dst_entity_id(tvb, pinfo, cfdp_header_tree, offset, len_ent_id);
offset += len_ent_id;
proto_item_set_end(cfdp_header, tvb, offset);
if(!(first_byte & HDR_TYPE_CFDP))
{
proto_item *cfdp_file_directive_header;
proto_tree *cfdp_file_directive_header_tree;
guint8 directive_code;
cfdp_file_directive_header_tree = proto_tree_add_subtree(cfdp_tree, tvb, offset, cfdp_packet_data_length,
ett_cfdp_file_directive_header, &cfdp_file_directive_header, "CFDP File Directive");
directive_code = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(cfdp_file_directive_header_tree, hf_cfdp_file_directive_type, tvb, offset, 1, directive_code);
offset += 1;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s PDU", val_to_str(directive_code, cfdp_directive_codes, "Reserved (%d)"));
switch(directive_code)
{
case EOF_PDU:
offset = dissect_cfdp_eof_pdu(tvb, pinfo, cfdp_file_directive_header_tree, offset, cfdp_packet_data_length);
break;
case FINISHED_PDU:
offset = dissect_cfdp_finished_pdu(tvb, pinfo, cfdp_file_directive_header_tree, offset, cfdp_packet_data_length);
break;
case ACK_PDU:
offset = dissect_cfdp_ack_pdu(tvb, pinfo, cfdp_file_directive_header_tree, offset);
break;
case METADATA_PDU:
offset = dissect_cfdp_metadata_pdu(tvb, pinfo, cfdp_file_directive_header_tree, offset, cfdp_packet_data_length);
break;
case NAK_PDU:
offset = dissect_cfdp_nak_pdu(tvb, cfdp_file_directive_header_tree, offset, cfdp_packet_data_length);
break;
case PROMPT_PDU:
offset = dissect_cfdp_prompt_pdu(tvb, pinfo, cfdp_file_directive_header_tree, offset);
break;
case KEEP_ALIVE_PDU:
offset = dissect_cfdp_keep_alive_pdu(tvb, cfdp_file_directive_header_tree, offset);
break;
default:
break;
}
proto_item_set_end(cfdp_file_directive_header, tvb, offset);
}else{
proto_tree *cfdp_file_data_header_tree;
col_add_fstr(pinfo->cinfo, COL_INFO, "File Data PDU");
cfdp_file_data_header_tree = proto_tree_add_subtree(cfdp_tree, tvb, offset, cfdp_packet_data_length,
ett_cfdp_file_data_header, NULL, "CFDP File Data");
proto_tree_add_item(cfdp_file_data_header_tree, hf_cfdp_file_data_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(cfdp_file_data_header_tree, hf_cfdp_user_data, tvb, offset, cfdp_packet_data_length-4, ENC_NA);
offset += cfdp_packet_data_length-4;
}
if(first_byte & HDR_CRCF){
proto_item *cfdp_crc;
proto_tree *cfdp_crc_tree;
cfdp_crc_tree = proto_tree_add_subtree(cfdp_tree, tvb, offset, 2, ett_cfdp_crc, &cfdp_crc, "CRC");
proto_tree_add_item(cfdp_crc_tree, hf_cfdp_crc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_item_set_end(cfdp_crc, tvb, offset);
}
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_cfdp(void)
{
static hf_register_info hf[] = {
{ &hf_cfdp_version,
{ "Version", "cfdp.version",
FT_UINT8, BASE_DEC, NULL, HDR_VERSION_CFDP,
NULL, HFILL }
},
{ &hf_cfdp_pdu_type,
{ "PDU Type", "cfdp.pdu_type",
FT_UINT8, BASE_DEC, VALS(cfdp_pdu_type), HDR_TYPE_CFDP,
NULL, HFILL }
},
{ &hf_cfdp_direction,
{ "Direction", "cfdp.direction",
FT_UINT8, BASE_DEC, VALS(cfdp_direction), HDR_DIR,
NULL, HFILL }
},
{ &hf_cfdp_trans_mode,
{ "Trans. Mode", "cfdp.trans_mode",
FT_UINT8, BASE_DEC, VALS(cfdp_trans_mode), HDR_TMODE,
NULL, HFILL }
},
{ &hf_cfdp_crc_flag,
{ "CRC Flag", "cfdp.crc_flag",
FT_UINT8, BASE_DEC, VALS(cfdp_crc_flag), HDR_CRCF,
NULL, HFILL }
},
{ &hf_cfdp_res1,
{ "Bit reserved 1", "cfdp.res1",
FT_UINT8, BASE_DEC, NULL, HDR_RES1,
NULL, HFILL }
},
{ &hf_cfdp_data_length,
{ "PDU Data length", "cfdp.data_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cfdp_res2,
{ "Bit reserved 2", "cfdp.res2",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_cfdp_entid_length,
{ "Length of entity IDs", "cfdp.entid_length",
FT_UINT8, BASE_DEC, NULL, 0x70,
NULL, HFILL }
},
{ &hf_cfdp_res3,
{ "Bit reserved 3", "cfdp.res3",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }
},
{ &hf_cfdp_transeqnum_length,
{ "Length of Transaction sequence number", "cfdp.transeqnum_length",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_cfdp_srcid,
{ "Source entity ID", "cfdp.srcid",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cfdp_transeqnum,
{ "Transaction sequence number", "cfdp.transeqnum",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cfdp_dstid,
{ "Destination entity ID", "cfdp.dstid",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cfdp_file_directive_type,
{ "File Directive type", "cfdp.fdtype",
FT_UINT8, BASE_DEC, VALS(cfdp_file_directive_type), 0x0,
NULL, HFILL }
},
{ &hf_cfdp_file_data_offset,
{ "Offset", "cfdp.offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cfdp_progress,
{ "Progress", "cfdp.progress",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cfdp_dir_code_ack,
{ "PDU acknowledged", "cfdp.dir_code_ack",
FT_UINT8, BASE_DEC, VALS(cfdp_file_directive_type), 0xf0,
NULL, HFILL }
},
{ &hf_cfdp_dir_subtype_ack,
{ "Directive subtype code", "cfdp.dir_subtype_ack",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_cfdp_condition_code,
{ "Condition Code", "cfdp.condition_code",
FT_UINT8, BASE_DEC, VALS(cfdp_condition_codes), 0xf0,
NULL, HFILL }
},
{ &hf_cfdp_spare_one,
{ "Spare", "cfdp.spare_one",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }
},
{ &hf_cfdp_spare_one_2,
{ "Spare", "cfdp.spare_one_2",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_cfdp_spare_two,
{ "Spare", "cfdp.spare_two",
FT_UINT8, BASE_DEC, NULL, 0x0c,
NULL, HFILL }
},
{ &hf_cfdp_spare_four,
{ "Spare", "cfdp.spare_four",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_cfdp_spare_five,
{ "Spare", "cfdp.spare_five",
FT_UINT8, BASE_DEC, NULL, 0x3E,
NULL, HFILL }
},
{ &hf_cfdp_spare_seven,
{ "Spare", "cfdp.spare_seven",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_cfdp_spare_seven_2,
{ "Spare", "cfdp.spare_seven_2",
FT_UINT8, BASE_DEC, NULL, 0xfe,
NULL, HFILL }
},
{ &hf_cfdp_trans_stat_ack,
{ "Transaction status", "cfdp.trans_stat_ack",
FT_UINT8, BASE_DEC, VALS(cfdp_trans_stat_ack), 0x03,
NULL, HFILL }
},
{ &hf_cfdp_trans_stat,
{ "Transaction status", "cfdp.trans_stat",
FT_UINT8, BASE_DEC, VALS(cfdp_trans_stat_ack), 0xC0,
NULL, HFILL }
},
{ &hf_cfdp_trans_stat_2,
{ "Transaction status", "cfdp.trans_stat_2",
FT_UINT8, BASE_DEC, VALS(cfdp_trans_stat_ack), 0x60,
NULL, HFILL }
},
{ &hf_cfdp_file_checksum,
{ "Checksum", "cfdp.checksum",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cfdp_file_size,
{ "File size", "cfdp.file_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cfdp_end_system_stat,
{ "End system status", "cfdp.end_system_stat",
FT_UINT8, BASE_DEC, VALS(cfdp_end_system_stat), 0x08,
NULL, HFILL }
},
{ &hf_cfdp_delivery_code,
{ "Delivery code", "cfdp.delivery_code",
FT_UINT8, BASE_DEC, VALS(cfdp_delivery_code), 0x04,
NULL, HFILL }
},
{ &hf_cfdp_file_stat,
{ "File status", "cfdp.file_status",
FT_UINT8, BASE_DEC, VALS(cfdp_file_stat), 0x03,
NULL, HFILL }
},
{ &hf_cfdp_segment_control,
{ "Segmentation control", "cfdp.segment_control",
FT_UINT8, BASE_DEC, VALS(cfdp_segment_control), 0x80,
NULL, HFILL }
},
{ &hf_cfdp_tlv_len,
{ "Length", "cfdp.tlv_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cfdp_src_file_name,
{"Source file name", "cfdp.src_file_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cfdp_dst_file_name,
{"Destination file name", "cfdp.dst_file_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cfdp_first_file_name,
{"First file name", "cfdp.first_file_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cfdp_second_file_name,
{"Second file name", "cfdp.second_file_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cfdp_nak_st_scope,
{"Start of scope", "cfdp.nak_st_scope", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cfdp_nak_sp_scope,
{"End of scope", "cfdp.nak_sp_scope", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cfdp_crc,
{"CRC", "cfdp.crc", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cfdp_action_code,
{"Action code", "cfdp.action_code", FT_UINT8, BASE_DEC, VALS(cfdp_action_code), 0xF0,
NULL, HFILL}
},
{ &hf_cfdp_status_code_1,
{"Status code", "cfdp.status_code_1", FT_UINT8, BASE_DEC, VALS(cfdp_status_code_1), 0x0F,
NULL, HFILL}
},
{ &hf_cfdp_status_code_2,
{"Status code", "cfdp.status_code_2", FT_UINT8, BASE_DEC, VALS(cfdp_status_code_2), 0x0F,
NULL, HFILL}
},
{ &hf_cfdp_status_code_3,
{"Status code", "cfdp.status_code_3", FT_UINT8, BASE_DEC, VALS(cfdp_status_code_3), 0x0F,
NULL, HFILL}
},
{ &hf_cfdp_status_code_4,
{"Status code", "cfdp.status_code_4", FT_UINT8, BASE_DEC, VALS(cfdp_status_code_4), 0x0F,
NULL, HFILL}
},
{ &hf_cfdp_status_code_5,
{"Status code", "cfdp.status_code_5", FT_UINT8, BASE_DEC, VALS(cfdp_status_code_5), 0x0F,
NULL, HFILL}
},
{ &hf_cfdp_status_code_6,
{"Status code", "cfdp.status_code_6", FT_UINT8, BASE_DEC, VALS(cfdp_status_code_6), 0x0F,
NULL, HFILL}
},
{ &hf_cfdp_status_code_7,
{"Status code", "cfdp.status_code_7", FT_UINT8, BASE_DEC, VALS(cfdp_status_code_7), 0x0F,
NULL, HFILL}
},
{ &hf_cfdp_status_code_8,
{"Status code", "cfdp.status_code_8", FT_UINT8, BASE_DEC, VALS(cfdp_status_code_8), 0x0F,
NULL, HFILL}
},
{ &hf_cfdp_handler_code,
{ "Handler Code", "cfdp.handler_code",
FT_UINT8, BASE_DEC, VALS(cfdp_handler_codes), 0x0F,
NULL, HFILL }
},
{ &hf_cfdp_trans_mode_msg,
{ "Trans. Mode", "cfdp.trans_mode_msg",
FT_UINT8, BASE_DEC, VALS(cfdp_trans_mode), 0x01,
NULL, HFILL }
},
{ &hf_cfdp_proxy_msg_type,
{ "Proxy Message Type", "cfdp.proxy_msg_type",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &cfdp_proxy_msg_type_ext, 0x0,
NULL, HFILL }
},
{ &hf_cfdp_proxy_segment_control,
{ "Segmentation control", "cfdp.proxy_segment_control",
FT_UINT8, BASE_DEC, VALS(cfdp_segment_control), 0x01,
NULL, HFILL }
},
{ &hf_cfdp_proxy_delivery_code,
{ "Delivery code", "cfdp.proxy_delivery_code",
FT_UINT8, BASE_DEC, VALS(cfdp_delivery_code), 0x04,
NULL, HFILL }
},
{ &hf_cfdp_response_req,
{ "Response required", "cfdp.response_req",
FT_UINT8, BASE_DEC, VALS(cfdp_response_req), 0x80,
NULL, HFILL }
},
{ &hf_cfdp_directory_name,
{"Directory Name", "cfdp.directory_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cfdp_directory_file_name,
{"Directory File Name", "cfdp.directory_file_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cfdp_listing_resp_code,
{"Listing Response Code", "cfdp.listing_resp_code",
FT_UINT8, BASE_DEC, VALS(cfdp_listing_resp_code), 0x80,
NULL, HFILL}
},
{ &hf_cfdp_report_file_name,
{"Report File Name", "cfdp.report_file_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cfdp_rep_resp_code,
{"Report Response Code", "cfdp.rep_resp_code",
FT_UINT8, BASE_DEC, VALS(cfdp_rep_resp_code), 0x01,
NULL, HFILL}
},
{ &hf_cfdp_suspension_ind,
{"Suspension indicator", "cfdp.suspension_ind",
FT_UINT8, BASE_DEC, VALS(cfdp_suspension_ind), 0x80,
NULL, HFILL}
},
{ &hf_cfdp_filestore_message, { "Filestore Message", "cfdp.filestore_message", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_cfdp_entity, { "Entity", "cfdp.entity", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_cfdp_message_to_user, { "Message to User", "cfdp.message_to_user", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_cfdp_flow_label, { "Flow label", "cfdp.flow_label", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_cfdp_segment_requests, { "Segment requests", "cfdp.segment_requests", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_cfdp_user_data, { "User Data", "cfdp.user_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_cfdp,
&ett_cfdp_header,
&ett_cfdp_file_directive_header,
&ett_cfdp_file_data_header,
&ett_cfdp_fault_location,
&ett_cfdp_crc,
&ett_cfdp_filestore_req,
&ett_cfdp_filestore_resp,
&ett_cfdp_msg_to_user,
&ett_cfdp_fault_hdl_overr,
&ett_cfdp_flow_label
};
static ei_register_info ei[] = {
{ &ei_cfdp_bad_length, { "cfdp.bad_length", PI_MALFORMED, PI_ERROR, "Bad length field", EXPFILL }},
};
expert_module_t* expert_cfdp;
proto_cfdp = proto_register_protocol("CFDP", "CFDP", "cfdp");
proto_register_field_array(proto_cfdp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_cfdp = expert_register_protocol(proto_cfdp);
expert_register_field_array(expert_cfdp, ei, array_length(ei));
cfdp_handle = register_dissector("cfdp", dissect_cfdp, proto_cfdp);
}
void
proto_reg_handoff_cfdp(void)
{
dissector_add_uint("ccsds.apid", CFDP_APID, cfdp_handle);
dissector_add_for_decode_as_with_preference("udp.port", cfdp_handle);
}
