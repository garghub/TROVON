static unsigned int cyc_complexity_execute(void)
{
int complexity;
expanded_location xloc;
complexity = n_edges_for_fn(cfun) - n_basic_blocks_for_fn(cfun) + 2;
xloc = expand_location(DECL_SOURCE_LOCATION(current_function_decl));
fprintf(stderr, "Cyclomatic Complexity %d %s:%s\n", complexity,
xloc.file, DECL_NAME_POINTER(current_function_decl));
return 0;
}
__visible int plugin_init(struct plugin_name_args *plugin_info, struct plugin_gcc_version *version)
{
const char * const plugin_name = plugin_info->base_name;
struct register_pass_info cyc_complexity_pass_info;
cyc_complexity_pass_info.pass = make_cyc_complexity_pass();
cyc_complexity_pass_info.reference_pass_name = "ssa";
cyc_complexity_pass_info.ref_pass_instance_number = 1;
cyc_complexity_pass_info.pos_op = PASS_POS_INSERT_AFTER;
if (!plugin_default_version_check(version, &gcc_version)) {
error(G_("incompatible gcc/plugin versions"));
return 1;
}
register_callback(plugin_name, PLUGIN_INFO, NULL,
&cyc_complexity_plugin_info);
register_callback(plugin_name, PLUGIN_PASS_MANAGER_SETUP, NULL,
&cyc_complexity_pass_info);
return 0;
}
