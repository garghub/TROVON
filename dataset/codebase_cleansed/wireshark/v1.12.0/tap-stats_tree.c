static void
draw_stats_tree(void *psp)
{
stats_tree *st = (stats_tree *)psp;
GString *s;
s= stats_tree_format_as_str(st, ST_FORMAT_PLAIN, stats_tree_get_default_sort_col(st),
stats_tree_is_default_sort_DESC(st));
printf("%s",s->str);
g_string_free(s,TRUE);
}
static void
init_stats_tree(const char *opt_arg, void *userdata _U_)
{
char *abbr = stats_tree_get_abbr(opt_arg);
GString *error_string;
stats_tree_cfg *cfg = NULL;
stats_tree *st = NULL;
if (abbr) {
cfg = stats_tree_get_cfg_by_abbr(abbr);
if (cfg != NULL) {
if (strncmp (opt_arg, cfg->pr->init_string, strlen(cfg->pr->init_string)) == 0){
st = stats_tree_new(cfg,NULL,opt_arg+strlen(cfg->pr->init_string));
} else {
report_failure("Wrong stats_tree (%s) found when looking at ->init_string",abbr);
return;
}
} else {
report_failure("no such stats_tree (%s) found in stats_tree registry",abbr);
return;
}
g_free(abbr);
} else {
report_failure("could not obtain stats_tree abbr (%s) from arg '%s'",abbr,opt_arg);
return;
}
error_string = register_tap_listener(st->cfg->tapname,
st,
st->filter,
st->cfg->flags,
stats_tree_reset,
stats_tree_packet,
draw_stats_tree);
if (error_string) {
report_failure("stats_tree for: %s failed to attach to the tap: %s",cfg->name,error_string->str);
return;
}
if (cfg->init) cfg->init(st);
}
static void
register_stats_tree_tap (gpointer k _U_, gpointer v, gpointer p _U_)
{
stats_tree_cfg *cfg = (stats_tree_cfg *)v;
cfg->pr = (tree_cfg_pres *)g_malloc(sizeof(tree_cfg_pres));
cfg->pr->init_string = g_strdup_printf("%s,tree", cfg->abbr);
register_stat_cmd_arg(cfg->pr->init_string, init_stats_tree, NULL);
}
static void
free_tree_presentation(stats_tree *st)
{
g_free(st->pr);
}
void
register_tap_listener_stats_tree_stat(void)
{
stats_tree_presentation(register_stats_tree_tap, NULL, NULL, NULL, NULL,
NULL, free_tree_presentation, NULL, NULL, NULL);
}
