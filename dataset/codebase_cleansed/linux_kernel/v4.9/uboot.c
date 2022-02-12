static void __init parse_uboot_commandline(char *commandp, int size)
{
extern unsigned long _init_sp;
unsigned long *sp;
unsigned long uboot_kbd;
unsigned long uboot_initrd_start, uboot_initrd_end;
unsigned long uboot_cmd_start, uboot_cmd_end;
sp = (unsigned long *)_init_sp;
uboot_kbd = sp[1];
uboot_initrd_start = sp[2];
uboot_initrd_end = sp[3];
uboot_cmd_start = sp[4];
uboot_cmd_end = sp[5];
if (uboot_cmd_start && uboot_cmd_end)
strncpy(commandp, (const char *)uboot_cmd_start, size);
#if defined(CONFIG_BLK_DEV_INITRD)
if (uboot_initrd_start && uboot_initrd_end &&
(uboot_initrd_end > uboot_initrd_start)) {
initrd_start = uboot_initrd_start;
initrd_end = uboot_initrd_end;
ROOT_DEV = Root_RAM0;
printk(KERN_INFO "initrd at 0x%lx:0x%lx\n",
initrd_start, initrd_end);
}
#endif
}
__init void process_uboot_commandline(char *commandp, int size)
{
int len, n;
n = strnlen(commandp, size);
commandp += n;
len = size - n;
if (len) {
*commandp++ = ' ';
len--;
}
parse_uboot_commandline(commandp, len);
commandp[size - 1] = 0;
}
