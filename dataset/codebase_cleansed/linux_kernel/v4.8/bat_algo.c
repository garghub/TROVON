void batadv_algo_init(void)
{
INIT_HLIST_HEAD(&batadv_algo_list);
}
static struct batadv_algo_ops *batadv_algo_get(char *name)
{
struct batadv_algo_ops *bat_algo_ops = NULL, *bat_algo_ops_tmp;
hlist_for_each_entry(bat_algo_ops_tmp, &batadv_algo_list, list) {
if (strcmp(bat_algo_ops_tmp->name, name) != 0)
continue;
bat_algo_ops = bat_algo_ops_tmp;
break;
}
return bat_algo_ops;
}
int batadv_algo_register(struct batadv_algo_ops *bat_algo_ops)
{
struct batadv_algo_ops *bat_algo_ops_tmp;
bat_algo_ops_tmp = batadv_algo_get(bat_algo_ops->name);
if (bat_algo_ops_tmp) {
pr_info("Trying to register already registered routing algorithm: %s\n",
bat_algo_ops->name);
return -EEXIST;
}
if (!bat_algo_ops->iface.enable ||
!bat_algo_ops->iface.disable ||
!bat_algo_ops->iface.update_mac ||
!bat_algo_ops->iface.primary_set ||
!bat_algo_ops->neigh.cmp ||
!bat_algo_ops->neigh.is_similar_or_better) {
pr_info("Routing algo '%s' does not implement required ops\n",
bat_algo_ops->name);
return -EINVAL;
}
INIT_HLIST_NODE(&bat_algo_ops->list);
hlist_add_head(&bat_algo_ops->list, &batadv_algo_list);
return 0;
}
int batadv_algo_select(struct batadv_priv *bat_priv, char *name)
{
struct batadv_algo_ops *bat_algo_ops;
bat_algo_ops = batadv_algo_get(name);
if (!bat_algo_ops)
return -EINVAL;
bat_priv->algo_ops = bat_algo_ops;
return 0;
}
int batadv_algo_seq_print_text(struct seq_file *seq, void *offset)
{
struct batadv_algo_ops *bat_algo_ops;
seq_puts(seq, "Available routing algorithms:\n");
hlist_for_each_entry(bat_algo_ops, &batadv_algo_list, list) {
seq_printf(seq, " * %s\n", bat_algo_ops->name);
}
return 0;
}
static int batadv_param_set_ra(const char *val, const struct kernel_param *kp)
{
struct batadv_algo_ops *bat_algo_ops;
char *algo_name = (char *)val;
size_t name_len = strlen(algo_name);
if (name_len > 0 && algo_name[name_len - 1] == '\n')
algo_name[name_len - 1] = '\0';
bat_algo_ops = batadv_algo_get(algo_name);
if (!bat_algo_ops) {
pr_err("Routing algorithm '%s' is not supported\n", algo_name);
return -EINVAL;
}
return param_set_copystring(algo_name, kp);
}
