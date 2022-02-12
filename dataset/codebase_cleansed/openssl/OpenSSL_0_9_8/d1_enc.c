int dtls1_enc(SSL *s, int send)
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
{
enc=EVP_CIPHER_CTX_cipher(s->enc_write_ctx);
if ( rec->data != rec->input)
fprintf(stderr, "%s:%d: rec->data != rec->input\n",
__FILE__, __LINE__);
else if ( EVP_CIPHER_block_size(ds->cipher) > 1)
RAND_bytes(rec->input, EVP_CIPHER_block_size(ds->cipher));
}
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
#ifdef KSSL_DEBUG
printf("dtls1_enc(%d)\n", send);
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
SSLerr(SSL_F_DTLS1_ENC,SSL_R_BLOCK_CIPHER_PAD_IS_WRONG);
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
rec->data += bs;
rec->input += bs;
rec->length -= bs;
}
}
return(1);
}
