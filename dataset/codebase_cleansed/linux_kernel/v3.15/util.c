char *xstrdup(const char *s)
{
int len = strlen(s) + 1;
char *dup = xmalloc(len);
memcpy(dup, s, len);
return dup;
}
char *join_path(const char *path, const char *name)
{
int lenp = strlen(path);
int lenn = strlen(name);
int len;
int needslash = 1;
char *str;
len = lenp + lenn + 2;
if ((lenp > 0) && (path[lenp-1] == '/')) {
needslash = 0;
len--;
}
str = xmalloc(len);
memcpy(str, path, lenp);
if (needslash) {
str[lenp] = '/';
lenp++;
}
memcpy(str+lenp, name, lenn+1);
return str;
}
int util_is_printable_string(const void *data, int len)
{
const char *s = data;
const char *ss, *se;
if (len == 0)
return 0;
if (s[len - 1] != '\0')
return 0;
se = s + len;
while (s < se) {
ss = s;
while (s < se && *s && isprint(*s))
s++;
if (*s != '\0' || s == ss)
return 0;
s++;
}
return 1;
}
static char get_oct_char(const char *s, int *i)
{
char x[4];
char *endx;
long val;
x[3] = '\0';
strncpy(x, s + *i, 3);
val = strtol(x, &endx, 8);
assert(endx > x);
(*i) += endx - x;
return val;
}
static char get_hex_char(const char *s, int *i)
{
char x[3];
char *endx;
long val;
x[2] = '\0';
strncpy(x, s + *i, 2);
val = strtol(x, &endx, 16);
if (!(endx > x))
die("\\x used with no following hex digits\n");
(*i) += endx - x;
return val;
}
char get_escape_char(const char *s, int *i)
{
char c = s[*i];
int j = *i + 1;
char val;
assert(c);
switch (c) {
case 'a':
val = '\a';
break;
case 'b':
val = '\b';
break;
case 't':
val = '\t';
break;
case 'n':
val = '\n';
break;
case 'v':
val = '\v';
break;
case 'f':
val = '\f';
break;
case 'r':
val = '\r';
break;
case '0':
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
j--;
val = get_oct_char(s, &j);
break;
case 'x':
val = get_hex_char(s, &j);
break;
default:
val = c;
}
(*i) = j;
return val;
}
int utilfdt_read_err_len(const char *filename, char **buffp, off_t *len)
{
int fd = 0;
char *buf = NULL;
off_t bufsize = 1024, offset = 0;
int ret = 0;
*buffp = NULL;
if (strcmp(filename, "-") != 0) {
fd = open(filename, O_RDONLY);
if (fd < 0)
return errno;
}
buf = xmalloc(bufsize);
do {
if (offset == bufsize) {
bufsize *= 2;
buf = xrealloc(buf, bufsize);
if (!buf) {
ret = ENOMEM;
break;
}
}
ret = read(fd, &buf[offset], bufsize - offset);
if (ret < 0) {
ret = errno;
break;
}
offset += ret;
} while (ret != 0);
close(fd);
if (ret)
free(buf);
else
*buffp = buf;
*len = bufsize;
return ret;
}
int utilfdt_read_err(const char *filename, char **buffp)
{
off_t len;
return utilfdt_read_err_len(filename, buffp, &len);
}
char *utilfdt_read_len(const char *filename, off_t *len)
{
char *buff;
int ret = utilfdt_read_err_len(filename, &buff, len);
if (ret) {
fprintf(stderr, "Couldn't open blob from '%s': %s\n", filename,
strerror(ret));
return NULL;
}
return buff;
}
char *utilfdt_read(const char *filename)
{
off_t len;
return utilfdt_read_len(filename, &len);
}
int utilfdt_write_err(const char *filename, const void *blob)
{
int fd = 1;
int totalsize;
int offset;
int ret = 0;
const char *ptr = blob;
if (strcmp(filename, "-") != 0) {
fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
if (fd < 0)
return errno;
}
totalsize = fdt_totalsize(blob);
offset = 0;
while (offset < totalsize) {
ret = write(fd, ptr + offset, totalsize - offset);
if (ret < 0) {
ret = -errno;
break;
}
offset += ret;
}
if (fd != 1)
close(fd);
return ret < 0 ? -ret : 0;
}
int utilfdt_write(const char *filename, const void *blob)
{
int ret = utilfdt_write_err(filename, blob);
if (ret) {
fprintf(stderr, "Couldn't write blob to '%s': %s\n", filename,
strerror(ret));
}
return ret ? -1 : 0;
}
int utilfdt_decode_type(const char *fmt, int *type, int *size)
{
int qualifier = 0;
if (!*fmt)
return -1;
*size = -1;
if (strchr("hlLb", *fmt)) {
qualifier = *fmt++;
if (qualifier == *fmt) {
switch (*fmt++) {
case 'h':
qualifier = 'b';
break;
}
}
}
if ((*fmt == '\0') || !strchr("iuxs", *fmt))
return -1;
if (*fmt != 's')
*size = qualifier == 'b' ? 1 :
qualifier == 'h' ? 2 :
qualifier == 'l' ? 4 : -1;
*type = *fmt++;
if (*fmt)
return -1;
return 0;
}
void utilfdt_print_data(const char *data, int len)
{
int i;
const char *p = data;
const char *s;
if (len == 0)
return;
if (util_is_printable_string(data, len)) {
printf(" = ");
s = data;
do {
printf("\"%s\"", s);
s += strlen(s) + 1;
if (s < data + len)
printf(", ");
} while (s < data + len);
} else if ((len % 4) == 0) {
const uint32_t *cell = (const uint32_t *)data;
printf(" = <");
for (i = 0; i < len; i += 4)
printf("0x%08x%s", fdt32_to_cpu(cell[i]),
i < (len - 4) ? " " : "");
printf(">");
} else {
printf(" = [");
for (i = 0; i < len; i++)
printf("%02x%s", *p++, i < len - 1 ? " " : "");
printf("]");
}
}
void util_version(void)
{
printf("Version: %s\n", DTC_VERSION);
exit(0);
}
void util_usage(const char *errmsg, const char *synopsis,
const char *short_opts, struct option const long_opts[],
const char * const opts_help[])
{
FILE *fp = errmsg ? stderr : stdout;
const char a_arg[] = "<arg>";
size_t a_arg_len = strlen(a_arg) + 1;
size_t i;
int optlen;
fprintf(fp,
"Usage: %s\n"
"\n"
"Options: -[%s]\n", synopsis, short_opts);
optlen = 0;
for (i = 0; long_opts[i].name; ++i) {
int l = strlen(long_opts[i].name) + 1;
if (long_opts[i].has_arg == a_argument)
l += a_arg_len;
if (optlen < l)
optlen = l;
}
for (i = 0; long_opts[i].name; ++i) {
assert(opts_help[i] != NULL);
if (long_opts[i].val > '~')
fprintf(fp, " ");
else
fprintf(fp, " -%c, ", long_opts[i].val);
if (long_opts[i].has_arg == no_argument)
fprintf(fp, "--%-*s", optlen, long_opts[i].name);
else
fprintf(fp, "--%s %s%*s", long_opts[i].name, a_arg,
(int)(optlen - strlen(long_opts[i].name) - a_arg_len), "");
fprintf(fp, "%s\n", opts_help[i]);
}
if (errmsg) {
fprintf(fp, "\nError: %s\n", errmsg);
exit(EXIT_FAILURE);
} else
exit(EXIT_SUCCESS);
}
