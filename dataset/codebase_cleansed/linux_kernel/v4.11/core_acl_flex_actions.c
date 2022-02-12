struct mlxsw_afa *mlxsw_afa_create(unsigned int max_acts_per_set,
const struct mlxsw_afa_ops *ops,
void *ops_priv)
{
struct mlxsw_afa *mlxsw_afa;
int err;
mlxsw_afa = kzalloc(sizeof(*mlxsw_afa), GFP_KERNEL);
if (!mlxsw_afa)
return ERR_PTR(-ENOMEM);
err = rhashtable_init(&mlxsw_afa->set_ht, &mlxsw_afa_set_ht_params);
if (err)
goto err_set_rhashtable_init;
err = rhashtable_init(&mlxsw_afa->fwd_entry_ht,
&mlxsw_afa_fwd_entry_ht_params);
if (err)
goto err_fwd_entry_rhashtable_init;
mlxsw_afa->max_acts_per_set = max_acts_per_set;
mlxsw_afa->ops = ops;
mlxsw_afa->ops_priv = ops_priv;
return mlxsw_afa;
err_fwd_entry_rhashtable_init:
rhashtable_destroy(&mlxsw_afa->set_ht);
err_set_rhashtable_init:
kfree(mlxsw_afa);
return ERR_PTR(err);
}
void mlxsw_afa_destroy(struct mlxsw_afa *mlxsw_afa)
{
rhashtable_destroy(&mlxsw_afa->fwd_entry_ht);
rhashtable_destroy(&mlxsw_afa->set_ht);
kfree(mlxsw_afa);
}
static void mlxsw_afa_set_goto_set(struct mlxsw_afa_set *set,
enum mlxsw_afa_set_goto_binding_cmd cmd,
u16 group_id)
{
char *actions = set->ht_key.enc_actions;
mlxsw_afa_set_type_set(actions, MLXSW_AFA_SET_TYPE_GOTO);
mlxsw_afa_set_goto_g_set(actions, true);
mlxsw_afa_set_goto_binding_cmd_set(actions, cmd);
mlxsw_afa_set_goto_next_binding_set(actions, group_id);
}
static void mlxsw_afa_set_next_set(struct mlxsw_afa_set *set,
u32 next_set_kvdl_index)
{
char *actions = set->ht_key.enc_actions;
mlxsw_afa_set_type_set(actions, MLXSW_AFA_SET_TYPE_NEXT);
mlxsw_afa_set_next_action_set_ptr_set(actions, next_set_kvdl_index);
}
static struct mlxsw_afa_set *mlxsw_afa_set_create(bool is_first)
{
struct mlxsw_afa_set *set;
set = kzalloc(sizeof(*set), GFP_KERNEL);
if (!set)
return NULL;
mlxsw_afa_set_goto_set(set, MLXSW_AFA_SET_GOTO_BINDING_CMD_TERM, 0);
set->ht_key.is_first = is_first;
set->ref_count = 1;
return set;
}
static void mlxsw_afa_set_destroy(struct mlxsw_afa_set *set)
{
kfree(set);
}
static int mlxsw_afa_set_share(struct mlxsw_afa *mlxsw_afa,
struct mlxsw_afa_set *set)
{
int err;
err = rhashtable_insert_fast(&mlxsw_afa->set_ht, &set->ht_node,
mlxsw_afa_set_ht_params);
if (err)
return err;
err = mlxsw_afa->ops->kvdl_set_add(mlxsw_afa->ops_priv,
&set->kvdl_index,
set->ht_key.enc_actions,
set->ht_key.is_first);
if (err)
goto err_kvdl_set_add;
set->shared = true;
set->prev = NULL;
return 0;
err_kvdl_set_add:
rhashtable_remove_fast(&mlxsw_afa->set_ht, &set->ht_node,
mlxsw_afa_set_ht_params);
return err;
}
static void mlxsw_afa_set_unshare(struct mlxsw_afa *mlxsw_afa,
struct mlxsw_afa_set *set)
{
mlxsw_afa->ops->kvdl_set_del(mlxsw_afa->ops_priv,
set->kvdl_index,
set->ht_key.is_first);
rhashtable_remove_fast(&mlxsw_afa->set_ht, &set->ht_node,
mlxsw_afa_set_ht_params);
set->shared = false;
}
static void mlxsw_afa_set_put(struct mlxsw_afa *mlxsw_afa,
struct mlxsw_afa_set *set)
{
if (--set->ref_count)
return;
if (set->shared)
mlxsw_afa_set_unshare(mlxsw_afa, set);
mlxsw_afa_set_destroy(set);
}
static struct mlxsw_afa_set *mlxsw_afa_set_get(struct mlxsw_afa *mlxsw_afa,
struct mlxsw_afa_set *orig_set)
{
struct mlxsw_afa_set *set;
int err;
set = rhashtable_lookup_fast(&mlxsw_afa->set_ht, &orig_set->ht_key,
mlxsw_afa_set_ht_params);
if (set) {
set->ref_count++;
mlxsw_afa_set_put(mlxsw_afa, orig_set);
} else {
set = orig_set;
err = mlxsw_afa_set_share(mlxsw_afa, set);
if (err)
return ERR_PTR(err);
}
return set;
}
struct mlxsw_afa_block *mlxsw_afa_block_create(struct mlxsw_afa *mlxsw_afa)
{
struct mlxsw_afa_block *block;
block = kzalloc(sizeof(*block), GFP_KERNEL);
if (!block)
return NULL;
INIT_LIST_HEAD(&block->fwd_entry_ref_list);
block->afa = mlxsw_afa;
block->first_set = mlxsw_afa_set_create(true);
if (!block->first_set)
goto err_first_set_create;
block->cur_set = block->first_set;
return block;
err_first_set_create:
kfree(block);
return NULL;
}
void mlxsw_afa_block_destroy(struct mlxsw_afa_block *block)
{
struct mlxsw_afa_set *set = block->first_set;
struct mlxsw_afa_set *next_set;
do {
next_set = set->next;
mlxsw_afa_set_put(block->afa, set);
set = next_set;
} while (set);
mlxsw_afa_fwd_entry_refs_destroy(block);
kfree(block);
}
int mlxsw_afa_block_commit(struct mlxsw_afa_block *block)
{
struct mlxsw_afa_set *set = block->cur_set;
struct mlxsw_afa_set *prev_set;
block->cur_set = NULL;
block->finished = true;
do {
prev_set = set->prev;
set = mlxsw_afa_set_get(block->afa, set);
if (IS_ERR(set))
return PTR_ERR(set);
if (prev_set) {
prev_set->next = set;
mlxsw_afa_set_next_set(prev_set, set->kvdl_index);
set = prev_set;
}
} while (prev_set);
block->first_set = set;
return 0;
}
char *mlxsw_afa_block_first_set(struct mlxsw_afa_block *block)
{
return block->first_set->ht_key.enc_actions;
}
u32 mlxsw_afa_block_first_set_kvdl_index(struct mlxsw_afa_block *block)
{
return block->first_set->kvdl_index;
}
void mlxsw_afa_block_continue(struct mlxsw_afa_block *block)
{
if (WARN_ON(block->finished))
return;
mlxsw_afa_set_goto_set(block->cur_set,
MLXSW_AFA_SET_GOTO_BINDING_CMD_NONE, 0);
block->finished = true;
}
void mlxsw_afa_block_jump(struct mlxsw_afa_block *block, u16 group_id)
{
if (WARN_ON(block->finished))
return;
mlxsw_afa_set_goto_set(block->cur_set,
MLXSW_AFA_SET_GOTO_BINDING_CMD_JUMP, group_id);
block->finished = true;
}
static struct mlxsw_afa_fwd_entry *
mlxsw_afa_fwd_entry_create(struct mlxsw_afa *mlxsw_afa, u8 local_port)
{
struct mlxsw_afa_fwd_entry *fwd_entry;
int err;
fwd_entry = kzalloc(sizeof(*fwd_entry), GFP_KERNEL);
if (!fwd_entry)
return ERR_PTR(-ENOMEM);
fwd_entry->ht_key.local_port = local_port;
fwd_entry->ref_count = 1;
err = rhashtable_insert_fast(&mlxsw_afa->fwd_entry_ht,
&fwd_entry->ht_node,
mlxsw_afa_fwd_entry_ht_params);
if (err)
goto err_rhashtable_insert;
err = mlxsw_afa->ops->kvdl_fwd_entry_add(mlxsw_afa->ops_priv,
&fwd_entry->kvdl_index,
local_port);
if (err)
goto err_kvdl_fwd_entry_add;
return fwd_entry;
err_kvdl_fwd_entry_add:
rhashtable_remove_fast(&mlxsw_afa->fwd_entry_ht, &fwd_entry->ht_node,
mlxsw_afa_fwd_entry_ht_params);
err_rhashtable_insert:
kfree(fwd_entry);
return ERR_PTR(err);
}
static void mlxsw_afa_fwd_entry_destroy(struct mlxsw_afa *mlxsw_afa,
struct mlxsw_afa_fwd_entry *fwd_entry)
{
mlxsw_afa->ops->kvdl_fwd_entry_del(mlxsw_afa->ops_priv,
fwd_entry->kvdl_index);
rhashtable_remove_fast(&mlxsw_afa->fwd_entry_ht, &fwd_entry->ht_node,
mlxsw_afa_fwd_entry_ht_params);
kfree(fwd_entry);
}
static struct mlxsw_afa_fwd_entry *
mlxsw_afa_fwd_entry_get(struct mlxsw_afa *mlxsw_afa, u8 local_port)
{
struct mlxsw_afa_fwd_entry_ht_key ht_key = {0};
struct mlxsw_afa_fwd_entry *fwd_entry;
ht_key.local_port = local_port;
fwd_entry = rhashtable_lookup_fast(&mlxsw_afa->fwd_entry_ht, &ht_key,
mlxsw_afa_fwd_entry_ht_params);
if (fwd_entry) {
fwd_entry->ref_count++;
return fwd_entry;
}
return mlxsw_afa_fwd_entry_create(mlxsw_afa, local_port);
}
static void mlxsw_afa_fwd_entry_put(struct mlxsw_afa *mlxsw_afa,
struct mlxsw_afa_fwd_entry *fwd_entry)
{
if (--fwd_entry->ref_count)
return;
mlxsw_afa_fwd_entry_destroy(mlxsw_afa, fwd_entry);
}
static struct mlxsw_afa_fwd_entry_ref *
mlxsw_afa_fwd_entry_ref_create(struct mlxsw_afa_block *block, u8 local_port)
{
struct mlxsw_afa_fwd_entry_ref *fwd_entry_ref;
struct mlxsw_afa_fwd_entry *fwd_entry;
int err;
fwd_entry_ref = kzalloc(sizeof(*fwd_entry_ref), GFP_KERNEL);
if (!fwd_entry_ref)
return ERR_PTR(-ENOMEM);
fwd_entry = mlxsw_afa_fwd_entry_get(block->afa, local_port);
if (IS_ERR(fwd_entry)) {
err = PTR_ERR(fwd_entry);
goto err_fwd_entry_get;
}
fwd_entry_ref->fwd_entry = fwd_entry;
list_add(&fwd_entry_ref->list, &block->fwd_entry_ref_list);
return fwd_entry_ref;
err_fwd_entry_get:
kfree(fwd_entry_ref);
return ERR_PTR(err);
}
static void
mlxsw_afa_fwd_entry_ref_destroy(struct mlxsw_afa_block *block,
struct mlxsw_afa_fwd_entry_ref *fwd_entry_ref)
{
list_del(&fwd_entry_ref->list);
mlxsw_afa_fwd_entry_put(block->afa, fwd_entry_ref->fwd_entry);
kfree(fwd_entry_ref);
}
static void mlxsw_afa_fwd_entry_refs_destroy(struct mlxsw_afa_block *block)
{
struct mlxsw_afa_fwd_entry_ref *fwd_entry_ref;
struct mlxsw_afa_fwd_entry_ref *tmp;
list_for_each_entry_safe(fwd_entry_ref, tmp,
&block->fwd_entry_ref_list, list)
mlxsw_afa_fwd_entry_ref_destroy(block, fwd_entry_ref);
}
static char *mlxsw_afa_block_append_action(struct mlxsw_afa_block *block,
u8 action_code, u8 action_size)
{
char *oneact;
char *actions;
if (WARN_ON(block->finished))
return NULL;
if (block->cur_act_index + action_size >
block->afa->max_acts_per_set) {
struct mlxsw_afa_set *set;
set = mlxsw_afa_set_create(false);
if (!set)
return NULL;
set->prev = block->cur_set;
block->cur_act_index = 0;
block->cur_set->next = set;
block->cur_set = set;
}
actions = block->cur_set->ht_key.enc_actions;
oneact = actions + block->cur_act_index * MLXSW_AFA_ONE_ACTION_LEN;
block->cur_act_index += action_size;
mlxsw_afa_all_action_type_set(oneact, action_code);
return oneact + MLXSW_AFA_PAYLOAD_OFFSET;
}
static inline void
mlxsw_afa_trapdisc_pack(char *payload,
enum mlxsw_afa_trapdisc_forward_action forward_action)
{
mlxsw_afa_trapdisc_forward_action_set(payload, forward_action);
}
int mlxsw_afa_block_append_drop(struct mlxsw_afa_block *block)
{
char *act = mlxsw_afa_block_append_action(block,
MLXSW_AFA_TRAPDISC_CODE,
MLXSW_AFA_TRAPDISC_SIZE);
if (!act)
return -ENOBUFS;
mlxsw_afa_trapdisc_pack(act, MLXSW_AFA_TRAPDISC_FORWARD_ACTION_DISCARD);
return 0;
}
static inline void
mlxsw_afa_forward_pack(char *payload, enum mlxsw_afa_forward_type type,
u32 pbs_ptr, bool in_port)
{
mlxsw_afa_forward_type_set(payload, type);
mlxsw_afa_forward_pbs_ptr_set(payload, pbs_ptr);
mlxsw_afa_forward_in_port_set(payload, in_port);
}
int mlxsw_afa_block_append_fwd(struct mlxsw_afa_block *block,
u8 local_port, bool in_port)
{
struct mlxsw_afa_fwd_entry_ref *fwd_entry_ref;
u32 kvdl_index;
char *act;
int err;
if (in_port)
return -EOPNOTSUPP;
fwd_entry_ref = mlxsw_afa_fwd_entry_ref_create(block, local_port);
if (IS_ERR(fwd_entry_ref))
return PTR_ERR(fwd_entry_ref);
kvdl_index = fwd_entry_ref->fwd_entry->kvdl_index;
act = mlxsw_afa_block_append_action(block, MLXSW_AFA_FORWARD_CODE,
MLXSW_AFA_FORWARD_SIZE);
if (!act) {
err = -ENOBUFS;
goto err_append_action;
}
mlxsw_afa_forward_pack(act, MLXSW_AFA_FORWARD_TYPE_PBS,
kvdl_index, in_port);
return 0;
err_append_action:
mlxsw_afa_fwd_entry_ref_destroy(block, fwd_entry_ref);
return err;
}
