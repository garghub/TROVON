void proto_register_mac_mgmt_msg_arq_feedback(void)
{
static hf_register_info hf[] =
{
{
&hf_arq_ack_type,
{
"ACK Type", "wmx.arq.ack_type",
FT_UINT8, BASE_DEC, VALS(vals_arq_ack_type), 0x60, NULL, HFILL
}
},
{
&hf_arq_bsn,
{
"BSN", "wmx.arq.bsn",
FT_UINT16, BASE_DEC, NULL, 0x1FFC, NULL, HFILL
}
},
{
&hf_arq_cid,
{
"Connection ID", "wmx.arq.cid",
FT_UINT16, BASE_DEC, NULL, 0x00, "The ID of the connection being referenced", HFILL
}
},
{
&hf_arq_discard_bsn,
{
"BSN", "wmx.arq.discard_bsn",
FT_UINT16, BASE_DEC, NULL, 0x07FF, NULL, HFILL
}
},
{
&hf_arq_discard_cid,
{
"Connection ID", "wmx.arq.discard_cid",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL
}
},
{
&hf_arq_discard_reserved,
{
"Reserved", "wmx.arq.discard_reserved",
FT_UINT8, BASE_DEC, NULL, 0xF8, NULL, HFILL
}
},
{
&hf_arq_last,
{
"LAST", "wmx.arq.last",
FT_BOOLEAN, 8, TFS(&tfs_arq_last), 0x80, NULL, HFILL
}
},
{
&hf_arq_num_ack_maps,
{
"Number of ACK Maps", "wmx.arq.num_maps",
FT_UINT8, BASE_DEC, NULL, 0x03, NULL, HFILL
}
},
{
&hf_arq_reserved,
{
"Reserved", "wmx.arq.reserved",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL
}
},
{
&hf_arq_reset_cid,
{
"Connection ID", "wmx.arq.reset_cid",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL
}
},
{
&hf_arq_reset_direction,
{
"Direction", "wmx.arq.reset_direction",
FT_UINT8, BASE_DEC, VALS(vals_arq_reset_direction), 0x30, NULL, HFILL
}
},
{
&hf_arq_reset_reserved,
{
"Reserved", "wmx.arq.reset_reserved",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL
}
},
{
&hf_arq_reset_type,
{
"Type", "wmx.arq.reset_type",
FT_UINT8, BASE_DEC, VALS(vals_arq_reset_type), 0xC0, NULL, HFILL
}
},
{
&hf_arq_selective_map,
{
"Selective ACK Map", "wmx.arq.selective_map",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_arq_0seq_ack_map,
{
"Sequence ACK Map", "wmx.arq.seq_ack_map",
FT_UINT8, BASE_HEX, NULL, 0x60, NULL, HFILL
}
},
{
&hf_arq_1seq_ack_map,
{
"Sequence ACK Map", "wmx.arq.seq_ack_map",
FT_UINT8, BASE_HEX, NULL, 0x70, NULL, HFILL
}
},
{
&hf_arq_seq_format,
{
"Sequence Format", "wmx.arq.seq_format",
FT_UINT8, BASE_DEC, NULL, 0x80, NULL, HFILL
}
},
{
&hf_arq_0seq1_len,
{
"Sequence 1 Length", "wmx.arq.seq1_len",
FT_UINT16, BASE_DEC, NULL, 0x1F80, NULL, HFILL
}
},
{
&hf_arq_0seq2_len,
{
"Sequence 2 Length", "wmx.arq.seq2_len",
FT_UINT16, BASE_DEC, NULL, 0x007E, NULL, HFILL
}
},
{
&hf_arq_1seq1_len,
{
"Sequence 1 Length", "wmx.arq.seq1_len",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL
}
},
{
&hf_arq_1seq2_len,
{
"Sequence 2 Length", "wmx.arq.seq2_len",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL
}
},
{
&hf_arq_1seq3_len,
{
"Sequence 3 Length", "wmx.arq.seq3_len",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL
}
},
{
&hf_ack_type_reserved,
{
"Reserved", "wmx.ack_type.reserved",
FT_UINT8, BASE_DEC, NULL, 0x03, NULL, HFILL
}
}
};
proto_mac_mgmt_msg_arq_decoder = proto_register_protocol (
"WiMax ARQ Feedback/Discard/Reset Messages",
"WiMax ARQ Feedback/Discard/Reset (arq)",
"wmx.arq"
);
proto_register_field_array(proto_mac_mgmt_msg_arq_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
static void dissect_mac_mgmt_msg_arq_feedback_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
guint offset = 0;
guint arq_feedback_ie_count = 0;
guint arq_cid;
gboolean arq_last = FALSE;
guint arq_ack_type;
guint arq_bsn;
guint arq_num_ack_maps;
guint tvb_len;
proto_item *arq_feedback_item;
proto_tree *arq_feedback_tree;
proto_item *arq_fb_item = NULL;
proto_tree *arq_fb_tree = NULL;
proto_item *ti = NULL;
guint i, seq_format;
{
tvb_len = tvb_reported_length(tvb);
arq_feedback_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_arq_decoder, tvb, offset, -1, "MAC Management Message, ARQ-Feedback");
arq_feedback_tree = proto_item_add_subtree(arq_feedback_item, ett_mac_mgmt_msg_arq_decoder);
while(offset < tvb_len && !arq_last)
{
arq_feedback_ie_count++;
arq_cid = tvb_get_ntohs(tvb, offset);
arq_last = ((tvb_get_guint8(tvb, offset + 2) & 0x80) != 0);
arq_ack_type = (tvb_get_guint8(tvb, offset + 2) & 0x60) >> 5;
arq_bsn = (tvb_get_ntohs(tvb, offset + 2) & 0x1FFC) >> 2;
arq_num_ack_maps = 1 + (tvb_get_guint8(tvb, offset + 3) & 0x03);
arq_fb_item = proto_tree_add_protocol_format(arq_feedback_tree, proto_mac_mgmt_msg_arq_decoder, tvb, offset, tvb_len, "ARQ_Feedback_IE");
proto_item_append_text(arq_fb_item, ", CID: %u, %s ARQ feedback IE, %s, BSN: %u",
arq_cid, arq_last ? "Last" : "More", val_to_str_const(arq_ack_type, vals_arq_ack_type, ""), arq_bsn);
if (arq_ack_type != ARQ_CUMULATIVE_ACK_ENTRY) {
proto_item_append_text(arq_fb_item, ", %u ACK Map(s)", arq_num_ack_maps);
}
arq_fb_tree = proto_item_add_subtree(arq_fb_item, ett_mac_mgmt_msg_arq_decoder);
proto_tree_add_item(arq_fb_tree, hf_arq_cid, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_fb_tree, hf_arq_last, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_fb_tree, hf_arq_ack_type, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_fb_tree, hf_arq_bsn, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (arq_ack_type != ARQ_CUMULATIVE_ACK_ENTRY) {
ti = proto_tree_add_item(arq_fb_tree, hf_arq_num_ack_maps, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%d map(s))", arq_num_ack_maps);
offset += 2;
for (i = 0; i < arq_num_ack_maps; i++) {
offset += 2;
if (arq_ack_type != 3) {
proto_tree_add_item(arq_fb_tree, hf_arq_selective_map, tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(arq_fb_tree, hf_arq_seq_format, tvb, offset, 1, ENC_BIG_ENDIAN);
seq_format = (tvb_get_guint8(tvb, offset) & 0x80) >> 7;
if (seq_format == 0) {
proto_tree_add_item(arq_fb_tree, hf_arq_0seq_ack_map, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_fb_tree, hf_arq_0seq1_len, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_fb_tree, hf_arq_0seq2_len, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_fb_tree, hf_arq_reserved, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(arq_fb_tree, hf_arq_1seq_ack_map, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_fb_tree, hf_arq_1seq1_len, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_fb_tree, hf_arq_1seq2_len, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_fb_tree, hf_arq_1seq3_len, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
}
}
} else {
proto_tree_add_item(arq_fb_tree, hf_ack_type_reserved, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
offset += 2;
}
offset += 2;
}
proto_item_append_text(arq_feedback_item, ", %u ARQ_feedback_IE(s)", arq_feedback_ie_count);
}
}
static void dissect_mac_mgmt_msg_arq_discard_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *arq_discard_item;
proto_tree *arq_discard_tree;
{
arq_discard_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_arq_decoder, tvb, 0, -1, "MAC Management Message, ARQ-Discard");
arq_discard_tree = proto_item_add_subtree(arq_discard_item, ett_mac_mgmt_msg_arq_decoder);
proto_tree_add_item(arq_discard_tree, hf_arq_discard_cid, tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_discard_tree, hf_arq_discard_reserved, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_discard_tree, hf_arq_discard_bsn, tvb, 3, 2, ENC_BIG_ENDIAN);
}
}
static void dissect_mac_mgmt_msg_arq_reset_decoder(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *arq_reset_item;
proto_tree *arq_reset_tree;
{
arq_reset_item = proto_tree_add_protocol_format(tree, proto_mac_mgmt_msg_arq_decoder, tvb, 0, -1, "MAC Management Message, ARQ-Reset");
arq_reset_tree = proto_item_add_subtree(arq_reset_item, ett_mac_mgmt_msg_arq_decoder);
proto_tree_add_item(arq_reset_tree, hf_arq_reset_cid, tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_reset_tree, hf_arq_reset_type, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_reset_tree, hf_arq_reset_direction, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(arq_reset_tree, hf_arq_reset_reserved, tvb, 3, 1, ENC_BIG_ENDIAN);
}
}
void
proto_reg_handoff_mac_mgmt_msg_arq(void)
{
dissector_handle_t arq_handle;
arq_handle = create_dissector_handle(dissect_mac_mgmt_msg_arq_feedback_decoder, proto_mac_mgmt_msg_arq_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_ARQ_FEEDBACK, arq_handle);
arq_handle = create_dissector_handle(dissect_mac_mgmt_msg_arq_discard_decoder, proto_mac_mgmt_msg_arq_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_ARQ_DISCARD, arq_handle);
arq_handle = create_dissector_handle(dissect_mac_mgmt_msg_arq_reset_decoder, proto_mac_mgmt_msg_arq_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_ARQ_RESET, arq_handle);
}
