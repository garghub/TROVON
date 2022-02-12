static int acpi_thermal_rel_open(struct inode *inode, struct file *file)
{
spin_lock(&acpi_thermal_rel_chrdev_lock);
if (acpi_thermal_rel_chrdev_exclu ||
(acpi_thermal_rel_chrdev_count && (file->f_flags & O_EXCL))) {
spin_unlock(&acpi_thermal_rel_chrdev_lock);
return -EBUSY;
}
if (file->f_flags & O_EXCL)
acpi_thermal_rel_chrdev_exclu = 1;
acpi_thermal_rel_chrdev_count++;
spin_unlock(&acpi_thermal_rel_chrdev_lock);
return nonseekable_open(inode, file);
}
static int acpi_thermal_rel_release(struct inode *inode, struct file *file)
{
spin_lock(&acpi_thermal_rel_chrdev_lock);
acpi_thermal_rel_chrdev_count--;
acpi_thermal_rel_chrdev_exclu = 0;
spin_unlock(&acpi_thermal_rel_chrdev_lock);
return 0;
}
int acpi_parse_trt(acpi_handle handle, int *trt_count, struct trt **trtp,
bool create_dev)
{
acpi_status status;
int result = 0;
int i;
int nr_bad_entries = 0;
struct trt *trts;
struct acpi_device *adev;
union acpi_object *p;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_buffer element = { 0, NULL };
struct acpi_buffer trt_format = { sizeof("RRNNNNNN"), "RRNNNNNN" };
if (!acpi_has_method(handle, "_TRT"))
return 0;
status = acpi_evaluate_object(handle, "_TRT", NULL, &buffer);
if (ACPI_FAILURE(status))
return -ENODEV;
p = buffer.pointer;
if (!p || (p->type != ACPI_TYPE_PACKAGE)) {
pr_err("Invalid _TRT data\n");
result = -EFAULT;
goto end;
}
*trt_count = p->package.count;
trts = kzalloc(*trt_count * sizeof(struct trt), GFP_KERNEL);
if (!trts) {
result = -ENOMEM;
goto end;
}
for (i = 0; i < *trt_count; i++) {
struct trt *trt = &trts[i - nr_bad_entries];
element.length = sizeof(struct trt);
element.pointer = trt;
status = acpi_extract_package(&(p->package.elements[i]),
&trt_format, &element);
if (ACPI_FAILURE(status)) {
nr_bad_entries++;
pr_warn("_TRT package %d is invalid, ignored\n", i);
continue;
}
if (!create_dev)
continue;
result = acpi_bus_get_device(trt->source, &adev);
if (!result)
acpi_create_platform_device(adev);
else
pr_warn("Failed to get source ACPI device\n");
result = acpi_bus_get_device(trt->target, &adev);
if (!result)
acpi_create_platform_device(adev);
else
pr_warn("Failed to get target ACPI device\n");
}
*trtp = trts;
*trt_count -= nr_bad_entries;
end:
kfree(buffer.pointer);
return result;
}
int acpi_parse_art(acpi_handle handle, int *art_count, struct art **artp,
bool create_dev)
{
acpi_status status;
int result = 0;
int i;
int nr_bad_entries = 0;
struct art *arts;
struct acpi_device *adev;
union acpi_object *p;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_buffer element = { 0, NULL };
struct acpi_buffer art_format = {
sizeof("RRNNNNNNNNNNN"), "RRNNNNNNNNNNN" };
if (!acpi_has_method(handle, "_ART"))
return 0;
status = acpi_evaluate_object(handle, "_ART", NULL, &buffer);
if (ACPI_FAILURE(status))
return -ENODEV;
p = buffer.pointer;
if (!p || (p->type != ACPI_TYPE_PACKAGE)) {
pr_err("Invalid _ART data\n");
result = -EFAULT;
goto end;
}
*art_count = p->package.count - 1;
arts = kzalloc(*art_count * sizeof(struct art), GFP_KERNEL);
if (!arts) {
result = -ENOMEM;
goto end;
}
for (i = 0; i < *art_count; i++) {
struct art *art = &arts[i - nr_bad_entries];
element.length = sizeof(struct art);
element.pointer = art;
status = acpi_extract_package(&(p->package.elements[i + 1]),
&art_format, &element);
if (ACPI_FAILURE(status)) {
pr_warn("_ART package %d is invalid, ignored", i);
nr_bad_entries++;
continue;
}
if (!create_dev)
continue;
if (art->source) {
result = acpi_bus_get_device(art->source, &adev);
if (!result)
acpi_create_platform_device(adev);
else
pr_warn("Failed to get source ACPI device\n");
}
if (art->target) {
result = acpi_bus_get_device(art->target, &adev);
if (!result)
acpi_create_platform_device(adev);
else
pr_warn("Failed to get source ACPI device\n");
}
}
*artp = arts;
*art_count -= nr_bad_entries;
end:
kfree(buffer.pointer);
return result;
}
static void get_single_name(acpi_handle handle, char *name)
{
struct acpi_buffer buffer = {ACPI_ALLOCATE_BUFFER};
if (ACPI_FAILURE(acpi_get_name(handle, ACPI_SINGLE_NAME, &buffer)))
pr_warn("Failed get name from handle\n");
else {
memcpy(name, buffer.pointer, ACPI_NAME_SIZE);
kfree(buffer.pointer);
}
}
static int fill_art(char __user *ubuf)
{
int i;
int ret;
int count;
int art_len;
struct art *arts = NULL;
union art_object *art_user;
ret = acpi_parse_art(acpi_thermal_rel_handle, &count, &arts, false);
if (ret)
goto free_art;
art_len = count * sizeof(union art_object);
art_user = kzalloc(art_len, GFP_KERNEL);
if (!art_user) {
ret = -ENOMEM;
goto free_art;
}
for (i = 0; i < count; i++) {
get_single_name(arts[i].source, art_user[i].source_device);
get_single_name(arts[i].target, art_user[i].target_device);
memcpy(&art_user[i].weight, &arts[i].weight,
sizeof(u64) * (ACPI_NR_ART_ELEMENTS - 2));
}
if (copy_to_user(ubuf, art_user, art_len))
ret = -EFAULT;
kfree(art_user);
free_art:
kfree(arts);
return ret;
}
static int fill_trt(char __user *ubuf)
{
int i;
int ret;
int count;
int trt_len;
struct trt *trts = NULL;
union trt_object *trt_user;
ret = acpi_parse_trt(acpi_thermal_rel_handle, &count, &trts, false);
if (ret)
goto free_trt;
trt_len = count * sizeof(union trt_object);
trt_user = kzalloc(trt_len, GFP_KERNEL);
if (!trt_user) {
ret = -ENOMEM;
goto free_trt;
}
for (i = 0; i < count; i++) {
get_single_name(trts[i].source, trt_user[i].source_device);
get_single_name(trts[i].target, trt_user[i].target_device);
trt_user[i].sample_period = trts[i].sample_period;
trt_user[i].influence = trts[i].influence;
}
if (copy_to_user(ubuf, trt_user, trt_len))
ret = -EFAULT;
kfree(trt_user);
free_trt:
kfree(trts);
return ret;
}
static long acpi_thermal_rel_ioctl(struct file *f, unsigned int cmd,
unsigned long __arg)
{
int ret = 0;
unsigned long length = 0;
unsigned long count = 0;
char __user *arg = (void __user *)__arg;
struct trt *trts;
struct art *arts;
switch (cmd) {
case ACPI_THERMAL_GET_TRT_COUNT:
ret = acpi_parse_trt(acpi_thermal_rel_handle, (int *)&count,
&trts, false);
kfree(trts);
if (!ret)
return put_user(count, (unsigned long __user *)__arg);
return ret;
case ACPI_THERMAL_GET_TRT_LEN:
ret = acpi_parse_trt(acpi_thermal_rel_handle, (int *)&count,
&trts, false);
kfree(trts);
length = count * sizeof(union trt_object);
if (!ret)
return put_user(length, (unsigned long __user *)__arg);
return ret;
case ACPI_THERMAL_GET_TRT:
return fill_trt(arg);
case ACPI_THERMAL_GET_ART_COUNT:
ret = acpi_parse_art(acpi_thermal_rel_handle, (int *)&count,
&arts, false);
kfree(arts);
if (!ret)
return put_user(count, (unsigned long __user *)__arg);
return ret;
case ACPI_THERMAL_GET_ART_LEN:
ret = acpi_parse_art(acpi_thermal_rel_handle, (int *)&count,
&arts, false);
kfree(arts);
length = count * sizeof(union art_object);
if (!ret)
return put_user(length, (unsigned long __user *)__arg);
return ret;
case ACPI_THERMAL_GET_ART:
return fill_art(arg);
default:
return -ENOTTY;
}
}
int acpi_thermal_rel_misc_device_add(acpi_handle handle)
{
acpi_thermal_rel_handle = handle;
return misc_register(&acpi_thermal_rel_misc_device);
}
int acpi_thermal_rel_misc_device_remove(acpi_handle handle)
{
misc_deregister(&acpi_thermal_rel_misc_device);
return 0;
}
