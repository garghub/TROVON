static struct hid_blacklist *usbhid_exists_dquirk(const u16 idVendor,
const u16 idProduct)
{
struct quirks_list_struct *q;
struct hid_blacklist *bl_entry = NULL;
list_for_each_entry(q, &dquirks_list, node) {
if (q->hid_bl_item.idVendor == idVendor &&
q->hid_bl_item.idProduct == idProduct) {
bl_entry = &q->hid_bl_item;
break;
}
}
if (bl_entry != NULL)
dbg_hid("Found dynamic quirk 0x%x for USB HID vendor 0x%hx prod 0x%hx\n",
bl_entry->quirks, bl_entry->idVendor,
bl_entry->idProduct);
return bl_entry;
}
static int usbhid_modify_dquirk(const u16 idVendor, const u16 idProduct,
const u32 quirks)
{
struct quirks_list_struct *q_new, *q;
int list_edited = 0;
if (!idVendor) {
dbg_hid("Cannot add a quirk with idVendor = 0\n");
return -EINVAL;
}
q_new = kmalloc(sizeof(struct quirks_list_struct), GFP_KERNEL);
if (!q_new) {
dbg_hid("Could not allocate quirks_list_struct\n");
return -ENOMEM;
}
q_new->hid_bl_item.idVendor = idVendor;
q_new->hid_bl_item.idProduct = idProduct;
q_new->hid_bl_item.quirks = quirks;
down_write(&dquirks_rwsem);
list_for_each_entry(q, &dquirks_list, node) {
if (q->hid_bl_item.idVendor == idVendor &&
q->hid_bl_item.idProduct == idProduct) {
list_replace(&q->node, &q_new->node);
kfree(q);
list_edited = 1;
break;
}
}
if (!list_edited)
list_add_tail(&q_new->node, &dquirks_list);
up_write(&dquirks_rwsem);
return 0;
}
static void usbhid_remove_all_dquirks(void)
{
struct quirks_list_struct *q, *temp;
down_write(&dquirks_rwsem);
list_for_each_entry_safe(q, temp, &dquirks_list, node) {
list_del(&q->node);
kfree(q);
}
up_write(&dquirks_rwsem);
}
int usbhid_quirks_init(char **quirks_param)
{
u16 idVendor, idProduct;
u32 quirks;
int n = 0, m;
for (; n < MAX_USBHID_BOOT_QUIRKS && quirks_param[n]; n++) {
m = sscanf(quirks_param[n], "0x%hx:0x%hx:0x%x",
&idVendor, &idProduct, &quirks);
if (m != 3 ||
usbhid_modify_dquirk(idVendor, idProduct, quirks) != 0) {
printk(KERN_WARNING
"Could not parse HID quirk module param %s\n",
quirks_param[n]);
}
}
return 0;
}
void usbhid_quirks_exit(void)
{
usbhid_remove_all_dquirks();
}
static const struct hid_blacklist *usbhid_exists_squirk(const u16 idVendor,
const u16 idProduct)
{
const struct hid_blacklist *bl_entry = NULL;
int n = 0;
for (; hid_blacklist[n].idVendor; n++)
if (hid_blacklist[n].idVendor == idVendor &&
hid_blacklist[n].idProduct == idProduct)
bl_entry = &hid_blacklist[n];
if (bl_entry != NULL)
dbg_hid("Found squirk 0x%x for USB HID vendor 0x%hx prod 0x%hx\n",
bl_entry->quirks, bl_entry->idVendor,
bl_entry->idProduct);
return bl_entry;
}
u32 usbhid_lookup_quirk(const u16 idVendor, const u16 idProduct)
{
u32 quirks = 0;
const struct hid_blacklist *bl_entry = NULL;
if (idVendor == USB_VENDOR_ID_NCR &&
idProduct >= USB_DEVICE_ID_NCR_FIRST &&
idProduct <= USB_DEVICE_ID_NCR_LAST)
return HID_QUIRK_NO_INIT_REPORTS;
down_read(&dquirks_rwsem);
bl_entry = usbhid_exists_dquirk(idVendor, idProduct);
if (!bl_entry)
bl_entry = usbhid_exists_squirk(idVendor, idProduct);
if (bl_entry)
quirks = bl_entry->quirks;
up_read(&dquirks_rwsem);
return quirks;
}
