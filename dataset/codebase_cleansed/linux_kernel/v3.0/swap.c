static int swsusp_extents_insert(unsigned long swap_offset)
{
struct rb_node **new = &(swsusp_extents.rb_node);
struct rb_node *parent = NULL;
struct swsusp_extent *ext;
while (*new) {
ext = container_of(*new, struct swsusp_extent, node);
parent = *new;
if (swap_offset < ext->start) {
if (swap_offset == ext->start - 1) {
ext->start--;
return 0;
}
new = &((*new)->rb_left);
} else if (swap_offset > ext->end) {
if (swap_offset == ext->end + 1) {
ext->end++;
return 0;
}
new = &((*new)->rb_right);
} else {
return -EINVAL;
}
}
ext = kzalloc(sizeof(struct swsusp_extent), GFP_KERNEL);
if (!ext)
return -ENOMEM;
ext->start = swap_offset;
ext->end = swap_offset;
rb_link_node(&ext->node, parent, new);
rb_insert_color(&ext->node, &swsusp_extents);
return 0;
}
sector_t alloc_swapdev_block(int swap)
{
unsigned long offset;
offset = swp_offset(get_swap_page_of_type(swap));
if (offset) {
if (swsusp_extents_insert(offset))
swap_free(swp_entry(swap, offset));
else
return swapdev_block(swap, offset);
}
return 0;
}
void free_all_swap_pages(int swap)
{
struct rb_node *node;
while ((node = swsusp_extents.rb_node)) {
struct swsusp_extent *ext;
unsigned long offset;
ext = container_of(node, struct swsusp_extent, node);
rb_erase(node, &swsusp_extents);
for (offset = ext->start; offset <= ext->end; offset++)
swap_free(swp_entry(swap, offset));
kfree(ext);
}
}
int swsusp_swap_in_use(void)
{
return (swsusp_extents.rb_node != NULL);
}
static int mark_swapfiles(struct swap_map_handle *handle, unsigned int flags)
{
int error;
hib_bio_read_page(swsusp_resume_block, swsusp_header, NULL);
if (!memcmp("SWAP-SPACE",swsusp_header->sig, 10) ||
!memcmp("SWAPSPACE2",swsusp_header->sig, 10)) {
memcpy(swsusp_header->orig_sig,swsusp_header->sig, 10);
memcpy(swsusp_header->sig, HIBERNATE_SIG, 10);
swsusp_header->image = handle->first_sector;
swsusp_header->flags = flags;
error = hib_bio_write_page(swsusp_resume_block,
swsusp_header, NULL);
} else {
printk(KERN_ERR "PM: Swap header not found!\n");
error = -ENODEV;
}
return error;
}
static int swsusp_swap_check(void)
{
int res;
res = swap_type_of(swsusp_resume_device, swsusp_resume_block,
&hib_resume_bdev);
if (res < 0)
return res;
root_swap = res;
res = blkdev_get(hib_resume_bdev, FMODE_WRITE, NULL);
if (res)
return res;
res = set_blocksize(hib_resume_bdev, PAGE_SIZE);
if (res < 0)
blkdev_put(hib_resume_bdev, FMODE_WRITE);
return res;
}
static int write_page(void *buf, sector_t offset, struct bio **bio_chain)
{
void *src;
if (!offset)
return -ENOSPC;
if (bio_chain) {
src = (void *)__get_free_page(__GFP_WAIT | __GFP_HIGH);
if (src) {
copy_page(src, buf);
} else {
WARN_ON_ONCE(1);
bio_chain = NULL;
src = buf;
}
} else {
src = buf;
}
return hib_bio_write_page(offset, src, bio_chain);
}
static void release_swap_writer(struct swap_map_handle *handle)
{
if (handle->cur)
free_page((unsigned long)handle->cur);
handle->cur = NULL;
}
static int get_swap_writer(struct swap_map_handle *handle)
{
int ret;
ret = swsusp_swap_check();
if (ret) {
if (ret != -ENOSPC)
printk(KERN_ERR "PM: Cannot find swap device, try "
"swapon -a.\n");
return ret;
}
handle->cur = (struct swap_map_page *)get_zeroed_page(GFP_KERNEL);
if (!handle->cur) {
ret = -ENOMEM;
goto err_close;
}
handle->cur_swap = alloc_swapdev_block(root_swap);
if (!handle->cur_swap) {
ret = -ENOSPC;
goto err_rel;
}
handle->k = 0;
handle->first_sector = handle->cur_swap;
return 0;
err_rel:
release_swap_writer(handle);
err_close:
swsusp_close(FMODE_WRITE);
return ret;
}
static int swap_write_page(struct swap_map_handle *handle, void *buf,
struct bio **bio_chain)
{
int error = 0;
sector_t offset;
if (!handle->cur)
return -EINVAL;
offset = alloc_swapdev_block(root_swap);
error = write_page(buf, offset, bio_chain);
if (error)
return error;
handle->cur->entries[handle->k++] = offset;
if (handle->k >= MAP_PAGE_ENTRIES) {
error = hib_wait_on_bio_chain(bio_chain);
if (error)
goto out;
offset = alloc_swapdev_block(root_swap);
if (!offset)
return -ENOSPC;
handle->cur->next_swap = offset;
error = write_page(handle->cur, handle->cur_swap, NULL);
if (error)
goto out;
clear_page(handle->cur);
handle->cur_swap = offset;
handle->k = 0;
}
out:
return error;
}
static int flush_swap_writer(struct swap_map_handle *handle)
{
if (handle->cur && handle->cur_swap)
return write_page(handle->cur, handle->cur_swap, NULL);
else
return -EINVAL;
}
static int swap_writer_finish(struct swap_map_handle *handle,
unsigned int flags, int error)
{
if (!error) {
flush_swap_writer(handle);
printk(KERN_INFO "PM: S");
error = mark_swapfiles(handle, flags);
printk("|\n");
}
if (error)
free_all_swap_pages(root_swap);
release_swap_writer(handle);
swsusp_close(FMODE_WRITE);
return error;
}
static int save_image(struct swap_map_handle *handle,
struct snapshot_handle *snapshot,
unsigned int nr_to_write)
{
unsigned int m;
int ret;
int nr_pages;
int err2;
struct bio *bio;
struct timeval start;
struct timeval stop;
printk(KERN_INFO "PM: Saving image data pages (%u pages) ... ",
nr_to_write);
m = nr_to_write / 100;
if (!m)
m = 1;
nr_pages = 0;
bio = NULL;
do_gettimeofday(&start);
while (1) {
ret = snapshot_read_next(snapshot);
if (ret <= 0)
break;
ret = swap_write_page(handle, data_of(*snapshot), &bio);
if (ret)
break;
if (!(nr_pages % m))
printk(KERN_CONT "\b\b\b\b%3d%%", nr_pages / m);
nr_pages++;
}
err2 = hib_wait_on_bio_chain(&bio);
do_gettimeofday(&stop);
if (!ret)
ret = err2;
if (!ret)
printk(KERN_CONT "\b\b\b\bdone\n");
else
printk(KERN_CONT "\n");
swsusp_show_speed(&start, &stop, nr_to_write, "Wrote");
return ret;
}
static int save_image_lzo(struct swap_map_handle *handle,
struct snapshot_handle *snapshot,
unsigned int nr_to_write)
{
unsigned int m;
int ret = 0;
int nr_pages;
int err2;
struct bio *bio;
struct timeval start;
struct timeval stop;
size_t off, unc_len, cmp_len;
unsigned char *unc, *cmp, *wrk, *page;
page = (void *)__get_free_page(__GFP_WAIT | __GFP_HIGH);
if (!page) {
printk(KERN_ERR "PM: Failed to allocate LZO page\n");
return -ENOMEM;
}
wrk = vmalloc(LZO1X_1_MEM_COMPRESS);
if (!wrk) {
printk(KERN_ERR "PM: Failed to allocate LZO workspace\n");
free_page((unsigned long)page);
return -ENOMEM;
}
unc = vmalloc(LZO_UNC_SIZE);
if (!unc) {
printk(KERN_ERR "PM: Failed to allocate LZO uncompressed\n");
vfree(wrk);
free_page((unsigned long)page);
return -ENOMEM;
}
cmp = vmalloc(LZO_CMP_SIZE);
if (!cmp) {
printk(KERN_ERR "PM: Failed to allocate LZO compressed\n");
vfree(unc);
vfree(wrk);
free_page((unsigned long)page);
return -ENOMEM;
}
printk(KERN_INFO
"PM: Compressing and saving image data (%u pages) ... ",
nr_to_write);
m = nr_to_write / 100;
if (!m)
m = 1;
nr_pages = 0;
bio = NULL;
do_gettimeofday(&start);
for (;;) {
for (off = 0; off < LZO_UNC_SIZE; off += PAGE_SIZE) {
ret = snapshot_read_next(snapshot);
if (ret < 0)
goto out_finish;
if (!ret)
break;
memcpy(unc + off, data_of(*snapshot), PAGE_SIZE);
if (!(nr_pages % m))
printk(KERN_CONT "\b\b\b\b%3d%%", nr_pages / m);
nr_pages++;
}
if (!off)
break;
unc_len = off;
ret = lzo1x_1_compress(unc, unc_len,
cmp + LZO_HEADER, &cmp_len, wrk);
if (ret < 0) {
printk(KERN_ERR "PM: LZO compression failed\n");
break;
}
if (unlikely(!cmp_len ||
cmp_len > lzo1x_worst_compress(unc_len))) {
printk(KERN_ERR "PM: Invalid LZO compressed length\n");
ret = -1;
break;
}
*(size_t *)cmp = cmp_len;
for (off = 0; off < LZO_HEADER + cmp_len; off += PAGE_SIZE) {
memcpy(page, cmp + off, PAGE_SIZE);
ret = swap_write_page(handle, page, &bio);
if (ret)
goto out_finish;
}
}
out_finish:
err2 = hib_wait_on_bio_chain(&bio);
do_gettimeofday(&stop);
if (!ret)
ret = err2;
if (!ret)
printk(KERN_CONT "\b\b\b\bdone\n");
else
printk(KERN_CONT "\n");
swsusp_show_speed(&start, &stop, nr_to_write, "Wrote");
vfree(cmp);
vfree(unc);
vfree(wrk);
free_page((unsigned long)page);
return ret;
}
static int enough_swap(unsigned int nr_pages, unsigned int flags)
{
unsigned int free_swap = count_swap_pages(root_swap, 1);
unsigned int required;
pr_debug("PM: Free swap pages: %u\n", free_swap);
required = PAGES_FOR_IO + ((flags & SF_NOCOMPRESS_MODE) ?
nr_pages : (nr_pages * LZO_CMP_PAGES) / LZO_UNC_PAGES + 1);
return free_swap > required;
}
int swsusp_write(unsigned int flags)
{
struct swap_map_handle handle;
struct snapshot_handle snapshot;
struct swsusp_info *header;
unsigned long pages;
int error;
pages = snapshot_get_image_size();
error = get_swap_writer(&handle);
if (error) {
printk(KERN_ERR "PM: Cannot get swap writer\n");
return error;
}
if (!enough_swap(pages, flags)) {
printk(KERN_ERR "PM: Not enough free swap\n");
error = -ENOSPC;
goto out_finish;
}
memset(&snapshot, 0, sizeof(struct snapshot_handle));
error = snapshot_read_next(&snapshot);
if (error < PAGE_SIZE) {
if (error >= 0)
error = -EFAULT;
goto out_finish;
}
header = (struct swsusp_info *)data_of(snapshot);
error = swap_write_page(&handle, header, NULL);
if (!error) {
error = (flags & SF_NOCOMPRESS_MODE) ?
save_image(&handle, &snapshot, pages - 1) :
save_image_lzo(&handle, &snapshot, pages - 1);
}
out_finish:
error = swap_writer_finish(&handle, flags, error);
return error;
}
static void release_swap_reader(struct swap_map_handle *handle)
{
if (handle->cur)
free_page((unsigned long)handle->cur);
handle->cur = NULL;
}
static int get_swap_reader(struct swap_map_handle *handle,
unsigned int *flags_p)
{
int error;
*flags_p = swsusp_header->flags;
if (!swsusp_header->image)
return -EINVAL;
handle->cur = (struct swap_map_page *)get_zeroed_page(__GFP_WAIT | __GFP_HIGH);
if (!handle->cur)
return -ENOMEM;
error = hib_bio_read_page(swsusp_header->image, handle->cur, NULL);
if (error) {
release_swap_reader(handle);
return error;
}
handle->k = 0;
return 0;
}
static int swap_read_page(struct swap_map_handle *handle, void *buf,
struct bio **bio_chain)
{
sector_t offset;
int error;
if (!handle->cur)
return -EINVAL;
offset = handle->cur->entries[handle->k];
if (!offset)
return -EFAULT;
error = hib_bio_read_page(offset, buf, bio_chain);
if (error)
return error;
if (++handle->k >= MAP_PAGE_ENTRIES) {
error = hib_wait_on_bio_chain(bio_chain);
handle->k = 0;
offset = handle->cur->next_swap;
if (!offset)
release_swap_reader(handle);
else if (!error)
error = hib_bio_read_page(offset, handle->cur, NULL);
}
return error;
}
static int swap_reader_finish(struct swap_map_handle *handle)
{
release_swap_reader(handle);
return 0;
}
static int load_image(struct swap_map_handle *handle,
struct snapshot_handle *snapshot,
unsigned int nr_to_read)
{
unsigned int m;
int error = 0;
struct timeval start;
struct timeval stop;
struct bio *bio;
int err2;
unsigned nr_pages;
printk(KERN_INFO "PM: Loading image data pages (%u pages) ... ",
nr_to_read);
m = nr_to_read / 100;
if (!m)
m = 1;
nr_pages = 0;
bio = NULL;
do_gettimeofday(&start);
for ( ; ; ) {
error = snapshot_write_next(snapshot);
if (error <= 0)
break;
error = swap_read_page(handle, data_of(*snapshot), &bio);
if (error)
break;
if (snapshot->sync_read)
error = hib_wait_on_bio_chain(&bio);
if (error)
break;
if (!(nr_pages % m))
printk("\b\b\b\b%3d%%", nr_pages / m);
nr_pages++;
}
err2 = hib_wait_on_bio_chain(&bio);
do_gettimeofday(&stop);
if (!error)
error = err2;
if (!error) {
printk("\b\b\b\bdone\n");
snapshot_write_finalize(snapshot);
if (!snapshot_image_loaded(snapshot))
error = -ENODATA;
} else
printk("\n");
swsusp_show_speed(&start, &stop, nr_to_read, "Read");
return error;
}
static int load_image_lzo(struct swap_map_handle *handle,
struct snapshot_handle *snapshot,
unsigned int nr_to_read)
{
unsigned int m;
int error = 0;
struct bio *bio;
struct timeval start;
struct timeval stop;
unsigned nr_pages;
size_t i, off, unc_len, cmp_len;
unsigned char *unc, *cmp, *page[LZO_CMP_PAGES];
for (i = 0; i < LZO_CMP_PAGES; i++) {
page[i] = (void *)__get_free_page(__GFP_WAIT | __GFP_HIGH);
if (!page[i]) {
printk(KERN_ERR "PM: Failed to allocate LZO page\n");
while (i)
free_page((unsigned long)page[--i]);
return -ENOMEM;
}
}
unc = vmalloc(LZO_UNC_SIZE);
if (!unc) {
printk(KERN_ERR "PM: Failed to allocate LZO uncompressed\n");
for (i = 0; i < LZO_CMP_PAGES; i++)
free_page((unsigned long)page[i]);
return -ENOMEM;
}
cmp = vmalloc(LZO_CMP_SIZE);
if (!cmp) {
printk(KERN_ERR "PM: Failed to allocate LZO compressed\n");
vfree(unc);
for (i = 0; i < LZO_CMP_PAGES; i++)
free_page((unsigned long)page[i]);
return -ENOMEM;
}
printk(KERN_INFO
"PM: Loading and decompressing image data (%u pages) ... ",
nr_to_read);
m = nr_to_read / 100;
if (!m)
m = 1;
nr_pages = 0;
bio = NULL;
do_gettimeofday(&start);
error = snapshot_write_next(snapshot);
if (error <= 0)
goto out_finish;
for (;;) {
error = swap_read_page(handle, page[0], NULL);
if (error)
break;
cmp_len = *(size_t *)page[0];
if (unlikely(!cmp_len ||
cmp_len > lzo1x_worst_compress(LZO_UNC_SIZE))) {
printk(KERN_ERR "PM: Invalid LZO compressed length\n");
error = -1;
break;
}
for (off = PAGE_SIZE, i = 1;
off < LZO_HEADER + cmp_len; off += PAGE_SIZE, i++) {
error = swap_read_page(handle, page[i], &bio);
if (error)
goto out_finish;
}
error = hib_wait_on_bio_chain(&bio);
if (error)
goto out_finish;
for (off = 0, i = 0;
off < LZO_HEADER + cmp_len; off += PAGE_SIZE, i++) {
memcpy(cmp + off, page[i], PAGE_SIZE);
}
unc_len = LZO_UNC_SIZE;
error = lzo1x_decompress_safe(cmp + LZO_HEADER, cmp_len,
unc, &unc_len);
if (error < 0) {
printk(KERN_ERR "PM: LZO decompression failed\n");
break;
}
if (unlikely(!unc_len ||
unc_len > LZO_UNC_SIZE ||
unc_len & (PAGE_SIZE - 1))) {
printk(KERN_ERR "PM: Invalid LZO uncompressed length\n");
error = -1;
break;
}
for (off = 0; off < unc_len; off += PAGE_SIZE) {
memcpy(data_of(*snapshot), unc + off, PAGE_SIZE);
if (!(nr_pages % m))
printk("\b\b\b\b%3d%%", nr_pages / m);
nr_pages++;
error = snapshot_write_next(snapshot);
if (error <= 0)
goto out_finish;
}
}
out_finish:
do_gettimeofday(&stop);
if (!error) {
printk("\b\b\b\bdone\n");
snapshot_write_finalize(snapshot);
if (!snapshot_image_loaded(snapshot))
error = -ENODATA;
} else
printk("\n");
swsusp_show_speed(&start, &stop, nr_to_read, "Read");
vfree(cmp);
vfree(unc);
for (i = 0; i < LZO_CMP_PAGES; i++)
free_page((unsigned long)page[i]);
return error;
}
int swsusp_read(unsigned int *flags_p)
{
int error;
struct swap_map_handle handle;
struct snapshot_handle snapshot;
struct swsusp_info *header;
memset(&snapshot, 0, sizeof(struct snapshot_handle));
error = snapshot_write_next(&snapshot);
if (error < PAGE_SIZE)
return error < 0 ? error : -EFAULT;
header = (struct swsusp_info *)data_of(snapshot);
error = get_swap_reader(&handle, flags_p);
if (error)
goto end;
if (!error)
error = swap_read_page(&handle, header, NULL);
if (!error) {
error = (*flags_p & SF_NOCOMPRESS_MODE) ?
load_image(&handle, &snapshot, header->pages - 1) :
load_image_lzo(&handle, &snapshot, header->pages - 1);
}
swap_reader_finish(&handle);
end:
if (!error)
pr_debug("PM: Image successfully loaded\n");
else
pr_debug("PM: Error %d resuming\n", error);
return error;
}
int swsusp_check(void)
{
int error;
hib_resume_bdev = blkdev_get_by_dev(swsusp_resume_device,
FMODE_READ, NULL);
if (!IS_ERR(hib_resume_bdev)) {
set_blocksize(hib_resume_bdev, PAGE_SIZE);
clear_page(swsusp_header);
error = hib_bio_read_page(swsusp_resume_block,
swsusp_header, NULL);
if (error)
goto put;
if (!memcmp(HIBERNATE_SIG, swsusp_header->sig, 10)) {
memcpy(swsusp_header->sig, swsusp_header->orig_sig, 10);
error = hib_bio_write_page(swsusp_resume_block,
swsusp_header, NULL);
} else {
error = -EINVAL;
}
put:
if (error)
blkdev_put(hib_resume_bdev, FMODE_READ);
else
pr_debug("PM: Image signature found, resuming\n");
} else {
error = PTR_ERR(hib_resume_bdev);
}
if (error)
pr_debug("PM: Image not found (code %d)\n", error);
return error;
}
void swsusp_close(fmode_t mode)
{
if (IS_ERR(hib_resume_bdev)) {
pr_debug("PM: Image device not initialised\n");
return;
}
blkdev_put(hib_resume_bdev, mode);
}
static int swsusp_header_init(void)
{
swsusp_header = (struct swsusp_header*) __get_free_page(GFP_KERNEL);
if (!swsusp_header)
panic("Could not allocate memory for swsusp_header\n");
return 0;
}
