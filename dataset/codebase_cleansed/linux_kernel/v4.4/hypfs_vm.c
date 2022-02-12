static int diag2fc(int size, char* query, void *addr)
{
unsigned long residual_cnt;
unsigned long rc;
struct diag2fc_parm_list parm_list;
memcpy(parm_list.userid, query, NAME_LEN);
ASCEBC(parm_list.userid, NAME_LEN);
parm_list.addr = (unsigned long) addr ;
parm_list.size = size;
parm_list.fmt = 0x02;
memset(parm_list.aci_grp, 0x40, NAME_LEN);
rc = -1;
diag_stat_inc(DIAG_STAT_X2FC);
asm volatile(
" diag %0,%1,0x2fc\n"
"0:\n"
EX_TABLE(0b,0b)
: "=d" (residual_cnt), "+d" (rc) : "0" (&parm_list) : "memory");
if ((rc != 0 ) && (rc != -2))
return rc;
else
return -residual_cnt;
}
static void *diag2fc_store(char *query, unsigned int *count, int offset)
{
void *data;
int size;
do {
size = diag2fc(0, query, NULL);
if (size < 0)
return ERR_PTR(-EACCES);
data = vmalloc(size + offset);
if (!data)
return ERR_PTR(-ENOMEM);
if (diag2fc(size, query, data + offset) == 0)
break;
vfree(data);
} while (1);
*count = (size / sizeof(struct diag2fc_data));
return data;
}
static void diag2fc_free(const void *data)
{
vfree(data);
}
static int hpyfs_vm_create_guest(struct dentry *systems_dir,
struct diag2fc_data *data)
{
char guest_name[NAME_LEN + 1] = {};
struct dentry *guest_dir, *cpus_dir, *samples_dir, *mem_dir;
int dedicated_flag, capped_value;
capped_value = (data->flags & 0x00000006) >> 1;
dedicated_flag = (data->flags & 0x00000008) >> 3;
memcpy(guest_name, data->guest_name, NAME_LEN);
EBCASC(guest_name, NAME_LEN);
strim(guest_name);
guest_dir = hypfs_mkdir(systems_dir, guest_name);
if (IS_ERR(guest_dir))
return PTR_ERR(guest_dir);
ATTRIBUTE(guest_dir, "onlinetime_us", data->el_time);
cpus_dir = hypfs_mkdir(guest_dir, "cpus");
if (IS_ERR(cpus_dir))
return PTR_ERR(cpus_dir);
ATTRIBUTE(cpus_dir, "cputime_us", data->used_cpu);
ATTRIBUTE(cpus_dir, "capped", capped_value);
ATTRIBUTE(cpus_dir, "dedicated", dedicated_flag);
ATTRIBUTE(cpus_dir, "count", data->vcpus);
ATTRIBUTE(cpus_dir, "weight_min", data->ocpus);
ATTRIBUTE(cpus_dir, "weight_max", data->cpu_max);
ATTRIBUTE(cpus_dir, "weight_cur", data->cpu_shares);
mem_dir = hypfs_mkdir(guest_dir, "mem");
if (IS_ERR(mem_dir))
return PTR_ERR(mem_dir);
ATTRIBUTE(mem_dir, "min_KiB", data->mem_min_kb);
ATTRIBUTE(mem_dir, "max_KiB", data->mem_max_kb);
ATTRIBUTE(mem_dir, "used_KiB", data->mem_used_kb);
ATTRIBUTE(mem_dir, "share_KiB", data->mem_share_kb);
samples_dir = hypfs_mkdir(guest_dir, "samples");
if (IS_ERR(samples_dir))
return PTR_ERR(samples_dir);
ATTRIBUTE(samples_dir, "cpu_using", data->cpu_use_samp);
ATTRIBUTE(samples_dir, "cpu_delay", data->cpu_delay_samp);
ATTRIBUTE(samples_dir, "mem_delay", data->page_wait_samp);
ATTRIBUTE(samples_dir, "idle", data->idle_samp);
ATTRIBUTE(samples_dir, "other", data->other_samp);
ATTRIBUTE(samples_dir, "total", data->total_samp);
return 0;
}
int hypfs_vm_create_files(struct dentry *root)
{
struct dentry *dir, *file;
struct diag2fc_data *data;
unsigned int count = 0;
int rc, i;
data = diag2fc_store(guest_query, &count, 0);
if (IS_ERR(data))
return PTR_ERR(data);
dir = hypfs_mkdir(root, "hyp");
if (IS_ERR(dir)) {
rc = PTR_ERR(dir);
goto failed;
}
file = hypfs_create_str(dir, "type", "z/VM Hypervisor");
if (IS_ERR(file)) {
rc = PTR_ERR(file);
goto failed;
}
dir = hypfs_mkdir(root, "cpus");
if (IS_ERR(dir)) {
rc = PTR_ERR(dir);
goto failed;
}
file = hypfs_create_u64(dir, "count", data->lcpus);
if (IS_ERR(file)) {
rc = PTR_ERR(file);
goto failed;
}
dir = hypfs_mkdir(root, "systems");
if (IS_ERR(dir)) {
rc = PTR_ERR(dir);
goto failed;
}
for (i = 0; i < count; i++) {
rc = hpyfs_vm_create_guest(dir, &(data[i]));
if (rc)
goto failed;
}
diag2fc_free(data);
return 0;
failed:
diag2fc_free(data);
return rc;
}
static int dbfs_diag2fc_create(void **data, void **data_free_ptr, size_t *size)
{
struct dbfs_d2fc *d2fc;
unsigned int count;
d2fc = diag2fc_store(guest_query, &count, sizeof(d2fc->hdr));
if (IS_ERR(d2fc))
return PTR_ERR(d2fc);
get_tod_clock_ext(d2fc->hdr.tod_ext);
d2fc->hdr.len = count * sizeof(struct diag2fc_data);
d2fc->hdr.version = DBFS_D2FC_HDR_VERSION;
d2fc->hdr.count = count;
memset(&d2fc->hdr.reserved, 0, sizeof(d2fc->hdr.reserved));
*data = d2fc;
*data_free_ptr = d2fc;
*size = d2fc->hdr.len + sizeof(struct dbfs_d2fc_hdr);
return 0;
}
int hypfs_vm_init(void)
{
if (!MACHINE_IS_VM)
return 0;
if (diag2fc(0, all_guests, NULL) > 0)
guest_query = all_guests;
else if (diag2fc(0, local_guest, NULL) > 0)
guest_query = local_guest;
else
return -EACCES;
return hypfs_dbfs_create_file(&dbfs_file_2fc);
}
void hypfs_vm_exit(void)
{
if (!MACHINE_IS_VM)
return;
hypfs_dbfs_remove_file(&dbfs_file_2fc);
}
