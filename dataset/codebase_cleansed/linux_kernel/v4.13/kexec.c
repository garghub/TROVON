static int copy_user_segment_list(struct kimage *image,
unsigned long nr_segments,
struct kexec_segment __user *segments)
{
int ret;
size_t segment_bytes;
image->nr_segments = nr_segments;
segment_bytes = nr_segments * sizeof(*segments);
ret = copy_from_user(image->segment, segments, segment_bytes);
if (ret)
ret = -EFAULT;
return ret;
}
static int kimage_alloc_init(struct kimage **rimage, unsigned long entry,
unsigned long nr_segments,
struct kexec_segment __user *segments,
unsigned long flags)
{
int ret;
struct kimage *image;
bool kexec_on_panic = flags & KEXEC_ON_CRASH;
if (kexec_on_panic) {
if ((entry < phys_to_boot_phys(crashk_res.start)) ||
(entry > phys_to_boot_phys(crashk_res.end)))
return -EADDRNOTAVAIL;
}
image = do_kimage_alloc_init();
if (!image)
return -ENOMEM;
image->start = entry;
ret = copy_user_segment_list(image, nr_segments, segments);
if (ret)
goto out_free_image;
if (kexec_on_panic) {
image->control_page = crashk_res.start;
image->type = KEXEC_TYPE_CRASH;
}
ret = sanity_check_segment_list(image);
if (ret)
goto out_free_image;
ret = -ENOMEM;
image->control_code_page = kimage_alloc_control_pages(image,
get_order(KEXEC_CONTROL_PAGE_SIZE));
if (!image->control_code_page) {
pr_err("Could not allocate control_code_buffer\n");
goto out_free_image;
}
if (!kexec_on_panic) {
image->swap_page = kimage_alloc_control_pages(image, 0);
if (!image->swap_page) {
pr_err("Could not allocate swap buffer\n");
goto out_free_control_pages;
}
}
*rimage = image;
return 0;
out_free_control_pages:
kimage_free_page_list(&image->control_pages);
out_free_image:
kfree(image);
return ret;
}
static int do_kexec_load(unsigned long entry, unsigned long nr_segments,
struct kexec_segment __user *segments, unsigned long flags)
{
struct kimage **dest_image, *image;
unsigned long i;
int ret;
if (flags & KEXEC_ON_CRASH) {
dest_image = &kexec_crash_image;
if (kexec_crash_image)
arch_kexec_unprotect_crashkres();
} else {
dest_image = &kexec_image;
}
if (nr_segments == 0) {
kimage_free(xchg(dest_image, NULL));
return 0;
}
if (flags & KEXEC_ON_CRASH) {
kimage_free(xchg(&kexec_crash_image, NULL));
}
ret = kimage_alloc_init(&image, entry, nr_segments, segments, flags);
if (ret)
return ret;
if (flags & KEXEC_PRESERVE_CONTEXT)
image->preserve_context = 1;
ret = machine_kexec_prepare(image);
if (ret)
goto out;
ret = kimage_crash_copy_vmcoreinfo(image);
if (ret)
goto out;
for (i = 0; i < nr_segments; i++) {
ret = kimage_load_segment(image, &image->segment[i]);
if (ret)
goto out;
}
kimage_terminate(image);
image = xchg(dest_image, image);
out:
if ((flags & KEXEC_ON_CRASH) && kexec_crash_image)
arch_kexec_protect_crashkres();
kimage_free(image);
return ret;
}
