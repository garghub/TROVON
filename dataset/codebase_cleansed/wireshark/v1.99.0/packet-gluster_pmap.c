static int
gluster_pmap_portbybrick_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_brick_status, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_brick_port, offset);
return offset;
}
static int
gluster_pmap_portbybrick_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree, hf_gluster_brick, offset,
NULL);
return offset;
}
static int
gluster_dump_reply_detail(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
proto_item *detail_item;
proto_tree *detail_tree;
const gchar *progname = NULL;
detail_tree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_gluster_dump_detail, &detail_item, "Available Progam: ");
offset = dissect_rpc_string(tvb, detail_tree, hf_gluster_progname,
offset, &progname);
proto_item_append_text(detail_item, "%s", progname);
offset = dissect_rpc_uint64(tvb, detail_tree, hf_gluster_prognum,
offset);
offset = dissect_rpc_uint64(tvb, detail_tree, hf_gluster_progver,
offset);
return offset;
}
static int
gluster_dump_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_uint64(tvb, tree, hf_gluster_gfsid, offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_list(tvb, pinfo, tree, offset,
gluster_dump_reply_detail, NULL);
return offset;
}
static int
gluster_dump_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_uint64(tvb, tree, hf_gluster_gfsid, offset);
return offset;
}
void
proto_register_gluster_pmap(void)
{
static hf_register_info hf[] = {
{ &hf_gluster_pmap_proc,
{ "Gluster Portmap", "gluster.pmap.proc", FT_UINT32,
BASE_DEC, VALS(gluster_pmap_proc_vals), 0,
NULL, HFILL }
},
{ &hf_gluster_brick,
{ "Brick", "gluster.brick", FT_STRINGZ, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_gluster_brick_status,
{ "Status", "gluster.brick.status", FT_INT32, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_gluster_brick_port,
{ "Port", "gluster.brick.port", FT_INT32, BASE_DEC,
NULL, 0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_gluster_pmap
};
proto_gluster_pmap = proto_register_protocol("Gluster Portmap",
"Gluster Portmap", "gluster.pmap");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_gluster_pmap, hf, array_length(hf));
}
void
proto_reg_handoff_gluster_pmap(void)
{
rpc_init_prog(proto_gluster_pmap, GLUSTER_PMAP_PROGRAM,
ett_gluster_pmap);
rpc_init_proc_table(GLUSTER_PMAP_PROGRAM, 1, gluster_pmap_proc,
hf_gluster_pmap_proc);
}
void
proto_register_gluster_dump(void)
{
static hf_register_info hf[] = {
{ &hf_gluster_dump_proc,
{ "Gluster DUMP", "gluster.dump.proc", FT_UINT32,
BASE_DEC, VALS(gluster_dump_proc_vals), 0,
NULL, HFILL }
},
{ &hf_gluster_progname,
{ "Program Name", "gluster.dump.progname", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_gluster_prognum,
{ "Program Number", "gluster.dump.prognum",
FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_gluster_progver,
{ "Program Version", "gluster.dump.progver",
FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_gluster_gfsid,
{ "GFS ID", "gluster.gfsid", FT_UINT64, BASE_HEX, NULL,
0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_gluster_dump,
&ett_gluster_dump_detail
};
proto_gluster_dump = proto_register_protocol("Gluster Dump",
"Gluster Dump", "gluster.dump");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_gluster_dump, hf, array_length(hf));
}
void
proto_reg_handoff_gluster_dump(void)
{
rpc_init_prog(proto_gluster_dump, GLUSTER_DUMP_PROGRAM,
ett_gluster_dump);
rpc_init_proc_table(GLUSTER_DUMP_PROGRAM, 1, gluster_dump_proc,
hf_gluster_dump_proc);
}
