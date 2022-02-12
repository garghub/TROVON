static long timevaldiff(struct timeval *starttime, struct timeval *finishtime) {
long msec;
msec=(finishtime->tv_sec-starttime->tv_sec)*1000;
msec+=(finishtime->tv_usec-starttime->tv_usec)/1000;
return msec;
}
static gboolean pong(echld_msg_type_t type, GByteArray* ba _U_, void* data) {
struct _ping* p = (struct _ping*)data;
struct timeval t;
long ret = -1;
gettimeofday(&t,NULL);
switch (type) {
case ECHLD_PONG:
ret = timevaldiff(&(p->tv),&t);
break;
default:
ret = -1;
break;
}
if (p->cb) p->cb(ret, p->cb_data);
g_free(p);
return TRUE;
}
extern echld_state_t echld_ping(int chld_id, echld_ping_cb_t pcb, void* cb_data) {
struct _ping* p = g_new0(struct _ping,1);
p->cb = pcb;
p->cb_data = cb_data;
gettimeofday(&(p->tv),NULL);
return echld_reqh(chld_id, ECHLD_PING, 0, NULL, pong, p);
}
static gboolean got_param(echld_msg_type_t type, GByteArray* ba _U_, void* data) {
struct _get_param* g = (struct _get_param*)data;
char* err_msg;
switch (type) {
case ECHLD_PARAM:
if (g->cb) {
char* param;
char* value;
g->dec(ba,&param,&value);
g->cb(param,value,NULL,g->cb_data);
}
break;
case ECHLD_ERROR: {
int errnum;
g->dec_err(ba,&errnum,&err_msg);
g->cb(NULL,NULL,err_msg,g->cb_data);
break;
}
default:
err_msg = g_strdup_printf("other type='%s'",TY(type));
g->cb(NULL,NULL,err_msg,g->cb_data);
g_free(err_msg);
break;
}
g_free(g);
return TRUE;
}
extern echld_state_t echld_get_param(int chld_id, const char* param, echld_param_cb_t acb, void* cb_data) {
struct _get_param* g = g_new0(struct _get_param,1);
echld_parent_encoder_t* enc;
parent_decoder_t* dec;
enc_msg_t* em;
echld_get_all_codecs(NULL, NULL, &enc, &dec);
em = enc->get_param(param);
g->name = param;
g->cb = acb;
g->cb_data = cb_data;
g->dec = dec->param;
g->dec_err = dec->error;
return echld_reqh(chld_id, ECHLD_GET_PARAM, 0, em, got_param, g);
}
extern echld_state_t echld_set_param(int chld_id, const char* param, const char* value, echld_param_cb_t acb, void* cb_data) {
struct _get_param* g = g_new0(struct _get_param,1);
echld_parent_encoder_t* enc;
parent_decoder_t* dec;
enc_msg_t* em;
echld_get_all_codecs(NULL, NULL, &enc, &dec);
em = enc->set_param(param,value);
g->name = param;
g->cb = acb;
g->cb_data = cb_data;
g->dec = dec->param;
g->dec_err = dec->error;
return echld_reqh(chld_id, ECHLD_SET_PARAM, 0, em, got_param, g);
}
static gboolean closed(echld_msg_type_t type, GByteArray* ba, void* data) {
close_t* c = (close_t*)data;
parent_decoder_t* dec;
char* err_msg;
echld_get_all_codecs(NULL, NULL, NULL, &dec);
switch (type) {
case ECHLD_CLOSING: {
if (c->cb) {
c->cb(NULL,c->cb_data);
}
break;
}
case ECHLD_ERROR: {
int errnum;
if ( dec->error(ba, &errnum ,&err_msg) ) {
c->cb(err_msg,c->cb_data);
g_free(err_msg);
} else {
c->cb("Canot decode error message",c->cb_data);
}
break;
}
default:
err_msg = g_strdup_printf("other type='%s'",TY(type));
c->cb(err_msg,c->cb_data);
g_free(err_msg);
break;
}
g_free(c);
return TRUE;
}
echld_state_t echld_close(int child_id, echld_close_cb_t pcb, void* cb_data) {
close_t* c = g_new0(close_t,1);
c->cb = pcb;
c->cb_data = cb_data;
return echld_reqh(child_id,ECHLD_CLOSE_CHILD, 0, NULL, closed, c);
}
