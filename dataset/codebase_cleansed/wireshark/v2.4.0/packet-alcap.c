static const gchar* dissect_fields_unknown(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
proto_item* pi = proto_tree_add_item(tree,hf_alcap_unknown,tvb,offset,len,ENC_NA);
expert_add_info(pinfo, pi, &ei_alcap_undecoded);
return NULL;
}
static const gchar* dissect_fields_cau(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info) {
guint coding;
const gchar* ret_str;
proto_item* pi;
if (len < 2) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
msg_info->release_cause = tvb_get_guint8(tvb, offset+1) & 0x7f;
coding = tvb_get_guint8(tvb, offset) & 0x3;
proto_tree_add_item(tree, hf_alcap_cau_coding, tvb, offset, 1, ENC_BIG_ENDIAN);
if (coding == 0) {
pi = proto_tree_add_item(tree, hf_alcap_cau_value_itu, tvb, offset+1, 1, ENC_BIG_ENDIAN);
if ( msg_info->release_cause && msg_info->release_cause != 31 )
expert_add_info(pinfo, pi, &ei_alcap_abnormal_release);
ret_str = val_to_str(msg_info->release_cause, cause_values_itu, "Unknown(%u)");
} else {
proto_tree_add_item(tree, hf_alcap_cau_value_non_itu, tvb, offset+1 , 1, ENC_BIG_ENDIAN);
ret_str = wmem_strdup_printf(wmem_packet_scope(), "%u", msg_info->release_cause);
}
if (!tree) return ret_str;
offset += 2;
if (len > 2) {
int diag_len = tvb_get_guint8(tvb,offset);
pi = proto_tree_add_item(tree,hf_alcap_cau_diag, tvb, offset,len-2,ENC_NA);
tree = proto_item_add_subtree(pi,ett_cau_diag);
proto_tree_add_item(tree, hf_alcap_cau_diag_len, tvb, offset, 1, ENC_BIG_ENDIAN);
if (diag_len) {
switch (msg_info->release_cause) {
case 97:
case 99:
case 110:
proto_tree_add_item(tree, hf_alcap_cau_diag_msg, tvb, ++offset, 1, ENC_BIG_ENDIAN);
while(diag_len >= 2) {
proto_tree_add_item(tree, hf_alcap_cau_diag_param_id, tvb, ++offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_cau_diag_field_num, tvb, ++offset, 1, ENC_BIG_ENDIAN);
diag_len -= 2;
}
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_alcap_undecoded, tvb, offset, diag_len);
break;
}
}
}
return ret_str;
}
static const gchar* dissect_fields_ceid(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info) {
if (len != 5) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item_ret_uint(tree, hf_alcap_ceid_pathid, tvb, offset, 4, ENC_BIG_ENDIAN, &msg_info->pathid);
msg_info->cid = tvb_get_guint8(tvb,offset+4);
if (msg_info->pathid == 0) {
return "Path: 0 (All Paths)";
}
proto_tree_add_item(tree,hf_alcap_ceid_cid,tvb,offset+4,1,ENC_BIG_ENDIAN);
if (msg_info->cid == 0) {
return wmem_strdup_printf(wmem_packet_scope(), "Path: %u CID: 0 (Every CID)",msg_info->pathid);
} else {
return wmem_strdup_printf(wmem_packet_scope(), "Path: %u CID: %u",msg_info->pathid,msg_info->cid);
}
}
static const gchar* dissect_fields_desea(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
e164_info_t* e164;
if (len < 2) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
e164 = wmem_new(wmem_packet_scope(), e164_info_t);
e164->e164_number_type = CALLED_PARTY_NUMBER;
e164->nature_of_address = tvb_get_guint8(tvb,offset) & 0x7f;
e164->E164_number_str = (gchar*)tvb_get_string_enc(wmem_packet_scope(),tvb,offset+1,len,ENC_ASCII|ENC_NA);
e164->E164_number_length = len-1;
dissect_e164_number(tvb, tree, offset-1, len, *e164);
return NULL;
}
static const gchar* dissect_fields_oesea(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
e164_info_t* e164;
if (len < 2) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
e164 = wmem_new(wmem_packet_scope(), e164_info_t);
e164->e164_number_type = CALLING_PARTY_NUMBER;
e164->nature_of_address = tvb_get_guint8(tvb,offset) & 0x7f;
e164->E164_number_str = (gchar*)tvb_get_string_enc(wmem_packet_scope(),tvb,offset+1,len,ENC_ASCII|ENC_NA);
e164->E164_number_length = len-1;
dissect_e164_number(tvb, tree, offset-1, len, *e164);
return NULL;
}
static const gchar* dissect_fields_dnsea(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info) {
if (len < 1) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
msg_info->dest_nsap = tvb_bytes_to_str(wmem_packet_scope(), tvb,offset,20);
proto_tree_add_item(tree, hf_alcap_dnsea, tvb, offset, 20, ENC_NA);
dissect_nsap(tvb, offset,20, tree);
return NULL;
}
static const gchar* dissect_fields_onsea(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info) {
if (len < 1) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
msg_info->orig_nsap = tvb_bytes_to_str(wmem_packet_scope(), tvb,offset,20);
proto_tree_add_item(tree, hf_alcap_onsea, tvb, offset, 20, ENC_NA);
dissect_nsap(tvb, offset,20, tree);
return NULL;
}
static const gchar* dissect_fields_alc(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 12) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree, hf_alcap_alc_max_br_fw, tvb, offset+0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_alc_max_br_bw, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_alc_avg_br_fw, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_alc_avg_br_bw, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_alc_max_sdu_fw, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_alc_max_sdu_bw, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_alc_avg_sdu_fw, tvb, offset+10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_alc_avg_sdu_bw, tvb, offset+11, 1, ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_plc(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 12) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree, hf_alcap_plc_max_br_fw, tvb, offset+0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_plc_max_br_bw, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_plc_avg_br_fw, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_plc_avg_br_bw, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_plc_max_sdu_fw, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_plc_max_sdu_bw, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_plc_avg_sdu_fw, tvb, offset+10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_plc_avg_sdu_bw, tvb, offset+11, 1, ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_osaid(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info) {
if (len != 4) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
msg_info->osaid = tvb_get_ntohl(tvb,offset);
proto_tree_add_item(tree, hf_alcap_osaid, tvb, offset, 4, ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_sugr(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info) {
if (len != 4) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
msg_info->sugr = tvb_get_ntohl(tvb,offset);
proto_tree_add_item(tree, hf_alcap_sugr, tvb, offset, 4, ENC_NA);
return NULL;
}
static const gchar* dissect_fields_suci(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 4) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree, hf_alcap_suci, tvb, offset, len, ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_ssia(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 8) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree, hf_alcap_ssia_pr_type, tvb, offset+0,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssia_pr_id, tvb, offset+2,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssia_frm, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssia_cmd, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssia_mfr2, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssia_mfr1, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssia_dtmf, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssia_cas, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssia_fax, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssia_pcm, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssia_max_len, tvb, offset+4,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssia_oui, tvb, offset+5,3,ENC_NA);
return NULL;
}
static const gchar* dissect_fields_ssim(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 3) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_ssim_frm,tvb,offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssim_mult,tvb,offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssim_max,tvb,offset+1,2,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_ssisa(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 14) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_ssisa_max_sssar_fw,tvb,offset,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssisa_max_sssar_bw,tvb,offset+3,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssisa_max_sscop_sdu_fw,tvb,offset+6,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssisa_max_sscop_sdu_bw,tvb,offset+8,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssisa_max_sscop_uu_fw,tvb,offset+10,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssisa_max_sscop_uu_bw,tvb,offset+12,2,ENC_BIG_ENDIAN);
proto_tree_add_expert_format(tree,pinfo,&ei_alcap_undecoded,tvb,offset,14,"Not yet decoded: Q.2630.1 7.4.8");
return NULL;
}
static const gchar* dissect_fields_ssisu(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 7) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_ssisu_max_sssar_fw,tvb,offset,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssisu_max_sssar_bw,tvb,offset+3,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssisu_ted,tvb,offset+6,1,ENC_BIG_ENDIAN);
proto_tree_add_expert_format(tree,pinfo,&ei_alcap_undecoded,tvb,offset,7,"Not yet decoded: Q.2630.1 7.4.9");
return NULL;
}
static const gchar* dissect_fields_none(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 0) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
return NULL;
}
static const gchar* dissect_fields_ssiae(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 8) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree, hf_alcap_ssiae_pr_type, tvb, offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_lb, tvb, offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_rc, tvb, offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_syn, tvb, offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_pr_id, tvb, offset+1,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_frm, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_cmd, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_mfr2, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_mfr1, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_dtmf, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_cas, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_fax, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_pcm, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_max_len, tvb, offset+4,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_ssiae_oui, tvb, offset+5,3,ENC_NA);
return NULL;
}
static const gchar* dissect_fields_pssiae(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 8) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree, hf_alcap_pssiae_pr_type, tvb, offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_lb, tvb, offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_rc, tvb, offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_syn, tvb, offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_pr_id, tvb, offset+1,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_frm, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_cmd, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_mfr2, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_mfr1, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_dtmf, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_cas, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_fax, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_pcm, tvb, offset+3,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_max_len, tvb, offset+4,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_pssiae_oui, tvb, offset+5,3,ENC_NA);
return NULL;
}
static const gchar* dissect_fields_ssime(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 3) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_ssime_frm,tvb,offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssime_lb,tvb,offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssime_mult,tvb,offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_ssime_max,tvb,offset+1,2,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_pssime(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 3) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_pssime_frm,tvb,offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pssime_lb,tvb,offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pssime_mult,tvb,offset,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pssime_max,tvb,offset+1,2,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_acc(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 1) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_acc_level,tvb,offset,len,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_cp(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 1) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_cp,tvb,offset,len,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_pt(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 1) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_pt,tvb,offset,len,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_hc(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 1) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_hc,tvb,offset,len,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_fbw(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 12) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_fbw_br_fw,tvb,offset,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_fbw_br_bw,tvb,offset+3,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_fbw_bucket_fw,tvb,offset+6,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_fbw_bucket_bw,tvb,offset+8,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_fbw_size_fw,tvb,offset+10,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_fbw_size_bw,tvb,offset+11,1,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_pfbw(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 12) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_pfbw_br_fw,tvb,offset,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pfbw_br_bw,tvb,offset+3,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pfbw_bucket_fw,tvb,offset+6,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pfbw_bucket_bw,tvb,offset+8,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pfbw_size_fw,tvb,offset+10,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pfbw_size_bw,tvb,offset+11,1,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_vbws(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 13) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_vbws_br_fw,tvb,offset,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbws_br_bw,tvb,offset+3,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbws_bucket_fw,tvb,offset+6,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbws_bucket_bw,tvb,offset+8,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbws_size_fw,tvb,offset+10,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbws_size_bw,tvb,offset+11,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbws_size_bw,tvb,offset+11,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbws_stt,tvb,offset+12,1,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_pvbws(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 13) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_pvbws_br_fw,tvb,offset,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbws_br_bw,tvb,offset+3,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbws_bucket_fw,tvb,offset+6,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbws_bucket_bw,tvb,offset+8,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbws_size_fw,tvb,offset+10,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbws_size_bw,tvb,offset+11,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbws_size_bw,tvb,offset+11,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbws_stt,tvb,offset+12,1,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_pvbwt(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 22) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_pvbwt_peak_br_fw,tvb,offset,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbwt_peak_br_bw,tvb,offset+3,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbwt_peak_bucket_fw,tvb,offset+6,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbwt_peak_bucket_bw,tvb,offset+8,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbwt_sust_br_fw,tvb,offset+10,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbwt_sust_br_bw,tvb,offset+13,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbwt_sust_bucket_fw,tvb,offset+16,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbwt_sust_bucket_bw,tvb,offset+18,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbwt_size_fw,tvb,offset+20,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_pvbwt_size_bw,tvb,offset+21,1,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_vbwt(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
if (len != 22) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
proto_tree_add_item(tree,hf_alcap_vbwt_peak_br_fw,tvb,offset,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbwt_peak_br_bw,tvb,offset+3,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbwt_peak_bucket_fw,tvb,offset+6,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbwt_peak_bucket_bw,tvb,offset+8,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbwt_sust_br_fw,tvb,offset+10,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbwt_sust_br_bw,tvb,offset+13,3,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbwt_sust_bucket_fw,tvb,offset+16,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbwt_sust_bucket_bw,tvb,offset+18,2,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbwt_size_fw,tvb,offset+20,1,ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_alcap_vbwt_size_bw,tvb,offset+21,1,ENC_BIG_ENDIAN);
return NULL;
}
static const gchar* dissect_fields_sut(packet_info* pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int len, alcap_message_info_t* msg_info _U_) {
guint sut_len;
if (len < 2) {
proto_tree_add_expert(tree, pinfo, &ei_alcap_parameter_field_bad_length, tvb, offset, len);
return NULL;
}
sut_len = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_alcap_sut_len, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_alcap_sut, tvb, offset, sut_len, ENC_NA);
return NULL;
}
static void alcap_leg_tree(proto_tree* tree, tvbuff_t* tvb, packet_info *pinfo, const alcap_leg_info_t* leg) {
proto_item* pi;
tree = proto_tree_add_subtree(tree,tvb,0,0,ett_leg,NULL,"[ALCAP Leg Info]");
if (leg->dsaid) {
pi = proto_tree_add_uint(tree,hf_alcap_leg_dsaid,tvb,0,0,leg->dsaid);
PROTO_ITEM_SET_GENERATED(pi);
}
if (leg->osaid) {
pi = proto_tree_add_uint(tree,hf_alcap_leg_osaid,tvb,0,0,leg->osaid);
PROTO_ITEM_SET_GENERATED(pi);
}
if (leg->pathid) {
pi = proto_tree_add_uint(tree,hf_alcap_leg_pathid,tvb,0,0,leg->pathid);
PROTO_ITEM_SET_GENERATED(pi);
}
if (leg->cid) {
pi = proto_tree_add_uint(tree,hf_alcap_leg_cid,tvb,0,0,leg->cid);
PROTO_ITEM_SET_GENERATED(pi);
}
if (leg->sugr) {
pi = proto_tree_add_uint(tree,hf_alcap_leg_sugr,tvb,0,0,leg->sugr);
PROTO_ITEM_SET_GENERATED(pi);
}
if (leg->orig_nsap) {
pi = proto_tree_add_string(tree,hf_alcap_leg_onsea,tvb,0,0,leg->orig_nsap);
PROTO_ITEM_SET_GENERATED(pi);
}
if (leg->dest_nsap) {
pi = proto_tree_add_string(tree,hf_alcap_leg_dnsea,tvb,0,0,leg->dest_nsap);
PROTO_ITEM_SET_GENERATED(pi);
}
if(leg->release_cause) {
pi = proto_tree_add_uint(tree,hf_alcap_leg_release_cause,tvb,0,0,leg->release_cause);
PROTO_ITEM_SET_GENERATED(pi);
if (leg->release_cause && leg->release_cause != 31)
expert_add_info(pinfo, pi, &ei_alcap_release_cause_not31);
}
if(leg->msgs) {
alcap_msg_data_t* msg = leg->msgs;
proto_item* pi_local;
proto_tree* tree_local = proto_tree_add_subtree(tree,tvb,0,0,ett_leg,&pi_local,"[Messages in this leg]");
do {
pi_local = proto_tree_add_uint(tree_local,hf_alcap_leg_frame,tvb,0,0,msg->framenum);
proto_item_set_text(pi_local,"%s in frame %u",
val_to_str_ext_const(msg->msg_type,&msg_type_strings_ext,"Unknown message"),
msg->framenum);
PROTO_ITEM_SET_GENERATED(pi_local);
} while (( msg = msg->next));
}
}
extern void alcap_tree_from_bearer_key(proto_tree* tree, tvbuff_t* tvb, packet_info *pinfo, const gchar* key) {
alcap_leg_info_t* leg = (alcap_leg_info_t*)wmem_tree_lookup_string(legs_by_bearer,key,0);
if (leg) {
alcap_leg_tree(tree,tvb,pinfo,leg);
}
}
static int dissect_alcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
proto_tree *alcap_tree = NULL;
alcap_message_info_t* msg_info = wmem_new0(wmem_packet_scope(), alcap_message_info_t);
int len = tvb_reported_length(tvb);
int offset;
proto_item* pi;
proto_tree* compat_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, alcap_proto_name_short);
if (tree) {
proto_item *alcap_item = proto_tree_add_item(tree, proto_alcap, tvb, 0, -1, ENC_NA);
alcap_tree = proto_item_add_subtree(alcap_item, ett_alcap);
}
proto_tree_add_item(alcap_tree,hf_alcap_dsaid,tvb,0,4,ENC_BIG_ENDIAN);
pi = proto_tree_add_item(alcap_tree,hf_alcap_msg_id,tvb,4,1,ENC_BIG_ENDIAN);
msg_info->dsaid = tvb_get_ntohl(tvb, 0);
msg_info->msg_type = tvb_get_guint8(tvb, 4);
expert_add_info(pinfo, pi, &ei_alcap_response);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(msg_info->msg_type, msg_type_strings, "Unknown Message"));
pi = proto_tree_add_item(alcap_tree,hf_alcap_compat,tvb,5,1,ENC_NA);
compat_tree = proto_item_add_subtree(pi,ett_compat);
proto_tree_add_item(compat_tree,hf_alcap_compat_pass_on_sni,tvb,5,1,ENC_BIG_ENDIAN);
proto_tree_add_item(compat_tree,hf_alcap_compat_pass_on_ii,tvb,5,1,ENC_BIG_ENDIAN);
proto_tree_add_item(compat_tree,hf_alcap_compat_general_sni,tvb,5,1,ENC_BIG_ENDIAN);
proto_tree_add_item(compat_tree,hf_alcap_compat_general_ii,tvb,5,1,ENC_BIG_ENDIAN);
len -= ALCAP_MSG_HEADER_LEN;
offset = ALCAP_MSG_HEADER_LEN;
while(len > 0) {
guint param_id = tvb_get_guint8(tvb,offset);
guint param_len = tvb_get_guint8(tvb,offset+2);
const alcap_param_info_t* param_info = GET_PARAM_INFO(param_id);
proto_tree* param_tree;
const gchar* colinfo_str = NULL;
pi = proto_tree_add_item(alcap_tree,hf_alcap_param_id,tvb,offset,1,ENC_BIG_ENDIAN);
param_tree = proto_item_add_subtree(pi,param_info->ett);
pi = proto_tree_add_item(param_tree,hf_alcap_compat,tvb,offset+1,1,ENC_NA);
compat_tree = proto_item_add_subtree(pi,ett_compat);
proto_tree_add_item(compat_tree,hf_alcap_compat_pass_on_sni,tvb,offset+1,1,ENC_BIG_ENDIAN);
proto_tree_add_item(compat_tree,hf_alcap_compat_pass_on_ii,tvb,offset+1,1,ENC_BIG_ENDIAN);
proto_tree_add_item(compat_tree,hf_alcap_compat_general_sni,tvb,offset+1,1,ENC_BIG_ENDIAN);
proto_tree_add_item(compat_tree,hf_alcap_compat_general_ii,tvb,offset+1,1,ENC_BIG_ENDIAN);
proto_tree_add_item(param_tree,hf_alcap_param_len,tvb,offset+2,1,ENC_BIG_ENDIAN);
if ( alcap_tree || param_info->run_wo_tree )
colinfo_str = param_info->dissect_fields(pinfo,tvb,param_tree,offset+3,param_len,msg_info);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",colinfo_str);
len -= 3 + param_len;
offset += 3 + param_len;
}
if (keep_persistent_info) {
alcap_leg_info_t* leg = NULL;
switch (msg_info->msg_type) {
case 5:
if( ! ( leg = (alcap_leg_info_t*)wmem_tree_lookup32(legs_by_osaid,msg_info->osaid) )) {
leg = wmem_new(wmem_file_scope(), alcap_leg_info_t);
leg->dsaid = 0;
leg->osaid = msg_info->osaid;
leg->pathid = msg_info->pathid;
leg->cid = msg_info->cid;
leg->sugr = msg_info->sugr;
leg->orig_nsap = NULL;
leg->dest_nsap = NULL;
if (msg_info->orig_nsap) {
gchar* key = wmem_strdup_printf(wmem_file_scope(), "%s:%.8X",msg_info->orig_nsap,leg->sugr);
ascii_strdown_inplace(key);
leg->orig_nsap = wmem_strdup(wmem_file_scope(), msg_info->orig_nsap);
if (!wmem_tree_lookup_string(legs_by_bearer,key,0)) {
wmem_tree_insert_string(legs_by_bearer,key,leg,0);
}
}
if (msg_info->dest_nsap) {
gchar* key = wmem_strdup_printf(wmem_file_scope(), "%s:%.8X",msg_info->dest_nsap,leg->sugr);
ascii_strdown_inplace(key);
leg->dest_nsap = wmem_strdup(wmem_file_scope(), msg_info->dest_nsap);
if (!wmem_tree_lookup_string(legs_by_bearer,key,0)) {
wmem_tree_insert_string(legs_by_bearer,key,leg,0);
}
}
leg->msgs = NULL;
leg->release_cause = 0;
wmem_tree_insert32(legs_by_osaid,leg->osaid,leg);
}
break;
case 4:
if(( leg = (alcap_leg_info_t *)wmem_tree_lookup32(legs_by_osaid,msg_info->dsaid) )) {
leg->dsaid = msg_info->osaid;
wmem_tree_insert32(legs_by_dsaid,leg->dsaid,leg);
}
break;
case 6:
case 12:
case 13:
case 14:
if( ( leg = (alcap_leg_info_t *)wmem_tree_lookup32(legs_by_osaid,msg_info->dsaid) )
|| ( leg = (alcap_leg_info_t *)wmem_tree_lookup32(legs_by_dsaid,msg_info->dsaid) ) ) {
if(msg_info->release_cause)
leg->release_cause = msg_info->release_cause;
}
break;
case 7:
leg = (alcap_leg_info_t *)wmem_tree_lookup32(legs_by_osaid,msg_info->dsaid);
if(leg) {
leg->release_cause = msg_info->release_cause;
} else if (( leg = (alcap_leg_info_t *)wmem_tree_lookup32(legs_by_dsaid,msg_info->dsaid) )) {
leg->release_cause = msg_info->release_cause;
}
break;
default:
break;
}
if (leg != NULL && ( (! leg->msgs) || leg->msgs->last->framenum < pinfo->num ) ) {
alcap_msg_data_t* msg = wmem_new(wmem_file_scope(), alcap_msg_data_t);
msg->msg_type = msg_info->msg_type;
msg->framenum = pinfo->num;
msg->next = NULL;
msg->last = NULL;
if (leg->msgs) {
leg->msgs->last->next = msg;
} else {
leg->msgs = msg;
}
leg->msgs->last = msg;
}
if (tree && leg) alcap_leg_tree(alcap_tree,tvb,pinfo,leg);
}
return tvb_captured_length(tvb);
}
void
proto_register_alcap(void)
{
module_t *alcap_module;
expert_module_t *expert_alcap;
static hf_register_info hf[] = {
{ &hf_alcap_dsaid,
{ "DSAID", "alcap.dsaid",
FT_UINT32, BASE_HEX, NULL, 0,
"Destination Service Association ID", HFILL }
},
{ &hf_alcap_msg_id,
{ "Message Type", "alcap.msg_type",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &msg_type_strings_ext, 0,
NULL, HFILL }
},
{ &hf_alcap_compat,
{ "Message Compatibility", "alcap.compat",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_compat_pass_on_sni,
{ "Pass-On SNI", "alcap.compat.pass.sni",
FT_UINT8, BASE_DEC, VALS(send_notification), 0x40,
"Send Notification Indicator", HFILL }
},
{ &hf_alcap_compat_pass_on_ii,
{ "Pass-On II", "alcap.compat.pass.ii",
FT_UINT8, BASE_DEC, VALS(instruction_indicator), 0x30,
"Instruction Indicator", HFILL }
},
{ &hf_alcap_compat_general_sni,
{ "General SNI", "alcap.compat.general.sni",
FT_UINT8, BASE_DEC, VALS(send_notification), 0x04,
"Send Notification Indicator", HFILL }
},
{ &hf_alcap_compat_general_ii,
{ "General II", "alcap.compat.general.ii",
FT_UINT8, BASE_DEC, VALS(instruction_indicator), 0x03,
"Instruction Indicator", HFILL }
},
{ &hf_alcap_unknown,
{ "Unknown Field Data", "alcap.unknown.field",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_param_id,
{ "Parameter", "alcap.param",
FT_UINT8, BASE_DEC, VALS(msg_parm_strings), 0,
"Parameter Id", HFILL }
},
{ &hf_alcap_param_len,
{ "Length", "alcap.param.len",
FT_UINT8, BASE_DEC, NULL, 0,
"Parameter Length", HFILL }
},
{ &hf_alcap_cau_coding,
{ "Cause Coding", "alcap.cau.coding",
FT_UINT8, BASE_DEC, VALS(cause_coding_vals), 0x03,
NULL, HFILL }
},
{ &hf_alcap_cau_value_itu,
{ "Cause Value (ITU)", "alcap.cau.value",
FT_UINT8, BASE_DEC, VALS(cause_values_itu), 0x7f,
NULL, HFILL }
},
{ &hf_alcap_cau_value_non_itu,
{ "Cause Value (Other)", "alcap.cau.value",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_alcap_cau_diag,
{ "Diagnostic", "alcap.cau.diag",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_cau_diag_len,
{ "Length", "alcap.cau.diag.len",
FT_UINT8, BASE_DEC, NULL, 0,
"Diagnostics Length", HFILL }
},
{ &hf_alcap_cau_diag_msg,
{ "Message Identifier", "alcap.cau.diag.msg",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &msg_type_strings_ext, 0,
NULL, HFILL }
},
{ &hf_alcap_cau_diag_param_id,
{ "Parameter Identifier", "alcap.cau.diag.param",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_cau_diag_field_num,
{ "Field Number", "alcap.cau.diag.field_num",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ceid_pathid,
{ "Path ID", "alcap.ceid.pathid",
FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(all_paths_vals), 0,
NULL, HFILL }
},
{ &hf_alcap_ceid_cid,
{ "CID", "alcap.ceid.cid",
FT_UINT8, BASE_DEC|BASE_SPECIAL_VALS, VALS(all_cids_vals), 0,
NULL, HFILL }
},
{ &hf_alcap_dnsea,
{ "Address", "alcap.dnsea.addr",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_alc_max_br_fw,
{ "Maximum Forward Bit Rate", "alcap.alc.bitrate.max.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_alc_max_br_bw,
{ "Maximum Backwards Bit Rate", "alcap.alc.bitrate.max.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_alc_avg_br_fw,
{ "Average Forward Bit Rate", "alcap.alc.bitrate.avg.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_alc_avg_br_bw,
{ "Average Backwards Bit Rate", "alcap.alc.bitrate.avg.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_alc_max_sdu_fw,
{ "Maximum Forward CPS SDU Size", "alcap.alc.sdusize.max.fw",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_alcap_alc_max_sdu_bw,
{ "Maximum Backwards CPS SDU Size", "alcap.alc.sdusize.max.bw",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_alcap_alc_avg_sdu_fw,
{ "Average Forward CPS SDU Size", "alcap.alc.sdusize.avg.fw",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_alcap_alc_avg_sdu_bw,
{ "Average Backwards CPS SDU Size", "alcap.alc.sdusize.avg.bw",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_alcap_osaid,
{ "OSAID", "alcap.osaid",
FT_UINT32, BASE_HEX, NULL, 0,
"Originating Service Association ID", HFILL }
},
{ &hf_alcap_sugr,
{ "SUGR", "alcap.sugr",
FT_BYTES, BASE_NONE, NULL, 0,
"Served User Generated Reference", HFILL }
},
{ &hf_alcap_sut_len,
{ "SUT Length", "alcap.sut.sut_len",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_sut,
{ "SUT", "alcap.sut.transport",
FT_BYTES, BASE_NONE, NULL, 0,
"Served User Transport", HFILL }
},
{ &hf_alcap_ssia_pr_type,
{ "Profile Type", "alcap.ssia.profile.type",
FT_UINT8, BASE_DEC, VALS(audio_profile_type), 0xc0,
"I.366.2 Profile Type", HFILL }
},
{ &hf_alcap_ssia_pr_id,
{ "Profile Id", "alcap.ssia.profile.id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssia_frm,
{ "Frame Mode", "alcap.ssia.frm",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x80,
NULL, HFILL }
},
{ &hf_alcap_ssia_cmd,
{ "Circuit Mode", "alcap.ssia.cmd",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x40,
NULL, HFILL }
},
{ &hf_alcap_ssia_mfr2,
{ "Multi-Frequency R2", "alcap.ssia.mfr2",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x20,
NULL, HFILL }
},
{ &hf_alcap_ssia_mfr1,
{ "Multi-Frequency R1", "alcap.ssia.mfr1",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x10,
NULL, HFILL }
},
{ &hf_alcap_ssia_dtmf,
{ "DTMF", "alcap.ssia.dtmf",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x08,
NULL, HFILL }
},
{ &hf_alcap_ssia_cas,
{ "CAS", "alcap.ssia.cas",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x04,
"Channel Associated Signalling", HFILL }
},
{ &hf_alcap_ssia_fax,
{ "Fax", "alcap.ssia.fax",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x02,
"Facsimile", HFILL }
},
{ &hf_alcap_ssia_pcm,
{ "PCM Mode", "alcap.ssia.pcm",
FT_UINT8, BASE_DEC, VALS(alaw_ulaw), 0x01,
NULL, HFILL }
},
{ &hf_alcap_ssia_max_len,
{ "Max Len of FM Data", "alcap.ssia.max_fmdata_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssia_oui,
{ "OUI", "alcap.ssia.oui",
FT_BYTES, BASE_NONE, NULL, 0,
"Organizational Unique Identifier", HFILL }
},
{ &hf_alcap_ssim_frm,
{ "Frame Mode", "alcap.ssim.frm",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x80,
NULL, HFILL }
},
{ &hf_alcap_ssim_mult,
{ "Multiplier", "alcap.ssim.mult",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_alcap_ssim_max,
{ "Max Len", "alcap.ssim.max",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssisa_max_sssar_fw,
{ "Maximum Len of SSSAR-SDU Forward", "alcap.ssisa.sssar.max_len.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssisa_max_sssar_bw,
{ "Maximum Len of SSSAR-SDU Backwards", "alcap.ssisa.sssar.max_len.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssisa_max_sscop_sdu_fw,
{ "Maximum Len of SSSAR-SDU Forward", "alcap.ssisa.sscop.max_sdu_len.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssisa_max_sscop_sdu_bw,
{ "Maximum Len of SSSAR-SDU Backwards", "alcap.ssisa.sscop.max_sdu_len.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssisa_max_sscop_uu_fw,
{ "Maximum Len of SSSAR-SDU Forward", "alcap.ssisa.sscop.max_uu_len.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssisa_max_sscop_uu_bw,
{ "Maximum Len of SSSAR-SDU Backwards", "alcap.ssisa.sscop.max_uu_len.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssisu_max_sssar_fw,
{ "Maximum Len of SSSAR-SDU Forward", "alcap.ssisu.sssar.max_len.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssisu_max_sssar_bw,
{ "Maximum Len of SSSAR-SDU Backwards", "alcap.ssisu.sssar.max_len.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssisu_ted,
{ "Transmission Error Detection", "alcap.ssisu.ted",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x80,
NULL, HFILL }
},
{ &hf_alcap_pt,
{ "QoS Codepoint", "alcap.pt.codepoint",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_alcap_plc_max_br_fw,
{ "Maximum Forward Bit Rate", "alcap.plc.bitrate.max.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_plc_max_br_bw,
{ "Maximum Backwards Bit Rate", "alcap.plc.bitrate.max.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_plc_avg_br_fw,
{ "Average Forward Bit Rate", "alcap.plc.bitrate.avg.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_plc_avg_br_bw,
{ "Average Backwards Bit Rate", "alcap.plc.bitrate.avg.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_plc_max_sdu_fw,
{ "Maximum Forward CPS SDU Size", "alcap.plc.sdusize.max.fw",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_alcap_plc_max_sdu_bw,
{ "Maximum Backwards CPS SDU Size", "alcap.plc.sdusize.max.bw",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_alcap_plc_avg_sdu_fw,
{ "Maximum Forward CPS SDU Size", "alcap.plc.sdusize.max.fw",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_alcap_plc_avg_sdu_bw,
{ "Maximum Backwards CPS SDU Size", "alcap.plc.sdusize.max.bw",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_alcap_pssiae_pr_type,
{ "Profile Type", "alcap.pssiae.profile.type",
FT_UINT8, BASE_DEC, VALS(audio_profile_type), 0xc0,
"I.366.2 Profile Type", HFILL }
},
{ &hf_alcap_pssiae_pr_id,
{ "Profile Id", "alcap.pssiae.profile.id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pssiae_lb,
{ "Loopback", "alcap.pssiae.lb",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0xc0,
NULL, HFILL }
},
{ &hf_alcap_pssiae_rc,
{ "Rate Control", "alcap.pssiae.rc",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0xc0,
NULL, HFILL }
},
{ &hf_alcap_pssiae_syn,
{ "Synchronization", "alcap.pssiae.syn",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0xc0,
"Transport of synchronization of change in SSCS operation", HFILL }
},
{ &hf_alcap_pssiae_frm,
{ "Frame Mode", "alcap.pssiae.frm",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x80,
NULL, HFILL }
},
{ &hf_alcap_pssiae_cmd,
{ "Circuit Mode", "alcap.pssiae.cmd",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x40,
NULL, HFILL }
},
{ &hf_alcap_pssiae_mfr2,
{ "Multi-Frequency R2", "alcap.pssiae.mfr2",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x20,
NULL, HFILL }
},
{ &hf_alcap_pssiae_mfr1,
{ "Multi-Frequency R1", "alcap.pssiae.mfr1",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x10,
NULL, HFILL }
},
{ &hf_alcap_pssiae_dtmf,
{ "DTMF", "alcap.pssiae.dtmf",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x08,
NULL, HFILL }
},
{ &hf_alcap_pssiae_cas,
{ "CAS", "alcap.pssiae.cas",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x04,
"Channel Associated Signalling", HFILL }
},
{ &hf_alcap_pssiae_fax,
{ "Fax", "alcap.pssiae.fax",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x02,
"Facsimile", HFILL }
},
{ &hf_alcap_pssiae_pcm,
{ "PCM Mode", "alcap.pssiae.pcm",
FT_UINT8, BASE_DEC, VALS(alaw_ulaw), 0x01,
NULL, HFILL }
},
{ &hf_alcap_pssiae_max_len,
{ "Max Len of FM Data", "alcap.pssiae.max_fmdata_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pssiae_oui,
{ "OUI", "alcap.pssiae.oui",
FT_BYTES, BASE_NONE, NULL, 0,
"Organizational Unique Identifier", HFILL }
},
{ &hf_alcap_pssime_frm,
{ "Frame Mode", "alcap.pssime.frm",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x80,
NULL, HFILL }
},
{ &hf_alcap_pssime_lb,
{ "Loopback", "alcap.pssime.lb",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x40,
NULL, HFILL }
},
{ &hf_alcap_pssime_mult,
{ "Multiplier", "alcap.pssime.mult",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_alcap_pssime_max,
{ "Max Len", "alcap.pssime.max",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_suci,
{ "SUCI", "alcap.suci",
FT_UINT8, BASE_HEX, NULL, 0,
"Served User Correlation Id", HFILL }
},
{ &hf_alcap_onsea,
{ "Address", "alcap.onsea.addr",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssiae_pr_type,
{ "Profile Type", "alcap.ssiae.profile.type",
FT_UINT8, BASE_DEC, VALS(audio_profile_type), 0xc0,
"I.366.2 Profile Type", HFILL }
},
{ &hf_alcap_ssiae_lb,
{ "Loopback", "alcap.ssiae.lb",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0xc0,
NULL, HFILL }
},
{ &hf_alcap_ssiae_rc,
{ "Rate Control", "alcap.ssiae.rc",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0xc0,
NULL, HFILL }
},
{ &hf_alcap_ssiae_syn,
{ "Synchronization", "alcap.ssiae.syn",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0xc0,
"Transport of synchronization of change in SSCS operation", HFILL }
},
{ &hf_alcap_ssiae_pr_id,
{ "Profile Id", "alcap.ssiae.profile.id",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssiae_frm,
{ "Frame Mode", "alcap.ssiae.frm",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x80,
NULL, HFILL }
},
{ &hf_alcap_ssiae_cmd,
{ "Circuit Mode", "alcap.ssiae.cmd",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x40,
NULL, HFILL }
},
{ &hf_alcap_ssiae_mfr2,
{ "Multi-Frequency R2", "alcap.ssiae.mfr2",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x20,
NULL, HFILL }
},
{ &hf_alcap_ssiae_mfr1,
{ "Multi-Frequency R1", "alcap.ssiae.mfr1",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x10,
NULL, HFILL }
},
{ &hf_alcap_ssiae_dtmf,
{ "DTMF", "alcap.ssiae.dtmf",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x08,
NULL, HFILL }
},
{ &hf_alcap_ssiae_cas,
{ "CAS", "alcap.ssiae.cas",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x04,
"Channel Associated Signalling", HFILL }
},
{ &hf_alcap_ssiae_fax,
{ "Fax", "alcap.ssiae.fax",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x02,
"Facsimile", HFILL }
},
{ &hf_alcap_ssiae_pcm,
{ "PCM Mode", "alcap.ssiae.pcm",
FT_UINT8, BASE_DEC, VALS(alaw_ulaw), 0x01,
NULL, HFILL }
},
{ &hf_alcap_ssiae_max_len,
{ "Max Len of FM Data", "alcap.ssiae.max_fmdata_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_ssiae_oui,
{ "OUI", "alcap.ssiae.oui",
FT_BYTES, BASE_NONE, NULL, 0,
"Organizational Unique Identifier", HFILL }
},
{ &hf_alcap_ssime_frm,
{ "Frame Mode", "alcap.ssime.frm",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x80,
NULL, HFILL }
},
{ &hf_alcap_ssime_lb,
{ "Loopback", "alcap.ssime.lb",
FT_UINT8, BASE_DEC, VALS(enabled_disabled), 0x40,
NULL, HFILL }
},
{ &hf_alcap_ssime_mult,
{ "Multiplier", "alcap.ssime.mult",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_alcap_ssime_max,
{ "Max Len", "alcap.ssime.max",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_acc_level,
{ "Congestion Level", "alcap.acc.level",
FT_UINT8, BASE_DEC, VALS(congestion_level), 0,
NULL, HFILL }
},
{ &hf_alcap_cp,
{ "Level", "alcap.cp.level",
FT_UINT8, BASE_DEC, VALS(connection_priority), 0x07,
NULL, HFILL }
},
{ &hf_alcap_hc,
{ "Codepoint", "alcap.hc.codepoint",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pfbw_br_fw,
{ "CPS Forward Bitrate", "alcap.pfbw.bitrate.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pfbw_br_bw,
{ "CPS Backwards Bitrate", "alcap.pfbw.bitrate.bw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pfbw_bucket_fw,
{ "Forward CPS Bucket Size", "alcap.pfbw.bucket_size.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pfbw_bucket_bw,
{ "Backwards CPS Bucket Size", "alcap.pfbw.bucket_size.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pfbw_size_fw,
{ "Forward CPS Packet Size", "alcap.pfbw.max_size.fw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pfbw_size_bw,
{ "Backwards CPS Packet Size", "alcap.pfbw.max_size.bw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbws_br_fw,
{ "Peak CPS Forward Bitrate", "alcap.pvbws.bitrate.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbws_br_bw,
{ "Peak CPS Backwards Bitrate", "alcap.pvbws.bitrate.bw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbws_bucket_fw,
{ "Peak Forward CPS Bucket Size", "alcap.pvbws.bucket_size.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbws_bucket_bw,
{ "Peak Backwards CPS Bucket Size", "alcap.pvbws.bucket_size.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbws_size_fw,
{ "Forward CPS Packet Size", "alcap.pvbws.max_size.fw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbws_size_bw,
{ "Backwards CPS Packet Size", "alcap.pvbws.max_size.bw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbws_stt,
{ "Source Traffic Type", "alcap.pvbws.stt",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbwt_peak_br_fw,
{ "Peak CPS Forward Bitrate", "alcap.pvbwt.bitrate.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbwt_peak_br_bw,
{ "Peak CPS Backwards Bitrate", "alcap.pvbwt.bitrate.bw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbwt_peak_bucket_fw,
{ "Peak Forward CPS Bucket Size", "alcap.pvbwt.bucket_size.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbwt_peak_bucket_bw,
{ "Peak Backwards CPS Bucket Size", "alcap.pvbwt.bucket_size.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbwt_sust_br_fw,
{ "Sustainable CPS Forward Bitrate", "alcap.pvbwt.bitrate.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbwt_sust_br_bw,
{ "Sustainable CPS Backwards Bitrate", "alcap.pvbwt.bitrate.bw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbwt_sust_bucket_fw,
{ "Sustainable Forward CPS Bucket Size", "alcap.pvbwt.bucket_size.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbwt_sust_bucket_bw,
{ "Sustainable Backwards CPS Bucket Size", "alcap.pvbwt.bucket_size.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbwt_size_fw,
{ "Forward CPS Packet Size", "alcap.pvbwt.max_size.fw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_pvbwt_size_bw,
{ "Backwards CPS Packet Size", "alcap.pvbwt.max_size.bw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_fbw_br_fw,
{ "CPS Forward Bitrate", "alcap.fbw.bitrate.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_fbw_br_bw,
{ "CPS Backwards Bitrate", "alcap.fbw.bitrate.bw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_fbw_bucket_fw,
{ "Forward CPS Bucket Size", "alcap.fbw.bucket_size.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_fbw_bucket_bw,
{ "Backwards CPS Bucket Size", "alcap.fbw.bucket_size.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_fbw_size_fw,
{ "Forward CPS Packet Size", "alcap.fbw.max_size.fw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_fbw_size_bw,
{ "Backwards CPS Packet Size", "alcap.fbw.max_size.bw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbws_br_fw,
{ "CPS Forward Bitrate", "alcap.vbws.bitrate.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbws_br_bw,
{ "CPS Backwards Bitrate", "alcap.vbws.bitrate.bw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbws_bucket_fw,
{ "Forward CPS Bucket Size", "alcap.vbws.bucket_size.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbws_bucket_bw,
{ "Backwards CPS Bucket Size", "alcap.vbws.bucket_size.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbws_size_fw,
{ "Forward CPS Packet Size", "alcap.vbws.max_size.fw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbws_size_bw,
{ "Backwards CPS Packet Size", "alcap.vbws.max_size.bw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbws_stt,
{ "Source Traffic Type", "alcap.vbws.stt",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbwt_peak_br_fw,
{ "Peak CPS Forward Bitrate", "alcap.vbwt.bitrate.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbwt_peak_br_bw,
{ "Peak CPS Backwards Bitrate", "alcap.vbwt.bitrate.bw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbwt_peak_bucket_fw,
{ "Peak Forward CPS Bucket Size", "alcap.vbwt.bucket_size.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbwt_peak_bucket_bw,
{ "Peak Backwards CPS Bucket Size", "alcap.vbwt.bucket_size.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbwt_sust_br_fw,
{ "Sustainable CPS Forward Bitrate", "alcap.vbwt.bitrate.fw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbwt_sust_br_bw,
{ "Sustainable CPS Backwards Bitrate", "alcap.vbwt.bitrate.bw",
FT_UINT24, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbwt_sust_bucket_fw,
{ "Sustainable Forward CPS Bucket Size", "alcap.vbwt.bucket_size.fw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbwt_sust_bucket_bw,
{ "Sustainable Backwards CPS Bucket Size", "alcap.vbwt.bucket_size.bw",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbwt_size_fw,
{ "Forward CPS Packet Size", "alcap.vbwt.max_size.fw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_vbwt_size_bw,
{ "Backwards CPS Packet Size", "alcap.vbwt.max_size.bw",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_leg_osaid,
{ "Leg's ERQ OSA id", "alcap.leg.osaid",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_leg_dsaid,
{ "Leg's ECF OSA id", "alcap.leg.dsaid",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_leg_pathid,
{ "Leg's path id", "alcap.leg.pathid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_leg_cid,
{ "Leg's channel id", "alcap.leg.cid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_leg_sugr,
{ "Leg's SUGR", "alcap.leg.sugr",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_leg_dnsea,
{ "Leg's destination NSAP", "alcap.leg.dnsea",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_leg_onsea,
{ "Leg's originating NSAP", "alcap.leg.onsea",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_leg_frame,
{ "a message of this leg", "alcap.leg.msg",
FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_alcap_leg_release_cause,
{ "Leg's cause value in REL", "alcap.leg.cause",
FT_UINT8, BASE_DEC, VALS(cause_values_itu), 0,
NULL, HFILL }
},
};
gint* ett[] = {
&ett_alcap,
&ett_leg,
&ett_compat,
&ett_cau_diag,
&param_infos[0].ett,
&param_infos[1].ett,
&param_infos[2].ett,
&param_infos[3].ett,
&param_infos[4].ett,
&param_infos[5].ett,
&param_infos[6].ett,
&param_infos[7].ett,
&param_infos[8].ett,
&param_infos[9].ett,
&param_infos[10].ett,
&param_infos[11].ett,
&param_infos[12].ett,
&param_infos[13].ett,
&param_infos[14].ett,
&param_infos[15].ett,
&param_infos[16].ett,
&param_infos[17].ett,
&param_infos[18].ett,
&param_infos[19].ett,
&param_infos[20].ett,
&param_infos[21].ett,
&param_infos[22].ett,
&param_infos[23].ett,
&param_infos[24].ett,
&param_infos[25].ett,
&param_infos[26].ett,
&param_infos[27].ett,
&param_infos[28].ett,
&param_infos[29].ett,
&param_infos[30].ett,
&param_infos[31].ett,
&param_infos[32].ett,
&param_infos[33].ett,
&param_infos[34].ett,
&param_infos[35].ett,
};
static ei_register_info ei[] = {
{ &ei_alcap_parameter_field_bad_length, { "alcap.parameter_field_bad_length", PI_MALFORMED, PI_WARN, "Wrong length for parameter fields", EXPFILL }},
{ &ei_alcap_undecoded, { "alcap.undecoded", PI_UNDECODED, PI_WARN, "Undecoded", EXPFILL }},
{ &ei_alcap_release_cause_not31, { "alcap.leg.cause.not31", PI_RESPONSE_CODE, PI_WARN, "Leg Release cause != 31", EXPFILL }},
{ &ei_alcap_abnormal_release, { "alcap.abnormal_release", PI_RESPONSE_CODE, PI_WARN, "Abnormal Release", EXPFILL }},
{ &ei_alcap_response, { "alcap.response", PI_RESPONSE_CODE, PI_NOTE, " ", EXPFILL }},
};
proto_alcap = proto_register_protocol(alcap_proto_name, alcap_proto_name_short, "alcap");
alcap_handle = register_dissector("alcap", dissect_alcap, proto_alcap);
proto_register_field_array(proto_alcap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_alcap = expert_register_protocol(proto_alcap);
expert_register_field_array(expert_alcap, ei, array_length(ei));
alcap_module = prefs_register_protocol(proto_alcap, NULL);
prefs_register_bool_preference(alcap_module, "leg_info",
"Keep Leg Information",
"Whether persistent call leg information is to be kept",
&keep_persistent_info);
legs_by_dsaid = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
legs_by_osaid = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
legs_by_bearer = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
}
void
proto_reg_handoff_alcap(void)
{
dissector_add_uint("mtp3.service_indicator", MTP_SI_AAL2, alcap_handle);
}
