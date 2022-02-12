static int
dissect_error(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree,
const gchar *packet_type,
guint32 *error)
{
const gchar *errstr;
*error = tvb_get_ntohl(tvb, offset);
errstr = val_to_str(*error, vxi11_core_error_vals, "Error %d");
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_error, offset);
if (tree)
{
proto_item_append_text(tree, " (%s) %s", packet_type, errstr);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", errstr);
return offset;
}
static int
dissect_flags(tvbuff_t *tvb, int offset, proto_tree *tree)
{
if (tree)
{
guint32 flags =
tvb_get_ntohl(tvb, offset);
proto_item *flags_item =
proto_tree_add_item(tree, hf_vxi11_core_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
if (flags_item)
{
proto_tree *flags_tree =
proto_item_add_subtree(flags_item, ett_vxi11_core_flags);
proto_tree_add_item(flags_tree, hf_vxi11_core_flag_wait_lock, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_vxi11_core_flag_end, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_vxi11_core_flag_term_chr_set, tvb, offset, 4, ENC_BIG_ENDIAN);
if (flags != 0)
{
wmem_strbuf_t *strbuf = wmem_strbuf_new_label(wmem_packet_scope());
if (flags & VXI11_CORE_FLAG_WAITLOCK)
{
wmem_strbuf_append(strbuf, "WAIT_LOCK, ");
}
if (flags & VXI11_CORE_FLAG_END)
{
wmem_strbuf_append(strbuf, "END, ");
}
if (flags & VXI11_CORE_FLAG_TERMCHRSET)
{
wmem_strbuf_append(strbuf, "TERM_CHR_SET, ");
}
wmem_strbuf_truncate(strbuf, wmem_strbuf_get_len(strbuf) - 2);
proto_item_append_text(flags_item, " (%s)", wmem_strbuf_get_str(strbuf));
}
}
}
return offset + 4;
}
static int
dissect_reason(tvbuff_t *tvb, int offset, proto_tree *tree)
{
if (tree)
{
guint32 reason =
tvb_get_ntohl(tvb, offset);
proto_item *reason_item =
proto_tree_add_item(tree, hf_vxi11_core_reason, tvb, offset, 4, ENC_BIG_ENDIAN);
if (reason_item)
{
proto_tree *reason_tree =
proto_item_add_subtree(reason_item, ett_vxi11_core_reason);
proto_tree_add_item(reason_tree, hf_vxi11_core_reason_req_cnt, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(reason_tree, hf_vxi11_core_reason_chr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(reason_tree, hf_vxi11_core_reason_end, tvb, offset, 4, ENC_BIG_ENDIAN);
if (reason != 0)
{
wmem_strbuf_t *strbuf = wmem_strbuf_new_label(wmem_packet_scope());
if (reason & VXI11_CORE_REASON_REQCNT)
{
wmem_strbuf_append(strbuf, "REQ_CNT, ");
}
if (reason & VXI11_CORE_REASON_CHR)
{
wmem_strbuf_append(strbuf, "CHR, ");
}
if (reason & VXI11_CORE_REASON_END)
{
wmem_strbuf_append(strbuf, "END, ");
}
wmem_strbuf_truncate(strbuf, wmem_strbuf_get_len(strbuf) - 2);
proto_item_append_text(reason_item, " (%s)", wmem_strbuf_get_str(strbuf));
}
}
}
return offset + 4;
}
static int
dissect_create_link_parms(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
const char *str;
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_client_id, offset);
offset = dissect_rpc_bool(tvb, tree, hf_vxi11_core_lock_device, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lock_timeout, offset);
offset = dissect_rpc_string(tvb, tree, hf_vxi11_core_device, offset, &str);
if (tree)
{
proto_item_append_text(tree, " (Create_LinkParms) %s", str);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", str);
return offset;
}
static int
dissect_create_link_resp(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 error, lid;
offset = dissect_error(tvb, offset, pinfo, tree, "Create_LinkResp", &error);
lid = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lid, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_abort_port, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_max_recv_size, offset);
if (error == VXI11_CORE_ERROR_NO_ERROR)
{
if (tree)
{
proto_item_append_text(tree, " LID=%d", lid);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " LID=%d", lid);
}
return offset;
}
static int
dissect_device_SRQ_parms(tvbuff_t *tvb,
int offset,
packet_info *pinfo _U_,
proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_opaque_data(tvb, offset, tree, NULL, hf_vxi11_intr_handle, FALSE, 0, FALSE, NULL, NULL);
if (tree)
{
proto_item_append_text(tree, " (Device_SrqParms)");
}
return offset;
}
static int
dissect_device_docmd_parms(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 lid, cmd;
const gchar *cmdstr;
lid = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lid, offset);
offset = dissect_flags(tvb, offset, tree);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_io_timeout, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lock_timeout, offset);
cmd = tvb_get_ntohl(tvb, offset);
cmdstr = val_to_str(cmd, vxi11_core_cmd_vals, "Unknown(0x%x)");
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_cmd, offset);
offset = dissect_rpc_bool(tvb, tree, hf_vxi11_core_network_order, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_size, offset);
offset = dissect_rpc_opaque_data(tvb, offset, tree, NULL, hf_vxi11_core_data, FALSE, 0, FALSE, NULL, NULL);
if (tree)
{
proto_item_append_text(tree, " (Device_DocmdParms) LID=%d CMD=%s", lid, cmdstr);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " LID=%d CMD=%s", lid, cmdstr);
return offset;
}
static int
dissect_device_docmd_resp(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 error;
offset = dissect_error(tvb, offset, pinfo, tree, "Device_DocmdResp", &error);
offset = dissect_rpc_opaque_data(tvb, offset, tree, NULL, hf_vxi11_core_data, FALSE, 0, FALSE, NULL, NULL);
return offset;
}
static int
dissect_device_enable_SRQ_parms(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 lid = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lid, offset);
offset = dissect_rpc_bool(tvb, tree, hf_vxi11_core_enable, offset);
offset = dissect_rpc_opaque_data(tvb, offset, tree, NULL, hf_vxi11_core_handle, FALSE, 0, FALSE, NULL, NULL);
if (tree)
{
proto_item_append_text(tree, " (Device_EnableSrqParms) LID=%d", lid);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " LID=%d", lid);
return offset;
}
static int
dissect_device_error(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 error;
return dissect_error(tvb, offset, pinfo, tree, "Device_Error", &error);
}
static int
dissect_device_generic_parms(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 lid = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lid, offset);
offset = dissect_flags(tvb, offset, tree);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_io_timeout, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lock_timeout, offset);
if (tree)
{
proto_item_append_text(tree, " (Device_GenericParms) LID=%d", lid);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " LID=%d", lid);
return offset;
}
static int
dissect_device_link(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 lid = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lid, offset);
if (tree)
{
proto_item_append_text(tree, " (Device_Link) LID=%d", lid);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " LID=%d", lid);
return offset;
}
static int
dissect_device_lock_parms(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 lid = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lid, offset);
offset = dissect_flags(tvb, offset, tree);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lock_timeout, offset);
if (tree)
{
proto_item_append_text(tree, " (Device_LockParms) LID=%d", lid);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " LID=%d", lid);
return offset;
}
static int
dissect_device_read_parms(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 lid = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lid, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_size, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_io_timeout, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lock_timeout, offset);
offset = dissect_flags(tvb, offset, tree);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_term_char, offset);
if (tree)
{
proto_item_append_text(tree, " (Device_ReadParms) LID=%d", lid);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " LID=%d", lid);
return offset;
}
static int
dissect_device_read_resp(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 error;
guint32 datalength = 0;
offset = dissect_error(tvb, offset, pinfo, tree, "Device_ReadResp", &error);
offset = dissect_reason(tvb, offset, tree);
datalength = tvb_get_ntohl( tvb, offset);
if(MAX_DATA_SHOW_SIZE <=datalength)
datalength = MAX_DATA_SHOW_SIZE;
col_append_fstr( pinfo->cinfo, COL_INFO," %s",tvb_format_text(tvb, offset+4,(guint32) datalength));
offset = dissect_rpc_opaque_data(tvb, offset, tree, NULL, hf_vxi11_core_data, FALSE, 0, FALSE, NULL, NULL);
return offset;
}
static int
dissect_device_readstb_resp(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 error, stb;
offset = dissect_error(tvb, offset, pinfo, tree, "Device_ReadStbResp", &error);
stb = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_stb, offset);
if (error == VXI11_CORE_ERROR_NO_ERROR)
{
if (tree)
{
proto_item_append_text(tree, " STB=0x%02x", stb);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " STB=0x%02x", stb);
}
return offset;
}
static int
dissect_device_remote_func(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 addr, port;
const gchar *addrstr;
addr = tvb_get_ipv4(tvb, offset);
addrstr = ip_to_str((guint8 *)&addr);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_host_addr, offset);
port = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_host_port, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_prog_num, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_prog_vers, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_prog_family, offset);
if (tree)
{
proto_item_append_text(tree, " (Device_RemoteFunc) %s:%d", addrstr, port);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " %s:%d", addrstr, port);
return offset;
}
static int
dissect_device_write_parms(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 datalength = 0;
guint32 lid = tvb_get_ntohl(tvb, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lid, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_io_timeout, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_lock_timeout, offset);
offset = dissect_flags(tvb, offset, tree);
col_append_fstr(pinfo->cinfo, COL_INFO, " LID=%d", lid);
datalength = tvb_get_ntohl( tvb, offset);
if(MAX_DATA_SHOW_SIZE <=datalength)
datalength = MAX_DATA_SHOW_SIZE;
col_append_fstr( pinfo->cinfo, COL_INFO," %s",tvb_format_text(tvb, offset+4,(guint32) datalength));
offset = dissect_rpc_opaque_data(tvb, offset, tree, NULL, hf_vxi11_core_data, FALSE, 0, FALSE, NULL, NULL);
if (tree)
{
proto_item_append_text(tree, " (Device_WriteParms) LID=%d", lid);
}
return offset;
}
static int
dissect_device_write_resp(tvbuff_t *tvb,
int offset,
packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
guint32 error;
offset = dissect_error(tvb, offset, pinfo, tree, "Device_WriteResp", &error);
offset = dissect_rpc_uint32(tvb, tree, hf_vxi11_core_size, offset);
return offset;
}
void
proto_register_vxi11_core(void)
{
static const value_string vxi11_core_v1_proc_vals[] = {
{ VXI11_CORE_PROC_NULL, "NULL" },
{ VXI11_CORE_PROC_CREATE_LINK, "CREATE_LINK" },
{ VXI11_CORE_PROC_DEVICE_WRITE, "DEVICE_WRITE" },
{ VXI11_CORE_PROC_DEVICE_READ, "DEVICE_READ" },
{ VXI11_CORE_PROC_DEVICE_READSTB, "DEVICE_READSTB" },
{ VXI11_CORE_PROC_DEVICE_TRIGGER, "DEVICE_TRIGGER" },
{ VXI11_CORE_PROC_DEVICE_CLEAR, "DEVICE_CLEAR" },
{ VXI11_CORE_PROC_DEVICE_REMOTE, "DEVICE_REMOTE" },
{ VXI11_CORE_PROC_DEVICE_LOCAL, "DEVICE_LOCAL" },
{ VXI11_CORE_PROC_DEVICE_LOCK, "DEVICE_LOCK" },
{ VXI11_CORE_PROC_DEVICE_UNLOCK, "DEVICE_UNLOCK" },
{ VXI11_CORE_PROC_DEVICE_ENABLE_SRQ, "DEVICE_ENABLE_SRQ" },
{ VXI11_CORE_PROC_DEVICE_DOCMD, "DEVICE_DOCMD" },
{ VXI11_CORE_PROC_DESTROY_LINK, "DESTROY_LINK" },
{ VXI11_CORE_PROC_CREATE_INTR_CHAN, "CREATE_INTR_CHAN" },
{ VXI11_CORE_PROC_DESTROY_INTR_CHAN, "DESTROY_INTR_CHAN" },
{ 0, NULL }
};
static const value_string vxi11_core_addr_family_vals[] = {
{ VXI11_CORE_ADDRESS_FAMILY_TCP, "TCP" },
{ VXI11_CORE_ADDRESS_FAMILY_UDP, "UDP" },
{ 0, NULL }
};
static hf_register_info vxi11_core_hf[] = {
{ &hf_vxi11_core_procedure_v1,
{
"V1 Procedure", "vxi11_core.procedure_v1", FT_UINT32, BASE_DEC,
VALS(vxi11_core_v1_proc_vals), 0, NULL, HFILL
}
},
{ &hf_vxi11_core_abort_port,
{
"Abort Port", "vxi11_core.abort_port", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_client_id,
{
"Client ID", "vxi11_core.client_id", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_cmd,
{
"Command", "vxi11_core.cmd", FT_UINT32, BASE_HEX,
VALS(vxi11_core_cmd_vals), 0, NULL, HFILL
}
},
{ &hf_vxi11_core_data,
{
"Data", "vxi11_core.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_device,
{
"Device Name", "vxi11_core.device", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_enable,
{
"Enable", "vxi11_core.enable", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_yes_no), 0, NULL, HFILL
}
},
{ &hf_vxi11_core_error,
{
"Error Code", "vxi11_core.error", FT_UINT32, BASE_DEC,
VALS(vxi11_core_error_vals), 0, NULL, HFILL
}
},
{ &hf_vxi11_core_flags,
{
"Flags", "vxi11_core.flags", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_flag_wait_lock,
{
"Wait Until Locked", "vxi11_core.flags.wait_lock", FT_BOOLEAN, 32,
NULL, VXI11_CORE_FLAG_WAITLOCK, NULL, HFILL
}
},
{ &hf_vxi11_core_flag_end,
{
"Set EOI", "vxi11_core.flags.end", FT_BOOLEAN, 32,
NULL, VXI11_CORE_FLAG_END, NULL, HFILL
}
},
{ &hf_vxi11_core_flag_term_chr_set,
{
"Termination Character Set", "vxi11_core.flags.term_chr_set", FT_BOOLEAN, 32,
NULL, VXI11_CORE_FLAG_TERMCHRSET, NULL, HFILL
}
},
{ &hf_vxi11_core_handle,
{
"Handle", "vxi11_core.handle", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_host_addr,
{
"Host Address", "vxi11_core.host_addr", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_host_port,
{
"Host Port", "vxi11_core.host_port", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_io_timeout,
{
"I/O Timeout", "vxi11_core.io_timeout", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_lid,
{
"Link ID", "vxi11_core.lid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_lock_device,
{
"Lock Device", "vxi11_core.lock_device", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_yes_no), 0, NULL, HFILL
}
},
{ &hf_vxi11_core_lock_timeout,
{
"Lock Timeout", "vxi11_core.lock_timeout", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_max_recv_size,
{
"Maximum Receive Size", "vxi11_core.max_recv_size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_network_order,
{
"Network Byte Order", "vxi11_core.network_order", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_yes_no), 0, NULL, HFILL
}
},
{ &hf_vxi11_core_prog_family,
{
"Address Family", "vxi11_core.prog_family", FT_UINT32, BASE_DEC,
VALS(vxi11_core_addr_family_vals), 0, NULL, HFILL
}
},
{ &hf_vxi11_core_prog_num,
{
"Program", "vxi11_core.prog_num", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_prog_vers,
{
"Version", "vxi11_core.prog_vers", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_reason,
{
"Reason", "vxi11_core.reason", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_reason_req_cnt,
{
"Requested Count Reached", "vxi11_core.reason.req_cnt", FT_BOOLEAN, 32,
NULL, VXI11_CORE_REASON_REQCNT, NULL, HFILL
}
},
{ &hf_vxi11_core_reason_chr,
{
"Termination Character Seen", "vxi11_core.reason.chr", FT_BOOLEAN, 32,
NULL, VXI11_CORE_REASON_CHR, NULL, HFILL
}
},
{ &hf_vxi11_core_reason_end,
{
"EOI Set", "vxi11_core.reason.end", FT_BOOLEAN, 32,
NULL, VXI11_CORE_REASON_END, NULL, HFILL
}
},
{ &hf_vxi11_core_size,
{
"Size", "vxi11_core.size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_stb,
{
"Status Byte", "vxi11_core.stb", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL
}
},
{ &hf_vxi11_core_term_char,
{
"Termination Character", "vxi11_core.term_char", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL
}
}
};
static gint *vxi11_core_ett[] = {
&ett_vxi11_core,
&ett_vxi11_core_flags,
&ett_vxi11_core_reason
};
proto_vxi11_core = proto_register_protocol("VXI-11 Core Protocol",
"VXI-11 Core",
"vxi11_core");
proto_register_field_array(proto_vxi11_core, vxi11_core_hf, array_length(vxi11_core_hf));
proto_register_subtree_array(vxi11_core_ett, array_length(vxi11_core_ett));
}
void
proto_reg_handoff_vxi11_core(void)
{
static const vsff vxi111_core_proc[] = {
{ VXI11_CORE_PROC_NULL, "NULL",
NULL, NULL },
{ VXI11_CORE_PROC_CREATE_LINK, "CREATE_LINK",
dissect_create_link_parms, dissect_create_link_resp },
{ VXI11_CORE_PROC_DEVICE_WRITE, "DEVICE_WRITE",
dissect_device_write_parms, dissect_device_write_resp },
{ VXI11_CORE_PROC_DEVICE_READ, "DEVICE_READ",
dissect_device_read_parms, dissect_device_read_resp },
{ VXI11_CORE_PROC_DEVICE_READSTB, "DEVICE_READSTB",
dissect_device_generic_parms, dissect_device_readstb_resp },
{ VXI11_CORE_PROC_DEVICE_TRIGGER, "DEVICE_TRIGGER",
dissect_device_generic_parms, dissect_device_error },
{ VXI11_CORE_PROC_DEVICE_CLEAR, "DEVICE_CLEAR",
dissect_device_generic_parms, dissect_device_error },
{ VXI11_CORE_PROC_DEVICE_REMOTE, "DEVICE_REMOTE",
dissect_device_generic_parms, dissect_device_error },
{ VXI11_CORE_PROC_DEVICE_LOCAL, "DEVICE_LOCAL",
dissect_device_generic_parms, dissect_device_error },
{ VXI11_CORE_PROC_DEVICE_LOCK, "DEVICE_LOCK",
dissect_device_lock_parms, dissect_device_error },
{ VXI11_CORE_PROC_DEVICE_UNLOCK, "DEVICE_UNLOCK",
dissect_device_link, dissect_device_error },
{ VXI11_CORE_PROC_DEVICE_ENABLE_SRQ, "DEVICE_ENABLE_SRQ",
dissect_device_enable_SRQ_parms, dissect_device_error },
{ VXI11_CORE_PROC_DEVICE_DOCMD, "DEVICE_DOCMD",
dissect_device_docmd_parms, dissect_device_docmd_resp },
{ VXI11_CORE_PROC_DESTROY_LINK, "DESTROY_LINK",
dissect_device_link, dissect_device_error },
{ VXI11_CORE_PROC_CREATE_INTR_CHAN, "CREATE_INTR_CHAN",
dissect_device_remote_func, dissect_device_error },
{ VXI11_CORE_PROC_DESTROY_INTR_CHAN, "DESTROY_INTR_CHAN",
NULL, dissect_device_error },
{ 0, NULL, NULL, NULL }
};
rpc_init_prog(proto_vxi11_core, VXI11_CORE_PROGRAM, ett_vxi11_core);
rpc_init_proc_table(VXI11_CORE_PROGRAM,
VXI11_CORE_VERSION,
vxi111_core_proc,
hf_vxi11_core_procedure_v1);
}
void
proto_register_vxi11_async(void)
{
static const value_string vxi11_async_v1_proc_vals[] = {
{ VXI11_ASYNC_PROC_NULL, "NULL" },
{ VXI11_ASYNC_PROC_DEVICE_ABORT, "DEVICE_ABORT" },
{ 0, NULL }
};
static hf_register_info vxi11_async_hf[] = {
{ &hf_vxi11_async_procedure_v1,
{
"V1 Procedure", "vxi11_async.procedure_v1", FT_UINT32, BASE_DEC,
VALS(vxi11_async_v1_proc_vals), 0, NULL, HFILL
}
}
};
static gint *vxi11_async_ett[] = {
&ett_vxi11_async,
};
proto_vxi11_async = proto_register_protocol("VXI-11 Asynchronous Abort",
"VXI-11 Async",
"vxi11_async");
proto_register_field_array(proto_vxi11_async, vxi11_async_hf, array_length(vxi11_async_hf));
proto_register_subtree_array(vxi11_async_ett, array_length(vxi11_async_ett));
}
void
proto_reg_handoff_vxi11_async(void)
{
static const vsff vxi111_async_proc[] = {
{ VXI11_ASYNC_PROC_NULL, "NULL",
NULL, NULL },
{ VXI11_ASYNC_PROC_DEVICE_ABORT, "DEVICE_ABORT",
dissect_device_link, dissect_device_error },
{ 0, NULL, NULL, NULL }
};
rpc_init_prog(proto_vxi11_async, VXI11_ASYNC_PROGRAM, ett_vxi11_async);
rpc_init_proc_table(VXI11_ASYNC_PROGRAM,
VXI11_ASYNC_VERSION,
vxi111_async_proc,
hf_vxi11_async_procedure_v1);
}
void
proto_register_vxi11_intr(void)
{
static const value_string vxi11_intr_v1_proc_vals[] = {
{ VXI11_INTR_PROC_NULL, "NULL" },
{ VXI11_INTR_PROC_DEVICE_INTR_SRQ, "DEVICE_INTR_SRQ" },
{ 0, NULL }
};
static hf_register_info vxi11_intr_hf[] = {
{ &hf_vxi11_intr_procedure_v1,
{
"V1 Procedure", "vxi11_intr.procedure_v1", FT_UINT32, BASE_DEC,
VALS(vxi11_intr_v1_proc_vals), 0, NULL, HFILL
}
},
{ &hf_vxi11_intr_handle,
{
"Handle", "vxi11_intr.handle", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL
}
}
};
static gint *vxi11_intr_ett[] = {
&ett_vxi11_intr,
};
proto_vxi11_intr = proto_register_protocol("VXI-11 Interrupt",
"VXI-11 Intr",
"vxi11_intr");
proto_register_field_array(proto_vxi11_intr, vxi11_intr_hf, array_length(vxi11_intr_hf));
proto_register_subtree_array(vxi11_intr_ett, array_length(vxi11_intr_ett));
}
void
proto_reg_handoff_vxi11_intr(void)
{
static const vsff vxi111_intr_proc[] = {
{ VXI11_INTR_PROC_NULL, "NULL",
NULL, NULL },
{ VXI11_INTR_PROC_DEVICE_INTR_SRQ, "DEVICE_INTR_SRQ",
dissect_device_SRQ_parms, NULL },
{ 0, NULL, NULL, NULL }
};
rpc_init_prog(proto_vxi11_intr, VXI11_INTR_PROGRAM, ett_vxi11_intr);
rpc_init_proc_table(VXI11_INTR_PROGRAM,
VXI11_INTR_VERSION,
vxi111_intr_proc,
hf_vxi11_intr_procedure_v1);
}
