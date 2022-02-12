void w1_bq27000_write(struct device *dev, u8 buf, u8 reg)
{
struct w1_slave *sl = container_of(dev, struct w1_slave, dev);
if (!dev) {
pr_info("Could not obtain slave dev ptr\n");
return;
}
w1_write_8(sl->master, HDQ_CMD_WRITE | reg);
w1_write_8(sl->master, buf);
}
int w1_bq27000_read(struct device *dev, u8 reg)
{
u8 val;
struct w1_slave *sl = container_of(dev, struct w1_slave, dev);
if (!dev)
return 0;
w1_write_8(sl->master, HDQ_CMD_READ | reg);
val = w1_read_8(sl->master);
return val;
}
static int w1_bq27000_add_slave(struct w1_slave *sl)
{
int ret;
int id = 1;
struct platform_device *pdev;
pdev = platform_device_alloc("bq27000-battery", id);
if (!pdev) {
ret = -ENOMEM;
return ret;
}
pdev->dev.parent = &sl->dev;
ret = platform_device_add(pdev);
if (ret)
goto pdev_add_failed;
dev_set_drvdata(&sl->dev, pdev);
goto success;
pdev_add_failed:
platform_device_unregister(pdev);
success:
return ret;
}
static void w1_bq27000_remove_slave(struct w1_slave *sl)
{
struct platform_device *pdev = dev_get_drvdata(&sl->dev);
platform_device_unregister(pdev);
}
static int __init w1_bq27000_init(void)
{
if (F_ID)
w1_bq27000_family.fid = F_ID;
return w1_register_family(&w1_bq27000_family);
}
static void __exit w1_bq27000_exit(void)
{
w1_unregister_family(&w1_bq27000_family);
}
