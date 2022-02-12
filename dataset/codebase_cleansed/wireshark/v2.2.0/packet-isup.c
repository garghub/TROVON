static void
isup_apm_defragment_init(void)
{
reassembly_table_init (&isup_apm_msg_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
isup_apm_defragment_cleanup(void)
{
reassembly_table_destroy(&isup_apm_msg_reassembly_table);
}
static char number_to_char(int number)
{
if (number < 10)
return ((char) number + ASCII_NUMBER_DELTA);
else
return ((char) number + ASCII_LETTER_DELTA);
}
static void
dissect_isup_cvr_response_ind_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 cvr_response_ind;
cvr_response_ind = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_cvr_rsp_ind, parameter_tvb, 0, CVR_RESP_IND_LENGTH, cvr_response_ind);
proto_item_set_text(parameter_item, "Circuit Validation Test Response Indicator: 0x%x", cvr_response_ind);
}
static void
dissect_isup_circuit_group_char_ind_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 cvr_cg_char_ind;
cvr_cg_char_ind = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_cvr_cg_car_ind, parameter_tvb, 0, CG_CHAR_IND_LENGTH, cvr_cg_char_ind);
proto_tree_add_uint(parameter_tree, hf_isup_cvr_cg_double_seize, parameter_tvb, 0, CG_CHAR_IND_LENGTH, cvr_cg_char_ind);
proto_tree_add_uint(parameter_tree, hf_isup_cvr_cg_alarm_car_ind, parameter_tvb, 0, CG_CHAR_IND_LENGTH, cvr_cg_char_ind);
proto_tree_add_uint(parameter_tree, hf_isup_cvr_cont_chk_ind, parameter_tvb, 0, CG_CHAR_IND_LENGTH, cvr_cg_char_ind);
proto_item_set_text(parameter_item, "Circuit Validation Test Response Circuit Group Characteristics: 0x%x", cvr_cg_char_ind);
}
static void
dissect_isup_nature_of_connection_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 nature_of_connection_ind;
static const int * indicators[] = {
&hf_isup_satellite_indicator,
&hf_isup_continuity_check_indicator,
&hf_isup_echo_control_device_indicator,
NULL
};
nature_of_connection_ind = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, NATURE_OF_CONNECTION_IND_LENGTH, indicators, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Nature of Connection Indicators: 0x%x", nature_of_connection_ind);
}
static void
dissect_isup_forward_call_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 forward_call_ind = tvb_get_ntohs(parameter_tvb, 0);
static const int * indicators[] = {
&hf_isup_forw_call_natnl_inatnl_call_indicator,
&hf_isup_forw_call_end_to_end_method_indicator,
&hf_isup_forw_call_interworking_indicator,
&hf_isup_forw_call_end_to_end_info_indicator,
&hf_isup_forw_call_isdn_user_part_indicator,
&hf_isup_forw_call_preferences_indicator,
&hf_isup_forw_call_isdn_access_indicator,
&hf_isup_forw_call_sccp_method_indicator,
&hf_isup_forw_call_ported_num_trans_indicator,
&hf_isup_forw_call_qor_attempt_indicator,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, FORWARD_CALL_IND_LENGTH, indicators, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Forward Call Indicators: 0x%x", forward_call_ind);
}
static void
dissect_isup_calling_partys_category_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item, guint8 itu_isup_variant)
{
guint8 calling_partys_category;
calling_partys_category = tvb_get_guint8(parameter_tvb, 0);
if (itu_isup_variant == ISUP_RUSSIAN_VARIANT) {
proto_tree_add_uint(parameter_tree, hf_russian_isup_calling_partys_category,
parameter_tvb, 0, CALLING_PRTYS_CATEGORY_LENGTH, calling_partys_category);
proto_item_set_text(parameter_item, "Calling Party's category: 0x%x (%s)",
calling_partys_category,
val_to_str_ext_const(calling_partys_category,
&russian_isup_calling_partys_category_value_ext,
"reserved/spare"));
} else {
proto_tree_add_uint(parameter_tree, hf_isup_calling_partys_category,
parameter_tvb, 0, CALLING_PRTYS_CATEGORY_LENGTH, calling_partys_category);
proto_item_set_text(parameter_item, "Calling Party's category: 0x%x (%s)",
calling_partys_category,
val_to_str_ext_const(calling_partys_category,
&isup_calling_partys_category_value_ext,
"reserved/spare"));
}
}
static void
dissect_isup_transmission_medium_requirement_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 transmission_medium_requirement;
transmission_medium_requirement = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_transmission_medium_requirement,
parameter_tvb, 0, TRANSMISSION_MEDIUM_REQUIREMENT_LENGTH, transmission_medium_requirement);
proto_item_set_text(parameter_item, "Transmission medium requirement: %u (%s)", transmission_medium_requirement,
val_to_str_ext_const(transmission_medium_requirement, &isup_transmission_medium_requirement_value_ext, "spare"));
}
static char *
dissect_isup_digits_common(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_, proto_tree *tree, proto_item *item,
const char *param_name, gint hf_number, gint hf_odd_digit, gint hf_even_digit,
gboolean even_indicator, e164_number_type_t number_type, guint nature_of_address)
{
gint i = 0;
gint reported_length, captured_length;
proto_item *digits_item;
proto_tree *digits_tree;
guint8 digit_pair = 0;
wmem_strbuf_t *strbuf_number;
char *number;
e164_info_t e164_info;
gint start_offset = offset;
reported_length = tvb_reported_length_remaining(tvb, offset);
if (reported_length == 0) {
expert_add_info(pinfo, item, &ei_isup_empty_number);
proto_item_set_text(item, "%s: (empty)", param_name);
return NULL;
}
strbuf_number = wmem_strbuf_sized_new(wmem_packet_scope(), MAXDIGITS+1, 0);
captured_length = tvb_captured_length_remaining(tvb, offset);
while (captured_length > 0) {
if (++i > MAXDIGITS) {
break;
}
digit_pair = tvb_get_guint8(tvb, offset);
wmem_strbuf_append_c(strbuf_number, number_to_char(digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK));
if ((captured_length - 1) > 0) {
if (++i > MAXDIGITS) {
break;
}
wmem_strbuf_append_c(strbuf_number, number_to_char((digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10));
}
offset += 1;
captured_length -= 1;
}
if (even_indicator && (tvb_captured_length(tvb) > 0) && (++i < MAXDIGITS)) {
wmem_strbuf_append_c(strbuf_number, number_to_char((digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10));
}
number = wmem_strbuf_finalize(strbuf_number);
offset = start_offset;
i = 0;
digits_item = proto_tree_add_string(tree, hf_number, tvb, offset, -1, number);
digits_tree = proto_item_add_subtree(digits_item, ett_isup_address_digits);
while (reported_length > 0) {
if (++i > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
proto_tree_add_item(digits_tree, hf_odd_digit, tvb, offset, 1, ENC_NA);
if ((reported_length - 1) > 0) {
if (++i > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
proto_tree_add_item(digits_tree, hf_even_digit, tvb, offset, 1, ENC_NA);
}
offset += 1;
reported_length -= 1;
}
if (even_indicator && (tvb_reported_length(tvb) > 0)) {
if (++i < MAXDIGITS) {
proto_tree_add_item(digits_tree, hf_even_digit, tvb, offset - 1, 1, ENC_NA);
} else {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
}
}
proto_item_append_text(digits_item, "%s", number);
if (number_type != NONE) {
e164_info.e164_number_type = number_type;
e164_info.nature_of_address = nature_of_address;
e164_info.E164_number_str = number;
e164_info.E164_number_length = i - 1;
dissect_e164_number(tvb, digits_tree, 2, (offset - 2), e164_info);
}
proto_item_set_text(item, "%s: %s", param_name, number);
return number;
}
void
dissect_isup_called_party_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1, indicators2;
gint offset = 0;
gint number_plan;
static const int *indicators1_flags[] = {
&hf_isup_odd_even_indicator,
&hf_isup_called_party_nature_of_address_indicator,
NULL
};
static const int *indicators2_flags[] = {
&hf_isup_inn_indicator,
&hf_isup_numbering_plan_indicator,
NULL
};
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, indicators1_flags, ENC_NA);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
number_plan = (indicators2 & 0x70)>> 4;
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 1, 1, indicators2_flags, ENC_NA);
offset = 2;
tap_called_number = dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Called Party Number", hf_isup_called, hf_isup_called_party_odd_address_signal_digit,
hf_isup_called_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
number_plan == 1 ? CALLED_PARTY_NUMBER : NONE,
(indicators1 & 0x7f));
}
static void
dissect_isup_subsequent_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1;
gint offset = 0;
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
offset = 1;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Subsequent Number", hf_isup_subsequent_number, hf_isup_called_party_odd_address_signal_digit,
hf_isup_called_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
NONE, 0);
}
static void
dissect_isup_information_request_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
static const int * indicators[] = {
&hf_isup_calling_party_address_request_indicator,
&hf_isup_info_req_holding_indicator,
&hf_isup_calling_partys_category_request_indicator,
&hf_isup_charge_information_request_indicator,
&hf_isup_malicious_call_identification_request_indicator,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, INFO_REQUEST_IND_LENGTH, indicators, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Information request indicators: 0x%x", tvb_get_ntohs(parameter_tvb, 0));
}
static void
dissect_isup_information_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
static const int * indicators[] = {
&hf_isup_calling_party_address_response_indicator,
&hf_isup_hold_provided_indicator,
&hf_isup_calling_partys_category_response_indicator,
&hf_isup_charge_information_response_indicator,
&hf_isup_solicited_indicator,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, INFO_IND_LENGTH, indicators, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Information indicators: 0x%x", tvb_get_ntohs(parameter_tvb, 0));
}
static void
dissect_isup_continuity_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 continuity_indicators;
continuity_indicators = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_continuity_indicator, parameter_tvb, 0, CONTINUITY_IND_LENGTH, continuity_indicators);
proto_item_set_text(parameter_item, "Continuity indicators: 0x%x", continuity_indicators);
}
static void
dissect_isup_backward_call_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
static const int * indicators[] = {
&hf_isup_backw_call_charge_ind,
&hf_isup_backw_call_called_partys_status_ind,
&hf_isup_backw_call_called_partys_category_ind,
&hf_isup_backw_call_end_to_end_method_ind,
&hf_isup_backw_call_interworking_ind,
&hf_isup_backw_call_end_to_end_info_ind,
&hf_isup_backw_call_isdn_user_part_ind,
&hf_isup_backw_call_holding_ind,
&hf_isup_backw_call_isdn_access_ind,
&hf_isup_backw_call_echo_control_device_ind,
&hf_isup_backw_call_sccp_method_ind,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, indicators, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Backward Call Indicators: 0x%x", tvb_get_ntohs(parameter_tvb, 0));
}
void
dissect_isup_cause_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_cause_indicators, parameter_tvb, 0, -1, ENC_NA);
dissect_q931_cause_ie(parameter_tvb, 0, length,
parameter_tree,
hf_isup_cause_indicator, &tap_cause_value, isup_parameter_type_value);
proto_item_set_text(parameter_item, "Cause indicators, see Q.850 (%u byte%s length)", length , plurality(length, "", "s"));
}
static void
dissect_ansi_isup_cause_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 coding_standard;
guint8 cause_value;
int offset = 0;
guint length = tvb_reported_length(parameter_tvb);
coding_standard = (tvb_get_guint8(parameter_tvb, offset)&0x60)>>5;
switch (coding_standard) {
case 0:
proto_tree_add_item(parameter_tree, hf_isup_cause_location, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_ansi_isup_coding_standard, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
if (length == 0)
return;
proto_tree_add_item(parameter_tree, hf_isup_cause_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
cause_value = tvb_get_guint8(parameter_tvb, offset)&0x7f;
offset += 1;
length -= 1;
proto_item_set_text(parameter_item, "Cause indicators: %s (%u)",
val_to_str_ext_const(cause_value, &q850_cause_code_vals_ext, "spare"), cause_value);
if (length == 0) {
return;
}
proto_tree_add_item(parameter_tree, hf_isup_diagnostic, parameter_tvb, offset, length, ENC_NA);
return;
case 2:
proto_tree_add_item(parameter_tree, hf_isup_cause_location, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_ansi_isup_coding_standard, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
if (length == 0)
return;
proto_tree_add_item(parameter_tree, hf_ansi_isup_cause_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
cause_value = tvb_get_guint8(parameter_tvb, offset)&0x7f;
proto_item_set_text(parameter_item, "Cause indicators: %s (%u)",
val_to_str_ext_const(cause_value, &ansi_isup_cause_code_vals_ext, "spare"),
cause_value);
offset += 1;
length -= 1;
if (length == 0) {
return;
}
proto_tree_add_item(parameter_tree, hf_isup_diagnostic, parameter_tvb, offset, length, ENC_NA);
return;
default:
proto_tree_add_item(parameter_tree, hf_ansi_isup_coding_standard, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
proto_item_set_text(parameter_item, "Cause indicators(%u byte%s length)", length , plurality(length, "", "s"));
}
static void
dissect_isup_suspend_resume_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators;
indicators = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_suspend_resume_indicator, parameter_tvb, 0, SUSPEND_RESUME_IND_LENGTH, indicators);
proto_item_set_text(parameter_item, "Suspend/Resume indicator: 0x%x", indicators);
}
static void
dissect_isup_range_and_status_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_tree *range_tree;
int offset = 0;
guint8 range, actual_status_length;
range = tvb_get_guint8(parameter_tvb, 0) + 1;
proto_tree_add_uint_format(parameter_tree, hf_isup_range_indicator, parameter_tvb, offset, RANGE_LENGTH, range, "Range: %u", range);
offset = offset + RANGE_LENGTH;
actual_status_length = tvb_reported_length_remaining(parameter_tvb, offset);
if (actual_status_length > 0) {
range_tree = proto_tree_add_subtree(parameter_tree, parameter_tvb, offset, -1, ett_isup_range, NULL, "Status subfield");
if (range<9) {
proto_tree_add_uint_bits_format_value(range_tree, hf_isup_bitbucket, parameter_tvb, (offset*8)+(8-range), range,
tvb_get_guint8(parameter_tvb, offset), "%u bit 1", range);
}
} else {
expert_add_info(pinfo, parameter_item, &ei_isup_status_subfield_not_present);
}
proto_item_set_text(parameter_item, "Range (%u) and status", range);
}
static void
dissect_isup_circuit_group_supervision_message_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 cgs_message_type;
cgs_message_type = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_cgs_message_type, parameter_tvb, 0, CIRC_GRP_SV_MSG_TYPE_LENGTH, cgs_message_type);
proto_item_set_text(parameter_item, "Circuit group supervision message type: %s (%u)",
val_to_str_const(cgs_message_type, isup_cgs_message_type_value, "unknown"), cgs_message_type);
}
static void
dissect_isup_facility_ind_parameter(tvbuff_t *parameter_tvb, proto_item *parameter_item)
{
guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_item_set_text(parameter_item, "Facility indicator: %s (%u)" , val_to_str_const(indicator, isup_facility_ind_value, "spare"), indicator);
}
static void
dissect_isup_circuit_state_ind_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *circuit_state_item;
proto_tree *circuit_state_tree;
guint8 circuit_state;
gint offset = 0;
gint i = 0;
while (tvb_reported_length_remaining(parameter_tvb, offset) > 0) {
circuit_state_tree = proto_tree_add_subtree_format(parameter_tree, parameter_tvb, offset, -1,
ett_isup_circuit_state_ind, &circuit_state_item,
"Circuit# CIC+%u state", i);
circuit_state = tvb_get_guint8(parameter_tvb, offset);
if ((circuit_state & DC_8BIT_MASK) == 0) {
proto_tree_add_uint(circuit_state_tree, hf_isup_mtc_blocking_state1, parameter_tvb, offset, 1, circuit_state);
proto_item_append_text(circuit_state_item, ": %s",
val_to_str_const(circuit_state&BA_8BIT_MASK, isup_mtc_blocking_state_DC00_value, "unknown"));
}
else {
proto_tree_add_uint(circuit_state_tree, hf_isup_mtc_blocking_state2, parameter_tvb, offset, 1, circuit_state);
proto_tree_add_uint(circuit_state_tree, hf_isup_call_proc_state, parameter_tvb, offset, 1, circuit_state);
proto_tree_add_uint(circuit_state_tree, hf_isup_hw_blocking_state, parameter_tvb, offset, 1, circuit_state);
proto_item_append_text(circuit_state_item, ": %s", val_to_str_const(circuit_state&BA_8BIT_MASK, isup_mtc_blocking_state_DCnot00_value, "unknown"));
}
i++;
offset += 1;
}
proto_item_set_text(parameter_item, "Circuit state indicator (national use)");
}
static void
dissect_isup_event_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators;
indicators = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint_format_value(parameter_tree, hf_isup_event_ind, parameter_tvb, 0, EVENT_INFO_LENGTH, indicators,
"%s (%u)",
val_to_str_const(indicators & GFEDCBA_8BIT_MASK, isup_event_ind_value, "spare"),
indicators & GFEDCBA_8BIT_MASK);
proto_tree_add_boolean(parameter_tree, hf_isup_event_presentation_restricted_ind, parameter_tvb, 0, EVENT_INFO_LENGTH, indicators);
proto_item_set_text(parameter_item, "Event information: %s (%u)", val_to_str_const(indicators & GFEDCBA_8BIT_MASK, isup_event_ind_value, "spare"), indicators);
}
static void
dissect_isup_user_to_user_information_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_user_to_user_info, parameter_tvb, 0, -1, ENC_NA);
dissect_q931_user_user_ie(parameter_tvb, pinfo, 0, length,
parameter_tree);
proto_item_set_text(parameter_item, "User-to-user information,(%u byte%s length)",
length , plurality(length, "", "s"));
}
static void
dissect_isup_call_reference_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint32 call_id;
guint16 spc;
call_id = tvb_get_ntoh24(parameter_tvb, 0);
spc = tvb_get_letohs(parameter_tvb, CALL_ID_LENGTH) & 0x3FFF;
proto_tree_add_item(parameter_tree, hf_isup_call_identity, parameter_tvb, 0, CALL_ID_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_signalling_point_code, parameter_tvb, CALL_ID_LENGTH, SPC_LENGTH, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Call Reference: Call ID = %u, SPC = %u", call_id, spc);
}
static void
dissect_isup_access_transport_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree,
proto_item *parameter_item, packet_info *pinfo)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_access_transport_parameter_field, parameter_tvb, 0, -1, ENC_NA);
if (q931_ie_handle)
call_dissector(q931_ie_handle, parameter_tvb, pinfo, parameter_tree);
proto_item_set_text(parameter_item, "Access transport (%u byte%s length)",
length , plurality(length, "", "s"));
}
void
dissect_nsap(tvbuff_t *parameter_tvb, gint offset, gint len, proto_tree *parameter_tree)
{
guint8 afi;
guint icp;
afi = tvb_get_guint8(parameter_tvb, offset);
switch (afi) {
case 0x35:
proto_tree_add_item(parameter_tree, hf_isup_idp, parameter_tvb, offset, 3, ENC_NA);
proto_tree_add_uint(parameter_tree, hf_afi, parameter_tvb, offset, 1, afi);
offset = offset + 1;
icp = tvb_get_ntohs(parameter_tvb, offset);
proto_tree_add_uint(parameter_tree, hf_iana_icp, parameter_tvb, offset, 1, icp);
if (icp == 0) {
proto_tree_add_item(parameter_tree, hf_isup_dsp, parameter_tvb, offset + 2, 17, ENC_NA);
proto_tree_add_item(parameter_tree, hf_nsap_ipv6_addr, parameter_tvb, offset + 2,
16, ENC_NA);
}
else {
proto_tree_add_item(parameter_tree, hf_isup_dsp, parameter_tvb, offset + 2, 17, ENC_NA);
proto_tree_add_item(parameter_tree, hf_nsap_ipv4_addr, parameter_tvb, offset + 2, 4, ENC_BIG_ENDIAN);
}
break;
case 0x45:
case 0xC3:
proto_tree_add_item(parameter_tree, hf_isup_idp, parameter_tvb, offset, 9, ENC_NA);
proto_tree_add_uint(parameter_tree, hf_afi, parameter_tvb, offset, 1, afi);
proto_tree_add_item(parameter_tree, hf_isup_idi, parameter_tvb, offset + 1, 8, ENC_NA);
offset = offset +1;
dissect_e164_cc(parameter_tvb, parameter_tree, offset, E164_ENC_BCD);
proto_tree_add_uint_format_value(parameter_tree, hf_bicc_nsap_dsp_length, parameter_tvb, offset, 0,
(len-9), "%u (len %u -9)", (len-9), len);
proto_tree_add_item(parameter_tree, hf_bicc_nsap_dsp, parameter_tvb, offset + 8, (len - 9), ENC_NA);
break;
default:
proto_tree_add_uint(parameter_tree, hf_afi, parameter_tvb, offset, len, afi);
}
}
extern int dissect_codec_mode(proto_tree *tree, tvbuff_t *tvb, int offset, int len) {
guint8 tempdata;
static const int * active_code_sets[] = {
&hf_active_code_set_12_2,
&hf_active_code_set_10_2,
&hf_active_code_set_7_95,
&hf_active_code_set_7_40,
&hf_active_code_set_6_70,
&hf_active_code_set_5_90,
&hf_active_code_set_5_15,
&hf_active_code_set_4_75,
NULL
};
static const int * supported_code_sets[] = {
&hf_supported_code_set_12_2,
&hf_supported_code_set_10_2,
&hf_supported_code_set_7_95,
&hf_supported_code_set_7_40,
&hf_supported_code_set_6_70,
&hf_supported_code_set_5_90,
&hf_supported_code_set_5_15,
&hf_supported_code_set_4_75,
NULL
};
tempdata = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_Organization_Identifier , tvb, offset, 1, tempdata);
switch (tempdata) {
case ITU_T :
offset = offset + 1;
tempdata = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_codec_type , tvb, offset, 1, tempdata);
offset = offset + 1;
switch (tempdata) {
case G_711_64_A :
case G_711_64_U :
case G_711_56_A :
case G_711_56_U :
case G_722_SB_ADPCM :
case G_723_1 :
case G_723_1_Annex_A :
break;
case G_726_ADPCM :
case G_727_Embedded_ADPCM :
if (len > 2) {
proto_tree_add_item(tree, hf_isup_configuration_data, tvb, offset, 1, ENC_NA);
offset = offset + 1;
}
break;
case G_728 :
case G_729_CS_ACELP :
case G_729_Annex_B :
if (len > 2) {
proto_tree_add_item(tree, hf_isup_configuration_data, tvb, offset, 1, ENC_NA);
offset = offset + 1;
}
break;
default:
break;
}
break;
case ETSI:
offset = offset + 1;
tempdata = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_etsi_codec_type , tvb, offset, 1, tempdata);
if (len > 2) {
offset = offset + 1;
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_active_code_set,
ett_acs, active_code_sets, ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
}
if (len > 3) {
offset = offset + 1;
proto_tree_add_bitmask_with_flags(tree, tvb, offset, hf_supported_code_set,
ett_acs, supported_code_sets, ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
}
if (len > 4) {
offset = offset + 1;
proto_tree_add_item(tree, hf_optimisation_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_max_codec_modes, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
offset = offset + 1;
break;
default:
offset = offset + 1;
proto_tree_add_item(tree, hf_isup_unknown_organisation_identifier, tvb, offset, len, ENC_NA);
offset = offset + len - 1;
break;
}
return offset;
}
static int
dissect_codec(tvbuff_t *parameter_tvb, proto_tree *bat_ase_element_tree, gint length_indicator, gint offset, gint identifier)
{
static const int * compatibility_info[] = {
&hf_Instruction_ind_for_general_action,
&hf_Send_notification_ind_for_general_action,
&hf_Instruction_ind_for_pass_on_not_possible,
&hf_Send_notification_ind_for_pass_on_not_possible,
&hf_isup_extension_ind,
NULL
};
proto_tree_add_uint(bat_ase_element_tree , hf_bat_ase_identifier , parameter_tvb, offset - 1, 1, identifier);
proto_tree_add_uint(bat_ase_element_tree , hf_length_indicator , parameter_tvb, offset, 1, length_indicator);
offset = offset + 1;
proto_tree_add_bitmask_list(bat_ase_element_tree, parameter_tvb, offset, 1, compatibility_info, ENC_NA);
offset = dissect_codec_mode(bat_ase_element_tree, parameter_tvb, offset+1, length_indicator-1);
return offset;
}
static void
dissect_bat_ase_Encapsulated_Application_Information(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, gint offset)
{
gint list_end;
tvbuff_t *next_tvb;
proto_tree *bat_ase_tree, *bat_ase_element_tree, *bat_ase_iwfa_tree;
proto_item *bat_ase_element_item, *bat_ase_iwfa_item;
guint8 identifier, content, BCTP_Indicator_field_1, BCTP_Indicator_field_2;
guint8 tempdata, element_no, number_of_indicators;
guint16 sdp_length;
guint8 diagnostic_len;
guint8 length_ind_len;
guint tempdata16;
guint content_len, length_indicator;
guint duration;
guint diagnostic;
guint32 bncid, Local_BCU_ID;
element_no = 0;
bat_ase_tree = proto_tree_add_subtree(parameter_tree, parameter_tvb, offset, -1, ett_bat_ase, NULL,
"Bearer Association Transport (BAT) Application Service Element (ASE) Encapsulated Application Information:");
while (tvb_reported_length_remaining(parameter_tvb, offset) > 0) {
element_no = element_no + 1;
identifier = tvb_get_guint8(parameter_tvb, offset);
offset = offset + 1;
proto_tree_add_item(bat_ase_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
tempdata = tvb_get_guint8(parameter_tvb, offset);
if (tempdata & 0x80) {
length_indicator = tempdata & 0x7f;
length_ind_len = 1;
}
else {
offset = offset + 1;
tempdata16 = (tempdata & 0x7f);
length_indicator = tvb_get_guint8(parameter_tvb, offset)& 0x0f;
length_indicator = length_indicator << 7;
length_indicator = length_indicator + tempdata16;
length_ind_len = 2;
}
bat_ase_element_tree = proto_tree_add_subtree_format(bat_ase_tree, parameter_tvb,
(offset - length_ind_len), (length_indicator + 2),
ett_bat_ase_element, &bat_ase_element_item,
"BAT ASE Element %u, Identifier: %s", element_no,
val_to_str_ext(identifier, &bat_ase_list_of_Identifiers_vals_ext, "unknown (%u)"));
if (identifier != CODEC) {
proto_tree_add_uint(bat_ase_element_tree , hf_bat_ase_identifier , parameter_tvb,
offset - length_ind_len, 1, identifier);
proto_tree_add_uint(bat_ase_element_tree , hf_length_indicator , parameter_tvb,
offset - length_ind_len + 1, length_ind_len, length_indicator);
offset = offset + 1;
proto_tree_add_item(bat_ase_element_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bat_ase_element_tree, hf_Send_notification_ind_for_pass_on_not_possible, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bat_ase_element_tree, hf_Instruction_ind_for_pass_on_not_possible, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bat_ase_element_tree, hf_Send_notification_ind_for_general_action, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bat_ase_element_tree, hf_Instruction_ind_for_general_action, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset = offset + 1;
}
content_len = length_indicator - 1 ;
switch (identifier) {
case ACTION_INDICATOR :
content = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(bat_ase_element_tree, hf_Action_Indicator , parameter_tvb, offset, 1, content);
proto_item_append_text(bat_ase_element_item, " - %s",
val_to_str_ext(content, &bat_ase_action_indicator_field_vals_ext, "unknown (%u)"));
offset = offset + 1;
break;
case BACKBONE_NETWORK_CONNECTION_IDENTIFIER :
bncid = tvb_get_ntohl(parameter_tvb, offset);
switch (content_len) {
case 1:
bncid = bncid & 0x000000ff;
break;
case 2:
bncid = bncid & 0x0000ffff;
break;
case 3:
bncid = bncid & 0x00ffffff;
break;
case 4:;
default:;
}
proto_tree_add_uint_format(bat_ase_element_tree, hf_bncid, parameter_tvb, offset, content_len, bncid, "BNCId: 0x%08x", bncid);
proto_item_append_text(bat_ase_element_item, " - 0x%08x", bncid);
offset = offset + content_len;
break;
case INTERWORKING_FUNCTION_ADDRESS :
bat_ase_iwfa_item = proto_tree_add_item(bat_ase_element_tree, hf_bat_ase_biwfa, parameter_tvb, offset, content_len,
ENC_NA);
bat_ase_iwfa_tree = proto_item_add_subtree(bat_ase_iwfa_item , ett_bat_ase_iwfa);
dissect_nsap(parameter_tvb, offset, content_len, bat_ase_iwfa_tree);
offset = offset + content_len;
break;
case CODEC_LIST :
list_end = offset + content_len;
while (offset < (list_end - 1)) {
identifier = tvb_get_guint8(parameter_tvb, offset);
offset = offset + 1;
tempdata = tvb_get_guint8(parameter_tvb, offset);
if (tempdata & 0x80) {
length_indicator = tempdata & 0x7f;
}
else {
offset = offset +1;
length_indicator = tvb_get_guint8(parameter_tvb, offset);
length_indicator = length_indicator << 7;
length_indicator = length_indicator & (tempdata & 0x7f);
}
offset = dissect_codec(parameter_tvb, bat_ase_element_tree, length_indicator , offset, identifier);
}
break;
case CODEC :
offset = dissect_codec(parameter_tvb, bat_ase_element_tree, length_indicator , offset, identifier);
break;
case BAT_COMPATIBILITY_REPORT :
tempdata = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(bat_ase_element_tree, hf_BAT_ASE_Comp_Report_Reason, parameter_tvb, offset, 1, tempdata);
offset = offset + 1;
diagnostic_len = content_len - 1;
while (diagnostic_len > 0) {
tempdata = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(bat_ase_element_tree, hf_BAT_ASE_Comp_Report_ident, parameter_tvb, offset, 1, tempdata);
offset = offset + 1;
diagnostic = tvb_get_letohs(parameter_tvb, offset);
proto_tree_add_uint(bat_ase_element_tree, hf_BAT_ASE_Comp_Report_diagnostic, parameter_tvb, offset, 2, diagnostic);
offset = offset + 2;
diagnostic_len = diagnostic_len - 3;
}
break;
case BEARER_NETWORK_CONNECTION_CHARACTERISTICS :
tempdata = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(bat_ase_element_tree, hf_characteristics , parameter_tvb,
offset, 1, tempdata);
proto_item_append_text(bat_ase_element_item, " - %s",
val_to_str_ext(tempdata, &bearer_network_connection_characteristics_vals_ext, "unknown (%u)"));
offset = offset + content_len;
break;
case BEARER_CONTROL_INFORMATION :
BCTP_Indicator_field_1 = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(bat_ase_element_tree, hf_BCTP_Version_Indicator,
parameter_tvb, offset, 1, BCTP_Indicator_field_1);
proto_tree_add_boolean(bat_ase_element_tree, hf_BVEI,
parameter_tvb, offset, 1, BCTP_Indicator_field_1);
offset = offset + 1;
BCTP_Indicator_field_2 = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(bat_ase_element_tree, hf_Tunnelled_Protocol_Indicator ,
parameter_tvb, offset, 1, BCTP_Indicator_field_2);
proto_tree_add_boolean(bat_ase_element_tree, hf_TPEI,
parameter_tvb, offset, 1, BCTP_Indicator_field_2);
offset = offset + 1;
sdp_length = (length_indicator) - 3;
if (sdp_length > tvb_reported_length_remaining(parameter_tvb, offset)) {
next_tvb = tvb_new_subset_remaining(parameter_tvb, offset);
} else {
next_tvb = tvb_new_subset_length(parameter_tvb, offset, sdp_length);
}
if (BCTP_Indicator_field_2==0x20) {
call_dissector(sdp_handle, next_tvb, pinfo, bat_ase_element_tree);
} else {
proto_tree_add_item(bat_ase_element_tree, hf_isup_tunnelled_protocol_data, next_tvb, 0, -1, ENC_NA);
}
offset = offset + sdp_length;
break;
case BEARER_CONTROL_TUNNELLING :
tempdata = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_boolean(bat_ase_element_tree, hf_bearer_control_tunneling , parameter_tvb, offset, 1, (tempdata & 0x01));
if (tempdata & 0x01)
proto_item_append_text(bat_ase_element_item, " - Tunnelling to be used ");
offset = offset + content_len;
break;
case BEARER_CONTROL_UNIT_IDENTIFIER :
tempdata = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(bat_ase_element_tree, hf_isup_network_id_length_indicator, parameter_tvb, offset, 1, ENC_NA);
offset = offset + 1;
if (tempdata > 0) {
proto_tree_add_item(bat_ase_element_tree, hf_isup_network_id, parameter_tvb, offset, tempdata, ENC_NA);
offset += tempdata;
}
Local_BCU_ID = tvb_get_letohl(parameter_tvb, offset);
proto_tree_add_uint_format_value(bat_ase_element_tree, hf_Local_BCU_ID , parameter_tvb, offset, 4,
Local_BCU_ID , "0x%08x", Local_BCU_ID);
offset += 4;
break;
case SIGNAL :
break;
case BEARER_REDIRECTION_CAPABILITY :
tempdata = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_boolean(bat_ase_element_tree, hf_late_cut_through_cap_ind , parameter_tvb, offset, 1, tempdata);
offset = offset + content_len;
break;
case BEARER_REDIRECTION_INDICATORS :
number_of_indicators = 0;
while (number_of_indicators < content_len) {
tempdata = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(bat_ase_element_tree, hf_bat_ase_bearer_redir_ind , parameter_tvb, offset, 1, tempdata);
offset = offset + 1;
number_of_indicators = number_of_indicators + 1;
}
break;
case SIGNAL_TYPE :
tempdata = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(bat_ase_element_tree, hf_bat_ase_signal , parameter_tvb, offset, 1, tempdata);
offset = offset + content_len;
break;
case DURATION :
duration = tvb_get_letohs(parameter_tvb, offset);
proto_tree_add_uint(bat_ase_element_tree, hf_bat_ase_duration , parameter_tvb, offset, 2, duration);
offset = offset + content_len;
break;
default :
proto_tree_add_item(bat_ase_element_tree, hf_bat_ase_default, parameter_tvb, offset, content_len, ENC_NA);
offset = offset + content_len;
}
}
}
static void
dissect_isup_application_transport_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 si_and_apm_seg_ind;
guint8 apm_Segmentation_local_ref = 0;
guint16 aci16;
gint offset = 0;
guint8 octet;
guint length = tvb_reported_length(parameter_tvb);
gboolean more_frag;
gboolean save_fragmented;
tvbuff_t *new_tvb = NULL;
tvbuff_t *next_tvb = NULL;
fragment_head *frag_msg = NULL;
static const int * apm_flags[] = {
&hf_isup_extension_ind,
&hf_isup_apm_si_ind,
&hf_isup_apm_segmentation_ind,
NULL
};
static const int * app_trans_flags[] = {
&hf_isup_extension_ind,
&hf_isup_app_Send_notification_ind,
&hf_isup_app_Release_call_ind,
NULL
};
static const int * app_field_flags[] = {
&hf_isup_extension_ind,
&hf_isup_app_cont_ident,
NULL
};
proto_item_set_text(parameter_item, "Application transport, (%u byte%s length)", length , plurality(length, "", "s"));
aci16 = tvb_get_guint8(parameter_tvb, offset);
if ((aci16 & H_8BIT_MASK) == 0x80) {
aci16 = aci16 & 0x7f;
proto_tree_add_bitmask(parameter_tree, parameter_tvb, offset, hf_isup_app_transport_param_field8, ett_app_transport_fields, app_field_flags, ENC_NA);
offset = offset + 1;
}
else {
proto_tree_add_item(parameter_tree, hf_isup_app_transport_param_field16, parameter_tvb, offset, 2, ENC_BIG_ENDIAN);
aci16 = (aci16<<8) | (tvb_get_guint8(parameter_tvb, offset) & 0x7f);
proto_tree_add_uint(parameter_tree, hf_isup_app_cont_ident , parameter_tvb, offset, 2, aci16);
offset = offset + 2;
}
proto_tree_add_bitmask(parameter_tree, parameter_tvb, offset, hf_isup_app_transport_instruction_indicator, ett_app_transport, app_trans_flags, ENC_NA);
offset = offset + 1;
si_and_apm_seg_ind = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_bitmask(parameter_tree, parameter_tvb, offset, hf_isup_apm_seg_indicator, ett_apm_seg_indicator, apm_flags, ENC_NA);
offset = offset + 1;
if ((si_and_apm_seg_ind & H_8BIT_MASK) == 0x00) {
apm_Segmentation_local_ref = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_apm_slr, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset = offset + 1;
}
if (aci16 > 3) {
octet = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_isup_orig_addr_len, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (octet != 0) {
proto_tree_add_item(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(parameter_tree, hf_isup_inn_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(parameter_tree, hf_isup_address_digits, parameter_tvb, offset, octet - 2, ENC_NA);
offset = offset + octet - 2;
}
octet = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_isup_dest_addr_len, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (octet != 0) {
proto_tree_add_item(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(parameter_tree, hf_isup_inn_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(parameter_tree, hf_isup_address_digits, parameter_tvb, offset, octet - 2, ENC_NA);
offset = offset + octet - 2;
}
}
if (isup_apm_desegment) {
if ((si_and_apm_seg_ind != 0xc0) && ((si_and_apm_seg_ind & H_8BIT_MASK)!=0x80)) {
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
more_frag = TRUE;
if (si_and_apm_seg_ind == 0)
more_frag = FALSE;
frag_msg = fragment_add_seq_next(&isup_apm_msg_reassembly_table,
parameter_tvb, offset,
pinfo,
(apm_Segmentation_local_ref & 0x7f),
NULL,
tvb_reported_length_remaining(parameter_tvb, offset),
more_frag);
if ((si_and_apm_seg_ind & 0x3f) !=0 && (si_and_apm_seg_ind &0x40) !=0) {
fragment_set_tot_len(&isup_apm_msg_reassembly_table,
pinfo,
apm_Segmentation_local_ref & 0x7f,
NULL,
(si_and_apm_seg_ind & 0x3f));
}
new_tvb = process_reassembled_data(parameter_tvb, offset, pinfo,
"Reassembled ISUP", frag_msg, &isup_apm_msg_frag_items,
NULL, parameter_tree);
if (frag_msg) {
col_append_str(pinfo->cinfo, COL_INFO,
" (Message Reassembled)");
} else {
col_append_str(pinfo->cinfo, COL_INFO,
" (Message fragment)");
}
pinfo->fragmented = save_fragmented;
}
}
if (offset == (gint)length) {
proto_tree_add_item(parameter_tree, hf_isup_apm_user_info_field, parameter_tvb, offset, 0, ENC_NA);
return;
}
if (new_tvb) {
next_tvb = new_tvb;
} else {
next_tvb = tvb_new_subset_remaining(parameter_tvb, offset);
}
proto_tree_add_item(parameter_tree, hf_isup_apm_user_info_field, parameter_tvb, offset, -1, ENC_NA);
switch (aci16 & 0x7fff) {
case 3:
dissect_charging_ase_ChargingMessageType_PDU(next_tvb, pinfo, parameter_tree, NULL);
break;
case 5:
dissect_bat_ase_Encapsulated_Application_Information(next_tvb, pinfo, parameter_tree, 0);
break;
default:
expert_add_info_format(pinfo, parameter_tree, &ei_isup_not_dissected_yet, "No further dissection of APM-user information field");
break;
}
}
static void
dissect_isup_optional_forward_call_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 ind;
static const int * indicators[] = {
&hf_isup_cug_call_ind,
&hf_isup_simple_segmentation_ind,
&hf_isup_connected_line_identity_request_ind,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, OPTIONAL_FORWARD_CALL_IND_LENGTH, indicators, ENC_NA);
ind = tvb_get_guint8(parameter_tvb, 0);
proto_item_set_text(parameter_item, "Optional forward call indicators: %s (%u)",
val_to_str_const(ind & BA_8BIT_MASK, isup_CUG_call_ind_value, "spare"),
ind);
}
void
dissect_isup_calling_party_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1, indicators2;
gint offset = 0;
gint number_plan;
static const int * indicators1_fields[] = {
&hf_isup_odd_even_indicator,
&hf_isup_calling_party_nature_of_address_indicator,
NULL
};
static const int * indicators2_fields[] = {
&hf_isup_ni_indicator,
&hf_isup_numbering_plan_indicator,
&hf_isup_address_presentation_restricted_indicator,
&hf_isup_screening_indicator,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, indicators1_fields, ENC_NA);
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 1, 1, indicators2_fields, ENC_NA);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
number_plan = (indicators2 & 0x70)>> 4;
offset = 2;
tap_calling_number = dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Calling Party Number", hf_isup_calling, hf_isup_calling_party_odd_address_signal_digit,
hf_isup_calling_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
number_plan == 1 ? CALLING_PARTY_NUMBER : NONE,
(indicators1 & 0x7f));
}
void
dissect_isup_original_called_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1;
gint offset = 0;
static const int * indicators1_fields[] = {
&hf_isup_odd_even_indicator,
&hf_isup_calling_party_nature_of_address_indicator,
NULL
};
static const int * indicators2_fields[] = {
&hf_isup_numbering_plan_indicator,
&hf_isup_address_presentation_restricted_indicator,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, indicators1_fields, ENC_NA);
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 1, 1, indicators2_fields, ENC_NA);
offset = 2;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Original Called Number", hf_isup_original_called_number,
hf_isup_calling_party_odd_address_signal_digit,
hf_isup_calling_party_even_address_signal_digit,
((indicators1 & 0x80) == 0), NONE, 0);
}
void
dissect_isup_redirecting_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1;
gint offset = 0;
static const int * indicators1_fields[] = {
&hf_isup_odd_even_indicator,
&hf_isup_calling_party_nature_of_address_indicator,
NULL
};
static const int * indicators2_fields[] = {
&hf_isup_numbering_plan_indicator,
&hf_isup_address_presentation_restricted_indicator,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, indicators1_fields, ENC_NA);
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 1, 1, indicators2_fields, ENC_NA);
offset = 2;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Redirecting Number", hf_isup_redirecting, hf_isup_calling_party_odd_address_signal_digit,
hf_isup_calling_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
NONE, 0);
}
static void
dissect_isup_redirection_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1;
gint offset = 0;
static const int * indicators1_fields[] = {
&hf_isup_odd_even_indicator,
&hf_isup_called_party_nature_of_address_indicator,
NULL
};
static const int * indicators2_fields[] = {
&hf_isup_inn_indicator,
&hf_isup_numbering_plan_indicator,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, indicators1_fields, ENC_NA);
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 1, 1, indicators2_fields, ENC_NA);
offset = 2;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Redirection Number", hf_isup_redirection_number, hf_isup_called_party_odd_address_signal_digit,
hf_isup_called_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
NONE, 0);
}
static void
dissect_isup_connection_request_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint32 local_ref;
guint16 spc;
guint8 protocol_class, credit, offset = 0;
local_ref = tvb_get_ntoh24(parameter_tvb, 0);
proto_tree_add_item(parameter_tree, hf_isup_local_reference, parameter_tvb, offset, LOCAL_REF_LENGTH, ENC_BIG_ENDIAN);
offset = LOCAL_REF_LENGTH;
spc = tvb_get_letohs(parameter_tvb, offset) & 0x3FFF;
proto_tree_add_item(parameter_tree, hf_isup_signalling_point_code, parameter_tvb, offset, SPC_LENGTH, ENC_BIG_ENDIAN);
offset += SPC_LENGTH;
protocol_class = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_isup_protocol_class, parameter_tvb, offset, PROTOCOL_CLASS_LENGTH, ENC_BIG_ENDIAN);
offset += PROTOCOL_CLASS_LENGTH;
credit = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_isup_credit, parameter_tvb, offset, CREDIT_LENGTH, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item,
"Connection request: Local Reference = %u, SPC = %u, Protocol Class = %u, Credit = %u",
local_ref, spc, protocol_class, credit);
}
void
dissect_isup_redirection_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
if (tvb_reported_length(parameter_tvb) == 2) {
guint16 indicators;
indicators = tvb_get_ntohs(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_redirecting_ind, parameter_tvb, 0, REDIRECTION_INFO_LENGTH, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_original_redirection_reason, parameter_tvb, 0, REDIRECTION_INFO_LENGTH, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_redirection_counter, parameter_tvb, 0, REDIRECTION_INFO_LENGTH, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_redirection_reason, parameter_tvb, 0, REDIRECTION_INFO_LENGTH, indicators);
proto_item_set_text(parameter_item, "Redirection Information");
}
else {
guint16 indicators;
indicators = tvb_get_guint8(parameter_tvb, 0) * 0x100;
proto_tree_add_uint(parameter_tree, hf_isup_redirecting_ind, parameter_tvb, 0, 1, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_original_redirection_reason, parameter_tvb, 0, 1, indicators);
proto_item_set_text(parameter_item, "Redirection Information (2nd octet not present since ISUP '88)");
}
}
static void
dissect_isup_closed_user_group_interlock_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
char NI_digits[5] = "";
guint8 digit_pair;
guint16 bin_code;
digit_pair = tvb_get_guint8(parameter_tvb, 0);
NI_digits[0] = number_to_char((digit_pair & HGFE_8BIT_MASK) / 0x10);
NI_digits[1] = number_to_char(digit_pair & DCBA_8BIT_MASK);
digit_pair = tvb_get_guint8(parameter_tvb, 1);
NI_digits[2] = number_to_char((digit_pair & HGFE_8BIT_MASK) / 0x10);
NI_digits[3] = number_to_char(digit_pair & DCBA_8BIT_MASK);
NI_digits[4] = '\0';
proto_tree_add_string(parameter_tree, hf_isup_network_identity, parameter_tvb, 0, 2, NI_digits);
bin_code = tvb_get_ntohs(parameter_tvb, 2);
proto_tree_add_item(parameter_tree, hf_isup_binary_code, parameter_tvb, 2, 2, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Closed user group interlock code: NI = %s, Binary code = 0x%x", NI_digits, bin_code);
}
static void
dissect_isup_user_service_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_user_service_information, parameter_tvb, 0, length, ENC_NA);
proto_item_set_text(parameter_item, "User service information, (%u byte%s length)",
length , plurality(length, "", "s"));
dissect_q931_bearer_capability_ie(parameter_tvb,
0, length,
parameter_tree);
}
static void
dissect_isup_signalling_point_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 spc;
spc = tvb_get_letohs(parameter_tvb, 0) & 0x3FFF;
proto_tree_add_item(parameter_tree, hf_isup_signalling_point_code, parameter_tvb, 0, SIGNALLING_POINT_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Signalling point code: %u", spc);
}
static void
dissect_isup_connected_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1;
gint offset = 0;
static const int * indicators1_fields[] = {
&hf_isup_odd_even_indicator,
&hf_isup_calling_party_nature_of_address_indicator,
NULL
};
static const int * indicators2_fields[] = {
&hf_isup_numbering_plan_indicator,
&hf_isup_address_presentation_restricted_indicator,
&hf_isup_screening_indicator,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, indicators1_fields, ENC_NA);
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 1, 1, indicators2_fields, ENC_NA);
offset = 2;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Connected Number", hf_isup_connected_number, hf_isup_calling_party_odd_address_signal_digit,
hf_isup_calling_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
NONE, 0);
}
static void
dissect_isup_transit_network_selection_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1;
gint offset = 0;
static const int * indicators_fields[] = {
&hf_isup_odd_even_indicator,
&hf_isup_type_of_network_identification,
&hf_isup_network_identification_plan,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, indicators_fields, ENC_NA);
indicators1 = tvb_get_guint8(parameter_tvb, 0);
offset = 1;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Transit network selection", hf_isup_transit_network_selection, hf_isup_calling_party_odd_address_signal_digit,
hf_isup_calling_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
NONE, 0);
}
static void
dissect_isup_circuit_assignment_map_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 map_type;
map_type = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_map_type, parameter_tvb, 0, 1, map_type);
proto_tree_add_item(parameter_tree, hf_isup_circuit_assignment_map, parameter_tvb, 1, 5, ENC_NA);
proto_item_set_text(parameter_item, "Circuit assignment map");
}
static void
dissect_isup_automatic_congestion_level_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 congestion_level;
congestion_level = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_automatic_congestion_level, parameter_tvb, 0, AUTO_CONGEST_LEVEL_LENGTH, congestion_level);
proto_item_set_text(parameter_item, "Automatic congestion level: %s (%u)",
val_to_str_const(congestion_level, isup_auto_congestion_level_value, "spare"), congestion_level);
}
static void
dissect_isup_optional_backward_call_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
static const int * indicators[] = {
&hf_isup_inband_information_ind,
&hf_isup_call_diversion_may_occur_ind,
&hf_isup_simple_segmentation_ind,
&hf_isup_mlpp_user_ind,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, OPTIONAL_BACKWARD_CALL_IND_LENGTH, indicators, ENC_NA);
proto_item_set_text(parameter_item, "Optional backward call indicators: 0x%x", tvb_get_guint8(parameter_tvb, 0));
}
static void
dissect_isup_user_to_user_indicators_parameter(tvbuff_t *parameter_tvb,
proto_tree *parameter_tree,
proto_item *parameter_item)
{
guint8 indicators;
static const int * req_fields[] = {
&hf_isup_UUI_type,
&hf_isup_UUI_req_service1,
&hf_isup_UUI_req_service2,
&hf_isup_UUI_req_service3,
NULL
};
static const int * res_fields[] = {
&hf_isup_UUI_type,
&hf_isup_UUI_res_service1,
&hf_isup_UUI_res_service2,
&hf_isup_UUI_res_service3,
&hf_isup_UUI_network_discard_ind,
NULL
};
indicators = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_UUI_type, parameter_tvb, 0, 1, indicators);
if ((indicators & 0x01) == 0) {
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, req_fields, ENC_NA);
}
else {
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, res_fields, ENC_NA);
}
proto_item_set_text(parameter_item, "User-to-user indicators: 0x%x", indicators);
}
static void
dissect_isup_original_isc_point_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 spc;
spc = tvb_get_letohs(parameter_tvb, 0) & 0x3FFF;
proto_tree_add_item(parameter_tree, hf_isup_origination_isc_point_code, parameter_tvb, 0, ORIGINAL_ISC_POINT_CODE_LENGTH, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Origination ISC point code: %u", spc);
}
static void
dissect_isup_generic_notification_indicator_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators;
indicators = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_notification_indicator, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Generic notification indicator: %s",
val_to_str_ext((indicators&0x7f), &q763_generic_notification_indicator_vals_ext, "Reserved (0x%X)"));
}
static void
dissect_isup_call_history_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 info;
info = tvb_get_ntohs(parameter_tvb, 0);
proto_tree_add_uint_format_value(parameter_tree, hf_isup_call_history_info, parameter_tvb, 0, CALL_HISTORY_INFO_LENGTH, info, "propagation delay = %u ms", info);
proto_item_set_text(parameter_item, "Call history info: propagation delay = %u ms", info);
}
static void
dissect_isup_access_delivery_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_access_delivery_ind, parameter_tvb, 0, ACCESS_DELIVERY_INFO_LENGTH, indicator);
proto_item_set_text(parameter_item, "Access delivery information: 0x%x", indicator);
}
static void
dissect_isup_network_specific_facility_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_network_specific_facility, parameter_tvb, 0, length, ENC_NA);
proto_item_set_text(parameter_item, "Network specific facility (%u byte%s length)", length , plurality(length, "", "s"));
}
static void
dissect_isup_user_service_information_prime_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_user_service_information_prime, parameter_tvb, 0, length, ENC_NA);
dissect_q931_bearer_capability_ie(parameter_tvb,
0, length,
parameter_tree);
proto_item_set_text(parameter_item, "User service information prime, (%u byte%s length)",
length , plurality(length, "", "s"));
}
static void
dissect_isup_propagation_delay_counter_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 info;
info = tvb_get_ntohs(parameter_tvb, 0);
proto_tree_add_uint_format_value(parameter_tree, hf_isup_propagation_delay_counter, parameter_tvb, 0, PROPAGATION_DELAY_COUNT_LENGTH, info, "%u ms", info);
proto_item_set_text(parameter_item, "Propagation delay counter = %u ms", info);
}
static void
dissect_isup_remote_operations_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_remote_operations, parameter_tvb, 0, length, ENC_NA);
proto_item_set_text(parameter_item, "Remote operations (%u byte%s length)", length , plurality(length, "", "s"));
}
static void
dissect_isup_service_activation_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint i;
guint8 feature_code;
guint length = tvb_reported_length(parameter_tvb);
for (i=0; i<length; i++) {
feature_code = tvb_get_guint8(parameter_tvb, i);
proto_tree_add_uint_format(parameter_tree, hf_isup_feature_code, parameter_tvb, i, 1, feature_code, "Feature Code %u: %u", i+1, feature_code);
}
proto_item_set_text(parameter_item, "Service Activation (%u byte%s length)", length , plurality(length, "", "s"));
}
static void
dissect_isup_user_teleservice_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_user_teleservice_information, parameter_tvb, 0, length, ENC_NA);
dissect_q931_high_layer_compat_ie(parameter_tvb, 0, length, parameter_tree);
proto_item_set_text(parameter_item,
"User teleservice information");
}
static void
dissect_isup_transmission_medium_used_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 transmission_medium_requirement;
transmission_medium_requirement = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_transmission_medium_requirement_prime,
parameter_tvb, 0, TRANSMISSION_MEDIUM_RQMT_PRIME_LENGTH, transmission_medium_requirement);
proto_item_set_text(parameter_item,
"Transmission medium used: %u (%s)",
transmission_medium_requirement,
val_to_str_ext_const(transmission_medium_requirement,
&isup_transmission_medium_requirement_prime_value_ext,
"spare/reserved"));
}
static void
dissect_isup_call_diversion_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint_format_value(parameter_tree, hf_isup_call_diversion_information, parameter_tvb, 0, CALL_DIV_INFO_LENGTH, indicator,
"0x%x (refer to 3.6/Q.763 for detailed decoding)", indicator);
proto_item_set_text(parameter_item, "Call diversion information: 0x%x", indicator);
}
static void
dissect_isup_echo_control_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
static const int * info[] = {
&hf_isup_OECD_inf_ind,
&hf_isup_IECD_inf_ind,
&hf_isup_OECD_req_ind,
&hf_isup_IECD_req_ind,
NULL
};
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_bitmask(parameter_tree, parameter_tvb, 0, hf_isup_echo_control_information, ett_echo_control_information, info, ENC_NA);
proto_item_set_text(parameter_item, "Echo control information: 0x%x", indicator);
}
static void
dissect_isup_message_compatibility_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint length = tvb_reported_length(parameter_tvb);
gint offset = 0;
static const int * params[] = {
&hf_isup_transit_at_intermediate_exchange_ind,
&hf_isup_Release_call_ind,
&hf_isup_Send_notification_ind,
&hf_isup_Discard_message_ind_value,
&hf_isup_pass_on_not_possible_indicator2,
&hf_isup_Broadband_narrowband_interworking_ind2,
&hf_isup_extension_ind,
NULL
};
proto_tree_add_bitmask(parameter_tree, parameter_tvb, offset, hf_isup_message_compatibility_information, ett_message_compatibility_information, params, ENC_NA);
proto_item_set_text(parameter_item, "Message compatibility information (%u byte%s length)",
length , plurality(length, "", "s"));
}
static void
dissect_isup_parameter_compatibility_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint length = tvb_reported_length(parameter_tvb);
guint len = length;
guint8 upgraded_parameter, upgraded_parameter_no;
guint8 offset;
guint8 instruction_indicators;
static const int * indicator_flags[] = {
&hf_isup_transit_at_intermediate_exchange_ind,
&hf_isup_Release_call_ind,
&hf_isup_Send_notification_ind,
&hf_isup_Discard_message_ind_value,
&hf_isup_Discard_parameter_ind,
&hf_isup_Pass_on_not_possible_indicator,
&hf_isup_extension_ind,
NULL
};
offset = 0;
upgraded_parameter_no = 0;
proto_item_set_text(parameter_item, "Parameter compatibility information (%u byte%s length)", length , plurality(length, "", "s"));
while (len > 0) {
upgraded_parameter_no = upgraded_parameter_no + 1;
upgraded_parameter = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint_format(parameter_tree, hf_isup_upgraded_parameter, parameter_tvb, offset, 1, upgraded_parameter,
"Upgraded parameter no: %u = %s", upgraded_parameter_no,
val_to_str_ext(upgraded_parameter, &isup_parameter_type_value_ext, "unknown (%u)"));
offset += 1;
len -= 1;
instruction_indicators = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_bitmask(parameter_tree, parameter_tvb, offset, hf_isup_instruction_indicators, ett_instruction_indicators, indicator_flags, ENC_NA);
offset += 1;
len -= 1;
if (!(instruction_indicators & H_8BIT_MASK)) {
if (len == 0)
return;
instruction_indicators = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(parameter_tree, hf_isup_Broadband_narrowband_interworking_ind,
parameter_tvb, offset, 1, instruction_indicators);
offset += 1;
len -= 1;
}
if (len == 0)
return;
;
}
}
static void
dissect_isup_mlpp_precedence_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
char NI_digits[5] = "";
const char *temp_text = "";
guint8 digit_pair;
guint32 bin_code;
proto_tree_add_item(parameter_tree, hf_isup_look_forward_busy, parameter_tvb, 0, 1, ENC_NA);
proto_tree_add_item(parameter_tree, hf_isup_precedence_level, parameter_tvb, 0, 1, ENC_NA);
digit_pair = tvb_get_guint8(parameter_tvb, 1);
NI_digits[0] = number_to_char((digit_pair & HGFE_8BIT_MASK) / 0x10);
NI_digits[1] = number_to_char(digit_pair & DCBA_8BIT_MASK);
digit_pair = tvb_get_guint8(parameter_tvb, 2);
NI_digits[2] = number_to_char((digit_pair & HGFE_8BIT_MASK) / 0x10);
NI_digits[3] = number_to_char(digit_pair & DCBA_8BIT_MASK);
NI_digits[4] = '\0';
proto_tree_add_string(parameter_tree, hf_isup_network_identity, parameter_tvb, 1, 2, NI_digits);
bin_code = tvb_get_ntoh24(parameter_tvb, 3);
proto_tree_add_item(parameter_tree, hf_isup_mlpp_service_domain, parameter_tvb, 3, 3, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item,
"MLPP precedence: Prec = %s, NI = %s, MLPP service domain = 0x%x", temp_text, NI_digits, bin_code);
}
static void
dissect_isup_mcid_request_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint_format_value(parameter_tree, hf_isup_mcid_request_indicators, parameter_tvb, 0, MCID_REQUEST_IND_LENGTH, indicator, "0x%x (MCID requested by Bit1=1, Holding requested by Bit2=1 see 3.31/Q.763)", indicator);
proto_item_set_text(parameter_item, "MCID request indicators: 0x%x", indicator);
}
static void
dissect_isup_mcid_response_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint_format_value(parameter_tree, hf_isup_mcid_response_indicators, parameter_tvb, 0, MCID_RESPONSE_IND_LENGTH, indicator, "0x%x (MCID included if Bit1=1, Holding provided if Bit2=1 see 3.32/Q.763)", indicator);
proto_item_set_text(parameter_item, "MCID response indicators: 0x%x", indicator);
}
static void
dissect_isup_hop_counter_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 counter;
counter = tvb_get_guint8(parameter_tvb, 0) & EDCBA_8BIT_MASK;
proto_tree_add_item(parameter_tree, hf_isup_hop_counter, parameter_tvb, 0, HOP_COUNTER_LENGTH, ENC_NA);
proto_item_set_text(parameter_item, "Hop counter: %u", counter);
}
static void
dissect_isup_orig_line_info_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 info;
info = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_item(parameter_tree, hf_isup_originating_line_info, parameter_tvb, 0, ORIG_LINE_INFO_LENGTH, ENC_NA);
proto_item_set_text(parameter_item, "Originating line info: %u (ANI II if < 51, reserved otherwise)", info);
}
static void
dissect_isup_transmission_medium_requirement_prime_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 transmission_medium_requirement;
transmission_medium_requirement = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_transmission_medium_requirement_prime,
parameter_tvb, 0, TRANSMISSION_MEDIUM_RQMT_PRIME_LENGTH, transmission_medium_requirement);
proto_item_set_text(parameter_item,
"Transmission medium requirement prime: %u (%s)",
transmission_medium_requirement,
val_to_str_ext_const(transmission_medium_requirement,
&isup_transmission_medium_requirement_prime_value_ext,
"spare/reserved"));
}
void
dissect_isup_location_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1, indicators2;
gint offset = 0;
static const int * indicators1_fields[] = {
&hf_isup_odd_even_indicator,
&hf_isup_calling_party_nature_of_address_indicator,
NULL
};
static const int * indicators2_fields[] = {
&hf_isup_inn_indicator,
&hf_isup_numbering_plan_indicator,
&hf_isup_address_presentation_restricted_indicator,
&hf_isup_screening_indicator,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, indicators1_fields, ENC_NA);
indicators1 = tvb_get_guint8(parameter_tvb, 0);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
if ((indicators2 & GFE_8BIT_MASK) == 0x50) {
proto_tree_add_uint_format_value(parameter_tree, hf_isup_number_different_meaning, parameter_tvb, 1, 1, indicators2 & GFE_8BIT_MASK,
"Numbering plan indicator = private numbering plan");
}
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 1, 1, indicators2_fields, ENC_NA);
if (tvb_reported_length_remaining(parameter_tvb, offset) < 3) {
proto_item_set_text(parameter_item, "Location number: address not available");
return;
}
offset = 2;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Location number", hf_isup_location_number, hf_isup_calling_party_odd_address_signal_digit,
hf_isup_calling_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
NONE, 0);
}
static void
dissect_isup_redirection_number_restriction_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_item(parameter_tree, hf_isup_presentation_indicator, parameter_tvb, 0, REDIRECTION_NUMBER_RESTRICTION_LENGTH, ENC_NA);
proto_item_set_text(parameter_item, "Redirection number restriction: 0x%x ", indicator);
}
static void
dissect_isup_call_transfer_reference_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 id;
id = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_item(parameter_tree, hf_isup_call_transfer_identity, parameter_tvb, 0, CALL_TRANSFER_REF_LENGTH, ENC_NA);
proto_item_set_text(parameter_item, "Call transfer reference: %u", id);
}
static void
dissect_isup_loop_prevention_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_item(parameter_tree, hf_isup_loop_prevention_indicator_type, parameter_tvb, 0, LOOP_PREVENTION_IND_LENGTH, ENC_NA);
if ((indicator & A_8BIT_MASK) == 0) {
proto_item_set_text(parameter_item, "Loop prevention indicators: Request (%u)", indicator);
}
else {
proto_tree_add_uint(parameter_tree, hf_isup_loop_prevention_response_ind,
parameter_tvb, 0, LOOP_PREVENTION_IND_LENGTH, indicator);
proto_item_set_text(parameter_item, "Loop prevention indicators: Response (%u)", indicator);
}
}
static void
dissect_isup_call_transfer_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1, indicators2;
gint offset = 0;
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_calling_party_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, indicators2);
if ((indicators2 & GFE_8BIT_MASK) == 0x50)
proto_tree_add_uint_format_value(parameter_tree, hf_isup_number_different_meaning, parameter_tvb, 1, 1, indicators2 & GFE_8BIT_MASK,
"Numbering plan indicator = private numbering plan");
proto_tree_add_uint(parameter_tree, hf_isup_address_presentation_restricted_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_screening_indicator_enhanced, parameter_tvb, 1, 1, indicators2);
offset = 2;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Call Transfer Number", hf_isup_call_transfer_number, hf_isup_calling_party_odd_address_signal_digit,
hf_isup_calling_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
NONE, 0);
}
static void
dissect_isup_ccss_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_item(parameter_tree, hf_isup_ccss_call_indicator, parameter_tvb, 0, LOOP_PREVENTION_IND_LENGTH, ENC_NA);
if ((indicator & A_8BIT_MASK) == 0) {
proto_item_set_text(parameter_item, "CCSS call indicator: no indication (%u)", indicator);
}
else {
proto_item_set_text(parameter_item, "CCSS call indicator: CCSS call (%u)", indicator);
}
}
static void
dissect_isup_forward_gvns_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_forward_gvns, parameter_tvb, 0, length, ENC_NA);
proto_item_set_text(parameter_item, "Forward GVNS (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_redirect_capability_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item, guint8 itu_isup_variant)
{
guint length = tvb_reported_length(parameter_tvb);
switch (itu_isup_variant) {
case ISUP_JAPAN_VARIANT:
case ISUP_JAPAN_TTC_VARIANT:
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_redirect_capability, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_uint_format_value(parameter_tree, hf_isup_redirect_capability, parameter_tvb, 0, length, itu_isup_variant, "(format is a national matter)");
break;
}
proto_item_set_text(parameter_item, "Redirect Capability (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_backward_gvns_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint_format_value(parameter_tree, hf_isup_backward_gvns, parameter_tvb, 0, BACKWARD_GVNS_LENGTH, indicator,
"0x%x (refer to 3.62/Q.763 for detailed decoding)", indicator);
proto_item_set_text(parameter_item, "Backward GVNS: 0x%x", indicator);
}
static void
dissect_isup_network_management_controls_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_temporary_alternative_routing_ind,
parameter_tvb, 0, NETWORK_MANAGEMENT_CONTROLS_LENGTH, indicator);
proto_tree_add_boolean(parameter_tree, hf_isup_extension_ind, parameter_tvb, 0, NETWORK_MANAGEMENT_CONTROLS_LENGTH, indicator);
proto_item_set_text(parameter_item, "Network management controls: 0x%x", indicator);
}
static void
dissect_isup_correlation_id_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_correlation_id, parameter_tvb, 0, length, ENC_NA);
proto_item_set_text(parameter_item, "Correlation ID, see Q.1281 (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_scf_id_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_scf_id, parameter_tvb, 0, length, ENC_NA);
proto_item_set_text(parameter_item, "SCF ID, see Q.1281 (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_call_diversion_treatment_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_call_to_be_diverted_ind, parameter_tvb, 0, CALL_DIV_TREATMENT_IND_LENGTH, indicator);
proto_tree_add_boolean(parameter_tree, hf_isup_extension_ind, parameter_tvb, 0, CALL_DIV_TREATMENT_IND_LENGTH, indicator);
proto_item_set_text(parameter_item, "Call diversion treatment indicators: 0x%x", indicator);
}
static void
dissect_isup_called_in_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1;
gint offset = 0;
static const int * indicators1_fields[] = {
&hf_isup_odd_even_indicator,
&hf_isup_calling_party_nature_of_address_indicator,
NULL
};
static const int * indicators2_fields[] = {
&hf_isup_numbering_plan_indicator,
&hf_isup_address_presentation_restricted_indicator,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, indicators1_fields, ENC_NA);
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 1, 1, indicators2_fields, ENC_NA);
offset = 2;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Called IN Number", hf_isup_called_in_number, hf_isup_calling_party_odd_address_signal_digit,
hf_isup_calling_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
NONE, 0);
}
static void
dissect_isup_call_offering_treatment_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_call_to_be_offered_ind, parameter_tvb, 0, CALL_OFFERING_TREATMENT_IND_LENGTH, indicator);
proto_tree_add_boolean(parameter_tree, hf_isup_extension_ind, parameter_tvb, 0, CALL_OFFERING_TREATMENT_IND_LENGTH, indicator);
proto_item_set_text(parameter_item, "Call offering treatment indicators: 0x%x", indicator);
}
static void
dissect_isup_charged_party_identification_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_charged_party_identification, parameter_tvb, 0, length, ENC_NA);
proto_item_set_text(parameter_item, "Charged party identification (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_conference_treatment_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_conference_acceptance_ind, parameter_tvb, 0, CONFERENCE_TREATMENT_IND_LENGTH, indicator);
proto_tree_add_boolean(parameter_tree, hf_isup_extension_ind, parameter_tvb, 0, CONFERENCE_TREATMENT_IND_LENGTH, indicator);
proto_item_set_text(parameter_item, "Conference treatment indicators: 0x%x", indicator);
}
static void
dissect_isup_display_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_display_information, parameter_tvb, 0, length, ENC_NA);
proto_item_set_text(parameter_item, "Display information (%u Byte%s)",
length , plurality(length, "", "s"));
}
static void
dissect_isup_uid_action_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint_format_value(parameter_tree, hf_isup_uid_action_indicators, parameter_tvb, 0, UID_ACTION_IND_LENGTH, indicator,
"0x%x (refer to 3.78/Q.763 for detailed decoding)", indicator);
proto_item_set_text(parameter_item, "UID action indicators: 0x%x", indicator);
}
static void
dissect_isup_uid_capability_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint_format_value(parameter_tree, hf_isup_uid_capability_indicators, parameter_tvb, 0, UID_CAPABILITY_IND_LENGTH,
indicator, "0x%x (refer to 3.79/Q.763 for detailed decoding)", indicator);
proto_item_set_text(parameter_item, "UID capability indicators: 0x%x", indicator);
}
static void
dissect_isup_redirect_counter_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item, guint8 itu_isup_variant)
{
guint length = tvb_reported_length(parameter_tvb);
switch (itu_isup_variant) {
case ISUP_JAPAN_VARIANT:
case ISUP_JAPAN_TTC_VARIANT:
proto_tree_add_item(parameter_tree, hf_japan_isup_redirect_counter, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_uint_format_value(parameter_tree, hf_isup_redirect_counter, parameter_tvb, 0, length, itu_isup_variant, "(format is a national matter)");
break;
}
proto_item_set_text(parameter_item, "Redirect counter (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_collect_call_request_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_item(parameter_tree, hf_isup_collect_call_request_indicator, parameter_tvb, 0, COLLECT_CALL_REQUEST_LENGTH, ENC_NA);
if ((indicator & A_8BIT_MASK) == 0) {
proto_item_set_text(parameter_item, "Collect call request: no indication (0x%x)", indicator);
}
else {
proto_item_set_text(parameter_item, "Collect call request: collect call requested (0x%x)", indicator);
}
}
static void
dissect_isup_calling_geodetic_location_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint length = tvb_reported_length(parameter_tvb);
guint8 oct, lpri;
oct = tvb_get_guint8(parameter_tvb, 0);
lpri = (oct & 0xc0) >> 2;
proto_tree_add_uint(parameter_tree, hf_isup_geo_loc_presentation_restricted_ind, parameter_tvb, 0, 1, oct);
proto_tree_add_uint(parameter_tree, hf_isup_geo_loc_screening_ind, parameter_tvb, 0, 1, oct);
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, 1, 1, ENC_NA);
proto_tree_add_item(parameter_tree, hf_isup_geo_loc_shape, parameter_tvb, 1, 1, ENC_NA);
if (length > 2)
{
if (lpri < 0x2)
{
proto_tree_add_item(parameter_tree, hf_isup_geo_loc_shape_description, parameter_tvb, 2, length - 2, ENC_NA);
}
else
{
proto_tree_add_expert_format(parameter_tree, pinfo, &ei_isup_not_dissected_yet, parameter_tvb, 2, length - 2,
"Unknown (?), should not have data if LPRI is 'location not available'");
}
}
proto_item_set_text(parameter_item, "Calling geodetic location");
}
void
dissect_isup_generic_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1, indicators2;
gint offset = 0;
static const int * indicators1_fields[] = {
&hf_isup_odd_even_indicator,
&hf_isup_calling_party_nature_of_address_indicator,
NULL
};
static const int * indicators2_fields[] = {
&hf_isup_ni_indicator,
&hf_isup_numbering_plan_indicator,
&hf_isup_address_presentation_restricted_indicator,
&hf_isup_screening_indicator_enhanced,
NULL
};
static const int * indicators2_fields_gfe[] = {
&hf_isup_ni_indicator,
&hf_isup_numbering_plan_indicator,
&hf_isup_number_different_meaning,
&hf_isup_address_presentation_restricted_indicator,
&hf_isup_screening_indicator,
NULL
};
proto_tree_add_item(parameter_tree, hf_isup_number_qualifier_indicator, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb,1 , 1, indicators1_fields, ENC_NA);
indicators1 = tvb_get_guint8(parameter_tvb, 1);
indicators2 = tvb_get_guint8(parameter_tvb, 2);
if ((indicators2 & GFE_8BIT_MASK) == 0x50) {
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 2, 1, indicators2_fields_gfe, ENC_NA);
} else {
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 2, 1, indicators2_fields, ENC_NA);
}
offset = 3;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Generic Number", hf_isup_generic_number, hf_isup_calling_party_odd_address_signal_digit,
hf_isup_calling_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
NONE, 0);
indicators1 = indicators1 & 0x7f;
indicators2 = (indicators2 & 0x70)>>4;
if ((indicators1 == ISUP_CALLED_PARTY_NATURE_INTERNATNL_NR) && (indicators2 == ISDN_NUMBERING_PLAN))
dissect_e164_cc(parameter_tvb, parameter_tree, 3, E164_ENC_BCD);
}
static void
dissect_isup_jurisdiction_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
gint offset = 0;
offset = 0;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Jurisdiction", hf_isup_jurisdiction, hf_isup_called_party_odd_address_signal_digit,
hf_isup_called_party_even_address_signal_digit, (tvb_reported_length(parameter_tvb) > 0),
NONE, 0);
}
static void
dissect_isup_generic_name_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
gint gen_name_length;
char *gen_name = NULL;
static const int * indicators[] = {
&hf_isup_generic_name_presentation,
&hf_isup_generic_name_availability,
&hf_isup_generic_name_type,
NULL
};
gen_name = (char *)wmem_alloc(wmem_packet_scope(), MAXGNAME + 1);
gen_name[0] = '\0';
gen_name_length = tvb_reported_length(parameter_tvb) - 1;
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, indicators, ENC_NA);
gen_name = tvb_get_string_enc(wmem_packet_scope(), parameter_tvb, 1, gen_name_length, ENC_ASCII);
gen_name[gen_name_length] = '\0';
proto_tree_add_string(parameter_tree, hf_isup_generic_name_ia5, parameter_tvb, 2, gen_name_length, gen_name);
proto_item_set_text(parameter_item, "Generic name: %s", gen_name);
}
static void
dissect_isup_generic_digits_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_item(parameter_tree, hf_isup_generic_digits, parameter_tvb, 0, length, ENC_NA);
proto_item_set_text(parameter_item, "Generic digits (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_charge_number_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators1;
gint offset = 0;
static const int * indicators1_fields[] = {
&hf_isup_odd_even_indicator,
&hf_isup_charge_number_nature_of_address_indicator,
NULL
};
proto_tree_add_bitmask_list(parameter_tree, parameter_tvb, 0, 1, indicators1_fields, ENC_NA);
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_item(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, ENC_NA);
offset = 2;
dissect_isup_digits_common(parameter_tvb, offset, pinfo, parameter_tree, parameter_item,
"Charge Number", hf_isup_charge_number, hf_isup_calling_party_odd_address_signal_digit,
hf_isup_calling_party_even_address_signal_digit, ((indicators1 & 0x80) == 0),
NONE, 0);
}
static void
dissect_isup_unknown_parameter(tvbuff_t *parameter_tvb, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_item_set_text(parameter_item, "Parameter Type unknown/reserved (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_japan_isup_called_dir_num(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
int offset = 0;
int parameter_length;
parameter_length = tvb_reported_length_remaining(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_called_party_nature_of_address_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(parameter_tree, hf_isup_inn_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_expert_format(parameter_tree, pinfo, &ei_isup_not_dissected_yet, parameter_tvb, offset, parameter_length-offset, "Number not dissected yet");
proto_item_set_text(parameter_item, "Called Directory Number");
}
static void
dissect_japan_isup_redirect_fwd_inf(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
int offset = 0;
guint8 tag, tag_len, ext_ind;
int parameter_length;
parameter_length = tvb_reported_length_remaining(parameter_tvb, offset);
while (offset < parameter_length) {
tag = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_japan_isup_rfi_info_type, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
tag_len = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_japan_isup_rfi_info_len, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (tag) {
case 3:
ext_ind = 0;
while (ext_ind == 0) {
ext_ind = tvb_get_guint8(parameter_tvb, offset) >> 7;
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_perf_redir_reason, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(parameter_tree, hf_japan_isup_redir_pos_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case 4:
ext_ind = 0;
while (ext_ind == 0) {
ext_ind = tvb_get_guint8(parameter_tvb, offset)>>7;
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_inv_redir_reason, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
default:
proto_tree_add_expert_format(parameter_tree, pinfo, &ei_isup_not_dissected_yet, parameter_tvb, offset, tag_len, "Unknown(not dissected) tag");
offset = offset + tag_len;
break;
}
}
proto_item_set_text(parameter_item, "Redirect forward information");
}
static void
dissect_japan_isup_redirect_backw_inf(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
int offset = 0;
guint8 tag, tag_len, ext_ind;
int parameter_length;
parameter_length = tvb_reported_length_remaining(parameter_tvb, offset);
while (offset < parameter_length) {
tag = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_japan_isup_bwd_info_type, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
tag_len = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_japan_isup_tag_len, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (tag) {
case 3:
ext_ind = 0;
while (ext_ind == 0) {
ext_ind = tvb_get_guint8(parameter_tvb, offset)>>7;
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_inv_redir_reason, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
default:
proto_tree_add_expert_format(parameter_tree, pinfo, &ei_isup_not_dissected_yet, parameter_tvb, offset, tag_len, "Unknown(not dissected) tag");
offset = offset + tag_len;
break;
}
}
proto_item_set_text(parameter_item, "Redirect backward information");
}
static void
dissect_japan_isup_emergency_call_ind(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
int offset = 0;
proto_tree_add_item(parameter_tree, hf_japan_isup_emerg_call_type, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Emergency Call Indicator");
}
static void
dissect_japan_isup_emergency_call_inf_ind(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
int offset = 0;
proto_tree_add_item(parameter_tree, hf_japan_isup_hold_at_emerg_call_disc_ind, parameter_tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Emergency Call Information Indicator");
}
static void
dissect_japan_isup_network_poi_cad(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *digits_item;
proto_tree *digits_tree;
int offset = 0;
guint8 octet;
guint8 odd_even;
guint8 carrier_info_length;
gint num_octets_with_digits = 0;
gint digit_index = 0;
wmem_strbuf_t *ca_number = wmem_strbuf_sized_new(wmem_packet_scope(), MAXDIGITS+1, 0);
proto_tree_add_item(parameter_tree, hf_isup_carrier_info_poi_entry_HEI, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_carrier_info_poi_exit_HEI, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
carrier_info_length = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_japan_isup_carrier_info_length, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
digits_tree = proto_tree_add_subtree(parameter_tree, parameter_tvb, offset, -1,
ett_isup_address_digits, &digits_item, "Charge Area Number");
odd_even = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_boolean(digits_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, odd_even);
num_octets_with_digits = carrier_info_length - 1;
digit_index = 0;
while (num_octets_with_digits > 0) {
offset += 1;
octet = tvb_get_guint8(parameter_tvb, offset);
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_ca_odd_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(ca_number, number_to_char(octet & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK));
if (num_octets_with_digits == 1) {
if (odd_even == 0) {
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_ca_even_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(ca_number, number_to_char((octet & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10));
}
}
else {
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_ca_even_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(ca_number, number_to_char((octet & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10));
}
num_octets_with_digits--;
}
proto_item_append_text(digits_item, ": %s", wmem_strbuf_get_str(ca_number));
proto_item_set_text(parameter_item, "Network POI-CA");
}
void
dissect_japan_isup_additonal_user_cat(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
int offset = 0;
guint8 type;
int parameter_length;
parameter_length = tvb_reported_length_remaining(parameter_tvb, offset);
while (offset < parameter_length) {
type = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_japan_isup_add_user_cat_type, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (type) {
case 0xfe:
proto_tree_add_item(parameter_tree, hf_japan_isup_type_1_add_fixed_serv_inf, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0xfd:
proto_tree_add_item(parameter_tree, hf_japan_isup_type_1_add_mobile_serv_inf, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0xfc:
proto_tree_add_item(parameter_tree, hf_japan_isup_type_2_add_mobile_serv_inf, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0xfb:
proto_tree_add_item(parameter_tree, hf_japan_isup_type_3_add_mobile_serv_inf, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_expert_format(parameter_tree, pinfo, &ei_isup_not_dissected_yet, parameter_tvb, offset, 1,
"Unknown(not dissected) Additional User/Service Information");
break;
}
offset += 1;
}
proto_item_set_text(parameter_item, "Additional User Category");
}
static void
dissect_japan_isup_reason_for_clip_fail(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
int offset = 0;
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_reason_for_clip_fail, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Reason for CLIP failure");
}
static void
dissect_japan_isup_contractor_number(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
int offset = 0;
int parameter_length;
const char *digit_str;
parameter_length = tvb_reported_length_remaining(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_called_party_nature_of_address_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
digit_str = tvb_bcd_dig_to_wmem_packet_str( parameter_tvb, offset, parameter_length-2, NULL, FALSE);
proto_tree_add_string(parameter_tree, hf_japan_isup_contractor_number, parameter_tvb, offset, parameter_length-offset, digit_str);
proto_item_set_text(parameter_item, "Contractor Number %s", digit_str);
}
static void
dissect_japan_isup_carrier_information(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *catagory_of_carrier;
proto_tree *carrier_info_tree;
proto_item *digits_item;
proto_tree *digits_tree;
proto_item *type_of_carrier;
proto_tree *type_of_carrier_tree;
guint8 octet;
guint8 odd_even;
guint8 type_of_carrier_info;
guint8 carrier_info_length;
guint8 carrierX_end_index;
gint offset = 0;
gint length = 0;
gint num_octets_with_digits = 0;
gint digit_index;
wmem_strbuf_t *cid_number;
wmem_strbuf_t *ca_number;
octet = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_carrier_info_iec, parameter_tvb, 0, 1, octet);
length = tvb_reported_length_remaining(parameter_tvb, 2);
if (length == 0) {
expert_add_info(pinfo, parameter_item, &ei_isup_empty_number);
proto_item_set_text(parameter_item, "Carrier Information (empty)");
return;
}
offset = 1;
while (length > 0) {
carrier_info_tree = proto_tree_add_subtree(parameter_tree, parameter_tvb, offset, -1,
ett_isup_carrier_info, &catagory_of_carrier, "Category of Carrier:");
octet = tvb_get_guint8(parameter_tvb, offset);
proto_item_set_text(catagory_of_carrier, "%s (%u)", val_to_str_ext_const(octet, &isup_carrier_info_category_vals_ext, "spare"), octet );
offset += 1;
carrierX_end_index = tvb_get_guint8(parameter_tvb, offset)+offset;
while (offset < carrierX_end_index) {
type_of_carrier_tree = proto_tree_add_subtree(carrier_info_tree, parameter_tvb, offset, -1,
ett_isup_carrier_info, &type_of_carrier, "Type of Carrier:");
offset += 1;
type_of_carrier_info = tvb_get_guint8(parameter_tvb, offset);
proto_item_set_text(type_of_carrier, "%s (%u)", val_to_str_ext_const(type_of_carrier_info, &isup_carrier_info_type_of_carrier_vals_ext, "spare"), type_of_carrier_info );
offset += 1;
carrier_info_length = tvb_get_guint8(parameter_tvb, offset);
if (type_of_carrier_info == CARRIER_INFO_TYPE_OF_CARRIER_POIHIE) {
offset += 1;
octet = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(type_of_carrier_tree, hf_isup_carrier_info_poi_entry_HEI, parameter_tvb, 0, 1, octet);
proto_tree_add_uint(type_of_carrier_tree, hf_isup_carrier_info_poi_exit_HEI, parameter_tvb, 0, 1, octet);
}
if (type_of_carrier_info == CARRIER_INFO_TYPE_OF_CARRIER_POICA) {
digits_tree = proto_tree_add_subtree(type_of_carrier_tree, parameter_tvb, offset, -1,
ett_isup_address_digits, &digits_item, "Charge Area");
offset += 1;
odd_even = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_boolean(digits_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, odd_even);
num_octets_with_digits = carrier_info_length - 1;
ca_number = wmem_strbuf_sized_new(wmem_packet_scope(), MAXDIGITS+1, 0);
digit_index = 0;
while (num_octets_with_digits > 0) {
offset += 1;
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
octet = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_ca_odd_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(ca_number, number_to_char(octet & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK));
if (num_octets_with_digits == 1) {
if (odd_even == 0) {
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_ca_even_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(ca_number, number_to_char((octet & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10));
}
}
else {
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_ca_even_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(ca_number, number_to_char((octet & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10));
}
num_octets_with_digits--;
}
proto_item_append_text(digits_item, ": %s", wmem_strbuf_get_str(ca_number));
}
if (type_of_carrier_info == CARRIER_INFO_TYPE_OF_CARRIER_CARID) {
digits_tree = proto_tree_add_subtree(type_of_carrier_tree, parameter_tvb, offset, -1,
ett_isup_address_digits, &digits_item, "Carrier ID Code");
offset += 1;
odd_even = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_boolean(digits_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, odd_even);
num_octets_with_digits = carrier_info_length - 1;
cid_number = wmem_strbuf_sized_new(wmem_packet_scope(), MAXDIGITS+1, 0);
digit_index = 0;
while (num_octets_with_digits > 0) {
offset += 1;
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
octet = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_odd_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(cid_number, number_to_char(octet & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK));
if (num_octets_with_digits == 1) {
if (odd_even == 0) {
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_even_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(cid_number, number_to_char((octet & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10));
}
}
else {
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_even_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(cid_number, number_to_char((octet & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10));
}
num_octets_with_digits--;
}
proto_item_append_text(digits_item, ": %s", wmem_strbuf_get_str(cid_number));
}
}
offset += 1;
length = tvb_reported_length_remaining(parameter_tvb, offset);
}
proto_item_set_text(parameter_item, "Carrier Information");
}
static void
dissect_japan_isup_charge_inf_delay(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
int offset = 0;
int parameter_length;
parameter_length = tvb_reported_length_remaining(parameter_tvb, offset);
while (offset < parameter_length) {
proto_tree_add_item(parameter_tree, hf_japan_isup_charge_delay_type, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
proto_item_set_text(parameter_item, "Carrier Information");
}
static void
dissect_japan_isup_charge_area_info(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *digits_item;
proto_tree *digits_tree;
guint8 octet;
gint nat_of_info_indic;
gint length;
gint offset;
gint odd_even;
gint digit_index = 0;
wmem_strbuf_t *ca_number = wmem_strbuf_sized_new(wmem_packet_scope(), MAXDIGITS+1, 0);
octet = tvb_get_guint8(parameter_tvb, 0);
nat_of_info_indic = octet & 0x7F;
odd_even = octet & 0x80;
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, octet);
proto_tree_add_uint(parameter_tree, hf_japan_isup_charge_area_nat_of_info_value, parameter_tvb, 0, 1, octet);
offset = 1;
length = tvb_reported_length_remaining(parameter_tvb, offset);
if (nat_of_info_indic == CHARGE_AREA_NAT_INFO_CA) {
digits_tree = proto_tree_add_subtree(parameter_tree, parameter_tvb, offset, -1,
ett_isup_address_digits, &digits_item, "Charge Area");
while (length > 0) {
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
octet = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_ca_odd_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(ca_number, number_to_char(octet & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK));
if (length == 1) {
if (odd_even == 0) {
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_ca_even_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(ca_number, number_to_char((octet & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10));
}
}
else {
if (++digit_index > MAXDIGITS) {
expert_add_info(pinfo, digits_item, &ei_isup_too_many_digits);
break;
}
proto_tree_add_uint(digits_tree, hf_isup_carrier_info_ca_even_no_digits, parameter_tvb, 0, 1, octet);
wmem_strbuf_append_c(ca_number, number_to_char((octet & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10));
}
offset += 1;
length -= 1;
}
proto_item_append_text(digits_item, ": %s", wmem_strbuf_get_str(ca_number));
}
if (nat_of_info_indic == CHARGE_AREA_NAT_INFO_MA) {
digits_tree = proto_tree_add_subtree(parameter_tree, parameter_tvb, offset, -1,
ett_isup_address_digits, &digits_item, "Message Area:");
octet = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(digits_tree, hf_japan_isup_charging_info_nc_odd_digits, parameter_tvb, 0, 1, octet);
proto_tree_add_uint(digits_tree, hf_japan_isup_charging_info_nc_even_digits, parameter_tvb, 0, 1, octet);
octet++;
octet = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(digits_tree, hf_japan_isup_charging_info_nc_odd_digits, parameter_tvb, 0, 1, octet);
proto_tree_add_uint(digits_tree, hf_japan_isup_charging_info_nc_even_digits, parameter_tvb, 0, 1, octet);
octet++;
length = tvb_reported_length_remaining(parameter_tvb, offset);
while (length > 0) {
octet = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(digits_tree, hf_isup_charging_info_maca_odd_digits, parameter_tvb, 0, 1, octet);
if (length == 1) {
if (odd_even == 0) {
proto_tree_add_uint(digits_tree, hf_isup_charging_info_maca_even_digits, parameter_tvb, 0, 1, octet);
}
}
else {
proto_tree_add_uint(digits_tree, hf_isup_charging_info_maca_even_digits, parameter_tvb, 0, 1, octet);
}
offset += 1;
length -= 1;
}
}
proto_item_set_text(parameter_item, "Charge Area Information");
}
static guint16
dissect_japan_chg_inf_type(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 chg_inf_type;
chg_inf_type = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_item(parameter_tree, hf_japan_isup_charge_info_type, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_item_set_text(parameter_item, "Charge information type");
return chg_inf_type;
}
static void
dissect_japan_chg_inf_type_acr(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item _U_)
{
int offset = 0;
guint8 ext_ind;
ext_ind = tvb_get_guint8(parameter_tvb, offset)>>7;
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_sig_elem_type, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (!ext_ind) {
ext_ind = tvb_get_guint8(parameter_tvb, offset)>>7;
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_activation_id, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (!ext_ind) {
ext_ind = tvb_get_guint8(parameter_tvb, offset)>>7;
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_op_cls, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_op_type, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (!ext_ind) {
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_charging_party_type, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_collecting_metod, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
}
}
proto_tree_add_item(parameter_tree, hf_japan_isup_tariff_rate_pres, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_japan_chg_inf_type_crt(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item _U_)
{
int offset = 0;
guint8 ext_ind;
guint8 len;
int parameter_length;
parameter_length = tvb_reported_length_remaining(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_japan_isup_utp, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ext_ind = tvb_get_guint8(parameter_tvb, offset)>>7;
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_crci1, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (!ext_ind) {
len = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_japan_isup_crci1_len, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(parameter_tree, hf_japan_isup_iu, parameter_tvb, offset, 2, ENC_NA|ENC_ASCII);
offset += 2;
proto_tree_add_item(parameter_tree, hf_japan_isup_dcr, parameter_tvb, offset, 3, ENC_NA|ENC_ASCII);
offset+=3;
if (len > 5) {
proto_tree_add_item(parameter_tree, hf_japan_isup_ecr, parameter_tvb, offset, 3, ENC_NA|ENC_ASCII);
offset += 3;
}
if (len > 8) {
proto_tree_add_item(parameter_tree, hf_japan_isup_ncr, parameter_tvb, offset, 3, ENC_NA|ENC_ASCII);
offset += 3;
}
if (len > 11) {
proto_tree_add_item(parameter_tree, hf_japan_isup_scr, parameter_tvb, offset, 3, ENC_NA|ENC_ASCII);
offset += 3;
}
}
if (parameter_length > offset) {
ext_ind = tvb_get_guint8(parameter_tvb, offset)>>7;
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_japan_isup_crci2, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (!ext_ind) {
len = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_japan_isup_crci1_len, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(parameter_tree, hf_japan_isup_iu, parameter_tvb, offset, 2, ENC_NA|ENC_ASCII);
offset += 2;
proto_tree_add_item(parameter_tree, hf_japan_isup_dcr, parameter_tvb, offset, 3, ENC_NA|ENC_ASCII);
offset += 3;
if (len > 5) {
proto_tree_add_item(parameter_tree, hf_japan_isup_ecr, parameter_tvb, offset, 3, ENC_NA|ENC_ASCII);
offset += 3;
}
if (len > 8) {
proto_tree_add_item(parameter_tree, hf_japan_isup_ncr, parameter_tvb, offset, 3, ENC_NA|ENC_ASCII);
offset += 3;
}
if (len > 11) {
proto_tree_add_item(parameter_tree, hf_japan_isup_scr, parameter_tvb, offset, 3, ENC_NA|ENC_ASCII);
}
}
}
}
static void
dissect_japan_chg_inf_param(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item, guint16 chg_inf_type)
{
switch (chg_inf_type) {
case 3:
dissect_japan_chg_inf_type_acr(parameter_tvb, parameter_tree, parameter_item);
break;
case 254:
dissect_japan_chg_inf_type_crt(parameter_tvb, parameter_tree, parameter_item);
break;
default:
proto_tree_add_expert_format(parameter_tree, pinfo, &ei_isup_not_dissected_yet, parameter_tvb, 0, -1, "Charge information data, not dissected yet");
break;
}
proto_item_set_text(parameter_item, "Charge information");
}
static void
dissect_isup_optional_parameter(tvbuff_t *optional_parameters_tvb, packet_info *pinfo, proto_tree *isup_tree, guint8 itu_isup_variant)
{
proto_item *parameter_item;
proto_tree *parameter_tree;
gint offset = 0;
guint parameter_type, parameter_length, actual_length;
tvbuff_t *parameter_tvb;
guint8 octet;
guint16 chg_inf_type = 0xffff;
parameter_type = 0xFF;
while ((tvb_reported_length_remaining(optional_parameters_tvb, offset) >= 1) && (parameter_type != PARAM_TYPE_END_OF_OPT_PARAMS)) {
parameter_type = tvb_get_guint8(optional_parameters_tvb, offset);
if (parameter_type != PARAM_TYPE_END_OF_OPT_PARAMS) {
parameter_length = tvb_get_guint8(optional_parameters_tvb, offset + PARAMETER_TYPE_LENGTH);
parameter_tree = proto_tree_add_subtree_format(isup_tree, optional_parameters_tvb,
offset,
parameter_length + PARAMETER_TYPE_LENGTH + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Parameter: type %u",
parameter_type);
switch (itu_isup_variant) {
case ISUP_JAPAN_VARIANT:
case ISUP_JAPAN_TTC_VARIANT:
proto_tree_add_uint_format_value(parameter_tree, hf_isup_opt_parameter_type, optional_parameters_tvb, offset, PARAMETER_TYPE_LENGTH,
parameter_type,
"%u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &japan_isup_parameter_type_value_ext, "unknown"));
break;
default:
proto_tree_add_uint(parameter_tree, hf_isup_opt_parameter_type, optional_parameters_tvb, offset, PARAMETER_TYPE_LENGTH, parameter_type);
break;
}
offset += PARAMETER_TYPE_LENGTH;
octet = tvb_get_guint8(optional_parameters_tvb, offset);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, optional_parameters_tvb, offset,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
offset += PARAMETER_LENGTH_IND_LENGTH;
if (octet == 0)
continue;
actual_length = tvb_reported_length_remaining(optional_parameters_tvb, offset);
if (actual_length > 0) {
parameter_tvb = tvb_new_subset(optional_parameters_tvb, offset, MIN(parameter_length, actual_length), parameter_length);
switch (parameter_type) {
case PARAM_TYPE_CALL_REF:
dissect_isup_call_reference_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_TRANSM_MEDIUM_REQU:
dissect_isup_transmission_medium_requirement_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_ACC_TRANSP:
dissect_isup_access_transport_parameter(parameter_tvb, parameter_tree, parameter_item, pinfo);
break;
case PARAM_TYPE_CALLED_PARTY_NR:
dissect_isup_called_party_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SUBSQT_NR:
dissect_isup_subsequent_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_NATURE_OF_CONN_IND:
dissect_isup_nature_of_connection_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_FORW_CALL_IND:
dissect_isup_forward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_OPT_FORW_CALL_IND:
dissect_isup_optional_forward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALLING_PRTY_CATEG:
dissect_isup_calling_partys_category_parameter(parameter_tvb, parameter_tree, parameter_item, itu_isup_variant);
break;
case PARAM_TYPE_CALLING_PARTY_NR:
dissect_isup_calling_party_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECTING_NR:
dissect_isup_redirecting_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECTION_NR:
dissect_isup_redirection_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CONNECTION_REQ:
dissect_isup_connection_request_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_INFO_REQ_IND:
dissect_isup_information_request_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_INFO_IND:
dissect_isup_information_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CONTINUITY_IND:
dissect_isup_continuity_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_BACKW_CALL_IND:
dissect_isup_backward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CAUSE_INDICATORS:
dissect_isup_cause_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECTION_INFO:
dissect_isup_redirection_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CIRC_GRP_SV_MSG_TYPE:
dissect_isup_circuit_group_supervision_message_type_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_RANGE_AND_STATUS:
dissect_isup_range_and_status_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_FACILITY_IND:
dissect_isup_facility_ind_parameter(parameter_tvb, parameter_item);
break;
case PARAM_TYPE_CLSD_USR_GRP_ILOCK_CD:
dissect_isup_closed_user_group_interlock_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_USER_SERVICE_INFO:
dissect_isup_user_service_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SIGNALLING_POINT_CODE:
dissect_isup_signalling_point_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_USER_TO_USER_INFO:
dissect_isup_user_to_user_information_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CONNECTED_NR:
dissect_isup_connected_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SUSP_RESUME_IND:
dissect_isup_suspend_resume_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_TRANSIT_NETW_SELECT:
dissect_isup_transit_network_selection_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_EVENT_INFO:
dissect_isup_event_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CIRC_ASSIGN_MAP:
dissect_isup_circuit_assignment_map_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CIRC_STATE_IND:
dissect_isup_circuit_state_ind_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_AUTO_CONG_LEVEL:
dissect_isup_automatic_congestion_level_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_ORIG_CALLED_NR:
dissect_isup_original_called_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_OPT_BACKW_CALL_IND:
dissect_isup_optional_backward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_USER_TO_USER_IND:
dissect_isup_user_to_user_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_ORIG_ISC_POINT_CODE:
dissect_isup_original_isc_point_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_NOTIF_IND:
dissect_isup_generic_notification_indicator_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_HIST_INFO :
dissect_isup_call_history_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_ACC_DELIV_INFO:
dissect_isup_access_delivery_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_NETW_SPECIFIC_FACLTY:
dissect_isup_network_specific_facility_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_USER_SERVICE_INFO_PR:
dissect_isup_user_service_information_prime_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_PROPAG_DELAY_COUNTER:
dissect_isup_propagation_delay_counter_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REMOTE_OPERATIONS:
dissect_isup_remote_operations_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SERVICE_ACTIVATION:
dissect_isup_service_activation_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_USER_TELESERV_INFO:
dissect_isup_user_teleservice_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_TRANSM_MEDIUM_USED:
dissect_isup_transmission_medium_used_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_DIV_INFO:
dissect_isup_call_diversion_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_ECHO_CTRL_INFO:
dissect_isup_echo_control_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_MSG_COMPAT_INFO:
dissect_isup_message_compatibility_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_PARAM_COMPAT_INFO:
dissect_isup_parameter_compatibility_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_MLPP_PRECEDENCE:
dissect_isup_mlpp_precedence_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_MCID_REQ_IND:
dissect_isup_mcid_request_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_MCID_RSP_IND:
dissect_isup_mcid_response_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_HOP_COUNTER:
dissect_isup_hop_counter_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_TRANSM_MEDIUM_RQUR_PR:
dissect_isup_transmission_medium_requirement_prime_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_LOCATION_NR:
dissect_isup_location_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIR_NR_RSTRCT:
dissect_isup_redirection_number_restriction_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_TRANS_REF:
dissect_isup_call_transfer_reference_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_LOOP_PREV_IND:
dissect_isup_loop_prevention_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_TRANS_NR:
dissect_isup_call_transfer_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CCSS:
dissect_isup_ccss_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_FORW_GVNS:
dissect_isup_forward_gvns_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_BACKW_GVNS:
dissect_isup_backward_gvns_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECT_CAPAB:
dissect_isup_redirect_capability_parameter(parameter_tvb, parameter_tree, parameter_item, itu_isup_variant);
break;
case PARAM_TYPE_NETW_MGMT_CTRL:
dissect_isup_network_management_controls_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CORRELATION_ID:
dissect_isup_correlation_id_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SCF_ID:
dissect_isup_scf_id_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_DIV_TREAT_IND:
dissect_isup_call_diversion_treatment_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALLED_IN_NR:
dissect_isup_called_in_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_OFF_TREAT_IND:
dissect_isup_call_offering_treatment_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CHARGED_PARTY_IDENT:
dissect_isup_charged_party_identification_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CONF_TREAT_IND:
dissect_isup_conference_treatment_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_DISPLAY_INFO:
dissect_isup_display_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_UID_ACTION_IND:
dissect_isup_uid_action_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_UID_CAPAB_IND:
dissect_isup_uid_capability_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECT_COUNTER:
dissect_isup_redirect_counter_parameter(parameter_tvb, parameter_tree, parameter_item, itu_isup_variant);
break;
case PARAM_TYPE_COLLECT_CALL_REQ:
dissect_isup_collect_call_request_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_NR:
dissect_isup_generic_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_DIGITS:
dissect_isup_generic_digits_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_APPLICATON_TRANS:
dissect_isup_application_transport_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
default:
switch (itu_isup_variant) {
case ISUP_JAPAN_VARIANT:
case ISUP_JAPAN_TTC_VARIANT:
switch (parameter_type) {
case JAPAN_ISUP_PARAM_CALLED_DIRECTORY_NUMBER:
dissect_japan_isup_called_dir_num(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_REDIRECT_FORWARD_INF:
dissect_japan_isup_redirect_fwd_inf(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_REDIRECT_BACKWARD_INF:
dissect_japan_isup_redirect_backw_inf(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_EMERGENCY_CALL_IND:
dissect_japan_isup_emergency_call_ind(parameter_tvb, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_EMERGENCY_CALL_INF_IND:
dissect_japan_isup_emergency_call_inf_ind(parameter_tvb, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_NETWORK_POI_CA:
dissect_japan_isup_network_poi_cad(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_TYPE_CARRIER_INFO:
dissect_japan_isup_carrier_information(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_CHARGE_INF_DELAY:
dissect_japan_isup_charge_inf_delay(parameter_tvb, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_TYPE_ADDITONAL_USER_CAT:
dissect_japan_isup_additonal_user_cat(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_REASON_FOR_CLIP_FAIL:
dissect_japan_isup_reason_for_clip_fail(parameter_tvb, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_TYPE_CONTRACTOR_NUMBER:
dissect_japan_isup_contractor_number(parameter_tvb, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_TYPE_CHARGE_INF_TYPE:
chg_inf_type = dissect_japan_chg_inf_type(parameter_tvb, parameter_tree, parameter_item);
break;
case JAPAN_ISUP_PARAM_TYPE_CHARGE_INF:
dissect_japan_chg_inf_param(parameter_tvb, pinfo, parameter_tree, parameter_item, chg_inf_type);
break;
case JAPAN_ISUP_PARAM_TYPE_CHARGE_AREA_INFO:
dissect_japan_isup_charge_area_info(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
default:
dissect_isup_unknown_parameter(parameter_tvb, parameter_item);
break;
}
break;
default:
dissect_isup_unknown_parameter(parameter_tvb, parameter_item);
break;
}
break;
}
offset += MIN(parameter_length, actual_length);
}
}
else {
proto_tree_add_uint_format(isup_tree, hf_isup_parameter_type, optional_parameters_tvb , offset, PARAMETER_TYPE_LENGTH,
parameter_type, "End of optional parameters (%u)", parameter_type);
}
}
}
static void
dissect_ansi_isup_optional_parameter(tvbuff_t *optional_parameters_tvb, packet_info *pinfo, proto_tree *isup_tree, guint8 itu_isup_variant)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
gint offset = 0;
guint parameter_type, parameter_length, actual_length;
tvbuff_t *parameter_tvb;
guint8 octet;
parameter_type = 0xFF;
while ((tvb_reported_length_remaining(optional_parameters_tvb, offset) >= 1) && (parameter_type != PARAM_TYPE_END_OF_OPT_PARAMS)) {
parameter_type = tvb_get_guint8(optional_parameters_tvb, offset);
if (parameter_type != PARAM_TYPE_END_OF_OPT_PARAMS) {
parameter_length = tvb_get_guint8(optional_parameters_tvb, offset + PARAMETER_TYPE_LENGTH);
parameter_tree = proto_tree_add_subtree_format(isup_tree, optional_parameters_tvb,
offset, parameter_length + PARAMETER_TYPE_LENGTH + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item, "Parameter: type %u",
parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_opt_parameter_type, optional_parameters_tvb, offset,
PARAMETER_TYPE_LENGTH, parameter_type);
offset += PARAMETER_TYPE_LENGTH;
octet = tvb_get_guint8(optional_parameters_tvb, offset);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, optional_parameters_tvb, offset,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
offset += PARAMETER_LENGTH_IND_LENGTH;
if (octet == 0)
continue;
actual_length = tvb_reported_length_remaining(optional_parameters_tvb, offset);
if (actual_length > 0) {
parameter_tvb = tvb_new_subset(optional_parameters_tvb, offset, MIN(parameter_length, actual_length), parameter_length);
switch (parameter_type) {
case PARAM_TYPE_CALL_REF:
dissect_isup_call_reference_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_TRANSM_MEDIUM_REQU:
dissect_isup_transmission_medium_requirement_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_ACC_TRANSP:
dissect_isup_access_transport_parameter(parameter_tvb, parameter_tree, parameter_item, pinfo);
break;
case PARAM_TYPE_CALLED_PARTY_NR:
dissect_isup_called_party_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SUBSQT_NR:
dissect_isup_subsequent_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_NATURE_OF_CONN_IND:
dissect_isup_nature_of_connection_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_FORW_CALL_IND:
dissect_isup_forward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_OPT_FORW_CALL_IND:
dissect_isup_optional_forward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALLING_PRTY_CATEG:
dissect_isup_calling_partys_category_parameter(parameter_tvb, parameter_tree, parameter_item, itu_isup_variant);
break;
case PARAM_TYPE_CALLING_PARTY_NR:
dissect_isup_calling_party_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECTING_NR:
dissect_isup_redirecting_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECTION_NR:
dissect_isup_redirection_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CONNECTION_REQ:
dissect_isup_connection_request_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_INFO_REQ_IND:
dissect_isup_information_request_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_INFO_IND:
dissect_isup_information_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CONTINUITY_IND:
dissect_isup_continuity_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_BACKW_CALL_IND:
dissect_isup_backward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CAUSE_INDICATORS:
dissect_ansi_isup_cause_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECTION_INFO:
dissect_isup_redirection_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CIRC_GRP_SV_MSG_TYPE:
dissect_isup_circuit_group_supervision_message_type_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_RANGE_AND_STATUS:
dissect_isup_range_and_status_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_FACILITY_IND:
dissect_isup_facility_ind_parameter(parameter_tvb, parameter_item);
break;
case PARAM_TYPE_CLSD_USR_GRP_ILOCK_CD:
dissect_isup_closed_user_group_interlock_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_USER_SERVICE_INFO:
dissect_isup_user_service_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SIGNALLING_POINT_CODE:
dissect_isup_signalling_point_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_USER_TO_USER_INFO:
dissect_isup_user_to_user_information_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CONNECTED_NR:
dissect_isup_connected_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SUSP_RESUME_IND:
dissect_isup_suspend_resume_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_TRANSIT_NETW_SELECT:
dissect_isup_transit_network_selection_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_EVENT_INFO:
dissect_isup_event_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CIRC_ASSIGN_MAP:
dissect_isup_circuit_assignment_map_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CIRC_STATE_IND:
dissect_isup_circuit_state_ind_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_AUTO_CONG_LEVEL:
dissect_isup_automatic_congestion_level_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_ORIG_CALLED_NR:
dissect_isup_original_called_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_OPT_BACKW_CALL_IND:
dissect_isup_optional_backward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_USER_TO_USER_IND:
dissect_isup_user_to_user_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_ORIG_ISC_POINT_CODE:
dissect_isup_original_isc_point_code_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_NOTIF_IND:
dissect_isup_generic_notification_indicator_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_HIST_INFO :
dissect_isup_call_history_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_ACC_DELIV_INFO:
dissect_isup_access_delivery_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_NETW_SPECIFIC_FACLTY:
dissect_isup_network_specific_facility_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_USER_SERVICE_INFO_PR:
dissect_isup_user_service_information_prime_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_PROPAG_DELAY_COUNTER:
dissect_isup_propagation_delay_counter_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REMOTE_OPERATIONS:
dissect_isup_remote_operations_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SERVICE_ACTIVATION:
dissect_isup_service_activation_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_USER_TELESERV_INFO:
dissect_isup_user_teleservice_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_TRANSM_MEDIUM_USED:
dissect_isup_transmission_medium_used_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_DIV_INFO:
dissect_isup_call_diversion_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_ECHO_CTRL_INFO:
dissect_isup_echo_control_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_MSG_COMPAT_INFO:
dissect_isup_message_compatibility_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_PARAM_COMPAT_INFO:
dissect_isup_parameter_compatibility_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_MLPP_PRECEDENCE:
dissect_isup_mlpp_precedence_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_MCID_REQ_IND:
dissect_isup_mcid_request_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_MCID_RSP_IND:
dissect_isup_mcid_response_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_HOP_COUNTER:
dissect_isup_hop_counter_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_ORIG_LINE_INFO:
dissect_isup_orig_line_info_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_TRANSM_MEDIUM_RQUR_PR:
dissect_isup_transmission_medium_requirement_prime_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_LOCATION_NR:
dissect_isup_location_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIR_NR_RSTRCT:
dissect_isup_redirection_number_restriction_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_TRANS_REF:
dissect_isup_call_transfer_reference_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_LOOP_PREV_IND:
dissect_isup_loop_prevention_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_TRANS_NR:
dissect_isup_call_transfer_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CCSS:
dissect_isup_ccss_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_FORW_GVNS:
dissect_isup_forward_gvns_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_BACKW_GVNS:
dissect_isup_backward_gvns_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECT_CAPAB:
dissect_isup_redirect_capability_parameter(parameter_tvb, parameter_tree, parameter_item, itu_isup_variant);
break;
case PARAM_TYPE_NETW_MGMT_CTRL:
dissect_isup_network_management_controls_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CORRELATION_ID:
dissect_isup_correlation_id_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SCF_ID:
dissect_isup_scf_id_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_DIV_TREAT_IND:
dissect_isup_call_diversion_treatment_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALLED_IN_NR:
dissect_isup_called_in_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALL_OFF_TREAT_IND:
dissect_isup_call_offering_treatment_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CHARGED_PARTY_IDENT:
dissect_isup_charged_party_identification_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CONF_TREAT_IND:
dissect_isup_conference_treatment_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_DISPLAY_INFO:
dissect_isup_display_information_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_UID_ACTION_IND:
dissect_isup_uid_action_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_UID_CAPAB_IND:
dissect_isup_uid_capability_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECT_COUNTER:
dissect_isup_redirect_counter_parameter(parameter_tvb, parameter_tree, parameter_item, itu_isup_variant);
break;
case PARAM_TYPE_COLLECT_CALL_REQ:
dissect_isup_collect_call_request_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALLING_GEODETIC_LOCATION:
dissect_isup_calling_geodetic_location_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_NR:
dissect_isup_generic_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_JURISDICTION:
dissect_isup_jurisdiction_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_NAME:
dissect_isup_generic_name_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_DIGITS:
dissect_isup_generic_digits_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CHARGE_NR:
dissect_isup_charge_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
case PARAM_TYPE_APPLICATON_TRANS:
dissect_isup_application_transport_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
break;
default:
dissect_isup_unknown_parameter(parameter_tvb, parameter_item);
break;
}
offset += MIN(parameter_length, actual_length);
}
}
else {
proto_tree_add_uint_format(isup_tree, hf_isup_parameter_type, optional_parameters_tvb , offset,
PARAMETER_TYPE_LENGTH, parameter_type, "End of optional parameters (%u)", parameter_type);
}
}
}
static gint
dissect_ansi_isup_circuit_validation_test_resp_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{
proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = ANSI_ISUP_PARAM_TYPE_CVR_RESP_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset, CVR_RESP_IND_LENGTH,
ett_isup_parameter, &parameter_item, "CVR Response Indicator");
proto_tree_add_uint_format_value(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type,
"%u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "CVR Response Indicator"));
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(CVR_RESP_IND_LENGTH, actual_length), CVR_RESP_IND_LENGTH);
dissect_isup_cvr_response_ind_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += CVR_RESP_IND_LENGTH;
parameter_type = ANSI_ISUP_PARAM_TYPE_CG_CHAR_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
CG_CHAR_IND_LENGTH, ett_isup_parameter, &parameter_item,
"Circuit Group Characteristics Indicators");
proto_tree_add_uint_format_value(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type,
"%u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "Circuit Group Characters"));
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(CG_CHAR_IND_LENGTH, actual_length), CG_CHAR_IND_LENGTH);
dissect_isup_circuit_group_char_ind_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += CG_CHAR_IND_LENGTH;
return offset;
}
static gint
dissect_ansi_isup_circuit_reservation_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_NATURE_OF_CONN_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
NATURE_OF_CONNECTION_IND_LENGTH, ett_isup_parameter, &parameter_item,
"Nature of Connection Indicators");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(NATURE_OF_CONNECTION_IND_LENGTH, actual_length), NATURE_OF_CONNECTION_IND_LENGTH);
dissect_isup_nature_of_connection_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += NATURE_OF_CONNECTION_IND_LENGTH;
return offset;
}
static gint
dissect_isup_initial_address_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree, guint8 itu_isup_variant)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_NATURE_OF_CONN_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
NATURE_OF_CONNECTION_IND_LENGTH, ett_isup_parameter, &parameter_item,
"Nature of Connection Indicators");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(NATURE_OF_CONNECTION_IND_LENGTH, actual_length), NATURE_OF_CONNECTION_IND_LENGTH);
dissect_isup_nature_of_connection_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += NATURE_OF_CONNECTION_IND_LENGTH;
parameter_type = PARAM_TYPE_FORW_CALL_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
FORWARD_CALL_IND_LENGTH, ett_isup_parameter, &parameter_item,
"Forward Call Indicators");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(FORWARD_CALL_IND_LENGTH, actual_length), FORWARD_CALL_IND_LENGTH);
dissect_isup_forward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += FORWARD_CALL_IND_LENGTH;
parameter_type = PARAM_TYPE_CALLING_PRTY_CATEG;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
CALLING_PRTYS_CATEGORY_LENGTH,
ett_isup_parameter, &parameter_item,
"Calling Party's category");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(CALLING_PRTYS_CATEGORY_LENGTH, actual_length), CALLING_PRTYS_CATEGORY_LENGTH);
dissect_isup_calling_partys_category_parameter(parameter_tvb, parameter_tree, parameter_item, itu_isup_variant);
offset += CALLING_PRTYS_CATEGORY_LENGTH;
switch (isup_standard) {
case ITU_STANDARD:
parameter_type = PARAM_TYPE_TRANSM_MEDIUM_REQU;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
TRANSMISSION_MEDIUM_REQUIREMENT_LENGTH,
ett_isup_parameter, &parameter_item,
"Transmission medium requirement");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset,
MIN(TRANSMISSION_MEDIUM_REQUIREMENT_LENGTH, actual_length),
TRANSMISSION_MEDIUM_REQUIREMENT_LENGTH);
dissect_isup_transmission_medium_requirement_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += TRANSMISSION_MEDIUM_REQUIREMENT_LENGTH;
break;
case ANSI_STANDARD:
parameter_type = PARAM_TYPE_USER_SERVICE_INFO;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"User Service Information");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
dissect_isup_user_service_information_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
break;
}
parameter_type = PARAM_TYPE_CALLED_PARTY_NR;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Called Party Number");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
dissect_isup_called_party_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint dissect_isup_subsequent_address_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_SUBSQT_NR;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Subsequent Number");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
dissect_isup_subsequent_number_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_information_request_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_INFO_REQ_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
INFO_REQUEST_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Information request indicators");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(INFO_REQUEST_IND_LENGTH, actual_length), INFO_REQUEST_IND_LENGTH);
dissect_isup_information_request_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += INFO_REQUEST_IND_LENGTH;
return offset;
}
static gint
dissect_isup_information_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{
proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_INFO_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
INFO_IND_LENGTH, ett_isup_parameter, &parameter_item,
"Information indicators");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(INFO_IND_LENGTH, actual_length), INFO_IND_LENGTH);
dissect_isup_information_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += INFO_IND_LENGTH;
return offset;
}
static gint
dissect_isup_continuity_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_CONTINUITY_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
CONTINUITY_IND_LENGTH, ett_isup_parameter, &parameter_item,
"Continuity indicators");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(CONTINUITY_IND_LENGTH, actual_length), CONTINUITY_IND_LENGTH);
dissect_isup_continuity_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += CONTINUITY_IND_LENGTH;
return offset;
}
static gint
dissect_isup_address_complete_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_BACKW_CALL_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
BACKWARD_CALL_IND_LENGTH, ett_isup_parameter, &parameter_item,
"Backward Call Indicators");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(BACKWARD_CALL_IND_LENGTH, actual_length), BACKWARD_CALL_IND_LENGTH);
dissect_isup_backward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += BACKWARD_CALL_IND_LENGTH;
return offset;
}
static gint
dissect_isup_connect_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_BACKW_CALL_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
BACKWARD_CALL_IND_LENGTH, ett_isup_parameter, &parameter_item,
"Backward Call Indicators");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(BACKWARD_CALL_IND_LENGTH, actual_length), BACKWARD_CALL_IND_LENGTH);
dissect_isup_backward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += BACKWARD_CALL_IND_LENGTH;
return offset;
}
static gint
dissect_isup_release_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_CAUSE_INDICATORS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Cause indicators");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
switch (isup_standard) {
case ITU_STANDARD:
dissect_isup_cause_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ANSI_STANDARD:
dissect_ansi_isup_cause_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
}
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_suspend_resume_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_SUSP_RESUME_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
SUSPEND_RESUME_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Suspend/Resume indicator");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(SUSPEND_RESUME_IND_LENGTH, actual_length), SUSPEND_RESUME_IND_LENGTH);
dissect_isup_suspend_resume_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += SUSPEND_RESUME_IND_LENGTH;
return offset;
}
static gint
dissect_isup_circuit_group_reset_query_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_RANGE_AND_STATUS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Range and status");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
dissect_isup_range_and_status_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_circuit_group_blocking_messages(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_CIRC_GRP_SV_MSG_TYPE;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
CIRC_GRP_SV_MSG_TYPE_LENGTH,
ett_isup_parameter, &parameter_item,
"Circuit group supervision message type");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(CIRC_GRP_SV_MSG_TYPE_LENGTH, actual_length), CIRC_GRP_SV_MSG_TYPE_LENGTH);
dissect_isup_circuit_group_supervision_message_type_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += CIRC_GRP_SV_MSG_TYPE_LENGTH;
parameter_type = PARAM_TYPE_RANGE_AND_STATUS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Range and status");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
dissect_isup_range_and_status_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_facility_request_accepted_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_FACILITY_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
FACILITY_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Facility indicator");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(FACILITY_IND_LENGTH, actual_length), FACILITY_IND_LENGTH);
dissect_isup_facility_ind_parameter(parameter_tvb, parameter_item);
offset += FACILITY_IND_LENGTH;
return offset;
}
static gint
dissect_isup_facility_reject_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_FACILITY_IND;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
FACILITY_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Facility indicator");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(FACILITY_IND_LENGTH, actual_length), FACILITY_IND_LENGTH);
dissect_isup_facility_ind_parameter(parameter_tvb, parameter_item);
offset += FACILITY_IND_LENGTH;
parameter_type = PARAM_TYPE_CAUSE_INDICATORS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Cause indicators, see Q.850");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb,
offset, PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
switch (isup_standard) {
case ITU_STANDARD:
dissect_isup_cause_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ANSI_STANDARD:
dissect_ansi_isup_cause_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
}
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_circuit_group_reset_acknowledgement_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_RANGE_AND_STATUS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Range and status");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
dissect_isup_range_and_status_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_circuit_group_query_response_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_RANGE_AND_STATUS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Range and status");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
dissect_isup_range_and_status_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
parameter_type = PARAM_TYPE_CIRC_STATE_IND;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Circuit state indicator (national use)");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
dissect_isup_circuit_state_ind_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_call_progress_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_EVENT_INFO;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset,
EVENT_INFO_LENGTH, ett_isup_parameter, &parameter_item,
"Event information");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(EVENT_INFO_LENGTH, actual_length), EVENT_INFO_LENGTH);
dissect_isup_event_information_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += EVENT_INFO_LENGTH;
return offset;
}
static gint
dissect_isup_user_to_user_information_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_USER_TO_USER_INFO;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"User-to-user information, see Q.931");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
dissect_isup_user_to_user_information_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_confusion_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_CAUSE_INDICATORS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Cause indicators, see Q.850");
proto_tree_add_uint(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type);
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length,
message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH,
parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
switch (isup_standard) {
case ITU_STANDARD:
dissect_isup_cause_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case ANSI_STANDARD:
dissect_ansi_isup_cause_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
}
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static int
dissect_french_isup_charging_pulse_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{
gint offset = 0;
proto_tree_add_item(isup_tree, hf_isup_french_coll_field, message_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(isup_tree, hf_isup_french_msg_num, message_tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_israeli_backward_charging_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{
gint offset = 0;
proto_tree_add_item(isup_tree, hf_isup_israeli_charging_message_indicators_current, message_tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(isup_tree, hf_isup_israeli_charging_message_indicators_next, message_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(isup_tree, hf_isup_israeli_current_rate, message_tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(isup_tree, hf_isup_israeli_time_indicator, message_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(isup_tree, hf_isup_israeli_next_rate, message_tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_israeli_traffic_change_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{
gint offset = 0;
proto_tree_add_item(isup_tree, hf_isup_israeli_charging_message_indicators_current, message_tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(isup_tree, hf_isup_israeli_charging_message_indicators_next, message_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(isup_tree, hf_isup_israeli_time_indicator, message_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(isup_tree, hf_isup_israeli_next_rate, message_tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_japan_chg_inf(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree)
{
proto_item *parameter_item;
proto_tree *parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
guint8 chg_inf_type;
parameter_type = JAPAN_ISUP_PARAM_TYPE_CHARGE_INF_TYPE;
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb, offset, 1,
ett_isup_parameter, &parameter_item, "Charge information type");
proto_tree_add_uint_format_value(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type,
"%u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &japan_isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(1, actual_length), 1);
chg_inf_type = tvb_get_guint8(parameter_tvb, 0);
dissect_japan_chg_inf_type(parameter_tvb, parameter_tree, parameter_item);
offset += 1;
parameter_type = JAPAN_ISUP_PARAM_TYPE_CHARGE_INF;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_tree = proto_tree_add_subtree(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
ett_isup_parameter, &parameter_item,
"Charge information");
proto_tree_add_uint_format_value(parameter_tree, hf_isup_mand_parameter_type, message_tvb, 0, 0, parameter_type,
"%u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &japan_isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset,
PARAMETER_POINTER_LENGTH, parameter_pointer);
proto_tree_add_uint(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer,
PARAMETER_LENGTH_IND_LENGTH, parameter_length);
actual_length = tvb_ensure_captured_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb,
offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH,
MIN(parameter_length, actual_length),
parameter_length);
switch (chg_inf_type) {
case 3:
dissect_japan_chg_inf_type_acr(parameter_tvb, parameter_tree, parameter_item);
break;
case 254:
dissect_japan_chg_inf_type_crt(parameter_tvb, parameter_tree, parameter_item);
break;
default:
proto_tree_add_expert_format(parameter_tree, pinfo, &ei_isup_not_dissected_yet, parameter_tvb, 0, -1, "Charge information data, not dissected yet");
break;
}
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static void
dissect_ansi_isup_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree, guint8 itu_isup_variant, guint32 circuit_id)
{
isup_tap_rec_t *tap_rec;
tvbuff_t *parameter_tvb;
tvbuff_t *optional_parameter_tvb;
proto_tree *pass_along_tree;
proto_item *type_item;
gint offset, bufferlength;
guint8 message_type, opt_parameter_pointer;
gint opt_part_possible = FALSE;
tap_calling_number = NULL;
offset = 0;
message_type = tvb_get_guint8(message_tvb, 0);
type_item = proto_tree_add_uint_format(isup_tree, hf_isup_message_type, message_tvb, 0, MESSAGE_TYPE_LENGTH, message_type, "Message type: %s (%u)",
val_to_str_ext_const(message_type, &ansi_isup_message_type_value_ext, "reserved"), message_type);
offset += MESSAGE_TYPE_LENGTH;
tap_rec = (isup_tap_rec_t *)wmem_alloc(wmem_packet_scope(), sizeof(isup_tap_rec_t));
tap_rec->message_type = message_type;
tap_rec->calling_number = NULL;
tap_rec->called_number = NULL;
tap_rec->circuit_id = circuit_id;
parameter_tvb = tvb_new_subset_remaining(message_tvb, offset);
switch (message_type) {
case MESSAGE_TYPE_INITIAL_ADDR:
offset += dissect_isup_initial_address_message(parameter_tvb, pinfo, isup_tree, itu_isup_variant);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_SUBSEQ_ADDR:
offset += dissect_isup_subsequent_address_message(parameter_tvb, pinfo, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_INFO_REQ:
offset += dissect_isup_information_request_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_INFO:
offset += dissect_isup_information_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_CONTINUITY:
offset += dissect_isup_continuity_message(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_ADDR_CMPL:
offset += dissect_isup_address_complete_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_CONNECT:
offset += dissect_isup_connect_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_FORW_TRANS:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_ANSWER:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_RELEASE:
offset += dissect_isup_release_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_SUSPEND:
offset += dissect_isup_suspend_resume_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_RESUME:
offset += dissect_isup_suspend_resume_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_REL_CMPL:
break;
case MESSAGE_TYPE_CONT_CHECK_REQ:
break;
case MESSAGE_TYPE_RESET_CIRCUIT:
break;
case MESSAGE_TYPE_BLOCKING:
break;
case MESSAGE_TYPE_UNBLOCKING:
break;
case MESSAGE_TYPE_BLOCK_ACK:
break;
case MESSAGE_TYPE_UNBLOCK_ACK:
break;
case MESSAGE_TYPE_CIRC_GRP_RST:
offset += dissect_isup_circuit_group_reset_query_message(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_BLCK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_UNBL:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_BL_ACK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_UNBL_ACK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_FACILITY_REQ:
offset += dissect_isup_facility_request_accepted_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_FACILITY_ACC:
offset += dissect_isup_facility_request_accepted_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_FACILITY_REJ:
offset += dissect_isup_facility_reject_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_LOOP_BACK_ACK:
break;
case MESSAGE_TYPE_PASS_ALONG:
{
guint8 pa_message_type;
pa_message_type = tvb_get_guint8(parameter_tvb, 0);
pass_along_tree = proto_tree_add_subtree_format(isup_tree, parameter_tvb, offset, -1,
ett_isup_pass_along_message, NULL, "Pass-along: %s Message (%u)",
val_to_str_ext_const(pa_message_type, &isup_message_type_value_acro_ext, "reserved"),
pa_message_type);
dissect_ansi_isup_message(parameter_tvb, pinfo, pass_along_tree, itu_isup_variant, circuit_id);
break;
}
case MESSAGE_TYPE_CIRC_GRP_RST_ACK:
offset += dissect_isup_circuit_group_reset_acknowledgement_message(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_QRY:
offset += dissect_isup_circuit_group_reset_query_message(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_QRY_RSP:
offset += dissect_isup_circuit_group_query_response_message(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CALL_PROGRSS:
offset += dissect_isup_call_progress_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_USER2USER_INFO:
offset += dissect_isup_user_to_user_information_message(parameter_tvb, pinfo, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_UNEQUIPPED_CIC:
break;
case MESSAGE_TYPE_CONFUSION:
offset += dissect_isup_confusion_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_OVERLOAD:
break;
case MESSAGE_TYPE_CHARGE_INFO:
bufferlength = tvb_reported_length_remaining(message_tvb, offset);
if (bufferlength != 0)
proto_tree_add_expert(isup_tree, pinfo, &ei_isup_format_national_matter, parameter_tvb, 0, bufferlength);
break;
case MESSAGE_TYPE_NETW_RESRC_MGMT:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_FACILITY:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_USER_PART_TEST:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_USER_PART_AVAIL:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_IDENT_REQ:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_IDENT_RSP:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_SEGMENTATION:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_LOOP_PREVENTION:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_APPLICATION_TRANS:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_PRE_RELEASE_INFO:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_SUBSEQUENT_DIR_NUM:
bufferlength = tvb_reported_length_remaining(message_tvb, offset);
if (bufferlength != 0)
proto_tree_add_expert(isup_tree, pinfo, &ei_isup_format_national_matter, parameter_tvb, 0, bufferlength);
break;
case ANSI_ISUP_MESSAGE_TYPE_CIRCUIT_RES_ACK:
break;
case ANSI_ISUP_MESSAGE_TYPE_CIRCUIT_RES:
offset += dissect_ansi_isup_circuit_reservation_message(parameter_tvb, isup_tree);
break;
case ANSI_ISUP_MESSAGE_TYPE_CCT_VAL_TEST_RSP:
opt_part_possible = TRUE;
offset += dissect_ansi_isup_circuit_validation_test_resp_message(parameter_tvb, isup_tree);
break;
case ANSI_ISUP_MESSAGE_TYPE_CCT_VAL_TEST:
break;
default:
bufferlength = tvb_reported_length_remaining(message_tvb, offset);
if (bufferlength != 0)
expert_add_info(pinfo, type_item, &ei_isup_message_type_unknown);
break;
}
if (opt_part_possible == TRUE) {
opt_parameter_pointer = tvb_get_guint8(message_tvb, offset);
if (opt_parameter_pointer > 0) {
proto_tree_add_uint_format(isup_tree, hf_isup_pointer_to_start_of_optional_part, message_tvb, offset,
PARAMETER_POINTER_LENGTH, opt_parameter_pointer,
"Pointer to start of optional part: %u", opt_parameter_pointer);
offset += opt_parameter_pointer;
optional_parameter_tvb = tvb_new_subset_remaining(message_tvb, offset);
dissect_ansi_isup_optional_parameter(optional_parameter_tvb, pinfo, isup_tree, itu_isup_variant);
}
else
proto_tree_add_uint_format(isup_tree, hf_isup_pointer_to_start_of_optional_part, message_tvb, offset,
PARAMETER_POINTER_LENGTH, opt_parameter_pointer,
"No optional parameter present (Pointer: %u)", opt_parameter_pointer);
}
else if (message_type != MESSAGE_TYPE_CHARGE_INFO)
expert_add_info(pinfo, type_item, &ei_isup_message_type_no_optional_parameters);
tap_rec->calling_number = tap_calling_number ? tap_calling_number : wmem_strdup(wmem_packet_scope(), "");
tap_rec->called_number = tap_called_number;
tap_rec->cause_value = tap_cause_value;
tap_queue_packet(isup_tap, pinfo, tap_rec);
}
static void
dissect_isup_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree, guint8 itu_isup_variant, guint32 circuit_id)
{
isup_tap_rec_t *tap_rec;
tvbuff_t *parameter_tvb;
tvbuff_t *optional_parameter_tvb;
proto_tree *pass_along_tree;
proto_item *type_item = NULL;
gint offset, bufferlength;
guint8 message_type, opt_parameter_pointer;
gint opt_part_possible = FALSE;
tap_calling_number = NULL;
offset = 0;
message_type = tvb_get_guint8(message_tvb, 0);
switch (itu_isup_variant) {
case ISUP_ITU_STANDARD_VARIANT:
type_item = proto_tree_add_uint_format_value(isup_tree, hf_isup_message_type, message_tvb, 0, MESSAGE_TYPE_LENGTH, message_type,
"%s (%u)",
val_to_str_ext_const(message_type, &isup_message_type_value_ext, "reserved"),
message_type);
break;
case ISUP_FRENCH_VARIANT:
type_item = proto_tree_add_uint_format_value(isup_tree, hf_isup_message_type, message_tvb, 0, MESSAGE_TYPE_LENGTH, message_type,
"%s (%u)",
val_to_str_ext_const(message_type, &french_isup_message_type_value_ext, "reserved"),
message_type);
break;
case ISUP_ISRAELI_VARIANT:
type_item = proto_tree_add_uint_format_value(isup_tree, hf_isup_message_type, message_tvb, 0, MESSAGE_TYPE_LENGTH, message_type,
"%s (%u)",
val_to_str_ext_const(message_type, &israeli_isup_message_type_value_ext, "reserved"),
message_type);
break;
case ISUP_RUSSIAN_VARIANT:
type_item = proto_tree_add_uint_format_value(isup_tree, hf_isup_message_type, message_tvb, 0, MESSAGE_TYPE_LENGTH, message_type,
"%s (%u)",
val_to_str_ext_const(message_type, &russian_isup_message_type_value_ext, "reserved"),
message_type);
break;
case ISUP_JAPAN_VARIANT:
case ISUP_JAPAN_TTC_VARIANT:
type_item = proto_tree_add_uint_format_value(isup_tree, hf_isup_message_type, message_tvb, 0, MESSAGE_TYPE_LENGTH, message_type,
"%s (%u)",
val_to_str_ext_const(message_type, &japan_isup_message_type_value_ext, "reserved"),
message_type);
break;
}
offset += MESSAGE_TYPE_LENGTH;
tap_rec = (isup_tap_rec_t *)wmem_alloc(wmem_packet_scope(), sizeof(isup_tap_rec_t));
tap_rec->message_type = message_type;
tap_rec->calling_number = NULL;
tap_rec->called_number = NULL;
tap_rec->circuit_id = circuit_id;
parameter_tvb = tvb_new_subset_remaining(message_tvb, offset);
switch (message_type) {
case MESSAGE_TYPE_INITIAL_ADDR:
offset += dissect_isup_initial_address_message(parameter_tvb, pinfo, isup_tree, itu_isup_variant);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_SUBSEQ_ADDR:
offset += dissect_isup_subsequent_address_message(parameter_tvb, pinfo, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_INFO_REQ:
offset += dissect_isup_information_request_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_INFO:
offset += dissect_isup_information_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_CONTINUITY:
offset += dissect_isup_continuity_message(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_ADDR_CMPL:
offset += dissect_isup_address_complete_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_CONNECT:
offset += dissect_isup_connect_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_FORW_TRANS:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_ANSWER:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_RELEASE:
offset += dissect_isup_release_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_SUSPEND:
offset += dissect_isup_suspend_resume_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_RESUME:
offset += dissect_isup_suspend_resume_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_REL_CMPL:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_CONT_CHECK_REQ:
break;
case MESSAGE_TYPE_RESET_CIRCUIT:
break;
case MESSAGE_TYPE_BLOCKING:
break;
case MESSAGE_TYPE_UNBLOCKING:
break;
case MESSAGE_TYPE_BLOCK_ACK:
break;
case MESSAGE_TYPE_UNBLOCK_ACK:
break;
case MESSAGE_TYPE_CIRC_GRP_RST:
offset += dissect_isup_circuit_group_reset_query_message(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_BLCK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_UNBL:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_BL_ACK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_UNBL_ACK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_FACILITY_REQ:
offset += dissect_isup_facility_request_accepted_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_FACILITY_ACC:
offset += dissect_isup_facility_request_accepted_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_FACILITY_REJ:
offset += dissect_isup_facility_reject_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_LOOP_BACK_ACK:
break;
case MESSAGE_TYPE_PASS_ALONG:
{
guint8 pa_message_type;
pa_message_type = tvb_get_guint8(parameter_tvb, 0);
pass_along_tree = proto_tree_add_subtree_format(isup_tree, parameter_tvb, offset, -1,
ett_isup_pass_along_message, NULL,
"Pass-along: %s Message (%u)",
val_to_str_ext_const(pa_message_type, &isup_message_type_value_acro_ext, "reserved"),
pa_message_type);
dissect_isup_message(parameter_tvb, pinfo, pass_along_tree, itu_isup_variant, circuit_id);
break;
}
case MESSAGE_TYPE_CIRC_GRP_RST_ACK:
offset += dissect_isup_circuit_group_reset_acknowledgement_message(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_QRY:
offset += dissect_isup_circuit_group_reset_query_message(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_QRY_RSP:
offset += dissect_isup_circuit_group_query_response_message(parameter_tvb, pinfo, isup_tree);
break;
case MESSAGE_TYPE_CALL_PROGRSS:
offset += dissect_isup_call_progress_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_USER2USER_INFO:
offset += dissect_isup_user_to_user_information_message(parameter_tvb, pinfo, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_UNEQUIPPED_CIC:
break;
case MESSAGE_TYPE_CONFUSION:
offset += dissect_isup_confusion_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_OVERLOAD:
break;
case MESSAGE_TYPE_CHARGE_INFO:
bufferlength = tvb_reported_length_remaining(message_tvb, offset);
if (bufferlength != 0) {
switch (itu_isup_variant) {
case ISUP_RUSSIAN_VARIANT:
proto_tree_add_expert(isup_tree, pinfo, &ei_isup_format_national_matter, parameter_tvb, 0, bufferlength);
break;
default:
proto_tree_add_expert(isup_tree, pinfo, &ei_isup_format_national_matter, parameter_tvb, 0, bufferlength);
break;
}
}
break;
case MESSAGE_TYPE_NETW_RESRC_MGMT:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_FACILITY:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_USER_PART_TEST:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_USER_PART_AVAIL:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_IDENT_REQ:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_IDENT_RSP:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_SEGMENTATION:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_LOOP_PREVENTION:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_APPLICATION_TRANS:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_PRE_RELEASE_INFO:
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_SUBSEQUENT_DIR_NUM:
bufferlength = tvb_reported_length_remaining(message_tvb, offset);
if (bufferlength != 0)
proto_tree_add_expert(isup_tree, pinfo, &ei_isup_format_national_matter, parameter_tvb, 0, bufferlength);
break;
default:
switch (itu_isup_variant) {
case ISUP_ITU_STANDARD_VARIANT:
bufferlength = tvb_reported_length_remaining(message_tvb, offset);
if (bufferlength != 0)
expert_add_info(pinfo, type_item, &ei_isup_message_type_unknown);
break;
case ISUP_FRENCH_VARIANT:
switch (message_type) {
case FRENCH_CHARGING_PULSE:
offset += dissect_french_isup_charging_pulse_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case FRENCH_CHARGING_ACK:
opt_part_possible = TRUE;
break;
default:
bufferlength = tvb_reported_length_remaining(message_tvb, offset);
if (bufferlength != 0)
expert_add_info(pinfo, type_item, &ei_isup_message_type_unknown);
break;
}
break;
case ISUP_ISRAELI_VARIANT:
switch (message_type) {
case ISRAELI_BACKWARD_CHARGING:
offset += dissect_israeli_backward_charging_message(parameter_tvb, isup_tree);
break;
case ISRAELI_TRAFFIC_CHANGE:
offset += dissect_israeli_traffic_change_message(parameter_tvb, isup_tree);
break;
case ISRAELI_CHARGE_ACK:
break;
default:
bufferlength = tvb_reported_length_remaining(message_tvb, offset);
if (bufferlength != 0)
expert_add_info(pinfo, type_item, &ei_isup_message_type_unknown);
break;
}
break;
case ISUP_RUSSIAN_VARIANT:
switch (message_type) {
case RUSSIAN_CLEAR_CALLING_LINE:
break;
case RUSSIAN_RINGING:
opt_part_possible = TRUE;
break;
default:
bufferlength = tvb_reported_length_remaining(message_tvb, offset);
if (bufferlength != 0)
expert_add_info(pinfo, type_item, &ei_isup_message_type_unknown);
break;
}
break;
case ISUP_JAPAN_VARIANT:
case ISUP_JAPAN_TTC_VARIANT:
switch (message_type) {
case MESSAGE_TYPE_JAPAN_CHARG_INF:
offset += dissect_japan_chg_inf(parameter_tvb, pinfo, isup_tree);
opt_part_possible = TRUE;
break;
default:
bufferlength = tvb_reported_length_remaining(message_tvb, offset);
if (bufferlength != 0)
expert_add_info(pinfo, type_item, &ei_isup_message_type_unknown);
break;
}
break;
}
break;
}
if (opt_part_possible == TRUE) {
opt_parameter_pointer = tvb_get_guint8(message_tvb, offset);
if (opt_parameter_pointer > 0) {
proto_tree_add_uint_format(isup_tree, hf_isup_pointer_to_start_of_optional_part, message_tvb, offset,
PARAMETER_POINTER_LENGTH, opt_parameter_pointer,
"Pointer to start of optional part: %u", opt_parameter_pointer);
offset += opt_parameter_pointer;
optional_parameter_tvb = tvb_new_subset_remaining(message_tvb, offset);
dissect_isup_optional_parameter(optional_parameter_tvb, pinfo, isup_tree, itu_isup_variant);
}
else
proto_tree_add_uint_format(isup_tree, hf_isup_pointer_to_start_of_optional_part, message_tvb, offset,
PARAMETER_POINTER_LENGTH, opt_parameter_pointer,
"No optional parameter present (Pointer: %u)", opt_parameter_pointer);
}
else if (message_type != MESSAGE_TYPE_CHARGE_INFO)
expert_add_info(pinfo, type_item, &ei_isup_message_type_no_optional_parameters);
tap_rec->calling_number = tap_calling_number ? tap_calling_number : wmem_strdup(wmem_packet_scope(), "");
tap_rec->called_number = tap_called_number;
tap_rec->cause_value = tap_cause_value;
tap_queue_packet(isup_tap, pinfo, tap_rec);
}
static int
dissect_isup(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *isup_tree = NULL;
tvbuff_t *message_tvb;
guint16 cic;
guint8 message_type;
guint8 itu_isup_variant = g_isup_variant;
value_string_ext *used_value_string_ext;
message_type = tvb_get_guint8(tvb, CIC_OFFSET + CIC_LENGTH);
pinfo->ctype = CT_ISUP;
switch (mtp3_standard) {
case ANSI_STANDARD:
isup_standard = ANSI_STANDARD;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISUP(ANSI)");
cic = tvb_get_letohs(tvb, CIC_OFFSET) & 0x3FFF;
if (isup_show_cic_in_info) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s (CIC %u) ",
val_to_str_ext_const(message_type, &ansi_isup_message_type_value_acro_ext, "reserved"),
cic);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str_ext_const(message_type, &ansi_isup_message_type_value_acro_ext, "reserved"));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_isup, tvb, 0, -1, ENC_NA);
isup_tree = proto_item_add_subtree(ti, ett_isup);
proto_tree_add_uint(isup_tree, hf_isup_cic, tvb, CIC_OFFSET, CIC_LENGTH, cic);
}
message_tvb = tvb_new_subset_remaining(tvb, CIC_LENGTH);
dissect_ansi_isup_message(message_tvb, pinfo, isup_tree, ISUP_ITU_STANDARD_VARIANT, cic);
break;
default:
isup_standard = ITU_STANDARD;
cic = tvb_get_letohs(tvb, CIC_OFFSET) & 0x0FFF;
switch (itu_isup_variant) {
case ISUP_FRENCH_VARIANT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISUP(French)");
used_value_string_ext = &french_isup_message_type_value_acro_ext;
break;
case ISUP_ISRAELI_VARIANT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISUP(Israeli)");
used_value_string_ext = &israeli_isup_message_type_value_acro_ext;
break;
case ISUP_RUSSIAN_VARIANT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISUP(Russian)");
used_value_string_ext = &russian_isup_message_type_value_acro_ext;
break;
case ISUP_JAPAN_VARIANT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISUP(Japan)");
used_value_string_ext = &japan_isup_message_type_value_acro_ext;
break;
case ISUP_JAPAN_TTC_VARIANT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISUP(Japan TTC)");
used_value_string_ext = &japan_isup_message_type_value_acro_ext;
cic = tvb_get_letohs(tvb, CIC_OFFSET) & 0x1FFF;
break;
default:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISUP(ITU)");
used_value_string_ext = &isup_message_type_value_acro_ext;
break;
}
if (isup_show_cic_in_info) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s (CIC %u) ",
val_to_str_ext_const(message_type, used_value_string_ext, "reserved"),
cic);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str_ext_const(message_type, used_value_string_ext, "reserved"));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_isup, tvb, 0, -1, ENC_NA);
isup_tree = proto_item_add_subtree(ti, ett_isup);
proto_tree_add_uint(isup_tree, hf_isup_cic, tvb, CIC_OFFSET, CIC_LENGTH, cic);
}
message_tvb = tvb_new_subset_remaining(tvb, CIC_LENGTH);
dissect_isup_message(message_tvb, pinfo, isup_tree, itu_isup_variant, cic);
}
return tvb_captured_length(tvb);
}
static int
dissect_bicc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *bicc_tree = NULL;
tvbuff_t *message_tvb;
guint32 bicc_cic;
guint8 message_type;
guint8 itu_isup_variant = g_isup_variant;
value_string_ext *used_value_string_ext;
switch (itu_isup_variant) {
case ISUP_FRENCH_VARIANT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BICC(French)");
used_value_string_ext = &french_isup_message_type_value_acro_ext;
break;
case ISUP_ISRAELI_VARIANT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BICC(Israeli)");
used_value_string_ext = &israeli_isup_message_type_value_acro_ext;
break;
case ISUP_RUSSIAN_VARIANT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BICC(Russian)");
used_value_string_ext = &russian_isup_message_type_value_acro_ext;
break;
case ISUP_JAPAN_VARIANT:
case ISUP_JAPAN_TTC_VARIANT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BICC(Japan)");
used_value_string_ext = &japan_isup_message_type_value_acro_ext;
break;
default:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BICC(ITU)");
used_value_string_ext = &isup_message_type_value_acro_ext;
break;
}
message_type = tvb_get_guint8(tvb, BICC_CIC_OFFSET + BICC_CIC_LENGTH);
bicc_cic = tvb_get_letohl(tvb, BICC_CIC_OFFSET);
pinfo->ctype = CT_BICC;
col_clear(pinfo->cinfo, COL_INFO);
if (isup_show_cic_in_info) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ",
"%s (CIC %u)",
val_to_str_ext_const(message_type, used_value_string_ext, "reserved"),
bicc_cic);
} else {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ",
"%s",
val_to_str_ext_const(message_type, used_value_string_ext, "reserved"));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_bicc, tvb, 0, -1, ENC_NA);
bicc_tree = proto_item_add_subtree(ti, ett_bicc);
proto_tree_add_uint_format(bicc_tree, hf_bicc_cic, tvb, BICC_CIC_OFFSET, BICC_CIC_LENGTH,
bicc_cic, "CIC: %u", bicc_cic);
}
message_tvb = tvb_new_subset_remaining(tvb, BICC_CIC_LENGTH);
dissect_isup_message(message_tvb, pinfo, bicc_tree, itu_isup_variant, bicc_cic);
col_set_fence(pinfo->cinfo, COL_INFO);
return tvb_captured_length(tvb);
}
static int
dissect_application_isup(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *ti;
proto_tree *isup_tree = NULL;
tvbuff_t *message_tvb;
guint8 message_type;
char *version, *base;
guint8 itu_isup_variant = ISUP_ITU_STANDARD_VARIANT;
if (data) {
http_message_info_t *message_info = (http_message_info_t *)data;
if (message_info->media_str) {
version = ws_find_media_type_parameter(message_info->media_str, "version");
base = ws_find_media_type_parameter(message_info->media_str, "base");
if ((version && g_ascii_strncasecmp(version, "ansi", 4) == 0) ||
(base && g_ascii_strncasecmp(base, "ansi", 4) == 0)) {
isup_standard = ANSI_STANDARD;
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/ISUP(ANSI)");
message_type = tvb_get_guint8(tvb, 0);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ",
"ISUP:%s",
val_to_str_ext_const(message_type, &ansi_isup_message_type_value_acro_ext, "reserved"));
if (tree) {
ti = proto_tree_add_item(tree, proto_isup, tvb, 0, -1, ENC_NA);
isup_tree = proto_item_add_subtree(ti, ett_isup);
}
message_tvb = tvb_new_subset_remaining(tvb, 0);
dissect_ansi_isup_message(message_tvb, pinfo, isup_tree, ISUP_ITU_STANDARD_VARIANT, 0);
return tvb_reported_length(tvb);
} else if ((version && g_ascii_strcasecmp(version, "spirou") == 0) ||
(base && g_ascii_strcasecmp(base, "spirou") == 0)) {
isup_standard = ITU_STANDARD;
itu_isup_variant = ISUP_FRENCH_VARIANT;
} else {
isup_standard = ITU_STANDARD;
}
g_free(version);
g_free(base);
} else {
isup_standard = ITU_STANDARD;
}
} else {
isup_standard = ITU_STANDARD;
}
message_type = tvb_get_guint8(tvb, 0);
switch (itu_isup_variant) {
case ISUP_ITU_STANDARD_VARIANT:
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/ISUP(ITU)");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ",
"ISUP:%s",
val_to_str_ext_const(message_type, &isup_message_type_value_acro_ext, "reserved"));
break;
case ISUP_FRENCH_VARIANT:
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/ISUP(French)");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ",
"ISUP:%s",
val_to_str_ext_const(message_type, &french_isup_message_type_value_acro_ext, "reserved"));
break;
#if 0
case ISUP_ISRAELI_VARIANT:
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/ISUP(Israeli)");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ",
"ISUP:%s",
val_to_str_ext_const(message_type, &israeli_isup_message_type_value_acro_ext, "reserved"));
break;
#endif
default:
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ",
"ISUP: Unknown variant %d", itu_isup_variant);
break;
}
if (tree) {
ti = proto_tree_add_item(tree, proto_isup, tvb, 0, -1, ENC_NA);
isup_tree = proto_item_add_subtree(ti, ett_isup);
}
message_tvb = tvb_new_subset_remaining(tvb, 0);
dissect_isup_message(message_tvb, pinfo, isup_tree, itu_isup_variant, 0);
return tvb_reported_length(tvb);
}
static void
msg_stats_tree_init(stats_tree *st)
{
st_node_msg = stats_tree_create_node(st, "Messages by Type", 0, TRUE);
st_node_dir = stats_tree_create_node(st, "Messages by Direction", 0, TRUE);
}
static int
msg_stats_tree_packet(stats_tree *st, packet_info *pinfo, epan_dissect_t *edt _U_, const void *p)
{
const gchar *msg = try_val_to_str_ext(((const isup_tap_rec_t*)p)->message_type, &isup_message_type_value_acro_ext);
gchar *src, *dst, *dir;
int msg_node;
int dir_node;
src = address_to_str(NULL, &pinfo->src);
dst = address_to_str(NULL, &pinfo->dst);
dir = wmem_strdup_printf(NULL, "%s->%s", src, dst);
wmem_free(NULL, src);
wmem_free(NULL, dst);
msg_node = tick_stat_node(st, msg, st_node_msg, TRUE);
tick_stat_node(st, dir, msg_node, FALSE);
dir_node = tick_stat_node(st, dir, st_node_dir, TRUE);
tick_stat_node(st, msg, dir_node, FALSE);
wmem_free(NULL, dir);
return 1;
}
void
proto_register_isup(void)
{
static hf_register_info hf[] = {
{ &hf_isup_cic,
{ "CIC", "isup.cic",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_message_type,
{ "Message Type", "isup.message_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_parameter_type,
{ "Parameter Type", "isup.parameter_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_mand_parameter_type,
{ "Mandatory Parameter", "isup.parameter_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &isup_parameter_type_value_ext, 0x0,
NULL, HFILL }},
{ &hf_isup_opt_parameter_type,
{ "Optional Parameter", "isup.parameter_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &ansi_isup_parameter_type_value_ext, 0x0,
NULL, HFILL }},
{ &hf_isup_parameter_length,
{ "Parameter Length", "isup.parameter_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_mandatory_variable_parameter_pointer,
{ "Pointer to Parameter", "isup.mandatory_variable_parameter_pointer",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_pointer_to_start_of_optional_part,
{ "Pointer to optional parameter part", "isup.optional_parameter_part_pointer",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_satellite_indicator,
{ "Satellite Indicator", "isup.satellite_indicator",
FT_UINT8, BASE_HEX, VALS(isup_satellite_ind_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_continuity_check_indicator,
{ "Continuity Check Indicator", "isup.continuity_check_indicator",
FT_UINT8, BASE_HEX, VALS(isup_continuity_check_ind_value), DC_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_echo_control_device_indicator,
{ "Echo Control Device Indicator", "isup.echo_control_device_indicator",
FT_BOOLEAN, 8, TFS(&isup_echo_control_device_ind_value), E_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_forw_call_natnl_inatnl_call_indicator,
{ "National/international call indicator", "isup.forw_call_natnl_inatnl_call_indicator",
FT_BOOLEAN, 16, TFS(&isup_natnl_inatnl_call_ind_value), A_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_forw_call_end_to_end_method_indicator,
{ "End-to-end method indicator", "isup.forw_call_end_to_end_method_indicator",
FT_UINT16, BASE_HEX, VALS(isup_end_to_end_method_ind_value), CB_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_forw_call_interworking_indicator,
{ "Interworking indicator", "isup.forw_call_interworking_indicator",
FT_BOOLEAN, 16, TFS(&isup_interworking_ind_value), D_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_forw_call_end_to_end_info_indicator,
{ "End-to-end information indicator", "isup.forw_call_end_to_end_information_indicator",
FT_BOOLEAN, 16, TFS(&isup_end_to_end_info_ind_value), E_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_forw_call_isdn_user_part_indicator,
{ "ISDN user part indicator", "isup.forw_call_isdn_user_part_indicator",
FT_BOOLEAN, 16, TFS(&isup_ISDN_user_part_ind_value), F_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_forw_call_preferences_indicator,
{ "ISDN user part preference indicator", "isup.forw_call_preferences_indicator",
FT_UINT16, BASE_HEX, VALS(isup_preferences_ind_value), HG_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_forw_call_isdn_access_indicator,
{ "ISDN access indicator", "isup.forw_call_isdn_access_indicator",
FT_BOOLEAN, 16, TFS(&isup_ISDN_originating_access_ind_value), I_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_forw_call_sccp_method_indicator,
{ "SCCP method indicator", "isup.forw_call_sccp_method_indicator",
FT_UINT16, BASE_HEX, VALS(isup_SCCP_method_ind_value), KJ_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_forw_call_ported_num_trans_indicator,
{ "Ported number translation indicator", "isup.forw_call_ported_num_trans_indicator",
FT_BOOLEAN, 16, TFS(&isup_ISDN_ported_num_trans_ind_value), M_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_forw_call_qor_attempt_indicator,
{ "Query on Release attempt indicator", "isup.forw_call_qor_attempt_indicator",
FT_BOOLEAN, 16, TFS(&isup_ISDN_qor_attempt_ind_value), N_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_calling_partys_category,
{ "Calling Party's category", "isup.calling_partys_category",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &isup_calling_partys_category_value_ext, 0x0,
NULL, HFILL }},
{ &hf_russian_isup_calling_partys_category,
{ "Calling Party's category", "isup.russian.calling_partys_category",
FT_UINT8, BASE_HEX, VALS(isup_calling_partys_category_value), 0x0,
NULL, HFILL }},
{ &hf_isup_transmission_medium_requirement,
{ "Transmission medium requirement", "isup.transmission_medium_requirement",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &isup_transmission_medium_requirement_value_ext, 0x0,
NULL, HFILL }},
{ &hf_isup_odd_even_indicator,
{ "Odd/even indicator", "isup.isdn_odd_even_indicator",
FT_BOOLEAN, 8, TFS(&isup_odd_even_ind_value), ISUP_ODD_EVEN_MASK,
NULL, HFILL }},
{ &hf_isup_generic_name_presentation,
{ "Presentation indicator", "isup.isdn_generic_name_presentation",
FT_UINT8, BASE_DEC, VALS(isup_generic_name_presentation_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_generic_name_availability,
{ "Availability indicator", "isup.isdn_generic_name_availability",
FT_BOOLEAN, 8, TFS(&isup_generic_name_availability_value), E_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_generic_name_type,
{ "Type indicator", "isup.isdn_generic_name_type",
FT_UINT8, BASE_DEC, VALS(isup_generic_name_type_value), HGF_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_generic_name_ia5,
{ "Generic Name", "isup.isdn_generic_name_ia5",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_called_party_nature_of_address_indicator,
{ "Nature of address indicator", "isup.called_party_nature_of_address_indicator",
FT_UINT8, BASE_DEC, VALS(isup_called_party_nature_of_address_ind_value), ISUP_NATURE_OF_ADDRESS_IND_MASK,
NULL, HFILL }},
{ &hf_isup_calling_party_nature_of_address_indicator,
{ "Nature of address indicator", "isup.calling_party_nature_of_address_indicator",
FT_UINT8, BASE_DEC, VALS(isup_calling_party_nature_of_address_ind_value), ISUP_NATURE_OF_ADDRESS_IND_MASK,
NULL, HFILL }},
{ &hf_isup_charge_number_nature_of_address_indicator,
{ "Nature of address indicator", "isup.charge_number_nature_of_address_indicator",
FT_UINT8, BASE_DEC, VALS(isup_charge_number_nature_of_address_ind_value), ISUP_NATURE_OF_ADDRESS_IND_MASK,
NULL, HFILL }},
{ &hf_isup_inn_indicator,
{ "INN indicator", "isup.inn_indicator",
FT_BOOLEAN, 8, TFS(&isup_INN_ind_value), ISUP_INN_MASK,
NULL, HFILL }},
{ &hf_isup_ni_indicator,
{ "NI indicator", "isup.ni_indicator",
FT_BOOLEAN, 8, TFS(&isup_NI_ind_value), ISUP_NI_MASK,
NULL, HFILL }},
{ &hf_isup_numbering_plan_indicator,
{ "Numbering plan indicator", "isup.numbering_plan_indicator",
FT_UINT8, BASE_DEC, VALS(isup_numbering_plan_ind_value), ISUP_NUMBERING_PLAN_IND_MASK,
NULL, HFILL }},
{ &hf_isup_address_presentation_restricted_indicator,
{ "Address presentation restricted indicator", "isup.address_presentation_restricted_indicator",
FT_UINT8, BASE_DEC, VALS(isup_address_presentation_restricted_ind_value), ISUP_ADDRESS_PRESENTATION_RESTR_IND_MASK,
NULL, HFILL }},
{ &hf_isup_number_different_meaning,
{ "Different meaning for number", "isup.number_different_meaning",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_isup_screening_indicator,
{ "Screening indicator", "isup.screening_indicator",
FT_UINT8, BASE_DEC, VALS(isup_screening_ind_value), ISUP_SCREENING_IND_MASK,
NULL, HFILL }},
{ &hf_isup_screening_indicator_enhanced,
{ "Screening indicator", "isup.screening_indicator_enhanced",
FT_UINT8, BASE_DEC, VALS(isup_screening_ind_enhanced_value), ISUP_SCREENING_IND_MASK,
NULL, HFILL }},
{ &hf_isup_called_party_odd_address_signal_digit,
{ "Address signal digit", "isup.called_party_odd_address_signal_digit",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &isup_called_party_address_digit_value_ext, ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK,
NULL, HFILL }},
{ &hf_isup_calling_party_odd_address_signal_digit,
{ "Address signal digit", "isup.calling_party_odd_address_signal_digit",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &isup_calling_party_address_digit_value_ext, ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK,
NULL, HFILL }},
{ &hf_isup_called_party_even_address_signal_digit,
{ "Address signal digit", "isup.called_party_even_address_signal_digit",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &isup_called_party_address_digit_value_ext, ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK,
NULL, HFILL }},
{ &hf_isup_calling_party_even_address_signal_digit,
{ "Address signal digit", "isup.calling_party_even_address_signal_digit",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &isup_calling_party_address_digit_value_ext, ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK,
NULL, HFILL }},
{ &hf_isup_calling_party_address_request_indicator,
{ "Calling party address request indicator", "isup.calling_party_address_request_indicator",
FT_BOOLEAN, 16, TFS(&isup_calling_party_address_request_ind_value), A_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_info_req_holding_indicator,
{ "Holding indicator", "isup.info_req_holding_indicator",
FT_BOOLEAN, 16, TFS(&isup_holding_ind_value), B_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_calling_partys_category_request_indicator,
{ "Calling party's category request indicator", "isup.calling_partys_category_request_indicator",
FT_BOOLEAN, 16, TFS(&isup_calling_partys_category_request_ind_value), D_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_charge_information_request_indicator,
{ "Charge information request indicator", "isup.charge_information_request_indicator",
FT_BOOLEAN, 16, TFS(&isup_charge_information_request_ind_value), E_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_malicious_call_identification_request_indicator,
{ "Malicious call identification request indicator (ISUP'88)", "isup.malicious_call_ident_request_indicator",
FT_BOOLEAN, 16, TFS(&isup_malicious_call_identification_request_ind_value), H_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_calling_party_address_response_indicator,
{ "Calling party address response indicator", "isup.calling_party_address_response_indicator",
FT_UINT16, BASE_HEX, VALS(isup_calling_party_address_response_ind_value), BA_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_OECD_inf_ind,
{ "OECD information indicator", "isup.OECD_inf_ind_vals",
FT_UINT8, BASE_HEX, VALS(OECD_inf_ind_vals), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_IECD_inf_ind,
{ "IECD information indicator", "isup.IECD_inf_ind_vals",
FT_UINT8, BASE_HEX, VALS(IECD_inf_ind_vals), DC_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_OECD_req_ind,
{ "OECD request indicator", "isup.OECD_req_ind_vals",
FT_UINT8, BASE_HEX, VALS(OECD_req_ind_vals), FE_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_IECD_req_ind,
{ "IECD request indicator", "isup.IECD_req_ind_vals",
FT_UINT8, BASE_HEX, VALS(IECD_req_ind_vals), HG_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_hold_provided_indicator,
{ "Hold provided indicator", "isup.hold_provided_indicator",
FT_BOOLEAN, 16, TFS(&isup_hold_provided_ind_value), C_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_calling_partys_category_response_indicator,
{ "Calling party's category response indicator", "isup.calling_partys_category_response_indicator",
FT_BOOLEAN, 16, TFS(&isup_calling_partys_category_response_ind_value), F_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_charge_information_response_indicator,
{ "Charge information response indicator", "isup.charge_information_response_indicator",
FT_BOOLEAN, 16, TFS(&isup_charge_information_response_ind_value), G_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_solicited_indicator,
{ "Solicited indicator", "isup.solicited_indicator",
FT_BOOLEAN, 16, TFS(&isup_solicited_information_ind_value), H_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_continuity_indicator,
{ "Continuity indicator", "isup.continuity_indicator",
FT_BOOLEAN, 8, TFS(&isup_continuity_ind_value), A_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_backw_call_charge_ind,
{ "Charge indicator", "isup.charge_indicator",
FT_UINT16, BASE_HEX, VALS(isup_charge_ind_value), BA_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_backw_call_called_partys_status_ind,
{ "Called party's status indicator", "isup.called_partys_status_indicator",
FT_UINT16, BASE_HEX, VALS(isup_called_partys_status_ind_value), DC_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_backw_call_called_partys_category_ind,
{ "Called party's category indicator", "isup.called_partys_category_indicator",
FT_UINT16, BASE_HEX, VALS(isup_called_partys_category_ind_value), FE_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_backw_call_end_to_end_method_ind,
{ "End-to-end method indicator", "isup.backw_call_end_to_end_method_indicator",
FT_UINT16, BASE_HEX, VALS(isup_end_to_end_method_ind_value), HG_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_backw_call_interworking_ind,
{ "Interworking indicator", "isup.backw_call_interworking_indicator",
FT_BOOLEAN, 16, TFS(&isup_interworking_ind_value), I_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_backw_call_end_to_end_info_ind,
{ "End-to-end information indicator", "isup.backw_call_end_to_end_information_indicator",
FT_BOOLEAN, 16, TFS(&isup_end_to_end_info_ind_value), J_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_backw_call_isdn_user_part_ind,
{ "ISDN user part indicator", "isup.backw_call_isdn_user_part_indicator",
FT_BOOLEAN, 16, TFS(&isup_ISDN_user_part_ind_value), K_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_backw_call_holding_ind,
{ "Holding indicator", "isup.backw_call_holding_indicator",
FT_BOOLEAN, 16, TFS(&isup_holding_ind_value), L_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_backw_call_isdn_access_ind,
{ "ISDN access indicator", "isup.backw_call_isdn_access_indicator",
FT_BOOLEAN, 16, TFS(&isup_ISDN_terminating_access_ind_value), M_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_backw_call_echo_control_device_ind,
{ "Echo Control Device Indicator", "isup.backw_call_echo_control_device_indicator",
FT_BOOLEAN, 16, TFS(&isup_echo_control_device_ind_value), N_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_backw_call_sccp_method_ind,
{ "SCCP method indicator", "isup.backw_call_sccp_method_indicator",
FT_UINT16, BASE_HEX, VALS(isup_SCCP_method_ind_value), PO_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_cause_indicator,
{ "Cause indicator", "isup.cause_indicator",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &q850_cause_code_vals_ext, 0x7f,
NULL, HFILL }},
{ &hf_ansi_isup_cause_indicator,
{ "Cause indicator", "ansi_isup.cause_indicator",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &ansi_isup_cause_code_vals_ext, 0x7f,
NULL, HFILL }},
{ &hf_isup_suspend_resume_indicator,
{ "Suspend/Resume indicator", "isup.suspend_resume_indicator",
FT_BOOLEAN, 8, TFS(&isup_suspend_resume_ind_value), A_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_range_indicator,
{ "Range indicator", "isup.range_indicator",
FT_UINT8, BASE_DEC, NULL , 0x0,
NULL, HFILL }},
{ &hf_isup_bitbucket,
{ "Bit", "isup.bitbucket",
FT_UINT8, BASE_DEC, NULL , 0x0,
NULL, HFILL }},
{ &hf_isup_cgs_message_type,
{ "Circuit group supervision message type", "isup.cgs_message_type",
FT_UINT8, BASE_DEC, VALS(isup_cgs_message_type_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_mtc_blocking_state1,
{ "Maintenance blocking state", "isup.mtc_blocking_state",
FT_UINT8, BASE_DEC, VALS(isup_mtc_blocking_state_DC00_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_mtc_blocking_state2,
{ "Maintenance blocking state", "isup.mtc_blocking_state",
FT_UINT8, BASE_DEC, VALS(isup_mtc_blocking_state_DCnot00_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_call_proc_state,
{ "Call processing state", "isup.call_processing_state",
FT_UINT8, BASE_DEC, VALS(isup_call_processing_state_value), DC_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_hw_blocking_state,
{ "HW blocking state", "isup.hw_blocking_state",
FT_UINT8, BASE_DEC, VALS(isup_HW_blocking_state_value), FE_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_event_ind,
{ "Event indicator", "isup.event_ind",
FT_UINT8, BASE_DEC, VALS(isup_event_ind_value), GFEDCBA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_event_presentation_restricted_ind,
{ "Event presentation restricted indicator", "isup.event_presentation_restr_ind",
FT_BOOLEAN, 8, TFS(&isup_event_presentation_restricted_ind_value), H_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_cug_call_ind,
{ "Closed user group call indicator", "isup.clg_call_ind",
FT_UINT8, BASE_DEC, VALS(isup_CUG_call_ind_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_simple_segmentation_ind,
{ "Simple segmentation indicator", "isup.simple_segmentation_ind",
FT_BOOLEAN, 8, TFS(&isup_simple_segmentation_ind_value), C_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_connected_line_identity_request_ind,
{ "Connected line identity request indicator", "isup.connected_line_identity_request_ind",
FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), H_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_redirecting_ind,
{ "Redirection indicator", "isup.redirecting_ind",
FT_UINT16, BASE_DEC, VALS(isup_redirecting_ind_value), CBA_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_original_redirection_reason,
{ "Original redirection reason", "isup.original_redirection_reason",
FT_UINT16, BASE_DEC, VALS(isup_original_redirection_reason_value), HGFE_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_redirection_counter,
{ "Redirection counter", "isup.redirection_counter",
FT_UINT16, BASE_DEC, NULL, KJI_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_redirection_reason,
{ "Redirection reason", "isup.redirection_reason",
FT_UINT16, BASE_DEC, VALS(isup_redirection_reason_value), PONM_16BIT_MASK,
NULL, HFILL }},
{ &hf_isup_type_of_network_identification,
{ "Type of network identification", "isup.type_of_network_identification",
FT_UINT8, BASE_DEC, VALS(isup_type_of_network_identification_value), GFE_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_network_identification_plan,
{ "Network identification plan", "isup.network_identification_plan",
FT_UINT8, BASE_DEC, VALS(isup_network_identification_plan_value), DCBA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_map_type,
{ "Map Type", "isup.map_type",
FT_UINT8, BASE_DEC, VALS(isup_map_type_value), FEDCBA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_automatic_congestion_level,
{ "Automatic congestion level", "isup.automatic_congestion_level",
FT_UINT8, BASE_DEC, VALS(isup_auto_congestion_level_value), 0x0,
NULL, HFILL }},
{ &hf_isup_inband_information_ind,
{ "In-band information indicator", "isup.inband_information_ind",
FT_BOOLEAN, 8, TFS(&isup_inband_information_ind_value), A_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_call_diversion_may_occur_ind,
{ "Call diversion may occur indicator", "isup.call_diversion_may_occur_ind",
FT_BOOLEAN, 8, TFS(&isup_call_diversion_may_occur_ind_value), B_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_mlpp_user_ind,
{ "MLPP user indicator", "isup.mlpp_user",
FT_BOOLEAN, 8, TFS(&isup_MLPP_user_ind_value), D_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_UUI_type,
{ "User-to-User indicator type", "isup.UUI_type",
FT_BOOLEAN, 8, TFS(&isup_UUI_type_value), A_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_UUI_req_service1,
{ "User-to-User indicator request service 1", "isup.UUI_req_service1",
FT_UINT8, BASE_DEC, VALS(isup_UUI_request_service_values), CB_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_UUI_req_service2,
{ "User-to-User indicator request service 2", "isup.UUI_req_service2",
FT_UINT8, BASE_DEC, VALS(isup_UUI_request_service_values), ED_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_UUI_req_service3,
{ "User-to-User indicator request service 3", "isup.UUI_req_service3",
FT_UINT8, BASE_DEC, VALS(isup_UUI_request_service_values), GF_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_UUI_res_service1,
{ "User-to-User indicator response service 1", "isup.UUI_res_service1",
FT_UINT8, BASE_DEC, VALS(isup_UUI_response_service_values), CB_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_UUI_res_service2,
{ "User-to-User indicator response service 2", "isup.UUI_res_service2",
FT_UINT8, BASE_DEC, VALS(isup_UUI_response_service_values), ED_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_UUI_res_service3,
{ "User-to-User response service 3", "isup.UUI_res_service3",
FT_UINT8, BASE_DEC, VALS(isup_UUI_response_service_values), GF_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_notification_indicator,
{ "Notification indicator", "isup.notification_indicator",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &q763_generic_notification_indicator_vals_ext, 0x7f,
NULL, HFILL }},
{ &hf_isup_UUI_network_discard_ind,
{ "User-to-User indicator network discard indicator", "isup.UUI_network_discard_ind",
FT_BOOLEAN, 8, TFS(&isup_UUI_network_discard_ind_value), H_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_access_delivery_ind,
{ "Access delivery indicator", "isup.access_delivery_ind",
FT_BOOLEAN, 8, TFS(&isup_access_delivery_ind_value), A_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_transmission_medium_requirement_prime,
{ "Transmission medium requirement prime", "isup.transmission_medium_requirement_prime",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &isup_transmission_medium_requirement_prime_value_ext, 0x0,
NULL, HFILL }},
{ &hf_isup_loop_prevention_response_ind,
{ "Response indicator", "isup.loop_prevention_response_ind",
FT_UINT8, BASE_DEC, VALS(isup_loop_prevention_response_ind_value), CB_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_temporary_alternative_routing_ind,
{ "Temporary alternative routing indicator", "isup.temporary_alternative_routing_ind",
FT_BOOLEAN, 8, TFS(&isup_temporary_alternative_routing_ind_value), A_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_extension_ind,
{ "Extension indicator", "isup.extension_ind",
FT_BOOLEAN, 8, TFS(&isup_extension_ind_value), H_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_call_to_be_diverted_ind,
{ "Call to be diverted indicator", "isup.call_to_be_diverted_ind",
FT_UINT8, BASE_DEC, VALS(isup_call_to_be_diverted_ind_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_call_to_be_offered_ind,
{ "Call to be offered indicator", "isup.call_to_be_offered_ind",
FT_UINT8, BASE_DEC, VALS(isup_call_to_be_offered_ind_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_conference_acceptance_ind,
{ "Conference acceptance indicator", "isup.conference_acceptance_ind",
FT_UINT8, BASE_DEC, VALS(isup_conference_acceptance_ind_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_transit_at_intermediate_exchange_ind,
{ "Transit at intermediate exchange indicator", "isup.transit_at_intermediate_exchange_ind",
FT_BOOLEAN, 8, TFS(&isup_transit_at_intermediate_exchange_ind_value), A_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Release_call_ind,
{ "Release call indicator", "isup.Release_call_ind",
FT_BOOLEAN, 8, TFS(&isup_Release_call_indicator_value), B_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Send_notification_ind,
{ "Send notification indicator", "isup.Send_notification_ind",
FT_BOOLEAN, 8, TFS(&isup_Send_notification_ind_value), C_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Discard_message_ind_value,
{ "Discard message indicator", "isup.Discard_message_ind_value",
FT_BOOLEAN, 8, TFS(&isup_Discard_message_ind_value), D_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Discard_parameter_ind,
{ "Discard parameter indicator", "isup.Discard_parameter_ind",
FT_BOOLEAN, 8, TFS(&isup_Discard_parameter_ind_value), E_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Pass_on_not_possible_indicator,
{ "Pass on not possible indicator", "isup.Pass_on_not_possible_ind",
FT_UINT8, BASE_HEX, VALS(isup_Pass_on_not_possible_indicator_vals), GF_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_pass_on_not_possible_indicator2,
{ "Pass on not possible indicator", "isup.Pass_on_not_possible_val",
FT_BOOLEAN, 8, TFS(&isup_pass_on_not_possible_indicator_value), E_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Broadband_narrowband_interworking_ind,
{ "Broadband narrowband interworking indicator Bits JF", "isup.broadband_narrowband_interworking_ind",
FT_UINT8, BASE_HEX, VALS(ISUP_Broadband_narrowband_interworking_indicator_vals), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Broadband_narrowband_interworking_ind2,
{ "Broadband narrowband interworking indicator Bits GF", "isup.broadband_narrowband_interworking_ind2",
FT_UINT8, BASE_HEX, VALS(ISUP_Broadband_narrowband_interworking_indicator_vals), GF_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_app_cont_ident,
{ "Application context identifier", "isup.app_context_identifier",
FT_UINT16, BASE_DEC, VALS(isup_application_transport_parameter_value), GFEDCBA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_app_Release_call_ind,
{ "Release call indicator (RCI)", "isup.app_Release_call_indicator",
FT_BOOLEAN, 8, TFS(&isup_Release_call_indicator_value), A_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_app_Send_notification_ind,
{ "Send notification indicator (SNI)", "isup.app_Send_notification_ind",
FT_BOOLEAN, 8, TFS(&isup_Send_notification_ind_value), B_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_apm_segmentation_ind,
{ "APM segmentation indicator", "isup.apm_segmentation_ind",
FT_UINT8, BASE_DEC, VALS(isup_APM_segmentation_ind_value), FEDCBA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_apm_si_ind,
{ "Sequence indicator (SI)", "isup.APM_Sequence_ind",
FT_BOOLEAN, 8, TFS(&isup_Sequence_ind_value), G_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_orig_addr_len,
{ "Originating Address length", "isup.orig_addr_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_dest_addr_len,
{ "Destination Address length", "isup.dest_addr_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_apm_slr,
{ "Segmentation local reference (SLR)", "isup.APM_slr",
FT_UINT8, BASE_DEC, NULL, GFEDCBA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_cause_location,
{ "Cause location", "isup.cause_location",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &q931_cause_location_vals_ext, 0x0f,
NULL, HFILL }},
{ &hf_ansi_isup_coding_standard,
{ "Coding standard", "ansi_isup.coding_standard", FT_UINT8, BASE_HEX,
VALS(ansi_isup_coding_standard_vals), 0x60, NULL, HFILL }},
{ &hf_bat_ase_identifier,
{ "BAT ASE Identifiers", "bicc.bat_ase_identifier",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bat_ase_list_of_Identifiers_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_length_indicator,
{ "BAT ASE Element length indicator", "bicc.bat_ase_length_indicator",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_Action_Indicator,
{ "BAT ASE action indicator field", "bicc.bat_ase_bat_ase_action_indicator_field",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bat_ase_action_indicator_field_vals_ext, 0x00,
NULL, HFILL }},
{ &hf_Instruction_ind_for_general_action,
{ "BAT ASE Instruction indicator for general action", "bicc.bat_ase_Instruction_ind_for_general_action",
FT_UINT8, BASE_HEX, VALS(Instruction_indicator_for_general_action_vals), 0x03,
NULL, HFILL }},
{ &hf_Send_notification_ind_for_general_action,
{ "Send notification indicator for general action", "bicc.bat_ase_Send_notification_ind_for_general_action",
FT_BOOLEAN, 8, TFS(&isup_Send_notification_ind_value), 0x04,
NULL, HFILL }},
{ &hf_Instruction_ind_for_pass_on_not_possible,
{ "Instruction ind for pass-on not possible", "bicc.bat_ase_Instruction_ind_for_pass_on_not_possible",
FT_UINT8, BASE_HEX, VALS(Instruction_indicator_for_pass_on_not_possible_vals), 0x30,
NULL, HFILL }},
{ &hf_Send_notification_ind_for_pass_on_not_possible,
{ "Send notification indication for pass-on not possible", "bicc.bat_ase_Send_notification_ind_for_pass_on_not_possible",
FT_BOOLEAN, 8, TFS(&isup_Send_notification_ind_value), 0x40,
NULL, HFILL }},
{ &hf_BCTP_Version_Indicator,
{ "BCTP Version Indicator", "bicc.bat_ase_BCTP_Version_Indicator",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }},
{ &hf_BVEI,
{ "BVEI", "bicc.bat_ase_BCTP_BVEI",
FT_BOOLEAN, 8, TFS(&BCTP_BVEI_value), 0x40,
NULL, HFILL }},
{ &hf_Tunnelled_Protocol_Indicator,
{ "Tunnelled Protocol Indicator", "bicc.bat_ase_BCTP_Tunnelled_Protocol_Indicator",
FT_UINT8, BASE_DEC, VALS(BCTP_Tunnelled_Protocol_Indicator_vals), 0x3f,
NULL, HFILL }},
{ &hf_TPEI,
{ "TPEI", "bicc.bat_ase_BCTP_tpei",
FT_BOOLEAN, 8, TFS(&BCTP_TPEI_value), 0x40,
NULL, HFILL }},
{ &hf_bncid,
{ "Backbone Network Connection Identifier (BNCId)", "bat_ase.bncid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_bat_ase_biwfa,
{ "Interworking Function Address(X.213 NSAP encoded)", "bat_ase.biwfa",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_afi,
{ "X.213 Address Format Information (AFI)", "x213.afi",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &x213_afi_value_ext, 0x0,
NULL, HFILL }},
{ &hf_bicc_nsap_dsp,
{ "X.213 Address Format Information (DSP)", "x213.dsp",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bicc_nsap_dsp_length,
{ "DSP Length", "x213.dsp_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_characteristics,
{ "Backbone network connection characteristics", "bat_ase.char",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bearer_network_connection_characteristics_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_Organization_Identifier,
{ "Organization identifier subfield", "bat_ase.organization_identifier_subfield",
FT_UINT8, BASE_DEC, VALS(bat_ase_organization_identifier_subfield_vals), 0x0,
NULL, HFILL }},
{ &hf_codec_type,
{ "ITU-T codec type subfield", "bat_ase.ITU_T_codec_type_subfield",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ITU_T_codec_type_subfield_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_etsi_codec_type,
{ "ETSI codec type subfield", "bat_ase.ETSI_codec_type_subfield",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ETSI_codec_type_subfield_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_active_code_set,
{ "Active Code Set", "bat_ase.acs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_active_code_set_12_2,
{ "12.2 kbps rate", "bat_ase.acs.12_2",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }},
{ &hf_active_code_set_10_2,
{ "10.2 kbps rate", "bat_ase.acs.10_2",
FT_UINT8, BASE_HEX, NULL, 0x40,
NULL, HFILL }},
{ &hf_active_code_set_7_95,
{ "7.95 kbps rate", "bat_ase.acs.7_95",
FT_UINT8, BASE_HEX, NULL, 0x20,
NULL, HFILL }},
{ &hf_active_code_set_7_40,
{ "7.40 kbps rate", "bat_ase.acs.7_40",
FT_UINT8, BASE_HEX, NULL, 0x10,
NULL, HFILL }},
{ &hf_active_code_set_6_70,
{ "6.70 kbps rate", "bat_ase.acs.6_70",
FT_UINT8, BASE_HEX, NULL, 0x08,
NULL, HFILL }},
{ &hf_active_code_set_5_90,
{ "5.90 kbps rate", "bat_ase.acs.5_90",
FT_UINT8, BASE_HEX, NULL, 0x04,
NULL, HFILL }},
{ &hf_active_code_set_5_15,
{ "5.15 kbps rate", "bat_ase.acs.5_15",
FT_UINT8, BASE_HEX, NULL, 0x02,
NULL, HFILL }},
{ &hf_active_code_set_4_75,
{ "4.75 kbps rate", "bat_ase.acs.4_75",
FT_UINT8, BASE_HEX, NULL, 0x01,
NULL, HFILL }},
{ &hf_supported_code_set,
{ "Supported Code Set", "bat_ase.scs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_supported_code_set_12_2,
{ "12.2 kbps rate", "bat_ase.scs.12_2",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }},
{ &hf_supported_code_set_10_2,
{ "10.2 kbps rate", "bat_ase.scs.10_2",
FT_UINT8, BASE_HEX, NULL, 0x40,
NULL, HFILL }},
{ &hf_supported_code_set_7_95,
{ "7.95 kbps rate", "bat_ase.scs.7_95",
FT_UINT8, BASE_HEX, NULL, 0x20,
NULL, HFILL }},
{ &hf_supported_code_set_7_40,
{ "7.40 kbps rate", "bat_ase.scs.7_40",
FT_UINT8, BASE_HEX, NULL, 0x10,
NULL, HFILL }},
{ &hf_supported_code_set_6_70,
{ "6.70 kbps rate", "bat_ase.scs.6_70",
FT_UINT8, BASE_HEX, NULL, 0x08,
NULL, HFILL }},
{ &hf_supported_code_set_5_90,
{ "5.90 kbps rate", "bat_ase.scs.5_90",
FT_UINT8, BASE_HEX, NULL, 0x04,
NULL, HFILL }},
{ &hf_supported_code_set_5_15,
{ "5.15 kbps rate", "bat_ase.scs.5_15",
FT_UINT8, BASE_HEX, NULL, 0x02,
NULL, HFILL }},
{ &hf_supported_code_set_4_75,
{ "4.75 kbps rate", "bat_ase.scs.4_75",
FT_UINT8, BASE_HEX, NULL, 0x01,
NULL, HFILL }},
{ &hf_optimisation_mode,
{ "Optimisation Mode for ACS , OM", "bat_ase.optimisation_mode",
FT_UINT8, BASE_HEX, VALS(optimisation_mode_vals), 0x8,
NULL, HFILL }},
{ &hf_max_codec_modes,
{ "Maximal number of Codec Modes, MACS", "bat_ase.macs",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }},
{ &hf_bearer_control_tunneling,
{ "Bearer control tunneling", "bat_ase.bearer_control_tunneling",
FT_BOOLEAN, 8, TFS(&Bearer_Control_Tunnelling_ind_value), 0x01,
NULL, HFILL }},
{ &hf_BAT_ASE_Comp_Report_Reason,
{ "Compatibility report reason", "bat_ase.Comp_Report_Reason",
FT_UINT8, BASE_HEX, VALS(BAT_ASE_Report_Reason_vals), 0x0,
NULL, HFILL }},
{ &hf_BAT_ASE_Comp_Report_ident,
{ "Compatibility report ident", "bat_ase.Comp_Report_ident",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bat_ase_list_of_Identifiers_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_BAT_ASE_Comp_Report_diagnostic,
{ "Diagnostics", "bat_ase.Comp_Report_diagnostic",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_Local_BCU_ID,
{ "Local BCU ID", "bat_ase.Local_BCU_ID",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_late_cut_through_cap_ind,
{ "Late Cut-through capability indicator", "bat_ase.late_cut_through_cap_ind",
FT_BOOLEAN, 8, TFS(&late_cut_through_cap_ind_value), 0x01,
NULL, HFILL }},
{ &hf_bat_ase_signal,
{ "Q.765.5 - Signal Type", "bat_ase.signal_type",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &BAT_ASE_Signal_Type_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_bat_ase_duration,
{ "Duration in ms", "bat_ase.signal_type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bat_ase_default,
{ "Default", "bat_ase.default",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bat_ase_bearer_redir_ind,
{ "Redirection Indicator", "bat_ase.bearer_redir_ind",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &Bearer_Redirection_Indicator_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_nsap_ipv4_addr,
{ "IWFA IPv4 Address", "nsap.ipv4_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IPv4 address", HFILL }},
{ &hf_nsap_ipv6_addr,
{ "IWFA IPv6 Address", "nsap.ipv6_addr",
FT_IPv6, BASE_NONE, NULL, 0x0,
"IPv6 address", HFILL}},
{ &hf_iana_icp,
{ "IANA ICP", "nsap.iana_icp",
FT_UINT16, BASE_HEX, VALS(iana_icp_values), 0x0,
NULL, HFILL }},
{ &hf_isup_called,
{ "Called Party Number", "isup.called",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_calling,
{ "Calling Party Number", "isup.calling",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_redirecting,
{ "Redirecting Number", "isup.redirecting",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_redirection_number,
{ "Redirection Number", "isup.redirection_number",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_subsequent_number,
{ "Subsequent Number", "isup.subsequent_number",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_connected_number,
{ "Connected Number", "isup.connected_number",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_transit_network_selection,
{ "Transit Network Selection", "isup.transit_network_selection",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_original_called_number,
{ "Original Called Number", "isup.original_called_number",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_location_number,
{ "Location Number", "isup.location_number",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_call_transfer_number,
{ "Call Transfer Number", "isup.call_transfer_number",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_called_in_number,
{ "Called IN Number", "isup.called_in_number",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_generic_number,
{ "Generic Number", "isup.generic_number",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_jurisdiction,
{ "Jurisdiction", "isup.jurisdiction",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_charge_number,
{ "Charge Number", "isup.charge_number",
FT_STRING, ENC_ASCII, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_apm_msg_fragments,
{ "Message fragments", "isup.apm.msg.fragments",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isup_apm_msg_fragment,
{ "Message fragment", "isup.apm.msg.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isup_apm_msg_fragment_overlap,
{ "Message fragment overlap", "isup.apm.msg.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_apm_msg_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data", "isup.apm.msg.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_apm_msg_fragment_multiple_tails,
{ "Message has multiple tail fragments", "isup.apm.msg.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_apm_msg_fragment_too_long_fragment,
{ "Message fragment too long", "isup.apm.msg.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_apm_msg_fragment_error,
{ "Message defragmentation error", "isup.apm.msg.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isup_apm_msg_fragment_count,
{ "Message fragment count", "isup.apm.msg.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_isup_apm_msg_reassembled_in,
{ "Reassembled in", "isup.apm.msg.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_isup_apm_msg_reassembled_length,
{ "Reassembled ISUP length", "isup.apm.msg.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_isup_cvr_rsp_ind,
{ "CVR Response Ind", "isup.conn_rsp_ind",
FT_UINT8, BASE_DEC, VALS(isup_cvr_rsp_ind_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_cvr_cg_car_ind,
{ "CVR Circuit Group Carrier", "isup.cg_carrier_ind",
FT_UINT8, BASE_HEX, VALS(isup_cvr_cg_car_ind_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_cvr_cg_double_seize,
{ "Double Seize Control", "isup.cg_char_ind.doubleSeize",
FT_UINT8, BASE_HEX, VALS(isup_cvr_cg_double_seize_value), DC_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_cvr_cg_alarm_car_ind,
{ "Alarm Carrier Indicator", "isup.cg_alarm_car_ind",
FT_UINT8, BASE_HEX, VALS(isup_cvr_alarm_car_ind_value), FE_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_cvr_cont_chk_ind,
{ "Continuity Check Indicator", "isup.cg_alarm_cnt_chk",
FT_UINT8, BASE_HEX, VALS(isup_cvr_cont_chk_ind_value), HG_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_geo_loc_presentation_restricted_ind,
{ "Calling Geodetic Location presentation restricted indicator", "isup.location_presentation_restr_ind",
FT_UINT8, BASE_DEC, VALS(isup_location_presentation_restricted_ind_value), DC_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_geo_loc_screening_ind,
{ "Calling Geodetic Location screening indicator", "isup.location_screening_ind",
FT_UINT8, BASE_DEC, VALS(isup_screening_ind_enhanced_value), BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_french_coll_field,
{ "Collection field", "isup.french.coll_field",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_french_msg_num,
{ "Message number", "isup.french.msg_num",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_israeli_charging_message_indicators_current,
{ "Current Tariff", "isup.israeli.cmi_current",
FT_UINT8, BASE_DEC, VALS(israeli_cmi_current_rate), 0x03,
NULL, HFILL }},
{ &hf_isup_israeli_charging_message_indicators_next,
{ "Next Tariff", "isup.israeli.cmi_next",
FT_UINT8, BASE_DEC, VALS(israeli_cmi_next_rate), 0x0C,
NULL, HFILL }},
{ &hf_isup_israeli_current_rate,
{ "Current Rate", "isup.israeli.current_rate",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_israeli_time_indicator,
{ "Time Indicator", "isup.israeli.time_indicator",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &israeli_time_indicators_ext, 0x0,
NULL, HFILL }},
{ &hf_isup_israeli_next_rate,
{ "Next Rate", "isup.israeli.next_ratej",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_redirect_capability,
{ "Redirect possible indicator", "isup.jpn.redirect_capability",
FT_UINT8, BASE_DEC, VALS(isup_jpn_redirect_capabilit_vals), 0x07,
NULL, HFILL }},
{ &hf_japan_isup_redirect_counter,
{ "Redirect counter", "isup.jpn.redirect_counter",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }},
{ &hf_japan_isup_rfi_info_type,
{ "Information Type Tag", "isup.rfi.info_type",
FT_UINT8, BASE_DEC, VALS(isup_rfi_info_type_values), 0x0,
NULL, HFILL }},
{ &hf_japan_isup_rfi_info_len,
{ "Length", "isup.rfi.info_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_perf_redir_reason,
{ "Performing redirect reason", "isup.rfi.perf_redir_reason",
FT_UINT8, BASE_DEC, VALS(perf_redir_reason_vals), 0x7f,
NULL, HFILL }},
{ &hf_japan_isup_redir_pos_ind,
{ "Redirect possible indicator at performing exchange", "isup.rfi.redir_pos_ind",
FT_UINT8, BASE_DEC, VALS(redir_pos_ind_vals), 0x07,
NULL, HFILL }},
{ &hf_japan_isup_emerg_call_type,
{ "Emergency Call Type", "isup.jpn.emerg_call_type",
FT_UINT8, BASE_DEC, VALS(japan_isup_emerg_call_type_vals), 0x03,
NULL, HFILL }},
{ &hf_japan_isup_hold_at_emerg_call_disc_ind,
{ "Hold at emergency Call Disconnection Indicators", "isup.jpn.hold_at_emerg_call_disc_ind",
FT_UINT16, BASE_DEC, VALS(hold_at_emerg_call_disc_ind_vals), 0x0300,
NULL, HFILL }},
{ &hf_japan_isup_inv_redir_reason,
{ "Invoking redirect reason", "isup.rfi.inv_redir_reason",
FT_UINT8, BASE_DEC, VALS(perf_redir_reason_vals), 0x7f,
NULL, HFILL }},
{ &hf_japan_isup_bwd_info_type,
{ "Information Type Tag", "isup.jpn.bwd_info_type",
FT_UINT8, BASE_DEC, VALS(japan_isup_bwd_info_type_vals), 0x0,
NULL, HFILL }},
{ &hf_japan_isup_tag_len,
{ "Length", "isup.jpn.tag_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_add_user_cat_type,
{ "Type of Additional User/Service Information", "isup.jpn.add_user_cat_type",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(jpn_isup_add_user_cat_type_vals), 0x0,
NULL, HFILL }},
{ &hf_japan_isup_type_1_add_fixed_serv_inf,
{ "Type 1 of additional fixed service information", "isup.jpn.type_1_add_fixed_serv_inf",
FT_UINT8, BASE_DEC, VALS(jpn_isup_type_1_add_fixed_serv_inf_vals), 0x0,
NULL, HFILL }},
{ &hf_japan_isup_type_1_add_mobile_serv_inf,
{ "Type 1 of additional mobile service information", "isup.jpn.type_1_add_mobile_serv_inf",
FT_UINT8, BASE_DEC, VALS(jpn_isup_type_1_add_mobile_serv_inf_vals), 0x0,
NULL, HFILL }},
{ &hf_japan_isup_type_2_add_mobile_serv_inf,
{ "Type 2 of additional mobile service information (Communication Method)", "isup.jpn.type_2_add_mobile_serv_inf",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &jpn_isup_type_2_add_mobile_serv_inf_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_type_3_add_mobile_serv_inf,
{ "Type 3 of additional mobile service information (Charging Method)", "isup.jpn.type_3_add_mobile_serv_inf",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_reason_for_clip_fail,
{ "Reason for CLIP failure", "isup.jpn.reason_for_clip_fail",
FT_UINT8, BASE_DEC, VALS(jpn_isup_reason_for_clip_fail_vals), 0x0,
NULL, HFILL }},
{ &hf_japan_isup_contractor_number,
{ "Contractor Number", "isup.jpn.contractor_number",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_charge_area_nat_of_info_value,
{ "Nature of Information indicator", "isup.charg_area_info.oddeven_indic",
FT_UINT8, BASE_DEC, VALS(isup_charge_area_info_nat_of_info_value), 0x7F,
NULL, HFILL }},
{ &hf_japan_isup_charging_info_nc_odd_digits,
{ "NC", "isup.charg_area_info.nc_odd_digit",
FT_UINT8, BASE_DEC, VALS(isup_carrier_info_digits_value), 0x0F,
NULL, HFILL }},
{ &hf_japan_isup_charging_info_nc_even_digits,
{ "NC", "isup.charg_area_info.nc_even_digit",
FT_UINT8, BASE_DEC, VALS(isup_carrier_info_digits_value), 0xF0,
NULL, HFILL }},
{ &hf_isup_charging_info_maca_odd_digits,
{ "MA/CA", "isup.charg_area_info.maca_odd_digit",
FT_UINT8, BASE_DEC, VALS(isup_carrier_info_digits_value), 0x0F,
NULL, HFILL }},
{ &hf_isup_charging_info_maca_even_digits,
{ "MA/CA", "isup.charg_area_info.maca_even_digit",
FT_UINT8, BASE_DEC, VALS(isup_carrier_info_digits_value), 0xF0,
NULL, HFILL }},
{ &hf_isup_carrier_info_iec,
{ "IEC Indicator", "isup.carrier_info.iec",
FT_UINT8, BASE_DEC, VALS(isup_carrier_info_iec_indic_value), 0x00,
NULL, HFILL }},
#if 0
{ &hf_isup_carrier_info_cat_of_carrier,
{ "Category of Carrier", "isup.carrier_info.cat_of_carrier",
FT_UINT8, BASE_HEX, VALS(isup_carrier_info_category_value), 0x00,
NULL, HFILL }},
{ &hf_isup_carrier_info_type_of_carrier_info,
{ "Type of Carrier", "isup.carrier_info.type_of_carrier",
FT_UINT8, BASE_HEX, VALS(isup_carrier_info_type_of_carrier_value), 0x00,
NULL, HFILL }},
#endif
{ &hf_japan_isup_carrier_info_length,
{ "Length of Carrier Information", "isup.jpn.arrier_info_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_carrier_info_odd_no_digits,
{ "CID", "isup.carrier_info.cid_odd_digit",
FT_UINT8, BASE_DEC, VALS(isup_carrier_info_digits_value), 0x0F,
NULL, HFILL }},
{ &hf_isup_carrier_info_even_no_digits,
{ "CID", "isup.carrier_info.cid_even_digit",
FT_UINT8, BASE_DEC, VALS(isup_carrier_info_digits_value), 0xF0,
NULL, HFILL }},
{ &hf_isup_carrier_info_ca_odd_no_digits,
{ "CA", "isup.carrier_info.ca_odd_digit",
FT_UINT8, BASE_DEC, VALS(isup_carrier_info_digits_value), 0x0F,
NULL, HFILL }},
{ &hf_isup_carrier_info_ca_even_no_digits,
{ "CA", "isup.carrier_info.ca_even_digit",
FT_UINT8, BASE_DEC, VALS(isup_carrier_info_digits_value), 0xF0,
NULL, HFILL }},
{ &hf_isup_carrier_info_poi_exit_HEI,
{ "Exit POI Hierarchy", "isup.carrier_info_exit_hierarchy",
FT_UINT8, BASE_DEC, VALS(isup_carrier_info_poihie_value), 0x0F,
NULL, HFILL }},
{ &hf_isup_carrier_info_poi_entry_HEI,
{ "Entry POI Hierarchy", "isup.carrier_info_entry_hierarchy",
FT_UINT8, BASE_DEC, VALS(isup_carrier_info_poihie_value), 0xF0,
NULL, HFILL }},
{ &hf_japan_isup_charge_delay_type,
{ "Type of delayed charging information", "isup.japan.charge_delay_type",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(japan_isup_charge_delay_type_value), 0x0,
NULL, HFILL }},
{ &hf_japan_isup_charge_info_type,
{ "Charge information type", "isup.japan.chg_inf_type",
FT_UINT8, BASE_DEC, VALS(japan_isup_chg_info_type_value), 0x0,
NULL, HFILL }},
{ &hf_japan_isup_sig_elem_type,
{ "Signal element type", "isup.japan.sig_elem_type",
FT_UINT8, BASE_DEC, VALS(japan_isup_sig_elem_type_values), 0x7f,
NULL, HFILL }},
{ &hf_japan_isup_activation_id,
{ "Activation id", "isup.japan.activation_id",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }},
{ &hf_japan_isup_op_cls,
{ "Operation class", "isup.japan.op_cls",
FT_UINT8, BASE_DEC, VALS(japan_isup_op_cls_values), 0x60,
NULL, HFILL }},
{ &hf_japan_isup_op_type,
{ "Operation type", "isup.japan.op_type",
FT_UINT8, BASE_DEC, VALS(japan_isup_op_type_values), 0x1f,
NULL, HFILL }},
{ &hf_japan_isup_charging_party_type,
{ "Charging party type", "isup.japan.charging_party_type",
FT_UINT8, BASE_DEC, VALS(japan_isup_charging_party_type_values), 0x70,
NULL, HFILL }},
{ &hf_japan_isup_utp,
{ "Unit per Time Period (UTP)", "isup.japan.utp",
FT_UINT8, BASE_DEC, VALS(japan_isup_utp_values), 0x0,
NULL, HFILL }},
{ &hf_japan_isup_crci1,
{ "Charge rate information category 1 (CRIC 1)", "isup.japan.crci1",
FT_UINT8, BASE_DEC, VALS(japan_isup_crci1_values), 0x7f,
NULL, HFILL }},
{ &hf_japan_isup_crci2,
{ "Charge rate information category 2 (CRIC 2)", "isup.japan.crci2",
FT_UINT8, BASE_DEC, VALS(japan_isup_crci1_values), 0x7f,
NULL, HFILL }},
{ &hf_japan_isup_crci1_len,
{ "Length", "isup.japan.crci1_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_iu,
{ "Initial units (IU)", "isup.japan.iu",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_dcr,
{ "Daytime Charge rate (DCR)", "isup.japan.dcr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_ecr,
{ "Evening Charge rate (ECR)", "isup.japan.ecr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_ncr,
{ "Nighttime Charge rate (NCR)", "isup.japan.ncr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_scr,
{ "Spare charge rate (SCR)", "isup.japan.scr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_japan_isup_collecting_metod,
{ "Charging party type", "isup.japan.collecting_metod",
FT_UINT8, BASE_DEC, VALS(japan_isup_collecting_metod_values), 0x0f,
NULL, HFILL }},
{ &hf_japan_isup_tariff_rate_pres,
{ "Tariff rate presentation", "isup.japan.tariff_rate_pres",
FT_UINT8, BASE_DEC, VALS(japan_isup_tariff_rate_pres_values), 0x7f,
NULL, HFILL }},
{ &hf_isup_cause_indicators, { "Cause indicators (-> Q.850)", "isup.cause_indicators", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_diagnostic, { "Diagnostic", "isup.diagnostic", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_user_to_user_info, { "User-to-user info (-> Q.931)", "isup.user_to_user_info", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_call_identity, { "Call identity", "isup.call_identity", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_signalling_point_code, { "Signalling Point Code", "isup.signalling_point_code", FT_UINT16, BASE_DEC, NULL, 0x3FFF, NULL, HFILL }},
{ &hf_isup_access_transport_parameter_field, { "Access transport parameter field (-> Q.931)", "isup.access_transport_parameter_field", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_idp, { "IDP", "isup.idp", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_dsp, { "DSP", "isup.dsp", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_idi, { "IDI", "isup.idi", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_configuration_data, { "Configuration data", "isup.configuration_data", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_unknown_organisation_identifier, { "Unknown organisation Identifier (Non ITU-T/ETSI codec)", "isup.unknown_organisation_identifier", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_tunnelled_protocol_data, { "Tunnelled Protocol Data", "isup.tunnelled_protocol_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_network_id_length_indicator, { "Network ID Length indicator", "isup.network_id_length_indicator", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_network_id, { "Network ID", "isup.network_id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_app_transport_param_field8, { "Application transport parameter fields", "isup.app_transport_param_field", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_app_transport_param_field16, { "Application transport parameter fields", "isup.app_transport_param_field", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_app_transport_instruction_indicator, { "Application transport instruction indicators", "isup.app_transport_instruction_indicator", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_apm_seg_indicator, { "APM segmentation indicator", "isup.apm_seg_indicator", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_address_digits, { "Address digits", "isup.address_digits", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_apm_user_info_field, { "APM-user information field", "isup.apm_user_info_field", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_local_reference, { "Local Reference", "isup.local_reference", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_protocol_class, { "Protocol Class", "isup.protocol_class", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_credit, { "Credit", "isup.credit", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_network_identity, { "Network Identity", "isup.network_identity", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_binary_code, { "Binary Code", "isup.binary_code", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_user_service_information, { "User service information (-> Q.931 Bearer_capability)", "isup.user_service_information", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_circuit_assignment_map, { "Circuit assignment map (bit position indicates usage of corresponding circuit->3.69/Q.763)", "isup.circuit_assignment_map", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_origination_isc_point_code, { "Origination ISC Point Code", "isup.origination_isc_point_code", FT_UINT16, BASE_DEC, NULL, 0x3FFF, NULL, HFILL }},
{ &hf_isup_call_history_info, { "Call history info", "isup.call_history_info", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_network_specific_facility, { "Network specific facility (refer to 3.36/Q.763 for detailed decoding)", "isup.network_specific_facility", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_user_service_information_prime, { "User service information prime (-> Q.931 Bearer capability information IE)", "isup.user_service_information_prime", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_propagation_delay_counter, { "Propagation delay counter", "isup.propagation_delay_counter", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_remote_operations, { "Remote operations", "isup.remote_operations", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_feature_code, { "Feature Code", "isup.feature_code", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_user_teleservice_information, { "User teleservice information (-> Q.931 High Layer Compatibility IE)", "isup.user_teleservice_information", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_call_diversion_information, { "Call diversion information", "isup.call_diversion_information", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_echo_control_information, { "Echo control information", "isup.echo_control_information", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_message_compatibility_information, { "Message compatibility information", "isup.message_compatibility_information", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_upgraded_parameter, { "Upgraded parameter", "isup.upgraded_parameter", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &isup_parameter_type_value_ext, 0x0, NULL, HFILL }},
{ &hf_isup_instruction_indicators, { "Instruction indicators", "isup.instruction_indicators", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_look_forward_busy, { "Look forward busy", "isup.look_forward_busy", FT_UINT8, BASE_DEC, VALS(isup_mlpp_precedence_look_forward_busy_vals), 0x60, NULL, HFILL }},
{ &hf_isup_precedence_level, { "Precedence Level", "isup.precedence_level", FT_UINT8, BASE_DEC, VALS(isup_mlpp_precedence_level_vals), 0x0F, NULL, HFILL }},
{ &hf_isup_mlpp_service_domain, { "MLPP service domain", "isup.mlpp_service_domain", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_mcid_request_indicators, { "MCID request indicators", "isup.mcid_request_indicators", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_mcid_response_indicators, { "MCID response indicators", "isup.mcid_response_indicators", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_hop_counter, { "Hop counter", "isup.hop_counter", FT_UINT8, BASE_DEC, NULL, EDCBA_8BIT_MASK, NULL, HFILL }},
{ &hf_isup_originating_line_info, { "Originating line info", "isup.originating_line_info", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_presentation_indicator, { "Presentation indicator", "isup.presentation_indicator", FT_UINT8, BASE_DEC, VALS(isup_redirection_presentation_indicator_vals), BA_8BIT_MASK, NULL, HFILL }},
{ &hf_isup_call_transfer_identity, { "Call transfer identity", "isup.call_transfer_identity", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_loop_prevention_indicator_type, { "Type", "isup.loop_prevention_indicator_type", FT_BOOLEAN, 8, TFS(&tfs_response_request), A_8BIT_MASK, NULL, HFILL }},
{ &hf_isup_ccss_call_indicator, { "CCSS call indicator", "isup.ccss_call_indicator", FT_BOOLEAN, 8, TFS(&tfs_ccss_call_no_indication), A_8BIT_MASK, NULL, HFILL }},
{ &hf_isup_forward_gvns, { "Forward GVNS (refer to 3.66/Q.763 for detailed decoding)", "isup.forward_gvns", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_redirect_capability, { "Redirect capability", "isup.redirect_capability", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_backward_gvns, { "Backward GVNS", "isup.backward_gvns", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_correlation_id, { "Correlation ID (-> Q.1281)", "isup.correlation_id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_scf_id, { "SCF ID (-> Q.1281)", "isup.scf_id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_charged_party_identification, { "Charged party identification (format is national network specific)", "isup.charged_party_identification", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_display_information, { "Display information (-> Q.931)", "isup.display_information", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_uid_action_indicators, { "UID action indicators", "isup.uid_action_indicators", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_uid_capability_indicators, { "UID capability indicators", "isup.uid_capability_indicators", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_redirect_counter, { "Redirect counter", "isup.redirect_counter", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_collect_call_request_indicator, { "Collect call request indicator", "isup.collect_call_request_indicator", FT_BOOLEAN, 8, TFS(&tfs_collect_call_req_no_indication), A_8BIT_MASK, NULL, HFILL }},
{ &hf_isup_geo_loc_shape, { "Calling geodetic location type of shape", "isup.geo_loc_shape", FT_UINT8, BASE_DEC, VALS(isup_location_type_of_shape_value), GFEDCBA_8BIT_MASK, NULL, HFILL }},
{ &hf_isup_geo_loc_shape_description, { "Shape description", "isup.shape_description", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isup_number_qualifier_indicator, { "Number qualifier indicator", "isup.number_qualifier_indicator", FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(number_qualifier_indicator_vals), 0x0, NULL, HFILL }},
{ &hf_isup_generic_digits, { "Generic digits (refer to 3.24/Q.673 for detailed decoding)", "isup.generic_digits", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_isup,
&ett_isup_parameter,
&ett_isup_address_digits,
&ett_isup_carrier_info,
&ett_isup_pass_along_message,
&ett_isup_circuit_state_ind,
&ett_bat_ase,
&ett_bat_ase_element,
&ett_bat_ase_iwfa,
&ett_scs,
&ett_acs,
&ett_isup_apm_msg_fragment,
&ett_isup_apm_msg_fragments,
&ett_isup_range,
&ett_app_transport_fields,
&ett_app_transport,
&ett_apm_seg_indicator,
&ett_echo_control_information,
&ett_instruction_indicators,
&ett_message_compatibility_information,
};
static ei_register_info ei[] = {
{ &ei_isup_format_national_matter, { "isup.format_national_matter", PI_PROTOCOL, PI_NOTE, "Format is a national matter", EXPFILL }},
{ &ei_isup_message_type_unknown, { "isup.message_type.unknown", PI_PROTOCOL, PI_WARN, "Unknown Message type (possibly reserved/used in former ISUP version)", EXPFILL }},
{ &ei_isup_not_dissected_yet, { "isup.not_dissected_yet", PI_UNDECODED, PI_WARN, "Not dissected yet", EXPFILL }},
{ &ei_isup_status_subfield_not_present, { "isup.status_subfield_not_present", PI_PROTOCOL, PI_NOTE, "Status subfield is not present with this message type", EXPFILL }},
{ &ei_isup_message_type_no_optional_parameters, { "isup.message_type.no_optional_parameters", PI_PROTOCOL, PI_NOTE, "No optional parameters are possible with this message type", EXPFILL }},
{ &ei_isup_empty_number, { "isup.empty_number", PI_PROTOCOL, PI_NOTE, "(empty) number", EXPFILL }},
{ &ei_isup_too_many_digits, { "isup.too_many_digits", PI_MALFORMED, PI_ERROR, "Too many digits", EXPFILL }}
};
static const enum_val_t isup_variants[] = {
{"ITU Standard", "ITU Standard", ISUP_ITU_STANDARD_VARIANT},
{"French National Standard", "French National Standard", ISUP_FRENCH_VARIANT},
{"Israeli National Standard", "Israeli National Standard", ISUP_ISRAELI_VARIANT},
{"Russian National Standard", "Russian National Standard", ISUP_RUSSIAN_VARIANT},
{"Japan National Standard", "Japan National Standard", ISUP_JAPAN_VARIANT},
{"Japan National Standard (TTC)", "Japan National Standard (TTC)", ISUP_JAPAN_TTC_VARIANT},
{NULL, NULL, -1}
};
module_t *isup_module;
expert_module_t* expert_isup;
proto_isup = proto_register_protocol("ISDN User Part",
"ISUP", "isup");
isup_handle = register_dissector("isup", dissect_isup, proto_isup);
proto_register_field_array(proto_isup, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_isup = expert_register_protocol(proto_isup);
expert_register_field_array(expert_isup, ei, array_length(ei));
isup_tap = register_tap("isup");
isup_module = prefs_register_protocol(proto_isup, NULL);
prefs_register_enum_preference(isup_module, "variant",
"Select Standard or national ISUP variant",
"Note national variants may not be fully supported",
&g_isup_variant, isup_variants, FALSE);
prefs_register_bool_preference(isup_module, "show_cic_in_info", "Show CIC in Info column",
"Show the CIC value (in addition to the message type) in the Info column",
(gint *)&isup_show_cic_in_info);
prefs_register_bool_preference(isup_module, "defragment_apm",
"Reassemble APM messages",
"Whether APM messages datagrams should be reassembled",
&isup_apm_desegment);
stats_tree_register_with_group("isup", "isup_msg", "_ISUP Messages",
0, msg_stats_tree_packet, msg_stats_tree_init,
NULL, REGISTER_STAT_GROUP_TELEPHONY);
}
void
proto_reg_handoff_isup(void)
{
dissector_handle_t application_isup_handle;
application_isup_handle = create_dissector_handle(dissect_application_isup, proto_isup);
dissector_add_uint("mtp3.service_indicator", MTP_SI_ISUP, isup_handle);
dissector_add_string("media_type", "application/isup", application_isup_handle);
dissector_add_string("tali.opcode", "isot", isup_handle);
}
void
proto_register_bicc(void)
{
static hf_register_info hf[] = {
{ &hf_bicc_cic,
{ "Call identification Code (CIC)", "bicc.cic",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_bicc
};
proto_bicc = proto_register_protocol("Bearer Independent Call Control",
"BICC", "bicc");
bicc_handle = register_dissector("bicc", dissect_bicc, proto_bicc);
proto_register_field_array(proto_bicc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(isup_apm_defragment_init);
register_cleanup_routine(isup_apm_defragment_cleanup);
}
void
proto_reg_handoff_bicc(void)
{
sdp_handle = find_dissector_add_dependency("sdp", proto_isup);
q931_ie_handle = find_dissector_add_dependency("q931.ie", proto_isup);
dissector_add_uint("mtp3.service_indicator", MTP_SI_BICC, bicc_handle);
dissector_add_uint("sctp.ppi", BICC_PAYLOAD_PROTOCOL_ID, bicc_handle);
}
