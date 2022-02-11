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
V_67 = 0x00100000 ;
F_34 ( 4 , F_25 , V_68 , 0 , L_7 ) ;
F_34 ( 6 , F_25 , V_68 , 0 , L_7 ) ;
F_34 ( 8 , F_25 , V_68 , 0 , L_8 ) ;
F_34 ( 10 , F_25 , V_68 , 0 , L_8 ) ;
F_11 ( & V_33 , V_31 ) ;
if ( F_35 ( V_69 ) & V_70 )
F_7 ( V_69 , 0xa05f ) ;
F_5 ( V_12 , F_6 ( V_13 . V_14 ) |
V_23 | V_16 ) ;
F_7 ( V_71 , F_9 ( V_72 ) |
V_73 ) ;
F_5 ( V_17 , F_6 ( V_22 . V_14 ) |
V_23 | V_24 |
V_16 ) ;
F_7 ( V_20 , F_9 ( V_25 ) |
V_26 ) ;
F_5 ( V_74 , F_36 ( V_75 . V_14 ) |
V_16 ) ;
F_7 ( V_76 , F_37 ( 0 ) ) ;
V_66 = F_35 ( V_77 ) & ~ V_78 ;
V_66 |= V_79 | V_80 ;
F_7 ( V_77 , V_66 ) ;
F_22 ( V_81 L_9 ,
F_35 ( V_82 ) , F_35 ( V_83 ) ) ;
F_7 ( V_83 , 0x0a0a ) ;
V_66 = F_35 ( V_69 ) | V_70 ;
F_7 ( V_69 , V_66 ) ;
F_27 ( V_49 , 0 ) ;
F_7 ( V_84 , F_35 ( V_84 ) | ( 1 << 10 ) ) ;
F_27 ( V_85 , 0x28 ) ;
F_19 ( 3 , V_50 + V_51 ) ;
F_15 ( & V_33 , V_31 ) ;
}
static void T_3 F_38 ( void )
{
unsigned int V_86 ;
V_86 = V_87 |
V_88 | V_89 ;
F_7 ( V_90 , V_86 ) ;
F_27 ( V_49 , ~ 0x40 ) ;
F_27 ( V_85 , 0x68 ) ;
#if 0
ret = request_irq(IRQ_AP_LBUSTIMEOUT, lb_timeout, 0, "bus timeout", NULL);
if (ret)
printk(KERN_ERR "PCI: unable to grab local bus timeout "
"interrupt: %d\n", ret);
#endif
F_39 ( V_13 . V_14 , V_75 . V_14 , 0 ) ;
}
static V_35 T_3 F_40 ( struct V_91 * V_92 , V_35 * V_93 )
{
if ( * V_93 == 0 )
* V_93 = 1 ;
return F_41 ( V_92 , V_93 ) ;
}
static int T_3 F_42 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_92 . V_98 ;
struct V_99 V_100 ;
struct V_101 V_102 ;
struct V_103 * V_104 ;
int V_55 , V_64 ;
V_50 = F_43 ( & V_95 -> V_92 , V_105 , 0x100 ) ;
if ( ! V_50 ) {
F_44 ( & V_95 -> V_92 , L_10 ) ;
return - V_106 ;
}
if ( ! V_97 ) {
F_44 ( & V_95 -> V_92 , L_11 ) ;
return - V_106 ;
}
if ( F_45 ( & V_100 , V_97 ) )
return - V_65 ;
V_104 = F_46 ( V_95 , V_107 , 0 ) ;
if ( ! V_104 ) {
F_44 ( & V_95 -> V_92 , L_12 ) ;
return - V_106 ;
}
V_108 = F_43 ( & V_95 -> V_92 , V_104 -> V_14 ,
F_47 ( V_104 ) ) ;
if ( ! V_108 ) {
F_44 ( & V_95 -> V_92 , L_13 ) ;
return - V_106 ;
}
V_55 = F_48 ( V_95 , 0 ) ;
if ( V_55 <= 0 ) {
F_44 ( & V_95 -> V_92 , L_14 ) ;
return - V_106 ;
}
V_64 = F_49 ( & V_95 -> V_92 , V_55 , F_28 , 0 ,
L_15 , NULL ) ;
if ( V_64 < 0 ) {
F_44 ( & V_95 -> V_92 , L_16 , V_55 , V_64 ) ;
return V_64 ;
}
F_50 (&parser, &range) {
if ( ! V_102 . V_31 ) {
F_51 ( & V_102 , V_97 , & V_18 ) ;
V_18 . V_109 = L_17 ;
}
if ( V_102 . V_31 & V_110 ) {
F_51 ( & V_102 , V_97 , & V_75 ) ;
V_75 . V_109 = L_18 ;
}
if ( ( V_102 . V_31 & V_107 ) &&
! ( V_102 . V_31 & V_111 ) ) {
V_72 = V_102 . V_112 ;
V_113 = V_102 . V_28 ;
F_51 ( & V_102 , V_97 , & V_13 ) ;
V_13 . V_109 = L_19 ;
}
if ( ( V_102 . V_31 & V_107 ) &&
( V_102 . V_31 & V_111 ) ) {
V_25 = V_102 . V_112 ;
V_114 = V_102 . V_28 ;
F_51 ( & V_102 , V_97 , & V_22 ) ;
V_22 . V_109 = L_20 ;
}
}
if ( ! V_18 . V_14 || ! V_75 . V_14 ||
! V_13 . V_14 || ! V_22 . V_14 ) {
F_44 ( & V_95 -> V_92 , L_21 ) ;
return - V_65 ;
}
V_115 . V_116 = V_117 ;
F_52 ( & V_95 -> V_92 , & V_115 ) ;
return 0 ;
}
static int T_3 F_53 ( void )
{
return F_54 ( & V_118 , F_42 ) ;
}
int T_3 F_55 ( void )
{
F_56 ( V_119 , F_57 ( V_119 ) ) ;
V_120 = ( unsigned long ) V_121 ;
F_58 ( F_59 ( V_122 ) ) ;
return 0 ;
}
