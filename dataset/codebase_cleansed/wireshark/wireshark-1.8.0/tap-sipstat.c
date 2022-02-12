static void
sip_init_hash(sipstat_t *sp)
{
int i;
sp->hash_responses = g_hash_table_new(g_int_hash, g_int_equal);
for (i=0 ; vals_status_code[i].strptr ; i++)
{
gint *key = g_malloc (sizeof(gint));
sip_response_code_t *sc = g_malloc (sizeof(sip_response_code_t));
*key = vals_status_code[i].value;
sc->packets=0;
sc->response_code = *key;
sc->name=vals_status_code[i].strptr;
sc->sp = sp;
g_hash_table_insert(sc->sp->hash_responses, key, sc);
}
sp->hash_requests = g_hash_table_new(g_str_hash, g_str_equal);
}
static void
sip_draw_hash_requests( gchar *key _U_ , sip_request_method_t *data, gchar * format)
{
if (data->packets==0)
return;
printf( format, data->response, data->packets);
}
static void
sip_draw_hash_responses( gint * key _U_ , sip_response_code_t *data, char * format)
{
if (data==NULL) {
g_warning("C'est quoi ce borderl key=%d\n", *key);
exit(EXIT_FAILURE);
}
if (data->packets==0)
return;
printf(format, data->response_code, data->name, data->packets );
}
static void
sip_reset_hash_responses(gchar *key _U_ , sip_response_code_t *data, gpointer ptr _U_ )
{
data->packets = 0;
}
static void
sip_reset_hash_requests(gchar *key _U_ , sip_request_method_t *data, gpointer ptr _U_ )
{
data->packets = 0;
}
static void
sipstat_reset(void *psp )
{
sipstat_t *sp=psp;
if (sp) {
sp->packets = 0;
sp->resent_packets = 0;
sp->average_setup_time = 0;
sp->max_setup_time = 0;
sp->min_setup_time = 0;
sp->no_of_completed_calls = 0;
sp->total_setup_time = 0;
g_hash_table_foreach( sp->hash_responses, (GHFunc)sip_reset_hash_responses, NULL);
g_hash_table_foreach( sp->hash_requests, (GHFunc)sip_reset_hash_requests, NULL);
}
}
static int
sipstat_packet(void *psp, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *pri)
{
const sip_info_value_t *value=pri;
sipstat_t *sp = (sipstat_t *)psp;
sp->packets++;
if (value->setup_time){
sp->no_of_completed_calls++;
if ( sp->total_setup_time == 0 ){
sp->average_setup_time = value->setup_time;
sp->total_setup_time = value->setup_time;
sp->max_setup_time = value->setup_time;
sp->min_setup_time = value->setup_time;
}else{
sp->total_setup_time = sp->total_setup_time + value->setup_time;
if (sp->max_setup_time < value->setup_time){
sp->max_setup_time = value->setup_time;
}
if (sp->min_setup_time > value->setup_time){
sp->min_setup_time = value->setup_time;
}
sp->average_setup_time = (guint32)(sp->total_setup_time / sp->no_of_completed_calls);
}
}
if (value->resend)
{
sp->resent_packets++;
}
if (value->response_code != 0)
{
guint *key = g_malloc(sizeof(guint));
sip_response_code_t *sc;
*key = value->response_code;
sc = g_hash_table_lookup(sp->hash_responses, key);
if (sc==NULL)
{
int i = value->response_code;
if ((i<100) || (i>=700))
{
return 0;
}
else if (i<200)
{
*key=199;
}
else if (i<300)
{
*key=299;
}
else if (i<400)
{
*key=399;
}
else if (i<500)
{
*key=499;
}
else if (i<600)
{
*key=599;
}
else
{
*key = 699;
}
sc = g_hash_table_lookup(sp->hash_responses, key);
if (sc==NULL)
{
return 0;
}
}
sc->packets++;
}
else if (value->request_method)
{
sip_request_method_t *sc;
sc = g_hash_table_lookup(sp->hash_requests, value->request_method);
if (sc == NULL)
{
sc=g_malloc(sizeof(sip_request_method_t));
sc->response = g_strdup(value->request_method);
sc->packets = 1;
sc->sp = sp;
g_hash_table_insert(sp->hash_requests, sc->response, sc);
}
else
{
sc->packets++;
}
}
else
{
return 0;
}
return 1;
}
static void
sipstat_draw(void *psp )
{
sipstat_t *sp=psp;
printf("\n");
printf("===================================================================\n");
if (sp->filter == NULL)
printf("SIP Statistics\n");
else
printf("SIP Statistics with filter %s\n", sp->filter);
printf("\nNumber of SIP messages: %d", sp->packets);
printf("\nNumber of resent SIP messages: %d\n", sp->resent_packets);
printf( "\n* SIP Status Codes in reply packets\n");
g_hash_table_foreach( sp->hash_responses, (GHFunc)sip_draw_hash_responses,
" SIP %3d %-15s : %5d Packets\n");
printf("\n* List of SIP Request methods\n");
g_hash_table_foreach( sp->hash_requests, (GHFunc)sip_draw_hash_requests,
" %-15s : %5d Packets\n");
printf( "\n* Average setup time %d ms\n Min %d ms\n Max %d ms\n", sp->average_setup_time, sp->min_setup_time, sp->max_setup_time);
printf("===================================================================\n");
}
static void
sipstat_init(const char *optarg, void* userdata _U_)
{
sipstat_t *sp;
const char *filter=NULL;
GString *error_string;
if (strncmp (optarg, "sip,stat,", 9) == 0){
filter=optarg+9;
} else {
filter=NULL;
}
sp = g_malloc( sizeof(sipstat_t) );
if(filter){
sp->filter=g_strdup(filter);
} else {
sp->filter=NULL;
}
error_string = register_tap_listener(
"sip",
sp,
filter,
0,
sipstat_reset,
sipstat_packet,
sipstat_draw);
if (error_string){
g_free(sp->filter);
g_free(sp);
fprintf (stderr, "tshark: Couldn't register sip,stat tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
sp->packets = 0;
sp->resent_packets = 0;
sip_init_hash(sp);
}
void
register_tap_listener_sipstat(void)
{
register_stat_cmd_arg("sip,stat", sipstat_init,NULL);
}
