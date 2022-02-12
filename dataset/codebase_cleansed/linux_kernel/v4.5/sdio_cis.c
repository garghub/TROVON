static int cistpl_vers_1(struct mmc_card *card, struct sdio_func *func,
const unsigned char *buf, unsigned size)
{
unsigned i, nr_strings;
char **buffer, *string;
buf += 2;
size -= 2;
nr_strings = 0;
for (i = 0; i < size; i++) {
if (buf[i] == 0xff)
break;
if (buf[i] == 0)
nr_strings++;
}
if (nr_strings == 0)
return 0;
size = i;
buffer = kzalloc(sizeof(char*) * nr_strings + size, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
string = (char*)(buffer + nr_strings);
for (i = 0; i < nr_strings; i++) {
buffer[i] = string;
strcpy(string, buf);
string += strlen(string) + 1;
buf += strlen(buf) + 1;
}
if (func) {
func->num_info = nr_strings;
func->info = (const char**)buffer;
} else {
card->num_info = nr_strings;
card->info = (const char**)buffer;
}
return 0;
}
static int cistpl_manfid(struct mmc_card *card, struct sdio_func *func,
const unsigned char *buf, unsigned size)
{
unsigned int vendor, device;
vendor = buf[0] | (buf[1] << 8);
device = buf[2] | (buf[3] << 8);
if (func) {
func->vendor = vendor;
func->device = device;
} else {
card->cis.vendor = vendor;
card->cis.device = device;
}
return 0;
}
static int cis_tpl_parse(struct mmc_card *card, struct sdio_func *func,
const char *tpl_descr,
const struct cis_tpl *tpl, int tpl_count,
unsigned char code,
const unsigned char *buf, unsigned size)
{
int i, ret;
for (i = 0; i < tpl_count; i++, tpl++) {
if (tpl->code == code)
break;
}
if (i < tpl_count) {
if (size >= tpl->min_size) {
if (tpl->parse)
ret = tpl->parse(card, func, buf, size);
else
ret = -EILSEQ;
} else {
ret = -EINVAL;
}
if (ret && ret != -EILSEQ && ret != -ENOENT) {
pr_err("%s: bad %s tuple 0x%02x (%u bytes)\n",
mmc_hostname(card->host), tpl_descr, code, size);
}
} else {
ret = -ENOENT;
}
return ret;
}
static int cistpl_funce_common(struct mmc_card *card, struct sdio_func *func,
const unsigned char *buf, unsigned size)
{
if (func)
return -EINVAL;
card->cis.blksize = buf[1] | (buf[2] << 8);
card->cis.max_dtr = speed_val[(buf[3] >> 3) & 15] *
speed_unit[buf[3] & 7];
return 0;
}
static int cistpl_funce_func(struct mmc_card *card, struct sdio_func *func,
const unsigned char *buf, unsigned size)
{
unsigned vsn;
unsigned min_size;
if (!func)
return -EINVAL;
vsn = func->card->cccr.sdio_vsn;
min_size = (vsn == SDIO_SDIO_REV_1_00) ? 28 : 42;
if (size < min_size)
return -EINVAL;
func->max_blksize = buf[12] | (buf[13] << 8);
if (vsn > SDIO_SDIO_REV_1_00)
func->enable_timeout = (buf[28] | (buf[29] << 8)) * 10;
else
func->enable_timeout = jiffies_to_msecs(HZ);
return 0;
}
static int cistpl_funce(struct mmc_card *card, struct sdio_func *func,
const unsigned char *buf, unsigned size)
{
if (size < 1)
return -EINVAL;
return cis_tpl_parse(card, func, "CISTPL_FUNCE",
cis_tpl_funce_list,
ARRAY_SIZE(cis_tpl_funce_list),
buf[0], buf, size);
}
static int sdio_read_cis(struct mmc_card *card, struct sdio_func *func)
{
int ret;
struct sdio_func_tuple *this, **prev;
unsigned i, ptr = 0;
for (i = 0; i < 3; i++) {
unsigned char x, fn;
if (func)
fn = func->num;
else
fn = 0;
ret = mmc_io_rw_direct(card, 0, 0,
SDIO_FBR_BASE(fn) + SDIO_FBR_CIS + i, 0, &x);
if (ret)
return ret;
ptr |= x << (i * 8);
}
if (func)
prev = &func->tuples;
else
prev = &card->tuples;
BUG_ON(*prev);
do {
unsigned char tpl_code, tpl_link;
ret = mmc_io_rw_direct(card, 0, 0, ptr++, 0, &tpl_code);
if (ret)
break;
if (tpl_code == 0xff)
break;
if (tpl_code == 0x00)
continue;
ret = mmc_io_rw_direct(card, 0, 0, ptr++, 0, &tpl_link);
if (ret)
break;
if (tpl_link == 0xff)
break;
this = kmalloc(sizeof(*this) + tpl_link, GFP_KERNEL);
if (!this)
return -ENOMEM;
for (i = 0; i < tpl_link; i++) {
ret = mmc_io_rw_direct(card, 0, 0,
ptr + i, 0, &this->data[i]);
if (ret)
break;
}
if (ret) {
kfree(this);
break;
}
ret = cis_tpl_parse(card, func, "CIS",
cis_tpl_list, ARRAY_SIZE(cis_tpl_list),
tpl_code, this->data, tpl_link);
if (ret == -EILSEQ || ret == -ENOENT) {
this->next = NULL;
this->code = tpl_code;
this->size = tpl_link;
*prev = this;
prev = &this->next;
if (ret == -ENOENT) {
pr_warn_ratelimited("%s: queuing unknown"
" CIS tuple 0x%02x (%u bytes)\n",
mmc_hostname(card->host),
tpl_code, tpl_link);
}
ret = 0;
} else {
kfree(this);
}
ptr += tpl_link;
} while (!ret);
if (func)
*prev = card->tuples;
return ret;
}
int sdio_read_common_cis(struct mmc_card *card)
{
return sdio_read_cis(card, NULL);
}
void sdio_free_common_cis(struct mmc_card *card)
{
struct sdio_func_tuple *tuple, *victim;
tuple = card->tuples;
while (tuple) {
victim = tuple;
tuple = tuple->next;
kfree(victim);
}
card->tuples = NULL;
}
int sdio_read_func_cis(struct sdio_func *func)
{
int ret;
ret = sdio_read_cis(func->card, func);
if (ret)
return ret;
get_device(&func->card->dev);
if (func->vendor == 0) {
func->vendor = func->card->cis.vendor;
func->device = func->card->cis.device;
}
return 0;
}
void sdio_free_func_cis(struct sdio_func *func)
{
struct sdio_func_tuple *tuple, *victim;
tuple = func->tuples;
while (tuple && tuple != func->card->tuples) {
victim = tuple;
tuple = tuple->next;
kfree(victim);
}
func->tuples = NULL;
put_device(&func->card->dev);
}
