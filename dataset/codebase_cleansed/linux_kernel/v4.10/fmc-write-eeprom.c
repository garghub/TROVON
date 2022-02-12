static int fwe_run_tlv(struct fmc_device *fmc, const struct firmware *fw,
int write)
{
const uint8_t *p = fw->data;
int len = fw->size;
uint16_t thislen, thisaddr;
int err;
while (len > 5) {
thisaddr = get_unaligned_le16(p+1);
thislen = get_unaligned_le16(p+3);
if (p[0] != 'w' || thislen + 5 > len) {
dev_err(&fmc->dev, "invalid tlv at offset %ti\n",
p - fw->data);
return -EINVAL;
}
err = 0;
if (write) {
dev_info(&fmc->dev, "write %i bytes at 0x%04x\n",
thislen, thisaddr);
err = fmc->op->write_ee(fmc, thisaddr, p + 5, thislen);
}
if (err < 0) {
dev_err(&fmc->dev, "write failure @0x%04x\n",
thisaddr);
return err;
}
p += 5 + thislen;
len -= 5 + thislen;
}
if (write)
dev_info(&fmc->dev, "write_eeprom: success\n");
return 0;
}
static int fwe_run_bin(struct fmc_device *fmc, const struct firmware *fw)
{
int ret;
dev_info(&fmc->dev, "programming %zi bytes\n", fw->size);
ret = fmc->op->write_ee(fmc, 0, (void *)fw->data, fw->size);
if (ret < 0) {
dev_info(&fmc->dev, "write_eeprom: error %i\n", ret);
return ret;
}
dev_info(&fmc->dev, "write_eeprom: success\n");
return 0;
}
static int fwe_run(struct fmc_device *fmc, const struct firmware *fw, char *s)
{
char *last4 = s + strlen(s) - 4;
int err;
if (!strcmp(last4, ".bin"))
return fwe_run_bin(fmc, fw);
if (!strcmp(last4, ".tlv")) {
err = fwe_run_tlv(fmc, fw, 0);
if (!err)
err = fwe_run_tlv(fmc, fw, 1);
return err;
}
dev_err(&fmc->dev, "invalid file name \"%s\"\n", s);
return -EINVAL;
}
static int fwe_probe(struct fmc_device *fmc)
{
int err, index = 0;
const struct firmware *fw;
struct device *dev = &fmc->dev;
char *s;
if (!fwe_drv.busid_n) {
dev_err(dev, "%s: no busid passed, refusing all cards\n",
KBUILD_MODNAME);
return -ENODEV;
}
if (fmc->op->validate)
index = fmc->op->validate(fmc, &fwe_drv);
if (index < 0) {
pr_err("%s: refusing device \"%s\"\n", KBUILD_MODNAME,
dev_name(dev));
return -ENODEV;
}
if (index >= fwe_file_n) {
pr_err("%s: no filename for device index %i\n",
KBUILD_MODNAME, index);
return -ENODEV;
}
s = fwe_file[index];
if (!s) {
pr_err("%s: no filename for \"%s\" not programming\n",
KBUILD_MODNAME, dev_name(dev));
return -ENOENT;
}
err = request_firmware(&fw, s, dev);
if (err < 0) {
dev_err(&fmc->dev, "request firmware \"%s\": error %i\n",
s, err);
return err;
}
fwe_run(fmc, fw, s);
release_firmware(fw);
return 0;
}
static int fwe_remove(struct fmc_device *fmc)
{
return 0;
}
static int fwe_init(void)
{
int ret;
ret = fmc_driver_register(&fwe_drv);
return ret;
}
static void fwe_exit(void)
{
fmc_driver_unregister(&fwe_drv);
}
