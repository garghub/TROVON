int net_ratelimit(void)
{
return __ratelimit(&net_ratelimit_state);
}
__be32 in_aton(const char *str)
{
unsigned long l;
unsigned int val;
int i;
l = 0;
for (i = 0; i < 4; i++) {
l <<= 8;
if (*str != '\0') {
val = 0;
while (*str != '\0' && *str != '.' && *str != '\n') {
val *= 10;
val += *str - '0';
str++;
}
l |= val;
if (*str != '\0')
str++;
}
}
return htonl(l);
}
static inline int xdigit2bin(char c, int delim)
{
int val;
if (c == delim || c == '\0')
return IN6PTON_DELIM;
if (c == ':')
return IN6PTON_COLON_MASK;
if (c == '.')
return IN6PTON_DOT;
val = hex_to_bin(c);
if (val >= 0)
return val | IN6PTON_XDIGIT | (val < 10 ? IN6PTON_DIGIT : 0);
if (delim == -1)
return IN6PTON_DELIM;
return IN6PTON_UNKNOWN;
}
int in4_pton(const char *src, int srclen,
u8 *dst,
int delim, const char **end)
{
const char *s;
u8 *d;
u8 dbuf[4];
int ret = 0;
int i;
int w = 0;
if (srclen < 0)
srclen = strlen(src);
s = src;
d = dbuf;
i = 0;
while(1) {
int c;
c = xdigit2bin(srclen > 0 ? *s : '\0', delim);
if (!(c & (IN6PTON_DIGIT | IN6PTON_DOT | IN6PTON_DELIM | IN6PTON_COLON_MASK))) {
goto out;
}
if (c & (IN6PTON_DOT | IN6PTON_DELIM | IN6PTON_COLON_MASK)) {
if (w == 0)
goto out;
*d++ = w & 0xff;
w = 0;
i++;
if (c & (IN6PTON_DELIM | IN6PTON_COLON_MASK)) {
if (i != 4)
goto out;
break;
}
goto cont;
}
w = (w * 10) + c;
if ((w & 0xffff) > 255) {
goto out;
}
cont:
if (i >= 4)
goto out;
s++;
srclen--;
}
ret = 1;
memcpy(dst, dbuf, sizeof(dbuf));
out:
if (end)
*end = s;
return ret;
}
int in6_pton(const char *src, int srclen,
u8 *dst,
int delim, const char **end)
{
const char *s, *tok = NULL;
u8 *d, *dc = NULL;
u8 dbuf[16];
int ret = 0;
int i;
int state = IN6PTON_COLON_1_2 | IN6PTON_XDIGIT | IN6PTON_NULL;
int w = 0;
memset(dbuf, 0, sizeof(dbuf));
s = src;
d = dbuf;
if (srclen < 0)
srclen = strlen(src);
while (1) {
int c;
c = xdigit2bin(srclen > 0 ? *s : '\0', delim);
if (!(c & state))
goto out;
if (c & (IN6PTON_DELIM | IN6PTON_COLON_MASK)) {
if (!(state & IN6PTON_NULL)) {
*d++ = (w >> 8) & 0xff;
*d++ = w & 0xff;
}
w = 0;
if (c & IN6PTON_DELIM) {
break;
}
switch (state & IN6PTON_COLON_MASK) {
case IN6PTON_COLON_2:
dc = d;
state = IN6PTON_XDIGIT | IN6PTON_DELIM;
if (dc - dbuf >= sizeof(dbuf))
state |= IN6PTON_NULL;
break;
case IN6PTON_COLON_1|IN6PTON_COLON_1_2:
state = IN6PTON_XDIGIT | IN6PTON_COLON_2;
break;
case IN6PTON_COLON_1:
state = IN6PTON_XDIGIT;
break;
case IN6PTON_COLON_1_2:
state = IN6PTON_COLON_2;
break;
default:
state = 0;
}
tok = s + 1;
goto cont;
}
if (c & IN6PTON_DOT) {
ret = in4_pton(tok ? tok : s, srclen + (int)(s - tok), d, delim, &s);
if (ret > 0) {
d += 4;
break;
}
goto out;
}
w = (w << 4) | (0xff & c);
state = IN6PTON_COLON_1 | IN6PTON_DELIM;
if (!(w & 0xf000)) {
state |= IN6PTON_XDIGIT;
}
if (!dc && d + 2 < dbuf + sizeof(dbuf)) {
state |= IN6PTON_COLON_1_2;
state &= ~IN6PTON_DELIM;
}
if (d + 2 >= dbuf + sizeof(dbuf)) {
state &= ~(IN6PTON_COLON_1|IN6PTON_COLON_1_2);
}
cont:
if ((dc && d + 4 < dbuf + sizeof(dbuf)) ||
d + 4 == dbuf + sizeof(dbuf)) {
state |= IN6PTON_DOT;
}
if (d >= dbuf + sizeof(dbuf)) {
state &= ~(IN6PTON_XDIGIT|IN6PTON_COLON_MASK);
}
s++;
srclen--;
}
i = 15; d--;
if (dc) {
while(d >= dc)
dst[i--] = *d--;
while(i >= dc - dbuf)
dst[i--] = 0;
while(i >= 0)
dst[i--] = *d--;
} else
memcpy(dst, dbuf, sizeof(dbuf));
ret = 1;
out:
if (end)
*end = s;
return ret;
}
void inet_proto_csum_replace4(__sum16 *sum, struct sk_buff *skb,
__be32 from, __be32 to, int pseudohdr)
{
__be32 diff[] = { ~from, to };
if (skb->ip_summed != CHECKSUM_PARTIAL) {
*sum = csum_fold(csum_partial(diff, sizeof(diff),
~csum_unfold(*sum)));
if (skb->ip_summed == CHECKSUM_COMPLETE && pseudohdr)
skb->csum = ~csum_partial(diff, sizeof(diff),
~skb->csum);
} else if (pseudohdr)
*sum = ~csum_fold(csum_partial(diff, sizeof(diff),
csum_unfold(*sum)));
}
void inet_proto_csum_replace16(__sum16 *sum, struct sk_buff *skb,
const __be32 *from, const __be32 *to,
int pseudohdr)
{
__be32 diff[] = {
~from[0], ~from[1], ~from[2], ~from[3],
to[0], to[1], to[2], to[3],
};
if (skb->ip_summed != CHECKSUM_PARTIAL) {
*sum = csum_fold(csum_partial(diff, sizeof(diff),
~csum_unfold(*sum)));
if (skb->ip_summed == CHECKSUM_COMPLETE && pseudohdr)
skb->csum = ~csum_partial(diff, sizeof(diff),
~skb->csum);
} else if (pseudohdr)
*sum = ~csum_fold(csum_partial(diff, sizeof(diff),
csum_unfold(*sum)));
}
static void __net_random_once_deferred(struct work_struct *w)
{
struct __net_random_once_work *work =
container_of(w, struct __net_random_once_work, work);
if (!static_key_enabled(work->key))
static_key_slow_inc(work->key);
kfree(work);
}
static void __net_random_once_disable_jump(struct static_key *key)
{
struct __net_random_once_work *w;
w = kmalloc(sizeof(*w), GFP_ATOMIC);
if (!w)
return;
INIT_WORK(&w->work, __net_random_once_deferred);
w->key = key;
schedule_work(&w->work);
}
bool __net_get_random_once(void *buf, int nbytes, bool *done,
struct static_key *done_key)
{
static DEFINE_SPINLOCK(lock);
unsigned long flags;
spin_lock_irqsave(&lock, flags);
if (*done) {
spin_unlock_irqrestore(&lock, flags);
return false;
}
get_random_bytes(buf, nbytes);
*done = true;
spin_unlock_irqrestore(&lock, flags);
__net_random_once_disable_jump(done_key);
return true;
}
