static int
gluster_gd_mgmt_dissect_uuid(tvbuff_t *tvb, proto_tree *tree, int hfindex,
int offset)
{
if (tree) {
e_guid_t uuid;
int start_offset = offset;
uuid.data1 = (tvb_get_ntohl(tvb, offset) & 0xff) << 24 |
(tvb_get_ntohl(tvb, offset+4) & 0xff) << 16 |
(tvb_get_ntohl(tvb, offset+8) & 0xff) << 8 |
(tvb_get_ntohl(tvb, offset+12) & 0xff);
offset += 16;
uuid.data2 = (tvb_get_ntohl(tvb, offset) & 0xff) << 8 |
(tvb_get_ntohl(tvb, offset+4) & 0xff);
offset += 8;
uuid.data3 = (tvb_get_ntohl(tvb, offset) & 0xff) << 8 |
(tvb_get_ntohl(tvb, offset+4) & 0xff);
offset += 8;
uuid.data4[0] = tvb_get_ntohl(tvb, offset);
offset += 4;
uuid.data4[1] = tvb_get_ntohl(tvb, offset);
offset += 4;
uuid.data4[2] = tvb_get_ntohl(tvb, offset);
offset += 4;
uuid.data4[3] = tvb_get_ntohl(tvb, offset);
offset += 4;
uuid.data4[4] = tvb_get_ntohl(tvb, offset);
offset += 4;
uuid.data4[5] = tvb_get_ntohl(tvb, offset);
offset += 4;
uuid.data4[6] = tvb_get_ntohl(tvb, offset);
offset += 4;
uuid.data4[7] = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_guid(tree, hfindex, tvb, start_offset, 4*16, &uuid);
} else
offset += 16 * 4;
return offset;
}
static int
gluster_gd_mgmt_probe_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_string(tvb, tree, hf_glusterd_hostname, offset,
NULL);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_port, offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
return offset;
}
static int
gluster_gd_mgmt_probe_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_string(tvb, tree, hf_glusterd_hostname, offset,
NULL);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_port, offset);
return offset;
}
static int
gluster_gd_mgmt_friend_add_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_string(tvb, tree, hf_glusterd_hostname, offset,
NULL);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_port, offset);
return offset;
}
static int
gluster_gd_mgmt_friend_add_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_string(tvb, tree, hf_glusterd_hostname, offset,
NULL);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_port, offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_vols, offset);
return offset;
}
static int
gluster_gd_mgmt_cluster_lock_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
return offset;
}
static int
gluster_gd_mgmt_cluster_lock_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
return offset;
}
static int
gluster_gd_mgmt_stage_op_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_string(tvb, tree, hf_glusterd_op_errstr, offset,
NULL);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
return offset;
}
static int
gluster_gd_mgmt_stage_op_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
return offset;
}
static int
gluster_gd_mgmt_commit_op_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_buf, offset);
offset = dissect_rpc_string(tvb, tree, hf_glusterd_op_errstr, offset,
NULL);
return offset;
}
static int
gluster_gd_mgmt_commit_op_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_buf,
offset);
return offset;
}
static int
gluster_gd_mgmt_friend_update_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
return offset;
}
static int
gluster_gd_mgmt_friend_update_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_vols,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_port, offset);
return offset;
}
static int
glusterd_mgmt_2_cluster_lock_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
return offset;
}
static int
glusterd_mgmt_2_cluster_lock_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
return offset;
}
static int
glusterd_mgmt_2_stage_op_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_string(tvb, tree, hf_glusterd_op_errstr, offset,
NULL);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
return offset;
}
static int
glusterd_mgmt_2_stage_op_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
return offset;
}
static int
glusterd_mgmt_2_commit_op_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_buf, offset);
offset = dissect_rpc_string(tvb, tree, hf_glusterd_op_errstr, offset,
NULL);
return offset;
}
static int
glusterd_mgmt_2_commit_op_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_buf, offset);
return offset;
}
static int
glusterd_mgmt_3_lock_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_tnx_id,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
return offset;
}
static int
glusterd_mgmt_3_lock_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_tnx_id,
offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
return offset;
}
static int
glusterd_mgmt_3_pre_val_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
return offset;
}
static int
glusterd_mgmt_3_pre_val_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_string(tvb, tree, hf_glusterd_op_errstr, offset,
NULL);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
return offset;
}
static int
glusterd_mgmt_3_commit_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
offset = dissect_rpc_string(tvb, tree, hf_glusterd_op_errstr, offset,
NULL);
return offset;
}
static int
glusterd_mgmt_3_post_val_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = gluster_gd_mgmt_dissect_uuid(tvb, tree, hf_glusterd_uuid,
offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op_ret, offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
return offset;
}
static int
glusterd_brick_2_common_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = dissect_rpc_string(tvb, tree, hf_glusterd_op_errstr, offset,
NULL);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
return offset;
}
static int
glusterd_brick_2_common_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree, hf_glusterd_name, offset,
NULL);
offset = dissect_rpc_uint32(tvb, tree, hf_glusterd_op, offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_glusterd_dict, offset);
return offset;
}
void
proto_register_gluster_gd_mgmt(void)
{
static hf_register_info hf[] = {
{ &hf_gd_mgmt_proc,
{ "Gluster Daemon Management", "glusterd.mgmt.proc",
FT_UINT32, BASE_DEC | BASE_EXT_STRING, &gd_mgmt_proc_vals_ext,
0, NULL, HFILL }
},
{ &hf_gd_mgmt_2_proc,
{ "Gluster Daemon Management", "glusterd.mgmt.proc",
FT_UINT32, BASE_DEC | BASE_EXT_STRING, &gd_mgmt_2_proc_vals_ext,
0, NULL, HFILL }
},
{ &hf_gd_mgmt_3_proc,
{ "Gluster Daemon Management", "glusterd.mgmt.proc",
FT_UINT32, BASE_DEC | BASE_EXT_STRING, &gd_mgmt_3_proc_vals_ext,
0, NULL, HFILL }
},
{ &hf_gd_mgmt_brick_2_proc,
{ "Gluster Daemon Brick Operations",
"glusterd.brick.proc", FT_UINT32, BASE_DEC | BASE_EXT_STRING,
&gd_mgmt_brick_2_proc_vals_ext, 0, NULL,
HFILL }
},
{ &hf_glusterd_friend_proc ,
{ "Gluster Daemon Friend Operations",
"glusterd.friend.proc", FT_UINT32, BASE_DEC | BASE_EXT_STRING,
&glusterd_friend_proc_vals_ext, 0, NULL,
HFILL }
},
{ &hf_glusterd_dict,
{ "Dict", "glusterd.dict", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_glusterd_op,
{ "Operation", "glusterd.op", FT_UINT32, BASE_DEC | BASE_EXT_STRING,
&glusterd_op_vals_ext, 0, NULL, HFILL }
},
{ &hf_glusterd_op_ret,
{ "Return of previous operation", "glusterd.op_ret",
FT_UINT32, BASE_DEC, NULL , 0, NULL, HFILL }
},
{ &hf_glusterd_op_errstr,
{ "Error", "glusterd.op_errstr", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_glusterd_uuid,
{ "UUID", "glusterd.uuid", FT_GUID,
BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_glusterd_tnx_id,
{ "Transaction ID", "glusterd.tnx_id", FT_GUID,
BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_glusterd_hostname,
{ "Hostname", "glusterd.hostname", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_glusterd_port,
{ "Port", "glusterd.port", FT_INT32, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_glusterd_vols,
{ "Volumes", "glusterd.vols", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_glusterd_buf,
{ "Buffer", "glusterd.buffer", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_glusterd_name,
{ "Name", "glusterd.name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_gd_mgmt,
&ett_gd_brick,
&ett_gd_friend
};
proto_glusterd = proto_register_protocol("Gluster Daemon", "GlusterD",
"glusterd");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_glusterd, hf, array_length(hf));
proto_gd_mgmt = proto_register_protocol("Gluster Daemon Management",
"GlusterD Management", "glusterd.mgmt");
proto_gd_brick = proto_register_protocol(
"Gluster Daemon Brick Operations",
"GlusterD Brick", "glusterd.brick");
proto_gd_friend = proto_register_protocol(
"Gluster Daemon Friend Operations",
"GlusterD Friend", "glusterd.friend");
}
void
proto_reg_handoff_gluster_gd_mgmt(void)
{
rpc_init_prog(proto_gd_mgmt, GD_MGMT_PROGRAM, ett_gd_mgmt);
rpc_init_proc_table(GD_MGMT_PROGRAM, 1, gd_mgmt_proc, hf_gd_mgmt_proc);
rpc_init_proc_table(GD_MGMT_PROGRAM, 2, gd_mgmt_2_proc,
hf_gd_mgmt_2_proc);
rpc_init_proc_table(GD_MGMT_PROGRAM, 3, gd_mgmt_3_proc,
hf_gd_mgmt_3_proc);
rpc_init_prog(proto_gd_brick, GD_BRICK_PROGRAM, ett_gd_brick);
rpc_init_proc_table(GD_BRICK_PROGRAM, 2, gd_mgmt_brick_2_proc,
hf_gd_mgmt_brick_2_proc);
rpc_init_prog(proto_gd_friend, GD_FRIEND_PROGRAM, ett_gd_friend);
rpc_init_proc_table(GD_FRIEND_PROGRAM, 2,glusterd_friend_proc,
hf_glusterd_friend_proc);
}
