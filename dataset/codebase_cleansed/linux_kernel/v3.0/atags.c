static int
read_buffer(char* page, char** start, off_t off, int count,
int* eof, void* data)
{
struct buffer *buffer = (struct buffer *)data;
if (off >= buffer->size) {
*eof = 1;
return 0;
}
count = min((int) (buffer->size - off), count);
memcpy(page, &buffer->data[off], count);
return count;
}
void __init save_atags(const struct tag *tags)
{
memcpy(atags_copy, tags, sizeof(atags_copy));
}
static int __init init_atags_procfs(void)
{
struct proc_dir_entry *tags_entry;
struct tag *tag = (struct tag *)atags_copy;
struct buffer *b;
size_t size;
if (tag->hdr.tag != ATAG_CORE) {
printk(KERN_INFO "No ATAGs?");
return -EINVAL;
}
for (; tag->hdr.size; tag = tag_next(tag))
;
size = (char *)tag - atags_copy + sizeof(struct tag_header);
WARN_ON(tag->hdr.tag != ATAG_NONE);
b = kmalloc(sizeof(*b) + size, GFP_KERNEL);
if (!b)
goto nomem;
b->size = size;
memcpy(b->data, atags_copy, size);
tags_entry = create_proc_read_entry("atags", 0400,
NULL, read_buffer, b);
if (!tags_entry)
goto nomem;
return 0;
nomem:
kfree(b);
printk(KERN_ERR "Exporting ATAGs: not enough memory\n");
return -ENOMEM;
}
