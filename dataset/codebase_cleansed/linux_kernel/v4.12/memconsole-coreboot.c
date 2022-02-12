static int memconsole_coreboot_init(phys_addr_t physaddr)
{
struct cbmem_cons __iomem *tmp_cbmc;
tmp_cbmc = memremap(physaddr, sizeof(*tmp_cbmc), MEMREMAP_WB);
if (!tmp_cbmc)
return -ENOMEM;
cbmem_console = memremap(physaddr,
tmp_cbmc->buffer_size + sizeof(*cbmem_console),
MEMREMAP_WB);
memunmap(tmp_cbmc);
if (!cbmem_console)
return -ENOMEM;
memconsole_setup(cbmem_console->buffer_body,
min(cbmem_console->buffer_cursor, cbmem_console->buffer_size));
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
