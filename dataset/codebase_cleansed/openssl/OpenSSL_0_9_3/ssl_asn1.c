int i2d_SSL_SESSION(SSL_SESSION *in, unsigned char **pp)
{
#define LSIZE2 (sizeof(long)*2)
int v1=0,v2=0,v3=0,v4=0;
unsigned char buf[4],ibuf1[LSIZE2],ibuf2[LSIZE2];
unsigned char ibuf3[LSIZE2],ibuf4[LSIZE2];
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
M_ASN1_I2D_len(&(a.version), i2d_ASN1_INTEGER);
M_ASN1_I2D_len(&(a.ssl_version), i2d_ASN1_INTEGER);
M_ASN1_I2D_len(&(a.cipher), i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_len(&(a.session_id), i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_len(&(a.master_key), i2d_ASN1_OCTET_STRING);
if (in->key_arg_length > 0)
M_ASN1_I2D_len_IMP_opt(&(a.key_arg),i2d_ASN1_OCTET_STRING);
if (in->time != 0L)
M_ASN1_I2D_len_EXP_opt(&(a.time),i2d_ASN1_INTEGER,1,v1);
if (in->timeout != 0L)
M_ASN1_I2D_len_EXP_opt(&(a.timeout),i2d_ASN1_INTEGER,2,v2);
if (in->peer != NULL)
M_ASN1_I2D_len_EXP_opt(in->peer,i2d_X509,3,v3);
M_ASN1_I2D_len_EXP_opt(&a.session_id_context,i2d_ASN1_OCTET_STRING,4,v4);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(&(a.version), i2d_ASN1_INTEGER);
M_ASN1_I2D_put(&(a.ssl_version), i2d_ASN1_INTEGER);
M_ASN1_I2D_put(&(a.cipher), i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_put(&(a.session_id), i2d_ASN1_OCTET_STRING);
M_ASN1_I2D_put(&(a.master_key), i2d_ASN1_OCTET_STRING);
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
M_ASN1_I2D_finish();
}
SSL_SESSION *d2i_SSL_SESSION(SSL_SESSION **a, unsigned char **pp,
long length)
{
int version,ssl_version=0,i;
long id;
ASN1_INTEGER ai,*aip;
ASN1_OCTET_STRING os,*osp;
M_ASN1_D2I_vars(a,SSL_SESSION *,SSL_SESSION_new);
aip= &ai;
osp= &os;
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
ai.data=NULL; ai.length=0;
M_ASN1_D2I_get(aip,d2i_ASN1_INTEGER);
version=(int)ASN1_INTEGER_get(aip);
if (ai.data != NULL) { Free(ai.data); ai.data=NULL; ai.length=0; }
M_ASN1_D2I_get(aip,d2i_ASN1_INTEGER);
ssl_version=(int)ASN1_INTEGER_get(aip);
ret->ssl_version=ssl_version;
if (ai.data != NULL) { Free(ai.data); ai.data=NULL; ai.length=0; }
os.data=NULL; os.length=0;
M_ASN1_D2I_get(osp,d2i_ASN1_OCTET_STRING);
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
else if ((ssl_version>>8) == 3)
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
SSLerr(SSL_F_D2I_SSL_SESSION,SSL_R_UNKNOWN_SSL_VERSION);
return(NULL);
}
ret->cipher=NULL;
ret->cipher_id=id;
M_ASN1_D2I_get(osp,d2i_ASN1_OCTET_STRING);
if ((ssl_version>>8) == SSL3_VERSION)
i=SSL3_MAX_SSL_SESSION_ID_LENGTH;
else
i=SSL2_MAX_SSL_SESSION_ID_LENGTH;
if (os.length > i)
os.length=i;
ret->session_id_length=os.length;
memcpy(ret->session_id,os.data,os.length);
M_ASN1_D2I_get(osp,d2i_ASN1_OCTET_STRING);
if (ret->master_key_length > SSL_MAX_MASTER_KEY_LENGTH)
ret->master_key_length=SSL_MAX_MASTER_KEY_LENGTH;
else
ret->master_key_length=os.length;
memcpy(ret->master_key,os.data,ret->master_key_length);
os.length=0;
M_ASN1_D2I_get_IMP_opt(osp,d2i_ASN1_OCTET_STRING,0,V_ASN1_OCTET_STRING);
if (os.length > SSL_MAX_KEY_ARG_LENGTH)
ret->key_arg_length=SSL_MAX_KEY_ARG_LENGTH;
else
ret->key_arg_length=os.length;
memcpy(ret->key_arg,os.data,ret->key_arg_length);
if (os.data != NULL) Free(os.data);
ai.length=0;
M_ASN1_D2I_get_EXP_opt(aip,d2i_ASN1_INTEGER,1);
if (ai.data != NULL)
{
ret->time=ASN1_INTEGER_get(aip);
Free(ai.data); ai.data=NULL; ai.length=0;
}
else
ret->time=time(NULL);
ai.length=0;
M_ASN1_D2I_get_EXP_opt(aip,d2i_ASN1_INTEGER,2);
if (ai.data != NULL)
{
ret->timeout=ASN1_INTEGER_get(aip);
Free(ai.data); ai.data=NULL; ai.length=0;
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
SSLerr(SSL_F_D2I_SSL_SESSION,SSL_R_BAD_LENGTH);
ret->sid_ctx_length=os.length;
memcpy(ret->sid_ctx,os.data,os.length);
Free(os.data); os.data=NULL; os.length=0;
}
else
ret->sid_ctx_length=0;
M_ASN1_D2I_Finish(a,SSL_SESSION_free,SSL_F_D2I_SSL_SESSION);
}
