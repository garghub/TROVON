static void
bootopt_00(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_bo00_sip, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_chs_bo00_byte1, byte1,
ENC_LITTLE_ENDIAN, 0);
}
static void
bootopt_01(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_chs_bo01_spsel, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
static void
bootopt_02(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_bo02_request, &hf_ipmi_chs_bo02_discovered, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Service partition scan: ",
"Not discovered", ett_ipmi_chs_bo02_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
bootopt_03(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_bo03_pef, &hf_ipmi_chs_bo03_cctrl_timeout,
&hf_ipmi_chs_bo03_wd_timeout, &hf_ipmi_chs_bo03_softreset, &hf_ipmi_chs_bo03_powerup, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "BMC boot flag valid, don't clear on: ",
"None", ett_ipmi_chs_bo03_byte1, byte1, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
}
static void
bootopt_04(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte2[] = { &hf_ipmi_chs_bo04_bootinit_ack_oem, &hf_ipmi_chs_bo04_bootinit_ack_sms,
&hf_ipmi_chs_bo04_bootinit_ack_os, &hf_ipmi_chs_bo04_bootinit_ack_osloader,
&hf_ipmi_chs_bo04_bootinit_ack_bios, NULL };
proto_tree_add_item(tree, hf_ipmi_chs_bo04_write_mask, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, "Boot Initiator Acknowledge data: ",
"None", ett_ipmi_chs_bo04_byte2, byte2, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
}
static void
bootopt_05(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_bo05_bootflags_valid,
&hf_ipmi_chs_bo05_permanent, &hf_ipmi_chs_bo05_boottype, NULL };
static const int *byte2[] = { &hf_ipmi_chs_bo05_cmos_clear, &hf_ipmi_chs_bo05_lock_kbd,
&hf_ipmi_chs_bo05_bootdev, &hf_ipmi_chs_bo05_screen_blank, &hf_ipmi_chs_bo05_lockout_reset, NULL };
static const int *byte3[] = { &hf_ipmi_chs_bo05_lockout_poweroff, &hf_ipmi_chs_bo05_bios_verbosity,
&hf_ipmi_chs_bo05_progress_traps, &hf_ipmi_chs_bo05_pwd_bypass, &hf_ipmi_chs_bo05_lock_sleep,
&hf_ipmi_chs_bo05_console_redirection, NULL };
static const int *byte4[] = { &hf_ipmi_chs_bo05_bios_shared_override,
&hf_ipmi_chs_bo05_bios_muxctl_override, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_chs_bo05_byte1,
byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_chs_bo05_byte2,
byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, NULL, NULL, ett_ipmi_chs_bo05_byte3,
byte3, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 3, 1, NULL, NULL, ett_ipmi_chs_bo05_byte4,
byte4, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_chs_bo05_byte5, tvb, 4, 1, ENC_LITTLE_ENDIAN);
}
static void
bootopt_06(tvbuff_t *tvb, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_bo06_chan_num, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_chs_bo06_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_chs_bo06_session_id, tvb, 1, 4, ENC_LITTLE_ENDIAN);
ipmi_add_timestamp(tree, hf_ipmi_chs_bo06_bootinfo_timestamp, tvb, 5);
}
static void
bootopt_07(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_chs_bo07_block_selector, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_chs_bo07_block_data, tvb, 1, -1, ENC_NA);
}
static void
rs00(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_00_capflags_ppi, &hf_ipmi_chs_00_capflags_di,
&hf_ipmi_chs_00_capflags_fpl, &hf_ipmi_chs_00_capflags_is, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Capabilities: ", "None",
ett_ipmi_chs_00_capflags, byte1, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
proto_tree_add_item(tree, hf_ipmi_chs_00_fru_dev_addr, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_chs_00_sdr_dev_addr, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_chs_00_sel_dev_addr, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_chs_00_sm_dev_addr, tvb, 4, 1, ENC_LITTLE_ENDIAN);
if (tvb_captured_length(tvb) >= 5) {
proto_tree_add_item(tree, hf_ipmi_chs_00_bridge_dev_addr, tvb, 5, 1, ENC_LITTLE_ENDIAN);
}
}
static void
rs01(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_01_pwr_state_policy,
&hf_ipmi_chs_01_pwr_state_ctl_fault, &hf_ipmi_chs_01_pwr_state_fault,
&hf_ipmi_chs_01_pwr_state_ilock, &hf_ipmi_chs_01_pwr_state_overload,
&hf_ipmi_chs_01_pwr_state_powered, NULL };
static const int *byte2[] = { &hf_ipmi_chs_01_last_event_via_ipmi,
&hf_ipmi_chs_01_last_event_down_by_fault, &hf_ipmi_chs_01_last_event_interlock,
&hf_ipmi_chs_01_last_event_overload, &hf_ipmi_chs_01_last_event_ac_failed, NULL };
static const int *byte3[] = { &hf_ipmi_chs_01_misc_identsupp, &hf_ipmi_chs_01_misc_identstate,
&hf_ipmi_chs_01_misc_fan, &hf_ipmi_chs_01_misc_drive, &hf_ipmi_chs_01_misc_fpl_active,
&hf_ipmi_chs_01_misc_intrusion, NULL };
static const int *byte4[] = { &hf_ipmi_chs_01_fpb_standby_allowed,
&hf_ipmi_chs_01_fpb_diagintr_allowed, &hf_ipmi_chs_01_fpb_reset_allowed,
&hf_ipmi_chs_01_fpb_poweroff_allowed, &hf_ipmi_chs_01_fpb_standby_disabled,
&hf_ipmi_chs_01_fpb_diagintr_disabled, &hf_ipmi_chs_01_fpb_reset_disabled,
&hf_ipmi_chs_01_fpb_poweroff_disabled, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Current Power State: ", NULL,
ett_ipmi_chs_01_pwr_state, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, "Last Power Event: ", NULL,
ett_ipmi_chs_01_last_event, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, "Misc. State: ", NULL,
ett_ipmi_chs_01_misc, byte3, ENC_LITTLE_ENDIAN, 0);
if (tvb_captured_length(tvb) > 3) {
proto_tree_add_bitmask_text(tree, tvb, 3, 1, "Front panel buttons capabilities: ",
NULL, ett_ipmi_chs_01_fpb, byte4, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
};
}
static void
rq02(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_02_cctrl, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_chs_02_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rq04(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte2[] = { &hf_ipmi_chs_04_perm_on, NULL };
if (tvb_captured_length(tvb) > 0) {
proto_tree_add_item(tree, hf_ipmi_chs_04_ival, tvb, 0, 1, ENC_LITTLE_ENDIAN);
}
if (tvb_captured_length(tvb) > 1) {
proto_tree_add_bitmask_text(tree, tvb, 1, 1, "Flags: ", "None",
ett_ipmi_chs_04_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
}
static void
rq05(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_05_flags_fpl, &hf_ipmi_chs_05_flags_intrusion, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Capabilities: ", "None",
ett_ipmi_chs_05_flags, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_chs_05_fru_dev_addr, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_chs_05_sdr_dev_addr, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_chs_05_sel_dev_addr, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_chs_05_sm_dev_addr, tvb, 4, 1, ENC_LITTLE_ENDIAN);
if (tvb_captured_length(tvb) > 5) {
proto_tree_add_item(tree, hf_ipmi_chs_05_bridge_dev_addr, tvb, 5, 1, ENC_LITTLE_ENDIAN);
}
}
static void
rq06(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_06_rq_policy, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_chs_06_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rs06(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_06_rs_policy_support_powerup,
&hf_ipmi_chs_06_rs_policy_support_restore, &hf_ipmi_chs_06_rs_policy_support_poweroff, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Power Restore Policy support: ", "None",
ett_ipmi_chs_06_policy_support, byte1, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
}
static void
rs07(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_07_cause, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_chs_07_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_chs_07_chan, tvb, 1, 1, ENC_LITTLE_ENDIAN);
}
static void
rq08(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *s_tree;
tvbuff_t *sub;
guint8 pno;
const char *desc;
pno = tvb_get_guint8(tvb, 0) & 0x7f;
if (pno < array_length(boot_options)) {
desc = boot_options[pno].name;
} else if (pno >= 96 && pno <= 127) {
desc = "OEM";
} else {
desc = "Reserved";
}
s_tree = proto_tree_add_subtree_format(tree, tvb, 0, 1,
ett_ipmi_chs_08_byte1, NULL, "Boot option parameter selector: %s (0x%02x)",
desc, pno);
proto_tree_add_item(s_tree, hf_ipmi_chs_08_valid, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint_format_value(s_tree, hf_ipmi_chs_08_selector, tvb, 0, 1,
pno, "Boot option parameter selector: %s (0x%02x)",
desc, pno);
if (tvb_captured_length(tvb) > 1) {
if (pno < array_length(boot_options)) {
sub = tvb_new_subset_remaining(tvb, 1);
boot_options[pno].intrp(sub, tree);
} else {
proto_tree_add_none_format(tree, hf_ipmi_chs_08_data, tvb, 1,
-1, "Parameter data: %s", desc);
}
}
}
static void
rq09(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree *s_tree;
guint8 pno;
const char *desc;
pno = tvb_get_guint8(tvb, 0) & 0x7f;
if (pno < array_length(boot_options)) {
desc = boot_options[pno].name;
} else if (pno >= 96 && pno <= 127) {
desc = "OEM";
} else {
desc = "Reserved";
}
s_tree = proto_tree_add_subtree_format(tree, tvb, 0, 1,
ett_ipmi_chs_09_rq_byte1, NULL, "Boot option parameter selector: %s (0x%02x)",
desc, pno);
proto_tree_add_uint_format_value(s_tree, hf_ipmi_chs_09_rq_param_select, tvb, 0, 1,
pno, "Boot option parameter selector: %s (0x%02x)",
desc, pno);
proto_tree_add_item(tree, hf_ipmi_chs_09_rq_set_select, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_chs_09_rq_block_select, tvb, 2, 1, ENC_LITTLE_ENDIAN);
}
static void
rs09(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const int *byte1[] = { &hf_ipmi_chs_09_rs_param_version, NULL };
proto_tree *s_tree;
tvbuff_t *sub;
guint8 pno;
const char *desc;
pno = tvb_get_guint8(tvb, 1) & 0x7f;
if (pno < array_length(boot_options)) {
desc = boot_options[pno].name;
} else if (pno >= 96 && pno <= 127) {
desc = "OEM";
} else {
desc = "Reserved";
}
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_chs_09_rs_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
s_tree = proto_tree_add_subtree_format(tree, tvb, 1, 1,
ett_ipmi_chs_09_rs_byte2, NULL, "Boot option parameter selector: %s (0x%02x)",
desc, pno);
proto_tree_add_item(s_tree, hf_ipmi_chs_09_rs_valid, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint_format_value(s_tree, hf_ipmi_chs_09_rs_param_select, tvb, 1, 1,
pno, "Boot option parameter selector: %s (0x%02x)",
desc, pno);
if (pno < array_length(boot_options)) {
sub = tvb_new_subset_remaining(tvb, 2);
boot_options[pno].intrp(sub, tree);
} else {
proto_tree_add_item(tree, hf_ipmi_chs_09_rs_param_data, tvb, 2, -1, ENC_NA);
}
}
static void
rs0f(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_chs_0f_minpercnt, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_chs_0f_counter, tvb, 1, 4, ENC_LITTLE_ENDIAN);
}
void
proto_register_ipmi_chassis(void)
{
static hf_register_info hf[] = {
{ &hf_ipmi_chs_bo00_sip,
{ "Set In Progress",
"ipmi.bootopt00.sip", FT_UINT8, BASE_HEX, VALS(bo00_sip_vals), 0x03, NULL, HFILL }},
{ &hf_ipmi_chs_bo01_spsel,
{ "Service Partition Selector",
"ipmi.bootopt01.spsel", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_bo02_request,
{ "Request BIOS to scan for specified service partition",
"ipmi.bootopt02.spscan.request", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_chs_bo02_discovered,
{ "Service Partition discovered",
"ipmi.bootopt02.spscan.discovered", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_bo03_pef,
{ "Reset/power cycle caused by PEF",
"ipmi.bootopt03.bmcboot.pef", FT_BOOLEAN, 8, TFS(&bo03_dontclear_tfs), 0x10, NULL, HFILL }},
{ &hf_ipmi_chs_bo03_cctrl_timeout,
{ "Chassis Control command not received within 60s timeout",
"ipmi.bootopt03.bmcboot.cctrl_timeout", FT_BOOLEAN, 8, TFS(&bo03_dontclear_tfs), 0x08, NULL, HFILL }},
{ &hf_ipmi_chs_bo03_wd_timeout,
{ "Reset/power cycle caused by watchdog timeout",
"ipmi.bootopt03.bmcboot.wd_timeout", FT_BOOLEAN, 8, TFS(&bo03_dontclear_tfs), 0x04, NULL, HFILL }},
{ &hf_ipmi_chs_bo03_softreset,
{ "Pushbutton reset / soft reset",
"ipmi.bootopt03.bmcboot.softreset", FT_BOOLEAN, 8, TFS(&bo03_dontclear_tfs), 0x02, NULL, HFILL }},
{ &hf_ipmi_chs_bo03_powerup,
{ "Power up via pushbutton or wake event",
"ipmi.bootopt03.bmcboot.powerup", FT_BOOLEAN, 8, TFS(&bo03_dontclear_tfs), 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_bo04_write_mask,
{ "Write mask",
"ipmi.bootopt04.write_mask", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_bo04_bootinit_ack_oem,
{ "OEM",
"ipmi.bootopt04.bootinit_ack.oem", FT_BOOLEAN, 8, TFS(&bo04_bootinit_ack_tfs), 0x10, NULL, HFILL }},
{ &hf_ipmi_chs_bo04_bootinit_ack_sms,
{ "SMS",
"ipmi.bootopt04.bootinit_ack.sms", FT_BOOLEAN, 8, TFS(&bo04_bootinit_ack_tfs), 0x08, NULL, HFILL }},
{ &hf_ipmi_chs_bo04_bootinit_ack_os,
{ "OS / Service Partition",
"ipmi.bootopt04.bootinit_ack.os", FT_BOOLEAN, 8, TFS(&bo04_bootinit_ack_tfs), 0x04, NULL, HFILL }},
{ &hf_ipmi_chs_bo04_bootinit_ack_osloader,
{ "OS Loader",
"ipmi.bootopt04.bootinit_ack.osloader", FT_BOOLEAN, 8, TFS(&bo04_bootinit_ack_tfs), 0x02, NULL, HFILL }},
{ &hf_ipmi_chs_bo04_bootinit_ack_bios,
{ "BIOS/POST",
"ipmi.bootopt04.bootinit_ack.bios", FT_BOOLEAN, 8, TFS(&bo04_bootinit_ack_tfs), 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_bootflags_valid,
{ "Boot flags valid",
"ipmi.bootopt05.boot_flags_valid", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_permanent,
{ "Permanency",
"ipmi.bootopt05.permanent", FT_BOOLEAN, 8, TFS(&bo05_permanent_tfs), 0x40, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_boottype,
{ "Boot type",
"ipmi.bootopt05.boottype", FT_BOOLEAN, 8, TFS(&bo05_boottype_tfs), 0x20, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_cmos_clear,
{ "CMOS Clear",
"ipmi.bootopt05.cmos_clear", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_lock_kbd,
{ "Lock Keyboard",
"ipmi.bootopt05.lock_kbd", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_bootdev,
{ "Boot Device Selector",
"ipmi.bootopt05.bootdev", FT_UINT8, BASE_HEX, VALS(bo05_bootdev_vals), 0x3c, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_screen_blank,
{ "Screen Blank",
"ipmi.bootopt05.screen_blank", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_lockout_reset,
{ "Lock out Reset buttons",
"ipmi.bootopt05.lockout_reset", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_lockout_poweroff,
{ "Lock out (power off / sleep request) via Power Button",
"ipmi.bootopt05.lockout_poweroff", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_bios_verbosity,
{ "BIOS verbosity",
"ipmi.bootopt05.bios_verbosity", FT_UINT8, BASE_HEX, VALS(bo05_bios_verbosity_vals), 0x60, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_progress_traps,
{ "Force Progress Event Traps",
"ipmi.bootopt05.progress_traps", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_pwd_bypass,
{ "User password bypass",
"ipmi.bootopt05.pwd_bypass", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_lock_sleep,
{ "Lock Out Sleep Button",
"ipmi.bootopt05.lock_sleep", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_console_redirection,
{ "Console redirection",
"ipmi.bootopt05.console_redirection", FT_UINT8, BASE_HEX, VALS(bo05_console_redir_vals), 0x03, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_bios_shared_override,
{ "BIOS Shared Mode Override",
"ipmi.bootopt05.bios_shared_override", FT_BOOLEAN, 8, TFS(&bo05_bios_shared_tfs), 0x08, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_bios_muxctl_override,
{ "BIOS Mux Control Override",
"ipmi.bootopt05.bios_muxctl_override", FT_UINT8, BASE_HEX, VALS(bo05_bios_muxctl_vals), 0x07, NULL, HFILL }},
{ &hf_ipmi_chs_bo05_byte5,
{ "Data 5 (reserved)",
"ipmi.bootopt05.byte5", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_bo06_chan_num,
{ "Channel",
"ipmi.bootopt06.chan_num", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_channel), 0x0f, NULL, HFILL }},
{ &hf_ipmi_chs_bo06_session_id,
{ "Session ID",
"ipmi.bootopt06.session_id", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_bo06_bootinfo_timestamp,
{ "Boot Info Timestamp",
"impi.bootopt06.bootinfo_timestamp", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_bo07_block_selector,
{ "Block selector",
"ipmi.bootopt07.block_selector", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_bo07_block_data,
{ "Block data",
"ipmi.bootopt07.block_data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_00_capflags_ppi,
{ "Power interlock",
"ipmi.ch00.cap.power_interlock", FT_BOOLEAN, 8, TFS(&tfs_00_provided), 0x08, NULL, HFILL }},
{ &hf_ipmi_chs_00_capflags_di,
{ "Diagnostic Interrupt",
"ipmi.ch00.cap.diag_int", FT_BOOLEAN, 8, TFS(&tfs_00_provided), 0x04, NULL, HFILL }},
{ &hf_ipmi_chs_00_capflags_fpl,
{ "Front Panel Lockout",
"ipmi.ch00.cap.fpl", FT_BOOLEAN, 8, TFS(&tfs_00_provided), 0x02, NULL, HFILL }},
{ &hf_ipmi_chs_00_capflags_is,
{ "Intrusion sensor",
"ipmi.ch00.cap.intrusion", FT_BOOLEAN, 8, TFS(&tfs_00_provided), 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_00_fru_dev_addr,
{ "Chassis FRU Info Device Address",
"ipmi.ch00.fru_info", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_00_sdr_dev_addr,
{ "Chassis SDR Device Address",
"ipmi.ch00.sdr", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_00_sel_dev_addr,
{ "Chassis SEL Device Address",
"ipmi.ch00.sel", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_00_sm_dev_addr,
{ "Chassis System Management Device Address",
"ipmi.ch00.sm", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_00_bridge_dev_addr,
{ "Chassis Bridge Device Address",
"ipmi.ch00.bridge", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_01_pwr_state_policy,
{ "Power Restore Policy",
"ipmi.ch01.cur_pwr.policy", FT_UINT8, BASE_HEX, VALS(vals_01_pwr_policy), 0x60, NULL, HFILL }},
{ &hf_ipmi_chs_01_pwr_state_ctl_fault,
{ "Power Control Fault",
"ipmi.ch01.cur_pwr.ctl_fault", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_chs_01_pwr_state_fault,
{ "Power Fault",
"ipmi.ch01.cur_pwr.fault", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_chs_01_pwr_state_ilock,
{ "Interlock",
"ipmi.ch01.cur_pwr.interlock", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_chs_01_pwr_state_overload,
{ "Overload",
"ipmi.ch01.cur_pwr.overload", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_chs_01_pwr_state_powered,
{ "Power is on",
"ipmi.ch01.cur_pwr.powered", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_01_last_event_via_ipmi,
{ "Last `Power is on' state was entered via IPMI command",
"ipmi.ch01.last.on_via_ipmi", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_chs_01_last_event_down_by_fault,
{ "Last power down caused by power fault",
"ipmi.ch01.last.down_by_fault", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_chs_01_last_event_interlock,
{ "Last power down caused by a power interlock being activated",
"ipmi.ch01.last.interlock", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_chs_01_last_event_overload,
{ "Last power down caused by a power overload",
"ipmi.ch01.last.overload", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_chs_01_last_event_ac_failed,
{ "AC failed",
"ipmi.ch01.last.ac_failed", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_01_misc_identsupp,
{ "Chassis Identify command and state info supported",
"ipmi.ch01.identsupp", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ipmi_chs_01_misc_identstate,
{ "Chassis Identify state (if supported)",
"ipmi.ch01.identstate", FT_UINT8, BASE_HEX, VALS(vals_01_identstate), 0x30, NULL, HFILL }},
{ &hf_ipmi_chs_01_misc_fan,
{ "Cooling/fan fault detected",
"ipmi.ch01.misc.fan", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_chs_01_misc_drive,
{ "Drive Fault",
"ipmi.ch01.misc.drive", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_chs_01_misc_fpl_active,
{ "Front Panel Lockout active",
"ipmi.ch01.misc.fpl_active", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_chs_01_misc_intrusion,
{ "Chassis intrusion active",
"ipmi.ch01.misc.intrusion", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_01_fpb_standby_allowed,
{ "Standby disable allowed",
"ipmi.ch01.fpb.standby_allowed", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_chs_01_fpb_diagintr_allowed,
{ "Diagnostic interrupt disable allowed",
"ipmi.ch01.fpb.diagintr_allowed", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ipmi_chs_01_fpb_reset_allowed,
{ "Reset disable allowed",
"ipmi.ch01.fpb.reset_allowed", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ipmi_chs_01_fpb_poweroff_allowed,
{ "Poweroff disable allowed",
"ipmi.ch01.fpb.poweroff_allowed", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_chs_01_fpb_standby_disabled,
{ "Standby disabled",
"ipmi.ch01.fpb.standby_disabled", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_chs_01_fpb_diagintr_disabled,
{ "Diagnostic interrupt disabled",
"ipmi.ch01.fpb.diagintr_disabled", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_chs_01_fpb_reset_disabled,
{ "Reset disabled",
"ipmi.ch01.fpb.reset_disabled", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_chs_01_fpb_poweroff_disabled,
{ "Poweroff disabled",
"ipmi.ch01.fpb.poweroff_disabled", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_02_cctrl,
{ "Chassis Control",
"ipmi.ch02.chassis_control", FT_UINT8, BASE_HEX, VALS(vals_02_cctrl), 0x0f, NULL, HFILL }},
{ &hf_ipmi_chs_04_ival,
{ "Identify Interval in seconds",
"ipmi.ch04.interval", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_1s_1based), 0, NULL, HFILL }},
{ &hf_ipmi_chs_04_perm_on,
{ "Turn on Identify indefinitely",
"ipmi.ch04.perm_on", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_05_flags_fpl,
{ "Provides Front Panel Lockout",
"ipmi.ch05.flags.fpl", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_chs_05_flags_intrusion,
{ "Provides intrusion sensor",
"ipmi.ch05.flags.intrusion", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_05_fru_dev_addr,
{ "Chassis FRU Info Device Address",
"ipmi.ch05.fru_info", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_05_sdr_dev_addr,
{ "Chassis SDR Device Address",
"ipmi.ch05.sdr", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_05_sel_dev_addr,
{ "Chassis SEL Device Address",
"ipmi.ch05.sel", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_05_sm_dev_addr,
{ "Chassis System Management Device Address",
"ipmi.ch05.sm", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_05_bridge_dev_addr,
{ "Chassis Bridge Device Address",
"ipmi.ch05.bridge", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_06_rq_policy,
{ "Power Restore Policy",
"ipmi.ch06.rq_policy", FT_UINT8, BASE_HEX, VALS(vals_06_policy), 0x07, NULL, HFILL }},
{ &hf_ipmi_chs_06_rs_policy_support_powerup,
{ "Always powering up",
"ipmi.ch06.rs_support.powerup", FT_BOOLEAN, 8, TFS(&tfs_06_supported), 0x04, NULL, HFILL }},
{ &hf_ipmi_chs_06_rs_policy_support_restore,
{ "Restoring previous state",
"ipmi.ch06.rs_support.restore", FT_BOOLEAN, 8, TFS(&tfs_06_supported), 0x02, NULL, HFILL }},
{ &hf_ipmi_chs_06_rs_policy_support_poweroff,
{ "Staying powered off",
"ipmi.ch06.rs_support.poweroff", FT_BOOLEAN, 8, TFS(&tfs_06_supported), 0x01, NULL, HFILL }},
{ &hf_ipmi_chs_07_cause,
{ "Restart Cause",
"ipmi.ch07.cause", FT_UINT8, BASE_HEX, VALS(vals_07_cause), 0x0f, NULL, HFILL }},
{ &hf_ipmi_chs_07_chan,
{ "Channel",
"ipmi.ch07.chan", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_channel), 0, NULL, HFILL }},
{ &hf_ipmi_chs_08_valid,
{ "Validity",
"ipmi.ch08.valid", FT_BOOLEAN, 8, TFS(&tfs_08_valid), 0x80, NULL, HFILL }},
{ &hf_ipmi_chs_08_selector,
{ "Boot option parameter selector",
"ipmi.ch08.selector", FT_UINT8, BASE_HEX, NULL, 0x7f, NULL, HFILL }},
{ &hf_ipmi_chs_08_data,
{ "Boot option parameter data",
"ipmi.ch08.data", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_09_rq_param_select,
{ "Parameter selector",
"ipmi.ch09.rq_param_select", FT_UINT8, BASE_HEX, NULL, 0x7f, NULL, HFILL }},
{ &hf_ipmi_chs_09_rq_set_select,
{ "Set Selector",
"ipmi.ch09.rq_set_select", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_09_rq_block_select,
{ "Block Selector",
"ipmi.ch09.rq_block_select", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_09_rs_param_version,
{ "Parameter Version",
"ipmi.ch09.rs_param_version", FT_UINT8, BASE_HEX, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_chs_09_rs_valid,
{ "Parameter Valid",
"ipmi.ch09.rs_valid", FT_BOOLEAN, 8, TFS(&tfs_09_valid), 0x80, NULL, HFILL }},
{ &hf_ipmi_chs_09_rs_param_select,
{ "Parameter Selector",
"ipmi.ch09.rs_param_select", FT_UINT8, BASE_HEX, NULL, 0x7f, NULL, HFILL }},
{ &hf_ipmi_chs_09_rs_param_data,
{ "Configuration parameter data",
"ipmi.ch09.rs_param_data", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_0f_minpercnt,
{ "Minutes per count",
"ipmi.ch0f.minpercnt", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_chs_0f_counter,
{ "Counter reading",
"ipmi.ch0f.counter", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ipmi_chs_bo00_byte1,
&ett_ipmi_chs_bo02_byte1,
&ett_ipmi_chs_bo03_byte1,
&ett_ipmi_chs_bo04_byte2,
&ett_ipmi_chs_bo05_byte1,
&ett_ipmi_chs_bo05_byte2,
&ett_ipmi_chs_bo05_byte3,
&ett_ipmi_chs_bo05_byte4,
&ett_ipmi_chs_bo06_byte1,
&ett_ipmi_chs_00_capflags,
&ett_ipmi_chs_01_pwr_state,
&ett_ipmi_chs_01_last_event,
&ett_ipmi_chs_01_misc,
&ett_ipmi_chs_01_fpb,
&ett_ipmi_chs_02_byte1,
&ett_ipmi_chs_04_byte2,
&ett_ipmi_chs_05_flags,
&ett_ipmi_chs_06_byte1,
&ett_ipmi_chs_06_policy_support,
&ett_ipmi_chs_07_byte1,
&ett_ipmi_chs_08_byte1,
&ett_ipmi_chs_09_rq_byte1,
&ett_ipmi_chs_09_rs_byte1,
&ett_ipmi_chs_09_rs_byte2,
};
proto_register_field_array(proto_ipmi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ipmi_register_netfn_cmdtab(IPMI_CHASSIS_REQ, IPMI_OEM_NONE, NULL, 0, NULL,
cmd_chassis, array_length(cmd_chassis));
}
