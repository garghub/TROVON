static void
dissect_sccpmg_affected_ssn(tvbuff_t *tvb, proto_tree *sccpmg_tree)
{
proto_tree_add_item(sccpmg_tree, hf_sccpmg_affected_ssn, tvb,
SCCPMG_AFFECTED_SSN_OFFSET, SCCPMG_SSN_LENGTH,
ENC_BIG_ENDIAN);
}
static void
dissect_sccpmg_affected_pc(tvbuff_t *tvb, proto_tree *sccpmg_tree)
{
guint8 offset = SCCPMG_AFFECTED_PC_OFFSET;
if (mtp3_standard == ITU_STANDARD) {
proto_tree_add_item(sccpmg_tree, hf_sccpmg_affected_itu_pc, tvb,
offset, ITU_PC_LENGTH, ENC_LITTLE_ENDIAN);
} else if (mtp3_standard == JAPAN_STANDARD) {
proto_tree_add_item(sccpmg_tree, hf_sccpmg_affected_japan_pc,
tvb, offset, JAPAN_PC_LENGTH, ENC_LITTLE_ENDIAN);
} else {
int *hf_affected_pc;
if (mtp3_standard == ANSI_STANDARD)
{
hf_affected_pc = &hf_sccpmg_affected_ansi_pc;
} else {
hf_affected_pc = &hf_sccpmg_affected_chinese_pc;
}
dissect_mtp3_3byte_pc(tvb, offset, sccpmg_tree,
ett_sccpmg_affected_pc, *hf_affected_pc,
hf_sccpmg_affected_pc_network,
hf_sccpmg_affected_pc_cluster,
hf_sccpmg_affected_pc_member, 0, 0);
}
}
static void
dissect_sccpmg_smi(tvbuff_t *tvb, proto_tree *sccpmg_tree)
{
guint8 offset = 0;
if (mtp3_standard == ITU_STANDARD || mtp3_standard == JAPAN_STANDARD)
offset = ITU_SCCPMG_SMI_OFFSET;
else
offset = ANSI_SCCPMG_SMI_OFFSET;
proto_tree_add_item(sccpmg_tree, hf_sccpmg_smi, tvb, offset,
SCCPMG_SMI_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_sccpmg_congestion_level(tvbuff_t *tvb, proto_tree *sccpmg_tree)
{
guint8 offset = 0;
if (mtp3_standard == CHINESE_ITU_STANDARD)
offset = CHINESE_ITU_SCCPMG_CONGESTION_OFFSET;
else
offset = ITU_SCCPMG_CONGESTION_OFFSET;
proto_tree_add_item(sccpmg_tree, hf_sccpmg_congestion_level, tvb,
offset, ITU_SCCPMG_CONGESTION_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_sccpmg_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *sccpmg_tree)
{
guint8 message_type;
message_type = tvb_get_guint8(tvb, SCCPMG_MESSAGE_TYPE_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(message_type, sccpmg_message_type_acro_values, "Unknown"));
if (sccpmg_tree) {
proto_tree_add_uint(sccpmg_tree, hf_sccpmg_message_type, tvb,
SCCPMG_MESSAGE_TYPE_OFFSET,
SCCPMG_MESSAGE_TYPE_LENGTH, message_type);
}
switch(message_type) {
case SCCPMG_MESSAGE_TYPE_SBR:
case SCCPMG_MESSAGE_TYPE_SNR:
case SCCPMG_MESSAGE_TYPE_SRT:
if (mtp3_standard != ANSI_STANDARD)
{
proto_tree_add_expert(sccpmg_tree, pinfo, &ei_sccpmg_unknown_msg, tvb, 0, -1);
break;
}
case SCCPMG_MESSAGE_TYPE_SSA:
case SCCPMG_MESSAGE_TYPE_SSP:
case SCCPMG_MESSAGE_TYPE_SST:
case SCCPMG_MESSAGE_TYPE_SOR:
case SCCPMG_MESSAGE_TYPE_SOG:
dissect_sccpmg_affected_ssn(tvb, sccpmg_tree);
dissect_sccpmg_affected_pc(tvb, sccpmg_tree);
dissect_sccpmg_smi(tvb, sccpmg_tree);
break;
case SCCPMG_MESSAGE_TYPE_SSC:
if (mtp3_standard != ANSI_STANDARD)
{
dissect_sccpmg_affected_ssn(tvb, sccpmg_tree);
dissect_sccpmg_affected_pc(tvb, sccpmg_tree);
dissect_sccpmg_smi(tvb, sccpmg_tree);
dissect_sccpmg_congestion_level(tvb, sccpmg_tree);
}
default:
proto_tree_add_expert(sccpmg_tree, pinfo, &ei_sccpmg_unknown_msg, tvb, 0, -1);
}
}
static void
dissect_sccpmg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *sccpmg_item;
proto_tree *sccpmg_tree = NULL;
switch(mtp3_standard) {
case ITU_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SCCPMG (Int. ITU)");
break;
case ANSI_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SCCPMG (ANSI)");
break;
case CHINESE_ITU_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SCCPMG (Chin. ITU)");
break;
};
if (tree) {
sccpmg_item = proto_tree_add_item(tree, proto_sccpmg, tvb, 0,
-1, ENC_NA);
sccpmg_tree = proto_item_add_subtree(sccpmg_item, ett_sccpmg);
}
dissect_sccpmg_message(tvb, pinfo, sccpmg_tree);
}
void
proto_register_sccpmg(void)
{
static hf_register_info hf[] = {
{ &hf_sccpmg_message_type,
{ "Message Type", "sccpmg.message_type",
FT_UINT8, BASE_HEX, VALS(sccpmg_message_type_values), 0x0,
NULL, HFILL}},
{ &hf_sccpmg_affected_ssn,
{ "Affected SubSystem Number", "sccpmg.ssn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sccpmg_affected_itu_pc,
{ "Affected Point Code", "sccpmg.pc",
FT_UINT16, BASE_DEC, NULL, ITU_PC_MASK,
NULL, HFILL}},
{ &hf_sccpmg_affected_japan_pc,
{ "Affected Point Code", "sccpmg.pc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_sccpmg_affected_ansi_pc,
{ "Affected Point Code", "sccpmg.ansi_pc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_sccpmg_affected_chinese_pc,
{ "Affected Point Code", "sccpmg.chinese_pc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_sccpmg_affected_pc_network,
{ "Affected PC Network", "sccpmg.network",
FT_UINT24, BASE_DEC, NULL, ANSI_NETWORK_MASK,
NULL, HFILL}},
{ &hf_sccpmg_affected_pc_cluster,
{ "Affected PC Cluster", "sccpmg.cluster",
FT_UINT24, BASE_DEC, NULL, ANSI_CLUSTER_MASK,
NULL, HFILL}},
{ &hf_sccpmg_affected_pc_member,
{ "Affected PC Member", "sccpmg.member",
FT_UINT24, BASE_DEC, NULL, ANSI_MEMBER_MASK,
NULL, HFILL}},
{ &hf_sccpmg_smi,
{ "Subsystem Multiplicity Indicator", "sccpmg.smi",
FT_UINT8, BASE_DEC, NULL, SCCPMG_SMI_MASK,
NULL, HFILL}},
{ &hf_sccpmg_congestion_level,
{ "SCCP Congestion Level (ITU)", "sccpmg.congestion",
FT_UINT8, BASE_DEC, NULL, ITU_SCCPMG_CONGESTION_MASK,
NULL, HFILL}}
};
static gint *ett[] = {
&ett_sccpmg,
&ett_sccpmg_affected_pc
};
static ei_register_info ei[] = {
{ &ei_sccpmg_unknown_msg, { "sccpmg.unknown_msg", PI_UNDECODED, PI_WARN, "Unknown message", EXPFILL }},
};
expert_module_t* expert_sccpmg;
proto_sccpmg = proto_register_protocol("Signalling Connection Control Part Management",
"SCCPMG", "sccpmg");
proto_register_field_array(proto_sccpmg, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_sccpmg = expert_register_protocol(proto_sccpmg);
expert_register_field_array(expert_sccpmg, ei, array_length(ei));
}
void
proto_reg_handoff_sccpmg(void)
{
dissector_handle_t sccpmg_handle;
sccpmg_handle = create_dissector_handle(dissect_sccpmg, proto_sccpmg);
dissector_add_uint("sccp.ssn", SCCPMG_SSN, sccpmg_handle);
}
