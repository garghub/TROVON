int i2d_SSL_SESSION(SSL_SESSION *in, unsigned char **pp)
{
#define LSIZE2 (sizeof(long)*2)
int v1=0,v2=0,v3=0,v4=0,v5=0,v7=0,v8=0;
unsigned char buf[4],ibuf1[LSIZE2],ibuf2[LSIZE2];
unsigned char ibuf3[LSIZE2],ibuf4[LSIZE2],ibuf5[LSIZE2];
#ifndef OPENSSL_NO_TLSEXT
int v6=0,v9=0,v10=0;
unsigned char ibuf6[LSIZE2];
#endif
#ifndef OPENSSL_NO_COMP
unsigned char cbuf;
int v11=0;
#endif
#ifndef OPENSSL_NO_SRP
int v12=0;
#endif
long l;
SSL_SESSION_ASN1 a;
M_ASN1_I2D_vars(in);
if ((in == NULL) || ((in->cipher == NULL) && (in->cipher_id == 0)))
return(0);
a.version.length=LSIZE2;
a.version.type=V_ASN1_INTEGER;
a.version.data=ibuf1;
ASN1_INTEGER_set(&(a.version),SSL_SESSION_ASN1_VERSION);
a.ssl_version.length=LSIZE2;
a.ssl_version.type=V_ASN1_INTEGER;
a.ssl_version.data=ibuf2;
ASN1_INTEGER_set(&(a.ssl_version),in->ssl_version);
a.cipher.type=V_ASN1_OCTET_STRING;
a.cipher.data=buf;
if (in->cipher == NULL)
l=in->cipher_id;
else
l=in->cipher->id;
if (in->ssl_version == SSL2_VERSION)
{
a.cipher.length=3;
buf[0]=((unsigned char)(l>>16L))&0xff;
buf[1]=((unsigned char)(l>> 8L))&0xff;
buf[2]=((unsigned char)(l ))&0xff;
}
else
{
a.cipher.length=2;
buf[0]=((unsigned char)(l>>8L))&0xff;
buf[1]=((unsigned char)(l ))&0xff;
}
#ifndef OPENSSL_NO_COMP
if (in->compress_meth)
{
cbuf = (unsigned char)in->compress_meth;
a.comp_id.length = 1;
a.comp_id.type = V_ASN1_OCTET_STRING;
a.comp_id.data = &cbuf;
}
#endif
a.master_key.length=in->master_key_length;
a.master_key.type=V_ASN1_OCTET_STRING;
a.master_key.data=in->master_key;
a.session_id.length=in->session_id_length;
a.session_id.type=V_ASN1_OCTET_STRING;
a.session_id.data=in->session_id;
a.session_id_context.length=in->sid_ctx_length;
a.session_id_context.type=V_ASN1_OCTET_STRING;
a.session_id_context.data=in->sid_ctx;
a.key_arg.length=in->key_arg_length;
a.key_arg.type=V_ASN1_OCTET_STRING;
a.key_arg.data=in->key_arg;
#ifndef OPENSSL_NO_KRB5
if (in->krb5_client_princ_len)
{
a.krb5_princ.length=in->krb5_client_princ_len;
a.krb5_princ.type=V_ASN1_OCTET_STRING;
a.krb5_princ.data=in->krb5_client_princ;
}
#endif
if (in->time != 0L)
{
a.time.length=LSIZE2;
a.time.type=V_ASN1_INTEGER;
a.time.data=ibuf3;
ASN1_INTEGER_set(&(a.time),in->time);
}
if (in->timeout != 0L)
{
a.timeout.length=LSIZE2;
a.timeout.type=V_ASN1_INTEGER;
a.timeout.data=ibuf4;
ASN1_INTEGER_set(&(a.timeout),in->timeout);
}
if (in->verify_result != X509_V_OK)
{
a.verify_result.length=LSIZE2;
a.verify_result.type=V_ASN1_INTEGER;
a.verify_result.data=ibuf5;
ASN1_INTEGER_set(&a.verify_result,in->verify_result);
}
#ifndef OPENSSL_NO_TLSEXT
if (in->tlsext_hostname)
{
a.tlsext_hostname.length=strlen(in->tlsext_hostname);
a.tlsext_hostname.type=V_ASN1_OCTET_STRING;
a.tlsext_hostname.data=(unsigned char *)in->tlsext_hostname;
}
if (in->tlsext_tick)
{
a.tlsext_tick.length= in->tlsext_ticklen;
a.tlsext_tick.type=V_ASN1_OCTET_STRING;
a.tlsext_tick.data=(unsigned char *)in->tlsext_tick;
}
if (in->tlsext_tick_lifetime_hint > 0)
{
a.tlsext_tick_lifetime.length=LSIZE2;
a.tlsext_tick_lifetime.type=V_ASN1_INTEGER;
a.tlsext_tick_lifetime.data=ibuf6;
ASN1_INTEGER_set(&a.tlsext_tick_lifetime,in->tlsext_tick_lifetime_hint);
}
#endif
#ifndef OPENSSL_NO_PSK
if (in->psk_identity_hint)
{
a.psk_identity_hint.length=strlen(in->psk_identity_hint);
a.psk_identity_hint.type=V_ASN1_OCTET_STRING;
a.psk_identity_hint.data=(unsigned char *)(in->psk_identity_hint);
}
if (in->psk_identity)
{
a.psk_identity.length=strlen(in->psk_identity);
a.psk_identity.type=V_ASN1_OCTET_STRING;
a.psk_identity.data=(unsigned char *)(in->psk_identity);
}
#endif
#ifndef OPENSSL_NO_SRP
if (in->srp_username)
{
a.srp_username.length=strlen(in->srp_username);
a.srp_username.type=V_ASN1_OCTET_STRING;
a.srp_username.data=(unsigned char *)(in->srp_username);
}
#endif
M_ASN1_I2D_len(&(a.version), i2d_ASN1_INTEGER);
M_ASN1_I2D_len(&(a.ssl_version), i2d_ASN1_INTEGER);
M_ASN1_I2D_len(&(a.cipher), i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_len(&(a.session_id), i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_len(&(a.master_key), i2d_ASN1_OCTET_STRING);
#ifndef OPENSSL_NO_KRB5
if (in->krb5_client_princ_len)
M_ASN1_I2D_len(&(a.krb5_princ), i2d_ASN1_OCTET_STRING);
#endif
if (in->key_arg_length > 0)
M_ASN1_I2D_len_IMP_opt(&(a.key_arg),i2d_ASN1_OCTET_STRING);
if (in->time != 0L)
M_ASN1_I2D_len_EXP_opt(&(a.time),i2d_ASN1_INTEGER,1,v1);
if (in->timeout != 0L)
M_ASN1_I2D_len_EXP_opt(&(a.timeout),i2d_ASN1_INTEGER,2,v2);
if (in->peer != NULL)
M_ASN1_I2D_len_EXP_opt(in->peer,i2d_X509,3,v3);
M_ASN1_I2D_len_EXP_opt(&a.session_id_context,i2d_ASN1_OCTET_STRING,4,v4);
if (in->verify_result != X509_V_OK)
M_ASN1_I2D_len_EXP_opt(&(a.verify_result),i2d_ASN1_INTEGER,5,v5);
#ifndef OPENSSL_NO_TLSEXT
if (in->tlsext_tick_lifetime_hint > 0)
M_ASN1_I2D_len_EXP_opt(&a.tlsext_tick_lifetime, i2d_ASN1_INTEGER,9,v9);
if (in->tlsext_tick)
M_ASN1_I2D_len_EXP_opt(&(a.tlsext_tick), i2d_ASN1_OCTET_STRING,10,v10);
if (in->tlsext_hostname)
M_ASN1_I2D_len_EXP_opt(&(a.tlsext_hostname), i2d_ASN1_OCTET_STRING,6,v6);
#ifndef OPENSSL_NO_COMP
if (in->compress_meth)
M_ASN1_I2D_len_EXP_opt(&(a.comp_id), i2d_ASN1_OCTET_STRING,11,v11);
#endif
#endif
#ifndef OPENSSL_NO_PSK
if (in->psk_identity_hint)
M_ASN1_I2D_len_EXP_opt(&(a.psk_identity_hint), i2d_ASN1_OCTET_STRING,7,v7);
if (in->psk_identity)
M_ASN1_I2D_len_EXP_opt(&(a.psk_identity), i2d_ASN1_OCTET_STRING,8,v8);
#endif
#ifndef OPENSSL_NO_SRP
if (in->srp_username)
M_ASN1_I2D_len_EXP_opt(&(a.srp_username), i2d_ASN1_OCTET_STRING,12,v12);
#endif
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(&(a.version), i2d_ASN1_INTEGER);
M_ASN1_I2D_put(&(a.ssl_version), i2d_ASN1_INTEGER);
M_ASN1_I2D_put(&(a.cipher), i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_put(&(a.session_id), i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_put(&(a.master_key), i2d_ASN1_OCTET_STRING);
#ifndef OPENSSL_NO_KRB5
if (in->krb5_client_princ_len)
M_ASN1_I2D_put(&(a.krb5_princ), i2d_ASN1_OCTET_STRING);
#endif
if (in->key_arg_length > 0)
M_ASN1_I2D_put_IMP_opt(&(a.key_arg),i2d_ASN1_OCTET_STRING,0);
if (in->time != 0L)
M_ASN1_I2D_put_EXP_opt(&(a.time),i2d_ASN1_INTEGER,1,v1);
if (in->timeout != 0L)
M_ASN1_I2D_put_EXP_opt(&(a.timeout),i2d_ASN1_INTEGER,2,v2);
if (in->peer != NULL)
M_ASN1_I2D_put_EXP_opt(in->peer,i2d_X509,3,v3);
M_ASN1_I2D_put_EXP_opt(&a.session_id_context,i2d_ASN1_OCTET_STRING,4,
v4);
if (in->verify_result != X509_V_OK)
M_ASN1_I2D_put_EXP_opt(&a.verify_result,i2d_ASN1_INTEGER,5,v5);
#ifndef OPENSSL_NO_TLSEXT
if (in->tlsext_hostname)
M_ASN1_I2D_put_EXP_opt(&(a.tlsext_hostname), i2d_ASN1_OCTET_STRING,6,v6);
#endif
#ifndef OPENSSL_NO_PSK
if (in->psk_identity_hint)
M_ASN1_I2D_put_EXP_opt(&(a.psk_identity_hint), i2d_ASN1_OCTET_STRING,7,v7);
if (in->psk_identity)
M_ASN1_I2D_put_EXP_opt(&(a.psk_identity), i2d_ASN1_OCTET_STRING,8,v8);
#endif
#ifndef OPENSSL_NO_TLSEXT
if (in->tlsext_tick_lifetime_hint > 0)
M_ASN1_I2D_put_EXP_opt(&a.tlsext_tick_lifetime, i2d_ASN1_INTEGER,9,v9);
if (in->tlsext_tick)
M_ASN1_I2D_put_EXP_opt(&(a.tlsext_tick), i2d_ASN1_OCTET_STRING,10,v10);
#endif
#ifndef OPENSSL_NO_COMP
if (in->compress_meth)
M_ASN1_I2D_put_EXP_opt(&(a.comp_id), i2d_ASN1_OCTET_STRING,11,v11);
#endif
#ifndef OPENSSL_NO_SRP
if (in->srp_username)
M_ASN1_I2D_put_EXP_opt(&(a.srp_username), i2d_ASN1_OCTET_STRING,12,v12);
#endif
M_ASN1_I2D_finish();
}
SSL_SESSION *d2i_SSL_SESSION(SSL_SESSION **a, const unsigned char **pp,
long length)
{
int ssl_version=0,i;
long id;
ASN1_INTEGER ai,*aip;
ASN1_OCTET_STRING os,*osp;
M_ASN1_D2I_vars(a,SSL_SESSION *,SSL_SESSION_new);
aip= &ai;
osp= &os;
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
ai.data=NULL; ai.length=0;
M_ASN1_D2I_get_x(ASN1_INTEGER,aip,d2i_ASN1_INTEGER);
if (ai.data != NULL) { OPENSSL_free(ai.data); ai.data=NULL; ai.length=0; }
M_ASN1_D2I_get_x(ASN1_INTEGER,aip,d2i_ASN1_INTEGER);
ssl_version=(int)ASN1_INTEGER_get(aip);
ret->ssl_version=ssl_version;
if (ai.data != NULL) { OPENSSL_free(ai.data); ai.data=NULL; ai.length=0; }
os.data=NULL; os.length=0;
M_ASN1_D2I_get_x(ASN1_OCTET_STRING,osp,d2i_ASN1_OCTET_STRING);
if (ssl_version == SSL2_VERSION)
{
if (os.length != 3)
{
c.error=SSL_R_CIPHER_CODE_WRONG_LENGTH;
goto err;
}
id=0x02000000L|
((unsigned long)os.data[0]<<16L)|
((unsigned long)os.data[1]<< 8L)|
(unsigned long)os.data[2];
}
else if ((ssl_version>>8) >= SSL3_VERSION_MAJOR)
{
if (os.length != 2)
{
c.error=SSL_R_CIPHER_CODE_WRONG_LENGTH;
goto err;
}
id=0x03000000L|
((unsigned long)os.data[0]<<8L)|
(unsigned long)os.data[1];
}
else
{
c.error=SSL_R_UNKNOWN_SSL_VERSION;
goto err;
}
ret->cipher=NULL;
ret->cipher_id=id;
M_ASN1_D2I_get_x(ASN1_OCTET_STRING,osp,d2i_ASN1_OCTET_STRING);
if ((ssl_version>>8) >= SSL3_VERSION_MAJOR)
i=SSL3_MAX_SSL_SESSION_ID_LENGTH;
else
i=SSL2_MAX_SSL_SESSION_ID_LENGTH;
if (os.length > i)
os.length = i;
if (os.length > (int)sizeof(ret->session_id))
os.length = sizeof(ret->session_id);
ret->session_id_length=os.length;
OPENSSL_assert(os.length <= (int)sizeof(ret->session_id));
memcpy(ret->session_id,os.data,os.length);
M_ASN1_D2I_get_x(ASN1_OCTET_STRING,osp,d2i_ASN1_OCTET_STRING);
if (os.length > SSL_MAX_MASTER_KEY_LENGTH)
ret->master_key_length=SSL_MAX_MASTER_KEY_LENGTH;
else
ret->master_key_length=os.length;
memcpy(ret->master_key,os.data,ret->master_key_length);
os.length=0;
#ifndef OPENSSL_NO_KRB5
os.length=0;
M_ASN1_D2I_get_opt(osp,d2i_ASN1_OCTET_STRING,V_ASN1_OCTET_STRING);
if (os.data)
{
if (os.length > SSL_MAX_KRB5_PRINCIPAL_LENGTH)
ret->krb5_client_princ_len=0;
else
ret->krb5_client_princ_len=os.length;
memcpy(ret->krb5_client_princ,os.data,ret->krb5_client_princ_len);
OPENSSL_free(os.data);
os.data = NULL;
os.length = 0;
}
else
ret->krb5_client_princ_len=0;
#endif
M_ASN1_D2I_get_IMP_opt(osp,d2i_ASN1_OCTET_STRING,0,V_ASN1_OCTET_STRING);
if (os.length > SSL_MAX_KEY_ARG_LENGTH)
ret->key_arg_length=SSL_MAX_KEY_ARG_LENGTH;
else
ret->key_arg_length=os.length;
memcpy(ret->key_arg,os.data,ret->key_arg_length);
if (os.data != NULL) OPENSSL_free(os.data);
ai.length=0;
M_ASN1_D2I_get_EXP_opt(aip,d2i_ASN1_INTEGER,1);
if (ai.data != NULL)
{
ret->time=ASN1_INTEGER_get(aip);
OPENSSL_free(ai.data); ai.data=NULL; ai.length=0;
}
else
ret->time=(unsigned long)time(NULL);
ai.length=0;
M_ASN1_D2I_get_EXP_opt(aip,d2i_ASN1_INTEGER,2);
if (ai.data != NULL)
{
ret->timeout=ASN1_INTEGER_get(aip);
OPENSSL_free(ai.data); ai.data=NULL; ai.length=0;
}
else
ret->timeout=3;
if (ret->peer != NULL)
{
X509_free(ret->peer);
ret->peer=NULL;
}
M_ASN1_D2I_get_EXP_opt(ret->peer,d2i_X509,3);
os.length=0;
os.data=NULL;
M_ASN1_D2I_get_EXP_opt(osp,d2i_ASN1_OCTET_STRING,4);
if(os.data != NULL)
{
if (os.length > SSL_MAX_SID_CTX_LENGTH)
{
c.error=SSL_R_BAD_LENGTH;
goto err;
}
else
{
ret->sid_ctx_length=os.length;
memcpy(ret->sid_ctx,os.data,os.length);
}
OPENSSL_free(os.data); os.data=NULL; os.length=0;
}
else
ret->sid_ctx_length=0;
ai.length=0;
M_ASN1_D2I_get_EXP_opt(aip,d2i_ASN1_INTEGER,5);
if (ai.data != NULL)
{
ret->verify_result=ASN1_INTEGER_get(aip);
OPENSSL_free(ai.data); ai.data=NULL; ai.length=0;
}
else
ret->verify_result=X509_V_OK;
#ifndef OPENSSL_NO_TLSEXT
os.length=0;
os.data=NULL;
M_ASN1_D2I_get_EXP_opt(osp,d2i_ASN1_OCTET_STRING,6);
if (os.data)
{
ret->tlsext_hostname = BUF_strndup((char *)os.data, os.length);
OPENSSL_free(os.data);
os.data = NULL;
os.length = 0;
}
else
ret->tlsext_hostname=NULL;
#endif
#ifndef OPENSSL_NO_PSK
os.length=0;
os.data=NULL;
M_ASN1_D2I_get_EXP_opt(osp,d2i_ASN1_OCTET_STRING,7);
if (os.data)
{
ret->psk_identity_hint = BUF_strndup((char *)os.data, os.length);
OPENSSL_free(os.data);
os.data = NULL;
os.length = 0;
}
else
ret->psk_identity_hint=NULL;
os.length=0;
os.data=NULL;
M_ASN1_D2I_get_EXP_opt(osp,d2i_ASN1_OCTET_STRING,8);
if (os.data)
{
ret->psk_identity = BUF_strndup((char *)os.data, os.length);
OPENSSL_free(os.data);
os.data = NULL;
os.length = 0;
}
else
ret->psk_identity=NULL;
#endif
#ifndef OPENSSL_NO_TLSEXT
ai.length=0;
M_ASN1_D2I_get_EXP_opt(aip,d2i_ASN1_INTEGER,9);
if (ai.data != NULL)
{
ret->tlsext_tick_lifetime_hint=ASN1_INTEGER_get(aip);
OPENSSL_free(ai.data); ai.data=NULL; ai.length=0;
}
else if (ret->tlsext_ticklen && ret->session_id_length)
ret->tlsext_tick_lifetime_hint = -1;
else
ret->tlsext_tick_lifetime_hint=0;
os.length=0;
os.data=NULL;
M_ASN1_D2I_get_EXP_opt(osp,d2i_ASN1_OCTET_STRING,10);
if (os.data)
{
ret->tlsext_tick = os.data;
ret->tlsext_ticklen = os.length;
os.data = NULL;
os.length = 0;
}
else
ret->tlsext_tick=NULL;
#endif
#ifndef OPENSSL_NO_COMP
os.length=0;
os.data=NULL;
M_ASN1_D2I_get_EXP_opt(osp,d2i_ASN1_OCTET_STRING,11);
if (os.data)
{
ret->compress_meth = os.data[0];
OPENSSL_free(os.data);
os.data = NULL;
}
#endif
#ifndef OPENSSL_NO_SRP
os.length=0;
os.data=NULL;
M_ASN1_D2I_get_EXP_opt(osp,d2i_ASN1_OCTET_STRING,12);
if (os.data)
{
ret->srp_username = BUF_strndup((char *)os.data, os.length);
OPENSSL_free(os.data);
os.data = NULL;
os.length = 0;
}
else
ret->srp_username=NULL;
#endif
M_ASN1_D2I_Finish(a,SSL_SESSION_free,SSL_F_D2I_SSL_SESSION);
}
