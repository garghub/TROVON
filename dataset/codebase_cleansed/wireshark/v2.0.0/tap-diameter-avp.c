static gboolean
tree_traverse_pre_order(proto_tree *tree, proto_tree_traverse_func func, gpointer data)
{
proto_node *pnode = tree;
proto_node *child;
proto_node *current;
if (func(pnode, data))
return TRUE;
child = pnode->first_child;
while (child != NULL) {
current = child;
child = current->next;
if (tree_traverse_pre_order((proto_tree *)current, func, data))
return TRUE;
}
return FALSE;
}
static gboolean
diam_tree_to_csv(proto_node *node, gpointer data)
{
char *val_str = NULL;
char *val_tmp = NULL;
ftenum_t ftype;
field_info *fi;
header_field_info *hfi;
if (!node) {
fprintf(stderr, "traverse end: empty node. node='%p' data='%p'\n", (void *)node, (void *)data);
return FALSE;
}
fi = node->finfo;
hfi = fi ? fi->hfinfo : NULL;
if (!hfi) {
fprintf(stderr, "traverse end: hfi not found. node='%p'\n", (void *)node);
return FALSE;
}
ftype = fvalue_type_ftenum(&fi->value);
if (ftype != FT_NONE && ftype != FT_PROTOCOL) {
val_tmp = fvalue_to_string_repr(&fi->value, FTREPR_DISPLAY, hfi->display, NULL);
if (val_tmp)
{
val_str = g_strdup(val_tmp);
g_free(val_tmp);
} else
val_str = g_strdup_printf("unsupported type: %s", ftype_name(ftype));
printf("%s='%s' ", hfi->name, val_str);
g_free(val_str);
}
return FALSE;
}
static int
diameteravp_packet(void *pds, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pdi)
{
int ret = 0;
double resp_time = 0.;
gboolean is_request = TRUE;
guint32 cmd_code = 0;
guint32 req_frame = 0;
guint32 ans_frame = 0;
guint32 diam_child_node = 0;
proto_node *current = NULL;
proto_node *node = NULL;
header_field_info *hfi = NULL;
field_info *finfo = NULL;
const diameter_req_ans_pair_t *dp = (const diameter_req_ans_pair_t *)pdi;
diameteravp_t *ds = NULL;
if (!dp || !edt || !edt->tree)
return ret;
ds = (diameteravp_t *)pds;
if (pinfo->fd->num > ds->frame) {
ds->frame = pinfo->fd->num;
ds->diammsg_toprocess = 0;
} else {
ds->diammsg_toprocess += 1;
}
is_request = dp->processing_request;
cmd_code = dp->cmd_code;
req_frame = dp->req_frame;
ans_frame = dp->ans_frame;
if (!is_request) {
nstime_t ns;
nstime_delta(&ns, &pinfo->fd->abs_ts, &dp->req_time);
resp_time = nstime_to_sec(&ns);
resp_time = resp_time < 0. ? 0. : resp_time;
}
if (ds->cmd_code && ds->cmd_code != cmd_code)
return ret;
node = edt->tree->first_child;
while (node != NULL) {
current = node;
node = current->next;
finfo = current->finfo;
hfi = finfo ? finfo->hfinfo : NULL;
if (hfi && hfi->abbrev && strcmp(hfi->abbrev, "diameter") == 0) {
if (ds->diammsg_toprocess == diam_child_node) {
if (is_request) {
ds->req_count++;
} else {
ds->ans_count++;
if (req_frame > 0)
ds->paired_ans_count++;
}
printf("frame='%u' time='%f' src='%s' srcport='%u' dst='%s' dstport='%u' proto='diameter' msgnr='%u' is_request='%d' cmd='%u' req_frame='%u' ans_frame='%u' resp_time='%f' ",
pinfo->fd->num, nstime_to_sec(&pinfo->fd->abs_ts), address_to_str(pinfo->pool, &pinfo->src), pinfo->srcport, address_to_str(pinfo->pool, &pinfo->dst), pinfo->destport, ds->diammsg_toprocess, is_request, cmd_code, req_frame, ans_frame, resp_time);
tree_traverse_pre_order(current, diam_tree_to_csv, &ds);
printf("\n");
}
diam_child_node++;
}
}
return ret;
}
static void
diameteravp_draw(void *pds)
{
diameteravp_t *ds = (diameteravp_t *)pds;
printf("=== Diameter Summary ===\nrequset count:\t%u\nanswer count:\t%u\nreq/ans pairs:\t%u\n", ds->req_count, ds->ans_count, ds->paired_ans_count);
}
static void
diameteravp_init(const char *opt_arg, void *userdata _U_)
{
diameteravp_t *ds;
gchar *field = NULL;
gchar **tokens;
guint opt_count = 0;
guint opt_idx = 0;
GString *filter = NULL;
GString *error_string = NULL;
ds = g_new(diameteravp_t, 1);
ds->frame = 0;
ds->diammsg_toprocess = 0;
ds->cmd_code = 0;
ds->req_count = 0;
ds->ans_count = 0;
ds->paired_ans_count = 0;
ds->filter = NULL;
filter = g_string_new("diameter");
tokens = g_strsplit(opt_arg, ",", 1024);
opt_count = 0;
while (tokens[opt_count])
opt_count++;
if (opt_count > 2)
ds->cmd_code = (guint32)atoi(tokens[2]);
for (opt_idx=3; opt_idx<opt_count; opt_idx++)
{
field = tokens[opt_idx];
g_string_append(filter, "||");
if (!strchr(field, '.'))
g_string_append(filter, "diameter.");
g_string_append(filter, field);
}
g_strfreev(tokens);
ds->filter = g_string_free(filter, FALSE);
error_string = register_tap_listener("diameter", ds, ds->filter, 0, NULL, diameteravp_packet, diameteravp_draw);
if (error_string) {
g_free(ds);
fprintf(stderr, "tshark: Couldn't register diam,csv tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_diameteravp(void)
{
register_stat_tap_ui(&diameteravp_ui, NULL);
}
