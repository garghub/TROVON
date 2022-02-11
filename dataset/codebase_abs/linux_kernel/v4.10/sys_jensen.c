static void
F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 7 )
F_2 ( V_2 ) ;
}
static void
F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 7 )
F_4 ( V_2 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 7 )
F_6 ( V_2 ) ;
}
static void
F_7 ( unsigned long V_4 )
{
int V_3 ;
switch ( V_4 ) {
case 0x660 :
F_8 ( L_1 ) ;
F_8 ( L_2 , F_9 ( 0x61 ) , F_9 ( 0x461 ) ) ;
return;
case 0x900 : V_3 = 4 ; break;
case 0x920 : V_3 = 3 ; break;
case 0x980 : V_3 = 1 ; break;
case 0x990 : V_3 = 9 ; break;
default:
if ( V_4 > 0x900 ) {
F_8 ( L_3 , V_4 ) ;
return;
}
V_3 = ( V_4 - 0x800 ) >> 4 ;
if ( V_3 == 1 )
V_3 = 7 ;
break;
}
if ( ! F_10 ( V_3 ) ) {
if ( V_4 >= 0x900 )
{
F_9 ( 0x64 ) ;
F_9 ( 0x60 ) ;
F_9 ( 0x3fa ) ;
F_9 ( 0x2fa ) ;
F_11 ( 0x0c , 0x3fc ) ;
F_11 ( 0x0c , 0x2fc ) ;
F_11 ( 0 , 0x61 ) ;
F_11 ( 0 , 0x461 ) ;
}
}
#if 0
{
static unsigned int last_msg = 0, last_cc = 0;
static int last_irq = -1, count = 0;
unsigned int cc;
__asm __volatile("rpcc %0" : "=r"(cc));
++count;
#define F_12 (150000000)
if (cc - last_msg > ((JENSEN_CYCLES_PER_SEC) * 3) ||
irq != last_irq) {
printk(KERN_CRIT " irq %d count %d cc %u @ %lx\n",
irq, count, cc-last_cc, get_irq_regs()->pc);
count = 0;
last_msg = cc;
last_irq = irq;
}
last_cc = cc;
}
#endif
F_13 ( V_3 ) ;
}
static void T_1
F_14 ( void )
{
F_15 () ;
F_16 ( 1 , & V_5 , V_6 ) ;
F_16 ( 4 , & V_5 , V_6 ) ;
F_16 ( 3 , & V_5 , V_6 ) ;
F_16 ( 7 , & V_5 , V_6 ) ;
F_16 ( 9 , & V_5 , V_6 ) ;
F_17 () ;
}
static void T_1
F_18 ( void )
{
struct V_7 * V_8 ;
#ifdef F_19
static struct V_9 V_10 = { . V_11 = 0xffffffffUL , } ;
V_12 = & V_10 ;
#endif
V_13 = V_8 = F_20 () ;
V_8 -> V_14 = & V_15 ;
V_8 -> V_16 = & V_17 ;
V_8 -> V_18 = 0 ;
V_8 -> V_19 = V_20 - V_21 ;
V_8 -> V_22 = 0 ;
V_8 -> V_23 = V_24 - V_21 ;
V_8 -> V_25 = 0 ;
V_8 -> V_26 = V_8 -> V_27 = NULL ;
V_28 = 0 ;
V_29 = 0xffffffff ;
}
static void
F_21 ( unsigned long V_4 , unsigned long V_30 )
{
F_8 ( V_31 L_4 ) ;
}
