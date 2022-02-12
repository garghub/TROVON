static int
dissect_uma_IE(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
tvbuff_t *l3_tvb;
tvbuff_t *llc_tvb;
tvbuff_t *new_tvb;
int ie_offset;
guint8 ie_value;
guint16 ie_len = 0;
guint8 octet;
proto_item *urr_ie_item;
proto_tree *urr_ie_tree;
char *string;
guint16 GPRS_user_data_transport_UDP_port,UNC_tcp_port,RTP_UDP_port,RTCP_UDP_port;
guint32 udr;
conversation_t *conversation;
address dst_addr, null_addr;
guint8 str_len;
address src_addr;
ie_value = tvb_get_guint8(tvb,offset);
urr_ie_item = proto_tree_add_text(tree,tvb,offset,-1,"%s",
val_to_str_ext(ie_value, &uma_urr_IE_type_vals_ext, "Unknown IE (%u)"));
urr_ie_tree = proto_item_add_subtree(urr_ie_item, ett_urr_ie);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_IE, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_len = tvb_get_guint8(tvb,offset);
if ( (ie_len & 0x80) == 0x80 ){
offset++;
ie_len = (ie_len & 0x7f) << 8;
ie_len = ie_len | (tvb_get_guint8(tvb,offset));
proto_item_set_len(urr_ie_item, ie_len + 3);
proto_tree_add_uint(urr_ie_tree, hf_uma_urr_IE_len , tvb, offset-1, 2, ie_len );
ie_offset = offset +1;
}else{
proto_item_set_len(urr_ie_item, ie_len + 2);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_IE_len, tvb, offset, 1, ENC_BIG_ENDIAN);
ie_offset = offset +1;
}
switch(ie_value){
case 1:
de_mid(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 2:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_uri, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 3:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_radio_type_of_id, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,ie_offset);
if (( octet & 0xf) == 0){
ie_offset++;
proto_tree_add_item(urr_ie_tree, hf_uma_urr_radio_id, tvb, ie_offset, ie_len-1, ENC_NA);
}else{
proto_tree_add_text(urr_ie_tree, tvb, ie_offset, ie_len,"Unknown format");
}
break;
case 4:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_cell_id, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
break;
case 5:
de_lai(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 6:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_gci, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 7:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_tura, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_gc, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_uc, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
if(ie_len>1){
ie_offset++;
proto_tree_add_item(urr_ie_tree, hf_uma_urr_gmsi, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_psho, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_rrs, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
}
break;
case 8:
new_tvb = tvb_new_subset(tvb, ie_offset,ie_len, ie_len );
dissect_geographical_description(new_tvb, pinfo, urr_ie_tree);
break;
case 9:
octet = tvb_get_guint8(tvb,ie_offset);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_IP_Address_type, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
ie_offset++;
if ( octet == 0x57 ){
}else{
sgw_ipv4_address = tvb_get_ipv4(tvb, ie_offset);
proto_tree_add_ipv4(urr_ie_tree, hf_uma_urr_sgw_ipv4, tvb, ie_offset, 4, sgw_ipv4_address);
}
break;
case 10:
if ( ie_len > 0){
string = (gchar*)tvb_get_ephemeral_string(tvb, ie_offset, ie_len);
proto_tree_add_string(urr_ie_tree, hf_uma_urr_FQDN, tvb, ie_offset, ie_len, string);
}else{
proto_tree_add_text(urr_ie_tree,tvb,offset,1,"FQDN not present");
}
break;
case 11:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_redirection_counter, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 12:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_dis_rej_cau, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 13:
de_rr_cell_dsc(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 14:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_ECMC, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_NMO, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_GPRS, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_DTM, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_ATT, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_MSCR, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
ie_offset++;
proto_tree_add_item(urr_ie_tree, hf_uma_urr_T3212_timer, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
ie_offset++;
proto_tree_add_item(urr_ie_tree, hf_uma_urr_RAC, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
ie_offset++;
proto_tree_add_item(urr_ie_tree, hf_uma_urr_SGSNR, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_ECMP, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_RE, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_PFCFM, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_3GECS, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
ie_offset++;
proto_tree_add_text(urr_ie_tree,tvb,ie_offset,2,"Access Control Class N");
break;
case 15:
be_cell_id_list(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 16:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_TU3907_timer, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
break;
case 17:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_GSM_RR_state, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 18:
de_gmm_rai(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 19:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_gan_band, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 20:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_URR_state, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 21:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_register_reject_cause, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 22:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_TU3906_timer, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
break;
case 23:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_TU3910_timer, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
break;
case 24:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_TU3902_timer, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
break;
case 25:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_communication_port, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
break;
case 26:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_L3_protocol_discriminator, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_L3_Message, tvb, ie_offset, ie_len, ENC_NA);
l3_tvb = tvb_new_subset(tvb, ie_offset,ie_len, ie_len );
if (!dissector_try_uint(bssap_pdu_type_table,BSSAP_PDU_TYPE_DTAP, l3_tvb, pinfo, urr_ie_tree))
call_dissector(data_handle, l3_tvb, pinfo, urr_ie_tree);
break;
case 27:
de_rr_ch_mode(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 28:
de_ms_cm_2(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 29:
de_rr_cause(tvb, urr_ie_tree, pinfo, ie_offset, 1, NULL, 0);
break;
case 30:
de_rr_cip_mode_set(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 31:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_GPRS_resumption, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 32:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_L3_protocol_discriminator, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_L3_Message, tvb, ie_offset, ie_len, ENC_NA);
l3_tvb = tvb_new_subset(tvb, ie_offset,ie_len, ie_len );
if (!dissector_try_uint(bssap_pdu_type_table,BSSAP_PDU_TYPE_DTAP, l3_tvb, pinfo, urr_ie_tree))
call_dissector(data_handle, l3_tvb, pinfo, urr_ie_tree);
break;
case 33:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_ULQI, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 34:
de_rr_tlli(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 35:
de_sm_pflow_id(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 36:
de_rr_sus_cau(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 37:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_TU3920_timer, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
break;
case 38:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_peak_tpt_cls, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_radio_pri, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_rlc_mode, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 39:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_ga_psr_cause, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 40:
udr = tvb_get_ntoh24(tvb, ie_offset) * 100;
proto_tree_add_uint(urr_ie_tree, hf_uma_urr_udr , tvb, ie_offset, 3, udr );
break;
case 41:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_RAC, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 42:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_ap_location, tvb, ie_offset, ie_len, ENC_NA);
break;
case 43:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_TU4001_timer, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
break;
case 44:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_LS, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 45:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_cipher_res, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 46:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_rand_val, tvb, ie_offset, ie_len, ENC_NA);
break;
case 47:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_ciphering_command_mac, tvb, ie_offset, ie_len, ENC_NA);
break;
case 48:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_ciphering_key_seq_num, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 49:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_sapi_id, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 50:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_establishment_cause, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 51:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_channel, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 52:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_PDU_in_error, tvb, ie_offset, ie_len, ENC_NA);
break;
case 53:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_sample_size, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 54:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_payload_type, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 55:
de_rr_multirate_conf(tvb, urr_ie_tree, pinfo, ie_offset, ie_len, NULL, 0);
break;
case 56:
de_ms_cm_3(tvb, urr_ie_tree, pinfo, offset, ie_len, NULL, 0);
break;
case 57:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_LLC_PDU, tvb, ie_offset, ie_len, ENC_NA);
llc_tvb = tvb_new_subset(tvb, ie_offset,ie_len, ie_len );
if (llc_handle) {
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/");
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
call_dissector(llc_handle, llc_tvb, pinfo, urr_ie_tree);
}else{
if (data_handle)
call_dissector(data_handle, llc_tvb, pinfo, urr_ie_tree);
}
break;
case 58:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_LBLI, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 59:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_RI, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 60:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_TU4003_timer, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
break;
case 61:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_ap_service_name_type, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
ie_offset++;
proto_tree_add_item(urr_ie_tree, hf_uma_urr_ap_Service_name_value, tvb, ie_offset, ie_len -1, ENC_ASCII|ENC_NA);
break;
case 62:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_uma_service_zone_icon_ind, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
ie_offset++;
proto_tree_add_item(urr_ie_tree, hf_uma_urr_uma_service_zone_str_len, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
str_len = tvb_get_guint8(tvb,ie_offset);
ie_offset++;
proto_tree_add_item(urr_ie_tree, hf_uma_urr_uma_service_zone_str, tvb, ie_offset, str_len, ENC_ASCII|ENC_NA);
break;
case 63:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_window_size, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_uma_codec_mode, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 64:
new_tvb = tvb_new_subset(tvb, ie_offset,ie_len, ie_len );
dissect_rrc_InterRATHandoverInfo_PDU(new_tvb, pinfo, urr_ie_tree, NULL);
break;
case 65:
de_rr_cm_enq_mask(tvb, urr_ie_tree, pinfo, offset, ie_len, NULL, 0);
break;
case 66:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_UTRAN_cell_id_disc, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,ie_offset);
ie_offset++;
if ( octet == 0 ){
ie_offset = dissect_e212_mcc_mnc(tvb, pinfo, urr_ie_tree, ie_offset, TRUE);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_lac, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
}
break;
case 67:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_suti, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 68:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_uma_mps, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 69:
octet = tvb_get_guint8(tvb,ie_offset);
proto_tree_add_uint(urr_ie_tree, hf_uma_urr_num_of_plms , tvb, ie_offset, 1, octet);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_lac, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
break;
case 70:
while(ie_offset<=(offset + ie_len)){
proto_tree_add_item(urr_ie_tree, hf_uma_urr_RXLEV_NCELL, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
ie_offset++;
}
break;
case 71:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_cbs, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
break;
case 72:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_num_of_cbs_frms , tvb, ie_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(urr_ie_tree, tvb, ie_offset + 1, ie_len-1,"CBS Frames - Not decoded");
break;
case 73:
break;
case 79:
case 80:
case 81:
case 82:
case 83:
case 84:
case 85:
case 86:
case 87:
case 88:
case 89:
case 90:
case 91:
case 92:
case 93:
case 94:
case 95:
proto_tree_add_text(urr_ie_tree,tvb,ie_offset,ie_len,"DATA");
break;
case 96:
proto_tree_add_item(urr_ie_tree, hf_uma_urr_radio_type_of_id, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb,ie_offset);
if (( octet & 0xf) == 0){
ie_offset++;
proto_tree_add_item(urr_ie_tree, hf_uma_urr_ms_radio_id, tvb, ie_offset, ie_len-1, ENC_NA);
}else{
proto_tree_add_text(urr_ie_tree, tvb, ie_offset, ie_len,"Unknown format");
}
break;
case 97:
octet = tvb_get_guint8(tvb,ie_offset);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_IP_Address_type, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
if (ie_len > 4 )
ie_offset++;
if ( octet == 0x57 ){
}else{
unc_ipv4_address = tvb_get_ipv4(tvb, ie_offset);
proto_tree_add_ipv4(urr_ie_tree, hf_uma_urr_unc_ipv4, tvb, ie_offset, 4, unc_ipv4_address);
}
break;
case 98:
if ( ie_len > 0){
string = (gchar*)tvb_get_ephemeral_string(tvb, ie_offset, ie_len);
proto_tree_add_string(urr_ie_tree, hf_uma_unc_FQDN, tvb, ie_offset, ie_len, string);
}else{
proto_tree_add_text(urr_ie_tree,tvb,offset,1,"UNC FQDN not present");
}
break;
case 99:
octet = tvb_get_guint8(tvb,ie_offset);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_IP_Address_type, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
ie_offset++;
if ( octet == 0x57 ){
}else{
GPRS_user_data_ipv4_address = tvb_get_ipv4(tvb, ie_offset);
proto_tree_add_ipv4(urr_ie_tree, hf_uma_urr_GPRS_user_data_transport_ipv4, tvb, ie_offset, 4, GPRS_user_data_ipv4_address);
}
break;
case 100:
GPRS_user_data_transport_UDP_port = tvb_get_ntohs(tvb,ie_offset);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_GPRS_port, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
if (pinfo->fd->flags.visited)
{
break;
}
SET_ADDRESS(&null_addr, AT_NONE, 0, NULL);
SET_ADDRESS(&dst_addr, AT_IPv4, 4, &GPRS_user_data_ipv4_address);
conversation = find_conversation(pinfo->fd->num,&dst_addr,
&null_addr, PT_UDP, GPRS_user_data_transport_UDP_port,
0, NO_ADDR_B|NO_PORT_B);
if (conversation == NULL) {
conversation = conversation_new(pinfo->fd->num, &dst_addr,
&null_addr, PT_UDP,GPRS_user_data_transport_UDP_port ,
0, NO_ADDR2|NO_PORT2);
conversation_set_dissector(conversation, uma_udp_handle);
}
break;
case 103:
UNC_tcp_port = tvb_get_ntohs(tvb,ie_offset);
proto_tree_add_uint(urr_ie_tree, hf_uma_urr_UNC_tcp_port , tvb, ie_offset, 2, UNC_tcp_port);
if (pinfo->fd->flags.visited)
{
break;
}
SET_ADDRESS(&null_addr, AT_NONE, 0, NULL);
SET_ADDRESS(&dst_addr, AT_IPv4, 4, &unc_ipv4_address);
conversation = find_conversation(pinfo->fd->num,&dst_addr,
&null_addr, PT_TCP, UNC_tcp_port,
0, NO_ADDR_B|NO_PORT_B);
if (conversation == NULL) {
conversation = conversation_new(pinfo->fd->num, &dst_addr,
&null_addr, PT_TCP,UNC_tcp_port ,
0, NO_ADDR2|NO_PORT2);
conversation_set_dissector(conversation, uma_tcp_handle);
}
break;
case 104:
RTP_UDP_port = tvb_get_ntohs(tvb,ie_offset);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_RTP_port, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
if(unc_ipv4_address!=0){
SET_ADDRESS(&src_addr, AT_IPv4, 4, &unc_ipv4_address);
}else{
src_addr = pinfo->src;
}
if((!pinfo->fd->flags.visited) && RTP_UDP_port!=0 && rtp_handle){
rtp_add_address(pinfo, &src_addr, RTP_UDP_port, 0, "UMA", pinfo->fd->num, FALSE, 0);
if ((RTP_UDP_port & 0x1) == 0){
RTCP_UDP_port = RTP_UDP_port + 1;
rtcp_add_address(pinfo, &src_addr, RTCP_UDP_port, 0, "UMA", pinfo->fd->num);
}
}
break;
case 105:
RTCP_UDP_port = tvb_get_ntohs(tvb,ie_offset);
proto_tree_add_item(urr_ie_tree, hf_uma_urr_RTCP_port, tvb, ie_offset, 2, ENC_BIG_ENDIAN);
if((!pinfo->fd->flags.visited) && rtcp_ipv4_address!=0 && RTCP_UDP_port!=0 && rtcp_handle){
SET_ADDRESS(&src_addr, AT_IPv4, 4, &rtcp_ipv4_address);
rtcp_add_address(pinfo, &src_addr, RTCP_UDP_port, 0, "UMA", pinfo->fd->num);
}
break;
case 106:
while(ie_offset<=(offset + ie_len)){
proto_tree_add_item(urr_ie_tree, hf_uma_urr_RXLEV_NCELL, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
ie_offset++;
}
break;
case 107:
while(ie_offset<=(offset + ie_len)){
proto_tree_add_item(urr_ie_tree, hf_uma_urr_RXLEV_NCELL, tvb, ie_offset, 1, ENC_BIG_ENDIAN);
ie_offset++;
}
break;
case 108:
case 109:
case 110:
case 111:
case 112:
case 115:
case 116:
case 117:
case 118:
case 119:
case 120:
case 121:
case 122:
case 123:
case 124:
case 125:
case 126:
default:
proto_tree_add_text(urr_ie_tree,tvb,ie_offset,ie_len,"DATA");
break;
}
offset = offset + ie_len;
return offset;
}
static void
dissect_uma(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 octet, pd;
guint16 msg_len;
proto_item *ti;
proto_tree *uma_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UMA");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_uma, tvb, 0, -1, ENC_NA);
uma_tree = proto_item_add_subtree(ti, ett_uma);
msg_len = tvb_get_ntohs(tvb,offset);
proto_tree_add_item(uma_tree, hf_uma_length_indicator, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
octet = tvb_get_guint8(tvb,offset);
pd = octet & 0x0f;
proto_tree_add_item(uma_tree, hf_uma_skip_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((octet & 0xf0) != 0 ){
proto_tree_add_text(uma_tree, tvb,offset,-1,"Skip this message");
return;
}
proto_tree_add_item(uma_tree, hf_uma_pd, tvb, offset, 1, ENC_BIG_ENDIAN);
switch ( pd ){
case 0:
case 1:
offset++;
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_item(uma_tree, hf_uma_urr_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str_ext(octet, &uma_urr_msg_type_vals_ext, "Unknown URR (%u)"));
while ((msg_len + 1) > offset ){
offset++;
offset = dissect_uma_IE(tvb, pinfo, uma_tree, offset);
}
break;
case 2:
offset++;
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_item(uma_tree, hf_uma_urlc_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str_ext(octet, &uma_urlc_msg_type_vals_ext, "Unknown URLC (%u)"));
col_set_fence(pinfo->cinfo,COL_INFO);
offset++;
proto_tree_add_item(uma_tree, hf_uma_urlc_TLLI, tvb, offset, 4, ENC_NA);
offset = offset + 3;
while ((msg_len + 1) > offset ){
offset++;
offset = dissect_uma_IE(tvb, pinfo, uma_tree, offset);
}
break;
default:
proto_tree_add_text(uma_tree, tvb,offset,-1,"Unknown protocol %u",pd);
break;
}
}
static guint
get_uma_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohs(tvb,offset)+2;
}
static void
dissect_uma_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, uma_desegment, UMA_HEADER_SIZE,
get_uma_pdu_len, dissect_uma);
}
static int
dissect_uma_urlc_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0;
guint8 octet;
guint16 msg_len;
proto_item *ti;
proto_tree *uma_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UMA");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_uma, tvb, 0, -1, ENC_NA);
uma_tree = proto_item_add_subtree(ti, ett_uma);
octet = tvb_get_guint8(tvb,offset);
proto_tree_add_item(uma_tree, hf_uma_urlc_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",val_to_str_ext(octet, &uma_urlc_msg_type_vals_ext, "Unknown URLC (%u)"));
col_set_fence(pinfo->cinfo,COL_INFO);
msg_len = tvb_length_remaining(tvb,offset) - 1;
switch ( octet ){
case 2:
case 6:
case 7:
offset++;
proto_tree_add_item(uma_tree, hf_uma_urlc_TLLI, tvb, offset, 4, ENC_NA);
offset = offset + 4;
proto_tree_add_item(uma_tree, hf_uma_urlc_seq_nr, tvb, offset, 2, ENC_NA);
offset++;
while (msg_len > offset){
offset++;
offset = dissect_uma_IE(tvb, pinfo, uma_tree, offset);
}
return offset;
default:
proto_tree_add_text(uma_tree, tvb,offset,-1,"Wrong message type %u",octet);
return tvb_length(tvb);
}
}
static void
range_delete_callback(guint32 port)
{
dissector_delete_uint("tcp.port", port, uma_tcp_handle);
}
static void
range_add_callback(guint32 port)
{
dissector_add_uint("tcp.port", port, uma_tcp_handle);
}
void
proto_reg_handoff_uma(void)
{
static gboolean Initialized=FALSE;
static range_t *uma_tcp_port_range;
if (!Initialized) {
uma_tcp_handle = find_dissector("umatcp");
uma_udp_handle = find_dissector("umaudp");
dissector_add_handle("udp.port", uma_udp_handle);
data_handle = find_dissector("data");
rtp_handle = find_dissector("rtp");
rtcp_handle = find_dissector("rtcp");
llc_handle = find_dissector("llcgprs");
bssap_pdu_type_table = find_dissector_table("bssap.pdu_type");
Initialized=TRUE;
} else {
range_foreach(uma_tcp_port_range, range_delete_callback);
g_free(uma_tcp_port_range);
}
uma_tcp_port_range = range_copy(global_uma_tcp_port_range);
range_foreach(uma_tcp_port_range, range_add_callback);
}
void
proto_register_uma(void)
{
module_t *uma_module;
static hf_register_info hf[] = {
{ &hf_uma_length_indicator,
{ "Length Indicator","uma.li",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_pd,
{ "Protocol Discriminator","uma.pd",
FT_UINT8, BASE_DEC, VALS(uma_pd_vals), 0x0f,
NULL, HFILL }
},
{ &hf_uma_skip_ind,
{ "Skip Indicator", "uma.skip.ind",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_uma_urr_msg_type,
{ "URR Message Type", "uma.urr.msg.type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &uma_urr_msg_type_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_uma_urlc_msg_type,
{ "URLC Message Type", "uma.urlc.msg.type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &uma_urlc_msg_type_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_uma_urlc_TLLI,
{ "Temporary Logical Link Identifier","uma.urlc.tlli",
FT_BYTES,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urlc_seq_nr,
{ "Sequence Number","uma.urlc.seq.nr",
FT_BYTES,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_IE,
{ "URR Information Element","uma.urr.ie.type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &uma_urr_IE_type_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_IE_len,
{ "URR Information Element length","uma.urr.ie.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_uri,
{ "GAN Release Indicator","uma.urr.uri",
FT_UINT8, BASE_DEC, VALS(uma_urr_gan_rel_ind_vals), 0x07,
"URI", HFILL }
},
{ &hf_uma_urr_radio_type_of_id,
{ "Type of identity","uma.urr.radio_type_of_id",
FT_UINT8, BASE_DEC, VALS(radio_type_of_id_vals), 0x0f,
NULL, HFILL }
},
{ &hf_uma_urr_radio_id,
{ "Radio Identity","uma.urr.radio_id",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_uma_urr_cell_id,
{ "Cell Identity","uma.urr.cell_id",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_uma_urr_lac,
{ "Location area code","uma.urr.lac",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_gci,
{ "GCI, GSM Coverage Indicator","uma.urr.gci",
FT_UINT8, BASE_DEC, VALS(uma_gci_vals), 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_tura,
{ "TURA, Type of Unlicensed Radio","uma.urr.tura",
FT_UINT8,BASE_DEC, VALS(uma_tura_vals), 0xf,
NULL, HFILL }
},
{ &hf_uma_urr_gc,
{ "GC, GERAN Capable","uma.urr.gc",
FT_UINT8,BASE_DEC, VALS(uma_gc_vals), 0x10,
NULL, HFILL }
},
{ &hf_uma_urr_uc,
{ "UC, UTRAN Capable","uma.urr.uc",
FT_UINT8,BASE_DEC, VALS(uma_uc_vals), 0x20,
"GC, GERAN Capable", HFILL }
},
{ &hf_uma_urr_rrs,
{ "RTP Redundancy Support(RRS)","uma.urr.rrs",
FT_UINT8,BASE_DEC, VALS(uma_rrs_vals), 0x01,
NULL, HFILL }
},
{ &hf_uma_urr_gmsi,
{ "GMSI, GAN Mode Support Indicator)","uma.urr.gmsi",
FT_UINT8,BASE_DEC, VALS(uma_gmsi_vals), 0x06,
"GMSI, GAN Mode Support Indicator", HFILL }
},
{ &hf_uma_urr_psho,
{ "PS HO, PS Handover Capable","uma.urr.psho",
FT_UINT8,BASE_DEC, VALS(uma_ps_ho_vals), 0x02,
NULL, HFILL }
},
{ &hf_uma_urr_IP_Address_type,
{ "IP address type number value","uma.urr.ip_type",
FT_UINT8,BASE_DEC, VALS(IP_address_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_FQDN,
{ "Fully Qualified Domain/Host Name (FQDN)", "uma.urr.fqdn",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_uma_urr_sgw_ipv4,
{ "SGW IPv4 address","uma.urr.sgwipv4",
FT_IPv4,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_redirection_counter,
{ "Redirection Counter","uma.urr.redirection_counter",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_dis_rej_cau,
{ "Discovery Reject Cause","uma.urr.dis_rej_cau",
FT_UINT8,BASE_DEC, VALS(uma_discovery_reject_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_ECMC,
{ "ECMC, Early Classmark Sending Control","uma.urr.ECMC",
FT_UINT8,BASE_DEC, VALS(ECMC_vals), 0x2,
NULL, HFILL }
},
{ &hf_uma_urr_NMO,
{ "NMO, Network Mode of Operation","uma.urr.NMO",
FT_UINT8,BASE_DEC, VALS(NMO_vals), 0xc,
NULL, HFILL }
},
{ &hf_uma_urr_GPRS,
{ "GPRS, GPRS Availability","uma.urr.GPRS",
FT_UINT8,BASE_DEC, VALS(GPRS_avail_vals), 0x10,
NULL, HFILL }
},
{ &hf_uma_urr_DTM,
{ "DTM, Dual Transfer Mode of Operation by network","uma.urr.dtm",
FT_UINT8,BASE_DEC, VALS(DTM_vals), 0x20,
NULL, HFILL }
},
{ &hf_uma_urr_ATT,
{ "ATT, Attach-detach allowed","uma.urr.att",
FT_UINT8,BASE_DEC, VALS(ATT_vals), 0x40,
NULL, HFILL }
},
{ &hf_uma_urr_MSCR,
{ "MSCR, MSC Release","uma.urr.mscr",
FT_UINT8,BASE_DEC, VALS(MSCR_vals), 0x80,
NULL, HFILL }
},
{ &hf_uma_urr_T3212_timer,
{ "T3212 Timer value(seconds)","uma.urr.t3212",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_RAC,
{ "Routing Area Code","uma.urr.rac",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_ap_location,
{ "AP Location","uma.urr.ap_location",
FT_BYTES,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_SGSNR,
{ "SGSN Release","uma.urr.SGSNR",
FT_UINT8,BASE_DEC, VALS(SGSNR_vals), 0x01,
NULL, HFILL }
},
{ &hf_uma_urr_ECMP,
{ "ECMP, Emergency Call Mode Preference","uma.urr.ECMP",
FT_UINT8,BASE_DEC, VALS(ECMP_vals), 0x02,
NULL, HFILL }
},
{ &hf_uma_urr_RE,
{ "RE, Call reestablishment allowed","uma.urr.RE",
FT_UINT8,BASE_DEC, VALS(RE_vals), 0x04,
NULL, HFILL }
},
{ &hf_uma_urr_PFCFM,
{ "PFCFM, PFC_FEATURE_MODE","uma.urr.PFCFM",
FT_UINT8,BASE_DEC, VALS(PFCFM_vals), 0x08,
NULL, HFILL }
},
{ &hf_uma_urr_3GECS,
{ "3GECS, 3G Early Classmark Sending Restriction","uma.urr.3GECS",
FT_UINT8,BASE_DEC, VALS(Three_GECS_vals), 0x10,
NULL, HFILL }
},
{ &hf_uma_urr_TU3907_timer,
{ "TU3907 Timer value(seconds)","uma.urr.tu3907",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_GSM_RR_state,
{ "GSM RR State value","uma.urr.gsmrrstate",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &uma_GRS_GSM_RR_State_vals_ext, 0x7,
NULL, HFILL }
},
{ &hf_uma_urr_gan_band,
{ "UMA Band","uma.urr.umaband",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &uma_gan_band_vals_ext, 0x0f,
NULL, HFILL }
},
{ &hf_uma_urr_URR_state,
{ "URR State","uma.urr.state",
FT_UINT8,BASE_DEC, VALS(URR_state_vals), 0x03,
NULL, HFILL }
},
{ &hf_uma_urr_register_reject_cause,
{ "Register Reject Cause","uma.urr.reg_rej_cau",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &register_reject_cause_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_TU3906_timer,
{ "TU3907 Timer value(seconds)","uma.urr.tu3906",
FT_UINT16,BASE_DEC, NULL, 0x0,
"TU3906 Timer value(seconds)", HFILL }
},
{ &hf_uma_urr_TU3910_timer,
{ "TU3907 Timer value(seconds)","uma.urr.tu3910",
FT_UINT16,BASE_DEC, NULL, 0x0,
"TU3910 Timer value(seconds)", HFILL }
},
{ &hf_uma_urr_TU3902_timer,
{ "TU3902 Timer value(seconds)","uma.urr.tu3902",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_communication_port,
{ "Communication Port","uma.urr.communication_port",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_L3_Message,
{ "L3 message contents","uma.urr.l3",
FT_BYTES,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_L3_protocol_discriminator,
{ "Protocol discriminator","uma.urr.L3_protocol_discriminator",
FT_UINT8,BASE_DEC, VALS(protocol_discriminator_vals), 0x0f,
NULL, HFILL }
},
{ &hf_uma_urr_GPRS_resumption,
{ "GPRS resumption ACK","uma.urr.GPRS_resumption",
FT_UINT8,BASE_DEC, VALS(GPRS_resumption_vals), 0x1,
NULL, HFILL }
},
{ &hf_uma_urr_ULQI,
{ "ULQI, UL Quality Indication","uma.urr.ULQI",
FT_UINT8,BASE_DEC, VALS(uma_ulqi_vals), 0x0f,
NULL, HFILL }
},
{ &hf_uma_urr_TU3920_timer,
{ "TU3920 Timer value(seconds)","uma.urr.tu3920",
FT_UINT16,BASE_DEC, NULL, 0x0,
"TU3920 Timer value(hundreds of of ms)", HFILL }
},
{ &hf_uma_urr_peak_tpt_cls,
{ "PEAK_THROUGHPUT_CLASS","uma.urr.peak_tpt_cls",
FT_UINT8,BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_uma_urr_radio_pri,
{ "Radio Priority","uma.urr.radio_pri",
FT_UINT8,BASE_DEC, VALS(radio_pri_vals), 0x30,
"RADIO_PRIORITY", HFILL }
},
{ &hf_uma_urr_rlc_mode,
{ "RLC mode","uma.urr.rrlc_mode",
FT_UINT8,BASE_DEC, VALS(rlc_mode_vals), 0x80,
NULL, HFILL }
},
{ &hf_uma_urr_ga_psr_cause,
{ "GA-PSR Cause","uma.urr.ga_psr_cause",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &uma_ga_psr_cause_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_udr,
{ "User Data Rate value (bits/s)","uma.urr.URLCcause",
FT_UINT32,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_TU4001_timer,
{ "TU4001 Timer value(seconds)","uma.urr.tu4001",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_LS,
{ "Location Status(LS)","uma.urr.LS",
FT_UINT8,BASE_DEC, VALS(LS_vals), 0x3,
NULL, HFILL }
},
{ &hf_uma_urr_cipher_res,
{ "Cipher Response(CR)","uma.urr.CR",
FT_UINT8,BASE_DEC, VALS(CR_vals), 0x3,
NULL, HFILL }
},
{ &hf_uma_urr_rand_val,
{ "Ciphering Command RAND value","uma.rand_val",
FT_BYTES,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_ciphering_command_mac,
{ "Ciphering Command MAC (Message Authentication Code)","uma.ciphering_command_mac",
FT_BYTES,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_ciphering_key_seq_num,
{ "Values for the ciphering key","uma.ciphering_key_seq_num",
FT_UINT8,BASE_DEC, NULL, 0x7,
NULL, HFILL }
},
{ &hf_uma_urr_sapi_id,
{ "SAPI ID","uma.sapi_id",
FT_UINT8,BASE_DEC, VALS(sapi_id_vals), 0x7,
NULL, HFILL }
},
{ &hf_uma_urr_establishment_cause,
{ "Establishment Cause","uma.urr.establishment_cause",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &uma_establishment_cause_val_ext, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_channel,
{ "Channel","uma.urr.channel",
FT_UINT8,BASE_DEC, VALS(channel_vals), 0x3,
NULL, HFILL }
},
{ &hf_uma_urr_PDU_in_error,
{ "PDU in Error,","uma.urr.PDU_in_error",
FT_BYTES,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_sample_size,
{ "Sample Size","uma.urr.sample_size",
FT_UINT8,BASE_DEC, VALS(sample_size_vals), 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_payload_type,
{ "Payload Type","uma.urr.payload_type",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_LLC_PDU,
{ "LLC-PDU","uma.urr.llc_pdu",
FT_BYTES,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_LBLI,
{ "LBLI, Location Black List indicator","uma.urr.LBLI",
FT_UINT8,BASE_DEC, VALS(LBLI_vals), 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_RI,
{ "Reset Indicator(RI)","uma.urr.RI",
FT_UINT8,BASE_DEC, VALS(RI_vals), 0x1,
NULL, HFILL }
},
{ &hf_uma_urr_TU4003_timer,
{ "TU4003 Timer value(seconds)","uma.urr.tu4003",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_ap_service_name_type,
{ "AP Service Name type","uma.urr.ap_service_name_type",
FT_UINT8,BASE_DEC, VALS(ap_service_name_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_ap_Service_name_value,
{ "AP Service Name Value","uma.urr.ap_service_name_value",
FT_STRING,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_uma_service_zone_icon_ind,
{ "UMA Service Zone Icon Indicator","uma.urr.uma_service_zone_icon_ind",
FT_UINT8,BASE_DEC, VALS(uma_service_zone_icon_ind_vals), 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_uma_service_zone_str_len,
{ "Length of UMA Service Zone string","uma.urr.service_zone_str_len",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_window_size,
{ "Window Size","uma.urr.uma_window_size",
FT_UINT8,BASE_DEC, VALS(window_size_vals), 0x03,
NULL, HFILL }
},
{ &hf_uma_urr_uma_codec_mode,
{ "GAN A/Gb Mode Codec Mode","uma.urr.uma_codec_mode",
FT_UINT8,BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_uma_urr_UTRAN_cell_id_disc,
{ "UTRAN Cell Identification Discriminator","uma.urr.uma_UTRAN_cell_id_disc",
FT_UINT8,BASE_DEC, VALS(UTRAN_cell_id_disc_vals), 0x0f,
NULL, HFILL }
},
{ &hf_uma_urr_suti,
{ "SUTI, Serving GANC table indicator","uma.urr.uma_suti",
FT_UINT8,BASE_DEC, VALS(suti_vals), 0x01,
NULL, HFILL }
},
{ &hf_uma_urr_uma_mps,
{ "UMPS, Manual PLMN Selection indicator","uma.urr.mps",
FT_UINT8,BASE_DEC, VALS(mps_vals), 0x3,
"MPS, Manual PLMN Selection indicator", HFILL }
},
{ &hf_uma_urr_num_of_plms,
{ "Number of PLMN:s","uma.urr.num_of_plms",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_cbs,
{ "CBS Cell Broadcast Service","uma.urr.cbs",
FT_UINT8,BASE_DEC, VALS(cbs_vals), 0x01,
NULL, HFILL }
},
{ &hf_uma_urr_num_of_cbs_frms,
{ "Number of CBS Frames","uma.urr.num_of_cbs_frms",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_ms_radio_id,
{ "MS Radio Identity","uma.urr.ms_radio_id",
FT_ETHER, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_uma_urr_uma_service_zone_str,
{ "UMA Service Zone string,","uma.urr.uma_service_zone_str",
FT_STRING,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_unc_ipv4,
{ "UNC IPv4 address","uma.urr.uncipv4",
FT_IPv4,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_unc_FQDN,
{ "UNC Fully Qualified Domain/Host Name (FQDN)", "uma.urr.unc_fqdn",
FT_STRING, BASE_NONE,NULL,0x0,
NULL, HFILL }
},
{ &hf_uma_urr_GPRS_user_data_transport_ipv4,
{ "IP address for GPRS user data transport","uma.urr.gprs_usr_data_ipv4",
FT_IPv4,BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_GPRS_port,
{ "UDP Port for GPRS user data transport","uma.urr.gprs_port",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_UNC_tcp_port,
{ "UNC TCP port","uma.urr.tcp_port",
FT_UINT16,BASE_DEC, NULL, 0x0,
"UDP Port for GPRS user data transport", HFILL }
},
{ &hf_uma_urr_RTP_port,
{ "RTP UDP port","uma.urr.rtp_port",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_RTCP_port,
{ "RTCP UDP port","uma.urr.rtcp_port",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_uma_urr_RXLEV_NCELL,
{ "RX Level","uma.urr.rxlevel",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_uma,
&ett_uma_toc,
&ett_urr_ie,
};
proto_uma = proto_register_protocol("Unlicensed Mobile Access","UMA", "uma");
register_dissector("umatcp", dissect_uma_tcp, proto_uma);
new_register_dissector("umaudp", dissect_uma_urlc_udp, proto_uma);
proto_register_field_array(proto_uma, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
uma_module = prefs_register_protocol(proto_uma, proto_reg_handoff_uma);
range_convert_str(&global_uma_tcp_port_range, DEFAULT_UMA_PORT_RANGE, MAX_UDP_PORT);
prefs_register_bool_preference(uma_module, "desegment_ucp_messages",
"Reassemble UMA messages spanning multiple TCP segments",
"Whether the UMA dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&uma_desegment);
prefs_register_obsolete_preference(uma_module, "tcp.port1");
prefs_register_obsolete_preference(uma_module, "udp.ports");
prefs_register_range_preference(uma_module, "tcp.ports", "UMA TCP ports",
"TCP ports to be decoded as UMA (default: "
DEFAULT_UMA_PORT_RANGE ")",
&global_uma_tcp_port_range, MAX_UDP_PORT);
}
