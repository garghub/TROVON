struct sk_buff *bcm_pkt_buf_get_skb(uint len)
{
struct sk_buff *skb;
skb = dev_alloc_skb(len);
if (skb) {
skb_put(skb, len);
skb->priority = 0;
}
return skb;
}
void bcm_pkt_buf_free_skb(struct sk_buff *skb)
{
struct sk_buff *nskb;
int nest = 0;
while (skb) {
nskb = skb->next;
skb->next = NULL;
if (skb->destructor)
dev_kfree_skb_any(skb);
else
dev_kfree_skb(skb);
nest++;
skb = nskb;
}
}
uint bcm_pktfrombuf(struct sk_buff *p, uint offset, int len,
unsigned char *buf)
{
uint n, ret = 0;
for (; p && offset; p = p->next) {
if (offset < (uint) (p->len))
break;
offset -= p->len;
}
if (!p)
return 0;
for (; p && len; p = p->next) {
n = min((uint) (p->len) - offset, (uint) len);
memcpy(p->data + offset, buf, n);
buf += n;
len -= n;
ret += n;
offset = 0;
}
return ret;
}
uint bcm_pkttotlen(struct sk_buff *p)
{
uint total;
total = 0;
for (; p; p = p->next)
total += p->len;
return total;
}
struct sk_buff *bcm_pktq_penq(struct pktq *pq, int prec,
struct sk_buff *p)
{
struct pktq_prec *q;
if (pktq_full(pq) || pktq_pfull(pq, prec))
return NULL;
q = &pq->q[prec];
if (q->head)
q->tail->prev = p;
else
q->head = p;
q->tail = p;
q->len++;
pq->len++;
if (pq->hi_prec < prec)
pq->hi_prec = (u8) prec;
return p;
}
struct sk_buff *bcm_pktq_penq_head(struct pktq *pq, int prec,
struct sk_buff *p)
{
struct pktq_prec *q;
if (pktq_full(pq) || pktq_pfull(pq, prec))
return NULL;
q = &pq->q[prec];
if (q->head == NULL)
q->tail = p;
p->prev = q->head;
q->head = p;
q->len++;
pq->len++;
if (pq->hi_prec < prec)
pq->hi_prec = (u8) prec;
return p;
}
struct sk_buff *bcm_pktq_pdeq(struct pktq *pq, int prec)
{
struct pktq_prec *q;
struct sk_buff *p;
q = &pq->q[prec];
p = q->head;
if (p == NULL)
return NULL;
q->head = p->prev;
if (q->head == NULL)
q->tail = NULL;
q->len--;
pq->len--;
p->prev = NULL;
return p;
}
struct sk_buff *bcm_pktq_pdeq_tail(struct pktq *pq, int prec)
{
struct pktq_prec *q;
struct sk_buff *p, *prev;
q = &pq->q[prec];
p = q->head;
if (p == NULL)
return NULL;
for (prev = NULL; p != q->tail; p = p->prev)
prev = p;
if (prev)
prev->prev = NULL;
else
q->head = NULL;
q->tail = prev;
q->len--;
pq->len--;
return p;
}
void
bcm_pktq_pflush(struct pktq *pq, int prec, bool dir,
ifpkt_cb_t fn, void *arg)
{
struct pktq_prec *q;
struct sk_buff *p, *prev = NULL;
q = &pq->q[prec];
p = q->head;
while (p) {
if (fn == NULL || (*fn) (p, arg)) {
bool head = (p == q->head);
if (head)
q->head = p->prev;
else
prev->prev = p->prev;
p->prev = NULL;
bcm_pkt_buf_free_skb(p);
q->len--;
pq->len--;
p = (head ? q->head : prev->prev);
} else {
prev = p;
p = p->prev;
}
}
if (q->head == NULL) {
q->tail = NULL;
}
}
void bcm_pktq_flush(struct pktq *pq, bool dir,
ifpkt_cb_t fn, void *arg)
{
int prec;
for (prec = 0; prec < pq->num_prec; prec++)
bcm_pktq_pflush(pq, prec, dir, fn, arg);
}
void bcm_pktq_init(struct pktq *pq, int num_prec, int max_len)
{
int prec;
memset(pq, 0,
offsetof(struct pktq, q) + (sizeof(struct pktq_prec) * num_prec));
pq->num_prec = (u16) num_prec;
pq->max = (u16) max_len;
for (prec = 0; prec < num_prec; prec++)
pq->q[prec].max = pq->max;
}
struct sk_buff *bcm_pktq_peek_tail(struct pktq *pq, int *prec_out)
{
int prec;
if (pq->len == 0)
return NULL;
for (prec = 0; prec < pq->hi_prec; prec++)
if (pq->q[prec].head)
break;
if (prec_out)
*prec_out = prec;
return pq->q[prec].tail;
}
int bcm_pktq_mlen(struct pktq *pq, uint prec_bmp)
{
int prec, len;
len = 0;
for (prec = 0; prec <= pq->hi_prec; prec++)
if (prec_bmp & (1 << prec))
len += pq->q[prec].len;
return len;
}
struct sk_buff *bcm_pktq_mdeq(struct pktq *pq, uint prec_bmp,
int *prec_out)
{
struct pktq_prec *q;
struct sk_buff *p;
int prec;
if (pq->len == 0)
return NULL;
while ((prec = pq->hi_prec) > 0 && pq->q[prec].head == NULL)
pq->hi_prec--;
while ((prec_bmp & (1 << prec)) == 0 || pq->q[prec].head == NULL)
if (prec-- == 0)
return NULL;
q = &pq->q[prec];
p = q->head;
if (p == NULL)
return NULL;
q->head = p->prev;
if (q->head == NULL)
q->tail = NULL;
q->len--;
if (prec_out)
*prec_out = prec;
pq->len--;
p->prev = NULL;
return p;
}
int bcm_ether_atoe(char *p, u8 *ea)
{
int i = 0;
for (;;) {
ea[i++] = (char)simple_strtoul(p, &p, 16);
if (!*p++ || i == 6)
break;
}
return i == 6;
}
void bcm_prpkt(const char *msg, struct sk_buff *p0)
{
struct sk_buff *p;
if (msg && (msg[0] != '\0'))
printk(KERN_DEBUG "%s:\n", msg);
for (p = p0; p; p = p->next)
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, p->data, p->len);
}
const bcm_iovar_t *bcm_iovar_lookup(const bcm_iovar_t *table, const char *name)
{
const bcm_iovar_t *vi;
const char *lookup_name;
lookup_name = strrchr(name, ':');
if (lookup_name != NULL)
lookup_name++;
else
lookup_name = name;
for (vi = table; vi->name; vi++) {
if (!strcmp(vi->name, lookup_name))
return vi;
}
return NULL;
}
int bcm_iovar_lencheck(const bcm_iovar_t *vi, void *arg, int len, bool set)
{
int bcmerror = 0;
switch (vi->type) {
case IOVT_BOOL:
case IOVT_INT8:
case IOVT_INT16:
case IOVT_INT32:
case IOVT_UINT8:
case IOVT_UINT16:
case IOVT_UINT32:
if (len < (int)sizeof(int)) {
bcmerror = -EOVERFLOW;
}
break;
case IOVT_BUFFER:
if (len < vi->minlen) {
bcmerror = -EOVERFLOW;
}
break;
case IOVT_VOID:
if (!set) {
bcmerror = -ENOTSUPP;
} else if (len) {
bcmerror = -ENOBUFS;
}
break;
default:
bcmerror = -ENOTSUPP;
}
return bcmerror;
}
u8 bcm_crc8(u8 *pdata,
uint nbytes,
u8 crc
) {
while (nbytes-- > 0)
crc = crc8_table[(crc ^ *pdata++) & 0xff];
return crc;
}
bcm_tlv_t *bcm_parse_tlvs(void *buf, int buflen, uint key)
{
bcm_tlv_t *elt;
int totlen;
elt = (bcm_tlv_t *) buf;
totlen = buflen;
while (totlen >= 2) {
int len = elt->len;
if ((elt->id == key) && (totlen >= (len + 2)))
return elt;
elt = (bcm_tlv_t *) ((u8 *) elt + (len + 2));
totlen -= (len + 2);
}
return NULL;
}
int
bcm_format_flags(const bcm_bit_desc_t *bd, u32 flags, char *buf, int len)
{
int i;
char *p = buf;
char hexstr[16];
int slen = 0, nlen = 0;
u32 bit;
const char *name;
if (len < 2 || !buf)
return 0;
buf[0] = '\0';
for (i = 0; flags != 0; i++) {
bit = bd[i].bit;
name = bd[i].name;
if (bit == 0 && flags != 0) {
snprintf(hexstr, 16, "0x%X", flags);
name = hexstr;
flags = 0;
} else if ((flags & bit) == 0)
continue;
flags &= ~bit;
nlen = strlen(name);
slen += nlen;
if (flags != 0)
slen += 1;
if (len <= slen)
break;
strncpy(p, name, nlen + 1);
p += nlen;
if (flags != 0)
p += snprintf(p, 2, " ");
len -= slen;
}
if (flags != 0) {
if (len < 2)
p -= 2 - len;
p += snprintf(p, 2, ">");
}
return (int)(p - buf);
}
int bcm_format_hex(char *str, const void *bytes, int len)
{
int i;
char *p = str;
const u8 *src = (const u8 *)bytes;
for (i = 0; i < len; i++) {
p += snprintf(p, 3, "%02X", *src);
src++;
}
return (int)(p - str);
}
char *bcm_chipname(uint chipid, char *buf, uint len)
{
const char *fmt;
fmt = ((chipid > 0xa000) || (chipid < 0x4000)) ? "%d" : "%x";
snprintf(buf, len, fmt, chipid);
return buf;
}
uint bcm_mkiovar(char *name, char *data, uint datalen, char *buf, uint buflen)
{
uint len;
len = strlen(name) + 1;
if ((len + datalen) > buflen)
return 0;
strncpy(buf, name, buflen);
memcpy(&buf[len], data, datalen);
len += datalen;
return len;
}
u16 bcm_qdbm_to_mw(u8 qdbm)
{
uint factor = 1;
int idx = qdbm - QDBM_OFFSET;
if (idx >= QDBM_TABLE_LEN) {
return 0xFFFF;
}
while (idx < 0) {
idx += 40;
factor *= 10;
}
return (nqdBm_to_mW_map[idx] + factor / 2) / factor;
}
u8 bcm_mw_to_qdbm(u16 mw)
{
u8 qdbm;
int offset;
uint mw_uint = mw;
uint boundary;
if (mw_uint <= 1)
return 0;
offset = QDBM_OFFSET;
while (mw_uint < QDBM_TABLE_LOW_BOUND) {
mw_uint *= 10;
offset -= 40;
}
for (qdbm = 0; qdbm < QDBM_TABLE_LEN - 1; qdbm++) {
boundary = nqdBm_to_mW_map[qdbm] + (nqdBm_to_mW_map[qdbm + 1] -
nqdBm_to_mW_map[qdbm]) / 2;
if (mw_uint < boundary)
break;
}
qdbm += (u8) offset;
return qdbm;
}
uint bcm_bitcount(u8 *bitmap, uint length)
{
uint bitcount = 0, i;
u8 tmp;
for (i = 0; i < length; i++) {
tmp = bitmap[i];
while (tmp) {
bitcount++;
tmp &= (tmp - 1);
}
}
return bitcount;
}
void bcm_binit(struct bcmstrbuf *b, char *buf, uint size)
{
b->origsize = b->size = size;
b->origbuf = b->buf = buf;
}
int bcm_bprintf(struct bcmstrbuf *b, const char *fmt, ...)
{
va_list ap;
int r;
va_start(ap, fmt);
r = vsnprintf(b->buf, b->size, fmt, ap);
if ((r == -1) || (r >= (int)b->size) || (r == 0)) {
b->size = 0;
} else {
b->size -= r;
b->buf += r;
}
va_end(ap);
return r;
}
