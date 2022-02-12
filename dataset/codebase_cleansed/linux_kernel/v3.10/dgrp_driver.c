static int dgrp_init_module(void)
{
int ret;
INIT_LIST_HEAD(&nd_struct_list);
spin_lock_init(&dgrp_poll_data.poll_lock);
init_timer(&dgrp_poll_data.timer);
dgrp_poll_data.poll_tick = dgrp_poll_tick;
dgrp_poll_data.timer.function = dgrp_poll_handler;
dgrp_poll_data.timer.data = (unsigned long) &dgrp_poll_data;
ret = dgrp_create_class_sysfs_files();
if (ret)
return ret;
dgrp_register_proc();
return 0;
}
static void dgrp_cleanup_module(void)
{
struct nd_struct *nd, *next;
dgrp_unregister_proc();
dgrp_remove_class_sysfs_files();
list_for_each_entry_safe(nd, next, &nd_struct_list, list) {
dgrp_tty_uninit(nd);
kfree(nd);
}
}
