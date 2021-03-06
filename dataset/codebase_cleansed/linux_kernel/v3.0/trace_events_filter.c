static int filter_pred_string(struct filter_pred *pred, void *event)
{
char *addr = (char *)(event + pred->offset);
int cmp, match;
cmp = pred->regex.match(addr, &pred->regex, pred->regex.field_len);
match = cmp ^ pred->not;
return match;
}
static int filter_pred_pchar(struct filter_pred *pred, void *event)
{
char **addr = (char **)(event + pred->offset);
int cmp, match;
int len = strlen(*addr) + 1;
cmp = pred->regex.match(*addr, &pred->regex, len);
match = cmp ^ pred->not;
return match;
}
static int filter_pred_strloc(struct filter_pred *pred, void *event)
{
u32 str_item = *(u32 *)(event + pred->offset);
int str_loc = str_item & 0xffff;
int str_len = str_item >> 16;
char *addr = (char *)(event + str_loc);
int cmp, match;
cmp = pred->regex.match(addr, &pred->regex, str_len);
match = cmp ^ pred->not;
return match;
}
static int filter_pred_none(struct filter_pred *pred, void *event)
{
return 0;
}
static int regex_match_full(char *str, struct regex *r, int len)
{
if (strncmp(str, r->pattern, len) == 0)
return 1;
return 0;
}
static int regex_match_front(char *str, struct regex *r, int len)
{
if (strncmp(str, r->pattern, r->len) == 0)
return 1;
return 0;
}
static int regex_match_middle(char *str, struct regex *r, int len)
{
if (strnstr(str, r->pattern, len))
return 1;
return 0;
}
static int regex_match_end(char *str, struct regex *r, int len)
{
int strlen = len - 1;
if (strlen >= r->len &&
memcmp(str + strlen - r->len, r->pattern, r->len) == 0)
return 1;
return 0;
}
enum regex_type filter_parse_regex(char *buff, int len, char **search, int *not)
{
int type = MATCH_FULL;
int i;
if (buff[0] == '!') {
*not = 1;
buff++;
len--;
} else
*not = 0;
*search = buff;
for (i = 0; i < len; i++) {
if (buff[i] == '*') {
if (!i) {
*search = buff + 1;
type = MATCH_END_ONLY;
} else {
if (type == MATCH_END_ONLY)
type = MATCH_MIDDLE_ONLY;
else
type = MATCH_FRONT_ONLY;
buff[i] = 0;
break;
}
}
}
return type;
}
static void filter_build_regex(struct filter_pred *pred)
{
struct regex *r = &pred->regex;
char *search;
enum regex_type type = MATCH_FULL;
int not = 0;
if (pred->op == OP_GLOB) {
type = filter_parse_regex(r->pattern, r->len, &search, &not);
r->len = strlen(search);
memmove(r->pattern, search, r->len+1);
}
switch (type) {
case MATCH_FULL:
r->match = regex_match_full;
break;
case MATCH_FRONT_ONLY:
r->match = regex_match_front;
break;
case MATCH_MIDDLE_ONLY:
r->match = regex_match_middle;
break;
case MATCH_END_ONLY:
r->match = regex_match_end;
break;
}
pred->not ^= not;
}
static struct filter_pred *
get_pred_parent(struct filter_pred *pred, struct filter_pred *preds,
int index, enum move_type *move)
{
if (pred->parent & FILTER_PRED_IS_RIGHT)
*move = MOVE_UP_FROM_RIGHT;
else
*move = MOVE_UP_FROM_LEFT;
pred = &preds[pred->parent & ~FILTER_PRED_IS_RIGHT];
return pred;
}
static int process_ops(struct filter_pred *preds,
struct filter_pred *op, void *rec)
{
struct filter_pred *pred;
int match = 0;
int type;
int i;
type = op->op == OP_OR;
for (i = 0; i < op->val; i++) {
pred = &preds[op->ops[i]];
match = pred->fn(pred, rec);
if (!!match == type)
return match;
}
return match;
}
int filter_match_preds(struct event_filter *filter, void *rec)
{
int match = -1;
enum move_type move = MOVE_DOWN;
struct filter_pred *preds;
struct filter_pred *pred;
struct filter_pred *root;
int n_preds;
int done = 0;
if (!filter)
return 1;
n_preds = filter->n_preds;
if (!n_preds)
return 1;
preds = rcu_dereference_sched(filter->preds);
root = rcu_dereference_sched(filter->root);
if (!root)
return 1;
pred = root;
match = -1;
do {
switch (move) {
case MOVE_DOWN:
if (pred->left != FILTER_PRED_INVALID) {
if (!pred->ops) {
pred = &preds[pred->left];
continue;
}
match = process_ops(preds, pred, rec);
} else
match = pred->fn(pred, rec);
if (pred == root)
break;
pred = get_pred_parent(pred, preds,
pred->parent, &move);
continue;
case MOVE_UP_FROM_LEFT:
if (!!match == (pred->op == OP_OR)) {
if (pred == root)
break;
pred = get_pred_parent(pred, preds,
pred->parent, &move);
continue;
}
pred = &preds[pred->right];
move = MOVE_DOWN;
continue;
case MOVE_UP_FROM_RIGHT:
if (pred == root)
break;
pred = get_pred_parent(pred, preds,
pred->parent, &move);
continue;
}
done = 1;
} while (!done);
return match;
}
static void parse_error(struct filter_parse_state *ps, int err, int pos)
{
ps->lasterr = err;
ps->lasterr_pos = pos;
}
static void remove_filter_string(struct event_filter *filter)
{
if (!filter)
return;
kfree(filter->filter_string);
filter->filter_string = NULL;
}
static int replace_filter_string(struct event_filter *filter,
char *filter_string)
{
kfree(filter->filter_string);
filter->filter_string = kstrdup(filter_string, GFP_KERNEL);
if (!filter->filter_string)
return -ENOMEM;
return 0;
}
static int append_filter_string(struct event_filter *filter,
char *string)
{
int newlen;
char *new_filter_string;
BUG_ON(!filter->filter_string);
newlen = strlen(filter->filter_string) + strlen(string) + 1;
new_filter_string = kmalloc(newlen, GFP_KERNEL);
if (!new_filter_string)
return -ENOMEM;
strcpy(new_filter_string, filter->filter_string);
strcat(new_filter_string, string);
kfree(filter->filter_string);
filter->filter_string = new_filter_string;
return 0;
}
static void append_filter_err(struct filter_parse_state *ps,
struct event_filter *filter)
{
int pos = ps->lasterr_pos;
char *buf, *pbuf;
buf = (char *)__get_free_page(GFP_TEMPORARY);
if (!buf)
return;
append_filter_string(filter, "\n");
memset(buf, ' ', PAGE_SIZE);
if (pos > PAGE_SIZE - 128)
pos = 0;
buf[pos] = '^';
pbuf = &buf[pos] + 1;
sprintf(pbuf, "\nparse_error: %s\n", err_text[ps->lasterr]);
append_filter_string(filter, buf);
free_page((unsigned long) buf);
}
void print_event_filter(struct ftrace_event_call *call, struct trace_seq *s)
{
struct event_filter *filter;
mutex_lock(&event_mutex);
filter = call->filter;
if (filter && filter->filter_string)
trace_seq_printf(s, "%s\n", filter->filter_string);
else
trace_seq_printf(s, "none\n");
mutex_unlock(&event_mutex);
}
void print_subsystem_event_filter(struct event_subsystem *system,
struct trace_seq *s)
{
struct event_filter *filter;
mutex_lock(&event_mutex);
filter = system->filter;
if (filter && filter->filter_string)
trace_seq_printf(s, "%s\n", filter->filter_string);
else
trace_seq_printf(s, "none\n");
mutex_unlock(&event_mutex);
}
static struct ftrace_event_field *
__find_event_field(struct list_head *head, char *name)
{
struct ftrace_event_field *field;
list_for_each_entry(field, head, link) {
if (!strcmp(field->name, name))
return field;
}
return NULL;
}
static struct ftrace_event_field *
find_event_field(struct ftrace_event_call *call, char *name)
{
struct ftrace_event_field *field;
struct list_head *head;
field = __find_event_field(&ftrace_common_fields, name);
if (field)
return field;
head = trace_get_fields(call);
return __find_event_field(head, name);
}
static void filter_free_pred(struct filter_pred *pred)
{
if (!pred)
return;
kfree(pred->field_name);
kfree(pred);
}
static void filter_clear_pred(struct filter_pred *pred)
{
kfree(pred->field_name);
pred->field_name = NULL;
pred->regex.len = 0;
}
static int __alloc_pred_stack(struct pred_stack *stack, int n_preds)
{
stack->preds = kzalloc(sizeof(*stack->preds)*(n_preds + 1), GFP_KERNEL);
if (!stack->preds)
return -ENOMEM;
stack->index = n_preds;
return 0;
}
static void __free_pred_stack(struct pred_stack *stack)
{
kfree(stack->preds);
stack->index = 0;
}
static int __push_pred_stack(struct pred_stack *stack,
struct filter_pred *pred)
{
int index = stack->index;
if (WARN_ON(index == 0))
return -ENOSPC;
stack->preds[--index] = pred;
stack->index = index;
return 0;
}
static struct filter_pred *
__pop_pred_stack(struct pred_stack *stack)
{
struct filter_pred *pred;
int index = stack->index;
pred = stack->preds[index++];
if (!pred)
return NULL;
stack->index = index;
return pred;
}
static int filter_set_pred(struct event_filter *filter,
int idx,
struct pred_stack *stack,
struct filter_pred *src,
filter_pred_fn_t fn)
{
struct filter_pred *dest = &filter->preds[idx];
struct filter_pred *left;
struct filter_pred *right;
*dest = *src;
if (src->field_name) {
dest->field_name = kstrdup(src->field_name, GFP_KERNEL);
if (!dest->field_name)
return -ENOMEM;
}
dest->fn = fn;
dest->index = idx;
if (dest->op == OP_OR || dest->op == OP_AND) {
right = __pop_pred_stack(stack);
left = __pop_pred_stack(stack);
if (!left || !right)
return -EINVAL;
if (left->index & FILTER_PRED_FOLD &&
(left->op == dest->op ||
left->left == FILTER_PRED_INVALID) &&
right->index & FILTER_PRED_FOLD &&
(right->op == dest->op ||
right->left == FILTER_PRED_INVALID))
dest->index |= FILTER_PRED_FOLD;
dest->left = left->index & ~FILTER_PRED_FOLD;
dest->right = right->index & ~FILTER_PRED_FOLD;
left->parent = dest->index & ~FILTER_PRED_FOLD;
right->parent = dest->index | FILTER_PRED_IS_RIGHT;
} else {
dest->left = FILTER_PRED_INVALID;
dest->index |= FILTER_PRED_FOLD;
}
return __push_pred_stack(stack, dest);
}
static void __free_preds(struct event_filter *filter)
{
int i;
if (filter->preds) {
for (i = 0; i < filter->a_preds; i++)
kfree(filter->preds[i].field_name);
kfree(filter->preds);
filter->preds = NULL;
}
filter->a_preds = 0;
filter->n_preds = 0;
}
static void filter_disable(struct ftrace_event_call *call)
{
call->flags &= ~TRACE_EVENT_FL_FILTERED;
}
static void __free_filter(struct event_filter *filter)
{
if (!filter)
return;
__free_preds(filter);
kfree(filter->filter_string);
kfree(filter);
}
void destroy_preds(struct ftrace_event_call *call)
{
__free_filter(call->filter);
call->filter = NULL;
}
static struct event_filter *__alloc_filter(void)
{
struct event_filter *filter;
filter = kzalloc(sizeof(*filter), GFP_KERNEL);
return filter;
}
static int __alloc_preds(struct event_filter *filter, int n_preds)
{
struct filter_pred *pred;
int i;
if (filter->preds)
__free_preds(filter);
filter->preds =
kzalloc(sizeof(*filter->preds) * n_preds, GFP_KERNEL);
if (!filter->preds)
return -ENOMEM;
filter->a_preds = n_preds;
filter->n_preds = 0;
for (i = 0; i < n_preds; i++) {
pred = &filter->preds[i];
pred->fn = filter_pred_none;
}
return 0;
}
static void filter_free_subsystem_preds(struct event_subsystem *system)
{
struct ftrace_event_call *call;
list_for_each_entry(call, &ftrace_events, list) {
if (strcmp(call->class->system, system->name) != 0)
continue;
filter_disable(call);
remove_filter_string(call->filter);
}
}
static void filter_free_subsystem_filters(struct event_subsystem *system)
{
struct ftrace_event_call *call;
list_for_each_entry(call, &ftrace_events, list) {
if (strcmp(call->class->system, system->name) != 0)
continue;
__free_filter(call->filter);
call->filter = NULL;
}
}
static int filter_add_pred_fn(struct filter_parse_state *ps,
struct ftrace_event_call *call,
struct event_filter *filter,
struct filter_pred *pred,
struct pred_stack *stack,
filter_pred_fn_t fn)
{
int idx, err;
if (WARN_ON(filter->n_preds == filter->a_preds)) {
parse_error(ps, FILT_ERR_TOO_MANY_PREDS, 0);
return -ENOSPC;
}
idx = filter->n_preds;
filter_clear_pred(&filter->preds[idx]);
err = filter_set_pred(filter, idx, stack, pred, fn);
if (err)
return err;
filter->n_preds++;
return 0;
}
int filter_assign_type(const char *type)
{
if (strstr(type, "__data_loc") && strstr(type, "char"))
return FILTER_DYN_STRING;
if (strchr(type, '[') && strstr(type, "char"))
return FILTER_STATIC_STRING;
return FILTER_OTHER;
}
static bool is_string_field(struct ftrace_event_field *field)
{
return field->filter_type == FILTER_DYN_STRING ||
field->filter_type == FILTER_STATIC_STRING ||
field->filter_type == FILTER_PTR_STRING;
}
static int is_legal_op(struct ftrace_event_field *field, int op)
{
if (is_string_field(field) &&
(op != OP_EQ && op != OP_NE && op != OP_GLOB))
return 0;
if (!is_string_field(field) && op == OP_GLOB)
return 0;
return 1;
}
static filter_pred_fn_t select_comparison_fn(int op, int field_size,
int field_is_signed)
{
filter_pred_fn_t fn = NULL;
switch (field_size) {
case 8:
if (op == OP_EQ || op == OP_NE)
fn = filter_pred_64;
else if (field_is_signed)
fn = filter_pred_s64;
else
fn = filter_pred_u64;
break;
case 4:
if (op == OP_EQ || op == OP_NE)
fn = filter_pred_32;
else if (field_is_signed)
fn = filter_pred_s32;
else
fn = filter_pred_u32;
break;
case 2:
if (op == OP_EQ || op == OP_NE)
fn = filter_pred_16;
else if (field_is_signed)
fn = filter_pred_s16;
else
fn = filter_pred_u16;
break;
case 1:
if (op == OP_EQ || op == OP_NE)
fn = filter_pred_8;
else if (field_is_signed)
fn = filter_pred_s8;
else
fn = filter_pred_u8;
break;
}
return fn;
}
static int filter_add_pred(struct filter_parse_state *ps,
struct ftrace_event_call *call,
struct event_filter *filter,
struct filter_pred *pred,
struct pred_stack *stack,
bool dry_run)
{
struct ftrace_event_field *field;
filter_pred_fn_t fn;
unsigned long long val;
int ret;
fn = pred->fn = filter_pred_none;
if (pred->op == OP_AND)
goto add_pred_fn;
else if (pred->op == OP_OR)
goto add_pred_fn;
field = find_event_field(call, pred->field_name);
if (!field) {
parse_error(ps, FILT_ERR_FIELD_NOT_FOUND, 0);
return -EINVAL;
}
pred->offset = field->offset;
if (!is_legal_op(field, pred->op)) {
parse_error(ps, FILT_ERR_ILLEGAL_FIELD_OP, 0);
return -EINVAL;
}
if (is_string_field(field)) {
filter_build_regex(pred);
if (field->filter_type == FILTER_STATIC_STRING) {
fn = filter_pred_string;
pred->regex.field_len = field->size;
} else if (field->filter_type == FILTER_DYN_STRING)
fn = filter_pred_strloc;
else
fn = filter_pred_pchar;
} else {
if (field->is_signed)
ret = strict_strtoll(pred->regex.pattern, 0, &val);
else
ret = strict_strtoull(pred->regex.pattern, 0, &val);
if (ret) {
parse_error(ps, FILT_ERR_ILLEGAL_INTVAL, 0);
return -EINVAL;
}
pred->val = val;
fn = select_comparison_fn(pred->op, field->size,
field->is_signed);
if (!fn) {
parse_error(ps, FILT_ERR_INVALID_OP, 0);
return -EINVAL;
}
}
if (pred->op == OP_NE)
pred->not = 1;
add_pred_fn:
if (!dry_run)
return filter_add_pred_fn(ps, call, filter, pred, stack, fn);
return 0;
}
static void parse_init(struct filter_parse_state *ps,
struct filter_op *ops,
char *infix_string)
{
memset(ps, '\0', sizeof(*ps));
ps->infix.string = infix_string;
ps->infix.cnt = strlen(infix_string);
ps->ops = ops;
INIT_LIST_HEAD(&ps->opstack);
INIT_LIST_HEAD(&ps->postfix);
}
static char infix_next(struct filter_parse_state *ps)
{
ps->infix.cnt--;
return ps->infix.string[ps->infix.tail++];
}
static char infix_peek(struct filter_parse_state *ps)
{
if (ps->infix.tail == strlen(ps->infix.string))
return 0;
return ps->infix.string[ps->infix.tail];
}
static void infix_advance(struct filter_parse_state *ps)
{
ps->infix.cnt--;
ps->infix.tail++;
}
static inline int is_precedence_lower(struct filter_parse_state *ps,
int a, int b)
{
return ps->ops[a].precedence < ps->ops[b].precedence;
}
static inline int is_op_char(struct filter_parse_state *ps, char c)
{
int i;
for (i = 0; strcmp(ps->ops[i].string, "OP_NONE"); i++) {
if (ps->ops[i].string[0] == c)
return 1;
}
return 0;
}
static int infix_get_op(struct filter_parse_state *ps, char firstc)
{
char nextc = infix_peek(ps);
char opstr[3];
int i;
opstr[0] = firstc;
opstr[1] = nextc;
opstr[2] = '\0';
for (i = 0; strcmp(ps->ops[i].string, "OP_NONE"); i++) {
if (!strcmp(opstr, ps->ops[i].string)) {
infix_advance(ps);
return ps->ops[i].id;
}
}
opstr[1] = '\0';
for (i = 0; strcmp(ps->ops[i].string, "OP_NONE"); i++) {
if (!strcmp(opstr, ps->ops[i].string))
return ps->ops[i].id;
}
return OP_NONE;
}
static inline void clear_operand_string(struct filter_parse_state *ps)
{
memset(ps->operand.string, '\0', MAX_FILTER_STR_VAL);
ps->operand.tail = 0;
}
static inline int append_operand_char(struct filter_parse_state *ps, char c)
{
if (ps->operand.tail == MAX_FILTER_STR_VAL - 1)
return -EINVAL;
ps->operand.string[ps->operand.tail++] = c;
return 0;
}
static int filter_opstack_push(struct filter_parse_state *ps, int op)
{
struct opstack_op *opstack_op;
opstack_op = kmalloc(sizeof(*opstack_op), GFP_KERNEL);
if (!opstack_op)
return -ENOMEM;
opstack_op->op = op;
list_add(&opstack_op->list, &ps->opstack);
return 0;
}
static int filter_opstack_empty(struct filter_parse_state *ps)
{
return list_empty(&ps->opstack);
}
static int filter_opstack_top(struct filter_parse_state *ps)
{
struct opstack_op *opstack_op;
if (filter_opstack_empty(ps))
return OP_NONE;
opstack_op = list_first_entry(&ps->opstack, struct opstack_op, list);
return opstack_op->op;
}
static int filter_opstack_pop(struct filter_parse_state *ps)
{
struct opstack_op *opstack_op;
int op;
if (filter_opstack_empty(ps))
return OP_NONE;
opstack_op = list_first_entry(&ps->opstack, struct opstack_op, list);
op = opstack_op->op;
list_del(&opstack_op->list);
kfree(opstack_op);
return op;
}
static void filter_opstack_clear(struct filter_parse_state *ps)
{
while (!filter_opstack_empty(ps))
filter_opstack_pop(ps);
}
static char *curr_operand(struct filter_parse_state *ps)
{
return ps->operand.string;
}
static int postfix_append_operand(struct filter_parse_state *ps, char *operand)
{
struct postfix_elt *elt;
elt = kmalloc(sizeof(*elt), GFP_KERNEL);
if (!elt)
return -ENOMEM;
elt->op = OP_NONE;
elt->operand = kstrdup(operand, GFP_KERNEL);
if (!elt->operand) {
kfree(elt);
return -ENOMEM;
}
list_add_tail(&elt->list, &ps->postfix);
return 0;
}
static int postfix_append_op(struct filter_parse_state *ps, int op)
{
struct postfix_elt *elt;
elt = kmalloc(sizeof(*elt), GFP_KERNEL);
if (!elt)
return -ENOMEM;
elt->op = op;
elt->operand = NULL;
list_add_tail(&elt->list, &ps->postfix);
return 0;
}
static void postfix_clear(struct filter_parse_state *ps)
{
struct postfix_elt *elt;
while (!list_empty(&ps->postfix)) {
elt = list_first_entry(&ps->postfix, struct postfix_elt, list);
list_del(&elt->list);
kfree(elt->operand);
kfree(elt);
}
}
static int filter_parse(struct filter_parse_state *ps)
{
int in_string = 0;
int op, top_op;
char ch;
while ((ch = infix_next(ps))) {
if (ch == '"') {
in_string ^= 1;
continue;
}
if (in_string)
goto parse_operand;
if (isspace(ch))
continue;
if (is_op_char(ps, ch)) {
op = infix_get_op(ps, ch);
if (op == OP_NONE) {
parse_error(ps, FILT_ERR_INVALID_OP, 0);
return -EINVAL;
}
if (strlen(curr_operand(ps))) {
postfix_append_operand(ps, curr_operand(ps));
clear_operand_string(ps);
}
while (!filter_opstack_empty(ps)) {
top_op = filter_opstack_top(ps);
if (!is_precedence_lower(ps, top_op, op)) {
top_op = filter_opstack_pop(ps);
postfix_append_op(ps, top_op);
continue;
}
break;
}
filter_opstack_push(ps, op);
continue;
}
if (ch == '(') {
filter_opstack_push(ps, OP_OPEN_PAREN);
continue;
}
if (ch == ')') {
if (strlen(curr_operand(ps))) {
postfix_append_operand(ps, curr_operand(ps));
clear_operand_string(ps);
}
top_op = filter_opstack_pop(ps);
while (top_op != OP_NONE) {
if (top_op == OP_OPEN_PAREN)
break;
postfix_append_op(ps, top_op);
top_op = filter_opstack_pop(ps);
}
if (top_op == OP_NONE) {
parse_error(ps, FILT_ERR_UNBALANCED_PAREN, 0);
return -EINVAL;
}
continue;
}
parse_operand:
if (append_operand_char(ps, ch)) {
parse_error(ps, FILT_ERR_OPERAND_TOO_LONG, 0);
return -EINVAL;
}
}
if (strlen(curr_operand(ps)))
postfix_append_operand(ps, curr_operand(ps));
while (!filter_opstack_empty(ps)) {
top_op = filter_opstack_pop(ps);
if (top_op == OP_NONE)
break;
if (top_op == OP_OPEN_PAREN) {
parse_error(ps, FILT_ERR_UNBALANCED_PAREN, 0);
return -EINVAL;
}
postfix_append_op(ps, top_op);
}
return 0;
}
static struct filter_pred *create_pred(int op, char *operand1, char *operand2)
{
struct filter_pred *pred;
pred = kzalloc(sizeof(*pred), GFP_KERNEL);
if (!pred)
return NULL;
pred->field_name = kstrdup(operand1, GFP_KERNEL);
if (!pred->field_name) {
kfree(pred);
return NULL;
}
strcpy(pred->regex.pattern, operand2);
pred->regex.len = strlen(pred->regex.pattern);
pred->op = op;
return pred;
}
static struct filter_pred *create_logical_pred(int op)
{
struct filter_pred *pred;
pred = kzalloc(sizeof(*pred), GFP_KERNEL);
if (!pred)
return NULL;
pred->op = op;
return pred;
}
static int check_preds(struct filter_parse_state *ps)
{
int n_normal_preds = 0, n_logical_preds = 0;
struct postfix_elt *elt;
list_for_each_entry(elt, &ps->postfix, list) {
if (elt->op == OP_NONE)
continue;
if (elt->op == OP_AND || elt->op == OP_OR) {
n_logical_preds++;
continue;
}
n_normal_preds++;
}
if (!n_normal_preds || n_logical_preds >= n_normal_preds) {
parse_error(ps, FILT_ERR_INVALID_FILTER, 0);
return -EINVAL;
}
return 0;
}
static int count_preds(struct filter_parse_state *ps)
{
struct postfix_elt *elt;
int n_preds = 0;
list_for_each_entry(elt, &ps->postfix, list) {
if (elt->op == OP_NONE)
continue;
n_preds++;
}
return n_preds;
}
static int check_pred_tree(struct event_filter *filter,
struct filter_pred *root)
{
struct filter_pred *preds;
struct filter_pred *pred;
enum move_type move = MOVE_DOWN;
int count = 0;
int done = 0;
int max;
max = 3 * filter->n_preds;
preds = filter->preds;
if (!preds)
return -EINVAL;
pred = root;
do {
if (WARN_ON(count++ > max))
return -EINVAL;
switch (move) {
case MOVE_DOWN:
if (pred->left != FILTER_PRED_INVALID) {
pred = &preds[pred->left];
continue;
}
if (pred == root)
break;
pred = get_pred_parent(pred, preds,
pred->parent, &move);
continue;
case MOVE_UP_FROM_LEFT:
pred = &preds[pred->right];
move = MOVE_DOWN;
continue;
case MOVE_UP_FROM_RIGHT:
if (pred == root)
break;
pred = get_pred_parent(pred, preds,
pred->parent, &move);
continue;
}
done = 1;
} while (!done);
return 0;
}
static int count_leafs(struct filter_pred *preds, struct filter_pred *root)
{
struct filter_pred *pred;
enum move_type move = MOVE_DOWN;
int count = 0;
int done = 0;
pred = root;
do {
switch (move) {
case MOVE_DOWN:
if (pred->left != FILTER_PRED_INVALID) {
pred = &preds[pred->left];
continue;
}
if (pred == root)
return 1;
count++;
pred = get_pred_parent(pred, preds,
pred->parent, &move);
continue;
case MOVE_UP_FROM_LEFT:
pred = &preds[pred->right];
move = MOVE_DOWN;
continue;
case MOVE_UP_FROM_RIGHT:
if (pred == root)
break;
pred = get_pred_parent(pred, preds,
pred->parent, &move);
continue;
}
done = 1;
} while (!done);
return count;
}
static int fold_pred(struct filter_pred *preds, struct filter_pred *root)
{
struct filter_pred *pred;
enum move_type move = MOVE_DOWN;
int count = 0;
int children;
int done = 0;
root->index &= ~FILTER_PRED_FOLD;
if (root->left == FILTER_PRED_INVALID)
return 0;
children = count_leafs(preds, &preds[root->left]);
children += count_leafs(preds, &preds[root->right]);
root->ops = kzalloc(sizeof(*root->ops) * children, GFP_KERNEL);
if (!root->ops)
return -ENOMEM;
root->val = children;
pred = root;
do {
switch (move) {
case MOVE_DOWN:
if (pred->left != FILTER_PRED_INVALID) {
pred = &preds[pred->left];
continue;
}
if (WARN_ON(count == children))
return -EINVAL;
pred->index &= ~FILTER_PRED_FOLD;
root->ops[count++] = pred->index;
pred = get_pred_parent(pred, preds,
pred->parent, &move);
continue;
case MOVE_UP_FROM_LEFT:
pred = &preds[pred->right];
move = MOVE_DOWN;
continue;
case MOVE_UP_FROM_RIGHT:
if (pred == root)
break;
pred = get_pred_parent(pred, preds,
pred->parent, &move);
continue;
}
done = 1;
} while (!done);
return 0;
}
static int fold_pred_tree(struct event_filter *filter,
struct filter_pred *root)
{
struct filter_pred *preds;
struct filter_pred *pred;
enum move_type move = MOVE_DOWN;
int done = 0;
int err;
preds = filter->preds;
if (!preds)
return -EINVAL;
pred = root;
do {
switch (move) {
case MOVE_DOWN:
if (pred->index & FILTER_PRED_FOLD) {
err = fold_pred(preds, pred);
if (err)
return err;
} else if (pred->left != FILTER_PRED_INVALID) {
pred = &preds[pred->left];
continue;
}
if (pred == root)
break;
pred = get_pred_parent(pred, preds,
pred->parent, &move);
continue;
case MOVE_UP_FROM_LEFT:
pred = &preds[pred->right];
move = MOVE_DOWN;
continue;
case MOVE_UP_FROM_RIGHT:
if (pred == root)
break;
pred = get_pred_parent(pred, preds,
pred->parent, &move);
continue;
}
done = 1;
} while (!done);
return 0;
}
static int replace_preds(struct ftrace_event_call *call,
struct event_filter *filter,
struct filter_parse_state *ps,
char *filter_string,
bool dry_run)
{
char *operand1 = NULL, *operand2 = NULL;
struct filter_pred *pred;
struct filter_pred *root;
struct postfix_elt *elt;
struct pred_stack stack = { };
int err;
int n_preds = 0;
n_preds = count_preds(ps);
if (n_preds >= MAX_FILTER_PRED) {
parse_error(ps, FILT_ERR_TOO_MANY_PREDS, 0);
return -ENOSPC;
}
err = check_preds(ps);
if (err)
return err;
if (!dry_run) {
err = __alloc_pred_stack(&stack, n_preds);
if (err)
return err;
err = __alloc_preds(filter, n_preds);
if (err)
goto fail;
}
n_preds = 0;
list_for_each_entry(elt, &ps->postfix, list) {
if (elt->op == OP_NONE) {
if (!operand1)
operand1 = elt->operand;
else if (!operand2)
operand2 = elt->operand;
else {
parse_error(ps, FILT_ERR_TOO_MANY_OPERANDS, 0);
err = -EINVAL;
goto fail;
}
continue;
}
if (WARN_ON(n_preds++ == MAX_FILTER_PRED)) {
parse_error(ps, FILT_ERR_TOO_MANY_PREDS, 0);
err = -ENOSPC;
goto fail;
}
if (elt->op == OP_AND || elt->op == OP_OR) {
pred = create_logical_pred(elt->op);
goto add_pred;
}
if (!operand1 || !operand2) {
parse_error(ps, FILT_ERR_MISSING_FIELD, 0);
err = -EINVAL;
goto fail;
}
pred = create_pred(elt->op, operand1, operand2);
add_pred:
if (!pred) {
err = -ENOMEM;
goto fail;
}
err = filter_add_pred(ps, call, filter, pred, &stack, dry_run);
filter_free_pred(pred);
if (err)
goto fail;
operand1 = operand2 = NULL;
}
if (!dry_run) {
pred = __pop_pred_stack(&stack);
if (!pred)
return -EINVAL;
root = pred;
pred = __pop_pred_stack(&stack);
if (WARN_ON(pred)) {
err = -EINVAL;
filter->root = NULL;
goto fail;
}
err = check_pred_tree(filter, root);
if (err)
goto fail;
err = fold_pred_tree(filter, root);
if (err)
goto fail;
barrier();
filter->root = root;
}
err = 0;
fail:
__free_pred_stack(&stack);
return err;
}
static int replace_system_preds(struct event_subsystem *system,
struct filter_parse_state *ps,
char *filter_string)
{
struct ftrace_event_call *call;
struct filter_list *filter_item;
struct filter_list *tmp;
LIST_HEAD(filter_list);
bool fail = true;
int err;
list_for_each_entry(call, &ftrace_events, list) {
if (strcmp(call->class->system, system->name) != 0)
continue;
err = replace_preds(call, NULL, ps, filter_string, true);
if (err)
goto fail;
}
list_for_each_entry(call, &ftrace_events, list) {
struct event_filter *filter;
if (strcmp(call->class->system, system->name) != 0)
continue;
filter_item = kzalloc(sizeof(*filter_item), GFP_KERNEL);
if (!filter_item)
goto fail_mem;
list_add_tail(&filter_item->list, &filter_list);
filter_item->filter = __alloc_filter();
if (!filter_item->filter)
goto fail_mem;
filter = filter_item->filter;
err = replace_filter_string(filter, filter_string);
if (err)
goto fail_mem;
err = replace_preds(call, filter, ps, filter_string, false);
if (err) {
filter_disable(call);
parse_error(ps, FILT_ERR_BAD_SUBSYS_FILTER, 0);
append_filter_err(ps, filter);
} else
call->flags |= TRACE_EVENT_FL_FILTERED;
filter = call->filter;
call->filter = filter_item->filter;
filter_item->filter = filter;
fail = false;
}
if (fail)
goto fail;
synchronize_sched();
list_for_each_entry_safe(filter_item, tmp, &filter_list, list) {
__free_filter(filter_item->filter);
list_del(&filter_item->list);
kfree(filter_item);
}
return 0;
fail:
list_for_each_entry_safe(filter_item, tmp, &filter_list, list) {
list_del(&filter_item->list);
kfree(filter_item);
}
parse_error(ps, FILT_ERR_BAD_SUBSYS_FILTER, 0);
return -EINVAL;
fail_mem:
if (!fail)
synchronize_sched();
list_for_each_entry_safe(filter_item, tmp, &filter_list, list) {
__free_filter(filter_item->filter);
list_del(&filter_item->list);
kfree(filter_item);
}
return -ENOMEM;
}
int apply_event_filter(struct ftrace_event_call *call, char *filter_string)
{
struct filter_parse_state *ps;
struct event_filter *filter;
struct event_filter *tmp;
int err = 0;
mutex_lock(&event_mutex);
if (!strcmp(strstrip(filter_string), "0")) {
filter_disable(call);
filter = call->filter;
if (!filter)
goto out_unlock;
call->filter = NULL;
synchronize_sched();
__free_filter(filter);
goto out_unlock;
}
err = -ENOMEM;
ps = kzalloc(sizeof(*ps), GFP_KERNEL);
if (!ps)
goto out_unlock;
filter = __alloc_filter();
if (!filter) {
kfree(ps);
goto out_unlock;
}
replace_filter_string(filter, filter_string);
parse_init(ps, filter_ops, filter_string);
err = filter_parse(ps);
if (err) {
append_filter_err(ps, filter);
goto out;
}
err = replace_preds(call, filter, ps, filter_string, false);
if (err) {
filter_disable(call);
append_filter_err(ps, filter);
} else
call->flags |= TRACE_EVENT_FL_FILTERED;
out:
tmp = call->filter;
call->filter = filter;
if (tmp) {
synchronize_sched();
__free_filter(tmp);
}
filter_opstack_clear(ps);
postfix_clear(ps);
kfree(ps);
out_unlock:
mutex_unlock(&event_mutex);
return err;
}
int apply_subsystem_event_filter(struct event_subsystem *system,
char *filter_string)
{
struct filter_parse_state *ps;
struct event_filter *filter;
int err = 0;
mutex_lock(&event_mutex);
if (!strcmp(strstrip(filter_string), "0")) {
filter_free_subsystem_preds(system);
remove_filter_string(system->filter);
filter = system->filter;
system->filter = NULL;
synchronize_sched();
filter_free_subsystem_filters(system);
__free_filter(filter);
goto out_unlock;
}
err = -ENOMEM;
ps = kzalloc(sizeof(*ps), GFP_KERNEL);
if (!ps)
goto out_unlock;
filter = __alloc_filter();
if (!filter)
goto out;
replace_filter_string(filter, filter_string);
__free_filter(system->filter);
system->filter = filter;
parse_init(ps, filter_ops, filter_string);
err = filter_parse(ps);
if (err) {
append_filter_err(ps, system->filter);
goto out;
}
err = replace_system_preds(system, ps, filter_string);
if (err)
append_filter_err(ps, system->filter);
out:
filter_opstack_clear(ps);
postfix_clear(ps);
kfree(ps);
out_unlock:
mutex_unlock(&event_mutex);
return err;
}
void ftrace_profile_free_filter(struct perf_event *event)
{
struct event_filter *filter = event->filter;
event->filter = NULL;
__free_filter(filter);
}
int ftrace_profile_set_filter(struct perf_event *event, int event_id,
char *filter_str)
{
int err;
struct event_filter *filter;
struct filter_parse_state *ps;
struct ftrace_event_call *call = NULL;
mutex_lock(&event_mutex);
list_for_each_entry(call, &ftrace_events, list) {
if (call->event.type == event_id)
break;
}
err = -EINVAL;
if (&call->list == &ftrace_events)
goto out_unlock;
err = -EEXIST;
if (event->filter)
goto out_unlock;
filter = __alloc_filter();
if (!filter) {
err = PTR_ERR(filter);
goto out_unlock;
}
err = -ENOMEM;
ps = kzalloc(sizeof(*ps), GFP_KERNEL);
if (!ps)
goto free_filter;
parse_init(ps, filter_ops, filter_str);
err = filter_parse(ps);
if (err)
goto free_ps;
err = replace_preds(call, filter, ps, filter_str, false);
if (!err)
event->filter = filter;
free_ps:
filter_opstack_clear(ps);
postfix_clear(ps);
kfree(ps);
free_filter:
if (err)
__free_filter(filter);
out_unlock:
mutex_unlock(&event_mutex);
return err;
}
