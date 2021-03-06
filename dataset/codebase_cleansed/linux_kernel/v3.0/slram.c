static int slram_erase(struct mtd_info *mtd, struct erase_info *instr)
{
slram_priv_t *priv = mtd->priv;
if (instr->addr + instr->len > mtd->size) {
return(-EINVAL);
}
memset(priv->start + instr->addr, 0xff, instr->len);
instr->state = MTD_ERASE_DONE;
mtd_erase_callback(instr);
return(0);
}
static int slram_point(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, void **virt, resource_size_t *phys)
{
slram_priv_t *priv = mtd->priv;
if (phys)
return -EINVAL;
if (from + len > mtd->size)
return -EINVAL;
*virt = priv->start + from;
*retlen = len;
return(0);
}
static void slram_unpoint(struct mtd_info *mtd, loff_t from, size_t len)
{
}
static int slram_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
slram_priv_t *priv = mtd->priv;
if (from > mtd->size)
return -EINVAL;
if (from + len > mtd->size)
len = mtd->size - from;
memcpy(buf, priv->start + from, len);
*retlen = len;
return(0);
}
static int slram_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
slram_priv_t *priv = mtd->priv;
if (to + len > mtd->size)
return -EINVAL;
memcpy(priv->start + to, buf, len);
*retlen = len;
return(0);
}
static int register_device(char *name, unsigned long start, unsigned long length)
{
slram_mtd_list_t **curmtd;
curmtd = &slram_mtdlist;
while (*curmtd) {
curmtd = &(*curmtd)->next;
}
*curmtd = kmalloc(sizeof(slram_mtd_list_t), GFP_KERNEL);
if (!(*curmtd)) {
E("slram: Cannot allocate new MTD device.\n");
return(-ENOMEM);
}
(*curmtd)->mtdinfo = kzalloc(sizeof(struct mtd_info), GFP_KERNEL);
(*curmtd)->next = NULL;
if ((*curmtd)->mtdinfo) {
(*curmtd)->mtdinfo->priv =
kzalloc(sizeof(slram_priv_t), GFP_KERNEL);
if (!(*curmtd)->mtdinfo->priv) {
kfree((*curmtd)->mtdinfo);
(*curmtd)->mtdinfo = NULL;
}
}
if (!(*curmtd)->mtdinfo) {
E("slram: Cannot allocate new MTD device.\n");
return(-ENOMEM);
}
if (!(((slram_priv_t *)(*curmtd)->mtdinfo->priv)->start =
ioremap(start, length))) {
E("slram: ioremap failed\n");
return -EIO;
}
((slram_priv_t *)(*curmtd)->mtdinfo->priv)->end =
((slram_priv_t *)(*curmtd)->mtdinfo->priv)->start + length;
(*curmtd)->mtdinfo->name = name;
(*curmtd)->mtdinfo->size = length;
(*curmtd)->mtdinfo->flags = MTD_CAP_RAM;
(*curmtd)->mtdinfo->erase = slram_erase;
(*curmtd)->mtdinfo->point = slram_point;
(*curmtd)->mtdinfo->unpoint = slram_unpoint;
(*curmtd)->mtdinfo->read = slram_read;
(*curmtd)->mtdinfo->write = slram_write;
(*curmtd)->mtdinfo->owner = THIS_MODULE;
(*curmtd)->mtdinfo->type = MTD_RAM;
(*curmtd)->mtdinfo->erasesize = SLRAM_BLK_SZ;
(*curmtd)->mtdinfo->writesize = 1;
if (mtd_device_register((*curmtd)->mtdinfo, NULL, 0)) {
E("slram: Failed to register new device\n");
iounmap(((slram_priv_t *)(*curmtd)->mtdinfo->priv)->start);
kfree((*curmtd)->mtdinfo->priv);
kfree((*curmtd)->mtdinfo);
return(-EAGAIN);
}
T("slram: Registered device %s from %luKiB to %luKiB\n", name,
(start / 1024), ((start + length) / 1024));
T("slram: Mapped from 0x%p to 0x%p\n",
((slram_priv_t *)(*curmtd)->mtdinfo->priv)->start,
((slram_priv_t *)(*curmtd)->mtdinfo->priv)->end);
return(0);
}
static void unregister_devices(void)
{
slram_mtd_list_t *nextitem;
while (slram_mtdlist) {
nextitem = slram_mtdlist->next;
mtd_device_unregister(slram_mtdlist->mtdinfo);
iounmap(((slram_priv_t *)slram_mtdlist->mtdinfo->priv)->start);
kfree(slram_mtdlist->mtdinfo->priv);
kfree(slram_mtdlist->mtdinfo);
kfree(slram_mtdlist);
slram_mtdlist = nextitem;
}
}
static unsigned long handle_unit(unsigned long value, char *unit)
{
if ((*unit == 'M') || (*unit == 'm')) {
return(value * 1024 * 1024);
} else if ((*unit == 'K') || (*unit == 'k')) {
return(value * 1024);
}
return(value);
}
static int parse_cmdline(char *devname, char *szstart, char *szlength)
{
char *buffer;
unsigned long devstart;
unsigned long devlength;
if ((!devname) || (!szstart) || (!szlength)) {
unregister_devices();
return(-EINVAL);
}
devstart = simple_strtoul(szstart, &buffer, 0);
devstart = handle_unit(devstart, buffer);
if (*(szlength) != '+') {
devlength = simple_strtoul(szlength, &buffer, 0);
devlength = handle_unit(devlength, buffer) - devstart;
if (devlength < devstart)
goto err_out;
devlength -= devstart;
} else {
devlength = simple_strtoul(szlength + 1, &buffer, 0);
devlength = handle_unit(devlength, buffer);
}
T("slram: devname=%s, devstart=0x%lx, devlength=0x%lx\n",
devname, devstart, devlength);
if (devlength % SLRAM_BLK_SZ != 0)
goto err_out;
if ((devstart = register_device(devname, devstart, devlength))){
unregister_devices();
return((int)devstart);
}
return(0);
err_out:
E("slram: Illegal length parameter.\n");
return(-EINVAL);
}
static int __init mtd_slram_setup(char *str)
{
map = str;
return(1);
}
static int __init init_slram(void)
{
char *devname;
int i;
#ifndef MODULE
char *devstart;
char *devlength;
i = 0;
if (!map) {
E("slram: not enough parameters.\n");
return(-EINVAL);
}
while (map) {
devname = devstart = devlength = NULL;
if (!(devname = strsep(&map, ","))) {
E("slram: No devicename specified.\n");
break;
}
T("slram: devname = %s\n", devname);
if ((!map) || (!(devstart = strsep(&map, ",")))) {
E("slram: No devicestart specified.\n");
}
T("slram: devstart = %s\n", devstart);
if ((!map) || (!(devlength = strsep(&map, ",")))) {
E("slram: No devicelength / -end specified.\n");
}
T("slram: devlength = %s\n", devlength);
if (parse_cmdline(devname, devstart, devlength) != 0) {
return(-EINVAL);
}
}
#else
int count;
for (count = 0; count < SLRAM_MAX_DEVICES_PARAMS && map[count];
count++) {
}
if ((count % 3 != 0) || (count == 0)) {
E("slram: not enough parameters.\n");
return(-EINVAL);
}
for (i = 0; i < (count / 3); i++) {
devname = map[i * 3];
if (parse_cmdline(devname, map[i * 3 + 1], map[i * 3 + 2])!=0) {
return(-EINVAL);
}
}
#endif
return(0);
}
static void __exit cleanup_slram(void)
{
unregister_devices();
}
