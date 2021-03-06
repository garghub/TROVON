static int __init md_setup(char *str)
{
int minor, level, factor, fault, partitioned = 0;
char *pername = "";
char *str1;
int ent;
if (*str == 'd') {
partitioned = 1;
str++;
}
if (get_option(&str, &minor) != 2) {
printk(KERN_WARNING "md: Too few arguments supplied to md=.\n");
return 0;
}
str1 = str;
for (ent=0 ; ent< md_setup_ents ; ent++)
if (md_setup_args[ent].minor == minor &&
md_setup_args[ent].partitioned == partitioned) {
printk(KERN_WARNING "md: md=%s%d, Specified more than once. "
"Replacing previous definition.\n", partitioned?"d":"", minor);
break;
}
if (ent >= ARRAY_SIZE(md_setup_args)) {
printk(KERN_WARNING "md: md=%s%d - too many md initialisations\n", partitioned?"d":"", minor);
return 0;
}
if (ent >= md_setup_ents)
md_setup_ents++;
switch (get_option(&str, &level)) {
case 2:
if (level == 0 || level == LEVEL_LINEAR) {
if (get_option(&str, &factor) != 2 ||
get_option(&str, &fault) != 2) {
printk(KERN_WARNING "md: Too few arguments supplied to md=.\n");
return 0;
}
md_setup_args[ent].level = level;
md_setup_args[ent].chunk = 1 << (factor+12);
if (level == LEVEL_LINEAR)
pername = "linear";
else
pername = "raid0";
break;
}
case 1:
str = str1;
case 0:
md_setup_args[ent].level = LEVEL_NONE;
pername="super-block";
}
printk(KERN_INFO "md: Will configure md%d (%s) from %s, below.\n",
minor, pername, str);
md_setup_args[ent].device_names = str;
md_setup_args[ent].partitioned = partitioned;
md_setup_args[ent].minor = minor;
return 1;
}
static void __init md_setup_drive(void)
{
int minor, i, ent, partitioned;
dev_t dev;
dev_t devices[MD_SB_DISKS+1];
for (ent = 0; ent < md_setup_ents ; ent++) {
int fd;
int err = 0;
char *devname;
mdu_disk_info_t dinfo;
char name[16];
minor = md_setup_args[ent].minor;
partitioned = md_setup_args[ent].partitioned;
devname = md_setup_args[ent].device_names;
sprintf(name, "/dev/md%s%d", partitioned?"_d":"", minor);
if (partitioned)
dev = MKDEV(mdp_major, minor << MdpMinorShift);
else
dev = MKDEV(MD_MAJOR, minor);
create_dev(name, dev);
for (i = 0; i < MD_SB_DISKS && devname != NULL; i++) {
char *p;
char comp_name[64];
u32 rdev;
p = strchr(devname, ',');
if (p)
*p++ = 0;
dev = name_to_dev_t(devname);
if (strncmp(devname, "/dev/", 5) == 0)
devname += 5;
snprintf(comp_name, 63, "/dev/%s", devname);
rdev = bstat(comp_name);
if (rdev)
dev = new_decode_dev(rdev);
if (!dev) {
printk(KERN_WARNING "md: Unknown device name: %s\n", devname);
break;
}
devices[i] = dev;
devname = p;
}
devices[i] = 0;
if (!i)
continue;
printk(KERN_INFO "md: Loading md%s%d: %s\n",
partitioned ? "_d" : "", minor,
md_setup_args[ent].device_names);
fd = sys_open(name, 0, 0);
if (fd < 0) {
printk(KERN_ERR "md: open failed - cannot start "
"array %s\n", name);
continue;
}
if (sys_ioctl(fd, SET_ARRAY_INFO, 0) == -EBUSY) {
printk(KERN_WARNING
"md: Ignoring md=%d, already autodetected. (Use raid=noautodetect)\n",
minor);
sys_close(fd);
continue;
}
if (md_setup_args[ent].level != LEVEL_NONE) {
mdu_array_info_t ainfo;
ainfo.level = md_setup_args[ent].level;
ainfo.size = 0;
ainfo.nr_disks =0;
ainfo.raid_disks =0;
while (devices[ainfo.raid_disks])
ainfo.raid_disks++;
ainfo.md_minor =minor;
ainfo.not_persistent = 1;
ainfo.state = (1 << MD_SB_CLEAN);
ainfo.layout = 0;
ainfo.chunk_size = md_setup_args[ent].chunk;
err = sys_ioctl(fd, SET_ARRAY_INFO, (long)&ainfo);
for (i = 0; !err && i <= MD_SB_DISKS; i++) {
dev = devices[i];
if (!dev)
break;
dinfo.number = i;
dinfo.raid_disk = i;
dinfo.state = (1<<MD_DISK_ACTIVE)|(1<<MD_DISK_SYNC);
dinfo.major = MAJOR(dev);
dinfo.minor = MINOR(dev);
err = sys_ioctl(fd, ADD_NEW_DISK, (long)&dinfo);
}
} else {
for (i = 0; i <= MD_SB_DISKS; i++) {
dev = devices[i];
if (!dev)
break;
dinfo.major = MAJOR(dev);
dinfo.minor = MINOR(dev);
sys_ioctl(fd, ADD_NEW_DISK, (long)&dinfo);
}
}
if (!err)
err = sys_ioctl(fd, RUN_ARRAY, 0);
if (err)
printk(KERN_WARNING "md: starting md%d failed\n", minor);
else {
sys_close(fd);
fd = sys_open(name, 0, 0);
sys_ioctl(fd, BLKRRPART, 0);
}
sys_close(fd);
}
}
static int __init raid_setup(char *str)
{
int len, pos;
len = strlen(str) + 1;
pos = 0;
while (pos < len) {
char *comma = strchr(str+pos, ',');
int wlen;
if (comma)
wlen = (comma-str)-pos;
else wlen = (len-1)-pos;
if (!strncmp(str, "noautodetect", wlen))
raid_noautodetect = 1;
if (!strncmp(str, "autodetect", wlen))
raid_noautodetect = 0;
if (strncmp(str, "partitionable", wlen)==0)
raid_autopart = 1;
if (strncmp(str, "part", wlen)==0)
raid_autopart = 1;
pos += wlen+1;
}
return 1;
}
static void __init autodetect_raid(void)
{
int fd;
printk(KERN_INFO "md: Waiting for all devices to be available before autodetect\n");
printk(KERN_INFO "md: If you don't use raid, use raid=noautodetect\n");
wait_for_device_probe();
fd = sys_open("/dev/md0", 0, 0);
if (fd >= 0) {
sys_ioctl(fd, RAID_AUTORUN, raid_autopart);
sys_close(fd);
}
}
void __init md_run_setup(void)
{
create_dev("/dev/md0", MKDEV(MD_MAJOR, 0));
if (raid_noautodetect)
printk(KERN_INFO "md: Skipping autodetection of RAID arrays. (raid=autodetect will force)\n");
else
autodetect_raid();
md_setup_drive();
}
