static void
icmpv6stat_reset(void *tapdata)
{
icmpv6stat_t *icmpv6stat = (icmpv6stat_t *)tapdata;
g_slist_free(icmpv6stat->rt_list);
memset(icmpv6stat, 0, sizeof(icmpv6stat_t));
icmpv6stat->min_msecs = 1.0 * G_MAXUINT;
}
static gint compare_doubles(gconstpointer a, gconstpointer b)
{
double ad, bd;
ad = *(double *)a;
bd = *(double *)b;
if (ad < bd)
return -1;
if (ad > bd)
return 1;
return 0;
}
static int
icmpv6stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *data)
{
icmpv6stat_t *icmpv6stat = (icmpv6stat_t *)tapdata;
const icmp_transaction_t *trans = (const icmp_transaction_t *)data;
double resp_time, *rt;
if (trans == NULL)
return 0;
if (trans->resp_frame) {
resp_time = nstime_to_msec(&trans->resp_time);
rt = g_new(double,1);
if (rt == NULL)
return 0;
*rt = resp_time;
icmpv6stat->rt_list = g_slist_prepend(icmpv6stat->rt_list, rt);
icmpv6stat->num_resps++;
if (icmpv6stat->min_msecs > resp_time) {
icmpv6stat->min_frame = trans->resp_frame;
icmpv6stat->min_msecs = resp_time;
}
if (icmpv6stat->max_msecs < resp_time) {
icmpv6stat->max_frame = trans->resp_frame;
icmpv6stat->max_msecs = resp_time;
}
icmpv6stat->tot_msecs += resp_time;
} else if (trans->rqst_frame)
icmpv6stat->num_rqsts++;
else
return 0;
return 1;
}
static void compute_stats(icmpv6stat_t *icmpv6stat, double *mean, double *med, double *sdev)
{
GSList *slist;
double diff;
double sq_diff_sum = 0.0;
icmpv6stat->rt_list = g_slist_sort(icmpv6stat->rt_list, compare_doubles);
slist = icmpv6stat->rt_list;
if (icmpv6stat->num_resps == 0 || slist == NULL) {
*mean = 0.0;
*med = 0.0;
*sdev = 0.0;
return;
}
*mean = icmpv6stat->tot_msecs / icmpv6stat->num_resps;
if (icmpv6stat->num_resps & 1)
*med = *(double *)g_slist_nth_data(slist, icmpv6stat->num_resps / 2);
else {
*med =
(*(double *)g_slist_nth_data(slist, (icmpv6stat->num_resps - 1) / 2) +
*(double *)g_slist_nth_data(slist, icmpv6stat->num_resps / 2)) / 2;
}
for ( ; slist; slist = g_slist_next(slist)) {
diff = *(double *)slist->data - *mean;
sq_diff_sum += diff * diff;
}
if (icmpv6stat->num_resps > 1)
*sdev = sqrt(sq_diff_sum / (icmpv6stat->num_resps - 1));
else
*sdev = 0.0;
}
static void
icmpv6stat_draw(void *tapdata)
{
icmpv6stat_t *icmpv6stat = (icmpv6stat_t *)tapdata;
unsigned int lost;
double mean, sdev, med;
printf("\n");
printf("==========================================================================\n");
printf("ICMPv6 Service Response Time (SRT) Statistics (all times in ms):\n");
printf("Filter: %s\n", icmpv6stat->filter ? icmpv6stat->filter : "<none>");
printf("\nRequests Replies Lost %% Loss\n");
if (icmpv6stat->num_rqsts) {
lost = icmpv6stat->num_rqsts - icmpv6stat->num_resps;
compute_stats(icmpv6stat, &mean, &med, &sdev);
printf("%-10u%-10u%-10u%5.1f%%\n\n",
icmpv6stat->num_rqsts, icmpv6stat->num_resps, lost,
100.0 * lost / icmpv6stat->num_rqsts);
printf("Minimum Maximum Mean Median SDeviation Min Frame Max Frame\n");
printf("%-10.3f%-10.3f%-10.3f%-10.3f%-10.3f %-10u%-10u\n",
icmpv6stat->min_msecs >= G_MAXUINT ? 0.0 : icmpv6stat->min_msecs,
icmpv6stat->max_msecs, mean, med, sdev,
icmpv6stat->min_frame, icmpv6stat->max_frame);
} else {
printf("0 0 0 0.0%%\n\n");
printf("Minimum Maximum Mean Median SDeviation Min Frame Max Frame\n");
printf("0.000 0.000 0.000 0.000 0.000 0 0\n");
}
printf("==========================================================================\n");
}
static void
icmpv6stat_init(const char *opt_arg, void* userdata _U_)
{
icmpv6stat_t *icmpv6stat;
const char *filter = NULL;
GString *error_string;
if (strstr(opt_arg, "icmpv6,srt,"))
filter = opt_arg + strlen("icmpv6,srt,");
icmpv6stat = (icmpv6stat_t *)g_try_malloc(sizeof(icmpv6stat_t));
if (icmpv6stat == NULL) {
fprintf(stderr, "tshark: g_try_malloc() fatal error.\n");
exit(1);
}
memset(icmpv6stat, 0, sizeof(icmpv6stat_t));
icmpv6stat->min_msecs = 1.0 * G_MAXUINT;
if (filter)
icmpv6stat->filter = g_strdup(filter);
error_string = register_tap_listener("icmpv6", icmpv6stat, icmpv6stat->filter,
TL_REQUIRES_NOTHING, icmpv6stat_reset, icmpv6stat_packet, icmpv6stat_draw);
if (error_string) {
if (icmpv6stat->filter)
g_free(icmpv6stat->filter);
g_free(icmpv6stat);
fprintf(stderr, "tshark: Couldn't register icmpv6,srt tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_icmpv6stat(void)
{
register_stat_cmd_arg("icmpv6,srt", icmpv6stat_init, NULL);
}
