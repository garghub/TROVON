int dispatcher_debug(int level, const char* fmt, ...) {
va_list ap;
char* str;
if (debug_lvl<level) return 1;
va_start(ap, fmt);
str = g_strdup_vprintf(fmt,ap);
va_end(ap);
if (dispatcher) {
fprintf(debug_fp, "dispatcher[%d]: reqh_id=%d dbg_level=%d message='%s'\n", dispatcher->pid, dispatcher->reqh_id, level, str);
} else {
fprintf(debug_fp, "dispatcher: dbg_level=%d message='%s'\n", level, str);
}
fflush(debug_fp);
g_free(str);
return 1;
}
static char* param_get_dbg_level(char** err _U_) {
return g_strdup_printf("%d",debug_lvl);
}
static echld_bool_t param_set_dbg_level(char* val , char** err ) {
char* p;
int lvl = (int)strtol(val, &p, 10);
if (p<=val) {
*err = g_strdup("not an integer");
return FALSE;
} else if (lvl < 0 || lvl > 5) {
*err = g_strdup_printf("invalid level=%d (min=0 max=5)",lvl);
return FALSE;
}
debug_lvl = lvl;
DCOM();
return TRUE;
}
static void init_stuff(void) {
#ifdef HAVE_LIBPCAP
capture_opts_init(&stuff.cap_opts);
capture_session_init(&stuff.cap_sess, (void *)&stuff.cfile);
#endif
}
static void children_massacre(void) {
int i;
struct dispatcher_child* cc = dispatcher->children;
int max_children = dispatcher->max_children;
for(i = 0; i < max_children; i++) {
struct dispatcher_child* c = &(cc[i]);
if (c->pid > 0) {
DISP_DBG((0,"killing ch=%d pid=%d",c->chld_id,c->pid));
kill(c->pid,SIGTERM);
}
}
}
static void dispatcher_fatal(int cause, const char* fmt, ...) {
size_t len= 1024;
gchar err_str[len];
va_list ap;
va_start(ap, fmt);
g_vsnprintf(err_str,len,fmt,ap);
va_end(ap);
DISP_DBG((0,"fatal cause=%d msg=\"%s\"",cause ,err_str));
children_massacre();
exit(cause);
}
static void dispatcher_err(int errnum, const char* fmt, ...) {
size_t len= 1024;
gchar err_str[len];
va_list ap;
static GByteArray* ba;
va_start(ap, fmt);
g_vsnprintf(err_str,len,fmt,ap);
va_end(ap);
DISP_DBG((0,"error=\"%s\"",err_str));
ba = dispatcher->enc.to_parent->error(errnum, err_str);
DISP_RESP(ba,ECHLD_ERROR);
g_byte_array_free(ba,TRUE);
}
static char* intflist2json(GList* if_list, char** if_cap_err) {
#define ADDRSTRLEN 46
int i;
GList *if_entry;
if_info_t *if_info;
GSList *addr;
if_addr_t *if_addr;
if_capabilities_t *caps;
char addr_str[ADDRSTRLEN];
GString *str = g_string_new("{ what='interfaces', interfaces={ \n");
char* s;
i = 1;
for (if_entry = g_list_first(if_list); if_entry != NULL;
if_entry = g_list_next(if_entry)) {
if_info = (if_info_t *)if_entry->data;
g_string_append_printf(str," %s={ intf='%s',", if_info->name, if_info->name);
if (if_info->vendor_description != NULL)
g_string_append_printf(str," vnd_desc='%s',", if_info->vendor_description);
if (if_info->friendly_name != NULL)
g_string_append_printf(str," name='%s', addrs=[ ", if_info->friendly_name);
for (addr = g_slist_nth(if_info->addrs, 0); addr != NULL;
addr = g_slist_next(addr)) {
if_addr = (if_addr_t *)addr->data;
switch(if_addr->ifat_type) {
case IF_AT_IPv4:
if (inet_ntop(AF_INET, &if_addr->addr.ip4_addr, addr_str,
ADDRSTRLEN)) {
g_string_append_printf(str,"'%s',", addr_str);
} else {
g_string_append(str,"'<unknown IPv4>',");
}
break;
case IF_AT_IPv6:
if (inet_ntop(AF_INET6, &if_addr->addr.ip6_addr,
addr_str, ADDRSTRLEN)) {
g_string_append_printf(str,"'%s',", addr_str);
} else {
g_string_append(str,"'<unknown IPv6>',");
}
break;
default:
g_string_append_printf(str,"'<type unknown %u>',", if_addr->ifat_type);
}
}
g_string_truncate(str,str->len - 1);
g_string_append(str," ]");
if (if_info->loopback)
g_string_append(str,", loopback=1");
else
g_string_append(str,", loopback=0");
caps = capture_get_if_capabilities(if_info->name, 0, if_cap_err, NULL);
if (caps != NULL) {
if (caps->data_link_types != NULL) {
GList* lt_entry = caps->data_link_types;
data_link_info_t *data_link_info;
g_string_append(str,", data_link_types=[");
for (; lt_entry != NULL; lt_entry = g_list_next(lt_entry) ) {
data_link_info = (data_link_info_t *)lt_entry->data;
g_string_append_printf(str,"{ name='%s', desc='%s' }, ", data_link_info->name, (data_link_info->description) ? data_link_info->description : "" );
}
g_string_truncate(str,str->len - 2);
g_string_append(str,"]");
}
g_string_append_printf(str,", can_set_rfmon=%s", caps->can_set_rfmon ? "1" : "0");
if (caps->can_set_rfmon) {
free_if_capabilities(caps);
caps = capture_get_if_capabilities(if_info->name, 1, if_cap_err, NULL);
if (caps->data_link_types != NULL) {
GList* lt_entry = caps->data_link_types;
data_link_info_t *data_link_info;
g_string_append(str,", data_link_types_rfmon=[");
for (; lt_entry != NULL; lt_entry = g_list_next(lt_entry)) {
data_link_info = (data_link_info_t *)lt_entry->data;
g_string_append_printf(str,"{ name='%s', desc='%s' }, ", data_link_info->name, (data_link_info->description) ? data_link_info->description : "" );
}
g_string_truncate(str,str->len - 2);
g_string_append(str,"]");
}
}
free_if_capabilities(caps);
}
g_string_append(str,"},\n");
}
g_string_truncate(str,str->len - 2);
g_string_append(str,"}");
s=str->str;
g_string_free(str,FALSE);
return s;
}
static void get_interfaces(char** err) {
int err_no = 0;
GList* if_list;
err = NULL;
if_list = capture_interface_list(&err_no, err, NULL);
if (err) {
DISP_DBG((1,"Could not get capture interface list: %s",err));
} else {
intf_list = intflist2json(if_list,err);
if (err) {
DISP_DBG((1,"get capabilities error: %s",err));
}
}
free_interface_list(if_list);
}
static char* param_get_interfaces(char** err _U_) {
return g_strdup(intf_list ? intf_list : "");
}
static char* param_get_loop_timeout(char** err _U_) {
return g_strdup_printf("%fs", (((float)disp_loop_timeout_usec)/1000000.0) );
}
static echld_bool_t param_set_loop_timeout(char* val , char** err ) {
char* p;
int usec = (int)strtol(val, &p, 10);
if (p<=val) {
*err = g_strdup("not an integer");
return FALSE;
}
disp_loop_timeout_usec = usec;
return TRUE;
}
static char* param_get_long_version(char** err _U_) {
return g_strdup(version_long_str);
}
static char* param_get_version(char** err _U_) {
return g_strdup(version_str);
}
static char* param_get_capture_types(char** err _U_) {
GString* str = g_string_new("");
char* s;
int i;
for (i = 0; i < WTAP_NUM_FILE_TYPES; i++) {
if (wtap_dump_can_open(i)) {
g_string_append_printf(str,"%s: %s\n",
wtap_file_type_short_string(i), wtap_file_type_string(i));
}
}
s = str->str;
g_string_free(str,FALSE);
return s;
}
static echld_bool_t param_set_add_hosts_file(char* val, char** err) {
if (add_hosts_file(val)) {
return TRUE;
} else {
*err = g_strdup_printf("Can't read host entries from \"%s\"",val);
return FALSE;
}
}
static echld_bool_t param_set_x_opt(char* val, char** err) {
if (ex_opt_add(val)) {
return TRUE;
} else {
*err = g_strdup_printf("Cannot set X opt '%s'",val);
return FALSE;
}
}
static char* param_get_params(char** err _U_) {
return paramset_get_params_list(disp_params,PARAM_LIST_FMT);
}
static struct dispatcher_child* dispatcher_get_child(struct dispatcher* d, int chld_id) {
int i;
struct dispatcher_child* cc = d->children;
int max_children = d->max_children;
for(i = 0; i < max_children; i++) {
struct dispatcher_child* c = &(cc[i]);
if (c->chld_id == chld_id) return c;
}
return NULL;
}
static void dispatcher_clear_child(struct dispatcher_child* c) {
echld_reset_reader(&(c->reader), -1, 4096);
c->chld_id = -1;
c->state = FREE;
c->reader.fd = -1;
c->write_fd = -1;
c->pid = -1;
c->reqh_id = -1;
c->closing = FALSE;
}
static void set_dumpcap_pid(int pid) {
dispatcher->dumpcap_pid = pid;
}
static void dispatcher_clear(void) {
DISP_DBG((2,"dispatcher_clear"));
}
void dispatcher_sig(int sig) {
DISP_FATAL((TERMINATED,"SIG sig=%d",sig));
exit(1);
}
void dispatcher_reaper(int sig) {
int status;
int i;
struct dispatcher_child* cc = dispatcher->children;
int max_children = dispatcher->max_children;
int pid = waitpid(-1, &status, WNOHANG);
int reqh_id_save = dispatcher->reqh_id;
dispatcher->reqh_id = 0;
if (sig != SIGCHLD) {
DISP_DBG((1,"Reaper got wrong signal=%d",sig));
dispatcher->reqh_id = reqh_id_save;
return;
}
DISP_DBG((2,"Child dead pid=%d",pid));
for(i = 0; i < max_children; i++) {
struct dispatcher_child* c = &(cc[i]);
if ( c->pid == pid ) {
if (c->closing || dispatcher->closing) {
DISP_WRITE(dispatcher->parent_out, NULL, c->chld_id, ECHLD_CLOSING, c->reqh_id);
} else {
char* s = NULL;
GByteArray* em;
if (WIFEXITED(status)) {
s = g_strdup_printf(
"Unexpected dead: reason='exited' pid=%d status=%d",
pid, WEXITSTATUS(status));
} else if ( WIFSIGNALED(status) ) {
s = g_strdup_printf(
"Unexpected dead: reason='signaled' pid=%d termsig=%d coredump=%s",
pid, WTERMSIG(status), WCOREDUMP(status) ? "yes":"no");
} else if (WIFSTOPPED(status)) {
s = g_strdup_printf(
"Unexpected dead: reason='stopped' pid=%d stopsig=%d",
pid, WSTOPSIG(status));
}
em = dispatcher->enc.to_parent->child_dead(s);
dispatcher_err(ECHLD_ERR_CRASHED_CHILD, s);
if (s) g_free(s);
DISP_WRITE(dispatcher->parent_out, em, c->chld_id, ECHLD_CHILD_DEAD, 0);
if (em) g_byte_array_free(em,TRUE);
}
CHLD_SET_STATE(c,CLOSED);
dispatcher_clear_child(c);
dispatcher->reqh_id = reqh_id_save;
return;
}
}
if (pid == dispatcher->dumpcap_pid) {
dispatcher->dumpcap_pid = 0;
dispatcher->reqh_id = reqh_id_save;
DISP_DBG((2,"dumpcap dead pid=%d",pid));
return;
}
dispatcher_err(ECHLD_ERR_UNKNOWN_PID, "Unkown child pid: %d", pid);
dispatcher->reqh_id = reqh_id_save;
}
static void dispatcher_destroy(void) {
dispatcher->closing = TRUE;
children_massacre();
exit(0);
}
static long dispatch_to_parent(guint8* b, size_t len, echld_chld_id_t chld_id, echld_msg_type_t type, echld_reqh_id_t reqh_id, void* data) {
GByteArray in_ba;
struct dispatcher_child* c = (struct dispatcher_child*)data;
dispatcher->reqh_id = c->reqh_id = reqh_id;
in_ba.data = b;
in_ba.len = (guint)len;
if (chld_id != c->chld_id) {
goto misbehabing;
}
switch(type) {
case ECHLD_ERROR: break;
case ECHLD_TIMED_OUT: break;
case ECHLD_HELLO: CHLD_SET_STATE(c,IDLE); break;
case ECHLD_CLOSING:
c->closing = TRUE;
CHLD_SET_STATE(c,CLOSING);
break;
case ECHLD_PARAM: break;
case ECHLD_PONG: break;
case ECHLD_FILE_OPENED: CHLD_SET_STATE(c,READING); break;
case ECHLD_INTERFACE_OPENED: CHLD_SET_STATE(c,READY); break;
case ECHLD_CAPTURE_STARTED: CHLD_SET_STATE(c,CAPTURING); break;
case ECHLD_NOTIFY: break;
case ECHLD_PACKET_SUM: break;
case ECHLD_TREE: break;
case ECHLD_BUFFER: break;
case ECHLD_EOF:
case ECHLD_CAPTURE_STOPPED: CHLD_SET_STATE(c,DONE); break;
case ECHLD_NOTE_ADDED: break;
case ECHLD_PACKET_LIST: break;
case ECHLD_FILE_SAVED: break;
default:
goto misbehabing;
}
DISP_DBG((4,"Dispatching to parent reqh_id=%d chld_id=%d type='%c'",reqh_id,c->chld_id,type));
return DISP_WRITE(dispatcher->parent_out, &in_ba, chld_id, type, reqh_id);
misbehabing:
CHLD_SET_STATE(c,ERRORED);
c->closing = TRUE;
kill(c->pid,SIGTERM);
dispatcher_err(ECHLD_ERR_CRASHED_CHILD,"chld_id=%d",chld_id);
return 0;
}
static void detach_new_child(enc_msg_t* em, echld_chld_id_t chld_id) {
struct dispatcher_child* c;
int reqh_id = dispatcher->reqh_id;
int pid;
if (( c = dispatcher_get_child(dispatcher, chld_id) )) {
dispatcher_err(ECHLD_ERR_CHILD_EXISTS,"chld_id=%d exists already while creating new child",chld_id);
return;
} else if (( c = dispatcher_get_child(dispatcher, -1) )) {
int disp_pipe_fds[2];
int child_pipe_fds[2];
int pipe_to_disp;
int pipe_from_disp;
int pipe_to_child;
int pipe_from_child;
DISP_DBG((5,"new_child pipe(dispatcher)"));
if( pipe(disp_pipe_fds) < 0) {
dispatcher_err(ECHLD_ERR_CANNOT_FORK,"CANNOT OPEN PARENT PIPE: %s",strerror(errno));
return;
}
pipe_from_disp = disp_pipe_fds[0];
pipe_to_child = disp_pipe_fds[1];
DISP_DBG((5,"new_child pipe(child)"));
if( pipe(child_pipe_fds) < 0) {
close(pipe_from_disp);
close(pipe_to_child);
dispatcher_err(ECHLD_ERR_CANNOT_FORK,"CANNOT OPEN CHILD PIPE: %s",strerror(errno));
return;
}
pipe_from_child = child_pipe_fds[0];
pipe_to_disp = child_pipe_fds[1];
DISP_DBG((4,"New Child Forking()"));
switch (( pid = fork() )) {
case -1: {
close(pipe_to_child);
close(pipe_to_disp);
close(pipe_from_child);
close(pipe_from_disp);
dispatcher_err(ECHLD_ERR_CANNOT_FORK,"CANNOT FORK: %s",strerror(errno));
return;
}
case 0: {
dispatcher_clear();
close(pipe_to_child);
close(pipe_from_child);
echld_child_initialize(chld_id, pipe_from_disp,pipe_to_disp,reqh_id,&stuff);
exit( echld_child_loop() );
return;
}
default: {
close(pipe_to_disp);
close(pipe_from_disp);
echld_reset_reader(&(c->reader), pipe_from_child,4096);
c->write_fd = pipe_to_child;
c->pid = pid;
c->chld_id = chld_id;
c->closing = FALSE;
CHLD_SET_STATE(c,CREATING);
DISP_DBG((4,"Child Forked pid=%d chld_id=%d from_fd=%d to_fd=%d",
pid, c->chld_id, pipe_from_child, pipe_to_child));
start_wait_time.tv_sec = (int)(start_wait_time_us / 1000000);
start_wait_time.tv_usec = (int)(start_wait_time_us % 1000000);
select(0,NULL,NULL,NULL,&start_wait_time);
DISP_WRITE(pipe_to_child, em, c->chld_id, ECHLD_NEW_CHILD, dispatcher->reqh_id);
return;
}
}
} else {
dispatcher_err(ECHLD_ERR_CANNOT_FORK, "MAX CHILDREN REACHED: max_children=%d",dispatcher->max_children);
return;
}
}
static long dispatch_to_child(guint8* b, size_t len, echld_chld_id_t chld_id, echld_msg_type_t type, echld_reqh_id_t reqh_id, void* data _U_) {
GByteArray in_ba;
in_ba.data = b;
in_ba.len = (guint)len;
dispatcher->reqh_id = reqh_id;
DISP_DBG((1,"RCV<- type='%s' chld_id=%d reqh_id=%d",TY(type),chld_id,reqh_id));
if (chld_id == 0) {
DISP_DBG((2,"Message to Dispatcher"));
switch(type) {
case ECHLD_CLOSE_CHILD:
dispatcher_destroy();
return 0;
case ECHLD_PING:
DISP_DBG((2,"PONG reqh_id=%d",reqh_id));
DISP_WRITE(dispatcher->parent_out, NULL, chld_id, ECHLD_PONG, reqh_id);
return 0;
case ECHLD_SET_PARAM:{
char* param;
char* value;
if ( dispatcher->dec.from_parent->set_param(b,len,&param,&value) ) {
GByteArray* ba;
char* err;
if (! paramset_apply_set (disp_params, param, value, &err) ) {
dispatcher_err(ECHLD_CANNOT_SET_PARAM,"%s",err);
g_free(err);
return 0;
}
ba = dispatcher->enc.to_parent->param(param,value);
DISP_RESP(ba,ECHLD_PARAM);
g_byte_array_free(ba,TRUE);
DISP_DBG((1,"Set Param: param='%s' value='%s'",param,value));
return 0;
} else {
dispatcher_err(ECHLD_CANNOT_SET_PARAM,"reason='decoder error'");
return 0;
}
}
case ECHLD_GET_PARAM: {
GByteArray* ba;
char* param;
if ( dispatcher->dec.from_parent->get_param(b,len,&param) ) {
char* err;
char* val;
if (! (val = paramset_apply_get (disp_params, param, &err)) ) {
dispatcher_err(ECHLD_CANNOT_GET_PARAM,"%s",err);
g_free(err);
return 0;
}
ba = dispatcher->enc.to_parent->param(param,val);
DISP_RESP(ba,ECHLD_PARAM);
g_byte_array_free(ba,TRUE);
DISP_DBG((1,"Get Param: param='%s' value='%s'",param,val));
return 0;
} else {
dispatcher_err(ECHLD_CANNOT_GET_PARAM,"reason='decoder error'");
return 0;
}
}
default:
dispatcher_err(ECHLD_ERR_WRONG_MSG, "wrong message to dispatcher type='%c'", type);
return 0;
}
} else {
struct dispatcher_child* c;
DISP_DBG((2,"Parent => Child"));
if (! (c = dispatcher_get_child(dispatcher, chld_id)) ) {
if (type == ECHLD_NEW_CHILD) {
detach_new_child(&in_ba,chld_id);
return 0;
} else {
dispatcher_err(ECHLD_ERR_NO_SUCH_CHILD, "wrong chld_id %d", chld_id);
return 0;
}
} else {
switch(type) {
case ECHLD_CLOSE_CHILD:
CHLD_SET_STATE(c,CLOSED);
goto relay_frame;
case ECHLD_OPEN_FILE:
CHLD_SET_STATE(c,READING);
goto relay_frame;
case ECHLD_OPEN_INTERFACE:
CHLD_SET_STATE(c,READY);
goto relay_frame;
case ECHLD_START_CAPTURE:
CHLD_SET_STATE(c,CAPTURING);
goto relay_frame;
case ECHLD_STOP_CAPTURE:
CHLD_SET_STATE(c,DONE);
goto relay_frame;
case ECHLD_SAVE_FILE:
case ECHLD_APPLY_FILTER:
case ECHLD_SET_PARAM:
case ECHLD_GET_PARAM:
case ECHLD_PING:
case ECHLD_GET_SUM:
case ECHLD_GET_TREE:
case ECHLD_GET_BUFFER:
case ECHLD_ADD_NOTE:
relay_frame: {
DISP_DBG((3,"Relay to Child chld_id=%d type='%c' req_id=%d",chld_id, type, reqh_id));
return DISP_WRITE(c->write_fd, &in_ba, chld_id, type, reqh_id);
}
default:
dispatcher_err(ECHLD_ERR_WRONG_MSG, "wrong message %d %c", reqh_id, type);
return 0;
}
}
}
}
int dispatcher_loop(void) {
int parent_out = dispatcher->parent_out;
int parent_in = dispatcher->parent_in.fd;
struct dispatcher_child* children = dispatcher->children;
DISP_DBG((5,"LOOP in_fd=%d out_fd=%d",parent_in, parent_out));
do {
fd_set rfds;
fd_set efds;
struct dispatcher_child* c;
int nfds;
int nchld = 0;
struct timeval disp_loop_timeout;
FD_ZERO(&rfds);
FD_ZERO(&efds);
FD_SET(parent_in,&rfds);
FD_SET(parent_in,&efds);
FD_SET(parent_out,&efds);
for (c = children; c->pid; c++) {
if (c->chld_id > 0) {
nchld++;
FD_SET(c->reader.fd, &rfds);
FD_SET(c->reader.fd, &efds);
}
}
DISP_DBG((4,"Select()ing nchld=%d",nchld,disp_loop_timeout.tv_usec));
disp_loop_timeout.tv_sec = (int)(disp_loop_timeout_usec / 1000000);
disp_loop_timeout.tv_usec = (int)(disp_loop_timeout_usec % 1000000);
nfds = select(FD_SETSIZE, &rfds, NULL, &efds, &disp_loop_timeout);
DISP_DBG((5,"Select()ed nfds=%d",nchld,nfds));
if (nfds < 0) {
DISP_DBG((1,"select error='%s'",strerror(errno) ));
continue;
}
if ( FD_ISSET(parent_in, &rfds)) {
long st = echld_read_frame(&(dispatcher->parent_in), dispatch_to_child, dispatcher);
if (st < 0) {
DISP_DBG((1,"read frame returning < 0 for parent"));
continue;
}
}
if ( FD_ISSET(parent_in, &efds) ) {
DISP_DBG((1,"Parent In Pipe Errored!"));
continue;
}
if ( FD_ISSET(parent_out, &efds) ) {
DISP_DBG((1,"Parent Out Pipe Errored!"));
continue;
}
for (c=children; c->pid; c++) {
if (c->reader.fd > 0) {
if ( FD_ISSET(c->reader.fd,&efds) ) {
struct timeval wait_time;
wait_time.tv_sec = 0;
wait_time.tv_usec = DISP_KILLED_CHILD_WAIT;
DISP_DBG((1,"errored child pipe chld_id=%d",c->chld_id));
kill(c->pid,SIGTERM);
select(0,NULL,NULL,NULL,&wait_time);
dispatcher_clear_child(c);
continue;
}
if (FD_ISSET(c->reader.fd,&rfds)) {
long st = echld_read_frame(&(c->reader), dispatch_to_parent, c);
if (st < 0) {
DISP_DBG((1,"read_frame returned < 0 for chld_id=%d",c->chld_id));
continue;
}
continue;
}
}
}
} while(1);
return 1;
}
void dispatcher_alrm(int sig _U_) {
DISP_DBG((1,"ALRM received"));
}
