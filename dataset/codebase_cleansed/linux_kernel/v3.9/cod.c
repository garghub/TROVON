static s32 cod_f_close(struct file *filp)
{
if (!filp)
return -EFAULT;
filp_close(filp, NULL);
return 0;
}
static struct file *cod_f_open(const char *psz_file_name, const char *sz_mode)
{
mm_segment_t fs;
struct file *filp;
fs = get_fs();
set_fs(get_ds());
filp = filp_open(psz_file_name, O_RDONLY, 0);
if (IS_ERR(filp))
filp = NULL;
set_fs(fs);
return filp;
}
static s32 cod_f_read(void __user *pbuffer, s32 size, s32 count,
struct file *filp)
{
if (!filp)
return -EFAULT;
if ((size > 0) && (count > 0) && pbuffer) {
u32 dw_bytes_read;
mm_segment_t fs;
fs = get_fs();
set_fs(get_ds());
dw_bytes_read = filp->f_op->read(filp, pbuffer, size * count,
&(filp->f_pos));
set_fs(fs);
if (!dw_bytes_read)
return -EBADF;
return dw_bytes_read / size;
}
return -EINVAL;
}
static s32 cod_f_seek(struct file *filp, s32 offset, s32 origin)
{
loff_t dw_cur_pos;
if (!filp)
return -EFAULT;
dw_cur_pos = filp->f_op->llseek(filp, offset, origin);
if ((s32) dw_cur_pos < 0)
return -EPERM;
return 0;
}
static s32 cod_f_tell(struct file *filp)
{
loff_t dw_cur_pos;
if (!filp)
return -EFAULT;
dw_cur_pos = filp->f_op->llseek(filp, 0, SEEK_CUR);
if ((s32) dw_cur_pos < 0)
return -EPERM;
return dw_cur_pos;
}
void cod_close(struct cod_libraryobj *lib)
{
struct cod_manager *hmgr;
hmgr = lib->cod_mgr;
hmgr->fxns.close_fxn(lib->dbll_lib);
kfree(lib);
}
int cod_create(struct cod_manager **mgr, char *str_zl_file)
{
struct cod_manager *mgr_new;
struct dbll_attrs zl_attrs;
int status = 0;
*mgr = NULL;
mgr_new = kzalloc(sizeof(struct cod_manager), GFP_KERNEL);
if (mgr_new == NULL)
return -ENOMEM;
mgr_new->fxns = ldr_fxns;
mgr_new->fxns.init_fxn();
zl_attrs.alloc = (dbll_alloc_fxn) no_op;
zl_attrs.free = (dbll_free_fxn) no_op;
zl_attrs.fread = (dbll_read_fxn) cod_f_read;
zl_attrs.fseek = (dbll_seek_fxn) cod_f_seek;
zl_attrs.ftell = (dbll_tell_fxn) cod_f_tell;
zl_attrs.fclose = (dbll_f_close_fxn) cod_f_close;
zl_attrs.fopen = (dbll_f_open_fxn) cod_f_open;
zl_attrs.sym_lookup = NULL;
zl_attrs.base_image = true;
zl_attrs.log_write = NULL;
zl_attrs.log_write_handle = NULL;
zl_attrs.write = NULL;
zl_attrs.rmm_handle = NULL;
zl_attrs.input_params = NULL;
zl_attrs.sym_handle = NULL;
zl_attrs.sym_arg = NULL;
mgr_new->attrs = zl_attrs;
status = mgr_new->fxns.create_fxn(&mgr_new->target, &zl_attrs);
if (status) {
cod_delete(mgr_new);
return -ESPIPE;
}
*mgr = mgr_new;
return 0;
}
void cod_delete(struct cod_manager *cod_mgr_obj)
{
if (cod_mgr_obj->base_lib) {
if (cod_mgr_obj->loaded)
cod_mgr_obj->fxns.unload_fxn(cod_mgr_obj->base_lib,
&cod_mgr_obj->attrs);
cod_mgr_obj->fxns.close_fxn(cod_mgr_obj->base_lib);
}
if (cod_mgr_obj->target) {
cod_mgr_obj->fxns.delete_fxn(cod_mgr_obj->target);
cod_mgr_obj->fxns.exit_fxn();
}
kfree(cod_mgr_obj);
}
int cod_get_base_lib(struct cod_manager *cod_mgr_obj,
struct dbll_library_obj **plib)
{
int status = 0;
*plib = (struct dbll_library_obj *)cod_mgr_obj->base_lib;
return status;
}
int cod_get_base_name(struct cod_manager *cod_mgr_obj, char *sz_name,
u32 usize)
{
int status = 0;
if (usize <= COD_MAXPATHLENGTH)
strlcpy(sz_name, cod_mgr_obj->sz_zl_file, usize);
else
status = -EPERM;
return status;
}
int cod_get_entry(struct cod_manager *cod_mgr_obj, u32 *entry_pt)
{
*entry_pt = cod_mgr_obj->entry;
return 0;
}
int cod_get_loader(struct cod_manager *cod_mgr_obj,
struct dbll_tar_obj **loader)
{
int status = 0;
*loader = (struct dbll_tar_obj *)cod_mgr_obj->target;
return status;
}
int cod_get_section(struct cod_libraryobj *lib, char *str_sect,
u32 *addr, u32 *len)
{
struct cod_manager *cod_mgr_obj;
int status = 0;
*addr = 0;
*len = 0;
if (lib != NULL) {
cod_mgr_obj = lib->cod_mgr;
status = cod_mgr_obj->fxns.get_sect_fxn(lib->dbll_lib, str_sect,
addr, len);
} else {
status = -ESPIPE;
}
return status;
}
int cod_get_sym_value(struct cod_manager *cod_mgr_obj, char *str_sym,
u32 *pul_value)
{
struct dbll_sym_val *dbll_sym;
dev_dbg(bridge, "%s: cod_mgr_obj: %p str_sym: %s pul_value: %p\n",
__func__, cod_mgr_obj, str_sym, pul_value);
if (cod_mgr_obj->base_lib) {
if (!cod_mgr_obj->fxns.
get_addr_fxn(cod_mgr_obj->base_lib, str_sym, &dbll_sym)) {
if (!cod_mgr_obj->fxns.
get_c_addr_fxn(cod_mgr_obj->base_lib, str_sym,
&dbll_sym))
return -ESPIPE;
}
} else {
return -ESPIPE;
}
*pul_value = dbll_sym->value;
return 0;
}
int cod_load_base(struct cod_manager *cod_mgr_obj, u32 num_argc, char *args[],
cod_writefxn pfn_write, void *arb, char *envp[])
{
dbll_flags flags;
struct dbll_attrs save_attrs;
struct dbll_attrs new_attrs;
int status;
u32 i;
for (i = 0; i < num_argc; i++) {
if (args[i] == NULL) {
num_argc = i;
break;
}
}
cod_mgr_obj->fxns.get_attrs_fxn(cod_mgr_obj->target, &save_attrs);
new_attrs = save_attrs;
new_attrs.write = (dbll_write_fxn) pfn_write;
new_attrs.input_params = arb;
new_attrs.alloc = (dbll_alloc_fxn) no_op;
new_attrs.free = (dbll_free_fxn) no_op;
new_attrs.log_write = NULL;
new_attrs.log_write_handle = NULL;
flags = DBLL_CODE | DBLL_DATA | DBLL_SYMB;
status = cod_mgr_obj->fxns.load_fxn(cod_mgr_obj->base_lib, flags,
&new_attrs,
&cod_mgr_obj->entry);
if (status)
cod_mgr_obj->fxns.close_fxn(cod_mgr_obj->base_lib);
if (!status)
cod_mgr_obj->loaded = true;
else
cod_mgr_obj->base_lib = NULL;
return status;
}
int cod_open(struct cod_manager *hmgr, char *sz_coff_path,
u32 flags, struct cod_libraryobj **lib_obj)
{
int status = 0;
struct cod_libraryobj *lib = NULL;
*lib_obj = NULL;
lib = kzalloc(sizeof(struct cod_libraryobj), GFP_KERNEL);
if (lib == NULL)
status = -ENOMEM;
if (!status) {
lib->cod_mgr = hmgr;
status = hmgr->fxns.open_fxn(hmgr->target, sz_coff_path, flags,
&lib->dbll_lib);
if (!status)
*lib_obj = lib;
}
if (status)
pr_err("%s: error status 0x%x, sz_coff_path: %s flags: 0x%x\n",
__func__, status, sz_coff_path, flags);
return status;
}
int cod_open_base(struct cod_manager *hmgr, char *sz_coff_path,
dbll_flags flags)
{
int status = 0;
struct dbll_library_obj *lib;
if (hmgr->base_lib) {
if (hmgr->loaded) {
hmgr->fxns.unload_fxn(hmgr->base_lib, &hmgr->attrs);
hmgr->loaded = false;
}
hmgr->fxns.close_fxn(hmgr->base_lib);
hmgr->base_lib = NULL;
}
status = hmgr->fxns.open_fxn(hmgr->target, sz_coff_path, flags, &lib);
if (!status) {
hmgr->base_lib = lib;
strncpy(hmgr->sz_zl_file, sz_coff_path, COD_MAXPATHLENGTH - 1);
hmgr->sz_zl_file[COD_MAXPATHLENGTH - 1] = '\0';
}
if (status)
pr_err("%s: error status 0x%x sz_coff_path: %s\n", __func__,
status, sz_coff_path);
return status;
}
int cod_read_section(struct cod_libraryobj *lib, char *str_sect,
char *str_content, u32 content_size)
{
int status = 0;
if (lib != NULL)
status =
lib->cod_mgr->fxns.read_sect_fxn(lib->dbll_lib, str_sect,
str_content, content_size);
else
status = -ESPIPE;
return status;
}
static bool no_op(void)
{
return true;
}
