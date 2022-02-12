static int mlxsw_sp_dpipe_table_erif_actions_dump(void *priv,
struct sk_buff *skb)
{
struct devlink_dpipe_action action = {0};
int err;
action.type = DEVLINK_DPIPE_ACTION_TYPE_FIELD_MODIFY;
action.header = &mlxsw_sp_dpipe_header_metadata;
action.field_id = MLXSW_SP_DPIPE_FIELD_METADATA_L3_FORWARD;
err = devlink_dpipe_action_put(skb, &action);
if (err)
return err;
action.type = DEVLINK_DPIPE_ACTION_TYPE_FIELD_MODIFY;
action.header = &mlxsw_sp_dpipe_header_metadata;
action.field_id = MLXSW_SP_DPIPE_FIELD_METADATA_L3_DROP;
return devlink_dpipe_action_put(skb, &action);
}
static int mlxsw_sp_dpipe_table_erif_matches_dump(void *priv,
struct sk_buff *skb)
{
struct devlink_dpipe_match match = {0};
match.type = DEVLINK_DPIPE_MATCH_TYPE_FIELD_EXACT;
match.header = &mlxsw_sp_dpipe_header_metadata;
match.field_id = MLXSW_SP_DPIPE_FIELD_METADATA_ERIF_PORT;
return devlink_dpipe_match_put(skb, &match);
}
static void mlxsw_sp_erif_entry_clear(struct devlink_dpipe_entry *entry)
{
unsigned int value_count, value_index;
struct devlink_dpipe_value *value;
value = entry->action_values;
value_count = entry->action_values_count;
for (value_index = 0; value_index < value_count; value_index++) {
kfree(value[value_index].value);
kfree(value[value_index].mask);
}
value = entry->match_values;
value_count = entry->match_values_count;
for (value_index = 0; value_index < value_count; value_index++) {
kfree(value[value_index].value);
kfree(value[value_index].mask);
}
}
static void
mlxsw_sp_erif_match_action_prepare(struct devlink_dpipe_match *match,
struct devlink_dpipe_action *action)
{
action->type = DEVLINK_DPIPE_ACTION_TYPE_FIELD_MODIFY;
action->header = &mlxsw_sp_dpipe_header_metadata;
action->field_id = MLXSW_SP_DPIPE_FIELD_METADATA_L3_FORWARD;
match->type = DEVLINK_DPIPE_MATCH_TYPE_FIELD_EXACT;
match->header = &mlxsw_sp_dpipe_header_metadata;
match->field_id = MLXSW_SP_DPIPE_FIELD_METADATA_ERIF_PORT;
}
static int mlxsw_sp_erif_entry_prepare(struct devlink_dpipe_entry *entry,
struct devlink_dpipe_value *match_value,
struct devlink_dpipe_match *match,
struct devlink_dpipe_value *action_value,
struct devlink_dpipe_action *action)
{
entry->match_values = match_value;
entry->match_values_count = 1;
entry->action_values = action_value;
entry->action_values_count = 1;
match_value->match = match;
match_value->value_size = sizeof(u32);
match_value->value = kmalloc(match_value->value_size, GFP_KERNEL);
if (!match_value->value)
return -ENOMEM;
action_value->action = action;
action_value->value_size = sizeof(u32);
action_value->value = kmalloc(action_value->value_size, GFP_KERNEL);
if (!action_value->value)
goto err_action_alloc;
return 0;
err_action_alloc:
kfree(match_value->value);
return -ENOMEM;
}
static int mlxsw_sp_erif_entry_get(struct mlxsw_sp *mlxsw_sp,
struct devlink_dpipe_entry *entry,
struct mlxsw_sp_rif *rif,
bool counters_enabled)
{
u32 *action_value;
u32 *rif_value;
u64 cnt;
int err;
rif_value = entry->match_values->value;
*rif_value = mlxsw_sp_rif_index(rif);
entry->match_values->mapping_value = mlxsw_sp_rif_dev_ifindex(rif);
entry->match_values->mapping_valid = true;
action_value = entry->action_values->value;
*action_value = 1;
entry->counter_valid = false;
entry->counter = 0;
entry->index = mlxsw_sp_rif_index(rif);
if (!counters_enabled)
return 0;
err = mlxsw_sp_rif_counter_value_get(mlxsw_sp, rif,
MLXSW_SP_RIF_COUNTER_EGRESS,
&cnt);
if (!err) {
entry->counter = cnt;
entry->counter_valid = true;
}
return 0;
}
static int
mlxsw_sp_table_erif_entries_dump(void *priv, bool counters_enabled,
struct devlink_dpipe_dump_ctx *dump_ctx)
{
struct devlink_dpipe_value match_value, action_value;
struct devlink_dpipe_action action = {0};
struct devlink_dpipe_match match = {0};
struct devlink_dpipe_entry entry = {0};
struct mlxsw_sp *mlxsw_sp = priv;
unsigned int rif_count;
int i, j;
int err;
memset(&match_value, 0, sizeof(match_value));
memset(&action_value, 0, sizeof(action_value));
mlxsw_sp_erif_match_action_prepare(&match, &action);
err = mlxsw_sp_erif_entry_prepare(&entry, &match_value, &match,
&action_value, &action);
if (err)
return err;
rif_count = MLXSW_CORE_RES_GET(mlxsw_sp->core, MAX_RIFS);
rtnl_lock();
i = 0;
start_again:
err = devlink_dpipe_entry_ctx_prepare(dump_ctx);
if (err)
return err;
j = 0;
for (; i < rif_count; i++) {
struct mlxsw_sp_rif *rif = mlxsw_sp_rif_by_index(mlxsw_sp, i);
if (!rif)
continue;
err = mlxsw_sp_erif_entry_get(mlxsw_sp, &entry, rif,
counters_enabled);
if (err)
goto err_entry_get;
err = devlink_dpipe_entry_ctx_append(dump_ctx, &entry);
if (err) {
if (err == -EMSGSIZE) {
if (!j)
goto err_entry_append;
break;
}
goto err_entry_append;
}
j++;
}
devlink_dpipe_entry_ctx_close(dump_ctx);
if (i != rif_count)
goto start_again;
rtnl_unlock();
mlxsw_sp_erif_entry_clear(&entry);
return 0;
err_entry_append:
err_entry_get:
rtnl_unlock();
mlxsw_sp_erif_entry_clear(&entry);
return err;
}
static int mlxsw_sp_table_erif_counters_update(void *priv, bool enable)
{
struct mlxsw_sp *mlxsw_sp = priv;
int i;
rtnl_lock();
for (i = 0; i < MLXSW_CORE_RES_GET(mlxsw_sp->core, MAX_RIFS); i++) {
struct mlxsw_sp_rif *rif = mlxsw_sp_rif_by_index(mlxsw_sp, i);
if (!rif)
continue;
if (enable)
mlxsw_sp_rif_counter_alloc(mlxsw_sp, rif,
MLXSW_SP_RIF_COUNTER_EGRESS);
else
mlxsw_sp_rif_counter_free(mlxsw_sp, rif,
MLXSW_SP_RIF_COUNTER_EGRESS);
}
rtnl_unlock();
return 0;
}
static int mlxsw_sp_dpipe_erif_table_init(struct mlxsw_sp *mlxsw_sp)
{
struct devlink *devlink = priv_to_devlink(mlxsw_sp->core);
u64 table_size;
table_size = MLXSW_CORE_RES_GET(mlxsw_sp->core, MAX_RIFS);
return devlink_dpipe_table_register(devlink,
MLXSW_SP_DPIPE_TABLE_NAME_ERIF,
&mlxsw_sp_erif_ops,
mlxsw_sp, table_size,
false);
}
static void mlxsw_sp_dpipe_erif_table_fini(struct mlxsw_sp *mlxsw_sp)
{
struct devlink *devlink = priv_to_devlink(mlxsw_sp->core);
devlink_dpipe_table_unregister(devlink, MLXSW_SP_DPIPE_TABLE_NAME_ERIF);
}
int mlxsw_sp_dpipe_init(struct mlxsw_sp *mlxsw_sp)
{
struct devlink *devlink = priv_to_devlink(mlxsw_sp->core);
int err;
err = devlink_dpipe_headers_register(devlink,
&mlxsw_sp_dpipe_headers);
if (err)
return err;
err = mlxsw_sp_dpipe_erif_table_init(mlxsw_sp);
if (err)
goto err_erif_register;
return 0;
err_erif_register:
devlink_dpipe_headers_unregister(priv_to_devlink(mlxsw_sp->core));
return err;
}
void mlxsw_sp_dpipe_fini(struct mlxsw_sp *mlxsw_sp)
{
struct devlink *devlink = priv_to_devlink(mlxsw_sp->core);
mlxsw_sp_dpipe_erif_table_fini(mlxsw_sp);
devlink_dpipe_headers_unregister(devlink);
}
