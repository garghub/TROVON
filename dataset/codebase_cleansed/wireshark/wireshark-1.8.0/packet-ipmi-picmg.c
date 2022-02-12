static void
rs00(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_00_version, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_00_max_fruid, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_00_ipmc_fruid, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
static void
rq01(tvbuff_t *tvb, proto_tree *tree)
{
if (tvb_length(tvb) > 0) {
proto_tree_add_item(tree, hf_ipmi_picmg_01_rq_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
if (tvb_length(tvb) > 1) {
proto_tree_add_item(tree, hf_ipmi_picmg_01_rq_addr_key_type, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
if (tvb_length(tvb) > 2) {
proto_tree_add_item(tree, hf_ipmi_picmg_01_rq_addr_key, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
if (tvb_length(tvb) > 3) {
proto_tree_add_item(tree, hf_ipmi_picmg_01_rq_site_type, tvb, 3, 1, ENC_LITTLE_ENDIAN);
}
}
static void
rs01(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_01_rs_hwaddr, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_01_rs_ipmbaddr, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_01_rs_rsrv, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_01_rs_fruid, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_01_rs_site_num, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_01_rs_site_type, tvb, 5, 1, ENC_LITTLE_ENDIAN);
}
static void
rs02(tvbuff_t *tvb, proto_tree *tree)
{
ipmi_add_typelen(tree, "Shelf Address", tvb, 0, TRUE);
}
static void
rq03(tvbuff_t *tvb, proto_tree *tree)
{
ipmi_add_typelen(tree, "Shelf Address", tvb, 0, TRUE);
}
static void
rq04(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_04_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_04_cmd, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rq05(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_05_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
rs05(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_picmg_05_led3, &hf_ipmi_picmg_05_led2,
&hf_ipmi_picmg_05_led1, &hf_ipmi_picmg_05_blue_led, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "General Status LEDs: ", "None",
ett_ipmi_picmg_05_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_picmg_05_app_leds, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rq06(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_06_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_06_ledid, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rs06(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_picmg_06_cap_white, &hf_ipmi_picmg_06_cap_orange,
&hf_ipmi_picmg_06_cap_amber, &hf_ipmi_picmg_06_cap_green, &hf_ipmi_picmg_06_cap_red,
&hf_ipmi_picmg_06_cap_blue, NULL };
static const int *byte2[] = { &hf_ipmi_picmg_06_default_local_color, NULL };
static const int *byte3[] = { &hf_ipmi_picmg_06_default_override_color, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Color capabilities: ", "None",
ett_ipmi_picmg_06_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_picmg_06_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, NULL, NULL,
ett_ipmi_picmg_06_byte3, byte3, ENC_LITTLE_ENDIAN, 0);
}
static void
parse_led_state(proto_tree *tree, tvbuff_t *tvb, guint offs, const char *desc)
{
static const int *color[] = { &hf_ipmi_picmg_led_color, NULL };
static const value_string funcs[] = {
{ 0x00, "LED Off override" },
{ 0xfb, "Lamp Test state" },
{ 0xfc, "Restore Local Control" },
{ 0xfd, "Reserved" },
{ 0xfe, "Reserved" },
{ 0xff, "LED On override" },
{ 0, NULL }
};
proto_item *ti;
guint8 v;
v = tvb_get_guint8(tvb, offs);
proto_tree_add_uint_format(tree, hf_ipmi_picmg_led_function, tvb, offs, 1,
v, "%sFunction: %s (0x%02x)", desc,
val_to_str(v, funcs, "LED Blinking override, off-duration %d0ms"),
v);
v = tvb_get_guint8(tvb, offs + 1);
proto_tree_add_uint_format(tree, hf_ipmi_picmg_led_on_duration, tvb, offs + 1, 1,
v, "%sOn-duration: %d0ms", desc, v);
v = tvb_get_guint8(tvb, offs + 2) & 0x0f;
ti = proto_tree_add_bitmask_text(tree, tvb, offs + 2, 1,
NULL, NULL, ett_ipmi_picmg_led_color, color, ENC_LITTLE_ENDIAN, 0);
proto_item_set_text(ti, "%sColor: %s", desc, val_to_str(v, led_color_vals, "Reserved"));
}
static void
rq07(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_07_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_07_ledid, tvb, 1, 1, ENC_LITTLE_ENDIAN);
parse_led_state(tree, tvb, 2, "");
}
static void
rq08(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_08_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_08_ledid, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rs08(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_picmg_08_state_lamptest, &hf_ipmi_picmg_08_state_override,
&hf_ipmi_picmg_08_state_local, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "LED States: ", "None",
ett_ipmi_picmg_08_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
parse_led_state(tree, tvb, 1, "Local Control ");
if (tvb_length(tvb) > 4) {
parse_led_state(tree, tvb, 4, "Override ");
}
if (tvb_length(tvb) > 7) {
proto_tree_add_item(tree, hf_ipmi_picmg_08_lamptest_duration, tvb, 7, 1, ENC_LITTLE_ENDIAN);
}
}
static void
parse_ipmb_state(proto_tree *tree, tvbuff_t *tvb, guint offs, int hf, int ett)
{
char buf[32];
const char *desc;
proto_tree *s_tree;
proto_item *ti;
guint8 v, num;
v = tvb_get_guint8(tvb, offs);
if (v == 0xff) {
proto_tree_add_uint_format_value(tree, hf, tvb, 0, 1,
v, "Don't change (0xff)");
} else {
num = v >> 1;
if (!num) {
desc = "All Links";
} else if (num < 0x60) {
g_snprintf(buf, sizeof(buf), "Link #%d", num);
desc = buf;
} else {
desc = "Reserved";
}
ti = proto_tree_add_uint_format_value(tree, hf, tvb, 0, 1,
v, "%s, %s", desc, (v & 1) ? "Local Control" : "Override");
s_tree = proto_item_add_subtree(ti, ett);
proto_tree_add_text(s_tree, tvb, 0, 1, "%sLink: %s (0x%02x)",
ipmi_dcd8(v, 0xfe), desc, num);
proto_tree_add_text(s_tree, tvb, 0, 1, "%sState: %s",
ipmi_dcd8(v, 0x01), (v & 1) ? "Local Control State" : "Override State (Isolate)");
}
}
static void
rq09(tvbuff_t *tvb, proto_tree *tree)
{
parse_ipmb_state(tree, tvb, 0, hf_ipmi_picmg_09_ipmba, ett_ipmi_picmg_09_ipmba);
parse_ipmb_state(tree, tvb, 1, hf_ipmi_picmg_09_ipmbb, ett_ipmi_picmg_09_ipmbb);
}
static void
rq0a(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte2[] = { &hf_ipmi_picmg_0a_msk_d_locked, &hf_ipmi_picmg_0a_msk_locked, NULL };
static const int *byte3[] = { &hf_ipmi_picmg_0a_d_locked, &hf_ipmi_picmg_0a_locked, NULL };
proto_tree_add_item(tree, hf_ipmi_picmg_0a_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, "Will affect bits: ", "None",
ett_ipmi_picmg_0a_byte2, byte2, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, "Activation Policy Set Bits: ", NULL,
ett_ipmi_picmg_0a_byte3, byte3, ENC_LITTLE_ENDIAN, 0);
}
static void
rq0b(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_0b_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
rs0b(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_picmg_0b_d_locked, &hf_ipmi_picmg_0b_locked, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Activation Policy Bits: ", NULL,
ett_ipmi_picmg_0b_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rq0c(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_0c_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_0c_cmd, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rq0d(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_0d_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
if (tvb_length(tvb) > 1) {
proto_tree_add_item(tree, hf_ipmi_picmg_0d_start, tvb, 1, 2, ENC_LITTLE_ENDIAN);
}
}
static void
rs0d(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_0d_recordid, tvb, 0, 2, ENC_LITTLE_ENDIAN);
}
static void
parse_link_info_state(proto_tree *tree, tvbuff_t *tvb, guint offs, const char *num, const value_string *vs)
{
static const int *link_info[] = { &hf_ipmi_picmg_linkinfo_grpid, &hf_ipmi_picmg_linkinfo_type_ext,
&hf_ipmi_picmg_linkinfo_type, &hf_ipmi_picmg_linkinfo_ports, &hf_ipmi_picmg_linkinfo_iface,
&hf_ipmi_picmg_linkinfo_chan, NULL };
guint8 v = tvb_get_guint8(tvb, offs + 4);
char buf[32];
g_snprintf(buf, sizeof(buf), "Link info%s: ", num);
proto_tree_add_bitmask_text(tree, tvb, offs, 4, buf, NULL,
ett_ipmi_picmg_link_info, link_info, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_uint_format(tree, hf_ipmi_picmg_linkinfo_state, tvb, offs + 4, 1,
v, "State%s: %s (0x%02x)", num, val_to_str(v, vs, "Reserved"), v);
}
static void
rq0e(tvbuff_t *tvb, proto_tree *tree)
{
static const value_string state_vals[] = {
{ 0x00, "Disable" },
{ 0x01, "Enable" },
{ 0, NULL }
};
parse_link_info_state(tree, tvb, 0, "", state_vals);
}
static void
rq0f(tvbuff_t *tvb, proto_tree *tree)
{
static const int *chan[] = { &hf_ipmi_picmg_0f_iface, &hf_ipmi_picmg_0f_chan, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_picmg_0f_chan, chan, ENC_LITTLE_ENDIAN, 0);
}
static void
rs0f(tvbuff_t *tvb, proto_tree *tree)
{
static const value_string state_vals[] = {
{ 0x00, "Disabled" },
{ 0x01, "Enabled" },
{ 0, NULL }
};
if (tvb_length(tvb) > 0) {
parse_link_info_state(tree, tvb, 0, " 1", state_vals);
}
if (tvb_length(tvb) > 5) {
parse_link_info_state(tree, tvb, 5, " 2", state_vals);
}
if (tvb_length(tvb) > 10) {
parse_link_info_state(tree, tvb, 10, " 3", state_vals);
}
if (tvb_length(tvb) > 15) {
parse_link_info_state(tree, tvb, 15, " 4", state_vals);
}
}
static void
rq10(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_10_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
rs10(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_10_nslots, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_10_ipmc_loc, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rq11(tvbuff_t *tvb, proto_tree *tree)
{
static const value_string plvl_vals[] = {
{ 0x00, "Power Off" },
{ 0xff, "Do not change" },
{ 0, NULL }
};
guint8 v = tvb_get_guint8(tvb, 1);
proto_tree_add_item(tree, hf_ipmi_picmg_11_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint_format_value(tree, hf_ipmi_picmg_11_power_level, tvb, 1, 1,
v, "%s", val_to_str(v, plvl_vals, "Power Level %d"));
proto_tree_add_item(tree, hf_ipmi_picmg_11_set_to_desired, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
static void
rq12(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_12_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_12_pwr_type, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rs12(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_picmg_12_dynamic, &hf_ipmi_picmg_12_pwr_lvl, NULL };
guint8 v, v2, i, max;
guint32 tmp;
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_picmg_12_byte1, byte1, ENC_LITTLE_ENDIAN, BMT_NO_FALSE);
proto_tree_add_item(tree, hf_ipmi_picmg_12_delay, tvb, 1, 1, ENC_LITTLE_ENDIAN);
v = tvb_get_guint8(tvb, 2);
proto_tree_add_uint_format_value(tree, hf_ipmi_picmg_12_pwr_mult, tvb, 2, 1,
v, "%d.%dW", v / 10, v % 10);
max = tvb_length(tvb) - 3;
if (max == 0) {
max = 1;
} else if (max > 20) {
max = 20;
}
for (i = 1; i <= max; i++) {
v2 = tvb_get_guint8(tvb, 2 + i);
tmp = (guint)v2 * v;
proto_tree_add_uint_format(tree, hf_ipmi_picmg_12_pwr_draw, tvb, 2 + i, 1,
v2, "Power Draw [%d]: %d.%dW (0x%02x)", i,
tmp / 10, tmp % 10, v2);
}
}
static void
rq13(tvbuff_t *tvb, proto_tree *tree)
{
if (tvb_length(tvb) > 0) {
proto_tree_add_item(tree, hf_ipmi_picmg_13_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
}
static void
rq14(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_14_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
rs14(tvbuff_t *tvb, proto_tree *tree)
{
static const int *prop[] = { &hf_ipmi_picmg_14_local_control, NULL };
proto_tree_add_item(tree, hf_ipmi_picmg_14_speed_min, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_14_speed_max, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_14_speed_norm, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 3, 1, "Fan Tray Properties: ", "None",
ett_ipmi_picmg_14_prop, prop, ENC_LITTLE_ENDIAN, 0);
}
static void
rq15(tvbuff_t *tvb, proto_tree *tree)
{
guint8 v = tvb_get_guint8(tvb, 1);
proto_tree_add_item(tree, hf_ipmi_picmg_15_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint_format_value(tree, hf_ipmi_picmg_15_fan_level, tvb, 1, 1,
v, "%s", val_to_str(v, fan_level_vals, "%d"));
if (tvb_length(tvb) > 2) {
proto_tree_add_item(tree, hf_ipmi_picmg_15_local_enable, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
}
static void
rq16(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_16_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
rs16(tvbuff_t *tvb, proto_tree *tree)
{
guint8 v;
v = tvb_get_guint8(tvb, 0);
proto_tree_add_uint_format_value(tree, hf_ipmi_picmg_16_override_level, tvb, 0, 1,
v, "%s", val_to_str(v, fan_level_vals, "%d"));
if (tvb_length(tvb) > 1) {
proto_tree_add_item(tree, hf_ipmi_picmg_16_local_level, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
if (tvb_length(tvb) > 2) {
proto_tree_add_item(tree, hf_ipmi_picmg_16_local_enable, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
}
static void
rq17(tvbuff_t *tvb, proto_tree *tree)
{
static const value_string vals_17_cmd_fromshmm[] = {
{ 0x00, "Query" },
{ 0x01, "Release" },
{ 0x02, "Force" },
{ 0x03, "Bus Free" },
{ 0, NULL }
};
static const value_string vals_17_cmd_toshmm[] = {
{ 0x00, "Request" },
{ 0x01, "Relinquish" },
{ 0x02, "Notify" },
{ 0, NULL }
};
guint to_shmm = ipmi_current_hdr->trg_sa == 0x20;
guint cmd = tvb_get_guint8(tvb, 0);
if (!tree) {
ipmi_setsaveddata(0, (to_shmm << 8) | cmd);
return;
}
proto_tree_add_uint_format_value(tree, hf_ipmi_picmg_17_cmd, tvb, 0, 1,
cmd, "%s (0x%02x)", val_to_str(cmd,
to_shmm ? vals_17_cmd_toshmm : vals_17_cmd_fromshmm,
"Reserved"), cmd);
proto_tree_add_item(tree, hf_ipmi_picmg_17_resid, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rs17(tvbuff_t *tvb, proto_tree *tree)
{
static const value_string response_vals[] = {
{ 0x000000, "In Control" },
{ 0x000001, "No Control" },
{ 0x000100, "Ack" },
{ 0x000101, "Refused" },
{ 0x000102, "No Control" },
{ 0x000200, "Ack" },
{ 0x000201, "No Control" },
{ 0x000300, "Accept" },
{ 0x000301, "Not Needed" },
{ 0x010000, "Grant" },
{ 0x010001, "Busy" },
{ 0x010002, "Defer" },
{ 0x010003, "Deny" },
{ 0x010100, "Ack" },
{ 0x010101, "Error" },
{ 0x010200, "Ack" },
{ 0x010201, "Error" },
{ 0x010202, "Deny" },
{ 0, NULL }
};
guint32 val;
guint8 status;
if (!ipmi_getsaveddata(0, &val)) {
proto_tree_add_item(tree, hf_ipmi_picmg_17_status, tvb, 0, 1, ENC_LITTLE_ENDIAN);
return;
}
status = tvb_get_guint8(tvb, 0);
val = (val << 8) | status;
proto_tree_add_uint_format_value(tree, hf_ipmi_picmg_17_status, tvb, 0, 1,
status, "%s (0x%02x)", val_to_str(val, response_vals, "Reserved"), status);
}
static void
rq18(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_18_li_key_type, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_18_li_key, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rs18(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_18_link_num, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_18_sensor_num, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rs1b(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_1b_addr_active, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_1b_addr_backup, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
rq1c(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_1c_fan_site_number, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_1c_fan_enable_state, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_1c_fan_policy_timeout, tvb, 2, 1, ENC_LITTLE_ENDIAN);
if (tvb_length(tvb) > 3) {
proto_tree_add_item(tree, hf_ipmi_picmg_1c_site_number, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_1c_site_type, tvb, 4, 1, ENC_LITTLE_ENDIAN);
}
}
static void
rq1d(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_1d_fan_site_number, tvb, 0, 1, ENC_LITTLE_ENDIAN);
if (tvb_length(tvb) > 1) {
proto_tree_add_item(tree, hf_ipmi_picmg_1d_site_number, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_1d_site_type, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
}
static void
rs1d(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_1d_policy, tvb, 0, 1, ENC_LITTLE_ENDIAN);
if (tvb_length(tvb) > 1) {
proto_tree_add_item(tree, hf_ipmi_picmg_1d_coverage, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
}
static void
rq1e(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_1e_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
rs1e(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_picmg_1e_cap_diagintr,
&hf_ipmi_picmg_1e_cap_graceful_reboot, &hf_ipmi_picmg_1e_cap_warm_reset, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "FRU Control Capabilities: ", "None",
ett_ipmi_picmg_1e_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rq1f(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_1f_rq_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_1f_rq_op, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_1f_rq_lockid, tvb, 2, 2, ENC_LITTLE_ENDIAN);
}
static void
rs1f(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_1f_rs_lockid, tvb, 0, 2, ENC_LITTLE_ENDIAN);
ipmi_add_timestamp(tree, hf_ipmi_picmg_1f_rs_tstamp, tvb, 2);
}
static void
rq20(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_20_fruid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_20_lockid, tvb, 1, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_20_offset, tvb, 3, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_20_data, tvb, 5, tvb_length(tvb) - 5, ENC_NA);
}
static void
rs20(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_20_count, tvb, 0, 1, ENC_NA);
}
static void
rq21(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_21_addr_num, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
rs21(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte9[] = { &hf_ipmi_picmg_21_is_shm, &hf_ipmi_picmg_21_addr_type, NULL };
guint8 addrtype;
ipmi_add_timestamp(tree, hf_ipmi_picmg_21_tstamp, tvb, 0);
proto_tree_add_item(tree, hf_ipmi_picmg_21_addr_count, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_21_site_type, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_21_site_num, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_21_max_unavail, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 8, 1, NULL, NULL, ett_ipmi_picmg_21_byte9, byte9, ENC_LITTLE_ENDIAN, 0);
addrtype = tvb_get_guint8(tvb, 8) & 0x7f;
if (addrtype == 0x01) {
proto_tree_add_item(tree, hf_ipmi_picmg_21_ipaddr, tvb, 9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_21_rmcpport, tvb, 13, 2, ENC_BIG_ENDIAN);
};
}
static void
rq22(tvbuff_t *tvb, proto_tree *tree)
{
if (!tree) {
ipmi_setsaveddata(0, tvb_get_guint8(tvb, 0));
return;
}
proto_tree_add_item(tree, hf_ipmi_picmg_22_feed_idx, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
rs22(tvbuff_t *tvb, proto_tree *tree)
{
guint32 offs = 0;
guint16 v;
guint i, max;
proto_tree_add_item(tree, hf_ipmi_picmg_22_update_cnt, tvb, 0, 2, ENC_LITTLE_ENDIAN);
max = tvb_length(tvb) / 2 - 1;
if (!max) {
max = 1;
}
ipmi_getsaveddata(0, &offs);
for (i = 0; i < max; i++) {
v = tvb_get_letohs(tvb, 2 + 2 * i);
proto_tree_add_uint_format(tree, hf_ipmi_picmg_22_pwr_alloc, tvb, 2 + 2 * i, 2,
v, "Power Feed [%d] Allocation: %d Watts", offs + i, v);
}
}
static void
add_component_bits(proto_tree *tree, tvbuff_t *tvb, guint offs, const char *desc)
{
static const gint *compbits[] = { &hf_ipmi_picmg_XX_comp7, &hf_ipmi_picmg_XX_comp6, &hf_ipmi_picmg_XX_comp5,
&hf_ipmi_picmg_XX_comp4, &hf_ipmi_picmg_XX_comp3, &hf_ipmi_picmg_XX_comp2, &hf_ipmi_picmg_XX_comp1, &hf_ipmi_picmg_XX_comp0, NULL };
proto_tree_add_bitmask_text(tree, tvb, offs, 1, desc, "None",
ett_ipmi_picmg_XX_compbits, compbits, ENC_LITTLE_ENDIAN, 0);
}
static void
rs2e(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte2[] = { &hf_ipmi_picmg_2e_upgrade_undesirable, &hf_ipmi_picmg_2e_auto_rollback_override,
&hf_ipmi_picmg_2e_ipmc_degraded, &hf_ipmi_picmg_2e_deferred_activate, &hf_ipmi_picmg_2e_services_affected,
&hf_ipmi_picmg_2e_manual_rollback, &hf_ipmi_picmg_2e_auto_rollback, &hf_ipmi_picmg_2e_self_test, NULL };
proto_tree_add_item(tree, hf_ipmi_picmg_2e_version, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, "Capabilities: ", "None",
ett_ipmi_picmg_2e_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_picmg_2e_upgrade_tout, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_2e_selftest_tout, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_2e_rollback_tout, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_2e_inaccessibility_tout, tvb, 5, 1, ENC_LITTLE_ENDIAN);
add_component_bits(tree, tvb, 6, "Components present: ");
}
static void
prop_00(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_picmg_prop00_cold_reset, &hf_ipmi_picmg_prop00_deferred_activation,
&hf_ipmi_picmg_prop00_comparison, &hf_ipmi_picmg_prop00_preparation, &hf_ipmi_picmg_prop00_rollback, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "General Component Properties: ", "None",
ett_ipmi_picmg_prop00_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
parse_version(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_picmg_prop01_fw_major, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_picmg_prop01_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_picmg_prop01_fw_minor, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_prop01_fw_aux, tvb, 2, 4, ENC_NA);
}
static void
prop_02(tvbuff_t *tvb, proto_tree *tree)
{
guint len = tvb_length(tvb);
if (len > 12) {
len = 12;
}
proto_tree_add_item(tree, hf_ipmi_picmg_prop02_desc, tvb, 0, len, ENC_ASCII|ENC_NA);
}
static void
rq2f(tvbuff_t *tvb, proto_tree *tree)
{
guint8 pno = tvb_get_guint8(tvb, 1);
const char *desc;
if (!tree) {
ipmi_setsaveddata(0, pno);
return;
}
if (pno < array_length(compprops)) {
desc = compprops[pno].name;
} else if (pno >= 0xC0) {
desc = "OEM";
} else {
desc = "Reserved";
}
proto_tree_add_item(tree, hf_ipmi_picmg_2f_comp_id, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint_format_value(tree, hf_ipmi_picmg_2f_comp_prop, tvb, 1, 1, pno,
"%s (0x%02x)", desc, pno);
}
static void
rs2f(tvbuff_t *tvb, proto_tree *tree)
{
guint32 pno;
const char *desc;
proto_item *ti;
if (!ipmi_getsaveddata(0, &pno)) {
proto_tree_add_item(tree, hf_ipmi_picmg_2f_prop_data, tvb, 0, tvb_length(tvb), ENC_NA);
return;
}
if (pno < array_length(compprops)) {
desc = compprops[pno].name;
} else if (pno >= 0xC0) {
desc = "OEM";
} else {
desc = "Reserved";
}
ti = proto_tree_add_text(tree, tvb, 0, 0, "Property selector: %s (0x%02x)", desc, pno);
PROTO_ITEM_SET_GENERATED(ti);
if (pno < array_length(compprops)) {
compprops[pno].intrp(tvb, tree);
} else {
proto_tree_add_item(tree, hf_ipmi_picmg_2f_prop_data, tvb, 0, tvb_length(tvb), ENC_NA);
}
}
static void
rq31(tvbuff_t *tvb, proto_tree *tree)
{
add_component_bits(tree, tvb, 0, "Components: ");
proto_tree_add_item(tree, hf_ipmi_picmg_31_action, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rq32(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_32_block, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_32_data, tvb, 1, tvb_length(tvb) - 1, ENC_NA);
}
static void
rs32(tvbuff_t *tvb, proto_tree *tree)
{
if (tvb_length(tvb) > 0) {
proto_tree_add_item(tree, hf_ipmi_picmg_32_sec_offs, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_32_sec_len, tvb, 4, 4, ENC_LITTLE_ENDIAN);
}
}
static void
rq33(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_picmg_33_comp_id, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_picmg_33_img_len, tvb, 1, 4, ENC_LITTLE_ENDIAN);
}
static void
rs34(tvbuff_t *tvb, proto_tree *tree)
{
static const guint8 sig = 0;
static const gint *byte3[] = { &hf_ipmi_picmg_34_percentage, NULL };
guint8 v;
ipmi_cmd_t *c;
v = tvb_get_guint8(tvb, 0);
c = ipmi_getcmd(ipmi_getnetfn(IPMI_GROUP_REQ, &sig), v);
proto_tree_add_uint_format_value(tree, hf_ipmi_picmg_34_cmd, tvb, 0, 1, v,
"%s (0x%02x)", c->desc, v);
v = tvb_get_guint8(tvb, 1);
proto_tree_add_uint_format_value(tree, hf_ipmi_picmg_34_ccode, tvb, 1, 1, v,
"%s (0x%02x)", ipmi_get_completion_code(v, c), v);
if (tvb_length(tvb) > 2) {
proto_tree_add_bitmask_text(tree, tvb, 2, 1, NULL, NULL,
ett_ipmi_picmg_34_byte3, byte3, ENC_LITTLE_ENDIAN, 0);
}
}
static void
rq35(tvbuff_t *tvb, proto_tree *tree)
{
if (tvb_length(tvb) > 0) {
proto_tree_add_item(tree, hf_ipmi_picmg_35_rollback_override, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
}
static void
rs36(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte2[] = { &hf_ipmi_picmg_36_fail_sel, &hf_ipmi_picmg_36_fail_sdr,
&hf_ipmi_picmg_36_fail_bmc_fru, &hf_ipmi_picmg_36_fail_ipmb_sig, &hf_ipmi_picmg_36_fail_sdr_empty,
&hf_ipmi_picmg_36_fail_iua, &hf_ipmi_picmg_36_fail_bb_fw, &hf_ipmi_picmg_36_fail_oper_fw, NULL };
int res, fail;
res = tvb_get_guint8(tvb, 0);
fail = tvb_get_guint8(tvb, 1);
proto_tree_add_uint_format(tree, hf_ipmi_picmg_36_result, tvb, 0, 1,
res, "Self test result: %s (0x%02x)",
val_to_str(res, vals_36_result, "Device-specific internal failure"),
res);
if (res == 0x55 || res == 0xff) {
proto_tree_add_uint_format_value(tree, hf_ipmi_picmg_36_fail, tvb, 1, 1,
fail, "0x%02x (must be 0x00)",
fail);
} else if (res == 0x57) {
proto_tree_add_bitmask(tree, tvb, 1, hf_ipmi_picmg_36_fail, ett_ipmi_picmg_36_byte2, byte2, ENC_LITTLE_ENDIAN);
} else if (res == 0x60) {
add_component_bits(tree, tvb, 1, "Failed components: ");
} else {
proto_tree_add_uint_format_value(tree, hf_ipmi_picmg_36_fail, tvb, 1, 1,
fail, "0x%02x (device-specific)", fail);
}
}
static void
rs37(tvbuff_t *tvb, proto_tree *tree)
{
static const gint *byte2[] = { &hf_ipmi_picmg_37_percent, NULL };
const char *desc;
switch (ipmi_current_hdr->ccode) {
case 0x00: desc = "Components completed rollback: "; break;
case 0x80: desc = "Components (should be None): "; break;
case 0x81: desc = "Components failed to rollback: "; break;
default: desc = "Components (ignored): "; break;
}
add_component_bits(tree, tvb, 0, desc);
if (tvb_length(tvb) > 1) {
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_picmg_37_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
}
void
ipmi_register_picmg(gint proto_ipmi)
{
static hf_register_info hf[] = {
{ &hf_ipmi_picmg_led_function,
{ "LED Function",
"ipmi.led.function", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_led_on_duration,
{ "On-duration",
"ipmi.led.on_duration", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_led_color,
{ "Color",
"ipmi.led.color", FT_UINT8, BASE_HEX, led_color_vals, 0x0f, NULL, HFILL }},
{ &hf_ipmi_picmg_linkinfo_grpid,
{ "Grouping ID",
"ipmi.linkinfo.grpid", FT_UINT32, BASE_DEC, NULL, 0xff000000, NULL, HFILL }},
{ &hf_ipmi_picmg_linkinfo_type_ext,
{ "Type extension",
"ipmi.linkinfo.type_ext", FT_UINT32, BASE_HEX, NULL, 0x00f00000, NULL, HFILL }},
{ &hf_ipmi_picmg_linkinfo_type,
{ "Type",
"ipmi.linkinfo.type", FT_UINT32, BASE_HEX, linkinfo_type_vals, 0x000ff000, NULL, HFILL }},
{ &hf_ipmi_picmg_linkinfo_ports,
{ "Ports",
"ipmi.linkinfo.ports", FT_UINT32, BASE_HEX, linkinfo_ports_vals, 0x00000f00, NULL, HFILL }},
{ &hf_ipmi_picmg_linkinfo_iface,
{ "Interface",
"ipmi.linkinfo.iface", FT_UINT32, BASE_HEX, linkinfo_iface_vals, 0x000000c0, NULL, HFILL }},
{ &hf_ipmi_picmg_linkinfo_chan,
{ "Channel",
"ipmi.linkinfo.chan", FT_UINT32, BASE_DEC, NULL, 0x0000003f, NULL, HFILL }},
{ &hf_ipmi_picmg_linkinfo_state,
{ "State",
"ipmi.picmg0e.state", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_00_version,
{ "PICMG Extension Version",
"ipmi.picmg00.version", FT_UINT8, BASE_CUSTOM, ipmi_fmt_version, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_00_max_fruid,
{ "Max FRU Device ID",
"ipmi.picmg00.max_fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_00_ipmc_fruid,
{ "FRU Device ID for IPMC",
"ipmi.picmg00.ipmc_fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_01_rq_fruid,
{ "FRU ID",
"ipmi.picmg01.rq_fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_01_rq_addr_key_type,
{ "Address Key Type",
"ipmi.picmg01.rq_addr_key_type", FT_UINT8, BASE_HEX, addr_key_type_vals, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_01_rq_addr_key,
{ "Address Key",
"ipmi.picmg01.rq_addr_key", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_01_rq_site_type,
{ "Site Type",
"ipmi.picmg01.rq_site_type", FT_UINT8, BASE_HEX, site_type_vals, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_01_rs_hwaddr,
{ "Hardware Address",
"ipmi.picmg01.rs_hwaddr", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_01_rs_ipmbaddr,
{ "IPMB-0 Address",
"ipmi.picmg01.rs_ipmbaddr", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_01_rs_rsrv,
{ "Reserved (shall be 0xFF)",
"ipmi.picmg01.rs_rsrv", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_01_rs_fruid,
{ "FRU ID",
"ipmi.picmg01.rs_fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_01_rs_site_num,
{ "Site Number",
"ipmi.picmg01.rs_site_num", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_01_rs_site_type,
{ "Site Type",
"ipmi.picmg01.rs_site_type", FT_UINT8, BASE_HEX, site_type_vals, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_04_fruid,
{ "FRU ID",
"ipmi.picmg04.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_04_cmd,
{ "Command",
"ipmi.picmg04.cmd", FT_UINT8, BASE_HEX, vals_04_cmd, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_05_fruid,
{ "FRU ID",
"ipmi.picmg05.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_05_led3,
{ "LED 3",
"ipmi.picmg05.led3", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_picmg_05_led2,
{ "LED 2",
"ipmi.picmg05.led2", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_picmg_05_led1,
{ "LED 1",
"ipmi.picmg05.led1", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_picmg_05_blue_led,
{ "BLUE LED",
"ipmi.picmg05.blue_led", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_picmg_05_app_leds,
{ "Application-specific LED Count",
"ipmi.picmg05.app_leds", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_06_fruid,
{ "FRU ID",
"ipmi.picmg06.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_06_ledid,
{ "LED ID",
"ipmi.picmg06.ledid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_06_cap_white,
{ "White",
"ipmi.picmg06.cap_white", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ipmi_picmg_06_cap_orange,
{ "Orange",
"ipmi.picmg06.cap_orange", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ipmi_picmg_06_cap_amber,
{ "Amber",
"ipmi.picmg06.cap_amber", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_picmg_06_cap_green,
{ "Green",
"ipmi.picmg06.cap_green", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_picmg_06_cap_red,
{ "Red",
"ipmi.picmg06.cap_red", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_picmg_06_cap_blue,
{ "Blue",
"ipmi.picmg06.cap_blue", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_picmg_06_default_local_color,
{ "Default LED Color in Local Control state",
"ipmi.picmg06.def_local", FT_UINT8, BASE_HEX, led_color_vals, 0x0f, NULL, HFILL }},
{ &hf_ipmi_picmg_06_default_override_color,
{ "Default LED Color in Override state",
"ipmi.picmg06.def_override", FT_UINT8, BASE_HEX, led_color_vals, 0x0f, NULL, HFILL }},
{ &hf_ipmi_picmg_07_fruid,
{ "FRU ID",
"ipmi.picmg07.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_07_ledid,
{ "LED ID",
"ipmi.picmg07.ledid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_08_fruid,
{ "FRU ID",
"ipmi.picmg08.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_08_ledid,
{ "LED ID",
"ipmi.picmg08.ledid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_08_state_lamptest,
{ "Lamp Test",
"ipmi.picmg08.state_lamptest", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_picmg_08_state_override,
{ "Override",
"ipmi.picmg08.state_override", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_picmg_08_state_local,
{ "Local Control",
"ipmi.picmg08.state_local", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_picmg_08_lamptest_duration,
{ "Lamp test duration",
"ipmi.picmg08.lamptest_duration", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_09_ipmba,
{ "IPMB-A State",
"ipmi.picmg09.ipmba", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_09_ipmbb,
{ "IPMB-B State",
"ipmi.picmg09.ipmbb", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_0a_fruid,
{ "FRU ID",
"ipmi.picmg0a.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_0a_msk_d_locked,
{ "Deactivation-Locked bit",
"ipmi.picmg0a.msk_deactivation", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_picmg_0a_msk_locked,
{ "Locked bit",
"ipmi.picmg0a.msk_locked", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_picmg_0a_d_locked,
{ "Deactivation-Locked bit",
"ipmi.picmg0a.deactivation", FT_BOOLEAN, 8, TFS(&set_clear_tfs), 0x02, NULL, HFILL }},
{ &hf_ipmi_picmg_0a_locked,
{ "Locked bit",
"ipmi.picmg0a.locked", FT_BOOLEAN, 8, TFS(&set_clear_tfs), 0x01, NULL, HFILL }},
{ &hf_ipmi_picmg_0b_fruid,
{ "FRU ID",
"ipmi.picmg0b.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_0b_d_locked,
{ "Deactivation-Locked bit",
"ipmi.picmg0b.deactivation", FT_BOOLEAN, 8, TFS(&set_clear_tfs), 0x02, NULL, HFILL }},
{ &hf_ipmi_picmg_0b_locked,
{ "Locked bit",
"ipmi.picmg0b.locked", FT_BOOLEAN, 8, TFS(&set_clear_tfs), 0x01, NULL, HFILL }},
{ &hf_ipmi_picmg_0c_fruid,
{ "FRU ID",
"ipmi.picmg0c.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_0c_cmd,
{ "Command",
"ipmi.picmg0c.cmd", FT_UINT8, BASE_HEX, vals_0c_cmd, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_0d_fruid,
{ "FRU ID",
"ipmi.picmg0d.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_0d_start,
{ "Search after record ID",
"ipmi.picmg0d.start", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_0d_recordid,
{ "Record ID",
"ipmi.picmg0d.recordid", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_0f_iface,
{ "Interface",
"ipmi.linkinfo.iface", FT_UINT8, BASE_HEX, linkinfo_iface_vals, 0x000000c0, NULL, HFILL }},
{ &hf_ipmi_picmg_0f_chan,
{ "Channel",
"ipmi.linkinfo.chan", FT_UINT8, BASE_DEC, NULL, 0x0000003f, NULL, HFILL }},
{ &hf_ipmi_picmg_10_fruid,
{ "FRU ID",
"ipmi.picmg10.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_10_nslots,
{ "Number of spanned slots",
"ipmi.picmg10.nslots", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_10_ipmc_loc,
{ "IPMC Location",
"ipmi.picmg10.ipmc_loc", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_11_fruid,
{ "FRU ID",
"ipmi.picmg11.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_11_power_level,
{ "Power Level",
"ipmi.picmg11.power_level", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_11_set_to_desired,
{ "Set Present Levels to Desired",
"ipmi.picmg11.set_to_desired", FT_UINT8, BASE_HEX, vals_11_set, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_12_fruid,
{ "FRU ID",
"ipmi.picmg12.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_12_pwr_type,
{ "Power Type",
"ipmi.picmg12.pwr_type", FT_UINT8, BASE_HEX, vals_12_pwr_type, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_12_dynamic,
{ "Dynamic Power Configuration",
"ipmi.picmg12.dynamic", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_picmg_12_pwr_lvl,
{ "Power Level",
"ipmi.picmg12.pwd_lvl", FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_picmg_12_delay,
{ "Delay to stable power",
"ipmi.picmg12.delay", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_12_pwr_mult,
{ "Power multiplier",
"ipmi.picmg12.pwr_mult", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_12_pwr_draw,
{ "Power draw",
"ipmi.picmg12.pwr_draw", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_13_fruid,
{ "FRU ID",
"ipmi.picmg13.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_14_fruid,
{ "FRU ID",
"ipmi.picmg14.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_14_speed_min,
{ "Minimum Speed Level",
"ipmi.picmg14.speed_min", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_14_speed_max,
{ "Maximum Speed Level",
"ipmi.picmg14.speed_max", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_14_speed_norm,
{ "Normal Operating Level",
"ipmi.picmg14.speed_norm", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_14_local_control,
{ "Local Control Mode Supported",
"ipmi.picmg14.local_control", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_picmg_15_fruid,
{ "FRU ID",
"ipmi.picmg15.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_15_fan_level,
{ "Fan Level",
"ipmi.picmg15.fan_level", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_15_local_enable,
{ "Local Control Enable State",
"ipmi.picmg15.local_enable", FT_UINT8, BASE_HEX, enable_vals, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_16_fruid,
{ "FRU ID",
"ipmi.picmg16.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_16_override_level,
{ "Override Fan Level",
"ipmi.picmg16.override_level", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_16_local_level,
{ "Local Control Fan Level",
"ipmi.picmg16.local_level", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_16_local_enable,
{ "Local Control Enable State",
"ipmi.picmg16.local_enable", FT_UINT8, BASE_HEX, enabled_vals, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_17_cmd,
{ "Command",
"ipmi.picmg17.cmd", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_17_resid,
{ "Bused Resource ID",
"ipmi.picmg17.resid", FT_UINT8, BASE_HEX, busresid_vals, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_17_status,
{ "Status",
"ipmi.picmg17.status", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_18_li_key_type,
{ "Link Info Key Type",
"ipmi.picmg18.li_key_type", FT_UINT8, BASE_HEX, vals_18_keytype, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_18_li_key,
{ "Link Info Key",
"ipmi.picmg18.li_key", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_18_link_num,
{ "Link Number",
"ipmi.picmg18.link_num", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_18_sensor_num,
{ "Sensor Number",
"ipmi.picmg18.sensor_num", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1b_addr_active,
{ "Active Shelf Manager IPMB Address",
"ipmi.picmg1b.addr_active", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1b_addr_backup,
{ "Backup Shelf Manager IPMB Address",
"ipmi.picmg1b.addr_backup", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1c_fan_site_number,
{ "Fan Tray Site Number",
"ipmi.picmg1c.fan_site_number", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1c_fan_enable_state,
{ "Fan Enable state",
"ipmi.picmg1c.fan_enable_state", FT_UINT8, BASE_HEX, enable_vals, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1c_fan_policy_timeout,
{ "Fan Policy Timeout",
"ipmi.picmg1c.fan_policy_timeout", FT_UINT8, BASE_CUSTOM, ipmi_fmt_5s_1based, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1c_site_number,
{ "Site Number",
"ipmi.picmg1c.site_number", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1c_site_type,
{ "Site Type",
"ipmi.picmg1c.site_type", FT_UINT8, BASE_HEX, site_type_vals, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1d_fan_site_number,
{ "Fan Tray Site Number",
"ipmi.picmg1d.fan_site_number", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1d_site_number,
{ "Site Number",
"ipmi.picmg1d.site_number", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1d_site_type,
{ "Site Type",
"ipmi.picmg1d.site_type", FT_UINT8, BASE_HEX, site_type_vals, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1d_policy,
{ "Policy",
"ipmi.picmg1d.fan_enable_state", FT_UINT8, BASE_HEX, vals_1d_policy, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1d_coverage,
{ "Coverage",
"ipmi.picmg1d.coverage", FT_UINT8, BASE_HEX, vals_1d_coverage, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1e_fruid,
{ "FRU ID",
"ipmi.picmg1e.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1e_cap_diagintr,
{ "Diagnostic interrupt",
"ipmi.picmg1e.cap_diagintr", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_picmg_1e_cap_graceful_reboot,
{ "Graceful reboot",
"ipmi.picmg1e.cap_reboot", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_picmg_1e_cap_warm_reset,
{ "Warm Reset",
"ipmi.picmg1e.cap_warmreset", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_picmg_1f_rq_fruid,
{ "FRU ID",
"ipmi.picmg1f.rq_fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1f_rq_op,
{ "Operation",
"ipmi.picmg1f.rq_op", FT_UINT8, BASE_HEX, vals_1f_op, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1f_rq_lockid,
{ "Lock ID",
"ipmi.picmg1f.rq_lockid", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1f_rs_lockid,
{ "Lock ID",
"ipmi.picmg1f.rs_lockid", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_1f_rs_tstamp,
{ "Last Commit Timestamp",
"ipmi.picmg1f.rs_tstamp", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_20_fruid,
{ "FRU ID",
"ipmi.picmg20.fruid", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_20_lockid,
{ "Lock ID",
"ipmi.picmg20.lockid", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_20_offset,
{ "Offset to write",
"ipmi.picmg20.offset", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_20_data,
{ "Data to write",
"ipmi.picmg20.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_20_count,
{ "Count written",
"ipmi.picmg20.count", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_21_addr_num,
{ "Address Number",
"ipmi.picmg21.addr_num", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_21_tstamp,
{ "Shelf IP Address Last Change Timestamp",
"ipmi.picmg21.tstamp", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_21_addr_count,
{ "Address Count",
"ipmi.picmg21.addr_count", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_21_site_type,
{ "Site Type",
"ipmi.picmg21.site_type", FT_UINT8, BASE_HEX, site_type_vals, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_21_site_num,
{ "Site Number",
"ipmi.picmg21.site_num", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_21_max_unavail,
{ "Maximum Unavailable Time",
"ipmi.picmg21.max_unavail", FT_UINT8, BASE_CUSTOM, ipmi_fmt_1s_1based, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_21_is_shm,
{ "Shelf Manager IP Address",
"ipmi.picmg21.is_shm", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_picmg_21_addr_type,
{ "Address Type",
"ipmi.picmg21.addr_type", FT_UINT8, BASE_HEX, NULL, 0x7f, NULL, HFILL }},
{ &hf_ipmi_picmg_21_ipaddr,
{ "IP Address",
"ipmi.picmg21.ip_addr", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_21_rmcpport,
{ "RMCP Port",
"ipmi.picmg21.rmcp_port", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_22_feed_idx,
{ "Power Feed Index",
"ipmi.picmg22.feed_idx", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_22_update_cnt,
{ "Update Counter",
"ipmi.picmg22.update_cnt", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_22_pwr_alloc,
{ "Power Feed Allocation",
"ipmi.picmg22.pwr_alloc", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_XX_comp7,
{ "Component 7",
"ipmi.hpm1.comp7", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_picmg_XX_comp6,
{ "Component 6",
"ipmi.hpm1.comp6", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ipmi_picmg_XX_comp5,
{ "Component 5",
"ipmi.hpm1.comp5", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ipmi_picmg_XX_comp4,
{ "Component 4",
"ipmi.hpm1.comp4", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_picmg_XX_comp3,
{ "Component 3",
"ipmi.hpm1.comp3", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_picmg_XX_comp2,
{ "Component 2",
"ipmi.hpm1.comp2", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_picmg_XX_comp1,
{ "Component 1",
"ipmi.hpm1.comp1", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_picmg_XX_comp0,
{ "Component 0",
"ipmi.hpm1.comp0", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_version,
{ "HPM.1 version",
"ipmi.picmg2e.hpm1_version", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_upgrade_undesirable,
{ "Firmware Upgrade Undesirable",
"ipmi.picmg2e.upgrade_undesirable", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_auto_rollback_override,
{ "Automatic Rollback Overridden",
"ipmi.picmg2e.auto_rollback_override", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_ipmc_degraded,
{ "IPMC degraded during upgrade",
"ipmi.picmg2e.ipmc_degraded", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_deferred_activate,
{ "Deferred Activation supported",
"ipmi.picmg2e.deferred_activate", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_services_affected,
{ "Services affected by upgrade",
"ipmi.picmg2e.services_affected", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_manual_rollback,
{ "Manual Rollback supported",
"ipmi.picmg2e.manual_rollback", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_auto_rollback,
{ "Automatic Rollback supported",
"ipmi.picmg2e.auto_rollback", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_self_test,
{ "Self-Test supported",
"ipmi.picmg2e.self_test", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_upgrade_tout,
{ "Upgrade timeout",
"ipmi.picmg2e.upgrade_tout", FT_UINT8, BASE_CUSTOM, ipmi_fmt_5s_1based, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_selftest_tout,
{ "Self-test timeout",
"ipmi.picmg2e.selftest_tout", FT_UINT8, BASE_CUSTOM, ipmi_fmt_5s_1based, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_rollback_tout,
{ "Rollback timeout",
"ipmi.picmg2e.rollback_tout", FT_UINT8, BASE_CUSTOM, ipmi_fmt_5s_1based, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_2e_inaccessibility_tout,
{ "Inaccessibility timeout",
"ipmi.picmg2e.inaccessibility_tout", FT_UINT8, BASE_CUSTOM, ipmi_fmt_5s_1based, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_prop00_cold_reset,
{ "Payload cold reset required",
"ipmi.prop00.cold_reset", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ipmi_picmg_prop00_deferred_activation,
{ "Deferred firmware activation supported",
"ipmi.prop00.deferred_activation", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_picmg_prop00_comparison,
{ "Firmware comparison supported",
"ipmi.prop00.firmware_comparison", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_picmg_prop00_preparation,
{ "Prepare Components action required",
"ipmi.prop00.preparation", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_picmg_prop00_rollback,
{ "Rollback/Backup support",
"ipmi.prop00.rollback", FT_UINT8, BASE_HEX, vals_prop00_rollback, 0x03, NULL, HFILL }},
{ &hf_ipmi_picmg_prop01_fw_major,
{ "Major Firmware Revision (binary encoded)",
"ipmi.prop01.fw_major", FT_UINT8, BASE_HEX, NULL, 0x7f, NULL, HFILL }},
{ &hf_ipmi_picmg_prop01_fw_minor,
{ "Minor Firmware Revision (BCD encoded)",
"ipmi.prop01.fw_minor", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_prop01_fw_aux,
{ "Auxiliary Firmware Revision Information",
"ipmi.prop01.fw_aux", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_prop02_desc,
{ "Description string",
"ipmi.prop02.desc", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_2f_comp_id,
{ "Component ID",
"ipmi.picmg2f.comp_id", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_2f_comp_prop,
{ "Component property selector",
"ipmi.picmg2f.comp_prop", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_2f_prop_data,
{ "Unknown property data",
"ipmi.picmg2f.prop_data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_31_action,
{ "Upgrade action",
"ipmi.picmg31.action", FT_UINT8, BASE_HEX, vals_31_action, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_32_block,
{ "Block Number",
"ipmi.picmg32.block", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_32_data,
{ "Data",
"ipmi.picmg32.data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_32_sec_offs,
{ "Section Offset",
"ipmi.picmg32.sec_offs", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_32_sec_len,
{ "Section Length",
"ipmi.picmg32.sec_len", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_33_comp_id,
{ "Component ID",
"ipmi.picmg33.comp_id", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_33_img_len,
{ "Image Length",
"ipmi.picmg33.img_len", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_34_cmd,
{ "Command in progress",
"ipmi.picmg34.cmd", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_34_ccode,
{ "Last command completion code",
"ipmi.picmg34.ccode", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_34_percentage,
{ "Completion estimate",
"ipmi.picmg34.percent", FT_UINT8, BASE_CUSTOM, ipmi_fmt_percent, 0x7f, NULL, HFILL }},
{ &hf_ipmi_picmg_35_rollback_override,
{ "Rollback Override Policy",
"ipmi.picmg35.rollback_override", FT_UINT8, BASE_HEX, vals_35_override, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_36_result,
{ "Self test result",
"ipmi.picmg36.self_test_result", FT_UINT8, BASE_HEX, vals_36_result, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_36_fail,
{ "Self-test error bitfield",
"ipmi.picmg36.fail", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_picmg_36_fail_sel,
{ "Cannot access SEL device",
"ipmi.picmg36.fail.sel", FT_BOOLEAN, 8, TFS(&tfs_36_fail_unknown), 0x80, NULL, HFILL }},
{ &hf_ipmi_picmg_36_fail_sdr,
{ "Cannot access SDR Repository",
"ipmi.picmg36.fail.sdr", FT_BOOLEAN, 8, TFS(&tfs_36_fail_unknown), 0x40, NULL, HFILL }},
{ &hf_ipmi_picmg_36_fail_bmc_fru,
{ "Cannot access BMC FRU device",
"ipmi.picmg36.fail.bmc_fru", FT_BOOLEAN, 8, TFS(&tfs_36_fail_unknown), 0x20, NULL, HFILL }},
{ &hf_ipmi_picmg_36_fail_ipmb_sig,
{ "IPMB signal lines do not respond",
"ipmi.picmg36.fail.ipmb_sig", FT_BOOLEAN, 8, TFS(&tfs_36_fail_unknown), 0x10, NULL, HFILL }},
{ &hf_ipmi_picmg_36_fail_sdr_empty,
{ "SDR Repository is empty",
"ipmi.picmg36.fail.sdr_empty", FT_BOOLEAN, 8, TFS(&tfs_36_fail_unknown), 0x08, NULL, HFILL }},
{ &hf_ipmi_picmg_36_fail_iua,
{ "Internal Use Area of BMC FRU corrupted",
"ipmi.picmg36.fail.iua", FT_BOOLEAN, 8, TFS(&tfs_36_fail_unknown), 0x04, NULL, HFILL }},
{ &hf_ipmi_picmg_36_fail_bb_fw,
{ "Controller update boot block firmware corrupted",
"ipmi.picmg36.fail.bb_fw", FT_BOOLEAN, 8, TFS(&tfs_36_fail_unknown), 0x02, NULL, HFILL }},
{ &hf_ipmi_picmg_36_fail_oper_fw,
{ "Controller operational firmware corrupted",
"ipmi.picmg36.fail.oper_fw", FT_BOOLEAN, 8, TFS(&tfs_36_fail_unknown), 0x01, NULL, HFILL }},
{ &hf_ipmi_picmg_37_percent,
{ "Estimated percentage complete",
"ipmi.picmg37.percent", FT_UINT8, BASE_CUSTOM, ipmi_fmt_percent, 0x7f, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ipmi_picmg_led_color,
&ett_ipmi_picmg_link_info,
&ett_ipmi_picmg_05_byte1,
&ett_ipmi_picmg_06_byte1,
&ett_ipmi_picmg_06_byte2,
&ett_ipmi_picmg_06_byte3,
&ett_ipmi_picmg_08_byte1,
&ett_ipmi_picmg_09_ipmba,
&ett_ipmi_picmg_09_ipmbb,
&ett_ipmi_picmg_0a_byte2,
&ett_ipmi_picmg_0a_byte3,
&ett_ipmi_picmg_0b_byte1,
&ett_ipmi_picmg_0f_chan,
&ett_ipmi_picmg_12_byte1,
&ett_ipmi_picmg_14_prop,
&ett_ipmi_picmg_1e_byte1,
&ett_ipmi_picmg_21_byte9,
&ett_ipmi_picmg_XX_compbits,
&ett_ipmi_picmg_2e_byte2,
&ett_ipmi_picmg_prop00_byte1,
&ett_ipmi_picmg_prop01_byte1,
&ett_ipmi_picmg_34_byte3,
&ett_ipmi_picmg_36_byte2,
&ett_ipmi_picmg_37_byte2,
};
static guint8 sig_picmg[1] = { 0 };
proto_register_field_array(proto_ipmi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ipmi_register_netfn_cmdtab(IPMI_GROUP_REQ, IPMI_OEM_NONE, sig_picmg, 1,
"PICMG", cmd_picmg, array_length(cmd_picmg));
}
