static char *get_dirname(const char *path)
{
const char *slash = strrchr(path, '/');
if (slash) {
int len = slash - path;
char *dir = xmalloc(len + 1);
memcpy(dir, path, len);
dir[len] = '\0';
return dir;
}
return NULL;
}
static char *try_open(const char *dirname, const char *fname, FILE **fp)
{
char *fullname;
if (!dirname || fname[0] == '/')
fullname = xstrdup(fname);
else
fullname = join_path(dirname, fname);
*fp = fopen(fullname, "rb");
if (!*fp) {
free(fullname);
fullname = NULL;
}
return fullname;
}
static char *fopen_any_on_path(const char *fname, FILE **fp)
{
const char *cur_dir = NULL;
struct search_path *node;
char *fullname;
assert(fp);
if (current_srcfile)
cur_dir = current_srcfile->dir;
fullname = try_open(cur_dir, fname, fp);
for (node = search_path_head; !*fp && node; node = node->next)
fullname = try_open(node->dirname, fname, fp);
return fullname;
}
FILE *srcfile_relative_open(const char *fname, char **fullnamep)
{
FILE *f;
char *fullname;
if (streq(fname, "-")) {
f = stdin;
fullname = xstrdup("<stdin>");
} else {
fullname = fopen_any_on_path(fname, &f);
if (!f)
die("Couldn't open \"%s\": %s\n", fname,
strerror(errno));
}
if (depfile)
fprintf(depfile, " %s", fullname);
if (fullnamep)
*fullnamep = fullname;
else
free(fullname);
return f;
}
void srcfile_push(const char *fname)
{
struct srcfile_state *srcfile;
if (srcfile_depth++ >= MAX_SRCFILE_DEPTH)
die("Includes nested too deeply");
srcfile = xmalloc(sizeof(*srcfile));
srcfile->f = srcfile_relative_open(fname, &srcfile->name);
srcfile->dir = get_dirname(srcfile->name);
srcfile->prev = current_srcfile;
srcfile->lineno = 1;
srcfile->colno = 1;
current_srcfile = srcfile;
}
bool srcfile_pop(void)
{
struct srcfile_state *srcfile = current_srcfile;
assert(srcfile);
current_srcfile = srcfile->prev;
if (fclose(srcfile->f))
die("Error closing \"%s\": %s\n", srcfile->name,
strerror(errno));
return current_srcfile ? true : false;
}
void srcfile_add_search_path(const char *dirname)
{
struct search_path *node;
node = xmalloc(sizeof(*node));
node->next = NULL;
node->dirname = xstrdup(dirname);
if (search_path_tail)
*search_path_tail = node;
else
search_path_head = node;
search_path_tail = &node->next;
}
void srcpos_update(struct srcpos *pos, const char *text, int len)
{
int i;
pos->file = current_srcfile;
pos->first_line = current_srcfile->lineno;
pos->first_column = current_srcfile->colno;
for (i = 0; i < len; i++)
if (text[i] == '\n') {
current_srcfile->lineno++;
current_srcfile->colno = 1;
} else if (text[i] == '\t') {
current_srcfile->colno =
ALIGN(current_srcfile->colno, TAB_SIZE);
} else {
current_srcfile->colno++;
}
pos->last_line = current_srcfile->lineno;
pos->last_column = current_srcfile->colno;
}
struct srcpos *
srcpos_copy(struct srcpos *pos)
{
struct srcpos *pos_new;
pos_new = xmalloc(sizeof(struct srcpos));
memcpy(pos_new, pos, sizeof(struct srcpos));
return pos_new;
}
void
srcpos_dump(struct srcpos *pos)
{
printf("file : \"%s\"\n",
pos->file ? (char *) pos->file : "<no file>");
printf("first_line : %d\n", pos->first_line);
printf("first_column: %d\n", pos->first_column);
printf("last_line : %d\n", pos->last_line);
printf("last_column : %d\n", pos->last_column);
printf("file : %s\n", pos->file->name);
}
char *
srcpos_string(struct srcpos *pos)
{
const char *fname = "<no-file>";
char *pos_str;
int rc;
if (pos)
fname = pos->file->name;
if (pos->first_line != pos->last_line)
rc = asprintf(&pos_str, "%s:%d.%d-%d.%d", fname,
pos->first_line, pos->first_column,
pos->last_line, pos->last_column);
else if (pos->first_column != pos->last_column)
rc = asprintf(&pos_str, "%s:%d.%d-%d", fname,
pos->first_line, pos->first_column,
pos->last_column);
else
rc = asprintf(&pos_str, "%s:%d.%d", fname,
pos->first_line, pos->first_column);
if (rc == -1)
die("Couldn't allocate in srcpos string");
return pos_str;
}
void srcpos_verror(struct srcpos *pos, const char *prefix,
const char *fmt, va_list va)
{
char *srcstr;
srcstr = srcpos_string(pos);
fprintf(stderr, "%s: %s ", prefix, srcstr);
vfprintf(stderr, fmt, va);
fprintf(stderr, "\n");
free(srcstr);
}
void srcpos_error(struct srcpos *pos, const char *prefix,
const char *fmt, ...)
{
va_list va;
va_start(va, fmt);
srcpos_verror(pos, prefix, fmt, va);
va_end(va);
}
void srcpos_set_line(char *f, int l)
{
current_srcfile->name = f;
current_srcfile->lineno = l;
}
