static int
dissect_remsysact_remotecreateinstance_rqst(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_dcom_this(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_nospec_data(tvb, offset, pinfo, tree, drep, 4);
offset = dissect_dcom_PMInterfacePointer(tvb, offset, pinfo, tree, drep,
hf_sysact_unknown, NULL );
return offset;
}
static int
dissect_remsysact_remotecreateinstance_resp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, guint8 *drep)
{
offset = dissect_dcom_that(tvb, offset, pinfo, tree, drep);
offset = dissect_dcom_PMInterfacePointer(tvb, offset, pinfo, tree, drep,
hf_sysact_unknown, NULL );
offset = dissect_dcom_HRESULT(tvb, offset, pinfo, tree, drep,
NULL );
return offset;
}
void
proto_register_ISystemActivator (void)
{
static hf_register_info hf[] = {
{ &hf_opnum,
{ "Operation", "isystemactivator.opnum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sysact_unknown,
{ "IUnknown", "isystemactivator.unknown", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ISystemActivator
};
proto_ISystemActivator = proto_register_protocol ("ISystemActivator ISystemActivator Resolver",
"ISystemActivator",
"isystemactivator");
proto_register_field_array (proto_ISystemActivator, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_ISystemActivator (void)
{
dcerpc_init_uuid (proto_ISystemActivator, ett_ISystemActivator,
&uuid_ISystemActivator, ver_ISystemActivator,
ISystemActivator_dissectors, hf_opnum);
}
