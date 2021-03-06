static void ins__delete(struct ins_operands *ops)
{
free(ops->source.raw);
free(ops->source.name);
free(ops->target.raw);
free(ops->target.name);
}
static int ins__raw_scnprintf(struct ins *ins, char *bf, size_t size,
struct ins_operands *ops)
{
return scnprintf(bf, size, "%-6.6s %s", ins->name, ops->raw);
}
int ins__scnprintf(struct ins *ins, char *bf, size_t size,
struct ins_operands *ops)
{
if (ins->ops->scnprintf)
return ins->ops->scnprintf(ins, bf, size, ops);
return ins__raw_scnprintf(ins, bf, size, ops);
}
static int call__parse(struct ins_operands *ops)
{
char *endptr, *tok, *name;
ops->target.addr = strtoull(ops->raw, &endptr, 16);
name = strchr(endptr, '<');
if (name == NULL)
goto indirect_call;
name++;
tok = strchr(name, '>');
if (tok == NULL)
return -1;
*tok = '\0';
ops->target.name = strdup(name);
*tok = '>';
return ops->target.name == NULL ? -1 : 0;
indirect_call:
tok = strchr(endptr, '(');
if (tok != NULL) {
ops->target.addr = 0;
return 0;
}
tok = strchr(endptr, '*');
if (tok == NULL)
return -1;
ops->target.addr = strtoull(tok + 1, NULL, 16);
return 0;
}
static int call__scnprintf(struct ins *ins, char *bf, size_t size,
struct ins_operands *ops)
{
if (ops->target.name)
return scnprintf(bf, size, "%-6.6s %s", ins->name, ops->target.name);
if (ops->target.addr == 0)
return ins__raw_scnprintf(ins, bf, size, ops);
return scnprintf(bf, size, "%-6.6s *%" PRIx64, ins->name, ops->target.addr);
}
bool ins__is_call(const struct ins *ins)
{
return ins->ops == &call_ops;
}
static int jump__parse(struct ins_operands *ops)
{
const char *s = strchr(ops->raw, '+');
ops->target.addr = strtoll(ops->raw, NULL, 16);
if (s++ != NULL)
ops->target.offset = strtoll(s, NULL, 16);
else
ops->target.offset = UINT64_MAX;
return 0;
}
static int jump__scnprintf(struct ins *ins, char *bf, size_t size,
struct ins_operands *ops)
{
return scnprintf(bf, size, "%-6.6s %" PRIx64, ins->name, ops->target.offset);
}
bool ins__is_jump(const struct ins *ins)
{
return ins->ops == &jump_ops;
}
static int comment__symbol(char *raw, char *comment, u64 *addrp, char **namep)
{
char *endptr, *name, *t;
if (strstr(raw, "(%rip)") == NULL)
return 0;
*addrp = strtoull(comment, &endptr, 16);
name = strchr(endptr, '<');
if (name == NULL)
return -1;
name++;
t = strchr(name, '>');
if (t == NULL)
return 0;
*t = '\0';
*namep = strdup(name);
*t = '>';
return 0;
}
static int lock__parse(struct ins_operands *ops)
{
char *name;
ops->locked.ops = zalloc(sizeof(*ops->locked.ops));
if (ops->locked.ops == NULL)
return 0;
if (disasm_line__parse(ops->raw, &name, &ops->locked.ops->raw) < 0)
goto out_free_ops;
ops->locked.ins = ins__find(name);
if (ops->locked.ins == NULL)
goto out_free_ops;
if (!ops->locked.ins->ops)
return 0;
if (ops->locked.ins->ops->parse)
ops->locked.ins->ops->parse(ops->locked.ops);
return 0;
out_free_ops:
free(ops->locked.ops);
ops->locked.ops = NULL;
return 0;
}
static int lock__scnprintf(struct ins *ins, char *bf, size_t size,
struct ins_operands *ops)
{
int printed;
if (ops->locked.ins == NULL)
return ins__raw_scnprintf(ins, bf, size, ops);
printed = scnprintf(bf, size, "%-6.6s ", ins->name);
return printed + ins__scnprintf(ops->locked.ins, bf + printed,
size - printed, ops->locked.ops);
}
static void lock__delete(struct ins_operands *ops)
{
free(ops->locked.ops);
free(ops->target.raw);
free(ops->target.name);
}
static int mov__parse(struct ins_operands *ops)
{
char *s = strchr(ops->raw, ','), *target, *comment, prev;
if (s == NULL)
return -1;
*s = '\0';
ops->source.raw = strdup(ops->raw);
*s = ',';
if (ops->source.raw == NULL)
return -1;
target = ++s;
while (s[0] != '\0' && !isspace(s[0]))
++s;
prev = *s;
*s = '\0';
ops->target.raw = strdup(target);
*s = prev;
if (ops->target.raw == NULL)
goto out_free_source;
comment = strchr(s, '#');
if (comment == NULL)
return 0;
while (comment[0] != '\0' && isspace(comment[0]))
++comment;
comment__symbol(ops->source.raw, comment, &ops->source.addr, &ops->source.name);
comment__symbol(ops->target.raw, comment, &ops->target.addr, &ops->target.name);
return 0;
out_free_source:
free(ops->source.raw);
ops->source.raw = NULL;
return -1;
}
static int mov__scnprintf(struct ins *ins, char *bf, size_t size,
struct ins_operands *ops)
{
return scnprintf(bf, size, "%-6.6s %s,%s", ins->name,
ops->source.name ?: ops->source.raw,
ops->target.name ?: ops->target.raw);
}
static int dec__parse(struct ins_operands *ops)
{
char *target, *comment, *s, prev;
target = s = ops->raw;
while (s[0] != '\0' && !isspace(s[0]))
++s;
prev = *s;
*s = '\0';
ops->target.raw = strdup(target);
*s = prev;
if (ops->target.raw == NULL)
return -1;
comment = strchr(s, '#');
if (comment == NULL)
return 0;
while (comment[0] != '\0' && isspace(comment[0]))
++comment;
comment__symbol(ops->target.raw, comment, &ops->target.addr, &ops->target.name);
return 0;
}
static int dec__scnprintf(struct ins *ins, char *bf, size_t size,
struct ins_operands *ops)
{
return scnprintf(bf, size, "%-6.6s %s", ins->name,
ops->target.name ?: ops->target.raw);
}
static int nop__scnprintf(struct ins *ins __maybe_unused, char *bf, size_t size,
struct ins_operands *ops __maybe_unused)
{
return scnprintf(bf, size, "%-6.6s", "nop");
}
static int ins__cmp(const void *name, const void *insp)
{
const struct ins *ins = insp;
return strcmp(name, ins->name);
}
static struct ins *ins__find(const char *name)
{
const int nmemb = ARRAY_SIZE(instructions);
return bsearch(name, instructions, nmemb, sizeof(struct ins), ins__cmp);
}
int symbol__annotate_init(struct map *map __maybe_unused, struct symbol *sym)
{
struct annotation *notes = symbol__annotation(sym);
pthread_mutex_init(&notes->lock, NULL);
return 0;
}
int symbol__alloc_hist(struct symbol *sym)
{
struct annotation *notes = symbol__annotation(sym);
const size_t size = symbol__size(sym);
size_t sizeof_sym_hist;
if (size > (SIZE_MAX - sizeof(struct sym_hist)) / sizeof(u64))
return -1;
sizeof_sym_hist = (sizeof(struct sym_hist) + size * sizeof(u64));
if (sizeof_sym_hist > (SIZE_MAX - sizeof(*notes->src))
/ symbol_conf.nr_events)
return -1;
notes->src = zalloc(sizeof(*notes->src) + symbol_conf.nr_events * sizeof_sym_hist);
if (notes->src == NULL)
return -1;
notes->src->sizeof_sym_hist = sizeof_sym_hist;
notes->src->nr_histograms = symbol_conf.nr_events;
INIT_LIST_HEAD(&notes->src->source);
return 0;
}
void symbol__annotate_zero_histograms(struct symbol *sym)
{
struct annotation *notes = symbol__annotation(sym);
pthread_mutex_lock(&notes->lock);
if (notes->src != NULL)
memset(notes->src->histograms, 0,
notes->src->nr_histograms * notes->src->sizeof_sym_hist);
pthread_mutex_unlock(&notes->lock);
}
int symbol__inc_addr_samples(struct symbol *sym, struct map *map,
int evidx, u64 addr)
{
unsigned offset;
struct annotation *notes;
struct sym_hist *h;
notes = symbol__annotation(sym);
if (notes->src == NULL)
return -ENOMEM;
pr_debug3("%s: addr=%#" PRIx64 "\n", __func__, map->unmap_ip(map, addr));
if (addr < sym->start || addr > sym->end)
return -ERANGE;
offset = addr - sym->start;
h = annotation__histogram(notes, evidx);
h->sum++;
h->addr[offset]++;
pr_debug3("%#" PRIx64 " %s: period++ [addr: %#" PRIx64 ", %#" PRIx64
", evidx=%d] => %" PRIu64 "\n", sym->start, sym->name,
addr, addr - sym->start, evidx, h->addr[offset]);
return 0;
}
static void disasm_line__init_ins(struct disasm_line *dl)
{
dl->ins = ins__find(dl->name);
if (dl->ins == NULL)
return;
if (!dl->ins->ops)
return;
if (dl->ins->ops->parse)
dl->ins->ops->parse(&dl->ops);
}
static int disasm_line__parse(char *line, char **namep, char **rawp)
{
char *name = line, tmp;
while (isspace(name[0]))
++name;
if (name[0] == '\0')
return -1;
*rawp = name + 1;
while ((*rawp)[0] != '\0' && !isspace((*rawp)[0]))
++*rawp;
tmp = (*rawp)[0];
(*rawp)[0] = '\0';
*namep = strdup(name);
if (*namep == NULL)
goto out_free_name;
(*rawp)[0] = tmp;
if ((*rawp)[0] != '\0') {
(*rawp)++;
while (isspace((*rawp)[0]))
++(*rawp);
}
return 0;
out_free_name:
free(*namep);
*namep = NULL;
return -1;
}
static struct disasm_line *disasm_line__new(s64 offset, char *line, size_t privsize)
{
struct disasm_line *dl = zalloc(sizeof(*dl) + privsize);
if (dl != NULL) {
dl->offset = offset;
dl->line = strdup(line);
if (dl->line == NULL)
goto out_delete;
if (offset != -1) {
if (disasm_line__parse(dl->line, &dl->name, &dl->ops.raw) < 0)
goto out_free_line;
disasm_line__init_ins(dl);
}
}
return dl;
out_free_line:
free(dl->line);
out_delete:
free(dl);
return NULL;
}
void disasm_line__free(struct disasm_line *dl)
{
free(dl->line);
free(dl->name);
if (dl->ins && dl->ins->ops->free)
dl->ins->ops->free(&dl->ops);
else
ins__delete(&dl->ops);
free(dl);
}
int disasm_line__scnprintf(struct disasm_line *dl, char *bf, size_t size, bool raw)
{
if (raw || !dl->ins)
return scnprintf(bf, size, "%-6.6s %s", dl->name, dl->ops.raw);
return ins__scnprintf(dl->ins, bf, size, &dl->ops);
}
static void disasm__add(struct list_head *head, struct disasm_line *line)
{
list_add_tail(&line->node, head);
}
struct disasm_line *disasm__get_next_ip_line(struct list_head *head, struct disasm_line *pos)
{
list_for_each_entry_continue(pos, head, node)
if (pos->offset >= 0)
return pos;
return NULL;
}
static int disasm_line__print(struct disasm_line *dl, struct symbol *sym, u64 start,
int evidx, u64 len, int min_pcnt, int printed,
int max_lines, struct disasm_line *queue)
{
static const char *prev_line;
static const char *prev_color;
if (dl->offset != -1) {
const char *path = NULL;
unsigned int hits = 0;
double percent = 0.0;
const char *color;
struct annotation *notes = symbol__annotation(sym);
struct source_line *src_line = notes->src->lines;
struct sym_hist *h = annotation__histogram(notes, evidx);
s64 offset = dl->offset;
const u64 addr = start + offset;
struct disasm_line *next;
next = disasm__get_next_ip_line(&notes->src->source, dl);
while (offset < (s64)len &&
(next == NULL || offset < next->offset)) {
if (src_line) {
if (path == NULL)
path = src_line[offset].path;
percent += src_line[offset].percent;
} else
hits += h->addr[offset];
++offset;
}
if (src_line == NULL && h->sum)
percent = 100.0 * hits / h->sum;
if (percent < min_pcnt)
return -1;
if (max_lines && printed >= max_lines)
return 1;
if (queue != NULL) {
list_for_each_entry_from(queue, &notes->src->source, node) {
if (queue == dl)
break;
disasm_line__print(queue, sym, start, evidx, len,
0, 0, 1, NULL);
}
}
color = get_percent_color(percent);
if (path) {
if (!prev_line || strcmp(prev_line, path)
|| color != prev_color) {
color_fprintf(stdout, color, " %s", path);
prev_line = path;
prev_color = color;
}
}
color_fprintf(stdout, color, " %7.2f", percent);
printf(" : ");
color_fprintf(stdout, PERF_COLOR_MAGENTA, " %" PRIx64 ":", addr);
color_fprintf(stdout, PERF_COLOR_BLUE, "%s\n", dl->line);
} else if (max_lines && printed >= max_lines)
return 1;
else {
if (queue)
return -1;
if (!*dl->line)
printf(" :\n");
else
printf(" : %s\n", dl->line);
}
return 0;
}
static int symbol__parse_objdump_line(struct symbol *sym, struct map *map,
FILE *file, size_t privsize)
{
struct annotation *notes = symbol__annotation(sym);
struct disasm_line *dl;
char *line = NULL, *parsed_line, *tmp, *tmp2, *c;
size_t line_len;
s64 line_ip, offset = -1;
if (getline(&line, &line_len, file) < 0)
return -1;
if (!line)
return -1;
while (line_len != 0 && isspace(line[line_len - 1]))
line[--line_len] = '\0';
c = strchr(line, '\n');
if (c)
*c = 0;
line_ip = -1;
parsed_line = line;
tmp = line;
while (*tmp) {
if (*tmp != ' ')
break;
tmp++;
}
if (*tmp) {
line_ip = strtoull(tmp, &tmp2, 16);
if (*tmp2 != ':' || tmp == tmp2 || tmp2[1] == '\0')
line_ip = -1;
}
if (line_ip != -1) {
u64 start = map__rip_2objdump(map, sym->start),
end = map__rip_2objdump(map, sym->end);
offset = line_ip - start;
if (offset < 0 || (u64)line_ip > end)
offset = -1;
else
parsed_line = tmp2 + 1;
}
dl = disasm_line__new(offset, parsed_line, privsize);
free(line);
if (dl == NULL)
return -1;
disasm__add(&notes->src->source, dl);
return 0;
}
int symbol__annotate(struct symbol *sym, struct map *map, size_t privsize)
{
struct dso *dso = map->dso;
char *filename = dso__build_id_filename(dso, NULL, 0);
bool free_filename = true;
char command[PATH_MAX * 2];
FILE *file;
int err = 0;
char symfs_filename[PATH_MAX];
if (filename) {
snprintf(symfs_filename, sizeof(symfs_filename), "%s%s",
symbol_conf.symfs, filename);
}
if (filename == NULL) {
if (dso->has_build_id) {
pr_err("Can't annotate %s: not enough memory\n",
sym->name);
return -ENOMEM;
}
goto fallback;
} else if (readlink(symfs_filename, command, sizeof(command)) < 0 ||
strstr(command, "[kernel.kallsyms]") ||
access(symfs_filename, R_OK)) {
free(filename);
fallback:
filename = dso->long_name;
snprintf(symfs_filename, sizeof(symfs_filename), "%s%s",
symbol_conf.symfs, filename);
free_filename = false;
}
if (dso->symtab_type == DSO_BINARY_TYPE__KALLSYMS) {
char bf[BUILD_ID_SIZE * 2 + 16] = " with build id ";
char *build_id_msg = NULL;
if (dso->annotate_warned)
goto out_free_filename;
if (dso->has_build_id) {
build_id__sprintf(dso->build_id,
sizeof(dso->build_id), bf + 15);
build_id_msg = bf;
}
err = -ENOENT;
dso->annotate_warned = 1;
pr_err("Can't annotate %s:\n\n"
"No vmlinux file%s\nwas found in the path.\n\n"
"Please use:\n\n"
" perf buildid-cache -av vmlinux\n\n"
"or:\n\n"
" --vmlinux vmlinux\n",
sym->name, build_id_msg ?: "");
goto out_free_filename;
}
pr_debug("%s: filename=%s, sym=%s, start=%#" PRIx64 ", end=%#" PRIx64 "\n", __func__,
filename, sym->name, map->unmap_ip(map, sym->start),
map->unmap_ip(map, sym->end));
pr_debug("annotating [%p] %30s : [%p] %30s\n",
dso, dso->long_name, sym, sym->name);
snprintf(command, sizeof(command),
"%s %s%s --start-address=0x%016" PRIx64
" --stop-address=0x%016" PRIx64
" -d %s %s -C %s|grep -v %s|expand",
objdump_path ? objdump_path : "objdump",
disassembler_style ? "-M " : "",
disassembler_style ? disassembler_style : "",
map__rip_2objdump(map, sym->start),
map__rip_2objdump(map, sym->end+1),
symbol_conf.annotate_asm_raw ? "" : "--no-show-raw",
symbol_conf.annotate_src ? "-S" : "",
symfs_filename, filename);
pr_debug("Executing: %s\n", command);
file = popen(command, "r");
if (!file)
goto out_free_filename;
while (!feof(file))
if (symbol__parse_objdump_line(sym, map, file, privsize) < 0)
break;
pclose(file);
out_free_filename:
if (free_filename)
free(filename);
return err;
}
static void insert_source_line(struct rb_root *root, struct source_line *src_line)
{
struct source_line *iter;
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
int ret;
while (*p != NULL) {
parent = *p;
iter = rb_entry(parent, struct source_line, node);
ret = strcmp(iter->path, src_line->path);
if (ret == 0) {
iter->percent_sum += src_line->percent;
return;
}
if (ret < 0)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
}
src_line->percent_sum = src_line->percent;
rb_link_node(&src_line->node, parent, p);
rb_insert_color(&src_line->node, root);
}
static void __resort_source_line(struct rb_root *root, struct source_line *src_line)
{
struct source_line *iter;
struct rb_node **p = &root->rb_node;
struct rb_node *parent = NULL;
while (*p != NULL) {
parent = *p;
iter = rb_entry(parent, struct source_line, node);
if (src_line->percent_sum > iter->percent_sum)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
}
rb_link_node(&src_line->node, parent, p);
rb_insert_color(&src_line->node, root);
}
static void resort_source_line(struct rb_root *dest_root, struct rb_root *src_root)
{
struct source_line *src_line;
struct rb_node *node;
node = rb_first(src_root);
while (node) {
struct rb_node *next;
src_line = rb_entry(node, struct source_line, node);
next = rb_next(node);
rb_erase(node, src_root);
__resort_source_line(dest_root, src_line);
node = next;
}
}
static void symbol__free_source_line(struct symbol *sym, int len)
{
struct annotation *notes = symbol__annotation(sym);
struct source_line *src_line = notes->src->lines;
int i;
for (i = 0; i < len; i++)
free(src_line[i].path);
free(src_line);
notes->src->lines = NULL;
}
static int symbol__get_source_line(struct symbol *sym, struct map *map,
int evidx, struct rb_root *root, int len,
const char *filename)
{
u64 start;
int i;
char cmd[PATH_MAX * 2];
struct source_line *src_line;
struct annotation *notes = symbol__annotation(sym);
struct sym_hist *h = annotation__histogram(notes, evidx);
struct rb_root tmp_root = RB_ROOT;
if (!h->sum)
return 0;
src_line = notes->src->lines = calloc(len, sizeof(struct source_line));
if (!notes->src->lines)
return -1;
start = map__rip_2objdump(map, sym->start);
for (i = 0; i < len; i++) {
char *path = NULL;
size_t line_len;
u64 offset;
FILE *fp;
src_line[i].percent = 100.0 * h->addr[i] / h->sum;
if (src_line[i].percent <= 0.5)
continue;
offset = start + i;
sprintf(cmd, "addr2line -e %s %016" PRIx64, filename, offset);
fp = popen(cmd, "r");
if (!fp)
continue;
if (getline(&path, &line_len, fp) < 0 || !line_len)
goto next;
src_line[i].path = malloc(sizeof(char) * line_len + 1);
if (!src_line[i].path)
goto next;
strcpy(src_line[i].path, path);
insert_source_line(&tmp_root, &src_line[i]);
next:
pclose(fp);
}
resort_source_line(root, &tmp_root);
return 0;
}
static void print_summary(struct rb_root *root, const char *filename)
{
struct source_line *src_line;
struct rb_node *node;
printf("\nSorted summary for file %s\n", filename);
printf("----------------------------------------------\n\n");
if (RB_EMPTY_ROOT(root)) {
printf(" Nothing higher than %1.1f%%\n", MIN_GREEN);
return;
}
node = rb_first(root);
while (node) {
double percent;
const char *color;
char *path;
src_line = rb_entry(node, struct source_line, node);
percent = src_line->percent_sum;
color = get_percent_color(percent);
path = src_line->path;
color_fprintf(stdout, color, " %7.2f %s", percent, path);
node = rb_next(node);
}
}
static void symbol__annotate_hits(struct symbol *sym, int evidx)
{
struct annotation *notes = symbol__annotation(sym);
struct sym_hist *h = annotation__histogram(notes, evidx);
u64 len = symbol__size(sym), offset;
for (offset = 0; offset < len; ++offset)
if (h->addr[offset] != 0)
printf("%*" PRIx64 ": %" PRIu64 "\n", BITS_PER_LONG / 2,
sym->start + offset, h->addr[offset]);
printf("%*s: %" PRIu64 "\n", BITS_PER_LONG / 2, "h->sum", h->sum);
}
int symbol__annotate_printf(struct symbol *sym, struct map *map, int evidx,
bool full_paths, int min_pcnt, int max_lines,
int context)
{
struct dso *dso = map->dso;
char *filename;
const char *d_filename;
struct annotation *notes = symbol__annotation(sym);
struct disasm_line *pos, *queue = NULL;
u64 start = map__rip_2objdump(map, sym->start);
int printed = 2, queue_len = 0;
int more = 0;
u64 len;
filename = strdup(dso->long_name);
if (!filename)
return -ENOMEM;
if (full_paths)
d_filename = filename;
else
d_filename = basename(filename);
len = symbol__size(sym);
printf(" Percent | Source code & Disassembly of %s\n", d_filename);
printf("------------------------------------------------\n");
if (verbose)
symbol__annotate_hits(sym, evidx);
list_for_each_entry(pos, &notes->src->source, node) {
if (context && queue == NULL) {
queue = pos;
queue_len = 0;
}
switch (disasm_line__print(pos, sym, start, evidx, len,
min_pcnt, printed, max_lines,
queue)) {
case 0:
++printed;
if (context) {
printed += queue_len;
queue = NULL;
queue_len = 0;
}
break;
case 1:
++more;
break;
case -1:
default:
if (!context)
break;
if (queue_len == context)
queue = list_entry(queue->node.next, typeof(*queue), node);
else
++queue_len;
break;
}
}
free(filename);
return more;
}
void symbol__annotate_zero_histogram(struct symbol *sym, int evidx)
{
struct annotation *notes = symbol__annotation(sym);
struct sym_hist *h = annotation__histogram(notes, evidx);
memset(h, 0, notes->src->sizeof_sym_hist);
}
void symbol__annotate_decay_histogram(struct symbol *sym, int evidx)
{
struct annotation *notes = symbol__annotation(sym);
struct sym_hist *h = annotation__histogram(notes, evidx);
int len = symbol__size(sym), offset;
h->sum = 0;
for (offset = 0; offset < len; ++offset) {
h->addr[offset] = h->addr[offset] * 7 / 8;
h->sum += h->addr[offset];
}
}
void disasm__purge(struct list_head *head)
{
struct disasm_line *pos, *n;
list_for_each_entry_safe(pos, n, head, node) {
list_del(&pos->node);
disasm_line__free(pos);
}
}
static size_t disasm_line__fprintf(struct disasm_line *dl, FILE *fp)
{
size_t printed;
if (dl->offset == -1)
return fprintf(fp, "%s\n", dl->line);
printed = fprintf(fp, "%#" PRIx64 " %s", dl->offset, dl->name);
if (dl->ops.raw[0] != '\0') {
printed += fprintf(fp, "%.*s %s\n", 6 - (int)printed, " ",
dl->ops.raw);
}
return printed + fprintf(fp, "\n");
}
size_t disasm__fprintf(struct list_head *head, FILE *fp)
{
struct disasm_line *pos;
size_t printed = 0;
list_for_each_entry(pos, head, node)
printed += disasm_line__fprintf(pos, fp);
return printed;
}
int symbol__tty_annotate(struct symbol *sym, struct map *map, int evidx,
bool print_lines, bool full_paths, int min_pcnt,
int max_lines)
{
struct dso *dso = map->dso;
const char *filename = dso->long_name;
struct rb_root source_line = RB_ROOT;
u64 len;
if (symbol__annotate(sym, map, 0) < 0)
return -1;
len = symbol__size(sym);
if (print_lines) {
symbol__get_source_line(sym, map, evidx, &source_line,
len, filename);
print_summary(&source_line, filename);
}
symbol__annotate_printf(sym, map, evidx, full_paths,
min_pcnt, max_lines, 0);
if (print_lines)
symbol__free_source_line(sym, len);
disasm__purge(&symbol__annotation(sym)->src->source);
return 0;
}
