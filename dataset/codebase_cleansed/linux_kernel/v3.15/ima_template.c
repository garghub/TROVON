static int __init ima_template_setup(char *str)
{
struct ima_template_desc *template_desc;
int template_len = strlen(str);
template_desc = lookup_template_desc(str);
if (!template_desc)
return 1;
if (template_len == 3 && strcmp(str, IMA_TEMPLATE_IMA_NAME) == 0 &&
ima_hash_algo != HASH_ALGO_SHA1 && ima_hash_algo != HASH_ALGO_MD5) {
pr_err("template does not support hash alg\n");
return 1;
}
ima_template = template_desc;
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
char *c, *template_fmt_copy, *template_fmt_ptr;
int template_num_fields = template_fmt_size(template_fmt);
int i, result = 0;
if (template_num_fields > IMA_TEMPLATE_NUM_FIELDS_MAX)
return -EINVAL;
template_fmt_copy = kstrdup(template_fmt, GFP_KERNEL);
if (template_fmt_copy == NULL)
return -ENOMEM;
*fields = kzalloc(template_num_fields * sizeof(*fields), GFP_KERNEL);
if (*fields == NULL) {
result = -ENOMEM;
goto out;
}
template_fmt_ptr = template_fmt_copy;
for (i = 0; (c = strsep(&template_fmt_ptr, "|")) != NULL &&
i < template_num_fields; i++) {
struct ima_template_field *f = lookup_template_field(c);
if (!f) {
result = -ENOENT;
goto out;
}
(*fields)[i] = f;
}
*num_fields = i;
out:
if (result < 0) {
kfree(*fields);
*fields = NULL;
}
kfree(template_fmt_copy);
return result;
}
static int init_defined_templates(void)
{
int i = 0;
int result = 0;
for (i = 0; i < ARRAY_SIZE(defined_templates); i++) {
struct ima_template_desc *template = &defined_templates[i];
result = template_desc_init_fields(template->fmt,
&(template->fields),
&(template->num_fields));
if (result < 0)
return result;
}
return result;
}
struct ima_template_desc *ima_template_desc_current(void)
{
if (!ima_template)
ima_template =
lookup_template_desc(CONFIG_IMA_DEFAULT_TEMPLATE);
return ima_template;
}
int ima_init_template(void)
{
int result;
result = init_defined_templates();
if (result < 0)
return result;
return 0;
}
