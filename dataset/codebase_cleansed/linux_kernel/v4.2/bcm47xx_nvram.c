static u32 find_nvram_size(void __iomem *end)
{
struct nvram_header __iomem *header;
int i;
for (i = 0; i < ARRAY_SIZE(nvram_sizes); i++) {
header = (struct nvram_header *)(end - nvram_sizes[i]);
if (header->magic == NVRAM_MAGIC)
return nvram_sizes[i];
}
return 0;
}
static int nvram_find_and_copy(void __iomem *iobase, u32 lim)
{
struct nvram_header __iomem *header;
int i;
u32 off;
u32 *src, *dst;
u32 size;
if (nvram_len) {
pr_warn("nvram already initialized\n");
return -EEXIST;
}
off = FLASH_MIN;
while (off <= lim) {
size = find_nvram_size(iobase + off);
if (size) {
header = (struct nvram_header *)(iobase + off - size);
goto found;
}
off <<= 1;
}
header = (struct nvram_header *)(iobase + 4096);
if (header->magic == NVRAM_MAGIC) {
size = NVRAM_SPACE;
goto found;
}
header = (struct nvram_header *)(iobase + 1024);
if (header->magic == NVRAM_MAGIC) {
size = NVRAM_SPACE;
goto found;
}
pr_err("no nvram found\n");
return -ENXIO;
found:
src = (u32 *)header;
dst = (u32 *)nvram_buf;
for (i = 0; i < sizeof(struct nvram_header); i += 4)
*dst++ = __raw_readl(src++);
header = (struct nvram_header *)nvram_buf;
nvram_len = header->len;
if (nvram_len > size) {
pr_err("The nvram size according to the header seems to be bigger than the partition on flash\n");
nvram_len = size;
}
if (nvram_len >= NVRAM_SPACE) {
pr_err("nvram on flash (%i bytes) is bigger than the reserved space in memory, will just copy the first %i bytes\n",
header->len, NVRAM_SPACE - 1);
nvram_len = NVRAM_SPACE - 1;
}
for (; i < nvram_len; i += 4)
*dst++ = readl(src++);
nvram_buf[NVRAM_SPACE - 1] = '\0';
return 0;
}
int bcm47xx_nvram_init_from_mem(u32 base, u32 lim)
{
void __iomem *iobase;
int err;
iobase = ioremap_nocache(base, lim);
if (!iobase)
return -ENOMEM;
err = nvram_find_and_copy(iobase, lim);
iounmap(iobase);
return err;
}
static int nvram_init(void)
{
#ifdef CONFIG_MTD
struct mtd_info *mtd;
struct nvram_header header;
size_t bytes_read;
int err;
mtd = get_mtd_device_nm("nvram");
if (IS_ERR(mtd))
return -ENODEV;
err = mtd_read(mtd, 0, sizeof(header), &bytes_read, (uint8_t *)&header);
if (!err && header.magic == NVRAM_MAGIC &&
header.len > sizeof(header)) {
nvram_len = header.len;
if (nvram_len >= NVRAM_SPACE) {
pr_err("nvram on flash (%i bytes) is bigger than the reserved space in memory, will just copy the first %i bytes\n",
header.len, NVRAM_SPACE);
nvram_len = NVRAM_SPACE - 1;
}
err = mtd_read(mtd, 0, nvram_len, &nvram_len,
(u8 *)nvram_buf);
return err;
}
#endif
return -ENXIO;
}
int bcm47xx_nvram_getenv(const char *name, char *val, size_t val_len)
{
char *var, *value, *end, *eq;
int err;
if (!name)
return -EINVAL;
if (!nvram_len) {
err = nvram_init();
if (err)
return err;
}
var = &nvram_buf[sizeof(struct nvram_header)];
end = nvram_buf + sizeof(nvram_buf);
while (var < end && *var) {
eq = strchr(var, '=');
if (!eq)
break;
value = eq + 1;
if (eq - var == strlen(name) &&
strncmp(var, name, eq - var) == 0)
return snprintf(val, val_len, "%s", value);
var = value + strlen(value) + 1;
}
return -ENOENT;
}
int bcm47xx_nvram_gpio_pin(const char *name)
{
int i, err;
char nvram_var[] = "gpioXX";
char buf[NVRAM_MAX_GPIO_VALUE_LEN];
for (i = 0; i < NVRAM_MAX_GPIO_ENTRIES; i++) {
err = snprintf(nvram_var, sizeof(nvram_var), "gpio%i", i);
if (err <= 0)
continue;
err = bcm47xx_nvram_getenv(nvram_var, buf, sizeof(buf));
if (err <= 0)
continue;
if (!strcmp(name, buf))
return i;
}
return -ENOENT;
}
char *bcm47xx_nvram_get_contents(size_t *nvram_size)
{
int err;
char *nvram;
if (!nvram_len) {
err = nvram_init();
if (err)
return NULL;
}
*nvram_size = nvram_len - sizeof(struct nvram_header);
nvram = vmalloc(*nvram_size);
if (!nvram)
return NULL;
memcpy(nvram, &nvram_buf[sizeof(struct nvram_header)], *nvram_size);
return nvram;
}
