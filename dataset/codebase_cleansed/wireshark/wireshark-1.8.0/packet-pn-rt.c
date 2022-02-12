static void
dissect_DataStatus(tvbuff_t *tvb, int offset, proto_tree *tree, guint8 u8DataStatus)
{
proto_item *sub_item;
proto_tree *sub_tree;
sub_item = proto_tree_add_uint_format(tree, hf_pn_rt_data_status,
tvb, offset, 1, u8DataStatus,
"DataStatus: 0x%02x (Frame: %s and %s, Provider: %s and %s)",
u8DataStatus,
(u8DataStatus & 0x04) ? "Valid" : "Invalid",
(u8DataStatus & 0x01) ? "Primary" : "Backup",
(u8DataStatus & 0x20) ? "Ok" : "Problem",
(u8DataStatus & 0x10) ? "Run" : "Stop");
sub_tree = proto_item_add_subtree(sub_item, ett_pn_rt_data_status);
proto_tree_add_uint(sub_tree, hf_pn_rt_data_status_ignore, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(sub_tree, hf_pn_rt_data_status_Reserved_2, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(sub_tree, hf_pn_rt_data_status_ok, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(sub_tree, hf_pn_rt_data_status_operate, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(sub_tree, hf_pn_rt_data_status_res3, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(sub_tree, hf_pn_rt_data_status_valid, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(sub_tree, hf_pn_rt_data_status_redundancy, tvb, offset, 1, u8DataStatus);
proto_tree_add_uint(sub_tree, hf_pn_rt_data_status_primary, tvb, offset, 1, u8DataStatus);
}
static gboolean IsDFP_Frame(tvbuff_t *tvb)
{
guint16 u16SFCRC16;
guint8 u8SFPosition;
guint8 u8SFDataLength = 255;
int offset = 0;
guint32 u32SubStart;
guint16 crc;
gint tvb_len =0;
offset += 2;
tvb_len = tvb_length(tvb);
if(offset + 4 > tvb_len)
return FALSE;
while(1) {
u32SubStart = offset;
u8SFPosition = tvb_get_guint8(tvb, offset);
offset += 1;
u8SFDataLength = tvb_get_guint8(tvb, offset);
offset += 1;
if(u8SFDataLength == 0) {
break;
}
offset += 1;
offset += 1;
offset += u8SFDataLength;
if(offset > tvb_len)
return FALSE;
u16SFCRC16 = tvb_get_letohs(tvb, offset);
if(u16SFCRC16 != 0){
if(u8SFPosition & 0x80) {
crc = crc16_plain_tvb_offset(tvb, u32SubStart, offset-u32SubStart);
if(crc != u16SFCRC16) {
return FALSE;
} else {
}
} else {
}
}
offset += 2;
}
return TRUE;
}
gboolean
dissect_CSF_SDU_heur(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree)
{
guint16 u16FrameID;
guint16 u16SFCRC16;
guint8 u8SFPosition;
guint8 u8SFDataLength = 255;
guint8 u8SFCycleCounter;
guint8 u8SFDataStatus;
gint offset = 0;
guint32 u32SubStart;
proto_item *sub_item;
proto_tree *sub_tree;
proto_item *item;
guint16 crc;
u16FrameID = GPOINTER_TO_UINT(pinfo->private_data);
if((u16FrameID < 0x100) || (u16FrameID > 0x0fff))
return (FALSE);
if (IsDFP_Frame(tvb)) {
u16SFCRC16 = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_pn_rt_sf_crc16, tvb, offset, 2, u16SFCRC16);
offset += 2;
while(1) {
sub_item = proto_tree_add_item(tree, hf_pn_rt_sf, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_rt_sf);
u32SubStart = offset;
u8SFPosition = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(sub_tree, hf_pn_rt_sf_position, tvb, offset, 1, u8SFPosition);
offset += 1;
u8SFDataLength = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(sub_tree, hf_pn_rt_sf_data_length, tvb, offset, 1, u8SFDataLength);
offset += 1;
if(u8SFDataLength == 0) {
proto_item_append_text(sub_item, ": Pos:%u, Length:%u", u8SFPosition, u8SFDataLength);
proto_item_set_len(sub_item, offset - u32SubStart);
break;
}
u8SFCycleCounter = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(sub_tree, hf_pn_rt_sf_cycle_counter, tvb, offset, 1, u8SFCycleCounter);
offset += 1;
u8SFDataStatus = tvb_get_guint8(tvb, offset);
dissect_DataStatus(tvb, offset, sub_tree, u8SFDataStatus);
offset += 1;
offset = dissect_pn_user_data(tvb, offset, pinfo, sub_tree, u8SFDataLength, "DataItem");
u16SFCRC16 = tvb_get_letohs(tvb, offset);
item = proto_tree_add_uint(sub_tree, hf_pn_rt_sf_crc16, tvb, offset, 2, u16SFCRC16);
if(u16SFCRC16 != 0 ) {
crc = crc16_plain_tvb_offset(tvb, u32SubStart, offset-u32SubStart);
if(crc != u16SFCRC16) {
proto_item_append_text(item, " [Preliminary check: incorrect, should be: %u]", crc);
expert_add_info_format(pinfo, item, PI_CHECKSUM, PI_ERROR, "Bad checksum");
} else {
proto_item_append_text(item, " [Preliminary check: Correct]");
}
} else {
proto_item_append_text(item, " [No check, supplied CRC == zero]");
}
offset += 2;
proto_item_append_text(sub_item, ": Pos:%u, Length:%u, Cycle:%u, Status: 0x%02x (%s,%s,%s,%s)",
u8SFPosition, u8SFDataLength, u8SFCycleCounter, u8SFDataStatus,
(u8SFDataStatus & 0x04) ? "Valid" : "Invalid",
(u8SFDataStatus & 0x01) ? "Primary" : "Backup",
(u8SFDataStatus & 0x20) ? "Ok" : "Problem",
(u8SFDataStatus & 0x10) ? "Run" : "Stop");
proto_item_set_len(sub_item, offset - u32SubStart);
}
return TRUE;
}
return FALSE;
}
static gboolean
dissect_FRAG_PDU_heur(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree)
{
guint16 u16FrameID;
int offset = 0;
proto_item *sub_item;
proto_tree *sub_tree;
guint8 u8FragDataLength;
proto_item *status_item;
proto_tree *status_tree;
guint8 u8FragStatus;
u16FrameID = GPOINTER_TO_UINT(pinfo->private_data);
if (u16FrameID >= 0xFF80 && u16FrameID <= 0xFF8F) {
sub_item = proto_tree_add_item(tree, hf_pn_rt_frag, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_rt_frag);
u8FragDataLength = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(sub_tree, hf_pn_rt_frag_data_length, tvb, offset, 1, u8FragDataLength);
offset += 1;
status_item = proto_tree_add_item(sub_tree, hf_pn_rt_frag_status, tvb, offset, 1, ENC_NA);
status_tree = proto_item_add_subtree(status_item, ett_pn_rt_frag_status);
u8FragStatus = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(status_tree, hf_pn_rt_frag_status_more_follows, tvb, offset, 1, u8FragStatus);
proto_tree_add_uint(status_tree, hf_pn_rt_frag_status_error, tvb, offset, 1, u8FragStatus);
proto_tree_add_uint(status_tree, hf_pn_rt_frag_status_fragment_number, tvb, offset, 1, u8FragStatus);
offset += 1;
proto_item_append_text(status_item, ": Number: %u, %s, %s",
u8FragStatus & 0x3F,
val_to_str( (u8FragStatus & 0x80) >> 7, pn_rt_frag_status_more_follows, "Unknown"),
val_to_str( (u8FragStatus & 0x40) >> 6, pn_rt_frag_status_error, "Unknown"));
proto_tree_add_string_format(sub_tree, hf_pn_rt_frag_data, tvb, offset, tvb_length(tvb) - offset, "data",
"FragData: %d bytes", tvb_length(tvb) - offset);
dissect_pn_undecoded(tvb, offset, pinfo, sub_tree, tvb_length(tvb) - offset);
return TRUE;
}
return FALSE;
}
static void
dissect_pn_rt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint pdu_len;
gint data_len;
guint16 u16FrameID;
guint8 u8DataStatus;
guint8 u8TransferStatus;
guint16 u16CycleCounter;
const gchar *pszProtAddInfo;
const gchar *pszProtShort;
const gchar *pszProtSummary;
const gchar *pszProtComment;
proto_tree *pn_rt_tree, *ti;
gchar szFieldSummary[100];
tvbuff_t *next_tvb;
gboolean bCyclic;
pn_rt_tree = NULL;
ti = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PN-RT");
col_set_str(pinfo->cinfo, COL_INFO, "PROFINET Real-Time");
pdu_len = tvb_reported_length(tvb);
if (pdu_len < 6) {
dissect_pn_malformed(tvb, 0, pinfo, tree, pdu_len);
return;
}
u16FrameID = tvb_get_ntohs(tvb, 0);
if (u16FrameID <= 0x001F) {
pszProtShort = "PN-RT";
pszProtAddInfo = "reserved, ";
pszProtSummary = "Real-Time";
pszProtComment = "0x0000-0x001F: Reserved ID";
bCyclic = FALSE;
} else if (u16FrameID <= 0x0021) {
pszProtShort = "PN-PTCP";
pszProtAddInfo = "Synchronization, ";
pszProtSummary = "Real-Time";
pszProtComment = "0x0020-0x0021: Real-Time: Sync (with follow up)";
bCyclic = FALSE;
} else if (u16FrameID <= 0x007F) {
pszProtShort = "PN-RT";
pszProtAddInfo = "reserved, ";
pszProtSummary = "Real-Time";
pszProtComment = "0x0022-0x007F: Reserved ID";
bCyclic = FALSE;
} else if (u16FrameID <= 0x0081) {
pszProtShort = "PN-PTCP";
pszProtAddInfo = "Synchronization, ";
pszProtSummary = "Isochronous-Real-Time";
pszProtComment = "0x0080-0x0081: Real-Time: Sync (without follow up)";
bCyclic = FALSE;
} else if (u16FrameID <= 0x00FF) {
pszProtShort = "PN-RT";
pszProtAddInfo = "reserved, ";
pszProtSummary = "Real-Time";
pszProtComment = "0x0082-0x00FF: Reserved ID";
bCyclic = FALSE;
} else if (u16FrameID <= 0x6FF) {
pszProtShort = "PN-RTC3";
pszProtAddInfo = "RTC3, ";
pszProtSummary = "Isochronous-Real-Time";
pszProtComment = "0x0100-0x06FF: RED: Real-Time(class=3): non redundant, normal or DFP";
bCyclic = TRUE;
} else if (u16FrameID <= 0x0FFF){
pszProtShort = "PN-RTC3";
pszProtAddInfo = "RTC3, ";
pszProtSummary = "Isochronous-Real-Time";
pszProtComment = "0x0700-0x0FFF: RED: Real-Time(class=3): redundant, normal or DFP";
bCyclic = TRUE;
} else if (u16FrameID <= 0x7FFF) {
pszProtShort = "PN-RT";
pszProtAddInfo = "reserved, ";
pszProtSummary = "Real-Time";
pszProtComment = "0x1000-0x7FFF: Reserved ID";
bCyclic = FALSE;
} else if (u16FrameID <= 0xBBFF){
pszProtShort = "PN-RTC2";
pszProtAddInfo = "RTC2, ";
pszProtSummary = "cyclic Real-Time";
pszProtComment = "0x8000-0xBBFF: Real-Time(class=2): non redundant, normal";
bCyclic = TRUE;
} else if (u16FrameID <= 0xBFFF){
pszProtShort = "PN-RTC2";
pszProtAddInfo = "RTC2, ";
pszProtSummary = "cyclic Real-Time";
pszProtComment = "0xBC00-0xBFFF: Real-Time(class=2 multicast): non redundant, normal";
bCyclic = TRUE;
} else if (u16FrameID <= 0xF7FF){
pszProtShort = "PN-RTC1/UDP";
pszProtAddInfo = "RTC1/UDP, ";
pszProtSummary = "cyclic Real-Time";
pszProtComment = "0xC000-0xF7FF: Real-Time(class=1/UDP): Cyclic";
bCyclic = TRUE;
} else if (u16FrameID <= 0xFBFF){
pszProtShort = "PN-RTC1/UDP";
pszProtAddInfo = "Multicast, ";
pszProtSummary = "cyclic Real-Time";
pszProtComment = "0xF800-0xFBFF: Real-Time(class=1/UDP multicast): Cyclic";
bCyclic = TRUE;
} else if (u16FrameID <= 0xFDFF){
pszProtShort = "PN-RTA";
pszProtAddInfo = "Reserved, ";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "0xFC00-0xFDFF: Reserved";
bCyclic = FALSE;
if (u16FrameID == 0xfc01) {
pszProtShort = "PN-RTA";
pszProtAddInfo = "Alarm High, ";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "Real-Time: Acyclic PN-IO Alarm high priority";
}
} else if (u16FrameID <= 0xFEFF){
pszProtShort = "PN-RTA";
pszProtAddInfo = "Reserved, ";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "0xFE00-0xFEFF: Real-Time: Reserved";
bCyclic = FALSE;
if (u16FrameID == 0xFE01) {
pszProtShort = "PN-RTA";
pszProtAddInfo = "Alarm Low, ";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "Real-Time: Acyclic PN-IO Alarm low priority";
}
if (u16FrameID == FRAME_ID_DCP_HELLO) {
pszProtShort = "PN-RTA";
pszProtAddInfo = "";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "Real-Time: DCP (Dynamic Configuration Protocol) hello";
}
if (u16FrameID == FRAME_ID_DCP_GETORSET) {
pszProtShort = "PN-RTA";
pszProtAddInfo = "";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "Real-Time: DCP (Dynamic Configuration Protocol) get/set";
}
if (u16FrameID == FRAME_ID_DCP_IDENT_REQ) {
pszProtShort = "PN-RTA";
pszProtAddInfo = "";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "Real-Time: DCP (Dynamic Configuration Protocol) identify multicast request";
}
if (u16FrameID == FRAME_ID_DCP_IDENT_RES) {
pszProtShort = "PN-RTA";
pszProtAddInfo = "";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "Real-Time: DCP (Dynamic Configuration Protocol) identify response";
}
} else if (u16FrameID <= 0xFF01){
pszProtShort = "PN-PTCP";
pszProtAddInfo = "RTA Sync, ";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "0xFF00-0xFF01: PTCP Announce";
bCyclic = FALSE;
} else if (u16FrameID <= 0xFF1F){
pszProtShort = "PN-PTCP";
pszProtAddInfo = "RTA Sync, ";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "0xFF02-0xFF1F: Reserved";
bCyclic = FALSE;
} else if (u16FrameID <= 0xFF21){
pszProtShort = "PN-PTCP";
pszProtAddInfo = "Follow Up, ";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "0xFF20-0xFF21: PTCP Follow Up";
bCyclic = FALSE;
} else if (u16FrameID <= 0xFF22){
pszProtShort = "PN-PTCP";
pszProtAddInfo = "Follow Up, ";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "0xFF22-0xFF3F: Reserved";
bCyclic = FALSE;
} else if (u16FrameID <= 0xFF43){
pszProtShort = "PN-PTCP";
pszProtAddInfo = "Delay, ";
pszProtSummary = "acyclic Real-Time";
pszProtComment = "0xFF40-0xFF43: Acyclic Real-Time: Delay";
bCyclic = FALSE;
} else if (u16FrameID <= 0xFF7F){
pszProtShort = "PN-RT";
pszProtAddInfo = "Reserved, ";
pszProtSummary = "Real-Time";
pszProtComment = "0xFF44-0xFF7F: reserved ID";
bCyclic = FALSE;
} else if (u16FrameID <= 0xFF8F){
pszProtShort = "PN-RT";
pszProtAddInfo = "Fragmentation, ";
pszProtSummary = "Real-Time";
pszProtComment = "0xFF80-0xFF8F: Fragmentation";
bCyclic = FALSE;
} else {
pszProtShort = "PN-RT";
pszProtAddInfo = "Reserved, ";
pszProtSummary = "Real-Time";
pszProtComment = "0xFF90-0xFFFF: reserved ID";
bCyclic = FALSE;
}
if (bCyclic) {
u16CycleCounter = tvb_get_ntohs(tvb, pdu_len - 4);
u8DataStatus = tvb_get_guint8(tvb, pdu_len - 2);
u8TransferStatus = tvb_get_guint8(tvb, pdu_len - 1);
g_snprintf (szFieldSummary, sizeof(szFieldSummary),
"%sID:0x%04x, Len:%4u, Cycle:%5u (%s,%s,%s,%s)",
pszProtAddInfo, u16FrameID, pdu_len - 2 - 4, u16CycleCounter,
(u8DataStatus & 0x04) ? "Valid" : "Invalid",
(u8DataStatus & 0x01) ? "Primary" : "Backup",
(u8DataStatus & 0x20) ? "Ok" : "Problem",
(u8DataStatus & 0x10) ? "Run" : "Stop");
data_len = pdu_len - 2 - 4;
} else {
u16CycleCounter = 0;
u8DataStatus = 0;
u8TransferStatus = 0;
g_snprintf (szFieldSummary, sizeof(szFieldSummary),
"%sID:0x%04x, Len:%4u",
pszProtAddInfo, u16FrameID, pdu_len - 2);
data_len = pdu_len - 2;
}
if (tree) {
if (pn_rt_summary_in_tree) {
ti = proto_tree_add_protocol_format(tree, proto_pn_rt, tvb, 0, pdu_len,
"PROFINET %s, %s", pszProtSummary, szFieldSummary);
} else {
ti = proto_tree_add_item(tree, proto_pn_rt, tvb, 0, pdu_len, ENC_NA);
}
pn_rt_tree = proto_item_add_subtree(ti, ett_pn_rt);
proto_tree_add_uint_format(pn_rt_tree, hf_pn_rt_frame_id, tvb,
0, 2, u16FrameID, "FrameID: 0x%04x (%s)", u16FrameID, pszProtComment);
if (bCyclic) {
proto_tree_add_uint_format(pn_rt_tree, hf_pn_rt_cycle_counter, tvb,
pdu_len - 4, 2, u16CycleCounter, "CycleCounter: %u", u16CycleCounter);
dissect_DataStatus(tvb, pdu_len - 2, tree, u8DataStatus);
if (u8TransferStatus) {
proto_tree_add_uint_format(pn_rt_tree, hf_pn_rt_transfer_status, tvb,
pdu_len - 1, 1, u8TransferStatus,
"TransferStatus: 0x%02x (ignore this frame)", u8TransferStatus);
} else {
proto_tree_add_uint_format(pn_rt_tree, hf_pn_rt_transfer_status, tvb,
pdu_len - 1, 1, u8TransferStatus,
"TransferStatus: 0x%02x (OK)", u8TransferStatus);
}
}
}
col_add_str(pinfo->cinfo, COL_INFO, szFieldSummary);
col_set_str(pinfo->cinfo, COL_PROTOCOL, pszProtShort);
pinfo->private_data = GUINT_TO_POINTER( (guint32) u16FrameID);
next_tvb = tvb_new_subset(tvb, 2, data_len, data_len);
if(!dissector_try_heuristic(heur_subdissector_list, next_tvb, pinfo, tree)) {
dissect_pn_undecoded(next_tvb, 0, pinfo, tree, tvb_length(next_tvb));
}
}
void
proto_register_pn_rt(void)
{
static hf_register_info hf[] = {
{ &hf_pn_rt_frame_id, {
"FrameID", "pn_rt.frame_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_rt_cycle_counter, {
"CycleCounter", "pn_rt.cycle_counter", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_rt_data_status, {
"DataStatus", "pn_rt.ds", FT_UINT8, BASE_HEX, 0, 0x0, NULL, HFILL }},
{ &hf_pn_rt_data_status_ignore, {
"Ignore (1:Ignore/0:Evaluate)", "pn_rt.ds_ignore", FT_UINT8, BASE_HEX, 0, 0x80, NULL, HFILL }},
{ &hf_pn_rt_data_status_Reserved_2, {
"Reserved_2 (should be zero)", "pn_rt.ds_Reserved_2", FT_UINT8, BASE_HEX, 0, 0x40, NULL, HFILL }},
{ &hf_pn_rt_data_status_ok, {
"StationProblemIndicator (1:Ok/0:Problem)", "pn_rt.ds_ok", FT_UINT8, BASE_HEX, 0, 0x20, NULL, HFILL }},
{ &hf_pn_rt_data_status_operate, {
"ProviderState (1:Run/0:Stop)", "pn_rt.ds_operate", FT_UINT8, BASE_HEX, 0, 0x10, NULL, HFILL }},
{ &hf_pn_rt_data_status_res3, {
"Reserved_1 (should be zero)", "pn_rt.ds_res3", FT_UINT8, BASE_HEX, 0, 0x08, NULL, HFILL }},
{ &hf_pn_rt_data_status_valid, {
"DataValid (1:Valid/0:Invalid)", "pn_rt.ds_valid", FT_UINT8, BASE_HEX, 0, 0x04, NULL, HFILL }},
{ &hf_pn_rt_data_status_redundancy, {
"Redundancy", "pn_rt.ds_redundancy", FT_UINT8, BASE_HEX, VALS(pn_rt_ds_redundancy), 0x02, NULL, HFILL }},
{ &hf_pn_rt_data_status_primary, {
"State (1:Primary/0:Backup)", "pn_rt.ds_primary", FT_UINT8, BASE_HEX, 0, 0x01, NULL, HFILL }},
{ &hf_pn_rt_transfer_status,
{ "TransferStatus", "pn_rt.transfer_status", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_rt_sf, {
"SubFrame", "pn_rt.sf", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_rt_sf_crc16, {
"SFCRC16", "pn_rt.sf.crc16", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_rt_sf_position, {
"Position", "pn_rt.sf.position", FT_UINT8, BASE_DEC, NULL, 0x7F, NULL, HFILL }},
{ &hf_pn_rt_sf_position_control, {
"Control", "pn_rt.sf.position_control", FT_UINT8, BASE_DEC, VALS(pn_rt_position_control), 0x80, NULL, HFILL }},
{ &hf_pn_rt_sf_data_length, {
"DataLength", "pn_rt.sf.data_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_rt_sf_cycle_counter, {
"CycleCounter", "pn_rt.sf.cycle_counter", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_rt_frag, {
"PROFINET Real-Time Fragment", "pn_rt.frag", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_rt_frag_data_length, {
"FragDataLength", "pn_rt.frag_data_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_rt_frag_status, {
"FragStatus", "pn_rt.frag_status", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_rt_frag_status_more_follows, {
"MoreFollows", "pn_rt.frag_status.more_follows", FT_UINT8, BASE_HEX, VALS(pn_rt_frag_status_more_follows), 0x80, NULL, HFILL }},
{ &hf_pn_rt_frag_status_error, {
"Error", "pn_rt.frag_status.error", FT_UINT8, BASE_HEX, VALS(pn_rt_frag_status_error), 0x40, NULL, HFILL }},
{ &hf_pn_rt_frag_status_fragment_number, {
"FragmentNumber (zero based)", "pn_rt.frag_status.fragment_number", FT_UINT8, BASE_DEC, NULL, 0x3F, NULL, HFILL }},
{ &hf_pn_rt_frag_data, {
"FragData", "pn_rt.frag_data", FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }},
};
static gint *ett[] = {
&ett_pn_rt,
&ett_pn_rt_data_status,
&ett_pn_rt_sf,
&ett_pn_rt_frag,
&ett_pn_rt_frag_status
};
module_t *pn_rt_module;
proto_pn_rt = proto_register_protocol("PROFINET Real-Time Protocol",
"PN-RT", "pn_rt");
proto_register_field_array(proto_pn_rt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
pn_rt_module = prefs_register_protocol(proto_pn_rt, NULL);
prefs_register_bool_preference(pn_rt_module, "summary_in_tree",
"Show PN-RT summary in protocol tree",
"Whether the PN-RT summary line should be shown in the protocol tree",
&pn_rt_summary_in_tree);
register_heur_dissector_list("pn_rt", &heur_subdissector_list);
init_pn (proto_pn_rt);
}
void
proto_reg_handoff_pn_rt(void)
{
dissector_handle_t pn_rt_handle;
pn_rt_handle = create_dissector_handle(dissect_pn_rt, proto_pn_rt);
dissector_add_uint("ethertype", ETHERTYPE_PROFINET, pn_rt_handle);
dissector_add_uint("udp.port", 0x8892, pn_rt_handle);
heur_dissector_add("pn_rt", dissect_CSF_SDU_heur, proto_pn_rt);
heur_dissector_add("pn_rt", dissect_FRAG_PDU_heur, proto_pn_rt);
}
