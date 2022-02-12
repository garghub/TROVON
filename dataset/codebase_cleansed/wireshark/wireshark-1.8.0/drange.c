drange_node*
drange_node_new(void)
{
drange_node* new_range_node;
new_range_node = g_new(drange_node,1);
new_range_node->start_offset = 0;
new_range_node->length = 0;
new_range_node->end_offset = 0;
new_range_node->ending = DRANGE_NODE_END_T_UNINITIALIZED;
return new_range_node;
}
void
drange_node_free(drange_node* drnode)
{
g_free(drnode);
}
gint
drange_node_get_start_offset(drange_node* drnode)
{
g_assert(drnode->ending != DRANGE_NODE_END_T_UNINITIALIZED);
return drnode->start_offset;
}
gint
drange_node_get_length(drange_node* drnode)
{
g_assert(drnode->ending == DRANGE_NODE_END_T_LENGTH);
return drnode->length;
}
gint
drange_node_get_end_offset(drange_node* drnode)
{
g_assert(drnode->ending == DRANGE_NODE_END_T_OFFSET);
return drnode->end_offset;
}
drange_node_end_t
drange_node_get_ending(drange_node* drnode)
{
g_assert(drnode->ending != DRANGE_NODE_END_T_UNINITIALIZED);
return drnode->ending;
}
void
drange_node_set_start_offset(drange_node* drnode, gint offset)
{
drnode->start_offset = offset;
}
void
drange_node_set_length(drange_node* drnode, gint length)
{
drnode->length = length;
drnode->ending = DRANGE_NODE_END_T_LENGTH;
}
void
drange_node_set_end_offset(drange_node* drnode, gint offset)
{
drnode->end_offset = offset;
drnode->ending = DRANGE_NODE_END_T_OFFSET;
}
void
drange_node_set_to_the_end(drange_node* drnode)
{
drnode->ending = DRANGE_NODE_END_T_TO_THE_END;
}
drange*
drange_new(void)
{
drange* new_drange;
new_drange = g_new(drange,1);
new_drange->range_list = NULL;
new_drange->has_total_length = TRUE;
new_drange->total_length = 0;
new_drange->min_start_offset = G_MAXINT;
new_drange->max_start_offset = G_MININT;
return new_drange;
}
static void
drange_append_wrapper(gpointer data, gpointer user_data)
{
drange_node *drnode = (drange_node *)data;
drange *dr = (drange *)user_data;
drange_append_drange_node(dr, drnode);
}
drange*
drange_new_from_list(GSList *list)
{
drange *new_drange;
new_drange = drange_new();
g_slist_foreach(list, drange_append_wrapper, new_drange);
return new_drange;
}
static void
drange_node_free_wrapper(gpointer data, gpointer userdata _U_)
{
g_free(data);
}
void
drange_free(drange* dr)
{
drange_node_free_list(dr->range_list);
g_free(dr);
}
void
drange_node_free_list(GSList* list)
{
g_slist_foreach(list, drange_node_free_wrapper, NULL);
}
gboolean drange_has_total_length(drange* dr){ return dr->has_total_length; }
gint drange_get_total_length(drange* dr) { return dr->total_length; }
gint drange_get_min_start_offset(drange* dr) { return dr->min_start_offset; }
gint drange_get_max_start_offset(drange* dr) { return dr->max_start_offset; }
static void
update_drange_with_node(drange *dr, drange_node *drnode)
{
if(drnode->ending == DRANGE_NODE_END_T_TO_THE_END){
dr->has_total_length = FALSE;
}
else if(dr->has_total_length){
dr->total_length += drnode->length;
}
if(drnode->start_offset < dr->min_start_offset){
dr->min_start_offset = drnode->start_offset;
}
if(drnode->start_offset > dr->max_start_offset){
dr->max_start_offset = drnode->start_offset;
}
}
void
drange_prepend_drange_node(drange* dr, drange_node* drnode)
{
if(drnode != NULL){
dr->range_list = g_slist_prepend(dr->range_list,drnode);
update_drange_with_node(dr, drnode);
}
}
void
drange_append_drange_node(drange* dr, drange_node* drnode)
{
if(drnode != NULL){
dr->range_list = g_slist_append(dr->range_list,drnode);
update_drange_with_node(dr, drnode);
}
}
void
drange_foreach_drange_node(drange* dr, GFunc func, gpointer funcdata)
{
g_slist_foreach(dr->range_list,func,funcdata);
}
