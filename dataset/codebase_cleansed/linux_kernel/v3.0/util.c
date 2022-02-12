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
