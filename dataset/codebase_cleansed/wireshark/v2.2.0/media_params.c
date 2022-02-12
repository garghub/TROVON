static const char *
ws_get_next_media_type_parameter(const char *pos, gsize *retnamelen,
const char **retvalue, gsize *retvaluelen,
const char **nextp)
{
const char *p, *namep, *valuep;
char c;
p = pos;
while ((c = *p) != '\0' && g_ascii_isspace(c))
p++;
if (c == '\0') {
return NULL;
}
namep = p;
while ((c = *p) != '\0' && c != '=' && c != ';')
p++;
*retnamelen = (gsize) (p - namep);
if (c == '\0') {
if (retvalue != NULL)
*retvalue = NULL;
if (retvaluelen != NULL)
*retvaluelen = 0;
*nextp = p;
return namep;
}
if (c == ';') {
if (retvalue != NULL)
*retvalue = NULL;
if (retvaluelen != NULL)
*retvaluelen = 0;
*nextp = p + 1;
return namep;
}
p++;
valuep = p;
if (retvalue != NULL)
*retvalue = valuep;
if (*p == '"') {
p++;
for (;;) {
c = *p;
if (c == '\0') {
if (retvaluelen != NULL) {
*retvaluelen = (gsize) (p - valuep);
}
*nextp = p;
return namep;
}
if (c == '"') {
p++;
break;
}
if (c == '\\') {
p++;
if (*p == '\0') {
break;
}
}
p++;
}
while ((c = *p) != '\0' && c != ';')
p++;
} else {
while ((c = *p) != '\0' && c != ';')
p++;
}
if (c == '\0') {
if (retvaluelen != NULL) {
*retvaluelen = (gsize) (p - valuep);
}
*nextp = p;
return namep;
}
if (retvaluelen != NULL) {
*retvaluelen = (gsize) (p - valuep);
}
*nextp = p + 1;
return namep;
}
char *
ws_find_media_type_parameter(const char *parameters, const char *key)
{
const char *p, *name, *value;
char c;
gsize keylen, namelen, valuelen;
char *valuestr, *vp;
if (parameters == NULL || key == NULL)
return NULL;
keylen = (gsize) strlen(key);
if (keylen == 0) {
return NULL;
}
p = parameters;
if (*p == '\0') {
return NULL;
}
do {
name = ws_get_next_media_type_parameter(p, &namelen, &value,
&valuelen, &p);
if (name == NULL) {
return NULL;
}
if (namelen == keylen && g_ascii_strncasecmp(name, key, keylen) == 0) {
break;
}
} while (*p);
if (value == NULL) {
return NULL;
}
valuestr = (char *)g_malloc(valuelen + 1);
vp = valuestr;
p = value;
if (*p == '"') {
p++;
for (;;) {
c = *p;
if (c == '\0') {
*vp = '\0';
return valuestr;
}
if (c == '"') {
p++;
break;
}
if (c == '\\') {
p++;
if (*p == '\0') {
break;
}
}
*vp++ = *p++;
}
} else {
while ((c = *p) != '\0' && g_ascii_isgraph(c) && c != '(' &&
c != ')' && c != '<' && c != '>' && c != '@' &&
c != ',' && c != ';' && c != ':' && c != '\\' &&
c != '"' && c != '/' && c != '[' && c != ']' &&
c != '?' && c != '=' && c != '{' && c != '}') {
*vp++ = c;
p++;
}
}
*vp = '\0';
return valuestr;
}
