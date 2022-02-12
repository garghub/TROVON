static ssize_t show_ec_reboot(struct device *dev,
struct device_attribute *attr, char *buf)
{
int count = 0;
count += scnprintf(buf + count, PAGE_SIZE - count,
"ro|rw|cancel|cold|disable-jump|hibernate");
count += scnprintf(buf + count, PAGE_SIZE - count,
" [at-shutdown]\n");
return count;
}
static ssize_t store_ec_reboot(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
static const struct {
const char * const str;
uint8_t cmd;
uint8_t flags;
} words[] = {
{"cancel", EC_REBOOT_CANCEL, 0},
{"ro", EC_REBOOT_JUMP_RO, 0},
{"rw", EC_REBOOT_JUMP_RW, 0},
{"cold", EC_REBOOT_COLD, 0},
{"disable-jump", EC_REBOOT_DISABLE_JUMP, 0},
{"hibernate", EC_REBOOT_HIBERNATE, 0},
{"at-shutdown", -1, EC_REBOOT_FLAG_ON_AP_SHUTDOWN},
};
struct cros_ec_command msg = { 0 };
struct ec_params_reboot_ec *param =
(struct ec_params_reboot_ec *)msg.outdata;
int got_cmd = 0, offset = 0;
int i;
int ret;
struct cros_ec_device *ec = dev_get_drvdata(dev);
param->flags = 0;
while (1) {
while (buf[offset] && isspace(buf[offset]))
offset++;
if (!buf[offset])
break;
for (i = 0; i < ARRAY_SIZE(words); i++) {
if (!strncasecmp(words[i].str, buf+offset,
strlen(words[i].str))) {
if (words[i].flags) {
param->flags |= words[i].flags;
} else {
param->cmd = words[i].cmd;
got_cmd = 1;
}
break;
}
}
while (buf[offset] && !isspace(buf[offset]))
offset++;
}
if (!got_cmd)
return -EINVAL;
msg.command = EC_CMD_REBOOT_EC;
msg.outsize = sizeof(param);
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
return ret;
if (msg.result != EC_RES_SUCCESS) {
dev_dbg(ec->dev, "EC result %d\n", msg.result);
return -EINVAL;
}
return count;
}
static ssize_t show_ec_version(struct device *dev,
struct device_attribute *attr, char *buf)
{
static const char * const image_names[] = {"unknown", "RO", "RW"};
struct ec_response_get_version *r_ver;
struct ec_response_get_chip_info *r_chip;
struct ec_response_board_version *r_board;
struct cros_ec_command msg = { 0 };
int ret;
int count = 0;
struct cros_ec_device *ec = dev_get_drvdata(dev);
msg.command = EC_CMD_GET_VERSION;
msg.insize = sizeof(*r_ver);
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
return ret;
if (msg.result != EC_RES_SUCCESS)
return scnprintf(buf, PAGE_SIZE,
"ERROR: EC returned %d\n", msg.result);
r_ver = (struct ec_response_get_version *)msg.indata;
r_ver->version_string_ro[sizeof(r_ver->version_string_ro) - 1] = '\0';
r_ver->version_string_rw[sizeof(r_ver->version_string_rw) - 1] = '\0';
count += scnprintf(buf + count, PAGE_SIZE - count,
"RO version: %s\n", r_ver->version_string_ro);
count += scnprintf(buf + count, PAGE_SIZE - count,
"RW version: %s\n", r_ver->version_string_rw);
count += scnprintf(buf + count, PAGE_SIZE - count,
"Firmware copy: %s\n",
(r_ver->current_image < ARRAY_SIZE(image_names) ?
image_names[r_ver->current_image] : "?"));
msg.command = EC_CMD_GET_BUILD_INFO;
msg.insize = sizeof(msg.indata);
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
count += scnprintf(buf + count, PAGE_SIZE - count,
"Build info: XFER ERROR %d\n", ret);
else if (msg.result != EC_RES_SUCCESS)
count += scnprintf(buf + count, PAGE_SIZE - count,
"Build info: EC error %d\n", msg.result);
else {
msg.indata[sizeof(msg.indata) - 1] = '\0';
count += scnprintf(buf + count, PAGE_SIZE - count,
"Build info: %s\n", msg.indata);
}
msg.command = EC_CMD_GET_CHIP_INFO;
msg.insize = sizeof(*r_chip);
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
count += scnprintf(buf + count, PAGE_SIZE - count,
"Chip info: XFER ERROR %d\n", ret);
else if (msg.result != EC_RES_SUCCESS)
count += scnprintf(buf + count, PAGE_SIZE - count,
"Chip info: EC error %d\n", msg.result);
else {
r_chip = (struct ec_response_get_chip_info *)msg.indata;
r_chip->vendor[sizeof(r_chip->vendor) - 1] = '\0';
r_chip->name[sizeof(r_chip->name) - 1] = '\0';
r_chip->revision[sizeof(r_chip->revision) - 1] = '\0';
count += scnprintf(buf + count, PAGE_SIZE - count,
"Chip vendor: %s\n", r_chip->vendor);
count += scnprintf(buf + count, PAGE_SIZE - count,
"Chip name: %s\n", r_chip->name);
count += scnprintf(buf + count, PAGE_SIZE - count,
"Chip revision: %s\n", r_chip->revision);
}
msg.command = EC_CMD_GET_BOARD_VERSION;
msg.insize = sizeof(*r_board);
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
count += scnprintf(buf + count, PAGE_SIZE - count,
"Board version: XFER ERROR %d\n", ret);
else if (msg.result != EC_RES_SUCCESS)
count += scnprintf(buf + count, PAGE_SIZE - count,
"Board version: EC error %d\n", msg.result);
else {
r_board = (struct ec_response_board_version *)msg.indata;
count += scnprintf(buf + count, PAGE_SIZE - count,
"Board version: %d\n",
r_board->board_version);
}
return count;
}
static ssize_t show_ec_flashinfo(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ec_response_flash_info *resp;
struct cros_ec_command msg = { 0 };
int ret;
struct cros_ec_device *ec = dev_get_drvdata(dev);
msg.command = EC_CMD_FLASH_INFO;
msg.insize = sizeof(*resp);
ret = cros_ec_cmd_xfer(ec, &msg);
if (ret < 0)
return ret;
if (msg.result != EC_RES_SUCCESS)
return scnprintf(buf, PAGE_SIZE,
"ERROR: EC returned %d\n", msg.result);
resp = (struct ec_response_flash_info *)msg.indata;
return scnprintf(buf, PAGE_SIZE,
"FlashSize %d\nWriteSize %d\n"
"EraseSize %d\nProtectSize %d\n",
resp->flash_size, resp->write_block_size,
resp->erase_block_size, resp->protect_block_size);
}
void ec_dev_sysfs_init(struct cros_ec_device *ec)
{
int error;
error = sysfs_create_group(&ec->vdev->kobj, &ec_attr_group);
if (error)
pr_warn("failed to create group: %d\n", error);
}
void ec_dev_sysfs_remove(struct cros_ec_device *ec)
{
sysfs_remove_group(&ec->vdev->kobj, &ec_attr_group);
}
