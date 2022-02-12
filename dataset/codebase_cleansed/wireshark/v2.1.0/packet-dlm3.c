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
dissect_dlm3_rcom_status(tvbuff_t *tvb, proto_tree *tree,
guint length, int offset)
{
if ((length - offset) < ( 4 * 2 + 8 ))
return;
proto_tree_add_bitmask(tree, tvb, offset,
hf_dlm3_rs_flags, ett_dlm3_rs_flags,
rs_flags_fields, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rs_unused1, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree,
hf_dlm3_rs_unused2, tvb, offset, 8, ENC_LITTLE_ENDIAN);
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
guint length, int offset, guint32 h_version)
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
if (rc_type == DLM3_RCOM_STATUS && (h_version & 0xffff) > 0) {
sub_tree = proto_item_add_subtree(sub_item,
ett_dlm3_rcom_status);
dissect_dlm3_rcom_status(tvb, sub_tree, length, offset);
} else if (rc_type == DLM3_RCOM_LOCK) {
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
length = tvb_captured_length(tvb);
if (length < 4 + 4 + 4 + 2 + 1 + 1)
return 0;
h_version = tvb_get_letohl(tvb, 0);
if ((h_version & 0xffff0000) != DLM3_MAJOR_VERSION ||
(h_version & 0xffff) > DLM3_MINOR_VERSION_MAX)
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
{
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
dissect_dlm3_rcom(tvb, pinfo, sub_tree, length, offset, h_version);
}
}
return tvb_captured_length(tvb);
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
{ &hf_dlm3_m_lkid,
{ "Lock ID on Sender", "dlm3.m.lkid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_remid,
{ "Lock ID on Receiver", "dlm3.m.remid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_parent_lkid,
{ "Parent Lock ID on Sender", "dlm3.m.parent_lkid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_parent_remid,
{ "Parent Lock ID on Receiver", "dlm3.m.parent_remid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_exflags,
{ "External Flags", "dlm3.m.exflags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_noqueue,
{ "Don't queue", "dlm3.m.exflags.noqueue",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NOQUEUE,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_cancel,
{ "Cancel", "dlm3.m.exflags.cancel",
FT_BOOLEAN, 32, NULL, DLM3_LKF_CANCEL,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_convert,
{ "Convert", "dlm3.m.exflags.convert",
FT_BOOLEAN, 32, NULL, DLM3_LKF_CONVERT,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_valblk,
{ "Return the contents of the lock value block", "dlm3.m.exflags.valblk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_VALBLK,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_quecvt,
{ "Force a conversion request to be queued", "dlm3.m.exflags.quecvt",
FT_BOOLEAN, 32, NULL, DLM3_LKF_QUECVT,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_ivvalblk,
{ "Invalidate the lock value block", "dlm3.m.exflags.ivvalblk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_IVVALBLK,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_convdeadlk,
{ "Forced down to NL to resolve a conversion deadlock", "dlm3.m.exflags.convdeadlk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_CONVDEADLK,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_persistent,
{ "Persistent", "dlm3.m.exflags.persistent",
FT_BOOLEAN, 32, NULL, DLM3_LKF_PERSISTENT,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_nodlckwt,
{ "Don't cancel the lock if it gets into conversion deadlock", "dlm3.m.exflags.nodlckwt",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NODLCKWT,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_nodlckblk,
{ "Nodlckblk", "dlm3.m.exflags.nodlckblk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NODLCKBLK,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_expedite,
{ "Grant a NL lock immediately", "dlm3.m.exflags.expedite",
FT_BOOLEAN, 32, NULL, DLM3_LKF_EXPEDITE,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_noqueuebast,
{ "Send blocking ASTs even for NOQUEUE operations", "dlm3.m.exflags.noqueuebast",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NOQUEUEBAST,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_headque,
{ "Add a lock to the head of the queue", "dlm3.m.exflags.headque",
FT_BOOLEAN, 32, NULL, DLM3_LKF_HEADQUE,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_noorder,
{ "Disregard the standard grant order rules", "dlm3.m.exflags.noorder",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NOORDER,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_orphan,
{ "Orphan", "dlm3.m.exflags.orphan",
FT_BOOLEAN, 32, NULL, DLM3_LKF_ORPHAN,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_altpr,
{ "Try to grant the lock in `protected read' mode", "dlm3.m.exflags.altpr",
FT_BOOLEAN, 32, NULL, DLM3_LKF_ALTPR,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_altcw,
{ "Try to grant the lock in `concurrent read' mode", "dlm3.m.exflags.altcw",
FT_BOOLEAN, 32, NULL, DLM3_LKF_ALTCW,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_forceunlock,
{ "Force unlock", "dlm3.m.exflags.forceunlock",
FT_BOOLEAN, 32, NULL, DLM3_LKF_FORCEUNLOCK,
NULL, HFILL}},
{ &hf_dlm3_m_exflags_timeout,
{ "Timeout", "dlm3.m.exflags.timeout",
FT_BOOLEAN, 32, NULL, DLM3_LKF_TIMEOUT,
NULL, HFILL}},
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
{ &hf_dlm3_m_flags,
{ "Internal Flags", "dlm3.m.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_flags_user,
{ "User space lock realted", "dlm3.m.flags.user",
FT_BOOLEAN, 32, NULL, DLM3_IFL_USER,
NULL, HFILL}},
{ &hf_dlm3_m_flags_orphan,
{ "Orphaned lock", "dlm3.m.flags.orphan",
FT_BOOLEAN, 32, NULL, DLM3_IFL_ORPHAN,
NULL, HFILL}},
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
{ &hf_dlm3_m_asts,
{ "Asynchronous Traps", "dlm3.m.asts",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_m_asts_comp,
{ "Completion", "dlm3.m.asts.comp",
FT_BOOLEAN, 32, NULL, DLM3_AST_COMP,
NULL, HFILL }},
{ &hf_dlm3_m_asts_bast,
{ "Blocking", "dlm3.m.asts.bast",
FT_BOOLEAN, 32, NULL, DLM3_AST_BAST,
NULL, HFILL }},
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
{ &hf_dlm3_rf_lsflags,
{ "External Flags", "dlm3.rf.lsflags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_noqueue,
{ "Don't queue", "dlm3.rf.lsflags.noqueue",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NOQUEUE,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_cancel,
{ "Cancel", "dlm3.rf.lsflags.cancel",
FT_BOOLEAN, 32, NULL, DLM3_LKF_CANCEL,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_convert,
{ "Convert", "dlm3.rf.lsflags.convert",
FT_BOOLEAN, 32, NULL, DLM3_LKF_CONVERT,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_valblk,
{ "Return the contents of the lock value block", "dlm3.rf.lsflags.valblk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_VALBLK,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_quecvt,
{ "Force a conversion request to be queued", "dlm3.rf.lsflags.quecvt",
FT_BOOLEAN, 32, NULL, DLM3_LKF_QUECVT,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_ivvalblk,
{ "Invalidate the lock value block", "dlm3.rf.lsflags.ivvalblk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_IVVALBLK,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_convdeadlk,
{ "Forced down to NL to resolve a conversion deadlock", "dlm3.rf.lsflags.convdeadlk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_CONVDEADLK,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_persistent,
{ "Persistent", "dlm3.rf.lsflags.persistent",
FT_BOOLEAN, 32, NULL, DLM3_LKF_PERSISTENT,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_nodlckwt,
{ "Don't cancel the lock if it gets into conversion deadlock", "dlm3.rf.lsflags.nodlckwt",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NODLCKWT,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_nodlckblk,
{ "Nodlckblk", "dlm3.rf.lsflags.nodlckblk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NODLCKBLK,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_expedite,
{ "Grant a NL lock immediately", "dlm3.rf.lsflags.expedite",
FT_BOOLEAN, 32, NULL, DLM3_LKF_EXPEDITE,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_noqueuebast,
{ "Send blocking ASTs even for NOQUEUE operations", "dlm3.rf.lsflags.noqueuebast",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NOQUEUEBAST,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_headque,
{ "Add a lock to the head of the queue", "dlm3.rf.lsflags.headque",
FT_BOOLEAN, 32, NULL, DLM3_LKF_HEADQUE,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_noorder,
{ "Disregard the standard grant order rules", "dlm3.rf.lsflags.noorder",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NOORDER,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_orphan,
{ "Orphan", "dlm3.rf.lsflags.orphan",
FT_BOOLEAN, 32, NULL, DLM3_LKF_ORPHAN,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_altpr,
{ "Try to grant the lock in `protected read' mode", "dlm3.rf.lsflags.altpr",
FT_BOOLEAN, 32, NULL, DLM3_LKF_ALTPR,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_altcw,
{ "Try to grant the lock in `concurrent read' mode", "dlm3.rf.lsflags.altcw",
FT_BOOLEAN, 32, NULL, DLM3_LKF_ALTCW,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_forceunlock,
{ "Force unlock", "dlm3.rf.lsflags.forceunlock",
FT_BOOLEAN, 32, NULL, DLM3_LKF_FORCEUNLOCK,
NULL, HFILL}},
{ &hf_dlm3_rf_lsflags_timeout,
{ "Timeout", "dlm3.rf.lsflags.timeout",
FT_BOOLEAN, 32, NULL, DLM3_LKF_TIMEOUT,
NULL, HFILL}},
{ &hf_dlm3_rf_unused,
{ "Unused area", "dlm3.rf.lsflags.unused",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rs_flags,
{ "Recovery Command Status Flags", "dlm3.rs.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rs_flags_need_slots,
{ "Need slots", "dlm3.rs.flags.need_slots",
FT_UINT32, BASE_HEX, NULL, DLM_RSF_NEED_SLOTS,
NULL, HFILL}},
{ &hf_dlm3_rs_unused1,
{ "Unused area", "dlm3.rs.unused1",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rs_unused2,
{ "Unused area", "dlm3.rs.unused2",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_ownpid,
{ "Process ID of Lock Owner", "dlm3.rl.ownpid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_lkid,
{ "Lock ID on Sender", "dlm3.rl.lkid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_remid,
{ "Lock ID on Receiver", "dlm3.rl.remid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_parent_lkid,
{ "Parent Lock ID on Sender", "dlm3.rl.parent_lkid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_parent_remid,
{ "Parent Lock ID on Receiver", "dlm3.rl.parent_remid",
FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags,
{ "External Flags", "dlm3.rl.exflags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_noqueue,
{ "Don't queue", "dlm3.rl.exflags.noqueue",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NOQUEUE,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_cancel,
{ "Cancel", "dlm3.rl.exflags.cancel",
FT_BOOLEAN, 32, NULL, DLM3_LKF_CANCEL,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_convert,
{ "Convert", "dlm3.rl.exflags.convert",
FT_BOOLEAN, 32, NULL, DLM3_LKF_CONVERT,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_valblk,
{ "Return the contents of the lock value block", "dlm3.rl.exflags.valblk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_VALBLK,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_quecvt,
{ "Force a conversion request to be queued", "dlm3.rl.exflags.quecvt",
FT_BOOLEAN, 32, NULL, DLM3_LKF_QUECVT,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_ivvalblk,
{ "Invalidate the lock value block", "dlm3.rl.exflags.ivvalblk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_IVVALBLK,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_convdeadlk,
{ "Forced down to NL to resolve a conversion deadlock", "dlm3.rl.exflags.convdeadlk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_CONVDEADLK,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_persistent,
{ "Persistent", "dlm3.rl.exflags.persistent",
FT_BOOLEAN, 32, NULL, DLM3_LKF_PERSISTENT,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_nodlckwt,
{ "Don't cancel the lock if it gets into conversion deadlock", "dlm3.rl.exflags.nodlckwt",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NODLCKWT,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_nodlckblk,
{ "Nodlckblk", "dlm3.rl.exflags.nodlckblk",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NODLCKBLK,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_expedite,
{ "Grant a NL lock immediately", "dlm3.rl.exflags.expedite",
FT_BOOLEAN, 32, NULL, DLM3_LKF_EXPEDITE,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_noqueuebast,
{ "Send blocking ASTs even for NOQUEUE operations", "dlm3.rl.exflags.noqueuebast",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NOQUEUEBAST,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_headque,
{ "Add a lock to the head of the queue", "dlm3.rl.exflags.headque",
FT_BOOLEAN, 32, NULL, DLM3_LKF_HEADQUE,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_noorder,
{ "Disregard the standard grant order rules", "dlm3.rl.exflags.noorder",
FT_BOOLEAN, 32, NULL, DLM3_LKF_NOORDER,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_orphan,
{ "Orphan", "dlm3.rl.exflags.orphan",
FT_BOOLEAN, 32, NULL, DLM3_LKF_ORPHAN,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_altpr,
{ "Try to grant the lock in `protected read' mode", "dlm3.rl.exflags.altpr",
FT_BOOLEAN, 32, NULL, DLM3_LKF_ALTPR,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_altcw,
{ "Try to grant the lock in `concurrent read' mode", "dlm3.rl.exflags.altcw",
FT_BOOLEAN, 32, NULL, DLM3_LKF_ALTCW,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_forceunlock,
{ "Force unlock", "dlm3.rl.exflags.forceunlock",
FT_BOOLEAN, 32, NULL, DLM3_LKF_FORCEUNLOCK,
NULL, HFILL}},
{ &hf_dlm3_rl_exflags_timeout,
{ "Timeout", "dlm3.rl.exflags.timeout",
FT_BOOLEAN, 32, NULL, DLM3_LKF_TIMEOUT,
NULL, HFILL}},
{ &hf_dlm3_rl_flags,
{ "Internal Flags", "dlm3.rl.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_flags_user,
{ "User space lock realted", "dlm3.rl.flags.user",
FT_BOOLEAN, 32, NULL, DLM3_IFL_USER,
NULL, HFILL}},
{ &hf_dlm3_rl_flags_orphan,
{ "Orphaned lock", "dlm3.rl.flags.orphan",
FT_BOOLEAN, 32, NULL, DLM3_IFL_ORPHAN,
NULL, HFILL}},
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
{ &hf_dlm3_rl_asts,
{ "Asynchronous Traps", "dlm3.rl.asts",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_dlm3_rl_asts_comp,
{ "Completion", "dlm3.rl.asts.comp",
FT_BOOLEAN, 8, NULL, DLM3_AST_COMP,
NULL, HFILL }},
{ &hf_dlm3_rl_asts_bast,
{ "Blocking", "dlm3.rl.asts.bast",
FT_BOOLEAN, 8, NULL, DLM3_AST_BAST,
NULL, HFILL }},
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
&ett_dlm3_rcom_status,
&ett_dlm3_rcom_lock,
&ett_dlm3_rcom_config,
&ett_dlm3_rs_flags,
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
dlm3_sctp_handle = create_dissector_handle(dissect_dlm3, proto_dlm3);
dlm3_tcp_handle = create_dissector_handle(dissect_dlm3, proto_dlm3);
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
