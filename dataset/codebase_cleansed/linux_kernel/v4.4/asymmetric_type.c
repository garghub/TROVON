struct asymmetric_key_id *asymmetric_key_generate_id(const void *val_1,
size_t len_1,
const void *val_2,
size_t len_2)
{
struct asymmetric_key_id *kid;
kid = kmalloc(sizeof(struct asymmetric_key_id) + len_1 + len_2,
GFP_KERNEL);
if (!kid)
return ERR_PTR(-ENOMEM);
kid->len = len_1 + len_2;
memcpy(kid->data, val_1, len_1);
memcpy(kid->data + len_1, val_2, len_2);
return kid;
}
bool asymmetric_key_id_same(const struct asymmetric_key_id *kid1,
const struct asymmetric_key_id *kid2)
{
if (!kid1 || !kid2)
return false;
if (kid1->len != kid2->len)
return false;
return memcmp(kid1->data, kid2->data, kid1->len) == 0;
}
bool asymmetric_key_id_partial(const struct asymmetric_key_id *kid1,
const struct asymmetric_key_id *kid2)
{
if (!kid1 || !kid2)
return false;
if (kid1->len < kid2->len)
return false;
return memcmp(kid1->data + (kid1->len - kid2->len),
kid2->data, kid2->len) == 0;
}
static bool asymmetric_match_key_ids(
const struct asymmetric_key_ids *kids,
const struct asymmetric_key_id *match_id,
bool (*match)(const struct asymmetric_key_id *kid1,
const struct asymmetric_key_id *kid2))
{
int i;
if (!kids || !match_id)
return false;
for (i = 0; i < ARRAY_SIZE(kids->id); i++)
if (match(kids->id[i], match_id))
return true;
return false;
}
inline int __asymmetric_key_hex_to_key_id(const char *id,
struct asymmetric_key_id *match_id,
size_t hexlen)
{
match_id->len = hexlen;
return hex2bin(match_id->data, id, hexlen);
}
struct asymmetric_key_id *asymmetric_key_hex_to_key_id(const char *id)
{
struct asymmetric_key_id *match_id;
size_t asciihexlen;
int ret;
if (!*id)
return ERR_PTR(-EINVAL);
asciihexlen = strlen(id);
if (asciihexlen & 1)
return ERR_PTR(-EINVAL);
match_id = kmalloc(sizeof(struct asymmetric_key_id) + asciihexlen / 2,
GFP_KERNEL);
if (!match_id)
return ERR_PTR(-ENOMEM);
ret = __asymmetric_key_hex_to_key_id(id, match_id, asciihexlen / 2);
if (ret < 0) {
kfree(match_id);
return ERR_PTR(-EINVAL);
}
return match_id;
}
static bool asymmetric_key_cmp(const struct key *key,
const struct key_match_data *match_data)
{
const struct asymmetric_key_ids *kids = asymmetric_key_ids(key);
const struct asymmetric_key_id *match_id = match_data->preparsed;
return asymmetric_match_key_ids(kids, match_id,
asymmetric_key_id_same);
}
static bool asymmetric_key_cmp_partial(const struct key *key,
const struct key_match_data *match_data)
{
const struct asymmetric_key_ids *kids = asymmetric_key_ids(key);
const struct asymmetric_key_id *match_id = match_data->preparsed;
return asymmetric_match_key_ids(kids, match_id,
asymmetric_key_id_partial);
}
static int asymmetric_key_match_preparse(struct key_match_data *match_data)
{
struct asymmetric_key_id *match_id;
const char *spec = match_data->raw_data;
const char *id;
bool (*cmp)(const struct key *, const struct key_match_data *) =
asymmetric_key_cmp;
if (!spec || !*spec)
return -EINVAL;
if (spec[0] == 'i' &&
spec[1] == 'd' &&
spec[2] == ':') {
id = spec + 3;
cmp = asymmetric_key_cmp_partial;
} else if (spec[0] == 'e' &&
spec[1] == 'x' &&
spec[2] == ':') {
id = spec + 3;
} else {
goto default_match;
}
match_id = asymmetric_key_hex_to_key_id(id);
if (IS_ERR(match_id))
return PTR_ERR(match_id);
match_data->preparsed = match_id;
match_data->cmp = cmp;
match_data->lookup_type = KEYRING_SEARCH_LOOKUP_ITERATE;
return 0;
default_match:
return 0;
}
static void asymmetric_key_match_free(struct key_match_data *match_data)
{
kfree(match_data->preparsed);
}
static void asymmetric_key_describe(const struct key *key, struct seq_file *m)
{
const struct asymmetric_key_subtype *subtype = asymmetric_key_subtype(key);
const struct asymmetric_key_ids *kids = asymmetric_key_ids(key);
const struct asymmetric_key_id *kid;
const unsigned char *p;
int n;
seq_puts(m, key->description);
if (subtype) {
seq_puts(m, ": ");
subtype->describe(key, m);
if (kids && kids->id[1]) {
kid = kids->id[1];
seq_putc(m, ' ');
n = kid->len;
p = kid->data;
if (n > 4) {
p += n - 4;
n = 4;
}
seq_printf(m, "%*phN", n, p);
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
static void asymmetric_key_free_kids(struct asymmetric_key_ids *kids)
{
int i;
if (kids) {
for (i = 0; i < ARRAY_SIZE(kids->id); i++)
kfree(kids->id[i]);
kfree(kids);
}
}
static void asymmetric_key_free_preparse(struct key_preparsed_payload *prep)
{
struct asymmetric_key_subtype *subtype = prep->payload.data[asym_subtype];
struct asymmetric_key_ids *kids = prep->payload.data[asym_key_ids];
pr_devel("==>%s()\n", __func__);
if (subtype) {
subtype->destroy(prep->payload.data[asym_crypto]);
module_put(subtype->owner);
}
asymmetric_key_free_kids(kids);
kfree(prep->description);
}
static void asymmetric_key_destroy(struct key *key)
{
struct asymmetric_key_subtype *subtype = asymmetric_key_subtype(key);
struct asymmetric_key_ids *kids = key->payload.data[asym_key_ids];
void *data = key->payload.data[asym_crypto];
key->payload.data[asym_crypto] = NULL;
key->payload.data[asym_subtype] = NULL;
key->payload.data[asym_key_ids] = NULL;
if (subtype) {
subtype->destroy(data);
module_put(subtype->owner);
}
asymmetric_key_free_kids(kids);
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
