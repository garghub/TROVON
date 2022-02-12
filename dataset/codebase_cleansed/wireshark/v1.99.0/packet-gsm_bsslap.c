static guint16
de_ta(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_bsslap_ta, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_bsslap_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_bsslap_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_rrlp_flg(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_bsslap_rrlp_flg, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_rrlp_ie(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
tvbuff_t *rrlp_tvb;
guint16 length;
length = tvb_get_ntohs(tvb, offset);
curr_offset = offset + 2;
if (length > 0)
{
rrlp_tvb = tvb_new_subset_length(tvb, curr_offset, length);
if (bsslap_rrlp_handle)
call_dissector(bsslap_rrlp_handle, rrlp_tvb, pinfo, tree);
}
curr_offset += length;
return(curr_offset - offset);
}
static guint16
de_cell_id_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 consumed;
guint8 cell_id_disc;
guint8 num_cells;
proto_item *item = NULL;
proto_tree *subtree = NULL;
curr_offset = offset;
cell_id_disc = tvb_get_guint8(tvb,curr_offset);
num_cells = 0;
while(len>0){
num_cells++;
consumed = 0;
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, -1, ett_bsslap_cell_list, &item, "Cell %u", num_cells);
if (add_string)
add_string[0] = '\0';
proto_tree_add_item(subtree, hf_gsm_bsslap_cell_id_disc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
len--;
switch(cell_id_disc){
case 0:
consumed+= be_cell_id_aux(tvb, subtree, pinfo, curr_offset, len, NULL, 0, 0);
break;
case 1:
consumed+= be_cell_id_aux(tvb, subtree, pinfo, curr_offset, len, NULL, 0, 1);
break;
case 2:
case 3:
default:
proto_tree_add_text(subtree,tvb, curr_offset, len,"Not decoded yet");
consumed = len;
break;
}
curr_offset += consumed;
len-=consumed;
proto_item_set_len(item, consumed+1);
}
return(curr_offset - offset);
}
static guint16
de_enh_meas_rep(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree,tvb, curr_offset, len,"Not decoded yet");
return(len);
}
static guint16
de_lac(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_bsslap_lac, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_ms_pow(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_bsslap_ms_pow, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_delta_time(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_bsslap_timer_value, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_blap_enc_key(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree,tvb, curr_offset, 8,"Encryption Key (Kc)");
curr_offset = curr_offset + 8;
return(curr_offset - offset);
}
static guint16
de_poll_rep(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_bsslap_poll_rep, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_pkt_ch_desc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree,tvb, curr_offset, len,"Not decoded yet");
return(len);
}
static guint16
de_tfi(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_bsslap_tfi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static void
dissect_gsm_bsslap_ta_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = tvb_length_remaining(tvb,offset);
ELEM_MAND_TV(BSSLAP_PARAM_CELL_IDENTITY, GSM_A_PDU_TYPE_COMMON, DE_CELL_ID, "Serving Cell Identity");
ELEM_MAND_TV(BSSLAP_PARAM_TIMING_ADVANCE, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_TA, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_MEASUREMENT_REPORT, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_MEAS_REP, " BSSLAP");
ELEM_OPT_TLV(BSSLAP_PARAM_ENHANCED_MEASUREMENT_REPORT, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_ENH_MEAS_REP, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_CELL_IDENTITY_LIST, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_CELL_ID_LIST, "-Measured Cell");
return;
}
static void
dissect_gsm_bsslap_reject(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = tvb_length_remaining(tvb,offset);
ELEM_MAND_TV(BSSLAP_PARAM_CAUSE, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_CAUSE,NULL);
return;
}
static void
dissect_gsm_bsslap_reset(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = tvb_length_remaining(tvb,offset);
ELEM_MAND_TV(BSSLAP_PARAM_CELL_IDENTITY, GSM_A_PDU_TYPE_COMMON, DE_CELL_ID, NULL);
ELEM_MAND_TV(BSSLAP_PARAM_TIMING_ADVANCE, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_TA, NULL);
ELEM_MAND_TV(BSSLAP_PARAM_CHANNEL_DESCRIPTION,GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC,NULL);
ELEM_MAND_TV(BSSLAP_PARAM_CAUSE, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_CAUSE,NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_MEASUREMENT_REPORT, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_MEAS_REP, " BSSLAP");
ELEM_OPT_TLV(BSSLAP_PARAM_ENHANCED_MEASUREMENT_REPORT, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_ENH_MEAS_REP, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_CELL_IDENTITY_LIST, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_CELL_ID_LIST, "-Measured Cell");
ELEM_OPT_TLV(BSSLAP_PARAM_LOCATION_AREA_CODE, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_LAC, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_FREQUENCY_LIST, GSM_A_PDU_TYPE_RR, DE_RR_FREQ_LIST, NULL);
ELEM_OPT_TV(BSSLAP_PARAM_CHANNEL_MODE, GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_MULTIRATE_CONFIGURATION, GSM_A_PDU_TYPE_RR, DE_RR_MULTIRATE_CONF, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_PACKET_CHANNEL_DESCRIPTION, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_PKT_CH_DESC, NULL);
ELEM_OPT_TV(BSSLAP_PARAM_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI,NULL);
ELEM_OPT_TV(BSSLAP_PARAM_TFI, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_TFI,NULL);
ELEM_OPT_TV(BSSLAP_PARAM_STARTING_TIME, GSM_A_PDU_TYPE_RR, DE_RR_STARTING_TIME, "TBF Starting Time");
ELEM_OPT_TV(BSSLAP_PARAM_ENCRYPTION_KEY, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_ENC_KEY,NULL);
ELEM_OPT_TV(BSSLAP_PARAM_CIPHER_MODE_SETTING, GSM_A_PDU_TYPE_RR, DE_RR_CIP_MODE_SET, NULL);
return;
}
static void
dissect_gsm_bsslap_abort(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = tvb_length_remaining(tvb,offset);
ELEM_MAND_TV(BSSLAP_PARAM_CAUSE, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_CAUSE,NULL);
return;
}
static void
dissect_gsm_bsslap_ta_layer3(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = tvb_length_remaining(tvb,offset);
ELEM_MAND_TV(BSSLAP_PARAM_TIMING_ADVANCE, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_TA, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_MEASUREMENT_REPORT, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_MEAS_REP, " BSSLAP");
ELEM_OPT_TLV(BSSLAP_PARAM_ENHANCED_MEASUREMENT_REPORT, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_ENH_MEAS_REP, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_CELL_IDENTITY_LIST, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_CELL_ID_LIST, "-Measured Cell");
return;
}
static void
dissect_gsm_bsslap_ms_pos_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = tvb_length_remaining(tvb,offset);
ELEM_MAND_TV(BSSLAP_PARAM_RRLP_FLAG, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_RRLP_FLG,"flag");
ELEM_MAND_TV(BSSLAP_PARAM_RRLP_IE, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_RRLP_IE,"RRLP Info");
return;
}
static void
dissect_gsm_bsslap_ms_pos_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = tvb_length_remaining(tvb,offset);
ELEM_MAND_TV(BSSLAP_PARAM_RRLP_FLAG, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_RRLP_FLG,"flag");
ELEM_MAND_TV(BSSLAP_PARAM_RRLP_IE, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_RRLP_IE,"RRLP Info");
ELEM_OPT_TV(BSSLAP_PARAM_TIMING_ADVANCE, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_TA, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_MEASUREMENT_REPORT, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_MEAS_REP, " BSSLAP");
ELEM_OPT_TLV(BSSLAP_PARAM_ENHANCED_MEASUREMENT_REPORT, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_ENH_MEAS_REP, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_CELL_IDENTITY_LIST, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_CELL_ID_LIST, "-Measured Cell");
return;
}
static void
dissect_gsm_bsslap_u_tdoa_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = tvb_length_remaining(tvb,offset);
ELEM_OPT_TV(BSSLAP_PARAM_DELTA_TIMER, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_DELTA_TIME, NULL);
ELEM_OPT_TV(BSSLAP_PARAM_POLLING_REPETITION, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_POLL_REP, NULL);
return;
}
static void
dissect_gsm_bsslap_u_tdoa_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = tvb_length_remaining(tvb,offset);
ELEM_MAND_TV(BSSLAP_PARAM_CHANNEL_DESCRIPTION,GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, NULL);
ELEM_MAND_TLV(BSSLAP_PARAM_SERVING_CELL_IDENTIFIER,GSM_A_PDU_TYPE_BSSMAP, BE_CELL_ID, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_FREQUENCY_LIST, GSM_A_PDU_TYPE_RR, DE_RR_FREQ_LIST, NULL);
ELEM_OPT_TV(BSSLAP_PARAM_TIMING_ADVANCE, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_TA, NULL);
ELEM_OPT_TV(BSSLAP_PARAM_MS_POWER, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_MS_POW, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_MEASUREMENT_REPORT, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_MEAS_REP, " BSSLAP");
ELEM_OPT_TV(BSSLAP_PARAM_ENCRYPTION_KEY, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_ENC_KEY, NULL);
ELEM_OPT_TV(BSSLAP_PARAM_CIPHER_MODE_SETTING, GSM_A_PDU_TYPE_RR, DE_RR_CIP_MODE_SET, NULL);
ELEM_OPT_TV(BSSLAP_PARAM_CHANNEL_MODE, GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_MULTIRATE_CONFIGURATION, GSM_A_PDU_TYPE_RR, DE_RR_MULTIRATE_CONF, NULL);
ELEM_OPT_TLV(BSSLAP_PARAM_CELL_IDENTITY_LIST, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_CELL_ID_LIST, "-Measured Cell");
ELEM_OPT_TLV(BSSLAP_PARAM_PACKET_CHANNEL_DESCRIPTION, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_PKT_CH_DESC, NULL);
ELEM_OPT_TV(BSSLAP_PARAM_TLLI, GSM_A_PDU_TYPE_RR, DE_RR_TLLI, NULL);
ELEM_OPT_TV(BSSLAP_PARAM_TFI, GSM_A_PDU_TYPE_BSSLAP, DE_BLAP_TFI, NULL);
ELEM_OPT_TV(BSSLAP_PARAM_STARTING_TIME, GSM_A_PDU_TYPE_RR, DE_RR_STARTING_TIME, "TBF Starting Time");
return;
}
static void
dissect_gsm_bsslap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item;
proto_tree *sub_tree;
int offset=0;
guint8 octet;
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/BSSLAP");
if (tree) {
octet = tvb_get_guint8(tvb, offset);
item = proto_tree_add_item(tree, proto_gsm_bsslap, tvb, 0, -1, ENC_NA);
sub_tree = proto_item_add_subtree(item, ett_gsm_bsslap);
proto_tree_add_item(sub_tree, hf_gsm_bsslap_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (octet){
case BSSLAP_TA_REQUEST:
break;
case BSSLAP_TA_RESPONSE:
dissect_gsm_bsslap_ta_res(tvb, sub_tree, pinfo, offset);
break;
case BSSLAP_REJECT:
dissect_gsm_bsslap_reject(tvb, sub_tree, pinfo, offset);
break;
case BSSLAP_RESET:
dissect_gsm_bsslap_reset(tvb, sub_tree, pinfo, offset);
break;
case BSSLAP_ABORT:
dissect_gsm_bsslap_abort(tvb, sub_tree, pinfo, offset);
break;
case BSSLAP_TA_LAYER3:
dissect_gsm_bsslap_ta_layer3(tvb, sub_tree, pinfo, offset);
break;
case BSSLAP_MS_POS_CMD:
dissect_gsm_bsslap_ms_pos_cmd(tvb, sub_tree, pinfo, offset);
break;
case BSSLAP_MS_POS_RES:
dissect_gsm_bsslap_ms_pos_res(tvb, sub_tree, pinfo, offset);
break;
case BSSLAP_U_TDOA_REQ:
dissect_gsm_bsslap_u_tdoa_req(tvb, sub_tree, pinfo, offset);
break;
case BSSLAP_U_TDOA_RES:
dissect_gsm_bsslap_u_tdoa_res(tvb, sub_tree, pinfo, offset);
break;
default:
break;
}
}
}
void
proto_reg_handoff_gsm_bsslap(void)
{
bsslap_rrlp_handle = find_dissector("rrlp");
}
void
proto_register_gsm_bsslap(void)
{
guint i;
guint last_offset;
static hf_register_info hf[] = {
{ &hf_gsm_bsslap_msg_type,
{ "Message Type IE", "gsm_bsslap.msg_type",
FT_UINT8, BASE_DEC, VALS(gsm_a_bsslap_msg_strings), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_bsslap_elem_id,
{ "Element ID", "gsm_bsslap.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_bsslap_ta,
{ "Timing Advance", "gsm_bsslap.ta",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_bsslap_timer_value,
{"Timer Value", "gsm_bsslap.timerValue",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_bsslap_ms_pow,
{"MS Power", "gsm_bsslap.MS_pow",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_bsslap_cause,
{"Cause", "gsm_bsslap.cause",
FT_UINT8, BASE_DEC, VALS(gsm_bsslap_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_bsslap_rrlp_flg,
{"RRLP Flag", "gsm_bsslap.rrlp_flg",
FT_BOOLEAN, 8, TFS(&gsm_bsslap_rrlp_flg_vals), 0x01,
"Cause", HFILL }
},
{ &hf_gsm_bsslap_tfi,
{"TFI", "gsm_bsslap.tfi",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_gsm_bsslap_poll_rep,
{"Number of polling repetitions", "gsm_bsslap.poll_rep",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL }
},
{ &hf_gsm_bsslap_lac,
{"Location Area Code", "gsm_bsslap.lac",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_gsm_bsslap_cell_id_disc,
{"Cell identification Discriminator", "gsm_bsslap.cell_id_disc",
FT_UINT8, BASE_DEC, VALS(gsm_a_bsslap_cell_id_disc_vals), 0xf,
NULL, HFILL }
},
};
#define NUM_INDIVIDUAL_ELEMS 2
gint *ett[NUM_INDIVIDUAL_ELEMS + NUM_GSM_BSSLAP_MSG +
NUM_GSM_BSSLAP_ELEM];
ett[0] = &ett_gsm_bsslap;
ett[1] = &ett_bsslap_cell_list;
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_GSM_BSSLAP_MSG; i++, last_offset++)
{
ett_gsm_bsslap_msg[i] = -1;
ett[last_offset] = &ett_gsm_bsslap_msg[i];
}
for (i=0; i < NUM_GSM_BSSLAP_ELEM; i++, last_offset++)
{
ett_gsm_bsslap_elem[i] = -1;
ett[last_offset] = &ett_gsm_bsslap_elem[i];
}
proto_gsm_bsslap =
proto_register_protocol("BSS LCS Assistance Protocol",
"BSSLAP", "bsslap");
proto_register_field_array(proto_gsm_bsslap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gsm_bsslap", dissect_gsm_bsslap, proto_gsm_bsslap);
}
