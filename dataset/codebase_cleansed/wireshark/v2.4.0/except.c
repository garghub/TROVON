int except_init(void)
{
int retval = 1;
pthread_mutex_lock(&init_mtx);
assert (init_counter < INT_MAX);
if (init_counter++ == 0) {
int top_ok = (pthread_key_create(&top_key, 0) == 0);
int uh_ok = (pthread_key_create(&uh_key, 0) == 0);
int alloc_ok = (pthread_key_create(&alloc_key, 0) == 0);
int dealloc_ok = (pthread_key_create(&dealloc_key, 0) == 0);
if (!top_ok || !uh_ok || !alloc_ok || !dealloc_ok) {
retval = 0;
init_counter = 0;
if (top_ok)
pthread_key_delete(top_key);
if (uh_ok)
pthread_key_delete(uh_key);
if (alloc_ok)
pthread_key_delete(alloc_key);
if (dealloc_ok)
pthread_key_delete(dealloc_key);
}
}
pthread_mutex_unlock(&init_mtx);
return retval;
}
void except_deinit(void)
{
pthread_mutex_lock(&init_mtx);
assert (init_counter > 0);
if (--init_counter == 0) {
pthread_key_delete(top_key);
pthread_key_delete(uh_key);
pthread_key_delete(alloc_key);
pthread_key_delete(dealloc_key);
}
pthread_mutex_unlock(&init_mtx);
}
int except_init(void)
{
assert (init_counter < INT_MAX);
init_counter++;
return 1;
}
void except_deinit(void)
{
assert (init_counter > 0);
init_counter--;
}
static int match(const volatile except_id_t *thrown, const except_id_t *caught)
{
int group_match = (caught->except_group == XCEPT_GROUP_ANY ||
caught->except_group == thrown->except_group);
int code_match = (caught->except_code == XCEPT_CODE_ANY ||
caught->except_code == thrown->except_code);
return group_match && code_match;
}
WS_NORETURN static void do_throw(except_t *except)
{
struct except_stacknode *top;
assert (except->except_id.except_group != 0 &&
except->except_id.except_code != 0);
for (top = get_top(); top != 0; top = top->except_down) {
if (top->except_type == XCEPT_CLEANUP) {
top->except_info.except_cleanup->except_func(top->except_info.except_cleanup->except_context);
} else {
struct except_catch *catcher = top->except_info.except_catcher;
const except_id_t *pi = catcher->except_id;
size_t i;
assert (top->except_type == XCEPT_CATCHER);
except_free(catcher->except_obj.except_dyndata);
for (i = 0; i < catcher->except_size; pi++, i++) {
if (match(&except->except_id, pi)) {
catcher->except_obj = *except;
set_top(top);
longjmp(catcher->except_jmp, 1);
}
}
}
}
set_top(top);
get_catcher()(except);
abort();
}
static void unhandled_catcher(except_t *except)
{
if (except->except_message == NULL) {
fprintf(stderr, "Unhandled exception (group=%lu, code=%lu)\n",
except->except_id.except_group,
except->except_id.except_code);
} else {
fprintf(stderr, "Unhandled exception (\"%s\", group=%lu, code=%lu)\n",
except->except_message, except->except_id.except_group,
except->except_id.except_code);
}
abort();
}
static void stack_push(struct except_stacknode *node)
{
node->except_down = get_top();
set_top(node);
}
void except_setup_clean(struct except_stacknode *esn,
struct except_cleanup *ecl, void (*cleanf)(void *), void *context)
{
esn->except_type = XCEPT_CLEANUP;
ecl->except_func = cleanf;
ecl->except_context = context;
esn->except_info.except_cleanup = ecl;
stack_push(esn);
}
void except_setup_try(struct except_stacknode *esn,
struct except_catch *ech, const except_id_t id[], size_t size)
{
ech->except_id = id;
ech->except_size = size;
ech->except_obj.except_dyndata = 0;
esn->except_type = XCEPT_CATCHER;
esn->except_info.except_catcher = ech;
stack_push(esn);
}
struct except_stacknode *except_pop(void)
{
struct except_stacknode *top = get_top();
set_top(top->except_down);
return top;
}
WS_NORETURN void except_rethrow(except_t *except)
{
struct except_stacknode *top = get_top();
assert (top != 0);
assert (top->except_type == XCEPT_CATCHER);
assert (&top->except_info.except_catcher->except_obj == except);
set_top(top->except_down);
do_throw(except);
}
WS_NORETURN void except_throw(long group, long code, const char *msg)
{
except_t except;
except.except_id.except_group = group;
except.except_id.except_code = code;
except.except_message = msg;
except.except_dyndata = 0;
#ifdef _WIN32
if (code == DissectorError && IsDebuggerPresent()) {
DebugBreak();
}
#endif
do_throw(&except);
}
WS_NORETURN void except_throwd(long group, long code, const char *msg, void *data)
{
except_t except;
except.except_id.except_group = group;
except.except_id.except_code = code;
except.except_message = msg;
except.except_dyndata = data;
do_throw(&except);
}
WS_NORETURN void except_throwf(long group, long code, const char *fmt, ...)
{
char *buf = (char *)except_alloc(XCEPT_BUFFER_SIZE);
va_list vl;
va_start (vl, fmt);
g_vsnprintf(buf, XCEPT_BUFFER_SIZE, fmt, vl);
va_end (vl);
except_throwd(group, code, buf, buf);
}
unsigned long except_code(except_t *ex)
{
return ex->except_id.except_code;
}
unsigned long except_group(except_t *ex)
{
return ex->except_id.except_group;
}
const char *except_message(except_t *ex)
{
return ex->except_message;
}
void *except_data(except_t *ex)
{
return ex->except_dyndata;
}
void *except_take_data(except_t *ex)
{
void *data = ex->except_dyndata;
ex->except_dyndata = 0;
return data;
}
void except_set_allocator(void *(*alloc)(size_t), void (*dealloc)(void *))
{
set_alloc(alloc);
set_dealloc(dealloc);
}
void *except_alloc(size_t size)
{
void *ptr = get_alloc()(size);
if (ptr == 0)
except_throw(XCEPT_BAD_ALLOC, 0, "out of memory");
return ptr;
}
void except_free(void *ptr)
{
get_dealloc()(ptr);
}
static void cleanup(void *arg)
{
ws_debug_printf("cleanup(\"%s\") called\n", (char *) arg);
}
static void bottom_level(void)
{
char buf[256];
ws_debug_printf("throw exception? "); fflush(stdout);
fgets(buf, sizeof buf, stdin);
if (buf[0] >= 0 && (buf[0] == 'Y' || buf[0] == 'y'))
except_throw(1, 1, "nasty exception");
}
static void top_level(void)
{
except_cleanup_push(cleanup, "argument");
bottom_level();
except_cleanup_pop(0);
}
int main(int argc, char **argv)
{
static const except_id_t catch[] = { { 1, 1 }, { 1, 2 } };
except_t *ex;
char *msg;
except_try_push(catch, 2, &ex);
if (!ex) {
except_try_push(catch, 2, &ex);
if (!ex) {
top_level();
} else {
msg = except_message(ex);
if (msg == NULL) {
ws_debug_printf("caught exception (inner): s=%lu, c=%lu\n",
except_group(ex), except_code(ex));
} else {
ws_debug_printf("caught exception (inner): \"%s\", s=%lu, c=%lu\n",
msg, except_group(ex), except_code(ex));
}
except_rethrow(ex);
}
except_try_pop();
} else {
msg = except_message(ex);
if (msg == NULL) {
ws_debug_printf("caught exception (outer): s=%lu, c=%lu\n",
except_group(ex), except_code(ex));
} else {
ws_debug_printf("caught exception (outer): \"%s\", s=%lu, c=%lu\n",
except_message(ex), except_group(ex), except_code(ex));
}
}
except_try_pop();
except_throw(99, 99, "exception in main");
return 0;
}
