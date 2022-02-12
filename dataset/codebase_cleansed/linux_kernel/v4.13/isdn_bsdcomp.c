static void bsd_clear(struct bsd_db *db)
{
db->clear_count++;
db->max_ent = FIRST - 1;
db->n_bits = BSD_INIT_BITS;
db->bytes_out = 0;
db->in_count = 0;
db->incomp_count = 0;
db->ratio = 0;
db->checkpoint = CHECK_GAP;
}
static int bsd_check(struct bsd_db *db)
{
unsigned int new_ratio;
if (db->in_count >= db->checkpoint)
{
if (db->in_count >= RATIO_MAX || db->bytes_out >= RATIO_MAX)
{
db->in_count -= (db->in_count >> 2);
db->bytes_out -= (db->bytes_out >> 2);
}
db->checkpoint = db->in_count + CHECK_GAP;
if (db->max_ent >= db->maxmaxcode)
{
new_ratio = db->in_count << RATIO_SCALE_LOG;
if (db->bytes_out != 0)
{
new_ratio /= db->bytes_out;
}
if (new_ratio < db->ratio || new_ratio < 1 * RATIO_SCALE)
{
bsd_clear(db);
return 1;
}
db->ratio = new_ratio;
}
}
return 0;
}
static void bsd_stats(void *state, struct compstat *stats)
{
struct bsd_db *db = (struct bsd_db *) state;
stats->unc_bytes = db->uncomp_bytes;
stats->unc_packets = db->uncomp_count;
stats->comp_bytes = db->comp_bytes;
stats->comp_packets = db->comp_count;
stats->inc_bytes = db->incomp_bytes;
stats->inc_packets = db->incomp_count;
stats->in_count = db->in_count;
stats->bytes_out = db->bytes_out;
}
static void bsd_reset(void *state, unsigned char code, unsigned char id,
unsigned char *data, unsigned len,
struct isdn_ppp_resetparams *rsparm)
{
struct bsd_db *db = (struct bsd_db *) state;
bsd_clear(db);
db->seqno = 0;
db->clear_count = 0;
}
static void bsd_free(void *state)
{
struct bsd_db *db = (struct bsd_db *) state;
if (db) {
vfree(db->dict);
db->dict = NULL;
vfree(db->lens);
db->lens = NULL;
kfree(db);
}
}
static void *bsd_alloc(struct isdn_ppp_comp_data *data)
{
int bits;
unsigned int hsize, hshift, maxmaxcode;
struct bsd_db *db;
int decomp;
static unsigned int htab[][2] = {
{ 5003 , 4 } , { 5003 , 4 } , { 5003 , 4 } , { 5003 , 4 } ,
{ 9001 , 5 } , { 18013 , 6 } , { 35023 , 7 } , { 69001 , 8 }
};
if (data->optlen != 1 || data->num != CI_BSD_COMPRESS
|| BSD_VERSION(data->options[0]) != BSD_CURRENT_VERSION)
return NULL;
bits = BSD_NBITS(data->options[0]);
if (bits < 9 || bits > 15)
return NULL;
hsize = htab[bits - 9][0];
hshift = htab[bits - 9][1];
maxmaxcode = MAXCODE(bits);
db = kzalloc(sizeof(struct bsd_db), GFP_KERNEL);
if (!db)
return NULL;
db->xmit = data->flags & IPPP_COMP_FLAG_XMIT;
decomp = db->xmit ? 0 : 1;
db->dict = vmalloc(hsize * sizeof(struct bsd_dict));
if (!db->dict) {
bsd_free(db);
return NULL;
}
if (!decomp)
db->lens = NULL;
else {
db->lens = vmalloc((maxmaxcode + 1) * sizeof(db->lens[0]));
if (!db->lens) {
bsd_free(db);
return (NULL);
}
}
db->totlen = sizeof(struct bsd_db) + (sizeof(struct bsd_dict) * hsize);
db->hsize = hsize;
db->hshift = hshift;
db->maxmaxcode = maxmaxcode;
db->maxbits = bits;
return (void *)db;
}
static int bsd_init(void *state, struct isdn_ppp_comp_data *data, int unit, int debug)
{
struct bsd_db *db = state;
int indx;
int decomp;
if (!state || !data) {
printk(KERN_ERR "isdn_bsd_init: [%d] ERR, state %lx data %lx\n", unit, (long)state, (long)data);
return 0;
}
decomp = db->xmit ? 0 : 1;
if (data->optlen != 1 || data->num != CI_BSD_COMPRESS
|| (BSD_VERSION(data->options[0]) != BSD_CURRENT_VERSION)
|| (BSD_NBITS(data->options[0]) != db->maxbits)
|| (decomp && db->lens == NULL)) {
printk(KERN_ERR "isdn_bsd: %d %d %d %d %lx\n", data->optlen, data->num, data->options[0], decomp, (unsigned long)db->lens);
return 0;
}
if (decomp)
for (indx = LAST; indx >= 0; indx--)
db->lens[indx] = 1;
indx = db->hsize;
while (indx-- != 0) {
db->dict[indx].codem1 = BADCODEM1;
db->dict[indx].cptr = 0;
}
db->unit = unit;
db->mru = 0;
db->debug = 1;
bsd_reset(db, 0, 0, NULL, 0, NULL);
return 1;
}
static unsigned short *lens_ptr(struct bsd_db *db, int idx)
{
if ((unsigned int) idx > (unsigned int) db->maxmaxcode) {
printk(KERN_DEBUG "<9>ppp: lens_ptr(%d) > max\n", idx);
idx = 0;
}
return lens_ptrx(db, idx);
}
static struct bsd_dict *dict_ptr(struct bsd_db *db, int idx)
{
if ((unsigned int) idx >= (unsigned int) db->hsize) {
printk(KERN_DEBUG "<9>ppp: dict_ptr(%d) > max\n", idx);
idx = 0;
}
return dict_ptrx(db, idx);
}
static int bsd_compress(void *state, struct sk_buff *skb_in, struct sk_buff *skb_out, int proto)
{
struct bsd_db *db;
int hshift;
unsigned int max_ent;
unsigned int n_bits;
unsigned int bitno;
unsigned long accm;
int ent;
unsigned long fcode;
struct bsd_dict *dictp;
unsigned char c;
int hval, disp, ilen, mxcode;
unsigned char *rptr = skb_in->data;
int isize = skb_in->len;
#define OUTPUT(ent) \
{ \
bitno -= n_bits; \
accm |= ((ent) << bitno); \
do { \
if (skb_out && skb_tailroom(skb_out) > 0) \
skb_put_u8(skb_out, (u8)(accm >> 24)); \
accm <<= 8; \
bitno += 8; \
} while (bitno <= 24); \
}
printk(KERN_DEBUG "bsd_compress called with %x\n", proto);
ent = proto;
if (proto < 0x21 || proto > 0xf9 || !(proto & 0x1))
return 0;
db = (struct bsd_db *) state;
hshift = db->hshift;
max_ent = db->max_ent;
n_bits = db->n_bits;
bitno = 32;
accm = 0;
mxcode = MAXCODE(n_bits);
if (skb_out && skb_tailroom(skb_out) >= 2) {
char *v = skb_put(skb_out, 2);
v[0] = db->seqno >> 8;
v[1] = db->seqno;
}
ilen = ++isize;
while (--ilen > 0) {
c = *rptr++;
fcode = BSD_KEY(ent, c);
hval = BSD_HASH(ent, c, hshift);
dictp = dict_ptr(db, hval);
if (dictp->codem1 >= max_ent)
goto nomatch;
if (dictp->fcode == fcode) {
ent = dictp->codem1 + 1;
continue;
}
disp = (hval == 0) ? 1 : hval;
do {
hval += disp;
if (hval >= db->hsize)
hval -= db->hsize;
dictp = dict_ptr(db, hval);
if (dictp->codem1 >= max_ent)
goto nomatch;
} while (dictp->fcode != fcode);
ent = dictp->codem1 + 1;
continue;
nomatch:
OUTPUT(ent);
if (max_ent < db->maxmaxcode) {
struct bsd_dict *dictp2;
struct bsd_dict *dictp3;
int indx;
if (max_ent >= mxcode) {
db->n_bits = ++n_bits;
mxcode = MAXCODE(n_bits);
}
dictp2 = dict_ptr(db, max_ent + 1);
indx = dictp2->cptr;
dictp3 = dict_ptr(db, indx);
if (dictp3->codem1 == max_ent)
dictp3->codem1 = BADCODEM1;
dictp2->cptr = hval;
dictp->codem1 = max_ent;
dictp->fcode = fcode;
db->max_ent = ++max_ent;
if (db->lens) {
unsigned short *len1 = lens_ptr(db, max_ent);
unsigned short *len2 = lens_ptr(db, ent);
*len1 = *len2 + 1;
}
}
ent = c;
}
OUTPUT(ent);
if (skb_out)
db->bytes_out += skb_out->len;
db->uncomp_bytes += isize;
db->in_count += isize;
++db->uncomp_count;
++db->seqno;
if (bitno < 32)
++db->bytes_out;
if (bsd_check(db))
OUTPUT(CLEAR);
if (bitno < 32 && skb_out && skb_tailroom(skb_out) > 0)
skb_put_u8(skb_out,
(unsigned char)((accm | (0xff << (bitno - 8))) >> 24));
if (max_ent >= mxcode && max_ent < db->maxmaxcode)
db->n_bits++;
if (!skb_out || skb_out->len >= skb_in->len) {
++db->incomp_count;
db->incomp_bytes += isize;
return 0;
}
++db->comp_count;
db->comp_bytes += skb_out->len;
return skb_out->len;
#undef OUTPUT
}
static void bsd_incomp(void *state, struct sk_buff *skb_in, int proto)
{
bsd_compress(state, skb_in, NULL, proto);
}
static int bsd_decompress(void *state, struct sk_buff *skb_in, struct sk_buff *skb_out,
struct isdn_ppp_resetparams *rsparm)
{
struct bsd_db *db;
unsigned int max_ent;
unsigned long accm;
unsigned int bitno;
unsigned int n_bits;
unsigned int tgtbitno;
struct bsd_dict *dictp;
int seq;
unsigned int incode;
unsigned int oldcode;
unsigned int finchar;
unsigned char *p, *ibuf;
int ilen;
int codelen;
int extra;
db = (struct bsd_db *) state;
max_ent = db->max_ent;
accm = 0;
bitno = 32;
n_bits = db->n_bits;
tgtbitno = 32 - n_bits;
printk(KERN_DEBUG "bsd_decompress called\n");
if (!skb_in || !skb_out) {
printk(KERN_ERR "bsd_decompress called with NULL parameter\n");
return DECOMP_ERROR;
}
if ((p = skb_pull(skb_in, 2)) == NULL) {
return DECOMP_ERROR;
}
p -= 2;
seq = (p[0] << 8) + p[1];
ilen = skb_in->len;
ibuf = skb_in->data;
if (seq != db->seqno) {
if (db->debug) {
printk(KERN_DEBUG "bsd_decomp%d: bad sequence # %d, expected %d\n",
db->unit, seq, db->seqno - 1);
}
return DECOMP_ERROR;
}
++db->seqno;
db->bytes_out += ilen;
if (skb_tailroom(skb_out) > 0)
skb_put_u8(skb_out, 0);
else
return DECOMP_ERR_NOMEM;
oldcode = CLEAR;
for (;;) {
if (ilen-- <= 0) {
db->in_count += (skb_out->len - 1);
break;
}
bitno -= 8;
accm |= *ibuf++ << bitno;
if (tgtbitno < bitno)
continue;
incode = accm >> tgtbitno;
accm <<= n_bits;
bitno += n_bits;
if (incode == CLEAR) {
if (ilen > 0) {
if (db->debug)
printk(KERN_DEBUG "bsd_decomp%d: bad CLEAR\n", db->unit);
return DECOMP_FATALERROR;
}
bsd_clear(db);
break;
}
if ((incode > max_ent + 2) || (incode > db->maxmaxcode)
|| (incode > max_ent && oldcode == CLEAR)) {
if (db->debug) {
printk(KERN_DEBUG "bsd_decomp%d: bad code 0x%x oldcode=0x%x ",
db->unit, incode, oldcode);
printk(KERN_DEBUG "max_ent=0x%x skb->Len=%d seqno=%d\n",
max_ent, skb_out->len, db->seqno);
}
return DECOMP_FATALERROR;
}
if (incode > max_ent) {
finchar = oldcode;
extra = 1;
} else {
finchar = incode;
extra = 0;
}
codelen = *(lens_ptr(db, finchar));
if (skb_tailroom(skb_out) < codelen + extra) {
if (db->debug) {
printk(KERN_DEBUG "bsd_decomp%d: ran out of mru\n", db->unit);
#ifdef DEBUG
printk(KERN_DEBUG " len=%d, finchar=0x%x, codelen=%d,skblen=%d\n",
ilen, finchar, codelen, skb_out->len);
#endif
}
return DECOMP_FATALERROR;
}
p = skb_put(skb_out, codelen);
p += codelen;
while (finchar > LAST) {
struct bsd_dict *dictp2 = dict_ptr(db, finchar);
dictp = dict_ptr(db, dictp2->cptr);
#ifdef DEBUG
if (--codelen <= 0 || dictp->codem1 != finchar - 1) {
if (codelen <= 0) {
printk(KERN_ERR "bsd_decomp%d: fell off end of chain ", db->unit);
printk(KERN_ERR "0x%x at 0x%x by 0x%x, max_ent=0x%x\n", incode, finchar, dictp2->cptr, max_ent);
} else {
if (dictp->codem1 != finchar - 1) {
printk(KERN_ERR "bsd_decomp%d: bad code chain 0x%x finchar=0x%x ", db->unit, incode, finchar);
printk(KERN_ERR "oldcode=0x%x cptr=0x%x codem1=0x%x\n", oldcode, dictp2->cptr, dictp->codem1);
}
}
return DECOMP_FATALERROR;
}
#endif
{
u32 fcode = dictp->fcode;
*--p = (fcode >> 16) & 0xff;
finchar = fcode & 0xffff;
}
}
*--p = finchar;
#ifdef DEBUG
if (--codelen != 0)
printk(KERN_ERR "bsd_decomp%d: short by %d after code 0x%x, max_ent=0x%x\n", db->unit, codelen, incode, max_ent);
#endif
if (extra)
skb_put_u8(skb_out, finchar);
if (oldcode != CLEAR && max_ent < db->maxmaxcode) {
struct bsd_dict *dictp2, *dictp3;
u16 *lens1, *lens2;
unsigned long fcode;
int hval, disp, indx;
fcode = BSD_KEY(oldcode, finchar);
hval = BSD_HASH(oldcode, finchar, db->hshift);
dictp = dict_ptr(db, hval);
if (dictp->codem1 < max_ent) {
disp = (hval == 0) ? 1 : hval;
do {
hval += disp;
if (hval >= db->hsize)
hval -= db->hsize;
dictp = dict_ptr(db, hval);
} while (dictp->codem1 < max_ent);
}
dictp2 = dict_ptr(db, max_ent + 1);
indx = dictp2->cptr;
dictp3 = dict_ptr(db, indx);
if (dictp3->codem1 == max_ent)
dictp3->codem1 = BADCODEM1;
dictp2->cptr = hval;
dictp->codem1 = max_ent;
dictp->fcode = fcode;
db->max_ent = ++max_ent;
lens1 = lens_ptr(db, max_ent);
lens2 = lens_ptr(db, oldcode);
*lens1 = *lens2 + 1;
if (max_ent >= MAXCODE(n_bits) && max_ent < db->maxmaxcode) {
db->n_bits = ++n_bits;
tgtbitno = 32-n_bits;
}
}
oldcode = incode;
}
++db->comp_count;
++db->uncomp_count;
db->comp_bytes += skb_in->len - BSD_OVHD;
db->uncomp_bytes += skb_out->len;
if (bsd_check(db)) {
if (db->debug)
printk(KERN_DEBUG "bsd_decomp%d: peer should have cleared dictionary on %d\n",
db->unit, db->seqno - 1);
}
return skb_out->len;
}
static int __init isdn_bsdcomp_init(void)
{
int answer = isdn_ppp_register_compressor(&ippp_bsd_compress);
if (answer == 0)
printk(KERN_INFO "PPP BSD Compression module registered\n");
return answer;
}
static void __exit isdn_bsdcomp_exit(void)
{
isdn_ppp_unregister_compressor(&ippp_bsd_compress);
}
