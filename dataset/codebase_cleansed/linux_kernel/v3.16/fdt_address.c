static void __init of_dump_addr(const char *s, const __be32 *addr, int na)
{
pr_debug("%s", s);
while(na--)
pr_cont(" %08x", *(addr++));
pr_debug("\n");
}
static void __init of_dump_addr(const char *s, const __be32 *addr, int na) { }
static void __init fdt_bus_default_count_cells(const void *blob, int parentoffset,
int *addrc, int *sizec)
{
const __be32 *prop;
if (addrc) {
prop = fdt_getprop(blob, parentoffset, "#address-cells", NULL);
if (prop)
*addrc = be32_to_cpup(prop);
else
*addrc = dt_root_addr_cells;
}
if (sizec) {
prop = fdt_getprop(blob, parentoffset, "#size-cells", NULL);
if (prop)
*sizec = be32_to_cpup(prop);
else
*sizec = dt_root_size_cells;
}
}
static u64 __init fdt_bus_default_map(__be32 *addr, const __be32 *range,
int na, int ns, int pna)
{
u64 cp, s, da;
cp = of_read_number(range, na);
s = of_read_number(range + na + pna, ns);
da = of_read_number(addr, na);
pr_debug("FDT: default map, cp=%llx, s=%llx, da=%llx\n",
cp, s, da);
if (da < cp || da >= (cp + s))
return OF_BAD_ADDR;
return da - cp;
}
static int __init fdt_bus_default_translate(__be32 *addr, u64 offset, int na)
{
u64 a = of_read_number(addr, na);
memset(addr, 0, na * 4);
a += offset;
if (na > 1)
addr[na - 2] = cpu_to_fdt32(a >> 32);
addr[na - 1] = cpu_to_fdt32(a & 0xffffffffu);
return 0;
}
static int __init fdt_translate_one(const void *blob, int parent,
const struct of_bus *bus,
const struct of_bus *pbus, __be32 *addr,
int na, int ns, int pna, const char *rprop)
{
const __be32 *ranges;
int rlen;
int rone;
u64 offset = OF_BAD_ADDR;
ranges = fdt_getprop(blob, parent, rprop, &rlen);
if (!ranges)
return 1;
if (rlen == 0) {
offset = of_read_number(addr, na);
memset(addr, 0, pna * 4);
pr_debug("FDT: empty ranges, 1:1 translation\n");
goto finish;
}
pr_debug("FDT: walking ranges...\n");
rlen /= 4;
rone = na + pna + ns;
for (; rlen >= rone; rlen -= rone, ranges += rone) {
offset = bus->map(addr, ranges, na, ns, pna);
if (offset != OF_BAD_ADDR)
break;
}
if (offset == OF_BAD_ADDR) {
pr_debug("FDT: not found !\n");
return 1;
}
memcpy(addr, ranges + na, 4 * pna);
finish:
of_dump_addr("FDT: parent translation for:", addr, pna);
pr_debug("FDT: with offset: %llx\n", offset);
return pbus->translate(addr, offset, pna);
}
u64 __init fdt_translate_address(const void *blob, int node_offset)
{
int parent, len;
const struct of_bus *bus, *pbus;
const __be32 *reg;
__be32 addr[OF_MAX_ADDR_CELLS];
int na, ns, pna, pns;
u64 result = OF_BAD_ADDR;
pr_debug("FDT: ** translation for device %s **\n",
fdt_get_name(blob, node_offset, NULL));
reg = fdt_getprop(blob, node_offset, "reg", &len);
if (!reg) {
pr_err("FDT: warning: device tree node '%s' has no address.\n",
fdt_get_name(blob, node_offset, NULL));
goto bail;
}
parent = fdt_parent_offset(blob, node_offset);
if (parent < 0)
goto bail;
bus = &of_busses[0];
bus->count_cells(blob, parent, &na, &ns);
if (!OF_CHECK_COUNTS(na, ns)) {
pr_err("FDT: Bad cell count for %s\n",
fdt_get_name(blob, node_offset, NULL));
goto bail;
}
memcpy(addr, reg, na * 4);
pr_debug("FDT: bus (na=%d, ns=%d) on %s\n",
na, ns, fdt_get_name(blob, parent, NULL));
of_dump_addr("OF: translating address:", addr, na);
for (;;) {
node_offset = parent;
parent = fdt_parent_offset(blob, node_offset);
if (parent < 0) {
pr_debug("FDT: reached root node\n");
result = of_read_number(addr, na);
break;
}
pbus = &of_busses[0];
pbus->count_cells(blob, parent, &pna, &pns);
if (!OF_CHECK_COUNTS(pna, pns)) {
pr_err("FDT: Bad cell count for %s\n",
fdt_get_name(blob, node_offset, NULL));
break;
}
pr_debug("FDT: parent bus (na=%d, ns=%d) on %s\n",
pna, pns, fdt_get_name(blob, parent, NULL));
if (fdt_translate_one(blob, node_offset, bus, pbus,
addr, na, ns, pna, "ranges"))
break;
na = pna;
ns = pns;
bus = pbus;
of_dump_addr("FDT: one level translation:", addr, na);
}
bail:
return result;
}
