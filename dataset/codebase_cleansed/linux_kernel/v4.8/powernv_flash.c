static int powernv_flash_async_op(struct mtd_info *mtd, enum flash_op op,
loff_t offset, size_t len, size_t *retlen, u_char *buf)
{
struct powernv_flash *info = (struct powernv_flash *)mtd->priv;
struct device *dev = &mtd->dev;
int token;
struct opal_msg msg;
int rc;
dev_dbg(dev, "%s(op=%d, offset=0x%llx, len=%zu)\n",
__func__, op, offset, len);
token = opal_async_get_token_interruptible();
if (token < 0) {
if (token != -ERESTARTSYS)
dev_err(dev, "Failed to get an async token\n");
return token;
}
switch (op) {
case FLASH_OP_READ:
rc = opal_flash_read(info->id, offset, __pa(buf), len, token);
break;
case FLASH_OP_WRITE:
rc = opal_flash_write(info->id, offset, __pa(buf), len, token);
break;
case FLASH_OP_ERASE:
rc = opal_flash_erase(info->id, offset, len, token);
break;
default:
BUG_ON(1);
}
if (rc != OPAL_ASYNC_COMPLETION) {
dev_err(dev, "opal_flash_async_op(op=%d) failed (rc %d)\n",
op, rc);
opal_async_release_token(token);
return -EIO;
}
rc = opal_async_wait_response(token, &msg);
opal_async_release_token(token);
if (rc) {
dev_err(dev, "opal async wait failed (rc %d)\n", rc);
return -EIO;
}
rc = opal_get_async_rc(msg);
if (rc == OPAL_SUCCESS) {
rc = 0;
if (retlen)
*retlen = len;
} else {
rc = -EIO;
}
return rc;
}
static int powernv_flash_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
return powernv_flash_async_op(mtd, FLASH_OP_READ, from,
len, retlen, buf);
}
static int powernv_flash_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
return powernv_flash_async_op(mtd, FLASH_OP_WRITE, to,
len, retlen, (u_char *)buf);
}
static int powernv_flash_erase(struct mtd_info *mtd, struct erase_info *erase)
{
int rc;
erase->state = MTD_ERASING;
rc = powernv_flash_async_op(mtd, FLASH_OP_ERASE, erase->addr,
erase->len, NULL, NULL);
if (rc) {
erase->fail_addr = erase->addr;
erase->state = MTD_ERASE_FAILED;
} else {
erase->state = MTD_ERASE_DONE;
}
mtd_erase_callback(erase);
return rc;
}
static int powernv_flash_set_driver_info(struct device *dev,
struct mtd_info *mtd)
{
u64 size;
u32 erase_size;
int rc;
rc = of_property_read_u32(dev->of_node, "ibm,flash-block-size",
&erase_size);
if (rc) {
dev_err(dev, "couldn't get resource block size information\n");
return rc;
}
rc = of_property_read_u64(dev->of_node, "reg", &size);
if (rc) {
dev_err(dev, "couldn't get resource size information\n");
return rc;
}
mtd->name = of_get_property(dev->of_node, "name", NULL);
mtd->type = MTD_NORFLASH;
mtd->flags = MTD_WRITEABLE;
mtd->size = size;
mtd->erasesize = erase_size;
mtd->writebufsize = mtd->writesize = 1;
mtd->owner = THIS_MODULE;
mtd->_erase = powernv_flash_erase;
mtd->_read = powernv_flash_read;
mtd->_write = powernv_flash_write;
mtd->dev.parent = dev;
return 0;
}
static int powernv_flash_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct powernv_flash *data;
int ret;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data) {
ret = -ENOMEM;
goto out;
}
data->mtd.priv = data;
ret = of_property_read_u32(dev->of_node, "ibm,opal-id", &(data->id));
if (ret) {
dev_err(dev, "no device property 'ibm,opal-id'\n");
goto out;
}
ret = powernv_flash_set_driver_info(dev, &data->mtd);
if (ret)
goto out;
dev_set_drvdata(dev, data);
ret = mtd_device_register(&data->mtd, NULL, 0);
out:
return ret;
}
static int powernv_flash_release(struct platform_device *pdev)
{
struct powernv_flash *data = dev_get_drvdata(&(pdev->dev));
return mtd_device_unregister(&(data->mtd));
}
