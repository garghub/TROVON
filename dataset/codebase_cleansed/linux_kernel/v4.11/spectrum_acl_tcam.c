static int mlxsw_sp_acl_tcam_init(struct mlxsw_sp *mlxsw_sp, void *priv)
{
struct mlxsw_sp_acl_tcam *tcam = priv;
u64 max_tcam_regions;
u64 max_regions;
u64 max_groups;
size_t alloc_size;
int err;
max_tcam_regions = MLXSW_CORE_RES_GET(mlxsw_sp->core,
ACL_MAX_TCAM_REGIONS);
max_regions = MLXSW_CORE_RES_GET(mlxsw_sp->core, ACL_MAX_REGIONS);
if (max_tcam_regions < max_regions)
max_regions = max_tcam_regions;
alloc_size = sizeof(tcam->used_regions[0]) * BITS_TO_LONGS(max_regions);
tcam->used_regions = kzalloc(alloc_size, GFP_KERNEL);
if (!tcam->used_regions)
return -ENOMEM;
tcam->max_regions = max_regions;
max_groups = MLXSW_CORE_RES_GET(mlxsw_sp->core, ACL_MAX_GROUPS);
alloc_size = sizeof(tcam->used_groups[0]) * BITS_TO_LONGS(max_groups);
tcam->used_groups = kzalloc(alloc_size, GFP_KERNEL);
if (!tcam->used_groups) {
err = -ENOMEM;
goto err_alloc_used_groups;
}
tcam->max_groups = max_groups;
tcam->max_group_size = MLXSW_CORE_RES_GET(mlxsw_sp->core,
ACL_MAX_GROUP_SIZE);
return 0;
err_alloc_used_groups:
kfree(tcam->used_regions);
return err;
}
static void mlxsw_sp_acl_tcam_fini(struct mlxsw_sp *mlxsw_sp, void *priv)
{
struct mlxsw_sp_acl_tcam *tcam = priv;
kfree(tcam->used_groups);
kfree(tcam->used_regions);
}
static int mlxsw_sp_acl_tcam_region_id_get(struct mlxsw_sp_acl_tcam *tcam,
u16 *p_id)
{
u16 id;
id = find_first_zero_bit(tcam->used_regions, tcam->max_regions);
if (id < tcam->max_regions) {
__set_bit(id, tcam->used_regions);
*p_id = id;
return 0;
}
return -ENOBUFS;
}
static void mlxsw_sp_acl_tcam_region_id_put(struct mlxsw_sp_acl_tcam *tcam,
u16 id)
{
__clear_bit(id, tcam->used_regions);
}
static int mlxsw_sp_acl_tcam_group_id_get(struct mlxsw_sp_acl_tcam *tcam,
u16 *p_id)
{
u16 id;
id = find_first_zero_bit(tcam->used_groups, tcam->max_groups);
if (id < tcam->max_groups) {
__set_bit(id, tcam->used_groups);
*p_id = id;
return 0;
}
return -ENOBUFS;
}
static void mlxsw_sp_acl_tcam_group_id_put(struct mlxsw_sp_acl_tcam *tcam,
u16 id)
{
__clear_bit(id, tcam->used_groups);
}
static int mlxsw_sp_acl_tcam_group_update(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_group *group)
{
struct mlxsw_sp_acl_tcam_region *region;
char pagt_pl[MLXSW_REG_PAGT_LEN];
int acl_index = 0;
mlxsw_reg_pagt_pack(pagt_pl, group->id);
list_for_each_entry(region, &group->region_list, list)
mlxsw_reg_pagt_acl_id_pack(pagt_pl, acl_index++, region->id);
mlxsw_reg_pagt_size_set(pagt_pl, acl_index);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(pagt), pagt_pl);
}
static int
mlxsw_sp_acl_tcam_group_add(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam *tcam,
struct mlxsw_sp_acl_tcam_group *group,
const struct mlxsw_sp_acl_tcam_pattern *patterns,
unsigned int patterns_count)
{
int err;
group->tcam = tcam;
group->patterns = patterns;
group->patterns_count = patterns_count;
INIT_LIST_HEAD(&group->region_list);
err = mlxsw_sp_acl_tcam_group_id_get(tcam, &group->id);
if (err)
return err;
err = mlxsw_sp_acl_tcam_group_update(mlxsw_sp, group);
if (err)
goto err_group_update;
err = rhashtable_init(&group->chunk_ht,
&mlxsw_sp_acl_tcam_chunk_ht_params);
if (err)
goto err_rhashtable_init;
return 0;
err_rhashtable_init:
err_group_update:
mlxsw_sp_acl_tcam_group_id_put(tcam, group->id);
return err;
}
static void mlxsw_sp_acl_tcam_group_del(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_group *group)
{
struct mlxsw_sp_acl_tcam *tcam = group->tcam;
rhashtable_destroy(&group->chunk_ht);
mlxsw_sp_acl_tcam_group_id_put(tcam, group->id);
WARN_ON(!list_empty(&group->region_list));
}
static int
mlxsw_sp_acl_tcam_group_bind(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_group *group,
struct net_device *dev, bool ingress)
{
struct mlxsw_sp_port *mlxsw_sp_port;
char ppbt_pl[MLXSW_REG_PPBT_LEN];
if (!mlxsw_sp_port_dev_check(dev))
return -EINVAL;
mlxsw_sp_port = netdev_priv(dev);
group->bound.local_port = mlxsw_sp_port->local_port;
group->bound.ingress = ingress;
mlxsw_reg_ppbt_pack(ppbt_pl,
group->bound.ingress ? MLXSW_REG_PXBT_E_IACL :
MLXSW_REG_PXBT_E_EACL,
MLXSW_REG_PXBT_OP_BIND, group->bound.local_port,
group->id);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ppbt), ppbt_pl);
}
static void
mlxsw_sp_acl_tcam_group_unbind(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_group *group)
{
char ppbt_pl[MLXSW_REG_PPBT_LEN];
mlxsw_reg_ppbt_pack(ppbt_pl,
group->bound.ingress ? MLXSW_REG_PXBT_E_IACL :
MLXSW_REG_PXBT_E_EACL,
MLXSW_REG_PXBT_OP_UNBIND, group->bound.local_port,
group->id);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ppbt), ppbt_pl);
}
static unsigned int
mlxsw_sp_acl_tcam_region_prio(struct mlxsw_sp_acl_tcam_region *region)
{
struct mlxsw_sp_acl_tcam_chunk *chunk;
if (list_empty(&region->chunk_list))
return 0;
chunk = list_first_entry(&region->chunk_list, typeof(*chunk), list);
return chunk->priority;
}
static unsigned int
mlxsw_sp_acl_tcam_region_max_prio(struct mlxsw_sp_acl_tcam_region *region)
{
struct mlxsw_sp_acl_tcam_chunk *chunk;
if (list_empty(&region->chunk_list))
return 0;
chunk = list_last_entry(&region->chunk_list, typeof(*chunk), list);
return chunk->priority;
}
static void
mlxsw_sp_acl_tcam_group_list_add(struct mlxsw_sp_acl_tcam_group *group,
struct mlxsw_sp_acl_tcam_region *region)
{
struct mlxsw_sp_acl_tcam_region *region2;
struct list_head *pos;
list_for_each(pos, &group->region_list) {
region2 = list_entry(pos, typeof(*region2), list);
if (mlxsw_sp_acl_tcam_region_prio(region2) >
mlxsw_sp_acl_tcam_region_prio(region))
break;
}
list_add_tail(&region->list, pos);
group->region_count++;
}
static void
mlxsw_sp_acl_tcam_group_list_del(struct mlxsw_sp_acl_tcam_group *group,
struct mlxsw_sp_acl_tcam_region *region)
{
group->region_count--;
list_del(&region->list);
}
static int
mlxsw_sp_acl_tcam_group_region_attach(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_group *group,
struct mlxsw_sp_acl_tcam_region *region)
{
int err;
if (group->region_count == group->tcam->max_group_size)
return -ENOBUFS;
mlxsw_sp_acl_tcam_group_list_add(group, region);
err = mlxsw_sp_acl_tcam_group_update(mlxsw_sp, group);
if (err)
goto err_group_update;
region->group = group;
return 0;
err_group_update:
mlxsw_sp_acl_tcam_group_list_del(group, region);
mlxsw_sp_acl_tcam_group_update(mlxsw_sp, group);
return err;
}
static void
mlxsw_sp_acl_tcam_group_region_detach(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region)
{
struct mlxsw_sp_acl_tcam_group *group = region->group;
mlxsw_sp_acl_tcam_group_list_del(group, region);
mlxsw_sp_acl_tcam_group_update(mlxsw_sp, group);
}
static struct mlxsw_sp_acl_tcam_region *
mlxsw_sp_acl_tcam_group_region_find(struct mlxsw_sp_acl_tcam_group *group,
unsigned int priority,
struct mlxsw_afk_element_usage *elusage,
bool *p_need_split)
{
struct mlxsw_sp_acl_tcam_region *region, *region2;
struct list_head *pos;
bool issubset;
list_for_each(pos, &group->region_list) {
region = list_entry(pos, typeof(*region), list);
if (pos->next != &group->region_list) {
region2 = list_entry(pos->next, typeof(*region2), list);
if (priority >= mlxsw_sp_acl_tcam_region_prio(region2))
continue;
}
issubset = mlxsw_afk_key_info_subset(region->key_info, elusage);
if (!issubset &&
priority < mlxsw_sp_acl_tcam_region_prio(region))
return NULL;
if (!issubset &&
priority > mlxsw_sp_acl_tcam_region_max_prio(region))
continue;
*p_need_split = !issubset;
return region;
}
return NULL;
}
static void
mlxsw_sp_acl_tcam_group_use_patterns(struct mlxsw_sp_acl_tcam_group *group,
struct mlxsw_afk_element_usage *elusage,
struct mlxsw_afk_element_usage *out)
{
const struct mlxsw_sp_acl_tcam_pattern *pattern;
int i;
for (i = 0; i < group->patterns_count; i++) {
pattern = &group->patterns[i];
mlxsw_afk_element_usage_fill(out, pattern->elements,
pattern->elements_count);
if (mlxsw_afk_element_usage_subset(elusage, out))
return;
}
memcpy(out, elusage, sizeof(*out));
}
static int
mlxsw_sp_acl_tcam_region_alloc(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region)
{
struct mlxsw_afk_key_info *key_info = region->key_info;
char ptar_pl[MLXSW_REG_PTAR_LEN];
unsigned int encodings_count;
int i;
int err;
mlxsw_reg_ptar_pack(ptar_pl, MLXSW_REG_PTAR_OP_ALLOC,
MLXSW_SP_ACL_TCAM_REGION_BASE_COUNT,
region->id, region->tcam_region_info);
encodings_count = mlxsw_afk_key_info_blocks_count_get(key_info);
for (i = 0; i < encodings_count; i++) {
u16 encoding;
encoding = mlxsw_afk_key_info_block_encoding_get(key_info, i);
mlxsw_reg_ptar_key_id_pack(ptar_pl, i, encoding);
}
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ptar), ptar_pl);
if (err)
return err;
mlxsw_reg_ptar_unpack(ptar_pl, region->tcam_region_info);
return 0;
}
static void
mlxsw_sp_acl_tcam_region_free(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region)
{
char ptar_pl[MLXSW_REG_PTAR_LEN];
mlxsw_reg_ptar_pack(ptar_pl, MLXSW_REG_PTAR_OP_FREE, 0, region->id,
region->tcam_region_info);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ptar), ptar_pl);
}
static int
mlxsw_sp_acl_tcam_region_resize(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region,
u16 new_size)
{
char ptar_pl[MLXSW_REG_PTAR_LEN];
mlxsw_reg_ptar_pack(ptar_pl, MLXSW_REG_PTAR_OP_RESIZE,
new_size, region->id, region->tcam_region_info);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ptar), ptar_pl);
}
static int
mlxsw_sp_acl_tcam_region_enable(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region)
{
char pacl_pl[MLXSW_REG_PACL_LEN];
mlxsw_reg_pacl_pack(pacl_pl, region->id, true,
region->tcam_region_info);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(pacl), pacl_pl);
}
static void
mlxsw_sp_acl_tcam_region_disable(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region)
{
char pacl_pl[MLXSW_REG_PACL_LEN];
mlxsw_reg_pacl_pack(pacl_pl, region->id, false,
region->tcam_region_info);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(pacl), pacl_pl);
}
static int
mlxsw_sp_acl_tcam_region_entry_insert(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region,
unsigned int offset,
struct mlxsw_sp_acl_rule_info *rulei)
{
char ptce2_pl[MLXSW_REG_PTCE2_LEN];
char *act_set;
char *mask;
char *key;
mlxsw_reg_ptce2_pack(ptce2_pl, true, MLXSW_REG_PTCE2_OP_WRITE_WRITE,
region->tcam_region_info, offset);
key = mlxsw_reg_ptce2_flex_key_blocks_data(ptce2_pl);
mask = mlxsw_reg_ptce2_mask_data(ptce2_pl);
mlxsw_afk_encode(region->key_info, &rulei->values, key, mask);
act_set = mlxsw_afa_block_first_set(rulei->act_block);
mlxsw_reg_ptce2_flex_action_set_memcpy_to(ptce2_pl, act_set);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ptce2), ptce2_pl);
}
static void
mlxsw_sp_acl_tcam_region_entry_remove(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region,
unsigned int offset)
{
char ptce2_pl[MLXSW_REG_PTCE2_LEN];
mlxsw_reg_ptce2_pack(ptce2_pl, false, MLXSW_REG_PTCE2_OP_WRITE_WRITE,
region->tcam_region_info, offset);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ptce2), ptce2_pl);
}
static int
mlxsw_sp_acl_tcam_region_catchall_add(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region)
{
struct parman_prio *parman_prio = &region->catchall.parman_prio;
struct parman_item *parman_item = &region->catchall.parman_item;
struct mlxsw_sp_acl_rule_info *rulei;
int err;
parman_prio_init(region->parman, parman_prio,
MLXSW_SP_ACL_TCAM_CATCHALL_PRIO);
err = parman_item_add(region->parman, parman_prio, parman_item);
if (err)
goto err_parman_item_add;
rulei = mlxsw_sp_acl_rulei_create(mlxsw_sp->acl);
if (IS_ERR(rulei)) {
err = PTR_ERR(rulei);
goto err_rulei_create;
}
mlxsw_sp_acl_rulei_act_continue(rulei);
err = mlxsw_sp_acl_rulei_commit(rulei);
if (err)
goto err_rulei_commit;
err = mlxsw_sp_acl_tcam_region_entry_insert(mlxsw_sp, region,
parman_item->index, rulei);
region->catchall.rulei = rulei;
if (err)
goto err_rule_insert;
return 0;
err_rule_insert:
err_rulei_commit:
mlxsw_sp_acl_rulei_destroy(rulei);
err_rulei_create:
parman_item_remove(region->parman, parman_prio, parman_item);
err_parman_item_add:
parman_prio_fini(parman_prio);
return err;
}
static void
mlxsw_sp_acl_tcam_region_catchall_del(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region)
{
struct parman_prio *parman_prio = &region->catchall.parman_prio;
struct parman_item *parman_item = &region->catchall.parman_item;
struct mlxsw_sp_acl_rule_info *rulei = region->catchall.rulei;
mlxsw_sp_acl_tcam_region_entry_remove(mlxsw_sp, region,
parman_item->index);
mlxsw_sp_acl_rulei_destroy(rulei);
parman_item_remove(region->parman, parman_prio, parman_item);
parman_prio_fini(parman_prio);
}
static void
mlxsw_sp_acl_tcam_region_move(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region,
u16 src_offset, u16 dst_offset, u16 size)
{
char prcr_pl[MLXSW_REG_PRCR_LEN];
mlxsw_reg_prcr_pack(prcr_pl, MLXSW_REG_PRCR_OP_MOVE,
region->tcam_region_info, src_offset,
region->tcam_region_info, dst_offset, size);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(prcr), prcr_pl);
}
static int mlxsw_sp_acl_tcam_region_parman_resize(void *priv,
unsigned long new_count)
{
struct mlxsw_sp_acl_tcam_region *region = priv;
struct mlxsw_sp *mlxsw_sp = region->mlxsw_sp;
u64 max_tcam_rules;
max_tcam_rules = MLXSW_CORE_RES_GET(mlxsw_sp->core, ACL_MAX_TCAM_RULES);
if (new_count > max_tcam_rules)
return -EINVAL;
return mlxsw_sp_acl_tcam_region_resize(mlxsw_sp, region, new_count);
}
static void mlxsw_sp_acl_tcam_region_parman_move(void *priv,
unsigned long from_index,
unsigned long to_index,
unsigned long count)
{
struct mlxsw_sp_acl_tcam_region *region = priv;
struct mlxsw_sp *mlxsw_sp = region->mlxsw_sp;
mlxsw_sp_acl_tcam_region_move(mlxsw_sp, region,
from_index, to_index, count);
}
static struct mlxsw_sp_acl_tcam_region *
mlxsw_sp_acl_tcam_region_create(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam *tcam,
struct mlxsw_afk_element_usage *elusage)
{
struct mlxsw_afk *afk = mlxsw_sp_acl_afk(mlxsw_sp->acl);
struct mlxsw_sp_acl_tcam_region *region;
int err;
region = kzalloc(sizeof(*region), GFP_KERNEL);
if (!region)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&region->chunk_list);
region->mlxsw_sp = mlxsw_sp;
region->parman = parman_create(&mlxsw_sp_acl_tcam_region_parman_ops,
region);
if (!region->parman) {
err = -ENOMEM;
goto err_parman_create;
}
region->key_info = mlxsw_afk_key_info_get(afk, elusage);
if (IS_ERR(region->key_info)) {
err = PTR_ERR(region->key_info);
goto err_key_info_get;
}
err = mlxsw_sp_acl_tcam_region_id_get(tcam, &region->id);
if (err)
goto err_region_id_get;
err = mlxsw_sp_acl_tcam_region_alloc(mlxsw_sp, region);
if (err)
goto err_tcam_region_alloc;
err = mlxsw_sp_acl_tcam_region_enable(mlxsw_sp, region);
if (err)
goto err_tcam_region_enable;
err = mlxsw_sp_acl_tcam_region_catchall_add(mlxsw_sp, region);
if (err)
goto err_tcam_region_catchall_add;
return region;
err_tcam_region_catchall_add:
mlxsw_sp_acl_tcam_region_disable(mlxsw_sp, region);
err_tcam_region_enable:
mlxsw_sp_acl_tcam_region_free(mlxsw_sp, region);
err_tcam_region_alloc:
mlxsw_sp_acl_tcam_region_id_put(tcam, region->id);
err_region_id_get:
mlxsw_afk_key_info_put(region->key_info);
err_key_info_get:
parman_destroy(region->parman);
err_parman_create:
kfree(region);
return ERR_PTR(err);
}
static void
mlxsw_sp_acl_tcam_region_destroy(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_region *region)
{
mlxsw_sp_acl_tcam_region_catchall_del(mlxsw_sp, region);
mlxsw_sp_acl_tcam_region_disable(mlxsw_sp, region);
mlxsw_sp_acl_tcam_region_free(mlxsw_sp, region);
mlxsw_sp_acl_tcam_region_id_put(region->group->tcam, region->id);
mlxsw_afk_key_info_put(region->key_info);
parman_destroy(region->parman);
kfree(region);
}
static int
mlxsw_sp_acl_tcam_chunk_assoc(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_group *group,
unsigned int priority,
struct mlxsw_afk_element_usage *elusage,
struct mlxsw_sp_acl_tcam_chunk *chunk)
{
struct mlxsw_sp_acl_tcam_region *region;
bool region_created = false;
bool need_split;
int err;
region = mlxsw_sp_acl_tcam_group_region_find(group, priority, elusage,
&need_split);
if (region && need_split) {
return -EOPNOTSUPP;
}
if (!region) {
struct mlxsw_afk_element_usage region_elusage;
mlxsw_sp_acl_tcam_group_use_patterns(group, elusage,
&region_elusage);
region = mlxsw_sp_acl_tcam_region_create(mlxsw_sp, group->tcam,
&region_elusage);
if (IS_ERR(region))
return PTR_ERR(region);
region_created = true;
}
chunk->region = region;
list_add_tail(&chunk->list, &region->chunk_list);
if (!region_created)
return 0;
err = mlxsw_sp_acl_tcam_group_region_attach(mlxsw_sp, group, region);
if (err)
goto err_group_region_attach;
return 0;
err_group_region_attach:
mlxsw_sp_acl_tcam_region_destroy(mlxsw_sp, region);
return err;
}
static void
mlxsw_sp_acl_tcam_chunk_deassoc(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_chunk *chunk)
{
struct mlxsw_sp_acl_tcam_region *region = chunk->region;
list_del(&chunk->list);
if (list_empty(&region->chunk_list)) {
mlxsw_sp_acl_tcam_group_region_detach(mlxsw_sp, region);
mlxsw_sp_acl_tcam_region_destroy(mlxsw_sp, region);
}
}
static struct mlxsw_sp_acl_tcam_chunk *
mlxsw_sp_acl_tcam_chunk_create(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_group *group,
unsigned int priority,
struct mlxsw_afk_element_usage *elusage)
{
struct mlxsw_sp_acl_tcam_chunk *chunk;
int err;
if (priority == MLXSW_SP_ACL_TCAM_CATCHALL_PRIO)
return ERR_PTR(-EINVAL);
chunk = kzalloc(sizeof(*chunk), GFP_KERNEL);
if (!chunk)
return ERR_PTR(-ENOMEM);
chunk->priority = priority;
chunk->group = group;
chunk->ref_count = 1;
err = mlxsw_sp_acl_tcam_chunk_assoc(mlxsw_sp, group, priority,
elusage, chunk);
if (err)
goto err_chunk_assoc;
parman_prio_init(chunk->region->parman, &chunk->parman_prio, priority);
err = rhashtable_insert_fast(&group->chunk_ht, &chunk->ht_node,
mlxsw_sp_acl_tcam_chunk_ht_params);
if (err)
goto err_rhashtable_insert;
return chunk;
err_rhashtable_insert:
parman_prio_fini(&chunk->parman_prio);
mlxsw_sp_acl_tcam_chunk_deassoc(mlxsw_sp, chunk);
err_chunk_assoc:
kfree(chunk);
return ERR_PTR(err);
}
static void
mlxsw_sp_acl_tcam_chunk_destroy(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_chunk *chunk)
{
struct mlxsw_sp_acl_tcam_group *group = chunk->group;
rhashtable_remove_fast(&group->chunk_ht, &chunk->ht_node,
mlxsw_sp_acl_tcam_chunk_ht_params);
parman_prio_fini(&chunk->parman_prio);
mlxsw_sp_acl_tcam_chunk_deassoc(mlxsw_sp, chunk);
kfree(chunk);
}
static struct mlxsw_sp_acl_tcam_chunk *
mlxsw_sp_acl_tcam_chunk_get(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_group *group,
unsigned int priority,
struct mlxsw_afk_element_usage *elusage)
{
struct mlxsw_sp_acl_tcam_chunk *chunk;
chunk = rhashtable_lookup_fast(&group->chunk_ht, &priority,
mlxsw_sp_acl_tcam_chunk_ht_params);
if (chunk) {
if (WARN_ON(!mlxsw_afk_key_info_subset(chunk->region->key_info,
elusage)))
return ERR_PTR(-EINVAL);
chunk->ref_count++;
return chunk;
}
return mlxsw_sp_acl_tcam_chunk_create(mlxsw_sp, group,
priority, elusage);
}
static void mlxsw_sp_acl_tcam_chunk_put(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_chunk *chunk)
{
if (--chunk->ref_count)
return;
mlxsw_sp_acl_tcam_chunk_destroy(mlxsw_sp, chunk);
}
static int mlxsw_sp_acl_tcam_entry_add(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_group *group,
struct mlxsw_sp_acl_tcam_entry *entry,
struct mlxsw_sp_acl_rule_info *rulei)
{
struct mlxsw_sp_acl_tcam_chunk *chunk;
struct mlxsw_sp_acl_tcam_region *region;
int err;
chunk = mlxsw_sp_acl_tcam_chunk_get(mlxsw_sp, group, rulei->priority,
&rulei->values.elusage);
if (IS_ERR(chunk))
return PTR_ERR(chunk);
region = chunk->region;
err = parman_item_add(region->parman, &chunk->parman_prio,
&entry->parman_item);
if (err)
goto err_parman_item_add;
err = mlxsw_sp_acl_tcam_region_entry_insert(mlxsw_sp, region,
entry->parman_item.index,
rulei);
if (err)
goto err_rule_insert;
entry->chunk = chunk;
return 0;
err_rule_insert:
parman_item_remove(region->parman, &chunk->parman_prio,
&entry->parman_item);
err_parman_item_add:
mlxsw_sp_acl_tcam_chunk_put(mlxsw_sp, chunk);
return err;
}
static void mlxsw_sp_acl_tcam_entry_del(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_acl_tcam_entry *entry)
{
struct mlxsw_sp_acl_tcam_chunk *chunk = entry->chunk;
struct mlxsw_sp_acl_tcam_region *region = chunk->region;
mlxsw_sp_acl_tcam_region_entry_remove(mlxsw_sp, region,
entry->parman_item.index);
parman_item_remove(region->parman, &chunk->parman_prio,
&entry->parman_item);
mlxsw_sp_acl_tcam_chunk_put(mlxsw_sp, chunk);
}
static int
mlxsw_sp_acl_tcam_flower_ruleset_add(struct mlxsw_sp *mlxsw_sp,
void *priv, void *ruleset_priv)
{
struct mlxsw_sp_acl_tcam_flower_ruleset *ruleset = ruleset_priv;
struct mlxsw_sp_acl_tcam *tcam = priv;
return mlxsw_sp_acl_tcam_group_add(mlxsw_sp, tcam, &ruleset->group,
mlxsw_sp_acl_tcam_patterns,
MLXSW_SP_ACL_TCAM_PATTERNS_COUNT);
}
static void
mlxsw_sp_acl_tcam_flower_ruleset_del(struct mlxsw_sp *mlxsw_sp,
void *ruleset_priv)
{
struct mlxsw_sp_acl_tcam_flower_ruleset *ruleset = ruleset_priv;
mlxsw_sp_acl_tcam_group_del(mlxsw_sp, &ruleset->group);
}
static int
mlxsw_sp_acl_tcam_flower_ruleset_bind(struct mlxsw_sp *mlxsw_sp,
void *ruleset_priv,
struct net_device *dev, bool ingress)
{
struct mlxsw_sp_acl_tcam_flower_ruleset *ruleset = ruleset_priv;
return mlxsw_sp_acl_tcam_group_bind(mlxsw_sp, &ruleset->group,
dev, ingress);
}
static void
mlxsw_sp_acl_tcam_flower_ruleset_unbind(struct mlxsw_sp *mlxsw_sp,
void *ruleset_priv)
{
struct mlxsw_sp_acl_tcam_flower_ruleset *ruleset = ruleset_priv;
mlxsw_sp_acl_tcam_group_unbind(mlxsw_sp, &ruleset->group);
}
static int
mlxsw_sp_acl_tcam_flower_rule_add(struct mlxsw_sp *mlxsw_sp,
void *ruleset_priv, void *rule_priv,
struct mlxsw_sp_acl_rule_info *rulei)
{
struct mlxsw_sp_acl_tcam_flower_ruleset *ruleset = ruleset_priv;
struct mlxsw_sp_acl_tcam_flower_rule *rule = rule_priv;
return mlxsw_sp_acl_tcam_entry_add(mlxsw_sp, &ruleset->group,
&rule->entry, rulei);
}
static void
mlxsw_sp_acl_tcam_flower_rule_del(struct mlxsw_sp *mlxsw_sp, void *rule_priv)
{
struct mlxsw_sp_acl_tcam_flower_rule *rule = rule_priv;
mlxsw_sp_acl_tcam_entry_del(mlxsw_sp, &rule->entry);
}
static const struct mlxsw_sp_acl_profile_ops *
mlxsw_sp_acl_tcam_profile_ops(struct mlxsw_sp *mlxsw_sp,
enum mlxsw_sp_acl_profile profile)
{
const struct mlxsw_sp_acl_profile_ops *ops;
if (WARN_ON(profile >= ARRAY_SIZE(mlxsw_sp_acl_tcam_profile_ops_arr)))
return NULL;
ops = mlxsw_sp_acl_tcam_profile_ops_arr[profile];
if (WARN_ON(!ops))
return NULL;
return ops;
}
