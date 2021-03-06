static int __init ab3100_otp_read(struct ab3100_otp *otp)
{
u8 otpval[8];
u8 otpp;
int err;
err = abx500_get_register_interruptible(otp->dev, 0,
AB3100_OTPP, &otpp);
if (err) {
dev_err(otp->dev, "unable to read OTPP register\n");
return err;
}
err = abx500_get_register_page_interruptible(otp->dev, 0,
AB3100_OTP0, otpval, 8);
if (err) {
dev_err(otp->dev, "unable to read OTP register page\n");
return err;
}
otp->locked = (otpp & 0x80);
otp->freq = (otpp & 0x40) ? 32768 : 34100;
otp->paf = (otpval[1] & 0x80);
otp->imeich = (otpval[1] & 0x40);
otp->cid = ((otpval[1] << 8) | otpval[0]) & 0x3fff;
otp->tac = ((otpval[4] & 0x0f) << 16) | (otpval[3] << 8) | otpval[2];
otp->fac = ((otpval[5] & 0x0f) << 4) | (otpval[4] >> 4);
otp->svn = (otpval[7] << 12) | (otpval[6] << 4) | (otpval[5] >> 4);
return 0;
}
static int ab3100_show_otp(struct seq_file *s, void *v)
{
struct ab3100_otp *otp = s->private;
seq_printf(s, "OTP is %s\n", otp->locked ? "LOCKED" : "UNLOCKED");
seq_printf(s, "OTP clock switch startup is %uHz\n", otp->freq);
seq_printf(s, "PAF is %s\n", otp->paf ? "SET" : "NOT SET");
seq_printf(s, "IMEI is %s\n", otp->imeich ?
"CHANGEABLE" : "NOT CHANGEABLE");
seq_printf(s, "CID: 0x%04x (decimal: %d)\n", otp->cid, otp->cid);
seq_printf(s, "IMEI: %u-%u-%u\n", otp->tac, otp->fac, otp->svn);
return 0;
}
static int ab3100_otp_open(struct inode *inode, struct file *file)
{
return single_open(file, ab3100_show_otp, inode->i_private);
}
static int __init ab3100_otp_init_debugfs(struct device *dev,
struct ab3100_otp *otp)
{
otp->debugfs = debugfs_create_file("ab3100_otp", S_IFREG | S_IRUGO,
NULL, otp,
&ab3100_otp_operations);
if (!otp->debugfs) {
dev_err(dev, "AB3100 debugfs OTP file registration failed!\n");
return -ENOENT;
}
return 0;
}
static void __exit ab3100_otp_exit_debugfs(struct ab3100_otp *otp)
{
debugfs_remove(otp->debugfs);
}
static inline int __init ab3100_otp_init_debugfs(struct device *dev,
struct ab3100_otp *otp)
{
return 0;
}
static inline void __exit ab3100_otp_exit_debugfs(struct ab3100_otp *otp)
{
}
static int __init ab3100_otp_probe(struct platform_device *pdev)
{
struct ab3100_otp *otp;
int err = 0;
int i;
otp = kzalloc(sizeof(struct ab3100_otp), GFP_KERNEL);
if (!otp) {
dev_err(&pdev->dev, "could not allocate AB3100 OTP device\n");
return -ENOMEM;
}
otp->dev = &pdev->dev;
platform_set_drvdata(pdev, otp);
err = ab3100_otp_read(otp);
if (err)
goto err_otp_read;
dev_info(&pdev->dev, "AB3100 OTP readout registered\n");
for (i = 0; i < ARRAY_SIZE(ab3100_otp_attrs); i++) {
err = device_create_file(&pdev->dev,
&ab3100_otp_attrs[i]);
if (err)
goto err_create_file;
}
err = ab3100_otp_init_debugfs(&pdev->dev, otp);
if (err)
goto err_init_debugfs;
return 0;
err_init_debugfs:
err_create_file:
while (--i >= 0)
device_remove_file(&pdev->dev, &ab3100_otp_attrs[i]);
err_otp_read:
kfree(otp);
return err;
}
static int __exit ab3100_otp_remove(struct platform_device *pdev)
{
struct ab3100_otp *otp = platform_get_drvdata(pdev);
int i;
for (i = 0; i < ARRAY_SIZE(ab3100_otp_attrs); i++)
device_remove_file(&pdev->dev,
&ab3100_otp_attrs[i]);
ab3100_otp_exit_debugfs(otp);
kfree(otp);
return 0;
}
