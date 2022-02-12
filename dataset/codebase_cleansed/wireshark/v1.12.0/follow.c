static char *
sgetline(char *str, int *next)
{
char *end;
end = strstr(str, "\r\n");
if (!end) {
*next = (int)strlen(str);
return NULL;
}
*end = '\0';
*next = (int)(end-str+2);
return str;
}
gboolean
parse_http_header(char *data, size_t len, size_t *content_start)
{
char *tmp, *copy, *line;
size_t pos = 0;
int next_line;
gboolean is_gzipped;
tmp = copy = g_strndup(data, len);
if (!tmp) {
*content_start = 0;
return FALSE;
}
sgetline(tmp, &next_line);
tmp += next_line;
pos += next_line;
is_gzipped = FALSE;
*content_start = -1;
while ((line = sgetline(tmp, &next_line))) {
char *key, *val, *c;
tmp += next_line;
pos += next_line;
if (strlen(line) == 0) {
break;
}
c = strchr(line, ':');
if (!c) break;
key = line;
*c = '\0';
val = c+2;
if (!strcmp(key, "Content-Encoding") && strstr(val, "gzip")) {
is_gzipped = TRUE;
}
}
*content_start = pos;
g_free(copy);
return is_gzipped;
}
