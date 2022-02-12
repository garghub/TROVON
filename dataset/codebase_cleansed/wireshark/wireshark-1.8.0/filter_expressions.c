struct filter_expression *
filter_expression_new(const gchar *label, const gchar *expr,
const gboolean enabled)
{
struct filter_expression *expression;
struct filter_expression *prev;
expression = (struct filter_expression *)g_malloc(sizeof(struct filter_expression));
memset(expression, '\0', sizeof(struct filter_expression));
expression->button = NULL;
expression->label = g_strdup(label);
expression->expression = g_strdup(expr);
expression->enabled = enabled;
expression->deleted = FALSE;
expression->index = 0;
expression->next = NULL;
if (*pfilter_expression_head == NULL) {
_filter_expression_head = expression;
} else {
prev = *pfilter_expression_head;
while (prev->next != NULL)
prev = prev->next;
prev->next = expression;
expression->index = prev->index + 1;
}
return(expression);
}
void
filter_expression_init(gboolean enable_prefs)
{
if (enable_prefs)
prefs.filter_expressions = pfilter_expression_head;
}
