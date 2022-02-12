static void usage(void)
{
fprintf(stderr, "Usage: fixdep [-e] <depfile> <target> <cmdline>\n");
fprintf(stderr, " -e insert extra dependencies given on stdin\n");
exit(1);
}
static void print_cmdline(void)
{
printf("cmd_%s := %s\n\n", target, cmdline);
}
static void print_config(const char *m, int slen)
{
int c, i;
printf(" $(wildcard include/config/");
for (i = 0; i < slen; i++) {
c = m[i];
if (c == '_')
c = '/';
else
c = tolower(c);
putchar(c);
}
printf(".h) \\\n");
}
static void do_extra_deps(void)
{
if (insert_extra_deps) {
char buf[80];
while(fgets(buf, sizeof(buf), stdin)) {
int len = strlen(buf);
if (len < 2 || buf[len-1] != '\n') {
fprintf(stderr, "fixdep: bad data on stdin\n");
exit(1);
}
print_config(buf, len-1);
}
}
}
static unsigned int strhash(const char *str, unsigned int sz)
{
unsigned int i, hash = 2166136261U;
for (i = 0; i < sz; i++)
hash = (hash ^ str[i]) * 0x01000193;
return hash;
}
static int is_defined_config(const char *name, int len, unsigned int hash)
{
struct item *aux;
for (aux = hashtab[hash % HASHSZ]; aux; aux = aux->next) {
if (aux->hash == hash && aux->len == len &&
memcmp(aux->name, name, len) == 0)
return 1;
}
return 0;
}
static void define_config(const char *name, int len, unsigned int hash)
{
struct item *aux = malloc(sizeof(*aux) + len);
if (!aux) {
perror("fixdep:malloc");
exit(1);
}
memcpy(aux->name, name, len);
aux->len = len;
aux->hash = hash;
aux->next = hashtab[hash % HASHSZ];
hashtab[hash % HASHSZ] = aux;
}
static void use_config(const char *m, int slen)
{
unsigned int hash = strhash(m, slen);
if (is_defined_config(m, slen, hash))
return;
define_config(m, slen, hash);
print_config(m, slen);
}
static void parse_config_file(const char *p)
{
const char *q, *r;
while ((p = strstr(p, "CONFIG_"))) {
p += 7;
q = p;
while (*q && (isalnum(*q) || *q == '_'))
q++;
if (memcmp(q - 7, "_MODULE", 7) == 0)
r = q - 7;
else
r = q;
if (r > p)
use_config(p, r - p);
p = q;
}
}
static int strrcmp(const char *s, const char *sub)
{
int slen = strlen(s);
int sublen = strlen(sub);
if (sublen > slen)
return 1;
return memcmp(s + slen - sublen, sub, sublen);
}
static void do_config_file(const char *filename)
{
struct stat st;
int fd;
char *map;
fd = open(filename, O_RDONLY);
if (fd < 0) {
fprintf(stderr, "fixdep: error opening config file: ");
perror(filename);
exit(2);
}
if (fstat(fd, &st) < 0) {
fprintf(stderr, "fixdep: error fstat'ing config file: ");
perror(filename);
exit(2);
}
if (st.st_size == 0) {
close(fd);
return;
}
map = malloc(st.st_size + 1);
if (!map) {
perror("fixdep: malloc");
close(fd);
return;
}
if (read(fd, map, st.st_size) != st.st_size) {
perror("fixdep: read");
close(fd);
return;
}
map[st.st_size] = '\0';
close(fd);
parse_config_file(map);
free(map);
}
static void parse_dep_file(void *map, size_t len)
{
char *m = map;
char *end = m + len;
char *p;
char s[PATH_MAX];
int is_target;
int saw_any_target = 0;
int is_first_dep = 0;
while (m < end) {
while (m < end && (*m == ' ' || *m == '\\' || *m == '\n'))
m++;
p = m;
while (p < end && *p != ' ' && *p != '\\' && *p != '\n')
p++;
is_target = (*(p-1) == ':');
if (is_target) {
is_first_dep = 1;
} else {
memcpy(s, m, p-m);
s[p - m] = 0;
if (strrcmp(s, "include/generated/autoconf.h") &&
strrcmp(s, "include/generated/autoksyms.h") &&
strrcmp(s, "arch/um/include/uml-config.h") &&
strrcmp(s, "include/linux/kconfig.h") &&
strrcmp(s, ".ver")) {
if (is_first_dep) {
if (!saw_any_target) {
saw_any_target = 1;
printf("source_%s := %s\n\n",
target, s);
printf("deps_%s := \\\n",
target);
}
is_first_dep = 0;
} else
printf(" %s \\\n", s);
do_config_file(s);
}
}
m = p + 1;
}
if (!saw_any_target) {
fprintf(stderr, "fixdep: parse error; no targets found\n");
exit(1);
}
do_extra_deps();
printf("\n%s: $(deps_%s)\n\n", target, target);
printf("$(deps_%s):\n", target);
}
static void print_deps(void)
{
struct stat st;
int fd;
void *map;
fd = open(depfile, O_RDONLY);
if (fd < 0) {
fprintf(stderr, "fixdep: error opening depfile: ");
perror(depfile);
exit(2);
}
if (fstat(fd, &st) < 0) {
fprintf(stderr, "fixdep: error fstat'ing depfile: ");
perror(depfile);
exit(2);
}
if (st.st_size == 0) {
fprintf(stderr,"fixdep: %s is empty\n",depfile);
close(fd);
return;
}
map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
if ((long) map == -1) {
perror("fixdep: mmap");
close(fd);
return;
}
parse_dep_file(map, st.st_size);
munmap(map, st.st_size);
close(fd);
}
int main(int argc, char *argv[])
{
if (argc == 5 && !strcmp(argv[1], "-e")) {
insert_extra_deps = 1;
argv++;
} else if (argc != 4)
usage();
depfile = argv[1];
target = argv[2];
cmdline = argv[3];
print_cmdline();
print_deps();
return 0;
}
