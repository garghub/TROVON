static inline u32 sigma_action_len(struct sigma_action *sa)
{
return (sa->len_hi << 16) | le16_to_cpu(sa->len);
}
static size_t sigma_action_size(struct sigma_action *sa)
{
size_t payload = 0;
switch (sa->instr) {
case SIGMA_ACTION_WRITEXBYTES:
case SIGMA_ACTION_WRITESINGLE:
case SIGMA_ACTION_WRITESAFELOAD:
payload = sigma_action_len(sa);
break;
default:
break;
}
payload = ALIGN(payload, 2);
return payload + sizeof(struct sigma_action);
}
static int
process_sigma_action(struct sigma_firmware *ssfw, struct sigma_action *sa)
{
size_t len = sigma_action_len(sa);
int ret;
pr_debug("%s: instr:%i addr:%#x len:%zu\n", __func__,
sa->instr, sa->addr, len);
switch (sa->instr) {
case SIGMA_ACTION_WRITEXBYTES:
case SIGMA_ACTION_WRITESINGLE:
case SIGMA_ACTION_WRITESAFELOAD:
ret = ssfw->write(ssfw->control_data, sa, len);
if (ret < 0)
return -EINVAL;
break;
case SIGMA_ACTION_DELAY:
udelay(len);
len = 0;
break;
case SIGMA_ACTION_END:
return 0;
default:
return -EINVAL;
}
return 1;
}
static int
process_sigma_actions(struct sigma_firmware *ssfw)
{
struct sigma_action *sa;
size_t size;
int ret;
while (ssfw->pos + sizeof(*sa) <= ssfw->fw->size) {
sa = (struct sigma_action *)(ssfw->fw->data + ssfw->pos);
size = sigma_action_size(sa);
ssfw->pos += size;
if (ssfw->pos > ssfw->fw->size || size == 0)
break;
ret = process_sigma_action(ssfw, sa);
pr_debug("%s: action returned %i\n", __func__, ret);
if (ret <= 0)
return ret;
}
if (ssfw->pos != ssfw->fw->size)
return -EINVAL;
return 0;
}
int _process_sigma_firmware(struct device *dev,
struct sigma_firmware *ssfw, const char *name)
{
int ret;
struct sigma_firmware_header *ssfw_head;
const struct firmware *fw;
u32 crc;
pr_debug("%s: loading firmware %s\n", __func__, name);
ret = request_firmware(&fw, name, dev);
if (ret) {
pr_debug("%s: request_firmware() failed with %i\n", __func__, ret);
return ret;
}
ssfw->fw = fw;
ret = -EINVAL;
if (fw->size < sizeof(*ssfw_head) || fw->size >= 0x4000000) {
dev_err(dev, "Failed to load firmware: Invalid size\n");
goto done;
}
ssfw_head = (void *)fw->data;
if (memcmp(ssfw_head->magic, SIGMA_MAGIC, ARRAY_SIZE(ssfw_head->magic))) {
dev_err(dev, "Failed to load firmware: Invalid magic\n");
goto done;
}
crc = crc32(0, fw->data + sizeof(*ssfw_head),
fw->size - sizeof(*ssfw_head));
pr_debug("%s: crc=%x\n", __func__, crc);
if (crc != le32_to_cpu(ssfw_head->crc)) {
dev_err(dev, "Failed to load firmware: Wrong crc checksum: expected %x got %x\n",
le32_to_cpu(ssfw_head->crc), crc);
goto done;
}
ssfw->pos = sizeof(*ssfw_head);
ret = process_sigma_actions(ssfw);
done:
release_firmware(fw);
pr_debug("%s: loaded %s\n", __func__, name);
return ret;
}
