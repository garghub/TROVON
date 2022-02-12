static void
cmd00_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint * bits_vita_ipmc[] = {
&hf_vita_tier, &hf_vita_layer, NULL
};
static const gint * bits_vita_ipmb[] = {
&hf_vita_ipmb_itfs, &hf_vita_ipmb_freq, NULL
};
static const gint * bits_vita_vso[] = {
&hf_vita_vso_std, NULL
};
proto_tree_add_bitmask(tree, tvb, 0, hf_vita_ipmc,
ett_vita_ipmc, bits_vita_ipmc, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 1, hf_vita_ipmb,
ett_vita_ipmb, bits_vita_ipmb, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 2, hf_vita_vso,
ett_vita_vso, bits_vita_vso, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_rev, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_max_fruid, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_ipmc_fruid, tvb, 5, 1, ENC_LITTLE_ENDIAN);
}
static void
cmd01_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint len = tvb_captured_length(tvb);
if (len > 0) {
proto_tree_add_item(tree, hf_vita_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
if (len > 1) {
proto_tree_add_item(tree, hf_vita_addr_key_type, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
if (len > 2) {
proto_tree_add_item(tree, hf_vita_addr_key, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
if (len > 3) {
proto_tree_add_item(tree, hf_vita_site_type, tvb, 3, 1, ENC_LITTLE_ENDIAN);
}
}
static void
cmd01_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_hw_addr, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_ipmb_addr, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_reserved, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fruid, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_site_num, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_site_type, tvb, 5, 1, ENC_LITTLE_ENDIAN);
if (tvb_captured_length(tvb) > 7) {
proto_tree_add_item(tree, hf_vita_reserved, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_ipmbl_addr, tvb, 7, 1, ENC_LITTLE_ENDIAN);
}
}
static void
cmd02_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
ipmi_add_typelen(tree, "Chassis Identifier", tvb, 0, TRUE);
}
static void
cmd04_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fru_control, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
cmd05_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
cmd05_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_reserved, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_led_count, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
cmd06_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_led_id, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
cmd06_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint * bits_vita_led_caps[] = {
&hf_vita_led_cap_white, &hf_vita_led_cap_orange,
&hf_vita_led_cap_amber, &hf_vita_led_cap_green,
&hf_vita_led_cap_red, &hf_vita_led_cap_blue,
NULL
};
static const int * bits_vita_led_flags[] = {
&hf_vita_led_flag_pwr,
&hf_vita_led_flag_hw_restrict,
NULL
};
proto_tree_add_bitmask(tree, tvb, 0, hf_vita_led_caps,
ett_vita_led_caps, bits_vita_led_caps, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 1, hf_vita_led_def_loc_color,
ett_vita_led_color, bits_vita_led_color, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 2, hf_vita_led_def_ovr_color,
ett_vita_led_color, bits_vita_led_color, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 3, hf_vita_led_flags,
ett_vita_led_flags, bits_vita_led_flags, ENC_LITTLE_ENDIAN);
}
static void
cmd07_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_led_id, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_led_ovr_func, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_led_ovr_duration, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 4, hf_vita_led_ovr_color,
ett_vita_led_color, bits_vita_led_color, ENC_LITTLE_ENDIAN);
}
static void
cmd08_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int * bits_vita_led_states[] = {
&hf_vita_led_state_local,
&hf_vita_led_state_override,
&hf_vita_led_state_lamp_test,
&hf_vita_led_state_hw_restrict,
NULL
};
proto_tree_add_bitmask(tree, tvb, 0, hf_vita_led_states,
ett_vita_led_states, bits_vita_led_states, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_led_loc_func, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_led_loc_duration, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 3, hf_vita_led_loc_color,
ett_vita_led_color, bits_vita_led_color, ENC_LITTLE_ENDIAN);
if (tvb_captured_length(tvb) > 4) {
proto_tree_add_item(tree, hf_vita_led_ovr_func, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_led_ovr_duration, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 6, hf_vita_led_ovr_color,
ett_vita_led_color, bits_vita_led_color, ENC_LITTLE_ENDIAN);
}
if (tvb_captured_length(tvb) > 7) {
proto_tree_add_item(tree, hf_vita_led_lamp_test_duration, tvb, 7, 1, ENC_LITTLE_ENDIAN);
}
}
static void
cmd09_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int * bits_vita_ipmb_state[] = {
&hf_vita_ipmb_state,
&hf_vita_ipmb_link_id,
NULL
};
proto_tree_add_bitmask(tree, tvb, 0, hf_vita_ipmba_state,
ett_vita_ipmb_state, bits_vita_ipmb_state, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 1, hf_vita_ipmbb_state,
ett_vita_ipmb_state, bits_vita_ipmb_state, ENC_LITTLE_ENDIAN);
}
static void
cmd0A_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 1, hf_vita_fru_policy_mask_bits,
ett_vita_fru_policy_bits, bits_vita_fru_policy_bits,
ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 2, hf_vita_fru_policy_set_bits,
ett_vita_fru_policy_bits, bits_vita_fru_policy_bits,
ENC_LITTLE_ENDIAN);
}
static void
cmd0B_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_bitmask(tree, tvb, 0, hf_vita_fru_policy_bits,
ett_vita_fru_policy_bits, bits_vita_fru_policy_bits,
ENC_LITTLE_ENDIAN);
}
static void
cmd0C_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fru_activation, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
cmd0D_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_record_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
cmd14_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int * bits_vita_fan_properties[] = {
&hf_vita_fan_prop_local_control,
NULL
};
proto_tree_add_item(tree, hf_vita_fan_min_level, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fan_max_level, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fan_norm_level, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 3, hf_vita_fan_properties,
ett_vita_fan_properties, bits_vita_fan_properties, ENC_LITTLE_ENDIAN);
}
static void
cmd15_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fan_override_level, tvb, 1, 1, ENC_LITTLE_ENDIAN);
if (tvb_captured_length(tvb) > 2) {
proto_tree_add_item(tree, hf_vita_fan_local_control, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
}
static void
cmd16_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fan_override_level, tvb, 0, 1, ENC_LITTLE_ENDIAN);
if (tvb_captured_length(tvb) > 1) {
proto_tree_add_item(tree, hf_vita_fan_local_level, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
if (tvb_captured_length(tvb) > 2) {
proto_tree_add_item(tree, hf_vita_fan_local_control, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
}
static void
cmd18_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_ipmb_link_key_type, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_ipmb_link_key_value, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
cmd18_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_ipmb_link_number, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_ipmb_sensor_number, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
cmd1B_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_active_chmc_ipmb_addr, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_backup_chmc_ipmb_addr, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
cmd1C_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fan_number, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fan_policy, tvb, 1, 1, ENC_LITTLE_ENDIAN);
if (tvb_captured_length(tvb) > 2) {
proto_tree_add_item(tree, hf_vita_fan_policy_timeout, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
if (tvb_captured_length(tvb) > 3) {
proto_tree_add_item(tree, hf_vita_site_num, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_site_type, tvb, 4, 1, ENC_LITTLE_ENDIAN);
}
}
static void
cmd1D_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fan_number, tvb, 0, 1, ENC_LITTLE_ENDIAN);
if (tvb_captured_length(tvb) > 1) {
proto_tree_add_item(tree, hf_vita_site_num, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_site_type, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
}
static void
cmd1D_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fan_policy, tvb, 0, 1, ENC_LITTLE_ENDIAN);
if (tvb_captured_length(tvb) > 1) {
proto_tree_add_item(tree, hf_vita_fan_coverage, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
cmd1E_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int * bits_vita_fru_control_caps[] = {
&hf_vita_fru_control_cap_cold,
&hf_vita_fru_control_cap_warm,
&hf_vita_fru_control_cap_grace,
&hf_vita_fru_control_cap_diag,
&hf_vita_fru_control_cap_pwr,
NULL
};
proto_tree_add_bitmask(tree, tvb, 0, hf_vita_fru_control_caps,
ett_vita_fru_control_caps, bits_vita_fru_control_caps, ENC_LITTLE_ENDIAN);
}
static void
cmd1F_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fru_lock_operation, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fru_lock_id, tvb, 2, 2, ENC_LITTLE_ENDIAN);
}
static void
cmd1F_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fru_lock_id, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fru_lock_timestamp, tvb, 2, 4, ENC_LITTLE_ENDIAN);
}
static void
cmd20_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fru_lock_id, tvb, 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fru_write_offset, tvb, 3, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fru_write_data, tvb, 5,
tvb_captured_length(tvb) - 5, ENC_NA);
}
static void
cmd20_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fru_write_count, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
cmd21_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_chassis_addr_number, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
cmd21_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item * item;
static const int * bits_vita_chassis_addr_type[] = {
&hf_vita_chassis_addr_chmc,
&hf_vita_chassis_addr_format,
NULL
};
proto_tree_add_item(tree, hf_vita_chassis_addr_timestamp, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_chassis_addr_count, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_site_type, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_site_num, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_chassis_max_unavail, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 8, hf_vita_chassis_addr_type,
ett_vita_chassis_addr_type, bits_vita_chassis_addr_type,
ENC_LITTLE_ENDIAN);
item = proto_tree_add_item(tree, hf_vita_chassis_addr, tvb, 8, -1, ENC_NA);
if (!(tvb_get_guint8(tvb, 8) & 0x7f)) {
proto_tree * sub = proto_item_add_subtree(item, ett_vita_chassis_addr);
proto_tree_add_item(sub, hf_vita_ipv4_addr, tvb, 9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub, hf_vita_rmcp_port, tvb, 13, 2, ENC_BIG_ENDIAN);
}
}
static void
cmd41_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_bitmask(tree, tvb, 0, hf_vita_persistent_control_state,
ett_vita_persistent_control_state,
bits_vita_persistent_control_state,
ENC_LITTLE_ENDIAN);
}
static void
cmd42_rq(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 1, hf_vita_persistent_control_mask,
ett_vita_persistent_control_state,
bits_vita_persistent_control_state,
ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask(tree, tvb, 2, hf_vita_persistent_control_set,
ett_vita_persistent_control_state,
bits_vita_persistent_control_state,
ENC_LITTLE_ENDIAN);
}
static void
cmd43_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int * bits_vita_persistent_control_caps[] = {
&hf_vita_persistent_control_cap_cold,
&hf_vita_persistent_control_cap_warm,
NULL
};
proto_tree_add_bitmask(tree, tvb, 0, hf_vita_persistent_control_caps,
ett_vita_persistent_control_caps,
bits_vita_persistent_control_caps,
ENC_LITTLE_ENDIAN);
}
static void
cmd44_rs(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_vita_fru_state_sensor_num, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fru_health_sensor_num, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fru_voltage_sensor_num, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_fru_temp_sensor_num, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_payload_test_results_sensor_num, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_vita_payload_test_status_sensor_num, tvb, 5, 1, ENC_LITTLE_ENDIAN);
}
void
ipmi_register_vita(gint proto_ipmi)
{
static const guint8 sig_vita[1] = { 3 };
proto_register_field_array(proto_ipmi, hf_ipmi_vita,
array_length(hf_ipmi_vita));
proto_register_subtree_array(ett_ipmi_vita,
array_length(ett_ipmi_vita));
ipmi_register_netfn_cmdtab(IPMI_GROUP_REQ, IPMI_OEM_NONE,
sig_vita, 1, "VITA", cmd_vita, array_length(cmd_vita));
}
