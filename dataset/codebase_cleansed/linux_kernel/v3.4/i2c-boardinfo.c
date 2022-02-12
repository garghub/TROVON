int __init
i2c_register_board_info(int busnum,
struct i2c_board_info const *info, unsigned len)
{
int status;
down_write(&__i2c_board_lock);
if (busnum >= __i2c_first_dynamic_bus_num)
__i2c_first_dynamic_bus_num = busnum + 1;
for (status = 0; len; len--, info++) {
struct i2c_devinfo *devinfo;
devinfo = kzalloc(sizeof(*devinfo), GFP_KERNEL);
if (!devinfo) {
pr_debug("i2c-core: can't register boardinfo!\n");
status = -ENOMEM;
break;
}
devinfo->busnum = busnum;
devinfo->board_info = *info;
list_add_tail(&devinfo->list, &__i2c_board_list);
}
up_write(&__i2c_board_lock);
return status;
}
