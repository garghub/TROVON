static void
rs01(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte2[] = { &hf_ipmi_app_01_dev_prov_sdr, &hf_ipmi_app_01_dev_rev, NULL };
static const gint *byte3[] = { &hf_ipmi_app_01_dev_avail, &hf_ipmi_app_01_fw_rev_maj, NULL };
static const gint *byte6[] = { &hf_ipmi_app_01_ipmi_ads_chassis, &hf_ipmi_app_01_ipmi_ads_bridge,
&hf_ipmi_app_01_ipmi_ads_ipmb_ev_gen, &hf_ipmi_app_01_ipmi_ads_ipmb_ev_recv,
&hf_ipmi_app_01_ipmi_ads_fru, &hf_ipmi_app_01_ipmi_ads_sel, &hf_ipmi_app_01_ipmi_ads_sdr,
&hf_ipmi_app_01_ipmi_ads_sensor, NULL };
size_t len;
len = tvb_captured_length(tvb);
proto_tree_add_item(tree, hf_ipmi_app_01_dev_id, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_app_01_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, NULL, NULL, ett_ipmi_app_01_byte3, byte3, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_app_01_fw_rev_min, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_app_01_ipmi_version, tvb, 4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 5, 1, "Additional device support: ", "None",
ett_ipmi_app_01_byte6, byte6, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_app_01_manufacturer, tvb, 6, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_app_01_product, tvb, 9, 2, ENC_LITTLE_ENDIAN);
if (len > 11) {
proto_tree_add_item(tree, hf_ipmi_app_01_fw_aux, tvb, 11, 4, ENC_NA);
}
}
static void
rs04(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte2[] = { &hf_ipmi_app_04_fail_sel, &hf_ipmi_app_04_fail_sdr,
&hf_ipmi_app_04_fail_bmc_fru, &hf_ipmi_app_04_fail_ipmb_sig, &hf_ipmi_app_04_fail_sdr_empty,
&hf_ipmi_app_04_fail_iua, &hf_ipmi_app_04_fail_bb_fw, &hf_ipmi_app_04_fail_oper_fw, NULL };
int res, fail;
res = tvb_get_guint8(tvb, 0);
fail = tvb_get_guint8(tvb, 1);
proto_tree_add_uint_format_value(tree, hf_ipmi_app_04_result, tvb, 0, 1,
res, "%s (0x%02x)",
val_to_str_const(res, vals_04_result, "Device-specific internal failure"),
res);
if (res == 0x55 || res == 0x56 || res == 0xff) {
proto_tree_add_uint_format_value(tree, hf_ipmi_app_04_fail, tvb, 1, 1,
fail, "0x%02x (must be 0x00)",
fail);
return;
}
if (res != 0x57) {
proto_tree_add_uint_format_value(tree, hf_ipmi_app_04_fail, tvb, 1, 1,
fail, "0x%02x (device-specific)",
fail);
return;
}
proto_tree_add_bitmask(tree, tvb, 1, hf_ipmi_app_04_fail, ett_ipmi_app_04_byte2, byte2, ENC_LITTLE_ENDIAN);
}
static void
rq05(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_app_05_devspec, tvb, 0, -1, ENC_NA);
}
static void
rq06(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_06_syspwr_set, &hf_ipmi_app_06_syspwr_enum, NULL };
static const gint *byte2[] = { &hf_ipmi_app_06_devpwr_set, &hf_ipmi_app_06_devpwr_enum, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "ACPI System Power State: ", NULL,
ett_ipmi_app_06_syspwr, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, "ACPI Device Power State: ", NULL,
ett_ipmi_app_06_devpwr, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
rs07(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_07_syspwr_enum, NULL };
static const gint *byte2[] = { &hf_ipmi_app_07_devpwr_enum, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "ACPI System Power State: ", NULL,
ett_ipmi_app_07_syspwr, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, "ACPI Device Power State: ", NULL,
ett_ipmi_app_07_devpwr, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
rs08(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
ipmi_add_guid(tree, hf_ipmi_app_08_guid, tvb, 0);
}
static void
rq24(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_24_timer_use_dont_log,
&hf_ipmi_app_24_timer_use_dont_stop, &hf_ipmi_app_24_timer_use_timer_use, NULL };
static const gint *byte2[] = { &hf_ipmi_app_24_timer_action_interrupt,
&hf_ipmi_app_24_timer_action_timeout_action, NULL };
static const gint *byte4[] = { &hf_ipmi_app_24_expiration_flags_oem,
&hf_ipmi_app_24_expiration_flags_smsos, &hf_ipmi_app_24_expiration_flags_osload,
&hf_ipmi_app_24_expiration_flags_biospost, &hf_ipmi_app_24_expiration_flags_biosfrb2, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Timer Use: ", NULL, ett_ipmi_app_24_timer_use,
byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_app_24_timer_action,
byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_app_24_pretimeout, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 3, 1, "Timer Use Expiration flags clear: ", "None",
ett_ipmi_app_24_expiration_flags, byte4, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
proto_tree_add_item(tree, hf_ipmi_app_24_initial_countdown, tvb, 4, 2, ENC_LITTLE_ENDIAN);
}
static void
rs25(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_25_timer_use_dont_log,
&hf_ipmi_app_25_timer_use_started, &hf_ipmi_app_25_timer_use_timer_use, NULL };
static const gint *byte2[] = { &hf_ipmi_app_25_timer_action_interrupt,
&hf_ipmi_app_25_timer_action_timeout_action, NULL };
static const gint *byte4[] = { &hf_ipmi_app_25_expiration_flags_oem, &hf_ipmi_app_25_expiration_flags_smsos,
&hf_ipmi_app_25_expiration_flags_osload, &hf_ipmi_app_25_expiration_flags_biospost,
&hf_ipmi_app_25_expiration_flags_biosfrb2, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Timer Use: ", NULL, ett_ipmi_app_25_timer_use,
byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_app_25_timer_action,
byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_app_25_pretimeout, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 3, 1, "Timer Use Expiration flags: ", "None",
ett_ipmi_app_25_expiration_flags, byte4, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
proto_tree_add_item(tree, hf_ipmi_app_25_initial_countdown, tvb, 4, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_app_25_present_countdown, tvb, 6, 2, ENC_LITTLE_ENDIAN);
}
static void
rq2e(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_2e_byte1_oem2, &hf_ipmi_app_2e_byte1_oem1,
&hf_ipmi_app_2e_byte1_oem0, &hf_ipmi_app_2e_byte1_sel, &hf_ipmi_app_2e_byte1_emb,
&hf_ipmi_app_2e_byte1_emb_full_intr, &hf_ipmi_app_2e_byte1_rmq_intr, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Enables: ", "None", ett_ipmi_app_2e_byte1,
byte1, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
}
static void
rs2f(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_2f_byte1_oem2, &hf_ipmi_app_2f_byte1_oem1,
&hf_ipmi_app_2f_byte1_oem0, &hf_ipmi_app_2f_byte1_sel, &hf_ipmi_app_2f_byte1_emb,
&hf_ipmi_app_2f_byte1_emb_full_intr, &hf_ipmi_app_2f_byte1_rmq_intr, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Enables: ", "None", ett_ipmi_app_2f_byte1,
byte1, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
}
static void
rq30(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_30_byte1_oem2, &hf_ipmi_app_30_byte1_oem1,
&hf_ipmi_app_30_byte1_oem0, &hf_ipmi_app_30_byte1_wd_pretimeout,
&hf_ipmi_app_30_byte1_emb, &hf_ipmi_app_30_byte1_rmq, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Clear Message Flags: ", "None",
ett_ipmi_app_30_byte1, byte1, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
}
static void
rs31(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_31_byte1_oem2, &hf_ipmi_app_31_byte1_oem1,
&hf_ipmi_app_31_byte1_oem0, &hf_ipmi_app_31_byte1_wd_pretimeout,
&hf_ipmi_app_31_byte1_emb, &hf_ipmi_app_31_byte1_rmq, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, "Flags: ", "None",
ett_ipmi_app_31_byte1, byte1, ENC_LITTLE_ENDIAN, BMT_NO_TFS);
}
static void
rq32(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_32_rq_chno, NULL };
static const gint *byte2[] = { &hf_ipmi_app_32_rq_state, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_app_32_rq_byte1,
byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_app_32_rq_byte2,
byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
rs32(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_32_rs_chno, NULL };
static const gint *byte2[] = { &hf_ipmi_app_32_rs_state, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_app_32_rs_byte1,
byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_app_32_rs_byte2,
byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
rs33(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_33_rs_chan,
&hf_ipmi_app_33_rs_priv, NULL };
tvbuff_t *next;
ipmi_dissect_arg_t arg;
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_app_33_rs_byte1,
byte1, ENC_LITTLE_ENDIAN, 0);
next = tvb_new_subset_remaining(tvb, 1);
arg.context = IPMI_E_GETMSG;
arg.channel = tvb_get_guint8(tvb, 0) & 0xF;
arg.flags = 0;
do_dissect_ipmb(next, pinfo, tree,
hf_ipmi_app_33_msg, ett_ipmi_app_33_msg, &arg);
}
static void
rq34(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_34_track, &hf_ipmi_app_34_encrypt,
&hf_ipmi_app_34_auth, &hf_ipmi_app_34_chan, NULL };
tvbuff_t *next;
ipmi_dissect_arg_t arg;
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_app_34_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
next = tvb_new_subset_remaining(tvb, 1);
arg.context = IPMI_E_SENDMSG_RQ;
arg.channel = tvb_get_guint8(tvb, 0) & 0xF;
arg.flags = 0;
do_dissect_ipmb(next, pinfo, tree,
hf_ipmi_app_34_msg, ett_ipmi_app_34_msg, &arg);
}
static void
rs34(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tvb_captured_length(tvb)) {
ipmi_dissect_arg_t arg;
arg.context = IPMI_E_SENDMSG_RS;
arg.channel = 0;
arg.flags = 0;
do_dissect_ipmb(tvb, pinfo, tree,
hf_ipmi_app_34_msg, ett_ipmi_app_34_msg, &arg);
}
}
static void
rq38(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_38_rq_ipmi20, &hf_ipmi_app_38_rq_chan, NULL };
static const gint *byte2[] = { &hf_ipmi_app_38_rq_priv, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_app_38_rq_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_app_38_rq_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
}
static void
rs38(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_38_rs_chan, NULL };
static const gint *byte2[] = { &hf_ipmi_app_38_rs_ipmi20, &hf_ipmi_app_38_rs_auth_oem,
&hf_ipmi_app_38_rs_auth_straight, &hf_ipmi_app_38_rs_auth_md5, &hf_ipmi_app_38_rs_auth_md2,
&hf_ipmi_app_38_rs_auth_none, NULL };
static const gint *byte3[] = { &hf_ipmi_app_38_rs_kg, &hf_ipmi_app_38_rs_permsg, &hf_ipmi_app_38_rs_userauth,
&hf_ipmi_app_38_rs_user_nonnull, &hf_ipmi_app_38_rs_user_null, &hf_ipmi_app_38_rs_user_anon, NULL };
static const gint *byte4[] = { &hf_ipmi_app_38_rs_ipmi20_conn, &hf_ipmi_app_38_rs_ipmi15_conn, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL, ett_ipmi_app_38_rs_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL, ett_ipmi_app_38_rs_byte2, byte2, ENC_LITTLE_ENDIAN, BMT_NO_FALSE);
proto_tree_add_bitmask_text(tree, tvb, 2, 1, NULL, NULL, ett_ipmi_app_38_rs_byte3, byte3, ENC_LITTLE_ENDIAN, BMT_NO_FALSE);
proto_tree_add_bitmask_text(tree, tvb, 3, 1, "Supported connections: ", "None",
ett_ipmi_app_38_rs_byte4, byte4, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_app_38_rs_oem_iana, tvb, 4, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_app_38_rs_oem_aux, tvb, 7, 1, ENC_LITTLE_ENDIAN);
}
static void
rq39(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_39_authtype, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_app_39_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_app_39_user, tvb, 1, 16, ENC_ASCII|ENC_NA);
}
static void
rs39(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_app_39_temp_session, tvb, 0, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_app_39_challenge, tvb, 4, 16, ENC_NA);
}
static void
rq3a(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_3a_authtype, NULL };
static const gint *byte2[] = { &hf_ipmi_app_3a_privlevel, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_app_3a_rq_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_bitmask_text(tree, tvb, 1, 1, NULL, NULL,
ett_ipmi_app_3a_rq_byte2, byte2, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_app_3a_authcode, tvb, 2, 16, ENC_NA);
proto_tree_add_item(tree, hf_ipmi_app_3a_outbound_seq, tvb, 18, 4, ENC_LITTLE_ENDIAN);
}
static void
rs3a(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_3a_authtype_session, NULL };
static const gint *byte10[] = { &hf_ipmi_app_3a_maxpriv_session, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_app_3a_rs_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
proto_tree_add_item(tree, hf_ipmi_app_3a_session_id, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_ipmi_app_3a_inbound_seq, tvb, 5, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_bitmask_text(tree, tvb, 9, 1, NULL, NULL,
ett_ipmi_app_3a_rs_byte10, byte10, ENC_LITTLE_ENDIAN, 0);
}
static void
rq3b(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_3b_req_priv, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_app_3b_rq_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rs3b(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
static const gint *byte1[] = { &hf_ipmi_app_3b_new_priv, NULL };
proto_tree_add_bitmask_text(tree, tvb, 0, 1, NULL, NULL,
ett_ipmi_app_3b_rs_byte1, byte1, ENC_LITTLE_ENDIAN, 0);
}
static void
rq3c(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_tree_add_item(tree, hf_ipmi_app_3c_session_id, tvb, 0, 4, ENC_LITTLE_ENDIAN);
if (tvb_captured_length(tvb) > 4) {
proto_tree_add_item(tree, hf_ipmi_app_3c_session_handle, tvb, 4, 1, ENC_LITTLE_ENDIAN);
}
}
void
proto_register_ipmi_app(void)
{
static hf_register_info hf[] = {
{ &hf_ipmi_app_01_dev_id,
{ "Device ID",
"ipmi.app00.dev.id", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_01_dev_prov_sdr,
{ "Device provides Device SDRs",
"ipmi.app00.dev.provides_dev_sdr", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_app_01_dev_rev,
{ "Device Revision (binary encoded)",
"ipmi.app00.dev.rev", FT_UINT8, BASE_HEX, NULL, 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_01_dev_avail,
{ "Device availability",
"ipmi.app01.dev.avail", FT_BOOLEAN, 8, TFS(&tfs_01_dev_avail), 0x80, NULL, HFILL }},
{ &hf_ipmi_app_01_fw_rev_maj,
{ "Major Firmware Revision (binary encoded)",
"ipmi.app01.fw.major", FT_UINT8, BASE_HEX, NULL, 0x7f, NULL, HFILL }},
{ &hf_ipmi_app_01_fw_rev_min,
{ "Minor Firmware Revision (BCD encoded)",
"ipmi.app01.fw.minor", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_01_ipmi_version,
{ "IPMI version",
"ipmi.app01.ipmi.version", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_version), 0, NULL, HFILL }},
{ &hf_ipmi_app_01_ipmi_ads_chassis,
{ "Chassis",
"ipmi.app01.ads.chassis", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_app_01_ipmi_ads_bridge,
{ "Bridge",
"ipmi.app01.ads.bridge", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ipmi_app_01_ipmi_ads_ipmb_ev_gen,
{ "Event Generator",
"ipmi.app01.ads.ipmb_ev_gen", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ipmi_app_01_ipmi_ads_ipmb_ev_recv,
{ "Event Receiver",
"ipmi.app01.ads.ipmb_ev_recv", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_app_01_ipmi_ads_fru,
{ "FRU Inventory",
"ipmi.app01.ads.fru", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_app_01_ipmi_ads_sel,
{ "SEL",
"ipmi.app01.ads.sel", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_app_01_ipmi_ads_sdr,
{ "SDR Repository",
"ipmi.app01.ads.sdr", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_app_01_ipmi_ads_sensor,
{ "Sensor",
"ipmi.app01.ads.sensor", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_app_01_manufacturer,
{ "Manufacturer ID",
"ipmi.app01.manufacturer", FT_UINT24, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_01_product,
{ "Product ID",
"ipmi.app01.product", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_01_fw_aux,
{ "Auxiliary Firmware Revision Information",
"ipmi.app01.fw.aux", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_04_result,
{ "Self test result",
"ipmi.app04.self_test_result", FT_UINT8, BASE_HEX, VALS(vals_04_result), 0, NULL, HFILL }},
{ &hf_ipmi_app_04_fail,
{ "Self-test error bitfield",
"ipmi.app04.fail", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_04_fail_sel,
{ "Cannot access SEL device",
"ipmi.app04.fail.sel", FT_BOOLEAN, 8, TFS(&tfs_04_fail_unknown), 0x80, NULL, HFILL }},
{ &hf_ipmi_app_04_fail_sdr,
{ "Cannot access SDR Repository",
"ipmi.app04.fail.sdr", FT_BOOLEAN, 8, TFS(&tfs_04_fail_unknown), 0x40, NULL, HFILL }},
{ &hf_ipmi_app_04_fail_bmc_fru,
{ "Cannot access BMC FRU device",
"ipmi.app04.fail.bmc_fru", FT_BOOLEAN, 8, TFS(&tfs_04_fail_unknown), 0x20, NULL, HFILL }},
{ &hf_ipmi_app_04_fail_ipmb_sig,
{ "IPMB signal lines do not respond",
"ipmi.app04.fail.ipmb_sig", FT_BOOLEAN, 8, TFS(&tfs_04_fail_unknown), 0x10, NULL, HFILL }},
{ &hf_ipmi_app_04_fail_sdr_empty,
{ "SDR Repository is empty",
"ipmi.app04.fail.sdr_empty", FT_BOOLEAN, 8, TFS(&tfs_04_fail_unknown), 0x08, NULL, HFILL }},
{ &hf_ipmi_app_04_fail_iua,
{ "Internal Use Area of BMC FRU corrupted",
"ipmi.app04.fail.iua", FT_BOOLEAN, 8, TFS(&tfs_04_fail_unknown), 0x04, NULL, HFILL }},
{ &hf_ipmi_app_04_fail_bb_fw,
{ "Controller update boot block firmware corrupted",
"ipmi.app04.fail.bb_fw", FT_BOOLEAN, 8, TFS(&tfs_04_fail_unknown), 0x02, NULL, HFILL }},
{ &hf_ipmi_app_04_fail_oper_fw,
{ "Controller operational firmware corrupted",
"ipmi.app04.fail.oper_fw", FT_BOOLEAN, 8, TFS(&tfs_04_fail_unknown), 0x01, NULL, HFILL }},
{ &hf_ipmi_app_05_devspec,
{ "Device-specific parameters",
"ipmi.app05.devspec", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_06_syspwr_set,
{ "System Power State",
"ipmi.app06.syspwr.set", FT_BOOLEAN, 8, TFS(&tfs_06_pwr), 0x80, NULL, HFILL }},
{ &hf_ipmi_app_06_syspwr_enum,
{ "System Power State enumeration",
"ipmi.app06.syspwr.enum", FT_UINT8, BASE_HEX, VALS(vals_06_syspwr), 0x7f, NULL, HFILL }},
{ &hf_ipmi_app_06_devpwr_set,
{ "Device Power State",
"ipmi.app06.devpwr.set", FT_BOOLEAN, 8, TFS(&tfs_06_pwr), 0x80, NULL, HFILL }},
{ &hf_ipmi_app_06_devpwr_enum,
{ "Device Power State enumeration",
"ipmi.app06.devpwr.enum", FT_UINT8, BASE_HEX, VALS(vals_06_devpwr), 0x7f, NULL, HFILL }},
{ &hf_ipmi_app_07_syspwr_enum,
{ "ACPI System Power State",
"ipmi.app07.syspwr", FT_UINT8, BASE_HEX, VALS(vals_07_syspwr), 0x7f, NULL, HFILL }},
{ &hf_ipmi_app_07_devpwr_enum,
{ "ACPI Device Power State",
"ipmi.app07.devpwr", FT_UINT8, BASE_HEX, VALS(vals_07_devpwr), 0x7f, NULL, HFILL }},
{ &hf_ipmi_app_08_guid,
{ "GUID",
"ipmi.app08.guid", FT_GUID, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_24_timer_use_dont_log,
{ "Don't log",
"ipmi.app24.timer_use.dont_log", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_app_24_timer_use_dont_stop,
{ "Don't stop timer on Set Watchdog command",
"ipmi.app24.timer_use.dont_stop", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ipmi_app_24_timer_use_timer_use,
{ "Timer use",
"ipmi.app24.timer_use.timer_use", FT_UINT8, BASE_HEX, VALS(vals_24_timer_use), 0x07, NULL, HFILL }},
{ &hf_ipmi_app_24_timer_action_interrupt,
{ "Pre-timeout interrupt",
"ipmi.app24.timer_action.interrupt", FT_UINT8, BASE_HEX, VALS(vals_24_timer_action_interrupt), 0x70, NULL, HFILL }},
{ &hf_ipmi_app_24_timer_action_timeout_action,
{ "Timeout action",
"ipmi.app24.timer_action.timeout", FT_UINT8, BASE_HEX, VALS(vals_24_timer_action_timeout), 0x07, NULL, HFILL }},
{ &hf_ipmi_app_24_pretimeout,
{ "Pre-timeout interval",
"ipmi.app24.pretimeout", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_1s_1based), 0, NULL, HFILL }},
{ &hf_ipmi_app_24_expiration_flags_oem,
{ "OEM",
"ipmi.app24.exp_flags.oem", FT_BOOLEAN, 8, TFS(&tfs_24_exp_flags), 0x20, NULL, HFILL }},
{ &hf_ipmi_app_24_expiration_flags_smsos,
{ "SMS/OS",
"ipmi.app24.exp_flags.sms_os", FT_BOOLEAN, 8, TFS(&tfs_24_exp_flags), 0x10, NULL, HFILL }},
{ &hf_ipmi_app_24_expiration_flags_osload,
{ "OS Load",
"ipmi.app24.exp_flags.osload", FT_BOOLEAN, 8, TFS(&tfs_24_exp_flags), 0x08, NULL, HFILL }},
{ &hf_ipmi_app_24_expiration_flags_biospost,
{ "BIOS/POST",
"ipmi.app24.exp_flags.biospost", FT_BOOLEAN, 8, TFS(&tfs_24_exp_flags), 0x04, NULL, HFILL }},
{ &hf_ipmi_app_24_expiration_flags_biosfrb2,
{ "BIOS FRB2",
"ipmi.app24.exp_flags.biosfrb2", FT_BOOLEAN, 8, TFS(&tfs_24_exp_flags), 0x02, NULL, HFILL }},
{ &hf_ipmi_app_24_initial_countdown,
{ "Initial countdown value (100ms/count)",
"ipmi.app24.initial_countdown", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_25_timer_use_dont_log,
{ "Don't log",
"ipmi.app25.timer_use.dont_log", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_app_25_timer_use_started,
{ "Started",
"ipmi.app25.timer_use.started", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ipmi_app_25_timer_use_timer_use,
{ "Timer user",
"ipmi.app25.timer_use.timer_use", FT_UINT8, BASE_HEX, VALS(vals_24_timer_use), 0x07, NULL, HFILL }},
{ &hf_ipmi_app_25_timer_action_interrupt,
{ "Pre-timeout interrupt",
"ipmi.app25.timer_action.interrupt", FT_UINT8, BASE_HEX, VALS(vals_24_timer_action_interrupt), 0x70, NULL, HFILL }},
{ &hf_ipmi_app_25_timer_action_timeout_action,
{ "Timeout action",
"ipmi.app25.timer_action.timeout", FT_UINT8, BASE_HEX, VALS(vals_24_timer_action_timeout), 0x07, NULL, HFILL }},
{ &hf_ipmi_app_25_pretimeout,
{ "Pre-timeout interval",
"ipmi.app25.pretimeout", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_1s_1based), 0, NULL, HFILL }},
{ &hf_ipmi_app_25_expiration_flags_oem,
{ "OEM",
"ipmi.app25.exp_flags.oem", FT_BOOLEAN, 8, TFS(&tfs_24_exp_flags), 0x20, NULL, HFILL }},
{ &hf_ipmi_app_25_expiration_flags_smsos,
{ "SMS/OS",
"ipmi.app25.exp_flags.sms_os", FT_BOOLEAN, 8, TFS(&tfs_24_exp_flags), 0x10, NULL, HFILL }},
{ &hf_ipmi_app_25_expiration_flags_osload,
{ "OS Load",
"ipmi.app25.exp_flags.osload", FT_BOOLEAN, 8, TFS(&tfs_24_exp_flags), 0x08, NULL, HFILL }},
{ &hf_ipmi_app_25_expiration_flags_biospost,
{ "BIOS/POST",
"ipmi.app25.exp_flags.biospost", FT_BOOLEAN, 8, TFS(&tfs_24_exp_flags), 0x04, NULL, HFILL }},
{ &hf_ipmi_app_25_expiration_flags_biosfrb2,
{ "BIOS FRB2",
"ipmi.app25.exp_flags.biosfrb2", FT_BOOLEAN, 8, TFS(&tfs_24_exp_flags), 0x02, NULL, HFILL }},
{ &hf_ipmi_app_25_initial_countdown,
{ "Initial countdown value (100ms/count)",
"ipmi.app25.initial_countdown", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_25_present_countdown,
{ "Present countdown value (100ms/count)",
"ipmi.app25.initial_countdown", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_2e_byte1_oem2,
{ "OEM 2",
"ipmi.app2e.bmc_global_enables.oem2", FT_BOOLEAN, 8, TFS(&tfs_2e_enable), 0x80, NULL, HFILL }},
{ &hf_ipmi_app_2e_byte1_oem1,
{ "OEM 1",
"ipmi.app2e.bmc_global_enables.oem1", FT_BOOLEAN, 8, TFS(&tfs_2e_enable), 0x40, NULL, HFILL }},
{ &hf_ipmi_app_2e_byte1_oem0,
{ "OEM 0",
"ipmi.app2e.bmc_global_enables.oem0", FT_BOOLEAN, 8, TFS(&tfs_2e_enable), 0x20, NULL, HFILL }},
{ &hf_ipmi_app_2e_byte1_sel,
{ "System Event Logging",
"ipmi.app2e.bmc_global_enables.sel", FT_BOOLEAN, 8, TFS(&tfs_2e_enable), 0x08, NULL, HFILL }},
{ &hf_ipmi_app_2e_byte1_emb,
{ "Event Message Buffer",
"ipmi.app2e.bmc_global_enables.emb", FT_BOOLEAN, 8, TFS(&tfs_2e_enable), 0x04, NULL, HFILL }},
{ &hf_ipmi_app_2e_byte1_emb_full_intr,
{ "Event Message Buffer Full Interrupt",
"ipmi.app2e.bmc_global_enables.emb_full_intr", FT_BOOLEAN, 8, TFS(&tfs_2e_enable), 0x02, NULL, HFILL }},
{ &hf_ipmi_app_2e_byte1_rmq_intr,
{ "Receive Message Queue Interrupt",
"ipmi.app2e.bmc_global_enables.rmq_intr", FT_BOOLEAN, 8, TFS(&tfs_2e_enable), 0x01, NULL, HFILL }},
{ &hf_ipmi_app_2f_byte1_oem2,
{ "OEM 2",
"ipmi.app2f.bmc_global_enables.oem2", FT_BOOLEAN, 8, TFS(&tfs_2f_enabled), 0x80, NULL, HFILL }},
{ &hf_ipmi_app_2f_byte1_oem1,
{ "OEM 1",
"ipmi.app2f.bmc_global_enables.oem1", FT_BOOLEAN, 8, TFS(&tfs_2f_enabled), 0x40, NULL, HFILL }},
{ &hf_ipmi_app_2f_byte1_oem0,
{ "OEM 0",
"ipmi.app2f.bmc_global_enables.oem0", FT_BOOLEAN, 8, TFS(&tfs_2f_enabled), 0x20, NULL, HFILL }},
{ &hf_ipmi_app_2f_byte1_sel,
{ "System Event Logging",
"ipmi.app2f.bmc_global_enables.sel", FT_BOOLEAN, 8, TFS(&tfs_2f_enabled), 0x08, NULL, HFILL }},
{ &hf_ipmi_app_2f_byte1_emb,
{ "Event Message Buffer",
"ipmi.app2f.bmc_global_enables.emb", FT_BOOLEAN, 8, TFS(&tfs_2f_enabled), 0x04, NULL, HFILL }},
{ &hf_ipmi_app_2f_byte1_emb_full_intr,
{ "Event Message Buffer Full Interrupt",
"ipmi.app2f.bmc_global_enables.emb_full_intr", FT_BOOLEAN, 8, TFS(&tfs_2f_enabled), 0x02, NULL, HFILL }},
{ &hf_ipmi_app_2f_byte1_rmq_intr,
{ "Receive Message Queue Interrupt",
"ipmi.app2f.bmc_global_enables.rmq_intr", FT_BOOLEAN, 8, TFS(&tfs_2f_enabled), 0x01, NULL, HFILL }},
{ &hf_ipmi_app_30_byte1_oem2,
{ "OEM 2",
"ipmi.app30.byte1.oem2", FT_BOOLEAN, 8, TFS(&tfs_30_clear), 0x80, NULL, HFILL }},
{ &hf_ipmi_app_30_byte1_oem1,
{ "OEM 1",
"ipmi.app30.byte1.oem1", FT_BOOLEAN, 8, TFS(&tfs_30_clear), 0x40, NULL, HFILL }},
{ &hf_ipmi_app_30_byte1_oem0,
{ "OEM 0",
"ipmi.app30.byte1.oem0", FT_BOOLEAN, 8, TFS(&tfs_30_clear), 0x20, NULL, HFILL }},
{ &hf_ipmi_app_30_byte1_wd_pretimeout,
{ "Watchdog pre-timeout interrupt flag",
"ipmi.app30.byte1.wd_pretimeout", FT_BOOLEAN, 8, TFS(&tfs_30_clear), 0x08, NULL, HFILL }},
{ &hf_ipmi_app_30_byte1_emb,
{ "Event Message Buffer",
"ipmi.app30.byte1.emb", FT_BOOLEAN, 8, TFS(&tfs_30_clear), 0x02, NULL, HFILL }},
{ &hf_ipmi_app_30_byte1_rmq,
{ "Receive Message Queue",
"ipmi.app30.byte1.rmq", FT_BOOLEAN, 8, TFS(&tfs_30_clear), 0x01, NULL, HFILL }},
{ &hf_ipmi_app_31_byte1_oem2,
{ "OEM 2 data available",
"ipmi.app31.byte1.oem2", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_ipmi_app_31_byte1_oem1,
{ "OEM 1 data available",
"ipmi.app31.byte1.oem1", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_ipmi_app_31_byte1_oem0,
{ "OEM 0 data available",
"ipmi.app31.byte1.oem0", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ipmi_app_31_byte1_wd_pretimeout,
{ "Watchdog pre-timeout interrupt occurred",
"ipmi.app31.byte1.wd_pretimeout", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_app_31_byte1_emb,
{ "Event Message Buffer Full",
"ipmi.app31.byte1.emb", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_app_31_byte1_rmq,
{ "Receive Message Available",
"ipmi.app31.byte1.rmq", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_app_32_rq_chno,
{ "Channel",
"ipmi.app32.rq_chno", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_channel), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_32_rq_state,
{ "Channel State",
"ipmi.app32.rq_state", FT_UINT8, BASE_HEX, VALS(vals_32_state), 0x03, NULL, HFILL }},
{ &hf_ipmi_app_32_rs_chno,
{ "Channel",
"ipmi.app32.rs_chno", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_channel), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_32_rs_state,
{ "Channel State",
"ipmi.app32.rs_state", FT_BOOLEAN, 8, TFS(&tfs_32_state), 0x01, NULL, HFILL }},
{ &hf_ipmi_app_33_rs_chan,
{ "Channel",
"ipmi.app33.chan", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_channel), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_33_rs_priv,
{ "Inferred privilege level",
"ipmi.app33.priv", FT_UINT8, BASE_HEX, VALS(vals_XX_priv), 0xf0, NULL, HFILL }},
{ &hf_ipmi_app_33_msg,
{ "Message data",
"ipmi.app33.msg", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_34_track,
{ "Tracking",
"ipmi.app34.track", FT_UINT8, BASE_HEX, VALS(vals_34_track), 0xc0, NULL, HFILL }},
{ &hf_ipmi_app_34_encrypt,
{ "Encryption required",
"ipmi.app34.encrypt", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_ipmi_app_34_auth,
{ "Authentication required",
"ipmi.app34.auth", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_app_34_chan,
{ "Channel",
"ipmi.app34.chan", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_channel), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_34_msg,
{ "Embedded message",
"ipmi.app34.msg", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_38_rq_ipmi20,
{ "Version compatibility",
"ipmi.app38.rq_ipmi20", FT_UINT8, BASE_DEC, VALS(vals_38_ipmi20), 0x80, NULL, HFILL }},
{ &hf_ipmi_app_38_rq_chan,
{ "Channel",
"ipmi.app38.rq_chan", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_channel), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_38_rq_priv,
{ "Requested privilege level",
"ipmi.app38.rq_priv", FT_UINT8, BASE_HEX, VALS(vals_XX_priv), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_chan,
{ "Channel",
"ipmi.app38.rs_chan", FT_UINT8, BASE_CUSTOM, CF_FUNC(ipmi_fmt_channel), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_ipmi20,
{ "Version compatibility",
"ipmi.app38.rs_ipmi20", FT_UINT8, BASE_DEC, VALS(vals_38_ipmi20), 0x80, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_auth_oem,
{ "OEM Proprietary authentication",
"ipmi.app38.rs_auth_oem", FT_BOOLEAN, 8, TFS(&tfs_38_supp), 0x20, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_auth_straight,
{ "Straight password/key",
"ipmi.app38.rs_auth_straight", FT_BOOLEAN, 8, TFS(&tfs_38_supp), 0x10, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_auth_md5,
{ "MD5",
"ipmi.app38.rs_auth_md5", FT_BOOLEAN, 8, TFS(&tfs_38_supp), 0x04, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_auth_md2,
{ "MD2",
"ipmi.app38.rs_auth_md2", FT_BOOLEAN, 8, TFS(&tfs_38_supp), 0x02, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_auth_none,
{ "No auth",
"ipmi.app38.rs_auth_none", FT_BOOLEAN, 8, TFS(&tfs_38_supp), 0x01, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_kg,
{ "KG",
"ipmi.app38.rs_kg_status", FT_BOOLEAN, 8, TFS(&tfs_38_kg), 0x20, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_permsg,
{ "Per-message Authentication disabled",
"ipmi.app38.rs_permsg", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_userauth,
{ "User-level Authentication disabled",
"ipmi.app38.rs_userauth", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_user_nonnull,
{ "Non-null usernames enabled",
"ipmi.app38.rs_user_nonnull", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_user_null,
{ "Null usernames enabled",
"ipmi.app38.rs_user_null", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_user_anon,
{ "Anonymous login enabled",
"ipmi.app38.rs_user_anon", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_ipmi20_conn,
{ "IPMI v2.0",
"ipmi.app38.rs_ipmi20_conn", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_ipmi15_conn,
{ "IPMI v1.5",
"ipmi.app38.rs_ipmi15_conn", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_oem_iana,
{ "OEM ID",
"ipmi.app38.rs_oem_iana", FT_UINT24, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_38_rs_oem_aux,
{ "OEM Auxiliary data",
"ipmi.app38.rs_oem_aux", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_39_authtype,
{ "Authentication Type",
"ipmi.app39.authtype", FT_UINT8, BASE_HEX, VALS(vals_XX_auth), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_39_user,
{ "User Name",
"ipmi.app39.user", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_39_temp_session,
{ "Temporary Session ID",
"ipmi.app39.temp_session", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_39_challenge,
{ "Challenge",
"ipmi.app39.challenge", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_3a_authtype,
{ "Authentication Type",
"ipmi.app3a.authtype", FT_UINT8, BASE_HEX, VALS(vals_XX_auth), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_3a_privlevel,
{ "Requested Maximum Privilege Level",
"ipmi.app3a.privlevel", FT_UINT8, BASE_HEX, VALS(vals_XX_priv), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_3a_authcode,
{ "Challenge string/Auth Code",
"ipmi.app3a.authcode", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_3a_outbound_seq,
{ "Initial Outbound Sequence Number",
"ipmi.app3a.outbound_seq", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_3a_authtype_session,
{ "Authentication Type for session",
"ipmi.app3a.authtype_session", FT_UINT8, BASE_HEX, VALS(vals_XX_auth), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_3a_session_id,
{ "Session ID",
"ipmi.app3a.session_id", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_3a_inbound_seq,
{ "Initial Inbound Sequence Number",
"ipmi.app3a.inbound_seq", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_3a_maxpriv_session,
{ "Maximum Privilege Level for session",
"ipmi.app3a.maxpriv_session", FT_UINT8, BASE_HEX, VALS(vals_XX_priv), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_3b_req_priv,
{ "Requested Privilege Level",
"ipmi.app3b.req_priv", FT_UINT8, BASE_HEX, VALS(vals_XX_priv), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_3b_new_priv,
{ "New Privilege Level",
"ipmi.app3b.new_priv", FT_UINT8, BASE_HEX, VALS(vals_XX_priv), 0x0f, NULL, HFILL }},
{ &hf_ipmi_app_3c_session_id,
{ "Session ID",
"ipmi.app3c.session_id", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_ipmi_app_3c_session_handle,
{ "Session handle",
"ipmi.app3c.session_handle", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ipmi_app_01_byte2,
&ett_ipmi_app_01_byte3,
&ett_ipmi_app_01_byte6,
&ett_ipmi_app_04_byte2,
&ett_ipmi_app_06_syspwr,
&ett_ipmi_app_06_devpwr,
&ett_ipmi_app_07_syspwr,
&ett_ipmi_app_07_devpwr,
&ett_ipmi_app_24_timer_use,
&ett_ipmi_app_24_timer_action,
&ett_ipmi_app_24_expiration_flags,
&ett_ipmi_app_25_timer_use,
&ett_ipmi_app_25_timer_action,
&ett_ipmi_app_25_expiration_flags,
&ett_ipmi_app_2e_byte1,
&ett_ipmi_app_2f_byte1,
&ett_ipmi_app_30_byte1,
&ett_ipmi_app_31_byte1,
&ett_ipmi_app_32_rq_byte1,
&ett_ipmi_app_32_rq_byte2,
&ett_ipmi_app_32_rs_byte1,
&ett_ipmi_app_32_rs_byte2,
&ett_ipmi_app_33_rs_byte1,
&ett_ipmi_app_33_msg,
&ett_ipmi_app_34_byte1,
&ett_ipmi_app_34_msg,
&ett_ipmi_app_38_rq_byte1,
&ett_ipmi_app_38_rq_byte2,
&ett_ipmi_app_38_rs_byte1,
&ett_ipmi_app_38_rs_byte2,
&ett_ipmi_app_38_rs_byte3,
&ett_ipmi_app_38_rs_byte4,
&ett_ipmi_app_39_byte1,
&ett_ipmi_app_3a_rq_byte1,
&ett_ipmi_app_3a_rq_byte2,
&ett_ipmi_app_3a_rs_byte1,
&ett_ipmi_app_3a_rs_byte10,
&ett_ipmi_app_3b_rq_byte1,
&ett_ipmi_app_3b_rs_byte1,
};
proto_register_field_array(proto_ipmi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ipmi_register_netfn_cmdtab(IPMI_APP_REQ, IPMI_OEM_NONE, NULL, 0, NULL,
cmd_app, array_length(cmd_app));
}
