static int
conv_dissect_who_are_you_rqst (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
e_uuid_t actuid;
offset = dissect_ndr_uuid_t (tvb, offset, pinfo, tree, drep, hf_conv_who_are_you_rqst_actuid, &actuid);
offset = dissect_ndr_time_t (tvb, offset, pinfo, tree, drep, hf_conv_who_are_you_rqst_boot_time, NULL);
col_add_fstr(pinfo->cinfo, COL_INFO,
"conv_who_are_you request actuid: %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
actuid.Data1, actuid.Data2, actuid.Data3,
actuid.Data4[0], actuid.Data4[1], actuid.Data4[2], actuid.Data4[3],
actuid.Data4[4], actuid.Data4[5], actuid.Data4[6], actuid.Data4[7]);
return offset;
}
static int
conv_dissect_who_are_you_resp (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint32 seq, st;
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep, hf_conv_who_are_you_resp_seq, &seq);
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep, hf_conv_rc, &st);
col_add_fstr(pinfo->cinfo, COL_INFO, "conv_who_are_you response seq:%u st:%s",
seq, val_to_str_ext(st, &dce_error_vals_ext, "%u"));
return offset;
}
static int
conv_dissect_who_are_you2_rqst (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
e_uuid_t actuid;
offset = dissect_ndr_uuid_t (tvb, offset, pinfo, tree, drep, hf_conv_who_are_you2_rqst_actuid, &actuid);
offset = dissect_ndr_time_t (tvb, offset, pinfo, tree, drep, hf_conv_who_are_you2_rqst_boot_time, NULL);
col_add_fstr(pinfo->cinfo, COL_INFO,
"conv_who_are_you2 request actuid: %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
actuid.Data1, actuid.Data2, actuid.Data3,
actuid.Data4[0], actuid.Data4[1], actuid.Data4[2], actuid.Data4[3],
actuid.Data4[4], actuid.Data4[5], actuid.Data4[6], actuid.Data4[7]);
return offset;
}
static int
conv_dissect_who_are_you2_resp (tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree,
guint8 *drep)
{
guint32 seq, st;
e_uuid_t cas_uuid;
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep, hf_conv_who_are_you2_resp_seq, &seq);
offset = dissect_ndr_uuid_t (tvb, offset, pinfo, tree, drep, hf_conv_who_are_you2_resp_casuuid, &cas_uuid);
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep, hf_conv_rc, &st);
col_add_fstr(pinfo->cinfo, COL_INFO,
"conv_who_are_you2 response seq:%u st:%s cas:%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
seq, val_to_str_ext(st, &dce_error_vals_ext, "%u"),
cas_uuid.Data1, cas_uuid.Data2, cas_uuid.Data3,
cas_uuid.Data4[0], cas_uuid.Data4[1], cas_uuid.Data4[2], cas_uuid.Data4[3],
cas_uuid.Data4[4], cas_uuid.Data4[5], cas_uuid.Data4[6], cas_uuid.Data4[7]);
return offset;
}
void
proto_register_conv (void)
{
static hf_register_info hf[] = {
{ &hf_conv_opnum,
{ "Operation", "conv.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_conv_rc,
{"Status", "conv.status", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &dce_error_vals_ext, 0x0, NULL, HFILL }},
{ &hf_conv_who_are_you_rqst_actuid,
{"Activity UID", "conv.who_are_you_rqst_actuid", FT_GUID, BASE_NONE, NULL, 0x0, "UUID", HFILL }},
{ &hf_conv_who_are_you_rqst_boot_time,
{"Boot time", "conv.who_are_you_rqst_boot_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL }},
{ &hf_conv_who_are_you2_rqst_actuid,
{"Activity UID", "conv.who_are_you2_rqst_actuid", FT_GUID, BASE_NONE, NULL, 0x0, "UUID", HFILL }},
{ &hf_conv_who_are_you2_rqst_boot_time,
{"Boot time", "conv.who_are_you2_rqst_boot_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL }},
{ &hf_conv_who_are_you_resp_seq,
{"Sequence Number", "conv.who_are_you_resp_seq", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_conv_who_are_you2_resp_seq,
{"Sequence Number", "conv.who_are_you2_resp_seq", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_conv_who_are_you2_resp_casuuid,
{"Client's address space UUID", "conv.who_are_you2_resp_casuuid", FT_GUID, BASE_NONE, NULL, 0x0, "UUID", HFILL }}
};
static gint *ett[] = {
&ett_conv
};
proto_conv = proto_register_protocol ("DCE/RPC Conversation Manager", "CONV", "conv");
proto_register_field_array (proto_conv, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_conv (void)
{
dcerpc_init_uuid (proto_conv, ett_conv, &uuid_conv, ver_conv, conv_dissectors, hf_conv_opnum);
}
