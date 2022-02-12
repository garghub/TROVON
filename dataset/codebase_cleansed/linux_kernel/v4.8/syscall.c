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
int bpf_map_precharge_memlock(u32 pages)
{
struct user_struct *user = get_current_user();
unsigned long memlock_limit, cur;
memlock_limit = rlimit(RLIMIT_MEMLOCK) >> PAGE_SHIFT;
cur = atomic_long_read(&user->locked_vm);
free_uid(user);
if (cur + pages > memlock_limit)
return -EPERM;
return 0;
}
static int bpf_map_charge_memlock(struct bpf_map *map)
{
struct user_struct *user = get_current_user();
unsigned long memlock_limit;
memlock_limit = rlimit(RLIMIT_MEMLOCK) >> PAGE_SHIFT;
atomic_long_add(map->pages, &user->locked_vm);
if (atomic_long_read(&user->locked_vm) > memlock_limit) {
atomic_long_sub(map->pages, &user->locked_vm);
free_uid(user);
return -EPERM;
}
map->user = user;
return 0;
}
static void bpf_map_uncharge_memlock(struct bpf_map *map)
{
struct user_struct *user = map->user;
atomic_long_sub(map->pages, &user->locked_vm);
free_uid(user);
}
static void bpf_map_free_deferred(struct work_struct *work)
{
struct bpf_map *map = container_of(work, struct bpf_map, work);
bpf_map_uncharge_memlock(map);
map->ops->map_free(map);
}
static void bpf_map_put_uref(struct bpf_map *map)
{
if (atomic_dec_and_test(&map->usercnt)) {
if (map->map_type == BPF_MAP_TYPE_PROG_ARRAY)
bpf_fd_array_map_clear(map);
}
}
void bpf_map_put(struct bpf_map *map)
{
if (atomic_dec_and_test(&map->refcnt)) {
INIT_WORK(&map->work, bpf_map_free_deferred);
schedule_work(&map->work);
}
}
void bpf_map_put_with_uref(struct bpf_map *map)
{
bpf_map_put_uref(map);
bpf_map_put(map);
}
static int bpf_map_release(struct inode *inode, struct file *filp)
{
struct bpf_map *map = filp->private_data;
if (map->ops->map_release)
map->ops->map_release(map, filp);
bpf_map_put_with_uref(map);
return 0;
}
static void bpf_map_show_fdinfo(struct seq_file *m, struct file *filp)
{
const struct bpf_map *map = filp->private_data;
seq_printf(m,
"map_type:\t%u\n"
"key_size:\t%u\n"
"value_size:\t%u\n"
"max_entries:\t%u\n"
"map_flags:\t%#x\n",
map->map_type,
map->key_size,
map->value_size,
map->max_entries,
map->map_flags);
}
int bpf_map_new_fd(struct bpf_map *map)
{
return anon_inode_getfd("bpf-map", &bpf_map_fops, map,
O_RDWR | O_CLOEXEC);
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
atomic_set(&map->usercnt, 1);
err = bpf_map_charge_memlock(map);
if (err)
goto free_map;
err = bpf_map_new_fd(map);
if (err < 0)
goto free_map;
return err;
free_map:
map->ops->map_free(map);
return err;
}
struct bpf_map *__bpf_map_get(struct fd f)
{
if (!f.file)
return ERR_PTR(-EBADF);
if (f.file->f_op != &bpf_map_fops) {
fdput(f);
return ERR_PTR(-EINVAL);
}
return f.file->private_data;
}
struct bpf_map *bpf_map_inc(struct bpf_map *map, bool uref)
{
if (atomic_inc_return(&map->refcnt) > BPF_MAX_REFCNT) {
atomic_dec(&map->refcnt);
return ERR_PTR(-EBUSY);
}
if (uref)
atomic_inc(&map->usercnt);
return map;
}
struct bpf_map *bpf_map_get_with_uref(u32 ufd)
{
struct fd f = fdget(ufd);
struct bpf_map *map;
map = __bpf_map_get(f);
if (IS_ERR(map))
return map;
map = bpf_map_inc(map, true);
fdput(f);
return map;
}
static void __user *u64_to_ptr(__u64 val)
{
return (void __user *) (unsigned long) val;
}
int __weak bpf_stackmap_copy(struct bpf_map *map, void *key, void *value)
{
return -ENOTSUPP;
}
static int map_lookup_elem(union bpf_attr *attr)
{
void __user *ukey = u64_to_ptr(attr->key);
void __user *uvalue = u64_to_ptr(attr->value);
int ufd = attr->map_fd;
struct bpf_map *map;
void *key, *value, *ptr;
u32 value_size;
struct fd f;
int err;
if (CHECK_ATTR(BPF_MAP_LOOKUP_ELEM))
return -EINVAL;
f = fdget(ufd);
map = __bpf_map_get(f);
if (IS_ERR(map))
return PTR_ERR(map);
err = -ENOMEM;
key = kmalloc(map->key_size, GFP_USER);
if (!key)
goto err_put;
err = -EFAULT;
if (copy_from_user(key, ukey, map->key_size) != 0)
goto free_key;
if (map->map_type == BPF_MAP_TYPE_PERCPU_HASH ||
map->map_type == BPF_MAP_TYPE_PERCPU_ARRAY)
value_size = round_up(map->value_size, 8) * num_possible_cpus();
else
value_size = map->value_size;
err = -ENOMEM;
value = kmalloc(value_size, GFP_USER | __GFP_NOWARN);
if (!value)
goto free_key;
if (map->map_type == BPF_MAP_TYPE_PERCPU_HASH) {
err = bpf_percpu_hash_copy(map, key, value);
} else if (map->map_type == BPF_MAP_TYPE_PERCPU_ARRAY) {
err = bpf_percpu_array_copy(map, key, value);
} else if (map->map_type == BPF_MAP_TYPE_STACK_TRACE) {
err = bpf_stackmap_copy(map, key, value);
} else {
rcu_read_lock();
ptr = map->ops->map_lookup_elem(map, key);
if (ptr)
memcpy(value, ptr, value_size);
rcu_read_unlock();
err = ptr ? 0 : -ENOENT;
}
if (err)
goto free_value;
err = -EFAULT;
if (copy_to_user(uvalue, value, value_size) != 0)
goto free_value;
err = 0;
free_value:
kfree(value);
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
struct bpf_map *map;
void *key, *value;
u32 value_size;
struct fd f;
int err;
if (CHECK_ATTR(BPF_MAP_UPDATE_ELEM))
return -EINVAL;
f = fdget(ufd);
map = __bpf_map_get(f);
if (IS_ERR(map))
return PTR_ERR(map);
err = -ENOMEM;
key = kmalloc(map->key_size, GFP_USER);
if (!key)
goto err_put;
err = -EFAULT;
if (copy_from_user(key, ukey, map->key_size) != 0)
goto free_key;
if (map->map_type == BPF_MAP_TYPE_PERCPU_HASH ||
map->map_type == BPF_MAP_TYPE_PERCPU_ARRAY)
value_size = round_up(map->value_size, 8) * num_possible_cpus();
else
value_size = map->value_size;
err = -ENOMEM;
value = kmalloc(value_size, GFP_USER | __GFP_NOWARN);
if (!value)
goto free_key;
err = -EFAULT;
if (copy_from_user(value, uvalue, value_size) != 0)
goto free_value;
preempt_disable();
__this_cpu_inc(bpf_prog_active);
if (map->map_type == BPF_MAP_TYPE_PERCPU_HASH) {
err = bpf_percpu_hash_update(map, key, value, attr->flags);
} else if (map->map_type == BPF_MAP_TYPE_PERCPU_ARRAY) {
err = bpf_percpu_array_update(map, key, value, attr->flags);
} else if (map->map_type == BPF_MAP_TYPE_PERF_EVENT_ARRAY ||
map->map_type == BPF_MAP_TYPE_PROG_ARRAY ||
map->map_type == BPF_MAP_TYPE_CGROUP_ARRAY) {
rcu_read_lock();
err = bpf_fd_array_map_update_elem(map, f.file, key, value,
attr->flags);
rcu_read_unlock();
} else {
rcu_read_lock();
err = map->ops->map_update_elem(map, key, value, attr->flags);
rcu_read_unlock();
}
__this_cpu_dec(bpf_prog_active);
preempt_enable();
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
struct bpf_map *map;
struct fd f;
void *key;
int err;
if (CHECK_ATTR(BPF_MAP_DELETE_ELEM))
return -EINVAL;
f = fdget(ufd);
map = __bpf_map_get(f);
if (IS_ERR(map))
return PTR_ERR(map);
err = -ENOMEM;
key = kmalloc(map->key_size, GFP_USER);
if (!key)
goto err_put;
err = -EFAULT;
if (copy_from_user(key, ukey, map->key_size) != 0)
goto free_key;
preempt_disable();
__this_cpu_inc(bpf_prog_active);
rcu_read_lock();
err = map->ops->map_delete_elem(map, key);
rcu_read_unlock();
__this_cpu_dec(bpf_prog_active);
preempt_enable();
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
struct bpf_map *map;
void *key, *next_key;
struct fd f;
int err;
if (CHECK_ATTR(BPF_MAP_GET_NEXT_KEY))
return -EINVAL;
f = fdget(ufd);
map = __bpf_map_get(f);
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
prog->type = type;
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
if (insn->imm == BPF_FUNC_get_route_realm)
prog->dst_needed = 1;
if (insn->imm == BPF_FUNC_get_prandom_u32)
bpf_user_rnd_init_once();
if (insn->imm == BPF_FUNC_tail_call) {
insn->imm = 0;
insn->code |= BPF_X;
continue;
}
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
static int bpf_prog_charge_memlock(struct bpf_prog *prog)
{
struct user_struct *user = get_current_user();
unsigned long memlock_limit;
memlock_limit = rlimit(RLIMIT_MEMLOCK) >> PAGE_SHIFT;
atomic_long_add(prog->pages, &user->locked_vm);
if (atomic_long_read(&user->locked_vm) > memlock_limit) {
atomic_long_sub(prog->pages, &user->locked_vm);
free_uid(user);
return -EPERM;
}
prog->aux->user = user;
return 0;
}
static void bpf_prog_uncharge_memlock(struct bpf_prog *prog)
{
struct user_struct *user = prog->aux->user;
atomic_long_sub(prog->pages, &user->locked_vm);
free_uid(user);
}
static void __bpf_prog_put_rcu(struct rcu_head *rcu)
{
struct bpf_prog_aux *aux = container_of(rcu, struct bpf_prog_aux, rcu);
free_used_maps(aux);
bpf_prog_uncharge_memlock(aux->prog);
bpf_prog_free(aux->prog);
}
void bpf_prog_put(struct bpf_prog *prog)
{
if (atomic_dec_and_test(&prog->aux->refcnt))
call_rcu(&prog->aux->rcu, __bpf_prog_put_rcu);
}
static int bpf_prog_release(struct inode *inode, struct file *filp)
{
struct bpf_prog *prog = filp->private_data;
bpf_prog_put(prog);
return 0;
}
int bpf_prog_new_fd(struct bpf_prog *prog)
{
return anon_inode_getfd("bpf-prog", &bpf_prog_fops, prog,
O_RDWR | O_CLOEXEC);
}
static struct bpf_prog *____bpf_prog_get(struct fd f)
{
if (!f.file)
return ERR_PTR(-EBADF);
if (f.file->f_op != &bpf_prog_fops) {
fdput(f);
return ERR_PTR(-EINVAL);
}
return f.file->private_data;
}
struct bpf_prog *bpf_prog_add(struct bpf_prog *prog, int i)
{
if (atomic_add_return(i, &prog->aux->refcnt) > BPF_MAX_REFCNT) {
atomic_sub(i, &prog->aux->refcnt);
return ERR_PTR(-EBUSY);
}
return prog;
}
struct bpf_prog *bpf_prog_inc(struct bpf_prog *prog)
{
return bpf_prog_add(prog, 1);
}
static struct bpf_prog *__bpf_prog_get(u32 ufd, enum bpf_prog_type *type)
{
struct fd f = fdget(ufd);
struct bpf_prog *prog;
prog = ____bpf_prog_get(f);
if (IS_ERR(prog))
return prog;
if (type && prog->type != *type) {
prog = ERR_PTR(-EINVAL);
goto out;
}
prog = bpf_prog_inc(prog);
out:
fdput(f);
return prog;
}
struct bpf_prog *bpf_prog_get(u32 ufd)
{
return __bpf_prog_get(ufd, NULL);
}
struct bpf_prog *bpf_prog_get_type(u32 ufd, enum bpf_prog_type type)
{
return __bpf_prog_get(ufd, &type);
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
if (type == BPF_PROG_TYPE_KPROBE &&
attr->kern_version != LINUX_VERSION_CODE)
return -EINVAL;
if (type != BPF_PROG_TYPE_SOCKET_FILTER && !capable(CAP_SYS_ADMIN))
return -EPERM;
prog = bpf_prog_alloc(bpf_prog_size(attr->insn_cnt), GFP_USER);
if (!prog)
return -ENOMEM;
err = bpf_prog_charge_memlock(prog);
if (err)
goto free_prog_nouncharge;
prog->len = attr->insn_cnt;
err = -EFAULT;
if (copy_from_user(prog->insns, u64_to_ptr(attr->insns),
prog->len * sizeof(struct bpf_insn)) != 0)
goto free_prog;
prog->orig_prog = NULL;
prog->jited = 0;
atomic_set(&prog->aux->refcnt, 1);
prog->gpl_compatible = is_gpl ? 1 : 0;
err = find_prog_type(type, prog);
if (err < 0)
goto free_prog;
err = bpf_check(&prog, attr);
if (err < 0)
goto free_used_maps;
fixup_bpf_calls(prog);
prog = bpf_prog_select_runtime(prog, &err);
if (err < 0)
goto free_used_maps;
err = bpf_prog_new_fd(prog);
if (err < 0)
goto free_used_maps;
return err;
free_used_maps:
free_used_maps(prog->aux);
free_prog:
bpf_prog_uncharge_memlock(prog);
free_prog_nouncharge:
bpf_prog_free(prog);
return err;
}
static int bpf_obj_pin(const union bpf_attr *attr)
{
if (CHECK_ATTR(BPF_OBJ))
return -EINVAL;
return bpf_obj_pin_user(attr->bpf_fd, u64_to_ptr(attr->pathname));
}
static int bpf_obj_get(const union bpf_attr *attr)
{
if (CHECK_ATTR(BPF_OBJ) || attr->bpf_fd != 0)
return -EINVAL;
return bpf_obj_get_user(u64_to_ptr(attr->pathname));
}
