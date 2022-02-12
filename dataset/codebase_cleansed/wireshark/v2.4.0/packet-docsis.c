static void
dissect_ehdr (tvbuff_t * tvb, proto_tree * tree, packet_info * pinfo)
{
proto_tree *ehdr_tree;
proto_item *eh_length_item;
gint ehdrlen;
int pos;
guint8 type;
guint8 len;
ehdrlen = tvb_get_guint8 (tvb, 1);
pos = 4;
ehdr_tree = proto_tree_add_subtree(tree, tvb, pos, ehdrlen, ett_ehdr, NULL, "Extended Header");
while (pos < ehdrlen + 4)
{
type = (tvb_get_guint8 (tvb, pos) & 0xF0);
len = (tvb_get_guint8 (tvb, pos) & 0x0F);
if ((((type >> 4) & 0x0F)== 6) && (len == 2))
{
proto_tree_add_uint_format_value(ehdr_tree, hf_docsis_eh_type, tvb, pos, 1, 0x60, "Unsolicited Grant Sync EHDR Sub-Element");
}
else
{
proto_tree_add_item (ehdr_tree, hf_docsis_eh_type, tvb, pos, 1, ENC_BIG_ENDIAN);
}
eh_length_item = proto_tree_add_item (ehdr_tree, hf_docsis_eh_len, tvb, pos, 1, ENC_BIG_ENDIAN);
switch ((type >> 4) & 0x0F)
{
case EH_REQUEST:
if (len == 3)
{
proto_tree_add_item(ehdr_tree, hf_docsis_mini_slots, tvb, pos + 1, 1, ENC_NA);
proto_tree_add_item(ehdr_tree, hf_docsis_sid, tvb, pos + 2, 2, ENC_BIG_ENDIAN);
}
else
{
expert_add_info(pinfo, eh_length_item, &ei_docsis_eh_len);
return;
}
break;
case EH_ACK_REQ:
if (len == 2)
{
proto_tree_add_item(ehdr_tree, hf_docsis_sid, tvb, pos + 1, 2, ENC_BIG_ENDIAN);
}
else
{
expert_add_info(pinfo, eh_length_item, &ei_docsis_eh_len);
return;
}
break;
case EH_BP_UP:
proto_tree_add_item (ehdr_tree, hf_docsis_key_seq, tvb, pos + 1, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_ver, tvb, pos + 1, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_bpi_en, tvb, pos + 2, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_toggle_bit, tvb, pos + 2,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_sid, tvb, pos + 2, 2,
ENC_BIG_ENDIAN);
frag_sid = tvb_get_guint8 (tvb, pos+2) & 0xCFFF;
proto_tree_add_item (ehdr_tree, hf_docsis_mini_slots, tvb, pos + 4,
1, ENC_BIG_ENDIAN);
if (pinfo->fragmented)
{
proto_tree_add_item (ehdr_tree, hf_docsis_frag_rsvd, tvb, pos+5,
1, ENC_BIG_ENDIAN);
frag_flags = tvb_get_guint8 (tvb, pos+5) & 0x30;
proto_tree_add_item (ehdr_tree, hf_docsis_frag_first, tvb, pos+5,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_frag_last, tvb, pos+5,
1, ENC_BIG_ENDIAN);
frag_seq = tvb_get_guint8 (tvb, pos+5) & 0x0F;
proto_tree_add_item (ehdr_tree, hf_docsis_frag_seq, tvb, pos+5,
1, ENC_BIG_ENDIAN);
}
break;
case EH_BP_DOWN:
proto_tree_add_item (ehdr_tree, hf_docsis_key_seq, tvb, pos + 1, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_ver, tvb, pos + 1, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_bpi_en, tvb, pos + 2, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_toggle_bit, tvb, pos + 2,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_said, tvb, pos + 2, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_reserved, tvb, pos + 4, 1,
ENC_BIG_ENDIAN);
break;
case EH_SFLOW_HDR_DOWN:
case EH_SFLOW_HDR_UP:
proto_tree_add_item(ehdr_tree, hf_docsis_ehdr_phsi, tvb, pos+1, 1, ENC_BIG_ENDIAN);
if (len == 2)
{
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_qind, tvb, pos+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_grants, tvb, pos+2, 1, ENC_BIG_ENDIAN);
}
break;
case EH_BP_UP2:
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_bpup2_key_seq, tvb, pos + 1, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_bpup2_ver, tvb, pos + 1, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_bpup2_bpi_en, tvb, pos + 2, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_bpup2_toggle_bit, tvb, pos + 2,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_bpup2_sid, tvb, pos + 2, 2,
ENC_BIG_ENDIAN);
break;
case EH_DS_SERVICE:
proto_tree_add_item(ehdr_tree, hf_docsis_ehdr_ds_traffic_pri, tvb, pos+1, 1, ENC_BIG_ENDIAN);
if (len == 3)
{
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_ds_dsid, tvb, pos+1, 3, ENC_BIG_ENDIAN);
}
if (len == 5)
{
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_ds_seq_chg_cnt, tvb, pos+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_ds_dsid, tvb, pos+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_ds_pkt_seq_num, tvb, pos+4, 2, ENC_BIG_ENDIAN);
}
break;
case EH_PATH_VERIFY:
if (len == 5)
{
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_pv_st_refpt, tvb, pos+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (ehdr_tree, hf_docsis_ehdr_pv_timestamp, tvb, pos+2, 4, ENC_BIG_ENDIAN);
}
break;
case EH_EXTENDED:
{
tvbuff_t *subset = tvb_new_subset_remaining(tvb, pos);
dissect_ehdr (subset, ehdr_tree, pinfo);
}
break;
default:
if (len > 0)
proto_tree_add_item (ehdr_tree, hf_docsis_eh_val, tvb, pos + 1,
len, ENC_NA);
}
pos += len + 1;
}
return;
}
static void
dissect_hcs_field (tvbuff_t * tvb, packet_info * pinfo, proto_tree * docsis_tree, gint hdrlen)
{
if(docsis_check_fcs){
guint16 fcs = g_ntohs(crc16_ccitt_tvb(tvb, (hdrlen - 2)));
proto_tree_add_checksum(docsis_tree, tvb, (hdrlen - 2), hf_docsis_hcs, hf_docsis_hcs_status, &ei_docsis_hcs_bad, pinfo, fcs, ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
else
{
proto_tree_add_checksum(docsis_tree, tvb, (hdrlen - 2), hf_docsis_hcs, hf_docsis_hcs_status, &ei_docsis_hcs_bad, pinfo, 0, ENC_BIG_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
}
return;
}
static void
dissect_exthdr_length_field (tvbuff_t * tvb, packet_info * pinfo, proto_tree * docsis_tree, guint8 exthdr, guint16 mac_parm, guint16 len_sid, guint16 *payload_length)
{
proto_item *length_item;
if (exthdr == EXT_HDR_ON)
{
proto_tree_add_item (docsis_tree, hf_docsis_ehdrlen, tvb, 1, 1, ENC_BIG_ENDIAN);
length_item = proto_tree_add_item (docsis_tree, hf_docsis_len, tvb, 2, 2, ENC_BIG_ENDIAN);
if ((len_sid - mac_parm) > *payload_length)
{
*payload_length = len_sid;
expert_add_info(pinfo, length_item, &ei_docsis_len);
}
dissect_ehdr (tvb, docsis_tree, pinfo);
}
else
{
proto_tree_add_item (docsis_tree, hf_docsis_macparm, tvb, 1, 1, ENC_BIG_ENDIAN);
length_item = proto_tree_add_item (docsis_tree, hf_docsis_len, tvb, 2, 2, ENC_BIG_ENDIAN);
if (len_sid > *payload_length)
{
*payload_length = len_sid;
expert_add_info(pinfo, length_item, &ei_docsis_len);
}
}
return;
}
static int
dissect_docsis (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
guint8 fc = 0;
guint8 fctype = 0;
guint8 fcparm = 0;
guint8 exthdr = 0;
guint16 mac_parm = 0;
guint8 hdrlen = DOCSIS_MIN_HEADER_LEN;
guint16 len_sid = 0;
tvbuff_t *next_tvb = NULL;
tvbuff_t *mgt_tvb = NULL;
gint pdulen = 0;
guint16 payload_length = 0;
guint16 framelen = 0;
gboolean save_fragmented;
proto_item *ti;
proto_tree *docsis_tree;
static guint16 concatlen;
static guint16 concatpos;
fc = tvb_get_guint8 (tvb, 0);
fctype = (fc >> 6) & 0x03;
fcparm = (fc >> 1) & 0x1F;
exthdr = (fc & 0x01);
if (fcparm == FCPARM_QUEUE_DEPTH_REQ_FRM) {
mac_parm = tvb_get_ntohs (tvb, 1);
len_sid = tvb_get_ntohs (tvb, 3);
hdrlen = DOCSIS_MIN_HEADER_LEN + 1;
} else {
mac_parm = tvb_get_guint8 (tvb, 1);
len_sid = tvb_get_ntohs (tvb, 2);
}
if (exthdr == EXT_HDR_ON) {
hdrlen += mac_parm;
}
payload_length = tvb_captured_length_remaining (tvb, hdrlen);
if ((fctype == FCTYPE_MACSPC) && (fcparm == FCPARM_RQST_FRM || fcparm == FCPARM_QUEUE_DEPTH_REQ_FRM))
{
pdulen = 0;
if (fcparm == FCPARM_QUEUE_DEPTH_REQ_FRM)
framelen = DOCSIS_MIN_HEADER_LEN + 1;
else
framelen = DOCSIS_MIN_HEADER_LEN;
} else {
framelen = DOCSIS_MIN_HEADER_LEN + len_sid;
pdulen = len_sid - (mac_parm + 2);
}
col_set_str (pinfo->cinfo, COL_PROTOCOL, "DOCSIS");
switch (fctype)
{
case FCTYPE_PACKET:
col_set_str (pinfo->cinfo, COL_INFO, "Packet PDU");
break;
case FCTYPE_RESERVED:
col_set_str (pinfo->cinfo, COL_INFO, "Reserved PDU");
break;
case FCTYPE_ISOLAT:
col_set_str (pinfo->cinfo, COL_INFO, "Isolation PDU");
break;
case FCTYPE_MACSPC:
if (fcparm == FCPARM_RQST_FRM)
col_add_fstr (pinfo->cinfo, COL_INFO,
"Request Frame SID = %u Mini Slots = %u", len_sid,
mac_parm);
else if (fcparm == FCPARM_QUEUE_DEPTH_REQ_FRM)
col_add_fstr (pinfo->cinfo, COL_INFO,
"Request Frame SID = %u Bytes Requested = %u", len_sid,
mac_parm);
else if (fcparm == FCPARM_FRAG_HDR)
col_set_str (pinfo->cinfo, COL_INFO, "Fragmented Frame");
else
col_set_str (pinfo->cinfo, COL_INFO, "Mac Specific");
break;
}
ti = proto_tree_add_item(tree, proto_docsis, tvb, 0, hdrlen, ENC_NA);
docsis_tree = proto_item_add_subtree (ti, ett_docsis);
proto_tree_add_item (docsis_tree, hf_docsis_fctype, tvb, 0, 1, ENC_BIG_ENDIAN);
switch (fctype)
{
case FCTYPE_PACKET:
{
proto_item_append_text (ti, " Packet PDU");
proto_tree_add_item (docsis_tree, hf_docsis_fcparm, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (docsis_tree, hf_docsis_exthdr, tvb, 0, 1, ENC_BIG_ENDIAN);
dissect_exthdr_length_field (tvb, pinfo, docsis_tree, exthdr, mac_parm, len_sid, &payload_length);
dissect_hcs_field (tvb, pinfo, docsis_tree, hdrlen);
if (pdulen > 0)
{
next_tvb = tvb_new_subset_remaining(tvb, hdrlen);
call_dissector (eth_withoutfcs_handle, next_tvb, pinfo, docsis_tree);
}
if (concatlen > 0)
{
concatlen = concatlen - framelen;
concatpos += framelen;
}
break;
}
case FCTYPE_RESERVED:
{
proto_item_append_text (ti, " Reserved PDU");
proto_tree_add_item (docsis_tree, hf_docsis_fcparm, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (docsis_tree, hf_docsis_exthdr, tvb, 0, 1, ENC_BIG_ENDIAN);
dissect_exthdr_length_field (tvb, pinfo, docsis_tree, exthdr, mac_parm, len_sid, &payload_length);
dissect_hcs_field (tvb, pinfo, docsis_tree, hdrlen);
if (concatlen > 0)
{
concatlen = concatlen - framelen;
concatpos += framelen;
}
next_tvb = tvb_new_subset_remaining(tvb, hdrlen);
call_data_dissector(next_tvb, pinfo, tree);
break;
}
case FCTYPE_ISOLAT:
{
proto_item_append_text (ti, " Isolation PDU");
proto_tree_add_item (docsis_tree, hf_docsis_fcparm, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (docsis_tree, hf_docsis_exthdr, tvb, 0, 1, ENC_BIG_ENDIAN);
dissect_exthdr_length_field (tvb, pinfo, docsis_tree, exthdr, mac_parm, len_sid, &payload_length);
dissect_hcs_field (tvb, pinfo, docsis_tree, hdrlen);
if (pdulen > 0)
{
next_tvb = tvb_new_subset_remaining(tvb, hdrlen);
call_dissector (eth_withoutfcs_handle, next_tvb, pinfo, docsis_tree);
}
if (concatlen > 0)
{
concatlen = concatlen - framelen;
concatpos += framelen;
}
break;
}
case FCTYPE_MACSPC:
{
proto_item_append_text (ti, " MAC-Specific PDU");
proto_tree_add_item (docsis_tree, hf_docsis_machdr_fcparm, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (docsis_tree, hf_docsis_exthdr, tvb, 0, 1, ENC_BIG_ENDIAN);
switch(fcparm)
{
case FCPARM_TIMING_HDR:
case FCPARM_MAC_MGMT_HDR:
{
dissect_exthdr_length_field (tvb, pinfo, docsis_tree, exthdr, mac_parm, len_sid, &payload_length);
dissect_hcs_field (tvb, pinfo, docsis_tree, hdrlen);
mgt_tvb = tvb_new_subset_remaining(tvb, hdrlen);
call_dissector (docsis_mgmt_handle, mgt_tvb, pinfo, docsis_tree);
break;
}
case FCPARM_RQST_FRM:
{
proto_tree_add_uint (docsis_tree, hf_docsis_mini_slots, tvb, 1, 1, mac_parm);
proto_tree_add_uint (docsis_tree, hf_docsis_sid, tvb, 2, 2, len_sid);
dissect_hcs_field (tvb, pinfo, docsis_tree, hdrlen);
if (concatlen > 0)
{
concatlen = concatlen - framelen;
concatpos += framelen;
}
break;
}
case FCPARM_FRAG_HDR:
{
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
dissect_exthdr_length_field (tvb, pinfo, docsis_tree, exthdr, mac_parm, len_sid, &payload_length);
dissect_hcs_field (tvb, pinfo, docsis_tree, hdrlen);
guint32 sent_fcs = tvb_get_ntohl(tvb, (hdrlen + len_sid - 4));
guint32 fcs = crc32_802_tvb(tvb, tvb_captured_length(tvb) - 4);
if (sent_fcs == fcs)
{
fragment_item *frag_msg = NULL;
frag_msg = fragment_add_seq_check(&docsis_reassembly_table,
tvb, hdrlen, pinfo,
frag_sid, NULL,
frag_seq,
(len_sid - 4),
!(frag_flags & FRAG_LAST));
next_tvb = process_reassembled_data(tvb, hdrlen, pinfo,
"Reassembled Message", frag_msg, &docsis_frag_items,
NULL, docsis_tree);
if (frag_flags == FRAG_LAST)
pinfo->fragmented = FALSE;
else
pinfo->fragmented = TRUE;
if (frag_msg) {
proto_item_append_text (ti, " (Message Reassembled)");
} else {
proto_item_append_text (ti, " (Message fragment %u)", frag_seq);
}
if(next_tvb)
{
call_dissector (eth_withoutfcs_handle, next_tvb, pinfo, docsis_tree);
} else {
tvbuff_t *payload_tvb = tvb_new_subset_length_caplen(tvb, hdrlen, (len_sid - 4), -1);
call_data_dissector(payload_tvb, pinfo, docsis_tree);
}
} else {
expert_add_info(pinfo, ti, &ei_docsis_frag_fcs_bad);
}
proto_tree_add_checksum(docsis_tree, tvb, (hdrlen + len_sid - 4), hf_docsis_frag_fcs, hf_docsis_frag_fcs_status, &ei_docsis_frag_fcs_bad, pinfo, fcs, ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
pinfo->fragmented = save_fragmented;
break;
}
case FCPARM_QUEUE_DEPTH_REQ_FRM:
{
proto_tree_add_uint (docsis_tree, hf_docsis_requested_size, tvb, 1, 2, mac_parm);
proto_tree_add_uint (docsis_tree, hf_docsis_sid, tvb, 3, 2, len_sid);
dissect_hcs_field (tvb, pinfo, docsis_tree, hdrlen);
if (concatlen > 0)
{
concatlen = concatlen - framelen;
concatpos += framelen;
}
break;
}
case FCPARM_CONCAT_HDR:
{
proto_item_append_text (ti, " (Concatenated Header)");
proto_tree_add_item (docsis_tree, hf_docsis_concat_cnt, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (docsis_tree, hf_docsis_len, tvb, 2, 2, ENC_BIG_ENDIAN);
dissect_hcs_field (tvb, pinfo, docsis_tree, hdrlen);
concatlen = len_sid;
concatpos = DOCSIS_MIN_HEADER_LEN;
while (concatlen > 0)
{
next_tvb = tvb_new_subset_length_caplen (tvb, concatpos, -1, concatlen);
call_dissector (docsis_handle, next_tvb, pinfo, docsis_tree);
}
concatlen = 0;
concatpos = 0;
break;
}
default:
concatlen = 0;
break;
}
break;
}
}
return tvb_captured_length(tvb);
}
void
proto_register_docsis (void)
{
static hf_register_info hf[] = {
{&hf_docsis_fctype,
{"FCType", "docsis.fctype",
FT_UINT8, BASE_HEX, VALS (fctype_vals), 0xC0,
"Frame Control Type", HFILL}
},
{&hf_docsis_fcparm,
{"FCParm", "docsis.fcparm",
FT_UINT8, BASE_DEC, VALS (pkt_fcparm_vals), 0x3E,
"Parameter Field", HFILL}
},
{&hf_docsis_machdr_fcparm,
{"FCParm", "docsis.fcparm",
FT_UINT8, BASE_DEC, VALS (ms_fcparm_vals), 0x3E,
"Parameter Field", HFILL}
},
{&hf_docsis_exthdr,
{"EXTHDR", "docsis.exthdr",
FT_BOOLEAN, 8, TFS (&exthdr_tfs), 0x01,
"Extended Header Presence", HFILL}
},
{&hf_docsis_macparm,
{"MacParm", "docsis.macparm",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Mac Parameter Field", HFILL}
},
{&hf_docsis_concat_cnt,
{"Number of Concatenated Frames", "docsis.concat_cnt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ehdrlen,
{"Extended Header Length (bytes)", "docsis.ehdrlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_len,
{"Length of the MAC frame (bytes)", "docsis.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of the MAC frame, not counting the fixed-length MAC header", HFILL}
},
{&hf_docsis_eh_type,
{"Type", "docsis.ehdr.type",
FT_UINT8, BASE_DEC, VALS (eh_type_vals), 0xF0,
"TLV Type", HFILL}
},
{&hf_docsis_eh_len,
{"Length", "docsis.ehdr.len",
FT_UINT8, BASE_DEC, NULL, 0x0F,
"TLV Len", HFILL}
},
{&hf_docsis_eh_val,
{"Value", "docsis.ehdr.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"TLV Value", HFILL}
},
{&hf_docsis_frag_rsvd,
{"Reserved", "docsis.frag_rsvd",
FT_UINT8, BASE_DEC, NULL, 0xC0,
NULL, HFILL}
},
{&hf_docsis_frag_first,
{"First Frame", "docsis.frag_first",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL}
},
{&hf_docsis_frag_last,
{"Last Frame", "docsis.frag_last",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL}
},
{&hf_docsis_frag_seq,
{"Fragmentation Sequence #", "docsis.frag_seq",
FT_UINT8, BASE_DEC, NULL, 0x0F,
"Fragmentation Sequence Number", HFILL}
},
{&hf_docsis_sid,
{"SID", "docsis.ehdr.sid",
FT_UINT16, BASE_DEC_HEX, NULL, 0x3FFF,
"Service Identifier", HFILL}
},
{&hf_docsis_said,
{"SAID", "docsis.ehdr.said",
FT_UINT16, BASE_DEC, NULL, 0x3FFF,
"Security Association Identifier", HFILL}
},
{&hf_docsis_reserved,
{"Reserved", "docsis.ehdr.rsvd",
FT_UINT8, BASE_HEX, NULL, 0x3FFF,
"Reserved Byte", HFILL}
},
{&hf_docsis_mini_slots,
{"MiniSlots", "docsis.ehdr.minislots",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Mini Slots Requested", HFILL}
},
{&hf_docsis_requested_size,
{"Bytes Requested", "docsis.ehdr.reqsize",
FT_UINT16, BASE_DEC, NULL, 0xFFFF,
NULL, HFILL}
},
{&hf_docsis_key_seq,
{"Key Sequence", "docsis.ehdr.keyseq",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL}
},
{&hf_docsis_ehdr_ver,
{"Version", "docsis.ehdr.ver",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL}
},
{&hf_docsis_ehdr_phsi,
{"Payload Header Suppression Index", "docsis.ehdr.phsi",
FT_UINT8, BASE_DEC|BASE_SPECIAL_VALS, VALS(unique_no_phs), 0x0,
NULL, HFILL}
},
{&hf_docsis_ehdr_qind,
{"Queue Indicator", "docsis.ehdr.qind",
FT_BOOLEAN, 8, TFS(&qind_tfs), 0x80,
NULL, HFILL}
},
{&hf_docsis_ehdr_grants,
{"Active Grants", "docsis.ehdr.act_grants",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL}
},
{&hf_docsis_ehdr_bpup2_key_seq,
{"Key Sequence", "docsis.ehdr.bpup2_keyseq",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL}
},
{&hf_docsis_ehdr_bpup2_ver,
{"Version", "docsis.ehdr.bpup2_ver",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL}
},
{&hf_docsis_ehdr_bpup2_bpi_en,
{"Encryption", "docsis.ehdr.bpup2_bpi_en",
FT_BOOLEAN, 8, TFS (&ena_dis_tfs), 0x80,
"BPI Enable", HFILL}
},
{&hf_docsis_ehdr_bpup2_toggle_bit,
{"Toggle", "docsis.ehdr.bpup2_toggle_bit",
FT_BOOLEAN, 8, TFS (&odd_even_tfs), 0x40,
NULL, HFILL}
},
{&hf_docsis_ehdr_bpup2_sid,
{"SID", "docsis.ehdr.bpup2_sid",
FT_UINT16, BASE_DEC, NULL, 0x3FFF,
"Service Identifier", HFILL}
},
{ &hf_docsis_ehdr_pv_st_refpt,
{ "Start Reference Point", "docsis.ehdr.pv_start_ref",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_docsis_ehdr_pv_timestamp,
{ "Timestamp", "docsis.ehdr.pv_timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_ehdr_ds_traffic_pri,
{"DS Traffic Priority", "docsis.ehdr.ds_traffic_pri",
FT_UINT8, BASE_DEC, NULL, 0xE0,
NULL, HFILL}
},
{&hf_docsis_ehdr_ds_seq_chg_cnt,
{"DS Sequence Change Count", "docsis.ehdr.ds_seq_chg_cnt",
FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL}
},
{&hf_docsis_ehdr_ds_dsid,
{"DS DSID", "docsis.ehdr.ds_dsid",
FT_UINT32, BASE_DEC, NULL, 0x0FFFFF,
NULL, HFILL}
},
{&hf_docsis_ehdr_ds_pkt_seq_num,
{"DS Packet Sequence Number", "docsis.ehdr.ds_pkt_seq_num",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_hcs,
{"Header check sequence", "docsis.hcs",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_docsis_hcs_status,
{ "HCS Status", "docsis.hcs.status",
FT_UINT8, BASE_NONE, VALS(local_proto_checksum_vals), 0x0,
NULL, HFILL}
},
{ &hf_docsis_bpi_en,
{ "Encryption", "docsis.bpi_en",
FT_BOOLEAN, 8, TFS (&ena_dis_tfs), 0x80,
"BPI Enable", HFILL}
},
{ &hf_docsis_toggle_bit,
{ "Toggle", "docsis.toggle_bit",
FT_BOOLEAN, 8, TFS (&odd_even_tfs), 0x40,
NULL, HFILL}
},
{ &hf_docsis_fragment_overlap,
{ "Fragment overlap", "docsis.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL}
},
{ &hf_docsis_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "docsis.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL}
},
{ &hf_docsis_fragment_multiple_tails,
{ "Multiple tail fragments found", "docsis.fragment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL}
},
{ &hf_docsis_fragment_too_long_fragment,
{ "Fragment too long", "docsis.fragment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL}
},
{ &hf_docsis_fragment_error,
{ "Defragmentation error", "docsis.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL}
},
{ &hf_docsis_fragment_count,
{ "Fragment count", "docsis.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_docsis_fragment,
{ "DOCSIS Fragment", "docsis.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_docsis_fragments,
{ "DOCSIS Fragments", "docsis.fragments",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_docsis_reassembled_in,
{ "Reassembled DOCSIS in frame", "docsis.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This DOCSIS packet is reassembled in this frame", HFILL}
},
{ &hf_docsis_reassembled_length,
{ "Reassembled DOCSIS length", "docsis.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL}
},
{ &hf_docsis_reassembled_data,
{ "Reassembled DOCSIS data", "docsis.reassembled.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"The reassembled payload", HFILL}
},
{ &hf_docsis_frag_fcs,
{ "Fragment FCS", "docsis.frag.fcs",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_docsis_frag_fcs_status,
{ "Fragment FCS Status", "docsis.frag.fcs.status",
FT_UINT8, BASE_NONE, VALS(local_proto_checksum_vals), 0x0,
NULL, HFILL}
}
};
static ei_register_info ei[] = {
{ &ei_docsis_hcs_bad, { "docsis.hcs_bad", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
{ &ei_docsis_len, { "docsis.len.past_end", PI_MALFORMED, PI_ERROR, "Length field value goes past the end of the payload", EXPFILL }},
{ &ei_docsis_frag_fcs_bad, { "docsis.frag.fcs_bad", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
{ &ei_docsis_eh_len, { "docsis.ehdr.len.past_end", PI_MALFORMED, PI_ERROR, "Extended Header Length Invalid!", EXPFILL }}
};
static gint *ett[] = {
&ett_docsis,
&ett_ehdr,
&ett_docsis_fragment,
&ett_docsis_fragments
};
module_t *docsis_module;
expert_module_t* expert_docsis;
proto_docsis = proto_register_protocol ("DOCSIS", "DOCSIS", "docsis");
proto_register_field_array (proto_docsis, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_docsis = expert_register_protocol(proto_docsis);
expert_register_field_array(expert_docsis, ei, array_length(ei));
docsis_module = prefs_register_protocol(proto_docsis, NULL);
prefs_register_bool_preference(docsis_module, "check_fcs",
"Validate the DOCSIS checksum if possible",
"Whether or not to validate the Header Check Sequence",
&docsis_check_fcs);
#if 0
docsis_dissector_table = register_dissector_table ("docsis",
"DOCSIS Encapsulation Type", proto_docsis,
FT_UINT8, BASE_DEC);
#endif
docsis_handle = register_dissector ("docsis", dissect_docsis, proto_docsis);
reassembly_table_register(&docsis_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_reg_handoff_docsis (void)
{
dissector_add_uint ("wtap_encap", WTAP_ENCAP_DOCSIS, docsis_handle);
docsis_mgmt_handle = find_dissector ("docsis_mgmt");
eth_withoutfcs_handle = find_dissector_add_dependency("eth_withoutfcs", proto_docsis);
}
