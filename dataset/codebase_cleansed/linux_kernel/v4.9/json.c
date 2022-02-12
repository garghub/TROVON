static char *mapfile(const char *fn, size_t *size)
{
unsigned ps = sysconf(_SC_PAGESIZE);
struct stat st;
char *map = NULL;
int err;
int fd = open(fn, O_RDONLY);
if (fd < 0 && verbose && fn) {
pr_err("Error opening events file '%s': %s\n", fn,
strerror(errno));
}
if (fd < 0)
return NULL;
err = fstat(fd, &st);
if (err < 0)
goto out;
*size = st.st_size;
map = mmap(NULL,
(st.st_size + ps - 1) & ~(ps - 1),
PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
if (map == MAP_FAILED)
map = NULL;
out:
close(fd);
return map;
}
static void unmapfile(char *map, size_t size)
{
unsigned ps = sysconf(_SC_PAGESIZE);
munmap(map, roundup(size, ps));
}
jsmntok_t *parse_json(const char *fn, char **map, size_t *size, int *len)
{
jsmn_parser parser;
jsmntok_t *tokens;
jsmnerr_t res;
unsigned sz;
*map = mapfile(fn, size);
if (!*map)
return NULL;
sz = *size * 16;
tokens = malloc(sz);
if (!tokens)
goto error;
jsmn_init(&parser);
res = jsmn_parse(&parser, *map, *size, tokens,
sz / sizeof(jsmntok_t));
if (res != JSMN_SUCCESS) {
pr_err("%s: json error %s\n", fn, jsmn_strerror(res));
goto error_free;
}
if (len)
*len = parser.toknext;
return tokens;
error_free:
free(tokens);
error:
unmapfile(*map, *size);
return NULL;
}
void free_json(char *map, size_t size, jsmntok_t *tokens)
{
free(tokens);
unmapfile(map, size);
}
static int countchar(char *map, char c, int end)
{
int i;
int count = 0;
for (i = 0; i < end; i++)
if (map[i] == c)
count++;
return count;
}
int json_line(char *map, jsmntok_t *t)
{
return countchar(map, '\n', t->start) + 1;
}
const char *json_name(jsmntok_t *t)
{
return LOOKUP(jsmn_types, t->type);
}
int json_len(jsmntok_t *t)
{
return t->end - t->start;
}
int json_streq(char *map, jsmntok_t *t, const char *s)
{
unsigned len = json_len(t);
return len == strlen(s) && !strncasecmp(map + t->start, s, len);
}
