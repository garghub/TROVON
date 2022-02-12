static char *ipl_type_str(enum ipl_type type)
{
switch (type) {
case IPL_TYPE_CCW:
return IPL_CCW_STR;
case IPL_TYPE_FCP:
return IPL_FCP_STR;
case IPL_TYPE_FCP_DUMP:
return IPL_FCP_DUMP_STR;
case IPL_TYPE_NSS:
return IPL_NSS_STR;
case IPL_TYPE_UNKNOWN:
default:
return IPL_UNKNOWN_STR;
}
}
static char *dump_type_str(enum dump_type type)
{
switch (type) {
case DUMP_TYPE_NONE:
return DUMP_NONE_STR;
case DUMP_TYPE_CCW:
return DUMP_CCW_STR;
case DUMP_TYPE_FCP:
return DUMP_FCP_STR;
default:
return NULL;
}
}
int diag308(unsigned long subcode, void *addr)
{
register unsigned long _addr asm("0") = (unsigned long) addr;
register unsigned long _rc asm("1") = 0;
asm volatile(
" diag %0,%2,0x308\n"
"0:\n"
EX_TABLE(0b,0b)
: "+d" (_addr), "+d" (_rc)
: "d" (subcode) : "cc", "memory");
return _rc;
}
static void make_attrs_ro(struct attribute **attrs)
{
while (*attrs) {
(*attrs)->mode = S_IRUGO;
attrs++;
}
}
static __init enum ipl_type get_ipl_type(void)
{
struct ipl_parameter_block *ipl = IPL_PARMBLOCK_START;
if (ipl_flags & IPL_NSS_VALID)
return IPL_TYPE_NSS;
if (!(ipl_flags & IPL_DEVNO_VALID))
return IPL_TYPE_UNKNOWN;
if (!(ipl_flags & IPL_PARMBLOCK_VALID))
return IPL_TYPE_CCW;
if (ipl->hdr.version > IPL_MAX_SUPPORTED_VERSION)
return IPL_TYPE_UNKNOWN;
if (ipl->hdr.pbt != DIAG308_IPL_TYPE_FCP)
return IPL_TYPE_UNKNOWN;
if (ipl->ipl_info.fcp.opt == DIAG308_IPL_OPT_DUMP)
return IPL_TYPE_FCP_DUMP;
return IPL_TYPE_FCP;
}
static ssize_t ipl_type_show(struct kobject *kobj, struct kobj_attribute *attr,
char *page)
{
return sprintf(page, "%s\n", ipl_type_str(ipl_info.type));
}
static size_t reipl_get_ascii_vmparm(char *dest, size_t size,
const struct ipl_parameter_block *ipb)
{
int i;
size_t len;
char has_lowercase = 0;
len = 0;
if ((ipb->ipl_info.ccw.vm_flags & DIAG308_VM_FLAGS_VP_VALID) &&
(ipb->ipl_info.ccw.vm_parm_len > 0)) {
len = min_t(size_t, size - 1, ipb->ipl_info.ccw.vm_parm_len);
memcpy(dest, ipb->ipl_info.ccw.vm_parm, len);
for (i = 0; i < len; i++)
if ((dest[i] > 0x80 && dest[i] < 0x8a) ||
(dest[i] > 0x90 && dest[i] < 0x9a) ||
(dest[i] > 0xa1 && dest[i] < 0xaa)) {
has_lowercase = 1;
break;
}
if (!has_lowercase)
EBC_TOLOWER(dest, len);
EBCASC(dest, len);
}
dest[len] = 0;
return len;
}
size_t append_ipl_vmparm(char *dest, size_t size)
{
size_t rc;
rc = 0;
if (diag308_set_works && (ipl_block.hdr.pbt == DIAG308_IPL_TYPE_CCW))
rc = reipl_get_ascii_vmparm(dest, size, &ipl_block);
else
dest[0] = 0;
return rc;
}
static ssize_t ipl_vm_parm_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
char parm[DIAG308_VMPARM_SIZE + 1] = {};
append_ipl_vmparm(parm, sizeof(parm));
return sprintf(page, "%s\n", parm);
}
static size_t scpdata_length(const char* buf, size_t count)
{
while (count) {
if (buf[count - 1] != '\0' && buf[count - 1] != ' ')
break;
count--;
}
return count;
}
static size_t reipl_append_ascii_scpdata(char *dest, size_t size,
const struct ipl_parameter_block *ipb)
{
size_t count;
size_t i;
int has_lowercase;
count = min(size - 1, scpdata_length(ipb->ipl_info.fcp.scp_data,
ipb->ipl_info.fcp.scp_data_len));
if (!count)
goto out;
has_lowercase = 0;
for (i = 0; i < count; i++) {
if (!isascii(ipb->ipl_info.fcp.scp_data[i])) {
count = 0;
goto out;
}
if (!has_lowercase && islower(ipb->ipl_info.fcp.scp_data[i]))
has_lowercase = 1;
}
if (has_lowercase)
memcpy(dest, ipb->ipl_info.fcp.scp_data, count);
else
for (i = 0; i < count; i++)
dest[i] = tolower(ipb->ipl_info.fcp.scp_data[i]);
out:
dest[count] = '\0';
return count;
}
size_t append_ipl_scpdata(char *dest, size_t len)
{
size_t rc;
rc = 0;
if (ipl_block.hdr.pbt == DIAG308_IPL_TYPE_FCP)
rc = reipl_append_ascii_scpdata(dest, len, &ipl_block);
else
dest[0] = 0;
return rc;
}
static ssize_t sys_ipl_device_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
struct ipl_parameter_block *ipl = IPL_PARMBLOCK_START;
switch (ipl_info.type) {
case IPL_TYPE_CCW:
return sprintf(page, "0.0.%04x\n", ipl_devno);
case IPL_TYPE_FCP:
case IPL_TYPE_FCP_DUMP:
return sprintf(page, "0.0.%04x\n", ipl->ipl_info.fcp.devno);
default:
return 0;
}
}
static ssize_t ipl_parameter_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
return memory_read_from_buffer(buf, count, &off, IPL_PARMBLOCK_START,
IPL_PARMBLOCK_SIZE);
}
static ssize_t ipl_scp_data_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
unsigned int size = IPL_PARMBLOCK_START->ipl_info.fcp.scp_data_len;
void *scp_data = &IPL_PARMBLOCK_START->ipl_info.fcp.scp_data;
return memory_read_from_buffer(buf, count, &off, scp_data, size);
}
static ssize_t ipl_ccw_loadparm_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
char loadparm[LOADPARM_LEN + 1] = {};
if (!sclp_ipl_info.is_valid)
return sprintf(page, "#unknown#\n");
memcpy(loadparm, &sclp_ipl_info.loadparm, LOADPARM_LEN);
EBCASC(loadparm, LOADPARM_LEN);
strim(loadparm);
return sprintf(page, "%s\n", loadparm);
}
static int __init ipl_register_fcp_files(void)
{
int rc;
rc = sysfs_create_group(&ipl_kset->kobj, &ipl_fcp_attr_group);
if (rc)
goto out;
rc = sysfs_create_bin_file(&ipl_kset->kobj, &ipl_parameter_attr);
if (rc)
goto out_ipl_parm;
rc = sysfs_create_bin_file(&ipl_kset->kobj, &ipl_scp_data_attr);
if (!rc)
goto out;
sysfs_remove_bin_file(&ipl_kset->kobj, &ipl_parameter_attr);
out_ipl_parm:
sysfs_remove_group(&ipl_kset->kobj, &ipl_fcp_attr_group);
out:
return rc;
}
static void __ipl_run(void *unused)
{
diag308(DIAG308_IPL, NULL);
if (MACHINE_IS_VM)
__cpcmd("IPL", NULL, 0, NULL);
else if (ipl_info.type == IPL_TYPE_CCW)
reipl_ccw_dev(&ipl_info.data.ccw.dev_id);
}
static void ipl_run(struct shutdown_trigger *trigger)
{
smp_call_ipl_cpu(__ipl_run, NULL);
}
static int __init ipl_init(void)
{
int rc;
ipl_kset = kset_create_and_add("ipl", NULL, firmware_kobj);
if (!ipl_kset) {
rc = -ENOMEM;
goto out;
}
switch (ipl_info.type) {
case IPL_TYPE_CCW:
if (MACHINE_IS_VM)
rc = sysfs_create_group(&ipl_kset->kobj,
&ipl_ccw_attr_group_vm);
else
rc = sysfs_create_group(&ipl_kset->kobj,
&ipl_ccw_attr_group_lpar);
break;
case IPL_TYPE_FCP:
case IPL_TYPE_FCP_DUMP:
rc = ipl_register_fcp_files();
break;
case IPL_TYPE_NSS:
rc = sysfs_create_group(&ipl_kset->kobj, &ipl_nss_attr_group);
break;
default:
rc = sysfs_create_group(&ipl_kset->kobj,
&ipl_unknown_attr_group);
break;
}
out:
if (rc)
panic("ipl_init failed: rc = %i\n", rc);
return 0;
}
static ssize_t reipl_generic_vmparm_show(struct ipl_parameter_block *ipb,
char *page)
{
char vmparm[DIAG308_VMPARM_SIZE + 1] = {};
reipl_get_ascii_vmparm(vmparm, sizeof(vmparm), ipb);
return sprintf(page, "%s\n", vmparm);
}
static ssize_t reipl_generic_vmparm_store(struct ipl_parameter_block *ipb,
size_t vmparm_max,
const char *buf, size_t len)
{
int i, ip_len;
ip_len = len;
if ((len > 0) && (buf[len - 1] == '\n'))
ip_len--;
if (ip_len > vmparm_max)
return -EINVAL;
for (i = 0; i < ip_len; i++)
if (!(isalnum(buf[i]) || isascii(buf[i]) || isprint(buf[i])))
return -EINVAL;
memset(ipb->ipl_info.ccw.vm_parm, 0, DIAG308_VMPARM_SIZE);
ipb->ipl_info.ccw.vm_parm_len = ip_len;
if (ip_len > 0) {
ipb->ipl_info.ccw.vm_flags |= DIAG308_VM_FLAGS_VP_VALID;
memcpy(ipb->ipl_info.ccw.vm_parm, buf, ip_len);
ASCEBC(ipb->ipl_info.ccw.vm_parm, ip_len);
} else {
ipb->ipl_info.ccw.vm_flags &= ~DIAG308_VM_FLAGS_VP_VALID;
}
return len;
}
static ssize_t reipl_nss_vmparm_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
return reipl_generic_vmparm_show(reipl_block_nss, page);
}
static ssize_t reipl_nss_vmparm_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
return reipl_generic_vmparm_store(reipl_block_nss, 56, buf, len);
}
static ssize_t reipl_ccw_vmparm_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
return reipl_generic_vmparm_show(reipl_block_ccw, page);
}
static ssize_t reipl_ccw_vmparm_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
return reipl_generic_vmparm_store(reipl_block_ccw, 64, buf, len);
}
static ssize_t reipl_fcp_scpdata_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
size_t size = reipl_block_fcp->ipl_info.fcp.scp_data_len;
void *scp_data = reipl_block_fcp->ipl_info.fcp.scp_data;
return memory_read_from_buffer(buf, count, &off, scp_data, size);
}
static ssize_t reipl_fcp_scpdata_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
size_t padding;
size_t scpdata_len;
if (off < 0)
return -EINVAL;
if (off >= DIAG308_SCPDATA_SIZE)
return -ENOSPC;
if (count > DIAG308_SCPDATA_SIZE - off)
count = DIAG308_SCPDATA_SIZE - off;
memcpy(reipl_block_fcp->ipl_info.fcp.scp_data, buf + off, count);
scpdata_len = off + count;
if (scpdata_len % 8) {
padding = 8 - (scpdata_len % 8);
memset(reipl_block_fcp->ipl_info.fcp.scp_data + scpdata_len,
0, padding);
scpdata_len += padding;
}
reipl_block_fcp->ipl_info.fcp.scp_data_len = scpdata_len;
reipl_block_fcp->hdr.len = IPL_PARM_BLK_FCP_LEN + scpdata_len;
reipl_block_fcp->hdr.blk0_len = IPL_PARM_BLK0_FCP_LEN + scpdata_len;
return count;
}
static void reipl_get_ascii_loadparm(char *loadparm,
struct ipl_parameter_block *ibp)
{
memcpy(loadparm, ibp->ipl_info.ccw.load_parm, LOADPARM_LEN);
EBCASC(loadparm, LOADPARM_LEN);
loadparm[LOADPARM_LEN] = 0;
strim(loadparm);
}
static ssize_t reipl_generic_loadparm_show(struct ipl_parameter_block *ipb,
char *page)
{
char buf[LOADPARM_LEN + 1];
reipl_get_ascii_loadparm(buf, ipb);
return sprintf(page, "%s\n", buf);
}
static ssize_t reipl_generic_loadparm_store(struct ipl_parameter_block *ipb,
const char *buf, size_t len)
{
int i, lp_len;
lp_len = len;
if ((len > 0) && (buf[len - 1] == '\n'))
lp_len--;
if ((lp_len > LOADPARM_LEN) || ((lp_len > 0) && (buf[0] == ' ')))
return -EINVAL;
for (i = 0; i < lp_len; i++) {
if (isalpha(buf[i]) || isdigit(buf[i]) || (buf[i] == ' ') ||
(buf[i] == '.'))
continue;
return -EINVAL;
}
memset(ipb->ipl_info.ccw.load_parm, ' ', LOADPARM_LEN);
memcpy(ipb->ipl_info.ccw.load_parm, buf, lp_len);
ASCEBC(ipb->ipl_info.ccw.load_parm, LOADPARM_LEN);
return len;
}
static ssize_t reipl_nss_loadparm_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
return reipl_generic_loadparm_show(reipl_block_nss, page);
}
static ssize_t reipl_nss_loadparm_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
return reipl_generic_loadparm_store(reipl_block_nss, buf, len);
}
static ssize_t reipl_ccw_loadparm_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
return reipl_generic_loadparm_show(reipl_block_ccw, page);
}
static ssize_t reipl_ccw_loadparm_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
return reipl_generic_loadparm_store(reipl_block_ccw, buf, len);
}
static void reipl_get_ascii_nss_name(char *dst,
struct ipl_parameter_block *ipb)
{
memcpy(dst, ipb->ipl_info.ccw.nss_name, NSS_NAME_SIZE);
EBCASC(dst, NSS_NAME_SIZE);
dst[NSS_NAME_SIZE] = 0;
}
static ssize_t reipl_nss_name_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
char nss_name[NSS_NAME_SIZE + 1] = {};
reipl_get_ascii_nss_name(nss_name, reipl_block_nss);
return sprintf(page, "%s\n", nss_name);
}
static ssize_t reipl_nss_name_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
int nss_len;
nss_len = len;
if ((len > 0) && (buf[len - 1] == '\n'))
nss_len--;
if (nss_len > NSS_NAME_SIZE)
return -EINVAL;
memset(reipl_block_nss->ipl_info.ccw.nss_name, 0x40, NSS_NAME_SIZE);
if (nss_len > 0) {
reipl_block_nss->ipl_info.ccw.vm_flags |=
DIAG308_VM_FLAGS_NSS_VALID;
memcpy(reipl_block_nss->ipl_info.ccw.nss_name, buf, nss_len);
ASCEBC(reipl_block_nss->ipl_info.ccw.nss_name, nss_len);
EBC_TOUPPER(reipl_block_nss->ipl_info.ccw.nss_name, nss_len);
} else {
reipl_block_nss->ipl_info.ccw.vm_flags &=
~DIAG308_VM_FLAGS_NSS_VALID;
}
return len;
}
static void set_reipl_block_actual(struct ipl_parameter_block *reipl_block)
{
reipl_block_actual = reipl_block;
os_info_entry_add(OS_INFO_REIPL_BLOCK, reipl_block_actual,
reipl_block->hdr.len);
}
static int reipl_set_type(enum ipl_type type)
{
if (!(reipl_capabilities & type))
return -EINVAL;
switch(type) {
case IPL_TYPE_CCW:
if (diag308_set_works)
reipl_method = REIPL_METHOD_CCW_DIAG;
else if (MACHINE_IS_VM)
reipl_method = REIPL_METHOD_CCW_VM;
else
reipl_method = REIPL_METHOD_CCW_CIO;
set_reipl_block_actual(reipl_block_ccw);
break;
case IPL_TYPE_FCP:
if (diag308_set_works)
reipl_method = REIPL_METHOD_FCP_RW_DIAG;
else if (MACHINE_IS_VM)
reipl_method = REIPL_METHOD_FCP_RO_VM;
else
reipl_method = REIPL_METHOD_FCP_RO_DIAG;
set_reipl_block_actual(reipl_block_fcp);
break;
case IPL_TYPE_FCP_DUMP:
reipl_method = REIPL_METHOD_FCP_DUMP;
break;
case IPL_TYPE_NSS:
if (diag308_set_works)
reipl_method = REIPL_METHOD_NSS_DIAG;
else
reipl_method = REIPL_METHOD_NSS;
set_reipl_block_actual(reipl_block_nss);
break;
case IPL_TYPE_UNKNOWN:
reipl_method = REIPL_METHOD_DEFAULT;
break;
default:
BUG();
}
reipl_type = type;
return 0;
}
static ssize_t reipl_type_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
return sprintf(page, "%s\n", ipl_type_str(reipl_type));
}
static ssize_t reipl_type_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
int rc = -EINVAL;
if (strncmp(buf, IPL_CCW_STR, strlen(IPL_CCW_STR)) == 0)
rc = reipl_set_type(IPL_TYPE_CCW);
else if (strncmp(buf, IPL_FCP_STR, strlen(IPL_FCP_STR)) == 0)
rc = reipl_set_type(IPL_TYPE_FCP);
else if (strncmp(buf, IPL_NSS_STR, strlen(IPL_NSS_STR)) == 0)
rc = reipl_set_type(IPL_TYPE_NSS);
return (rc != 0) ? rc : len;
}
static void get_ipl_string(char *dst, struct ipl_parameter_block *ipb,
const enum ipl_method m)
{
char loadparm[LOADPARM_LEN + 1] = {};
char vmparm[DIAG308_VMPARM_SIZE + 1] = {};
char nss_name[NSS_NAME_SIZE + 1] = {};
size_t pos = 0;
reipl_get_ascii_loadparm(loadparm, ipb);
reipl_get_ascii_nss_name(nss_name, ipb);
reipl_get_ascii_vmparm(vmparm, sizeof(vmparm), ipb);
switch (m) {
case REIPL_METHOD_CCW_VM:
pos = sprintf(dst, "IPL %X CLEAR", ipb->ipl_info.ccw.devno);
break;
case REIPL_METHOD_NSS:
pos = sprintf(dst, "IPL %s", nss_name);
break;
default:
break;
}
if (strlen(loadparm) > 0)
pos += sprintf(dst + pos, " LOADPARM '%s'", loadparm);
if (strlen(vmparm) > 0)
sprintf(dst + pos, " PARM %s", vmparm);
}
static void __reipl_run(void *unused)
{
struct ccw_dev_id devid;
static char buf[128];
switch (reipl_method) {
case REIPL_METHOD_CCW_CIO:
devid.devno = reipl_block_ccw->ipl_info.ccw.devno;
devid.ssid = 0;
reipl_ccw_dev(&devid);
break;
case REIPL_METHOD_CCW_VM:
get_ipl_string(buf, reipl_block_ccw, REIPL_METHOD_CCW_VM);
__cpcmd(buf, NULL, 0, NULL);
break;
case REIPL_METHOD_CCW_DIAG:
diag308(DIAG308_SET, reipl_block_ccw);
diag308(DIAG308_IPL, NULL);
break;
case REIPL_METHOD_FCP_RW_DIAG:
diag308(DIAG308_SET, reipl_block_fcp);
diag308(DIAG308_IPL, NULL);
break;
case REIPL_METHOD_FCP_RO_DIAG:
diag308(DIAG308_IPL, NULL);
break;
case REIPL_METHOD_FCP_RO_VM:
__cpcmd("IPL", NULL, 0, NULL);
break;
case REIPL_METHOD_NSS_DIAG:
diag308(DIAG308_SET, reipl_block_nss);
diag308(DIAG308_IPL, NULL);
break;
case REIPL_METHOD_NSS:
get_ipl_string(buf, reipl_block_nss, REIPL_METHOD_NSS);
__cpcmd(buf, NULL, 0, NULL);
break;
case REIPL_METHOD_DEFAULT:
if (MACHINE_IS_VM)
__cpcmd("IPL", NULL, 0, NULL);
diag308(DIAG308_IPL, NULL);
break;
case REIPL_METHOD_FCP_DUMP:
break;
}
disabled_wait((unsigned long) __builtin_return_address(0));
}
static void reipl_run(struct shutdown_trigger *trigger)
{
smp_call_ipl_cpu(__reipl_run, NULL);
}
static void reipl_block_ccw_init(struct ipl_parameter_block *ipb)
{
ipb->hdr.len = IPL_PARM_BLK_CCW_LEN;
ipb->hdr.version = IPL_PARM_BLOCK_VERSION;
ipb->hdr.blk0_len = IPL_PARM_BLK0_CCW_LEN;
ipb->hdr.pbt = DIAG308_IPL_TYPE_CCW;
}
static void reipl_block_ccw_fill_parms(struct ipl_parameter_block *ipb)
{
if (sclp_ipl_info.is_valid)
memcpy(ipb->ipl_info.ccw.load_parm,
&sclp_ipl_info.loadparm, LOADPARM_LEN);
else
memset(ipb->ipl_info.ccw.load_parm, 0x40, LOADPARM_LEN);
ipb->hdr.flags = DIAG308_FLAGS_LP_VALID;
if (MACHINE_IS_VM && diag308_set_works &&
(ipl_block.ipl_info.ccw.vm_flags & DIAG308_VM_FLAGS_VP_VALID)) {
ipb->ipl_info.ccw.vm_flags |= DIAG308_VM_FLAGS_VP_VALID;
ipb->ipl_info.ccw.vm_parm_len =
ipl_block.ipl_info.ccw.vm_parm_len;
memcpy(ipb->ipl_info.ccw.vm_parm,
ipl_block.ipl_info.ccw.vm_parm, DIAG308_VMPARM_SIZE);
}
}
static int __init reipl_nss_init(void)
{
int rc;
if (!MACHINE_IS_VM)
return 0;
reipl_block_nss = (void *) get_zeroed_page(GFP_KERNEL);
if (!reipl_block_nss)
return -ENOMEM;
if (!diag308_set_works)
sys_reipl_nss_vmparm_attr.attr.mode = S_IRUGO;
rc = sysfs_create_group(&reipl_kset->kobj, &reipl_nss_attr_group);
if (rc)
return rc;
reipl_block_ccw_init(reipl_block_nss);
if (ipl_info.type == IPL_TYPE_NSS) {
memset(reipl_block_nss->ipl_info.ccw.nss_name,
' ', NSS_NAME_SIZE);
memcpy(reipl_block_nss->ipl_info.ccw.nss_name,
kernel_nss_name, strlen(kernel_nss_name));
ASCEBC(reipl_block_nss->ipl_info.ccw.nss_name, NSS_NAME_SIZE);
reipl_block_nss->ipl_info.ccw.vm_flags |=
DIAG308_VM_FLAGS_NSS_VALID;
reipl_block_ccw_fill_parms(reipl_block_nss);
}
reipl_capabilities |= IPL_TYPE_NSS;
return 0;
}
static int __init reipl_ccw_init(void)
{
int rc;
reipl_block_ccw = (void *) get_zeroed_page(GFP_KERNEL);
if (!reipl_block_ccw)
return -ENOMEM;
if (MACHINE_IS_VM) {
if (!diag308_set_works)
sys_reipl_ccw_vmparm_attr.attr.mode = S_IRUGO;
rc = sysfs_create_group(&reipl_kset->kobj,
&reipl_ccw_attr_group_vm);
} else {
if(!diag308_set_works)
sys_reipl_ccw_loadparm_attr.attr.mode = S_IRUGO;
rc = sysfs_create_group(&reipl_kset->kobj,
&reipl_ccw_attr_group_lpar);
}
if (rc)
return rc;
reipl_block_ccw_init(reipl_block_ccw);
if (ipl_info.type == IPL_TYPE_CCW) {
reipl_block_ccw->ipl_info.ccw.devno = ipl_devno;
reipl_block_ccw_fill_parms(reipl_block_ccw);
}
reipl_capabilities |= IPL_TYPE_CCW;
return 0;
}
static int __init reipl_fcp_init(void)
{
int rc;
if (!diag308_set_works) {
if (ipl_info.type == IPL_TYPE_FCP) {
make_attrs_ro(reipl_fcp_attrs);
sys_reipl_fcp_scp_data_attr.attr.mode = S_IRUGO;
} else
return 0;
}
reipl_block_fcp = (void *) get_zeroed_page(GFP_KERNEL);
if (!reipl_block_fcp)
return -ENOMEM;
reipl_fcp_kset = kset_create_and_add(IPL_FCP_STR, NULL,
&reipl_kset->kobj);
if (!reipl_fcp_kset) {
free_page((unsigned long) reipl_block_fcp);
return -ENOMEM;
}
rc = sysfs_create_group(&reipl_fcp_kset->kobj, &reipl_fcp_attr_group);
if (rc) {
kset_unregister(reipl_fcp_kset);
free_page((unsigned long) reipl_block_fcp);
return rc;
}
rc = sysfs_create_bin_file(&reipl_fcp_kset->kobj,
&sys_reipl_fcp_scp_data_attr);
if (rc) {
sysfs_remove_group(&reipl_fcp_kset->kobj, &reipl_fcp_attr_group);
kset_unregister(reipl_fcp_kset);
free_page((unsigned long) reipl_block_fcp);
return rc;
}
if (ipl_info.type == IPL_TYPE_FCP)
memcpy(reipl_block_fcp, IPL_PARMBLOCK_START, PAGE_SIZE);
else {
reipl_block_fcp->hdr.len = IPL_PARM_BLK_FCP_LEN;
reipl_block_fcp->hdr.version = IPL_PARM_BLOCK_VERSION;
reipl_block_fcp->hdr.blk0_len = IPL_PARM_BLK0_FCP_LEN;
reipl_block_fcp->hdr.pbt = DIAG308_IPL_TYPE_FCP;
reipl_block_fcp->ipl_info.fcp.opt = DIAG308_IPL_OPT_IPL;
}
reipl_capabilities |= IPL_TYPE_FCP;
return 0;
}
static int __init reipl_type_init(void)
{
enum ipl_type reipl_type = ipl_info.type;
struct ipl_parameter_block *reipl_block;
unsigned long size;
reipl_block = os_info_old_entry(OS_INFO_REIPL_BLOCK, &size);
if (!reipl_block)
goto out;
if (reipl_block->hdr.pbt == DIAG308_IPL_TYPE_FCP) {
memcpy(reipl_block_fcp, reipl_block, size);
reipl_type = IPL_TYPE_FCP;
} else if (reipl_block->hdr.pbt == DIAG308_IPL_TYPE_CCW) {
memcpy(reipl_block_ccw, reipl_block, size);
reipl_type = IPL_TYPE_CCW;
}
out:
return reipl_set_type(reipl_type);
}
static int __init reipl_init(void)
{
int rc;
reipl_kset = kset_create_and_add("reipl", NULL, firmware_kobj);
if (!reipl_kset)
return -ENOMEM;
rc = sysfs_create_file(&reipl_kset->kobj, &reipl_type_attr.attr);
if (rc) {
kset_unregister(reipl_kset);
return rc;
}
rc = reipl_ccw_init();
if (rc)
return rc;
rc = reipl_fcp_init();
if (rc)
return rc;
rc = reipl_nss_init();
if (rc)
return rc;
return reipl_type_init();
}
static int dump_set_type(enum dump_type type)
{
if (!(dump_capabilities & type))
return -EINVAL;
switch (type) {
case DUMP_TYPE_CCW:
if (diag308_set_works)
dump_method = DUMP_METHOD_CCW_DIAG;
else if (MACHINE_IS_VM)
dump_method = DUMP_METHOD_CCW_VM;
else
dump_method = DUMP_METHOD_CCW_CIO;
break;
case DUMP_TYPE_FCP:
dump_method = DUMP_METHOD_FCP_DIAG;
break;
default:
dump_method = DUMP_METHOD_NONE;
}
dump_type = type;
return 0;
}
static ssize_t dump_type_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
return sprintf(page, "%s\n", dump_type_str(dump_type));
}
static ssize_t dump_type_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
int rc = -EINVAL;
if (strncmp(buf, DUMP_NONE_STR, strlen(DUMP_NONE_STR)) == 0)
rc = dump_set_type(DUMP_TYPE_NONE);
else if (strncmp(buf, DUMP_CCW_STR, strlen(DUMP_CCW_STR)) == 0)
rc = dump_set_type(DUMP_TYPE_CCW);
else if (strncmp(buf, DUMP_FCP_STR, strlen(DUMP_FCP_STR)) == 0)
rc = dump_set_type(DUMP_TYPE_FCP);
return (rc != 0) ? rc : len;
}
static void diag308_dump(void *dump_block)
{
diag308(DIAG308_SET, dump_block);
while (1) {
if (diag308(DIAG308_DUMP, NULL) != 0x302)
break;
udelay_simple(USEC_PER_SEC);
}
}
static void __dump_run(void *unused)
{
struct ccw_dev_id devid;
static char buf[100];
switch (dump_method) {
case DUMP_METHOD_CCW_CIO:
devid.devno = dump_block_ccw->ipl_info.ccw.devno;
devid.ssid = 0;
reipl_ccw_dev(&devid);
break;
case DUMP_METHOD_CCW_VM:
sprintf(buf, "STORE STATUS");
__cpcmd(buf, NULL, 0, NULL);
sprintf(buf, "IPL %X", dump_block_ccw->ipl_info.ccw.devno);
__cpcmd(buf, NULL, 0, NULL);
break;
case DUMP_METHOD_CCW_DIAG:
diag308_dump(dump_block_ccw);
break;
case DUMP_METHOD_FCP_DIAG:
diag308_dump(dump_block_fcp);
break;
default:
break;
}
}
static void dump_run(struct shutdown_trigger *trigger)
{
if (dump_method == DUMP_METHOD_NONE)
return;
smp_send_stop();
smp_call_ipl_cpu(__dump_run, NULL);
}
static int __init dump_ccw_init(void)
{
int rc;
dump_block_ccw = (void *) get_zeroed_page(GFP_KERNEL);
if (!dump_block_ccw)
return -ENOMEM;
rc = sysfs_create_group(&dump_kset->kobj, &dump_ccw_attr_group);
if (rc) {
free_page((unsigned long)dump_block_ccw);
return rc;
}
dump_block_ccw->hdr.len = IPL_PARM_BLK_CCW_LEN;
dump_block_ccw->hdr.version = IPL_PARM_BLOCK_VERSION;
dump_block_ccw->hdr.blk0_len = IPL_PARM_BLK0_CCW_LEN;
dump_block_ccw->hdr.pbt = DIAG308_IPL_TYPE_CCW;
dump_capabilities |= DUMP_TYPE_CCW;
return 0;
}
static int __init dump_fcp_init(void)
{
int rc;
if (!sclp_ipl_info.has_dump)
return 0;
if (!diag308_set_works)
return 0;
dump_block_fcp = (void *) get_zeroed_page(GFP_KERNEL);
if (!dump_block_fcp)
return -ENOMEM;
rc = sysfs_create_group(&dump_kset->kobj, &dump_fcp_attr_group);
if (rc) {
free_page((unsigned long)dump_block_fcp);
return rc;
}
dump_block_fcp->hdr.len = IPL_PARM_BLK_FCP_LEN;
dump_block_fcp->hdr.version = IPL_PARM_BLOCK_VERSION;
dump_block_fcp->hdr.blk0_len = IPL_PARM_BLK0_FCP_LEN;
dump_block_fcp->hdr.pbt = DIAG308_IPL_TYPE_FCP;
dump_block_fcp->ipl_info.fcp.opt = DIAG308_IPL_OPT_DUMP;
dump_capabilities |= DUMP_TYPE_FCP;
return 0;
}
static int __init dump_init(void)
{
int rc;
dump_kset = kset_create_and_add("dump", NULL, firmware_kobj);
if (!dump_kset)
return -ENOMEM;
rc = sysfs_create_file(&dump_kset->kobj, &dump_type_attr.attr);
if (rc) {
kset_unregister(dump_kset);
return rc;
}
rc = dump_ccw_init();
if (rc)
return rc;
rc = dump_fcp_init();
if (rc)
return rc;
dump_set_type(DUMP_TYPE_NONE);
return 0;
}
static void dump_reipl_run(struct shutdown_trigger *trigger)
{
unsigned long ipib = (unsigned long) reipl_block_actual;
unsigned int csum;
csum = csum_partial(reipl_block_actual, reipl_block_actual->hdr.len, 0);
mem_assign_absolute(S390_lowcore.ipib, ipib);
mem_assign_absolute(S390_lowcore.ipib_checksum, csum);
dump_run(trigger);
}
static int __init dump_reipl_init(void)
{
if (!diag308_set_works)
return -EOPNOTSUPP;
else
return 0;
}
static void vmcmd_run(struct shutdown_trigger *trigger)
{
char *cmd;
if (strcmp(trigger->name, ON_REIPL_STR) == 0)
cmd = vmcmd_on_reboot;
else if (strcmp(trigger->name, ON_PANIC_STR) == 0)
cmd = vmcmd_on_panic;
else if (strcmp(trigger->name, ON_HALT_STR) == 0)
cmd = vmcmd_on_halt;
else if (strcmp(trigger->name, ON_POFF_STR) == 0)
cmd = vmcmd_on_poff;
else if (strcmp(trigger->name, ON_RESTART_STR) == 0)
cmd = vmcmd_on_restart;
else
return;
if (strlen(cmd) == 0)
return;
__cpcmd(cmd, NULL, 0, NULL);
}
static int vmcmd_init(void)
{
if (!MACHINE_IS_VM)
return -EOPNOTSUPP;
vmcmd_kset = kset_create_and_add("vmcmd", NULL, firmware_kobj);
if (!vmcmd_kset)
return -ENOMEM;
return sysfs_create_group(&vmcmd_kset->kobj, &vmcmd_attr_group);
}
static void stop_run(struct shutdown_trigger *trigger)
{
if (strcmp(trigger->name, ON_PANIC_STR) == 0 ||
strcmp(trigger->name, ON_RESTART_STR) == 0)
disabled_wait((unsigned long) __builtin_return_address(0));
smp_stop_cpu();
}
static int set_trigger(const char *buf, struct shutdown_trigger *trigger,
size_t len)
{
int i;
for (i = 0; i < SHUTDOWN_ACTIONS_COUNT; i++) {
if (sysfs_streq(buf, shutdown_actions_list[i]->name)) {
if (shutdown_actions_list[i]->init_rc) {
return shutdown_actions_list[i]->init_rc;
} else {
trigger->action = shutdown_actions_list[i];
return len;
}
}
}
return -EINVAL;
}
static ssize_t on_reboot_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
return sprintf(page, "%s\n", on_reboot_trigger.action->name);
}
static ssize_t on_reboot_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
return set_trigger(buf, &on_reboot_trigger, len);
}
static void do_machine_restart(char *__unused)
{
smp_send_stop();
on_reboot_trigger.action->fn(&on_reboot_trigger);
reipl_run(NULL);
}
static ssize_t on_panic_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
return sprintf(page, "%s\n", on_panic_trigger.action->name);
}
static ssize_t on_panic_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
return set_trigger(buf, &on_panic_trigger, len);
}
static void do_panic(void)
{
lgr_info_log();
on_panic_trigger.action->fn(&on_panic_trigger);
stop_run(&on_panic_trigger);
}
static ssize_t on_restart_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
return sprintf(page, "%s\n", on_restart_trigger.action->name);
}
static ssize_t on_restart_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
return set_trigger(buf, &on_restart_trigger, len);
}
static void __do_restart(void *ignore)
{
__arch_local_irq_stosm(0x04);
smp_send_stop();
#ifdef CONFIG_CRASH_DUMP
crash_kexec(NULL);
#endif
on_restart_trigger.action->fn(&on_restart_trigger);
stop_run(&on_restart_trigger);
}
void do_restart(void)
{
tracing_off();
debug_locks_off();
lgr_info_log();
smp_call_online_cpu(__do_restart, NULL);
}
static ssize_t on_halt_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
return sprintf(page, "%s\n", on_halt_trigger.action->name);
}
static ssize_t on_halt_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
return set_trigger(buf, &on_halt_trigger, len);
}
static void do_machine_halt(void)
{
smp_send_stop();
on_halt_trigger.action->fn(&on_halt_trigger);
stop_run(&on_halt_trigger);
}
static ssize_t on_poff_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
return sprintf(page, "%s\n", on_poff_trigger.action->name);
}
static ssize_t on_poff_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
return set_trigger(buf, &on_poff_trigger, len);
}
static void do_machine_power_off(void)
{
smp_send_stop();
on_poff_trigger.action->fn(&on_poff_trigger);
stop_run(&on_poff_trigger);
}
static void __init shutdown_triggers_init(void)
{
shutdown_actions_kset = kset_create_and_add("shutdown_actions", NULL,
firmware_kobj);
if (!shutdown_actions_kset)
goto fail;
if (sysfs_create_file(&shutdown_actions_kset->kobj,
&on_reboot_attr.attr))
goto fail;
if (sysfs_create_file(&shutdown_actions_kset->kobj,
&on_panic_attr.attr))
goto fail;
if (sysfs_create_file(&shutdown_actions_kset->kobj,
&on_halt_attr.attr))
goto fail;
if (sysfs_create_file(&shutdown_actions_kset->kobj,
&on_poff_attr.attr))
goto fail;
if (sysfs_create_file(&shutdown_actions_kset->kobj,
&on_restart_attr.attr))
goto fail;
return;
fail:
panic("shutdown_triggers_init failed\n");
}
static void __init shutdown_actions_init(void)
{
int i;
for (i = 0; i < SHUTDOWN_ACTIONS_COUNT; i++) {
if (!shutdown_actions_list[i]->init)
continue;
shutdown_actions_list[i]->init_rc =
shutdown_actions_list[i]->init();
}
}
static int __init s390_ipl_init(void)
{
sclp_get_ipl_info(&sclp_ipl_info);
shutdown_actions_init();
shutdown_triggers_init();
return 0;
}
static void __init strncpy_skip_quote(char *dst, char *src, int n)
{
int sx, dx;
dx = 0;
for (sx = 0; src[sx] != 0; sx++) {
if (src[sx] == '"')
continue;
dst[dx++] = src[sx];
if (dx >= n)
break;
}
}
static int __init vmcmd_on_reboot_setup(char *str)
{
if (!MACHINE_IS_VM)
return 1;
strncpy_skip_quote(vmcmd_on_reboot, str, 127);
vmcmd_on_reboot[127] = 0;
on_reboot_trigger.action = &vmcmd_action;
return 1;
}
static int __init vmcmd_on_panic_setup(char *str)
{
if (!MACHINE_IS_VM)
return 1;
strncpy_skip_quote(vmcmd_on_panic, str, 127);
vmcmd_on_panic[127] = 0;
on_panic_trigger.action = &vmcmd_action;
return 1;
}
static int __init vmcmd_on_halt_setup(char *str)
{
if (!MACHINE_IS_VM)
return 1;
strncpy_skip_quote(vmcmd_on_halt, str, 127);
vmcmd_on_halt[127] = 0;
on_halt_trigger.action = &vmcmd_action;
return 1;
}
static int __init vmcmd_on_poff_setup(char *str)
{
if (!MACHINE_IS_VM)
return 1;
strncpy_skip_quote(vmcmd_on_poff, str, 127);
vmcmd_on_poff[127] = 0;
on_poff_trigger.action = &vmcmd_action;
return 1;
}
static int on_panic_notify(struct notifier_block *self,
unsigned long event, void *data)
{
do_panic();
return NOTIFY_OK;
}
void __init setup_ipl(void)
{
ipl_info.type = get_ipl_type();
switch (ipl_info.type) {
case IPL_TYPE_CCW:
ipl_info.data.ccw.dev_id.devno = ipl_devno;
ipl_info.data.ccw.dev_id.ssid = 0;
break;
case IPL_TYPE_FCP:
case IPL_TYPE_FCP_DUMP:
ipl_info.data.fcp.dev_id.devno =
IPL_PARMBLOCK_START->ipl_info.fcp.devno;
ipl_info.data.fcp.dev_id.ssid = 0;
ipl_info.data.fcp.wwpn = IPL_PARMBLOCK_START->ipl_info.fcp.wwpn;
ipl_info.data.fcp.lun = IPL_PARMBLOCK_START->ipl_info.fcp.lun;
break;
case IPL_TYPE_NSS:
strncpy(ipl_info.data.nss.name, kernel_nss_name,
sizeof(ipl_info.data.nss.name));
break;
case IPL_TYPE_UNKNOWN:
break;
}
atomic_notifier_chain_register(&panic_notifier_list, &on_panic_nb);
}
void __init ipl_update_parameters(void)
{
int rc;
rc = diag308(DIAG308_STORE, &ipl_block);
if ((rc == DIAG308_RC_OK) || (rc == DIAG308_RC_NOCONFIG))
diag308_set_works = 1;
}
void __init ipl_save_parameters(void)
{
struct cio_iplinfo iplinfo;
void *src, *dst;
if (cio_get_iplinfo(&iplinfo))
return;
ipl_devno = iplinfo.devno;
ipl_flags |= IPL_DEVNO_VALID;
if (!iplinfo.is_qdio)
return;
ipl_flags |= IPL_PARMBLOCK_VALID;
src = (void *)(unsigned long)S390_lowcore.ipl_parmblock_ptr;
dst = (void *)IPL_PARMBLOCK_ORIGIN;
memmove(dst, src, PAGE_SIZE);
S390_lowcore.ipl_parmblock_ptr = IPL_PARMBLOCK_ORIGIN;
}
void register_reset_call(struct reset_call *reset)
{
mutex_lock(&rcall_mutex);
list_add(&reset->list, &rcall);
mutex_unlock(&rcall_mutex);
}
void unregister_reset_call(struct reset_call *reset)
{
mutex_lock(&rcall_mutex);
list_del(&reset->list);
mutex_unlock(&rcall_mutex);
}
static void do_reset_calls(void)
{
struct reset_call *reset;
#ifdef CONFIG_64BIT
if (diag308_set_works) {
diag308_reset();
return;
}
#endif
list_for_each_entry(reset, &rcall, list)
reset->fn();
}
void s390_reset_system(void (*func)(void *), void *data)
{
struct _lowcore *lc;
lc = (struct _lowcore *)(unsigned long) store_prefix();
lc->panic_stack = S390_lowcore.panic_stack;
dump_prefix_page = (u32)(unsigned long) lc;
set_prefix(0);
__ctl_clear_bit(0,28);
S390_lowcore.mcck_new_psw.mask = psw_kernel_bits | PSW_MASK_DAT;
S390_lowcore.mcck_new_psw.addr =
PSW_ADDR_AMODE | (unsigned long) s390_base_mcck_handler;
S390_lowcore.program_new_psw.mask = psw_kernel_bits | PSW_MASK_DAT;
S390_lowcore.program_new_psw.addr =
PSW_ADDR_AMODE | (unsigned long) s390_base_pgm_handler;
store_status();
do_reset_calls();
if (func)
func(data);
}
