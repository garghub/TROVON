static void
dissect_dlm3_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint length, int offset)
{
guint32 m_type;
m_type = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree,
hf_dlm3_m_type, tvb, offset, 4, m_type);
col_append_fstr(pinfo->cinfo, COL_INFO,
": %s",
val_to_str_const(m_type,
dlm3_msg,
"Unknown"));
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_nodeid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_pid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_lkid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_remid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_parent_lkid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_parent_remid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset,
hf_dlm3_m_exflags, ett_dlm3_m_exflags,
m_exflags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset,
hf_dlm3_m_sbflags, ett_dlm3_sbflags,
m_sbflags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset,
hf_dlm3_m_flags, ett_dlm3_m_flags,
m_flags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_lvbseq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_hash, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_status, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_grmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_rqmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_bastmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset,
hf_dlm3_m_asts, ett_dlm3_m_asts,
m_asts_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_m_result, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if ((length - offset) > 0) {
proto_tree_add_item(tree,
hf_dlm3_m_extra,
tvb,
offset,
-1,
ENC_NA);
}
}
static void
dissect_dlm3_rcom_lock(tvbuff_t *tvb, proto_tree *tree,
guint length, int offset)
{
proto_item *sub_item;
proto_tree *sub_tree;
int sub_offset;
guint16 namelen;
guint32 exflags;
if ((length - offset) < ( 4 * 8 + 4 + 1 * 4 + 2 * 2
+ DLM3_RESNAME_MAXLEN ))
return;
proto_tree_add_item(tree,
hf_dlm3_rl_ownpid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rl_lkid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rl_remid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rl_parent_lkid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rl_parent_remid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset,
hf_dlm3_rl_exflags, ett_dlm3_rl_exflags,
rl_exflags_fields, ENC_LITTLE_ENDIAN);
exflags = tvb_get_letohl(tvb, offset);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset,
hf_dlm3_rl_flags, ett_dlm3_rl_flags,
rl_flags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rl_lvbseq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rl_result, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rl_rqmode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree,
hf_dlm3_rl_grmode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree,
hf_dlm3_rl_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset,
hf_dlm3_rl_asts, ett_dlm3_rl_asts,
rl_asts_fields, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree,
hf_dlm3_rl_wait_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
namelen = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree,
hf_dlm3_rl_namelen, tvb, offset, 2,
namelen);
offset += 2;
sub_item = proto_tree_add_item(tree,
hf_dlm3_rl_name, tvb, offset,
DLM3_RESNAME_MAXLEN, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item,
ett_dlm3_rl_name);
sub_offset = offset;
proto_tree_add_item(sub_tree,
hf_dlm3_rl_name_contents, tvb, sub_offset,
namelen, ENC_ASCII|ENC_NA);
sub_offset += namelen;
proto_tree_add_item(sub_tree,
hf_dlm3_rl_name_padding, tvb, sub_offset,
DLM3_RESNAME_MAXLEN - namelen, ENC_NA);
offset += DLM3_RESNAME_MAXLEN;
if (((length - offset) > 0) && (exflags & DLM3_LKF_VALBLK))
proto_tree_add_item(tree,
hf_dlm3_rl_lvb, tvb, offset,
-1,
ENC_NA);
}
static void
dissect_dlm3_rcom_config(tvbuff_t *tvb, proto_tree *tree,
guint length, int offset)
{
if ((length - offset) < ( 4 + 4 + 8 ))
return;
proto_tree_add_item(tree,
hf_dlm3_rf_lvblen, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset,
hf_dlm3_rf_lsflags, ett_dlm3_rf_lsflags,
rf_lsflags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rf_unused, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
static void
dissect_dlm3_rcom(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint length, int offset)
{
guint32 rc_type;
proto_item *sub_item;
proto_tree *sub_tree;
rc_type = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree,
hf_dlm3_rc_type, tvb, offset, 4, rc_type);
col_append_fstr(pinfo->cinfo, COL_INFO,
": %s",
val_to_str_const(rc_type,
dlm3_rcom,
"Unknown"));
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rc_result, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rc_id, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree,
hf_dlm3_rc_seq, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree,
hf_dlm3_rc_seq_reply, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
if ((length - offset) == 0) {
return;
}
sub_item = proto_tree_add_item(tree,
hf_dlm3_rc_buf,
tvb,
offset,
-1,
ENC_NA);
offset += 0;
if (rc_type == DLM3_RCOM_LOCK) {
sub_tree = proto_item_add_subtree(sub_item,
ett_dlm3_rcom_lock);
dissect_dlm3_rcom_lock(tvb, sub_tree, length, offset);
} else if (rc_type == DLM3_RCOM_STATUS_REPLY) {
sub_tree = proto_item_add_subtree(sub_item,
ett_dlm3_rcom_config);
dissect_dlm3_rcom_config(tvb, sub_tree, length, offset);
}
}
static int
dissect_dlm3(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
proto_item *item, *sub_item;
proto_tree *tree, *sub_tree;
int offset;
guint length;
guint32 h_version;
guint8 h_cmd;
length = tvb_length(tvb);
if (length < 4 + 4 + 4 + 2 + 1 + 1)
return 0;
h_version = tvb_get_letohl(tvb, 0);
if (h_version != (DLM3_MAJOR_VERSION|DLM3_MINOR_VERSION))
return 0;
h_cmd = tvb_get_guint8(tvb, 4 + 4 + 4 + 2) ;
if ((h_cmd != DLM3_MSG) && (h_cmd != DLM3_RCOM))
return 0;
if ((h_cmd == DLM3_MSG) && (length < ((4 + 4 + 4 + 2 + 1 + 1)
+ (4 * 12 + 4 * 6))))
return 0;
else if ((h_cmd == DLM3_RCOM) && (length < 4 + 4 + 8 + 8 + 8))
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DLM3");
col_set_str(pinfo->cinfo, COL_INFO, "DLM3");
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(h_cmd,
dlm3_cmd,
"packet-dlm3.c internal bug"));
if (parent_tree) {
offset = 0;
item = proto_tree_add_item(parent_tree, proto_dlm3, tvb, offset,
-1, ENC_NA);
tree = proto_item_add_subtree(item, ett_dlm3);
sub_item = proto_tree_add_uint(tree,
hf_dlm3_h_version, tvb, offset, 4,
h_version);
sub_tree = proto_item_add_subtree(sub_item, ett_dlm3_version);
proto_tree_add_uint(sub_tree,
hf_dlm3_h_major_version, tvb, offset + 0, 2,
(h_version & 0xFFFF0000) >> 16);
proto_tree_add_uint(sub_tree,
hf_dlm3_h_minor_version, tvb, offset + 2, 2,
(h_version & 0x0000FFFF));
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_h_lockspace, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_h_nodeid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_h_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
sub_item = proto_tree_add_uint(tree,
hf_dlm3_h_cmd, tvb, offset, 1, h_cmd);
offset += 1;
proto_tree_add_item(tree,
hf_dlm3_h_pad, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (h_cmd == DLM3_MSG) {
sub_tree = proto_item_add_subtree(sub_item, ett_dlm3_msg);
dissect_dlm3_msg(tvb, pinfo, sub_tree, length, offset);
} else if (h_cmd== DLM3_RCOM) {
sub_tree = proto_item_add_subtree(sub_item, ett_dlm3_rcom);
dissect_dlm3_rcom(tvb, pinfo, sub_tree, length, offset);
}
}
return tvb_length(tvb);
}
void
proto_register_dlm3(void)
{
module_t *dlm3_module;
static hf_register_info hf[] = {
{ &hf_dlm3_h_version,
{ "Version", "dlm3.h.version",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_h_major_version,
{ "Major Version", "dlm3.h.major_version",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_h_minor_version,
{ "Minor Version", "dlm3.h.minor_version",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_h_lockspace,
{ "Lockspace Global ID", "dlm3.h.lockspac",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_h_nodeid,
{ "Sender Node ID", "dlm3.h.nodeid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_h_length,
{ "Length", "dlm3.h.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_h_cmd,
{ "Command", "dlm3.h.cmd",
FT_UINT8, BASE_DEC, VALS(dlm3_cmd), 0x0,
NULL, HFILL }},
{ &hf_dlm3_h_pad,
{ "Padding", "dlm3.h.pad",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_m_type,
{ "Message Type", "dlm3.m.type",
FT_UINT32, BASE_DEC, VALS(dlm3_msg), 0x0,
NULL, HFILL }},
{ &hf_dlm3_m_nodeid,
{ "Receiver Node ID", "dlm3.m.nodeid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_m_pid,
{ "Process ID of Lock Owner", "dlm3.m.pid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
DLM3_REGISTER_HF_LOCKID(m),
DLM3_REGISTER_HF_EXFLAGS(m_exflags, "m.exflags"),
{ &hf_dlm3_m_sbflags,
{ "Status Block Flags", "dlm3.m.sbflags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_sbflags_demoted,
{ "Demoted for deadlock resolution", "dlm3.m.sbflags.demoted",
FT_BOOLEAN, 32, NULL, DLM3_SBF_DEMOTED,
NULL, HFILL}},
{ &hf_dlm3_m_sbflags_valnotvalid,
{ "Lock Value Block Is Invalid", "dlm3.m.sbflags.valnotvalid",
FT_BOOLEAN, 32, NULL, DLM3_SBF_VALNOTVALID,
NULL, HFILL}},
{ &hf_dlm3_m_sbflags_altmode,
{ "Try to Grant in Alternative Mode", "dlm3.m.sbflags.altmode",
FT_BOOLEAN, 32, NULL, DLM3_SBF_ALTMODE,
NULL, HFILL}},
DLM3_REGISTER_HF_FLAGS(m_flags, "m.flags"),
{ &hf_dlm3_m_lvbseq,
{ "Lock Value Block Sequence Number", "dlm3.m.lvbseq",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_hash,
{ "Hash value", "dlm3.m.hash",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_status,
{ "Status", "dlm3.m.status",
FT_INT32, BASE_DEC, VALS(dlm3_status), 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_grmode,
{ "Granted Mode", "dlm3.m.grmode",
FT_INT32, BASE_DEC, VALS(dlm3_mode), 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_rqmode,
{ "Request Mode", "dlm3.m.rqmode",
FT_INT32, BASE_DEC, VALS(dlm3_mode), 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_bastmode,
{ "Mode requested by another node", "dlm3.m.bastmode",
FT_INT32, BASE_DEC, VALS(dlm3_mode), 0x0,
NULL, HFILL}},
DLM3_REGISTER_HF_ASTS(m, 32),
{ &hf_dlm3_m_result,
{ "Message Result(errno)", "dlm3.m.result",
FT_INT32, BASE_DEC, VALS(dlm3_result), 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_extra,
{ "Extra Message", "dlm3.m.extra",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rc_type,
{ "Recovery Command Type", "dlm3.rc.type",
FT_UINT32, BASE_DEC, VALS(dlm3_rcom), 0x0,
NULL, HFILL}},
{ &hf_dlm3_rc_result,
{ "Recovery Command Result", "dlm3.rc.result",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rc_id,
{ "Recovery Command ID", "dlm3.rc.id",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rc_seq,
{ "Recovery Command Sequence Number of Sender", "dlm3.rc.seq",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rc_seq_reply,
{ "Recovery Command Sequence Number of Receiver", "dlm3.rc.seq_reply",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rc_buf,
{ "Recovery Buffer", "dlm3.rc.buf",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rf_lvblen,
{ "Lock Value Block Length", "dlm3.rf.lvblen",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
DLM3_REGISTER_HF_EXFLAGS(rf_lsflags, "rf.lsflags"),
{ &hf_dlm3_rf_unused,
{ "Unused area", "dlm3.rf.lsflags.unused",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_ownpid,
{ "Process ID of Lock Owner", "dlm3.rl.ownpid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
DLM3_REGISTER_HF_LOCKID(rl),
DLM3_REGISTER_HF_EXFLAGS(rl_exflags, "rl.exflags"),
DLM3_REGISTER_HF_FLAGS(rl_flags, "rl.flags"),
{ &hf_dlm3_rl_lvbseq,
{ "Lock Value Block Sequence Number", "dlm3.rl.lvbseq",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_result,
{ "Result of Recovering master copy", "dlm3.rl.result",
FT_INT32, BASE_DEC, VALS(dlm3_result), 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_rqmode,
{ "Request Mode", "dlm3.rl.rqmode",
FT_INT8, BASE_DEC, VALS(dlm3_mode), 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_grmode,
{ "Granted Mode", "dlm3.rl.grmode",
FT_INT8, BASE_DEC, VALS(dlm3_mode), 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_status,
{ "Status", "dlm3.rl.status",
FT_INT8, BASE_DEC, VALS(dlm3_rs), 0x0,
NULL, HFILL}},
DLM3_REGISTER_HF_ASTS(rl, 8),
{ &hf_dlm3_rl_wait_type,
{ "Message Type the waiter is waiting for", "dlm3.rl.wait_type",
FT_UINT16, BASE_DEC, VALS(dlm3_msg), 0x0,
NULL, HFILL }},
{ &hf_dlm3_rl_namelen,
{ "Length of `name' field", "dlm3.rl.namelen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_rl_name,
{ "Name of Resource", "dlm3.rl.name",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_rl_name_contents,
{ "Contents actually occupying `name' field", "dlm3.rl.name_contents",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_rl_name_padding,
{ "Padding", "dlm3.rl.name_padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dlm3_rl_lvb,
{ "Lock Value Block", "dlm3.rl.lvb",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_dlm3,
&ett_dlm3_version,
&ett_dlm3_msg,
&ett_dlm3_m_exflags,
&ett_dlm3_sbflags,
&ett_dlm3_m_flags,
&ett_dlm3_m_asts,
&ett_dlm3_rcom,
&ett_dlm3_rcom_lock,
&ett_dlm3_rcom_config,
&ett_dlm3_rf_lsflags,
&ett_dlm3_rl_exflags,
&ett_dlm3_rl_flags,
&ett_dlm3_rl_asts,
&ett_dlm3_rl_name
};
proto_dlm3 = proto_register_protocol("Distributed Lock Manager",
"DLM3", "dlm3");
proto_register_field_array(proto_dlm3, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
dlm3_module = prefs_register_protocol(proto_dlm3,
proto_reg_handoff_dlm3);
prefs_register_uint_preference(dlm3_module, "tcp.port",
"DLM3 TCP Port",
"Set the TCP port for Distributed Lock Manager",
10,
&dlm3_tcp_port);
prefs_register_uint_preference(dlm3_module, "sctp.port",
"DLM3 SCTP Port",
"Set the SCTP port for Distributed Lock Manager",
10,
&dlm3_sctp_port);
}
void
proto_reg_handoff_dlm3(void)
{
static gboolean dissector_registered = FALSE;
static guint tcp_port;
static guint sctp_port;
static dissector_handle_t dlm3_tcp_handle;
static dissector_handle_t dlm3_sctp_handle;
if (!dissector_registered) {
dlm3_sctp_handle = new_create_dissector_handle(dissect_dlm3, proto_dlm3);
dlm3_tcp_handle = new_create_dissector_handle(dissect_dlm3, proto_dlm3);
dissector_registered = TRUE;
} else {
dissector_delete_uint("tcp.port", tcp_port, dlm3_tcp_handle);
dissector_delete_uint("sctp.port", sctp_port, dlm3_sctp_handle);
}
tcp_port = dlm3_tcp_port;
sctp_port = dlm3_sctp_port;
dissector_add_uint("tcp.port", tcp_port, dlm3_tcp_handle);
dissector_add_uint("sctp.port", sctp_port, dlm3_sctp_handle);
}
