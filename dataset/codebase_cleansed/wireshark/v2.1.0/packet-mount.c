static int
dissect_fhstatus(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, rpc_call_info_value* civ)
{
gint32 status;
status=tvb_get_ntohl(tvb,offset);
offset = dissect_rpc_uint32(tvb,tree,hf_mount3_status,offset);
switch (status) {
case 0:
offset = dissect_fhandle(tvb,offset,pinfo,tree,"fhandle", NULL, civ);
break;
default:
col_append_fstr(
pinfo->cinfo, COL_INFO, " Error:%s",
val_to_str(status, mount3_mountstat3,
"Unknown (0x%08X)"));
break;
}
return offset;
}
static int
dissect_mount_dirpath_call(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data)
{
const char *mountpoint=NULL;
int offset = 0;
if((!pinfo->fd->flags.visited) && nfs_file_name_snooping){
rpc_call_info_value *civ=(rpc_call_info_value *)data;
if(civ->request && (civ->proc==1)){
const gchar *host;
unsigned char *name;
guint32 len;
unsigned char *ptr;
host=address_to_str(wmem_packet_scope(), &pinfo->dst);
len=tvb_get_ntohl(tvb, offset);
if (len >= ITEM_LABEL_LENGTH)
THROW(ReportedBoundsError);
name=(unsigned char *)g_malloc(strlen(host)+1+len+1+200);
ptr=name;
memcpy(ptr, host, strlen(host));
ptr+=strlen(host);
*ptr++=':';
tvb_memcpy(tvb, ptr, offset+4, len);
ptr+=len;
*ptr=0;
nfs_name_snoop_add_name(civ->xid, tvb, -1, (gint)strlen(name), 0, 0, name);
}
}
offset = dissect_rpc_string(tvb,tree,hf_mount_path,offset,&mountpoint);
col_append_fstr(pinfo->cinfo, COL_INFO," %s", mountpoint);
return offset;
}
static int
dissect_mount1_mnt_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
return dissect_fhstatus(tvb,0,pinfo,tree,(rpc_call_info_value*)data);
}
static int
dissect_mountlist(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item* lock_item;
proto_tree* lock_tree;
int old_offset = offset;
const char* hostname;
const char* directory;
lock_item = proto_tree_add_item(tree, hf_mount_mountlist, tvb,
offset, -1, ENC_NA);
lock_tree = proto_item_add_subtree(lock_item, ett_mount_mountlist);
offset = dissect_rpc_string(tvb, lock_tree,
hf_mount_mountlist_hostname, offset, &hostname);
offset = dissect_rpc_string(tvb, lock_tree,
hf_mount_mountlist_directory, offset, &directory);
if (lock_item) {
proto_item_set_text(lock_item, "Mount List Entry: %s:%s", hostname, directory);
proto_item_set_len(lock_item, offset - old_offset);
}
return offset;
}
static int
dissect_mount_dump_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
return dissect_rpc_list(tvb, pinfo, tree, 0,
dissect_mountlist, NULL);
}
static int
dissect_group(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
int str_len;
if (group_names_len < MAX_GROUP_NAME_LIST - 5) {
str_len=tvb_get_nstringz(tvb,offset+4,
MAX_GROUP_NAME_LIST-5-group_names_len,
group_name_list+group_names_len);
if((group_names_len>=(MAX_GROUP_NAME_LIST-5))||(str_len<0)){
g_snprintf(group_name_list+(MAX_GROUP_NAME_LIST-5), 5, "...");
group_names_len=MAX_GROUP_NAME_LIST - 1;
} else {
group_names_len+=str_len;
group_name_list[group_names_len++]=' ';
}
group_name_list[group_names_len]=0;
}
offset = dissect_rpc_string(tvb, tree,
hf_mount_groups_group, offset, NULL);
return offset;
}
static int
dissect_exportlist(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item* exportlist_item = NULL;
proto_tree* exportlist_tree = NULL;
int old_offset = offset;
int groups_offset;
proto_item* groups_item = NULL;
proto_item* groups_tree = NULL;
const char* directory;
group_name_list[0]=0;
group_names_len=0;
if (tree) {
exportlist_item = proto_tree_add_item(tree, hf_mount_exportlist, tvb, offset, -1, ENC_NA);
exportlist_tree = proto_item_add_subtree(exportlist_item, ett_mount_exportlist);
}
offset = dissect_rpc_string(tvb, exportlist_tree,
hf_mount_exportlist_directory, offset, &directory);
groups_offset = offset;
groups_item = proto_tree_add_item(exportlist_tree, hf_mount_groups, tvb, offset, -1, ENC_NA);
groups_tree = proto_item_add_subtree(groups_item, ett_mount_groups);
offset = dissect_rpc_list(tvb, pinfo, groups_tree, offset,
dissect_group, NULL);
if (groups_item) {
if (offset - groups_offset == 4) {
proto_item_set_text(groups_item, "Groups: empty");
}
proto_item_set_len(groups_item, offset - groups_offset);
}
if (exportlist_item) {
proto_item_set_text(exportlist_item, "Export List Entry: %s -> %s", directory,group_name_list);
proto_item_set_len(exportlist_item, offset - old_offset);
}
return offset;
}
static int
dissect_mount_export_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
return dissect_rpc_list(tvb, pinfo, tree, 0,
dissect_exportlist, NULL);
}
static int
dissect_mount_pathconf_reply(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint32 pc_mask;
static const int * flags[] = {
&hf_mount_pathconf_error_all,
&hf_mount_pathconf_error_link_max,
&hf_mount_pathconf_error_max_canon,
&hf_mount_pathconf_error_max_input,
&hf_mount_pathconf_error_name_max,
&hf_mount_pathconf_error_path_max,
&hf_mount_pathconf_error_pipe_buf,
&hf_mount_pathconf_chown_restricted,
&hf_mount_pathconf_no_trunc,
&hf_mount_pathconf_error_vdisable,
NULL
};
int offset = 0;
pc_mask = tvb_get_ntohl(tvb, offset+OFFS_MASK) & 0xffff;
if (!(pc_mask & (PC_ERROR_LINK_MAX|PC_ERROR_ALL))) {
dissect_rpc_uint32(tvb,tree,hf_mount_pathconf_link_max,offset);
}
offset += 4;
if (!(pc_mask & (PC_ERROR_MAX_CANON|PC_ERROR_ALL))) {
proto_tree_add_item(tree,
hf_mount_pathconf_max_canon,tvb,offset+2,2,
tvb_get_ntohs(tvb,offset)&0xffff);
}
offset += 4;
if (!(pc_mask & (PC_ERROR_MAX_INPUT|PC_ERROR_ALL))) {
proto_tree_add_item(tree,
hf_mount_pathconf_max_input,tvb,offset+2,2,
tvb_get_ntohs(tvb,offset)&0xffff);
}
offset += 4;
if (!(pc_mask & (PC_ERROR_NAME_MAX|PC_ERROR_ALL))) {
proto_tree_add_item(tree,
hf_mount_pathconf_name_max,tvb,offset+2,2,
tvb_get_ntohs(tvb,offset)&0xffff);
}
offset += 4;
if (!(pc_mask & (PC_ERROR_PATH_MAX|PC_ERROR_ALL))) {
proto_tree_add_item(tree,
hf_mount_pathconf_path_max,tvb,offset+2,2,
tvb_get_ntohs(tvb,offset)&0xffff);
}
offset += 4;
if (!(pc_mask & (PC_ERROR_PIPE_BUF|PC_ERROR_ALL))) {
proto_tree_add_item(tree,
hf_mount_pathconf_pipe_buf,tvb,offset+2,2,
tvb_get_ntohs(tvb,offset)&0xffff);
}
offset += 4;
offset += 4;
if (!(pc_mask & (PC_ERROR_VDISABLE|PC_ERROR_ALL))) {
proto_tree_add_item(tree,
hf_mount_pathconf_vdisable,tvb,offset+3,1,
tvb_get_ntohs(tvb,offset)&0xffff);
}
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset+2, hf_mount_pathconf_mask, ett_mount_pathconf_mask, flags, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
dissect_mountstat3(packet_info *pinfo, tvbuff_t *tvb, proto_tree *tree, int offset, int hfindex, guint32 *status)
{
guint32 mountstat3;
mountstat3 = tvb_get_ntohl(tvb, offset);
if(mountstat3){
col_append_fstr(
pinfo->cinfo, COL_INFO, " Error:%s",
val_to_str(mountstat3, mount3_mountstat3,
"Unknown (0x%08X)"));
}
offset = dissect_rpc_uint32(tvb,tree,hfindex,offset);
*status = mountstat3;
return offset;
}
static int
dissect_mount3_mnt_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
guint32 status;
guint32 auth_flavors;
guint32 auth_flavor;
guint32 auth_flavor_i;
int offset = 0;
offset = dissect_mountstat3(pinfo,tvb,tree,offset,hf_mount3_status,&status);
switch (status) {
case 0:
offset = dissect_nfs3_fh(tvb,offset,pinfo,tree,"fhandle",NULL,(rpc_call_info_value*)data);
auth_flavors = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree,hf_mount_flavors, tvb,
offset, 4, auth_flavors);
offset += 4;
for (auth_flavor_i = 0 ; auth_flavor_i < auth_flavors ; auth_flavor_i++) {
auth_flavor = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree,hf_mount_flavor, tvb,
offset, 4, auth_flavor);
offset += 4;
}
break;
default:
break;
}
return offset;
}
static int
dissect_sgi_exportlist(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item* exportlist_item = NULL;
proto_tree* exportlist_tree = NULL;
int old_offset = offset;
const char* directory, *options;
if (tree) {
exportlist_item = proto_tree_add_item(tree, hf_mount_exportlist,
tvb, offset, -1, ENC_NA);
if (exportlist_item)
exportlist_tree = proto_item_add_subtree(exportlist_item,
ett_mount_exportlist);
}
offset = dissect_rpc_string(tvb, exportlist_tree,
hf_mount_exportlist_directory, offset, &directory);
offset = dissect_rpc_bool(tvb, exportlist_tree,
hf_mount_has_options, offset);
offset = dissect_rpc_string(tvb, exportlist_tree, hf_mount_options,
offset, &options);
if (exportlist_item) {
proto_item_set_text(exportlist_item,
"Export List Entry: %s %s", directory,
options);
proto_item_set_len(exportlist_item, offset - old_offset);
}
return offset;
}
static int
dissect_mount_exportlist_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
return dissect_rpc_list(tvb, pinfo, tree, 0,
dissect_sgi_exportlist, NULL);
}
static int
dissect_mount_statvfs_reply(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
static const int * flags[] = {
&hf_mount_statvfs_flag_rdonly,
&hf_mount_statvfs_flag_nosuid,
&hf_mount_statvfs_flag_notrunc,
&hf_mount_statvfs_flag_nodev,
&hf_mount_statvfs_flag_grpid,
&hf_mount_statvfs_flag_local,
NULL
};
int offset = 0;
dissect_rpc_uint32(tvb, tree, hf_mount_statvfs_bsize, offset);
offset += 4;
dissect_rpc_uint32(tvb, tree, hf_mount_statvfs_frsize, offset);
offset += 4;
dissect_rpc_uint32(tvb, tree, hf_mount_statvfs_blocks, offset);
offset += 4;
dissect_rpc_uint32(tvb, tree, hf_mount_statvfs_bfree, offset);
offset += 4;
dissect_rpc_uint32(tvb, tree, hf_mount_statvfs_bavail, offset);
offset += 4;
dissect_rpc_uint32(tvb, tree, hf_mount_statvfs_files, offset);
offset += 4;
dissect_rpc_uint32(tvb, tree, hf_mount_statvfs_ffree, offset);
offset += 4;
dissect_rpc_uint32(tvb, tree, hf_mount_statvfs_favail, offset);
offset += 4;
dissect_rpc_bytes(tvb, tree, hf_mount_statvfs_basetype, offset,
16, TRUE, NULL);
offset += 16;
dissect_rpc_bytes(tvb, tree, hf_mount_statvfs_fstr, offset, 32, FALSE, NULL);
offset += 32;
dissect_rpc_uint32(tvb, tree, hf_mount_statvfs_fsid, offset);
offset += 4;
proto_tree_add_bitmask(tree, tvb, offset, hf_mount_statvfs_flag, ett_mount_statvfs_flag, flags, ENC_BIG_ENDIAN);
offset += 4;
dissect_rpc_uint32(tvb, tree, hf_mount_statvfs_namemax, offset);
offset += 4;
return offset;
}
void
proto_register_mount(void)
{
static hf_register_info hf[] = {
{ &hf_mount_procedure_v1, {
"V1 Procedure", "mount.procedure_v1", FT_UINT32, BASE_DEC,
VALS(mount1_proc_vals), 0, NULL, HFILL }},
{ &hf_mount_procedure_v2, {
"V2 Procedure", "mount.procedure_v2", FT_UINT32, BASE_DEC,
VALS(mount2_proc_vals), 0, NULL, HFILL }},
{ &hf_mount_procedure_v3, {
"V3 Procedure", "mount.procedure_v3", FT_UINT32, BASE_DEC,
VALS(mount3_proc_vals), 0, NULL, HFILL }},
{ &hf_sgi_mount_procedure_v1, {
"SGI V1 procedure", "mount.procedure_sgi_v1", FT_UINT32, BASE_DEC,
VALS(sgi_mount1_proc_vals), 0, NULL, HFILL }},
{ &hf_mount_path, {
"Path", "mount.path", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_mount3_status, {
"Status", "mount.status", FT_UINT32, BASE_DEC,
VALS(mount3_mountstat3), 0, NULL, HFILL }},
{ &hf_mount_mountlist_hostname, {
"Hostname", "mount.dump.hostname", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_mount_mountlist_directory, {
"Directory", "mount.dump.directory", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_mount_mountlist, {
"Mount List Entry", "mount.dump.entry", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_mount_groups_group, {
"Group", "mount.export.group", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_mount_groups, {
"Groups", "mount.export.groups", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_mount_has_options, {
"Has options", "mount.export.has_options", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_mount_options, {
"Options", "mount.export.options", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_mount_exportlist_directory, {
"Directory", "mount.export.directory", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_mount_exportlist, {
"Export List Entry", "mount.export.entry", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_mount_pathconf_link_max, {
"Maximum number of links to a file", "mount.pathconf.link_max",
FT_UINT32, BASE_DEC,
NULL, 0, "Maximum number of links allowed to a file", HFILL }},
{ &hf_mount_pathconf_max_canon, {
"Maximum terminal input line length", "mount.pathconf.max_canon",
FT_UINT16, BASE_DEC,
NULL, 0, "Max tty input line length", HFILL }},
{ &hf_mount_pathconf_max_input, {
"Terminal input buffer size", "mount.pathconf.max_input",
FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_mount_pathconf_name_max, {
"Maximum file name length", "mount.pathconf.name_max",
FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_mount_pathconf_path_max, {
"Maximum path name length", "mount.pathconf.path_max",
FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_mount_pathconf_pipe_buf, {
"Pipe buffer size", "mount.pathconf.pipe_buf",
FT_UINT16, BASE_DEC,
NULL, 0, "Maximum amount of data that can be written atomically to a pipe", HFILL }},
{ &hf_mount_pathconf_vdisable, {
"VDISABLE character", "mount.pathconf.vdisable_char",
FT_UINT8, BASE_HEX,
NULL, 0, "Character value to disable a terminal special character", HFILL }},
{ &hf_mount_pathconf_mask, {
"Reply error/status bits", "mount.pathconf.mask",
FT_UINT16, BASE_HEX,
NULL, 0, "Bit mask with error and status bits", HFILL }},
{ &hf_mount_pathconf_error_all, {
"ERROR_ALL", "mount.pathconf.mask.error_all",
FT_BOOLEAN, 16, TFS(&tos_error_all),
PC_ERROR_ALL, NULL, HFILL }},
{ &hf_mount_pathconf_error_link_max, {
"ERROR_LINK_MAX", "mount.pathconf.mask.error_link_max",
FT_BOOLEAN, 16, TFS(&tos_error_link_max),
PC_ERROR_LINK_MAX, NULL, HFILL }},
{ &hf_mount_pathconf_error_max_canon, {
"ERROR_MAX_CANON", "mount.pathconf.mask.error_max_canon",
FT_BOOLEAN, 16, TFS(&tos_error_max_canon),
PC_ERROR_MAX_CANON, NULL, HFILL }},
{ &hf_mount_pathconf_error_max_input, {
"ERROR_MAX_INPUT", "mount.pathconf.mask.error_max_input",
FT_BOOLEAN, 16, TFS(&tos_error_max_input),
PC_ERROR_MAX_INPUT, NULL, HFILL }},
{ &hf_mount_pathconf_error_name_max, {
"ERROR_NAME_MAX", "mount.pathconf.mask.error_name_max",
FT_BOOLEAN, 16, TFS(&tos_error_name_max),
PC_ERROR_NAME_MAX, NULL, HFILL }},
{ &hf_mount_pathconf_error_path_max, {
"ERROR_PATH_MAX", "mount.pathconf.mask.error_path_max",
FT_BOOLEAN, 16, TFS(&tos_error_path_max),
PC_ERROR_PATH_MAX, NULL, HFILL }},
{ &hf_mount_pathconf_error_pipe_buf, {
"ERROR_PIPE_BUF", "mount.pathconf.mask.error_pipe_buf",
FT_BOOLEAN, 16, TFS(&tos_error_pipe_buf),
PC_ERROR_PIPE_BUF, NULL, HFILL }},
{ &hf_mount_pathconf_chown_restricted, {
"CHOWN_RESTRICTED", "mount.pathconf.mask.chown_restricted",
FT_BOOLEAN, 16, TFS(&tos_chown_restricted),
PC_CHOWN_RESTRICTED, NULL, HFILL }},
{ &hf_mount_pathconf_no_trunc, {
"NO_TRUNC", "mount.pathconf.mask.no_trunc",
FT_BOOLEAN, 16, TFS(&tos_no_trunc),
PC_NO_TRUNC, NULL, HFILL }},
{ &hf_mount_pathconf_error_vdisable, {
"ERROR_VDISABLE", "mount.pathconf.mask.error_vdisable",
FT_BOOLEAN, 16, TFS(&tos_error_vdisable),
PC_ERROR_VDISABLE, NULL, HFILL }},
{ &hf_mount_statvfs_bsize, {
"Block size", "mount.statvfs.f_bsize",
FT_UINT32, BASE_DEC, NULL, 0,
"File system block size", HFILL }},
{ &hf_mount_statvfs_frsize, {
"Fragment size", "mount.statvfs.f_frsize",
FT_UINT32, BASE_DEC, NULL, 0,
"File system fragment size", HFILL }},
{ &hf_mount_statvfs_blocks, {
"Blocks", "mount.statvfs.f_blocks",
FT_UINT32, BASE_DEC, NULL, 0,
"Total fragment sized blocks", HFILL }},
{ &hf_mount_statvfs_bfree, {
"Blocks Free", "mount.statvfs.f_bfree",
FT_UINT32, BASE_DEC, NULL, 0,
"Free fragment sized blocks", HFILL }},
{ &hf_mount_statvfs_bavail, {
"Blocks Available", "mount.statvfs.f_bavail",
FT_UINT32, BASE_DEC, NULL, 0,
"Available fragment sized blocks", HFILL }},
{ &hf_mount_statvfs_files, {
"Files", "mount.statvfs.f_files",
FT_UINT32, BASE_DEC, NULL, 0,
"Total files/inodes", HFILL }},
{ &hf_mount_statvfs_ffree, {
"Files Free", "mount.statvfs.f_ffree",
FT_UINT32, BASE_DEC, NULL, 0,
"Free files/inodes", HFILL }},
{ &hf_mount_statvfs_favail, {
"Files Available", "mount.statvfs.f_favail",
FT_UINT32, BASE_DEC, NULL, 0,
"Available files/inodes", HFILL }},
{ &hf_mount_statvfs_fsid, {
"File system ID", "mount.statvfs.f_fsid",
FT_UINT32, BASE_DEC, NULL, 0,
"File system identifier", HFILL }},
{ &hf_mount_statvfs_basetype, {
"Type", "mount.statvfs.f_basetype",
FT_STRING, BASE_NONE, NULL, 0,
"File system type", HFILL }},
{ &hf_mount_statvfs_flag, {
"Flags", "mount.statvfs.f_flag",
FT_UINT32, BASE_HEX, NULL, 0,
"Flags bit-mask", HFILL }},
{ &hf_mount_statvfs_flag_rdonly, {
"ST_RDONLY", "mount.statvfs.f_flag.st_rdonly",
FT_BOOLEAN, 32, TFS(&tos_st_rdonly), ST_RDONLY,
NULL, HFILL }},
{ &hf_mount_statvfs_flag_nosuid, {
"ST_NOSUID", "mount.statvfs.f_flag.st_nosuid",
FT_BOOLEAN, 32, TFS(&tos_st_nosuid), ST_NOSUID,
NULL, HFILL }},
{ &hf_mount_statvfs_flag_notrunc, {
"ST_NOTRUNC", "mount.statvfs.f_flag.st_notrunc",
FT_BOOLEAN, 32, TFS(&tos_st_notrunc), ST_NOTRUNC,
NULL, HFILL }},
{ &hf_mount_statvfs_flag_nodev, {
"ST_NODEV", "mount.statvfs.f_flag.st_nodev",
FT_BOOLEAN, 32, TFS(&tos_st_nodev), ST_NODEV,
NULL, HFILL }},
{ &hf_mount_statvfs_flag_grpid, {
"ST_GRPID", "mount.statvfs.f_flag.st_grpid",
FT_BOOLEAN, 32, TFS(&tos_st_grpid), ST_GRPID,
NULL, HFILL }},
{ &hf_mount_statvfs_flag_local, {
"ST_LOCAL", "mount.statvfs.f_flag.st_local",
FT_BOOLEAN, 32, TFS(&tos_st_local), ST_LOCAL,
NULL, HFILL }},
{ &hf_mount_statvfs_namemax, {
"Maximum file name length", "mount.statvfs.f_namemax",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mount_statvfs_fstr, {
"File system specific string", "mount.statvfs.f_fstr",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mount_flavors, {
"Flavors", "mount.flavors", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_mount_flavor, {
"Flavor", "mount.flavor", FT_UINT32, BASE_DEC,
VALS(rpc_auth_flavor), 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_mount,
&ett_mount_mountlist,
&ett_mount_groups,
&ett_mount_exportlist,
&ett_mount_pathconf_mask,
&ett_mount_statvfs_flag,
};
proto_mount = proto_register_protocol("Mount Service", "MOUNT",
"mount");
proto_sgi_mount = proto_register_protocol("SGI Mount Service",
"SGI MOUNT", "sgimount");
proto_register_field_array(proto_mount, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mount(void)
{
rpc_init_prog(proto_mount, MOUNT_PROGRAM, ett_mount,
G_N_ELEMENTS(mount_vers_info), mount_vers_info);
rpc_init_prog(proto_sgi_mount, SGI_MOUNT_PROGRAM, ett_mount,
G_N_ELEMENTS(sgi_mount_vers_info), sgi_mount_vers_info);
}
