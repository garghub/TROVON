static struct proc_dir_entry *
createProcDir(const char *name, struct proc_dir_entry *parent)
{
struct proc_dir_entry *p = proc_mkdir_mode(name, S_IFDIR, parent);
if (p == NULL)
ERRDRV("failed to create /proc directory %s", name);
return p;
}
static struct proc_dir_entry *
createProcFile(const char *name, struct proc_dir_entry *parent,
const struct file_operations *fops, void *data)
{
struct proc_dir_entry *p = proc_create_data(name, 0, parent,
fops, data);
if (p == NULL)
ERRDRV("failed to create /proc file %s", name);
return p;
}
static int proc_open(struct inode *inode, struct file *file)
{
return single_open(file, seq_show, PDE_DATA(inode));
}
MYPROCTYPE *visor_proc_CreateType(struct proc_dir_entry *procDirRoot,
const char **name,
const char **propertyNames,
void (*show_property)(struct seq_file *,
void *, int))
{
int i = 0;
MYPROCTYPE *rc = NULL, *type = NULL;
struct proc_dir_entry *parent = NULL;
if (procDirRoot == NULL) {
ERRDRV("procDirRoot cannot be NULL!\n");
goto Away;
}
if (name == NULL || name[0] == NULL) {
ERRDRV("name must contain at least 1 node name!\n");
goto Away;
}
type = kzalloc(sizeof(MYPROCTYPE), GFP_KERNEL | __GFP_NORETRY);
if (type == NULL) {
ERRDRV("out of memory\n");
goto Away;
}
type->name = name;
type->propertyNames = propertyNames;
type->nProperties = 0;
type->nNames = 0;
type->show_property = show_property;
type->procDirRoot = procDirRoot;
if (type->propertyNames != NULL)
while (type->propertyNames[type->nProperties] != NULL)
type->nProperties++;
while (type->name[type->nNames] != NULL)
type->nNames++;
type->procDirs = kzalloc((type->nNames + 1) *
sizeof(struct proc_dir_entry *),
GFP_KERNEL | __GFP_NORETRY);
if (type->procDirs == NULL) {
ERRDRV("out of memory\n");
goto Away;
}
parent = procDirRoot;
for (i = 0; i < type->nNames; i++) {
type->procDirs[i] = createProcDir(type->name[i], parent);
if (type->procDirs[i] == NULL) {
rc = NULL;
goto Away;
}
parent = type->procDirs[i];
}
type->procDir = type->procDirs[type->nNames-1];
rc = type;
Away:
if (rc == NULL) {
if (type != NULL) {
visor_proc_DestroyType(type);
type = NULL;
}
}
return rc;
}
void visor_proc_DestroyType(MYPROCTYPE *type)
{
if (type == NULL)
return;
if (type->procDirs != NULL) {
int i = type->nNames-1;
while (i >= 0) {
if (type->procDirs[i] != NULL) {
struct proc_dir_entry *parent = NULL;
if (i == 0)
parent = type->procDirRoot;
else
parent = type->procDirs[i-1];
remove_proc_entry(type->name[i], parent);
}
i--;
}
kfree(type->procDirs);
type->procDirs = NULL;
}
kfree(type);
}
MYPROCOBJECT *visor_proc_CreateObject(MYPROCTYPE *type,
const char *name, void *context)
{
MYPROCOBJECT *obj = NULL, *rc = NULL;
int i = 0;
if (type == NULL) {
ERRDRV("type cannot be NULL\n");
goto Away;
}
obj = kzalloc(sizeof(MYPROCOBJECT), GFP_KERNEL | __GFP_NORETRY);
if (obj == NULL) {
ERRDRV("out of memory\n");
goto Away;
}
obj->type = type;
obj->context = context;
if (name == NULL) {
obj->name = NULL;
obj->procDir = type->procDir;
} else {
obj->namesize = strlen(name)+1;
obj->name = kmalloc(obj->namesize, GFP_KERNEL | __GFP_NORETRY);
if (obj->name == NULL) {
obj->namesize = 0;
ERRDRV("out of memory\n");
goto Away;
}
strcpy(obj->name, name);
obj->procDir = createProcDir(obj->name, type->procDir);
if (obj->procDir == NULL)
goto Away;
}
obj->procDirPropertyContexts =
kzalloc((type->nProperties + 1) *
sizeof(struct proc_dir_entry_context),
GFP_KERNEL | __GFP_NORETRY);
if (obj->procDirPropertyContexts == NULL) {
ERRDRV("out of memory\n");
goto Away;
}
obj->procDirProperties = kzalloc((type->nProperties + 1) *
sizeof(struct proc_dir_entry *),
GFP_KERNEL | __GFP_NORETRY);
if (obj->procDirProperties == NULL) {
ERRDRV("out of memory\n");
goto Away;
}
for (i = 0; i < type->nProperties; i++) {
obj->procDirPropertyContexts[i].procObject = obj;
obj->procDirPropertyContexts[i].propertyIndex = i;
obj->procDirPropertyContexts[i].show_property =
type->show_property;
if (type->propertyNames[i][0] != '\0') {
obj->procDirProperties[i] =
createProcFile(type->propertyNames[i],
obj->procDir, &proc_fops,
&obj->procDirPropertyContexts[i]);
if (obj->procDirProperties[i] == NULL) {
rc = NULL;
goto Away;
}
}
}
rc = obj;
Away:
if (rc == NULL) {
if (obj != NULL) {
visor_proc_DestroyObject(obj);
obj = NULL;
}
}
return rc;
}
void visor_proc_DestroyObject(MYPROCOBJECT *obj)
{
MYPROCTYPE *type = NULL;
if (obj == NULL)
return;
type = obj->type;
if (type == NULL)
return;
if (obj->procDirProperties != NULL) {
int i = 0;
for (i = 0; i < type->nProperties; i++) {
if (obj->procDirProperties[i] != NULL) {
remove_proc_entry(type->propertyNames[i],
obj->procDir);
obj->procDirProperties[i] = NULL;
}
}
kfree(obj->procDirProperties);
obj->procDirProperties = NULL;
}
kfree(obj->procDirPropertyContexts);
obj->procDirPropertyContexts = NULL;
if (obj->procDir != NULL) {
if (obj->name != NULL)
remove_proc_entry(obj->name, type->procDir);
obj->procDir = NULL;
}
kfree(obj->name);
obj->name = NULL;
kfree(obj);
}
static int seq_show(struct seq_file *seq, void *offset)
{
struct proc_dir_entry_context *ctx = seq->private;
if (ctx == NULL) {
ERRDRV("I don't have a freakin' clue...");
return 0;
}
(*ctx->show_property)(seq, ctx->procObject->context,
ctx->propertyIndex);
return 0;
}
