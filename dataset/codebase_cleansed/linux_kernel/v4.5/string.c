s64 perf_atoll(const char *str)
{
s64 length;
char *p;
char c;
if (!isdigit(str[0]))
goto out_err;
length = strtoll(str, &p, 10);
switch (c = *p++) {
case 'b': case 'B':
if (*p)
goto out_err;
case '\0':
return length;
default:
goto out_err;
case 'k': case 'K':
length <<= 10;
break;
case 'm': case 'M':
length <<= 20;
break;
case 'g': case 'G':
length <<= 30;
break;
case 't': case 'T':
length <<= 40;
break;
}
if (islower(c)) {
if (strcmp(p, "b") != 0)
goto out_err;
} else {
if (strcmp(p, "B") != 0)
goto out_err;
}
return length;
out_err:
return -1;
}
static const char *skip_sep(const char *cp)
{
while (*cp && isspace(*cp))
cp++;
return cp;
}
static const char *skip_arg(const char *cp)
{
while (*cp && !isspace(*cp))
cp++;
return cp;
}
static int count_argc(const char *str)
{
int count = 0;
while (*str) {
str = skip_sep(str);
if (*str) {
count++;
str = skip_arg(str);
}
}
return count;
}
void argv_free(char **argv)
{
char **p;
for (p = argv; *p; p++)
zfree(p);
free(argv);
}
char **argv_split(const char *str, int *argcp)
{
int argc = count_argc(str);
char **argv = zalloc(sizeof(*argv) * (argc+1));
char **argvp;
if (argv == NULL)
goto out;
if (argcp)
*argcp = argc;
argvp = argv;
while (*str) {
str = skip_sep(str);
if (*str) {
const char *p = str;
char *t;
str = skip_arg(str);
t = strndup(p, str-p);
if (t == NULL)
goto fail;
*argvp++ = t;
}
}
*argvp = NULL;
out:
return argv;
fail:
argv_free(argv);
return NULL;
}
static bool __match_charclass(const char *pat, char c, const char **npat)
{
bool complement = false, ret = true;
if (*pat == '!') {
complement = true;
pat++;
}
if (*pat++ == c)
goto end;
while (*pat && *pat != ']') {
if (*pat == '-' && *(pat + 1) != ']') {
if (*(pat - 1) <= c && c <= *(pat + 1))
goto end;
if (*(pat - 1) > *(pat + 1))
goto error;
pat += 2;
} else if (*pat++ == c)
goto end;
}
if (!*pat)
goto error;
ret = false;
end:
while (*pat && *pat != ']')
pat++;
if (!*pat)
goto error;
*npat = pat + 1;
return complement ? !ret : ret;
error:
return false;
}
static bool __match_glob(const char *str, const char *pat, bool ignore_space)
{
while (*str && *pat && *pat != '*') {
if (ignore_space) {
if (isspace(*str)) {
str++;
continue;
}
if (isspace(*pat)) {
pat++;
continue;
}
}
if (*pat == '?') {
str++;
pat++;
continue;
} else if (*pat == '[')
if (__match_charclass(pat + 1, *str, &pat)) {
str++;
continue;
} else
return false;
else if (*pat == '\\')
pat++;
if (*str++ != *pat++)
return false;
}
if (*pat == '*') {
while (*pat == '*')
pat++;
if (!*pat)
return true;
while (*str)
if (__match_glob(str++, pat, ignore_space))
return true;
}
return !*str && !*pat;
}
bool strglobmatch(const char *str, const char *pat)
{
return __match_glob(str, pat, false);
}
bool strlazymatch(const char *str, const char *pat)
{
return __match_glob(str, pat, true);
}
int strtailcmp(const char *s1, const char *s2)
{
int i1 = strlen(s1);
int i2 = strlen(s2);
while (--i1 >= 0 && --i2 >= 0) {
if (s1[i1] != s2[i2])
return s1[i1] - s2[i2];
}
return 0;
}
char *strxfrchar(char *s, char from, char to)
{
char *p = s;
while ((p = strchr(p, from)) != NULL)
*p++ = to;
return s;
}
char *ltrim(char *s)
{
int len = strlen(s);
while (len && isspace(*s)) {
len--;
s++;
}
return s;
}
char *rtrim(char *s)
{
size_t size = strlen(s);
char *end;
if (!size)
return s;
end = s + size - 1;
while (end >= s && isspace(*end))
end--;
*(end + 1) = '\0';
return s;
}
char *asprintf_expr_inout_ints(const char *var, bool in, size_t nints, int *ints)
{
size_t size = nints * 28 + 1;
size_t i, printed = 0;
char *expr = malloc(size);
if (expr) {
const char *or_and = "||", *eq_neq = "==";
char *e = expr;
if (!in) {
or_and = "&&";
eq_neq = "!=";
}
for (i = 0; i < nints; ++i) {
if (printed == size)
goto out_err_overflow;
if (i > 0)
printed += snprintf(e + printed, size - printed, " %s ", or_and);
printed += scnprintf(e + printed, size - printed,
"%s %s %d", var, eq_neq, ints[i]);
}
}
return expr;
out_err_overflow:
free(expr);
return NULL;
}
