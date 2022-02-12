static int __init dump_properties_enable(char *arg)
{
dump_properties = true;
return 0;
}
static void __init unmarshal_key_value_pairs(struct dev_header *dev_header,
struct device *dev, void *ptr,
struct property_entry entry[])
{
int i;
for (i = 0; i < dev_header->prop_count; i++) {
int remaining = dev_header->len - (ptr - (void *)dev_header);
u32 key_len, val_len;
char *key;
if (sizeof(key_len) > remaining)
break;
key_len = *(typeof(key_len) *)ptr;
if (key_len + sizeof(val_len) > remaining ||
key_len < sizeof(key_len) + sizeof(efi_char16_t) ||
*(efi_char16_t *)(ptr + sizeof(key_len)) == 0) {
dev_err(dev, "invalid property name len at %#zx\n",
ptr - (void *)dev_header);
break;
}
val_len = *(typeof(val_len) *)(ptr + key_len);
if (key_len + val_len > remaining ||
val_len < sizeof(val_len)) {
dev_err(dev, "invalid property val len at %#zx\n",
ptr - (void *)dev_header + key_len);
break;
}
key = kzalloc((key_len - sizeof(key_len)) * 4 + 1, GFP_KERNEL);
if (!key) {
dev_err(dev, "cannot allocate property name\n");
break;
}
ucs2_as_utf8(key, ptr + sizeof(key_len),
key_len - sizeof(key_len));
entry[i].name = key;
entry[i].is_array = true;
entry[i].length = val_len - sizeof(val_len);
entry[i].pointer.raw_data = ptr + key_len + sizeof(val_len);
if (!entry[i].length) {
entry[i].length = 1;
entry[i].pointer.raw_data = &one;
}
if (dump_properties) {
dev_info(dev, "property: %s\n", entry[i].name);
print_hex_dump(KERN_INFO, pr_fmt(), DUMP_PREFIX_OFFSET,
16, 1, entry[i].pointer.raw_data,
entry[i].length, true);
}
ptr += key_len + val_len;
}
if (i != dev_header->prop_count) {
dev_err(dev, "got %d device properties, expected %u\n", i,
dev_header->prop_count);
print_hex_dump(KERN_ERR, pr_fmt(), DUMP_PREFIX_OFFSET,
16, 1, dev_header, dev_header->len, true);
return;
}
dev_info(dev, "assigning %d device properties\n", i);
}
static int __init unmarshal_devices(struct properties_header *properties)
{
size_t offset = offsetof(struct properties_header, dev_header[0]);
while (offset + sizeof(struct dev_header) < properties->len) {
struct dev_header *dev_header = (void *)properties + offset;
struct property_entry *entry = NULL;
struct device *dev;
size_t len;
int ret, i;
void *ptr;
if (offset + dev_header->len > properties->len ||
dev_header->len <= sizeof(*dev_header)) {
pr_err("invalid len in dev_header at %#zx\n", offset);
return -EINVAL;
}
ptr = dev_header->path;
len = dev_header->len - sizeof(*dev_header);
dev = efi_get_device_by_path((struct efi_dev_path **)&ptr, &len);
if (IS_ERR(dev)) {
pr_err("device path parse error %ld at %#zx:\n",
PTR_ERR(dev), ptr - (void *)dev_header);
print_hex_dump(KERN_ERR, pr_fmt(), DUMP_PREFIX_OFFSET,
16, 1, dev_header, dev_header->len, true);
dev = NULL;
goto skip_device;
}
entry = kcalloc(dev_header->prop_count + 1, sizeof(*entry),
GFP_KERNEL);
if (!entry) {
dev_err(dev, "cannot allocate properties\n");
goto skip_device;
}
unmarshal_key_value_pairs(dev_header, dev, ptr, entry);
if (!entry[0].name)
goto skip_device;
ret = device_add_properties(dev, entry);
if (ret)
dev_err(dev, "error %d assigning properties\n", ret);
for (i = 0; entry[i].name; i++)
kfree(entry[i].name);
skip_device:
kfree(entry);
put_device(dev);
offset += dev_header->len;
}
return 0;
}
static int __init map_properties(void)
{
struct properties_header *properties;
struct setup_data *data;
u32 data_len;
u64 pa_data;
int ret;
if (!dmi_match(DMI_SYS_VENDOR, "Apple Inc.") &&
!dmi_match(DMI_SYS_VENDOR, "Apple Computer, Inc."))
return 0;
pa_data = boot_params.hdr.setup_data;
while (pa_data) {
data = ioremap(pa_data, sizeof(*data));
if (!data) {
pr_err("cannot map setup_data header\n");
return -ENOMEM;
}
if (data->type != SETUP_APPLE_PROPERTIES) {
pa_data = data->next;
iounmap(data);
continue;
}
data_len = data->len;
iounmap(data);
data = ioremap(pa_data, sizeof(*data) + data_len);
if (!data) {
pr_err("cannot map setup_data payload\n");
return -ENOMEM;
}
properties = (struct properties_header *)data->data;
if (properties->version != 1) {
pr_err("unsupported version:\n");
print_hex_dump(KERN_ERR, pr_fmt(), DUMP_PREFIX_OFFSET,
16, 1, properties, data_len, true);
ret = -ENOTSUPP;
} else if (properties->len != data_len) {
pr_err("length mismatch, expected %u\n", data_len);
print_hex_dump(KERN_ERR, pr_fmt(), DUMP_PREFIX_OFFSET,
16, 1, properties, data_len, true);
ret = -EINVAL;
} else
ret = unmarshal_devices(properties);
data->len = 0;
iounmap(data);
free_bootmem_late(pa_data + sizeof(*data), data_len);
return ret;
}
return 0;
}
