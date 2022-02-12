static guint16
de_bmaple_apdu(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 apdu_protocol_id;
tvbuff_t *APDU_tvb;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len, "APDU");
apdu_protocol_id = tvb_get_guint8(tvb,curr_offset);
proto_tree_add_item(tree, hf_gsm_bssmap_le_apdu_protocol_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch(apdu_protocol_id){
case 1:
APDU_tvb = tvb_new_subset_length(tvb, curr_offset+1, len-1);
if(gsm_bsslap_handle)
call_dissector(gsm_bsslap_handle, APDU_tvb, pinfo, g_tree);
break;
case 2:
break;
case 3:
break;
default:
break;
}
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
de_bmaple_decihp_keys(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
gint bit_offset;
bit_offset = (offset<<3);
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_spare, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
bit_offset += 7;
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_ciphering_key_flag, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_current_deciphering_key_value, tvb, bit_offset, 56, ENC_NA);
bit_offset += 56;
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_next_deciphering_key_value, tvb, bit_offset, 56, ENC_NA);
return(len);
}
static guint16
de_bmaple_req_gps_ass_data(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_bssmap_le_acq_ass, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_bssmap_le_ref_time, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_bssmap_le_ref_loc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_bssmap_le_dgps_corr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_bssmap_le_nav_mod, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_bssmap_le_iono_mod, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_bssmap_le_utc_mod, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_bssmap_le_almanac, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_gsm_bssmap_le_ephemeris_ext_chk, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_bssmap_le_ephemeris_ext, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_bssmap_le_real_time_int, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_text(tree, tvb, curr_offset, len-2, "Satellite related data Not decoded yet");
return(len);
}
static guint16
de_bmaple_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_bssmap_le_lcs_cause_value, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if (len == 2)
{
proto_tree_add_item(tree, hf_gsm_bssmap_le_diagnostic_value, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
return(curr_offset - offset);
}
static guint16
de_bmaple_client(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 bitCount;
bitCount = offset<<3;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_client_category, tvb, bitCount, 4, ENC_BIG_ENDIAN);
bitCount = bitCount + 4;
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_client_subtype, tvb, bitCount, 4, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_bmaple_lcs_qos(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint64 verticalCoordIndicator, velocityRequested, horizontalAccuracyIndicator, verticalAccuracyIndicator;
guint16 bitCount;
bitCount = offset << 3;
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_spare, tvb, bitCount, 6, ENC_BIG_ENDIAN);
bitCount = bitCount + 6;
proto_tree_add_bits_ret_val(tree, hf_gsm_bssmap_le_velocity_requested, tvb, bitCount, 1, &velocityRequested, ENC_BIG_ENDIAN);
bitCount++;
proto_tree_add_bits_ret_val(tree, hf_gsm_bssmap_le_vertical_coordinate_indicator, tvb, bitCount, 1, &verticalCoordIndicator, ENC_BIG_ENDIAN);
bitCount++;
proto_tree_add_bits_ret_val(tree, hf_gsm_bssmap_le_horizontal_accuracy_indicator, tvb, bitCount, 1, &horizontalAccuracyIndicator, ENC_BIG_ENDIAN);
bitCount++;
if(horizontalAccuracyIndicator == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_horizontal_accuracy, tvb, bitCount, 7, ENC_BIG_ENDIAN);
bitCount = bitCount + 7;
}
else
{
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_spare, tvb, bitCount, 7, ENC_BIG_ENDIAN);
bitCount = bitCount + 7;
}
proto_tree_add_bits_ret_val(tree, hf_gsm_bssmap_le_vertical_accuracy_indicator, tvb, bitCount, 1, &verticalAccuracyIndicator, ENC_BIG_ENDIAN);
bitCount++;
if(verticalAccuracyIndicator == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_vertical_accuracy, tvb, bitCount, 7, ENC_BIG_ENDIAN);
bitCount = bitCount + 7;
}
else
{
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_spare, tvb, bitCount, 7, ENC_BIG_ENDIAN);
bitCount = bitCount + 7;
}
proto_tree_add_bits_item(tree, hf_gsm_bssmap_le_response_time_category, tvb, bitCount, 2, ENC_BIG_ENDIAN);
return(len);
}
static guint16
de_bmaple_pos_dta(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *data_tvb;
guint32 curr_offset;
curr_offset = offset;
data_tvb = tvb_new_subset_length(tvb, curr_offset, len);
dissect_geographical_description(data_tvb, pinfo, tree);
return(len);
}
static guint16
be_lcs_capability(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_text(tree, tvb, offset, len, "Not decoded yet");
return len;
}
static guint16
be_packet_meas_rep(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_text(tree, tvb, offset, len, "Not decoded yet");
return len;
}
static guint16
be_measured_cell_identity(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_text(tree, tvb, offset, len, "Not decoded yet");
return len;
}
static void
bssmap_le_perf_loc_request(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BSSMAP_LE_LOCATION_TYPE, GSM_A_PDU_TYPE_BSSMAP, BE_LOC_TYPE, NULL)
ELEM_MAND_TLV(BSSMAP_LE_CELL_IDENTIFIER, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_OPT_TLV(BSSMAP_LE_CLASSMARK_INFORMATION_TYPE_3, GSM_A_PDU_TYPE_BSSMAP, BE_CM_INFO_3, NULL);
ELEM_OPT_TLV(BSSMAP_LE_LCS_CLIENT_TYPE, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCS_CLIENT_TYPE, NULL);
ELEM_OPT_TLV(BSSMAP_LE_CHOSEN_CHANNEL, GSM_A_PDU_TYPE_BSSMAP, BE_CHOSEN_CHAN, NULL);
ELEM_OPT_TLV(BSSMAP_LE_LCS_PRIORITY, GSM_A_PDU_TYPE_BSSMAP, BE_LCS_PRIO, NULL);
ELEM_OPT_TLV(BSSMAP_LE_LCS_QOS, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCSQOS, NULL);
ELEM_OPT_TLV(BSSMAP_LE_REQUESTED_GPS_ASSISTANCE_DATA, GSM_A_PDU_TYPE_BSSMAP, BE_GPS_ASSIST_DATA, NULL);
ELEM_MAND_TELV(BSSMAP_LE_APDU, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_APDU, NULL);
ELEM_OPT_TLV(BSSMAP_LE_LCS_CAPABILITY, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCS_CAPABILITY, NULL);
ELEM_OPT_TLV(BSSMAP_LE_PACKET_MEASUREMENT_REPORT, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_PACKET_MEAS_REP, NULL);
ELEM_OPT_TLV(BSSMAP_LE_CELL_IDENTITY_LIST, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_MEAS_CELL_ID, NULL);
ELEM_OPT_TLV(BSSMAP_LE_IMSI, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_IMSI, NULL);
ELEM_OPT_TLV(BSSMAP_LE_IMEI, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_IMEI, NULL);
ELEM_OPT_TLV(BSSMAP_LE_GANSS_LOCATION_TYPE, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_GANSS_LOC_TYPE, NULL);
ELEM_OPT_TLV(BSSMAP_LE_REQUESTED_GANSS_ASSISTANCE_DATA, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_REQ_GNSS_ASSIST_D, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_le_perf_loc_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(BSSMAP_LE_GEOGRAPHIC_LOCATION, BSSAP_PDU_TYPE_BSSMAP, BE_LOC_EST, NULL);
ELEM_OPT_TLV(BSSMAP_LE_POSITIONING_DATA, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_POS_DATA, NULL);
ELEM_OPT_TLV(BSSMAP_LE_DECIPHERING_KEYS, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_DECIPH_KEYS, NULL);
ELEM_OPT_TLV(BSSMAP_LE_LCS_CAUSE, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_LCS_CAUSE, NULL);
ELEM_OPT_TLV(BSSMAP_LE_VELOCITY_DATA, BSSAP_PDU_TYPE_BSSMAP, BE_VEL_EST, NULL);
ELEM_OPT_TLV(BSSMAP_LE_GANSS_POSITIONING_DATA, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_GANSS_POS_DATA, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_le_connection_oriented(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TELV(BSSMAP_LE_APDU, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_APDU, NULL);
ELEM_OPT_TLV(BSSMAP_LE_SEGMENTATION, BSSAP_PDU_TYPE_BSSMAP, BE_SEG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
bssmap_le_perf_loc_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_TLV(BSSMAP_LE_CELL_IDENTIFIER, GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_MAND_TELV(BSSMAP_LE_APDU, GSM_PDU_TYPE_BSSMAP_LE, DE_BMAPLE_APDU, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
void
dissect_bssmap_le(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
static gsm_a_tap_rec_t tap_rec[4];
static gsm_a_tap_rec_t *tap_p;
static guint tap_current=0;
guint8 oct;
guint32 offset, saved_offset;
guint32 len;
gint idx;
proto_item *bssmap_le_item = NULL;
proto_tree *bssmap_le_tree = NULL;
const gchar *str;
sccp_msg_info_t *sccp_msg_p;
sccp_msg_p = pinfo->sccp_info;
if (!(sccp_msg_p && sccp_msg_p->data.co.assoc)) {
sccp_msg_p = NULL;
}
col_append_str(pinfo->cinfo, COL_INFO, "(BSSMAP LE) ");
tap_current++;
if (tap_current >= 4)
{
tap_current = 0;
}
tap_p = &tap_rec[tap_current];
offset = 0;
saved_offset = offset;
g_tree = tree;
len = tvb_length(tvb);
oct = tvb_get_guint8(tvb, offset++);
str = try_val_to_str_idx((guint32) oct, gsm_bssmap_le_msg_strings, &idx);
if (sccp_msg_p && !sccp_msg_p->data.co.label) {
sccp_msg_p->data.co.label = wmem_strdup(wmem_file_scope(),
val_to_str((guint32) oct,
gsm_bssmap_le_msg_strings, "BSSMAP LE(0x%02x)"));
}
if (str == NULL)
{
bssmap_le_item =
proto_tree_add_protocol_format(tree, proto_bssmap_le, tvb, 0, len,
"Lb - I/F BSSMAP LE - Unknown BSSMAP Message Type (0x%02x)",
oct);
bssmap_le_tree = proto_item_add_subtree(bssmap_le_item, ett_bssmap_le_msg);
}
else
{
bssmap_le_item =
proto_tree_add_protocol_format(tree, proto_bssmap_le, tvb, 0, -1,
"Lb - I/F BSSMAP LE - %s",
str);
bssmap_le_tree = proto_item_add_subtree(bssmap_le_item, ett_gsm_bssmap_le_msg[idx]);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", str);
proto_tree_add_uint_format(bssmap_le_tree, hf_gsm_bssmap_le_msg_type,
tvb, saved_offset, 1, oct, "Message Type %s",str);
}
tap_p->pdu_type = BSSAP_PDU_TYPE_BSSMAP;
tap_p->message_type = oct;
tap_queue_packet(gsm_a_tap, pinfo, tap_p);
if (str == NULL) return;
if (offset >= len) return;
if (bssmap_le_msg_fcn[idx] == NULL)
{
proto_tree_add_text(bssmap_le_tree,
tvb, offset, len - offset,
"Message Elements");
}
else
{
(*bssmap_le_msg_fcn[idx])(tvb, bssmap_le_tree, pinfo, offset, len - offset);
}
}
void
proto_register_gsm_bssmap_le(void)
{
guint i;
guint last_offset;
static hf_register_info hf[] = {
{ &hf_gsm_bssmap_le_msg_type,
{ "BSSMAP LE Message Type", "gsm_bssmap_le.msgtype",
FT_UINT8, BASE_HEX, VALS(gsm_bssmap_le_msg_strings), 0x0,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_elem_id,
{ "Element ID", "gsm_bssmap_le.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_apdu_protocol_id,
{ "Protocol ID", "gsm_bssmap_le.apdu_protocol_id",
FT_UINT8, BASE_DEC, VALS(gsm_apdu_protocol_id_strings), 0x0,
"APDU embedded protocol id", HFILL }
},
{ &hf_gsm_bssmap_le_spare,
{ "Spare", "gsm_bssmap_le.spare",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_ciphering_key_flag,
{ "Ciphering Key Flag", "gsm_bssmap_le.decipheringKeys.flag",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_current_deciphering_key_value,
{ "Current Deciphering Key Value", "gsm_bssmap_le.decipheringKeys.current",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL,
HFILL}
},
{ &hf_gsm_bssmap_le_next_deciphering_key_value,
{ "Next Deciphering Key Value", "gsm_bssmap_le.decipheringKeys.next",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_acq_ass,
{ "Acquisition Assistance", "gsm_bssmap_le.acq_ass",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x80,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_ref_time,
{ "Reference Time", "gsm_bssmap_le.ref_time",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x40,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_ref_loc,
{ "Reference Location", "gsm_bssmap_le.ref_loc",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x20,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_dgps_corr,
{ "DGPS Corrections", "gsm_bssmap_le.gps_corr",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x08,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_nav_mod,
{ "Navigation Model", "gsm_bssmap_le.nav_mod",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x10,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_iono_mod,
{ "Ionospheric Model", "gsm_bssmap_le.iono_mod",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x04,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_utc_mod,
{ "UTC Model", "gsm_bssmap_le.utc_mod",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x02,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_almanac,
{ "Almanac", "gsm_bssmap_le.almanac",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x01,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_ephemeris_ext_chk,
{ "Ephemeris Extension Check", "gsm_bssmap_le.ephemeris_ext_chk",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x04,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_ephemeris_ext,
{ "Ephemeris Extension", "gsm_bssmap_le.ephemeris_ext",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x02,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_real_time_int,
{ "Real-Time Integrity", "gsm_bssmap_le.real_time_int",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x01,
NULL, HFILL }
},
{ &hf_gsm_bssmap_le_lcs_cause_value,
{ "Cause Value", "gsm_bssmap_le.lcsCauseValue",
FT_UINT8, BASE_HEX, VALS(bssmap_le_lcs_cause_values), 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_diagnostic_value,
{ "Diagnostic Value", "gsm_bssmap_le.diagnosticValue",
FT_UINT8, BASE_HEX, VALS(bssmap_le_position_method_failure_diagnostic_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_client_category,
{ "Client Category", "gsm_bssmap_le.lcsClientType.clientCategory",
FT_UINT8, BASE_HEX, VALS(bssmap_le_client_category), 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_client_subtype,
{ "Client Subtype", "gsm_bssmap_le.lcsClientType.clientSubtype",
FT_UINT8, BASE_HEX, VALS(bssmap_le_client_subtype), 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_velocity_requested,
{ "Velocity Requested", "gsm_bssmap_le.lcsQos.velocityRequested",
FT_UINT8, BASE_HEX, VALS(bssmap_le_velocity_requested_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_vertical_coordinate_indicator,
{ "Vertical Coordinate Indicator", "gsm_bssmap_le.lcsQos.verticalCoordinateIndicator",
FT_UINT8, BASE_HEX, VALS(bssmap_le_vertical_coordinate_indicator_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_horizontal_accuracy_indicator,
{ "Horizontal Accuracy Indicator", "gsm_bssmap_le.lcsQos.horizontalAccuracyIndicator",
FT_UINT8, BASE_HEX, VALS(bssmap_le_horizontal_accuracy_indicator_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_horizontal_accuracy,
{ "Horizontal Accuracy", "gsm_bssmap_le.lcsQos.horizontalAccuracy",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_vertical_accuracy,
{ "Vertical Accuracy", "gsm_bssmap_le.lcsQos.verticalAccuracy",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_vertical_accuracy_indicator,
{ "Vertical Accuracy Indicator", "gsm_bssmap_le.lcsQos.verticalAccuracyIndicator",
FT_UINT8, BASE_HEX, VALS(bssmap_le_vertical_accuracy_indicator_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_bssmap_le_response_time_category,
{ "Response Time Category", "gsm_bssmap_le.lcsQos.responseTimeCategory",
FT_UINT8, BASE_HEX, VALS(bssmap_le_response_time_definitions_vals), 0x0,
NULL, HFILL}
},
};
#define NUM_INDIVIDUAL_ELEMS 1
gint *ett[NUM_INDIVIDUAL_ELEMS + NUM_GSM_BSSMAP_LE_MSG +
NUM_GSM_BSSMAP_LE_ELEM];
ett[0] = &ett_bssmap_le_msg;
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_GSM_BSSMAP_LE_MSG; i++, last_offset++)
{
ett_gsm_bssmap_le_msg[i] = -1;
ett[last_offset] = &ett_gsm_bssmap_le_msg[i];
}
for (i=0; i < NUM_GSM_BSSMAP_LE_ELEM; i++, last_offset++)
{
ett_gsm_bssmap_le_elem[i] = -1;
ett[last_offset] = &ett_gsm_bssmap_le_elem[i];
}
proto_bssmap_le =
proto_register_protocol("Lb-I/F BSSMAP LE", "GSM BSSMAP LE", "gsm_bssmap_le");
proto_register_field_array(proto_bssmap_le, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gsm_bssmap_le", dissect_bssmap_le, proto_bssmap_le);
}
void
proto_reg_handoff_gsm_bssmap_le(void)
{
dissector_handle_t bssmap_le_handle;
bssmap_le_handle = find_dissector("gsm_bssmap_le");
dissector_add_uint("bssap.pdu_type", BSSAP_PDU_TYPE_BSSMAP, bssmap_le_handle);
gsm_bsslap_handle = find_dissector("gsm_bsslap");
}
