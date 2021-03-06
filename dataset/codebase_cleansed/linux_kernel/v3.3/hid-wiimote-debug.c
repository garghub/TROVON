static int wiidebug_eeprom_open(struct inode *i, struct file *f)
{
f->private_data = i->i_private;
return 0;
}
static ssize_t wiidebug_eeprom_read(struct file *f, char __user *u, size_t s,
loff_t *off)
{
struct wiimote_debug *dbg = f->private_data;
struct wiimote_data *wdata = dbg->wdata;
unsigned long flags;
ssize_t ret;
char buf[16];
__u16 size;
if (s == 0)
return -EINVAL;
if (*off > 0xffffff)
return 0;
if (s > 16)
s = 16;
ret = wiimote_cmd_acquire(wdata);
if (ret)
return ret;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.cmd_read_size = s;
wdata->state.cmd_read_buf = buf;
wiimote_cmd_set(wdata, WIIPROTO_REQ_RMEM, *off & 0xffff);
wiiproto_req_reeprom(wdata, *off, s);
spin_unlock_irqrestore(&wdata->state.lock, flags);
ret = wiimote_cmd_wait(wdata);
if (!ret)
size = wdata->state.cmd_read_size;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->state.cmd_read_buf = NULL;
spin_unlock_irqrestore(&wdata->state.lock, flags);
wiimote_cmd_release(wdata);
if (ret)
return ret;
else if (size == 0)
return -EIO;
if (copy_to_user(u, buf, size))
return -EFAULT;
*off += size;
ret = size;
return ret;
}
static int wiidebug_drm_show(struct seq_file *f, void *p)
{
struct wiimote_debug *dbg = f->private;
const char *str = NULL;
unsigned long flags;
__u8 drm;
spin_lock_irqsave(&dbg->wdata->state.lock, flags);
drm = dbg->wdata->state.drm;
spin_unlock_irqrestore(&dbg->wdata->state.lock, flags);
if (drm < WIIPROTO_REQ_MAX)
str = wiidebug_drmmap[drm];
if (!str)
str = "unknown";
seq_printf(f, "%s\n", str);
return 0;
}
static int wiidebug_drm_open(struct inode *i, struct file *f)
{
return single_open(f, wiidebug_drm_show, i->i_private);
}
static ssize_t wiidebug_drm_write(struct file *f, const char __user *u,
size_t s, loff_t *off)
{
struct wiimote_debug *dbg = f->private_data;
unsigned long flags;
char buf[16];
ssize_t len;
int i;
if (s == 0)
return -EINVAL;
len = min((size_t) 15, s);
if (copy_from_user(buf, u, len))
return -EFAULT;
buf[15] = 0;
for (i = 0; i < WIIPROTO_REQ_MAX; ++i) {
if (!wiidebug_drmmap[i])
continue;
if (!strcasecmp(buf, wiidebug_drmmap[i]))
break;
}
if (i == WIIPROTO_REQ_MAX)
i = simple_strtoul(buf, NULL, 10);
spin_lock_irqsave(&dbg->wdata->state.lock, flags);
wiiproto_req_drm(dbg->wdata, (__u8) i);
spin_unlock_irqrestore(&dbg->wdata->state.lock, flags);
return len;
}
int wiidebug_init(struct wiimote_data *wdata)
{
struct wiimote_debug *dbg;
unsigned long flags;
int ret = -ENOMEM;
dbg = kzalloc(sizeof(*dbg), GFP_KERNEL);
if (!dbg)
return -ENOMEM;
dbg->wdata = wdata;
dbg->eeprom = debugfs_create_file("eeprom", S_IRUSR,
dbg->wdata->hdev->debug_dir, dbg, &wiidebug_eeprom_fops);
if (!dbg->eeprom)
goto err;
dbg->drm = debugfs_create_file("drm", S_IRUSR,
dbg->wdata->hdev->debug_dir, dbg, &wiidebug_drm_fops);
if (!dbg->drm)
goto err_drm;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->debug = dbg;
spin_unlock_irqrestore(&wdata->state.lock, flags);
return 0;
err_drm:
debugfs_remove(dbg->eeprom);
err:
kfree(dbg);
return ret;
}
void wiidebug_deinit(struct wiimote_data *wdata)
{
struct wiimote_debug *dbg = wdata->debug;
unsigned long flags;
if (!dbg)
return;
spin_lock_irqsave(&wdata->state.lock, flags);
wdata->debug = NULL;
spin_unlock_irqrestore(&wdata->state.lock, flags);
debugfs_remove(dbg->drm);
debugfs_remove(dbg->eeprom);
kfree(dbg);
}
