static void
http_init_hash( httpstat_t *sp)
{
int i;
sp->hash_responses = g_hash_table_new( g_int_hash, g_int_equal);
for (i=0 ; vals_status_code[i].strptr ; i++ )
{
gint *key = g_malloc (sizeof(gint));
http_response_code_t *sc = g_malloc (sizeof(http_response_code_t));
*key = vals_status_code[i].value;
sc->packets=0;
sc->response_code = *key;
sc->name=vals_status_code[i].strptr;
sc->sp = sp;
g_hash_table_insert( sc->sp->hash_responses, key, sc);
}
sp->hash_requests = g_hash_table_new( g_str_hash, g_str_equal);
}
static void
http_draw_hash_requests( gchar *key _U_ , http_request_methode_t *data, gchar * format)
{
if (data->packets==0)
return;
printf( format, data->response, data->packets);
}
static void
http_draw_hash_responses( gint * key _U_ , http_response_code_t *data, char * format)
{
if (data==NULL) {
g_warning("No data available, key=%d\n", *key);
exit(EXIT_FAILURE);
}
if (data->packets==0)
return;
printf(format, data->response_code, data->name, data->packets );
}
static void
http_reset_hash_responses(gchar *key _U_ , http_response_code_t *data, gpointer ptr _U_ )
{
data->packets = 0;
}
static void
http_reset_hash_requests(gchar *key _U_ , http_request_methode_t *data, gpointer ptr _U_ )
{
data->packets = 0;
}
static void
httpstat_reset(void *psp )
{
httpstat_t *sp=psp;
g_hash_table_foreach( sp->hash_responses, (GHFunc)http_reset_hash_responses, NULL);
g_hash_table_foreach( sp->hash_requests, (GHFunc)http_reset_hash_requests, NULL);
}
static int
httpstat_packet(void *psp , packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *pri)
{
const http_info_value_t *value=pri;
httpstat_t *sp=(httpstat_t *) psp;
if (value->response_code!=0) {
guint *key=g_malloc( sizeof(guint) );
http_response_code_t *sc;
*key=value->response_code;
sc = g_hash_table_lookup(
sp->hash_responses,
key);
if (sc==NULL){
int i = value->response_code;
if ((i<100) || (i>=600)) {
return 0;
}
else if (i<200){
*key=199;
}
else if (i<300){
*key=299;
}
else if (i<400){
*key=399;
}
else if (i<500){
*key=499;
}
else{
*key=599;
}
sc = g_hash_table_lookup(
sp->hash_responses,
key);
if (sc==NULL)
return 0;
}
sc->packets++;
}
else if (value->request_method){
http_request_methode_t *sc;
sc = g_hash_table_lookup(
sp->hash_requests,
value->request_method);
if (sc==NULL){
sc=g_malloc( sizeof(http_request_methode_t) );
sc->response=g_strdup( value->request_method );
sc->packets=1;
sc->sp = sp;
g_hash_table_insert( sp->hash_requests, sc->response, sc);
} else {
sc->packets++;
}
} else {
return 0;
}
return 1;
}
static void
httpstat_draw(void *psp )
{
httpstat_t *sp=psp;
printf("\n");
printf("===================================================================\n");
if (! sp->filter[0])
printf("HTTP Statistics\n");
else
printf("HTTP Statistics with filter %s\n", sp->filter);
printf( "* HTTP Status Codes in reply packets\n");
g_hash_table_foreach( sp->hash_responses, (GHFunc)http_draw_hash_responses,
" HTTP %3d %s\n");
printf("* List of HTTP Request methods\n");
g_hash_table_foreach( sp->hash_requests, (GHFunc)http_draw_hash_requests,
" %9s %d \n");
printf("===================================================================\n");
}
static void
gtk_httpstat_init(const char *optarg,void* userdata _U_)
{
httpstat_t *sp;
const char *filter=NULL;
GString *error_string;
if (!strncmp (optarg, "http,stat,", 10)){
filter=optarg+10;
} else {
filter=NULL;
}
sp = g_malloc( sizeof(httpstat_t) );
if(filter){
sp->filter=g_strdup(filter);
} else {
sp->filter=NULL;
}
error_string = register_tap_listener(
"http",
sp,
filter,
0,
httpstat_reset,
httpstat_packet,
httpstat_draw);
if (error_string){
g_free(sp->filter);
g_free(sp);
fprintf (stderr, "tshark: Couldn't register http,stat tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
http_init_hash(sp);
}
void
register_tap_listener_gtkhttpstat(void)
{
register_stat_cmd_arg("http,stat,", gtk_httpstat_init,NULL);
}
