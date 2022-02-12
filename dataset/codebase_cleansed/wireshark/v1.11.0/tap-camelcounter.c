static void camelcounter_reset(void *phs)
{
struct camelcounter_t * p_counter= ( struct camelcounter_t *) phs;
memset(p_counter,0,sizeof(struct camelcounter_t));
}
static int camelcounter_packet(void *phs,
packet_info *pinfo _U_,
epan_dissect_t *edt _U_,
const void *phi)
{
struct camelcounter_t * p_counter =(struct camelcounter_t *)phs;
const struct camelsrt_info_t * pi=(const struct camelsrt_info_t *)phi;
if (pi->opcode != 255)
p_counter->camel_msg[pi->opcode]++;
return 1;
}
static void camelcounter_draw(void *phs)
{
struct camelcounter_t * p_counter= (struct camelcounter_t *)phs;
int i;
printf("\n");
printf("CAMEL Message and Response Status Counter:\n");
printf("------------------------------------------\n");
for(i=0;i<camel_MAX_NUM_OPR_CODES;i++) {
if(p_counter->camel_msg[i]!=0) {
printf("%30s ", val_to_str(i,camel_opr_code_strings,"Unknown message "));
printf("%6d\n", p_counter->camel_msg[i]);
}
}
printf("------------------------------------------\n");
}
static void camelcounter_init(const char *opt_arg, void* userdata _U_)
{
struct camelcounter_t *p_camelcounter;
GString *error_string;
p_camelcounter = g_new(struct camelcounter_t,1);
if(!strncmp(opt_arg,"camel,counter,",13)){
p_camelcounter->filter=g_strdup(opt_arg+13);
} else {
p_camelcounter->filter=NULL;
}
camelcounter_reset(p_camelcounter);
error_string=register_tap_listener("CAMEL",
p_camelcounter,
p_camelcounter->filter,
0,
NULL,
camelcounter_packet,
camelcounter_draw);
if(error_string){
g_free(p_camelcounter->filter);
g_free(p_camelcounter);
fprintf(stderr, "tshark: Couldn't register camel,counter tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_camelcounter(void)
{
register_stat_cmd_arg("camel,counter", camelcounter_init, NULL);
}
