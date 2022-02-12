static void efi_free_all_buff_pages(struct capsule_info *cap_info)
{
while (cap_info->index > 0)
__free_page(phys_to_page(cap_info->pages[--cap_info->index]));
cap_info->index = NO_FURTHER_WRITE_ACTION;
}
int __efi_capsule_setup_info(struct capsule_info *cap_info)
{
size_t pages_needed;
int ret;
void *temp_page;
pages_needed = ALIGN(cap_info->total_size, PAGE_SIZE) / PAGE_SIZE;
if (pages_needed == 0) {
pr_err("invalid capsule size");
return -EINVAL;
}
ret = efi_capsule_supported(cap_info->header.guid,
cap_info->header.flags,
cap_info->header.imagesize,
&cap_info->reset_type);
if (ret) {
pr_err("capsule not supported\n");
return ret;
}
temp_page = krealloc(cap_info->pages,
pages_needed * sizeof(void *),
GFP_KERNEL | __GFP_ZERO);
if (!temp_page)
return -ENOMEM;
cap_info->pages = temp_page;
return 0;
}
int __weak efi_capsule_setup_info(struct capsule_info *cap_info, void *kbuff,
size_t hdr_bytes)
{
if (hdr_bytes < sizeof(efi_capsule_header_t))
return 0;
memcpy(&cap_info->header, kbuff, sizeof(cap_info->header));
cap_info->total_size = cap_info->header.imagesize;
return __efi_capsule_setup_info(cap_info);
}
static ssize_t efi_capsule_submit_update(struct capsule_info *cap_info)
{
int ret;
ret = efi_capsule_update(&cap_info->header, cap_info->pages);
if (ret) {
pr_err("capsule update failed\n");
return ret;
}
cap_info->index = NO_FURTHER_WRITE_ACTION;
pr_info("Successfully upload capsule file with reboot type '%s'\n",
!cap_info->reset_type ? "RESET_COLD" :
cap_info->reset_type == 1 ? "RESET_WARM" :
"RESET_SHUTDOWN");
return 0;
}
static ssize_t efi_capsule_write(struct file *file, const char __user *buff,
size_t count, loff_t *offp)
{
int ret = 0;
struct capsule_info *cap_info = file->private_data;
struct page *page;
void *kbuff = NULL;
size_t write_byte;
if (count == 0)
return 0;
if (cap_info->index < 0)
return -EIO;
if (!cap_info->page_bytes_remain) {
page = alloc_page(GFP_KERNEL);
if (!page) {
ret = -ENOMEM;
goto failed;
}
cap_info->pages[cap_info->index++] = page_to_phys(page);
cap_info->page_bytes_remain = PAGE_SIZE;
} else {
page = phys_to_page(cap_info->pages[cap_info->index - 1]);
}
kbuff = kmap(page);
kbuff += PAGE_SIZE - cap_info->page_bytes_remain;
write_byte = min_t(size_t, count, cap_info->page_bytes_remain);
if (copy_from_user(kbuff, buff, write_byte)) {
ret = -EFAULT;
goto fail_unmap;
}
cap_info->page_bytes_remain -= write_byte;
if (cap_info->header.headersize == 0) {
ret = efi_capsule_setup_info(cap_info, kbuff - cap_info->count,
cap_info->count + write_byte);
if (ret)
goto fail_unmap;
}
cap_info->count += write_byte;
kunmap(page);
if (cap_info->header.headersize > 0 &&
cap_info->count >= cap_info->total_size) {
if (cap_info->count > cap_info->total_size) {
pr_err("capsule upload size exceeded header defined size\n");
ret = -EINVAL;
goto failed;
}
ret = efi_capsule_submit_update(cap_info);
if (ret)
goto failed;
}
return write_byte;
fail_unmap:
kunmap(page);
failed:
efi_free_all_buff_pages(cap_info);
return ret;
}
static int efi_capsule_flush(struct file *file, fl_owner_t id)
{
int ret = 0;
struct capsule_info *cap_info = file->private_data;
if (cap_info->index > 0) {
pr_err("capsule upload not complete\n");
efi_free_all_buff_pages(cap_info);
ret = -ECANCELED;
}
return ret;
}
static int efi_capsule_release(struct inode *inode, struct file *file)
{
struct capsule_info *cap_info = file->private_data;
kfree(cap_info->pages);
kfree(file->private_data);
file->private_data = NULL;
return 0;
}
static int efi_capsule_open(struct inode *inode, struct file *file)
{
struct capsule_info *cap_info;
cap_info = kzalloc(sizeof(*cap_info), GFP_KERNEL);
if (!cap_info)
return -ENOMEM;
cap_info->pages = kzalloc(sizeof(void *), GFP_KERNEL);
if (!cap_info->pages) {
kfree(cap_info);
return -ENOMEM;
}
file->private_data = cap_info;
return 0;
}
static int __init efi_capsule_loader_init(void)
{
int ret;
if (!efi_enabled(EFI_RUNTIME_SERVICES))
return -ENODEV;
ret = misc_register(&efi_capsule_misc);
if (ret)
pr_err("Unable to register capsule loader device\n");
return ret;
}
static void __exit efi_capsule_loader_exit(void)
{
misc_deregister(&efi_capsule_misc);
}
