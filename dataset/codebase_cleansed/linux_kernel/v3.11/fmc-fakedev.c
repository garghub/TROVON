static int ff_reprogram(struct fmc_device *fmc, struct fmc_driver *drv,
char *gw)
{
const struct firmware *fw;
int ret;
if (!gw) {
fmc->flags &= ~FMC_DEVICE_HAS_CUSTOM;
fmc->flags |= FMC_DEVICE_HAS_GOLDEN;
return 0;
}
dev_info(&fmc->dev, "reprogramming with %s\n", gw);
ret = request_firmware(&fw, gw, &fmc->dev);
if (ret < 0) {
dev_warn(&fmc->dev, "request firmware \"%s\": error %i\n",
gw, ret);
goto out;
}
fmc->flags &= ~FMC_DEVICE_HAS_GOLDEN;
fmc->flags |= FMC_DEVICE_HAS_CUSTOM;
out:
release_firmware(fw);
return ret;
}
static int ff_irq_request(struct fmc_device *fmc, irq_handler_t handler,
char *name, int flags)
{
return -EOPNOTSUPP;
}
static void ff_work_fn(struct work_struct *work)
{
struct ff_dev *ff = ff_current_dev;
int ret;
fmc_device_unregister_n(ff->fmc, ff_nr_dev);
device_unregister(&ff->dev);
ff_current_dev = NULL;
ff = ff_dev_create();
if (IS_ERR(ff)) {
pr_warning("%s: can't re-create FMC devices\n", __func__);
return;
}
ret = fmc_device_register_n(ff->fmc, ff_nr_dev);
if (ret < 0) {
dev_warn(&ff->dev, "can't re-register FMC devices\n");
device_unregister(&ff->dev);
return;
}
ff_current_dev = ff;
}
static int ff_eeprom_read(struct fmc_device *fmc, uint32_t offset,
void *buf, size_t size)
{
if (offset > FF_EEPROM_SIZE)
return -EINVAL;
if (offset + size > FF_EEPROM_SIZE)
size = FF_EEPROM_SIZE - offset;
memcpy(buf, fmc->eeprom + offset, size);
return size;
}
static int ff_eeprom_write(struct fmc_device *fmc, uint32_t offset,
const void *buf, size_t size)
{
if (offset > FF_EEPROM_SIZE)
return -EINVAL;
if (offset + size > FF_EEPROM_SIZE)
size = FF_EEPROM_SIZE - offset;
dev_info(&fmc->dev, "write_eeprom: offset %i, size %zi\n",
(int)offset, size);
memcpy(fmc->eeprom + offset, buf, size);
schedule_delayed_work(&ff_work, HZ * 2);
return size;
}
static int ff_read_ee(struct fmc_device *fmc, int pos, void *data, int len)
{
if (!(fmc->flags & FMC_DEVICE_HAS_GOLDEN))
return -EOPNOTSUPP;
return ff_eeprom_read(fmc, pos, data, len);
}
static int ff_write_ee(struct fmc_device *fmc, int pos,
const void *data, int len)
{
if (!(fmc->flags & FMC_DEVICE_HAS_GOLDEN))
return -EOPNOTSUPP;
return ff_eeprom_write(fmc, pos, data, len);
}
static uint32_t ff_readl(struct fmc_device *fmc, int offset)
{
return 0;
}
static void ff_writel(struct fmc_device *fmc, uint32_t value, int offset)
{
return;
}
static int ff_validate(struct fmc_device *fmc, struct fmc_driver *drv)
{
int i;
if (!drv->busid_n)
return 0;
for (i = 0; i < drv->busid_n; i++)
if (drv->busid_val[i] == fmc->device_id)
return i;
return -ENOENT;
}
static void ff_dev_release(struct device *dev)
{
struct ff_dev *ff = container_of(dev, struct ff_dev, dev);
kfree(ff);
}
static struct ff_dev *ff_dev_create(void)
{
struct ff_dev *ff;
struct fmc_device *fmc;
int i, ret;
ff = kzalloc(sizeof(*ff), GFP_KERNEL);
if (!ff)
return ERR_PTR(-ENOMEM);
dev_set_name(&ff->dev, "fake-fmc-carrier");
ff->dev.release = ff_dev_release;
ret = device_register(&ff->dev);
if (ret < 0) {
put_device(&ff->dev);
return ERR_PTR(ret);
}
for (i = 0; i < ff_nr_dev; i++) {
fmc = kmemdup(&ff_template_fmc, sizeof(ff_template_fmc),
GFP_KERNEL);
fmc->hwdev = &ff->dev;
fmc->carrier_data = ff;
fmc->nr_slots = ff_nr_dev;
fmc->eeprom = ff_eeimg[i];
fmc->eeprom_addr = 0x50 + 2 * i;
fmc->slot_id = i;
ff->fmc[i] = fmc;
ff_template_fmc.device_id++;
}
return ff;
}
static int ff_init(void)
{
struct ff_dev *ff;
const struct firmware *fw;
int i, len, ret = 0;
for (i = 1; i < FF_MAX_MEZZANINES; i++)
memcpy(ff_eeimg[i], ff_eeimg[0], sizeof(ff_eeimg[0]));
if (ff_nr_eeprom > ff_nr_dev)
ff_nr_dev = ff_nr_eeprom;
ff = ff_dev_create();
if (IS_ERR(ff))
return PTR_ERR(ff);
for (i = 0; i < ff_nr_eeprom; i++) {
if (!strlen(ff_eeprom[i]))
continue;
ret = request_firmware(&fw, ff_eeprom[i], &ff->dev);
if (ret < 0) {
dev_err(&ff->dev, "Mezzanine %i: can't load \"%s\" "
"(error %i)\n", i, ff_eeprom[i], -ret);
} else {
len = min_t(size_t, fw->size, (size_t)FF_EEPROM_SIZE);
memcpy(ff_eeimg[i], fw->data, len);
release_firmware(fw);
dev_info(&ff->dev, "Mezzanine %i: eeprom \"%s\"\n", i,
ff_eeprom[i]);
}
}
ret = fmc_device_register_n(ff->fmc, ff_nr_dev);
if (ret) {
device_unregister(&ff->dev);
return ret;
}
ff_current_dev = ff;
return ret;
}
static void ff_exit(void)
{
if (ff_current_dev) {
fmc_device_unregister_n(ff_current_dev->fmc, ff_nr_dev);
device_unregister(&ff_current_dev->dev);
}
cancel_delayed_work_sync(&ff_work);
}
