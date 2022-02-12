static int get_optional_pkey_id(const char *pkey_name)
{
const EVP_PKEY_ASN1_METHOD *ameth;
int pkey_id=0;
ameth = EVP_PKEY_asn1_find_str(NULL,pkey_name,-1);
if (ameth)
{
EVP_PKEY_asn1_get0_info(&pkey_id, NULL,NULL,NULL,NULL,ameth);
}
return pkey_id;
}
static int get_optional_pkey_id(const char *pkey_name)
{
const EVP_PKEY_ASN1_METHOD *ameth;
ENGINE *tmpeng = NULL;
int pkey_id=0;
ameth = EVP_PKEY_asn1_find_str(&tmpeng,pkey_name,-1);
if (ameth)
{
EVP_PKEY_asn1_get0_info(&pkey_id, NULL,NULL,NULL,NULL,ameth);
}
if (tmpeng) ENGINE_finish(tmpeng);
return pkey_id;
}
void ssl_load_ciphers(void)
{
ssl_cipher_methods[SSL_ENC_DES_IDX]=
EVP_get_cipherbyname(SN_des_cbc);
ssl_cipher_methods[SSL_ENC_3DES_IDX]=
EVP_get_cipherbyname(SN_des_ede3_cbc);
ssl_cipher_methods[SSL_ENC_RC4_IDX]=
EVP_get_cipherbyname(SN_rc4);
ssl_cipher_methods[SSL_ENC_RC2_IDX]=
EVP_get_cipherbyname(SN_rc2_cbc);
#ifndef OPENSSL_NO_IDEA
ssl_cipher_methods[SSL_ENC_IDEA_IDX]=
EVP_get_cipherbyname(SN_idea_cbc);
#else
ssl_cipher_methods[SSL_ENC_IDEA_IDX]= NULL;
#endif
ssl_cipher_methods[SSL_ENC_AES128_IDX]=
EVP_get_cipherbyname(SN_aes_128_cbc);
ssl_cipher_methods[SSL_ENC_AES256_IDX]=
EVP_get_cipherbyname(SN_aes_256_cbc);
ssl_cipher_methods[SSL_ENC_CAMELLIA128_IDX]=
EVP_get_cipherbyname(SN_camellia_128_cbc);
ssl_cipher_methods[SSL_ENC_CAMELLIA256_IDX]=
EVP_get_cipherbyname(SN_camellia_256_cbc);
ssl_cipher_methods[SSL_ENC_GOST89_IDX]=
EVP_get_cipherbyname(SN_gost89_cnt);
ssl_cipher_methods[SSL_ENC_SEED_IDX]=
EVP_get_cipherbyname(SN_seed_cbc);
ssl_digest_methods[SSL_MD_MD5_IDX]=
EVP_get_digestbyname(SN_md5);
ssl_mac_secret_size[SSL_MD_MD5_IDX]=
EVP_MD_size(ssl_digest_methods[SSL_MD_MD5_IDX]);
OPENSSL_assert(ssl_mac_secret_size[SSL_MD_MD5_IDX] >= 0);
ssl_digest_methods[SSL_MD_SHA1_IDX]=
EVP_get_digestbyname(SN_sha1);
ssl_mac_secret_size[SSL_MD_SHA1_IDX]=
EVP_MD_size(ssl_digest_methods[SSL_MD_SHA1_IDX]);
OPENSSL_assert(ssl_mac_secret_size[SSL_MD_SHA1_IDX] >= 0);
ssl_digest_methods[SSL_MD_GOST94_IDX]=
EVP_get_digestbyname(SN_id_GostR3411_94);
if (ssl_digest_methods[SSL_MD_GOST94_IDX])
{
ssl_mac_secret_size[SSL_MD_GOST94_IDX]=
EVP_MD_size(ssl_digest_methods[SSL_MD_GOST94_IDX]);
OPENSSL_assert(ssl_mac_secret_size[SSL_MD_GOST94_IDX] >= 0);
}
ssl_digest_methods[SSL_MD_GOST89MAC_IDX]=
EVP_get_digestbyname(SN_id_Gost28147_89_MAC);
ssl_mac_pkey_id[SSL_MD_GOST89MAC_IDX] = get_optional_pkey_id("gost-mac");
if (ssl_mac_pkey_id[SSL_MD_GOST89MAC_IDX]) {
ssl_mac_secret_size[SSL_MD_GOST89MAC_IDX]=32;
}
}
static int sk_comp_cmp(const SSL_COMP * const *a,
const SSL_COMP * const *b)
{
return((*a)->id-(*b)->id);
}
static void load_builtin_compressions(void)
{
int got_write_lock = 0;
CRYPTO_r_lock(CRYPTO_LOCK_SSL);
if (ssl_comp_methods == NULL)
{
CRYPTO_r_unlock(CRYPTO_LOCK_SSL);
CRYPTO_w_lock(CRYPTO_LOCK_SSL);
got_write_lock = 1;
if (ssl_comp_methods == NULL)
{
SSL_COMP *comp = NULL;
MemCheck_off();
ssl_comp_methods=sk_SSL_COMP_new(sk_comp_cmp);
if (ssl_comp_methods != NULL)
{
comp=(SSL_COMP *)OPENSSL_malloc(sizeof(SSL_COMP));
if (comp != NULL)
{
comp->method=COMP_zlib();
if (comp->method
&& comp->method->type == NID_undef)
OPENSSL_free(comp);
else
{
comp->id=SSL_COMP_ZLIB_IDX;
comp->name=comp->method->name;
sk_SSL_COMP_push(ssl_comp_methods,comp);
}
}
}
MemCheck_on();
}
}
if (got_write_lock)
CRYPTO_w_unlock(CRYPTO_LOCK_SSL);
else
CRYPTO_r_unlock(CRYPTO_LOCK_SSL);
}
int ssl_cipher_get_evp(const SSL_SESSION *s, const EVP_CIPHER **enc,
const EVP_MD **md, int *mac_pkey_type, int *mac_secret_size,SSL_COMP **comp)
{
int i;
const SSL_CIPHER *c;
c=s->cipher;
if (c == NULL) return(0);
if (comp != NULL)
{
SSL_COMP ctmp;
#ifndef OPENSSL_NO_COMP
load_builtin_compressions();
#endif
*comp=NULL;
ctmp.id=s->compress_meth;
if (ssl_comp_methods != NULL)
{
i=sk_SSL_COMP_find(ssl_comp_methods,&ctmp);
if (i >= 0)
*comp=sk_SSL_COMP_value(ssl_comp_methods,i);
else
*comp=NULL;
}
}
if ((enc == NULL) || (md == NULL)) return(0);
switch (c->algorithm_enc)
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
case SSL_AES128:
i=SSL_ENC_AES128_IDX;
break;
case SSL_AES256:
i=SSL_ENC_AES256_IDX;
break;
case SSL_CAMELLIA128:
i=SSL_ENC_CAMELLIA128_IDX;
break;
case SSL_CAMELLIA256:
i=SSL_ENC_CAMELLIA256_IDX;
break;
case SSL_eGOST2814789CNT:
i=SSL_ENC_GOST89_IDX;
break;
case SSL_SEED:
i=SSL_ENC_SEED_IDX;
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
switch (c->algorithm_mac)
{
case SSL_MD5:
i=SSL_MD_MD5_IDX;
break;
case SSL_SHA1:
i=SSL_MD_SHA1_IDX;
break;
case SSL_GOST94:
i = SSL_MD_GOST94_IDX;
break;
case SSL_GOST89MAC:
i = SSL_MD_GOST89MAC_IDX;
break;
default:
i= -1;
break;
}
if ((i < 0) || (i > SSL_MD_NUM_IDX))
{
*md=NULL;
if (mac_pkey_type!=NULL) *mac_pkey_type = NID_undef;
if (mac_secret_size!=NULL) *mac_secret_size = 0;
}
else
{
*md=ssl_digest_methods[i];
if (mac_pkey_type!=NULL) *mac_pkey_type = ssl_mac_pkey_id[i];
if (mac_secret_size!=NULL) *mac_secret_size = ssl_mac_secret_size[i];
}
if ((*enc != NULL) && (*md != NULL) && (!mac_pkey_type||*mac_pkey_type != NID_undef))
return(1);
else
return(0);
}
int ssl_get_handshake_digest(int idx, long *mask, const EVP_MD **md)
{
if (idx <0||idx>=SSL_MD_NUM_IDX)
{
return 0;
}
if (ssl_handshake_digest_flag[idx]==0) return 0;
*mask = ssl_handshake_digest_flag[idx];
*md = ssl_digest_methods[idx];
return 1;
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
static void ll_append_head(CIPHER_ORDER **head, CIPHER_ORDER *curr,
CIPHER_ORDER **tail)
{
if (curr == *head) return;
if (curr == *tail)
*tail=curr->prev;
if (curr->next != NULL)
curr->next->prev=curr->prev;
if (curr->prev != NULL)
curr->prev->next=curr->next;
(*head)->prev=curr;
curr->next= *head;
curr->prev=NULL;
*head=curr;
}
static void ssl_cipher_get_disabled(unsigned long *mkey, unsigned long *auth, unsigned long *enc, unsigned long *mac, unsigned long *ssl)
{
*mkey = 0;
*auth = 0;
*enc = 0;
*mac = 0;
*ssl = 0;
#ifdef OPENSSL_NO_RSA
*mkey |= SSL_kRSA;
*auth |= SSL_aRSA;
#endif
#ifdef OPENSSL_NO_DSA
*auth |= SSL_aDSS;
#endif
*mkey |= SSL_kDHr|SSL_kDHd;
*auth |= SSL_aDH;
#ifdef OPENSSL_NO_DH
*mkey |= SSL_kDHr|SSL_kDHd|SSL_kEDH;
*auth |= SSL_aDH;
#endif
#ifdef OPENSSL_NO_KRB5
*mkey |= SSL_kKRB5;
*auth |= SSL_aKRB5;
#endif
#ifdef OPENSSL_NO_ECDSA
*auth |= SSL_aECDSA;
#endif
#ifdef OPENSSL_NO_ECDH
*mkey |= SSL_kECDHe|SSL_kECDHr;
*auth |= SSL_aECDH;
#endif
#ifdef OPENSSL_NO_PSK
*mkey |= SSL_kPSK;
*auth |= SSL_aPSK;
#endif
if (!get_optional_pkey_id("gost94")) {
*auth |= SSL_aGOST94;
}
if (!get_optional_pkey_id("gost2001")) {
*auth |= SSL_aGOST01;
}
if ((*auth & (SSL_aGOST94|SSL_aGOST01)) == (SSL_aGOST94|SSL_aGOST01)) {
*mkey |= SSL_kGOST;
}
#ifdef SSL_FORBID_ENULL
*enc |= SSL_eNULL;
#endif
*enc |= (ssl_cipher_methods[SSL_ENC_DES_IDX ] == NULL) ? SSL_DES :0;
*enc |= (ssl_cipher_methods[SSL_ENC_3DES_IDX] == NULL) ? SSL_3DES:0;
*enc |= (ssl_cipher_methods[SSL_ENC_RC4_IDX ] == NULL) ? SSL_RC4 :0;
*enc |= (ssl_cipher_methods[SSL_ENC_RC2_IDX ] == NULL) ? SSL_RC2 :0;
*enc |= (ssl_cipher_methods[SSL_ENC_IDEA_IDX] == NULL) ? SSL_IDEA:0;
*enc |= (ssl_cipher_methods[SSL_ENC_AES128_IDX] == NULL) ? SSL_AES128:0;
*enc |= (ssl_cipher_methods[SSL_ENC_AES256_IDX] == NULL) ? SSL_AES256:0;
*enc |= (ssl_cipher_methods[SSL_ENC_CAMELLIA128_IDX] == NULL) ? SSL_CAMELLIA128:0;
*enc |= (ssl_cipher_methods[SSL_ENC_CAMELLIA256_IDX] == NULL) ? SSL_CAMELLIA256:0;
*enc |= (ssl_cipher_methods[SSL_ENC_GOST89_IDX] == NULL) ? SSL_eGOST2814789CNT:0;
*enc |= (ssl_cipher_methods[SSL_ENC_SEED_IDX] == NULL) ? SSL_SEED:0;
*mac |= (ssl_digest_methods[SSL_MD_MD5_IDX ] == NULL) ? SSL_MD5 :0;
*mac |= (ssl_digest_methods[SSL_MD_SHA1_IDX] == NULL) ? SSL_SHA1:0;
*mac |= (ssl_digest_methods[SSL_MD_GOST94_IDX] == NULL) ? SSL_GOST94:0;
*mac |= (ssl_digest_methods[SSL_MD_GOST89MAC_IDX] == NULL || ssl_mac_pkey_id[SSL_MD_GOST89MAC_IDX]==NID_undef)? SSL_GOST89MAC:0;
}
static void ssl_cipher_collect_ciphers(const SSL_METHOD *ssl_method,
int num_of_ciphers,
unsigned long disabled_mkey, unsigned long disabled_auth,
unsigned long disabled_enc, unsigned long disabled_mac,
unsigned long disabled_ssl,
CIPHER_ORDER *co_list,
CIPHER_ORDER **head_p, CIPHER_ORDER **tail_p)
{
int i, co_list_num;
const SSL_CIPHER *c;
co_list_num = 0;
for (i = 0; i < num_of_ciphers; i++)
{
c = ssl_method->get_cipher(i);
if ((c != NULL) && c->valid &&
!(c->algorithm_mkey & disabled_mkey) &&
!(c->algorithm_auth & disabled_auth) &&
!(c->algorithm_enc & disabled_enc) &&
!(c->algorithm_mac & disabled_mac) &&
!(c->algorithm_ssl & disabled_ssl))
{
co_list[co_list_num].cipher = c;
co_list[co_list_num].next = NULL;
co_list[co_list_num].prev = NULL;
co_list[co_list_num].active = 0;
co_list_num++;
#ifdef KSSL_DEBUG
printf("\t%d: %s %lx %lx %lx\n",i,c->name,c->id,c->algorithm_mkey,c->algorithm_auth);
#endif
}
}
if (co_list_num > 0)
{
co_list[0].prev = NULL;
if (co_list_num > 1)
{
co_list[0].next = &co_list[1];
for (i = 1; i < co_list_num - 1; i++)
{
co_list[i].prev = &co_list[i - 1];
co_list[i].next = &co_list[i + 1];
}
co_list[co_list_num - 1].prev = &co_list[co_list_num - 2];
}
co_list[co_list_num - 1].next = NULL;
*head_p = &co_list[0];
*tail_p = &co_list[co_list_num - 1];
}
}
static void ssl_cipher_collect_aliases(const SSL_CIPHER **ca_list,
int num_of_group_aliases,
unsigned long disabled_mkey, unsigned long disabled_auth,
unsigned long disabled_enc, unsigned long disabled_mac,
unsigned long disabled_ssl,
CIPHER_ORDER *head)
{
CIPHER_ORDER *ciph_curr;
const SSL_CIPHER **ca_curr;
int i;
unsigned long mask_mkey = ~disabled_mkey;
unsigned long mask_auth = ~disabled_auth;
unsigned long mask_enc = ~disabled_enc;
unsigned long mask_mac = ~disabled_mac;
unsigned long mask_ssl = ~disabled_ssl;
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
unsigned long algorithm_mkey = cipher_aliases[i].algorithm_mkey;
unsigned long algorithm_auth = cipher_aliases[i].algorithm_auth;
unsigned long algorithm_enc = cipher_aliases[i].algorithm_enc;
unsigned long algorithm_mac = cipher_aliases[i].algorithm_mac;
unsigned long algorithm_ssl = cipher_aliases[i].algorithm_ssl;
if (algorithm_mkey)
if ((algorithm_mkey & mask_mkey) == 0)
continue;
if (algorithm_auth)
if ((algorithm_auth & mask_auth) == 0)
continue;
if (algorithm_enc)
if ((algorithm_enc & mask_enc) == 0)
continue;
if (algorithm_mac)
if ((algorithm_mac & mask_mac) == 0)
continue;
if (algorithm_ssl)
if ((algorithm_ssl & mask_ssl) == 0)
continue;
*ca_curr = (SSL_CIPHER *)(cipher_aliases + i);
ca_curr++;
}
*ca_curr = NULL;
}
static void ssl_cipher_apply_rule(unsigned long cipher_id,
unsigned long alg_mkey, unsigned long alg_auth,
unsigned long alg_enc, unsigned long alg_mac,
unsigned long alg_ssl,
unsigned long algo_strength,
int rule, int strength_bits,
CIPHER_ORDER **head_p, CIPHER_ORDER **tail_p)
{
CIPHER_ORDER *head, *tail, *curr, *curr2, *last;
const SSL_CIPHER *cp;
int reverse = 0;
#ifdef CIPHER_DEBUG
printf("Applying rule %d with %08lx/%08lx/%08lx/%08lx/%08lx %08lx (%d)\n",
rule, alg_mkey, alg_auth, alg_enc, alg_mac, alg_ssl, algo_strength, strength_bits);
#endif
if (rule == CIPHER_DEL)
reverse = 1;
head = *head_p;
tail = *tail_p;
if (reverse)
{
curr = tail;
last = head;
}
else
{
curr = head;
last = tail;
}
curr2 = curr;
for (;;)
{
if ((curr == NULL) || (curr == last)) break;
curr = curr2;
curr2 = reverse ? curr->prev : curr->next;
cp = curr->cipher;
if (strength_bits >= 0)
{
if (strength_bits != cp->strength_bits)
continue;
}
else
{
#ifdef CIPHER_DEBUG
printf("\nName: %s:\nAlgo = %08lx/%08lx/%08lx/%08lx/%08lx Algo_strength = %08lx\n", cp->name, cp->algorithm_mkey, cp->algorithm_auth, cp->algorithm_enc, cp->algorithm_mac, cp->algorithm_ssl, cp->algo_strength);
#endif
if (alg_mkey && !(alg_mkey & cp->algorithm_mkey))
continue;
if (alg_auth && !(alg_auth & cp->algorithm_auth))
continue;
if (alg_enc && !(alg_enc & cp->algorithm_enc))
continue;
if (alg_mac && !(alg_mac & cp->algorithm_mac))
continue;
if (alg_ssl && !(alg_ssl & cp->algorithm_ssl))
continue;
if ((algo_strength & SSL_EXP_MASK) && !(algo_strength & SSL_EXP_MASK & cp->algo_strength))
continue;
if ((algo_strength & SSL_STRONG_MASK) && !(algo_strength & SSL_STRONG_MASK & cp->algo_strength))
continue;
}
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
{
if (curr->active)
{
ll_append_head(&head, curr, &tail);
curr->active = 0;
}
}
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
static int ssl_cipher_strength_sort(CIPHER_ORDER **head_p,
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
ssl_cipher_apply_rule(0, 0, 0, 0, 0, 0, 0, CIPHER_ORD, i, head_p, tail_p);
OPENSSL_free(number_uses);
return(1);
}
static int ssl_cipher_process_rulestr(const char *rule_str,
CIPHER_ORDER **head_p, CIPHER_ORDER **tail_p,
const SSL_CIPHER **ca_list)
{
unsigned long alg_mkey, alg_auth, alg_enc, alg_mac, alg_ssl, algo_strength;
const char *l, *start, *buf;
int j, multi, found, rule, retval, ok, buflen;
unsigned long cipher_id = 0;
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
alg_mkey = 0;
alg_auth = 0;
alg_enc = 0;
alg_mac = 0;
alg_ssl = 0;
algo_strength = 0;
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
cipher_id = 0;
while (ca_list[j])
{
if (!strncmp(buf, ca_list[j]->name, buflen) &&
(ca_list[j]->name[buflen] == '\0'))
{
found = 1;
break;
}
else
j++;
}
if (!found)
break;
if (ca_list[j]->algorithm_mkey)
{
if (alg_mkey)
{
alg_mkey &= ca_list[j]->algorithm_mkey;
if (!alg_mkey) { found = 0; break; }
}
else
alg_mkey = ca_list[j]->algorithm_mkey;
}
if (ca_list[j]->algorithm_auth)
{
if (alg_auth)
{
alg_auth &= ca_list[j]->algorithm_auth;
if (!alg_auth) { found = 0; break; }
}
else
alg_auth = ca_list[j]->algorithm_auth;
}
if (ca_list[j]->algorithm_enc)
{
if (alg_enc)
{
alg_enc &= ca_list[j]->algorithm_enc;
if (!alg_enc) { found = 0; break; }
}
else
alg_enc = ca_list[j]->algorithm_enc;
}
if (ca_list[j]->algorithm_mac)
{
if (alg_mac)
{
alg_mac &= ca_list[j]->algorithm_mac;
if (!alg_mac) { found = 0; break; }
}
else
alg_mac = ca_list[j]->algorithm_mac;
}
if (ca_list[j]->algo_strength & SSL_EXP_MASK)
{
if (algo_strength & SSL_EXP_MASK)
{
algo_strength &= (ca_list[j]->algo_strength & SSL_EXP_MASK) | ~SSL_EXP_MASK;
if (!(algo_strength & SSL_EXP_MASK)) { found = 0; break; }
}
else
algo_strength |= ca_list[j]->algo_strength & SSL_EXP_MASK;
}
if (ca_list[j]->algo_strength & SSL_STRONG_MASK)
{
if (algo_strength & SSL_STRONG_MASK)
{
algo_strength &= (ca_list[j]->algo_strength & SSL_STRONG_MASK) | ~SSL_STRONG_MASK;
if (!(algo_strength & SSL_STRONG_MASK)) { found = 0; break; }
}
else
algo_strength |= ca_list[j]->algo_strength & SSL_STRONG_MASK;
}
if (ca_list[j]->valid)
{
cipher_id = ca_list[j]->id;
}
else
{
if (ca_list[j]->algorithm_ssl)
{
if (alg_ssl)
{
alg_ssl &= ca_list[j]->algorithm_ssl;
if (!alg_ssl) { found = 0; break; }
}
else
alg_ssl = ca_list[j]->algorithm_ssl;
}
}
if (!multi) break;
}
if (rule == CIPHER_SPECIAL)
{
ok = 0;
if ((buflen == 8) &&
!strncmp(buf, "STRENGTH", 8))
ok = ssl_cipher_strength_sort(head_p, tail_p);
else
SSLerr(SSL_F_SSL_CIPHER_PROCESS_RULESTR,
SSL_R_INVALID_COMMAND);
if (ok == 0)
retval = 0;
while ((*l != '\0') && !ITEM_SEP(*l))
l++;
}
else if (found)
{
ssl_cipher_apply_rule(cipher_id,
alg_mkey, alg_auth, alg_enc, alg_mac, alg_ssl, algo_strength,
rule, -1, head_p, tail_p);
}
else
{
while ((*l != '\0') && !ITEM_SEP(*l))
l++;
}
if (*l == '\0') break;
}
return(retval);
}
char *SSL_CIPHER_get_name(const SSL_CIPHER *c)
{
if (c != NULL)
return(c->name);
return("(NONE)");
}
int SSL_CIPHER_get_bits(const SSL_CIPHER *c, int *alg_bits)
{
int ret=0;
if (c != NULL)
{
if (alg_bits != NULL) *alg_bits = c->alg_bits;
ret = c->strength_bits;
}
return(ret);
}
void *SSL_COMP_get_compression_methods(void)
{
return NULL;
}
int SSL_COMP_add_compression_method(int id, void *cm)
{
return 1;
}
const char *SSL_COMP_get_name(const void *comp)
{
return NULL;
}
int SSL_COMP_add_compression_method(int id, COMP_METHOD *cm)
{
SSL_COMP *comp;
if (cm == NULL || cm->type == NID_undef)
return 1;
if (id < 193 || id > 255)
{
SSLerr(SSL_F_SSL_COMP_ADD_COMPRESSION_METHOD,SSL_R_COMPRESSION_ID_NOT_WITHIN_PRIVATE_RANGE);
return 0;
}
MemCheck_off();
comp=(SSL_COMP *)OPENSSL_malloc(sizeof(SSL_COMP));
comp->id=id;
comp->method=cm;
load_builtin_compressions();
if (ssl_comp_methods
&& sk_SSL_COMP_find(ssl_comp_methods,comp) >= 0)
{
OPENSSL_free(comp);
MemCheck_on();
SSLerr(SSL_F_SSL_COMP_ADD_COMPRESSION_METHOD,SSL_R_DUPLICATE_COMPRESSION_ID);
return(1);
}
else if ((ssl_comp_methods == NULL)
|| !sk_SSL_COMP_push(ssl_comp_methods,comp))
{
OPENSSL_free(comp);
MemCheck_on();
SSLerr(SSL_F_SSL_COMP_ADD_COMPRESSION_METHOD,ERR_R_MALLOC_FAILURE);
return(1);
}
else
{
MemCheck_on();
return(0);
}
}
const char *SSL_COMP_get_name(const COMP_METHOD *comp)
{
if (comp)
return comp->name;
return NULL;
}
