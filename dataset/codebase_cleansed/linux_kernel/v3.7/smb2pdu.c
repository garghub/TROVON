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
if (tcon->ses && tcon->ses->server &&
(tcon->ses->server->sec_mode & SECMODE_SIGN_REQUIRED))
hdr->Flags |= SMB2_FLAGS_SIGNED;
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
req->Dialects[0] = cpu_to_le16(ses->server->vals->protocol_id);
req->DialectCount = cpu_to_le16(1);
inc_rfc1001_len(req, 2);
if ((sec_flags & CIFSSEC_MUST_SIGN) == CIFSSEC_MUST_SIGN)
temp = SMB2_NEGOTIATE_SIGNING_REQUIRED;
else if (sec_flags & CIFSSEC_MAY_SIGN)
temp = SMB2_NEGOTIATE_SIGNING_ENABLED;
req->SecurityMode = cpu_to_le16(temp);
req->Capabilities = cpu_to_le32(ses->server->vals->req_capabilities);
memcpy(req->ClientGUID, cifs_client_guid, SMB2_CLIENT_GUID_SIZE);
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4;
rc = SendReceive2(xid, ses, iov, 1, &resp_buftype, flags);
rsp = (struct smb2_negotiate_rsp *)iov[0].iov_base;
if (rc != 0)
goto neg_exit;
cFYI(1, "mode 0x%x", rsp->SecurityMode);
if (rsp->DialectRevision == cpu_to_le16(SMB20_PROT_ID))
cFYI(1, "negotiated smb2.0 dialect");
else if (rsp->DialectRevision == cpu_to_le16(SMB21_PROT_ID))
cFYI(1, "negotiated smb2.1 dialect");
else if (rsp->DialectRevision == cpu_to_le16(SMB30_PROT_ID))
cFYI(1, "negotiated smb3.0 dialect");
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
cFYI(1, "sec_flags 0x%x", sec_flags);
if (sec_flags & CIFSSEC_MUST_SIGN) {
cFYI(1, "Signing required");
if (!(server->sec_mode & (SMB2_NEGOTIATE_SIGNING_REQUIRED |
SMB2_NEGOTIATE_SIGNING_ENABLED))) {
cERROR(1, "signing required but server lacks support");
rc = -EOPNOTSUPP;
goto neg_exit;
}
server->sec_mode |= SECMODE_SIGN_REQUIRED;
} else if (sec_flags & CIFSSEC_MAY_SIGN) {
cFYI(1, "Signing optional");
if (server->sec_mode & SMB2_NEGOTIATE_SIGNING_REQUIRED) {
cFYI(1, "Server requires signing");
server->sec_mode |= SECMODE_SIGN_REQUIRED;
} else {
server->sec_mode &=
~(SECMODE_SIGN_ENABLED | SECMODE_SIGN_REQUIRED);
}
} else {
cFYI(1, "Signing disabled");
if (server->sec_mode & SMB2_NEGOTIATE_SIGNING_REQUIRED) {
cERROR(1, "Server requires packet signing to be enabled"
" in /proc/fs/cifs/SecurityFlags.");
rc = -EOPNOTSUPP;
goto neg_exit;
}
server->sec_mode &=
~(SECMODE_SIGN_ENABLED | SECMODE_SIGN_REQUIRED);
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
if (resp_buftype != CIFS_NO_BUFFER &&
rsp->hdr.Status == STATUS_MORE_PROCESSING_REQUIRED) {
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
if (server->sec_mode & SECMODE_SIGN_REQUIRED)
req->hdr.Flags |= SMB2_FLAGS_SIGNED;
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
static struct create_lease *
create_lease_buf(u8 *lease_key, u8 oplock)
{
struct create_lease *buf;
buf = kmalloc(sizeof(struct create_lease), GFP_KERNEL);
if (!buf)
return NULL;
memset(buf, 0, sizeof(struct create_lease));
buf->lcontext.LeaseKeyLow = cpu_to_le64(*((u64 *)lease_key));
buf->lcontext.LeaseKeyHigh = cpu_to_le64(*((u64 *)(lease_key + 8)));
if (oplock == SMB2_OPLOCK_LEVEL_EXCLUSIVE)
buf->lcontext.LeaseState = SMB2_LEASE_WRITE_CACHING |
SMB2_LEASE_READ_CACHING;
else if (oplock == SMB2_OPLOCK_LEVEL_II)
buf->lcontext.LeaseState = SMB2_LEASE_READ_CACHING;
else if (oplock == SMB2_OPLOCK_LEVEL_BATCH)
buf->lcontext.LeaseState = SMB2_LEASE_HANDLE_CACHING |
SMB2_LEASE_READ_CACHING |
SMB2_LEASE_WRITE_CACHING;
buf->ccontext.DataOffset = cpu_to_le16(offsetof
(struct create_lease, lcontext));
buf->ccontext.DataLength = cpu_to_le32(sizeof(struct lease_context));
buf->ccontext.NameOffset = cpu_to_le16(offsetof
(struct create_lease, Name));
buf->ccontext.NameLength = cpu_to_le16(4);
buf->Name[0] = 'R';
buf->Name[1] = 'q';
buf->Name[2] = 'L';
buf->Name[3] = 's';
return buf;
}
static __u8
parse_lease_state(struct smb2_create_rsp *rsp)
{
char *data_offset;
struct create_lease *lc;
bool found = false;
data_offset = (char *)rsp;
data_offset += 4 + le32_to_cpu(rsp->CreateContextsOffset);
lc = (struct create_lease *)data_offset;
do {
char *name = le16_to_cpu(lc->ccontext.NameOffset) + (char *)lc;
if (le16_to_cpu(lc->ccontext.NameLength) != 4 ||
strncmp(name, "RqLs", 4)) {
lc = (struct create_lease *)((char *)lc
+ le32_to_cpu(lc->ccontext.Next));
continue;
}
if (lc->lcontext.LeaseFlags & SMB2_LEASE_FLAG_BREAK_IN_PROGRESS)
return SMB2_OPLOCK_LEVEL_NOCHANGE;
found = true;
break;
} while (le32_to_cpu(lc->ccontext.Next) != 0);
if (!found)
return 0;
return smb2_map_lease_to_oplock(lc->lcontext.LeaseState);
}
int
SMB2_open(const unsigned int xid, struct cifs_tcon *tcon, __le16 *path,
u64 *persistent_fid, u64 *volatile_fid, __u32 desired_access,
__u32 create_disposition, __u32 file_attributes, __u32 create_options,
__u8 *oplock, struct smb2_file_all_info *buf)
{
struct smb2_create_req *req;
struct smb2_create_rsp *rsp;
struct TCP_Server_Info *server;
struct cifs_ses *ses = tcon->ses;
struct kvec iov[3];
int resp_buftype;
int uni_path_len;
__le16 *copy_path = NULL;
int copy_size;
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
req->ImpersonationLevel = IL_IMPERSONATION;
req->DesiredAccess = cpu_to_le32(desired_access);
req->FileAttributes = cpu_to_le32(file_attributes);
req->ShareAccess = FILE_SHARE_ALL_LE;
req->CreateDisposition = cpu_to_le32(create_disposition);
req->CreateOptions = cpu_to_le32(create_options);
uni_path_len = (2 * UniStrnlen((wchar_t *)path, PATH_MAX)) + 2;
req->NameOffset = cpu_to_le16(sizeof(struct smb2_create_req)
- 8 - 4 );
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4;
if (uni_path_len >= 4) {
req->NameLength = cpu_to_le16(uni_path_len - 2);
iov[0].iov_len--;
if (uni_path_len % 8 != 0) {
copy_size = uni_path_len / 8 * 8;
if (copy_size < uni_path_len)
copy_size += 8;
copy_path = kzalloc(copy_size, GFP_KERNEL);
if (!copy_path)
return -ENOMEM;
memcpy((char *)copy_path, (const char *)path,
uni_path_len);
uni_path_len = copy_size;
path = copy_path;
}
iov[1].iov_len = uni_path_len;
iov[1].iov_base = path;
inc_rfc1001_len(req, uni_path_len - 1);
} else {
iov[0].iov_len += 7;
req->hdr.smb2_buf_length = cpu_to_be32(be32_to_cpu(
req->hdr.smb2_buf_length) + 8 - 1);
num_iovecs = 1;
req->NameLength = 0;
}
if (!server->oplocks)
*oplock = SMB2_OPLOCK_LEVEL_NONE;
if (!(tcon->ses->server->capabilities & SMB2_GLOBAL_CAP_LEASING) ||
*oplock == SMB2_OPLOCK_LEVEL_NONE)
req->RequestedOplockLevel = *oplock;
else {
iov[num_iovecs].iov_base = create_lease_buf(oplock+1, *oplock);
if (iov[num_iovecs].iov_base == NULL) {
cifs_small_buf_release(req);
kfree(copy_path);
return -ENOMEM;
}
iov[num_iovecs].iov_len = sizeof(struct create_lease);
req->RequestedOplockLevel = SMB2_OPLOCK_LEVEL_LEASE;
req->CreateContextsOffset = cpu_to_le32(
sizeof(struct smb2_create_req) - 4 - 8 +
iov[num_iovecs-1].iov_len);
req->CreateContextsLength = cpu_to_le32(
sizeof(struct create_lease));
inc_rfc1001_len(&req->hdr, sizeof(struct create_lease));
num_iovecs++;
}
rc = SendReceive2(xid, ses, iov, num_iovecs, &resp_buftype, 0);
rsp = (struct smb2_create_rsp *)iov[0].iov_base;
if (rc != 0) {
cifs_stats_fail_inc(tcon, SMB2_CREATE_HE);
goto creat_exit;
}
*persistent_fid = rsp->PersistentFileId;
*volatile_fid = rsp->VolatileFileId;
if (buf) {
memcpy(buf, &rsp->CreationTime, 32);
buf->AllocationSize = rsp->AllocationSize;
buf->EndOfFile = rsp->EndofFile;
buf->Attributes = rsp->FileAttributes;
buf->NumberOfLinks = cpu_to_le32(1);
buf->DeletePending = 0;
}
if (rsp->OplockLevel == SMB2_OPLOCK_LEVEL_LEASE)
*oplock = parse_lease_state(rsp);
else
*oplock = rsp->OplockLevel;
creat_exit:
kfree(copy_path);
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
static int
query_info(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid, u8 info_class,
size_t output_len, size_t min_len, void *data)
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
req->FileInfoClass = info_class;
req->PersistentFileId = persistent_fid;
req->VolatileFileId = volatile_fid;
req->InputBufferOffset =
cpu_to_le16(sizeof(struct smb2_query_info_req) - 1 - 4);
req->OutputBufferLength = cpu_to_le32(output_len);
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4;
rc = SendReceive2(xid, ses, iov, 1, &resp_buftype, 0);
rsp = (struct smb2_query_info_rsp *)iov[0].iov_base;
if (rc) {
cifs_stats_fail_inc(tcon, SMB2_QUERY_INFO_HE);
goto qinf_exit;
}
rc = validate_and_copy_buf(le16_to_cpu(rsp->OutputBufferOffset),
le32_to_cpu(rsp->OutputBufferLength),
&rsp->hdr, min_len, data);
qinf_exit:
free_rsp_buf(resp_buftype, rsp);
return rc;
}
int
SMB2_query_info(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid,
struct smb2_file_all_info *data)
{
return query_info(xid, tcon, persistent_fid, volatile_fid,
FILE_ALL_INFORMATION,
sizeof(struct smb2_file_all_info) + MAX_NAME * 2,
sizeof(struct smb2_file_all_info), data);
}
int
SMB2_get_srv_num(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid, __le64 *uniqueid)
{
return query_info(xid, tcon, persistent_fid, volatile_fid,
FILE_INTERNAL_INFORMATION,
sizeof(struct smb2_file_internal_info),
sizeof(struct smb2_file_internal_info), uniqueid);
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
struct smb_rqst rqst = { .rq_iov = &iov,
.rq_nvec = 1 };
cFYI(1, "In echo request");
rc = small_smb2_init(SMB2_ECHO, NULL, (void **)&req);
if (rc)
return rc;
req->hdr.CreditRequest = cpu_to_le16(1);
iov.iov_base = (char *)req;
iov.iov_len = get_rfc1002_length(req) + 4;
rc = cifs_call_async(server, &rqst, NULL, smb2_echo_callback, server,
CIFS_ECHO_OP);
if (rc)
cFYI(1, "Echo request failed: %d", rc);
cifs_small_buf_release(req);
return rc;
}
int
SMB2_flush(const unsigned int xid, struct cifs_tcon *tcon, u64 persistent_fid,
u64 volatile_fid)
{
struct smb2_flush_req *req;
struct TCP_Server_Info *server;
struct cifs_ses *ses = tcon->ses;
struct kvec iov[1];
int resp_buftype;
int rc = 0;
cFYI(1, "Flush");
if (ses && (ses->server))
server = ses->server;
else
return -EIO;
rc = small_smb2_init(SMB2_FLUSH, tcon, (void **) &req);
if (rc)
return rc;
req->PersistentFileId = persistent_fid;
req->VolatileFileId = volatile_fid;
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4;
rc = SendReceive2(xid, ses, iov, 1, &resp_buftype, 0);
if ((rc != 0) && tcon)
cifs_stats_fail_inc(tcon, SMB2_FLUSH_HE);
free_rsp_buf(resp_buftype, iov[0].iov_base);
return rc;
}
static int
smb2_new_read_req(struct kvec *iov, struct cifs_io_parms *io_parms,
unsigned int remaining_bytes, int request_type)
{
int rc = -EACCES;
struct smb2_read_req *req = NULL;
rc = small_smb2_init(SMB2_READ, io_parms->tcon, (void **) &req);
if (rc)
return rc;
if (io_parms->tcon->ses->server == NULL)
return -ECONNABORTED;
req->hdr.ProcessId = cpu_to_le32(io_parms->pid);
req->PersistentFileId = io_parms->persistent_fid;
req->VolatileFileId = io_parms->volatile_fid;
req->ReadChannelInfoOffset = 0;
req->ReadChannelInfoLength = 0;
req->Channel = 0;
req->MinimumCount = 0;
req->Length = cpu_to_le32(io_parms->length);
req->Offset = cpu_to_le64(io_parms->offset);
if (request_type & CHAINED_REQUEST) {
if (!(request_type & END_OF_CHAIN)) {
req->hdr.NextCommand =
cpu_to_le32(get_rfc1002_length(req) + 4);
} else
req->hdr.NextCommand = 0;
if (request_type & RELATED_REQUEST) {
req->hdr.Flags |= SMB2_FLAGS_RELATED_OPERATIONS;
req->hdr.SessionId = 0xFFFFFFFF;
req->hdr.TreeId = 0xFFFFFFFF;
req->PersistentFileId = 0xFFFFFFFF;
req->VolatileFileId = 0xFFFFFFFF;
}
}
if (remaining_bytes > io_parms->length)
req->RemainingBytes = cpu_to_le32(remaining_bytes);
else
req->RemainingBytes = 0;
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4;
return rc;
}
static void
smb2_readv_callback(struct mid_q_entry *mid)
{
struct cifs_readdata *rdata = mid->callback_data;
struct cifs_tcon *tcon = tlink_tcon(rdata->cfile->tlink);
struct TCP_Server_Info *server = tcon->ses->server;
struct smb2_hdr *buf = (struct smb2_hdr *)rdata->iov.iov_base;
unsigned int credits_received = 1;
struct smb_rqst rqst = { .rq_iov = &rdata->iov,
.rq_nvec = 1,
.rq_pages = rdata->pages,
.rq_npages = rdata->nr_pages,
.rq_pagesz = rdata->pagesz,
.rq_tailsz = rdata->tailsz };
cFYI(1, "%s: mid=%llu state=%d result=%d bytes=%u", __func__,
mid->mid, mid->mid_state, rdata->result, rdata->bytes);
switch (mid->mid_state) {
case MID_RESPONSE_RECEIVED:
credits_received = le16_to_cpu(buf->CreditRequest);
if (server->sec_mode &
(SECMODE_SIGN_REQUIRED | SECMODE_SIGN_ENABLED)) {
int rc;
rc = smb2_verify_signature(&rqst, server);
if (rc)
cERROR(1, "SMB signature verification returned "
"error = %d", rc);
}
task_io_account_read(rdata->bytes);
cifs_stats_bytes_read(tcon, rdata->bytes);
break;
case MID_REQUEST_SUBMITTED:
case MID_RETRY_NEEDED:
rdata->result = -EAGAIN;
break;
default:
if (rdata->result != -ENODATA)
rdata->result = -EIO;
}
if (rdata->result)
cifs_stats_fail_inc(tcon, SMB2_READ_HE);
queue_work(cifsiod_wq, &rdata->work);
DeleteMidQEntry(mid);
add_credits(server, credits_received, 0);
}
int
smb2_async_readv(struct cifs_readdata *rdata)
{
int rc;
struct smb2_hdr *buf;
struct cifs_io_parms io_parms;
struct smb_rqst rqst = { .rq_iov = &rdata->iov,
.rq_nvec = 1 };
cFYI(1, "%s: offset=%llu bytes=%u", __func__,
rdata->offset, rdata->bytes);
io_parms.tcon = tlink_tcon(rdata->cfile->tlink);
io_parms.offset = rdata->offset;
io_parms.length = rdata->bytes;
io_parms.persistent_fid = rdata->cfile->fid.persistent_fid;
io_parms.volatile_fid = rdata->cfile->fid.volatile_fid;
io_parms.pid = rdata->pid;
rc = smb2_new_read_req(&rdata->iov, &io_parms, 0, 0);
if (rc)
return rc;
buf = (struct smb2_hdr *)rdata->iov.iov_base;
rdata->iov.iov_len = get_rfc1002_length(rdata->iov.iov_base) + 4;
kref_get(&rdata->refcount);
rc = cifs_call_async(io_parms.tcon->ses->server, &rqst,
cifs_readv_receive, smb2_readv_callback,
rdata, 0);
if (rc) {
kref_put(&rdata->refcount, cifs_readdata_release);
cifs_stats_fail_inc(io_parms.tcon, SMB2_READ_HE);
}
cifs_small_buf_release(buf);
return rc;
}
int
SMB2_read(const unsigned int xid, struct cifs_io_parms *io_parms,
unsigned int *nbytes, char **buf, int *buf_type)
{
int resp_buftype, rc = -EACCES;
struct smb2_read_rsp *rsp = NULL;
struct kvec iov[1];
*nbytes = 0;
rc = smb2_new_read_req(iov, io_parms, 0, 0);
if (rc)
return rc;
rc = SendReceive2(xid, io_parms->tcon->ses, iov, 1,
&resp_buftype, CIFS_LOG_ERROR);
rsp = (struct smb2_read_rsp *)iov[0].iov_base;
if (rsp->hdr.Status == STATUS_END_OF_FILE) {
free_rsp_buf(resp_buftype, iov[0].iov_base);
return 0;
}
if (rc) {
cifs_stats_fail_inc(io_parms->tcon, SMB2_READ_HE);
cERROR(1, "Send error in read = %d", rc);
} else {
*nbytes = le32_to_cpu(rsp->DataLength);
if ((*nbytes > CIFS_MAX_MSGSIZE) ||
(*nbytes > io_parms->length)) {
cFYI(1, "bad length %d for count %d", *nbytes,
io_parms->length);
rc = -EIO;
*nbytes = 0;
}
}
if (*buf) {
memcpy(*buf, (char *)rsp->hdr.ProtocolId + rsp->DataOffset,
*nbytes);
free_rsp_buf(resp_buftype, iov[0].iov_base);
} else if (resp_buftype != CIFS_NO_BUFFER) {
*buf = iov[0].iov_base;
if (resp_buftype == CIFS_SMALL_BUFFER)
*buf_type = CIFS_SMALL_BUFFER;
else if (resp_buftype == CIFS_LARGE_BUFFER)
*buf_type = CIFS_LARGE_BUFFER;
}
return rc;
}
static void
smb2_writev_callback(struct mid_q_entry *mid)
{
struct cifs_writedata *wdata = mid->callback_data;
struct cifs_tcon *tcon = tlink_tcon(wdata->cfile->tlink);
unsigned int written;
struct smb2_write_rsp *rsp = (struct smb2_write_rsp *)mid->resp_buf;
unsigned int credits_received = 1;
switch (mid->mid_state) {
case MID_RESPONSE_RECEIVED:
credits_received = le16_to_cpu(rsp->hdr.CreditRequest);
wdata->result = smb2_check_receive(mid, tcon->ses->server, 0);
if (wdata->result != 0)
break;
written = le32_to_cpu(rsp->DataLength);
if (written > wdata->bytes)
written &= 0xFFFF;
if (written < wdata->bytes)
wdata->result = -ENOSPC;
else
wdata->bytes = written;
break;
case MID_REQUEST_SUBMITTED:
case MID_RETRY_NEEDED:
wdata->result = -EAGAIN;
break;
default:
wdata->result = -EIO;
break;
}
if (wdata->result)
cifs_stats_fail_inc(tcon, SMB2_WRITE_HE);
queue_work(cifsiod_wq, &wdata->work);
DeleteMidQEntry(mid);
add_credits(tcon->ses->server, credits_received, 0);
}
int
smb2_async_writev(struct cifs_writedata *wdata)
{
int rc = -EACCES;
struct smb2_write_req *req = NULL;
struct cifs_tcon *tcon = tlink_tcon(wdata->cfile->tlink);
struct kvec iov;
struct smb_rqst rqst;
rc = small_smb2_init(SMB2_WRITE, tcon, (void **) &req);
if (rc)
goto async_writev_out;
req->hdr.ProcessId = cpu_to_le32(wdata->cfile->pid);
req->PersistentFileId = wdata->cfile->fid.persistent_fid;
req->VolatileFileId = wdata->cfile->fid.volatile_fid;
req->WriteChannelInfoOffset = 0;
req->WriteChannelInfoLength = 0;
req->Channel = 0;
req->Offset = cpu_to_le64(wdata->offset);
req->DataOffset = cpu_to_le16(
offsetof(struct smb2_write_req, Buffer) - 4);
req->RemainingBytes = 0;
iov.iov_len = get_rfc1002_length(req) + 4 - 1;
iov.iov_base = req;
rqst.rq_iov = &iov;
rqst.rq_nvec = 1;
rqst.rq_pages = wdata->pages;
rqst.rq_npages = wdata->nr_pages;
rqst.rq_pagesz = wdata->pagesz;
rqst.rq_tailsz = wdata->tailsz;
cFYI(1, "async write at %llu %u bytes", wdata->offset, wdata->bytes);
req->Length = cpu_to_le32(wdata->bytes);
inc_rfc1001_len(&req->hdr, wdata->bytes - 1 );
kref_get(&wdata->refcount);
rc = cifs_call_async(tcon->ses->server, &rqst, NULL,
smb2_writev_callback, wdata, 0);
if (rc) {
kref_put(&wdata->refcount, cifs_writedata_release);
cifs_stats_fail_inc(tcon, SMB2_WRITE_HE);
}
async_writev_out:
cifs_small_buf_release(req);
return rc;
}
int
SMB2_write(const unsigned int xid, struct cifs_io_parms *io_parms,
unsigned int *nbytes, struct kvec *iov, int n_vec)
{
int rc = 0;
struct smb2_write_req *req = NULL;
struct smb2_write_rsp *rsp = NULL;
int resp_buftype;
*nbytes = 0;
if (n_vec < 1)
return rc;
rc = small_smb2_init(SMB2_WRITE, io_parms->tcon, (void **) &req);
if (rc)
return rc;
if (io_parms->tcon->ses->server == NULL)
return -ECONNABORTED;
req->hdr.ProcessId = cpu_to_le32(io_parms->pid);
req->PersistentFileId = io_parms->persistent_fid;
req->VolatileFileId = io_parms->volatile_fid;
req->WriteChannelInfoOffset = 0;
req->WriteChannelInfoLength = 0;
req->Channel = 0;
req->Length = cpu_to_le32(io_parms->length);
req->Offset = cpu_to_le64(io_parms->offset);
req->DataOffset = cpu_to_le16(
offsetof(struct smb2_write_req, Buffer) - 4);
req->RemainingBytes = 0;
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4 - 1;
inc_rfc1001_len(req, io_parms->length - 1 );
rc = SendReceive2(xid, io_parms->tcon->ses, iov, n_vec + 1,
&resp_buftype, 0);
rsp = (struct smb2_write_rsp *)iov[0].iov_base;
if (rc) {
cifs_stats_fail_inc(io_parms->tcon, SMB2_WRITE_HE);
cERROR(1, "Send error in write = %d", rc);
} else
*nbytes = le32_to_cpu(rsp->DataLength);
free_rsp_buf(resp_buftype, rsp);
return rc;
}
static unsigned int
num_entries(char *bufstart, char *end_of_buf, char **lastentry, size_t size)
{
int len;
unsigned int entrycount = 0;
unsigned int next_offset = 0;
FILE_DIRECTORY_INFO *entryptr;
if (bufstart == NULL)
return 0;
entryptr = (FILE_DIRECTORY_INFO *)bufstart;
while (1) {
entryptr = (FILE_DIRECTORY_INFO *)
((char *)entryptr + next_offset);
if ((char *)entryptr + size > end_of_buf) {
cERROR(1, "malformed search entry would overflow");
break;
}
len = le32_to_cpu(entryptr->FileNameLength);
if ((char *)entryptr + len + size > end_of_buf) {
cERROR(1, "directory entry name would overflow frame "
"end of buf %p", end_of_buf);
break;
}
*lastentry = (char *)entryptr;
entrycount++;
next_offset = le32_to_cpu(entryptr->NextEntryOffset);
if (!next_offset)
break;
}
return entrycount;
}
int
SMB2_query_directory(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid, int index,
struct cifs_search_info *srch_inf)
{
struct smb2_query_directory_req *req;
struct smb2_query_directory_rsp *rsp = NULL;
struct kvec iov[2];
int rc = 0;
int len;
int resp_buftype;
unsigned char *bufptr;
struct TCP_Server_Info *server;
struct cifs_ses *ses = tcon->ses;
__le16 asteriks = cpu_to_le16('*');
char *end_of_smb;
unsigned int output_size = CIFSMaxBufSize;
size_t info_buf_size;
if (ses && (ses->server))
server = ses->server;
else
return -EIO;
rc = small_smb2_init(SMB2_QUERY_DIRECTORY, tcon, (void **) &req);
if (rc)
return rc;
switch (srch_inf->info_level) {
case SMB_FIND_FILE_DIRECTORY_INFO:
req->FileInformationClass = FILE_DIRECTORY_INFORMATION;
info_buf_size = sizeof(FILE_DIRECTORY_INFO) - 1;
break;
case SMB_FIND_FILE_ID_FULL_DIR_INFO:
req->FileInformationClass = FILEID_FULL_DIRECTORY_INFORMATION;
info_buf_size = sizeof(SEARCH_ID_FULL_DIR_INFO) - 1;
break;
default:
cERROR(1, "info level %u isn't supported",
srch_inf->info_level);
rc = -EINVAL;
goto qdir_exit;
}
req->FileIndex = cpu_to_le32(index);
req->PersistentFileId = persistent_fid;
req->VolatileFileId = volatile_fid;
len = 0x2;
bufptr = req->Buffer;
memcpy(bufptr, &asteriks, len);
req->FileNameOffset =
cpu_to_le16(sizeof(struct smb2_query_directory_req) - 1 - 4);
req->FileNameLength = cpu_to_le16(len);
output_size = min_t(unsigned int, output_size, server->maxBuf);
output_size = min_t(unsigned int, output_size, 2 << 15);
req->OutputBufferLength = cpu_to_le32(output_size);
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4 - 1;
iov[1].iov_base = (char *)(req->Buffer);
iov[1].iov_len = len;
inc_rfc1001_len(req, len - 1 );
rc = SendReceive2(xid, ses, iov, 2, &resp_buftype, 0);
rsp = (struct smb2_query_directory_rsp *)iov[0].iov_base;
if (rc) {
cifs_stats_fail_inc(tcon, SMB2_QUERY_DIRECTORY_HE);
goto qdir_exit;
}
rc = validate_buf(le16_to_cpu(rsp->OutputBufferOffset),
le32_to_cpu(rsp->OutputBufferLength), &rsp->hdr,
info_buf_size);
if (rc)
goto qdir_exit;
srch_inf->unicode = true;
if (srch_inf->ntwrk_buf_start) {
if (srch_inf->smallBuf)
cifs_small_buf_release(srch_inf->ntwrk_buf_start);
else
cifs_buf_release(srch_inf->ntwrk_buf_start);
}
srch_inf->ntwrk_buf_start = (char *)rsp;
srch_inf->srch_entries_start = srch_inf->last_entry = 4 +
(char *)&rsp->hdr + le16_to_cpu(rsp->OutputBufferOffset);
end_of_smb = get_rfc1002_length(rsp) + 4 + (char *)&rsp->hdr;
srch_inf->entries_in_buffer =
num_entries(srch_inf->srch_entries_start, end_of_smb,
&srch_inf->last_entry, info_buf_size);
srch_inf->index_of_last_entry += srch_inf->entries_in_buffer;
cFYI(1, "num entries %d last_index %lld srch start %p srch end %p",
srch_inf->entries_in_buffer, srch_inf->index_of_last_entry,
srch_inf->srch_entries_start, srch_inf->last_entry);
if (resp_buftype == CIFS_LARGE_BUFFER)
srch_inf->smallBuf = false;
else if (resp_buftype == CIFS_SMALL_BUFFER)
srch_inf->smallBuf = true;
else
cERROR(1, "illegal search buffer type");
if (rsp->hdr.Status == STATUS_NO_MORE_FILES)
srch_inf->endOfSearch = 1;
else
srch_inf->endOfSearch = 0;
return rc;
qdir_exit:
free_rsp_buf(resp_buftype, rsp);
return rc;
}
static int
send_set_info(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid, u32 pid, int info_class,
unsigned int num, void **data, unsigned int *size)
{
struct smb2_set_info_req *req;
struct smb2_set_info_rsp *rsp = NULL;
struct kvec *iov;
int rc = 0;
int resp_buftype;
unsigned int i;
struct TCP_Server_Info *server;
struct cifs_ses *ses = tcon->ses;
if (ses && (ses->server))
server = ses->server;
else
return -EIO;
if (!num)
return -EINVAL;
iov = kmalloc(sizeof(struct kvec) * num, GFP_KERNEL);
if (!iov)
return -ENOMEM;
rc = small_smb2_init(SMB2_SET_INFO, tcon, (void **) &req);
if (rc) {
kfree(iov);
return rc;
}
req->hdr.ProcessId = cpu_to_le32(pid);
req->InfoType = SMB2_O_INFO_FILE;
req->FileInfoClass = info_class;
req->PersistentFileId = persistent_fid;
req->VolatileFileId = volatile_fid;
req->BufferOffset =
cpu_to_le16(sizeof(struct smb2_set_info_req) - 1 - 4);
req->BufferLength = cpu_to_le32(*size);
inc_rfc1001_len(req, *size - 1 );
memcpy(req->Buffer, *data, *size);
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4;
for (i = 1; i < num; i++) {
inc_rfc1001_len(req, size[i]);
le32_add_cpu(&req->BufferLength, size[i]);
iov[i].iov_base = (char *)data[i];
iov[i].iov_len = size[i];
}
rc = SendReceive2(xid, ses, iov, num, &resp_buftype, 0);
rsp = (struct smb2_set_info_rsp *)iov[0].iov_base;
if (rc != 0) {
cifs_stats_fail_inc(tcon, SMB2_SET_INFO_HE);
goto out;
}
out:
free_rsp_buf(resp_buftype, rsp);
kfree(iov);
return rc;
}
int
SMB2_rename(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid, __le16 *target_file)
{
struct smb2_file_rename_info info;
void **data;
unsigned int size[2];
int rc;
int len = (2 * UniStrnlen((wchar_t *)target_file, PATH_MAX));
data = kmalloc(sizeof(void *) * 2, GFP_KERNEL);
if (!data)
return -ENOMEM;
info.ReplaceIfExists = 1;
info.RootDirectory = 0;
info.FileNameLength = cpu_to_le32(len);
data[0] = &info;
size[0] = sizeof(struct smb2_file_rename_info);
data[1] = target_file;
size[1] = len + 2 ;
rc = send_set_info(xid, tcon, persistent_fid, volatile_fid,
current->tgid, FILE_RENAME_INFORMATION, 2, data,
size);
kfree(data);
return rc;
}
int
SMB2_set_hardlink(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid, __le16 *target_file)
{
struct smb2_file_link_info info;
void **data;
unsigned int size[2];
int rc;
int len = (2 * UniStrnlen((wchar_t *)target_file, PATH_MAX));
data = kmalloc(sizeof(void *) * 2, GFP_KERNEL);
if (!data)
return -ENOMEM;
info.ReplaceIfExists = 0;
info.RootDirectory = 0;
info.FileNameLength = cpu_to_le32(len);
data[0] = &info;
size[0] = sizeof(struct smb2_file_link_info);
data[1] = target_file;
size[1] = len + 2 ;
rc = send_set_info(xid, tcon, persistent_fid, volatile_fid,
current->tgid, FILE_LINK_INFORMATION, 2, data, size);
kfree(data);
return rc;
}
int
SMB2_set_eof(const unsigned int xid, struct cifs_tcon *tcon, u64 persistent_fid,
u64 volatile_fid, u32 pid, __le64 *eof)
{
struct smb2_file_eof_info info;
void *data;
unsigned int size;
info.EndOfFile = *eof;
data = &info;
size = sizeof(struct smb2_file_eof_info);
return send_set_info(xid, tcon, persistent_fid, volatile_fid, pid,
FILE_END_OF_FILE_INFORMATION, 1, &data, &size);
}
int
SMB2_set_info(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid, FILE_BASIC_INFO *buf)
{
unsigned int size;
size = sizeof(FILE_BASIC_INFO);
return send_set_info(xid, tcon, persistent_fid, volatile_fid,
current->tgid, FILE_BASIC_INFORMATION, 1,
(void **)&buf, &size);
}
int
SMB2_oplock_break(const unsigned int xid, struct cifs_tcon *tcon,
const u64 persistent_fid, const u64 volatile_fid,
__u8 oplock_level)
{
int rc;
struct smb2_oplock_break *req = NULL;
cFYI(1, "SMB2_oplock_break");
rc = small_smb2_init(SMB2_OPLOCK_BREAK, tcon, (void **) &req);
if (rc)
return rc;
req->VolatileFid = volatile_fid;
req->PersistentFid = persistent_fid;
req->OplockLevel = oplock_level;
req->hdr.CreditRequest = cpu_to_le16(1);
rc = SendReceiveNoRsp(xid, tcon->ses, (char *) req, CIFS_OBREAK_OP);
if (rc) {
cifs_stats_fail_inc(tcon, SMB2_OPLOCK_BREAK_HE);
cFYI(1, "Send error in Oplock Break = %d", rc);
}
return rc;
}
static void
copy_fs_info_to_kstatfs(struct smb2_fs_full_size_info *pfs_inf,
struct kstatfs *kst)
{
kst->f_bsize = le32_to_cpu(pfs_inf->BytesPerSector) *
le32_to_cpu(pfs_inf->SectorsPerAllocationUnit);
kst->f_blocks = le64_to_cpu(pfs_inf->TotalAllocationUnits);
kst->f_bfree = le64_to_cpu(pfs_inf->ActualAvailableAllocationUnits);
kst->f_bavail = le64_to_cpu(pfs_inf->CallerAvailableAllocationUnits);
return;
}
static int
build_qfs_info_req(struct kvec *iov, struct cifs_tcon *tcon, int level,
int outbuf_len, u64 persistent_fid, u64 volatile_fid)
{
int rc;
struct smb2_query_info_req *req;
cFYI(1, "Query FSInfo level %d", level);
if ((tcon->ses == NULL) || (tcon->ses->server == NULL))
return -EIO;
rc = small_smb2_init(SMB2_QUERY_INFO, tcon, (void **) &req);
if (rc)
return rc;
req->InfoType = SMB2_O_INFO_FILESYSTEM;
req->FileInfoClass = level;
req->PersistentFileId = persistent_fid;
req->VolatileFileId = volatile_fid;
req->InputBufferOffset =
cpu_to_le16(sizeof(struct smb2_query_info_req) - 1 - 4);
req->OutputBufferLength = cpu_to_le32(
outbuf_len + sizeof(struct smb2_query_info_rsp) - 1 - 4);
iov->iov_base = (char *)req;
iov->iov_len = get_rfc1002_length(req) + 4;
return 0;
}
int
SMB2_QFS_info(const unsigned int xid, struct cifs_tcon *tcon,
u64 persistent_fid, u64 volatile_fid, struct kstatfs *fsdata)
{
struct smb2_query_info_rsp *rsp = NULL;
struct kvec iov;
int rc = 0;
int resp_buftype;
struct cifs_ses *ses = tcon->ses;
struct smb2_fs_full_size_info *info = NULL;
rc = build_qfs_info_req(&iov, tcon, FS_FULL_SIZE_INFORMATION,
sizeof(struct smb2_fs_full_size_info),
persistent_fid, volatile_fid);
if (rc)
return rc;
rc = SendReceive2(xid, ses, &iov, 1, &resp_buftype, 0);
if (rc) {
cifs_stats_fail_inc(tcon, SMB2_QUERY_INFO_HE);
goto qinf_exit;
}
rsp = (struct smb2_query_info_rsp *)iov.iov_base;
info = (struct smb2_fs_full_size_info *)(4 +
le16_to_cpu(rsp->OutputBufferOffset) + (char *)&rsp->hdr);
rc = validate_buf(le16_to_cpu(rsp->OutputBufferOffset),
le32_to_cpu(rsp->OutputBufferLength), &rsp->hdr,
sizeof(struct smb2_fs_full_size_info));
if (!rc)
copy_fs_info_to_kstatfs(info, fsdata);
qinf_exit:
free_rsp_buf(resp_buftype, iov.iov_base);
return rc;
}
int
smb2_lockv(const unsigned int xid, struct cifs_tcon *tcon,
const __u64 persist_fid, const __u64 volatile_fid, const __u32 pid,
const __u32 num_lock, struct smb2_lock_element *buf)
{
int rc = 0;
struct smb2_lock_req *req = NULL;
struct kvec iov[2];
int resp_buf_type;
unsigned int count;
cFYI(1, "smb2_lockv num lock %d", num_lock);
rc = small_smb2_init(SMB2_LOCK, tcon, (void **) &req);
if (rc)
return rc;
req->hdr.ProcessId = cpu_to_le32(pid);
req->LockCount = cpu_to_le16(num_lock);
req->PersistentFileId = persist_fid;
req->VolatileFileId = volatile_fid;
count = num_lock * sizeof(struct smb2_lock_element);
inc_rfc1001_len(req, count - sizeof(struct smb2_lock_element));
iov[0].iov_base = (char *)req;
iov[0].iov_len = get_rfc1002_length(req) + 4 - count;
iov[1].iov_base = (char *)buf;
iov[1].iov_len = count;
cifs_stats_inc(&tcon->stats.cifs_stats.num_locks);
rc = SendReceive2(xid, tcon->ses, iov, 2, &resp_buf_type, CIFS_NO_RESP);
if (rc) {
cFYI(1, "Send error in smb2_lockv = %d", rc);
cifs_stats_fail_inc(tcon, SMB2_LOCK_HE);
}
return rc;
}
int
SMB2_lock(const unsigned int xid, struct cifs_tcon *tcon,
const __u64 persist_fid, const __u64 volatile_fid, const __u32 pid,
const __u64 length, const __u64 offset, const __u32 lock_flags,
const bool wait)
{
struct smb2_lock_element lock;
lock.Offset = cpu_to_le64(offset);
lock.Length = cpu_to_le64(length);
lock.Flags = cpu_to_le32(lock_flags);
if (!wait && lock_flags != SMB2_LOCKFLAG_UNLOCK)
lock.Flags |= cpu_to_le32(SMB2_LOCKFLAG_FAIL_IMMEDIATELY);
return smb2_lockv(xid, tcon, persist_fid, volatile_fid, pid, 1, &lock);
}
int
SMB2_lease_break(const unsigned int xid, struct cifs_tcon *tcon,
__u8 *lease_key, const __le32 lease_state)
{
int rc;
struct smb2_lease_ack *req = NULL;
cFYI(1, "SMB2_lease_break");
rc = small_smb2_init(SMB2_OPLOCK_BREAK, tcon, (void **) &req);
if (rc)
return rc;
req->hdr.CreditRequest = cpu_to_le16(1);
req->StructureSize = cpu_to_le16(36);
inc_rfc1001_len(req, 12);
memcpy(req->LeaseKey, lease_key, 16);
req->LeaseState = lease_state;
rc = SendReceiveNoRsp(xid, tcon->ses, (char *) req, CIFS_OBREAK_OP);
if (rc) {
cifs_stats_fail_inc(tcon, SMB2_OPLOCK_BREAK_HE);
cFYI(1, "Send error in Lease Break = %d", rc);
}
return rc;
}
