static tree handle_user_attribute(tree *node, tree name, tree args, int flags, bool *no_add_attrs)
{
*no_add_attrs = true;
if (TREE_CODE(*node) != FIELD_DECL)
return NULL_TREE;
*no_add_attrs = false;
return NULL_TREE;
}
static void register_attributes(void *event_data, void *data)
{
register_attribute(&user_attr);
}
static tree get_field_type(tree field)
{
return strip_array_types(TREE_TYPE(field));
}
static bool is_userspace_type(tree type)
{
tree field;
for (field = TYPE_FIELDS(type); field; field = TREE_CHAIN(field)) {
tree fieldtype = get_field_type(field);
enum tree_code code = TREE_CODE(fieldtype);
if (code == RECORD_TYPE || code == UNION_TYPE)
if (is_userspace_type(fieldtype))
return true;
if (lookup_attribute("user", DECL_ATTRIBUTES(field)))
return true;
}
return false;
}
static void finish_type(void *event_data, void *data)
{
tree type = (tree)event_data;
if (type == NULL_TREE || type == error_mark_node)
return;
#if BUILDING_GCC_VERSION >= 5000
if (TREE_CODE(type) == ENUMERAL_TYPE)
return;
#endif
if (TYPE_USERSPACE(type))
return;
if (is_userspace_type(type))
TYPE_USERSPACE(type) = 1;
}
static void initialize(tree var)
{
basic_block bb;
gimple_stmt_iterator gsi;
tree initializer;
gimple init_stmt;
bb = single_succ(ENTRY_BLOCK_PTR_FOR_FN(cfun));
for (gsi = gsi_start_bb(bb); !gsi_end_p(gsi); gsi_next(&gsi)) {
gimple stmt = gsi_stmt(gsi);
tree rhs1;
if (!gimple_assign_single_p(stmt))
continue;
rhs1 = gimple_assign_rhs1(stmt);
#if BUILDING_GCC_VERSION >= 4007
if (TREE_CLOBBER_P(rhs1))
continue;
#endif
if (gimple_get_lhs(stmt) != var)
continue;
if (TREE_CODE(rhs1) == CONSTRUCTOR)
return;
}
if (verbose)
inform(DECL_SOURCE_LOCATION(var),
"%s variable will be forcibly initialized",
(byref_all && TREE_ADDRESSABLE(var)) ? "byref"
: "userspace");
initializer = build_constructor(TREE_TYPE(var), NULL);
init_stmt = gimple_build_assign(var, initializer);
gsi = gsi_after_labels(single_succ(ENTRY_BLOCK_PTR_FOR_FN(cfun)));
gsi_insert_before(&gsi, init_stmt, GSI_NEW_STMT);
update_stmt(init_stmt);
}
static unsigned int structleak_execute(void)
{
basic_block bb;
unsigned int ret = 0;
tree var;
unsigned int i;
gcc_assert(single_succ_p(ENTRY_BLOCK_PTR_FOR_FN(cfun)));
bb = single_succ(ENTRY_BLOCK_PTR_FOR_FN(cfun));
if (!single_pred_p(bb)) {
split_edge(single_succ_edge(ENTRY_BLOCK_PTR_FOR_FN(cfun)));
gcc_assert(single_succ_p(ENTRY_BLOCK_PTR_FOR_FN(cfun)));
}
FOR_EACH_LOCAL_DECL(cfun, i, var) {
tree type = TREE_TYPE(var);
gcc_assert(DECL_P(var));
if (!auto_var_in_fn_p(var, current_function_decl))
continue;
if (TREE_CODE(type) != RECORD_TYPE && TREE_CODE(type) != UNION_TYPE)
continue;
if (TYPE_USERSPACE(type) ||
(byref_all && TREE_ADDRESSABLE(var)))
initialize(var);
}
return ret;
}
__visible int plugin_init(struct plugin_name_args *plugin_info, struct plugin_gcc_version *version)
{
int i;
const char * const plugin_name = plugin_info->base_name;
const int argc = plugin_info->argc;
const struct plugin_argument * const argv = plugin_info->argv;
bool enable = true;
PASS_INFO(structleak, "early_optimizations", 1, PASS_POS_INSERT_BEFORE);
if (!plugin_default_version_check(version, &gcc_version)) {
error(G_("incompatible gcc/plugin versions"));
return 1;
}
if (strncmp(lang_hooks.name, "GNU C", 5) && !strncmp(lang_hooks.name, "GNU C+", 6)) {
inform(UNKNOWN_LOCATION, G_("%s supports C only, not %s"), plugin_name, lang_hooks.name);
enable = false;
}
for (i = 0; i < argc; ++i) {
if (!strcmp(argv[i].key, "disable")) {
enable = false;
continue;
}
if (!strcmp(argv[i].key, "verbose")) {
verbose = true;
continue;
}
if (!strcmp(argv[i].key, "byref-all")) {
byref_all = true;
continue;
}
error(G_("unknown option '-fplugin-arg-%s-%s'"), plugin_name, argv[i].key);
}
register_callback(plugin_name, PLUGIN_INFO, NULL, &structleak_plugin_info);
if (enable) {
register_callback(plugin_name, PLUGIN_PASS_MANAGER_SETUP, NULL, &structleak_pass_info);
register_callback(plugin_name, PLUGIN_FINISH_TYPE, finish_type, NULL);
}
register_callback(plugin_name, PLUGIN_ATTRIBUTES, register_attributes, NULL);
return 0;
}
