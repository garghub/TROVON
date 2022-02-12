static int
dissect_hclnfsd_gids(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint32 ngids, ngids_i;
proto_tree *gidtree = NULL;
proto_item *giditem = NULL;
ngids = tvb_get_ntohl(tvb, offset);
if (tree)
{
giditem = proto_tree_add_item(tree, hf_hclnfsd_gids, tvb, offset, 4, ENC_BIG_ENDIAN);
gidtree = proto_item_add_subtree(giditem, ett_hclnfsd_gids);
}
offset += 4;
if (gidtree)
{
for (ngids_i = 0; ngids_i < ngids; ngids_i++)
{
proto_tree_add_item(gidtree, hf_hclnfsd_gid, tvb, offset + (4 * ngids_i), 4, ENC_BIG_ENDIAN);
}
}
offset += 4 * ngids;
return offset;
}
static int
dissect_hclnfsd_spool_inquire_call(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data)
{
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_status, offset);
offset = dissect_nfs3_fh(tvb, offset, pinfo, tree, "spool filehandle", NULL, (rpc_call_info_value*)data);
return offset;
}
static int
dissect_hclnfsd_spool_file_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_printername, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_filename, offset, NULL);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_fileext, offset);
return offset;
}
static char *
hclnfsd_decode_obscure(const char *ident, int ident_len)
{
char *ident_decoded, *ident_out;
int j, x, y;
ident_decoded = (char *)wmem_alloc(wmem_packet_scope(), ident_len);
ident_out = ident_decoded;
for (x = -1, j = 0; j < ident_len; j++)
{
y = *ident;
x ^= *ident;
*ident_out = x;
x = y;
ident++;
ident_out++;
}
return ident_decoded;
}
static int
dissect_hclnfsd_authorize_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint32 request_type;
const char *ident = NULL;
char *ident_decoded;
char *username = NULL;
char *password = NULL;
int ident_len = 0;
int newoffset;
proto_item *ident_item = NULL;
proto_tree *ident_tree = NULL;
proto_tree_add_item(tree, hf_hclnfsd_server_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
request_type = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, hf_hclnfsd_request_type, tvb, offset,
4, request_type);
offset += 4;
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_device, offset,
NULL);
ident_tree = proto_tree_add_subtree(tree, tvb, offset, -1,
ett_hclnfsd_auth_ident, &ident_item, "Authentication Ident");
if (ident_tree)
{
newoffset = dissect_rpc_string(tvb, ident_tree,
hf_hclnfsd_auth_ident_obscure, offset, &ident);
if (ident)
{
ident_len = (int)strlen(ident);
proto_item_set_len(ident_item, ident_len);
ident_decoded = hclnfsd_decode_obscure(ident, ident_len);
username = ident_decoded + 2;
password = username + strlen(username) + 1;
proto_tree_add_string(ident_tree, hf_hclnfsd_username, tvb, offset, ident_len, username);
proto_tree_add_string(ident_tree, hf_hclnfsd_password, tvb, offset, ident_len, password);
offset = newoffset;
}
}
return offset;
}
static int
dissect_hclnfsd_authorize_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint32 status;
status = tvb_get_ntohl(tvb, offset);
if (!tree)
return offset;
offset += 4;
if (status != 0)
return offset;
proto_tree_add_uint(tree, hf_hclnfsd_status, tvb, offset, 4, status);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_uid, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_gid, offset);
offset = dissect_hclnfsd_gids(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_hclnfsd_grp_name_to_numb_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_grpname, offset, NULL);
return offset;
}
static int
dissect_hclnfsd_grp_name_to_numb_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_gid, offset);
return offset;
}
static int
dissect_hclnfsd_grp_to_number_call(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
offset = dissect_hclnfsd_gids(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_hclnfsd_grp_to_number_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
return dissect_rpc_string(tvb, tree, hf_hclnfsd_grpname, offset,
NULL);
}
static int
dissect_hclnfsd_return_host_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_tree_add_item(tree, hf_hclnfsd_host_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_hclnfsd_return_host_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_hostname, offset, NULL);
return offset;
}
static int
dissect_hclnfsd_uid_to_name_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint32 nuids, nuids_i;
proto_tree *uidtree = NULL;
proto_item *uiditem = NULL;
nuids = tvb_get_ntohl(tvb, offset);
if (tree)
{
uiditem = proto_tree_add_item(tree, hf_hclnfsd_uids, tvb, offset, 4, ENC_BIG_ENDIAN);
if (uiditem)
uidtree = proto_item_add_subtree(uiditem, ett_hclnfsd_uids);
}
offset += 4;
for (nuids_i = 0; nuids_i < nuids; nuids_i++)
offset = dissect_rpc_uint32(tvb, uidtree, hf_hclnfsd_uid, offset);
return offset;
}
static int
dissect_hclnfsd_uid_to_name_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint32 nusers, nusers_i;
proto_tree *usertree = NULL;
proto_item *useritem = NULL;
nusers = tvb_get_ntohl(tvb, offset);
if (tree)
{
useritem = proto_tree_add_item(tree, hf_hclnfsd_uids, tvb, offset, 4, ENC_BIG_ENDIAN);
if (useritem)
usertree = proto_item_add_subtree(useritem, ett_hclnfsd_usernames);
}
offset += 4;
if (!usertree)
return offset;
for (nusers_i = 0; nusers_i < nusers; nusers_i++)
offset = dissect_rpc_string(tvb, usertree,
hf_hclnfsd_username, offset, NULL);
return offset;
}
static int
dissect_hclnfsd_name_to_uid_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_username, offset, NULL);
return offset;
}
static int
dissect_hclnfsd_name_to_uid_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_uid, offset);
return offset;
}
static int
dissect_hclnfsd_share_call(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data)
{
guint32 request_type;
request_type = tvb_get_ntohl(tvb, offset);
if (tree)
proto_tree_add_uint(tree, hf_hclnfsd_request_type, tvb, offset,
4, request_type);
offset += 4;
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_cookie, offset);
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_lockname, offset, NULL);
offset = dissect_nfs3_fh(tvb, offset, pinfo, tree, "Filehandle", NULL, (rpc_call_info_value*)data);
offset = dissect_rpc_data(tvb, tree, hf_hclnfsd_unknown_data, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_mode, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_access, offset);
offset += 4;
return offset;
}
static int
dissect_hclnfsd_share_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint32 request_type;
request_type = tvb_get_ntohl(tvb, offset);
if (tree)
proto_tree_add_uint(tree, hf_hclnfsd_request_type, tvb, offset,
4, request_type);
offset += 4;
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_cookie, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_status, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_sequence, offset);
return offset;
}
static int
dissect_hclnfsd_unshare_call(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
return dissect_hclnfsd_share_call(tvb, offset, pinfo, tree, data);
}
static int
dissect_hclnfsd_unshare_reply(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
return dissect_hclnfsd_share_reply(tvb, offset, pinfo, tree, data);
}
static int
dissect_hclnfsd_lock_call(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data)
{
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_status, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_cookie, offset);
offset += 4;
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_exclusive, offset);
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_lockname, offset, NULL);
offset = dissect_nfs3_fh(tvb, offset, pinfo, tree, "Filehandle", NULL, (rpc_call_info_value*)data);
offset = dissect_rpc_data(tvb, tree, hf_hclnfsd_lockowner, offset);
offset += 4;
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_offset, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_length, offset);
return offset;
}
static int
dissect_hclnfsd_lock_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint request_type;
request_type = tvb_get_ntohl(tvb, offset);
if (tree)
proto_tree_add_uint(tree, hf_hclnfsd_request_type, tvb, offset,
4, request_type);
offset += 4;
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_cookie, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_status, offset);
return offset;
}
static int
dissect_hclnfsd_remove_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_lockname, offset, NULL);
offset += 4;
return offset;
}
static int
dissect_hclnfsd_unlock_call(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data)
{
offset += 4;
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_cookie, offset);
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_lockname, offset, NULL);
offset = dissect_nfs3_fh(tvb, offset, pinfo, tree, "Filehandle", NULL, (rpc_call_info_value*)data);
offset = dissect_rpc_data(tvb, tree, hf_hclnfsd_unknown_data, offset);
offset += 4;
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_offset, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_length, offset);
return offset;
}
static int
dissect_hclnfsd_unlock_reply(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
return dissect_hclnfsd_lock_reply(tvb, offset, pinfo, tree, data);
}
static int
dissect_hclnfsd_get_printers_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint nqueues, nqueues_i;
proto_item *queuesitem = NULL;
proto_tree *queuestree = NULL;
nqueues = tvb_get_ntohl(tvb, offset);
if (tree)
{
queuesitem = proto_tree_add_item(tree, hf_hclnfsd_print_queues, tvb, offset, 4, ENC_BIG_ENDIAN);
if (queuesitem)
queuestree = proto_item_add_subtree(queuesitem,
ett_hclnfsd_printqueues);
}
offset += 4;
if (!queuestree)
return offset;
for (nqueues_i = 0; nqueues_i < nqueues; nqueues_i++)
{
offset = dissect_rpc_string(tvb, tree,
hf_hclnfsd_queuename, offset, NULL);
offset = dissect_rpc_string(tvb, tree,
hf_hclnfsd_queuecomment, offset, NULL);
}
return offset;
}
static int
dissect_hclnfsd_get_printq_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_queuename, offset, NULL);
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_username, offset, NULL);
return offset;
}
static int
dissect_hclnfsd_get_printq_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
guint datafollows;
proto_item *queueitem = NULL;
proto_tree *queuetree = NULL;
proto_item *jobitem;
proto_tree *jobtree;
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_printqueuenumber, offset);
offset = dissect_rpc_string(tvb, tree, hf_hclnfsd_queuecomment, offset, NULL);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_queuestatus, offset);
offset = dissect_rpc_uint32(tvb, tree, hf_hclnfsd_numphysicalprinters, offset);
datafollows = tvb_get_ntohl(tvb, offset);
if (tree)
{
queueitem = proto_tree_add_item(tree, hf_hclnfsd_print_jobs, tvb, offset, 4, ENC_BIG_ENDIAN);
queuetree = proto_item_add_subtree(queueitem, ett_hclnfsd_printqueues);
}
offset += 4;
while (datafollows)
{
jobitem = proto_tree_add_item(queuetree, hf_hclnfsd_job_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
jobtree = proto_item_add_subtree(jobitem, ett_hclnfsd_printjob);
offset = dissect_rpc_string(tvb, jobtree,
hf_hclnfsd_username, offset, NULL);
offset = dissect_rpc_string(tvb, jobtree,
hf_hclnfsd_printparams, offset, NULL);
offset = dissect_rpc_uint32(tvb, jobtree, hf_hclnfsd_queuestatus, offset);
offset = dissect_rpc_uint32(tvb, jobtree, hf_hclnfsd_jobstatus, offset);
offset = dissect_rpc_uint32(tvb, jobtree, hf_hclnfsd_timesubmitted, offset);
offset = dissect_rpc_uint32(tvb, jobtree, hf_hclnfsd_size, offset);
offset = dissect_rpc_uint32(tvb, jobtree, hf_hclnfsd_copies, offset);
offset = dissect_rpc_string(tvb, jobtree, hf_hclnfsd_queuecomment, offset, NULL);
datafollows = tvb_get_ntohl(tvb, offset);
offset += 4;
}
return offset;
}
void
proto_register_hclnfsd(void)
{
static hf_register_info hf[] = {
{ &hf_hclnfsd_procedure_v1, {
"V1 Procedure", "hclnfsd.procedure_v1", FT_UINT32, BASE_DEC,
VALS(hclnfsd1_proc_vals), 0, NULL, HFILL }},
{ &hf_hclnfsd_request_type, {
"Request Type", "hclnfsd.request_type", FT_UINT32, BASE_DEC,
VALS(names_request_type), 0, NULL, HFILL }},
{ &hf_hclnfsd_device, {
"Device", "hclnfsd.device", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
#if 0
{ &hf_hclnfsd_login, {
"Login Text", "hclnfsd.logintext", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
#endif
{ &hf_hclnfsd_lockname, {
"Lockname", "hclnfsd.lockname", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_unknown_data, {
"Unknown", "hclnfsd.unknown_data", FT_BYTES, BASE_NONE,
NULL, 0, "Data", HFILL }},
{ &hf_hclnfsd_lockowner, {
"Lockowner", "hclnfsd.lockowner", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_printername, {
"Printer Name", "hclnfsd.printername", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_filename, {
"Filename", "hclnfsd.filename", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_fileext, {
"File Extension", "hclnfsd.fileext", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_grpname, {
"Group", "hclnfsd.group", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_hostname, {
"Hostname", "hclnfsd.hostname", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_username, {
"Username", "hclnfsd.username", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_queuename, {
"Name", "hclnfsd.printqueuename", FT_STRING, BASE_NONE,
NULL, 0, "Print Queue Name", HFILL }},
{ &hf_hclnfsd_queuecomment, {
"Comment", "hclnfsd.printqueuecomment", FT_STRING, BASE_NONE,
NULL, 0, "Print Queue Comment", HFILL }},
{ &hf_hclnfsd_printparams, {
"Print Parameters", "hclnfsd.printparameters", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_status, {
"Status", "hclnfsd.status", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_uid, {
"UID", "hclnfsd.uid", FT_UINT32, BASE_DEC,
NULL, 0, "User ID", HFILL }},
{ &hf_hclnfsd_sequence, {
"Sequence", "hclnfsd.sequence", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_cookie, {
"Cookie", "hclnfsd.cookie", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_mode, {
"Mode", "hclnfsd.mode", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_access, {
"Access", "hclnfsd.access", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_exclusive, {
"Exclusive", "hclnfsd.exclusive", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_offset, {
"Offset", "hclnfsd.offset", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_length, {
"Length", "hclnfsd.length", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_queuestatus, {
"Queue Status", "hclnfsd.queuestatus", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_printqueuenumber, {
"Print Queue Number", "hclnfsd.pqn", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_numphysicalprinters, {
"Number of Physical Printers", "hclnfsd.npp", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_jobstatus, {
"Job Status", "hclnfsd.jobstatus", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_timesubmitted, {
"Time Submitted", "hclnfsd.timesubmitted", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_size, {
"Size", "hclnfsd.size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_copies, {
"Copies", "hclnfsd.copies", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_gid, {
"GID", "hclnfsd.gid", FT_UINT32, BASE_DEC,
NULL, 0, "Group ID", HFILL }},
{ &hf_hclnfsd_server_ip, {
"Server IP", "hclnfsd.server_ip", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_host_ip, {
"Host IP", "hclnfsd.host_ip", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_hclnfsd_auth_ident_obscure, {
"Obscure Ident", "hclnfsd.authorize.ident.obscure", FT_STRING,
BASE_NONE , NULL, 0, "Authentication Obscure Ident", HFILL }},
{ &hf_hclnfsd_gids,
{ "GIDs", "hclnfsd.gids",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_hclnfsd_password,
{ "Password", "hclnfsd.password",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_hclnfsd_uids,
{ "UIDs", "hclnfsd.uids",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_hclnfsd_print_queues,
{ "Print Queues", "hclnfsd.print_queues",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_hclnfsd_print_jobs,
{ "Print Jobs", "hclnfsd.print_jobs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_hclnfsd_job_id,
{ "Job ID", "hclnfsd.job_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_hclnfsd,
&ett_hclnfsd_gids,
&ett_hclnfsd_groups,
&ett_hclnfsd_uids,
&ett_hclnfsd_usernames,
&ett_hclnfsd_printqueues,
&ett_hclnfsd_printjob,
&ett_hclnfsd_auth_ident
};
proto_hclnfsd = proto_register_protocol("Hummingbird NFS Daemon",
"HCLNFSD", "hclnfsd");
proto_register_field_array(proto_hclnfsd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_hclnfsd(void)
{
rpc_init_prog(proto_hclnfsd, HCLNFSD_PROGRAM, ett_hclnfsd);
rpc_init_proc_table(HCLNFSD_PROGRAM, 1, hclnfsd1_proc, hf_hclnfsd_procedure_v1);
}
