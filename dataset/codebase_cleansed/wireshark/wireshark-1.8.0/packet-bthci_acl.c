static void
dissect_btacl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *btacl_tree = NULL;
guint16 flags, length;
gboolean fragmented;
int offset = 0;
guint16 pb_flag, l2cap_length = 0;
tvbuff_t *next_tvb;
bthci_acl_data_t *acl_data;
chandle_data_t *chandle_data;
void* pd_save;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HCI_ACL");
if (tree) {
ti = proto_tree_add_item(tree, proto_btacl, tvb, offset, -1, ENC_NA);
btacl_tree = proto_item_add_subtree(ti, ett_btacl);
}
flags = tvb_get_letohs(tvb, offset);
pb_flag = (flags & 0x3000) >> 12;
proto_tree_add_item(btacl_tree, hf_btacl_chandle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btacl_tree, hf_btacl_pb_flag, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(btacl_tree, hf_btacl_bc_flag, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
acl_data = ep_alloc(sizeof(bthci_acl_data_t));
acl_data->chandle = flags&0x0fff;
pd_save = pinfo->private_data;
pinfo->private_data = acl_data;
chandle_data = se_tree_lookup32(chandle_tree, acl_data->chandle);
if (!chandle_data) {
chandle_data = se_alloc(sizeof(chandle_data_t));
chandle_data->start_fragments = se_tree_create_non_persistent(EMEM_TREE_TYPE_RED_BLACK, "bthci_acl fragment starts");
se_tree_insert32(chandle_tree, acl_data->chandle, chandle_data);
}
length = tvb_get_letohs(tvb, offset);
proto_tree_add_item(btacl_tree, hf_btacl_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
switch(pb_flag) {
case 0x01:
fragmented = TRUE;
break;
case 0x00:
case 0x02:
l2cap_length = tvb_get_letohs(tvb, offset);
fragmented = ((l2cap_length+4)!=length);
break;
default:
fragmented = FALSE;
}
if ((!fragmented)
|| ((!acl_reassembly)&& !(pb_flag&0x01))) {
next_tvb = tvb_new_subset(tvb, offset, tvb_length_remaining(tvb, offset), length);
if (btl2cap_handle) {
call_dissector(btl2cap_handle, next_tvb, pinfo, tree);
}
pinfo->private_data = pd_save;
return;
}
if (fragmented && acl_reassembly) {
multi_fragment_pdu_t *mfp = NULL;
gint len;
if (!(pb_flag&0x01)) {
if (!pinfo->fd->flags.visited) {
mfp = se_alloc(sizeof(multi_fragment_pdu_t));
mfp->first_frame = pinfo->fd->num;
mfp->last_frame = 0;
mfp->tot_len = l2cap_length+4;
mfp->reassembled = se_alloc(mfp->tot_len);
len = tvb_length_remaining(tvb, offset);
if (len <= mfp->tot_len) {
tvb_memcpy(tvb, (guint8*)mfp->reassembled, offset, len);
mfp->cur_off = len;
se_tree_insert32(chandle_data->start_fragments, pinfo->fd->num, mfp);
}
} else {
mfp = se_tree_lookup32(chandle_data->start_fragments, pinfo->fd->num);
}
if (mfp != NULL && mfp->last_frame) {
proto_item *item;
item = proto_tree_add_uint(btacl_tree, hf_btacl_reassembled_in, tvb, 0, 0, mfp->last_frame);
PROTO_ITEM_SET_GENERATED(item);
col_append_fstr(pinfo->cinfo, COL_INFO, " [Reassembled in #%u]", mfp->last_frame);
}
}
if (pb_flag == 0x01) {
mfp = se_tree_lookup32_le(chandle_data->start_fragments, pinfo->fd->num);
if (!pinfo->fd->flags.visited) {
len = tvb_length_remaining(tvb, offset);
if (mfp != NULL && !mfp->last_frame && (mfp->tot_len>=mfp->cur_off+len)) {
tvb_memcpy(tvb, (guint8*)mfp->reassembled+mfp->cur_off, offset, len);
mfp->cur_off+=len;
if (mfp->cur_off == mfp->tot_len) {
mfp->last_frame = pinfo->fd->num;
}
}
}
if (mfp) {
proto_item *item;
item = proto_tree_add_uint(btacl_tree, hf_btacl_continuation_to, tvb, 0, 0, mfp->first_frame);
PROTO_ITEM_SET_GENERATED(item);
col_append_fstr(pinfo->cinfo, COL_INFO, " [Continuation to #%u]", mfp->first_frame);
}
if (mfp != NULL && mfp->last_frame == pinfo->fd->num) {
next_tvb = tvb_new_child_real_data(tvb, (guint8*)mfp->reassembled, mfp->tot_len, mfp->tot_len);
add_new_data_source(pinfo, next_tvb, "Reassembled BTHCI ACL");
if (btl2cap_handle) {
call_dissector(btl2cap_handle, next_tvb, pinfo, tree);
}
}
}
}
pinfo->private_data = pd_save;
}
void
proto_register_btacl(void)
{
static hf_register_info hf[] = {
{ &hf_btacl_chandle,
{ "Connection Handle", "bthci_acl.chandle",
FT_UINT16, BASE_HEX, NULL, 0x0FFF,
NULL, HFILL }
},
{ &hf_btacl_pb_flag,
{ "PB Flag", "bthci_acl.pb_flag",
FT_UINT16, BASE_DEC, VALS(pb_flag_vals), 0x3000,
"Packet Boundary Flag", HFILL }
},
{ &hf_btacl_bc_flag,
{ "BC Flag", "bthci_acl.bc_flag",
FT_UINT16, BASE_DEC, VALS(bc_flag_vals), 0xC000,
"Broadcast Flag", HFILL }
},
{ &hf_btacl_length,
{ "Data Total Length", "bthci_acl.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_btacl_data,
{ "Data", "bthci_acl.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_btacl_continuation_to,
{ "This is a continuation to the PDU in frame", "bthci_acl.continuation_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a continuation to the PDU in frame #", HFILL }
},
{ &hf_btacl_reassembled_in,
{ "This PDU is reassembled in frame", "bthci_acl.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This PDU is reassembled in frame #", HFILL }
},
};
static gint *ett[] = {
&ett_btacl,
};
module_t *btacl_module;
proto_btacl = proto_register_protocol("Bluetooth HCI ACL Packet", "HCI_ACL", "bthci_acl");
register_dissector("bthci_acl", dissect_btacl, proto_btacl);
proto_register_field_array(proto_btacl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
btacl_module = prefs_register_protocol(proto_btacl, NULL);
prefs_register_bool_preference(btacl_module, "btacl_reassembly",
"Reassemble ACL Fragments",
"Whether the ACL dissector should reassemble fragmented PDUs",
&acl_reassembly);
chandle_tree = se_tree_create(EMEM_TREE_TYPE_RED_BLACK, "bthci_acl chandles");
}
void
proto_reg_handoff_btacl(void)
{
dissector_handle_t bthci_acl_handle;
bthci_acl_handle = find_dissector("bthci_acl");
dissector_add_uint("hci_h4.type", HCI_H4_TYPE_ACL, bthci_acl_handle);
dissector_add_uint("hci_h1.type", BTHCI_CHANNEL_ACL, bthci_acl_handle);
btl2cap_handle = find_dissector("btl2cap");
}
