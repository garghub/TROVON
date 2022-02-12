static void usage(void)
{
fprintf(stderr, "Usage: kallsyms [--all-symbols] "
"[--symbol-prefix=<prefix char>] "
"[--base-relative] < in.map > out.S\n");
exit(1);
}
static inline int is_arm_mapping_symbol(const char *str)
{
return str[0] == '$' && strchr("axtd", str[1])
&& (str[2] == '\0' || str[2] == '.');
}
static int check_symbol_range(const char *sym, unsigned long long addr,
struct addr_range *ranges, int entries)
{
size_t i;
struct addr_range *ar;
for (i = 0; i < entries; ++i) {
ar = &ranges[i];
if (strcmp(sym, ar->start_sym) == 0) {
ar->start = addr;
return 0;
} else if (strcmp(sym, ar->end_sym) == 0) {
ar->end = addr;
return 0;
}
}
return 1;
}
static int read_symbol(FILE *in, struct sym_entry *s)
{
char str[500];
char *sym, stype;
int rc;
rc = fscanf(in, "%llx %c %499s\n", &s->addr, &stype, str);
if (rc != 3) {
if (rc != EOF && fgets(str, 500, in) == NULL)
fprintf(stderr, "Read error or end of file.\n");
return -1;
}
if (strlen(str) > KSYM_NAME_LEN) {
fprintf(stderr, "Symbol %s too long for kallsyms (%zu vs %d).\n"
"Please increase KSYM_NAME_LEN both in kernel and kallsyms.c\n",
str, strlen(str), KSYM_NAME_LEN);
return -1;
}
sym = str;
if (symbol_prefix_char && str[0] == symbol_prefix_char)
sym++;
if (strcmp(sym, "_text") == 0)
_text = s->addr;
else if (check_symbol_range(sym, s->addr, text_ranges,
ARRAY_SIZE(text_ranges)) == 0)
;
else if (toupper(stype) == 'A')
{
if (strcmp(sym, "__kernel_syscall_via_break") &&
strcmp(sym, "__kernel_syscall_via_epc") &&
strcmp(sym, "__kernel_sigtramp") &&
strcmp(sym, "__gp"))
return -1;
}
else if (toupper(stype) == 'U' ||
is_arm_mapping_symbol(sym))
return -1;
else if (str[0] == '$')
return -1;
else if (stype == 'N')
return -1;
s->len = strlen(str) + 1;
s->sym = malloc(s->len + 1);
if (!s->sym) {
fprintf(stderr, "kallsyms failure: "
"unable to allocate required amount of memory\n");
exit(EXIT_FAILURE);
}
strcpy((char *)s->sym + 1, str);
s->sym[0] = stype;
s->percpu_absolute = 0;
check_symbol_range(sym, s->addr, &percpu_range, 1);
return 0;
}
static int symbol_in_range(struct sym_entry *s, struct addr_range *ranges,
int entries)
{
size_t i;
struct addr_range *ar;
for (i = 0; i < entries; ++i) {
ar = &ranges[i];
if (s->addr >= ar->start && s->addr <= ar->end)
return 1;
}
return 0;
}
static int symbol_valid(struct sym_entry *s)
{
static char *special_symbols[] = {
"kallsyms_addresses",
"kallsyms_offsets",
"kallsyms_relative_base",
"kallsyms_num_syms",
"kallsyms_names",
"kallsyms_markers",
"kallsyms_token_table",
"kallsyms_token_index",
"_SDA_BASE_",
"_SDA2_BASE_",
NULL };
static char *special_prefixes[] = {
"__crc_",
NULL };
static char *special_suffixes[] = {
"_veneer",
"_from_arm",
"_from_thumb",
NULL };
int i;
char *sym_name = (char *)s->sym + 1;
if (symbol_prefix_char && *sym_name == symbol_prefix_char)
sym_name++;
if (!all_symbols) {
if (symbol_in_range(s, text_ranges,
ARRAY_SIZE(text_ranges)) == 0)
return 0;
if ((s->addr == text_range_text->end &&
strcmp(sym_name,
text_range_text->end_sym)) ||
(s->addr == text_range_inittext->end &&
strcmp(sym_name,
text_range_inittext->end_sym)))
return 0;
}
for (i = 0; special_symbols[i]; i++)
if (strcmp(sym_name, special_symbols[i]) == 0)
return 0;
for (i = 0; special_prefixes[i]; i++) {
int l = strlen(special_prefixes[i]);
if (l <= strlen(sym_name) &&
strncmp(sym_name, special_prefixes[i], l) == 0)
return 0;
}
for (i = 0; special_suffixes[i]; i++) {
int l = strlen(sym_name) - strlen(special_suffixes[i]);
if (l >= 0 && strcmp(sym_name + l, special_suffixes[i]) == 0)
return 0;
}
return 1;
}
static void read_map(FILE *in)
{
while (!feof(in)) {
if (table_cnt >= table_size) {
table_size += 10000;
table = realloc(table, sizeof(*table) * table_size);
if (!table) {
fprintf(stderr, "out of memory\n");
exit (1);
}
}
if (read_symbol(in, &table[table_cnt]) == 0) {
table[table_cnt].start_pos = table_cnt;
table_cnt++;
}
}
}
static void output_label(char *label)
{
if (symbol_prefix_char)
printf(".globl %c%s\n", symbol_prefix_char, label);
else
printf(".globl %s\n", label);
printf("\tALGN\n");
if (symbol_prefix_char)
printf("%c%s:\n", symbol_prefix_char, label);
else
printf("%s:\n", label);
}
static int expand_symbol(unsigned char *data, int len, char *result)
{
int c, rlen, total=0;
while (len) {
c = *data;
if (best_table[c][0]==c && best_table_len[c]==1) {
*result++ = c;
total++;
} else {
rlen = expand_symbol(best_table[c], best_table_len[c], result);
total += rlen;
result += rlen;
}
data++;
len--;
}
*result=0;
return total;
}
static int symbol_absolute(struct sym_entry *s)
{
return s->percpu_absolute;
}
static void write_src(void)
{
unsigned int i, k, off;
unsigned int best_idx[256];
unsigned int *markers;
char buf[KSYM_NAME_LEN];
printf("#include <asm/types.h>\n");
printf("#if BITS_PER_LONG == 64\n");
printf("#define PTR .quad\n");
printf("#define ALGN .align 8\n");
printf("#else\n");
printf("#define PTR .long\n");
printf("#define ALGN .align 4\n");
printf("#endif\n");
printf("\t.section .rodata, \"a\"\n");
if (!base_relative)
output_label("kallsyms_addresses");
else
output_label("kallsyms_offsets");
for (i = 0; i < table_cnt; i++) {
if (base_relative) {
long long offset;
int overflow;
if (!absolute_percpu) {
offset = table[i].addr - relative_base;
overflow = (offset < 0 || offset > UINT_MAX);
} else if (symbol_absolute(&table[i])) {
offset = table[i].addr;
overflow = (offset < 0 || offset > INT_MAX);
} else {
offset = relative_base - table[i].addr - 1;
overflow = (offset < INT_MIN || offset >= 0);
}
if (overflow) {
fprintf(stderr, "kallsyms failure: "
"%s symbol value %#llx out of range in relative mode\n",
symbol_absolute(&table[i]) ? "absolute" : "relative",
table[i].addr);
exit(EXIT_FAILURE);
}
printf("\t.long\t%#x\n", (int)offset);
} else if (!symbol_absolute(&table[i])) {
if (_text <= table[i].addr)
printf("\tPTR\t_text + %#llx\n",
table[i].addr - _text);
else
printf("\tPTR\t_text - %#llx\n",
_text - table[i].addr);
} else {
printf("\tPTR\t%#llx\n", table[i].addr);
}
}
printf("\n");
if (base_relative) {
output_label("kallsyms_relative_base");
printf("\tPTR\t_text - %#llx\n", _text - relative_base);
printf("\n");
}
output_label("kallsyms_num_syms");
printf("\tPTR\t%d\n", table_cnt);
printf("\n");
markers = malloc(sizeof(unsigned int) * ((table_cnt + 255) / 256));
if (!markers) {
fprintf(stderr, "kallsyms failure: "
"unable to allocate required memory\n");
exit(EXIT_FAILURE);
}
output_label("kallsyms_names");
off = 0;
for (i = 0; i < table_cnt; i++) {
if ((i & 0xFF) == 0)
markers[i >> 8] = off;
printf("\t.byte 0x%02x", table[i].len);
for (k = 0; k < table[i].len; k++)
printf(", 0x%02x", table[i].sym[k]);
printf("\n");
off += table[i].len + 1;
}
printf("\n");
output_label("kallsyms_markers");
for (i = 0; i < ((table_cnt + 255) >> 8); i++)
printf("\tPTR\t%d\n", markers[i]);
printf("\n");
free(markers);
output_label("kallsyms_token_table");
off = 0;
for (i = 0; i < 256; i++) {
best_idx[i] = off;
expand_symbol(best_table[i], best_table_len[i], buf);
printf("\t.asciz\t\"%s\"\n", buf);
off += strlen(buf) + 1;
}
printf("\n");
output_label("kallsyms_token_index");
for (i = 0; i < 256; i++)
printf("\t.short\t%d\n", best_idx[i]);
printf("\n");
}
static void learn_symbol(unsigned char *symbol, int len)
{
int i;
for (i = 0; i < len - 1; i++)
token_profit[ symbol[i] + (symbol[i + 1] << 8) ]++;
}
static void forget_symbol(unsigned char *symbol, int len)
{
int i;
for (i = 0; i < len - 1; i++)
token_profit[ symbol[i] + (symbol[i + 1] << 8) ]--;
}
static void build_initial_tok_table(void)
{
unsigned int i, pos;
pos = 0;
for (i = 0; i < table_cnt; i++) {
if ( symbol_valid(&table[i]) ) {
if (pos != i)
table[pos] = table[i];
learn_symbol(table[pos].sym, table[pos].len);
pos++;
}
}
table_cnt = pos;
}
static void *find_token(unsigned char *str, int len, unsigned char *token)
{
int i;
for (i = 0; i < len - 1; i++) {
if (str[i] == token[0] && str[i+1] == token[1])
return &str[i];
}
return NULL;
}
static void compress_symbols(unsigned char *str, int idx)
{
unsigned int i, len, size;
unsigned char *p1, *p2;
for (i = 0; i < table_cnt; i++) {
len = table[i].len;
p1 = table[i].sym;
p2 = find_token(p1, len, str);
if (!p2) continue;
forget_symbol(table[i].sym, len);
size = len;
do {
*p2 = idx;
p2++;
size -= (p2 - p1);
memmove(p2, p2 + 1, size);
p1 = p2;
len--;
if (size < 2) break;
p2 = find_token(p1, size, str);
} while (p2);
table[i].len = len;
learn_symbol(table[i].sym, len);
}
}
static int find_best_token(void)
{
int i, best, bestprofit;
bestprofit=-10000;
best = 0;
for (i = 0; i < 0x10000; i++) {
if (token_profit[i] > bestprofit) {
best = i;
bestprofit = token_profit[i];
}
}
return best;
}
static void optimize_result(void)
{
int i, best;
for (i = 255; i >= 0; i--) {
if (!best_table_len[i]) {
best = find_best_token();
if (token_profit[best] == 0)
break;
best_table_len[i] = 2;
best_table[i][0] = best & 0xFF;
best_table[i][1] = (best >> 8) & 0xFF;
compress_symbols(best_table[i], i);
}
}
}
static void insert_real_symbols_in_table(void)
{
unsigned int i, j, c;
memset(best_table, 0, sizeof(best_table));
memset(best_table_len, 0, sizeof(best_table_len));
for (i = 0; i < table_cnt; i++) {
for (j = 0; j < table[i].len; j++) {
c = table[i].sym[j];
best_table[c][0]=c;
best_table_len[c]=1;
}
}
}
static void optimize_token_table(void)
{
build_initial_tok_table();
insert_real_symbols_in_table();
if (!table_cnt) {
fprintf(stderr, "No valid symbol.\n");
exit(1);
}
optimize_result();
}
static int may_be_linker_script_provide_symbol(const struct sym_entry *se)
{
const char *symbol = (char *)se->sym + 1;
int len = se->len - 1;
if (len < 8)
return 0;
if (symbol[0] != '_' || symbol[1] != '_')
return 0;
if (!memcmp(symbol + 2, "start_", 6))
return 1;
if (!memcmp(symbol + 2, "stop_", 5))
return 1;
if (!memcmp(symbol + 2, "end_", 4))
return 1;
if (!memcmp(symbol + len - 6, "_start", 6))
return 1;
if (!memcmp(symbol + len - 4, "_end", 4))
return 1;
return 0;
}
static int prefix_underscores_count(const char *str)
{
const char *tail = str;
while (*tail == '_')
tail++;
return tail - str;
}
static int compare_symbols(const void *a, const void *b)
{
const struct sym_entry *sa;
const struct sym_entry *sb;
int wa, wb;
sa = a;
sb = b;
if (sa->addr > sb->addr)
return 1;
if (sa->addr < sb->addr)
return -1;
wa = (sa->sym[0] == 'w') || (sa->sym[0] == 'W');
wb = (sb->sym[0] == 'w') || (sb->sym[0] == 'W');
if (wa != wb)
return wa - wb;
wa = may_be_linker_script_provide_symbol(sa);
wb = may_be_linker_script_provide_symbol(sb);
if (wa != wb)
return wa - wb;
wa = prefix_underscores_count((const char *)sa->sym + 1);
wb = prefix_underscores_count((const char *)sb->sym + 1);
if (wa != wb)
return wa - wb;
return sa->start_pos - sb->start_pos;
}
static void sort_symbols(void)
{
qsort(table, table_cnt, sizeof(struct sym_entry), compare_symbols);
}
static void make_percpus_absolute(void)
{
unsigned int i;
for (i = 0; i < table_cnt; i++)
if (symbol_in_range(&table[i], &percpu_range, 1)) {
table[i].sym[0] = 'A';
table[i].percpu_absolute = 1;
}
}
static void record_relative_base(void)
{
unsigned int i;
relative_base = -1ULL;
for (i = 0; i < table_cnt; i++)
if (!symbol_absolute(&table[i]) &&
table[i].addr < relative_base)
relative_base = table[i].addr;
}
int main(int argc, char **argv)
{
if (argc >= 2) {
int i;
for (i = 1; i < argc; i++) {
if(strcmp(argv[i], "--all-symbols") == 0)
all_symbols = 1;
else if (strcmp(argv[i], "--absolute-percpu") == 0)
absolute_percpu = 1;
else if (strncmp(argv[i], "--symbol-prefix=", 16) == 0) {
char *p = &argv[i][16];
if ((*p == '"' && *(p+2) == '"') || (*p == '\'' && *(p+2) == '\''))
p++;
symbol_prefix_char = *p;
} else if (strcmp(argv[i], "--base-relative") == 0)
base_relative = 1;
else
usage();
}
} else if (argc != 1)
usage();
read_map(stdin);
if (absolute_percpu)
make_percpus_absolute();
if (base_relative)
record_relative_base();
sort_symbols();
optimize_token_table();
write_src();
return 0;
}
