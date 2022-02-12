void iface_toolbar_add(const iface_toolbar *toolbar)
{
if (iface_toolbar_add_cb) {
iface_toolbar_add_cb(toolbar);
}
}
void iface_toolbar_remove(const gchar *menu_title)
{
if (iface_toolbar_remove_cb) {
iface_toolbar_remove_cb(menu_title);
}
}
gboolean iface_toolbar_use(void)
{
return iface_toolbar_add_cb ? TRUE : FALSE;
}
void iface_toolbar_register_cb(iface_toolbar_add_cb_t add_cb, iface_toolbar_remove_cb_t remove_cb)
{
iface_toolbar_add_cb = add_cb;
iface_toolbar_remove_cb = remove_cb;
}
