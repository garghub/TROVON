static void __init pkey_debug_init(void)
{
debug_info = debug_register("pkey", 1, 1, 4 * sizeof(long));
debug_register_view(debug_info, &debug_sprintf_view);
debug_set_level(debug_info, 3);
}
static void __exit pkey_debug_exit(void)
{
debug_unregister(debug_info);
}
static int check_secaeskeytoken(const u8 *token, int keybitsize)
{
struct secaeskeytoken *t = (struct secaeskeytoken *) token;
if (t->type != 0x01) {
DEBUG_ERR(
"check_secaeskeytoken secure token check failed, type mismatch 0x%02x != 0x01\n",
(int) t->type);
return -EINVAL;
}
if (t->version != 0x04) {
DEBUG_ERR(
"check_secaeskeytoken secure token check failed, version mismatch 0x%02x != 0x04\n",
(int) t->version);
return -EINVAL;
}
if (keybitsize > 0 && t->bitsize != keybitsize) {
DEBUG_ERR(
"check_secaeskeytoken secure token check failed, bitsize mismatch %d != %d\n",
(int) t->bitsize, keybitsize);
return -EINVAL;
}
return 0;
}
static int alloc_and_prep_cprbmem(size_t paramblen,
u8 **pcprbmem,
struct CPRBX **preqCPRB,
struct CPRBX **prepCPRB)
{
u8 *cprbmem;
size_t cprbplusparamblen = sizeof(struct CPRBX) + paramblen;
struct CPRBX *preqcblk, *prepcblk;
cprbmem = kmalloc(2 * cprbplusparamblen, GFP_KERNEL);
if (!cprbmem)
return -ENOMEM;
memset(cprbmem, 0, 2 * cprbplusparamblen);
preqcblk = (struct CPRBX *) cprbmem;
prepcblk = (struct CPRBX *) (cprbmem + cprbplusparamblen);
preqcblk->cprb_len = sizeof(struct CPRBX);
preqcblk->cprb_ver_id = 0x02;
memcpy(preqcblk->func_id, "T2", 2);
preqcblk->rpl_msgbl = cprbplusparamblen;
if (paramblen) {
preqcblk->req_parmb =
((u8 *) preqcblk) + sizeof(struct CPRBX);
preqcblk->rpl_parmb =
((u8 *) prepcblk) + sizeof(struct CPRBX);
}
*pcprbmem = cprbmem;
*preqCPRB = preqcblk;
*prepCPRB = prepcblk;
return 0;
}
static void free_cprbmem(void *mem, size_t paramblen, int scrub)
{
if (scrub)
memzero_explicit(mem, 2 * (sizeof(struct CPRBX) + paramblen));
kfree(mem);
}
static inline void prep_xcrb(struct ica_xcRB *pxcrb,
u16 cardnr,
struct CPRBX *preqcblk,
struct CPRBX *prepcblk)
{
memset(pxcrb, 0, sizeof(*pxcrb));
pxcrb->agent_ID = 0x4341;
pxcrb->user_defined = (cardnr == 0xFFFF ? AUTOSELECT : cardnr);
pxcrb->request_control_blk_length =
preqcblk->cprb_len + preqcblk->req_parml;
pxcrb->request_control_blk_addr = (void __user *) preqcblk;
pxcrb->reply_control_blk_length = preqcblk->rpl_msgbl;
pxcrb->reply_control_blk_addr = (void __user *) prepcblk;
}
static inline int _zcrypt_send_cprb(struct ica_xcRB *xcrb)
{
int rc;
mm_segment_t old_fs = get_fs();
set_fs(KERNEL_DS);
rc = zcrypt_send_cprb(xcrb);
set_fs(old_fs);
return rc;
}
int pkey_genseckey(u16 cardnr, u16 domain,
u32 keytype, struct pkey_seckey *seckey)
{
int i, rc, keysize;
int seckeysize;
u8 *mem;
struct CPRBX *preqcblk, *prepcblk;
struct ica_xcRB xcrb;
struct kgreqparm {
u8 subfunc_code[2];
u16 rule_array_len;
struct lv1 {
u16 len;
char key_form[8];
char key_length[8];
char key_type1[8];
char key_type2[8];
} lv1;
struct lv2 {
u16 len;
struct keyid {
u16 len;
u16 attr;
u8 data[SECKEYBLOBSIZE];
} keyid[6];
} lv2;
} *preqparm;
struct kgrepparm {
u8 subfunc_code[2];
u16 rule_array_len;
struct lv3 {
u16 len;
u16 keyblocklen;
struct {
u16 toklen;
u16 tokattr;
u8 tok[0];
} keyblock;
} lv3;
} *prepparm;
rc = alloc_and_prep_cprbmem(PARMBSIZE, &mem, &preqcblk, &prepcblk);
if (rc)
return rc;
preqcblk->domain = domain;
preqparm = (struct kgreqparm *) preqcblk->req_parmb;
memcpy(preqparm->subfunc_code, "KG", 2);
preqparm->rule_array_len = sizeof(preqparm->rule_array_len);
preqparm->lv1.len = sizeof(struct lv1);
memcpy(preqparm->lv1.key_form, "OP ", 8);
switch (keytype) {
case PKEY_KEYTYPE_AES_128:
keysize = 16;
memcpy(preqparm->lv1.key_length, "KEYLN16 ", 8);
break;
case PKEY_KEYTYPE_AES_192:
keysize = 24;
memcpy(preqparm->lv1.key_length, "KEYLN24 ", 8);
break;
case PKEY_KEYTYPE_AES_256:
keysize = 32;
memcpy(preqparm->lv1.key_length, "KEYLN32 ", 8);
break;
default:
DEBUG_ERR(
"pkey_genseckey unknown/unsupported keytype %d\n",
keytype);
rc = -EINVAL;
goto out;
}
memcpy(preqparm->lv1.key_type1, "AESDATA ", 8);
preqparm->lv2.len = sizeof(struct lv2);
for (i = 0; i < 6; i++) {
preqparm->lv2.keyid[i].len = sizeof(struct keyid);
preqparm->lv2.keyid[i].attr = (i == 2 ? 0x30 : 0x10);
}
preqcblk->req_parml = sizeof(struct kgreqparm);
prep_xcrb(&xcrb, cardnr, preqcblk, prepcblk);
rc = _zcrypt_send_cprb(&xcrb);
if (rc) {
DEBUG_ERR(
"pkey_genseckey zcrypt_send_cprb (cardnr=%d domain=%d) failed with errno %d\n",
(int) cardnr, (int) domain, rc);
goto out;
}
if (prepcblk->ccp_rtcode != 0) {
DEBUG_ERR(
"pkey_genseckey secure key generate failure, card response %d/%d\n",
(int) prepcblk->ccp_rtcode,
(int) prepcblk->ccp_rscode);
rc = -EIO;
goto out;
}
prepcblk->rpl_parmb = ((u8 *) prepcblk) + sizeof(struct CPRBX);
prepparm = (struct kgrepparm *) prepcblk->rpl_parmb;
seckeysize = prepparm->lv3.keyblock.toklen
- sizeof(prepparm->lv3.keyblock.toklen)
- sizeof(prepparm->lv3.keyblock.tokattr);
if (seckeysize != SECKEYBLOBSIZE) {
DEBUG_ERR(
"pkey_genseckey secure token size mismatch %d != %d bytes\n",
seckeysize, SECKEYBLOBSIZE);
rc = -EIO;
goto out;
}
rc = check_secaeskeytoken(prepparm->lv3.keyblock.tok, 8*keysize);
if (rc) {
rc = -EIO;
goto out;
}
memcpy(seckey->seckey, prepparm->lv3.keyblock.tok, SECKEYBLOBSIZE);
out:
free_cprbmem(mem, PARMBSIZE, 0);
return rc;
}
int pkey_clr2seckey(u16 cardnr, u16 domain, u32 keytype,
const struct pkey_clrkey *clrkey,
struct pkey_seckey *seckey)
{
int rc, keysize, seckeysize;
u8 *mem;
struct CPRBX *preqcblk, *prepcblk;
struct ica_xcRB xcrb;
struct cmreqparm {
u8 subfunc_code[2];
u16 rule_array_len;
char rule_array[8];
struct lv1 {
u16 len;
u8 clrkey[0];
} lv1;
struct lv2 {
u16 len;
struct keyid {
u16 len;
u16 attr;
u8 data[SECKEYBLOBSIZE];
} keyid;
} lv2;
} *preqparm;
struct lv2 *plv2;
struct cmrepparm {
u8 subfunc_code[2];
u16 rule_array_len;
struct lv3 {
u16 len;
u16 keyblocklen;
struct {
u16 toklen;
u16 tokattr;
u8 tok[0];
} keyblock;
} lv3;
} *prepparm;
rc = alloc_and_prep_cprbmem(PARMBSIZE, &mem, &preqcblk, &prepcblk);
if (rc)
return rc;
preqcblk->domain = domain;
preqparm = (struct cmreqparm *) preqcblk->req_parmb;
memcpy(preqparm->subfunc_code, "CM", 2);
memcpy(preqparm->rule_array, "AES ", 8);
preqparm->rule_array_len =
sizeof(preqparm->rule_array_len) + sizeof(preqparm->rule_array);
switch (keytype) {
case PKEY_KEYTYPE_AES_128:
keysize = 16;
break;
case PKEY_KEYTYPE_AES_192:
keysize = 24;
break;
case PKEY_KEYTYPE_AES_256:
keysize = 32;
break;
default:
DEBUG_ERR(
"pkey_clr2seckey unknown/unsupported keytype %d\n",
keytype);
rc = -EINVAL;
goto out;
}
preqparm->lv1.len = sizeof(struct lv1) + keysize;
memcpy(preqparm->lv1.clrkey, clrkey->clrkey, keysize);
plv2 = (struct lv2 *) (((u8 *) &preqparm->lv2) + keysize);
plv2->len = sizeof(struct lv2);
plv2->keyid.len = sizeof(struct keyid);
plv2->keyid.attr = 0x30;
preqcblk->req_parml = sizeof(struct cmreqparm) + keysize;
prep_xcrb(&xcrb, cardnr, preqcblk, prepcblk);
rc = _zcrypt_send_cprb(&xcrb);
if (rc) {
DEBUG_ERR(
"pkey_clr2seckey zcrypt_send_cprb (cardnr=%d domain=%d) failed with errno %d\n",
(int) cardnr, (int) domain, rc);
goto out;
}
if (prepcblk->ccp_rtcode != 0) {
DEBUG_ERR(
"pkey_clr2seckey clear key import failure, card response %d/%d\n",
(int) prepcblk->ccp_rtcode,
(int) prepcblk->ccp_rscode);
rc = -EIO;
goto out;
}
prepcblk->rpl_parmb = ((u8 *) prepcblk) + sizeof(struct CPRBX);
prepparm = (struct cmrepparm *) prepcblk->rpl_parmb;
seckeysize = prepparm->lv3.keyblock.toklen
- sizeof(prepparm->lv3.keyblock.toklen)
- sizeof(prepparm->lv3.keyblock.tokattr);
if (seckeysize != SECKEYBLOBSIZE) {
DEBUG_ERR(
"pkey_clr2seckey secure token size mismatch %d != %d bytes\n",
seckeysize, SECKEYBLOBSIZE);
rc = -EIO;
goto out;
}
rc = check_secaeskeytoken(prepparm->lv3.keyblock.tok, 8*keysize);
if (rc) {
rc = -EIO;
goto out;
}
memcpy(seckey->seckey, prepparm->lv3.keyblock.tok, SECKEYBLOBSIZE);
out:
free_cprbmem(mem, PARMBSIZE, 1);
return rc;
}
int pkey_sec2protkey(u16 cardnr, u16 domain,
const struct pkey_seckey *seckey,
struct pkey_protkey *protkey)
{
int rc;
u8 *mem;
struct CPRBX *preqcblk, *prepcblk;
struct ica_xcRB xcrb;
struct uskreqparm {
u8 subfunc_code[2];
u16 rule_array_len;
struct lv1 {
u16 len;
u16 attr_len;
u16 attr_flags;
} lv1;
struct lv2 {
u16 len;
u16 attr_len;
u16 attr_flags;
u8 token[0];
} lv2 __packed;
} *preqparm;
struct uskrepparm {
u8 subfunc_code[2];
u16 rule_array_len;
struct lv3 {
u16 len;
u16 attr_len;
u16 attr_flags;
struct cpacfkeyblock {
u8 version;
u8 flags[2];
u8 algo;
u8 form;
u8 pad1[3];
u16 keylen;
u8 key[64];
u16 keyattrlen;
u8 keyattr[32];
u8 pad2[1];
u8 vptype;
u8 vp[32];
} keyblock;
} lv3 __packed;
} *prepparm;
rc = alloc_and_prep_cprbmem(PARMBSIZE, &mem, &preqcblk, &prepcblk);
if (rc)
return rc;
preqcblk->domain = domain;
preqparm = (struct uskreqparm *) preqcblk->req_parmb;
memcpy(preqparm->subfunc_code, "US", 2);
preqparm->rule_array_len = sizeof(preqparm->rule_array_len);
preqparm->lv1.len = sizeof(struct lv1);
preqparm->lv1.attr_len = sizeof(struct lv1) - sizeof(preqparm->lv1.len);
preqparm->lv1.attr_flags = 0x0001;
preqparm->lv2.len = sizeof(struct lv2) + SECKEYBLOBSIZE;
preqparm->lv2.attr_len = sizeof(struct lv2)
- sizeof(preqparm->lv2.len) + SECKEYBLOBSIZE;
preqparm->lv2.attr_flags = 0x0000;
memcpy(preqparm->lv2.token, seckey->seckey, SECKEYBLOBSIZE);
preqcblk->req_parml = sizeof(struct uskreqparm) + SECKEYBLOBSIZE;
prep_xcrb(&xcrb, cardnr, preqcblk, prepcblk);
rc = _zcrypt_send_cprb(&xcrb);
if (rc) {
DEBUG_ERR(
"pkey_sec2protkey zcrypt_send_cprb (cardnr=%d domain=%d) failed with errno %d\n",
(int) cardnr, (int) domain, rc);
goto out;
}
if (prepcblk->ccp_rtcode != 0) {
DEBUG_ERR(
"pkey_sec2protkey unwrap secure key failure, card response %d/%d\n",
(int) prepcblk->ccp_rtcode,
(int) prepcblk->ccp_rscode);
rc = -EIO;
goto out;
}
if (prepcblk->ccp_rscode != 0) {
DEBUG_WARN(
"pkey_sec2protkey unwrap secure key warning, card response %d/%d\n",
(int) prepcblk->ccp_rtcode,
(int) prepcblk->ccp_rscode);
}
prepcblk->rpl_parmb = ((u8 *) prepcblk) + sizeof(struct CPRBX);
prepparm = (struct uskrepparm *) prepcblk->rpl_parmb;
if (prepparm->lv3.keyblock.version != 0x01) {
DEBUG_ERR(
"pkey_sec2protkey reply param keyblock version mismatch 0x%02x != 0x01\n",
(int) prepparm->lv3.keyblock.version);
rc = -EIO;
goto out;
}
switch (prepparm->lv3.keyblock.keylen) {
case 16+32:
protkey->type = PKEY_KEYTYPE_AES_128;
break;
case 24+32:
protkey->type = PKEY_KEYTYPE_AES_192;
break;
case 32+32:
protkey->type = PKEY_KEYTYPE_AES_256;
break;
default:
DEBUG_ERR("pkey_sec2protkey unknown/unsupported keytype %d\n",
prepparm->lv3.keyblock.keylen);
rc = -EIO;
goto out;
}
protkey->len = prepparm->lv3.keyblock.keylen;
memcpy(protkey->protkey, prepparm->lv3.keyblock.key, protkey->len);
out:
free_cprbmem(mem, PARMBSIZE, 0);
return rc;
}
int pkey_clr2protkey(u32 keytype,
const struct pkey_clrkey *clrkey,
struct pkey_protkey *protkey)
{
long fc;
int keysize;
u8 paramblock[64];
switch (keytype) {
case PKEY_KEYTYPE_AES_128:
keysize = 16;
fc = CPACF_PCKMO_ENC_AES_128_KEY;
break;
case PKEY_KEYTYPE_AES_192:
keysize = 24;
fc = CPACF_PCKMO_ENC_AES_192_KEY;
break;
case PKEY_KEYTYPE_AES_256:
keysize = 32;
fc = CPACF_PCKMO_ENC_AES_256_KEY;
break;
default:
DEBUG_ERR("pkey_clr2protkey unknown/unsupported keytype %d\n",
keytype);
return -EINVAL;
}
memset(paramblock, 0, sizeof(paramblock));
memcpy(paramblock, clrkey->clrkey, keysize);
cpacf_pckmo(fc, paramblock);
protkey->type = keytype;
protkey->len = keysize + 32;
memcpy(protkey->protkey, paramblock, keysize + 32);
return 0;
}
static int query_crypto_facility(u16 cardnr, u16 domain,
const char *keyword,
u8 *rarray, size_t *rarraylen,
u8 *varray, size_t *varraylen)
{
int rc;
u16 len;
u8 *mem, *ptr;
struct CPRBX *preqcblk, *prepcblk;
struct ica_xcRB xcrb;
struct fqreqparm {
u8 subfunc_code[2];
u16 rule_array_len;
char rule_array[8];
struct lv1 {
u16 len;
u8 data[VARDATASIZE];
} lv1;
u16 dummylen;
} *preqparm;
size_t parmbsize = sizeof(struct fqreqparm);
struct fqrepparm {
u8 subfunc_code[2];
u8 lvdata[0];
} *prepparm;
rc = alloc_and_prep_cprbmem(parmbsize, &mem, &preqcblk, &prepcblk);
if (rc)
return rc;
preqcblk->domain = domain;
preqparm = (struct fqreqparm *) preqcblk->req_parmb;
memcpy(preqparm->subfunc_code, "FQ", 2);
strncpy(preqparm->rule_array, keyword, sizeof(preqparm->rule_array));
preqparm->rule_array_len =
sizeof(preqparm->rule_array_len) + sizeof(preqparm->rule_array);
preqparm->lv1.len = sizeof(preqparm->lv1);
preqparm->dummylen = sizeof(preqparm->dummylen);
preqcblk->req_parml = parmbsize;
prep_xcrb(&xcrb, cardnr, preqcblk, prepcblk);
rc = _zcrypt_send_cprb(&xcrb);
if (rc) {
DEBUG_ERR(
"query_crypto_facility zcrypt_send_cprb (cardnr=%d domain=%d) failed with errno %d\n",
(int) cardnr, (int) domain, rc);
goto out;
}
if (prepcblk->ccp_rtcode != 0) {
DEBUG_ERR(
"query_crypto_facility unwrap secure key failure, card response %d/%d\n",
(int) prepcblk->ccp_rtcode,
(int) prepcblk->ccp_rscode);
rc = -EIO;
goto out;
}
prepcblk->rpl_parmb = ((u8 *) prepcblk) + sizeof(struct CPRBX);
prepparm = (struct fqrepparm *) prepcblk->rpl_parmb;
ptr = prepparm->lvdata;
len = *((u16 *) ptr);
if (len > sizeof(u16)) {
ptr += sizeof(u16);
len -= sizeof(u16);
if (rarray && rarraylen && *rarraylen > 0) {
*rarraylen = (len > *rarraylen ? *rarraylen : len);
memcpy(rarray, ptr, *rarraylen);
}
ptr += len;
}
len = *((u16 *) ptr);
if (len > sizeof(u16)) {
ptr += sizeof(u16);
len -= sizeof(u16);
if (varray && varraylen && *varraylen > 0) {
*varraylen = (len > *varraylen ? *varraylen : len);
memcpy(varray, ptr, *varraylen);
}
ptr += len;
}
out:
free_cprbmem(mem, parmbsize, 0);
return rc;
}
static int fetch_mkvp(u16 cardnr, u16 domain, u64 mkvp[2])
{
int rc, found = 0;
size_t rlen, vlen;
u8 *rarray, *varray, *pg;
pg = (u8 *) __get_free_page(GFP_KERNEL);
if (!pg)
return -ENOMEM;
rarray = pg;
varray = pg + PAGE_SIZE/2;
rlen = vlen = PAGE_SIZE/2;
rc = query_crypto_facility(cardnr, domain, "STATICSA",
rarray, &rlen, varray, &vlen);
if (rc == 0 && rlen > 8*8 && vlen > 184+8) {
if (rarray[8*8] == '2') {
mkvp[0] = *((u64 *)(varray + 184));
mkvp[1] = *((u64 *)(varray + 172));
found = 1;
}
}
free_page((unsigned long) pg);
return found ? 0 : -ENOENT;
}
static int mkvp_cache_fetch(u16 cardnr, u16 domain, u64 mkvp[2])
{
int rc = -ENOENT;
struct mkvp_info *ptr;
spin_lock_bh(&mkvp_list_lock);
list_for_each_entry(ptr, &mkvp_list, list) {
if (ptr->cardnr == cardnr &&
ptr->domain == domain) {
memcpy(mkvp, ptr->mkvp, 2 * sizeof(u64));
rc = 0;
break;
}
}
spin_unlock_bh(&mkvp_list_lock);
return rc;
}
static void mkvp_cache_update(u16 cardnr, u16 domain, u64 mkvp[2])
{
int found = 0;
struct mkvp_info *ptr;
spin_lock_bh(&mkvp_list_lock);
list_for_each_entry(ptr, &mkvp_list, list) {
if (ptr->cardnr == cardnr &&
ptr->domain == domain) {
memcpy(ptr->mkvp, mkvp, 2 * sizeof(u64));
found = 1;
break;
}
}
if (!found) {
ptr = kmalloc(sizeof(*ptr), GFP_ATOMIC);
if (!ptr) {
spin_unlock_bh(&mkvp_list_lock);
return;
}
ptr->cardnr = cardnr;
ptr->domain = domain;
memcpy(ptr->mkvp, mkvp, 2 * sizeof(u64));
list_add(&ptr->list, &mkvp_list);
}
spin_unlock_bh(&mkvp_list_lock);
}
static void mkvp_cache_scrub(u16 cardnr, u16 domain)
{
struct mkvp_info *ptr;
spin_lock_bh(&mkvp_list_lock);
list_for_each_entry(ptr, &mkvp_list, list) {
if (ptr->cardnr == cardnr &&
ptr->domain == domain) {
list_del(&ptr->list);
kfree(ptr);
break;
}
}
spin_unlock_bh(&mkvp_list_lock);
}
static void __exit mkvp_cache_free(void)
{
struct mkvp_info *ptr, *pnext;
spin_lock_bh(&mkvp_list_lock);
list_for_each_entry_safe(ptr, pnext, &mkvp_list, list) {
list_del(&ptr->list);
kfree(ptr);
}
spin_unlock_bh(&mkvp_list_lock);
}
int pkey_findcard(const struct pkey_seckey *seckey,
u16 *pcardnr, u16 *pdomain, int verify)
{
struct secaeskeytoken *t = (struct secaeskeytoken *) seckey;
struct zcrypt_device_matrix *device_matrix;
u16 card, dom;
u64 mkvp[2];
int i, rc, oi = -1;
if (t->mkvp == 0)
return -EINVAL;
device_matrix = kmalloc(sizeof(struct zcrypt_device_matrix),
GFP_KERNEL);
if (!device_matrix)
return -ENOMEM;
zcrypt_device_status_mask(device_matrix);
for (i = 0; i < MAX_ZDEV_ENTRIES; i++) {
card = AP_QID_CARD(device_matrix->device[i].qid);
dom = AP_QID_QUEUE(device_matrix->device[i].qid);
if (device_matrix->device[i].online &&
device_matrix->device[i].functions & 0x04) {
if (mkvp_cache_fetch(card, dom, mkvp) == 0 &&
t->mkvp == mkvp[0]) {
if (!verify)
break;
if (fetch_mkvp(card, dom, mkvp) == 0) {
mkvp_cache_update(card, dom, mkvp);
if (t->mkvp == mkvp[0])
break;
}
}
} else {
mkvp_cache_scrub(card, dom);
}
}
if (i >= MAX_ZDEV_ENTRIES) {
for (i = 0; i < MAX_ZDEV_ENTRIES; i++) {
if (!(device_matrix->device[i].online &&
device_matrix->device[i].functions & 0x04))
continue;
card = AP_QID_CARD(device_matrix->device[i].qid);
dom = AP_QID_QUEUE(device_matrix->device[i].qid);
if (fetch_mkvp(card, dom, mkvp) == 0) {
mkvp_cache_update(card, dom, mkvp);
if (t->mkvp == mkvp[0])
break;
if (t->mkvp == mkvp[1] && oi < 0)
oi = i;
}
}
if (i >= MAX_ZDEV_ENTRIES && oi >= 0) {
card = AP_QID_CARD(device_matrix->device[oi].qid);
dom = AP_QID_QUEUE(device_matrix->device[oi].qid);
}
}
if (i < MAX_ZDEV_ENTRIES || oi >= 0) {
if (pcardnr)
*pcardnr = card;
if (pdomain)
*pdomain = dom;
rc = 0;
} else
rc = -ENODEV;
kfree(device_matrix);
return rc;
}
int pkey_skey2pkey(const struct pkey_seckey *seckey,
struct pkey_protkey *protkey)
{
u16 cardnr, domain;
int rc, verify;
for (verify = 0; verify < 2; verify++) {
rc = pkey_findcard(seckey, &cardnr, &domain, verify);
if (rc)
continue;
rc = pkey_sec2protkey(cardnr, domain, seckey, protkey);
if (rc == 0)
break;
}
if (rc)
DEBUG_DBG("pkey_skey2pkey failed rc=%d\n", rc);
return rc;
}
int pkey_verifykey(const struct pkey_seckey *seckey,
u16 *pcardnr, u16 *pdomain,
u16 *pkeysize, u32 *pattributes)
{
struct secaeskeytoken *t = (struct secaeskeytoken *) seckey;
u16 cardnr, domain;
u64 mkvp[2];
int rc;
rc = check_secaeskeytoken((u8 *) seckey, 0);
if (rc)
goto out;
if (pattributes)
*pattributes = PKEY_VERIFY_ATTR_AES;
if (pkeysize)
*pkeysize = t->bitsize;
rc = pkey_findcard(seckey, &cardnr, &domain, 1);
if (rc)
goto out;
rc = mkvp_cache_fetch(cardnr, domain, mkvp);
if (rc)
goto out;
if (t->mkvp == mkvp[1]) {
DEBUG_DBG("pkey_verifykey secure key has old mkvp\n");
if (pattributes)
*pattributes |= PKEY_VERIFY_ATTR_OLD_MKVP;
}
if (pcardnr)
*pcardnr = cardnr;
if (pdomain)
*pdomain = domain;
out:
DEBUG_DBG("pkey_verifykey rc=%d\n", rc);
return rc;
}
static long pkey_unlocked_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
int rc;
switch (cmd) {
case PKEY_GENSECK: {
struct pkey_genseck __user *ugs = (void __user *) arg;
struct pkey_genseck kgs;
if (copy_from_user(&kgs, ugs, sizeof(kgs)))
return -EFAULT;
rc = pkey_genseckey(kgs.cardnr, kgs.domain,
kgs.keytype, &kgs.seckey);
DEBUG_DBG("pkey_ioctl pkey_genseckey()=%d\n", rc);
if (rc)
break;
if (copy_to_user(ugs, &kgs, sizeof(kgs)))
return -EFAULT;
break;
}
case PKEY_CLR2SECK: {
struct pkey_clr2seck __user *ucs = (void __user *) arg;
struct pkey_clr2seck kcs;
if (copy_from_user(&kcs, ucs, sizeof(kcs)))
return -EFAULT;
rc = pkey_clr2seckey(kcs.cardnr, kcs.domain, kcs.keytype,
&kcs.clrkey, &kcs.seckey);
DEBUG_DBG("pkey_ioctl pkey_clr2seckey()=%d\n", rc);
if (rc)
break;
if (copy_to_user(ucs, &kcs, sizeof(kcs)))
return -EFAULT;
memzero_explicit(&kcs, sizeof(kcs));
break;
}
case PKEY_SEC2PROTK: {
struct pkey_sec2protk __user *usp = (void __user *) arg;
struct pkey_sec2protk ksp;
if (copy_from_user(&ksp, usp, sizeof(ksp)))
return -EFAULT;
rc = pkey_sec2protkey(ksp.cardnr, ksp.domain,
&ksp.seckey, &ksp.protkey);
DEBUG_DBG("pkey_ioctl pkey_sec2protkey()=%d\n", rc);
if (rc)
break;
if (copy_to_user(usp, &ksp, sizeof(ksp)))
return -EFAULT;
break;
}
case PKEY_CLR2PROTK: {
struct pkey_clr2protk __user *ucp = (void __user *) arg;
struct pkey_clr2protk kcp;
if (copy_from_user(&kcp, ucp, sizeof(kcp)))
return -EFAULT;
rc = pkey_clr2protkey(kcp.keytype,
&kcp.clrkey, &kcp.protkey);
DEBUG_DBG("pkey_ioctl pkey_clr2protkey()=%d\n", rc);
if (rc)
break;
if (copy_to_user(ucp, &kcp, sizeof(kcp)))
return -EFAULT;
memzero_explicit(&kcp, sizeof(kcp));
break;
}
case PKEY_FINDCARD: {
struct pkey_findcard __user *ufc = (void __user *) arg;
struct pkey_findcard kfc;
if (copy_from_user(&kfc, ufc, sizeof(kfc)))
return -EFAULT;
rc = pkey_findcard(&kfc.seckey,
&kfc.cardnr, &kfc.domain, 1);
DEBUG_DBG("pkey_ioctl pkey_findcard()=%d\n", rc);
if (rc)
break;
if (copy_to_user(ufc, &kfc, sizeof(kfc)))
return -EFAULT;
break;
}
case PKEY_SKEY2PKEY: {
struct pkey_skey2pkey __user *usp = (void __user *) arg;
struct pkey_skey2pkey ksp;
if (copy_from_user(&ksp, usp, sizeof(ksp)))
return -EFAULT;
rc = pkey_skey2pkey(&ksp.seckey, &ksp.protkey);
DEBUG_DBG("pkey_ioctl pkey_skey2pkey()=%d\n", rc);
if (rc)
break;
if (copy_to_user(usp, &ksp, sizeof(ksp)))
return -EFAULT;
break;
}
case PKEY_VERIFYKEY: {
struct pkey_verifykey __user *uvk = (void __user *) arg;
struct pkey_verifykey kvk;
if (copy_from_user(&kvk, uvk, sizeof(kvk)))
return -EFAULT;
rc = pkey_verifykey(&kvk.seckey, &kvk.cardnr, &kvk.domain,
&kvk.keysize, &kvk.attributes);
DEBUG_DBG("pkey_ioctl pkey_verifykey()=%d\n", rc);
if (rc)
break;
if (copy_to_user(uvk, &kvk, sizeof(kvk)))
return -EFAULT;
break;
}
default:
return -ENOTTY;
}
return rc;
}
static int __init pkey_init(void)
{
cpacf_mask_t pckmo_functions;
if (!cpacf_query(CPACF_PCKMO, &pckmo_functions))
return -EOPNOTSUPP;
if (!cpacf_test_func(&pckmo_functions, CPACF_PCKMO_ENC_AES_128_KEY) ||
!cpacf_test_func(&pckmo_functions, CPACF_PCKMO_ENC_AES_192_KEY) ||
!cpacf_test_func(&pckmo_functions, CPACF_PCKMO_ENC_AES_256_KEY))
return -EOPNOTSUPP;
pkey_debug_init();
return misc_register(&pkey_dev);
}
static void __exit pkey_exit(void)
{
misc_deregister(&pkey_dev);
mkvp_cache_free();
pkey_debug_exit();
}
