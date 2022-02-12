int
inet_aton(cp_arg, addr)
const char *cp_arg;
struct in_addr *addr;
{
register const u_char *cp = cp_arg;
register u_long val;
register int base;
register size_t n;
register u_char c;
u_int parts[4];
register u_int *pp = parts;
for (;;) {
val = 0; base = 10;
if (*cp == '0') {
if (*++cp == 'x' || *cp == 'X')
base = 16, cp++;
else
base = 8;
}
while ((c = *cp) != '\0') {
if (isascii(c) && isdigit(c)) {
val = (val * base) + (c - '0');
cp++;
continue;
}
if (base == 16 && isascii(c) && isxdigit(c)) {
val = (val << 4) +
(c + 10 - (islower(c) ? 'a' : 'A'));
cp++;
continue;
}
break;
}
if (*cp == '.') {
if (pp >= parts + 3 || val > 0xff)
return (0);
*pp++ = val, cp++;
} else
break;
}
if (*cp && (!isascii(*cp) || !isspace(*cp)))
return (0);
n = pp - parts + 1;
switch (n) {
case 1:
break;
case 2:
if (val > 0xffffff)
return (0);
val |= parts[0] << 24;
break;
case 3:
if (val > 0xffff)
return (0);
val |= (parts[0] << 24) | (parts[1] << 16);
break;
case 4:
if (val > 0xff)
return (0);
val |= (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8);
break;
}
if (addr)
addr->s_addr = htonl(val);
return (1);
}
