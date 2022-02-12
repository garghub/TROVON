static gint
sort_by_name(gconstpointer a, gconstpointer b)
{
return strcmp(((const stat_cmd_arg *)a)->cmd,
((const stat_cmd_arg *)b)->cmd);
}
void
register_stat_cmd_arg(const char *cmd, void (*func)(const char*, void*),void* userdata)
{
stat_cmd_arg *newsca;
newsca=g_malloc(sizeof(stat_cmd_arg));
newsca->cmd=cmd;
newsca->func=func;
newsca->userdata=userdata;
stat_cmd_arg_list=g_slist_insert_sorted(stat_cmd_arg_list, newsca,
sort_by_name);
}
gboolean
process_stat_cmd_arg(char *optstr)
{
GSList *entry;
stat_cmd_arg *sca;
stat_requested *tr;
for(entry=stat_cmd_arg_list;entry;entry=g_slist_next(entry)){
sca=entry->data;
if(!strncmp(sca->cmd,optstr,strlen(sca->cmd))){
tr=g_malloc(sizeof (stat_requested));
tr->sca = sca;
tr->arg=g_strdup(optstr);
stats_requested=g_slist_append(stats_requested, tr);
return TRUE;
}
}
return FALSE;
}
void
list_stat_cmd_args(void)
{
GSList *entry;
stat_cmd_arg *sca;
for(entry=stat_cmd_arg_list;entry;entry=g_slist_next(entry)){
sca=entry->data;
fprintf(stderr," %s\n",sca->cmd);
}
}
void
start_requested_stats(void)
{
stat_requested *sr;
while(stats_requested){
sr=stats_requested->data;
(*sr->sca->func)(sr->arg,sr->sca->userdata);
g_free(sr->arg);
g_free(sr);
stats_requested=g_slist_remove(stats_requested, sr);
}
}
