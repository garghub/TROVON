static void set_data(char *field, char *data)
{
memset(field, ' ', CPI_LENGTH_NAME);
memcpy(field, data, strlen(data));
sclp_ascebc_str(field, CPI_LENGTH_NAME);
}
static void cpi_callback(struct sclp_req *req, void *data)
{
struct completion *completion = data;
complete(completion);
}
static struct sclp_req *cpi_prepare_req(void)
{
struct sclp_req *req;
struct cpi_sccb *sccb;
struct cpi_evbuf *evb;
req = kzalloc(sizeof(struct sclp_req), GFP_KERNEL);
if (!req)
return ERR_PTR(-ENOMEM);
sccb = (struct cpi_sccb *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!sccb) {
kfree(req);
return ERR_PTR(-ENOMEM);
}
sccb->header.length = sizeof(struct cpi_sccb);
sccb->cpi_evbuf.header.length = sizeof(struct cpi_evbuf);
sccb->cpi_evbuf.header.type = 0x0b;
evb = &sccb->cpi_evbuf;
set_data(evb->system_type, system_type);
set_data(evb->system_name, system_name);
evb->system_level = system_level;
set_data(evb->sysplex_name, sysplex_name);
req->command = SCLP_CMDW_WRITE_EVENT_DATA;
req->sccb = sccb;
req->status = SCLP_REQ_FILLED;
req->callback = cpi_callback;
return req;
}
static void cpi_free_req(struct sclp_req *req)
{
free_page((unsigned long) req->sccb);
kfree(req);
}
static int cpi_req(void)
{
struct completion completion;
struct sclp_req *req;
int rc;
int response;
rc = sclp_register(&sclp_cpi_event);
if (rc)
goto out;
if (!(sclp_cpi_event.sclp_receive_mask & EVTYP_CTLPROGIDENT_MASK)) {
rc = -EOPNOTSUPP;
goto out_unregister;
}
req = cpi_prepare_req();
if (IS_ERR(req)) {
rc = PTR_ERR(req);
goto out_unregister;
}
init_completion(&completion);
req->callback_data = &completion;
rc = sclp_add_request(req);
if (rc)
goto out_free_req;
wait_for_completion(&completion);
if (req->status != SCLP_REQ_DONE) {
pr_warning("request failed (status=0x%02x)\n",
req->status);
rc = -EIO;
goto out_free_req;
}
response = ((struct cpi_sccb *) req->sccb)->header.response_code;
if (response != 0x0020) {
pr_warning("request failed with response code 0x%x\n",
response);
rc = -EIO;
}
out_free_req:
cpi_free_req(req);
out_unregister:
sclp_unregister(&sclp_cpi_event);
out:
return rc;
}
static int check_string(const char *attr, const char *str)
{
size_t len;
size_t i;
len = strlen(str);
if ((len > 0) && (str[len - 1] == '\n'))
len--;
if (len > CPI_LENGTH_NAME)
return -EINVAL;
for (i = 0; i < len ; i++) {
if (isalpha(str[i]) || isdigit(str[i]) ||
strchr("$@# ", str[i]))
continue;
return -EINVAL;
}
return 0;
}
static void set_string(char *attr, const char *value)
{
size_t len;
size_t i;
len = strlen(value);
if ((len > 0) && (value[len - 1] == '\n'))
len--;
for (i = 0; i < CPI_LENGTH_NAME; i++) {
if (i < len)
attr[i] = toupper(value[i]);
else
attr[i] = ' ';
}
}
static ssize_t system_name_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
int rc;
mutex_lock(&sclp_cpi_mutex);
rc = snprintf(page, PAGE_SIZE, "%s\n", system_name);
mutex_unlock(&sclp_cpi_mutex);
return rc;
}
static ssize_t system_name_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf,
size_t len)
{
int rc;
rc = check_string("system_name", buf);
if (rc)
return rc;
mutex_lock(&sclp_cpi_mutex);
set_string(system_name, buf);
mutex_unlock(&sclp_cpi_mutex);
return len;
}
static ssize_t sysplex_name_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
int rc;
mutex_lock(&sclp_cpi_mutex);
rc = snprintf(page, PAGE_SIZE, "%s\n", sysplex_name);
mutex_unlock(&sclp_cpi_mutex);
return rc;
}
static ssize_t sysplex_name_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf,
size_t len)
{
int rc;
rc = check_string("sysplex_name", buf);
if (rc)
return rc;
mutex_lock(&sclp_cpi_mutex);
set_string(sysplex_name, buf);
mutex_unlock(&sclp_cpi_mutex);
return len;
}
static ssize_t system_type_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
int rc;
mutex_lock(&sclp_cpi_mutex);
rc = snprintf(page, PAGE_SIZE, "%s\n", system_type);
mutex_unlock(&sclp_cpi_mutex);
return rc;
}
static ssize_t system_type_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf,
size_t len)
{
int rc;
rc = check_string("system_type", buf);
if (rc)
return rc;
mutex_lock(&sclp_cpi_mutex);
set_string(system_type, buf);
mutex_unlock(&sclp_cpi_mutex);
return len;
}
static ssize_t system_level_show(struct kobject *kobj,
struct kobj_attribute *attr, char *page)
{
unsigned long long level;
mutex_lock(&sclp_cpi_mutex);
level = system_level;
mutex_unlock(&sclp_cpi_mutex);
return snprintf(page, PAGE_SIZE, "%#018llx\n", level);
}
static ssize_t system_level_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf,
size_t len)
{
unsigned long long level;
char *endp;
level = simple_strtoull(buf, &endp, 16);
if (endp == buf)
return -EINVAL;
if (*endp == '\n')
endp++;
if (*endp)
return -EINVAL;
mutex_lock(&sclp_cpi_mutex);
system_level = level;
mutex_unlock(&sclp_cpi_mutex);
return len;
}
static ssize_t set_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t len)
{
int rc;
mutex_lock(&sclp_cpi_mutex);
rc = cpi_req();
mutex_unlock(&sclp_cpi_mutex);
if (rc)
return rc;
return len;
}
int sclp_cpi_set_data(const char *system, const char *sysplex, const char *type,
const u64 level)
{
int rc;
rc = check_string("system_name", system);
if (rc)
return rc;
rc = check_string("sysplex_name", sysplex);
if (rc)
return rc;
rc = check_string("system_type", type);
if (rc)
return rc;
mutex_lock(&sclp_cpi_mutex);
set_string(system_name, system);
set_string(sysplex_name, sysplex);
set_string(system_type, type);
system_level = level;
rc = cpi_req();
mutex_unlock(&sclp_cpi_mutex);
return rc;
}
static int __init cpi_init(void)
{
int rc;
cpi_kset = kset_create_and_add("cpi", NULL, firmware_kobj);
if (!cpi_kset)
return -ENOMEM;
rc = sysfs_create_group(&cpi_kset->kobj, &cpi_attr_group);
if (rc)
kset_unregister(cpi_kset);
return rc;
}
