static void
slist_stnode_free(gpointer data, gpointer user_data _U_)
{
stnode_free((stnode_t *)data);
}
void
set_nodelist_free(GSList *params)
{
g_slist_foreach(params, slist_stnode_free, NULL);
g_slist_free(params);
}
void
sttype_set_replace_element(stnode_t *node, stnode_t *oldnode, stnode_t *newnode)
{
GSList *nodelist = (GSList*)stnode_data(node);
while (nodelist) {
if (nodelist->data == oldnode) {
nodelist->data = newnode;
break;
}
nodelist = g_slist_next(nodelist);
}
}
void
sttype_register_set(void)
{
static sttype_t set_type = {
STTYPE_SET,
"SET",
NULL,
NULL,
NULL
};
sttype_register(&set_type);
}
