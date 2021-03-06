static ssize_t chars_chartab_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
int i;
int len = 0;
char *cp;
char *buf_pointer = buf;
size_t bufsize = PAGE_SIZE;
unsigned long flags;
spk_lock(flags);
*buf_pointer = '\0';
for (i = 0; i < 256; i++) {
if (bufsize <= 1)
break;
if (strcmp("characters", attr->attr.name) == 0) {
len = scnprintf(buf_pointer, bufsize, "%d\t%s\n",
i, characters[i]);
} else {
if (IS_TYPE(i, B_CTL))
cp = "B_CTL";
else if (IS_TYPE(i, WDLM))
cp = "WDLM";
else if (IS_TYPE(i, A_PUNC))
cp = "A_PUNC";
else if (IS_TYPE(i, PUNC))
cp = "PUNC";
else if (IS_TYPE(i, NUM))
cp = "NUM";
else if (IS_TYPE(i, A_CAP))
cp = "A_CAP";
else if (IS_TYPE(i, ALPHA))
cp = "ALPHA";
else if (IS_TYPE(i, B_CAPSYM))
cp = "B_CAPSYM";
else if (IS_TYPE(i, B_SYM))
cp = "B_SYM";
else
cp = "0";
len =
scnprintf(buf_pointer, bufsize, "%d\t%s\n", i, cp);
}
bufsize -= len;
buf_pointer += len;
}
spk_unlock(flags);
return buf_pointer - buf;
}
static void report_char_chartab_status(int reset, int received, int used,
int rejected, int do_characters)
{
char *object_type[] = {
"character class entries",
"character descriptions",
};
int len;
char buf[80];
if (reset) {
pr_info("%s reset to defaults\n", object_type[do_characters]);
} else if (received) {
len = snprintf(buf, sizeof(buf),
" updated %d of %d %s\n",
used, received, object_type[do_characters]);
if (rejected)
snprintf(buf + (len - 1), sizeof(buf) - (len - 1),
" with %d reject%s\n",
rejected, rejected > 1 ? "s" : "");
printk(buf);
}
}
static ssize_t chars_chartab_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t count)
{
char *cp = (char *) buf;
char *end = cp + count;
char *linefeed = NULL;
char keyword[MAX_DESC_LEN + 1];
char *outptr = NULL;
char *temp = NULL;
char *desc = NULL;
ssize_t retval = count;
unsigned long flags;
unsigned long index = 0;
int charclass = 0;
int received = 0;
int used = 0;
int rejected = 0;
int reset = 0;
int do_characters = !strcmp(attr->attr.name, "characters");
size_t desc_length = 0;
int i;
spk_lock(flags);
while (cp < end) {
while ((cp < end) && (*cp == ' ' || *cp == '\t'))
cp++;
if (cp == end)
break;
if ((*cp == '\n') || strchr("dDrR", *cp)) {
reset = 1;
break;
}
received++;
linefeed = strchr(cp, '\n');
if (!linefeed) {
rejected++;
break;
}
if (!isdigit(*cp)) {
rejected++;
cp = linefeed + 1;
continue;
}
index = simple_strtoul(cp, &temp, 10);
if (index > 255) {
rejected++;
cp = linefeed + 1;
continue;
}
while ((temp < linefeed) && (*temp == ' ' || *temp == '\t'))
temp++;
desc_length = linefeed - temp;
if (desc_length > MAX_DESC_LEN) {
rejected++;
cp = linefeed + 1;
continue;
}
if (do_characters) {
desc = kmalloc(desc_length + 1, GFP_ATOMIC);
if (!desc) {
retval = -ENOMEM;
reset = 1;
break;
}
outptr = desc;
} else {
outptr = keyword;
}
for (i = 0; i < desc_length; i++)
outptr[i] = temp[i];
outptr[desc_length] = '\0';
if (do_characters) {
if (characters[index] != default_chars[index])
kfree(characters[index]);
characters[index] = desc;
used++;
} else {
charclass = chartab_get_value(keyword);
if (charclass == 0) {
rejected++;
cp = linefeed + 1;
continue;
}
if (charclass != spk_chartab[index]) {
spk_chartab[index] = charclass;
used++;
}
}
cp = linefeed + 1;
}
if (reset) {
if (do_characters)
reset_default_chars();
else
reset_default_chartab();
}
spk_unlock(flags);
report_char_chartab_status(reset, received, used, rejected,
do_characters);
return retval;
}
static ssize_t keymap_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
char *cp = buf;
int i;
int n;
int num_keys;
int nstates;
u_char *cp1;
u_char ch;
unsigned long flags;
spk_lock(flags);
cp1 = key_buf + SHIFT_TBL_SIZE;
num_keys = (int)(*cp1);
nstates = (int)cp1[1];
cp += sprintf(cp, "%d, %d, %d,\n", KEY_MAP_VER, num_keys, nstates);
cp1 += 2;
for (n = 0; n <= num_keys; n++) {
for (i = 0; i <= nstates; i++) {
ch = *cp1++;
cp += sprintf(cp, "%d,", (int)ch);
*cp++ = (i < nstates) ? SPACE : '\n';
}
}
cp += sprintf(cp, "0, %d\n", KEY_MAP_VER);
spk_unlock(flags);
return (int)(cp-buf);
}
static ssize_t keymap_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t count)
{
int i;
ssize_t ret = count;
char *in_buff = NULL;
char *cp;
u_char *cp1;
unsigned long flags;
spk_lock(flags);
in_buff = kmemdup(buf, count + 1, GFP_ATOMIC);
if (!in_buff) {
spk_unlock(flags);
return -ENOMEM;
}
if (strchr("dDrR", *in_buff)) {
set_key_info(key_defaults, key_buf);
pr_info("keymap set to default values\n");
kfree(in_buff);
spk_unlock(flags);
return count;
}
if (in_buff[count - 1] == '\n')
in_buff[count - 1] = '\0';
cp = in_buff;
cp1 = (u_char *)in_buff;
for (i = 0; i < 3; i++) {
cp = s2uchar(cp, cp1);
cp1++;
}
i = (int)cp1[-2]+1;
i *= (int)cp1[-1]+1;
i += 2;
if (cp1[-3] != KEY_MAP_VER || cp1[-1] > 10 ||
i+SHIFT_TBL_SIZE+4 >= sizeof(key_buf)) {
pr_warn("i %d %d %d %d\n", i,
(int)cp1[-3], (int)cp1[-2], (int)cp1[-1]);
kfree(in_buff);
spk_unlock(flags);
return -EINVAL;
}
while (--i >= 0) {
cp = s2uchar(cp, cp1);
cp1++;
if (!(*cp))
break;
}
if (i != 0 || cp1[-1] != KEY_MAP_VER || cp1[-2] != 0) {
ret = -EINVAL;
pr_warn("end %d %d %d %d\n", i,
(int)cp1[-3], (int)cp1[-2], (int)cp1[-1]);
} else {
if (set_key_info(in_buff, key_buf)) {
set_key_info(key_defaults, key_buf);
ret = -EINVAL;
pr_warn("set key failed\n");
}
}
kfree(in_buff);
spk_unlock(flags);
return ret;
}
static ssize_t silent_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t count)
{
int len;
struct vc_data *vc = vc_cons[fg_console].d;
char ch = 0;
char shut;
unsigned long flags;
len = strlen(buf);
if (len > 0 && len < 3) {
ch = buf[0];
if (ch == '\n')
ch = '0';
}
if (ch < '0' || ch > '7') {
pr_warn("silent value '%c' not in range (0,7)\n", ch);
return -EINVAL;
}
spk_lock(flags);
if (ch&2) {
shut = 1;
do_flush();
} else {
shut = 0;
}
if (ch&4)
shut |= 0x40;
if (ch&1)
spk_shut_up |= shut;
else
spk_shut_up &= ~shut;
spk_unlock(flags);
return count;
}
static ssize_t synth_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
int rv;
if (synth == NULL)
rv = sprintf(buf, "%s\n", "none");
else
rv = sprintf(buf, "%s\n", synth->name);
return rv;
}
static ssize_t synth_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t count)
{
int len;
char new_synth_name[10];
len = strlen(buf);
if (len < 2 || len > 9)
return -EINVAL;
strncpy(new_synth_name, buf, len);
if (new_synth_name[len - 1] == '\n')
len--;
new_synth_name[len] = '\0';
strlwr(new_synth_name);
if ((synth != NULL) && (!strcmp(new_synth_name, synth->name))) {
pr_warn("%s already in use\n", new_synth_name);
} else if (synth_init(new_synth_name) != 0) {
pr_warn("failed to init synth %s\n", new_synth_name);
return -ENODEV;
}
return count;
}
static ssize_t synth_direct_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t count)
{
u_char tmp[256];
int len;
int bytes;
const char *ptr = buf;
if (!synth)
return -EPERM;
len = strlen(buf);
while (len > 0) {
bytes = min_t(size_t, len, 250);
strncpy(tmp, ptr, bytes);
tmp[bytes] = '\0';
xlate(tmp);
synth_printf("%s", tmp);
ptr += bytes;
len -= bytes;
}
return count;
}
static ssize_t version_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
char *cp;
cp = buf;
cp += sprintf(cp, "Speakup version %s\n", SPEAKUP_VERSION);
if (synth)
cp += sprintf(cp, "%s synthesizer driver version %s\n",
synth->name, synth->version);
return cp - buf;
}
static ssize_t punc_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
int i;
char *cp = buf;
struct st_var_header *p_header;
struct punc_var_t *var;
struct st_bits_data *pb;
short mask;
unsigned long flags;
p_header = var_header_by_name(attr->attr.name);
if (p_header == NULL) {
pr_warn("p_header is null, attr->attr.name is %s\n",
attr->attr.name);
return -EINVAL;
}
var = get_punc_var(p_header->var_id);
if (var == NULL) {
pr_warn("var is null, p_header->var_id is %i\n",
p_header->var_id);
return -EINVAL;
}
spk_lock(flags);
pb = (struct st_bits_data *) &punc_info[var->value];
mask = pb->mask;
for (i = 33; i < 128; i++) {
if (!(spk_chartab[i]&mask))
continue;
*cp++ = (char)i;
}
spk_unlock(flags);
return cp-buf;
}
static ssize_t punc_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t count)
{
int x;
struct st_var_header *p_header;
struct punc_var_t *var;
char punc_buf[100];
unsigned long flags;
x = strlen(buf);
if (x < 1 || x > 99)
return -EINVAL;
p_header = var_header_by_name(attr->attr.name);
if (p_header == NULL) {
pr_warn("p_header is null, attr->attr.name is %s\n",
attr->attr.name);
return -EINVAL;
}
var = get_punc_var(p_header->var_id);
if (var == NULL) {
pr_warn("var is null, p_header->var_id is %i\n",
p_header->var_id);
return -EINVAL;
}
strncpy(punc_buf, buf, x);
while (x && punc_buf[x - 1] == '\n')
x--;
punc_buf[x] = '\0';
spk_lock(flags);
if (*punc_buf == 'd' || *punc_buf == 'r')
x = set_mask_bits(0, var->value, 3);
else
x = set_mask_bits(punc_buf, var->value, 3);
spk_unlock(flags);
return count;
}
ssize_t spk_var_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
int rv = 0;
struct st_var_header *param;
struct var_t *var;
char *cp1;
char *cp;
char ch;
unsigned long flags;
param = var_header_by_name(attr->attr.name);
if (param == NULL)
return -EINVAL;
spk_lock(flags);
var = (struct var_t *) param->data;
switch (param->var_type) {
case VAR_NUM:
case VAR_TIME:
if (var)
rv = sprintf(buf, "%i\n", var->u.n.value);
else
rv = sprintf(buf, "0\n");
break;
case VAR_STRING:
if (var) {
cp1 = buf;
*cp1++ = '"';
for (cp = (char *)param->p_val; (ch = *cp); cp++) {
if (ch >= ' ' && ch < '~')
*cp1++ = ch;
else
cp1 += sprintf(cp1, "\\""x%02x", ch);
}
*cp1++ = '"';
*cp1++ = '\n';
*cp1 = '\0';
rv = cp1-buf;
} else {
rv = sprintf(buf, "\"\"\n");
}
break;
default:
rv = sprintf(buf, "Bad parameter %s, type %i\n",
param->name, param->var_type);
break;
}
spk_unlock(flags);
return rv;
}
EXPORT_SYMBOL_GPL(spk_var_show);
/*
* This function is called when a user echos a value to one of the
* variable parameters.
*/
ssize_t spk_var_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t count)
{
struct st_var_header *param;
int ret;
int len;
char *cp;
struct var_t *var_data;
int value;
unsigned long flags;
param = var_header_by_name(attr->attr.name);
if (param == NULL)
return -EINVAL;
if (param->data == NULL)
return 0;
ret = 0;
cp = xlate((char *) buf);
spk_lock(flags);
switch (param->var_type) {
case VAR_NUM:
case VAR_TIME:
if (*cp == 'd' || *cp == 'r' || *cp == '\0')
len = E_DEFAULT;
else if (*cp == '+' || *cp == '-')
len = E_INC;
else
len = E_SET;
speakup_s2i(cp, &value);
ret = set_num_var(value, param, len);
if (ret == E_RANGE) {
var_data = param->data;
pr_warn("value for %s out of range, expect %d to %d\n",
attr->attr.name,
var_data->u.n.low, var_data->u.n.high);
}
break;
case VAR_STRING:
len = strlen(buf);
if ((len >= 1) && (buf[len - 1] == '\n'))
--len;
if ((len >= 2) && (buf[0] == '"') && (buf[len - 1] == '"')) {
++buf;
len -= 2;
}
cp = (char *) buf;
cp[len] = '\0';
ret = set_string_var(buf, param, len);
if (ret == E_TOOLONG)
pr_warn("value too long for %s\n",
attr->attr.name);
break;
default:
pr_warn("%s unknown type %d\n",
param->name, (int)param->var_type);
break;
}
/*
* If voice was just changed, we might need to reset our default
* pitch and volume.
*/
if (strcmp(attr->attr.name, "voice") == 0) {
if (synth && synth->default_pitch) {
param = var_header_by_name("pitch");
if (param) {
set_num_var(synth->default_pitch[value], param,
E_NEW_DEFAULT);
set_num_var(0, param, E_DEFAULT);
}
}
if (synth && synth->default_vol) {
param = var_header_by_name("vol");
if (param) {
set_num_var(synth->default_vol[value], param,
E_NEW_DEFAULT);
set_num_var(0, param, E_DEFAULT);
}
}
}
spk_unlock(flags);
if (ret == SET_DEFAULT)
pr_info("%s reset to default value\n", attr->attr.name);
return count;
}
EXPORT_SYMBOL_GPL(spk_var_store);
/*
* Functions for reading and writing lists of i18n messages. Incomplete.
*/
static ssize_t message_show_helper(char *buf, enum msg_index_t first,
enum msg_index_t last)
{
size_t bufsize = PAGE_SIZE;
char *buf_pointer = buf;
int printed;
enum msg_index_t cursor;
int index = 0;
*buf_pointer = '\0'; /* buf_pointer always looking at a NUL byte. */
for (cursor = first; cursor <= last; cursor++, index++) {
if (bufsize <= 1)
break;
printed = scnprintf(buf_pointer, bufsize, "%d\t%s\n",
index, msg_get(cursor));
buf_pointer += printed;
bufsize -= printed;
}
return buf_pointer - buf;
}
static void report_msg_status(int reset, int received, int used,
int rejected, char *groupname)
{
int len;
char buf[160];
if (reset) {
pr_info("i18n messages from group %s reset to defaults\n",
groupname);
} else if (received) {
len = snprintf(buf, sizeof(buf),
" updated %d of %d i18n messages from group %s\n",
used, received, groupname);
if (rejected)
snprintf(buf + (len - 1), sizeof(buf) - (len - 1),
" with %d reject%s\n",
rejected, rejected > 1 ? "s" : "");
printk(buf);
}
}
static ssize_t message_store_helper(const char *buf, size_t count,
struct msg_group_t *group)
{
char *cp = (char *) buf;
char *end = cp + count;
char *linefeed = NULL;
char *temp = NULL;
ssize_t msg_stored = 0;
ssize_t retval = count;
size_t desc_length = 0;
unsigned long index = 0;
int received = 0;
int used = 0;
int rejected = 0;
int reset = 0;
enum msg_index_t firstmessage = group->start;
enum msg_index_t lastmessage = group->end;
enum msg_index_t curmessage;
while (cp < end) {
while ((cp < end) && (*cp == ' ' || *cp == '\t'))
cp++;
if (cp == end)
break;
if (strchr("dDrR", *cp)) {
reset = 1;
break;
}
received++;
linefeed = strchr(cp, '\n');
if (!linefeed) {
rejected++;
break;
}
if (!isdigit(*cp)) {
rejected++;
cp = linefeed + 1;
continue;
}
index = simple_strtoul(cp, &temp, 10);
while ((temp < linefeed) && (*temp == ' ' || *temp == '\t'
