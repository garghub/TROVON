static void
isup_apm_defragment_init(void)
{
fragment_table_init (&isup_apm_msg_fragment_table);
reassembled_table_init(&isup_apm_msg_reassembled_table);
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
nature_of_connection_ind = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_satellite_indicator, parameter_tvb, 0,NATURE_OF_CONNECTION_IND_LENGTH, nature_of_connection_ind);
proto_tree_add_uint(parameter_tree, hf_isup_continuity_check_indicator, parameter_tvb, 0,NATURE_OF_CONNECTION_IND_LENGTH, nature_of_connection_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_echo_control_device_indicator, parameter_tvb, 0, NATURE_OF_CONNECTION_IND_LENGTH, nature_of_connection_ind);
proto_item_set_text(parameter_item, "Nature of Connection Indicators: 0x%x", nature_of_connection_ind);
}
static void
dissect_isup_forward_call_indicators_parameter(tvbuff_t *parameter_tvb,proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 forward_call_ind;
forward_call_ind = tvb_get_ntohs(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_forw_call_natnl_inatnl_call_indicator, parameter_tvb, 0, FORWARD_CALL_IND_LENGTH, forward_call_ind);
proto_tree_add_uint(parameter_tree, hf_isup_forw_call_end_to_end_method_indicator, parameter_tvb, 0, FORWARD_CALL_IND_LENGTH, forward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_forw_call_interworking_indicator, parameter_tvb, 0, FORWARD_CALL_IND_LENGTH, forward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_forw_call_end_to_end_info_indicator, parameter_tvb, 0, FORWARD_CALL_IND_LENGTH, forward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_forw_call_isdn_user_part_indicator, parameter_tvb, 0, FORWARD_CALL_IND_LENGTH, forward_call_ind);
proto_tree_add_uint(parameter_tree, hf_isup_forw_call_preferences_indicator, parameter_tvb, 0, FORWARD_CALL_IND_LENGTH, forward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_forw_call_isdn_access_indicator, parameter_tvb, 0, FORWARD_CALL_IND_LENGTH, forward_call_ind);
proto_tree_add_uint(parameter_tree, hf_isup_forw_call_sccp_method_indicator, parameter_tvb, 0, FORWARD_CALL_IND_LENGTH, forward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_forw_call_ported_num_trans_indicator, parameter_tvb, 0, FORWARD_CALL_IND_LENGTH, forward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_forw_call_qor_attempt_indicator, parameter_tvb, 0, FORWARD_CALL_IND_LENGTH, forward_call_ind);
proto_item_set_text(parameter_item, "Forward Call Indicators: 0x%x", forward_call_ind);
}
static void
dissect_isup_calling_partys_category_parameter(tvbuff_t *parameter_tvb,proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 calling_partys_category;
calling_partys_category = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_calling_partys_category, parameter_tvb, 0, CALLING_PRTYS_CATEGORY_LENGTH, calling_partys_category);
proto_item_set_text(parameter_item, "Calling Party's category: 0x%x (%s)", calling_partys_category, val_to_str_ext_const(calling_partys_category, &isup_calling_partys_category_value_ext, "reserved/spare"));
}
static void
dissect_isup_transmission_medium_requirement_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 transmission_medium_requirement;
transmission_medium_requirement = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_transmission_medium_requirement, parameter_tvb, 0, TRANSMISSION_MEDIUM_REQUIREMENT_LENGTH,transmission_medium_requirement);
proto_item_set_text(parameter_item, "Transmission medium requirement: %u (%s)", transmission_medium_requirement, val_to_str_ext_const(transmission_medium_requirement, &isup_transmission_medium_requirement_value_ext, "spare"));
}
void
dissect_isup_called_party_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
proto_item *hidden_item;
guint8 indicators1, indicators2;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char called_number[MAXDIGITS + 1]="";
e164_info_t e164_info;
gint number_plan;
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_called_party_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
number_plan = (indicators2 & 0x70)>> 4;
proto_tree_add_boolean(parameter_tree, hf_isup_inn_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, indicators2);
offset = 2;
if (tvb_reported_length_remaining(parameter_tvb, offset) == 0) {
proto_tree_add_text(parameter_tree, parameter_tvb, offset, 0, "Called Number (empty)");
proto_item_set_text(parameter_item, "Called Number: (empty)");
return;
}
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1, "Called Party Number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
while((length = tvb_reported_length_remaining(parameter_tvb, offset)) > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
called_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
called_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
called_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
called_number[i++] = '\0';
proto_item_set_text(address_digits_item, "Called Party Number: %s", called_number);
proto_item_set_text(parameter_item, "Called Party Number: %s", called_number);
if (number_plan == 1) {
e164_info.e164_number_type = CALLED_PARTY_NUMBER;
e164_info.nature_of_address = indicators1 & 0x7f;
e164_info.E164_number_str = called_number;
e164_info.E164_number_length = i - 1;
dissect_e164_number(parameter_tvb, address_digits_tree, 2, (offset - 2), e164_info);
hidden_item = proto_tree_add_string(address_digits_tree, hf_isup_called, parameter_tvb,
offset - length, length, called_number);
PROTO_ITEM_SET_HIDDEN(hidden_item);
} else {
proto_tree_add_string(address_digits_tree, hf_isup_called, parameter_tvb,
offset - length, length, called_number);
}
tap_called_number = ep_strdup(called_number);
}
static void
dissect_isup_subsequent_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 indicators1;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char called_number[MAXDIGITS + 1]="";
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
offset = 1;
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Subsequent Number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
while((length = tvb_reported_length_remaining(parameter_tvb, offset)) > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
called_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
called_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
called_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
called_number[i] = '\0';
proto_item_set_text(address_digits_item, "Subsequent Number: %s", called_number);
proto_item_set_text(parameter_item, "Subsequent Number: %s", called_number);
}
static void
dissect_isup_information_request_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 information_request_indicators;
information_request_indicators = tvb_get_ntohs(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_calling_party_address_request_indicator, parameter_tvb, 0, INFO_REQUEST_IND_LENGTH, information_request_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_info_req_holding_indicator, parameter_tvb, 0, INFO_REQUEST_IND_LENGTH, information_request_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_calling_partys_category_request_indicator, parameter_tvb, 0, INFO_REQUEST_IND_LENGTH, information_request_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_charge_information_request_indicator, parameter_tvb, 0, INFO_REQUEST_IND_LENGTH, information_request_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_malicious_call_identification_request_indicator, parameter_tvb, 0, INFO_REQUEST_IND_LENGTH, information_request_indicators);
proto_item_set_text(parameter_item, "Information request indicators: 0x%x", information_request_indicators);
}
static void
dissect_isup_information_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 information_indicators;
information_indicators = tvb_get_ntohs(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_calling_party_address_response_indicator, parameter_tvb, 0, INFO_IND_LENGTH, information_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_hold_provided_indicator, parameter_tvb, 0, INFO_IND_LENGTH, information_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_calling_partys_category_response_indicator, parameter_tvb, 0, INFO_IND_LENGTH, information_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_charge_information_response_indicator, parameter_tvb, 0, INFO_IND_LENGTH, information_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_solicited_indicator, parameter_tvb, 0, INFO_IND_LENGTH, information_indicators);
proto_item_set_text(parameter_item, "Information indicators: 0x%x", information_indicators);
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
dissect_isup_backward_call_indicators_parameter(tvbuff_t *parameter_tvb,proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 backward_call_ind;
backward_call_ind = tvb_get_ntohs(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_backw_call_charge_ind, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, backward_call_ind);
proto_tree_add_uint(parameter_tree, hf_isup_backw_call_called_partys_status_ind, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, backward_call_ind);
proto_tree_add_uint(parameter_tree, hf_isup_backw_call_called_partys_category_ind, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, backward_call_ind);
proto_tree_add_uint(parameter_tree, hf_isup_backw_call_end_to_end_method_ind, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, backward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_backw_call_interworking_ind, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, backward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_backw_call_end_to_end_info_ind, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, backward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_backw_call_isdn_user_part_ind, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, backward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_backw_call_holding_ind, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, backward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_backw_call_isdn_access_ind, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, backward_call_ind);
proto_tree_add_boolean(parameter_tree, hf_isup_backw_call_echo_control_device_ind, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, backward_call_ind);
proto_tree_add_uint(parameter_tree, hf_isup_backw_call_sccp_method_ind, parameter_tvb, 0, BACKWARD_CALL_IND_LENGTH, backward_call_ind);
proto_item_set_text(parameter_item, "Backward Call Indicators: 0x%x", backward_call_ind);
}
void
dissect_isup_cause_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb,0, -1, "Cause indicators (-> Q.850)");
dissect_q931_cause_ie(parameter_tvb,0,length,
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
offset ++;
length--;
if (length == 0)
return;
proto_tree_add_item(parameter_tree, hf_isup_cause_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
cause_value=tvb_get_guint8(parameter_tvb, offset)&0x7f;
offset ++;
length--;
proto_item_set_text(parameter_item, "Cause indicators: %s (%u)", val_to_str_ext_const(cause_value, &q850_cause_code_vals_ext, "spare"),cause_value);
if (length == 0) {
return;
}
proto_tree_add_text(parameter_tree, parameter_tvb, offset,
length, "Diagnostic: %s",
tvb_bytes_to_str(parameter_tvb, offset, length));
return;
case 2:
proto_tree_add_item(parameter_tree, hf_isup_cause_location, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_ansi_isup_coding_standard, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
length--;
if (length == 0)
return;
proto_tree_add_item(parameter_tree, hf_ansi_isup_cause_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
cause_value=tvb_get_guint8(parameter_tvb, offset)&0x7f;
proto_item_set_text(parameter_item, "Cause indicators: %s (%u)",
val_to_str_ext_const(cause_value, &ansi_isup_cause_code_vals_ext, "spare"),
cause_value);
offset ++;
length--;
if (length == 0) {
return;
}
proto_tree_add_text(parameter_tree, parameter_tvb, offset,
length, "Diagnostic: %s",
tvb_bytes_to_str(parameter_tvb, offset, length));
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
dissect_isup_range_and_status_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 range, actual_status_length;
range = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint_format(parameter_tree, hf_isup_range_indicator, parameter_tvb, 0, RANGE_LENGTH, range, "Range: %u", range);
actual_status_length = tvb_reported_length_remaining(parameter_tvb, RANGE_LENGTH);
if (actual_status_length > 0)
proto_tree_add_text(parameter_tree, parameter_tvb , RANGE_LENGTH, -1, "Status subfield");
else
proto_tree_add_text(parameter_tree, parameter_tvb , 0, 0, "Status subfield is not present with this message type");
proto_item_set_text(parameter_item, "Range (%u) and status", range);
}
static void
dissect_isup_circuit_group_supervision_message_type_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 cgs_message_type;
cgs_message_type = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_cgs_message_type, parameter_tvb, 0, CIRC_GRP_SV_MSG_TYPE_LENGTH, cgs_message_type);
proto_item_set_text(parameter_item, "Circuit group supervision message type: %s (%u)" ,val_to_str(cgs_message_type, isup_cgs_message_type_value,"unknown"), cgs_message_type);
}
static void
dissect_isup_facility_ind_parameter(tvbuff_t *parameter_tvb, proto_item *parameter_item)
{
guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_item_set_text(parameter_item, "Facility indicator: %s (%u)" ,val_to_str(indicator, isup_facility_ind_value,"spare"), indicator);
}
static void
dissect_isup_circuit_state_ind_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *circuit_state_item;
proto_tree *circuit_state_tree;
guint8 circuit_state;
gint offset=0;
gint i=0;
while(tvb_reported_length_remaining(parameter_tvb, offset) > 0) {
circuit_state_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Circuit# CIC+%u state", i);
circuit_state_tree = proto_item_add_subtree(circuit_state_item, ett_isup_circuit_state_ind);
circuit_state = tvb_get_guint8(parameter_tvb, offset);
if ((circuit_state & DC_8BIT_MASK) == 0) {
proto_tree_add_uint(circuit_state_tree, hf_isup_mtc_blocking_state1, parameter_tvb, offset, 1, circuit_state);
proto_item_set_text(circuit_state_item, "Circuit# CIC+%u state: %s", i++, val_to_str(circuit_state&BA_8BIT_MASK, isup_mtc_blocking_state_DC00_value, "unknown"));
}
else {
proto_tree_add_uint(circuit_state_tree, hf_isup_mtc_blocking_state2, parameter_tvb, offset, 1, circuit_state);
proto_tree_add_uint(circuit_state_tree, hf_isup_call_proc_state, parameter_tvb, offset, 1, circuit_state);
proto_tree_add_uint(circuit_state_tree, hf_isup_hw_blocking_state, parameter_tvb, offset, 1, circuit_state);
proto_item_set_text(circuit_state_item, "Circuit# CIC+%u state: %s", i++, val_to_str(circuit_state&BA_8BIT_MASK, isup_mtc_blocking_state_DCnot00_value, "unknown"));
}
offset++;
}
proto_item_set_text(parameter_item, "Circuit state indicator (national use)");
}
static void
dissect_isup_event_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators;
indicators = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint_format(parameter_tree, hf_isup_event_ind, parameter_tvb, 0, EVENT_INFO_LENGTH, indicators, "Event indicator: %s (%u)", val_to_str(indicators & GFEDCBA_8BIT_MASK, isup_event_ind_value, "spare"), indicators & GFEDCBA_8BIT_MASK);
proto_tree_add_boolean(parameter_tree, hf_isup_event_presentation_restricted_ind, parameter_tvb, 0, EVENT_INFO_LENGTH, indicators);
proto_item_set_text(parameter_item,"Event information: %s (%u)", val_to_str(indicators & GFEDCBA_8BIT_MASK, isup_event_ind_value, "spare"),indicators);
}
static void
dissect_isup_user_to_user_information_parameter(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, -1,
"User-to-user info (-> Q.931)");
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
proto_tree_add_text(parameter_tree, parameter_tvb, 0, CALL_ID_LENGTH, "Call identity: %u", call_id);
proto_tree_add_text(parameter_tree, parameter_tvb, CALL_ID_LENGTH, SPC_LENGTH, "Signalling Point Code: %u", spc);
proto_item_set_text(parameter_item, "Call Reference: Call ID = %u, SPC = %u", call_id, spc);
}
static void
dissect_isup_access_transport_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree,
proto_item *parameter_item, packet_info *pinfo)
{ guint length = tvb_reported_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, -1,
"Access transport parameter field (-> Q.931)");
if (q931_ie_handle)
call_dissector(q931_ie_handle, parameter_tvb, pinfo, parameter_tree);
proto_item_set_text(parameter_item, "Access transport (%u byte%s length)",
length , plurality(length, "", "s"));
}
void
dissect_nsap(tvbuff_t *parameter_tvb,gint offset,gint len, proto_tree *parameter_tree)
{
guint8 afi;
guint8 length = 0;
guint icp, cc_offset;
afi = tvb_get_guint8(parameter_tvb, offset);
switch (afi) {
case 0x35:
proto_tree_add_text(parameter_tree, parameter_tvb, offset, 3,
"IDP = %s", tvb_bytes_to_str(parameter_tvb, offset, 3));
proto_tree_add_uint(parameter_tree, hf_afi, parameter_tvb, offset, 1, afi);
offset = offset + 1;
icp = tvb_get_ntohs(parameter_tvb, offset);
proto_tree_add_uint(parameter_tree, hf_iana_icp, parameter_tvb, offset, 1, icp);
if (icp == 0) {
proto_tree_add_text(parameter_tree, parameter_tvb, offset + 2 , 17,
"DSP = %s", tvb_bytes_to_str(parameter_tvb, offset + 2, 17));
proto_tree_add_item(parameter_tree, hf_nsap_ipv6_addr, parameter_tvb, offset + 2,
16, ENC_NA);
}
else {
proto_tree_add_text(parameter_tree, parameter_tvb, offset + 2, 17,
"DSP = %s", tvb_bytes_to_str(parameter_tvb, offset + 2, 17));
proto_tree_add_item(parameter_tree, hf_nsap_ipv4_addr, parameter_tvb, offset + 2, 4, ENC_BIG_ENDIAN);
}
break;
case 0x45:
case 0xC3:
proto_tree_add_text(parameter_tree, parameter_tvb, offset, 9,
"IDP = %s", tvb_bytes_to_str(parameter_tvb, offset, 9));
proto_tree_add_uint(parameter_tree, hf_afi, parameter_tvb, offset, 1, afi);
proto_tree_add_text(parameter_tree, parameter_tvb, offset + 1, 8,
"IDI = %s", tvb_bytes_to_str(parameter_tvb, offset + 1, 8));
offset = offset +1;
cc_offset = offset;
dissect_e164_cc(parameter_tvb, parameter_tree, 3, TRUE);
proto_tree_add_text(parameter_tree,parameter_tvb, cc_offset, length,"DSP length %u(len %u -9)",(len-9),len);
proto_tree_add_item(parameter_tree, hf_bicc_nsap_dsp, parameter_tvb, offset + 8, (len - 9),ENC_NA);
break;
default:
proto_tree_add_uint(parameter_tree, hf_afi, parameter_tvb, offset, len, afi);
}
}
extern int dissect_codec_mode(proto_tree *tree, tvbuff_t *tvb, int offset, int len) {
guint8 tempdata;
proto_tree *scs_item, *acs_item;
proto_tree *scs_tree, *acs_tree;
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
tempdata = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "Configuration data : 0x%x", tempdata);
offset = offset + 1;
}
break;
case G_728 :
case G_729_CS_ACELP :
case G_729_Annex_B :
if (len > 2) {
tempdata = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1 , "Configuration data : 0x%x", tempdata);
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
acs_item = proto_tree_add_item(tree, hf_active_code_set, tvb, offset, 1, ENC_LITTLE_ENDIAN);
acs_tree = proto_item_add_subtree(acs_item,ett_acs);
proto_tree_add_item(acs_tree, hf_active_code_set_12_2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(acs_tree, hf_active_code_set_10_2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(acs_tree, hf_active_code_set_7_95, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(acs_tree, hf_active_code_set_7_40, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(acs_tree, hf_active_code_set_6_70, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(acs_tree, hf_active_code_set_5_90, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(acs_tree, hf_active_code_set_5_15, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(acs_tree, hf_active_code_set_4_75, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
if (len > 3) {
offset = offset + 1;
scs_item = proto_tree_add_item(tree, hf_supported_code_set, tvb, offset, 1, ENC_LITTLE_ENDIAN);
scs_tree = proto_item_add_subtree(scs_item,ett_scs);
proto_tree_add_item(scs_tree, hf_supported_code_set_12_2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(scs_tree, hf_supported_code_set_10_2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(scs_tree, hf_supported_code_set_7_95, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(scs_tree, hf_supported_code_set_7_40, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(scs_tree, hf_supported_code_set_6_70, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(scs_tree, hf_supported_code_set_5_90, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(scs_tree, hf_supported_code_set_5_15, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(scs_tree, hf_supported_code_set_4_75, tvb, offset, 1, ENC_LITTLE_ENDIAN);
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
tempdata = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, len ,
"Unknown organisation Identifier (Non ITU-T/ETSI codec) %u", tempdata);
offset = offset + len - 1;
break;
}
return offset;
}
static int
dissect_codec(tvbuff_t *parameter_tvb, proto_tree *bat_ase_element_tree, gint length_indicator, gint offset,gint identifier)
{
guint8 compatibility_info;
proto_tree_add_uint(bat_ase_element_tree , hf_bat_ase_identifier , parameter_tvb, offset - 1, 1, identifier);
proto_tree_add_uint(bat_ase_element_tree , hf_length_indicator , parameter_tvb, offset, 1, length_indicator);
offset = offset + 1;
compatibility_info = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(bat_ase_element_tree, hf_Instruction_ind_for_general_action , parameter_tvb, offset, 1, compatibility_info);
proto_tree_add_boolean(bat_ase_element_tree, hf_Send_notification_ind_for_general_action , parameter_tvb, offset, 1, compatibility_info);
proto_tree_add_uint(bat_ase_element_tree, hf_Instruction_ind_for_pass_on_not_possible , parameter_tvb, offset, 1, compatibility_info);
proto_tree_add_boolean(bat_ase_element_tree, hf_Send_notification_ind_for_pass_on_not_possible , parameter_tvb, offset, 1, compatibility_info);
proto_tree_add_boolean(bat_ase_element_tree, hf_isup_extension_ind , parameter_tvb, offset, 1, compatibility_info);
offset = dissect_codec_mode(bat_ase_element_tree, parameter_tvb, offset+1,length_indicator-1);
return offset;
}
static void
dissect_bat_ase_Encapsulated_Application_Information(tvbuff_t *parameter_tvb, packet_info *pinfo, proto_tree *parameter_tree, gint offset)
{
gint length = tvb_reported_length_remaining(parameter_tvb, offset), list_end;
tvbuff_t *next_tvb;
proto_tree *bat_ase_tree, *bat_ase_element_tree, *bat_ase_iwfa_tree;
proto_item *bat_ase_item, *bat_ase_element_item, *bat_ase_iwfa_item;
guint8 identifier,content, BCTP_Indicator_field_1, BCTP_Indicator_field_2;
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
bat_ase_item = proto_tree_add_text(parameter_tree,parameter_tvb, offset, -1,
"Bearer Association Transport (BAT) Application Service Element (ASE) Encapsulated Application Information:");
bat_ase_tree = proto_item_add_subtree(bat_ase_item , ett_bat_ase);
proto_tree_add_text(bat_ase_tree, parameter_tvb, offset, -1,
"BAT ASE Encapsulated Application Information, (%u byte%s length)", length, plurality(length, "", "s"));
while(tvb_reported_length_remaining(parameter_tvb, offset) > 0) {
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
bat_ase_element_item = proto_tree_add_text(bat_ase_tree,parameter_tvb,
(offset - length_ind_len),(length_indicator + 2),"BAT ASE Element %u, Identifier: %s",element_no,
val_to_str_ext(identifier,&bat_ase_list_of_Identifiers_vals_ext,"unknown (%u)"));
bat_ase_element_tree = proto_item_add_subtree(bat_ase_element_item ,
ett_bat_ase_element);
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
val_to_str_ext(content,&bat_ase_action_indicator_field_vals_ext, "unknown (%u)"));
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
proto_item_append_text(bat_ase_element_item, " - 0x%08x",bncid);
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
val_to_str_ext(tempdata,&bearer_network_connection_characteristics_vals_ext, "unknown (%u)"));
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
if(sdp_length > tvb_length_remaining(parameter_tvb,offset)) {
next_tvb = tvb_new_subset_remaining(parameter_tvb, offset);
} else {
next_tvb = tvb_new_subset(parameter_tvb, offset, sdp_length, sdp_length);
}
call_dissector(sdp_handle, next_tvb, pinfo, bat_ase_element_tree);
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
proto_tree_add_text(bat_ase_element_tree, parameter_tvb, offset, 1, "Network ID Length indicator = %u",tempdata);
offset = offset + 1;
if (tempdata > 0) {
proto_tree_add_text(bat_ase_element_tree, parameter_tvb, offset, tempdata , "Network ID: %s",
tvb_bytes_to_str(parameter_tvb, offset, tempdata));
offset = offset + tempdata;
}
Local_BCU_ID = tvb_get_letohl(parameter_tvb, offset);
proto_tree_add_uint_format(bat_ase_element_tree, hf_Local_BCU_ID , parameter_tvb, offset, 4, Local_BCU_ID , "Local BCU ID : 0x%08x", Local_BCU_ID);
offset = offset + 4;
break;
case SIGNAL :
break;
case BEARER_REDIRECTION_CAPABILITY :
tempdata = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_boolean(bat_ase_element_tree, hf_late_cut_trough_cap_ind , parameter_tvb, offset, 1, tempdata);
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
proto_tree_add_text(bat_ase_element_tree, parameter_tvb, offset,content_len , "Default ?, (%u byte%s length)", (content_len), plurality(content_len, "", "s"));
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
tvbuff_t* new_tvb = NULL;
tvbuff_t* next_tvb = NULL;
fragment_data *frag_msg = NULL;
proto_tree_add_text(parameter_tree, parameter_tvb, offset, -1, "Application transport parameter fields:");
proto_item_set_text(parameter_item, "Application transport, (%u byte%s length)", length , plurality(length, "", "s"));
aci16 = tvb_get_guint8(parameter_tvb, offset);
if ((aci16 & H_8BIT_MASK) == 0x80) {
aci16 = aci16 & 0x7f;
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(parameter_tree, hf_isup_app_cont_ident , parameter_tvb, offset, 1, aci16);
offset = offset + 1;
}
else {
aci16 = (aci16<<8) | (tvb_get_guint8(parameter_tvb, offset) & 0x7f);
proto_tree_add_uint(parameter_tree, hf_isup_app_cont_ident , parameter_tvb, offset, 2, aci16);
offset = offset + 2;
}
proto_tree_add_text(parameter_tree, parameter_tvb, offset, -1, "Application transport instruction indicators: ");
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_app_Send_notification_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_app_Release_call_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset = offset + 1;
proto_tree_add_text(parameter_tree, parameter_tvb, offset, 1, "APM segmentation indicator:");
si_and_apm_seg_ind = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_apm_si_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_apm_segmentation_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset = offset + 1;
if ((si_and_apm_seg_ind & H_8BIT_MASK) == 0x00) {
apm_Segmentation_local_ref = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_item(parameter_tree, hf_isup_extension_ind, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_apm_slr, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset = offset + 1;
}
if (aci16 > 3) {
octet = tvb_get_guint8(parameter_tvb,offset);
proto_tree_add_item(parameter_tree, hf_isup_orig_addr_len, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (octet != 0) {
proto_tree_add_item(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(parameter_tree, hf_isup_inn_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_text(parameter_tree, parameter_tvb, offset, octet - 2, "Address digits");
offset = offset + octet - 2;
}
octet = tvb_get_guint8(parameter_tvb,offset);
proto_tree_add_item(parameter_tree, hf_isup_dest_addr_len, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (octet != 0) {
proto_tree_add_item(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(parameter_tree, hf_isup_inn_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_text(parameter_tree, parameter_tvb, offset, octet - 2, "Address digits");
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
frag_msg = fragment_add_seq_next(parameter_tvb, offset, pinfo,
(apm_Segmentation_local_ref & 0x7f),
isup_apm_msg_fragment_table,
isup_apm_msg_reassembled_table,
tvb_length_remaining(parameter_tvb, offset),
more_frag);
if ((si_and_apm_seg_ind & 0x3f) !=0 && (si_and_apm_seg_ind &0x40) !=0) {
fragment_set_tot_len(pinfo, apm_Segmentation_local_ref & 0x7f, isup_apm_msg_fragment_table, (si_and_apm_seg_ind & 0x3f));
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
proto_tree_add_text(parameter_tree, parameter_tvb, offset, 0, "Empty APM-user information field");
return;
}
if (new_tvb) {
next_tvb = new_tvb;
} else {
next_tvb = tvb_new_subset_remaining(parameter_tvb, offset);
}
proto_tree_add_text(parameter_tree, parameter_tvb, offset, -1,
"APM-user information field (%u Bytes)",tvb_length_remaining(parameter_tvb, offset));
switch(aci16 & 0x7fff) {
case 3:
dissect_charging_ase_ChargingMessageType_PDU(next_tvb, pinfo, parameter_tree);
break;
case 5:
dissect_bat_ase_Encapsulated_Application_Information(next_tvb, pinfo, parameter_tree, 0);
break;
default:
proto_tree_add_text(parameter_tree, parameter_tvb, offset, -1, "No further dissection of APM-user information field");
break;
}
}
static void
dissect_isup_optional_forward_call_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators;
indicators = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_cug_call_ind, parameter_tvb, 0, OPTIONAL_FORWARD_CALL_IND_LENGTH, indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_simple_segmentation_ind, parameter_tvb, 0, OPTIONAL_FORWARD_CALL_IND_LENGTH, indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_connected_line_identity_request_ind, parameter_tvb, 0, OPTIONAL_FORWARD_CALL_IND_LENGTH, indicators);
proto_item_set_text(parameter_item,"Optional forward call indicators: %s (%u)", val_to_str(indicators & BA_8BIT_MASK, isup_CUG_call_ind_value, "spare"), indicators);
}
void
dissect_isup_calling_party_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
proto_item *hidden_item;
guint8 indicators1, indicators2;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char calling_number[MAXDIGITS + 1]="";
e164_info_t e164_info;
gint number_plan;
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_calling_party_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
number_plan = (indicators2 & 0x70)>> 4;
proto_tree_add_boolean(parameter_tree, hf_isup_ni_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_address_presentation_restricted_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_screening_indicator, parameter_tvb, 1, 1, indicators2);
offset = 2;
length = tvb_length_remaining(parameter_tvb, offset);
if (length == 0) {
proto_tree_add_text(parameter_tree, parameter_tvb, offset, 0, "Calling Number (empty)");
proto_item_set_text(parameter_item, "Calling Number: (empty)");
return;
}
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Calling Party Number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
while(length > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
length = tvb_length_remaining(parameter_tvb, offset);
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
proto_item_set_text(address_digits_item, "Calling Party Number: %s", calling_number);
calling_number[i++] = '\0';
if (number_plan == 1) {
e164_info.e164_number_type = CALLING_PARTY_NUMBER;
e164_info.nature_of_address = indicators1 & 0x7f;
e164_info.E164_number_str = calling_number;
e164_info.E164_number_length = i - 1;
dissect_e164_number(parameter_tvb, address_digits_tree, 2, (offset - 2), e164_info);
hidden_item = proto_tree_add_string(address_digits_tree, hf_isup_calling, parameter_tvb,
offset - length, length, calling_number);
PROTO_ITEM_SET_HIDDEN(hidden_item);
} else {
proto_tree_add_string(address_digits_tree, hf_isup_calling, parameter_tvb,
offset - length, length, calling_number);
}
proto_item_set_text(parameter_item, "Calling Party Number: %s", calling_number);
tap_calling_number = ep_strdup(calling_number);
}
void
dissect_isup_original_called_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 indicators1, indicators2;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char calling_number[MAXDIGITS + 1]="";
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_calling_party_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_address_presentation_restricted_indicator, parameter_tvb, 1, 1, indicators2);
offset = 2;
length = tvb_length_remaining(parameter_tvb, offset);
if (length == 0) {
proto_tree_add_text(parameter_tree, parameter_tvb, offset, 0, "Original Called Number (empty)");
proto_item_set_text(parameter_item, "Original Called Number: (empty)");
return;
}
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Original Called Number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
length = tvb_length_remaining(parameter_tvb, offset);
while(length > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
length = tvb_length_remaining(parameter_tvb, offset);
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
calling_number[i] = '\0';
proto_item_set_text(address_digits_item, "Original Called Number: %s", calling_number);
proto_item_set_text(parameter_item, "Original Called Number: %s", calling_number);
}
void
dissect_isup_redirecting_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 indicators1, indicators2;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char calling_number[MAXDIGITS + 1]="";
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_calling_party_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_address_presentation_restricted_indicator, parameter_tvb, 1, 1, indicators2);
offset = 2;
length = tvb_length_remaining(parameter_tvb, offset);
if (length == 0) {
proto_tree_add_text(parameter_tree, parameter_tvb, offset, 0, "Redirecting Number (empty)");
proto_item_set_text(parameter_item, "Redirecting Number: (empty)");
return;
}
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Redirecting Number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
length = tvb_length_remaining(parameter_tvb, offset);
while(length > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
length = tvb_length_remaining(parameter_tvb, offset);
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
calling_number[i] = '\0';
proto_item_set_text(address_digits_item, "Redirecting Number: %s", calling_number);
proto_tree_add_string(address_digits_tree, hf_isup_redirecting, parameter_tvb, offset - length, length, calling_number);
proto_item_set_text(parameter_item, "Redirecting Number: %s", calling_number);
}
static void
dissect_isup_redirection_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 indicators1, indicators2;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char called_number[MAXDIGITS + 1]="";
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_called_party_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
proto_tree_add_boolean(parameter_tree, hf_isup_inn_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, indicators2);
offset = 2;
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Redirection Number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
length = tvb_length_remaining(parameter_tvb, offset);
while(length > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
called_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
called_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
length = tvb_length_remaining(parameter_tvb, offset);
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
called_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
called_number[i] = '\0';
proto_item_set_text(address_digits_item, "Redirection Number: %s", called_number);
proto_item_set_text(parameter_item, "Redirection Number: %s", called_number);
}
static void
dissect_isup_connection_request_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint32 local_ref;
guint16 spc;
guint8 protocol_class, credit, offset=0;
local_ref = tvb_get_ntoh24(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, offset, LOCAL_REF_LENGTH, "Local Reference: %u", local_ref);
offset = LOCAL_REF_LENGTH;
spc = tvb_get_letohs(parameter_tvb,offset) & 0x3FFF;
proto_tree_add_text(parameter_tree, parameter_tvb, offset, SPC_LENGTH, "Signalling Point Code: %u", spc);
offset += SPC_LENGTH;
protocol_class = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_text(parameter_tree, parameter_tvb, offset, PROTOCOL_CLASS_LENGTH, "Protocol Class: %u", protocol_class);
offset += PROTOCOL_CLASS_LENGTH;
credit = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_text(parameter_tree, parameter_tvb, offset, CREDIT_LENGTH, "Credit: %u", credit);
proto_item_set_text(parameter_item, "Connection request: Local Reference = %u, SPC = %u, Protocol Class = %u, Credit = %u", local_ref, spc, protocol_class, credit);
}
void
dissect_isup_redirection_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
if (tvb_length(parameter_tvb) == 2) {
guint16 indicators;
indicators = tvb_get_ntohs(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_redirecting_ind, parameter_tvb,0 , REDIRECTION_INFO_LENGTH, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_original_redirection_reason, parameter_tvb,0 , REDIRECTION_INFO_LENGTH, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_redirection_counter, parameter_tvb,0 , REDIRECTION_INFO_LENGTH, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_redirection_reason, parameter_tvb,0 , REDIRECTION_INFO_LENGTH, indicators);
proto_item_set_text(parameter_item, "Redirection Information");
}
else {
guint16 indicators;
indicators = tvb_get_guint8(parameter_tvb, 0) * 0x100;
proto_tree_add_uint(parameter_tree, hf_isup_redirecting_ind, parameter_tvb, 0, 1, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_original_redirection_reason, parameter_tvb,0 , 1, indicators);
proto_item_set_text(parameter_item, "Redirection Information (2nd octet not present since ISUP '88)");
}
}
static void
dissect_isup_closed_user_group_interlock_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
char NI_digits[5]="";
guint8 digit_pair;
guint16 bin_code;
digit_pair = tvb_get_guint8(parameter_tvb, 0);
NI_digits[0] = number_to_char((digit_pair & HGFE_8BIT_MASK) / 0x10);
NI_digits[1] = number_to_char(digit_pair & DCBA_8BIT_MASK);
digit_pair = tvb_get_guint8(parameter_tvb, 1);
NI_digits[2] = number_to_char((digit_pair & HGFE_8BIT_MASK) / 0x10);
NI_digits[3] = number_to_char(digit_pair & DCBA_8BIT_MASK);
NI_digits[4] = '\0';
proto_tree_add_text(parameter_tree, parameter_tvb, 0, 2, "Network Identity: %s", NI_digits);
bin_code = tvb_get_ntohs(parameter_tvb, 2);
proto_tree_add_text(parameter_tree, parameter_tvb, 3, 2, "Binary Code: 0x%x", bin_code);
proto_item_set_text(parameter_item, "Closed user group interlock code: NI = %s, Binary code = 0x%x", NI_digits, bin_code);
}
static void
dissect_isup_user_service_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length,
"User service information (-> Q.931 Bearer_capability)");
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
proto_tree_add_text(parameter_tree, parameter_tvb, 0, SIGNALLING_POINT_CODE_LENGTH, "Signalling Point Code: %u", spc);
proto_item_set_text(parameter_item, "Signalling point code: %u", spc);
}
static void
dissect_isup_connected_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 indicators1, indicators2;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char calling_number[MAXDIGITS + 1]="";
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_calling_party_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_address_presentation_restricted_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_screening_indicator, parameter_tvb, 1, 1, indicators2);
offset = 2;
length = tvb_length_remaining(parameter_tvb, offset);
if (length == 0)
return;
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Connected Number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
while(length > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
length = tvb_length_remaining(parameter_tvb, offset);
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
calling_number[i] = '\0';
proto_item_set_text(address_digits_item, "Connected Number: %s", calling_number);
proto_item_set_text(parameter_item, "Connected Number: %s", calling_number);
}
static void
dissect_isup_transit_network_selection_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 indicators;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char network_id[MAXDIGITS + 1]="";
indicators = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_type_of_network_identification, parameter_tvb, 0, 1, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_network_identification_plan, parameter_tvb, 0, 1, indicators);
offset = 1;
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Network identification");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
length = tvb_length_remaining(parameter_tvb, offset);
while(length > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
network_id[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
network_id[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
length = tvb_length_remaining(parameter_tvb, offset);
}
if (((indicators & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
network_id[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
network_id[i++] = '\0';
proto_item_set_text(address_digits_item, "Network identification: %s", network_id);
proto_item_set_text(parameter_item, "Transit network selection: %s", network_id);
}
static void
dissect_isup_circuit_assignment_map_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 map_type;
map_type = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_map_type, parameter_tvb, 0, 1, map_type);
proto_tree_add_text(parameter_tree, parameter_tvb, 1, 5, "Circuit assignment map (bit position indicates usage of corresponding circuit->3.69/Q.763)");
proto_item_set_text(parameter_item, "Circuit assignment map");
}
static void
dissect_isup_automatic_congestion_level_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 congestion_level;
congestion_level = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_automatic_congestion_level, parameter_tvb, 0, AUTO_CONGEST_LEVEL_LENGTH, congestion_level);
proto_item_set_text(parameter_item, "Automatic congestion level: %s (%u)", val_to_str(congestion_level, isup_auto_congestion_level_value, "spare"), congestion_level);
}
static void
dissect_isup_optional_backward_call_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators;
indicators = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_inband_information_ind, parameter_tvb, 0, OPTIONAL_BACKWARD_CALL_IND_LENGTH, indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_call_diversion_may_occur_ind, parameter_tvb, 0, OPTIONAL_BACKWARD_CALL_IND_LENGTH, indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_simple_segmentation_ind, parameter_tvb, 0, OPTIONAL_BACKWARD_CALL_IND_LENGTH, indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_mlpp_user_ind, parameter_tvb, 0, OPTIONAL_BACKWARD_CALL_IND_LENGTH, indicators);
proto_item_set_text(parameter_item,"Optional backward call indicators: 0x%x", indicators);
}
static void
dissect_isup_user_to_user_indicators_parameter(tvbuff_t *parameter_tvb,
proto_tree *parameter_tree,
proto_item *parameter_item)
{
guint8 indicators;
indicators = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_UUI_type, parameter_tvb, 0, 1, indicators);
if ((indicators & 0x01) == 0) {
proto_tree_add_uint(parameter_tree, hf_isup_UUI_req_service1, parameter_tvb, 0, 1, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_UUI_req_service2, parameter_tvb, 0, 1, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_UUI_req_service3, parameter_tvb, 0, 1, indicators);
}
else {
proto_tree_add_uint(parameter_tree, hf_isup_UUI_res_service1, parameter_tvb, 0, 1, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_UUI_res_service2, parameter_tvb, 0, 1, indicators);
proto_tree_add_uint(parameter_tree, hf_isup_UUI_res_service3, parameter_tvb, 0, 1, indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_UUI_network_discard_ind, parameter_tvb, 0, 1, indicators);
}
proto_item_set_text(parameter_item,"User-to-user indicators: 0x%x", indicators);
}
static void
dissect_isup_original_isc_point_code_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 spc;
spc = tvb_get_letohs(parameter_tvb, 0) & 0x3FFF;
proto_tree_add_text(parameter_tree, parameter_tvb, 0, ORIGINAL_ISC_POINT_CODE_LENGTH, "Origination ISC Point Code: %u", spc);
proto_item_set_text(parameter_item, "Origination ISC point code: %u", spc);
}
static void
dissect_isup_generic_notification_indicator_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicators;
indicators = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, GENERIC_NOTIFICATION_IND_LENGTH, "Generic notification indicator: 0x%x (refer to 3.25/Q.763 for detailed decoding)", indicators);
proto_item_set_text(parameter_item,"Generic notification indicator: 0x%x", indicators);
}
static void
dissect_isup_call_history_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint16 info;
info = tvb_get_ntohs(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, CALL_HISTORY_INFO_LENGTH, "Call history info: propagation delay = %u ms", info);
proto_item_set_text(parameter_item,"Call history info: propagation delay = %u ms", info);
}
static void
dissect_isup_access_delivery_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_access_delivery_ind, parameter_tvb, 0, ACCESS_DELIVERY_INFO_LENGTH, indicator);
proto_item_set_text(parameter_item, "Access delivery information: 0x%x", indicator);
}
static void
dissect_isup_network_specific_facility_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length, "Network specific facility (refer to 3.36/Q.763 for detailed decoding)");
proto_item_set_text(parameter_item, "Network specific facility (%u byte%s length)", length , plurality(length, "", "s"));
}
static void
dissect_isup_user_service_information_prime_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length,
"User service information prime (-> Q.931 Bearer capability information IE)");
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
proto_tree_add_text(parameter_tree, parameter_tvb, 0, PROPAGATION_DELAY_COUNT_LENGTH, "Propagation delay counter = %u ms", info);
proto_item_set_text(parameter_item,"Propagation delay counter = %u ms", info);
}
static void
dissect_isup_remote_operations_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length, "Remote operations");
proto_item_set_text(parameter_item, "Remote operations (%u byte%s length)", length , plurality(length, "", "s"));
}
static void
dissect_isup_service_activation_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint i;
guint8 feature_code;
guint length = tvb_length(parameter_tvb);
for (i=0; i< length; i++) {
feature_code = tvb_get_guint8(parameter_tvb, i);
proto_tree_add_text(parameter_tree, parameter_tvb, i, 1, "Feature Code %u: %u", i+1, feature_code);
}
proto_item_set_text(parameter_item, "Service Activation (%u byte%s length)", length , plurality(length, "", "s"));
}
static void
dissect_isup_user_teleservice_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length,
"User teleservice information (-> Q.931 High Layer Compatibility IE)");
dissect_q931_high_layer_compat_ie(parameter_tvb, 0, length, parameter_tree);
proto_item_set_text(parameter_item,
"User teleservice information");
}
static void
dissect_isup_transmission_medium_used_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 transmission_medium_requirement;
transmission_medium_requirement = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_transmission_medium_requirement_prime, parameter_tvb, 0, TRANSMISSION_MEDIUM_RQMT_PRIME_LENGTH,transmission_medium_requirement);
proto_item_set_text(parameter_item, "Transmission medium used: %u (%s)", transmission_medium_requirement, val_to_str_ext_const(transmission_medium_requirement, &isup_transmission_medium_requirement_prime_value_ext, "spare/reserved"));
}
static void
dissect_isup_call_diversion_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, CALL_DIV_INFO_LENGTH, "Call diversion information: 0x%x (refer to 3.6/Q.763 for detailed decoding)", indicator);
proto_item_set_text(parameter_item, "Call diversion information: 0x%x", indicator);
}
static void
dissect_isup_echo_control_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
gint offset = 0;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, ECHO_CONTROL_INFO_LENGTH,
"Echo control information: 0x%x", indicator);
proto_tree_add_uint(parameter_tree, hf_isup_OECD_inf_ind,
parameter_tvb, offset, 1, indicator);
proto_tree_add_uint(parameter_tree, hf_isup_IECD_inf_ind,
parameter_tvb, offset, 1, indicator);
proto_tree_add_uint(parameter_tree, hf_isup_OECD_req_ind,
parameter_tvb, offset, 1, indicator);
proto_tree_add_uint(parameter_tree, hf_isup_IECD_req_ind,
parameter_tvb, offset, 1, indicator);
proto_item_set_text(parameter_item, "Echo control information: 0x%x", indicator);
}
static void
dissect_isup_message_compatibility_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint length = tvb_length(parameter_tvb);
guint instruction_indicators;
gint offset = 0;
instruction_indicators = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length,
"Message compatibility information");
proto_tree_add_boolean(parameter_tree, hf_isup_transit_at_intermediate_exchange_ind,
parameter_tvb, offset, 1, instruction_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_Release_call_ind,
parameter_tvb, offset, 1, instruction_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_Send_notification_ind,
parameter_tvb, offset, 1, instruction_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_Discard_message_ind_value,
parameter_tvb, offset, 1, instruction_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_pass_on_not_possible_indicator2,
parameter_tvb, offset, 1,instruction_indicators);
proto_tree_add_uint(parameter_tree, hf_isup_Broadband_narrowband_interworking_ind2,
parameter_tvb, offset, 1,instruction_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_extension_ind ,
parameter_tvb, offset, 1, instruction_indicators);
proto_item_set_text(parameter_item, "Message compatibility information (%u byte%s length)",
length , plurality(length, "", "s"));
}
static void
dissect_isup_parameter_compatibility_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint length = tvb_length(parameter_tvb);
guint len = length;
guint8 upgraded_parameter, upgraded_parameter_no;
guint8 offset;
guint8 instruction_indicators;
offset = 0;
upgraded_parameter_no = 0;
proto_item_set_text(parameter_item, "Parameter compatibility information (%u byte%s length)", length , plurality(length, "", "s"));
while (len > 0) {
upgraded_parameter_no = upgraded_parameter_no + 1;
upgraded_parameter = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_text(parameter_tree, parameter_tvb, offset, 1,
"Upgraded parameter no: %u = %s", upgraded_parameter_no,
val_to_str_ext(upgraded_parameter, &isup_parameter_type_value_ext, "unknown (%u)"));
offset += 1;
len -= 1;
instruction_indicators = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_text(parameter_tree, parameter_tvb, offset, 1,
"Instruction indicators: 0x%x ",
instruction_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_transit_at_intermediate_exchange_ind,
parameter_tvb, offset, 1, instruction_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_Release_call_ind, parameter_tvb, offset, 1, instruction_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_Send_notification_ind, parameter_tvb, offset, 1, instruction_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_Discard_message_ind_value, parameter_tvb, offset, 1, instruction_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_Discard_parameter_ind, parameter_tvb, offset, 1, instruction_indicators);
proto_tree_add_uint(parameter_tree, hf_isup_Pass_on_not_possible_indicator, parameter_tvb, offset, 1,instruction_indicators);
proto_tree_add_boolean(parameter_tree, hf_isup_extension_ind , parameter_tvb, offset, 1, instruction_indicators);
offset += 1;
len -= 1;
if (!(instruction_indicators & H_8BIT_MASK)) {
if (len == 0)
return;
instruction_indicators = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(parameter_tree, hf_isup_Broadband_narrowband_interworking_ind, parameter_tvb, offset, 1,instruction_indicators);
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
char NI_digits[5]="";
const char *temp_text = "";
guint8 indicators, digit_pair;
guint32 bin_code;
indicators = tvb_get_guint8(parameter_tvb, 0);
switch ((indicators & 0x60) >> 5) {
case 0x0:
temp_text = "Allowed";
break;
case 0x1:
temp_text = "Not Allowed";
break;
case 0x2:
temp_text = "Path reserved";
break;
case 0x3:
temp_text = "Spare";
break;
}
proto_tree_add_text(parameter_tree, parameter_tvb, 0, 1, "Look forward busy: %s", temp_text);
switch (indicators & 0xf) {
case 0x0:
temp_text = "Flash Override";
break;
case 0x1:
temp_text = "Flash";
break;
case 0x2:
temp_text = "Immediate";
break;
case 0x3:
temp_text = "Priority";
break;
case 0x4:
temp_text = "Routine";
break;
default:
temp_text = "Spare";
break;
}
proto_tree_add_text(parameter_tree, parameter_tvb, 0, 1, "Precedence Level: %s",temp_text);
digit_pair = tvb_get_guint8(parameter_tvb, 1);
NI_digits[0] = number_to_char((digit_pair & HGFE_8BIT_MASK) / 0x10);
NI_digits[1] = number_to_char(digit_pair & DCBA_8BIT_MASK);
digit_pair = tvb_get_guint8(parameter_tvb, 2);
NI_digits[2] = number_to_char((digit_pair & HGFE_8BIT_MASK) / 0x10);
NI_digits[3] = number_to_char(digit_pair & DCBA_8BIT_MASK);
NI_digits[4] = '\0';
proto_tree_add_text(parameter_tree, parameter_tvb, 1, 2, "Network Identity: %s", NI_digits);
bin_code = tvb_get_ntoh24(parameter_tvb, 3);
proto_tree_add_text(parameter_tree, parameter_tvb, 3, 3, "MLPP service domain: 0x%x", bin_code);
proto_item_set_text(parameter_item, "MLPP precedence: Prec = %s, NI = %s, MLPP service domain = 0x%x", temp_text, NI_digits, bin_code);
}
static void
dissect_isup_mcid_request_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0,MCID_REQUEST_IND_LENGTH, "MCID request indicators: 0x%x (MCID requested by Bit1=1, Holding requested by Bit2=1 see 3.31/Q.763)", indicator);
proto_item_set_text(parameter_item, "MCID request indicators: 0x%x", indicator);
}
static void
dissect_isup_mcid_response_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0,MCID_RESPONSE_IND_LENGTH, "MCID response indicators: 0x%x (MCID included if Bit1=1, Holding provided if Bit2=1 see 3.32/Q.763)", indicator);
proto_item_set_text(parameter_item, "MCID response indicators: 0x%x", indicator);
}
static void
dissect_isup_hop_counter_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 counter;
counter = tvb_get_guint8(parameter_tvb, 0) & EDCBA_8BIT_MASK;
proto_tree_add_text(parameter_tree, parameter_tvb, 0, HOP_COUNTER_LENGTH, "Hop counter: %u", counter);
proto_item_set_text(parameter_item, "Hop counter: %u", counter);
}
static void
dissect_isup_orig_line_info_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 info;
info = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, ORIG_LINE_INFO_LENGTH, "Originating line info: %u", info);
proto_item_set_text(parameter_item, "Originating line info: %u (ANI II if < 51, reserved otherwise)", info);
}
static void
dissect_isup_transmission_medium_requirement_prime_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 transmission_medium_requirement;
transmission_medium_requirement = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_transmission_medium_requirement_prime, parameter_tvb, 0, TRANSMISSION_MEDIUM_RQMT_PRIME_LENGTH,transmission_medium_requirement);
proto_item_set_text(parameter_item, "Transmission medium requirement prime: %u (%s)", transmission_medium_requirement, val_to_str_ext_const(transmission_medium_requirement, &isup_transmission_medium_requirement_prime_value_ext, "spare/reserved"));
}
void
dissect_isup_location_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 indicators1, indicators2;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char calling_number[MAXDIGITS + 1]="";
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_calling_party_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
proto_tree_add_boolean(parameter_tree, hf_isup_inn_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, indicators2);
if ((indicators2 & GFE_8BIT_MASK) == 0x50)
proto_tree_add_text(parameter_tree, parameter_tvb, 1, 1, "Different meaning for Location Number: Numbering plan indicator = private numbering plan");
proto_tree_add_uint(parameter_tree, hf_isup_address_presentation_restricted_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_screening_indicator, parameter_tvb, 1, 1, indicators2);
if (tvb_length_remaining(parameter_tvb, offset) < 3) {
proto_tree_add_text(parameter_tree, parameter_tvb, 1, -1, "Location number: address not available");
proto_item_set_text(parameter_item, "Location number: address not available");
return;
}
offset = 2;
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Location number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
length = tvb_length_remaining(parameter_tvb, offset);
while(length > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
length = tvb_length_remaining(parameter_tvb, offset);
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
calling_number[i] = '\0';
proto_item_set_text(address_digits_item, "Location number: %s", calling_number);
proto_item_set_text(parameter_item, "Location number: %s", calling_number);
}
static void
dissect_isup_redirection_number_restriction_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
switch (indicator & BA_8BIT_MASK) {
case 0:
proto_tree_add_text(parameter_tree, parameter_tvb, 0, REDIRECTION_NUMBER_RESTRICTION_LENGTH, "Presentation indicator: Presentation allowed");
break;
case 1:
proto_tree_add_text(parameter_tree, parameter_tvb, 0, REDIRECTION_NUMBER_RESTRICTION_LENGTH, "Presentation indicator: Presentation restricted");
break;
default:
proto_tree_add_text(parameter_tree, parameter_tvb, 0, REDIRECTION_NUMBER_RESTRICTION_LENGTH, "Presentation indicator: spare");
break;
}
proto_item_set_text(parameter_item, "Redirection number restriction: 0x%x ", indicator);
}
static void
dissect_isup_call_transfer_reference_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 id;
id = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, CALL_TRANSFER_REF_LENGTH, "Call transfer identity: %u", id);
proto_item_set_text(parameter_item, "Call transfer reference: %u", id);
}
static void
dissect_isup_loop_prevention_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
if ((indicator & A_8BIT_MASK)==0) {
proto_tree_add_text(parameter_tree, parameter_tvb, 0, LOOP_PREVENTION_IND_LENGTH, "Type: Request");
proto_item_set_text(parameter_item, "Loop prevention indicators: Request (%u)", indicator);
}
else {
proto_tree_add_text(parameter_tree, parameter_tvb, 0, LOOP_PREVENTION_IND_LENGTH, "Type: Response");
proto_tree_add_uint(parameter_tree, hf_isup_loop_prevention_response_ind, parameter_tvb, 0, LOOP_PREVENTION_IND_LENGTH, indicator);
proto_item_set_text(parameter_item, "Loop prevention indicators: Response (%u)", indicator);
}
}
static void
dissect_isup_call_transfer_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 indicators1, indicators2;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char calling_number[MAXDIGITS + 1]="";
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_calling_party_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, indicators2);
if ((indicators2 & GFE_8BIT_MASK) == 0x50)
proto_tree_add_text(parameter_tree, parameter_tvb, 1, 1, "Different meaning for Call Transfer Number: Numbering plan indicator = private numbering plan");
proto_tree_add_uint(parameter_tree, hf_isup_address_presentation_restricted_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_screening_indicator_enhanced, parameter_tvb, 1, 1, indicators2);
offset = 2;
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Call transfer number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
length = tvb_length_remaining(parameter_tvb, offset);
while(length > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
length = tvb_length_remaining(parameter_tvb, offset);
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
calling_number[i] = '\0';
proto_item_set_text(address_digits_item, "Call transfer number: %s", calling_number);
proto_item_set_text(parameter_item, "Call transfer number: %s", calling_number);
}
static void
dissect_isup_ccss_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
if ((indicator & A_8BIT_MASK)==0) {
proto_tree_add_text(parameter_tree, parameter_tvb, 0, LOOP_PREVENTION_IND_LENGTH, "CCSS call indicator: no indication");
proto_item_set_text(parameter_item, "CCSS call indicator: no indication (%u)", indicator);
}
else {
proto_tree_add_text(parameter_tree, parameter_tvb, 0, LOOP_PREVENTION_IND_LENGTH, "CCSS call indicator: CCSS call");
proto_item_set_text(parameter_item, "CCSS call indicator: CCSS call (%u)", indicator);
}
}
static void
dissect_isup_forward_gvns_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length, "Forward GVNS (refer to 3.66/Q.763 for detailed decoding)");
proto_item_set_text(parameter_item, "Forward GVNS (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_redirect_capability_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length, "Redirect capability (format is a national matter)");
proto_item_set_text(parameter_item, "Redirect Capability (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_backward_gvns_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, BACKWARD_GVNS_LENGTH, "Backward GVNS: 0x%x (refer to 3.62/Q.763 for detailed decoding)", indicator);
proto_item_set_text(parameter_item, "Backward GVNS: 0x%x", indicator);
}
static void
dissect_isup_network_management_controls_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_temporary_alternative_routing_ind, parameter_tvb, 0,NETWORK_MANAGEMENT_CONTROLS_LENGTH, indicator);
proto_tree_add_boolean(parameter_tree, hf_isup_extension_ind, parameter_tvb, 0,NETWORK_MANAGEMENT_CONTROLS_LENGTH, indicator);
proto_item_set_text(parameter_item, "Network management controls: 0x%x", indicator);
}
static void
dissect_isup_correlation_id_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length, "Correlation ID (-> Q.1281)");
proto_item_set_text(parameter_item, "Correlation ID, see Q.1281 (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_scf_id_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length, "SCF ID (-> Q.1281)");
proto_item_set_text(parameter_item, "SCF ID, see Q.1281 (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_call_diversion_treatment_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_call_to_be_diverted_ind, parameter_tvb, 0,CALL_DIV_TREATMENT_IND_LENGTH, indicator);
proto_tree_add_boolean(parameter_tree, hf_isup_extension_ind, parameter_tvb, 0, CALL_DIV_TREATMENT_IND_LENGTH, indicator);
proto_item_set_text(parameter_item, "Call diversion treatment indicators: 0x%x", indicator);
}
static void
dissect_isup_called_in_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 indicators1, indicators2;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char calling_number[MAXDIGITS + 1]="";
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_calling_party_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_address_presentation_restricted_indicator, parameter_tvb, 1, 1, indicators2);
offset = 2;
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Called IN Number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
length = tvb_length_remaining(parameter_tvb, offset);
while(length > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
length = tvb_length_remaining(parameter_tvb, offset);
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
calling_number[i] = '\0';
proto_item_set_text(address_digits_item, "Called IN Number: %s", calling_number);
proto_item_set_text(parameter_item, "Called IN Number: %s", calling_number);
}
static void
dissect_isup_call_offering_treatment_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_call_to_be_offered_ind, parameter_tvb, 0,CALL_OFFERING_TREATMENT_IND_LENGTH, indicator);
proto_tree_add_boolean(parameter_tree, hf_isup_extension_ind, parameter_tvb, 0, CALL_OFFERING_TREATMENT_IND_LENGTH, indicator);
proto_item_set_text(parameter_item, "Call offering treatment indicators: 0x%x", indicator);
}
static void
dissect_isup_charged_party_identification_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length, "Charged party identification (format is national network specific)");
proto_item_set_text(parameter_item, "Charged party identification (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_conference_treatment_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_conference_acceptance_ind, parameter_tvb, 0,CONFERENCE_TREATMENT_IND_LENGTH, indicator);
proto_tree_add_boolean(parameter_tree, hf_isup_extension_ind, parameter_tvb, 0, CONFERENCE_TREATMENT_IND_LENGTH, indicator);
proto_item_set_text(parameter_item, "Conference treatment indicators: 0x%x", indicator);
}
static void
dissect_isup_display_information_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length,
"Display information (-> Q.931)");
proto_item_set_text(parameter_item, "Display information (%u Byte%s)",
length , plurality(length, "", "s"));
}
static void
dissect_isup_uid_action_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0,UID_ACTION_IND_LENGTH, "UID action indicators: 0x%x (refer to 3.78/Q.763 for detailed decoding)", indicator);
proto_item_set_text(parameter_item, "UID action indicators: 0x%x", indicator);
}
static void
dissect_isup_uid_capability_indicators_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0,UID_CAPABILITY_IND_LENGTH, "UID capability indicators: 0x%x (refer to 3.79/Q.763 for detailed decoding)", indicator);
proto_item_set_text(parameter_item, "UID capability indicators: 0x%x", indicator);
}
static void
dissect_isup_redirect_counter_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length, "Redirect counter (format is a national matter)");
proto_item_set_text(parameter_item, "Redirect counter (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_collect_call_request_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint8 indicator;
indicator = tvb_get_guint8(parameter_tvb, 0);
if ((indicator & A_8BIT_MASK) == 0) {
proto_tree_add_text(parameter_tree, parameter_tvb, 0, COLLECT_CALL_REQUEST_LENGTH, "Collect call request indicator: no indication");
proto_item_set_text(parameter_item, "Collect call request: no indication (0x%x)", indicator);
}
else {
proto_tree_add_text(parameter_tree, parameter_tvb, 0, COLLECT_CALL_REQUEST_LENGTH, "Collect call request indicator: collect call requested");
proto_item_set_text(parameter_item, "Collect call request: collect call requested (0x%x)", indicator);
}
}
static void
dissect_isup_calling_geodetic_location_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint length = tvb_length(parameter_tvb);
guint8 oct, lpri;
oct = tvb_get_guint8(parameter_tvb, 0);
lpri = (oct & 0xc0) >> 2;
proto_tree_add_uint(parameter_tree, hf_isup_geo_loc_presentation_restricted_ind, parameter_tvb, 0, 1, oct);
proto_tree_add_uint(parameter_tree, hf_isup_geo_loc_screening_ind, parameter_tvb, 0, 1, oct);
oct = tvb_get_guint8(parameter_tvb, 1);
proto_tree_add_boolean(parameter_tree, hf_isup_extension_ind, parameter_tvb, 1, 1, oct);
proto_tree_add_text(parameter_tree, parameter_tvb, 1, 1,
"Calling geodetic location type of shape: %s (%u)",
val_to_str(oct & GFEDCBA_8BIT_MASK, isup_location_type_of_shape_value, "spare/reserved"), oct);
if (length > 2)
{
if (lpri < 0x2)
{
proto_tree_add_text(parameter_tree, parameter_tvb, 2, length - 2,
"Shape description");
}
else
{
proto_tree_add_text(parameter_tree, parameter_tvb, 2, length - 2,
"Unknown (?), should not have data if LPRI is 'location not available'");
}
}
proto_item_set_text(parameter_item, "Calling geodetic location");
}
void
dissect_isup_generic_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 indicators1, indicators2, nr_qualifier_ind;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char calling_number[MAXDIGITS + 1]="";
nr_qualifier_ind = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, 1, "Number qualifier indicator: 0x%x (refer to 3.26/Q.763 for detailed decoding)", nr_qualifier_ind);
indicators1 = tvb_get_guint8(parameter_tvb, 1);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 1, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_calling_party_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 2);
proto_tree_add_boolean(parameter_tree, hf_isup_ni_indicator, parameter_tvb, 2, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 2, 1, indicators2);
if ((indicators2 & GFE_8BIT_MASK) == 0x50)
proto_tree_add_text(parameter_tree, parameter_tvb, 2, 1, "Different meaning for Generic Number: Numbering plan indicator = private numbering plan");
proto_tree_add_uint(parameter_tree, hf_isup_address_presentation_restricted_indicator, parameter_tvb, 2, 1, indicators2);
proto_tree_add_uint(parameter_tree, hf_isup_screening_indicator_enhanced, parameter_tvb, 2, 1, indicators2);
offset = 3;
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Generic number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
length = tvb_length_remaining(parameter_tvb, offset);
while(length > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
length = tvb_length_remaining(parameter_tvb, offset);
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
calling_number[i] = '\0';
indicators1 = indicators1 & 0x7f;
indicators2 = (indicators2 & 0x70)>>4;
if ((indicators1 == ISUP_CALLED_PARTY_NATURE_INTERNATNL_NR)&&(indicators2==ISDN_NUMBERING_PLAN))
dissect_e164_cc(parameter_tvb, address_digits_tree, 3, TRUE);
proto_item_set_text(address_digits_item, "Generic number: %s", calling_number);
proto_item_set_text(parameter_item, "Generic number: %s", calling_number);
}
static void
dissect_isup_jurisdiction_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char called_number[MAXDIGITS + 1]="";
offset = 0;
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Jurisdiction");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
while((length = tvb_reported_length_remaining(parameter_tvb, offset)) > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
called_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
called_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
}
if (tvb_length(parameter_tvb) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_called_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
called_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
called_number[i] = '\0';
proto_item_set_text(address_digits_item, "Jurisdiction: %s", called_number);
proto_item_set_text(parameter_item, "Jurisdiction: %s", called_number);
}
static void
dissect_isup_generic_name_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
guint8 indicator;
gint gen_name_length;
char *gen_name=NULL;
gen_name=ep_alloc(MAXGNAME + 1);
gen_name[0] = '\0';
gen_name_length = tvb_length(parameter_tvb) - 1;
indicator = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_uint(parameter_tree, hf_isup_generic_name_presentation, parameter_tvb, 1, 1, indicator);
proto_tree_add_boolean(parameter_tree, hf_isup_generic_name_availability, parameter_tvb, 1, 1, indicator);
proto_tree_add_uint(parameter_tree, hf_isup_generic_name_type, parameter_tvb, 1, 1, indicator);
gen_name = tvb_get_ephemeral_string(parameter_tvb,1,gen_name_length);
gen_name[gen_name_length] = '\0';
proto_tree_add_string(parameter_tree, hf_isup_generic_name_ia5, parameter_tvb, 2, gen_name_length, gen_name);
proto_item_set_text(parameter_item, "Generic name: %s", gen_name);
}
static void
dissect_isup_generic_digits_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_tree_add_text(parameter_tree, parameter_tvb, 0, length, "Generic digits (refer to 3.24/Q.673 for detailed decoding)");
proto_item_set_text(parameter_item, "Generic digits (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_charge_number_parameter(tvbuff_t *parameter_tvb, proto_tree *parameter_tree, proto_item *parameter_item)
{
proto_item *address_digits_item;
proto_tree *address_digits_tree;
guint8 indicators1, indicators2;
guint8 address_digit_pair=0;
gint offset=0;
gint i=0;
gint length;
char calling_number[MAXDIGITS + 1]="";
indicators1 = tvb_get_guint8(parameter_tvb, 0);
proto_tree_add_boolean(parameter_tree, hf_isup_odd_even_indicator, parameter_tvb, 0, 1, indicators1);
proto_tree_add_uint(parameter_tree, hf_isup_charge_number_nature_of_address_indicator, parameter_tvb, 0, 1, indicators1);
indicators2 = tvb_get_guint8(parameter_tvb, 1);
proto_tree_add_uint(parameter_tree, hf_isup_numbering_plan_indicator, parameter_tvb, 1, 1, indicators2);
offset = 2;
address_digits_item = proto_tree_add_text(parameter_tree, parameter_tvb,
offset, -1,
"Charge Number");
address_digits_tree = proto_item_add_subtree(address_digits_item, ett_isup_address_digits);
length = tvb_length_remaining(parameter_tvb, offset);
while(length > 0) {
address_digit_pair = tvb_get_guint8(parameter_tvb, offset);
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_odd_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char(address_digit_pair & ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
if ((length - 1) > 0) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
offset++;
length = tvb_length_remaining(parameter_tvb, offset);
}
if (((indicators1 & 0x80) == 0) && (tvb_length(parameter_tvb) > 0)) {
proto_tree_add_uint(address_digits_tree, hf_isup_calling_party_even_address_signal_digit, parameter_tvb, offset - 1, 1, address_digit_pair);
calling_number[i++] = number_to_char((address_digit_pair & ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK) / 0x10);
if (i > MAXDIGITS)
THROW(ReportedBoundsError);
}
calling_number[i] = '\0';
proto_item_set_text(address_digits_item, "Charge Number: %s", calling_number);
proto_item_set_text(parameter_item, "Charge Number: %s", calling_number);
}
static void
dissect_isup_unknown_parameter(tvbuff_t *parameter_tvb, proto_item *parameter_item)
{ guint length = tvb_length(parameter_tvb);
proto_item_set_text(parameter_item, "Parameter Type unknown/reserved (%u Byte%s)", length , plurality(length, "", "s"));
}
static void
dissect_isup_optional_parameter(tvbuff_t *optional_parameters_tvb,packet_info *pinfo, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
gint offset = 0;
guint parameter_type, parameter_length, actual_length;
tvbuff_t *parameter_tvb;
guint8 octet;
parameter_type = 0xFF;
while ((tvb_length_remaining(optional_parameters_tvb, offset) >= 1) && (parameter_type != PARAM_TYPE_END_OF_OPT_PARAMS)) {
parameter_type = tvb_get_guint8(optional_parameters_tvb, offset);
if (parameter_type != PARAM_TYPE_END_OF_OPT_PARAMS) {
parameter_length = tvb_get_guint8(optional_parameters_tvb, offset + PARAMETER_TYPE_LENGTH);
parameter_item = proto_tree_add_text(isup_tree, optional_parameters_tvb,
offset,
parameter_length + PARAMETER_TYPE_LENGTH + PARAMETER_LENGTH_IND_LENGTH,
"Parameter: type %u",
parameter_type);
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, optional_parameters_tvb, offset, PARAMETER_TYPE_LENGTH,
parameter_type,
"Optional Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext,"unknown"));
offset += PARAMETER_TYPE_LENGTH;
octet = tvb_get_guint8(optional_parameters_tvb,offset);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, optional_parameters_tvb, offset, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
offset += PARAMETER_LENGTH_IND_LENGTH;
if (octet == 0)
continue;
actual_length = tvb_length_remaining(optional_parameters_tvb, offset);
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
dissect_isup_called_party_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SUBSQT_NR:
dissect_isup_subsequent_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_calling_partys_category_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALLING_PARTY_NR:
dissect_isup_calling_party_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECTING_NR:
dissect_isup_redirecting_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECTION_NR:
dissect_isup_redirection_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_range_and_status_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_connected_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SUSP_RESUME_IND:
dissect_isup_suspend_resume_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_TRANSIT_NETW_SELECT:
dissect_isup_transit_network_selection_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_original_called_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_location_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_call_transfer_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_redirect_capability_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_called_in_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_redirect_counter_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_COLLECT_CALL_REQ:
dissect_isup_collect_call_request_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_NR:
dissect_isup_generic_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_DIGITS:
dissect_isup_generic_digits_parameter(parameter_tvb, parameter_tree, parameter_item);
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
proto_tree_add_uint_format(isup_tree, hf_isup_parameter_type, optional_parameters_tvb , offset, PARAMETER_TYPE_LENGTH,
parameter_type, "End of optional parameters (%u)", parameter_type);
}
}
}
static void
dissect_ansi_isup_optional_parameter(tvbuff_t *optional_parameters_tvb,packet_info *pinfo, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
gint offset = 0;
guint parameter_type, parameter_length, actual_length;
tvbuff_t *parameter_tvb;
guint8 octet;
parameter_type = 0xFF;
while ((tvb_length_remaining(optional_parameters_tvb, offset) >= 1) && (parameter_type != PARAM_TYPE_END_OF_OPT_PARAMS)) {
parameter_type = tvb_get_guint8(optional_parameters_tvb, offset);
if (parameter_type != PARAM_TYPE_END_OF_OPT_PARAMS) {
parameter_length = tvb_get_guint8(optional_parameters_tvb, offset + PARAMETER_TYPE_LENGTH);
parameter_item = proto_tree_add_text(isup_tree, optional_parameters_tvb,
offset,
parameter_length + PARAMETER_TYPE_LENGTH + PARAMETER_LENGTH_IND_LENGTH,
"Parameter: type %u",
parameter_type);
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, optional_parameters_tvb, offset, PARAMETER_TYPE_LENGTH, parameter_type,
"Optional Parameter: %u (%s)", parameter_type,
val_to_str_ext_const(parameter_type, &ansi_isup_parameter_type_value_ext,"unknown"));
offset += PARAMETER_TYPE_LENGTH;
octet = tvb_get_guint8(optional_parameters_tvb,offset);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, optional_parameters_tvb, offset, PARAMETER_LENGTH_IND_LENGTH, parameter_length,
"Parameter length: %u", parameter_length);
offset += PARAMETER_LENGTH_IND_LENGTH;
if (octet == 0)
continue;
actual_length = tvb_length_remaining(optional_parameters_tvb, offset);
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
dissect_isup_called_party_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SUBSQT_NR:
dissect_isup_subsequent_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_calling_partys_category_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALLING_PARTY_NR:
dissect_isup_calling_party_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECTING_NR:
dissect_isup_redirecting_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_REDIRECTION_NR:
dissect_isup_redirection_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_range_and_status_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_connected_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_SUSP_RESUME_IND:
dissect_isup_suspend_resume_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_TRANSIT_NETW_SELECT:
dissect_isup_transit_network_selection_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_original_called_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_location_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_call_transfer_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_redirect_capability_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_called_in_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
dissect_isup_redirect_counter_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_COLLECT_CALL_REQ:
dissect_isup_collect_call_request_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CALLING_GEODETIC_LOCATION:
dissect_isup_calling_geodetic_location_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_NR:
dissect_isup_generic_number_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_JURISDICTION:
dissect_isup_jurisdiction_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_NAME:
dissect_isup_generic_name_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_GENERIC_DIGITS:
dissect_isup_generic_digits_parameter(parameter_tvb, parameter_tree, parameter_item);
break;
case PARAM_TYPE_CHARGE_NR:
dissect_isup_charge_number_parameter(parameter_tvb, parameter_tree, parameter_item);
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
proto_tree_add_uint_format(isup_tree, hf_isup_parameter_type, optional_parameters_tvb , offset, PARAMETER_TYPE_LENGTH, parameter_type, "End of optional parameters (%u)", parameter_type);
}
}
}
static gint
dissect_ansi_isup_circuit_validation_test_resp_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{
proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type,actual_length;
parameter_type = ANSI_ISUP_PARAM_TYPE_CVR_RESP_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset, CVR_RESP_IND_LENGTH, "CVR Response Indicator");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext,"CVR Response Indicator"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(CVR_RESP_IND_LENGTH, actual_length), CVR_RESP_IND_LENGTH);
dissect_isup_cvr_response_ind_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += CVR_RESP_IND_LENGTH;
parameter_type = ANSI_ISUP_PARAM_TYPE_CG_CHAR_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
CG_CHAR_IND_LENGTH,
"Circuit Group Characteristics Indicators");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "Circuit Group Characters"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(CG_CHAR_IND_LENGTH, actual_length), CG_CHAR_IND_LENGTH);
dissect_isup_circuit_group_char_ind_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += CG_CHAR_IND_LENGTH;
return offset;
}
static gint
dissect_ansi_isup_circuit_reservation_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_NATURE_OF_CONN_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
NATURE_OF_CONNECTION_IND_LENGTH,
"Nature of Connection Indicators");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext,"unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(NATURE_OF_CONNECTION_IND_LENGTH, actual_length), NATURE_OF_CONNECTION_IND_LENGTH);
dissect_isup_nature_of_connection_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += NATURE_OF_CONNECTION_IND_LENGTH;
return offset;
}
static gint
dissect_isup_initial_address_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_NATURE_OF_CONN_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
NATURE_OF_CONNECTION_IND_LENGTH,
"Nature of Connection Indicators");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(NATURE_OF_CONNECTION_IND_LENGTH, actual_length), NATURE_OF_CONNECTION_IND_LENGTH);
dissect_isup_nature_of_connection_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += NATURE_OF_CONNECTION_IND_LENGTH;
parameter_type = PARAM_TYPE_FORW_CALL_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
FORWARD_CALL_IND_LENGTH,
"Forward Call Indicators");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(FORWARD_CALL_IND_LENGTH, actual_length), FORWARD_CALL_IND_LENGTH);
dissect_isup_forward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += FORWARD_CALL_IND_LENGTH;
parameter_type = PARAM_TYPE_CALLING_PRTY_CATEG;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
CALLING_PRTYS_CATEGORY_LENGTH,
"Calling Party's category");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(CALLING_PRTYS_CATEGORY_LENGTH, actual_length),CALLING_PRTYS_CATEGORY_LENGTH);
dissect_isup_calling_partys_category_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += CALLING_PRTYS_CATEGORY_LENGTH;
switch (isup_standard) {
case ITU_STANDARD:
parameter_type = PARAM_TYPE_TRANSM_MEDIUM_REQU;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
TRANSMISSION_MEDIUM_REQUIREMENT_LENGTH,
"Transmission medium requirement");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(TRANSMISSION_MEDIUM_REQUIREMENT_LENGTH, actual_length), TRANSMISSION_MEDIUM_REQUIREMENT_LENGTH);
dissect_isup_transmission_medium_requirement_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += TRANSMISSION_MEDIUM_REQUIREMENT_LENGTH;
break;
case ANSI_STANDARD:
parameter_type = PARAM_TYPE_USER_SERVICE_INFO;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"User Service Information");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
dissect_isup_user_service_information_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
break;
}
parameter_type = PARAM_TYPE_CALLED_PARTY_NR;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"Called Party Number");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
dissect_isup_called_party_number_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint dissect_isup_subsequent_address_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_SUBSQT_NR;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"Subsequent Number");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
dissect_isup_subsequent_number_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_information_request_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_INFO_REQ_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
INFO_REQUEST_IND_LENGTH,
"Information request indicators");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(INFO_REQUEST_IND_LENGTH, actual_length), INFO_REQUEST_IND_LENGTH);
dissect_isup_information_request_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += INFO_REQUEST_IND_LENGTH;
return offset;
}
static gint
dissect_isup_information_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_INFO_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
INFO_IND_LENGTH,
"Information indicators");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(INFO_IND_LENGTH, actual_length), INFO_IND_LENGTH);
dissect_isup_information_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += INFO_IND_LENGTH;
return offset;
}
static gint
dissect_isup_continuity_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_CONTINUITY_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
CONTINUITY_IND_LENGTH,
"Continuity indicators");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(CONTINUITY_IND_LENGTH, actual_length), CONTINUITY_IND_LENGTH);
dissect_isup_continuity_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += CONTINUITY_IND_LENGTH;
return offset;
}
static gint
dissect_isup_address_complete_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_BACKW_CALL_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
BACKWARD_CALL_IND_LENGTH,
"Backward Call Indicators");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(BACKWARD_CALL_IND_LENGTH, actual_length), BACKWARD_CALL_IND_LENGTH);
dissect_isup_backward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += BACKWARD_CALL_IND_LENGTH;
return offset;
}
static gint
dissect_isup_connect_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_BACKW_CALL_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
BACKWARD_CALL_IND_LENGTH,
"Backward Call Indicators");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(BACKWARD_CALL_IND_LENGTH, actual_length), BACKWARD_CALL_IND_LENGTH);
dissect_isup_backward_call_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += BACKWARD_CALL_IND_LENGTH;
return offset;
}
static gint
dissect_isup_release_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_CAUSE_INDICATORS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"Cause indicators");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
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
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_SUSP_RESUME_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
SUSPEND_RESUME_IND_LENGTH,
"Suspend/Resume indicator");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(SUSPEND_RESUME_IND_LENGTH, actual_length), SUSPEND_RESUME_IND_LENGTH);
dissect_isup_suspend_resume_indicators_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += SUSPEND_RESUME_IND_LENGTH;
return offset;
}
static gint
dissect_isup_circuit_group_reset_query_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_RANGE_AND_STATUS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"Range and status");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
dissect_isup_range_and_status_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_circuit_group_blocking_messages(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_CIRC_GRP_SV_MSG_TYPE;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
CIRC_GRP_SV_MSG_TYPE_LENGTH,
"Circuit group supervision message type");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(CIRC_GRP_SV_MSG_TYPE_LENGTH, actual_length), CIRC_GRP_SV_MSG_TYPE_LENGTH);
dissect_isup_circuit_group_supervision_message_type_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += CIRC_GRP_SV_MSG_TYPE_LENGTH;
parameter_type = PARAM_TYPE_RANGE_AND_STATUS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"Range and status");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
dissect_isup_range_and_status_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_facility_request_accepted_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_FACILITY_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
FACILITY_IND_LENGTH,
"Facility indicator");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(FACILITY_IND_LENGTH, actual_length), FACILITY_IND_LENGTH);
dissect_isup_facility_ind_parameter(parameter_tvb, parameter_item);
offset += FACILITY_IND_LENGTH;
return offset;
}
static gint
dissect_isup_facility_reject_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_FACILITY_IND;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
FACILITY_IND_LENGTH,
"Facility indicator");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(FACILITY_IND_LENGTH, actual_length), FACILITY_IND_LENGTH);
dissect_isup_facility_ind_parameter(parameter_tvb, parameter_item);
offset += FACILITY_IND_LENGTH;
parameter_type = PARAM_TYPE_CAUSE_INDICATORS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"Cause indicators, see Q.850");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
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
dissect_isup_circuit_group_reset_acknowledgement_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_RANGE_AND_STATUS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"Range and status");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
dissect_isup_range_and_status_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_circuit_group_query_response_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_RANGE_AND_STATUS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"Range and status");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
dissect_isup_range_and_status_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
parameter_type = PARAM_TYPE_CIRC_STATE_IND;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"Circuit state indicator (national use)");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
dissect_isup_circuit_state_ind_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_call_progress_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, actual_length;
parameter_type = PARAM_TYPE_EVENT_INFO;
parameter_item = proto_tree_add_text(isup_tree, message_tvb, offset,
EVENT_INFO_LENGTH,
"Event information");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset, MIN(EVENT_INFO_LENGTH, actual_length), EVENT_INFO_LENGTH);
dissect_isup_event_information_parameter(parameter_tvb, parameter_tree, parameter_item);
offset += EVENT_INFO_LENGTH;
return offset;
}
static gint
dissect_isup_user_to_user_information_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_USER_TO_USER_INFO;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"User-to-user information, see Q.931");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
dissect_isup_user_to_user_information_parameter(parameter_tvb, pinfo, parameter_tree, parameter_item);
offset += PARAMETER_POINTER_LENGTH;
return offset;
}
static gint
dissect_isup_confusion_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{ proto_item* parameter_item;
proto_tree* parameter_tree;
tvbuff_t *parameter_tvb;
gint offset = 0;
gint parameter_type, parameter_pointer, parameter_length, actual_length;
parameter_type = PARAM_TYPE_CAUSE_INDICATORS;
parameter_pointer = tvb_get_guint8(message_tvb, offset);
parameter_length = tvb_get_guint8(message_tvb, offset + parameter_pointer);
parameter_item = proto_tree_add_text(isup_tree, message_tvb,
offset + parameter_pointer,
parameter_length + PARAMETER_LENGTH_IND_LENGTH,
"Cause indicators, see Q.850");
parameter_tree = proto_item_add_subtree(parameter_item, ett_isup_parameter);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_type, message_tvb, 0, 0, parameter_type,
"Mandatory Parameter: %u (%s)",
parameter_type,
val_to_str_ext_const(parameter_type, &isup_parameter_type_value_ext, "unknown"));
proto_tree_add_uint_format(parameter_tree, hf_isup_mandatory_variable_parameter_pointer, message_tvb, offset, PARAMETER_POINTER_LENGTH, parameter_pointer, "Pointer to Parameter: %u", parameter_pointer);
proto_tree_add_uint_format(parameter_tree, hf_isup_parameter_length, message_tvb, offset + parameter_pointer, PARAMETER_LENGTH_IND_LENGTH, parameter_length, "Parameter length: %u", parameter_length);
actual_length = tvb_ensure_length_remaining(message_tvb, offset);
parameter_tvb = tvb_new_subset(message_tvb, offset + parameter_pointer + PARAMETER_LENGTH_IND_LENGTH, MIN(parameter_length, actual_length), parameter_length);
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
offset++;
proto_tree_add_item(isup_tree, hf_isup_french_msg_num, message_tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int
dissect_israeli_backward_charging_message(tvbuff_t *message_tvb, proto_tree *isup_tree)
{
gint offset = 0;
proto_tree_add_item(isup_tree, hf_isup_israeli_charging_message_indicators_current, message_tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(isup_tree, hf_isup_israeli_charging_message_indicators_next, message_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(isup_tree, hf_isup_israeli_current_rate, message_tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(isup_tree, hf_isup_israeli_time_indicator, message_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
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
offset++;
proto_tree_add_item(isup_tree, hf_isup_israeli_time_indicator, message_tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(isup_tree, hf_isup_israeli_next_rate, message_tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static void
dissect_ansi_isup_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree)
{
isup_tap_rec_t *tap_rec;
tvbuff_t *parameter_tvb;
tvbuff_t *optional_parameter_tvb;
proto_item* pass_along_item;
proto_tree* pass_along_tree;
gint offset, bufferlength;
guint8 message_type, opt_parameter_pointer;
gint opt_part_possible = FALSE;
tap_calling_number = NULL;
offset = 0;
message_type = tvb_get_guint8(message_tvb,0);
proto_tree_add_uint_format(isup_tree, hf_isup_message_type, message_tvb, 0, MESSAGE_TYPE_LENGTH, message_type, "Message type: %s (%u)",
val_to_str_ext_const(message_type, &ansi_isup_message_type_value_ext, "reserved"), message_type);
offset += MESSAGE_TYPE_LENGTH;
tap_rec = (isup_tap_rec_t *)ep_alloc(sizeof(isup_tap_rec_t));
tap_rec->message_type = message_type;
tap_rec->calling_number = NULL;
tap_rec->called_number = NULL;
parameter_tvb = tvb_new_subset_remaining(message_tvb, offset);
switch (message_type) {
case MESSAGE_TYPE_INITIAL_ADDR:
offset += dissect_isup_initial_address_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_SUBSEQ_ADDR:
offset += dissect_isup_subsequent_address_message(parameter_tvb, isup_tree);
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
offset += dissect_isup_circuit_group_reset_query_message(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_BLCK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_UNBL:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_BL_ACK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_UNBL_ACK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, isup_tree);
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
pass_along_item = proto_tree_add_text(isup_tree, parameter_tvb, offset, -1,
"Pass-along: %s Message (%u)",
val_to_str_ext_const(pa_message_type, &isup_message_type_value_acro_ext, "reserved"),
pa_message_type);
pass_along_tree = proto_item_add_subtree(pass_along_item, ett_isup_pass_along_message);
dissect_ansi_isup_message(parameter_tvb, pinfo, pass_along_tree);
break;
}
case MESSAGE_TYPE_CIRC_GRP_RST_ACK:
offset += dissect_isup_circuit_group_reset_acknowledgement_message(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_QRY:
offset += dissect_isup_circuit_group_reset_query_message(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_QRY_RSP:
offset += dissect_isup_circuit_group_query_response_message(parameter_tvb, isup_tree);
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
bufferlength = tvb_length_remaining(message_tvb, offset);
if (bufferlength != 0)
proto_tree_add_text(isup_tree, parameter_tvb, 0, bufferlength, "Format is a national matter");
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
bufferlength = tvb_length_remaining(message_tvb, offset);
if (bufferlength != 0)
proto_tree_add_text(isup_tree, parameter_tvb, 0, bufferlength, "Format is a national matter");
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
bufferlength = tvb_length_remaining(message_tvb, offset);
if (bufferlength != 0)
proto_tree_add_text(isup_tree, parameter_tvb, 0, bufferlength, "Unknown Message type (possibly reserved/used in former ISUP version)");
break;
}
if (opt_part_possible == TRUE) {
opt_parameter_pointer = tvb_get_guint8(message_tvb, offset);
if (opt_parameter_pointer > 0) {
proto_tree_add_uint_format(isup_tree, hf_isup_pointer_to_start_of_optional_part, message_tvb, offset, PARAMETER_POINTER_LENGTH, opt_parameter_pointer, "Pointer to start of optional part: %u", opt_parameter_pointer);
offset += opt_parameter_pointer;
optional_parameter_tvb = tvb_new_subset_remaining(message_tvb, offset);
dissect_ansi_isup_optional_parameter(optional_parameter_tvb, pinfo, isup_tree);
}
else
proto_tree_add_uint_format(isup_tree, hf_isup_pointer_to_start_of_optional_part, message_tvb, offset, PARAMETER_POINTER_LENGTH, opt_parameter_pointer, "No optional parameter present (Pointer: %u)", opt_parameter_pointer);
}
else if (message_type !=MESSAGE_TYPE_CHARGE_INFO)
proto_tree_add_text(isup_tree, message_tvb, 0, 0, "No optional parameters are possible with this message type");
tap_rec->calling_number=tap_calling_number?tap_calling_number:ep_strdup("");
tap_rec->called_number=tap_called_number;
tap_rec->cause_value=tap_cause_value;
tap_queue_packet(isup_tap, pinfo, tap_rec);
}
static void
dissect_isup_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *isup_tree, guint8 itu_isup_variant)
{
isup_tap_rec_t *tap_rec;
tvbuff_t *parameter_tvb;
tvbuff_t *optional_parameter_tvb;
proto_item* pass_along_item;
proto_tree* pass_along_tree;
gint offset, bufferlength;
guint8 message_type, opt_parameter_pointer;
gint opt_part_possible = FALSE;
tap_calling_number = NULL;
offset = 0;
message_type = tvb_get_guint8(message_tvb,0);
switch(itu_isup_variant) {
case ISUP_ITU_STANDARD_VARIANT:
proto_tree_add_uint_format(isup_tree, hf_isup_message_type, message_tvb, 0, MESSAGE_TYPE_LENGTH, message_type,
"Message type: %s (%u)",
val_to_str_ext_const(message_type, &isup_message_type_value_ext, "reserved"),
message_type);
break;
case ISUP_FRENCH_VARIANT:
proto_tree_add_uint_format(isup_tree, hf_isup_message_type, message_tvb, 0, MESSAGE_TYPE_LENGTH, message_type,
"Message type: %s (%u)",
val_to_str_ext_const(message_type, &french_isup_message_type_value_ext, "reserved"),
message_type);
break;
case ISUP_ISRAELI_VARIANT:
proto_tree_add_uint_format(isup_tree, hf_isup_message_type, message_tvb, 0, MESSAGE_TYPE_LENGTH, message_type,
"Message type: %s (%u)",
val_to_str_ext_const(message_type, &israeli_isup_message_type_value_ext, "reserved"),
message_type);
break;
}
offset += MESSAGE_TYPE_LENGTH;
tap_rec = (isup_tap_rec_t *)ep_alloc(sizeof(isup_tap_rec_t));
tap_rec->message_type = message_type;
tap_rec->calling_number = NULL;
tap_rec->called_number = NULL;
parameter_tvb = tvb_new_subset_remaining(message_tvb, offset);
switch (message_type) {
case MESSAGE_TYPE_INITIAL_ADDR:
offset += dissect_isup_initial_address_message(parameter_tvb, isup_tree);
opt_part_possible = TRUE;
break;
case MESSAGE_TYPE_SUBSEQ_ADDR:
offset += dissect_isup_subsequent_address_message(parameter_tvb, isup_tree);
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
offset += dissect_isup_circuit_group_reset_query_message(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_BLCK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_UNBL:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_BL_ACK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_UNBL_ACK:
offset += dissect_isup_circuit_group_blocking_messages(parameter_tvb, isup_tree);
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
pass_along_item = proto_tree_add_text(isup_tree, parameter_tvb, offset, -1,
"Pass-along: %s Message (%u)",
val_to_str_ext_const(pa_message_type, &isup_message_type_value_acro_ext, "reserved"),
pa_message_type);
pass_along_tree = proto_item_add_subtree(pass_along_item, ett_isup_pass_along_message);
dissect_isup_message(parameter_tvb, pinfo, pass_along_tree, itu_isup_variant);
break;
}
case MESSAGE_TYPE_CIRC_GRP_RST_ACK:
offset += dissect_isup_circuit_group_reset_acknowledgement_message(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_QRY:
offset += dissect_isup_circuit_group_reset_query_message(parameter_tvb, isup_tree);
break;
case MESSAGE_TYPE_CIRC_GRP_QRY_RSP:
offset += dissect_isup_circuit_group_query_response_message(parameter_tvb, isup_tree);
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
bufferlength = tvb_length_remaining(message_tvb, offset);
if (bufferlength != 0)
proto_tree_add_text(isup_tree, parameter_tvb, 0, bufferlength, "Format is a national matter");
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
bufferlength = tvb_length_remaining(message_tvb, offset);
if (bufferlength != 0)
proto_tree_add_text(isup_tree, parameter_tvb, 0, bufferlength, "Format is a national matter");
break;
default:
switch(itu_isup_variant) {
case ISUP_ITU_STANDARD_VARIANT:
bufferlength = tvb_length_remaining(message_tvb, offset);
if (bufferlength != 0)
proto_tree_add_text(isup_tree, parameter_tvb, 0, bufferlength, "Unknown Message type (possibly reserved/used in former ISUP version)");
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
bufferlength = tvb_length_remaining(message_tvb, offset);
if (bufferlength != 0)
proto_tree_add_text(isup_tree, parameter_tvb, 0, bufferlength, "Unknown Message type (possibly reserved/used in former ISUP version)");
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
bufferlength = tvb_length_remaining(message_tvb, offset);
if (bufferlength != 0)
proto_tree_add_text(isup_tree, parameter_tvb, 0, bufferlength, "Unknown Message type (possibly reserved/used in former ISUP version)");
break;
}
break;
}
break;
}
if (opt_part_possible == TRUE) {
opt_parameter_pointer = tvb_get_guint8(message_tvb, offset);
if (opt_parameter_pointer > 0) {
proto_tree_add_uint_format(isup_tree, hf_isup_pointer_to_start_of_optional_part, message_tvb, offset, PARAMETER_POINTER_LENGTH, opt_parameter_pointer, "Pointer to start of optional part: %u", opt_parameter_pointer);
offset += opt_parameter_pointer;
optional_parameter_tvb = tvb_new_subset_remaining(message_tvb, offset);
dissect_isup_optional_parameter(optional_parameter_tvb, pinfo, isup_tree);
}
else
proto_tree_add_uint_format(isup_tree, hf_isup_pointer_to_start_of_optional_part, message_tvb, offset, PARAMETER_POINTER_LENGTH, opt_parameter_pointer, "No optional parameter present (Pointer: %u)", opt_parameter_pointer);
}
else if (message_type != MESSAGE_TYPE_CHARGE_INFO)
proto_tree_add_text(isup_tree, message_tvb, 0, 0, "No optional parameters are possible with this message type");
tap_rec->calling_number=tap_calling_number?tap_calling_number:ep_strdup("");
tap_rec->called_number=tap_called_number;
tap_rec->cause_value=tap_cause_value;
tap_queue_packet(isup_tap, pinfo, tap_rec);
}
static void
dissect_isup(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
switch(mtp3_standard) {
case ANSI_STANDARD:
isup_standard = ANSI_STANDARD;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISUP(ANSI)");
cic = tvb_get_letohs(tvb, CIC_OFFSET) & 0x3FFF;
pinfo->circuit_id = cic;
if (isup_show_cic_in_info) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s (CIC %u) ",
val_to_str_ext_const(message_type, &ansi_isup_message_type_value_acro_ext, "reserved"),
cic);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_ext_const(message_type, &ansi_isup_message_type_value_acro_ext, "reserved"));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_isup, tvb, 0, -1, ENC_NA);
isup_tree = proto_item_add_subtree(ti, ett_isup);
proto_tree_add_uint_format(isup_tree, hf_isup_cic, tvb, CIC_OFFSET, CIC_LENGTH, cic, "CIC: %u", cic);
}
message_tvb = tvb_new_subset_remaining(tvb, CIC_LENGTH);
dissect_ansi_isup_message(message_tvb, pinfo, isup_tree);
break;
default:
isup_standard = ITU_STANDARD;
switch(itu_isup_variant) {
case ISUP_FRENCH_VARIANT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISUP(French)");
used_value_string_ext = &french_isup_message_type_value_acro_ext;
break;
case ISUP_ISRAELI_VARIANT:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISUP(Israeli)");
used_value_string_ext = &israeli_isup_message_type_value_acro_ext;
break;
default:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISUP(ITU)");
used_value_string_ext = &isup_message_type_value_acro_ext;
break;
}
cic = tvb_get_letohs(tvb, CIC_OFFSET) & 0x0FFF;
pinfo->circuit_id = cic;
if (isup_show_cic_in_info) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s (CIC %u) ",
val_to_str_ext_const(message_type, used_value_string_ext, "reserved"),
cic);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_ext_const(message_type, used_value_string_ext, "reserved"));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_isup, tvb, 0, -1, ENC_NA);
isup_tree = proto_item_add_subtree(ti, ett_isup);
proto_tree_add_uint_format(isup_tree, hf_isup_cic, tvb, CIC_OFFSET, CIC_LENGTH, cic, "CIC: %u", cic);
}
message_tvb = tvb_new_subset_remaining(tvb, CIC_LENGTH);
dissect_isup_message(message_tvb, pinfo, isup_tree, itu_isup_variant);
}
}
static void
dissect_bicc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *bicc_tree = NULL;
tvbuff_t *message_tvb;
guint32 bicc_cic;
guint8 message_type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BICC");
message_type = tvb_get_guint8(tvb, BICC_CIC_OFFSET + BICC_CIC_LENGTH);
bicc_cic = tvb_get_letohl(tvb, BICC_CIC_OFFSET);
pinfo->ctype = CT_BICC;
pinfo->circuit_id = bicc_cic;
col_clear(pinfo->cinfo, COL_INFO);
if (isup_show_cic_in_info) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ",
"%s (CIC %u)",
val_to_str_ext_const(message_type, &isup_message_type_value_acro_ext, "reserved"),
bicc_cic);
} else {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ",
"%s",
val_to_str_ext_const(message_type, &isup_message_type_value_acro_ext, "reserved"));
}
if (tree) {
ti = proto_tree_add_item(tree, proto_bicc, tvb, 0, -1, ENC_NA);
bicc_tree = proto_item_add_subtree(ti, ett_bicc);
proto_tree_add_uint_format(bicc_tree, hf_bicc_cic, tvb, BICC_CIC_OFFSET, BICC_CIC_LENGTH, bicc_cic, "CIC: %u", bicc_cic);
}
message_tvb = tvb_new_subset_remaining(tvb, BICC_CIC_LENGTH);
dissect_isup_message(message_tvb, pinfo, bicc_tree, ISUP_ITU_STANDARD_VARIANT);
col_set_fence(pinfo->cinfo, COL_INFO);
}
static void
dissect_application_isup(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *isup_tree = NULL;
tvbuff_t *message_tvb;
guint8 message_type;
gchar *content_type_parameter_str;
guint8 itu_isup_variant = ISUP_ITU_STANDARD_VARIANT;
if(pinfo->private_data) {
content_type_parameter_str = ascii_strdown_inplace(pinfo->private_data);
if(strstr(content_type_parameter_str,"ansi")) {
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
dissect_ansi_isup_message(message_tvb, pinfo, isup_tree);
return;
} else if(strstr(content_type_parameter_str,"spirou")) {
isup_standard = ITU_STANDARD;
itu_isup_variant = ISUP_FRENCH_VARIANT;
} else {
isup_standard = ITU_STANDARD;
}
} else {
isup_standard = ITU_STANDARD;
}
message_type = tvb_get_guint8(tvb, 0);
switch(itu_isup_variant) {
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
dissect_isup_message(message_tvb, pinfo, isup_tree, itu_isup_variant);
}
static void
msg_stats_tree_init(stats_tree* st)
{
st_node_msg = stats_tree_create_node(st, "Messages by Type", 0, TRUE);
st_node_dir = stats_tree_create_node(st, "Messages by Direction", 0, TRUE);
}
static int
msg_stats_tree_packet(stats_tree *st, packet_info *pinfo, epan_dissect_t *edt _U_, const void *p)
{
const gchar *msg = match_strval_ext(((const isup_tap_rec_t*)p)->message_type, &isup_message_type_value_acro_ext);
gchar *dir;
int msg_node;
int dir_node;
dir = ep_strdup_printf("%s->%s", ep_address_to_str(&pinfo->src), ep_address_to_str(&pinfo->dst));
msg_node = tick_stat_node(st, msg, st_node_msg, TRUE);
tick_stat_node(st, dir, msg_node, FALSE);
dir_node = tick_stat_node(st, dir, st_node_dir, TRUE);
tick_stat_node(st, msg, dir_node, FALSE);
return 1;
}
void
proto_register_isup(void)
{
static hf_register_info hf[] = {
{ &hf_isup_cic,
{ "CIC", "isup.cic",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_message_type,
{ "Message Type", "isup.message_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isup_parameter_type,
{ "Parameter Type", "isup.parameter_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
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
FT_BOOLEAN, 8, TFS(&isup_echo_control_device_ind_value),E_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_forw_call_natnl_inatnl_call_indicator,
{ "National/international call indicator", "isup.forw_call_natnl_inatnl_call_indicator",
FT_BOOLEAN, 16, TFS(&isup_natnl_inatnl_call_ind_value),A_16BIT_MASK,
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
FT_UINT8, BASE_DEC, VALS(isup_called_party_address_digit_value), ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK,
NULL, HFILL }},
{ &hf_isup_calling_party_odd_address_signal_digit,
{ "Address signal digit", "isup.calling_party_odd_address_signal_digit",
FT_UINT8, BASE_DEC, VALS(isup_calling_party_address_digit_value), ISUP_ODD_ADDRESS_SIGNAL_DIGIT_MASK,
NULL, HFILL }},
{ &hf_isup_called_party_even_address_signal_digit,
{ "Address signal digit", "isup.called_party_even_address_signal_digit",
FT_UINT8, BASE_DEC, VALS(isup_called_party_address_digit_value), ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK,
NULL, HFILL }},
{ &hf_isup_calling_party_even_address_signal_digit,
{ "Address signal digit", "isup.calling_party_even_address_signal_digit",
FT_UINT8, BASE_DEC, VALS(isup_calling_party_address_digit_value), ISUP_EVEN_ADDRESS_SIGNAL_DIGIT_MASK,
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
{ "Solicited indicator", "isup.solicided_indicator",
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
{ "Event presentation restricted indicator", "isup.event_presentatiation_restr_ind",
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
FT_BOOLEAN, 8, TFS(&isup_connected_line_identity_request_ind_value), H_8BIT_MASK,
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
FT_BOOLEAN, 8, TFS(&isup_Send_notification_ind_value),C_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Discard_message_ind_value,
{ "Discard message indicator","isup.Discard_message_ind_value",
FT_BOOLEAN, 8, TFS(&isup_Discard_message_ind_value), D_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Discard_parameter_ind,
{ "Discard parameter indicator","isup.Discard_parameter_ind",
FT_BOOLEAN, 8, TFS(&isup_Discard_parameter_ind_value), E_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Pass_on_not_possible_indicator,
{ "Pass on not possible indicator", "isup_Pass_on_not_possible_ind",
FT_UINT8, BASE_HEX, VALS(isup_Pass_on_not_possible_indicator_vals),GF_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_pass_on_not_possible_indicator2,
{ "Pass on not possible indicator", "isup_Pass_on_not_possible_val",
FT_BOOLEAN, 8, TFS(&isup_pass_on_not_possible_indicator_value),E_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Broadband_narrowband_interworking_ind,
{ "Broadband narrowband interworking indicator Bits JF", "isup_broadband-narrowband_interworking_ind",
FT_UINT8, BASE_HEX, VALS(ISUP_Broadband_narrowband_interworking_indicator_vals),BA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_Broadband_narrowband_interworking_ind2,
{ "Broadband narrowband interworking indicator Bits GF", "isup_broadband-narrowband_interworking_ind2",
FT_UINT8, BASE_HEX, VALS(ISUP_Broadband_narrowband_interworking_indicator_vals),GF_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_app_cont_ident,
{ "Application context identifier", "isup.app_context_identifier",
FT_UINT16, BASE_DEC, VALS(isup_application_transport_parameter_value),GFEDCBA_8BIT_MASK,
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
FT_UINT8, BASE_DEC, NULL,GFEDCBA_8BIT_MASK,
NULL, HFILL }},
{ &hf_isup_cause_location,
{ "Cause location", "isup.cause_location",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &q931_cause_location_vals_ext, 0x0f,
NULL, HFILL }},
{ &hf_ansi_isup_coding_standard,
{ "Coding standard", "ansi_isup.coding_standard", FT_UINT8, BASE_HEX,
VALS(ansi_isup_coding_standard_vals), 0x60,NULL, HFILL }},
{ &hf_bat_ase_identifier,
{ "BAT ASE Identifiers", "bicc.bat_ase_identifier",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bat_ase_list_of_Identifiers_vals_ext,0x0,
NULL, HFILL }},
{ &hf_length_indicator,
{ "BAT ASE Element length indicator", "bicc.bat_ase_length_indicator",
FT_UINT16, BASE_DEC, NULL,0x0,
NULL, HFILL }},
{ &hf_Action_Indicator,
{ "BAT ASE action indicator field", "bicc.bat_ase_bat_ase_action_indicator_field",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bat_ase_action_indicator_field_vals_ext,0x00,
NULL, HFILL }},
{ &hf_Instruction_ind_for_general_action,
{ "BAT ASE Instruction indicator for general action", "bicc.bat_ase_Instruction_ind_for_general_action",
FT_UINT8, BASE_HEX, VALS(Instruction_indicator_for_general_action_vals),0x03,
NULL, HFILL }},
{ &hf_Send_notification_ind_for_general_action,
{ "Send notification indicator for general action", "bicc.bat_ase_Send_notification_ind_for_general_action",
FT_BOOLEAN, 8, TFS(&isup_Send_notification_ind_value), 0x04,
NULL, HFILL }},
{ &hf_Instruction_ind_for_pass_on_not_possible,
{ "Instruction ind for pass-on not possible", "bicc.bat_ase_Instruction_ind_for_pass_on_not_possible",
FT_UINT8, BASE_HEX, VALS(Instruction_indicator_for_pass_on_not_possible_vals),0x30,
NULL, HFILL }},
{ &hf_Send_notification_ind_for_pass_on_not_possible,
{ "Send notification indication for pass-on not possible", "bicc.bat_ase_Send_notification_ind_for_pass_on_not_possible",
FT_BOOLEAN, 8, TFS(&isup_Send_notification_ind_value), 0x40,
NULL, HFILL }},
{ &hf_BCTP_Version_Indicator,
{ "BCTP Version Indicator", "bicc.bat_ase_BCTP_Version_Indicator",
FT_UINT8, BASE_DEC, NULL,0x1f,
NULL, HFILL }},
{ &hf_BVEI,
{ "BVEI", "bicc.bat_ase_BCTP_BVEI",
FT_BOOLEAN, 8, TFS(&BCTP_BVEI_value), 0x40,
NULL, HFILL }},
{ &hf_Tunnelled_Protocol_Indicator,
{ "Tunnelled Protocol Indicator", "bicc.bat_ase_BCTP_Tunnelled_Protocol_Indicator",
FT_UINT8, BASE_DEC, VALS(BCTP_Tunnelled_Protocol_Indicator_vals),0x3f,
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
{ "Interworking Function Address(X.213 NSAP encoded)", "bat_ase_biwfa",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_afi,
{ "X.213 Address Format Information (AFI)", "x213.afi",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &x213_afi_value_ext,0x0,
NULL, HFILL }},
{ &hf_bicc_nsap_dsp,
{ "X.213 Address Format Information (DSP)", "x213.dsp",
FT_BYTES, BASE_NONE, NULL,0x0,
NULL, HFILL }},
{ &hf_characteristics,
{ "Backbone network connection characteristics", "bat_ase.char",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bearer_network_connection_characteristics_vals_ext,0x0,
NULL, HFILL }},
{ &hf_Organization_Identifier,
{ "Organization identifier subfield", "bat_ase.organization_identifier_subfield",
FT_UINT8, BASE_DEC, VALS(bat_ase_organization_identifier_subfield_vals),0x0,
NULL, HFILL }},
{ &hf_codec_type,
{ "ITU-T codec type subfield", "bat_ase.ITU_T_codec_type_subfield",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ITU_T_codec_type_subfield_vals_ext,0x0,
NULL, HFILL }},
{ &hf_etsi_codec_type,
{ "ETSI codec type subfield", "bat_ase.ETSI_codec_type_subfield",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ETSI_codec_type_subfield_vals_ext,0x0,
NULL, HFILL }},
{ &hf_active_code_set,
{ "Active Code Set", "bat_ase.acs",
FT_UINT8, BASE_HEX, NULL,0x0,
NULL, HFILL }},
{ &hf_active_code_set_12_2,
{ "12.2 kbps rate", "bat_ase.acs.12_2",
FT_UINT8, BASE_HEX, NULL,0x80,
NULL, HFILL }},
{ &hf_active_code_set_10_2,
{ "10.2 kbps rate", "bat_ase.acs.10_2",
FT_UINT8, BASE_HEX, NULL,0x40,
NULL, HFILL }},
{ &hf_active_code_set_7_95,
{ "7.95 kbps rate", "bat_ase.acs.7_95",
FT_UINT8, BASE_HEX, NULL,0x20,
NULL, HFILL }},
{ &hf_active_code_set_7_40,
{ "7.40 kbps rate", "bat_ase.acs.7_40",
FT_UINT8, BASE_HEX, NULL,0x10,
NULL, HFILL }},
{ &hf_active_code_set_6_70,
{ "6.70 kbps rate", "bat_ase.acs.6_70",
FT_UINT8, BASE_HEX, NULL,0x08,
NULL, HFILL }},
{ &hf_active_code_set_5_90,
{ "5.90 kbps rate", "bat_ase.acs.5_90",
FT_UINT8, BASE_HEX, NULL,0x04,
NULL, HFILL }},
{ &hf_active_code_set_5_15,
{ "5.15 kbps rate", "bat_ase.acs.5_15",
FT_UINT8, BASE_HEX, NULL,0x02,
NULL, HFILL }},
{ &hf_active_code_set_4_75,
{ "4.75 kbps rate", "bat_ase.acs.4_75",
FT_UINT8, BASE_HEX, NULL,0x01,
NULL, HFILL }},
{ &hf_supported_code_set,
{ "Supported Code Set", "bat_ase.scs",
FT_UINT8, BASE_HEX, NULL,0x0,
NULL, HFILL }},
{ &hf_supported_code_set_12_2,
{ "12.2 kbps rate", "bat_ase.scs.12_2",
FT_UINT8, BASE_HEX, NULL,0x80,
NULL, HFILL }},
{ &hf_supported_code_set_10_2,
{ "10.2 kbps rate", "bat_ase.scs.10_2",
FT_UINT8, BASE_HEX, NULL,0x40,
NULL, HFILL }},
{ &hf_supported_code_set_7_95,
{ "7.95 kbps rate", "bat_ase.scs.7_95",
FT_UINT8, BASE_HEX, NULL,0x20,
NULL, HFILL }},
{ &hf_supported_code_set_7_40,
{ "7.40 kbps rate", "bat_ase.scs.7_40",
FT_UINT8, BASE_HEX, NULL,0x10,
NULL, HFILL }},
{ &hf_supported_code_set_6_70,
{ "6.70 kbps rate", "bat_ase.scs.6_70",
FT_UINT8, BASE_HEX, NULL,0x08,
NULL, HFILL }},
{ &hf_supported_code_set_5_90,
{ "5.90 kbps rate", "bat_ase.scs.5_90",
FT_UINT8, BASE_HEX, NULL,0x04,
NULL, HFILL }},
{ &hf_supported_code_set_5_15,
{ "5.15 kbps rate", "bat_ase.scs.5_15",
FT_UINT8, BASE_HEX, NULL,0x02,
NULL, HFILL }},
{ &hf_supported_code_set_4_75,
{ "4.75 kbps rate", "bat_ase.scs.4_75",
FT_UINT8, BASE_HEX, NULL,0x01,
NULL, HFILL }},
{ &hf_optimisation_mode,
{ "Optimisation Mode for ACS , OM", "bat_ase.optimisation_mode",
FT_UINT8, BASE_HEX, VALS(optimisation_mode_vals),0x8,
NULL, HFILL }},
{ &hf_max_codec_modes,
{ "Maximal number of Codec Modes, MACS", "bat_ase.macs",
FT_UINT8, BASE_DEC, NULL,0x07,
NULL, HFILL }},
{ &hf_bearer_control_tunneling,
{ "Bearer control tunneling", "bat_ase.bearer_control_tunneling",
FT_BOOLEAN, 8, TFS(&Bearer_Control_Tunnelling_ind_value),0x01,
NULL, HFILL }},
{ &hf_BAT_ASE_Comp_Report_Reason,
{ "Compatibility report reason", "bat_ase.Comp_Report_Reason",
FT_UINT8, BASE_HEX, VALS(BAT_ASE_Report_Reason_vals),0x0,
NULL, HFILL }},
{ &hf_BAT_ASE_Comp_Report_ident,
{ "Bearer control tunneling", "bat_ase.bearer_control_tunneling",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &bat_ase_list_of_Identifiers_vals_ext,0x0,
NULL, HFILL }},
{ &hf_BAT_ASE_Comp_Report_diagnostic,
{ "Diagnostics", "bat_ase.Comp_Report_diagnostic",
FT_UINT16, BASE_HEX, NULL,0x0,
NULL, HFILL }},
{ &hf_Local_BCU_ID,
{ "Local BCU ID", "bat_ase.Local_BCU_ID",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_late_cut_trough_cap_ind,
{ "Late Cut-through capability indicator", "bat_ase.late_cut_trough_cap_ind",
FT_BOOLEAN, 8, TFS(&late_cut_trough_cap_ind_value),0x01,
NULL, HFILL }},
{ &hf_bat_ase_signal,
{ "Q.765.5 - Signal Type", "bat_ase.signal_type",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &BAT_ASE_Signal_Type_vals_ext,0x0,
NULL, HFILL }},
{ &hf_bat_ase_duration,
{ "Duration in ms", "bat_ase.signal_type",
FT_UINT16, BASE_DEC, NULL,0x0,
NULL, HFILL }},
{ &hf_bat_ase_bearer_redir_ind,
{ "Redirection Indicator", "bat_ase.bearer_redir_ind",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &Bearer_Redirection_Indicator_vals_ext,0x0,
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
FT_UINT16, BASE_HEX, VALS(iana_icp_values),0x0,
NULL, HFILL }},
{ &hf_isup_called,
{ "ISUP Called Number", "isup.called",
FT_STRING, BASE_NONE, NULL,0x0,
NULL, HFILL }},
{ &hf_isup_calling,
{ "ISUP Calling Number", "isup.calling",
FT_STRING, BASE_NONE, NULL,0x0,
NULL, HFILL }},
{ &hf_isup_redirecting,
{ "ISUP Redirecting Number", "isup.redirecting",
FT_STRING, BASE_NONE, NULL,0x0,
NULL, HFILL }},
{&hf_isup_apm_msg_fragments,
{"Message fragments", "isup_apm.msg.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{&hf_isup_apm_msg_fragment,
{"Message fragment", "isup_apm.msg.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{&hf_isup_apm_msg_fragment_overlap,
{"Message fragment overlap", "isup_apm.msg.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{&hf_isup_apm_msg_fragment_overlap_conflicts,
{"Message fragment overlapping with conflicting data","isup_apm.msg.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{&hf_isup_apm_msg_fragment_multiple_tails,
{"Message has multiple tail fragments", "isup_apm.msg.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{&hf_isup_apm_msg_fragment_too_long_fragment,
{"Message fragment too long", "isup_apm.msg.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{&hf_isup_apm_msg_fragment_error,
{"Message defragmentation error", "isup_apm.msg.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{&hf_isup_apm_msg_fragment_count,
{"Message fragment count", "isup_apm.msg.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{&hf_isup_apm_msg_reassembled_in,
{"Reassembled in", "isup_apm.msg.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{&hf_isup_apm_msg_reassembled_length,
{"Reassembled ISUP length", "isup_apm.msg.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{&hf_isup_cvr_rsp_ind,
{"CVR Response Ind", "conn_rsp_ind",
FT_UINT8, BASE_DEC, VALS(isup_cvr_rsp_ind_value), BA_8BIT_MASK,
NULL, HFILL }},
{&hf_isup_cvr_cg_car_ind,
{"CVR Circuit Group Carrier","cg_carrier_ind",
FT_UINT8, BASE_HEX, VALS(isup_cvr_cg_car_ind_value), BA_8BIT_MASK,
NULL, HFILL }},
{&hf_isup_cvr_cg_double_seize,
{"Double Seize Control", "cg_char_ind.doubleSeize",
FT_UINT8, BASE_HEX, VALS(isup_cvr_cg_double_seize_value), DC_8BIT_MASK,
NULL, HFILL }},
{&hf_isup_cvr_cg_alarm_car_ind,
{"Alarm Carrier Indicator", "cg_alarm_car_ind",
FT_UINT8, BASE_HEX, VALS(isup_cvr_alarm_car_ind_value), FE_8BIT_MASK,
NULL, HFILL }},
{&hf_isup_cvr_cont_chk_ind,
{"Continuity Check Indicator","cg_alarm_cnt_chk",
FT_UINT8, BASE_HEX, VALS(isup_cvr_cont_chk_ind_value), HG_8BIT_MASK,
NULL,HFILL }},
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
FT_UINT8, BASE_DEC, VALS(israeli_time_indicators), 0x0,
NULL, HFILL }},
{ &hf_isup_israeli_next_rate,
{ "Next Rate", "isup.israeli.next_ratej",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_isup,
&ett_isup_parameter,
&ett_isup_address_digits,
&ett_isup_pass_along_message,
&ett_isup_circuit_state_ind,
&ett_bat_ase,
&ett_bat_ase_element,
&ett_bat_ase_iwfa,
&ett_scs,
&ett_acs,
&ett_isup_apm_msg_fragment,
&ett_isup_apm_msg_fragments,
};
static enum_val_t isup_variants[] = {
{"ITU Standard", "ITU Standard", ISUP_ITU_STANDARD_VARIANT},
{"French national Standard", "French national Standard", ISUP_FRENCH_VARIANT},
{"Israeli national Standard", "Israeli national Standard", ISUP_ISRAELI_VARIANT},
{NULL, NULL, -1}
};
proto_isup = proto_register_protocol("ISDN User Part",
"ISUP", "isup");
register_dissector("isup", dissect_isup, proto_isup);
proto_register_field_array(proto_isup, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
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
dissector_handle_t isup_handle;
dissector_handle_t application_isup_handle;
isup_handle = create_dissector_handle(dissect_isup, proto_isup);
application_isup_handle = create_dissector_handle(dissect_application_isup, proto_isup);
dissector_add_uint("mtp3.service_indicator", MTP_SI_ISUP, isup_handle);
dissector_add_string("media_type","application/isup", application_isup_handle);
dissector_add_string("tali.opcode", "isot", isup_handle);
}
void
proto_register_bicc(void)
{
static hf_register_info hf[] = {
{ &hf_bicc_cic,
{ "Call identification Code (CIC)", "bicc.cic",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_bicc
};
proto_bicc = proto_register_protocol("Bearer Independent Call Control",
"BICC", "bicc");
register_dissector("bicc", dissect_bicc, proto_bicc);
proto_register_field_array(proto_bicc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(isup_apm_defragment_init);
}
void
proto_reg_handoff_bicc(void)
{
dissector_handle_t bicc_handle;
sdp_handle = find_dissector("sdp");
q931_ie_handle = find_dissector("q931.ie");
bicc_handle = create_dissector_handle(dissect_bicc, proto_bicc);
dissector_add_uint("mtp3.service_indicator", MTP_SI_BICC, bicc_handle);
dissector_add_uint("sctp.ppi", BICC_PAYLOAD_PROTOCOL_ID, bicc_handle);
}
