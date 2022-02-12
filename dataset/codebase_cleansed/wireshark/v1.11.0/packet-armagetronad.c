static gboolean
is_armagetronad_packet(tvbuff_t * tvb)
{
gint offset = 0;
while (tvb_length_remaining(tvb, offset) > 2) {
gint data_len = tvb_get_ntohs(tvb, offset + 4) * 2;
#if 0
if (!try_val_to_str(tvb_get_ntohs(tvb, offset), descriptors))
return FALSE;
#endif
if (!tvb_bytes_exist(tvb, offset + 6, data_len))
return FALSE;
offset += 6 + data_len;
}
return tvb_length_remaining(tvb, offset) == 2;
}
static void
add_message_data(tvbuff_t * tvb, gint offset, gint data_len, proto_tree * tree)
{
gchar *data = NULL;
gchar tmp;
int i;
if (!tree)
return;
data = (gchar *)tvb_memcpy(tvb, wmem_alloc(wmem_packet_scope(), data_len + 1), offset, data_len);
data[data_len] = '\0';
for (i = 0; i < data_len; i += 2) {
if (!data[i])
data[i] = ' ';
if (!data[i+1])
data[i+1] = ' ';
tmp = data[i];
data[i] = data[i+1];
data[i+1] = tmp;
}
proto_tree_add_string(tree, hf_armagetronad_data, tvb, offset,
data_len, (gchar *) data);
}
static gint
add_message(tvbuff_t * tvb, gint offset, proto_tree * tree, wmem_strbuf_t * info)
{
guint16 descriptor_id, message_id;
gint data_len;
proto_item *msg;
proto_tree *msg_tree;
const gchar *descriptor;
descriptor_id = tvb_get_ntohs(tvb, offset);
message_id = tvb_get_ntohs(tvb, offset + 2);
data_len = tvb_get_ntohs(tvb, offset + 4) * 2;
descriptor = val_to_str(descriptor_id, descriptors, "Unknown (%u)");
if (descriptor_id == ACK)
msg = proto_tree_add_none_format(tree,
hf_armagetronad_msg_subtree,
tvb, offset, data_len + 6,
"ACK %d messages",
data_len / 2);
else
msg = proto_tree_add_none_format(tree,
hf_armagetronad_msg_subtree,
tvb, offset, data_len + 6,
"Message 0x%04x [%s]",
message_id, descriptor);
msg_tree = proto_item_add_subtree(msg, ett_message);
proto_tree_add_item(msg_tree, hf_armagetronad_descriptor_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
if (info)
wmem_strbuf_append_printf(info, "%s, ", descriptor);
proto_tree_add_item(msg_tree, hf_armagetronad_message_id, tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(msg_tree, hf_armagetronad_data_len, tvb,
offset + 4, 2, ENC_BIG_ENDIAN);
add_message_data(tvb, offset + 6, data_len, msg_tree);
return data_len + 6;
}
static gint
dissect_armagetronad(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * data _U_)
{
proto_item *ti;
proto_tree *armagetronad_tree;
guint16 sender;
gint offset = 0;
wmem_strbuf_t *info;
gsize new_len;
if (!is_armagetronad_packet(tvb))
return 0;
info = wmem_strbuf_new(wmem_packet_scope(), "");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Armagetronad");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_armagetronad, tvb, 0, -1, ENC_NA);
armagetronad_tree = proto_item_add_subtree(ti, ett_armagetronad);
while (tvb_length_remaining(tvb, offset) > 2)
offset += add_message(tvb, offset, armagetronad_tree, info);
sender = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ti, hf_armagetronad_sender_id, tvb, offset, 2,
ENC_BIG_ENDIAN);
new_len = wmem_strbuf_get_len(info) - 2;
if (new_len > 0)
wmem_strbuf_truncate(info, new_len);
else
info = wmem_strbuf_new(wmem_packet_scope(), "No message");
col_add_fstr(pinfo->cinfo, COL_INFO, "[%s] from 0x%04x",
wmem_strbuf_get_str(info), sender);
return offset + 2;
}
void proto_register_armagetronad(void)
{
static hf_register_info hf[] = {
{&hf_armagetronad_descriptor_id,
{"Descriptor", "armagetronad.descriptor_id",
FT_UINT16, BASE_DEC, VALS(descriptors), 0x0,
"The ID of the descriptor (the command)", HFILL}
},
{&hf_armagetronad_message_id,
{"MessageID", "armagetronad.message_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
"The ID of the message (to ack it)", HFILL}
},
{&hf_armagetronad_data_len,
{"DataLen", "armagetronad.data_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The length of the data (in shorts)", HFILL}
},
{&hf_armagetronad_data,
{"Data", "armagetronad.data",
FT_STRING, BASE_NONE, NULL, 0x0,
"The actual data (array of shorts in network order)", HFILL}
},
{&hf_armagetronad_sender_id,
{"SenderID", "armagetronad.sender_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
"The ID of the sender (0x0000 for the server)", HFILL}
},
{&hf_armagetronad_msg_subtree,
{"Message", "armagetronad.message",
FT_NONE, BASE_NONE, NULL, 0x0,
"A message", HFILL}
}
};
static gint *ett[] = {
&ett_armagetronad,
&ett_message
};
proto_armagetronad =
proto_register_protocol("The Armagetron Advanced OpenGL Tron clone",
"Armagetronad", "armagetronad");
proto_register_field_array(proto_armagetronad, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("armagetronad", dissect_armagetronad,
proto_armagetronad);
}
void proto_reg_handoff_armagetronad(void)
{
dissector_handle_t armagetronad_handle;
armagetronad_handle = find_dissector("armagetronad");
dissector_add_uint("udp.port", UDP_PORT_ARMAGETRONAD, armagetronad_handle);
dissector_add_uint("udp.port", UDP_PORT_MASTER, armagetronad_handle);
}
