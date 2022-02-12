static int hvc_beat_get_chars(uint32_t vtermno, char *buf, int cnt)
{
static unsigned char q[sizeof(unsigned long) * 2]
__attribute__((aligned(sizeof(unsigned long))));
static int qlen = 0;
u64 got;
again:
if (qlen) {
if (qlen > cnt) {
memcpy(buf, q, cnt);
qlen -= cnt;
memmove(q + cnt, q, qlen);
return cnt;
} else {
int r;
memcpy(buf, q, qlen);
r = qlen;
qlen = 0;
return r;
}
}
if (beat_get_term_char(vtermno, &got,
((u64 *)q), ((u64 *)q) + 1) == 0) {
qlen = got;
goto again;
}
return 0;
}
static int hvc_beat_put_chars(uint32_t vtermno, const char *buf, int cnt)
{
unsigned long kb[2];
int rest, nlen;
for (rest = cnt; rest > 0; rest -= nlen) {
nlen = (rest > 16) ? 16 : rest;
memcpy(kb, buf, nlen);
beat_put_term_char(vtermno, nlen, kb[0], kb[1]);
buf += nlen;
}
return cnt;
}
static int hvc_beat_config(char *p)
{
hvc_beat_useit = simple_strtoul(p, NULL, 0);
return 0;
}
static int __init hvc_beat_console_init(void)
{
if (hvc_beat_useit && of_machine_is_compatible("Beat")) {
hvc_instantiate(0, 0, &hvc_beat_get_put_ops);
}
return 0;
}
static int __init hvc_beat_init(void)
{
struct hvc_struct *hp;
if (!firmware_has_feature(FW_FEATURE_BEAT))
return -ENODEV;
hp = hvc_alloc(0, 0, &hvc_beat_get_put_ops, 16);
if (IS_ERR(hp))
return PTR_ERR(hp);
hvc_beat_dev = hp;
return 0;
}
static void __exit hvc_beat_exit(void)
{
if (hvc_beat_dev)
hvc_remove(hvc_beat_dev);
}
