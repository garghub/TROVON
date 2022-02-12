static int
gluster_hndsk_setvolume_reply(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data)
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
proto_tree *tree, void* data)
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
proto_tree *tree, void* data)
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
proto_tree *tree, void* data)
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
packet_info *pinfo, proto_tree *tree, void* data)
{
int offset = 0;
offset = gluster_dissect_common_reply(tvb, offset, pinfo, tree, data);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_hndsk_dict,
offset);
return offset;
}
static int
glusterfs_rpc_dissect_upcall_flags(proto_tree *tree, tvbuff_t *tvb, int offset)
{
static const int *flag_bits[] = {
&hg_gluster_cbk_upcall_flag_nlink,
&hg_gluster_cbk_upcall_flag_mode,
&hg_gluster_cbk_upcall_flag_own,
&hg_gluster_cbk_upcall_flag_size,
&hg_gluster_cbk_upcall_flag_times,
&hg_gluster_cbk_upcall_flag_atime,
&hg_gluster_cbk_upcall_flag_perm,
&hg_gluster_cbk_upcall_flag_rename,
&hg_gluster_cbk_upcall_flag_forget,
&hg_gluster_cbk_upcall_flag_parent_times,
&hg_gluster_cbk_upcall_flag_xattr,
&hg_gluster_cbk_upcall_flag_xattr_rm,
NULL
};
if (tree)
proto_tree_add_bitmask(tree, tvb, offset,
hf_gluster_cbk_ci_flags, ett_gluster_cbk_flags,
flag_bits, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
gluster_cbk_cache_invalidation_call(tvbuff_t *tvb,
packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int offset = 0;
offset = dissect_rpc_string(tvb, tree, hf_gluster_cbk_gfid, offset, NULL);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_cbk_upcall_event_type, offset);
offset = glusterfs_rpc_dissect_upcall_flags(tree, tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_gluster_cbk_ci_expire_time_attr, offset);
offset = glusterfs_rpc_dissect_gf_iatt(tree, tvb,
hf_gluster_cbk_ci_stat, offset);
offset = glusterfs_rpc_dissect_gf_iatt(tree, tvb,
hf_gluster_cbk_ci_parent_stat, offset);
offset = glusterfs_rpc_dissect_gf_iatt(tree, tvb,
hf_gluster_cbk_ci_oldparent_stat, offset);
offset = gluster_rpc_dissect_dict(tree, tvb, hf_gluster_cbk_xdata, offset);
return offset;
}
static int
gluster_hndsk_dissect_common_reply(tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, void* data)
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
},
{ &hf_gluster_cbk_gfid,
{ "GFID", "glusterfs.cbk.gfid", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_gluster_cbk_upcall_event_type,
{ "Event Type", "glusterfs.cbk.upcall.event_type", FT_UINT32, BASE_DEC | BASE_EXT_STRING,
&gluster_cbk_upcall_event_type_ext, 0, NULL, HFILL }
},
{ &hf_gluster_cbk_ci_flags,
{ "Flags", "glusterfs.cbk.cache_invalidation.flags", FT_UINT32, BASE_DEC_HEX,
NULL, 0, NULL, HFILL }
},
{ &hf_gluster_cbk_ci_expire_time_attr,
{ "Expire Time Attr", "glusterfs.cbk.cache_invalidation.expire_time_attr",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_gluster_cbk_ci_stat,
{ "Stat", "glusterfs.cbk.cache_invalidation.stat", FT_NONE, BASE_NONE, NULL,
0, NULL, HFILL }
},
{ &hf_gluster_cbk_ci_parent_stat,
{ "Parent Stat", "glusterfs.cbk.cache_invalidation.parent.stat", FT_NONE, BASE_NONE, NULL,
0, NULL, HFILL }
},
{ &hf_gluster_cbk_ci_oldparent_stat,
{ "Old Parent Stat", "glusterfs.cbk.cache_invalidation.oldparent.stat",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_gluster_cbk_xdata,
{ "Xdata", "glusterfs.cbk.xdata", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_nlink,
{ "NLINK", "glusterfs.cbk.cache_invalidation.flag.nlink",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000001,
NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_mode,
{ "MODE", "glusterfs.cbk.cache_invalidation.flag.mode",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000002,
NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_own,
{ "OWN", "glusterfs.cbk.cache_invalidation.flag.own",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000004,
NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_size,
{ "SIZE", "glusterfs.cbk.cache_invalidation.flag.size",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000008,
NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_times,
{ "TIMES", "glusterfs.cbk.cache_invalidation.flag.times",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000010,
NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_atime,
{ "ATIME", "glusterfs.cbk.cache_invalidation.flag.atime",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000020,
NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_perm,
{ "PERM", "glusterfs.cbk.cache_invalidation.flag.perm",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000040,
NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_rename,
{ "RENAME", "glusterfs.cbk.cache_invalidation.flag.rename",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000080,
NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_forget,
{ "FORGET", "glusterfs.cbk.cache_invalidation.flag.forget",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000100,
NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_parent_times,
{ "PARENT_TIMES", "glusterfs.cbk.cache_invalidation.flag.parent_times",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000200,
NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_xattr,
{ "XATTR", "glusterfs.cbk.cache_invalidation.flag.xattr",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000400,
NULL, HFILL }
},
{ &hg_gluster_cbk_upcall_flag_xattr_rm,
{ "XATTR_RM", "glusterfs.cbk.cache_invalidation.flag.xattr_rm",
FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x00000800,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_gluster_cbk,
&ett_gluster_cbk_flags
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
