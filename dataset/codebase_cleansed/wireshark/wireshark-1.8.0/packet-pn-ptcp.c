static int
dissect_PNPTCP_TLVHeader(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, guint16 *type, guint16 *length)
{
guint16 tl_type;
guint16 tl_length;
dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_ptcp_tl_type, &tl_type);
*type = tl_type >> 9;
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_ptcp_tl_length, &tl_length);
*length = tl_length & 0x1FF;
return offset;
}
static int
dissect_PNPTCP_Subdomain(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 u16FrameID)
{
guint8 mac[6];
e_uuid_t uuid;
offset = dissect_pn_mac(tvb, offset, pinfo, tree, hf_pn_ptcp_master_source_address, mac);
offset = dissect_pn_uuid(tvb, offset, pinfo, tree, hf_pn_ptcp_subdomain_uuid, &uuid);
if(u16FrameID == 0xff00 || u16FrameID == 0xff01) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Master=%02x:%02x:%02x:%02x:%02x:%02x",
mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}
proto_item_append_text(item, ": MasterSource=%02x:%02x:%02x:%02x:%02x:%02x",
mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
proto_item_append_text(item, ", Subdomain=%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
uuid.Data1, uuid.Data2, uuid.Data3,
uuid.Data4[0], uuid.Data4[1],
uuid.Data4[2], uuid.Data4[3],
uuid.Data4[4], uuid.Data4[5],
uuid.Data4[6], uuid.Data4[7]);
return offset;
}
static int
dissect_PNPTCP_Time(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint16 EpochNumber;
guint32 Seconds;
guint32 NanoSeconds;
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_ptcp_epoch_number, &EpochNumber);
offset = dissect_pn_uint32(tvb, offset, pinfo, tree, hf_pn_ptcp_seconds, &Seconds);
offset = dissect_pn_uint32(tvb, offset, pinfo, tree, hf_pn_ptcp_nanoseconds, &NanoSeconds);
proto_item_append_text(item, ": Seconds=%u NanoSeconds=%u EpochNumber=%u",
Seconds, NanoSeconds, EpochNumber);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Time: %4us %09uns, Epoch: %u",
Seconds, NanoSeconds, EpochNumber);
return offset;
}
static int
dissect_PNPTCP_TimeExtension(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint16 Flags;
guint16 CurrentUTCOffset;
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_ptcp_flags, &Flags);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_ptcp_currentutcoffset, &CurrentUTCOffset);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
proto_item_append_text(item, ": Flags=0x%x, CurrentUTCOffset=%u", Flags, CurrentUTCOffset);
return offset;
}
static int
dissect_PNPTCP_Master(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint8 MasterPriority1;
guint8 MasterPriority2;
guint8 ClockClass;
guint8 ClockAccuracy;
gint16 ClockVariance;
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_ptcp_master_priority1, &MasterPriority1);
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_ptcp_master_priority2, &MasterPriority2);
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_ptcp_clock_class, &ClockClass);
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_ptcp_clock_accuracy, &ClockAccuracy);
offset = dissect_pn_int16(tvb, offset, pinfo, tree, hf_pn_ptcp_clockvariance, &ClockVariance);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Prio1=\"%s\"",
val_to_str(MasterPriority1, pn_ptcp_master_prio1_short_vals, "(Reserved: 0x%x)"));
proto_item_append_text(item, ": Prio1=\"%s\", Prio2=%s, Clock: Class=\"%s\", Accuracy=%s, Variance=%d",
val_to_str(MasterPriority1, pn_ptcp_master_prio1_short_vals, "(Reserved: 0x%x)"),
val_to_str(MasterPriority2, pn_ptcp_master_prio2_vals, "(Reserved: 0x%x)"),
val_to_str(ClockClass, pn_ptcp_clock_class_vals, "(Reserved: 0x%x)"),
val_to_str(ClockAccuracy, pn_ptcp_clock_accuracy_vals, "(Reserved: 0x%x)"),
ClockVariance);
return offset;
}
static int
dissect_PNPTCP_PortParameter(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint32 t2portrxdelay;
guint32 t3porttxdelay;
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_pn_uint32(tvb, offset, pinfo, tree, hf_pn_ptcp_t2portrxdelay, &t2portrxdelay);
offset = dissect_pn_uint32(tvb, offset, pinfo, tree, hf_pn_ptcp_t3porttxdelay, &t3porttxdelay);
proto_item_append_text(item, ": T2PortRxDelay=%uns, T3PortTxDelay=%uns",
t2portrxdelay, t3porttxdelay);
col_append_fstr(pinfo->cinfo, COL_INFO, ", T2Rx=%uns, T3Tx=%uns",
t2portrxdelay, t3porttxdelay);
return offset;
}
static int
dissect_PNPTCP_DelayParameter(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint8 mac[6];
offset = dissect_pn_mac(tvb, offset, pinfo, tree, hf_pn_ptcp_port_mac_address, mac);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
proto_item_append_text(item, ": PortMAC=%02x:%02x:%02x:%02x:%02x:%02x",
mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
col_append_fstr(pinfo->cinfo, COL_INFO, ", PortMAC=%02x:%02x:%02x:%02x:%02x:%02x",
mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
return offset;
}
static int
dissect_PNPTCP_PortTime(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint32 t2timestamp;
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_pn_uint32(tvb, offset, pinfo, tree, hf_pn_ptcp_t2timestamp, &t2timestamp);
proto_item_append_text(item, ": T2TimeStamp=%uns", t2timestamp);
col_append_fstr(pinfo->cinfo, COL_INFO, ", T2TS=%uns", t2timestamp);
return offset;
}
static int
dissect_PNPTCP_Option_PROFINET(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 length)
{
guint8 subType;
e_uuid_t uuid;
offset = dissect_pn_uint8(tvb, offset, pinfo, tree, hf_pn_ptcp_profinet_subtype, &subType);
length --;
switch(subType) {
case 1:
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
offset = dissect_pn_uuid(tvb, offset, pinfo, tree, hf_pn_ptcp_irdata_uuid, &uuid);
proto_item_append_text(item, ": IRDataUUID=%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
uuid.Data1, uuid.Data2, uuid.Data3,
uuid.Data4[0], uuid.Data4[1],
uuid.Data4[2], uuid.Data4[3],
uuid.Data4[4], uuid.Data4[5],
uuid.Data4[6], uuid.Data4[7]);
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, length);
break;
}
return offset;
}
static int
dissect_PNPTCP_Option(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 length)
{
guint32 oui;
if (length < 4)
{
if (tree) {
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, length);
}
return (offset);
}
offset = dissect_pn_oid(tvb, offset, pinfo,tree, hf_pn_ptcp_oui, &oui);
length -= 3;
switch (oui)
{
case OUI_PROFINET:
case OUI_PROFINET_MULTICAST:
proto_item_append_text(item, ": PROFINET");
offset = dissect_PNPTCP_Option_PROFINET(tvb, offset, pinfo, tree, item, length);
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, length);
}
return (offset);
}
static int
dissect_PNPTCP_block(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item _U_, gboolean *end, guint16 u16FrameID)
{
guint16 type;
guint16 length;
proto_item *sub_item;
proto_tree *sub_tree;
proto_item *tlvheader_item;
proto_tree *tlvheader_tree;
guint32 u32SubStart;
*end = FALSE;
sub_item = proto_tree_add_item(tree, hf_pn_ptcp_block, tvb, offset, 0, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_pn_ptcp_block);
u32SubStart = offset;
tlvheader_item = proto_tree_add_item(sub_tree, hf_pn_ptcp_block_tlvheader, tvb, offset, 2 , ENC_NA);
tlvheader_tree = proto_item_add_subtree(tlvheader_item, ett_pn_ptcp_block_header);
offset = dissect_PNPTCP_TLVHeader(tvb, offset, pinfo, tlvheader_tree, sub_item, &type, &length);
proto_item_set_text(sub_item, "%s",
val_to_str(type, pn_ptcp_block_type, "Unknown"));
proto_item_append_text(tlvheader_item, ": Type=%s (%x), Length=%u",
val_to_str(type, pn_ptcp_block_type, "Unknown"), type, length);
switch(type) {
case(0x00):
*end = TRUE;
break;
case(0x01):
dissect_PNPTCP_Subdomain(tvb, offset, pinfo, sub_tree, sub_item, u16FrameID);
break;
case(0x02):
dissect_PNPTCP_Time(tvb, offset, pinfo, sub_tree, sub_item);
break;
case(0x03):
dissect_PNPTCP_TimeExtension(tvb, offset, pinfo, sub_tree, sub_item);
break;
case(0x04):
dissect_PNPTCP_Master(tvb, offset, pinfo, sub_tree, sub_item);
break;
case(0x05):
dissect_PNPTCP_PortParameter(tvb, offset, pinfo, sub_tree, sub_item);
break;
case(0x06):
dissect_PNPTCP_DelayParameter(tvb, offset, pinfo, sub_tree, sub_item);
break;
case(0x07):
dissect_PNPTCP_PortTime(tvb, offset, pinfo, sub_tree, sub_item);
break;
case(0x7F):
dissect_PNPTCP_Option(tvb, offset, pinfo, sub_tree, sub_item, length);
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, length);
}
offset += length;
proto_item_set_len(sub_item, offset - u32SubStart);
return offset;
}
static int
dissect_PNPTCP_blocks(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 u16FrameID)
{
gboolean end = FALSE;
while(!end) {
offset = dissect_PNPTCP_block(tvb, offset, pinfo, tree, item, &end, u16FrameID);
}
return offset;
}
static int
dissect_PNPTCP_FollowUpPDU(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 u16FrameID, const char *name, const char *name_short)
{
proto_item *header_item;
proto_tree *header_tree;
guint16 seq_id;
gint32 delay1ns_fup;
header_item = proto_tree_add_item(tree, hf_pn_ptcp_header, tvb, offset, 20 , ENC_NA);
header_tree = proto_item_add_subtree(header_item, ett_pn_ptcp_header);
offset = dissect_pn_padding(tvb, offset, pinfo, header_tree, 12);
offset = dissect_pn_uint16(tvb, offset, pinfo, header_tree, hf_pn_ptcp_seq_id, &seq_id);
offset = dissect_pn_align4(tvb, offset, pinfo, header_tree);
offset = dissect_pn_int32(tvb, offset, pinfo, header_tree, hf_pn_ptcp_delay1ns_fup, &delay1ns_fup);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq=%3u, Delay=%11dns", name, seq_id, delay1ns_fup);
proto_item_append_text(item, "%s: Sequence=%u, Delay=%dns", name_short, seq_id, delay1ns_fup);
proto_item_append_text(header_item, ": Sequence=%u, Delay=%dns", seq_id, delay1ns_fup);
offset = dissect_PNPTCP_blocks(tvb, offset, pinfo, tree, item, u16FrameID);
return offset;
}
static int
dissect_PNPTCP_RTSyncPDU(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 u16FrameID, const char *name, const char *name_short)
{
proto_item *header_item;
proto_tree *header_tree;
guint32 res_1;
guint32 res_2;
guint32 delay10ns;
guint16 seq_id;
guint8 delay1ns_8;
guint64 delay1ns_64;
guint32 delay1ns_32;
guint32 delayms;
header_item = proto_tree_add_item(tree, hf_pn_ptcp_header, tvb, offset, 20 , ENC_NA);
header_tree = proto_item_add_subtree(header_item, ett_pn_ptcp_header);
offset = dissect_pn_uint32(tvb, offset, pinfo, header_tree, hf_pn_ptcp_res1, &res_1);
offset = dissect_pn_uint32(tvb, offset, pinfo, header_tree, hf_pn_ptcp_res2, &res_2);
offset = dissect_pn_uint32(tvb, offset, pinfo, header_tree, hf_pn_ptcp_delay10ns, &delay10ns);
offset = dissect_pn_uint16(tvb, offset, pinfo, header_tree, hf_pn_ptcp_seq_id, &seq_id);
offset = dissect_pn_uint8(tvb, offset, pinfo, header_tree, hf_pn_ptcp_delay1ns_byte, &delay1ns_8);
offset = dissect_pn_align4(tvb, offset, pinfo, header_tree);
offset = dissect_pn_uint32(tvb, offset, pinfo, header_tree, hf_pn_ptcp_delay1ns, &delay1ns_32);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
delay1ns_64 = ((guint64) delay10ns) * 10 + delay1ns_8 + delay1ns_32;
delayms = (guint32) (delay1ns_64 / (1000 * 1000));
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq=%3u, Delay=%11" G_GINT64_MODIFIER "uns",
name, seq_id, delay1ns_64);
proto_item_append_text(item, "%s: Sequence=%u, Delay=%" G_GINT64_MODIFIER "uns",
name_short, seq_id, delay1ns_64);
proto_item_append_text(header_item, ": Sequence=%u, Delay=%" G_GINT64_MODIFIER "uns",
seq_id, delay1ns_64);
if(delay1ns_64 != 0)
proto_item_append_text(header_item, " (%u.%03u,%03u,%03u sec)",
delayms / 1000,
delayms % 1000,
(delay10ns % (1000*100)) / 100,
delay10ns % 100 * 10 + delay1ns_8);
offset = dissect_PNPTCP_blocks(tvb, offset, pinfo, tree, item, u16FrameID);
return offset;
}
static int
dissect_PNPTCP_AnnouncePDU(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 u16FrameID, const char *name, const char *name_short)
{
proto_item *header_item;
proto_tree *header_tree;
guint16 seq_id;
header_item = proto_tree_add_item(tree, hf_pn_ptcp_header, tvb, offset, 20 , ENC_NA);
header_tree = proto_item_add_subtree(header_item, ett_pn_ptcp_header);
offset = dissect_pn_padding(tvb, offset, pinfo, header_tree, 12);
offset = dissect_pn_uint16(tvb, offset, pinfo, header_tree, hf_pn_ptcp_seq_id, &seq_id);
offset = dissect_pn_padding(tvb, offset, pinfo, header_tree, 6);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq=%3u", name, seq_id);
proto_item_append_text(item, "%s: Sequence=%u", name_short, seq_id);
proto_item_append_text(header_item, ": Sequence=%u", seq_id);
offset = dissect_PNPTCP_blocks(tvb, offset, pinfo, tree, item, u16FrameID);
return offset;
}
static int
dissect_PNPTCP_DelayPDU(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint16 u16FrameID, const char *name, const char *name_short)
{
proto_item *header_item;
proto_tree *header_tree;
guint16 seq_id;
guint32 delay1ns;
header_item = proto_tree_add_item(tree, hf_pn_ptcp_header, tvb, offset, 20 , ENC_NA);
header_tree = proto_item_add_subtree(header_item, ett_pn_ptcp_header);
offset = dissect_pn_padding(tvb, offset, pinfo, header_tree, 12);
offset = dissect_pn_uint16(tvb, offset, pinfo, header_tree, hf_pn_ptcp_seq_id, &seq_id);
offset = dissect_pn_align4(tvb, offset, pinfo, header_tree);
offset = dissect_pn_uint32(tvb, offset, pinfo, header_tree, hf_pn_ptcp_delay1ns, &delay1ns);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq=%3u, Delay=%11uns", name, seq_id, delay1ns);
proto_item_append_text(item, "%s: Sequence=%u, Delay=%uns", name_short, seq_id, delay1ns);
proto_item_append_text(header_item, ": Sequence=%u, Delay=%uns", seq_id, delay1ns);
offset = dissect_PNPTCP_blocks(tvb, offset, pinfo, tree, item, u16FrameID);
return offset;
}
static gboolean
dissect_PNPTCP_Data_heur(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree)
{
guint16 u16FrameID;
proto_item *item = NULL;
proto_tree *ptcp_tree = NULL;
int offset = 0;
guint32 u32SubStart;
u16FrameID = GPOINTER_TO_UINT(pinfo->private_data);
if ( (u16FrameID >= 0x0100 && u16FrameID < 0xFF00) || (u16FrameID > 0xFF5F) ) {
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PN-PTCP");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_protocol_format(tree, proto_pn_ptcp, tvb, 0, 0, "PROFINET PTCP, ");
ptcp_tree = proto_item_add_subtree(item, ett_pn_ptcp);
u32SubStart = offset;
switch(u16FrameID) {
case(0x0020):
offset = dissect_PNPTCP_RTSyncPDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "RTSync FU (Clock)", "RTSync FU (Clock)");
break;
case(0x0021):
offset = dissect_PNPTCP_RTSyncPDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "RTSync FU (Time)", "RTSync FU (Time)");
break;
case(0x0080):
offset = dissect_PNPTCP_RTSyncPDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "RTSync (Clock)", "RTSync (Clock)");
break;
case(0x0081):
offset = dissect_PNPTCP_RTSyncPDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "RTSync (Time)", "RTSync (Time)");
break;
case(0xff00):
offset = dissect_PNPTCP_AnnouncePDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "Announce (Clock)", "Announce (Clock)");
break;
case(0xff01):
offset = dissect_PNPTCP_AnnouncePDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "Announce (Time)", "Announce (Time)");
break;
case(0xff20):
offset = dissect_PNPTCP_FollowUpPDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "FollowUp (Clock)", "FollowUp (Clock)");
break;
case(0xff21):
offset = dissect_PNPTCP_FollowUpPDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "FollowUp (Time)", "FollowUp (Time)");
break;
case(0xff40):
offset = dissect_PNPTCP_DelayPDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "DelayReq ", "DelayReq");
break;
case(0xff41):
offset = dissect_PNPTCP_DelayPDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "DelayRes ", "DelayRes");
break;
case(0xff42):
offset = dissect_PNPTCP_DelayPDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "DelayFuRes ", "DelayFuRes");
break;
case(0xff43):
offset = dissect_PNPTCP_DelayPDU (tvb, offset, pinfo, ptcp_tree, item, u16FrameID, "DelayRes ", "DelayRes");
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, tvb_length_remaining(tvb, offset));
col_append_fstr(pinfo->cinfo, COL_INFO, "Reserved FrameID 0x%04x", u16FrameID);
proto_item_append_text(item, "Reserved FrameID 0x%04x", u16FrameID);
offset += tvb_length_remaining(tvb, offset);
}
proto_item_set_len(item, offset - u32SubStart);
return TRUE;
}
void
proto_register_pn_ptcp (void)
{
static hf_register_info hf[] = {
{ &hf_pn_ptcp_header,
{ "Header", "pn_ptcp.header", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_block,
{ "Block", "pn_ptcp.block", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_block_tlvheader,
{ "TLVHeader", "pn_ptcp.tlvheader", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_res1,
{ "Reserved 1", "pn_ptcp.res1", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_res2,
{ "Reserved 2", "pn_ptcp.res2", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_delay10ns,
{ "Delay10ns", "pn_ptcp.delay10ns", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_seq_id,
{ "SequenceID", "pn_ptcp.sequence_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_delay1ns_byte,
{ "Delay1ns_Byte", "pn_ptcp.delay1ns_byte", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_delay1ns,
{ "Delay1ns", "pn_ptcp.delay1ns", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_delay1ns_fup,
{ "Delay1ns_FUP", "pn_ptcp.delay1ns_fup", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_tl_length,
{ "TypeLength.Length", "pn_ptcp.tl_length", FT_UINT16, BASE_DEC, 0x0, 0x1FF, NULL, HFILL }},
{ &hf_pn_ptcp_tl_type,
{ "TypeLength.Type", "pn_ptcp.tl_type", FT_UINT16, BASE_DEC, 0x0, 0xFE00, NULL, HFILL }},
{ &hf_pn_ptcp_master_source_address,
{ "MasterSourceAddress", "pn_ptcp.master_source_address", FT_ETHER, BASE_NONE, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_subdomain_uuid,
{ "SubdomainUUID", "pn_ptcp.subdomain_uuid", FT_GUID, BASE_NONE, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_port_mac_address,
{ "PortMACAddress", "pn_ptcp.port_mac_address", FT_ETHER, BASE_NONE, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_t2portrxdelay,
{ "T2PortRxDelay (ns)", "pn_ptcp.t2portrxdelay", FT_UINT32, BASE_DEC, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_t3porttxdelay,
{ "T3PortTxDelay (ns)", "pn_ptcp.t3porttxdelay", FT_UINT32, BASE_DEC, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_t2timestamp,
{ "T2TimeStamp (ns)", "pn_ptcp.t2timestamp", FT_UINT32, BASE_DEC, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_epoch_number,
{ "EpochNumber", "pn_ptcp.epoch_number", FT_UINT16, BASE_DEC, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_seconds,
{ "Seconds", "pn_ptcp.seconds", FT_UINT32, BASE_DEC, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_nanoseconds,
{ "NanoSeconds", "pn_ptcp.nanoseconds", FT_UINT32, BASE_DEC, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_flags,
{ "Flags", "pn_ptcp.flags", FT_UINT16, BASE_HEX, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_currentutcoffset,
{ "CurrentUTCOffset", "pn_ptcp.currentutcoffset", FT_UINT16, BASE_DEC, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_master_priority1,
{ "MasterPriority1", "pn_ptcp.master_priority1", FT_UINT8, BASE_DEC, VALS(pn_ptcp_master_prio1_vals), 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_master_priority2,
{ "MasterPriority2", "pn_ptcp.master_priority2", FT_UINT8, BASE_DEC, VALS(pn_ptcp_master_prio2_vals), 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_clock_class,
{ "ClockClass", "pn_ptcp.clock_class", FT_UINT8, BASE_DEC, VALS(pn_ptcp_clock_class_vals), 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_clock_accuracy,
{ "ClockAccuracy", "pn_ptcp.clock_accuracy", FT_UINT8, BASE_DEC, VALS(pn_ptcp_clock_accuracy_vals), 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_clockvariance,
{ "ClockVariance", "pn_ptcp.clockvariance", FT_INT16, BASE_DEC, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_oui,
{ "Organizationally Unique Identifier", "pn_ptcp.oui", FT_UINT24, BASE_HEX,
VALS(pn_ptcp_oui_vals), 0x0, NULL, HFILL }},
{ &hf_pn_ptcp_profinet_subtype,
{ "Subtype", "pn_ptcp.subtype", FT_UINT8, BASE_HEX,
VALS(pn_ptcp_profinet_subtype_vals), 0x0, "PROFINET Subtype", HFILL }},
{ &hf_pn_ptcp_irdata_uuid,
{ "IRDataUUID", "pn_ptcp.irdata_uuid", FT_GUID, BASE_NONE, 0x0, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_pn_ptcp,
&ett_pn_ptcp_header,
&ett_pn_ptcp_block,
&ett_pn_ptcp_block_header
};
proto_pn_ptcp = proto_register_protocol ("PROFINET PTCP", "PN-PTCP", "pn_ptcp");
proto_register_field_array (proto_pn_ptcp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_pn_ptcp (void)
{
heur_dissector_add("pn_rt", dissect_PNPTCP_Data_heur, proto_pn_ptcp);
}
