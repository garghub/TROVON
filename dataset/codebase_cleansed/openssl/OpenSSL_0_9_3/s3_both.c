int ssl3_send_finished(SSL *s, int a, int b, unsigned char *sender,
int slen)
{
unsigned char *p,*d;
int i;
unsigned long l;
if (s->state == a)
{
d=(unsigned char *)s->init_buf->data;
p= &(d[4]);
i=s->method->ssl3_enc->final_finish_mac(s,
&(s->s3->finish_dgst1),
&(s->s3->finish_dgst2),
sender,slen,p);
p+=i;
l=i;
#ifdef WIN16
l&=0xffff;
#endif
*(d++)=SSL3_MT_FINISHED;
l2n3(l,d);
s->init_num=(int)l+4;
s->init_off=0;
s->state=b;
}
return(ssl3_do_write(s,SSL3_RT_HANDSHAKE));
}
int ssl3_get_finished(SSL *s, int a, int b)
{
int al,i,ok;
long n;
unsigned char *p;
n=ssl3_get_message(s,
a,
b,
SSL3_MT_FINISHED,
64,
&ok);
if (!ok) return((int)n);
if (!s->s3->change_cipher_spec)
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_GET_FINISHED,SSL_R_GOT_A_FIN_BEFORE_A_CCS);
goto f_err;
}
s->s3->change_cipher_spec=0;
p=(unsigned char *)s->init_buf->data;
i=s->method->ssl3_enc->finish_mac_length;
if (i != n)
{
al=SSL_AD_DECODE_ERROR;
SSLerr(SSL_F_SSL3_GET_FINISHED,SSL_R_BAD_DIGEST_LENGTH);
goto f_err;
}
if (memcmp( p, (char *)&(s->s3->tmp.finish_md[0]),i) != 0)
{
al=SSL_AD_DECRYPT_ERROR;
SSLerr(SSL_F_SSL3_GET_FINISHED,SSL_R_DIGEST_CHECK_FAILED);
goto f_err;
}
return(1);
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
return(0);
}
int ssl3_send_change_cipher_spec(SSL *s, int a, int b)
{
unsigned char *p;
if (s->state == a)
{
p=(unsigned char *)s->init_buf->data;
*p=SSL3_MT_CCS;
s->init_num=1;
s->init_off=0;
s->state=b;
}
return(ssl3_do_write(s,SSL3_RT_CHANGE_CIPHER_SPEC));
}
unsigned long ssl3_output_cert_chain(SSL *s, X509 *x)
{
unsigned char *p;
int n,i;
unsigned long l=7;
BUF_MEM *buf;
X509_STORE_CTX xs_ctx;
X509_OBJECT obj;
buf=s->init_buf;
if (!BUF_MEM_grow(buf,(int)(10)))
{
SSLerr(SSL_F_SSL3_OUTPUT_CERT_CHAIN,ERR_R_BUF_LIB);
return(0);
}
if (x != NULL)
{
X509_STORE_CTX_init(&xs_ctx,s->ctx->cert_store,NULL,NULL);
for (;;)
{
n=i2d_X509(x,NULL);
if (!BUF_MEM_grow(buf,(int)(n+l+3)))
{
SSLerr(SSL_F_SSL3_OUTPUT_CERT_CHAIN,ERR_R_BUF_LIB);
return(0);
}
p=(unsigned char *)&(buf->data[l]);
l2n3(n,p);
i2d_X509(x,&p);
l+=n+3;
if (X509_NAME_cmp(X509_get_subject_name(x),
X509_get_issuer_name(x)) == 0) break;
i=X509_STORE_get_by_subject(&xs_ctx,X509_LU_X509,
X509_get_issuer_name(x),&obj);
if (i <= 0) break;
x=obj.data.x509;
X509_free(x);
}
X509_STORE_CTX_cleanup(&xs_ctx);
}
if (s->ctx->extra_certs != NULL)
for (i=0; i<sk_X509_num(s->ctx->extra_certs); i++)
{
x=sk_X509_value(s->ctx->extra_certs,i);
n=i2d_X509(x,NULL);
if (!BUF_MEM_grow(buf,(int)(n+l+3)))
{
SSLerr(SSL_F_SSL3_OUTPUT_CERT_CHAIN,ERR_R_BUF_LIB);
return(0);
}
p=(unsigned char *)&(buf->data[l]);
l2n3(n,p);
i2d_X509(x,&p);
l+=n+3;
}
l-=7;
p=(unsigned char *)&(buf->data[4]);
l2n3(l,p);
l+=3;
p=(unsigned char *)&(buf->data[0]);
*(p++)=SSL3_MT_CERTIFICATE;
l2n3(l,p);
l+=4;
return(l);
}
long ssl3_get_message(SSL *s, int st1, int stn, int mt, long max, int *ok)
{
unsigned char *p;
unsigned long l;
long n;
int i,al;
if (s->s3->tmp.reuse_message)
{
s->s3->tmp.reuse_message=0;
if ((mt >= 0) && (s->s3->tmp.message_type != mt))
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_GET_MESSAGE,SSL_R_UNEXPECTED_MESSAGE);
goto f_err;
}
*ok=1;
return((int)s->s3->tmp.message_size);
}
p=(unsigned char *)s->init_buf->data;
if (s->state == st1)
{
i=ssl3_read_bytes(s,SSL3_RT_HANDSHAKE,&p[s->init_num],
4-s->init_num);
if (i < (4-s->init_num))
{
*ok=0;
return(ssl3_part_read(s,i));
}
if ((mt >= 0) && (*p != mt))
{
al=SSL_AD_UNEXPECTED_MESSAGE;
SSLerr(SSL_F_SSL3_GET_MESSAGE,SSL_R_UNEXPECTED_MESSAGE);
goto f_err;
}
s->s3->tmp.message_type= *(p++);
n2l3(p,l);
if (l > (unsigned long)max)
{
al=SSL_AD_ILLEGAL_PARAMETER;
SSLerr(SSL_F_SSL3_GET_MESSAGE,SSL_R_EXCESSIVE_MESSAGE_SIZE);
goto f_err;
}
if (l && !BUF_MEM_grow(s->init_buf,(int)l))
{
SSLerr(SSL_F_SSL3_GET_MESSAGE,ERR_R_BUF_LIB);
goto err;
}
s->s3->tmp.message_size=l;
s->state=stn;
s->init_num=0;
}
p=(unsigned char *)s->init_buf->data;
n=s->s3->tmp.message_size;
if (n > 0)
{
i=ssl3_read_bytes(s,SSL3_RT_HANDSHAKE,&p[s->init_num],n);
if (i != (int)n)
{
*ok=0;
return(ssl3_part_read(s,i));
}
}
*ok=1;
return(n);
f_err:
ssl3_send_alert(s,SSL3_AL_FATAL,al);
err:
*ok=0;
return(-1);
}
int ssl_cert_type(X509 *x, EVP_PKEY *pkey)
{
EVP_PKEY *pk;
int ret= -1,i,j;
if (pkey == NULL)
pk=X509_get_pubkey(x);
else
pk=pkey;
if (pk == NULL) goto err;
i=pk->type;
if (i == EVP_PKEY_RSA)
{
ret=SSL_PKEY_RSA_ENC;
if (x != NULL)
{
j=X509_get_ext_count(x);
}
}
else if (i == EVP_PKEY_DSA)
{
ret=SSL_PKEY_DSA_SIGN;
}
else if (i == EVP_PKEY_DH)
{
if (x == NULL)
ret=SSL_PKEY_DH_DSA;
else
{
j=X509_get_signature_type(x);
if (j == EVP_PKEY_RSA)
ret=SSL_PKEY_DH_RSA;
else if (j== EVP_PKEY_DSA)
ret=SSL_PKEY_DH_DSA;
else ret= -1;
}
}
else
ret= -1;
err:
if(!pkey) EVP_PKEY_free(pk);
return(ret);
}
int ssl_verify_alarm_type(long type)
{
int al;
switch(type)
{
case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
case X509_V_ERR_UNABLE_TO_GET_CRL:
al=SSL_AD_UNKNOWN_CA;
break;
case X509_V_ERR_UNABLE_TO_DECRYPT_CERT_SIGNATURE:
case X509_V_ERR_UNABLE_TO_DECRYPT_CRL_SIGNATURE:
case X509_V_ERR_UNABLE_TO_DECODE_ISSUER_PUBLIC_KEY:
case X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD:
case X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD:
case X509_V_ERR_ERROR_IN_CRL_LAST_UPDATE_FIELD:
case X509_V_ERR_ERROR_IN_CRL_NEXT_UPDATE_FIELD:
case X509_V_ERR_CERT_NOT_YET_VALID:
case X509_V_ERR_CRL_NOT_YET_VALID:
al=SSL_AD_BAD_CERTIFICATE;
break;
case X509_V_ERR_CERT_SIGNATURE_FAILURE:
case X509_V_ERR_CRL_SIGNATURE_FAILURE:
al=SSL_AD_DECRYPT_ERROR;
break;
case X509_V_ERR_CERT_HAS_EXPIRED:
case X509_V_ERR_CRL_HAS_EXPIRED:
al=SSL_AD_CERTIFICATE_EXPIRED;
break;
case X509_V_ERR_CERT_REVOKED:
al=SSL_AD_CERTIFICATE_REVOKED;
break;
case X509_V_ERR_OUT_OF_MEM:
al=SSL_AD_INTERNAL_ERROR;
break;
case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY:
case X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE:
case X509_V_ERR_CERT_CHAIN_TOO_LONG:
al=SSL_AD_UNKNOWN_CA;
break;
case X509_V_ERR_APPLICATION_VERIFICATION:
al=SSL_AD_HANDSHAKE_FAILURE;
break;
default:
al=SSL_AD_CERTIFICATE_UNKNOWN;
break;
}
return(al);
}
int ssl3_setup_buffers(SSL *s)
{
unsigned char *p;
unsigned int extra;
if (s->s3->rbuf.buf == NULL)
{
if (s->options & SSL_OP_MICROSOFT_BIG_SSLV3_BUFFER)
extra=SSL3_RT_MAX_EXTRA;
else
extra=0;
if ((p=(unsigned char *)Malloc(SSL3_RT_MAX_PACKET_SIZE+extra))
== NULL)
goto err;
s->s3->rbuf.buf=p;
}
if (s->s3->wbuf.buf == NULL)
{
if ((p=(unsigned char *)Malloc(SSL3_RT_MAX_PACKET_SIZE))
== NULL)
goto err;
s->s3->wbuf.buf=p;
}
s->packet= &(s->s3->rbuf.buf[0]);
return(1);
err:
SSLerr(SSL_F_SSL3_SETUP_BUFFERS,ERR_R_MALLOC_FAILURE);
return(0);
}
