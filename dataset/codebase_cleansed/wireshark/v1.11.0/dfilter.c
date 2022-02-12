void
dfilter_fail(const char *format, ...)
{
va_list args;
if (dfilter_error_msg != NULL)
return;
va_start(args, format);
g_vsnprintf(dfilter_error_msg_buf, sizeof(dfilter_error_msg_buf),
format, args);
dfilter_error_msg = dfilter_error_msg_buf;
va_end(args);
}
void
dfilter_init(void)
{
if (ParserObj) {
g_message("I expected ParserObj to be NULL\n");
DfilterFree(ParserObj, g_free);
}
ParserObj = DfilterAlloc(g_malloc);
#ifdef DFTRACE
DfilterTrace(stdout, "lemon> ");
#endif
sttype_init();
dfilter_macro_init();
}
void
dfilter_cleanup(void)
{
if (ParserObj) {
DfilterFree(ParserObj, g_free);
}
sttype_cleanup();
}
static dfilter_t*
dfilter_new(void)
{
dfilter_t *df;
df = g_new0(dfilter_t, 1);
df->insns = NULL;
df->deprecated = NULL;
return df;
}
static void
free_insns(GPtrArray *insns)
{
unsigned int i;
dfvm_insn_t *insn;
for (i = 0; i < insns->len; i++) {
insn = (dfvm_insn_t *)g_ptr_array_index(insns, i);
dfvm_insn_free(insn);
}
g_ptr_array_free(insns, TRUE);
}
void
dfilter_free(dfilter_t *df)
{
guint i;
if (!df)
return;
if (df->insns) {
free_insns(df->insns);
}
if (df->consts) {
free_insns(df->consts);
}
g_free(df->interesting_fields);
for (i = 0; i < df->max_registers; i++) {
if (df->registers[i]) {
g_list_free(df->registers[i]);
}
}
if (df->deprecated) {
for (i = 0; i < df->deprecated->len; ++i) {
gchar *depr = (gchar *)g_ptr_array_index(df->deprecated, i);
g_free(depr);
}
g_ptr_array_free(df->deprecated, TRUE);
}
g_free(df->registers);
g_free(df->attempted_load);
g_free(df);
}
static dfwork_t*
dfwork_new(void)
{
dfwork_t *dfw;
dfw = g_new0(dfwork_t, 1);
dfw->first_constant = -1;
return dfw;
}
static void
dfwork_free(dfwork_t *dfw)
{
if (dfw->st_root) {
stnode_free(dfw->st_root);
}
if (dfw->loaded_fields) {
g_hash_table_destroy(dfw->loaded_fields);
}
if (dfw->interesting_fields) {
g_hash_table_destroy(dfw->interesting_fields);
}
if (dfw->insns) {
free_insns(dfw->insns);
}
if (dfw->consts) {
free_insns(dfw->consts);
}
g_free(dfw);
}
gboolean
dfilter_compile(const gchar *text, dfilter_t **dfp)
{
int token;
dfilter_t *dfilter;
dfwork_t *dfw;
gboolean failure = FALSE;
const char *depr_test;
guint i;
GPtrArray *deprecated;
g_assert(dfp);
if (!text) {
*dfp = NULL;
return FALSE;
}
dfilter_error_msg = NULL;
if ( !( text = dfilter_macro_apply(text, &dfilter_error_msg) ) ) {
return FALSE;
}
dfw = dfwork_new();
df_scanner_text(text);
deprecated = g_ptr_array_new();
while (1) {
df_lval = stnode_new(STTYPE_UNINITIALIZED, NULL);
token = df_lex();
if (token == SCAN_FAILED) {
failure = TRUE;
break;
}
if (token == 0) {
break;
}
depr_test = stnode_deprecated(df_lval);
if (depr_test) {
for (i = 0; i < deprecated->len; i++) {
if (g_ascii_strcasecmp(depr_test, (const gchar *)g_ptr_array_index(deprecated, i)) == 0) {
depr_test = NULL;
}
}
}
if (depr_test) {
g_ptr_array_add(deprecated, g_strdup(depr_test));
}
Dfilter(ParserObj, token, df_lval, dfw);
df_lval = NULL;
if (dfw->syntax_error) {
failure = TRUE;
break;
}
}
if (df_lval) {
stnode_free(df_lval);
df_lval = NULL;
}
Dfilter(ParserObj, 0, NULL, dfw);
if (dfw->syntax_error)
failure = TRUE;
df_scanner_cleanup();
if (failure)
goto FAILURE;
if (dfw->st_root == NULL) {
*dfp = NULL;
for (i = 0; i < deprecated->len; ++i) {
gchar* depr = (gchar*)g_ptr_array_index(deprecated,i);
g_free(depr);
}
g_ptr_array_free(deprecated, TRUE);
}
else {
if (!dfw_semcheck(dfw, deprecated)) {
goto FAILURE;
}
dfw_gencode(dfw);
dfilter = dfilter_new();
dfilter->insns = dfw->insns;
dfilter->consts = dfw->consts;
dfw->insns = NULL;
dfw->consts = NULL;
dfilter->interesting_fields = dfw_interesting_fields(dfw,
&dfilter->num_interesting_fields);
dfilter->num_registers = dfw->first_constant;
dfilter->max_registers = dfw->next_register;
dfilter->registers = g_new0(GList*, dfilter->max_registers);
dfilter->attempted_load = g_new0(gboolean, dfilter->max_registers);
dfvm_init_const(dfilter);
dfilter->deprecated = deprecated;
*dfp = dfilter;
}
dfwork_free(dfw);
return TRUE;
FAILURE:
if (dfw) {
dfwork_free(dfw);
}
for (i = 0; i < deprecated->len; ++i) {
gchar* depr = (gchar*)g_ptr_array_index(deprecated,i);
g_free(depr);
}
g_ptr_array_free(deprecated, TRUE);
dfilter_fail("Unable to parse filter string \"%s\".", text);
*dfp = NULL;
return FALSE;
}
gboolean
dfilter_apply(dfilter_t *df, proto_tree *tree)
{
return dfvm_apply(df, tree);
}
gboolean
dfilter_apply_edt(dfilter_t *df, epan_dissect_t* edt)
{
return dfvm_apply(df, edt->tree);
}
void
dfilter_prime_proto_tree(const dfilter_t *df, proto_tree *tree)
{
int i;
for (i = 0; i < df->num_interesting_fields; i++) {
proto_tree_prime_hfid(tree, df->interesting_fields[i]);
}
}
GPtrArray *
dfilter_deprecated_tokens(dfilter_t *df) {
if (df->deprecated && df->deprecated->len > 0) {
return df->deprecated;
}
return NULL;
}
void
dfilter_dump(dfilter_t *df)
{
guint i;
const gchar *sep = "";
dfvm_dump(stdout, df);
if (df->deprecated && df->deprecated->len) {
printf("\nDeprecated tokens: ");
for (i = 0; i < df->deprecated->len; i++) {
printf("%s\"%s\"", sep, (char *) g_ptr_array_index(df->deprecated, i));
sep = ", ";
}
printf("\n");
}
}
