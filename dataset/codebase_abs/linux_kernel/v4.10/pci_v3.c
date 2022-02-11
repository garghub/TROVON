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
int V_30 = F_11 ( V_2 , V_3 , V_27 , V_28 , V_29 ) ;
F_8 () ;
return V_30 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_3 , int V_27 ,
int V_28 , T_2 V_29 )
{
int V_30 = F_13 ( V_2 , V_3 , V_27 , V_28 , V_29 ) ;
F_8 () ;
return V_30 ;
}
static int T_3 F_14 ( struct V_31 * V_32 )
{
if ( F_15 ( & V_33 , & V_13 ) ) {
F_16 ( V_34 L_1
L_2 ) ;
return - V_35 ;
}
if ( F_15 ( & V_33 , & V_22 ) ) {
F_17 ( & V_13 ) ;
F_16 ( V_34 L_3
L_2 ) ;
return - V_35 ;
}
F_18 ( & V_32 -> V_36 , & V_13 , V_32 -> V_37 ) ;
F_18 ( & V_32 -> V_36 , & V_22 , V_32 -> V_37 ) ;
return 1 ;
}
static int
F_19 ( unsigned long V_38 , unsigned int V_39 , struct V_40 * V_41 )
{
unsigned long V_42 = F_20 ( V_41 ) ;
unsigned long V_43 = * ( unsigned long * ) V_42 ;
#if 0
char buf[128];
sprintf(buf, "V3 fault: addr 0x%08lx, FSR 0x%03x, PC 0x%08lx [%08lx] LBFADDR=%08x LBFCODE=%02x ISTAT=%02x\n",
addr, fsr, pc, instr, __raw_readl(ap_syscon_base + INTEGRATOR_SC_LBFADDR_OFFSET), __raw_readl(ap_syscon_base + INTEGRATOR_SC_LBFCODE_OFFSET) & 255,
v3_readb(V3_LB_ISTAT));
printk(KERN_DEBUG "%s", buf);
#endif
F_21 ( V_44 , 0 ) ;
F_22 ( 3 , V_45 + V_46 ) ;
if ( ( V_43 & 0x0c100000 ) == 0x04100000 ) {
int V_47 = ( V_43 >> 12 ) & 15 ;
unsigned long V_29 ;
if ( V_43 & 0x00400000 )
V_29 = 255 ;
else
V_29 = - 1 ;
V_41 -> V_48 [ V_47 ] = V_29 ;
V_41 -> V_49 += 4 ;
return 0 ;
}
if ( ( V_43 & 0x0e100090 ) == 0x00100090 ) {
int V_47 = ( V_43 >> 12 ) & 15 ;
V_41 -> V_48 [ V_47 ] = - 1 ;
V_41 -> V_49 += 4 ;
return 0 ;
}
return 1 ;
}
static T_4 F_23 ( int V_50 , void * V_51 )
{
#ifdef F_24
struct V_40 * V_41 = F_25 () ;
unsigned long V_42 = F_20 ( V_41 ) ;
unsigned long V_43 = * ( unsigned long * ) V_42 ;
char V_52 [ 128 ] ;
extern void V_53 ( const char * ) ;
sprintf ( V_52 , L_4
L_5 , V_50 , V_42 , V_43 ,
F_26 ( V_45 + V_54 ) ,
F_26 ( V_45 + V_55 ) & 255 ,
F_27 ( V_44 ) ) ;
V_53 ( V_52 ) ;
#endif
F_7 ( V_56 , 0xf000 ) ;
F_21 ( V_44 , 0 ) ;
F_22 ( 3 , V_45 + V_46 ) ;
#ifdef F_24
if ( ( V_43 & 0x0c100000 ) == 0x04100000 ) {
int V_47 = ( V_43 >> 16 ) & 15 ;
sprintf ( V_52 , L_6 , V_47 , V_41 -> V_48 [ V_47 ] ) ;
V_53 ( V_52 ) ;
}
#endif
return V_57 ;
}
static int T_3 F_28 ( int V_58 , struct V_31 * V_32 )
{
int V_30 = 0 ;
if ( ! V_45 )
return - V_59 ;
if ( V_58 == 0 ) {
V_32 -> V_37 = V_13 . V_14 ;
V_30 = F_14 ( V_32 ) ;
}
return V_30 ;
}
static void T_3 F_29 ( void )
{
unsigned int V_60 ;
T_5 V_61 = F_30 ( V_62 . V_14 ) ;
V_63 = 0x00100000 ;
F_31 ( 4 , F_19 , V_64 , 0 , L_7 ) ;
F_31 ( 6 , F_19 , V_64 , 0 , L_7 ) ;
F_31 ( 8 , F_19 , V_64 , 0 , L_8 ) ;
F_31 ( 10 , F_19 , V_64 , 0 , L_8 ) ;
if ( F_32 ( V_65 ) & V_66 )
F_7 ( V_65 , 0xa05f ) ;
F_5 ( V_12 , F_6 ( V_13 . V_14 ) |
V_23 | V_16 ) ;
F_7 ( V_67 , F_9 ( V_68 ) |
V_69 ) ;
F_5 ( V_17 , F_6 ( V_22 . V_14 ) |
V_23 | V_24 |
V_16 ) ;
F_7 ( V_20 , F_9 ( V_25 ) |
V_26 ) ;
F_5 ( V_70 , F_33 ( V_61 ) |
V_16 ) ;
F_7 ( V_71 , F_34 ( 0 ) ) ;
V_60 = F_32 ( V_72 ) & ~ V_73 ;
V_60 |= V_74 | V_75 ;
F_7 ( V_72 , V_60 ) ;
F_16 ( V_76 L_9 ,
F_32 ( V_77 ) , F_32 ( V_78 ) ) ;
F_7 ( V_78 , 0x0a0a ) ;
V_60 = F_32 ( V_65 ) | V_66 ;
F_7 ( V_65 , V_60 ) ;
F_21 ( V_44 , 0 ) ;
F_7 ( V_79 , F_32 ( V_79 ) | ( 1 << 10 ) ) ;
F_21 ( V_80 , 0x28 ) ;
F_22 ( 3 , V_45 + V_46 ) ;
}
static void T_3 F_35 ( void )
{
unsigned int V_81 ;
T_5 V_61 = F_30 ( V_62 . V_14 ) ;
V_81 = V_82 |
V_83 | V_84 ;
F_7 ( V_85 , V_81 ) ;
F_21 ( V_44 , ~ 0x40 ) ;
F_21 ( V_80 , 0x68 ) ;
#if 0
ret = request_irq(IRQ_AP_LBUSTIMEOUT, lb_timeout, 0, "bus timeout", NULL);
if (ret)
printk(KERN_ERR "PCI: unable to grab local bus timeout "
"interrupt: %d\n", ret);
#endif
F_36 ( V_13 . V_14 , V_61 , 0 ) ;
}
static T_6 T_3 F_37 ( struct V_86 * V_87 , T_6 * V_88 )
{
if ( * V_88 == 0 )
* V_88 = 1 ;
return F_38 ( V_87 , V_88 ) ;
}
static int T_3 F_39 ( struct V_89 * V_90 )
{
struct V_91 * V_92 = V_90 -> V_87 . V_93 ;
struct V_94 V_95 ;
struct V_96 V_97 ;
struct V_98 * V_99 ;
int V_50 , V_30 ;
V_45 = F_40 ( & V_90 -> V_87 , V_100 , 0x100 ) ;
if ( ! V_45 ) {
F_41 ( & V_90 -> V_87 , L_10 ) ;
return - V_101 ;
}
if ( ! V_92 ) {
F_41 ( & V_90 -> V_87 , L_11 ) ;
return - V_101 ;
}
if ( F_42 ( & V_95 , V_92 ) )
return - V_59 ;
V_99 = F_43 ( V_90 , V_102 , 0 ) ;
if ( ! V_99 ) {
F_41 ( & V_90 -> V_87 , L_12 ) ;
return - V_101 ;
}
V_103 = F_40 ( & V_90 -> V_87 , V_99 -> V_14 ,
F_44 ( V_99 ) ) ;
if ( ! V_103 ) {
F_41 ( & V_90 -> V_87 , L_13 ) ;
return - V_101 ;
}
V_50 = F_45 ( V_90 , 0 ) ;
if ( V_50 <= 0 ) {
F_41 ( & V_90 -> V_87 , L_14 ) ;
return - V_101 ;
}
V_30 = F_46 ( & V_90 -> V_87 , V_50 , F_23 , 0 ,
L_15 , NULL ) ;
if ( V_30 < 0 ) {
F_41 ( & V_90 -> V_87 , L_16 , V_50 , V_30 ) ;
return V_30 ;
}
F_47 (&parser, &range) {
if ( ! V_97 . V_104 ) {
V_30 = F_48 ( & V_97 , V_92 , & V_18 ) ;
V_18 . V_105 = L_17 ;
}
if ( V_97 . V_104 & V_106 ) {
V_30 = F_48 ( & V_97 , V_92 , & V_62 ) ;
V_62 . V_105 = L_18 ;
}
if ( ( V_97 . V_104 & V_102 ) &&
! ( V_97 . V_104 & V_107 ) ) {
V_68 = V_97 . V_108 ;
V_109 = V_97 . V_28 ;
V_30 = F_48 ( & V_97 , V_92 , & V_13 ) ;
V_13 . V_105 = L_19 ;
}
if ( ( V_97 . V_104 & V_102 ) &&
( V_97 . V_104 & V_107 ) ) {
V_25 = V_97 . V_108 ;
V_110 = V_97 . V_28 ;
V_30 = F_48 ( & V_97 , V_92 , & V_22 ) ;
V_22 . V_105 = L_20 ;
}
if ( V_30 < 0 ) {
F_41 ( & V_90 -> V_87 , L_21 ) ;
return V_30 ;
}
}
V_111 . V_112 = V_113 ;
F_49 ( & V_90 -> V_87 , & V_111 ) ;
return 0 ;
}
static int T_3 F_50 ( void )
{
return F_51 ( & V_114 , F_39 ) ;
}
int T_3 F_52 ( void )
{
F_53 ( V_115 , F_54 ( V_115 ) ) ;
V_116 = ( unsigned long ) V_117 ;
F_55 ( F_56 ( V_118 ) ) ;
return 0 ;
}
