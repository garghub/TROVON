struct tpm_chip *tpm_chip_find_get(int chip_num)
{
struct tpm_chip *pos, *chip = NULL;
rcu_read_lock();
list_for_each_entry_rcu(pos, &tpm_chip_list, list) {
if (chip_num != TPM_ANY_NUM && chip_num != pos->dev_num)
continue;
if (try_module_get(pos->pdev->driver->owner)) {
chip = pos;
break;
}
}
rcu_read_unlock();
return chip;
}
static void tpm_dev_release(struct device *dev)
{
struct tpm_chip *chip = container_of(dev, struct tpm_chip, dev);
spin_lock(&driver_lock);
clear_bit(chip->dev_num, dev_mask);
spin_unlock(&driver_lock);
kfree(chip);
}
struct tpm_chip *tpmm_chip_alloc(struct device *dev,
const struct tpm_class_ops *ops)
{
struct tpm_chip *chip;
int rc;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL)
return ERR_PTR(-ENOMEM);
mutex_init(&chip->tpm_mutex);
INIT_LIST_HEAD(&chip->list);
chip->ops = ops;
spin_lock(&driver_lock);
chip->dev_num = find_first_zero_bit(dev_mask, TPM_NUM_DEVICES);
spin_unlock(&driver_lock);
if (chip->dev_num >= TPM_NUM_DEVICES) {
dev_err(dev, "No available tpm device numbers\n");
kfree(chip);
return ERR_PTR(-ENOMEM);
}
set_bit(chip->dev_num, dev_mask);
scnprintf(chip->devname, sizeof(chip->devname), "tpm%d", chip->dev_num);
chip->pdev = dev;
dev_set_drvdata(dev, chip);
chip->dev.class = tpm_class;
chip->dev.release = tpm_dev_release;
chip->dev.parent = chip->pdev;
#ifdef CONFIG_ACPI
chip->dev.groups = chip->groups;
#endif
if (chip->dev_num == 0)
chip->dev.devt = MKDEV(MISC_MAJOR, TPM_MINOR);
else
chip->dev.devt = MKDEV(MAJOR(tpm_devt), chip->dev_num);
dev_set_name(&chip->dev, "%s", chip->devname);
device_initialize(&chip->dev);
cdev_init(&chip->cdev, &tpm_fops);
chip->cdev.owner = chip->pdev->driver->owner;
chip->cdev.kobj.parent = &chip->dev.kobj;
rc = devm_add_action(dev, (void (*)(void *)) put_device, &chip->dev);
if (rc) {
put_device(&chip->dev);
return ERR_PTR(rc);
}
return chip;
}
static int tpm_add_char_device(struct tpm_chip *chip)
{
int rc;
rc = cdev_add(&chip->cdev, chip->dev.devt, 1);
if (rc) {
dev_err(&chip->dev,
"unable to cdev_add() %s, major %d, minor %d, err=%d\n",
chip->devname, MAJOR(chip->dev.devt),
MINOR(chip->dev.devt), rc);
return rc;
}
rc = device_add(&chip->dev);
if (rc) {
dev_err(&chip->dev,
"unable to device_register() %s, major %d, minor %d, err=%d\n",
chip->devname, MAJOR(chip->dev.devt),
MINOR(chip->dev.devt), rc);
cdev_del(&chip->cdev);
return rc;
}
return rc;
}
static void tpm_del_char_device(struct tpm_chip *chip)
{
cdev_del(&chip->cdev);
device_del(&chip->dev);
}
static int tpm1_chip_register(struct tpm_chip *chip)
{
int rc;
if (chip->flags & TPM_CHIP_FLAG_TPM2)
return 0;
rc = tpm_sysfs_add_device(chip);
if (rc)
return rc;
chip->bios_dir = tpm_bios_log_setup(chip->devname);
return 0;
}
static void tpm1_chip_unregister(struct tpm_chip *chip)
{
if (chip->flags & TPM_CHIP_FLAG_TPM2)
return;
if (chip->bios_dir)
tpm_bios_log_teardown(chip->bios_dir);
tpm_sysfs_del_device(chip);
}
int tpm_chip_register(struct tpm_chip *chip)
{
int rc;
rc = tpm1_chip_register(chip);
if (rc)
return rc;
tpm_add_ppi(chip);
rc = tpm_add_char_device(chip);
if (rc)
goto out_err;
spin_lock(&driver_lock);
list_add_tail_rcu(&chip->list, &tpm_chip_list);
spin_unlock(&driver_lock);
chip->flags |= TPM_CHIP_FLAG_REGISTERED;
if (!(chip->flags & TPM_CHIP_FLAG_TPM2)) {
rc = __compat_only_sysfs_link_entry_to_kobj(&chip->pdev->kobj,
&chip->dev.kobj,
"ppi");
if (rc && rc != -ENOENT) {
tpm_chip_unregister(chip);
return rc;
}
}
return 0;
out_err:
tpm1_chip_unregister(chip);
return rc;
}
void tpm_chip_unregister(struct tpm_chip *chip)
{
if (!(chip->flags & TPM_CHIP_FLAG_REGISTERED))
return;
spin_lock(&driver_lock);
list_del_rcu(&chip->list);
spin_unlock(&driver_lock);
synchronize_rcu();
if (!(chip->flags & TPM_CHIP_FLAG_TPM2))
sysfs_remove_link(&chip->pdev->kobj, "ppi");
tpm1_chip_unregister(chip);
tpm_del_char_device(chip);
}
