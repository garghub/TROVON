static int is_reserved_word(register const char *str, register unsigned int len)
{
int i;
for (i = 0; i < NR_KEYWORDS; i++) {
struct resword *r = keywords + i;
int l = strlen(r->name);
if (len == l && !memcmp(str, r->name, len))
return r->token;
}
return -1;
}
