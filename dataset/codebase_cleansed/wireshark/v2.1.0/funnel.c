const funnel_ops_t* funnel_get_funnel_ops(void) { return ops; }
void funnel_set_funnel_ops(const funnel_ops_t* o) { ops = o; }
static void funnel_insert_menu (funnel_menu_t** menu_list, funnel_menu_t *menu)
{
if (!(*menu_list)) {
*menu_list = menu;
} else {
funnel_menu_t* c;
for (c = *menu_list; c->next; c = c->next);
c->next = menu;
}
}
static void funnel_remove_menu (funnel_menu_t ** menu_list, funnel_menu_t *menu)
{
funnel_menu_t *m = *menu_list, *p = NULL;
while (m) {
if (m->callback == menu->callback) {
if (p) {
p->next = m->next;
} else {
*menu_list = m->next;
}
g_free(m->name);
g_free(m);
if (p) {
m = p->next;
} else {
m = *menu_list ? (*menu_list)->next : NULL;
}
} else {
p = m;
m = m->next;
}
}
}
static void funnel_clear_menu (funnel_menu_t** menu_list)
{
funnel_menu_t *m;
while (*menu_list) {
m = *menu_list;
*menu_list = m->next;
g_free(m->name);
g_free(m);
}
*menu_list = NULL;
}
void funnel_register_menu(const char *name,
register_stat_group_t group,
funnel_menu_callback callback,
gpointer callback_data,
gboolean retap)
{
funnel_menu_t* m = (funnel_menu_t *)g_malloc(sizeof(funnel_menu_t));
m->name = g_strdup(name);
m->group = group;
m->callback = callback;
m->callback_data = callback_data;
m->retap = retap;
m->next = NULL;
funnel_insert_menu(&registered_menus, m);
if (menus_registered) {
funnel_menu_t* m_r = (funnel_menu_t *)g_memdup(m, sizeof *m);
m_r->name = g_strdup(name);
funnel_insert_menu(&added_menus, m_r);
}
}
void funnel_deregister_menus(funnel_menu_callback callback)
{
funnel_menu_t* m = (funnel_menu_t *)g_malloc0(sizeof(funnel_menu_t));
m->callback = callback;
funnel_remove_menu(&registered_menus, m);
funnel_insert_menu(&removed_menus, m);
}
void funnel_register_all_menus(funnel_registration_cb_t r_cb)
{
funnel_menu_t* c;
for (c = registered_menus; c; c = c->next) {
r_cb(c->name,c->group,c->callback,c->callback_data,c->retap);
}
menus_registered = TRUE;
}
void funnel_reload_menus(funnel_deregistration_cb_t d_cb,
funnel_registration_cb_t r_cb)
{
funnel_menu_t* c;
for (c = removed_menus; c; c = c->next) {
d_cb(c->callback);
}
for (c = added_menus; c; c = c->next) {
r_cb(c->name,c->group,c->callback,c->callback_data,c->retap);
}
funnel_clear_menu(&removed_menus);
funnel_clear_menu(&added_menus);
}
