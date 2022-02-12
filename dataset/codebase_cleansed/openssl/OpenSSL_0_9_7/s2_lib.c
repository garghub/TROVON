static long ssl2_default_timeout(void)
{
return(300);
}
SSL_METHOD *sslv2_base_method(void)
{
return(&SSLv2_data);
}
int ssl2_num_ciphers(void)
{
return(SSL2_NUM_CIPHERS);
}
SSL_CIPHER *ssl2_get_cipher(unsigned int u)
{
if (u < SSL2_NUM_CIPHERS)
return(&(ssl2_ciphers[SSL2_NUM_CIPHERS-1-u]));
else
return(NULL);
}
int ssl2_pending(SSL *s)
{
return SSL_in_init(s) ? 0 : s->s2->ract_data_length;
}
int ssl2_new(SSL *s)
{
SSL2_STATE *s2;
if ((s2=OPENSSL_malloc(sizeof *s2)) == NULL) goto err;
memset(s2,0,sizeof *s2);
#if SSL2_MAX_RECORD_LENGTH_3_BYTE_HEADER + 3 > SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER + 2
# error "assertion failed"
#endif
if ((s2->rbuf=OPENSSL_malloc(
SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER+2)) == NULL) goto err;
if ((s2->wbuf=OPENSSL_malloc(
SSL2_MAX_RECORD_LENGTH_2_BYTE_HEADER+3)) == NULL) goto err;
s->s2=s2;
ssl2_clear(s);
return(1);
err:
if (s2 != NULL)
{
if (s2->wbuf != NULL) OPENSSL_free(s2->wbuf);
if (s2->rbuf != NULL) OPENSSL_free(s2->rbuf);
OPENSSL_free(s2);
}
return(0);
}
void ssl2_free(SSL *s)
{
SSL2_STATE *s2;
if(s == NULL)
return;
s2=s->s2;
if (s2->rbuf != NULL) OPENSSL_free(s2->rbuf);
if (s2->wbuf != NULL) OPENSSL_free(s2->wbuf);
OPENSSL_cleanse(s2,sizeof *s2);
OPENSSL_free(s2);
s->s2=NULL;
}
void ssl2_clear(SSL *s)
{
SSL2_STATE *s2;
unsigned char *rbuf,*wbuf;
s2=s->s2;
rbuf=s2->rbuf;
wbuf=s2->wbuf;
memset(s2,0,sizeof *s2);
s2->rbuf=rbuf;
s2->wbuf=wbuf;
s2->clear_text=1;
s->packet=s2->rbuf;
s->version=SSL2_VERSION;
s->packet_length=0;
}
long ssl2_ctrl(SSL *s, int cmd, long larg, void *parg)
{
int ret=0;
switch(cmd)
{
case SSL_CTRL_GET_SESSION_REUSED:
ret=s->hit;
break;
default:
break;
}
return(ret);
}
long ssl2_callback_ctrl(SSL *s, int cmd, void (*fp)())
{
return(0);
}
long ssl2_ctx_ctrl(SSL_CTX *ctx, int cmd, long larg, void *parg)
{
return(0);
}
long ssl2_ctx_callback_ctrl(SSL_CTX *ctx, int cmd, void (*fp)())
{
return(0);
}
SSL_CIPHER *ssl2_get_cipher_by_char(const unsigned char *p)
{
static int init=1;
static SSL_CIPHER *sorted[SSL2_NUM_CIPHERS];
SSL_CIPHER c,*cp= &c,**cpp;
unsigned long id;
int i;
if (init)
{
CRYPTO_w_lock(CRYPTO_LOCK_SSL);
if (init)
{
for (i=0; i<SSL2_NUM_CIPHERS; i++)
sorted[i]= &(ssl2_ciphers[i]);
qsort((char *)sorted,
SSL2_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp);
init=0;
}
CRYPTO_w_unlock(CRYPTO_LOCK_SSL);
}
id=0x02000000L|((unsigned long)p[0]<<16L)|
((unsigned long)p[1]<<8L)|(unsigned long)p[2];
c.id=id;
cpp=(SSL_CIPHER **)OBJ_bsearch((char *)&cp,
(char *)sorted,
SSL2_NUM_CIPHERS,sizeof(SSL_CIPHER *),
FP_ICC ssl_cipher_ptr_id_cmp);
if ((cpp == NULL) || !(*cpp)->valid)
return(NULL);
else
return(*cpp);
}
int ssl2_put_cipher_by_char(const SSL_CIPHER *c, unsigned char *p)
{
long l;
if (p != NULL)
{
l=c->id;
if ((l & 0xff000000) != 0x02000000) return(0);
p[0]=((unsigned char)(l>>16L))&0xFF;
p[1]=((unsigned char)(l>> 8L))&0xFF;
p[2]=((unsigned char)(l ))&0xFF;
}
return(3);
}
int ssl2_generate_key_material(SSL *s)
{
unsigned int i;
EVP_MD_CTX ctx;
unsigned char *km;
unsigned char c='0';
const EVP_MD *md5;
md5 = EVP_md5();
#ifdef CHARSET_EBCDIC
c = os_toascii['0'];
#endif
EVP_MD_CTX_init(&ctx);
km=s->s2->key_material;
if (s->session->master_key_length < 0 || s->session->master_key_length > sizeof s->session->master_key)
{
SSLerr(SSL_F_SSL2_GENERATE_KEY_MATERIAL, ERR_R_INTERNAL_ERROR);
return 0;
}
for (i=0; i<s->s2->key_material_length; i += EVP_MD_size(md5))
{
if (((km - s->s2->key_material) + EVP_MD_size(md5)) > sizeof s->s2->key_material)
{
SSLerr(SSL_F_SSL2_GENERATE_KEY_MATERIAL, ERR_R_INTERNAL_ERROR);
return 0;
}
EVP_DigestInit_ex(&ctx, md5, NULL);
OPENSSL_assert(s->session->master_key_length >= 0
&& s->session->master_key_length
< sizeof s->session->master_key);
EVP_DigestUpdate(&ctx,s->session->master_key,s->session->master_key_length);
EVP_DigestUpdate(&ctx,&c,1);
c++;
EVP_DigestUpdate(&ctx,s->s2->challenge,s->s2->challenge_length);
EVP_DigestUpdate(&ctx,s->s2->conn_id,s->s2->conn_id_length);
EVP_DigestFinal_ex(&ctx,km,NULL);
km += EVP_MD_size(md5);
}
EVP_MD_CTX_cleanup(&ctx);
return 1;
}
void ssl2_return_error(SSL *s, int err)
{
if (!s->error)
{
s->error=3;
s->error_code=err;
ssl2_write_error(s);
}
}
void ssl2_write_error(SSL *s)
{
unsigned char buf[3];
int i,error;
buf[0]=SSL2_MT_ERROR;
buf[1]=(s->error_code>>8)&0xff;
buf[2]=(s->error_code)&0xff;
error=s->error;
s->error=0;
OPENSSL_assert(error >= 0 && error <= sizeof buf);
i=ssl2_write(s,&(buf[3-error]),error);
if (i < 0)
s->error=error;
else
{
s->error=error-i;
if (s->error == 0)
if (s->msg_callback)
s->msg_callback(1, s->version, 0, buf, 3, s, s->msg_callback_arg);
}
}
int ssl2_shutdown(SSL *s)
{
s->shutdown=(SSL_SENT_SHUTDOWN|SSL_RECEIVED_SHUTDOWN);
return(1);
}
