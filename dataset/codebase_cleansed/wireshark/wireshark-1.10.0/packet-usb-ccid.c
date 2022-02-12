static void
dissect_ccid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item;
proto_tree *ccid_tree;
guint8 cmd;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBCCID");
col_set_str(pinfo->cinfo, COL_INFO, "CCID Packet");
item = proto_tree_add_item(tree, proto_ccid, tvb, 0, 10, ENC_NA);
ccid_tree = proto_item_add_subtree(item, ett_ccid);
proto_tree_add_item(ccid_tree, hf_ccid_bMessageType, tvb, 0, 1, ENC_NA);
cmd = tvb_get_guint8(tvb, 0);
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s", val_to_str_const(cmd, ccid_messagetypes_vals, "Unknown"));
switch (cmd) {
case PC_RDR_SET_PARAMS:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bProtocolNum, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_text(ccid_tree, tvb, 8, 2, "Reserved for Future Use");
if (tvb_get_letohl(tvb, 1) != 0)
{
next_tvb = tvb_new_subset_remaining(tvb, 10);
call_dissector(sub_handles[SUB_DATA], next_tvb, pinfo, tree);
}
break;
case PC_RDR_ICC_ON:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bPowerSelect, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_text(ccid_tree, tvb, 8, 2, "Reserved for Future Use");
break;
case PC_RDR_ICC_OFF:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_text(ccid_tree, tvb, 7, 3, "Reserved for Future Use");
break;
case PC_RDR_GET_SLOT_STATUS:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_text(ccid_tree, tvb, 7, 3, "Reserved for Future Use");
break;
case PC_RDR_GET_PARAMS:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_text(ccid_tree, tvb, 7, 3, "Reserved for Future Use");
break;
case PC_RDR_XFR_BLOCK:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bBWI, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_wLevelParameter, tvb, 8, 2, ENC_LITTLE_ENDIAN);
if (tvb_get_letohl(tvb, 1) != 0)
{
next_tvb = tvb_new_subset_remaining(tvb, 10);
if (sub_selected != SUB_DATA) {
if (sub_selected == SUB_PN532_ACS_PSEUDO_APDU) {
if (tvb_get_guint8(tvb, 15) == 0xD4) {
call_dissector(sub_handles[sub_selected], tvb_new_subset_remaining(tvb, 15), pinfo, tree);
}
else {
call_dissector(sub_handles[SUB_DATA], next_tvb, pinfo, tree);
}
}
else if (sub_selected == SUB_ISO7816) {
pinfo->p2p_dir = P2P_DIR_SENT;
call_dissector(sub_handles[SUB_ISO7816], next_tvb, pinfo, tree);
}
else {
call_dissector(sub_handles[sub_selected], next_tvb, pinfo, tree);
}
}
else {
call_dissector(sub_handles[SUB_DATA], next_tvb, pinfo, tree);
}
}
break;
case RDR_PC_DATA_BLOCK:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bStatus, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bError, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bChainParameter, tvb, 9, 1, ENC_LITTLE_ENDIAN);
if (tvb_get_letohl(tvb, 1) != 0)
{
next_tvb = tvb_new_subset_remaining(tvb, 10);
if (sub_selected == SUB_PN532_ACS_PSEUDO_APDU && tvb_get_guint8(tvb, 10) == 0xD5) {
call_dissector(sub_handles[SUB_PN532_ACS_PSEUDO_APDU], next_tvb, pinfo, tree);
}
else if (sub_selected == SUB_ISO7816) {
pinfo->p2p_dir = P2P_DIR_RECV;
call_dissector(sub_handles[SUB_ISO7816], next_tvb, pinfo, tree);
}
else {
call_dissector(sub_handles[SUB_DATA], next_tvb, pinfo, tree);
}
}
break;
case RDR_PC_SLOT_STATUS:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bStatus, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bError, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bClockStatus, tvb, 9, 1, ENC_LITTLE_ENDIAN);
break;
}
}
void
proto_register_ccid(void)
{
static hf_register_info hf[] = {
{&hf_ccid_bMessageType,
{ "Message Type", "usbccid.bMessageType", FT_UINT8, BASE_HEX,
VALS(ccid_opcode_vals), 0x0, NULL, HFILL }},
{&hf_ccid_dwLength,
{ "Packet Length", "usbccid.dwLength", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bSlot,
{ "Slot", "usbccid.bSlot", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bSeq,
{ "Sequence", "usbccid.bSeq", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bStatus,
{ "Status", "usbccid.bStatus", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bError,
{ "Error", "usbccid.bError", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bChainParameter,
{ "Chain Parameter", "usbccid.bChainParameter", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bPowerSelect,
{ "Voltage Level", "usbccid.bPowerSelect", FT_UINT8, BASE_HEX,
VALS(ccid_voltage_levels_vals), 0x0, NULL, HFILL }},
{&hf_ccid_bClockStatus,
{ "Clock Status", "usbccid.bClockStatus", FT_UINT8, BASE_HEX,
VALS(ccid_clock_states_vals), 0x0, NULL, HFILL }},
{&hf_ccid_bProtocolNum,
{ "Data Structure Type", "usbccid.bProtocolNum", FT_UINT8, BASE_HEX,
VALS(ccid_proto_structs_vals), 0x0, NULL, HFILL }},
{&hf_ccid_bBWI,
{ "Block Wait Time Integer", "usbccid.bBWI", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_wLevelParameter,
{ "Level Parameter", "usbccid.wLevelParameter", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_ccid
};
static const enum_val_t sub_enum_vals[] = {
{ "data", "Data", SUB_DATA },
{ "iso7816", "Generic ISO 7816", SUB_ISO7816 },
{ "gsm_sim", "GSM SIM", SUB_GSM_SIM },
{ "pn532", "NXP PN532 with ACS Pseudo-Header", SUB_PN532_ACS_PSEUDO_APDU},
{ NULL, NULL, 0 }
};
module_t *pref_mod;
proto_ccid = proto_register_protocol("USB CCID", "USBCCID", "usbccid");
proto_register_field_array(proto_ccid, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
pref_mod = prefs_register_protocol(proto_ccid, NULL);
prefs_register_enum_preference(pref_mod, "prtype", "PC -> Reader Payload Type", "How commands from the PC to the reader are interpreted",
&sub_selected, sub_enum_vals, FALSE);
ccid_dissector_table = register_dissector_table("usbccid.payload",
"CCID Payload", FT_UINT8, BASE_DEC);
register_dissector("usbccid", dissect_ccid, proto_ccid);
}
void
proto_reg_handoff_ccid(void)
{
dissector_handle_t usb_ccid_bulk_handle;
usb_ccid_bulk_handle = find_dissector("usbccid");
dissector_add_uint("usb.bulk", IF_CLASS_SMART_CARD, usb_ccid_bulk_handle);
sub_handles[SUB_DATA] = find_dissector("data");
sub_handles[SUB_ISO7816] = find_dissector("iso7816");
sub_handles[SUB_GSM_SIM] = find_dissector("gsm_sim");
sub_handles[SUB_PN532_ACS_PSEUDO_APDU] = find_dissector("pn532");
}
