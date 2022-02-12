static void
dissect_bssap_unknown_message(tvbuff_t *message_tvb, proto_tree *bssap_tree)
{
guint32 message_length;
message_length = tvb_length(message_tvb);
proto_tree_add_text(bssap_tree, message_tvb, 0, message_length,
"Unknown message (%u byte%s)",
message_length, plurality(message_length, "", "s"));
}
static void
dissect_bssap_unknown_param(tvbuff_t *tvb, proto_tree *tree, guint8 type, guint16 length)
{
proto_tree_add_text(tree, tvb, 0, length,
"Unknown parameter 0x%x (%u byte%s)",
type, length, plurality(length, "", "s"));
}
static void
dissect_bssap_data_param(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *bssap_tree, proto_tree *tree)
{
if ((pdu_type <= 0x01))
{
if (bssap_or_bsap_global == BSSAP)
{
if((gsm_or_lb_interface_global == LB_INTERFACE) && (pdu_type == BSSAP_PDU_TYPE_BSSMAP))
{
bsap_dissector_handle = find_dissector("gsm_bssmap_le");
if(bsap_dissector_handle == NULL) return;
call_dissector(bsap_dissector_handle, tvb, pinfo, tree);
return;
}
else if((gsm_or_lb_interface_global == GSM_INTERFACE) && (pdu_type == BSSAP_PDU_TYPE_BSSMAP))
{
bsap_dissector_handle = find_dissector("gsm_a_bssmap");
if(bsap_dissector_handle == NULL) return;
call_dissector(bsap_dissector_handle, tvb, pinfo, tree);
return;
}
else
{
if (dissector_try_uint(bssap_dissector_table, pdu_type, tvb, pinfo, tree)) return;
}
}
else
{
if (dissector_try_uint(bsap_dissector_table, pdu_type, tvb, pinfo, tree))
return;
}
}
call_dissector(data_handle, tvb, pinfo, bssap_tree);
}
static void
dissect_bssap_dlci_param(tvbuff_t *tvb, proto_tree *tree, guint16 length)
{
proto_item *dlci_item;
proto_tree *dlci_tree;
guint8 oct;
dlci_item =
proto_tree_add_text(tree, tvb, 0, length,
"Data Link Connection Identifier");
dlci_tree = proto_item_add_subtree(dlci_item, ett_bssap_dlci);
oct = tvb_get_guint8(tvb, 0);
if (bssap_or_bsap_global == BSSAP)
{
proto_tree_add_uint(dlci_tree, hf_bssap_dlci_cc, tvb, 0, length, oct);
proto_tree_add_uint(dlci_tree, hf_bssap_dlci_spare, tvb, 0, length, oct);
proto_tree_add_uint(dlci_tree, hf_bssap_dlci_sapi, tvb, 0, length, oct);
}
else
{
proto_tree_add_uint(dlci_tree, hf_bsap_dlci_cc, tvb, 0, length, oct);
proto_tree_add_uint(dlci_tree, hf_bsap_dlci_rsvd, tvb, 0, length, oct);
proto_tree_add_uint(dlci_tree, hf_bsap_dlci_sapi, tvb, 0, length, oct);
}
}
static void
dissect_bssap_length_param(tvbuff_t *tvb, proto_tree *tree, guint16 length)
{
guint8 data_length;
data_length = tvb_get_guint8(tvb, 0);
proto_tree_add_uint(tree, hf_bssap_length, tvb, 0, length, data_length);
}
static guint16
dissect_bssap_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bssap_tree,
proto_tree *tree, guint8 parameter_type, gint offset,
guint16 parameter_length)
{
tvbuff_t *parameter_tvb;
parameter_tvb = tvb_new_subset(tvb, offset, parameter_length, parameter_length);
switch (parameter_type)
{
case PARAMETER_DLCI:
dissect_bssap_dlci_param(parameter_tvb, bssap_tree, parameter_length);
break;
case PARAMETER_LENGTH:
dissect_bssap_length_param(parameter_tvb, bssap_tree, parameter_length);
break;
case PARAMETER_DATA:
dissect_bssap_data_param(parameter_tvb, pinfo, bssap_tree, tree);
break;
default:
dissect_bssap_unknown_param(parameter_tvb, bssap_tree, parameter_type,
parameter_length);
break;
}
return(parameter_length);
}
static guint16
dissect_bssap_var_parameter(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *bssap_tree, proto_tree *tree,
guint8 parameter_type, gint offset)
{
guint16 parameter_length;
guint8 length_length;
parameter_length = tvb_get_guint8(tvb, offset);
length_length = LENGTH_LENGTH;
offset += length_length;
dissect_bssap_parameter(tvb, pinfo, bssap_tree, tree, parameter_type,
offset, parameter_length);
return(parameter_length + length_length);
}
static int
dissect_bssap_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bssap_tree,
proto_tree *tree)
{
gint offset;
pdu_type = tvb_get_guint8(tvb, PDU_TYPE_OFFSET);
offset = PDU_TYPE_LENGTH;
if (bssap_tree)
{
proto_tree_add_uint(bssap_tree,
(bssap_or_bsap_global == BSSAP) ? hf_bssap_pdu_type : hf_bsap_pdu_type,
tvb, PDU_TYPE_OFFSET, PDU_TYPE_LENGTH, pdu_type);
}
switch (pdu_type)
{
case BSSAP_PDU_TYPE_BSSMAP:
offset += dissect_bssap_parameter(tvb, pinfo, bssap_tree, tree,
PARAMETER_LENGTH, offset,
LENGTH_LENGTH);
offset += dissect_bssap_var_parameter(tvb, pinfo, bssap_tree, tree,
PARAMETER_DATA,
(offset - LENGTH_LENGTH));
break;
case BSSAP_PDU_TYPE_DTAP:
offset += dissect_bssap_parameter(tvb, pinfo, bssap_tree, tree,
PARAMETER_DLCI,
offset, DLCI_LENGTH);
offset += dissect_bssap_parameter(tvb, pinfo, bssap_tree, tree,
PARAMETER_LENGTH, offset,
LENGTH_LENGTH);
offset += dissect_bssap_var_parameter(tvb, pinfo, bssap_tree, tree,
PARAMETER_DATA,
(offset - LENGTH_LENGTH));
break;
default:
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str_const(pdu_type,
((bssap_or_bsap_global == BSSAP) ?
bssap_pdu_type_acro_values : bsap_pdu_type_acro_values),
"Unknown"));
dissect_bssap_unknown_message(tvb, bssap_tree);
break;
}
return offset;
}
static void
dissect_bssap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *bssap_item;
proto_tree *bssap_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, ((bssap_or_bsap_global == BSSAP) ? "BSSAP" : "BSAP"));
if (pinfo->sccp_info && pinfo->sccp_info->data.co.assoc )
pinfo->sccp_info->data.co.assoc->payload = SCCP_PLOAD_BSSAP;
bssap_item = proto_tree_add_protocol_format(tree, proto_bssap, tvb, 0, -1,
(bssap_or_bsap_global == BSSAP) ? "BSSAP" : "BSAP");
bssap_tree = proto_item_add_subtree(bssap_item, ett_bssap);
dissect_bssap_message(tvb, pinfo, bssap_tree, tree);
}
static const char*
unpack_digits(tvbuff_t *tvb, int offset, dgt_set_t *dgt, gboolean skip_first)
{
int length;
guint8 octet;
int i = 0;
char *digit_str;
length = tvb_length(tvb);
if (length < offset)
return "";
digit_str = (char *)wmem_alloc(wmem_packet_scope(), (length - offset)*2+1);
while (offset < length) {
octet = tvb_get_guint8(tvb, offset);
if (!skip_first) {
digit_str[i] = dgt->out[octet & 0x0f];
i++;
}
skip_first = FALSE;
octet = octet >> 4;
if (octet == 0x0f)
break;
digit_str[i] = dgt->out[octet & 0x0f];
i++;
offset++;
}
digit_str[i]= '\0';
return digit_str;
}
static gboolean
check_ie(tvbuff_t *tvb, proto_tree *tree, int *offset, guint8 expected_ie)
{
guint8 ie_type;
guint8 ie_len;
ie_type = tvb_get_guint8(tvb, *offset);
if (ie_type != expected_ie) {
proto_tree_add_text(tree, tvb, *offset, 1, "Mandatory IE %s expected but IE %s Found",
val_to_str_ext(expected_ie, &bssap_plus_ie_id_values_ext, "Unknown %u"),
val_to_str_ext(ie_type, &bssap_plus_ie_id_values_ext, "Unknown %u"));
(*offset)++;
ie_len = tvb_get_guint8(tvb, *offset);
*offset = *offset + ie_len;
return FALSE;
}
return TRUE;
}
static gboolean
check_optional_ie(tvbuff_t *tvb, int offset, guint8 expected_ie)
{
guint8 ie_type;
ie_type = tvb_get_guint8(tvb, offset);
if (ie_type != expected_ie) {
return FALSE;
}
return TRUE;
}
static int
dissect_bssap_cell_global_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_item *item;
proto_tree *ie_tree;
proto_item *cgi_item;
proto_tree *cgi_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_cell_global_id_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_cell_global_id);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
cgi_item = proto_tree_add_item(ie_tree, hf_bssap_cell_global_id, tvb, offset, ie_len, ENC_NA);
cgi_tree = proto_item_add_subtree(cgi_item, ett_bssap_cgi);
de_gmm_rai(tvb, cgi_tree, pinfo, offset, ie_len, NULL, 0);
offset = offset + 6;
de_cell_id(tvb, cgi_tree, pinfo, offset, ie_len, NULL, 0);
offset = offset + 2;
return offset;
}
static int
dissect_bssap_channel_needed(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_channel_needed_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_channel_needed);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
de_rr_chnl_needed(tvb, ie_tree, pinfo, offset, ie_len, NULL, 0);
return offset + ie_len;
}
static int
dissect_bssap_dlink_tunnel_payload_control_and_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
tvbuff_t *next_tvb;
guint8 ie_len;
guint8 octet;
guint8 prot_disc;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_dlink_tnl_pld_cntrl_amd_inf_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_dlink_tnl_pld_cntrl_amd_inf);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_tom_prot_disc, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb, offset);
prot_disc = (octet&0x78)>>3;
proto_tree_add_item(ie_tree, hf_bssap_e_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_bssap_tunnel_prio, tvb, offset, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset(tvb, offset, ie_len-4, ie_len-4);
if ((prot_disc == 2)&&(rrlp_handle))
call_dissector(rrlp_handle, next_tvb, pinfo, ie_tree);
else
call_dissector(data_handle, next_tvb, pinfo, ie_tree);
return offset + ie_len;
}
static int
dissect_bssap_emlpp_priority(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_emlpp_prio_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_emlpp_prio);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_call_priority, tvb, offset, ie_len, ENC_BIG_ENDIAN);
return offset + ie_len;
}
static int
dissect_bssap_gprs_erroneous_msg(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_gprs_erroneous_msg_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_erroneous_msg);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_data, tvb, offset, ie_len, ENC_NA);
return offset + ie_len;
}
static int
dissect_bssap_gprs_location_update_type(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_gprs_loc_upd_type_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_gprs_loc_upd);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_gprs_loc_upd_type, tvb, offset, ie_len, ENC_BIG_ENDIAN);
return offset + ie_len;
}
static int
dissect_bssap_Gs_cause(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_Gs_cause_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bassp_Gs_cause);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_Gs_cause, tvb, offset, ie_len, ENC_BIG_ENDIAN);
return offset + ie_len;
}
static int
dissect_bssap_imei(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
tvbuff_t *ie_tvb;
const char *digit_str;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_imei_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bassp_imei);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_tvb = tvb_new_subset(tvb, offset, ie_len, ie_len);
digit_str = unpack_digits(ie_tvb, 0, &Dgt1_9_bcd, FALSE);
proto_tree_add_string(ie_tree, hf_bssap_imei, ie_tvb, 0, -1, digit_str);
return offset + ie_len;
}
static int
dissect_bssap_imesiv(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
tvbuff_t *ie_tvb;
const char *digit_str;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_imesiv_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bassp_imesiv);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_tvb = tvb_new_subset(tvb, offset, ie_len, ie_len);
digit_str = unpack_digits(ie_tvb, 0, &Dgt1_9_bcd, FALSE);
proto_tree_add_string(ie_tree, hf_bssap_imeisv, ie_tvb, 0, -1, digit_str);
return offset + ie_len;
}
static int
dissect_bssap_imsi(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
tvbuff_t *ie_tvb;
const char *digit_str;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_imsi_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_imsi);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ie_tvb = tvb_new_subset(tvb, offset, ie_len, ie_len);
digit_str = unpack_digits(ie_tvb, 0, &Dgt1_9_bcd, TRUE);
proto_tree_add_string(ie_tree, hf_bssap_imsi, ie_tvb, 0, -1, digit_str);
return offset + ie_len;
}
static int
dissect_bssap_imsi_det_from_gprs_serv_type(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_imsi_det_from_gprs_serv_type_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_imsi_det_from_gprs_serv_type);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_imsi_det_from_gprs_serv_type, tvb, offset, ie_len, ENC_BIG_ENDIAN);
return offset + ie_len;
}
static int
dissect_bssap_imsi_det_from_non_gprs_serv_type(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_imsi_det_from_non_gprs_serv_type_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_imsi_det_from_non_gprs_serv_type);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_data, tvb, offset, ie_len, ENC_NA);
return offset + ie_len;
}
static int
dissect_bssap_info_req(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_info_req_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_info_req);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_info_req, tvb, offset, ie_len, ENC_BIG_ENDIAN);
return offset + ie_len;
}
static int
dissect_bssap_loc_area_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_loc_area_id_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_loc_area_id);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
de_lai(tvb, ie_tree, pinfo, offset, ie_len, NULL, 0);
return offset + ie_len;
}
static int
dissect_bssap_location_information_age(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_loc_inf_age_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_loc_inf_age);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_loc_inf_age, tvb, offset, ie_len, ENC_BIG_ENDIAN);
return offset + ie_len;
}
static int
dissect_bssap_MM_information(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_mm_information_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_mm_information);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
dtap_mm_mm_info(tvb, ie_tree, pinfo, offset, ie_len);
return offset + ie_len;
}
static int
dissect_bssap_mobile_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_mobile_id_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_mobile_id);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
de_mid(tvb, ie_tree, pinfo, offset, ie_len, NULL, 0);
return offset + ie_len;
}
static int
dissect_bssap_mobile_stn_cls_mrk1(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_mobile_stn_cls_mrk1_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_mobile_stn_cls_mrk1);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
de_ms_cm_1(tvb, ie_tree, pinfo, offset, ie_len, NULL, 0);
return offset + ie_len;
}
static int
dissect_bssap_mobile_station_state(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_mobile_station_state_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_mobile_station_state);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_mobile_station_state, tvb, offset, ie_len, ENC_BIG_ENDIAN);
return offset + ie_len;
}
static int
dissect_bssap_ptmsi(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_ptmsi_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_ptmsi);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_ptmsi, tvb, offset, ie_len, ENC_NA);
return offset + ie_len;
}
static int
dissect_bssap_reject_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_reject_cause_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_reject_cause);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
de_rej_cause(tvb, ie_tree, pinfo, offset, ie_len, NULL, 0);
return offset + ie_len;
}
static int
dissect_bssap_service_area_id(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_service_area_id_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_service_area_id);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_data, tvb, offset, ie_len, ENC_NA);
return offset + ie_len;
}
static int
dissect_bssap_sgsn_number(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
tvbuff_t *number_tvb;
const char *digit_str;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_sgsn_nr_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_sgsn_nr);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_extension, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_bssap_type_of_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_bssap_numbering_plan_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
number_tvb = tvb_new_subset(tvb, offset, ie_len-1, ie_len-1);
digit_str = unpack_digits(number_tvb, 0, &Dgt1_9_bcd, FALSE);
proto_tree_add_string(ie_tree, hf_bssap_sgsn_number, number_tvb, 0, -1, digit_str);
return offset + ie_len-1;
}
static int
dissect_bssap_tmsi(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_tmsi_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_tmsi);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_tmsi, tvb, offset, ie_len, ENC_NA);
return offset + ie_len;
}
static int
dissect_bssap_tmsi_status(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_tmsi_status_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_tmsi_status);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_tmsi_status, tvb, offset, ie_len, ENC_BIG_ENDIAN);
return offset + ie_len;
}
static int
dissect_bssap_ulink_tunnel_payload_control_and_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
tvbuff_t *next_tvb;
guint8 ie_len;
guint8 octet;
guint8 prot_disc;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_ulink_tnl_pld_cntrl_amd_inf_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_ulink_tnl_pld_cntrl_amd_inf);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_tom_prot_disc, tvb, offset, 1, ENC_BIG_ENDIAN);
octet = tvb_get_guint8(tvb, offset);
prot_disc = (octet&0x78)>>3;
proto_tree_add_item(ie_tree, hf_bssap_e_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_bssap_tunnel_prio, tvb, offset, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset(tvb, offset, ie_len - 4, ie_len - 4);
if ((prot_disc == 2)&&(rrlp_handle))
call_dissector(rrlp_handle, next_tvb, pinfo, ie_tree);
else
call_dissector(data_handle, next_tvb, pinfo, ie_tree);
return offset + ie_len;
}
static int
dissect_bssap_vlr_number(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
guint8 ie_len;
tvbuff_t *number_tvb;
const char *digit_str;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_vlr_number_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_vlr_number);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_extension, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_bssap_type_of_number, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_bssap_numbering_plan_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
number_tvb = tvb_new_subset(tvb, offset, ie_len - 1, ie_len - 1);
digit_str = unpack_digits(number_tvb, 0, &Dgt1_9_bcd, FALSE);
proto_tree_add_string(ie_tree, hf_bssap_sgsn_number, number_tvb, 0, -1, digit_str);
return offset + ie_len - 1;
}
static int
dissect_bssap_global_cn_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *item;
proto_tree *ie_tree;
proto_item *plmn_item;
proto_tree *plmn_tree;
proto_item *global_cn_id_item;
proto_tree *global_cn_id_tree;
guint8 ie_len;
ie_len = tvb_get_guint8(tvb, offset+1);
item = proto_tree_add_item(tree, hf_bssap_global_cn_id_ie, tvb, offset, ie_len+2, ENC_NA);
ie_tree = proto_item_add_subtree(item, ett_bssap_global_cn);
proto_tree_add_item(ie_tree, hf_bssap_plus_ie, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ie_tree, hf_bssap_plus_ie_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
global_cn_id_item = proto_tree_add_item(ie_tree, hf_bssap_global_cn_id, tvb, offset, ie_len, ENC_NA);
global_cn_id_tree = proto_item_add_subtree(global_cn_id_item, ett_bssap_global_cn_id);
plmn_item = proto_tree_add_item(global_cn_id_tree, hf_bssap_plmn_id, tvb, offset, 3, ENC_NA);
plmn_tree = proto_item_add_subtree(plmn_item, ett_bssap_plmn);
dissect_e212_mcc_mnc(tvb, pinfo, plmn_tree, offset, TRUE);
offset = offset + 3;
proto_tree_add_item(global_cn_id_tree, hf_bssap_cn_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset+2;
return offset;
}
static void dissect_bssap_plus(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *bssap_item;
proto_tree *bssap_tree;
guint8 message_type;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BSSAP+");
if (pinfo->sccp_info && pinfo->sccp_info->data.co.assoc)
pinfo->sccp_info->data.co.assoc->payload = SCCP_PLOAD_BSSAP;
bssap_item = proto_tree_add_item(tree, proto_bssap, tvb, 0, -1, ENC_NA);
bssap_tree = proto_item_add_subtree(bssap_item, ett_bssap);
message_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(bssap_tree, hf_bssap_plus_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
col_add_str(pinfo->cinfo, COL_INFO, val_to_str_ext(message_type, &bssap_plus_message_type_values_ext, "Unknown %u"));
switch (message_type) {
case BSSAP_PAGING_REQUEST:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_VLR_NUMBER))
offset = dissect_bssap_vlr_number(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_TMSI))
offset = dissect_bssap_tmsi(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_LOC_AREA_ID))
offset = dissect_bssap_loc_area_id(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_CHANNEL_NEEDED))
offset = dissect_bssap_channel_needed(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_EMLPP_PRIORITY))
offset = dissect_bssap_emlpp_priority(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_GLOBAL_CN_ID))
offset = dissect_bssap_global_cn_id(tvb, pinfo, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_PAGING_REJECT:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_GS_CAUSE))
offset = dissect_bssap_Gs_cause(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_DOWNLINK_TUNNEL_REQUEST:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_VLR_NUMBER))
offset = dissect_bssap_vlr_number(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_DLINK_TNL_PLD_CTR_AND_INF))
offset = dissect_bssap_dlink_tunnel_payload_control_and_info(tvb, pinfo, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_UPLINK_TUNNEL_REQUEST:
if (check_ie(tvb, tree, &offset, BSSAP_SGSN_NUMBER))
offset = dissect_bssap_sgsn_number(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_ULINK_TNL_PLD_CTR_AND_INF))
offset = dissect_bssap_ulink_tunnel_payload_control_and_info(tvb, pinfo, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_LOCATION_UPDATE_REQUEST:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_SGSN_NUMBER))
offset = dissect_bssap_sgsn_number(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_GPRS_LOC_UPD_TYPE))
offset = dissect_bssap_gprs_location_update_type(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_CELL_GBL_ID))
offset = dissect_bssap_cell_global_id(tvb, bssap_tree, pinfo, offset);
if (check_ie(tvb, tree, &offset, BSSAP_MOBILE_STN_CLS_MRK1))
offset = dissect_bssap_mobile_stn_cls_mrk1(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_LOC_AREA_ID))
offset = dissect_bssap_loc_area_id(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_TMSI_STATUS))
offset = dissect_bssap_tmsi_status(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_SERVICE_AREA_ID))
offset = dissect_bssap_service_area_id(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_IMEISV))
offset = dissect_bssap_imesiv(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_LOCATION_UPDATE_ACCEPT:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_LOC_AREA_ID))
offset = dissect_bssap_loc_area_id(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_MOBILE_ID))
offset = dissect_bssap_mobile_id(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_LOCATION_UPDATE_REJECT:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_REJECT_CAUSE))
offset = dissect_bssap_reject_cause(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_TMSI_REALLOCATION_COMPLETE:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_CELL_GBL_ID))
offset = dissect_bssap_cell_global_id(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_SERVICE_AREA_ID))
offset = dissect_bssap_service_area_id(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_ALERT_REQUEST:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_ALERT_ACK:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_ALERT_REJECT:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_GS_CAUSE))
offset = dissect_bssap_Gs_cause(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_MS_ACTIVITY_INDICATION:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_CELL_GBL_ID))
offset = dissect_bssap_cell_global_id(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_SERVICE_AREA_ID))
offset = dissect_bssap_service_area_id(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_GPRS_DETACH_INDICATION:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_SGSN_NUMBER))
offset = dissect_bssap_sgsn_number(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_IMSI_DET_FROM_GPRS_SERV_TYPE))
offset = dissect_bssap_imsi_det_from_gprs_serv_type(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_CELL_GBL_ID))
offset = dissect_bssap_cell_global_id(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_SERVICE_AREA_ID))
offset = dissect_bssap_service_area_id(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_GPRS_DETACH_ACK:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_IMSI_DETACH_INDICATION:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_SGSN_NUMBER))
offset = dissect_bssap_sgsn_number(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_IMSI_DET_FROM_NON_GPRS_SERV_TYPE))
offset = dissect_bssap_imsi_det_from_non_gprs_serv_type(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_CELL_GBL_ID))
offset = dissect_bssap_cell_global_id(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_LOC_INF_AGE))
offset = dissect_bssap_location_information_age(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_SERVICE_AREA_ID))
offset = dissect_bssap_service_area_id(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_IMSI_DETACH_ACK:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_RESET_INDICATION:
if (check_optional_ie(tvb, offset, BSSAP_SGSN_NUMBER)) {
offset = dissect_bssap_sgsn_number(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
}else{
if (check_optional_ie(tvb, offset, BSSAP_VLR_NUMBER)) {
offset = dissect_bssap_vlr_number(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
}
}
proto_tree_add_text(tree, tvb, offset, -1, "Conditional IE");
break;
case BSSAP_RESET_ACK:
if (check_optional_ie(tvb, offset, BSSAP_SGSN_NUMBER)) {
offset = dissect_bssap_sgsn_number(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
}else{
if (check_optional_ie(tvb, offset, BSSAP_VLR_NUMBER)) {
offset = dissect_bssap_vlr_number(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
}
}
proto_tree_add_text(tree, tvb, offset, -1, "Conditional IE");
break;
case BSSAP_MS_INFORMATION_REQUEST:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_INFO_REQ))
offset = dissect_bssap_info_req(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_MS_INFORMATION_RESPONSE:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_TMSI))
offset = dissect_bssap_tmsi(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_PTMSI))
offset = dissect_bssap_ptmsi(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_IMEI))
offset = dissect_bssap_imei(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_IMEISV))
offset = dissect_bssap_imesiv(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_CELL_GBL_ID))
offset = dissect_bssap_cell_global_id(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_LOC_INF_AGE))
offset = dissect_bssap_location_information_age(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_MOBILE_STN_STATE))
offset = dissect_bssap_mobile_station_state(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_SERVICE_AREA_ID))
offset = dissect_bssap_service_area_id(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_MM_INFORMATION_REQUEST:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
if (check_optional_ie(tvb, offset, BSSAP_MM_INFORMATION))
offset = dissect_bssap_MM_information(tvb, bssap_tree, pinfo, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_MOBILE_STATUS:
if (check_optional_ie(tvb, offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_GS_CAUSE))
offset = dissect_bssap_Gs_cause(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_ERRONEOUS_MSG))
offset = dissect_bssap_gprs_erroneous_msg(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
case BSSAP_MS_UNREACHABLE:
if (check_ie(tvb, tree, &offset, BSSAP_IMSI))
offset = dissect_bssap_imsi(tvb, bssap_tree, offset);
if (check_ie(tvb, tree, &offset, BSSAP_GS_CAUSE))
offset = dissect_bssap_Gs_cause(tvb, bssap_tree, offset);
if (tvb_length_remaining(tvb, offset) <= 0)
return;
proto_tree_add_text(tree, tvb, offset, -1, "Extraneous data");
break;
default:
break;
}
}
static gboolean
dissect_bssap_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
switch (tvb_get_guint8(tvb, 0))
{
case 0x00:
if (tvb_get_guint8(tvb, 1) != (tvb_length(tvb) - 2)) {
return(FALSE);
}
if (tvb_get_guint8(tvb, 2) == 0x40 && tvb_get_guint8(tvb, 3) != 0x01) {
return(FALSE);
}
break;
case 0x01:
if (tvb_get_guint8(tvb, 2) != (tvb_length(tvb) - 3)) {
return(FALSE);
}
break;
default:
return(FALSE);
}
dissect_bssap(tvb, pinfo, tree);
return(TRUE);
}
void
proto_register_bssap(void)
{
module_t *bssap_module;
static hf_register_info hf[] = {
{ &hf_bssap_pdu_type,
{ "Message Type", "bssap.pdu_type",
FT_UINT8, BASE_HEX, VALS(bssap_pdu_type_values), 0x0,
NULL, HFILL}},
{ &hf_bsap_pdu_type,
{ "Message Type", "bsap.pdu_type",
FT_UINT8, BASE_HEX, VALS(bsap_pdu_type_values), 0x0,
NULL, HFILL}},
{ &hf_bssap_dlci_cc,
{ "Control Channel", "bssap.dlci.cc",
FT_UINT8, BASE_HEX, VALS(bssap_cc_values), CC_MASK,
NULL, HFILL}},
{ &hf_bsap_dlci_cc,
{ "Control Channel", "bsap.dlci.cc",
FT_UINT8, BASE_HEX, VALS(bsap_cc_values), CC_MASK,
NULL, HFILL}},
{ &hf_bssap_dlci_spare,
{ "Spare", "bssap.dlci.spare",
FT_UINT8, BASE_HEX, NULL, SPARE_MASK,
NULL, HFILL}},
{ &hf_bsap_dlci_rsvd,
{ "Reserved", "bsap.dlci.rsvd",
FT_UINT8, BASE_HEX, NULL, SPARE_MASK,
NULL, HFILL}},
{ &hf_bssap_dlci_sapi,
{ "SAPI", "bssap.dlci.sapi",
FT_UINT8, BASE_HEX, VALS(bssap_sapi_values), SAPI_MASK,
NULL, HFILL}},
{ &hf_bsap_dlci_sapi,
{ "SAPI", "bsap.dlci.sapi",
FT_UINT8, BASE_HEX, VALS(bsap_sapi_values), SAPI_MASK,
NULL, HFILL}},
{ &hf_bssap_length,
{ "Length", "bssap.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_bssap_plus_message_type,
{ "Message Type", "bssap_plus.msg_type",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &bssap_plus_message_type_values_ext, 0x0,
NULL, HFILL}},
{ &hf_bssap_plus_ie,
{ "IEI", "bssap_plus.iei",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &bssap_plus_ie_id_values_ext, 0x0,
NULL, HFILL}},
{ &hf_bssap_plus_ie_len,
{ "Length indicator", "bssap_plus.ie_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_bssap_extension,
{ "Extension", "bssap.extension",
FT_BOOLEAN, 8, TFS(&bssap_extension_value), 0x80,
NULL, HFILL }},
{ &hf_bssap_type_of_number,
{ "Type of number", "bssap.type_of_number",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_type_of_number_values), 0x70,
NULL, HFILL }},
{ &hf_bssap_numbering_plan_id,
{ "Numbering plan identification", "bssap.number_plan",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_numbering_plan_id_values), 0x0f,
NULL, HFILL }},
{ &hf_bssap_sgsn_number,
{ "SGSN number", "bssap.sgsn_number",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
#if 0
{ &hf_bssap_vlr_number,
{ "VLR number", "bssap.vlr_number",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
#endif
{ &hf_bssap_cell_global_id_ie,
{ "Cell global identity IE", "bssap.cell_global_id_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_channel_needed_ie,
{ "Channel needed IE", "bssap.channel_needed_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_dlink_tnl_pld_cntrl_amd_inf_ie,
{ "Downlink Tunnel Payload Control and Info IE", "bssap.dlink_tnl_pld_cntrl_amd_inf_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_ulink_tnl_pld_cntrl_amd_inf_ie,
{ "Uplink Tunnel Payload Control and Info IE", "bssap.ulink_tnl_pld_cntrl_amd_inf_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_emlpp_prio_ie,
{ "eMLPP Priority IE", "bssap.emlpp_prio_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_gprs_erroneous_msg_ie,
{ "Erroneous message IE", "bssap.erroneous_msg_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_gprs_loc_upd_type_ie,
{ "GPRS location update type IE", "bssap.loc_upd_type_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_Gs_cause_ie,
{ "Gs Cause IE", "bssap.Gs_cause_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_imei_ie,
{ "IMEI IE", "bssap.imei_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_imesiv_ie,
{ "IMEISV IE", "bssap.imesiv",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_imsi_ie,
{ "IMSI IE", "bssap.imsi_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_imsi_det_from_gprs_serv_type_ie,
{ "IMSI detach from GPRS service type IE", "bssap.msi_det_from_gprs_serv_type_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_imsi_det_from_non_gprs_serv_type_ie,
{ "IMSI detach from non-GPRS service IE", "bssap.msi_det_from_non_gprs_serv_type_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_info_req_ie,
{ "Information requested IE", "bssap.info_req_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_loc_area_id_ie,
{ "Location area identifier IE", "bssap.loc_area_id_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_loc_inf_age_ie,
{ "Location information age IE", "bssap.loc_inf_age_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_mm_information_ie,
{ "MM information IE", "bssap.mm_information",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_mobile_id_ie,
{ "Mobile identity IE", "bssap.mobile_id_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_mobile_stn_cls_mrk1_ie,
{ "Mobile station classmark 1 IE", "bssap.mobile_stn_cls_mrk1_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_mobile_station_state_ie,
{ "Mobile station state IE", "bssap.mobile_station_state_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_ptmsi_ie,
{ "PTMSI IE", "bssap.ptmsi_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_reject_cause_ie,
{ "Reject cause IE", "bssap.reject_cause_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_service_area_id_ie,
{ "Service area identification IE", "bssap.service_area_id_ie",
FT_NONE, BASE_NONE, NULL, 0,
"Mobile station classmark 1", HFILL }},
{ &hf_bssap_sgsn_nr_ie,
{ "SGSN number IE", "bssap.sgsn_nr_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_tmsi_ie,
{ "TMSI IE", "bssap.tmsi_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_tmsi_status_ie,
{ "TMSI status IE", "bssap.tmsi_status_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_vlr_number_ie,
{ "VLR number IE", "bssap.vlr_number_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_global_cn_id_ie,
{ "Global CN-Id IE", "bssap.global_cn_id_ie",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_plus_ie_data,
{ "IE Data", "bssap.ie_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_call_priority,
{ "eMLPP Priority", "bssap.call_priority",
FT_UINT8, BASE_DEC, VALS(bssap_call_priority_values), 0x07,
NULL, HFILL}},
{ &hf_bssap_gprs_loc_upd_type,
{ "GPRS location update type", "bssap.gprs_loc_upd_type",
FT_UINT8, BASE_DEC, VALS(bssap_plus_GPRS_loc_upd_type_values), 0x0,
NULL, HFILL}},
{ &hf_bssap_Gs_cause,
{ "Gs cause", "bssap.Gs_cause",
FT_UINT8, BASE_DEC, VALS(bssap_Gs_cause_values), 0x0,
NULL, HFILL}},
{ &hf_bssap_imei,
{ "IMEI", "bssap.imei",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_imeisv,
{ "IMEISV", "bssap.imeisv",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_imsi,
{ "IMSI", "bssap.imsi",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_bssap_imsi_det_from_gprs_serv_type,
{ "IMSI detach from GPRS service type", "bssap.imsi_det_from_gprs_serv_type",
FT_UINT8, BASE_DEC, VALS(bssap_Gs_cause_values), 0x0,
NULL, HFILL}},
{ &hf_bssap_info_req,
{ "Information requested", "bssap.info_req",
FT_UINT8, BASE_DEC, VALS(bssap_info_req_values), 0x0,
NULL, HFILL}},
{ &hf_bssap_loc_inf_age,
{ "AgeOfLocationInformation in minutes", "bssap.loc_inf_age",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_bssap_mobile_station_state,
{ "Mobile station state", "bssap.mobile_station_state",
FT_UINT8, BASE_DEC, VALS(bssap_mobile_station_state_values), 0x0,
NULL, HFILL}},
{ &hf_bssap_ptmsi,
{ "PTMSI", "bssap.ptmsi",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_bssap_tmsi,
{ "TMSI", "bssap.tmsi",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_bssap_tmsi_status,
{ "TMSI status", "bssap.tmsi_status",
FT_BOOLEAN, 8, TFS(&bssap_tmsi_flag), 0x01,
NULL, HFILL }},
{ &hf_bssap_tom_prot_disc,
{ "TOM Protocol Discriminator", "bssap.Tom_prot_disc",
FT_UINT8, BASE_DEC, VALS(bssap_tom_prot_disc_values), 0x78,
NULL, HFILL}},
{ &hf_bssap_e_bit,
{ "E: Cipher Request", "bssap.e_bit",
FT_BOOLEAN, 8, TFS(&bssap_E_flag), 0x04,
NULL, HFILL }},
{ &hf_bssap_tunnel_prio,
{ "Tunnel Priority", "bssap.tunnel_prio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_bssap_global_cn_id,
{ "Global CN-Id", "bssap.global_cn_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_bssap_plmn_id,
{ "PLMN-Id", "bssap.plmn_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_bssap_cn_id,
{ "CN-Id", "bssap.cn_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_bssap_cell_global_id,
{ "Cell global identity", "bssap.cell_global_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_bssap,
&ett_bssap_dlci,
&ett_bssap_imsi,
&ett_bssap_imsi_det_from_gprs_serv_type,
&ett_bssap_imsi_det_from_non_gprs_serv_type,
&ett_bssap_info_req,
&ett_bssap_loc_area_id,
&ett_bssap_loc_inf_age,
&ett_bssap_mm_information,
&ett_bssap_mobile_id,
&ett_bssap_sgsn_nr,
&ett_bssap_tmsi,
&ett_bssap_tmsi_status,
&ett_bssap_vlr_number,
&ett_bssap_global_cn,
&ett_bssap_gprs_loc_upd,
&ett_bassp_Gs_cause,
&ett_bassp_imei,
&ett_bassp_imesiv,
&ett_bssap_cell_global_id,
&ett_bssap_cgi,
&ett_bssap_channel_needed,
&ett_bssap_dlink_tnl_pld_cntrl_amd_inf,
&ett_bssap_ulink_tnl_pld_cntrl_amd_inf,
&ett_bssap_emlpp_prio,
&ett_bssap_erroneous_msg,
&ett_bssap_mobile_stn_cls_mrk1,
&ett_bssap_mobile_station_state,
&ett_bssap_ptmsi,
&ett_bssap_reject_cause,
&ett_bssap_service_area_id,
&ett_bssap_global_cn_id,
&ett_bssap_plmn,
};
static const enum_val_t gsm_or_lb_interface_options[] = {
{ "gsm a", "GSM A", GSM_INTERFACE },
{ "lb", "Lb", LB_INTERFACE },
{ NULL, NULL, 0 }
};
static const enum_val_t bssap_or_bsap_options[] = {
{ "bssap", "BSSAP", BSSAP },
{ "bsap", "BSAP", BSAP },
{ NULL, NULL, 0 }
};
proto_bssap = proto_register_protocol("BSSAP/BSAP", "BSSAP", "bssap");
register_dissector("bssap", dissect_bssap, proto_bssap);
register_dissector("bssap_plus", dissect_bssap_plus, proto_bssap);
proto_register_field_array(proto_bssap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
bssap_module = prefs_register_protocol(proto_bssap, proto_reg_handoff_bssap);
prefs_register_enum_preference(bssap_module,
"bsap_or_bssap",
"Identify to sub-dissector as",
"For the sake of sub-dissectors registering to accept data "
"from the BSSAP/BSAP dissector, this defines whether it is "
"identified as BSSAP or BSAP.",
&bssap_or_bsap_global,
bssap_or_bsap_options,
FALSE);
prefs_register_enum_preference(bssap_module,
"gsm_or_lb_interface",
"Identify the BSSAP interface",
"GSM-A is the interface between the BSC and the MSC. Lb is the interface between the BSC and the SMLC.",
&gsm_or_lb_interface_global,
gsm_or_lb_interface_options,
FALSE);
prefs_register_uint_preference(bssap_module, "ssn",
"Subsystem number used for BSSAP",
"Set Subsystem number used for BSSAP/BSSAP+",
10, &global_bssap_ssn);
bssap_dissector_table = register_dissector_table("bssap.pdu_type", "BSSAP Message Type", FT_UINT8, BASE_DEC);
bsap_dissector_table = register_dissector_table("bsap.pdu_type", "BSAP Message Type", FT_UINT8, BASE_DEC);
}
void
proto_reg_handoff_bssap(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t bssap_plus_handle;
static guint old_bssap_ssn;
if (!initialized) {
heur_dissector_add("sccp", dissect_bssap_heur, proto_bssap);
heur_dissector_add("sua", dissect_bssap_heur, proto_bssap);
bssap_plus_handle = create_dissector_handle(dissect_bssap_plus, proto_bssap);
data_handle = find_dissector("data");
rrlp_handle = find_dissector("rrlp");
initialized = TRUE;
} else {
dissector_delete_uint("sccp.ssn", old_bssap_ssn, bssap_plus_handle);
}
dissector_add_uint("sccp.ssn", global_bssap_ssn, bssap_plus_handle);
old_bssap_ssn = global_bssap_ssn;
}
