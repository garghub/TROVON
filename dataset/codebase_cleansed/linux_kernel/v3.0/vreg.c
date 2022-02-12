struct vreg *vreg_get(struct device *dev, const char *id)
{
int n;
for (n = 0; n < ARRAY_SIZE(vregs); n++) {
if (!strcmp(vregs[n].name, id))
return vregs + n;
}
return ERR_PTR(-ENOENT);
}
void vreg_put(struct vreg *vreg)
{
}
int vreg_enable(struct vreg *vreg)
{
unsigned id = vreg->id;
unsigned enable = 1;
if (vreg->refcnt == 0)
vreg->status = msm_proc_comm(PCOM_VREG_SWITCH, &id, &enable);
if ((vreg->refcnt < UINT_MAX) && (!vreg->status))
vreg->refcnt++;
return vreg->status;
}
int vreg_disable(struct vreg *vreg)
{
unsigned id = vreg->id;
unsigned enable = 0;
if (!vreg->refcnt)
return 0;
if (vreg->refcnt == 1)
vreg->status = msm_proc_comm(PCOM_VREG_SWITCH, &id, &enable);
if (!vreg->status)
vreg->refcnt--;
return vreg->status;
}
int vreg_set_level(struct vreg *vreg, unsigned mv)
{
unsigned id = vreg->id;
vreg->status = msm_proc_comm(PCOM_VREG_SET_LEVEL, &id, &mv);
return vreg->status;
}
static int vreg_debug_set(void *data, u64 val)
{
struct vreg *vreg = data;
switch (val) {
case 0:
vreg_disable(vreg);
break;
case 1:
vreg_enable(vreg);
break;
default:
vreg_set_level(vreg, val);
break;
}
return 0;
}
static int vreg_debug_get(void *data, u64 *val)
{
struct vreg *vreg = data;
if (!vreg->status)
*val = 0;
else
*val = 1;
return 0;
}
static int vreg_debug_count_set(void *data, u64 val)
{
struct vreg *vreg = data;
if (val > UINT_MAX)
val = UINT_MAX;
vreg->refcnt = val;
return 0;
}
static int vreg_debug_count_get(void *data, u64 *val)
{
struct vreg *vreg = data;
*val = vreg->refcnt;
return 0;
}
static int __init vreg_debug_init(void)
{
struct dentry *dent;
int n;
char name[32];
const char *refcnt_name = "_refcnt";
dent = debugfs_create_dir("vreg", 0);
if (IS_ERR(dent))
return 0;
for (n = 0; n < ARRAY_SIZE(vregs); n++) {
(void) debugfs_create_file(vregs[n].name, 0644,
dent, vregs + n, &vreg_fops);
strlcpy(name, vregs[n].name, sizeof(name));
strlcat(name, refcnt_name, sizeof(name));
(void) debugfs_create_file(name, 0644,
dent, vregs + n, &vreg_count_fops);
}
return 0;
}
