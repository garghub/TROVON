static void
wtp_defragment_init(void)
{
reassembly_table_init(&wtp_reassembly_table,
&addresses_reassembly_table_functions);
}
static char retransmission_indicator(unsigned char octet)
{
switch (pdu_type(octet)) {
case INVOKE:
case RESULT:
case ACK:
case SEGMENTED_INVOKE:
case SEGMENTED_RESULT:
case NEGATIVE_ACK:
return octet & 0x01;
default:
return 0;
}
}
static void
wtp_handle_tpi(proto_tree *tree, tvbuff_t *tvb)
{
int offset = 0;
unsigned char tByte;
unsigned char tType;
unsigned char tLen;
proto_tree *subTree = NULL;
proto_item *pi;
tByte = tvb_get_guint8(tvb, offset++);
tType = (tByte & 0x78) >> 3;
if (tByte & 0x04)
tLen = tvb_get_guint8(tvb, offset++);
else
tLen = tByte & 0x03;
pi = proto_tree_add_uint(tree, hf_wtp_tpi_type,
tvb, 0, tvb_length(tvb), tType);
subTree = proto_item_add_subtree(pi, ett_tpilist);
switch (tType) {
case 0x00:
break;
case 0x01:
proto_tree_add_item(subTree, hf_wtp_tpi_info,
tvb, offset, tLen, ENC_NA);
break;
case 0x02:
proto_tree_add_item(subTree, hf_wtp_tpi_opt,
tvb, offset++, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subTree, hf_wtp_tpi_optval,
tvb, offset, tLen - 1, ENC_NA);
break;
case 0x03:
proto_tree_add_item(subTree, hf_wtp_tpi_psn,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case 0x04:
break;
case 0x05:
break;
default:
break;
}
}
static void
dissect_wtp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
char *szInfo;
int offCur = 0;
gint returned_length, str_index = 0;
unsigned char b0;
unsigned char fCon;
unsigned char fRID;
unsigned char fTTR = '\0';
guint cbHeader = 0;
guint vHeader = 0;
int abortType = 0;
proto_item *ti = NULL;
proto_tree *wtp_tree = NULL;
char pdut;
char clsTransaction = 3;
int numMissing = 0;
int i;
tvbuff_t *wsp_tvb = NULL;
guint8 psn = 0;
guint16 TID = 0;
int dataOffset;
gint dataLen;
#define SZINFO_SIZE 256
szInfo=(char *)ep_alloc(SZINFO_SIZE);
b0 = tvb_get_guint8 (tvb, offCur + 0);
if (b0 == 0) {
guint c_fieldlen = 0;
guint c_pdulen = 0;
if (tree) {
ti = proto_tree_add_item(tree, proto_wtp,
tvb, offCur, 1, ENC_NA);
wtp_tree = proto_item_add_subtree(ti, ett_wtp_sub_pdu_tree);
proto_item_append_text(ti, ", PDU concatenation");
}
offCur = 1;
i = 1;
while (offCur < (int) tvb_reported_length(tvb)) {
tvbuff_t *wtp_tvb;
b0 = tvb_get_guint8(tvb, offCur + 0);
if (b0 & 0x80) {
c_fieldlen = 2;
c_pdulen = ((b0 & 0x7f) << 8) | tvb_get_guint8(tvb, offCur + 1);
} else {
c_fieldlen = 1;
c_pdulen = b0;
}
if (tree) {
proto_tree_add_uint(wtp_tree, hf_wtp_header_sub_pdu_size,
tvb, offCur, c_fieldlen, c_pdulen);
}
if (i > 1) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
wtp_tvb = tvb_new_subset(tvb, offCur + c_fieldlen, c_pdulen, c_pdulen);
dissect_wtp_common(wtp_tvb, pinfo, wtp_tree);
offCur += c_fieldlen + c_pdulen;
i++;
}
if (tree) {
proto_item_append_text(ti, ", PDU count: %u", i);
}
return;
}
fCon = b0 & 0x80;
fRID = retransmission_indicator(b0);
pdut = pdu_type(b0);
#ifdef DEBUG
printf("WTP packet %u: tree = %p, pdu = %s (%u) length: %u\n",
pinfo->fd->num, tree,
val_to_str(pdut, vals_wtp_pdu_type, "Unknown PDU type 0x%x"),
pdut, tvb_length(tvb));
#endif
returned_length = g_snprintf(szInfo, SZINFO_SIZE, "WTP %s",
val_to_str(pdut, vals_wtp_pdu_type, "Unknown PDU type 0x%x"));
str_index += MIN(returned_length, SZINFO_SIZE-str_index);
switch (pdut) {
case INVOKE:
fTTR = transmission_trailer(b0);
TID = tvb_get_ntohs(tvb, offCur + 1);
psn = 0;
clsTransaction = transaction_class(tvb_get_guint8(tvb, offCur + 3));
returned_length = g_snprintf(&szInfo[str_index], SZINFO_SIZE-str_index,
" Class %d", clsTransaction);
str_index += MIN(returned_length, SZINFO_SIZE-str_index);
cbHeader = 4;
break;
case SEGMENTED_INVOKE:
case SEGMENTED_RESULT:
fTTR = transmission_trailer(b0);
TID = tvb_get_ntohs(tvb, offCur + 1);
psn = tvb_get_guint8(tvb, offCur + 3);
if (psn != 0) {
returned_length = g_snprintf(&szInfo[str_index], SZINFO_SIZE-str_index,
" (%u)", psn);
str_index += MIN(returned_length, SZINFO_SIZE-str_index);
}
cbHeader = 4;
break;
case ABORT:
cbHeader = 4;
break;
case RESULT:
fTTR = transmission_trailer(b0);
TID = tvb_get_ntohs(tvb, offCur + 1);
psn = 0;
cbHeader = 3;
break;
case ACK:
cbHeader = 3;
break;
case NEGATIVE_ACK:
numMissing = tvb_get_guint8(tvb, offCur + 3);
cbHeader = numMissing + 4;
break;
default:
break;
};
if (fRID) {
g_snprintf(&szInfo[str_index], SZINFO_SIZE-str_index, " R" );
};
if (tree) {
#ifdef DEBUG
fprintf(stderr, "dissect_wtp: cbHeader = %d\n", cbHeader);
#endif
ti = proto_tree_add_item(tree, proto_wtp, tvb, offCur, 0, ENC_NA);
#ifdef DEBUG
fprintf(stderr, "dissect_wtp: (7) Returned from proto_tree_add_item\n");
#endif
wtp_tree = proto_item_add_subtree(ti, ett_wtp);
#ifdef DEBUG
fprintf(stderr, "dissect_wtp: cbHeader = %d\n", cbHeader);
fprintf(stderr, "dissect_wtp: offCur = %d\n", offCur);
#endif
proto_tree_add_item(
wtp_tree,
hf_wtp_header_flag_continue,
tvb,
offCur,
1,
b0
);
proto_tree_add_item(wtp_tree, hf_wtp_header_pdu_type, tvb, offCur, 1, ENC_LITTLE_ENDIAN);
switch(pdut) {
case INVOKE:
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_Trailer, tvb, offCur, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_RID, tvb, offCur, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID_response, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_Inv_version , tvb, offCur + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_Inv_flag_TIDNew, tvb, offCur + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_Inv_flag_UP, tvb, offCur + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_Inv_Reserved, tvb, offCur + 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_Inv_TransactionClass, tvb, offCur + 3, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti,
", PDU: Invoke (%u)"
", Transaction Class: %s (%u)",
INVOKE,
val_to_str_const(clsTransaction, vals_transaction_classes, "Undefined"),
clsTransaction);
break;
case RESULT:
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_Trailer, tvb, offCur, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_RID, tvb, offCur, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID_response, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", PDU: Result (%u)", RESULT);
break;
case ACK:
proto_tree_add_item(wtp_tree, hf_wtp_header_Ack_flag_TVETOK, tvb, offCur, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_RID, tvb, offCur, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID_response, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", PDU: ACK (%u)", ACK);
break;
case ABORT:
abortType = tvb_get_guint8 (tvb, offCur) & 0x07;
proto_tree_add_item(wtp_tree, hf_wtp_header_Abort_type , tvb, offCur , 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID_response, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
if (abortType == PROVIDER) {
guint8 reason = tvb_get_guint8(tvb, offCur + 3);
proto_tree_add_item( wtp_tree, hf_wtp_header_Abort_reason_provider , tvb, offCur + 3 , 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti,
", PDU: Abort (%u)"
", Type: Provider (%u)"
", Reason: %s (%u)",
ABORT,
PROVIDER,
val_to_str_const(reason, vals_abort_reason_provider, "Undefined"),
reason);
}
else if (abortType == USER) {
guint8 reason = tvb_get_guint8(tvb, offCur + 3);
proto_tree_add_item(wtp_tree, hf_wtp_header_Abort_reason_user , tvb, offCur + 3 , 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti,
", PDU: Abort (%u)"
", Type: User (%u)"
", Reason: %s (%u)",
ABORT,
PROVIDER,
val_to_str_ext_const(reason, &vals_wsp_reason_codes_ext, "Undefined"),
reason);
}
break;
case SEGMENTED_INVOKE:
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_Trailer, tvb, offCur, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_RID, tvb, offCur, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID_response, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_sequence_number , tvb, offCur + 3, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti,
", PDU: Segmented Invoke (%u)"
", Packet Sequence Number: %u",
SEGMENTED_INVOKE, psn);
break;
case SEGMENTED_RESULT:
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_Trailer, tvb, offCur, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_RID, tvb, offCur, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID_response, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_sequence_number , tvb, offCur + 3, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti,
", PDU: Segmented Result (%u)"
", Packet Sequence Number: %u",
SEGMENTED_RESULT, psn);
break;
case NEGATIVE_ACK:
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_RID, tvb, offCur, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID_response, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_flag_TID, tvb, offCur + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(wtp_tree, hf_wtp_header_missing_packets , tvb, offCur + 3, 1, ENC_LITTLE_ENDIAN);
for (i = 0; i < numMissing; i++)
{
proto_tree_add_item(wtp_tree, hf_wtp_header_sequence_number, tvb, offCur + 4 + i, 1, ENC_LITTLE_ENDIAN);
}
proto_item_append_text(ti,
", PDU: Negative Ack (%u)"
", Missing Packets: %u",
NEGATIVE_ACK, numMissing);
break;
default:
break;
};
if (fRID) {
proto_item_append_text(ti, ", Retransmission");
}
} else {
#ifdef DEBUG
fprintf(stderr, "dissect_wtp: (4) tree was %p\n", tree);
#endif
}
if (fCon) {
guint8 tCon;
guint8 tByte;
guint tpiLen;
tvbuff_t *tmp_tvb;
vHeader = 0;
do {
tByte = tvb_get_guint8(tvb, offCur + cbHeader + vHeader);
tCon = tByte & 0x80;
if (tByte & 0x04)
tpiLen = 2 + tvb_get_guint8(tvb, offCur + cbHeader + vHeader + 1);
else
tpiLen = 1 + (tByte & 0x03);
if (tree)
{
tmp_tvb = tvb_new_subset(tvb, offCur + cbHeader + vHeader, tpiLen, tpiLen);
wtp_handle_tpi(wtp_tree, tmp_tvb);
}
vHeader += tpiLen;
} while (tCon);
} else {
}
if (tree)
proto_item_set_len(ti, cbHeader + vHeader);
#ifdef DEBUG
fprintf( stderr, "dissect_wtp: cbHeader = %d\n", cbHeader );
#endif
dataOffset = offCur + cbHeader + vHeader;
dataLen = tvb_reported_length_remaining(tvb, dataOffset);
if ((dataLen >= 0) &&
! ((pdut==ACK) || (pdut==NEGATIVE_ACK) || (pdut==ABORT)))
{
if ( ( (pdut == SEGMENTED_INVOKE) || (pdut == SEGMENTED_RESULT)
|| ( ((pdut == INVOKE) || (pdut == RESULT)) && (!fTTR) )
) && tvb_bytes_exist(tvb, dataOffset, dataLen) )
{
fragment_data *fd_wtp = NULL;
guint32 reassembled_in = 0;
gboolean save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
fd_wtp = fragment_add_seq(&wtp_reassembly_table, tvb, dataOffset,
pinfo, TID, NULL, psn, dataLen, !fTTR, 0);
wsp_tvb = process_reassembled_data(tvb, dataOffset, pinfo,
"Reassembled WTP", fd_wtp, &wtp_frag_items,
NULL, wtp_tree);
#ifdef DEBUG
printf("WTP: Packet %u %s -> %d: wsp_tvb = %p, fd_wtp = %p, frame = %u\n",
pinfo->fd->num,
fd_wtp ? "Reassembled" : "Not reassembled",
fd_wtp ? fd_wtp->reassembled_in : -1,
wsp_tvb,
fd_wtp
);
#endif
if (fd_wtp) {
reassembled_in = fd_wtp->reassembled_in;
if (pinfo->fd->num == reassembled_in) {
call_dissector(wsp_handle, wsp_tvb, pinfo, tree);
} else {
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO,
"%s (WTP payload reassembled in packet %u)",
szInfo, fd_wtp->reassembled_in);
}
if (tree) {
proto_tree_add_text(wtp_tree, tvb, dataOffset, -1,
"Payload");
}
}
} else {
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO,
"%s (Unreassembled fragment %u)",
szInfo, psn);
}
if (tree) {
proto_tree_add_text(wtp_tree, tvb, dataOffset, -1,
"Payload");
}
}
pinfo->fragmented = save_fragmented;
}
else if ( ((pdut == INVOKE) || (pdut == RESULT)) && (fTTR) )
{
wsp_tvb = tvb_new_subset_remaining(tvb, dataOffset);
call_dissector(wsp_handle, wsp_tvb, pinfo, tree);
}
else
{
if (check_col(pinfo->cinfo, COL_INFO))
col_append_str(pinfo->cinfo, COL_INFO, szInfo);
}
}
else
{
if (check_col(pinfo->cinfo, COL_INFO))
col_append_str(pinfo->cinfo, COL_INFO, szInfo);
}
}
static void
dissect_wtp_fromudp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WTP+WSP");
col_clear(pinfo->cinfo, COL_INFO);
dissect_wtp_common(tvb, pinfo, tree);
}
static void
dissect_wtp_fromwtls(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WTLS+WTP+WSP");
col_clear(pinfo->cinfo, COL_INFO);
dissect_wtp_common(tvb, pinfo, tree);
}
void
proto_register_wtp(void)
{
static hf_register_info hf[] = {
{ &hf_wtp_header_sub_pdu_size,
{ "Sub PDU size", "wtp.sub_pdu_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Size of Sub-PDU (bytes)", HFILL
}
},
{ &hf_wtp_header_flag_continue,
{ "Continue Flag", "wtp.continue_flag",
FT_BOOLEAN, 8, TFS( &continue_truth ), 0x80,
NULL, HFILL
}
},
{ &hf_wtp_header_pdu_type,
{ "PDU Type", "wtp.pdu_type",
FT_UINT8, BASE_HEX, VALS( vals_wtp_pdu_type ), 0x78,
NULL, HFILL
}
},
{ &hf_wtp_header_flag_Trailer,
{ "Trailer Flags", "wtp.trailer_flags",
FT_UINT8, BASE_HEX, VALS( vals_transaction_trailer ), 0x06,
NULL, HFILL
}
},
{ &hf_wtp_header_flag_RID,
{ "Re-transmission Indicator", "wtp.RID",
FT_BOOLEAN, 8, TFS( &RID_truth ), 0x01,
NULL, HFILL
}
},
{ &hf_wtp_header_flag_TID_response,
{ "TID Response", "wtp.TID.response",
FT_BOOLEAN, 16, TFS( &tid_response_truth ), 0x8000,
NULL, HFILL
}
},
{ &hf_wtp_header_flag_TID,
{ "Transaction ID", "wtp.TID",
FT_UINT16, BASE_HEX, NULL, 0x7FFF,
NULL, HFILL
}
},
{ &hf_wtp_header_Inv_version,
{ "Version", "wtp.header.version",
FT_UINT8, BASE_HEX, VALS( vals_version ), 0xC0,
NULL, HFILL
}
},
{ &hf_wtp_header_Inv_flag_TIDNew,
{ "TIDNew", "wtp.header.TIDNew",
FT_BOOLEAN, 8, TFS( &TIDNew_truth ), 0x20,
NULL, HFILL
}
},
{ &hf_wtp_header_Inv_flag_UP,
{ "U/P flag", "wtp.header.UP",
FT_BOOLEAN, 8, TFS( &UP_truth ), 0x10,
NULL, HFILL
}
},
{ &hf_wtp_header_Inv_Reserved,
{ "Reserved", "wtp.inv.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0C,
NULL, HFILL
}
},
{ &hf_wtp_header_Inv_TransactionClass,
{ "Transaction Class", "wtp.inv.transaction_class",
FT_UINT8, BASE_HEX, VALS( vals_transaction_classes ), 0x03,
NULL, HFILL
}
},
{ &hf_wtp_header_Ack_flag_TVETOK,
{ "Tve/Tok flag", "wtp.ack.tvetok",
FT_BOOLEAN, 8, TFS( &TVETOK_truth ), 0x04,
NULL, HFILL
}
},
{ &hf_wtp_header_Abort_type,
{ "Abort Type", "wtp.abort.type",
FT_UINT8, BASE_HEX, VALS ( vals_abort_type ), 0x07,
NULL, HFILL
}
},
{ &hf_wtp_header_Abort_reason_provider,
{ "Abort Reason", "wtp.abort.reason.provider",
FT_UINT8, BASE_HEX, VALS ( vals_abort_reason_provider ), 0x00,
NULL, HFILL
}
},
{ &hf_wtp_header_Abort_reason_user,
{ "Abort Reason", "wtp.abort.reason.user",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &vals_wsp_reason_codes_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtp_header_sequence_number,
{ "Packet Sequence Number", "wtp.header.sequence",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtp_header_missing_packets,
{ "Missing Packets", "wtp.header.missing_packets",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
#if 0
{ &hf_wtp_header_variable_part,
{ "Header: Variable part", "wtp.header_variable_part",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Variable part of the header", HFILL
}
},
{ &hf_wtp_data,
{ "Data", "wtp.header_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_wtp_tpi_type,
{ "TPI", "wtp.tpi",
FT_UINT8, BASE_HEX, VALS(vals_tpi_type), 0x00,
"Identification of the Transport Information Item", HFILL
}
},
{ &hf_wtp_tpi_psn,
{ "Packet sequence number", "wtp.tpi.psn",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Sequence number of this packet", HFILL
}
},
{ &hf_wtp_tpi_opt,
{ "Option", "wtp.tpi.opt",
FT_UINT8, BASE_HEX, VALS(vals_tpi_opt), 0x00,
"The given option for this TPI", HFILL
}
},
{ &hf_wtp_tpi_optval,
{ "Option Value", "wtp.tpi.opt.val",
FT_NONE, BASE_NONE, NULL, 0x00,
"The value that is supplied with this option", HFILL
}
},
{ &hf_wtp_tpi_info,
{ "Information", "wtp.tpi.info",
FT_NONE, BASE_NONE, NULL, 0x00,
"The information being send by this TPI", HFILL
}
},
{ &hf_wtp_fragment_overlap,
{ "Fragment overlap", "wtp.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL
}
},
{ &hf_wtp_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "wtp.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL
}
},
{ &hf_wtp_fragment_multiple_tails,
{ "Multiple tail fragments found", "wtp.fragment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL
}
},
{ &hf_wtp_fragment_too_long_fragment,
{ "Fragment too long", "wtp.fragment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL
}
},
{ &hf_wtp_fragment_error,
{ "Defragmentation error", "wtp.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL
}
},
{ &hf_wtp_fragment_count,
{ "Fragment count", "wtp.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_wtp_reassembled_in,
{ "Reassembled in", "wtp.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"WTP fragments are reassembled in the given packet", HFILL
}
},
{ &hf_wtp_reassembled_length,
{ "Reassembled WTP length", "wtp.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL
}
},
{ &hf_wtp_fragment,
{ "WTP Fragment", "wtp.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_wtp_fragments,
{ "WTP Fragments", "wtp.fragments",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
};
static gint *ett[] = {
&ett_wtp,
&ett_wtp_sub_pdu_tree,
&ett_header,
&ett_tpilist,
&ett_wsp_fragments,
&ett_wtp_fragment,
};
proto_wtp = proto_register_protocol(
"Wireless Transaction Protocol",
"WTP",
"wtp"
);
proto_register_field_array(proto_wtp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("wtp-wtls", dissect_wtp_fromwtls, proto_wtp);
register_dissector("wtp-udp", dissect_wtp_fromudp, proto_wtp);
register_init_routine(wtp_defragment_init);
}
void
proto_reg_handoff_wtp(void)
{
dissector_handle_t wtp_fromudp_handle;
wsp_handle = find_dissector("wsp-co");
wtp_fromudp_handle = find_dissector("wtp-udp");
dissector_add_uint("udp.port", UDP_PORT_WTP_WSP, wtp_fromudp_handle);
dissector_add_uint("gsm_sms_ud.udh.port", UDP_PORT_WTP_WSP, wtp_fromudp_handle);
dissector_add_uint("gsm_sms.udh.port", UDP_PORT_WTP_WSP, wtp_fromudp_handle);
}
