static int validate_nla(const struct nlattr *nla, int maxtype,
const struct nla_policy *policy)
{
const struct nla_policy *pt;
int minlen = 0, attrlen = nla_len(nla), type = nla_type(nla);
if (type <= 0 || type > maxtype)
return 0;
pt = &policy[type];
BUG_ON(pt->type > NLA_TYPE_MAX);
switch (pt->type) {
case NLA_FLAG:
if (attrlen > 0)
return -ERANGE;
break;
case NLA_NUL_STRING:
if (pt->len)
minlen = min_t(int, attrlen, pt->len + 1);
else
minlen = attrlen;
if (!minlen || memchr(nla_data(nla), '\0', minlen) == NULL)
return -EINVAL;
case NLA_STRING:
if (attrlen < 1)
return -ERANGE;
if (pt->len) {
char *buf = nla_data(nla);
if (buf[attrlen - 1] == '\0')
attrlen--;
if (attrlen > pt->len)
return -ERANGE;
}
break;
case NLA_BINARY:
if (pt->len && attrlen > pt->len)
return -ERANGE;
break;
case NLA_NESTED_COMPAT:
if (attrlen < pt->len)
return -ERANGE;
if (attrlen < NLA_ALIGN(pt->len))
break;
if (attrlen < NLA_ALIGN(pt->len) + NLA_HDRLEN)
return -ERANGE;
nla = nla_data(nla) + NLA_ALIGN(pt->len);
if (attrlen < NLA_ALIGN(pt->len) + NLA_HDRLEN + nla_len(nla))
return -ERANGE;
break;
case NLA_NESTED:
if (attrlen == 0)
break;
default:
if (pt->len)
minlen = pt->len;
else if (pt->type != NLA_UNSPEC)
minlen = nla_attr_minlen[pt->type];
if (attrlen < minlen)
return -ERANGE;
}
return 0;
}
int nla_validate(const struct nlattr *head, int len, int maxtype,
const struct nla_policy *policy,
struct netlink_ext_ack *extack)
{
const struct nlattr *nla;
int rem;
nla_for_each_attr(nla, head, len, rem) {
int err = validate_nla(nla, maxtype, policy);
if (err < 0) {
if (extack)
extack->bad_attr = nla;
return err;
}
}
return 0;
}
int
nla_policy_len(const struct nla_policy *p, int n)
{
int i, len = 0;
for (i = 0; i < n; i++, p++) {
if (p->len)
len += nla_total_size(p->len);
else if (nla_attr_minlen[p->type])
len += nla_total_size(nla_attr_minlen[p->type]);
}
return len;
}
int nla_parse(struct nlattr **tb, int maxtype, const struct nlattr *head,
int len, const struct nla_policy *policy,
struct netlink_ext_ack *extack)
{
const struct nlattr *nla;
int rem, err;
memset(tb, 0, sizeof(struct nlattr *) * (maxtype + 1));
nla_for_each_attr(nla, head, len, rem) {
u16 type = nla_type(nla);
if (type > 0 && type <= maxtype) {
if (policy) {
err = validate_nla(nla, maxtype, policy);
if (err < 0) {
if (extack)
extack->bad_attr = nla;
goto errout;
}
}
tb[type] = (struct nlattr *)nla;
}
}
if (unlikely(rem > 0))
pr_warn_ratelimited("netlink: %d bytes leftover after parsing attributes in process `%s'.\n",
rem, current->comm);
err = 0;
errout:
return err;
}
struct nlattr *nla_find(const struct nlattr *head, int len, int attrtype)
{
const struct nlattr *nla;
int rem;
nla_for_each_attr(nla, head, len, rem)
if (nla_type(nla) == attrtype)
return (struct nlattr *)nla;
return NULL;
}
size_t nla_strlcpy(char *dst, const struct nlattr *nla, size_t dstsize)
{
size_t srclen = nla_len(nla);
char *src = nla_data(nla);
if (srclen > 0 && src[srclen - 1] == '\0')
srclen--;
if (dstsize > 0) {
size_t len = (srclen >= dstsize) ? dstsize - 1 : srclen;
memset(dst, 0, dstsize);
memcpy(dst, src, len);
}
return srclen;
}
int nla_memcpy(void *dest, const struct nlattr *src, int count)
{
int minlen = min_t(int, count, nla_len(src));
memcpy(dest, nla_data(src), minlen);
if (count > minlen)
memset(dest + minlen, 0, count - minlen);
return minlen;
}
int nla_memcmp(const struct nlattr *nla, const void *data,
size_t size)
{
int d = nla_len(nla) - size;
if (d == 0)
d = memcmp(nla_data(nla), data, size);
return d;
}
int nla_strcmp(const struct nlattr *nla, const char *str)
{
int len = strlen(str);
char *buf = nla_data(nla);
int attrlen = nla_len(nla);
int d;
if (attrlen > 0 && buf[attrlen - 1] == '\0')
attrlen--;
d = attrlen - len;
if (d == 0)
d = memcmp(nla_data(nla), str, len);
return d;
}
struct nlattr *__nla_reserve(struct sk_buff *skb, int attrtype, int attrlen)
{
struct nlattr *nla;
nla = (struct nlattr *) skb_put(skb, nla_total_size(attrlen));
nla->nla_type = attrtype;
nla->nla_len = nla_attr_size(attrlen);
memset((unsigned char *) nla + nla->nla_len, 0, nla_padlen(attrlen));
return nla;
}
struct nlattr *__nla_reserve_64bit(struct sk_buff *skb, int attrtype,
int attrlen, int padattr)
{
if (nla_need_padding_for_64bit(skb))
nla_align_64bit(skb, padattr);
return __nla_reserve(skb, attrtype, attrlen);
}
void *__nla_reserve_nohdr(struct sk_buff *skb, int attrlen)
{
void *start;
start = skb_put(skb, NLA_ALIGN(attrlen));
memset(start, 0, NLA_ALIGN(attrlen));
return start;
}
struct nlattr *nla_reserve(struct sk_buff *skb, int attrtype, int attrlen)
{
if (unlikely(skb_tailroom(skb) < nla_total_size(attrlen)))
return NULL;
return __nla_reserve(skb, attrtype, attrlen);
}
struct nlattr *nla_reserve_64bit(struct sk_buff *skb, int attrtype, int attrlen,
int padattr)
{
size_t len;
if (nla_need_padding_for_64bit(skb))
len = nla_total_size_64bit(attrlen);
else
len = nla_total_size(attrlen);
if (unlikely(skb_tailroom(skb) < len))
return NULL;
return __nla_reserve_64bit(skb, attrtype, attrlen, padattr);
}
void *nla_reserve_nohdr(struct sk_buff *skb, int attrlen)
{
if (unlikely(skb_tailroom(skb) < NLA_ALIGN(attrlen)))
return NULL;
return __nla_reserve_nohdr(skb, attrlen);
}
void __nla_put(struct sk_buff *skb, int attrtype, int attrlen,
const void *data)
{
struct nlattr *nla;
nla = __nla_reserve(skb, attrtype, attrlen);
memcpy(nla_data(nla), data, attrlen);
}
void __nla_put_64bit(struct sk_buff *skb, int attrtype, int attrlen,
const void *data, int padattr)
{
struct nlattr *nla;
nla = __nla_reserve_64bit(skb, attrtype, attrlen, padattr);
memcpy(nla_data(nla), data, attrlen);
}
void __nla_put_nohdr(struct sk_buff *skb, int attrlen, const void *data)
{
void *start;
start = __nla_reserve_nohdr(skb, attrlen);
memcpy(start, data, attrlen);
}
int nla_put(struct sk_buff *skb, int attrtype, int attrlen, const void *data)
{
if (unlikely(skb_tailroom(skb) < nla_total_size(attrlen)))
return -EMSGSIZE;
__nla_put(skb, attrtype, attrlen, data);
return 0;
}
int nla_put_64bit(struct sk_buff *skb, int attrtype, int attrlen,
const void *data, int padattr)
{
size_t len;
if (nla_need_padding_for_64bit(skb))
len = nla_total_size_64bit(attrlen);
else
len = nla_total_size(attrlen);
if (unlikely(skb_tailroom(skb) < len))
return -EMSGSIZE;
__nla_put_64bit(skb, attrtype, attrlen, data, padattr);
return 0;
}
int nla_put_nohdr(struct sk_buff *skb, int attrlen, const void *data)
{
if (unlikely(skb_tailroom(skb) < NLA_ALIGN(attrlen)))
return -EMSGSIZE;
__nla_put_nohdr(skb, attrlen, data);
return 0;
}
int nla_append(struct sk_buff *skb, int attrlen, const void *data)
{
if (unlikely(skb_tailroom(skb) < NLA_ALIGN(attrlen)))
return -EMSGSIZE;
memcpy(skb_put(skb, attrlen), data, attrlen);
return 0;
}
