static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
F_2 ( V_5 L_1
L_2 , V_2 -> V_6 ) ;
V_4 = ( V_7 == V_8 ) ? 2 : 4 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_2 ( V_5
L_3
L_4 ,
V_3 + 1 ,
V_2 -> V_9 [ V_3 ] . V_10 , V_2 -> V_9 [ V_3 ] . V_11 ,
V_2 -> V_9 [ V_3 ] . V_12 , V_2 -> V_9 [ V_3 ] . V_13 ) ;
F_2 ( L_5 , ( void * ) V_2 -> V_9 [ V_3 ] . V_11 ) ;
}
}
void F_3 ( struct V_14 * V_15 , long V_16 )
{
char V_17 [ 36 ] ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_6 , V_15 ,
0 , V_16 , V_20 ) == V_21 )
return;
if ( V_16 < 0x100 ) {
sprintf ( V_17 , L_7 , V_16 ) ;
F_5 ( V_17 , V_15 ) ;
}
V_16 -= 0x100 ;
if ( V_15 -> V_10 & V_22 ) {
sprintf ( V_17 , L_8 , V_16 ) ;
F_5 ( V_17 , V_15 ) ;
}
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_25 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_28 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = V_16 ;
F_7 ( V_25 , & V_18 , V_32 ) ;
}
void F_8 ( struct V_14 * V_15 , long V_16 )
{
char V_17 [ 36 ] ;
if ( F_4 ( V_33 , L_9 , V_15 ,
0 , V_16 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
sprintf ( V_17 , L_10 , V_16 ) ;
F_5 ( V_17 , V_15 ) ;
}
void F_9 ( const char * V_34 , int line )
{
F_10 ( 1 ) ;
F_2 ( L_11 , V_34 , line ) ;
}
static int F_11 ( int V_35 , unsigned long V_36 , char * V_37 , int V_38 )
{
unsigned long V_39 ;
int V_40 = - V_41 ;
F_12 ( & V_42 , V_39 ) ;
if ( V_43 ) {
V_40 = V_43 ( V_35 , V_36 , V_37 , V_38 ) ;
} else if ( V_7 == V_44 ) {
if ( F_13 ( V_35 , V_36 , V_37 , V_38 ) == - 1 )
V_40 = - V_45 ;
else
V_40 = 0 ;
} else
V_40 = - V_41 ;
F_14 ( & V_42 , V_39 ) ;
return V_40 ;
}
int F_15 ( T_2 V_46 )
{
unsigned long V_39 ;
int V_40 = 0 ;
F_12 ( & V_42 , V_39 ) ;
if ( ! V_43 )
V_43 = V_46 ;
else
V_40 = - V_47 ;
F_14 ( & V_42 , V_39 ) ;
return V_40 ;
}
void F_16 ( T_2 V_46 )
{
unsigned long V_39 ;
F_12 ( & V_42 , V_39 ) ;
if ( V_43 == V_46 )
V_43 = NULL ;
F_14 ( & V_42 , V_39 ) ;
}
void F_17 ( struct V_14 * V_15 , unsigned long V_48 , unsigned long V_49 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_12 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
goto V_52;
if ( V_15 -> V_10 & V_22 ) {
F_2 ( L_13
L_14 , V_48 , V_49 ) ;
F_5 ( L_15 , V_15 ) ;
}
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_53 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_54 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_53 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_20 ( struct V_14 * V_15 , unsigned long V_48 , unsigned long V_49 )
{
if ( F_4 ( V_33 , L_16 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_17 ( V_15 , V_48 , V_49 ) ;
}
void F_21 ( struct V_14 * V_15 , unsigned long V_55 , unsigned long V_56 )
{
unsigned short type = ( V_56 >> 16 ) ;
unsigned short V_57 = ( V_56 & 0xffff ) ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_12 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
F_2 ( L_17
L_18 ,
V_55 , V_57 , type ) ;
F_5 ( L_15 , V_15 ) ;
}
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_53 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_54 ;
V_18 . V_29 = ( void V_30 * ) V_55 ;
V_18 . V_31 = 0 ;
F_7 ( V_53 , & V_18 , V_32 ) ;
}
void F_22 ( struct V_14 * V_15 , unsigned long V_55 , unsigned long V_56 )
{
if ( F_4 ( V_33 , L_16 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_21 ( V_15 , V_55 , V_56 ) ;
}
bool F_23 ( struct V_14 * V_15 )
{
unsigned char V_58 ;
T_3 V_59 ;
if ( F_24 ( V_59 , ( T_3 V_30 * ) V_15 -> V_11 ) == - V_60 )
return false ;
if ( ( V_59 & 0xc0800000 ) == 0xc0800000 ) {
if ( V_59 & 0x2000 )
V_58 = ( V_15 -> V_10 >> 24 ) ;
else
V_58 = ( V_59 >> 5 ) ;
if ( ( V_58 & 0xf2 ) == V_61 ) {
if ( V_59 & 0x1000000 ) {
F_25 ( V_59 , V_15 ) ;
return true ;
} else if ( V_59 & 0x200000 ) {
return false ;
}
F_26 ( V_59 , V_15 ) ;
return true ;
}
}
return false ;
}
void F_27 ( struct V_14 * V_15 , unsigned long V_48 , unsigned long V_49 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_19 , V_15 ,
0 , 0x30 , V_20 ) == V_21 )
goto V_52;
if ( V_15 -> V_10 & V_22 ) {
const struct V_62 * V_63 ;
V_63 = F_28 ( V_15 -> V_11 ) ;
if ( V_63 ) {
#ifdef F_29
F_2 ( L_20 , V_15 -> V_11 ) ;
F_2 ( L_21 ,
V_15 -> V_11 , V_63 -> V_64 ) ;
#endif
V_15 -> V_11 = V_63 -> V_64 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
goto V_52;
}
F_2 ( L_22
L_14 , V_48 , V_49 ) ;
F_5 ( L_23 , V_15 ) ;
}
if ( F_23 ( V_15 ) )
return;
V_18 . V_24 = V_53 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_54 ;
V_18 . V_29 = ( void V_30 * ) V_49 ;
V_18 . V_31 = 0 ;
F_7 ( V_53 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_30 ( struct V_14 * V_15 , unsigned long V_48 , unsigned long V_49 )
{
if ( F_4 ( V_33 , L_24 , V_15 ,
0 , 0x30 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_27 ( V_15 , V_48 , V_49 ) ;
}
void F_31 ( struct V_14 * V_15 , unsigned long V_55 , unsigned long V_56 )
{
unsigned short type = ( V_56 >> 16 ) ;
unsigned short V_57 = ( V_56 & 0xffff ) ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_19 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
const struct V_62 * V_63 ;
V_63 = F_28 ( V_15 -> V_11 ) ;
if ( V_63 ) {
#ifdef F_29
F_2 ( L_20 , V_15 -> V_11 ) ;
F_2 ( L_21 ,
V_15 -> V_11 , V_63 -> V_64 ) ;
#endif
V_15 -> V_11 = V_63 -> V_64 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
F_2 ( L_25
L_18 ,
V_55 , V_57 , type ) ;
F_5 ( L_23 , V_15 ) ;
}
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
if ( F_23 ( V_15 ) )
return;
V_18 . V_24 = V_53 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_54 ;
V_18 . V_29 = ( void V_30 * ) V_55 ;
V_18 . V_31 = 0 ;
F_7 ( V_53 , & V_18 , V_32 ) ;
}
void F_32 ( struct V_14 * V_15 , unsigned long V_55 , unsigned long V_56 )
{
if ( F_4 ( V_33 , L_24 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_31 ( V_15 , V_55 , V_56 ) ;
}
static void F_33 ( void )
{
unsigned long V_65 ;
if ( V_7 != V_44 )
F_34 () ;
for ( V_65 = 0 ; V_65 < ( V_66 << 1 ) ; V_65 += 32 ) {
F_35 ( V_65 , 0x0 ) ;
F_36 ( V_65 , 0x0 ) ;
}
__asm__ __volatile__("flush %%g6\n\t"
"membar #Sync\n\t"
"stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (LSU_CONTROL_IC | LSU_CONTROL_DC |
LSU_CONTROL_IM | LSU_CONTROL_DM),
"i" (ASI_LSU_CONTROL)
: "memory");
}
static void F_37 ( void )
{
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (ESTATE_ERR_ALL),
"i" (ASI_ESTATE_ERROR_EN));
}
static void F_38 ( unsigned long V_67 , unsigned long V_68 , unsigned long V_69 , unsigned long V_70 )
{
unsigned short V_71 ;
char V_72 [ 64 ] , * V_2 ;
if ( V_69 & V_70 ) {
V_71 = V_73 [ V_69 & 0xff ] ;
if ( F_11 ( V_71 , V_67 , V_72 , sizeof( V_72 ) ) < 0 )
V_2 = V_74 ;
else
V_2 = V_72 ;
F_2 ( V_75 L_26
L_27 ,
F_39 () , V_71 , V_2 ) ;
}
if ( V_68 & V_70 ) {
V_71 = V_73 [ V_68 & 0xff ] ;
if ( F_11 ( V_71 , V_67 , V_72 , sizeof( V_72 ) ) < 0 )
V_2 = V_74 ;
else
V_2 = V_72 ;
F_2 ( V_75 L_28
L_27 ,
F_39 () , V_71 , V_2 ) ;
}
}
static void F_40 ( unsigned long V_76 , unsigned long V_67 , unsigned long V_68 , unsigned long V_69 , int V_77 , struct V_14 * V_15 )
{
F_2 ( V_75 L_29
L_30 ,
F_39 () , V_76 , V_67 , V_69 , V_68 , V_77 ) ;
F_38 ( V_67 , V_68 , V_69 , V_78 ) ;
F_4 ( V_19 , L_31 , V_15 ,
0 , V_79 , V_20 ) ;
F_37 () ;
}
static void F_41 ( unsigned long V_76 , unsigned long V_67 , unsigned long V_68 , unsigned long V_69 , unsigned long V_13 , int V_77 , struct V_14 * V_15 )
{
T_1 V_18 ;
F_2 ( V_75 L_32
L_33 ,
F_39 () , V_76 , V_67 , V_69 , V_68 , V_13 , V_77 ) ;
F_38 ( V_67 , V_68 , V_69 , V_80 ) ;
F_4 ( V_19 , L_34 , V_15 ,
0 , V_13 , V_20 ) ;
if ( V_15 -> V_10 & V_22 ) {
if ( V_77 )
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_35 , V_15 ) ;
}
F_33 () ;
F_37 () ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_81 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_82 ;
V_18 . V_29 = ( void * ) 0 ;
V_18 . V_31 = 0 ;
F_7 ( V_81 , & V_18 , V_32 ) ;
}
void F_42 ( struct V_14 * V_15 , unsigned long V_83 , unsigned long V_67 )
{
unsigned long V_76 , V_13 , V_68 , V_69 ;
int V_77 ;
V_76 = ( V_83 & V_84 ) >> V_85 ;
V_13 = ( V_83 & V_86 ) >> V_87 ;
V_77 = ( V_83 & V_88 ) ? 1 : 0 ;
V_69 = ( V_83 & V_89 ) >> V_90 ;
V_68 = ( V_83 & V_91 ) >> V_92 ;
#ifdef F_43
if ( V_13 == V_93 &&
V_94 && V_95 == F_39 () ) {
F_33 () ;
F_37 () ;
V_96 = 1 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
#endif
if ( V_76 & V_97 )
F_41 ( V_76 , V_67 , V_68 , V_69 , V_13 , V_77 , V_15 ) ;
if ( V_13 == V_79 ) {
if ( V_76 & V_97 ) {
if ( V_68 & V_78 ) {
__asm__ __volatile__(
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (udbh & UDBE_CE),
"r" (0x0), "i" (ASI_UDB_ERROR_W));
}
if ( V_69 & V_78 ) {
__asm__ __volatile__(
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (udbl & UDBE_CE),
"r" (0x18), "i" (ASI_UDB_ERROR_W));
}
}
F_40 ( V_76 , V_67 , V_68 , V_69 , V_77 , V_15 ) ;
}
}
void F_44 ( void )
{
unsigned long V_98 ;
F_2 ( L_36 ,
F_39 () ) ;
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (dcr)
: "i" (ASI_DCU_CONTROL_REG));
V_98 |= ( V_99 | V_100 | V_101 | V_102 ) ;
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (dcr), "i" (ASI_DCU_CONTROL_REG));
}
static inline struct V_103 * F_45 ( unsigned long V_76 )
{
struct V_103 * V_2 ;
int V_104 = F_39 () ;
if ( ! V_105 )
return NULL ;
V_2 = V_105 + ( V_104 * 2 ) ;
if ( ( V_76 & V_106 ) != 0UL )
V_2 ++ ;
return V_2 ;
}
void T_4 F_46 ( void )
{
unsigned long V_107 , V_108 , V_109 , V_110 ;
int V_3 , V_111 ;
V_107 = 0UL ;
V_108 = ~ 0UL ;
for ( V_3 = 0 ; V_3 < V_112 ; V_3 ++ ) {
unsigned long V_113 ;
V_113 = F_47 ( V_3 ) . V_114 ;
if ( ! V_113 )
continue;
if ( V_113 > V_107 )
V_107 = V_113 ;
V_113 = F_47 ( V_3 ) . V_115 ;
if ( V_113 < V_108 )
V_108 = V_113 ;
}
if ( V_107 == 0UL || V_108 == ~ 0UL ) {
F_48 ( L_37
L_38 ) ;
F_49 () ;
}
V_116 = ( 2 * V_107 ) ;
V_117 = V_108 ;
V_118 = F_50 ( V_116 ) ;
if ( V_118 == ~ 0UL ) {
F_48 ( L_39
L_40 ,
V_116 ) ;
F_49 () ;
}
V_111 = V_112 * ( 2 * sizeof( struct V_103 ) ) ;
for ( V_109 = 0 ; V_109 < V_119 ; V_109 ++ ) {
if ( ( V_66 << V_109 ) >= V_111 )
break;
}
V_105 = (struct V_103 * )
F_51 ( V_120 , V_109 ) ;
if ( ! V_105 ) {
F_48 ( L_41
L_42 , V_111 ) ;
F_49 () ;
}
memset ( V_105 , 0 , V_66 << V_109 ) ;
for ( V_3 = 0 ; V_3 < 2 * V_112 ; V_3 ++ )
V_105 [ V_3 ] . V_76 = V_121 ;
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
if ( ( V_110 >> 32 ) == V_122 ||
( V_110 >> 32 ) == V_123 ) {
V_124 = & V_125 [ 0 ] ;
V_126 = V_127 ;
} else if ( ( V_110 >> 32 ) == 0x003e0015 ) {
V_124 = & V_128 [ 0 ] ;
V_126 = V_129 ;
} else {
V_124 = & V_130 [ 0 ] ;
V_126 = V_131 ;
}
memcpy ( V_132 , V_133 , ( 8 * 4 ) ) ;
memcpy ( V_134 , V_135 , ( 8 * 4 ) ) ;
memcpy ( V_136 , V_137 , ( 8 * 4 ) ) ;
memcpy ( V_138 , V_139 , ( 8 * 4 ) ) ;
memcpy ( V_140 , V_141 , ( 8 * 4 ) ) ;
memcpy ( V_142 , V_143 , ( 8 * 4 ) ) ;
memcpy ( V_144 , V_141 , ( 8 * 4 ) ) ;
memcpy ( V_145 , V_143 , ( 8 * 4 ) ) ;
if ( V_7 == V_146 ) {
memcpy ( V_147 , V_148 , ( 8 * 4 ) ) ;
memcpy ( V_149 , V_150 , ( 8 * 4 ) ) ;
memcpy ( V_151 , V_152 , ( 8 * 4 ) ) ;
memcpy ( V_153 , V_154 , ( 8 * 4 ) ) ;
}
F_52 ( V_155 ) ;
}
static void F_53 ( void )
{
unsigned long V_156 = V_118 ;
unsigned long V_157 = V_117 ;
unsigned long V_158 = V_116 ;
__asm__ __volatile__("1: subcc %0, %4, %0\n\t"
" bne,pt %%xcc, 1b\n\t"
" ldxa [%2 + %0] %3, %%g0\n\t"
: "=&r" (flush_size)
: "0" (flush_size), "r" (flush_base),
"i" (ASI_PHYS_USE_EC), "r" (flush_linesize));
}
static void F_54 ( unsigned long V_159 )
{
unsigned long V_160 ;
V_159 &= ~ ( 8UL - 1UL ) ;
V_159 = ( V_118 +
( V_159 & ( ( V_116 >> 1UL ) - 1UL ) ) ) ;
V_160 = V_159 + ( V_116 >> 1UL ) ;
__asm__ __volatile__("ldxa [%0] %2, %%g0\n\t"
"ldxa [%1] %2, %%g0\n\t"
"membar #Sync"
:
: "r" (physaddr), "r" (alias),
"i" (ASI_PHYS_USE_EC));
}
static void F_55 ( void )
{
unsigned int V_161 , V_162 ;
unsigned long V_55 ;
V_161 = F_56 () . V_161 ;
V_162 = F_56 () . V_162 ;
for ( V_55 = 0 ; V_55 < V_161 ; V_55 += V_162 ) {
__asm__ __volatile__("stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (addr | (2 << 3)),
"i" (ASI_IC_TAG));
}
}
static void F_57 ( void )
{
unsigned long V_163 ;
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
"or %0, %2, %%g1\n\t"
"stxa %%g1, [%%g0] %1\n\t"
"membar #Sync"
: "=r" (dcu_save)
: "i" (ASI_DCU_CONTROL_REG), "i" (DCU_IC)
: "g1");
F_55 () ;
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (dcu_save), "i" (ASI_DCU_CONTROL_REG));
}
static void F_58 ( void )
{
unsigned int V_164 , V_165 ;
unsigned long V_55 ;
V_164 = F_56 () . V_164 ;
V_165 = F_56 () . V_165 ;
for ( V_55 = 0 ; V_55 < V_164 ; V_55 += V_165 ) {
__asm__ __volatile__("stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (addr), "i" (ASI_DCACHE_TAG));
}
}
static void F_59 ( void )
{
unsigned int V_164 , V_165 ;
unsigned long V_55 ;
V_164 = F_56 () . V_164 ;
V_165 = F_56 () . V_165 ;
for ( V_55 = 0 ; V_55 < V_164 ; V_55 += V_165 ) {
unsigned long V_166 = ( V_55 >> 14 ) ;
unsigned long line ;
__asm__ __volatile__("membar #Sync\n\t"
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (tag), "r" (addr),
"i" (ASI_DCACHE_UTAG));
for ( line = V_55 ; line < V_55 + V_165 ; line += 8 )
__asm__ __volatile__("membar #Sync\n\t"
"stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (line),
"i" (ASI_DCACHE_DATA));
}
}
static inline unsigned long F_60 ( unsigned long V_76 )
{
unsigned long V_167 = 0 ;
int V_3 ;
for ( V_3 = 0 ; V_124 [ V_3 ] . V_168 ; V_3 ++ ) {
if ( ( V_167 = ( V_76 & V_124 [ V_3 ] . V_168 ) ) != 0UL )
return V_167 ;
}
return V_167 ;
}
static const char * F_61 ( unsigned long V_70 )
{
int V_3 ;
for ( V_3 = 0 ; V_124 [ V_3 ] . V_168 ; V_3 ++ ) {
if ( ( V_70 & V_124 [ V_3 ] . V_168 ) != 0UL )
return V_124 [ V_3 ] . V_169 ;
}
return L_43 ;
}
static void F_62 ( struct V_14 * V_15 , struct V_103 * V_18 ,
unsigned long V_76 , unsigned long V_67 , int V_170 )
{
unsigned long V_171 ;
char V_172 [ 256 ] ;
F_2 ( L_44 L_45 ,
( V_170 ? V_75 : V_173 ) , F_39 () ,
V_76 , V_67 ,
( V_76 & V_106 ) ? 1 : 0 ) ;
F_2 ( L_44 L_46 ,
( V_170 ? V_75 : V_173 ) , F_39 () ,
V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_174 [ V_175 ] , V_15 -> V_10 ) ;
F_2 ( L_44 L_47 ,
( V_170 ? V_75 : V_173 ) , F_39 () ) ;
F_2 ( L_48 , ( void * ) V_15 -> V_11 ) ;
F_2 ( L_44 L_49 ,
( V_170 ? V_75 : V_173 ) , F_39 () ,
( V_76 & V_176 ) >> V_177 ,
( V_76 & V_178 ) >> V_179 ,
( V_76 & V_180 ) ? L_50 : L_51 ,
( V_76 & V_181 ) ? L_52 : L_51 ) ;
V_171 = F_60 ( V_76 ) ;
F_2 ( L_44 L_53 ,
( V_170 ? V_75 : V_173 ) , F_39 () ,
V_171 , F_61 ( V_171 ) ) ;
#define F_63 (CHAFSR_IVC | CHAFSR_IVU | \
CHAFSR_CPC | CHAFSR_CPU | \
CHAFSR_UE | CHAFSR_CE | \
CHAFSR_EDC | CHAFSR_EDU | \
CHAFSR_UCC | CHAFSR_UCU | \
CHAFSR_WDU | CHAFSR_WDC)
#define F_64 (CHAFSR_EMC | CHAFSR_EMU)
if ( V_76 & F_63 ) {
int V_182 ;
int V_40 ;
V_182 = ( V_76 & V_178 ) >> V_179 ;
V_182 = V_183 [ V_182 ] ;
V_40 = F_11 ( V_182 , V_67 , V_172 , sizeof( V_172 ) ) ;
if ( V_40 != - 1 )
F_2 ( L_44 L_54 ,
( V_170 ? V_75 : V_173 ) ,
F_39 () , V_172 ) ;
} else if ( V_76 & F_64 ) {
int V_182 ;
int V_40 ;
V_182 = ( V_76 & V_176 ) >> V_177 ;
V_182 = V_184 [ V_182 ] ;
V_40 = F_11 ( V_182 , V_67 , V_172 , sizeof( V_172 ) ) ;
if ( V_40 != - 1 )
F_2 ( L_44 L_55 ,
( V_170 ? V_75 : V_173 ) ,
F_39 () , V_172 ) ;
}
F_2 ( L_44 L_56 ,
( V_170 ? V_75 : V_173 ) , F_39 () ,
( int ) V_18 -> V_185 ,
V_18 -> V_186 ,
V_18 -> V_187 ,
V_18 -> V_188 ) ;
F_2 ( L_44 L_57 ,
( V_170 ? V_75 : V_173 ) , F_39 () ,
V_18 -> V_189 [ 0 ] ,
V_18 -> V_189 [ 1 ] ,
V_18 -> V_189 [ 2 ] ,
V_18 -> V_189 [ 3 ] ) ;
F_2 ( L_44 L_58
L_59 ,
( V_170 ? V_75 : V_173 ) , F_39 () ,
( int ) V_18 -> V_190 ,
V_18 -> V_191 ,
V_18 -> V_192 ,
V_18 -> V_193 ,
V_18 -> V_194 ,
V_18 -> V_195 ) ;
F_2 ( L_44 L_60 ,
( V_170 ? V_75 : V_173 ) , F_39 () ,
V_18 -> V_196 [ 0 ] ,
V_18 -> V_196 [ 1 ] ,
V_18 -> V_196 [ 2 ] ,
V_18 -> V_196 [ 3 ] ) ;
F_2 ( L_44 L_61 ,
( V_170 ? V_75 : V_173 ) , F_39 () ,
V_18 -> V_196 [ 4 ] ,
V_18 -> V_196 [ 5 ] ,
V_18 -> V_196 [ 6 ] ,
V_18 -> V_196 [ 7 ] ) ;
F_2 ( L_44 L_62 ,
( V_170 ? V_75 : V_173 ) , F_39 () ,
( int ) V_18 -> V_197 , V_18 -> V_198 ) ;
F_2 ( L_44 L_63 ,
( V_170 ? V_75 : V_173 ) , F_39 () ,
V_18 -> V_199 [ 0 ] ,
V_18 -> V_199 [ 1 ] ,
V_18 -> V_199 [ 2 ] ,
V_18 -> V_199 [ 3 ] ) ;
V_76 = ( V_76 & ~ V_171 ) & V_126 ;
while ( V_76 != 0UL ) {
unsigned long V_70 = F_60 ( V_76 ) ;
F_2 ( L_44 L_64 ,
( V_170 ? V_75 : V_173 ) ,
V_70 , F_61 ( V_70 ) ) ;
V_76 &= ~ V_70 ;
}
if ( ! V_170 )
F_2 ( V_173 L_65 ) ;
}
static int F_65 ( struct V_103 * V_200 )
{
unsigned long V_76 , V_67 ;
int V_40 = 0 ;
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
: "=r" (afsr)
: "i" (ASI_AFSR));
if ( ( V_76 & V_126 ) != 0 ) {
if ( V_200 != NULL ) {
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
: "=r" (afar)
: "i" (ASI_AFAR));
V_200 -> V_76 = V_76 ;
V_200 -> V_67 = V_67 ;
}
V_40 = 1 ;
}
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync\n\t"
: : "r" (afsr), "i" (ASI_AFSR));
return V_40 ;
}
void F_66 ( struct V_14 * V_15 , unsigned long V_76 , unsigned long V_67 )
{
struct V_103 V_201 , * V_2 ;
int V_170 ;
F_53 () ;
V_2 = F_45 ( V_76 ) ;
if ( ! V_2 ) {
F_48 ( L_66 ,
V_76 , V_67 ) ;
F_48 ( L_67 ,
F_39 () , V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_10 ) ;
F_49 () ;
}
memcpy ( & V_201 , V_2 , sizeof( V_201 ) ) ;
if ( V_2 -> V_76 != V_76 || V_2 -> V_67 != V_67 )
V_201 . V_76 = V_121 ;
else
V_2 -> V_76 = V_121 ;
F_57 () ;
F_58 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_DC | DCU_IC)
: "g1");
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_NCEEN | ESTATE_ERROR_CEEN)
: "g1");
V_170 = 1 ;
if ( V_76 & ( V_202 | V_203 | V_204 ) )
V_170 = 0 ;
if ( F_65 ( & V_201 ) ) {
unsigned long V_205 = V_201 . V_76 ;
if ( V_205 & ( V_206 | V_207 |
V_208 | V_209 |
V_210 | V_211 |
V_212 | V_213 ) )
V_170 = 0 ;
}
F_62 ( V_15 , & V_201 , V_76 , V_67 , V_170 ) ;
if ( ! V_170 )
F_67 ( L_68 ) ;
F_53 () ;
}
static int F_68 ( unsigned long V_159 )
{
unsigned long V_214 ;
unsigned long V_215 , V_216 ;
int V_40 ;
__asm__ __volatile__("ldxa [%%g0] %2, %0\n\t"
"andn %0, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %2\n\t"
"membar #Sync"
: "=&r" (orig_estate)
: "i" (ESTATE_ERROR_CEEN),
"i" (ASI_ESTATE_ERROR_EN)
: "g1");
V_159 &= ~ ( 8UL - 1UL ) ;
V_215 = ( V_118 +
( V_159 & ( ( V_116 >> 1 ) - 1 ) ) ) ;
V_216 = V_215 + ( V_116 >> 1 ) ;
__asm__ __volatile__("ldxa [%0] %3, %%g0\n\t"
"ldxa [%1] %3, %%g0\n\t"
"casxa [%2] %3, %%g0, %%g0\n\t"
"ldxa [%0] %3, %%g0\n\t"
"ldxa [%1] %3, %%g0\n\t"
"membar #Sync"
:
: "r" (alias1), "r" (alias2),
"r" (physaddr), "i" (ASI_PHYS_USE_EC));
if ( F_65 ( NULL ) ) {
__asm__ __volatile__("ldxa [%0] %1, %%g0\n\t"
"membar #Sync"
: : "r" (physaddr), "i" (ASI_PHYS_USE_EC));
if ( F_65 ( NULL ) )
V_40 = 2 ;
else
V_40 = 1 ;
} else {
V_40 = 0 ;
}
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
: : "r" (orig_estate), "i" (ASI_ESTATE_ERROR_EN));
return V_40 ;
}
static int F_69 ( unsigned long V_36 )
{
unsigned long V_217 = V_155 + V_36 ;
if ( V_217 > ( unsigned long ) V_218 )
return 0 ;
return F_70 ( V_217 ) ;
}
void F_71 ( struct V_14 * V_15 , unsigned long V_76 , unsigned long V_67 )
{
struct V_103 V_201 , * V_2 ;
int V_170 , V_219 ;
V_2 = F_45 ( V_76 ) ;
if ( ! V_2 ) {
F_48 ( L_69 ,
V_76 , V_67 ) ;
F_48 ( L_67 ,
F_39 () , V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_10 ) ;
F_49 () ;
}
memcpy ( & V_201 , V_2 , sizeof( V_201 ) ) ;
if ( V_2 -> V_76 != V_76 || V_2 -> V_67 != V_67 )
V_201 . V_76 = V_121 ;
else
V_2 -> V_76 = V_121 ;
V_219 = F_69 ( V_67 ) ;
if ( V_219 && ( V_76 & V_220 ) != 0UL ) {
F_68 ( V_67 ) ;
}
{
int V_221 , V_222 ;
V_221 = V_222 = 0 ;
if ( ( V_76 & V_223 ) != 0UL ) {
if ( ( V_76 & V_126 ) == V_223 )
V_222 = 1 ;
else
V_221 = 1 ;
} else if ( ( V_76 & V_224 ) != 0UL ) {
if ( ( V_76 & V_126 ) == V_224 )
V_222 = 1 ;
else
V_221 = 1 ;
}
F_57 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_IC)
: "g1");
if ( V_221 )
F_53 () ;
else if ( V_222 )
F_54 ( V_67 ) ;
}
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_CEEN)
: "g1");
V_170 = 1 ;
if ( V_76 & ( V_202 | V_203 | V_204 ) )
V_170 = 0 ;
( void ) F_65 ( & V_201 ) ;
F_62 ( V_15 , & V_201 , V_76 , V_67 , V_170 ) ;
if ( ! V_170 )
F_67 ( L_70 ) ;
}
void F_72 ( struct V_14 * V_15 , unsigned long V_76 , unsigned long V_67 )
{
struct V_103 V_201 , * V_2 ;
int V_170 , V_219 ;
#ifdef F_43
if ( V_94 && V_95 == F_39 () ) {
F_57 () ;
F_58 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_DC | DCU_IC)
: "g1");
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_NCEEN | ESTATE_ERROR_CEEN)
: "g1");
( void ) F_65 ( NULL ) ;
V_96 = 1 ;
V_15 -> V_11 += 4 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
#endif
V_2 = F_45 ( V_76 ) ;
if ( ! V_2 ) {
F_48 ( L_71 ,
V_76 , V_67 ) ;
F_48 ( L_67 ,
F_39 () , V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_10 ) ;
F_49 () ;
}
memcpy ( & V_201 , V_2 , sizeof( V_201 ) ) ;
if ( V_2 -> V_76 != V_76 || V_2 -> V_67 != V_67 )
V_201 . V_76 = V_121 ;
else
V_2 -> V_76 = V_121 ;
V_219 = F_69 ( V_67 ) ;
{
int V_221 , V_222 ;
V_221 = V_222 = 0 ;
if ( ( V_76 & V_207 ) != 0UL ) {
if ( ( V_76 & V_126 ) == V_207 )
V_222 = 1 ;
else
V_221 = 1 ;
} else if ( ( V_76 & V_212 ) != 0UL ) {
if ( ( V_76 & V_126 ) == V_212 )
V_222 = 1 ;
else
V_221 = 1 ;
}
F_57 () ;
F_58 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_IC | DCU_DC)
: "g1");
if ( V_221 )
F_53 () ;
else if ( V_222 )
F_54 ( V_67 ) ;
}
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_NCEEN | ESTATE_ERROR_CEEN)
: "g1");
V_170 = 1 ;
if ( V_76 & ( V_202 | V_203 | V_204 ) )
V_170 = 0 ;
if ( F_65 ( & V_201 ) ) {
unsigned long V_205 = V_201 . V_76 ;
if ( V_205 & ( V_206 | V_207 |
V_208 | V_209 |
V_210 | V_211 |
V_212 | V_213 ) )
V_170 = 0 ;
}
F_62 ( V_15 , & V_201 , V_76 , V_67 , V_170 ) ;
if ( V_170 && V_219 ) {
if ( ( V_15 -> V_10 & V_22 ) == 0UL ) {
V_170 = 1 ;
} else {
const struct V_62 * V_63 ;
V_63 = F_28 ( V_15 -> V_11 ) ;
if ( V_63 ) {
V_170 = 1 ;
} else {
V_170 = 0 ;
}
if ( V_170 ) {
if ( F_73 ( V_67 >> V_225 ) )
F_74 ( F_75 ( V_67 >> V_225 ) ) ;
else
V_170 = 0 ;
if ( V_170 ) {
V_15 -> V_11 = V_63 -> V_64 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
}
}
}
} else {
V_170 = 0 ;
}
if ( ! V_170 )
F_67 ( L_72 ) ;
}
void F_76 ( int type , struct V_14 * V_15 )
{
if ( type & 0x1 )
F_55 () ;
else
F_59 () ;
F_58 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_DC | DCU_IC)
: "g1");
if ( type & 0x2 ) {
F_2 ( V_5 L_73 ,
F_39 () ,
( type & 0x1 ) ? 'I' : 'D' ,
V_15 -> V_11 ) ;
F_2 ( V_5 L_48 , ( void * ) V_15 -> V_11 ) ;
F_67 ( L_74 ) ;
}
F_2 ( V_75 L_73 ,
F_39 () ,
( type & 0x1 ) ? 'I' : 'D' ,
V_15 -> V_11 ) ;
F_2 ( V_75 L_48 , ( void * ) V_15 -> V_11 ) ;
}
static const char * F_77 ( T_5 type )
{
static const char * V_226 [ V_227 ] = {
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79 ,
L_80 ,
L_81 ,
} ;
if ( type < V_227 )
return V_226 [ type ] ;
return L_82 ;
}
static void F_78 ( T_3 V_228 )
{
static const char * V_229 [] = {
L_83 ,
L_84 ,
L_85 ,
L_86 ,
L_87 ,
L_88 ,
L_89 ,
L_90 ,
L_91 ,
} ;
static const char * V_230 [] = {
L_92 ,
L_93 ,
L_94 ,
L_95 ,
} ;
static const char * V_231 [] = {
L_96 ,
L_97 ,
L_98 ,
L_99 ,
} ;
T_3 V_232 , V_233 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_79 ( V_229 ) ; V_3 ++ ) {
if ( V_228 & ( 1U << V_3 ) ) {
const char * V_234 = V_229 [ V_3 ] ;
F_80 ( L_100 , V_234 ) ;
}
}
V_232 = ( ( V_228 & V_235 ) >>
V_236 ) ;
F_80 ( L_100 , V_230 [ V_232 ] ) ;
V_233 = ( ( V_228 & V_237 ) >>
V_238 ) ;
F_80 ( L_100 , V_231 [ V_233 ] ) ;
if ( V_228 & V_239 )
F_80 ( L_101 ) ;
}
static void F_81 ( const char * V_240 , struct V_14 * V_15 )
{
unsigned int V_59 ;
T_6 V_55 ;
if ( ! ( V_15 -> V_10 & V_22 ) )
return;
V_59 = * ( unsigned int * ) V_15 -> V_11 ;
V_55 = F_82 ( V_15 , V_59 , 0 ) ;
F_2 ( L_102 ,
V_240 , V_55 ) ;
}
static void F_83 ( struct V_14 * V_15 , struct V_241 * V_242 ,
int V_104 , const char * V_240 , T_7 * V_243 )
{
T_6 * V_244 = ( T_6 * ) V_242 ;
T_3 V_228 ;
int V_245 ;
F_2 ( L_103 , V_240 , V_104 ) ;
F_2 ( L_104 ,
V_240 , V_15 -> V_11 , ( void * ) V_15 -> V_11 ) ;
F_2 ( L_105 ,
V_240 , V_244 [ 0 ] , V_244 [ 1 ] , V_244 [ 2 ] , V_244 [ 3 ] ) ;
F_2 ( L_106 ,
V_240 , V_244 [ 4 ] , V_244 [ 5 ] , V_244 [ 6 ] , V_244 [ 7 ] ) ;
F_2 ( L_107 ,
V_240 , V_242 -> V_246 , V_242 -> V_247 ) ;
F_2 ( L_108 , V_240 , F_77 ( V_242 -> V_248 ) ) ;
V_228 = V_242 -> V_249 ;
F_2 ( L_109 , V_240 , V_228 ) ;
F_78 ( V_228 ) ;
F_80 ( L_110 ) ;
if ( V_228 & ( V_250 |
V_251 |
V_252 ) ) {
F_2 ( L_111 , V_240 , V_242 -> V_253 ) ;
if ( V_242 -> V_253 == ~ ( T_6 ) 0 )
F_81 ( V_240 , V_15 ) ;
}
if ( V_228 & ( V_250 | V_252 ) )
F_2 ( L_112 , V_240 , V_242 -> V_254 ) ;
if ( V_228 & ( V_255 |
V_256 |
V_257 |
V_258 ) )
F_2 ( L_113 , V_240 , V_242 -> V_259 ) ;
if ( V_228 & V_252 )
F_2 ( L_114 , V_240 , V_242 -> V_260 ) ;
if ( ( V_228 & ( V_256 |
V_257 |
V_258 ) ) &&
( V_242 -> V_261 & V_262 ) != 0 )
F_2 ( L_115 ,
V_240 , V_242 -> V_261 & ~ V_262 ) ;
F_84 ( V_15 ) ;
if ( ( V_245 = F_85 ( V_243 ) ) != 0 ) {
F_86 ( V_243 , 0 ) ;
F_87 () ;
F_2 ( L_116 ,
V_240 , V_245 ) ;
}
}
void F_88 ( struct V_14 * V_15 , unsigned long V_263 )
{
enum V_50 V_51 = F_18 () ;
struct V_241 * V_242 , V_264 ;
struct V_265 * V_266 ;
unsigned long V_36 ;
int V_104 ;
V_104 = F_89 () ;
V_266 = & V_267 [ V_104 ] ;
V_36 = V_266 -> V_268 + V_263 ;
V_242 = F_90 ( V_36 ) ;
memcpy ( & V_264 , V_242 , sizeof( struct V_241 ) ) ;
V_242 -> V_246 = 0 ;
F_87 () ;
F_91 () ;
if ( V_264 . V_248 == V_269 ) {
F_92 ( L_117 ,
V_264 . V_270 ) ;
F_93 ( true ) ;
goto V_52;
}
F_83 ( V_15 , & V_264 , V_104 ,
V_271 L_118 ,
& V_272 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_94 ( struct V_14 * V_15 )
{
F_95 ( & V_272 ) ;
}
static unsigned long F_96 ( struct V_14 * V_15 )
{
unsigned int V_59 ;
if ( ! F_97 ( & V_59 , ( void V_30 * ) V_15 -> V_11 , 4 ) ) {
return F_82 ( V_15 , V_59 ,
( V_59 >> 25 ) & 0x1f ) ;
}
return 0 ;
}
bool F_98 ( struct V_14 * V_15 ,
struct V_241 * V_242 ) {
unsigned int V_228 = V_242 -> V_249 ;
if ( V_228 & V_250 ) {
unsigned long V_55 = V_242 -> V_253 ;
T_1 V_18 ;
if ( V_55 == ~ ( T_6 ) 0 ) {
F_99 ( L_119 ) ;
} else {
unsigned long V_273 = F_100 ( V_242 -> V_254 ,
V_66 ) ;
F_99 ( L_120 ,
V_55 ) ;
F_99 ( L_121 ,
V_273 ) ;
while ( V_273 -- > 0 ) {
if ( F_73 ( V_55 >> V_225 ) )
F_74 ( F_75 ( V_55 >> V_225 ) ) ;
V_55 += V_66 ;
}
}
V_18 . V_24 = V_274 ;
V_18 . V_26 = 0 ;
V_18 . V_31 = 0 ;
F_7 ( V_18 . V_24 , & V_18 , V_32 ) ;
return true ;
}
if ( V_228 & V_251 ) {
T_1 V_18 ;
V_18 . V_24 = V_81 ;
V_18 . V_27 = V_275 ;
V_18 . V_29 = ( void V_30 * ) F_96 ( V_15 ) ;
F_7 ( V_18 . V_24 , & V_18 , V_32 ) ;
return true ;
}
return false ;
}
void F_101 ( struct V_14 * V_15 , unsigned long V_263 )
{
struct V_241 * V_242 , V_264 ;
struct V_265 * V_266 ;
unsigned long V_36 ;
int V_104 ;
V_104 = F_89 () ;
V_266 = & V_267 [ V_104 ] ;
V_36 = V_266 -> V_276 + V_263 ;
V_242 = F_90 ( V_36 ) ;
memcpy ( & V_264 , V_242 , sizeof( struct V_241 ) ) ;
V_242 -> V_246 = 0 ;
F_87 () ;
F_91 () ;
if ( ! ( V_15 -> V_10 & V_22 ) &&
F_98 ( V_15 , & V_264 ) ) {
return;
}
#ifdef F_43
if ( V_94 && V_95 == V_104 ) {
V_96 = 1 ;
V_15 -> V_11 += 4 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
#endif
F_83 ( V_15 , & V_264 , V_104 ,
V_5 L_122 ,
& V_277 ) ;
F_67 ( L_123 ) ;
}
void F_102 ( struct V_14 * V_15 )
{
F_95 ( & V_277 ) ;
}
static void F_103 ( struct V_14 * V_15 )
{
F_5 ( L_124 , V_15 ) ;
}
void F_104 ( struct V_14 * V_15 , int V_6 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_2 ( V_5 L_125 ,
V_15 -> V_11 , V_6 ) ;
F_2 ( V_5 L_126 , ( void * ) V_15 -> V_11 ) ;
F_2 ( V_5 L_127 , V_15 -> V_174 [ V_175 ] ) ;
F_2 ( V_5 L_128 ,
( void * ) V_15 -> V_174 [ V_175 ] ) ;
F_2 ( V_5 L_129
L_130 ,
V_278 , V_279 ,
V_280 , V_281 ) ;
F_103 ( V_15 ) ;
}
void F_105 ( struct V_14 * V_15 , int V_6 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_2 ( V_5 L_131 ,
V_15 -> V_11 , V_6 ) ;
F_2 ( V_5 L_132 , ( void * ) V_15 -> V_11 ) ;
F_2 ( V_5 L_133 , V_15 -> V_174 [ V_175 ] ) ;
F_2 ( V_5 L_134 ,
( void * ) V_15 -> V_174 [ V_175 ] ) ;
F_2 ( V_5 L_135
L_130 ,
V_282 , V_283 ,
V_284 , V_285 ) ;
F_103 ( V_15 ) ;
}
void F_106 ( unsigned long V_286 , unsigned long V_287 )
{
F_2 ( V_173 L_136 ,
V_286 , V_287 ) ;
}
void F_107 ( unsigned long V_286 , unsigned long V_287 )
{
F_2 ( V_173 L_137 ,
V_286 , V_287 ) ;
}
static void F_108 ( struct V_14 * V_15 )
{
if ( V_15 -> V_10 & V_22 ) {
V_15 -> V_11 = V_15 -> V_12 ;
V_15 -> V_12 += 4 ;
} else {
unsigned long V_288 = F_109 () -> V_289 [ 0 ] ;
T_1 V_18 ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_290 ;
V_18 . V_26 = 0 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
V_18 . V_27 = V_291 ;
if ( ( V_288 & 0x1c000 ) == ( 1 << 14 ) ) {
if ( V_288 & 0x10 )
V_18 . V_27 = V_292 ;
else if ( V_288 & 0x08 )
V_18 . V_27 = V_293 ;
else if ( V_288 & 0x04 )
V_18 . V_27 = V_294 ;
else if ( V_288 & 0x02 )
V_18 . V_27 = V_295 ;
else if ( V_288 & 0x01 )
V_18 . V_27 = V_296 ;
}
F_7 ( V_290 , & V_18 , V_32 ) ;
}
}
void F_110 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
if ( F_4 ( V_19 , L_138 , V_15 ,
0 , 0x24 , V_290 ) == V_21 )
goto V_52;
F_108 ( V_15 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_111 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
struct V_297 * V_298 = V_299 ;
int V_40 = 0 ;
if ( F_4 ( V_19 , L_139 , V_15 ,
0 , 0x25 , V_290 ) == V_21 )
goto V_52;
switch ( ( F_109 () -> V_289 [ 0 ] & 0x1c000 ) ) {
case ( 2 << 14 ) :
case ( 3 << 14 ) :
V_40 = F_112 ( V_15 , V_298 , false ) ;
break;
}
if ( V_40 )
goto V_52;
F_108 ( V_15 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_113 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_140 , V_15 ,
0 , 0x26 , V_300 ) == V_21 )
goto V_52;
if ( V_15 -> V_10 & V_22 )
F_5 ( L_141 , V_15 ) ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_300 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_301 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_300 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_114 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_142 , V_15 ,
0 , 0x28 , V_290 ) == V_21 )
goto V_52;
if ( V_15 -> V_10 & V_22 )
F_5 ( L_143 , V_15 ) ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_290 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_302 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_290 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
static void F_115 ( unsigned int * V_303 )
{
int V_3 ;
if ( ( ( ( unsigned long ) V_303 ) & 3 ) )
return;
F_2 ( L_144 ) ;
for ( V_3 = - 3 ; V_3 < 6 ; V_3 ++ )
F_2 ( L_145 , V_3 ? ' ' : '<' , V_303 [ V_3 ] , V_3 ? ' ' : '>' ) ;
F_2 ( L_146 ) ;
}
static void F_116 ( unsigned int V_30 * V_303 )
{
int V_3 ;
unsigned int V_37 [ 9 ] ;
if ( ( ( ( unsigned long ) V_303 ) & 3 ) )
return;
if ( F_97 ( V_37 , V_303 - 3 , sizeof( V_37 ) ) )
return;
F_2 ( L_144 ) ;
for ( V_3 = 0 ; V_3 < 9 ; V_3 ++ )
F_2 ( L_145 , V_3 == 3 ? ' ' : '<' , V_37 [ V_3 ] , V_3 == 3 ? ' ' : '>' ) ;
F_2 ( L_146 ) ;
}
void F_117 ( struct V_304 * V_305 , unsigned long * V_306 )
{
unsigned long V_307 , V_308 ;
struct V_309 * V_310 ;
int V_311 = 0 ;
#ifdef F_118
int V_312 = 0 ;
#endif
V_308 = ( unsigned long ) V_306 ;
if ( ! V_305 )
V_305 = V_32 ;
V_310 = F_119 ( V_305 ) ;
if ( V_308 == 0UL ) {
if ( V_305 == V_32 )
asm("mov %%fp, %0" : "=r" (ksp));
else
V_308 = V_310 -> V_308 ;
}
if ( V_310 == F_109 () )
F_120 () ;
V_307 = V_308 + V_313 ;
F_2 ( L_147 ) ;
do {
struct V_314 * V_315 ;
struct V_14 * V_15 ;
unsigned long V_303 ;
if ( ! F_121 ( V_310 , V_307 ) )
break;
V_315 = (struct V_314 * ) V_307 ;
V_15 = (struct V_14 * ) ( V_315 + 1 ) ;
if ( F_122 ( V_310 , V_15 ) ) {
if ( ! ( V_15 -> V_10 & V_22 ) )
break;
V_303 = V_15 -> V_11 ;
V_307 = V_15 -> V_174 [ V_316 ] + V_313 ;
} else {
V_303 = V_315 -> V_317 ;
V_307 = ( unsigned long ) V_315 -> V_307 + V_313 ;
}
F_2 ( L_148 , V_303 , ( void * ) V_303 ) ;
#ifdef F_118
if ( ( V_303 + 8UL ) == ( unsigned long ) & V_318 ) {
int V_319 = V_305 -> V_320 ;
if ( V_305 -> V_321 && V_319 >= V_312 ) {
V_303 = V_305 -> V_321 [ V_319 - V_312 ] . V_40 ;
F_2 ( L_148 , V_303 , ( void * ) V_303 ) ;
V_312 ++ ;
}
}
#endif
} while ( ++ V_311 < 16 );
}
static inline struct V_322 * F_123 ( struct V_322 * V_323 )
{
unsigned long V_307 = V_323 -> V_324 [ 6 ] ;
if ( ! V_307 )
return NULL ;
return (struct V_322 * ) ( V_307 + V_313 ) ;
}
void T_8 F_5 ( char * V_325 , struct V_14 * V_15 )
{
static int V_326 ;
int V_311 = 0 ;
F_2 (
L_149
L_150
L_151
L_152 ) ;
F_2 ( L_153 , V_32 -> V_327 , F_124 ( V_32 ) , V_325 , ++ V_326 ) ;
F_4 ( V_328 , V_325 , V_15 , 0 , 255 , V_53 ) ;
__asm__ __volatile__("flushw");
F_84 ( V_15 ) ;
F_125 ( V_329 , V_330 ) ;
if ( V_15 -> V_10 & V_22 ) {
struct V_309 * V_310 = F_109 () ;
struct V_322 * V_323 = (struct V_322 * )
( V_15 -> V_174 [ V_331 ] + V_313 ) ;
while ( V_323 &&
V_311 ++ < 30 &&
F_121 ( V_310 , ( unsigned long ) V_323 ) ) {
F_2 ( L_154 , V_323 -> V_324 [ 7 ] ,
( void * ) V_323 -> V_324 [ 7 ] ) ;
V_323 = F_123 ( V_323 ) ;
}
F_115 ( ( unsigned int * ) V_15 -> V_11 ) ;
} else {
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
F_116 ( ( unsigned int V_30 * ) V_15 -> V_11 ) ;
}
if ( V_332 )
F_67 ( L_155 ) ;
if ( V_15 -> V_10 & V_22 )
F_126 ( V_274 ) ;
F_126 ( V_53 ) ;
}
void F_127 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
unsigned long V_303 = V_15 -> V_11 ;
unsigned long V_10 = V_15 -> V_10 ;
T_3 V_59 ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_156 , V_15 ,
0 , 0x10 , V_25 ) == V_21 )
goto V_52;
if ( V_10 & V_22 )
F_5 ( L_157 , V_15 ) ;
if ( F_6 ( V_23 ) )
V_303 = ( T_3 ) V_303 ;
if ( F_24 ( V_59 , ( T_3 V_30 * ) V_303 ) != - V_60 ) {
if ( ( V_59 & 0xc1ffc000 ) == 0x81700000 ) {
if ( F_128 ( V_59 , V_15 ) )
goto V_52;
} else if ( ( V_59 & 0xc1580000 ) == 0xc1100000 ) {
if ( F_25 ( V_59 , V_15 ) )
goto V_52;
} else if ( V_7 == V_8 ) {
if ( ( V_59 & V_333 ) == V_334 ) {
if ( ! F_129 ( V_15 , V_59 ) )
goto V_52;
} else {
struct V_297 * V_298 = V_299 ;
if ( F_112 ( V_15 , V_298 , true ) )
goto V_52;
}
}
}
V_18 . V_24 = V_25 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_335 ;
V_18 . V_29 = ( void V_30 * ) V_303 ;
V_18 . V_31 = 0 ;
F_7 ( V_25 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_130 ( struct V_14 * V_15 , unsigned long V_49 , unsigned long V_48 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_158 , V_15 ,
0 , 0x34 , V_53 ) == V_21 )
goto V_52;
if ( V_15 -> V_10 & V_22 ) {
F_131 ( V_15 , * ( ( unsigned int * ) V_15 -> V_11 ) ) ;
goto V_52;
}
if ( F_23 ( V_15 ) )
return;
V_18 . V_24 = V_81 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_336 ;
V_18 . V_29 = ( void V_30 * ) V_49 ;
V_18 . V_31 = 0 ;
F_7 ( V_81 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_132 ( struct V_14 * V_15 , unsigned long V_55 , unsigned long V_56 )
{
T_1 V_18 ;
if ( F_4 ( V_19 , L_158 , V_15 ,
0 , 0x34 , V_53 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
F_131 ( V_15 , * ( ( unsigned int * ) V_15 -> V_11 ) ) ;
return;
}
if ( F_23 ( V_15 ) )
return;
V_18 . V_24 = V_81 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_336 ;
V_18 . V_29 = ( void V_30 * ) V_55 ;
V_18 . V_31 = 0 ;
F_7 ( V_81 , & V_18 , V_32 ) ;
}
void F_133 ( struct V_14 * V_15 )
{
enum V_50 V_51 = F_18 () ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_159 , V_15 ,
0 , 0x11 , V_25 ) == V_21 )
goto V_52;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_25 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_337 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_25 , & V_18 , V_32 ) ;
V_52:
F_19 ( V_51 ) ;
}
void F_134 ( struct V_14 * V_15 )
{
F_133 ( V_15 ) ;
}
void F_135 ( struct V_14 * V_15 )
{
F_18 () ;
F_5 ( L_160 , V_15 ) ;
}
void F_136 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_161 , V_15 ) ;
}
void F_137 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_162 , V_15 ) ;
}
void F_138 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_163 , V_15 ) ;
}
void F_139 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_164 , V_15 ) ;
}
void F_140 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_165 , V_15 ) ;
}
void F_141 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_166 , V_15 ) ;
}
void F_142 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_167 , V_15 ) ;
}
void F_143 ( struct V_14 * V_15 )
{
F_18 () ;
F_5 ( L_168 , V_15 ) ;
}
void F_144 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_169 , V_15 ) ;
}
void F_145 ( struct V_14 * V_15 )
{
F_18 () ;
F_5 ( L_170 , V_15 ) ;
}
void F_146 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_171 , V_15 ) ;
}
void F_147 ( struct V_14 * V_15 )
{
F_18 () ;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_172 , V_15 ) ;
}
void F_148 ( struct V_14 * V_15 )
{
V_15 -> V_174 [ V_338 ] = F_149 ( V_15 -> V_10 ) ;
V_15 -> V_11 = V_15 -> V_12 ;
V_15 -> V_12 += 4 ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
}
void T_9 F_150 ( struct V_309 * V_339 )
{
int V_104 = F_151 () ;
struct V_265 * V_2 = & V_267 [ V_104 ] ;
V_2 -> V_340 = V_339 ;
V_2 -> V_341 = 0 ;
}
void T_4 F_152 ( void )
{
F_153 ( V_342 != F_154 ( struct V_309 , V_343 ) ||
V_344 != F_154 ( struct V_309 , V_39 ) ||
V_345 != F_154 ( struct V_309 , V_104 ) ||
V_346 != F_154 ( struct V_309 , V_347 ) ||
V_348 != F_154 ( struct V_309 , V_308 ) ||
V_349 != F_154 ( struct V_309 ,
V_350 ) ||
V_351 != F_154 ( struct V_309 , V_352 ) ||
V_353 != F_154 ( struct V_309 , V_354 ) ||
V_355 != F_154 ( struct V_309 ,
V_322 ) ||
V_356 != F_154 ( struct V_309 ,
V_357 ) ||
V_358 != F_154 ( struct V_309 , V_359 ) ||
V_360 != F_154 ( struct V_309 , V_289 ) ||
V_361 != F_154 ( struct V_309 ,
V_362 ) ||
V_363 != F_154 ( struct V_309 , V_364 ) ||
V_365 != F_154 ( struct V_309 ,
V_366 ) ||
V_367 != F_154 ( struct V_309 ,
V_368 ) ||
V_369 != F_154 ( struct V_309 ,
V_370 ) ||
V_371 != F_154 ( struct V_309 , V_372 ) ||
( V_371 & ( 64 - 1 ) ) ) ;
F_153 ( V_373 != F_154 ( struct V_265 ,
V_340 ) ||
( V_374 !=
F_154 ( struct V_265 , V_341 ) ) ||
( V_375 !=
F_154 ( struct V_265 , V_376 ) ) ||
( V_377 !=
F_154 ( struct V_265 , V_378 ) ) ||
( V_379 !=
F_154 ( struct V_265 , V_380 ) ) ||
( V_381 !=
F_154 ( struct V_265 , V_268 ) ) ||
( V_382 !=
F_154 ( struct V_265 , V_383 ) ) ||
( V_384 !=
F_154 ( struct V_265 , V_276 ) ) ||
( V_385 !=
F_154 ( struct V_265 , V_386 ) ) ||
( V_387 !=
F_154 ( struct V_265 , V_388 ) ) ||
( V_389 !=
F_154 ( struct V_265 , V_390 ) ) ||
( V_391 !=
F_154 ( struct V_265 , V_392 ) ) ||
( V_393 !=
F_154 ( struct V_265 , V_394 ) ) ||
( V_395 !=
F_154 ( struct V_265 , V_396 ) ) ||
( V_397 !=
F_154 ( struct V_265 , V_398 ) ) ||
( V_399 !=
F_154 ( struct V_265 , V_400 ) ) ||
( V_401 !=
F_154 ( struct V_265 , V_402 ) ) ||
( V_403 !=
F_154 ( struct V_265 , V_404 ) ) ||
( V_405 !=
F_154 ( struct V_265 , V_406 ) ) ) ;
F_153 ( ( V_407 !=
F_154 ( struct V_408 , V_409 ) ) ||
( V_410 !=
F_154 ( struct V_408 , V_411 ) ) ||
( V_412 !=
F_154 ( struct V_408 , V_413 ) ) ||
( V_414 !=
F_154 ( struct V_408 , V_415 ) ) ||
( V_416 !=
F_154 ( struct V_408 , V_417 ) ) ||
( V_418 !=
F_154 ( struct V_408 , V_419 ) ) ) ;
F_155 ( & V_420 ) ;
V_32 -> V_421 = & V_420 ;
}
