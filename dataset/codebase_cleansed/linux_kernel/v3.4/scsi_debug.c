static unsigned int scsi_debug_lbp(void)
{
return scsi_debug_lbpu | scsi_debug_lbpws | scsi_debug_lbpws10;
}
static inline sector_t dif_offset(sector_t sector)
{
return sector << 3;
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
static void mk_sense_buffer(struct sdebug_dev_info *devip, int key,
int asc, int asq)
{
unsigned char *sbuff;
sbuff = devip->sense_buff;
memset(sbuff, 0, SDEBUG_SENSE_LEN);
scsi_build_sense_buffer(scsi_debug_dsense, sbuff, key, asc, asq);
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: [sense_key,asc,ascq]: "
"[0x%x,0x%x,0x%x]\n", key, asc, asq);
}
static void get_data_transfer_info(unsigned char *cmd,
unsigned long long *lba, unsigned int *num,
u32 *ei_lba)
{
*ei_lba = 0;
switch (*cmd) {
case VARIABLE_LENGTH_CMD:
*lba = (u64)cmd[19] | (u64)cmd[18] << 8 |
(u64)cmd[17] << 16 | (u64)cmd[16] << 24 |
(u64)cmd[15] << 32 | (u64)cmd[14] << 40 |
(u64)cmd[13] << 48 | (u64)cmd[12] << 56;
*ei_lba = (u32)cmd[23] | (u32)cmd[22] << 8 |
(u32)cmd[21] << 16 | (u32)cmd[20] << 24;
*num = (u32)cmd[31] | (u32)cmd[30] << 8 | (u32)cmd[29] << 16 |
(u32)cmd[28] << 24;
break;
case WRITE_SAME_16:
case WRITE_16:
case READ_16:
*lba = (u64)cmd[9] | (u64)cmd[8] << 8 |
(u64)cmd[7] << 16 | (u64)cmd[6] << 24 |
(u64)cmd[5] << 32 | (u64)cmd[4] << 40 |
(u64)cmd[3] << 48 | (u64)cmd[2] << 56;
*num = (u32)cmd[13] | (u32)cmd[12] << 8 | (u32)cmd[11] << 16 |
(u32)cmd[10] << 24;
break;
case WRITE_12:
case READ_12:
*lba = (u32)cmd[5] | (u32)cmd[4] << 8 | (u32)cmd[3] << 16 |
(u32)cmd[2] << 24;
*num = (u32)cmd[9] | (u32)cmd[8] << 8 | (u32)cmd[7] << 16 |
(u32)cmd[6] << 24;
break;
case WRITE_SAME:
case WRITE_10:
case READ_10:
case XDWRITEREAD_10:
*lba = (u32)cmd[5] | (u32)cmd[4] << 8 | (u32)cmd[3] << 16 |
(u32)cmd[2] << 24;
*num = (u32)cmd[8] | (u32)cmd[7] << 8;
break;
case WRITE_6:
case READ_6:
*lba = (u32)cmd[3] | (u32)cmd[2] << 8 |
(u32)(cmd[1] & 0x1f) << 16;
*num = (0 == cmd[4]) ? 256 : cmd[4];
break;
default:
break;
}
}
static int scsi_debug_ioctl(struct scsi_device *dev, int cmd, void __user *arg)
{
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts) {
printk(KERN_INFO "scsi_debug: ioctl: cmd=0x%x\n", cmd);
}
return -EINVAL;
}
static int check_readiness(struct scsi_cmnd * SCpnt, int reset_only,
struct sdebug_dev_info * devip)
{
if (devip->reset) {
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: Reporting Unit "
"attention: power on reset\n");
devip->reset = 0;
mk_sense_buffer(devip, UNIT_ATTENTION, POWERON_RESET, 0);
return check_condition_result;
}
if ((0 == reset_only) && devip->stopped) {
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: Reporting Not "
"ready: initializing command required\n");
mk_sense_buffer(devip, NOT_READY, LOGICAL_UNIT_NOT_READY,
0x2);
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
if (sdb->resid)
sdb->resid -= act_len;
else
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
static int resp_inquiry(struct scsi_cmnd * scp, int target,
struct sdebug_dev_info * devip)
{
unsigned char pq_pdt;
unsigned char * arr;
unsigned char *cmd = (unsigned char *)scp->cmnd;
int alloc_len, n, ret;
alloc_len = (cmd[3] << 8) + cmd[4];
arr = kzalloc(SDEBUG_MAX_INQ_ARR_SZ, GFP_ATOMIC);
if (! arr)
return DID_REQUEUE << 16;
if (devip->wlun)
pq_pdt = 0x1e;
else if (scsi_debug_no_lun_0 && (0 == devip->lun))
pq_pdt = 0x7f;
else
pq_pdt = (scsi_debug_ptype & 0x1f);
arr[0] = pq_pdt;
if (0x2 & cmd[1]) {
mk_sense_buffer(devip, ILLEGAL_REQUEST, INVALID_FIELD_IN_CDB,
0);
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
lu_id_num = devip->wlun ? -1 : (((host_no + 1) * 2000) +
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
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_CDB, 0);
kfree(arr);
return check_condition_result;
}
len = min(((arr[2] << 8) + arr[3]) + 4, alloc_len);
ret = fill_from_dev_buffer(scp, arr,
min(len, SDEBUG_MAX_INQ_ARR_SZ));
kfree(arr);
return ret;
}
arr[1] = DEV_REMOVEABLE(target) ? 0x80 : 0;
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
arr[58] = 0x0; arr[59] = 0x77;
arr[60] = 0x3; arr[61] = 0x14;
n = 62;
if (scsi_debug_ptype == 0) {
arr[n++] = 0x3; arr[n++] = 0x3d;
} else if (scsi_debug_ptype == 1) {
arr[n++] = 0x3; arr[n++] = 0x60;
}
arr[n++] = 0xc; arr[n++] = 0xf;
ret = fill_from_dev_buffer(scp, arr,
min(alloc_len, SDEBUG_LONG_INQ_SZ));
kfree(arr);
return ret;
}
static int resp_requests(struct scsi_cmnd * scp,
struct sdebug_dev_info * devip)
{
unsigned char * sbuff;
unsigned char *cmd = (unsigned char *)scp->cmnd;
unsigned char arr[SDEBUG_SENSE_LEN];
int want_dsense;
int len = 18;
memset(arr, 0, sizeof(arr));
if (devip->reset == 1)
mk_sense_buffer(devip, 0, NO_ADDITIONAL_SENSE, 0);
want_dsense = !!(cmd[1] & 1) || scsi_debug_dsense;
sbuff = devip->sense_buff;
if ((iec_m_pg[2] & 0x4) && (6 == (iec_m_pg[3] & 0xf))) {
if (want_dsense) {
arr[0] = 0x72;
arr[1] = 0x0;
arr[2] = THRESHOLD_EXCEEDED;
arr[3] = 0xff;
} else {
arr[0] = 0x70;
arr[2] = 0x0;
arr[7] = 0xa;
arr[12] = THRESHOLD_EXCEEDED;
arr[13] = 0xff;
}
} else {
memcpy(arr, sbuff, SDEBUG_SENSE_LEN);
if ((cmd[1] & 1) && (! scsi_debug_dsense)) {
memset(arr, 0, sizeof(arr));
arr[0] = 0x72;
arr[1] = sbuff[2];
arr[2] = sbuff[12];
arr[3] = sbuff[13];
len = 8;
}
}
mk_sense_buffer(devip, 0, NO_ADDITIONAL_SENSE, 0);
return fill_from_dev_buffer(scp, arr, len);
}
static int resp_start_stop(struct scsi_cmnd * scp,
struct sdebug_dev_info * devip)
{
unsigned char *cmd = (unsigned char *)scp->cmnd;
int power_cond, errsts, start;
if ((errsts = check_readiness(scp, 1, devip)))
return errsts;
power_cond = (cmd[4] & 0xf0) >> 4;
if (power_cond) {
mk_sense_buffer(devip, ILLEGAL_REQUEST, INVALID_FIELD_IN_CDB,
0);
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
int errsts;
if ((errsts = check_readiness(scp, 1, devip)))
return errsts;
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
unsigned char *cmd = (unsigned char *)scp->cmnd;
unsigned char arr[SDEBUG_READCAP16_ARR_SZ];
unsigned long long capac;
int errsts, k, alloc_len;
if ((errsts = check_readiness(scp, 1, devip)))
return errsts;
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
unsigned char *cmd = (unsigned char *)scp->cmnd;
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
if (DEV_REMOVEABLE(target))
p[20] |= 0x20;
if (1 == pcontrol)
memset(p + 2, 0, sizeof(format_pg) - 2);
return sizeof(format_pg);
}
static int resp_caching_pg(unsigned char * p, int pcontrol, int target)
{
unsigned char caching_pg[] = {0x8, 18, 0x14, 0, 0xff, 0xff, 0, 0,
0xff, 0xff, 0xff, 0xff, 0x80, 0x14, 0, 0, 0, 0, 0, 0};
memcpy(p, caching_pg, sizeof(caching_pg));
if (1 == pcontrol)
memset(p + 2, 0, sizeof(caching_pg) - 2);
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
static int resp_mode_sense(struct scsi_cmnd * scp, int target,
struct sdebug_dev_info * devip)
{
unsigned char dbd, llbaa;
int pcontrol, pcode, subpcode, bd_len;
unsigned char dev_spec;
int k, alloc_len, msense_6, offset, len, errsts, target_dev_id;
unsigned char * ap;
unsigned char arr[SDEBUG_MAX_MSENSE_SZ];
unsigned char *cmd = (unsigned char *)scp->cmnd;
if ((errsts = check_readiness(scp, 1, devip)))
return errsts;
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
mk_sense_buffer(devip, ILLEGAL_REQUEST, SAVING_PARAMS_UNSUP,
0);
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
mk_sense_buffer(devip, ILLEGAL_REQUEST, INVALID_FIELD_IN_CDB,
0);
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
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_CDB, 0);
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
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_CDB, 0);
return check_condition_result;
}
offset += len;
break;
default:
mk_sense_buffer(devip, ILLEGAL_REQUEST, INVALID_FIELD_IN_CDB,
0);
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
static int resp_mode_select(struct scsi_cmnd * scp, int mselect6,
struct sdebug_dev_info * devip)
{
int pf, sp, ps, md_len, bd_len, off, spf, pg_len;
int param_len, res, errsts, mpage;
unsigned char arr[SDEBUG_MAX_MSELECT_SZ];
unsigned char *cmd = (unsigned char *)scp->cmnd;
if ((errsts = check_readiness(scp, 1, devip)))
return errsts;
memset(arr, 0, sizeof(arr));
pf = cmd[1] & 0x10;
sp = cmd[1] & 0x1;
param_len = mselect6 ? cmd[4] : ((cmd[7] << 8) + cmd[8]);
if ((0 == pf) || sp || (param_len > SDEBUG_MAX_MSELECT_SZ)) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_CDB, 0);
return check_condition_result;
}
res = fetch_to_dev_buffer(scp, arr, param_len);
if (-1 == res)
return (DID_ERROR << 16);
else if ((res < param_len) &&
(SCSI_DEBUG_OPT_NOISE & scsi_debug_opts))
printk(KERN_INFO "scsi_debug: mode_select: cdb indicated=%d, "
" IO sent=%d bytes\n", param_len, res);
md_len = mselect6 ? (arr[0] + 1) : ((arr[0] << 8) + arr[1] + 2);
bd_len = mselect6 ? arr[3] : ((arr[6] << 8) + arr[7]);
if (md_len > 2) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_PARAM_LIST, 0);
return check_condition_result;
}
off = bd_len + (mselect6 ? 4 : 8);
mpage = arr[off] & 0x3f;
ps = !!(arr[off] & 0x80);
if (ps) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_PARAM_LIST, 0);
return check_condition_result;
}
spf = !!(arr[off] & 0x40);
pg_len = spf ? ((arr[off + 2] << 8) + arr[off + 3] + 4) :
(arr[off + 1] + 2);
if ((pg_len + off) > param_len) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
PARAMETER_LIST_LENGTH_ERR, 0);
return check_condition_result;
}
switch (mpage) {
case 0xa:
if (ctrl_m_pg[1] == arr[off + 1]) {
memcpy(ctrl_m_pg + 2, arr + off + 2,
sizeof(ctrl_m_pg) - 2);
scsi_debug_dsense = !!(ctrl_m_pg[2] & 0x4);
return 0;
}
break;
case 0x1c:
if (iec_m_pg[1] == arr[off + 1]) {
memcpy(iec_m_pg + 2, arr + off + 2,
sizeof(iec_m_pg) - 2);
return 0;
}
break;
default:
break;
}
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_PARAM_LIST, 0);
return check_condition_result;
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
int ppc, sp, pcontrol, pcode, subpcode, alloc_len, errsts, len, n;
unsigned char arr[SDEBUG_MAX_LSENSE_SZ];
unsigned char *cmd = (unsigned char *)scp->cmnd;
if ((errsts = check_readiness(scp, 1, devip)))
return errsts;
memset(arr, 0, sizeof(arr));
ppc = cmd[1] & 0x2;
sp = cmd[1] & 0x1;
if (ppc || sp) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_CDB, 0);
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
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_CDB, 0);
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
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_CDB, 0);
return check_condition_result;
}
} else {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_CDB, 0);
return check_condition_result;
}
len = min(((arr[2] << 8) + arr[3]) + 4, alloc_len);
return fill_from_dev_buffer(scp, arr,
min(len, SDEBUG_MAX_INQ_ARR_SZ));
}
static int check_device_access_params(struct sdebug_dev_info *devi,
unsigned long long lba, unsigned int num)
{
if (lba + num > sdebug_capacity) {
mk_sense_buffer(devi, ILLEGAL_REQUEST, ADDR_OUT_OF_RANGE, 0);
return check_condition_result;
}
if (num > sdebug_store_sectors) {
mk_sense_buffer(devi, ILLEGAL_REQUEST, INVALID_FIELD_IN_CDB, 0);
return check_condition_result;
}
return 0;
}
static int do_device_access(struct scsi_cmnd *scmd,
struct sdebug_dev_info *devi,
unsigned long long lba, unsigned int num, int write)
{
int ret;
unsigned long long block, rest = 0;
int (*func)(struct scsi_cmnd *, unsigned char *, int);
func = write ? fetch_to_dev_buffer : fill_from_dev_buffer;
block = do_div(lba, sdebug_store_sectors);
if (block + num > sdebug_store_sectors)
rest = block + num - sdebug_store_sectors;
ret = func(scmd, fake_storep + (block * scsi_debug_sector_size),
(num - rest) * scsi_debug_sector_size);
if (!ret && rest)
ret = func(scmd, fake_storep, rest * scsi_debug_sector_size);
return ret;
}
static int prot_verify_read(struct scsi_cmnd *SCpnt, sector_t start_sec,
unsigned int sectors, u32 ei_lba)
{
unsigned int i, resid;
struct scatterlist *psgl;
struct sd_dif_tuple *sdt;
sector_t sector;
sector_t tmp_sec = start_sec;
void *paddr;
start_sec = do_div(tmp_sec, sdebug_store_sectors);
sdt = (struct sd_dif_tuple *)(dif_storep + dif_offset(start_sec));
for (i = 0 ; i < sectors ; i++) {
u16 csum;
if (sdt[i].app_tag == 0xffff)
continue;
sector = start_sec + i;
switch (scsi_debug_guard) {
case 1:
csum = ip_compute_csum(fake_storep +
sector * scsi_debug_sector_size,
scsi_debug_sector_size);
break;
case 0:
csum = crc_t10dif(fake_storep +
sector * scsi_debug_sector_size,
scsi_debug_sector_size);
csum = cpu_to_be16(csum);
break;
default:
BUG();
}
if (sdt[i].guard_tag != csum) {
printk(KERN_ERR "%s: GUARD check failed on sector %lu" \
" rcvd 0x%04x, data 0x%04x\n", __func__,
(unsigned long)sector,
be16_to_cpu(sdt[i].guard_tag),
be16_to_cpu(csum));
dif_errors++;
return 0x01;
}
if (scsi_debug_dif == SD_DIF_TYPE1_PROTECTION &&
be32_to_cpu(sdt[i].ref_tag) != (sector & 0xffffffff)) {
printk(KERN_ERR "%s: REF check failed on sector %lu\n",
__func__, (unsigned long)sector);
dif_errors++;
return 0x03;
}
if (scsi_debug_dif == SD_DIF_TYPE2_PROTECTION &&
be32_to_cpu(sdt[i].ref_tag) != ei_lba) {
printk(KERN_ERR "%s: REF check failed on sector %lu\n",
__func__, (unsigned long)sector);
dif_errors++;
return 0x03;
}
ei_lba++;
}
resid = sectors * 8;
sector = start_sec;
scsi_for_each_prot_sg(SCpnt, psgl, scsi_prot_sg_count(SCpnt), i) {
int len = min(psgl->length, resid);
paddr = kmap_atomic(sg_page(psgl)) + psgl->offset;
memcpy(paddr, dif_storep + dif_offset(sector), len);
sector += len >> 3;
if (sector >= sdebug_store_sectors) {
tmp_sec = sector;
sector = do_div(tmp_sec, sdebug_store_sectors);
}
resid -= len;
kunmap_atomic(paddr);
}
dix_reads++;
return 0;
}
static int resp_read(struct scsi_cmnd *SCpnt, unsigned long long lba,
unsigned int num, struct sdebug_dev_info *devip,
u32 ei_lba)
{
unsigned long iflags;
int ret;
ret = check_device_access_params(devip, lba, num);
if (ret)
return ret;
if ((SCSI_DEBUG_OPT_MEDIUM_ERR & scsi_debug_opts) &&
(lba <= (OPT_MEDIUM_ERR_ADDR + OPT_MEDIUM_ERR_NUM - 1)) &&
((lba + num) > OPT_MEDIUM_ERR_ADDR)) {
mk_sense_buffer(devip, MEDIUM_ERROR, UNRECOVERED_READ_ERR, 0);
if (0x70 == (devip->sense_buff[0] & 0x7f)) {
devip->sense_buff[0] |= 0x80;
ret = (lba < OPT_MEDIUM_ERR_ADDR)
? OPT_MEDIUM_ERR_ADDR : (int)lba;
devip->sense_buff[3] = (ret >> 24) & 0xff;
devip->sense_buff[4] = (ret >> 16) & 0xff;
devip->sense_buff[5] = (ret >> 8) & 0xff;
devip->sense_buff[6] = ret & 0xff;
}
scsi_set_resid(SCpnt, scsi_bufflen(SCpnt));
return check_condition_result;
}
if (scsi_debug_dix && scsi_prot_sg_count(SCpnt)) {
int prot_ret = prot_verify_read(SCpnt, lba, num, ei_lba);
if (prot_ret) {
mk_sense_buffer(devip, ABORTED_COMMAND, 0x10, prot_ret);
return illegal_condition_result;
}
}
read_lock_irqsave(&atomic_rw, iflags);
ret = do_device_access(SCpnt, devip, lba, num, 0);
read_unlock_irqrestore(&atomic_rw, iflags);
return ret;
}
void dump_sector(unsigned char *buf, int len)
{
int i, j;
printk(KERN_ERR ">>> Sector Dump <<<\n");
for (i = 0 ; i < len ; i += 16) {
printk(KERN_ERR "%04d: ", i);
for (j = 0 ; j < 16 ; j++) {
unsigned char c = buf[i+j];
if (c >= 0x20 && c < 0x7e)
printk(" %c ", buf[i+j]);
else
printk("%02x ", buf[i+j]);
}
printk("\n");
}
}
static int prot_verify_write(struct scsi_cmnd *SCpnt, sector_t start_sec,
unsigned int sectors, u32 ei_lba)
{
int i, j, ret;
struct sd_dif_tuple *sdt;
struct scatterlist *dsgl = scsi_sglist(SCpnt);
struct scatterlist *psgl = scsi_prot_sglist(SCpnt);
void *daddr, *paddr;
sector_t tmp_sec = start_sec;
sector_t sector;
int ppage_offset;
unsigned short csum;
sector = do_div(tmp_sec, sdebug_store_sectors);
BUG_ON(scsi_sg_count(SCpnt) == 0);
BUG_ON(scsi_prot_sg_count(SCpnt) == 0);
paddr = kmap_atomic(sg_page(psgl)) + psgl->offset;
ppage_offset = 0;
scsi_for_each_sg(SCpnt, dsgl, scsi_sg_count(SCpnt), i) {
daddr = kmap_atomic(sg_page(dsgl)) + dsgl->offset;
for (j = 0 ; j < dsgl->length ; j += scsi_debug_sector_size) {
if (ppage_offset >= psgl->length) {
kunmap_atomic(paddr);
psgl = sg_next(psgl);
BUG_ON(psgl == NULL);
paddr = kmap_atomic(sg_page(psgl))
+ psgl->offset;
ppage_offset = 0;
}
sdt = paddr + ppage_offset;
switch (scsi_debug_guard) {
case 1:
csum = ip_compute_csum(daddr,
scsi_debug_sector_size);
break;
case 0:
csum = cpu_to_be16(crc_t10dif(daddr,
scsi_debug_sector_size));
break;
default:
BUG();
ret = 0;
goto out;
}
if (sdt->guard_tag != csum) {
printk(KERN_ERR
"%s: GUARD check failed on sector %lu " \
"rcvd 0x%04x, calculated 0x%04x\n",
__func__, (unsigned long)sector,
be16_to_cpu(sdt->guard_tag),
be16_to_cpu(csum));
ret = 0x01;
dump_sector(daddr, scsi_debug_sector_size);
goto out;
}
if (scsi_debug_dif == SD_DIF_TYPE1_PROTECTION &&
be32_to_cpu(sdt->ref_tag)
!= (start_sec & 0xffffffff)) {
printk(KERN_ERR
"%s: REF check failed on sector %lu\n",
__func__, (unsigned long)sector);
ret = 0x03;
dump_sector(daddr, scsi_debug_sector_size);
goto out;
}
if (scsi_debug_dif == SD_DIF_TYPE2_PROTECTION &&
be32_to_cpu(sdt->ref_tag) != ei_lba) {
printk(KERN_ERR
"%s: REF check failed on sector %lu\n",
__func__, (unsigned long)sector);
ret = 0x03;
dump_sector(daddr, scsi_debug_sector_size);
goto out;
}
memcpy(dif_storep + dif_offset(sector), sdt, 8);
sector++;
if (sector == sdebug_store_sectors)
sector = 0;
start_sec++;
ei_lba++;
daddr += scsi_debug_sector_size;
ppage_offset += sizeof(struct sd_dif_tuple);
}
kunmap_atomic(daddr);
}
kunmap_atomic(paddr);
dix_writes++;
return 0;
out:
dif_errors++;
kunmap_atomic(daddr);
kunmap_atomic(paddr);
return ret;
}
static unsigned int map_state(sector_t lba, unsigned int *num)
{
unsigned int granularity, alignment, mapped;
sector_t block, next, end;
granularity = scsi_debug_unmap_granularity;
alignment = granularity - scsi_debug_unmap_alignment;
block = lba + alignment;
do_div(block, granularity);
mapped = test_bit(block, map_storep);
if (mapped)
next = find_next_zero_bit(map_storep, map_size, block);
else
next = find_next_bit(map_storep, map_size, block);
end = next * granularity - scsi_debug_unmap_alignment;
*num = end - lba;
return mapped;
}
static void map_region(sector_t lba, unsigned int len)
{
unsigned int granularity, alignment;
sector_t end = lba + len;
granularity = scsi_debug_unmap_granularity;
alignment = granularity - scsi_debug_unmap_alignment;
while (lba < end) {
sector_t block, rem;
block = lba + alignment;
rem = do_div(block, granularity);
if (block < map_size)
set_bit(block, map_storep);
lba += granularity - rem;
}
}
static void unmap_region(sector_t lba, unsigned int len)
{
unsigned int granularity, alignment;
sector_t end = lba + len;
granularity = scsi_debug_unmap_granularity;
alignment = granularity - scsi_debug_unmap_alignment;
while (lba < end) {
sector_t block, rem;
block = lba + alignment;
rem = do_div(block, granularity);
if (rem == 0 && lba + granularity <= end && block < map_size) {
clear_bit(block, map_storep);
if (scsi_debug_lbprz)
memset(fake_storep +
block * scsi_debug_sector_size, 0,
scsi_debug_sector_size);
}
lba += granularity - rem;
}
}
static int resp_write(struct scsi_cmnd *SCpnt, unsigned long long lba,
unsigned int num, struct sdebug_dev_info *devip,
u32 ei_lba)
{
unsigned long iflags;
int ret;
ret = check_device_access_params(devip, lba, num);
if (ret)
return ret;
if (scsi_debug_dix && scsi_prot_sg_count(SCpnt)) {
int prot_ret = prot_verify_write(SCpnt, lba, num, ei_lba);
if (prot_ret) {
mk_sense_buffer(devip, ILLEGAL_REQUEST, 0x10, prot_ret);
return illegal_condition_result;
}
}
write_lock_irqsave(&atomic_rw, iflags);
ret = do_device_access(SCpnt, devip, lba, num, 1);
if (scsi_debug_unmap_granularity)
map_region(lba, num);
write_unlock_irqrestore(&atomic_rw, iflags);
if (-1 == ret)
return (DID_ERROR << 16);
else if ((ret < (num * scsi_debug_sector_size)) &&
(SCSI_DEBUG_OPT_NOISE & scsi_debug_opts))
printk(KERN_INFO "scsi_debug: write: cdb indicated=%u, "
" IO sent=%d bytes\n", num * scsi_debug_sector_size, ret);
return 0;
}
static int resp_write_same(struct scsi_cmnd *scmd, unsigned long long lba,
unsigned int num, struct sdebug_dev_info *devip,
u32 ei_lba, unsigned int unmap)
{
unsigned long iflags;
unsigned long long i;
int ret;
ret = check_device_access_params(devip, lba, num);
if (ret)
return ret;
if (num > scsi_debug_write_same_length) {
mk_sense_buffer(devip, ILLEGAL_REQUEST, INVALID_FIELD_IN_CDB,
0);
return check_condition_result;
}
write_lock_irqsave(&atomic_rw, iflags);
if (unmap && scsi_debug_unmap_granularity) {
unmap_region(lba, num);
goto out;
}
ret = fetch_to_dev_buffer(scmd,
fake_storep + (lba * scsi_debug_sector_size),
scsi_debug_sector_size);
if (-1 == ret) {
write_unlock_irqrestore(&atomic_rw, iflags);
return (DID_ERROR << 16);
} else if ((ret < (num * scsi_debug_sector_size)) &&
(SCSI_DEBUG_OPT_NOISE & scsi_debug_opts))
printk(KERN_INFO "scsi_debug: write same: cdb indicated=%u, "
" IO sent=%d bytes\n", num * scsi_debug_sector_size, ret);
for (i = 1 ; i < num ; i++)
memcpy(fake_storep + ((lba + i) * scsi_debug_sector_size),
fake_storep + (lba * scsi_debug_sector_size),
scsi_debug_sector_size);
if (scsi_debug_unmap_granularity)
map_region(lba, num);
out:
write_unlock_irqrestore(&atomic_rw, iflags);
return 0;
}
static int resp_unmap(struct scsi_cmnd * scmd, struct sdebug_dev_info * devip)
{
unsigned char *buf;
struct unmap_block_desc *desc;
unsigned int i, payload_len, descriptors;
int ret;
ret = check_readiness(scmd, 1, devip);
if (ret)
return ret;
payload_len = get_unaligned_be16(&scmd->cmnd[7]);
BUG_ON(scsi_bufflen(scmd) != payload_len);
descriptors = (payload_len - 8) / 16;
buf = kmalloc(scsi_bufflen(scmd), GFP_ATOMIC);
if (!buf)
return check_condition_result;
scsi_sg_copy_to_buffer(scmd, buf, scsi_bufflen(scmd));
BUG_ON(get_unaligned_be16(&buf[0]) != payload_len - 2);
BUG_ON(get_unaligned_be16(&buf[2]) != descriptors * 16);
desc = (void *)&buf[8];
for (i = 0 ; i < descriptors ; i++) {
unsigned long long lba = get_unaligned_be64(&desc[i].lba);
unsigned int num = get_unaligned_be32(&desc[i].blocks);
ret = check_device_access_params(devip, lba, num);
if (ret)
goto out;
unmap_region(lba, num);
}
ret = 0;
out:
kfree(buf);
return ret;
}
static int resp_get_lba_status(struct scsi_cmnd * scmd,
struct sdebug_dev_info * devip)
{
unsigned long long lba;
unsigned int alloc_len, mapped, num;
unsigned char arr[SDEBUG_GET_LBA_STATUS_LEN];
int ret;
ret = check_readiness(scmd, 1, devip);
if (ret)
return ret;
lba = get_unaligned_be64(&scmd->cmnd[2]);
alloc_len = get_unaligned_be32(&scmd->cmnd[10]);
if (alloc_len < 24)
return 0;
ret = check_device_access_params(devip, lba, 1);
if (ret)
return ret;
mapped = map_state(lba, &num);
memset(arr, 0, SDEBUG_GET_LBA_STATUS_LEN);
put_unaligned_be32(20, &arr[0]);
put_unaligned_be64(lba, &arr[8]);
put_unaligned_be32(num, &arr[16]);
arr[20] = !mapped;
return fill_from_dev_buffer(scmd, arr, SDEBUG_GET_LBA_STATUS_LEN);
}
static int resp_report_luns(struct scsi_cmnd * scp,
struct sdebug_dev_info * devip)
{
unsigned int alloc_len;
int lun_cnt, i, upper, num, n, wlun, lun;
unsigned char *cmd = (unsigned char *)scp->cmnd;
int select_report = (int)cmd[2];
struct scsi_lun *one_lun;
unsigned char arr[SDEBUG_RLUN_ARR_SZ];
unsigned char * max_addr;
alloc_len = cmd[9] + (cmd[8] << 8) + (cmd[7] << 16) + (cmd[6] << 24);
if ((alloc_len < 4) || (select_report > 2)) {
mk_sense_buffer(devip, ILLEGAL_REQUEST, INVALID_FIELD_IN_CDB,
0);
return check_condition_result;
}
memset(arr, 0, SDEBUG_RLUN_ARR_SZ);
lun_cnt = scsi_debug_max_luns;
if (1 == select_report)
lun_cnt = 0;
else if (scsi_debug_no_lun_0 && (lun_cnt > 0))
--lun_cnt;
wlun = (select_report > 0) ? 1 : 0;
num = lun_cnt + wlun;
arr[2] = ((sizeof(struct scsi_lun) * num) >> 8) & 0xff;
arr[3] = (sizeof(struct scsi_lun) * num) & 0xff;
n = min((int)((SDEBUG_RLUN_ARR_SZ - 8) /
sizeof(struct scsi_lun)), num);
if (n < num) {
wlun = 0;
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
if (wlun) {
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
int i, j, ret = -1;
unsigned char *kaddr, *buf;
unsigned int offset;
struct scatterlist *sg;
struct scsi_data_buffer *sdb = scsi_in(scp);
buf = kmalloc(scsi_bufflen(scp), GFP_ATOMIC);
if (!buf)
return ret;
scsi_sg_copy_to_buffer(scp, buf, scsi_bufflen(scp));
offset = 0;
for_each_sg(sdb->table.sgl, sg, sdb->table.nents, i) {
kaddr = (unsigned char *)kmap_atomic(sg_page(sg));
if (!kaddr)
goto out;
for (j = 0; j < sg->length; j++)
*(kaddr + sg->offset + j) ^= *(buf + offset + j);
offset += sg->length;
kunmap_atomic(kaddr);
}
ret = 0;
out:
kfree(buf);
return ret;
}
static void timer_intr_handler(unsigned long indx)
{
struct sdebug_queued_cmd * sqcp;
unsigned long iflags;
if (indx >= scsi_debug_max_queue) {
printk(KERN_ERR "scsi_debug:timer_intr_handler: indx too "
"large\n");
return;
}
spin_lock_irqsave(&queued_arr_lock, iflags);
sqcp = &queued_arr[(int)indx];
if (! sqcp->in_use) {
printk(KERN_ERR "scsi_debug:timer_intr_handler: Unexpected "
"interrupt\n");
spin_unlock_irqrestore(&queued_arr_lock, iflags);
return;
}
sqcp->in_use = 0;
if (sqcp->done_funct) {
sqcp->a_cmnd->result = sqcp->scsi_result;
sqcp->done_funct(sqcp->a_cmnd);
}
sqcp->done_funct = NULL;
spin_unlock_irqrestore(&queued_arr_lock, iflags);
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
printk(KERN_ERR "Host info NULL\n");
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
open_devip->reset = 1;
open_devip->used = 1;
memset(open_devip->sense_buff, 0, SDEBUG_SENSE_LEN);
if (scsi_debug_dsense)
open_devip->sense_buff[0] = 0x72;
else {
open_devip->sense_buff[0] = 0x70;
open_devip->sense_buff[7] = 0xa;
}
if (sdev->lun == SAM2_WLUN_REPORT_LUNS)
open_devip->wlun = SAM2_WLUN_REPORT_LUNS & 0xff;
return open_devip;
}
static int scsi_debug_slave_alloc(struct scsi_device *sdp)
{
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: slave_alloc <%u %u %u %u>\n",
sdp->host->host_no, sdp->channel, sdp->id, sdp->lun);
queue_flag_set_unlocked(QUEUE_FLAG_BIDI, sdp->request_queue);
return 0;
}
static int scsi_debug_slave_configure(struct scsi_device *sdp)
{
struct sdebug_dev_info *devip;
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: slave_configure <%u %u %u %u>\n",
sdp->host->host_no, sdp->channel, sdp->id, sdp->lun);
if (sdp->host->max_cmd_len != SCSI_DEBUG_MAX_CMD_LEN)
sdp->host->max_cmd_len = SCSI_DEBUG_MAX_CMD_LEN;
devip = devInfoReg(sdp);
if (NULL == devip)
return 1;
sdp->hostdata = devip;
if (sdp->host->cmd_per_lun)
scsi_adjust_queue_depth(sdp, SDEBUG_TAGGED_QUEUING,
sdp->host->cmd_per_lun);
blk_queue_max_segment_size(sdp->request_queue, 256 * 1024);
if (scsi_debug_no_uld)
sdp->no_uld_attach = 1;
return 0;
}
static void scsi_debug_slave_destroy(struct scsi_device *sdp)
{
struct sdebug_dev_info *devip =
(struct sdebug_dev_info *)sdp->hostdata;
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: slave_destroy <%u %u %u %u>\n",
sdp->host->host_no, sdp->channel, sdp->id, sdp->lun);
if (devip) {
devip->used = 0;
sdp->hostdata = NULL;
}
}
static int stop_queued_cmnd(struct scsi_cmnd *cmnd)
{
unsigned long iflags;
int k;
struct sdebug_queued_cmd *sqcp;
spin_lock_irqsave(&queued_arr_lock, iflags);
for (k = 0; k < scsi_debug_max_queue; ++k) {
sqcp = &queued_arr[k];
if (sqcp->in_use && (cmnd == sqcp->a_cmnd)) {
del_timer_sync(&sqcp->cmnd_timer);
sqcp->in_use = 0;
sqcp->a_cmnd = NULL;
break;
}
}
spin_unlock_irqrestore(&queued_arr_lock, iflags);
return (k < scsi_debug_max_queue) ? 1 : 0;
}
static void stop_all_queued(void)
{
unsigned long iflags;
int k;
struct sdebug_queued_cmd *sqcp;
spin_lock_irqsave(&queued_arr_lock, iflags);
for (k = 0; k < scsi_debug_max_queue; ++k) {
sqcp = &queued_arr[k];
if (sqcp->in_use && sqcp->a_cmnd) {
del_timer_sync(&sqcp->cmnd_timer);
sqcp->in_use = 0;
sqcp->a_cmnd = NULL;
}
}
spin_unlock_irqrestore(&queued_arr_lock, iflags);
}
static int scsi_debug_abort(struct scsi_cmnd * SCpnt)
{
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: abort\n");
++num_aborts;
stop_queued_cmnd(SCpnt);
return SUCCESS;
}
static int scsi_debug_biosparam(struct scsi_device *sdev,
struct block_device * bdev, sector_t capacity, int *info)
{
int res;
unsigned char *buf;
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: biosparam\n");
buf = scsi_bios_ptable(bdev);
if (buf) {
res = scsi_partsize(buf, capacity,
&info[2], &info[0], &info[1]);
kfree(buf);
if (! res)
return res;
}
info[0] = sdebug_heads;
info[1] = sdebug_sectors_per;
info[2] = sdebug_cylinders_per;
return 0;
}
static int scsi_debug_device_reset(struct scsi_cmnd * SCpnt)
{
struct sdebug_dev_info * devip;
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: device_reset\n");
++num_dev_resets;
if (SCpnt) {
devip = devInfoReg(SCpnt->device);
if (devip)
devip->reset = 1;
}
return SUCCESS;
}
static int scsi_debug_bus_reset(struct scsi_cmnd * SCpnt)
{
struct sdebug_host_info *sdbg_host;
struct sdebug_dev_info * dev_info;
struct scsi_device * sdp;
struct Scsi_Host * hp;
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: bus_reset\n");
++num_bus_resets;
if (SCpnt && ((sdp = SCpnt->device)) && ((hp = sdp->host))) {
sdbg_host = *(struct sdebug_host_info **)shost_priv(hp);
if (sdbg_host) {
list_for_each_entry(dev_info,
&sdbg_host->dev_info_list,
dev_list)
dev_info->reset = 1;
}
}
return SUCCESS;
}
static int scsi_debug_host_reset(struct scsi_cmnd * SCpnt)
{
struct sdebug_host_info * sdbg_host;
struct sdebug_dev_info * dev_info;
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: host_reset\n");
++num_host_resets;
spin_lock(&sdebug_host_list_lock);
list_for_each_entry(sdbg_host, &sdebug_host_list, host_list) {
list_for_each_entry(dev_info, &sdbg_host->dev_info_list,
dev_list)
dev_info->reset = 1;
}
spin_unlock(&sdebug_host_list_lock);
stop_all_queued();
return SUCCESS;
}
static void __init init_all_queued(void)
{
unsigned long iflags;
int k;
struct sdebug_queued_cmd * sqcp;
spin_lock_irqsave(&queued_arr_lock, iflags);
for (k = 0; k < scsi_debug_max_queue; ++k) {
sqcp = &queued_arr[k];
init_timer(&sqcp->cmnd_timer);
sqcp->in_use = 0;
sqcp->a_cmnd = NULL;
}
spin_unlock_irqrestore(&queued_arr_lock, iflags);
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
printk(KERN_WARNING "scsi_debug:build_parts: reducing "
"partitions to %d\n", SDEBUG_MAX_PARTS);
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
pp->start_sect = start_sec;
pp->nr_sects = end_sec - start_sec + 1;
pp->sys_ind = 0x83;
}
}
static int schedule_resp(struct scsi_cmnd * cmnd,
struct sdebug_dev_info * devip,
done_funct_t done, int scsi_result, int delta_jiff)
{
if ((SCSI_DEBUG_OPT_NOISE & scsi_debug_opts) && cmnd) {
if (scsi_result) {
struct scsi_device * sdp = cmnd->device;
printk(KERN_INFO "scsi_debug: <%u %u %u %u> "
"non-zero result=0x%x\n", sdp->host->host_no,
sdp->channel, sdp->id, sdp->lun, scsi_result);
}
}
if (cmnd && devip) {
if (SAM_STAT_CHECK_CONDITION == (scsi_result & 0xff))
memcpy(cmnd->sense_buffer, devip->sense_buff,
(SCSI_SENSE_BUFFERSIZE > SDEBUG_SENSE_LEN) ?
SDEBUG_SENSE_LEN : SCSI_SENSE_BUFFERSIZE);
}
if (delta_jiff <= 0) {
if (cmnd)
cmnd->result = scsi_result;
if (done)
done(cmnd);
return 0;
} else {
unsigned long iflags;
int k;
struct sdebug_queued_cmd * sqcp = NULL;
spin_lock_irqsave(&queued_arr_lock, iflags);
for (k = 0; k < scsi_debug_max_queue; ++k) {
sqcp = &queued_arr[k];
if (! sqcp->in_use)
break;
}
if (k >= scsi_debug_max_queue) {
spin_unlock_irqrestore(&queued_arr_lock, iflags);
printk(KERN_WARNING "scsi_debug: can_queue exceeded\n");
return 1;
}
sqcp->in_use = 1;
sqcp->a_cmnd = cmnd;
sqcp->scsi_result = scsi_result;
sqcp->done_funct = done;
sqcp->cmnd_timer.function = timer_intr_handler;
sqcp->cmnd_timer.data = k;
sqcp->cmnd_timer.expires = jiffies + delta_jiff;
add_timer(&sqcp->cmnd_timer);
spin_unlock_irqrestore(&queued_arr_lock, iflags);
if (cmnd)
cmnd->result = 0;
return 0;
}
}
static const char * scsi_debug_info(struct Scsi_Host * shp)
{
sprintf(sdebug_info, "scsi_debug, version %s [%s], "
"dev_size_mb=%d, opts=0x%x", SCSI_DEBUG_VERSION,
scsi_debug_version_date, scsi_debug_dev_size_mb,
scsi_debug_opts);
return sdebug_info;
}
static int scsi_debug_proc_info(struct Scsi_Host *host, char *buffer, char **start, off_t offset,
int length, int inout)
{
int len, pos, begin;
int orig_length;
orig_length = length;
if (inout == 1) {
char arr[16];
int minLen = length > 15 ? 15 : length;
if (!capable(CAP_SYS_ADMIN) || !capable(CAP_SYS_RAWIO))
return -EACCES;
memcpy(arr, buffer, minLen);
arr[minLen] = '\0';
if (1 != sscanf(arr, "%d", &pos))
return -EINVAL;
scsi_debug_opts = pos;
if (scsi_debug_every_nth != 0)
scsi_debug_cmnd_count = 0;
return length;
}
begin = 0;
pos = len = sprintf(buffer, "scsi_debug adapter driver, version "
"%s [%s]\n"
"num_tgts=%d, shared (ram) size=%d MB, opts=0x%x, "
"every_nth=%d(curr:%d)\n"
"delay=%d, max_luns=%d, scsi_level=%d\n"
"sector_size=%d bytes, cylinders=%d, heads=%d, sectors=%d\n"
"number of aborts=%d, device_reset=%d, bus_resets=%d, "
"host_resets=%d\ndix_reads=%d dix_writes=%d dif_errors=%d\n",
SCSI_DEBUG_VERSION, scsi_debug_version_date, scsi_debug_num_tgts,
scsi_debug_dev_size_mb, scsi_debug_opts, scsi_debug_every_nth,
scsi_debug_cmnd_count, scsi_debug_delay,
scsi_debug_max_luns, scsi_debug_scsi_level,
scsi_debug_sector_size, sdebug_cylinders_per, sdebug_heads,
sdebug_sectors_per, num_aborts, num_dev_resets, num_bus_resets,
num_host_resets, dix_reads, dix_writes, dif_errors);
if (pos < offset) {
len = 0;
begin = pos;
}
*start = buffer + (offset - begin);
len -= (offset - begin);
if (len > length)
len = length;
return len;
}
static ssize_t sdebug_delay_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_delay);
}
static ssize_t sdebug_delay_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int delay;
char work[20];
if (1 == sscanf(buf, "%10s", work)) {
if ((1 == sscanf(work, "%d", &delay)) && (delay >= 0)) {
scsi_debug_delay = delay;
return count;
}
}
return -EINVAL;
}
static ssize_t sdebug_opts_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "0x%x\n", scsi_debug_opts);
}
static ssize_t sdebug_opts_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int opts;
char work[20];
if (1 == sscanf(buf, "%10s", work)) {
if (0 == strnicmp(work,"0x", 2)) {
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
scsi_debug_cmnd_count = 0;
return count;
}
static ssize_t sdebug_ptype_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_ptype);
}
static ssize_t sdebug_ptype_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_ptype = n;
return count;
}
return -EINVAL;
}
static ssize_t sdebug_dsense_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_dsense);
}
static ssize_t sdebug_dsense_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_dsense = n;
return count;
}
return -EINVAL;
}
static ssize_t sdebug_fake_rw_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_fake_rw);
}
static ssize_t sdebug_fake_rw_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_fake_rw = n;
return count;
}
return -EINVAL;
}
static ssize_t sdebug_no_lun_0_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_no_lun_0);
}
static ssize_t sdebug_no_lun_0_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_no_lun_0 = n;
return count;
}
return -EINVAL;
}
static ssize_t sdebug_num_tgts_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_num_tgts);
}
static ssize_t sdebug_num_tgts_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_num_tgts = n;
sdebug_max_tgts_luns();
return count;
}
return -EINVAL;
}
static ssize_t sdebug_dev_size_mb_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_dev_size_mb);
}
static ssize_t sdebug_num_parts_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_num_parts);
}
static ssize_t sdebug_every_nth_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_every_nth);
}
static ssize_t sdebug_every_nth_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int nth;
if ((count > 0) && (1 == sscanf(buf, "%d", &nth))) {
scsi_debug_every_nth = nth;
scsi_debug_cmnd_count = 0;
return count;
}
return -EINVAL;
}
static ssize_t sdebug_max_luns_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_max_luns);
}
static ssize_t sdebug_max_luns_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_max_luns = n;
sdebug_max_tgts_luns();
return count;
}
return -EINVAL;
}
static ssize_t sdebug_max_queue_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_max_queue);
}
static ssize_t sdebug_max_queue_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n > 0) &&
(n <= SCSI_DEBUG_CANQUEUE)) {
scsi_debug_max_queue = n;
return count;
}
return -EINVAL;
}
static ssize_t sdebug_no_uld_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_no_uld);
}
static ssize_t sdebug_scsi_level_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_scsi_level);
}
static ssize_t sdebug_virtual_gb_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_virtual_gb);
}
static ssize_t sdebug_virtual_gb_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_virtual_gb = n;
sdebug_capacity = get_sdebug_capacity();
return count;
}
return -EINVAL;
}
static ssize_t sdebug_add_host_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_add_host);
}
static ssize_t sdebug_add_host_store(struct device_driver * ddp,
const char * buf, size_t count)
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
static ssize_t sdebug_vpd_use_hostno_show(struct device_driver * ddp,
char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_vpd_use_hostno);
}
static ssize_t sdebug_vpd_use_hostno_store(struct device_driver * ddp,
const char * buf, size_t count)
{
int n;
if ((count > 0) && (1 == sscanf(buf, "%d", &n)) && (n >= 0)) {
scsi_debug_vpd_use_hostno = n;
return count;
}
return -EINVAL;
}
static ssize_t sdebug_sector_size_show(struct device_driver * ddp, char * buf)
{
return scnprintf(buf, PAGE_SIZE, "%u\n", scsi_debug_sector_size);
}
static ssize_t sdebug_dix_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_dix);
}
static ssize_t sdebug_dif_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_dif);
}
static ssize_t sdebug_guard_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_guard);
}
static ssize_t sdebug_ato_show(struct device_driver *ddp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", scsi_debug_ato);
}
static ssize_t sdebug_map_show(struct device_driver *ddp, char *buf)
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
static int do_create_driverfs_files(void)
{
int ret;
ret = driver_create_file(&sdebug_driverfs_driver, &driver_attr_add_host);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_delay);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_dev_size_mb);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_dsense);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_every_nth);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_fake_rw);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_max_luns);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_max_queue);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_no_lun_0);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_no_uld);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_num_parts);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_num_tgts);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_ptype);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_opts);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_scsi_level);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_virtual_gb);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_vpd_use_hostno);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_sector_size);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_dix);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_dif);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_guard);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_ato);
ret |= driver_create_file(&sdebug_driverfs_driver, &driver_attr_map);
return ret;
}
static void do_remove_driverfs_files(void)
{
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_map);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_ato);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_guard);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_dif);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_dix);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_sector_size);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_vpd_use_hostno);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_virtual_gb);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_scsi_level);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_opts);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_ptype);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_num_tgts);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_num_parts);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_no_uld);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_no_lun_0);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_max_queue);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_max_luns);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_fake_rw);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_every_nth);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_dsense);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_dev_size_mb);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_delay);
driver_remove_file(&sdebug_driverfs_driver, &driver_attr_add_host);
}
static int __init scsi_debug_init(void)
{
unsigned long sz;
int host_to_add;
int k;
int ret;
switch (scsi_debug_sector_size) {
case 512:
case 1024:
case 2048:
case 4096:
break;
default:
printk(KERN_ERR "scsi_debug_init: invalid sector_size %d\n",
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
printk(KERN_ERR "scsi_debug_init: dif must be 0, 1, 2 or 3\n");
return -EINVAL;
}
if (scsi_debug_guard > 1) {
printk(KERN_ERR "scsi_debug_init: guard must be 0 or 1\n");
return -EINVAL;
}
if (scsi_debug_ato > 1) {
printk(KERN_ERR "scsi_debug_init: ato must be 0 or 1\n");
return -EINVAL;
}
if (scsi_debug_physblk_exp > 15) {
printk(KERN_ERR "scsi_debug_init: invalid physblk_exp %u\n",
scsi_debug_physblk_exp);
return -EINVAL;
}
if (scsi_debug_lowest_aligned > 0x3fff) {
printk(KERN_ERR "scsi_debug_init: lowest_aligned too big: %u\n",
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
fake_storep = vmalloc(sz);
if (NULL == fake_storep) {
printk(KERN_ERR "scsi_debug_init: out of memory, 1\n");
return -ENOMEM;
}
memset(fake_storep, 0, sz);
if (scsi_debug_num_parts > 0)
sdebug_build_parts(fake_storep, sz);
if (scsi_debug_dif) {
int dif_size;
dif_size = sdebug_store_sectors * sizeof(struct sd_dif_tuple);
dif_storep = vmalloc(dif_size);
printk(KERN_ERR "scsi_debug_init: dif_storep %u bytes @ %p\n",
dif_size, dif_storep);
if (dif_storep == NULL) {
printk(KERN_ERR "scsi_debug_init: out of mem. (DIX)\n");
ret = -ENOMEM;
goto free_vm;
}
memset(dif_storep, 0xff, dif_size);
}
if (scsi_debug_lbp()) {
unsigned int map_bytes;
scsi_debug_unmap_max_blocks =
clamp(scsi_debug_unmap_max_blocks, 0U, 0xffffffffU);
scsi_debug_unmap_max_desc =
clamp(scsi_debug_unmap_max_desc, 0U, 256U);
scsi_debug_unmap_granularity =
clamp(scsi_debug_unmap_granularity, 1U, 0xffffffffU);
if (scsi_debug_unmap_alignment &&
scsi_debug_unmap_granularity < scsi_debug_unmap_alignment) {
printk(KERN_ERR
"%s: ERR: unmap_granularity < unmap_alignment\n",
__func__);
return -EINVAL;
}
map_size = (sdebug_store_sectors / scsi_debug_unmap_granularity);
map_bytes = map_size >> 3;
map_storep = vmalloc(map_bytes);
printk(KERN_INFO "scsi_debug_init: %lu provisioning blocks\n",
map_size);
if (map_storep == NULL) {
printk(KERN_ERR "scsi_debug_init: out of mem. (MAP)\n");
ret = -ENOMEM;
goto free_vm;
}
memset(map_storep, 0x0, map_bytes);
if (scsi_debug_num_parts)
map_region(0, 2);
}
pseudo_primary = root_device_register("pseudo_0");
if (IS_ERR(pseudo_primary)) {
printk(KERN_WARNING "scsi_debug: root_device_register() error\n");
ret = PTR_ERR(pseudo_primary);
goto free_vm;
}
ret = bus_register(&pseudo_lld_bus);
if (ret < 0) {
printk(KERN_WARNING "scsi_debug: bus_register error: %d\n",
ret);
goto dev_unreg;
}
ret = driver_register(&sdebug_driverfs_driver);
if (ret < 0) {
printk(KERN_WARNING "scsi_debug: driver_register error: %d\n",
ret);
goto bus_unreg;
}
ret = do_create_driverfs_files();
if (ret < 0) {
printk(KERN_WARNING "scsi_debug: driver_create_file error: %d\n",
ret);
goto del_files;
}
init_all_queued();
host_to_add = scsi_debug_add_host;
scsi_debug_add_host = 0;
for (k = 0; k < host_to_add; k++) {
if (sdebug_add_adapter()) {
printk(KERN_ERR "scsi_debug_init: "
"sdebug_add_adapter failed k=%d\n", k);
break;
}
}
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts) {
printk(KERN_INFO "scsi_debug_init: built %d host(s)\n",
scsi_debug_add_host);
}
return 0;
del_files:
do_remove_driverfs_files();
driver_unregister(&sdebug_driverfs_driver);
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
for (; k; k--)
sdebug_remove_adapter();
do_remove_driverfs_files();
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
static
int scsi_debug_queuecommand_lck(struct scsi_cmnd *SCpnt, done_funct_t done)
{
unsigned char *cmd = (unsigned char *) SCpnt->cmnd;
int len, k;
unsigned int num;
unsigned long long lba;
u32 ei_lba;
int errsts = 0;
int target = SCpnt->device->id;
struct sdebug_dev_info *devip = NULL;
int inj_recovered = 0;
int inj_transport = 0;
int inj_dif = 0;
int inj_dix = 0;
int delay_override = 0;
int unmap = 0;
scsi_set_resid(SCpnt, 0);
if ((SCSI_DEBUG_OPT_NOISE & scsi_debug_opts) && cmd) {
printk(KERN_INFO "scsi_debug: cmd ");
for (k = 0, len = SCpnt->cmd_len; k < len; ++k)
printk("%02x ", (int)cmd[k]);
printk("\n");
}
if (target == SCpnt->device->host->hostt->this_id) {
printk(KERN_INFO "scsi_debug: initiator's id used as "
"target!\n");
return schedule_resp(SCpnt, NULL, done,
DID_NO_CONNECT << 16, 0);
}
if ((SCpnt->device->lun >= scsi_debug_max_luns) &&
(SCpnt->device->lun != SAM2_WLUN_REPORT_LUNS))
return schedule_resp(SCpnt, NULL, done,
DID_NO_CONNECT << 16, 0);
devip = devInfoReg(SCpnt->device);
if (NULL == devip)
return schedule_resp(SCpnt, NULL, done,
DID_NO_CONNECT << 16, 0);
if ((scsi_debug_every_nth != 0) &&
(++scsi_debug_cmnd_count >= abs(scsi_debug_every_nth))) {
scsi_debug_cmnd_count = 0;
if (scsi_debug_every_nth < -1)
scsi_debug_every_nth = -1;
if (SCSI_DEBUG_OPT_TIMEOUT & scsi_debug_opts)
return 0;
else if (SCSI_DEBUG_OPT_MAC_TIMEOUT & scsi_debug_opts &&
scsi_medium_access_command(SCpnt))
return 0;
else if (SCSI_DEBUG_OPT_RECOVERED_ERR & scsi_debug_opts)
inj_recovered = 1;
else if (SCSI_DEBUG_OPT_TRANSPORT_ERR & scsi_debug_opts)
inj_transport = 1;
else if (SCSI_DEBUG_OPT_DIF_ERR & scsi_debug_opts)
inj_dif = 1;
else if (SCSI_DEBUG_OPT_DIX_ERR & scsi_debug_opts)
inj_dix = 1;
}
if (devip->wlun) {
switch (*cmd) {
case INQUIRY:
case REQUEST_SENSE:
case TEST_UNIT_READY:
case REPORT_LUNS:
break;
default:
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: Opcode: 0x%x "
"not supported for wlun\n", *cmd);
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_OPCODE, 0);
errsts = check_condition_result;
return schedule_resp(SCpnt, devip, done, errsts,
0);
}
}
switch (*cmd) {
case INQUIRY:
delay_override = 1;
errsts = resp_inquiry(SCpnt, target, devip);
break;
case REQUEST_SENSE:
delay_override = 1;
errsts = resp_requests(SCpnt, devip);
break;
case REZERO_UNIT:
case START_STOP:
errsts = resp_start_stop(SCpnt, devip);
break;
case ALLOW_MEDIUM_REMOVAL:
errsts = check_readiness(SCpnt, 1, devip);
if (errsts)
break;
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: Medium removal %s\n",
cmd[4] ? "inhibited" : "enabled");
break;
case SEND_DIAGNOSTIC:
errsts = check_readiness(SCpnt, 1, devip);
break;
case TEST_UNIT_READY:
delay_override = 1;
errsts = check_readiness(SCpnt, 0, devip);
break;
case RESERVE:
errsts = check_readiness(SCpnt, 1, devip);
break;
case RESERVE_10:
errsts = check_readiness(SCpnt, 1, devip);
break;
case RELEASE:
errsts = check_readiness(SCpnt, 1, devip);
break;
case RELEASE_10:
errsts = check_readiness(SCpnt, 1, devip);
break;
case READ_CAPACITY:
errsts = resp_readcap(SCpnt, devip);
break;
case SERVICE_ACTION_IN:
if (cmd[1] == SAI_READ_CAPACITY_16)
errsts = resp_readcap16(SCpnt, devip);
else if (cmd[1] == SAI_GET_LBA_STATUS) {
if (scsi_debug_lbp() == 0) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_COMMAND_OPCODE, 0);
errsts = check_condition_result;
} else
errsts = resp_get_lba_status(SCpnt, devip);
} else {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_OPCODE, 0);
errsts = check_condition_result;
}
break;
case MAINTENANCE_IN:
if (MI_REPORT_TARGET_PGS != cmd[1]) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_OPCODE, 0);
errsts = check_condition_result;
break;
}
errsts = resp_report_tgtpgs(SCpnt, devip);
break;
case READ_16:
case READ_12:
case READ_10:
if (scsi_debug_dif == SD_DIF_TYPE2_PROTECTION &&
cmd[1] & 0xe0) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_COMMAND_OPCODE, 0);
errsts = check_condition_result;
break;
}
if ((scsi_debug_dif == SD_DIF_TYPE1_PROTECTION ||
scsi_debug_dif == SD_DIF_TYPE3_PROTECTION) &&
(cmd[1] & 0xe0) == 0)
printk(KERN_ERR "Unprotected RD/WR to DIF device\n");
case READ_6:
read:
errsts = check_readiness(SCpnt, 0, devip);
if (errsts)
break;
if (scsi_debug_fake_rw)
break;
get_data_transfer_info(cmd, &lba, &num, &ei_lba);
errsts = resp_read(SCpnt, lba, num, devip, ei_lba);
if (inj_recovered && (0 == errsts)) {
mk_sense_buffer(devip, RECOVERED_ERROR,
THRESHOLD_EXCEEDED, 0);
errsts = check_condition_result;
} else if (inj_transport && (0 == errsts)) {
mk_sense_buffer(devip, ABORTED_COMMAND,
TRANSPORT_PROBLEM, ACK_NAK_TO);
errsts = check_condition_result;
} else if (inj_dif && (0 == errsts)) {
mk_sense_buffer(devip, ABORTED_COMMAND, 0x10, 1);
errsts = illegal_condition_result;
} else if (inj_dix && (0 == errsts)) {
mk_sense_buffer(devip, ILLEGAL_REQUEST, 0x10, 1);
errsts = illegal_condition_result;
}
break;
case REPORT_LUNS:
delay_override = 1;
errsts = resp_report_luns(SCpnt, devip);
break;
case VERIFY:
errsts = check_readiness(SCpnt, 0, devip);
break;
case WRITE_16:
case WRITE_12:
case WRITE_10:
if (scsi_debug_dif == SD_DIF_TYPE2_PROTECTION &&
cmd[1] & 0xe0) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_COMMAND_OPCODE, 0);
errsts = check_condition_result;
break;
}
if ((scsi_debug_dif == SD_DIF_TYPE1_PROTECTION ||
scsi_debug_dif == SD_DIF_TYPE3_PROTECTION) &&
(cmd[1] & 0xe0) == 0)
printk(KERN_ERR "Unprotected RD/WR to DIF device\n");
case WRITE_6:
write:
errsts = check_readiness(SCpnt, 0, devip);
if (errsts)
break;
if (scsi_debug_fake_rw)
break;
get_data_transfer_info(cmd, &lba, &num, &ei_lba);
errsts = resp_write(SCpnt, lba, num, devip, ei_lba);
if (inj_recovered && (0 == errsts)) {
mk_sense_buffer(devip, RECOVERED_ERROR,
THRESHOLD_EXCEEDED, 0);
errsts = check_condition_result;
} else if (inj_dif && (0 == errsts)) {
mk_sense_buffer(devip, ABORTED_COMMAND, 0x10, 1);
errsts = illegal_condition_result;
} else if (inj_dix && (0 == errsts)) {
mk_sense_buffer(devip, ILLEGAL_REQUEST, 0x10, 1);
errsts = illegal_condition_result;
}
break;
case WRITE_SAME_16:
case WRITE_SAME:
if (cmd[1] & 0x8) {
if ((*cmd == WRITE_SAME_16 && scsi_debug_lbpws == 0) ||
(*cmd == WRITE_SAME && scsi_debug_lbpws10 == 0)) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_CDB, 0);
errsts = check_condition_result;
} else
unmap = 1;
}
if (errsts)
break;
errsts = check_readiness(SCpnt, 0, devip);
if (errsts)
break;
get_data_transfer_info(cmd, &lba, &num, &ei_lba);
errsts = resp_write_same(SCpnt, lba, num, devip, ei_lba, unmap);
break;
case UNMAP:
errsts = check_readiness(SCpnt, 0, devip);
if (errsts)
break;
if (scsi_debug_unmap_max_desc == 0 || scsi_debug_lbpu == 0) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_COMMAND_OPCODE, 0);
errsts = check_condition_result;
} else
errsts = resp_unmap(SCpnt, devip);
break;
case MODE_SENSE:
case MODE_SENSE_10:
errsts = resp_mode_sense(SCpnt, target, devip);
break;
case MODE_SELECT:
errsts = resp_mode_select(SCpnt, 1, devip);
break;
case MODE_SELECT_10:
errsts = resp_mode_select(SCpnt, 0, devip);
break;
case LOG_SENSE:
errsts = resp_log_sense(SCpnt, devip);
break;
case SYNCHRONIZE_CACHE:
delay_override = 1;
errsts = check_readiness(SCpnt, 0, devip);
break;
case WRITE_BUFFER:
errsts = check_readiness(SCpnt, 1, devip);
break;
case XDWRITEREAD_10:
if (!scsi_bidi_cmnd(SCpnt)) {
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_CDB, 0);
errsts = check_condition_result;
break;
}
errsts = check_readiness(SCpnt, 0, devip);
if (errsts)
break;
if (scsi_debug_fake_rw)
break;
get_data_transfer_info(cmd, &lba, &num, &ei_lba);
errsts = resp_read(SCpnt, lba, num, devip, ei_lba);
if (errsts)
break;
errsts = resp_write(SCpnt, lba, num, devip, ei_lba);
if (errsts)
break;
errsts = resp_xdwriteread(SCpnt, lba, num, devip);
break;
case VARIABLE_LENGTH_CMD:
if (scsi_debug_dif == SD_DIF_TYPE2_PROTECTION) {
if ((cmd[10] & 0xe0) == 0)
printk(KERN_ERR
"Unprotected RD/WR to DIF device\n");
if (cmd[9] == READ_32) {
BUG_ON(SCpnt->cmd_len < 32);
goto read;
}
if (cmd[9] == WRITE_32) {
BUG_ON(SCpnt->cmd_len < 32);
goto write;
}
}
mk_sense_buffer(devip, ILLEGAL_REQUEST,
INVALID_FIELD_IN_CDB, 0);
errsts = check_condition_result;
break;
default:
if (SCSI_DEBUG_OPT_NOISE & scsi_debug_opts)
printk(KERN_INFO "scsi_debug: Opcode: 0x%x not "
"supported\n", *cmd);
errsts = check_readiness(SCpnt, 1, devip);
if (errsts)
break;
mk_sense_buffer(devip, ILLEGAL_REQUEST, INVALID_OPCODE, 0);
errsts = check_condition_result;
break;
}
return schedule_resp(SCpnt, devip, done, errsts,
(delay_override ? 0 : scsi_debug_delay));
}
static int sdebug_driver_probe(struct device * dev)
{
int error = 0;
struct sdebug_host_info *sdbg_host;
struct Scsi_Host *hpnt;
int host_prot;
sdbg_host = to_sdebug_host(dev);
sdebug_driver_template.can_queue = scsi_debug_max_queue;
hpnt = scsi_host_alloc(&sdebug_driver_template, sizeof(sdbg_host));
if (NULL == hpnt) {
printk(KERN_ERR "%s: scsi_register failed\n", __func__);
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
