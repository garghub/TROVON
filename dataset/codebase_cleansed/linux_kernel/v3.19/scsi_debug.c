static unsigned int scsi_debug_lbp(void)
{
return ((0 == scsi_debug_fake_rw) &&
(scsi_debug_lbpu | scsi_debug_lbpws | scsi_debug_lbpws10));
}
static void *fake_store(unsigned long long lba)
{
lba = do_div(lba, sdebug_store_sectors);
return fake_storep + lba * scsi_debug_sector_size;
}
static struct sd_dif_tuple *dif_store(sector_t sector)
{
sector = do_div(sector, sdebug_store_sectors);
return dif_storep + sector;
}
static void sdebug_max_tgts_luns(void)
{
struct sdebug_host_info *sdbg_host;
struct Scsi_Host *hpnt;
spin_lock(&sdebug_host_list_lock);
list_for_each_entry(sdbg_host, &sdebug_host_list, host_list) {
hpnt = sdbg_host->shost;
if ((hpnt->this_id >= 0) &&
(scsi_debug_num_tgts > hpnt->this_id))
hpnt->max_id = scsi_debug_num_tgts + 1;
else
hpnt->max_id = scsi_debug_num_tgts;
hpnt->max_lun = SAM2_WLUN_REPORT_LUNS;
}
spin_unlock(&sdebug_host_list_lock);
}
static void
mk_sense_invalid_fld(struct scsi_cmnd *scp, enum sdeb_cmd_data c_d,
int in_byte, int in_bit)
{
unsigned char *sbuff;
u8 sks[4];
int sl, asc;
sbuff = scp->sense_buffer;
if (!sbuff) {
sdev_printk(KERN_ERR, scp->device,
"%s: sense_buffer is NULL\n", __func__);
return;
}
asc = c_d ? INVALID_FIELD_IN_CDB : INVALID_FIELD_IN_PARAM_LIST;
memset(sbuff, 0, SCSI_SENSE_BUFFERSIZE);
scsi_build_sense_buffer(scsi_debug_dsense, sbuff, ILLEGAL_REQUEST,
asc, 0);
memset(sks, 0, sizeof(sks));
sks[0] = 0x80;
if (c_d)
sks[0] |= 0x40;
if (in_bit >= 0) {
sks[0] |= 0x8;
sks[0] |= 0x7 & in_bit;
}
put_unaligned_be16(in_byte, sks + 1);
if (scsi_debug_dsense) {
sl = sbuff[7] + 8;
sbuff[7] = sl;
sbuff[sl] = 0x2;
sbuff[sl + 1] = 0x6;
memcpy(sbuff + sl + 4, sks, 3);
} else
memcpy(sbuff + 15, sks, 3);
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
sdev_printk(KERN_INFO, scp->device, "%s: [sense_key,asc,ascq"
"]: [0x5,0x%x,0x0] %c byte=%d, bit=%d\n",
my_name, asc, c_d ? 'C' : 'D', in_byte, in_bit);
}
static void mk_sense_buffer(struct scsi_cmnd *scp, int key, int asc, int asq)
{
unsigned char *sbuff;
sbuff = scp->sense_buffer;
if (!sbuff) {
sdev_printk(KERN_ERR, scp->device,
"%s: sense_buffer is NULL\n", __func__);
return;
}
memset(sbuff, 0, SCSI_SENSE_BUFFERSIZE);
scsi_build_sense_buffer(scsi_debug_dsense, sbuff, key, asc, asq);
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
sdev_printk(KERN_INFO, scp->device,
"%s: [sense_key,asc,ascq]: [0x%x,0x%x,0x%x]\n",
my_name, key, asc, asq);
}
static void
mk_sense_invalid_opcode(struct scsi_cmnd *scp)
{
mk_sense_buffer(scp, ILLEGAL_REQUEST, INVALID_OPCODE, 0);
}
static int scsi_debug_ioctl(struct scsi_device *dev, int cmd, void __user *arg)
{
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts) {
if (0x1261 == cmd)
sdev_printk(KERN_INFO, dev,
"%s: BLKFLSBUF [0x1261]\n", __func__);
else if (0x5331 == cmd)
sdev_printk(KERN_INFO, dev,
"%s: CDROM_GET_CAPABILITY [0x5331]\n",
__func__);
else
sdev_printk(KERN_INFO, dev, "%s: cmd=0x%x\n",
__func__, cmd);
}
return -EINVAL;
}
static int check_readiness(struct scsi_cmnd *SCpnt, int uas_only,
struct sdebug_dev_info * devip)
{
int k;
bool debug = !!(SCSI_DEBUG_OPT_NOISE & scsi_debug_opts);
k = find_first_bit(devip->uas_bm, SDEBUG_NUM_UAS);
if (k != SDEBUG_NUM_UAS) {
const char *cp = NULL;
switch (k) {
case SDEBUG_UA_POR:
mk_sense_buffer(SCpnt, UNIT_ATTENTION,
UA_RESET_ASC, POWER_ON_RESET_ASCQ);
if (debug)
cp = "power on reset";
break;
case SDEBUG_UA_BUS_RESET:
mk_sense_buffer(SCpnt, UNIT_ATTENTION,
UA_RESET_ASC, BUS_RESET_ASCQ);
if (debug)
cp = "bus reset";
break;
case SDEBUG_UA_MODE_CHANGED:
mk_sense_buffer(SCpnt, UNIT_ATTENTION,
UA_CHANGED_ASC, MODE_CHANGED_ASCQ);
if (debug)
cp = "mode parameters changed";
break;
case SDEBUG_UA_CAPACITY_CHANGED:
mk_sense_buffer(SCpnt, UNIT_ATTENTION,
UA_CHANGED_ASC, CAPACITY_CHANGED_ASCQ);
if (debug)
cp = "capacity data changed";
break;
default:
pr_warn("%s: unexpected unit attention code=%d\n",
__func__, k);
if (debug)
cp = "unknown";
break;
}
clear_bit(k, devip->uas_bm);
if (debug)
sdev_printk(KERN_INFO, SCpnt->device,
"%s reports: Unit attention: %s\n",
my_name, cp);
return check_condition_result;
}
if ((UAS_TUR == uas_only) && devip->stopped) {
mk_sense_buffer(SCpnt, NOT_READY, LOGICAL_UNIT_NOT_READY,
0x2);
if (debug)
sdev_printk(KERN_INFO, SCpnt->device,
"%s reports: Not ready: %s\n", my_name,
"initializing command required");
return check_condition_result;
}
return 0;
}
static int fill_from_dev_buffer(struct scsi_cmnd *scp, unsigned char *arr,
int arr_len)
{
int act_len;
struct scsi_data_buffer *sdb = scsi_in(scp);
if (!sdb->length)
return 0;
if (!(scsi_bidi_cmnd(scp) || scp->sc_data_direction == DMA_FROM_DEVICE))
return (DID_ERROR << 16);
act_len = sg_copy_from_buffer(sdb->table.sgl, sdb->table.nents,
arr, arr_len);
sdb->resid = scsi_bufflen(scp) - act_len;
return 0;
}
static int fetch_to_dev_buffer(struct scsi_cmnd *scp, unsigned char *arr,
int arr_len)
{
if (!scsi_bufflen(scp))
return 0;
if (!(scsi_bidi_cmnd(scp) || scp->sc_data_direction == DMA_TO_DEVICE))
return -1;
return scsi_sg_copy_to_buffer(scp, arr, arr_len);
}
static int inquiry_evpd_83(unsigned char * arr, int port_group_id,
int target_dev_id, int dev_id_num,
const char * dev_id_str,
int dev_id_str_len)
{
int num, port_a;
char b[32];
port_a = target_dev_id + 1;
arr[0] = 0x2;
arr[1] = 0x1;
arr[2] = 0x0;
memcpy(&arr[4], inq_vendor_id, 8);
memcpy(&arr[12], inq_product_id, 16);
memcpy(&arr[28], dev_id_str, dev_id_str_len);
num = 8 + 16 + dev_id_str_len;
arr[3] = num;
num += 4;
if (dev_id_num >= 0) {
arr[num++] = 0x1;
arr[num++] = 0x3;
arr[num++] = 0x0;
arr[num++] = 0x8;
arr[num++] = 0x53;
arr[num++] = 0x33;
arr[num++] = 0x33;
arr[num++] = 0x30;
arr[num++] = (dev_id_num >> 24);
arr[num++] = (dev_id_num >> 16) & 0xff;
arr[num++] = (dev_id_num >> 8) & 0xff;
arr[num++] = dev_id_num & 0xff;
arr[num++] = 0x61;
arr[num++] = 0x94;
arr[num++] = 0x0;
arr[num++] = 0x4;
arr[num++] = 0x0;
arr[num++] = 0x0;
arr[num++] = 0x0;
arr[num++] = 0x1;
}
arr[num++] = 0x61;
arr[num++] = 0x93;
arr[num++] = 0x0;
arr[num++] = 0x8;
arr[num++] = 0x52;
arr[num++] = 0x22;
arr[num++] = 0x22;
arr[num++] = 0x20;
arr[num++] = (port_a >> 24);
arr[num++] = (port_a >> 16) & 0xff;
arr[num++] = (port_a >> 8) & 0xff;
arr[num++] = port_a & 0xff;
arr[num++] = 0x61;
arr[num++] = 0x95;
arr[num++] = 0x0;
arr[num++] = 0x4;
arr[num++] = 0;
arr[num++] = 0;
arr[num++] = (port_group_id >> 8) & 0xff;
arr[num++] = port_group_id & 0xff;
arr[num++] = 0x61;
arr[num++] = 0xa3;
arr[num++] = 0x0;
arr[num++] = 0x8;
arr[num++] = 0x52;
arr[num++] = 0x22;
arr[num++] = 0x22;
arr[num++] = 0x20;
arr[num++] = (target_dev_id >> 24);
arr[num++] = (target_dev_id >> 16) & 0xff;
arr[num++] = (target_dev_id >> 8) & 0xff;
arr[num++] = target_dev_id & 0xff;
arr[num++] = 0x63;
arr[num++] = 0xa8;
arr[num++] = 0x0;
arr[num++] = 24;
memcpy(arr + num, "naa.52222220", 12);
num += 12;
snprintf(b, sizeof(b), "%08X", target_dev_id);
memcpy(arr + num, b, 8);
num += 8;
memset(arr + num, 0, 4);
num += 4;
return num;
}
static int inquiry_evpd_84(unsigned char * arr)
{
memcpy(arr, vpd84_data, sizeof(vpd84_data));
return sizeof(vpd84_data);
}
static int inquiry_evpd_85(unsigned char * arr)
{
int num = 0;
const char * na1 = "https://www.kernel.org/config";
const char * na2 = "http://www.kernel.org/log";
int plen, olen;
arr[num++] = 0x1;
arr[num++] = 0x0;
arr[num++] = 0x0;
olen = strlen(na1);
plen = olen + 1;
if (plen % 4)
plen = ((plen / 4) + 1) * 4;
arr[num++] = plen;
memcpy(arr + num, na1, olen);
memset(arr + num + olen, 0, plen - olen);
num += plen;
arr[num++] = 0x4;
arr[num++] = 0x0;
arr[num++] = 0x0;
olen = strlen(na2);
plen = olen + 1;
if (plen % 4)
plen = ((plen / 4) + 1) * 4;
arr[num++] = plen;
memcpy(arr + num, na2, olen);
memset(arr + num + olen, 0, plen - olen);
num += plen;
return num;
}
static int inquiry_evpd_88(unsigned char * arr, int target_dev_id)
{
int num = 0;
int port_a, port_b;
port_a = target_dev_id + 1;
port_b = port_a + 1;
arr[num++] = 0x0;
arr[num++] = 0x0;
arr[num++] = 0x0;
arr[num++] = 0x1;
memset(arr + num, 0, 6);
num += 6;
arr[num++] = 0x0;
arr[num++] = 12;
arr[num++] = 0x61;
arr[num++] = 0x93;
arr[num++] = 0x0;
arr[num++] = 0x8;
arr[num++] = 0x52;
arr[num++] = 0x22;
arr[num++] = 0x22;
arr[num++] = 0x20;
arr[num++] = (port_a >> 24);
arr[num++] = (port_a >> 16) & 0xff;
arr[num++] = (port_a >> 8) & 0xff;
arr[num++] = port_a & 0xff;
arr[num++] = 0x0;
arr[num++] = 0x0;
arr[num++] = 0x0;
arr[num++] = 0x2;
memset(arr + num, 0, 6);
num += 6;
arr[num++] = 0x0;
arr[num++] = 12;
arr[num++] = 0x61;
arr[num++] = 0x93;
arr[num++] = 0x0;
arr[num++] = 0x8;
arr[num++] = 0x52;
arr[num++] = 0x22;
arr[num++] = 0x22;
arr[num++] = 0x20;
arr[num++] = (port_b >> 24);
arr[num++] = (port_b >> 16) & 0xff;
arr[num++] = (port_b >> 8) & 0xff;
arr[num++] = port_b & 0xff;
return num;
}
static int inquiry_evpd_89(unsigned char * arr)
{
memcpy(arr, vpd89_data, sizeof(vpd89_data));
return sizeof(vpd89_data);
}
static int inquiry_evpd_b0(unsigned char * arr)
{
unsigned int gran;
memcpy(arr, vpdb0_data, sizeof(vpdb0_data));
gran = 1 << scsi_debug_physblk_exp;
arr[2] = (gran >> 8) & 0xff;
arr[3] = gran & 0xff;
if (sdebug_store_sectors > 0x400) {
arr[4] = (sdebug_store_sectors >> 24) & 0xff;
arr[5] = (sdebug_store_sectors >> 16) & 0xff;
arr[6] = (sdebug_store_sectors >> 8) & 0xff;
arr[7] = sdebug_store_sectors & 0xff;
}
put_unaligned_be32(scsi_debug_opt_blks, &arr[8]);
if (scsi_debug_lbpu) {
put_unaligned_be32(scsi_debug_unmap_max_blocks, &arr[16]);
put_unaligned_be32(scsi_debug_unmap_max_desc, &arr[20]);
}
if (scsi_debug_unmap_alignment) {
put_unaligned_be32(scsi_debug_unmap_alignment, &arr[28]);
arr[28] |= 0x80;
}
put_unaligned_be32(scsi_debug_unmap_granularity, &arr[24]);
put_unaligned_be64(scsi_debug_write_same_length, &arr[32]);
return 0x3c;
return sizeof(vpdb0_data);
}
static int inquiry_evpd_b1(unsigned char *arr)
{
memset(arr, 0, 0x3c);
arr[0] = 0;
arr[1] = 1;
arr[2] = 0;
arr[3] = 5;
return 0x3c;
}
static int inquiry_evpd_b2(unsigned char *arr)
{
memset(arr, 0, 0x4);
arr[0] = 0;
if (scsi_debug_lbpu)
arr[1] = 1 << 7;
if (scsi_debug_lbpws)
arr[1] |= 1 << 6;
if (scsi_debug_lbpws10)
arr[1] |= 1 << 5;
if (scsi_debug_lbprz)
arr[1] |= 1 << 2;
return 0x4;
}
static int resp_inquiry(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
unsigned char pq_pdt;
unsigned char * arr;
unsigned char *cmd = scp->cmnd;
int alloc_len, n, ret;
bool have_wlun;
alloc_len = (cmd[3] << 8) + cmd[4];
arr = kzalloc(SDEBUG_MAX_INQ_ARR_SZ, GFP_ATOMIC);
if (! arr)
return DID_REQUEUE << 16;
have_wlun = (scp->device->lun == SAM2_WLUN_REPORT_LUNS);
if (have_wlun)
pq_pdt = 0x1e;
else if (scsi_debug_no_lun_0 && (0 == devip->lun))
pq_pdt = 0x7f;
else
pq_pdt = (scsi_debug_ptype & 0x1f);
arr[0] = pq_pdt;
if (0x2 & cmd[1]) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 1, 1);
kfree(arr);
return check_condition_result;
} else if (0x1 & cmd[1]) {
int lu_id_num, port_group_id, target_dev_id, len;
char lu_id_str[6];
int host_no = devip->sdbg_host->shost->host_no;
port_group_id = (((host_no + 1) & 0x7f) << 8) +
(devip->channel & 0x7f);
if (0 == scsi_debug_vpd_use_hostno)
host_no = 0;
lu_id_num = have_wlun ? -1 : (((host_no + 1) * 2000) +
(devip->target * 1000) + devip->lun);
target_dev_id = ((host_no + 1) * 2000) +
(devip->target * 1000) - 3;
len = scnprintf(lu_id_str, 6, "%d", lu_id_num);
if (0 == cmd[2]) {
arr[1] = cmd[2];
n = 4;
arr[n++] = 0x0;
arr[n++] = 0x80;
arr[n++] = 0x83;
arr[n++] = 0x84;
arr[n++] = 0x85;
arr[n++] = 0x86;
arr[n++] = 0x87;
arr[n++] = 0x88;
arr[n++] = 0x89;
arr[n++] = 0xb0;
arr[n++] = 0xb1;
if (scsi_debug_lbp())
arr[n++] = 0xb2;
arr[3] = n - 4;
} else if (0x80 == cmd[2]) {
arr[1] = cmd[2];
arr[3] = len;
memcpy(&arr[4], lu_id_str, len);
} else if (0x83 == cmd[2]) {
arr[1] = cmd[2];
arr[3] = inquiry_evpd_83(&arr[4], port_group_id,
target_dev_id, lu_id_num,
lu_id_str, len);
} else if (0x84 == cmd[2]) {
arr[1] = cmd[2];
arr[3] = inquiry_evpd_84(&arr[4]);
} else if (0x85 == cmd[2]) {
arr[1] = cmd[2];
arr[3] = inquiry_evpd_85(&arr[4]);
} else if (0x86 == cmd[2]) {
arr[1] = cmd[2];
arr[3] = 0x3c;
if (scsi_debug_dif == SD_DIF_TYPE3_PROTECTION)
arr[4] = 0x4;
else if (scsi_debug_dif)
arr[4] = 0x5;
else
arr[4] = 0x0;
arr[5] = 0x7;
} else if (0x87 == cmd[2]) {
arr[1] = cmd[2];
arr[3] = 0x8;
arr[4] = 0x2;
arr[6] = 0x80;
arr[8] = 0x18;
arr[10] = 0x82;
} else if (0x88 == cmd[2]) {
arr[1] = cmd[2];
arr[3] = inquiry_evpd_88(&arr[4], target_dev_id);
} else if (0x89 == cmd[2]) {
arr[1] = cmd[2];
n = inquiry_evpd_89(&arr[4]);
arr[2] = (n >> 8);
arr[3] = (n & 0xff);
} else if (0xb0 == cmd[2]) {
arr[1] = cmd[2];
arr[3] = inquiry_evpd_b0(&arr[4]);
} else if (0xb1 == cmd[2]) {
arr[1] = cmd[2];
arr[3] = inquiry_evpd_b1(&arr[4]);
} else if (0xb2 == cmd[2]) {
arr[1] = cmd[2];
arr[3] = inquiry_evpd_b2(&arr[4]);
} else {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 2, -1);
kfree(arr);
return check_condition_result;
}
len = min(((arr[2] << 8) + arr[3]) + 4, alloc_len);
ret = fill_from_dev_buffer(scp, arr,
min(len, SDEBUG_MAX_INQ_ARR_SZ));
kfree(arr);
return ret;
}
arr[1] = scsi_debug_removable ? 0x80 : 0;
arr[2] = scsi_debug_scsi_level;
arr[3] = 2;
arr[4] = SDEBUG_LONG_INQ_SZ - 5;
arr[5] = scsi_debug_dif ? 1 : 0;
if (0 == scsi_debug_vpd_use_hostno)
arr[5] = 0x10;
arr[6] = 0x10;
arr[7] = 0xa;
memcpy(&arr[8], inq_vendor_id, 8);
memcpy(&arr[16], inq_product_id, 16);
memcpy(&arr[32], inq_product_rev, 4);
arr[58] = 0x0; arr[59] = 0xa2;
arr[60] = 0x4; arr[61] = 0x68;
n = 62;
if (scsi_debug_ptype == 0) {
arr[n++] = 0x4; arr[n++] = 0xc5;
} else if (scsi_debug_ptype == 1) {
arr[n++] = 0x5; arr[n++] = 0x25;
}
arr[n++] = 0x20; arr[n++] = 0xe6;
ret = fill_from_dev_buffer(scp, arr,
min(alloc_len, SDEBUG_LONG_INQ_SZ));
kfree(arr);
return ret;
}
static int resp_requests(struct scsi_cmnd * scp,
struct sdebug_dev_info * devip)
{
unsigned char * sbuff;
unsigned char *cmd = scp->cmnd;
unsigned char arr[SCSI_SENSE_BUFFERSIZE];
bool dsense, want_dsense;
int len = 18;
memset(arr, 0, sizeof(arr));
dsense = !!(cmd[1] & 1);
want_dsense = dsense || scsi_debug_dsense;
sbuff = scp->sense_buffer;
if ((iec_m_pg[2] & 0x4) && (6 == (iec_m_pg[3] & 0xf))) {
if (dsense) {
arr[0] = 0x72;
arr[1] = 0x0;
arr[2] = THRESHOLD_EXCEEDED;
arr[3] = 0xff;
len = 8;
} else {
arr[0] = 0x70;
arr[2] = 0x0;
arr[7] = 0xa;
arr[12] = THRESHOLD_EXCEEDED;
arr[13] = 0xff;
}
} else {
memcpy(arr, sbuff, SCSI_SENSE_BUFFERSIZE);
if (arr[0] >= 0x70 && dsense == scsi_debug_dsense)
;
else if (arr[0] <= 0x70) {
if (dsense) {
memset(arr, 0, 8);
arr[0] = 0x72;
len = 8;
} else {
memset(arr, 0, 18);
arr[0] = 0x70;
arr[7] = 0xa;
}
} else if (dsense) {
memset(arr, 0, 8);
arr[0] = 0x72;
arr[1] = sbuff[2];
arr[2] = sbuff[12];
arr[3] = sbuff[13];
len = 8;
} else {
memset(arr, 0, 18);
arr[0] = 0x70;
arr[2] = sbuff[1];
arr[7] = 0xa;
arr[12] = sbuff[1];
arr[13] = sbuff[3];
}
}
mk_sense_buffer(scp, 0, NO_ADDITIONAL_SENSE, 0);
return fill_from_dev_buffer(scp, arr, len);
}
static int resp_start_stop(struct scsi_cmnd * scp,
struct sdebug_dev_info * devip)
{
unsigned char *cmd = scp->cmnd;
int power_cond, start;
power_cond = (cmd[4] & 0xf0) >> 4;
if (power_cond) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 4, 7);
return check_condition_result;
}
start = cmd[4] & 1;
if (start == devip->stopped)
devip->stopped = !start;
return 0;
}
static sector_t get_sdebug_capacity(void)
{
if (scsi_debug_virtual_gb > 0)
return (sector_t)scsi_debug_virtual_gb *
(1073741824 / scsi_debug_sector_size);
else
return sdebug_store_sectors;
}
static int resp_readcap(struct scsi_cmnd * scp,
struct sdebug_dev_info * devip)
{
unsigned char arr[SDEBUG_READCAP_ARR_SZ];
unsigned int capac;
sdebug_capacity = get_sdebug_capacity();
memset(arr, 0, SDEBUG_READCAP_ARR_SZ);
if (sdebug_capacity < 0xffffffff) {
capac = (unsigned int)sdebug_capacity - 1;
arr[0] = (capac >> 24);
arr[1] = (capac >> 16) & 0xff;
arr[2] = (capac >> 8) & 0xff;
arr[3] = capac & 0xff;
} else {
arr[0] = 0xff;
arr[1] = 0xff;
arr[2] = 0xff;
arr[3] = 0xff;
}
arr[6] = (scsi_debug_sector_size >> 8) & 0xff;
arr[7] = scsi_debug_sector_size & 0xff;
return fill_from_dev_buffer(scp, arr, SDEBUG_READCAP_ARR_SZ);
}
static int resp_readcap16(struct scsi_cmnd * scp,
struct sdebug_dev_info * devip)
{
unsigned char *cmd = scp->cmnd;
unsigned char arr[SDEBUG_READCAP16_ARR_SZ];
unsigned long long capac;
int k, alloc_len;
alloc_len = ((cmd[10] << 24) + (cmd[11] << 16) + (cmd[12] << 8)
+ cmd[13]);
sdebug_capacity = get_sdebug_capacity();
memset(arr, 0, SDEBUG_READCAP16_ARR_SZ);
capac = sdebug_capacity - 1;
for (k = 0; k < 8; ++k, capac >>= 8)
arr[7 - k] = capac & 0xff;
arr[8] = (scsi_debug_sector_size >> 24) & 0xff;
arr[9] = (scsi_debug_sector_size >> 16) & 0xff;
arr[10] = (scsi_debug_sector_size >> 8) & 0xff;
arr[11] = scsi_debug_sector_size & 0xff;
arr[13] = scsi_debug_physblk_exp & 0xf;
arr[14] = (scsi_debug_lowest_aligned >> 8) & 0x3f;
if (scsi_debug_lbp()) {
arr[14] |= 0x80;
if (scsi_debug_lbprz)
arr[14] |= 0x40;
}
arr[15] = scsi_debug_lowest_aligned & 0xff;
if (scsi_debug_dif) {
arr[12] = (scsi_debug_dif - 1) << 1;
arr[12] |= 1;
}
return fill_from_dev_buffer(scp, arr,
min(alloc_len, SDEBUG_READCAP16_ARR_SZ));
}
static int resp_report_tgtpgs(struct scsi_cmnd * scp,
struct sdebug_dev_info * devip)
{
unsigned char *cmd = scp->cmnd;
unsigned char * arr;
int host_no = devip->sdbg_host->shost->host_no;
int n, ret, alen, rlen;
int port_group_a, port_group_b, port_a, port_b;
alen = ((cmd[6] << 24) + (cmd[7] << 16) + (cmd[8] << 8)
+ cmd[9]);
arr = kzalloc(SDEBUG_MAX_TGTPGS_ARR_SZ, GFP_ATOMIC);
if (! arr)
return DID_REQUEUE << 16;
port_a = 0x1;
port_b = 0x2;
port_group_a = (((host_no + 1) & 0x7f) << 8) +
(devip->channel & 0x7f);
port_group_b = (((host_no + 1) & 0x7f) << 8) +
(devip->channel & 0x7f) + 0x80;
n = 4;
if (0 == scsi_debug_vpd_use_hostno) {
arr[n++] = host_no % 3;
arr[n++] = 0x0F;
} else {
arr[n++] = 0x0;
arr[n++] = 0x01;
}
arr[n++] = (port_group_a >> 8) & 0xff;
arr[n++] = port_group_a & 0xff;
arr[n++] = 0;
arr[n++] = 0;
arr[n++] = 0;
arr[n++] = 0x1;
arr[n++] = 0;
arr[n++] = 0;
arr[n++] = (port_a >> 8) & 0xff;
arr[n++] = port_a & 0xff;
arr[n++] = 3;
arr[n++] = 0x08;
arr[n++] = (port_group_b >> 8) & 0xff;
arr[n++] = port_group_b & 0xff;
arr[n++] = 0;
arr[n++] = 0;
arr[n++] = 0;
arr[n++] = 0x1;
arr[n++] = 0;
arr[n++] = 0;
arr[n++] = (port_b >> 8) & 0xff;
arr[n++] = port_b & 0xff;
rlen = n - 4;
arr[0] = (rlen >> 24) & 0xff;
arr[1] = (rlen >> 16) & 0xff;
arr[2] = (rlen >> 8) & 0xff;
arr[3] = rlen & 0xff;
rlen = min(alen,n);
ret = fill_from_dev_buffer(scp, arr,
min(rlen, SDEBUG_MAX_TGTPGS_ARR_SZ));
kfree(arr);
return ret;
}
static int
resp_rsup_opcodes(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
bool rctd;
u8 reporting_opts, req_opcode, sdeb_i, supp;
u16 req_sa, u;
u32 alloc_len, a_len;
int k, offset, len, errsts, count, bump, na;
const struct opcode_info_t *oip;
const struct opcode_info_t *r_oip;
u8 *arr;
u8 *cmd = scp->cmnd;
rctd = !!(cmd[2] & 0x80);
reporting_opts = cmd[2] & 0x7;
req_opcode = cmd[3];
req_sa = get_unaligned_be16(cmd + 4);
alloc_len = get_unaligned_be32(cmd + 6);
if (alloc_len < 4 || alloc_len > 0xffff) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 6, -1);
return check_condition_result;
}
if (alloc_len > 8192)
a_len = 8192;
else
a_len = alloc_len;
arr = kzalloc((a_len < 256) ? 320 : a_len + 64, GFP_ATOMIC);
if (NULL == arr) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, INSUFF_RES_ASC,
INSUFF_RES_ASCQ);
return check_condition_result;
}
switch (reporting_opts) {
case 0:
for (count = 0, oip = opcode_info_arr;
oip->num_attached != 0xff; ++oip) {
if (F_INV_OP & oip->flags)
continue;
count += (oip->num_attached + 1);
}
bump = rctd ? 20 : 8;
put_unaligned_be32(count * bump, arr);
for (offset = 4, oip = opcode_info_arr;
oip->num_attached != 0xff && offset < a_len; ++oip) {
if (F_INV_OP & oip->flags)
continue;
na = oip->num_attached;
arr[offset] = oip->opcode;
put_unaligned_be16(oip->sa, arr + offset + 2);
if (rctd)
arr[offset + 5] |= 0x2;
if (FF_SA & oip->flags)
arr[offset + 5] |= 0x1;
put_unaligned_be16(oip->len_mask[0], arr + offset + 6);
if (rctd)
put_unaligned_be16(0xa, arr + offset + 8);
r_oip = oip;
for (k = 0, oip = oip->arrp; k < na; ++k, ++oip) {
if (F_INV_OP & oip->flags)
continue;
offset += bump;
arr[offset] = oip->opcode;
put_unaligned_be16(oip->sa, arr + offset + 2);
if (rctd)
arr[offset + 5] |= 0x2;
if (FF_SA & oip->flags)
arr[offset + 5] |= 0x1;
put_unaligned_be16(oip->len_mask[0],
arr + offset + 6);
if (rctd)
put_unaligned_be16(0xa,
arr + offset + 8);
}
oip = r_oip;
offset += bump;
}
break;
case 1:
case 2:
case 3:
sdeb_i = opcode_ind_arr[req_opcode];
oip = &opcode_info_arr[sdeb_i];
if (F_INV_OP & oip->flags) {
supp = 1;
offset = 4;
} else {
if (1 == reporting_opts) {
if (FF_SA & oip->flags) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB,
2, 2);
kfree(arr);
return check_condition_result;
}
req_sa = 0;
} else if (2 == reporting_opts &&
0 == (FF_SA & oip->flags)) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 4, -1);
kfree(arr);
return check_condition_result;
}
if (0 == (FF_SA & oip->flags) &&
req_opcode == oip->opcode)
supp = 3;
else if (0 == (FF_SA & oip->flags)) {
na = oip->num_attached;
for (k = 0, oip = oip->arrp; k < na;
++k, ++oip) {
if (req_opcode == oip->opcode)
break;
}
supp = (k >= na) ? 1 : 3;
} else if (req_sa != oip->sa) {
na = oip->num_attached;
for (k = 0, oip = oip->arrp; k < na;
++k, ++oip) {
if (req_sa == oip->sa)
break;
}
supp = (k >= na) ? 1 : 3;
} else
supp = 3;
if (3 == supp) {
u = oip->len_mask[0];
put_unaligned_be16(u, arr + 2);
arr[4] = oip->opcode;
for (k = 1; k < u; ++k)
arr[4 + k] = (k < 16) ?
oip->len_mask[k] : 0xff;
offset = 4 + u;
} else
offset = 4;
}
arr[1] = (rctd ? 0x80 : 0) | supp;
if (rctd) {
put_unaligned_be16(0xa, arr + offset);
offset += 12;
}
break;
default:
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 2, 2);
kfree(arr);
return check_condition_result;
}
offset = (offset < a_len) ? offset : a_len;
len = (offset < alloc_len) ? offset : alloc_len;
errsts = fill_from_dev_buffer(scp, arr, len);
kfree(arr);
return errsts;
}
static int
resp_rsup_tmfs(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
bool repd;
u32 alloc_len, len;
u8 arr[16];
u8 *cmd = scp->cmnd;
memset(arr, 0, sizeof(arr));
repd = !!(cmd[2] & 0x80);
alloc_len = get_unaligned_be32(cmd + 6);
if (alloc_len < 4) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 6, -1);
return check_condition_result;
}
arr[0] = 0xc8;
arr[1] = 0x1;
if (repd) {
arr[3] = 0xc;
len = 16;
} else
len = 4;
len = (len < alloc_len) ? len : alloc_len;
return fill_from_dev_buffer(scp, arr, len);
}
static int resp_err_recov_pg(unsigned char * p, int pcontrol, int target)
{
unsigned char err_recov_pg[] = {0x1, 0xa, 0xc0, 11, 240, 0, 0, 0,
5, 0, 0xff, 0xff};
memcpy(p, err_recov_pg, sizeof(err_recov_pg));
if (1 == pcontrol)
memset(p + 2, 0, sizeof(err_recov_pg) - 2);
return sizeof(err_recov_pg);
}
static int resp_disconnect_pg(unsigned char * p, int pcontrol, int target)
{
unsigned char disconnect_pg[] = {0x2, 0xe, 128, 128, 0, 10, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0};
memcpy(p, disconnect_pg, sizeof(disconnect_pg));
if (1 == pcontrol)
memset(p + 2, 0, sizeof(disconnect_pg) - 2);
return sizeof(disconnect_pg);
}
static int resp_format_pg(unsigned char * p, int pcontrol, int target)
{
unsigned char format_pg[] = {0x3, 0x16, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0x40, 0, 0, 0};
memcpy(p, format_pg, sizeof(format_pg));
p[10] = (sdebug_sectors_per >> 8) & 0xff;
p[11] = sdebug_sectors_per & 0xff;
p[12] = (scsi_debug_sector_size >> 8) & 0xff;
p[13] = scsi_debug_sector_size & 0xff;
if (scsi_debug_removable)
p[20] |= 0x20;
if (1 == pcontrol)
memset(p + 2, 0, sizeof(format_pg) - 2);
return sizeof(format_pg);
}
static int resp_caching_pg(unsigned char * p, int pcontrol, int target)
{
unsigned char ch_caching_pg[] = { 0x4, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned char d_caching_pg[] = {0x8, 18, 0x14, 0, 0xff, 0xff, 0, 0,
0xff, 0xff, 0xff, 0xff, 0x80, 0x14, 0, 0, 0, 0, 0, 0};
if (SCSI_DEBUG_OPT_N_WCE & scsi_debug_opts)
caching_pg[2] &= ~0x4;
memcpy(p, caching_pg, sizeof(caching_pg));
if (1 == pcontrol)
memcpy(p + 2, ch_caching_pg, sizeof(ch_caching_pg));
else if (2 == pcontrol)
memcpy(p, d_caching_pg, sizeof(d_caching_pg));
return sizeof(caching_pg);
}
static int resp_ctrl_m_pg(unsigned char * p, int pcontrol, int target)
{
unsigned char ch_ctrl_m_pg[] = { 0x6, 0, 0, 0, 0, 0,
0, 0, 0, 0};
unsigned char d_ctrl_m_pg[] = {0xa, 10, 2, 0, 0, 0, 0, 0,
0, 0, 0x2, 0x4b};
if (scsi_debug_dsense)
ctrl_m_pg[2] |= 0x4;
else
ctrl_m_pg[2] &= ~0x4;
if (scsi_debug_ato)
ctrl_m_pg[5] |= 0x80;
memcpy(p, ctrl_m_pg, sizeof(ctrl_m_pg));
if (1 == pcontrol)
memcpy(p + 2, ch_ctrl_m_pg, sizeof(ch_ctrl_m_pg));
else if (2 == pcontrol)
memcpy(p, d_ctrl_m_pg, sizeof(d_ctrl_m_pg));
return sizeof(ctrl_m_pg);
}
static int resp_iec_m_pg(unsigned char * p, int pcontrol, int target)
{
unsigned char ch_iec_m_pg[] = { 0x4, 0xf, 0, 0, 0, 0,
0, 0, 0x0, 0x0};
unsigned char d_iec_m_pg[] = {0x1c, 0xa, 0x08, 0, 0, 0, 0, 0,
0, 0, 0x0, 0x0};
memcpy(p, iec_m_pg, sizeof(iec_m_pg));
if (1 == pcontrol)
memcpy(p + 2, ch_iec_m_pg, sizeof(ch_iec_m_pg));
else if (2 == pcontrol)
memcpy(p, d_iec_m_pg, sizeof(d_iec_m_pg));
return sizeof(iec_m_pg);
}
static int resp_sas_sf_m_pg(unsigned char * p, int pcontrol, int target)
{
unsigned char sas_sf_m_pg[] = {0x19, 0x6,
0x6, 0x0, 0x7, 0xd0, 0x0, 0x0};
memcpy(p, sas_sf_m_pg, sizeof(sas_sf_m_pg));
if (1 == pcontrol)
memset(p + 2, 0, sizeof(sas_sf_m_pg) - 2);
return sizeof(sas_sf_m_pg);
}
static int resp_sas_pcd_m_spg(unsigned char * p, int pcontrol, int target,
int target_dev_id)
{
unsigned char sas_pcd_m_pg[] = {0x59, 0x1, 0, 0x64, 0, 0x6, 0, 2,
0, 0, 0, 0, 0x10, 0x9, 0x8, 0x0,
0x52, 0x22, 0x22, 0x20, 0x0, 0x0, 0x0, 0x0,
0x51, 0x11, 0x11, 0x10, 0x0, 0x0, 0x0, 0x1,
0x2, 0, 0, 0, 0, 0, 0, 0,
0x88, 0x99, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 0, 0, 0x10, 0x9, 0x8, 0x0,
0x52, 0x22, 0x22, 0x20, 0x0, 0x0, 0x0, 0x0,
0x51, 0x11, 0x11, 0x10, 0x0, 0x0, 0x0, 0x1,
0x3, 0, 0, 0, 0, 0, 0, 0,
0x88, 0x99, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
};
int port_a, port_b;
port_a = target_dev_id + 1;
port_b = port_a + 1;
memcpy(p, sas_pcd_m_pg, sizeof(sas_pcd_m_pg));
p[20] = (port_a >> 24);
p[21] = (port_a >> 16) & 0xff;
p[22] = (port_a >> 8) & 0xff;
p[23] = port_a & 0xff;
p[48 + 20] = (port_b >> 24);
p[48 + 21] = (port_b >> 16) & 0xff;
p[48 + 22] = (port_b >> 8) & 0xff;
p[48 + 23] = port_b & 0xff;
if (1 == pcontrol)
memset(p + 4, 0, sizeof(sas_pcd_m_pg) - 4);
return sizeof(sas_pcd_m_pg);
}
static int resp_sas_sha_m_spg(unsigned char * p, int pcontrol)
{
unsigned char sas_sha_m_pg[] = {0x59, 0x2, 0, 0xc, 0, 0x6, 0x10, 0,
0, 0, 0, 0, 0, 0, 0, 0,
};
memcpy(p, sas_sha_m_pg, sizeof(sas_sha_m_pg));
if (1 == pcontrol)
memset(p + 4, 0, sizeof(sas_sha_m_pg) - 4);
return sizeof(sas_sha_m_pg);
}
static int
resp_mode_sense(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
unsigned char dbd, llbaa;
int pcontrol, pcode, subpcode, bd_len;
unsigned char dev_spec;
int k, alloc_len, msense_6, offset, len, target_dev_id;
int target = scp->device->id;
unsigned char * ap;
unsigned char arr[SDEBUG_MAX_MSENSE_SZ];
unsigned char *cmd = scp->cmnd;
dbd = !!(cmd[1] & 0x8);
pcontrol = (cmd[2] & 0xc0) >> 6;
pcode = cmd[2] & 0x3f;
subpcode = cmd[3];
msense_6 = (MODE_SENSE == cmd[0]);
llbaa = msense_6 ? 0 : !!(cmd[1] & 0x10);
if ((0 == scsi_debug_ptype) && (0 == dbd))
bd_len = llbaa ? 16 : 8;
else
bd_len = 0;
alloc_len = msense_6 ? cmd[4] : ((cmd[7] << 8) | cmd[8]);
memset(arr, 0, SDEBUG_MAX_MSENSE_SZ);
if (0x3 == pcontrol) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, SAVING_PARAMS_UNSUP, 0);
return check_condition_result;
}
target_dev_id = ((devip->sdbg_host->shost->host_no + 1) * 2000) +
(devip->target * 1000) - 3;
if (0 == scsi_debug_ptype)
dev_spec = (DEV_READONLY(target) ? 0x80 : 0x0) | 0x10;
else
dev_spec = 0x0;
if (msense_6) {
arr[2] = dev_spec;
arr[3] = bd_len;
offset = 4;
} else {
arr[3] = dev_spec;
if (16 == bd_len)
arr[4] = 0x1;
arr[7] = bd_len;
offset = 8;
}
ap = arr + offset;
if ((bd_len > 0) && (!sdebug_capacity))
sdebug_capacity = get_sdebug_capacity();
if (8 == bd_len) {
if (sdebug_capacity > 0xfffffffe) {
ap[0] = 0xff;
ap[1] = 0xff;
ap[2] = 0xff;
ap[3] = 0xff;
} else {
ap[0] = (sdebug_capacity >> 24) & 0xff;
ap[1] = (sdebug_capacity >> 16) & 0xff;
ap[2] = (sdebug_capacity >> 8) & 0xff;
ap[3] = sdebug_capacity & 0xff;
}
ap[6] = (scsi_debug_sector_size >> 8) & 0xff;
ap[7] = scsi_debug_sector_size & 0xff;
offset += bd_len;
ap = arr + offset;
} else if (16 == bd_len) {
unsigned long long capac = sdebug_capacity;
for (k = 0; k < 8; ++k, capac >>= 8)
ap[7 - k] = capac & 0xff;
ap[12] = (scsi_debug_sector_size >> 24) & 0xff;
ap[13] = (scsi_debug_sector_size >> 16) & 0xff;
ap[14] = (scsi_debug_sector_size >> 8) & 0xff;
ap[15] = scsi_debug_sector_size & 0xff;
offset += bd_len;
ap = arr + offset;
}
if ((subpcode > 0x0) && (subpcode < 0xff) && (0x19 != pcode)) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 3, -1);
return check_condition_result;
}
switch (pcode) {
case 0x1:
len = resp_err_recov_pg(ap, pcontrol, target);
offset += len;
break;
case 0x2:
len = resp_disconnect_pg(ap, pcontrol, target);
offset += len;
break;
case 0x3:
len = resp_format_pg(ap, pcontrol, target);
offset += len;
break;
case 0x8:
len = resp_caching_pg(ap, pcontrol, target);
offset += len;
break;
case 0xa:
len = resp_ctrl_m_pg(ap, pcontrol, target);
offset += len;
break;
case 0x19:
if ((subpcode > 0x2) && (subpcode < 0xff)) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 3, -1);
return check_condition_result;
}
len = 0;
if ((0x0 == subpcode) || (0xff == subpcode))
len += resp_sas_sf_m_pg(ap + len, pcontrol, target);
if ((0x1 == subpcode) || (0xff == subpcode))
len += resp_sas_pcd_m_spg(ap + len, pcontrol, target,
target_dev_id);
if ((0x2 == subpcode) || (0xff == subpcode))
len += resp_sas_sha_m_spg(ap + len, pcontrol);
offset += len;
break;
case 0x1c:
len = resp_iec_m_pg(ap, pcontrol, target);
offset += len;
break;
case 0x3f:
if ((0 == subpcode) || (0xff == subpcode)) {
len = resp_err_recov_pg(ap, pcontrol, target);
len += resp_disconnect_pg(ap + len, pcontrol, target);
len += resp_format_pg(ap + len, pcontrol, target);
len += resp_caching_pg(ap + len, pcontrol, target);
len += resp_ctrl_m_pg(ap + len, pcontrol, target);
len += resp_sas_sf_m_pg(ap + len, pcontrol, target);
if (0xff == subpcode) {
len += resp_sas_pcd_m_spg(ap + len, pcontrol,
target, target_dev_id);
len += resp_sas_sha_m_spg(ap + len, pcontrol);
}
len += resp_iec_m_pg(ap + len, pcontrol, target);
} else {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 3, -1);
return check_condition_result;
}
offset += len;
break;
default:
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 2, 5);
return check_condition_result;
}
if (msense_6)
arr[0] = offset - 1;
else {
arr[0] = ((offset - 2) >> 8) & 0xff;
arr[1] = (offset - 2) & 0xff;
}
return fill_from_dev_buffer(scp, arr, min(alloc_len, offset));
}
static int
resp_mode_select(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
int pf, sp, ps, md_len, bd_len, off, spf, pg_len;
int param_len, res, mpage;
unsigned char arr[SDEBUG_MAX_MSELECT_SZ];
unsigned char *cmd = scp->cmnd;
int mselect6 = (MODE_SELECT == cmd[0]);
memset(arr, 0, sizeof(arr));
pf = cmd[1] & 0x10;
sp = cmd[1] & 0x1;
param_len = mselect6 ? cmd[4] : ((cmd[7] << 8) + cmd[8]);
if ((0 == pf) || sp || (param_len > SDEBUG_MAX_MSELECT_SZ)) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, mselect6 ? 4 : 7, -1);
return check_condition_result;
}
res = fetch_to_dev_buffer(scp, arr, param_len);
if (-1 == res)
return (DID_ERROR << 16);
else if ((res < param_len) &&
(SCSI_DEBUG_OPT_NOISE & scsi_debug_opts))
sdev_printk(KERN_INFO, scp->device,
"%s: cdb indicated=%d, IO sent=%d bytes\n",
__func__, param_len, res);
md_len = mselect6 ? (arr[0] + 1) : ((arr[0] << 8) + arr[1] + 2);
bd_len = mselect6 ? arr[3] : ((arr[6] << 8) + arr[7]);
if (md_len > 2) {
mk_sense_invalid_fld(scp, SDEB_IN_DATA, 0, -1);
return check_condition_result;
}
off = bd_len + (mselect6 ? 4 : 8);
mpage = arr[off] & 0x3f;
ps = !!(arr[off] & 0x80);
if (ps) {
mk_sense_invalid_fld(scp, SDEB_IN_DATA, off, 7);
return check_condition_result;
}
spf = !!(arr[off] & 0x40);
pg_len = spf ? ((arr[off + 2] << 8) + arr[off + 3] + 4) :
(arr[off + 1] + 2);
if ((pg_len + off) > param_len) {
mk_sense_buffer(scp, ILLEGAL_REQUEST,
PARAMETER_LIST_LENGTH_ERR, 0);
return check_condition_result;
}
switch (mpage) {
case 0x8:
if (caching_pg[1] == arr[off + 1]) {
memcpy(caching_pg + 2, arr + off + 2,
sizeof(caching_pg) - 2);
goto set_mode_changed_ua;
}
break;
case 0xa:
if (ctrl_m_pg[1] == arr[off + 1]) {
memcpy(ctrl_m_pg + 2, arr + off + 2,
sizeof(ctrl_m_pg) - 2);
scsi_debug_dsense = !!(ctrl_m_pg[2] & 0x4);
goto set_mode_changed_ua;
}
break;
case 0x1c:
if (iec_m_pg[1] == arr[off + 1]) {
memcpy(iec_m_pg + 2, arr + off + 2,
sizeof(iec_m_pg) - 2);
goto set_mode_changed_ua;
}
break;
default:
break;
}
mk_sense_invalid_fld(scp, SDEB_IN_DATA, off, 5);
return check_condition_result;
set_mode_changed_ua:
set_bit(SDEBUG_UA_MODE_CHANGED, devip->uas_bm);
return 0;
}
static int resp_temp_l_pg(unsigned char * arr)
{
unsigned char temp_l_pg[] = {0x0, 0x0, 0x3, 0x2, 0x0, 38,
0x0, 0x1, 0x3, 0x2, 0x0, 65,
};
memcpy(arr, temp_l_pg, sizeof(temp_l_pg));
return sizeof(temp_l_pg);
}
static int resp_ie_l_pg(unsigned char * arr)
{
unsigned char ie_l_pg[] = {0x0, 0x0, 0x3, 0x3, 0x0, 0x0, 38,
};
memcpy(arr, ie_l_pg, sizeof(ie_l_pg));
if (iec_m_pg[2] & 0x4) {
arr[4] = THRESHOLD_EXCEEDED;
arr[5] = 0xff;
}
return sizeof(ie_l_pg);
}
static int resp_log_sense(struct scsi_cmnd * scp,
struct sdebug_dev_info * devip)
{
int ppc, sp, pcontrol, pcode, subpcode, alloc_len, len, n;
unsigned char arr[SDEBUG_MAX_LSENSE_SZ];
unsigned char *cmd = scp->cmnd;
memset(arr, 0, sizeof(arr));
ppc = cmd[1] & 0x2;
sp = cmd[1] & 0x1;
if (ppc || sp) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 1, ppc ? 1 : 0);
return check_condition_result;
}
pcontrol = (cmd[2] & 0xc0) >> 6;
pcode = cmd[2] & 0x3f;
subpcode = cmd[3] & 0xff;
alloc_len = (cmd[7] << 8) + cmd[8];
arr[0] = pcode;
if (0 == subpcode) {
switch (pcode) {
case 0x0:
n = 4;
arr[n++] = 0x0;
arr[n++] = 0xd;
arr[n++] = 0x2f;
arr[3] = n - 4;
break;
case 0xd:
arr[3] = resp_temp_l_pg(arr + 4);
break;
case 0x2f:
arr[3] = resp_ie_l_pg(arr + 4);
break;
default:
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 2, 5);
return check_condition_result;
}
} else if (0xff == subpcode) {
arr[0] |= 0x40;
arr[1] = subpcode;
switch (pcode) {
case 0x0:
n = 4;
arr[n++] = 0x0;
arr[n++] = 0x0;
arr[n++] = 0x0;
arr[n++] = 0xff;
arr[n++] = 0xd;
arr[n++] = 0x0;
arr[n++] = 0x2f;
arr[n++] = 0x0;
arr[3] = n - 4;
break;
case 0xd:
n = 4;
arr[n++] = 0xd;
arr[n++] = 0x0;
arr[3] = n - 4;
break;
case 0x2f:
n = 4;
arr[n++] = 0x2f;
arr[n++] = 0x0;
arr[3] = n - 4;
break;
default:
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 2, 5);
return check_condition_result;
}
} else {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 3, -1);
return check_condition_result;
}
len = min(((arr[2] << 8) + arr[3]) + 4, alloc_len);
return fill_from_dev_buffer(scp, arr,
min(len, SDEBUG_MAX_INQ_ARR_SZ));
}
static int check_device_access_params(struct scsi_cmnd *scp,
unsigned long long lba, unsigned int num)
{
if (lba + num > sdebug_capacity) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, LBA_OUT_OF_RANGE, 0);
return check_condition_result;
}
if (num > sdebug_store_sectors) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, INVALID_FIELD_IN_CDB, 0);
return check_condition_result;
}
return 0;
}
static int
do_device_access(struct scsi_cmnd *scmd, u64 lba, u32 num, bool do_write)
{
int ret;
u64 block, rest = 0;
struct scsi_data_buffer *sdb;
enum dma_data_direction dir;
size_t (*func)(struct scatterlist *, unsigned int, void *, size_t,
off_t);
if (do_write) {
sdb = scsi_out(scmd);
dir = DMA_TO_DEVICE;
func = sg_pcopy_to_buffer;
} else {
sdb = scsi_in(scmd);
dir = DMA_FROM_DEVICE;
func = sg_pcopy_from_buffer;
}
if (!sdb->length)
return 0;
if (!(scsi_bidi_cmnd(scmd) || scmd->sc_data_direction == dir))
return -1;
block = do_div(lba, sdebug_store_sectors);
if (block + num > sdebug_store_sectors)
rest = block + num - sdebug_store_sectors;
ret = func(sdb->table.sgl, sdb->table.nents,
fake_storep + (block * scsi_debug_sector_size),
(num - rest) * scsi_debug_sector_size, 0);
if (ret != (num - rest) * scsi_debug_sector_size)
return ret;
if (rest) {
ret += func(sdb->table.sgl, sdb->table.nents,
fake_storep, rest * scsi_debug_sector_size,
(num - rest) * scsi_debug_sector_size);
}
return ret;
}
static bool
comp_write_worker(u64 lba, u32 num, const u8 *arr)
{
bool res;
u64 block, rest = 0;
u32 store_blks = sdebug_store_sectors;
u32 lb_size = scsi_debug_sector_size;
block = do_div(lba, store_blks);
if (block + num > store_blks)
rest = block + num - store_blks;
res = !memcmp(fake_storep + (block * lb_size), arr,
(num - rest) * lb_size);
if (!res)
return res;
if (rest)
res = memcmp(fake_storep, arr + ((num - rest) * lb_size),
rest * lb_size);
if (!res)
return res;
arr += num * lb_size;
memcpy(fake_storep + (block * lb_size), arr, (num - rest) * lb_size);
if (rest)
memcpy(fake_storep, arr + ((num - rest) * lb_size),
rest * lb_size);
return res;
}
static __be16 dif_compute_csum(const void *buf, int len)
{
__be16 csum;
if (scsi_debug_guard)
csum = (__force __be16)ip_compute_csum(buf, len);
else
csum = cpu_to_be16(crc_t10dif(buf, len));
return csum;
}
static int dif_verify(struct sd_dif_tuple *sdt, const void *data,
sector_t sector, u32 ei_lba)
{
__be16 csum = dif_compute_csum(data, scsi_debug_sector_size);
if (sdt->guard_tag != csum) {
pr_err("%s: GUARD check failed on sector %lu rcvd 0x%04x, data 0x%04x\n",
__func__,
(unsigned long)sector,
be16_to_cpu(sdt->guard_tag),
be16_to_cpu(csum));
return 0x01;
}
if (scsi_debug_dif == SD_DIF_TYPE1_PROTECTION &&
be32_to_cpu(sdt->ref_tag) != (sector & 0xffffffff)) {
pr_err("%s: REF check failed on sector %lu\n",
__func__, (unsigned long)sector);
return 0x03;
}
if (scsi_debug_dif == SD_DIF_TYPE2_PROTECTION &&
be32_to_cpu(sdt->ref_tag) != ei_lba) {
pr_err("%s: REF check failed on sector %lu\n",
__func__, (unsigned long)sector);
return 0x03;
}
return 0;
}
static void dif_copy_prot(struct scsi_cmnd *SCpnt, sector_t sector,
unsigned int sectors, bool read)
{
size_t resid;
void *paddr;
const void *dif_store_end = dif_storep + sdebug_store_sectors;
struct sg_mapping_iter miter;
resid = sectors * sizeof(*dif_storep);
sg_miter_start(&miter, scsi_prot_sglist(SCpnt),
scsi_prot_sg_count(SCpnt), SG_MITER_ATOMIC |
(read ? SG_MITER_TO_SG : SG_MITER_FROM_SG));
while (sg_miter_next(&miter) && resid > 0) {
size_t len = min(miter.length, resid);
void *start = dif_store(sector);
size_t rest = 0;
if (dif_store_end < start + len)
rest = start + len - dif_store_end;
paddr = miter.addr;
if (read)
memcpy(paddr, start, len - rest);
else
memcpy(start, paddr, len - rest);
if (rest) {
if (read)
memcpy(paddr + len - rest, dif_storep, rest);
else
memcpy(dif_storep, paddr + len - rest, rest);
}
sector += len / sizeof(*dif_storep);
resid -= len;
}
sg_miter_stop(&miter);
}
static int prot_verify_read(struct scsi_cmnd *SCpnt, sector_t start_sec,
unsigned int sectors, u32 ei_lba)
{
unsigned int i;
struct sd_dif_tuple *sdt;
sector_t sector;
for (i = 0; i < sectors; i++, ei_lba++) {
int ret;
sector = start_sec + i;
sdt = dif_store(sector);
if (sdt->app_tag == cpu_to_be16(0xffff))
continue;
ret = dif_verify(sdt, fake_store(sector), sector, ei_lba);
if (ret) {
dif_errors++;
return ret;
}
}
dif_copy_prot(SCpnt, start_sec, sectors, true);
dix_reads++;
return 0;
}
static int
resp_read_dt0(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
u8 *cmd = scp->cmnd;
u64 lba;
u32 num;
u32 ei_lba;
unsigned long iflags;
int ret;
bool check_prot;
switch (cmd[0]) {
case READ_16:
ei_lba = 0;
lba = get_unaligned_be64(cmd + 2);
num = get_unaligned_be32(cmd + 10);
check_prot = true;
break;
case READ_10:
ei_lba = 0;
lba = get_unaligned_be32(cmd + 2);
num = get_unaligned_be16(cmd + 7);
check_prot = true;
break;
case READ_6:
ei_lba = 0;
lba = (u32)cmd[3] | (u32)cmd[2] << 8 |
(u32)(cmd[1] & 0x1f) << 16;
num = (0 == cmd[4]) ? 256 : cmd[4];
check_prot = true;
break;
case READ_12:
ei_lba = 0;
lba = get_unaligned_be32(cmd + 2);
num = get_unaligned_be32(cmd + 6);
check_prot = true;
break;
case XDWRITEREAD_10:
ei_lba = 0;
lba = get_unaligned_be32(cmd + 2);
num = get_unaligned_be16(cmd + 7);
check_prot = false;
break;
default:
lba = get_unaligned_be64(cmd + 12);
ei_lba = get_unaligned_be32(cmd + 20);
num = get_unaligned_be32(cmd + 28);
check_prot = false;
break;
}
if (check_prot) {
if (scsi_debug_dif == SD_DIF_TYPE2_PROTECTION &&
(cmd[1] & 0xe0)) {
mk_sense_invalid_opcode(scp);
return check_condition_result;
}
if ((scsi_debug_dif == SD_DIF_TYPE1_PROTECTION ||
scsi_debug_dif == SD_DIF_TYPE3_PROTECTION) &&
(cmd[1] & 0xe0) == 0)
sdev_printk(KERN_ERR, scp->device, "Unprotected RD "
"to DIF device\n");
}
if (sdebug_any_injecting_opt) {
struct sdebug_scmd_extra_t *ep = scsi_cmd_priv(scp);
if (ep->inj_short)
num /= 2;
}
if (lba + num > sdebug_capacity) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, LBA_OUT_OF_RANGE, 0);
return check_condition_result;
}
if (num > sdebug_store_sectors) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, INVALID_FIELD_IN_CDB, 0);
return check_condition_result;
}
if ((SCSI_DEBUG_OPT_MEDIUM_ERR & scsi_debug_opts) &&
(lba <= (OPT_MEDIUM_ERR_ADDR + OPT_MEDIUM_ERR_NUM - 1)) &&
((lba + num) > OPT_MEDIUM_ERR_ADDR)) {
mk_sense_buffer(scp, MEDIUM_ERROR, UNRECOVERED_READ_ERR, 0);
if (0x70 == (scp->sense_buffer[0] & 0x7f)) {
scp->sense_buffer[0] |= 0x80;
ret = (lba < OPT_MEDIUM_ERR_ADDR)
? OPT_MEDIUM_ERR_ADDR : (int)lba;
put_unaligned_be32(ret, scp->sense_buffer + 3);
}
scsi_set_resid(scp, scsi_bufflen(scp));
return check_condition_result;
}
read_lock_irqsave(&atomic_rw, iflags);
if (scsi_debug_dix && scsi_prot_sg_count(scp)) {
int prot_ret = prot_verify_read(scp, lba, num, ei_lba);
if (prot_ret) {
read_unlock_irqrestore(&atomic_rw, iflags);
mk_sense_buffer(scp, ABORTED_COMMAND, 0x10, prot_ret);
return illegal_condition_result;
}
}
ret = do_device_access(scp, lba, num, false);
read_unlock_irqrestore(&atomic_rw, iflags);
if (ret == -1)
return DID_ERROR << 16;
scsi_in(scp)->resid = scsi_bufflen(scp) - ret;
if (sdebug_any_injecting_opt) {
struct sdebug_scmd_extra_t *ep = scsi_cmd_priv(scp);
if (ep->inj_recovered) {
mk_sense_buffer(scp, RECOVERED_ERROR,
THRESHOLD_EXCEEDED, 0);
return check_condition_result;
} else if (ep->inj_transport) {
mk_sense_buffer(scp, ABORTED_COMMAND,
TRANSPORT_PROBLEM, ACK_NAK_TO);
return check_condition_result;
} else if (ep->inj_dif) {
mk_sense_buffer(scp, ABORTED_COMMAND, 0x10, 1);
return illegal_condition_result;
} else if (ep->inj_dix) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, 0x10, 1);
return illegal_condition_result;
}
}
return 0;
}
void dump_sector(unsigned char *buf, int len)
{
int i, j, n;
pr_err(">>> Sector Dump <<<\n");
for (i = 0 ; i < len ; i += 16) {
char b[128];
for (j = 0, n = 0; j < 16; j++) {
unsigned char c = buf[i+j];
if (c >= 0x20 && c < 0x7e)
n += scnprintf(b + n, sizeof(b) - n,
" %c ", buf[i+j]);
else
n += scnprintf(b + n, sizeof(b) - n,
"%02x ", buf[i+j]);
}
pr_err("%04d: %s\n", i, b);
}
}
static int prot_verify_write(struct scsi_cmnd *SCpnt, sector_t start_sec,
unsigned int sectors, u32 ei_lba)
{
int ret;
struct sd_dif_tuple *sdt;
void *daddr;
sector_t sector = start_sec;
int ppage_offset;
int dpage_offset;
struct sg_mapping_iter diter;
struct sg_mapping_iter piter;
BUG_ON(scsi_sg_count(SCpnt) == 0);
BUG_ON(scsi_prot_sg_count(SCpnt) == 0);
sg_miter_start(&piter, scsi_prot_sglist(SCpnt),
scsi_prot_sg_count(SCpnt),
SG_MITER_ATOMIC | SG_MITER_FROM_SG);
sg_miter_start(&diter, scsi_sglist(SCpnt), scsi_sg_count(SCpnt),
SG_MITER_ATOMIC | SG_MITER_FROM_SG);
while (sg_miter_next(&piter)) {
dpage_offset = 0;
if (WARN_ON(!sg_miter_next(&diter))) {
ret = 0x01;
goto out;
}
for (ppage_offset = 0; ppage_offset < piter.length;
ppage_offset += sizeof(struct sd_dif_tuple)) {
if (dpage_offset >= diter.length) {
if (WARN_ON(!sg_miter_next(&diter))) {
ret = 0x01;
goto out;
}
dpage_offset = 0;
}
sdt = piter.addr + ppage_offset;
daddr = diter.addr + dpage_offset;
ret = dif_verify(sdt, daddr, sector, ei_lba);
if (ret) {
dump_sector(daddr, scsi_debug_sector_size);
goto out;
}
sector++;
ei_lba++;
dpage_offset += scsi_debug_sector_size;
}
diter.consumed = dpage_offset;
sg_miter_stop(&diter);
}
sg_miter_stop(&piter);
dif_copy_prot(SCpnt, start_sec, sectors, false);
dix_writes++;
return 0;
out:
dif_errors++;
sg_miter_stop(&diter);
sg_miter_stop(&piter);
return ret;
}
static unsigned long lba_to_map_index(sector_t lba)
{
if (scsi_debug_unmap_alignment) {
lba += scsi_debug_unmap_granularity -
scsi_debug_unmap_alignment;
}
do_div(lba, scsi_debug_unmap_granularity);
return lba;
}
static sector_t map_index_to_lba(unsigned long index)
{
sector_t lba = index * scsi_debug_unmap_granularity;
if (scsi_debug_unmap_alignment) {
lba -= scsi_debug_unmap_granularity -
scsi_debug_unmap_alignment;
}
return lba;
}
static unsigned int map_state(sector_t lba, unsigned int *num)
{
sector_t end;
unsigned int mapped;
unsigned long index;
unsigned long next;
index = lba_to_map_index(lba);
mapped = test_bit(index, map_storep);
if (mapped)
next = find_next_zero_bit(map_storep, map_size, index);
else
next = find_next_bit(map_storep, map_size, index);
end = min_t(sector_t, sdebug_store_sectors, map_index_to_lba(next));
*num = end - lba;
return mapped;
}
static void map_region(sector_t lba, unsigned int len)
{
sector_t end = lba + len;
while (lba < end) {
unsigned long index = lba_to_map_index(lba);
if (index < map_size)
set_bit(index, map_storep);
lba = map_index_to_lba(index + 1);
}
}
static void unmap_region(sector_t lba, unsigned int len)
{
sector_t end = lba + len;
while (lba < end) {
unsigned long index = lba_to_map_index(lba);
if (lba == map_index_to_lba(index) &&
lba + scsi_debug_unmap_granularity <= end &&
index < map_size) {
clear_bit(index, map_storep);
if (scsi_debug_lbprz) {
memset(fake_storep +
lba * scsi_debug_sector_size, 0,
scsi_debug_sector_size *
scsi_debug_unmap_granularity);
}
if (dif_storep) {
memset(dif_storep + lba, 0xff,
sizeof(*dif_storep) *
scsi_debug_unmap_granularity);
}
}
lba = map_index_to_lba(index + 1);
}
}
static int
resp_write_dt0(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
u8 *cmd = scp->cmnd;
u64 lba;
u32 num;
u32 ei_lba;
unsigned long iflags;
int ret;
bool check_prot;
switch (cmd[0]) {
case WRITE_16:
ei_lba = 0;
lba = get_unaligned_be64(cmd + 2);
num = get_unaligned_be32(cmd + 10);
check_prot = true;
break;
case WRITE_10:
ei_lba = 0;
lba = get_unaligned_be32(cmd + 2);
num = get_unaligned_be16(cmd + 7);
check_prot = true;
break;
case WRITE_6:
ei_lba = 0;
lba = (u32)cmd[3] | (u32)cmd[2] << 8 |
(u32)(cmd[1] & 0x1f) << 16;
num = (0 == cmd[4]) ? 256 : cmd[4];
check_prot = true;
break;
case WRITE_12:
ei_lba = 0;
lba = get_unaligned_be32(cmd + 2);
num = get_unaligned_be32(cmd + 6);
check_prot = true;
break;
case 0x53:
ei_lba = 0;
lba = get_unaligned_be32(cmd + 2);
num = get_unaligned_be16(cmd + 7);
check_prot = false;
break;
default:
lba = get_unaligned_be64(cmd + 12);
ei_lba = get_unaligned_be32(cmd + 20);
num = get_unaligned_be32(cmd + 28);
check_prot = false;
break;
}
if (check_prot) {
if (scsi_debug_dif == SD_DIF_TYPE2_PROTECTION &&
(cmd[1] & 0xe0)) {
mk_sense_invalid_opcode(scp);
return check_condition_result;
}
if ((scsi_debug_dif == SD_DIF_TYPE1_PROTECTION ||
scsi_debug_dif == SD_DIF_TYPE3_PROTECTION) &&
(cmd[1] & 0xe0) == 0)
sdev_printk(KERN_ERR, scp->device, "Unprotected WR "
"to DIF device\n");
}
if (lba + num > sdebug_capacity) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, LBA_OUT_OF_RANGE, 0);
return check_condition_result;
}
if (num > sdebug_store_sectors) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, INVALID_FIELD_IN_CDB, 0);
return check_condition_result;
}
write_lock_irqsave(&atomic_rw, iflags);
if (scsi_debug_dix && scsi_prot_sg_count(scp)) {
int prot_ret = prot_verify_write(scp, lba, num, ei_lba);
if (prot_ret) {
write_unlock_irqrestore(&atomic_rw, iflags);
mk_sense_buffer(scp, ILLEGAL_REQUEST, 0x10, prot_ret);
return illegal_condition_result;
}
}
ret = do_device_access(scp, lba, num, true);
if (scsi_debug_lbp())
map_region(lba, num);
write_unlock_irqrestore(&atomic_rw, iflags);
if (-1 == ret)
return (DID_ERROR << 16);
else if ((ret < (num * scsi_debug_sector_size)) &&
(SCSI_DEBUG_OPT_NOISE & scsi_debug_opts))
sdev_printk(KERN_INFO, scp->device,
"%s: write: cdb indicated=%u, IO sent=%d bytes\n",
my_name, num * scsi_debug_sector_size, ret);
if (sdebug_any_injecting_opt) {
struct sdebug_scmd_extra_t *ep = scsi_cmd_priv(scp);
if (ep->inj_recovered) {
mk_sense_buffer(scp, RECOVERED_ERROR,
THRESHOLD_EXCEEDED, 0);
return check_condition_result;
} else if (ep->inj_dif) {
mk_sense_buffer(scp, ABORTED_COMMAND, 0x10, 1);
return illegal_condition_result;
} else if (ep->inj_dix) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, 0x10, 1);
return illegal_condition_result;
}
}
return 0;
}
static int
resp_write_same(struct scsi_cmnd *scp, u64 lba, u32 num, u32 ei_lba,
bool unmap, bool ndob)
{
unsigned long iflags;
unsigned long long i;
int ret;
ret = check_device_access_params(scp, lba, num);
if (ret)
return ret;
write_lock_irqsave(&atomic_rw, iflags);
if (unmap && scsi_debug_lbp()) {
unmap_region(lba, num);
goto out;
}
if (ndob) {
memset(fake_storep + (lba * scsi_debug_sector_size), 0,
scsi_debug_sector_size);
ret = 0;
} else
ret = fetch_to_dev_buffer(scp, fake_storep +
(lba * scsi_debug_sector_size),
scsi_debug_sector_size);
if (-1 == ret) {
write_unlock_irqrestore(&atomic_rw, iflags);
return (DID_ERROR << 16);
} else if ((ret < (num * scsi_debug_sector_size)) &&
(SCSI_DEBUG_OPT_NOISE & scsi_debug_opts))
sdev_printk(KERN_INFO, scp->device,
"%s: %s: cdb indicated=%u, IO sent=%d bytes\n",
my_name, "write same",
num * scsi_debug_sector_size, ret);
for (i = 1 ; i < num ; i++)
memcpy(fake_storep + ((lba + i) * scsi_debug_sector_size),
fake_storep + (lba * scsi_debug_sector_size),
scsi_debug_sector_size);
if (scsi_debug_lbp())
map_region(lba, num);
out:
write_unlock_irqrestore(&atomic_rw, iflags);
return 0;
}
static int
resp_write_same_10(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
u8 *cmd = scp->cmnd;
u32 lba;
u16 num;
u32 ei_lba = 0;
bool unmap = false;
if (cmd[1] & 0x8) {
if (scsi_debug_lbpws10 == 0) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 1, 3);
return check_condition_result;
} else
unmap = true;
}
lba = get_unaligned_be32(cmd + 2);
num = get_unaligned_be16(cmd + 7);
if (num > scsi_debug_write_same_length) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 7, -1);
return check_condition_result;
}
return resp_write_same(scp, lba, num, ei_lba, unmap, false);
}
static int
resp_write_same_16(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
u8 *cmd = scp->cmnd;
u64 lba;
u32 num;
u32 ei_lba = 0;
bool unmap = false;
bool ndob = false;
if (cmd[1] & 0x8) {
if (scsi_debug_lbpws == 0) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 1, 3);
return check_condition_result;
} else
unmap = true;
}
if (cmd[1] & 0x1)
ndob = true;
lba = get_unaligned_be64(cmd + 2);
num = get_unaligned_be32(cmd + 10);
if (num > scsi_debug_write_same_length) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 10, -1);
return check_condition_result;
}
return resp_write_same(scp, lba, num, ei_lba, unmap, ndob);
}
static int
resp_comp_write(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
u8 *cmd = scp->cmnd;
u8 *arr;
u8 *fake_storep_hold;
u64 lba;
u32 dnum;
u32 lb_size = scsi_debug_sector_size;
u8 num;
unsigned long iflags;
int ret;
int retval = 0;
lba = get_unaligned_be64(cmd + 2);
num = cmd[13];
if (0 == num)
return 0;
if (scsi_debug_dif == SD_DIF_TYPE2_PROTECTION &&
(cmd[1] & 0xe0)) {
mk_sense_invalid_opcode(scp);
return check_condition_result;
}
if ((scsi_debug_dif == SD_DIF_TYPE1_PROTECTION ||
scsi_debug_dif == SD_DIF_TYPE3_PROTECTION) &&
(cmd[1] & 0xe0) == 0)
sdev_printk(KERN_ERR, scp->device, "Unprotected WR "
"to DIF device\n");
if (lba + num > sdebug_capacity) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, LBA_OUT_OF_RANGE, 0);
return check_condition_result;
}
if (num > sdebug_store_sectors) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, INVALID_FIELD_IN_CDB, 0);
return check_condition_result;
}
dnum = 2 * num;
arr = kzalloc(dnum * lb_size, GFP_ATOMIC);
if (NULL == arr) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, INSUFF_RES_ASC,
INSUFF_RES_ASCQ);
return check_condition_result;
}
write_lock_irqsave(&atomic_rw, iflags);
fake_storep_hold = fake_storep;
fake_storep = arr;
ret = do_device_access(scp, 0, dnum, true);
fake_storep = fake_storep_hold;
if (ret == -1) {
retval = DID_ERROR << 16;
goto cleanup;
} else if ((ret < (dnum * lb_size)) &&
(SCSI_DEBUG_OPT_NOISE & scsi_debug_opts))
sdev_printk(KERN_INFO, scp->device, "%s: compare_write: cdb "
"indicated=%u, IO sent=%d bytes\n", my_name,
dnum * lb_size, ret);
if (!comp_write_worker(lba, num, arr)) {
mk_sense_buffer(scp, MISCOMPARE, MISCOMPARE_VERIFY_ASC, 0);
retval = check_condition_result;
goto cleanup;
}
if (scsi_debug_lbp())
map_region(lba, num);
cleanup:
write_unlock_irqrestore(&atomic_rw, iflags);
kfree(arr);
return retval;
}
static int
resp_unmap(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
unsigned char *buf;
struct unmap_block_desc *desc;
unsigned int i, payload_len, descriptors;
int ret;
unsigned long iflags;
if (!scsi_debug_lbp())
return 0;
payload_len = get_unaligned_be16(scp->cmnd + 7);
BUG_ON(scsi_bufflen(scp) != payload_len);
descriptors = (payload_len - 8) / 16;
if (descriptors > scsi_debug_unmap_max_desc) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 7, -1);
return check_condition_result;
}
buf = kmalloc(scsi_bufflen(scp), GFP_ATOMIC);
if (!buf) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, INSUFF_RES_ASC,
INSUFF_RES_ASCQ);
return check_condition_result;
}
scsi_sg_copy_to_buffer(scp, buf, scsi_bufflen(scp));
BUG_ON(get_unaligned_be16(&buf[0]) != payload_len - 2);
BUG_ON(get_unaligned_be16(&buf[2]) != descriptors * 16);
desc = (void *)&buf[8];
write_lock_irqsave(&atomic_rw, iflags);
for (i = 0 ; i < descriptors ; i++) {
unsigned long long lba = get_unaligned_be64(&desc[i].lba);
unsigned int num = get_unaligned_be32(&desc[i].blocks);
ret = check_device_access_params(scp, lba, num);
if (ret)
goto out;
unmap_region(lba, num);
}
ret = 0;
out:
write_unlock_irqrestore(&atomic_rw, iflags);
kfree(buf);
return ret;
}
static int
resp_get_lba_status(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
u8 *cmd = scp->cmnd;
u64 lba;
u32 alloc_len, mapped, num;
u8 arr[SDEBUG_GET_LBA_STATUS_LEN];
int ret;
lba = get_unaligned_be64(cmd + 2);
alloc_len = get_unaligned_be32(cmd + 10);
if (alloc_len < 24)
return 0;
ret = check_device_access_params(scp, lba, 1);
if (ret)
return ret;
if (scsi_debug_lbp())
mapped = map_state(lba, &num);
else {
mapped = 1;
sdebug_capacity = get_sdebug_capacity();
if (sdebug_capacity - lba <= 0xffffffff)
num = sdebug_capacity - lba;
else
num = 0xffffffff;
}
memset(arr, 0, SDEBUG_GET_LBA_STATUS_LEN);
put_unaligned_be32(20, arr);
put_unaligned_be64(lba, arr + 8);
put_unaligned_be32(num, arr + 16);
arr[20] = !mapped;
return fill_from_dev_buffer(scp, arr, SDEBUG_GET_LBA_STATUS_LEN);
}
static int resp_report_luns(struct scsi_cmnd * scp,
struct sdebug_dev_info * devip)
{
unsigned int alloc_len;
int lun_cnt, i, upper, num, n, want_wlun, shortish;
u64 lun;
unsigned char *cmd = scp->cmnd;
int select_report = (int)cmd[2];
struct scsi_lun *one_lun;
unsigned char arr[SDEBUG_RLUN_ARR_SZ];
unsigned char * max_addr;
alloc_len = cmd[9] + (cmd[8] << 8) + (cmd[7] << 16) + (cmd[6] << 24);
shortish = (alloc_len < 4);
if (shortish || (select_report > 2)) {
mk_sense_invalid_fld(scp, SDEB_IN_CDB, shortish ? 6 : 2, -1);
return check_condition_result;
}
memset(arr, 0, SDEBUG_RLUN_ARR_SZ);
lun_cnt = scsi_debug_max_luns;
if (1 == select_report)
lun_cnt = 0;
else if (scsi_debug_no_lun_0 && (lun_cnt > 0))
--lun_cnt;
want_wlun = (select_report > 0) ? 1 : 0;
num = lun_cnt + want_wlun;
arr[2] = ((sizeof(struct scsi_lun) * num) >> 8) & 0xff;
arr[3] = (sizeof(struct scsi_lun) * num) & 0xff;
n = min((int)((SDEBUG_RLUN_ARR_SZ - 8) /
sizeof(struct scsi_lun)), num);
if (n < num) {
want_wlun = 0;
lun_cnt = n;
}
one_lun = (struct scsi_lun *) &arr[8];
max_addr = arr + SDEBUG_RLUN_ARR_SZ;
for (i = 0, lun = (scsi_debug_no_lun_0 ? 1 : 0);
((i < lun_cnt) && ((unsigned char *)(one_lun + i) < max_addr));
i++, lun++) {
upper = (lun >> 8) & 0x3f;
if (upper)
one_lun[i].scsi_lun[0] =
(upper | (SAM2_LUN_ADDRESS_METHOD << 6));
one_lun[i].scsi_lun[1] = lun & 0xff;
}
if (want_wlun) {
one_lun[i].scsi_lun[0] = (SAM2_WLUN_REPORT_LUNS >> 8) & 0xff;
one_lun[i].scsi_lun[1] = SAM2_WLUN_REPORT_LUNS & 0xff;
i++;
}
alloc_len = (unsigned char *)(one_lun + i) - arr;
return fill_from_dev_buffer(scp, arr,
min((int)alloc_len, SDEBUG_RLUN_ARR_SZ));
}
static int resp_xdwriteread(struct scsi_cmnd *scp, unsigned long long lba,
unsigned int num, struct sdebug_dev_info *devip)
{
int j;
unsigned char *kaddr, *buf;
unsigned int offset;
struct scsi_data_buffer *sdb = scsi_in(scp);
struct sg_mapping_iter miter;
buf = kmalloc(scsi_bufflen(scp), GFP_ATOMIC);
if (!buf) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, INSUFF_RES_ASC,
INSUFF_RES_ASCQ);
return check_condition_result;
}
scsi_sg_copy_to_buffer(scp, buf, scsi_bufflen(scp));
offset = 0;
sg_miter_start(&miter, sdb->table.sgl, sdb->table.nents,
SG_MITER_ATOMIC | SG_MITER_TO_SG);
while (sg_miter_next(&miter)) {
kaddr = miter.addr;
for (j = 0; j < miter.length; j++)
*(kaddr + j) ^= *(buf + offset + j);
offset += miter.length;
}
sg_miter_stop(&miter);
kfree(buf);
return 0;
}
static int
resp_xdwriteread_10(struct scsi_cmnd *scp, struct sdebug_dev_info *devip)
{
u8 *cmd = scp->cmnd;
u64 lba;
u32 num;
int errsts;
if (!scsi_bidi_cmnd(scp)) {
mk_sense_buffer(scp, ILLEGAL_REQUEST, INSUFF_RES_ASC,
INSUFF_RES_ASCQ);
return check_condition_result;
}
errsts = resp_read_dt0(scp, devip);
if (errsts)
return errsts;
if (!(cmd[1] & 0x4)) {
errsts = resp_write_dt0(scp, devip);
if (errsts)
return errsts;
}
lba = get_unaligned_be32(cmd + 2);
num = get_unaligned_be16(cmd + 7);
return resp_xdwriteread(scp, lba, num, devip);
}
static void sdebug_q_cmd_complete(unsigned long indx)
{
int qa_indx;
int retiring = 0;
unsigned long iflags;
struct sdebug_queued_cmd *sqcp;
struct scsi_cmnd *scp;
struct sdebug_dev_info *devip;
atomic_inc(&sdebug_completions);
qa_indx = indx;
if ((qa_indx < 0) || (qa_indx >= SCSI_DEBUG_CANQUEUE)) {
pr_err("%s: wild qa_indx=%d\n", __func__, qa_indx);
return;
}
spin_lock_irqsave(&queued_arr_lock, iflags);
sqcp = &queued_arr[qa_indx];
scp = sqcp->a_cmnd;
if (NULL == scp) {
spin_unlock_irqrestore(&queued_arr_lock, iflags);
pr_err("%s: scp is NULL\n", __func__);
return;
}
devip = (struct sdebug_dev_info *)scp->device->hostdata;
if (devip)
atomic_dec(&devip->num_in_q);
else
pr_err("%s: devip=NULL\n", __func__);
if (atomic_read(&retired_max_queue) > 0)
retiring = 1;
sqcp->a_cmnd = NULL;
if (!test_and_clear_bit(qa_indx, queued_in_use_bm)) {
spin_unlock_irqrestore(&queued_arr_lock, iflags);
pr_err("%s: Unexpected completion\n", __func__);
return;
}
if (unlikely(retiring)) {
int k, retval;
retval = atomic_read(&retired_max_queue);
if (qa_indx >= retval) {
spin_unlock_irqrestore(&queued_arr_lock, iflags);
pr_err("%s: index %d too large\n", __func__, retval);
return;
}
k = find_last_bit(queued_in_use_bm, retval);
if ((k < scsi_debug_max_queue) || (k == retval))
atomic_set(&retired_max_queue, 0);
else
atomic_set(&retired_max_queue, k + 1);
}
spin_unlock_irqrestore(&queued_arr_lock, iflags);
scp->scsi_done(scp);
}
static enum hrtimer_restart
sdebug_q_cmd_hrt_complete(struct hrtimer *timer)
{
int qa_indx;
int retiring = 0;
unsigned long iflags;
struct sdebug_hrtimer *sd_hrtp = (struct sdebug_hrtimer *)timer;
struct sdebug_queued_cmd *sqcp;
struct scsi_cmnd *scp;
struct sdebug_dev_info *devip;
atomic_inc(&sdebug_completions);
qa_indx = sd_hrtp->qa_indx;
if ((qa_indx < 0) || (qa_indx >= SCSI_DEBUG_CANQUEUE)) {
pr_err("%s: wild qa_indx=%d\n", __func__, qa_indx);
goto the_end;
}
spin_lock_irqsave(&queued_arr_lock, iflags);
sqcp = &queued_arr[qa_indx];
scp = sqcp->a_cmnd;
if (NULL == scp) {
spin_unlock_irqrestore(&queued_arr_lock, iflags);
pr_err("%s: scp is NULL\n", __func__);
goto the_end;
}
devip = (struct sdebug_dev_info *)scp->device->hostdata;
if (devip)
atomic_dec(&devip->num_in_q);
else
pr_err("%s: devip=NULL\n", __func__);
if (atomic_read(&retired_max_queue) > 0)
retiring = 1;
sqcp->a_cmnd = NULL;
if (!test_and_clear_bit(qa_indx, queued_in_use_bm)) {
spin_unlock_irqrestore(&queued_arr_lock, iflags);
pr_err("%s: Unexpected completion\n", __func__);
goto the_end;
}
if (unlikely(retiring)) {
int k, retval;
retval = atomic_read(&retired_max_queue);
if (qa_indx >= retval) {
spin_unlock_irqrestore(&queued_arr_lock, iflags);
pr_err("%s: index %d too large\n", __func__, retval);
goto the_end;
}
k = find_last_bit(queued_in_use_bm, retval);
if ((k < scsi_debug_max_queue) || (k == retval))
atomic_set(&retired_max_queue, 0);
else
atomic_set(&retired_max_queue, k + 1);
}
spin_unlock_irqrestore(&queued_arr_lock, iflags);
scp->scsi_done(scp);
the_end:
return HRTIMER_NORESTART;
}
static struct sdebug_dev_info *
sdebug_device_create(struct sdebug_host_info *sdbg_host, gfp_t flags)
{
struct sdebug_dev_info *devip;
devip = kzalloc(sizeof(*devip), flags);
if (devip) {
devip->sdbg_host = sdbg_host;
list_add_tail(&devip->dev_list, &sdbg_host->dev_info_list);
}
return devip;
}
static struct sdebug_dev_info * devInfoReg(struct scsi_device * sdev)
{
struct sdebug_host_info * sdbg_host;
struct sdebug_dev_info * open_devip = NULL;
struct sdebug_dev_info * devip =
(struct sdebug_dev_info *)sdev->hostdata;
if (devip)
return devip;
sdbg_host = *(struct sdebug_host_info **)shost_priv(sdev->host);
if (!sdbg_host) {
pr_err("%s: Host info NULL\n", __func__);
return NULL;
}
list_for_each_entry(devip, &sdbg_host->dev_info_list, dev_list) {
if ((devip->used) && (devip->channel == sdev->channel) &&
(devip->target == sdev->id) &&
(devip->lun == sdev->lun))
return devip;
else {
if ((!devip->used) && (!open_devip))
open_devip = devip;
}
}
if (!open_devip) {
open_devip = sdebug_device_create(sdbg_host, GFP_ATOMIC);
if (!open_devip) {
printk(KERN_ERR "%s: out of memory at line %d\n",
__func__, __LINE__);
return NULL;
}
}
open_devip->channel = sdev->channel;
open_devip->target = sdev->id;
open_devip->lun = sdev->lun;
open_devip->sdbg_host = sdbg_host;
atomic_set(&open_devip->num_in_q, 0);
set_bit(SDEBUG_UA_POR, open_devip->uas_bm);
open_devip->used = true;
return open_devip;
}
static int scsi_debug_slave_alloc(struct scsi_device *sdp)
{
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: slave_alloc <%u %u %u %llu>\n",
sdp->host->host_no, sdp->channel, sdp->id, sdp->lun);
queue_flag_set_unlocked(QUEUE_FLAG_BIDI, sdp->request_queue);
return 0;
}
static int scsi_debug_slave_configure(struct scsi_device *sdp)
{
struct sdebug_dev_info *devip;
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: slave_configure <%u %u %u %llu>\n",
sdp->host->host_no, sdp->channel, sdp->id, sdp->lun);
if (sdp->host->max_cmd_len != SCSI_DEBUG_MAX_CMD_LEN)
sdp->host->max_cmd_len = SCSI_DEBUG_MAX_CMD_LEN;
devip = devInfoReg(sdp);
if (NULL == devip)
return 1;
sdp->hostdata = devip;
blk_queue_max_segment_size(sdp->request_queue, -1U);
if (scsi_debug_no_uld)
sdp->no_uld_attach = 1;
return 0;
}
static void scsi_debug_slave_destroy(struct scsi_device *sdp)
{
struct sdebug_dev_info *devip =
(struct sdebug_dev_info *)sdp->hostdata;
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: slave_destroy <%u %u %u %llu>\n",
sdp->host->host_no, sdp->channel, sdp->id, sdp->lun);
if (devip) {
devip->used = false;
sdp->hostdata = NULL;
}
}
static int stop_queued_cmnd(struct scsi_cmnd *cmnd)
{
unsigned long iflags;
int k, qmax, r_qmax;
struct sdebug_queued_cmd *sqcp;
struct sdebug_dev_info *devip;
spin_lock_irqsave(&queued_arr_lock, iflags);
qmax = scsi_debug_max_queue;
r_qmax = atomic_read(&retired_max_queue);
if (r_qmax > qmax)
qmax = r_qmax;
for (k = 0; k < qmax; ++k) {
if (test_bit(k, queued_in_use_bm)) {
sqcp = &queued_arr[k];
if (cmnd == sqcp->a_cmnd) {
devip = (struct sdebug_dev_info *)
cmnd->device->hostdata;
if (devip)
atomic_dec(&devip->num_in_q);
sqcp->a_cmnd = NULL;
spin_unlock_irqrestore(&queued_arr_lock,
iflags);
if (scsi_debug_ndelay > 0) {
if (sqcp->sd_hrtp)
hrtimer_cancel(
&sqcp->sd_hrtp->hrt);
} else if (scsi_debug_delay > 0) {
if (sqcp->cmnd_timerp)
del_timer_sync(
sqcp->cmnd_timerp);
} else if (scsi_debug_delay < 0) {
if (sqcp->tletp)
tasklet_kill(sqcp->tletp);
}
clear_bit(k, queued_in_use_bm);
return 1;
}
}
}
spin_unlock_irqrestore(&queued_arr_lock, iflags);
return 0;
}
static void stop_all_queued(void)
{
unsigned long iflags;
int k;
struct sdebug_queued_cmd *sqcp;
struct sdebug_dev_info *devip;
spin_lock_irqsave(&queued_arr_lock, iflags);
for (k = 0; k < SCSI_DEBUG_CANQUEUE; ++k) {
if (test_bit(k, queued_in_use_bm)) {
sqcp = &queued_arr[k];
if (sqcp->a_cmnd) {
devip = (struct sdebug_dev_info *)
sqcp->a_cmnd->device->hostdata;
if (devip)
atomic_dec(&devip->num_in_q);
sqcp->a_cmnd = NULL;
spin_unlock_irqrestore(&queued_arr_lock,
iflags);
if (scsi_debug_ndelay > 0) {
if (sqcp->sd_hrtp)
hrtimer_cancel(
&sqcp->sd_hrtp->hrt);
} else if (scsi_debug_delay > 0) {
if (sqcp->cmnd_timerp)
del_timer_sync(
sqcp->cmnd_timerp);
} else if (scsi_debug_delay < 0) {
if (sqcp->tletp)
tasklet_kill(sqcp->tletp);
}
clear_bit(k, queued_in_use_bm);
spin_lock_irqsave(&queued_arr_lock, iflags);
}
}
}
spin_unlock_irqrestore(&queued_arr_lock, iflags);
}
static void free_all_queued(void)
{
unsigned long iflags;
int k;
struct sdebug_queued_cmd *sqcp;
spin_lock_irqsave(&queued_arr_lock, iflags);
for (k = 0; k < SCSI_DEBUG_CANQUEUE; ++k) {
sqcp = &queued_arr[k];
kfree(sqcp->cmnd_timerp);
sqcp->cmnd_timerp = NULL;
kfree(sqcp->tletp);
sqcp->tletp = NULL;
kfree(sqcp->sd_hrtp);
sqcp->sd_hrtp = NULL;
}
spin_unlock_irqrestore(&queued_arr_lock, iflags);
}
static int scsi_debug_abort(struct scsi_cmnd *SCpnt)
{
++num_aborts;
if (SCpnt) {
if (SCpnt->device &&
(SCSI_DEBUG_OPT_ALL_NOISE & scsi_debug_opts))
sdev_printk(KERN_INFO, SCpnt->device, "%s\n",
__func__);
stop_queued_cmnd(SCpnt);
}
return SUCCESS;
}
static int scsi_debug_device_reset(struct scsi_cmnd * SCpnt)
{
struct sdebug_dev_info * devip;
++num_dev_resets;
if (SCpnt && SCpnt->device) {
struct scsi_device *sdp = SCpnt->device;
if (SCSI_DEBUG_OPT_ALL_NOISE & scsi_debug_opts)
sdev_printk(KERN_INFO, sdp, "%s\n", __func__);
devip = devInfoReg(sdp);
if (devip)
set_bit(SDEBUG_UA_POR, devip->uas_bm);
}
return SUCCESS;
}
static int scsi_debug_target_reset(struct scsi_cmnd *SCpnt)
{
struct sdebug_host_info *sdbg_host;
struct sdebug_dev_info *devip;
struct scsi_device *sdp;
struct Scsi_Host *hp;
int k = 0;
++num_target_resets;
if (!SCpnt)
goto lie;
sdp = SCpnt->device;
if (!sdp)
goto lie;
if (SCSI_DEBUG_OPT_ALL_NOISE & scsi_debug_opts)
sdev_printk(KERN_INFO, sdp, "%s\n", __func__);
hp = sdp->host;
if (!hp)
goto lie;
sdbg_host = *(struct sdebug_host_info **)shost_priv(hp);
if (sdbg_host) {
list_for_each_entry(devip,
&sdbg_host->dev_info_list,
dev_list)
if (devip->target == sdp->id) {
set_bit(SDEBUG_UA_BUS_RESET, devip->uas_bm);
++k;
}
}
if (SCSI_DEBUG_OPT_RESET_NOISE & scsi_debug_opts)
sdev_printk(KERN_INFO, sdp,
"%s: %d device(s) found in target\n", __func__, k);
lie:
return SUCCESS;
}
static int scsi_debug_bus_reset(struct scsi_cmnd * SCpnt)
{
struct sdebug_host_info *sdbg_host;
struct sdebug_dev_info *devip;
struct scsi_device * sdp;
struct Scsi_Host * hp;
int k = 0;
++num_bus_resets;
if (!(SCpnt && SCpnt->device))
goto lie;
sdp = SCpnt->device;
if (SCSI_DEBUG_OPT_ALL_NOISE & scsi_debug_opts)
sdev_printk(KERN_INFO, sdp, "%s\n", __func__);
hp = sdp->host;
if (hp) {
sdbg_host = *(struct sdebug_host_info **)shost_priv(hp);
if (sdbg_host) {
list_for_each_entry(devip,
&sdbg_host->dev_info_list,
dev_list) {
set_bit(SDEBUG_UA_BUS_RESET, devip->uas_bm);
++k;
}
}
}
if (SCSI_DEBUG_OPT_RESET_NOISE & scsi_debug_opts)
sdev_printk(KERN_INFO, sdp,
"%s: %d device(s) found in host\n", __func__, k);
lie:
return SUCCESS;
}
static int scsi_debug_host_reset(struct scsi_cmnd * SCpnt)
{
struct sdebug_host_info * sdbg_host;
struct sdebug_dev_info *devip;
int k = 0;
++num_host_resets;
if ((SCpnt->device) && (SCSI_DEBUG_OPT_ALL_NOISE & scsi_debug_opts))
sdev_printk(KERN_INFO, SCpnt->device, "%s\n", __func__);
spin_lock(&sdebug_host_list_lock);
list_for_each_entry(sdbg_host, &sdebug_host_list, host_list) {
list_for_each_entry(devip, &sdbg_host->dev_info_list,
dev_list) {
set_bit(SDEBUG_UA_BUS_RESET, devip->uas_bm);
++k;
}
}
spin_unlock(&sdebug_host_list_lock);
stop_all_queued();
if (SCSI_DEBUG_OPT_RESET_NOISE & scsi_debug_opts)
sdev_printk(KERN_INFO, SCpnt->device,
"%s: %d device(s) found\n", __func__, k);
return SUCCESS;
}
static void __init sdebug_build_parts(unsigned char *ramp,
unsigned long store_size)
{
struct partition * pp;
int starts[SDEBUG_MAX_PARTS + 2];
int sectors_per_part, num_sectors, k;
int heads_by_sects, start_sec, end_sec;
if ((scsi_debug_num_parts < 1) || (store_size < 1048576))
return;
if (scsi_debug_num_parts > SDEBUG_MAX_PARTS) {
scsi_debug_num_parts = SDEBUG_MAX_PARTS;
pr_warn("%s: reducing partitions to %d\n", __func__,
SDEBUG_MAX_PARTS);
}
num_sectors = (int)sdebug_store_sectors;
sectors_per_part = (num_sectors - sdebug_sectors_per)
/ scsi_debug_num_parts;
heads_by_sects = sdebug_heads * sdebug_sectors_per;
starts[0] = sdebug_sectors_per;
for (k = 1; k < scsi_debug_num_parts; ++k)
starts[k] = ((k * sectors_per_part) / heads_by_sects)
* heads_by_sects;
starts[scsi_debug_num_parts] = num_sectors;
starts[scsi_debug_num_parts + 1] = 0;
ramp[510] = 0x55;
ramp[511] = 0xAA;
pp = (struct partition *)(ramp + 0x1be);
for (k = 0; starts[k + 1]; ++k, ++pp) {
start_sec = starts[k];
end_sec = starts[k + 1] - 1;
pp->boot_ind = 0;
pp->cyl = start_sec / heads_by_sects;
pp->head = (start_sec - (pp->cyl * heads_by_sects))
/ sdebug_sectors_per;
pp->sector = (start_sec % sdebug_sectors_per) + 1;
pp->end_cyl = end_sec / heads_by_sects;
pp->end_head = (end_sec - (pp->end_cyl * heads_by_sects))
/ sdebug_sectors_per;
pp->end_sector = (end_sec % sdebug_sectors_per) + 1;
pp->start_sect = cpu_to_le32(start_sec);
pp->nr_sects = cpu_to_le32(end_sec - start_sec + 1);
pp->sys_ind = 0x83;
}
}
static int
schedule_resp(struct scsi_cmnd *cmnd, struct sdebug_dev_info *devip,
int scsi_result, int delta_jiff)
{
unsigned long iflags;
int k, num_in_q, qdepth, inject;
struct sdebug_queued_cmd *sqcp = NULL;
struct scsi_device *sdp = cmnd->device;
if (NULL == cmnd || NULL == devip) {
pr_warn("%s: called with NULL cmnd or devip pointer\n",
__func__);
return SCSI_MLQUEUE_HOST_BUSY;
}
if ((scsi_result) && (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts))
sdev_printk(KERN_INFO, sdp, "%s: non-zero result=0x%x\n",
__func__, scsi_result);
if (delta_jiff == 0)
goto respond_in_thread;
spin_lock_irqsave(&queued_arr_lock, iflags);
num_in_q = atomic_read(&devip->num_in_q);
qdepth = cmnd->device->queue_depth;
inject = 0;
if ((qdepth > 0) && (num_in_q >= qdepth)) {
if (scsi_result) {
spin_unlock_irqrestore(&queued_arr_lock, iflags);
goto respond_in_thread;
} else
scsi_result = device_qfull_result;
} else if ((scsi_debug_every_nth != 0) &&
(SCSI_DEBUG_OPT_RARE_TSF & scsi_debug_opts) &&
(scsi_result == 0)) {
if ((num_in_q == (qdepth - 1)) &&
(atomic_inc_return(&sdebug_a_tsf) >=
abs(scsi_debug_every_nth))) {
atomic_set(&sdebug_a_tsf, 0);
inject = 1;
scsi_result = device_qfull_result;
}
}
k = find_first_zero_bit(queued_in_use_bm, scsi_debug_max_queue);
if (k >= scsi_debug_max_queue) {
spin_unlock_irqrestore(&queued_arr_lock, iflags);
if (scsi_result)
goto respond_in_thread;
else if (SCSI_DEBUG_OPT_ALL_TSF & scsi_debug_opts)
scsi_result = device_qfull_result;
if (SCSI_DEBUG_OPT_Q_NOISE & scsi_debug_opts)
sdev_printk(KERN_INFO, sdp,
"%s: max_queue=%d exceeded, %s\n",
__func__, scsi_debug_max_queue,
(scsi_result ? "status: TASK SET FULL" :
"report: host busy"));
if (scsi_result)
goto respond_in_thread;
else
return SCSI_MLQUEUE_HOST_BUSY;
}
__set_bit(k, queued_in_use_bm);
atomic_inc(&devip->num_in_q);
sqcp = &queued_arr[k];
sqcp->a_cmnd = cmnd;
cmnd->result = scsi_result;
spin_unlock_irqrestore(&queued_arr_lock, iflags);
if (delta_jiff > 0) {
if (NULL == sqcp->cmnd_timerp) {
sqcp->cmnd_timerp = kmalloc(sizeof(struct timer_list),
GFP_ATOMIC);
if (NULL == sqcp->cmnd_timerp)
return SCSI_MLQUEUE_HOST_BUSY;
init_timer(sqcp->cmnd_timerp);
}
sqcp->cmnd_timerp->function = sdebug_q_cmd_complete;
sqcp->cmnd_timerp->data = k;
sqcp->cmnd_timerp->expires = get_jiffies_64() + delta_jiff;
add_timer(sqcp->cmnd_timerp);
} else if (scsi_debug_ndelay > 0) {
ktime_t kt = ktime_set(0, scsi_debug_ndelay);
struct sdebug_hrtimer *sd_hp = sqcp->sd_hrtp;
if (NULL == sd_hp) {
sd_hp = kmalloc(sizeof(*sd_hp), GFP_ATOMIC);
if (NULL == sd_hp)
return SCSI_MLQUEUE_HOST_BUSY;
sqcp->sd_hrtp = sd_hp;
hrtimer_init(&sd_hp->hrt, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
sd_hp->hrt.function = sdebug_q_cmd_hrt_complete;
sd_hp->qa_indx = k;
}
hrtimer_start(&sd_hp->hrt, kt, HRTIMER_MODE_REL);
} else {
if (NULL == sqcp->tletp) {
sqcp->tletp = kmalloc(sizeof(*sqcp->tletp),
GFP_ATOMIC);
if (NULL == sqcp->tletp)
return SCSI_MLQUEUE_HOST_BUSY;
tasklet_init(sqcp->tletp,
sdebug_q_cmd_complete, k);
}
if (-1 == delta_jiff)
tasklet_hi_schedule(sqcp->tletp);
else
tasklet_schedule(sqcp->tletp);
}
if ((SCSI_DEBUG_OPT_Q_NOISE & scsi_debug_opts) &&
(scsi_result == device_qfull_result))
sdev_printk(KERN_INFO, sdp,
"%s: num_in_q=%d +1, %s%s\n", __func__,
num_in_q, (inject ? "<inject> " : ""),
"status: TASK SET FULL");
return 0;
respond_in_thread:
cmnd->result = scsi_result;
cmnd->scsi_done(cmnd);
return 0;
}
static const char * scsi_debug_info(struct Scsi_Host * shp)
{
sprintf(sdebug_info, "scsi_debug, version %s [%s], "
"dev_size_mb=%d, opts=0x%x", SCSI_DEBUG_VERSION,
scsi_debug_version_date, scsi_debug_dev_size_mb,
scsi_debug_opts);
return sdebug_info;
}
static int scsi_debug_write_info(struct Scsi_Host *host, char *buffer, int length)
{
char arr[16];
int opts;
int minLen = length > 15 ? 15 : length;
if (!capable(CAP_SYS_ADMIN) || !capable(CAP_SYS_RAWIO))
return -EACCES;
memcpy(arr, buffer, minLen);
arr[minLen] = '\0';
if (1 != sscanf(arr, "%d", &opts))
return -EINVAL;
scsi_debug_opts = opts;
if (scsi_debug_every_nth != 0)
atomic_set(&sdebug_cmnd_count, 0);
return length;
}
static int scsi_debug_show_info(struct seq_file *m, struct Scsi_Host *host)
{
int f, l;
char b[32];
if (scsi_debug_every_nth > 0)
snprintf(b, sizeof(b), " (curr:%d)",
((SCSI_DEBUG_OPT_RARE_TSF & scsi_debug_opts) ?
atomic_read(&sdebug_a_tsf) :
atomic_read(&sdebug_cmnd_count)));
else
b[0] = '\0';
seq_printf(m, "scsi_debug adapter driver, version %s [%s]\n"
"num_tgts=%d, shared (ram) size=%d MB, opts=0x%x, "
"every_nth=%d%s\n"
"delay=%d, ndelay=%d, max_luns=%d, q_completions=%d\n"
"sector_size=%d bytes, cylinders=%d, heads=%d, sectors=%d\n"
"command aborts=%d; RESETs: device=%d, target=%d, bus=%d, "
"host=%d\ndix_reads=%d dix_writes=%d dif_errors=%d "
"usec_in_jiffy=%lu\n",
SCSI_DEBUG_VERSION, scsi_debug_version_date,
scsi_debug_num_tgts, scsi_debug_dev_size_mb, scsi_debug_opts,
scsi_debug_every_nth, b, scsi_debug_delay, scsi_debug_ndelay,
scsi_debug_max_luns, atomic_read(&sdebug_completions),
scsi_debug_sector_size, sdebug_cylinders_per, sdebug_heads,
sdebug_sectors_per, num_aborts, num_dev_resets,
num_target_resets, num_bus_resets, num_host_resets,
dix_reads, dix_writes, dif_errors, TICK_NSEC / 1000);
f = find_first_bit(queued_in_use_bm, scsi_debug_max_queue);
if (f != scsi_debug_max_queue) {
l = find_last_bit(queued_in_use_bm, scsi_debug_max_queue);
seq_printf(m, " %s BUSY: first,last bits set: %d,%d\n",
"queued_in_use_bm", f, l);
}
return 0;
}
static ssize_t delay_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_delay);
}
static ssize_t delay_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int delay, res;
if ((count > 0) && (1 == sscanf(buf, "%d", &delay))) {
res = count;
if (scsi_debug_delay != delay) {
unsigned long iflags;
int k;
spin_lock_irqsave(&queued_arr_lock, iflags);
k = find_first_bit(queued_in_use_bm,
scsi_debug_max_queue);
if (k != scsi_debug_max_queue)
res = -EBUSY;
else {
scsi_debug_delay = delay;
scsi_debug_ndelay = 0;
}
spin_unlock_irqrestore(&queued_arr_lock, iflags);
}
return res;
}
return -EINVAL;
}
static ssize_t ndelay_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_ndelay);
}
static ssize_t ndelay_store(struct device_driver *ddp, const char *buf,
size_t count)
{
unsigned long iflags;
int ndelay, res, k;
if ((count > 0) && (1 == sscanf(buf, "%d", &ndelay)) &&
(ndelay >= 0) && (ndelay < 1000000000)) {
res = count;
if (scsi_debug_ndelay != ndelay) {
spin_lock_irqsave(&queued_arr_lock, iflags);
k = find_first_bit(queued_in_use_bm,
scsi_debug_max_queue);
if (k != scsi_debug_max_queue)
res = -EBUSY;
else {
scsi_debug_ndelay = ndelay;
scsi_debug_delay = ndelay ? DELAY_OVERRIDDEN
: DEF_DELAY;
}
spin_unlock_irqrestore(&queued_arr_lock, iflags);
}
return res;
}
return -EINVAL;
}
static ssize_t opts_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "0x%x\n", scsi_debug_opts);
}
static ssize_t opts_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int opts;
char work[20];
if (1 == sscanf(buf, "%10s", work)) {
if (0 == strncasecmp(work,"0x", 2)) {
if (1 == sscanf(&work[2], "%x", &opts))
goto opts_done;
} else {
if (1 == sscanf(work, "%d", &opts))
goto opts_done;
}
}
return -EINVAL;
opts_done:
scsi_debug_opts = opts;
if (SCSI_DEBUG_OPT_RECOVERED_ERR & opts)
sdebug_any_injecting_opt = true;
else if (SCSI_DEBUG_OPT_TRANSPORT_ERR & opts)
sdebug_any_injecting_opt = true;
else if (SCSI_DEBUG_OPT_DIF_ERR & opts)
sdebug_any_injecting_opt = true;
else if (SCSI_DEBUG_OPT_DIX_ERR & opts)
sdebug_any_injecting_opt = true;
else if (SCSI_DEBUG_OPT_SHORT_TRANSFER & opts)
sdebug_any_injecting_opt = true;
atomic_set(&sdebug_cmnd_count, 0);
atomic_set(&sdebug_a_tsf, 0);
return count;
}
static ssize_t ptype_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_ptype);
}
static ssize_t ptype_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_ptype = n;
return count;
}
return -EINVAL;
}
static ssize_t dsense_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_dsense);
}
static ssize_t dsense_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_dsense = n;
return count;
}
return -EINVAL;
}
static ssize_t fake_rw_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_fake_rw);
}
static ssize_t fake_rw_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
n = (n > 0);
scsi_debug_fake_rw = (scsi_debug_fake_rw > 0);
if (scsi_debug_fake_rw != n) {
if ((0 == n) && (NULL == fake_storep)) {
unsigned long sz =
(unsigned long)scsi_debug_dev_size_mb *
1048576;
fake_storep = vmalloc(sz);
if (NULL == fake_storep) {
pr_err("%s: out of memory, 9\n",
__func__);
return -ENOMEM;
}
memset(fake_storep, 0, sz);
}
scsi_debug_fake_rw = n;
}
return count;
}
return -EINVAL;
}
static ssize_t no_lun_0_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_no_lun_0);
}
static ssize_t no_lun_0_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_no_lun_0 = n;
return count;
}
return -EINVAL;
}
static ssize_t num_tgts_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_num_tgts);
}
static ssize_t num_tgts_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_num_tgts = n;
sdebug_max_tgts_luns();
return count;
}
return -EINVAL;
}
static ssize_t dev_size_mb_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_dev_size_mb);
}
static ssize_t num_parts_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_num_parts);
}
static ssize_t every_nth_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_every_nth);
}
static ssize_t every_nth_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int nth;
if ((count > 0) && (1 == sscanf(buf, "%d", &nth))) {
scsi_debug_every_nth = nth;
atomic_set(&sdebug_cmnd_count, 0);
return count;
}
return -EINVAL;
}
static ssize_t max_luns_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_max_luns);
}
static ssize_t max_luns_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_max_luns = n;
sdebug_max_tgts_luns();
return count;
}
return -EINVAL;
}
static ssize_t max_queue_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_max_queue);
}
static ssize_t max_queue_store(struct device_driver *ddp, const char *buf,
size_t count)
{
unsigned long iflags;
int n, k;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n > 0) &&
(n <= SCSI_DEBUG_CANQUEUE)) {
spin_lock_irqsave(&queued_arr_lock, iflags);
k = find_last_bit(queued_in_use_bm, SCSI_DEBUG_CANQUEUE);
scsi_debug_max_queue = n;
if (SCSI_DEBUG_CANQUEUE == k)
atomic_set(&retired_max_queue, 0);
else if (k >= n)
atomic_set(&retired_max_queue, k + 1);
else
atomic_set(&retired_max_queue, 0);
spin_unlock_irqrestore(&queued_arr_lock, iflags);
return count;
}
return -EINVAL;
}
static ssize_t no_uld_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_no_uld);
}
static ssize_t scsi_level_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_scsi_level);
}
static ssize_t virtual_gb_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_virtual_gb);
}
static ssize_t virtual_gb_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int n;
bool changed;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
changed = (scsi_debug_virtual_gb != n);
scsi_debug_virtual_gb = n;
sdebug_capacity = get_sdebug_capacity();
if (changed) {
struct sdebug_host_info *sdhp;
struct sdebug_dev_info *dp;
spin_lock(&sdebug_host_list_lock);
list_for_each_entry(sdhp, &sdebug_host_list,
host_list) {
list_for_each_entry(dp, &sdhp->dev_info_list,
dev_list) {
set_bit(SDEBUG_UA_CAPACITY_CHANGED,
dp->uas_bm);
}
}
spin_unlock(&sdebug_host_list_lock);
}
return count;
}
return -EINVAL;
}
static ssize_t add_host_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_add_host);
}
static ssize_t add_host_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int delta_hosts;
if (sscanf(buf, "%d", &delta_hosts) != 1)
return -EINVAL;
if (delta_hosts > 0) {
do {
sdebug_add_adapter();
} while (--delta_hosts);
} else if (delta_hosts < 0) {
do {
sdebug_remove_adapter();
} while (++delta_hosts);
}
return count;
}
static ssize_t vpd_use_hostno_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_vpd_use_hostno);
}
static ssize_t vpd_use_hostno_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_vpd_use_hostno = n;
return count;
}
return -EINVAL;
}
static ssize_t sector_size_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%u\n", scsi_debug_sector_size);
}
static ssize_t dix_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_dix);
}
static ssize_t dif_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_dif);
}
static ssize_t guard_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%u\n", scsi_debug_guard);
}
static ssize_t ato_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_ato);
}
static ssize_t map_show(struct device_driver *ddp, char *buf)
{
ssize_t count;
if (!scsi_debug_lbp())
return scnprintf(buf, PAGE_SIZE, "0-%u\n",
sdebug_store_sectors);
count = bitmap_scnlistprintf(buf, PAGE_SIZE, map_storep, map_size);
buf[count++] = '\n';
buf[count++] = 0;
return count;
}
static ssize_t removable_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_removable ? 1 : 0);
}
static ssize_t removable_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_removable = (n > 0);
return count;
}
return -EINVAL;
}
static ssize_t host_lock_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", !!scsi_debug_host_lock);
}
static ssize_t host_lock_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int n, res;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
bool new_host_lock = (n > 0);
res = count;
if (new_host_lock != scsi_debug_host_lock) {
unsigned long iflags;
int k;
spin_lock_irqsave(&queued_arr_lock, iflags);
k = find_first_bit(queued_in_use_bm,
scsi_debug_max_queue);
if (k != scsi_debug_max_queue)
res = -EBUSY;
else
scsi_debug_host_lock = new_host_lock;
spin_unlock_irqrestore(&queued_arr_lock, iflags);
}
return res;
}
return -EINVAL;
}
static ssize_t strict_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", !!scsi_debug_strict);
}
static ssize_t strict_store(struct device_driver *ddp, const char *buf,
size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_strict = (n > 0);
return count;
}
return -EINVAL;
}
static int __init scsi_debug_init(void)
{
unsigned long sz;
int host_to_add;
int k;
int ret;
atomic_set(&sdebug_cmnd_count, 0);
atomic_set(&sdebug_completions, 0);
atomic_set(&retired_max_queue, 0);
if (scsi_debug_ndelay >= 1000000000) {
pr_warn("%s: ndelay must be less than 1 second, ignored\n",
__func__);
scsi_debug_ndelay = 0;
} else if (scsi_debug_ndelay > 0)
scsi_debug_delay = DELAY_OVERRIDDEN;
switch (scsi_debug_sector_size) {
case 512:
case 1024:
case 2048:
case 4096:
break;
default:
pr_err("%s: invalid sector_size %d\n", __func__,
scsi_debug_sector_size);
return -EINVAL;
}
switch (scsi_debug_dif) {
case SD_DIF_TYPE0_PROTECTION:
case SD_DIF_TYPE1_PROTECTION:
case SD_DIF_TYPE2_PROTECTION:
case SD_DIF_TYPE3_PROTECTION:
break;
default:
pr_err("%s: dif must be 0, 1, 2 or 3\n", __func__);
return -EINVAL;
}
if (scsi_debug_guard > 1) {
pr_err("%s: guard must be 0 or 1\n", __func__);
return -EINVAL;
}
if (scsi_debug_ato > 1) {
pr_err("%s: ato must be 0 or 1\n", __func__);
return -EINVAL;
}
if (scsi_debug_physblk_exp > 15) {
pr_err("%s: invalid physblk_exp %u\n", __func__,
scsi_debug_physblk_exp);
return -EINVAL;
}
if (scsi_debug_lowest_aligned > 0x3fff) {
pr_err("%s: lowest_aligned too big: %u\n", __func__,
scsi_debug_lowest_aligned);
return -EINVAL;
}
if (scsi_debug_dev_size_mb < 1)
scsi_debug_dev_size_mb = 1;
sz = (unsigned long)scsi_debug_dev_size_mb * 1048576;
sdebug_store_sectors = sz / scsi_debug_sector_size;
sdebug_capacity = get_sdebug_capacity();
sdebug_heads = 8;
sdebug_sectors_per = 32;
if (scsi_debug_dev_size_mb >= 16)
sdebug_heads = 32;
else if (scsi_debug_dev_size_mb >= 256)
sdebug_heads = 64;
sdebug_cylinders_per = (unsigned long)sdebug_capacity /
(sdebug_sectors_per * sdebug_heads);
if (sdebug_cylinders_per >= 1024) {
sdebug_heads = 255;
sdebug_sectors_per = 63;
sdebug_cylinders_per = (unsigned long)sdebug_capacity /
(sdebug_sectors_per * sdebug_heads);
}
if (0 == scsi_debug_fake_rw) {
fake_storep = vmalloc(sz);
if (NULL == fake_storep) {
pr_err("%s: out of memory, 1\n", __func__);
return -ENOMEM;
}
memset(fake_storep, 0, sz);
if (scsi_debug_num_parts > 0)
sdebug_build_parts(fake_storep, sz);
}
if (scsi_debug_dix) {
int dif_size;
dif_size = sdebug_store_sectors * sizeof(struct sd_dif_tuple);
dif_storep = vmalloc(dif_size);
pr_err("%s: dif_storep %u bytes @ %p\n", __func__, dif_size,
dif_storep);
if (dif_storep == NULL) {
pr_err("%s: out of mem. (DIX)\n", __func__);
ret = -ENOMEM;
goto free_vm;
}
memset(dif_storep, 0xff, dif_size);
}
if (scsi_debug_lbp()) {
scsi_debug_unmap_max_blocks =
clamp(scsi_debug_unmap_max_blocks, 0U, 0xffffffffU);
scsi_debug_unmap_max_desc =
clamp(scsi_debug_unmap_max_desc, 0U, 256U);
scsi_debug_unmap_granularity =
clamp(scsi_debug_unmap_granularity, 1U, 0xffffffffU);
if (scsi_debug_unmap_alignment &&
scsi_debug_unmap_granularity <=
scsi_debug_unmap_alignment) {
pr_err("%s: ERR: unmap_granularity <= unmap_alignment\n",
__func__);
return -EINVAL;
}
map_size = lba_to_map_index(sdebug_store_sectors - 1) + 1;
map_storep = vmalloc(BITS_TO_LONGS(map_size) * sizeof(long));
pr_info("%s: %lu provisioning blocks\n", __func__, map_size);
if (map_storep == NULL) {
pr_err("%s: out of mem. (MAP)\n", __func__);
ret = -ENOMEM;
goto free_vm;
}
bitmap_zero(map_storep, map_size);
if (scsi_debug_num_parts)
map_region(0, 2);
}
pseudo_primary = root_device_register("pseudo_0");
if (IS_ERR(pseudo_primary)) {
pr_warn("%s: root_device_register() error\n", __func__);
ret = PTR_ERR(pseudo_primary);
goto free_vm;
}
ret = bus_register(&pseudo_lld_bus);
if (ret < 0) {
pr_warn("%s: bus_register error: %d\n", __func__, ret);
goto dev_unreg;
}
ret = driver_register(&sdebug_driverfs_driver);
if (ret < 0) {
pr_warn("%s: driver_register error: %d\n", __func__, ret);
goto bus_unreg;
}
host_to_add = scsi_debug_add_host;
scsi_debug_add_host = 0;
for (k = 0; k < host_to_add; k++) {
if (sdebug_add_adapter()) {
pr_err("%s: sdebug_add_adapter failed k=%d\n",
__func__, k);
break;
}
}
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts) {
pr_info("%s: built %d host(s)\n", __func__,
scsi_debug_add_host);
}
return 0;
bus_unreg:
bus_unregister(&pseudo_lld_bus);
dev_unreg:
root_device_unregister(pseudo_primary);
free_vm:
if (map_storep)
vfree(map_storep);
if (dif_storep)
vfree(dif_storep);
vfree(fake_storep);
return ret;
}
static void __exit scsi_debug_exit(void)
{
int k = scsi_debug_add_host;
stop_all_queued();
free_all_queued();
for (; k; k--)
sdebug_remove_adapter();
driver_unregister(&sdebug_driverfs_driver);
bus_unregister(&pseudo_lld_bus);
root_device_unregister(pseudo_primary);
if (dif_storep)
vfree(dif_storep);
vfree(fake_storep);
}
static void sdebug_release_adapter(struct device * dev)
{
struct sdebug_host_info *sdbg_host;
sdbg_host = to_sdebug_host(dev);
kfree(sdbg_host);
}
static int sdebug_add_adapter(void)
{
int k, devs_per_host;
int error = 0;
struct sdebug_host_info *sdbg_host;
struct sdebug_dev_info *sdbg_devinfo, *tmp;
sdbg_host = kzalloc(sizeof(*sdbg_host),GFP_KERNEL);
if (NULL == sdbg_host) {
printk(KERN_ERR "%s: out of memory at line %d\n",
__func__, __LINE__);
return -ENOMEM;
}
INIT_LIST_HEAD(&sdbg_host->dev_info_list);
devs_per_host = scsi_debug_num_tgts * scsi_debug_max_luns;
for (k = 0; k < devs_per_host; k++) {
sdbg_devinfo = sdebug_device_create(sdbg_host, GFP_KERNEL);
if (!sdbg_devinfo) {
printk(KERN_ERR "%s: out of memory at line %d\n",
__func__, __LINE__);
error = -ENOMEM;
goto clean;
}
}
spin_lock(&sdebug_host_list_lock);
list_add_tail(&sdbg_host->host_list, &sdebug_host_list);
spin_unlock(&sdebug_host_list_lock);
sdbg_host->dev.bus = &pseudo_lld_bus;
sdbg_host->dev.parent = pseudo_primary;
sdbg_host->dev.release = &sdebug_release_adapter;
dev_set_name(&sdbg_host->dev, "adapter%d", scsi_debug_add_host);
error = device_register(&sdbg_host->dev);
if (error)
goto clean;
++scsi_debug_add_host;
return error;
clean:
list_for_each_entry_safe(sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
list_del(&sdbg_devinfo->dev_list);
kfree(sdbg_devinfo);
}
kfree(sdbg_host);
return error;
}
static void sdebug_remove_adapter(void)
{
struct sdebug_host_info * sdbg_host = NULL;
spin_lock(&sdebug_host_list_lock);
if (!list_empty(&sdebug_host_list)) {
sdbg_host = list_entry(sdebug_host_list.prev,
struct sdebug_host_info, host_list);
list_del(&sdbg_host->host_list);
}
spin_unlock(&sdebug_host_list_lock);
if (!sdbg_host)
return;
device_unregister(&sdbg_host->dev);
--scsi_debug_add_host;
}
static int
sdebug_change_qdepth(struct scsi_device *sdev, int qdepth)
{
int num_in_q = 0;
unsigned long iflags;
struct sdebug_dev_info *devip;
spin_lock_irqsave(&queued_arr_lock, iflags);
devip = (struct sdebug_dev_info *)sdev->hostdata;
if (NULL == devip) {
spin_unlock_irqrestore(&queued_arr_lock, iflags);
return -ENODEV;
}
num_in_q = atomic_read(&devip->num_in_q);
spin_unlock_irqrestore(&queued_arr_lock, iflags);
if (qdepth < 1)
qdepth = 1;
if (qdepth > SCSI_DEBUG_CANQUEUE + 10)
qdepth = SCSI_DEBUG_CANQUEUE + 10;
scsi_change_queue_depth(sdev, qdepth);
if (SCSI_DEBUG_OPT_Q_NOISE & scsi_debug_opts) {
sdev_printk(KERN_INFO, sdev,
"%s: qdepth=%d, num_in_q=%d\n",
__func__, qdepth, num_in_q);
}
return sdev->queue_depth;
}
static int
check_inject(struct scsi_cmnd *scp)
{
struct sdebug_scmd_extra_t *ep = scsi_cmd_priv(scp);
memset(ep, 0, sizeof(struct sdebug_scmd_extra_t));
if (atomic_inc_return(&sdebug_cmnd_count) >=
abs(scsi_debug_every_nth)) {
atomic_set(&sdebug_cmnd_count, 0);
if (scsi_debug_every_nth < -1)
scsi_debug_every_nth = -1;
if (SCSI_DEBUG_OPT_TIMEOUT & scsi_debug_opts)
return 1;
else if (SCSI_DEBUG_OPT_MAC_TIMEOUT & scsi_debug_opts &&
scsi_medium_access_command(scp))
return 1;
if (sdebug_any_injecting_opt) {
int opts = scsi_debug_opts;
if (SCSI_DEBUG_OPT_RECOVERED_ERR & opts)
ep->inj_recovered = true;
else if (SCSI_DEBUG_OPT_TRANSPORT_ERR & opts)
ep->inj_transport = true;
else if (SCSI_DEBUG_OPT_DIF_ERR & opts)
ep->inj_dif = true;
else if (SCSI_DEBUG_OPT_DIX_ERR & opts)
ep->inj_dix = true;
else if (SCSI_DEBUG_OPT_SHORT_TRANSFER & opts)
ep->inj_short = true;
}
}
return 0;
}
static int
scsi_debug_queuecommand(struct scsi_cmnd *scp)
{
u8 sdeb_i;
struct scsi_device *sdp = scp->device;
const struct opcode_info_t *oip;
const struct opcode_info_t *r_oip;
struct sdebug_dev_info *devip;
u8 *cmd = scp->cmnd;
int (*r_pfp)(struct scsi_cmnd *, struct sdebug_dev_info *);
int k, na;
int errsts = 0;
int errsts_no_connect = DID_NO_CONNECT << 16;
u32 flags;
u16 sa;
u8 opcode = cmd[0];
bool has_wlun_rl;
bool debug = !!(SCSI_DEBUG_OPT_NOISE & scsi_debug_opts);
scsi_set_resid(scp, 0);
if (debug && !(SCSI_DEBUG_OPT_NO_CDB_NOISE & scsi_debug_opts)) {
char b[120];
int n, len, sb;
len = scp->cmd_len;
sb = (int)sizeof(b);
if (len > 32)
strcpy(b, "too long, over 32 bytes");
else {
for (k = 0, n = 0; k < len && n < sb; ++k)
n += scnprintf(b + n, sb - n, "%02x ",
(u32)cmd[k]);
}
sdev_printk(KERN_INFO, sdp, "%s: cmd %s\n", my_name, b);
}
has_wlun_rl = (sdp->lun == SAM2_WLUN_REPORT_LUNS);
if ((sdp->lun >= scsi_debug_max_luns) && !has_wlun_rl)
return schedule_resp(scp, NULL, errsts_no_connect, 0);
sdeb_i = opcode_ind_arr[opcode];
oip = &opcode_info_arr[sdeb_i];
devip = (struct sdebug_dev_info *)sdp->hostdata;
if (!devip) {
devip = devInfoReg(sdp);
if (NULL == devip)
return schedule_resp(scp, NULL, errsts_no_connect, 0);
}
na = oip->num_attached;
r_pfp = oip->pfp;
if (na) {
r_oip = oip;
if (FF_SA & r_oip->flags) {
if (F_SA_LOW & oip->flags)
sa = 0x1f & cmd[1];
else
sa = get_unaligned_be16(cmd + 8);
for (k = 0; k <= na; oip = r_oip->arrp + k++) {
if (opcode == oip->opcode && sa == oip->sa)
break;
}
} else {
for (k = 0; k <= na; oip = r_oip->arrp + k++) {
if (opcode == oip->opcode)
break;
}
}
if (k > na) {
if (F_SA_LOW & r_oip->flags)
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 1, 4);
else if (F_SA_HIGH & r_oip->flags)
mk_sense_invalid_fld(scp, SDEB_IN_CDB, 8, 7);
else
mk_sense_invalid_opcode(scp);
goto check_cond;
}
}
flags = oip->flags;
if (F_INV_OP & flags) {
mk_sense_invalid_opcode(scp);
goto check_cond;
}
if (has_wlun_rl && !(F_RL_WLUN_OK & flags)) {
if (debug)
sdev_printk(KERN_INFO, sdp, "scsi_debug: Opcode: "
"0x%x not supported for wlun\n", opcode);
mk_sense_invalid_opcode(scp);
goto check_cond;
}
if (scsi_debug_strict) {
u8 rem;
int j;
for (k = 1; k < oip->len_mask[0] && k < 16; ++k) {
rem = ~oip->len_mask[k] & cmd[k];
if (rem) {
for (j = 7; j >= 0; --j, rem <<= 1) {
if (0x80 & rem)
break;
}
mk_sense_invalid_fld(scp, SDEB_IN_CDB, k, j);
goto check_cond;
}
}
}
if (!(F_SKIP_UA & flags) &&
SDEBUG_NUM_UAS != find_first_bit(devip->uas_bm, SDEBUG_NUM_UAS)) {
errsts = check_readiness(scp, UAS_ONLY, devip);
if (errsts)
goto check_cond;
}
if ((F_M_ACCESS & flags) && devip->stopped) {
mk_sense_buffer(scp, NOT_READY, LOGICAL_UNIT_NOT_READY, 0x2);
if (debug)
sdev_printk(KERN_INFO, sdp, "%s reports: Not ready: "
"%s\n", my_name, "initializing command "
"required");
errsts = check_condition_result;
goto fini;
}
if (scsi_debug_fake_rw && (F_FAKE_RW & flags))
goto fini;
if (scsi_debug_every_nth) {
if (check_inject(scp))
return 0;
}
if (oip->pfp)
errsts = oip->pfp(scp, devip);
else if (r_pfp)
errsts = r_pfp(scp, devip);
fini:
return schedule_resp(scp, devip, errsts,
((F_DELAY_OVERR & flags) ? 0 : scsi_debug_delay));
check_cond:
return schedule_resp(scp, devip, check_condition_result, 0);
}
static int
sdebug_queuecommand_lock_or_not(struct Scsi_Host *shost, struct scsi_cmnd *cmd)
{
if (scsi_debug_host_lock) {
unsigned long iflags;
int rc;
spin_lock_irqsave(shost->host_lock, iflags);
rc = scsi_debug_queuecommand(cmd);
spin_unlock_irqrestore(shost->host_lock, iflags);
return rc;
} else
return scsi_debug_queuecommand(cmd);
}
static int sdebug_driver_probe(struct device * dev)
{
int error = 0;
int opts;
struct sdebug_host_info *sdbg_host;
struct Scsi_Host *hpnt;
int host_prot;
sdbg_host = to_sdebug_host(dev);
sdebug_driver_template.can_queue = scsi_debug_max_queue;
if (scsi_debug_clustering)
sdebug_driver_template.use_clustering = ENABLE_CLUSTERING;
hpnt = scsi_host_alloc(&sdebug_driver_template, sizeof(sdbg_host));
if (NULL == hpnt) {
pr_err("%s: scsi_host_alloc failed\n", __func__);
error = -ENODEV;
return error;
}
sdbg_host->shost = hpnt;
*((struct sdebug_host_info **)hpnt->hostdata) = sdbg_host;
if ((hpnt->this_id >= 0) && (scsi_debug_num_tgts > hpnt->this_id))
hpnt->max_id = scsi_debug_num_tgts + 1;
else
hpnt->max_id = scsi_debug_num_tgts;
hpnt->max_lun = SAM2_WLUN_REPORT_LUNS;
host_prot = 0;
switch (scsi_debug_dif) {
case SD_DIF_TYPE1_PROTECTION:
host_prot = SHOST_DIF_TYPE1_PROTECTION;
if (scsi_debug_dix)
host_prot |= SHOST_DIX_TYPE1_PROTECTION;
break;
case SD_DIF_TYPE2_PROTECTION:
host_prot = SHOST_DIF_TYPE2_PROTECTION;
if (scsi_debug_dix)
host_prot |= SHOST_DIX_TYPE2_PROTECTION;
break;
case SD_DIF_TYPE3_PROTECTION:
host_prot = SHOST_DIF_TYPE3_PROTECTION;
if (scsi_debug_dix)
host_prot |= SHOST_DIX_TYPE3_PROTECTION;
break;
default:
if (scsi_debug_dix)
host_prot |= SHOST_DIX_TYPE0_PROTECTION;
break;
}
scsi_host_set_prot(hpnt, host_prot);
printk(KERN_INFO "scsi_debug: host protection%s%s%s%s%s%s%s\n",
(host_prot & SHOST_DIF_TYPE1_PROTECTION) ? " DIF1" : "",
(host_prot & SHOST_DIF_TYPE2_PROTECTION) ? " DIF2" : "",
(host_prot & SHOST_DIF_TYPE3_PROTECTION) ? " DIF3" : "",
(host_prot & SHOST_DIX_TYPE0_PROTECTION) ? " DIX0" : "",
(host_prot & SHOST_DIX_TYPE1_PROTECTION) ? " DIX1" : "",
(host_prot & SHOST_DIX_TYPE2_PROTECTION) ? " DIX2" : "",
(host_prot & SHOST_DIX_TYPE3_PROTECTION) ? " DIX3" : "");
if (scsi_debug_guard == 1)
scsi_host_set_guard(hpnt, SHOST_DIX_GUARD_IP);
else
scsi_host_set_guard(hpnt, SHOST_DIX_GUARD_CRC);
opts = scsi_debug_opts;
if (SCSI_DEBUG_OPT_RECOVERED_ERR & opts)
sdebug_any_injecting_opt = true;
else if (SCSI_DEBUG_OPT_TRANSPORT_ERR & opts)
sdebug_any_injecting_opt = true;
else if (SCSI_DEBUG_OPT_DIF_ERR & opts)
sdebug_any_injecting_opt = true;
else if (SCSI_DEBUG_OPT_DIX_ERR & opts)
sdebug_any_injecting_opt = true;
else if (SCSI_DEBUG_OPT_SHORT_TRANSFER & opts)
sdebug_any_injecting_opt = true;
error = scsi_add_host(hpnt, &sdbg_host->dev);
if (error) {
printk(KERN_ERR "%s: scsi_add_host failed\n", __func__);
error = -ENODEV;
scsi_host_put(hpnt);
} else
scsi_scan_host(hpnt);
return error;
}
static int sdebug_driver_remove(struct device * dev)
{
struct sdebug_host_info *sdbg_host;
struct sdebug_dev_info *sdbg_devinfo, *tmp;
sdbg_host = to_sdebug_host(dev);
if (!sdbg_host) {
printk(KERN_ERR "%s: Unable to locate host info\n",
__func__);
return -ENODEV;
}
scsi_remove_host(sdbg_host->shost);
list_for_each_entry_safe(sdbg_devinfo, tmp, &sdbg_host->dev_info_list,
dev_list) {
list_del(&sdbg_devinfo->dev_list);
kfree(sdbg_devinfo);
}
scsi_host_put(sdbg_host->shost);
return 0;
}
static int pseudo_lld_bus_match(struct device *dev,
struct device_driver *dev_driver)
{
return 1;
}
