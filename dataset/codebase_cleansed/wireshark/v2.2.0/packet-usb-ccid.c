static gint
dissect_usb_ccid_descriptor(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint8 descriptor_type;
guint8 descriptor_len;
proto_item *freq_item;
proto_tree *desc_tree;
guint8 num_clock_supp;
proto_item *lcd_layout_item;
proto_tree *lcd_layout_tree;
descriptor_len = tvb_get_guint8(tvb, offset);
descriptor_type = tvb_get_guint8(tvb, offset+1);
if (descriptor_type!=USB_DESC_TYPE_SMARTCARD)
return 0;
desc_tree = proto_tree_add_subtree(tree, tvb, offset, descriptor_len,
ett_ccid_desc, NULL, "SMART CARD DEVICE CLASS DESCRIPTOR");
dissect_usb_descriptor_header(desc_tree, tvb, offset,
&ccid_descriptor_type_vals_ext);
offset += 2;
proto_tree_add_item(desc_tree, hf_ccid_bcdCCID, tvb,
offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(desc_tree, hf_ccid_bMaxSlotIndex, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_bitmask(desc_tree, tvb, offset,
hf_ccid_bVoltageSupport, ett_ccid_voltage_level, bVoltageLevel_fields,
ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_bitmask(desc_tree, tvb, offset,
hf_ccid_dwProtocols, ett_ccid_protocols, dwProtocols_fields,
ENC_LITTLE_ENDIAN);
offset += 4;
freq_item = proto_tree_add_item(desc_tree, hf_ccid_dwDefaultClock, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(freq_item, " kHz");
offset += 4;
freq_item = proto_tree_add_item(desc_tree, hf_ccid_dwMaximumClock, tvb,
offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(freq_item, " kHz");
offset += 4;
num_clock_supp = tvb_get_guint8(tvb, offset);
freq_item = proto_tree_add_item(desc_tree, hf_ccid_bNumClockSupported, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
if (num_clock_supp==0)
proto_item_append_text(freq_item, " (only default and maximum)");
offset++;
proto_tree_add_item(desc_tree, hf_ccid_dwDataRate,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(desc_tree, hf_ccid_dwMaxDataRate,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(desc_tree, hf_ccid_bNumDataRatesSupported,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
offset += 4;
proto_tree_add_item(desc_tree, hf_ccid_dwSynchProtocols,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(desc_tree, hf_ccid_dwMechanical,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(desc_tree, tvb, offset,
hf_ccid_dwFeatures, ett_ccid_features, bFeatures_fields,
ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(desc_tree, hf_ccid_dwMaxCCIDMessageLength,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(desc_tree, hf_ccid_bClassGetResponse,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(desc_tree, hf_ccid_bClassEnvelope,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
lcd_layout_item = proto_tree_add_item(desc_tree, hf_ccid_wLcdLayout,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
lcd_layout_tree = proto_item_add_subtree(
lcd_layout_item, ett_ccid_lcd_layout);
proto_tree_add_item(lcd_layout_tree, hf_ccid_wLcdLayout_lines,
tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(lcd_layout_tree, hf_ccid_wLcdLayout_chars,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_bitmask(desc_tree, tvb, offset,
hf_ccid_bPINSupport, ett_ccid_pin_support, bPINSupport_fields,
ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(desc_tree, hf_ccid_bMaxCCIDBusySlots,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
return offset;
}
static gint
dissect_ccid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *item;
proto_tree *ccid_tree;
guint8 cmd;
tvbuff_t *next_tvb;
usb_conv_info_t *usb_conv_info;
if (data == NULL)
return 0;
usb_conv_info = (usb_conv_info_t *)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBCCID");
col_set_str(pinfo->cinfo, COL_INFO, "CCID Packet");
item = proto_tree_add_item(tree, proto_ccid, tvb, 0, 10, ENC_NA);
ccid_tree = proto_item_add_subtree(item, ett_ccid);
proto_tree_add_item(ccid_tree, hf_ccid_bMessageType, tvb, 0, 1, ENC_LITTLE_ENDIAN);
cmd = tvb_get_guint8(tvb, 0);
col_append_fstr(pinfo->cinfo, COL_INFO, " - %s", val_to_str_const(cmd, ccid_messagetypes_vals, "Unknown"));
switch (cmd) {
case PC_RDR_SET_PARAMS:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bProtocolNum, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_Reserved, tvb, 8, 2, ENC_LITTLE_ENDIAN);
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
proto_tree_add_item(ccid_tree, hf_ccid_Reserved, tvb, 8, 2, ENC_LITTLE_ENDIAN);
break;
case PC_RDR_ICC_OFF:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_Reserved, tvb, 7, 3, ENC_LITTLE_ENDIAN);
break;
case PC_RDR_GET_SLOT_STATUS:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_Reserved, tvb, 7, 3, ENC_LITTLE_ENDIAN);
break;
case PC_RDR_GET_PARAMS:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_Reserved, tvb, 7, 3, ENC_LITTLE_ENDIAN);
break;
case PC_RDR_XFR_BLOCK:
case PC_RDR_ESCAPE:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
if (cmd == PC_RDR_ESCAPE) {
proto_tree_add_item(ccid_tree, hf_ccid_abRFU, tvb, 7, 3, ENC_NA);
} else {
proto_tree_add_item(ccid_tree, hf_ccid_bBWI, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_wLevelParameter, tvb, 8, 2, ENC_LITTLE_ENDIAN);
}
if (tvb_get_letohl(tvb, 1) != 0)
{
next_tvb = tvb_new_subset_remaining(tvb, 10);
if (sub_selected != SUB_DATA) {
if (sub_selected == SUB_PN532) {
call_dissector_with_data(sub_handles[sub_selected], tvb_new_subset_remaining(tvb, 10), pinfo, tree, usb_conv_info);
} else if (sub_selected == SUB_ACR122_PN532) {
pinfo->p2p_dir = P2P_DIR_SENT;
call_dissector_with_data(sub_handles[sub_selected], tvb_new_subset_remaining(tvb, 10), pinfo, tree, usb_conv_info);
} else if (sub_selected == SUB_ISO7816) {
pinfo->p2p_dir = P2P_DIR_SENT;
call_dissector(sub_handles[SUB_ISO7816], next_tvb, pinfo, tree);
} else {
call_dissector(sub_handles[sub_selected], next_tvb, pinfo, tree);
}
} else if (usb_conv_info->deviceVendor == 0x072F && usb_conv_info->deviceProduct == 0x2200) {
pinfo->p2p_dir = P2P_DIR_SENT;
call_dissector_with_data(sub_handles[SUB_ACR122_PN532], tvb_new_subset_remaining(tvb, 10), pinfo, tree, usb_conv_info);
} else {
call_dissector(sub_handles[SUB_DATA], next_tvb, pinfo, tree);
}
}
break;
case RDR_PC_DATA_BLOCK:
case RDR_PC_ESCAPE:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bStatus, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bError, tvb, 8, 1, ENC_LITTLE_ENDIAN);
if (cmd == RDR_PC_ESCAPE)
proto_tree_add_item(ccid_tree, hf_ccid_bRFU, tvb, 9, 1, ENC_LITTLE_ENDIAN);
else
proto_tree_add_item(ccid_tree, hf_ccid_bChainParameter, tvb, 9, 1, ENC_LITTLE_ENDIAN);
if (tvb_get_letohl(tvb, 1) != 0)
{
next_tvb = tvb_new_subset_remaining(tvb, 10);
if (sub_selected == SUB_PN532) {
next_tvb= tvb_new_subset_length(tvb, 10, tvb_get_guint8(tvb, 1));
call_dissector_with_data(sub_handles[SUB_PN532], next_tvb, pinfo, tree, usb_conv_info);
} else if (sub_selected == SUB_ACR122_PN532) {
pinfo->p2p_dir = P2P_DIR_RECV;
call_dissector_with_data(sub_handles[SUB_ACR122_PN532], tvb_new_subset_remaining(tvb, 10), pinfo, tree, usb_conv_info);
} else if (sub_selected == SUB_GSM_SIM_CMD) {
call_dissector(sub_handles[SUB_GSM_SIM_RSP], next_tvb, pinfo, tree);
} else if (sub_selected == SUB_ISO7816) {
pinfo->p2p_dir = P2P_DIR_RECV;
call_dissector(sub_handles[SUB_ISO7816], next_tvb, pinfo, tree);
} else if (usb_conv_info->deviceVendor == 0x072F && usb_conv_info->deviceProduct == 0x2200) {
pinfo->p2p_dir = P2P_DIR_RECV;
call_dissector_with_data(sub_handles[SUB_ACR122_PN532], tvb_new_subset_remaining(tvb, 10), pinfo, tree, usb_conv_info);
} else {
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
case RDR_PC_PARAMS:
proto_tree_add_item(ccid_tree, hf_ccid_dwLength, tvb, 1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 5, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bStatus, tvb, 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bError, tvb, 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bProtocolNum, tvb, 8, 1, ENC_LITTLE_ENDIAN);
break;
case RDR_PC_NOTIF_SLOT_CHNG:
proto_tree_add_bitmask(ccid_tree, tvb, 1,
hf_ccid_bmSlotICCState, ett_ccid_slot_change, bmSlotICCState_fields,
ENC_LITTLE_ENDIAN);
break;
case RDR_PC_HWERROR:
proto_tree_add_item(ccid_tree, hf_ccid_bSlot, tvb, 1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bSeq, tvb, 2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ccid_tree, hf_ccid_bHardwareErrorCode, tvb, 3, 1, ENC_LITTLE_ENDIAN);
break;
}
return tvb_captured_length(tvb);
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
{&hf_ccid_bRFU,
{ "RFU", "usbccid.bRFU", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_abRFU,
{ "RFU", "usbccid.abRFU", FT_BYTES, BASE_NONE,
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
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bcdCCID,
{ "bcdCCID", "usbccid.bcdCCID", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bMaxSlotIndex,
{ "max slot index", "usbccid.bMaxSlotIndex", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bVoltageSupport,
{ "voltage support", "usbccid.bVoltageSupport", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bVoltageSupport18,
{ "1.8V", "usbccid.bVoltageSupport.18", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x04, NULL, HFILL }},
{&hf_ccid_bVoltageSupport30,
{ "3.0V", "usbccid.bVoltageSupport.30", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x02, NULL, HFILL }},
{&hf_ccid_bVoltageSupport50,
{ "5.0V", "usbccid.bVoltageSupport.50", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x01, NULL, HFILL }},
{&hf_ccid_dwProtocols,
{ "dwProtocols", "usbccid.dwProtocols", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{&hf_ccid_dwProtocols_t0,
{ "T=0", "usbccid.dwProtocols.t0", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x01, NULL, HFILL }},
{&hf_ccid_dwProtocols_t1,
{ "T=1", "usbccid.dwProtocols.t1", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x02, NULL, HFILL }},
{&hf_ccid_dwDefaultClock,
{ "default clock frequency", "usbccid.dwDefaultClock",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_dwMaximumClock,
{ "maximum clock frequency", "usbccid.dwMaximumClock",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bNumClockSupported,
{ "number of supported clock frequencies", "usbccid.bNumClockSupported",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_dwDataRate,
{ "default ICC I/O data rate in bps", "usbccid.dwDataRate",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_dwMaxDataRate,
{ "maximum ICC I/O data rate in bps", "usbccid.dwMaxDataRate",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bNumDataRatesSupported,
{ "number of supported data rates", "usbccid.bNumDataRatesSupported",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_dwSynchProtocols,
{ "supported protocol types", "usbccid.dwSynchProtocols",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_dwMechanical,
{ "mechanical characteristics", "usbccid.dwMechanical",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_dwFeatures,
{ "intelligent features", "usbccid.dwFeatures",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_dwFeatures_autoIccActivation,
{ "Automatic activation of ICC on inserting",
"usbccid.dwFeatures.autoIccActivation", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x04, NULL, HFILL }},
{&hf_ccid_dwFeatures_autoParam,
{ "Automatic parameter configuration based on ATR",
"usbccid.dwFeatures.autoParam", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x02, NULL, HFILL }},
{&hf_ccid_dwFeatures_autoIccClk,
{ "Automatic ICC clock frequency change",
"usbccid.dwFeatures.autoIccClk", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x10, NULL, HFILL }},
{&hf_ccid_dwFeatures_autoBaudRate,
{ "Automatic baud rate change",
"usbccid.dwFeatures.autoBaudRate", FT_BOOLEAN, 32,
TFS(&tfs_supported_not_supported), 0x20, NULL, HFILL }},
{&hf_ccid_dwMaxCCIDMessageLength,
{ "maximum CCID message length", "usbccid.dwMaxCCIDMessageLength",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bClassGetResponse,
{ "default class for Get Response", "usbccid.hf_ccid_bClassGetResponse",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bClassEnvelope,
{ "default class for Envelope", "usbccid.hf_ccid_bClassEnvelope",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_wLcdLayout,
{ "LCD layout", "usbccid.hf_ccid_wLcdLayout",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_wLcdLayout_lines,
{ "Lines", "usbccid.hf_ccid_wLcdLayout.lines",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_wLcdLayout_chars,
{ "Characters per line", "usbccid.hf_ccid_wLcdLayout.chars",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bPINSupport,
{ "PIN support", "usbccid.hf_ccid_bPINSupport",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_bPINSupport_modify,
{ "PIN modification", "usbccid.hf_ccid_bPINSupport.modify",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x02, NULL, HFILL }},
{&hf_ccid_bPINSupport_vrfy,
{ "PIN verification", "usbccid.hf_ccid_bPINSupport.verify",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x01, NULL, HFILL }},
{&hf_ccid_bMaxCCIDBusySlots,
{ "maximum number of busy slots", "usbccid.hf_ccid_bMaxCCIDBusySlots",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_ccid_Reserved,
{ "Reserved for Future Use", "usbccid.hf_ccid_Reserved",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ccid_bmSlotICCState,
{ "Slot ICC State", "usbccid.hf_ccid_bmSlotICCState",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_ccid_bmSlotICCState_slot0Current,
{ "Slot 0 Current Status", "usbccid.hf_ccid_bmSlotICCState.slot0Current",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x01, NULL, HFILL } },
{ &hf_ccid_bmSlotICCState_slot0Changed,
{ "Slot 0 Status changed", "usbccid.hf_ccid_bmSlotICCState.slot0Changed",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02, NULL, HFILL } },
{ &hf_ccid_bmSlotICCState_slot1Current,
{ "Slot 1 Current Status", "usbccid.hf_ccid_bmSlotICCState.slot1Current",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x04, NULL, HFILL } },
{ &hf_ccid_bmSlotICCState_slot1Changed,
{ "Slot 1 Status changed", "usbccid.hf_ccid_bmSlotICCState.slot1Changed",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x08, NULL, HFILL } },
{ &hf_ccid_bmSlotICCState_slot2Current,
{ "Slot 2 Current Status", "usbccid.hf_ccid_bmSlotICCState.slot2Current",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x10, NULL, HFILL } },
{ &hf_ccid_bmSlotICCState_slot2Changed,
{ "Slot 2 Status changed", "usbccid.hf_ccid_bmSlotICCState.slot2Changed",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20, NULL, HFILL } },
{ &hf_ccid_bmSlotICCState_slot3Current,
{ "Slot 3 Current Status", "usbccid.hf_ccid_bmSlotICCState.slot3Current",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x40, NULL, HFILL } },
{ &hf_ccid_bmSlotICCState_slot3Changed,
{ "Slot 3 Status changed", "usbccid.hf_ccid_bmSlotICCState.slot3Changed",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x80, NULL, HFILL } },
{ &hf_ccid_bHardwareErrorCode,
{ "Hardware Error Code", "usbccid.hf_ccid_bHardwareErrorCode",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_ccid,
&ett_ccid_desc,
&ett_ccid_voltage_level,
&ett_ccid_protocols,
&ett_ccid_features,
&ett_ccid_lcd_layout,
&ett_ccid_pin_support,
&ett_ccid_slot_change
};
static const enum_val_t sub_enum_vals[] = {
{ "data", "Data", SUB_DATA },
{ "iso7816", "Generic ISO 7816", SUB_ISO7816 },
{ "gsm_sim", "GSM SIM", SUB_GSM_SIM_CMD },
{ "pn532", "NXP PN532", SUB_PN532},
{ "acr122", "ACR122 PN532", SUB_ACR122_PN532},
{ NULL, NULL, 0 }
};
module_t *pref_mod;
proto_ccid = proto_register_protocol("USB CCID", "USBCCID", "usbccid");
proto_register_field_array(proto_ccid, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
pref_mod = prefs_register_protocol(proto_ccid, NULL);
prefs_register_enum_preference(pref_mod, "prtype", "PC -> Reader Payload Type", "How commands from the PC to the reader are interpreted",
&sub_selected, sub_enum_vals, FALSE);
usb_ccid_handle = register_dissector("usbccid", dissect_ccid, proto_ccid);
}
void
proto_reg_handoff_ccid(void)
{
dissector_handle_t usb_ccid_descr_handle;
usb_ccid_descr_handle = create_dissector_handle(
dissect_usb_ccid_descriptor, proto_ccid);
dissector_add_uint("usb.descriptor", IF_CLASS_SMART_CARD, usb_ccid_descr_handle);
dissector_add_uint("usb.bulk", IF_CLASS_SMART_CARD, usb_ccid_handle);
dissector_add_for_decode_as("usb.device", usb_ccid_handle);
dissector_add_for_decode_as("usb.product", usb_ccid_handle);
dissector_add_for_decode_as("usb.protocol", usb_ccid_handle);
sub_handles[SUB_DATA] = find_dissector("data");
sub_handles[SUB_ISO7816] = find_dissector_add_dependency("iso7816", proto_ccid);
sub_handles[SUB_GSM_SIM_CMD] = find_dissector_add_dependency("gsm_sim.command", proto_ccid);
sub_handles[SUB_PN532] = find_dissector_add_dependency("pn532", proto_ccid);
sub_handles[SUB_ACR122_PN532] = find_dissector_add_dependency("acr122", proto_ccid);
sub_handles[SUB_GSM_SIM_RSP] = find_dissector_add_dependency("gsm_sim.response", proto_ccid);
}
