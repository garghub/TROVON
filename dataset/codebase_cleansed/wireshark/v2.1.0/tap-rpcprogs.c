static int
rpcprogs_packet(void *dummy1 _U_, packet_info *pinfo, epan_dissect_t *edt _U_, const void *pri)
{
const rpc_call_info_value *ri = (const rpc_call_info_value *)pri;
nstime_t delta;
rpc_program_t *rp = NULL;
if (!prog_list) {
rp = g_new(rpc_program_t, 1);
rp->next = NULL;
rp->program = ri->prog;
rp->version = ri->vers;
rp->num = 0;
rp->min.secs = 0;
rp->min.nsecs = 0;
rp->max.secs = 0;
rp->max.nsecs = 0;
rp->tot.secs = 0;
rp->tot.nsecs = 0;
prog_list = rp;
} else if ((ri->prog == prog_list->program)
&& (ri->vers == prog_list->version)) {
rp = prog_list;
} else if ( (ri->prog < prog_list->program)
|| ((ri->prog == prog_list->program) && (ri->vers < prog_list->version))) {
rp = g_new(rpc_program_t, 1);
rp->next = prog_list;
rp->program = ri->prog;
rp->version = ri->vers;
rp->num = 0;
rp->min.secs = 0;
rp->min.nsecs = 0;
rp->max.secs = 0;
rp->max.nsecs = 0;
rp->tot.secs = 0;
rp->tot.nsecs = 0;
prog_list = rp;
} else {
for (rp=prog_list; rp; rp=rp->next) {
if ((rp->next)
&& (rp->next->program == ri->prog)
&& (rp->next->version == ri->vers)) {
rp = rp->next;
break;
}
if ((!rp->next)
|| (rp->next->program > ri->prog)
|| ( (rp->next->program == ri->prog)
&& (rp->next->version > ri->vers))) {
rpc_program_t *trp;
trp = g_new(rpc_program_t, 1);
trp->next = rp->next;
trp->program = ri->prog;
trp->version = ri->vers;
trp->num = 0;
trp->min.secs = 0;
trp->min.nsecs = 0;
trp->max.secs = 0;
trp->max.nsecs = 0;
trp->tot.secs = 0;
trp->tot.nsecs = 0;
rp->next = trp;
rp = trp;
break;
}
}
}
if (ri->request || !rp) {
return 0;
}
nstime_delta(&delta, &pinfo->abs_ts, &ri->req_time);
if ((rp->max.secs == 0)
&& (rp->max.nsecs == 0) ) {
rp->max.secs = delta.secs;
rp->max.nsecs = delta.nsecs;
}
if ((rp->min.secs == 0)
&& (rp->min.nsecs == 0) ) {
rp->min.secs = delta.secs;
rp->min.nsecs = delta.nsecs;
}
if ( (delta.secs < rp->min.secs)
|| ( (delta.secs == rp->min.secs)
&& (delta.nsecs < rp->min.nsecs) ) ) {
rp->min.secs = delta.secs;
rp->min.nsecs = delta.nsecs;
}
if ( (delta.secs > rp->max.secs)
|| ( (delta.secs == rp->max.secs)
&& (delta.nsecs > rp->max.nsecs) ) ) {
rp->max.secs = delta.secs;
rp->max.nsecs = delta.nsecs;
}
rp->tot.secs += delta.secs;
rp->tot.nsecs += delta.nsecs;
if (rp->tot.nsecs > NANOSECS_PER_SEC) {
rp->tot.nsecs -= NANOSECS_PER_SEC;
rp->tot.secs++;
}
rp->num++;
return 1;
}
static void
rpcprogs_draw(void *dummy _U_)
{
guint64 td;
rpc_program_t *rp;
char str[64];
printf("\n");
printf("==========================================================\n");
printf("ONC-RPC Program Statistics:\n");
printf("Program Version Calls Min SRT Max SRT Avg SRT\n");
for (rp = prog_list;rp;rp = rp->next) {
if (rp->num == 0) {
continue;
}
td = ((guint64)(rp->tot.secs)) * NANOSECS_PER_SEC + rp->tot.nsecs;
td = ((td / rp->num) + 500) / 1000;
g_snprintf(str, sizeof(str), "%s(%d)", rpc_prog_name(rp->program), rp->program);
printf("%-15s %2u %6d %3d.%06d %3d.%06d %3" G_GINT64_MODIFIER "u.%06" G_GINT64_MODIFIER "u\n",
str,
rp->version,
rp->num,
(int)(rp->min.secs), (rp->min.nsecs+500)/1000,
(int)(rp->max.secs), (rp->max.nsecs+500)/1000,
td/MICROSECS_PER_SEC, td%MICROSECS_PER_SEC
);
}
printf("===================================================================\n");
}
static void
rpcprogs_init(const char *opt_arg _U_, void *userdata _U_)
{
GString *error_string;
if (already_enabled) {
return;
}
already_enabled = 1;
error_string = register_tap_listener("rpc", NULL, NULL, 0, NULL, rpcprogs_packet, rpcprogs_draw);
if (error_string) {
fprintf(stderr, "tshark: Couldn't register rpc,programs tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_rpcprogs(void)
{
register_stat_tap_ui(&rpcprogs_ui, NULL);
}
