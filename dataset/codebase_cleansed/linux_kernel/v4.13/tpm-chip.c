int tpm_try_get_ops(struct tpm_chip *chip)
{
int rc = -EIO;
get_device(&chip->dev);
down_read(&chip->ops_sem);
if (!chip->ops)
goto out_lock;
return 0;
out_lock:
up_read(&chip->ops_sem);
put_device(&chip->dev);
return rc;
}
void tpm_put_ops(struct tpm_chip *chip)
{
up_read(&chip->ops_sem);
put_device(&chip->dev);
}
struct tpm_chip *tpm_chip_find_get(int chip_num)
{
struct tpm_chip *chip, *res = NULL;
int chip_prev;
mutex_lock(&idr_lock);
if (chip_num == TPM_ANY_NUM) {
chip_num = 0;
do {
chip_prev = chip_num;
chip = idr_get_next(&dev_nums_idr, &chip_num);
if (chip && !tpm_try_get_ops(chip)) {
res = chip;
break;
}
} while (chip_prev != chip_num);
} else {
chip = idr_find(&dev_nums_idr, chip_num);
if (chip && !tpm_try_get_ops(chip))
res = chip;
}
mutex_unlock(&idr_lock);
return res;
}
static void tpm_dev_release(struct device *dev)
{
struct tpm_chip *chip = container_of(dev, struct tpm_chip, dev);
mutex_lock(&idr_lock);
idr_remove(&dev_nums_idr, chip->dev_num);
mutex_unlock(&idr_lock);
kfree(chip->log.bios_event_log);
kfree(chip->work_space.context_buf);
kfree(chip->work_space.session_buf);
kfree(chip);
}
static void tpm_devs_release(struct device *dev)
{
struct tpm_chip *chip = container_of(dev, struct tpm_chip, devs);
put_device(&chip->dev);
}
static int tpm_class_shutdown(struct device *dev)
{
struct tpm_chip *chip = container_of(dev, struct tpm_chip, dev);
if (chip->flags & TPM_CHIP_FLAG_TPM2) {
down_write(&chip->ops_sem);
tpm2_shutdown(chip, TPM2_SU_CLEAR);
chip->ops = NULL;
up_write(&chip->ops_sem);
}
if (dev->bus && dev->bus->shutdown)
dev->bus->shutdown(dev);
else if (dev->driver && dev->driver->shutdown)
dev->driver->shutdown(dev);
return 0;
}
struct tpm_chip *tpm_chip_alloc(struct device *pdev,
const struct tpm_class_ops *ops)
{
struct tpm_chip *chip;
int rc;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL)
return ERR_PTR(-ENOMEM);
mutex_init(&chip->tpm_mutex);
init_rwsem(&chip->ops_sem);
chip->ops = ops;
mutex_lock(&idr_lock);
rc = idr_alloc(&dev_nums_idr, NULL, 0, TPM_NUM_DEVICES, GFP_KERNEL);
mutex_unlock(&idr_lock);
if (rc < 0) {
dev_err(pdev, "No available tpm device numbers\n");
kfree(chip);
return ERR_PTR(rc);
}
chip->dev_num = rc;
device_initialize(&chip->dev);
device_initialize(&chip->devs);
chip->dev.class = tpm_class;
chip->dev.class->shutdown = tpm_class_shutdown;
chip->dev.release = tpm_dev_release;
chip->dev.parent = pdev;
chip->dev.groups = chip->groups;
chip->devs.parent = pdev;
chip->devs.class = tpmrm_class;
chip->devs.release = tpm_devs_release;
if (chip->flags & TPM_CHIP_FLAG_TPM2)
get_device(&chip->dev);
if (chip->dev_num == 0)
chip->dev.devt = MKDEV(MISC_MAJOR, TPM_MINOR);
else
chip->dev.devt = MKDEV(MAJOR(tpm_devt), chip->dev_num);
chip->devs.devt =
MKDEV(MAJOR(tpm_devt), chip->dev_num + TPM_NUM_DEVICES);
rc = dev_set_name(&chip->dev, "tpm%d", chip->dev_num);
if (rc)
goto out;
rc = dev_set_name(&chip->devs, "tpmrm%d", chip->dev_num);
if (rc)
goto out;
if (!pdev)
chip->flags |= TPM_CHIP_FLAG_VIRTUAL;
cdev_init(&chip->cdev, &tpm_fops);
cdev_init(&chip->cdevs, &tpmrm_fops);
chip->cdev.owner = THIS_MODULE;
chip->cdevs.owner = THIS_MODULE;
chip->work_space.context_buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (!chip->work_space.context_buf) {
rc = -ENOMEM;
goto out;
}
chip->work_space.session_buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (!chip->work_space.session_buf) {
rc = -ENOMEM;
goto out;
}
chip->locality = -1;
return chip;
out:
put_device(&chip->devs);
put_device(&chip->dev);
return ERR_PTR(rc);
}
struct tpm_chip *tpmm_chip_alloc(struct device *pdev,
const struct tpm_class_ops *ops)
{
struct tpm_chip *chip;
int rc;
chip = tpm_chip_alloc(pdev, ops);
if (IS_ERR(chip))
return chip;
rc = devm_add_action_or_reset(pdev,
(void (*)(void *)) put_device,
&chip->dev);
if (rc)
return ERR_PTR(rc);
dev_set_drvdata(pdev, chip);
return chip;
}
static int tpm_add_char_device(struct tpm_chip *chip)
{
int rc;
rc = cdev_device_add(&chip->cdev, &chip->dev);
if (rc) {
dev_err(&chip->dev,
"unable to cdev_device_add() %s, major %d, minor %d, err=%d\n",
dev_name(&chip->dev), MAJOR(chip->dev.devt),
MINOR(chip->dev.devt), rc);
return rc;
}
if (chip->flags & TPM_CHIP_FLAG_TPM2) {
rc = cdev_device_add(&chip->cdevs, &chip->devs);
if (rc) {
dev_err(&chip->devs,
"unable to cdev_device_add() %s, major %d, minor %d, err=%d\n",
dev_name(&chip->devs), MAJOR(chip->devs.devt),
MINOR(chip->devs.devt), rc);
return rc;
}
}
mutex_lock(&idr_lock);
idr_replace(&dev_nums_idr, chip, chip->dev_num);
mutex_unlock(&idr_lock);
return rc;
}
static void tpm_del_char_device(struct tpm_chip *chip)
{
cdev_device_del(&chip->cdev, &chip->dev);
mutex_lock(&idr_lock);
idr_replace(&dev_nums_idr, NULL, chip->dev_num);
mutex_unlock(&idr_lock);
down_write(&chip->ops_sem);
if (chip->flags & TPM_CHIP_FLAG_TPM2)
tpm2_shutdown(chip, TPM2_SU_CLEAR);
chip->ops = NULL;
up_write(&chip->ops_sem);
}
static void tpm_del_legacy_sysfs(struct tpm_chip *chip)
{
struct attribute **i;
if (chip->flags & (TPM_CHIP_FLAG_TPM2 | TPM_CHIP_FLAG_VIRTUAL))
return;
sysfs_remove_link(&chip->dev.parent->kobj, "ppi");
for (i = chip->groups[0]->attrs; *i != NULL; ++i)
sysfs_remove_link(&chip->dev.parent->kobj, (*i)->name);
}
static int tpm_add_legacy_sysfs(struct tpm_chip *chip)
{
struct attribute **i;
int rc;
if (chip->flags & (TPM_CHIP_FLAG_TPM2 | TPM_CHIP_FLAG_VIRTUAL))
return 0;
rc = __compat_only_sysfs_link_entry_to_kobj(
&chip->dev.parent->kobj, &chip->dev.kobj, "ppi");
if (rc && rc != -ENOENT)
return rc;
for (i = chip->groups[0]->attrs; *i != NULL; ++i) {
rc = __compat_only_sysfs_link_entry_to_kobj(
&chip->dev.parent->kobj, &chip->dev.kobj, (*i)->name);
if (rc) {
tpm_del_legacy_sysfs(chip);
return rc;
}
}
return 0;
}
int tpm_chip_register(struct tpm_chip *chip)
{
int rc;
if (chip->ops->flags & TPM_OPS_AUTO_STARTUP) {
if (chip->flags & TPM_CHIP_FLAG_TPM2)
rc = tpm2_auto_startup(chip);
else
rc = tpm1_auto_startup(chip);
if (rc)
return rc;
}
tpm_sysfs_add_device(chip);
rc = tpm_bios_log_setup(chip);
if (rc != 0 && rc != -ENODEV)
return rc;
tpm_add_ppi(chip);
rc = tpm_add_char_device(chip);
if (rc) {
tpm_bios_log_teardown(chip);
return rc;
}
rc = tpm_add_legacy_sysfs(chip);
if (rc) {
tpm_chip_unregister(chip);
return rc;
}
return 0;
}
void tpm_chip_unregister(struct tpm_chip *chip)
{
tpm_del_legacy_sysfs(chip);
tpm_bios_log_teardown(chip);
if (chip->flags & TPM_CHIP_FLAG_TPM2)
cdev_device_del(&chip->cdevs, &chip->devs);
tpm_del_char_device(chip);
}
