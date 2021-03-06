static int mipc_check_address(u32 pa)
{
if (pa < 0x10000000 || pa > 0x14000000)
return -EINVAL;
return 0;
}
static struct mipc_infohdr *mipc_get_infohdr(void)
{
struct mipc_infohdr **hdrp, *hdr;
hdrp = (struct mipc_infohdr **)0x13fffffc;
if (mipc_check_address((u32)hdrp)) {
printf("mini: invalid hdrp %08X\n", (u32)hdrp);
hdr = NULL;
goto out;
}
hdr = *hdrp;
if (mipc_check_address((u32)hdr)) {
printf("mini: invalid hdr %08X\n", (u32)hdr);
hdr = NULL;
goto out;
}
if (memcmp(hdr->magic, "IPC", 3)) {
printf("mini: invalid magic\n");
hdr = NULL;
goto out;
}
out:
return hdr;
}
static int mipc_get_mem2_boundary(u32 *mem2_boundary)
{
struct mipc_infohdr *hdr;
int error;
hdr = mipc_get_infohdr();
if (!hdr) {
error = -1;
goto out;
}
if (mipc_check_address(hdr->mem2_boundary)) {
printf("mini: invalid mem2_boundary %08X\n",
hdr->mem2_boundary);
error = -EINVAL;
goto out;
}
*mem2_boundary = hdr->mem2_boundary;
error = 0;
out:
return error;
}
static void platform_fixups(void)
{
void *mem;
u32 reg[4];
u32 mem2_boundary;
int len;
int error;
mem = finddevice("/memory");
if (!mem)
fatal("Can't find memory node\n");
len = getprop(mem, "reg", reg, sizeof(reg));
if (len != sizeof(reg)) {
goto out;
}
error = mipc_get_mem2_boundary(&mem2_boundary);
if (error) {
mem2_boundary = MEM2_TOP - FIRMWARE_DEFAULT_SIZE;
}
if (mem2_boundary > reg[2] && mem2_boundary < reg[2] + reg[3]) {
reg[3] = mem2_boundary - reg[2];
printf("top of MEM2 @ %08X\n", reg[2] + reg[3]);
setprop(mem, "reg", reg, sizeof(reg));
}
out:
return;
}
void platform_init(unsigned long r3, unsigned long r4, unsigned long r5)
{
u32 heapsize = 24*1024*1024 - (u32)_end;
simple_alloc_init(_end, heapsize, 32, 64);
fdt_init(_dtb_start);
out_be32(EXI_CTRL, in_be32(EXI_CTRL) | EXI_CTRL_ENABLE);
if (ug_probe())
console_ops.write = ug_console_write;
platform_ops.fixups = platform_fixups;
}
