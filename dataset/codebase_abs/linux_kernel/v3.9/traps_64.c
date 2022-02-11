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
char V_17 [ 32 ] ;
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
char V_17 [ 32 ] ;
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
T_1 V_18 ;
if ( F_4 ( V_19 , L_12 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
F_2 ( L_13
L_14 , V_48 , V_49 ) ;
F_5 ( L_15 , V_15 ) ;
}
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_50 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_51 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_50 , & V_18 , V_32 ) ;
}
void F_18 ( struct V_14 * V_15 , unsigned long V_48 , unsigned long V_49 )
{
if ( F_4 ( V_33 , L_16 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_17 ( V_15 , V_48 , V_49 ) ;
}
void F_19 ( struct V_14 * V_15 , unsigned long V_52 , unsigned long V_53 )
{
unsigned short type = ( V_53 >> 16 ) ;
unsigned short V_54 = ( V_53 & 0xffff ) ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_12 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
F_2 ( L_17
L_18 ,
V_52 , V_54 , type ) ;
F_5 ( L_15 , V_15 ) ;
}
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_50 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_51 ;
V_18 . V_29 = ( void V_30 * ) V_52 ;
V_18 . V_31 = 0 ;
F_7 ( V_50 , & V_18 , V_32 ) ;
}
void F_20 ( struct V_14 * V_15 , unsigned long V_52 , unsigned long V_53 )
{
if ( F_4 ( V_33 , L_16 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_19 ( V_15 , V_52 , V_53 ) ;
}
void F_21 ( struct V_14 * V_15 , unsigned long V_48 , unsigned long V_49 )
{
T_1 V_18 ;
if ( F_4 ( V_19 , L_19 , V_15 ,
0 , 0x30 , V_20 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
const struct V_55 * V_56 ;
V_56 = F_22 ( V_15 -> V_11 ) ;
if ( V_56 ) {
#ifdef F_23
F_2 ( L_20 , V_15 -> V_11 ) ;
F_2 ( L_21 ,
V_15 -> V_11 , V_56 -> V_57 ) ;
#endif
V_15 -> V_11 = V_56 -> V_57 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
F_2 ( L_22
L_14 , V_48 , V_49 ) ;
F_5 ( L_23 , V_15 ) ;
}
V_18 . V_24 = V_50 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_51 ;
V_18 . V_29 = ( void V_30 * ) V_49 ;
V_18 . V_31 = 0 ;
F_7 ( V_50 , & V_18 , V_32 ) ;
}
void F_24 ( struct V_14 * V_15 , unsigned long V_48 , unsigned long V_49 )
{
if ( F_4 ( V_33 , L_24 , V_15 ,
0 , 0x30 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_21 ( V_15 , V_48 , V_49 ) ;
}
void F_25 ( struct V_14 * V_15 , unsigned long V_52 , unsigned long V_53 )
{
unsigned short type = ( V_53 >> 16 ) ;
unsigned short V_54 = ( V_53 & 0xffff ) ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_19 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
const struct V_55 * V_56 ;
V_56 = F_22 ( V_15 -> V_11 ) ;
if ( V_56 ) {
#ifdef F_23
F_2 ( L_20 , V_15 -> V_11 ) ;
F_2 ( L_21 ,
V_15 -> V_11 , V_56 -> V_57 ) ;
#endif
V_15 -> V_11 = V_56 -> V_57 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
F_2 ( L_25
L_18 ,
V_52 , V_54 , type ) ;
F_5 ( L_23 , V_15 ) ;
}
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_50 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_51 ;
V_18 . V_29 = ( void V_30 * ) V_52 ;
V_18 . V_31 = 0 ;
F_7 ( V_50 , & V_18 , V_32 ) ;
}
void F_26 ( struct V_14 * V_15 , unsigned long V_52 , unsigned long V_53 )
{
if ( F_4 ( V_33 , L_24 , V_15 ,
0 , 0x8 , V_20 ) == V_21 )
return;
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_25 ( V_15 , V_52 , V_53 ) ;
}
static void F_27 ( void )
{
unsigned long V_58 ;
if ( V_7 != V_44 )
F_28 () ;
for ( V_58 = 0 ; V_58 < ( V_59 << 1 ) ; V_58 += 32 ) {
F_29 ( V_58 , 0x0 ) ;
F_30 ( V_58 , 0x0 ) ;
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
static void F_31 ( void )
{
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (ESTATE_ERR_ALL),
"i" (ASI_ESTATE_ERROR_EN));
}
static void F_32 ( unsigned long V_60 , unsigned long V_61 , unsigned long V_62 , unsigned long V_63 )
{
unsigned short V_64 ;
char V_65 [ 64 ] , * V_2 ;
if ( V_62 & V_63 ) {
V_64 = V_66 [ V_62 & 0xff ] ;
if ( F_11 ( V_64 , V_60 , V_65 , sizeof( V_65 ) ) < 0 )
V_2 = V_67 ;
else
V_2 = V_65 ;
F_2 ( V_68 L_26
L_27 ,
F_33 () , V_64 , V_2 ) ;
}
if ( V_61 & V_63 ) {
V_64 = V_66 [ V_61 & 0xff ] ;
if ( F_11 ( V_64 , V_60 , V_65 , sizeof( V_65 ) ) < 0 )
V_2 = V_67 ;
else
V_2 = V_65 ;
F_2 ( V_68 L_28
L_27 ,
F_33 () , V_64 , V_2 ) ;
}
}
static void F_34 ( unsigned long V_69 , unsigned long V_60 , unsigned long V_61 , unsigned long V_62 , int V_70 , struct V_14 * V_15 )
{
F_2 ( V_68 L_29
L_30 ,
F_33 () , V_69 , V_60 , V_62 , V_61 , V_70 ) ;
F_32 ( V_60 , V_61 , V_62 , V_71 ) ;
F_4 ( V_19 , L_31 , V_15 ,
0 , V_72 , V_20 ) ;
F_31 () ;
}
static void F_35 ( unsigned long V_69 , unsigned long V_60 , unsigned long V_61 , unsigned long V_62 , unsigned long V_13 , int V_70 , struct V_14 * V_15 )
{
T_1 V_18 ;
F_2 ( V_68 L_32
L_33 ,
F_33 () , V_69 , V_60 , V_62 , V_61 , V_13 , V_70 ) ;
F_32 ( V_60 , V_61 , V_62 , V_73 ) ;
F_4 ( V_19 , L_34 , V_15 ,
0 , V_13 , V_20 ) ;
if ( V_15 -> V_10 & V_22 ) {
if ( V_70 )
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_35 , V_15 ) ;
}
F_27 () ;
F_31 () ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_74 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_75 ;
V_18 . V_29 = ( void * ) 0 ;
V_18 . V_31 = 0 ;
F_7 ( V_74 , & V_18 , V_32 ) ;
}
void F_36 ( struct V_14 * V_15 , unsigned long V_76 , unsigned long V_60 )
{
unsigned long V_69 , V_13 , V_61 , V_62 ;
int V_70 ;
V_69 = ( V_76 & V_77 ) >> V_78 ;
V_13 = ( V_76 & V_79 ) >> V_80 ;
V_70 = ( V_76 & V_81 ) ? 1 : 0 ;
V_62 = ( V_76 & V_82 ) >> V_83 ;
V_61 = ( V_76 & V_84 ) >> V_85 ;
#ifdef F_37
if ( V_13 == V_86 &&
V_87 && V_88 == F_33 () ) {
F_27 () ;
F_31 () ;
V_89 = 1 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
#endif
if ( V_69 & V_90 )
F_35 ( V_69 , V_60 , V_61 , V_62 , V_13 , V_70 , V_15 ) ;
if ( V_13 == V_72 ) {
if ( V_69 & V_90 ) {
if ( V_61 & V_71 ) {
__asm__ __volatile__(
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (udbh & UDBE_CE),
"r" (0x0), "i" (ASI_UDB_ERROR_W));
}
if ( V_62 & V_71 ) {
__asm__ __volatile__(
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (udbl & UDBE_CE),
"r" (0x18), "i" (ASI_UDB_ERROR_W));
}
}
F_34 ( V_69 , V_60 , V_61 , V_62 , V_70 , V_15 ) ;
}
}
void F_38 ( void )
{
unsigned long V_91 ;
F_2 ( L_36 ,
F_33 () ) ;
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (dcr)
: "i" (ASI_DCU_CONTROL_REG));
V_91 |= ( V_92 | V_93 | V_94 | V_95 ) ;
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (dcr), "i" (ASI_DCU_CONTROL_REG));
}
static inline struct V_96 * F_39 ( unsigned long V_69 )
{
struct V_96 * V_2 ;
int V_97 = F_33 () ;
if ( ! V_98 )
return NULL ;
V_2 = V_98 + ( V_97 * 2 ) ;
if ( ( V_69 & V_99 ) != 0UL )
V_2 ++ ;
return V_2 ;
}
void T_3 F_40 ( void )
{
unsigned long V_100 , V_101 , V_102 , V_103 ;
int V_3 , V_104 ;
V_100 = 0UL ;
V_101 = ~ 0UL ;
for ( V_3 = 0 ; V_3 < V_105 ; V_3 ++ ) {
unsigned long V_106 ;
V_106 = F_41 ( V_3 ) . V_107 ;
if ( ! V_106 )
continue;
if ( V_106 > V_100 )
V_100 = V_106 ;
V_106 = F_41 ( V_3 ) . V_108 ;
if ( V_106 < V_101 )
V_101 = V_106 ;
}
if ( V_100 == 0UL || V_101 == ~ 0UL ) {
F_42 ( L_37
L_38 ) ;
F_43 () ;
}
V_109 = ( 2 * V_100 ) ;
V_110 = V_101 ;
V_111 = F_44 ( V_109 ) ;
if ( V_111 == ~ 0UL ) {
F_42 ( L_39
L_40 ,
V_109 ) ;
F_43 () ;
}
V_104 = V_105 * ( 2 * sizeof( struct V_96 ) ) ;
for ( V_102 = 0 ; V_102 < V_112 ; V_102 ++ ) {
if ( ( V_59 << V_102 ) >= V_104 )
break;
}
V_98 = (struct V_96 * )
F_45 ( V_113 , V_102 ) ;
if ( ! V_98 ) {
F_42 ( L_41
L_42 , V_104 ) ;
F_43 () ;
}
memset ( V_98 , 0 , V_59 << V_102 ) ;
for ( V_3 = 0 ; V_3 < 2 * V_105 ; V_3 ++ )
V_98 [ V_3 ] . V_69 = V_114 ;
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
if ( ( V_103 >> 32 ) == V_115 ||
( V_103 >> 32 ) == V_116 ) {
V_117 = & V_118 [ 0 ] ;
V_119 = V_120 ;
} else if ( ( V_103 >> 32 ) == 0x003e0015 ) {
V_117 = & V_121 [ 0 ] ;
V_119 = V_122 ;
} else {
V_117 = & V_123 [ 0 ] ;
V_119 = V_124 ;
}
memcpy ( V_125 , V_126 , ( 8 * 4 ) ) ;
memcpy ( V_127 , V_128 , ( 8 * 4 ) ) ;
memcpy ( V_129 , V_130 , ( 8 * 4 ) ) ;
memcpy ( V_131 , V_132 , ( 8 * 4 ) ) ;
memcpy ( V_133 , V_134 , ( 8 * 4 ) ) ;
memcpy ( V_135 , V_136 , ( 8 * 4 ) ) ;
memcpy ( V_137 , V_134 , ( 8 * 4 ) ) ;
memcpy ( V_138 , V_136 , ( 8 * 4 ) ) ;
if ( V_7 == V_139 ) {
memcpy ( V_140 , V_141 , ( 8 * 4 ) ) ;
memcpy ( V_142 , V_143 , ( 8 * 4 ) ) ;
memcpy ( V_144 , V_145 , ( 8 * 4 ) ) ;
memcpy ( V_146 , V_147 , ( 8 * 4 ) ) ;
}
F_46 ( V_148 ) ;
}
static void F_47 ( void )
{
unsigned long V_149 = V_111 ;
unsigned long V_150 = V_110 ;
unsigned long V_151 = V_109 ;
__asm__ __volatile__("1: subcc %0, %4, %0\n\t"
" bne,pt %%xcc, 1b\n\t"
" ldxa [%2 + %0] %3, %%g0\n\t"
: "=&r" (flush_size)
: "0" (flush_size), "r" (flush_base),
"i" (ASI_PHYS_USE_EC), "r" (flush_linesize));
}
static void F_48 ( unsigned long V_152 )
{
unsigned long V_153 ;
V_152 &= ~ ( 8UL - 1UL ) ;
V_152 = ( V_111 +
( V_152 & ( ( V_109 >> 1UL ) - 1UL ) ) ) ;
V_153 = V_152 + ( V_109 >> 1UL ) ;
__asm__ __volatile__("ldxa [%0] %2, %%g0\n\t"
"ldxa [%1] %2, %%g0\n\t"
"membar #Sync"
:
: "r" (physaddr), "r" (alias),
"i" (ASI_PHYS_USE_EC));
}
static void F_49 ( void )
{
unsigned int V_154 , V_155 ;
unsigned long V_52 ;
V_154 = F_50 () . V_154 ;
V_155 = F_50 () . V_155 ;
for ( V_52 = 0 ; V_52 < V_154 ; V_52 += V_155 ) {
__asm__ __volatile__("stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (addr | (2 << 3)),
"i" (ASI_IC_TAG));
}
}
static void F_51 ( void )
{
unsigned long V_156 ;
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
"or %0, %2, %%g1\n\t"
"stxa %%g1, [%%g0] %1\n\t"
"membar #Sync"
: "=r" (dcu_save)
: "i" (ASI_DCU_CONTROL_REG), "i" (DCU_IC)
: "g1");
F_49 () ;
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (dcu_save), "i" (ASI_DCU_CONTROL_REG));
}
static void F_52 ( void )
{
unsigned int V_157 , V_158 ;
unsigned long V_52 ;
V_157 = F_50 () . V_157 ;
V_158 = F_50 () . V_158 ;
for ( V_52 = 0 ; V_52 < V_157 ; V_52 += V_158 ) {
__asm__ __volatile__("stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (addr), "i" (ASI_DCACHE_TAG));
}
}
static void F_53 ( void )
{
unsigned int V_157 , V_158 ;
unsigned long V_52 ;
V_157 = F_50 () . V_157 ;
V_158 = F_50 () . V_158 ;
for ( V_52 = 0 ; V_52 < V_157 ; V_52 += V_158 ) {
unsigned long V_159 = ( V_52 >> 14 ) ;
unsigned long line ;
__asm__ __volatile__("membar #Sync\n\t"
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (tag), "r" (addr),
"i" (ASI_DCACHE_UTAG));
for ( line = V_52 ; line < V_52 + V_158 ; line += 8 )
__asm__ __volatile__("membar #Sync\n\t"
"stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (line),
"i" (ASI_DCACHE_DATA));
}
}
static inline unsigned long F_54 ( unsigned long V_69 )
{
unsigned long V_160 = 0 ;
int V_3 ;
for ( V_3 = 0 ; V_117 [ V_3 ] . V_161 ; V_3 ++ ) {
if ( ( V_160 = ( V_69 & V_117 [ V_3 ] . V_161 ) ) != 0UL )
return V_160 ;
}
return V_160 ;
}
static const char * F_55 ( unsigned long V_63 )
{
int V_3 ;
for ( V_3 = 0 ; V_117 [ V_3 ] . V_161 ; V_3 ++ ) {
if ( ( V_63 & V_117 [ V_3 ] . V_161 ) != 0UL )
return V_117 [ V_3 ] . V_162 ;
}
return L_43 ;
}
static void F_56 ( struct V_14 * V_15 , struct V_96 * V_18 ,
unsigned long V_69 , unsigned long V_60 , int V_163 )
{
unsigned long V_164 ;
char V_165 [ 256 ] ;
F_2 ( L_44 L_45 ,
( V_163 ? V_68 : V_166 ) , F_33 () ,
V_69 , V_60 ,
( V_69 & V_99 ) ? 1 : 0 ) ;
F_2 ( L_44 L_46 ,
( V_163 ? V_68 : V_166 ) , F_33 () ,
V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_167 [ V_168 ] , V_15 -> V_10 ) ;
F_2 ( L_44 L_47 ,
( V_163 ? V_68 : V_166 ) , F_33 () ) ;
F_2 ( L_48 , ( void * ) V_15 -> V_11 ) ;
F_2 ( L_44 L_49 ,
( V_163 ? V_68 : V_166 ) , F_33 () ,
( V_69 & V_169 ) >> V_170 ,
( V_69 & V_171 ) >> V_172 ,
( V_69 & V_173 ) ? L_50 : L_51 ,
( V_69 & V_174 ) ? L_52 : L_51 ) ;
V_164 = F_54 ( V_69 ) ;
F_2 ( L_44 L_53 ,
( V_163 ? V_68 : V_166 ) , F_33 () ,
V_164 , F_55 ( V_164 ) ) ;
#define F_57 (CHAFSR_IVC | CHAFSR_IVU | \
CHAFSR_CPC | CHAFSR_CPU | \
CHAFSR_UE | CHAFSR_CE | \
CHAFSR_EDC | CHAFSR_EDU | \
CHAFSR_UCC | CHAFSR_UCU | \
CHAFSR_WDU | CHAFSR_WDC)
#define F_58 (CHAFSR_EMC | CHAFSR_EMU)
if ( V_69 & F_57 ) {
int V_175 ;
int V_40 ;
V_175 = ( V_69 & V_171 ) >> V_172 ;
V_175 = V_176 [ V_175 ] ;
V_40 = F_11 ( V_175 , V_60 , V_165 , sizeof( V_165 ) ) ;
if ( V_40 != - 1 )
F_2 ( L_44 L_54 ,
( V_163 ? V_68 : V_166 ) ,
F_33 () , V_165 ) ;
} else if ( V_69 & F_58 ) {
int V_175 ;
int V_40 ;
V_175 = ( V_69 & V_169 ) >> V_170 ;
V_175 = V_177 [ V_175 ] ;
V_40 = F_11 ( V_175 , V_60 , V_165 , sizeof( V_165 ) ) ;
if ( V_40 != - 1 )
F_2 ( L_44 L_55 ,
( V_163 ? V_68 : V_166 ) ,
F_33 () , V_165 ) ;
}
F_2 ( L_44 L_56 ,
( V_163 ? V_68 : V_166 ) , F_33 () ,
( int ) V_18 -> V_178 ,
V_18 -> V_179 ,
V_18 -> V_180 ,
V_18 -> V_181 ) ;
F_2 ( L_44 L_57 ,
( V_163 ? V_68 : V_166 ) , F_33 () ,
V_18 -> V_182 [ 0 ] ,
V_18 -> V_182 [ 1 ] ,
V_18 -> V_182 [ 2 ] ,
V_18 -> V_182 [ 3 ] ) ;
F_2 ( L_44 L_58
L_59 ,
( V_163 ? V_68 : V_166 ) , F_33 () ,
( int ) V_18 -> V_183 ,
V_18 -> V_184 ,
V_18 -> V_185 ,
V_18 -> V_186 ,
V_18 -> V_187 ,
V_18 -> V_188 ) ;
F_2 ( L_44 L_60 ,
( V_163 ? V_68 : V_166 ) , F_33 () ,
V_18 -> V_189 [ 0 ] ,
V_18 -> V_189 [ 1 ] ,
V_18 -> V_189 [ 2 ] ,
V_18 -> V_189 [ 3 ] ) ;
F_2 ( L_44 L_61 ,
( V_163 ? V_68 : V_166 ) , F_33 () ,
V_18 -> V_189 [ 4 ] ,
V_18 -> V_189 [ 5 ] ,
V_18 -> V_189 [ 6 ] ,
V_18 -> V_189 [ 7 ] ) ;
F_2 ( L_44 L_62 ,
( V_163 ? V_68 : V_166 ) , F_33 () ,
( int ) V_18 -> V_190 , V_18 -> V_191 ) ;
F_2 ( L_44 L_63 ,
( V_163 ? V_68 : V_166 ) , F_33 () ,
V_18 -> V_192 [ 0 ] ,
V_18 -> V_192 [ 1 ] ,
V_18 -> V_192 [ 2 ] ,
V_18 -> V_192 [ 3 ] ) ;
V_69 = ( V_69 & ~ V_164 ) & V_119 ;
while ( V_69 != 0UL ) {
unsigned long V_63 = F_54 ( V_69 ) ;
F_2 ( L_44 L_64 ,
( V_163 ? V_68 : V_166 ) ,
V_63 , F_55 ( V_63 ) ) ;
V_69 &= ~ V_63 ;
}
if ( ! V_163 )
F_2 ( V_166 L_65 ) ;
}
static int F_59 ( struct V_96 * V_193 )
{
unsigned long V_69 , V_60 ;
int V_40 = 0 ;
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
: "=r" (afsr)
: "i" (ASI_AFSR));
if ( ( V_69 & V_119 ) != 0 ) {
if ( V_193 != NULL ) {
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
: "=r" (afar)
: "i" (ASI_AFAR));
V_193 -> V_69 = V_69 ;
V_193 -> V_60 = V_60 ;
}
V_40 = 1 ;
}
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync\n\t"
: : "r" (afsr), "i" (ASI_AFSR));
return V_40 ;
}
void F_60 ( struct V_14 * V_15 , unsigned long V_69 , unsigned long V_60 )
{
struct V_96 V_194 , * V_2 ;
int V_163 ;
F_47 () ;
V_2 = F_39 ( V_69 ) ;
if ( ! V_2 ) {
F_42 ( L_66 ,
V_69 , V_60 ) ;
F_42 ( L_67 ,
F_33 () , V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_10 ) ;
F_43 () ;
}
memcpy ( & V_194 , V_2 , sizeof( V_194 ) ) ;
if ( V_2 -> V_69 != V_69 || V_2 -> V_60 != V_60 )
V_194 . V_69 = V_114 ;
else
V_2 -> V_69 = V_114 ;
F_51 () ;
F_52 () ;
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
V_163 = 1 ;
if ( V_69 & ( V_195 | V_196 | V_197 ) )
V_163 = 0 ;
if ( F_59 ( & V_194 ) ) {
unsigned long V_198 = V_194 . V_69 ;
if ( V_198 & ( V_199 | V_200 |
V_201 | V_202 |
V_203 | V_204 |
V_205 | V_206 ) )
V_163 = 0 ;
}
F_56 ( V_15 , & V_194 , V_69 , V_60 , V_163 ) ;
if ( ! V_163 )
F_61 ( L_68 ) ;
F_47 () ;
}
static int F_62 ( unsigned long V_152 )
{
unsigned long V_207 ;
unsigned long V_208 , V_209 ;
int V_40 ;
__asm__ __volatile__("ldxa [%%g0] %2, %0\n\t"
"andn %0, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %2\n\t"
"membar #Sync"
: "=&r" (orig_estate)
: "i" (ESTATE_ERROR_CEEN),
"i" (ASI_ESTATE_ERROR_EN)
: "g1");
V_152 &= ~ ( 8UL - 1UL ) ;
V_208 = ( V_111 +
( V_152 & ( ( V_109 >> 1 ) - 1 ) ) ) ;
V_209 = V_208 + ( V_109 >> 1 ) ;
__asm__ __volatile__("ldxa [%0] %3, %%g0\n\t"
"ldxa [%1] %3, %%g0\n\t"
"casxa [%2] %3, %%g0, %%g0\n\t"
"ldxa [%0] %3, %%g0\n\t"
"ldxa [%1] %3, %%g0\n\t"
"membar #Sync"
:
: "r" (alias1), "r" (alias2),
"r" (physaddr), "i" (ASI_PHYS_USE_EC));
if ( F_59 ( NULL ) ) {
__asm__ __volatile__("ldxa [%0] %1, %%g0\n\t"
"membar #Sync"
: : "r" (physaddr), "i" (ASI_PHYS_USE_EC));
if ( F_59 ( NULL ) )
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
static int F_63 ( unsigned long V_36 )
{
unsigned long V_210 = V_148 + V_36 ;
if ( V_210 > ( unsigned long ) V_211 )
return 0 ;
return F_64 ( V_210 ) ;
}
void F_65 ( struct V_14 * V_15 , unsigned long V_69 , unsigned long V_60 )
{
struct V_96 V_194 , * V_2 ;
int V_163 , V_212 ;
V_2 = F_39 ( V_69 ) ;
if ( ! V_2 ) {
F_42 ( L_69 ,
V_69 , V_60 ) ;
F_42 ( L_67 ,
F_33 () , V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_10 ) ;
F_43 () ;
}
memcpy ( & V_194 , V_2 , sizeof( V_194 ) ) ;
if ( V_2 -> V_69 != V_69 || V_2 -> V_60 != V_60 )
V_194 . V_69 = V_114 ;
else
V_2 -> V_69 = V_114 ;
V_212 = F_63 ( V_60 ) ;
if ( V_212 && ( V_69 & V_213 ) != 0UL ) {
F_62 ( V_60 ) ;
}
{
int V_214 , V_215 ;
V_214 = V_215 = 0 ;
if ( ( V_69 & V_216 ) != 0UL ) {
if ( ( V_69 & V_119 ) == V_216 )
V_215 = 1 ;
else
V_214 = 1 ;
} else if ( ( V_69 & V_217 ) != 0UL ) {
if ( ( V_69 & V_119 ) == V_217 )
V_215 = 1 ;
else
V_214 = 1 ;
}
F_51 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_IC)
: "g1");
if ( V_214 )
F_47 () ;
else if ( V_215 )
F_48 ( V_60 ) ;
}
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_CEEN)
: "g1");
V_163 = 1 ;
if ( V_69 & ( V_195 | V_196 | V_197 ) )
V_163 = 0 ;
( void ) F_59 ( & V_194 ) ;
F_56 ( V_15 , & V_194 , V_69 , V_60 , V_163 ) ;
if ( ! V_163 )
F_61 ( L_70 ) ;
}
void F_66 ( struct V_14 * V_15 , unsigned long V_69 , unsigned long V_60 )
{
struct V_96 V_194 , * V_2 ;
int V_163 , V_212 ;
#ifdef F_37
if ( V_87 && V_88 == F_33 () ) {
F_51 () ;
F_52 () ;
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
( void ) F_59 ( NULL ) ;
V_89 = 1 ;
V_15 -> V_11 += 4 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
#endif
V_2 = F_39 ( V_69 ) ;
if ( ! V_2 ) {
F_42 ( L_71 ,
V_69 , V_60 ) ;
F_42 ( L_67 ,
F_33 () , V_15 -> V_11 , V_15 -> V_12 , V_15 -> V_10 ) ;
F_43 () ;
}
memcpy ( & V_194 , V_2 , sizeof( V_194 ) ) ;
if ( V_2 -> V_69 != V_69 || V_2 -> V_60 != V_60 )
V_194 . V_69 = V_114 ;
else
V_2 -> V_69 = V_114 ;
V_212 = F_63 ( V_60 ) ;
{
int V_214 , V_215 ;
V_214 = V_215 = 0 ;
if ( ( V_69 & V_200 ) != 0UL ) {
if ( ( V_69 & V_119 ) == V_200 )
V_215 = 1 ;
else
V_214 = 1 ;
} else if ( ( V_69 & V_205 ) != 0UL ) {
if ( ( V_69 & V_119 ) == V_205 )
V_215 = 1 ;
else
V_214 = 1 ;
}
F_51 () ;
F_52 () ;
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_IC | DCU_DC)
: "g1");
if ( V_214 )
F_47 () ;
else if ( V_215 )
F_48 ( V_60 ) ;
}
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_NCEEN | ESTATE_ERROR_CEEN)
: "g1");
V_163 = 1 ;
if ( V_69 & ( V_195 | V_196 | V_197 ) )
V_163 = 0 ;
if ( F_59 ( & V_194 ) ) {
unsigned long V_198 = V_194 . V_69 ;
if ( V_198 & ( V_199 | V_200 |
V_201 | V_202 |
V_203 | V_204 |
V_205 | V_206 ) )
V_163 = 0 ;
}
F_56 ( V_15 , & V_194 , V_69 , V_60 , V_163 ) ;
if ( V_163 && V_212 ) {
if ( ( V_15 -> V_10 & V_22 ) == 0UL ) {
V_163 = 1 ;
} else {
const struct V_55 * V_56 ;
V_56 = F_22 ( V_15 -> V_11 ) ;
if ( V_56 ) {
V_163 = 1 ;
} else {
V_163 = 0 ;
}
if ( V_163 ) {
if ( F_67 ( V_60 >> V_218 ) )
F_68 ( F_69 ( V_60 >> V_218 ) ) ;
else
V_163 = 0 ;
if ( V_163 ) {
V_15 -> V_11 = V_56 -> V_57 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
}
}
}
} else {
V_163 = 0 ;
}
if ( ! V_163 )
F_61 ( L_72 ) ;
}
void F_70 ( int type , struct V_14 * V_15 )
{
if ( type & 0x1 )
F_49 () ;
else
F_53 () ;
F_52 () ;
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
F_33 () ,
( type & 0x1 ) ? 'I' : 'D' ,
V_15 -> V_11 ) ;
F_2 ( V_5 L_48 , ( void * ) V_15 -> V_11 ) ;
F_61 ( L_74 ) ;
}
F_2 ( V_68 L_73 ,
F_33 () ,
( type & 0x1 ) ? 'I' : 'D' ,
V_15 -> V_11 ) ;
F_2 ( V_68 L_48 , ( void * ) V_15 -> V_11 ) ;
}
static const char * F_71 ( T_4 type )
{
static const char * V_219 [ V_220 ] = {
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79 ,
L_80 ,
L_81 ,
} ;
if ( type < V_220 )
return V_219 [ type ] ;
return L_82 ;
}
static void F_72 ( T_5 V_221 )
{
static const char * V_222 [] = {
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
static const char * V_223 [] = {
L_92 ,
L_93 ,
L_94 ,
L_95 ,
} ;
static const char * V_224 [] = {
L_96 ,
L_97 ,
L_98 ,
L_99 ,
} ;
T_5 V_225 , V_226 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_73 ( V_222 ) ; V_3 ++ ) {
if ( V_221 & ( 1U << V_3 ) ) {
const char * V_227 = V_222 [ V_3 ] ;
F_74 ( L_100 , V_227 ) ;
}
}
V_225 = ( ( V_221 & V_228 ) >>
V_229 ) ;
F_74 ( L_100 , V_223 [ V_225 ] ) ;
V_226 = ( ( V_221 & V_230 ) >>
V_231 ) ;
F_74 ( L_100 , V_224 [ V_226 ] ) ;
if ( V_221 & V_232 )
F_74 ( L_101 ) ;
}
static void F_75 ( const char * V_233 , struct V_14 * V_15 )
{
unsigned int V_234 ;
T_6 V_52 ;
if ( ! ( V_15 -> V_10 & V_22 ) )
return;
V_234 = * ( unsigned int * ) V_15 -> V_11 ;
V_52 = F_76 ( V_15 , V_234 , 0 ) ;
F_2 ( L_102 ,
V_233 , V_52 ) ;
}
static void F_77 ( struct V_14 * V_15 , struct V_235 * V_236 ,
int V_97 , const char * V_233 , T_7 * V_237 )
{
T_6 * V_238 = ( T_6 * ) V_236 ;
T_5 V_221 ;
int V_239 ;
F_2 ( L_103 , V_233 , V_97 ) ;
F_2 ( L_104 ,
V_233 , V_15 -> V_11 , ( void * ) V_15 -> V_11 ) ;
F_2 ( L_105 ,
V_233 , V_238 [ 0 ] , V_238 [ 1 ] , V_238 [ 2 ] , V_238 [ 3 ] ) ;
F_2 ( L_106 ,
V_233 , V_238 [ 4 ] , V_238 [ 5 ] , V_238 [ 6 ] , V_238 [ 7 ] ) ;
F_2 ( L_107 ,
V_233 , V_236 -> V_240 , V_236 -> V_241 ) ;
F_2 ( L_108 , V_233 , F_71 ( V_236 -> V_242 ) ) ;
V_221 = V_236 -> V_243 ;
F_2 ( L_109 , V_233 , V_221 ) ;
F_72 ( V_221 ) ;
F_74 ( L_110 ) ;
if ( V_221 & ( V_244 |
V_245 |
V_246 ) ) {
F_2 ( L_111 , V_233 , V_236 -> V_247 ) ;
if ( V_236 -> V_247 == ~ ( T_6 ) 0 )
F_75 ( V_233 , V_15 ) ;
}
if ( V_221 & ( V_244 | V_246 ) )
F_2 ( L_112 , V_233 , V_236 -> V_248 ) ;
if ( V_221 & ( V_249 |
V_250 |
V_251 |
V_252 ) )
F_2 ( L_113 , V_233 , V_236 -> V_253 ) ;
if ( V_221 & V_246 )
F_2 ( L_114 , V_233 , V_236 -> V_254 ) ;
if ( ( V_221 & ( V_250 |
V_251 |
V_252 ) ) &&
( V_236 -> V_255 & V_256 ) != 0 )
F_2 ( L_115 ,
V_233 , V_236 -> V_255 & ~ V_256 ) ;
F_78 ( V_15 ) ;
if ( ( V_239 = F_79 ( V_237 ) ) != 0 ) {
F_80 ( V_237 , 0 ) ;
F_81 () ;
F_2 ( L_116 ,
V_233 , V_239 ) ;
}
}
void F_82 ( struct V_14 * V_15 , unsigned long V_257 )
{
struct V_235 * V_236 , V_258 ;
struct V_259 * V_260 ;
unsigned long V_36 ;
int V_97 ;
V_97 = F_83 () ;
V_260 = & V_261 [ V_97 ] ;
V_36 = V_260 -> V_262 + V_257 ;
V_236 = F_84 ( V_36 ) ;
memcpy ( & V_258 , V_236 , sizeof( struct V_235 ) ) ;
V_236 -> V_240 = 0 ;
F_81 () ;
F_85 () ;
if ( V_258 . V_242 == V_263 ) {
F_86 ( L_117 ,
V_258 . V_264 ) ;
F_87 ( true ) ;
return;
}
F_77 ( V_15 , & V_258 , V_97 ,
V_265 L_118 ,
& V_266 ) ;
}
void F_88 ( struct V_14 * V_15 )
{
F_89 ( & V_266 ) ;
}
void F_90 ( struct V_14 * V_15 , unsigned long V_257 )
{
struct V_235 * V_236 , V_258 ;
struct V_259 * V_260 ;
unsigned long V_36 ;
int V_97 ;
V_97 = F_83 () ;
V_260 = & V_261 [ V_97 ] ;
V_36 = V_260 -> V_267 + V_257 ;
V_236 = F_84 ( V_36 ) ;
memcpy ( & V_258 , V_236 , sizeof( struct V_235 ) ) ;
V_236 -> V_240 = 0 ;
F_81 () ;
F_85 () ;
#ifdef F_37
if ( V_87 && V_88 == V_97 ) {
V_89 = 1 ;
V_15 -> V_11 += 4 ;
V_15 -> V_12 = V_15 -> V_11 + 4 ;
return;
}
#endif
F_77 ( V_15 , & V_258 , V_97 ,
V_5 L_119 ,
& V_268 ) ;
F_61 ( L_120 ) ;
}
void F_91 ( struct V_14 * V_15 )
{
F_89 ( & V_268 ) ;
}
void F_92 ( struct V_14 * V_15 , int V_6 )
{
if ( V_6 > 1 )
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_2 ( V_5 L_121 ,
V_15 -> V_11 , V_6 ) ;
F_2 ( V_5 L_122 , ( void * ) V_15 -> V_11 ) ;
F_2 ( V_5 L_123 , V_15 -> V_167 [ V_168 ] ) ;
F_2 ( V_5 L_124 ,
( void * ) V_15 -> V_167 [ V_168 ] ) ;
F_2 ( V_5 L_125
L_126 ,
V_269 , V_270 ,
V_271 , V_272 ) ;
F_43 () ;
}
void F_93 ( struct V_14 * V_15 , int V_6 )
{
if ( V_6 > 1 )
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_2 ( V_5 L_127 ,
V_15 -> V_11 , V_6 ) ;
F_2 ( V_5 L_128 , ( void * ) V_15 -> V_11 ) ;
F_2 ( V_5 L_129 , V_15 -> V_167 [ V_168 ] ) ;
F_2 ( V_5 L_130 ,
( void * ) V_15 -> V_167 [ V_168 ] ) ;
F_2 ( V_5 L_131
L_126 ,
V_273 , V_274 ,
V_275 , V_276 ) ;
F_43 () ;
}
void F_94 ( unsigned long V_277 , unsigned long V_278 )
{
F_2 ( V_166 L_132 ,
V_277 , V_278 ) ;
}
void F_95 ( unsigned long V_277 , unsigned long V_278 )
{
F_2 ( V_166 L_133 ,
V_277 , V_278 ) ;
}
void F_96 ( struct V_14 * V_15 )
{
if ( V_15 -> V_10 & V_22 ) {
V_15 -> V_11 = V_15 -> V_12 ;
V_15 -> V_12 += 4 ;
} else {
unsigned long V_279 = F_97 () -> V_280 [ 0 ] ;
T_1 V_18 ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_281 ;
V_18 . V_26 = 0 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
V_18 . V_27 = V_282 ;
if ( ( V_279 & 0x1c000 ) == ( 1 << 14 ) ) {
if ( V_279 & 0x10 )
V_18 . V_27 = V_283 ;
else if ( V_279 & 0x08 )
V_18 . V_27 = V_284 ;
else if ( V_279 & 0x04 )
V_18 . V_27 = V_285 ;
else if ( V_279 & 0x02 )
V_18 . V_27 = V_286 ;
else if ( V_279 & 0x01 )
V_18 . V_27 = V_287 ;
}
F_7 ( V_281 , & V_18 , V_32 ) ;
}
}
void F_98 ( struct V_14 * V_15 )
{
if ( F_4 ( V_19 , L_134 , V_15 ,
0 , 0x24 , V_281 ) == V_21 )
return;
F_96 ( V_15 ) ;
}
void F_99 ( struct V_14 * V_15 )
{
struct V_288 * V_289 = V_290 ;
int V_40 = 0 ;
if ( F_4 ( V_19 , L_135 , V_15 ,
0 , 0x25 , V_281 ) == V_21 )
return;
switch ( ( F_97 () -> V_280 [ 0 ] & 0x1c000 ) ) {
case ( 2 << 14 ) :
case ( 3 << 14 ) :
V_40 = F_100 ( V_15 , V_289 , false ) ;
break;
}
if ( V_40 )
return;
F_96 ( V_15 ) ;
}
void F_101 ( struct V_14 * V_15 )
{
T_1 V_18 ;
if ( F_4 ( V_19 , L_136 , V_15 ,
0 , 0x26 , V_291 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 )
F_5 ( L_137 , V_15 ) ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_291 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_292 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_291 , & V_18 , V_32 ) ;
}
void F_102 ( struct V_14 * V_15 )
{
T_1 V_18 ;
if ( F_4 ( V_19 , L_138 , V_15 ,
0 , 0x28 , V_281 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 )
F_5 ( L_139 , V_15 ) ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_281 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_293 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_281 , & V_18 , V_32 ) ;
}
static void F_103 ( unsigned int * V_294 )
{
int V_3 ;
if ( ( ( ( unsigned long ) V_294 ) & 3 ) )
return;
F_2 ( L_140 ) ;
for ( V_3 = - 3 ; V_3 < 6 ; V_3 ++ )
F_2 ( L_141 , V_3 ? ' ' : '<' , V_294 [ V_3 ] , V_3 ? ' ' : '>' ) ;
F_2 ( L_142 ) ;
}
static void F_104 ( unsigned int V_30 * V_294 )
{
int V_3 ;
unsigned int V_37 [ 9 ] ;
if ( ( ( ( unsigned long ) V_294 ) & 3 ) )
return;
if ( F_105 ( V_37 , V_294 - 3 , sizeof( V_37 ) ) )
return;
F_2 ( L_140 ) ;
for ( V_3 = 0 ; V_3 < 9 ; V_3 ++ )
F_2 ( L_141 , V_3 == 3 ? ' ' : '<' , V_37 [ V_3 ] , V_3 == 3 ? ' ' : '>' ) ;
F_2 ( L_142 ) ;
}
void F_106 ( struct V_295 * V_296 , unsigned long * V_297 )
{
unsigned long V_298 , V_299 ;
struct V_300 * V_301 ;
int V_302 = 0 ;
#ifdef F_107
int V_303 = 0 ;
#endif
V_299 = ( unsigned long ) V_297 ;
if ( ! V_296 )
V_296 = V_32 ;
V_301 = F_108 ( V_296 ) ;
if ( V_299 == 0UL ) {
if ( V_296 == V_32 )
asm("mov %%fp, %0" : "=r" (ksp));
else
V_299 = V_301 -> V_299 ;
}
if ( V_301 == F_97 () )
F_109 () ;
V_298 = V_299 + V_304 ;
F_2 ( L_143 ) ;
do {
struct V_305 * V_306 ;
struct V_14 * V_15 ;
unsigned long V_294 ;
if ( ! F_110 ( V_301 , V_298 ) )
break;
V_306 = (struct V_305 * ) V_298 ;
V_15 = (struct V_14 * ) ( V_306 + 1 ) ;
if ( F_111 ( V_301 , V_15 ) ) {
if ( ! ( V_15 -> V_10 & V_22 ) )
break;
V_294 = V_15 -> V_11 ;
V_298 = V_15 -> V_167 [ V_307 ] + V_304 ;
} else {
V_294 = V_306 -> V_308 ;
V_298 = ( unsigned long ) V_306 -> V_298 + V_304 ;
}
F_2 ( L_144 , V_294 , ( void * ) V_294 ) ;
#ifdef F_107
if ( ( V_294 + 8UL ) == ( unsigned long ) & V_309 ) {
int V_310 = V_296 -> V_311 ;
if ( V_296 -> V_312 && V_310 >= V_303 ) {
V_294 = V_296 -> V_312 [ V_310 - V_303 ] . V_40 ;
F_2 ( L_144 , V_294 , ( void * ) V_294 ) ;
V_303 ++ ;
}
}
#endif
} while ( ++ V_302 < 16 );
}
void F_112 ( void )
{
F_106 ( V_32 , NULL ) ;
}
static inline struct V_313 * F_113 ( struct V_313 * V_314 )
{
unsigned long V_298 = V_314 -> V_315 [ 6 ] ;
if ( ! V_298 )
return NULL ;
return (struct V_313 * ) ( V_298 + V_304 ) ;
}
void F_5 ( char * V_316 , struct V_14 * V_15 )
{
static int V_317 ;
int V_302 = 0 ;
F_2 (
L_145
L_146
L_147
L_148 ) ;
F_2 ( L_149 , V_32 -> V_318 , F_114 ( V_32 ) , V_316 , ++ V_317 ) ;
F_4 ( V_319 , V_316 , V_15 , 0 , 255 , V_50 ) ;
__asm__ __volatile__("flushw");
F_78 ( V_15 ) ;
F_115 ( V_320 , V_321 ) ;
if ( V_15 -> V_10 & V_22 ) {
struct V_300 * V_301 = F_97 () ;
struct V_313 * V_314 = (struct V_313 * )
( V_15 -> V_167 [ V_322 ] + V_304 ) ;
while ( V_314 &&
V_302 ++ < 30 &&
F_110 ( V_301 , ( unsigned long ) V_314 ) ) {
F_2 ( L_150 , V_314 -> V_315 [ 7 ] ,
( void * ) V_314 -> V_315 [ 7 ] ) ;
V_314 = F_113 ( V_314 ) ;
}
F_103 ( ( unsigned int * ) V_15 -> V_11 ) ;
} else {
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
F_104 ( ( unsigned int V_30 * ) V_15 -> V_11 ) ;
}
if ( V_15 -> V_10 & V_22 )
F_116 ( V_323 ) ;
F_116 ( V_50 ) ;
}
void F_117 ( struct V_14 * V_15 )
{
unsigned long V_294 = V_15 -> V_11 ;
unsigned long V_10 = V_15 -> V_10 ;
T_5 V_234 ;
T_1 V_18 ;
if ( F_4 ( V_19 , L_151 , V_15 ,
0 , 0x10 , V_25 ) == V_21 )
return;
if ( V_10 & V_22 )
F_5 ( L_152 , V_15 ) ;
if ( F_6 ( V_23 ) )
V_294 = ( T_5 ) V_294 ;
if ( F_118 ( V_234 , ( T_5 V_30 * ) V_294 ) != - V_324 ) {
if ( ( V_234 & 0xc1ffc000 ) == 0x81700000 ) {
if ( F_119 ( V_234 , V_15 ) )
return;
} else if ( ( V_234 & 0xc1580000 ) == 0xc1100000 ) {
if ( F_120 ( V_234 , V_15 ) )
return;
} else if ( V_7 == V_8 ) {
if ( ( V_234 & V_325 ) == V_326 ) {
if ( ! F_121 ( V_15 , V_234 ) )
return;
} else {
struct V_288 * V_289 = V_290 ;
if ( F_100 ( V_15 , V_289 , true ) )
return;
}
}
}
V_18 . V_24 = V_25 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_327 ;
V_18 . V_29 = ( void V_30 * ) V_294 ;
V_18 . V_31 = 0 ;
F_7 ( V_25 , & V_18 , V_32 ) ;
}
void F_122 ( struct V_14 * V_15 , unsigned long V_49 , unsigned long V_48 )
{
T_1 V_18 ;
if ( F_4 ( V_19 , L_153 , V_15 ,
0 , 0x34 , V_50 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
F_123 ( V_15 , * ( ( unsigned int * ) V_15 -> V_11 ) ) ;
return;
}
V_18 . V_24 = V_74 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_328 ;
V_18 . V_29 = ( void V_30 * ) V_49 ;
V_18 . V_31 = 0 ;
F_7 ( V_74 , & V_18 , V_32 ) ;
}
void F_124 ( struct V_14 * V_15 , unsigned long V_52 , unsigned long V_53 )
{
T_1 V_18 ;
if ( F_4 ( V_19 , L_153 , V_15 ,
0 , 0x34 , V_50 ) == V_21 )
return;
if ( V_15 -> V_10 & V_22 ) {
F_123 ( V_15 , * ( ( unsigned int * ) V_15 -> V_11 ) ) ;
return;
}
V_18 . V_24 = V_74 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_328 ;
V_18 . V_29 = ( void V_30 * ) V_52 ;
V_18 . V_31 = 0 ;
F_7 ( V_74 , & V_18 , V_32 ) ;
}
void F_125 ( struct V_14 * V_15 )
{
T_1 V_18 ;
if ( F_4 ( V_19 , L_154 , V_15 ,
0 , 0x11 , V_25 ) == V_21 )
return;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
V_18 . V_24 = V_25 ;
V_18 . V_26 = 0 ;
V_18 . V_27 = V_329 ;
V_18 . V_29 = ( void V_30 * ) V_15 -> V_11 ;
V_18 . V_31 = 0 ;
F_7 ( V_25 , & V_18 , V_32 ) ;
}
void F_126 ( struct V_14 * V_15 )
{
F_125 ( V_15 ) ;
}
void F_127 ( struct V_14 * V_15 )
{
F_5 ( L_155 , V_15 ) ;
}
void F_128 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_156 , V_15 ) ;
}
void F_129 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_157 , V_15 ) ;
}
void F_130 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_158 , V_15 ) ;
}
void F_131 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_159 , V_15 ) ;
}
void F_132 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_160 , V_15 ) ;
}
void F_133 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_161 , V_15 ) ;
}
void F_134 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_162 , V_15 ) ;
}
void F_135 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_163 , V_15 ) ;
}
void F_136 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_164 , V_15 ) ;
}
void F_137 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_165 , V_15 ) ;
}
void F_138 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_166 , V_15 ) ;
}
void F_139 ( struct V_14 * V_15 )
{
F_5 ( L_167 , V_15 ) ;
}
void F_140 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_168 , V_15 ) ;
}
void F_141 ( struct V_14 * V_15 )
{
F_5 ( L_169 , V_15 ) ;
}
void F_142 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_170 , V_15 ) ;
}
void F_143 ( struct V_14 * V_15 )
{
F_1 ( (struct V_1 * ) ( V_15 + 1 ) ) ;
F_5 ( L_171 , V_15 ) ;
}
void F_144 ( struct V_14 * V_15 )
{
V_15 -> V_167 [ V_330 ] = F_145 ( V_15 -> V_10 ) ;
V_15 -> V_11 = V_15 -> V_12 ;
V_15 -> V_12 += 4 ;
if ( F_6 ( V_23 ) ) {
V_15 -> V_11 &= 0xffffffff ;
V_15 -> V_12 &= 0xffffffff ;
}
}
void T_8 F_146 ( struct V_300 * V_331 )
{
int V_97 = F_147 () ;
struct V_259 * V_2 = & V_261 [ V_97 ] ;
V_2 -> V_332 = V_331 ;
V_2 -> V_333 = 0 ;
}
void T_3 F_148 ( void )
{
F_149 ( V_334 != F_150 ( struct V_300 , V_335 ) ||
V_336 != F_150 ( struct V_300 , V_39 ) ||
V_337 != F_150 ( struct V_300 , V_97 ) ||
V_338 != F_150 ( struct V_300 , V_339 ) ||
V_340 != F_150 ( struct V_300 , V_299 ) ||
V_341 != F_150 ( struct V_300 ,
V_342 ) ||
V_343 != F_150 ( struct V_300 , V_344 ) ||
V_345 != F_150 ( struct V_300 , V_346 ) ||
V_347 != F_150 ( struct V_300 ,
V_348 ) ||
V_349 != F_150 ( struct V_300 ,
V_313 ) ||
V_350 != F_150 ( struct V_300 ,
V_351 ) ||
V_352 != F_150 ( struct V_300 , V_353 ) ||
V_354 != F_150 ( struct V_300 , V_280 ) ||
V_355 != F_150 ( struct V_300 ,
V_356 ) ||
V_357 != F_150 ( struct V_300 , V_358 ) ||
V_359 != F_150 ( struct V_300 ,
V_360 ) ||
V_361 != F_150 ( struct V_300 ,
V_362 ) ||
V_363 != F_150 ( struct V_300 ,
V_364 ) ||
V_365 != F_150 ( struct V_300 ,
V_366 ) ||
V_367 != F_150 ( struct V_300 , V_368 ) ||
( V_367 & ( 64 - 1 ) ) ) ;
F_149 ( V_369 != F_150 ( struct V_259 ,
V_332 ) ||
( V_370 !=
F_150 ( struct V_259 , V_333 ) ) ||
( V_371 !=
F_150 ( struct V_259 , V_372 ) ) ||
( V_373 !=
F_150 ( struct V_259 , V_374 ) ) ||
( V_375 !=
F_150 ( struct V_259 , V_376 ) ) ||
( V_377 !=
F_150 ( struct V_259 , V_262 ) ) ||
( V_378 !=
F_150 ( struct V_259 , V_379 ) ) ||
( V_380 !=
F_150 ( struct V_259 , V_267 ) ) ||
( V_381 !=
F_150 ( struct V_259 , V_382 ) ) ||
( V_383 !=
F_150 ( struct V_259 , V_384 ) ) ||
( V_385 !=
F_150 ( struct V_259 , V_386 ) ) ||
( V_387 !=
F_150 ( struct V_259 , V_388 ) ) ||
( V_389 !=
F_150 ( struct V_259 , V_390 ) ) ||
( V_391 !=
F_150 ( struct V_259 , V_392 ) ) ||
( V_393 !=
F_150 ( struct V_259 , V_394 ) ) ||
( V_395 !=
F_150 ( struct V_259 , V_396 ) ) ||
( V_397 !=
F_150 ( struct V_259 , V_398 ) ) ||
( V_399 !=
F_150 ( struct V_259 , V_400 ) ) ||
( V_401 !=
F_150 ( struct V_259 , V_402 ) ) ) ;
F_149 ( ( V_403 !=
F_150 ( struct V_404 , V_405 ) ) ||
( V_406 !=
F_150 ( struct V_404 , V_407 ) ) ||
( V_408 !=
F_150 ( struct V_404 , V_409 ) ) ||
( V_410 !=
F_150 ( struct V_404 , V_411 ) ) ||
( V_412 !=
F_150 ( struct V_404 , V_413 ) ) ||
( V_414 !=
F_150 ( struct V_404 , V_415 ) ) ) ;
F_89 ( & V_416 . V_417 ) ;
V_32 -> V_418 = & V_416 ;
}
