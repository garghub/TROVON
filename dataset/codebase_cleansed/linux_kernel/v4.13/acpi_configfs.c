static ssize_t acpi_table_aml_write(struct config_item *cfg,
const void *data, size_t size)
{
const struct acpi_table_header *header = data;
struct acpi_table *table;
int ret;
table = container_of(cfg, struct acpi_table, cfg);
if (table->header) {
pr_err("table already loaded\n");
return -EBUSY;
}
if (header->length != size) {
pr_err("invalid table length\n");
return -EINVAL;
}
if (memcmp(header->signature, ACPI_SIG_SSDT, 4)) {
pr_err("invalid table signature\n");
return -EINVAL;
}
table = container_of(cfg, struct acpi_table, cfg);
table->header = kmemdup(header, header->length, GFP_KERNEL);
if (!table->header)
return -ENOMEM;
ACPI_INFO(("Host-directed Dynamic ACPI Table Load:"));
ret = acpi_tb_install_and_load_table(
ACPI_PTR_TO_PHYSADDR(table->header),
ACPI_TABLE_ORIGIN_EXTERNAL_VIRTUAL, FALSE,
&table->index);
if (ret) {
kfree(table->header);
table->header = NULL;
}
return ret;
}
static inline struct acpi_table_header *get_header(struct config_item *cfg)
{
struct acpi_table *table = container_of(cfg, struct acpi_table, cfg);
if (!table->header)
pr_err("table not loaded\n");
return table->header;
}
static ssize_t acpi_table_aml_read(struct config_item *cfg,
void *data, size_t size)
{
struct acpi_table_header *h = get_header(cfg);
if (!h)
return -EINVAL;
if (data)
memcpy(data, h, h->length);
return h->length;
}
ssize_t acpi_table_signature_show(struct config_item *cfg, char *str)
{
struct acpi_table_header *h = get_header(cfg);
if (!h)
return -EINVAL;
return sprintf(str, "%.*s\n", ACPI_NAME_SIZE, h->signature);
}
ssize_t acpi_table_length_show(struct config_item *cfg, char *str)
{
struct acpi_table_header *h = get_header(cfg);
if (!h)
return -EINVAL;
return sprintf(str, "%d\n", h->length);
}
ssize_t acpi_table_revision_show(struct config_item *cfg, char *str)
{
struct acpi_table_header *h = get_header(cfg);
if (!h)
return -EINVAL;
return sprintf(str, "%d\n", h->revision);
}
ssize_t acpi_table_oem_id_show(struct config_item *cfg, char *str)
{
struct acpi_table_header *h = get_header(cfg);
if (!h)
return -EINVAL;
return sprintf(str, "%.*s\n", ACPI_OEM_ID_SIZE, h->oem_id);
}
ssize_t acpi_table_oem_table_id_show(struct config_item *cfg, char *str)
{
struct acpi_table_header *h = get_header(cfg);
if (!h)
return -EINVAL;
return sprintf(str, "%.*s\n", ACPI_OEM_TABLE_ID_SIZE, h->oem_table_id);
}
ssize_t acpi_table_oem_revision_show(struct config_item *cfg, char *str)
{
struct acpi_table_header *h = get_header(cfg);
if (!h)
return -EINVAL;
return sprintf(str, "%d\n", h->oem_revision);
}
ssize_t acpi_table_asl_compiler_id_show(struct config_item *cfg, char *str)
{
struct acpi_table_header *h = get_header(cfg);
if (!h)
return -EINVAL;
return sprintf(str, "%.*s\n", ACPI_NAME_SIZE, h->asl_compiler_id);
}
ssize_t acpi_table_asl_compiler_revision_show(struct config_item *cfg,
char *str)
{
struct acpi_table_header *h = get_header(cfg);
if (!h)
return -EINVAL;
return sprintf(str, "%d\n", h->asl_compiler_revision);
}
static struct config_item *acpi_table_make_item(struct config_group *group,
const char *name)
{
struct acpi_table *table;
table = kzalloc(sizeof(*table), GFP_KERNEL);
if (!table)
return ERR_PTR(-ENOMEM);
config_item_init_type_name(&table->cfg, name, &acpi_table_type);
return &table->cfg;
}
static void acpi_table_drop_item(struct config_group *group,
struct config_item *cfg)
{
struct acpi_table *table = container_of(cfg, struct acpi_table, cfg);
ACPI_INFO(("Host-directed Dynamic ACPI Table Unload"));
acpi_tb_unload_table(table->index);
}
static int __init acpi_configfs_init(void)
{
int ret;
struct config_group *root = &acpi_configfs.su_group;
config_group_init(root);
ret = configfs_register_subsystem(&acpi_configfs);
if (ret)
return ret;
acpi_table_group = configfs_register_default_group(root, "table",
&acpi_tables_type);
return PTR_ERR_OR_ZERO(acpi_table_group);
}
static void __exit acpi_configfs_exit(void)
{
configfs_unregister_default_group(acpi_table_group);
configfs_unregister_subsystem(&acpi_configfs);
}
