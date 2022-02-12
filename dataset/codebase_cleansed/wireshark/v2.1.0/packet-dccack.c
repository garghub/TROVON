static int
dissect_dccack (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
guint16 pos;
guint8 type, length;
proto_tree *dcc_tree;
proto_item *dcc_item;
guint16 len;
len = tvb_reported_length(tvb);
col_set_str(pinfo->cinfo, COL_INFO, "DCC-ACK Message: ");
if (tree)
{
dcc_item =
proto_tree_add_protocol_format (tree, proto_docsis_dccack, tvb, 0,
-1, "DCC-ACK Message");
dcc_tree = proto_item_add_subtree (dcc_item, ett_docsis_dccack);
proto_tree_add_item (dcc_tree, hf_docsis_dccack_tran_id, tvb, 0, 2, ENC_BIG_ENDIAN);
pos = 2;
while (pos < len)
{
type = tvb_get_guint8 (tvb, pos++);
length = tvb_get_guint8 (tvb, pos++);
switch (type)
{
case DCCACK_KEY_SEQ_NUM:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccack_key_seq_num, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCACK_HMAC_DIGEST:
if (length == 20)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccack_hmac_digest, tvb,
pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
break;
}
pos = pos + length;
}
}
return tvb_captured_length(tvb);
}
void
proto_register_docsis_dccack (void)
{
static hf_register_info hf[] = {
{&hf_docsis_dccack_tran_id ,
{
"Transaction ID",
"docsis_dccack.tran_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccack_key_seq_num ,
{
"Auth Key Sequence Number",
"docsis_dccack.key_seq_num",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccack_hmac_digest ,
{
"HMAC-DigestNumber",
"docsis_dccack.hmac_digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
};
static gint *ett[] = {
&ett_docsis_dccack,
};
proto_docsis_dccack =
proto_register_protocol ("DOCSIS Downstream Channel Change Acknowledge",
"DOCSIS DCC-ACK", "docsis_dccack");
proto_register_field_array (proto_docsis_dccack, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_dccack", dissect_dccack, proto_docsis_dccack);
}
void
proto_reg_handoff_docsis_dccack (void)
{
dissector_handle_t docsis_dccack_handle;
docsis_dccack_handle = find_dissector ("docsis_dccack");
dissector_add_uint ("docsis_mgmt", 0x19, docsis_dccack_handle);
}
