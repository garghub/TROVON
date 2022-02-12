static int ssl_cipher_info_find(const ssl_cipher_table * table,
size_t table_cnt, uint32_t mask)
{
size_t i;
for (i = 0; i < table_cnt; i++, table++) {
if (table->mask == mask)
return i;
}
return -1;
}
static int get_optional_pkey_id(const char *pkey_name)
{
const EVP_PKEY_ASN1_METHOD *ameth;
int pkey_id = 0;
ameth = EVP_PKEY_asn1_find_str(NULL, pkey_name, -1);
if (ameth && EVP_PKEY_asn1_get0_info(&pkey_id, NULL, NULL, NULL, NULL,
ameth) > 0) {
return pkey_id;
}
return 0;
}
static int get_optional_pkey_id(const char *pkey_name)
{
const EVP_PKEY_ASN1_METHOD *ameth;
ENGINE *tmpeng = NULL;
int pkey_id = 0;
ameth = EVP_PKEY_asn1_find_str(&tmpeng, pkey_name, -1);
if (ameth) {
if (EVP_PKEY_asn1_get0_info(&pkey_id, NULL, NULL, NULL, NULL,
ameth) <= 0)
pkey_id = 0;
}
ENGINE_finish(tmpeng);
return pkey_id;
}
void ssl_load_ciphers(void)
{
size_t i;
const ssl_cipher_table *t;
disabled_enc_mask = 0;
ssl_sort_cipher_list();
for (i = 0, t = ssl_cipher_table_cipher; i < SSL_ENC_NUM_IDX; i++, t++) {
if (t->nid == NID_undef) {
ssl_cipher_methods[i] = NULL;
} else {
const EVP_CIPHER *cipher = EVP_get_cipherbynid(t->nid);
ssl_cipher_methods[i] = cipher;
if (cipher == NULL)
disabled_enc_mask |= t->mask;
}
}
#ifdef SSL_FORBID_ENULL
disabled_enc_mask |= SSL_eNULL;
#endif
disabled_mac_mask = 0;
for (i = 0, t = ssl_cipher_table_mac; i < SSL_MD_NUM_IDX; i++, t++) {
const EVP_MD *md = EVP_get_digestbynid(t->nid);
ssl_digest_methods[i] = md;
if (md == NULL) {
disabled_mac_mask |= t->mask;
} else {
ssl_mac_secret_size[i] = EVP_MD_size(md);
OPENSSL_assert(ssl_mac_secret_size[i] >= 0);
}
}
OPENSSL_assert(ssl_digest_methods[SSL_MD_MD5_IDX] != NULL);
OPENSSL_assert(ssl_digest_methods[SSL_MD_SHA1_IDX] != NULL);
disabled_mkey_mask = 0;
disabled_auth_mask = 0;
#ifdef OPENSSL_NO_RSA
disabled_mkey_mask |= SSL_kRSA | SSL_kRSAPSK;
disabled_auth_mask |= SSL_aRSA;
#endif
#ifdef OPENSSL_NO_DSA
disabled_auth_mask |= SSL_aDSS;
#endif
#ifdef OPENSSL_NO_DH
disabled_mkey_mask |= SSL_kDHE | SSL_kDHEPSK;
#endif
#ifdef OPENSSL_NO_EC
disabled_mkey_mask |= SSL_kECDHEPSK;
disabled_auth_mask |= SSL_aECDSA;
#endif
#ifdef OPENSSL_NO_PSK
disabled_mkey_mask |= SSL_PSK;
disabled_auth_mask |= SSL_aPSK;
#endif
#ifdef OPENSSL_NO_SRP
disabled_mkey_mask |= SSL_kSRP;
#endif
ssl_mac_pkey_id[SSL_MD_GOST89MAC_IDX] = get_optional_pkey_id("gost-mac");
if (ssl_mac_pkey_id[SSL_MD_GOST89MAC_IDX]) {
ssl_mac_secret_size[SSL_MD_GOST89MAC_IDX] = 32;
} else {
disabled_mac_mask |= SSL_GOST89MAC;
}
ssl_mac_pkey_id[SSL_MD_GOST89MAC12_IDX] =
get_optional_pkey_id("gost-mac-12");
if (ssl_mac_pkey_id[SSL_MD_GOST89MAC12_IDX]) {
ssl_mac_secret_size[SSL_MD_GOST89MAC12_IDX] = 32;
} else {
disabled_mac_mask |= SSL_GOST89MAC12;
}
if (!get_optional_pkey_id("gost2001"))
disabled_auth_mask |= SSL_aGOST01 | SSL_aGOST12;
if (!get_optional_pkey_id("gost2012_256"))
disabled_auth_mask |= SSL_aGOST12;
if (!get_optional_pkey_id("gost2012_512"))
disabled_auth_mask |= SSL_aGOST12;
if ((disabled_auth_mask & (SSL_aGOST01 | SSL_aGOST12)) ==
(SSL_aGOST01 | SSL_aGOST12))
disabled_mkey_mask |= SSL_kGOST;
}
static int sk_comp_cmp(const SSL_COMP *const *a, const SSL_COMP *const *b)
{
return ((*a)->id - (*b)->id);
}
static int load_builtin_compressions(void)
{
return RUN_ONCE(&ssl_load_builtin_comp_once, do_load_builtin_compressions);
}
int ssl_cipher_get_evp(const SSL_SESSION *s, const EVP_CIPHER **enc,
const EVP_MD **md, int *mac_pkey_type,
int *mac_secret_size, SSL_COMP **comp, int use_etm)
{
int i;
const SSL_CIPHER *c;
c = s->cipher;
if (c == NULL)
return (0);
if (comp != NULL) {
SSL_COMP ctmp;
#ifndef OPENSSL_NO_COMP
if (!load_builtin_compressions()) {
}
#endif
*comp = NULL;
ctmp.id = s->compress_meth;
if (ssl_comp_methods != NULL) {
i = sk_SSL_COMP_find(ssl_comp_methods, &ctmp);
if (i >= 0)
*comp = sk_SSL_COMP_value(ssl_comp_methods, i);
else
*comp = NULL;
}
if ((enc == NULL) && (md == NULL))
return 1;
}
if ((enc == NULL) || (md == NULL))
return 0;
i = ssl_cipher_info_lookup(ssl_cipher_table_cipher, c->algorithm_enc);
if (i == -1)
*enc = NULL;
else {
if (i == SSL_ENC_NULL_IDX)
*enc = EVP_enc_null();
else
*enc = ssl_cipher_methods[i];
}
i = ssl_cipher_info_lookup(ssl_cipher_table_mac, c->algorithm_mac);
if (i == -1) {
*md = NULL;
if (mac_pkey_type != NULL)
*mac_pkey_type = NID_undef;
if (mac_secret_size != NULL)
*mac_secret_size = 0;
if (c->algorithm_mac == SSL_AEAD)
mac_pkey_type = NULL;
} else {
*md = ssl_digest_methods[i];
if (mac_pkey_type != NULL)
*mac_pkey_type = ssl_mac_pkey_id[i];
if (mac_secret_size != NULL)
*mac_secret_size = ssl_mac_secret_size[i];
}
if ((*enc != NULL) &&
(*md != NULL || (EVP_CIPHER_flags(*enc) & EVP_CIPH_FLAG_AEAD_CIPHER))
&& (!mac_pkey_type || *mac_pkey_type != NID_undef)) {
const EVP_CIPHER *evp;
if (use_etm)
return 1;
if (s->ssl_version >> 8 != TLS1_VERSION_MAJOR ||
s->ssl_version < TLS1_VERSION)
return 1;
if (FIPS_mode())
return 1;
if (c->algorithm_enc == SSL_RC4 &&
c->algorithm_mac == SSL_MD5 &&
(evp = EVP_get_cipherbyname("RC4-HMAC-MD5")))
*enc = evp, *md = NULL;
else if (c->algorithm_enc == SSL_AES128 &&
c->algorithm_mac == SSL_SHA1 &&
(evp = EVP_get_cipherbyname("AES-128-CBC-HMAC-SHA1")))
*enc = evp, *md = NULL;
else if (c->algorithm_enc == SSL_AES256 &&
c->algorithm_mac == SSL_SHA1 &&
(evp = EVP_get_cipherbyname("AES-256-CBC-HMAC-SHA1")))
*enc = evp, *md = NULL;
else if (c->algorithm_enc == SSL_AES128 &&
c->algorithm_mac == SSL_SHA256 &&
(evp = EVP_get_cipherbyname("AES-128-CBC-HMAC-SHA256")))
*enc = evp, *md = NULL;
else if (c->algorithm_enc == SSL_AES256 &&
c->algorithm_mac == SSL_SHA256 &&
(evp = EVP_get_cipherbyname("AES-256-CBC-HMAC-SHA256")))
*enc = evp, *md = NULL;
return (1);
} else
return (0);
}
const EVP_MD *ssl_md(int idx)
{
idx &= SSL_HANDSHAKE_MAC_MASK;
if (idx < 0 || idx >= SSL_MD_NUM_IDX)
return NULL;
return ssl_digest_methods[idx];
}
const EVP_MD *ssl_handshake_md(SSL *s)
{
return ssl_md(ssl_get_algorithm2(s));
}
const EVP_MD *ssl_prf_md(SSL *s)
{
return ssl_md(ssl_get_algorithm2(s) >> TLS1_PRF_DGST_SHIFT);
}
static void ll_append_tail(CIPHER_ORDER **head, CIPHER_ORDER *curr,
CIPHER_ORDER **tail)
{
if (curr == *tail)
return;
if (curr == *head)
*head = curr->next;
if (curr->prev != NULL)
curr->prev->next = curr->next;
if (curr->next != NULL)
curr->next->prev = curr->prev;
(*tail)->next = curr;
curr->prev = *tail;
curr->next = NULL;
*tail = curr;
}
static void ll_append_head(CIPHER_ORDER **head, CIPHER_ORDER *curr,
CIPHER_ORDER **tail)
{
if (curr == *head)
return;
if (curr == *tail)
*tail = curr->prev;
if (curr->next != NULL)
curr->next->prev = curr->prev;
if (curr->prev != NULL)
curr->prev->next = curr->next;
(*head)->prev = curr;
curr->next = *head;
curr->prev = NULL;
*head = curr;
}
static void ssl_cipher_collect_ciphers(const SSL_METHOD *ssl_method,
int num_of_ciphers,
uint32_t disabled_mkey,
uint32_t disabled_auth,
uint32_t disabled_enc,
uint32_t disabled_mac,
CIPHER_ORDER *co_list,
CIPHER_ORDER **head_p,
CIPHER_ORDER **tail_p)
{
int i, co_list_num;
const SSL_CIPHER *c;
co_list_num = 0;
for (i = 0; i < num_of_ciphers; i++) {
c = ssl_method->get_cipher(i);
if (c == NULL || !c->valid)
continue;
if (FIPS_mode() && (c->algo_strength & SSL_FIPS))
continue;
if ((c->algorithm_mkey & disabled_mkey) ||
(c->algorithm_auth & disabled_auth) ||
(c->algorithm_enc & disabled_enc) ||
(c->algorithm_mac & disabled_mac))
continue;
if (((ssl_method->ssl3_enc->enc_flags & SSL_ENC_FLAG_DTLS) == 0) &&
c->min_tls == 0)
continue;
if (((ssl_method->ssl3_enc->enc_flags & SSL_ENC_FLAG_DTLS) != 0) &&
c->min_dtls == 0)
continue;
co_list[co_list_num].cipher = c;
co_list[co_list_num].next = NULL;
co_list[co_list_num].prev = NULL;
co_list[co_list_num].active = 0;
co_list_num++;
}
if (co_list_num > 0) {
co_list[0].prev = NULL;
if (co_list_num > 1) {
co_list[0].next = &co_list[1];
for (i = 1; i < co_list_num - 1; i++) {
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
uint32_t disabled_mkey,
uint32_t disabled_auth,
uint32_t disabled_enc,
uint32_t disabled_mac,
CIPHER_ORDER *head)
{
CIPHER_ORDER *ciph_curr;
const SSL_CIPHER **ca_curr;
int i;
uint32_t mask_mkey = ~disabled_mkey;
uint32_t mask_auth = ~disabled_auth;
uint32_t mask_enc = ~disabled_enc;
uint32_t mask_mac = ~disabled_mac;
ciph_curr = head;
ca_curr = ca_list;
while (ciph_curr != NULL) {
*ca_curr = ciph_curr->cipher;
ca_curr++;
ciph_curr = ciph_curr->next;
}
for (i = 0; i < num_of_group_aliases; i++) {
uint32_t algorithm_mkey = cipher_aliases[i].algorithm_mkey;
uint32_t algorithm_auth = cipher_aliases[i].algorithm_auth;
uint32_t algorithm_enc = cipher_aliases[i].algorithm_enc;
uint32_t algorithm_mac = cipher_aliases[i].algorithm_mac;
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
*ca_curr = (SSL_CIPHER *)(cipher_aliases + i);
ca_curr++;
}
*ca_curr = NULL;
}
static void ssl_cipher_apply_rule(uint32_t cipher_id, uint32_t alg_mkey,
uint32_t alg_auth, uint32_t alg_enc,
uint32_t alg_mac, int min_tls,
uint32_t algo_strength, int rule,
int32_t strength_bits, CIPHER_ORDER **head_p,
CIPHER_ORDER **tail_p)
{
CIPHER_ORDER *head, *tail, *curr, *next, *last;
const SSL_CIPHER *cp;
int reverse = 0;
#ifdef CIPHER_DEBUG
fprintf(stderr,
"Applying rule %d with %08x/%08x/%08x/%08x/%08x %08x (%d)\n",
rule, alg_mkey, alg_auth, alg_enc, alg_mac, min_tls,
algo_strength, strength_bits);
#endif
if (rule == CIPHER_DEL || rule == CIPHER_BUMP)
reverse = 1;
head = *head_p;
tail = *tail_p;
if (reverse) {
next = tail;
last = head;
} else {
next = head;
last = tail;
}
curr = NULL;
for (;;) {
if (curr == last)
break;
curr = next;
if (curr == NULL)
break;
next = reverse ? curr->prev : curr->next;
cp = curr->cipher;
if (strength_bits >= 0) {
if (strength_bits != cp->strength_bits)
continue;
} else {
#ifdef CIPHER_DEBUG
fprintf(stderr,
"\nName: %s:\nAlgo = %08x/%08x/%08x/%08x/%08x Algo_strength = %08x\n",
cp->name, cp->algorithm_mkey, cp->algorithm_auth,
cp->algorithm_enc, cp->algorithm_mac, cp->min_tls,
cp->algo_strength);
#endif
if (alg_mkey && !(alg_mkey & cp->algorithm_mkey))
continue;
if (alg_auth && !(alg_auth & cp->algorithm_auth))
continue;
if (alg_enc && !(alg_enc & cp->algorithm_enc))
continue;
if (alg_mac && !(alg_mac & cp->algorithm_mac))
continue;
if (min_tls && (min_tls != cp->min_tls))
continue;
if ((algo_strength & SSL_STRONG_MASK)
&& !(algo_strength & SSL_STRONG_MASK & cp->algo_strength))
continue;
if ((algo_strength & SSL_DEFAULT_MASK)
&& !(algo_strength & SSL_DEFAULT_MASK & cp->algo_strength))
continue;
}
#ifdef CIPHER_DEBUG
fprintf(stderr, "Action = %d\n", rule);
#endif
if (rule == CIPHER_ADD) {
if (!curr->active) {
ll_append_tail(&head, curr, &tail);
curr->active = 1;
}
}
else if (rule == CIPHER_ORD) {
if (curr->active) {
ll_append_tail(&head, curr, &tail);
}
} else if (rule == CIPHER_DEL) {
if (curr->active) {
ll_append_head(&head, curr, &tail);
curr->active = 0;
}
} else if (rule == CIPHER_BUMP) {
if (curr->active)
ll_append_head(&head, curr, &tail);
} else if (rule == CIPHER_KILL) {
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
int32_t max_strength_bits;
int i, *number_uses;
CIPHER_ORDER *curr;
max_strength_bits = 0;
curr = *head_p;
while (curr != NULL) {
if (curr->active && (curr->cipher->strength_bits > max_strength_bits))
max_strength_bits = curr->cipher->strength_bits;
curr = curr->next;
}
number_uses = OPENSSL_zalloc(sizeof(int) * (max_strength_bits + 1));
if (number_uses == NULL) {
SSLerr(SSL_F_SSL_CIPHER_STRENGTH_SORT, ERR_R_MALLOC_FAILURE);
return (0);
}
curr = *head_p;
while (curr != NULL) {
if (curr->active)
number_uses[curr->cipher->strength_bits]++;
curr = curr->next;
}
for (i = max_strength_bits; i >= 0; i--)
if (number_uses[i] > 0)
ssl_cipher_apply_rule(0, 0, 0, 0, 0, 0, 0, CIPHER_ORD, i, head_p,
tail_p);
OPENSSL_free(number_uses);
return (1);
}
static int ssl_cipher_process_rulestr(const char *rule_str,
CIPHER_ORDER **head_p,
CIPHER_ORDER **tail_p,
const SSL_CIPHER **ca_list, CERT *c)
{
uint32_t alg_mkey, alg_auth, alg_enc, alg_mac, algo_strength;
int min_tls;
const char *l, *buf;
int j, multi, found, rule, retval, ok, buflen;
uint32_t cipher_id = 0;
char ch;
retval = 1;
l = rule_str;
for (;;) {
ch = *l;
if (ch == '\0')
break;
if (ch == '-') {
rule = CIPHER_DEL;
l++;
} else if (ch == '+') {
rule = CIPHER_ORD;
l++;
} else if (ch == '!') {
rule = CIPHER_KILL;
l++;
} else if (ch == '@') {
rule = CIPHER_SPECIAL;
l++;
} else {
rule = CIPHER_ADD;
}
if (ITEM_SEP(ch)) {
l++;
continue;
}
alg_mkey = 0;
alg_auth = 0;
alg_enc = 0;
alg_mac = 0;
min_tls = 0;
algo_strength = 0;
for (;;) {
ch = *l;
buf = l;
buflen = 0;
#ifndef CHARSET_EBCDIC
while (((ch >= 'A') && (ch <= 'Z')) ||
((ch >= '0') && (ch <= '9')) ||
((ch >= 'a') && (ch <= 'z')) ||
(ch == '-') || (ch == '.') || (ch == '='))
#else
while (isalnum(ch) || (ch == '-') || (ch == '.') || (ch == '='))
#endif
{
ch = *(++l);
buflen++;
}
if (buflen == 0) {
SSLerr(SSL_F_SSL_CIPHER_PROCESS_RULESTR, SSL_R_INVALID_COMMAND);
retval = found = 0;
l++;
break;
}
if (rule == CIPHER_SPECIAL) {
found = 0;
break;
}
if (ch == '+') {
multi = 1;
l++;
} else
multi = 0;
j = found = 0;
cipher_id = 0;
while (ca_list[j]) {
if (strncmp(buf, ca_list[j]->name, buflen) == 0
&& (ca_list[j]->name[buflen] == '\0')) {
found = 1;
break;
} else
j++;
}
if (!found)
break;
if (ca_list[j]->algorithm_mkey) {
if (alg_mkey) {
alg_mkey &= ca_list[j]->algorithm_mkey;
if (!alg_mkey) {
found = 0;
break;
}
} else
alg_mkey = ca_list[j]->algorithm_mkey;
}
if (ca_list[j]->algorithm_auth) {
if (alg_auth) {
alg_auth &= ca_list[j]->algorithm_auth;
if (!alg_auth) {
found = 0;
break;
}
} else
alg_auth = ca_list[j]->algorithm_auth;
}
if (ca_list[j]->algorithm_enc) {
if (alg_enc) {
alg_enc &= ca_list[j]->algorithm_enc;
if (!alg_enc) {
found = 0;
break;
}
} else
alg_enc = ca_list[j]->algorithm_enc;
}
if (ca_list[j]->algorithm_mac) {
if (alg_mac) {
alg_mac &= ca_list[j]->algorithm_mac;
if (!alg_mac) {
found = 0;
break;
}
} else
alg_mac = ca_list[j]->algorithm_mac;
}
if (ca_list[j]->algo_strength & SSL_STRONG_MASK) {
if (algo_strength & SSL_STRONG_MASK) {
algo_strength &=
(ca_list[j]->algo_strength & SSL_STRONG_MASK) |
~SSL_STRONG_MASK;
if (!(algo_strength & SSL_STRONG_MASK)) {
found = 0;
break;
}
} else
algo_strength = ca_list[j]->algo_strength & SSL_STRONG_MASK;
}
if (ca_list[j]->algo_strength & SSL_DEFAULT_MASK) {
if (algo_strength & SSL_DEFAULT_MASK) {
algo_strength &=
(ca_list[j]->algo_strength & SSL_DEFAULT_MASK) |
~SSL_DEFAULT_MASK;
if (!(algo_strength & SSL_DEFAULT_MASK)) {
found = 0;
break;
}
} else
algo_strength |=
ca_list[j]->algo_strength & SSL_DEFAULT_MASK;
}
if (ca_list[j]->valid) {
cipher_id = ca_list[j]->id;
} else {
if (ca_list[j]->min_tls) {
if (min_tls != 0 && min_tls != ca_list[j]->min_tls) {
found = 0;
break;
} else {
min_tls = ca_list[j]->min_tls;
}
}
}
if (!multi)
break;
}
if (rule == CIPHER_SPECIAL) {
ok = 0;
if ((buflen == 8) && strncmp(buf, "STRENGTH", 8) == 0)
ok = ssl_cipher_strength_sort(head_p, tail_p);
else if (buflen == 10 && strncmp(buf, "SECLEVEL=", 9) == 0) {
int level = buf[9] - '0';
if (level < 0 || level > 5) {
SSLerr(SSL_F_SSL_CIPHER_PROCESS_RULESTR,
SSL_R_INVALID_COMMAND);
} else {
c->sec_level = level;
ok = 1;
}
} else
SSLerr(SSL_F_SSL_CIPHER_PROCESS_RULESTR, SSL_R_INVALID_COMMAND);
if (ok == 0)
retval = 0;
while ((*l != '\0') && !ITEM_SEP(*l))
l++;
} else if (found) {
ssl_cipher_apply_rule(cipher_id,
alg_mkey, alg_auth, alg_enc, alg_mac,
min_tls, algo_strength, rule, -1, head_p,
tail_p);
} else {
while ((*l != '\0') && !ITEM_SEP(*l))
l++;
}
if (*l == '\0')
break;
}
return (retval);
}
static int check_suiteb_cipher_list(const SSL_METHOD *meth, CERT *c,
const char **prule_str)
{
unsigned int suiteb_flags = 0, suiteb_comb2 = 0;
if (strncmp(*prule_str, "SUITEB128ONLY", 13) == 0) {
suiteb_flags = SSL_CERT_FLAG_SUITEB_128_LOS_ONLY;
} else if (strncmp(*prule_str, "SUITEB128C2", 11) == 0) {
suiteb_comb2 = 1;
suiteb_flags = SSL_CERT_FLAG_SUITEB_128_LOS;
} else if (strncmp(*prule_str, "SUITEB128", 9) == 0) {
suiteb_flags = SSL_CERT_FLAG_SUITEB_128_LOS;
} else if (strncmp(*prule_str, "SUITEB192", 9) == 0) {
suiteb_flags = SSL_CERT_FLAG_SUITEB_192_LOS;
}
if (suiteb_flags) {
c->cert_flags &= ~SSL_CERT_FLAG_SUITEB_128_LOS;
c->cert_flags |= suiteb_flags;
} else
suiteb_flags = c->cert_flags & SSL_CERT_FLAG_SUITEB_128_LOS;
if (!suiteb_flags)
return 1;
if (!(meth->ssl3_enc->enc_flags & SSL_ENC_FLAG_TLS1_2_CIPHERS)) {
SSLerr(SSL_F_CHECK_SUITEB_CIPHER_LIST,
SSL_R_AT_LEAST_TLS_1_2_NEEDED_IN_SUITEB_MODE);
return 0;
}
# ifndef OPENSSL_NO_EC
switch (suiteb_flags) {
case SSL_CERT_FLAG_SUITEB_128_LOS:
if (suiteb_comb2)
*prule_str = "ECDHE-ECDSA-AES256-GCM-SHA384";
else
*prule_str =
"ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384";
break;
case SSL_CERT_FLAG_SUITEB_128_LOS_ONLY:
*prule_str = "ECDHE-ECDSA-AES128-GCM-SHA256";
break;
case SSL_CERT_FLAG_SUITEB_192_LOS:
*prule_str = "ECDHE-ECDSA-AES256-GCM-SHA384";
break;
}
return 1;
# else
SSLerr(SSL_F_CHECK_SUITEB_CIPHER_LIST, SSL_R_ECDH_REQUIRED_FOR_SUITEB_MODE);
return 0;
# endif
}
char *SSL_CIPHER_get_version(const SSL_CIPHER *c)
{
if (c == NULL)
return "(NONE)";
if (c->min_tls == TLS1_VERSION)
return "TLSv1.0";
return ssl_protocol_to_string(c->min_tls);
}
const char *SSL_CIPHER_get_name(const SSL_CIPHER *c)
{
if (c != NULL)
return (c->name);
return ("(NONE)");
}
int SSL_CIPHER_get_bits(const SSL_CIPHER *c, int *alg_bits)
{
int ret = 0;
if (c != NULL) {
if (alg_bits != NULL)
*alg_bits = (int)c->alg_bits;
ret = (int)c->strength_bits;
}
return ret;
}
uint32_t SSL_CIPHER_get_id(const SSL_CIPHER *c)
{
return c->id;
}
int SSL_COMP_add_compression_method(int id, COMP_METHOD *cm)
{
return 1;
}
static void cmeth_free(SSL_COMP *cm)
{
OPENSSL_free(cm);
}
void ssl_comp_free_compression_methods_int(void)
{
STACK_OF(SSL_COMP) *old_meths = ssl_comp_methods;
ssl_comp_methods = NULL;
sk_SSL_COMP_pop_free(old_meths, cmeth_free);
}
int SSL_COMP_add_compression_method(int id, COMP_METHOD *cm)
{
SSL_COMP *comp;
if (cm == NULL || COMP_get_type(cm) == NID_undef)
return 1;
if (id < 193 || id > 255) {
SSLerr(SSL_F_SSL_COMP_ADD_COMPRESSION_METHOD,
SSL_R_COMPRESSION_ID_NOT_WITHIN_PRIVATE_RANGE);
return 0;
}
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);
comp = OPENSSL_malloc(sizeof(*comp));
if (comp == NULL) {
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
SSLerr(SSL_F_SSL_COMP_ADD_COMPRESSION_METHOD, ERR_R_MALLOC_FAILURE);
return (1);
}
comp->id = id;
comp->method = cm;
load_builtin_compressions();
if (ssl_comp_methods && sk_SSL_COMP_find(ssl_comp_methods, comp) >= 0) {
OPENSSL_free(comp);
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
SSLerr(SSL_F_SSL_COMP_ADD_COMPRESSION_METHOD,
SSL_R_DUPLICATE_COMPRESSION_ID);
return (1);
}
if (ssl_comp_methods == NULL || !sk_SSL_COMP_push(ssl_comp_methods, comp)) {
OPENSSL_free(comp);
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
SSLerr(SSL_F_SSL_COMP_ADD_COMPRESSION_METHOD, ERR_R_MALLOC_FAILURE);
return (1);
}
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
return (0);
}
const char *SSL_COMP_get_name(const COMP_METHOD *comp)
{
#ifndef OPENSSL_NO_COMP
return comp ? COMP_get_name(comp) : NULL;
#else
return NULL;
#endif
}
int ssl_cipher_get_cert_index(const SSL_CIPHER *c)
{
uint32_t alg_a;
alg_a = c->algorithm_auth;
if (alg_a & SSL_aECDSA)
return SSL_PKEY_ECC;
else if (alg_a & SSL_aDSS)
return SSL_PKEY_DSA_SIGN;
else if (alg_a & SSL_aRSA)
return SSL_PKEY_RSA_ENC;
else if (alg_a & SSL_aGOST12)
return SSL_PKEY_GOST_EC;
else if (alg_a & SSL_aGOST01)
return SSL_PKEY_GOST01;
return -1;
}
const SSL_CIPHER *ssl_get_cipher_by_char(SSL *ssl, const unsigned char *ptr)
{
const SSL_CIPHER *c = ssl->method->get_cipher_by_char(ptr);
if (c == NULL || c->valid == 0)
return NULL;
return c;
}
const SSL_CIPHER *SSL_CIPHER_find(SSL *ssl, const unsigned char *ptr)
{
return ssl->method->get_cipher_by_char(ptr);
}
int SSL_CIPHER_get_cipher_nid(const SSL_CIPHER *c)
{
int i;
if (c == NULL)
return NID_undef;
i = ssl_cipher_info_lookup(ssl_cipher_table_cipher, c->algorithm_enc);
if (i == -1)
return NID_undef;
return ssl_cipher_table_cipher[i].nid;
}
int SSL_CIPHER_get_digest_nid(const SSL_CIPHER *c)
{
int i = ssl_cipher_info_lookup(ssl_cipher_table_mac, c->algorithm_mac);
if (i == -1)
return NID_undef;
return ssl_cipher_table_mac[i].nid;
}
int SSL_CIPHER_get_kx_nid(const SSL_CIPHER *c)
{
int i = ssl_cipher_info_lookup(ssl_cipher_table_kx, c->algorithm_mkey);
if (i == -1)
return NID_undef;
return ssl_cipher_table_kx[i].nid;
}
int SSL_CIPHER_get_auth_nid(const SSL_CIPHER *c)
{
int i = ssl_cipher_info_lookup(ssl_cipher_table_auth, c->algorithm_auth);
if (i == -1)
return NID_undef;
return ssl_cipher_table_auth[i].nid;
}
int SSL_CIPHER_is_aead(const SSL_CIPHER *c)
{
return (c->algorithm_mac & SSL_AEAD) ? 1 : 0;
}
