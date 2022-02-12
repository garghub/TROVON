static void
cbch_defragment_init(void)
{
fragment_table_init(&fragment_block_table);
reassembled_table_init(&reassembled_message_table);
}
static void
dissect_schedule_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *top_tree)
{
guint8 octet1, i, j, k = 0;
guint8 len, sched_begin, sched_end, new_slots[48];
guint8 offset = 0;
gboolean valid_message = TRUE;
guint16 other_slots[48];
proto_item *item = NULL, *schedule_item = NULL;
proto_tree *sched_tree = NULL, *sched_subtree = NULL;
len = tvb_length(tvb);
col_append_str(pinfo->cinfo, COL_INFO, " CBCH Schedule Message ");
schedule_item = proto_tree_add_protocol_format(top_tree, proto_cbch, tvb, 0, len,
"GSM CBCH Schedule Message");
sched_tree = proto_item_add_subtree(schedule_item, ett_schedule_msg);
proto_tree_add_item(sched_tree, hf_gsm_cbch_sched_type, tvb, offset, 1, ENC_BIG_ENDIAN);
octet1 = tvb_get_guint8(tvb, offset);
if (0 == (octet1 & 0xC0))
{
sched_begin = octet1 & 0x3F;
proto_tree_add_item(sched_tree, hf_gsm_cbch_sched_begin_slot, tvb, offset++, 1, ENC_BIG_ENDIAN);
if (1 == sched_begin)
{
proto_tree_add_text(sched_tree, tvb, offset - 1, 1, "(apparently) Scheduled Scheduling Message");
}
else if ((2 <= sched_begin) && (48 >= sched_begin))
{
proto_tree_add_text(sched_tree, tvb, offset - 1, 1, "(apparently) Unscheduled Scheduling Message");
}
else
{
proto_tree_add_text(sched_tree, tvb, offset - 1, 1, "Begin Slot Number out of range: ignoring message");
valid_message = FALSE;
}
proto_tree_add_item(sched_tree, hf_gsm_cbch_sched_spare, tvb, offset, 1, ENC_BIG_ENDIAN);
sched_end = tvb_get_guint8(tvb, offset);
proto_tree_add_item(sched_tree, hf_gsm_cbch_sched_end_slot, tvb, offset++, 1, ENC_BIG_ENDIAN);
if (sched_end < sched_begin)
{
proto_tree_add_text(sched_tree, tvb, offset - 1, 1, "End Slot Number less than Begin Slot Number: ignoring message");
valid_message = FALSE;
}
if (valid_message)
{
memset(&new_slots, 0xFF, sizeof(new_slots));
memset(&other_slots, 0xFF, sizeof(other_slots));
for (i=0; i<6; i++)
{
octet1 = tvb_get_guint8(tvb, offset++);
for (j=0; j<8; j++)
{
if (octet1 & (0x80>>j))
{
new_slots[k++] = (i<<3) + j + 1;
}
}
}
item = proto_tree_add_text(sched_tree, tvb, offset-6, 6, "This schedule contains %d slots with new messages", k);
sched_subtree = proto_item_add_subtree(item, ett_schedule_new_msg);
for (i=0; i<k; i++)
{
DISSECTOR_ASSERT(new_slots[i] < 48);
octet1 = tvb_get_guint8(tvb, offset);
if ((octet1 & 0x80) == 0x80)
{
guint8 octet2;
guint16 msg_id;
octet2 = tvb_get_guint8(tvb, offset + 1);
msg_id = ((octet1 &0x7F) << 8) + octet2;
proto_tree_add_text(sched_subtree, tvb, offset, 2,
"Slot: %d, Message ID: %d, First transmission of an SMSCB within the Schedule Period",
new_slots[i], msg_id);
offset +=2;
other_slots[new_slots[i] - 1] = msg_id;
}
else if ((octet1 & 0xC0) == 0)
{
if (octet1 < new_slots[i])
{
proto_tree_add_text(sched_subtree, tvb, offset++, 1,
"Slot: %d, Message ID: %d, Repeat of Slot %d",
new_slots[i], other_slots[octet1 - 1], octet1);
other_slots[new_slots[i] - 1] = other_slots[octet1 - 1];
}
else
{
proto_tree_add_text(sched_subtree, tvb, offset++, 1,
"Slot: %d, Apparent forward reference to slot %d",
new_slots[i], octet1);
}
}
else if (octet1 == 0x40)
{
proto_tree_add_text(sched_subtree, tvb, offset++, 1, "Slot: %d Free Message Slot, optional reading", new_slots[k]);
other_slots[new_slots[i] - 1] = 0xFFFE;
}
else if (octet1 == 0x41)
{
proto_tree_add_text(sched_subtree, tvb, offset++, 1, "Slot: %d Free Message Slot, reading advised", new_slots[k]);
other_slots[new_slots[i] - 1] = 0xFFFE;
}
else
{
proto_tree_add_text(sched_subtree, tvb, offset, 1, "Slot: %d reserved MDT: %x", new_slots[k], octet1);
other_slots[new_slots[i] - 1] = 0xFFFE;
}
}
proto_item_set_end(item, tvb, offset);
item = proto_tree_add_text(sched_tree, tvb, offset, 0, "Other message slots in this schedule");
sched_subtree = proto_item_add_subtree(item, ett_schedule_new_msg);
for (k=0; offset<len; j++)
{
while ((other_slots[k]!=0xFFFF) && (k<sched_end))
{
k++;
}
if (k >= sched_end)
break;
octet1 = tvb_get_guint8(tvb, offset);
if ((octet1 & 0x80) == 0x80)
{
if ((offset+1)<len)
{
guint8 octet2;
guint16 msg_id;
octet2 = tvb_get_guint8(tvb, offset + 1);
msg_id = ((octet1 &0x7F) << 8) + octet2;
other_slots[k] = msg_id;
proto_tree_add_text(sched_subtree, tvb, offset, 2,
"Slot: %d, Message: %d, First transmission of an SMSCB within the Schedule Period",
++k, msg_id);
offset +=2;
}
}
else if ((octet1 & 0xC0) == 0)
{
if (octet1 < k)
{
other_slots[k] = other_slots[octet1 - 1];
proto_tree_add_text(sched_subtree, tvb, offset++, 1,
"Slot: %d, Message ID: %d, Repeat of Slot %d",
++k, other_slots[octet1 - 1], octet1);
}
else
{
proto_tree_add_text(sched_subtree, tvb, offset++, 1,
"Slot: %d, Apparent forward reference to slot %d",
++k, octet1);
}
}
else if (octet1 == 0x40)
{
proto_tree_add_text(sched_subtree, tvb, offset++, 1, "Slot: %d Free Message Slot, optional reading", ++k);
}
else if (octet1 == 0x41)
{
proto_tree_add_text(sched_subtree, tvb, offset++, 1, "Slot: %d Free Message Slot, reading advised", ++k);
}
else
{
proto_tree_add_text(sched_subtree, tvb, offset, 1, "Slot: %d reserved MDT: %x", ++k, octet1);
}
}
proto_item_set_end(item, tvb, offset);
proto_tree_add_text(sched_tree, tvb, offset, -1, "Padding");
}
}
}
static void
dissect_cbch(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
fragment_data *frag_data = NULL;
guint8 octet, lb, lpd, seq_num;
guint32 offset;
guint32 len;
proto_item *cbch_item = NULL;
proto_tree *cbch_tree = NULL;
tvbuff_t *reass_tvb = NULL, *msg_tvb = NULL;
len = tvb_length(tvb);
offset = 0;
octet = tvb_get_guint8(tvb, offset);
cbch_item = proto_tree_add_protocol_format(tree, proto_cbch, tvb, 0, len,
"GSM CBCH - Block (0x%02x)", octet&3);
col_append_str(pinfo->cinfo, COL_PROTOCOL, " CBCH");
cbch_tree = proto_item_add_subtree(cbch_item, ett_cbch_msg);
proto_tree_add_text(cbch_tree, tvb, offset, 1, "CBCH Block");
proto_tree_add_uint(cbch_tree, hf_gsm_cbch_spare_bit, tvb, offset, 1, octet);
proto_tree_add_uint(cbch_tree, hf_gsm_cbch_lpd, tvb, offset, 1, octet);
proto_tree_add_uint(cbch_tree, hf_gsm_cbch_lb, tvb, offset, 1, octet);
proto_tree_add_uint(cbch_tree, hf_gsm_cbch_seq_num, tvb, offset, 1, octet);
seq_num = octet & 0x0F;
lpd = (octet & 0x60) >> 5;
lb = (octet & 0x10) >> 4;
if (lpd == 1)
{
switch (seq_num)
{
case 0x00:
case 0x08:
pinfo->fragmented = TRUE;
frag_data = fragment_add_seq_check(tvb, offset, pinfo, 0,
fragment_block_table, reassembled_message_table,
seq_num & 0x03, CBCH_FRAGMENT_SIZE + 1, !lb);
reass_tvb = process_reassembled_data(tvb, offset, pinfo, "Reassembled CBCH message",
frag_data, &cbch_frag_items, NULL, cbch_tree);
break;
case 0x01:
case 0x02:
case 0x03:
pinfo->fragmented = TRUE;
offset++;
frag_data = fragment_add_seq_check(tvb, offset, pinfo, 0,
fragment_block_table, reassembled_message_table, seq_num,
CBCH_FRAGMENT_SIZE, !lb);
reass_tvb = process_reassembled_data(tvb, offset, pinfo, "Reassembled CBCH message",
frag_data, &cbch_frag_items, NULL, cbch_tree);
break;
case 0x0F:
proto_tree_add_text(cbch_tree, tvb, offset, 1, "NULL message");
call_dissector(data_handle, tvb, pinfo, cbch_tree);
break;
default:
proto_tree_add_text(cbch_tree, tvb, offset, 1, "reserved Sequence Number");
call_dissector(data_handle, tvb, pinfo, cbch_tree);
break;
}
if (reass_tvb)
{
offset = 0;
octet = tvb_get_guint8(reass_tvb, offset++);
msg_tvb = tvb_new_subset_remaining(reass_tvb, offset);
if (octet & 0x08)
{
dissect_schedule_message(msg_tvb, pinfo, tree);
}
else
{
call_dissector(cbs_handle, msg_tvb, pinfo, tree);
}
}
}
else
{
proto_tree_add_text(cbch_tree, tvb, offset, 1, "invalid Link Protocol Discriminator");
call_dissector(data_handle, tvb, pinfo, cbch_tree);
}
}
void
proto_register_gsm_cbch(void)
{
static hf_register_info hf_smscb[] =
{
{ &hf_gsm_cbch_spare_bit,
{ "GSM CBCH spare bit", "gsm_cbch_block_type.spare",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL}
},
{ &hf_gsm_cbch_lpd,
{ "GSM CBCH Link Protocol Discriminator", "gsm_cbch_block_type.lpd",
FT_UINT8, BASE_DEC, VALS(block_type_lpd_strings), 0x60,
NULL, HFILL}
},
{ &hf_gsm_cbch_lb,
{ "GSM CBCH Last Block", "gsm_cbch_block_type.lb",
FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL}
},
{ &hf_gsm_cbch_seq_num,
{ "GSM CBCH Sequence Number", "gsm_cbch_block_type.seq_num",
FT_UINT8, BASE_DEC, VALS(block_type_seq_num_values), 0x0F,
NULL, HFILL}
},
{ &hf_gsm_cbch_sched_type,
{ "GSM CBCH Schedule Type", "gsm_cbch.sched_type",
FT_UINT8, BASE_DEC, VALS(sched_type_values), 0xC0,
NULL, HFILL}
},
{ &hf_gsm_cbch_sched_begin_slot,
{ "GSM CBCH Schedule Begin slot", "gsm_cbch.schedule_begin",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL}
},
{ &hf_gsm_cbch_sched_spare,
{ "GSM CBCH Schedule Spare Bits", "gsm_cbch.sched_spare",
FT_UINT8, BASE_DEC, NULL, 0xC0,
NULL, HFILL}
},
{ &hf_gsm_cbch_sched_end_slot,
{ "GSM CBCH Schedule End Slot", "gsm_cbch.sched_end",
FT_UINT8, BASE_DEC, NULL, 0x3F,
NULL, HFILL}
},
{ &hf_gsm_cbch_sched_msg_id,
{ "GSM CBCH Schedule Message ID", "gsm_cbch.sched_msg_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_cbch_fragment_overlap,
{ "Fragment overlap",
"gsm_cbch.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL
}
},
{ &hf_cbch_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap",
"gsm_cbch.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL
}
},
{ &hf_cbch_fragment_multiple_tails,
{ "Multiple tail fragments found",
"gsm_cbch.fragment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL
}
},
{ &hf_cbch_fragment_too_long_fragment,
{ "Fragment too long",
"gsm_cbch.fragment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL
}
},
{ &hf_cbch_fragment_error,
{ "Defragmentation error",
"gsm_cbch.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL
}
},
{ &hf_cbch_fragment_count,
{ "Fragmentation count",
"gsm_cbch.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of CBCH Fragments", HFILL
}
},
{ &hf_cbch_reassembled_in,
{ "Reassembled in",
"gsm_cbch.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"CBCH fragments are reassembled in the given packet", HFILL
}
},
{ &hf_cbch_reassembled_length,
{ "Reassembled message length is one less than indicated here",
"gsm_cbch.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled message", HFILL
}
},
{ &hf_cbch_fragment,
{ "CBCH Fragment",
"gsm_cbch.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_cbch_fragments,
{ "CBCH Fragments",
"gsm_cbch.fragments",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_cbch_msg,
&ett_schedule_msg,
&ett_schedule_new_msg,
&ett_cbch_fragment,
&ett_cbch_fragments,
};
proto_cbch = proto_register_protocol("GSM Cell Broadcast Channel", "GSM CBCH", "gsm_cbch");
proto_register_field_array(proto_cbch, hf_smscb, array_length(hf_smscb));
register_dissector("gsm_cbch", dissect_cbch, proto_cbch);
register_init_routine(cbch_defragment_init);
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_gsm_cbch(void)
{
data_handle = find_dissector("data");
cbs_handle = find_dissector("gsm_cell_broadcast");
}
