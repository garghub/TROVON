static char *
__demangle_java_sym(const char *str, const char *end, char *buf, int maxlen, int mode)
{
int rlen = 0;
int array = 0;
int narg = 0;
const char *q;
if (!end)
end = str + strlen(str);
for (q = str; q != end; q++) {
if (rlen == (maxlen - 1))
break;
switch (*q) {
case 'L':
if (mode == MODE_PREFIX || mode == MODE_CTYPE) {
if (mode == MODE_CTYPE) {
if (narg)
rlen += scnprintf(buf + rlen, maxlen - rlen, ", ");
narg++;
}
rlen += scnprintf(buf + rlen, maxlen - rlen, "class ");
if (mode == MODE_PREFIX)
mode = MODE_CLASS;
} else
buf[rlen++] = *q;
break;
case 'B':
case 'C':
case 'D':
case 'F':
case 'I':
case 'J':
case 'S':
case 'Z':
if (mode == MODE_TYPE) {
if (narg)
rlen += scnprintf(buf + rlen, maxlen - rlen, ", ");
rlen += scnprintf(buf + rlen, maxlen - rlen, "%s", base_types[*q - 'A']);
while (array--)
rlen += scnprintf(buf + rlen, maxlen - rlen, "[]");
array = 0;
narg++;
} else
buf[rlen++] = *q;
break;
case 'V':
if (mode == MODE_TYPE) {
rlen += scnprintf(buf + rlen, maxlen - rlen, "void");
while (array--)
rlen += scnprintf(buf + rlen, maxlen - rlen, "[]");
array = 0;
} else
buf[rlen++] = *q;
break;
case '[':
if (mode != MODE_TYPE)
goto error;
array++;
break;
case '(':
if (mode != MODE_FUNC)
goto error;
buf[rlen++] = *q;
mode = MODE_TYPE;
break;
case ')':
if (mode != MODE_TYPE)
goto error;
buf[rlen++] = *q;
narg = 0;
break;
case ';':
if (mode != MODE_CLASS && mode != MODE_CTYPE)
goto error;
if (isalpha(*(q + 1)))
rlen += scnprintf(buf + rlen, maxlen - rlen, ".");
if (mode == MODE_CLASS)
mode = MODE_FUNC;
else if (mode == MODE_CTYPE)
mode = MODE_TYPE;
break;
case '/':
if (mode != MODE_CLASS && mode != MODE_CTYPE)
goto error;
rlen += scnprintf(buf + rlen, maxlen - rlen, ".");
break;
default :
buf[rlen++] = *q;
}
}
buf[rlen] = '\0';
return buf;
error:
return NULL;
}
char *
java_demangle_sym(const char *str, int flags)
{
char *buf, *ptr;
char *p;
size_t len, l1 = 0;
if (!str)
return NULL;
p = strrchr(str, ')');
if (!p)
return NULL;
len = strlen(str) * 3 + 1;
buf = malloc(len);
if (!buf)
return NULL;
buf[0] = '\0';
if (!(flags & JAVA_DEMANGLE_NORET)) {
ptr = __demangle_java_sym(p + 1, NULL, buf, len, MODE_TYPE);
if (!ptr)
goto error;
l1 = strlen(buf);
buf[l1++] = ' ';
}
ptr = __demangle_java_sym(str, p + 1, buf + l1, len - l1, MODE_PREFIX);
if (!ptr)
goto error;
return buf;
error:
free(buf);
return NULL;
}
