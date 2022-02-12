static inline struct set_elem *
list_set_elem(const struct list_set *map, u32 id)
{
return (struct set_elem *)((void *)map->members + id * map->dsize);
}
static inline struct set_telem *
list_set_telem(const struct list_set *map, u32 id)
{
return (struct set_telem *)((void *)map->members + id * map->dsize);
}
static inline bool
list_set_timeout(const struct list_set *map, u32 id)
{
const struct set_telem *elem = list_set_telem(map, id);
return ip_set_timeout_test(elem->timeout);
}
static inline bool
list_set_expired(const struct list_set *map, u32 id)
{
const struct set_telem *elem = list_set_telem(map, id);
return ip_set_timeout_expired(elem->timeout);
}
static int
list_set_kadt(struct ip_set *set, const struct sk_buff *skb,
enum ipset_adt adt, u8 pf, u8 dim, u8 flags)
{
struct list_set *map = set->data;
struct set_elem *elem;
u32 i;
int ret;
for (i = 0; i < map->size; i++) {
elem = list_set_elem(map, i);
if (elem->id == IPSET_INVALID_ID)
return 0;
if (with_timeout(map->timeout) && list_set_expired(map, i))
continue;
switch (adt) {
case IPSET_TEST:
ret = ip_set_test(elem->id, skb, pf, dim, flags);
if (ret > 0)
return ret;
break;
case IPSET_ADD:
ret = ip_set_add(elem->id, skb, pf, dim, flags);
if (ret == 0)
return ret;
break;
case IPSET_DEL:
ret = ip_set_del(elem->id, skb, pf, dim, flags);
if (ret == 0)
return ret;
break;
default:
break;
}
}
return -EINVAL;
}
static bool
next_id_eq(const struct list_set *map, u32 i, ip_set_id_t id)
{
const struct set_elem *elem;
if (i + 1 < map->size) {
elem = list_set_elem(map, i + 1);
return !!(elem->id == id &&
!(with_timeout(map->timeout) &&
list_set_expired(map, i + 1)));
}
return 0;
}
static void
list_elem_add(struct list_set *map, u32 i, ip_set_id_t id)
{
struct set_elem *e;
for (; i < map->size; i++) {
e = list_set_elem(map, i);
swap(e->id, id);
if (e->id == IPSET_INVALID_ID)
break;
}
}
static void
list_elem_tadd(struct list_set *map, u32 i, ip_set_id_t id,
unsigned long timeout)
{
struct set_telem *e;
for (; i < map->size; i++) {
e = list_set_telem(map, i);
swap(e->id, id);
swap(e->timeout, timeout);
if (e->id == IPSET_INVALID_ID)
break;
}
}
static int
list_set_add(struct list_set *map, u32 i, ip_set_id_t id,
unsigned long timeout)
{
const struct set_elem *e = list_set_elem(map, i);
if (i == map->size - 1 && e->id != IPSET_INVALID_ID)
ip_set_put_byindex(e->id);
if (with_timeout(map->timeout))
list_elem_tadd(map, i, id, ip_set_timeout_set(timeout));
else
list_elem_add(map, i, id);
return 0;
}
static int
list_set_del(struct list_set *map, u32 i)
{
struct set_elem *a = list_set_elem(map, i), *b;
ip_set_put_byindex(a->id);
for (; i < map->size - 1; i++) {
b = list_set_elem(map, i + 1);
a->id = b->id;
if (with_timeout(map->timeout))
((struct set_telem *)a)->timeout =
((struct set_telem *)b)->timeout;
a = b;
if (a->id == IPSET_INVALID_ID)
break;
}
a->id = IPSET_INVALID_ID;
return 0;
}
static int
list_set_uadt(struct ip_set *set, struct nlattr *tb[],
enum ipset_adt adt, u32 *lineno, u32 flags)
{
struct list_set *map = set->data;
bool with_timeout = with_timeout(map->timeout);
int before = 0;
u32 timeout = map->timeout;
ip_set_id_t id, refid = IPSET_INVALID_ID;
const struct set_elem *elem;
struct ip_set *s;
u32 i;
int ret = 0;
if (unlikely(!tb[IPSET_ATTR_NAME] ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_CADT_FLAGS)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_LINENO])
*lineno = nla_get_u32(tb[IPSET_ATTR_LINENO]);
id = ip_set_get_byname(nla_data(tb[IPSET_ATTR_NAME]), &s);
if (id == IPSET_INVALID_ID)
return -IPSET_ERR_NAME;
if (s->type->features & IPSET_TYPE_NAME) {
ret = -IPSET_ERR_LOOP;
goto finish;
}
if (tb[IPSET_ATTR_CADT_FLAGS]) {
u32 f = ip_set_get_h32(tb[IPSET_ATTR_CADT_FLAGS]);
before = f & IPSET_FLAG_BEFORE;
}
if (before && !tb[IPSET_ATTR_NAMEREF]) {
ret = -IPSET_ERR_BEFORE;
goto finish;
}
if (tb[IPSET_ATTR_NAMEREF]) {
refid = ip_set_get_byname(nla_data(tb[IPSET_ATTR_NAMEREF]),
&s);
if (refid == IPSET_INVALID_ID) {
ret = -IPSET_ERR_NAMEREF;
goto finish;
}
if (!before)
before = -1;
}
if (tb[IPSET_ATTR_TIMEOUT]) {
if (!with_timeout) {
ret = -IPSET_ERR_TIMEOUT;
goto finish;
}
timeout = ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT]);
}
switch (adt) {
case IPSET_TEST:
for (i = 0; i < map->size && !ret; i++) {
elem = list_set_elem(map, i);
if (elem->id == IPSET_INVALID_ID ||
(before != 0 && i + 1 >= map->size))
break;
else if (with_timeout && list_set_expired(map, i))
continue;
else if (before > 0 && elem->id == id)
ret = next_id_eq(map, i, refid);
else if (before < 0 && elem->id == refid)
ret = next_id_eq(map, i, id);
else if (before == 0 && elem->id == id)
ret = 1;
}
break;
case IPSET_ADD:
for (i = 0; i < map->size && !ret; i++) {
elem = list_set_elem(map, i);
if (elem->id == id &&
!(with_timeout && list_set_expired(map, i)))
ret = -IPSET_ERR_EXIST;
}
if (ret == -IPSET_ERR_EXIST)
break;
ret = -IPSET_ERR_LIST_FULL;
for (i = 0; i < map->size && ret == -IPSET_ERR_LIST_FULL; i++) {
elem = list_set_elem(map, i);
if (elem->id == IPSET_INVALID_ID)
ret = before != 0 ? -IPSET_ERR_REF_EXIST
: list_set_add(map, i, id, timeout);
else if (elem->id != refid)
continue;
else if (with_timeout && list_set_expired(map, i))
ret = -IPSET_ERR_REF_EXIST;
else if (before)
ret = list_set_add(map, i, id, timeout);
else if (i + 1 < map->size)
ret = list_set_add(map, i + 1, id, timeout);
}
break;
case IPSET_DEL:
ret = -IPSET_ERR_EXIST;
for (i = 0; i < map->size && ret == -IPSET_ERR_EXIST; i++) {
elem = list_set_elem(map, i);
if (elem->id == IPSET_INVALID_ID) {
ret = before != 0 ? -IPSET_ERR_REF_EXIST
: -IPSET_ERR_EXIST;
break;
} else if (with_timeout && list_set_expired(map, i))
continue;
else if (elem->id == id &&
(before == 0 ||
(before > 0 &&
next_id_eq(map, i, refid))))
ret = list_set_del(map, i);
else if (before < 0 &&
elem->id == refid &&
next_id_eq(map, i, id))
ret = list_set_del(map, i + 1);
}
break;
default:
break;
}
finish:
if (refid != IPSET_INVALID_ID)
ip_set_put_byindex(refid);
if (adt != IPSET_ADD || ret)
ip_set_put_byindex(id);
return ip_set_eexist(ret, flags) ? 0 : ret;
}
static void
list_set_flush(struct ip_set *set)
{
struct list_set *map = set->data;
struct set_elem *elem;
u32 i;
for (i = 0; i < map->size; i++) {
elem = list_set_elem(map, i);
if (elem->id != IPSET_INVALID_ID) {
ip_set_put_byindex(elem->id);
elem->id = IPSET_INVALID_ID;
}
}
}
static void
list_set_destroy(struct ip_set *set)
{
struct list_set *map = set->data;
if (with_timeout(map->timeout))
del_timer_sync(&map->gc);
list_set_flush(set);
kfree(map);
set->data = NULL;
}
static int
list_set_head(struct ip_set *set, struct sk_buff *skb)
{
const struct list_set *map = set->data;
struct nlattr *nested;
nested = ipset_nest_start(skb, IPSET_ATTR_DATA);
if (!nested)
goto nla_put_failure;
NLA_PUT_NET32(skb, IPSET_ATTR_SIZE, htonl(map->size));
if (with_timeout(map->timeout))
NLA_PUT_NET32(skb, IPSET_ATTR_TIMEOUT, htonl(map->timeout));
NLA_PUT_NET32(skb, IPSET_ATTR_REFERENCES, htonl(set->ref - 1));
NLA_PUT_NET32(skb, IPSET_ATTR_MEMSIZE,
htonl(sizeof(*map) + map->size * map->dsize));
ipset_nest_end(skb, nested);
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int
list_set_list(const struct ip_set *set,
struct sk_buff *skb, struct netlink_callback *cb)
{
const struct list_set *map = set->data;
struct nlattr *atd, *nested;
u32 i, first = cb->args[2];
const struct set_elem *e;
atd = ipset_nest_start(skb, IPSET_ATTR_ADT);
if (!atd)
return -EMSGSIZE;
for (; cb->args[2] < map->size; cb->args[2]++) {
i = cb->args[2];
e = list_set_elem(map, i);
if (e->id == IPSET_INVALID_ID)
goto finish;
if (with_timeout(map->timeout) && list_set_expired(map, i))
continue;
nested = ipset_nest_start(skb, IPSET_ATTR_DATA);
if (!nested) {
if (i == first) {
nla_nest_cancel(skb, atd);
return -EMSGSIZE;
} else
goto nla_put_failure;
}
NLA_PUT_STRING(skb, IPSET_ATTR_NAME,
ip_set_name_byindex(e->id));
if (with_timeout(map->timeout)) {
const struct set_telem *te =
(const struct set_telem *) e;
NLA_PUT_NET32(skb, IPSET_ATTR_TIMEOUT,
htonl(ip_set_timeout_get(te->timeout)));
}
ipset_nest_end(skb, nested);
}
finish:
ipset_nest_end(skb, atd);
cb->args[2] = 0;
return 0;
nla_put_failure:
nla_nest_cancel(skb, nested);
ipset_nest_end(skb, atd);
if (unlikely(i == first)) {
cb->args[2] = 0;
return -EMSGSIZE;
}
return 0;
}
static bool
list_set_same_set(const struct ip_set *a, const struct ip_set *b)
{
const struct list_set *x = a->data;
const struct list_set *y = b->data;
return x->size == y->size &&
x->timeout == y->timeout;
}
static void
list_set_gc(unsigned long ul_set)
{
struct ip_set *set = (struct ip_set *) ul_set;
struct list_set *map = set->data;
struct set_telem *e;
u32 i;
write_lock_bh(&set->lock);
for (i = 0; i < map->size; i++) {
e = list_set_telem(map, i);
if (e->id != IPSET_INVALID_ID && list_set_expired(map, i))
list_set_del(map, i);
}
write_unlock_bh(&set->lock);
map->gc.expires = jiffies + IPSET_GC_PERIOD(map->timeout) * HZ;
add_timer(&map->gc);
}
static void
list_set_gc_init(struct ip_set *set)
{
struct list_set *map = set->data;
init_timer(&map->gc);
map->gc.data = (unsigned long) set;
map->gc.function = list_set_gc;
map->gc.expires = jiffies + IPSET_GC_PERIOD(map->timeout) * HZ;
add_timer(&map->gc);
}
static bool
init_list_set(struct ip_set *set, u32 size, size_t dsize,
unsigned long timeout)
{
struct list_set *map;
struct set_elem *e;
u32 i;
map = kzalloc(sizeof(*map) + size * dsize, GFP_KERNEL);
if (!map)
return false;
map->size = size;
map->dsize = dsize;
map->timeout = timeout;
set->data = map;
for (i = 0; i < size; i++) {
e = list_set_elem(map, i);
e->id = IPSET_INVALID_ID;
}
return true;
}
static int
list_set_create(struct ip_set *set, struct nlattr *tb[], u32 flags)
{
u32 size = IP_SET_LIST_DEFAULT_SIZE;
if (unlikely(!ip_set_optattr_netorder(tb, IPSET_ATTR_SIZE) ||
!ip_set_optattr_netorder(tb, IPSET_ATTR_TIMEOUT)))
return -IPSET_ERR_PROTOCOL;
if (tb[IPSET_ATTR_SIZE])
size = ip_set_get_h32(tb[IPSET_ATTR_SIZE]);
if (size < IP_SET_LIST_MIN_SIZE)
size = IP_SET_LIST_MIN_SIZE;
if (tb[IPSET_ATTR_TIMEOUT]) {
if (!init_list_set(set, size, sizeof(struct set_telem),
ip_set_timeout_uget(tb[IPSET_ATTR_TIMEOUT])))
return -ENOMEM;
list_set_gc_init(set);
} else {
if (!init_list_set(set, size, sizeof(struct set_elem),
IPSET_NO_TIMEOUT))
return -ENOMEM;
}
set->variant = &list_set;
return 0;
}
static int __init
list_set_init(void)
{
return ip_set_type_register(&list_set_type);
}
static void __exit
list_set_fini(void)
{
ip_set_type_unregister(&list_set_type);
}
