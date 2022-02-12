const char *
inet_ntop(af, src, dst, size)
int af;
const void *src;
char *dst;
size_t size;
{
switch (af) {
case AF_INET:
return (inet_ntop4(src, dst, size));
case AF_INET6:
return (inet_ntop6(src, dst, size));
default:
errno = EAFNOSUPPORT;
return (NULL);
}
}
static const char *
inet_ntop4(src, dst, size)
const u_char *src;
char *dst;
size_t size;
{
static const char fmt[] = "%u.%u.%u.%u";
char tmp[sizeof "255.255.255.255"];
int nprinted;
nprinted = g_snprintf(tmp, sizeof(tmp), fmt, src[0], src[1], src[2], src[3]);
if ((size_t)nprinted >= size) {
errno = ENOSPC;
return (NULL);
}
g_strlcpy(dst, tmp, size);
return (dst);
}
static const char *
inet_ntop6(src, dst, size)
const u_char *src;
char *dst;
size_t size;
{
char tmp[sizeof "ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255"], *tp;
struct { int base, len; } best, cur;
u_int words[NS_IN6ADDRSZ / NS_INT16SZ];
int i;
memset(words, '\0', sizeof words);
for (i = 0; i < NS_IN6ADDRSZ; i++)
words[i / 2] |= (src[i] << ((1 - (i % 2)) << 3));
best.base = -1;
cur.base = -1;
for (i = 0; i < (NS_IN6ADDRSZ / NS_INT16SZ); i++) {
if (words[i] == 0) {
if (cur.base == -1)
cur.base = i, cur.len = 1;
else
cur.len++;
} else {
if (cur.base != -1) {
if (best.base == -1 || cur.len > best.len)
best = cur;
cur.base = -1;
}
}
}
if (cur.base != -1) {
if (best.base == -1 || cur.len > best.len)
best = cur;
}
if (best.base != -1 && best.len < 2)
best.base = -1;
tp = tmp;
for (i = 0; i < (NS_IN6ADDRSZ / NS_INT16SZ); i++) {
if (best.base != -1 && i >= best.base &&
i < (best.base + best.len)) {
if (i == best.base)
*tp++ = ':';
continue;
}
if (i != 0)
*tp++ = ':';
if (i == 6 && best.base == 0 &&
(best.len == 6 || (best.len == 5 && words[5] == 0xffff))) {
if (!inet_ntop4(src+12, tp, sizeof tmp - (tp - tmp)))
return (NULL);
tp += strlen(tp);
break;
}
tp += g_snprintf(tp, (gulong) (sizeof tmp - (tp - tmp)), "%x", words[i]);
}
if (best.base != -1 && (best.base + best.len) ==
(NS_IN6ADDRSZ / NS_INT16SZ))
*tp++ = ':';
*tp++ = '\0';
if ((size_t)(tp - tmp) > size) {
errno = ENOSPC;
return (NULL);
}
g_strlcpy(dst, tmp, size);
return (dst);
}
