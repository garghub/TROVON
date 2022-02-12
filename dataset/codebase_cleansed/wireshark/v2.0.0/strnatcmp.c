static int
nat_isdigit(nat_char a)
{
return g_ascii_isdigit(a);
}
static int
nat_isspace(nat_char a)
{
return g_ascii_isspace(a);
}
static nat_char
nat_toupper(nat_char a)
{
return g_ascii_toupper(a);
}
static int
compare_right(nat_char const *a, nat_char const *b)
{
int bias = 0;
for (;; a++, b++) {
if (!nat_isdigit(*a) && !nat_isdigit(*b))
return bias;
else if (!nat_isdigit(*a))
return -1;
else if (!nat_isdigit(*b))
return +1;
else if (*a < *b) {
if (!bias)
bias = -1;
} else if (*a > *b) {
if (!bias)
bias = +1;
} else if (!*a && !*b)
return bias;
}
return 0;
}
static int
compare_left(nat_char const *a, nat_char const *b)
{
for (;; a++, b++) {
if (!nat_isdigit(*a) && !nat_isdigit(*b))
return 0;
else if (!nat_isdigit(*a))
return -1;
else if (!nat_isdigit(*b))
return +1;
else if (*a < *b)
return -1;
else if (*a > *b)
return +1;
}
return 0;
}
static int strnatcmp0(nat_char const *a, nat_char const *b, int fold_case)
{
int ai, bi;
nat_char ca, cb;
int fractional, result;
if (!a || !b) {
if (!a && !b)
return 0;
if (!a)
return -1;
return +1;
}
ai = bi = 0;
while (1) {
ca = a[ai]; cb = b[bi];
while (nat_isspace(ca))
ca = a[++ai];
while (nat_isspace(cb))
cb = b[++bi];
if (nat_isdigit(ca) && nat_isdigit(cb)) {
fractional = (ca == '0' || cb == '0');
if (fractional) {
if ((result = compare_left(a+ai, b+bi)) != 0)
return result;
} else {
if ((result = compare_right(a+ai, b+bi)) != 0)
return result;
}
}
if (!ca && !cb) {
return 0;
}
if (fold_case) {
ca = nat_toupper(ca);
cb = nat_toupper(cb);
}
if (ca < cb)
return -1;
else if (ca > cb)
return +1;
++ai; ++bi;
}
}
int ws_ascii_strnatcmp(nat_char const *a, nat_char const *b)
{
return strnatcmp0(a, b, 0);
}
int ws_ascii_strnatcasecmp(nat_char const *a, nat_char const *b)
{
return strnatcmp0(a, b, 1);
}
