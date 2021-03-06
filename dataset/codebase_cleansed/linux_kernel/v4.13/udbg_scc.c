static void udbg_scc_putc(char c)
{
if (sccc) {
while ((in_8(sccc) & SCC_TXRDY) == 0)
;
out_8(sccd, c);
if (c == '\n')
udbg_scc_putc('\r');
}
}
static int udbg_scc_getc_poll(void)
{
if (sccc) {
if ((in_8(sccc) & SCC_RXRDY) != 0)
return in_8(sccd);
else
return -1;
}
return -1;
}
static int udbg_scc_getc(void)
{
if (sccc) {
while ((in_8(sccc) & SCC_RXRDY) == 0)
;
return in_8(sccd);
}
return -1;
}
void udbg_scc_init(int force_scc)
{
const u32 *reg;
unsigned long addr;
struct device_node *stdout = NULL, *escc = NULL, *macio = NULL;
struct device_node *ch, *ch_def = NULL, *ch_a = NULL;
const char *path;
int i, x;
escc = of_find_node_by_name(NULL, "escc");
if (escc == NULL)
goto bail;
macio = of_get_parent(escc);
if (macio == NULL)
goto bail;
path = of_get_property(of_chosen, "linux,stdout-path", NULL);
if (path != NULL)
stdout = of_find_node_by_path(path);
for (ch = NULL; (ch = of_get_next_child(escc, ch)) != NULL;) {
if (ch == stdout)
ch_def = of_node_get(ch);
if (strcmp(ch->name, "ch-a") == 0)
ch_a = of_node_get(ch);
}
if (ch_def == NULL && !force_scc)
goto bail;
ch = ch_def ? ch_def : ch_a;
reg = of_get_property(escc, "reg", NULL);
if (reg == NULL)
goto bail;
addr = reg[0];
reg = of_get_property(macio, "assigned-addresses", NULL);
if (reg == NULL)
goto bail;
addr += reg[2];
pmac_call_feature(PMAC_FTR_SCC_ENABLE, ch,
PMAC_SCC_ASYNC | PMAC_SCC_FLAG_XMON, 1);
if (ch == ch_a)
addr += 0x20;
sccc = ioremap(addr & PAGE_MASK, PAGE_SIZE) ;
sccc += addr & ~PAGE_MASK;
sccd = sccc + 0x10;
mb();
for (i = 20000; i != 0; --i)
x = in_8(sccc);
out_8(sccc, 0x09);
out_8(sccc, 0xc0);
if (ch_def != NULL) {
out_8(sccc, 13);
scc_inittab[1] = in_8(sccc);
out_8(sccc, 12);
scc_inittab[3] = in_8(sccc);
} else if (of_machine_is_compatible("RackMac1,1")
|| of_machine_is_compatible("RackMac1,2")
|| of_machine_is_compatible("MacRISC4")) {
scc_inittab[1] = 0;
scc_inittab[3] = 0;
} else {
scc_inittab[1] = 0;
scc_inittab[3] = 1;
}
for (i = 0; i < sizeof(scc_inittab); ++i)
out_8(sccc, scc_inittab[i]);
udbg_putc = udbg_scc_putc;
udbg_getc = udbg_scc_getc;
udbg_getc_poll = udbg_scc_getc_poll;
udbg_puts("Hello World !\n");
bail:
of_node_put(macio);
of_node_put(escc);
of_node_put(stdout);
of_node_put(ch_def);
of_node_put(ch_a);
}
static void udbg_real_scc_putc(char c)
{
while ((real_readb(sccc) & SCC_TXRDY) == 0)
;
real_writeb(c, sccd);
if (c == '\n')
udbg_real_scc_putc('\r');
}
void __init udbg_init_pmac_realmode(void)
{
sccc = (volatile u8 __iomem *)0x80013020ul;
sccd = (volatile u8 __iomem *)0x80013030ul;
udbg_putc = udbg_real_scc_putc;
udbg_getc = NULL;
udbg_getc_poll = NULL;
}
