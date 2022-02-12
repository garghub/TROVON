static inline int deg(unsigned int poly)
{
return fls(poly) - 1;
}
static int atmel_pmecc_build_gf_tables(int mm, unsigned int poly,
struct atmel_pmecc_gf_tables *gf_tables)
{
unsigned int i, x = 1;
const unsigned int k = BIT(deg(poly));
unsigned int nn = BIT(mm) - 1;
if (k != (1u << mm))
return -EINVAL;
for (i = 0; i < nn; i++) {
gf_tables->alpha_to[i] = x;
gf_tables->index_of[x] = i;
if (i && (x == 1))
return -EINVAL;
x <<= 1;
if (x & k)
x ^= poly;
}
gf_tables->alpha_to[nn] = 1;
gf_tables->index_of[0] = 0;
return 0;
}
static const struct atmel_pmecc_gf_tables *
atmel_pmecc_create_gf_tables(const struct atmel_pmecc_user_req *req)
{
struct atmel_pmecc_gf_tables *gf_tables;
unsigned int poly, degree, table_size;
int ret;
if (req->ecc.sectorsize == 512) {
degree = PMECC_GF_DIMENSION_13;
poly = PMECC_GF_13_PRIMITIVE_POLY;
table_size = PMECC_LOOKUP_TABLE_SIZE_512;
} else {
degree = PMECC_GF_DIMENSION_14;
poly = PMECC_GF_14_PRIMITIVE_POLY;
table_size = PMECC_LOOKUP_TABLE_SIZE_1024;
}
gf_tables = kzalloc(sizeof(*gf_tables) +
(2 * table_size * sizeof(u16)),
GFP_KERNEL);
if (!gf_tables)
return ERR_PTR(-ENOMEM);
gf_tables->alpha_to = (void *)(gf_tables + 1);
gf_tables->index_of = gf_tables->alpha_to + table_size;
ret = atmel_pmecc_build_gf_tables(degree, poly, gf_tables);
if (ret) {
kfree(gf_tables);
return ERR_PTR(ret);
}
return gf_tables;
}
static const struct atmel_pmecc_gf_tables *
atmel_pmecc_get_gf_tables(const struct atmel_pmecc_user_req *req)
{
const struct atmel_pmecc_gf_tables **gf_tables, *ret;
mutex_lock(&pmecc_gf_tables_lock);
if (req->ecc.sectorsize == 512)
gf_tables = &pmecc_gf_tables_512;
else
gf_tables = &pmecc_gf_tables_1024;
ret = *gf_tables;
if (!ret) {
ret = atmel_pmecc_create_gf_tables(req);
if (!IS_ERR(ret))
*gf_tables = ret;
}
mutex_unlock(&pmecc_gf_tables_lock);
return ret;
}
static int atmel_pmecc_prepare_user_req(struct atmel_pmecc *pmecc,
struct atmel_pmecc_user_req *req)
{
int i, max_eccbytes, eccbytes = 0, eccstrength = 0;
if (req->pagesize <= 0 || req->oobsize <= 0 || req->ecc.bytes <= 0)
return -EINVAL;
if (req->ecc.ooboffset >= 0 &&
req->ecc.ooboffset + req->ecc.bytes > req->oobsize)
return -EINVAL;
if (req->ecc.sectorsize == ATMEL_PMECC_SECTOR_SIZE_AUTO) {
if (req->ecc.strength != ATMEL_PMECC_MAXIMIZE_ECC_STRENGTH)
return -EINVAL;
if (req->pagesize > 512)
req->ecc.sectorsize = 1024;
else
req->ecc.sectorsize = 512;
}
if (req->ecc.sectorsize != 512 && req->ecc.sectorsize != 1024)
return -EINVAL;
if (req->pagesize % req->ecc.sectorsize)
return -EINVAL;
req->ecc.nsectors = req->pagesize / req->ecc.sectorsize;
max_eccbytes = req->ecc.bytes;
for (i = 0; i < pmecc->caps->nstrengths; i++) {
int nbytes, strength = pmecc->caps->strengths[i];
if (req->ecc.strength != ATMEL_PMECC_MAXIMIZE_ECC_STRENGTH &&
strength < req->ecc.strength)
continue;
nbytes = DIV_ROUND_UP(strength * fls(8 * req->ecc.sectorsize),
8);
nbytes *= req->ecc.nsectors;
if (nbytes > max_eccbytes)
break;
eccstrength = strength;
eccbytes = nbytes;
if (req->ecc.strength != ATMEL_PMECC_MAXIMIZE_ECC_STRENGTH)
break;
}
if (!eccstrength)
return -EINVAL;
req->ecc.bytes = eccbytes;
req->ecc.strength = eccstrength;
if (req->ecc.ooboffset < 0)
req->ecc.ooboffset = req->oobsize - eccbytes;
return 0;
}
struct atmel_pmecc_user *
atmel_pmecc_create_user(struct atmel_pmecc *pmecc,
struct atmel_pmecc_user_req *req)
{
struct atmel_pmecc_user *user;
const struct atmel_pmecc_gf_tables *gf_tables;
int strength, size, ret;
ret = atmel_pmecc_prepare_user_req(pmecc, req);
if (ret)
return ERR_PTR(ret);
size = sizeof(*user);
size = ALIGN(size, sizeof(u16));
size += ((2 * req->ecc.strength) + 1) * sizeof(u16) *
(2 + req->ecc.strength + 2);
size += (req->ecc.strength + 1) * sizeof(u16);
size = ALIGN(size, sizeof(s32));
size += (req->ecc.strength + 1) * sizeof(s32);
user = kzalloc(size, GFP_KERNEL);
if (!user)
return ERR_PTR(-ENOMEM);
user->pmecc = pmecc;
user->partial_syn = (s16 *)PTR_ALIGN(user + 1, sizeof(u16));
user->si = user->partial_syn + ((2 * req->ecc.strength) + 1);
user->lmu = user->si + ((2 * req->ecc.strength) + 1);
user->smu = user->lmu + (req->ecc.strength + 1);
user->mu = (s32 *)PTR_ALIGN(user->smu +
(((2 * req->ecc.strength) + 1) *
(req->ecc.strength + 2)),
sizeof(s32));
user->dmu = user->mu + req->ecc.strength + 1;
user->delta = user->dmu + req->ecc.strength + 1;
gf_tables = atmel_pmecc_get_gf_tables(req);
if (IS_ERR(gf_tables)) {
kfree(user);
return ERR_CAST(gf_tables);
}
user->gf_tables = gf_tables;
user->eccbytes = req->ecc.bytes / req->ecc.nsectors;
for (strength = 0; strength < pmecc->caps->nstrengths; strength++) {
if (pmecc->caps->strengths[strength] == req->ecc.strength)
break;
}
user->cache.cfg = PMECC_CFG_BCH_STRENGTH(strength) |
PMECC_CFG_NSECTORS(req->ecc.nsectors);
if (req->ecc.sectorsize == 1024)
user->cache.cfg |= PMECC_CFG_SECTOR1024;
user->cache.sarea = req->oobsize - 1;
user->cache.saddr = req->ecc.ooboffset;
user->cache.eaddr = req->ecc.ooboffset + req->ecc.bytes - 1;
return user;
}
void atmel_pmecc_destroy_user(struct atmel_pmecc_user *user)
{
kfree(user);
}
static int get_strength(struct atmel_pmecc_user *user)
{
const int *strengths = user->pmecc->caps->strengths;
return strengths[user->cache.cfg & PMECC_CFG_BCH_STRENGTH_MASK];
}
static int get_sectorsize(struct atmel_pmecc_user *user)
{
return user->cache.cfg & PMECC_LOOKUP_TABLE_SIZE_1024 ? 1024 : 512;
}
static void atmel_pmecc_gen_syndrome(struct atmel_pmecc_user *user, int sector)
{
int strength = get_strength(user);
u32 value;
int i;
for (i = 0; i < strength; i++) {
value = readl_relaxed(user->pmecc->regs.base +
ATMEL_PMECC_REM(sector, i / 2));
if (i & 1)
value >>= 16;
user->partial_syn[(2 * i) + 1] = value;
}
}
static void atmel_pmecc_substitute(struct atmel_pmecc_user *user)
{
int degree = get_sectorsize(user) == 512 ? 13 : 14;
int cw_len = BIT(degree) - 1;
int strength = get_strength(user);
s16 *alpha_to = user->gf_tables->alpha_to;
s16 *index_of = user->gf_tables->index_of;
s16 *partial_syn = user->partial_syn;
s16 *si;
int i, j;
si = user->si;
memset(&si[1], 0, sizeof(s16) * ((2 * strength) - 1));
for (i = 1; i < 2 * strength; i += 2) {
for (j = 0; j < degree; j++) {
if (partial_syn[i] & BIT(j))
si[i] = alpha_to[i * j] ^ si[i];
}
}
for (i = 2, j = 1; j <= strength; i = ++j << 1) {
if (si[j] == 0) {
si[i] = 0;
} else {
s16 tmp;
tmp = index_of[si[j]];
tmp = (tmp * 2) % cw_len;
si[i] = alpha_to[tmp];
}
}
}
static void atmel_pmecc_get_sigma(struct atmel_pmecc_user *user)
{
s16 *lmu = user->lmu;
s16 *si = user->si;
s32 *mu = user->mu;
s32 *dmu = user->dmu;
s32 *delta = user->delta;
int degree = get_sectorsize(user) == 512 ? 13 : 14;
int cw_len = BIT(degree) - 1;
int strength = get_strength(user);
int num = 2 * strength + 1;
s16 *index_of = user->gf_tables->index_of;
s16 *alpha_to = user->gf_tables->alpha_to;
int i, j, k;
u32 dmu_0_count, tmp;
s16 *smu = user->smu;
int ro;
int largest;
int diff;
dmu_0_count = 0;
mu[0] = -1;
memset(smu, 0, sizeof(s16) * num);
smu[0] = 1;
dmu[0] = 1;
lmu[0] = 0;
delta[0] = (mu[0] * 2 - lmu[0]) >> 1;
mu[1] = 0;
memset(&smu[num], 0, sizeof(s16) * num);
smu[num] = 1;
dmu[1] = si[1];
lmu[1] = 0;
delta[1] = (mu[1] * 2 - lmu[1]) >> 1;
memset(&smu[(strength + 1) * num], 0, sizeof(s16) * num);
for (i = 1; i <= strength; i++) {
mu[i + 1] = i << 1;
if (dmu[i] == 0) {
dmu_0_count++;
tmp = ((strength - (lmu[i] >> 1) - 1) / 2);
if ((strength - (lmu[i] >> 1) - 1) & 0x1)
tmp += 2;
else
tmp += 1;
if (dmu_0_count == tmp) {
for (j = 0; j <= (lmu[i] >> 1) + 1; j++)
smu[(strength + 1) * num + j] =
smu[i * num + j];
lmu[strength + 1] = lmu[i];
return;
}
for (j = 0; j <= lmu[i] >> 1; j++)
smu[(i + 1) * num + j] = smu[i * num + j];
lmu[i + 1] = lmu[i];
} else {
ro = 0;
largest = -1;
for (j = 0; j < i; j++) {
if ((dmu[j]) && (delta[j] > largest)) {
largest = delta[j];
ro = j;
}
}
diff = (mu[i] - mu[ro]);
if ((lmu[i] >> 1) > ((lmu[ro] >> 1) + diff))
lmu[i + 1] = lmu[i];
else
lmu[i + 1] = ((lmu[ro] >> 1) + diff) * 2;
for (k = 0; k < num; k++)
smu[(i + 1) * num + k] = 0;
for (k = 0; k <= lmu[ro] >> 1; k++) {
s16 a, b, c;
if (!(smu[ro * num + k] && dmu[i]))
continue;
a = index_of[dmu[i]];
b = index_of[dmu[ro]];
c = index_of[smu[ro * num + k]];
tmp = a + (cw_len - b) + c;
a = alpha_to[tmp % cw_len];
smu[(i + 1) * num + (k + diff)] = a;
}
for (k = 0; k <= lmu[i] >> 1; k++)
smu[(i + 1) * num + k] ^= smu[i * num + k];
}
delta[i + 1] = (mu[i + 1] * 2 - lmu[i + 1]) >> 1;
if (i >= strength)
continue;
for (k = 0; k <= (lmu[i + 1] >> 1); k++) {
tmp = 2 * (i - 1);
if (k == 0) {
dmu[i + 1] = si[tmp + 3];
} else if (smu[(i + 1) * num + k] && si[tmp + 3 - k]) {
s16 a, b, c;
a = index_of[smu[(i + 1) * num + k]];
b = si[2 * (i - 1) + 3 - k];
c = index_of[b];
tmp = a + c;
tmp %= cw_len;
dmu[i + 1] = alpha_to[tmp] ^ dmu[i + 1];
}
}
}
}
static int atmel_pmecc_err_location(struct atmel_pmecc_user *user)
{
int sector_size = get_sectorsize(user);
int degree = sector_size == 512 ? 13 : 14;
struct atmel_pmecc *pmecc = user->pmecc;
int strength = get_strength(user);
int ret, roots_nbr, i, err_nbr = 0;
int num = (2 * strength) + 1;
s16 *smu = user->smu;
u32 val;
writel(PMERRLOC_DISABLE, pmecc->regs.errloc + ATMEL_PMERRLOC_ELDIS);
for (i = 0; i <= user->lmu[strength + 1] >> 1; i++) {
writel_relaxed(smu[(strength + 1) * num + i],
pmecc->regs.errloc + ATMEL_PMERRLOC_SIGMA(i));
err_nbr++;
}
val = (err_nbr - 1) << 16;
if (sector_size == 1024)
val |= 1;
writel(val, pmecc->regs.errloc + ATMEL_PMERRLOC_ELCFG);
writel((sector_size * 8) + (degree * strength),
pmecc->regs.errloc + ATMEL_PMERRLOC_ELEN);
ret = readl_relaxed_poll_timeout(pmecc->regs.errloc +
ATMEL_PMERRLOC_ELISR,
val, val & PMERRLOC_CALC_DONE, 0,
PMECC_MAX_TIMEOUT_MS * 1000);
if (ret) {
dev_err(pmecc->dev,
"PMECC: Timeout to calculate error location.\n");
return ret;
}
roots_nbr = (val & PMERRLOC_ERR_NUM_MASK) >> 8;
if (roots_nbr == user->lmu[strength + 1] >> 1)
return err_nbr - 1;
return -EBADMSG;
}
int atmel_pmecc_correct_sector(struct atmel_pmecc_user *user, int sector,
void *data, void *ecc)
{
struct atmel_pmecc *pmecc = user->pmecc;
int sectorsize = get_sectorsize(user);
int eccbytes = user->eccbytes;
int i, nerrors;
if (!(user->isr & BIT(sector)))
return 0;
atmel_pmecc_gen_syndrome(user, sector);
atmel_pmecc_substitute(user);
atmel_pmecc_get_sigma(user);
nerrors = atmel_pmecc_err_location(user);
if (nerrors < 0)
return nerrors;
for (i = 0; i < nerrors; i++) {
const char *area;
int byte, bit;
u32 errpos;
u8 *ptr;
errpos = readl_relaxed(pmecc->regs.errloc +
ATMEL_PMERRLOC_EL(pmecc->caps->el_offset, i));
errpos--;
byte = errpos / 8;
bit = errpos % 8;
if (byte < sectorsize) {
ptr = data + byte;
area = "data";
} else if (byte < sectorsize + eccbytes) {
ptr = ecc + byte - sectorsize;
area = "ECC";
} else {
dev_dbg(pmecc->dev,
"Invalid errpos value (%d, max is %d)\n",
errpos, (sectorsize + eccbytes) * 8);
return -EINVAL;
}
dev_dbg(pmecc->dev,
"Bit flip in %s area, byte %d: 0x%02x -> 0x%02x\n",
area, byte, *ptr, (unsigned int)(*ptr ^ BIT(bit)));
*ptr ^= BIT(bit);
}
return nerrors;
}
bool atmel_pmecc_correct_erased_chunks(struct atmel_pmecc_user *user)
{
return user->pmecc->caps->correct_erased_chunks;
}
void atmel_pmecc_get_generated_eccbytes(struct atmel_pmecc_user *user,
int sector, void *ecc)
{
struct atmel_pmecc *pmecc = user->pmecc;
u8 *ptr = ecc;
int i;
for (i = 0; i < user->eccbytes; i++)
ptr[i] = readb_relaxed(pmecc->regs.base +
ATMEL_PMECC_ECC(sector, i));
}
int atmel_pmecc_enable(struct atmel_pmecc_user *user, int op)
{
struct atmel_pmecc *pmecc = user->pmecc;
u32 cfg;
if (op != NAND_ECC_READ && op != NAND_ECC_WRITE) {
dev_err(pmecc->dev, "Bad ECC operation!");
return -EINVAL;
}
mutex_lock(&user->pmecc->lock);
cfg = user->cache.cfg;
if (op == NAND_ECC_WRITE)
cfg |= PMECC_CFG_WRITE_OP;
else
cfg |= PMECC_CFG_AUTO_ENABLE;
writel(cfg, pmecc->regs.base + ATMEL_PMECC_CFG);
writel(user->cache.sarea, pmecc->regs.base + ATMEL_PMECC_SAREA);
writel(user->cache.saddr, pmecc->regs.base + ATMEL_PMECC_SADDR);
writel(user->cache.eaddr, pmecc->regs.base + ATMEL_PMECC_EADDR);
writel(PMECC_CTRL_ENABLE, pmecc->regs.base + ATMEL_PMECC_CTRL);
writel(PMECC_CTRL_DATA, pmecc->regs.base + ATMEL_PMECC_CTRL);
return 0;
}
void atmel_pmecc_disable(struct atmel_pmecc_user *user)
{
struct atmel_pmecc *pmecc = user->pmecc;
writel(PMECC_CTRL_RST, pmecc->regs.base + ATMEL_PMECC_CTRL);
writel(PMECC_CTRL_DISABLE, pmecc->regs.base + ATMEL_PMECC_CTRL);
mutex_unlock(&user->pmecc->lock);
}
int atmel_pmecc_wait_rdy(struct atmel_pmecc_user *user)
{
struct atmel_pmecc *pmecc = user->pmecc;
u32 status;
int ret;
ret = readl_relaxed_poll_timeout(pmecc->regs.base +
ATMEL_PMECC_SR,
status, !(status & PMECC_SR_BUSY), 0,
PMECC_MAX_TIMEOUT_MS * 1000);
if (ret) {
dev_err(pmecc->dev,
"Timeout while waiting for PMECC ready.\n");
return ret;
}
user->isr = readl_relaxed(pmecc->regs.base + ATMEL_PMECC_ISR);
return 0;
}
static struct atmel_pmecc *atmel_pmecc_create(struct platform_device *pdev,
const struct atmel_pmecc_caps *caps,
int pmecc_res_idx, int errloc_res_idx)
{
struct device *dev = &pdev->dev;
struct atmel_pmecc *pmecc;
struct resource *res;
pmecc = devm_kzalloc(dev, sizeof(*pmecc), GFP_KERNEL);
if (!pmecc)
return ERR_PTR(-ENOMEM);
pmecc->caps = caps;
pmecc->dev = dev;
mutex_init(&pmecc->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, pmecc_res_idx);
pmecc->regs.base = devm_ioremap_resource(dev, res);
if (IS_ERR(pmecc->regs.base))
return ERR_CAST(pmecc->regs.base);
res = platform_get_resource(pdev, IORESOURCE_MEM, errloc_res_idx);
pmecc->regs.errloc = devm_ioremap_resource(dev, res);
if (IS_ERR(pmecc->regs.errloc))
return ERR_CAST(pmecc->regs.errloc);
writel(0xffffffff, pmecc->regs.base + ATMEL_PMECC_IDR);
writel(PMECC_CTRL_RST, pmecc->regs.base + ATMEL_PMECC_CTRL);
writel(PMECC_CTRL_DISABLE, pmecc->regs.base + ATMEL_PMECC_CTRL);
return pmecc;
}
static void devm_atmel_pmecc_put(struct device *dev, void *res)
{
struct atmel_pmecc **pmecc = res;
put_device((*pmecc)->dev);
}
static struct atmel_pmecc *atmel_pmecc_get_by_node(struct device *userdev,
struct device_node *np)
{
struct platform_device *pdev;
struct atmel_pmecc *pmecc, **ptr;
pdev = of_find_device_by_node(np);
if (!pdev || !platform_get_drvdata(pdev))
return ERR_PTR(-EPROBE_DEFER);
ptr = devres_alloc(devm_atmel_pmecc_put, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
get_device(&pdev->dev);
pmecc = platform_get_drvdata(pdev);
*ptr = pmecc;
devres_add(userdev, ptr);
return pmecc;
}
struct atmel_pmecc *devm_atmel_pmecc_get(struct device *userdev)
{
struct atmel_pmecc *pmecc;
struct device_node *np;
if (!userdev)
return ERR_PTR(-EINVAL);
if (!userdev->of_node)
return NULL;
np = of_parse_phandle(userdev->of_node, "ecc-engine", 0);
if (np) {
pmecc = atmel_pmecc_get_by_node(userdev, np);
of_node_put(np);
} else {
struct platform_device *pdev = to_platform_device(userdev);
const struct atmel_pmecc_caps *caps;
if (!of_property_read_bool(userdev->of_node,
"atmel,has-pmecc"))
return NULL;
caps = &at91sam9g45_caps;
np = of_find_compatible_node(userdev->of_node, NULL,
"atmel,sama5d3-nfc");
if (np) {
const struct of_device_id *match;
match = of_match_node(atmel_pmecc_legacy_match, np);
if (match && match->data)
caps = match->data;
of_node_put(np);
}
pmecc = atmel_pmecc_create(pdev, caps, 1, 2);
}
return pmecc;
}
static int atmel_pmecc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct atmel_pmecc_caps *caps;
struct atmel_pmecc *pmecc;
caps = of_device_get_match_data(&pdev->dev);
if (!caps) {
dev_err(dev, "Invalid caps\n");
return -EINVAL;
}
pmecc = atmel_pmecc_create(pdev, caps, 0, 1);
if (IS_ERR(pmecc))
return PTR_ERR(pmecc);
platform_set_drvdata(pdev, pmecc);
return 0;
}
