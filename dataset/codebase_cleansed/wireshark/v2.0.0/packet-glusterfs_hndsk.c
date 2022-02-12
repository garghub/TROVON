static int
gluster_hndsk_setvolume_reply(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_hndsk_dict,
offset);
return offset;
}
static int
gluster_hndsk_setvolume_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
return gluster_rpc_dissect_dict(tree, tvb, hf_gluster_hndsk_dict, 0);
}
static int
gluster_hndsk_2_setvolume_reply(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_hndsk_dict,
offset);
return offset;
}
static int
gluster_hndsk_2_setvolume_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
return gluster_rpc_dissect_dict(tree, tvb, hf_gluster_hndsk_dict, 0);
}
static int
gluster_hndsk_2_getspec_reply(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_string(tvb, tree, hf_gluster_hndsk_spec, offset,
NULL);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_hndsk_dict,
offset);
return offset;
}
static int
gluster_hndsk_2_getspec_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_gluster_hndsk_flags, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_rpc_string(tvb, tree, hf_gluster_hndsk_key, offset,
NULL);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_hndsk_dict,
offset);
return offset;
}
static int
gluster_hndsk_2_set_lk_ver_reply(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_uint32(tvb, tree,hf_gluster_hndsk_lk_ver, offset);
return offset;
}
static int
gluster_hndsk_2_set_lk_ver_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_string(tvb, tree, hf_gluster_hndsk_uid, offset,
NULL);
offset = dissect_rpc_uint32(tvb, tree,hf_gluster_hndsk_lk_ver, offset);
return offset;
}
static int
gluster_hndsk_2_event_notify_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_hndsk_event_op,
offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_hndsk_dict,
offset);
return offset;
}
static int
gluster_hndsk_2_event_notify_reply(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_hndsk_dict,
offset);
return offset;
}
static int
gluster_hndsk_dissect_common_reply(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, void* data _U_)
{
return gluster_dissect_common_reply(tvb, 0, pinfo, tree, data);
}
void
proto_register_gluster_hndsk(void)
{
static hf_register_info hf[] = {
{ &hf_gluster_hndsk_proc,
{ "GlusterFS Handshake", "glusterfs.hndsk.proc",
FT_UINT32, BASE_DEC,
VALS(gluster_hndsk_proc_vals), 0, NULL, HFILL }
},
{ &hf_gluster_hndsk_dict,
{ "Dict", "glusterfs.hndsk.dict", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_gluster_hndsk_event_op,
{ "Event Op", "glusterfs.hndsk.event_notify_op",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_gluster_hndsk_key,
{ "Key", "glusterfs.hndsk.getspec.key", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_gluster_hndsk_spec,
{ "Spec", "glusterfs.hndsk.getspec", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_gluster_hndsk_uid,
{ "Name", "glusterfs.hndsk.uid", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_gluster_hndsk_lk_ver,
{ "Event Op", "glusterfs.hndsk.lk_ver", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_gluster_hndsk_flags,
{ "Flags", "glusterfs.hndsk.flags", FT_UINT32, BASE_OCT,
NULL, 0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_gluster_hndsk
};
proto_gluster_hndsk = proto_register_protocol("GlusterFS Handshake",
"GlusterFS Handshake",
"glusterfs.hndsk");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_gluster_hndsk, hf, array_length(hf));
}
void
proto_reg_handoff_gluster_hndsk(void)
{
rpc_init_prog(proto_gluster_hndsk, GLUSTER_HNDSK_PROGRAM,
ett_gluster_hndsk,
G_N_ELEMENTS(gluster_hndsk_vers_info), gluster_hndsk_vers_info);
}
void
proto_register_gluster_cbk(void)
{
static hf_register_info hf[] = {
{ &hf_gluster_cbk_proc,
{ "GlusterFS Callback", "glusterfs.cbk.proc",
FT_UINT32, BASE_DEC,
VALS(gluster_cbk_proc_vals), 0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_gluster_cbk
};
proto_gluster_cbk = proto_register_protocol("GlusterFS Callback",
"GlusterFS Callback", "glusterfs.cbk");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_gluster_cbk, hf, array_length(hf));
}
void
proto_reg_handoff_gluster_cbk(void)
{
rpc_init_prog(proto_gluster_cbk, GLUSTER_CBK_PROGRAM, ett_gluster_cbk,
G_N_ELEMENTS(gluster_cbk_vers_info), gluster_cbk_vers_info);
}
