struct sock *unix_get_socket(struct file *filp)
{
struct sock *u_sock = NULL;
struct inode *inode = file_inode(filp);
if (S_ISSOCK(inode->i_mode) && !(filp->f_mode & FMODE_PATH)) {
struct socket *sock = SOCKET_I(inode);
struct sock *s = sock->sk;
if (s && sock->ops && sock->ops->family == PF_UNIX)
u_sock = s;
}
return u_sock;
}
void unix_inflight(struct user_struct *user, struct file *fp)
{
struct sock *s = unix_get_socket(fp);
spin_lock(&unix_gc_lock);
if (s) {
struct unix_sock *u = unix_sk(s);
if (atomic_long_inc_return(&u->inflight) == 1) {
BUG_ON(!list_empty(&u->link));
list_add_tail(&u->link, &gc_inflight_list);
} else {
BUG_ON(list_empty(&u->link));
}
unix_tot_inflight++;
}
user->unix_inflight++;
spin_unlock(&unix_gc_lock);
}
void unix_notinflight(struct user_struct *user, struct file *fp)
{
struct sock *s = unix_get_socket(fp);
spin_lock(&unix_gc_lock);
if (s) {
struct unix_sock *u = unix_sk(s);
BUG_ON(!atomic_long_read(&u->inflight));
BUG_ON(list_empty(&u->link));
if (atomic_long_dec_and_test(&u->inflight))
list_del_init(&u->link);
unix_tot_inflight--;
}
user->unix_inflight--;
spin_unlock(&unix_gc_lock);
}
static void scan_inflight(struct sock *x, void (*func)(struct unix_sock *),
struct sk_buff_head *hitlist)
{
struct sk_buff *skb;
struct sk_buff *next;
spin_lock(&x->sk_receive_queue.lock);
skb_queue_walk_safe(&x->sk_receive_queue, skb, next) {
if (UNIXCB(skb).fp) {
bool hit = false;
int nfd = UNIXCB(skb).fp->count;
struct file **fp = UNIXCB(skb).fp->fp;
while (nfd--) {
struct sock *sk = unix_get_socket(*fp++);
if (sk) {
struct unix_sock *u = unix_sk(sk);
if (test_bit(UNIX_GC_CANDIDATE, &u->gc_flags)) {
hit = true;
func(u);
}
}
}
if (hit && hitlist != NULL) {
__skb_unlink(skb, &x->sk_receive_queue);
__skb_queue_tail(hitlist, skb);
}
}
}
spin_unlock(&x->sk_receive_queue.lock);
}
static void scan_children(struct sock *x, void (*func)(struct unix_sock *),
struct sk_buff_head *hitlist)
{
if (x->sk_state != TCP_LISTEN) {
scan_inflight(x, func, hitlist);
} else {
struct sk_buff *skb;
struct sk_buff *next;
struct unix_sock *u;
LIST_HEAD(embryos);
spin_lock(&x->sk_receive_queue.lock);
skb_queue_walk_safe(&x->sk_receive_queue, skb, next) {
u = unix_sk(skb->sk);
BUG_ON(!list_empty(&u->link));
list_add_tail(&u->link, &embryos);
}
spin_unlock(&x->sk_receive_queue.lock);
while (!list_empty(&embryos)) {
u = list_entry(embryos.next, struct unix_sock, link);
scan_inflight(&u->sk, func, hitlist);
list_del_init(&u->link);
}
}
}
static void dec_inflight(struct unix_sock *usk)
{
atomic_long_dec(&usk->inflight);
}
static void inc_inflight(struct unix_sock *usk)
{
atomic_long_inc(&usk->inflight);
}
static void inc_inflight_move_tail(struct unix_sock *u)
{
atomic_long_inc(&u->inflight);
if (test_bit(UNIX_GC_MAYBE_CYCLE, &u->gc_flags))
list_move_tail(&u->link, &gc_candidates);
}
void wait_for_unix_gc(void)
{
if (unix_tot_inflight > UNIX_INFLIGHT_TRIGGER_GC && !gc_in_progress)
unix_gc();
wait_event(unix_gc_wait, gc_in_progress == false);
}
void unix_gc(void)
{
struct unix_sock *u;
struct unix_sock *next;
struct sk_buff_head hitlist;
struct list_head cursor;
LIST_HEAD(not_cycle_list);
spin_lock(&unix_gc_lock);
if (gc_in_progress)
goto out;
gc_in_progress = true;
list_for_each_entry_safe(u, next, &gc_inflight_list, link) {
long total_refs;
long inflight_refs;
total_refs = file_count(u->sk.sk_socket->file);
inflight_refs = atomic_long_read(&u->inflight);
BUG_ON(inflight_refs < 1);
BUG_ON(total_refs < inflight_refs);
if (total_refs == inflight_refs) {
list_move_tail(&u->link, &gc_candidates);
__set_bit(UNIX_GC_CANDIDATE, &u->gc_flags);
__set_bit(UNIX_GC_MAYBE_CYCLE, &u->gc_flags);
}
}
list_for_each_entry(u, &gc_candidates, link)
scan_children(&u->sk, dec_inflight, NULL);
list_add(&cursor, &gc_candidates);
while (cursor.next != &gc_candidates) {
u = list_entry(cursor.next, struct unix_sock, link);
list_move(&cursor, &u->link);
if (atomic_long_read(&u->inflight) > 0) {
list_move_tail(&u->link, &not_cycle_list);
__clear_bit(UNIX_GC_MAYBE_CYCLE, &u->gc_flags);
scan_children(&u->sk, inc_inflight_move_tail, NULL);
}
}
list_del(&cursor);
skb_queue_head_init(&hitlist);
list_for_each_entry(u, &gc_candidates, link)
scan_children(&u->sk, inc_inflight, &hitlist);
while (!list_empty(&not_cycle_list)) {
u = list_entry(not_cycle_list.next, struct unix_sock, link);
__clear_bit(UNIX_GC_CANDIDATE, &u->gc_flags);
list_move_tail(&u->link, &gc_inflight_list);
}
spin_unlock(&unix_gc_lock);
__skb_queue_purge(&hitlist);
spin_lock(&unix_gc_lock);
BUG_ON(!list_empty(&gc_candidates));
gc_in_progress = false;
wake_up(&unix_gc_wait);
out:
spin_unlock(&unix_gc_lock);
}
