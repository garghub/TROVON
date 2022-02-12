long tls1_default_timeout(void)
{
return(60*60*2);
}
int tls1_new(SSL *s)
{
if (!ssl3_new(s)) return(0);
s->method->ssl_clear(s);
return(1);
}
void tls1_free(SSL *s)
{
#ifndef OPENSSL_NO_TLSEXT
if (s->tlsext_session_ticket)
{
OPENSSL_free(s->tlsext_session_ticket);
}
#endif
ssl3_free(s);
}
void tls1_clear(SSL *s)
{
ssl3_clear(s);
s->version=TLS1_VERSION;
}
int tls1_ec_curve_id2nid(int curve_id)
{
if ((curve_id < 1) || ((unsigned int)curve_id >
sizeof(nid_list)/sizeof(nid_list[0])))
return 0;
return nid_list[curve_id-1];
}
int tls1_ec_nid2curve_id(int nid)
{
switch (nid)
{
case NID_sect163k1:
return 1;
case NID_sect163r1:
return 2;
case NID_sect163r2:
return 3;
case NID_sect193r1:
return 4;
case NID_sect193r2:
return 5;
case NID_sect233k1:
return 6;
case NID_sect233r1:
return 7;
case NID_sect239k1:
return 8;
case NID_sect283k1:
return 9;
case NID_sect283r1:
return 10;
case NID_sect409k1:
return 11;
case NID_sect409r1:
return 12;
case NID_sect571k1:
return 13;
case NID_sect571r1:
return 14;
case NID_secp160k1:
return 15;
case NID_secp160r1:
return 16;
case NID_secp160r2:
return 17;
case NID_secp192k1:
return 18;
case NID_X9_62_prime192v1:
return 19;
case NID_secp224k1:
return 20;
case NID_secp224r1:
return 21;
case NID_secp256k1:
return 22;
case NID_X9_62_prime256v1:
return 23;
case NID_secp384r1:
return 24;
case NID_secp521r1:
return 25;
default:
return 0;
}
}
unsigned char *ssl_add_clienthello_tlsext(SSL *s, unsigned char *p, unsigned char *limit)
{
int extdatalen=0;
unsigned char *ret = p;
if (s->client_version == SSL3_VERSION
&& !s->s3->send_connection_binding)
return p;
ret+=2;
if (ret>=limit) return NULL;
if (s->tlsext_hostname != NULL)
{
unsigned long size_str;
long lenmax;
if ((lenmax = limit - ret - 9) < 0
|| (size_str = strlen(s->tlsext_hostname)) > (unsigned long)lenmax)
return NULL;
s2n(TLSEXT_TYPE_server_name,ret);
s2n(size_str+5,ret);
s2n(size_str+3,ret);
*(ret++) = (unsigned char) TLSEXT_NAMETYPE_host_name;
s2n(size_str,ret);
memcpy(ret, s->tlsext_hostname, size_str);
ret+=size_str;
}
if (s->new_session)
{
int el;
if(!ssl_add_clienthello_renegotiate_ext(s, 0, &el, 0))
{
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
if((limit - p - 4 - el) < 0) return NULL;
s2n(TLSEXT_TYPE_renegotiate,ret);
s2n(el,ret);
if(!ssl_add_clienthello_renegotiate_ext(s, ret, &el, el))
{
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
ret += el;
}
#ifndef OPENSSL_NO_EC
if (s->tlsext_ecpointformatlist != NULL &&
s->version != DTLS1_VERSION)
{
long lenmax;
if ((lenmax = limit - ret - 5) < 0) return NULL;
if (s->tlsext_ecpointformatlist_length > (unsigned long)lenmax) return NULL;
if (s->tlsext_ecpointformatlist_length > 255)
{
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
s2n(TLSEXT_TYPE_ec_point_formats,ret);
s2n(s->tlsext_ecpointformatlist_length + 1,ret);
*(ret++) = (unsigned char) s->tlsext_ecpointformatlist_length;
memcpy(ret, s->tlsext_ecpointformatlist, s->tlsext_ecpointformatlist_length);
ret+=s->tlsext_ecpointformatlist_length;
}
if (s->tlsext_ellipticcurvelist != NULL &&
s->version != DTLS1_VERSION)
{
long lenmax;
if ((lenmax = limit - ret - 6) < 0) return NULL;
if (s->tlsext_ellipticcurvelist_length > (unsigned long)lenmax) return NULL;
if (s->tlsext_ellipticcurvelist_length > 65532)
{
SSLerr(SSL_F_SSL_ADD_CLIENTHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
s2n(TLSEXT_TYPE_elliptic_curves,ret);
s2n(s->tlsext_ellipticcurvelist_length + 2, ret);
s2n(s->tlsext_ellipticcurvelist_length, ret);
memcpy(ret, s->tlsext_ellipticcurvelist, s->tlsext_ellipticcurvelist_length);
ret+=s->tlsext_ellipticcurvelist_length;
}
#endif
if (!(SSL_get_options(s) & SSL_OP_NO_TICKET))
{
int ticklen;
if (!s->new_session && s->session && s->session->tlsext_tick)
ticklen = s->session->tlsext_ticklen;
else if (s->session && s->tlsext_session_ticket &&
s->tlsext_session_ticket->data)
{
ticklen = s->tlsext_session_ticket->length;
s->session->tlsext_tick = OPENSSL_malloc(ticklen);
if (!s->session->tlsext_tick)
return NULL;
memcpy(s->session->tlsext_tick,
s->tlsext_session_ticket->data,
ticklen);
s->session->tlsext_ticklen = ticklen;
}
else
ticklen = 0;
if (ticklen == 0 && s->tlsext_session_ticket &&
s->tlsext_session_ticket->data == NULL)
goto skip_ext;
if ((long)(limit - ret - 4 - ticklen) < 0) return NULL;
s2n(TLSEXT_TYPE_session_ticket,ret);
s2n(ticklen,ret);
if (ticklen)
{
memcpy(ret, s->session->tlsext_tick, ticklen);
ret += ticklen;
}
}
skip_ext:
#ifdef TLSEXT_TYPE_opaque_prf_input
if (s->s3->client_opaque_prf_input != NULL &&
s->version != DTLS1_VERSION)
{
size_t col = s->s3->client_opaque_prf_input_len;
if ((long)(limit - ret - 6 - col < 0))
return NULL;
if (col > 0xFFFD)
return NULL;
s2n(TLSEXT_TYPE_opaque_prf_input, ret);
s2n(col + 2, ret);
s2n(col, ret);
memcpy(ret, s->s3->client_opaque_prf_input, col);
ret += col;
}
#endif
if (s->tlsext_status_type == TLSEXT_STATUSTYPE_ocsp &&
s->version != DTLS1_VERSION)
{
int i;
long extlen, idlen, itmp;
OCSP_RESPID *id;
idlen = 0;
for (i = 0; i < sk_OCSP_RESPID_num(s->tlsext_ocsp_ids); i++)
{
id = sk_OCSP_RESPID_value(s->tlsext_ocsp_ids, i);
itmp = i2d_OCSP_RESPID(id, NULL);
if (itmp <= 0)
return NULL;
idlen += itmp + 2;
}
if (s->tlsext_ocsp_exts)
{
extlen = i2d_X509_EXTENSIONS(s->tlsext_ocsp_exts, NULL);
if (extlen < 0)
return NULL;
}
else
extlen = 0;
if ((long)(limit - ret - 7 - extlen - idlen) < 0) return NULL;
s2n(TLSEXT_TYPE_status_request, ret);
if (extlen + idlen > 0xFFF0)
return NULL;
s2n(extlen + idlen + 5, ret);
*(ret++) = TLSEXT_STATUSTYPE_ocsp;
s2n(idlen, ret);
for (i = 0; i < sk_OCSP_RESPID_num(s->tlsext_ocsp_ids); i++)
{
unsigned char *q = ret;
id = sk_OCSP_RESPID_value(s->tlsext_ocsp_ids, i);
ret += 2;
itmp = i2d_OCSP_RESPID(id, &ret);
s2n(itmp, q);
}
s2n(extlen, ret);
if (extlen > 0)
i2d_X509_EXTENSIONS(s->tlsext_ocsp_exts, &ret);
}
if ((extdatalen = ret-p-2)== 0)
return p;
s2n(extdatalen,p);
return ret;
}
unsigned char *ssl_add_serverhello_tlsext(SSL *s, unsigned char *p, unsigned char *limit)
{
int extdatalen=0;
unsigned char *ret = p;
if (s->version == SSL3_VERSION && !s->s3->send_connection_binding)
return p;
ret+=2;
if (ret>=limit) return NULL;
if (!s->hit && s->servername_done == 1 && s->session->tlsext_hostname != NULL)
{
if ((long)(limit - ret - 4) < 0) return NULL;
s2n(TLSEXT_TYPE_server_name,ret);
s2n(0,ret);
}
if(s->s3->send_connection_binding)
{
int el;
if(!ssl_add_serverhello_renegotiate_ext(s, 0, &el, 0))
{
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
if((limit - p - 4 - el) < 0) return NULL;
s2n(TLSEXT_TYPE_renegotiate,ret);
s2n(el,ret);
if(!ssl_add_serverhello_renegotiate_ext(s, ret, &el, el))
{
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
ret += el;
}
#ifndef OPENSSL_NO_EC
if (s->tlsext_ecpointformatlist != NULL &&
s->version != DTLS1_VERSION)
{
long lenmax;
if ((lenmax = limit - ret - 5) < 0) return NULL;
if (s->tlsext_ecpointformatlist_length > (unsigned long)lenmax) return NULL;
if (s->tlsext_ecpointformatlist_length > 255)
{
SSLerr(SSL_F_SSL_ADD_SERVERHELLO_TLSEXT, ERR_R_INTERNAL_ERROR);
return NULL;
}
s2n(TLSEXT_TYPE_ec_point_formats,ret);
s2n(s->tlsext_ecpointformatlist_length + 1,ret);
*(ret++) = (unsigned char) s->tlsext_ecpointformatlist_length;
memcpy(ret, s->tlsext_ecpointformatlist, s->tlsext_ecpointformatlist_length);
ret+=s->tlsext_ecpointformatlist_length;
}
#endif
if (s->tlsext_ticket_expected
&& !(SSL_get_options(s) & SSL_OP_NO_TICKET))
{
if ((long)(limit - ret - 4) < 0) return NULL;
s2n(TLSEXT_TYPE_session_ticket,ret);
s2n(0,ret);
}
if (s->tlsext_status_expected)
{
if ((long)(limit - ret - 4) < 0) return NULL;
s2n(TLSEXT_TYPE_status_request,ret);
s2n(0,ret);
}
#ifdef TLSEXT_TYPE_opaque_prf_input
if (s->s3->server_opaque_prf_input != NULL &&
s->version != DTLS1_VERSION)
{
size_t sol = s->s3->server_opaque_prf_input_len;
if ((long)(limit - ret - 6 - sol) < 0)
return NULL;
if (sol > 0xFFFD)
return NULL;
s2n(TLSEXT_TYPE_opaque_prf_input, ret);
s2n(sol + 2, ret);
s2n(sol, ret);
memcpy(ret, s->s3->server_opaque_prf_input, sol);
ret += sol;
}
#endif
if (((s->s3->tmp.new_cipher->id & 0xFFFF)==0x80 || (s->s3->tmp.new_cipher->id & 0xFFFF)==0x81)
&& (SSL_get_options(s) & SSL_OP_CRYPTOPRO_TLSEXT_BUG))
{ const unsigned char cryptopro_ext[36] = {
0xfd, 0xe8,
0x00, 0x20,
0x30, 0x1e, 0x30, 0x08, 0x06, 0x06, 0x2a, 0x85,
0x03, 0x02, 0x02, 0x09, 0x30, 0x08, 0x06, 0x06,
0x2a, 0x85, 0x03, 0x02, 0x02, 0x16, 0x30, 0x08,
0x06, 0x06, 0x2a, 0x85, 0x03, 0x02, 0x02, 0x17};
if (limit-ret<36) return NULL;
memcpy(ret,cryptopro_ext,36);
ret+=36;
}
if ((extdatalen = ret-p-2)== 0)
return p;
s2n(extdatalen,p);
return ret;
}
int ssl_parse_clienthello_tlsext(SSL *s, unsigned char **p, unsigned char *d, int n, int *al)
{
unsigned short type;
unsigned short size;
unsigned short len;
unsigned char *data = *p;
int renegotiate_seen = 0;
s->servername_done = 0;
s->tlsext_status_type = -1;
if (data >= (d+n-2))
goto ri_check;
n2s(data,len);
if (data > (d+n-len))
goto ri_check;
while (data <= (d+n-4))
{
n2s(data,type);
n2s(data,size);
if (data+size > (d+n))
goto ri_check;
#if 0
fprintf(stderr,"Received extension type %d size %d\n",type,size);
#endif
if (s->tlsext_debug_cb)
s->tlsext_debug_cb(s, 0, type, data, size,
s->tlsext_debug_arg);
if (type == TLSEXT_TYPE_server_name)
{
unsigned char *sdata;
int servname_type;
int dsize;
if (size < 2)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
n2s(data,dsize);
size -= 2;
if (dsize > size )
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
sdata = data;
while (dsize > 3)
{
servname_type = *(sdata++);
n2s(sdata,len);
dsize -= 3;
if (len > dsize)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (s->servername_done == 0)
switch (servname_type)
{
case TLSEXT_NAMETYPE_host_name:
if (s->session->tlsext_hostname == NULL)
{
if (len > TLSEXT_MAXLEN_host_name ||
((s->session->tlsext_hostname = OPENSSL_malloc(len+1)) == NULL))
{
*al = TLS1_AD_UNRECOGNIZED_NAME;
return 0;
}
memcpy(s->session->tlsext_hostname, sdata, len);
s->session->tlsext_hostname[len]='\0';
if (strlen(s->session->tlsext_hostname) != len) {
OPENSSL_free(s->session->tlsext_hostname);
s->session->tlsext_hostname = NULL;
*al = TLS1_AD_UNRECOGNIZED_NAME;
return 0;
}
s->servername_done = 1;
}
else
s->servername_done = strlen(s->session->tlsext_hostname) == len
&& strncmp(s->session->tlsext_hostname, (char *)sdata, len) == 0;
break;
default:
break;
}
dsize -= len;
}
if (dsize != 0)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
}
#ifndef OPENSSL_NO_EC
else if (type == TLSEXT_TYPE_ec_point_formats &&
s->version != DTLS1_VERSION)
{
unsigned char *sdata = data;
int ecpointformatlist_length = *(sdata++);
if (ecpointformatlist_length != size - 1)
{
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
s->session->tlsext_ecpointformatlist_length = 0;
if (s->session->tlsext_ecpointformatlist != NULL) OPENSSL_free(s->session->tlsext_ecpointformatlist);
if ((s->session->tlsext_ecpointformatlist = OPENSSL_malloc(ecpointformatlist_length)) == NULL)
{
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
s->session->tlsext_ecpointformatlist_length = ecpointformatlist_length;
memcpy(s->session->tlsext_ecpointformatlist, sdata, ecpointformatlist_length);
#if 0
fprintf(stderr,"ssl_parse_clienthello_tlsext s->session->tlsext_ecpointformatlist (length=%i) ", s->session->tlsext_ecpointformatlist_length);
sdata = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++)
fprintf(stderr,"%i ",*(sdata++));
fprintf(stderr,"\n");
#endif
}
else if (type == TLSEXT_TYPE_elliptic_curves &&
s->version != DTLS1_VERSION)
{
unsigned char *sdata = data;
int ellipticcurvelist_length = (*(sdata++) << 8);
ellipticcurvelist_length += (*(sdata++));
if (ellipticcurvelist_length != size - 2)
{
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
s->session->tlsext_ellipticcurvelist_length = 0;
if (s->session->tlsext_ellipticcurvelist != NULL) OPENSSL_free(s->session->tlsext_ellipticcurvelist);
if ((s->session->tlsext_ellipticcurvelist = OPENSSL_malloc(ellipticcurvelist_length)) == NULL)
{
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
s->session->tlsext_ellipticcurvelist_length = ellipticcurvelist_length;
memcpy(s->session->tlsext_ellipticcurvelist, sdata, ellipticcurvelist_length);
#if 0
fprintf(stderr,"ssl_parse_clienthello_tlsext s->session->tlsext_ellipticcurvelist (length=%i) ", s->session->tlsext_ellipticcurvelist_length);
sdata = s->session->tlsext_ellipticcurvelist;
for (i = 0; i < s->session->tlsext_ellipticcurvelist_length; i++)
fprintf(stderr,"%i ",*(sdata++));
fprintf(stderr,"\n");
#endif
}
#endif
#ifdef TLSEXT_TYPE_opaque_prf_input
else if (type == TLSEXT_TYPE_opaque_prf_input &&
s->version != DTLS1_VERSION)
{
unsigned char *sdata = data;
if (size < 2)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
n2s(sdata, s->s3->client_opaque_prf_input_len);
if (s->s3->client_opaque_prf_input_len != size - 2)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (s->s3->client_opaque_prf_input != NULL)
OPENSSL_free(s->s3->client_opaque_prf_input);
if (s->s3->client_opaque_prf_input_len == 0)
s->s3->client_opaque_prf_input = OPENSSL_malloc(1);
else
s->s3->client_opaque_prf_input = BUF_memdup(sdata, s->s3->client_opaque_prf_input_len);
if (s->s3->client_opaque_prf_input == NULL)
{
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
}
#endif
else if (type == TLSEXT_TYPE_session_ticket)
{
if (s->tls_session_ticket_ext_cb &&
!s->tls_session_ticket_ext_cb(s, data, size, s->tls_session_ticket_ext_cb_arg))
{
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
}
else if (type == TLSEXT_TYPE_renegotiate)
{
if(!ssl_parse_clienthello_renegotiate_ext(s, data, size, al))
return 0;
renegotiate_seen = 1;
}
else if (type == TLSEXT_TYPE_status_request &&
s->version != DTLS1_VERSION && s->ctx->tlsext_status_cb)
{
if (size < 5)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
s->tlsext_status_type = *data++;
size--;
if (s->tlsext_status_type == TLSEXT_STATUSTYPE_ocsp)
{
const unsigned char *sdata;
int dsize;
n2s(data,dsize);
size -= 2;
if (dsize > size )
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
while (dsize > 0)
{
OCSP_RESPID *id;
int idsize;
if (dsize < 4)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
n2s(data, idsize);
dsize -= 2 + idsize;
if (dsize < 0)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
sdata = data;
data += idsize;
id = d2i_OCSP_RESPID(NULL,
&sdata, idsize);
if (!id)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (data != sdata)
{
OCSP_RESPID_free(id);
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (!s->tlsext_ocsp_ids
&& !(s->tlsext_ocsp_ids =
sk_OCSP_RESPID_new_null()))
{
OCSP_RESPID_free(id);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
}
if (!sk_OCSP_RESPID_push(
s->tlsext_ocsp_ids, id))
{
OCSP_RESPID_free(id);
*al = SSL_AD_INTERNAL_ERROR;
return 0;
}
}
n2s(data,dsize);
size -= 2;
if (dsize > size)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
sdata = data;
if (dsize > 0)
{
s->tlsext_ocsp_exts =
d2i_X509_EXTENSIONS(NULL,
&sdata, dsize);
if (!s->tlsext_ocsp_exts
|| (data + dsize != sdata))
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
}
}
else
s->tlsext_status_type = -1;
}
data+=size;
}
*p = data;
ri_check:
if (!renegotiate_seen && s->new_session &&
!(s->options & SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION))
{
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_SSL_PARSE_CLIENTHELLO_TLSEXT,
SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED);
return 0;
}
return 1;
}
int ssl_parse_serverhello_tlsext(SSL *s, unsigned char **p, unsigned char *d, int n, int *al)
{
unsigned short type;
unsigned short size;
unsigned short len;
unsigned char *data = *p;
int tlsext_servername = 0;
int renegotiate_seen = 0;
if (data >= (d+n-2))
goto ri_check;
n2s(data,len);
while(data <= (d+n-4))
{
n2s(data,type);
n2s(data,size);
if (data+size > (d+n))
goto ri_check;
if (s->tlsext_debug_cb)
s->tlsext_debug_cb(s, 1, type, data, size,
s->tlsext_debug_arg);
if (type == TLSEXT_TYPE_server_name)
{
if (s->tlsext_hostname == NULL || size > 0)
{
*al = TLS1_AD_UNRECOGNIZED_NAME;
return 0;
}
tlsext_servername = 1;
}
#ifndef OPENSSL_NO_EC
else if (type == TLSEXT_TYPE_ec_point_formats &&
s->version != DTLS1_VERSION)
{
unsigned char *sdata = data;
int ecpointformatlist_length = *(sdata++);
if (ecpointformatlist_length != size - 1)
{
*al = TLS1_AD_DECODE_ERROR;
return 0;
}
s->session->tlsext_ecpointformatlist_length = 0;
if (s->session->tlsext_ecpointformatlist != NULL) OPENSSL_free(s->session->tlsext_ecpointformatlist);
if ((s->session->tlsext_ecpointformatlist = OPENSSL_malloc(ecpointformatlist_length)) == NULL)
{
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
s->session->tlsext_ecpointformatlist_length = ecpointformatlist_length;
memcpy(s->session->tlsext_ecpointformatlist, sdata, ecpointformatlist_length);
#if 0
fprintf(stderr,"ssl_parse_serverhello_tlsext s->session->tlsext_ecpointformatlist ");
sdata = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++)
fprintf(stderr,"%i ",*(sdata++));
fprintf(stderr,"\n");
#endif
}
#endif
else if (type == TLSEXT_TYPE_session_ticket)
{
if (s->tls_session_ticket_ext_cb &&
!s->tls_session_ticket_ext_cb(s, data, size, s->tls_session_ticket_ext_cb_arg))
{
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
if ((SSL_get_options(s) & SSL_OP_NO_TICKET)
|| (size > 0))
{
*al = TLS1_AD_UNSUPPORTED_EXTENSION;
return 0;
}
s->tlsext_ticket_expected = 1;
}
#ifdef TLSEXT_TYPE_opaque_prf_input
else if (type == TLSEXT_TYPE_opaque_prf_input &&
s->version != DTLS1_VERSION)
{
unsigned char *sdata = data;
if (size < 2)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
n2s(sdata, s->s3->server_opaque_prf_input_len);
if (s->s3->server_opaque_prf_input_len != size - 2)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (s->s3->server_opaque_prf_input != NULL)
OPENSSL_free(s->s3->server_opaque_prf_input);
if (s->s3->server_opaque_prf_input_len == 0)
s->s3->server_opaque_prf_input = OPENSSL_malloc(1);
else
s->s3->server_opaque_prf_input = BUF_memdup(sdata, s->s3->server_opaque_prf_input_len);
if (s->s3->server_opaque_prf_input == NULL)
{
*al = TLS1_AD_INTERNAL_ERROR;
return 0;
}
}
#endif
else if (type == TLSEXT_TYPE_status_request &&
s->version != DTLS1_VERSION)
{
if ((s->tlsext_status_type == -1) || (size > 0))
{
*al = TLS1_AD_UNSUPPORTED_EXTENSION;
return 0;
}
s->tlsext_status_expected = 1;
}
else if (type == TLSEXT_TYPE_renegotiate)
{
if(!ssl_parse_serverhello_renegotiate_ext(s, data, size, al))
return 0;
renegotiate_seen = 1;
}
data+=size;
}
if (data != d+n)
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
if (!s->hit && tlsext_servername == 1)
{
if (s->tlsext_hostname)
{
if (s->session->tlsext_hostname == NULL)
{
s->session->tlsext_hostname = BUF_strdup(s->tlsext_hostname);
if (!s->session->tlsext_hostname)
{
*al = SSL_AD_UNRECOGNIZED_NAME;
return 0;
}
}
else
{
*al = SSL_AD_DECODE_ERROR;
return 0;
}
}
}
*p = data;
ri_check:
if (!renegotiate_seen
&& !(s->options & SSL_OP_LEGACY_SERVER_CONNECT)
&& !(s->options & SSL_OP_ALLOW_UNSAFE_LEGACY_RENEGOTIATION))
{
*al = SSL_AD_HANDSHAKE_FAILURE;
SSLerr(SSL_F_SSL_PARSE_SERVERHELLO_TLSEXT,
SSL_R_UNSAFE_LEGACY_RENEGOTIATION_DISABLED);
return 0;
}
return 1;
}
int ssl_prepare_clienthello_tlsext(SSL *s)
{
#ifndef OPENSSL_NO_EC
int using_ecc = 0;
int i;
unsigned char *j;
unsigned long alg_k, alg_a;
STACK_OF(SSL_CIPHER) *cipher_stack = SSL_get_ciphers(s);
for (i = 0; i < sk_SSL_CIPHER_num(cipher_stack); i++)
{
SSL_CIPHER *c = sk_SSL_CIPHER_value(cipher_stack, i);
alg_k = c->algorithm_mkey;
alg_a = c->algorithm_auth;
if ((alg_k & (SSL_kEECDH|SSL_kECDHr|SSL_kECDHe) || (alg_a & SSL_aECDSA)))
{
using_ecc = 1;
break;
}
}
using_ecc = using_ecc && (s->version == TLS1_VERSION);
if (using_ecc)
{
if (s->tlsext_ecpointformatlist != NULL) OPENSSL_free(s->tlsext_ecpointformatlist);
if ((s->tlsext_ecpointformatlist = OPENSSL_malloc(3)) == NULL)
{
SSLerr(SSL_F_SSL_PREPARE_CLIENTHELLO_TLSEXT,ERR_R_MALLOC_FAILURE);
return -1;
}
s->tlsext_ecpointformatlist_length = 3;
s->tlsext_ecpointformatlist[0] = TLSEXT_ECPOINTFORMAT_uncompressed;
s->tlsext_ecpointformatlist[1] = TLSEXT_ECPOINTFORMAT_ansiX962_compressed_prime;
s->tlsext_ecpointformatlist[2] = TLSEXT_ECPOINTFORMAT_ansiX962_compressed_char2;
if (s->tlsext_ellipticcurvelist != NULL) OPENSSL_free(s->tlsext_ellipticcurvelist);
s->tlsext_ellipticcurvelist_length = sizeof(nid_list)/sizeof(nid_list[0]) * 2;
if ((s->tlsext_ellipticcurvelist = OPENSSL_malloc(s->tlsext_ellipticcurvelist_length)) == NULL)
{
s->tlsext_ellipticcurvelist_length = 0;
SSLerr(SSL_F_SSL_PREPARE_CLIENTHELLO_TLSEXT,ERR_R_MALLOC_FAILURE);
return -1;
}
for (i = 1, j = s->tlsext_ellipticcurvelist; (unsigned int)i <=
sizeof(nid_list)/sizeof(nid_list[0]); i++)
s2n(i,j);
}
#endif
#ifdef TLSEXT_TYPE_opaque_prf_input
{
int r = 1;
if (s->ctx->tlsext_opaque_prf_input_callback != 0)
{
r = s->ctx->tlsext_opaque_prf_input_callback(s, NULL, 0, s->ctx->tlsext_opaque_prf_input_callback_arg);
if (!r)
return -1;
}
if (s->tlsext_opaque_prf_input != NULL)
{
if (s->s3->client_opaque_prf_input != NULL)
OPENSSL_free(s->s3->client_opaque_prf_input);
if (s->tlsext_opaque_prf_input_len == 0)
s->s3->client_opaque_prf_input = OPENSSL_malloc(1);
else
s->s3->client_opaque_prf_input = BUF_memdup(s->tlsext_opaque_prf_input, s->tlsext_opaque_prf_input_len);
if (s->s3->client_opaque_prf_input == NULL)
{
SSLerr(SSL_F_SSL_PREPARE_CLIENTHELLO_TLSEXT,ERR_R_MALLOC_FAILURE);
return -1;
}
s->s3->client_opaque_prf_input_len = s->tlsext_opaque_prf_input_len;
}
if (r == 2)
s->s3->server_opaque_prf_input_len = s->tlsext_opaque_prf_input_len;
}
#endif
return 1;
}
int ssl_prepare_serverhello_tlsext(SSL *s)
{
#ifndef OPENSSL_NO_EC
unsigned long alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
unsigned long alg_a = s->s3->tmp.new_cipher->algorithm_auth;
int using_ecc = (alg_k & (SSL_kEECDH|SSL_kECDHr|SSL_kECDHe)) || (alg_a & SSL_aECDSA);
using_ecc = using_ecc && (s->session->tlsext_ecpointformatlist != NULL);
if (using_ecc)
{
if (s->tlsext_ecpointformatlist != NULL) OPENSSL_free(s->tlsext_ecpointformatlist);
if ((s->tlsext_ecpointformatlist = OPENSSL_malloc(3)) == NULL)
{
SSLerr(SSL_F_SSL_PREPARE_SERVERHELLO_TLSEXT,ERR_R_MALLOC_FAILURE);
return -1;
}
s->tlsext_ecpointformatlist_length = 3;
s->tlsext_ecpointformatlist[0] = TLSEXT_ECPOINTFORMAT_uncompressed;
s->tlsext_ecpointformatlist[1] = TLSEXT_ECPOINTFORMAT_ansiX962_compressed_prime;
s->tlsext_ecpointformatlist[2] = TLSEXT_ECPOINTFORMAT_ansiX962_compressed_char2;
}
#endif
return 1;
}
int ssl_check_clienthello_tlsext(SSL *s)
{
int ret=SSL_TLSEXT_ERR_NOACK;
int al = SSL_AD_UNRECOGNIZED_NAME;
#ifndef OPENSSL_NO_EC
#endif
if (s->ctx != NULL && s->ctx->tlsext_servername_callback != 0)
ret = s->ctx->tlsext_servername_callback(s, &al, s->ctx->tlsext_servername_arg);
else if (s->initial_ctx != NULL && s->initial_ctx->tlsext_servername_callback != 0)
ret = s->initial_ctx->tlsext_servername_callback(s, &al, s->initial_ctx->tlsext_servername_arg);
if ((s->tlsext_status_type != -1) && s->ctx && s->ctx->tlsext_status_cb)
{
int r;
r = s->ctx->tlsext_status_cb(s, s->ctx->tlsext_status_arg);
switch (r)
{
case SSL_TLSEXT_ERR_NOACK:
s->tlsext_status_expected = 0;
break;
case SSL_TLSEXT_ERR_OK:
if (s->tlsext_ocsp_resp)
s->tlsext_status_expected = 1;
else
s->tlsext_status_expected = 0;
break;
case SSL_TLSEXT_ERR_ALERT_FATAL:
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_INTERNAL_ERROR;
goto err;
}
}
else
s->tlsext_status_expected = 0;
#ifdef TLSEXT_TYPE_opaque_prf_input
{
int r = 1;
if (s->ctx->tlsext_opaque_prf_input_callback != 0)
{
r = s->ctx->tlsext_opaque_prf_input_callback(s, NULL, 0, s->ctx->tlsext_opaque_prf_input_callback_arg);
if (!r)
{
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_INTERNAL_ERROR;
goto err;
}
}
if (s->s3->server_opaque_prf_input != NULL)
OPENSSL_free(s->s3->server_opaque_prf_input);
s->s3->server_opaque_prf_input = NULL;
if (s->tlsext_opaque_prf_input != NULL)
{
if (s->s3->client_opaque_prf_input != NULL &&
s->s3->client_opaque_prf_input_len == s->tlsext_opaque_prf_input_len)
{
if (s->tlsext_opaque_prf_input_len == 0)
s->s3->server_opaque_prf_input = OPENSSL_malloc(1);
else
s->s3->server_opaque_prf_input = BUF_memdup(s->tlsext_opaque_prf_input, s->tlsext_opaque_prf_input_len);
if (s->s3->server_opaque_prf_input == NULL)
{
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_INTERNAL_ERROR;
goto err;
}
s->s3->server_opaque_prf_input_len = s->tlsext_opaque_prf_input_len;
}
}
if (r == 2 && s->s3->server_opaque_prf_input == NULL)
{
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_HANDSHAKE_FAILURE;
}
}
#endif
err:
switch (ret)
{
case SSL_TLSEXT_ERR_ALERT_FATAL:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
return -1;
case SSL_TLSEXT_ERR_ALERT_WARNING:
ssl3_send_alert(s,SSL3_AL_WARNING,al);
return 1;
case SSL_TLSEXT_ERR_NOACK:
s->servername_done=0;
default:
return 1;
}
}
int ssl_check_serverhello_tlsext(SSL *s)
{
int ret=SSL_TLSEXT_ERR_NOACK;
int al = SSL_AD_UNRECOGNIZED_NAME;
#ifndef OPENSSL_NO_EC
unsigned long alg_k = s->s3->tmp.new_cipher->algorithm_mkey;
unsigned long alg_a = s->s3->tmp.new_cipher->algorithm_auth;
if ((s->tlsext_ecpointformatlist != NULL) && (s->tlsext_ecpointformatlist_length > 0) &&
((alg_k & (SSL_kEECDH|SSL_kECDHr|SSL_kECDHe)) || (alg_a & SSL_aECDSA)))
{
size_t i;
unsigned char *list;
int found_uncompressed = 0;
if ((s->session->tlsext_ecpointformatlist == NULL) || (s->session->tlsext_ecpointformatlist_length == 0))
{
SSLerr(SSL_F_SSL_CHECK_SERVERHELLO_TLSEXT,SSL_R_TLS_INVALID_ECPOINTFORMAT_LIST);
return -1;
}
list = s->session->tlsext_ecpointformatlist;
for (i = 0; i < s->session->tlsext_ecpointformatlist_length; i++)
{
if (*(list++) == TLSEXT_ECPOINTFORMAT_uncompressed)
{
found_uncompressed = 1;
break;
}
}
if (!found_uncompressed)
{
SSLerr(SSL_F_SSL_CHECK_SERVERHELLO_TLSEXT,SSL_R_TLS_INVALID_ECPOINTFORMAT_LIST);
return -1;
}
}
ret = SSL_TLSEXT_ERR_OK;
#endif
if (s->ctx != NULL && s->ctx->tlsext_servername_callback != 0)
ret = s->ctx->tlsext_servername_callback(s, &al, s->ctx->tlsext_servername_arg);
else if (s->initial_ctx != NULL && s->initial_ctx->tlsext_servername_callback != 0)
ret = s->initial_ctx->tlsext_servername_callback(s, &al, s->initial_ctx->tlsext_servername_arg);
#ifdef TLSEXT_TYPE_opaque_prf_input
if (s->s3->server_opaque_prf_input_len > 0)
{
if (s->s3->server_opaque_prf_input == NULL)
{
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_HANDSHAKE_FAILURE;
}
if (s->s3->client_opaque_prf_input == NULL ||
s->s3->client_opaque_prf_input_len != s->s3->server_opaque_prf_input_len)
{
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
al = SSL_AD_ILLEGAL_PARAMETER;
}
}
#endif
if ((s->tlsext_status_type != -1) && !(s->tlsext_status_expected)
&& s->ctx && s->ctx->tlsext_status_cb)
{
int r;
if (s->tlsext_ocsp_resp)
{
OPENSSL_free(s->tlsext_ocsp_resp);
s->tlsext_ocsp_resp = NULL;
}
s->tlsext_ocsp_resplen = -1;
r = s->ctx->tlsext_status_cb(s, s->ctx->tlsext_status_arg);
if (r == 0)
{
al = SSL_AD_BAD_CERTIFICATE_STATUS_RESPONSE;
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
}
if (r < 0)
{
al = SSL_AD_INTERNAL_ERROR;
ret = SSL_TLSEXT_ERR_ALERT_FATAL;
}
}
switch (ret)
{
case SSL_TLSEXT_ERR_ALERT_FATAL:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
return -1;
case SSL_TLSEXT_ERR_ALERT_WARNING:
ssl3_send_alert(s,SSL3_AL_WARNING,al);
return 1;
case SSL_TLSEXT_ERR_NOACK:
s->servername_done=0;
default:
return 1;
}
}
int tls1_process_ticket(SSL *s, unsigned char *session_id, int len,
const unsigned char *limit, SSL_SESSION **ret)
{
const unsigned char *p = session_id + len;
unsigned short i;
if (SSL_get_options(s) & SSL_OP_NO_TICKET)
return 1;
if ((s->version <= SSL3_VERSION) || !limit)
return 1;
if (p >= limit)
return -1;
if (s->version == DTLS1_VERSION || s->version == DTLS1_BAD_VER)
{
i = *(p++);
p+= i;
if (p >= limit)
return -1;
}
n2s(p, i);
p+= i;
if (p >= limit)
return -1;
i = *(p++);
p += i;
if (p > limit)
return -1;
if ((p + 2) >= limit)
return 1;
n2s(p, i);
while ((p + 4) <= limit)
{
unsigned short type, size;
n2s(p, type);
n2s(p, size);
if (p + size > limit)
return 1;
if (type == TLSEXT_TYPE_session_ticket)
{
if (SSL_get_options(s) & SSL_OP_NO_TICKET)
return 1;
if (size == 0)
{
s->tlsext_ticket_expected = 1;
return 0;
}
if (s->tls_session_secret_cb)
{
return 0;
}
return tls_decrypt_ticket(s, p, size, session_id, len,
ret);
}
p += size;
}
return 1;
}
static int tls_decrypt_ticket(SSL *s, const unsigned char *etick, int eticklen,
const unsigned char *sess_id, int sesslen,
SSL_SESSION **psess)
{
SSL_SESSION *sess;
unsigned char *sdec;
const unsigned char *p;
int slen, mlen, renew_ticket = 0;
unsigned char tick_hmac[EVP_MAX_MD_SIZE];
HMAC_CTX hctx;
EVP_CIPHER_CTX ctx;
SSL_CTX *tctx = s->initial_ctx;
if (eticklen < 48)
goto tickerr;
HMAC_CTX_init(&hctx);
EVP_CIPHER_CTX_init(&ctx);
if (tctx->tlsext_ticket_key_cb)
{
unsigned char *nctick = (unsigned char *)etick;
int rv = tctx->tlsext_ticket_key_cb(s, nctick, nctick + 16,
&ctx, &hctx, 0);
if (rv < 0)
return -1;
if (rv == 0)
goto tickerr;
if (rv == 2)
renew_ticket = 1;
}
else
{
if (memcmp(etick, tctx->tlsext_tick_key_name, 16))
goto tickerr;
HMAC_Init_ex(&hctx, tctx->tlsext_tick_hmac_key, 16,
tlsext_tick_md(), NULL);
EVP_DecryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL,
tctx->tlsext_tick_aes_key, etick + 16);
}
mlen = HMAC_size(&hctx);
if (mlen < 0)
{
EVP_CIPHER_CTX_cleanup(&ctx);
return -1;
}
eticklen -= mlen;
HMAC_Update(&hctx, etick, eticklen);
HMAC_Final(&hctx, tick_hmac, NULL);
HMAC_CTX_cleanup(&hctx);
if (memcmp(tick_hmac, etick + eticklen, mlen))
goto tickerr;
p = etick + 16 + EVP_CIPHER_CTX_iv_length(&ctx);
eticklen -= 16 + EVP_CIPHER_CTX_iv_length(&ctx);
sdec = OPENSSL_malloc(eticklen);
if (!sdec)
{
EVP_CIPHER_CTX_cleanup(&ctx);
return -1;
}
EVP_DecryptUpdate(&ctx, sdec, &slen, p, eticklen);
if (EVP_DecryptFinal(&ctx, sdec + slen, &mlen) <= 0)
goto tickerr;
slen += mlen;
EVP_CIPHER_CTX_cleanup(&ctx);
p = sdec;
sess = d2i_SSL_SESSION(NULL, &p, slen);
OPENSSL_free(sdec);
if (sess)
{
if (sesslen)
memcpy(sess->session_id, sess_id, sesslen);
sess->session_id_length = sesslen;
*psess = sess;
s->tlsext_ticket_expected = renew_ticket;
return 1;
}
tickerr:
s->tlsext_ticket_expected = 1;
return 0;
}
