static int fpga_mgr_write_init_buf(struct fpga_manager *mgr,
struct fpga_image_info *info,
const char *buf, size_t count)
{
int ret;
mgr->state = FPGA_MGR_STATE_WRITE_INIT;
if (!mgr->mops->initial_header_size)
ret = mgr->mops->write_init(mgr, info, NULL, 0);
else
ret = mgr->mops->write_init(
mgr, info, buf, min(mgr->mops->initial_header_size, count));
if (ret) {
dev_err(&mgr->dev, "Error preparing FPGA for writing\n");
mgr->state = FPGA_MGR_STATE_WRITE_INIT_ERR;
return ret;
}
return 0;
}
static int fpga_mgr_write_init_sg(struct fpga_manager *mgr,
struct fpga_image_info *info,
struct sg_table *sgt)
{
struct sg_mapping_iter miter;
size_t len;
char *buf;
int ret;
if (!mgr->mops->initial_header_size)
return fpga_mgr_write_init_buf(mgr, info, NULL, 0);
sg_miter_start(&miter, sgt->sgl, sgt->nents, SG_MITER_FROM_SG);
if (sg_miter_next(&miter) &&
miter.length >= mgr->mops->initial_header_size) {
ret = fpga_mgr_write_init_buf(mgr, info, miter.addr,
miter.length);
sg_miter_stop(&miter);
return ret;
}
sg_miter_stop(&miter);
buf = kmalloc(mgr->mops->initial_header_size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
len = sg_copy_to_buffer(sgt->sgl, sgt->nents, buf,
mgr->mops->initial_header_size);
ret = fpga_mgr_write_init_buf(mgr, info, buf, len);
kfree(buf);
return ret;
}
static int fpga_mgr_write_complete(struct fpga_manager *mgr,
struct fpga_image_info *info)
{
int ret;
mgr->state = FPGA_MGR_STATE_WRITE_COMPLETE;
ret = mgr->mops->write_complete(mgr, info);
if (ret) {
dev_err(&mgr->dev, "Error after writing image data to FPGA\n");
mgr->state = FPGA_MGR_STATE_WRITE_COMPLETE_ERR;
return ret;
}
mgr->state = FPGA_MGR_STATE_OPERATING;
return 0;
}
int fpga_mgr_buf_load_sg(struct fpga_manager *mgr, struct fpga_image_info *info,
struct sg_table *sgt)
{
int ret;
ret = fpga_mgr_write_init_sg(mgr, info, sgt);
if (ret)
return ret;
mgr->state = FPGA_MGR_STATE_WRITE;
if (mgr->mops->write_sg) {
ret = mgr->mops->write_sg(mgr, sgt);
} else {
struct sg_mapping_iter miter;
sg_miter_start(&miter, sgt->sgl, sgt->nents, SG_MITER_FROM_SG);
while (sg_miter_next(&miter)) {
ret = mgr->mops->write(mgr, miter.addr, miter.length);
if (ret)
break;
}
sg_miter_stop(&miter);
}
if (ret) {
dev_err(&mgr->dev, "Error while writing image data to FPGA\n");
mgr->state = FPGA_MGR_STATE_WRITE_ERR;
return ret;
}
return fpga_mgr_write_complete(mgr, info);
}
static int fpga_mgr_buf_load_mapped(struct fpga_manager *mgr,
struct fpga_image_info *info,
const char *buf, size_t count)
{
int ret;
ret = fpga_mgr_write_init_buf(mgr, info, buf, count);
if (ret)
return ret;
mgr->state = FPGA_MGR_STATE_WRITE;
ret = mgr->mops->write(mgr, buf, count);
if (ret) {
dev_err(&mgr->dev, "Error while writing image data to FPGA\n");
mgr->state = FPGA_MGR_STATE_WRITE_ERR;
return ret;
}
return fpga_mgr_write_complete(mgr, info);
}
int fpga_mgr_buf_load(struct fpga_manager *mgr, struct fpga_image_info *info,
const char *buf, size_t count)
{
struct page **pages;
struct sg_table sgt;
const void *p;
int nr_pages;
int index;
int rc;
if (mgr->mops->write)
return fpga_mgr_buf_load_mapped(mgr, info, buf, count);
nr_pages = DIV_ROUND_UP((unsigned long)buf + count, PAGE_SIZE) -
(unsigned long)buf / PAGE_SIZE;
pages = kmalloc_array(nr_pages, sizeof(struct page *), GFP_KERNEL);
if (!pages)
return -ENOMEM;
p = buf - offset_in_page(buf);
for (index = 0; index < nr_pages; index++) {
if (is_vmalloc_addr(p))
pages[index] = vmalloc_to_page(p);
else
pages[index] = kmap_to_page((void *)p);
if (!pages[index]) {
kfree(pages);
return -EFAULT;
}
p += PAGE_SIZE;
}
rc = sg_alloc_table_from_pages(&sgt, pages, index, offset_in_page(buf),
count, GFP_KERNEL);
kfree(pages);
if (rc)
return rc;
rc = fpga_mgr_buf_load_sg(mgr, info, &sgt);
sg_free_table(&sgt);
return rc;
}
int fpga_mgr_firmware_load(struct fpga_manager *mgr,
struct fpga_image_info *info,
const char *image_name)
{
struct device *dev = &mgr->dev;
const struct firmware *fw;
int ret;
dev_info(dev, "writing %s to %s\n", image_name, mgr->name);
mgr->state = FPGA_MGR_STATE_FIRMWARE_REQ;
ret = request_firmware(&fw, image_name, dev);
if (ret) {
mgr->state = FPGA_MGR_STATE_FIRMWARE_REQ_ERR;
dev_err(dev, "Error requesting firmware %s\n", image_name);
return ret;
}
ret = fpga_mgr_buf_load(mgr, info, fw->data, fw->size);
release_firmware(fw);
return ret;
}
static ssize_t name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fpga_manager *mgr = to_fpga_manager(dev);
return sprintf(buf, "%s\n", mgr->name);
}
static ssize_t state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fpga_manager *mgr = to_fpga_manager(dev);
return sprintf(buf, "%s\n", state_str[mgr->state]);
}
static struct fpga_manager *__fpga_mgr_get(struct device *dev)
{
struct fpga_manager *mgr;
int ret = -ENODEV;
mgr = to_fpga_manager(dev);
if (!mgr)
goto err_dev;
if (!mutex_trylock(&mgr->ref_mutex)) {
ret = -EBUSY;
goto err_dev;
}
if (!try_module_get(dev->parent->driver->owner))
goto err_ll_mod;
return mgr;
err_ll_mod:
mutex_unlock(&mgr->ref_mutex);
err_dev:
put_device(dev);
return ERR_PTR(ret);
}
static int fpga_mgr_dev_match(struct device *dev, const void *data)
{
return dev->parent == data;
}
struct fpga_manager *fpga_mgr_get(struct device *dev)
{
struct device *mgr_dev = class_find_device(fpga_mgr_class, NULL, dev,
fpga_mgr_dev_match);
if (!mgr_dev)
return ERR_PTR(-ENODEV);
return __fpga_mgr_get(mgr_dev);
}
static int fpga_mgr_of_node_match(struct device *dev, const void *data)
{
return dev->of_node == data;
}
struct fpga_manager *of_fpga_mgr_get(struct device_node *node)
{
struct device *dev;
dev = class_find_device(fpga_mgr_class, NULL, node,
fpga_mgr_of_node_match);
if (!dev)
return ERR_PTR(-ENODEV);
return __fpga_mgr_get(dev);
}
void fpga_mgr_put(struct fpga_manager *mgr)
{
module_put(mgr->dev.parent->driver->owner);
mutex_unlock(&mgr->ref_mutex);
put_device(&mgr->dev);
}
int fpga_mgr_register(struct device *dev, const char *name,
const struct fpga_manager_ops *mops,
void *priv)
{
struct fpga_manager *mgr;
int id, ret;
if (!mops || !mops->write_complete || !mops->state ||
!mops->write_init || (!mops->write && !mops->write_sg) ||
(mops->write && mops->write_sg)) {
dev_err(dev, "Attempt to register without fpga_manager_ops\n");
return -EINVAL;
}
if (!name || !strlen(name)) {
dev_err(dev, "Attempt to register with no name!\n");
return -EINVAL;
}
mgr = kzalloc(sizeof(*mgr), GFP_KERNEL);
if (!mgr)
return -ENOMEM;
id = ida_simple_get(&fpga_mgr_ida, 0, 0, GFP_KERNEL);
if (id < 0) {
ret = id;
goto error_kfree;
}
mutex_init(&mgr->ref_mutex);
mgr->name = name;
mgr->mops = mops;
mgr->priv = priv;
mgr->state = mgr->mops->state(mgr);
device_initialize(&mgr->dev);
mgr->dev.class = fpga_mgr_class;
mgr->dev.parent = dev;
mgr->dev.of_node = dev->of_node;
mgr->dev.id = id;
dev_set_drvdata(dev, mgr);
ret = dev_set_name(&mgr->dev, "fpga%d", id);
if (ret)
goto error_device;
ret = device_add(&mgr->dev);
if (ret)
goto error_device;
dev_info(&mgr->dev, "%s registered\n", mgr->name);
return 0;
error_device:
ida_simple_remove(&fpga_mgr_ida, id);
error_kfree:
kfree(mgr);
return ret;
}
void fpga_mgr_unregister(struct device *dev)
{
struct fpga_manager *mgr = dev_get_drvdata(dev);
dev_info(&mgr->dev, "%s %s\n", __func__, mgr->name);
if (mgr->mops->fpga_remove)
mgr->mops->fpga_remove(mgr);
device_unregister(&mgr->dev);
}
static void fpga_mgr_dev_release(struct device *dev)
{
struct fpga_manager *mgr = to_fpga_manager(dev);
ida_simple_remove(&fpga_mgr_ida, mgr->dev.id);
kfree(mgr);
}
static int __init fpga_mgr_class_init(void)
{
pr_info("FPGA manager framework\n");
fpga_mgr_class = class_create(THIS_MODULE, "fpga_manager");
if (IS_ERR(fpga_mgr_class))
return PTR_ERR(fpga_mgr_class);
fpga_mgr_class->dev_groups = fpga_mgr_groups;
fpga_mgr_class->dev_release = fpga_mgr_dev_release;
return 0;
}
static void __exit fpga_mgr_class_exit(void)
{
class_destroy(fpga_mgr_class);
ida_destroy(&fpga_mgr_ida);
}
