static void
dissect_dccrsp_cm_jump_time (tvbuff_t * tvb, proto_tree * tree, int start, guint16 len)
{
guint8 type, length;
proto_item *dcc_item;
proto_tree *dcc_tree;
int pos;
pos = start;
dcc_item = proto_tree_add_text ( tree, tvb, start, len, "2 DCC-RSP CM Time Jump Encodings (Length = %u)", len);
dcc_tree = proto_item_add_subtree ( dcc_item , ett_docsis_dccrsp_cm_jump_time);
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos++);
length = tvb_get_guint8 (tvb, pos++);
switch (type)
{
case DCCRSP_CM_JUMP_TIME_LENGTH:
if (length == 4)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccrsp_cm_jump_time_length, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCRSP_CM_JUMP_TIME_START:
if (length == 8)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccrsp_cm_jump_time_start, tvb,
pos, length, ENC_BIG_ENDIAN);
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
static void
dissect_dccrsp (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
guint16 pos;
guint8 type, length;
proto_tree *dcc_tree;
proto_item *dcc_item;
guint16 len;
len = tvb_length_remaining (tvb, 0);
col_set_str(pinfo->cinfo, COL_INFO, "DCC-RSP Message: ");
if (tree)
{
dcc_item =
proto_tree_add_protocol_format (tree, proto_docsis_dccrsp, tvb, 0,
tvb_length_remaining (tvb, 0),
"DCC-RSP Message");
dcc_tree = proto_item_add_subtree (dcc_item, ett_docsis_dccrsp);
proto_tree_add_item (dcc_tree, hf_docsis_dccrsp_tran_id, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (dcc_tree, hf_docsis_dccrsp_conf_code, tvb, 2, 1, ENC_BIG_ENDIAN);
pos = 3;
while (pos < len)
{
type = tvb_get_guint8 (tvb, pos++);
length = tvb_get_guint8 (tvb, pos++);
switch (type)
{
case DCCRSP_CM_JUMP_TIME:
dissect_dccrsp_cm_jump_time (tvb , dcc_tree , pos , length );
break;
case DCCRSP_KEY_SEQ_NUM:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccrsp_key_seq_num, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCRSP_HMAC_DIGEST:
if (length == 20)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccrsp_hmac_digest, tvb,
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
}
void
proto_register_docsis_dccrsp (void)
{
static hf_register_info hf[] = {
{&hf_docsis_dccrsp_tran_id ,
{
"Transaction ID",
"docsis_dccrsp.tran_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_conf_code ,
{
"Confirmation Code",
"docsis_dccrsp.conf_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_cm_jump_time_length ,
{
"Jump Time Length",
"docsis_dccrsp.cm_jump_time_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_cm_jump_time_start ,
{
"Jump Time Start",
"docsis_dccrsp.cm_jump_time_start",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_key_seq_num ,
{
"Auth Key Sequence Number",
"docsis_dccrsp.key_seq_num",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccrsp_hmac_digest ,
{
"HMAC-DigestNumber",
"docsis_dccrsp.hmac_digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
};
static gint *ett[] = {
&ett_docsis_dccrsp,
&ett_docsis_dccrsp_cm_jump_time,
};
proto_docsis_dccrsp =
proto_register_protocol ("DOCSIS Downstream Channel Change Response",
"DOCSIS DCC-RSP", "docsis_dccrsp");
proto_register_field_array (proto_docsis_dccrsp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_dccrsp", dissect_dccrsp, proto_docsis_dccrsp);
}
void
proto_reg_handoff_docsis_dccrsp (void)
{
dissector_handle_t docsis_dccrsp_handle;
docsis_dccrsp_handle = find_dissector ("docsis_dccrsp");
dissector_add_uint ("docsis_mgmt", 0x18, docsis_dccrsp_handle);
}
