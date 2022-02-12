static struct bpf_map *find_and_alloc_map(union bpf_attr *attr)
{
struct bpf_map_type_list *tl;
struct bpf_map *map;
list_for_each_entry(tl, &bpf_map_types, list_node) {
if (tl->type == attr->map_type) {
map = tl->ops->map_alloc(attr);
if (IS_ERR(map))
return map;
map->ops = tl->ops;
map->map_type = attr->map_type;
return map;
}
}
return ERR_PTR(-EINVAL);
}
void bpf_register_map_type(struct bpf_map_type_list *tl)
{
list_add(&tl->list_node, &bpf_map_types);
}
static void bpf_map_free_deferred(struct work_struct *work)
{
struct bpf_map *map = container_of(work, struct bpf_map, work);
map->ops->map_free(map);
}
void bpf_map_put(struct bpf_map *map)
{
if (atomic_dec_and_test(&map->refcnt)) {
INIT_WORK(&map->work, bpf_map_free_deferred);
schedule_work(&map->work);
}
}
static int bpf_map_release(struct inode *inode, struct file *filp)
{
struct bpf_map *map = filp->private_data;
bpf_map_put(map);
return 0;
}
static int map_create(union bpf_attr *attr)
{
struct bpf_map *map;
int err;
err = CHECK_ATTR(BPF_MAP_CREATE);
if (err)
return -EINVAL;
map = find_and_alloc_map(attr);
if (IS_ERR(map))
return PTR_ERR(map);
atomic_set(&map->refcnt, 1);
err = anon_inode_getfd("bpf-map", &bpf_map_fops, map, O_RDWR | O_CLOEXEC);
if (err < 0)
goto free_map;
return err;
free_map:
map->ops->map_free(map);
return err;
}
struct bpf_map *bpf_map_get(struct fd f)
{
struct bpf_map *map;
if (!f.file)
return ERR_PTR(-EBADF);
if (f.file->f_op != &bpf_map_fops) {
fdput(f);
return ERR_PTR(-EINVAL);
}
map = f.file->private_data;
return map;
}
static void __user *u64_to_ptr(__u64 val)
{
return (void __user *) (unsigned long) val;
}
static int map_lookup_elem(union bpf_attr *attr)
{
void __user *ukey = u64_to_ptr(attr->key);
void __user *uvalue = u64_to_ptr(attr->value);
int ufd = attr->map_fd;
struct fd f = fdget(ufd);
struct bpf_map *map;
void *key, *value;
int err;
if (CHECK_ATTR(BPF_MAP_LOOKUP_ELEM))
return -EINVAL;
map = bpf_map_get(f);
if (IS_ERR(map))
return PTR_ERR(map);
err = -ENOMEM;
key = kmalloc(map->key_size, GFP_USER);
if (!key)
goto err_put;
err = -EFAULT;
if (copy_from_user(key, ukey, map->key_size) != 0)
goto free_key;
err = -ESRCH;
rcu_read_lock();
value = map->ops->map_lookup_elem(map, key);
if (!value)
goto err_unlock;
err = -EFAULT;
if (copy_to_user(uvalue, value, map->value_size) != 0)
goto err_unlock;
err = 0;
err_unlock:
rcu_read_unlock();
free_key:
kfree(key);
err_put:
fdput(f);
return err;
}
static int map_update_elem(union bpf_attr *attr)
{
void __user *ukey = u64_to_ptr(attr->key);
void __user *uvalue = u64_to_ptr(attr->value);
int ufd = attr->map_fd;
struct fd f = fdget(ufd);
struct bpf_map *map;
void *key, *value;
int err;
if (CHECK_ATTR(BPF_MAP_UPDATE_ELEM))
return -EINVAL;
map = bpf_map_get(f);
if (IS_ERR(map))
return PTR_ERR(map);
err = -ENOMEM;
key = kmalloc(map->key_size, GFP_USER);
if (!key)
goto err_put;
err = -EFAULT;
if (copy_from_user(key, ukey, map->key_size) != 0)
goto free_key;
err = -ENOMEM;
value = kmalloc(map->value_size, GFP_USER);
if (!value)
goto free_key;
err = -EFAULT;
if (copy_from_user(value, uvalue, map->value_size) != 0)
goto free_value;
rcu_read_lock();
err = map->ops->map_update_elem(map, key, value);
rcu_read_unlock();
free_value:
kfree(value);
free_key:
kfree(key);
err_put:
fdput(f);
return err;
}
static int map_delete_elem(union bpf_attr *attr)
{
void __user *ukey = u64_to_ptr(attr->key);
int ufd = attr->map_fd;
struct fd f = fdget(ufd);
struct bpf_map *map;
void *key;
int err;
if (CHECK_ATTR(BPF_MAP_DELETE_ELEM))
return -EINVAL;
map = bpf_map_get(f);
if (IS_ERR(map))
return PTR_ERR(map);
err = -ENOMEM;
key = kmalloc(map->key_size, GFP_USER);
if (!key)
goto err_put;
err = -EFAULT;
if (copy_from_user(key, ukey, map->key_size) != 0)
goto free_key;
rcu_read_lock();
err = map->ops->map_delete_elem(map, key);
rcu_read_unlock();
free_key:
kfree(key);
err_put:
fdput(f);
return err;
}
static int map_get_next_key(union bpf_attr *attr)
{
void __user *ukey = u64_to_ptr(attr->key);
void __user *unext_key = u64_to_ptr(attr->next_key);
int ufd = attr->map_fd;
struct fd f = fdget(ufd);
struct bpf_map *map;
void *key, *next_key;
int err;
if (CHECK_ATTR(BPF_MAP_GET_NEXT_KEY))
return -EINVAL;
map = bpf_map_get(f);
if (IS_ERR(map))
return PTR_ERR(map);
err = -ENOMEM;
key = kmalloc(map->key_size, GFP_USER);
if (!key)
goto err_put;
err = -EFAULT;
if (copy_from_user(key, ukey, map->key_size) != 0)
goto free_key;
err = -ENOMEM;
next_key = kmalloc(map->key_size, GFP_USER);
if (!next_key)
goto free_key;
rcu_read_lock();
err = map->ops->map_get_next_key(map, key, next_key);
rcu_read_unlock();
if (err)
goto free_next_key;
err = -EFAULT;
if (copy_to_user(unext_key, next_key, map->key_size) != 0)
goto free_next_key;
err = 0;
free_next_key:
kfree(next_key);
free_key:
kfree(key);
err_put:
fdput(f);
return err;
}
static int find_prog_type(enum bpf_prog_type type, struct bpf_prog *prog)
{
struct bpf_prog_type_list *tl;
list_for_each_entry(tl, &bpf_prog_types, list_node) {
if (tl->type == type) {
prog->aux->ops = tl->ops;
prog->aux->prog_type = type;
return 0;
}
}
return -EINVAL;
}
void bpf_register_prog_type(struct bpf_prog_type_list *tl)
{
list_add(&tl->list_node, &bpf_prog_types);
}
static void fixup_bpf_calls(struct bpf_prog *prog)
{
const struct bpf_func_proto *fn;
int i;
for (i = 0; i < prog->len; i++) {
struct bpf_insn *insn = &prog->insnsi[i];
if (insn->code == (BPF_JMP | BPF_CALL)) {
BUG_ON(!prog->aux->ops->get_func_proto);
fn = prog->aux->ops->get_func_proto(insn->imm);
BUG_ON(!fn->func);
insn->imm = fn->func - __bpf_call_base;
}
}
}
static void free_used_maps(struct bpf_prog_aux *aux)
{
int i;
for (i = 0; i < aux->used_map_cnt; i++)
bpf_map_put(aux->used_maps[i]);
kfree(aux->used_maps);
}
void bpf_prog_put(struct bpf_prog *prog)
{
if (atomic_dec_and_test(&prog->aux->refcnt)) {
free_used_maps(prog->aux);
bpf_prog_free(prog);
}
}
static int bpf_prog_release(struct inode *inode, struct file *filp)
{
struct bpf_prog *prog = filp->private_data;
bpf_prog_put(prog);
return 0;
}
static struct bpf_prog *get_prog(struct fd f)
{
struct bpf_prog *prog;
if (!f.file)
return ERR_PTR(-EBADF);
if (f.file->f_op != &bpf_prog_fops) {
fdput(f);
return ERR_PTR(-EINVAL);
}
prog = f.file->private_data;
return prog;
}
struct bpf_prog *bpf_prog_get(u32 ufd)
{
struct fd f = fdget(ufd);
struct bpf_prog *prog;
prog = get_prog(f);
if (IS_ERR(prog))
return prog;
atomic_inc(&prog->aux->refcnt);
fdput(f);
return prog;
}
static int bpf_prog_load(union bpf_attr *attr)
{
enum bpf_prog_type type = attr->prog_type;
struct bpf_prog *prog;
int err;
char license[128];
bool is_gpl;
if (CHECK_ATTR(BPF_PROG_LOAD))
return -EINVAL;
if (strncpy_from_user(license, u64_to_ptr(attr->license),
sizeof(license) - 1) < 0)
return -EFAULT;
license[sizeof(license) - 1] = 0;
is_gpl = license_is_gpl_compatible(license);
if (attr->insn_cnt >= BPF_MAXINSNS)
return -EINVAL;
prog = bpf_prog_alloc(bpf_prog_size(attr->insn_cnt), GFP_USER);
if (!prog)
return -ENOMEM;
prog->len = attr->insn_cnt;
err = -EFAULT;
if (copy_from_user(prog->insns, u64_to_ptr(attr->insns),
prog->len * sizeof(struct bpf_insn)) != 0)
goto free_prog;
prog->orig_prog = NULL;
prog->jited = false;
atomic_set(&prog->aux->refcnt, 1);
prog->aux->is_gpl_compatible = is_gpl;
err = find_prog_type(type, prog);
if (err < 0)
goto free_prog;
err = bpf_check(prog, attr);
if (err < 0)
goto free_used_maps;
fixup_bpf_calls(prog);
bpf_prog_select_runtime(prog);
err = anon_inode_getfd("bpf-prog", &bpf_prog_fops, prog, O_RDWR | O_CLOEXEC);
if (err < 0)
goto free_used_maps;
return err;
free_used_maps:
free_used_maps(prog->aux);
free_prog:
bpf_prog_free(prog);
return err;
}
