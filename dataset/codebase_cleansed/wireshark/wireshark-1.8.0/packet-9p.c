static int dissect_9P(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
guint32 tmp,i;
guint16 tmp16;
guint8 ninemsg;
guint offset = 0;
const char *mname;
gint len,reportedlen;
tvbuff_t *next_tvb;
proto_item *ti;
proto_tree *ninep_tree,*tmp_tree;
nstime_t tv;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "9P");
col_clear(pinfo->cinfo, COL_INFO);
ninemsg = tvb_get_guint8(tvb, offset + 4);
mname = val_to_str(ninemsg, ninep_msg_type, "Unknown");
if(strcmp(mname,"Unknown") == 0) {
col_add_fstr(pinfo->cinfo, COL_INFO, "9P Data Continuation(?) (Tag %u)",(guint)ninemsg);
return 0;
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s Tag=%u",mname,(guint)tvb_get_letohs(tvb,offset+5));
if (!tree)
return 0;
ti = proto_tree_add_item(tree, proto_9P, tvb, 0, -1, ENC_NA);
ninep_tree = proto_item_add_subtree(ti, ett_9P);
proto_tree_add_item(ninep_tree, hf_9P_msgsz, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ninep_tree, hf_9P_msgtype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
++offset;
proto_tree_add_item(ninep_tree, hf_9P_tag, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
switch(ninemsg) {
case RVERSION:
case TVERSION:
proto_tree_add_item(ninep_tree, hf_9P_maxsize, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_version, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_version);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
case TAUTH:
proto_tree_add_item(ninep_tree, hf_9P_afid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_uname, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_uname);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16+2;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_aname, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_aname);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
break;
case RAUTH:
dissect_9P_qid(tvb,ninep_tree,offset);
offset += 13;
break;
case RERROR:
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_ename, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_ename);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
break;
case TFLUSH:
proto_tree_add_item(ninep_tree, hf_9P_oldtag, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case RFLUSH:
break;
case TATTACH:
proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
proto_tree_add_item(ninep_tree, hf_9P_afid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_uname, tvb, offset+2, tmp16, ENC_ASCII|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_uname);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16 + 2;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_aname, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_aname);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16+2;
break;
case RATTACH:
dissect_9P_qid(tvb,ninep_tree,offset);
offset += 13;
break;
case TWALK:
proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
proto_tree_add_item(ninep_tree, hf_9P_newfid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
tmp16 = tvb_get_letohs(tvb,offset);
proto_tree_add_item(ninep_tree, hf_9P_nwalk, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
if(tmp16 > 250) {
tmp16 = 250;
tmp_tree = proto_tree_add_text(ninep_tree, tvb, 0, 0, "Only first 250 items shown");
PROTO_ITEM_SET_GENERATED(tmp_tree);
}
for(i = 0 ; i < tmp16; i++) {
guint16 tmplen;
proto_item *wname;
proto_tree *wname_tree;
tmplen = tvb_get_letohs(tvb,offset);
wname = proto_tree_add_item(ninep_tree, hf_9P_wname, tvb, offset+2, tmplen, ENC_UTF_8|ENC_NA);
wname_tree = proto_item_add_subtree(wname,ett_9P_wname);
proto_tree_add_item(wname_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmplen + 2;
}
break;
case RWALK:
tmp16 = tvb_get_letohs(tvb,offset);
proto_tree_add_item(ninep_tree, hf_9P_nqid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
if(tmp16 > 250) {
tmp16 = 250;
tmp_tree = proto_tree_add_text(ninep_tree, tvb, 0, 0, "Only first 250 items shown");
PROTO_ITEM_SET_GENERATED(tmp_tree);
}
for(i = 0; i < tmp16; i++) {
dissect_9P_qid(tvb,ninep_tree,offset);
offset += 13;
}
break;
case TOPEN:
proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
ti = proto_tree_add_item(ninep_tree, hf_9P_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
dissect_9P_mode(tvb,ti,offset);
break;
case ROPEN:
dissect_9P_qid(tvb,ninep_tree,offset);
offset += 13;
proto_tree_add_item(ninep_tree, hf_9P_iounit, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case TCREATE:
proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_name, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_filename);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16 + 2;
ti = proto_tree_add_item(ninep_tree, hf_9P_perm, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_dm(tvb,ti,offset,1);
offset +=4;
ti = proto_tree_add_item(ninep_tree, hf_9P_mode, tvb, offset, 1, ENC_LITTLE_ENDIAN);
dissect_9P_mode(tvb,ti,offset);
break;
case RCREATE:
dissect_9P_qid(tvb,ninep_tree,offset);
offset += 13;
proto_tree_add_item(ninep_tree, hf_9P_iounit, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case TREAD:
proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
proto_tree_add_item(ninep_tree, hf_9P_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset +=8;
proto_tree_add_item(ninep_tree, hf_9P_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case RREAD:
tmp = tvb_get_letohl(tvb,offset);
proto_tree_add_item(ninep_tree, hf_9P_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
len = tvb_reported_length_remaining(tvb, offset);
reportedlen = ((gint)tmp&0xffff) > len ? len : (gint)tmp&0xffff;
next_tvb = tvb_new_subset(tvb, offset, len, reportedlen);
call_dissector(data_handle,next_tvb, pinfo, tree);
break;
case TWRITE:
proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
proto_tree_add_item(ninep_tree, hf_9P_offset, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset +=8;
tmp = tvb_get_letohl(tvb,offset);
proto_tree_add_item(ninep_tree, hf_9P_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
len = tvb_reported_length_remaining(tvb, offset);
reportedlen = ((gint)tmp&0xffff) > len ? len : (gint)tmp&0xffff;
next_tvb = tvb_new_subset(tvb, offset, len, reportedlen);
call_dissector(data_handle,next_tvb, pinfo, tree);
break;
case RWRITE:
proto_tree_add_item(ninep_tree, hf_9P_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case TCLUNK:
proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case RCLUNK:
break;
case TREMOVE:
proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case RREMOVE:
break;
case TSTAT:
proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
break;
case RSTAT:
proto_tree_add_item(ninep_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(ninep_tree, hf_9P_sdlen, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(ninep_tree, hf_9P_stattype, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(ninep_tree, hf_9P_dev, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
dissect_9P_qid(tvb,ninep_tree,offset);
offset += 13;
ti = proto_tree_add_item(ninep_tree, hf_9P_statmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_dm(tvb,ti,offset,0);
offset +=4;
tv.secs = tvb_get_letohl(tvb,offset);
tv.nsecs = 0;
proto_tree_add_time(ninep_tree, hf_9P_atime, tvb, offset, 4, &tv);
offset +=4;
tv.secs = tvb_get_letohl(tvb,offset);
tv.nsecs = 0;
proto_tree_add_time(ninep_tree, hf_9P_mtime, tvb, offset, 4, &tv);
offset +=4;
proto_tree_add_item(ninep_tree, hf_9P_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset +=8;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_filename, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_filename);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16+2;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_uid, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_uid);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16+2;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_gid, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_gid);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16+2;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_muid, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_muid);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16+2;
break;
case TWSTAT:
proto_tree_add_item(ninep_tree, hf_9P_fid, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(ninep_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(ninep_tree, hf_9P_sdlen, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(ninep_tree, hf_9P_stattype, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(ninep_tree, hf_9P_dev, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset +=4;
dissect_9P_qid(tvb,ninep_tree,offset);
offset += 13;
ti = proto_tree_add_item(ninep_tree, hf_9P_statmode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
dissect_9P_dm(tvb,ti,offset,0);
offset +=4;
tv.secs = tvb_get_letohl(tvb,offset);
tv.nsecs = 0;
proto_tree_add_time(ninep_tree, hf_9P_atime, tvb, offset, 4, &tv);
offset +=4;
tv.secs = tvb_get_letohl(tvb,offset);
tv.nsecs = 0;
proto_tree_add_time(ninep_tree, hf_9P_mtime, tvb, offset, 4, &tv);
offset +=4;
proto_tree_add_item(ninep_tree, hf_9P_length, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset +=8;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_filename, tvb, offset+2, tmp16, ENC_ASCII|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_filename);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16+2;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_uid, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_uid);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16+2;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_gid, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_gid);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16+2;
tmp16 = tvb_get_letohs(tvb,offset);
ti = proto_tree_add_item(ninep_tree, hf_9P_muid, tvb, offset+2, tmp16, ENC_UTF_8|ENC_NA);
tmp_tree = proto_item_add_subtree(ti,ett_9P_muid);
proto_tree_add_item(tmp_tree, hf_9P_parmsz, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += tmp16+2;
break;
}
return offset;
}
static void dissect_9P_mode(tvbuff_t * tvb, proto_item * item,int offset)
{
proto_item *mode_tree;
guint8 mode;
mode = tvb_get_guint8(tvb,offset);
mode_tree = proto_item_add_subtree(item, ett_9P_omode);
if(!mode_tree)
return;
proto_tree_add_boolean(mode_tree, hf_9P_mode_c, tvb, offset, 1, mode);
proto_tree_add_boolean(mode_tree, hf_9P_mode_t, tvb, offset, 1, mode);
proto_tree_add_uint(mode_tree, hf_9P_mode_rwx, tvb, offset, 1, mode);
}
static void dissect_9P_qid(tvbuff_t * tvb, proto_tree * tree,int offset)
{
proto_item *qid_item,*qidtype_item;
proto_tree *qid_tree,*qidtype_tree;
guint64 path;
guint32 vers;
guint8 type;
if(!tree)
return;
type = tvb_get_guint8(tvb,offset);
vers = tvb_get_letohs(tvb,offset+1);
path = tvb_get_letoh64(tvb,offset+1+4);
qid_item = proto_tree_add_text(tree,tvb,offset,13,"Qid type=0x%02x vers=%d path=%" G_GINT64_MODIFIER "u",type,vers,path);
qid_tree = proto_item_add_subtree(qid_item,ett_9P_qid);
qidtype_item = proto_tree_add_item(qid_tree, hf_9P_qidtype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
qidtype_tree = proto_item_add_subtree(qidtype_item,ett_9P_qidtype);
proto_tree_add_text(qidtype_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(type, QTDIR, 8, "Directory", "not a Directory"));
proto_tree_add_text(qidtype_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(type, QTAPPEND, 8, "Append only", "not Append only"));
proto_tree_add_text(qidtype_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(type, QTEXCL, 8, "Exclusive use", "not Exclusive use"));
proto_tree_add_text(qidtype_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(type, QTMOUNT, 8, "Mounted channel", "not a Mounted channel"));
proto_tree_add_text(qidtype_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(type, QTAUTH, 8, "Authentication file", "not an Authentication file"));
proto_tree_add_text(qidtype_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(type, QTTMP, 8, "Temporary file (not backed up)", "not a Temporary file"));
proto_tree_add_item(qid_tree, hf_9P_qidvers, tvb, offset+1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(qid_tree, hf_9P_qidpath, tvb, offset+1+4, 8, ENC_LITTLE_ENDIAN);
}
static void dissect_9P_dm(tvbuff_t * tvb, proto_item * item,int offset,int iscreate)
{
proto_item *mode_tree;
guint32 dm;
dm = tvb_get_letohl(tvb,offset);
mode_tree = proto_item_add_subtree(item, ett_9P_dm);
if(!mode_tree)
return;
proto_tree_add_text(mode_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(dm, DMDIR, 32, "Directory", "not a Directory"));
if(!iscreate) {
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, DMAPPEND, 32, "Append only", "not Append only"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, DMEXCL, 32, "Exclusive use", "not Exclusive use"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, DMMOUNT, 32, "Mounted channel", "not a Mounted channel"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, DMAUTH, 32, "Authentication file", "not an Authentication file"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, DMTMP, 32, "Temporary file (not backed up)", "not a Temporary file"));
}
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, 0400, 32, "Read permission for owner", "no Read permission for owner"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, 0200, 32, "Write permission for owner", "no Write permission for owner"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, 0100, 32, "Execute permission for owner", "no Execute permission for owner"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, 040, 32, "Read permission for group", "no Read permission for group"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, 020, 32, "Write permission for group", "no Write permission for group"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, 010, 32, "Execute permission for group", "no Execute permission for group"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, 04, 32, "Read permission for others", "no Read permission for others"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, 02, 32, "Write permission for others", "no Write permission for others"));
proto_tree_add_text(mode_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(dm, 01, 32, "Execute permission for others", "no Execute permission for others"));
}
void proto_register_9P(void)
{
static hf_register_info hf[] = {
{&hf_9P_msgsz,
{"Msg length", "9p.msglen", FT_UINT32, BASE_DEC, NULL, 0x0,
"9P Message Length", HFILL}},
{&hf_9P_msgtype,
{"Msg Type", "9p.msgtype", FT_UINT8, BASE_DEC, VALS(ninep_msg_type), 0x0,
"Message Type", HFILL}},
{&hf_9P_tag,
{"Tag", "9p.tag", FT_UINT16, BASE_DEC, NULL, 0x0,
"9P Tag", HFILL}},
{&hf_9P_oldtag,
{"Old tag", "9p.oldtag", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_parmsz,
{"Param length", "9p.paramsz", FT_UINT16, BASE_DEC, NULL, 0x0,
"Parameter length", HFILL}},
{&hf_9P_maxsize,
{"Max msg size", "9p.maxsize", FT_UINT32, BASE_DEC, NULL, 0x0,
"Max message size", HFILL}},
{&hf_9P_fid,
{"Fid", "9p.fid", FT_UINT32, BASE_DEC, NULL, 0x0,
"File ID", HFILL}},
{&hf_9P_nqid,
{"Nr Qids", "9p.nqid", FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of Qid results", HFILL}},
{&hf_9P_mode,
{"Mode", "9p.mode", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_mode_rwx,
{"Open/Create Mode", "9p.mode.rwx", FT_UINT8, BASE_DEC,VALS(ninep_mode_vals),P9_MODEMASK,
NULL, HFILL}},
{&hf_9P_mode_t,
{"Trunc", "9p.mode.trunc", FT_BOOLEAN, 8, TFS(&tfs_set_notset), P9_OTRUNC,
"Truncate", HFILL}},
{&hf_9P_mode_c,
{"Remove on close", "9p.mode.orclose", FT_BOOLEAN, 8, TFS(&tfs_set_notset), P9_ORCLOSE,
NULL, HFILL}},
{&hf_9P_iounit,
{"I/O Unit", "9p.iounit", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_count,
{"Count", "9p.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_offset,
{"Offset", "9p.offset", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_perm,
{"Permissions", "9p.perm", FT_UINT32, BASE_OCT, NULL, 0x0,
"Permission bits", HFILL}},
{&hf_9P_qidpath,
{"Qid path", "9p.qidpath", FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_qidvers,
{"Qid version", "9p.qidvers", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_qidtype,
{"Qid type", "9p.qidtype", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_statmode,
{"Mode", "9p.statmode", FT_UINT32, BASE_OCT, NULL, 0x0,
"File mode flags", HFILL}},
{&hf_9P_stattype,
{"Type", "9p.stattype", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_atime,
{"Atime", "9p.atime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Access Time", HFILL}},
{&hf_9P_mtime,
{"Mtime", "9p.mtime", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Modified Time", HFILL}},
{&hf_9P_length,
{"Length", "9p.length", FT_UINT64, BASE_DEC, NULL, 0x0,
"File Length", HFILL}},
{&hf_9P_dev,
{"Dev", "9p.dev", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_wname,
{"Wname", "9p.wname", FT_STRING, BASE_NONE, NULL, 0x0,
"Path Name Element", HFILL}},
{&hf_9P_version,
{"Version", "9p.version", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_afid,
{"Afid", "9p.afid", FT_UINT32, BASE_DEC, NULL, 0x0,
"Authenticating FID", HFILL}},
{&hf_9P_uname,
{"Uname", "9p.uname", FT_STRING, BASE_NONE, NULL, 0x0,
"User Name", HFILL}},
{&hf_9P_aname,
{"Aname", "9p.aname", FT_STRING, BASE_NONE, NULL, 0x0,
"Access Name", HFILL}},
{&hf_9P_ename,
{"Ename", "9p.ename", FT_STRING, BASE_NONE, NULL, 0x0,
"Error", HFILL}},
{&hf_9P_name,
{"Name", "9p.name", FT_STRING, BASE_NONE, NULL, 0x0,
"Name of file", HFILL}},
{&hf_9P_sdlen,
{"Stat data length", "9p.sdlen", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_filename,
{"File name", "9p.filename", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{&hf_9P_uid,
{"Uid", "9p.uid", FT_STRING, BASE_NONE, NULL, 0x0,
"User id", HFILL}},
{&hf_9P_gid,
{"Gid", "9p.gid", FT_STRING, BASE_NONE, NULL, 0x0,
"Group id", HFILL}},
{&hf_9P_muid,
{"Muid", "9p.muid", FT_STRING, BASE_NONE, NULL, 0x0,
"Last modifiers uid", HFILL}},
{&hf_9P_newfid,
{"New fid", "9p.newfid", FT_UINT32, BASE_DEC, NULL, 0x0,
"New file ID", HFILL}},
{&hf_9P_nwalk,
{"Nr Walks", "9p.nwalk", FT_UINT32, BASE_DEC, NULL, 0x0,
"Nr of walk items", HFILL}}
};
static gint *ett[] = {
&ett_9P,
&ett_9P_omode,
&ett_9P_dm,
&ett_9P_wname,
&ett_9P_aname,
&ett_9P_ename,
&ett_9P_uname,
&ett_9P_uid,
&ett_9P_gid,
&ett_9P_muid,
&ett_9P_filename,
&ett_9P_version,
&ett_9P_qid,
&ett_9P_qidtype,
};
proto_9P = proto_register_protocol("Plan 9 9P", "9P", "9p");
proto_register_field_array(proto_9P, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_9P(void)
{
dissector_handle_t ninep_handle;
data_handle = find_dissector("data");
ninep_handle = new_create_dissector_handle(dissect_9P, proto_9P);
dissector_add_uint("tcp.port", NINEPORT, ninep_handle);
}
