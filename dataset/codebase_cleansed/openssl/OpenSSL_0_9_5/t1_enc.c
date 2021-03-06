static void tls1_P_hash(const EVP_MD *md, const unsigned char *sec,
int sec_len, unsigned char *seed, int seed_len,
unsigned char *out, int olen)
{
int chunk,n;
unsigned int j;
HMAC_CTX ctx;
HMAC_CTX ctx_tmp;
unsigned char A1[HMAC_MAX_MD_CBLOCK];
unsigned int A1_len;
chunk=EVP_MD_size(md);
HMAC_Init(&ctx,sec,sec_len,md);
HMAC_Update(&ctx,seed,seed_len);
HMAC_Final(&ctx,A1,&A1_len);
n=0;
for (;;)
{
HMAC_Init(&ctx,NULL,0,NULL);
HMAC_Update(&ctx,A1,A1_len);
memcpy(&ctx_tmp,&ctx,sizeof(ctx));
HMAC_Update(&ctx,seed,seed_len);
if (olen > chunk)
{
HMAC_Final(&ctx,out,&j);
out+=j;
olen-=j;
HMAC_Final(&ctx_tmp,A1,&A1_len);
}
else
{
HMAC_Final(&ctx,A1,&A1_len);
memcpy(out,A1,olen);
break;
}
}
HMAC_cleanup(&ctx);
HMAC_cleanup(&ctx_tmp);
memset(A1,0,sizeof(A1));
}
static void tls1_PRF(const EVP_MD *md5, const EVP_MD *sha1,
unsigned char *label, int label_len,
const unsigned char *sec, int slen, unsigned char *out1,
unsigned char *out2, int olen)
{
int len,i;
const unsigned char *S1,*S2;
len=slen/2;
S1=sec;
S2= &(sec[len]);
len+=(slen&1);
tls1_P_hash(md5 ,S1,len,label,label_len,out1,olen);
tls1_P_hash(sha1,S2,len,label,label_len,out2,olen);
for (i=0; i<olen; i++)
out1[i]^=out2[i];
}
static void tls1_generate_key_block(SSL *s, unsigned char *km,
unsigned char *tmp, int num)
{
unsigned char *p;
unsigned char buf[SSL3_RANDOM_SIZE*2+
TLS_MD_MAX_CONST_SIZE];
p=buf;
memcpy(p,TLS_MD_KEY_EXPANSION_CONST,
TLS_MD_KEY_EXPANSION_CONST_SIZE);
p+=TLS_MD_KEY_EXPANSION_CONST_SIZE;
memcpy(p,s->s3->server_random,SSL3_RANDOM_SIZE);
p+=SSL3_RANDOM_SIZE;
memcpy(p,s->s3->client_random,SSL3_RANDOM_SIZE);
p+=SSL3_RANDOM_SIZE;
tls1_PRF(s->ctx->md5,s->ctx->sha1,buf,(int)(p-buf),
s->session->master_key,s->session->master_key_length,
km,tmp,num);
}
int tls1_change_cipher_state(SSL *s, int which)
{
static const unsigned char empty[]="";
unsigned char *p,*key_block,*mac_secret;
unsigned char *exp_label,buf[TLS_MD_MAX_CONST_SIZE+
SSL3_RANDOM_SIZE*2];
unsigned char tmp1[EVP_MAX_KEY_LENGTH];
unsigned char tmp2[EVP_MAX_KEY_LENGTH];
unsigned char iv1[EVP_MAX_IV_LENGTH*2];
unsigned char iv2[EVP_MAX_IV_LENGTH*2];
unsigned char *ms,*key,*iv,*er1,*er2;
int client_write;
EVP_CIPHER_CTX *dd;
const EVP_CIPHER *c;
const SSL_COMP *comp;
const EVP_MD *m;
int _exp,n,i,j,k,exp_label_len,cl;
_exp=SSL_C_IS_EXPORT(s->s3->tmp.new_cipher);
c=s->s3->tmp.new_sym_enc;
m=s->s3->tmp.new_hash;
comp=s->s3->tmp.new_compression;
key_block=s->s3->tmp.key_block;
if (which & SSL3_CC_READ)
{
if ((s->enc_read_ctx == NULL) &&
((s->enc_read_ctx=(EVP_CIPHER_CTX *)
Malloc(sizeof(EVP_CIPHER_CTX))) == NULL))
goto err;
dd= s->enc_read_ctx;
s->read_hash=m;
if (s->expand != NULL)
{
COMP_CTX_free(s->expand);
s->expand=NULL;
}
if (comp != NULL)
{
s->expand=COMP_CTX_new(comp->method);
if (s->expand == NULL)
{
SSLerr(SSL_F_TLS1_CHANGE_CIPHER_STATE,SSL_R_COMPRESSION_LIBRARY_ERROR);
goto err2;
}
if (s->s3->rrec.comp == NULL)
s->s3->rrec.comp=(unsigned char *)
Malloc(SSL3_RT_MAX_ENCRYPTED_LENGTH);
if (s->s3->rrec.comp == NULL)
goto err;
}
memset(&(s->s3->read_sequence[0]),0,8);
mac_secret= &(s->s3->read_mac_secret[0]);
}
else
{
if ((s->enc_write_ctx == NULL) &&
((s->enc_write_ctx=(EVP_CIPHER_CTX *)
Malloc(sizeof(EVP_CIPHER_CTX))) == NULL))
goto err;
dd= s->enc_write_ctx;
s->write_hash=m;
if (s->compress != NULL)
{
COMP_CTX_free(s->compress);
s->compress=NULL;
}
if (comp != NULL)
{
s->compress=COMP_CTX_new(comp->method);
if (s->compress == NULL)
{
SSLerr(SSL_F_TLS1_CHANGE_CIPHER_STATE,SSL_R_COMPRESSION_LIBRARY_ERROR);
goto err2;
}
}
memset(&(s->s3->write_sequence[0]),0,8);
mac_secret= &(s->s3->write_mac_secret[0]);
}
EVP_CIPHER_CTX_init(dd);
p=s->s3->tmp.key_block;
i=EVP_MD_size(m);
cl=EVP_CIPHER_key_length(c);
j=_exp ? (cl < SSL_C_EXPORT_KEYLENGTH(s->s3->tmp.new_cipher) ?
cl : SSL_C_EXPORT_KEYLENGTH(s->s3->tmp.new_cipher)) : cl;
k=EVP_CIPHER_iv_length(c);
er1= &(s->s3->client_random[0]);
er2= &(s->s3->server_random[0]);
if ( (which == SSL3_CHANGE_CIPHER_CLIENT_WRITE) ||
(which == SSL3_CHANGE_CIPHER_SERVER_READ))
{
ms= &(p[ 0]); n=i+i;
key= &(p[ n]); n+=j+j;
iv= &(p[ n]); n+=k+k;
exp_label=(unsigned char *)TLS_MD_CLIENT_WRITE_KEY_CONST;
exp_label_len=TLS_MD_CLIENT_WRITE_KEY_CONST_SIZE;
client_write=1;
}
else
{
n=i;
ms= &(p[ n]); n+=i+j;
key= &(p[ n]); n+=j+k;
iv= &(p[ n]); n+=k;
exp_label=(unsigned char *)TLS_MD_SERVER_WRITE_KEY_CONST;
exp_label_len=TLS_MD_SERVER_WRITE_KEY_CONST_SIZE;
client_write=0;
}
if (n > s->s3->tmp.key_block_length)
{
SSLerr(SSL_F_TLS1_CHANGE_CIPHER_STATE,SSL_R_INTERNAL_ERROR);
goto err2;
}
memcpy(mac_secret,ms,i);
#ifdef TLS_DEBUG
printf("which = %04X\nmac key=",which);
{ int z; for (z=0; z<i; z++) printf("%02X%c",ms[z],((z+1)%16)?' ':'\n'); }
#endif
if (_exp)
{
p=buf;
memcpy(p,exp_label,exp_label_len);
p+=exp_label_len;
memcpy(p,s->s3->client_random,SSL3_RANDOM_SIZE);
p+=SSL3_RANDOM_SIZE;
memcpy(p,s->s3->server_random,SSL3_RANDOM_SIZE);
p+=SSL3_RANDOM_SIZE;
tls1_PRF(s->ctx->md5,s->ctx->sha1,buf,(int)(p-buf),key,j,
tmp1,tmp2,EVP_CIPHER_key_length(c));
key=tmp1;
if (k > 0)
{
p=buf;
memcpy(p,TLS_MD_IV_BLOCK_CONST,
TLS_MD_IV_BLOCK_CONST_SIZE);
p+=TLS_MD_IV_BLOCK_CONST_SIZE;
memcpy(p,s->s3->client_random,SSL3_RANDOM_SIZE);
p+=SSL3_RANDOM_SIZE;
memcpy(p,s->s3->server_random,SSL3_RANDOM_SIZE);
p+=SSL3_RANDOM_SIZE;
tls1_PRF(s->ctx->md5,s->ctx->sha1,buf,p-buf,empty,0,
iv1,iv2,k*2);
if (client_write)
iv=iv1;
else
iv= &(iv1[k]);
}
}
s->session->key_arg_length=0;
EVP_CipherInit(dd,c,key,iv,(which & SSL3_CC_WRITE));
#ifdef TLS_DEBUG
printf("which = %04X\nkey=",which);
{ int z; for (z=0; z<EVP_CIPHER_key_length(c); z++) printf("%02X%c",key[z],((z+1)%16)?' ':'\n'); }
printf("\niv=");
{ int z; for (z=0; z<k; z++) printf("%02X%c",iv[z],((z+1)%16)?' ':'\n'); }
printf("\n");
#endif
memset(tmp1,0,sizeof(tmp1));
memset(tmp2,0,sizeof(tmp1));
memset(iv1,0,sizeof(iv1));
memset(iv2,0,sizeof(iv2));
return(1);
err:
SSLerr(SSL_F_TLS1_CHANGE_CIPHER_STATE,ERR_R_MALLOC_FAILURE);
err2:
return(0);
}
int tls1_setup_key_block(SSL *s)
{
unsigned char *p1,*p2;
const EVP_CIPHER *c;
const EVP_MD *hash;
int num;
SSL_COMP *comp;
if (s->s3->tmp.key_block_length != 0)
return(1);
if (!ssl_cipher_get_evp(s->session,&c,&hash,&comp))
{
SSLerr(SSL_F_TLS1_SETUP_KEY_BLOCK,SSL_R_CIPHER_OR_HASH_UNAVAILABLE);
return(0);
}
s->s3->tmp.new_sym_enc=c;
s->s3->tmp.new_hash=hash;
num=EVP_CIPHER_key_length(c)+EVP_MD_size(hash)+EVP_CIPHER_iv_length(c);
num*=2;
ssl3_cleanup_key_block(s);
if ((p1=(unsigned char *)Malloc(num)) == NULL)
goto err;
if ((p2=(unsigned char *)Malloc(num)) == NULL)
goto err;
s->s3->tmp.key_block_length=num;
s->s3->tmp.key_block=p1;
#ifdef TLS_DEBUG
printf("client random\n");
{ int z; for (z=0; z<SSL3_RANDOM_SIZE; z++) printf("%02X%c",s->s3->client_random[z],((z+1)%16)?' ':'\n'); }
printf("server random\n");
{ int z; for (z=0; z<SSL3_RANDOM_SIZE; z++) printf("%02X%c",s->s3->server_random[z],((z+1)%16)?' ':'\n'); }
printf("pre-master\n");
{ int z; for (z=0; z<s->session->master_key_length; z++) printf("%02X%c",s->session->master_key[z],((z+1)%16)?' ':'\n'); }
#endif
tls1_generate_key_block(s,p1,p2,num);
memset(p2,0,num);
Free(p2);
#ifdef TLS_DEBUG
printf("\nkey block\n");
{ int z; for (z=0; z<num; z++) printf("%02X%c",p1[z],((z+1)%16)?' ':'\n'); }
#endif
return(1);
err:
SSLerr(SSL_F_TLS1_SETUP_KEY_BLOCK,ERR_R_MALLOC_FAILURE);
return(0);
}
int tls1_enc(SSL *s, int send)
{
SSL3_RECORD *rec;
EVP_CIPHER_CTX *ds;
unsigned long l;
int bs,i,ii,j,k,n=0;
const EVP_CIPHER *enc;
if (send)
{
if (s->write_hash != NULL)
n=EVP_MD_size(s->write_hash);
ds=s->enc_write_ctx;
rec= &(s->s3->wrec);
if (s->enc_write_ctx == NULL)
enc=NULL;
else
enc=EVP_CIPHER_CTX_cipher(s->enc_write_ctx);
}
else
{
if (s->read_hash != NULL)
n=EVP_MD_size(s->read_hash);
ds=s->enc_read_ctx;
rec= &(s->s3->rrec);
if (s->enc_read_ctx == NULL)
enc=NULL;
else
enc=EVP_CIPHER_CTX_cipher(s->enc_read_ctx);
}
if ((s->session == NULL) || (ds == NULL) ||
(enc == NULL))
{
memcpy(rec->data,rec->input,rec->length);
rec->input=rec->data;
}
else
{
l=rec->length;
bs=EVP_CIPHER_block_size(ds->cipher);
if ((bs != 1) && send)
{
i=bs-((int)l%bs);
j=i-1;
if (s->options & SSL_OP_TLS_BLOCK_PADDING_BUG)
{
if (s->s3->flags & TLS1_FLAGS_TLS_PADDING_BUG)
j++;
}
for (k=(int)l; k<(int)(l+i); k++)
rec->input[k]=j;
l+=i;
rec->length+=i;
}
EVP_Cipher(ds,rec->data,rec->input,l);
if ((bs != 1) && !send)
{
ii=i=rec->data[l-1];
i++;
if (s->options&SSL_OP_TLS_BLOCK_PADDING_BUG)
{
if ((memcmp(s->s3->read_sequence,
"\0\0\0\0\0\0\0\0",8) == 0) && !(ii & 1))
s->s3->flags|=TLS1_FLAGS_TLS_PADDING_BUG;
if (s->s3->flags & TLS1_FLAGS_TLS_PADDING_BUG)
i--;
}
if (i > (int)rec->length)
{
SSLerr(SSL_F_TLS1_ENC,SSL_R_BLOCK_CIPHER_PAD_IS_WRONG);
ssl3_send_alert(s,SSL3_AL_FATAL,SSL_AD_DECRYPTION_FAILED);
return(0);
}
for (j=(int)(l-i); j<(int)l; j++)
{
if (rec->data[j] != ii)
{
SSLerr(SSL_F_TLS1_ENC,SSL_R_DECRYPTION_FAILED);
ssl3_send_alert(s,SSL3_AL_FATAL,SSL_AD_DECRYPTION_FAILED);
return(0);
}
}
rec->length-=i;
}
}
return(1);
}
int tls1_cert_verify_mac(SSL *s, EVP_MD_CTX *in_ctx, unsigned char *out)
{
unsigned int ret;
EVP_MD_CTX ctx;
EVP_MD_CTX_copy(&ctx,in_ctx);
EVP_DigestFinal(&ctx,out,&ret);
return((int)ret);
}
int tls1_final_finish_mac(SSL *s, EVP_MD_CTX *in1_ctx, EVP_MD_CTX *in2_ctx,
const char *str, int slen, unsigned char *out)
{
unsigned int i;
EVP_MD_CTX ctx;
unsigned char buf[TLS_MD_MAX_CONST_SIZE+MD5_DIGEST_LENGTH+SHA_DIGEST_LENGTH];
unsigned char *q,buf2[12];
q=buf;
memcpy(q,str,slen);
q+=slen;
EVP_MD_CTX_copy(&ctx,in1_ctx);
EVP_DigestFinal(&ctx,q,&i);
q+=i;
EVP_MD_CTX_copy(&ctx,in2_ctx);
EVP_DigestFinal(&ctx,q,&i);
q+=i;
tls1_PRF(s->ctx->md5,s->ctx->sha1,buf,(int)(q-buf),
s->session->master_key,s->session->master_key_length,
out,buf2,12);
memset(&ctx,0,sizeof(EVP_MD_CTX));
return((int)12);
}
int tls1_mac(SSL *ssl, unsigned char *md, int send)
{
SSL3_RECORD *rec;
unsigned char *mac_sec,*seq;
const EVP_MD *hash;
unsigned int md_size;
int i;
HMAC_CTX hmac;
unsigned char buf[5];
if (send)
{
rec= &(ssl->s3->wrec);
mac_sec= &(ssl->s3->write_mac_secret[0]);
seq= &(ssl->s3->write_sequence[0]);
hash=ssl->write_hash;
}
else
{
rec= &(ssl->s3->rrec);
mac_sec= &(ssl->s3->read_mac_secret[0]);
seq= &(ssl->s3->read_sequence[0]);
hash=ssl->read_hash;
}
md_size=EVP_MD_size(hash);
buf[0]=rec->type;
buf[1]=TLS1_VERSION_MAJOR;
buf[2]=TLS1_VERSION_MINOR;
buf[3]=rec->length>>8;
buf[4]=rec->length&0xff;
HMAC_Init(&hmac,mac_sec,EVP_MD_size(hash),hash);
HMAC_Update(&hmac,seq,8);
HMAC_Update(&hmac,buf,5);
HMAC_Update(&hmac,rec->input,rec->length);
HMAC_Final(&hmac,md,&md_size);
#ifdef TLS_DEBUG
printf("sec=");
{unsigned int z; for (z=0; z<md_size; z++) printf("%02X ",mac_sec[z]); printf("\n"); }
printf("seq=");
{int z; for (z=0; z<8; z++) printf("%02X ",seq[z]); printf("\n"); }
printf("buf=");
{int z; for (z=0; z<5; z++) printf("%02X ",buf[z]); printf("\n"); }
printf("rec=");
{unsigned int z; for (z=0; z<rec->length; z++) printf("%02X ",buf[z]); printf("\n"); }
#endif
for (i=7; i>=0; i--)
if (++seq[i]) break;
#ifdef TLS_DEBUG
{unsigned int z; for (z=0; z<md_size; z++) printf("%02X ",md[z]); printf("\n"); }
#endif
return(md_size);
}
int tls1_generate_master_secret(SSL *s, unsigned char *out, unsigned char *p,
int len)
{
unsigned char buf[SSL3_RANDOM_SIZE*2+TLS_MD_MASTER_SECRET_CONST_SIZE];
unsigned char buff[SSL_MAX_MASTER_KEY_LENGTH];
memcpy(buf,TLS_MD_MASTER_SECRET_CONST,
TLS_MD_MASTER_SECRET_CONST_SIZE);
memcpy(&(buf[TLS_MD_MASTER_SECRET_CONST_SIZE]),
s->s3->client_random,SSL3_RANDOM_SIZE);
memcpy(&(buf[SSL3_RANDOM_SIZE+TLS_MD_MASTER_SECRET_CONST_SIZE]),
s->s3->server_random,SSL3_RANDOM_SIZE);
tls1_PRF(s->ctx->md5,s->ctx->sha1,
buf,TLS_MD_MASTER_SECRET_CONST_SIZE+SSL3_RANDOM_SIZE*2,p,len,
s->session->master_key,buff,SSL3_MASTER_SECRET_SIZE);
return(SSL3_MASTER_SECRET_SIZE);
}
int tls1_alert_code(int code)
{
switch (code)
{
case SSL_AD_CLOSE_NOTIFY: return(SSL3_AD_CLOSE_NOTIFY);
case SSL_AD_UNEXPECTED_MESSAGE: return(SSL3_AD_UNEXPECTED_MESSAGE);
case SSL_AD_BAD_RECORD_MAC: return(SSL3_AD_BAD_RECORD_MAC);
case SSL_AD_DECRYPTION_FAILED: return(TLS1_AD_DECRYPTION_FAILED);
case SSL_AD_RECORD_OVERFLOW: return(TLS1_AD_RECORD_OVERFLOW);
case SSL_AD_DECOMPRESSION_FAILURE:return(SSL3_AD_DECOMPRESSION_FAILURE);
case SSL_AD_HANDSHAKE_FAILURE: return(SSL3_AD_HANDSHAKE_FAILURE);
case SSL_AD_NO_CERTIFICATE: return(-1);
case SSL_AD_BAD_CERTIFICATE: return(SSL3_AD_BAD_CERTIFICATE);
case SSL_AD_UNSUPPORTED_CERTIFICATE:return(SSL3_AD_UNSUPPORTED_CERTIFICATE);
case SSL_AD_CERTIFICATE_REVOKED:return(SSL3_AD_CERTIFICATE_REVOKED);
case SSL_AD_CERTIFICATE_EXPIRED:return(SSL3_AD_CERTIFICATE_EXPIRED);
case SSL_AD_CERTIFICATE_UNKNOWN:return(SSL3_AD_CERTIFICATE_UNKNOWN);
case SSL_AD_ILLEGAL_PARAMETER: return(SSL3_AD_ILLEGAL_PARAMETER);
case SSL_AD_UNKNOWN_CA: return(TLS1_AD_UNKNOWN_CA);
case SSL_AD_ACCESS_DENIED: return(TLS1_AD_ACCESS_DENIED);
case SSL_AD_DECODE_ERROR: return(TLS1_AD_DECODE_ERROR);
case SSL_AD_DECRYPT_ERROR: return(TLS1_AD_DECRYPT_ERROR);
case SSL_AD_EXPORT_RESTRICTION: return(TLS1_AD_EXPORT_RESTRICTION);
case SSL_AD_PROTOCOL_VERSION: return(TLS1_AD_PROTOCOL_VERSION);
case SSL_AD_INSUFFICIENT_SECURITY:return(TLS1_AD_INSUFFICIENT_SECURITY);
case SSL_AD_INTERNAL_ERROR: return(TLS1_AD_INTERNAL_ERROR);
case SSL_AD_USER_CANCELLED: return(TLS1_AD_USER_CANCELLED);
case SSL_AD_NO_RENEGOTIATION: return(TLS1_AD_NO_RENEGOTIATION);
default: return(-1);
}
}
