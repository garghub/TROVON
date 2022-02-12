static unsigned int hashnum(unsigned int num)
{
unsigned int mask1 = HASH1 << 27, mask2 = HASH2 << 27;
for (; mask1 >= HASH1; mask1 >>= 1, mask2 >>= 1)
if (num & mask1)
num ^= mask2;
return num & (HASHSZ-1);
}
const char *names_vendor(u_int16_t vendorid)
{
struct vendor *v;
v = vendors[hashnum(vendorid)];
for (; v; v = v->next)
if (v->vendorid == vendorid)
return v->name;
return NULL;
}
const char *names_product(u_int16_t vendorid, u_int16_t productid)
{
struct product *p;
p = products[hashnum((vendorid << 16) | productid)];
for (; p; p = p->next)
if (p->vendorid == vendorid && p->productid == productid)
return p->name;
return NULL;
}
const char *names_class(u_int8_t classid)
{
struct class *c;
c = classes[hashnum(classid)];
for (; c; c = c->next)
if (c->classid == classid)
return c->name;
return NULL;
}
const char *names_subclass(u_int8_t classid, u_int8_t subclassid)
{
struct subclass *s;
s = subclasses[hashnum((classid << 8) | subclassid)];
for (; s; s = s->next)
if (s->classid == classid && s->subclassid == subclassid)
return s->name;
return NULL;
}
const char *names_protocol(u_int8_t classid, u_int8_t subclassid,
u_int8_t protocolid)
{
struct protocol *p;
p = protocols[hashnum((classid << 16) | (subclassid << 8)
| protocolid)];
for (; p; p = p->next)
if (p->classid == classid && p->subclassid == subclassid &&
p->protocolid == protocolid)
return p->name;
return NULL;
}
static void *my_malloc(size_t size)
{
struct pool *p;
p = calloc(1, sizeof(struct pool));
if (!p)
return NULL;
p->mem = calloc(1, size);
if (!p->mem) {
free(p);
return NULL;
}
p->next = pool_head;
pool_head = p;
return p->mem;
}
void names_free(void)
{
struct pool *pool;
if (!pool_head)
return;
for (pool = pool_head; pool != NULL; ) {
struct pool *tmp;
if (pool->mem)
free(pool->mem);
tmp = pool;
pool = pool->next;
free(tmp);
}
}
static int new_vendor(const char *name, u_int16_t vendorid)
{
struct vendor *v;
unsigned int h = hashnum(vendorid);
v = vendors[h];
for (; v; v = v->next)
if (v->vendorid == vendorid)
return -1;
v = my_malloc(sizeof(struct vendor) + strlen(name));
if (!v)
return -1;
strcpy(v->name, name);
v->vendorid = vendorid;
v->next = vendors[h];
vendors[h] = v;
return 0;
}
static int new_product(const char *name, u_int16_t vendorid,
u_int16_t productid)
{
struct product *p;
unsigned int h = hashnum((vendorid << 16) | productid);
p = products[h];
for (; p; p = p->next)
if (p->vendorid == vendorid && p->productid == productid)
return -1;
p = my_malloc(sizeof(struct product) + strlen(name));
if (!p)
return -1;
strcpy(p->name, name);
p->vendorid = vendorid;
p->productid = productid;
p->next = products[h];
products[h] = p;
return 0;
}
static int new_class(const char *name, u_int8_t classid)
{
struct class *c;
unsigned int h = hashnum(classid);
c = classes[h];
for (; c; c = c->next)
if (c->classid == classid)
return -1;
c = my_malloc(sizeof(struct class) + strlen(name));
if (!c)
return -1;
strcpy(c->name, name);
c->classid = classid;
c->next = classes[h];
classes[h] = c;
return 0;
}
static int new_subclass(const char *name, u_int8_t classid, u_int8_t subclassid)
{
struct subclass *s;
unsigned int h = hashnum((classid << 8) | subclassid);
s = subclasses[h];
for (; s; s = s->next)
if (s->classid == classid && s->subclassid == subclassid)
return -1;
s = my_malloc(sizeof(struct subclass) + strlen(name));
if (!s)
return -1;
strcpy(s->name, name);
s->classid = classid;
s->subclassid = subclassid;
s->next = subclasses[h];
subclasses[h] = s;
return 0;
}
static int new_protocol(const char *name, u_int8_t classid, u_int8_t subclassid,
u_int8_t protocolid)
{
struct protocol *p;
unsigned int h = hashnum((classid << 16) | (subclassid << 8)
| protocolid);
p = protocols[h];
for (; p; p = p->next)
if (p->classid == classid && p->subclassid == subclassid
&& p->protocolid == protocolid)
return -1;
p = my_malloc(sizeof(struct protocol) + strlen(name));
if (!p)
return -1;
strcpy(p->name, name);
p->classid = classid;
p->subclassid = subclassid;
p->protocolid = protocolid;
p->next = protocols[h];
protocols[h] = p;
return 0;
}
static void parse(FILE *f)
{
char buf[512], *cp;
unsigned int linectr = 0;
int lastvendor = -1;
int lastclass = -1;
int lastsubclass = -1;
int lasthut = -1;
int lastlang = -1;
unsigned int u;
while (fgets(buf, sizeof(buf), f)) {
linectr++;
cp = strchr(buf, '\r');
if (cp)
*cp = 0;
cp = strchr(buf, '\n');
if (cp)
*cp = 0;
if (buf[0] == '#' || !buf[0])
continue;
cp = buf;
if (buf[0] == 'P' && buf[1] == 'H' && buf[2] == 'Y' &&
buf[3] == 'S' && buf[4] == 'D' &&
buf[5] == 'E' && buf[6] == 'S' &&
buf[7] == ' ') {
continue;
}
if (buf[0] == 'P' && buf[1] == 'H' &&
buf[2] == 'Y' && buf[3] == ' ') {
continue;
}
if (buf[0] == 'B' && buf[1] == 'I' && buf[2] == 'A' &&
buf[3] == 'S' && buf[4] == ' ') {
continue;
}
if (buf[0] == 'L' && buf[1] == ' ') {
lasthut = lastclass = lastvendor = lastsubclass = -1;
lastlang = 1;
continue;
}
if (buf[0] == 'C' && buf[1] == ' ') {
cp = buf+2;
while (isspace(*cp))
cp++;
if (!isxdigit(*cp)) {
err("Invalid class spec at line %u", linectr);
continue;
}
u = strtoul(cp, &cp, 16);
while (isspace(*cp))
cp++;
if (!*cp) {
err("Invalid class spec at line %u", linectr);
continue;
}
if (new_class(cp, u))
err("Duplicate class spec at line %u class %04x %s",
linectr, u, cp);
dbg("line %5u class %02x %s", linectr, u, cp);
lasthut = lastlang = lastvendor = lastsubclass = -1;
lastclass = u;
continue;
}
if (buf[0] == 'A' && buf[1] == 'T' && isspace(buf[2])) {
continue;
}
if (buf[0] == 'H' && buf[1] == 'C' && buf[2] == 'C'
&& isspace(buf[3])) {
continue;
}
if (isxdigit(*cp)) {
u = strtoul(cp, &cp, 16);
while (isspace(*cp))
cp++;
if (!*cp) {
err("Invalid vendor spec at line %u", linectr);
continue;
}
if (new_vendor(cp, u))
err("Duplicate vendor spec at line %u vendor %04x %s",
linectr, u, cp);
dbg("line %5u vendor %04x %s", linectr, u, cp);
lastvendor = u;
lasthut = lastlang = lastclass = lastsubclass = -1;
continue;
}
if (buf[0] == '\t' && isxdigit(buf[1])) {
u = strtoul(buf+1, &cp, 16);
while (isspace(*cp))
cp++;
if (!*cp) {
err("Invalid product/subclass spec at line %u",
linectr);
continue;
}
if (lastvendor != -1) {
if (new_product(cp, lastvendor, u))
err("Duplicate product spec at line %u product %04x:%04x %s",
linectr, lastvendor, u, cp);
dbg("line %5u product %04x:%04x %s", linectr,
lastvendor, u, cp);
continue;
}
if (lastclass != -1) {
if (new_subclass(cp, lastclass, u))
err("Duplicate subclass spec at line %u class %02x:%02x %s",
linectr, lastclass, u, cp);
dbg("line %5u subclass %02x:%02x %s", linectr,
lastclass, u, cp);
lastsubclass = u;
continue;
}
if (lasthut != -1) {
continue;
}
if (lastlang != -1) {
continue;
}
err("Product/Subclass spec without prior Vendor/Class spec at line %u",
linectr);
continue;
}
if (buf[0] == '\t' && buf[1] == '\t' && isxdigit(buf[2])) {
u = strtoul(buf+2, &cp, 16);
while (isspace(*cp))
cp++;
if (!*cp) {
err("Invalid protocol spec at line %u",
linectr);
continue;
}
if (lastclass != -1 && lastsubclass != -1) {
if (new_protocol(cp, lastclass, lastsubclass,
u))
err("Duplicate protocol spec at line %u class %02x:%02x:%02x %s",
linectr, lastclass, lastsubclass,
u, cp);
dbg("line %5u protocol %02x:%02x:%02x %s",
linectr, lastclass, lastsubclass, u, cp);
continue;
}
err("Protocol spec without prior Class and Subclass spec at line %u",
linectr);
continue;
}
if (buf[0] == 'H' && buf[1] == 'I' &&
buf[2] == 'D' && buf[3] == ' ') {
continue;
}
if (buf[0] == 'H' && buf[1] == 'U' &&
buf[2] == 'T' && buf[3] == ' ') {
lastlang = lastclass = lastvendor = lastsubclass = -1;
lasthut = 1;
continue;
}
if (buf[0] == 'R' && buf[1] == ' ')
continue;
if (buf[0] == 'V' && buf[1] == 'T')
continue;
err("Unknown line at line %u", linectr);
}
}
int names_init(char *n)
{
FILE *f;
f = fopen(n, "r");
if (!f)
return errno;
parse(f);
fclose(f);
return 0;
}
