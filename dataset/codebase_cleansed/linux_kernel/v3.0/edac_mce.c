int edac_mce_register(struct edac_mce *edac_mce)
{
mutex_lock(&edac_mce_lock);
list_add_tail(&edac_mce->list, &edac_mce_list);
mutex_unlock(&edac_mce_lock);
return 0;
}
void edac_mce_unregister(struct edac_mce *edac_mce)
{
mutex_lock(&edac_mce_lock);
list_del(&edac_mce->list);
mutex_unlock(&edac_mce_lock);
}
int edac_mce_parse(struct mce *mce)
{
struct edac_mce *edac_mce;
list_for_each_entry(edac_mce, &edac_mce_list, list) {
if (edac_mce->check_error(edac_mce->priv, mce))
return 1;
}
return 0;
}
