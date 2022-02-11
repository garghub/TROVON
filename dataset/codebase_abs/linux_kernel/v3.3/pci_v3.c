static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 )
{
unsigned int V_5 , V_6 , V_7 ;
V_7 = V_2 -> V_8 ;
if ( V_4 > 255 )
F_2 () ;
if ( V_7 > 255 )
F_2 () ;
if ( V_3 > 255 )
F_2 () ;
if ( V_7 == 0 ) {
int V_9 = F_3 ( V_3 ) ;
V_5 = F_4 ( V_3 ) << 8 ;
V_6 = V_10 ;
if ( V_9 > 12 )
V_6 |= 1 << ( V_9 - 5 ) ;
else
V_5 |= 1 << ( V_9 + 11 ) ;
} else {
V_6 = V_10 | V_11 ;
V_5 = ( V_7 << 16 ) | ( V_3 << 8 ) ;
}
F_5 ( V_12 , F_6 ( V_13 ) |
V_14 | V_15 ) ;
F_5 ( V_16 , F_6 ( V_17 ) |
V_18 | V_15 ) ;
F_7 ( V_19 , V_6 ) ;
return V_20 + V_5 + V_4 ;
}
static void F_8 ( void )
{
F_5 ( V_16 , F_6 ( V_13 + V_21 ) |
V_22 | V_23 |
V_15 ) ;
F_7 ( V_19 , F_9 ( V_24 ) |
V_25 ) ;
F_5 ( V_12 , F_6 ( V_13 ) |
V_22 | V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 , int V_26 ,
int V_27 , T_1 * V_28 )
{
unsigned long V_29 ;
unsigned long V_30 ;
T_1 V_31 ;
F_11 ( & V_32 , V_30 ) ;
V_29 = F_1 ( V_2 , V_3 , V_26 ) ;
switch ( V_27 ) {
case 1 :
V_31 = F_12 ( V_29 ) ;
break;
case 2 :
V_31 = F_13 ( V_29 ) ;
break;
default:
V_31 = F_14 ( V_29 ) ;
break;
}
F_8 () ;
F_15 ( & V_32 , V_30 ) ;
* V_28 = V_31 ;
return V_33 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_3 , int V_26 ,
int V_27 , T_1 V_28 )
{
unsigned long V_29 ;
unsigned long V_30 ;
F_11 ( & V_32 , V_30 ) ;
V_29 = F_1 ( V_2 , V_3 , V_26 ) ;
switch ( V_27 ) {
case 1 :
F_17 ( ( V_34 ) V_28 , V_29 ) ;
F_12 ( V_29 ) ;
break;
case 2 :
F_18 ( ( V_35 ) V_28 , V_29 ) ;
F_13 ( V_29 ) ;
break;
case 4 :
F_19 ( V_28 , V_29 ) ;
F_14 ( V_29 ) ;
break;
}
F_8 () ;
F_15 ( & V_32 , V_30 ) ;
return V_33 ;
}
static int T_2 F_20 ( struct V_36 * V_37 )
{
if ( F_21 ( & V_38 , & V_39 ) ) {
F_22 ( V_40 L_1
L_2 ) ;
return - V_41 ;
}
if ( F_21 ( & V_38 , & V_42 ) ) {
F_23 ( & V_39 ) ;
F_22 ( V_40 L_3
L_2 ) ;
return - V_41 ;
}
F_24 ( & V_37 -> V_43 , & V_44 ) ;
F_24 ( & V_37 -> V_43 , & V_39 ) ;
F_24 ( & V_37 -> V_43 , & V_42 ) ;
return 1 ;
}
static int
F_25 ( unsigned long V_29 , unsigned int V_45 , struct V_46 * V_47 )
{
unsigned long V_48 = F_26 ( V_47 ) ;
unsigned long V_49 = * ( unsigned long * ) V_48 ;
#if 0
char buf[128];
sprintf(buf, "V3 fault: addr 0x%08lx, FSR 0x%03x, PC 0x%08lx [%08lx] LBFADDR=%08x LBFCODE=%02x ISTAT=%02x\n",
addr, fsr, pc, instr, __raw_readl(SC_LBFADDR), __raw_readl(SC_LBFCODE) & 255,
v3_readb(V3_LB_ISTAT));
printk(KERN_DEBUG "%s", buf);
#endif
F_27 ( V_50 , 0 ) ;
F_19 ( 3 , V_51 ) ;
if ( ( V_49 & 0x0c100000 ) == 0x04100000 ) {
int V_52 = ( V_49 >> 12 ) & 15 ;
unsigned long V_28 ;
if ( V_49 & 0x00400000 )
V_28 = 255 ;
else
V_28 = - 1 ;
V_47 -> V_53 [ V_52 ] = V_28 ;
V_47 -> V_54 += 4 ;
return 0 ;
}
if ( ( V_49 & 0x0e100090 ) == 0x00100090 ) {
int V_52 = ( V_49 >> 12 ) & 15 ;
V_47 -> V_53 [ V_52 ] = - 1 ;
V_47 -> V_54 += 4 ;
return 0 ;
}
return 1 ;
}
static T_3 F_28 ( int V_55 , void * V_56 )
{
#ifdef F_29
struct V_46 * V_47 = F_30 () ;
unsigned long V_48 = F_26 ( V_47 ) ;
unsigned long V_49 = * ( unsigned long * ) V_48 ;
char V_57 [ 128 ] ;
extern void V_58 ( const char * ) ;
sprintf ( V_57 , L_4
L_5 , V_59 , V_48 , V_49 ,
F_14 ( V_60 ) ,
F_14 ( V_61 ) & 255 ,
F_31 ( V_50 ) ) ;
V_58 ( V_57 ) ;
#endif
F_7 ( V_62 , 0xf000 ) ;
F_27 ( V_50 , 0 ) ;
F_19 ( 3 , V_51 ) ;
#ifdef F_29
if ( ( V_49 & 0x0c100000 ) == 0x04100000 ) {
int V_52 = ( V_49 >> 16 ) & 15 ;
sprintf ( V_57 , L_6 , V_52 , V_47 -> V_53 [ V_52 ] ) ;
V_58 ( V_57 ) ;
}
#endif
return V_63 ;
}
int T_2 F_32 ( int V_64 , struct V_36 * V_37 )
{
int V_65 = 0 ;
if ( V_64 == 0 ) {
V_37 -> V_66 = V_13 ;
V_65 = F_20 ( V_37 ) ;
}
return V_65 ;
}
struct V_1 * T_2 F_33 ( int V_64 , struct V_36 * V_37 )
{
return F_34 ( NULL , V_37 -> V_7 , & V_67 , V_37 ,
& V_37 -> V_43 ) ;
}
void T_2 F_35 ( void )
{
unsigned long V_30 ;
unsigned int V_68 ;
int V_65 ;
V_69 = 0x6000 ;
V_70 = 0x00100000 ;
F_36 ( 4 , F_25 , V_71 , 0 , L_7 ) ;
F_36 ( 6 , F_25 , V_71 , 0 , L_7 ) ;
F_36 ( 8 , F_25 , V_71 , 0 , L_8 ) ;
F_36 ( 10 , F_25 , V_71 , 0 , L_8 ) ;
F_11 ( & V_32 , V_30 ) ;
if ( F_37 ( V_72 ) & V_73 )
F_7 ( V_72 , 0xa05f ) ;
F_5 ( V_12 , F_6 ( V_13 ) |
V_22 | V_15 ) ;
F_7 ( V_74 , F_9 ( V_75 ) |
V_76 ) ;
F_5 ( V_16 , F_6 ( V_13 + V_21 ) |
V_22 | V_23 |
V_15 ) ;
F_7 ( V_19 , F_9 ( V_24 ) |
V_25 ) ;
F_5 ( V_77 , F_38 ( V_78 ) |
V_15 ) ;
F_7 ( V_79 , F_39 ( 0 ) ) ;
V_68 = F_37 ( V_80 ) & ~ V_81 ;
V_68 |= V_82 | V_83 ;
F_7 ( V_80 , V_68 ) ;
F_22 ( V_84 L_9 ,
F_37 ( V_85 ) , F_37 ( V_86 ) ) ;
F_7 ( V_86 , 0x0a0a ) ;
V_68 = F_37 ( V_72 ) | V_73 ;
F_7 ( V_72 , V_68 ) ;
F_27 ( V_50 , 0 ) ;
F_7 ( V_87 , F_37 ( V_87 ) | ( 1 << 10 ) ) ;
F_27 ( V_88 , 0x28 ) ;
F_19 ( 3 , V_51 ) ;
V_65 = F_40 ( V_59 , F_28 , 0 , L_10 , NULL ) ;
if ( V_65 )
F_22 ( V_40 L_11
L_12 , V_65 ) ;
F_15 ( & V_32 , V_30 ) ;
}
void T_2 F_41 ( void )
{
unsigned int V_89 ;
V_89 = V_90 |
V_91 | V_92 ;
F_7 ( V_93 , V_89 ) ;
F_27 ( V_50 , ~ 0x40 ) ;
F_27 ( V_88 , 0x68 ) ;
#if 0
ret = request_irq(IRQ_AP_LBUSTIMEOUT, lb_timeout, 0, "bus timeout", NULL);
if (ret)
printk(KERN_ERR "PCI: unable to grab local bus timeout "
"interrupt: %d\n", ret);
#endif
F_42 ( V_13 , V_78 , 0 ) ;
}
