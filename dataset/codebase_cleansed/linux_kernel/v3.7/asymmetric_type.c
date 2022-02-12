static int asymmetric_key_match(const struct key *key, const void *description)
{
const struct asymmetric_key_subtype *subtype = asymmetric_key_subtype(key);
const char *spec = description;
const char *id, *kid;
ptrdiff_t speclen;
size_t idlen, kidlen;
if (!subtype || !spec || !*spec)
return 0;
if (key->description && strcmp(key->description, description) == 0)
return 1;
id = strchr(spec, ':');
if (!id)
return 0;
speclen = id - spec;
id++;
kid = asymmetric_key_id(key);
if (!kid)
return 0;
idlen = strlen(id);
kidlen = strlen(kid);
if (idlen > kidlen)
return 0;
kid += kidlen - idlen;
if (strcasecmp(id, kid) != 0)
return 0;
if (speclen == 2 &&
memcmp(spec, "id", 2) == 0)
return 1;
if (speclen == subtype->name_len &&
memcmp(spec, subtype->name, speclen) == 0)
return 1;
return 0;
}
static void asymmetric_key_describe(const struct key *key, struct seq_file *m)
{
const struct asymmetric_key_subtype *subtype = asymmetric_key_subtype(key);
const char *kid = asymmetric_key_id(key);
size_t n;
seq_puts(m, key->description);
if (subtype) {
seq_puts(m, ": ");
subtype->describe(key, m);
if (kid) {
seq_putc(m, ' ');
n = strlen(kid);
if (n <= 8)
seq_puts(m, kid);
else
seq_puts(m, kid + n - 8);
}
seq_puts(m, " [");
seq_putc(m, ']');
}
}
static int asymmetric_key_preparse(struct key_preparsed_payload *prep)
{
struct asymmetric_key_parser *parser;
int ret;
pr_devel("==>%s()\n", __func__);
if (prep->datalen == 0)
return -EINVAL;
down_read(&asymmetric_key_parsers_sem);
ret = -EBADMSG;
list_for_each_entry(parser, &asymmetric_key_parsers, link) {
pr_debug("Trying parser '%s'\n", parser->name);
ret = parser->parse(prep);
if (ret != -EBADMSG) {
pr_debug("Parser recognised the format (ret %d)\n",
ret);
break;
}
}
up_read(&asymmetric_key_parsers_sem);
pr_devel("<==%s() = %d\n", __func__, ret);
return ret;
}
static void asymmetric_key_free_preparse(struct key_preparsed_payload *prep)
{
struct asymmetric_key_subtype *subtype = prep->type_data[0];
pr_devel("==>%s()\n", __func__);
if (subtype) {
subtype->destroy(prep->payload);
module_put(subtype->owner);
}
kfree(prep->type_data[1]);
kfree(prep->description);
}
static int asymmetric_key_instantiate(struct key *key, struct key_preparsed_payload *prep)
{
int ret;
pr_devel("==>%s()\n", __func__);
ret = key_payload_reserve(key, prep->quotalen);
if (ret == 0) {
key->type_data.p[0] = prep->type_data[0];
key->type_data.p[1] = prep->type_data[1];
key->payload.data = prep->payload;
prep->type_data[0] = NULL;
prep->type_data[1] = NULL;
prep->payload = NULL;
}
pr_devel("<==%s() = %d\n", __func__, ret);
return ret;
}
static void asymmetric_key_destroy(struct key *key)
{
struct asymmetric_key_subtype *subtype = asymmetric_key_subtype(key);
if (subtype) {
subtype->destroy(key->payload.data);
module_put(subtype->owner);
key->type_data.p[0] = NULL;
}
kfree(key->type_data.p[1]);
key->type_data.p[1] = NULL;
}
int register_asymmetric_key_parser(struct asymmetric_key_parser *parser)
{
struct asymmetric_key_parser *cursor;
int ret;
down_write(&asymmetric_key_parsers_sem);
list_for_each_entry(cursor, &asymmetric_key_parsers, link) {
if (strcmp(cursor->name, parser->name) == 0) {
pr_err("Asymmetric key parser '%s' already registered\n",
parser->name);
ret = -EEXIST;
goto out;
}
}
list_add_tail(&parser->link, &asymmetric_key_parsers);
pr_notice("Asymmetric key parser '%s' registered\n", parser->name);
ret = 0;
out:
up_write(&asymmetric_key_parsers_sem);
return ret;
}
void unregister_asymmetric_key_parser(struct asymmetric_key_parser *parser)
{
down_write(&asymmetric_key_parsers_sem);
list_del(&parser->link);
up_write(&asymmetric_key_parsers_sem);
pr_notice("Asymmetric key parser '%s' unregistered\n", parser->name);
}
static int __init asymmetric_key_init(void)
{
return register_key_type(&key_type_asymmetric);
}
static void __exit asymmetric_key_cleanup(void)
{
unregister_key_type(&key_type_asymmetric);
}
