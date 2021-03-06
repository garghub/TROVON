static int match_one(char *s, const char *p, substring_t args[])
{
char *meta;
int argc = 0;
if (!p)
return 1;
while(1) {
int len = -1;
meta = strchr(p, '%');
if (!meta)
return strcmp(p, s) == 0;
if (strncmp(p, s, meta-p))
return 0;
s += meta - p;
p = meta + 1;
if (isdigit(*p))
len = simple_strtoul(p, (char **) &p, 10);
else if (*p == '%') {
if (*s++ != '%')
return 0;
p++;
continue;
}
if (argc >= MAX_OPT_ARGS)
return 0;
args[argc].from = s;
switch (*p++) {
case 's': {
size_t str_len = strlen(s);
if (str_len == 0)
return 0;
if (len == -1 || len > str_len)
len = str_len;
args[argc].to = s + len;
break;
}
case 'd':
simple_strtol(s, &args[argc].to, 0);
goto num;
case 'u':
simple_strtoul(s, &args[argc].to, 0);
goto num;
case 'o':
simple_strtoul(s, &args[argc].to, 8);
goto num;
case 'x':
simple_strtoul(s, &args[argc].to, 16);
num:
if (args[argc].to == args[argc].from)
return 0;
break;
default:
return 0;
}
s = args[argc].to;
argc++;
}
}
int match_token(char *s, const match_table_t table, substring_t args[])
{
const struct match_token *p;
for (p = table; !match_one(s, p->pattern, args) ; p++)
;
return p->token;
}
static int match_number(substring_t *s, int *result, int base)
{
char *endp;
char *buf;
int ret;
long val;
size_t len = s->to - s->from;
buf = kmalloc(len + 1, GFP_KERNEL);
if (!buf)
return -ENOMEM;
memcpy(buf, s->from, len);
buf[len] = '\0';
ret = 0;
val = simple_strtol(buf, &endp, base);
if (endp == buf)
ret = -EINVAL;
else if (val < (long)INT_MIN || val > (long)INT_MAX)
ret = -ERANGE;
else
*result = (int) val;
kfree(buf);
return ret;
}
int match_int(substring_t *s, int *result)
{
return match_number(s, result, 0);
}
int match_octal(substring_t *s, int *result)
{
return match_number(s, result, 8);
}
int match_hex(substring_t *s, int *result)
{
return match_number(s, result, 16);
}
bool match_wildcard(const char *pattern, const char *str)
{
const char *s = str;
const char *p = pattern;
bool star = false;
while (*s) {
switch (*p) {
case '?':
s++;
p++;
break;
case '*':
star = true;
str = s;
if (!*++p)
return true;
pattern = p;
break;
default:
if (*s == *p) {
s++;
p++;
} else {
if (!star)
return false;
str++;
s = str;
p = pattern;
}
break;
}
}
if (*p == '*')
++p;
return !*p;
}
size_t match_strlcpy(char *dest, const substring_t *src, size_t size)
{
size_t ret = src->to - src->from;
if (size) {
size_t len = ret >= size ? size - 1 : ret;
memcpy(dest, src->from, len);
dest[len] = '\0';
}
return ret;
}
char *match_strdup(const substring_t *s)
{
size_t sz = s->to - s->from + 1;
char *p = kmalloc(sz, GFP_KERNEL);
if (p)
match_strlcpy(p, s, sz);
return p;
}
