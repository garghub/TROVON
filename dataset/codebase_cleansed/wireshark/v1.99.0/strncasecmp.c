int
strncasecmp (const char *s1, const char *s2, size_t n)
{
register const unsigned char *p1 = (const unsigned char *) s1;
register const unsigned char *p2 = (const unsigned char *) s2;
unsigned char c1, c2;
if (p1 == p2 || n == 0)
return 0;
do
{
c1 = tolower (*p1++);
c2 = tolower (*p2++);
if (c1 == '\0' || c1 != c2)
return c1 - c2;
} while (--n > 0);
return c1 - c2;
}
