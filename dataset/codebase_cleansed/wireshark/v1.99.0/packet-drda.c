static void
drda_init(void)
{
iPreviousFrameNumber = 0;
}
static int
dissect_drda(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint offset = 0;
guint16 iCommand;
guint16 iLength;
guint16 iCommandEnd = 0;
guint8 iFormatFlags;
guint8 iDSSType;
guint8 iDSSFlags;
guint16 iParameterCP;
gint iLengthParam;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DRDA");
if (iPreviousFrameNumber != pinfo->fd->num)
col_clear(pinfo->cinfo, COL_INFO);
else
col_append_str(pinfo->cinfo, COL_INFO, " | ");
iPreviousFrameNumber = pinfo->fd->num;
while ((guint) (offset + 10) <= tvb_length(tvb))
{
iCommand = tvb_get_ntohs(tvb, offset + 8);
iLength = tvb_get_ntohs(tvb, offset + 0);
if (iLength < 10) {
expert_add_info_format(pinfo, NULL, &ei_drda_opcode_invalid_length, "Invalid length detected (%u): should be at least 10 bytes long", iLength);
break;
}
iCommandEnd += iLength;
if (offset > 0)
col_append_str(pinfo->cinfo, COL_INFO, " | ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_ext(iCommand, &drda_opcode_abbr_ext, "Unknown (0x%02x)"));
if (tree)
{
proto_tree *drda_tree;
proto_tree *drdaroot_tree;
proto_tree *drda_tree_sub;
proto_item *ti;
ti = proto_tree_add_item(tree, proto_drda, tvb, offset, -1, ENC_NA);
proto_item_append_text(ti, " (%s)", val_to_str_ext(iCommand, &drda_opcode_vals_ext, "Unknown (0x%02x)"));
drdaroot_tree = proto_item_add_subtree(ti, ett_drda);
drda_tree = proto_tree_add_subtree(drdaroot_tree, tvb, offset, 10, ett_drda_ddm, &ti, DRDA_TEXT_DDM);
proto_item_append_text(ti, " (%s)", val_to_str_ext(iCommand, &drda_opcode_abbr_ext, "Unknown (0x%02x)"));
proto_tree_add_item(drda_tree, hf_drda_ddm_length, tvb, offset + 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(drda_tree, hf_drda_ddm_magic, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
iFormatFlags = tvb_get_guint8(tvb, offset + 3);
iDSSType = iFormatFlags & 0x0F;
iDSSFlags = iFormatFlags >> 4;
ti = proto_tree_add_item(drda_tree, hf_drda_ddm_format, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
drda_tree_sub = proto_item_add_subtree(ti, ett_drda_ddm_format);
proto_tree_add_boolean(drda_tree_sub, hf_drda_ddm_fmt_reserved, tvb, offset + 3, 1, iDSSFlags);
proto_tree_add_boolean(drda_tree_sub, hf_drda_ddm_fmt_chained, tvb, offset + 3, 1, iDSSFlags);
proto_tree_add_boolean(drda_tree_sub, hf_drda_ddm_fmt_errcont, tvb, offset + 3, 1, iDSSFlags);
proto_tree_add_boolean(drda_tree_sub, hf_drda_ddm_fmt_samecorr, tvb, offset + 3, 1, iDSSFlags);
proto_tree_add_uint(drda_tree_sub, hf_drda_ddm_fmt_dsstyp, tvb, offset + 3, 1, iDSSType);
proto_tree_add_item(drda_tree, hf_drda_ddm_rc, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(drda_tree, hf_drda_ddm_length2, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(drda_tree, hf_drda_ddm_codepoint, tvb, offset + 8, 2, ENC_BIG_ENDIAN);
for (offset += 10; offset < iCommandEnd; )
{
if (tvb_length_remaining(tvb, offset) >= 2)
{
iLengthParam = tvb_get_ntohs(tvb, offset + 0);
if (iLengthParam == 0 || iLengthParam == 1) iLengthParam = iLength - 10;
if (tvb_length_remaining(tvb, offset) >= iLengthParam)
{
iParameterCP = tvb_get_ntohs(tvb, offset + 2);
drda_tree_sub = proto_tree_add_subtree(drdaroot_tree, tvb, offset, iLengthParam,
ett_drda_param, &ti, DRDA_TEXT_PARAM);
proto_item_append_text(ti, " (%s)", val_to_str_ext(iParameterCP, &drda_opcode_vals_ext, "Unknown (0x%02x)"));
proto_tree_add_item(drda_tree_sub, hf_drda_param_length, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(drda_tree_sub, hf_drda_param_codepoint, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(drda_tree_sub, hf_drda_param_data, tvb, offset + 4, iLengthParam - 4, ENC_UTF_8|ENC_NA);
proto_tree_add_item(drda_tree_sub, hf_drda_param_data_ebcdic, tvb, offset + 4, iLengthParam - 4, ENC_EBCDIC|ENC_NA);
if (iCommand == DRDA_CP_SQLSTT)
{
tvbuff_t* next_tvb = NULL;
next_tvb = tvb_new_subset_length(tvb, offset + 4, iLengthParam - 4);
add_new_data_source(pinfo, next_tvb, "SQL statement");
proto_tree_add_item(drdaroot_tree, hf_drda_sqlstatement, next_tvb, 0, iLengthParam - 5, ENC_UTF_8|ENC_NA);
proto_tree_add_item(drdaroot_tree, hf_drda_sqlstatement_ebcdic, next_tvb, 0, iLengthParam - 4, ENC_EBCDIC|ENC_NA);
}
}
offset += iLengthParam;
}
else
{
break;
}
}
}
else
{
offset += iLength;
}
}
return tvb_length(tvb);
}
static guint
get_drda_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
if (tvb_length_remaining(tvb, offset) >= 10)
{
return (tvb_get_ntohs(tvb, offset));
}
return 0;
}
static int
dissect_drda_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, drda_desegment, 10, get_drda_pdu_len, dissect_drda, data);
return tvb_length(tvb);
}
static gboolean
dissect_drda_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
conversation_t * conversation;
if (tvb_length(tvb) >= 10)
{
guint16 cOuterLength, cInnerLength;
cOuterLength = tvb_get_ntohs(tvb, 0);
cInnerLength = tvb_get_ntohs(tvb, 6);
if ((tvb_get_guint8(tvb, 2) == DRDA_MAGIC) && ((cOuterLength - cInnerLength) == 6))
{
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, drda_tcp_handle);
dissect_drda(tvb, pinfo, tree, data);
return TRUE;
}
}
return FALSE;
}
void
proto_register_drda(void)
{
static hf_register_info hf[] = {
{ &hf_drda_ddm_length,
{ "Length", "drda.ddm.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"DDM length", HFILL }},
{ &hf_drda_ddm_magic,
{ "Magic", "drda.ddm.ddmid",
FT_UINT8, BASE_HEX, NULL, 0x0,
"DDM magic", HFILL }},
{ &hf_drda_ddm_format,
{ "Format", "drda.ddm.format",
FT_UINT8, BASE_HEX, NULL, 0x0,
"DDM format", HFILL }},
{ &hf_drda_ddm_fmt_reserved,
{ "Reserved", "drda.ddm.fmt.bit0",
FT_BOOLEAN, 4, TFS(&tfs_set_notset), DRDA_DSSFMT_RESERVED,
"DSSFMT reserved", HFILL }},
{ &hf_drda_ddm_fmt_chained,
{ "Chained", "drda.ddm.fmt.bit1",
FT_BOOLEAN, 4, TFS(&tfs_set_notset), DRDA_DSSFMT_CHAINED,
"DSSFMT chained", HFILL }},
{ &hf_drda_ddm_fmt_errcont,
{ "Continue", "drda.ddm.fmt.bit2",
FT_BOOLEAN, 4, TFS(&tfs_set_notset), DRDA_DSSFMT_CONTINUE,
"DSSFMT continue on error", HFILL }},
{ &hf_drda_ddm_fmt_samecorr,
{ "Same correlation", "drda.ddm.fmt.bit3",
FT_BOOLEAN, 4, TFS(&tfs_set_notset), DRDA_DSSFMT_SAME_CORR,
"DSSFMT same correlation", HFILL }},
{ &hf_drda_ddm_fmt_dsstyp,
{ "DSS type", "drda.ddm.fmt.dsstyp",
FT_UINT8, BASE_DEC, VALS(drda_dsstyp_abbr), 0x0,
"DSSFMT type", HFILL }},
{ &hf_drda_ddm_rc,
{ "CorrelId", "drda.ddm.rqscrr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"DDM correlation identifier", HFILL }},
{ &hf_drda_ddm_length2,
{ "Length2", "drda.ddm.length2",
FT_UINT16, BASE_DEC, NULL, 0x0,
"DDM length2", HFILL }},
{ &hf_drda_ddm_codepoint,
{ "Code point", "drda.ddm.codepoint",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &drda_opcode_abbr_ext, 0x0,
"DDM code point", HFILL }},
{ &hf_drda_param_length,
{ "Length", "drda.param.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Param length", HFILL }},
{ &hf_drda_param_codepoint,
{ "Code point", "drda.param.codepoint",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &drda_opcode_abbr_ext, 0x0,
"Param code point", HFILL }},
{ &hf_drda_param_data,
{ "Data (ASCII)", "drda.param.data",
FT_STRING, BASE_NONE, NULL, 0x0,
"Param data left as ASCII for display", HFILL }},
{ &hf_drda_param_data_ebcdic,
{ "Data (EBCDIC)", "drda.param.data.ebcdic",
FT_STRING, BASE_NONE, NULL, 0x0,
"Param data converted from EBCDIC to ASCII for display", HFILL }},
{ &hf_drda_sqlstatement,
{ "SQL statement (ASCII)", "drda.sqlstatement",
FT_STRING, BASE_NONE, NULL, 0x0,
"SQL statement left as ASCII for display", HFILL }},
{ &hf_drda_sqlstatement_ebcdic,
{ "SQL statement (EBCDIC)", "drda.sqlstatement.ebcdic",
FT_STRING, BASE_NONE, NULL, 0x0,
"SQL statement converted from EBCDIC to ASCII for display", HFILL }}
};
static gint *ett[] = {
&ett_drda,
&ett_drda_ddm,
&ett_drda_ddm_format,
&ett_drda_param
};
static ei_register_info ei[] = {
{ &ei_drda_opcode_invalid_length, { "drda.opcode.invalid_length", PI_MALFORMED, PI_ERROR, "Invalid length detected", EXPFILL }},
};
module_t *drda_module;
expert_module_t* expert_drda;
proto_drda = proto_register_protocol("DRDA", "DRDA", "drda");
proto_register_field_array(proto_drda, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_drda = expert_register_protocol(proto_drda);
expert_register_field_array(expert_drda, ei, array_length(ei));
drda_module = prefs_register_protocol(proto_drda, NULL);
prefs_register_bool_preference(drda_module, "desegment",
"Reassemble DRDA messages spanning multiple TCP segments",
"Whether the DRDA dissector should reassemble messages spanning"
" multiple TCP segments."
" To use this option, you must also enable"
" \"Allow subdissectors to reassemble TCP streams\""
" in the TCP protocol settings.",
&drda_desegment);
register_init_routine(&drda_init);
}
void
proto_reg_handoff_drda(void)
{
heur_dissector_add("tcp", dissect_drda_heur, proto_drda);
drda_tcp_handle = new_create_dissector_handle(dissect_drda_tcp, proto_drda);
}
