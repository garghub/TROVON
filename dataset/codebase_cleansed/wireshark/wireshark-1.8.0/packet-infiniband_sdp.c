static int
dissect_ib_sdp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int local_offset = 0;
proto_item *SDP_header_item = NULL;
proto_tree *SDP_header_tree = NULL;
proto_item *SDP_BSDH_header_item = NULL;
proto_tree *SDP_BSDH_header_tree = NULL;
proto_item *SDP_EH_header_item = NULL;
proto_tree *SDP_EH_header_tree = NULL;
guint8 mid;
conversation_t *conv;
conversation_infiniband_data *convo_data = NULL;
dissector_handle_t infiniband_handle;
if (tvb_length(tvb) < 16)
return 0;
if (gPREF_MAN_EN) {
if ( (ADDRESSES_EQUAL(&pinfo->src, &manual_addr[0]) &&
ADDRESSES_EQUAL(&pinfo->dst, &manual_addr[1]) &&
(pinfo->srcport == 0xffffffff || pinfo->srcport == gPREF_QP[0]) &&
(pinfo->destport == 0xffffffff || pinfo->destport == gPREF_QP[1])) ||
(ADDRESSES_EQUAL(&pinfo->src, &manual_addr[1]) &&
ADDRESSES_EQUAL(&pinfo->dst, &manual_addr[0]) &&
(pinfo->srcport == 0xffffffff || pinfo->srcport == gPREF_QP[1]) &&
(pinfo->destport == 0xffffffff || pinfo->destport == gPREF_QP[0])) )
goto manual_override;
}
conv = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_IBQP, pinfo->srcport, pinfo->destport, 0);
if (!conv) {
conv = find_conversation(pinfo->fd->num, &pinfo->dst, &pinfo->dst,
PT_IBQP, pinfo->destport, pinfo->destport, NO_ADDR_B|NO_PORT_B);
if (!conv)
return 0;
}
if (proto_infiniband < 0) {
infiniband_handle = find_dissector("infiniband");
if (!infiniband_handle)
return 0;
proto_infiniband = dissector_handle_get_protocol_index(infiniband_handle);
}
convo_data = conversation_get_proto_data(conv, proto_infiniband);
if (!(convo_data->service_id & SERVICE_ID_MASK))
return 0;
manual_override:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SDP");
SDP_header_item = proto_tree_add_item(tree, hf_ib_sdp, tvb, local_offset, -1, ENC_NA);
SDP_header_tree = proto_item_add_subtree(SDP_header_item, ett_ib_sdp);
SDP_BSDH_header_item = proto_tree_add_item(SDP_header_tree, hf_ib_sdp_bsdh, tvb, local_offset, 16, ENC_NA);
SDP_BSDH_header_tree = proto_item_add_subtree(SDP_BSDH_header_item, ett_ib_sdp_bsdh);
mid = tvb_get_guint8(tvb, local_offset);
proto_tree_add_item(SDP_BSDH_header_tree, hf_ib_sdp_mid, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(SDP_BSDH_header_tree, hf_ib_sdp_flags, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SDP_BSDH_header_tree, hf_ib_sdp_flags_oobpres, tvb, local_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(SDP_BSDH_header_tree, hf_ib_sdp_flags_oob_pend, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(SDP_BSDH_header_tree, hf_ib_sdp_flags_reqpipe, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(SDP_BSDH_header_tree, hf_ib_sdp_bufs, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SDP_BSDH_header_tree, hf_ib_sdp_len, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(SDP_BSDH_header_tree, hf_ib_sdp_mseq, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(SDP_BSDH_header_tree, hf_ib_sdp_mseqack, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
switch (mid) {
case Hello:
SDP_EH_header_item = proto_tree_add_item(SDP_header_tree, hf_ib_sdp_hh, tvb, local_offset, 48, ENC_NA);
SDP_EH_header_tree = proto_item_add_subtree(SDP_EH_header_item, ett_ib_sdp_hh);
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_majv, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_minv, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_ipv, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_cap, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_cap_invalidate, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_cap_extmaxadverts, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 1;
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_maxadverts, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_desremrcvsz, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_localrcvsz, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_localport, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 2;
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_src_ip, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_dst_ip, tvb, local_offset, 16, ENC_NA); local_offset += 16;
local_offset += 2;
proto_tree_add_item(SDP_EH_header_tree, hf_ib_sdp_extmaxadverts, tvb, local_offset, 2, ENC_BIG_ENDIAN);
break;
case HelloAck:
proto_tree_add_item(SDP_header_tree, hf_ib_sdp_hah, tvb, local_offset, 48, ENC_NA);
break;
case DisConn:
break;
case AbortConn:
break;
case SendSm:
break;
case RdmaWrCompl:
proto_tree_add_item(SDP_header_tree, hf_ib_sdp_rwch, tvb, local_offset, 48, ENC_NA);
break;
case RdmaRdCompl:
proto_tree_add_item(SDP_header_tree, hf_ib_sdp_rrch, tvb, local_offset, 48, ENC_NA);
break;
case ModeChange:
proto_tree_add_item(SDP_BSDH_header_tree, hf_ib_sdp_mch, tvb, local_offset, 48, ENC_NA);
break;
case SrcAvailCancel:
break;
case SinkAvailCancel:
break;
case SinkCancelAck:
break;
case ChRcvBuf:
proto_tree_add_item(SDP_header_tree, hf_ib_sdp_crbh, tvb, local_offset, 48, ENC_NA);
break;
case ChRcvBufAck:
proto_tree_add_item(SDP_header_tree, hf_ib_sdp_crbah, tvb, local_offset, 48, ENC_NA);
break;
case SuspComm:
proto_tree_add_item(SDP_header_tree, hf_ib_sdp_suspch, tvb, local_offset, 48, ENC_NA);
break;
case SuspCommAck:
break;
case SinkAvail:
proto_tree_add_item(SDP_header_tree, hf_ib_sdp_sinkah, tvb, local_offset, 48, ENC_NA);
break;
case SrcAvail:
proto_tree_add_item(SDP_header_tree, hf_ib_sdp_srcah, tvb, local_offset, 48, ENC_NA);
break;
case Data:
proto_tree_add_item(SDP_header_tree, hf_ib_sdp_data, tvb, local_offset, -1, ENC_NA);
break;
default:
break;
}
col_append_fstr(pinfo->cinfo, COL_INFO, "(SDP %s)",
rval_to_str(mid, mid_meanings, "Unknown"));
return tvb_length(tvb);
}
void
proto_register_ib_sdp(void)
{
module_t *ib_sdp_module;
static hf_register_info hf[] = {
{ &hf_ib_sdp, {
"SDP", "infiniband.sdp",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_ib_sdp_bsdh, {
"BSDH", "infiniband.sdp.bsdh",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_ib_sdp_mid, {
"MID", "infiniband.sdp.bsdh.mid",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(mid_meanings), 0x0, NULL, HFILL}
},
{&hf_ib_sdp_flags, {
"Flags", "infiniband.sdp.bsdh.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_ib_sdp_flags_oobpres, {
"OOB_PRES", "infiniband.sdp.bsdh.oobpres",
FT_UINT8, BASE_HEX, NULL, 0x1, "Out-Of-Band Data is present", HFILL}
},
{&hf_ib_sdp_flags_oob_pend, {
"OOB_PEND", "infiniband.sdp.bsdh.oobpend",
FT_UINT8, BASE_HEX, NULL, 0x2, "Out-Of-Band Data is pending", HFILL}
},
{&hf_ib_sdp_flags_reqpipe, {
"REQ_PIPE", "infiniband.sdp.bsdh.reqpipe",
FT_UINT8, BASE_HEX, NULL, 0x4, "Request change to Pipelined Mode", HFILL}
},
{&hf_ib_sdp_bufs, {
"Buffers", "infiniband.sdp.bsdh.bufs",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_ib_sdp_len, {
"Length", "infiniband.sdp.bsdh.len",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_ib_sdp_mseq, {
"MSeq", "infiniband.sdp.bsdh.mseq",
FT_UINT32, BASE_HEX, NULL, 0x0, "Message Sequence Number", HFILL}
},
{&hf_ib_sdp_mseqack, {
"MSeqAck", "infiniband.sdp.bsdh.mseqack",
FT_UINT32, BASE_HEX, NULL, 0x0, "Message Sequence Number Acknowledgement", HFILL}
},
{&hf_ib_sdp_hh, {
"Hello Header", "infiniband.sdp.hh",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL}
},
{&hf_ib_sdp_majv, {
"Major Protocol Version Number", "infiniband.sdp.hh.majv",
FT_UINT8, BASE_HEX, NULL, 0xf0, NULL, HFILL}
},
{&hf_ib_sdp_minv, {
"Minor Protocol Version Number", "infiniband.sdp.hh.minv",
FT_UINT8, BASE_HEX, NULL, 0x0f, NULL, HFILL}
},
{&hf_ib_sdp_ipv,
{"IP version", "infiniband.sdp.hh.ipv",
FT_UINT8, BASE_HEX, NULL, 0xf0, NULL, HFILL}
},
{&hf_ib_sdp_cap, {
"Capabilities", "infiniband.sdp.hh.cap",
FT_UINT8, BASE_HEX, NULL, 0x0f, NULL, HFILL}
},
{&hf_ib_sdp_cap_invalidate, {
"INVALIDATE_CAP", "infiniband.sdp.hh.cap_invalidate",
FT_UINT8, BASE_HEX, NULL, 0x1, "Supports incoming Send w/Invalidate opcode", HFILL}
},
{&hf_ib_sdp_cap_extmaxadverts, {
"EXTENDED_MAXADVERTS", "infiniband.sdp.hh.cap_extmaxadverts",
FT_UINT8, BASE_HEX, NULL, 0x2, "Extended MaxAdverts is used", HFILL}
},
{&hf_ib_sdp_maxadverts, {
"Maximum Advertisements", "infiniband.sdp.hh.maxadverts",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_ib_sdp_desremrcvsz, {
"DesRemRcvSz", "infiniband.sdp.hh.desremrcvsz",
FT_UINT32, BASE_DEC, NULL, 0x0, "Desired Remote Receive Size", HFILL}
},
{&hf_ib_sdp_localrcvsz,
{"LocalRcvSz", "infiniband.sdp.hh.localrcvsz",
FT_UINT32, BASE_DEC, NULL, 0x0, "Local Receive Size", HFILL}
},
{&hf_ib_sdp_localport, {
"Local Port", "infiniband.sdp.hh.localport",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_ib_sdp_src_ip, {
"Source IP", "infiniband.sdp.hh.src_ip",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_ib_sdp_dst_ip, {
"Destination IP", "infiniband.sdp.hh.dst_ip",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_ib_sdp_extmaxadverts, {
"Extended MaxAdverts", "infiniband.sdp.hh.extmaxadverts",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_ib_sdp_hah, {
"HelloAck Header", "infiniband.sdp.hah",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL}
},
{&hf_ib_sdp_rwch, {
"RdmaWrCompl Header", "infiniband.sdp.rwch",
FT_NONE, BASE_NONE, NULL, 0x00, "RDMA Write Complete", HFILL}
},
{&hf_ib_sdp_rrch, {
"RdmaRdCompl Header", "infiniband.sdp.rrch",
FT_NONE, BASE_NONE, NULL, 0x00, "RDMA Read Complete", HFILL}
},
{&hf_ib_sdp_mch, {
"ModeChange Header", "infiniband.sdp.mch",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL}
},
{&hf_ib_sdp_crbh, {
"ChRcvBuf Header", "infiniband.sdp.crbh",
FT_NONE, BASE_NONE, NULL, 0x00, "Change Receive private Buffer size", HFILL}
},
{&hf_ib_sdp_crbah, {
"ChRcvBufAck Header", "infiniband.sdp.crbah",
FT_NONE, BASE_NONE, NULL, 0x00, "Change Receive private Buffer size Acknowledgement", HFILL}
},
{&hf_ib_sdp_suspch, {
"SuspComm Header", "infiniband.sdp.suspch",
FT_NONE, BASE_NONE, NULL, 0x00, "Suspend Communication", HFILL}
},
{&hf_ib_sdp_sinkah, {
"SinkAvail Header", "infiniband.sdp.sinkah",
FT_NONE, BASE_NONE, NULL, 0x00, "Data Sink Available", HFILL}
},
{&hf_ib_sdp_srcah, {
"SrcAvail Header", "infiniband.sdp.srcah",
FT_NONE, BASE_NONE, NULL, 0x00, "Data Source Available", HFILL}
},
{&hf_ib_sdp_data, {
"Data", "infiniband.sdp.Data",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}
}
};
static gint *ett[] = {
&ett_ib_sdp,
&ett_ib_sdp_bsdh,
&ett_ib_sdp_hh,
};
proto_ib_sdp = proto_register_protocol("Infiniband Sockets Direct Protocol", "Infiniband SDP", "ib_sdp");
new_register_dissector("infiniband.sdp", dissect_ib_sdp, proto_ib_sdp);
proto_register_field_array(proto_ib_sdp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ib_sdp_module = prefs_register_protocol(proto_ib_sdp, proto_reg_handoff_ib_sdp);
prefs_register_bool_preference(ib_sdp_module, "manual_en", "Enable manual settings",
"Check to treat all traffic between the configured source/destination as SDP",
&gPREF_MAN_EN);
prefs_register_static_text_preference(ib_sdp_module, "addr_a", "Address A",
"Side A of the manually-configured connection");
prefs_register_enum_preference(ib_sdp_module, "addr_a_type", "Address Type",
"Type of address specified", &gPREF_TYPE[0], pref_address_types, FALSE);
prefs_register_string_preference(ib_sdp_module, "addr_a_id", "ID",
"LID/GID of address A", &gPREF_ID[0]);
prefs_register_uint_preference(ib_sdp_module, "addr_a_qp", "QP Number",
"QP Number for address A", 10, &gPREF_QP[0]);
prefs_register_static_text_preference(ib_sdp_module, "addr_b", "Address B",
"Side B of the manually-configured connection");
prefs_register_enum_preference(ib_sdp_module, "addr_b_type", "Address Type",
"Type of address specified", &gPREF_TYPE[1], pref_address_types, FALSE);
prefs_register_string_preference(ib_sdp_module, "addr_b_id", "ID",
"LID/GID of address B", &gPREF_ID[1]);
prefs_register_uint_preference(ib_sdp_module, "addr_b_qp", "QP Number",
"QP Number for address B", 10, &gPREF_QP[1]);
}
void
proto_reg_handoff_ib_sdp(void)
{
static gboolean initialized = FALSE;
if (!initialized) {
heur_dissector_add("infiniband.payload", dissect_ib_sdp, proto_ib_sdp);
heur_dissector_add("infiniband.mad.cm.private", dissect_ib_sdp, proto_ib_sdp);
manual_addr_data[0] = se_alloc(GID_SIZE);
manual_addr_data[1] = se_alloc(GID_SIZE);
initialized = TRUE;
}
if (gPREF_MAN_EN) {
gboolean error_occured = FALSE;
char *not_parsed;
int i;
for (i = 0; i < 2; i++) {
if (gPREF_TYPE[i] == 0) {
errno = 0;
*((guint16*)manual_addr_data[i]) = (guint16)strtoul(gPREF_ID[i], &not_parsed, 0);
if (errno || *not_parsed != '\0') {
error_occured = TRUE;
} else {
SET_ADDRESS(&manual_addr[i], AT_IB, sizeof(guint16), manual_addr_data[i]);
}
} else {
if (! inet_pton(AF_INET6, gPREF_ID[i], manual_addr_data[i]) ) {
error_occured = TRUE;
} else {
SET_ADDRESS(&manual_addr[i], AT_IB, GID_SIZE, manual_addr_data[i]);
}
}
if (error_occured) {
gPREF_MAN_EN = FALSE;
break;
}
}
}
}
