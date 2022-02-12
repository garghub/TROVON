static int tpm_open(struct inode *inode, struct file *file)
{
struct tpm_chip *chip;
struct file_priv *priv;
chip = container_of(inode->i_cdev, struct tpm_chip, cdev);
if (test_and_set_bit(0, &chip->is_open)) {
dev_dbg(&chip->dev, "Another process owns this TPM\n");
return -EBUSY;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (priv == NULL)
goto out;
tpm_common_open(file, chip, priv);
return 0;
out:
clear_bit(0, &chip->is_open);
return -ENOMEM;
}
static ssize_t tpm_write(struct file *file, const char __user *buf,
size_t size, loff_t *off)
{
return tpm_common_write(file, buf, size, off, NULL);
}
static int tpm_release(struct inode *inode, struct file *file)
{
struct file_priv *priv = file->private_data;
tpm_common_release(file, priv);
clear_bit(0, &priv->chip->is_open);
kfree(priv);
return 0;
}
