bool
rust_is_mangled(const char *sym)
{
size_t len, len_without_hash;
if (!sym)
return false;
len = strlen(sym);
if (len <= hash_prefix_len + hash_len)
return false;
len_without_hash = len - (hash_prefix_len + hash_len);
if (!is_prefixed_hash(sym + len_without_hash))
return false;
return looks_like_rust(sym, len_without_hash);
}
static bool is_prefixed_hash(const char *str)
{
const char *end;
bool seen[16];
size_t i;
int count;
if (strncmp(str, hash_prefix, hash_prefix_len))
return false;
str += hash_prefix_len;
memset(seen, false, sizeof(seen));
for (end = str + hash_len; str < end; str++)
if (*str >= '0' && *str <= '9')
seen[*str - '0'] = true;
else if (*str >= 'a' && *str <= 'f')
seen[*str - 'a' + 10] = true;
else
return false;
count = 0;
for (i = 0; i < 16; i++)
if (seen[i])
count++;
return count >= 5 && count <= 15;
}
static bool looks_like_rust(const char *str, size_t len)
{
const char *end = str + len;
while (str < end)
switch (*str) {
case '$':
if (!strncmp(str, "$C$", 3))
str += 3;
else if (!strncmp(str, "$SP$", 4)
|| !strncmp(str, "$BP$", 4)
|| !strncmp(str, "$RF$", 4)
|| !strncmp(str, "$LT$", 4)
|| !strncmp(str, "$GT$", 4)
|| !strncmp(str, "$LP$", 4)
|| !strncmp(str, "$RP$", 4))
str += 4;
else if (!strncmp(str, "$u20$", 5)
|| !strncmp(str, "$u27$", 5)
|| !strncmp(str, "$u5b$", 5)
|| !strncmp(str, "$u5d$", 5)
|| !strncmp(str, "$u7e$", 5))
str += 5;
else
return false;
break;
case '.':
if (!strncmp(str, "...", 3))
return false;
case 'a' ... 'z':
case 'A' ... 'Z':
case '0' ... '9':
case '_':
case ':':
str++;
break;
default:
return false;
}
return true;
}
void
rust_demangle_sym(char *sym)
{
const char *in;
char *out;
const char *end;
if (!sym)
return;
in = sym;
out = sym;
end = sym + strlen(sym) - (hash_prefix_len + hash_len);
while (in < end)
switch (*in) {
case '$':
if (!(unescape(&in, &out, "$C$", ',')
|| unescape(&in, &out, "$SP$", '@')
|| unescape(&in, &out, "$BP$", '*')
|| unescape(&in, &out, "$RF$", '&')
|| unescape(&in, &out, "$LT$", '<')
|| unescape(&in, &out, "$GT$", '>')
|| unescape(&in, &out, "$LP$", '(')
|| unescape(&in, &out, "$RP$", ')')
|| unescape(&in, &out, "$u20$", ' ')
|| unescape(&in, &out, "$u27$", '\'')
|| unescape(&in, &out, "$u5b$", '[')
|| unescape(&in, &out, "$u5d$", ']')
|| unescape(&in, &out, "$u7e$", '~'))) {
pr_err("demangle-rust: unexpected escape sequence");
goto done;
}
break;
case '_':
if ((in == sym || in[-1] == ':') && in[1] == '$')
in++;
else
*out++ = *in++;
break;
case '.':
if (in[1] == '.') {
*out++ = ':';
*out++ = ':';
in += 2;
} else {
*out++ = '-';
in++;
}
break;
case 'a' ... 'z':
case 'A' ... 'Z':
case '0' ... '9':
case ':':
*out++ = *in++;
break;
default:
pr_err("demangle-rust: unexpected character '%c' in symbol\n",
*in);
goto done;
}
done:
*out = '\0';
}
static bool unescape(const char **in, char **out, const char *seq, char value)
{
size_t len = strlen(seq);
if (strncmp(*in, seq, len))
return false;
**out = value;
*in += len;
*out += 1;
return true;
}
