static void
dissect_itdm_125usec(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
proto_item *itdm_item = NULL;
proto_tree *itdm_tree = NULL;
int offset;
guint32 flowid;
guint32 chanid;
guint16 chloc1;
guint16 chloc2;
guint8 chcmd;
guint8 actbit;
guint8 ackbit;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ITDM");
flowid = tvb_get_ntoh24(tvb, ITDM_FLOWID_OFFSET);
chanid = tvb_get_ntoh24(tvb, ITDM_CHANID_OFFSET);
chcmd = tvb_get_guint8(tvb, ITDM_CHCMD_OFFSET);
chloc1 = tvb_get_ntohs(tvb, ITDM_CHLOC1_OFFSET);
actbit = (chcmd & 0x10) ? 1 : 0;
ackbit = (chcmd & 0x20) ? 1 : 0;
chcmd = chcmd & 0x0f;
col_add_fstr(pinfo->cinfo, COL_INFO,
"Flow %d Chan %d ACT %d ACK %d %s",
flowid, chanid, actbit, ackbit,
val_to_str_const(chcmd, chcmd_vals, "Reserved"));
if (chcmd == ITDM_CMD_NEW_CHAN ||
chcmd == ITDM_CMD_CLOSE_CHAN ||
chcmd == ITDM_CMD_CYCLIC_REAF)
{
col_append_fstr(pinfo->cinfo, COL_INFO,
" Loc1 %d", chloc1);
}
else if (chcmd == ITDM_CMD_RELOC_CHAN)
{
chloc2 = tvb_get_ntohs(tvb, ITDM_CHLOC2_OFFSET);
col_append_fstr(pinfo->cinfo, COL_INFO,
" Loc1 %d Loc2 %d", chloc1, chloc2);
}
offset = 0;
if (tree)
{
itdm_item = proto_tree_add_item(tree, proto_itdm, tvb, 0, -1, ENC_NA);
itdm_tree = proto_item_add_subtree(itdm_item, ett_itdm);
proto_tree_add_item(itdm_tree, hf_itdm_timestamp, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(itdm_tree, hf_itdm_seqnum, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(itdm_tree, hf_itdm_sop_eop, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(itdm_tree, hf_itdm_last_pack, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(itdm_tree, hf_itdm_pktlen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(itdm_tree, hf_itdm_chksum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(itdm_tree, hf_itdm_uid, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(itdm_tree, hf_itdm_ack, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(itdm_tree, hf_itdm_act, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(itdm_tree, hf_itdm_chcmd, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(itdm_tree, hf_itdm_chid, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
if (chcmd == ITDM_CMD_PACKET_RATE)
{
proto_tree_add_item(itdm_tree, hf_itdm_pktrate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else
{
proto_tree_add_item(itdm_tree, hf_itdm_chloc1, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (chcmd == ITDM_CMD_CYCLIC_REAF ||
chcmd == ITDM_CMD_NEW_CHAN ||
chcmd == ITDM_CMD_CLOSE_CHAN)
{
proto_tree_add_item(itdm_tree, hf_itdm_cxnsize, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else
{
proto_tree_add_item(itdm_tree, hf_itdm_chloc2, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, tree);
}
static void
dissect_itdm_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
proto_item *itdm_ctl_item = NULL;
proto_tree *itdm_ctl_tree = NULL;
int offset;
guint32 flowid;
guint8 command;
guint32 trans_id;
guint32 paired_trans_id;
guint32 allocd_flowid;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ITDM-Control");
flowid = tvb_get_ntoh24(tvb, ITDM_FLOWID_OFFSET);
command = tvb_get_guint8(tvb, ITDM_CTL_CMD_OFFSET);
allocd_flowid = tvb_get_ntoh24(tvb, ITDM_CTL_FLOWID_OFFSET);
trans_id = tvb_get_ntohl(tvb, ITDM_CTL_TRANSID_OFFSET);
paired_trans_id = tvb_get_ntohl(tvb, ITDM_CTL_PAIRED_TRANSID_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO,
"Flow %d Command %s ",
flowid, val_to_str_const(command, itdm_ctl_command_vals, "Reserved"));
if (command != ITDM_CTL_CMD_AFI_REQ )
{
col_append_fstr(pinfo->cinfo, COL_INFO,
" Alloc'd FlowID %d", allocd_flowid);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " TransID 0x%x ", trans_id);
if (command != ITDM_CTL_CMD_AFI_REQ )
{
col_append_fstr(pinfo->cinfo, COL_INFO,
" Paired TransID 0x%x", paired_trans_id);
}
offset = 0;
if (tree)
{
itdm_ctl_item = proto_tree_add_item(tree, proto_itdm, tvb, 0, -1, ENC_NA);
itdm_ctl_tree = proto_item_add_subtree(itdm_ctl_item, ett_itdm_ctl);
proto_tree_add_item(itdm_ctl_tree, hf_itdm_timestamp, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(itdm_ctl_tree, hf_itdm_seqnum, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(itdm_ctl_tree, hf_itdm_sop_eop, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(itdm_ctl_tree, hf_itdm_last_pack, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(itdm_ctl_tree, hf_itdm_pktlen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(itdm_ctl_tree, hf_itdm_chksum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(itdm_ctl_tree, hf_itdm_uid, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(itdm_ctl_tree, hf_itdm_ctl_transid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(itdm_ctl_tree, hf_itdm_ctl_command, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (command != ITDM_CTL_CMD_AFI_REQ) {
proto_tree_add_item(itdm_ctl_tree, hf_itdm_ctl_flowid, tvb, offset, 3, ENC_BIG_ENDIAN);
}
offset += 3;
proto_tree_add_item(itdm_ctl_tree, hf_itdm_ctl_dm, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 1;
proto_tree_add_item(itdm_ctl_tree, hf_itdm_ctl_emts, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(itdm_ctl_tree, hf_itdm_ctl_pktrate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (command != ITDM_CTL_CMD_AFI_REQ) {
proto_tree_add_item(itdm_ctl_tree, hf_itdm_ctl_ptid, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
offset += 2;
proto_tree_add_item(itdm_ctl_tree, hf_itdm_ctl_cksum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, tree);
}
static void
dissect_itdm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 flowid;
if (tvb_captured_length(tvb) < 18)
return;
flowid = tvb_get_ntoh24(tvb, ITDM_FLOWID_OFFSET);
if (flowid == gbl_ItdmCTLFlowNo)
dissect_itdm_control(tvb, pinfo, tree);
else
dissect_itdm_125usec(tvb, pinfo, tree);
}
void
proto_register_itdm(void)
{
static hf_register_info hf[] = {
{ &hf_itdm_timestamp,{ "Timestamp", "itdm.timestamp",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_itdm_seqnum,{ "Sequence Number", "itdm.seqnum",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_itdm_sop_eop,{ "Start/End of Packet", "itdm.sop_eop",
FT_UINT8, BASE_DEC, VALS(sop_eop_vals), 0xc0, NULL, HFILL } },
{ &hf_itdm_last_pack,{ "Last Packet", "itdm.last_pack",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x20, NULL, HFILL } },
{ &hf_itdm_pktlen,{ "Packet Length", "itdm.pktlen",
FT_UINT16, BASE_DEC, NULL, 0x07ff, NULL, HFILL } },
{ &hf_itdm_chksum,{ "Checksum", "itdm.chksum",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_itdm_uid,{ "Flow ID", "itdm.uid",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_itdm_ack,{ "ACK", "itdm.ack",
FT_BOOLEAN, 8, TFS(&ack_tfs), 0x20, NULL, HFILL } },
{ &hf_itdm_act,{ "Activate", "itdm.act",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x10, NULL, HFILL } },
{ &hf_itdm_chcmd,{ "Channel Command", "itdm.chcmd",
FT_UINT8, BASE_DEC, VALS(chcmd_vals), 0x0f, NULL, HFILL } },
{ &hf_itdm_chid,{ "Channel ID", "itdm.chid",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_itdm_chloc1,{ "Channel Location 1", "itdm.chloc1",
FT_UINT16, BASE_DEC, NULL, 0x1ff, NULL, HFILL } },
{ &hf_itdm_chloc2,{ "Channel Location 2", "itdm.chloc2",
FT_UINT16, BASE_DEC, NULL, 0x1ff, NULL, HFILL } },
{ &hf_itdm_pktrate,{ "IEEE 754 Packet Rate", "itdm.pktrate",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_itdm_cxnsize, { "Connection Size", "itdm.cxnsize",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_itdm_ctl_transid, { "Transaction ID", "itdm.ctl_transid",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_itdm_ctl_command, { "Control Command", "itdm.ctl_cmd",
FT_UINT8, BASE_DEC, VALS(itdm_ctl_command_vals), 0x0, NULL, HFILL } },
{ &hf_itdm_ctl_flowid, { "Allocated Flow ID", "itdm.ctl_flowid",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_itdm_ctl_dm, { "I-TDM Data Mode", "itdm.ctl_dm",
FT_UINT8, BASE_DEC, VALS(itdm_ctl_data_mode_vals), 0x0, NULL, HFILL } },
{ &hf_itdm_ctl_emts, { "I-TDM Explicit Multi-timeslot Size", "itdm.ctlemts",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_itdm_ctl_pktrate, { "I-TDM Packet Rate", "itdm.ctl_pktrate",
FT_UINT32, BASE_HEX, VALS(itdm_ctl_pktrate_vals), 0x0, NULL, HFILL } },
{ &hf_itdm_ctl_ptid, { "Paired Transaction ID", "itdm.ctl_ptid",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_itdm_ctl_cksum, { "ITDM Control Message Checksum", "itdm.ctl_cksum",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL } }
};
static gint *ett[] = {
&ett_itdm,
&ett_itdm_ctl
};
module_t *itdm_module;
proto_itdm = proto_register_protocol("Internal TDM", "ITDM", "itdm");
proto_register_field_array(proto_itdm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
itdm_module = prefs_register_protocol(proto_itdm, proto_reg_handoff_itdm);
prefs_register_uint_preference(itdm_module, "mpls_label",
"ITDM MPLS label (Flow Bundle ID in hex)",
"The MPLS label (aka Flow Bundle ID) used by ITDM traffic.",
16, &gbl_ItdmMPLSLabel);
prefs_register_uint_preference(itdm_module, "ctl_flowno",
"I-TDM Control Protocol Flow Number",
"Flow Number used by I-TDM Control Protocol traffic.",
10, &gbl_ItdmCTLFlowNo);
}
void
proto_reg_handoff_itdm(void)
{
static gboolean Initialized=FALSE;
static dissector_handle_t itdm_handle;
static guint ItdmMPLSLabel;
if (!Initialized) {
itdm_handle = create_dissector_handle( dissect_itdm, proto_itdm );
data_handle = find_dissector("data");
Initialized=TRUE;
} else {
dissector_delete_uint("mpls.label", ItdmMPLSLabel, itdm_handle);
}
ItdmMPLSLabel = gbl_ItdmMPLSLabel;
dissector_add_uint("mpls.label", gbl_ItdmMPLSLabel, itdm_handle);
}
