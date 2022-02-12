static void
dissect_v52_protocol_discriminator(tvbuff_t *tvb, int offset, proto_tree *tree)
{
unsigned int discriminator = tvb_get_guint8(tvb, offset);
if (discriminator == 0x48) {
proto_tree_add_uint_format_value(tree, hf_v52_discriminator, tvb, offset, 1, discriminator,
"V5.2 (0x%02X)",
discriminator);
} else {
proto_tree_add_uint_format_value(tree, hf_v52_discriminator,
tvb, offset, 1, discriminator,
"Reserved (0x%02X)",
discriminator);
}
}
static void
dissect_pstn_sequence_number(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint8 pstn_sequence_number_tmp = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
pstn_sequence_number_tmp = tvb_get_guint8(info_tvb, info_offset+2)-0x80;
col_append_fstr(pinfo->cinfo, COL_INFO, " | SN: %u", pstn_sequence_number_tmp);
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_pstn_sequence_number, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_cadenced_ring(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint8 cadenced_ring_tmp = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
cadenced_ring_tmp = tvb_get_guint8(info_tvb, info_offset+2)-0x80;
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
col_append_fstr(pinfo->cinfo, COL_INFO, ": %u", cadenced_ring_tmp);
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_cadenced_ring, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_pulsed_signal(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
col_append_str(pinfo->cinfo, COL_INFO, ": ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset+2), pulse_type_values, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_pulse_type, info_tvb, info_offset+2, 1, ENC_BIG_ENDIAN);
if (data_length > 3) {
proto_tree_add_item(info_tree, hf_v52_suppression_indicator, info_tvb, info_offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_pulse_duration, info_tvb, info_offset+3, 1, ENC_BIG_ENDIAN);
}
if (data_length > 4) {
proto_tree_add_item(info_tree, hf_v52_ack_request_indicator, info_tvb, info_offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_number_of_pulses, info_tvb, info_offset+4, 1, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_steady_signal(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
col_append_str(pinfo->cinfo, COL_INFO, ": ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset+2)-0x80, steady_signal_values, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_steady_signal, info_tvb, info_offset+2, 1, ENC_BIG_ENDIAN);
}
}
static void
dissect_digit_signal(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 buffer = 0;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_digit_ack, info_tvb, info_offset+2, 1, ENC_NA);
buffer = tvb_get_guint8(info_tvb, info_offset+2)>>4;
buffer = buffer&0x03;
proto_tree_add_item(info_tree, hf_v52_digit_spare, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_digit_info, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
col_append_fstr(pinfo->cinfo, COL_INFO, ": %u", buffer);
}
static void
dissect_recognition_time(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 buffer = 0;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
buffer = tvb_get_guint8(info_tvb, info_offset+2)&0x7f;
if(buffer>=0x6b)
proto_tree_add_item(info_tree, hf_v52_pulse_type, info_tvb, info_offset+2, 1, ENC_BIG_ENDIAN);
else if(buffer<=0x1a)
proto_tree_add_item(info_tree, hf_v52_steady_signal, info_tvb, info_offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_duration_type, info_tvb, info_offset+3, 1, ENC_BIG_ENDIAN);
}
}
static void
dissect_enable_auto_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 buffer = 0;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
buffer = tvb_get_guint8(info_tvb, info_offset+2)&0x7f;
if(buffer>=0x6b)
proto_tree_add_item(info_tree, hf_v52_pulse_type, info_tvb, info_offset+2, 1, ENC_BIG_ENDIAN);
else if(buffer<=0x1a)
proto_tree_add_item(info_tree, hf_v52_steady_signal, info_tvb, info_offset+2, 1, ENC_BIG_ENDIAN);
buffer = tvb_get_guint8(info_tvb, info_offset+3)&0x7f;
if(buffer>=0x6b)
proto_tree_add_item(info_tree, hf_v52_pulse_type, info_tvb, info_offset+3, 1, ENC_BIG_ENDIAN);
else if(buffer<=0x1a)
proto_tree_add_item(info_tree, hf_v52_steady_signal, info_tvb, info_offset+3,1,ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+4)){
proto_tree_add_item(info_tree, hf_v52_suppression_indicator, info_tvb, info_offset+4,1,ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_pulse_duration, info_tvb, info_offset+4,1,ENC_BIG_ENDIAN);
}
if(tvb_length_remaining(info_tvb, info_offset+5)){
proto_tree_add_item(info_tree, hf_v52_ack_request_indicator, info_tvb, info_offset+5,1,ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_number_of_pulses, info_tvb, info_offset+5,1,ENC_BIG_ENDIAN);
}
}
}
static void
dissect_disable_auto_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 buffer = 0;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
buffer = tvb_get_guint8(info_tvb, info_offset+2)&0x7f;
if(buffer>=0x6b)
proto_tree_add_item(info_tree, hf_v52_pulse_type, info_tvb, info_offset+2, 1, ENC_BIG_ENDIAN);
else if(buffer<=0x1a)
proto_tree_add_item(info_tree, hf_v52_steady_signal, info_tvb, info_offset+2, 1, ENC_BIG_ENDIAN);
}
}
static void
dissect_cause(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
col_append_str(pinfo->cinfo, COL_INFO, ": ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset+2)-0x80, cause_type_values, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"), info_element);
proto_tree_add_item(info_tree, hf_v52_cause_type, info_tvb, info_offset+2, 1, ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+3))
proto_tree_add_uint_format(info_tree, hf_v52_msg_type, info_tvb, info_offset+3, 1, tvb_get_guint8(info_tvb, info_offset+3),
"Diagnostic: %s",val_to_str_const(tvb_get_guint8(info_tvb, info_offset+3), msg_type_values,"unknown"));
}
}
static void
dissect_resource_unavailable(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_res_unavailable, info_tvb, info_offset+2, info_element_length, ENC_ASCII|ENC_NA);
}
}
static void
dissect_pulse_notification(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = 1;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
if (info_tree != NULL) {
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_pulse_notification, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_line_information(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = 1;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
if (info_tree != NULL) {
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_line_info, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_state(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = 1;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
if (info_tree != NULL) {
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_state, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_auto_sig_sequence(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = 1;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
if (info_tree != NULL) {
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_auto_signalling_sequence, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_sequence_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = 1;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
if (info_tree != NULL) {
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_sequence_response, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_control_function_element(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
if (message_type_tmp != 0x11) {
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset+2)-0x80, control_function_element_values, "Unknown element"));
}
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_control_function_element, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_control_function_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
if (message_type_tmp != 0x13) {
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset+2)-0x80, control_function_id_values_short, "Unknown layer3 element"));
}
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_control_function_id, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_variant(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint8 variantValue = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
variantValue = tvb_get_guint8(info_tvb, info_offset+2)-0x80;
col_append_fstr(pinfo->cinfo, COL_INFO, " | Var: %u", variantValue);
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_variant, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_interface_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint8 interfaceAllIdValue = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
interfaceAllIdValue = (tvb_get_guint8(info_tvb, info_offset+2)<<16)+(tvb_get_guint8(info_tvb, info_offset+3)<<8)+(tvb_get_guint8(info_tvb, info_offset+4));
col_append_fstr(pinfo->cinfo, COL_INFO, " | Intf. ID: %u", interfaceAllIdValue);
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_if_up_id, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_if_id, info_tvb, info_offset+3, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_if_low_id, info_tvb, info_offset+4, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_if_all_id, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_sequence_number(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint8 hf_v52_sequence_number_tmp = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset), info_element_values_short, "Unknown element"));
hf_v52_sequence_number_tmp = tvb_get_guint8(info_tvb, info_offset+2)-0x80;
col_append_fstr(pinfo->cinfo, COL_INFO, ": %u", hf_v52_sequence_number_tmp);
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_sequence_number, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_physical_c_channel_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_fstr(pinfo->cinfo, COL_INFO, " | Phy C-ch: %u, %u", tvb_get_guint8(info_tvb, info_offset+2), tvb_get_guint8(info_tvb, info_offset+3));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_v5_link_id, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_v5_time_slot, info_tvb, info_offset+3, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_pp_rejection_cause(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset+2)-0x80, rejection_cause_values, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_rejection_cause, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_protocol_error(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset+2)-0x80, error_cause_values, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_error_cause, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_diagnostic_msg, info_tvb, info_offset+3, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_diagnostic_element, info_tvb, info_offset+4, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_performance_grading(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = 1;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset)-0xe0, performance_grading_values, "Unknown element"));
if (info_tree != NULL) {
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_performance_grading, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_cp_rejection_cause(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = 1;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset)-0xe0, cp_rejection_cause_values, "Unknown element"));
if (info_tree != NULL) {
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_cp_rejection_cause, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_user_port_identification(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 buffer = 0;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
if(buffer==0x01){
proto_tree_add_item(info_tree, hf_v52_pstn_user_port_id, info_tvb, info_offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_pstn_user_port_id_lower, info_tvb, info_offset+3, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " | PSTN port: %u", (((tvb_get_guint8(info_tvb, info_offset+2)>>1)<<8)+(tvb_get_guint8(info_tvb, info_offset+3))));
}
else if(buffer == 0x00){
proto_tree_add_item(info_tree, hf_v52_isdn_user_port_id, info_tvb, info_offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_isdn_user_port_id_lower, info_tvb, info_offset+3, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " | ISDN: %u", (((tvb_get_guint8(info_tvb, info_offset+2)>>2)<<7)+((tvb_get_guint8( info_tvb, info_offset+3)>>1))));
}
}
static void
dissect_isdn_port_time_slot_identification(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint8 isdn_user_port_ts_num_tmp = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
isdn_user_port_ts_num_tmp = (tvb_get_guint8(info_tvb, info_offset+2)) - 128;
col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%x", isdn_user_port_ts_num_tmp);
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_isdn_user_port_ts_num, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_v5_time_slot_identification(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint8 v5_link_id_tmp = 0;
guint8 v5_time_slot_tmp = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
v5_link_id_tmp = tvb_get_guint8(info_tvb, info_offset+2);
v5_time_slot_tmp = tvb_get_guint8(info_tvb, info_offset+3);
if (v5_time_slot_tmp >= 64) {
v5_time_slot_tmp = v5_time_slot_tmp - 64;
}
if (v5_time_slot_tmp >= 32) {
v5_time_slot_tmp = v5_time_slot_tmp - 32;
}
col_append_fstr(pinfo->cinfo, COL_INFO, " | V5 Link: %u, %u ", v5_link_id_tmp, v5_time_slot_tmp);
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_v5_link_id, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_override, info_tvb, info_offset+3, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_v5_time_slot, info_tvb, info_offset+3, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_multi_slot_map(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_fstr(pinfo->cinfo, COL_INFO, " | V5MSlink ID:%u",tvb_get_guint8(info_tvb, info_offset+2));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_v5_link_id, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+3))
proto_tree_add_item(info_tree, hf_v52_v5_multi_slot_elements, info_tvb, info_offset+3, info_element_length, ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+4))
proto_tree_add_item(info_tree, hf_v52_v5_multi_slot_elements, info_tvb, info_offset+4, info_element_length, ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+5))
proto_tree_add_item(info_tree, hf_v52_v5_multi_slot_elements, info_tvb, info_offset+5, info_element_length, ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+6))
proto_tree_add_item(info_tree, hf_v52_v5_multi_slot_elements, info_tvb, info_offset+6, info_element_length, ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+7))
proto_tree_add_item(info_tree, hf_v52_v5_multi_slot_elements, info_tvb, info_offset+7, info_element_length, ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+8))
proto_tree_add_item(info_tree, hf_v52_v5_multi_slot_elements, info_tvb, info_offset+8, info_element_length, ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+9))
proto_tree_add_item(info_tree, hf_v52_v5_multi_slot_elements, info_tvb, info_offset+9, info_element_length, ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+10))
proto_tree_add_item(info_tree, hf_v52_v5_multi_slot_elements, info_tvb, info_offset+10, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_bcc_rejct_cause(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset+2)-0x80, reject_cause_type_values, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_reject_cause_type, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_bcc_protocol_error_cause(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset+2)-0x80, bcc_protocol_error_cause_type_values, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_bcc_protocol_error_cause, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+3))
proto_tree_add_item(info_tree, hf_v52_diagnostic_message, info_tvb, info_offset+3, info_element_length, ENC_BIG_ENDIAN);
if(tvb_length_remaining(info_tvb, info_offset+4))
proto_tree_add_item(info_tree, hf_v52_diagnostic_information, info_tvb, info_offset+4, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_connection_incomplete(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset+2) & 0x80, connection_incomplete_reason_values, "Unknown element"));
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_connection_incomplete_reason, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_link_control_function(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *info_tree;
proto_item *ti_info;
guint8 info_element_length = 1;
guint8 info_element = 0;
guint16 data_length;
tvbuff_t *info_tvb;
int info_offset = 0;
info_element = tvb_get_guint8(tvb, offset);
data_length = tvb_get_guint8(tvb, offset+1)+2;
info_tvb = tvb_new_subset_length(tvb, offset, data_length);
info_tree = proto_tree_add_subtree(tree, info_tvb, info_offset, -1, ett_v52_info, &ti_info, "Info Element:");
if (message_type_tmp != 0x31) {
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(info_tvb, info_offset+2)-0x80, link_control_function_values, "Unknown element"));
}
if (info_tree != NULL) {
proto_tree_add_item(info_tree, hf_v52_info_element, info_tvb, info_offset, info_element_length, ENC_BIG_ENDIAN);
proto_tree_add_item(info_tree, hf_v52_info_length, info_tvb, info_offset+1, info_element_length, ENC_BIG_ENDIAN);
proto_item_append_text(ti_info, " %s (0x%x)",val_to_str_const(info_element, info_element_values, "unknown info element"),info_element);
proto_tree_add_item(info_tree, hf_v52_link_control_function, info_tvb, info_offset+2, info_element_length, ENC_BIG_ENDIAN);
}
}
static void
dissect_v52_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 4;
guint8 info_element, info_element_length;
int singleoctet;
while(tvb_length_remaining(tvb,offset) > 0){
singleoctet = 0;
info_element = tvb_get_guint8(tvb, offset);
switch(info_element){
case PSTN_SEQUENCE_NUMBER:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_pstn_sequence_number(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case CADENCED_RINGING:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_cadenced_ring(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case PULSED_SIGNAL:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_pulsed_signal(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case STEADY_SIGNAL:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_steady_signal(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case DIGIT_SIGNAL:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_digit_signal(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case RECOGNITION_TIME:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_recognition_time(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case ENABLE_AUTO_ACK:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_enable_auto_ack(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case DISABLE_AUTO_ACK:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_disable_auto_ack(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case CAUSE:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_cause(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case RESOURCE_UNAVAILABLE:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_resource_unavailable(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case PULSE_NOTIFICATION:
dissect_pulse_notification(tvb, pinfo, tree, offset);
singleoctet = 1;
break;
case LINE_INFORMATION:
dissect_line_information(tvb, pinfo, tree, offset);
singleoctet = 1;
break;
case STATE:
dissect_state(tvb, pinfo, tree, offset);
singleoctet = 1;
break;
case AUTO_SIG_SEQUENCE:
dissect_auto_sig_sequence(tvb, pinfo, tree, offset);
singleoctet = 1;
break;
case SEQUENCE_RESPONSE:
dissect_sequence_response(tvb, pinfo, tree, offset);
singleoctet = 1;
break;
case CONTROL_FUNCTION_ELEMENT:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_control_function_element(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case CONTROL_FUNCTION_ID:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_control_function_id(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case VARIANT:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_variant(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case INTERFACE_ID:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_interface_id(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case SEQUENCE_NUMBER:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_sequence_number(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case C_CHANNEL_ID:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_physical_c_channel_id(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case PP_REJECTION_CAUSE:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_pp_rejection_cause(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case PROTOCOL_ERROR:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_protocol_error(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case PERFORMANCE_GRADING:
dissect_performance_grading(tvb, pinfo, tree, offset);
singleoctet = 1;
break;
case CP_REJECTION_CAUSE:
dissect_cp_rejection_cause(tvb, pinfo, tree, offset);
singleoctet = 1;
break;
case USER_PORT_ID:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_user_port_identification(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case ISDN_PORT_TS_ID:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_isdn_port_time_slot_identification(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case V5_TIME_SLOT_ID:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_v5_time_slot_identification(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case MULTI_SLOT_MAP:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_multi_slot_map(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case BCC_REJECT_CAUSE:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_bcc_rejct_cause(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case BCC_PROTOCOL_ERROR_CAUSE:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_bcc_protocol_error_cause(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case CONNECTION_INCOMPLETE:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_connection_incomplete(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
case LINK_CONTROL_FUNCTION:
info_element_length = tvb_get_guint8(tvb,offset+1);
dissect_link_control_function(tvb, pinfo, tree, offset);
offset +=info_element_length+2;
break;
default:
offset += 1;
break;
}
if (singleoctet == 1) {
offset += 1;
}
#if 0
if (old_offset <= offset) {
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_WARN, "Zero-length information element");
return;
}
#endif
}
}
static void
dissect_v52_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
proto_tree *v52_tree = NULL;
proto_item *ti;
gboolean addr = FALSE;
guint8 bcc_all_address_tmp_up = -1;
guint16 pstn_all_address_tmp, isdn_all_address_tmp, bcc_all_address_tmp;
guint16 prot_all_address_tmp, link_all_address_tmp;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "V52");
if (tree) {
ti = proto_tree_add_item(tree, proto_v52, tvb, offset, -1, ENC_NA);
v52_tree = proto_item_add_subtree(ti, ett_v52);
dissect_v52_protocol_discriminator(tvb, offset, v52_tree);
}
if (v52_tree != NULL) {
message_type_tmp = tvb_get_guint8(tvb, MSG_TYPE_OFFSET);
if ((message_type_tmp >= 0x00) && (message_type_tmp <= 0x0e)) {
addr = TRUE;
proto_tree_add_item(v52_tree, hf_v52_pstn_address, tvb, ADDRESS_OFFSET, ADDRESS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(v52_tree, hf_v52_pstn_low_address, tvb, LOW_ADDRESS_OFFSET, LOW_ADDRESS_LENGTH, ENC_BIG_ENDIAN);
pstn_all_address_tmp = (((tvb_get_guint8(tvb,ADDRESS_OFFSET)>>1)<<8)+(tvb_get_guint8(tvb,LOW_ADDRESS_OFFSET)));
col_append_fstr(pinfo->cinfo, COL_INFO, " | PSTN: %u", pstn_all_address_tmp);
}
if ((message_type_tmp >= 0x10) && (message_type_tmp <= 0x13)) {
addr = TRUE;
if ((tvb_get_guint8(tvb, ADDRESS_OFFSET)&0x01) == 0x1) {
pstn_all_address_tmp = (((tvb_get_guint8(tvb, ADDRESS_OFFSET)>>1)<<8)+(tvb_get_guint8(tvb, LOW_ADDRESS_OFFSET)));
proto_tree_add_item(v52_tree, hf_v52_pstn_address, tvb, ADDRESS_OFFSET, ADDRESS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(v52_tree, hf_v52_pstn_low_address, tvb, LOW_ADDRESS_OFFSET, LOW_ADDRESS_LENGTH, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " | PSTN: %u", pstn_all_address_tmp);
}
else {
isdn_all_address_tmp = (((tvb_get_guint8(tvb, ADDRESS_OFFSET)>>2)<<7)+((tvb_get_guint8(tvb, LOW_ADDRESS_OFFSET)>>1)));
proto_tree_add_item(v52_tree, hf_v52_isdn_address, tvb, ADDRESS_OFFSET, ADDRESS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(v52_tree, hf_v52_isdn_low_address, tvb, LOW_ADDRESS_OFFSET, LOW_ADDRESS_LENGTH, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " | ISDN: %u", isdn_all_address_tmp);
}
}
if ((message_type_tmp == 0x30) || (message_type_tmp == 0x31)) {
addr = TRUE;
link_all_address_tmp = tvb_get_guint8(tvb, LOW_ADDRESS_OFFSET);
proto_tree_add_item(v52_tree, hf_v52_link_address, tvb, ADDRESS_OFFSET, ADDRESS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(v52_tree, hf_v52_link_low_address, tvb, LOW_ADDRESS_OFFSET, LOW_ADDRESS_LENGTH, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " | LinkId: %u", link_all_address_tmp);
}
if ((message_type_tmp >= 0x20) && (message_type_tmp <= 0x2a)) {
addr = TRUE;
proto_tree_add_item(v52_tree, hf_v52_bcc_address, tvb, ADDRESS_OFFSET, ADDRESS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(v52_tree, hf_v52_bcc_low_address, tvb, LOW_ADDRESS_OFFSET, LOW_ADDRESS_LENGTH, ENC_BIG_ENDIAN);
bcc_all_address_tmp_up = tvb_get_guint8(tvb, ADDRESS_OFFSET);
if (bcc_all_address_tmp_up >= 128) {
bcc_all_address_tmp_up = bcc_all_address_tmp_up - 128;
}
bcc_all_address_tmp = (bcc_all_address_tmp_up<<6) + tvb_get_guint8(tvb, LOW_ADDRESS_OFFSET);
col_append_fstr(pinfo->cinfo, COL_INFO, " | ref: %u", bcc_all_address_tmp);
}
if ((message_type_tmp >= 0x18) && (message_type_tmp <= 0x1f)) {
addr = TRUE;
prot_all_address_tmp = (tvb_get_guint8(tvb, ADDRESS_OFFSET)<<8) + (tvb_get_guint8(tvb,LOW_ADDRESS_OFFSET));
proto_tree_add_item(v52_tree, hf_v52_prot_address, tvb, ADDRESS_OFFSET, ADDRESS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(v52_tree, hf_v52_prot_low_address, tvb, LOW_ADDRESS_OFFSET, LOW_ADDRESS_LENGTH, ENC_BIG_ENDIAN);
if ((message_type_tmp == 0x1e) || (message_type_tmp == 0x1f)) {}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, " | Log C-ch: %u", prot_all_address_tmp);
}
}
if (addr == FALSE) {
if ((tvb_get_guint8(tvb, ADDRESS_OFFSET)&0x01) == 0x1) {
pstn_all_address_tmp = (((tvb_get_guint8(tvb, ADDRESS_OFFSET)>>1)<<8)+(tvb_get_guint8(tvb, LOW_ADDRESS_OFFSET)));
proto_tree_add_item(v52_tree, hf_v52_pstn_address, tvb, ADDRESS_OFFSET, ADDRESS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(v52_tree, hf_v52_pstn_low_address, tvb, LOW_ADDRESS_OFFSET, LOW_ADDRESS_LENGTH, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " | PSTN: %u", pstn_all_address_tmp);
}
else {
isdn_all_address_tmp = (((tvb_get_guint8(tvb, ADDRESS_OFFSET)>>2)<<7)+((tvb_get_guint8(tvb, LOW_ADDRESS_OFFSET)>>1)));
proto_tree_add_item(v52_tree, hf_v52_isdn_address, tvb, ADDRESS_OFFSET, ADDRESS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(v52_tree, hf_v52_isdn_low_address, tvb, LOW_ADDRESS_OFFSET, LOW_ADDRESS_LENGTH, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, " | ISDN: %u", isdn_all_address_tmp);
}
}
proto_tree_add_item(v52_tree, hf_v52_msg_type, tvb, MSG_TYPE_OFFSET, MSG_TYPE_LENGTH, ENC_BIG_ENDIAN);
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(tvb_get_guint8(tvb, MSG_TYPE_OFFSET), msg_type_values_short, "Unknown msg type"));
dissect_v52_info(tvb, pinfo, v52_tree);
}
}
static void
dissect_v52(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_v52_message(tvb, pinfo, tree);
}
void
proto_register_v52(void)
{
static hf_register_info hf[] = {
{ &hf_v52_discriminator,
{ "Protocol discriminator", "v52.disc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_v52_address,
{ "Address", "v52.address",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
#endif
#if 0
{ &hf_v52_low_address,
{ "Address Low", "v52.low_address",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
#endif
{ &hf_v52_isdn_address,
{ "Address isdn", "v52.isdn_address",
FT_UINT8, BASE_HEX, NULL, 0xfc,
NULL, HFILL } },
{ &hf_v52_isdn_low_address,
{ "Address isdn Low", "v52.isdn_low_address",
FT_UINT8, BASE_HEX, NULL, 0xfe,
NULL, HFILL } },
{ &hf_v52_pstn_address,
{ "Address pstn", "v52.pstn_address",
FT_UINT8, BASE_HEX, NULL, 0xfe,
NULL, HFILL } },
{ &hf_v52_pstn_low_address,
{ "Address pstn Low", "v52.pstn_low_address",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
{ &hf_v52_link_address,
{ "Address link", "v52.link_address",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
{ &hf_v52_link_low_address,
{ "Address link Low", "v52.link_low_address",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
{ &hf_v52_bcc_address,
{ "Address bcc", "v52.bcc_address",
FT_UINT8, BASE_HEX, NULL, 0x7f,
NULL, HFILL } },
{ &hf_v52_bcc_low_address,
{ "Address bcc Low", "v52.bcc_low_address",
FT_UINT8, BASE_HEX, NULL, 0x3f,
NULL, HFILL } },
{ &hf_v52_prot_address,
{ "Address prot", "v52.prot_address",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
{ &hf_v52_prot_low_address,
{ "Address prot Low", "v52.prot_low_address",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
#if 0
{ &hf_v52_ctrl_address,
{ "Address ctrl", "v52.ctrl_address",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
#endif
#if 0
{ &hf_v52_ctrl_low_address,
{ "Address ctrl Low", "v52.ctrl_low_address",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
#endif
{&hf_v52_msg_type,
{ "Message type", "v52.msg_type",
FT_UINT8, BASE_HEX, VALS(msg_type_values), 0x0,
NULL, HFILL } },
{&hf_v52_info_element,
{ "Information element", "v52.info_element",
FT_UINT8, BASE_HEX, VALS(info_element_values), 0x0,
NULL, HFILL } },
{&hf_v52_info_length,
{ "Information length", "v52.info_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{&hf_v52_pulse_notification,
{ "Pulse notification", "v52.pulse_notification",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{&hf_v52_pstn_sequence_number,
{ "Sequence number", "v52.pstn_sequence_number",
FT_UINT8, BASE_HEX, NULL, 0x7f,
NULL, HFILL } },
{&hf_v52_cadenced_ring,
{ "Cadenced ring", "v52.cadenced_ring",
FT_UINT8, BASE_HEX, NULL, 0x7f,
NULL, HFILL } },
{&hf_v52_pulse_type,
{ "Pulse Type", "v52.pulse_type",
FT_UINT8, BASE_HEX, VALS(pulse_type_values), 0x0,
NULL, HFILL } },
{&hf_v52_suppression_indicator,
{ "Suppression indicator", "v52.suppression_indicator",
FT_UINT8, BASE_HEX, VALS(suppression_indication_values), 0x60,
NULL, HFILL } },
{&hf_v52_pulse_duration,
{ "Pulse duration type", "v52.pulse_duration",
FT_UINT8, BASE_HEX, NULL, 0x1f,
NULL, HFILL } },
{&hf_v52_ack_request_indicator,
{ "Ack request indicator", "v52.ack_request_indicator",
FT_UINT8, BASE_HEX, VALS(ack_request_indication_values), 0x60,
NULL, HFILL } },
{&hf_v52_number_of_pulses,
{ "Number of pulses", "v52.number_of_pulses",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL } },
{&hf_v52_steady_signal,
{ "Steady Signal", "v52.steady_signal",
FT_UINT8, BASE_HEX, VALS(steady_signal_values), 0x7f,
NULL, HFILL } },
{&hf_v52_digit_ack,
{ "Digit ack request indication","v52.digit_ack",
FT_BOOLEAN, 8, TFS(&tfs_digit_ack_values), 0x40,
NULL, HFILL } },
{&hf_v52_digit_spare,
{ "Digit spare","v52.digit_spare",
FT_UINT8, BASE_HEX, NULL, 0x30,
NULL, HFILL } },
{&hf_v52_digit_info,
{ "Digit information", "v52.digit_info",
FT_UINT8, BASE_HEX, NULL, 0x0f,
NULL, HFILL } },
{&hf_v52_duration_type,
{ "Duration Type", "v52.duration_type",
FT_UINT8, BASE_HEX, NULL, 0x3f,
NULL, HFILL } },
{&hf_v52_res_unavailable,
{ "Resource unavailable", "v52.res_unavailable",
FT_STRING, BASE_NONE,NULL, 0x0,
NULL, HFILL } },
{&hf_v52_line_info,
{ "Line_Information", "v52.line_info",
FT_UINT8, BASE_HEX, VALS(line_info_values), 0x0f,
NULL, HFILL } },
{&hf_v52_state,
{ "PSTN FSM state", "v52.state",
FT_UINT8, BASE_HEX, VALS(state_values), 0x0f,
NULL, HFILL } },
{&hf_v52_auto_signalling_sequence,
{ "Autonomous signalling sequence","v52.auto_signalling_sequence",
FT_UINT8, BASE_HEX, NULL, 0x0f,
NULL, HFILL } },
{&hf_v52_sequence_response,
{ "Sequence response", "v52.sequence_response",
FT_UINT8, BASE_HEX, NULL, 0x0f,
NULL, HFILL } },
{&hf_v52_control_function_element,
{ "Control function element", "v52.control_function_element",
FT_UINT8, BASE_HEX, VALS(control_function_element_values), 0x7f,
NULL, HFILL } },
{&hf_v52_control_function_id,
{ "Control function ID", "v52.control_function",
FT_UINT8, BASE_HEX, VALS(control_function_id_values), 0x7f,
NULL, HFILL } },
{&hf_v52_variant,
{ "Variant", "v52.variant",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL } },
{&hf_v52_if_up_id,
{ "Interface up ID", "v52.interface_up_id",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
{&hf_v52_if_id,
{ "Interface ID", "v52.interface_id",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
{&hf_v52_if_low_id,
{ "Interface down ID", "v52.interface_low_id",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
{&hf_v52_if_all_id,
{ "Interface all ID", "v52.interface_all_id",
FT_UINT24, BASE_DEC, NULL, 0xffffff,
NULL, HFILL } },
{&hf_v52_sequence_number,
{ "Sequence number", "v52.sequence_number",
FT_UINT8, BASE_HEX, NULL, 0x7f,
NULL, HFILL } },
{&hf_v52_v5_link_id,
{ "V5 2048 kbit/s Link Identifier", "v52.V5_ln_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{&hf_v52_v5_multi_slot_elements,
{ "Additional MS ID", "v52.add_ms_id",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
{&hf_v52_v5_time_slot,
{ "V5 Time Slot Number", "v52.v5_time_slot",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL } },
{&hf_v52_rejection_cause,
{ "Rejection cause", "v52.rejection_cause",
FT_UINT8, BASE_HEX, VALS(rejection_cause_values), 0x7f,
NULL, HFILL } },
{&hf_v52_error_cause,
{ "Protocol Error Cause type", "v52.error_cause",
FT_UINT8, BASE_HEX, VALS(error_cause_values), 0x7f,
NULL, HFILL } },
{&hf_v52_diagnostic_msg,
{ "Diagnostic message", "v52.diagnostic_message",
FT_UINT8, BASE_HEX, NULL, 0x7f,
NULL, HFILL } },
{&hf_v52_diagnostic_element,
{ "Diagnostic element", "v52.diagnostic_element",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{&hf_v52_performance_grading,
{ "Performance grading", "v52.performance_grading",
FT_UINT8, BASE_HEX, VALS(performance_grading_values), 0x0f,
NULL, HFILL } },
{&hf_v52_cp_rejection_cause,
{ "Rejection cp cause", "v52.cp_rejection_cause",
FT_UINT8, BASE_HEX, VALS(cp_rejection_cause_values), 0x0f,
NULL, HFILL } },
{&hf_v52_pstn_user_port_id,
{ "PSTN User Port identification Value","v52.pstn_user_port_id",
FT_UINT8, BASE_HEX, NULL, 0xfe,
NULL, HFILL } },
{&hf_v52_pstn_user_port_id_lower,
{ "PSTN User Port Identification Value (lower)","v52.pstn_user_port_id_lower",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
{&hf_v52_isdn_user_port_id,
{ "ISDN User Port Identification Value","v52.isdn_user_port_id",
FT_UINT8, BASE_HEX, NULL, 0xfc,
NULL, HFILL } },
{&hf_v52_isdn_user_port_id_lower,
{ "ISDN User Port Identification Value (lower)","v52.user_port_id_lower",
FT_UINT8, BASE_HEX, NULL, 0xfe,
NULL, HFILL } },
{&hf_v52_isdn_user_port_ts_num,
{ "ISDN user port time slot number","v52.isdn_user_port_ts_num",
FT_UINT8, BASE_HEX, NULL, 0x1f,
NULL, HFILL } },
{&hf_v52_override,
{ "Override", "v52.override",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL } },
{&hf_v52_reject_cause_type,
{ "Reject cause type", "v52.reject_cause_type",
FT_UINT8, BASE_HEX, VALS(reject_cause_type_values), 0x7f,
NULL, HFILL } },
{&hf_v52_bcc_protocol_error_cause,
{ "Protocol error cause type", "v52.bcc_protocol_cause",
FT_UINT8, BASE_HEX, VALS(bcc_protocol_error_cause_type_values),0x7f,
NULL, HFILL } },
{&hf_v52_diagnostic_message,
{ "Diagnostic message", "v52.diagnoatic_message",
FT_UINT8, BASE_HEX, NULL, 0x7f,
NULL, HFILL } },
{&hf_v52_diagnostic_information,
{ "Diagnostic information", "v52.diagnostic_inforation",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL } },
{&hf_v52_connection_incomplete_reason,
{ "Reason", "v52.connection_incomplete_reason",
FT_UINT8, BASE_HEX, VALS(connection_incomplete_reason_values), 0x0,
NULL, HFILL } },
{&hf_v52_link_control_function,
{ "Link control function","v52.link_control_function",
FT_UINT8, BASE_HEX, VALS(link_control_function_values),0x7f,
NULL, HFILL } },
{&hf_v52_cause_type,
{ "Cause type", "v52.cause_type",
FT_UINT8, BASE_HEX, VALS(cause_type_values), 0x7f,
NULL, HFILL } }
};
static gint *ett[] = {
&ett_v52,
&ett_v52_info,
};
proto_v52 = proto_register_protocol("V5.2", "V5.2", "v52");
proto_register_field_array (proto_v52, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("v52", dissect_v52, proto_v52);
}
