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
static unsigned long ssl_cipher_get_disabled(void)
{
unsigned long mask;
mask = SSL_kFZA;
#ifdef NO_RSA
mask |= SSL_aRSA|SSL_kRSA;
#endif
#ifdef NO_DSA
mask |= SSL_aDSS;
#endif
#ifdef NO_DH
mask |= SSL_kDHr|SSL_kDHd|SSL_kEDH|SSL_aDH;
#endif
#ifdef SSL_FORBID_ENULL
mask |= SSL_eNULL;
#endif
mask |= (ssl_cipher_methods[SSL_ENC_DES_IDX ] == NULL) ? SSL_DES :0;
mask |= (ssl_cipher_methods[SSL_ENC_3DES_IDX] == NULL) ? SSL_3DES:0;
mask |= (ssl_cipher_methods[SSL_ENC_RC4_IDX ] == NULL) ? SSL_RC4 :0;
mask |= (ssl_cipher_methods[SSL_ENC_RC2_IDX ] == NULL) ? SSL_RC2 :0;
mask |= (ssl_cipher_methods[SSL_ENC_IDEA_IDX] == NULL) ? SSL_IDEA:0;
mask |= (ssl_cipher_methods[SSL_ENC_eFZA_IDX] == NULL) ? SSL_eFZA:0;
mask |= (ssl_digest_methods[SSL_MD_MD5_IDX ] == NULL) ? SSL_MD5 :0;
mask |= (ssl_digest_methods[SSL_MD_SHA1_IDX] == NULL) ? SSL_SHA1:0;
return(mask);
}
static void ssl_cipher_collect_ciphers(const SSL_METHOD *ssl_method,
int num_of_ciphers, unsigned long mask, CIPHER_ORDER *list,
CIPHER_ORDER **head_p, CIPHER_ORDER **tail_p)
{
int i, list_num;
SSL_CIPHER *c;
list_num = 0;
for (i = 0; i < num_of_ciphers; i++)
{
c = ssl_method->get_cipher(i);
if ((c != NULL) && c->valid && !(c->algorithms & mask))
{
list[list_num].cipher = c;
list[list_num].next = NULL;
list[list_num].prev = NULL;
list[list_num].active = 0;
list_num++;
}
}
for (i = 1; i < list_num - 1; i++)
{
list[i].prev = &(list[i-1]);
list[i].next = &(list[i+1]);
}
if (list_num > 0)
{
(*head_p) = &(list[0]);
(*head_p)->prev = NULL;
(*head_p)->next = &(list[1]);
(*tail_p) = &(list[list_num - 1]);
(*tail_p)->prev = &(list[list_num - 2]);
(*tail_p)->next = NULL;
}
}
static void ssl_cipher_collect_aliases(SSL_CIPHER **ca_list,
int num_of_group_aliases, unsigned long mask,
CIPHER_ORDER *head)
{
CIPHER_ORDER *ciph_curr;
SSL_CIPHER **ca_curr;
int i;
ciph_curr = head;
ca_curr = ca_list;
while (ciph_curr != NULL)
{
*ca_curr = ciph_curr->cipher;
ca_curr++;
ciph_curr = ciph_curr->next;
}
for (i = 0; i < num_of_group_aliases; i++)
{
if ((i == 0) ||
!(cipher_aliases[i].algorithms & mask))
{
*ca_curr = (SSL_CIPHER *)(cipher_aliases + i);
ca_curr++;
}
}
*ca_curr = NULL;
}
static void ssl_cipher_apply_rule(unsigned long algorithms, unsigned long mask,
unsigned long algo_strength, unsigned long mask_strength,
int rule, int strength_bits, CIPHER_ORDER *list,
CIPHER_ORDER **head_p, CIPHER_ORDER **tail_p)
{
CIPHER_ORDER *head, *tail, *curr, *curr2, *tail2;
SSL_CIPHER *cp;
unsigned long ma, ma_s;
#ifdef CIPHER_DEBUG
printf("Applying rule %d with %08lx %08lx %08lx %08lx (%d)\n",
rule, algorithms, mask, algo_strength, mask_strength,
strength_bits);
#endif
curr = head = *head_p;
curr2 = head;
tail2 = tail = *tail_p;
for (;;)
{
if ((curr == NULL) || (curr == tail2)) break;
curr = curr2;
curr2 = curr->next;
cp = curr->cipher;
if (strength_bits == -1)
{
ma = mask & cp->algorithms;
ma_s = mask_strength & cp->algo_strength;
#ifdef CIPHER_DEBUG
printf("\nName: %s:\nAlgo = %08lx Algo_strength = %08lx\nMask = %08lx Mask_strength %08lx\n", cp->name, cp->algorithms, cp->algo_strength, mask, mask_strength);
printf("ma = %08lx ma_s %08lx, ma&algo=%08lx, ma_s&algos=%08lx\n", ma, ma_s, ma&algorithms, ma_s&algo_strength);
#endif
if (((ma == 0) && (ma_s == 0)) ||
((ma & algorithms) != ma) ||
((ma_s & algo_strength) != ma_s))
continue;
}
else if (strength_bits != cp->strength_bits)
continue;
#ifdef CIPHER_DEBUG
printf("Action = %d\n", rule);
#endif
if (rule == CIPHER_ADD)
{
if (!curr->active)
{
ll_append_tail(&head, curr, &tail);
curr->active = 1;
}
}
else if (rule == CIPHER_ORD)
{
if (curr->active)
{
ll_append_tail(&head, curr, &tail);
}
}
else if (rule == CIPHER_DEL)
curr->active = 0;
else if (rule == CIPHER_KILL)
{
if (head == curr)
head = curr->next;
else
curr->prev->next = curr->next;
if (tail == curr)
tail = curr->prev;
curr->active = 0;
if (curr->next != NULL)
curr->next->prev = curr->prev;
if (curr->prev != NULL)
curr->prev->next = curr->next;
curr->next = NULL;
curr->prev = NULL;
}
}
*head_p = head;
*tail_p = tail;
}
static int ssl_cipher_strength_sort(CIPHER_ORDER *list, CIPHER_ORDER **head_p,
CIPHER_ORDER **tail_p)
{
int max_strength_bits, i, *number_uses;
CIPHER_ORDER *curr;
max_strength_bits = 0;
curr = *head_p;
while (curr != NULL)
{
if (curr->active &&
(curr->cipher->strength_bits > max_strength_bits))
max_strength_bits = curr->cipher->strength_bits;
curr = curr->next;
}
number_uses = OPENSSL_malloc((max_strength_bits + 1) * sizeof(int));
if (!number_uses)
{
SSLerr(SSL_F_SSL_CIPHER_STRENGTH_SORT,ERR_R_MALLOC_FAILURE);
return(0);
}
memset(number_uses, 0, (max_strength_bits + 1) * sizeof(int));
curr = *head_p;
while (curr != NULL)
{
if (curr->active)
number_uses[curr->cipher->strength_bits]++;
curr = curr->next;
}
for (i = max_strength_bits; i >= 0; i--)
if (number_uses[i] > 0)
ssl_cipher_apply_rule(0, 0, 0, 0, CIPHER_ORD, i,
list, head_p, tail_p);
OPENSSL_free(number_uses);
return(1);
}
static int ssl_cipher_process_rulestr(const char *rule_str,
CIPHER_ORDER *list, CIPHER_ORDER **head_p,
CIPHER_ORDER **tail_p, SSL_CIPHER **ca_list)
{
unsigned long algorithms, mask, algo_strength, mask_strength;
const char *l, *start, *buf;
int j, multi, found, rule, retval, ok, buflen;
char ch;
retval = 1;
l = rule_str;
for (;;)
{
ch = *l;
if (ch == '\0')
break;
if (ch == '-')
{ rule = CIPHER_DEL; l++; }
else if (ch == '+')
{ rule = CIPHER_ORD; l++; }
else if (ch == '!')
{ rule = CIPHER_KILL; l++; }
else if (ch == '@')
{ rule = CIPHER_SPECIAL; l++; }
else
{ rule = CIPHER_ADD; }
if (ITEM_SEP(ch))
{
l++;
continue;
}
algorithms = mask = algo_strength = mask_strength = 0;
start=l;
for (;;)
{
ch = *l;
buf = l;
buflen = 0;
#ifndef CHARSET_EBCDIC
while ( ((ch >= 'A') && (ch <= 'Z')) ||
((ch >= '0') && (ch <= '9')) ||
((ch >= 'a') && (ch <= 'z')) ||
(ch == '-'))
#else
while ( isalnum(ch) || (ch == '-'))
#endif
{
ch = *(++l);
buflen++;
}
if (buflen == 0)
{
SSLerr(SSL_F_SSL_CIPHER_PROCESS_RULESTR,
SSL_R_INVALID_COMMAND);
retval = found = 0;
l++;
break;
}
if (rule == CIPHER_SPECIAL)
{
found = 0;
break;
}
if (ch == '+')
{
multi=1;
l++;
}
else
multi=0;
j = found = 0;
while (ca_list[j])
{
if ((ca_list[j]->name[buflen] == '\0') &&
!strncmp(buf, ca_list[j]->name, buflen))
{
found = 1;
break;
}
else
j++;
}
if (!found)
break;
algorithms |= ca_list[j]->algorithms;
mask |= ca_list[j]->mask;
algo_strength |= ca_list[j]->algo_strength;
mask_strength |= ca_list[j]->mask_strength;
if (!multi) break;
}
if (rule == CIPHER_SPECIAL)
{
ok = 0;
if ((buflen == 8) &&
!strncmp(buf, "STRENGTH", 8))
ok = ssl_cipher_strength_sort(list,
head_p, tail_p);
else
SSLerr(SSL_F_SSL_CIPHER_PROCESS_RULESTR,
SSL_R_INVALID_COMMAND);
if (ok == 0)
retval = 0;
while ((*l != '\0') && ITEM_SEP(*l))
l++;
}
else if (found)
{
ssl_cipher_apply_rule(algorithms, mask,
algo_strength, mask_strength, rule, -1,
list, head_p, tail_p);
}
else
{
while ((*l != '\0') && ITEM_SEP(*l))
l++;
}
if (*l == '\0') break;
}
return(retval);
}
char *SSL_CIPHER_get_name(SSL_CIPHER *c)
{
if (c != NULL)
return(c->name);
return("(NONE)");
}
int SSL_CIPHER_get_bits(SSL_CIPHER *c, int *alg_bits)
{
int ret=0;
if (c != NULL)
{
if (alg_bits != NULL) *alg_bits = c->alg_bits;
ret = c->strength_bits;
}
return(ret);
}
static int sk_comp_cmp(const SSL_COMP * const *a,
const SSL_COMP * const *b)
{
return((*a)->id-(*b)->id);
}
int SSL_COMP_add_compression_method(int id, COMP_METHOD *cm)
{
SSL_COMP *comp;
STACK_OF(SSL_COMP) *sk;
comp=(SSL_COMP *)OPENSSL_malloc(sizeof(SSL_COMP));
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
