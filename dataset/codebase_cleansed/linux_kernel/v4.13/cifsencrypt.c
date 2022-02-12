static int
cifs_crypto_shash_md5_allocate(struct TCP_Server_Info *server)
{
int rc;
unsigned int size;
if (server->secmech.sdescmd5 != NULL)
return 0;
server->secmech.md5 = crypto_alloc_shash("md5", 0, 0);
if (IS_ERR(server->secmech.md5)) {
cifs_dbg(VFS, "could not allocate crypto md5\n");
rc = PTR_ERR(server->secmech.md5);
server->secmech.md5 = NULL;
return rc;
}
size = sizeof(struct shash_desc) +
crypto_shash_descsize(server->secmech.md5);
server->secmech.sdescmd5 = kmalloc(size, GFP_KERNEL);
if (!server->secmech.sdescmd5) {
crypto_free_shash(server->secmech.md5);
server->secmech.md5 = NULL;
return -ENOMEM;
}
server->secmech.sdescmd5->shash.tfm = server->secmech.md5;
server->secmech.sdescmd5->shash.flags = 0x0;
return 0;
}
int __cifs_calc_signature(struct smb_rqst *rqst,
struct TCP_Server_Info *server, char *signature,
struct shash_desc *shash)
{
int i;
int rc;
struct kvec *iov = rqst->rq_iov;
int n_vec = rqst->rq_nvec;
if (n_vec < 2 || iov[0].iov_len != 4)
return -EIO;
for (i = 1; i < n_vec; i++) {
if (iov[i].iov_len == 0)
continue;
if (iov[i].iov_base == NULL) {
cifs_dbg(VFS, "null iovec entry\n");
return -EIO;
}
if (i == 1 && iov[1].iov_len <= 4)
break;
rc = crypto_shash_update(shash,
iov[i].iov_base, iov[i].iov_len);
if (rc) {
cifs_dbg(VFS, "%s: Could not update with payload\n",
__func__);
return rc;
}
}
for (i = 0; i < rqst->rq_npages; i++) {
void *kaddr = kmap(rqst->rq_pages[i]);
size_t len = rqst->rq_pagesz;
if (i == rqst->rq_npages - 1)
len = rqst->rq_tailsz;
crypto_shash_update(shash, kaddr, len);
kunmap(rqst->rq_pages[i]);
}
rc = crypto_shash_final(shash, signature);
if (rc)
cifs_dbg(VFS, "%s: Could not generate hash\n", __func__);
return rc;
}
static int cifs_calc_signature(struct smb_rqst *rqst,
struct TCP_Server_Info *server, char *signature)
{
int rc;
if (!rqst->rq_iov || !signature || !server)
return -EINVAL;
if (!server->secmech.sdescmd5) {
rc = cifs_crypto_shash_md5_allocate(server);
if (rc) {
cifs_dbg(VFS, "%s: Can't alloc md5 crypto\n", __func__);
return -1;
}
}
rc = crypto_shash_init(&server->secmech.sdescmd5->shash);
if (rc) {
cifs_dbg(VFS, "%s: Could not init md5\n", __func__);
return rc;
}
rc = crypto_shash_update(&server->secmech.sdescmd5->shash,
server->session_key.response, server->session_key.len);
if (rc) {
cifs_dbg(VFS, "%s: Could not update with response\n", __func__);
return rc;
}
return __cifs_calc_signature(rqst, server, signature,
&server->secmech.sdescmd5->shash);
}
int cifs_sign_rqst(struct smb_rqst *rqst, struct TCP_Server_Info *server,
__u32 *pexpected_response_sequence_number)
{
int rc = 0;
char smb_signature[20];
struct smb_hdr *cifs_pdu = (struct smb_hdr *)rqst->rq_iov[0].iov_base;
if (rqst->rq_iov[0].iov_len != 4 ||
rqst->rq_iov[0].iov_base + 4 != rqst->rq_iov[1].iov_base)
return -EIO;
if ((cifs_pdu == NULL) || (server == NULL))
return -EINVAL;
if (!(cifs_pdu->Flags2 & SMBFLG2_SECURITY_SIGNATURE) ||
server->tcpStatus == CifsNeedNegotiate)
return rc;
if (!server->session_estab) {
memcpy(cifs_pdu->Signature.SecuritySignature, "BSRSPYL", 8);
return rc;
}
cifs_pdu->Signature.Sequence.SequenceNumber =
cpu_to_le32(server->sequence_number);
cifs_pdu->Signature.Sequence.Reserved = 0;
*pexpected_response_sequence_number = ++server->sequence_number;
++server->sequence_number;
rc = cifs_calc_signature(rqst, server, smb_signature);
if (rc)
memset(cifs_pdu->Signature.SecuritySignature, 0, 8);
else
memcpy(cifs_pdu->Signature.SecuritySignature, smb_signature, 8);
return rc;
}
int cifs_sign_smbv(struct kvec *iov, int n_vec, struct TCP_Server_Info *server,
__u32 *pexpected_response_sequence)
{
struct smb_rqst rqst = { .rq_iov = iov,
.rq_nvec = n_vec };
return cifs_sign_rqst(&rqst, server, pexpected_response_sequence);
}
int cifs_sign_smb(struct smb_hdr *cifs_pdu, struct TCP_Server_Info *server,
__u32 *pexpected_response_sequence_number)
{
struct kvec iov[2];
iov[0].iov_base = cifs_pdu;
iov[0].iov_len = 4;
iov[1].iov_base = (char *)cifs_pdu + 4;
iov[1].iov_len = be32_to_cpu(cifs_pdu->smb_buf_length);
return cifs_sign_smbv(iov, 2, server,
pexpected_response_sequence_number);
}
int cifs_verify_signature(struct smb_rqst *rqst,
struct TCP_Server_Info *server,
__u32 expected_sequence_number)
{
unsigned int rc;
char server_response_sig[8];
char what_we_think_sig_should_be[20];
struct smb_hdr *cifs_pdu = (struct smb_hdr *)rqst->rq_iov[0].iov_base;
if (rqst->rq_iov[0].iov_len != 4 ||
rqst->rq_iov[0].iov_base + 4 != rqst->rq_iov[1].iov_base)
return -EIO;
if (cifs_pdu == NULL || server == NULL)
return -EINVAL;
if (!server->session_estab)
return 0;
if (cifs_pdu->Command == SMB_COM_LOCKING_ANDX) {
struct smb_com_lock_req *pSMB =
(struct smb_com_lock_req *)cifs_pdu;
if (pSMB->LockType & LOCKING_ANDX_OPLOCK_RELEASE)
return 0;
}
if (memcmp(cifs_pdu->Signature.SecuritySignature, "BSRSPYL ", 8) == 0)
cifs_dbg(FYI, "dummy signature received for smb command 0x%x\n",
cifs_pdu->Command);
memcpy(server_response_sig, cifs_pdu->Signature.SecuritySignature, 8);
cifs_pdu->Signature.Sequence.SequenceNumber =
cpu_to_le32(expected_sequence_number);
cifs_pdu->Signature.Sequence.Reserved = 0;
mutex_lock(&server->srv_mutex);
rc = cifs_calc_signature(rqst, server, what_we_think_sig_should_be);
mutex_unlock(&server->srv_mutex);
if (rc)
return rc;
if (memcmp(server_response_sig, what_we_think_sig_should_be, 8))
return -EACCES;
else
return 0;
}
int setup_ntlm_response(struct cifs_ses *ses, const struct nls_table *nls_cp)
{
int rc = 0;
unsigned int temp_len = CIFS_SESS_KEY_SIZE + CIFS_AUTH_RESP_SIZE;
char temp_key[CIFS_SESS_KEY_SIZE];
if (!ses)
return -EINVAL;
ses->auth_key.response = kmalloc(temp_len, GFP_KERNEL);
if (!ses->auth_key.response)
return -ENOMEM;
ses->auth_key.len = temp_len;
rc = SMBNTencrypt(ses->password, ses->server->cryptkey,
ses->auth_key.response + CIFS_SESS_KEY_SIZE, nls_cp);
if (rc) {
cifs_dbg(FYI, "%s Can't generate NTLM response, error: %d\n",
__func__, rc);
return rc;
}
rc = E_md4hash(ses->password, temp_key, nls_cp);
if (rc) {
cifs_dbg(FYI, "%s Can't generate NT hash, error: %d\n",
__func__, rc);
return rc;
}
rc = mdfour(ses->auth_key.response, temp_key, CIFS_SESS_KEY_SIZE);
if (rc)
cifs_dbg(FYI, "%s Can't generate NTLM session key, error: %d\n",
__func__, rc);
return rc;
}
int calc_lanman_hash(const char *password, const char *cryptkey, bool encrypt,
char *lnm_session_key)
{
int i;
int rc;
char password_with_pad[CIFS_ENCPWD_SIZE];
memset(password_with_pad, 0, CIFS_ENCPWD_SIZE);
if (password)
strncpy(password_with_pad, password, CIFS_ENCPWD_SIZE);
if (!encrypt && global_secflags & CIFSSEC_MAY_PLNTXT) {
memcpy(lnm_session_key, password_with_pad,
CIFS_ENCPWD_SIZE);
return 0;
}
for (i = 0; i < CIFS_ENCPWD_SIZE; i++)
password_with_pad[i] = toupper(password_with_pad[i]);
rc = SMBencrypt(password_with_pad, cryptkey, lnm_session_key);
return rc;
}
static int
build_avpair_blob(struct cifs_ses *ses, const struct nls_table *nls_cp)
{
unsigned int dlen;
unsigned int size = 2 * sizeof(struct ntlmssp2_name);
char *defdmname = "WORKGROUP";
unsigned char *blobptr;
struct ntlmssp2_name *attrptr;
if (!ses->domainName) {
ses->domainName = kstrdup(defdmname, GFP_KERNEL);
if (!ses->domainName)
return -ENOMEM;
}
dlen = strlen(ses->domainName);
ses->auth_key.len = size + 2 * dlen;
ses->auth_key.response = kzalloc(ses->auth_key.len, GFP_KERNEL);
if (!ses->auth_key.response) {
ses->auth_key.len = 0;
return -ENOMEM;
}
blobptr = ses->auth_key.response;
attrptr = (struct ntlmssp2_name *) blobptr;
attrptr->type = cpu_to_le16(NTLMSSP_AV_NB_DOMAIN_NAME);
attrptr->length = cpu_to_le16(2 * dlen);
blobptr = (unsigned char *)attrptr + sizeof(struct ntlmssp2_name);
cifs_strtoUTF16((__le16 *)blobptr, ses->domainName, dlen, nls_cp);
return 0;
}
static int
find_domain_name(struct cifs_ses *ses, const struct nls_table *nls_cp)
{
unsigned int attrsize;
unsigned int type;
unsigned int onesize = sizeof(struct ntlmssp2_name);
unsigned char *blobptr;
unsigned char *blobend;
struct ntlmssp2_name *attrptr;
if (!ses->auth_key.len || !ses->auth_key.response)
return 0;
blobptr = ses->auth_key.response;
blobend = blobptr + ses->auth_key.len;
while (blobptr + onesize < blobend) {
attrptr = (struct ntlmssp2_name *) blobptr;
type = le16_to_cpu(attrptr->type);
if (type == NTLMSSP_AV_EOL)
break;
blobptr += 2;
attrsize = le16_to_cpu(attrptr->length);
blobptr += 2;
if (blobptr + attrsize > blobend)
break;
if (type == NTLMSSP_AV_NB_DOMAIN_NAME) {
if (!attrsize || attrsize >= CIFS_MAX_DOMAINNAME_LEN)
break;
if (!ses->domainName) {
ses->domainName =
kmalloc(attrsize + 1, GFP_KERNEL);
if (!ses->domainName)
return -ENOMEM;
cifs_from_utf16(ses->domainName,
(__le16 *)blobptr, attrsize, attrsize,
nls_cp, NO_MAP_UNI_RSVD);
break;
}
}
blobptr += attrsize;
}
return 0;
}
static __le64
find_timestamp(struct cifs_ses *ses)
{
unsigned int attrsize;
unsigned int type;
unsigned int onesize = sizeof(struct ntlmssp2_name);
unsigned char *blobptr;
unsigned char *blobend;
struct ntlmssp2_name *attrptr;
struct timespec ts;
if (!ses->auth_key.len || !ses->auth_key.response)
return 0;
blobptr = ses->auth_key.response;
blobend = blobptr + ses->auth_key.len;
while (blobptr + onesize < blobend) {
attrptr = (struct ntlmssp2_name *) blobptr;
type = le16_to_cpu(attrptr->type);
if (type == NTLMSSP_AV_EOL)
break;
blobptr += 2;
attrsize = le16_to_cpu(attrptr->length);
blobptr += 2;
if (blobptr + attrsize > blobend)
break;
if (type == NTLMSSP_AV_TIMESTAMP) {
if (attrsize == sizeof(u64))
return *((__le64 *)blobptr);
}
blobptr += attrsize;
}
ktime_get_real_ts(&ts);
return cpu_to_le64(cifs_UnixTimeToNT(ts));
}
static int calc_ntlmv2_hash(struct cifs_ses *ses, char *ntlmv2_hash,
const struct nls_table *nls_cp)
{
int rc = 0;
int len;
char nt_hash[CIFS_NTHASH_SIZE];
__le16 *user;
wchar_t *domain;
wchar_t *server;
if (!ses->server->secmech.sdeschmacmd5) {
cifs_dbg(VFS, "%s: can't generate ntlmv2 hash\n", __func__);
return -1;
}
E_md4hash(ses->password, nt_hash, nls_cp);
rc = crypto_shash_setkey(ses->server->secmech.hmacmd5, nt_hash,
CIFS_NTHASH_SIZE);
if (rc) {
cifs_dbg(VFS, "%s: Could not set NT Hash as a key\n", __func__);
return rc;
}
rc = crypto_shash_init(&ses->server->secmech.sdeschmacmd5->shash);
if (rc) {
cifs_dbg(VFS, "%s: could not init hmacmd5\n", __func__);
return rc;
}
len = ses->user_name ? strlen(ses->user_name) : 0;
user = kmalloc(2 + (len * 2), GFP_KERNEL);
if (user == NULL) {
rc = -ENOMEM;
return rc;
}
if (len) {
len = cifs_strtoUTF16(user, ses->user_name, len, nls_cp);
UniStrupr(user);
} else {
memset(user, '\0', 2);
}
rc = crypto_shash_update(&ses->server->secmech.sdeschmacmd5->shash,
(char *)user, 2 * len);
kfree(user);
if (rc) {
cifs_dbg(VFS, "%s: Could not update with user\n", __func__);
return rc;
}
if (ses->domainName) {
len = strlen(ses->domainName);
domain = kmalloc(2 + (len * 2), GFP_KERNEL);
if (domain == NULL) {
rc = -ENOMEM;
return rc;
}
len = cifs_strtoUTF16((__le16 *)domain, ses->domainName, len,
nls_cp);
rc =
crypto_shash_update(&ses->server->secmech.sdeschmacmd5->shash,
(char *)domain, 2 * len);
kfree(domain);
if (rc) {
cifs_dbg(VFS, "%s: Could not update with domain\n",
__func__);
return rc;
}
} else {
len = strlen(ses->serverName);
server = kmalloc(2 + (len * 2), GFP_KERNEL);
if (server == NULL) {
rc = -ENOMEM;
return rc;
}
len = cifs_strtoUTF16((__le16 *)server, ses->serverName, len,
nls_cp);
rc =
crypto_shash_update(&ses->server->secmech.sdeschmacmd5->shash,
(char *)server, 2 * len);
kfree(server);
if (rc) {
cifs_dbg(VFS, "%s: Could not update with server\n",
__func__);
return rc;
}
}
rc = crypto_shash_final(&ses->server->secmech.sdeschmacmd5->shash,
ntlmv2_hash);
if (rc)
cifs_dbg(VFS, "%s: Could not generate md5 hash\n", __func__);
return rc;
}
static int
CalcNTLMv2_response(const struct cifs_ses *ses, char *ntlmv2_hash)
{
int rc;
struct ntlmv2_resp *ntlmv2 = (struct ntlmv2_resp *)
(ses->auth_key.response + CIFS_SESS_KEY_SIZE);
unsigned int hash_len;
hash_len = ses->auth_key.len - (CIFS_SESS_KEY_SIZE +
offsetof(struct ntlmv2_resp, challenge.key[0]));
if (!ses->server->secmech.sdeschmacmd5) {
cifs_dbg(VFS, "%s: can't generate ntlmv2 hash\n", __func__);
return -1;
}
rc = crypto_shash_setkey(ses->server->secmech.hmacmd5,
ntlmv2_hash, CIFS_HMAC_MD5_HASH_SIZE);
if (rc) {
cifs_dbg(VFS, "%s: Could not set NTLMV2 Hash as a key\n",
__func__);
return rc;
}
rc = crypto_shash_init(&ses->server->secmech.sdeschmacmd5->shash);
if (rc) {
cifs_dbg(VFS, "%s: could not init hmacmd5\n", __func__);
return rc;
}
if (ses->server->negflavor == CIFS_NEGFLAVOR_EXTENDED)
memcpy(ntlmv2->challenge.key,
ses->ntlmssp->cryptkey, CIFS_SERVER_CHALLENGE_SIZE);
else
memcpy(ntlmv2->challenge.key,
ses->server->cryptkey, CIFS_SERVER_CHALLENGE_SIZE);
rc = crypto_shash_update(&ses->server->secmech.sdeschmacmd5->shash,
ntlmv2->challenge.key, hash_len);
if (rc) {
cifs_dbg(VFS, "%s: Could not update with response\n", __func__);
return rc;
}
rc = crypto_shash_final(&ses->server->secmech.sdeschmacmd5->shash,
ntlmv2->ntlmv2_hash);
if (rc)
cifs_dbg(VFS, "%s: Could not generate md5 hash\n", __func__);
return rc;
}
static int crypto_hmacmd5_alloc(struct TCP_Server_Info *server)
{
int rc;
unsigned int size;
if (server->secmech.sdeschmacmd5)
return 0;
server->secmech.hmacmd5 = crypto_alloc_shash("hmac(md5)", 0, 0);
if (IS_ERR(server->secmech.hmacmd5)) {
cifs_dbg(VFS, "could not allocate crypto hmacmd5\n");
rc = PTR_ERR(server->secmech.hmacmd5);
server->secmech.hmacmd5 = NULL;
return rc;
}
size = sizeof(struct shash_desc) +
crypto_shash_descsize(server->secmech.hmacmd5);
server->secmech.sdeschmacmd5 = kmalloc(size, GFP_KERNEL);
if (!server->secmech.sdeschmacmd5) {
crypto_free_shash(server->secmech.hmacmd5);
server->secmech.hmacmd5 = NULL;
return -ENOMEM;
}
server->secmech.sdeschmacmd5->shash.tfm = server->secmech.hmacmd5;
server->secmech.sdeschmacmd5->shash.flags = 0x0;
return 0;
}
int
setup_ntlmv2_rsp(struct cifs_ses *ses, const struct nls_table *nls_cp)
{
int rc;
int baselen;
unsigned int tilen;
struct ntlmv2_resp *ntlmv2;
char ntlmv2_hash[16];
unsigned char *tiblob = NULL;
__le64 rsp_timestamp;
if (ses->server->negflavor == CIFS_NEGFLAVOR_EXTENDED) {
if (!ses->domainName) {
if (ses->domainAuto) {
rc = find_domain_name(ses, nls_cp);
if (rc) {
cifs_dbg(VFS, "error %d finding domain name\n",
rc);
goto setup_ntlmv2_rsp_ret;
}
} else {
ses->domainName = kstrdup("", GFP_KERNEL);
}
}
} else {
rc = build_avpair_blob(ses, nls_cp);
if (rc) {
cifs_dbg(VFS, "error %d building av pair blob\n", rc);
goto setup_ntlmv2_rsp_ret;
}
}
rsp_timestamp = find_timestamp(ses);
baselen = CIFS_SESS_KEY_SIZE + sizeof(struct ntlmv2_resp);
tilen = ses->auth_key.len;
tiblob = ses->auth_key.response;
ses->auth_key.response = kmalloc(baselen + tilen, GFP_KERNEL);
if (!ses->auth_key.response) {
rc = -ENOMEM;
ses->auth_key.len = 0;
goto setup_ntlmv2_rsp_ret;
}
ses->auth_key.len += baselen;
ntlmv2 = (struct ntlmv2_resp *)
(ses->auth_key.response + CIFS_SESS_KEY_SIZE);
ntlmv2->blob_signature = cpu_to_le32(0x00000101);
ntlmv2->reserved = 0;
ntlmv2->time = rsp_timestamp;
get_random_bytes(&ntlmv2->client_chal, sizeof(ntlmv2->client_chal));
ntlmv2->reserved2 = 0;
memcpy(ses->auth_key.response + baselen, tiblob, tilen);
mutex_lock(&ses->server->srv_mutex);
rc = crypto_hmacmd5_alloc(ses->server);
if (rc) {
cifs_dbg(VFS, "could not crypto alloc hmacmd5 rc %d\n", rc);
goto unlock;
}
rc = calc_ntlmv2_hash(ses, ntlmv2_hash, nls_cp);
if (rc) {
cifs_dbg(VFS, "could not get v2 hash rc %d\n", rc);
goto unlock;
}
rc = CalcNTLMv2_response(ses, ntlmv2_hash);
if (rc) {
cifs_dbg(VFS, "Could not calculate CR1 rc: %d\n", rc);
goto unlock;
}
rc = crypto_shash_setkey(ses->server->secmech.hmacmd5,
ntlmv2_hash, CIFS_HMAC_MD5_HASH_SIZE);
if (rc) {
cifs_dbg(VFS, "%s: Could not set NTLMV2 Hash as a key\n",
__func__);
goto unlock;
}
rc = crypto_shash_init(&ses->server->secmech.sdeschmacmd5->shash);
if (rc) {
cifs_dbg(VFS, "%s: Could not init hmacmd5\n", __func__);
goto unlock;
}
rc = crypto_shash_update(&ses->server->secmech.sdeschmacmd5->shash,
ntlmv2->ntlmv2_hash,
CIFS_HMAC_MD5_HASH_SIZE);
if (rc) {
cifs_dbg(VFS, "%s: Could not update with response\n", __func__);
goto unlock;
}
rc = crypto_shash_final(&ses->server->secmech.sdeschmacmd5->shash,
ses->auth_key.response);
if (rc)
cifs_dbg(VFS, "%s: Could not generate md5 hash\n", __func__);
unlock:
mutex_unlock(&ses->server->srv_mutex);
setup_ntlmv2_rsp_ret:
kfree(tiblob);
return rc;
}
int
calc_seckey(struct cifs_ses *ses)
{
int rc;
struct crypto_skcipher *tfm_arc4;
struct scatterlist sgin, sgout;
struct skcipher_request *req;
unsigned char *sec_key;
sec_key = kmalloc(CIFS_SESS_KEY_SIZE, GFP_KERNEL);
if (sec_key == NULL)
return -ENOMEM;
get_random_bytes(sec_key, CIFS_SESS_KEY_SIZE);
tfm_arc4 = crypto_alloc_skcipher("ecb(arc4)", 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm_arc4)) {
rc = PTR_ERR(tfm_arc4);
cifs_dbg(VFS, "could not allocate crypto API arc4\n");
goto out;
}
rc = crypto_skcipher_setkey(tfm_arc4, ses->auth_key.response,
CIFS_SESS_KEY_SIZE);
if (rc) {
cifs_dbg(VFS, "%s: Could not set response as a key\n",
__func__);
goto out_free_cipher;
}
req = skcipher_request_alloc(tfm_arc4, GFP_KERNEL);
if (!req) {
rc = -ENOMEM;
cifs_dbg(VFS, "could not allocate crypto API arc4 request\n");
goto out_free_cipher;
}
sg_init_one(&sgin, sec_key, CIFS_SESS_KEY_SIZE);
sg_init_one(&sgout, ses->ntlmssp->ciphertext, CIFS_CPHTXT_SIZE);
skcipher_request_set_callback(req, 0, NULL, NULL);
skcipher_request_set_crypt(req, &sgin, &sgout, CIFS_CPHTXT_SIZE, NULL);
rc = crypto_skcipher_encrypt(req);
skcipher_request_free(req);
if (rc) {
cifs_dbg(VFS, "could not encrypt session key rc: %d\n", rc);
goto out_free_cipher;
}
memcpy(ses->auth_key.response, sec_key, CIFS_SESS_KEY_SIZE);
ses->auth_key.len = CIFS_SESS_KEY_SIZE;
out_free_cipher:
crypto_free_skcipher(tfm_arc4);
out:
kfree(sec_key);
return rc;
}
void
cifs_crypto_secmech_release(struct TCP_Server_Info *server)
{
if (server->secmech.cmacaes) {
crypto_free_shash(server->secmech.cmacaes);
server->secmech.cmacaes = NULL;
}
if (server->secmech.hmacsha256) {
crypto_free_shash(server->secmech.hmacsha256);
server->secmech.hmacsha256 = NULL;
}
if (server->secmech.md5) {
crypto_free_shash(server->secmech.md5);
server->secmech.md5 = NULL;
}
if (server->secmech.hmacmd5) {
crypto_free_shash(server->secmech.hmacmd5);
server->secmech.hmacmd5 = NULL;
}
if (server->secmech.ccmaesencrypt) {
crypto_free_aead(server->secmech.ccmaesencrypt);
server->secmech.ccmaesencrypt = NULL;
}
if (server->secmech.ccmaesdecrypt) {
crypto_free_aead(server->secmech.ccmaesdecrypt);
server->secmech.ccmaesdecrypt = NULL;
}
kfree(server->secmech.sdesccmacaes);
server->secmech.sdesccmacaes = NULL;
kfree(server->secmech.sdeschmacsha256);
server->secmech.sdeschmacsha256 = NULL;
kfree(server->secmech.sdeschmacmd5);
server->secmech.sdeschmacmd5 = NULL;
kfree(server->secmech.sdescmd5);
server->secmech.sdescmd5 = NULL;
}
