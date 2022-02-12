static int find_profile_by_name(char *profile_name,
SRTP_PROTECTION_PROFILE **pptr, unsigned len)
{
SRTP_PROTECTION_PROFILE *p;
p = srtp_known_profiles;
while (p->name) {
if ((len == strlen(p->name))
&& strncmp(p->name, profile_name, len) == 0) {
*pptr = p;
return 0;
}
p++;
}
return 1;
}
int SSL_CTX_set_tlsext_use_srtp(SSL_CTX *ctx, const char *profiles)
{
return ssl_ctx_make_profiles(profiles, &ctx->srtp_profiles);
}
int SSL_set_tlsext_use_srtp(SSL *s, const char *profiles)
{
return ssl_ctx_make_profiles(profiles, &s->srtp_profiles);
}
int ssl_add_clienthello_use_srtp_ext(SSL *s, unsigned char *p, int *len,
int maxlen)
{
int ct = 0;
int i;
STACK_OF(SRTP_PROTECTION_PROFILE) *clnt = 0;
SRTP_PROTECTION_PROFILE *prof;
clnt = SSL_get_srtp_profiles(s);
ct = sk_SRTP_PROTECTION_PROFILE_num(clnt);
if (p) {
if (ct == 0) {
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_USE_SRTP_EXT,
SSL_R_EMPTY_SRTP_PROTECTION_PROFILE_LIST);
return 1;
}
if ((2 + ct * 2 + 1) > maxlen) {
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_USE_SRTP_EXT,
SSL_R_SRTP_PROTECTION_PROFILE_LIST_TOO_LONG);
return 1;
}
s2n(ct * 2, p);
for (i = 0; i < ct; i++) {
prof = sk_SRTP_PROTECTION_PROFILE_value(clnt, i);
s2n(prof->id, p);
}
*p++ = 0;
}
*len = 2 + ct * 2 + 1;
return 0;
}
int ssl_parse_clienthello_use_srtp_ext(SSL *s, PACKET *pkt, int *al)
{
SRTP_PROTECTION_PROFILE *sprof;
STACK_OF(SRTP_PROTECTION_PROFILE) *srvr;
unsigned int ct, mki_len, id;
int i, srtp_pref;
PACKET subpkt;
if (!PACKET_get_net_2(pkt, &ct)
|| (ct & 1) != 0 || !PACKET_get_sub_packet(pkt, &subpkt, ct)) {
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_USE_SRTP_EXT,
SSL_R_BAD_SRTP_PROTECTION_PROFILE_LIST);
*al = SSL_AD_DECODE_ERROR;
return 1;
}
srvr = SSL_get_srtp_profiles(s);
s->srtp_profile = NULL;
srtp_pref = sk_SRTP_PROTECTION_PROFILE_num(srvr);
while (PACKET_remaining(&subpkt)) {
if (!PACKET_get_net_2(&subpkt, &id)) {
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_USE_SRTP_EXT,
SSL_R_BAD_SRTP_PROTECTION_PROFILE_LIST);
*al = SSL_AD_DECODE_ERROR;
return 1;
}
for (i = 0; i < srtp_pref; i++) {
sprof = sk_SRTP_PROTECTION_PROFILE_value(srvr, i);
if (sprof->id == id) {
s->srtp_profile = sprof;
srtp_pref = i;
break;
}
}
}
if (!PACKET_get_1(pkt, &mki_len)) {
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_USE_SRTP_EXT,
SSL_R_BAD_SRTP_PROTECTION_PROFILE_LIST);
*al = SSL_AD_DECODE_ERROR;
return 1;
}
if (!PACKET_forward(pkt, mki_len)
|| PACKET_remaining(pkt)) {
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_USE_SRTP_EXT,
SSL_R_BAD_SRTP_MKI_VALUE);
*al = SSL_AD_DECODE_ERROR;
return 1;
}
return 0;
}
int ssl_add_serverhello_use_srtp_ext(SSL *s, unsigned char *p, int *len,
int maxlen)
{
if (p) {
if (maxlen < 5) {
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_USE_SRTP_EXT,
SSL_R_SRTP_PROTECTION_PROFILE_LIST_TOO_LONG);
return 1;
}
if (s->srtp_profile == 0) {
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_USE_SRTP_EXT,
SSL_R_USE_SRTP_NOT_NEGOTIATED);
return 1;
}
s2n(2, p);
s2n(s->srtp_profile->id, p);
*p++ = 0;
}
*len = 5;
return 0;
}
int ssl_parse_serverhello_use_srtp_ext(SSL *s, PACKET *pkt, int *al)
{
unsigned int id, ct, mki;
int i;
STACK_OF(SRTP_PROTECTION_PROFILE) *clnt;
SRTP_PROTECTION_PROFILE *prof;
if (!PACKET_get_net_2(pkt, &ct)
|| ct != 2 || !PACKET_get_net_2(pkt, &id)
|| !PACKET_get_1(pkt, &mki)
|| PACKET_remaining(pkt) != 0) {
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_USE_SRTP_EXT,
SSL_R_BAD_SRTP_PROTECTION_PROFILE_LIST);
*al = SSL_AD_DECODE_ERROR;
return 1;
}
if (mki != 0) {
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_USE_SRTP_EXT,
SSL_R_BAD_SRTP_MKI_VALUE);
*al = SSL_AD_ILLEGAL_PARAMETER;
return 1;
}
clnt = SSL_get_srtp_profiles(s);
if (clnt == NULL) {
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_USE_SRTP_EXT,
SSL_R_NO_SRTP_PROFILES);
*al = SSL_AD_DECODE_ERROR;
return 1;
}
for (i = 0; i < sk_SRTP_PROTECTION_PROFILE_num(clnt); i++) {
prof = sk_SRTP_PROTECTION_PROFILE_value(clnt, i);
if (prof->id == id) {
s->srtp_profile = prof;
*al = 0;
return 0;
}
}
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_USE_SRTP_EXT,
SSL_R_BAD_SRTP_PROTECTION_PROFILE_LIST);
*al = SSL_AD_DECODE_ERROR;
return 1;
}
