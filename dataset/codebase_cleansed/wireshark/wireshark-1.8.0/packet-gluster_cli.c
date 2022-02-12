static int
gluster_cli_2_common_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree)
{
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_dict, offset);
return offset;
}
static int
gluster_cli_2_common_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
gchar* errstr= NULL;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree);
offset = dissect_rpc_string(tvb, tree, hf_gluster_op_errstr, offset,
&errstr);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_dict, offset);
return offset;
}
static int
gluster_cli_2_probe_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
gchar* hostname = NULL;
gchar* errstr = NULL;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_port, offset);
offset = dissect_rpc_string(tvb, tree, hf_gluster_hostname, offset,
&hostname);
offset = dissect_rpc_string(tvb, tree, hf_gluster_op_errstr, offset,
&errstr);
return offset;
}
static int
gluster_cli_2_probe_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree)
{
gchar* hostname = NULL;
offset = dissect_rpc_string(tvb, tree, hf_gluster_hostname, offset,
&hostname);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_port, offset);
return offset;
}
static int
gluster_cli_2_deprobe_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
gchar* hostname = NULL;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree);
offset = dissect_rpc_string(tvb, tree, hf_gluster_hostname, offset,
&hostname);
return offset;
}
static int
gluster_cli_2_deprobe_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree)
{
gchar* hostname = NULL;
offset = dissect_rpc_string(tvb, tree, hf_gluster_hostname, offset,
&hostname);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_port, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_flags, offset);
return offset;
}
static int
gluster_cli_2_fsm_log_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree)
{
gchar* name = NULL;
offset = dissect_rpc_string(tvb, tree, hf_gluster_wd, offset, &name);
return offset;
}
static int
gluster_cli_2_getwd_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
gchar* wd = NULL;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree);
offset = dissect_rpc_string(tvb, tree, hf_gluster_wd, offset, &wd);
return offset;
}
static int
gluster_cli_2_getwd_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_unused, offset);
return offset;
}
static int
gluster_cli_2_mount_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree)
{
gchar* label = NULL;
offset = dissect_rpc_string(tvb, tree, hf_gluster_label, offset,
&label);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_dict, offset);
return offset;
}
static int
gluster_cli_2_mount_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree)
{
gchar* path = NULL;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree);
offset = dissect_rpc_string(tvb, tree, hf_gluster_path, offset, &path);
return offset;
}
static int
gluster_cli_2_umount_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree)
{
gchar* path = NULL;
offset = dissect_rpc_uint32(tvb, tree,hf_gluster_lazy, offset);
offset = dissect_rpc_string(tvb, tree, hf_gluster_path, offset, &path);
return offset;
}
void
proto_register_gluster_cli(void)
{
static hf_register_info hf[] = {
{ &hf_gluster_cli_proc,
{ "Gluster CLI", "gluster.cli.proc", FT_UINT32,
BASE_DEC, VALS(gluster_cli_proc_vals), 0, NULL,
HFILL }
},
{ &hf_gluster_cli_2_proc,
{ "Gluster CLI", "gluster.cli.proc", FT_UINT32,
BASE_DEC, VALS(gluster_cli_2_proc_vals), 0,
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
rpc_init_prog(proto_gluster_cli, GLUSTER_CLI_PROGRAM, ett_gluster_cli);
rpc_init_proc_table(GLUSTER_CLI_PROGRAM, 1, gluster_cli_proc,
hf_gluster_cli_proc);
rpc_init_proc_table(GLUSTER_CLI_PROGRAM, 2, gluster_cli_2_proc,
hf_gluster_cli_2_proc);
}
