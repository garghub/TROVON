static void T_1 * F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 )
{
unsigned int V_5 , V_6 , V_7 ;
V_7 = V_2 -> V_8 ;
F_2 ( V_4 > 255 ) ;
F_2 ( V_7 > 255 ) ;
F_2 ( V_3 > 255 ) ;
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
F_5 ( V_12 , F_6 ( V_13 . V_14 ) |
V_15 | V_16 ) ;
F_5 ( V_17 , F_6 ( V_18 . V_14 ) |
V_19 | V_16 ) ;
F_7 ( V_20 , V_6 ) ;
return V_21 + V_5 + V_4 ;
}
static void F_8 ( void )
{
F_5 ( V_17 , F_6 ( V_22 . V_14 ) |
V_23 | V_24 |
V_16 ) ;
F_7 ( V_20 , F_9 ( V_25 ) |
V_26 ) ;
F_5 ( V_12 , F_6 ( V_13 . V_14 ) |
V_23 | V_16 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 , int V_27 ,
int V_28 , T_2 * V_29 )
{
void T_1 * V_30 ;
unsigned long V_31 ;
T_2 V_32 ;
F_11 ( & V_33 , V_31 ) ;
V_30 = F_1 ( V_2 , V_3 , V_27 ) ;
switch ( V_28 ) {
case 1 :
V_32 = F_12 ( V_30 ) ;
break;
case 2 :
V_32 = F_13 ( V_30 ) ;
break;
default:
V_32 = F_14 ( V_30 ) ;
break;
}
F_8 () ;
F_15 ( & V_33 , V_31 ) ;
* V_29 = V_32 ;
return V_34 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_3 , int V_27 ,
int V_28 , T_2 V_29 )
{
void T_1 * V_30 ;
unsigned long V_31 ;
F_11 ( & V_33 , V_31 ) ;
V_30 = F_1 ( V_2 , V_3 , V_27 ) ;
switch ( V_28 ) {
case 1 :
F_17 ( ( V_35 ) V_29 , V_30 ) ;
F_12 ( V_30 ) ;
break;
case 2 :
F_18 ( ( V_36 ) V_29 , V_30 ) ;
F_13 ( V_30 ) ;
break;
case 4 :
F_19 ( V_29 , V_30 ) ;
F_14 ( V_30 ) ;
break;
}
F_8 () ;
F_15 ( & V_33 , V_31 ) ;
return V_34 ;
}
static int T_3 F_20 ( struct V_37 * V_38 )
{
if ( F_21 ( & V_39 , & V_13 ) ) {
F_22 ( V_40 L_1
L_2 ) ;
return - V_41 ;
}
if ( F_21 ( & V_39 , & V_22 ) ) {
F_23 ( & V_13 ) ;
F_22 ( V_40 L_3
L_2 ) ;
return - V_41 ;
}
F_24 ( & V_38 -> V_42 , & V_13 , V_38 -> V_43 ) ;
F_24 ( & V_38 -> V_42 , & V_22 , V_38 -> V_43 ) ;
return 1 ;
}
static int
F_25 ( unsigned long V_30 , unsigned int V_44 , struct V_45 * V_46 )
{
unsigned long V_47 = F_26 ( V_46 ) ;
unsigned long V_48 = * ( unsigned long * ) V_47 ;
#if 0
char buf[128];
sprintf(buf, "V3 fault: addr 0x%08lx, FSR 0x%03x, PC 0x%08lx [%08lx] LBFADDR=%08x LBFCODE=%02x ISTAT=%02x\n",
addr, fsr, pc, instr, __raw_readl(ap_syscon_base + INTEGRATOR_SC_LBFADDR_OFFSET), __raw_readl(ap_syscon_base + INTEGRATOR_SC_LBFCODE_OFFSET) & 255,
v3_readb(V3_LB_ISTAT));
printk(KERN_DEBUG "%s", buf);
#endif
F_27 ( V_49 , 0 ) ;
F_19 ( 3 , V_50 + V_51 ) ;
if ( ( V_48 & 0x0c100000 ) == 0x04100000 ) {
int V_52 = ( V_48 >> 12 ) & 15 ;
unsigned long V_29 ;
if ( V_48 & 0x00400000 )
V_29 = 255 ;
else
V_29 = - 1 ;
V_46 -> V_53 [ V_52 ] = V_29 ;
V_46 -> V_54 += 4 ;
return 0 ;
}
if ( ( V_48 & 0x0e100090 ) == 0x00100090 ) {
int V_52 = ( V_48 >> 12 ) & 15 ;
V_46 -> V_53 [ V_52 ] = - 1 ;
V_46 -> V_54 += 4 ;
return 0 ;
}
return 1 ;
}
static T_4 F_28 ( int V_55 , void * V_56 )
{
#ifdef F_29
struct V_45 * V_46 = F_30 () ;
unsigned long V_47 = F_26 ( V_46 ) ;
unsigned long V_48 = * ( unsigned long * ) V_47 ;
char V_57 [ 128 ] ;
extern void V_58 ( const char * ) ;
sprintf ( V_57 , L_4
L_5 , V_55 , V_47 , V_48 ,
F_14 ( V_50 + V_59 ) ,
F_14 ( V_50 + V_60 ) & 255 ,
F_31 ( V_49 ) ) ;
V_58 ( V_57 ) ;
#endif
F_7 ( V_61 , 0xf000 ) ;
F_27 ( V_49 , 0 ) ;
F_19 ( 3 , V_50 + V_51 ) ;
#ifdef F_29
if ( ( V_48 & 0x0c100000 ) == 0x04100000 ) {
int V_52 = ( V_48 >> 16 ) & 15 ;
sprintf ( V_57 , L_6 , V_52 , V_46 -> V_53 [ V_52 ] ) ;
V_58 ( V_57 ) ;
}
#endif
return V_62 ;
}
static int T_3 F_32 ( int V_63 , struct V_37 * V_38 )
{
int V_64 = 0 ;
if ( ! V_50 )
return - V_65 ;
if ( V_63 == 0 ) {
V_38 -> V_43 = V_13 . V_14 ;
V_64 = F_20 ( V_38 ) ;
}
return V_64 ;
}
static void T_3 F_33 ( void )
{
unsigned long V_31 ;
unsigned int V_66 ;
T_5 V_67 = F_34 ( V_68 . V_14 ) ;
V_69 = 0x00100000 ;
F_35 ( 4 , F_25 , V_70 , 0 , L_7 ) ;
F_35 ( 6 , F_25 , V_70 , 0 , L_7 ) ;
F_35 ( 8 , F_25 , V_70 , 0 , L_8 ) ;
F_35 ( 10 , F_25 , V_70 , 0 , L_8 ) ;
F_11 ( & V_33 , V_31 ) ;
if ( F_36 ( V_71 ) & V_72 )
F_7 ( V_71 , 0xa05f ) ;
F_5 ( V_12 , F_6 ( V_13 . V_14 ) |
V_23 | V_16 ) ;
F_7 ( V_73 , F_9 ( V_74 ) |
V_75 ) ;
F_5 ( V_17 , F_6 ( V_22 . V_14 ) |
V_23 | V_24 |
V_16 ) ;
F_7 ( V_20 , F_9 ( V_25 ) |
V_26 ) ;
F_5 ( V_76 , F_37 ( V_67 ) |
V_16 ) ;
F_7 ( V_77 , F_38 ( 0 ) ) ;
V_66 = F_36 ( V_78 ) & ~ V_79 ;
V_66 |= V_80 | V_81 ;
F_7 ( V_78 , V_66 ) ;
F_22 ( V_82 L_9 ,
F_36 ( V_83 ) , F_36 ( V_84 ) ) ;
F_7 ( V_84 , 0x0a0a ) ;
V_66 = F_36 ( V_71 ) | V_72 ;
F_7 ( V_71 , V_66 ) ;
F_27 ( V_49 , 0 ) ;
F_7 ( V_85 , F_36 ( V_85 ) | ( 1 << 10 ) ) ;
F_27 ( V_86 , 0x28 ) ;
F_19 ( 3 , V_50 + V_51 ) ;
F_15 ( & V_33 , V_31 ) ;
}
static void T_3 F_39 ( void )
{
unsigned int V_87 ;
T_5 V_67 = F_34 ( V_68 . V_14 ) ;
V_87 = V_88 |
V_89 | V_90 ;
F_7 ( V_91 , V_87 ) ;
F_27 ( V_49 , ~ 0x40 ) ;
F_27 ( V_86 , 0x68 ) ;
#if 0
ret = request_irq(IRQ_AP_LBUSTIMEOUT, lb_timeout, 0, "bus timeout", NULL);
if (ret)
printk(KERN_ERR "PCI: unable to grab local bus timeout "
"interrupt: %d\n", ret);
#endif
F_40 ( V_13 . V_14 , V_67 , 0 ) ;
}
static V_35 T_3 F_41 ( struct V_92 * V_93 , V_35 * V_94 )
{
if ( * V_94 == 0 )
* V_94 = 1 ;
return F_42 ( V_93 , V_94 ) ;
}
static int T_3 F_43 ( struct V_95 * V_96 )
{
struct V_97 * V_98 = V_96 -> V_93 . V_99 ;
struct V_100 V_101 ;
struct V_102 V_103 ;
struct V_104 * V_105 ;
int V_55 , V_64 ;
V_50 = F_44 ( & V_96 -> V_93 , V_106 , 0x100 ) ;
if ( ! V_50 ) {
F_45 ( & V_96 -> V_93 , L_10 ) ;
return - V_107 ;
}
if ( ! V_98 ) {
F_45 ( & V_96 -> V_93 , L_11 ) ;
return - V_107 ;
}
if ( F_46 ( & V_101 , V_98 ) )
return - V_65 ;
V_105 = F_47 ( V_96 , V_108 , 0 ) ;
if ( ! V_105 ) {
F_45 ( & V_96 -> V_93 , L_12 ) ;
return - V_107 ;
}
V_109 = F_44 ( & V_96 -> V_93 , V_105 -> V_14 ,
F_48 ( V_105 ) ) ;
if ( ! V_109 ) {
F_45 ( & V_96 -> V_93 , L_13 ) ;
return - V_107 ;
}
V_55 = F_49 ( V_96 , 0 ) ;
if ( V_55 <= 0 ) {
F_45 ( & V_96 -> V_93 , L_14 ) ;
return - V_107 ;
}
V_64 = F_50 ( & V_96 -> V_93 , V_55 , F_28 , 0 ,
L_15 , NULL ) ;
if ( V_64 < 0 ) {
F_45 ( & V_96 -> V_93 , L_16 , V_55 , V_64 ) ;
return V_64 ;
}
F_51 (&parser, &range) {
if ( ! V_103 . V_31 ) {
V_64 = F_52 ( & V_103 , V_98 , & V_18 ) ;
V_18 . V_110 = L_17 ;
}
if ( V_103 . V_31 & V_111 ) {
V_64 = F_52 ( & V_103 , V_98 , & V_68 ) ;
V_68 . V_110 = L_18 ;
}
if ( ( V_103 . V_31 & V_108 ) &&
! ( V_103 . V_31 & V_112 ) ) {
V_74 = V_103 . V_113 ;
V_114 = V_103 . V_28 ;
V_64 = F_52 ( & V_103 , V_98 , & V_13 ) ;
V_13 . V_110 = L_19 ;
}
if ( ( V_103 . V_31 & V_108 ) &&
( V_103 . V_31 & V_112 ) ) {
V_25 = V_103 . V_113 ;
V_115 = V_103 . V_28 ;
V_64 = F_52 ( & V_103 , V_98 , & V_22 ) ;
V_22 . V_110 = L_20 ;
}
if ( V_64 < 0 ) {
F_45 ( & V_96 -> V_93 , L_21 ) ;
return V_64 ;
}
}
V_116 . V_117 = V_118 ;
F_53 ( & V_96 -> V_93 , & V_116 ) ;
return 0 ;
}
static int T_3 F_54 ( void )
{
return F_55 ( & V_119 , F_43 ) ;
}
int T_3 F_56 ( void )
{
F_57 ( V_120 , F_58 ( V_120 ) ) ;
V_121 = ( unsigned long ) V_122 ;
F_59 ( F_60 ( V_123 ) ) ;
return 0 ;
}
