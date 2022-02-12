bool efi_capsule_pending(int *reset_type)
{
if (!capsule_pending)
return false;
if (reset_type)
*reset_type = efi_reset_type;
return true;
}
int efi_capsule_supported(efi_guid_t guid, u32 flags, size_t size, int *reset)
{
efi_capsule_header_t capsule;
efi_capsule_header_t *cap_list[] = { &capsule };
efi_status_t status;
u64 max_size;
if (flags & ~EFI_CAPSULE_SUPPORTED_FLAG_MASK)
return -EINVAL;
capsule.headersize = capsule.imagesize = sizeof(capsule);
memcpy(&capsule.guid, &guid, sizeof(efi_guid_t));
capsule.flags = flags;
status = efi.query_capsule_caps(cap_list, 1, &max_size, reset);
if (status != EFI_SUCCESS)
return efi_status_to_err(status);
if (size > max_size)
return -ENOSPC;
return 0;
}
static inline unsigned int sg_pages_num(unsigned int count)
{
return DIV_ROUND_UP(count, SGLIST_PER_PAGE);
}
static int
efi_capsule_update_locked(efi_capsule_header_t *capsule,
struct page **sg_pages, int reset)
{
efi_physical_addr_t sglist_phys;
efi_status_t status;
lockdep_assert_held(&capsule_mutex);
if (efi_reset_type >= 0 && efi_reset_type != reset) {
pr_err("Conflicting capsule reset type %d (%d).\n",
reset, efi_reset_type);
return -EINVAL;
}
if (unlikely(stop_capsules)) {
pr_warn("Capsule update raced with reboot, aborting.\n");
return -EINVAL;
}
sglist_phys = page_to_phys(sg_pages[0]);
status = efi.update_capsule(&capsule, 1, sglist_phys);
if (status == EFI_SUCCESS) {
capsule_pending = true;
efi_reset_type = reset;
}
return efi_status_to_err(status);
}
int efi_capsule_update(efi_capsule_header_t *capsule, phys_addr_t *pages)
{
u32 imagesize = capsule->imagesize;
efi_guid_t guid = capsule->guid;
unsigned int count, sg_count;
u32 flags = capsule->flags;
struct page **sg_pages;
int rv, reset_type;
int i, j;
rv = efi_capsule_supported(guid, flags, imagesize, &reset_type);
if (rv)
return rv;
count = DIV_ROUND_UP(imagesize, PAGE_SIZE);
sg_count = sg_pages_num(count);
sg_pages = kzalloc(sg_count * sizeof(*sg_pages), GFP_KERNEL);
if (!sg_pages)
return -ENOMEM;
for (i = 0; i < sg_count; i++) {
sg_pages[i] = alloc_page(GFP_KERNEL);
if (!sg_pages[i]) {
rv = -ENOMEM;
goto out;
}
}
for (i = 0; i < sg_count; i++) {
efi_capsule_block_desc_t *sglist;
sglist = kmap(sg_pages[i]);
for (j = 0; j < SGLIST_PER_PAGE && count > 0; j++) {
u64 sz = min_t(u64, imagesize,
PAGE_SIZE - (u64)*pages % PAGE_SIZE);
sglist[j].length = sz;
sglist[j].data = *pages++;
imagesize -= sz;
count--;
}
sglist[j].length = 0;
if (i + 1 == sg_count)
sglist[j].data = 0;
else
sglist[j].data = page_to_phys(sg_pages[i + 1]);
kunmap(sg_pages[i]);
}
mutex_lock(&capsule_mutex);
rv = efi_capsule_update_locked(capsule, sg_pages, reset_type);
mutex_unlock(&capsule_mutex);
out:
for (i = 0; rv && i < sg_count; i++) {
if (sg_pages[i])
__free_page(sg_pages[i]);
}
kfree(sg_pages);
return rv;
}
static int capsule_reboot_notify(struct notifier_block *nb, unsigned long event, void *cmd)
{
mutex_lock(&capsule_mutex);
stop_capsules = true;
mutex_unlock(&capsule_mutex);
return NOTIFY_DONE;
}
static int __init capsule_reboot_register(void)
{
return register_reboot_notifier(&capsule_reboot_nb);
}
