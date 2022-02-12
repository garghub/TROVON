int qib_eeprom_read(struct qib_devdata *dd, u8 eeprom_offset,
void *buff, int len)
{
int ret;
ret = mutex_lock_interruptible(&dd->eep_lock);
if (!ret) {
ret = qib_twsi_reset(dd);
if (ret)
qib_dev_err(dd, "EEPROM Reset for read failed\n");
else
ret = qib_twsi_blk_rd(dd, dd->twsi_eeprom_dev,
eeprom_offset, buff, len);
mutex_unlock(&dd->eep_lock);
}
return ret;
}
static int eeprom_write_with_enable(struct qib_devdata *dd, u8 offset,
const void *buf, int len)
{
int ret, pwen;
pwen = dd->f_eeprom_wen(dd, 1);
ret = qib_twsi_reset(dd);
if (ret)
qib_dev_err(dd, "EEPROM Reset for write failed\n");
else
ret = qib_twsi_blk_wr(dd, dd->twsi_eeprom_dev,
offset, buf, len);
dd->f_eeprom_wen(dd, pwen);
return ret;
}
int qib_eeprom_write(struct qib_devdata *dd, u8 eeprom_offset,
const void *buff, int len)
{
int ret;
ret = mutex_lock_interruptible(&dd->eep_lock);
if (!ret) {
ret = eeprom_write_with_enable(dd, eeprom_offset, buff, len);
mutex_unlock(&dd->eep_lock);
}
return ret;
}
static u8 flash_csum(struct qib_flash *ifp, int adjust)
{
u8 *ip = (u8 *) ifp;
u8 csum = 0, len;
len = ifp->if_length;
if (len > sizeof(struct qib_flash))
len = sizeof(struct qib_flash);
while (len--)
csum += *ip++;
csum -= ifp->if_csum;
csum = ~csum;
if (adjust)
ifp->if_csum = csum;
return csum;
}
void qib_get_eeprom_info(struct qib_devdata *dd)
{
void *buf;
struct qib_flash *ifp;
__be64 guid;
int len, eep_stat;
u8 csum, *bguid;
int t = dd->unit;
struct qib_devdata *dd0 = qib_lookup(0);
if (t && dd0->nguid > 1 && t <= dd0->nguid) {
u8 oguid;
dd->base_guid = dd0->base_guid;
bguid = (u8 *) &dd->base_guid;
oguid = bguid[7];
bguid[7] += t;
if (oguid > bguid[7]) {
if (bguid[6] == 0xff) {
if (bguid[5] == 0xff) {
qib_dev_err(dd,
"Can't set %s GUID from base, wraps to OUI!\n",
qib_get_unit_name(t));
dd->base_guid = 0;
goto bail;
}
bguid[5]++;
}
bguid[6]++;
}
dd->nguid = 1;
goto bail;
}
len = sizeof(struct qib_flash);
buf = vmalloc(len);
if (!buf)
goto bail;
eep_stat = qib_eeprom_read(dd, 0, buf, len);
if (eep_stat) {
qib_dev_err(dd, "Failed reading GUID from eeprom\n");
goto done;
}
ifp = (struct qib_flash *)buf;
csum = flash_csum(ifp, 0);
if (csum != ifp->if_csum) {
qib_devinfo(dd->pcidev,
"Bad I2C flash checksum: 0x%x, not 0x%x\n",
csum, ifp->if_csum);
goto done;
}
if (*(__be64 *) ifp->if_guid == cpu_to_be64(0) ||
*(__be64 *) ifp->if_guid == ~cpu_to_be64(0)) {
qib_dev_err(dd,
"Invalid GUID %llx from flash; ignoring\n",
*(unsigned long long *) ifp->if_guid);
goto done;
}
if (*(u64 *) ifp->if_guid == 0x100007511000000ULL)
qib_devinfo(dd->pcidev,
"Warning, GUID %llx is default, probably not correct!\n",
*(unsigned long long *) ifp->if_guid);
bguid = ifp->if_guid;
if (!bguid[0] && !bguid[1] && !bguid[2]) {
bguid[1] = bguid[3];
bguid[2] = bguid[4];
bguid[3] = 0;
bguid[4] = 0;
guid = *(__be64 *) ifp->if_guid;
} else
guid = *(__be64 *) ifp->if_guid;
dd->base_guid = guid;
dd->nguid = ifp->if_numguid;
if ((ifp->if_fversion > 1) && ifp->if_sprefix[0] &&
((u8 *) ifp->if_sprefix)[0] != 0xFF) {
char *snp = dd->serial;
memcpy(snp, ifp->if_sprefix, sizeof(ifp->if_sprefix));
snp[sizeof(ifp->if_sprefix)] = '\0';
len = strlen(snp);
snp += len;
len = sizeof(dd->serial) - len;
if (len > sizeof(ifp->if_serial))
len = sizeof(ifp->if_serial);
memcpy(snp, ifp->if_serial, len);
} else {
memcpy(dd->serial, ifp->if_serial, sizeof(ifp->if_serial));
}
if (!strstr(ifp->if_comment, "Tested successfully"))
qib_dev_err(dd,
"Board SN %s did not pass functional test: %s\n",
dd->serial, ifp->if_comment);
done:
vfree(buf);
bail:;
}
