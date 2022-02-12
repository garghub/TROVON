static int idt_smb_write_byte(struct idt_89hpesx_dev *pdev,
const struct idt_smb_seq *seq)
{
s32 sts;
u8 ccode;
int idx;
for (idx = 0; idx < seq->bytecnt; idx++) {
ccode = seq->ccode | CCODE_BYTE;
if (idx == 0)
ccode |= CCODE_START;
if (idx == seq->bytecnt - 1)
ccode |= CCODE_END;
sts = idt_smb_safe(write_byte, pdev->client, ccode,
seq->data[idx]);
if (sts != 0)
return (int)sts;
}
return 0;
}
static int idt_smb_read_byte(struct idt_89hpesx_dev *pdev,
struct idt_smb_seq *seq)
{
s32 sts;
u8 ccode;
int idx;
for (idx = 0; idx < seq->bytecnt; idx++) {
ccode = seq->ccode | CCODE_BYTE;
if (idx == 0)
ccode |= CCODE_START;
if (idx == seq->bytecnt - 1)
ccode |= CCODE_END;
sts = idt_smb_safe(read_byte, pdev->client, ccode);
if (sts < 0)
return (int)sts;
seq->data[idx] = (u8)sts;
}
return 0;
}
static int idt_smb_write_word(struct idt_89hpesx_dev *pdev,
const struct idt_smb_seq *seq)
{
s32 sts;
u8 ccode;
int idx, evencnt;
evencnt = seq->bytecnt - (seq->bytecnt % 2);
for (idx = 0; idx < evencnt; idx += 2) {
ccode = seq->ccode | CCODE_WORD;
if (idx == 0)
ccode |= CCODE_START;
if (idx == evencnt - 2)
ccode |= CCODE_END;
sts = idt_smb_safe(write_word, pdev->client, ccode,
*(u16 *)&seq->data[idx]);
if (sts != 0)
return (int)sts;
}
if (seq->bytecnt != evencnt) {
ccode = seq->ccode | CCODE_BYTE | CCODE_END;
if (idx == 0)
ccode |= CCODE_START;
sts = idt_smb_safe(write_byte, pdev->client, ccode,
seq->data[idx]);
if (sts != 0)
return (int)sts;
}
return 0;
}
static int idt_smb_read_word(struct idt_89hpesx_dev *pdev,
struct idt_smb_seq *seq)
{
s32 sts;
u8 ccode;
int idx, evencnt;
evencnt = seq->bytecnt - (seq->bytecnt % 2);
for (idx = 0; idx < evencnt; idx += 2) {
ccode = seq->ccode | CCODE_WORD;
if (idx == 0)
ccode |= CCODE_START;
if (idx == evencnt - 2)
ccode |= CCODE_END;
sts = idt_smb_safe(read_word, pdev->client, ccode);
if (sts < 0)
return (int)sts;
*(u16 *)&seq->data[idx] = (u16)sts;
}
if (seq->bytecnt != evencnt) {
ccode = seq->ccode | CCODE_BYTE | CCODE_END;
if (idx == 0)
ccode |= CCODE_START;
sts = idt_smb_safe(read_byte, pdev->client, ccode);
if (sts < 0)
return (int)sts;
seq->data[idx] = (u8)sts;
}
return 0;
}
static int idt_smb_write_block(struct idt_89hpesx_dev *pdev,
const struct idt_smb_seq *seq)
{
u8 ccode;
if (seq->bytecnt > I2C_SMBUS_BLOCK_MAX)
return -EINVAL;
ccode = seq->ccode | CCODE_BLOCK | CCODE_START | CCODE_END;
return idt_smb_safe(write_block, pdev->client, ccode, seq->bytecnt,
seq->data);
}
static int idt_smb_read_block(struct idt_89hpesx_dev *pdev,
struct idt_smb_seq *seq)
{
s32 sts;
u8 ccode;
if (seq->bytecnt > I2C_SMBUS_BLOCK_MAX)
return -EINVAL;
ccode = seq->ccode | CCODE_BLOCK | CCODE_START | CCODE_END;
sts = idt_smb_safe(read_block, pdev->client, ccode, seq->data);
if (sts != seq->bytecnt)
return (sts < 0 ? sts : -ENODATA);
return 0;
}
static int idt_smb_write_i2c_block(struct idt_89hpesx_dev *pdev,
const struct idt_smb_seq *seq)
{
u8 ccode, buf[I2C_SMBUS_BLOCK_MAX + 1];
if (seq->bytecnt > I2C_SMBUS_BLOCK_MAX)
return -EINVAL;
buf[0] = seq->bytecnt;
memcpy(&buf[1], seq->data, seq->bytecnt);
ccode = seq->ccode | CCODE_BLOCK | CCODE_START | CCODE_END;
return idt_smb_safe(write_i2c_block, pdev->client, ccode,
seq->bytecnt + 1, buf);
}
static int idt_smb_read_i2c_block(struct idt_89hpesx_dev *pdev,
struct idt_smb_seq *seq)
{
u8 ccode, buf[I2C_SMBUS_BLOCK_MAX + 1];
s32 sts;
if (seq->bytecnt > I2C_SMBUS_BLOCK_MAX)
return -EINVAL;
ccode = seq->ccode | CCODE_BLOCK | CCODE_START | CCODE_END;
sts = idt_smb_safe(read_i2c_block, pdev->client, ccode,
seq->bytecnt + 1, buf);
if (sts != seq->bytecnt + 1)
return (sts < 0 ? sts : -ENODATA);
if (buf[0] != seq->bytecnt)
return -ENODATA;
memcpy(seq->data, &buf[1], seq->bytecnt);
return 0;
}
static int idt_eeprom_read_byte(struct idt_89hpesx_dev *pdev, u16 memaddr,
u8 *data)
{
struct device *dev = &pdev->client->dev;
struct idt_eeprom_seq eeseq;
struct idt_smb_seq smbseq;
int ret, retry;
smbseq.ccode = pdev->iniccode | CCODE_EEPROM;
smbseq.data = (u8 *)&eeseq;
retry = RETRY_CNT;
do {
smbseq.bytecnt = EEPROM_WRRD_CNT;
eeseq.cmd = pdev->inieecmd | EEPROM_OP_READ;
eeseq.eeaddr = pdev->eeaddr;
eeseq.memaddr = cpu_to_le16(memaddr);
ret = pdev->smb_write(pdev, &smbseq);
if (ret != 0) {
dev_err(dev, "Failed to init eeprom addr 0x%02hhx",
memaddr);
break;
}
smbseq.bytecnt = EEPROM_RD_CNT;
ret = pdev->smb_read(pdev, &smbseq);
if (ret != 0) {
dev_err(dev, "Failed to read eeprom data 0x%02hhx",
memaddr);
break;
}
if (retry && (eeseq.cmd & EEPROM_NAERR)) {
dev_dbg(dev, "EEPROM busy, retry reading after %d ms",
EEPROM_TOUT);
msleep(EEPROM_TOUT);
continue;
}
if (eeseq.cmd & (EEPROM_NAERR | EEPROM_LAERR | EEPROM_MSS)) {
dev_err(dev,
"Communication with eeprom failed, cmd 0x%hhx",
eeseq.cmd);
ret = -EREMOTEIO;
break;
}
*data = eeseq.data;
break;
} while (retry--);
return ret;
}
static int idt_eeprom_write(struct idt_89hpesx_dev *pdev, u16 memaddr, u16 len,
const u8 *data)
{
struct device *dev = &pdev->client->dev;
struct idt_eeprom_seq eeseq;
struct idt_smb_seq smbseq;
int ret;
u16 idx;
smbseq.ccode = pdev->iniccode | CCODE_EEPROM;
smbseq.data = (u8 *)&eeseq;
for (idx = 0; idx < len; idx++, memaddr++) {
mutex_lock(&pdev->smb_mtx);
smbseq.bytecnt = EEPROM_WR_CNT;
eeseq.cmd = pdev->inieecmd | EEPROM_OP_WRITE;
eeseq.eeaddr = pdev->eeaddr;
eeseq.memaddr = cpu_to_le16(memaddr);
eeseq.data = data[idx];
ret = pdev->smb_write(pdev, &smbseq);
if (ret != 0) {
dev_err(dev,
"Failed to write 0x%04hx:0x%02hhx to eeprom",
memaddr, data[idx]);
goto err_mutex_unlock;
}
eeseq.data = ~data[idx];
ret = idt_eeprom_read_byte(pdev, memaddr, &eeseq.data);
if (ret != 0)
goto err_mutex_unlock;
if (eeseq.data != data[idx]) {
dev_err(dev, "Values don't match 0x%02hhx != 0x%02hhx",
eeseq.data, data[idx]);
ret = -EREMOTEIO;
goto err_mutex_unlock;
}
err_mutex_unlock:
mutex_unlock(&pdev->smb_mtx);
if (ret != 0)
return ret;
}
return 0;
}
static int idt_eeprom_read(struct idt_89hpesx_dev *pdev, u16 memaddr, u16 len,
u8 *buf)
{
int ret;
u16 idx;
for (idx = 0; idx < len; idx++, memaddr++) {
mutex_lock(&pdev->smb_mtx);
ret = idt_eeprom_read_byte(pdev, memaddr, &buf[idx]);
mutex_unlock(&pdev->smb_mtx);
if (ret != 0)
return ret;
}
return 0;
}
static int idt_csr_write(struct idt_89hpesx_dev *pdev, u16 csraddr,
const u32 data)
{
struct device *dev = &pdev->client->dev;
struct idt_csr_seq csrseq;
struct idt_smb_seq smbseq;
int ret;
smbseq.ccode = pdev->iniccode | CCODE_CSR;
smbseq.data = (u8 *)&csrseq;
mutex_lock(&pdev->smb_mtx);
smbseq.bytecnt = CSR_WR_CNT;
csrseq.cmd = pdev->inicsrcmd | CSR_OP_WRITE;
csrseq.csraddr = cpu_to_le16(csraddr);
csrseq.data = cpu_to_le32(data);
ret = pdev->smb_write(pdev, &smbseq);
if (ret != 0) {
dev_err(dev, "Failed to write 0x%04x: 0x%04x to csr",
CSR_REAL_ADDR(csraddr), data);
goto err_mutex_unlock;
}
smbseq.bytecnt = CSR_WRRD_CNT;
csrseq.cmd = pdev->inicsrcmd | CSR_OP_READ;
ret = pdev->smb_write(pdev, &smbseq);
if (ret != 0) {
dev_err(dev, "Failed to init csr address 0x%04x",
CSR_REAL_ADDR(csraddr));
goto err_mutex_unlock;
}
smbseq.bytecnt = CSR_RD_CNT;
ret = pdev->smb_read(pdev, &smbseq);
if (ret != 0) {
dev_err(dev, "Failed to read csr 0x%04x",
CSR_REAL_ADDR(csraddr));
goto err_mutex_unlock;
}
if (csrseq.cmd & (CSR_RERR | CSR_WERR)) {
dev_err(dev, "IDT failed to perform CSR r/w");
ret = -EREMOTEIO;
goto err_mutex_unlock;
}
err_mutex_unlock:
mutex_unlock(&pdev->smb_mtx);
return ret;
}
static int idt_csr_read(struct idt_89hpesx_dev *pdev, u16 csraddr, u32 *data)
{
struct device *dev = &pdev->client->dev;
struct idt_csr_seq csrseq;
struct idt_smb_seq smbseq;
int ret;
smbseq.ccode = pdev->iniccode | CCODE_CSR;
smbseq.data = (u8 *)&csrseq;
mutex_lock(&pdev->smb_mtx);
smbseq.bytecnt = CSR_WRRD_CNT;
csrseq.cmd = pdev->inicsrcmd | CSR_OP_READ;
csrseq.csraddr = cpu_to_le16(csraddr);
ret = pdev->smb_write(pdev, &smbseq);
if (ret != 0) {
dev_err(dev, "Failed to init csr address 0x%04x",
CSR_REAL_ADDR(csraddr));
goto err_mutex_unlock;
}
smbseq.bytecnt = CSR_RD_CNT;
ret = pdev->smb_read(pdev, &smbseq);
if (ret != 0) {
dev_err(dev, "Failed to read csr 0x%04hx",
CSR_REAL_ADDR(csraddr));
goto err_mutex_unlock;
}
if (csrseq.cmd & (CSR_RERR | CSR_WERR)) {
dev_err(dev, "IDT failed to perform CSR r/w");
ret = -EREMOTEIO;
goto err_mutex_unlock;
}
*data = le32_to_cpu(csrseq.data);
err_mutex_unlock:
mutex_unlock(&pdev->smb_mtx);
return ret;
}
static ssize_t eeprom_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct idt_89hpesx_dev *pdev;
int ret;
pdev = dev_get_drvdata(kobj_to_dev(kobj));
ret = idt_eeprom_write(pdev, (u16)off, (u16)count, (u8 *)buf);
return (ret != 0 ? ret : count);
}
static ssize_t eeprom_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct idt_89hpesx_dev *pdev;
int ret;
pdev = dev_get_drvdata(kobj_to_dev(kobj));
ret = idt_eeprom_read(pdev, (u16)off, (u16)count, (u8 *)buf);
return (ret != 0 ? ret : count);
}
static ssize_t idt_dbgfs_csr_write(struct file *filep, const char __user *ubuf,
size_t count, loff_t *offp)
{
struct idt_89hpesx_dev *pdev = filep->private_data;
char *colon_ch, *csraddr_str, *csrval_str;
int ret, csraddr_len, csrval_len;
u32 csraddr, csrval;
char *buf;
buf = kmalloc(count + 1, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = simple_write_to_buffer(buf, count, offp, ubuf, count);
if (ret < 0)
goto free_buf;
buf[count] = 0;
colon_ch = strnchr(buf, count, ':');
if (colon_ch != NULL) {
csraddr_len = colon_ch - buf;
csraddr_str =
kmalloc(sizeof(char)*(csraddr_len + 1), GFP_KERNEL);
if (csraddr_str == NULL) {
ret = -ENOMEM;
goto free_buf;
}
strncpy(csraddr_str, buf, csraddr_len);
csraddr_str[csraddr_len] = '\0';
csrval_str = colon_ch + 1;
csrval_len = strnlen(csrval_str, count - csraddr_len);
} else {
csraddr_str = (char *)buf;
csraddr_len = strnlen(csraddr_str, count);
csrval_str = NULL;
csrval_len = 0;
}
ret = kstrtou32(csraddr_str, 0, &csraddr);
if (ret != 0)
goto free_csraddr_str;
if (csraddr > CSR_MAX || !IS_ALIGNED(csraddr, SZ_4)) {
ret = -EINVAL;
goto free_csraddr_str;
}
pdev->csr = (csraddr >> 2);
if (colon_ch != NULL) {
ret = kstrtou32(csrval_str, 0, &csrval);
if (ret != 0)
goto free_csraddr_str;
ret = idt_csr_write(pdev, pdev->csr, csrval);
if (ret != 0)
goto free_csraddr_str;
}
free_csraddr_str:
if (colon_ch != NULL)
kfree(csraddr_str);
free_buf:
kfree(buf);
return (ret != 0 ? ret : count);
}
static ssize_t idt_dbgfs_csr_read(struct file *filep, char __user *ubuf,
size_t count, loff_t *offp)
{
struct idt_89hpesx_dev *pdev = filep->private_data;
u32 csraddr, csrval;
char buf[CSRBUF_SIZE];
int ret, size;
ret = idt_csr_read(pdev, pdev->csr, &csrval);
if (ret != 0)
return ret;
csraddr = ((u32)pdev->csr << 2);
size = snprintf(buf, CSRBUF_SIZE, "0x%05x:0x%08x\n",
(unsigned int)csraddr, (unsigned int)csrval);
return simple_read_from_buffer(ubuf, count, offp, buf, size);
}
static void idt_set_defval(struct idt_89hpesx_dev *pdev)
{
pdev->eesize = 0;
pdev->eero = true;
pdev->inieecmd = 0;
pdev->eeaddr = 0;
}
static const struct i2c_device_id *idt_ee_match_id(struct fwnode_handle *fwnode)
{
const struct i2c_device_id *id = ee_ids;
const char *compatible, *p;
char devname[I2C_NAME_SIZE];
int ret;
ret = fwnode_property_read_string(fwnode, "compatible", &compatible);
if (ret)
return NULL;
p = strchr(compatible, ',');
strlcpy(devname, p ? p + 1 : compatible, sizeof(devname));
while (id->name[0]) {
if (strcmp(devname, id->name) == 0)
return id;
id++;
}
return NULL;
}
static void idt_get_fw_data(struct idt_89hpesx_dev *pdev)
{
struct device *dev = &pdev->client->dev;
struct fwnode_handle *fwnode;
const struct i2c_device_id *ee_id = NULL;
u32 eeprom_addr;
int ret;
device_for_each_child_node(dev, fwnode) {
ee_id = idt_ee_match_id(fwnode);
if (IS_ERR_OR_NULL(ee_id)) {
dev_warn(dev, "Skip unsupported EEPROM device");
continue;
} else
break;
}
if (!ee_id) {
dev_warn(dev, "No fwnode, EEPROM access disabled");
idt_set_defval(pdev);
return;
}
pdev->eesize = (u32)ee_id->driver_data;
ret = fwnode_property_read_u32(fwnode, "reg", &eeprom_addr);
if (ret || (eeprom_addr == 0)) {
dev_warn(dev, "No EEPROM reg found, use default address 0x%x",
EEPROM_DEF_ADDR);
pdev->inieecmd = 0;
pdev->eeaddr = EEPROM_DEF_ADDR << 1;
} else {
pdev->inieecmd = EEPROM_USA;
pdev->eeaddr = eeprom_addr << 1;
}
if (fwnode_property_read_bool(fwnode, "read-only"))
pdev->eero = true;
else
pdev->eero = false;
dev_info(dev, "EEPROM of %d bytes found by 0x%x",
pdev->eesize, pdev->eeaddr);
}
static struct idt_89hpesx_dev *idt_create_pdev(struct i2c_client *client)
{
struct idt_89hpesx_dev *pdev;
pdev = devm_kmalloc(&client->dev, sizeof(struct idt_89hpesx_dev),
GFP_KERNEL);
if (pdev == NULL)
return ERR_PTR(-ENOMEM);
pdev->client = client;
i2c_set_clientdata(client, pdev);
idt_get_fw_data(pdev);
pdev->inicsrcmd = CSR_DWE;
pdev->csr = CSR_DEF;
if (i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_PEC)) {
pdev->iniccode = CCODE_PEC;
client->flags |= I2C_CLIENT_PEC;
} else {
pdev->iniccode = 0;
}
return pdev;
}
static void idt_free_pdev(struct idt_89hpesx_dev *pdev)
{
i2c_set_clientdata(pdev->client, NULL);
}
static int idt_set_smbus_ops(struct idt_89hpesx_dev *pdev)
{
struct i2c_adapter *adapter = pdev->client->adapter;
struct device *dev = &pdev->client->dev;
if (i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_READ_BLOCK_DATA)) {
pdev->smb_read = idt_smb_read_block;
dev_dbg(dev, "SMBus block-read op chosen");
} else if (i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_READ_I2C_BLOCK)) {
pdev->smb_read = idt_smb_read_i2c_block;
dev_dbg(dev, "SMBus i2c-block-read op chosen");
} else if (i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_READ_WORD_DATA) &&
i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_READ_BYTE_DATA)) {
pdev->smb_read = idt_smb_read_word;
dev_warn(dev, "Use slow word/byte SMBus read ops");
} else if (i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_READ_BYTE_DATA)) {
pdev->smb_read = idt_smb_read_byte;
dev_warn(dev, "Use slow byte SMBus read op");
} else {
dev_err(dev, "No supported SMBus read op");
return -EPFNOSUPPORT;
}
if (i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_WRITE_BLOCK_DATA)) {
pdev->smb_write = idt_smb_write_block;
dev_dbg(dev, "SMBus block-write op chosen");
} else if (i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_WRITE_I2C_BLOCK)) {
pdev->smb_write = idt_smb_write_i2c_block;
dev_dbg(dev, "SMBus i2c-block-write op chosen");
} else if (i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_WRITE_WORD_DATA) &&
i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_WRITE_BYTE_DATA)) {
pdev->smb_write = idt_smb_write_word;
dev_warn(dev, "Use slow word/byte SMBus write op");
} else if (i2c_check_functionality(adapter,
I2C_FUNC_SMBUS_WRITE_BYTE_DATA)) {
pdev->smb_write = idt_smb_write_byte;
dev_warn(dev, "Use slow byte SMBus write op");
} else {
dev_err(dev, "No supported SMBus write op");
return -EPFNOSUPPORT;
}
mutex_init(&pdev->smb_mtx);
return 0;
}
static int idt_check_dev(struct idt_89hpesx_dev *pdev)
{
struct device *dev = &pdev->client->dev;
u32 viddid;
int ret;
ret = idt_csr_read(pdev, IDT_VIDDID_CSR, &viddid);
if (ret != 0) {
dev_err(dev, "Failed to read VID/DID");
return ret;
}
if ((viddid & IDT_VID_MASK) != PCI_VENDOR_ID_IDT) {
dev_err(dev, "Got unsupported VID/DID: 0x%08x", viddid);
return -ENODEV;
}
dev_info(dev, "Found IDT 89HPES device VID:0x%04x, DID:0x%04x",
(viddid & IDT_VID_MASK), (viddid >> 16));
return 0;
}
static int idt_create_sysfs_files(struct idt_89hpesx_dev *pdev)
{
struct device *dev = &pdev->client->dev;
int ret;
if (pdev->eesize == 0) {
dev_dbg(dev, "Skip creating sysfs-files");
return 0;
}
pdev->ee_file = devm_kmalloc(dev, sizeof(*pdev->ee_file), GFP_KERNEL);
if (!pdev->ee_file)
return -ENOMEM;
memcpy(pdev->ee_file, &bin_attr_eeprom, sizeof(*pdev->ee_file));
if (pdev->eero) {
pdev->ee_file->attr.mode &= ~0200;
pdev->ee_file->write = NULL;
}
pdev->ee_file->size = pdev->eesize;
ret = sysfs_create_bin_file(&dev->kobj, pdev->ee_file);
if (ret != 0) {
dev_err(dev, "Failed to create EEPROM sysfs-node");
return ret;
}
return 0;
}
static void idt_remove_sysfs_files(struct idt_89hpesx_dev *pdev)
{
struct device *dev = &pdev->client->dev;
if (pdev->eesize == 0)
return;
sysfs_remove_bin_file(&dev->kobj, pdev->ee_file);
}
static void idt_create_dbgfs_files(struct idt_89hpesx_dev *pdev)
{
struct i2c_client *cli = pdev->client;
char fname[CSRNAME_LEN];
snprintf(fname, CSRNAME_LEN, "%d-%04hx", cli->adapter->nr, cli->addr);
pdev->csr_dir = debugfs_create_dir(fname, csr_dbgdir);
pdev->csr_file = debugfs_create_file(cli->name, 0600,
pdev->csr_dir, pdev, &csr_dbgfs_ops);
}
static void idt_remove_dbgfs_files(struct idt_89hpesx_dev *pdev)
{
debugfs_remove_recursive(pdev->csr_dir);
}
static int idt_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct idt_89hpesx_dev *pdev;
int ret;
pdev = idt_create_pdev(client);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
ret = idt_set_smbus_ops(pdev);
if (ret != 0)
goto err_free_pdev;
ret = idt_check_dev(pdev);
if (ret != 0)
goto err_free_pdev;
ret = idt_create_sysfs_files(pdev);
if (ret != 0)
goto err_free_pdev;
idt_create_dbgfs_files(pdev);
return 0;
err_free_pdev:
idt_free_pdev(pdev);
return ret;
}
static int idt_remove(struct i2c_client *client)
{
struct idt_89hpesx_dev *pdev = i2c_get_clientdata(client);
idt_remove_dbgfs_files(pdev);
idt_remove_sysfs_files(pdev);
idt_free_pdev(pdev);
return 0;
}
static int __init idt_init(void)
{
if (debugfs_initialized())
csr_dbgdir = debugfs_create_dir("idt_csr", NULL);
return i2c_add_driver(&idt_driver);
}
static void __exit idt_exit(void)
{
debugfs_remove_recursive(csr_dbgdir);
i2c_del_driver(&idt_driver);
}
