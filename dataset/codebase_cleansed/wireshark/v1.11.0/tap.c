void
tap_init(void)
{
tap_packet_index=0;
return;
}
int
register_tap(const char *name)
{
tap_dissector_t *td, *tdl;
int i, tap_id;
if(tap_dissector_list){
tap_id=find_tap_id(name);
if (tap_id)
return tap_id;
}
td=(tap_dissector_t *)g_malloc(sizeof(tap_dissector_t));
td->next=NULL;
td->name = g_strdup(name);
if(!tap_dissector_list){
tap_dissector_list=td;
i=1;
} else {
for(i=2,tdl=tap_dissector_list;tdl->next;i++,tdl=tdl->next)
;
tdl->next=td;
}
return i;
}
void
tap_queue_packet(int tap_id, packet_info *pinfo, const void *tap_specific_data)
{
tap_packet_t *tpt;
if(!tapping_is_active){
return;
}
if(tap_packet_index >= TAP_PACKET_QUEUE_LEN){
g_warning("Too many taps queued");
return;
}
tpt=&tap_packet_array[tap_packet_index];
tpt->tap_id=tap_id;
tpt->pinfo=pinfo;
tpt->tap_specific_data=tap_specific_data;
tap_packet_index++;
}
void tap_build_interesting (epan_dissect_t *edt)
{
tap_listener_t *tl;
if(!tap_listener_queue){
return;
}
for(tl=(tap_listener_t *)tap_listener_queue;tl;tl=tl->next){
if(tl->code){
epan_dissect_prime_dfilter(edt, tl->code);
}
}
}
void
tap_queue_init(epan_dissect_t *edt)
{
if(!tap_listener_queue){
return;
}
tapping_is_active=TRUE;
tap_packet_index=0;
tap_build_interesting (edt);
}
void
tap_push_tapped_queue(epan_dissect_t *edt)
{
tap_packet_t *tp;
tap_listener_t *tl;
guint i;
if(!tapping_is_active){
return;
}
tapping_is_active=FALSE;
if(!tap_packet_index){
return;
}
for(i=0;i<tap_packet_index;i++){
for(tl=(tap_listener_t *)tap_listener_queue;tl;tl=tl->next){
tp=&tap_packet_array[i];
if(tp->tap_id==tl->tap_id){
gboolean passed=TRUE;
if(tl->code){
passed=dfilter_apply_edt(tl->code, edt);
}
if(passed && tl->packet){
tl->needs_redraw|=tl->packet(tl->tapdata, tp->pinfo, edt, tp->tap_specific_data);
}
}
}
}
}
const void *
fetch_tapped_data(int tap_id, int idx)
{
tap_packet_t *tp;
guint i;
if(!tapping_is_active){
return NULL;
}
if(!tap_packet_index){
return NULL;
}
for(i=0;i<tap_packet_index;i++){
tp=&tap_packet_array[i];
if(tp->tap_id==tap_id){
if(!idx--){
return tp->tap_specific_data;
}
}
}
return NULL;
}
void
reset_tap_listeners(void)
{
tap_listener_t *tl;
for(tl=(tap_listener_t *)tap_listener_queue;tl;tl=tl->next){
if(tl->reset){
tl->reset(tl->tapdata);
}
tl->needs_redraw=TRUE;
}
}
void
draw_tap_listeners(gboolean draw_all)
{
tap_listener_t *tl;
for(tl=(tap_listener_t *)tap_listener_queue;tl;tl=tl->next){
if(tl->needs_redraw || draw_all){
if(tl->draw){
tl->draw(tl->tapdata);
}
}
tl->needs_redraw=FALSE;
}
}
int
find_tap_id(const char *name)
{
tap_dissector_t *td;
int i;
for(i=1,td=tap_dissector_list;td;i++,td=td->next) {
if(!strcmp(td->name,name)){
return i;
}
}
return 0;
}
GString *
register_tap_listener(const char *tapname, void *tapdata, const char *fstring,
guint flags, tap_reset_cb reset, tap_packet_cb packet, tap_draw_cb draw)
{
tap_listener_t *tl;
int tap_id;
GString *error_string;
tap_id=find_tap_id(tapname);
if(!tap_id){
error_string = g_string_new("");
g_string_printf(error_string, "Tap %s not found", tapname);
return error_string;
}
tl=(tap_listener_t *)g_malloc(sizeof(tap_listener_t));
tl->code=NULL;
tl->needs_redraw=TRUE;
tl->flags=flags;
if(fstring){
if(!dfilter_compile(fstring, &tl->code)){
error_string = g_string_new("");
g_string_printf(error_string,
"Filter \"%s\" is invalid - %s",
fstring, dfilter_error_msg);
g_free(tl);
return error_string;
}
}
tl->tap_id=tap_id;
tl->tapdata=tapdata;
tl->reset=reset;
tl->packet=packet;
tl->draw=draw;
tl->next=(tap_listener_t *)tap_listener_queue;
tap_listener_queue=tl;
return NULL;
}
GString *
set_tap_dfilter(void *tapdata, const char *fstring)
{
tap_listener_t *tl=NULL,*tl2;
GString *error_string;
if(!tap_listener_queue){
return NULL;
}
if(tap_listener_queue->tapdata==tapdata){
tl=(tap_listener_t *)tap_listener_queue;
} else {
for(tl2=(tap_listener_t *)tap_listener_queue;tl2->next;tl2=tl2->next){
if(tl2->next->tapdata==tapdata){
tl=tl2->next;
break;
}
}
}
if(tl){
if(tl->code){
dfilter_free(tl->code);
tl->code=NULL;
}
tl->needs_redraw=TRUE;
if(fstring){
if(!dfilter_compile(fstring, &tl->code)){
error_string = g_string_new("");
g_string_printf(error_string,
"Filter \"%s\" is invalid - %s",
fstring, dfilter_error_msg);
return error_string;
}
}
}
return NULL;
}
void
remove_tap_listener(void *tapdata)
{
tap_listener_t *tl=NULL,*tl2;
if(!tap_listener_queue){
return;
}
if(tap_listener_queue->tapdata==tapdata){
tl=(tap_listener_t *)tap_listener_queue;
tap_listener_queue=tap_listener_queue->next;
} else {
for(tl2=(tap_listener_t *)tap_listener_queue;tl2->next;tl2=tl2->next){
if(tl2->next->tapdata==tapdata){
tl=tl2->next;
tl2->next=tl2->next->next;
break;
}
}
}
if(tl){
if(tl->code){
dfilter_free(tl->code);
}
g_free(tl);
}
return;
}
gboolean
tap_listeners_require_dissection(void)
{
volatile tap_listener_t *tap_queue = tap_listener_queue;
while(tap_queue) {
if(!(tap_queue->flags & TL_IS_DISSECTOR_HELPER))
return TRUE;
tap_queue = tap_queue->next;
}
return FALSE;
}
gboolean
have_tap_listener(int tap_id)
{
volatile tap_listener_t *tap_queue = tap_listener_queue;
while(tap_queue) {
if(tap_queue->tap_id == tap_id)
return TRUE;
tap_queue = tap_queue->next;
}
return FALSE;
}
gboolean
have_filtering_tap_listeners(void)
{
tap_listener_t *tl;
for(tl=(tap_listener_t *)tap_listener_queue;tl;tl=tl->next){
if(tl->code)
return TRUE;
}
return FALSE;
}
guint
union_of_tap_listener_flags(void)
{
tap_listener_t *tl;
guint flags = 0;
for(tl=(tap_listener_t *)tap_listener_queue;tl;tl=tl->next){
flags|=tl->flags;
}
return flags;
}
