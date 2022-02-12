static guint32 tvb_get_guint32_endian(tvbuff_t *a_tvb, gint a_iOffset, gboolean a_bLittleEndian)
{
guint32 iResult;
if (a_bLittleEndian)
iResult = tvb_get_letohl(a_tvb, a_iOffset);
else
iResult = tvb_get_ntohl(a_tvb, a_iOffset);
return iResult;
}
static void
dissect_mqpcf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *mq_tree = NULL;
proto_tree *mqroot_tree = NULL;
proto_item *ti = NULL;
gint offset = 0;
struct mqinfo* mqinfo = (struct mqinfo *)pinfo->private_data;
gboolean bLittleEndian;
bLittleEndian = ((mqinfo->encoding & MQ_ENC_INTEGER_REVERSED) != 0) ? TRUE : FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MQ PCF");
col_clear(pinfo->cinfo, COL_INFO);
if (tvb_length(tvb) >= 36)
{
gint iSizeMQCFH = 36;
guint32 iCommand = tvb_get_guint32_endian(tvb, offset + 12, bLittleEndian);
if (check_col(pinfo->cinfo, COL_INFO))
{
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(iCommand, mqpcf_opcode_vals, "Unknown (0x%02x)"));
}
if (tree)
{
ti = proto_tree_add_item(tree, proto_mqpcf, tvb, offset, -1, ENC_NA);
proto_item_append_text(ti, " (%s)", val_to_str(iCommand, mqpcf_opcode_vals, "Unknown (0x%02x)"));
mqroot_tree = proto_item_add_subtree(ti, ett_mqpcf);
ti = proto_tree_add_text(mqroot_tree, tvb, offset, iSizeMQCFH, MQ_TEXT_CFH);
mq_tree = proto_item_add_subtree(ti, ett_mqpcf_cfh);
proto_tree_add_item(mq_tree, hf_mqpcf_cfh_type, tvb, offset + 0, 4, bLittleEndian);
proto_tree_add_item(mq_tree, hf_mqpcf_cfh_length, tvb, offset + 4, 4, bLittleEndian);
proto_tree_add_item(mq_tree, hf_mqpcf_cfh_version, tvb, offset + 8, 4, bLittleEndian);
proto_tree_add_item(mq_tree, hf_mqpcf_cfh_command, tvb, offset + 12, 4, bLittleEndian);
proto_tree_add_item(mq_tree, hf_mqpcf_cfh_msgseqnumber, tvb, offset + 16, 4, bLittleEndian);
proto_tree_add_item(mq_tree, hf_mqpcf_cfh_control, tvb, offset + 20, 4, bLittleEndian);
proto_tree_add_item(mq_tree, hf_mqpcf_cfh_compcode, tvb, offset + 24, 4, bLittleEndian);
proto_tree_add_item(mq_tree, hf_mqpcf_cfh_reason, tvb, offset + 28, 4, bLittleEndian);
proto_tree_add_item(mq_tree, hf_mqpcf_cfh_paramcount, tvb, offset + 32, 4, bLittleEndian);
}
offset += iSizeMQCFH;
}
}
static gboolean
dissect_mqpcf_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (tvb_length(tvb) >= 36)
{
struct mqinfo* mqinfo = (struct mqinfo *)pinfo->private_data;
if (strncmp((const char*)mqinfo->format, MQ_FMT_ADMIN, 8) == 0
|| strncmp((const char*)mqinfo->format, MQ_FMT_EVENT, 8) == 0
|| strncmp((const char*)mqinfo->format, MQ_FMT_PCF, 8) == 0)
{
dissect_mqpcf(tvb, pinfo, tree);
return TRUE;
}
}
return FALSE;
}
void
proto_register_mqpcf(void)
{
static hf_register_info hf[] = {
{ &hf_mqpcf_cfh_type,
{ "Type", "mqpcf.cfh.type", FT_UINT32, BASE_DEC, NULL, 0x0, "CFH type", HFILL }},
{ &hf_mqpcf_cfh_length,
{ "Length", "mqpcf.cfh.length", FT_UINT32, BASE_DEC, NULL, 0x0, "CFH length", HFILL }},
{ &hf_mqpcf_cfh_version,
{ "Version", "mqpcf.cfh.version", FT_UINT32, BASE_DEC, NULL, 0x0, "CFH version", HFILL }},
{ &hf_mqpcf_cfh_command,
{ "Command", "mqpcf.cfh.command", FT_UINT32, BASE_DEC, NULL, 0x0, "CFH command", HFILL }},
{ &hf_mqpcf_cfh_msgseqnumber,
{ "Message sequence number", "mqpcf.cfh.msgseqnumber", FT_UINT32, BASE_DEC, NULL, 0x0, "CFH message sequence number", HFILL }},
{ &hf_mqpcf_cfh_control,
{ "Control", "mqpcf.cfh.control", FT_UINT32, BASE_DEC, NULL, 0x0, "CFH control", HFILL }},
{ &hf_mqpcf_cfh_compcode,
{ "Completion code", "mqpcf.cfh.compcode", FT_UINT32, BASE_DEC, NULL, 0x0, "CFH completion code", HFILL }},
{ &hf_mqpcf_cfh_reason,
{ "Reason code", "mqpcf.cfh.reasoncode", FT_UINT32, BASE_DEC, NULL, 0x0, "CFH reason code", HFILL }},
{ &hf_mqpcf_cfh_paramcount,
{ "Parameter count", "mqpcf.cfh.paramcount", FT_UINT32, BASE_DEC, NULL, 0x0, "CFH parameter count", HFILL }}
};
static gint *ett[] = {
&ett_mqpcf,
&ett_mqpcf_cfh,
};
proto_mqpcf = proto_register_protocol("WebSphere MQ Programmable Command Formats", "MQ PCF", "mqpcf");
proto_register_field_array(proto_mqpcf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mqpcf(void)
{
heur_dissector_add("mq", dissect_mqpcf_heur, proto_mqpcf);
}
