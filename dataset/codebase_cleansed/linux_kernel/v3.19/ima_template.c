static int __init ima_template_setup(char *str)
{
struct ima_template_desc *template_desc;
int template_len = strlen(str);
if (ima_template)
return 1;
template_desc = lookup_template_desc(str);
if (!template_desc) {
pr_err("template %s not found, using %s\n",
str, CONFIG_IMA_DEFAULT_TEMPLATE);
return 1;
}
if (template_len == 3 && strcmp(str, IMA_TEMPLATE_IMA_NAME) == 0 &&
ima_hash_algo != HASH_ALGO_SHA1 && ima_hash_algo != HASH_ALGO_MD5) {
pr_err("template does not support hash alg\n");
return 1;
}
ima_template = template_desc;
return 1;
}
static int __init ima_template_fmt_setup(char *str)
{
int num_templates = ARRAY_SIZE(defined_templates);
if (ima_template)
return 1;
if (template_desc_init_fields(str, NULL, NULL) < 0) {
pr_err("format string '%s' not valid, using template %s\n",
str, CONFIG_IMA_DEFAULT_TEMPLATE);
return 1;
}
defined_templates[num_templates - 1].fmt = str;
ima_template = defined_templates + num_templates - 1;
return 1;
}
static struct ima_template_desc *lookup_template_desc(const char *name)
{
int i;
for (i = 0; i < ARRAY_SIZE(defined_templates); i++) {
if (strcmp(defined_templates[i].name, name) == 0)
return defined_templates + i;
}
return NULL;
}
static struct ima_template_field *lookup_template_field(const char *field_id)
{
int i;
for (i = 0; i < ARRAY_SIZE(supported_fields); i++)
if (strncmp(supported_fields[i].field_id, field_id,
IMA_TEMPLATE_FIELD_ID_MAX_LEN) == 0)
return &supported_fields[i];
return NULL;
}
static int template_fmt_size(const char *template_fmt)
{
char c;
int template_fmt_len = strlen(template_fmt);
int i = 0, j = 0;
while (i < template_fmt_len) {
c = template_fmt[i];
if (c == '|')
j++;
i++;
}
return j + 1;
}
static int template_desc_init_fields(const char *template_fmt,
struct ima_template_field ***fields,
int *num_fields)
{
const char *template_fmt_ptr;
struct ima_template_field *found_fields[IMA_TEMPLATE_NUM_FIELDS_MAX];
int template_num_fields = template_fmt_size(template_fmt);
int i, len;
if (template_num_fields > IMA_TEMPLATE_NUM_FIELDS_MAX) {
pr_err("format string '%s' contains too many fields\n",
template_fmt);
return -EINVAL;
}
for (i = 0, template_fmt_ptr = template_fmt; i < template_num_fields;
i++, template_fmt_ptr += len + 1) {
char tmp_field_id[IMA_TEMPLATE_FIELD_ID_MAX_LEN + 1];
len = strchrnul(template_fmt_ptr, '|') - template_fmt_ptr;
if (len == 0 || len > IMA_TEMPLATE_FIELD_ID_MAX_LEN) {
pr_err("Invalid field with length %d\n", len);
return -EINVAL;
}
memcpy(tmp_field_id, template_fmt_ptr, len);
tmp_field_id[len] = '\0';
found_fields[i] = lookup_template_field(tmp_field_id);
if (!found_fields[i]) {
pr_err("field '%s' not found\n", tmp_field_id);
return -ENOENT;
}
}
if (fields && num_fields) {
*fields = kmalloc_array(i, sizeof(*fields), GFP_KERNEL);
if (*fields == NULL)
return -ENOMEM;
memcpy(*fields, found_fields, i * sizeof(*fields));
*num_fields = i;
}
return 0;
}
struct ima_template_desc *ima_template_desc_current(void)
{
if (!ima_template)
ima_template =
lookup_template_desc(CONFIG_IMA_DEFAULT_TEMPLATE);
return ima_template;
}
int __init ima_init_template(void)
{
struct ima_template_desc *template = ima_template_desc_current();
int result;
result = template_desc_init_fields(template->fmt,
&(template->fields),
&(template->num_fields));
if (result < 0)
pr_err("template %s init failed, result: %d\n",
(strlen(template->name) ?
template->name : template->fmt), result);
return result;
}
