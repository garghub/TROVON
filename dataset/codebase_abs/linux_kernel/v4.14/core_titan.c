static inline volatile unsigned long *
F_1 ( int V_1 )
{
return ( volatile unsigned long * ) ( V_2 + ( V_1 << 6 ) ) ;
}
static inline T_1
F_2 ( int V_1 , T_1 V_3 )
{
volatile unsigned long * V_4 = F_1 ( V_1 ) ;
return ( T_1 ) ( * V_4 & 0xff ) ;
}
static inline void
F_3 ( int V_1 , T_1 V_3 )
{
volatile unsigned long * V_4 = F_1 ( V_1 ) ;
* V_4 = ( unsigned long ) V_3 ;
}
static int
F_4 ( struct V_5 * V_6 , unsigned int V_7 , int V_8 ,
unsigned long * V_9 , unsigned char * V_10 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
unsigned long V_14 ;
T_1 V_15 = V_6 -> V_16 ;
F_5 ( ( L_1
L_2 ,
V_15 , V_7 , V_8 , V_9 , V_10 ) ) ;
if ( ! V_6 -> V_17 )
V_15 = 0 ;
* V_10 = ( V_15 != 0 ) ;
V_14 = ( V_15 << 16 ) | ( V_7 << 8 ) | V_8 ;
V_14 |= V_12 -> V_18 ;
* V_9 = V_14 ;
F_5 ( ( L_3 , V_14 ) ) ;
return 0 ;
}
static int
F_6 ( struct V_5 * V_15 , unsigned int V_19 , int V_8 ,
int V_20 , T_2 * V_3 )
{
unsigned long V_14 ;
unsigned char V_10 ;
if ( F_4 ( V_15 , V_19 , V_8 , & V_14 , & V_10 ) )
return V_21 ;
switch ( V_20 ) {
case 1 :
* V_3 = F_7 ( * ( V_22 ) V_14 ) ;
break;
case 2 :
* V_3 = F_8 ( * ( V_23 ) V_14 ) ;
break;
case 4 :
* V_3 = * ( V_24 ) V_14 ;
break;
}
return V_25 ;
}
static int
F_9 ( struct V_5 * V_15 , unsigned int V_19 , int V_8 ,
int V_20 , T_2 V_3 )
{
unsigned long V_14 ;
unsigned char V_10 ;
if ( F_4 ( V_15 , V_19 , V_8 , & V_14 , & V_10 ) )
return V_21 ;
switch ( V_20 ) {
case 1 :
F_10 ( V_3 , * ( V_22 ) V_14 ) ;
F_11 () ;
F_7 ( * ( V_22 ) V_14 ) ;
break;
case 2 :
F_12 ( V_3 , * ( V_23 ) V_14 ) ;
F_11 () ;
F_8 ( * ( V_23 ) V_14 ) ;
break;
case 4 :
* ( V_24 ) V_14 = V_3 ;
F_11 () ;
* ( V_24 ) V_14 ;
break;
}
return V_25 ;
}
void
F_13 ( struct V_11 * V_12 , T_3 V_26 , T_3 V_27 )
{
T_4 * V_28 =
( V_12 -> V_29 & 1 ) ? V_30 : V_31 ;
T_5 * V_32 ;
volatile unsigned long * V_33 ;
unsigned long V_3 ;
V_32 = & V_28 -> V_34 ;
if ( V_12 -> V_29 & 2 )
V_32 = & V_28 -> V_35 ;
V_33 = & V_32 -> V_36 . V_37 . V_38 . V_33 ;
if ( ( ( V_26 ^ V_27 ) & 0xffff0000 ) == 0 )
V_33 = & V_32 -> V_36 . V_37 . V_39 . V_33 ;
V_3 = ( V_26 & 0xffff0000 ) >> 12 ;
F_14 () ;
* V_33 = V_3 ;
F_11 () ;
* V_33 ;
}
static int
F_15 ( T_5 * V_32 )
{
union V_40 V_41 ;
V_41 . V_42 = V_32 -> V_41 . V_33 ;
return V_41 . V_43 . V_44 ;
}
static void T_6
F_16 ( T_5 * V_32 , int V_29 )
{
struct V_11 * V_12 ;
V_12 = F_17 () ;
if ( V_29 == 0 )
V_45 = V_12 ;
V_12 -> V_46 = F_18 () ;
V_12 -> V_47 = F_18 () ;
V_12 -> V_48 = 0 ;
V_12 -> V_49 = 0 ;
V_12 -> V_50
= ( F_19 ( V_29 ) & 0xffffffffffUL ) | 0x80000000000UL ;
V_12 -> V_51
= ( F_20 ( V_29 ) & 0xffffffffffUL ) | 0x80000000000UL ;
V_12 -> V_18 = F_21 ( V_29 ) ;
V_12 -> V_29 = V_29 ;
V_12 -> V_46 -> V_26 = F_20 ( V_29 ) - V_52 ;
V_12 -> V_46 -> V_27 = V_12 -> V_46 -> V_26 + V_53 - 1 ;
V_12 -> V_46 -> V_54 = V_55 [ V_29 ] ;
V_12 -> V_46 -> V_56 = V_57 ;
V_12 -> V_47 -> V_26 = F_19 ( V_29 ) - V_58 ;
V_12 -> V_47 -> V_27 = V_12 -> V_47 -> V_26 + 0xffffffff ;
V_12 -> V_47 -> V_54 = V_59 [ V_29 ] ;
V_12 -> V_47 -> V_56 = V_60 ;
if ( F_22 ( & V_61 , V_12 -> V_46 ) < 0 )
F_23 ( V_62 L_4 , V_29 ) ;
if ( F_22 ( & V_63 , V_12 -> V_47 ) < 0 )
F_23 ( V_62 L_5 , V_29 ) ;
V_64 [ V_29 ] . V_65 [ 0 ] = V_32 -> V_65 [ 0 ] . V_33 ;
V_64 [ V_29 ] . V_66 [ 0 ] = V_32 -> V_66 [ 0 ] . V_33 ;
V_64 [ V_29 ] . V_67 [ 0 ] = V_32 -> V_67 [ 0 ] . V_33 ;
V_64 [ V_29 ] . V_65 [ 1 ] = V_32 -> V_65 [ 1 ] . V_33 ;
V_64 [ V_29 ] . V_66 [ 1 ] = V_32 -> V_66 [ 1 ] . V_33 ;
V_64 [ V_29 ] . V_67 [ 1 ] = V_32 -> V_67 [ 1 ] . V_33 ;
V_64 [ V_29 ] . V_65 [ 2 ] = V_32 -> V_65 [ 2 ] . V_33 ;
V_64 [ V_29 ] . V_66 [ 2 ] = V_32 -> V_66 [ 2 ] . V_33 ;
V_64 [ V_29 ] . V_67 [ 2 ] = V_32 -> V_67 [ 2 ] . V_33 ;
V_64 [ V_29 ] . V_65 [ 3 ] = V_32 -> V_65 [ 3 ] . V_33 ;
V_64 [ V_29 ] . V_66 [ 3 ] = V_32 -> V_66 [ 3 ] . V_33 ;
V_64 [ V_29 ] . V_67 [ 3 ] = V_32 -> V_67 [ 3 ] . V_33 ;
V_12 -> V_68 = F_24 ( V_12 , 0x00800000 , 0x00800000 , 0 ) ;
V_12 -> V_68 -> V_69 = 8 ;
V_12 -> V_70 = F_24 ( V_12 , 0xc0000000 , 0x40000000 , 0 ) ;
V_12 -> V_70 -> V_69 = 4 ;
V_32 -> V_65 [ 0 ] . V_33 = V_12 -> V_68 -> V_71 | 3 ;
V_32 -> V_66 [ 0 ] . V_33 = ( V_12 -> V_68 -> V_20 - 1 ) & 0xfff00000 ;
V_32 -> V_67 [ 0 ] . V_33 = F_25 ( V_12 -> V_68 -> V_72 ) ;
V_32 -> V_65 [ 1 ] . V_33 = V_73 | 1 ;
V_32 -> V_66 [ 1 ] . V_33 = ( V_74 - 1 ) & 0xfff00000 ;
V_32 -> V_67 [ 1 ] . V_33 = 0 ;
V_32 -> V_65 [ 2 ] . V_33 = V_12 -> V_70 -> V_71 | 3 ;
V_32 -> V_66 [ 2 ] . V_33 = ( V_12 -> V_70 -> V_20 - 1 ) & 0xfff00000 ;
V_32 -> V_67 [ 2 ] . V_33 = F_25 ( V_12 -> V_70 -> V_72 ) ;
V_32 -> V_65 [ 3 ] . V_33 = 0 ;
V_32 -> V_41 . V_33 |= V_75 ;
if ( F_15 ( V_32 ) )
V_32 -> V_36 . V_76 . V_77 . V_33 = V_73 ;
F_13 ( V_12 , 0 , - 1 ) ;
}
static void T_6
F_26 ( T_4 * V_78 , T_4 * V_79 )
{
V_80 = V_81 -> V_82 . V_33 & 1L << 14 ;
F_16 ( & V_78 -> V_34 , 0 ) ;
if ( V_80 )
F_16 ( & V_79 -> V_34 , 1 ) ;
F_16 ( & V_78 -> V_35 , 2 ) ;
if ( V_80 )
F_16 ( & V_79 -> V_35 , 3 ) ;
}
void T_6
F_27 ( void )
{
#if 0
printk("%s: titan_init_arch()\n", __func__);
printk("%s: CChip registers:\n", __func__);
printk("%s: CSR_CSC 0x%lx\n", __func__, TITAN_cchip->csc.csr);
printk("%s: CSR_MTR 0x%lx\n", __func__, TITAN_cchip->mtr.csr);
printk("%s: CSR_MISC 0x%lx\n", __func__, TITAN_cchip->misc.csr);
printk("%s: CSR_DIM0 0x%lx\n", __func__, TITAN_cchip->dim0.csr);
printk("%s: CSR_DIM1 0x%lx\n", __func__, TITAN_cchip->dim1.csr);
printk("%s: CSR_DIR0 0x%lx\n", __func__, TITAN_cchip->dir0.csr);
printk("%s: CSR_DIR1 0x%lx\n", __func__, TITAN_cchip->dir1.csr);
printk("%s: CSR_DRIR 0x%lx\n", __func__, TITAN_cchip->drir.csr);
printk("%s: DChip registers:\n", __func__);
printk("%s: CSR_DSC 0x%lx\n", __func__, TITAN_dchip->dsc.csr);
printk("%s: CSR_STR 0x%lx\n", __func__, TITAN_dchip->str.csr);
printk("%s: CSR_DREV 0x%lx\n", __func__, TITAN_dchip->drev.csr);
#endif
V_83 = F_28 () ;
V_61 . V_27 = ~ 0UL ;
V_63 . V_27 = ~ 0UL ;
V_73 = 0x80000000 ;
V_74 = 0x40000000 ;
F_26 ( V_31 , V_30 ) ;
F_29 () ;
}
static void
F_30 ( T_5 * V_32 , int V_29 )
{
V_32 -> V_65 [ 0 ] . V_33 = V_64 [ V_29 ] . V_65 [ 0 ] ;
V_32 -> V_66 [ 0 ] . V_33 = V_64 [ V_29 ] . V_66 [ 0 ] ;
V_32 -> V_67 [ 0 ] . V_33 = V_64 [ V_29 ] . V_67 [ 0 ] ;
V_32 -> V_65 [ 1 ] . V_33 = V_64 [ V_29 ] . V_65 [ 1 ] ;
V_32 -> V_66 [ 1 ] . V_33 = V_64 [ V_29 ] . V_66 [ 1 ] ;
V_32 -> V_67 [ 1 ] . V_33 = V_64 [ V_29 ] . V_67 [ 1 ] ;
V_32 -> V_65 [ 2 ] . V_33 = V_64 [ V_29 ] . V_65 [ 2 ] ;
V_32 -> V_66 [ 2 ] . V_33 = V_64 [ V_29 ] . V_66 [ 2 ] ;
V_32 -> V_67 [ 2 ] . V_33 = V_64 [ V_29 ] . V_67 [ 2 ] ;
V_32 -> V_65 [ 3 ] . V_33 = V_64 [ V_29 ] . V_65 [ 3 ] ;
V_32 -> V_66 [ 3 ] . V_33 = V_64 [ V_29 ] . V_66 [ 3 ] ;
V_32 -> V_67 [ 3 ] . V_33 = V_64 [ V_29 ] . V_67 [ 3 ] ;
}
static void
F_31 ( T_4 * V_78 , T_4 * V_79 )
{
if ( V_80 ) {
F_30 ( & V_79 -> V_34 , 1 ) ;
F_30 ( & V_79 -> V_35 , 3 ) ;
}
F_30 ( & V_78 -> V_34 , 0 ) ;
F_30 ( & V_78 -> V_35 , 2 ) ;
}
void
F_32 ( int V_84 )
{
F_31 ( V_31 , V_30 ) ;
}
void T_7 *
F_33 ( unsigned long V_14 )
{
F_34 ( V_14 ) ;
return ( void T_7 * ) ( V_14 + V_52 ) ;
}
void T_7 *
F_35 ( unsigned long V_14 , unsigned long V_20 )
{
int V_85 = ( V_14 & V_86 ) >> V_87 ;
unsigned long V_88 = V_14 & ~ V_86 ;
unsigned long V_89 = V_88 + V_20 - 1 ;
struct V_11 * V_12 ;
struct V_90 * V_91 ;
unsigned long V_92 ;
unsigned long * V_72 ;
unsigned long V_93 ;
#ifdef F_36
if ( V_94 && F_37 ( V_14 ) ) {
V_85 = V_94 -> V_29 ;
V_14 += V_94 -> V_47 -> V_26 ;
}
#endif
for ( V_12 = V_95 ; V_12 ; V_12 = V_12 -> V_96 )
if ( V_12 -> V_29 == V_85 )
break;
if ( ! V_12 )
return NULL ;
if ( ( V_88 >= V_73 ) &&
( ( V_88 + V_20 - 1 ) < V_73 + V_74 ) ) {
V_92 = V_14 - V_73 + V_58 ;
return ( void T_7 * ) V_92 ;
}
if ( V_12 -> V_70 &&
V_88 >= ( unsigned long ) V_12 -> V_70 -> V_71 &&
V_89 < ( unsigned long ) V_12 -> V_70 -> V_71 + V_12 -> V_70 -> V_20 ) {
V_88 -= V_12 -> V_70 -> V_71 ;
V_89 -= V_12 -> V_70 -> V_71 ;
V_88 &= V_97 ;
V_20 = F_38 ( V_89 ) - V_88 ;
V_91 = F_39 ( V_20 , V_98 ) ;
if ( ! V_91 ) {
F_23 ( L_6 ) ;
return NULL ;
}
V_72 = V_12 -> V_70 -> V_72 ;
for ( V_92 = ( unsigned long ) V_91 -> V_14 ;
V_88 <= V_89 ;
V_88 += V_99 , V_92 += V_99 ) {
V_93 = V_72 [ V_88 >> V_100 ] ;
if ( ! ( V_93 & 1 ) ) {
F_23 ( L_7 ) ;
F_40 ( V_91 -> V_14 ) ;
return NULL ;
}
V_93 >>= 1 ;
if ( F_41 ( V_92 ,
V_93 << V_100 ,
V_99 , 0 ) ) {
F_23 ( L_8 ) ;
F_40 ( V_91 -> V_14 ) ;
return NULL ;
}
}
F_42 () ;
V_92 = ( unsigned long ) V_91 -> V_14 + ( V_14 & ~ V_97 ) ;
return ( void T_7 * ) V_92 ;
}
return ( void T_7 * ) ( V_14 + V_58 ) ;
}
void
F_43 ( volatile void T_7 * V_101 )
{
unsigned long V_14 = ( unsigned long ) V_101 ;
if ( V_14 >= V_102 )
F_40 ( ( void * ) ( V_97 & V_14 ) ) ;
}
int
F_44 ( const volatile void T_7 * V_101 )
{
unsigned long V_14 = ( unsigned long ) V_101 ;
if ( V_14 >= V_102 )
return 1 ;
else
return ( V_14 & 0x100000000UL ) == 0 ;
}
static int
F_45 ( T_8 * V_103 )
{
struct V_104 * V_105 ;
if ( ! V_106 )
return - V_107 ;
V_105 = F_46 ( sizeof( struct V_104 ) , V_108 ) ;
if ( V_105 == NULL )
return - V_107 ;
V_105 -> V_109 = V_103 -> V_12 -> V_70 ;
V_105 -> V_110 = V_106 / V_99 ;
V_105 -> V_111 = F_47 ( V_105 -> V_109 , V_105 -> V_110 ,
V_105 -> V_110 - 1 ) ;
if ( V_105 -> V_111 < 0 ) {
F_23 ( V_62 L_9 ) ;
F_48 ( V_105 ) ;
return - V_107 ;
}
V_103 -> V_112 . V_113 =
V_105 -> V_109 -> V_71 + V_105 -> V_111 * V_99 ;
V_103 -> V_112 . V_20 = V_105 -> V_110 * V_99 ;
V_103 -> V_112 . V_13 = V_105 ;
return 0 ;
}
static void
F_49 ( T_8 * V_103 )
{
struct V_104 * V_105 = V_103 -> V_112 . V_13 ;
int V_114 ;
V_114 = F_50 ( V_105 -> V_109 , V_105 -> V_111 , V_105 -> V_110 ) ;
if ( V_114 == - V_115 ) {
F_23 ( V_116
L_10 ) ;
F_51 ( V_105 -> V_109 , V_105 -> V_111 , V_105 -> V_110 ) ;
V_114 = F_50 ( V_105 -> V_109 , V_105 -> V_111 ,
V_105 -> V_110 ) ;
}
if ( V_114 < 0 )
F_23 ( V_62 L_11 ) ;
F_48 ( V_105 ) ;
F_48 ( V_103 ) ;
}
static int
F_52 ( T_8 * V_103 )
{
union V_40 V_41 ;
T_5 * V_32 = V_103 -> V_117 ;
V_41 . V_42 = V_32 -> V_41 . V_33 ;
V_41 . V_43 . V_118 = V_103 -> V_84 . V_119 . V_120 ;
V_41 . V_43 . V_121 = 0 ;
if ( V_103 -> V_84 . V_119 . V_122 & 2 )
V_41 . V_43 . V_121 = 1 ;
#if 0
if (agp->mode.bits.rate & 4)
pctl.pctl_r_bits.apctl_v_agp_rate = 2;
#endif
V_41 . V_43 . V_123 = 2 ;
V_41 . V_43 . V_124 = 7 ;
V_41 . V_43 . V_125 = V_103 -> V_84 . V_119 . V_126 ;
F_23 ( L_12 ,
1 << V_41 . V_43 . V_121 ,
V_41 . V_43 . V_118 ? L_13 : L_14 ) ;
V_32 -> V_41 . V_33 = V_41 . V_42 ;
F_53 ( 100 ) ;
return 0 ;
}
static int
F_54 ( T_8 * V_103 , T_9 V_111 , struct V_127 * V_128 )
{
struct V_104 * V_105 = V_103 -> V_112 . V_13 ;
return F_55 ( V_105 -> V_109 , V_105 -> V_111 + V_111 ,
V_128 -> V_129 , V_128 -> V_130 ) ;
}
static int
F_56 ( T_8 * V_103 , T_9 V_111 , struct V_127 * V_128 )
{
struct V_104 * V_105 = V_103 -> V_112 . V_13 ;
return F_51 ( V_105 -> V_109 , V_105 -> V_111 + V_111 ,
V_128 -> V_129 ) ;
}
static unsigned long
F_57 ( T_8 * V_103 , T_3 V_14 )
{
struct V_104 * V_105 = V_103 -> V_112 . V_13 ;
unsigned long V_88 = V_14 - V_105 -> V_109 -> V_71 ;
unsigned long V_131 ;
if ( V_14 < V_103 -> V_112 . V_113 ||
V_14 >= V_103 -> V_112 . V_113 + V_103 -> V_112 . V_20 ) {
F_23 ( L_15 , V_132 ) ;
return - V_133 ;
}
V_131 = V_105 -> V_109 -> V_72 [ V_88 >> V_100 ] ;
if ( ! ( V_131 & 1 ) ) {
F_23 ( L_16 , V_132 ) ;
return - V_133 ;
}
return ( V_131 >> 1 ) << V_100 ;
}
T_8 *
F_58 ( void )
{
T_8 * V_103 ;
struct V_11 * V_12 ;
T_5 * V_32 ;
int V_134 = - 1 ;
union V_40 V_41 ;
V_32 = & V_31 -> V_35 ;
if ( F_15 ( V_32 ) )
V_134 = 2 ;
if ( V_134 < 0 &&
V_80 &&
F_15 ( V_32 = & V_30 -> V_35 ) )
V_134 = 3 ;
for ( V_12 = V_95 ; V_12 ; V_12 = V_12 -> V_96 )
if ( V_12 -> V_29 == V_134 )
break;
if ( ! V_12 || ! V_12 -> V_70 )
return NULL ;
V_103 = F_46 ( sizeof( * V_103 ) , V_108 ) ;
if ( ! V_103 )
return NULL ;
V_103 -> V_12 = V_12 ;
V_103 -> V_117 = V_32 ;
V_103 -> V_135 = & V_136 ;
V_103 -> V_112 . V_113 = 0 ;
V_103 -> V_112 . V_20 = 0 ;
V_103 -> V_112 . V_13 = NULL ;
V_103 -> V_137 . V_138 = 0 ;
V_103 -> V_137 . V_119 . V_122 = 3 ;
V_103 -> V_137 . V_119 . V_120 = 1 ;
V_103 -> V_137 . V_119 . V_139 = 7 ;
V_41 . V_42 = V_32 -> V_41 . V_33 ;
V_103 -> V_84 . V_138 = 0 ;
V_103 -> V_84 . V_119 . V_122 = 1 << V_41 . V_43 . V_121 ;
V_103 -> V_84 . V_119 . V_120 = V_41 . V_43 . V_118 ;
V_103 -> V_84 . V_119 . V_139 = 7 ;
V_103 -> V_84 . V_119 . V_126 = V_41 . V_43 . V_125 ;
return V_103 ;
}
