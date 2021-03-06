static void __init bootx_printf(const char *format, ...)
{
const char *p, *q, *s;
va_list args;
unsigned long v;
va_start(args, format);
for (p = format; *p != 0; p = q) {
for (q = p; *q != 0 && *q != '\n' && *q != '%'; ++q)
;
if (q > p)
btext_drawtext(p, q - p);
if (*q == 0)
break;
if (*q == '\n') {
++q;
btext_flushline();
btext_drawstring("\r\n");
btext_flushline();
continue;
}
++q;
if (*q == 0)
break;
switch (*q) {
case 's':
++q;
s = va_arg(args, const char *);
if (s == NULL)
s = "<NULL>";
btext_drawstring(s);
break;
case 'x':
++q;
v = va_arg(args, unsigned long);
btext_drawhex(v);
break;
}
}
}
static void __init bootx_printf(const char *format, ...) {}
static void * __init bootx_early_getprop(unsigned long base,
unsigned long node,
char *prop)
{
struct bootx_dt_node *np = (struct bootx_dt_node *)(base + node);
u32 *ppp = &np->properties;
while(*ppp) {
struct bootx_dt_prop *pp =
(struct bootx_dt_prop *)(base + *ppp);
if (strcmp((char *)((unsigned long)pp->name + base),
prop) == 0) {
return (void *)((unsigned long)pp->value + base);
}
ppp = &pp->next;
}
return NULL;
}
static unsigned long __init bootx_dt_find_string(char *str)
{
char *s, *os;
s = os = (char *)bootx_dt_strbase;
s += 4;
while (s < (char *)bootx_dt_strend) {
if (strcmp(s, str) == 0)
return s - os;
s += strlen(s) + 1;
}
return 0;
}
static void __init bootx_dt_add_prop(char *name, void *data, int size,
unsigned long *mem_end)
{
unsigned long soff = bootx_dt_find_string(name);
if (data == NULL)
size = 0;
if (soff == 0) {
bootx_printf("WARNING: Can't find string index for <%s>\n",
name);
return;
}
if (size > 0x20000) {
bootx_printf("WARNING: ignoring large property ");
bootx_printf("%s length 0x%x\n", name, size);
return;
}
dt_push_token(OF_DT_PROP, mem_end);
dt_push_token(size, mem_end);
dt_push_token(soff, mem_end);
if (size && data) {
memcpy((void *)*mem_end, data, size);
*mem_end = _ALIGN_UP(*mem_end + size, 4);
}
}
static void __init bootx_add_chosen_props(unsigned long base,
unsigned long *mem_end)
{
u32 val;
bootx_dt_add_prop("linux,bootx", NULL, 0, mem_end);
if (bootx_info->kernelParamsOffset) {
char *args = (char *)((unsigned long)bootx_info) +
bootx_info->kernelParamsOffset;
bootx_dt_add_prop("bootargs", args, strlen(args) + 1, mem_end);
}
if (bootx_info->ramDisk) {
val = ((unsigned long)bootx_info) + bootx_info->ramDisk;
bootx_dt_add_prop("linux,initrd-start", &val, 4, mem_end);
val += bootx_info->ramDiskSize;
bootx_dt_add_prop("linux,initrd-end", &val, 4, mem_end);
}
if (strlen(bootx_disp_path))
bootx_dt_add_prop("linux,stdout-path", bootx_disp_path,
strlen(bootx_disp_path) + 1, mem_end);
}
static void __init bootx_add_display_props(unsigned long base,
unsigned long *mem_end,
int has_real_node)
{
boot_infos_t *bi = bootx_info;
u32 tmp;
if (has_real_node) {
bootx_dt_add_prop("linux,boot-display", NULL, 0, mem_end);
bootx_dt_add_prop("linux,opened", NULL, 0, mem_end);
} else
bootx_dt_add_prop("linux,bootx-noscreen", NULL, 0, mem_end);
tmp = bi->dispDeviceDepth;
bootx_dt_add_prop("linux,bootx-depth", &tmp, 4, mem_end);
tmp = bi->dispDeviceRect[2] - bi->dispDeviceRect[0];
bootx_dt_add_prop("linux,bootx-width", &tmp, 4, mem_end);
tmp = bi->dispDeviceRect[3] - bi->dispDeviceRect[1];
bootx_dt_add_prop("linux,bootx-height", &tmp, 4, mem_end);
tmp = bi->dispDeviceRowBytes;
bootx_dt_add_prop("linux,bootx-linebytes", &tmp, 4, mem_end);
tmp = (u32)bi->dispDeviceBase;
if (tmp == 0)
tmp = (u32)bi->logicalDisplayBase;
tmp += bi->dispDeviceRect[1] * bi->dispDeviceRowBytes;
tmp += bi->dispDeviceRect[0] * ((bi->dispDeviceDepth + 7) / 8);
bootx_dt_add_prop("linux,bootx-addr", &tmp, 4, mem_end);
}
static void __init bootx_dt_add_string(char *s, unsigned long *mem_end)
{
unsigned int l = strlen(s) + 1;
memcpy((void *)*mem_end, s, l);
bootx_dt_strend = *mem_end = *mem_end + l;
}
static void __init bootx_scan_dt_build_strings(unsigned long base,
unsigned long node,
unsigned long *mem_end)
{
struct bootx_dt_node *np = (struct bootx_dt_node *)(base + node);
u32 *cpp, *ppp = &np->properties;
unsigned long soff;
char *namep;
namep = np->full_name ? (char *)(base + np->full_name) : NULL;
if (namep == NULL) {
bootx_printf("Node without a full name !\n");
namep = "";
}
DBG("* strings: %s\n", namep);
if (!strcmp(namep, "/chosen")) {
DBG(" detected /chosen ! adding properties names !\n");
bootx_dt_add_string("linux,bootx", mem_end);
bootx_dt_add_string("linux,stdout-path", mem_end);
bootx_dt_add_string("linux,initrd-start", mem_end);
bootx_dt_add_string("linux,initrd-end", mem_end);
bootx_dt_add_string("bootargs", mem_end);
bootx_node_chosen = node;
}
if (node == bootx_info->dispDeviceRegEntryOffset) {
DBG(" detected display ! adding properties names !\n");
bootx_dt_add_string("linux,boot-display", mem_end);
bootx_dt_add_string("linux,opened", mem_end);
strlcpy(bootx_disp_path, namep, sizeof(bootx_disp_path));
}
while (*ppp) {
struct bootx_dt_prop *pp =
(struct bootx_dt_prop *)(base + *ppp);
namep = pp->name ? (char *)(base + pp->name) : NULL;
if (namep == NULL || strcmp(namep, "name") == 0)
goto next;
soff = bootx_dt_find_string(namep);
if (soff == 0)
bootx_dt_add_string(namep, mem_end);
next:
ppp = &pp->next;
}
cpp = &np->child;
while(*cpp) {
np = (struct bootx_dt_node *)(base + *cpp);
bootx_scan_dt_build_strings(base, *cpp, mem_end);
cpp = &np->sibling;
}
}
static void __init bootx_scan_dt_build_struct(unsigned long base,
unsigned long node,
unsigned long *mem_end)
{
struct bootx_dt_node *np = (struct bootx_dt_node *)(base + node);
u32 *cpp, *ppp = &np->properties;
char *namep, *p, *ep, *lp;
int l;
dt_push_token(OF_DT_BEGIN_NODE, mem_end);
namep = np->full_name ? (char *)(base + np->full_name) : NULL;
if (namep == NULL)
namep = "";
l = strlen(namep);
DBG("* struct: %s\n", namep);
memcpy((void *)*mem_end, namep, l + 1);
namep = (char *)*mem_end;
for (lp = p = namep, ep = namep + l; p < ep; p++) {
if (*p == '/')
lp = namep;
else if (*p != 0)
*lp++ = *p;
}
*lp = 0;
*mem_end = _ALIGN_UP((unsigned long)lp + 1, 4);
while (*ppp) {
struct bootx_dt_prop *pp =
(struct bootx_dt_prop *)(base + *ppp);
namep = pp->name ? (char *)(base + pp->name) : NULL;
if (namep == NULL || !strcmp(namep, "name"))
goto next;
if (node == bootx_node_chosen && !strcmp(namep, "bootargs"))
goto next;
bootx_dt_add_prop(namep,
pp->value ? (void *)(base + pp->value): NULL,
pp->length, mem_end);
next:
ppp = &pp->next;
}
if (node == bootx_node_chosen) {
bootx_add_chosen_props(base, mem_end);
if (bootx_info->dispDeviceRegEntryOffset == 0)
bootx_add_display_props(base, mem_end, 0);
}
else if (node == bootx_info->dispDeviceRegEntryOffset)
bootx_add_display_props(base, mem_end, 1);
cpp = &np->child;
while(*cpp) {
np = (struct bootx_dt_node *)(base + *cpp);
bootx_scan_dt_build_struct(base, *cpp, mem_end);
cpp = &np->sibling;
}
dt_push_token(OF_DT_END_NODE, mem_end);
}
static unsigned long __init bootx_flatten_dt(unsigned long start)
{
boot_infos_t *bi = bootx_info;
unsigned long mem_start, mem_end;
struct boot_param_header *hdr;
unsigned long base;
u64 *rsvmap;
mem_start = mem_end = _ALIGN_UP(((unsigned long)bi) + start, 4);
DBG("Boot params header at: %x\n", mem_start);
hdr = (struct boot_param_header *)mem_start;
mem_end += sizeof(struct boot_param_header);
rsvmap = (u64 *)(_ALIGN_UP(mem_end, 8));
hdr->off_mem_rsvmap = ((unsigned long)rsvmap) - mem_start;
mem_end = ((unsigned long)rsvmap) + 8 * sizeof(u64);
base = ((unsigned long)bi) + bi->deviceTreeOffset;
DBG("Building string array at: %x\n", mem_end);
DBG("Device Tree Base=%x\n", base);
bootx_dt_strbase = mem_end;
mem_end += 4;
bootx_dt_strend = mem_end;
bootx_scan_dt_build_strings(base, 4, &mem_end);
bootx_dt_add_string("linux,bootx-noscreen", &mem_end);
bootx_dt_add_string("linux,bootx-depth", &mem_end);
bootx_dt_add_string("linux,bootx-width", &mem_end);
bootx_dt_add_string("linux,bootx-height", &mem_end);
bootx_dt_add_string("linux,bootx-linebytes", &mem_end);
bootx_dt_add_string("linux,bootx-addr", &mem_end);
hdr->off_dt_strings = bootx_dt_strbase - mem_start;
hdr->dt_strings_size = bootx_dt_strend - bootx_dt_strbase;
mem_end = _ALIGN(mem_end, 16);
DBG("Building device tree structure at: %x\n", mem_end);
hdr->off_dt_struct = mem_end - mem_start;
bootx_scan_dt_build_struct(base, 4, &mem_end);
dt_push_token(OF_DT_END, &mem_end);
hdr->boot_cpuid_phys = 0;
hdr->magic = OF_DT_HEADER;
hdr->totalsize = mem_end - mem_start;
hdr->version = OF_DT_VERSION;
hdr->last_comp_version = 0x10;
mem_end = _ALIGN(mem_end, PAGE_SIZE);
DBG("End of boot params: %x\n", mem_end);
rsvmap[0] = mem_start;
rsvmap[1] = mem_end;
if (bootx_info->ramDisk) {
rsvmap[2] = ((unsigned long)bootx_info) + bootx_info->ramDisk;
rsvmap[3] = rsvmap[2] + bootx_info->ramDiskSize;
rsvmap[4] = 0;
rsvmap[5] = 0;
} else {
rsvmap[2] = 0;
rsvmap[3] = 0;
}
return (unsigned long)hdr;
}
static void __init btext_welcome(boot_infos_t *bi)
{
unsigned long flags;
unsigned long pvr;
bootx_printf("Welcome to Linux, kernel " UTS_RELEASE "\n");
bootx_printf("\nlinked at : 0x%x", KERNELBASE);
bootx_printf("\nframe buffer at : 0x%x", bi->dispDeviceBase);
bootx_printf(" (phys), 0x%x", bi->logicalDisplayBase);
bootx_printf(" (log)");
bootx_printf("\nklimit : 0x%x",(unsigned long)klimit);
bootx_printf("\nboot_info at : 0x%x", bi);
__asm__ __volatile__ ("mfmsr %0" : "=r" (flags));
bootx_printf("\nMSR : 0x%x", flags);
__asm__ __volatile__ ("mfspr %0, 287" : "=r" (pvr));
bootx_printf("\nPVR : 0x%x", pvr);
pvr >>= 16;
if (pvr > 1) {
__asm__ __volatile__ ("mfspr %0, 1008" : "=r" (flags));
bootx_printf("\nHID0 : 0x%x", flags);
}
if (pvr == 8 || pvr == 12 || pvr == 0x800c) {
__asm__ __volatile__ ("mfspr %0, 1019" : "=r" (flags));
bootx_printf("\nICTC : 0x%x", flags);
}
#ifdef DEBUG
bootx_printf("\n\n");
bootx_printf("bi->deviceTreeOffset : 0x%x\n",
bi->deviceTreeOffset);
bootx_printf("bi->deviceTreeSize : 0x%x\n",
bi->deviceTreeSize);
#endif
bootx_printf("\n\n");
}
void __init bootx_init(unsigned long r3, unsigned long r4)
{
boot_infos_t *bi = (boot_infos_t *) r4;
unsigned long hdr;
unsigned long space;
unsigned long ptr, x;
char *model;
unsigned long offset = reloc_offset();
reloc_got2(offset);
bootx_info = bi;
bootx_dt_strbase = bootx_dt_strend = 0;
bootx_node_chosen = 0;
bootx_disp_path[0] = 0;
if (!BOOT_INFO_IS_V2_COMPATIBLE(bi))
bi->logicalDisplayBase = bi->dispDeviceBase;
if (bi->dispDeviceDepth == 16)
bi->dispDeviceDepth = 15;
#ifdef CONFIG_BOOTX_TEXT
ptr = (unsigned long)bi->logicalDisplayBase;
ptr += bi->dispDeviceRect[1] * bi->dispDeviceRowBytes;
ptr += bi->dispDeviceRect[0] * ((bi->dispDeviceDepth + 7) / 8);
btext_setup_display(bi->dispDeviceRect[2] - bi->dispDeviceRect[0],
bi->dispDeviceRect[3] - bi->dispDeviceRect[1],
bi->dispDeviceDepth, bi->dispDeviceRowBytes,
(unsigned long)bi->logicalDisplayBase);
btext_clearscreen();
btext_flushscreen();
#endif
if (!BOOT_INFO_IS_COMPATIBLE(bi)) {
bootx_printf(" !!! WARNING - Incompatible version"
" of BootX !!!\n\n\n");
for (;;)
;
}
if (bi->architecture != BOOT_ARCH_PCI) {
bootx_printf(" !!! WARNING - Usupported machine"
" architecture !\n");
for (;;)
;
}
#ifdef CONFIG_BOOTX_TEXT
btext_welcome(bi);
#endif
if (bi->version < 4) {
model = (char *) bootx_early_getprop(r4 + bi->deviceTreeOffset,
4, "model");
if (model
&& (strcmp(model, "iMac,1") == 0
|| strcmp(model, "PowerMac1,1") == 0)) {
bootx_printf("iMac,1 detected, shutting down USB\n");
out_le32((unsigned __iomem *)0x80880008, 1);
}
}
if (bi->version < 5) {
space = bi->deviceTreeOffset + bi->deviceTreeSize;
if (bi->ramDisk >= space)
space = bi->ramDisk + bi->ramDiskSize;
} else
space = bi->totalParamsSize;
bootx_printf("Total space used by parameters & ramdisk: 0x%x\n", space);
if (bi->version < 4) {
bootx_printf("Touching pages...\n");
for (ptr = ((unsigned long) &_stext) & PAGE_MASK;
ptr < (unsigned long)bi + space; ptr += PAGE_SIZE)
x = *(volatile unsigned long *)ptr;
}
bootx_printf("Preparing boot params...\n");
hdr = bootx_flatten_dt(space);
#ifdef CONFIG_BOOTX_TEXT
#ifdef SET_BOOT_BAT
bootx_printf("Preparing BAT...\n");
btext_prepare_BAT();
#else
btext_unmap();
#endif
#endif
reloc_got2(-offset);
__start(hdr, KERNELBASE + offset, 0);
}
