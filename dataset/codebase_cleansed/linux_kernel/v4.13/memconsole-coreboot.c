static ssize_t memconsole_coreboot_read(char *buf, loff_t pos, size_t count)
{
u32 cursor = cbmem_console->cursor & CURSOR_MASK;
u32 flags = cbmem_console->cursor & ~CURSOR_MASK;
u32 size = cbmem_console_size;
struct seg {
u32 phys;
u32 len;
} seg[2] = { {0}, {0} };
size_t done = 0;
int i;
if (flags & OVERFLOW) {
if (cursor > size)
cursor = 0;
seg[0] = (struct seg){.phys = cursor, .len = size - cursor};
seg[1] = (struct seg){.phys = 0, .len = cursor};
} else {
seg[0] = (struct seg){.phys = 0, .len = min(cursor, size)};
}
for (i = 0; i < ARRAY_SIZE(seg) && count > done; i++) {
done += memory_read_from_buffer(buf + done, count - done, &pos,
cbmem_console->body + seg[i].phys, seg[i].len);
pos -= seg[i].len;
}
return done;
}
static int memconsole_coreboot_init(phys_addr_t physaddr)
{
struct cbmem_cons __iomem *tmp_cbmc;
tmp_cbmc = memremap(physaddr, sizeof(*tmp_cbmc), MEMREMAP_WB);
if (!tmp_cbmc)
return -ENOMEM;
cbmem_console_size = tmp_cbmc->size_dont_access_after_boot;
cbmem_console = memremap(physaddr,
cbmem_console_size + sizeof(*cbmem_console),
MEMREMAP_WB);
memunmap(tmp_cbmc);
if (!cbmem_console)
return -ENOMEM;
memconsole_setup(memconsole_coreboot_read);
return 0;
}
static int memconsole_probe(struct platform_device *pdev)
{
int ret;
struct lb_cbmem_ref entry;
ret = coreboot_table_find(CB_TAG_CBMEM_CONSOLE, &entry, sizeof(entry));
if (ret)
return ret;
ret = memconsole_coreboot_init(entry.cbmem_addr);
if (ret)
return ret;
return memconsole_sysfs_init();
}
static int memconsole_remove(struct platform_device *pdev)
{
memconsole_exit();
if (cbmem_console)
memunmap(cbmem_console);
return 0;
}
static int __init platform_memconsole_init(void)
{
struct platform_device *pdev;
pdev = platform_device_register_simple("memconsole", -1, NULL, 0);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
platform_driver_register(&memconsole_driver);
return 0;
}
