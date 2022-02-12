int v3_addr_get_afi(const IPAddressFamily *f)
{
return ((f != NULL &&
f->addressFamily != NULL &&
f->addressFamily->data != NULL)
? ((f->addressFamily->data[0] << 8) |
(f->addressFamily->data[1]))
: 0);
}
static int addr_expand(unsigned char *addr,
const ASN1_BIT_STRING *bs,
const int length,
const unsigned char fill)
{
if (bs->length < 0 || bs->length > length)
return 0;
if (bs->length > 0) {
memcpy(addr, bs->data, bs->length);
if ((bs->flags & 7) != 0) {
unsigned char mask = 0xFF >> (8 - (bs->flags & 7));
if (fill == 0)
addr[bs->length - 1] &= ~mask;
else
addr[bs->length - 1] |= mask;
}
}
memset(addr + bs->length, fill, length - bs->length);
return 1;
}
static int i2r_address(BIO *out,
const unsigned afi,
const unsigned char fill,
const ASN1_BIT_STRING *bs)
{
unsigned char addr[ADDR_RAW_BUF_LEN];
int i, n;
if (bs->length < 0)
return 0;
switch (afi) {
case IANA_AFI_IPV4:
if (!addr_expand(addr, bs, 4, fill))
return 0;
BIO_printf(out, "%d.%d.%d.%d", addr[0], addr[1], addr[2], addr[3]);
break;
case IANA_AFI_IPV6:
if (!addr_expand(addr, bs, 16, fill))
return 0;
for (n = 16; n > 1 && addr[n-1] == 0x00 && addr[n-2] == 0x00; n -= 2)
;
for (i = 0; i < n; i += 2)
BIO_printf(out, "%x%s", (addr[i] << 8) | addr[i+1], (i < 14 ? ":" : ""));
if (i < 16)
BIO_puts(out, ":");
if (i == 0)
BIO_puts(out, ":");
break;
default:
for (i = 0; i < bs->length; i++)
BIO_printf(out, "%s%02x", (i > 0 ? ":" : ""), bs->data[i]);
BIO_printf(out, "[%d]", (int) (bs->flags & 7));
break;
}
return 1;
}
static int i2r_IPAddressOrRanges(BIO *out,
const int indent,
const IPAddressOrRanges *aors,
const unsigned afi)
{
int i;
for (i = 0; i < sk_IPAddressOrRange_num(aors); i++) {
const IPAddressOrRange *aor = sk_IPAddressOrRange_value(aors, i);
BIO_printf(out, "%*s", indent, "");
switch (aor->type) {
case IPAddressOrRange_addressPrefix:
if (!i2r_address(out, afi, 0x00, aor->u.addressPrefix))
return 0;
BIO_printf(out, "/%d\n", addr_prefixlen(aor->u.addressPrefix));
continue;
case IPAddressOrRange_addressRange:
if (!i2r_address(out, afi, 0x00, aor->u.addressRange->min))
return 0;
BIO_puts(out, "-");
if (!i2r_address(out, afi, 0xFF, aor->u.addressRange->max))
return 0;
BIO_puts(out, "\n");
continue;
}
}
return 1;
}
static int i2r_IPAddrBlocks(const X509V3_EXT_METHOD *method,
void *ext,
BIO *out,
int indent)
{
const IPAddrBlocks *addr = ext;
int i;
for (i = 0; i < sk_IPAddressFamily_num(addr); i++) {
IPAddressFamily *f = sk_IPAddressFamily_value(addr, i);
const unsigned int afi = v3_addr_get_afi(f);
switch (afi) {
case IANA_AFI_IPV4:
BIO_printf(out, "%*sIPv4", indent, "");
break;
case IANA_AFI_IPV6:
BIO_printf(out, "%*sIPv6", indent, "");
break;
default:
BIO_printf(out, "%*sUnknown AFI %u", indent, "", afi);
break;
}
if (f->addressFamily->length > 2) {
switch (f->addressFamily->data[2]) {
case 1:
BIO_puts(out, " (Unicast)");
break;
case 2:
BIO_puts(out, " (Multicast)");
break;
case 3:
BIO_puts(out, " (Unicast/Multicast)");
break;
case 4:
BIO_puts(out, " (MPLS)");
break;
case 64:
BIO_puts(out, " (Tunnel)");
break;
case 65:
BIO_puts(out, " (VPLS)");
break;
case 66:
BIO_puts(out, " (BGP MDT)");
break;
case 128:
BIO_puts(out, " (MPLS-labeled VPN)");
break;
default:
BIO_printf(out, " (Unknown SAFI %u)",
(unsigned) f->addressFamily->data[2]);
break;
}
}
switch (f->ipAddressChoice->type) {
case IPAddressChoice_inherit:
BIO_puts(out, ": inherit\n");
break;
case IPAddressChoice_addressesOrRanges:
BIO_puts(out, ":\n");
if (!i2r_IPAddressOrRanges(out,
indent + 2,
f->ipAddressChoice->u.addressesOrRanges,
afi))
return 0;
break;
}
}
return 1;
}
static int IPAddressOrRange_cmp(const IPAddressOrRange *a,
const IPAddressOrRange *b,
const int length)
{
unsigned char addr_a[ADDR_RAW_BUF_LEN], addr_b[ADDR_RAW_BUF_LEN];
int prefixlen_a = 0, prefixlen_b = 0;
int r;
switch (a->type) {
case IPAddressOrRange_addressPrefix:
if (!addr_expand(addr_a, a->u.addressPrefix, length, 0x00))
return -1;
prefixlen_a = addr_prefixlen(a->u.addressPrefix);
break;
case IPAddressOrRange_addressRange:
if (!addr_expand(addr_a, a->u.addressRange->min, length, 0x00))
return -1;
prefixlen_a = length * 8;
break;
}
switch (b->type) {
case IPAddressOrRange_addressPrefix:
if (!addr_expand(addr_b, b->u.addressPrefix, length, 0x00))
return -1;
prefixlen_b = addr_prefixlen(b->u.addressPrefix);
break;
case IPAddressOrRange_addressRange:
if (!addr_expand(addr_b, b->u.addressRange->min, length, 0x00))
return -1;
prefixlen_b = length * 8;
break;
}
if ((r = memcmp(addr_a, addr_b, length)) != 0)
return r;
else
return prefixlen_a - prefixlen_b;
}
static int v4IPAddressOrRange_cmp(const IPAddressOrRange * const *a,
const IPAddressOrRange * const *b)
{
return IPAddressOrRange_cmp(*a, *b, 4);
}
static int v6IPAddressOrRange_cmp(const IPAddressOrRange * const *a,
const IPAddressOrRange * const *b)
{
return IPAddressOrRange_cmp(*a, *b, 16);
}
static int range_should_be_prefix(const unsigned char *min,
const unsigned char *max,
const int length)
{
unsigned char mask;
int i, j;
OPENSSL_assert(memcmp(min, max, length) <= 0);
for (i = 0; i < length && min[i] == max[i]; i++)
;
for (j = length - 1; j >= 0 && min[j] == 0x00 && max[j] == 0xFF; j--)
;
if (i < j)
return -1;
if (i > j)
return i * 8;
mask = min[i] ^ max[i];
switch (mask) {
case 0x01: j = 7; break;
case 0x03: j = 6; break;
case 0x07: j = 5; break;
case 0x0F: j = 4; break;
case 0x1F: j = 3; break;
case 0x3F: j = 2; break;
case 0x7F: j = 1; break;
default: return -1;
}
if ((min[i] & mask) != 0 || (max[i] & mask) != mask)
return -1;
else
return i * 8 + j;
}
static int make_addressPrefix(IPAddressOrRange **result,
unsigned char *addr,
const int prefixlen)
{
int bytelen = (prefixlen + 7) / 8, bitlen = prefixlen % 8;
IPAddressOrRange *aor = IPAddressOrRange_new();
if (aor == NULL)
return 0;
aor->type = IPAddressOrRange_addressPrefix;
if (aor->u.addressPrefix == NULL &&
(aor->u.addressPrefix = ASN1_BIT_STRING_new()) == NULL)
goto err;
if (!ASN1_BIT_STRING_set(aor->u.addressPrefix, addr, bytelen))
goto err;
aor->u.addressPrefix->flags &= ~7;
aor->u.addressPrefix->flags |= ASN1_STRING_FLAG_BITS_LEFT;
if (bitlen > 0) {
aor->u.addressPrefix->data[bytelen - 1] &= ~(0xFF >> bitlen);
aor->u.addressPrefix->flags |= 8 - bitlen;
}
*result = aor;
return 1;
err:
IPAddressOrRange_free(aor);
return 0;
}
static int make_addressRange(IPAddressOrRange **result,
unsigned char *min,
unsigned char *max,
const int length)
{
IPAddressOrRange *aor;
int i, prefixlen;
if ((prefixlen = range_should_be_prefix(min, max, length)) >= 0)
return make_addressPrefix(result, min, prefixlen);
if ((aor = IPAddressOrRange_new()) == NULL)
return 0;
aor->type = IPAddressOrRange_addressRange;
OPENSSL_assert(aor->u.addressRange == NULL);
if ((aor->u.addressRange = IPAddressRange_new()) == NULL)
goto err;
if (aor->u.addressRange->min == NULL &&
(aor->u.addressRange->min = ASN1_BIT_STRING_new()) == NULL)
goto err;
if (aor->u.addressRange->max == NULL &&
(aor->u.addressRange->max = ASN1_BIT_STRING_new()) == NULL)
goto err;
for (i = length; i > 0 && min[i - 1] == 0x00; --i)
;
if (!ASN1_BIT_STRING_set(aor->u.addressRange->min, min, i))
goto err;
aor->u.addressRange->min->flags &= ~7;
aor->u.addressRange->min->flags |= ASN1_STRING_FLAG_BITS_LEFT;
if (i > 0) {
unsigned char b = min[i - 1];
int j = 1;
while ((b & (0xFFU >> j)) != 0)
++j;
aor->u.addressRange->min->flags |= 8 - j;
}
for (i = length; i > 0 && max[i - 1] == 0xFF; --i)
;
if (!ASN1_BIT_STRING_set(aor->u.addressRange->max, max, i))
goto err;
aor->u.addressRange->max->flags &= ~7;
aor->u.addressRange->max->flags |= ASN1_STRING_FLAG_BITS_LEFT;
if (i > 0) {
unsigned char b = max[i - 1];
int j = 1;
while ((b & (0xFFU >> j)) != (0xFFU >> j))
++j;
aor->u.addressRange->max->flags |= 8 - j;
}
*result = aor;
return 1;
err:
IPAddressOrRange_free(aor);
return 0;
}
static IPAddressFamily *make_IPAddressFamily(IPAddrBlocks *addr,
const unsigned afi,
const unsigned *safi)
{
IPAddressFamily *f;
unsigned char key[3];
unsigned keylen;
int i;
key[0] = (afi >> 8) & 0xFF;
key[1] = afi & 0xFF;
if (safi != NULL) {
key[2] = *safi & 0xFF;
keylen = 3;
} else {
keylen = 2;
}
for (i = 0; i < sk_IPAddressFamily_num(addr); i++) {
f = sk_IPAddressFamily_value(addr, i);
OPENSSL_assert(f->addressFamily->data != NULL);
if (f->addressFamily->length == keylen &&
!memcmp(f->addressFamily->data, key, keylen))
return f;
}
if ((f = IPAddressFamily_new()) == NULL)
goto err;
if (f->ipAddressChoice == NULL &&
(f->ipAddressChoice = IPAddressChoice_new()) == NULL)
goto err;
if (f->addressFamily == NULL &&
(f->addressFamily = ASN1_OCTET_STRING_new()) == NULL)
goto err;
if (!ASN1_OCTET_STRING_set(f->addressFamily, key, keylen))
goto err;
if (!sk_IPAddressFamily_push(addr, f))
goto err;
return f;
err:
IPAddressFamily_free(f);
return NULL;
}
int v3_addr_add_inherit(IPAddrBlocks *addr,
const unsigned afi,
const unsigned *safi)
{
IPAddressFamily *f = make_IPAddressFamily(addr, afi, safi);
if (f == NULL ||
f->ipAddressChoice == NULL ||
(f->ipAddressChoice->type == IPAddressChoice_addressesOrRanges &&
f->ipAddressChoice->u.addressesOrRanges != NULL))
return 0;
if (f->ipAddressChoice->type == IPAddressChoice_inherit &&
f->ipAddressChoice->u.inherit != NULL)
return 1;
if (f->ipAddressChoice->u.inherit == NULL &&
(f->ipAddressChoice->u.inherit = ASN1_NULL_new()) == NULL)
return 0;
f->ipAddressChoice->type = IPAddressChoice_inherit;
return 1;
}
static IPAddressOrRanges *make_prefix_or_range(IPAddrBlocks *addr,
const unsigned afi,
const unsigned *safi)
{
IPAddressFamily *f = make_IPAddressFamily(addr, afi, safi);
IPAddressOrRanges *aors = NULL;
if (f == NULL ||
f->ipAddressChoice == NULL ||
(f->ipAddressChoice->type == IPAddressChoice_inherit &&
f->ipAddressChoice->u.inherit != NULL))
return NULL;
if (f->ipAddressChoice->type == IPAddressChoice_addressesOrRanges)
aors = f->ipAddressChoice->u.addressesOrRanges;
if (aors != NULL)
return aors;
if ((aors = sk_IPAddressOrRange_new_null()) == NULL)
return NULL;
switch (afi) {
case IANA_AFI_IPV4:
(void) sk_IPAddressOrRange_set_cmp_func(aors, v4IPAddressOrRange_cmp);
break;
case IANA_AFI_IPV6:
(void) sk_IPAddressOrRange_set_cmp_func(aors, v6IPAddressOrRange_cmp);
break;
}
f->ipAddressChoice->type = IPAddressChoice_addressesOrRanges;
f->ipAddressChoice->u.addressesOrRanges = aors;
return aors;
}
int v3_addr_add_prefix(IPAddrBlocks *addr,
const unsigned afi,
const unsigned *safi,
unsigned char *a,
const int prefixlen)
{
IPAddressOrRanges *aors = make_prefix_or_range(addr, afi, safi);
IPAddressOrRange *aor;
if (aors == NULL || !make_addressPrefix(&aor, a, prefixlen))
return 0;
if (sk_IPAddressOrRange_push(aors, aor))
return 1;
IPAddressOrRange_free(aor);
return 0;
}
int v3_addr_add_range(IPAddrBlocks *addr,
const unsigned afi,
const unsigned *safi,
unsigned char *min,
unsigned char *max)
{
IPAddressOrRanges *aors = make_prefix_or_range(addr, afi, safi);
IPAddressOrRange *aor;
int length = length_from_afi(afi);
if (aors == NULL)
return 0;
if (!make_addressRange(&aor, min, max, length))
return 0;
if (sk_IPAddressOrRange_push(aors, aor))
return 1;
IPAddressOrRange_free(aor);
return 0;
}
static int extract_min_max(IPAddressOrRange *aor,
unsigned char *min,
unsigned char *max,
int length)
{
if (aor == NULL || min == NULL || max == NULL)
return 0;
switch (aor->type) {
case IPAddressOrRange_addressPrefix:
return (addr_expand(min, aor->u.addressPrefix, length, 0x00) &&
addr_expand(max, aor->u.addressPrefix, length, 0xFF));
case IPAddressOrRange_addressRange:
return (addr_expand(min, aor->u.addressRange->min, length, 0x00) &&
addr_expand(max, aor->u.addressRange->max, length, 0xFF));
}
return 0;
}
int v3_addr_get_range(IPAddressOrRange *aor,
const unsigned afi,
unsigned char *min,
unsigned char *max,
const int length)
{
int afi_length = length_from_afi(afi);
if (aor == NULL || min == NULL || max == NULL ||
afi_length == 0 || length < afi_length ||
(aor->type != IPAddressOrRange_addressPrefix &&
aor->type != IPAddressOrRange_addressRange) ||
!extract_min_max(aor, min, max, afi_length))
return 0;
return afi_length;
}
static int IPAddressFamily_cmp(const IPAddressFamily * const *a_,
const IPAddressFamily * const *b_)
{
const ASN1_OCTET_STRING *a = (*a_)->addressFamily;
const ASN1_OCTET_STRING *b = (*b_)->addressFamily;
int len = ((a->length <= b->length) ? a->length : b->length);
int cmp = memcmp(a->data, b->data, len);
return cmp ? cmp : a->length - b->length;
}
int v3_addr_is_canonical(IPAddrBlocks *addr)
{
unsigned char a_min[ADDR_RAW_BUF_LEN], a_max[ADDR_RAW_BUF_LEN];
unsigned char b_min[ADDR_RAW_BUF_LEN], b_max[ADDR_RAW_BUF_LEN];
IPAddressOrRanges *aors;
int i, j, k;
if (addr == NULL)
return 1;
for (i = 0; i < sk_IPAddressFamily_num(addr) - 1; i++) {
const IPAddressFamily *a = sk_IPAddressFamily_value(addr, i);
const IPAddressFamily *b = sk_IPAddressFamily_value(addr, i + 1);
if (IPAddressFamily_cmp(&a, &b) >= 0)
return 0;
}
for (i = 0; i < sk_IPAddressFamily_num(addr); i++) {
IPAddressFamily *f = sk_IPAddressFamily_value(addr, i);
int length = length_from_afi(v3_addr_get_afi(f));
if (f == NULL || f->ipAddressChoice == NULL)
return 0;
switch (f->ipAddressChoice->type) {
case IPAddressChoice_inherit:
continue;
case IPAddressChoice_addressesOrRanges:
break;
default:
return 0;
}
aors = f->ipAddressChoice->u.addressesOrRanges;
if (sk_IPAddressOrRange_num(aors) == 0)
return 0;
for (j = 0; j < sk_IPAddressOrRange_num(aors) - 1; j++) {
IPAddressOrRange *a = sk_IPAddressOrRange_value(aors, j);
IPAddressOrRange *b = sk_IPAddressOrRange_value(aors, j + 1);
if (!extract_min_max(a, a_min, a_max, length) ||
!extract_min_max(b, b_min, b_max, length))
return 0;
if (memcmp(a_min, b_min, length) >= 0 ||
memcmp(a_min, a_max, length) > 0 ||
memcmp(b_min, b_max, length) > 0)
return 0;
for (k = length - 1; k >= 0 && b_min[k]-- == 0x00; k--)
;
if (memcmp(a_max, b_min, length) >= 0)
return 0;
if (a->type == IPAddressOrRange_addressRange &&
range_should_be_prefix(a_min, a_max, length) >= 0)
return 0;
}
j = sk_IPAddressOrRange_num(aors) - 1;
{
IPAddressOrRange *a = sk_IPAddressOrRange_value(aors, j);
if (a != NULL && a->type == IPAddressOrRange_addressRange) {
if (!extract_min_max(a, a_min, a_max, length))
return 0;
if (memcmp(a_min, a_max, length) > 0 ||
range_should_be_prefix(a_min, a_max, length) >= 0)
return 0;
}
}
}
return 1;
}
static int IPAddressOrRanges_canonize(IPAddressOrRanges *aors,
const unsigned afi)
{
int i, j, length = length_from_afi(afi);
sk_IPAddressOrRange_sort(aors);
for (i = 0; i < sk_IPAddressOrRange_num(aors) - 1; i++) {
IPAddressOrRange *a = sk_IPAddressOrRange_value(aors, i);
IPAddressOrRange *b = sk_IPAddressOrRange_value(aors, i + 1);
unsigned char a_min[ADDR_RAW_BUF_LEN], a_max[ADDR_RAW_BUF_LEN];
unsigned char b_min[ADDR_RAW_BUF_LEN], b_max[ADDR_RAW_BUF_LEN];
if (!extract_min_max(a, a_min, a_max, length) ||
!extract_min_max(b, b_min, b_max, length))
return 0;
if (memcmp(a_min, a_max, length) > 0 ||
memcmp(b_min, b_max, length) > 0)
return 0;
if (memcmp(a_max, b_min, length) >= 0)
return 0;
for (j = length - 1; j >= 0 && b_min[j]-- == 0x00; j--)
;
if (memcmp(a_max, b_min, length) == 0) {
IPAddressOrRange *merged;
if (!make_addressRange(&merged, a_min, b_max, length))
return 0;
(void) sk_IPAddressOrRange_set(aors, i, merged);
(void) sk_IPAddressOrRange_delete(aors, i + 1);
IPAddressOrRange_free(a);
IPAddressOrRange_free(b);
--i;
continue;
}
}
j = sk_IPAddressOrRange_num(aors) - 1;
{
IPAddressOrRange *a = sk_IPAddressOrRange_value(aors, j);
if (a != NULL && a->type == IPAddressOrRange_addressRange) {
unsigned char a_min[ADDR_RAW_BUF_LEN], a_max[ADDR_RAW_BUF_LEN];
extract_min_max(a, a_min, a_max, length);
if (memcmp(a_min, a_max, length) > 0)
return 0;
}
}
return 1;
}
int v3_addr_canonize(IPAddrBlocks *addr)
{
int i;
for (i = 0; i < sk_IPAddressFamily_num(addr); i++) {
IPAddressFamily *f = sk_IPAddressFamily_value(addr, i);
if (f->ipAddressChoice->type == IPAddressChoice_addressesOrRanges &&
!IPAddressOrRanges_canonize(f->ipAddressChoice->u.addressesOrRanges,
v3_addr_get_afi(f)))
return 0;
}
(void) sk_IPAddressFamily_set_cmp_func(addr, IPAddressFamily_cmp);
sk_IPAddressFamily_sort(addr);
OPENSSL_assert(v3_addr_is_canonical(addr));
return 1;
}
int v3_addr_inherits(IPAddrBlocks *addr)
{
int i;
if (addr == NULL)
return 0;
for (i = 0; i < sk_IPAddressFamily_num(addr); i++) {
IPAddressFamily *f = sk_IPAddressFamily_value(addr, i);
if (f->ipAddressChoice->type == IPAddressChoice_inherit)
return 1;
}
return 0;
}
static int addr_contains(IPAddressOrRanges *parent,
IPAddressOrRanges *child,
int length)
{
unsigned char p_min[ADDR_RAW_BUF_LEN], p_max[ADDR_RAW_BUF_LEN];
unsigned char c_min[ADDR_RAW_BUF_LEN], c_max[ADDR_RAW_BUF_LEN];
int p, c;
if (child == NULL || parent == child)
return 1;
if (parent == NULL)
return 0;
p = 0;
for (c = 0; c < sk_IPAddressOrRange_num(child); c++) {
if (!extract_min_max(sk_IPAddressOrRange_value(child, c),
c_min, c_max, length))
return -1;
for (;; p++) {
if (p >= sk_IPAddressOrRange_num(parent))
return 0;
if (!extract_min_max(sk_IPAddressOrRange_value(parent, p),
p_min, p_max, length))
return 0;
if (memcmp(p_max, c_max, length) < 0)
continue;
if (memcmp(p_min, c_min, length) > 0)
return 0;
break;
}
}
return 1;
}
int v3_addr_subset(IPAddrBlocks *a, IPAddrBlocks *b)
{
int i;
if (a == NULL || a == b)
return 1;
if (b == NULL || v3_addr_inherits(a) || v3_addr_inherits(b))
return 0;
(void) sk_IPAddressFamily_set_cmp_func(b, IPAddressFamily_cmp);
for (i = 0; i < sk_IPAddressFamily_num(a); i++) {
IPAddressFamily *fa = sk_IPAddressFamily_value(a, i);
int j = sk_IPAddressFamily_find(b, fa);
IPAddressFamily *fb;
fb = sk_IPAddressFamily_value(b, j);
if (fb == NULL)
return 0;
if (!addr_contains(fb->ipAddressChoice->u.addressesOrRanges,
fa->ipAddressChoice->u.addressesOrRanges,
length_from_afi(v3_addr_get_afi(fb))))
return 0;
}
return 1;
}
int v3_addr_validate_path(X509_STORE_CTX *ctx)
{
return v3_addr_validate_path_internal(ctx, ctx->chain, NULL);
}
