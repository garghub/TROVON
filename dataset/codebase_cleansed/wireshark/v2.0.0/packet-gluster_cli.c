static int
gluster_cli_2_common_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
return gluster_rpc_dissect_dict(tree, tvb, hf_gluster_dict, 0);
}
static int
gluster_cli_2_common_reply(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_string(tvb, tree, hf_gluster_op_errstr, offset,
NULL);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_dict, offset);
return offset;
}
static int
gluster_cli_2_probe_reply(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_port, offset);
offset = dissect_rpc_string(tvb, tree, hf_gluster_hostname, offset,
NULL);
offset = dissect_rpc_string(tvb, tree, hf_gluster_op_errstr, offset,
NULL);
return offset;
}
static int
gluster_cli_2_probe_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_string(tvb, tree, hf_gluster_hostname, offset,
NULL);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_port, offset);
return offset;
}
static int
gluster_cli_2_deprobe_reply(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_string(tvb, tree, hf_gluster_hostname, offset,
NULL);
return offset;
}
static int
gluster_cli_2_deprobe_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_string(tvb, tree, hf_gluster_hostname, offset,
NULL);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_port, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_flags, offset);
return offset;
}
static int
gluster_cli_2_fsm_log_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
return dissect_rpc_string(tvb, tree, hf_gluster_wd, 0, NULL);
}
static int
gluster_cli_2_getwd_reply(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_string(tvb, tree, hf_gluster_wd, offset, NULL);
return offset;
}
static int
gluster_cli_2_getwd_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
return dissect_rpc_uint32(tvb, tree, hf_gluster_unused, 0);
}
static int
gluster_cli_2_mount_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_string(tvb, tree, hf_gluster_label, offset,
NULL);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_dict, offset);
return offset;
}
static int
gluster_cli_2_mount_reply(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_string(tvb, tree, hf_gluster_path, offset, NULL);
return offset;
}
static int
gluster_cli_2_umount_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_lazy, offset);
offset = dissect_rpc_string(tvb, tree, hf_gluster_path, offset, NULL);
return offset;
}
static int
gluster_cli_dissect_common_reply(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
return gluster_dissect_common_reply(tvb, 0, pinfo, tree, data);
}
void
proto_register_gluster_cli(void)
{
static hf_register_info hf[] = {
{ &hf_gluster_cli_proc,
{ "Gluster CLI", "gluster.cli.proc", FT_UINT32,
BASE_DEC | BASE_EXT_STRING, &gluster_cli_proc_vals_ext, 0, NULL,
HFILL }
},
{ &hf_gluster_cli_2_proc,
{ "Gluster CLI", "gluster.cli.proc", FT_UINT32,
BASE_DEC | BASE_EXT_STRING, &gluster_cli_2_proc_vals_ext, 0,
NULL, HFILL }
},
{ &hf_gluster_dict,
{ "Dict", "gluster.dict", FT_STRING, BASE_NONE, NULL,
0, NULL, HFILL }
},
{ &hf_gluster_path,
{ "Path", "gluster.path", FT_STRING, BASE_NONE, NULL,
0, NULL, HFILL }
},
{ &hf_gluster_lazy,
{ "Lazy", "gluster.lazy", FT_UINT32, BASE_HEX, NULL,
0, NULL, HFILL }
},
{ &hf_gluster_label,
{ "Label", "gluster.label", FT_STRING, BASE_NONE, NULL,
0, NULL, HFILL }
},
{ &hf_gluster_unused,
{ "Unused", "gluster.unused", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }
},
{ &hf_gluster_wd,
{ "Path", "gluster.wd", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gluster_op_errstr,
{ "Error", "gluster.op_errstr", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_gluster_hostname,
{ "Hostname", "gluster.hostname", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_gluster_port,
{ "Port", "gluster.port", FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_gluster_flags,
{ "Flags", "gluster.flag", FT_UINT32, BASE_HEX, NULL,
0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_gluster_cli
};
proto_gluster_cli = proto_register_protocol("Gluster CLI",
"Gluster CLI", "gluster.cli");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_gluster_cli, hf, array_length(hf));
}
void
proto_reg_handoff_gluster_cli(void)
{
rpc_init_prog(proto_gluster_cli, GLUSTER_CLI_PROGRAM, ett_gluster_cli,
G_N_ELEMENTS(gluster_cli_vers_info), gluster_cli_vers_info);
}
