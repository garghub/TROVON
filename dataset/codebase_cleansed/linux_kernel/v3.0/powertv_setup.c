const char *get_system_type(void)
{
return "PowerTV";
}
void __init plat_mem_setup(void)
{
panic_on_oops = 1;
register_panic_notifier();
#if 0
mips_pcibios_init();
#endif
mips_reboot_setup();
}
static void register_panic_notifier()
{
static struct notifier_block panic_notifier = {
.notifier_call = panic_handler,
.next = NULL,
.priority = INT_MAX
};
atomic_notifier_chain_register(&panic_notifier_list, &panic_notifier);
}
static int panic_handler(struct notifier_block *notifier_block,
unsigned long event, void *cause_string)
{
struct pt_regs my_regs;
{
unsigned long at, v0, v1;
__asm__ __volatile__ (
".set noat\n"
LONG_S_ "$at, %[at]\n"
LONG_S_ "$2, %[v0]\n"
LONG_S_ "$3, %[v1]\n"
:
[at] "=m" (at),
[v0] "=m" (v0),
[v1] "=m" (v1)
:
: "at"
);
__asm__ __volatile__ (
".set noat\n"
"move $at, %[pt_regs]\n"
LONG_S_ "$4, " VAL(PT_R4) "($at)\n"
LONG_S_ "$5, " VAL(PT_R5) "($at)\n"
LONG_S_ "$6, " VAL(PT_R6) "($at)\n"
LONG_S_ "$7, " VAL(PT_R7) "($at)\n"
LONG_S_ "$8, " VAL(PT_R8) "($at)\n"
LONG_S_ "$9, " VAL(PT_R9) "($at)\n"
LONG_S_ "$10, " VAL(PT_R10) "($at)\n"
LONG_S_ "$11, " VAL(PT_R11) "($at)\n"
LONG_S_ "$12, " VAL(PT_R12) "($at)\n"
LONG_S_ "$13, " VAL(PT_R13) "($at)\n"
LONG_S_ "$14, " VAL(PT_R14) "($at)\n"
LONG_S_ "$15, " VAL(PT_R15) "($at)\n"
LONG_S_ "$16, " VAL(PT_R16) "($at)\n"
LONG_S_ "$17, " VAL(PT_R17) "($at)\n"
LONG_S_ "$18, " VAL(PT_R18) "($at)\n"
LONG_S_ "$19, " VAL(PT_R19) "($at)\n"
LONG_S_ "$20, " VAL(PT_R20) "($at)\n"
LONG_S_ "$21, " VAL(PT_R21) "($at)\n"
LONG_S_ "$22, " VAL(PT_R22) "($at)\n"
LONG_S_ "$23, " VAL(PT_R23) "($at)\n"
LONG_S_ "$24, " VAL(PT_R24) "($at)\n"
LONG_S_ "$25, " VAL(PT_R25) "($at)\n"
LONG_S_ "$26, " VAL(PT_R26) "($at)\n"
LONG_S_ "$27, " VAL(PT_R27) "($at)\n"
LONG_S_ "$gp, " VAL(PT_R28) "($at)\n"
LONG_S_ "$sp, " VAL(PT_R29) "($at)\n"
LONG_S_ "$fp, " VAL(PT_R30) "($at)\n"
LONG_S_ "$ra, " VAL(PT_R31) "($at)\n"
LONG_L_ "$8, %[at]\n"
LONG_S_ "$8, " VAL(PT_R1) "($at)\n"
LONG_L_ "$8, %[v0]\n"
LONG_S_ "$8, " VAL(PT_R2) "($at)\n"
LONG_L_ "$8, %[v1]\n"
LONG_S_ "$8, " VAL(PT_R3) "($at)\n"
:
:
[at] "m" (at),
[v0] "m" (v0),
[v1] "m" (v1),
[pt_regs] "r" (&my_regs)
: "at", "t0"
);
__asm__ __volatile__ (
".set noat\n"
"1:\n"
PTR_LA_ "$at, 1b\n"
LONG_S_ "$at, %[cp0_epc]\n"
:
[cp0_epc] "=m" (my_regs.cp0_epc)
:
: "at"
);
my_regs.cp0_cause = read_c0_cause();
my_regs.cp0_status = read_c0_status();
}
pr_crit("I'm feeling a bit sleepy. hmmmmm... perhaps a nap would... "
"zzzz... \n");
return NOTIFY_DONE;
}
static int rfmac_param(char *p)
{
u8 *q;
bool is_high_nibble;
int c;
if (*p == '0' && *(p+1) == 'x')
p += 2;
q = rfmac;
is_high_nibble = true;
for (c = (unsigned char) *p++;
isxdigit(c) && q - rfmac < ETH_ALEN;
c = (unsigned char) *p++) {
int nibble;
nibble = (isdigit(c) ? (c - '0') :
(isupper(c) ? c - 'A' + 10 : c - 'a' + 10));
if (is_high_nibble)
*q = nibble << 4;
else
*q++ |= nibble;
is_high_nibble = !is_high_nibble;
}
have_rfmac = (c == '\0' && q - rfmac == ETH_ALEN);
return 0;
}
void platform_random_ether_addr(u8 addr[ETH_ALEN])
{
const int num_random_bytes = 2;
const unsigned char non_sciatl_oui_bits = 0xc0u;
const unsigned char mac_addr_locally_managed = (1 << 1);
if (!have_rfmac) {
pr_warning("rfmac not available on command line; "
"generating random MAC address\n");
random_ether_addr(addr);
}
else {
int i;
addr[0] = non_sciatl_oui_bits | mac_addr_locally_managed;
get_random_bytes(&addr[1], num_random_bytes);
for (i = 1 + num_random_bytes; i < ETH_ALEN; i++)
addr[i] = rfmac[i];
}
}
