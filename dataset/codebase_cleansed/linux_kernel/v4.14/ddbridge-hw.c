const struct ddb_info *get_ddb_info(u16 vendor, u16 device,
u16 subvendor, u16 subdevice)
{
int i;
for (i = 0; i < ARRAY_SIZE(ddb_device_ids); i++) {
const struct ddb_device_id *id = &ddb_device_ids[i];
if (vendor == id->vendor &&
device == id->device &&
subvendor == id->subvendor &&
((subdevice == id->subdevice) ||
(id->subdevice == 0xffff)))
return id->info;
}
return &ddb_none;
}
