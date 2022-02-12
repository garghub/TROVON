int tty_register_ldisc(int disc, struct tty_ldisc_ops *new_ldisc)
{
unsigned long flags;
int ret = 0;
if (disc < N_TTY || disc >= NR_LDISCS)
return -EINVAL;
raw_spin_lock_irqsave(&tty_ldiscs_lock, flags);
tty_ldiscs[disc] = new_ldisc;
new_ldisc->num = disc;
new_ldisc->refcount = 0;
raw_spin_unlock_irqrestore(&tty_ldiscs_lock, flags);
return ret;
}
int tty_unregister_ldisc(int disc)
{
unsigned long flags;
int ret = 0;
if (disc < N_TTY || disc >= NR_LDISCS)
return -EINVAL;
raw_spin_lock_irqsave(&tty_ldiscs_lock, flags);
if (tty_ldiscs[disc]->refcount)
ret = -EBUSY;
else
tty_ldiscs[disc] = NULL;
raw_spin_unlock_irqrestore(&tty_ldiscs_lock, flags);
return ret;
}
static struct tty_ldisc_ops *get_ldops(int disc)
{
unsigned long flags;
struct tty_ldisc_ops *ldops, *ret;
raw_spin_lock_irqsave(&tty_ldiscs_lock, flags);
ret = ERR_PTR(-EINVAL);
ldops = tty_ldiscs[disc];
if (ldops) {
ret = ERR_PTR(-EAGAIN);
if (try_module_get(ldops->owner)) {
ldops->refcount++;
ret = ldops;
}
}
raw_spin_unlock_irqrestore(&tty_ldiscs_lock, flags);
return ret;
}
static void put_ldops(struct tty_ldisc_ops *ldops)
{
unsigned long flags;
raw_spin_lock_irqsave(&tty_ldiscs_lock, flags);
ldops->refcount--;
module_put(ldops->owner);
raw_spin_unlock_irqrestore(&tty_ldiscs_lock, flags);
}
static struct tty_ldisc *tty_ldisc_get(struct tty_struct *tty, int disc)
{
struct tty_ldisc *ld;
struct tty_ldisc_ops *ldops;
if (disc < N_TTY || disc >= NR_LDISCS)
return ERR_PTR(-EINVAL);
ldops = get_ldops(disc);
if (IS_ERR(ldops)) {
request_module("tty-ldisc-%d", disc);
ldops = get_ldops(disc);
if (IS_ERR(ldops))
return ERR_CAST(ldops);
}
ld = kmalloc(sizeof(struct tty_ldisc), GFP_KERNEL);
if (ld == NULL) {
put_ldops(ldops);
return ERR_PTR(-ENOMEM);
}
ld->ops = ldops;
ld->tty = tty;
return ld;
}
static void tty_ldisc_put(struct tty_ldisc *ld)
{
if (WARN_ON_ONCE(!ld))
return;
put_ldops(ld->ops);
kfree(ld);
}
static void *tty_ldiscs_seq_start(struct seq_file *m, loff_t *pos)
{
return (*pos < NR_LDISCS) ? pos : NULL;
}
static void *tty_ldiscs_seq_next(struct seq_file *m, void *v, loff_t *pos)
{
(*pos)++;
return (*pos < NR_LDISCS) ? pos : NULL;
}
static void tty_ldiscs_seq_stop(struct seq_file *m, void *v)
{
}
static int tty_ldiscs_seq_show(struct seq_file *m, void *v)
{
int i = *(loff_t *)v;
struct tty_ldisc_ops *ldops;
ldops = get_ldops(i);
if (IS_ERR(ldops))
return 0;
seq_printf(m, "%-10s %2d\n", ldops->name ? ldops->name : "???", i);
put_ldops(ldops);
return 0;
}
static int proc_tty_ldiscs_open(struct inode *inode, struct file *file)
{
return seq_open(file, &tty_ldiscs_seq_ops);
}
struct tty_ldisc *tty_ldisc_ref_wait(struct tty_struct *tty)
{
ldsem_down_read(&tty->ldisc_sem, MAX_SCHEDULE_TIMEOUT);
if (!tty->ldisc)
ldsem_up_read(&tty->ldisc_sem);
return tty->ldisc;
}
struct tty_ldisc *tty_ldisc_ref(struct tty_struct *tty)
{
struct tty_ldisc *ld = NULL;
if (ldsem_down_read_trylock(&tty->ldisc_sem)) {
ld = tty->ldisc;
if (!ld)
ldsem_up_read(&tty->ldisc_sem);
}
return ld;
}
void tty_ldisc_deref(struct tty_ldisc *ld)
{
ldsem_up_read(&ld->tty->ldisc_sem);
}
static inline int
__tty_ldisc_lock(struct tty_struct *tty, unsigned long timeout)
{
return ldsem_down_write(&tty->ldisc_sem, timeout);
}
static inline int
__tty_ldisc_lock_nested(struct tty_struct *tty, unsigned long timeout)
{
return ldsem_down_write_nested(&tty->ldisc_sem,
LDISC_SEM_OTHER, timeout);
}
static inline void __tty_ldisc_unlock(struct tty_struct *tty)
{
ldsem_up_write(&tty->ldisc_sem);
}
static int tty_ldisc_lock(struct tty_struct *tty, unsigned long timeout)
{
int ret;
ret = __tty_ldisc_lock(tty, timeout);
if (!ret)
return -EBUSY;
set_bit(TTY_LDISC_HALTED, &tty->flags);
return 0;
}
static void tty_ldisc_unlock(struct tty_struct *tty)
{
clear_bit(TTY_LDISC_HALTED, &tty->flags);
__tty_ldisc_unlock(tty);
}
static int
tty_ldisc_lock_pair_timeout(struct tty_struct *tty, struct tty_struct *tty2,
unsigned long timeout)
{
int ret;
if (tty < tty2) {
ret = __tty_ldisc_lock(tty, timeout);
if (ret) {
ret = __tty_ldisc_lock_nested(tty2, timeout);
if (!ret)
__tty_ldisc_unlock(tty);
}
} else {
WARN_ON_ONCE(tty == tty2);
if (tty2 && tty != tty2) {
ret = __tty_ldisc_lock(tty2, timeout);
if (ret) {
ret = __tty_ldisc_lock_nested(tty, timeout);
if (!ret)
__tty_ldisc_unlock(tty2);
}
} else
ret = __tty_ldisc_lock(tty, timeout);
}
if (!ret)
return -EBUSY;
set_bit(TTY_LDISC_HALTED, &tty->flags);
if (tty2)
set_bit(TTY_LDISC_HALTED, &tty2->flags);
return 0;
}
static void tty_ldisc_lock_pair(struct tty_struct *tty, struct tty_struct *tty2)
{
tty_ldisc_lock_pair_timeout(tty, tty2, MAX_SCHEDULE_TIMEOUT);
}
static void tty_ldisc_unlock_pair(struct tty_struct *tty,
struct tty_struct *tty2)
{
__tty_ldisc_unlock(tty);
if (tty2)
__tty_ldisc_unlock(tty2);
}
void tty_ldisc_flush(struct tty_struct *tty)
{
struct tty_ldisc *ld = tty_ldisc_ref(tty);
tty_buffer_flush(tty, ld);
if (ld)
tty_ldisc_deref(ld);
}
static void tty_set_termios_ldisc(struct tty_struct *tty, int disc)
{
down_write(&tty->termios_rwsem);
tty->termios.c_line = disc;
up_write(&tty->termios_rwsem);
tty->disc_data = NULL;
tty->receive_room = 0;
}
static int tty_ldisc_open(struct tty_struct *tty, struct tty_ldisc *ld)
{
WARN_ON(test_and_set_bit(TTY_LDISC_OPEN, &tty->flags));
if (ld->ops->open) {
int ret;
ret = ld->ops->open(tty);
if (ret)
clear_bit(TTY_LDISC_OPEN, &tty->flags);
tty_ldisc_debug(tty, "%p: opened\n", ld);
return ret;
}
return 0;
}
static void tty_ldisc_close(struct tty_struct *tty, struct tty_ldisc *ld)
{
WARN_ON(!test_bit(TTY_LDISC_OPEN, &tty->flags));
clear_bit(TTY_LDISC_OPEN, &tty->flags);
if (ld->ops->close)
ld->ops->close(tty);
tty_ldisc_debug(tty, "%p: closed\n", ld);
}
static void tty_ldisc_restore(struct tty_struct *tty, struct tty_ldisc *old)
{
struct tty_ldisc *new_ldisc;
int r;
old = tty_ldisc_get(tty, old->ops->num);
WARN_ON(IS_ERR(old));
tty->ldisc = old;
tty_set_termios_ldisc(tty, old->ops->num);
if (tty_ldisc_open(tty, old) < 0) {
tty_ldisc_put(old);
new_ldisc = tty_ldisc_get(tty, N_TTY);
if (IS_ERR(new_ldisc))
panic("n_tty: get");
tty->ldisc = new_ldisc;
tty_set_termios_ldisc(tty, N_TTY);
r = tty_ldisc_open(tty, new_ldisc);
if (r < 0)
panic("Couldn't open N_TTY ldisc for "
"%s --- error %d.",
tty_name(tty), r);
}
}
int tty_set_ldisc(struct tty_struct *tty, int disc)
{
int retval;
struct tty_ldisc *old_ldisc, *new_ldisc;
new_ldisc = tty_ldisc_get(tty, disc);
if (IS_ERR(new_ldisc))
return PTR_ERR(new_ldisc);
tty_lock(tty);
retval = tty_ldisc_lock(tty, 5 * HZ);
if (retval)
goto err;
if (!tty->ldisc) {
retval = -EIO;
goto out;
}
if (tty->ldisc->ops->num == disc)
goto out;
if (test_bit(TTY_HUPPED, &tty->flags)) {
retval = -EIO;
goto out;
}
old_ldisc = tty->ldisc;
tty_ldisc_close(tty, old_ldisc);
tty->ldisc = new_ldisc;
tty_set_termios_ldisc(tty, disc);
retval = tty_ldisc_open(tty, new_ldisc);
if (retval < 0) {
tty_ldisc_put(new_ldisc);
tty_ldisc_restore(tty, old_ldisc);
}
if (tty->ldisc->ops->num != old_ldisc->ops->num && tty->ops->set_ldisc) {
down_read(&tty->termios_rwsem);
tty->ops->set_ldisc(tty);
up_read(&tty->termios_rwsem);
}
new_ldisc = old_ldisc;
out:
tty_ldisc_unlock(tty);
tty_buffer_restart_work(tty->port);
err:
tty_ldisc_put(new_ldisc);
tty_unlock(tty);
return retval;
}
static void tty_ldisc_kill(struct tty_struct *tty)
{
if (!tty->ldisc)
return;
tty_ldisc_close(tty, tty->ldisc);
tty_ldisc_put(tty->ldisc);
tty->ldisc = NULL;
}
static void tty_reset_termios(struct tty_struct *tty)
{
down_write(&tty->termios_rwsem);
tty->termios = tty->driver->init_termios;
tty->termios.c_ispeed = tty_termios_input_baud_rate(&tty->termios);
tty->termios.c_ospeed = tty_termios_baud_rate(&tty->termios);
up_write(&tty->termios_rwsem);
}
int tty_ldisc_reinit(struct tty_struct *tty, int disc)
{
struct tty_ldisc *ld;
int retval;
ld = tty_ldisc_get(tty, disc);
if (IS_ERR(ld)) {
BUG_ON(disc == N_TTY);
return PTR_ERR(ld);
}
if (tty->ldisc) {
tty_ldisc_close(tty, tty->ldisc);
tty_ldisc_put(tty->ldisc);
}
tty->ldisc = ld;
tty_set_termios_ldisc(tty, disc);
retval = tty_ldisc_open(tty, tty->ldisc);
if (retval) {
if (!WARN_ON(disc == N_TTY)) {
tty_ldisc_put(tty->ldisc);
tty->ldisc = NULL;
}
}
return retval;
}
void tty_ldisc_hangup(struct tty_struct *tty, bool reinit)
{
struct tty_ldisc *ld;
tty_ldisc_debug(tty, "%p: hangup\n", tty->ldisc);
ld = tty_ldisc_ref(tty);
if (ld != NULL) {
if (ld->ops->flush_buffer)
ld->ops->flush_buffer(tty);
tty_driver_flush_buffer(tty);
if ((test_bit(TTY_DO_WRITE_WAKEUP, &tty->flags)) &&
ld->ops->write_wakeup)
ld->ops->write_wakeup(tty);
if (ld->ops->hangup)
ld->ops->hangup(tty);
tty_ldisc_deref(ld);
}
wake_up_interruptible_poll(&tty->write_wait, POLLOUT);
wake_up_interruptible_poll(&tty->read_wait, POLLIN);
tty_ldisc_lock(tty, MAX_SCHEDULE_TIMEOUT);
if (tty->driver->flags & TTY_DRIVER_RESET_TERMIOS)
tty_reset_termios(tty);
if (tty->ldisc) {
if (reinit) {
if (tty_ldisc_reinit(tty, tty->termios.c_line) < 0)
tty_ldisc_reinit(tty, N_TTY);
} else
tty_ldisc_kill(tty);
}
tty_ldisc_unlock(tty);
}
int tty_ldisc_setup(struct tty_struct *tty, struct tty_struct *o_tty)
{
int retval = tty_ldisc_open(tty, tty->ldisc);
if (retval)
return retval;
if (o_tty) {
retval = tty_ldisc_open(o_tty, o_tty->ldisc);
if (retval) {
tty_ldisc_close(tty, tty->ldisc);
return retval;
}
}
return 0;
}
void tty_ldisc_release(struct tty_struct *tty)
{
struct tty_struct *o_tty = tty->link;
tty_ldisc_lock_pair(tty, o_tty);
tty_ldisc_kill(tty);
if (o_tty)
tty_ldisc_kill(o_tty);
tty_ldisc_unlock_pair(tty, o_tty);
tty_ldisc_debug(tty, "released\n");
}
void tty_ldisc_init(struct tty_struct *tty)
{
struct tty_ldisc *ld = tty_ldisc_get(tty, N_TTY);
if (IS_ERR(ld))
panic("n_tty: init_tty");
tty->ldisc = ld;
}
void tty_ldisc_deinit(struct tty_struct *tty)
{
if (tty->ldisc)
tty_ldisc_put(tty->ldisc);
tty->ldisc = NULL;
}
