static CSN_CallBackStatus_t callback_UTRAN_TDD_map_NrOfFrequencies(proto_tree *tree _U_, tvbuff_t *tvb _U_, void* param1, void* param2, int bit_offset _U_, int ett_csn1 _U_)
{
guint8 * pNrOfCells = (guint8*)param1;
guint8 * pBitsInCellInfo = (guint8*)param2;
if ( *pNrOfCells < 32 )
{
*pBitsInCellInfo = NR_OF_TDD_CELLS_map[*pNrOfCells];
}
else
{
*pBitsInCellInfo = 0;
}
return 0;
}
static CSN_CallBackStatus_t callback_UTRAN_TDD_compute_TDD_CELL_INFORMATION(proto_tree *tree, tvbuff_t *tvb, void* param1, void* param2 _U_, int bit_offset, int ett_csn1)
{
proto_tree *subtree;
UTRAN_TDD_NeighbourCells_t *pUtranTddNcell = (UTRAN_TDD_NeighbourCells_t *)param1;
gint xdd_cell_info, wsize, nwi, jwi, w[64], i, iused;
gint curr_bit_offset, idx;
curr_bit_offset = bit_offset;
idx = pUtranTddNcell->BitsInCellInfo;
if ( idx > 0 )
{
subtree = proto_tree_add_subtree(tree, tvb, curr_bit_offset>>3, 1, ett_csn1, NULL, "TDD_CELL_INFORMATION: ");
if (pUtranTddNcell->Indic0)
{
proto_tree_add_uint(tree, hf_gsm_rlcmac_cell_parameter, tvb, curr_bit_offset>>3, 0, 0);
proto_tree_add_uint(tree, hf_gsm_rlcmac_sync_case_tstd, tvb, curr_bit_offset>>3, 0, 0);
proto_tree_add_uint(tree, hf_gsm_rlcmac_diversity_tdd, tvb, curr_bit_offset>>3, 0, 0);
}
if (idx)
{
wsize = 10;
nwi = 1;
jwi = 0;
i = 1;
while (idx > 0)
{
w[i] = tvb_get_bits(tvb, curr_bit_offset, wsize, ENC_BIG_ENDIAN);
curr_bit_offset += wsize;
idx -= wsize;
if (w[i] == 0)
{
idx = 0;
break;
}
if (++jwi==nwi)
{
jwi = 0;
nwi <<= 1;
wsize--;
}
i++;
}
if (idx < 0)
{
curr_bit_offset += idx;
}
iused = i-1;
for (i=1; i <= iused; i++)
{
xdd_cell_info = f_k(i, w, 1024);
proto_tree_add_uint(subtree, hf_gsm_rlcmac_cell_parameter, tvb, curr_bit_offset>>3, 0, xdd_cell_info & 0x007F);
proto_tree_add_uint(subtree, hf_gsm_rlcmac_sync_case_tstd, tvb, curr_bit_offset>>3, 0, (xdd_cell_info >> 7) & 0x01);
proto_tree_add_uint(subtree, hf_gsm_rlcmac_diversity_tdd, tvb, curr_bit_offset>>3, 0, (xdd_cell_info >> 8) & 0x01);
}
}
}
return curr_bit_offset - bit_offset;
}
static gint construct_gprs_data_segment_li_array(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint8 initial_offset, guint8 *li_count, length_indicator_t *li_array, guint64 *e)
{
gint offset = initial_offset;
guint8 li_array_size = *li_count;
proto_item *item;
*li_count = 0;
while (*e == 0)
{
item = proto_tree_add_bits_item(tree, hf_li, tvb, offset * 8, 6, ENC_BIG_ENDIAN);
if (*li_count < li_array_size)
{
li_array[*li_count].li = tvb_get_guint8(tvb, offset);
li_array[*li_count].offset = offset;
(*li_count)++;
}
else
{
expert_add_info(pinfo, item, &ei_li);
}
proto_tree_add_bits_item(tree, hf_me, tvb, (offset * 8) + 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_ret_val(tree, hf_e, tvb, (offset * 8) + 7, 1, e, ENC_BIG_ENDIAN);
offset++;
}
return (offset - initial_offset);
}
static gint construct_egprs_data_segment_li_array(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint8 initial_offset, guint8 *li_count, length_indicator_t *li_array, guint64 *e)
{
gint offset = initial_offset;
guint8 li_array_size = *li_count;
proto_item *item;
*li_count = 0;
while (*e == 0)
{
item = proto_tree_add_bits_item(tree, hf_li, tvb, offset * 8, 7, ENC_BIG_ENDIAN);
proto_tree_add_bits_ret_val(tree, hf_e, tvb, (offset * 8) + 7, 1, e, ENC_BIG_ENDIAN);
if (*li_count < li_array_size)
{
li_array[*li_count].offset = offset;
li_array[*li_count].li = tvb_get_guint8(tvb, offset);
(*li_count)++;
}
else
{
expert_add_info(pinfo, item, &ei_li);
}
offset++;
}
return (offset - initial_offset);
}
static guint8 dissect_gprs_data_segments(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 initial_offset,
guint8 octet_length, guint8 li_count, length_indicator_t *li_array)
{
guint8 octet_offset = initial_offset;
guint8 i;
tvbuff_t* data_tvb = NULL;
gboolean more = TRUE, first_li = TRUE;
proto_tree *subtree = NULL;
for(i = 0; (i < li_count) && more; i++)
{
guint8 li = li_array[i].li >> 2;
more = (li_array[i].li & 2) == 2;
switch (li)
{
case 0:
proto_tree_add_subtree_format(tree, tvb, li_array[i].offset, 1, ett_data_segments, NULL,
"LI[%d]=%d indicates: The previous segment of LLC Frame precisely filled the previous RLC Block",
i, li);
break;
case 63:
if (first_li)
{
subtree = proto_tree_add_subtree_format(tree, tvb, octet_offset, li, ett_data_segments, NULL,
"data segment: LI[%d]=%d indicates: The RLC data block contains only filler bits",
i, li);
}
else
{
subtree = proto_tree_add_subtree_format(tree, tvb, octet_offset, li, ett_data_segments, NULL,
"data segment: LI[%d]=%d indicates: The remainder of the RLC data block contains filler bits",
i, li);
}
data_tvb = tvb_new_subset_length(tvb, octet_offset, octet_length - octet_offset);
call_dissector(data_handle, data_tvb, pinfo, subtree);
octet_offset = octet_length;
break;
default:
subtree = proto_tree_add_subtree_format(tree, tvb, octet_offset, li, ett_data_segments, NULL,
"data segment: LI[%d]=%d indicates: (Last segment of) LLC frame (%d octets)",
i, li, li);
data_tvb = tvb_new_subset_length(tvb, octet_offset, li);
call_dissector(data_handle, data_tvb, pinfo, subtree);
octet_offset += li;
break;
}
first_li = FALSE;
}
if (octet_offset < octet_length)
{
if (more)
{
subtree = proto_tree_add_subtree_format(tree, tvb, octet_offset, octet_length - octet_offset, ett_data_segments, NULL,
"data segment: LI not present: \n The Upper Layer PDU in the current RLC data block either fills the current RLC data block precisely \nor continues in the following in-sequence RLC data block");
}
else
{
subtree = proto_tree_add_subtree(tree, tvb, octet_offset, octet_length - octet_offset, ett_data_segments, NULL, "Padding Octets");
}
data_tvb = tvb_new_subset_length(tvb, octet_offset, octet_length - octet_offset);
call_dissector(data_handle, data_tvb, pinfo, subtree);
octet_offset = octet_length;
}
return (octet_offset - initial_offset);
}
static guint16 dissect_egprs_data_segments(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint initial_offset, guint8 octet_length, guint8 li_count, length_indicator_t *li_array)
{
guint octet_offset = initial_offset;
guint8 i;
tvbuff_t *data_tvb = NULL;
gboolean first_li = TRUE;
proto_tree *subtree = NULL;
for(i = 0; i < li_count; i++)
{
guint8 li = li_array[i].li >> 1;
switch (li)
{
case 0:
if (first_li)
{
if (li_array[i].li & 1)
{
proto_tree_add_subtree_format(tree, tvb, li_array[i].offset, 1, ett_data_segments, NULL,
"LI[%d]=%d indicates: The previous RLC data block contains a Upper Layer PDU, or a part of it, \nthat fills precisely the previous data block and for which there is no length indicator in that RLC data block. \nThe current RLC data block contains a Upper Layer PDU that either fills the current RLC data block precisely or \ncontinues in the next RLC data block.",
i, li);
}
else
{
proto_tree_add_subtree_format(tree, tvb, li_array[i].offset, 1, ett_data_segments, NULL,
"LI[%d]=%d indicates: The last Upper Layer PDU of the previous in sequence RLC data block ends \nat the boundary of that RLC data block and it has no LI in the header of that RLC data block. \nThus the current RLC data block contains the first segment of all included Upper Layer PDUs.",
i, li);
}
}
else
{
proto_tree_add_subtree_format(tree, tvb, li_array[i].offset, 1, ett_data_segments, NULL,
"LI[%d]=%d indicates: Unexpected occurrence of LI=0.",
i, li);
}
break;
case 126:
if (first_li)
{
if (li_array[i].li & 1)
{
proto_tree_add_subtree_format(tree, tvb, li_array[i].offset, 1, ett_data_segments, NULL,
"LI[%d]=%d indicates: The current RLC data block contains the first segment of an Upper Layer PDU \nthat either fills the current RLC data block precisely or continues in the next RLC data block.",
i, li);
}
else
{
proto_tree_add_subtree_format(tree, tvb, li_array[i].offset, 1, ett_data_segments, NULL,
"LI[%d]=%d indicates: The current RLC data block contains the first segment of all included Upper Layer PDUs.",
i, li);
}
}
else
{
proto_tree_add_subtree_format(tree, tvb, li_array[i].offset, 1, ett_data_segments, NULL,
"LI[%d]=%d indicates: Unexpected occurrence of LI=126.",
i, li);
}
break;
case 127:
if (first_li)
{
subtree = proto_tree_add_subtree_format(tree, tvb, octet_offset, octet_length - octet_offset, ett_data_segments, NULL,
"data segment: LI[%d]=%d indicates: The RLC data block contains only filler bits",
i, li);
}
else
{
subtree = proto_tree_add_subtree_format(tree, tvb, octet_offset, octet_length - octet_offset, ett_data_segments, NULL,
"data segment: LI[%d]=%d indicates: The remainder of the RLC data block contains filler bits",
i, li);
}
data_tvb = tvb_new_subset_length(tvb, octet_offset, octet_length - octet_offset);
call_dissector(data_handle, data_tvb, pinfo, subtree);
octet_offset = octet_length;
break;
default:
subtree = proto_tree_add_subtree_format(tree, tvb, octet_offset, li, ett_data_segments, NULL,
"data segment: LI[%d]=%d indicates: (Last segment of) LLC frame (%d octets)",
i, li, li);
data_tvb = tvb_new_subset_length(tvb, octet_offset, li);
call_dissector(data_handle, data_tvb, pinfo, subtree);
octet_offset += li;
break;
}
first_li = FALSE;
}
if (octet_offset < octet_length)
{
subtree = proto_tree_add_subtree(tree, tvb, octet_offset, octet_length - octet_offset, ett_data_segments, NULL,
"data segment: LI not present: \n The Upper Layer PDU in the current RLC data block either fills the current RLC data block precisely \nor continues in the following in-sequence RLC data block");
data_tvb = tvb_new_subset_length(tvb, octet_offset, octet_length - octet_offset);
call_dissector(data_handle, data_tvb, pinfo, subtree);
octet_offset = octet_length;
}
return (octet_offset - initial_offset);
}
static void
dissect_ul_rlc_control_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, RlcMacUplink_t *data, guint16 bit_length)
{
csnStream_t ar;
proto_item *ti;
proto_tree *rlcmac_tree;
guint bit_offset = 0;
csnStreamInit(&ar, 0, bit_length, pinfo);
data->u.MESSAGE_TYPE = tvb_get_bits8(tvb, 8, 6);
ti = proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, bit_offset >> 3, -1,
"GSM RLC/MAC: %s (%d) (Uplink)",
val_to_str_ext(data->u.MESSAGE_TYPE, &ul_rlc_message_type_vals_ext, "Unknown Messsage Type"),
data->u.MESSAGE_TYPE);
rlcmac_tree = proto_item_add_subtree(ti, ett_gsm_rlcmac);
col_append_sep_str(pinfo->cinfo, COL_INFO, ":", val_to_str_ext(data->u.MESSAGE_TYPE, &ul_rlc_message_type_vals_ext, "Unknown Messsage Type"));
switch (data->u.MESSAGE_TYPE)
{
case MT_PACKET_CELL_CHANGE_FAILURE:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Cell_Change_Failure_t), tvb, &data->u.Packet_Cell_Change_Failure, ett_gsm_rlcmac);
break;
}
case MT_PACKET_CONTROL_ACK:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Control_Acknowledgement_t), tvb, &data->u.Packet_Control_Acknowledgement, ett_gsm_rlcmac);
break;
}
case MT_PACKET_DOWNLINK_ACK_NACK:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Downlink_Ack_Nack_t), tvb, &data->u.Packet_Downlink_Ack_Nack, ett_gsm_rlcmac);
break;
}
case MT_PACKET_UPLINK_DUMMY_CONTROL_BLOCK:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Uplink_Dummy_Control_Block_t), tvb, &data->u.Packet_Uplink_Dummy_Control_Block, ett_gsm_rlcmac);
break;
}
case MT_PACKET_MEASUREMENT_REPORT:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Measurement_Report_t), tvb, &data->u.Packet_Measurement_Report, ett_gsm_rlcmac);
break;
}
case MT_PACKET_RESOURCE_REQUEST:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Resource_Request_t), tvb, &data->u.Packet_Resource_Request, ett_gsm_rlcmac);
break;
}
case MT_PACKET_MOBILE_TBF_STATUS:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Mobile_TBF_Status_t), tvb, &data->u.Packet_Mobile_TBF_Status, ett_gsm_rlcmac);
break;
}
case MT_PACKET_PSI_STATUS:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_PSI_Status_t), tvb, &data->u.Packet_PSI_Status, ett_gsm_rlcmac);
break;
}
case MT_EGPRS_PACKET_DOWNLINK_ACK_NACK:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(EGPRS_PD_AckNack_t), tvb, &data->u.Egprs_Packet_Downlink_Ack_Nack, ett_gsm_rlcmac);
break;
}
case MT_PACKET_PAUSE:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Pause_t), tvb, &data->u.Packet_Pause, ett_gsm_rlcmac);
break;
}
case MT_PACKET_ENHANCED_MEASUREMENT_REPORT:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Enh_Measurement_Report_t), tvb, &data->u.Packet_Enh_Measurement_Report, ett_gsm_rlcmac);
break;
}
case MT_ADDITIONAL_MS_RAC:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Additional_MS_Rad_Access_Cap_t), tvb, &data->u.Additional_MS_Rad_Access_Cap, ett_gsm_rlcmac);
break;
}
case MT_PACKET_CELL_CHANGE_NOTIFICATION:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Cell_Change_Notification_t), tvb, &data->u.Packet_Cell_Change_Notification, ett_gsm_rlcmac);
break;
}
case MT_PACKET_SI_STATUS:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_SI_Status_t), tvb, &data->u.Packet_SI_Status, ett_gsm_rlcmac);
break;
}
default:
break;
}
}
static void
dissect_dl_rlc_control_message(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, RlcMacDownlink_t *data, guint16 initial_bit_offset, guint16 bit_length)
{
csnStream_t ar;
proto_item *ti;
proto_tree *rlcmac_tree;
guint16 bit_offset = initial_bit_offset;
ti = proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, bit_offset >> 3, -1,
"%s (%d) (downlink)",
val_to_str_ext(data->u.MESSAGE_TYPE, &dl_rlc_message_type_vals_ext, "Unknown Messsage Type"),
data->u.MESSAGE_TYPE);
rlcmac_tree = proto_item_add_subtree(ti, ett_gsm_rlcmac);
csnStreamInit(&ar, bit_offset, bit_length - bit_offset, pinfo);
switch (data->u.MESSAGE_TYPE)
{
case MT_PACKET_ACCESS_REJECT:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Access_Reject_t), tvb, &data->u.Packet_Access_Reject, ett_gsm_rlcmac);
break;
}
case MT_PACKET_CELL_CHANGE_ORDER:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Cell_Change_Order_t), tvb, &data->u.Packet_Cell_Change_Order, ett_gsm_rlcmac);
break;
}
case MT_PACKET_CELL_CHANGE_CONTINUE:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Cell_Change_Continue_t), tvb, &data->u.Packet_Cell_Change_Continue, ett_gsm_rlcmac);
break;
}
case MT_PACKET_DOWNLINK_ASSIGNMENT:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Downlink_Assignment_t), tvb, &data->u.Packet_Downlink_Assignment, ett_gsm_rlcmac);
break;
}
case MT_PACKET_MEASUREMENT_ORDER:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Measurement_Order_t), tvb, &data->u.Packet_Measurement_Order, ett_gsm_rlcmac);
break;
}
case MT_PACKET_NEIGHBOUR_CELL_DATA:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Neighbour_Cell_Data_t), tvb, &data->u.Packet_Neighbour_Cell_Data, ett_gsm_rlcmac);
break;
}
case MT_PACKET_SERVING_CELL_DATA:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Serving_Cell_Data_t), tvb, &data->u.Packet_Serving_Cell_Data, ett_gsm_rlcmac);
break;
}
case MT_PACKET_PAGING_REQUEST:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Paging_Request_t), tvb, &data->u.Packet_Paging_Request, ett_gsm_rlcmac);
break;
}
case MT_PACKET_PDCH_RELEASE:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_PDCH_Release_t), tvb, &data->u.Packet_PDCH_Release, ett_gsm_rlcmac);
break;
}
case MT_PACKET_POLLING_REQ:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Polling_Request_t), tvb, &data->u.Packet_Polling_Request, ett_gsm_rlcmac);
break;
}
case MT_PACKET_POWER_CONTROL_TIMING_ADVANCE:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Power_Control_Timing_Advance_t), tvb, &data->u.Packet_Power_Control_Timing_Advance, ett_gsm_rlcmac);
break;
}
case MT_PACKET_PRACH_PARAMETERS:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_PRACH_Parameters_t), tvb, &data->u.Packet_PRACH_Parameters, ett_gsm_rlcmac);
break;
}
case MT_PACKET_QUEUEING_NOTIFICATION:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Queueing_Notification_t), tvb, &data->u.Packet_Queueing_Notification, ett_gsm_rlcmac);
break;
}
case MT_PACKET_TIMESLOT_RECONFIGURE:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Timeslot_Reconfigure_t), tvb, &data->u.Packet_Timeslot_Reconfigure, ett_gsm_rlcmac);
break;
}
case MT_PACKET_TBF_RELEASE:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_TBF_Release_t), tvb, &data->u.Packet_TBF_Release, ett_gsm_rlcmac);
break;
}
case MT_PACKET_UPLINK_ACK_NACK:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Uplink_Ack_Nack_t), tvb, &data->u.Packet_Uplink_Ack_Nack, ett_gsm_rlcmac);
break;
}
case MT_PACKET_UPLINK_ASSIGNMENT:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Uplink_Assignment_t), tvb, &data->u.Packet_Uplink_Assignment, ett_gsm_rlcmac);
break;
}
case MT_PACKET_HANDOVER_COMMAND:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Handover_Command_t), tvb, &data->u.Packet_Handover_Command, ett_gsm_rlcmac);
break;
}
case MT_PACKET_PHYSICAL_INFORMATION:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_PhysicalInformation_t), tvb, &data->u.Packet_Handover_Command, ett_gsm_rlcmac);
break;
}
case MT_PACKET_DOWNLINK_DUMMY_CONTROL_BLOCK:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(Packet_Downlink_Dummy_Control_Block_t), tvb, &data->u.Packet_Downlink_Dummy_Control_Block, ett_gsm_rlcmac);
break;
}
case MT_PACKET_SYSTEM_INFO_1:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(PSI1_t), tvb, &data->u.PSI1, ett_gsm_rlcmac);
break;
}
case MT_PACKET_SYSTEM_INFO_2:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(PSI2_t), tvb, &data->u.PSI2, ett_gsm_rlcmac);
break;
}
case MT_PACKET_SYSTEM_INFO_3:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(PSI3_t), tvb, &data->u.PSI3, ett_gsm_rlcmac);
break;
}
case MT_PACKET_SYSTEM_INFO_5:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(PSI5_t), tvb, &data->u.PSI5, ett_gsm_rlcmac);
break;
}
case MT_PACKET_SYSTEM_INFO_13:
{
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(PSI13_t), tvb, &data->u.PSI13, ett_gsm_rlcmac);
break;
}
default:
break;
}
}
static void
dissect_dl_gprs_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, RlcMacDownlink_t * data)
{
proto_item *ti = NULL;
proto_tree *rlcmac_tree = NULL;
csnStream_t ar;
gint bit_offset = 0;
guint16 bit_length = tvb_reported_length(tvb) * 8;
guint8 payload_type = tvb_get_bits8(tvb, 0, 2);
guint8 rbsn = tvb_get_bits8(tvb, 8, 1);
guint8 fs = tvb_get_bits8(tvb, 14, 1);
guint8 ac = tvb_get_bits8(tvb, 15, 1);
col_append_sep_str(pinfo->cinfo, COL_INFO, ":", "GPRS DL");
if (payload_type == PAYLOAD_TYPE_DATA)
{
length_indicator_t li_array[7];
guint8 li_count = array_length(li_array);
guint64 e;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM RLC/MAC");
ti = proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, bit_offset >> 3, -1,
"GPRS DL DATA (CS%d)",
data->block_format & 0x0F);
rlcmac_tree = proto_item_add_subtree(ti, ett_gsm_rlcmac);
csnStreamInit(&ar, 0, bit_length, pinfo);
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(DL_Data_Block_GPRS_t), tvb, &data->u.DL_Data_Block_GPRS, ett_gsm_rlcmac);
bit_offset = ar.bit_offset;
e = data->u.DL_Data_Block_GPRS.E;
bit_offset += 8 * construct_gprs_data_segment_li_array(tvb, rlcmac_tree, pinfo,
bit_offset / 8,
&li_count,
li_array,
&e);
if (e)
{
dissect_gprs_data_segments(tvb, pinfo, rlcmac_tree, bit_offset / 8, bit_length / 8,
li_count,
li_array);
}
else
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_rlcmac_unexpected_header_extension, tvb, bit_offset >> 3, 1);
}
return;
}
else if (payload_type == PAYLOAD_TYPE_RESERVED)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, ":", "GSM RLC/MAC RESERVED MESSAGE TYPE");
ti = proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, bit_offset >> 3, -1, "Payload Type: RESERVED (0), not implemented");
rlcmac_tree = proto_item_add_subtree(ti, ett_gsm_rlcmac);
proto_tree_add_bits_item(rlcmac_tree, hf_dl_payload_type, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, hf_rrbp, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, hf_s_p, tvb, 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, hf_usf, tvb, 5, 3, ENC_BIG_ENDIAN);
return;
}
else if (data->block_format == RLCMAC_CS1)
{
guint8 message_type_offset = 8;
if (payload_type == PAYLOAD_TYPE_CTRL_OPT_OCTET)
{
message_type_offset += 8;
if (ac == 1)
{
message_type_offset += 8;
}
if ((rbsn == 1) && (fs == 0))
{
message_type_offset += 8;
}
}
data->u.MESSAGE_TYPE = tvb_get_bits8(tvb, message_type_offset, 6);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM RLC/MAC");
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ":", "GPRS DL:%s", val_to_str_ext(data->u.MESSAGE_TYPE, &dl_rlc_message_type_vals_ext, "Unknown Messsage Type"));
ti = proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, message_type_offset >> 3, -1,
"GSM RLC/MAC: %s (%d) (Downlink)",
val_to_str_ext(data->u.MESSAGE_TYPE, &dl_rlc_message_type_vals_ext, "Unknown Messsage Type"),
data->u.MESSAGE_TYPE);
rlcmac_tree = proto_item_add_subtree(ti, ett_gsm_rlcmac);
proto_tree_add_bits_item(rlcmac_tree, hf_dl_payload_type, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, hf_rrbp, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, hf_s_p, tvb, 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, hf_usf, tvb, 5, 3, ENC_BIG_ENDIAN);
bit_offset += 8;
if (payload_type == PAYLOAD_TYPE_CTRL_OPT_OCTET)
{
proto_tree_add_bits_item(rlcmac_tree, hf_dl_ctrl_rbsn, tvb, 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, hf_dl_ctrl_rti, tvb, 9, 5, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, hf_dl_ctrl_fs, tvb, 14, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, hf_dl_ctrl_ac, tvb, 15, 1, ENC_BIG_ENDIAN);
bit_offset += 8;
if (ac == 1)
{
guint8 ctrl_d = tvb_get_bits8(tvb, 23, 1);
proto_tree_add_bits_item(rlcmac_tree, hf_dl_ctrl_pr, tvb, 16, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, (ctrl_d?hf_downlink_tfi:hf_uplink_tfi), tvb, 18, 5, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, hf_dl_ctrl_d, tvb, 23, 1, ENC_BIG_ENDIAN);
bit_offset += 8;
}
if ((rbsn == 1) && (fs == 0))
{
proto_tree_add_bits_item(rlcmac_tree, hf_dl_ctrl_rbsn_e, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(rlcmac_tree, hf_dl_ctrl_fs_e, tvb, bit_offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(rlcmac_tree, hf_dl_ctrl_spare, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
}
}
dissect_dl_rlc_control_message(tvb, pinfo, rlcmac_tree, data, bit_offset, bit_length);
}
else
{
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_rlcmac_coding_scheme_invalid, tvb, bit_offset >> 3, -1, "GPRS block with invalid coding scheme (%d) for RLC Control",
data->block_format);
}
}
static void
dissect_egprs_dl_header_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, RlcMacDownlink_t *data, RlcMacPrivateData_t *rlc_mac)
{
if (data->flags & GSM_RLC_MAC_EGPRS_FANR_FLAG)
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_rlcmac_gprs_fanr_header_dissection_not_supported, tvb, 0, -1);
}
else
{
proto_item *ti;
proto_tree *rlcmac_tree;
csnStream_t ar;
guint16 bit_length = tvb_reported_length(tvb) * 8;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM RLC/MAC");
col_append_sep_str(pinfo->cinfo, COL_INFO, ":", "EGPRS DL:HEADER");
ti = proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, 0, -1,
"GSM RLC/MAC: EGPRS DL HEADER");
rlcmac_tree = proto_item_add_subtree(ti, ett_gsm_rlcmac);
rlc_mac->mcs = MCS_INVALID;
csnStreamInit(&ar, 0, bit_length, pinfo);
switch (data->block_format)
{
case RLCMAC_HDR_TYPE_3:
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(DL_Data_Block_EGPRS_Header_Type3_t), tvb, &data->u.DL_Data_Block_EGPRS_Header, ett_gsm_rlcmac);
rlc_mac->mcs = egprs_Header_type3_coding_puncturing_scheme_to_mcs[data->u.DL_Data_Block_EGPRS_Header.CPS];
break;
case RLCMAC_HDR_TYPE_2:
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(DL_Data_Block_EGPRS_Header_Type2_t), tvb, &data->u.DL_Data_Block_EGPRS_Header, ett_gsm_rlcmac);
rlc_mac->mcs = egprs_Header_type2_coding_puncturing_scheme_to_mcs[data->u.DL_Data_Block_EGPRS_Header.CPS];
break;
case RLCMAC_HDR_TYPE_1:
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(DL_Data_Block_EGPRS_Header_Type1_t), tvb, &data->u.DL_Data_Block_EGPRS_Header, ett_gsm_rlcmac);
rlc_mac->mcs = egprs_Header_type1_coding_puncturing_scheme_to_mcs[data->u.DL_Data_Block_EGPRS_Header.CPS];
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_gsm_rlcmac_egprs_header_type_not_handled, tvb, 0, -1);
break;
}
rlc_mac->u.egprs_dl_header_info.bsn1 = data->u.DL_Data_Block_EGPRS_Header.BSN1;
rlc_mac->u.egprs_dl_header_info.bsn2 =
(data->u.DL_Data_Block_EGPRS_Header.BSN1 + data->u.DL_Data_Block_EGPRS_Header.BSN2_offset) % 2048;
}
}
static void
dissect_ul_pacch_access_burst(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, RlcMacUplink_t * data)
{
proto_item *ti;
proto_tree *rlcmac_tree;
csnStream_t ar;
guint16 bit_length = tvb_reported_length(tvb) * 8;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM RLC/MAC");
col_append_sep_str(pinfo->cinfo, COL_INFO, ":", "PACCH ACCESS BURST");
ti = proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, 0, -1,
"GPRS UL PACCH ACCESS BURST");
rlcmac_tree = proto_item_add_subtree(ti, ett_gsm_rlcmac);
if ((bit_length > 8) && (tvb_get_bits16(tvb, 0, 9, ENC_BIG_ENDIAN) == 0x1F9))
{
csnStreamInit(&ar, 0, bit_length, pinfo);
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(UL_Packet_Control_Ack_11_t), tvb, &data->u.UL_Packet_Control_Ack_11, ett_gsm_rlcmac);
}
else if ((bit_length > 8) && (tvb_get_bits8(tvb, 0, 6) == 0x37))
{
csnStreamInit(&ar, 0, bit_length, pinfo);
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(UL_Packet_Control_Ack_TN_RRBP_11_t), tvb, &data->u.UL_Packet_Control_Ack_TN_RRBP_11, ett_gsm_rlcmac);
}
else if (tvb_get_bits8(tvb, 0, 6) == 0x1F)
{
csnStreamInit(&ar, 0, bit_length, pinfo);
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(UL_Packet_Control_Ack_8_t), tvb, &data->u.UL_Packet_Control_Ack_8, ett_gsm_rlcmac);
}
else if (tvb_get_bits8(tvb, 0, 3) == 0x0)
{
csnStreamInit(&ar, 0, bit_length, pinfo);
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(UL_Packet_Control_Ack_TN_RRBP_8_t), tvb, &data->u.UL_Packet_Control_Ack_TN_RRBP_8, ett_gsm_rlcmac);
}
else
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_rlcmac_unknown_pacch_access_burst, tvb, 0, -1);
call_dissector(data_handle, tvb, pinfo, tree);
}
}
static void
dissect_ul_gprs_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, RlcMacUplink_t * data)
{
csnStream_t ar;
guint8 payload_type = tvb_get_bits8(tvb, 0, 2);
guint16 bit_length = tvb_reported_length(tvb) * 8;
gint bit_offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM RLC/MAC");
col_append_sep_str(pinfo->cinfo, COL_INFO, ":", "GPRS UL");
if (payload_type == PAYLOAD_TYPE_DATA)
{
proto_item *ti;
proto_tree *rlcmac_tree;
guint64 e;
length_indicator_t li_array[10];
guint8 li_count = array_length(li_array);
ti = proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, bit_offset >> 3, -1,
"GPRS UL DATA (CS%d)",
data->block_format & 0x0F);
rlcmac_tree = proto_item_add_subtree(ti, ett_gsm_rlcmac);
data->u.UL_Data_Block_GPRS.TI = 0;
data->u.UL_Data_Block_GPRS.PI = 0;
csnStreamInit(&ar, 0, bit_length, pinfo);
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(UL_Data_Block_GPRS_t), tvb, &data->u.UL_Data_Block_GPRS, ett_gsm_rlcmac);
bit_offset = ar.bit_offset;
e = data->u.UL_Data_Block_GPRS.E;
bit_offset += 8 * construct_gprs_data_segment_li_array(tvb, rlcmac_tree, pinfo,
bit_offset / 8,
&li_count,
li_array,
&e);
if (data->u.UL_Data_Block_GPRS.TI)
{
proto_tree_add_bits_item(rlcmac_tree, hf_tlli, tvb, bit_offset, 32, ENC_BIG_ENDIAN);
bit_offset += 32;
}
if (data->u.UL_Data_Block_GPRS.PI)
{
proto_tree_add_bits_item(rlcmac_tree, hf_pfi, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
bit_offset += 7;
proto_tree_add_bits_ret_val(rlcmac_tree, hf_e, tvb, bit_offset, 1, &e, ENC_BIG_ENDIAN);
bit_offset ++;
}
if (e)
{
dissect_gprs_data_segments(tvb, pinfo, rlcmac_tree, bit_offset / 8, bit_length / 8,
li_count,
li_array);
}
else
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_rlcmac_unexpected_header_extension, tvb, bit_offset >> 3, 1);
}
}
else if (payload_type == PAYLOAD_TYPE_RESERVED)
{
proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, bit_offset >> 3, -1, "Payload Type: RESERVED (3)");
col_append_sep_str(pinfo->cinfo, COL_INFO, ":", "GSM RLC/MAC RESERVED MESSAGE TYPE");
}
else if (data->block_format == RLCMAC_CS1)
{
dissect_ul_rlc_control_message(tvb, pinfo, tree, data, bit_length);
}
else
{
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_rlcmac_coding_scheme_invalid, tvb, bit_offset >> 3, -1, "GPRS UL block with Coding Scheme CS%d and incompatible payload type",
data->block_format &0x0F);
}
}
static void
dissect_egprs_ul_header_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, RlcMacUplink_t *data, RlcMacPrivateData_t *rlc_mac)
{
if (data->flags & GSM_RLC_MAC_EGPRS_FANR_FLAG)
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_rlcmac_gprs_fanr_header_dissection_not_supported, tvb, 0, -1);
}
else
{
proto_item *ti;
proto_tree *rlcmac_tree;
csnStream_t ar;
guint16 bit_offset = 0;
guint16 bit_length = tvb_reported_length(tvb) * 8;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM RLC/MAC");
col_append_sep_str(pinfo->cinfo, COL_INFO, ":", "EGPRS UL:HEADER");
ti = proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, bit_offset >> 3, -1,
"GSM RLC/MAC: EGPRS UL HEADER");
rlcmac_tree = proto_item_add_subtree(ti, ett_gsm_rlcmac);
data->u.UL_Data_Block_EGPRS_Header.PI = 0;
rlc_mac->mcs = MCS_INVALID;
csnStreamInit(&ar, 0, bit_length, pinfo);
switch (data->block_format)
{
case RLCMAC_HDR_TYPE_3:
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(UL_Data_Block_EGPRS_Header_Type3_t), tvb, &data->u.UL_Data_Block_EGPRS_Header, ett_gsm_rlcmac);
rlc_mac->mcs = egprs_Header_type3_coding_puncturing_scheme_to_mcs[data->u.UL_Data_Block_EGPRS_Header.CPS];
break;
case RLCMAC_HDR_TYPE_2:
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(UL_Data_Block_EGPRS_Header_Type2_t), tvb, &data->u.UL_Data_Block_EGPRS_Header, ett_gsm_rlcmac);
rlc_mac->mcs = egprs_Header_type2_coding_puncturing_scheme_to_mcs[data->u.UL_Data_Block_EGPRS_Header.CPS];
break;
case RLCMAC_HDR_TYPE_1:
csnStreamDissector(rlcmac_tree, &ar, CSNDESCR(UL_Data_Block_EGPRS_Header_Type1_t), tvb, &data->u.UL_Data_Block_EGPRS_Header, ett_gsm_rlcmac);
rlc_mac->mcs = egprs_Header_type1_coding_puncturing_scheme_to_mcs[data->u.UL_Data_Block_EGPRS_Header.CPS];
break;
default:
proto_tree_add_expert(tree, pinfo, &ei_gsm_rlcmac_egprs_header_type_not_handled, tvb, 0, -1);
break;
}
rlc_mac->u.egprs_ul_header_info.pi = data->u.UL_Data_Block_EGPRS_Header.PI;
rlc_mac->u.egprs_ul_header_info.bsn1 = data->u.UL_Data_Block_EGPRS_Header.BSN1;
rlc_mac->u.egprs_ul_header_info.bsn2 = (data->u.UL_Data_Block_EGPRS_Header.BSN1 + data->u.UL_Data_Block_EGPRS_Header.BSN2_offset) % 2048;
}
}
static void
dissect_egprs_ul_data_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, RlcMacUplink_t *data, egprs_ul_header_info_t *egprs_ul_header_info)
{
proto_item *ti;
proto_tree *data_tree;
gint offset = 0;
length_indicator_t li_array[20];
guint8 li_count = array_length(li_array);
guint64 e, tlli_i;
guint16 block_number;
block_number = (data->flags & GSM_RLC_MAC_EGPRS_BLOCK2)?egprs_ul_header_info->bsn2:egprs_ul_header_info->bsn1;
col_append_sep_str(pinfo->cinfo, COL_INFO, ":", "DATA BLOCK");
ti = proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, offset, -1,
"GSM RLC/MAC: EGPRS UL DATA BLOCK %d (BSN %d)",
(data->flags & GSM_RLC_MAC_EGPRS_BLOCK2)?2:1,
block_number);
data_tree = proto_item_add_subtree(ti, ett_gsm_rlcmac_data);
proto_tree_add_bits_ret_val(data_tree, hf_ti, tvb, 6, 1, &tlli_i, ENC_BIG_ENDIAN);
proto_tree_add_bits_ret_val(data_tree, hf_e, tvb, 7, 1, &e, ENC_BIG_ENDIAN);
offset ++;
offset += construct_egprs_data_segment_li_array(tvb, data_tree, pinfo, offset,
&li_count,
li_array,
&e);
if (tlli_i)
{
proto_tree_add_bits_item(data_tree, hf_tlli, tvb, offset * 8, 32, ENC_BIG_ENDIAN);
offset += 4;
}
if (egprs_ul_header_info->pi)
{
proto_tree_add_bits_item(data_tree, hf_pfi, tvb, offset * 8, 7, ENC_BIG_ENDIAN);
proto_tree_add_bits_ret_val(data_tree, hf_e, tvb, (offset * 8) + 7, 1, &e, ENC_BIG_ENDIAN);
offset ++;
}
if (e)
{
dissect_egprs_data_segments(tvb, pinfo, data_tree, offset,
tvb_reported_length(tvb), li_count, li_array);
}
else
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_rlcmac_unexpected_header_extension, tvb, offset, 1);
}
}
static void
dissect_egprs_dl_data_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, RlcMacDownlink_t *data, egprs_dl_header_info_t *egprs_dl_header_info)
{
proto_item *ti;
proto_tree *data_tree;
gint offset = 0;
guint16 block_number;
length_indicator_t li_array[20];
guint8 li_count = array_length(li_array);
guint64 fbi, e;
block_number = (data->flags & GSM_RLC_MAC_EGPRS_BLOCK2)?egprs_dl_header_info->bsn2:egprs_dl_header_info->bsn1;
col_append_sep_str(pinfo->cinfo, COL_INFO, ":", "DATA BLOCK");
ti = proto_tree_add_protocol_format(tree, proto_gsm_rlcmac, tvb, offset, -1,
"GSM RLC/MAC: EGPRS DL DATA BLOCK %d (BSN %d)",
(data->flags & GSM_RLC_MAC_EGPRS_BLOCK2)?2:1,
block_number);
data_tree = proto_item_add_subtree(ti, ett_gsm_rlcmac_data);
proto_tree_add_bits_ret_val(data_tree, hf_fbi, tvb, 6, 1, &fbi, ENC_BIG_ENDIAN);
proto_tree_add_bits_ret_val(data_tree, hf_e, tvb, 7, 1, &e, ENC_BIG_ENDIAN);
offset ++;
offset += construct_egprs_data_segment_li_array(tvb, data_tree, pinfo, 1,
&li_count,
li_array,
&e);
if (e)
{
dissect_egprs_data_segments(tvb, pinfo, data_tree, offset,
tvb_reported_length(tvb), li_count, li_array);
}
else
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_rlcmac_unexpected_header_extension, tvb, offset, 1);
}
}
static int
dissect_gsm_rlcmac_downlink(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
RlcMacDownlink_t *rlc_dl;
RlcMacPrivateData_t *rlc_mac = (RlcMacPrivateData_t*)data;
rlc_dl = wmem_new0(wmem_packet_scope(), RlcMacDownlink_t);
if ((rlc_mac != NULL) && (rlc_mac->magic == GSM_RLC_MAC_MAGIC_NUMBER))
{
rlc_dl->block_format = rlc_mac->block_format;
rlc_dl->flags = rlc_mac->flags;
}
else
{
rlc_dl->block_format = RLCMAC_CS1;
rlc_dl->flags = 0;
}
switch (rlc_dl->block_format)
{
case RLCMAC_CS1:
case RLCMAC_CS2:
case RLCMAC_CS3:
case RLCMAC_CS4:
dissect_dl_gprs_block(tvb, pinfo, tree, rlc_dl);
break;
case RLCMAC_HDR_TYPE_1:
case RLCMAC_HDR_TYPE_2:
case RLCMAC_HDR_TYPE_3:
if (rlc_dl->flags & (GSM_RLC_MAC_EGPRS_BLOCK1 | GSM_RLC_MAC_EGPRS_BLOCK2))
{
dissect_egprs_dl_data_block(tvb, pinfo, tree, rlc_dl, &rlc_mac->u.egprs_dl_header_info);
}
else
{
dissect_egprs_dl_header_block(tvb, pinfo, tree, rlc_dl, rlc_mac);
}
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_rlcmac_coding_scheme_unknown, tvb, 0, -1, "GSM RLCMAC unknown coding scheme (%d)", rlc_dl->block_format);
break;
}
return tvb_reported_length(tvb);
}
static int
dissect_gsm_rlcmac_uplink(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
RlcMacUplink_t *rlc_ul;
RlcMacPrivateData_t *rlc_mac = (RlcMacPrivateData_t*)data;
rlc_ul = wmem_new0(wmem_packet_scope(), RlcMacUplink_t);
if ((rlc_mac != NULL) && (rlc_mac->magic == GSM_RLC_MAC_MAGIC_NUMBER))
{
rlc_ul->block_format = rlc_mac->block_format;
rlc_ul->flags = rlc_mac->flags;
}
else if (tvb_reported_length(tvb) < 3)
{
rlc_ul->block_format = RLCMAC_PRACH;
rlc_ul->flags = 0;
}
else
{
rlc_ul->block_format = RLCMAC_CS1;
rlc_ul->flags = 0;
}
switch (rlc_ul->block_format)
{
case RLCMAC_PRACH:
dissect_ul_pacch_access_burst(tvb, pinfo, tree, rlc_ul);
break;
case RLCMAC_CS1:
case RLCMAC_CS2:
case RLCMAC_CS3:
case RLCMAC_CS4:
dissect_ul_gprs_block(tvb, pinfo, tree, rlc_ul);
break;
case RLCMAC_HDR_TYPE_1:
case RLCMAC_HDR_TYPE_2:
case RLCMAC_HDR_TYPE_3:
if (rlc_ul->flags & (GSM_RLC_MAC_EGPRS_BLOCK1 | GSM_RLC_MAC_EGPRS_BLOCK2))
{
dissect_egprs_ul_data_block(tvb, pinfo, tree, rlc_ul, &rlc_mac->u.egprs_ul_header_info);
}
else
{
dissect_egprs_ul_header_block(tvb, pinfo, tree, rlc_ul, rlc_mac);
}
break;
default:
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_rlcmac_coding_scheme_unknown, tvb, 0, -1, "GSM RLCMAC unknown coding scheme (%d)", rlc_ul->block_format);
break;
}
return tvb_reported_length(tvb);
}
void
proto_register_gsm_rlcmac(void)
{
static gint *ett[] = {
&ett_gsm_rlcmac,
&ett_gsm_rlcmac_data,
&ett_data_segments
};
static hf_register_info hf[] = {
{ &hf_page_mode,
{ "PAGE_MODE", "gsm_rlcmac.page_mode",
FT_UINT8, BASE_DEC, VALS(page_mode_vals), 0x0,
NULL, HFILL
}
},
{ &hf_dl_persistent_level_exist,
{ "Exist_PERSISTENCE_LEVEL", "gsm_rlcmac.persistent_level_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dl_persistent_level,
{ "PERSISTENCE_LEVEL", "gsm_rlcmac.persistent_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_bsn,
{ "BSN", "gsm_rlcmac.bsn",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_bsn2_offset,
{ "BSN 2 offset", "gsm_rlcmac.bsn2_offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_e,
{ "Extension", "gsm_rlcmac.e",
FT_BOOLEAN, BASE_NONE, TFS(&e_vals), 0x0,
NULL, HFILL
}
},
{ &hf_li,
{ "Length Indicator", "gsm_rlcmac.li",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pi,
{ "PI", "gsm_rlcmac.pi",
FT_BOOLEAN, BASE_NONE, TFS(&pi_vals), 0x0,
NULL, HFILL
}
},
{ &hf_ti,
{ "TI", "gsm_rlcmac.ti",
FT_BOOLEAN, BASE_NONE, TFS(&ti_vals), 0x0,
NULL, HFILL
}
},
{ &hf_rsb,
{ "RSB", "gsm_rlcmac.rsb",
FT_BOOLEAN, BASE_NONE, TFS(&rsb_vals), 0x0,
NULL, HFILL
}
},
{ &hf_dl_spb,
{ "SPB (DL)", "gsm_rlcmac.dl.spb",
FT_UINT8, BASE_DEC, VALS(dl_spb_vals), 0x0,
NULL, HFILL
}
},
{ &hf_ul_spb,
{ "SPB (UL)", "gsm_rlcmac.ul.spb",
FT_UINT8, BASE_DEC, VALS(ul_spb_vals), 0x0,
NULL, HFILL
}
},
{ &hf_cps1,
{ "CPS", "gsm_rlcmac.cps",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &egprs_Header_type1_coding_puncturing_scheme_vals_ext, 0x0,
NULL, HFILL
}
},
{ &hf_cps2,
{ "CPS", "gsm_rlcmac.cps",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &egprs_Header_type2_coding_puncturing_scheme_vals_ext, 0x0,
NULL, HFILL
}
},
{ &hf_cps3,
{ "CPS", "gsm_rlcmac.cps",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &egprs_Header_type3_coding_puncturing_scheme_vals_ext, 0x0,
NULL, HFILL
}
},
{ &hf_me,
{ "ME", "gsm_rlcmac.me",
FT_UINT8, BASE_DEC, VALS(me_vals), 0x0,
NULL, HFILL
}
},
{ &hf_countdown_value,
{ "CV",
"gsm_rlcmac.ul.cv",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ul_data_si,
{ "SI",
"gsm_rlcmac.ul.data_si",
FT_BOOLEAN, BASE_NONE, TFS(&si_vals), 0x0,
NULL, HFILL
}
},
{ &hf_rrbp,
{ "RRBP",
"gsm_rlcmac.rrbp",
FT_UINT8, BASE_DEC, VALS(rrbp_vals), 0x0,
NULL, HFILL
}
},
{ &hf_s_p,
{ "S/P",
"gsm_rlcmac.s_p",
FT_BOOLEAN, BASE_NONE, TFS(&s_p_vals), 0x0,
NULL, HFILL
}
},
{ &hf_es_p,
{ "ES/P",
"gsm_rlcmac.es_p",
FT_UINT8, BASE_DEC, VALS(es_p_vals), 0x0,
NULL, HFILL
}
},
{ &hf_fbi,
{ "FBI",
"gsm_rlcmac.fbi",
FT_BOOLEAN, BASE_NONE, TFS(&fbi_vals), 0x0,
NULL, HFILL
}
},
{ &hf_uplink_tfi,
{ "UL TFI",
"gsm_rlcmac.ul.tfi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_global_tfi,
{ "UL TFI",
"gsm_rlcmac.global.tfi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_downlink_tfi,
{ "DL TFI",
"gsm_rlcmac.dl.tfi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ul_data_spare,
{ "UL SPARE",
"gsm_rlcmac.ul.data_spare",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pfi,
{ "PFI",
"gsm_rlcmac.pfi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_usf,
{ "USF",
"gsm_rlcmac.usf",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dl_payload_type,
{ "Payload Type (DL)",
"gsm_rlcmac.dl_payload_type",
FT_UINT8, BASE_DEC, VALS(dl_payload_type_vals), 0x0,
NULL, HFILL
}
},
{ &hf_ul_payload_type,
{ "Payload Type (UL)",
"gsm_rlcmac.ul_payload_type",
FT_UINT8, BASE_DEC, VALS(ul_payload_type_vals), 0x0,
NULL, HFILL
}
},
{ &hf_prach8_message_type_3,
{ "Message Type (3 bit)",
"gsm_rlcmac.message_type_3",
FT_UINT8, BASE_DEC, VALS(ul_prach8_message_type3_vals), 0x0,
NULL, HFILL
}
},
{ &hf_prach8_message_type_6,
{ "Message Type (6 bit)",
"gsm_rlcmac.message_type_6",
FT_UINT8, BASE_DEC, VALS(ul_prach8_message_type6_vals), 0x0,
NULL, HFILL
}
},
{ &hf_prach11_message_type_6,
{ "Message Type (6 bit)",
"gsm_rlcmac.message_type_6",
FT_UINT8, BASE_DEC, VALS(ul_prach11_message_type6_vals), 0x0,
NULL, HFILL
}
},
{ &hf_prach11_message_type_9,
{ "Message Type (9 bit)",
"gsm_rlcmac.message_type_9",
FT_UINT8, BASE_DEC, VALS(ul_prach11_message_type9_vals), 0x0,
NULL, HFILL
}
},
{ &hf_tlli,
{ "TLLI",
"gsm_rlcmac.tlli",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dl_ctrl_rbsn,
{ "RBSN",
"gsm_rlcmac.dl.rbsn",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dl_ctrl_rti,
{ "RTI",
"gsm_rlcmac.dl.rti",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dl_ctrl_fs,
{ "FS",
"gsm_rlcmac.dl.fs",
FT_BOOLEAN, BASE_NONE, TFS(&fs_vals), 0x0,
NULL, HFILL
}
},
{ &hf_dl_ctrl_ac,
{ "AC",
"gsm_rlcmac.dl.ac",
FT_BOOLEAN, BASE_NONE, TFS(&ac_vals), 0x0,
NULL, HFILL
}
},
{ &hf_dl_ctrl_pr,
{ "PR",
"gsm_rlcmac.dl.pr",
FT_UINT8, BASE_DEC, VALS(power_reduction_vals), 0x0,
NULL, HFILL
}
},
{ &hf_dl_ctrl_d,
{ "D",
"gsm_rlcmac.dl.d",
FT_BOOLEAN,BASE_NONE, TFS(&ctrl_d_vals), 0x0,
NULL, HFILL
}
},
{ &hf_dl_ctrl_rbsn_e,
{ "RBSNe",
"gsm_rlcmac.dl.rbsn_e",
FT_UINT8, BASE_DEC, VALS(rbsn_e_vals), 0x0,
NULL, HFILL
}
},
{ &hf_dl_ctrl_fs_e,
{ "FSe",
"gsm_rlcmac.dl.fs_e",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dl_ctrl_spare,
{ "DL CTRL SPARE",
"gsm_rlcmac.dl.ctrl_spare",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_startingtime_n32,
{ "N32", "gsm_rlcmac.dl.n32",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_startingtime_n51,
{ "N51", "gsm_rlcmac.dl.n51",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_startingtime_n26,
{ "N26", "gsm_rlcmac.dl.n26",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_starting_frame_number,
{ "Union", "gsm_rlcmac.dl.union",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_starting_frame_number_k,
{ "k", "gsm_rlcmac.dl.k",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_final_ack_indication,
{ "FINAL_ACK_INDICATION", "gsm_rlcmac.dl.final_ack_indication",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_starting_sequence_number,
{ "STARTING_SEQUENCE_NUMBER", "gsm_rlcmac.dl.starting_sequence_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_received_block_bitmap,
{ "Received Block Bitmap", "gsm_rlcmac.received_block_bitmap",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timing_advance_value,
{ "TIMING_ADVANCE_VALUE", "gsm_rlcmac.dl.timing_advance_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timing_advance_value_exist,
{ "TIMING_ADVANCE_VALUE Exist", "gsm_rlcmac.dl.timing_advance_value_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timing_advance_index,
{ "TIMING_ADVANCE_INDEX", "gsm_rlcmac.dl.timing_advance_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timing_advance_index_exist,
{ "TIMING_ADVANCE_INDEX Exist", "gsm_rlcmac.dl.timing_advance_index_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timing_advance_timeslot_number,
{ "TIMING_ADVANCE_TIMESLOT_NUMBER", "gsm_rlcmac.dl.timing_advance_timeslot_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_alpha,
{ "ALPHA", "gsm_rlcmac.dl.alpha",
FT_UINT8, BASE_DEC, VALS(alpha_vals), 0x0,
NULL, HFILL
}
},
{ &hf_t_avg_w,
{ "T_AVG_W", "gsm_rlcmac.dl.t_avg_w",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_t_avg_t,
{ "T_AVG_T", "gsm_rlcmac.dl.t_avg_t",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pc_meas_chan,
{ "PC_MEAS_CHAN", "gsm_rlcmac.dl.pc_meas_chan",
FT_BOOLEAN, BASE_NONE, TFS(&pc_meas_chan_vals), 0x0,
NULL, HFILL
}
},
{ &hf_n_avg_i,
{ "N_AVG_I", "gsm_rlcmac.dl.n_avg_i",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_global_power_control_parameters_pb,
{ "Pb", "gsm_rlcmac.dl.pb",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_global_power_control_parameters_int_meas_channel_list_avail,
{ "INT_MEAS_CHANNEL_LIST_AVAIL", "gsm_rlcmac.dl.int_meas_channel_list_avail",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_c_value,
{ "C_VALUE", "gsm_rlcmac.dl.c_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_rxqual,
{ "RXQUAL", "gsm_rlcmac.dl.rxqual",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_sign_var,
{ "SIGN_VAR", "gsm_rlcmac.dl.sign_var",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot0_i_level_tn,
{ "Slot[0].I_LEVEL_TN", "gsm_rlcmac.dl.slot0_i_level_tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot1_i_level_tn,
{ "Slot[1].I_LEVEL_TN", "gsm_rlcmac.dl.slot1_i_level_tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot2_i_level_tn,
{ "Slot[2].I_LEVEL_TN", "gsm_rlcmac.dl.slot2_i_level_tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot3_i_level_tn,
{ "Slot[3].I_LEVEL_TN", "gsm_rlcmac.dl.slot3_i_level_tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot4_i_level_tn,
{ "Slot[4].I_LEVEL_TN", "gsm_rlcmac.dl.slot4_i_level_tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot5_i_level_tn,
{ "Slot[5].I_LEVEL_TN", "gsm_rlcmac.dl.slot5_i_level_tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot6_i_level_tn,
{ "Slot[6].I_LEVEL_TN", "gsm_rlcmac.dl.slot6_i_level_tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot7_i_level_tn,
{ "Slot[7].I_LEVEL_TN", "gsm_rlcmac.dl.slot7_i_level_tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot0_i_level_tn_exist,
{ "Slot[0].I_LEVEL_TN Exist", "gsm_rlcmac.dl.slot0_i_level_tn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot1_i_level_tn_exist,
{ "Slot[1].I_LEVEL_TN Exist", "gsm_rlcmac.dl.slot1_i_level_tn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot2_i_level_tn_exist,
{ "Slot[2].I_LEVEL_TN Exist", "gsm_rlcmac.dl.slot2_i_level_tn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot3_i_level_tn_exist,
{ "Slot[3].I_LEVEL_TN Exist", "gsm_rlcmac.dl.slot3_i_level_tn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot4_i_level_tn_exist,
{ "Slot[4].I_LEVEL_TN Exist", "gsm_rlcmac.dl.slot4_i_level_tn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot5_i_level_tn_exist,
{ "Slot[5].I_LEVEL_TN Exist", "gsm_rlcmac.dl.slot5_i_level_tn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot6_i_level_tn_exist,
{ "Slot[6].I_LEVEL_TN Exist", "gsm_rlcmac.dl.slot6_i_level_tn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_quality_report_slot7_i_level_tn_exist,
{ "Slot[7].I_LEVEL_TN Exist", "gsm_rlcmac.dl.slot7_i_level_tn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_acknack_beginning_of_window,
{ "BEGINNING_OF_WINDOW", "gsm_rlcmac.dl.beginning_of_window",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_acknack_end_of_window,
{ "END_OF_WINDOW", "gsm_rlcmac.dl.end_of_window",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_acknack_crbb_length,
{ "CRBB_LENGTH", "gsm_rlcmac.dl.crbb_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_acknack_crbb_exist,
{ "CRBB Exist", "gsm_rlcmac.dl.crbb_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_acknack_crbb_starting_color_code,
{ "CRBB_STARTING_COLOR_CODE", "gsm_rlcmac.dl.crbb_starting_color_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_acknack_crbb_bitmap,
{ "CRBB_BITMAP", "gsm_rlcmac.dl.crbb_bitmap",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_acknack_urbb_bitmap,
{ "URBB_BITMAP", "gsm_rlcmac.dl.urbb_bitmap",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_acknack_dissector,
{ "ACKNACK Dissector length", "gsm_rlcmac.dl.acknack_dissector",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_acknack,
{ "ACKNACK", "gsm_rlcmac.dl.acknack",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_mobileallocationie_length,
{ "Length", "gsm_rlcmac.dl.mobileallocationie_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_single_rf_channel_spare,
{ "spare", "gsm_rlcmac.dl.single_rf_channel_spare",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_arfcn,
{ "ARFCN", "gsm_rlcmac.dl.arfcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_maio,
{ "MAIO", "gsm_rlcmac.dl.maio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_hsn,
{ "HSN", "gsm_rlcmac.dl.hsn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_channel_description_channel_type_and_tdma_offset,
{ "Channel_type_and_TDMA_offset", "gsm_rlcmac.dl.channel_description_channel_type_and_tdma_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_description_tn,
{ "TN", "gsm_rlcmac.dl.channel_description_tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_tsc,
{ "TSC", "gsm_rlcmac.dl.tsc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_group_call_reference_value,
{ "value", "gsm_rlcmac.dl.group_call_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_group_call_reference_sf,
{ "SF", "gsm_rlcmac.dl.group_call_sf",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_group_call_reference_af,
{ "AF", "gsm_rlcmac.dl.group_call_af",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_group_call_reference_call_priority,
{ "call_priority", "gsm_rlcmac.dl.group_call_reference_call_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_group_call_reference_ciphering_information,
{ "Ciphering_information", "gsm_rlcmac.dl.group_call_reference_call_ciphering_information",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nln_pch,
{ "NLN_PCH", "gsm_rlcmac.dl.nln_pch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nln_status,
{ "NLN_status", "gsm_rlcmac.dl.nln_status",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_priority,
{ "Priority", "gsm_rlcmac.dl.priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_p1_rest_octets_packet_page_indication_1,
{ "Packet_Page_Indication_1", "gsm_rlcmac.dl.p1_rest_octets_packet_page_indication_1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_p1_rest_octets_packet_page_indication_2,
{ "Packet_Page_Indication_2", "gsm_rlcmac.dl.p1_rest_octets_packet_page_indication_2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_p2_rest_octets_cn3,
{ "CN3", "gsm_rlcmac.dl.p2_rest_octets_cn3",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_nln,
{ "NLN", "gsm_rlcmac.dl.nln",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_p2_rest_octets_packet_page_indication_3,
{ "Packet_Page_Indication_3", "gsm_rlcmac.dl.p2_rest_octets_packet_page_indication_3",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_usf_bitmap,
{ "USF_BITMAP", "gsm_rlcmac.dl.usf_bitmap",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_usf_granularity,
{ "USF_GRANULARITY", "gsm_rlcmac.dl.usf_granularity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_p0,
{ "P0", "gsm_rlcmac.dl.p0",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pr_mode,
{ "PR_MODE", "gsm_rlcmac.dl.pr_mode",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gamma,
{ "GAMMA", "gsm_rlcmac.dl.gamma",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nr_of_radio_blocks_allocated,
{ "NR_OF_RADIO_BLOCKS_ALLOCATED", "gsm_rlcmac.dl.nr_of_radio_blocks_allocated",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_bts_pwr_ctrl_mode,
{ "BTS_PWR_CTRL_MODE", "gsm_rlcmac.dl.bts_pwr_ctrl_mode",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_polling,
{ "POLLING", "gsm_rlcmac.dl.polling",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_egprs_channel_coding_command,
{ "EGPRS_CHANNEL_CODING_COMMAND", "gsm_rlcmac.dl.egprs_channel_coding_command",
FT_UINT8, BASE_DEC, VALS(egprs_modulation_channel_coding_scheme_vals), 0x0,
NULL, HFILL
}
},
{ &hf_tlli_block_channel_coding,
{ "TLLI_BLOCK_CHANNEL_CODING", "gsm_rlcmac.dl.tlli_block_channel_coding",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_bep_period2,
{ "BEP_PERIOD2", "gsm_rlcmac.dl.bep_period2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_resegment,
{ "RESEGMENT", "gsm_rlcmac.dl.resegment",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_windowsize,
{ "EGPRS_WindowSize", "gsm_rlcmac.dl.egprs_windowsize",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_extendedra,
{ "ExtendedRA", "gsm_rlcmac.dl.extendedra",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ia_egprs_uniontype,
{ "UnionType", "gsm_rlcmac.dl.ia_egprs_00_uniontype",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ia_freqparamsbeforetime_length,
{ "Length", "gsm_rlcmac.dl.ia_freqparamsbeforetime_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_gprs_channel_coding_command,
{ "CHANNEL_CODING_COMMAND", "gsm_rlcmac.dl.gprs_channel_coding_command",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_link_quality_measurement_mode,
{ "LINK_QUALITY_MEASUREMENT_MODE", "gsm_rlcmac.dl.link_quality_measurement_mode",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_mode,
{ "RLC_MODE", "gsm_rlcmac.dl.rlc_mode",
FT_BOOLEAN, BASE_NONE, TFS(&rlc_mode_vals), 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_ta_valid,
{ "TA_VALID", "gsm_rlcmac.dl.packet_downlink_immassignment_ta_valid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_tqi,
{ "TQI", "gsm_rlcmac.dl.tqi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dl_message_type,
{ "MESSAGE_TYPE (DL)", "gsm_rlcmac.dl.message_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &dl_rlc_message_type_vals_ext, 0x0,
NULL, HFILL
}
},
{ &hf_dl_message_type_exist,
{ "Exist_STATUS_MESSAGE_TYPE", "gsm_rlcmac.dl.message_type_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_polling_id_choice,
{ "Packet Polling Choice", "gsm_rlcmac.dl.packet_polling_id.choice",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_mobile_bitlength,
{ "Bit length", "gsm_rlcmac.dl.bitlength",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_mobile_bitmap,
{ "Bitmap", "gsm_rlcmac.dl.bitmap",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_mobile_union,
{ "Mobile Allocation", "gsm_rlcmac.dl.bitmap",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_arfcn_index,
{ "ARFCN_INDEX", "gsm_rlcmac.dl.arfcn_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_arfcn_index_exist,
{ "ARFCN_INDEX Exist", "gsm_rlcmac.dl.arfcn_index_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_mobile_allocation_rfl_number,
{ "RFL_NUMBER", "gsm_rlcmac.dl.gprs_mobile_allocation_rfl_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_mobile_allocation_rfl_number_exist,
{ "RFL_NUMBER Exist", "gsm_rlcmac.dl.gprs_mobile_allocation_rfl_number_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si_rest_bitmap,
{ "BITMAP", "gsm_rlcmac.si.rest_bitmap",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si_length,
{ "Length", "gsm_rlcmac.si.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_cell_options_nmo,
{ "NMO", "gsm_rlcmac.dl.gprs_cell_options_nmo",
FT_UINT8, BASE_DEC, VALS(gsm_rlcmac_nmo_vals), 0x0,
NULL, HFILL
}
},
{ &hf_gprs_cell_options_t3168,
{ "T3168", "gsm_rlcmac.dl.gprs_cell_options_t3168",
FT_UINT8, BASE_DEC, VALS(gsm_rlcmac_t3168_vals), 0x0,
NULL, HFILL
}
},
{ &hf_gprs_cell_options_t3192,
{ "T3192", "gsm_rlcmac.dl.gprs_cell_options_t3192",
FT_UINT8, BASE_DEC, VALS(gsm_rlcmac_t3192_vals), 0x0,
NULL, HFILL
}
},
{ &hf_gprs_cell_options_drx_timer_max,
{ "DRX_TIMER_MAX", "gsm_rlcmac.dl.gprs_cell_options_drx_timer_max",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_cell_options_access_burst_type,
{ "ACCESS_BURST_TYPE", "gsm_rlcmac.dl.gprs_cell_options_access_burst_type",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ack_type,
{ "CONTROL_ACK_TYPE", "gsm_rlcmac.dl.ack_type",
FT_BOOLEAN, BASE_NONE, TFS(&ack_type_vals), 0x0,
NULL, HFILL
}
},
{ &hf_padding,
{ "Padding", "gsm_rlcmac.dl.padding",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_cell_options_bs_cv_max,
{ "BS_CV_MAX", "gsm_rlcmac.dl.gprs_cell_options_bs_cv_max",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_cell_options_pan_dec,
{ "PAN_DEC", "gsm_rlcmac.dl.gprs_cell_options_pan_dec",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_cell_options_pan_exist,
{ "Exist_PAN", "gsm_rlcmac.dl.gprs_cell_options_pan_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_cell_options_pan_inc,
{ "PAN_INC", "gsm_rlcmac.dl.gprs_cell_options_pan_inc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_cell_options_pan_max,
{ "PAN_MAX", "gsm_rlcmac.dl.gprs_cell_options_pan_max",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_cell_options_extension_exist,
{ "Exist_Extension_Bits", "gsm_rlcmac.dl.gprs_cell_options_extension_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rac,
{ "RAC", "gsm_rlcmac.dl.rac",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pbcch_not_present_spgc_ccch_sup,
{ "SPGC_CCCH_SUP", "gsm_rlcmac.dl.pbcch_not_present_spgc_ccch_sup",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pbcch_not_present_priority_access_thr,
{ "PRIORITY_ACCESS_THR", "gsm_rlcmac.dl.pbcch_not_present_priority_access_thr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pbcch_not_present_network_control_order,
{ "NETWORK_CONTROL_ORDER", "gsm_rlcmac.dl.pbcch_not_present_network_control_order",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pbcch_description_pb,
{ "Pb", "gsm_rlcmac.dl.pbcch_description_pb",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pbcch_description_tn,
{ "TN", "gsm_rlcmac.dl.pbcch_description_tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pbcch_description_choice,
{ "Description Choice", "gsm_rlcmac.dl.pbcch_description_choice",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pbcch_present_psi1_repeat_period,
{ "PSI1_REPEAT_PERIOD", "gsm_rlcmac.dl.pbcch_present_psi1_repeat_period",
FT_UINT8, BASE_DEC, VALS(gsm_rlcmac_val_plus_1_vals), 0x0,
NULL, HFILL
}
},
{ &hf_bcch_change_mark,
{ "BCCH_CHANGE_MARK", "gsm_rlcmac.dl.bcch_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si_change_field,
{ "SI_CHANGE_FIELD", "gsm_rlcmac.dl.si_change_field",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si13_change_mark,
{ "SI13_CHANGE_MARK", "gsm_rlcmac.dl.si13_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_sgsnr,
{ "SGSNR", "gsm_rlcmac.dl.sgsnr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si_status_ind,
{ "SI_STATUS_IND", "gsm_rlcmac.dl.si_status_ind",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packetbf_release,
{ "RELEASE", "gsm_rlcmac.dl.packetbf_release",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packetbf_padding,
{ "Padding", "gsm_rlcmac.dl.packetbf_padding",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packetbf_release_uplink_release,
{ "UPLINK_RELEASE", "gsm_rlcmac.dl.packetbf_release_uplink_release",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packetbf_release_downlink_release,
{ "DOWNLINK_RELEASE", "gsm_rlcmac.dl.packetbf_release_downlink_release",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packetbf_release_tbf_release_cause,
{ "TBF_RELEASE_CAUSE", "gsm_rlcmac.dl.packetbf_release_tbf_release_cause",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_control_acknowledgement_additionsr6_ctrl_ack_extension,
{ "CTRL_ACK_Extension", "gsm_rlcmac.ul.packet_control_ack_additionsr6_ctrl_ack_extension",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_control_acknowledgement_additionsr6_ctrl_ack_exist,
{ "Exist_CTRL_ACK_Extension", "gsm_rlcmac.ul.packet_control_ack_additionsr6_ctrl_ack_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_control_acknowledgement_additionsr5_tn_rrbp_exist,
{ "Exist_TN_RRBP", "gsm_rlcmac.ul.packet_control_ack_additionsr5_tn_rrbp_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_control_acknowledgement_additionsr5_g_rnti_extension_exist,
{ "Exist_TN_RRBP", "gsm_rlcmac.ul.packet_control_ack_additionsr5_g_rnti_extension_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_control_acknowledgement_additionsr6_exist,
{ "Exist_AdditionsR6", "gsm_rlcmac.ul.packet_control_ack_additionsr6_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_control_acknowledgement_additionsr5_tn_rrbp,
{ "TN_RRBP", "gsm_rlcmac.ul.packet_control_ack_additionsr5_tn_rrbp",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_control_acknowledgement_additionsr5_g_rnti_extension,
{ "G_RNTI_Extension", "gsm_rlcmac.ul.packet_control_ack_additionsr5_g_rnti_extension",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ul_retry,
{ "R", "gsm_rlcmac.ul.retry",
FT_BOOLEAN, BASE_NONE, TFS(&retry_vals), 0x0,
NULL, HFILL
}
},
{ &hf_ul_message_type,
{ "MESSAGE_TYPE (UL)", "gsm_rlcmac.ul.message_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &ul_rlc_message_type_vals_ext, 0x0,
NULL, HFILL
}
},
{ &hf_packet_control_acknowledgement_ctrl_ack,
{ "CTRL_ACK", "gsm_rlcmac.ul.packet_control_ack_ctrl_ack",
FT_UINT8, BASE_DEC, VALS(ctrl_ack_vals), 0x0,
NULL, HFILL
}
},
{ &hf_packet_control_acknowledgement_ctrl_ack_exist,
{ "Exist_AdditionsR5", "gsm_rlcmac.ul.packet_control_ack_ctrl_ack_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_receive_n_pdu_number_nsapi,
{ "nsapi", "gsm_rlcmac.dl.receive_n_pdu_number_nsapi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_receive_n_pdu_number_value,
{ "value", "gsm_rlcmac.dl.receive_n_pdu_number_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_dtm_egprs_dtm_egprs_multislot_class,
{ "DTM_EGPRS_multislot_class", "gsm_rlcmac.ul.dtm_egprs_multislot_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dtm_egprs_highmultislotclass_dtm_egprs_highmultislotclass,
{ "DTM_EGPRS_HighMultislotClass", "gsm_rlcmac.ul.dtm_egprs_highmultislotclass",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_hscsd_multislot_class,
{ "HSCSD_multislot_class", "gsm_rlcmac.ul.hscsd_multislot_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_gprs_multislot_class,
{ "GPRS_multislot_class", "gsm_rlcmac.ul.gprs_multislot_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_gprs_extended_dynamic_allocation_capability,
{ "GPRS_Extended_Dynamic_Allocation_Capability", "gsm_rlcmac.ul.gprs_extended_dynamic_allocation_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_sms_value,
{ "SMS_VALUE", "gsm_rlcmac.ul.sms_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_sm_value,
{ "SM_VALUE", "gsm_rlcmac.ul.sm_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_ecsd_multislot_class,
{ "ECSD_multislot_class", "gsm_rlcmac.ul.ecsd_multislot_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_egprs_multislot_class,
{ "EGPRS_multislot_class", "gsm_rlcmac.ul.egprs_multislot_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_egprs_extended_dynamic_allocation_capability,
{ "EGPRS_Extended_Dynamic_Allocation_Capability", "gsm_rlcmac.ul.egprs_extended_dynamic_allocation_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_dtm_gprs_multislot_class,
{ "DTM_GPRS_multislot_class", "gsm_rlcmac.ul.dtm_gprs_multislot_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_single_slot_dtm,
{ "Single_Slot_DTM", "gsm_rlcmac.ul.single_slot_dtm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dtm_egprs_dtm_egprs_multislot_class_exist,
{ "Exist_DTM_EGPRS_multislot_class", "gsm_rlcmac.ul.egprs_multislot_class_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dtm_egprs_highmultislotclass_dtm_egprs_highmultislotclass_exist,
{ "Exist_DTM_EGPRS_HighMultislotClass", "gsm_rlcmac.ul.egprs_highmultislotclass_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_hscsd_multislot_class_exist,
{ "Exist_HSCSD_multislot_class", "gsm_rlcmac.ul.hscsd_multislot_class_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_gprs_multislot_class_exist,
{ "Exist_GPRS_multislot_class", "gsm_rlcmac.ul.gprs_multislot_class_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_sms_exist,
{ "Exist_SM", "gsm_rlcmac.ul.sms_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_ecsd_multislot_class_exist,
{ "Exist_ECSD_multislot_class", "gsm_rlcmac.ul.ecsd_multislot_class_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_egprs_multislot_class_exist,
{ "Exist_EGPRS_multislot_class", "gsm_rlcmac.ul.egprs_multislot_class_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_dtm_gprs_multislot_class_exist,
{ "Exist_DTM_GPRS_multislot_class", "gsm_rlcmac.ul.gprs_multislot_class_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_rf_power_capability,
{ "RF_Power_Capability", "gsm_rlcmac.ul.rf_power_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_a5_bits,
{ "A5_bits", "gsm_rlcmac.ul.a5_bits",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_es_ind,
{ "ES_IND", "gsm_rlcmac.ul.es_ind",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_ps,
{ "PS", "gsm_rlcmac.ul.ps",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_vgcs,
{ "VGCS", "gsm_rlcmac.ul.vgcs",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_vbs,
{ "VBS", "gsm_rlcmac.ul.vbs",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_eight_psk_power_capability,
{ "Eight_PSK_Power_Capability", "gsm_rlcmac.ul.eight_psk_power_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_compact_interference_measurement_capability,
{ "COMPACT_Interference_Measurement_Capability", "gsm_rlcmac.ul.compact_interference_measurement_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_revision_level_indicator,
{ "Revision_Level_Indicator", "gsm_rlcmac.ul.revision_level_indicator",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_umts_fdd_radio_access_technology_capability,
{ "UMTS_FDD_Radio_Access_Technology_Capability", "gsm_rlcmac.ul.umts_fdd_radio_access_technology_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_umts_384_tdd_radio_access_technology_capability,
{ "UMTS_384_TDD_Radio_Access_Technology_Capability", "gsm_rlcmac.ul.umts_384_tdd_radio_access_technology_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_cdma2000_radio_access_technology_capability,
{ "CDMA2000_Radio_Access_Technology_Capability", "gsm_rlcmac.ul.cdma2000_radio_access_technology_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_umts_128_tdd_radio_access_technology_capability,
{ "UMTS_128_TDD_Radio_Access_Technology_Capability", "gsm_rlcmac.ul.umts_128_tdd_radio_access_technology_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_a5_bits_exist,
{ "Exist_A5_bits", "gsm_rlcmac.ul.a5_bits_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multislot_capability_exist,
{ "Exist_Multislot_capability", "gsm_rlcmac.ul.multislot_capability_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_eight_psk_power_capability_exist,
{ "Exist_Eight_PSK_Power_Capability", "gsm_rlcmac.ul.eight_psk_power_capability_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_extended_dtm_gprs_multislot_class_exist,
{ "Exist_Extended_DTM_multislot_class", "gsm_rlcmac.ul.extended_dtm_gprs_multislot_class_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_highmultislotcapability_exist,
{ "Exist_HighMultislotCapability", "gsm_rlcmac.ul.highmultislotcapability_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_geran_lu_modecapability_exist,
{ "Exist_GERAN_lu_ModeCapability", "gsm_rlcmac.ul.geran_lu_modecapability_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_dtm_gprs_highmultislotclass_exist,
{ "Exist_DTM_GPRS_HighMultislotClass", "gsm_rlcmac.ul.dtm_gprs_highmultislotclass_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_geran_feature_package_1,
{ "GERAN_Feature_Package_1", "gsm_rlcmac.ul.geran_feature_package_1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_extended_dtm_gprs_multislot_class,
{ "Extended_DTM_GPRS_multislot_class", "gsm_rlcmac.ul.extended_dtm_gprs_multislot_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_extended_dtm_egprs_multislot_class,
{ "Extended_DTM_EGPRS_multislot_class", "gsm_rlcmac.ul.extended_dtm_egprs_multislot_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_modulation_based_multislot_class_support,
{ "Modulation_based_multislot_class_support", "gsm_rlcmac.ul.modulation_based_multislot_class_support",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_highmultislotcapability,
{ "HighMultislotCapability", "gsm_rlcmac.ul.highmultislotcapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_geran_lu_modecapability,
{ "GERAN_lu_ModeCapability", "gsm_rlcmac.ul.geran_lu_modecapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_gmsk_multislotpowerprofile,
{ "GMSK_MultislotPowerProfile", "gsm_rlcmac.ul.gmsk_multislotpowerprofile",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_eightpsk_multislotprofile,
{ "EightPSK_MultislotProfile", "gsm_rlcmac.ul.eightpsk_multislotprofile",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_multipletbf_capability,
{ "MultipleTBF_Capability", "gsm_rlcmac.ul.multipletbf_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_downlinkadvancedreceiverperformance,
{ "DownlinkAdvancedReceiverPerformance", "gsm_rlcmac.ul.downlinkadvancedreceiverperformance",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_extendedrlc_mac_controlmessagesegmentionscapability,
{ "ExtendedRLC_MAC_ControlMessageSegmentionsCapability", "gsm_rlcmac.ul.extendedrlc_mac_controlmessagesegmentionscapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_dtm_enhancementscapability,
{ "DTM_EnhancementsCapability", "gsm_rlcmac.ul.dtm_enhancementscapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_dtm_gprs_highmultislotclass,
{ "DTM_GPRS_HighMultislotClass", "gsm_rlcmac.ul.dtm_gprs_highmultislotclass",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_ps_handovercapability,
{ "PS_HandoverCapability", "gsm_rlcmac.ul.ps_handovercapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_additional_accessechnologies_struct_t_access_technology_type,
{ "Access_Technology_Type", "gsm_rlcmac.ul.access_technology_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_additional_accessechnologies_struct_t_gmsk_power_class,
{ "GMSK_Power_class", "gsm_rlcmac.ul.gmsk_power_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_additional_accessechnologies_struct_t_eight_psk_power_class,
{ "Eight_PSK_Power_class", "gsm_rlcmac.ul.eight_psk_power_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_additional_access_technology_exist,
{ "Exist", "gsm_rlcmac.ul.additional_access_technology_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_content_dissector,
{ "Content Dissector", "gsm_rlcmac.content_dissector",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_additonal_access_dissector,
{ "Additional Access Dissector", "gsm_rlcmac.additonal_access_dissector",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_ra_capability_value_choice,
{ "Capability Value Choice", "gsm_rlcmac.ms_ra_capability_value_choice",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_ra_capability_value,
{ "Capability Value Exist", "gsm_rlcmac.ms_ra_capability_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_arc_a5_bits,
{ "A5_Bits", "gsm_rlcmac.ul.a5_bits",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_arc_arc2_spare,
{ "Arc2_Spare", "gsm_rlcmac.ul.arc2_spare",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_arc_arc1,
{ "Arc1", "gsm_rlcmac.ul.arc1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multiband_a5_bits,
{ "A5 Bits", "gsm_rlcmac.ul.multiband_a5_bits",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_edge_rf_pwr_edge_rf_pwrcap1,
{ "EDGE_RF_PwrCap1", "gsm_rlcmac.ul.edge_rf_pwrcap1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_edge_rf_pwr_edge_rf_pwrcap2,
{ "EDGE_RF_PwrCap2", "gsm_rlcmac.ul.edge_rf_pwrcap2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_spare1,
{ "Spare1", "gsm_rlcmac.ul.ms_class3_unpacked_spare1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_r_gsm_arc,
{ "R_GSM_Arc", "gsm_rlcmac.ul.ms_class3_unpacked_r_gsm_arc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_multislotclass,
{ "MultiSlotClass", "gsm_rlcmac.ul.ms_class3_unpacked_multislotclass",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_ucs2,
{ "UCS2", "gsm_rlcmac.ul.ms_class3_unpacked_ucs2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_extendedmeasurementcapability,
{ "ExtendedMeasurementCapability", "gsm_rlcmac.ul.ms_class3_unpacked_extendedmeasurementcapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_sms_value,
{ "SMS_VALUE", "gsm_rlcmac.ul.ms_class3_unpacked_sms_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_sm_value,
{ "SM_VALUE", "gsm_rlcmac.ul.ms_class3_unpacked_sm_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_ms_positioningmethod,
{ "MS_PositioningMethod", "gsm_rlcmac.ul.ms_class3_unpacked_ms_positioningmethod",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_edge_multislotclass,
{ "EDGE_MultiSlotClass", "gsm_rlcmac.ul.ms_class3_unpacked_edge_multislotclass",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_modulationcapability,
{ "ModulationCapability", "gsm_rlcmac.ul.ms_class3_unpacked_modulationcapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_gsm400_bands,
{ "GSM400_Bands", "gsm_rlcmac.ul.ms_class3_unpacked_gsm400_bands",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_gsm400_arc,
{ "GSM400_Arc", "gsm_rlcmac.ul.ms_class3_unpacked_gsm400_arc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_gsm850_arc,
{ "GSM850_Arc", "gsm_rlcmac.ul.ms_class3_unpacked_gsm850_arc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_pcs1900_arc,
{ "PCS1900_Arc", "gsm_rlcmac.ul.ms_class3_unpacked_pcs1900_arc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_umts_fdd_radio_access_technology_capability,
{ "UMTS_FDD_Radio_Access_Technology_Capability", "gsm_rlcmac.ul.ms_class3_unpacked_umts_fdd_radio_access_technology_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_umts_384_tdd_radio_access_technology_capability,
{ "UMTS_384_TDD_Radio_Access_Technology_Capability", "gsm_rlcmac.ul.ms_class3_unpacked_umts_384_tdd_radio_access_technology_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_cdma2000_radio_access_technology_capability,
{ "CDMA2000_Radio_Access_Technology_Capability", "gsm_rlcmac.ul.ms_class3_unpacked_cdma2000_radio_access_technology_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_dtm_gprs_multislot_class,
{ "DTM_GPRS_multislot_class", "gsm_rlcmac.ul.ms_class3_unpacked_dtm_gprs_multislot_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_single_slot_dtm,
{ "Single_Slot_DTM", "gsm_rlcmac.ul.ms_class3_unpacked_single_slot_dtm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_gsm_band,
{ "GSM_Band", "gsm_rlcmac.ul.ms_class3_unpacked_gsm_band",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_gsm_700_associated_radio_capability,
{ "GSM_700_Associated_Radio_Capability", "gsm_rlcmac.ul.ms_class3_unpacked_gsm_700_associated_radio_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_umts_128_tdd_radio_access_technology_capability,
{ "UMTS_128_TDD_Radio_Access_Technology_Capability", "gsm_rlcmac.ul.ms_class3_unpacked_umts_128_tdd_radio_access_technology_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_geran_feature_package_1,
{ "GERAN_Feature_Package_1", "gsm_rlcmac.ul.ms_class3_unpacked_geran_feature_package_1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_extended_dtm_gprs_multislot_class,
{ "Extended_DTM_GPRS_multislot_class", "gsm_rlcmac.ul.ms_class3_unpacked_extended_dtm_gprs_multislot_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_extended_dtm_egprs_multislot_class,
{ "Extended_DTM_EGPRS_multislot_class", "gsm_rlcmac.ul.ms_class3_unpacked_extended_dtm_egprs_multislot_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_highmultislotcapability,
{ "HighMultislotCapability", "gsm_rlcmac.ul.ms_class3_unpacked_highmultislotcapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_geran_lu_modecapability,
{ "GERAN_lu_ModeCapability", "gsm_rlcmac.ul.ms_class3_unpacked_geran_lu_modecapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_geran_featurepackage_2,
{ "GERAN_FeaturePackage_2", "gsm_rlcmac.ul.ms_class3_unpacked_geran_featurepackage_2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_gmsk_multislotpowerprofile,
{ "GMSK_MultislotPowerProfile", "gsm_rlcmac.ul.ms_class3_unpacked_gmsk_multislotpowerprofile",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_eightpsk_multislotprofile,
{ "EightPSK_MultislotProfile", "gsm_rlcmac.ul.ms_class3_unpacked_eightpsk_multislotprofile",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_tgsm_400_bandssupported,
{ "TGSM_400_BandsSupported", "gsm_rlcmac.ul.ms_class3_unpacked_tgsm_400_bandssupported",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_tgsm_400_associatedradiocapability,
{ "TGSM_400_AssociatedRadioCapability", "gsm_rlcmac.ul.ms_class3_unpacked_tgsm_400_associatedradiocapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_tgsm_900_associatedradiocapability,
{ "TGSM_900_AssociatedRadioCapability", "gsm_rlcmac.ul.ms_class3_unpacked_tgsm_900_associatedradiocapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_downlinkadvancedreceiverperformance,
{ "DownlinkAdvancedReceiverPerformance", "gsm_rlcmac.ul.ms_class3_unpacked_downlinkadvancedreceiverperformance",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_dtm_enhancementscapability,
{ "DTM_EnhancementsCapability", "gsm_rlcmac.ul.ms_class3_unpacked_dtm_enhancementscapability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_dtm_gprs_highmultislotclass,
{ "DTM_GPRS_HighMultislotClass", "gsm_rlcmac.ul.ms_class3_unpacked_dtm_gprs_highmultislotclass",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_offsetrequired,
{ "OffsetRequired", "gsm_rlcmac.ul.ms_class3_unpacked_offsetrequired",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_repeatedsacch_capability,
{ "RepeatedSACCH_Capability", "gsm_rlcmac.ul.ms_class3_unpacked_repeatedsacch_capability",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_class3_unpacked_spare2,
{ "Spare2", "gsm_rlcmac.ul.ms_class3_unpacked_spare2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_channel_request_description_peak_throughput_class,
{ "PEAK_THROUGHPUT_CLASS", "gsm_rlcmac.ul.channel_request_description_peak_throughput_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_request_description_radio_priority,
{ "RADIO_PRIORITY", "gsm_rlcmac.ul.channel_request_description_radio_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_request_description_llc_pdu_type,
{ "LLC_PDU_TYPE", "gsm_rlcmac.ul.channel_request_description_llc_pdu_type",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_channel_request_description_rlc_octet_count,
{ "RLC_OCTET_COUNT", "gsm_rlcmac.ul.channel_request_description_rlc_octet_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_resource_request_id_choice,
{ "Request ID Choice", "gsm_rlcmac.ul.packet_resource_request_id_choice",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_bep_measurementreport_mean_bep_exist,
{ "Exist", "gsm_rlcmac.ul.bep_measurementreport_mean_bep_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_bep_measurementreport_mean_bep_union,
{ "BEP_MeasurementReport", "gsm_rlcmac.ul.bep_measurementreport_mean_bep_union",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_interferencemeasurementreport_i_level_exist,
{ "Exist", "gsm_rlcmac.ul.interferencemeasurementreport_i_level_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_bep_measurements_exist,
{ "Exist_BEP_MEASUREMENTS", "gsm_rlcmac.ul.bep_measurements_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_interference_measurements_exist,
{ "Exist_INTERFERENCE_MEASUREMENTS", "gsm_rlcmac.ul.interference_measurements_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_bep_linkqualitymeasurements_mean_bep_gmsk_exist,
{ "Exist_MEAN_CV_BEP_GMSK", "gsm_rlcmac.ul.egprs_bep_linkqualitymeasurements_mean_bep_gmsk_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_bep_linkqualitymeasurements_mean_bep_8psk_exist,
{ "Exist_MEAN_CV_BEP_8PSK", "gsm_rlcmac.ul.egprs_bep_linkqualitymeasurements_mean_bep_8psk_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_bep_measurements_exist,
{ "Exist_EGPRS_BEP_LinkQualityMeasurements", "gsm_rlcmac.ul.egprs_bep_measurements_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_timeslotlinkquality_measurements_exist,
{ "Exist_EGPRS_TimeslotLinkQualityMeasurements", "gsm_rlcmac.ul.egprs_timeslotlinkquality_measurements_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pfi_exist,
{ "Exist_PFI", "gsm_rlcmac.ul.pfi_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_bep_measurementreport_mean_bep_gmsk,
{ "MEAN_BEP_GMSK", "gsm_rlcmac.ul.prr_mean_bep_gmsk",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_bep_measurementreport_mean_bep_8psk,
{ "MEAN_BEP_8PSK", "gsm_rlcmac.ul.prr_mean_bep_8psk",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_interferencemeasurementreport_i_level,
{ "I_LEVEL", "gsm_rlcmac.ul.prr_i_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_bep_linkqualitymeasurements_mean_bep_gmsk,
{ "MEAN_BEP_GMSK", "gsm_rlcmac.ul.prr_mean_bep_gmsk",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_bep_linkqualitymeasurements_cv_bep_gmsk,
{ "CV_BEP_GMSK", "gsm_rlcmac.ul.prr_cv_bep_gmsk",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_bep_linkqualitymeasurements_mean_bep_8psk,
{ "MEAN_BEP_8PSK", "gsm_rlcmac.ul.prr_mean_bep_8psk",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_bep_linkqualitymeasurements_cv_bep_8psk,
{ "CV_BEP_8PSK", "gsm_rlcmac.ul.prr_cv_bep_8psk",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_prr_additionsr99_ms_rac_additionalinformationavailable,
{ "MS_RAC_AdditionalInformationAvailable", "gsm_rlcmac.ul.prr_ms_rac_additionalinformationavailable",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_prr_additionsr99_retransmissionofprr,
{ "RetransmissionOfPRR", "gsm_rlcmac.ul.prr_retransmissionofprr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_additional_ms_rad_access_cap_id_choice,
{ "AdditionalMsRadAccessCapID Choice", "gsm_rlcmac.ul.additional_ms_rad_access_cap_id_choice",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ul_mac_header_spare,
{ "spare", "gsm_rlcmac.ul.mac_spare",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_resource_request_access_type,
{ "ACCESS_TYPE", "gsm_rlcmac.ul.prr_access_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_resource_request_access_type_exist,
{ "Exist_ACCESS_TYPE", "gsm_rlcmac.ul.prr_access_type_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ms_radio_access_capability_exist,
{ "Exist_MS_Radio_Access_capability", "gsm_rlcmac.ul.ms_radio_access_capability_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_resource_request_change_mark_exist,
{ "Exist_CHANGE_MARK", "gsm_rlcmac.ul.prr_change_mark_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_resource_request_sign_var_exist,
{ "Exist_SIGN_VAR", "gsm_rlcmac.ul.prr_sign_var_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_additionsr99_exist,
{ "Exist_AdditionsR99", "gsm_rlcmac.ul.additionsr99_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_resource_request_change_mark,
{ "CHANGE_MARK", "gsm_rlcmac.ul.prr_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_resource_request_c_value,
{ "C_VALUE", "gsm_rlcmac.ul.prr_c_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_resource_request_sign_var,
{ "SIGN_VAR", "gsm_rlcmac.ul.prr_sign_var",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_mobile_tbf_status_tbf_cause,
{ "TBF_CAUSE", "gsm_rlcmac.ul.pmts_tbf_cause",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi_message_psix_change_mark,
{ "PSIX_CHANGE_MARK", "gsm_rlcmac.ul.pps_psix_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_additional_msg_type,
{ "ADDITIONAL_MSG_TYPE", "gsm_rlcmac.ul.additional_msg_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_psi_status_pbcch_change_mark,
{ "PBCCH_CHANGE_MARK", "gsm_rlcmac.ul.pps_pbcch_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi_message_psix_count_instance_bitmap_exist,
{ "Exist_PSIX_COUNT_and_Instance_Bitmap", "gsm_rlcmac.ul.pps_count_instance_bitmap_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi_message_psix_count,
{ "PSIX_COUNT", "gsm_rlcmac.ul.pps_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi_message_instance_bitmap,
{ "Instance bitmap", "gsm_rlcmac.ul.pps_instance_bitmap",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi_message_exist,
{ "PSI_Message Exists", "gsm_rlcmac.ul.pps_message_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi_message_list,
{ "Message List", "gsm_rlcmac.ul.pps_message_list",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si_message_mess_rec,
{ "MESS_REC", "gsm_rlcmac.ul.si_message_mess_rec",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si_message_list_exist,
{ "SI_Message Exists", "gsm_rlcmac.ul.si_message_list_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si_message_list,
{ "Message List", "gsm_rlcmac.ul.si_message_list",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_channelqualityreport_c_value,
{ "C_VALUE", "gsm_rlcmac.ul.epdan_c_value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_pd_acknack_ms_out_of_memory,
{ "MS_OUT_OF_MEMORY", "gsm_rlcmac.ul.epdan_ms_out_of_memory",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_fddarget_cell_t_fdd_arfcn,
{ "FDD_ARFCN", "gsm_rlcmac.ul.epdan_fdd_arfcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_fddarget_cell_t_diversity,
{ "DIVERSITY", "gsm_rlcmac.ul.epdan_diversity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_fddarget_cell_t_bandwith_fdd,
{ "BANDWITH_FDD", "gsm_rlcmac.ul.epdan_bandwith_fdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_fddarget_cell_t_scrambling_code,
{ "SCRAMBLING_CODE", "gsm_rlcmac.ul.epdan_scrambling_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_tddarget_cell_t_tdd_arfcn,
{ "TDD-ARFCN", "gsm_rlcmac.ul.epdan_tdd_arfcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_tddarget_cell_t_diversity,
{ "Diversity TDD", "gsm_rlcmac.ul.epdan_diversity_tdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_tddarget_cell_t_bandwith_tdd,
{ "Bandwidth_TDD", "gsm_rlcmac.ul.epdan_bandwidth_tdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_tddarget_cell_t_cell_parameter,
{ "Cell Parameter", "gsm_rlcmac.ul.epdan_cell_param",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_tddarget_cell_t_sync_case_tstd,
{ "Sync Case TSTD", "gsm_rlcmac.ul.epdan_sync_case_tstd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_failure_bsic,
{ "BSIC", "gsm_rlcmac.ul.pccf_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_failure_cause,
{ "CAUSE", "gsm_rlcmac.ul.pccf_cause",
FT_UINT8, BASE_DEC, VALS(cell_change_failure_cause_vals), 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_target_cell_ci,
{ "UTRAN_CI", "gsm_rlcmac.ul.utran_csg_target_cell_ci",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_target_cell_ci,
{ "EUTRAN_CI", "gsm_rlcmac.ul.eutran_csg_target_cell_ci",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_target_cell_tac,
{ "Tracking Area Code", "gsm_rlcmac.ul.eutran_csg_target_cell_tac",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_gprs_additionsr99_tbf_est,
{ "TBF_EST", "gsm_rlcmac.ul.puan_tbf_est",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_gprs_fixedallocationdummy,
{ "FixedAllocationDummy", "gsm_rlcmac.ul.puan_fixedallocationdummy",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_egprs_00_pre_emptive_transmission,
{ "PRE_EMPTIVE_TRANSMISSION", "gsm_rlcmac.ul.puan_pre_emptive_transmission",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_egprs_00_prr_retransmission_request,
{ "PRR_RETRANSMISSION_REQUEST", "gsm_rlcmac.ul.puan_prr_retransmission_request",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_egprs_00_arac_retransmission_request,
{ "ARAC_RETRANSMISSION_REQUEST", "gsm_rlcmac.ul.puan_arac_retransmission_request",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_egprs_00_tbf_est,
{ "TBF_EST", "gsm_rlcmac.ul.puan_tbf_est",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_uplink_id_choice,
{ "Packet_Uplink_ID Choice", "gsm_rlcmac.ul.packet_uplink_id_choice",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_extended_timing_advance,
{ "Packet_Extended_Timing_Advance", "gsm_rlcmac.ul.packet_extended_timing_advance",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_change_mark_change_mark_1,
{ "CHANGE_MARK_1", "gsm_rlcmac.dl.pua_change_mark_1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_change_mark_change_mark_2,
{ "CHANGE_MARK_2", "gsm_rlcmac.dl.pua_change_mark_2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_indirect_encoding_ma_number,
{ "MA_NUMBER", "gsm_rlcmac.dl.pua_ma_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ma_frequency_list_length,
{ "MA Frequency List Length", "gsm_rlcmac.dl.ma_frequency_list_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ma_frequency_list,
{ "MA Frequency List", "gsm_rlcmac.dl.ma_frequency_list",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_request_reference_random_access_information,
{ "RANDOM_ACCESS_INFORMATION", "gsm_rlcmac.dl.pua_random_access_information",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_request_reference_frame_number,
{ "FRAME_NUMBER", "gsm_rlcmac.dl.pua_frame_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_extended_dynamic_allocation,
{ "Extended_Dynamic_Allocation", "gsm_rlcmac.dl.extended_dynamic_allocation",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ppc_timing_advance_id_choice,
{ "PacketPowerControlTimingAdvanceID", "gsm_rlcmac.dl.ppc_timing_advance_id_choice",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_data_blocks_granted,
{ "RLC_DATA_BLOCKS_GRANTED", "gsm_rlcmac.dl.rlc_data_blocks_granted",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_single_block_allocation_timeslot_number,
{ "TIMESLOT_NUMBER", "gsm_rlcmac.dl.pua_timeslot_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_dtm_single_block_allocation_timeslot_number,
{ "TIMESLOT_NUMBER", "gsm_rlcmac.dl.pua_dtm_timeslot_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_compact_reducedma_bitmaplength,
{ "BitmapLength", "gsm_rlcmac.dl.pua_bitmaplength",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_compact_reducedma_bitmap,
{ "Bitmap", "gsm_rlcmac.dl.pua_bitmap",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multiblock_allocation_timeslot_number,
{ "TIMESLOT_NUMBER", "gsm_rlcmac.dl.pua_multiblock_timeslot_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_egprs_00_arac_retransmission_request,
{ "ARAC_RETRANSMISSION_REQUEST", "gsm_rlcmac.dl.pua_egprs_00_arac_retransmission_request",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_egprs_00_access_tech_type,
{ "AccessTechnologyType", "gsm_rlcmac.dl.pua_egprs_00_access_tech_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_egprs_00_access_tech_type_exist,
{ "AccessTechnologyType Exist", "gsm_rlcmac.dl.pua_egprs_00_access_tech_type_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurement_mapping_struct_measurement_interval,
{ "MEASUREMENT_INTERVAL", "gsm_rlcmac.dl.pda_measurement_interval",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurement_mapping_struct_measurement_bitmap,
{ "MEASUREMENT_BITMAP", "gsm_rlcmac.dl.pda_measurement_bitmap",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_downlink_id_choice,
{ "Packet Downlink ID Choice", "gsm_rlcmac.dl.id_choice",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_mac_mode,
{ "MAC_MODE", "gsm_rlcmac.dl.mac_mode",
FT_UINT8, BASE_DEC, VALS(mac_mode_vals), 0x0,
NULL, HFILL
}
},
{ &hf_control_ack,
{ "CONTROL_ACK", "gsm_rlcmac.dl.control_ack",
FT_BOOLEAN, BASE_NONE, TFS(&control_ack_vals), 0x0,
NULL, HFILL
}
},
{ &hf_dl_timeslot_allocation,
{ "TIMESLOT_ALLOCATION", "gsm_rlcmac.dl.timeslot_allocation",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_dtm_channel_request_description_dtm_pkt_est_cause,
{ "DTM_Pkt_Est_Cause", "gsm_rlcmac.dl.pda_dtm_pkt_est_cause",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_mobile_identity_length_of_mobile_identity_contents,
{ "Length_of_Mobile_Identity_contents", "gsm_rlcmac.dl.ppr_length_of_mobile_identity_contents",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_mobile_identity_mobile_identity_contents,
{ "Mobile_Identity_contents", "gsm_rlcmac.dl.ppr_mobile_identity_contents",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_page_request_for_rr_conn_channel_needed,
{ "CHANNEL_NEEDED", "gsm_rlcmac.dl.ppr_channel_needed",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_page_request_for_rr_conn_tmsi,
{ "TMSI", "gsm_rlcmac.dl.ppr_conn_tmsi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_page_request_for_rr_conn_emlpp_priority,
{ "eMLPP_PRIORITY", "gsm_rlcmac.dl.ppr_emlpp_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_page_request_ptmsi,
{ "u.PTMSI", "gsm_rlcmac.dl.page_request_ptmsi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_pdch_release_timeslots_available,
{ "TIMESLOTS_AVAILABLE", "gsm_rlcmac.dl.ppr_timeslots_available",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_prach_acc_contr_class,
{ "ACC_CONTR_CLASS", "gsm_rlcmac.dl.prach_acc_contr_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_prach_max_retrans,
{ "MAX_RETRANS", "gsm_rlcmac.dl.prach_max_retrans",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_prach_control_s,
{ "S", "gsm_rlcmac.dl.prach_s",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_prach_control_tx_int,
{ "TX_INT", "gsm_rlcmac.dl.prach_tx_int",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_allocation_rfl_number,
{ "RFL_Number", "gsm_rlcmac.dl.cell_allocation_rfl_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_allocation_rfl_number_exist,
{ "RFL_Number Exist", "gsm_rlcmac.dl.cell_allocation_rfl_number_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_hcs_priority_class,
{ "PRIORITY_CLASS", "gsm_rlcmac.dl.hcs_priority_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_hcs_hcs_thr,
{ "HCS_THR", "gsm_rlcmac.dl.hcs_thr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_location_repeat_pbcch_location,
{ "PBCCH_LOCATION", "gsm_rlcmac.dl.pbcch_location",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_location_repeat_psi1_repeat_period,
{ "PSI1_REPEAT_PERIOD", "gsm_rlcmac.dl.psi1_repeat_period",
FT_UINT8, BASE_DEC, VALS(gsm_rlcmac_val_plus_1_vals), 0x0,
NULL, HFILL
}
},
{ &hf_si13_pbcch_location_si13_location,
{ "SI13_LOCATION", "gsm_rlcmac.dl.si13_location",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_bsic,
{ "BSIC", "gsm_rlcmac.dl.cell_selection_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_bar_access_2,
{ "CELL_BAR_ACCESS_2", "gsm_rlcmac.dl.cell_selection_cell_bar_access_2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_exc_acc,
{ "EXC_ACC", "gsm_rlcmac.dl.exc_acc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_same_ra_as_serving_cell,
{ "SAME_RA_AS_SERVING_CELL", "gsm_rlcmac.dl.cell_selection_same_ra_as_serving_cell",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_gprs_rxlev_access_min,
{ "GPRS_RXLEV_ACCESS_MIN", "gsm_rlcmac.dl.cell_selection_gprs_rxlev_access_min",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_gprs_ms_txpwr_max_cch,
{ "GPRS_MS_TXPWR_MAX_CCH", "gsm_rlcmac.dl.cell_selection_gprs_ms_txpwr_max_cch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_gprs_temporary_offset,
{ "GPRS_TEMPORARY_OFFSET", "gsm_rlcmac.dl.cell_selection_gprs_temporary_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_gprs_penalty_time,
{ "GPRS_PENALTY_TIME", "gsm_rlcmac.dl.cell_selection_gprs_penalty_time",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_gprs_reselect_offset,
{ "GPRS_RESELECT_OFFSET", "gsm_rlcmac.dl.cell_selection_gprs_reselect_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_param_with_freqdiff,
{ "FREQUENCY_DIFF", "gsm_rlcmac.dl.cell_selection_param_with_freqdiff",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcellparameters_start_frequency,
{ "START_FREQUENCY", "gsm_rlcmac.dl.cell_selection_start_frequency",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcellparameters_nr_of_remaining_cells,
{ "NR_OF_REMAINING_CELLS", "gsm_rlcmac.dl.cell_selection_nr_of_remaining_cells",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcellparameters_freq_diff_length,
{ "FREQ_DIFF_LENGTH", "gsm_rlcmac.dl.cellparameters_freq_diff_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_2_same_ra_as_serving_cell,
{ "SAME_RA_AS_SERVING_CELL", "gsm_rlcmac.dl.cell_selection2_same_ra_as_serving_cell",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_2_gprs_rxlev_access_min,
{ "GPRS_RXLEV_ACCESS_MIN", "gsm_rlcmac.dl.cell_selection2_gprs_rxlev_access_min",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_2_gprs_ms_txpwr_max_cch,
{ "GPRS_MS_TXPWR_MAX_CCH", "gsm_rlcmac.dl.cell_selection2_gprs_ms_txpwr_max_cch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_2_gprs_temporary_offset,
{ "GPRS_TEMPORARY_OFFSET", "gsm_rlcmac.dl.cell_selection2_gprs_temporary_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_2_gprs_penalty_time,
{ "GPRS_PENALTY_TIME", "gsm_rlcmac.dl.cell_selection2_gprs_penalty_time",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_2_gprs_reselect_offset,
{ "GPRS_RESELECT_OFFSET", "gsm_rlcmac.dl.cell_selection2_gprs_reselect_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_reject_id_choice,
{ "Reject ID Choice", "gsm_rlcmac.dl.reject_id_choice",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_reject_wait_indication,
{ "WAIT_INDICATION", "gsm_rlcmac.dl.par_wait_indication",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_reject_wait_indication_size,
{ "WAIT_INDICATION_SIZE", "gsm_rlcmac.dl.par_wait_indication_size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_order_id_choice,
{ "PacketCellChangeOrderID Choice", "gsm_rlcmac.dl.packet_cell_change_order_id_choice",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_h_freqbsiccell_bsic,
{ "BSIC", "gsm_rlcmac.dl.pcco_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_cellselectionparamswithfreqdiff_bsic,
{ "BSIC", "gsm_rlcmac.dl.pcco_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_add_frequency_list_start_frequency,
{ "START_FREQUENCY", "gsm_rlcmac.dl.add_frequency_list_start_frequency",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_add_frequency_list_bsic,
{ "BSIC", "gsm_rlcmac.dl.add_frequency_list_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_add_frequency_list_nr_of_frequencies,
{ "NR_OF_FREQUENCIES", "gsm_rlcmac.dl.add_frequency_list_nr_of_frequencies",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_add_frequency_list_freq_diff_length,
{ "FREQ_DIFF_LENGTH", "gsm_rlcmac.dl.add_frequency_list_freq_diff_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_frequency_list_nr_of_removed_freq,
{ "NR_OF_REMOVED_FREQ", "gsm_rlcmac.dl.add_frequency_list_nr_of_removed_freq",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_removed_freq_index_removed_freq_index,
{ "REMOVED FREQUENCIES", "gsm_rlcmac.dl.removed_freq_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_parameters_network_control_order,
{ "NETWORK_CONTROL_ORDER", "gsm_rlcmac.dl.nc_measurement_parameters_network_control_order",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_parameters_nc_non_drx_period,
{ "NC_NON_DRX_PERIOD", "gsm_rlcmac.dl.nc_measurement_parameters_nc_non_drx_period",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_parameters_nc_reporting_period_i,
{ "NC_REPORTING_PERIOD_I", "gsm_rlcmac.dl.nc_measurement_parameters_nc_reporting_period_i",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_parameters_nc_reporting_period_t,
{ "NC_REPORTING_PERIOD_T", "gsm_rlcmac.dl.nc_measurement_parameters_nc_reporting_period_t",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_parameters_with_frequency_list_network_control_order,
{ "NETWORK_CONTROL_ORDER", "gsm_rlcmac.dl.nc_measurement_parameters_network_control_order",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_parameters_with_frequency_list_nc_non_drx_period,
{ "NC_NON_DRX_PERIOD", "gsm_rlcmac.dl.nc_measurement_parameters_nc_non_drx_period",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_parameters_with_frequency_list_nc_reporting_period_i,
{ "NC_REPORTING_PERIOD_I", "gsm_rlcmac.dl.nc_measurement_parameters_nc_reporting_period_i",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_parameters_with_frequency_list_nc_reporting_period_t,
{ "NC_REPORTING_PERIOD_T", "gsm_rlcmac.dl.nc_measurement_parameters_nc_reporting_period_t",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ba_ind_ba_ind,
{ "BA_IND", "gsm_rlcmac.dl.pcco_ba_ind",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ba_ind_ba_ind_3g,
{ "BA_IND_3G", "gsm_rlcmac.dl.pcco_ba_ind_3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsreportpriority_number_cells,
{ "NUMBER_CELLS", "gsm_rlcmac.dl.gprsreportpriority_number_cells",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsreportpriority_report_priority,
{ "REPORT_PRIORITY", "gsm_rlcmac.dl.gprsreportpriority_report_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_offsetthreshold_reporting_offset,
{ "REPORTING_OFFSET", "gsm_rlcmac.dl.offsetthreshold_reporting_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_offsetthreshold_reporting_threshold,
{ "REPORTING_THRESHOLD", "gsm_rlcmac.dl.offsetthreshold_reporting_threshold",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams_pmo_pcco_multi_band_reporting,
{ "MULTI_BAND_REPORTING", "gsm_rlcmac.dl.gprsmeasurementparams_pmo_pcco_multi_band_reporting",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams_pmo_pcco_serving_band_reporting,
{ "SERVING_BAND_REPORTING", "gsm_rlcmac.dl.gprsmeasurementparams_pmo_pcco_serving_band_reporting",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams_pmo_pcco_scale_ord,
{ "SCALE_ORD", "gsm_rlcmac.dl.gprsmeasurementparams_pmo_pcco_scale_ord",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_gprsmeasurementparams3g_qsearch_p,
{ "Qsearch_p", "gsm_rlcmac.dl.gprsmeasurementparams3g_qsearch_p",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_searchprio3g,
{ "SearchPrio3G", "gsm_rlcmac.dl.gprsmeasurementparams3g_searchprio3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_repquantfdd,
{ "RepQuantFDD", "gsm_rlcmac.dl.gprsmeasurementparams3g_repquantfdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_multiratreportingfdd,
{ "MultiratReportingFDD", "gsm_rlcmac.dl.gprsmeasurementparams3g_multiratreportingfdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_reportingoffsetfdd,
{ "ReportingOffsetFDD", "gsm_rlcmac.dl.gprsmeasurementparams3g_reportingoffsetfdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_reportingthresholdfdd,
{ "ReportingThresholdFDD", "gsm_rlcmac.dl.gprsmeasurementparams3g_reportingthresholdfdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_multiratreportingtdd,
{ "MultiratReportingTDD", "gsm_rlcmac.dl.gprsmeasurementparams3g_multiratreportingtdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_reportingoffsettdd,
{ "ReportingOffsetTDD", "gsm_rlcmac.dl.gprsmeasurementparams3g_reportingoffsettdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_reportingthresholdtdd,
{ "ReportingThresholdTDD", "gsm_rlcmac.dl.gprsmeasurementparams3g_reportingthresholdtdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_multiratparams3g_multiratreporting,
{ "MultiratReporting", "gsm_rlcmac.dl.multiratparams3g_multiratreporting",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pmo_qsearch_p,
{ "Qsearch_P", "gsm_rlcmac.dl.enh_gprsmeasurementparams3g_pmo_qsearch_p",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pmo_searchprio3g,
{ "SearchPrio3G", "gsm_rlcmac.dl.enh_gprsmeasurementparams3g_pmo_searchprio3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pmo_repquantfdd,
{ "RepQuantFDD", "gsm_rlcmac.dl.enh_gprsmeasurementparams3g_pmo_repquantfdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pmo_multiratreportingfdd,
{ "MultiratReportingFDD", "gsm_rlcmac.dl.enh_gprsmeasurementparams3g_pmo_multiratreportingfdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pcco_qsearch_p,
{ "Qsearch_P", "gsm_rlcmac.dl.enh_gprsmeasurementparams3g_pcco_qsearch_p",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pcco_searchprio3g,
{ "SearchPrio3G", "gsm_rlcmac.dl.enh_gprsmeasurementparams3g_pcco_searchprio3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pcco_repquantfdd,
{ "RepQuantFDD", "gsm_rlcmac.dl.enh_gprsmeasurementparams3g_pcco_repquantfdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pcco_multiratreportingfdd,
{ "MultiratReportingFDD", "gsm_rlcmac.dl.enh_gprsmeasurementparams3g_pcco_multiratreportingfdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_n2_removed_3gcell_index,
{ "REMOVED_3GCELL_INDEX", "gsm_rlcmac.dl.removed_3gcell_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_n2_cell_diff_length_3g,
{ "CELL_DIFF_LENGTH_3G", "gsm_rlcmac.dl.cell_diff_length_3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_n2_cell_diff,
{ "CELL_DIFF", "gsm_rlcmac.dl.cell_diff",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_n2_count,
{ "N2 Count", "gsm_rlcmac.dl.n2_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_n1_count,
{ "N1 Count", "gsm_rlcmac.dl.n1_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cdma2000_description_complete_this,
{ "Complete_This", "gsm_rlcmac.dl.complete_this",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_fdd_neighbourcells_zero,
{ "ZERO", "gsm_rlcmac.dl.utran_fdd_neighbourcells_zero",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_fdd_neighbourcells_uarfcn,
{ "UARFCN", "gsm_rlcmac.dl.utran_fdd_neighbourcells_uarfcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_fdd_neighbourcells_indic0,
{ "Indic0", "gsm_rlcmac.dl.utran_fdd_neighbourcells_indic0",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_fdd_neighbourcells_nrofcells,
{ "NrOfCells", "gsm_rlcmac.dl.utran_fdd_neighbourcells_nrofcells",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_fdd_neighbourcells_cellinfo,
{ "CellInfo", "gsm_rlcmac.dl.utran_fdd_neighbourcells_cellinfo",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_fdd_description_bandwidth,
{ "Bandwidth", "gsm_rlcmac.dl.utran_fdd_neighbourcells_bandwidth",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_tdd_neighbourcells_zero,
{ "ZERO", "gsm_rlcmac.dl.utran_tdd_neighbourcells_zero",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_tdd_neighbourcells_uarfcn,
{ "UARFCN", "gsm_rlcmac.dl.utran_tdd_neighbourcells_uarfcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_tdd_neighbourcells_indic0,
{ "Indic0", "gsm_rlcmac.dl.utran_tdd_neighbourcells_indic0",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_tdd_neighbourcells_nrofcells,
{ "NrOfCells", "gsm_rlcmac.dl.utran_tdd_neighbourcells_nrofcells",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_tdd_description_bandwidth,
{ "Bandwidth", "gsm_rlcmac.dl.utran_tdd_description_bandwidth",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_index_start_3g,
{ "Index_Start_3G", "gsm_rlcmac.dl.index_start_3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_absolute_index_start_emr,
{ "Absolute_Index_Start_EMR", "gsm_rlcmac.dl.absolute_index_start_emr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi3_change_mark,
{ "PSI3_CHANGE_MARK", "gsm_rlcmac.dl.psi3_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pmo_pmo_ind,
{ "PMO_IND", "gsm_rlcmac.dl.enh_measurement_parameters_pmo_pmo_ind",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pmo_report_type,
{ "REPORT_TYPE", "gsm_rlcmac.dl.enh_measurement_parameters_pmo_report_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pmo_reporting_rate,
{ "REPORTING_RATE", "gsm_rlcmac.dl.enh_measurement_parameters_pmo_reporting_rate",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pmo_invalid_bsic_reporting,
{ "INVALID_BSIC_REPORTING", "gsm_rlcmac.dl.enh_measurement_parameters_pmo_invalid_bsic_reporting",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pcco_pmo_ind,
{ "PMO_IND", "gsm_rlcmac.dl.enh_measurement_parameters_pcco_pmo_ind",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pcco_report_type,
{ "REPORT_TYPE", "gsm_rlcmac.dl.enh_measurement_parameters_pcco_report_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pcco_reporting_rate,
{ "REPORTING_RATE", "gsm_rlcmac.dl.enh_measurement_parameters_pcco_reporting_rate",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pcco_invalid_bsic_reporting,
{ "INVALID_BSIC_REPORTING", "gsm_rlcmac.dl.enh_measurement_parameters_pcco_invalid_bsic_reporting",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ccn_support_description_number_cells,
{ "NUMBER_CELLS", "gsm_rlcmac.dl.ccn_support_description_number_cells",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ccn_supported,
{ "CCN_SUPPORTED", "gsm_rlcmac.dl.ccn_supported",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modecellselectionparameters_cell_bar_qualify_3,
{ "CELL_BAR_QUALIFY_3", "gsm_rlcmac.dl.lu_modecellselectionparameters_cell_bar_qualify_3",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeneighbourcellparams_nr_of_frequencies,
{ "NR_OF_FREQUENCIES", "gsm_rlcmac.dl.lu_modecellselectionparameters_nr_of_frequencies",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_cell_bar_qualify_3,
{ "CELL_BAR_QUALIFY_3", "gsm_rlcmac.dl.lu_modeonlycellselection_cell_bar_qualify_3",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_same_ra_as_serving_cell,
{ "SAME_RA_AS_SERVING_CELL", "gsm_rlcmac.dl.lu_modeonlycellselection_same_ra_as_serving_cell",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_gprs_rxlev_access_min,
{ "GPRS_RXLEV_ACCESS_MIN", "gsm_rlcmac.dl.lu_modeonlycellselection_gprs_rxlev_access_min",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_gprs_ms_txpwr_max_cch,
{ "GPRS_MS_TXPWR_MAX_CCH", "gsm_rlcmac.dl.lu_modeonlycellselection_gprs_ms_txpwr_max_cch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_gprs_temporary_offset,
{ "GPRS_TEMPORARY_OFFSET", "gsm_rlcmac.dl.lu_modeonlycellselection_gprs_temporary_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_gprs_penalty_time,
{ "GPRS_PENALTY_TIME", "gsm_rlcmac.dl.lu_modeonlycellselection_gprs_penalty_time",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_gprs_reselect_offset,
{ "GPRS_RESELECT_OFFSET", "gsm_rlcmac.dl.lu_modeonlycellselection_gprs_reselect_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselectionparamswithfreqdiff,
{ "FREQUENCY_DIFF", "gsm_rlcmac.dl.lu_modeonlycellselectionparamswithfreqdiff",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselectionparamswithfreqdiff_bsic,
{ "BSIC", "gsm_rlcmac.dl.lu_modeonlycellselectionparamswithfreqdiff_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_add_lu_modeonlyfrequencylist_start_frequency,
{ "START_FREQUENCY", "gsm_rlcmac.dl.dd_lu_modeonlyfrequencylist_start_frequency",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_add_lu_modeonlyfrequencylist_bsic,
{ "BSIC", "gsm_rlcmac.dl.dd_lu_modeonlyfrequencylist_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_add_lu_modeonlyfrequencylist_nr_of_frequencies,
{ "NR_OF_FREQUENCIES", "gsm_rlcmac.dl.dd_lu_modeonlyfrequencylist_nr_of_frequencies",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_add_lu_modeonlyfrequencylist_freq_diff_length,
{ "FREQ_DIFF_LENGTH", "gsm_rlcmac.dl.dd_lu_modeonlyfrequencylist_freq_diff_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_additionalmeasurementparams3g_fdd_reporting_threshold_2,
{ "FDD_REPORTING_THRESHOLD_2", "gsm_rlcmac.dl.gprs_additionalmeasurementparams3g_fdd_reporting_threshold_2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_servingcellpriorityparametersdescription_geran_priority,
{ "GERAN_PRIORITY", "gsm_rlcmac.dl.servingcellpriorityparametersdescription_geran_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_servingcellpriorityparametersdescription_thresh_priority_search,
{ "THRESH_Priority_Search", "gsm_rlcmac.dl.servingcellpriorityparametersdescription_thresh_priority_search",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_servingcellpriorityparametersdescription_thresh_gsm_low,
{ "THRESH_GSM_low", "gsm_rlcmac.dl.servingcellpriorityparametersdescription_thresh_gsm_low",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_servingcellpriorityparametersdescription_h_prio,
{ "H_PRIO", "gsm_rlcmac.dl.servingcellpriorityparametersdescription_h_prio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_servingcellpriorityparametersdescription_t_reselection,
{ "T_Reselection", "gsm_rlcmac.dl.servingcellpriorityparametersdescription_t_reselection",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedutran_priorityparameters_utran_freq_index,
{ "UTRAN_FREQUENCY_INDEX_a", "gsm_rlcmac.dl.repeatedutran_priorityparameters_utran_freq_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedutran_priorityparameters_utran_freq_index_exist,
{ "UTRAN_FREQUENCY_INDEX_a Exist", "gsm_rlcmac.dl.repeatedutran_priorityparameters_utran_freq_index_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedutran_priorityparameters_utran_priority,
{ "UTRAN_PRIORITY", "gsm_rlcmac.dl.repeatedutran_priorityparameters_utran_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedutran_priorityparameters_thresh_utran_high,
{ "THRESH_UTRAN_high", "gsm_rlcmac.dl.repeatedutran_priorityparameters_thresh_utran_high",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedutran_priorityparameters_thresh_utran_low,
{ "THRESH_UTRAN_low", "gsm_rlcmac.dl.repeatedutran_priorityparameters_thresh_utran_low",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedutran_priorityparameters_utran_qrxlevmin,
{ "UTRAN_QRXLEVMIN", "gsm_rlcmac.dl.repeatedutran_priorityparameters_utran_qrxlevmin",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_priorityparametersdescription3g_pmo_default_utran_priority,
{ "DEFAULT_UTRAN_PRIORITY", "gsm_rlcmac.dl.priorityparametersdescription3g_pmo_default_utran_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_priorityparametersdescription3g_pmo_default_thresh_utran,
{ "DEFAULT_THRESH_UTRAN", "gsm_rlcmac.dl.priorityparametersdescription3g_pmo_default_thresh_utran",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_priorityparametersdescription3g_pmo_default_utran_qrxlevmin,
{ "DEFAULT_UTRAN_QRXLEVMIN", "gsm_rlcmac.dl.priorityparametersdescription3g_pmo_default_utran_qrxlevmin",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reportinghreshold_offset_t_eutran_fdd_reporting_threshold,
{ "EUTRAN_FDD_REPORTING_THRESHOLD", "gsm_rlcmac.dl.eutran_fdd_reporting_threshold",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reportinghreshold_offset_t_eutran_fdd_reporting_threshold_2,
{ "EUTRAN_FDD_REPORTING_THRESHOLD_2", "gsm_rlcmac.dl.eutran_fdd_reporting_threshold_2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reportinghreshold_offset_t_eutran_fdd_reporting_offset,
{ "EUTRAN_FDD_REPORTING_OFFSET", "gsm_rlcmac.dl.eutran_fdd_reporting_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reportinghreshold_offset_t_eutran_tdd_reporting_threshold,
{ "EUTRAN_TDD_REPORTING_THRESHOLD", "gsm_rlcmac.dl.eutran_tdd_reporting_threshold",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reportinghreshold_offset_t_eutran_tdd_reporting_threshold_2,
{ "EUTRAN_TDD_REPORTING_THRESHOLD_2", "gsm_rlcmac.dl.eutran_tdd_reporting_threshold_2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reportinghreshold_offset_t_eutran_tdd_reporting_offset,
{ "EUTRAN_TDD_REPORTING_OFFSET", "gsm_rlcmac.dl.eutran_tdd_reporting_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_eutran_measurementparametersdescription_qsearch_p_eutran,
{ "Qsearch_P_EUTRAN", "gsm_rlcmac.dl.qsearch_p_eutran",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_eutran_measurementparametersdescription_eutran_rep_quant,
{ "EUTRAN_REP_QUANT", "gsm_rlcmac.dl.eutran_rep_quant",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_eutran_measurementparametersdescription_eutran_multirat_reporting,
{ "EUTRAN_MULTIRAT_REPORTING", "gsm_rlcmac.dl.eutran_multirat_reporting",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_cells_earfcn,
{ "EARFCN", "gsm_rlcmac.dl.repeatedeutran_cells_earfcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_cells_measurementbandwidth,
{ "MeasurementBandwidth", "gsm_rlcmac.dl.repeatedeutran_cells_measurementbandwidth",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_neighbourcells_eutran_priority,
{ "EUTRAN_PRIORITY", "gsm_rlcmac.dl.repeatedeutran_neighbourcells_eutran_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_neighbourcells_thresh_eutran_high,
{ "THRESH_EUTRAN_high", "gsm_rlcmac.dl.repeatedeutran_neighbourcells_thresh_eutran_high",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_neighbourcells_thresh_eutran_low,
{ "THRESH_EUTRAN_low", "gsm_rlcmac.dl.repeatedeutran_neighbourcells_thresh_eutran_low",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_neighbourcells_eutran_qrxlevmin,
{ "EUTRAN_QRXLEVMIN", "gsm_rlcmac.dl.repeatedeutran_neighbourcells_eutran_qrxlevmin",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcid_pattern_pcid_pattern_length,
{ "PCID_Pattern_length", "gsm_rlcmac.dl.pcid_pattern_pcid_pattern_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcid_pattern_pcid_pattern,
{ "PCID_Pattern", "gsm_rlcmac.dl.pcid_pattern_pcid_pattern",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcid_pattern_pcid_pattern_sense,
{ "PCID_Pattern_sense", "gsm_rlcmac.dl.pcid_pattern_pcid_pattern_sense",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcid_group_ie_pcid_bitmap_group,
{ "PCID_BITMAP_GROUP", "gsm_rlcmac.dl.pcid_group_ie_pcid_bitmap_group",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcid_group_ie_pcid,
{ "PCID_a", "gsm_rlcmac.dl.pcid_group_ie_pcid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcid_group_ie_pcid_exist,
{ "PCID_a Exist", "gsm_rlcmac.dl.pcid_group_ie_pcid_bitmap_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_frequency_index_eutran_frequency_index,
{ "EUTRAN_FREQUENCY_INDEX", "gsm_rlcmac.dl.eutran_frequency_index_eutran_frequency_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psc_pattern_length,
{ "PSC_pattern_length", "gsm_rlcmac.dl.psc_pattern_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psc_pattern,
{ "PSC_pattern", "gsm_rlcmac.dl.psc_pattern",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psc_pattern_sense,
{ "PSC_pattern_sense", "gsm_rlcmac.dl.psc_pattern_sense",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psc_group_psc,
{ "PSC", "gsm_rlcmac.dl.psc_group_psc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psc_group_psc_exist,
{ "PSC Exist", "gsm_rlcmac.dl.psc_group_psc_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_three3_csg_description_body_utran_freq_index,
{ "UTRAN_FREQUENCY_INDEX", "gsm_rlcmac.dl.three3_csg_description_body_utran_freq_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_three3_csg_description_body_utran_freq_index_exist,
{ "UTRAN_FREQUENCY_INDEX Exist", "gsm_rlcmac.dl.three3_csg_description_body_utran_freq_index_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_description_body_eutran_freq_index,
{ "EUTRAN_FREQUENCY_INDEX", "gsm_rlcmac.dl.eutran_csg_description_body_eutran_freq_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_description_body_eutran_freq_index_exist,
{ "EUTRAN_FREQUENCY_INDEX Exist", "gsm_rlcmac.dl.eutran_csg_description_body_eutran_freq_index_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_meas_ctrl_param_meas_ctrl_eutran,
{ "Measurement_Control_E-UTRAN", "gsm_rlcmac.dl.meas_ctrl_param_eutran",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_meas_ctrl_param_eutran_freq_idx,
{ "EUTRAN_FREQUENCY_INDEX", "gsm_rlcmac.dl.meas_ctrl_param_eutran_freq_idx",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_meas_ctrl_param_eutran_freq_idx_exist,
{ "EUTRAN_FREQUENCY_INDEX Exist", "gsm_rlcmac.dl.meas_ctrl_param_eutran_freq_idx_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_meas_ctrl_param_meas_ctrl_utran,
{ "Measurement_Control_UTRAN", "gsm_rlcmac.dl.meas_ctrl_param_utran",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_meas_ctrl_param_utran_freq_idx,
{ "UTRAN_FREQUENCY_INDEX", "gsm_rlcmac.dl.meas_ctrl_param_utran_freq_idx",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_meas_ctrl_param_utran_freq_idx_exist,
{ "UTRAN_FREQUENCY_INDEX Exist", "gsm_rlcmac.dl.meas_ctrl_param_utran_freq_idx_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rept_eutran_enh_cell_resel_param_eutran_qmin,
{ "E-UTRAN_Qmin", "gsm_rlcmac.dl.enh_cell_resel_param_eutran_qmin",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rept_eutran_enh_cell_resel_param_eutran_freq_index,
{ "EUTRAN_FREQUENCY_INDEX", "gsm_rlcmac.dl.enh_cell_resel_param_eutran_freq_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rept_eutran_enh_cell_resel_param_eutran_freq_index_exist,
{ "EUTRAN_FREQUENCY_INDEX Exist", "gsm_rlcmac.dl.enh_cell_resel_param_eutran_freq_index_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rept_eutran_enh_cell_resel_param_thresh_eutran_high_q,
{ "THRESH_E-UTRAN_high_Q", "gsm_rlcmac.dl.enh_cell_resel_param_eutran_high_q",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rept_eutran_enh_cell_resel_param_thresh_eutran_low_q,
{ "THRESH_E-UTRAN_low_Q", "gsm_rlcmac.dl.enh_cell_resel_param_eutran_low_q",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rept_eutran_enh_cell_resel_param_thresh_eutran_qqualmin,
{ "E-UTRAN_QQUALMIN", "gsm_rlcmac.dl.enh_cell_resel_param_eutran_qqualmin",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rept_eutran_enh_cell_resel_param_thresh_eutran_rsrpmin,
{ "E-UTRAN_RSRPmin", "gsm_rlcmac.dl.enh_cell_resel_param_eutran_rsrpmin",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_fdd_reporting_threshold,
{ "UTRAN_CSG_FDD_REPORTING_THRESHOLD", "gsm_rlcmac.dl.utran_csg_fdd_reporting_threshold",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_fdd_reporting_threshold2,
{ "UTRAN_CSG_FDD_REPORTING_THRESHOLD_2", "gsm_rlcmac.dl.utran_csg_fdd_reporting_threshold2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_tdd_reporting_threshold,
{ "UTRAN_CSG_TDD_REPORTING_THRESHOLD", "gsm_rlcmac.dl.utran_csg_tdd_reporting_threshold",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_fdd_reporting_threshold,
{ "E-UTRAN_CSG_FDD_REPORTING_THRESHOLD", "gsm_rlcmac.dl.eutran_csg_fdd_reporting_threshold",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_fdd_reporting_threshold2,
{ "E-UTRAN_CSG_FDD_REPORTING_THRESHOLD_2", "gsm_rlcmac.dl.eutran_csg_fdd_reporting_threshold2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_tdd_reporting_threshold,
{ "E-UTRAN_CSG_TDD_REPORTING_THRESHOLD", "gsm_rlcmac.dl.eutran_csg_tdd_reporting_threshold",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_tdd_reporting_threshold2,
{ "E-UTRAN_CSG_TDD_REPORTING_THRESHOLD_2", "gsm_rlcmac.dl.eutran_csg_tdd_reporting_threshold2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_parametersdescription_pmo_eutran_ccn_active,
{ "EUTRAN_CCN_ACTIVE", "gsm_rlcmac.dl.eutran_parametersdescription_pmo_eutran_ccn_active",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr8_ba_ind_3g,
{ "BA_IND_3G", "gsm_rlcmac.dl.pmo_additionsr8_ba_ind_3g",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr8_pmo_ind,
{ "PMO_IND", "gsm_rlcmac.dl.pmo_additionsr8_pmo_ind",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr7_reporting_offset_700,
{ "REPORTING_OFFSET_700", "gsm_rlcmac.dl.pmo_additionsr7_reporting_offset_700",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr7_reporting_threshold_700,
{ "REPORTING_THRESHOLD_700", "gsm_rlcmac.dl.pmo_additionsr7_reporting_threshold_700",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr7_reporting_offset_810,
{ "REPORTING_OFFSET_810", "gsm_rlcmac.dl.pmo_additionsr7_reporting_offset_810",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr7_reporting_threshold_810,
{ "REPORTING_THRESHOLD_810", "gsm_rlcmac.dl.pmo_additionsr7_reporting_threshold_810",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr6_ccn_active_3g,
{ "CCN_ACTIVE_3G", "gsm_rlcmac.dl.pmo_additionsr6_ccn_active_3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr6_ccn_active_3g,
{ "CCN_ACTIVE_3G", "gsm_rlcmac.dl.pcco_additionsr6_ccn_active_3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr5_grnti,
{ "GRNTI", "gsm_rlcmac.dl.pmo_additionsr5_grnti",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr5_grnti,
{ "GRNTI", "gsm_rlcmac.dl.pcco_additionsr5_grnti",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr4_ccn_active,
{ "CCN_ACTIVE", "gsm_rlcmac.dl.pmo_additionsr4_ccn_active",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr4_ccn_active,
{ "CCN_ACTIVE", "gsm_rlcmac.dl.pcco_additionsr4_ccn_active",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr4_container_id,
{ "CONTAINER_ID", "gsm_rlcmac.dl.pcco_additionsr4_container_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lsa_id_info_element_lsa_id,
{ "LSA_ID", "gsm_rlcmac.dl.lsa_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lsa_id_info_element_shortlsa_id,
{ "ShortLSA_ID", "gsm_rlcmac.dl.lsa_shortlsa_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lsa_parameters_nr_of_freq_or_cells,
{ "NR_OF_FREQ_OR_CELLS", "gsm_rlcmac.dl.lsa_nr_of_freq_or_cells",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_gsm_immediate_rel,
{ "IMMEDIATE_REL", "gsm_rlcmac.dl.taget_cell_immediate_rel",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_gsm_bsic,
{ "BSIC", "gsm_rlcmac.dl.taget_cell_gsm_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g_immediate_rel,
{ "IMMEDIATE_REL", "gsm_rlcmac.dl.immediate_rel",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_eutran_earfcn,
{ "EARFCN", "gsm_rlcmac.dl.pcco_target_cell_eutran_earfcn",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_eutran_measurement_bandwidth,
{ "Measurement Bandwidth", "gsm_rlcmac.dl.pcco_target_cell_eutran_meas_bw",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_eutran_pl_cell_id,
{ "Physical Layer Cell Identity", "gsm_rlcmac.dl.pcco_target_cell_eutran_cell_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_utran_priority_fdd_arfcn,
{ "FDD_ARFCN", "gsm_rlcmac.dl.idvl_utran_priority_fdd_arfcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_utran_priority_fdd_arfcn_exist,
{ "FDD_ARFCN Exist", "gsm_rlcmac.dl.idvl_utran_priority_fdd_arfcn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_utran_priority_tdd_arfcn,
{ "TDD_ARFCN", "gsm_rlcmac.dl.idvl_utran_priority_tdd_arfcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_utran_priority_tdd_arfcn_exist,
{ "TDD_ARFCN Exist", "gsm_rlcmac.dl.idvl_utran_priority_tdd_arfcn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_default_utran_priority,
{ "DEFAULT_UTRAN_PRIORITY", "gsm_rlcmac.dl.idvl_prio_dlft_geran_prio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_utran_priority,
{ "UTRAN_PRIORITY", "gsm_rlcmac.dl.idvl_prio_geran_prio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_default_eutran_priority,
{ "DEFAULT_E-UTRAN_PRIORITY", "gsm_rlcmac.dl.idvl_prio_dlft_eutran_prio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_eutran_priority,
{ "E-UTRAN_PRIORITY", "gsm_rlcmac.dl.idvl_prio_eutran_prio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_eutran_priority_earfcn,
{ "EARFCN", "gsm_rlcmac.dl.idvl_eutran_priority_earfcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_eutran_priority_earfcn_exist,
{ "EARFCN Exist", "gsm_rlcmac.dl.idvl_eutran_priority_earfcn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_prio_geran_priority,
{ "GERAN_PRIORITY", "gsm_rlcmac.dl.idvl_prio_dlft_geran_prio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_prio_t3230_timeout_value,
{ "T3230 timeout value", "gsm_rlcmac.dl.idvl_prio_t3230",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_g_rnti_ext,
{ "G-RNTI extension", "gsm_rlcmac.dl.pcco_g_rnti_ext",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ba_used_ba_used,
{ "BA_USED", "gsm_rlcmac.ul.ba_used",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ba_used_ba_used_3g,
{ "BA_USED_3G", "gsm_rlcmac.ul.ba_used_3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_serving_cell_data_rxlev_serving_cell,
{ "RXLEV_SERVING_CELL", "gsm_rlcmac.ul.rxlev_serving_cell",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurements_frequency_n,
{ "FREQUENCY_N", "gsm_rlcmac.ul.frequency_n",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurements_bsic_n,
{ "BSIC_N", "gsm_rlcmac.ul.bsic_n",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurements_rxlev_n,
{ "RXLEV_N", "gsm_rlcmac.ul.rxlev_n",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedinvalid_bsic_info_bcch_freq_n,
{ "BCCH_FREQ_N", "gsm_rlcmac.ul.bcch_freq_n",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedinvalid_bsic_info_bsic_n,
{ "BSIC_N", "gsm_rlcmac.ul.bsic_n",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedinvalid_bsic_info_rxlev_n,
{ "RXLEV_N", "gsm_rlcmac.ul.rxlev_n",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_reporting_quantity_instance_reporting_quantity,
{ "REPORTING_QUANTITY", "gsm_rlcmac.ul.reporting_quantity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pemr_additionsr8_bitmap_length,
{ "BITMAP_LENGTH", "gsm_rlcmac.ul.pemr_additionsr8_bitmap_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_report_nc_mode,
{ "NC_MODE", "gsm_rlcmac.ul.nc_mode",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_report_number_of_nc_measurements,
{ "NUMBER_OF_NC_MEASUREMENTS", "gsm_rlcmac.ul.number_of_nc_measurements",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_nc_measurement_report_nc_mode,
{ "NC_MODE", "gsm_rlcmac.ul.nc_mode",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_nc_measurement_report_pmo_used,
{ "PMO_USED", "gsm_rlcmac.ul.pmo_used",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_nc_measurement_report_bsic_seen,
{ "BSIC_Seen", "gsm_rlcmac.ul.bsic_seen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_nc_measurement_report_scale,
{ "SCALE", "gsm_rlcmac.ul.scale",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_ext_reporting_type,
{ "EXT_REPORTING_TYPE", "gsm_rlcmac.ul.ext_reporting_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot0_i_level,
{ "Slot[0].I_LEVEL", "gsm_rlcmac.ul.slot0_i_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot1_i_level,
{ "Slot[1].I_LEVEL", "gsm_rlcmac.ul.slot1_i_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot2_i_level,
{ "Slot[2].I_LEVEL", "gsm_rlcmac.ul.slot2_i_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot3_i_level,
{ "Slot[3].I_LEVEL", "gsm_rlcmac.ul.slot3_i_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot4_i_level,
{ "Slot[4].I_LEVEL", "gsm_rlcmac.ul.slot4_i_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot5_i_level,
{ "Slot[5].I_LEVEL", "gsm_rlcmac.ul.slot5_i_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot6_i_level,
{ "Slot[6].I_LEVEL", "gsm_rlcmac.ul.slot6_i_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot7_i_level,
{ "Slot[7].I_LEVEL", "gsm_rlcmac.ul.slot7_i_level",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_number_of_ext_measurements,
{ "NUMBER_OF_EXT_MEASUREMENTS", "gsm_rlcmac.ul.number_of_ext_measurements",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurements_3g_cell_list_index_3g,
{ "CELL_LIST_INDEX_3G", "gsm_rlcmac.ul.measurements_3g_cell_list_index_3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurements_3g_reporting_quantity,
{ "REPORTING_QUANTITY", "gsm_rlcmac.ul.measurements_3g_reporting_quantity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr99_pmo_used,
{ "PMO_USED", "gsm_rlcmac.ul.pmr_additionsr99_pmo_used",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr99_n_3g,
{ "N_3G", "gsm_rlcmac.ul.pmr_additionsr99_n_3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_eutran_meas_rpt_freq_idx,
{ "E-UTRAN_FREQUENCY_INDEX", "gsm_rlcmac.ul.pmr_eutran_meas_rpt_freq_idx",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_eutran_meas_rpt_cell_id,
{ "CELL IDENTITY", "gsm_rlcmac.ul.pmr_eutran_meas_rpt_cell_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_eutran_meas_rpt_quantity,
{ "REPORTING_QUANTITY", "gsm_rlcmac.ul.pmr_eutran_meas_rpt_quantity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_measurement_report_num_eutran,
{ "N_EUTRAN", "gsm_rlcmac.uleutran_measurement_report_num_eutran",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_emr_servingcell_dtx_used,
{ "DTX_USED", "gsm_rlcmac.ul.emr_servingcell_dtx_used",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_emr_servingcell_rxlev_val,
{ "RXLEV_VAL", "gsm_rlcmac.ul.emr_servingcell_rxlev_val",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_emr_servingcell_rx_qual_full,
{ "RX_QUAL_FULL", "gsm_rlcmac.ul.emr_servingcell_rx_qual_full",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_emr_servingcell_mean_bep,
{ "MEAN_BEP", "gsm_rlcmac.ul.emr_mean_bep",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_emr_servingcell_cv_bep,
{ "CV_BEP", "gsm_rlcmac.ul.emr_cv_bep",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_emr_servingcell_nbr_rcvd_blocks,
{ "NBR_RCVD_BLOCKS", "gsm_rlcmac.ul.emr_nbr_rcvd_blocks",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enhancedmeasurementreport_rr_short_pd,
{ "RR_Short_PD", "gsm_rlcmac.ul.emr_rr_short_pd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enhancedmeasurementreport_message_type,
{ "MESSAGE_TYPE", "gsm_rlcmac.ul.emr_message_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enhancedmeasurementreport_shortlayer2_header,
{ "ShortLayer2_Header", "gsm_rlcmac.ul.emr_shortlayer2_header",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enhancedmeasurementreport_bsic_seen,
{ "BSIC_Seen", "gsm_rlcmac.ul.emr_bsic_seen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enhancedmeasurementreport_scale,
{ "SCALE", "gsm_rlcmac.ul.emr_scale",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_packet_measurement_report_psi5_change_mark,
{ "PSI5_CHANGE_MARK", "gsm_rlcmac.ul.pmr_psi5_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_ext_frequency_list_start_frequency,
{ "START_FREQUENCY", "gsm_rlcmac.dl.ext_frequency_list_start_frequency",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_frequency_list_nr_of_frequencies,
{ "NR_OF_FREQUENCIES", "gsm_rlcmac.dl.ext_frequency_list_nr_of_frequencies",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_frequency_list_freq_diff_length,
{ "FREQ_DIFF_LENGTH", "gsm_rlcmac.dl.ext_frequency_list_freq_diff_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_packet_measurement_order_pmo_index,
{ "PMO_INDEX", "gsm_rlcmac.dl.pmo_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_measurement_order_pmo_count,
{ "PMO_COUNT", "gsm_rlcmac.dl.pmo_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ccn_measurement_report_rxlev_serving_cell,
{ "RXLEV_SERVING_CELL", "gsm_rlcmac.dl.rxlev_serving_cell",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ccn_measurement_report_number_of_nc_measurements,
{ "NUMBER_OF_NC_MEASUREMENTS", "gsm_rlcmac.dl.number_of_nc_measurements",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_gsm_notif_bsic,
{ "BSIC", "gsm_rlcmac.dl.target_cell_gsm_notif_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_fdd_target_cell_notif_fdd_arfcn,
{ "FDD_ARFCN", "gsm_rlcmac.dl.fdd_target_cell_notif_fdd_arfcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_fdd_target_cell_notif_bandwith_fdd,
{ "BANDWITH_FDD", "gsm_rlcmac.dl.fdd_target_cell_notif_bandwith_fdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_fdd_target_cell_notif_scrambling_code,
{ "SCRAMBLING_CODE", "gsm_rlcmac.dl.fdd_target_cell_notif_scrambling_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g_notif_reporting_quantity,
{ "REPORTING_QUANTITY", "gsm_rlcmac.dl.target_cell_3g_notif_reporting_quantity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccn_additionsr6_ba_used_3g,
{ "BA_USED_3G", "gsm_rlcmac.dl.pccn_additionsr6_ba_used_3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccn_additionsr6_n_3g,
{ "N_3G", "gsm_rlcmac.dl.pccn_additionsr6_n_3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_notification_ba_ind,
{ "BA_IND", "gsm_rlcmac.ul.pccn_ba_ind",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_notification_pmo_used,
{ "PMO_USED", "gsm_rlcmac.ul.pccn_pmo_used",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_notification_pccn_sending,
{ "PCCN_SENDING", "gsm_rlcmac.ul.pccn_pccn_sending",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_notification_lte_reporting_quantity,
{ "REPORTING_QUANTITY", "gsm_rlcmac.ul.pccn_lte_reporting_quantity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_ccn_meas_rpt_3g_ba_used,
{ "3G_BA_USED", "gsm_rlcmac.ul.pccn_eutran_ccn_meas_rpt_3g_ba_used",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_ccn_meas_rpt_num_eutran,
{ "N_EUTRAN", "gsm_rlcmac.ul.pccn_eutran_ccn_meas_rpt_num_eutran",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_ccn_meas_rpt_freq_idx,
{ "E-UTRAN_FREQUENCY_INDEX", "gsm_rlcmac.ul.pccn_eutran_ccn_meas_rpt_freq_idx",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_ccn_meas_cell_id,
{ "CELL IDENTITY", "gsm_rlcmac.ul.pccn_eutran_ccn_meas_rpt_cell_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_ccn_meas_rpt_quantity,
{ "REPORTING_QUANTITY", "gsm_rlcmac.ul.pccn_eutran_ccn_meas_rpt_rpt_quantity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_meas_rpt_cgi,
{ "UTRAN_CGI", "gsm_rlcmac.ul.utran_csg_meas_rpt_cgi",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_meas_rpt_csg_id,
{ "CSG_ID", "gsm_rlcmac.ul.utran_csg_meas_rpt_csg_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_meas_rpt_access_mode,
{ "Access Mode", "gsm_rlcmac.ul.utran_csg_meas_rpt_access_mode",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_meas_rpt_quantity,
{ "REPORTING_QUANTITY", "gsm_rlcmac.ul.utran_csg_meas_rpt_quantity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_meas_rpt_cgi,
{ "EUTRAN_CGI", "gsm_rlcmac.ul.eutran_csg_meas_rpt_cgi",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_meas_rpt_ta,
{ "Tracking Area Code", "gsm_rlcmac.ul.eutran_csg_meas_rpt_ta",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_meas_rpt_csg_id,
{ "CSG_ID", "gsm_rlcmac.ul.eutran_csg_meas_rpt_csg_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_meas_rpt_access_mode,
{ "Access Mode", "gsm_rlcmac.ul.eutran_csg_meas_rpt_access_mode",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_meas_rpt_quantity,
{ "REPORTING_QUANTITY", "gsm_rlcmac.ul.eutran_csg_meas_rpt_quantity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_continue_arfcn,
{ "ARFCN", "gsm_rlcmac.dl.pccc_arfcn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_continue_bsic,
{ "BSIC", "gsm_rlcmac.dl.pccc_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_continue_container_id,
{ "CONTAINER_ID", "gsm_rlcmac.dl.pccc_container_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pncd_container_with_id_bsic,
{ "BSIC", "gsm_rlcmac.dl.pncd_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pncd_container_with_id_container,
{ "CONTAINER", "gsm_rlcmac.dl.pncd_with_id_container",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pncd_container_without_id_container,
{ "CONTAINER", "gsm_rlcmac.dl.pncd_without_id_container",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pncd_container_choice,
{ "PNCD_CONTAINER Choice", "gsm_rlcmac.dl.pncd_container_choice",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_neighbour_cell_data_container_id,
{ "CONTAINER_ID", "gsm_rlcmac.dl.pncd_container_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_neighbour_cell_data_spare,
{ "spare", "gsm_rlcmac.dl.pncd_spare",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_neighbour_cell_data_container_index,
{ "CONTAINER_INDEX", "gsm_rlcmac.dl.pncd_container_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_serving_cell_data_spare,
{ "spare", "gsm_rlcmac.dl.pscd_spare",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_serving_cell_data_container_index,
{ "CONTAINER_INDEX", "gsm_rlcmac.dl.pscd_container_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_serving_cell_data_container,
{ "CONTAINER", "gsm_rlcmac.dl.pscd_container",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_servingcelldata_rxlev_serving_cell,
{ "RXLEV_SERVING_CELL", "gsm_rlcmac.dl.servingcelldata_rxlev_serving_cell",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeated_invalid_bsic_info_bcch_freq_ncell,
{ "BCCH_FREQ_NCELL", "gsm_rlcmac.dl.repeated_invalid_bsic_info_bcch_freq_ncell",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeated_invalid_bsic_info_bsic,
{ "BSIC", "gsm_rlcmac.dl.repeated_invalid_bsic_info_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeated_invalid_bsic_info_rxlev_ncell,
{ "RXLEV_NCELL", "gsm_rlcmac.dl.repeated_invalid_bsic_info_rxlev_ncell",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_reporting_quantity_reporting_quantity,
{ "REPORTING_QUANTITY", "gsm_rlcmac.dl.repeated_invalid_bsic_info_reporting_quantity",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurementreport_nc_mode,
{ "NC_MODE", "gsm_rlcmac.dl.nc_measurementreport_nc_mode",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurementreport_pmo_used,
{ "PMO_USED", "gsm_rlcmac.dl.nc_measurementreport_pmo_used",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurementreport_scale,
{ "SCALE", "gsm_rlcmac.dl.nc_measurementreport_scale",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_globaltimeslotdescription_ms_timeslotallocation,
{ "MS_TimeslotAllocation", "gsm_rlcmac.dl.pho_ms_timeslotallocation",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_usf_1_7_usf,
{ "USF", "gsm_rlcmac.dl.pho_usf",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_usf_allocationarray_usf_0,
{ "USF_0", "gsm_rlcmac.dl.pho_usf_0",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_description_linkqualitymeasurementmode,
{ "LinkQualityMeasurementMode", "gsm_rlcmac.dl.linkqualitymeasurementmode",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nas_container_nas_containerlength,
{ "NAS_ContainerLength", "gsm_rlcmac.dl.nas_containerlength",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nas_container_nas_container,
{ "NAS_Container", "gsm_rlcmac.dl.nas_container",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ps_handoverto_utran_payload_rrc_containerlength,
{ "RRC_ContainerLength", "gsm_rlcmac.dl.ps_handoverto_utran_payload_rrc_containerlength",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ps_handoverto_utran_payload_rrc_container,
{ "RRC_Container", "gsm_rlcmac.dl.ps_handoverto_utran_payload_rrc_container",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_handoverreference,
{ "HandoverReference", "gsm_rlcmac.dl.pho_radioresources_handoverreference",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_si,
{ "SI", "gsm_rlcmac.dl.pho_radioresources_si",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_nci,
{ "NCI", "gsm_rlcmac.dl.pho_radioresources_nci",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_bsic,
{ "BSIC", "gsm_rlcmac.dl.pho_radioresources_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_ccn_active,
{ "CCN_Active", "gsm_rlcmac.dl.pho_radioresources_ccn_active",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_ccn_active_3g,
{ "CCN_Active_3G", "gsm_rlcmac.dl.pho_radioresources_ccn_active_3g",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_networkcontrolorder,
{ "NetworkControlOrder", "gsm_rlcmac.dl.pho_radioresources_networkcontrolorder",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_rlc_reset,
{ "RLC_Reset", "gsm_rlcmac.dl.pho_radioresources_rlc_reset",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_uplinkcontroltimeslot,
{ "UplinkControlTimeslot", "gsm_rlcmac.dl.pho_radioresources_uplinkcontroltimeslot",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_handover_command_containerid,
{ "ContainerID", "gsm_rlcmac.dl.pho_containerid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_si1_restoctet_nch_position,
{ "NCH_Position", "gsm_rlcmac.dl.i1_restoctet_nch_position",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si1_restoctet_bandindicator,
{ "BandIndicator", "gsm_rlcmac.dl.i1_restoctet_bandindicator",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_selection_parameters_cbq,
{ "CBQ", "gsm_rlcmac.dl.selection_parameters_cbq",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_selection_parameters_cell_reselect_offset,
{ "CELL_RESELECT_OFFSET", "gsm_rlcmac.dl.cell_reselect_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_selection_parameters_temporary_offset,
{ "TEMPORARY_OFFSET", "gsm_rlcmac.dl.selection_parameters_temporary_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_selection_parameters_penalty_time,
{ "PENALTY_TIME", "gsm_rlcmac.dl.selection_parameters_penalty_time",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si3_rest_octet_power_offset,
{ "Power_Offset", "gsm_rlcmac.dl.si3_rest_octet_power_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si3_rest_octet_system_information_2ter_indicator,
{ "System_Information_2ter_Indicator", "gsm_rlcmac.dl.si3_rest_octet_system_information_2ter_indicator",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si3_rest_octet_early_classmark_sending_control,
{ "Early_Classmark_Sending_Control", "gsm_rlcmac.dl.si3_rest_octet_early_classmark_sending_control",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si3_rest_octet_where,
{ "WHERE", "gsm_rlcmac.dl.si3_rest_octet_where",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si3_rest_octet_ra_colour,
{ "RA_COLOUR", "gsm_rlcmac.dl.si3_rest_octet_ra_colour",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si13_position,
{ "SI13_POSITION", "gsm_rlcmac.dl.si13_position",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si3_rest_octet_ecs_restriction3g,
{ "ECS_Restriction3G", "gsm_rlcmac.dl.si3_rest_octet_ecs_restriction3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si3_rest_octet_si2quaterindicator,
{ "SI2quaterIndicator", "gsm_rlcmac.dl.si3_rest_octet_si2quaterindicator",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si4_rest_octet_power_offset,
{ "Power_Offset", "gsm_rlcmac.dl.si4_rest_octet_power_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si4_rest_octet_ra_colour,
{ "RA_COLOUR", "gsm_rlcmac.dl.si4_rest_octet_ra_colour",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pch_and_nch_info_pagingchannelrestructuring,
{ "PagingChannelRestructuring", "gsm_rlcmac.dl.pch_and_nch_info_pagingchannelrestructuring",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pch_and_nch_info_nln_sacch,
{ "NLN_SACCH", "gsm_rlcmac.dl.pch_and_nch_info_nln_sacch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pch_and_nch_info_callpriority,
{ "CallPriority", "gsm_rlcmac.dl.pch_and_nch_info_callpriority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si6_restoctet_vbs_vgcs_options,
{ "VBS_VGCS_Options", "gsm_rlcmac.dl.si6_restoctet_vbs_vgcs_options",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si6_restoctet_max_lapdm,
{ "MAX_LAPDm", "gsm_rlcmac.dl.si6_restoctet_max_lapdm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si6_restoctet_bandindicator,
{ "BandIndicator", "gsm_rlcmac.dl.si6_restoctet_bandindicator",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_packet_system_info_type1_pbcch_change_mark,
{ "PBCCH_CHANGE_MARK", "gsm_rlcmac.dl.psi1_pbcch_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type1_psi_change_field,
{ "PSI_CHANGE_FIELD", "gsm_rlcmac.dl.psi1_psi_change_field",
FT_UINT8, BASE_DEC, VALS(gsm_rlcmac_psi_change_field_vals), 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type1_psi1_repeat_period,
{ "PSI1_REPEAT_PERIOD", "gsm_rlcmac.dl.psi1_psi1_repeat_period",
FT_UINT8, BASE_DEC, VALS(gsm_rlcmac_val_plus_1_vals), 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type1_psi_count_lr,
{ "PSI_COUNT_LR", "gsm_rlcmac.dl.psi1_psi_count_lr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type1_psi_count_hr,
{ "PSI_COUNT_HR", "gsm_rlcmac.dl.psi1_psi_count_hr",
FT_UINT8, BASE_DEC, VALS(gsm_rlcmac_val_plus_1_vals), 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type1_measurement_order,
{ "MEASUREMENT_ORDER", "gsm_rlcmac.dl.psi1_measurement_order",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_rlcmac_psi1_measurement_order_value), 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type1_psi_status_ind,
{ "PSI_STATUS_IND", "gsm_rlcmac.dl.psi1_psi_status_ind",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type1_mscr,
{ "MSCR", "gsm_rlcmac.dl.psi1_mscr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type1_band_indicator,
{ "BAND_INDICATOR", "gsm_rlcmac.dl.psi1_band_indicator",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type1_lb_ms_txpwr_max_ccch,
{ "LB_MS_TXPWR_MAX_CCCH", "gsm_rlcmac.dl.psi1_lb_ms_txpwr_max_ccch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rai,
{ "RAI", "gsm_rlcmac.rai",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccch_org_bs_pcc_rel,
{ "BS_PCC_REL", "gsm_rlcmac.dl.pccch_org_bs_pcc_rel",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccch_org_pbcch_blks,
{ "PBCCH_BLKS", "gsm_rlcmac.dl.pccch_org_pbcch_blks",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccch_org_pag_blks_res,
{ "PAG_BLKS_RES", "gsm_rlcmac.dl.pccch_org_pag_blks_res",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccch_org_prach_blks,
{ "PRACH_BLKS", "gsm_rlcmac.dl.pccch_org_prach_blks",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type2_change_mark,
{ "PSI2_CHANGE_MARK", "gsm_rlcmac.dl.psi2_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type2_index,
{ "PSI2_INDEX", "gsm_rlcmac.dl.psi2_INDEX",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type2_count,
{ "PSI2_COUNT", "gsm_rlcmac.dl.psi2_COUNT",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_id_cell_identity,
{ "CELL_IDENTITY", "gsm_rlcmac.dl.cell_id_cell_identity",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_lai_lac,
{ "LAC", "gsm_rlcmac.dl.lai_lac",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_plmn_mcc1,
{ "MCC1", "gsm_rlcmac.dl.plmn_mcc1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_plmn_mcc2,
{ "MCC2", "gsm_rlcmac.dl.plmn_mcc2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_plmn_mcc3,
{ "MCC3", "gsm_rlcmac.dl.plmn_mcc3",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_plmn_mnc1,
{ "MNC1", "gsm_rlcmac.dl.plmn_mnc1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_plmn_mnc2,
{ "MNC2", "gsm_rlcmac.dl.plmn_mnc2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_plmn_mnc3,
{ "MNC3", "gsm_rlcmac.dl.plmn_mnc3",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_att,
{ "ATT", "gsm_rlcmac.dl.non_gprs_cell_opt_att",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_t3212,
{ "T3212", "gsm_rlcmac.dl.non_gprs_cell_opt_t3212",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_neci,
{ "NECI", "gsm_rlcmac.dl.non_gprs_cell_opt_neci",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_pwrc,
{ "PWRC", "gsm_rlcmac.dl.non_gprs_cell_opt_pwrc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_dtx,
{ "DTX", "gsm_rlcmac.dl.non_gprs_cell_opt_dtx",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_radio_link_timeout,
{ "RADIO_LINK_TIMEOUT", "gsm_rlcmac.dl.non_gprs_cell_opt_radio_link_timeout",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_bs_ag_blks_res,
{ "BS_AG_BLKS_RES", "gsm_rlcmac.dl.non_gprs_cell_opt_bs_ag_blks_res",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_ccch_conf,
{ "CCCH_CONF", "gsm_rlcmac.dl.non_gprs_cell_opt_ccch_conf",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_bs_pa_mfrms,
{ "BS_PA_MFRMS", "gsm_rlcmac.dl.non_gprs_cell_opt_bs_pa_mfrms",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_max_retrans,
{ "MAX_RETRANS", "gsm_rlcmac.dl.non_gprs_cell_opt_max_retrans",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_tx_int,
{ "TX_INTEGER", "gsm_rlcmac.dl.non_gprs_cell_opt_tx_integer",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_ec,
{ "EC", "gsm_rlcmac.dl.non_gprs_cell_opt_ec",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_non_gprs_cell_opt_ms_txpwr_max_ccch,
{ "MS_TXPWR_MAX_CCCH", "gsm_rlcmac.dl.non_gprs_cell_opt_ms_txpwr_max_ccch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_packet_non_gprs_cell_opt_ext_len,
{ "Extention_Length", "gsm_rlcmac.dl.non_gprs_cell_opt_extention_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#endif
{ &hf_packet_system_info_type2_ref_freq_num,
{ "RFL_NUMBER", "gsm_rlcmac.dl.psi2_ref_freq_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type2_ref_freq_length,
{ "Length", "gsm_rlcmac.dl.psi2_ref_freq_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type2_ref_freq,
{ "Contents", "gsm_rlcmac.dl.psi2_ref_freq",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
}, { &hf_packet_system_info_type2_ma_number,
{ "MA_NUMBER", "gsm_rlcmac.dl.psi2_ma_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type2_non_hopping_timeslot,
{ "TIMESLOT", "gsm_rlcmac.dl.psi2_pccch_desc_non_hopping_timeslot",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type2_hopping_ma_num,
{ "MA_NUMBER", "gsm_rlcmac.dl.psi2_pccch_desc_hopping_ma_num",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type2_hopping_timeslot,
{ "TIMESLOT", "gsm_rlcmac.dl.psi2_pccch_desc_hopping_timeslot",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type3_change_mark,
{ "PSI3_CHANGE_MARK", "gsm_rlcmac.dl.psi3_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type3_bis_count,
{ "PSI3_BIS_COUNT", "gsm_rlcmac.dl.psi3_bis_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_scell_param_gprs_rxlev_access_min,
{ "RXLEV_ACCESS_MIN", "gsm_rlcmac.dl.psi3_scell_param_gprs_rxlev_access_min",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_scell_param_gprs_ms_txpwr_max_cch,
{ "MS_TXPWR_MAX_CCH", "gsm_rlcmac.dl.psi3_scell_param_ms_txpwr_max_cch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_scell_param_multiband_reporting,
{ "MULTIBAND_REPORTING", "gsm_rlcmac.dl.psi3_scell_param_multiband_reporting",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_gen_cell_sel_gprs_cell_resl_hyst,
{ "GPRS_CELL_RESELECT_HYSTERESIS", "gsm_rlcmac.dl.psi3_gen_cell_sel_resel_hyst",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_gen_cell_sel_c31_hyst,
{ "C31_HYST", "gsm_rlcmac.dl.psi3_gen_cell_sel_c31_hyst",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_gen_cell_sel_c32_qual,
{ "C32_QUAL", "gsm_rlcmac.dl.psi3_gen_cell_sel_c32_qual",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_gen_cell_sel_t_resel,
{ "T_RESEL", "gsm_rlcmac.dl.psi3_gen_cell_sel_t_resel",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_gen_cell_sel_ra_resel_hyst,
{ "RA_RESELECT_HYSTERESIS", "gsm_rlcmac.dl.psi3_gen_cell_sel_ra_resel_hyst",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_cell_sel_bsic,
{ "BSIC", "gsm_rlcmac.dl.psi3_compact_cell_sel_bsic",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_cell_sel_same_as_scell,
{ "SAME_AS_SERVING_CELL", "gsm_rlcmac.dl.psi3_compact_cell_sel_same_as_scell",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_cell_sel_gprs_rxlev_access_min,
{ "GPRS_RXLEV_ACCESS_MIN", "gsm_rlcmac.dl.psi3_compact_cell_sel_gprs_rxlev_access_min",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_cell_sel_gprs_ms_txpwr_max_cch,
{ "GPRS_MS_TXPWR_MAX_CCH", "gsm_rlcmac.dl.psi3_compact_cell_sel_gprs_ms_txpwr_cch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_cell_sel_gprs_temp_offset,
{ "GPRS_TEMP_OFFSET", "gsm_rlcmac.dl.psi3_compact_cell_sel_gprs_temp_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_cell_sel_gprs_penalty_time,
{ "GPRS_PENALTY_TIME", "gsm_rlcmac.dl.psi3_compact_cell_sel_gprs_panelty_time",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_cell_sel_gprs_resel_offset,
{ "GPRS_RESEL_OFFSET", "gsm_rlcmac.dl.psi3_compact_cell_sel_gprs_resel_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_cell_sel_time_group,
{ "TIME_GROUP", "gsm_rlcmac.dl.psi3_compact_cell_sel_time_group",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_cell_sel_guar_const_pwr_blks,
{ "GUAR_CONSTANT_PWR_BLKS", "gsm_rlcmac.dl.psi3_compact_cell_sel_guar_const_pwr_blks",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_neighbour_cell_param_freq_diff,
{ "FREQUENCY_DIFF", "gsm_rlcmac.dl.packet_compact_neighbour_cell_param_freq_diff",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_ncell_param_start_freq,
{ "START_FREQUENCY", "gsm_rlcmac.dl.psi3_compact_ncell_start_freq",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_ncell_param_nr_of_remaining_cells,
{ "NR_OF_REMAINING_CELLS", "gsm_rlcmac.dl.psi3_compact_ncell_nr_of_remaining_cells",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_compact_ncell_param_freq_diff_length,
{ "FREQ_DIFF_LENGTH", "gsm_rlcmac.dl.psi3_compact_ncell_freq_diff_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_psi5_repquantfdd,
{ "FDD_REP_QUANT", "gsm_rlcmac.dl.psi5_rep_quant_fdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_psi5_multiratreportingfdd,
{ "FDD_MULTIRAT_REPORTING", "gsm_rlcmac.dl.psi5_multirat_reporting_fdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_psi5_reportingoffsetfdd,
{ "FDD_REPORTING_OFFSET", "gsm_rlcmac.dl.psi5_reporting_offset_fdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_psi5_reportingthresholdfdd,
{ "FDD_REPORTING_THRESHOLD", "gsm_rlcmac.dl.psi5_reporting_threshold_fdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_psi5_multiratreportingtdd,
{ "TDD_MULTIRAT_REPORTING", "gsm_rlcmac.dl.psi5_multirat_reporting_tdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_psi5_reportingoffsettdd,
{ "TDD_REPORTING_OFFSET", "gsm_rlcmac.dl.psi5_reporting_offset_tdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_psi5_reportingthresholdtdd,
{ "TDD_REPORTING_THRESHOLD", "gsm_rlcmac.dl.psi5_reporting_threshold_tdd",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_reporting_parameters_report_type,
{ "Report_Type", "gsm_rlcmac.dl.psi5_enh_reporting_param_report_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_reporting_parameters_reporting_rate,
{ "REPORTING_RATE", "gsm_rlcmac.dl.psi5_enh_reporting_param_reporting_rate",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_reporting_parameters_invalid_bsic_reporting,
{ "INVALID_BSIC_REPORTING", "gsm_rlcmac.dl.psi5_enh_reporting_param_invalid_bsic_reporting",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_reporting_parameters_ncc_permitted,
{ "NCC_PERMITTED", "gsm_rlcmac.dl.psi5_enh_reporting_param_ncc_permitted",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type5_change_mark,
{ "PSI5_CHANGE_MARK", "gsm_rlcmac.dl.psi5_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type5_index,
{ "PSI5_INDEX", "gsm_rlcmac.dl.psi5_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type5_count,
{ "PSI5_COUNT", "gsm_rlcmac.dl.psi5_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type13_lb_ms_mxpwr_max_cch,
{ "LB_MS_TXPWR_MAX_CCH", "gsm_rlcmac.dl.psi13_lb_ms_txpwr_max_cch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_system_info_type13_si2n_support,
{ "SI2n_SUPPORT", "gsm_rlcmac.dl.psi13_si2n_support",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_gprs,
{ "PU_AckNack_GPRS", "gsm_rlcmac.pu_acknack_gprs",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_egrps,
{ "PU_AckNack_EGPRS", "gsm_rlcmac.pu_acknack_egrps",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack,
{ "Packet_Ack_Nack", "gsm_rlcmac.pu_acknack",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_frequency_parameters,
{ "Frequency_Parameters", "gsm_rlcmac.frequency_parameters",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dynamic_allocation,
{ "Dynamic_Allocation", "gsm_rlcmac.dynamic_allocation",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_grps,
{ "PUA_GPRS", "gsm_rlcmac.pua_grps",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_egprs,
{ "PUA_GPRS", "gsm_rlcmac.pua_egprs",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_assignment,
{ "Packet_Uplink_Assignment", "gsm_rlcmac.pua_assignment",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_downlink_assignment,
{ "Packet_Downlink_Assignment", "gsm_rlcmac.packet_downlink_assignment",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_page_request_tfb_establishment,
{ "Page_request_for_TBF_establishment", "gsm_rlcmac.page_request_tfb_establishment",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_page_request_rr_conn,
{ "Page_request_for_RR_conn", "gsm_rlcmac.page_request_rr_conn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeated_page_info,
{ "Repeated_Page_info", "gsm_rlcmac.repeated_page_info",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_pdch_release,
{ "Packet_PDCH_Release", "gsm_rlcmac.packet_pdch_release",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_global_timing_or_power,
{ "GlobalTimingOrPower", "gsm_rlcmac.global_timing_or_power",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ppc_timing_advance,
{ "Packet_Power_Control_Timing_Advance", "gsm_rlcmac.ppc_timing_advance",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_queueing_notif,
{ "Packet_Queueing_Notification", "gsm_rlcmac.packet_queueing_notif",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_egprs,
{ "PTR_EGPRS", "gsm_rlcmac.ptr_egprs",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_timeslot_reconfigure,
{ "Packet_Timeslot_Reconfigure", "gsm_rlcmac.packet_timeslot_reconfigure",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_si_pbcch_location,
{ "SI13_PBCCH_Location", "gsm_rlcmac.si_pbcch_location",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pmo,
{ "ENH_Measurement_Parameters_PMO", "gsm_rlcmac.enh_measurement_parameters_pmo",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pcco,
{ "ENH_Measurement_Parameters_PCCO", "gsm_rlcmac.enh_measurement_parameters_pcco",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rept_eutran_enh_cell_resel_param,
{ "Rept_EUTRAN_Enh_Cell_Resel_Param", "gsm_rlcmac.rept_eutran_enh_cell_resel_param",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_utran_priority_param,
{ "Repeated_Individual_UTRAN_Priority_Parameters", "gsm_rlcmac.idvd_utran_priority_param",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_idvd_priorities,
{ "Individual_Priorities", "gsm_rlcmac.idvd_priorities",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lsa_id_info_element,
{ "LSA_ID_Info_Element", "gsm_rlcmac.lsa_id_info_element",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g,
{ "Target_Cell_3G", "gsm_rlcmac.target_cell_3g",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_order,
{ "Packet_Cell_Change_Order", "gsm_rlcmac.packet_cell_change_order",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_serving_cell_data,
{ "Serving_Cell_Data", "gsm_rlcmac.serving_cell_data",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_nc_measurement_report,
{ "ENH_NC_Measurement_Report", "gsm_rlcmac.enh_nc_measurement_report",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr99,
{ "PMR_AdditionsR99", "gsm_rlcmac.pmr_additionsr99",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_measurement_report,
{ "Packet_Measurement_Report", "gsm_rlcmac.packet_measurement_report",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_measurement_order,
{ "Packet_Measurement_Order", "gsm_rlcmac.packet_measurement_order",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ccn_measurement_report,
{ "CCN_Measurement_Report", "gsm_rlcmac.ccn_measurement_report",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_csg_notif,
{ "Target_Cell_CSG_Notif", "gsm_rlcmac.target_cell_csg_notif",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_other_rat2_notif,
{ "Target_Other_RAT_2_Notif", "gsm_rlcmac.target_other_rat2_notif",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_other_rat_notif,
{ "Target_Other_RAT_Notif", "gsm_rlcmac.target_other_rat_notif",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell,
{ "Target_Cell", "gsm_rlcmac.target_cell",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_notification,
{ "Packet_Cell_Change_Notification", "gsm_rlcmac.packet_cell_change_notification",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_continue,
{ "Packet_Cell_Change_Continue", "gsm_rlcmac.packet_cell_change_continue",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_neighbour_cell_data,
{ "Packet_Neighbour_Cell_Data", "gsm_rlcmac.packet_neighbour_cell_data",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_serving_cell_data,
{ "Packet_Serving_Cell_Data", "gsm_rlcmac.packet_serving_cell_data",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_uplinkassignment,
{ "PHO_UplinkAssignment", "gsm_rlcmac.pho_uplinkassignment",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_global_timeslot_description,
{ "GlobalTimeslotDescription", "gsm_rlcmac.global_timeslot_description",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_gprs,
{ "PHO_GPRS", "gsm_rlcmac.pho_gprs",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_downlink_tbf,
{ "DownlinkTBF", "gsm_rlcmac.downlink_tbf",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radio_resources,
{ "PHO_RadioResources", "gsm_rlcmac.pho_radio_resources",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ps_handoverto_a_gb_modepayload,
{ "PS_HandoverTo_A_GB_ModePayload", "gsm_rlcmac.ps_handoverto_a_gb_modepayload",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_handover_command,
{ "Packet_Handover_Command", "gsm_rlcmac.packet_handover_command",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccch_description,
{ "PCCCH_Description", "gsm_rlcmac.pccch_description",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gen_cell_sel,
{ "Gen_Cell_Sel", "gsm_rlcmac.gen_cell_sel",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi3_additionr99,
{ "PSI3_AdditionR99", "gsm_rlcmac.psi3_additionr99",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi5,
{ "PSI5", "gsm_rlcmac.psi5",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi13,
{ "PSI13", "gsm_rlcmac.psi13",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_downlink_ack_nack_channel_request_description_exist,
{ "Exist_Channel_Request_Description", "gsm_rlcmac.packet_downlink_ack_nack.channel_request_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_pd_acknack_egprs_channelqualityreport_exist,
{ "Exist_EGPRS_ChannelQualityReport", "gsm_rlcmac.egprs_pd_acknack.egprs_channelqualityreport_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_pd_acknack_channelrequestdescription_exist,
{ "Exist_ChannelRequestDescription", "gsm_rlcmac.egprs_pd_acknack.channelrequestdescription_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_pd_acknack_extensionbits_exist,
{ "Exist_ExtensionBits", "gsm_rlcmac.egprs_pd_acknack.extensionbits_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_fdd_target_cell_bandwith_fdd_exist,
{ "Exist_Bandwith_FDD", "gsm_rlcmac.fdd_target_cell.bandwith_fdd_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_tdd_target_cell_bandwith_tdd_exist,
{ "Exist_Bandwith_TDD", "gsm_rlcmac.tdd_target_cell.bandwith_tdd_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_target_cell_measurement_bandwidth_exist,
{ "Exist_Measurement_Bandwidth", "gsm_rlcmac.eutran_target_cell.measurement_bandwidth_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_target_cell_plmn_id_exist,
{ "Exist_PLMN_ID", "gsm_rlcmac.utran_csg_target_cell.plmn_id_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_target_cell_plmn_id_exist,
{ "Exist_PLMN_ID", "gsm_rlcmac.eutran_csg_target_cell.plmn_id_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccf_additionsr9_utran_csg_target_cell_exist,
{ "Exist_UTRAN_CSG_Target_Cell", "gsm_rlcmac.pccf_additionsr9.utran_csg_target_cell_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccf_additionsr9_eutran_csg_target_cell_exist,
{ "Exist_EUTRAN_CSG_Target_Cell", "gsm_rlcmac.pccf_additionsr9.eutran_csg_target_cell_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccf_additionsr8_eutran_target_cell_exist,
{ "Exist_EUTRAN_Target_Cell", "gsm_rlcmac.pccf_additionsr8.eutran_target_cell_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccf_additionsr5_g_rnti_extention_exist,
{ "Exist_G_RNTI_extention", "gsm_rlcmac.pccf_additionsr5.g_rnti_extention_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccf_additionsr99_fdd_description_exist,
{ "Exist_FDD_Description", "gsm_rlcmac.pccf_additionsr99.fdd_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccf_additionsr99_tdd_description_exist,
{ "Exist_TDD_Description", "gsm_rlcmac.pccf_additionsr99.tdd_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_power_control_parameters_slot0_exist,
{ "Slot[0].Exist", "gsm_rlcmac.power_control_parameters.slot0_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_power_control_parameters_slot1_exist,
{ "Slot[1].Exist", "gsm_rlcmac.power_control_parameters.slot1_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_power_control_parameters_slot2_exist,
{ "Slot[2].Exist", "gsm_rlcmac.power_control_parameters.slot2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_power_control_parameters_slot3_exist,
{ "Slot[3].Exist", "gsm_rlcmac.power_control_parameters.slot3_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_power_control_parameters_slot4_exist,
{ "Slot[4].Exist", "gsm_rlcmac.power_control_parameters.slot4_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_power_control_parameters_slot5_exist,
{ "Slot[5].Exist", "gsm_rlcmac.power_control_parameters.slot5_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_power_control_parameters_slot6_exist,
{ "Slot[6].Exist", "gsm_rlcmac.power_control_parameters.slot6_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_power_control_parameters_slot7_exist,
{ "Slot[7].Exist", "gsm_rlcmac.power_control_parameters.slot7_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_gprs_additionsr99_packetextendedtimingadvance_exist,
{ "Exist_PacketExtendedTimingAdvance", "gsm_rlcmac.pu_acknack_gprs_additionsr99.packetextendedtimingadvance_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_gprs_common_uplink_ack_nack_data_exist_contention_resolution_tlli_exist,
{ "Common_Uplink_Ack_Nack_Data.Exist_CONTENTION_RESOLUTION_TLLI", "gsm_rlcmac.pu_acknack_gprs.common_uplink_ack_nack_data.exist_contention_resolution_tlli_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_gprs_common_uplink_ack_nack_data_exist_packet_timing_advance_exist,
{ "Common_Uplink_Ack_Nack_Data.Exist_Packet_Timing_Advance", "gsm_rlcmac.pu_acknack_gprs.common_uplink_ack_nack_data.exist_packet_timing_advance_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_gprs_common_uplink_ack_nack_data_exist_power_control_parameters_exist,
{ "Common_Uplink_Ack_Nack_Data.Exist_Power_Control_Parameters", "gsm_rlcmac.pu_acknack_gprs.common_uplink_ack_nack_data.exist_power_control_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_gprs_common_uplink_ack_nack_data_exist_extension_bits_exist,
{ "Common_Uplink_Ack_Nack_Data.Exist_Extension_Bits", "gsm_rlcmac.pu_acknack_gprs.common_uplink_ack_nack_data.exist_extension_bits_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_egprs_00_common_uplink_ack_nack_data_exist_contention_resolution_tlli_exist,
{ "Common_Uplink_Ack_Nack_Data.Exist_CONTENTION_RESOLUTION_TLLI", "gsm_rlcmac.pu_acknack_egprs_00.common_uplink_ack_nack_data.exist_contention_resolution_tlli_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_egprs_00_common_uplink_ack_nack_data_exist_packet_timing_advance_exist,
{ "Common_Uplink_Ack_Nack_Data.Exist_Packet_Timing_Advance", "gsm_rlcmac.pu_acknack_egprs_00.common_uplink_ack_nack_data.exist_packet_timing_advance_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_egprs_00_packet_extended_timing_advance_exist,
{ "Exist_Packet_Extended_Timing_Advance", "gsm_rlcmac.pu_acknack_egprs_00.packet_extended_timing_advance_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_egprs_00_common_uplink_ack_nack_data_exist_power_control_parameters_exist,
{ "Common_Uplink_Ack_Nack_Data.Exist_Power_Control_Parameters", "gsm_rlcmac.pu_acknack_egprs_00.common_uplink_ack_nack_data.exist_power_control_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pu_acknack_egprs_00_common_uplink_ack_nack_data_exist_extension_bits_exist,
{ "Common_Uplink_Ack_Nack_Data.Exist_Extension_Bits", "gsm_rlcmac.pu_acknack_egprs_00.common_uplink_ack_nack_data.exist_extension_bits_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_change_mark_change_mark_2_exist,
{ "Exist_CHANGE_MARK_2", "gsm_rlcmac.change_mark.change_mark_2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_indirect_encoding_change_mark_exist,
{ "Exist_CHANGE_MARK", "gsm_rlcmac.indirect_encoding.change_mark_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timeslot_allocation_exist_exist,
{ "Exist", "gsm_rlcmac.timeslot_allocation.exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timeslot_allocation_power_ctrl_param_slot0_exist,
{ "Slot[0].Exist", "gsm_rlcmac.timeslot_allocation_power_ctrl_param.slot0_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timeslot_allocation_power_ctrl_param_slot1_exist,
{ "Slot[1].Exist", "gsm_rlcmac.timeslot_allocation_power_ctrl_param.slot1_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timeslot_allocation_power_ctrl_param_slot2_exist,
{ "Slot[2].Exist", "gsm_rlcmac.timeslot_allocation_power_ctrl_param.slot2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timeslot_allocation_power_ctrl_param_slot3_exist,
{ "Slot[3].Exist", "gsm_rlcmac.timeslot_allocation_power_ctrl_param.slot3_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timeslot_allocation_power_ctrl_param_slot4_exist,
{ "Slot[4].Exist", "gsm_rlcmac.timeslot_allocation_power_ctrl_param.slot4_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timeslot_allocation_power_ctrl_param_slot5_exist,
{ "Slot[5].Exist", "gsm_rlcmac.timeslot_allocation_power_ctrl_param.slot5_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timeslot_allocation_power_ctrl_param_slot6_exist,
{ "Slot[6].Exist", "gsm_rlcmac.timeslot_allocation_power_ctrl_param.slot6_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_timeslot_allocation_power_ctrl_param_slot7_exist,
{ "Slot[7].Exist", "gsm_rlcmac.timeslot_allocation_power_ctrl_param.slot7_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dynamic_allocation_p0_exist,
{ "Exist_P0", "gsm_rlcmac.dynamic_allocation.p0_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dynamic_allocation_uplink_tfi_assignment_exist,
{ "Exist_UPLINK_TFI_ASSIGNMENT", "gsm_rlcmac.dynamic_allocation.uplink_tfi_assignment_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dynamic_allocation_rlc_data_blocks_granted_exist,
{ "Exist_RLC_DATA_BLOCKS_GRANTED", "gsm_rlcmac.dynamic_allocation.rlc_data_blocks_granted_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_dynamic_allocation_tbf_starting_time_exist,
{ "Exist_TBF_Starting_Time", "gsm_rlcmac.dynamic_allocation.tbf_starting_time_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_single_block_allocation_alpha_and_gamma_tn_exist,
{ "Exist_ALPHA_and_GAMMA_TN", "gsm_rlcmac.single_block_allocation.alpha_and_gamma_tn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_single_block_allocation_p0_exist,
{ "Exist_P0", "gsm_rlcmac.single_block_allocation.p0_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_gprs_additionsr99_packet_extended_timing_advance_exist,
{ "Exist_Packet_Extended_Timing_Advance", "gsm_rlcmac.pua_gprs_additionsr99.packet_extended_timing_advance_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_gprs_frequency_parameters_exist,
{ "Exist_Frequency_Parameters", "gsm_rlcmac.pua_gprs.frequency_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_compact_reducedma_maio_2_exist,
{ "Exist_MAIO_2", "gsm_rlcmac.compact_reducedma.maio_2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multiblock_allocation_alpha_gamma_tn_exist,
{ "Exist_ALPHA_GAMMA_TN", "gsm_rlcmac.multiblock_allocation.alpha_gamma_tn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multiblock_allocation_p0_bts_pwr_ctrl_pr_mode_exist,
{ "Exist_P0_BTS_PWR_CTRL_PR_MODE", "gsm_rlcmac.multiblock_allocation.p0_bts_pwr_ctrl_pr_mode_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_egprs_00_contention_resolution_tlli_exist,
{ "Exist_CONTENTION_RESOLUTION_TLLI", "gsm_rlcmac.pua_egprs_00.contention_resolution_tlli_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_egprs_00_compact_reducedma_exist,
{ "Exist_COMPACT_ReducedMA", "gsm_rlcmac.pua_egprs_00.compact_reducedma_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_egprs_00_bep_period2_exist,
{ "Exist_BEP_PERIOD2", "gsm_rlcmac.pua_egprs_00.bep_period2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_egprs_00_packet_extended_timing_advance_exist,
{ "Exist_Packet_Extended_Timing_Advance", "gsm_rlcmac.pua_egprs_00.packet_extended_timing_advance_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pua_egprs_00_frequency_parameters_exist,
{ "Exist_Frequency_Parameters", "gsm_rlcmac.pua_egprs_00.frequency_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pda_additionsr99_egprs_params_exist,
{ "Exist_EGPRS_Params", "gsm_rlcmac.pda_additionsr99.egprs_params_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pda_additionsr99_bep_period2_exist,
{ "Exist_BEP_PERIOD2", "gsm_rlcmac.pda_additionsr99.bep_period2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pda_additionsr99_packet_extended_timing_advance_exist,
{ "Exist_Packet_Extended_Timing_Advance", "gsm_rlcmac.pda_additionsr99.packet_extended_timing_advance_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pda_additionsr99_compact_reducedma_exist,
{ "Exist_COMPACT_ReducedMA", "gsm_rlcmac.pda_additionsr99.compact_reducedma_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_downlink_assignment_p0_and_bts_pwr_ctrl_mode_exist,
{ "Exist_P0_and_BTS_PWR_CTRL_MODE", "gsm_rlcmac.packet_downlink_assignment.p0_and_bts_pwr_ctrl_mode_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_downlink_assignment_frequency_parameters_exist,
{ "Exist_Frequency_Parameters", "gsm_rlcmac.packet_downlink_assignment.frequency_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_downlink_assignment_downlink_tfi_assignment_exist,
{ "Exist_DOWNLINK_TFI_ASSIGNMENT", "gsm_rlcmac.packet_downlink_assignment.downlink_tfi_assignment_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_downlink_assignment_power_control_parameters_exist,
{ "Exist_Power_Control_Parameters", "gsm_rlcmac.packet_downlink_assignment.power_control_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_downlink_assignment_tbf_starting_time_exist,
{ "Exist_TBF_Starting_Time", "gsm_rlcmac.packet_downlink_assignment.tbf_starting_time_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_downlink_assignment_measurement_mapping_exist,
{ "Exist_Measurement_Mapping", "gsm_rlcmac.packet_downlink_assignment.measurement_mapping_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_page_request_for_rr_conn_emlpp_priority_exist,
{ "Exist_eMLPP_PRIORITY", "gsm_rlcmac.page_request_for_rr_conn.emlpp_priority_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_paging_request_nln_exist,
{ "Exist_NLN", "gsm_rlcmac.packet_paging_request.nln_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_power_control_timing_advance_global_power_control_parameters_exist,
{ "Exist_Global_Power_Control_Parameters", "gsm_rlcmac.packet_power_control_timing_advance.global_power_control_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_trdynamic_allocation_p0_exist,
{ "Exist_P0", "gsm_rlcmac.trdynamic_allocation.p0_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_trdynamic_allocation_rlc_data_blocks_granted_exist,
{ "Exist_RLC_DATA_BLOCKS_GRANTED", "gsm_rlcmac.trdynamic_allocation.rlc_data_blocks_granted_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_trdynamic_allocation_tbf_starting_time_exist,
{ "Exist_TBF_Starting_Time", "gsm_rlcmac.trdynamic_allocation.tbf_starting_time_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_gprs_additionsr99_packet_extended_timing_advance_exist,
{ "Exist_Packet_Extended_Timing_Advance", "gsm_rlcmac.ptr_gprs_additionsr99.packet_extended_timing_advance_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_gprs_common_timeslot_reconfigure_data_exist_downlink_tfi_assignment_exist,
{ "Common_Timeslot_Reconfigure_Data.Exist_DOWNLINK_TFI_ASSIGNMENT", "gsm_rlcmac.ptr_gprs.common_timeslot_reconfigure_data.exist_downlink_tfi_assignment_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_gprs_common_timeslot_reconfigure_data_exist_uplink_tfi_assignment_exist,
{ "Common_Timeslot_Reconfigure_Data.Exist_UPLINK_TFI_ASSIGNMENT", "gsm_rlcmac.ptr_gprs.common_timeslot_reconfigure_data.exist_uplink_tfi_assignment_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_gprs_common_timeslot_reconfigure_data_exist_frequency_parameters_exist,
{ "Common_Timeslot_Reconfigure_Data.Exist_Frequency_Parameters", "gsm_rlcmac.ptr_gprs.common_timeslot_reconfigure_data.exist_frequency_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_egprs_00_compact_reducedma_exist,
{ "Exist_COMPACT_ReducedMA", "gsm_rlcmac.ptr_egprs_00.compact_reducedma_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_egprs_00_downlink_egprs_windowsize_exist,
{ "Exist_DOWNLINK_EGPRS_WindowSize", "gsm_rlcmac.ptr_egprs_00.downlink_egprs_windowsize_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_egprs_00_uplink_egprs_windowsize_exist,
{ "Exist_UPLINK_EGPRS_WindowSize", "gsm_rlcmac.ptr_egprs_00.uplink_egprs_windowsize_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_egprs_00_packet_extended_timing_advance_exist,
{ "Exist_Packet_Extended_Timing_Advance", "gsm_rlcmac.ptr_egprs_00.packet_extended_timing_advance_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_egprs_00_common_timeslot_reconfigure_data_exist_downlink_tfi_assignment_exist,
{ "Common_Timeslot_Reconfigure_Data.Exist_DOWNLINK_TFI_ASSIGNMENT", "gsm_rlcmac.ptr_egprs_00.common_timeslot_reconfigure_data.exist_downlink_tfi_assignment_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_egprs_00_common_timeslot_reconfigure_data_exist_uplink_tfi_assignment_exist,
{ "Common_Timeslot_Reconfigure_Data.Exist_UPLINK_TFI_ASSIGNMENT", "gsm_rlcmac.ptr_egprs_00.common_timeslot_reconfigure_data.exist_uplink_tfi_assignment_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ptr_egprs_00_common_timeslot_reconfigure_data_exist_frequency_parameters_exist,
{ "Common_Timeslot_Reconfigure_Data.Exist_Frequency_Parameters", "gsm_rlcmac.ptr_egprs_00.common_timeslot_reconfigure_data.exist_frequency_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_rxlev_and_txpwr_exist,
{ "Exist_RXLEV_and_TXPWR", "gsm_rlcmac.cell_selection.rxlev_and_txpwr_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_offset_and_time_exist,
{ "Exist_OFFSET_and_TIME", "gsm_rlcmac.cell_selection.offset_and_time_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_gprs_reselect_offset_exist,
{ "Exist_GPRS_RESELECT_OFFSET", "gsm_rlcmac.cell_selection.gprs_reselect_offset_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_hcs_exist,
{ "Exist_HCS", "gsm_rlcmac.cell_selection.hcs_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_si13_pbcch_location_exist,
{ "Exist_SI13_PBCCH_Location", "gsm_rlcmac.cell_selection.si13_pbcch_location_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_2_rxlev_and_txpwr_exist,
{ "Exist_RXLEV_and_TXPWR", "gsm_rlcmac.cell_selection_2.rxlev_and_txpwr_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_2_offset_and_time_exist,
{ "Exist_OFFSET_and_TIME", "gsm_rlcmac.cell_selection_2.offset_and_time_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_2_gprs_reselect_offset_exist,
{ "Exist_GPRS_RESELECT_OFFSET", "gsm_rlcmac.cell_selection_2.gprs_reselect_offset_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_2_hcs_exist,
{ "Exist_HCS", "gsm_rlcmac.cell_selection_2.hcs_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cell_selection_2_si13_pbcch_location_exist,
{ "Exist_SI13_PBCCH_Location", "gsm_rlcmac.cell_selection_2.si13_pbcch_location_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_reject_wait_exist,
{ "Exist_Wait", "gsm_rlcmac.reject.wait_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cellselectionparamswithfreqdiff_cellselectionparams_exist,
{ "Exist_CellSelectionParams", "gsm_rlcmac.cellselectionparamswithfreqdiff.cellselectionparams_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_add_frequency_list_cell_selection_exist,
{ "Exist_Cell_Selection", "gsm_rlcmac.add_frequency_list.cell_selection_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_frequency_list_removed_freq_exist,
{ "Exist_REMOVED_FREQ", "gsm_rlcmac.nc_frequency_list.removed_freq_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_parameters_nc_exist,
{ "Exist_NC", "gsm_rlcmac.nc_measurement_parameters.nc_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_parameters_with_frequency_list_nc_exist,
{ "Exist_NC", "gsm_rlcmac.nc_measurement_parameters_with_frequency_list.nc_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurement_parameters_with_frequency_list_nc_frequency_list_exist,
{ "Exist_NC_FREQUENCY_LIST", "gsm_rlcmac.nc_measurement_parameters_with_frequency_list.nc_frequency_list_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams_pmo_pcco_multi_band_reporting_exist,
{ "Exist_MULTI_BAND_REPORTING", "gsm_rlcmac.gprsmeasurementparams_pmo_pcco.multi_band_reporting_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams_pmo_pcco_serving_band_reporting_exist,
{ "Exist_SERVING_BAND_REPORTING", "gsm_rlcmac.gprsmeasurementparams_pmo_pcco.serving_band_reporting_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams_pmo_pcco_offsetthreshold900_exist,
{ "Exist_OffsetThreshold900", "gsm_rlcmac.gprsmeasurementparams_pmo_pcco.offsetthreshold900_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams_pmo_pcco_offsetthreshold1800_exist,
{ "Exist_OffsetThreshold1800", "gsm_rlcmac.gprsmeasurementparams_pmo_pcco.offsetthreshold1800_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams_pmo_pcco_offsetthreshold400_exist,
{ "Exist_OffsetThreshold400", "gsm_rlcmac.gprsmeasurementparams_pmo_pcco.offsetthreshold400_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams_pmo_pcco_offsetthreshold1900_exist,
{ "Exist_OffsetThreshold1900", "gsm_rlcmac.gprsmeasurementparams_pmo_pcco.offsetthreshold1900_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams_pmo_pcco_offsetthreshold850_exist,
{ "Exist_OffsetThreshold850", "gsm_rlcmac.gprsmeasurementparams_pmo_pcco.offsetthreshold850_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multiratparams3g_existmultiratreporting_exist,
{ "existMultiratReporting", "gsm_rlcmac.multiratparams3g.existmultiratreporting_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_multiratparams3g_existoffsetthreshold_exist,
{ "existOffsetThreshold", "gsm_rlcmac.multiratparams3g.existoffsetthreshold_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pmo_existrepparamsfdd_exist,
{ "existRepParamsFDD", "gsm_rlcmac.enh_gprsmeasurementparams3g_pmo.existrepparamsfdd_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pmo_existoffsetthreshold_exist,
{ "existOffsetThreshold", "gsm_rlcmac.enh_gprsmeasurementparams3g_pmo.existoffsetthreshold_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pcco_existrepparamsfdd_exist,
{ "existRepParamsFDD", "gsm_rlcmac.enh_gprsmeasurementparams3g_pcco.existrepparamsfdd_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_gprsmeasurementparams3g_pcco_existoffsetthreshold_exist,
{ "existOffsetThreshold", "gsm_rlcmac.enh_gprsmeasurementparams3g_pcco.existoffsetthreshold_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_fdd_description_existbandwidth_exist,
{ "existBandwidth", "gsm_rlcmac.utran_fdd_description.existbandwidth_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_tdd_description_existbandwidth_exist,
{ "existBandwidth", "gsm_rlcmac.utran_tdd_description.existbandwidth_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelldescription3g_pmo_index_start_3g_exist,
{ "Exist_Index_Start_3G", "gsm_rlcmac.neighbourcelldescription3g_pmo.index_start_3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelldescription3g_pmo_absolute_index_start_emr_exist,
{ "Exist_Absolute_Index_Start_EMR", "gsm_rlcmac.neighbourcelldescription3g_pmo.absolute_index_start_emr_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelldescription3g_pmo_utran_fdd_description_exist,
{ "Exist_UTRAN_FDD_Description", "gsm_rlcmac.neighbourcelldescription3g_pmo.utran_fdd_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelldescription3g_pmo_utran_tdd_description_exist,
{ "Exist_UTRAN_TDD_Description", "gsm_rlcmac.neighbourcelldescription3g_pmo.utran_tdd_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelldescription3g_pmo_cdma2000_description_exist,
{ "Exist_CDMA2000_Description", "gsm_rlcmac.neighbourcelldescription3g_pmo.cdma2000_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelldescription3g_pmo_removed3gcelldescription_exist,
{ "Exist_Removed3GCellDescription", "gsm_rlcmac.neighbourcelldescription3g_pmo.removed3gcelldescription_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelldescription3g_pcco_index_start_3g_exist,
{ "Exist_Index_Start_3G", "gsm_rlcmac.neighbourcelldescription3g_pcco.index_start_3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelldescription3g_pcco_absolute_index_start_emr_exist,
{ "Exist_Absolute_Index_Start_EMR", "gsm_rlcmac.neighbourcelldescription3g_pcco.absolute_index_start_emr_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelldescription3g_pcco_utran_fdd_description_exist,
{ "Exist_UTRAN_FDD_Description", "gsm_rlcmac.neighbourcelldescription3g_pcco.utran_fdd_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelldescription3g_pcco_utran_tdd_description_exist,
{ "Exist_UTRAN_TDD_Description", "gsm_rlcmac.neighbourcelldescription3g_pcco.utran_tdd_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelldescription3g_pcco_removed3gcelldescription_exist,
{ "Exist_Removed3GCellDescription", "gsm_rlcmac.neighbourcelldescription3g_pcco.removed3gcelldescription_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pmo_neighbourcelldescription3g_exist,
{ "Exist_NeighbourCellDescription3G", "gsm_rlcmac.enh_measurement_parameters_pmo.neighbourcelldescription3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pmo_gprsreportpriority_exist,
{ "Exist_GPRSReportPriority", "gsm_rlcmac.enh_measurement_parameters_pmo.gprsreportpriority_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pmo_gprsmeasurementparams_exist,
{ "Exist_GPRSMeasurementParams", "gsm_rlcmac.enh_measurement_parameters_pmo.gprsmeasurementparams_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pmo_gprsmeasurementparams3g_exist,
{ "Exist_GPRSMeasurementParams3G", "gsm_rlcmac.enh_measurement_parameters_pmo.gprsmeasurementparams3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pcco_neighbourcelldescription3g_exist,
{ "Exist_NeighbourCellDescription3G", "gsm_rlcmac.enh_measurement_parameters_pcco.neighbourcelldescription3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pcco_gprsreportpriority_exist,
{ "Exist_GPRSReportPriority", "gsm_rlcmac.enh_measurement_parameters_pcco.gprsreportpriority_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pcco_gprsmeasurementparams_exist,
{ "Exist_GPRSMeasurementParams", "gsm_rlcmac.enh_measurement_parameters_pcco.gprsmeasurementparams_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_measurement_parameters_pcco_gprsmeasurementparams3g_exist,
{ "Exist_GPRSMeasurementParams3G", "gsm_rlcmac.enh_measurement_parameters_pcco.gprsmeasurementparams3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modecellselectionparameters_si13_alt_pbcch_location_exist,
{ "Exist_SI13_Alt_PBCCH_Location", "gsm_rlcmac.lu_modecellselectionparameters.si13_alt_pbcch_location_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modecellselectionparams_lu_modecellselectionparams_exist,
{ "Exist_lu_ModeCellSelectionParams", "gsm_rlcmac.lu_modecellselectionparams.lu_modecellselectionparams_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_rxlev_and_txpwr_exist,
{ "Exist_RXLEV_and_TXPWR", "gsm_rlcmac.lu_modeonlycellselection.rxlev_and_txpwr_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_offset_and_time_exist,
{ "Exist_OFFSET_and_TIME", "gsm_rlcmac.lu_modeonlycellselection.offset_and_time_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_gprs_reselect_offset_exist,
{ "Exist_GPRS_RESELECT_OFFSET", "gsm_rlcmac.lu_modeonlycellselection.gprs_reselect_offset_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_hcs_exist,
{ "Exist_HCS", "gsm_rlcmac.lu_modeonlycellselection.hcs_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselection_si13_alt_pbcch_location_exist,
{ "Exist_SI13_Alt_PBCCH_Location", "gsm_rlcmac.lu_modeonlycellselection.si13_alt_pbcch_location_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lu_modeonlycellselectionparamswithfreqdiff_lu_modeonlycellselectionparams_exist,
{ "Exist_lu_ModeOnlyCellSelectionParams", "gsm_rlcmac.lu_modeonlycellselectionparamswithfreqdiff.lu_modeonlycellselectionparams_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_add_lu_modeonlyfrequencylist_lu_modecellselection_exist,
{ "Exist_lu_ModeCellSelection", "gsm_rlcmac.add_lu_modeonlyfrequencylist.lu_modecellselection_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprs_additionalmeasurementparams3g_fdd_reporting_threshold_2_exist,
{ "Exist_FDD_REPORTING_THRESHOLD_2", "gsm_rlcmac.gprs_additionalmeasurementparams3g.fdd_reporting_threshold_2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedutran_priorityparameters_existutran_priority_exist,
{ "existUTRAN_PRIORITY", "gsm_rlcmac.repeatedutran_priorityparameters.existutran_priority_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedutran_priorityparameters_existthresh_utran_low_exist,
{ "existTHRESH_UTRAN_low", "gsm_rlcmac.repeatedutran_priorityparameters.existthresh_utran_low_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedutran_priorityparameters_existutran_qrxlevmin_exist,
{ "existUTRAN_QRXLEVMIN", "gsm_rlcmac.repeatedutran_priorityparameters.existutran_qrxlevmin_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_priorityparametersdescription3g_pmo_existdefault_utran_parameters_exist,
{ "existDEFAULT_UTRAN_Parameters", "gsm_rlcmac.priorityparametersdescription3g_pmo.existdefault_utran_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reporting_threshold_offset_existeutran_fdd_reporting_threshold_offset_exist,
{ "existEUTRAN_FDD_REPORTING_THRESHOLD_OFFSET", "gsm_rlcmac.eutran_reporting_threshold_offset.existeutran_fdd_reporting_threshold_offset_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reporting_threshold_offset_existeutran_fdd_reporting_threshold_2_exist,
{ "existEUTRAN_FDD_REPORTING_THRESHOLD_2", "gsm_rlcmac.eutran_reporting_threshold_offset.existeutran_fdd_reporting_threshold_2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reporting_threshold_offset_existeutran_fdd_reporting_offset_exist,
{ "existEUTRAN_FDD_REPORTING_OFFSET", "gsm_rlcmac.eutran_reporting_threshold_offset.existeutran_fdd_reporting_offset_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reporting_threshold_offset_existeutran_tdd_reporting_threshold_offset_exist,
{ "existEUTRAN_TDD_REPORTING_THRESHOLD_OFFSET", "gsm_rlcmac.eutran_reporting_threshold_offset.existeutran_tdd_reporting_threshold_offset_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reporting_threshold_offset_existeutran_tdd_reporting_threshold_2_exist,
{ "existEUTRAN_TDD_REPORTING_THRESHOLD_2", "gsm_rlcmac.eutran_reporting_threshold_offset.existeutran_tdd_reporting_threshold_2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_reporting_threshold_offset_existeutran_tdd_reporting_offset_exist,
{ "existEUTRAN_TDD_REPORTING_OFFSET", "gsm_rlcmac.eutran_reporting_threshold_offset.existeutran_tdd_reporting_offset_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_cells_existmeasurementbandwidth_exist,
{ "existMeasurementBandwidth", "gsm_rlcmac.repeatedeutran_cells.existmeasurementbandwidth_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_neighbourcells_existeutran_priority_exist,
{ "existEUTRAN_PRIORITY", "gsm_rlcmac.repeatedeutran_neighbourcells.existeutran_priority_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_neighbourcells_existthresh_eutran_low_exist,
{ "existTHRESH_EUTRAN_low", "gsm_rlcmac.repeatedeutran_neighbourcells.existthresh_eutran_low_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_neighbourcells_existeutran_qrxlevmin_exist,
{ "existEUTRAN_QRXLEVMIN", "gsm_rlcmac.repeatedeutran_neighbourcells.existeutran_qrxlevmin_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcid_group_ie_existpcid_bitmap_group_exist,
{ "existPCID_BITMAP_GROUP", "gsm_rlcmac.pcid_group_ie.existpcid_bitmap_group_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_parametersdescription_pmo_existgprs_eutran_measurementparametersdescription_exist,
{ "existGPRS_EUTRAN_MeasurementParametersDescription", "gsm_rlcmac.eutran_parametersdescription_pmo.existgprs_eutran_measurementparametersdescription_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_meas_ctrl_param_desp_existmeasurement_control_eutran_exist,
{ "existMeasurement_Control_EUTRAN", "gsm_rlcmac.meas_ctrl_param_desp.existmeasurement_control_eutran_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_meas_ctrl_param_desp_existmeasurement_control_utran_exist,
{ "existMeasurement_Control_UTRAN", "gsm_rlcmac.meas_ctrl_param_desp.existmeasurement_control_utran_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_reselection_based_on_rsrq_existthresh_eutran_low_q_exist,
{ "existTHRESH_EUTRAN_low_Q", "gsm_rlcmac.reselection_based_on_rsrq.existthresh_eutran_low_q_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_reselection_based_on_rsrq_existeutran_qqualmin_exist,
{ "existEUTRAN_QQUALMIN", "gsm_rlcmac.reselection_based_on_rsrq.existeutran_qqualmin_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_reselection_based_on_rsrq_existeutran_rsrpmin_exist,
{ "existEUTRAN_RSRPmin", "gsm_rlcmac.reselection_based_on_rsrq.existeutran_rsrpmin_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_cells_reporting_desp_existutran_csg_fdd_reporting_threshold_exist,
{ "existUTRAN_CSG_FDD_REPORTING_THRESHOLD", "gsm_rlcmac.utran_csg_cells_reporting_desp.existutran_csg_fdd_reporting_threshold_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_cells_reporting_desp_existutran_csg_tdd_reporting_threshold_exist,
{ "existUTRAN_CSG_TDD_REPORTING_THRESHOLD", "gsm_rlcmac.utran_csg_cells_reporting_desp.existutran_csg_tdd_reporting_threshold_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_cells_reporting_desp_existeutran_csg_fdd_reporting_threshold_exist,
{ "existEUTRAN_CSG_FDD_REPORTING_THRESHOLD", "gsm_rlcmac.eutran_csg_cells_reporting_desp.existeutran_csg_fdd_reporting_threshold_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_cells_reporting_desp_existeutran_csg_tdd_reporting_threshold_exist,
{ "existEUTRAN_CSG_TDD_REPORTING_THRESHOLD", "gsm_rlcmac.eutran_csg_cells_reporting_desp.existeutran_csg_tdd_reporting_threshold_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_csg_cells_reporting_desp_existutran_csg_cells_reporting_description_exist,
{ "existUTRAN_CSG_Cells_Reporting_Description", "gsm_rlcmac.csg_cells_reporting_desp.existutran_csg_cells_reporting_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_csg_cells_reporting_desp_existeutran_csg_cells_reporting_description_exist,
{ "existEUTRAN_CSG_Cells_Reporting_Description", "gsm_rlcmac.csg_cells_reporting_desp.existeutran_csg_cells_reporting_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_priorityandeutran_parametersdescription_pmo_existservingcellpriorityparametersdescription_exist,
{ "existServingCellPriorityParametersDescription", "gsm_rlcmac.priorityandeutran_parametersdescription_pmo.existservingcellpriorityparametersdescription_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_priorityandeutran_parametersdescription_pmo_existpriorityparametersdescription3g_pmo_exist,
{ "existPriorityParametersDescription3G_PMO", "gsm_rlcmac.priorityandeutran_parametersdescription_pmo.existpriorityparametersdescription3g_pmo_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_priorityandeutran_parametersdescription_pmo_existeutran_parametersdescription_pmo_exist,
{ "existEUTRAN_ParametersDescription_PMO", "gsm_rlcmac.priorityandeutran_parametersdescription_pmo.existeutran_parametersdescription_pmo_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_threeg_individual_priority_parameters_description_default_utran_priority_exist,
{ "Exist_DEFAULT_UTRAN_PRIORITY", "gsm_rlcmac.threeg_individual_priority_parameters_description.default_utran_priority_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_individual_priority_parameters_description_default_eutran_priority_exist,
{ "Exist_DEFAULT_EUTRAN_PRIORITY", "gsm_rlcmac.eutran_individual_priority_parameters_description.default_eutran_priority_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_provide_individual_priorities_3g_individual_priority_parameters_description_exist,
{ "Exist_3G_Individual_Priority_Parameters_Description", "gsm_rlcmac.provide_individual_priorities.3g_individual_priority_parameters_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_provide_individual_priorities_eutran_individual_priority_parameters_description_exist,
{ "Exist_EUTRAN_Individual_Priority_Parameters_Description", "gsm_rlcmac.provide_individual_priorities.eutran_individual_priority_parameters_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_provide_individual_priorities_t3230_timeout_value_exist,
{ "Exist_T3230_timeout_value", "gsm_rlcmac.provide_individual_priorities.t3230_timeout_value_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr9_existenhanced_cell_reselection_parameters_description_exist,
{ "existEnhanced_Cell_Reselection_Parameters_Description", "gsm_rlcmac.pmo_additionsr9.existenhanced_cell_reselection_parameters_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr9_existcsg_cells_reporting_description_exist,
{ "existCSG_Cells_Reporting_Description", "gsm_rlcmac.pmo_additionsr9.existcsg_cells_reporting_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr8_existba_ind_3g_pmo_ind_exist,
{ "existBA_IND_3G_PMO_IND", "gsm_rlcmac.pmo_additionsr8.existba_ind_3g_pmo_ind_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr8_existpriorityandeutran_parametersdescription_pmo_exist,
{ "existPriorityAndEUTRAN_ParametersDescription_PMO", "gsm_rlcmac.pmo_additionsr8.existpriorityandeutran_parametersdescription_pmo_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr8_existindividualpriorities_pmo_exist,
{ "existIndividualPriorities_PMO", "gsm_rlcmac.pmo_additionsr8.existindividualpriorities_pmo_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr8_existthreeg_csg_description_exist,
{ "existThreeG_CSG_Description", "gsm_rlcmac.pmo_additionsr8.existthreeg_csg_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr8_existeutran_csg_description_exist,
{ "existEUTRAN_CSG_Description", "gsm_rlcmac.pmo_additionsr8.existeutran_csg_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr8_existmeasurement_control_parameters_description_exist,
{ "existMeasurement_Control_Parameters_Description", "gsm_rlcmac.pmo_additionsr8.existmeasurement_control_parameters_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr7_existreporting_offset_threshold_700_exist,
{ "existREPORTING_OFFSET_THRESHOLD_700", "gsm_rlcmac.pmo_additionsr7.existreporting_offset_threshold_700_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr7_existreporting_offset_threshold_810_exist,
{ "existREPORTING_OFFSET_THRESHOLD_810", "gsm_rlcmac.pmo_additionsr7.existreporting_offset_threshold_810_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr5_existgrnti_extension_exist,
{ "existGRNTI_Extension", "gsm_rlcmac.pmo_additionsr5.existgrnti_extension_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr5_lu_modeneighbourcellparams_exist,
{ "exist_lu_ModeNeighbourCellParams", "gsm_rlcmac.pmo_additionsr5.lu_modeneighbourcellparams_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr5_existnc_lu_modeonlycapablecelllist_exist,
{ "existNC_lu_ModeOnlyCapableCellList", "gsm_rlcmac.pmo_additionsr5.existnc_lu_modeonlycapablecelllist_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr5_existgprs_additionalmeasurementparams3g_exist,
{ "existGPRS_AdditionalMeasurementParams3G", "gsm_rlcmac.pmo_additionsr5.existgprs_additionalmeasurementparams3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr5_existgrnti_extension_exist,
{ "existGRNTI_Extension", "gsm_rlcmac.pcco_additionsr5.existgrnti_extension_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr5_lu_modeneighbourcellparams_exist,
{ "exist_lu_ModeNeighbourCellParams", "gsm_rlcmac.pcco_additionsr5.lu_modeneighbourcellparams_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr5_existnc_lu_modeonlycapablecelllist_exist,
{ "existNC_lu_ModeOnlyCapableCellList", "gsm_rlcmac.pcco_additionsr5.existnc_lu_modeonlycapablecelllist_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr5_existgprs_additionalmeasurementparams3g_exist,
{ "existGPRS_AdditionalMeasurementParams3G", "gsm_rlcmac.pcco_additionsr5.existgprs_additionalmeasurementparams3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr4_ccn_support_description_id_exist,
{ "Exist_CCN_Support_Description_ID", "gsm_rlcmac.pmo_additionsr4.ccn_support_description_id_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr99_enh_measurement_parameters_exist,
{ "Exist_ENH_Measurement_Parameters", "gsm_rlcmac.pmo_additionsr99.enh_measurement_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr4_container_id_exist,
{ "Exist_Container_ID", "gsm_rlcmac.pcco_additionsr4.container_id_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr4_ccn_support_description_id_exist,
{ "Exist_CCN_Support_Description_ID", "gsm_rlcmac.pcco_additionsr4.ccn_support_description_id_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr98_lsa_parameters_exist,
{ "Exist_LSA_Parameters", "gsm_rlcmac.pmo_additionsr98.lsa_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr98_lsa_parameters_exist,
{ "Exist_LSA_Parameters", "gsm_rlcmac.pcco_additionsr98.lsa_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g_additionsr8_eutran_target_cell_exist,
{ "Exist_EUTRAN_Target_Cell", "gsm_rlcmac.target_cell_3g_additionsr8.eutran_target_cell_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g_additionsr8_individual_priorities_exist,
{ "Exist_Individual_Priorities", "gsm_rlcmac.target_cell_3g_additionsr8.individual_priorities_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g_additionsr5_g_rnti_extention_exist,
{ "Exist_G_RNTI_Extention", "gsm_rlcmac.target_cell_3g_additionsr5.g_rnti_extention_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g_fdd_description_exist,
{ "Exist_FDD_Description", "gsm_rlcmac.target_cell_3g.fdd_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g_tdd_description_exist,
{ "Exist_TDD_Description", "gsm_rlcmac.target_cell_3g.tdd_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_measurements_bsic_n_exist,
{ "Exist_BSIC_N", "gsm_rlcmac.nc_measurements.bsic_n_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_reporting_quantity_instance_reporting_quantity_exist,
{ "Exist_REPORTING_QUANTITY", "gsm_rlcmac.reporting_quantity_instance.reporting_quantity_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_nc_measurement_report_serving_cell_data_exist,
{ "Exist_Serving_Cell_Data", "gsm_rlcmac.enh_nc_measurement_report.serving_cell_data_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_nc_measurement_report_reportbitmap_exist,
{ "Exist_ReportBitmap", "gsm_rlcmac.enh_nc_measurement_report.reportbitmap_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot0_exist,
{ "Slot[0].Exist", "gsm_rlcmac.ext_measurement_report.slot0_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot1_exist,
{ "Slot[1].Exist", "gsm_rlcmac.ext_measurement_report.slot1_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot2_exist,
{ "Slot[2].Exist", "gsm_rlcmac.ext_measurement_report.slot2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot3_exist,
{ "Slot[3].Exist", "gsm_rlcmac.ext_measurement_report.slot3_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot4_exist,
{ "Slot[4].Exist", "gsm_rlcmac.ext_measurement_report.slot4_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot5_exist,
{ "Slot[5].Exist", "gsm_rlcmac.ext_measurement_report.slot5_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot6_exist,
{ "Slot[6].Exist", "gsm_rlcmac.ext_measurement_report.slot6_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_slot7_exist,
{ "Slot[7].Exist", "gsm_rlcmac.ext_measurement_report.slot7_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ext_measurement_report_i_level_exist,
{ "Exist_I_LEVEL", "gsm_rlcmac.ext_measurement_report.i_level_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_csg_measurement_report_plmn_id_exist,
{ "Exist_PLMN_ID", "gsm_rlcmac.utran_csg_measurement_report.plmn_id_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_measurement_report_plmn_id_exist,
{ "Exist_PLMN_ID", "gsm_rlcmac.eutran_csg_measurement_report.plmn_id_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr9_utran_csg_meas_rpt_exist,
{ "Exist_UTRAN_CSG_Meas_Rpt", "gsm_rlcmac.pmr_additionsr9.utran_csg_meas_rpt_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr9_eutran_csg_meas_rpt_exist,
{ "Exist_EUTRAN_CSG_Meas_Rpt", "gsm_rlcmac.pmr_additionsr9.eutran_csg_meas_rpt_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr8_eutran_meas_rpt_exist,
{ "Exist_EUTRAN_Meas_Rpt", "gsm_rlcmac.pmr_additionsr8.eutran_meas_rpt_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr5_grnti_exist,
{ "Exist_GRNTI", "gsm_rlcmac.pmr_additionsr5.grnti_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr99_info3g_exist,
{ "Exist_Info3G", "gsm_rlcmac.pmr_additionsr99.info3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr99_measurementreport3g_exist,
{ "Exist_MeasurementReport3G", "gsm_rlcmac.pmr_additionsr99.measurementreport3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_measurement_report_psi5_change_mark_exist,
{ "Exist_PSI5_CHANGE_MARK", "gsm_rlcmac.packet_measurement_report.psi5_change_mark_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pemr_additionsr9_utran_csg_target_cell_exist,
{ "Exist_UTRAN_CSG_Target_Cell", "gsm_rlcmac.pemr_additionsr9.utran_csg_target_cell_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pemr_additionsr9_eutran_csg_target_cell_exist,
{ "Exist_EUTRAN_CSG_Target_Cell", "gsm_rlcmac.pemr_additionsr9.eutran_csg_target_cell_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_bitmap_report_quantity_reporting_quantity_exist,
{ "Exist_REPORTING_QUANTITY", "gsm_rlcmac.bitmap_report_quantity.reporting_quantity_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pemr_additionsr8_eutran_meas_rpt_exist,
{ "Exist_EUTRAN_Meas_Rpt", "gsm_rlcmac.pemr_additionsr8.eutran_meas_rpt_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pemr_additionsr5_grnti_ext_exist,
{ "Exist_GRNTI_Ext", "gsm_rlcmac.pemr_additionsr5.grnti_ext_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_measurement_order_nc_measurement_parameters_exist,
{ "Exist_NC_Measurement_Parameters", "gsm_rlcmac.packet_measurement_order.nc_measurement_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_measurement_order_ext_measurement_parameters_exist,
{ "Exist_EXT_Measurement_Parameters", "gsm_rlcmac.packet_measurement_order.ext_measurement_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_fdd_target_cell_notif_bandwith_fdd_exist,
{ "Exist_Bandwith_FDD", "gsm_rlcmac.fdd_target_cell_notif.bandwith_fdd_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_tdd_target_cell_notif_bandwith_tdd_exist,
{ "Exist_Bandwith_TDD", "gsm_rlcmac.tdd_target_cell_notif.bandwith_tdd_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g_notif_fdd_description_exist,
{ "Exist_FDD_Description", "gsm_rlcmac.target_cell_3g_notif.fdd_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g_notif_tdd_description_exist,
{ "Exist_TDD_Description", "gsm_rlcmac.target_cell_3g_notif.tdd_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_eutran_cell_notif_measurement_bandwidth_exist,
{ "Exist_Measurement_Bandwidth", "gsm_rlcmac.target_eutran_cell_notif.measurement_bandwidth_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_4g_notif_arfcn_exist,
{ "Exist_Arfcn", "gsm_rlcmac.target_cell_4g_notif.arfcn_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_4g_notif_3g_target_cell_exist,
{ "Exist_3G_Target_Cell", "gsm_rlcmac.target_cell_4g_notif.3g_target_cell_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_4g_notif_eutran_target_cell_exist,
{ "Exist_Eutran_Target_Cell", "gsm_rlcmac.target_cell_4g_notif.eutran_target_cell_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_4g_notif_eutran_ccn_measurement_report_exist,
{ "Exist_Eutran_Ccn_Measurement_Report", "gsm_rlcmac.target_cell_4g_notif.eutran_ccn_measurement_report_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_csg_notif_eutran_ccn_measurement_report_exist,
{ "Exist_Eutran_Ccn_Measurement_Report", "gsm_rlcmac.target_cell_csg_notif.eutran_ccn_measurement_report_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccn_additionsr6_ba_used_3g_exist,
{ "Exist_BA_USED_3G", "gsm_rlcmac.pccn_additionsr6.ba_used_3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_continue_id_exist,
{ "Exist_ID", "gsm_rlcmac.packet_cell_change_continue.id_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_downlinkassignment_egprs_windowsize_exist,
{ "Exist_EGPRS_WindowSize", "gsm_rlcmac.pho_downlinkassignment.egprs_windowsize_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_usf_1_7_usf_exist,
{ "Exist_USF", "gsm_rlcmac.pho_usf_1_7.usf_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_uplinkassignment_channelcodingcommand_exist,
{ "Exist_ChannelCodingCommand", "gsm_rlcmac.pho_uplinkassignment.channelcodingcommand_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_uplinkassignment_egprs_channelcodingcommand_exist,
{ "Exist_EGPRS_ChannelCodingCommand", "gsm_rlcmac.pho_uplinkassignment.egprs_channelcodingcommand_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_uplinkassignment_egprs_windowsize_exist,
{ "Exist_EGPRS_WindowSize", "gsm_rlcmac.pho_uplinkassignment.egprs_windowsize_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_uplinkassignment_tbf_timeslotallocation_exist,
{ "Exist_TBF_TimeslotAllocation", "gsm_rlcmac.pho_uplinkassignment.tbf_timeslotallocation_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_globaltimeslotdescription_ua_pho_ua_exist,
{ "Exist_PHO_UA", "gsm_rlcmac.globaltimeslotdescription_ua.pho_ua_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_gprs_channelcodingcommand_exist,
{ "Exist_ChannelCodingCommand", "gsm_rlcmac.pho_gprs.channelcodingcommand_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_gprs_globaltimeslotdescription_ua_exist,
{ "Exist_GlobalTimeslotDescription_UA", "gsm_rlcmac.pho_gprs.globaltimeslotdescription_ua_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_gprs_downlinkassignment_exist,
{ "Exist_DownlinkAssignment", "gsm_rlcmac.pho_gprs.downlinkassignment_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_description_egprs_windowsize_exist,
{ "Exist_EGPRS_WindowSize", "gsm_rlcmac.egprs_description.egprs_windowsize_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_egprs_description_bep_period2_exist,
{ "Exist_BEP_Period2", "gsm_rlcmac.egprs_description.bep_period2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_downlinktbf_egprs_description_exist,
{ "Exist_EGPRS_Description", "gsm_rlcmac.downlinktbf.egprs_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_downlinktbf_downlinkassignment_exist,
{ "Exist_DownlinkAssignment", "gsm_rlcmac.downlinktbf.downlinkassignment_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_egprs_egprs_windowsize_exist,
{ "Exist_EGPRS_WindowSize", "gsm_rlcmac.pho_egprs.egprs_windowsize_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_egprs_egprs_channelcodingcommand_exist,
{ "Exist_EGPRS_ChannelCodingCommand", "gsm_rlcmac.pho_egprs.egprs_channelcodingcommand_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_egprs_bep_period2_exist,
{ "Exist_BEP_Period2", "gsm_rlcmac.pho_egprs.bep_period2_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_egprs_globaltimeslotdescription_ua_exist,
{ "Exist_GlobalTimeslotDescription_UA", "gsm_rlcmac.pho_egprs.globaltimeslotdescription_ua_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_egprs_downlinktbf_exist,
{ "Exist_DownlinkTBF", "gsm_rlcmac.pho_egprs.downlinktbf_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_timingadvance_packetextendedtimingadvance_exist,
{ "Exist_PacketExtendedTimingAdvance", "gsm_rlcmac.pho_timingadvance.packetextendedtimingadvance_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_handoverreference_exist,
{ "Exist_HandoverReference", "gsm_rlcmac.pho_radioresources.handoverreference_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_ccn_active_exist,
{ "Exist_CCN_Active", "gsm_rlcmac.pho_radioresources.ccn_active_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_ccn_active_3g_exist,
{ "Exist_CCN_Active_3G", "gsm_rlcmac.pho_radioresources.ccn_active_3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_ccn_support_description_exist,
{ "Exist_CCN_Support_Description", "gsm_rlcmac.pho_radioresources.ccn_support_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_pho_timingadvance_exist,
{ "Exist_PHO_TimingAdvance", "gsm_rlcmac.pho_radioresources.pho_timingadvance_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_po_pr_exist,
{ "Exist_PO_PR", "gsm_rlcmac.pho_radioresources.po_pr_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pho_radioresources_uplinkcontroltimeslot_exist,
{ "Exist_UplinkControlTimeslot", "gsm_rlcmac.pho_radioresources.uplinkcontroltimeslot_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_ps_handoverto_a_gb_modepayload_nas_container_exist,
{ "Exist_NAS_Container", "gsm_rlcmac.ps_handoverto_a_gb_modepayload.nas_container_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi1_psi_count_hr_exist,
{ "Exist_PSI_COUNT_HR", "gsm_rlcmac.psi1.psi_count_hr_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_non_gprs_cell_options_t3212_exist,
{ "Exist_T3212", "gsm_rlcmac.non_gprs_cell_options.t3212_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_non_gprs_cell_options_extension_bits_exist,
{ "Exist_Extension_Bits", "gsm_rlcmac.non_gprs_cell_options.extension_bits_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi2_cell_identification_exist,
{ "Exist_Cell_Identification", "gsm_rlcmac.psi2.cell_identification_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi2_non_gprs_cell_options_exist,
{ "Exist_Non_GPRS_Cell_Options", "gsm_rlcmac.psi2.non_gprs_cell_options_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_serving_cell_params_hcs_exist,
{ "Exist_HCS", "gsm_rlcmac.serving_cell_params.hcs_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gen_cell_sel_t_resel_exist,
{ "Exist_T_RESEL", "gsm_rlcmac.gen_cell_sel.t_resel_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gen_cell_sel_ra_reselect_hysteresis_exist,
{ "Exist_RA_RESELECT_HYSTERESIS", "gsm_rlcmac.gen_cell_sel.ra_reselect_hysteresis_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_compact_cell_sel_gprs_rxlev_access_min_exist,
{ "Exist_GPRS_RXLEV_ACCESS_MIN", "gsm_rlcmac.compact_cell_sel.gprs_rxlev_access_min_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_compact_cell_sel_gprs_temporary_offset_exist,
{ "Exist_GPRS_TEMPORARY_OFFSET", "gsm_rlcmac.compact_cell_sel.gprs_temporary_offset_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_compact_cell_sel_gprs_reselect_offset_exist,
{ "Exist_GPRS_RESELECT_OFFSET", "gsm_rlcmac.compact_cell_sel.gprs_reselect_offset_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_compact_cell_sel_hcs_parm_exist,
{ "Exist_Hcs_Parm", "gsm_rlcmac.compact_cell_sel.hcs_parm_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_compact_cell_sel_time_group_exist,
{ "Exist_TIME_GROUP", "gsm_rlcmac.compact_cell_sel.time_group_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_compact_cell_sel_guar_constant_pwr_blks_exist,
{ "Exist_GUAR_CONSTANT_PWR_BLKS", "gsm_rlcmac.compact_cell_sel.guar_constant_pwr_blks_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi3_additionr4_ccn_support_desc_exist,
{ "Exist_CCN_Support_Desc", "gsm_rlcmac.psi3_additionr4.ccn_support_desc_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi3_additionr99_compact_info_exist,
{ "Exist_COMPACT_Info", "gsm_rlcmac.psi3_additionr99.compact_info_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi3_additionr99_additionr4_exist,
{ "Exist_AdditionR4", "gsm_rlcmac.psi3_additionr99.additionr4_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi3_additionr98_lsa_parameters_exist,
{ "Exist_LSA_Parameters", "gsm_rlcmac.psi3_additionr98.lsa_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi3_additionr98_additionr99_exist,
{ "Exist_AdditionR99", "gsm_rlcmac.psi3_additionr98.additionr99_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi3_additionr98_exist,
{ "Exist_AdditionR98", "gsm_rlcmac.psi3.additionr98_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurementparams_multi_band_reporting_exist,
{ "Exist_MULTI_BAND_REPORTING", "gsm_rlcmac.measurementparams.multi_band_reporting_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurementparams_serving_band_reporting_exist,
{ "Exist_SERVING_BAND_REPORTING", "gsm_rlcmac.measurementparams.serving_band_reporting_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurementparams_scale_ord_exist,
{ "Exist_SCALE_ORD", "gsm_rlcmac.measurementparams.scale_ord_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurementparams_offsetthreshold900_exist,
{ "Exist_OffsetThreshold900", "gsm_rlcmac.measurementparams.offsetthreshold900_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurementparams_offsetthreshold1800_exist,
{ "Exist_OffsetThreshold1800", "gsm_rlcmac.measurementparams.offsetthreshold1800_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurementparams_offsetthreshold400_exist,
{ "Exist_OffsetThreshold400", "gsm_rlcmac.measurementparams.offsetthreshold400_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurementparams_offsetthreshold1900_exist,
{ "Exist_OffsetThreshold1900", "gsm_rlcmac.measurementparams.offsetthreshold1900_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_measurementparams_offsetthreshold850_exist,
{ "Exist_OffsetThreshold850", "gsm_rlcmac.measurementparams.offsetthreshold850_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_psi5_existrepparamsfdd_exist,
{ "existRepParamsFDD", "gsm_rlcmac.gprsmeasurementparams3g_psi5.existrepparamsfdd_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_psi5_existreportingparamsfdd_exist,
{ "existReportingParamsFDD", "gsm_rlcmac.gprsmeasurementparams3g_psi5.existreportingparamsfdd_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_psi5_existmultiratreportingtdd_exist,
{ "existMultiratReportingTDD", "gsm_rlcmac.gprsmeasurementparams3g_psi5.existmultiratreportingtdd_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_gprsmeasurementparams3g_psi5_existoffsetthresholdtdd_exist,
{ "existOffsetThresholdTDD", "gsm_rlcmac.gprsmeasurementparams3g_psi5.existoffsetthresholdtdd_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_reporting_parameters_ncc_permitted_exist,
{ "Exist_NCC_PERMITTED", "gsm_rlcmac.enh_reporting_parameters.ncc_permitted_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_reporting_parameters_gprsmeasurementparams_exist,
{ "Exist_GPRSMeasurementParams", "gsm_rlcmac.enh_reporting_parameters.gprsmeasurementparams_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_reporting_parameters_gprsmeasurementparams3g_exist,
{ "Exist_GPRSMeasurementParams3G", "gsm_rlcmac.enh_reporting_parameters.gprsmeasurementparams3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi5_additions_offsetthreshold_700_exist,
{ "Exist_OffsetThreshold_700", "gsm_rlcmac.psi5_additions.offsetthreshold_700_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi5_additions_offsetthreshold_810_exist,
{ "Exist_OffsetThreshold_810", "gsm_rlcmac.psi5_additions.offsetthreshold_810_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi5_additions_gprs_additionalmeasurementparams3g_exist,
{ "Exist_GPRS_AdditionalMeasurementParams3G", "gsm_rlcmac.psi5_additions.gprs_additionalmeasurementparams3g_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi5_additions_additionsr7_exist,
{ "Exist_AdditionsR7", "gsm_rlcmac.psi5_additions.additionsr7_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi5_additionsr_enh_reporting_param_exist,
{ "Exist_ENH_Reporting_Param", "gsm_rlcmac.psi5_additionsr.enh_reporting_param_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi5_additionsr_additionsr5_exist,
{ "Exist_AdditionsR5", "gsm_rlcmac.psi5_additionsr.additionsr5_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi5_eixst_nc_meas_param_exist,
{ "Eixst_NC_Meas_Param", "gsm_rlcmac.psi5.eixst_nc_meas_param_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi13_additions_lb_ms_txpwr_max_cch_exist,
{ "Exist_LB_MS_TXPWR_MAX_CCH", "gsm_rlcmac.psi13_additions.lb_ms_txpwr_max_cch_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi13_additions_additionsr6_exist,
{ "Exist_AdditionsR6", "gsm_rlcmac.psi13_additions.additionsr6_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi13_additionr_additionsr4_exist,
{ "Exist_AdditionsR4", "gsm_rlcmac.psi13_additionr.additionsr4_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi13_ma_exist,
{ "Exist_MA", "gsm_rlcmac.psi13.ma_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccf_additionsr8_additionsr9_exist,
{ "Exist_AdditionsR9", "gsm_rlcmac.pccf_additionsr8.additionsr9_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccf_additionsr5_additionsr8_exist,
{ "Exist_AdditionsR8", "gsm_rlcmac.pccf_additionsr5.additionsr8_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pccf_additionsr99_additionsr5_exist,
{ "Exist_AdditionsR5", "gsm_rlcmac.pccf_additionsr99.additionsr5_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr8_existadditionsr9_exist,
{ "existAdditionsR9", "gsm_rlcmac.pmo_additionsr8.existadditionsr9_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr7_existadditionsr8_exist,
{ "existAdditionsR8", "gsm_rlcmac.pmo_additionsr7.existadditionsr8_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr6_existadditionsr7_exist,
{ "existAdditionsR7", "gsm_rlcmac.pmo_additionsr6.existadditionsr7_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr5_existadditionsr6_exist,
{ "existAdditionsR6", "gsm_rlcmac.pmo_additionsr5.existadditionsr6_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr5_existadditionsr6_exist,
{ "existAdditionsR6", "gsm_rlcmac.pcco_additionsr5.existadditionsr6_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr4_additionsr5_exist,
{ "Exist_AdditionsR5", "gsm_rlcmac.pmo_additionsr4.additionsr5_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmo_additionsr99_additionsr4_exist,
{ "Exist_AdditionsR4", "gsm_rlcmac.pmo_additionsr99.additionsr4_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcco_additionsr4_additionsr5_exist,
{ "Exist_AdditionsR5", "gsm_rlcmac.pcco_additionsr4.additionsr5_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_gsm_additionsr98_exist,
{ "Exist_AdditionsR98", "gsm_rlcmac.target_cell_gsm.additionsr98_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g_additionsr5_additionsr8_exist,
{ "Exist_AdditionsR8", "gsm_rlcmac.target_cell_3g_additionsr5.additionsr8_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_target_cell_3g_additionsr5_exist,
{ "Exist_AdditionsR5", "gsm_rlcmac.target_cell_3g.additionsr5_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr8_additionsr9_exist,
{ "Exist_AdditionsR9", "gsm_rlcmac.pmr_additionsr8.additionsr9_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr5_additionsr8_exist,
{ "Exist_AdditionsR8", "gsm_rlcmac.pmr_additionsr5.additionsr8_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pmr_additionsr99_additionsr5_exist,
{ "Exist_AdditionsR5", "gsm_rlcmac.pmr_additionsr99.additionsr5_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pemr_additionsr8_additionsr9_exist,
{ "Exist_AdditionsR9", "gsm_rlcmac.pemr_additionsr8.additionsr9_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pemr_additionsr5_additionsr8_exist,
{ "Exist_AdditionsR8", "gsm_rlcmac.pemr_additionsr5.additionsr8_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_enh_measurement_report_additionsr5_exist,
{ "Exist_AdditionsR5", "gsm_rlcmac.packet_enh_measurement_report.additionsr5_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_measurement_order_additionsr98_exist,
{ "Exist_AdditionsR98", "gsm_rlcmac.packet_measurement_order.additionsr98_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_cell_change_notification_additionsr6_exist,
{ "Exist_AdditionsR6", "gsm_rlcmac.packet_cell_change_notification.additionsr6_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi1_additionsr99_additionsr6_exist,
{ "Exist_AdditionsR6", "gsm_rlcmac.psi1_additionsr99.additionsr6_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_paging_request_repeated_page_info_exist,
{ "Repeated_Page_info Exist", "gsm_rlcmac.packet_paging_request.repeated_page_info_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_neighbourcelllist_parameters_exist,
{ "Parameters Exist", "gsm_rlcmac.neighbourcelllist.parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_frequency_list_add_frequency_exist,
{ "Add_Frequency Exist", "gsm_rlcmac.nc_frequency_list.add_frequency_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_fdd_description_cellparams_exist,
{ "CellParams Exist", "gsm_rlcmac.utran_fdd_description.cellparams_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_utran_tdd_description_cellparams_exist,
{ "CellParams Exist", "gsm_rlcmac.utran_tdd_description.cellparams_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nc_lu_modeonlycapablecelllist_add_lu_modeonlyfrequencylist_exist,
{ "Add_lu_ModeOnlyFrequencyList Exist", "gsm_rlcmac.nc_lu_modeonlycapablecelllist.add_lu_modeonlyfrequencylist_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_priorityparametersdescription3g_pmo_repeatedutran_priorityparameters_a_exist,
{ "RepeatedUTRAN_PriorityParameters_a Exist", "gsm_rlcmac.priorityparametersdescription3g_pmo.repeatedutran_priorityparameters_a_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_neighbourcells_eutran_cells_a_exist,
{ "EUTRAN_Cells_a Exist", "gsm_rlcmac.repeatedeutran_neighbourcells.eutran_cells_a_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pcid_group_ie_pcid_pattern_a_exist,
{ "PCID_Pattern_a Exist", "gsm_rlcmac.pcid_group_ie.pcid_pattern_a_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_notallowedcells_eutran_frequency_index_a_exist,
{ "EUTRAN_FREQUENCY_INDEX_a Exist", "gsm_rlcmac.repeatedeutran_notallowedcells.eutran_frequency_index_a_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_pcid_to_ta_mapping_pcid_tota_mapping_a_exist,
{ "PCID_ToTA_Mapping_a Exist", "gsm_rlcmac.repeatedeutran_pcid_to_ta_mapping.pcid_tota_mapping_a_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_repeatedeutran_pcid_to_ta_mapping_eutran_frequency_index_a_exist,
{ "EUTRAN_FREQUENCY_INDEX_a Exist", "gsm_rlcmac.repeatedeutran_pcid_to_ta_mapping.eutran_frequency_index_a_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_parametersdescription_pmo_repeatedeutran_neighbourcells_a_exist,
{ "RepeatedEUTRAN_NeighbourCells_a Exist", "gsm_rlcmac.eutran_parametersdescription_pmo.repeatedeutran_neighbourcells_a_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_parametersdescription_pmo_repeatedeutran_notallowedcells_a_exist,
{ "RepeatedEUTRAN_NotAllowedCells_a Exist", "gsm_rlcmac.eutran_parametersdescription_pmo.repeatedeutran_notallowedcells_a_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_parametersdescription_pmo_repeatedeutran_pcid_to_ta_mapping_a_exist,
{ "RepeatedEUTRAN_PCID_to_TA_mapping_a Exist", "gsm_rlcmac.eutran_parametersdescription_pmo.repeatedeutran_pcid_to_ta_mapping_a_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psc_group_psc_pattern_exist,
{ "PSC_Pattern Exist", "gsm_rlcmac.psc_group.psc_pattern_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_threeg_csg_description_threeg_csg_description_body_exist,
{ "ThreeG_CSG_Description_Body Exist", "gsm_rlcmac.threeg_csg_description.threeg_csg_description_body_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_csg_description_eutran_csg_description_body_exist,
{ "EUTRAN_CSG_Description_Body Exist", "gsm_rlcmac.eutran_csg_description.eutran_csg_description_body_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_cell_reselect_param_desp_repeated_eutran_enhanced_cell_reselection_parameters_exist,
{ "Repeated_EUTRAN_Enhanced_Cell_Reselection_Parameters Exist", "gsm_rlcmac.enh_cell_reselect_param_desp.repeated_eutran_enhanced_cell_reselection_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_threeg_individual_priority_parameters_description_repeated_individual_utran_priority_parameters_exist,
{ "Repeated_Individual_UTRAN_Priority_Parameters Exist", "gsm_rlcmac.threeg_individual_priority_parameters_description.repeated_individual_utran_priority_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_eutran_individual_priority_parameters_description_repeated_individual_eutran_priority_parameters_exist,
{ "Repeated_Individual_EUTRAN_Priority_Parameters Exist", "gsm_rlcmac.eutran_individual_priority_parameters_description.repeated_individual_eutran_priority_parameters_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_lsa_id_info_lsa_id_info_elements_exist,
{ "LSA_ID_Info_Elements Exist", "gsm_rlcmac.lsa_id_info.lsa_id_info_elements_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_compact_info_compact_neighbour_cell_param_exist,
{ "COMPACT_Neighbour_Cell_Param Exist", "gsm_rlcmac.compact_info.compact_neighbour_cell_param_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_packet_access_reject_reject_exist,
{ "Reject[1] Exist", "gsm_rlcmac.acket_access_reject.reject_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_enh_nc_measurement_report_repeatedinvalid_bsic_info_exist,
{ "RepeatedInvalid_BSIC_Info[0] Exist", "gsm_rlcmac.enh_nc_measurement_report.repeatedinvalid_bsic_info_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_nonhoppingpccch_carriers_exist,
{ "Carriers[0] Exist", "gsm_rlcmac.nonhoppingpccch.carriers_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi2_reference_frequency_exist,
{ "Reference_Frequency[0] Exist", "gsm_rlcmac.psi2.reference_frequency_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi2_gprs_ma_exist,
{ "GPRS_MA[0] Exist", "gsm_rlcmac.psi2.gprs_ma_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_psi2_pccch_description_exist,
{ "PCCCH_Description[0] Exist", "gsm_rlcmac.psi2.pccch_description_exist",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_gsm_rlcmac_scrambling_code, { "Scrambling Code", "gsm_rlcmac.scrambling_code", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_rlcmac_diversity, { "Diversity", "gsm_rlcmac.diversity", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_gsm_rlcmac_cell_parameter, { "Cell Parameter", "gsm_rlcmac.cell_parameter", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_rlcmac_sync_case_tstd, { "Sync Case TSTD", "gsm_rlcmac.sync_case_tstd", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_rlcmac_diversity_tdd, { "Diversity TDD", "gsm_rlcmac.diversity_tdd", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static ei_register_info ei[] = {
{ &ei_li, { "gsm_rlcmac.li.too_many", PI_UNDECODED, PI_ERROR, "Too many LIs, corresponding blocks will not be decoded", EXPFILL }},
{ &ei_gsm_rlcmac_unexpected_header_extension, { "gsm_rlcmac.unexpected_header_extension", PI_MALFORMED, PI_ERROR, "Unexpected header extension, dissection abandoned", EXPFILL }},
{ &ei_gsm_rlcmac_coding_scheme_invalid, { "gsm_rlcmac.coding_scheme.invalid", PI_PROTOCOL, PI_WARN, "Invalid coding scheme", EXPFILL }},
{ &ei_gsm_rlcmac_gprs_fanr_header_dissection_not_supported, { "gsm_rlcmac.gprs_fanr_header_dissection_not_supported", PI_UNDECODED, PI_WARN, "GPRS FANR Header dissection not supported (yet)", EXPFILL }},
{ &ei_gsm_rlcmac_egprs_header_type_not_handled, { "gsm_rlcmac.egprs_header_type_not_handled", PI_UNDECODED, PI_WARN, "EGPRS Header Type not handled (yet)", EXPFILL }},
{ &ei_gsm_rlcmac_coding_scheme_unknown, { "gsm_rlcmac.coding_scheme.unknown", PI_PROTOCOL, PI_WARN, "GSM RLCMAC unknown coding scheme", EXPFILL }},
{ &ei_gsm_rlcmac_unknown_pacch_access_burst, { "gsm_rlcmac.unknown_pacch_access_burst", PI_PROTOCOL, PI_WARN, "Unknown PACCH access burst", EXPFILL }},
{ &ei_gsm_rlcmac_stream_not_supported, { "gsm_rlcmac.stream_not_supported", PI_UNDECODED, PI_WARN, "Stream not supported", EXPFILL }},
};
expert_module_t* expert_gsm_rlcmac;
proto_gsm_rlcmac = proto_register_protocol("Radio Link Control, Medium Access Control, 3GPP TS44.060",
"GSM RLC MAC", "gsm_rlcmac");
proto_register_field_array(proto_gsm_rlcmac, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gsm_rlcmac = expert_register_protocol(proto_gsm_rlcmac);
expert_register_field_array(expert_gsm_rlcmac, ei, array_length(ei));
new_register_dissector("gsm_rlcmac_ul", dissect_gsm_rlcmac_uplink, proto_gsm_rlcmac);
new_register_dissector("gsm_rlcmac_dl", dissect_gsm_rlcmac_downlink, proto_gsm_rlcmac);
}
void
proto_reg_handoff_gsm_rlcmac(void)
{
data_handle = find_dissector("data");
}
