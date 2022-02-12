const funnel_ops_t* funnel_get_funnel_ops(void) { return ops; }
void funnel_set_funnel_ops(const funnel_ops_t* o) { ops = o; }
void funnel_register_menu(const char *name,
register_stat_group_t group,
void (*callback)(gpointer),
gpointer callback_data,
gboolean retap) {
funnel_menu_t* m = g_malloc(sizeof(funnel_menu_t));
m->name = g_strdup(name);
m->group = group;
m->callback = callback;
m->callback_data = callback_data;
m->retap = retap;
m->next = NULL;
if (!menus) {
menus = m;
} else {
funnel_menu_t* c;
for (c = menus; c->next; c = c->next);
c->next = m;
}
}
void funnel_register_all_menus(funnel_registration_cb_t r_cb) {
funnel_menu_t* c;
for (c = menus; c; c = c->next) {
r_cb(c->name,c->group,c->callback,c->callback_data,c->retap);
}
}
