unsigned long
ucs2_strnlen(const ucs2_char_t *s, size_t maxlength)
{
unsigned long length = 0;
while (*s++ != 0 && length < maxlength)
length++;
return length;
}
unsigned long
ucs2_strlen(const ucs2_char_t *s)
{
return ucs2_strnlen(s, ~0UL);
}
unsigned long
ucs2_strsize(const ucs2_char_t *data, unsigned long maxlength)
{
return ucs2_strnlen(data, maxlength/sizeof(ucs2_char_t)) * sizeof(ucs2_char_t);
}
int
ucs2_strncmp(const ucs2_char_t *a, const ucs2_char_t *b, size_t len)
{
while (1) {
if (len == 0)
return 0;
if (*a < *b)
return -1;
if (*a > *b)
return 1;
if (*a == 0)
return 0;
a++;
b++;
len--;
}
}
