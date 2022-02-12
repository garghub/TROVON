static void
discover_timer(ulong vp)
{
static struct timer_list t;
static volatile ulong die;
static spinlock_t lock;
ulong flags;
enum { DTIMERTICK = HZ * 60 };
switch (vp) {
case TINIT:
init_timer(&t);
spin_lock_init(&lock);
t.data = TRUN;
t.function = discover_timer;
die = 0;
case TRUN:
spin_lock_irqsave(&lock, flags);
if (!die) {
t.expires = jiffies + DTIMERTICK;
add_timer(&t);
}
spin_unlock_irqrestore(&lock, flags);
aoecmd_cfg(0xffff, 0xff);
return;
case TKILL:
spin_lock_irqsave(&lock, flags);
die = 1;
spin_unlock_irqrestore(&lock, flags);
del_timer_sync(&t);
default:
return;
}
}
static void
aoe_exit(void)
{
discover_timer(TKILL);
aoenet_exit();
unregister_blkdev(AOE_MAJOR, DEVICE_NAME);
aoecmd_exit();
aoechr_exit();
aoedev_exit();
aoeblk_exit();
}
static int __init
aoe_init(void)
{
int ret;
ret = aoedev_init();
if (ret)
return ret;
ret = aoechr_init();
if (ret)
goto chr_fail;
ret = aoeblk_init();
if (ret)
goto blk_fail;
ret = aoenet_init();
if (ret)
goto net_fail;
ret = aoecmd_init();
if (ret)
goto cmd_fail;
ret = register_blkdev(AOE_MAJOR, DEVICE_NAME);
if (ret < 0) {
printk(KERN_ERR "aoe: can't register major\n");
goto blkreg_fail;
}
printk(KERN_INFO "aoe: AoE v%s initialised.\n", VERSION);
discover_timer(TINIT);
return 0;
blkreg_fail:
aoecmd_exit();
cmd_fail:
aoenet_exit();
net_fail:
aoeblk_exit();
blk_fail:
aoechr_exit();
chr_fail:
aoedev_exit();
printk(KERN_INFO "aoe: initialisation failure.\n");
return ret;
}
