static __u32 cifs_ssetup_hdr(struct cifs_ses *ses, SESSION_SETUP_ANDX *pSMB)
{
__u32 capabilities = 0;
pSMB->req.AndXCommand = 0xFF;
pSMB->req.MaxBufferSize = cpu_to_le16(min_t(u32,
CIFSMaxBufSize + MAX_CIFS_HDR_SIZE - 4,
USHRT_MAX));
pSMB->req.MaxMpxCount = cpu_to_le16(ses->server->maxReq);
pSMB->req.VcNumber = __constant_cpu_to_le16(1);
capabilities = CAP_LARGE_FILES | CAP_NT_SMBS | CAP_LEVEL_II_OPLOCKS |
CAP_LARGE_WRITE_X | CAP_LARGE_READ_X;
if (ses->server->sign)
pSMB->req.hdr.Flags2 |= SMBFLG2_SECURITY_SIGNATURE;
if (ses->capabilities & CAP_UNICODE) {
pSMB->req.hdr.Flags2 |= SMBFLG2_UNICODE;
capabilities |= CAP_UNICODE;
}
if (ses->capabilities & CAP_STATUS32) {
pSMB->req.hdr.Flags2 |= SMBFLG2_ERR_STATUS;
capabilities |= CAP_STATUS32;
}
if (ses->capabilities & CAP_DFS) {
pSMB->req.hdr.Flags2 |= SMBFLG2_DFS;
capabilities |= CAP_DFS;
}
if (ses->capabilities & CAP_UNIX)
capabilities |= CAP_UNIX;
return capabilities;
}
static void
unicode_oslm_strings(char **pbcc_area, const struct nls_table *nls_cp)
{
char *bcc_ptr = *pbcc_area;
int bytes_ret = 0;
bytes_ret = cifs_strtoUTF16((__le16 *)bcc_ptr, "Linux version ", 32,
nls_cp);
bcc_ptr += 2 * bytes_ret;
bytes_ret = cifs_strtoUTF16((__le16 *) bcc_ptr, init_utsname()->release,
32, nls_cp);
bcc_ptr += 2 * bytes_ret;
bcc_ptr += 2;
bytes_ret = cifs_strtoUTF16((__le16 *) bcc_ptr, CIFS_NETWORK_OPSYS,
32, nls_cp);
bcc_ptr += 2 * bytes_ret;
bcc_ptr += 2;
*pbcc_area = bcc_ptr;
}
static void unicode_domain_string(char **pbcc_area, struct cifs_ses *ses,
const struct nls_table *nls_cp)
{
char *bcc_ptr = *pbcc_area;
int bytes_ret = 0;
if (ses->domainName == NULL) {
*bcc_ptr = 0;
*(bcc_ptr+1) = 0;
bytes_ret = 0;
} else
bytes_ret = cifs_strtoUTF16((__le16 *) bcc_ptr, ses->domainName,
CIFS_MAX_DOMAINNAME_LEN, nls_cp);
bcc_ptr += 2 * bytes_ret;
bcc_ptr += 2;
*pbcc_area = bcc_ptr;
}
static void unicode_ssetup_strings(char **pbcc_area, struct cifs_ses *ses,
const struct nls_table *nls_cp)
{
char *bcc_ptr = *pbcc_area;
int bytes_ret = 0;
if (ses->user_name == NULL) {
*bcc_ptr = 0;
*(bcc_ptr+1) = 0;
} else {
bytes_ret = cifs_strtoUTF16((__le16 *) bcc_ptr, ses->user_name,
CIFS_MAX_USERNAME_LEN, nls_cp);
}
bcc_ptr += 2 * bytes_ret;
bcc_ptr += 2;
unicode_domain_string(&bcc_ptr, ses, nls_cp);
unicode_oslm_strings(&bcc_ptr, nls_cp);
*pbcc_area = bcc_ptr;
}
static void ascii_ssetup_strings(char **pbcc_area, struct cifs_ses *ses,
const struct nls_table *nls_cp)
{
char *bcc_ptr = *pbcc_area;
if (ses->user_name != NULL) {
strncpy(bcc_ptr, ses->user_name, CIFS_MAX_USERNAME_LEN);
bcc_ptr += strnlen(ses->user_name, CIFS_MAX_USERNAME_LEN);
}
*bcc_ptr = 0;
bcc_ptr++;
if (ses->domainName != NULL) {
strncpy(bcc_ptr, ses->domainName, CIFS_MAX_DOMAINNAME_LEN);
bcc_ptr += strnlen(ses->domainName, CIFS_MAX_DOMAINNAME_LEN);
}
*bcc_ptr = 0;
bcc_ptr++;
strcpy(bcc_ptr, "Linux version ");
bcc_ptr += strlen("Linux version ");
strcpy(bcc_ptr, init_utsname()->release);
bcc_ptr += strlen(init_utsname()->release) + 1;
strcpy(bcc_ptr, CIFS_NETWORK_OPSYS);
bcc_ptr += strlen(CIFS_NETWORK_OPSYS) + 1;
*pbcc_area = bcc_ptr;
}
static void
decode_unicode_ssetup(char **pbcc_area, int bleft, struct cifs_ses *ses,
const struct nls_table *nls_cp)
{
int len;
char *data = *pbcc_area;
cifs_dbg(FYI, "bleft %d\n", bleft);
kfree(ses->serverOS);
ses->serverOS = cifs_strndup_from_utf16(data, bleft, true, nls_cp);
cifs_dbg(FYI, "serverOS=%s\n", ses->serverOS);
len = (UniStrnlen((wchar_t *) data, bleft / 2) * 2) + 2;
data += len;
bleft -= len;
if (bleft <= 0)
return;
kfree(ses->serverNOS);
ses->serverNOS = cifs_strndup_from_utf16(data, bleft, true, nls_cp);
cifs_dbg(FYI, "serverNOS=%s\n", ses->serverNOS);
len = (UniStrnlen((wchar_t *) data, bleft / 2) * 2) + 2;
data += len;
bleft -= len;
if (bleft <= 0)
return;
kfree(ses->serverDomain);
ses->serverDomain = cifs_strndup_from_utf16(data, bleft, true, nls_cp);
cifs_dbg(FYI, "serverDomain=%s\n", ses->serverDomain);
return;
}
static void decode_ascii_ssetup(char **pbcc_area, __u16 bleft,
struct cifs_ses *ses,
const struct nls_table *nls_cp)
{
int len;
char *bcc_ptr = *pbcc_area;
cifs_dbg(FYI, "decode sessetup ascii. bleft %d\n", bleft);
len = strnlen(bcc_ptr, bleft);
if (len >= bleft)
return;
kfree(ses->serverOS);
ses->serverOS = kzalloc(len + 1, GFP_KERNEL);
if (ses->serverOS)
strncpy(ses->serverOS, bcc_ptr, len);
if (strncmp(ses->serverOS, "OS/2", 4) == 0)
cifs_dbg(FYI, "OS/2 server\n");
bcc_ptr += len + 1;
bleft -= len + 1;
len = strnlen(bcc_ptr, bleft);
if (len >= bleft)
return;
kfree(ses->serverNOS);
ses->serverNOS = kzalloc(len + 1, GFP_KERNEL);
if (ses->serverNOS)
strncpy(ses->serverNOS, bcc_ptr, len);
bcc_ptr += len + 1;
bleft -= len + 1;
len = strnlen(bcc_ptr, bleft);
if (len > bleft)
return;
cifs_dbg(FYI, "ascii: bytes left %d\n", bleft);
}
int decode_ntlmssp_challenge(char *bcc_ptr, int blob_len,
struct cifs_ses *ses)
{
unsigned int tioffset;
unsigned int tilen;
CHALLENGE_MESSAGE *pblob = (CHALLENGE_MESSAGE *)bcc_ptr;
if (blob_len < sizeof(CHALLENGE_MESSAGE)) {
cifs_dbg(VFS, "challenge blob len %d too small\n", blob_len);
return -EINVAL;
}
if (memcmp(pblob->Signature, "NTLMSSP", 8)) {
cifs_dbg(VFS, "blob signature incorrect %s\n",
pblob->Signature);
return -EINVAL;
}
if (pblob->MessageType != NtLmChallenge) {
cifs_dbg(VFS, "Incorrect message type %d\n",
pblob->MessageType);
return -EINVAL;
}
memcpy(ses->ntlmssp->cryptkey, pblob->Challenge, CIFS_CRYPTO_KEY_SIZE);
ses->ntlmssp->server_flags = le32_to_cpu(pblob->NegotiateFlags);
tioffset = le32_to_cpu(pblob->TargetInfoArray.BufferOffset);
tilen = le16_to_cpu(pblob->TargetInfoArray.Length);
if (tioffset > blob_len || tioffset + tilen > blob_len) {
cifs_dbg(VFS, "tioffset + tilen too high %u + %u",
tioffset, tilen);
return -EINVAL;
}
if (tilen) {
ses->auth_key.response = kmemdup(bcc_ptr + tioffset, tilen,
GFP_KERNEL);
if (!ses->auth_key.response) {
cifs_dbg(VFS, "Challenge target info alloc failure");
return -ENOMEM;
}
ses->auth_key.len = tilen;
}
return 0;
}
void build_ntlmssp_negotiate_blob(unsigned char *pbuffer,
struct cifs_ses *ses)
{
NEGOTIATE_MESSAGE *sec_blob = (NEGOTIATE_MESSAGE *)pbuffer;
__u32 flags;
memset(pbuffer, 0, sizeof(NEGOTIATE_MESSAGE));
memcpy(sec_blob->Signature, NTLMSSP_SIGNATURE, 8);
sec_blob->MessageType = NtLmNegotiate;
flags = NTLMSSP_NEGOTIATE_56 | NTLMSSP_REQUEST_TARGET |
NTLMSSP_NEGOTIATE_128 | NTLMSSP_NEGOTIATE_UNICODE |
NTLMSSP_NEGOTIATE_NTLM | NTLMSSP_NEGOTIATE_EXTENDED_SEC;
if (ses->server->sign) {
flags |= NTLMSSP_NEGOTIATE_SIGN;
if (!ses->server->session_estab ||
ses->ntlmssp->sesskey_per_smbsess)
flags |= NTLMSSP_NEGOTIATE_KEY_XCH;
}
sec_blob->NegotiateFlags = cpu_to_le32(flags);
sec_blob->WorkstationName.BufferOffset = 0;
sec_blob->WorkstationName.Length = 0;
sec_blob->WorkstationName.MaximumLength = 0;
sec_blob->DomainName.BufferOffset = 0;
sec_blob->DomainName.Length = 0;
sec_blob->DomainName.MaximumLength = 0;
}
int build_ntlmssp_auth_blob(unsigned char *pbuffer,
u16 *buflen,
struct cifs_ses *ses,
const struct nls_table *nls_cp)
{
int rc;
AUTHENTICATE_MESSAGE *sec_blob = (AUTHENTICATE_MESSAGE *)pbuffer;
__u32 flags;
unsigned char *tmp;
memcpy(sec_blob->Signature, NTLMSSP_SIGNATURE, 8);
sec_blob->MessageType = NtLmAuthenticate;
flags = NTLMSSP_NEGOTIATE_56 |
NTLMSSP_REQUEST_TARGET | NTLMSSP_NEGOTIATE_TARGET_INFO |
NTLMSSP_NEGOTIATE_128 | NTLMSSP_NEGOTIATE_UNICODE |
NTLMSSP_NEGOTIATE_NTLM | NTLMSSP_NEGOTIATE_EXTENDED_SEC;
if (ses->server->sign) {
flags |= NTLMSSP_NEGOTIATE_SIGN;
if (!ses->server->session_estab ||
ses->ntlmssp->sesskey_per_smbsess)
flags |= NTLMSSP_NEGOTIATE_KEY_XCH;
}
tmp = pbuffer + sizeof(AUTHENTICATE_MESSAGE);
sec_blob->NegotiateFlags = cpu_to_le32(flags);
sec_blob->LmChallengeResponse.BufferOffset =
cpu_to_le32(sizeof(AUTHENTICATE_MESSAGE));
sec_blob->LmChallengeResponse.Length = 0;
sec_blob->LmChallengeResponse.MaximumLength = 0;
sec_blob->NtChallengeResponse.BufferOffset = cpu_to_le32(tmp - pbuffer);
rc = setup_ntlmv2_rsp(ses, nls_cp);
if (rc) {
cifs_dbg(VFS, "Error %d during NTLMSSP authentication\n", rc);
goto setup_ntlmv2_ret;
}
memcpy(tmp, ses->auth_key.response + CIFS_SESS_KEY_SIZE,
ses->auth_key.len - CIFS_SESS_KEY_SIZE);
tmp += ses->auth_key.len - CIFS_SESS_KEY_SIZE;
sec_blob->NtChallengeResponse.Length =
cpu_to_le16(ses->auth_key.len - CIFS_SESS_KEY_SIZE);
sec_blob->NtChallengeResponse.MaximumLength =
cpu_to_le16(ses->auth_key.len - CIFS_SESS_KEY_SIZE);
if (ses->domainName == NULL) {
sec_blob->DomainName.BufferOffset = cpu_to_le32(tmp - pbuffer);
sec_blob->DomainName.Length = 0;
sec_blob->DomainName.MaximumLength = 0;
tmp += 2;
} else {
int len;
len = cifs_strtoUTF16((__le16 *)tmp, ses->domainName,
CIFS_MAX_USERNAME_LEN, nls_cp);
len *= 2;
sec_blob->DomainName.BufferOffset = cpu_to_le32(tmp - pbuffer);
sec_blob->DomainName.Length = cpu_to_le16(len);
sec_blob->DomainName.MaximumLength = cpu_to_le16(len);
tmp += len;
}
if (ses->user_name == NULL) {
sec_blob->UserName.BufferOffset = cpu_to_le32(tmp - pbuffer);
sec_blob->UserName.Length = 0;
sec_blob->UserName.MaximumLength = 0;
tmp += 2;
} else {
int len;
len = cifs_strtoUTF16((__le16 *)tmp, ses->user_name,
CIFS_MAX_USERNAME_LEN, nls_cp);
len *= 2;
sec_blob->UserName.BufferOffset = cpu_to_le32(tmp - pbuffer);
sec_blob->UserName.Length = cpu_to_le16(len);
sec_blob->UserName.MaximumLength = cpu_to_le16(len);
tmp += len;
}
sec_blob->WorkstationName.BufferOffset = cpu_to_le32(tmp - pbuffer);
sec_blob->WorkstationName.Length = 0;
sec_blob->WorkstationName.MaximumLength = 0;
tmp += 2;
if (((ses->ntlmssp->server_flags & NTLMSSP_NEGOTIATE_KEY_XCH) ||
(ses->ntlmssp->server_flags & NTLMSSP_NEGOTIATE_EXTENDED_SEC))
&& !calc_seckey(ses)) {
memcpy(tmp, ses->ntlmssp->ciphertext, CIFS_CPHTXT_SIZE);
sec_blob->SessionKey.BufferOffset = cpu_to_le32(tmp - pbuffer);
sec_blob->SessionKey.Length = cpu_to_le16(CIFS_CPHTXT_SIZE);
sec_blob->SessionKey.MaximumLength =
cpu_to_le16(CIFS_CPHTXT_SIZE);
tmp += CIFS_CPHTXT_SIZE;
} else {
sec_blob->SessionKey.BufferOffset = cpu_to_le32(tmp - pbuffer);
sec_blob->SessionKey.Length = 0;
sec_blob->SessionKey.MaximumLength = 0;
}
setup_ntlmv2_ret:
*buflen = tmp - pbuffer;
return rc;
}
enum securityEnum
select_sectype(struct TCP_Server_Info *server, enum securityEnum requested)
{
switch (server->negflavor) {
case CIFS_NEGFLAVOR_EXTENDED:
switch (requested) {
case Kerberos:
case RawNTLMSSP:
return requested;
case Unspecified:
if (server->sec_ntlmssp &&
(global_secflags & CIFSSEC_MAY_NTLMSSP))
return RawNTLMSSP;
if ((server->sec_kerberos || server->sec_mskerberos) &&
(global_secflags & CIFSSEC_MAY_KRB5))
return Kerberos;
default:
return Unspecified;
}
case CIFS_NEGFLAVOR_UNENCAP:
switch (requested) {
case NTLM:
case NTLMv2:
return requested;
case Unspecified:
if (global_secflags & CIFSSEC_MAY_NTLMV2)
return NTLMv2;
if (global_secflags & CIFSSEC_MAY_NTLM)
return NTLM;
default:
break;
}
case CIFS_NEGFLAVOR_LANMAN:
switch (requested) {
case LANMAN:
return requested;
case Unspecified:
if (global_secflags & CIFSSEC_MAY_LANMAN)
return LANMAN;
default:
return Unspecified;
}
default:
return Unspecified;
}
}
int
CIFS_SessSetup(const unsigned int xid, struct cifs_ses *ses,
const struct nls_table *nls_cp)
{
int rc = 0;
int wct;
struct smb_hdr *smb_buf;
char *bcc_ptr;
char *str_area;
SESSION_SETUP_ANDX *pSMB;
__u32 capabilities;
__u16 count;
int resp_buf_type;
struct kvec iov[3];
enum securityEnum type;
__u16 action, bytes_remaining;
struct key *spnego_key = NULL;
__le32 phase = NtLmNegotiate;
u16 blob_len;
char *ntlmsspblob = NULL;
if (ses == NULL) {
WARN(1, "%s: ses == NULL!", __func__);
return -EINVAL;
}
type = select_sectype(ses->server, ses->sectype);
cifs_dbg(FYI, "sess setup type %d\n", type);
if (type == Unspecified) {
cifs_dbg(VFS,
"Unable to select appropriate authentication method!");
return -EINVAL;
}
if (type == RawNTLMSSP) {
ses->ntlmssp = kmalloc(sizeof(struct ntlmssp_auth), GFP_KERNEL);
if (!ses->ntlmssp)
return -ENOMEM;
ses->ntlmssp->sesskey_per_smbsess = false;
}
ssetup_ntlmssp_authenticate:
if (phase == NtLmChallenge)
phase = NtLmAuthenticate;
if (type == LANMAN) {
#ifndef CONFIG_CIFS_WEAK_PW_HASH
return -EOPNOTSUPP;
#endif
wct = 10;
} else if ((type == NTLM) || (type == NTLMv2)) {
wct = 13;
} else
wct = 12;
rc = small_smb_init_no_tc(SMB_COM_SESSION_SETUP_ANDX, wct, ses,
(void **)&smb_buf);
if (rc)
return rc;
pSMB = (SESSION_SETUP_ANDX *)smb_buf;
capabilities = cifs_ssetup_hdr(ses, pSMB);
iov[0].iov_base = (char *)pSMB;
iov[0].iov_len = be32_to_cpu(smb_buf->smb_buf_length) + 4;
resp_buf_type = CIFS_SMALL_BUFFER;
str_area = kmalloc(2000, GFP_KERNEL);
if (str_area == NULL) {
rc = -ENOMEM;
goto ssetup_exit;
}
bcc_ptr = str_area;
iov[1].iov_base = NULL;
iov[1].iov_len = 0;
if (type == LANMAN) {
#ifdef CONFIG_CIFS_WEAK_PW_HASH
char lnm_session_key[CIFS_AUTH_RESP_SIZE];
pSMB->req.hdr.Flags2 &= ~SMBFLG2_UNICODE;
pSMB->old_req.PasswordLength = cpu_to_le16(CIFS_AUTH_RESP_SIZE);
rc = calc_lanman_hash(ses->password, ses->server->cryptkey,
ses->server->sec_mode & SECMODE_PW_ENCRYPT ?
true : false, lnm_session_key);
memcpy(bcc_ptr, (char *)lnm_session_key, CIFS_AUTH_RESP_SIZE);
bcc_ptr += CIFS_AUTH_RESP_SIZE;
cifs_dbg(FYI, "Negotiating LANMAN setting up strings\n");
ascii_ssetup_strings(&bcc_ptr, ses, nls_cp);
#endif
} else if (type == NTLM) {
pSMB->req_no_secext.Capabilities = cpu_to_le32(capabilities);
pSMB->req_no_secext.CaseInsensitivePasswordLength =
cpu_to_le16(CIFS_AUTH_RESP_SIZE);
pSMB->req_no_secext.CaseSensitivePasswordLength =
cpu_to_le16(CIFS_AUTH_RESP_SIZE);
rc = setup_ntlm_response(ses, nls_cp);
if (rc) {
cifs_dbg(VFS, "Error %d during NTLM authentication\n",
rc);
goto ssetup_exit;
}
memcpy(bcc_ptr, ses->auth_key.response + CIFS_SESS_KEY_SIZE,
CIFS_AUTH_RESP_SIZE);
bcc_ptr += CIFS_AUTH_RESP_SIZE;
memcpy(bcc_ptr, ses->auth_key.response + CIFS_SESS_KEY_SIZE,
CIFS_AUTH_RESP_SIZE);
bcc_ptr += CIFS_AUTH_RESP_SIZE;
if (ses->capabilities & CAP_UNICODE) {
if (iov[0].iov_len % 2) {
*bcc_ptr = 0;
bcc_ptr++;
}
unicode_ssetup_strings(&bcc_ptr, ses, nls_cp);
} else
ascii_ssetup_strings(&bcc_ptr, ses, nls_cp);
} else if (type == NTLMv2) {
pSMB->req_no_secext.Capabilities = cpu_to_le32(capabilities);
pSMB->req_no_secext.CaseInsensitivePasswordLength = 0;
rc = setup_ntlmv2_rsp(ses, nls_cp);
if (rc) {
cifs_dbg(VFS, "Error %d during NTLMv2 authentication\n",
rc);
goto ssetup_exit;
}
memcpy(bcc_ptr, ses->auth_key.response + CIFS_SESS_KEY_SIZE,
ses->auth_key.len - CIFS_SESS_KEY_SIZE);
bcc_ptr += ses->auth_key.len - CIFS_SESS_KEY_SIZE;
pSMB->req_no_secext.CaseSensitivePasswordLength =
cpu_to_le16(ses->auth_key.len - CIFS_SESS_KEY_SIZE);
if (ses->capabilities & CAP_UNICODE) {
if (iov[0].iov_len % 2) {
*bcc_ptr = 0;
bcc_ptr++;
}
unicode_ssetup_strings(&bcc_ptr, ses, nls_cp);
} else
ascii_ssetup_strings(&bcc_ptr, ses, nls_cp);
} else if (type == Kerberos) {
#ifdef CONFIG_CIFS_UPCALL
struct cifs_spnego_msg *msg;
spnego_key = cifs_get_spnego_key(ses);
if (IS_ERR(spnego_key)) {
rc = PTR_ERR(spnego_key);
spnego_key = NULL;
goto ssetup_exit;
}
msg = spnego_key->payload.data;
if (msg->version != CIFS_SPNEGO_UPCALL_VERSION) {
cifs_dbg(VFS, "incorrect version of cifs.upcall "
"expected %d but got %d)",
CIFS_SPNEGO_UPCALL_VERSION, msg->version);
rc = -EKEYREJECTED;
goto ssetup_exit;
}
ses->auth_key.response = kmemdup(msg->data, msg->sesskey_len,
GFP_KERNEL);
if (!ses->auth_key.response) {
cifs_dbg(VFS,
"Kerberos can't allocate (%u bytes) memory",
msg->sesskey_len);
rc = -ENOMEM;
goto ssetup_exit;
}
ses->auth_key.len = msg->sesskey_len;
pSMB->req.hdr.Flags2 |= SMBFLG2_EXT_SEC;
capabilities |= CAP_EXTENDED_SECURITY;
pSMB->req.Capabilities = cpu_to_le32(capabilities);
iov[1].iov_base = msg->data + msg->sesskey_len;
iov[1].iov_len = msg->secblob_len;
pSMB->req.SecurityBlobLength = cpu_to_le16(iov[1].iov_len);
if (ses->capabilities & CAP_UNICODE) {
if ((iov[0].iov_len + iov[1].iov_len) % 2) {
*bcc_ptr = 0;
bcc_ptr++;
}
unicode_oslm_strings(&bcc_ptr, nls_cp);
unicode_domain_string(&bcc_ptr, ses, nls_cp);
} else
ascii_ssetup_strings(&bcc_ptr, ses, nls_cp);
#else
cifs_dbg(VFS, "Kerberos negotiated but upcall support disabled!\n");
rc = -ENOSYS;
goto ssetup_exit;
#endif
} else if (type == RawNTLMSSP) {
if ((pSMB->req.hdr.Flags2 & SMBFLG2_UNICODE) == 0) {
cifs_dbg(VFS, "NTLMSSP requires Unicode support\n");
rc = -ENOSYS;
goto ssetup_exit;
}
cifs_dbg(FYI, "ntlmssp session setup phase %d\n", phase);
pSMB->req.hdr.Flags2 |= SMBFLG2_EXT_SEC;
capabilities |= CAP_EXTENDED_SECURITY;
pSMB->req.Capabilities |= cpu_to_le32(capabilities);
switch(phase) {
case NtLmNegotiate:
build_ntlmssp_negotiate_blob(
pSMB->req.SecurityBlob, ses);
iov[1].iov_len = sizeof(NEGOTIATE_MESSAGE);
iov[1].iov_base = pSMB->req.SecurityBlob;
pSMB->req.SecurityBlobLength =
cpu_to_le16(sizeof(NEGOTIATE_MESSAGE));
break;
case NtLmAuthenticate:
ntlmsspblob = kzalloc(
5*sizeof(struct _AUTHENTICATE_MESSAGE),
GFP_KERNEL);
if (!ntlmsspblob) {
rc = -ENOMEM;
goto ssetup_exit;
}
rc = build_ntlmssp_auth_blob(ntlmsspblob,
&blob_len, ses, nls_cp);
if (rc)
goto ssetup_exit;
iov[1].iov_len = blob_len;
iov[1].iov_base = ntlmsspblob;
pSMB->req.SecurityBlobLength = cpu_to_le16(blob_len);
smb_buf->Uid = ses->Suid;
break;
default:
cifs_dbg(VFS, "invalid phase %d\n", phase);
rc = -ENOSYS;
goto ssetup_exit;
}
if ((iov[0].iov_len + iov[1].iov_len) % 2) {
*bcc_ptr = 0;
bcc_ptr++;
}
unicode_oslm_strings(&bcc_ptr, nls_cp);
} else {
cifs_dbg(VFS, "secType %d not supported!\n", type);
rc = -ENOSYS;
goto ssetup_exit;
}
iov[2].iov_base = str_area;
iov[2].iov_len = (long) bcc_ptr - (long) str_area;
count = iov[1].iov_len + iov[2].iov_len;
smb_buf->smb_buf_length =
cpu_to_be32(be32_to_cpu(smb_buf->smb_buf_length) + count);
put_bcc(count, smb_buf);
rc = SendReceive2(xid, ses, iov, 3 , &resp_buf_type,
CIFS_LOG_ERROR);
pSMB = (SESSION_SETUP_ANDX *)iov[0].iov_base;
smb_buf = (struct smb_hdr *)iov[0].iov_base;
if ((type == RawNTLMSSP) && (resp_buf_type != CIFS_NO_BUFFER) &&
(smb_buf->Status.CifsError ==
cpu_to_le32(NT_STATUS_MORE_PROCESSING_REQUIRED))) {
if (phase != NtLmNegotiate) {
cifs_dbg(VFS, "Unexpected more processing error\n");
goto ssetup_exit;
}
phase = NtLmChallenge;
rc = 0;
}
if (rc)
goto ssetup_exit;
if ((smb_buf->WordCount != 3) && (smb_buf->WordCount != 4)) {
rc = -EIO;
cifs_dbg(VFS, "bad word count %d\n", smb_buf->WordCount);
goto ssetup_exit;
}
action = le16_to_cpu(pSMB->resp.Action);
if (action & GUEST_LOGIN)
cifs_dbg(FYI, "Guest login\n");
ses->Suid = smb_buf->Uid;
cifs_dbg(FYI, "UID = %llu\n", ses->Suid);
bytes_remaining = get_bcc(smb_buf);
bcc_ptr = pByteArea(smb_buf);
if (smb_buf->WordCount == 4) {
blob_len = le16_to_cpu(pSMB->resp.SecurityBlobLength);
if (blob_len > bytes_remaining) {
cifs_dbg(VFS, "bad security blob length %d\n",
blob_len);
rc = -EINVAL;
goto ssetup_exit;
}
if (phase == NtLmChallenge) {
rc = decode_ntlmssp_challenge(bcc_ptr, blob_len, ses);
if (rc)
goto ssetup_exit;
}
bcc_ptr += blob_len;
bytes_remaining -= blob_len;
}
if (bytes_remaining == 0) {
} else if (smb_buf->Flags2 & SMBFLG2_UNICODE) {
if (((unsigned long) bcc_ptr - (unsigned long) smb_buf) % 2) {
++bcc_ptr;
--bytes_remaining;
}
decode_unicode_ssetup(&bcc_ptr, bytes_remaining, ses, nls_cp);
} else {
decode_ascii_ssetup(&bcc_ptr, bytes_remaining, ses, nls_cp);
}
ssetup_exit:
if (spnego_key) {
key_invalidate(spnego_key);
key_put(spnego_key);
}
kfree(str_area);
kfree(ntlmsspblob);
ntlmsspblob = NULL;
if (resp_buf_type == CIFS_SMALL_BUFFER) {
cifs_dbg(FYI, "ssetup freeing small buf %p\n", iov[0].iov_base);
cifs_small_buf_release(iov[0].iov_base);
} else if (resp_buf_type == CIFS_LARGE_BUFFER)
cifs_buf_release(iov[0].iov_base);
if ((phase == NtLmChallenge) && (rc == 0))
goto ssetup_ntlmssp_authenticate;
if (!rc) {
mutex_lock(&ses->server->srv_mutex);
if (!ses->server->session_estab) {
if (ses->server->sign) {
ses->server->session_key.response =
kmemdup(ses->auth_key.response,
ses->auth_key.len, GFP_KERNEL);
if (!ses->server->session_key.response) {
rc = -ENOMEM;
mutex_unlock(&ses->server->srv_mutex);
goto keycp_exit;
}
ses->server->session_key.len =
ses->auth_key.len;
}
ses->server->sequence_number = 0x2;
ses->server->session_estab = true;
}
mutex_unlock(&ses->server->srv_mutex);
cifs_dbg(FYI, "CIFS session established successfully\n");
spin_lock(&GlobalMid_Lock);
ses->status = CifsGood;
ses->need_reconnect = false;
spin_unlock(&GlobalMid_Lock);
}
keycp_exit:
kfree(ses->auth_key.response);
ses->auth_key.response = NULL;
kfree(ses->ntlmssp);
return rc;
}
