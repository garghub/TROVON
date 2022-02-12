static void __init dmi_add_platform_ipmi(unsigned long base_addr,
u32 flags,
u8 slave_addr,
int irq,
int offset,
int type)
{
struct platform_device *pdev;
struct resource r[4];
unsigned int num_r = 1, size;
struct property_entry p[4] = {
PROPERTY_ENTRY_U8("slave-addr", slave_addr),
PROPERTY_ENTRY_U8("ipmi-type", type),
PROPERTY_ENTRY_U16("i2c-addr", base_addr),
{ }
};
char *name, *override;
int rv;
struct ipmi_dmi_info *info;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
pr_warn("ipmi:dmi: Could not allocate dmi info\n");
} else {
info->type = type;
info->flags = flags;
info->addr = base_addr;
info->slave_addr = slave_addr;
info->next = ipmi_dmi_infos;
ipmi_dmi_infos = info;
}
name = "dmi-ipmi-si";
override = "ipmi_si";
switch (type) {
case IPMI_DMI_TYPE_SSIF:
name = "dmi-ipmi-ssif";
override = "ipmi_ssif";
offset = 1;
size = 1;
break;
case IPMI_DMI_TYPE_BT:
size = 3;
break;
case IPMI_DMI_TYPE_KCS:
case IPMI_DMI_TYPE_SMIC:
size = 2;
break;
default:
pr_err("ipmi:dmi: Invalid IPMI type: %d", type);
return;
}
pdev = platform_device_alloc(name, ipmi_dmi_nr);
if (!pdev) {
pr_err("ipmi:dmi: Error allocation IPMI platform device");
return;
}
pdev->driver_override = override;
if (type == IPMI_DMI_TYPE_SSIF)
goto add_properties;
memset(r, 0, sizeof(r));
r[0].start = base_addr;
r[0].end = r[0].start + offset - 1;
r[0].name = "IPMI Address 1";
r[0].flags = flags;
if (size > 1) {
r[1].start = r[0].start + offset;
r[1].end = r[1].start + offset - 1;
r[1].name = "IPMI Address 2";
r[1].flags = flags;
num_r++;
}
if (size > 2) {
r[2].start = r[1].start + offset;
r[2].end = r[2].start + offset - 1;
r[2].name = "IPMI Address 3";
r[2].flags = flags;
num_r++;
}
if (irq) {
r[num_r].start = irq;
r[num_r].end = irq;
r[num_r].name = "IPMI IRQ";
r[num_r].flags = IORESOURCE_IRQ;
num_r++;
}
rv = platform_device_add_resources(pdev, r, num_r);
if (rv) {
dev_err(&pdev->dev,
"ipmi:dmi: Unable to add resources: %d\n", rv);
goto err;
}
add_properties:
rv = platform_device_add_properties(pdev, p);
if (rv) {
dev_err(&pdev->dev,
"ipmi:dmi: Unable to add properties: %d\n", rv);
goto err;
}
rv = platform_device_add(pdev);
if (rv) {
dev_err(&pdev->dev, "ipmi:dmi: Unable to add device: %d\n", rv);
goto err;
}
ipmi_dmi_nr++;
return;
err:
platform_device_put(pdev);
}
int ipmi_dmi_get_slave_addr(int type, u32 flags, unsigned long base_addr)
{
struct ipmi_dmi_info *info = ipmi_dmi_infos;
while (info) {
if (info->type == type &&
info->flags == flags &&
info->addr == base_addr)
return info->slave_addr;
info = info->next;
}
return 0;
}
static void __init dmi_decode_ipmi(const struct dmi_header *dm)
{
const u8 *data = (const u8 *) dm;
u32 flags = IORESOURCE_IO;
unsigned long base_addr;
u8 len = dm->length;
u8 slave_addr;
int irq = 0, offset;
int type;
if (len < DMI_IPMI_MIN_LENGTH)
return;
type = data[DMI_IPMI_TYPE];
slave_addr = data[DMI_IPMI_SLAVEADDR];
memcpy(&base_addr, data + DMI_IPMI_ADDR, sizeof(unsigned long));
if (len >= DMI_IPMI_VER2_LENGTH) {
if (type == IPMI_DMI_TYPE_SSIF) {
offset = 0;
flags = 0;
base_addr = data[DMI_IPMI_ADDR] >> 1;
if (base_addr == 0) {
base_addr = data[DMI_IPMI_SLAVEADDR] >> 1;
slave_addr = 0;
}
} else {
if (base_addr & 1) {
base_addr &= DMI_IPMI_IO_MASK;
} else {
flags = IORESOURCE_MEM;
}
base_addr |= (data[DMI_IPMI_ACCESS] >> 4) & 1;
irq = data[DMI_IPMI_IRQ];
switch ((data[DMI_IPMI_ACCESS] >> 6) & 3) {
case 0:
offset = 1;
break;
case 1:
offset = 4;
break;
case 2:
offset = 16;
break;
default:
pr_err("ipmi:dmi: Invalid offset: 0");
return;
}
}
} else {
base_addr = base_addr & DMI_IPMI_IO_MASK;
offset = 1;
}
dmi_add_platform_ipmi(base_addr, flags, slave_addr, irq,
offset, type);
}
static int __init scan_for_dmi_ipmi(void)
{
const struct dmi_device *dev = NULL;
while ((dev = dmi_find_device(DMI_DEV_TYPE_IPMI, NULL, dev)))
dmi_decode_ipmi((const struct dmi_header *) dev->device_data);
return 0;
}
