int
smb2_calc_signature(struct smb_rqst *rqst, struct TCP_Server_Info *server)
{
int i, rc;
unsigned char smb2_signature[SMB2_HMACSHA256_SIZE];
unsigned char *sigptr = smb2_signature;
struct kvec *iov = rqst->rq_iov;
int n_vec = rqst->rq_nvec;
struct smb2_hdr *smb2_pdu = (struct smb2_hdr *)iov[0].iov_base;
memset(smb2_signature, 0x0, SMB2_HMACSHA256_SIZE);
memset(smb2_pdu->Signature, 0x0, SMB2_SIGNATURE_SIZE);
rc = crypto_shash_setkey(server->secmech.hmacsha256,
server->session_key.response, SMB2_NTLMV2_SESSKEY_SIZE);
if (rc) {
cERROR(1, "%s: Could not update with response\n", __func__);
return rc;
}
rc = crypto_shash_init(&server->secmech.sdeschmacsha256->shash);
if (rc) {
cERROR(1, "%s: Could not init md5\n", __func__);
return rc;
}
for (i = 0; i < n_vec; i++) {
if (iov[i].iov_len == 0)
continue;
if (iov[i].iov_base == NULL) {
cERROR(1, "null iovec entry");
return -EIO;
}
if (i == 0) {
if (iov[0].iov_len <= 8)
break;
rc =
crypto_shash_update(
&server->secmech.sdeschmacsha256->shash,
iov[i].iov_base + 4, iov[i].iov_len - 4);
} else {
rc =
crypto_shash_update(
&server->secmech.sdeschmacsha256->shash,
iov[i].iov_base, iov[i].iov_len);
}
if (rc) {
cERROR(1, "%s: Could not update with payload\n",
__func__);
return rc;
}
}
for (i = 0; i < rqst->rq_npages; i++) {
struct kvec p_iov;
cifs_rqst_page_to_kvec(rqst, i, &p_iov);
crypto_shash_update(&server->secmech.sdeschmacsha256->shash,
p_iov.iov_base, p_iov.iov_len);
kunmap(rqst->rq_pages[i]);
}
rc = crypto_shash_final(&server->secmech.sdeschmacsha256->shash,
sigptr);
if (rc)
cERROR(1, "%s: Could not generate sha256 hash\n", __func__);
memcpy(smb2_pdu->Signature, sigptr, SMB2_SIGNATURE_SIZE);
return rc;
}
int
smb3_calc_signature(struct smb_rqst *rqst, struct TCP_Server_Info *server)
{
cFYI(1, "smb3 signatures not supported yet");
return -EOPNOTSUPP;
}
static int
smb2_sign_rqst(struct smb_rqst *rqst, struct TCP_Server_Info *server)
{
int rc = 0;
struct smb2_hdr *smb2_pdu = rqst->rq_iov[0].iov_base;
if (!(smb2_pdu->Flags & SMB2_FLAGS_SIGNED) ||
server->tcpStatus == CifsNeedNegotiate)
return rc;
if (!server->session_estab) {
strncpy(smb2_pdu->Signature, "BSRSPYL", 8);
return rc;
}
rc = server->ops->calc_signature(rqst, server);
return rc;
}
int
smb2_verify_signature(struct smb_rqst *rqst, struct TCP_Server_Info *server)
{
unsigned int rc;
char server_response_sig[16];
struct smb2_hdr *smb2_pdu = (struct smb2_hdr *)rqst->rq_iov[0].iov_base;
if ((smb2_pdu->Command == SMB2_NEGOTIATE) ||
(smb2_pdu->Command == SMB2_OPLOCK_BREAK) ||
(!server->session_estab))
return 0;
if (memcmp(smb2_pdu->Signature, "BSRSPYL ", 8) == 0)
cFYI(1, "dummy signature received for smb command 0x%x",
smb2_pdu->Command);
memcpy(server_response_sig, smb2_pdu->Signature, SMB2_SIGNATURE_SIZE);
memset(smb2_pdu->Signature, 0, SMB2_SIGNATURE_SIZE);
mutex_lock(&server->srv_mutex);
rc = server->ops->calc_signature(rqst, server);
mutex_unlock(&server->srv_mutex);
if (rc)
return rc;
if (memcmp(server_response_sig, smb2_pdu->Signature,
SMB2_SIGNATURE_SIZE))
return -EACCES;
else
return 0;
}
static inline void
smb2_seq_num_into_buf(struct TCP_Server_Info *server, struct smb2_hdr *hdr)
{
hdr->MessageId = get_next_mid(server);
}
static struct mid_q_entry *
smb2_mid_entry_alloc(const struct smb2_hdr *smb_buffer,
struct TCP_Server_Info *server)
{
struct mid_q_entry *temp;
if (server == NULL) {
cERROR(1, "Null TCP session in smb2_mid_entry_alloc");
return NULL;
}
temp = mempool_alloc(cifs_mid_poolp, GFP_NOFS);
if (temp == NULL)
return temp;
else {
memset(temp, 0, sizeof(struct mid_q_entry));
temp->mid = smb_buffer->MessageId;
temp->pid = current->pid;
temp->command = smb_buffer->Command;
temp->when_alloc = jiffies;
temp->server = server;
temp->callback = cifs_wake_up_task;
temp->callback_data = current;
}
atomic_inc(&midCount);
temp->mid_state = MID_REQUEST_ALLOCATED;
return temp;
}
static int
smb2_get_mid_entry(struct cifs_ses *ses, struct smb2_hdr *buf,
struct mid_q_entry **mid)
{
if (ses->server->tcpStatus == CifsExiting)
return -ENOENT;
if (ses->server->tcpStatus == CifsNeedReconnect) {
cFYI(1, "tcp session dead - return to caller to retry");
return -EAGAIN;
}
if (ses->status != CifsGood) {
if ((buf->Command != SMB2_SESSION_SETUP) &&
(buf->Command != SMB2_NEGOTIATE))
return -EAGAIN;
}
*mid = smb2_mid_entry_alloc(buf, ses->server);
if (*mid == NULL)
return -ENOMEM;
spin_lock(&GlobalMid_Lock);
list_add_tail(&(*mid)->qhead, &ses->server->pending_mid_q);
spin_unlock(&GlobalMid_Lock);
return 0;
}
int
smb2_check_receive(struct mid_q_entry *mid, struct TCP_Server_Info *server,
bool log_error)
{
unsigned int len = get_rfc1002_length(mid->resp_buf);
struct kvec iov;
struct smb_rqst rqst = { .rq_iov = &iov,
.rq_nvec = 1 };
iov.iov_base = (char *)mid->resp_buf;
iov.iov_len = get_rfc1002_length(mid->resp_buf) + 4;
dump_smb(mid->resp_buf, min_t(u32, 80, len));
if ((len > 24) &&
(server->sec_mode & (SECMODE_SIGN_REQUIRED|SECMODE_SIGN_ENABLED))) {
int rc;
rc = smb2_verify_signature(&rqst, server);
if (rc)
cERROR(1, "SMB signature verification returned error = "
"%d", rc);
}
return map_smb2_to_linux_error(mid->resp_buf, log_error);
}
struct mid_q_entry *
smb2_setup_request(struct cifs_ses *ses, struct smb_rqst *rqst)
{
int rc;
struct smb2_hdr *hdr = (struct smb2_hdr *)rqst->rq_iov[0].iov_base;
struct mid_q_entry *mid;
smb2_seq_num_into_buf(ses->server, hdr);
rc = smb2_get_mid_entry(ses, hdr, &mid);
if (rc)
return ERR_PTR(rc);
rc = smb2_sign_rqst(rqst, ses->server);
if (rc) {
cifs_delete_mid(mid);
return ERR_PTR(rc);
}
return mid;
}
struct mid_q_entry *
smb2_setup_async_request(struct TCP_Server_Info *server, struct smb_rqst *rqst)
{
int rc;
struct smb2_hdr *hdr = (struct smb2_hdr *)rqst->rq_iov[0].iov_base;
struct mid_q_entry *mid;
smb2_seq_num_into_buf(server, hdr);
mid = smb2_mid_entry_alloc(hdr, server);
if (mid == NULL)
return ERR_PTR(-ENOMEM);
rc = smb2_sign_rqst(rqst, server);
if (rc) {
DeleteMidQEntry(mid);
return ERR_PTR(rc);
}
return mid;
}
