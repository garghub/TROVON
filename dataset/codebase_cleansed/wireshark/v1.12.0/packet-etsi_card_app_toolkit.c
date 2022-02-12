static int
dissect_cat(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *cat_ti;
proto_tree *cat_tree, *elem_tree;
unsigned int pos = 0;
tvbuff_t *new_tvb;
gboolean ims_event = FALSE;
guint length = tvb_length(tvb);
gsm_sms_data_t sms_data;
cat_ti = proto_tree_add_item(tree, proto_cat, tvb, 0, -1, ENC_NA);
cat_tree = proto_item_add_subtree(cat_ti, ett_cat);
while (pos < length) {
proto_item *ti;
guint8 g8;
guint16 tag;
guint32 len, i;
guint8 *ptr = NULL;
tag = tvb_get_guint8(tvb, pos++) & 0x7f;
if (tag == 0x7f) {
tag = tvb_get_ntohs(tvb, pos) & 0x7fff;
pos += 2;
}
len = tvb_get_guint8(tvb, pos++);
switch (len) {
case 0x81:
len = tvb_get_guint8(tvb, pos++);
break;
case 0x82:
len = tvb_get_ntohs(tvb, pos);
pos += 2;
break;
case 0x83:
len = tvb_get_ntoh24(tvb, pos);
pos += 3;
break;
default:
break;
}
#if 1
ti = proto_tree_add_bytes_format(cat_tree, hf_cat_tlv, tvb, pos,
len, ptr, "%s: %s",
val_to_str_ext(tag, &comp_tlv_tag_vals_ext, "%02x"),
(const guint8 *)tvb_bytes_to_ep_str(tvb, pos, len));
#else
ti = proto_tree_add_bytes_format(cat_tree, hf_cat_tlv, tvb, pos,
len, ptr, "%s: ",
val_to_str_ext(tag, &comp_tlv_tag_vals_ext, "%02x"));
#endif
elem_tree = proto_item_add_subtree(ti, ett_elem);
switch (tag) {
case 0x01:
if (len < 3)
break;
proto_tree_add_item(elem_tree, hf_ctlv_cmd_nr, tvb, pos, 1, ENC_NA);
proto_tree_add_item(elem_tree, hf_ctlv_cmd_type, tvb, pos+1, 1, ENC_NA);
g8 = tvb_get_guint8(tvb, pos+1);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str_ext(g8, &cmd_type_vals_ext, "%02x "));
switch (g8) {
case 0x01:
proto_tree_add_item(elem_tree, hf_ctlv_cmd_qual_refresh, tvb, pos+2, 1, ENC_NA);
break;
case 0x13:
proto_tree_add_item(elem_tree, hf_ctlv_cmd_qual_send_short_msg, tvb, pos+2, 1, ENC_NA);
sms_data.stk_packing_required = tvb_get_guint8(tvb, pos+2) & 0x01 ? TRUE : FALSE;
break;
case 0x26:
proto_tree_add_item(elem_tree, hf_ctlv_cmd_qual_loci, tvb, pos+2, 1, ENC_NA);
break;
case 0x27:
proto_tree_add_item(elem_tree, hf_ctlv_cmd_qual_timer_mgmt, tvb, pos+2, 1, ENC_NA);
break;
case 0x40:
proto_tree_add_item(elem_tree, hf_ctlv_cmd_qual, tvb, pos+2, 1, ENC_NA);
ims_event = TRUE;
break;
case 0x43:
proto_tree_add_item(elem_tree, hf_ctlv_cmd_qual_send_data, tvb, pos+2, 1, ENC_NA);
break;
default:
proto_tree_add_item(elem_tree, hf_ctlv_cmd_qual, tvb, pos+2, 1, ENC_NA);
break;
}
break;
case 0x02:
if (len < 2)
break;
proto_tree_add_item(elem_tree, hf_ctlv_devid_src, tvb, pos, 1, ENC_NA);
proto_tree_add_item(elem_tree, hf_ctlv_devid_dst, tvb, pos+1, 1, ENC_NA);
break;
case 0x03:
g8 = tvb_get_guint8(tvb, pos);
proto_tree_add_item(elem_tree, hf_ctlv_result_gen, tvb, pos, 1, ENC_NA);
switch (g8) {
case 0x20:
proto_tree_add_item(elem_tree, hf_ctlv_result_term, tvb, pos+1, 1, ENC_NA);
break;
case 0x26:
proto_tree_add_item(elem_tree, hf_ctlv_result_launch_browser, tvb, pos+1, 1, ENC_NA);
break;
case 0x38:
proto_tree_add_item(elem_tree, hf_ctlv_result_multiplecard, tvb, pos+1, 1, ENC_NA);
break;
case 0x39:
proto_tree_add_item(elem_tree, hf_ctlv_result_cc_ctrl_mo_sm_ctrl, tvb, pos+1, 1, ENC_NA);
break;
case 0x3a:
proto_tree_add_item(elem_tree, hf_ctlv_result_bip, tvb, pos+1, 1, ENC_NA);
break;
case 0x3c:
proto_tree_add_item(elem_tree, hf_ctlv_result_frames_cmd, tvb, pos+1, 1, ENC_NA);
break;
default:
break;
}
break;
case 0x04:
if (len < 2)
break;
proto_tree_add_item(elem_tree, hf_ctlv_dur_time_intv, tvb, pos+1, 1, ENC_NA);
proto_tree_add_item(elem_tree, hf_ctlv_dur_time_unit, tvb, pos, 1, ENC_NA);
break;
case 0x05:
break;
case 0x06:
de_cld_party_bcd_num(tvb, elem_tree, pinfo, pos, len, NULL, 0);
break;
case 0x0b:
new_tvb = tvb_new_subset(tvb, pos, len, len);
if (new_tvb) {
int p2p_dir_save = pinfo->p2p_dir;
if (data) {
if (GPOINTER_TO_INT(data) == 0xd0) {
pinfo->p2p_dir = P2P_DIR_RECV;
} else {
pinfo->p2p_dir = P2P_DIR_SENT;
}
}
call_dissector_only(gsm_sms_handle, new_tvb, pinfo, elem_tree, &sms_data);
pinfo->p2p_dir = p2p_dir_save;
}
break;
case 0x0d:
if (len == 0)
break;
proto_tree_add_item(elem_tree, hf_ctlv_text_string_enc, tvb, pos, 1, ENC_NA);
g8 = tvb_get_guint8(tvb, pos);
switch (g8 & 0xf0) {
case 0x00:
g8 &= 0x0c;
break;
case 0xf0:
g8 &= 0x04;
break;
default:
break;
}
switch (g8) {
case 0x00:
proto_tree_add_item(elem_tree, hf_ctlv_text_string, tvb, pos+1, len-1, ENC_3GPP_TS_23_038_7BITS|ENC_NA);
break;
case 0x04:
proto_tree_add_item(elem_tree, hf_ctlv_text_string, tvb, pos+1, len-1, ENC_ASCII|ENC_NA);
break;
case 0x08:
proto_tree_add_item(elem_tree, hf_ctlv_text_string, tvb, pos+1, len-1, ENC_UCS_2|ENC_BIG_ENDIAN);
break;
default:
break;
}
break;
case 0x0e:
if (len < 1)
break;
proto_tree_add_item(elem_tree, hf_ctlv_tone, tvb, pos, 1, ENC_NA);
break;
case 0x13:
dissect_e212_mcc_mnc(tvb, pinfo, elem_tree, pos, TRUE);
proto_tree_add_item(elem_tree, hf_ctlv_loci_lac, tvb, pos+3, 2, ENC_BIG_ENDIAN);
if (len == 5)
break;
proto_tree_add_item(elem_tree, hf_ctlv_loci_cell_id, tvb, pos+5, 2, ENC_BIG_ENDIAN);
if (len == 7)
break;
proto_tree_add_item(elem_tree, hf_ctlv_loci_ext_cell_id, tvb, pos+7, 2, ENC_BIG_ENDIAN);
break;
case 0x14:
case 0x62:
de_mid(tvb, elem_tree, pinfo, pos, len, NULL, 0);
break;
case 0x19:
for (i = 0; i < len; i++) {
guint8 event = tvb_get_guint8(tvb, pos+i);
if ((event == 0x17) || (event == 0x18)) {
ims_event = TRUE;
}
proto_tree_add_uint(elem_tree, hf_ctlv_event, tvb, pos+i, 1, event);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str_ext(event, &event_list_vals_ext, "%02x "));
}
break;
case 0x1b:
for (i = 0; i < len; i++)
proto_tree_add_item(elem_tree, hf_ctlv_loc_status, tvb, pos+i, 1, ENC_NA);
break;
case 0x25:
{
guint8 oct;
oct = tvb_get_guint8(tvb, pos);
proto_tree_add_uint_format_value(elem_tree, hf_ctlv_timer_val_hr, tvb, pos, 1, oct, "%u (0x%02x)", 10*(oct&0x0f)+(oct>>4), oct);
oct = tvb_get_guint8(tvb, pos+1);
proto_tree_add_uint_format_value(elem_tree, hf_ctlv_timer_val_min, tvb, pos+1, 1, oct, "%u (0x%02x)", 10*(oct&0x0f)+(oct>>4), oct);
oct = tvb_get_guint8(tvb, pos+2);
proto_tree_add_uint_format_value(elem_tree, hf_ctlv_timer_val_sec, tvb, pos+2, 1, oct, "%u (0x%02x)", 10*(oct&0x0f)+(oct>>4), oct);
}
break;
case 0x26:
{
guint8 oct, tz;
oct = tvb_get_guint8(tvb, pos);
proto_tree_add_uint_format_value(elem_tree, hf_ctlv_date_time_yr, tvb, pos, 1, oct, "%u (0x%02x)", 10*(oct&0x0f)+(oct>>4), oct);
oct = tvb_get_guint8(tvb, pos+1);
proto_tree_add_uint_format_value(elem_tree, hf_ctlv_date_time_mo, tvb, pos+1, 1, oct, "%u (0x%02x)", 10*(oct&0x0f)+(oct>>4), oct);
oct = tvb_get_guint8(tvb, pos+2);
proto_tree_add_uint_format_value(elem_tree, hf_ctlv_date_time_day, tvb, pos+2, 1, oct, "%u (0x%02x)", 10*(oct&0x0f)+(oct>>4), oct);
oct = tvb_get_guint8(tvb, pos+3);
proto_tree_add_uint_format_value(elem_tree, hf_ctlv_date_time_hr, tvb, pos+3, 1, oct, "%u (0x%02x)", 10*(oct&0x0f)+(oct>>4), oct);
oct = tvb_get_guint8(tvb, pos+4);
proto_tree_add_uint_format_value(elem_tree, hf_ctlv_date_time_min, tvb, pos+4, 1, oct, "%u (0x%02x)", 10*(oct&0x0f)+(oct>>4), oct);
oct = tvb_get_guint8(tvb, pos+5);
proto_tree_add_uint_format_value(elem_tree, hf_ctlv_date_time_sec, tvb, pos+5, 1, oct, "%u (0x%02x)", 10*(oct&0x0f)+(oct>>4), oct);
oct = tvb_get_guint8(tvb, pos+6);
if (oct == 0xff) {
proto_tree_add_uint_format_value(elem_tree, hf_ctlv_date_time_tz, tvb, pos+6, 1, oct, "Unknown (0x%02x)", oct);
} else {
tz = (oct >> 4) + (oct & 0x07) * 10;
proto_tree_add_uint_format_value(elem_tree, hf_ctlv_date_time_tz, tvb, pos+6, 1, oct, "GMT %c %d hr %d min (0x%02x)",
(oct & 0x08)?'-':'+', tz/4, (tz%4)*15, oct);
}
}
break;
case 0x28:
proto_tree_add_item(elem_tree, hf_ctlv_at_cmd, tvb, pos, len, ENC_ASCII|ENC_NA);
break;
case 0x29:
proto_tree_add_item(elem_tree, hf_ctlv_at_rsp, tvb, pos, len, ENC_ASCII|ENC_NA);
break;
case 0x2d:
proto_tree_add_item(elem_tree, hf_ctlv_language, tvb, pos, len, ENC_ASCII|ENC_NA);
break;
case 0x2e:
proto_tree_add_item(elem_tree, hf_ctlv_me_status, tvb, pos, 1, ENC_NA);
proto_tree_add_item(elem_tree, hf_ctlv_timing_adv, tvb, pos+1, 1, ENC_NA);
break;
case 0x2f:
{
guint64 rid = tvb_get_ntoh40(tvb, pos);
proto_tree_add_uint64(elem_tree, hf_ctlv_aid_rid, tvb, pos, 5, rid);
if (rid == AID_RFID_ETSI) {
proto_tree_add_item(elem_tree, hf_ctlv_aid_pix_app_code_etsi, tvb, pos+5, 2, ENC_BIG_ENDIAN);
} else if (rid == AID_RFID_3GPP) {
proto_tree_add_item(elem_tree, hf_ctlv_aid_pix_app_code_3gpp, tvb, pos+5, 2, ENC_BIG_ENDIAN);
} else if (rid == AID_RFID_3GPP2) {
proto_tree_add_item(elem_tree, hf_ctlv_aid_pix_app_code_3gpp2, tvb, pos+5, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(elem_tree, hf_ctlv_aid_pix_app_code, tvb, pos+5, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(elem_tree, hf_ctlv_aid_pix_country_code, tvb, pos+7, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_aid_pix_app_prov_code, tvb, pos+9, 3, ENC_BIG_ENDIAN);
if (len > 12) {
proto_tree_add_item(elem_tree, hf_ctlv_aid_pix_app_prov_field, tvb, pos+12, len-12, ENC_NA);
}
}
break;
case 0x32:
for (i = 0; i < len; i++)
proto_tree_add_item(elem_tree, hf_ctlv_bearer, tvb, pos+i, 1, ENC_NA);
break;
case 0x35:
g8 = tvb_get_guint8(tvb, pos);
proto_tree_add_uint(elem_tree, hf_ctlv_bearer_descr, tvb, pos, 1, g8);
switch (g8) {
case 0x01:
proto_tree_add_item(elem_tree, hf_ctlv_bearer_csd_data_rate, tvb, pos+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_csd_bearer_serv, tvb, pos+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_csd_conn_elem, tvb, pos+3, 1, ENC_BIG_ENDIAN);
break;
case 0x02:
proto_tree_add_item(elem_tree, hf_ctlv_bearer_gprs_precedence, tvb, pos+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_gprs_delay, tvb, pos+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_gprs_reliability, tvb, pos+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_gprs_peak, tvb, pos+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_gprs_mean, tvb, pos+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_gprs_prot_type, tvb, pos+6, 1, ENC_BIG_ENDIAN);
break;
case 0x09:
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_traffic_class, tvb, pos+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_max_bitrate_ul, tvb, pos+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_max_bitrate_dl, tvb, pos+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_guaranteed_bitrate_ul, tvb, pos+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_guaranteed_bitrate_dl, tvb, pos+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_delivery_order, tvb, pos+10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_max_sdu_size, tvb, pos+11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_sdu_error_ratio, tvb, pos+12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_residual_bit_error_ratio, tvb, pos+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_delivery_erroneous_sdus, tvb, pos+14, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_transfer_delay, tvb, pos+15, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_traffic_handling_prio, tvb, pos+16, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_pdp_type, tvb, pos+1, 17, ENC_BIG_ENDIAN);
break;
case 0x0a:
break;
case 0x0b:
de_esm_qos(tvb, elem_tree, pinfo, pos+1, len-2, NULL, 0);
proto_tree_add_item(elem_tree, hf_ctlv_bearer_utran_pdp_type, tvb, pos+len-1, 1, ENC_BIG_ENDIAN);
break;
default:
if (len > 1) {
proto_tree_add_item(elem_tree, hf_ctlv_bearer_params, tvb, pos+1, len-1, ENC_NA);
}
break;
}
break;
case 0x39:
proto_tree_add_item(elem_tree, hf_ctlv_buffers_size, tvb, pos, 2, ENC_BIG_ENDIAN);
break;
case 0x3c:
if (len < 3)
break;
proto_tree_add_item(elem_tree, hf_ctlv_transport_ptype, tvb, pos, 1, ENC_NA);
proto_tree_add_item(elem_tree, hf_ctlv_transport_port, tvb, pos+1, 2, ENC_BIG_ENDIAN);
break;
case 0x3e:
g8 = tvb_get_guint8(tvb, pos);
proto_tree_add_uint(elem_tree, hf_ctlv_other_address_coding, tvb, pos, 1, g8);
switch (g8) {
case 0x21:
proto_tree_add_item(elem_tree, hf_ctlv_other_address_ipv4, tvb, pos+1, 4, ENC_NA);
break;
case 0x57:
proto_tree_add_item(elem_tree, hf_ctlv_other_address_ipv6, tvb, pos+1, 16, ENC_NA);
break;
default:
break;
}
break;
case 0x3f:
for (i = 0; i < len; i++)
proto_tree_add_item(elem_tree, hf_ctlv_access_tech, tvb, pos+i, 1, ENC_NA);
break;
case 0x47:
de_sm_apn(tvb, elem_tree, pinfo, pos, len, NULL, 0);
break;
case 0x69:
proto_tree_add_item(elem_tree, hf_ctlv_utran_eutran_meas_qual, tvb, pos, 1, ENC_NA);
break;
case 0x73:
de_gmm_rai(tvb, elem_tree, pinfo, pos, len, NULL, 0);
break;
case 0x74:
proto_tree_add_item(elem_tree, hf_ctlv_upd_attach_type, tvb, pos, 1, ENC_NA);
break;
case 0x76:
if (ims_event) {
proto_tree_add_item(elem_tree, hf_ctlv_iari, tvb, pos, len, ENC_UTF_8 | ENC_NA);
}
break;
case 0x77:
if (ims_event) {
i = 0;
while (i < len) {
if (tvb_get_guint8(tvb, pos+i) == 0x80) {
g8 = tvb_get_guint8(tvb, pos+i+1);
proto_tree_add_item(elem_tree, hf_ctlv_impu, tvb, pos+i+2, g8, ENC_UTF_8 | ENC_NA);
i += 2+g8;
} else {
break;
}
}
}
break;
case 0x78:
if (ims_event) {
guint8 *status_code = tvb_get_string(wmem_packet_scope(), tvb, pos, len);
proto_tree_add_string_format_value(elem_tree, hf_ctlv_ims_status_code, tvb, pos, len,
status_code, "%s (%s)", status_code, str_to_str(status_code, ims_status_code, "Unknown"));
}
break;
case 0x79:
for (i = 0; i < len; i+=3) {
dissect_e212_mcc_mnc(tvb, pinfo, elem_tree, pos+3*i, TRUE);
}
break;
case 0x7c:
nas_esm_pdn_con_req(tvb, elem_tree, pinfo, pos, len);
break;
case 0x7d:
de_emm_trac_area_id(tvb, elem_tree, pinfo, pos, 5, NULL, 0);
break;
default:
break;
}
pos += len;
}
return length;
}
void
proto_register_card_app_toolkit(void)
{
static hf_register_info hf[] = {
{ &hf_cat_tlv,
{ "COMPREHENSIVE-TLV", "etsi_cat.comp_tlv",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_devid_src,
{ "Source Device ID", "etsi_cat.comp_tlv.src_dev",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &dev_id_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_devid_dst,
{ "Destination Device ID", "etsi_cat.comp_tlv.dst_dev",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &dev_id_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_cmd_nr,
{ "Command Number", "etsi_cat.comp_tlv.cmd_nr",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_cmd_type,
{ "Command Type", "etsi_cat.comp_tlv.cmd_type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &cmd_type_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_cmd_qual_refresh,
{ "Command Qualifier", "etsi_cat.comp_tlv.cmd_qual.refresh",
FT_UINT8, BASE_HEX, VALS(cmd_qual_refresh_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_cmd_qual_send_short_msg,
{ "Command Qualifier", "etsi_cat.comp_tlv.cmd_qual.send_short_msg",
FT_BOOLEAN, 8, TFS(&cmd_qual_send_short_msg_value), 0x01,
NULL, HFILL },
},
{ &hf_ctlv_cmd_qual_loci,
{ "Command Qualifier", "etsi_cat.comp_tlv.cmd_qual.loci",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &cmd_qual_loci_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_cmd_qual_timer_mgmt,
{ "Command Qualifier", "etsi_cat.comp_tlv.cmd_qual.timer_mgmt",
FT_UINT8, BASE_HEX, VALS(cmd_qual_timer_mgmt_vals), 0x03,
NULL, HFILL },
},
{ &hf_ctlv_cmd_qual_send_data,
{ "Command Qualifier", "etsi_cat.comp_tlv.cmd_qual.send_data",
FT_BOOLEAN, 8, TFS(&cmd_qual_send_data_value), 0x01,
NULL, HFILL },
},
{ &hf_ctlv_cmd_qual,
{ "Command Qualifier", "etsi_cat.comp_tlv.cmd_qual",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_dur_time_intv,
{ "Time Interval", "etsi_cat.comp_tlv.time_interval",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_dur_time_unit,
{ "Time Unit", "etsi_cat.comp_tlv.time_unit",
FT_UINT8, BASE_HEX, VALS(time_unit_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_result_gen,
{ "Result", "etsi_cat.comp_tlv.result",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &result_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_result_term,
{ "Additional information", "etsi_cat.comp_tlv.result.term",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &result_term_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_result_launch_browser,
{ "Additional information", "etsi_cat.comp_tlv.result.launch_browser",
FT_UINT8, BASE_HEX, VALS(result_launch_browser_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_result_multiplecard,
{ "Additional information", "etsi_cat.comp_tlv.result.multiplecard",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &result_multiplecard_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_result_cc_ctrl_mo_sm_ctrl,
{ "Additional information", "etsi_cat.comp_tlv.result.cc_ctrl_mo_sm_ctrl",
FT_UINT8, BASE_HEX, VALS(result_cc_ctrl_mo_sm_ctrl_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_result_bip,
{ "Additional information", "etsi_cat.comp_tlv.result.bip",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &result_bip_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_result_frames_cmd,
{ "Additional information", "etsi_cat.comp_tlv.result.frames_cmd",
FT_UINT8, BASE_HEX, VALS(result_frames_cmd_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_text_string_enc,
{ "Text String Encoding", "etsi_cat.comp_tlv.text_encoding",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(text_encoding_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_text_string,
{ "Text String", "etsi_cat.comp_tlv.text",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_event,
{ "Event", "etsi_cat.comp_tlv.event",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &event_list_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_tone,
{ "Tone", "etsi_cat.comp_tlv.tone",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &tone_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_loc_status,
{ "Location Status", "etsi_cat.comp_tlv.loc_status",
FT_UINT8, BASE_HEX, VALS(loc_status_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_timer_val_hr,
{ "Hours", "etsi_cat.comp_tlv.timer_val.hr",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_timer_val_min,
{ "Minutes", "etsi_cat.comp_tlv.timer_val.min",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_timer_val_sec,
{ "Seconds", "etsi_cat.comp_tlv.timer_val.sec",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_date_time_yr,
{ "Year", "etsi_cat.comp_tlv.date_time.yr",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_date_time_mo,
{ "Month", "etsi_cat.comp_tlv.date_time.mo",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_date_time_day,
{ "Day", "etsi_cat.comp_tlv.date_time.day",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_date_time_hr,
{ "Hours", "etsi_cat.comp_tlv.date_time.hr",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_date_time_min,
{ "Minutes", "etsi_cat.comp_tlv.date_time.min",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_date_time_sec,
{ "Seconds", "etsi_cat.comp_tlv.date_time.sec",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_date_time_tz,
{ "Time Zone", "etsi_cat.comp_tlv.date_time.tz",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_at_cmd,
{ "AT Command", "etsi_cat.comp_tlv.at_cmd",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_at_rsp,
{ "AT Response", "etsi_cat.comp_tlv.at_rsp",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_language,
{ "Language", "etsi_cat.comp_tlv.language",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_me_status,
{ "ME Status", "etsi_cat.comp_tlv.me_status",
FT_UINT8, BASE_DEC, VALS(me_status_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_timing_adv,
{ "Timing Advance", "etsi_cat.comp_tlv.timing_adv",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_aid_rid,
{ "RID", "etsi_cat.comp_tlv.aid.rid",
FT_UINT64, BASE_HEX|BASE_VAL64_STRING, VALS64(aid_rid_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_aid_pix_app_code_etsi,
{ "PIX Application Code", "etsi_cat.comp_tlv.aid.pix.app_code",
FT_UINT16, BASE_HEX, VALS(aid_pix_app_code_etsi_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_aid_pix_app_code_3gpp,
{ "PIX Application Code", "etsi_cat.comp_tlv.aid.pix.app_code",
FT_UINT16, BASE_HEX, VALS(aid_pix_app_code_3gpp_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_aid_pix_app_code_3gpp2,
{ "PIX Application Code", "etsi_cat.comp_tlv.aid.pix.app_code",
FT_UINT16, BASE_HEX, VALS(aid_pix_app_code_3gpp2_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_aid_pix_app_code,
{ "PIX Application Code", "etsi_cat.comp_tlv.aid.pix.app_code",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_aid_pix_country_code,
{ "PIX Country Code", "etsi_cat.comp_tlv.aid.pix.country_code",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_aid_pix_app_prov_code,
{ "PIX Application Provider Code", "etsi_cat.comp_tlv.aid.pix.app_prov_code",
FT_UINT24, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_aid_pix_app_prov_field,
{ "PIX Application Provider Field", "etsi_cat.comp_tlv.aid.pix.app_prov_field",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer,
{ "Bearer", "etsi_cat.comp_tlv.bearer",
FT_UINT8, BASE_HEX, VALS(bearer_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_descr,
{ "Bearer Description", "etsi_cat.comp_tlv.bearer.descr",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &bearer_descr_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_csd_data_rate,
{ "Data Rate", "etsi_cat.comp_tlv.bearer.csd.data_rate",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &csd_data_rate_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_csd_bearer_serv,
{ "Bearer Service", "etsi_cat.comp_tlv.bearer.csd.bearer_serv",
FT_UINT8, BASE_DEC, VALS(csd_bearer_serv_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_csd_conn_elem,
{ "Connection Element", "etsi_cat.comp_tlv.bearer.csd.conn_elem",
FT_UINT8, BASE_DEC, VALS(csd_conn_elem_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_gprs_precedence,
{ "Precedence Class", "etsi_cat.comp_tlv.bearer.gprs.precedence",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_gprs_delay,
{ "Delay Class", "etsi_cat.comp_tlv.bearer.gprs.delay",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_gprs_reliability,
{ "Reliability Class", "etsi_cat.comp_tlv.bearer.gprs.reliability",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_gprs_peak,
{ "Peak Throughput Class", "etsi_cat.comp_tlv.bearer.gprs.peak",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_gprs_mean,
{ "Mean Throuhgput Class", "etsi_cat.comp_tlv.bearer.gprs.mean",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_gprs_prot_type,
{ "Packet Data Protocol Type", "etsi_cat.comp_tlv.bearer.gprs.prot_type",
FT_UINT8, BASE_DEC, VALS(gprs_prot_type_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_traffic_class,
{ "Traffic Class", "etsi_cat.comp_tlv.bearer.utran.traffic_class",
FT_UINT8, BASE_DEC, VALS(utran_traffic_class_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_max_bitrate_ul,
{ "Maximum Bitrate UL", "etsi_cat.comp_tlv.bearer.utran.max_bitrate_ul",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_max_bitrate_dl,
{ "Maximum Bitrate DL", "etsi_cat.comp_tlv.bearer.utran.max_bitrate_dl",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_guaranteed_bitrate_ul,
{ "Guaranteed Bitrate DL", "etsi_cat.comp_tlv.bearer.utran.guaranteed_bitrate_ul",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_guaranteed_bitrate_dl,
{ "Guaranteed Bitrate DL", "etsi_cat.comp_tlv.bearer.utran.guaranteed_bitrate_dl",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_delivery_order,
{ "Delivery Order", "etsi_cat.comp_tlv.bearer.utran.delivery_order",
FT_UINT8, BASE_DEC, VALS(utran_delivery_order_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_max_sdu_size,
{ "Maximum SDU Size", "etsi_cat.comp_tlv.bearer.utran.max_sdu_size",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_sdu_error_ratio,
{ "SDU Error Ratio", "etsi_cat.comp_tlv.bearer.utran.sdu_error_ratio",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_residual_bit_error_ratio,
{ "Residual Bit Error Ratio", "etsi_cat.comp_tlv.bearer.utran.residual_bit_error_ratio",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_delivery_erroneous_sdus,
{ "Delivery of Erroneous SDUs", "etsi_cat.comp_tlv.bearer.utran.delivery_erroneous_sdus",
FT_UINT8, BASE_DEC, VALS(utran_delivery_erroneous_sdus_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_transfer_delay,
{ "Transfer Delay", "etsi_cat.comp_tlv.bearer.utran.transfer_delay",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_traffic_handling_prio,
{ "Traffic Handling Priority", "etsi_cat.comp_tlv.bearer.utran.traffic_handling_prio",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_utran_pdp_type,
{ "PDP Type", "etsi_cat.comp_tlv.bearer.utran.pdp_type",
FT_UINT8, BASE_DEC, VALS(pdp_type_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_params,
{ "Bearer Parameters", "etsi_cat.comp_tlv.bearer.params",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_buffers_size,
{ "Buffer Size", "etsi_cat.comp_tlv.buffer_size",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_transport_ptype,
{ "Transport protocol type", "etsi_cat.comp_tlv.transport.ptype",
FT_UINT8, BASE_HEX, VALS(transport_ptype_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_transport_port,
{ "Transport port", "etsi_cat.comp_tlv.transport.port",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_other_address_coding,
{ "Coding of Type of address", "etsi_cat.comp_tlv.other_address.coding",
FT_UINT8, BASE_HEX, VALS(other_address_coding_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_other_address_ipv4,
{ "IPv4 address", "etsi_cat.comp_tlv.other_address.ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_other_address_ipv6,
{ "IPv4 address", "etsi_cat.comp_tlv.other_address.ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_access_tech,
{ "Access technology", "etsi_cat.comp_tlv.access_tech",
FT_UINT8, BASE_HEX, VALS(access_tech_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_utran_eutran_meas_qual,
{ "UTRAN/E-UTRAN Measurement Qualifier", "etsi_cat.comp_tlv.utran_eutran_meas_qual",
FT_UINT8, BASE_HEX, VALS(utran_eutran_meas_qual_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_upd_attach_type,
{ "UTRAN/E-UTRAN Measurement Qualifier", "etsi_cat.comp_tlv.upd_attach_type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &upd_attach_type_vals_ext, 0,
NULL, HFILL },
},
{ &hf_ctlv_loci_lac,
{ "Location Area Code / Tracking Area Code", "etsi_cat.comp_tlv.loci.lac",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_loci_cell_id,
{ "Cell ID", "etsi_cat.comp_tlv.loci.cell_id",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_loci_ext_cell_id,
{ "Extended Cell ID", "etsi_cat.comp_tlv.loci.ext_cell_id",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_iari,
{ "IARI", "etsi_cat.comp_tlv.iari",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_impu,
{ "IMPU", "etsi_cat.comp_tlv.impu",
FT_STRING, STR_UNICODE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_ims_status_code,
{ "IMS Status-Code", "etsi_cat.comp_tlv.ims_status_code",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL },
}
};
static gint *ett[] = {
&ett_cat,
&ett_elem,
};
proto_cat = proto_register_protocol("Card Application Tookit ETSI TS 102.223", "ETSI CAT",
"etsi_cat");
proto_register_field_array(proto_cat, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("etsi_cat", dissect_cat, proto_cat);
}
void
proto_reg_handoff_card_app_toolkit(void)
{
gsm_sms_handle = find_dissector("gsm_sms");
}
