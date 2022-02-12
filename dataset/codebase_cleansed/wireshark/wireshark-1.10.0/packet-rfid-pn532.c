static void
dissect_pn532(tvbuff_t * tvb, packet_info * pinfo, proto_tree *tree)
{
proto_item *item;
proto_tree *pn532_tree;
guint8 cmd;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PN532");
col_set_str(pinfo->cinfo, COL_INFO, "PN532 Packet");
item = proto_tree_add_item(tree, proto_pn532, tvb, 0, -1, ENC_NA);
pn532_tree = proto_item_add_subtree(item, ett_pn532);
proto_tree_add_item(pn532_tree, hf_pn532_direction, tvb, 0, 1, ENC_NA);
proto_tree_add_item(pn532_tree, hf_pn532_command, tvb, 1, 1, ENC_NA);
cmd = tvb_get_guint8(tvb, 1);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_ext_const(cmd, &pn532_commands_ext, "Unknown"));
switch (cmd) {
case DIAGNOSE_REQ:
break;
case DIAGNOSE_RSP:
break;
case GET_FIRMWARE_VERSION_REQ:
break;
case GET_FIRMWARE_VERSION_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_ic_version, tvb, 2, 1, ENC_NA);
proto_tree_add_item(pn532_tree, hf_pn532_fw_version, tvb, 3, 1, ENC_NA);
proto_tree_add_item(pn532_tree, hf_pn532_fw_revision, tvb, 4, 1, ENC_NA);
proto_tree_add_item(pn532_tree, hf_pn532_fw_support, tvb, 5, 1, ENC_NA);
break;
case GET_GENERAL_STATUS:
break;
case READ_REGISTER_REQ:
break;
case READ_REGISTER_RSP:
break;
case WRITE_REGISTER_REQ:
break;
case WRITE_REGISTER_RSP:
break;
case READ_GPIO:
break;
case WRITE_GPIO:
break;
case SET_SERIAL_BAUD_RATE:
break;
case SET_PARAMETERS_REQ:
break;
case SET_PARAMETERS_RSP:
break;
case SAM_CONFIGURATION_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_sam_mode, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case SAM_CONFIGURATION_RSP:
break;
case POWER_DOWN:
break;
case RF_CONFIGURATION_REQ:
break;
case RF_CONFIGURATION_RSP:
break;
case RF_REGULATION_TEST:
break;
case IN_JUMP_FOR_DEP:
break;
case IN_JUMP_FOR_PSL:
break;
case IN_LIST_PASSIVE_TARGET_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_MaxTg, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_BrTy, tvb, 3, 1, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, 3) == FELICA_212) || (tvb_get_guint8(tvb, 3) == FELICA_424)) {
next_tvb = tvb_new_subset_remaining(tvb, 4);
call_dissector(sub_handles[SUB_FELICA], next_tvb, pinfo, tree);
}
break;
case IN_LIST_PASSIVE_TARGET_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_NbTg, tvb, 2, 1, ENC_BIG_ENDIAN);
if (tvb_reported_length(tvb) == 20) {
proto_tree_add_item(pn532_tree, hf_pn532_14443b_pupi, tvb, 5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443b_app_data, tvb, 9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443b_proto_info, tvb, 13, 3, ENC_BIG_ENDIAN);
}
if ((tvb_reported_length(tvb) == 23) || (tvb_reported_length(tvb) == 17) || (tvb_reported_length(tvb) == 14)) {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_atqa, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_sak, tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid_length, tvb, 7, 1, ENC_BIG_ENDIAN);
if (tvb_reported_length(tvb) != 14) {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid, tvb, 8, 7, ENC_BIG_ENDIAN);
if (tvb_reported_length(tvb) == 23) {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_ats, tvb, 16, 5, ENC_BIG_ENDIAN);
}
}
else {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid, tvb, 8, 4, ENC_BIG_ENDIAN);
}
}
if (tvb_reported_length(tvb) == 30 || tvb_reported_length(tvb) == 33) {
if ((tvb_get_guint8(tvb, 4) == 0x00 && tvb_get_guint8(tvb, 5) == 0x04)) {
proto_tree_add_item(pn532_tree, hf_pn532_14443a_atqa, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_sak, tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid_length, tvb, 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pn532_tree, hf_pn532_14443a_uid, tvb, 8, 4, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, 13);
call_dissector(sub_handles[SUB_DATA], next_tvb, pinfo, tree);
}
}
if (tvb_reported_length(tvb) == 26) {
proto_tree_add_item(pn532_tree, hf_pn532_payload_length, tvb, 4, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset(tvb, 5, tvb_get_guint8(tvb, 4) - 1, 19);
call_dissector(sub_handles[SUB_FELICA], next_tvb, pinfo, tree);
}
break;
case IN_ATR:
break;
case IN_PSL:
break;
case IN_DATA_EXCHANGE_REQ:
if (sub_selected == SUB_MIFARE) {
proto_tree_add_item(pn532_tree, hf_pn532_Tg, tvb, 2, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, 3);
call_dissector(sub_handles[SUB_MIFARE], next_tvb, pinfo, tree);
}
else if (sub_selected == SUB_ISO7816) {
proto_tree_add_item(pn532_tree, hf_pn532_Tg, tvb, 2, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, 3);
pinfo->p2p_dir = P2P_DIR_SENT;
call_dissector(sub_handles[SUB_ISO7816], next_tvb, pinfo, tree);
}
else {
}
break;
case IN_DATA_EXCHANGE_RSP:
if (sub_selected == SUB_ISO7816) {
next_tvb = tvb_new_subset_remaining(tvb, 2);
pinfo->p2p_dir = P2P_DIR_RECV;
call_dissector(sub_handles[SUB_ISO7816], next_tvb, pinfo, tree);
}
else {
}
break;
case IN_COMMUNICATE_THRU_REQ:
if (sub_selected == SUB_FELICA) {
proto_tree_add_item(pn532_tree, hf_pn532_payload_length, tvb, 2, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, 3);
call_dissector(sub_handles[SUB_FELICA], next_tvb, pinfo, tree);
}
else {
}
break;
case IN_COMMUNICATE_THRU_RSP:
if (sub_selected == SUB_FELICA) {
proto_tree_add_item(pn532_tree, hf_pn532_payload_length, tvb, 3, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, 4);
call_dissector(sub_handles[SUB_FELICA], next_tvb, pinfo, tree);
}
else {
}
break;
case IN_DESELECT_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_Tg, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case IN_DESELECT_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_error, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case IN_RELEASE_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_Tg, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case IN_RELEASE_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_error, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case IN_SELECT_REQ:
proto_tree_add_item(pn532_tree, hf_pn532_Tg, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case IN_SELECT_RSP:
proto_tree_add_item(pn532_tree, hf_pn532_error, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case IN_AUTO_POLL_REQ:
break;
case IN_AUTO_POLL_RSP:
break;
case TG_INIT_AS_TARGET:
break;
case TG_SET_GENERAL_BYTES:
break;
case TG_GET_DATA:
break;
case TG_SET_DATA:
break;
case TG_SET_METADATA:
break;
case TG_GET_INITIATOR_CMD:
break;
case TG_RESP_TO_INITIATOR:
break;
case TG_GET_TARGET_STATUS:
break;
default:
break;
}
}
void proto_register_pn532(void)
{
static hf_register_info hf[] = {
{&hf_pn532_command,
{"Command", "pn532.cmd", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&pn532_commands_ext, 0x0, NULL, HFILL}},
{&hf_pn532_direction,
{"Direction", "pn532.tfi", FT_UINT8, BASE_HEX,
VALS(pn532_directions), 0x0, NULL, HFILL}},
{&hf_pn532_error,
{"Error Code", "pn532.error", FT_UINT8, BASE_HEX,
VALS(pn532_errors), 0x0, NULL, HFILL}},
{&hf_pn532_BrTy,
{"Baud Rate and Modulation", "pn532.BrTy", FT_UINT8, BASE_HEX,
VALS(pn532_brtypes), 0x0, NULL, HFILL}},
{&hf_pn532_MaxTg,
{"Maximum Number of Targets", "pn532.MaxTg", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_Tg,
{"Logical Target Number", "pn532.Tg", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_NbTg,
{"Number of Targets", "pn532.NbTg", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_payload_length,
{"Payload Length", "pn532.payload.length", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_ic_version,
{"Integrated Circuit Version", "pn532.ic.version", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_fw_version,
{"Firmware Version", "pn532.fw.version", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_fw_revision,
{"Firmware Revision", "pn532.fw.revision", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_fw_support,
{"Firmware Support", "pn532.fw.support", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443a_sak,
{"ISO/IEC 14443-A SAK", "pn532.iso.14443a.sak", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443a_atqa,
{"ISO/IEC 14443-A ATQA", "pn532.iso.14443a.atqa", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443a_uid,
{"ISO/IEC 14443-A UID", "pn532.iso.14443a.uid", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443a_uid_length,
{"ISO/IEC 14443-A UID Length", "pn532.iso.14443a.uid.length", FT_INT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443a_ats,
{"ISO/IEC 14443-A ATS", "pn532.iso.14443a.ats", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443b_pupi,
{"ISO/IEC 14443-B PUPI", "pn532.iso.14443b.pupi", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443b_app_data,
{"ISO/IEC 14443-B Application Data", "pn532.iso.14443b.app.data", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_14443b_proto_info,
{"ISO/IEC 14443-B Protocol Info", "pn532.iso.14443b.protocol.info", FT_UINT64, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{&hf_pn532_sam_mode,
{"SAM Mode", "pn532.sam.mode", FT_UINT8, BASE_HEX,
VALS(pn532_sam_modes), 0x0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_pn532
};
module_t *pref_mod;
static const enum_val_t sub_enum_vals[] = {
{ "data", "Data", SUB_DATA },
{ "felica", "Sony FeliCa", SUB_FELICA },
{ "mifare", "NXP MiFare", SUB_MIFARE },
{ "iso7816", "ISO 7816", SUB_ISO7816 },
{ NULL, NULL, 0 }
};
proto_pn532 = proto_register_protocol("NXP PN532", "PN532", "pn532");
proto_register_field_array(proto_pn532, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
pref_mod = prefs_register_protocol(proto_pn532, NULL);
prefs_register_enum_preference(pref_mod, "prtype532", "Payload Type", "Protocol payload type",
&sub_selected, sub_enum_vals, FALSE);
pn532_dissector_table = register_dissector_table("pn532.payload", "PN532 Payload", FT_UINT8, BASE_DEC);
register_dissector("pn532", dissect_pn532, proto_pn532);
}
void proto_reg_handoff_pn532(void)
{
sub_handles[SUB_DATA] = find_dissector("data");
sub_handles[SUB_FELICA] = find_dissector("felica");
sub_handles[SUB_MIFARE] = find_dissector("mifare");
sub_handles[SUB_ISO7816] = find_dissector("iso7816");
}
