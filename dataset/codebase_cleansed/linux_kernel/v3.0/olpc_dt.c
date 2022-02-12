static phandle __init olpc_dt_getsibling(phandle node)
{
const void *args[] = { (void *)node };
void *res[] = { &node };
if ((s32)node == -1)
return 0;
if (olpc_ofw("peer", args, res) || (s32)node == -1)
return 0;
return node;
}
static phandle __init olpc_dt_getchild(phandle node)
{
const void *args[] = { (void *)node };
void *res[] = { &node };
if ((s32)node == -1)
return 0;
if (olpc_ofw("child", args, res) || (s32)node == -1) {
pr_err("PROM: %s: fetching child failed!\n", __func__);
return 0;
}
return node;
}
static int __init olpc_dt_getproplen(phandle node, const char *prop)
{
const void *args[] = { (void *)node, prop };
int len;
void *res[] = { &len };
if ((s32)node == -1)
return -1;
if (olpc_ofw("getproplen", args, res)) {
pr_err("PROM: %s: getproplen failed!\n", __func__);
return -1;
}
return len;
}
static int __init olpc_dt_getproperty(phandle node, const char *prop,
char *buf, int bufsize)
{
int plen;
plen = olpc_dt_getproplen(node, prop);
if (plen > bufsize || plen < 1) {
return -1;
} else {
const void *args[] = { (void *)node, prop, buf, (void *)plen };
void *res[] = { &plen };
if (olpc_ofw("getprop", args, res)) {
pr_err("PROM: %s: getprop failed!\n", __func__);
return -1;
}
}
return plen;
}
static int __init olpc_dt_nextprop(phandle node, char *prev, char *buf)
{
const void *args[] = { (void *)node, prev, buf };
int success;
void *res[] = { &success };
buf[0] = '\0';
if ((s32)node == -1)
return -1;
if (olpc_ofw("nextprop", args, res) || success != 1)
return -1;
return 0;
}
static int __init olpc_dt_pkg2path(phandle node, char *buf,
const int buflen, int *len)
{
const void *args[] = { (void *)node, buf, (void *)buflen };
void *res[] = { len };
if ((s32)node == -1)
return -1;
if (olpc_ofw("package-to-path", args, res) || *len < 1)
return -1;
return 0;
}
void * __init prom_early_alloc(unsigned long size)
{
static u8 *mem;
static size_t free_mem;
void *res;
if (free_mem < size) {
const size_t chunk_size = max(PAGE_SIZE, size);
res = alloc_bootmem(chunk_size);
BUG_ON(!res);
prom_early_allocated += chunk_size;
memset(res, 0, chunk_size);
free_mem = chunk_size;
mem = res;
}
free_mem -= size;
res = mem;
mem += size;
return res;
}
void __init olpc_dt_build_devicetree(void)
{
phandle root;
if (!olpc_ofw_is_installed())
return;
root = olpc_dt_getsibling(0);
if (!root) {
pr_err("PROM: unable to get root node from OFW!\n");
return;
}
of_pdt_build_devicetree(root, &prom_olpc_ops);
pr_info("PROM DT: Built device tree with %u bytes of memory.\n",
prom_early_allocated);
}
static int __init olpc_create_platform_devices(void)
{
if (machine_is_olpc())
return of_platform_bus_probe(NULL, of_ids, NULL);
else
return 0;
}
