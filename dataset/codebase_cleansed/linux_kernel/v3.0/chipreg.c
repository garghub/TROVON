void register_mtd_chip_driver(struct mtd_chip_driver *drv)
{
spin_lock(&chip_drvs_lock);
list_add(&drv->list, &chip_drvs_list);
spin_unlock(&chip_drvs_lock);
}
void unregister_mtd_chip_driver(struct mtd_chip_driver *drv)
{
spin_lock(&chip_drvs_lock);
list_del(&drv->list);
spin_unlock(&chip_drvs_lock);
}
static struct mtd_chip_driver *get_mtd_chip_driver (const char *name)
{
struct list_head *pos;
struct mtd_chip_driver *ret = NULL, *this;
spin_lock(&chip_drvs_lock);
list_for_each(pos, &chip_drvs_list) {
this = list_entry(pos, typeof(*this), list);
if (!strcmp(this->name, name)) {
ret = this;
break;
}
}
if (ret && !try_module_get(ret->module))
ret = NULL;
spin_unlock(&chip_drvs_lock);
return ret;
}
struct mtd_info *do_map_probe(const char *name, struct map_info *map)
{
struct mtd_chip_driver *drv;
struct mtd_info *ret;
drv = get_mtd_chip_driver(name);
if (!drv && !request_module("%s", name))
drv = get_mtd_chip_driver(name);
if (!drv)
return NULL;
ret = drv->probe(map);
module_put(drv->module);
if (ret)
return ret;
return NULL;
}
void map_destroy(struct mtd_info *mtd)
{
struct map_info *map = mtd->priv;
if (map->fldrv->destroy)
map->fldrv->destroy(mtd);
module_put(map->fldrv->module);
kfree(mtd);
}
