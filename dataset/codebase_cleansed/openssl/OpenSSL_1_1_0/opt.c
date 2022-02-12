char *opt_progname(const char *argv0)
{
size_t i, n;
const char *p;
char *q;
for (p = argv0 + strlen(argv0); --p > argv0;)
if (*p == '/' || *p == '\\' || *p == ':') {
p++;
break;
}
n = strlen(p);
if (n > 4 &&
(strcmp(&p[n - 4], ".exe") == 0 || strcmp(&p[n - 4], ".EXE") == 0))
n -= 4;
if (n > sizeof prog - 1)
n = sizeof prog - 1;
for (q = prog, i = 0; i < n; i++, p++)
*q++ = isupper(*p) ? tolower(*p) : *p;
*q = '\0';
return prog;
}
char *opt_progname(const char *argv0)
{
const char *p, *q;
for (p = argv0 + strlen(argv0); --p > argv0;)
if (*p == ':' || *p == ']' || *p == '>') {
p++;
break;
}
q = strrchr(p, '.');
strncpy(prog, p, sizeof prog - 1);
prog[sizeof prog - 1] = '\0';
if (q != NULL && q - p < sizeof prog)
prog[q - p] = '\0';
return prog;
}
char *opt_progname(const char *argv0)
{
const char *p;
for (p = argv0 + strlen(argv0); --p > argv0;)
if (*p == '/') {
p++;
break;
}
strncpy(prog, p, sizeof prog - 1);
prog[sizeof prog - 1] = '\0';
return prog;
}
char *opt_getprog(void)
{
return prog;
}
char *opt_init(int ac, char **av, const OPTIONS *o)
{
argc = ac;
argv = av;
opt_index = 1;
opts = o;
opt_progname(av[0]);
unknown = NULL;
for (; o->name; ++o) {
#ifndef NDEBUG
const OPTIONS *next;
int duplicated, i;
#endif
if (o->name == OPT_HELP_STR || o->name == OPT_MORE_STR)
continue;
#ifndef NDEBUG
i = o->valtype;
assert(o->name[0] != '-');
assert(o->retval > 0);
switch (i) {
case 0: case '-': case '/': case '<': case '>': case 'E': case 'F':
case 'M': case 'U': case 'f': case 'l': case 'n': case 'p': case 's':
case 'u': case 'c':
break;
default:
assert(0);
}
for (next = o + 1; next->name; ++next) {
duplicated = strcmp(o->name, next->name) == 0;
assert(!duplicated);
}
#endif
if (o->name[0] == '\0') {
assert(unknown == NULL);
unknown = o;
assert(unknown->valtype == 0 || unknown->valtype == '-');
}
}
return prog;
}
int opt_format_error(const char *s, unsigned long flags)
{
OPT_PAIR *ap;
if (flags == OPT_FMT_PEMDER)
BIO_printf(bio_err, "%s: Bad format \"%s\"; must be pem or der\n",
prog, s);
else {
BIO_printf(bio_err, "%s: Bad format \"%s\"; must be one of:\n",
prog, s);
for (ap = formats; ap->name; ap++)
if (flags & ap->retval)
BIO_printf(bio_err, " %s\n", ap->name);
}
return 0;
}
int opt_format(const char *s, unsigned long flags, int *result)
{
switch (*s) {
default:
return 0;
case 'D':
case 'd':
if ((flags & OPT_FMT_PEMDER) == 0)
return opt_format_error(s, flags);
*result = FORMAT_ASN1;
break;
case 'T':
case 't':
if ((flags & OPT_FMT_TEXT) == 0)
return opt_format_error(s, flags);
*result = FORMAT_TEXT;
break;
case 'N':
case 'n':
if ((flags & OPT_FMT_NSS) == 0)
return opt_format_error(s, flags);
if (strcmp(s, "NSS") != 0 && strcmp(s, "nss") != 0)
return opt_format_error(s, flags);
*result = FORMAT_NSS;
break;
case 'S':
case 's':
if ((flags & OPT_FMT_SMIME) == 0)
return opt_format_error(s, flags);
*result = FORMAT_SMIME;
break;
case 'M':
case 'm':
if ((flags & OPT_FMT_MSBLOB) == 0)
return opt_format_error(s, flags);
*result = FORMAT_MSBLOB;
break;
case 'E':
case 'e':
if ((flags & OPT_FMT_ENGINE) == 0)
return opt_format_error(s, flags);
*result = FORMAT_ENGINE;
break;
case 'H':
case 'h':
if ((flags & OPT_FMT_HTTP) == 0)
return opt_format_error(s, flags);
*result = FORMAT_HTTP;
break;
case '1':
if ((flags & OPT_FMT_PKCS12) == 0)
return opt_format_error(s, flags);
*result = FORMAT_PKCS12;
break;
case 'P':
case 'p':
if (s[1] == '\0' || strcmp(s, "PEM") == 0 || strcmp(s, "pem") == 0) {
if ((flags & OPT_FMT_PEMDER) == 0)
return opt_format_error(s, flags);
*result = FORMAT_PEM;
} else if (strcmp(s, "PVK") == 0 || strcmp(s, "pvk") == 0) {
if ((flags & OPT_FMT_PVK) == 0)
return opt_format_error(s, flags);
*result = FORMAT_PVK;
} else if (strcmp(s, "P12") == 0 || strcmp(s, "p12") == 0
|| strcmp(s, "PKCS12") == 0 || strcmp(s, "pkcs12") == 0) {
if ((flags & OPT_FMT_PKCS12) == 0)
return opt_format_error(s, flags);
*result = FORMAT_PKCS12;
} else
return 0;
break;
}
return 1;
}
int opt_cipher(const char *name, const EVP_CIPHER **cipherp)
{
*cipherp = EVP_get_cipherbyname(name);
if (*cipherp)
return 1;
BIO_printf(bio_err, "%s: Unknown cipher %s\n", prog, name);
return 0;
}
int opt_md(const char *name, const EVP_MD **mdp)
{
*mdp = EVP_get_digestbyname(name);
if (*mdp)
return 1;
BIO_printf(bio_err, "%s: Unknown digest %s\n", prog, name);
return 0;
}
int opt_pair(const char *name, const OPT_PAIR* pairs, int *result)
{
const OPT_PAIR *pp;
for (pp = pairs; pp->name; pp++)
if (strcmp(pp->name, name) == 0) {
*result = pp->retval;
return 1;
}
BIO_printf(bio_err, "%s: Value must be one of:\n", prog);
for (pp = pairs; pp->name; pp++)
BIO_printf(bio_err, "\t%s\n", pp->name);
return 0;
}
int opt_int(const char *value, int *result)
{
long l;
if (!opt_long(value, &l))
return 0;
*result = (int)l;
if (*result != l) {
BIO_printf(bio_err, "%s: Value \"%s\" outside integer range\n",
prog, value);
return 0;
}
return 1;
}
int opt_long(const char *value, long *result)
{
int oerrno = errno;
long l;
char *endp;
errno = 0;
l = strtol(value, &endp, 0);
if (*endp
|| endp == value
|| ((l == LONG_MAX || l == LONG_MIN) && errno == ERANGE)
|| (l == 0 && errno != 0)) {
BIO_printf(bio_err, "%s: Can't parse \"%s\" as a number\n",
prog, value);
errno = oerrno;
return 0;
}
*result = l;
errno = oerrno;
return 1;
}
int opt_imax(const char *value, intmax_t *result)
{
int oerrno = errno;
intmax_t m;
char *endp;
errno = 0;
m = strtoimax(value, &endp, 0);
if (*endp
|| endp == value
|| ((m == INTMAX_MAX || m == INTMAX_MIN) && errno == ERANGE)
|| (m == 0 && errno != 0)) {
BIO_printf(bio_err, "%s: Can't parse \"%s\" as a number\n",
prog, value);
errno = oerrno;
return 0;
}
*result = m;
errno = oerrno;
return 1;
}
int opt_umax(const char *value, uintmax_t *result)
{
int oerrno = errno;
uintmax_t m;
char *endp;
errno = 0;
m = strtoumax(value, &endp, 0);
if (*endp
|| endp == value
|| (m == UINTMAX_MAX && errno == ERANGE)
|| (m == 0 && errno != 0)) {
BIO_printf(bio_err, "%s: Can't parse \"%s\" as a number\n",
prog, value);
errno = oerrno;
return 0;
}
*result = m;
errno = oerrno;
return 1;
}
int opt_ulong(const char *value, unsigned long *result)
{
int oerrno = errno;
char *endptr;
unsigned long l;
errno = 0;
l = strtoul(value, &endptr, 0);
if (*endptr
|| endptr == value
|| ((l == ULONG_MAX) && errno == ERANGE)
|| (l == 0 && errno != 0)) {
BIO_printf(bio_err, "%s: Can't parse \"%s\" as an unsigned number\n",
prog, value);
errno = oerrno;
return 0;
}
*result = l;
errno = oerrno;
return 1;
}
int opt_verify(int opt, X509_VERIFY_PARAM *vpm)
{
int i;
ossl_intmax_t t = 0;
ASN1_OBJECT *otmp;
X509_PURPOSE *xptmp;
const X509_VERIFY_PARAM *vtmp;
assert(vpm != NULL);
assert(opt > OPT_V__FIRST);
assert(opt < OPT_V__LAST);
switch ((enum range)opt) {
case OPT_V__FIRST:
case OPT_V__LAST:
return 0;
case OPT_V_POLICY:
otmp = OBJ_txt2obj(opt_arg(), 0);
if (otmp == NULL) {
BIO_printf(bio_err, "%s: Invalid Policy %s\n", prog, opt_arg());
return 0;
}
X509_VERIFY_PARAM_add0_policy(vpm, otmp);
break;
case OPT_V_PURPOSE:
i = X509_PURPOSE_get_by_sname(opt_arg());
if (i < 0) {
BIO_printf(bio_err, "%s: Invalid purpose %s\n", prog, opt_arg());
return 0;
}
xptmp = X509_PURPOSE_get0(i);
i = X509_PURPOSE_get_id(xptmp);
if (!X509_VERIFY_PARAM_set_purpose(vpm, i)) {
BIO_printf(bio_err,
"%s: Internal error setting purpose %s\n",
prog, opt_arg());
return 0;
}
break;
case OPT_V_VERIFY_NAME:
vtmp = X509_VERIFY_PARAM_lookup(opt_arg());
if (vtmp == NULL) {
BIO_printf(bio_err, "%s: Invalid verify name %s\n",
prog, opt_arg());
return 0;
}
X509_VERIFY_PARAM_set1(vpm, vtmp);
break;
case OPT_V_VERIFY_DEPTH:
i = atoi(opt_arg());
if (i >= 0)
X509_VERIFY_PARAM_set_depth(vpm, i);
break;
case OPT_V_VERIFY_AUTH_LEVEL:
i = atoi(opt_arg());
if (i >= 0)
X509_VERIFY_PARAM_set_auth_level(vpm, i);
break;
case OPT_V_ATTIME:
if (!opt_imax(opt_arg(), &t))
return 0;
if (t != (time_t)t) {
BIO_printf(bio_err, "%s: epoch time out of range %s\n",
prog, opt_arg());
return 0;
}
X509_VERIFY_PARAM_set_time(vpm, (time_t)t);
break;
case OPT_V_VERIFY_HOSTNAME:
if (!X509_VERIFY_PARAM_set1_host(vpm, opt_arg(), 0))
return 0;
break;
case OPT_V_VERIFY_EMAIL:
if (!X509_VERIFY_PARAM_set1_email(vpm, opt_arg(), 0))
return 0;
break;
case OPT_V_VERIFY_IP:
if (!X509_VERIFY_PARAM_set1_ip_asc(vpm, opt_arg()))
return 0;
break;
case OPT_V_IGNORE_CRITICAL:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_IGNORE_CRITICAL);
break;
case OPT_V_ISSUER_CHECKS:
break;
case OPT_V_CRL_CHECK:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_CRL_CHECK);
break;
case OPT_V_CRL_CHECK_ALL:
X509_VERIFY_PARAM_set_flags(vpm,
X509_V_FLAG_CRL_CHECK |
X509_V_FLAG_CRL_CHECK_ALL);
break;
case OPT_V_POLICY_CHECK:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_POLICY_CHECK);
break;
case OPT_V_EXPLICIT_POLICY:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_EXPLICIT_POLICY);
break;
case OPT_V_INHIBIT_ANY:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_INHIBIT_ANY);
break;
case OPT_V_INHIBIT_MAP:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_INHIBIT_MAP);
break;
case OPT_V_X509_STRICT:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_X509_STRICT);
break;
case OPT_V_EXTENDED_CRL:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_EXTENDED_CRL_SUPPORT);
break;
case OPT_V_USE_DELTAS:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_USE_DELTAS);
break;
case OPT_V_POLICY_PRINT:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_NOTIFY_POLICY);
break;
case OPT_V_CHECK_SS_SIG:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_CHECK_SS_SIGNATURE);
break;
case OPT_V_TRUSTED_FIRST:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_TRUSTED_FIRST);
break;
case OPT_V_SUITEB_128_ONLY:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_SUITEB_128_LOS_ONLY);
break;
case OPT_V_SUITEB_128:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_SUITEB_128_LOS);
break;
case OPT_V_SUITEB_192:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_SUITEB_192_LOS);
break;
case OPT_V_PARTIAL_CHAIN:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_PARTIAL_CHAIN);
break;
case OPT_V_NO_ALT_CHAINS:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_NO_ALT_CHAINS);
break;
case OPT_V_NO_CHECK_TIME:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_NO_CHECK_TIME);
break;
case OPT_V_ALLOW_PROXY_CERTS:
X509_VERIFY_PARAM_set_flags(vpm, X509_V_FLAG_ALLOW_PROXY_CERTS);
break;
}
return 1;
}
int opt_next(void)
{
char *p;
const OPTIONS *o;
int ival;
long lval;
unsigned long ulval;
ossl_intmax_t imval;
ossl_uintmax_t umval;
arg = NULL;
p = argv[opt_index];
if (p == NULL)
return 0;
if (*p != '-')
return 0;
opt_index++;
if (strcmp(p, "--") == 0)
return 0;
if (*++p == '-')
p++;
flag = p - 1;
if ((arg = strchr(p, '=')) != NULL)
*arg++ = '\0';
for (o = opts; o->name; ++o) {
if (strcmp(p, o->name) != 0)
continue;
if (o->valtype == 0 || o->valtype == '-') {
if (arg) {
BIO_printf(bio_err,
"%s: Option -%s does not take a value\n", prog, p);
return -1;
}
return o->retval;
}
if (arg == NULL) {
if (argv[opt_index] == NULL) {
BIO_printf(bio_err,
"%s: Option -%s needs a value\n", prog, o->name);
return -1;
}
arg = argv[opt_index++];
}
switch (o->valtype) {
default:
case 's':
break;
case '/':
if (app_isdir(arg) >= 0)
break;
BIO_printf(bio_err, "%s: Not a directory: %s\n", prog, arg);
return -1;
case '<':
if (strcmp(arg, "-") == 0 || app_access(arg, R_OK) >= 0)
break;
BIO_printf(bio_err,
"%s: Cannot open input file %s, %s\n",
prog, arg, strerror(errno));
return -1;
case '>':
if (strcmp(arg, "-") == 0 || app_access(arg, W_OK) >= 0 || errno == ENOENT)
break;
BIO_printf(bio_err,
"%s: Cannot open output file %s, %s\n",
prog, arg, strerror(errno));
return -1;
case 'p':
case 'n':
if (!opt_int(arg, &ival)
|| (o->valtype == 'p' && ival <= 0)) {
BIO_printf(bio_err,
"%s: Non-positive number \"%s\" for -%s\n",
prog, arg, o->name);
return -1;
}
break;
case 'M':
if (!opt_imax(arg, &imval)) {
BIO_printf(bio_err,
"%s: Invalid number \"%s\" for -%s\n",
prog, arg, o->name);
return -1;
}
break;
case 'U':
if (!opt_umax(arg, &umval)) {
BIO_printf(bio_err,
"%s: Invalid number \"%s\" for -%s\n",
prog, arg, o->name);
return -1;
}
break;
case 'l':
if (!opt_long(arg, &lval)) {
BIO_printf(bio_err,
"%s: Invalid number \"%s\" for -%s\n",
prog, arg, o->name);
return -1;
}
break;
case 'u':
if (!opt_ulong(arg, &ulval)) {
BIO_printf(bio_err,
"%s: Invalid number \"%s\" for -%s\n",
prog, arg, o->name);
return -1;
}
break;
case 'c':
case 'E':
case 'F':
case 'f':
if (opt_format(arg,
o->valtype == 'c' ? OPT_FMT_PDS :
o->valtype == 'E' ? OPT_FMT_PDE :
o->valtype == 'F' ? OPT_FMT_PEMDER
: OPT_FMT_ANY, &ival))
break;
BIO_printf(bio_err,
"%s: Invalid format \"%s\" for -%s\n",
prog, arg, o->name);
return -1;
}
return o->retval;
}
if (unknown != NULL) {
dunno = p;
return unknown->retval;
}
BIO_printf(bio_err, "%s: Option unknown option -%s\n", prog, p);
return -1;
}
char *opt_arg(void)
{
return arg;
}
char *opt_flag(void)
{
return flag;
}
char *opt_unknown(void)
{
return dunno;
}
char **opt_rest(void)
{
return &argv[opt_index];
}
int opt_num_rest(void)
{
int i = 0;
char **pp;
for (pp = opt_rest(); *pp; pp++, i++)
continue;
return i;
}
static const char *valtype2param(const OPTIONS *o)
{
switch (o->valtype) {
case 0:
case '-':
return "";
case 's':
return "val";
case '/':
return "dir";
case '<':
return "infile";
case '>':
return "outfile";
case 'p':
return "+int";
case 'n':
return "int";
case 'l':
return "long";
case 'u':
return "ulong";
case 'E':
return "PEM|DER|ENGINE";
case 'F':
return "PEM|DER";
case 'f':
return "format";
case 'M':
return "intmax";
case 'U':
return "uintmax";
}
return "parm";
}
void opt_help(const OPTIONS *list)
{
const OPTIONS *o;
int i;
int standard_prolog;
int width = 5;
char start[80 + 1];
char *p;
const char *help;
standard_prolog = list[0].name != OPT_HELP_STR;
for (o = list; o->name; o++) {
if (o->name == OPT_MORE_STR)
continue;
i = 2 + (int)strlen(o->name);
if (o->valtype != '-')
i += 1 + strlen(valtype2param(o));
if (i < MAX_OPT_HELP_WIDTH && i > width)
width = i;
assert(i < (int)sizeof start);
}
if (standard_prolog)
BIO_printf(bio_err, "Usage: %s [options]\nValid options are:\n",
prog);
for (o = list; o->name; o++) {
help = o->helpstr ? o->helpstr : "(No additional info)";
if (o->name == OPT_HELP_STR) {
BIO_printf(bio_err, help, prog);
continue;
}
memset(start, ' ', sizeof(start) - 1);
start[sizeof start - 1] = '\0';
if (o->name == OPT_MORE_STR) {
start[width] = '\0';
BIO_printf(bio_err, "%s %s\n", start, help);
continue;
}
p = start;
*p++ = ' ';
*p++ = '-';
if (o->name[0])
p += strlen(strcpy(p, o->name));
else
*p++ = '*';
if (o->valtype != '-') {
*p++ = ' ';
p += strlen(strcpy(p, valtype2param(o)));
}
*p = ' ';
if ((int)(p - start) >= MAX_OPT_HELP_WIDTH) {
*p = '\0';
BIO_printf(bio_err, "%s\n", start);
memset(start, ' ', sizeof(start));
}
start[width] = '\0';
BIO_printf(bio_err, "%s %s\n", start, help);
}
}
int app_isdir(const char *name)
{
struct stat sb;
return name != NULL && stat(name, &sb) >= 0 && S_ISDIR(sb.st_mode);
}
int main(int ac, char **av)
{
OPTION_CHOICE o;
char **rest;
char *prog;
bio_err = BIO_new_fp(stderr, BIO_NOCLOSE | BIO_FP_TEXT);
prog = opt_init(ac, av, options);
while ((o = opt_next()) != OPT_EOF) {
switch (c) {
case OPT_NOTUSED:
case OPT_EOF:
case OPT_ERR:
printf("%s: Usage error; try -help.\n", prog);
return 1;
case OPT_HELP:
opt_help(options);
return 0;
case OPT_IN:
printf("in %s\n", opt_arg());
break;
case OPT_INFORM:
printf("inform %s\n", opt_arg());
break;
case OPT_OUT:
printf("out %s\n", opt_arg());
break;
case OPT_COUNT:
printf("count %s\n", opt_arg());
break;
case OPT_U:
printf("u %s\n", opt_arg());
break;
case OPT_FLAG:
printf("flag\n");
break;
case OPT_STR:
printf("str %s\n", opt_arg());
break;
}
}
argc = opt_num_rest();
argv = opt_rest();
printf("args = %d\n", argc);
if (argc)
while (*argv)
printf(" %s\n", *argv++);
return 0;
}
