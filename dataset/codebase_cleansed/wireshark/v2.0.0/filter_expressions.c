struct filter_expression *
filter_expression_new(const gchar *label, const gchar *expr,
const gboolean enabled)
{
struct filter_expression *expression;
struct filter_expression *prev;
expression = (struct filter_expression *)g_malloc0(sizeof(struct filter_expression));
expression->label = g_strdup(label);
expression->expression = g_strdup(expr);
expression->enabled = enabled;
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
void
filter_expression_free(struct filter_expression *list_head)
{
if (list_head == NULL)
return;
filter_expression_free(list_head->next);
g_free(list_head->label);
g_free(list_head->expression);
}
