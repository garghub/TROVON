struct ia_css_host_data *ia_css_host_data_allocate(size_t size)
{
struct ia_css_host_data *me;
me = kmalloc(sizeof(struct ia_css_host_data), GFP_KERNEL);
if (!me)
return NULL;
me->size = (uint32_t)size;
me->address = sh_css_malloc(size);
if (!me->address) {
kfree(me);
return NULL;
}
return me;
}
void ia_css_host_data_free(struct ia_css_host_data *me)
{
if (me) {
sh_css_free(me->address);
me->address = NULL;
kfree(me);
}
}
