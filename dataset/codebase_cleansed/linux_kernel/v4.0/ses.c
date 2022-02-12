static int ses_probe(struct device *dev)
{
struct scsi_device *sdev = to_scsi_device(dev);
int err = -ENODEV;
if (sdev->type != TYPE_ENCLOSURE)
goto out;
err = 0;
sdev_printk(KERN_NOTICE, sdev, "Attached Enclosure device\n");
out:
return err;
}
static void init_device_slot_control(unsigned char *dest_desc,
struct enclosure_component *ecomp,
unsigned char *status)
{
memcpy(dest_desc, status, 4);
dest_desc[0] = 0;
if (ecomp->type == ENCLOSURE_COMPONENT_DEVICE)
dest_desc[1] = 0;
dest_desc[2] &= 0xde;
dest_desc[3] &= 0x3c;
}
static int ses_recv_diag(struct scsi_device *sdev, int page_code,
void *buf, int bufflen)
{
unsigned char cmd[] = {
RECEIVE_DIAGNOSTIC,
1,
page_code,
bufflen >> 8,
bufflen & 0xff,
0
};
return scsi_execute_req(sdev, cmd, DMA_FROM_DEVICE, buf, bufflen,
NULL, SES_TIMEOUT, SES_RETRIES, NULL);
}
static int ses_send_diag(struct scsi_device *sdev, int page_code,
void *buf, int bufflen)
{
u32 result;
unsigned char cmd[] = {
SEND_DIAGNOSTIC,
0x10,
0,
bufflen >> 8,
bufflen & 0xff,
0
};
result = scsi_execute_req(sdev, cmd, DMA_TO_DEVICE, buf, bufflen,
NULL, SES_TIMEOUT, SES_RETRIES, NULL);
if (result)
sdev_printk(KERN_ERR, sdev, "SEND DIAGNOSTIC result: %8x\n",
result);
return result;
}
static int ses_set_page2_descriptor(struct enclosure_device *edev,
struct enclosure_component *ecomp,
unsigned char *desc)
{
int i, j, count = 0, descriptor = ecomp->number;
struct scsi_device *sdev = to_scsi_device(edev->edev.parent);
struct ses_device *ses_dev = edev->scratch;
unsigned char *type_ptr = ses_dev->page1_types;
unsigned char *desc_ptr = ses_dev->page2 + 8;
memset(desc_ptr, 0, ses_dev->page2_len - 8);
for (i = 0; i < ses_dev->page1_num_types; i++, type_ptr += 4) {
for (j = 0; j < type_ptr[1]; j++) {
desc_ptr += 4;
if (type_ptr[0] != ENCLOSURE_COMPONENT_DEVICE &&
type_ptr[0] != ENCLOSURE_COMPONENT_ARRAY_DEVICE)
continue;
if (count++ == descriptor) {
memcpy(desc_ptr, desc, 4);
desc_ptr[0] |= 0x80;
desc_ptr[0] &= 0xf0;
}
}
}
return ses_send_diag(sdev, 2, ses_dev->page2, ses_dev->page2_len);
}
static unsigned char *ses_get_page2_descriptor(struct enclosure_device *edev,
struct enclosure_component *ecomp)
{
int i, j, count = 0, descriptor = ecomp->number;
struct scsi_device *sdev = to_scsi_device(edev->edev.parent);
struct ses_device *ses_dev = edev->scratch;
unsigned char *type_ptr = ses_dev->page1_types;
unsigned char *desc_ptr = ses_dev->page2 + 8;
ses_recv_diag(sdev, 2, ses_dev->page2, ses_dev->page2_len);
for (i = 0; i < ses_dev->page1_num_types; i++, type_ptr += 4) {
for (j = 0; j < type_ptr[1]; j++) {
desc_ptr += 4;
if (type_ptr[0] != ENCLOSURE_COMPONENT_DEVICE &&
type_ptr[0] != ENCLOSURE_COMPONENT_ARRAY_DEVICE)
continue;
if (count++ == descriptor)
return desc_ptr;
}
}
return NULL;
}
static void ses_get_fault(struct enclosure_device *edev,
struct enclosure_component *ecomp)
{
unsigned char *desc;
desc = ses_get_page2_descriptor(edev, ecomp);
if (desc)
ecomp->fault = (desc[3] & 0x60) >> 4;
}
static int ses_set_fault(struct enclosure_device *edev,
struct enclosure_component *ecomp,
enum enclosure_component_setting val)
{
unsigned char desc[4];
unsigned char *desc_ptr;
desc_ptr = ses_get_page2_descriptor(edev, ecomp);
if (!desc_ptr)
return -EIO;
init_device_slot_control(desc, ecomp, desc_ptr);
switch (val) {
case ENCLOSURE_SETTING_DISABLED:
desc[3] &= 0xdf;
break;
case ENCLOSURE_SETTING_ENABLED:
desc[3] |= 0x20;
break;
default:
return -EINVAL;
}
return ses_set_page2_descriptor(edev, ecomp, desc);
}
static void ses_get_status(struct enclosure_device *edev,
struct enclosure_component *ecomp)
{
unsigned char *desc;
desc = ses_get_page2_descriptor(edev, ecomp);
if (desc)
ecomp->status = (desc[0] & 0x0f);
}
static void ses_get_locate(struct enclosure_device *edev,
struct enclosure_component *ecomp)
{
unsigned char *desc;
desc = ses_get_page2_descriptor(edev, ecomp);
if (desc)
ecomp->locate = (desc[2] & 0x02) ? 1 : 0;
}
static int ses_set_locate(struct enclosure_device *edev,
struct enclosure_component *ecomp,
enum enclosure_component_setting val)
{
unsigned char desc[4];
unsigned char *desc_ptr;
desc_ptr = ses_get_page2_descriptor(edev, ecomp);
if (!desc_ptr)
return -EIO;
init_device_slot_control(desc, ecomp, desc_ptr);
switch (val) {
case ENCLOSURE_SETTING_DISABLED:
desc[2] &= 0xfd;
break;
case ENCLOSURE_SETTING_ENABLED:
desc[2] |= 0x02;
break;
default:
return -EINVAL;
}
return ses_set_page2_descriptor(edev, ecomp, desc);
}
static int ses_set_active(struct enclosure_device *edev,
struct enclosure_component *ecomp,
enum enclosure_component_setting val)
{
unsigned char desc[4];
unsigned char *desc_ptr;
desc_ptr = ses_get_page2_descriptor(edev, ecomp);
if (!desc_ptr)
return -EIO;
init_device_slot_control(desc, ecomp, desc_ptr);
switch (val) {
case ENCLOSURE_SETTING_DISABLED:
desc[2] &= 0x7f;
ecomp->active = 0;
break;
case ENCLOSURE_SETTING_ENABLED:
desc[2] |= 0x80;
ecomp->active = 1;
break;
default:
return -EINVAL;
}
return ses_set_page2_descriptor(edev, ecomp, desc);
}
static int ses_show_id(struct enclosure_device *edev, char *buf)
{
struct ses_device *ses_dev = edev->scratch;
unsigned long long id = get_unaligned_be64(ses_dev->page1+8+4);
return sprintf(buf, "%#llx\n", id);
}
static void ses_get_power_status(struct enclosure_device *edev,
struct enclosure_component *ecomp)
{
unsigned char *desc;
desc = ses_get_page2_descriptor(edev, ecomp);
if (desc)
ecomp->power_status = (desc[3] & 0x10) ? 0 : 1;
}
static int ses_set_power_status(struct enclosure_device *edev,
struct enclosure_component *ecomp,
int val)
{
unsigned char desc[4];
unsigned char *desc_ptr;
desc_ptr = ses_get_page2_descriptor(edev, ecomp);
if (!desc_ptr)
return -EIO;
init_device_slot_control(desc, ecomp, desc_ptr);
switch (val) {
case 0:
desc[3] |= 0x10;
break;
case 1:
desc[3] &= 0xef;
break;
default:
return -EINVAL;
}
ecomp->power_status = val;
return ses_set_page2_descriptor(edev, ecomp, desc);
}
static void ses_process_descriptor(struct enclosure_component *ecomp,
unsigned char *desc)
{
int eip = desc[0] & 0x10;
int invalid = desc[0] & 0x80;
enum scsi_protocol proto = desc[0] & 0x0f;
u64 addr = 0;
int slot = -1;
struct ses_component *scomp = ecomp->scratch;
unsigned char *d;
if (invalid)
return;
switch (proto) {
case SCSI_PROTOCOL_FCP:
if (eip) {
d = desc + 4;
slot = d[3];
}
break;
case SCSI_PROTOCOL_SAS:
if (eip) {
d = desc + 4;
slot = d[3];
d = desc + 8;
} else
d = desc + 4;
addr = (u64)d[12] << 56 |
(u64)d[13] << 48 |
(u64)d[14] << 40 |
(u64)d[15] << 32 |
(u64)d[16] << 24 |
(u64)d[17] << 16 |
(u64)d[18] << 8 |
(u64)d[19];
break;
default:
break;
}
ecomp->slot = slot;
scomp->addr = addr;
}
static int ses_enclosure_find_by_addr(struct enclosure_device *edev,
void *data)
{
struct efd *efd = data;
int i;
struct ses_component *scomp;
if (!edev->component[0].scratch)
return 0;
for (i = 0; i < edev->components; i++) {
scomp = edev->component[i].scratch;
if (scomp->addr != efd->addr)
continue;
if (enclosure_add_device(edev, i, efd->dev) == 0)
kobject_uevent(&efd->dev->kobj, KOBJ_CHANGE);
return 1;
}
return 0;
}
static void ses_enclosure_data_process(struct enclosure_device *edev,
struct scsi_device *sdev,
int create)
{
u32 result;
unsigned char *buf = NULL, *type_ptr, *desc_ptr, *addl_desc_ptr = NULL;
int i, j, page7_len, len, components;
struct ses_device *ses_dev = edev->scratch;
int types = ses_dev->page1_num_types;
unsigned char *hdr_buf = kzalloc(INIT_ALLOC_SIZE, GFP_KERNEL);
if (!hdr_buf)
goto simple_populate;
if (ses_dev->page10)
ses_recv_diag(sdev, 10, ses_dev->page10, ses_dev->page10_len);
result = ses_recv_diag(sdev, 7, hdr_buf, INIT_ALLOC_SIZE);
if (result)
goto simple_populate;
page7_len = len = (hdr_buf[2] << 8) + hdr_buf[3] + 4;
buf = kzalloc(len + 1, GFP_KERNEL);
if (!buf)
goto simple_populate;
result = ses_recv_diag(sdev, 7, buf, len);
if (result) {
simple_populate:
kfree(buf);
buf = NULL;
desc_ptr = NULL;
len = 0;
page7_len = 0;
} else {
desc_ptr = buf + 8;
len = (desc_ptr[2] << 8) + desc_ptr[3];
desc_ptr += len + 4;
}
if (ses_dev->page10)
addl_desc_ptr = ses_dev->page10 + 8;
type_ptr = ses_dev->page1_types;
components = 0;
for (i = 0; i < types; i++, type_ptr += 4) {
for (j = 0; j < type_ptr[1]; j++) {
char *name = NULL;
struct enclosure_component *ecomp;
if (desc_ptr) {
if (desc_ptr >= buf + page7_len) {
desc_ptr = NULL;
} else {
len = (desc_ptr[2] << 8) + desc_ptr[3];
desc_ptr += 4;
desc_ptr[len] = '\0';
name = desc_ptr;
}
}
if (type_ptr[0] == ENCLOSURE_COMPONENT_DEVICE ||
type_ptr[0] == ENCLOSURE_COMPONENT_ARRAY_DEVICE) {
if (create)
ecomp = enclosure_component_alloc(
edev,
components++,
type_ptr[0],
name);
else
ecomp = &edev->component[components++];
if (!IS_ERR(ecomp)) {
ses_get_power_status(edev, ecomp);
if (addl_desc_ptr)
ses_process_descriptor(
ecomp,
addl_desc_ptr);
if (create)
enclosure_component_register(
ecomp);
}
}
if (desc_ptr)
desc_ptr += len;
if (addl_desc_ptr)
addl_desc_ptr += addl_desc_ptr[1] + 2;
}
}
kfree(buf);
kfree(hdr_buf);
}
static void ses_match_to_enclosure(struct enclosure_device *edev,
struct scsi_device *sdev)
{
unsigned char *desc;
struct efd efd = {
.addr = 0,
};
ses_enclosure_data_process(edev, to_scsi_device(edev->edev.parent), 0);
if (!sdev->vpd_pg83_len)
return;
desc = sdev->vpd_pg83 + 4;
while (desc < sdev->vpd_pg83 + sdev->vpd_pg83_len) {
enum scsi_protocol proto = desc[0] >> 4;
u8 code_set = desc[0] & 0x0f;
u8 piv = desc[1] & 0x80;
u8 assoc = (desc[1] & 0x30) >> 4;
u8 type = desc[1] & 0x0f;
u8 len = desc[3];
if (piv && code_set == 1 && assoc == 1
&& proto == SCSI_PROTOCOL_SAS && type == 3 && len == 8)
efd.addr = get_unaligned_be64(&desc[4]);
desc += len + 4;
}
if (efd.addr) {
efd.dev = &sdev->sdev_gendev;
enclosure_for_each_device(ses_enclosure_find_by_addr, &efd);
}
}
static int ses_intf_add(struct device *cdev,
struct class_interface *intf)
{
struct scsi_device *sdev = to_scsi_device(cdev->parent);
struct scsi_device *tmp_sdev;
unsigned char *buf = NULL, *hdr_buf, *type_ptr;
struct ses_device *ses_dev;
u32 result;
int i, types, len, components = 0;
int err = -ENOMEM;
int num_enclosures;
struct enclosure_device *edev;
struct ses_component *scomp = NULL;
if (!scsi_device_enclosure(sdev)) {
struct enclosure_device *prev = NULL;
while ((edev = enclosure_find(&sdev->host->shost_gendev, prev)) != NULL) {
ses_match_to_enclosure(edev, sdev);
prev = edev;
}
return -ENODEV;
}
if (sdev->type != TYPE_ENCLOSURE)
sdev_printk(KERN_NOTICE, sdev, "Embedded Enclosure Device\n");
ses_dev = kzalloc(sizeof(*ses_dev), GFP_KERNEL);
hdr_buf = kzalloc(INIT_ALLOC_SIZE, GFP_KERNEL);
if (!hdr_buf || !ses_dev)
goto err_init_free;
result = ses_recv_diag(sdev, 1, hdr_buf, INIT_ALLOC_SIZE);
if (result)
goto recv_failed;
len = (hdr_buf[2] << 8) + hdr_buf[3] + 4;
buf = kzalloc(len, GFP_KERNEL);
if (!buf)
goto err_free;
result = ses_recv_diag(sdev, 1, buf, len);
if (result)
goto recv_failed;
types = 0;
num_enclosures = buf[1] + 1;
type_ptr = buf + 8;
for (i = 0; i < num_enclosures && type_ptr < buf + len; i++) {
types += type_ptr[2];
type_ptr += type_ptr[3] + 4;
}
ses_dev->page1_types = type_ptr;
ses_dev->page1_num_types = types;
for (i = 0; i < types && type_ptr < buf + len; i++, type_ptr += 4) {
if (type_ptr[0] == ENCLOSURE_COMPONENT_DEVICE ||
type_ptr[0] == ENCLOSURE_COMPONENT_ARRAY_DEVICE)
components += type_ptr[1];
}
ses_dev->page1 = buf;
ses_dev->page1_len = len;
buf = NULL;
result = ses_recv_diag(sdev, 2, hdr_buf, INIT_ALLOC_SIZE);
if (result)
goto recv_failed;
len = (hdr_buf[2] << 8) + hdr_buf[3] + 4;
buf = kzalloc(len, GFP_KERNEL);
if (!buf)
goto err_free;
result = ses_recv_diag(sdev, 2, buf, len);
if (result)
goto recv_failed;
ses_dev->page2 = buf;
ses_dev->page2_len = len;
buf = NULL;
result = ses_recv_diag(sdev, 10, hdr_buf, INIT_ALLOC_SIZE);
if (!result) {
len = (hdr_buf[2] << 8) + hdr_buf[3] + 4;
buf = kzalloc(len, GFP_KERNEL);
if (!buf)
goto err_free;
result = ses_recv_diag(sdev, 10, buf, len);
if (result)
goto recv_failed;
ses_dev->page10 = buf;
ses_dev->page10_len = len;
buf = NULL;
}
scomp = kzalloc(sizeof(struct ses_component) * components, GFP_KERNEL);
if (!scomp)
goto err_free;
edev = enclosure_register(cdev->parent, dev_name(&sdev->sdev_gendev),
components, &ses_enclosure_callbacks);
if (IS_ERR(edev)) {
err = PTR_ERR(edev);
goto err_free;
}
kfree(hdr_buf);
edev->scratch = ses_dev;
for (i = 0; i < components; i++)
edev->component[i].scratch = scomp + i;
ses_enclosure_data_process(edev, sdev, 1);
shost_for_each_device(tmp_sdev, sdev->host) {
if (tmp_sdev->lun != 0 || scsi_device_enclosure(tmp_sdev))
continue;
ses_match_to_enclosure(edev, tmp_sdev);
}
return 0;
recv_failed:
sdev_printk(KERN_ERR, sdev, "Failed to get diagnostic page 0x%x\n",
result);
err = -ENODEV;
err_free:
kfree(buf);
kfree(scomp);
kfree(ses_dev->page10);
kfree(ses_dev->page2);
kfree(ses_dev->page1);
err_init_free:
kfree(ses_dev);
kfree(hdr_buf);
sdev_printk(KERN_ERR, sdev, "Failed to bind enclosure %d\n", err);
return err;
}
static int ses_remove(struct device *dev)
{
return 0;
}
static void ses_intf_remove_component(struct scsi_device *sdev)
{
struct enclosure_device *edev, *prev = NULL;
while ((edev = enclosure_find(&sdev->host->shost_gendev, prev)) != NULL) {
prev = edev;
if (!enclosure_remove_device(edev, &sdev->sdev_gendev))
break;
}
if (edev)
put_device(&edev->edev);
}
static void ses_intf_remove_enclosure(struct scsi_device *sdev)
{
struct enclosure_device *edev;
struct ses_device *ses_dev;
edev = enclosure_find(&sdev->sdev_gendev, NULL);
if (!edev)
return;
ses_dev = edev->scratch;
edev->scratch = NULL;
kfree(ses_dev->page10);
kfree(ses_dev->page1);
kfree(ses_dev->page2);
kfree(ses_dev);
kfree(edev->component[0].scratch);
put_device(&edev->edev);
enclosure_unregister(edev);
}
static void ses_intf_remove(struct device *cdev,
struct class_interface *intf)
{
struct scsi_device *sdev = to_scsi_device(cdev->parent);
if (!scsi_device_enclosure(sdev))
ses_intf_remove_component(sdev);
else
ses_intf_remove_enclosure(sdev);
}
static int __init ses_init(void)
{
int err;
err = scsi_register_interface(&ses_interface);
if (err)
return err;
err = scsi_register_driver(&ses_template.gendrv);
if (err)
goto out_unreg;
return 0;
out_unreg:
scsi_unregister_interface(&ses_interface);
return err;
}
static void __exit ses_exit(void)
{
scsi_unregister_driver(&ses_template.gendrv);
scsi_unregister_interface(&ses_interface);
}
