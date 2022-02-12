static void
dissect_q931_segmented_message_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len != 2) {
proto_tree_add_text(tree, tvb, offset, len,
"Segmented message: length is %d, should be 2", len);
return;
}
if (tvb_get_guint8(tvb, offset) & 0x80) {
proto_tree_add_text(tree, tvb, offset, 1,
"First segment: %u segments remaining",
tvb_get_guint8(tvb, offset) & 0x7F);
} else {
proto_tree_add_text(tree, tvb, offset, 1,
"Not first segment: %u segments remaining",
tvb_get_guint8(tvb, offset) & 0x7F);
}
proto_tree_add_item(tree, hf_q931_segment_type, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_protocol_discriminator(tvbuff_t *tvb, int offset, proto_tree *tree)
{
unsigned int discriminator = tvb_get_guint8(tvb, offset);
if (discriminator == NLPID_DMS) {
proto_tree_add_uint_format(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"Protocol discriminator: Maintenance messages");
} else if (discriminator == NLPID_Q_931) {
proto_tree_add_uint_format(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"Protocol discriminator: Q.931");
} else if (discriminator == NLPID_Q_2931) {
proto_tree_add_uint_format(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"Protocol discriminator: Q.2931");
} else if ((discriminator >= 16 && discriminator < 63)
|| ((discriminator >= 80) && (discriminator < 254))) {
proto_tree_add_uint_format(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"Protocol discriminator: Network layer or layer 3 protocol (0x%02X)",
discriminator);
} else if (discriminator >= 64 && discriminator <= 79) {
proto_tree_add_uint_format(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"Protocol discriminator: National use (0x%02X)",
discriminator);
} else {
proto_tree_add_uint_format(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"Protocol discriminator: Reserved (0x%02X)",
discriminator);
}
}
void
dissect_q931_bearer_capability_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
guint8 it_rate;
guint8 modem_type;
guint8 uil2_protocol;
guint8 uil3_protocol;
guint8 add_l3_info;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
if (coding_standard != Q931_ITU_STANDARDIZED_CODING) {
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
return;
}
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_information_transfer_capability, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (!(octet & Q931_IE_VL_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Out-band negotiation %spossible",
(octet & 0x40) ? "" : "not ");
offset += 1;
len -= 1;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_transfer_mode, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_information_transfer_rate, tvb, offset, 1, octet);
it_rate = octet & 0x1F;
offset += 1;
len -= 1;
if (it_rate == Q931_IT_RATE_MULTIRATE) {
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, 1, "Rate multiplier: %u", tvb_get_guint8(tvb, offset) & 0x7f);
offset += 1;
len -= 1;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0x60) == 0x20) {
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_layer_ident, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_uil1, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Layer 1 is %s",
(octet & 0x40) ? "Asynchronous" : "Synchronous");
proto_tree_add_text(tree, tvb, offset, 1,
"Layer 1 in-band negotiation is %spossible",
(octet & 0x20) ? "" : "not ");
proto_tree_add_text(tree, tvb, offset, 1,
"User rate: %s",
val_to_str_ext(octet & 0x1F, &q931_l1_user_rate_vals_ext,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Intermediate rate: %s",
val_to_str(octet & 0x60, q931_l1_intermediate_rate_vals,
"Unknown (0x%X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"%s to send data with network independent clock",
(octet & 0x10) ? "Required" : "Not required");
proto_tree_add_text(tree, tvb, offset, 1,
"%s accept data with network independent clock",
(octet & 0x08) ? "Can" : "Cannot");
proto_tree_add_text(tree, tvb, offset, 1,
"%s to send data with flow control mechanism",
(octet & 0x04) ? "Required" : "Not required");
proto_tree_add_text(tree, tvb, offset, 1,
"%s accept data with flow control mechanism",
(octet & 0x02) ? "Can" : "Cannot");
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Rate adaption header %sincluded",
(octet & 0x40) ? "" : "not ");
proto_tree_add_text(tree, tvb, offset, 1,
"Multiple frame establishment %ssupported",
(octet & 0x20) ? "" : "not ");
proto_tree_add_text(tree, tvb, offset, 1,
"%s mode of operation",
(octet & 0x10) ? "Protocol sensitive" : "Bit transparent");
proto_tree_add_text(tree, tvb, offset, 1,
(octet & 0x08) ?
"Full protocol negotiation" : "LLI = 256 only");
proto_tree_add_text(tree, tvb, offset, 1,
"Message originator is %s",
(octet & 0x04) ? "Assignor only" : "Default assignee");
proto_tree_add_text(tree, tvb, offset, 1,
"Negotiation is done %s",
(octet & 0x02) ? "in-band" : "out-of-band");
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Stop bits: %s",
val_to_str(octet & 0x60, q931_l1_stop_bits_vals,
"Unknown (0x%X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Data bits: %s",
val_to_str(octet & 0x18, q931_l1_data_bits_vals,
"Unknown (0x%X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Parity: %s",
val_to_str(octet & 0x07, q931_l1_parity_vals,
"Unknown (0x%X)"));
if (octet & Q931_IE_VL_EXTENSION)
goto l1_done;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"%s duplex",
(octet & 0x40) ? "Full" : "Half");
modem_type = octet & 0x3F;
if (modem_type <= 0x5 ||
(modem_type >= 0x20 && modem_type <= 0x2F)) {
proto_tree_add_text(tree, tvb, offset, 1,
"Modem type: National use 0x%02X", modem_type);
} else if (modem_type >= 0x30) {
proto_tree_add_text(tree, tvb, offset, 1,
"Modem type: User specified 0x%02X", modem_type);
} else {
proto_tree_add_text(tree, tvb, offset, 1,
"Modem type: %s",
val_to_str_ext(modem_type, &q931_l1_modem_type_vals_ext,
"Unknown (0x%02X)"));
}
offset += 1;
len -= 1;
}
l1_done:
;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0x60) == 0x40) {
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_layer_ident, tvb, offset, 1, octet);
uil2_protocol = octet & 0x1F;
proto_tree_add_text(tree, tvb, offset, 1,
"User information layer 2 protocol: %s",
val_to_str_ext(uil2_protocol, &q931_uil2_vals_ext,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l2_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if (uil2_protocol == Q931_UIL2_USER_SPEC) {
proto_tree_add_text(tree, tvb, offset, 1,
"User-specified layer 2 protocol information: 0x%02X",
octet & 0x7F);
} else {
proto_tree_add_text(tree, tvb, offset, 1,
"Mode: %s",
val_to_str(octet & 0x60, q931_mode_vals,
"Unknown (0x%02X)"));
}
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l2_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Window size: %u k", octet & 0x7F);
offset += 1;
len -= 1;
}
l2_done:
;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0x60) == 0x60) {
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_layer_ident, tvb, offset, 1, octet);
uil3_protocol = octet & 0x1F;
proto_tree_add_text(tree, tvb, offset, 1,
"User information layer 3 protocol: %s",
val_to_str(uil3_protocol, q931_uil3_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
switch (uil3_protocol) {
case Q931_UIL3_X25_PL:
case Q931_UIL3_ISO_8208:
case Q931_UIL3_X223:
proto_tree_add_text(tree, tvb, offset, 1,
"Mode: %s",
val_to_str(octet & 0x60, q931_mode_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Default packet size: %u", octet & 0x0F);
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Packet window size: %u", octet & 0x7F);
break;
case Q931_UIL3_USER_SPEC:
proto_tree_add_text(tree, tvb, offset, 1,
"Default packet size: %u octets",
1 << (octet & 0x0F));
break;
case Q931_UIL3_TR_9577:
add_l3_info = (octet & 0x0F) << 4;
if (octet & Q931_IE_VL_EXTENSION)
goto l3_done;
if (len < 2)
return;
octet = tvb_get_guint8(tvb, offset + 1);
add_l3_info |= (octet & 0x0F);
proto_tree_add_text(tree, tvb, offset, 2,
"Additional layer 3 protocol information: %s",
val_to_str(add_l3_info, nlpid_vals,
"Unknown (0x%02X)"));
break;
}
}
l3_done:
;
}
static const gchar *get_message_name(guint8 prot_discr, guint8 message_type) {
if (prot_discr == NLPID_DMS)
return val_to_str(message_type, dms_message_type_vals, "Unknown (0x%02X)");
else
return val_to_str_ext(message_type, &q931_message_type_vals_ext, "Unknown (0x%02X)");
}
static void
dissect_q931_cause_ie_unsafe(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, int hf_cause_value, guint8 *cause_value, const value_string *ie_vals)
{
guint8 octet;
guint8 coding_standard;
guint8 rejection_reason;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
if (coding_standard != Q931_ITU_STANDARDIZED_CODING) {
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
return;
}
proto_tree_add_uint(tree, hf_q931_cause_location, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (!(octet & Q931_IE_VL_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Recommendation: %s",
val_to_str(octet & 0x7F, q931_cause_recommendation_vals,
"Unknown (0x%02X)"));
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
*cause_value = octet & 0x7F;
if(have_valid_q931_pi) {
q931_pi->cause_value = *cause_value;
}
proto_tree_add_uint(tree, hf_cause_value, tvb, offset, 1, *cause_value);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (len == 0)
return;
switch (*cause_value) {
case Q931_CAUSE_UNALLOC_NUMBER:
case Q931_CAUSE_NO_ROUTE_TO_DEST:
case Q931_CAUSE_QOS_UNAVAILABLE:
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Network service: %s",
(octet & 0x80) ? "User" : "Provider");
proto_tree_add_text(tree, tvb, offset, 1,
"%s",
(octet & 0x40) ? "Abnormal" : "Normal");
proto_tree_add_text(tree, tvb, offset, 1,
"Condition: %s",
val_to_str(octet & 0x03, q931_cause_condition_vals,
"Unknown (0x%X)"));
break;
case Q931_CAUSE_CALL_REJECTED:
rejection_reason = octet & 0x7C;
proto_tree_add_text(tree, tvb, offset, 1,
"Rejection reason: %s",
val_to_str(octet & 0x7C, q931_rejection_reason_vals,
"Unknown (0x%X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Condition: %s",
val_to_str(octet & 0x03, q931_cause_condition_vals,
"Unknown (0x%X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
switch (rejection_reason) {
case Q931_REJ_USER_SPECIFIC:
proto_tree_add_text(tree, tvb, offset, len,
"User specific diagnostic: %s",
tvb_bytes_to_str(tvb, offset, len));
break;
case Q931_REJ_IE_MISSING:
proto_tree_add_text(tree, tvb, offset, 1,
"Missing information element: %s",
val_to_str(tvb_get_guint8(tvb, offset), ie_vals,
"Unknown (0x%02X)"));
break;
case Q931_REJ_IE_INSUFFICIENT:
proto_tree_add_text(tree, tvb, offset, 1,
"Insufficient information element: %s",
val_to_str(tvb_get_guint8(tvb, offset), ie_vals,
"Unknown (0x%02X)"));
break;
default:
proto_tree_add_text(tree, tvb, offset, len,
"Diagnostic: %s",
tvb_bytes_to_str(tvb, offset, len));
break;
}
break;
case Q931_CAUSE_ACCESS_INFO_DISC:
case Q931_CAUSE_INCOMPATIBLE_DEST:
case Q931_CAUSE_MAND_IE_MISSING:
case Q931_CAUSE_IE_NONEX_OR_UNIMPL:
case Q931_CAUSE_INVALID_IE_CONTENTS:
do {
proto_tree_add_text(tree, tvb, offset, 1,
"Information element: %s",
val_to_str(tvb_get_guint8(tvb, offset), ie_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
} while (len != 0);
break;
case Q931_CAUSE_MT_NONEX_OR_UNIMPL:
case Q931_CAUSE_MSG_INCOMPAT_W_CS:
proto_tree_add_text(tree, tvb, offset, 1,
"Message type: %s",
val_to_str_ext(tvb_get_guint8(tvb, offset), &q931_message_type_vals_ext,
"Unknown (0x%02X)"));
break;
case Q931_CAUSE_REC_TIMER_EXP:
if (len < 3)
return;
proto_tree_add_text(tree, tvb, offset, 3,
"Timer: %.3s", tvb_get_ephemeral_string(tvb, offset, 3));
break;
default:
proto_tree_add_text(tree, tvb, offset, len,
"Diagnostics: %s",
tvb_bytes_to_str(tvb, offset, len));
}
}
void
dissect_q931_cause_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, int hf_cause_value, guint8 *cause_value, const value_string *ie_vals)
{
gboolean have_valid_q931_pi_save = have_valid_q931_pi;
have_valid_q931_pi = FALSE;
dissect_q931_cause_ie_unsafe(tvb, offset, len, tree, hf_cause_value, cause_value, ie_vals);
have_valid_q931_pi = have_valid_q931_pi_save;
}
static void
dissect_q931_change_status_ie(tvbuff_t *tvb, int offset, int len _U_, proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_extension_ind_preference, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_extension_ind_new_status, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_call_state_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
if (coding_standard != Q931_ITU_STANDARDIZED_CODING) {
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
return;
}
proto_tree_add_text(tree, tvb, offset, 1,
"Call state: %s",
val_to_str_ext(octet & 0x3F, &q931_call_state_vals_ext,
"Unknown (0x%02X)"));
}
static void
dissect_q931_channel_identification_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_channel_interface_explicit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_channel_interface_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_channel_exclusive, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_channel_dchan, tvb, offset, 1, ENC_BIG_ENDIAN);
if (octet & Q931_NOT_BASIC_CHANNEL) {
proto_tree_add_item(tree, hf_q931_channel_selection_pri, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_q931_channel_selection_bri, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
len -= 1;
if (octet & Q931_INTERFACE_IDENTIFIED) {
guint8 octet2;
guint32 identifier_val = 0;
int identifier_offset = offset;
int identifier_len = 0;
do {
if (len == 0)
break;
octet2 = tvb_get_guint8(tvb, offset);
offset += 1;
len -= 1;
identifier_len++;
identifier_val <<= 7;
identifier_val |= octet2 & 0x7F;
} while (!(octet2 & Q931_IE_VL_EXTENSION));
if (identifier_len != 0) {
proto_tree_add_text(tree, tvb, identifier_offset,
identifier_len, "Interface ID: %u", identifier_val);
}
}
if (octet & Q931_NOT_BASIC_CHANNEL) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
if (coding_standard != Q931_ITU_STANDARDIZED_CODING) {
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
return;
}
proto_tree_add_item(tree, hf_q931_channel_map, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_channel_element_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q931_IS_SLOT_MAP) {
guint8 octet2;
while (len) {
octet2 = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Slot map: 0x%02x", octet2);
offset += 1;
len -= 1;
}
} else {
guint8 octet2;
do {
if (len == 0)
break;
octet2 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_q931_channel_number,tvb,offset,1,ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
} while (!(octet2 & Q931_IE_VL_EXTENSION));
}
}
}
void
dissect_q931_progress_indicator_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
if (coding_standard != Q931_ITU_STANDARDIZED_CODING) {
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
return;
}
proto_tree_add_text(tree, tvb, offset, 1,
"Location: %s",
val_to_str_ext(octet & 0x0F, &q931_cause_location_vals_ext,
"Unknown (0x%X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Progress description: %s",
val_to_str_ext(octet & 0x7F, &q931_progress_description_vals_ext,
"Unknown (0x%02X)"));
}
static void
dissect_q931_ns_facilities_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
int netid_len;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
netid_len = octet & 0x7F;
proto_tree_add_text(tree, tvb, offset, 1,
"Network identification length: %u",
netid_len);
offset += 1;
len -= 1;
if (netid_len != 0) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Type of network identification: %s",
val_to_str(octet & 0x70, q931_netid_type_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Network identification plan: %s",
val_to_str(octet & 0x0F, q931_netid_plan_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
netid_len--;
if (len == 0)
return;
if (netid_len > len)
netid_len = len;
if (netid_len != 0) {
proto_tree_add_text(tree, tvb, offset, netid_len,
"Network identification: %s",
tvb_format_text(tvb, offset, netid_len));
offset += netid_len;
len -= netid_len;
}
}
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset,
len, "Network-specific facility specification: %s",
tvb_bytes_to_str(tvb, offset, len));
}
static void
dissect_q931_notification_indicator_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Notification description: %s",
val_to_str(octet & 0x7F, q931_notification_description_vals,
"Unknown (0x%02X)"));
}
static void
dissect_q931_date_time_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 6) {
proto_tree_add_text(tree, tvb, offset, 6,
"Date/time: %02u-%02u-%02u %02u:%02u:%02u",
tvb_get_guint8(tvb, offset + 0), tvb_get_guint8(tvb, offset + 1), tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3), tvb_get_guint8(tvb, offset + 4), tvb_get_guint8(tvb, offset + 5));
} else if (len == 5) {
proto_tree_add_text(tree, tvb, offset, 5,
"Date/time: %02u-%02u-%02u %02u:%02u:00",
tvb_get_guint8(tvb, offset + 0), tvb_get_guint8(tvb, offset + 1), tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3), tvb_get_guint8(tvb, offset + 4));
} else {
proto_tree_add_text(tree, tvb, offset, len,
"Date/time: length is %d, should be 5 or 6", len);
}
}
static void
dissect_q931_signal_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len != 1) {
proto_tree_add_text(tree, tvb, offset, len,
"Signal: length is %d, should be 1", len);
return;
}
proto_tree_add_text(tree, tvb, offset, 1,
"Signal: %s",
val_to_str_ext(tvb_get_guint8(tvb, offset), &q931_signal_vals_ext,
"Unknown (0x%02X)"));
}
static void
dissect_q931_information_rate_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len != 4) {
proto_tree_add_text(tree, tvb, offset, len,
"Information rate: length is %d, should be 4", len);
return;
}
proto_tree_add_text(tree, tvb, offset + 0, 1,
"Incoming information rate: %s",
val_to_str_ext(tvb_get_guint8(tvb, offset + 0) & 0x1F,
&q931_throughput_class_vals_ext, "Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset + 1, 1,
"Outgoing information rate: %s",
val_to_str_ext(tvb_get_guint8(tvb, offset + 1) & 0x1F,
&q931_throughput_class_vals_ext, "Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset + 2, 1,
"Minimum incoming information rate: %s",
val_to_str_ext(tvb_get_guint8(tvb, offset + 2) & 0x1F,
&q931_throughput_class_vals_ext, "Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset + 3, 1,
"Minimum outgoing information rate: %s",
val_to_str_ext(tvb_get_guint8(tvb, offset + 3) & 0x1F,
&q931_throughput_class_vals_ext, "Unknown (0x%02X)"));
}
static int
dissect_q931_guint16_value(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, const char *label)
{
guint8 octet;
guint16 value;
int value_len;
value_len = 0;
octet = tvb_get_guint8(tvb, offset);
if (octet & Q931_IE_VL_EXTENSION) {
goto bad_length;
}
value = (octet & 0x3) << 14;
offset += 1;
len -= 1;
value_len++;
if (len == 0) {
goto past_end;
}
octet = tvb_get_guint8(tvb, offset);
if (octet & Q931_IE_VL_EXTENSION) {
goto bad_length;
}
value |= (octet & 0x7F) << 7;
offset += 1;
len -= 1;
value_len++;
if (len == 0) {
goto past_end;
}
octet = tvb_get_guint8(tvb, offset);
if (!(octet & Q931_IE_VL_EXTENSION)) {
goto bad_length;
}
value |= (octet & 0x7F);
offset += 1;
value_len++;
proto_tree_add_text(tree, tvb, offset, value_len, "%s: %u ms", label,
value);
return value_len;
past_end:
proto_tree_add_text(tree, tvb, offset, len,
"%s goes past end of information element", label);
return -1;
bad_length:
proto_tree_add_text(tree, tvb, offset, len, "%s isn't 3 octets long",
label);
return -1;
}
static void
dissect_q931_e2e_transit_delay_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
int value_len;
if (len == 0)
return;
value_len = dissect_q931_guint16_value(tvb, offset, len, tree,
"Cumulative transit delay");
if (value_len < 0)
return;
offset += value_len;
len -= value_len;
if (len == 0)
return;
value_len = dissect_q931_guint16_value(tvb, offset, len, tree,
"Requested end-to-end transit delay");
if (value_len < 0)
return;
offset += value_len;
len -= value_len;
if (len == 0)
return;
dissect_q931_guint16_value(tvb, offset, len, tree,
"Maximum end-to-end transit delay");
}
static void
dissect_q931_td_selection_and_int_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
dissect_q931_guint16_value(tvb, offset, len, tree,
"Transit delay");
}
static void
dissect_q931_pl_binary_parameters_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Fast select: %s",
val_to_str(octet & 0x18, q931_fast_selected_vals, "Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"%s",
(octet & 0x04) ? "No request/request denied" :
"Request indicated/request accepted");
proto_tree_add_text(tree, tvb, offset, 1,
"%s confirmation",
(octet & 0x02) ? "Link-by-link" : "End-to-end");
proto_tree_add_text(tree, tvb, offset, 1,
"Modulus %u sequencing",
(octet & 0x01) ? 8 : 128);
}
static void
dissect_q931_pl_window_size_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, 1,
"Forward value: %u", tvb_get_guint8(tvb, offset) & 0x7F);
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, 1,
"Backward value: %u", tvb_get_guint8(tvb, offset) & 0x7F);
}
static void
dissect_q931_packet_size_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, 1,
"Forward value: %u", tvb_get_guint8(tvb, offset) & 0x7F);
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, 1,
"Backward value: %u", tvb_get_guint8(tvb, offset) & 0x7F);
}
static void
dissect_q931_cug_ie(tvbuff_t *tvb, int offset, int len, proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, 1,
"CUG indication: %s",
val_to_str(tvb_get_guint8(tvb, offset) & 0x07,
q931_cug_indication_vals, "Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, len, "CUG index code: %s",
tvb_format_text(tvb, offset, len));
}
static void
dissect_q931_reverse_charge_ind_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, 1,
"Reverse charging indication: %s",
val_to_str(tvb_get_guint8(tvb, offset) & 0x07,
q931_reverse_charging_indication_vals, "Unknown (0x%02X)"));
}
static void
dissect_q931_number_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, int hfindex, e164_info_t e164_info)
{
guint8 octet;
gint number_plan;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
number_plan = octet & 0x0f;
e164_info.nature_of_address = ( octet & 0x70 ) >> 4;
proto_tree_add_uint(tree, hf_q931_numbering_plan, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_number_type, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (!(octet & Q931_IE_VL_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_q931_screening_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_presentation_ind, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
}
if (!(octet & Q931_IE_VL_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Reason for redirection: %s",
val_to_str(octet & 0x0F, q931_redirection_reason_vals,
"Unknown (0x%X)"));
offset += 1;
len -= 1;
}
if (len == 0)
return;
proto_tree_add_item(tree, hfindex, tvb, offset, len, ENC_ASCII|ENC_NA);
proto_item_append_text(proto_tree_get_parent(tree), ": '%s'", tvb_format_text(tvb, offset, len));
if ( number_plan == 1 ) {
if ( e164_info.e164_number_type != NONE ){
e164_info.E164_number_str = tvb_get_ephemeral_string(tvb, offset, len);
e164_info.E164_number_length = len;
dissect_e164_number(tvb, tree, offset, len, e164_info);
}
}
if ( e164_info.e164_number_type == CALLING_PARTY_NUMBER && have_valid_q931_pi)
q931_pi->calling_number = tvb_get_ephemeral_string(tvb, offset, len);
if ( e164_info.e164_number_type == CALLED_PARTY_NUMBER && have_valid_q931_pi)
q931_pi->called_number = tvb_get_ephemeral_string(tvb, offset, len);
}
static void
dissect_q931_party_subaddr_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Type of subaddress: %s",
val_to_str(octet & 0x70, q931_subaddress_type_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Odd/even indicator: %s",
val_to_str(octet & 0x08, q931_odd_even_indicator_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, len, "Subaddress: %s",
tvb_bytes_to_str(tvb, offset, len));
}
static void
dissect_q931_restart_indicator_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len != 1) {
proto_tree_add_text(tree, tvb, offset, len,
"Restart indicator: length is %d, should be 1", len);
return;
}
proto_tree_add_text(tree, tvb, offset, 1,
"Restart indicator: %s",
val_to_str(tvb_get_guint8(tvb, offset) & 0x07,
q931_restart_indicator_class_vals, "Unknown (0x%02X)"));
}
void
dissect_q931_high_layer_compat_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
guint8 pres_method;
guint8 characteristics;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
pres_method = octet & 0x03;
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_interpretation, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_pres_meth_prot_prof, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if ((coding_standard != Q931_ITU_STANDARDIZED_CODING) || (pres_method != Q931_HIGH_LAYER_PROTOCOL_PROFILE)) {
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
return;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
characteristics = octet & 0x7F;
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_q931_high_layer_characteristics, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (!(octet & Q931_IE_VL_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((characteristics == Q931_AUDIOVISUAL) || (characteristics == 0x61) || (characteristics == 0x62) ||
(characteristics == 0x68)) {
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_q931_extended_audiovisual_characteristics, tvb, offset, 1, octet);
}
else if ((characteristics == Q931_MANAGEMENT) || (characteristics == Q931_MAINTENANCE)) {
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_q931_extended_high_layer_characteristics, tvb, offset, 1, octet);
}
}
}
void
dissect_q931_user_user_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree)
{
guint8 octet;
tvbuff_t *next_tvb = NULL;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Protocol discriminator: %s",
val_to_str_ext(octet, &q931_protocol_discriminator_vals_ext,
"Unknown (0x%02x)"));
offset += 1;
len -= 1;
if (len == 0)
return;
switch (octet) {
case Q931_PROTOCOL_DISCRIMINATOR_USER:
next_tvb = tvb_new_subset(tvb, offset, len, len);
proto_tree_add_text(tree, tvb, offset, len, "User information: %d octets", len);
if (!dissector_try_heuristic(q931_user_heur_subdissector_list, next_tvb, pinfo, tree, NULL)) {
call_dissector_only(data_handle, next_tvb, pinfo, tree, NULL);
}
break;
case Q931_PROTOCOL_DISCRIMINATOR_IA5:
proto_tree_add_text(tree, tvb, offset, len, "User information: %s",
tvb_format_text(tvb, offset, len));
break;
default:
proto_tree_add_text(tree, tvb, offset, len, "User information: %s",
tvb_bytes_to_str(tvb, offset, len));
break;
}
}
static void
dissect_q931_party_category_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Party category: %s",
val_to_str(octet&0x07, q931_party_category_vals,
"Unknown (0x%02x)"));
len -= 1;
if (len == 0)
return;
}
static void
dissect_q931_ia5_ie(tvbuff_t *tvb, int offset, int len, proto_tree *tree,
const char *label)
{
if (len != 0) {
proto_tree_add_text(tree, tvb, offset, len, "%s: %s", label,
tvb_format_text(tvb, offset, len));
proto_item_append_text(proto_tree_get_parent(tree), " '%s'", tvb_format_text(tvb, offset, len));
}
}
static void
dissect_q931_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean is_over_ip)
{
int offset = 0;
proto_tree *q931_tree = NULL;
proto_tree *ie_tree = NULL;
proto_item *ti, *ti_ie;
guint8 prot_discr;
guint8 call_ref_len;
guint8 call_ref[15];
guint32 call_ref_val;
guint8 message_type, segmented_message_type;
guint8 info_element;
guint16 info_element_len;
gboolean first_frag, more_frags;
guint32 frag_len;
fragment_data *fd_head;
tvbuff_t *next_tvb = NULL;
q931_pi=ep_new(q931_packet_info);
reset_q931_packet_info(q931_pi);
have_valid_q931_pi=TRUE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Q.931");
prot_discr = tvb_get_guint8(tvb, offset);
if (tree) {
ti = proto_tree_add_item(tree, proto_q931, tvb, offset, -1,
ENC_NA);
q931_tree = proto_item_add_subtree(ti, ett_q931);
dissect_q931_protocol_discriminator(tvb, offset, q931_tree);
}
offset += 1;
call_ref_len = tvb_get_guint8(tvb, offset) & 0xF;
if (q931_tree != NULL)
proto_tree_add_uint(q931_tree, hf_q931_call_ref_len, tvb, offset, 1, call_ref_len);
offset += 1;
switch (call_ref_len) {
case 0: call_ref_val = 0; break;
case 1: call_ref_val = tvb_get_guint8(tvb, offset); break;
case 2: call_ref_val = tvb_get_ntohs(tvb, offset); break;
case 3: call_ref_val = tvb_get_ntoh24(tvb, offset); break;
default: call_ref_val = tvb_get_ntohl(tvb, offset);
}
if (call_ref_len != 0) {
tvb_memcpy(tvb, call_ref, offset, call_ref_len);
if (q931_tree != NULL) {
proto_tree_add_boolean(q931_tree, hf_q931_call_ref_flag,
tvb, offset, 1, (call_ref[0] & 0x80) != 0);
call_ref[0] &= 0x7F;
proto_tree_add_bytes(q931_tree, hf_q931_call_ref,
tvb, offset, call_ref_len, call_ref);
} else
{
call_ref[0] &= 0x7F;
}
memcpy(&(q931_pi->crv), call_ref, call_ref_len > sizeof(q931_pi->crv) ? sizeof(q931_pi->crv) : call_ref_len );
offset += call_ref_len;
}
message_type = tvb_get_guint8(tvb, offset);
if(have_valid_q931_pi) {
q931_pi->message_type = message_type;
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO, get_message_name(prot_discr, message_type));
}
if (q931_tree != NULL){
if (prot_discr == NLPID_DMS)
proto_tree_add_item(q931_tree, hf_q931_maintenance_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(q931_tree, hf_q931_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
if ((message_type != Q931_SEGMENT) || !q931_reassembly ||
(tvb_reported_length_remaining(tvb, offset) <= 4)) {
dissect_q931_IEs(tvb, pinfo, tree, q931_tree, is_over_ip, offset, 0);
return;
}
info_element = tvb_get_guint8(tvb, offset);
info_element_len = tvb_get_guint8(tvb, offset + 1);
if ((info_element != Q931_IE_SEGMENTED_MESSAGE) || (info_element_len < 2)) {
dissect_q931_IEs(tvb, pinfo, tree, q931_tree, is_over_ip, offset, 0);
return;
}
ti_ie = proto_tree_add_text(q931_tree, tvb, offset, 1+1+info_element_len, "%s",
val_to_str(info_element, q931_info_element_vals[0], "Unknown information element (0x%02X)"));
ie_tree = proto_item_add_subtree(ti_ie, ett_q931_ie);
proto_tree_add_text(ie_tree, tvb, offset, 1, "Information element: %s",
val_to_str(info_element, q931_info_element_vals[0], "Unknown (0x%02X)"));
proto_tree_add_text(ie_tree, tvb, offset + 1, 1, "Length: %u", info_element_len);
dissect_q931_segmented_message_ie(tvb, offset + 2, info_element_len, ie_tree);
first_frag = (tvb_get_guint8(tvb, offset + 2) & 0x80) != 0;
more_frags = (tvb_get_guint8(tvb, offset + 2) & 0x7F) != 0;
segmented_message_type = tvb_get_guint8(tvb, offset + 3);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " of %s",
val_to_str_ext(segmented_message_type, &q931_message_type_vals_ext, "Unknown message type (0x%02X)"));
}
offset += 1 + 1 + info_element_len;
frag_len = tvb_reported_length_remaining(tvb, offset);
if (first_frag && fragment_get(&q931_reassembly_table, pinfo, call_ref_val, NULL)) {
fragment_end_seq_next(&q931_reassembly_table, pinfo, call_ref_val, NULL);
}
fd_head = fragment_add_seq_next(&q931_reassembly_table,
tvb, offset, pinfo, call_ref_val, NULL,
frag_len, more_frags);
if (fd_head) {
if (pinfo->fd->num == fd_head->reassembled_in) {
if (fd_head->next != NULL) {
next_tvb = tvb_new_child_real_data(tvb, fd_head->data, fd_head->len, fd_head->len);
add_new_data_source(pinfo, next_tvb, "Reassembled Q.931 IEs");
if (tree) {
proto_item *frag_tree_item;
show_fragment_seq_tree(fd_head, &q931_frag_items, q931_tree, pinfo, next_tvb, &frag_tree_item);
}
} else {
next_tvb = tvb_new_subset_remaining(tvb, offset);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s [reassembled]",
val_to_str_ext(segmented_message_type, &q931_message_type_vals_ext, "Unknown message type (0x%02X)"));
}
} else {
if (tree) proto_tree_add_uint(q931_tree, hf_q931_reassembled_in, tvb, offset, frag_len, fd_head->reassembled_in);
}
}
if (next_tvb)
dissect_q931_IEs(next_tvb, pinfo, tree, q931_tree, is_over_ip, 0, 0);
}
static void
dissect_q931_IEs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *root_tree,
proto_tree *q931_tree, gboolean is_over_ip, int offset, int initial_codeset)
{
proto_item *ti;
proto_tree *ie_tree = NULL;
guint8 info_element;
guint8 dummy;
guint16 info_element_len;
int codeset, locked_codeset;
gboolean non_locking_shift, first_segment;
tvbuff_t *h225_tvb, *next_tvb;
e164_info_t e164_info;
e164_info.e164_number_type = NONE;
e164_info.nature_of_address = NONE;
e164_info.E164_number_str = "";
e164_info.E164_number_length = NONE;
codeset = locked_codeset = initial_codeset;
first_segment = FALSE;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
info_element = tvb_get_guint8(tvb, offset);
if ((info_element & Q931_IE_SO_MASK) &&
((info_element & Q931_IE_SO_IDENTIFIER_MASK) == Q931_IE_SHIFT)) {
non_locking_shift = info_element & Q931_IE_SHIFT_NON_LOCKING;
codeset = info_element & Q931_IE_SHIFT_CODESET;
if (!non_locking_shift)
locked_codeset = codeset;
if (q931_tree != NULL) {
proto_tree_add_text(q931_tree, tvb, offset, 1,
"%s shift to codeset %u: %s",
(non_locking_shift ? "Non-locking" : "Locking"),
codeset,
val_to_str(codeset, q931_codeset_vals,
"Unknown (0x%02X)"));
}
offset += 1;
continue;
}
if (info_element & Q931_IE_SO_MASK) {
if (dissector_get_uint_handle(codeset_dissector_table, codeset) ||
dissector_get_uint_handle(ie_dissector_table, (codeset << 8) | (info_element & Q931_IE_SO_IDENTIFIER_MASK))) {
next_tvb = tvb_new_subset (tvb, offset, 1, 1);
if (dissector_try_uint(ie_dissector_table, (codeset << 8) | (info_element & Q931_IE_SO_IDENTIFIER_MASK), next_tvb, pinfo, q931_tree) ||
dissector_try_uint(codeset_dissector_table, codeset, next_tvb, pinfo, q931_tree)) {
offset += 1;
codeset = locked_codeset;
continue;
}
}
switch ((codeset << 8) | (info_element & Q931_IE_SO_IDENTIFIER_MASK)) {
case CS0 | Q931_IE_MORE_DATA_OR_SEND_COMP:
switch (info_element) {
case Q931_IE_MORE_DATA:
if (q931_tree != NULL) {
proto_tree_add_text(q931_tree, tvb, offset, 1,
"More data");
}
break;
case Q931_IE_SENDING_COMPLETE:
if (q931_tree != NULL) {
proto_tree_add_text(q931_tree, tvb, offset, 1,
"Sending complete");
}
break;
default:
if (q931_tree != NULL) {
proto_tree_add_text(q931_tree, tvb, offset, 1,
"Unknown information element (0x%02X)",
info_element);
}
break;
}
break;
case CS0 | Q931_IE_CONGESTION_LEVEL:
if (q931_tree != NULL) {
proto_tree_add_text(q931_tree, tvb, offset, 1,
"Congestion level: %s",
val_to_str(info_element & Q931_IE_SO_IE_MASK,
q931_congestion_level_vals,
"Unknown (0x%X)"));
}
break;
case CS0 | Q931_IE_REPEAT_INDICATOR:
if (q931_tree != NULL) {
proto_tree_add_text(q931_tree, tvb, offset, 1,
"Repeat indicator: %s",
val_to_str(info_element & Q931_IE_SO_IE_MASK,
q931_repeat_indication_vals,
"Unknown (0x%X)"));
}
break;
default:
if (q931_tree != NULL) {
proto_tree_add_text(q931_tree, tvb, offset, 1,
"Unknown information element (0x%02X)",
info_element);
}
break;
}
offset += 1;
codeset = locked_codeset;
continue;
}
if (is_over_ip && tvb_bytes_exist(tvb, offset, 4) &&
codeset == 0 && tvb_get_guint8(tvb, offset) == Q931_IE_USER_USER &&
tvb_get_guint8(tvb, offset + 3) == Q931_PROTOCOL_DISCRIMINATOR_ASN1) {
info_element_len = tvb_get_ntohs(tvb, offset + 1);
if (q931_tree != NULL) {
ti = proto_tree_add_text(q931_tree, tvb, offset,
1+2+info_element_len, "%s",
val_to_str(info_element,
q931_info_element_vals[codeset],
"Unknown information element (0x%02X)"));
ie_tree = proto_item_add_subtree(ti,
ett_q931_ie);
proto_tree_add_text(ie_tree, tvb, offset, 1,
"Information element: %s",
val_to_str(info_element,
q931_info_element_vals[codeset], "Unknown (0x%02X)"));
proto_tree_add_text(ie_tree, tvb, offset + 1,
2, "Length: %u", info_element_len);
proto_tree_add_text(ie_tree, tvb, offset + 3,
1, "Protocol discriminator: %s",
val_to_str_ext(tvb_get_guint8(tvb, offset + 3),
&q931_protocol_discriminator_vals_ext,
"Unknown (0x%02x)"));
}
if (info_element_len > 1) {
if (!pinfo->can_desegment) {
info_element_len = MIN(info_element_len, tvb_length_remaining(tvb, offset + 3));
}
if (h225_handle != NULL) {
h225_tvb = tvb_new_subset(tvb,
offset + 4, info_element_len - 1,
info_element_len - 1);
call_dissector(h225_handle, h225_tvb,
pinfo, root_tree);
} else {
proto_tree_add_text(ie_tree, tvb,
offset + 4, info_element_len - 1,
"User information: %s",
tvb_bytes_to_str(tvb, offset + 4,
info_element_len - 1));
}
}
offset += 1 + 2 + info_element_len;
} else {
info_element_len = tvb_get_guint8(tvb, offset + 1);
if (first_segment && (tvb_reported_length_remaining(tvb, offset + 2) < info_element_len)) {
proto_tree_add_text(q931_tree, tvb, offset, tvb_reported_length_remaining(tvb, offset), "Incomplete IE in the 1st segment");
break;
}
if (dissector_get_uint_handle(codeset_dissector_table, codeset) ||
dissector_get_uint_handle(ie_dissector_table, (codeset << 8) | info_element)) {
next_tvb = tvb_new_subset (tvb, offset, info_element_len + 2, info_element_len + 2);
if (dissector_try_uint(ie_dissector_table, (codeset << 8) | info_element, next_tvb, pinfo, q931_tree) ||
dissector_try_uint(codeset_dissector_table, codeset, next_tvb, pinfo, q931_tree)) {
offset += 2 + info_element_len;
codeset = locked_codeset;
continue;
}
}
ti = proto_tree_add_text(q931_tree, tvb, offset, 1+1+info_element_len, "%s",
val_to_str(info_element, q931_info_element_vals[codeset], "Unknown information element (0x%02X)"));
ie_tree = proto_item_add_subtree(ti, ett_q931_ie);
proto_tree_add_text(ie_tree, tvb, offset, 1, "Information element: %s",
val_to_str(info_element, q931_info_element_vals[codeset], "Unknown (0x%02X)"));
proto_tree_add_text(ie_tree, tvb, offset + 1, 1, "Length: %u", info_element_len);
if (((codeset << 8) | info_element) == (CS0 | Q931_IE_SEGMENTED_MESSAGE)) {
dissect_q931_segmented_message_ie(tvb, offset + 2, info_element_len, ie_tree);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, " of %s",
val_to_str_ext(tvb_get_guint8(tvb, offset + 3), &q931_message_type_vals_ext, "Unknown message type (0x%02X)"));
}
if (tvb_get_guint8(tvb, offset + 2) & 0x80) {
first_segment = TRUE;
} else {
proto_tree_add_text(q931_tree, tvb, offset + 4, tvb_reported_length_remaining(tvb, offset + 4), "Message segment");
info_element_len += tvb_reported_length_remaining(tvb, offset + 4);
}
} else {
switch ((codeset << 8) | info_element) {
case CS0 | Q931_IE_BEARER_CAPABILITY:
case CS0 | Q931_IE_LOW_LAYER_COMPAT:
if (q931_tree != NULL) {
dissect_q931_bearer_capability_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_CAUSE:
dissect_q931_cause_ie_unsafe(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q931_cause_value, &dummy, q931_info_element_vals0);
break;
case CS0 | Q931_IE_CHANGE_STATUS:
if (q931_tree != NULL) {
dissect_q931_change_status_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_CALL_STATE:
if (q931_tree != NULL) {
dissect_q931_call_state_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_CHANNEL_IDENTIFICATION:
if (q931_tree != NULL) {
dissect_q931_channel_identification_ie(
tvb, offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_PROGRESS_INDICATOR:
if (q931_tree != NULL) {
dissect_q931_progress_indicator_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_NETWORK_SPECIFIC_FACIL:
case CS0 | Q931_IE_TRANSIT_NETWORK_SEL:
if (q931_tree != NULL) {
dissect_q931_ns_facilities_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_NOTIFICATION_INDICATOR:
if (q931_tree != NULL) {
dissect_q931_notification_indicator_ie(
tvb, offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_DISPLAY:
if (q931_tree != NULL) {
dissect_q931_ia5_ie(tvb, offset + 2,
info_element_len, ie_tree,
"Display information");
}
break;
case CS0 | Q931_IE_DATE_TIME:
if (q931_tree != NULL) {
dissect_q931_date_time_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_KEYPAD_FACILITY:
if (q931_tree != NULL) {
dissect_q931_ia5_ie(tvb, offset + 2,
info_element_len, ie_tree,
"Keypad facility");
}
break;
case CS0 | Q931_IE_SIGNAL:
if (q931_tree != NULL) {
dissect_q931_signal_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_INFORMATION_RATE:
if (q931_tree != NULL) {
dissect_q931_information_rate_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_E2E_TRANSIT_DELAY:
if (q931_tree != NULL) {
dissect_q931_e2e_transit_delay_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_TD_SELECTION_AND_INT:
if (q931_tree != NULL) {
dissect_q931_td_selection_and_int_ie(
tvb, offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_PL_BINARY_PARAMETERS:
if (q931_tree != NULL) {
dissect_q931_pl_binary_parameters_ie(
tvb, offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_PL_WINDOW_SIZE:
if (q931_tree != NULL) {
dissect_q931_pl_window_size_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_PACKET_SIZE:
if (q931_tree != NULL) {
dissect_q931_packet_size_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_CUG:
if (q931_tree != NULL) {
dissect_q931_cug_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_REVERSE_CHARGE_IND:
if (q931_tree != NULL) {
dissect_q931_reverse_charge_ind_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_CONNECTED_NUMBER_DEFAULT:
if (q931_tree != NULL) {
dissect_q931_number_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q931_connected_number, e164_info);
}
break;
case CS0 | Q931_IE_CALLING_PARTY_NUMBER:
e164_info.e164_number_type = CALLING_PARTY_NUMBER;
dissect_q931_number_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q931_calling_party_number, e164_info);
break;
case CS0 | Q931_IE_CALLED_PARTY_NUMBER:
e164_info.e164_number_type = CALLED_PARTY_NUMBER;
dissect_q931_number_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q931_called_party_number, e164_info);
break;
case CS0 | Q931_IE_CALLING_PARTY_SUBADDR:
case CS0 | Q931_IE_CALLED_PARTY_SUBADDR:
if (q931_tree != NULL) {
dissect_q931_party_subaddr_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_REDIRECTING_NUMBER:
if (q931_tree != NULL) {
dissect_q931_number_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q931_redirecting_number, e164_info);
}
break;
case CS0 | Q931_IE_RESTART_INDICATOR:
if (q931_tree != NULL) {
dissect_q931_restart_indicator_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_HIGH_LAYER_COMPAT:
if (q931_tree != NULL) {
dissect_q931_high_layer_compat_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_USER_USER:
if (q931_tree != NULL) {
dissect_q931_user_user_ie(tvb, pinfo,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS5 | Q931_IE_PARTY_CATEGORY:
if (q931_tree != NULL) {
dissect_q931_party_category_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS6 | Q931_IE_DISPLAY:
if (q931_tree != NULL) {
dissect_q931_ia5_ie(tvb, offset + 2,
info_element_len, ie_tree,
"Avaya Display");
}
break;
default:
if (q931_tree != NULL) {
proto_tree_add_text(ie_tree, tvb,
offset + 2, info_element_len,
"Data: %s",
tvb_bytes_to_str(tvb, offset + 2,
info_element_len));
}
break;
}
}
offset += 1 + 1 + info_element_len;
}
codeset = locked_codeset;
}
if(have_valid_q931_pi) {
tap_queue_packet(q931_tap, pinfo, q931_pi);
}
have_valid_q931_pi=FALSE;
}
static gboolean
dissect_q931_tpkt_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int lv_tpkt_len;
lv_tpkt_len = is_tpkt(tvb, 3);
if (lv_tpkt_len == -1) {
return FALSE;
}
if (tvb_length(tvb) == 4) {
dissect_tpkt_encap(tvb, pinfo, tree, q931_desegment,
q931_tpkt_pdu_handle);
return TRUE;
}
if (!tvb_bytes_exist(tvb, 4, 3))
return FALSE;
if ((tvb_get_guint8(tvb, 4) != NLPID_Q_931) && (tvb_get_guint8(tvb, 4) != 0x03)) {
return FALSE;
}
dissect_tpkt_encap(tvb, pinfo, tree, q931_desegment,
q931_tpkt_pdu_handle);
return TRUE;
}
static void
dissect_q931_tpkt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_tpkt_heur(tvb, pinfo, tree, NULL);
}
static void
dissect_q931_tpkt_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_pdu(tvb, pinfo, tree, TRUE);
}
static void
dissect_q931(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_pdu(tvb, pinfo, tree, FALSE);
}
static void
dissect_q931_over_ip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_pdu(tvb, pinfo, tree, TRUE);
}
static void
dissect_q931_ie_cs0(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_IEs(tvb, pinfo, NULL, tree, FALSE, 0, 0);
}
static void
dissect_q931_ie_cs7(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_IEs(tvb, pinfo, NULL, tree, FALSE, 0, 7);
}
static void
q931_init(void) {
reassembly_table_init(&q931_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_register_q931(void)
{
static hf_register_info hf[] = {
{ &hf_q931_discriminator,
{ "Protocol discriminator", "q931.disc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_call_ref_len,
{ "Call reference value length", "q931.call_ref_len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_call_ref_flag,
{ "Call reference flag", "q931.call_ref_flag", FT_BOOLEAN, BASE_NONE, TFS(&tfs_call_ref_flag), 0x0,
NULL, HFILL }},
{ &hf_q931_call_ref,
{ "Call reference value", "q931.call_ref", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_message_type,
{ "Message type", "q931.message_type", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_message_type_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_q931_maintenance_message_type,
{ "Maintenance message type", "q931.maintenance_message_type", FT_UINT8, BASE_HEX, VALS(dms_message_type_vals), 0x0,
NULL, HFILL }},
{ &hf_q931_segment_type,
{ "Segmented message type", "q931.segment_type", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_message_type_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_q931_coding_standard,
{ "Coding standard", "q931.coding_standard", FT_UINT8, BASE_HEX,
VALS(q931_coding_standard_vals), 0x60,NULL, HFILL }},
{ &hf_q931_interpretation,
{ "Interpretation", "q931.interpretation", FT_UINT8, BASE_HEX,
VALS(q931_interpretation_vals), 0x1C, NULL, HFILL}},
{ &hf_q931_pres_meth_prot_prof,
{ "Presentation method of protocol profile", "q931.presentation_method_protocol_profile", FT_UINT8, BASE_HEX,
VALS(q931_pres_meth_prot_prof_vals), 0x03, NULL, HFILL}},
{ &hf_q931_high_layer_characteristics,
{ "High layer characteristics identification", "q931.high_layer_characteristics", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&q931_high_layer_characteristics_vals_ext, 0x7f, NULL, HFILL }},
{ &hf_q931_extended_high_layer_characteristics,
{ "Extended high layer characteristics identification", "q931.extended_high_layer_characteristics", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&q931_extended_high_layer_characteristics_vals_ext, 0x7f, NULL, HFILL }},
{ &hf_q931_extended_audiovisual_characteristics,
{ "Extended audiovisual characteristics identification", "q931.extended_audiovisual_characteristics", FT_UINT8, BASE_HEX,
VALS(q931_audiovisual_characteristics_vals), 0x7f, NULL, HFILL }},
{ &hf_q931_information_transfer_capability,
{ "Information transfer capability", "q931.information_transfer_capability", FT_UINT8, BASE_HEX,
VALS(q931_information_transfer_capability_vals), 0x1f,NULL, HFILL }},
{ &hf_q931_transfer_mode,
{ "Transfer mode", "q931.transfer_mode", FT_UINT8, BASE_HEX,
VALS(q931_transfer_mode_vals), 0x60,NULL, HFILL }},
{ &hf_q931_information_transfer_rate,
{ "Information transfer rate", "q931.information_transfer_rate", FT_UINT8, BASE_HEX,
VALS(q931_information_transfer_rate_vals), 0x1f,NULL, HFILL }},
{ &hf_q931_layer_ident,
{ "Layer identification", "q931.layer_ident", FT_UINT8, BASE_HEX,
VALS(q931_bearer_capability_layer_ident_vals), 0x60, NULL, HFILL }},
{ &hf_q931_uil1,
{ "User information layer 1 protocol", "q931.uil1", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&q931_uil1_vals_ext, 0x1f,NULL, HFILL }},
{ &hf_q931_cause_location,
{ "Cause location", "q931.cause_location", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &q931_cause_location_vals_ext, 0x0f,
NULL, HFILL }},
{ &hf_q931_cause_value,
{ "Cause value", "q931.cause_value", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &q931_cause_code_vals_ext, 0x7f,
NULL, HFILL }},
{ &hf_q931_number_type,
{ "Number type", "q931.number_type", FT_UINT8, BASE_HEX, VALS(q931_number_type_vals), 0x70,
NULL, HFILL }},
{ &hf_q931_numbering_plan,
{ "Numbering plan", "q931.numbering_plan", FT_UINT8, BASE_HEX, VALS(q931_numbering_plan_vals), 0x0f,
NULL, HFILL }},
{ &hf_q931_screening_ind,
{ "Screening indicator", "q931.screening_ind", FT_UINT8, BASE_HEX, VALS(q931_screening_indicator_vals), 0x03,
NULL, HFILL }},
{ &hf_q931_presentation_ind,
{ "Presentation indicator", "q931.presentation_ind", FT_UINT8, BASE_HEX, VALS(q931_presentation_indicator_vals), 0x60,
NULL, HFILL }},
{ &hf_q931_extension_ind,
{ "Extension indicator", "q931.extension_ind",
FT_BOOLEAN, 8, TFS(&q931_extension_ind_value), 0x80,
NULL, HFILL }},
{ &hf_q931_extension_ind_preference,
{ "Preference", "q931.extension_ind_preference",
FT_UINT8, BASE_DEC, VALS(q931_status_preference_vals), 0x40,
NULL, HFILL }},
{ &hf_q931_extension_ind_new_status,
{ "New status", "q931.extension_ind_new_status",
FT_UINT8, BASE_DEC, VALS(q931_new_status_vals), 0x07,
NULL, HFILL }},
{ &hf_q931_calling_party_number,
{ "Calling party number digits", "q931.calling_party_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_called_party_number,
{ "Called party number digits", "q931.called_party_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_connected_number,
{ "Connected party number digits", "q931.connected_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_redirecting_number,
{ "Redirecting party number digits", "q931.redirecting_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_channel_interface_explicit,
{ "Interface identifier present", "q931.channel.interface_id_present", FT_BOOLEAN, 8, NULL, 0x40,
"True if the interface identifier is explicit in the following octets", HFILL }},
{ &hf_q931_channel_interface_type,
{ "Interface type", "q931.channel.interface_type", FT_BOOLEAN, 8, TFS(&tfs_interface_type), 0x20,
"Identifies the ISDN interface type", HFILL }},
{ &hf_q931_channel_exclusive,
{ "Indicated channel", "q931.channel.exclusive", FT_BOOLEAN, 8, TFS(&tfs_channel_exclusive), 0x08,
"True if only the indicated channel is acceptable", HFILL }},
{ &hf_q931_channel_dchan,
{ "D-channel indicator", "q931.channel.dchan", FT_BOOLEAN, 8, NULL, 0x04,
"True if the identified channel is the D-Channel", HFILL }},
{ &hf_q931_channel_selection_bri,
{ "Information channel selection", "q931.channel.selection", FT_UINT8, BASE_HEX, q931_basic_channel_selection_vals, 0x03,
"Identifies the information channel to be used", HFILL }},
{ &hf_q931_channel_selection_pri,
{ "Information channel selection", "q931.channel.selection", FT_UINT8, BASE_HEX, q931_not_basic_channel_selection_vals, 0x03,
"Identifies the information channel to be used", HFILL }},
{ &hf_q931_channel_map,
{ "Number/map", "q931.channel.map", FT_BOOLEAN, 8, TFS(&tfs_channel_map), 0x10,
"True if channel is indicates by channel map rather than number", HFILL }},
{ &hf_q931_channel_element_type,
{ "Element type", "q931.channel.element_type", FT_UINT8, BASE_HEX, q931_element_type_vals, 0xF,
"Type of element in the channel number/slot map octets", HFILL }},
{ &hf_q931_channel_number,
{ "Channel number", "q931.channel.number", FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }},
{ &hf_q931_segment_overlap,
{ "Segment overlap", "q931.segment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{ &hf_q931_segment_overlap_conflict,
{ "Conflicting data in fragment overlap", "q931.segment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{ &hf_q931_segment_multiple_tails,
{ "Multiple tail fragments found", "q931.segment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{ &hf_q931_segment_too_long_segment,
{ "Segment too long", "q931.segment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Segment contained data past end of packet", HFILL }},
{ &hf_q931_segment_error,
{ "Defragmentation error", "q931.segment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{ &hf_q931_segment_count,
{ "Segment count", "q931.segment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_q931_segment,
{ "Q.931 Segment", "q931.segment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_segments,
{ "Q.931 Segments", "q931.segments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_reassembled_in,
{ "Reassembled Q.931 in frame", "q931.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This Q.931 message is reassembled in this frame", HFILL}},
{ &hf_q931_reassembled_length,
{ "Reassembled Q.931 length", "q931.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL}},
};
static gint *ett[] = {
&ett_q931,
&ett_q931_ie,
&ett_q931_segments,
&ett_q931_segment,
};
module_t *q931_module;
proto_q931 = proto_register_protocol("Q.931", "Q.931", "q931");
proto_register_field_array (proto_q931, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(q931_init);
register_dissector("q931", dissect_q931, proto_q931);
register_dissector("q931.tpkt", dissect_q931_tpkt, proto_q931);
q931_tpkt_handle = find_dissector("q931.tpkt");
q931_tpkt_pdu_handle = create_dissector_handle(dissect_q931_tpkt_pdu,
proto_q931);
register_dissector("q931.over_ip", dissect_q931_over_ip, proto_q931);
register_dissector("q931.ie", dissect_q931_ie_cs0, proto_q931);
register_dissector("q931.ie.cs7", dissect_q931_ie_cs7, proto_q931);
codeset_dissector_table = register_dissector_table("q931.codeset", "Q.931 Codeset", FT_UINT8, BASE_HEX);
ie_dissector_table = register_dissector_table("q931.ie", "Q.931 IE", FT_UINT16, BASE_HEX);
register_heur_dissector_list("q931_user", &q931_user_heur_subdissector_list);
q931_module = prefs_register_protocol(proto_q931, NULL);
prefs_register_bool_preference(q931_module, "desegment_h323_messages",
"Reassemble Q.931 messages spanning multiple TCP segments",
"Whether the Q.931 dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&q931_desegment);
prefs_register_bool_preference(q931_module, "reassembly",
"Reassemble segmented Q.931 messages",
"Reassemble segmented Q.931 messages (Q.931 - Annex H)",
&q931_reassembly);
q931_tap = register_tap("q931");
}
void
proto_reg_handoff_q931(void)
{
dissector_handle_t q931_handle;
dissector_handle_t q931_over_ip_handle;
q931_handle = find_dissector("q931");
dissector_add_uint("lapd.sapi", LAPD_SAPI_Q931, q931_handle);
q931_over_ip_handle = find_dissector("q931.over_ip");
dissector_add_uint("sctp.ppi", H323_PAYLOAD_PROTOCOL_ID, q931_over_ip_handle);
h225_handle = find_dissector("h225");
data_handle = find_dissector("data");
heur_dissector_add("tcp", dissect_q931_tpkt_heur, proto_q931);
}
static void reset_q931_packet_info(q931_packet_info *pi)
{
if(pi == NULL) {
return;
}
pi->calling_number = NULL;
pi->called_number = NULL;
pi->cause_value = 0xFF;
pi->crv = -1;
}
