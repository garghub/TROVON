static void
smb2_hdr_assemble(struct smb2_hdr *hdr, __le16 smb2_cmd ,
const struct cifs_tcon *tcon)
{
struct smb2_pdu *pdu = (struct smb2_pdu *)hdr;
char *temp = (char *)hdr;
__u16 parmsize = smb2_req_struct_sizes[le16_to_cpu(smb2_cmd)];
memset(temp, 0, 256);
hdr->smb2_buf_length = cpu_to_be32(parmsize + sizeof(struct smb2_hdr)
- 4 );
hdr->ProtocolId[0] = 0xFE;
hdr->ProtocolId[1] = 'S';
hdr->ProtocolId[2] = 'M';
hdr->ProtocolId[3] = 'B';
hdr->StructureSize = cpu_to_le16(64);
hdr->Command = smb2_cmd;
hdr->CreditRequest = cpu_to_le16(2);
hdr->ProcessId = cpu_to_le32((__u16)current->tgid);
if (!tcon)
goto out;
hdr->TreeId = tcon->tid;
if (tcon->ses)
hdr->SessionId = tcon->ses->Suid;
if (tcon->share_flags & SHI1005_FLAGS_DFS)
hdr->Flags |= SMB2_FLAGS_DFS_OPERATIONS;
out:
pdu->StructureSize2 = cpu_to_le16(parmsize);
return;
}
static int
smb2_reconnect(__le16 smb2_command, struct cifs_tcon *tcon)
{
int rc = 0;
struct nls_table *nls_codepage;
struct cifs_ses *ses;
struct TCP_Server_Info *server;
if (tcon == NULL)
return rc;
if (smb2_command == SMB2_TREE_CONNECT)
return rc;
if (tcon->tidStatus == CifsExiting) {
if ((smb2_command != SMB2_WRITE) &&
(smb2_command != SMB2_CREATE) &&
(smb2_command != SMB2_TREE_DISCONNECT)) {
cFYI(1, "can not send cmd %d while umounting",
smb2_command);
return -ENODEV;
}
}
if ((!tcon->ses) || (tcon->ses->status == CifsExiting) ||
(!tcon->ses->server))
return -EIO;
ses = tcon->ses;
server = ses->server;
while (server->tcpStatus == CifsNeedReconnect) {
switch (smb2_command) {
case SMB2_TREE_DISCONNECT:
case SMB2_CANCEL:
case SMB2_CLOSE:
case SMB2_OPLOCK_BREAK:
return -EAGAIN;
}
wait_event_interruptible_timeout(server->response_q,
(server->tcpStatus != CifsNeedReconnect), 10 * HZ);
if (server->tcpStatus != CifsNeedReconnect)
break;
if (!tcon->retry) {
cFYI(1, "gave up waiting on reconnect in smb_init");
return -EHOSTDOWN;
}
}
if (!tcon->ses->need_reconnect && !tcon->need_reconnect)
return rc;
nls_codepage = load_nls_default();
mutex_lock(&tcon->ses->session_mutex);
rc = cifs_negotiate_protocol(0, tcon->ses);
if (!rc && tcon->ses->need_reconnect)
rc = cifs_setup_session(0, tcon->ses, nls_codepage);
if (rc || !tcon->need_reconnect) {
mutex_unlock(&tcon->ses->session_mutex);
goto out;
}
cifs_mark_open_files_invalid(tcon);
rc = SMB2_tcon(0, tcon->ses, tcon->treeName, tcon, nls_codepage);
mutex_unlock(&tcon->ses->session_mutex);
cFYI(1, "reconnect tcon rc = %d", rc);
if (rc)
goto out;
atomic_inc(&tconInfoReconnectCount);
out:
switch (smb2_command) {
case SMB2_FLUSH:
case SMB2_READ:
case SMB2_WRITE:
case SMB2_LOCK:
case SMB2_IOCTL:
case SMB2_QUERY_DIRECTORY:
case SMB2_CHANGE_NOTIFY:
case SMB2_QUERY_INFO:
case SMB2_SET_INFO:
return -EAGAIN;
}
unload_nls(nls_codepage);
return rc;
}
static int
small_smb2_init(__le16 smb2_command, struct cifs_tcon *tcon,
void **request_buf)
{
int rc = 0;
rc = smb2_reconnect(smb2_command, tcon);
if (rc)
return rc;
*request_buf = cifs_small_buf_get();
if (*request_buf == NULL) {
return -ENOMEM;
}
smb2_hdr_assemble((struct smb2_hdr *) *request_buf, smb2_command, tcon);
if (tcon != NULL) {
#ifdef CONFIG_CIFS_STATS2
uint16_t com_code = le16_to_cpu(smb2_command);
cifs_stats_inc(&tcon->stats.smb2_stats.smb2_com_sent[com_code]);
#endif
cifs_stats_inc(&tcon->num_smbs_sent);
}
return rc;
}
static void
free_rsp_buf(int resp_buftype, void *rsp)
{
if (resp_buftype == CIFS_SMALL_BUFFER)
cifs_small_buf_release(rsp);
else if (resp_buftype == CIFS_LARGE_BUFFER)
cifs_buf_release(rsp);
}
int
SMB2_negotiate(const unsigned int xid, struct cifs_ses *ses)
{
struct smb2_negotiate_req *req;
struct smb2_negotiate_rsp *rsp;
struct kvec iov[1];
int rc = 0;
int resp_buftype;
struct TCP_Server_Info *server;
unsigned int sec_flags;
u16 i;
u16 temp = 0;
int blob_offset, blob_length;
char *security_blob;
int flags = CIFS_NEG_OP;
cFYI(1, "Negotiate protocol");
if (ses->server)
server = ses->server;
else {
rc = -EIO;
return rc;
}
rc = small_smb2_init(SMB2_NEGOTIATE, NULL, (void **) &req);
if (rc)
return rc;
if (ses->overrideSecFlg & (~(CIFSSEC_MUST_SIGN | CIFSSEC_MUST_SEAL)))
sec_flags = ses->overrideSecFlg;
else
sec_flags = global_secflags | ses->overrideSecFlg;
cFYI(1, "sec_flags 0x%x", sec_flags);
req->hdr.SessionId = 0;
for (i = 0; i < SMB2_NUM_PROT; i++)
req->Dialects[i] = smb2protocols[i].name;
req->DialectCount = cpu_to_le16(i);
inc_rfc1001_len(req, i * 2);
if ((sec_flags & CIFSSEC_MUST_SIGN) == CIFSSEC_MUST_SIGN)
temp = SMB2_NEGOTIATE_SIGNING_REQUIRED;
else if (sec_flags & CIFSSEC_MAY_SIGN)
temp = SMB2_NEGOTIATE_SIGNING_ENABLED;
req->SecurityMode = cpu_to_le16(temp);
req->Capabilities = cpu_to_le32(SMB2_GLOBAL_CAP_DFS);
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4;
rc = SendReceive2(xid, ses, iov, 1, &resp_buftype, flags);
rsp = (struct smb2_negotiate_rsp *)iov[0].iov_base;
if (rc != 0)
goto neg_exit;
if (rsp == NULL) {
rc = -EIO;
goto neg_exit;
}
cFYI(1, "mode 0x%x", rsp->SecurityMode);
if (rsp->DialectRevision == smb2protocols[SMB21_PROT].name)
cFYI(1, "negotiated smb2.1 dialect");
else if (rsp->DialectRevision == smb2protocols[SMB2_PROT].name)
cFYI(1, "negotiated smb2 dialect");
else {
cERROR(1, "Illegal dialect returned by server %d",
le16_to_cpu(rsp->DialectRevision));
rc = -EIO;
goto neg_exit;
}
server->dialect = le16_to_cpu(rsp->DialectRevision);
server->maxBuf = le32_to_cpu(rsp->MaxTransactSize);
server->max_read = le32_to_cpu(rsp->MaxReadSize);
server->max_write = le32_to_cpu(rsp->MaxWriteSize);
server->sec_mode = le16_to_cpu(rsp->SecurityMode);
server->capabilities = le32_to_cpu(rsp->Capabilities);
server->capabilities |= SMB2_NT_FIND | SMB2_LARGE_FILES;
security_blob = smb2_get_data_area_len(&blob_offset, &blob_length,
&rsp->hdr);
if (blob_length == 0) {
cERROR(1, "missing security blob on negprot");
rc = -EIO;
goto neg_exit;
}
#ifdef CONFIG_SMB2_ASN1
rc = decode_neg_token_init(security_blob, blob_length,
&server->sec_type);
if (rc == 1)
rc = 0;
else if (rc == 0) {
rc = -EIO;
goto neg_exit;
}
#endif
neg_exit:
free_rsp_buf(resp_buftype, rsp);
return rc;
}
int
SMB2_sess_setup(const unsigned int xid, struct cifs_ses *ses,
const struct nls_table *nls_cp)
{
struct smb2_sess_setup_req *req;
struct smb2_sess_setup_rsp *rsp = NULL;
struct kvec iov[2];
int rc = 0;
int resp_buftype;
__le32 phase = NtLmNegotiate;
struct TCP_Server_Info *server;
unsigned int sec_flags;
u8 temp = 0;
u16 blob_length = 0;
char *security_blob;
char *ntlmssp_blob = NULL;
bool use_spnego = false;
cFYI(1, "Session Setup");
if (ses->server)
server = ses->server;
else {
rc = -EIO;
return rc;
}
ses->ntlmssp = kmalloc(sizeof(struct ntlmssp_auth), GFP_KERNEL);
if (!ses->ntlmssp)
return -ENOMEM;
ses->server->secType = RawNTLMSSP;
ssetup_ntlmssp_authenticate:
if (phase == NtLmChallenge)
phase = NtLmAuthenticate;
rc = small_smb2_init(SMB2_SESSION_SETUP, NULL, (void **) &req);
if (rc)
return rc;
if (ses->overrideSecFlg & (~(CIFSSEC_MUST_SIGN | CIFSSEC_MUST_SEAL)))
sec_flags = ses->overrideSecFlg;
else
sec_flags = global_secflags | ses->overrideSecFlg;
cFYI(1, "sec_flags 0x%x", sec_flags);
req->hdr.SessionId = 0;
req->VcNumber = 0;
req->hdr.CreditRequest = cpu_to_le16(3);
if ((sec_flags & CIFSSEC_MUST_SIGN) == CIFSSEC_MUST_SIGN)
temp = SMB2_NEGOTIATE_SIGNING_REQUIRED;
else if (ses->server->sec_mode & SMB2_NEGOTIATE_SIGNING_REQUIRED)
temp = SMB2_NEGOTIATE_SIGNING_REQUIRED;
else if (sec_flags & CIFSSEC_MAY_SIGN)
temp = SMB2_NEGOTIATE_SIGNING_ENABLED;
req->SecurityMode = temp;
req->Capabilities = 0;
req->Channel = 0;
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4 - 1;
if (phase == NtLmNegotiate) {
ntlmssp_blob = kmalloc(sizeof(struct _NEGOTIATE_MESSAGE),
GFP_KERNEL);
if (ntlmssp_blob == NULL) {
rc = -ENOMEM;
goto ssetup_exit;
}
build_ntlmssp_negotiate_blob(ntlmssp_blob, ses);
if (use_spnego) {
cERROR(1, "spnego not supported for SMB2 yet");
rc = -EOPNOTSUPP;
kfree(ntlmssp_blob);
goto ssetup_exit;
} else {
blob_length = sizeof(struct _NEGOTIATE_MESSAGE);
security_blob = ntlmssp_blob;
}
} else if (phase == NtLmAuthenticate) {
req->hdr.SessionId = ses->Suid;
ntlmssp_blob = kzalloc(sizeof(struct _NEGOTIATE_MESSAGE) + 500,
GFP_KERNEL);
if (ntlmssp_blob == NULL) {
cERROR(1, "failed to malloc ntlmssp blob");
rc = -ENOMEM;
goto ssetup_exit;
}
rc = build_ntlmssp_auth_blob(ntlmssp_blob, &blob_length, ses,
nls_cp);
if (rc) {
cFYI(1, "build_ntlmssp_auth_blob failed %d", rc);
goto ssetup_exit;
}
if (use_spnego) {
cERROR(1, "spnego not supported for SMB2 yet");
rc = -EOPNOTSUPP;
kfree(ntlmssp_blob);
goto ssetup_exit;
} else {
security_blob = ntlmssp_blob;
}
} else {
cERROR(1, "illegal ntlmssp phase");
rc = -EIO;
goto ssetup_exit;
}
req->SecurityBufferOffset =
cpu_to_le16(sizeof(struct smb2_sess_setup_req) -
1 - 4 );
req->SecurityBufferLength = cpu_to_le16(blob_length);
iov[1].iov_base = security_blob;
iov[1].iov_len = blob_length;
inc_rfc1001_len(req, blob_length - 1 );
rc = SendReceive2(xid, ses, iov, 2, &resp_buftype, CIFS_LOG_ERROR);
kfree(security_blob);
rsp = (struct smb2_sess_setup_rsp *)iov[0].iov_base;
if (rsp->hdr.Status == STATUS_MORE_PROCESSING_REQUIRED) {
if (phase != NtLmNegotiate) {
cERROR(1, "Unexpected more processing error");
goto ssetup_exit;
}
if (offsetof(struct smb2_sess_setup_rsp, Buffer) - 4 !=
le16_to_cpu(rsp->SecurityBufferOffset)) {
cERROR(1, "Invalid security buffer offset %d",
le16_to_cpu(rsp->SecurityBufferOffset));
rc = -EIO;
goto ssetup_exit;
}
phase = NtLmChallenge;
rc = 0;
ses->Suid = rsp->hdr.SessionId;
rc = decode_ntlmssp_challenge(rsp->Buffer,
le16_to_cpu(rsp->SecurityBufferLength), ses);
}
if (rc != 0)
goto ssetup_exit;
if (rsp == NULL) {
rc = -EIO;
goto ssetup_exit;
}
ses->session_flags = le16_to_cpu(rsp->SessionFlags);
ssetup_exit:
free_rsp_buf(resp_buftype, rsp);
if ((phase == NtLmChallenge) && (rc == 0))
goto ssetup_ntlmssp_authenticate;
return rc;
}
int
SMB2_logoff(const unsigned int xid, struct cifs_ses *ses)
{
struct smb2_logoff_req *req;
int rc = 0;
struct TCP_Server_Info *server;
cFYI(1, "disconnect session %p", ses);
if (ses && (ses->server))
server = ses->server;
else
return -EIO;
rc = small_smb2_init(SMB2_LOGOFF, NULL, (void **) &req);
if (rc)
return rc;
req->hdr.SessionId = ses->Suid;
rc = SendReceiveNoRsp(xid, ses, (char *) &req->hdr, 0);
return rc;
}
static inline void cifs_stats_fail_inc(struct cifs_tcon *tcon, uint16_t code)
{
cifs_stats_inc(&tcon->stats.smb2_stats.smb2_com_failed[code]);
}
int
SMB2_tcon(const unsigned int xid, struct cifs_ses *ses, const char *tree,
struct cifs_tcon *tcon, const struct nls_table *cp)
{
struct smb2_tree_connect_req *req;
struct smb2_tree_connect_rsp *rsp = NULL;
struct kvec iov[2];
int rc = 0;
int resp_buftype;
int unc_path_len;
struct TCP_Server_Info *server;
__le16 *unc_path = NULL;
cFYI(1, "TCON");
if ((ses->server) && tree)
server = ses->server;
else
return -EIO;
if (tcon && tcon->bad_network_name)
return -ENOENT;
unc_path = kmalloc(MAX_SHARENAME_LENGTH * 2, GFP_KERNEL);
if (unc_path == NULL)
return -ENOMEM;
unc_path_len = cifs_strtoUTF16(unc_path, tree, strlen(tree), cp) + 1;
unc_path_len *= 2;
if (unc_path_len < 2) {
kfree(unc_path);
return -EINVAL;
}
rc = small_smb2_init(SMB2_TREE_CONNECT, tcon, (void **) &req);
if (rc) {
kfree(unc_path);
return rc;
}
if (tcon == NULL) {
req->hdr.SessionId = ses->Suid;
}
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4 - 1;
req->PathOffset = cpu_to_le16(sizeof(struct smb2_tree_connect_req)
- 1 - 4 );
req->PathLength = cpu_to_le16(unc_path_len - 2);
iov[1].iov_base = unc_path;
iov[1].iov_len = unc_path_len;
inc_rfc1001_len(req, unc_path_len - 1 );
rc = SendReceive2(xid, ses, iov, 2, &resp_buftype, 0);
rsp = (struct smb2_tree_connect_rsp *)iov[0].iov_base;
if (rc != 0) {
if (tcon) {
cifs_stats_fail_inc(tcon, SMB2_TREE_CONNECT_HE);
tcon->need_reconnect = true;
}
goto tcon_error_exit;
}
if (rsp == NULL) {
rc = -EIO;
goto tcon_exit;
}
if (tcon == NULL) {
ses->ipc_tid = rsp->hdr.TreeId;
goto tcon_exit;
}
if (rsp->ShareType & SMB2_SHARE_TYPE_DISK)
cFYI(1, "connection to disk share");
else if (rsp->ShareType & SMB2_SHARE_TYPE_PIPE) {
tcon->ipc = true;
cFYI(1, "connection to pipe share");
} else if (rsp->ShareType & SMB2_SHARE_TYPE_PRINT) {
tcon->print = true;
cFYI(1, "connection to printer");
} else {
cERROR(1, "unknown share type %d", rsp->ShareType);
rc = -EOPNOTSUPP;
goto tcon_error_exit;
}
tcon->share_flags = le32_to_cpu(rsp->ShareFlags);
tcon->maximal_access = le32_to_cpu(rsp->MaximalAccess);
tcon->tidStatus = CifsGood;
tcon->need_reconnect = false;
tcon->tid = rsp->hdr.TreeId;
strncpy(tcon->treeName, tree, MAX_TREE_SIZE);
if ((rsp->Capabilities & SMB2_SHARE_CAP_DFS) &&
((tcon->share_flags & SHI1005_FLAGS_DFS) == 0))
cERROR(1, "DFS capability contradicts DFS flag");
tcon_exit:
free_rsp_buf(resp_buftype, rsp);
kfree(unc_path);
return rc;
tcon_error_exit:
if (rsp->hdr.Status == STATUS_BAD_NETWORK_NAME) {
cERROR(1, "BAD_NETWORK_NAME: %s", tree);
tcon->bad_network_name = true;
}
goto tcon_exit;
}
int
SMB2_tdis(const unsigned int xid, struct cifs_tcon *tcon)
{
struct smb2_tree_disconnect_req *req;
int rc = 0;
struct TCP_Server_Info *server;
struct cifs_ses *ses = tcon->ses;
cFYI(1, "Tree Disconnect");
if (ses && (ses->server))
server = ses->server;
else
return -EIO;
if ((tcon->need_reconnect) || (tcon->ses->need_reconnect))
return 0;
rc = small_smb2_init(SMB2_TREE_DISCONNECT, tcon, (void **) &req);
if (rc)
return rc;
rc = SendReceiveNoRsp(xid, ses, (char *)&req->hdr, 0);
if (rc)
cifs_stats_fail_inc(tcon, SMB2_TREE_DISCONNECT_HE);
return rc;
}
int
SMB2_open(const unsigned int xid, struct cifs_tcon *tcon, __le16 *path,
u64 *persistent_fid, u64 *volatile_fid, __u32 desired_access,
__u32 create_disposition, __u32 file_attributes, __u32 create_options)
{
struct smb2_create_req *req;
struct smb2_create_rsp *rsp;
struct TCP_Server_Info *server;
struct cifs_ses *ses = tcon->ses;
struct kvec iov[2];
int resp_buftype;
int uni_path_len;
int rc = 0;
int num_iovecs = 2;
cFYI(1, "create/open");
if (ses && (ses->server))
server = ses->server;
else
return -EIO;
rc = small_smb2_init(SMB2_CREATE, tcon, (void **) &req);
if (rc)
return rc;
if (enable_oplocks)
req->RequestedOplockLevel = SMB2_OPLOCK_LEVEL_BATCH;
else
req->RequestedOplockLevel = SMB2_OPLOCK_LEVEL_NONE;
req->ImpersonationLevel = IL_IMPERSONATION;
req->DesiredAccess = cpu_to_le32(desired_access);
req->FileAttributes = cpu_to_le32(file_attributes);
req->ShareAccess = FILE_SHARE_ALL_LE;
req->CreateDisposition = cpu_to_le32(create_disposition);
req->CreateOptions = cpu_to_le32(create_options);
uni_path_len = (2 * UniStrnlen((wchar_t *)path, PATH_MAX)) + 2;
req->NameOffset = cpu_to_le16(sizeof(struct smb2_create_req)
- 1 - 4 );
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4;
if (uni_path_len >= 4) {
req->NameLength = cpu_to_le16(uni_path_len - 2);
iov[0].iov_len--;
iov[1].iov_len = uni_path_len;
iov[1].iov_base = path;
inc_rfc1001_len(req, uni_path_len - 1);
} else {
num_iovecs = 1;
req->NameLength = 0;
}
rc = SendReceive2(xid, ses, iov, num_iovecs, &resp_buftype, 0);
rsp = (struct smb2_create_rsp *)iov[0].iov_base;
if (rc != 0) {
cifs_stats_fail_inc(tcon, SMB2_CREATE_HE);
goto creat_exit;
}
if (rsp == NULL) {
rc = -EIO;
goto creat_exit;
}
*persistent_fid = rsp->PersistentFileId;
*volatile_fid = rsp->VolatileFileId;
creat_exit:
free_rsp_buf(resp_buftype, rsp);
return rc;
}
int
SMB2_close(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid)
{
struct smb2_close_req *req;
struct smb2_close_rsp *rsp;
struct TCP_Server_Info *server;
struct cifs_ses *ses = tcon->ses;
struct kvec iov[1];
int resp_buftype;
int rc = 0;
cFYI(1, "Close");
if (ses && (ses->server))
server = ses->server;
else
return -EIO;
rc = small_smb2_init(SMB2_CLOSE, tcon, (void **) &req);
if (rc)
return rc;
req->PersistentFileId = persistent_fid;
req->VolatileFileId = volatile_fid;
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4;
rc = SendReceive2(xid, ses, iov, 1, &resp_buftype, 0);
rsp = (struct smb2_close_rsp *)iov[0].iov_base;
if (rc != 0) {
if (tcon)
cifs_stats_fail_inc(tcon, SMB2_CLOSE_HE);
goto close_exit;
}
if (rsp == NULL) {
rc = -EIO;
goto close_exit;
}
close_exit:
free_rsp_buf(resp_buftype, rsp);
return rc;
}
static int
validate_buf(unsigned int offset, unsigned int buffer_length,
struct smb2_hdr *hdr, unsigned int min_buf_size)
{
unsigned int smb_len = be32_to_cpu(hdr->smb2_buf_length);
char *end_of_smb = smb_len + 4 + (char *)hdr;
char *begin_of_buf = 4 + offset + (char *)hdr;
char *end_of_buf = begin_of_buf + buffer_length;
if (buffer_length < min_buf_size) {
cERROR(1, "buffer length %d smaller than minimum size %d",
buffer_length, min_buf_size);
return -EINVAL;
}
if ((smb_len > 0x7FFFFF) || (buffer_length > 0x7FFFFF)) {
cERROR(1, "buffer length %d or smb length %d too large",
buffer_length, smb_len);
return -EINVAL;
}
if ((begin_of_buf > end_of_smb) || (end_of_buf > end_of_smb)) {
cERROR(1, "illegal server response, bad offset to data");
return -EINVAL;
}
return 0;
}
static int
validate_and_copy_buf(unsigned int offset, unsigned int buffer_length,
struct smb2_hdr *hdr, unsigned int minbufsize,
char *data)
{
char *begin_of_buf = 4 + offset + (char *)hdr;
int rc;
if (!data)
return -EINVAL;
rc = validate_buf(offset, buffer_length, hdr, minbufsize);
if (rc)
return rc;
memcpy(data, begin_of_buf, buffer_length);
return 0;
}
int
SMB2_query_info(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid,
struct smb2_file_all_info *data)
{
struct smb2_query_info_req *req;
struct smb2_query_info_rsp *rsp = NULL;
struct kvec iov[2];
int rc = 0;
int resp_buftype;
struct TCP_Server_Info *server;
struct cifs_ses *ses = tcon->ses;
cFYI(1, "Query Info");
if (ses && (ses->server))
server = ses->server;
else
return -EIO;
rc = small_smb2_init(SMB2_QUERY_INFO, tcon, (void **) &req);
if (rc)
return rc;
req->InfoType = SMB2_O_INFO_FILE;
req->FileInfoClass = FILE_ALL_INFORMATION;
req->PersistentFileId = persistent_fid;
req->VolatileFileId = volatile_fid;
req->InputBufferOffset =
cpu_to_le16(sizeof(struct smb2_query_info_req) - 1 - 4);
req->OutputBufferLength =
cpu_to_le32(sizeof(struct smb2_file_all_info) + MAX_NAME * 2);
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4;
rc = SendReceive2(xid, ses, iov, 1, &resp_buftype, 0);
if (rc) {
cifs_stats_fail_inc(tcon, SMB2_QUERY_INFO_HE);
goto qinf_exit;
}
rsp = (struct smb2_query_info_rsp *)iov[0].iov_base;
rc = validate_and_copy_buf(le16_to_cpu(rsp->OutputBufferOffset),
le32_to_cpu(rsp->OutputBufferLength),
&rsp->hdr, sizeof(struct smb2_file_all_info),
(char *)data);
qinf_exit:
free_rsp_buf(resp_buftype, rsp);
return rc;
}
static void
smb2_echo_callback(struct mid_q_entry *mid)
{
struct TCP_Server_Info *server = mid->callback_data;
struct smb2_echo_rsp *smb2 = (struct smb2_echo_rsp *)mid->resp_buf;
unsigned int credits_received = 1;
if (mid->mid_state == MID_RESPONSE_RECEIVED)
credits_received = le16_to_cpu(smb2->hdr.CreditRequest);
DeleteMidQEntry(mid);
add_credits(server, credits_received, CIFS_ECHO_OP);
}
int
SMB2_echo(struct TCP_Server_Info *server)
{
struct smb2_echo_req *req;
int rc = 0;
struct kvec iov;
cFYI(1, "In echo request");
rc = small_smb2_init(SMB2_ECHO, NULL, (void **)&req);
if (rc)
return rc;
req->hdr.CreditRequest = cpu_to_le16(1);
iov.iov_base = (char *)req;
iov.iov_len = get_rfc1002_length(req) + 4;
rc = cifs_call_async(server, &iov, 1, NULL, smb2_echo_callback, server,
CIFS_ECHO_OP);
if (rc)
cFYI(1, "Echo request failed: %d", rc);
cifs_small_buf_release(req);
return rc;
}
