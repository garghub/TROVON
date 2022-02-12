static int check_platform_magic(void)
{
short magic;
char protocol;
magic = inw(XEN_IOPORT_MAGIC);
if (magic != XEN_IOPORT_MAGIC_VAL) {
printk(KERN_ERR "Xen Platform PCI: unrecognised magic value\n");
return XEN_PLATFORM_ERR_MAGIC;
}
protocol = inb(XEN_IOPORT_PROTOVER);
printk(KERN_DEBUG "Xen Platform PCI: I/O protocol version %d\n",
protocol);
switch (protocol) {
case 1:
outw(XEN_IOPORT_LINUX_PRODNUM, XEN_IOPORT_PRODNUM);
outl(XEN_IOPORT_LINUX_DRVVER, XEN_IOPORT_DRVVER);
if (inw(XEN_IOPORT_MAGIC) != XEN_IOPORT_MAGIC_VAL) {
printk(KERN_ERR "Xen Platform: blacklisted by host\n");
return XEN_PLATFORM_ERR_BLACKLIST;
}
break;
default:
printk(KERN_WARNING "Xen Platform PCI: unknown I/O protocol version");
return XEN_PLATFORM_ERR_PROTOCOL;
}
return 0;
}
void xen_unplug_emulated_devices(void)
{
int r;
if (xen_emul_unplug & XEN_UNPLUG_NEVER)
return;
r = check_platform_magic();
if (r && !(r == XEN_PLATFORM_ERR_MAGIC &&
(xen_emul_unplug & XEN_UNPLUG_UNNECESSARY)))
return;
if (!xen_emul_unplug) {
if (xen_must_unplug_nics()) {
printk(KERN_INFO "Netfront and the Xen platform PCI driver have "
"been compiled for this kernel: unplug emulated NICs.\n");
xen_emul_unplug |= XEN_UNPLUG_ALL_NICS;
}
if (xen_must_unplug_disks()) {
printk(KERN_INFO "Blkfront and the Xen platform PCI driver have "
"been compiled for this kernel: unplug emulated disks.\n"
"You might have to change the root device\n"
"from /dev/hd[a-d] to /dev/xvd[a-d]\n"
"in your root= kernel command line option\n");
xen_emul_unplug |= XEN_UNPLUG_ALL_IDE_DISKS;
}
}
if (!(xen_emul_unplug & XEN_UNPLUG_UNNECESSARY))
outw(xen_emul_unplug, XEN_IOPORT_UNPLUG);
xen_platform_pci_unplug = xen_emul_unplug;
}
static int __init parse_xen_emul_unplug(char *arg)
{
char *p, *q;
int l;
for (p = arg; p; p = q) {
q = strchr(p, ',');
if (q) {
l = q - p;
q++;
} else {
l = strlen(p);
}
if (!strncmp(p, "all", l))
xen_emul_unplug |= XEN_UNPLUG_ALL;
else if (!strncmp(p, "ide-disks", l))
xen_emul_unplug |= XEN_UNPLUG_ALL_IDE_DISKS;
else if (!strncmp(p, "aux-ide-disks", l))
xen_emul_unplug |= XEN_UNPLUG_AUX_IDE_DISKS;
else if (!strncmp(p, "nics", l))
xen_emul_unplug |= XEN_UNPLUG_ALL_NICS;
else if (!strncmp(p, "unnecessary", l))
xen_emul_unplug |= XEN_UNPLUG_UNNECESSARY;
else if (!strncmp(p, "never", l))
xen_emul_unplug |= XEN_UNPLUG_NEVER;
else
printk(KERN_WARNING "unrecognised option '%s' "
"in parameter 'xen_emul_unplug'\n", p);
}
return 0;
}
