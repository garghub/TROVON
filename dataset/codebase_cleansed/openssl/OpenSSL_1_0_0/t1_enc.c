static void tls1_P_hash(const EVP_MD *md, const unsigned char *sec,
int sec_len,
const void *seed1, int seed1_len,
const void *seed2, int seed2_len,
const void *seed3, int seed3_len,
const void *seed4, int seed4_len,
const void *seed5, int seed5_len,
unsigned char *out, int olen)
{
int chunk,n;
unsigned int j;
HMAC_CTX ctx;
HMAC_CTX ctx_tmp;
unsigned char A1[EVP_MAX_MD_SIZE];
unsigned int A1_len;
chunk=EVP_MD_size(md);
OPENSSL_assert(chunk >= 0);
HMAC_CTX_init(&ctx);
HMAC_CTX_init(&ctx_tmp);
HMAC_Init_ex(&ctx,sec,sec_len,md, NULL);
HMAC_Init_ex(&ctx_tmp,sec,sec_len,md, NULL);
if (seed1 != NULL) HMAC_Update(&ctx,seed1,seed1_len);
if (seed2 != NULL) HMAC_Update(&ctx,seed2,seed2_len);
if (seed3 != NULL) HMAC_Update(&ctx,seed3,seed3_len);
if (seed4 != NULL) HMAC_Update(&ctx,seed4,seed4_len);
if (seed5 != NULL) HMAC_Update(&ctx,seed5,seed5_len);
HMAC_Final(&ctx,A1,&A1_len);
n=0;
for (;;)
{
HMAC_Init_ex(&ctx,NULL,0,NULL,NULL);
HMAC_Init_ex(&ctx_tmp,NULL,0,NULL,NULL);
HMAC_Update(&ctx,A1,A1_len);
HMAC_Update(&ctx_tmp,A1,A1_len);
if (seed1 != NULL) HMAC_Update(&ctx,seed1,seed1_len);
if (seed2 != NULL) HMAC_Update(&ctx,seed2,seed2_len);
if (seed3 != NULL) HMAC_Update(&ctx,seed3,seed3_len);
if (seed4 != NULL) HMAC_Update(&ctx,seed4,seed4_len);
if (seed5 != NULL) HMAC_Update(&ctx,seed5,seed5_len);
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
HMAC_CTX_cleanup(&ctx);
HMAC_CTX_cleanup(&ctx_tmp);
OPENSSL_cleanse(A1,sizeof(A1));
}
static void tls1_PRF(long digest_mask,
const void *seed1, int seed1_len,
const void *seed2, int seed2_len,
const void *seed3, int seed3_len,
const void *seed4, int seed4_len,
const void *seed5, int seed5_len,
const unsigned char *sec, int slen,
unsigned char *out1,
unsigned char *out2, int olen)
{
int len,i,idx,count;
const unsigned char *S1;
long m;
const EVP_MD *md;
count=0;
for (idx=0;ssl_get_handshake_digest(idx,&m,&md);idx++) {
if ((m<<TLS1_PRF_DGST_SHIFT) & digest_mask) count++;
}
len=slen/count;
S1=sec;
memset(out1,0,olen);
for (idx=0;ssl_get_handshake_digest(idx,&m,&md);idx++) {
if ((m<<TLS1_PRF_DGST_SHIFT) & digest_mask) {
if (!md) {
SSLerr(SSL_F_TLS1_PRF,
SSL_R_UNSUPPORTED_DIGEST_TYPE);
return;
}
tls1_P_hash(md ,S1,len+(slen&1),
seed1,seed1_len,seed2,seed2_len,seed3,seed3_len,seed4,seed4_len,seed5,seed5_len,
out2,olen);
S1+=len;
for (i=0; i<olen; i++)
{
out1[i]^=out2[i];
}
}
}
}
static void tls1_generate_key_block(SSL *s, unsigned char *km,
unsigned char *tmp, int num)
{
tls1_PRF(s->s3->tmp.new_cipher->algorithm2,
TLS_MD_KEY_EXPANSION_CONST,TLS_MD_KEY_EXPANSION_CONST_SIZE,
s->s3->server_random,SSL3_RANDOM_SIZE,
s->s3->client_random,SSL3_RANDOM_SIZE,
NULL,0,NULL,0,
s->session->master_key,s->session->master_key_length,
km,tmp,num);
#ifdef KSSL_DEBUG
printf("tls1_generate_key_block() ==> %d byte master_key =\n\t",
s->session->master_key_length);
{
int i;
for (i=0; i < s->session->master_key_length; i++)
{
printf("%02X", s->session->master_key[i]);
}
printf("\n"); }
#endif
}
int tls1_change_cipher_state(SSL *s, int which)
{
static const unsigned char empty[]="";
unsigned char *p,*key_block,*mac_secret;
unsigned char *exp_label;
unsigned char tmp1[EVP_MAX_KEY_LENGTH];
unsigned char tmp2[EVP_MAX_KEY_LENGTH];
unsigned char iv1[EVP_MAX_IV_LENGTH*2];
unsigned char iv2[EVP_MAX_IV_LENGTH*2];
unsigned char *ms,*key,*iv,*er1,*er2;
int client_write;
EVP_CIPHER_CTX *dd;
const EVP_CIPHER *c;
#ifndef OPENSSL_NO_COMP
const SSL_COMP *comp;
#endif
const EVP_MD *m;
int mac_type;
int *mac_secret_size;
EVP_MD_CTX *mac_ctx;
EVP_PKEY *mac_key;
int is_export,n,i,j,k,exp_label_len,cl;
int reuse_dd = 0;
is_export=SSL_C_IS_EXPORT(s->s3->tmp.new_cipher);
c=s->s3->tmp.new_sym_enc;
m=s->s3->tmp.new_hash;
mac_type = s->s3->tmp.new_mac_pkey_type;
#ifndef OPENSSL_NO_COMP
comp=s->s3->tmp.new_compression;
#endif
key_block=s->s3->tmp.key_block;
#ifdef KSSL_DEBUG
printf("tls1_change_cipher_state(which= %d) w/\n", which);
printf("\talg= %ld/%ld, comp= %p\n",
s->s3->tmp.new_cipher->algorithm_mkey,
s->s3->tmp.new_cipher->algorithm_auth,
comp);
printf("\tevp_cipher == %p ==? &d_cbc_ede_cipher3\n", c);
printf("\tevp_cipher: nid, blksz= %d, %d, keylen=%d, ivlen=%d\n",
c->nid,c->block_size,c->key_len,c->iv_len);
printf("\tkey_block: len= %d, data= ", s->s3->tmp.key_block_length);
{
int i;
for (i=0; i<s->s3->tmp.key_block_length; i++)
printf("%02x", key_block[i]); printf("\n");
}
#endif
if (which & SSL3_CC_READ)
{
if (s->s3->tmp.new_cipher->algorithm2 & TLS1_STREAM_MAC)
s->mac_flags |= SSL_MAC_FLAG_READ_MAC_STREAM;
else
s->mac_flags &= ~SSL_MAC_FLAG_READ_MAC_STREAM;
if (s->enc_read_ctx != NULL)
reuse_dd = 1;
else if ((s->enc_read_ctx=OPENSSL_malloc(sizeof(EVP_CIPHER_CTX))) == NULL)
goto err;
else
EVP_CIPHER_CTX_init(s->enc_read_ctx);
dd= s->enc_read_ctx;
mac_ctx=ssl_replace_hash(&s->read_hash,NULL);
#ifndef OPENSSL_NO_COMP
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
OPENSSL_malloc(SSL3_RT_MAX_ENCRYPTED_LENGTH);
if (s->s3->rrec.comp == NULL)
goto err;
}
#endif
if (s->version != DTLS1_VERSION)
memset(&(s->s3->read_sequence[0]),0,8);
mac_secret= &(s->s3->read_mac_secret[0]);
mac_secret_size=&(s->s3->read_mac_secret_size);
}
else
{
if (s->s3->tmp.new_cipher->algorithm2 & TLS1_STREAM_MAC)
s->mac_flags |= SSL_MAC_FLAG_WRITE_MAC_STREAM;
else
s->mac_flags &= ~SSL_MAC_FLAG_WRITE_MAC_STREAM;
if (s->enc_write_ctx != NULL)
reuse_dd = 1;
else if ((s->enc_write_ctx=OPENSSL_malloc(sizeof(EVP_CIPHER_CTX))) == NULL)
goto err;
else
EVP_CIPHER_CTX_init(s->enc_write_ctx);
dd= s->enc_write_ctx;
mac_ctx = ssl_replace_hash(&s->write_hash,NULL);
#ifndef OPENSSL_NO_COMP
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
#endif
if (s->version != DTLS1_VERSION)
memset(&(s->s3->write_sequence[0]),0,8);
mac_secret= &(s->s3->write_mac_secret[0]);
mac_secret_size = &(s->s3->write_mac_secret_size);
}
if (reuse_dd)
EVP_CIPHER_CTX_cleanup(dd);
p=s->s3->tmp.key_block;
i=*mac_secret_size=s->s3->tmp.new_mac_secret_size;
cl=EVP_CIPHER_key_length(c);
j=is_export ? (cl < SSL_C_EXPORT_KEYLENGTH(s->s3->tmp.new_cipher) ?
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
SSLerr(SSL_F_TLS1_CHANGE_CIPHER_STATE,ERR_R_INTERNAL_ERROR);
goto err2;
}
memcpy(mac_secret,ms,i);
mac_key = EVP_PKEY_new_mac_key(mac_type, NULL,
mac_secret,*mac_secret_size);
EVP_DigestSignInit(mac_ctx,NULL,m,NULL,mac_key);
EVP_PKEY_free(mac_key);
#ifdef TLS_DEBUG
printf("which = %04X\nmac key=",which);
{ int z; for (z=0; z<i; z++) printf("%02X%c",ms[z],((z+1)%16)?' ':'\n'); }
#endif
if (is_export)
{
tls1_PRF(s->s3->tmp.new_cipher->algorithm2,
exp_label,exp_label_len,
s->s3->client_random,SSL3_RANDOM_SIZE,
s->s3->server_random,SSL3_RANDOM_SIZE,
NULL,0,NULL,0,
key,j,tmp1,tmp2,EVP_CIPHER_key_length(c));
key=tmp1;
if (k > 0)
{
tls1_PRF(s->s3->tmp.new_cipher->algorithm2,
TLS_MD_IV_BLOCK_CONST,TLS_MD_IV_BLOCK_CONST_SIZE,
s->s3->client_random,SSL3_RANDOM_SIZE,
s->s3->server_random,SSL3_RANDOM_SIZE,
NULL,0,NULL,0,
empty,0,iv1,iv2,k*2);
if (client_write)
iv=iv1;
else
iv= &(iv1[k]);
}
}
s->session->key_arg_length=0;
#ifdef KSSL_DEBUG
{
int i;
printf("EVP_CipherInit_ex(dd,c,key=,iv=,which)\n");
printf("\tkey= "); for (i=0; i<c->key_len; i++) printf("%02x", key[i]);
printf("\n");
printf("\t iv= "); for (i=0; i<c->iv_len; i++) printf("%02x", iv[i]);
printf("\n");
}
#endif
EVP_CipherInit_ex(dd,c,NULL,key,iv,(which & SSL3_CC_WRITE));
#ifdef TLS_DEBUG
printf("which = %04X\nkey=",which);
{ int z; for (z=0; z<EVP_CIPHER_key_length(c); z++) printf("%02X%c",key[z],((z+1)%16)?' ':'\n'); }
printf("\niv=");
{ int z; for (z=0; z<k; z++) printf("%02X%c",iv[z],((z+1)%16)?' ':'\n'); }
printf("\n");
#endif
OPENSSL_cleanse(tmp1,sizeof(tmp1));
OPENSSL_cleanse(tmp2,sizeof(tmp1));
OPENSSL_cleanse(iv1,sizeof(iv1));
OPENSSL_cleanse(iv2,sizeof(iv2));
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
int mac_type= NID_undef,mac_secret_size=0;
#ifdef KSSL_DEBUG
printf ("tls1_setup_key_block()\n");
#endif
if (s->s3->tmp.key_block_length != 0)
return(1);
if (!ssl_cipher_get_evp(s->session,&c,&hash,&mac_type,&mac_secret_size,&comp))
{
SSLerr(SSL_F_TLS1_SETUP_KEY_BLOCK,SSL_R_CIPHER_OR_HASH_UNAVAILABLE);
return(0);
}
s->s3->tmp.new_sym_enc=c;
s->s3->tmp.new_hash=hash;
s->s3->tmp.new_mac_pkey_type = mac_type;
s->s3->tmp.new_mac_secret_size = mac_secret_size;
num=EVP_CIPHER_key_length(c)+mac_secret_size+EVP_CIPHER_iv_length(c);
num*=2;
ssl3_cleanup_key_block(s);
if ((p1=(unsigned char *)OPENSSL_malloc(num)) == NULL)
goto err;
if ((p2=(unsigned char *)OPENSSL_malloc(num)) == NULL)
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
OPENSSL_cleanse(p2,num);
OPENSSL_free(p2);
#ifdef TLS_DEBUG
printf("\nkey block\n");
{ int z; for (z=0; z<num; z++) printf("%02X%c",p1[z],((z+1)%16)?' ':'\n'); }
#endif
if (!(s->options & SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS))
{
s->s3->need_empty_fragments = 1;
if (s->session->cipher != NULL)
{
if (s->session->cipher->algorithm_enc == SSL_eNULL)
s->s3->need_empty_fragments = 0;
#ifndef OPENSSL_NO_RC4
if (s->session->cipher->algorithm_enc == SSL_RC4)
s->s3->need_empty_fragments = 0;
#endif
}
}
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
if (EVP_MD_CTX_md(s->write_hash))
{
n=EVP_MD_CTX_size(s->write_hash);
OPENSSL_assert(n >= 0);
}
ds=s->enc_write_ctx;
rec= &(s->s3->wrec);
if (s->enc_write_ctx == NULL)
enc=NULL;
else
enc=EVP_CIPHER_CTX_cipher(s->enc_write_ctx);
}
else
{
if (EVP_MD_CTX_md(s->read_hash))
{
n=EVP_MD_CTX_size(s->read_hash);
OPENSSL_assert(n >= 0);
}
ds=s->enc_read_ctx;
rec= &(s->s3->rrec);
if (s->enc_read_ctx == NULL)
enc=NULL;
else
enc=EVP_CIPHER_CTX_cipher(s->enc_read_ctx);
}
#ifdef KSSL_DEBUG
printf("tls1_enc(%d)\n", send);
#endif
if ((s->session == NULL) || (ds == NULL) ||
(enc == NULL))
{
memmove(rec->data,rec->input,rec->length);
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
#ifdef KSSL_DEBUG
{
unsigned long ui;
printf("EVP_Cipher(ds=%p,rec->data=%p,rec->input=%p,l=%ld) ==>\n",
ds,rec->data,rec->input,l);
printf("\tEVP_CIPHER_CTX: %d buf_len, %d key_len [%d %d], %d iv_len\n",
ds->buf_len, ds->cipher->key_len,
DES_KEY_SZ, DES_SCHEDULE_SZ,
ds->cipher->iv_len);
printf("\t\tIV: ");
for (i=0; i<ds->cipher->iv_len; i++) printf("%02X", ds->iv[i]);
printf("\n");
printf("\trec->input=");
for (ui=0; ui<l; ui++) printf(" %02x", rec->input[ui]);
printf("\n");
}
#endif
if (!send)
{
if (l == 0 || l%bs != 0)
{
SSLerr(SSL_F_TLS1_ENC,SSL_R_BLOCK_CIPHER_PAD_IS_WRONG);
ssl3_send_alert(s,SSL3_AL_FATAL,SSL_AD_DECRYPTION_FAILED);
return 0;
}
}
EVP_Cipher(ds,rec->data,rec->input,l);
#ifdef KSSL_DEBUG
{
unsigned long i;
printf("\trec->data=");
for (i=0; i<l; i++)
printf(" %02x", rec->data[i]); printf("\n");
}
#endif
if ((bs != 1) && !send)
{
ii=i=rec->data[l-1];
i++;
if ( (s->options&SSL_OP_TLS_BLOCK_PADDING_BUG)
&& !s->expand)
{
if ((memcmp(s->s3->read_sequence,
"\0\0\0\0\0\0\0\0",8) == 0) && !(ii & 1))
s->s3->flags|=TLS1_FLAGS_TLS_PADDING_BUG;
if (s->s3->flags & TLS1_FLAGS_TLS_PADDING_BUG)
i--;
}
if (i > (int)rec->length)
{
return -1;
}
for (j=(int)(l-i); j<(int)l; j++)
{
if (rec->data[j] != ii)
{
return -1;
}
}
rec->length-=i;
}
}
return(1);
}
int tls1_cert_verify_mac(SSL *s, int md_nid, unsigned char *out)
{
unsigned int ret;
EVP_MD_CTX ctx, *d=NULL;
int i;
if (s->s3->handshake_buffer)
if (!ssl3_digest_cached_records(s))
return 0;
for (i=0;i<SSL_MAX_DIGEST;i++)
{
if (s->s3->handshake_dgst[i]&&EVP_MD_CTX_type(s->s3->handshake_dgst[i])==md_nid)
{
d=s->s3->handshake_dgst[i];
break;
}
}
if (!d) {
SSLerr(SSL_F_TLS1_CERT_VERIFY_MAC,SSL_R_NO_REQUIRED_DIGEST);
return 0;
}
EVP_MD_CTX_init(&ctx);
EVP_MD_CTX_copy_ex(&ctx,d);
EVP_DigestFinal_ex(&ctx,out,&ret);
EVP_MD_CTX_cleanup(&ctx);
return((int)ret);
}
int tls1_final_finish_mac(SSL *s,
const char *str, int slen, unsigned char *out)
{
unsigned int i;
EVP_MD_CTX ctx;
unsigned char buf[2*EVP_MAX_MD_SIZE];
unsigned char *q,buf2[12];
int idx;
long mask;
int err=0;
const EVP_MD *md;
q=buf;
if (s->s3->handshake_buffer)
if (!ssl3_digest_cached_records(s))
return 0;
EVP_MD_CTX_init(&ctx);
for (idx=0;ssl_get_handshake_digest(idx,&mask,&md);idx++)
{
if (mask & s->s3->tmp.new_cipher->algorithm2)
{
int hashsize = EVP_MD_size(md);
if (hashsize < 0 || hashsize > (int)(sizeof buf - (size_t)(q-buf)))
{
err = 1;
}
else
{
EVP_MD_CTX_copy_ex(&ctx,s->s3->handshake_dgst[idx]);
EVP_DigestFinal_ex(&ctx,q,&i);
if (i != (unsigned int)hashsize)
err = 1;
q+=i;
}
}
}
tls1_PRF(s->s3->tmp.new_cipher->algorithm2,
str,slen, buf,(int)(q-buf), NULL,0, NULL,0, NULL,0,
s->session->master_key,s->session->master_key_length,
out,buf2,sizeof buf2);
EVP_MD_CTX_cleanup(&ctx);
if (err)
return 0;
else
return sizeof buf2;
}
int tls1_mac(SSL *ssl, unsigned char *md, int send)
{
SSL3_RECORD *rec;
unsigned char *mac_sec,*seq;
EVP_MD_CTX *hash;
size_t md_size;
int i;
EVP_MD_CTX hmac, *mac_ctx;
unsigned char buf[5];
int stream_mac = (send?(ssl->mac_flags & SSL_MAC_FLAG_WRITE_MAC_STREAM):(ssl->mac_flags&SSL_MAC_FLAG_READ_MAC_STREAM));
int t;
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
t=EVP_MD_CTX_size(hash);
OPENSSL_assert(t >= 0);
md_size=t;
buf[0]=rec->type;
buf[1]=(unsigned char)(ssl->version>>8);
buf[2]=(unsigned char)(ssl->version);
buf[3]=rec->length>>8;
buf[4]=rec->length&0xff;
if (stream_mac)
{
mac_ctx = hash;
}
else
{
EVP_MD_CTX_copy(&hmac,hash);
mac_ctx = &hmac;
}
if (ssl->version == DTLS1_VERSION || ssl->version == DTLS1_BAD_VER)
{
unsigned char dtlsseq[8],*p=dtlsseq;
s2n(send?ssl->d1->w_epoch:ssl->d1->r_epoch, p);
memcpy (p,&seq[2],6);
EVP_DigestSignUpdate(mac_ctx,dtlsseq,8);
}
else
EVP_DigestSignUpdate(mac_ctx,seq,8);
EVP_DigestSignUpdate(mac_ctx,buf,5);
EVP_DigestSignUpdate(mac_ctx,rec->input,rec->length);
t=EVP_DigestSignFinal(mac_ctx,md,&md_size);
OPENSSL_assert(t > 0);
if (!stream_mac) EVP_MD_CTX_cleanup(&hmac);
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
if (ssl->version != DTLS1_VERSION && ssl->version != DTLS1_BAD_VER)
{
for (i=7; i>=0; i--)
{
++seq[i];
if (seq[i] != 0) break;
}
}
#ifdef TLS_DEBUG
{unsigned int z; for (z=0; z<md_size; z++) printf("%02X ",md[z]); printf("\n"); }
#endif
return(md_size);
}
int tls1_generate_master_secret(SSL *s, unsigned char *out, unsigned char *p,
int len)
{
unsigned char buff[SSL_MAX_MASTER_KEY_LENGTH];
const void *co = NULL, *so = NULL;
int col = 0, sol = 0;
#ifdef KSSL_DEBUG
printf ("tls1_generate_master_secret(%p,%p, %p, %d)\n", s,out, p,len);
#endif
#ifdef TLSEXT_TYPE_opaque_prf_input
if (s->s3->client_opaque_prf_input != NULL && s->s3->server_opaque_prf_input != NULL &&
s->s3->client_opaque_prf_input_len > 0 &&
s->s3->client_opaque_prf_input_len == s->s3->server_opaque_prf_input_len)
{
co = s->s3->client_opaque_prf_input;
col = s->s3->server_opaque_prf_input_len;
so = s->s3->server_opaque_prf_input;
sol = s->s3->client_opaque_prf_input_len;
}
#endif
tls1_PRF(s->s3->tmp.new_cipher->algorithm2,
TLS_MD_MASTER_SECRET_CONST,TLS_MD_MASTER_SECRET_CONST_SIZE,
s->s3->client_random,SSL3_RANDOM_SIZE,
co, col,
s->s3->server_random,SSL3_RANDOM_SIZE,
so, sol,
p,len,
s->session->master_key,buff,sizeof buff);
#ifdef KSSL_DEBUG
printf ("tls1_generate_master_secret() complete\n");
#endif
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
case SSL_AD_UNSUPPORTED_EXTENSION: return(TLS1_AD_UNSUPPORTED_EXTENSION);
case SSL_AD_CERTIFICATE_UNOBTAINABLE: return(TLS1_AD_CERTIFICATE_UNOBTAINABLE);
case SSL_AD_UNRECOGNIZED_NAME: return(TLS1_AD_UNRECOGNIZED_NAME);
case SSL_AD_BAD_CERTIFICATE_STATUS_RESPONSE: return(TLS1_AD_BAD_CERTIFICATE_STATUS_RESPONSE);
case SSL_AD_BAD_CERTIFICATE_HASH_VALUE: return(TLS1_AD_BAD_CERTIFICATE_HASH_VALUE);
case SSL_AD_UNKNOWN_PSK_IDENTITY:return(TLS1_AD_UNKNOWN_PSK_IDENTITY);
#if 0
case DTLS1_AD_MISSING_HANDSHAKE_MESSAGE: return
(DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
#endif
default: return(-1);
}
}
