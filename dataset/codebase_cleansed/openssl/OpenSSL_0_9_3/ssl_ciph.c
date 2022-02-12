static int cmp_by_name(SSL_CIPHER **a, SSL_CIPHER **b)
{
return(strcmp((*a)->name,(*b)->name));
}
static void load_ciphers(void)
{
init_ciphers=0;
ssl_cipher_methods[SSL_ENC_DES_IDX]=
EVP_get_cipherbyname(SN_des_cbc);
ssl_cipher_methods[SSL_ENC_3DES_IDX]=
EVP_get_cipherbyname(SN_des_ede3_cbc);
ssl_cipher_methods[SSL_ENC_RC4_IDX]=
EVP_get_cipherbyname(SN_rc4);
ssl_cipher_methods[SSL_ENC_RC2_IDX]=
EVP_get_cipherbyname(SN_rc2_cbc);
ssl_cipher_methods[SSL_ENC_IDEA_IDX]=
EVP_get_cipherbyname(SN_idea_cbc);
ssl_digest_methods[SSL_MD_MD5_IDX]=
EVP_get_digestbyname(SN_md5);
ssl_digest_methods[SSL_MD_SHA1_IDX]=
EVP_get_digestbyname(SN_sha1);
}
int ssl_cipher_get_evp(SSL_SESSION *s, const EVP_CIPHER **enc,
const EVP_MD **md, SSL_COMP **comp)
{
int i;
SSL_CIPHER *c;
c=s->cipher;
if (c == NULL) return(0);
if (comp != NULL)
{
SSL_COMP ctmp;
if (s->compress_meth == 0)
*comp=NULL;
else if (ssl_comp_methods == NULL)
{
*comp=NULL;
}
else
{
ctmp.id=s->compress_meth;
i=sk_SSL_COMP_find(ssl_comp_methods,&ctmp);
if (i >= 0)
*comp=sk_SSL_COMP_value(ssl_comp_methods,i);
else
*comp=NULL;
}
}
if ((enc == NULL) || (md == NULL)) return(0);
switch (c->algorithms & SSL_ENC_MASK)
{
case SSL_DES:
i=SSL_ENC_DES_IDX;
break;
case SSL_3DES:
i=SSL_ENC_3DES_IDX;
break;
case SSL_RC4:
i=SSL_ENC_RC4_IDX;
break;
case SSL_RC2:
i=SSL_ENC_RC2_IDX;
break;
case SSL_IDEA:
i=SSL_ENC_IDEA_IDX;
break;
case SSL_eNULL:
i=SSL_ENC_NULL_IDX;
break;
default:
i= -1;
break;
}
if ((i < 0) || (i > SSL_ENC_NUM_IDX))
*enc=NULL;
else
{
if (i == SSL_ENC_NULL_IDX)
*enc=EVP_enc_null();
else
*enc=ssl_cipher_methods[i];
}
switch (c->algorithms & SSL_MAC_MASK)
{
case SSL_MD5:
i=SSL_MD_MD5_IDX;
break;
case SSL_SHA1:
i=SSL_MD_SHA1_IDX;
break;
default:
i= -1;
break;
}
if ((i < 0) || (i > SSL_MD_NUM_IDX))
*md=NULL;
else
*md=ssl_digest_methods[i];
if ((*enc != NULL) && (*md != NULL))
return(1);
else
return(0);
}
static void ll_append_tail(CIPHER_ORDER **head, CIPHER_ORDER *curr,
CIPHER_ORDER **tail)
{
if (curr == *tail) return;
if (curr == *head)
*head=curr->next;
if (curr->prev != NULL)
curr->prev->next=curr->next;
if (curr->next != NULL)
curr->next->prev=curr->prev;
(*tail)->next=curr;
curr->prev= *tail;
curr->next=NULL;
*tail=curr;
}
char *SSL_CIPHER_get_name(SSL_CIPHER *c)
{
if (c != NULL)
return(c->name);
return("(NONE)");
}
int SSL_CIPHER_get_bits(SSL_CIPHER *c, int *alg_bits)
{
int ret=0,a=0;
const EVP_CIPHER *enc;
const EVP_MD *md;
SSL_SESSION ss;
if (c != NULL)
{
ss.cipher=c;
if (!ssl_cipher_get_evp(&ss,&enc,&md,NULL))
return(0);
a=EVP_CIPHER_key_length(enc)*8;
if (SSL_C_IS_EXPORT(c))
{
ret=SSL_C_EXPORT_KEYLENGTH(c)*8;
}
else
{
if (c->algorithm2 & SSL2_CF_8_BYTE_ENC)
ret=64;
else
ret=a;
}
}
if (alg_bits != NULL) *alg_bits=a;
return(ret);
}
static int sk_comp_cmp(SSL_COMP **a,SSL_COMP **b)
{
return((*a)->id-(*b)->id);
}
int SSL_COMP_add_compression_method(int id, COMP_METHOD *cm)
{
SSL_COMP *comp;
STACK_OF(SSL_COMP) *sk;
comp=(SSL_COMP *)Malloc(sizeof(SSL_COMP));
comp->id=id;
comp->method=cm;
if (ssl_comp_methods == NULL)
sk=ssl_comp_methods=sk_SSL_COMP_new(sk_comp_cmp);
else
sk=ssl_comp_methods;
if ((sk == NULL) || !sk_SSL_COMP_push(sk,comp))
{
SSLerr(SSL_F_SSL_COMP_ADD_COMPRESSION_METHOD,ERR_R_MALLOC_FAILURE);
return(0);
}
else
return(1);
}
