static int _kstrtoull(const char *s, unsigned int base, unsigned long long *res)
{
unsigned long long acc;
int ok;
if (base == 0) {
if (s[0] == '0') {
if (_tolower(s[1]) == 'x' && isxdigit(s[2]))
base = 16;
else
base = 8;
} else
base = 10;
}
if (base == 16 && s[0] == '0' && _tolower(s[1]) == 'x')
s += 2;
acc = 0;
ok = 0;
while (*s) {
unsigned int val;
if ('0' <= *s && *s <= '9')
val = *s - '0';
else if ('a' <= _tolower(*s) && _tolower(*s) <= 'f')
val = _tolower(*s) - 'a' + 10;
else if (*s == '\n' && *(s + 1) == '\0')
break;
else
return -EINVAL;
if (val >= base)
return -EINVAL;
if (acc > div_u64(ULLONG_MAX - val, base))
return -ERANGE;
acc = acc * base + val;
ok = 1;
s++;
}
if (!ok)
return -EINVAL;
*res = acc;
return 0;
}
int kstrtoull(const char *s, unsigned int base, unsigned long long *res)
{
if (s[0] == '+')
s++;
return _kstrtoull(s, base, res);
}
int kstrtoll(const char *s, unsigned int base, long long *res)
{
unsigned long long tmp;
int rv;
if (s[0] == '-') {
rv = _kstrtoull(s + 1, base, &tmp);
if (rv < 0)
return rv;
if ((long long)(-tmp) >= 0)
return -ERANGE;
*res = -tmp;
} else {
rv = kstrtoull(s, base, &tmp);
if (rv < 0)
return rv;
if ((long long)tmp < 0)
return -ERANGE;
*res = tmp;
}
return 0;
}
int _kstrtoul(const char *s, unsigned int base, unsigned long *res)
{
unsigned long long tmp;
int rv;
rv = kstrtoull(s, base, &tmp);
if (rv < 0)
return rv;
if (tmp != (unsigned long long)(unsigned long)tmp)
return -ERANGE;
*res = tmp;
return 0;
}
int _kstrtol(const char *s, unsigned int base, long *res)
{
long long tmp;
int rv;
rv = kstrtoll(s, base, &tmp);
if (rv < 0)
return rv;
if (tmp != (long long)(long)tmp)
return -ERANGE;
*res = tmp;
return 0;
}
int kstrtouint(const char *s, unsigned int base, unsigned int *res)
{
unsigned long long tmp;
int rv;
rv = kstrtoull(s, base, &tmp);
if (rv < 0)
return rv;
if (tmp != (unsigned long long)(unsigned int)tmp)
return -ERANGE;
*res = tmp;
return 0;
}
int kstrtoint(const char *s, unsigned int base, int *res)
{
long long tmp;
int rv;
rv = kstrtoll(s, base, &tmp);
if (rv < 0)
return rv;
if (tmp != (long long)(int)tmp)
return -ERANGE;
*res = tmp;
return 0;
}
int kstrtou16(const char *s, unsigned int base, u16 *res)
{
unsigned long long tmp;
int rv;
rv = kstrtoull(s, base, &tmp);
if (rv < 0)
return rv;
if (tmp != (unsigned long long)(u16)tmp)
return -ERANGE;
*res = tmp;
return 0;
}
int kstrtos16(const char *s, unsigned int base, s16 *res)
{
long long tmp;
int rv;
rv = kstrtoll(s, base, &tmp);
if (rv < 0)
return rv;
if (tmp != (long long)(s16)tmp)
return -ERANGE;
*res = tmp;
return 0;
}
int kstrtou8(const char *s, unsigned int base, u8 *res)
{
unsigned long long tmp;
int rv;
rv = kstrtoull(s, base, &tmp);
if (rv < 0)
return rv;
if (tmp != (unsigned long long)(u8)tmp)
return -ERANGE;
*res = tmp;
return 0;
}
int kstrtos8(const char *s, unsigned int base, s8 *res)
{
long long tmp;
int rv;
rv = kstrtoll(s, base, &tmp);
if (rv < 0)
return rv;
if (tmp != (long long)(s8)tmp)
return -ERANGE;
*res = tmp;
return 0;
}
